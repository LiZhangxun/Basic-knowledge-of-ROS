#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <actionlib/server/simple_action_server.h> //action库，用于实现简单的action服务器
#include <actionlib_tutorials/AveragingAction.h>//这个头文件是Averaging.action文件自动生成的消息头文件

class AveragingAction
{
public:

  // action构造器，创建action服务器。
  // action服务器需要提供节点句柄，服务器名称，可选的executeCB参数。
  // 本例不使用executeCB参数，而是在构造函数里注册goal和preempt回调函数。   
  AveragingAction(std::string name) : 
    as_(nh_, name, false),
    action_name_(name)
  {
    //register the goal and feeback callbacks
    as_.registerGoalCallback(boost::bind(&AveragingAction::goalCB, this));
    as_.registerPreemptCallback(boost::bind(&AveragingAction::preemptCB, this));

    //订阅输入的数据，并定义数据处理的回调函数
    sub_ = nh_.subscribe("/random_number", 1, &AveragingAction::analysisCB, this);
    as_.start();
  }

  ~AveragingAction(void)
  {
  }
// 这里是在构造函数中引用的goalCB函数。
// 回调函数不返回任何内容，并且不带参数。
// 当goalCB被调用时，action需要接受goal并存储任何重要信息。
// 如果您需要在接受目标之前查看目标，请参阅SimpleActionServer（ExecuteCallbackMethod）教程。  
  void goalCB()
  {
    // reset helper variables
    data_count_ = 0;
    sum_ = 0;
    sum_sq_ = 0;
    // accept the new goal
    goal_ = as_.acceptNewGoal()->samples;
  }
// 此操作是事件驱动的，操作代码仅在回调发生时运行，因此创建抢占回调以确保操作快速响应取消请求。
// 回调函数不带参数，设置优先抢占处理。
  void preemptCB()
  {
    ROS_INFO("%s: Preempted", action_name_.c_str());
    // 取消目标
    as_.setPreempted();
  }
// 这里，分析回调采用订阅数据通道的消息格式，并在继续处理数据之前检查动作是否仍处于活动状态。
  void analysisCB(const std_msgs::Float32::ConstPtr& msg)
  {
    // 检查目标是否被取消
    if (!as_.isActive())
      return;
    
    data_count_++;
    feedback_.sample = data_count_;
    feedback_.data = msg->data;
    //compute the std_dev and mean of the data 
    sum_ += msg->data;
    feedback_.mean = sum_ / data_count_;
    sum_sq_ += pow(msg->data, 2);
    feedback_.std_dev = sqrt(fabs((sum_sq_/data_count_) - pow(feedback_.mean, 2)));
    as_.publishFeedback(feedback_);

    if(data_count_ > goal_) 
    {
      result_.mean = feedback_.mean;
      result_.std_dev = feedback_.std_dev;

      if(result_.mean < 5.0)
      {
        ROS_INFO("%s: Aborted", action_name_.c_str());
        //set the action state to aborted
        as_.setAborted(result_);
      }
      else 
      {
        ROS_INFO("%s: Succeeded", action_name_.c_str());
        // set the action state to succeeded
        as_.setSucceeded(result_);
      }
    } 
  }

protected:
    
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<actionlib_tutorials::AveragingAction> as_;
  std::string action_name_;
  int data_count_, goal_;
  float sum_, sum_sq_;
  actionlib_tutorials::AveragingFeedback feedback_;
  actionlib_tutorials::AveragingResult result_;
  ros::Subscriber sub_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "averaging");

  AveragingAction averaging(ros::this_node::getName());//将节点名字传给构造函数

  ros::spin();
  return 0;
}
