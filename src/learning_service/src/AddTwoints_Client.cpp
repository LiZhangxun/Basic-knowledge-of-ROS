#include <cstdlib>
#include <ros/ros.h>
#include <learning_service/AddTwoInts.h>

int main(int argc,char **argv)
{
    //ROS节点初始化
    ros::init(argc,argv,"add_twoints_client");
    
    //从终端命令行获取两个加数
    if(argc!=3)
    {
        ROS_INFO("usage: add_two_ints_client X Y");
        return 1;
    }
    //创建节点句柄
    ros::NodeHandle n;

    //创建一个client,请求服务器，消息类型是learning_service::AddTwoInts  //package名字::头文件名字
    //括注册客户端时,括号内填的是服务器的名称!!!
    ros::ServiceClient client=n.serviceClient<learning_service::AddTwoInts>("add_two_ints");

    //创建learing_service::AddTwoInts类型的service消息
    learning_service::AddTwoInts srv;//实例化对象srv
    srv.request.a=atoll(argv[1]);//通过终端输入这两个加数
    srv.request.b=atoll(argv[2]);

    //发布sservice请求，等待加法运算应答结果
    if(client.call(srv))//阻塞程序，如果服务器无响应，就会卡在这里
    {
        ROS_INFO("SUM : %ld",(long int)srv.response.sum);
    }
    else
    {
        ROS_ERROR("FAILED");
        return 1;
    }
    return 0;
}
