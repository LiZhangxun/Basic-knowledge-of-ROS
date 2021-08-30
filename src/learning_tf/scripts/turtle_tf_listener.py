#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将请求/show_person服务，服务数据类型learning_service::Person

import roslib
roslib.load_manifest('learning_tf')
import rospy
import math
import tf
import geometry_msgs.msg
import turtlesim.srv


if __name__ == '__main__':

    # 初始化节点
    rospy.init_node('turtle_tf_listener')

    # 创建tf监听器实例对象
    listener = tf.TransformListener()
    
    # 等待spawn服务启动 
    rospy.wait_for_service('spawn')
    
    # 产生一个spawn实例
    spawner = rospy.ServiceProxy('spawn', turtlesim.srv.Spawn)

    # turtle2的产生位置为:x=[4.000000], y=[2.000000], theta=[0.000000]
    spawner(4, 2, 0, 'turtle2')

    # 创建速度话题发布者
    turtle_vel = rospy.Publisher('turtle2/cmd_vel', geometry_msgs.msg.Twist,queue_size=1)

    # 设定循环频率
    rate = rospy.Rate(10.0)

    while not rospy.is_shutdown():
        try:
            # # 等待时间3秒
            listener.waitForTransform('/turtle2', '/turtle1', rospy.Time(0), rospy.Duration(3.0))
            # 查询turtle1和turtle2的位置关系，数据保存在列表trans和rot中
            (trans,rot) = listener.lookupTransform('/turtle2', '/turtle1', rospy.Time(0))

        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException) as result:
            rospy.loginfo(result)
            rospy.sleep(1)
            continue

        # 角速度计算
        angular = 4 * math.atan2(trans[1], trans[0])

        # 线速度计算
        linear = 0.5 * math.sqrt(trans[0] ** 2 + trans[1] ** 2)

        # 将计算的数据封装成geometry_msgs/Twist类型
        cmd = geometry_msgs.msg.Twist()
        cmd.linear.x = linear
        cmd.angular.z = angular

        # 发布数据
        turtle_vel.publish(cmd)

        # 按照指定频率休眠
        rate.sleep()


