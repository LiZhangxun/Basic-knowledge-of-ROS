#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将订阅/turtle1/pose话题，消息类型turtlesim::Pose

import rospy # 导入ros中Python库
from turtlesim.msg import Pose # 导入turtlesim包msg模块中的Pose功能

def poseCallback(msg):
    rospy.loginfo("Turtle pose: x:%0.6f, y:%0.6f", msg.x, msg.y)

def pose_subscriber():

	# ROS节点初始化
    rospy.init_node('pose_subscriber', anonymous=True)

	# 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    rospy.Subscriber("/turtle1/pose", Pose, poseCallback, queue_size = 100)

	# 循环等待回调函数
    rospy.spin()

if __name__ == '__main__':
    # 如果发生异常(rospy.ROSInterruptException),则执行pass跳过,程序结束
    try:
        pose_subscriber()
    except rospy.ROSInterruptException as result: # 如果终端被终止,则停止
        rospy.loginfo("%s", result)
    else:
        if rospy.is_shutdown(): # 如果没有异常,但是被终端终止,则输出以下语句
            rospy.loginfo("Terminate is shutted down!")
    finally: # 最后程序结束前打印这句话
        rospy.loginfo("Program stop.")
    