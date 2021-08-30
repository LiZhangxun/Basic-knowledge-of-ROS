#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import String

def callback(data): 
    #捕捉它所订阅的话题的数据
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

# 功能函数,创建并初始化订阅者节点
def listener():
    
    # 初始化节点
    rospy.init_node('listener', anonymous=True)
 
    # 创建订阅者,订阅话题chatter,类型为String类型,并注册回调函数callback.
    rospy.Subscriber("chatter", String, callback)
 
    # 循环等待接收数据,一旦有数据,则进入回调函数执行相应功能
    rospy.spin()
 
if __name__ == '__main__':
    try:
        listener()
    # 捕获一个rospy.ROSInterruptException异常
    except rospy.ROSInterruptException:
        pass