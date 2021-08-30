#include "ros/ros.h"        //导入ROS系统包含核心公共头文件
#include "std_msgs/String.h" //导入std_msgs/String消息头文件，这个是由std_msgs包的string.msg文件自动生成。

#include <sstream>


int main(int argc, char **argv)
{
  //初始化ROS节点，指定节点名称为“talker”，节点名称要保持唯一性
  ros::init(argc, argv, "talker");

  //创建节点句柄,实例化节点
  ros::NodeHandle n;

  //发布一个消息类型为std_msgs/String，命名为chatter的话题。
  //定义消息队列大小为1000，即超过1000条消息之后，旧的消息就会丢弃。
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  //指定发布消息的频率，这里指10Hz，也即每秒10次
  //通过 Rate::sleep()来处理睡眠的时间来控制对应的发布频率。
  ros::Rate loop_rate(10);

  int count = 0;
// 默认roscpp会植入一个SIGINT处理机制，当按下Ctrl-C，就会让ros::ok()返回false,那循环就会结束。
// ros::ok() 返回false的几种情况：
// 1.SIGINT收到(Ctrl-C)信号
// 2.另一个同名节点启动，会先中止之前的同名节点
// 3.ros::shutdown()被调用
// 4.所有的ros::NodeHandles被销毁
  while (ros::ok())
  {
    //实例化消息msg
    std_msgs::String msg;

    //定义字符串流“hello world”并赋值给ss, 最后转成为字符串赋值给msg.data  
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    //将字符打印在终端,输出调试信息;
    ROS_INFO("%s", msg.data.c_str());

    //实际发布的函数
    chatter_pub.publish(msg);

    //不是必需的，但是保持增加这个调用，是好习惯。
    //如果程序里也有订阅话题(指的是有回调函数)，就必需，否则回调函数不能起作用。
    ros::spinOnce();

    //根据之前ros::Rate loop_rate(10)的定义来控制发布话题的频率。定义10即为每秒10次
    loop_rate.sleep();

    count++;
  }


  return 0;
}