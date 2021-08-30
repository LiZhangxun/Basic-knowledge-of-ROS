#include "ros/ros.h"                            
#include "ros_tutorials_parameter/SrvTutorial.h"

#define PLUS            1   // 加法
#define MINUS           2   // 减法
#define MULTIPLICATION  3   // 乘法
#define DIVISION        4   // 除法

int g_operator = PLUS;//设置默认方式为加法

// service回调函数，输入参数req，输出参数res
bool calculation(ros_tutorials_parameter::SrvTutorial::Request &req,
                 ros_tutorials_parameter::SrvTutorial::Response &res)
{
  //选择使用哪种方式对数据进行处理,并将结果存储到res中
  // 根据g_operator参数值进行a和b的运算
  // 计算后将结果保存到服务响应值中
  switch(g_operator)
  {
    case PLUS:
         res.result = req.a + req.b; break;
    case MINUS:
         res.result = req.a - req.b; break;
    case MULTIPLICATION:
         res.result = req.a * req.b; break;
    case DIVISION://除法的时候注意判断被除数的值
         if(req.b == 0)
         {
           res.result = 0; break;
         }
         else
         {
           res.result = req.a / req.b; break;
         }
  }

  //显示请求的两个数字和运算结果
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.result);

  return true;
}

int main(int argc, char **argv)             
{
  // 初始化节点名称
  ros::init(argc, argv, "service_server");  

  // 初始化节点句柄
  ros::NodeHandle nh;    

  //调取calculation_method参数并设置为g_operator的值
  // g_operator每0.1秒检查一次参数的值，并判断对于通过服务请求收到的值进行何种四则运算
  nh.setParam("calculation_method", PLUS);//初始化参数

  // 创建一个名为ros_tutorials_service_server的server，注册回调函数calculation()
  ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);

  ROS_INFO("Waiting for client request...!");

  //使用ros::Rate对象可以指定要循环的频率。它将跟踪自上次调用r.sleep（）以来的持续时间，并在正确的时间内休眠。
  //它的功能就是先设定一个频率，然后通过睡眠度过一个循环中剩下的时间，来达到该设定频率。如果能够达到该设定频率则返回true，不能则返回false。
  //计时的起点是上一次睡眠的时间
  ros::Rate r(10);


  //默认情况下，roscpp将安装一个SIGINT处理程序，该处理程序提供Ctrl-C处理，如果发生这种情况，将导致ros::ok（）返回false。

//  当以下情况之一发生时，ros::ok（）将返回false:
// ​ 1.接受到一个SIGINT（Ctrl+C)
// ​ 2.该节点已被另一个具有相同名称的节点踢出ROS网络
// ​ 3.程序的任何其他部分已将调用了ros::shutdown()
// ​ 4.所有的ros::NodeHandles已经被销毁
//  一旦ros::ok()返回false，所有的ROS调用都会失败

  while (ros::ok())
  {
    //每隔0.1s从参数服务器读取终端输入的值,将值赋值给g_operator,并将运算符改为通过参数收到的值。
    nh.getParam("calculation_method", g_operator); 
    
    //查看一次回调函数队列
    ros::spinOnce();//观察是否有数据进入

    // 为了反复进入进程而添加的sleep（暂歇）函数  
    r.sleep();        
  }

  return 0;
}