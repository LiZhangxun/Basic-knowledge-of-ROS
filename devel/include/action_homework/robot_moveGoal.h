// Generated by gencpp from file action_homework/robot_moveGoal.msg
// DO NOT EDIT!


#ifndef ACTION_HOMEWORK_MESSAGE_ROBOT_MOVEGOAL_H
#define ACTION_HOMEWORK_MESSAGE_ROBOT_MOVEGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace action_homework
{
template <class ContainerAllocator>
struct robot_moveGoal_
{
  typedef robot_moveGoal_<ContainerAllocator> Type;

  robot_moveGoal_()
    : pose_x(0.0)
    , pose_y(0.0)  {
    }
  robot_moveGoal_(const ContainerAllocator& _alloc)
    : pose_x(0.0)
    , pose_y(0.0)  {
  (void)_alloc;
    }



   typedef float _pose_x_type;
  _pose_x_type pose_x;

   typedef float _pose_y_type;
  _pose_y_type pose_y;





  typedef boost::shared_ptr< ::action_homework::robot_moveGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::action_homework::robot_moveGoal_<ContainerAllocator> const> ConstPtr;

}; // struct robot_moveGoal_

typedef ::action_homework::robot_moveGoal_<std::allocator<void> > robot_moveGoal;

typedef boost::shared_ptr< ::action_homework::robot_moveGoal > robot_moveGoalPtr;
typedef boost::shared_ptr< ::action_homework::robot_moveGoal const> robot_moveGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::action_homework::robot_moveGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::action_homework::robot_moveGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace action_homework

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'action_homework': ['/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::action_homework::robot_moveGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::action_homework::robot_moveGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::action_homework::robot_moveGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::action_homework::robot_moveGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::action_homework::robot_moveGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::action_homework::robot_moveGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::action_homework::robot_moveGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9fb7694c5d0ece70c45eb28c876fc79c";
  }

  static const char* value(const ::action_homework::robot_moveGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9fb7694c5d0ece70ULL;
  static const uint64_t static_value2 = 0xc45eb28c876fc79cULL;
};

template<class ContainerAllocator>
struct DataType< ::action_homework::robot_moveGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "action_homework/robot_moveGoal";
  }

  static const char* value(const ::action_homework::robot_moveGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::action_homework::robot_moveGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#定义目标信息goal\n\
float32 pose_x\n\
float32 pose_y\n\
";
  }

  static const char* value(const ::action_homework::robot_moveGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::action_homework::robot_moveGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pose_x);
      stream.next(m.pose_y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct robot_moveGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::action_homework::robot_moveGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::action_homework::robot_moveGoal_<ContainerAllocator>& v)
  {
    s << indent << "pose_x: ";
    Printer<float>::stream(s, indent + "  ", v.pose_x);
    s << indent << "pose_y: ";
    Printer<float>::stream(s, indent + "  ", v.pose_y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ACTION_HOMEWORK_MESSAGE_ROBOT_MOVEGOAL_H
