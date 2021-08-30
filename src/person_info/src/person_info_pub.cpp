#include "ros/ros.h"
#include "person_info/person.h"//注意头文件person_info是person.h所在文件夹名字


int main(int argc, char *argv[])
{
	//ros节点初始化
	ros::init(argc, argv, "person_info_pub");
	//创建节点句柄
	ros::NodeHandle n;

	//创建一个发布者，发布名为/person_info的topic,消息类型为person_info::person,队列长度为10
	ros::Publisher person_info_pub = n.advertise<person_info::person>("/person_info", 10);

	//设置循环的频率1HZ,每秒发1次.
	ros::Rate loop_rate(1);

	while (ros::ok())
	{
		//初始化person_info::person类型的消息
		person_info::person person_msg;
		person_msg.name="LZX";
		person_msg.age=18;
		person_msg.sex=person_info::person::male;//宏定义的调用方式，头文件中定义好的值

		//发布消息
		person_info_pub.publish(person_msg);

		ROS_INFO("Publish Person Info: name:%s 	age:%d	sex:%d", person_msg.name.c_str(),person_msg.age,person_msg.sex);
		//按照循环频率延时
		loop_rate.sleep();
	}
	return 0;
}