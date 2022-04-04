// Generated by gencpp from file autoware_msgs/GridMapInfo.msg
// DO NOT EDIT!


#ifndef AUTOWARE_MSGS_MESSAGE_GRIDMAPINFO_H
#define AUTOWARE_MSGS_MESSAGE_GRIDMAPINFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <grid_map_msgs/GridMap.h>
#include <geometry_msgs/Transform.h>

namespace autoware_msgs
{
template <class ContainerAllocator>
struct GridMapInfo_
{
  typedef GridMapInfo_<ContainerAllocator> Type;

  GridMapInfo_()
    : header()
    , map()
    , trans()  {
    }
  GridMapInfo_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , map(_alloc)
    , trans(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::grid_map_msgs::GridMap_<ContainerAllocator>  _map_type;
  _map_type map;

   typedef  ::geometry_msgs::Transform_<ContainerAllocator>  _trans_type;
  _trans_type trans;





  typedef boost::shared_ptr< ::autoware_msgs::GridMapInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autoware_msgs::GridMapInfo_<ContainerAllocator> const> ConstPtr;

}; // struct GridMapInfo_

typedef ::autoware_msgs::GridMapInfo_<std::allocator<void> > GridMapInfo;

typedef boost::shared_ptr< ::autoware_msgs::GridMapInfo > GridMapInfoPtr;
typedef boost::shared_ptr< ::autoware_msgs::GridMapInfo const> GridMapInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autoware_msgs::GridMapInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autoware_msgs::GridMapInfo_<ContainerAllocator1> & lhs, const ::autoware_msgs::GridMapInfo_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.map == rhs.map &&
    lhs.trans == rhs.trans;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autoware_msgs::GridMapInfo_<ContainerAllocator1> & lhs, const ::autoware_msgs::GridMapInfo_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autoware_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::GridMapInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::GridMapInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::GridMapInfo_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ffedeb0db1855084acbee985977e827c";
  }

  static const char* value(const ::autoware_msgs::GridMapInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xffedeb0db1855084ULL;
  static const uint64_t static_value2 = 0xacbee985977e827cULL;
};

template<class ContainerAllocator>
struct DataType< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autoware_msgs/GridMapInfo";
  }

  static const char* value(const ::autoware_msgs::GridMapInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"grid_map_msgs/GridMap map\n"
"geometry_msgs/Transform trans\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: grid_map_msgs/GridMap\n"
"# Grid map header\n"
"GridMapInfo info\n"
"\n"
"# Grid map layer names.\n"
"string[] layers\n"
"\n"
"# Grid map basic layer names (optional). The basic layers\n"
"# determine which layers from `layers` need to be valid\n"
"# in order for a cell of the grid map to be valid.\n"
"string[] basic_layers\n"
"\n"
"# Grid map data.\n"
"std_msgs/Float32MultiArray[] data\n"
"\n"
"# Row start index (default 0).\n"
"uint16 outer_start_index\n"
"\n"
"# Column start index (default 0).\n"
"uint16 inner_start_index\n"
"\n"
"================================================================================\n"
"MSG: grid_map_msgs/GridMapInfo\n"
"# Header (time and frame)\n"
"Header header\n"
"\n"
"# Resolution of the grid [m/cell].\n"
"float64 resolution\n"
"\n"
"# Length in x-direction [m].\n"
"float64 length_x\n"
"\n"
"# Length in y-direction [m].\n"
"float64 length_y\n"
"\n"
"# Pose of the grid map center in the frame defined in `header` [m].\n"
"geometry_msgs/Pose pose\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Float32MultiArray\n"
"# Please look at the MultiArrayLayout message definition for\n"
"# documentation on all multiarrays.\n"
"\n"
"MultiArrayLayout  layout        # specification of data layout\n"
"float32[]         data          # array of data\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayLayout\n"
"# The multiarray declares a generic multi-dimensional array of a\n"
"# particular data type.  Dimensions are ordered from outer most\n"
"# to inner most.\n"
"\n"
"MultiArrayDimension[] dim # Array of dimension properties\n"
"uint32 data_offset        # padding elements at front of data\n"
"\n"
"# Accessors should ALWAYS be written in terms of dimension stride\n"
"# and specified outer-most dimension first.\n"
"# \n"
"# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]\n"
"#\n"
"# A standard, 3-channel 640x480 image with interleaved color channels\n"
"# would be specified as:\n"
"#\n"
"# dim[0].label  = \"height\"\n"
"# dim[0].size   = 480\n"
"# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)\n"
"# dim[1].label  = \"width\"\n"
"# dim[1].size   = 640\n"
"# dim[1].stride = 3*640 = 1920\n"
"# dim[2].label  = \"channel\"\n"
"# dim[2].size   = 3\n"
"# dim[2].stride = 3\n"
"#\n"
"# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayDimension\n"
"string label   # label of given dimension\n"
"uint32 size    # size of given dimension (in type units)\n"
"uint32 stride  # stride of given dimension\n"
"================================================================================\n"
"MSG: geometry_msgs/Transform\n"
"# This represents the transform between two coordinate frames in free space.\n"
"\n"
"Vector3 translation\n"
"Quaternion rotation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::autoware_msgs::GridMapInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.map);
      stream.next(m.trans);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GridMapInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autoware_msgs::GridMapInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autoware_msgs::GridMapInfo_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "map: ";
    s << std::endl;
    Printer< ::grid_map_msgs::GridMap_<ContainerAllocator> >::stream(s, indent + "  ", v.map);
    s << indent << "trans: ";
    s << std::endl;
    Printer< ::geometry_msgs::Transform_<ContainerAllocator> >::stream(s, indent + "  ", v.trans);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOWARE_MSGS_MESSAGE_GRIDMAPINFO_H
