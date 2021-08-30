#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
	//ros节点的初始化
	ros::init(argc, argv, "test_pub");//初始化节点的名字
	//创建节点句柄
	ros::NodeHandle n;
	//创建一个publisher，发布名为“chatter”的话题，消息类型为std_msgs::String，长度为1000;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//话题的名字为chatter
	//设置循环的频率
	ros::Rate loop_rate(1);//频率=周期的倒数(即f=1/T)
	
	int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;

		ss << "hello world " << count;
		msg.data = ss.str();
		//发布消息
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);

		ros::spinOnce();
		//按照循环频率延时
		loop_rate.sleep();
		++count;
	}

	return 0;
}