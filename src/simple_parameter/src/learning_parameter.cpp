#include "ros/ros.h"
#include <sstream>


// 一.获取参数

// 通过NodeHandle，有两种方式获取参数：(下面的例子，n是NodeHandle实例对象)
// 1.getParam()函数说明：
//    getParam函数可以进行重载，不过基本格式如下：
//    bool getParam (const std::string& key, parameter_type& output_value) const

//    1.key是参数名，命名方法参考:http://wiki.ros.org/Names

//    2.output_value用来保持参数的值

//    3.parameter_type类型包含bool, int, double, string, 或 特定的 XmlRpcValue 类型

//    4.XmlRpcValue类型包含所有类型，甚至是lists/maps

// 2.param()函数说明：
//    param类似getParam,不同是：在没有获取到参数值的时候，可以设置默认值。



int  main(int argc, char **argv)
{
    //初始化ROS节点，指定节点名称为“learning_parameter”，节点名称要保持唯一性
    ros::init(argc, argv, "learning_parameter");

    //创建节点句柄,实例化节点
    ros::NodeHandle n;

    // 1.getParam函数有一个布尔类型的返回值，可以通过它来表示是否获取参数成功
    // std::string s;
    // if (n.getParam("my_param", s))
    // {
    //     ROS_INFO("Got param: %s", s.c_str());
    // }
    // else
    // {
    //     ROS_ERROR("Failed to get param 'my_param'");
    // }

    // 2.param()函数类似getParam,不同是：在没有获取到参数值的时候，可以设置默认值。
    // int i;
    // n.param("my_num", i, 42);

    // 有时编译器需要字符串类型的提示。
    // std::string s;
    // n.param<std::string>("my_param", s, "default_value");//将参数值读出来赋给s,如果没有读出来,则设置s默认值为"default_value"

    // 3.通过setParam() 函数设置参数：
    // n.setParam("my_param", "hello there");

    // 4.删除参数:通过 deleteParam() 函数删除参数：
    // n.deleteParam("my_param");

    // 5.检查参数:这不是必需的，但有hasParam()可以实现检查
    // if (!n.hasParam("my_param"))
    // {
    //     ROS_INFO("No param named 'my_param'");
    // }

    // 6.搜索参数
    // 参数服务器允许你在你开始的工作空间或父工作空间进行搜索参数
    // 例如：如果参数服务器存在/a/b的参数，你的NodeHandle在/a/c工作空间，searchParam()搜索b会得到/a/b. 
    // 如果/a/c/b参数增加，搜索就会得到/a/c/b参数。
    // std::string param_name;
    // if (n.searchParam("b", param_name))
    // {
    //     // Found parameter, can now query it using param_name
    //     int i = 0;
    //     n.getParam(param_name, i);
    // }
    // else
    // {
    //     ROS_INFO("No param 'b' found in an upward search");
    // }

    return 0;

}
