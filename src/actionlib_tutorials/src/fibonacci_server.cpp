#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h> //是action库，用来执行简单的actions
#include <actionlib_tutorials/FibonacciAction.h>//这个头文件是由Fibonacci.action自动生成。

class FibonacciAction
{
protected:

  //创建多个私有变量，节点实例化变量;
  ros::NodeHandle nh_;

  //创建action服务端
  actionlib::SimpleActionServer<actionlib_tutorials::FibonacciAction> as_; 

  //保存服务端名称
  std::string action_name_;

  //actionlib实例化变量，保存反馈的feedback_变量，保存结果的result_变量
  actionlib_tutorials::FibonacciFeedback feedback_;
  actionlib_tutorials::FibonacciResult result_;

public:

  //构造函数，并初始化函数，创建action服务器。需要提供action名称，节点实例变量，可选的executeCB变量。
  FibonacciAction(std::string name) :
    as_(nh_, name, boost::bind(&FibonacciAction::executeCB, this, _1), false),
    action_name_(name)
  {
    //启动服务端
    as_.start();
    ROS_INFO("Server start!");
  }

  ~FibonacciAction(void)
  {
  }
  //executeCB函数引用在构造函数中创建，回调函数传递boost的共享指针类型ConstPtr的goal作为参数
  void executeCB(const actionlib_tutorials::FibonacciGoal::ConstPtr &goal)
  {
    //设置循环频率
    ros::Rate r(1);
    bool success = true;

    //将斐波那契的初值 以push_back方法尾插至容器中
    feedback_.sequence.clear();
    feedback_.sequence.push_back(0);
    feedback_.sequence.push_back(1);

    //输出初始化信息至终端
    ROS_INFO("%s: Executing, creating fibonacci sequence of order %i with seeds %i, %i", action_name_.c_str(), goal->order, feedback_.sequence[0], feedback_.sequence[1]);

    //开始计算斐波那契数列
    for(int i=1; i<=goal->order; i++)
    {
      //检查目标是否在终端被取消
      if (as_.isPreemptRequested() || !ros::ok())
      {
        ROS_INFO("%s: Preempted", action_name_.c_str());
        //停止action
        as_.setPreempted();
        success = false;
        break;
      }
      feedback_.sequence.push_back(feedback_.sequence[i] + feedback_.sequence[i-1]);
      //发布反馈结果
      as_.publishFeedback(feedback_);
      //以一定频率休眠
      r.sleep();
    }
    //如果发送成功
    if(success)
    {
      result_.sequence = feedback_.sequence;
      ROS_INFO("%s: Succeeded", action_name_.c_str());
      //将result返回
      as_.setSucceeded(result_);
    }
  }


};

//main函数实现开始action，并启动线程处理，运行和等待去接受goal值传入
int main(int argc, char** argv)
{
  ros::init(argc, argv, "fibonacci");

  //实例化斐波那契数列对象,自动调用构造函数,创建节点句柄,实例化节点对象
  FibonacciAction fibonacci("fibonacci");

  ros::spin();

  return 0;
}
