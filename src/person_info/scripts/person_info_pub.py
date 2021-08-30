#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将发布/person_info话题，自定义消息类型person_info::person

import rospy 
from person_info.msg import person # from 包名(person_info).模块名(msg) import 功能名(person)

def person_publisher():
	# ROS节点初始化
    rospy.init_node('person_publisher', anonymous=True)

	# 创建一个Publisher，发布名为/person_info的topic，消息类型为person_info::person，队列长度10
    person_info_pub = rospy.Publisher('/person_info', person, queue_size=10)

	#设置循环的频率
    rate = rospy.Rate(10) 

    while not rospy.is_shutdown():
		# 初始化person_info::person类型的消息
    	person_msg = person()
    	person_msg.name = "Tom"
    	person_msg.age  = 18
    	person_msg.sex  = person.male

		# 发布消息
        person_info_pub.publish(person_msg)
    	rospy.loginfo("Publsh person message[%s, %d, %d]", person_msg.name, person_msg.age, person_msg.sex)

		# 按照循环频率延时
        rate.sleep()

if __name__ == '__main__':
    try: # 首先执行发布函数
        person_publisher()
    except rospy.ROSInterruptException as result: # 如果终端被终止,则停止
        rospy.loginfo("%s", result)
    else:
        if rospy.is_shutdown(): # 如果没有异常,但是被终端终止,则输出以下语句
            rospy.loginfo("Terminate is shutted down!")
    finally: # 最后程序结束前打印这句话
        rospy.loginfo("Program stop.")