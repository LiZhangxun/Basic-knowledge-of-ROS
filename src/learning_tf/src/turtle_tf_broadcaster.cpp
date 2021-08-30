#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>


//在命令行输入rosrun learning_tf turtle_tf_broadcaster __name:=turtle2_tf_broadcaster /turtle2
//在命令行输入rosrun learning_tf turtle_tf_broadcaster __name:=turtle1_tf_broadcaster /turtle1

/*如何实现一个tf广播器
1.定义tf广播器
2.创建坐标变换值
3.发布坐标变换
*/

std::string turtle_name;
 
void poseCallback(const turtlesim::PoseConstPtr& msg)
{
  //创建tf广播器
  static tf::TransformBroadcaster br;

  //初始化tf数据(包括平移和旋转)
  tf::Transform transform;

  //设置平移姿态数据(x,y,z),由于是平面，所以z为0
  transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0));

  //设置旋转姿态数据
  tf::Quaternion q;
  q.setRPY(0, 0, msg->theta);//围绕x轴，y轴，z轴的旋转角度
  transform.setRotation(q);

  //广播world与海龟两个坐标系之间的tf数据,把transform发布出去
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char** argv)
{
  //初始化ros节点
  ros::init(argc, argv, "my_tf_broadcaster");

  //输入参数作为海龟名字
  if (argc != 2)
  {
      ROS_ERROR("need turtle name as argument");
      return -1;
  }
  turtle_name = argv[1];//获取海龟名字

  //创建节点句柄
  ros::NodeHandle node;

  //订阅海龟位姿话题
  ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, poseCallback);

 //循环等待回调函数
  ros::spin();

  return 0;
}
