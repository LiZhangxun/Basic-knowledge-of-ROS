#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将执行/turtle_command服务，服务数据类型std_srvs/Trigger

import rospy
import thread,time
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger, TriggerResponse

# 声明全局变量
pubCommand = False;

# 创建发布者,发布话题/turtle1/cmd_vel(由于需要被函数内部调用,只能在外部声明)
turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)

def command_thread():	
	while True:
		if pubCommand:
			vel_msg = Twist()
			vel_msg.linear.x = 0.5
			vel_msg.angular.z = 0.2
			turtle_vel_pub.publish(vel_msg)
			
		time.sleep(0.1)

def commandCallback(req):
	# 全局变量
	global pubCommand
	pubCommand = bool(1-pubCommand)

	# 显示请求数据
	rospy.loginfo("Publish turtle velocity command![%d]", pubCommand)

	# 反馈数据
	return TriggerResponse(1, "Change turtle command state!")

def turtle_command_server():
	# ROS节点初始化
    rospy.init_node('turtle_command_server')

	# 创建一个名为/turtle_command的server，注册回调函数commandCallback
    s = rospy.Service('/turtle_command', Trigger, commandCallback)

    print "Ready to receive turtle command."

	# 开启线程,执行command_thread函数
    thread.start_new_thread(command_thread, ())

	# 循环等待回调函数
    rospy.spin()

if __name__ == "__main__":
    turtle_command_server()
