#include <ros/ros.h>
///注意这种方式是采用>.h和.cpp分开编写,并且创建的是include下,在里面编写.h文件;
#ifndef TEST_H
#define TEST_H

class Test 
{
public:
    Test();//Test类的构造函数
    ~Test();////Test类的析构函数
private:
    ros::NodeHandle n;//ROS节点句柄
    ros::Publisher pub;
    // ros::Subscriber sub;
};

#endif // TEST_H