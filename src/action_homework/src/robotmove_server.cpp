#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "action_homework/robot_moveAction.h"

typedef actionlib::SimpleActionServer<action_homework::robot_moveAction> Server;

//收到action的goal后调用该回调函数
void execute (const action_homework::robot_moveGoalConstPtr& goal,Server* as)
{
    ros::Rate r(1);
    action_homework::robot_moveFeedback feedback;
    action_homework::robot_moveResult result;

    ROS_INFO("Success connect!");
    ROS_INFO("set robot goal to (%0.5f,%0.5f)!", goal->pose_x,goal->pose_y);

    //假设机器人移动的进度，并且按照１ＨＺ的频率发布进度feedback
    for (int i = 1; i <= 5; i++)
    {
         feedback.percent_complete = i * 20;
         as->publishFeedback(feedback);//反馈数据给客户端
         r.sleep();//休眠1s
    }

    //当action完成后，向客户端返回结果
     ROS_INFO("robot move to (%0.5f,%0.5f)!", result.finalpose_x, result.finalpose_y);
     as->setSucceeded();//通知客户端任务完成
}
 int main(int argc, char** argv)
{
     //初始化ros节点
     ros::init(argc, argv, "robotmove_server");

     //创建节点句柄
     ros::NodeHandle n;

     //定义一个服务器
     Server server(n, "robotmove", boost::bind(&execute, _1, &server), false);//绑定了回调函数execute
 
     //服务器开始运行
     server.start();
 
     ros::spin();
     return 0;
}