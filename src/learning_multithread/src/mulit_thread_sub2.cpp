#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/thread.hpp>

// 线程函数原型:
// ros::AsyncSpinner spinner(4); // Use 4 threads
// spinner.start();
// ros::waitForShutdown();
// 相比较之下，AsyncSpinner比MultiThreadedSpinner更优，它有start() 和stop() 函数，并且在销毁的时候会自动停止

class multiThreadListener
{
public:
	multiThreadListener()
	{	
		sub = n.subscribe("chatter1", 1, &multiThreadListener::chatterCallback1,this);
		sub2 = n.subscribe("chatter2", 1, &multiThreadListener::chatterCallback2,this);
	}
	void chatterCallback1(const std_msgs::String::ConstPtr& msg);
	void chatterCallback2(const std_msgs::String::ConstPtr& msg);

private:
	ros::NodeHandle n;
	ros::Subscriber sub;
	ros::Subscriber sub2;
  
};

void multiThreadListener::chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  ros::Rate loop_rate(0.5);//block chatterCallback2()
  loop_rate.sleep();
}

void multiThreadListener::chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
  
int main(int argc, char **argv)
{
  ros::init(argc, argv, "multi_sub");

  multiThreadListener listener_obj;
  
  ros::AsyncSpinner spinner(2); // Use 2 threads
  
  spinner.start();

  ros::waitForShutdown();

  return 0;
}