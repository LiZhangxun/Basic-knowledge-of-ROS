//#include "ros/ros.h"
#include "learning_cplus_lei/test.h"


int main(int argc, char *argv[])
{
    //ros节点的初始化
	ros::init(argc, argv, "test_pub");
    Test test;
    ros::spin();
    return 0;
}