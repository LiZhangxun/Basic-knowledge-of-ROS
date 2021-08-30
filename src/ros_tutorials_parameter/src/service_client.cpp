#include "ros/ros.h"                          
#include "ros_tutorials_parameter/SrvTutorial.h"
#include <cstdlib>                            // 要从读取从终端输入的数据,必须包含该头文件

int main(int argc, char **argv)               
{
  // 初始化节点名称
  ros::init(argc, argv, "service_client");    

  if (argc != 3)  // 从终端输入两个数
  {
    ROS_INFO("function : operator two number");
    ROS_INFO("arg0: double number, arg1: double number");
    return 1;
  }

  ros::NodeHandle nh;// 初始化节点句柄

  //等待服务器启动
  ros::service::waitForService("/ros_tutorial_srv");

  //创建一个client,请求服务器，消息类型是ros_tutorials_parameter::SrvTutorial  //package名字::头文件名字
  ros::ServiceClient client = nh.serviceClient<ros_tutorials_parameter::SrvTutorial>("ros_tutorial_srv");//注意填服务端名字

  ros_tutorials_parameter::SrvTutorial srv;//实例化对象srv
  //通过终端输入这两个加数
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);

  //发布service请求，等待加法运算应答结果
  if (client.call(srv))//阻塞程序，如果服务器无响应，就会卡在这里
  {
    ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
    ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
  }
  else
  {
    ROS_ERROR("Failed to call service ros_tutorial_srv");
    return 1;
  }
  return 0;
}