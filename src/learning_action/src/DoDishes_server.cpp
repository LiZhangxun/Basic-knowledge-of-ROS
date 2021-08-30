#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "learning_action/DoDishesAction.h"

typedef actionlib::SimpleActionServer<learning_action::DoDishesAction> Server;

//收到action的goal后调用该回调函数
void execute (const learning_action::DoDishesGoalConstPtr& goal,Server* as)
{
    ros::Rate r(1);
    learning_action::DoDishesFeedback feedback;

    ROS_INFO("Success connect!");
    ROS_INFO("Disheswasher %d is working.", goal->dishwasher_id);

    //假设洗盘子的进度，并且按照１ＨＺ的频率发布进度feedback
    for (int i = 1; i <= 10; i++)
    {
         feedback.percent_complete = i * 10;
         as->publishFeedback(feedback);//反馈数据给客户端
         r.sleep();//休眠1s
    }

    //当action完成后，向客户端返回结果
    ROS_INFO("Dishwasher %d finish working.", goal->dishwasher_id);
    as->setSucceeded();//通知客户端任务完成
    ros::shutdown();//关闭服务器
}
 int main(int argc, char** argv)
{
     //初始化ros节点
     ros::init(argc, argv, "do_dishes_server");

     //创建节点句柄
     ros::NodeHandle n;

     //定义一个服务器
     Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);//绑定了回调函数execute
 
     //服务器开始运行
     server.start();
 
     ros::spin();
     return 0;
}