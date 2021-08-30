#include <cstdlib>
#include <ros/ros.h>
#include <simple_client_server/AddTwoInts.h>  //是由编译系统自动根据我们先前创建的srv文件生成的对应该srv文件的头文件。

int main(int argc,char **argv)
{
    //ROS节点初始化
    ros::init(argc,argv,"add_twoints_client");
    
    //从终端命令行获取两个加数
    if(argc !=3)
    {
        ROS_INFO("usage: add_two_ints_client X Y");
        return 1;
    }
    //创建节点句柄
    ros::NodeHandle n;

     //等待服务器启动
    ros::service::waitForService("/add_two_ints");
    ROS_INFO("Waiting for service start...");

    //创建一个client,simple_client_server::AddTwoInts  //package名字::头文件名字
    //括注册客户端时,括号内填的是服务器的名称!!!
    ros::ServiceClient client=n.serviceClient<simple_client_server::AddTwoInts>("add_two_ints");

    //创建learing_service::AddTwoInts类型的service消息
    simple_client_server::AddTwoInts srv;//实例化对象srv
    srv.request.a=atoll(argv[1]);//通过终端输入这两个加数
    srv.request.b=atoll(argv[2]);

    // 发布service请求，等待加法运算应答结果
    // 由于service的调用是模态过程（调用的时候占用进程阻止其他代码的执行），一旦调用完成，将返回调用结果。
    // 如果service调用成功，call()函数将返回true，srv.response里面的值将是合法的值。
    // 如果调用失败，call()函数将返回false，srv.response里面的值将是非法的。
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