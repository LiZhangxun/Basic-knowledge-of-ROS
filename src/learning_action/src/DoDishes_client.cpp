#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include "learning_action/DoDishesAction.h"

//什么是动作
// 1.一种问答通信机制
// 2.带有连续的反馈
// 3.可以在任务运行过程中止
// 4.基于ros的消息机制实现

// Action的接口
// 1.goal：发布任务目标；
// 2.cancel：请求取消任务；
// 3.status：通知客户端当前的状态；
// 4.feedback：周期反馈任务运行的监控数据；
// 5.result：向客户端发送任务的执行结果，只发布一次。


 typedef actionlib::SimpleActionClient<learning_action::DoDishesAction> Client;
 //当action完成后会调用该回调函数一次
 void doneCb(const actionlib::SimpleClientGoalState& state, const learning_action::DoDishesResultConstPtr& result)
 {
     ROS_INFO("Yay! The dishes are now clean");
     ros::shutdown();
 }
 
 //当action激活后会调用该回调函数一次
 void activeCb()
 {
     ROS_INFO("Goal just went active");
 }
 
 //收到feedback后调用该回调函数
 void feedbackCb(const learning_action::DoDishesFeedbackConstPtr& feedback)
 {
     ROS_INFO(" percent_complete : %f ", feedback->percent_complete);
 }
 
 int main(int argc, char** argv)
 {
     //初始化ros节点
     ros::init(argc, argv, "do_dishes_client");
     
     //定义一个客户端
     Client client("do_dishes", true);
     
     //等待服务器端
     ROS_INFO("Waiting for action server to start.");
     client.waitForServer();//等待服务器,如果没有连接到服务器，会卡在这
     ROS_INFO("Action server started, sending goal.");
 
     //创建一个action的goal
     learning_action::DoDishesGoal goal;
     goal.dishwasher_id = 1;
     
     //发送action的goal给服务器端，并且设置回调函数
     client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
 
     ros::spin();
     
     return 0;
 }