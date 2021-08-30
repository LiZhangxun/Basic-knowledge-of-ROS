#include <ros/ros.h> // ROS的基本头文件
#include <cstdlib>
#include <actionlib/client/simple_action_client.h> // 动作库头文件
#include <actionlib/client/terminal_state.h> // 动作目标状态头文件
#include "learning_action2/FibonacciAction.h" // FibonacciAction动作头文件（构建后自动生成）

//当action完成后会调用该回调函数一次
 void doneCb(const actionlib::SimpleClientGoalState& state, const learning_action2::FibonacciResultConstPtr& result)
 {
     ROS_INFO("Yay! Everything had been done!");
     ros::shutdown();
 }
 
 //当action激活后会调用该回调函数一次
 void activeCb()
 {
     ROS_INFO("Goal just went active");
 }

//收到feedback后调用该回调函数
 void feedbackCb(const learning_action2::FibonacciFeedbackConstPtr& feedback)
 {
     ROS_INFO(" Already finish done: %d ", feedback->sequence[0]);
 }

int main (int argc, char **argv) // 节点主函数
{
    ros::init(argc, argv, "action_client"); // 初始化节点名称

    // 声明动作客户端（动作名称：ros_tutorial_action）
    actionlib::SimpleActionClient<learning_action2::FibonacciAction> ac("ros_tutorial_action", true);

     //从终端命令行获取goal_order
    if(argc !=2)
    {
        ROS_INFO("usage: please set a goal!");
        return 1;
    }

    ROS_INFO("Waiting for action server to start.");

    ac.waitForServer(); // 等待动作服务器启动

    ROS_INFO("Action server started, sending goal.");

    learning_action2::FibonacciGoal goal; // 声明动作目标
    goal.order = atoll(argv[1]); // 指定动作目标（进行n次斐波那契运算）,从终端输入
    ac.sendGoal(goal, &doneCb, &activeCb, &feedbackCb); // 发送动作目标并且注册回调函数(必须四个函数一起设置)

    // 设置动作完成时间限制（这里设置为30秒）
    bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

    // 在动作完成时限内收到动作结果值时
    if (finished_before_timeout)
    {
        // 获取动作目标状态值并将其显示在屏幕上
        actionlib::SimpleClientGoalState state = ac.getState();
        ROS_INFO("Action finished: %s",state.toString().c_str());
    }  
    else
        ROS_INFO("Action did not finish before the time out."); // 超过了动作完成时限的情况

 //exit
 return 0;
}