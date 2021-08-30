#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h> //可以使用命令行来查看已有服务的数据类型 rossrv show std_srvs/Trigger
/**
---(无request数据)
bool success
string message
**/

/**如何实现一个服务器
  *1.初始化ros节点
  *2.创建Server实例
  *3.循环等待服务请求，进入回调函数
  *4.在回调函数中完成服务功能的处理，并反馈应答数据
**/

//此服务端需要通过终端的rosservice call 来手动发送请求
//ros::Publisherturtle_vel_pub;//创建全局的发布者 turtle_vel_pub
 bool pubCommand=false;//设置标志位默认为false

 //service回调函数，输入参数req，输出参数res
 bool commandCallback(std_srvs::Trigger::Request &req,std_srvs::Trigger::Response &res)//请求request数据此处为空(req无)
 {
    pubCommand=!pubCommand;//每调用一次就取反一次（即将乌龟状态反转）

    //显示请求数据
    ROS_INFO("Publish turtle velocity command[%s]",pubCommand==true?"yes":"no");

    //设置反馈数据
    res.success=true;
    if(pubCommand==true)
    {
        res.message="Change turtle command state to 'Yes'!";
    }
    else
    {
        res.message="Change turtle command state to 'No'!";
    }

    return true;
 }

 int main(int argc,char**argv)
 {
     //ros节点初始化
     ros::init(argc,argv,"turtle_server");

     //创建节点句柄
     ros::NodeHandle n;

     //创建一个名为/turtle_command的server,注册回调函数commandcallback
     ros::ServiceServer command_service=n.advertiseService("/turtle_command",commandCallback);

     //创建一个PUBLISHER，发布名为/turtle1/cmd_vel的topic,消息类型为geometry_msgs::Twist,队列长度为10
     ros::Publisher turtle_vel_pub=n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);//发布速度指令，让海龟动起来

     //循环等待回调函数
     ROS_INFO("Ready to receive turtle command.");

     //设置循环频率
     ros::Rate loop_rate(10);

     while(ros::ok())
     {
        //查看一次回调函数队列
        ros::spinOnce();//观察是否有数据进入

        //如果标志为true,则发布速度指令
        if(pubCommand)
        {
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x=0.5;
            vel_msg.angular.z=0.5;
            turtle_vel_pub.publish(vel_msg);
        }

        //按照循环频率延时
        loop_rate.sleep();
     }
     return 0;
 }