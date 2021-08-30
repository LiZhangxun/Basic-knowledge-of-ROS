#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    //初始化节点
	ros::init(argc, argv, "test_sub");
    //创建节点句柄
	ros::NodeHandle n;
    //创建一个订阅者，订阅名为/chatter的topic,注册回调函数chatterCallback
	ros::Subscriber sub = n.subscribe("chatter", 1000, &chatterCallback);//订阅的话题名字需要和发布的话题名字相同
    //循环等待
	ros::spin();

	return 0;
}