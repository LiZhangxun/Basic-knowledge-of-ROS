#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将订阅/person_info话题，自定义消息类型person_info::person

import rospy
from person_info.msg import person 

def personInfoCallback(msg):
    rospy.loginfo("Subcribe person_info: name:%s  age:%d  sex:%d", msg.name, msg.age, msg.sex)

def person_subscriber():
	# ROS节点初始化
    rospy.init_node('person_subscriber', anonymous=True)

	# 创建一个Subscriber，订阅名为/person_info的topic，注册回调函数personInfoCallback
    rospy.Subscriber("/person_info", person, personInfoCallback)

	# 循环等待回调函数
    rospy.spin()

if __name__ == '__main__':
    try: # 首先执行函数
        person_subscriber()
    except rospy.ROSInterruptException as result: # 如果终端被终止,则停止
        rospy.loginfo("%s", result)
    else:
        if rospy.is_shutdown(): # 如果没有异常,但是被终端终止,则输出以下语句
            rospy.loginfo("Terminate is shutted down!")
    finally: # 最后程序结束前打印这句话
        rospy.loginfo("Program stop.")