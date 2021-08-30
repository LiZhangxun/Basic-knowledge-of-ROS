#include "ros/ros.h"
#include "person_service/s_c_person.h"//头文件名字与数据类型名字一样

//service回调函数，输入参数req,输出参数res
bool personCallback(person_service::s_c_person::Request &req,person_service::s_c_person::Response &res)
 {
    //显示请求数据
    ROS_INFO("Person:name:%s age:%d sex:%d",req.name.c_str(),req.age,req.sex);

    //设置反馈数据
    res.result="OK";

    return true;
 }
int main(int argc,char**argv)
 {
     //ros节点初始化
     ros::init(argc,argv,"person_server");

     //创建节点句柄
     ros::NodeHandle n;

     //创建一个名为/show_person的server,注册回调函数personCallback
     ros::ServiceServer person_server=n.advertiseService("/show_person",personCallback);

     ROS_INFO("Ready to show person information.");
     //循环等待回调函数
	 ros::spin();

     return 0;
 }