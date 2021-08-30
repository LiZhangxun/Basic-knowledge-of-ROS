#include "ros/ros.h"
#include "delta_lidar/Laser_distance.h"
//创建一个订阅者,订阅雷达的距离信息(自定义数据类型),修改了雷达的源码,直接调用雷达的距离信息进行分析

void distanceCallback(const delta_lidar::Laser_distance::ConstPtr& distance)
{
    //ROS_INFO("distance: %f", distance->distance);//激光雷达的距离数据
    if (!std::isnan(distance->distance)&&!std::isinf(distance->distance))//判断距离是否为无穷大,如果是无穷大,舍弃这个值,继续采样
    {
        if((distance->distance>0)&&(distance->distance<0.50))
            {
                ROS_INFO("Hit!!!"); 
            }
            else if((distance->distance>=0.50)&&(distance->distance<=5))
            {
                ROS_INFO("Safe!"); 
            }
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "distance_client");
    ros::NodeHandle n;

    //订阅距离类型数据
    ros::Subscriber sub = n.subscribe<delta_lidar::Laser_distance>("/distance_pub", 1000, distanceCallback);

    ROS_INFO("Waiting for laser distance.....");
    ros::spin();

    return 0;
}
