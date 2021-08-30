// 说明：

// 本教程介绍了roscpp定时器，它允许您安排一个回调发生周期性。
// 什么是Timers(定时器)?

// Timers能让你以一定的频率来执行
// 他们是比ros::Rate更加灵活和有用的形式，ros::Rate在编写简单发布节点和订阅节点用到。
// 注意：定时器不是实时的线程/内核替换，也不能保证它们的准确度，因为系统负载/功能会有很大的变化。
// 更多可以参考: roscpp Timers overview
// 使用定时器

// 创建定时器象创建订阅一样：
// ros::Timer timer = n.createTimer(ros::Duration(0.1), timerCallback);
// 回调函数：
// void timerCallback(const ros::TimerEvent& e);

#include "ros/ros.h"

void callback1(const ros::TimerEvent&)
{
  ROS_INFO("Callback 1 triggered");
}

void callback2(const ros::TimerEvent&)
{
  ROS_INFO("Callback 2 triggered");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  //增加两个定时器，一个100毫秒执行一次，一个1秒执行一次。
  ros::Timer timer1 = n.createTimer(ros::Duration(0.1), callback1);
  ros::Timer timer2 = n.createTimer(ros::Duration(1.0), callback2);

  ros::spin();

  return 0;
}