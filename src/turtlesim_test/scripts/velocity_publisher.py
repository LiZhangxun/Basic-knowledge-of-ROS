#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将发布turtle1/cmd_vel话题，消息类型geometry_msgs::Twist

import rospy # 导入ros中Python库
from geometry_msgs.msg import Twist # 导入geometry_msgs包msg模块中的Twist功能

# 定义功能函数
def velocity_publisher():

	# ROS节点初始化
    rospy.init_node('velocity_publisher', anonymous=True)

	# 创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10
    turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)

	#设置循环的频率
    rate = rospy.Rate(10) 

    while not rospy.is_shutdown():

		# 初始化geometry_msgs::Twist类型的消息
        vel_msg = Twist()
        vel_msg.linear.x = 0.5
        vel_msg.angular.z = 0.2

		# 发布消息
        turtle_vel_pub.publish(vel_msg)
    	rospy.loginfo("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z)

		# 按照循环频率延时
        rate.sleep()

if __name__ == '__main__': # 确保只在本文件运行测试代码.
    # 如果发生异常(rospy.ROSInterruptException),则执行pass跳过,程序结束
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass