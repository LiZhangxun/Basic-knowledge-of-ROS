#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib_tutorials/FibonacciAction.h>

using namespace actionlib_tutorials;
typedef actionlib::SimpleActionClient<FibonacciAction> Client;

class MyNode
{
public:
  //初始化客户端,给ac赋值
  MyNode(): ac("fibonacci", true)
  {
    ROS_INFO("Waiting for action server to start.");
    ac.waitForServer();
    //成功连上了服务器
    ROS_INFO("Action server started, sending goal.");
  }

  void doStuff(int order)
  {
    FibonacciGoal goal;
    goal.order = order;

    // 也可参考learning_ros里面的注册activecb函数和feedback_cb函数来写;
    ac.sendGoal(goal,
                boost::bind(&MyNode::doneCb, this, _1, _2),
                Client::SimpleActiveCallback(),
                Client::SimpleFeedbackCallback());

  }

  void doneCb(const actionlib::SimpleClientGoalState& state,
              const FibonacciResultConstPtr& result)
  {
    ROS_INFO("Finished in state [%s]", state.toString().c_str());
    ROS_INFO("Answer: %i", result->sequence.back());
    ros::shutdown();
  }

private:
  //实例化对象ac
  Client ac;
};

int main (int argc, char **argv)
{
  //初始化action客户端节点
  ros::init(argc, argv, "test_fibonacci_class_client");

  //实例化类对象
  MyNode my_node;

  //设定目标为10
  my_node.doStuff(10);

  //循环等待
  ros::spin();

  return 0;
}
