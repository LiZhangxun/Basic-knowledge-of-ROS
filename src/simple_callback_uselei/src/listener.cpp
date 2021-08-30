#include "ros/ros.h"
#include "std_msgs/String.h"

//大多数教程使用函数的例子，而不是类方法。这是因为使用函数比较简单，不是因为不支持类方法。
//本教程将向您展示如何使用类方法订阅服务回调。

class Listener
{
public:
  void callback(const std_msgs::String::ConstPtr& msg);//空实现
};

// //如果订阅在Listener内部，你替换最后的参数为关键词this，它意味着订阅会引用类的一部分。
// class Listener
// {
// public:
//   //在函数内部初始化节点句柄和实例化订阅者
//   ros::NodeHandle n;
//   ros::Subscriber cloud_sub;
//   void callback(const std_msgs::String::ConstPtr& msg);
//   cloud_sub = n.subscribe("chatter", 1000, &Listener::callback, this);
// };

void Listener::callback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_class");
  ros::NodeHandle n;

  //使用类方法作为回调函数
  Listener listener;
  ros::Subscriber sub = n.subscribe("chatter", 1000, &Listener::callback, &listener);


  ros::spin();

  return 0;
}