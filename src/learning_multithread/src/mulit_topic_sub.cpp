#include "ros/ros.h"
#include "std_msgs/String.h"

// 可以看到，发布程序中，以10hz的频率发布了chatter1和chatter2两个话题
// 在订阅程序中，回调函数1中加入了2s的延时，导致了回调函数2也只能2s才能接收到一个数据，

class multiReceiver
{
public:
	multiReceiver()
	{	
		sub = nh.subscribe("chatter1", 1, &multiReceiver::chatterCallback1,this);
		sub2 = nh.subscribe("chatter2", 1, &multiReceiver::chatterCallback2,this);
	}

	//声明回调函数
	void chatterCallback1(const std_msgs::String::ConstPtr& msg);
	void chatterCallback2(const std_msgs::String::ConstPtr& msg);

private:
	ros::NodeHandle nh;
	ros::Subscriber sub;
	ros::Subscriber sub2;
};


void multiReceiver::chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
	ros::Rate loop_rate(0.5);//设定休眠2s
	loop_rate.sleep();
}

void multiReceiver::chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  	ROS_INFO("I heard: [%s]", msg->data.c_str());
}
  
int main(int argc, char **argv)
{
	ros::init(argc, argv, "multi_sub");

	multiReceiver recOb;//在类中初始化ROS节点

	//循环等待回调函数
	ros::spin();

	return 0;
}
