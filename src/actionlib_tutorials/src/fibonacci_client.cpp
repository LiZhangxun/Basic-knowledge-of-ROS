#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>  //simple_action_client.h用来执行简单的action客户端
#include <actionlib/client/terminal_state.h>      //terminal_state.h 定义goal的状态
#include <actionlib_tutorials/FibonacciAction.h>  //由Fibonacci.action文件自动生成的头文件

int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_fibonacci");

  // action客户端依照action模板定义的消息类型与action服务器进行通讯
  // action客户端构造器需要提供两个参数：服务器名称和boolean选项（是否打开线程）
  actionlib::SimpleActionClient<actionlib_tutorials::FibonacciAction> ac("fibonacci", true);

  //action服务器可能没启动，客户端会等待服务器启动成功再继续。
  ROS_INFO("Waiting for action server to start.");
  ac.waitForServer(); 

  //创建goal消息，设置定值并发送给服务器。
  ROS_INFO("Action server started, sending goal.");
  actionlib_tutorials::FibonacciGoal goal;
  goal.order =10;
  ac.sendGoal(goal);

  //客户端等待服务器完成，时间间隔为30秒，超时则返回false
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    //如果服务器完成， goal的状态会被报告。
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
    actionlib_tutorials::FibonacciResult result = *(ac.getResult());
    std::stringstream result_string;

    std::copy(result.sequence.begin(), result.sequence.end(),std::ostream_iterator<int>(result_string, " "));
    ROS_INFO("Action result: %s", result_string.str().c_str());
  }
  else
    {
      ROS_INFO("Action did not finish before the time out.");
    }

  return 0;
}
