#include "ros/ros.h"
#include "simple_client_server/AddTwoInts.h" //是由编译系统自动根据我们先前创建的srv文件生成的对应该srv文件的头文件。

// service回调函数，输入参数req，输出参数res
//这个函数提供两个int值求和的服务，int值从request里面获取，而返回数据装入response内;
//这些数据类型都定义在srv文件内部，函数返回一个boolean值。
bool add(simple_client_server::AddTwoInts::Request &req,simple_client_server::AddTwoInts::Response &res)
{
    // 将输入参数中的请求数据相加，结果放到应答变量中
    res.sum = req.a + req.b;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);

    //现在，两个int值已经相加，并存入了response。
    //然后一些关于request和response的信息被记录下来。
    //最后，service完成计算后返回true值。
    return true;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "add_two_ints_server");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为add_two_ints的server，注册回调函数add()
    ros::ServiceServer service = n.advertiseService("add_two_ints", add);

    // 循环等待回调函数
    ROS_INFO("Ready to add two ints.");
    ROS_INFO("Waiting for client request....");
    ros::spin();

    return 0;
}