#include "ros/ros.h"
#include "person_info/person.h"


void personInfoCallback(const person_info::person::ConstPtr& msg)
{
	//将接收到的消息打印出来
	ROS_INFO("Subscribe Person Info: name:%s age:%d	sex:%d", msg->name.c_str(),msg->age,msg->sex);
	ROS_INFO("success!");
}

int main(int argc, char **argv)
{
	//初始化ros节点
	ros::init(argc, argv, "person_info_sub");
	//创建节点句柄
	ros::NodeHandle n;
	//创建一个订阅者，订阅名为/person_info的topic,注册回调函数personInfoCallback
	ros::Subscriber sub = n.subscribe("/person_info", 10, personInfoCallback);
	//循环等待回调函数
	ros::spin();
	
	return 0;
}