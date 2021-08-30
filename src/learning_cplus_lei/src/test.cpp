#include "learning_cplus_lei/test.h"
//由于创建的时候是include下面的learning_cplus_lei文件夹里面的.h文件,所以需要这样引用.
//并且编写cmakelist文件时需要link的是project的名字(learning_cplus_lei)
//#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>

using namespace std;

Test::Test()    //构造函数
{
    //创建一个发布者
    pub=n.advertise<std_msgs::String>("chatter", 1000);
    //设置循环的频率
	ros::Rate loop_rate(1);
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
