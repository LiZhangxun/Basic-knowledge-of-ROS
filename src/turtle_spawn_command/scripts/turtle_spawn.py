#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程将请求/spawn服务，服务数据类型turtlesim::Spawn

import sys
import rospy
from turtlesim.srv import Spawn

def turtle_spawn():
	# ROS节点初始化
    rospy.init_node('turtle_spawn')

	# 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
    rospy.wait_for_service('/spawn')
    try:
        # 创建一个客户端,去请求服务/spawn
        add_turtle = rospy.ServiceProxy('/spawn', Spawn)

		# 请求服务调用，输入请求数据,turtle2的产生位置为:x=[2.000000], y=[2.000000], theta=[0.000000]
        response = add_turtle(2.0, 2.0, 0.0, "turtle2")
        return response.name # 返回小海龟的名字
        
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":
	#服务调用并显示调用结果
    print "Spwan turtle successfully [name:%s]" %(turtle_spawn())


