#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将请求/show_person服务，服务数据类型person_service::s_c_person

import sys
import rospy
from person_service.srv import s_c_person, s_c_personRequest

def person_client():

	# ROS节点初始化
    rospy.init_node('person_client')

	# 发现/show_person服务后，创建一个服务客户端，连接名为/show_person的service
    rospy.wait_for_service('/show_person')
    try:
        # 创建一个客户端
        person_client = rospy.ServiceProxy('/show_person', s_c_person)

		# 请求服务调用，输入请求数据
        response = person_client("Tom", 20, s_c_personRequest.male)

        return response.result #将结果返回给main函数并显示

    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":

	#服务调用并显示调用结果
    print "Show person result : %s" %(person_client())


