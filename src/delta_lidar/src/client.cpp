/*
*  3iRoboticsLIDAR System II
*  Driver Interface
*
*  Copyright 2017 3iRobotics
*  All rights reserved.
*
*	Author: 3iRobotics, Data:2017-09-15
*
*/

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

#define RAD2DEG(x) ((x)*180./M_PI)

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    int count = scan->scan_time / scan->time_increment;//扫描的时间间隔/测量时间间隔
    //  ROS_INFO("I heard a laser scan %s[%d]:", scan->header.frame_id.c_str(), count);
    //  ROS_INFO("angle_range: %f, %f", RAD2DEG(scan->angle_min), RAD2DEG(scan->angle_max));

    //  while((scan->ranges[i])!='/0') {
    //     i++;}
  
    for(int i = 0; i < count; i++) {
        // float degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
        // ROS_INFO(": [%f, %f]", degree, scan->ranges[i]);
        // ROS_INFO("ranges: %f", scan->ranges[i]);//激光雷达的测量数据

        if (!std::isnan(scan->ranges[i])&&!std::isinf(scan->ranges[i]))//判断距离是否为无穷大,如果是无穷大,舍弃这个值,继续采样
        {
            ROS_INFO("ranges: %f", scan->ranges[i]);//激光雷达的测量数据
            // if((scan->ranges[i]>0)&&(scan->ranges[i]<0.20))
            // {
            //     ROS_INFO("Hit!!!"); 
            // }
            // else if((scan->ranges[i]>=0.20)&&(scan->ranges[i]<=5))
            // {
            //     ROS_INFO("Safe!"); 
            // }
        }
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "delta_2b_lidar_node_client");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scanCallback);//订阅激光类型数据

    ros::spin();

    return 0;
}
