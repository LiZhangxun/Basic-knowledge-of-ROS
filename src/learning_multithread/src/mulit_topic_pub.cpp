//包含ros相关的API头文件
#include "ros/ros.h"
//包含在std_msgs库里的String类型
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
	//初始化ROS节点
	ros::init(argc, argv, "multi_pub");

	//初始化节点句柄
	ros::NodeHandle n;

	//创建发布者，消息类型为std_msgs::String，队列长度为1
	ros::Publisher pub1 = n.advertise<std_msgs::String>("chatter1", 1);
	ros::Publisher pub2 = n.advertise<std_msgs::String>("chatter2", 1);

	//设定循环频率为10HZ,每过0.1s发送一次数据
	ros::Rate loop_rate(10);//10HZ
	int count = 0;

	//将数据打包循环发送
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();

		std_msgs::String msg2;
		std::stringstream ss2;
		ss2 << "hello " << count;
		msg2.data = ss2.str();

		ROS_INFO("%s", msg.data.c_str());
		ROS_INFO("%s", msg2.data.c_str());

		pub1.publish(msg);
		pub2.publish(msg2);

		//按指定频率休眠
		loop_rate.sleep();
		++count;
	}
	 return 0;
}