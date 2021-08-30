#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 每个python版本的ROS节点在开头都有这样以上两行声明，表示这个文件是python类型,并且表明文件编码格式   

import rospy  # 如果要写ROS节点，需要导入rospy。
from std_msgs.msg import String # std_msgs.msg的目的是可以使用std_msgs/String消息类型来发布

def talker(): # 创建一个发布话题的函数

    # 创建ROS节点talker,anoymous=True,保证你的节点独一无二。
    rospy.init_node('talker', anonymous=True)

    # 表示你正在使用String类型的消息来发布你的节点到chatter话题,String就是std_msgs.msg.String类。
    pub = rospy.Publisher('chatter', String, queue_size=10)

    # 这一行创建速率对象rate.在其方法sleep()的帮助下，它提供了一个以一定速率循环的方便的方法。
    # 参数10表示我们期望以每秒循环10次（只要我们的处理时间不超过1/10秒）
    rate = rospy.Rate(10) 

    # 若有Ctrl-C操作或其它终止终端的行为,则跳出while循环
    while not rospy.is_shutdown():

        # 创建一个字符串
        hello_str = "hello world:[%s]" % rospy.get_time()

        # 打印该字符串到终端
        rospy.loginfo(hello_str)

        # 节点发布消息
        pub.publish(hello_str)

        # 以设定好的频率进行休眠
        rate.sleep()
 
if __name__ == '__main__':
    
    try:
        talker()
    # 捕获一个rospy.ROSInterruptException异常
    except rospy.ROSInterruptException:
        pass