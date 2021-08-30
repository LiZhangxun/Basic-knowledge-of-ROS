#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 如何实现一个tf广播器:
# 1.定义tf广播器
# 2.创建坐标变换值
# 3.发布坐标变换
# */

import roslib
roslib.load_manifest('learning_tf')
import rospy

import tf
import turtlesim.msg

def handle_turtle_pose(msg, turtlename):

    # 创建一个广播器对象
    br = tf.TransformBroadcaster()

    # 从"world" 坐标系到"turtleX"坐标系进行发布。
    br.sendTransform((msg.x, msg.y, 0),
                     tf.transformations.quaternion_from_euler(0, 0, msg.theta),
                     rospy.Time.now(),
                     turtlename,
                     "world")

def broadcaster_init():

    # 初始化ros节点,名称为turtle_tf_broadcaster
    rospy.init_node('turtle_tf_broadcaster', anonymous=True)

    # 节点获取turtle参数，这个指定一个turtle名，如"turtle1" or "turtle2".
    # turtlename = rospy.get_param('~turtle')

    turtlename = str(input("请输入您要监听的小海龟tf的名字:")) # 在终端中输入时,类似于这样"turtle1"输入,需要打开两个终端分别输入两个海龟.

    # 订阅的话题名字组合
    topic_name = turtlename + "/pose"

    # 节点订阅"turtleX/pose" 主题，指定handle_turtle_pose回调函数,并指定回调函数的参数包含turtlename
    rospy.Subscriber(topic_name, turtlesim.msg.Pose, handle_turtle_pose, turtlename)
    
    # 循环等待
    rospy.spin()

if __name__ == '__main__':
    try:
        broadcaster_init()
    except rospy.ROSInterruptException :
        pass



