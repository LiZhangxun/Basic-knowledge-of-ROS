#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将请求/show_person服务，服务数据类型person_service::s_c_person

import rospy
from person_service.srv import s_c_person, s_c_personResponse

def personCallback(req):
	# 显示请求数据
    rospy.loginfo("Person: name:%s  age:%d  sex:%d", req.name, req.age, req.sex)

	# 反馈数据
    return s_c_personResponse("OK")

def person_server():
	# ROS节点初始化
    rospy.init_node('person_server')

	# 创建一个名为/show_person的server，注册回调函数personCallback
    s = rospy.Service('/show_person', s_c_person, personCallback)

    print "Ready to show person informtion."

    # 循环等待回调函数
    rospy.spin()

if __name__ == "__main__":
    person_server()


