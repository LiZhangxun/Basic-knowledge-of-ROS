#include "test.h"
//直接在include下的.h文件
//#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>

using namespace std;

Test::Test()    //构造函数
{
    ROS_INFO("hello");
    //创建一个发布者
    pub=n.advertise<std_msgs::String>("chatter", 1000);
    //设置循环的频率
	ros::Rate loop_rate(10);
    int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;

		ss << "hello world " << count;
		msg.data = ss.str();
		//发布消息
		ROS_INFO("%s", msg.data.c_str());
		pub.publish(msg);

		ros::spinOnce();
		//按照循环频率延时
		loop_rate.sleep();
		++count;
	}

}
Test::~Test()    //析构函数
{

}
