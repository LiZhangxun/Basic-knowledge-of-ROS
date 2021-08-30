// Generated by gencpp from file person_service/s_c_personResponse.msg
// DO NOT EDIT!


#ifndef PERSON_SERVICE_MESSAGE_S_C_PERSONRESPONSE_H
#define PERSON_SERVICE_MESSAGE_S_C_PERSONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace person_service
{
template <class ContainerAllocator>
struct s_c_personResponse_
{
  typedef s_c_personResponse_<ContainerAllocator> Type;

  s_c_personResponse_()
    : result()  {
    }
  s_c_personResponse_(const ContainerAllocator& _alloc)
    : result(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::person_service::s_c_personResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::person_service::s_c_personResponse_<ContainerAllocator> const> ConstPtr;

}; // struct s_c_personResponse_

typedef ::person_service::s_c_personResponse_<std::allocator<void> > s_c_personResponse;

typedef boost::shared_ptr< ::person_service::s_c_personResponse > s_c_personResponsePtr;
typedef boost::shared_ptr< ::person_service::s_c_personResponse const> s_c_personResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::person_service::s_c_personResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::person_service::s_c_personResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace person_service

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::person_service::s_c_personResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::person_service::s_c_personResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::person_service::s_c_personResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::person_service::s_c_personResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::person_service::s_c_personResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::person_service::s_c_personResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::person_service::s_c_personResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c22f2a1ed8654a0b365f1bb3f7ff2c0f";
  }

  static const char* value(const ::person_service::s_c_personResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc22f2a1ed8654a0bULL;
  static const uint64_t static_value2 = 0x365f1bb3f7ff2c0fULL;
};

template<class ContainerAllocator>
struct DataType< ::person_service::s_c_personResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "person_service/s_c_personResponse";
  }

  static const char* value(const ::person_service::s_c_personResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::person_service::s_c_personResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string result\n\
";
  }

  static const char* value(const ::person_service::s_c_personResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::person_service::s_c_personResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct s_c_personResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::person_service::s_c_personResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::person_service::s_c_personResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PERSON_SERVICE_MESSAGE_S_C_PERSONRESPONSE_H
