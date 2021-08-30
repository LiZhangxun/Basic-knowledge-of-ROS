#include "ros/ros.h"
#include "person_service/s_c_person.h"//头文件名字与数据类型名字一样

int main(int argc,char**argv)
{
    //初始化ros节点
    ros::init(argc,argv,"person_client");//节点名字"person_client"

    //创建节点句柄
    ros::NodeHandle node;

    //等待服务器启动，创建一个服务客户端,类型为person_service，名字为s_c_person（.h的文件名），连接名为/show_person的service
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client=node.serviceClient<person_service::s_c_person>("/show_person");

    //初始化person_service::s_c_person的请求数据
    person_service::s_c_person srv;
    srv.request.name="lzx";
    srv.request.age=20;
    srv.request.sex=person_service::s_c_person::Request::male;

    //请求服务调用
    ROS_INFO("Call service to show person[name:%s, age:%d,sex:%d]",
    srv.request.name.c_str(),srv.request.age,srv.request.sex);

    person_client.call(srv);//请求客户端

    //显示服务结果
    ROS_INFO("show person result:%s",srv.response.result.c_str());

    return 0;
}