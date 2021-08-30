#include <ros/ros.h>
#include <turtlesim/Spawn.h>//spawn 是系统自带的turtlesim里面的
/**如何实现一个客户端
  *1.初始化ros节点
  *2.创建一个client实例
  *3.发布服务请求数据
  *4.等待server处理之后的应答结果
**/
int main(int argc,char**argv)
{
    //初始化ros节点
    ros::init(argc,argv,"turtle_client");//节点名字"turtle_client"

    //创建节点句柄
    ros::NodeHandle node;

    //发现spawn服务后，创建一个服务客户端,类型为turtlesim::Spawn，连接名为/spawn的service
    ros::service::waitForService("/spawn");//阻塞程序,循环等待这个服务.
    ros::ServiceClient add_turtle=node.serviceClient<turtlesim::Spawn>("/spawn");

    //初始化turtlesim::Spawn的请求数据
    turtlesim::Spawn srv;
    srv.request.x=4.5;
    srv.request.y=5.544445;
    srv.request.theta=3.14;//海龟的角度(弧度)
    srv.request.name="turtle2";//海龟的名字

    //请求服务调用
    ROS_INFO("Call service to spawn turtle[x:%0.6f,y:%0.6f,name:%s]",
    srv.request.x,srv.request.y,srv.request.name.c_str());

    add_turtle.call(srv);//请求客户端,阻塞程序,在此处等待回应.

    //显示服务结果
    ROS_INFO("spawn turtle successfully! [name:%s]",srv.response.name.c_str());

    return 0;
}