#include "ros/ros.h"
#include <sstream>

// 如果NodeHandle创建时候有自己的命名空间，则访问私有名称就会有些麻烦。
// 代码：
// ros::init(argc, argv, "my_node_name");
// ros::NodeHandle nh("/my_node_handle_namespace");
// 那私有名称的如何求解？一些可选如：

// /my_node_handle_namespace/my_node_name/name
// my_node_name/my_node_handle_namespace/name
// /my_node_handle_namespace/name
// Something else entirely
// 因为这个原因，NodeHandle不允许直接通过私有名称作为参数传递或用nodehandle的构造函数作为参数。

//介绍如何访问NodeHandle类的私有名称
int main(int argc, char *argv[])
{
    //解决方案就是在实例化NodeHandle时候使用私有名称作为工作空间。
    ros::init(argc, argv, "my_node_name");

    //nh1的命名空间是 /my_node_name, and nh2的命名空间是/my_node_name/foo.
    ros::NodeHandle nh1("~");
    ros::NodeHandle nh2("~foo");

    // 下面的访问：
    // ros::NodeHandle nh;
    // nh.getParam("~name", ... );

    // 可替换成:
    // ros::NodeHandle nh("~");
    // nh.getParam("name", ... );

    return 0;
}