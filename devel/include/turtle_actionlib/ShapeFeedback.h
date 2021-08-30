// Generated by gencpp from file turtle_actionlib/ShapeFeedback.msg
// DO NOT EDIT!


#ifndef TURTLE_ACTIONLIB_MESSAGE_SHAPEFEEDBACK_H
#define TURTLE_ACTIONLIB_MESSAGE_SHAPEFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtle_actionlib
{
template <class ContainerAllocator>
struct ShapeFeedback_
{
  typedef ShapeFeedback_<ContainerAllocator> Type;

  ShapeFeedback_()
    {
    }
  ShapeFeedback_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct ShapeFeedback_

typedef ::turtle_actionlib::ShapeFeedback_<std::allocator<void> > ShapeFeedback;

typedef boost::shared_ptr< ::turtle_actionlib::ShapeFeedback > ShapeFeedbackPtr;
typedef boost::shared_ptr< ::turtle_actionlib::ShapeFeedback const> ShapeFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace turtle_actionlib

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'turtle_actionlib': ['/home/lizhangxun/ROS_C++/src/turtle_actionlib/msg', '/home/lizhangxun/ROS_C++/devel/share/turtle_actionlib/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::turtle_actionlib::ShapeFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtle_actionlib/ShapeFeedback";
  }

  static const char* value(const ::turtle_actionlib::ShapeFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
\n\
\n\
";
  }

  static const char* value(const ::turtle_actionlib::ShapeFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ShapeFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtle_actionlib::ShapeFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::turtle_actionlib::ShapeFeedback_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // TURTLE_ACTIONLIB_MESSAGE_SHAPEFEEDBACK_H
