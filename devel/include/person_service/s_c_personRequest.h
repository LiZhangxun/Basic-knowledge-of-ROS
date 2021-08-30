// Generated by gencpp from file person_service/s_c_personRequest.msg
// DO NOT EDIT!


#ifndef PERSON_SERVICE_MESSAGE_S_C_PERSONREQUEST_H
#define PERSON_SERVICE_MESSAGE_S_C_PERSONREQUEST_H


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
struct s_c_personRequest_
{
  typedef s_c_personRequest_<ContainerAllocator> Type;

  s_c_personRequest_()
    : name()
    , age(0)
    , sex(0)  {
    }
  s_c_personRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , age(0)
    , sex(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef uint8_t _age_type;
  _age_type age;

   typedef uint8_t _sex_type;
  _sex_type sex;



  enum {
    unknown = 0u,
    male = 1u,
    female = 2u,
  };


  typedef boost::shared_ptr< ::person_service::s_c_personRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::person_service::s_c_personRequest_<ContainerAllocator> const> ConstPtr;

}; // struct s_c_personRequest_

typedef ::person_service::s_c_personRequest_<std::allocator<void> > s_c_personRequest;

typedef boost::shared_ptr< ::person_service::s_c_personRequest > s_c_personRequestPtr;
typedef boost::shared_ptr< ::person_service::s_c_personRequest const> s_c_personRequestConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::person_service::s_c_personRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::person_service::s_c_personRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::person_service::s_c_personRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::person_service::s_c_personRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::person_service::s_c_personRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::person_service::s_c_personRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::person_service::s_c_personRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::person_service::s_c_personRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::person_service::s_c_personRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b3f7ec37d11629ec3010e27635cf22a9";
  }

  static const char* value(const ::person_service::s_c_personRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb3f7ec37d11629ecULL;
  static const uint64_t static_value2 = 0x3010e27635cf22a9ULL;
};

template<class ContainerAllocator>
struct DataType< ::person_service::s_c_personRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "person_service/s_c_personRequest";
  }

  static const char* value(const ::person_service::s_c_personRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::person_service::s_c_personRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
uint8 age\n\
uint8 sex\n\
\n\
uint8 unknown=0\n\
uint8 male=1\n\
uint8 female=2\n\
";
  }

  static const char* value(const ::person_service::s_c_personRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::person_service::s_c_personRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.age);
      stream.next(m.sex);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct s_c_personRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::person_service::s_c_personRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::person_service::s_c_personRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "age: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.age);
    s << indent << "sex: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sex);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PERSON_SERVICE_MESSAGE_S_C_PERSONREQUEST_H