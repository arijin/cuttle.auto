// Generated by gencpp from file vector_map_msgs/WaterArea.msg
// DO NOT EDIT!


#ifndef VECTOR_MAP_MSGS_MESSAGE_WATERAREA_H
#define VECTOR_MAP_MSGS_MESSAGE_WATERAREA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vector_map_msgs
{
template <class ContainerAllocator>
struct WaterArea_
{
  typedef WaterArea_<ContainerAllocator> Type;

  WaterArea_()
    : id(0)
    , kid(0)
    , slid(0)
    , elid(0)
    , connectid(0)  {
    }
  WaterArea_(const ContainerAllocator& _alloc)
    : id(0)
    , kid(0)
    , slid(0)
    , elid(0)
    , connectid(0)  {
  (void)_alloc;
    }



   typedef int32_t _id_type;
  _id_type id;

   typedef int32_t _kid_type;
  _kid_type kid;

   typedef int32_t _slid_type;
  _slid_type slid;

   typedef int32_t _elid_type;
  _elid_type elid;

   typedef int32_t _connectid_type;
  _connectid_type connectid;





  typedef boost::shared_ptr< ::vector_map_msgs::WaterArea_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vector_map_msgs::WaterArea_<ContainerAllocator> const> ConstPtr;

}; // struct WaterArea_

typedef ::vector_map_msgs::WaterArea_<std::allocator<void> > WaterArea;

typedef boost::shared_ptr< ::vector_map_msgs::WaterArea > WaterAreaPtr;
typedef boost::shared_ptr< ::vector_map_msgs::WaterArea const> WaterAreaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vector_map_msgs::WaterArea_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vector_map_msgs::WaterArea_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::vector_map_msgs::WaterArea_<ContainerAllocator1> & lhs, const ::vector_map_msgs::WaterArea_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.kid == rhs.kid &&
    lhs.slid == rhs.slid &&
    lhs.elid == rhs.elid &&
    lhs.connectid == rhs.connectid;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::vector_map_msgs::WaterArea_<ContainerAllocator1> & lhs, const ::vector_map_msgs::WaterArea_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace vector_map_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vector_map_msgs::WaterArea_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vector_map_msgs::WaterArea_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vector_map_msgs::WaterArea_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c3d76e4604dd439eb4bc0783df641df8";
  }

  static const char* value(const ::vector_map_msgs::WaterArea_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc3d76e4604dd439eULL;
  static const uint64_t static_value2 = 0xb4bc0783df641df8ULL;
};

template<class ContainerAllocator>
struct DataType< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vector_map_msgs/WaterArea";
  }

  static const char* value(const ::vector_map_msgs::WaterArea_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Ver 1.00\n"
"int32 id\n"
"int32 kid\n"
"int32 slid\n"
"int32 elid\n"
"int32 connectid\n"
;
  }

  static const char* value(const ::vector_map_msgs::WaterArea_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.kid);
      stream.next(m.slid);
      stream.next(m.elid);
      stream.next(m.connectid);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WaterArea_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vector_map_msgs::WaterArea_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vector_map_msgs::WaterArea_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
    s << indent << "kid: ";
    Printer<int32_t>::stream(s, indent + "  ", v.kid);
    s << indent << "slid: ";
    Printer<int32_t>::stream(s, indent + "  ", v.slid);
    s << indent << "elid: ";
    Printer<int32_t>::stream(s, indent + "  ", v.elid);
    s << indent << "connectid: ";
    Printer<int32_t>::stream(s, indent + "  ", v.connectid);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VECTOR_MAP_MSGS_MESSAGE_WATERAREA_H