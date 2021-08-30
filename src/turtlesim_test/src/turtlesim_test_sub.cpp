#include "ros/ros.h"
#include "turtlesim/Pose.h"	//包含消息类型的头文件(海龟仿真器包含的)


//如何实现一个订阅者
/**1.初始化ros节点
  *2.订阅需要的话题
  *3.循环等待话题消息，接收到消息后进入回调函数
  *4.在回调函数中完成消息的处理
**/


//接收到订阅的消息后会进入回调函数
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
	//打印接收到的数据和消息
	ROS_INFO("Turtlesim pose: x:%0.6f, y:%0.6f", msg->x,msg->y);//ros_info相当于printf函数
}

int main(int argc, char **argv)
{
	//初始化ros节点
	ros::init(argc, argv, "turtlesim_test_sub");

	//创建节点句柄
	ros::NodeHandle n;

	//创建一个Ssubscriber，订阅名为/turtle1/pose的topic,（订阅名字要和系统中存在的话题名字对应）,注册回调函数的posecallback
	ros::Subscriber sub = n.subscribe("/turtle1/pose", 10, poseCallback);//10表示缓冲区有10个队列
	//由于话题方式无同步性，回调函数相当于中断，必须有数据进来，才会进入;

	//循环等待函数	
	ros::spin();

	return 0;
}