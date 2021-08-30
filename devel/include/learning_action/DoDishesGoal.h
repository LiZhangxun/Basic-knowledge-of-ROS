// Generated by gencpp from file learning_action/DoDishesGoal.msg
// DO NOT EDIT!


#ifndef LEARNING_ACTION_MESSAGE_DODISHESGOAL_H
#define LEARNING_ACTION_MESSAGE_DODISHESGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace learning_action
{
template <class ContainerAllocator>
struct DoDishesGoal_
{
  typedef DoDishesGoal_<ContainerAllocator> Type;

  DoDishesGoal_()
    : dishwasher_id(0)  {
    }
  DoDishesGoal_(const ContainerAllocator& _alloc)
    : dishwasher_id(0)  {
  (void)_alloc;
    }



   typedef uint32_t _dishwasher_id_type;
  _dishwasher_id_type dishwasher_id;





  typedef boost::shared_ptr< ::learning_action::DoDishesGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learning_action::DoDishesGoal_<ContainerAllocator> const> ConstPtr;

}; // struct DoDishesGoal_

typedef ::learning_action::DoDishesGoal_<std::allocator<void> > DoDishesGoal;

typedef boost::shared_ptr< ::learning_action::DoDishesGoal > DoDishesGoalPtr;
typedef boost::shared_ptr< ::learning_action::DoDishesGoal const> DoDishesGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learning_action::DoDishesGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learning_action::DoDishesGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace learning_action

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'learning_action': ['/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::learning_action::DoDishesGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_action::DoDishesGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_action::DoDishesGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_action::DoDishesGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_action::DoDishesGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_action::DoDishesGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learning_action::DoDishesGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "65bd9e09a531006f4ecdeabe719004b9";
  }

  static const char* value(const ::learning_action::DoDishesGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x65bd9e09a531006fULL;
  static const uint64_t static_value2 = 0x4ecdeabe719004b9ULL;
};

template<class ContainerAllocator>
struct DataType< ::learning_action::DoDishesGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learning_action/DoDishesGoal";
  }

  static const char* value(const ::learning_action::DoDishesGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learning_action::DoDishesGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#定义目标信息goal\n\
uint32 dishwasher_id\n\
#Specify which dishwasher we want to use\n\
";
  }

  static const char* value(const ::learning_action::DoDishesGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learning_action::DoDishesGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dishwasher_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DoDishesGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learning_action::DoDishesGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learning_action::DoDishesGoal_<ContainerAllocator>& v)
  {
    s << indent << "dishwasher_id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.dishwasher_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARNING_ACTION_MESSAGE_DODISHESGOAL_H
