#include "ros/ros.h"
#include "geometry_msgs/Twist.h"//包含了小海龟运动的消息数据格式
/**如何实现发布者
  *1.初始化ros节点
  *2.向ROS Master注册节点信息，包括发布的话题名和话题中的消息类型
  *3.创建消息数据
  *4.按照一定频率循环发布消息
**/
int main(int argc, char *argv[])
{
	//ros节点的初始化
	ros::init(argc, argv, "turtlesim_test_pub");//注册节点，名字为“turtlesim_test_pub”
	//创建节点句柄
	ros::NodeHandle n;
	//创建一个publisher，发布名为/tutrle1/cmd_vel的话题，消息类型为geometry_msgs::Twist，长度为10;话题名字和小海龟订阅的话题名字一致；
	//发布者队列10表示最多缓存10个最新的数据,队列长度设置越大,能够缓存的数据越多.
	ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
	//设置循环的频率
	ros::Rate loop_rate(10);//频率为10HZ,周期为0.1S,每秒中发送10次.

	while (ros::ok())
	{
		//初始化geometry_msgs::Twist类型的消息
		geometry_msgs::Twist vel_msg;
		//设置海龟运行线速度和角速度
		vel_msg.linear.x=0.5;
		vel_msg.angular.z=0.2;

		//发布消息
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("publish turtle command[%0.2f n/s,%0.2f rad/s]",vel_msg.linear.x,vel_msg.angular.z);

		ros::spinOnce();
		//按照循环频率延时
		loop_rate.sleep();
	}
	return 0;
}