#include <string>
#include <ros/ros.h>
#include <std_srvs/Empty.h>
//#include <iostream>
int main(int argc,char **argv)
{
    int red,green,blue;
    int new_red,new_green,new_blue;

    //ros节点初始化
    ros::init(argc, argv, "parameter_config");
    
    //创建节点句柄
    ros::NodeHandle node;

    //读取背景颜色参数
    ros::param::get("/background_r",red);
    ros::param::get("/background_g",green);
    ros::param::get("/background_b",blue);
    
    new_red=160;
    new_green=32;
    new_blue=240;
    //设置背景颜色参数
    ros::param::set("/background_r",new_red);
    ros::param::set("/background_g",new_green);
    ros::param::set("/background_b",new_blue);

    ROS_INFO("Set Background Color[new_red:%d,new_green:%d,new_blue:%d]",new_red,new_green,new_blue);

    //调用服务，刷新背景颜色
    ros::service::waitForService("/clear");
    ros::ServiceClient clear_background=node.serviceClient<std_srvs::Empty>("/clear");
    std_srvs::Empty srv;
    clear_background.call(srv);

    sleep(1);

    return 0;

}