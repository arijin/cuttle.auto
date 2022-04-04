// Generated by gencpp from file autoware_msgs/DetectedObject.msg
// DO NOT EDIT!


#ifndef AUTOWARE_MSGS_MESSAGE_DETECTEDOBJECT_H
#define AUTOWARE_MSGS_MESSAGE_DETECTEDOBJECT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/ColorRGBA.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/PolygonStamped.h>
#include <autoware_msgs/LaneArray.h>
#include <sensor_msgs/Image.h>

namespace autoware_msgs
{
template <class ContainerAllocator>
struct DetectedObject_
{
  typedef DetectedObject_<ContainerAllocator> Type;

  DetectedObject_()
    : header()
    , id(0)
    , label()
    , score(0.0)
    , color()
    , valid(false)
    , space_frame()
    , pose()
    , dimensions()
    , variance()
    , velocity()
    , acceleration()
    , pointcloud()
    , convex_hull()
    , candidate_trajectories()
    , pose_reliable(false)
    , velocity_reliable(false)
    , acceleration_reliable(false)
    , image_frame()
    , x(0)
    , y(0)
    , width(0)
    , height(0)
    , angle(0.0)
    , roi_image()
    , indicator_state(0)
    , behavior_state(0)
    , user_defined_info()  {
    }
  DetectedObject_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(0)
    , label(_alloc)
    , score(0.0)
    , color(_alloc)
    , valid(false)
    , space_frame(_alloc)
    , pose(_alloc)
    , dimensions(_alloc)
    , variance(_alloc)
    , velocity(_alloc)
    , acceleration(_alloc)
    , pointcloud(_alloc)
    , convex_hull(_alloc)
    , candidate_trajectories(_alloc)
    , pose_reliable(false)
    , velocity_reliable(false)
    , acceleration_reliable(false)
    , image_frame(_alloc)
    , x(0)
    , y(0)
    , width(0)
    , height(0)
    , angle(0.0)
    , roi_image(_alloc)
    , indicator_state(0)
    , behavior_state(0)
    , user_defined_info(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _id_type;
  _id_type id;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _label_type;
  _label_type label;

   typedef float _score_type;
  _score_type score;

   typedef  ::std_msgs::ColorRGBA_<ContainerAllocator>  _color_type;
  _color_type color;

   typedef uint8_t _valid_type;
  _valid_type valid;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _space_frame_type;
  _space_frame_type space_frame;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _dimensions_type;
  _dimensions_type dimensions;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _variance_type;
  _variance_type variance;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;

   typedef  ::sensor_msgs::PointCloud2_<ContainerAllocator>  _pointcloud_type;
  _pointcloud_type pointcloud;

   typedef  ::geometry_msgs::PolygonStamped_<ContainerAllocator>  _convex_hull_type;
  _convex_hull_type convex_hull;

   typedef  ::autoware_msgs::LaneArray_<ContainerAllocator>  _candidate_trajectories_type;
  _candidate_trajectories_type candidate_trajectories;

   typedef uint8_t _pose_reliable_type;
  _pose_reliable_type pose_reliable;

   typedef uint8_t _velocity_reliable_type;
  _velocity_reliable_type velocity_reliable;

   typedef uint8_t _acceleration_reliable_type;
  _acceleration_reliable_type acceleration_reliable;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _image_frame_type;
  _image_frame_type image_frame;

   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;

   typedef int32_t _width_type;
  _width_type width;

   typedef int32_t _height_type;
  _height_type height;

   typedef float _angle_type;
  _angle_type angle;

   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _roi_image_type;
  _roi_image_type roi_image;

   typedef uint8_t _indicator_state_type;
  _indicator_state_type indicator_state;

   typedef uint8_t _behavior_state_type;
  _behavior_state_type behavior_state;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _user_defined_info_type;
  _user_defined_info_type user_defined_info;





  typedef boost::shared_ptr< ::autoware_msgs::DetectedObject_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autoware_msgs::DetectedObject_<ContainerAllocator> const> ConstPtr;

}; // struct DetectedObject_

typedef ::autoware_msgs::DetectedObject_<std::allocator<void> > DetectedObject;

typedef boost::shared_ptr< ::autoware_msgs::DetectedObject > DetectedObjectPtr;
typedef boost::shared_ptr< ::autoware_msgs::DetectedObject const> DetectedObjectConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autoware_msgs::DetectedObject_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autoware_msgs::DetectedObject_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autoware_msgs::DetectedObject_<ContainerAllocator1> & lhs, const ::autoware_msgs::DetectedObject_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.id == rhs.id &&
    lhs.label == rhs.label &&
    lhs.score == rhs.score &&
    lhs.color == rhs.color &&
    lhs.valid == rhs.valid &&
    lhs.space_frame == rhs.space_frame &&
    lhs.pose == rhs.pose &&
    lhs.dimensions == rhs.dimensions &&
    lhs.variance == rhs.variance &&
    lhs.velocity == rhs.velocity &&
    lhs.acceleration == rhs.acceleration &&
    lhs.pointcloud == rhs.pointcloud &&
    lhs.convex_hull == rhs.convex_hull &&
    lhs.candidate_trajectories == rhs.candidate_trajectories &&
    lhs.pose_reliable == rhs.pose_reliable &&
    lhs.velocity_reliable == rhs.velocity_reliable &&
    lhs.acceleration_reliable == rhs.acceleration_reliable &&
    lhs.image_frame == rhs.image_frame &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.width == rhs.width &&
    lhs.height == rhs.height &&
    lhs.angle == rhs.angle &&
    lhs.roi_image == rhs.roi_image &&
    lhs.indicator_state == rhs.indicator_state &&
    lhs.behavior_state == rhs.behavior_state &&
    lhs.user_defined_info == rhs.user_defined_info;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autoware_msgs::DetectedObject_<ContainerAllocator1> & lhs, const ::autoware_msgs::DetectedObject_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autoware_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::DetectedObject_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::DetectedObject_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::DetectedObject_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
{
  static const char* value()
  {
    return "536ff0bbdaac3ef3a57a314f80b8ed04";
  }

  static const char* value(const ::autoware_msgs::DetectedObject_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x536ff0bbdaac3ef3ULL;
  static const uint64_t static_value2 = 0xa57a314f80b8ed04ULL;
};

template<class ContainerAllocator>
struct DataType< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autoware_msgs/DetectedObject";
  }

  static const char* value(const ::autoware_msgs::DetectedObject_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header                 header\n"
"\n"
"uint32                          id\n"
"string                          label\n"
"float32                         score   #Score as defined by the detection, Optional\n"
"std_msgs/ColorRGBA              color   # Define this object specific color\n"
"bool                            valid   # Defines if this object is valid, or invalid as defined by the filtering\n"
"\n"
"################ 3D BB\n"
"string                          space_frame #3D Space coordinate frame of the object, required if pose and dimensions are defines\n"
"geometry_msgs/Pose              pose\n"
"geometry_msgs/Vector3           dimensions\n"
"geometry_msgs/Vector3           variance\n"
"geometry_msgs/Twist             velocity\n"
"geometry_msgs/Twist             acceleration\n"
"\n"
"sensor_msgs/PointCloud2         pointcloud\n"
"\n"
"geometry_msgs/PolygonStamped    convex_hull\n"
"autoware_msgs/LaneArray         candidate_trajectories\n"
"\n"
"bool                            pose_reliable\n"
"bool                            velocity_reliable\n"
"bool                            acceleration_reliable\n"
"\n"
"############### 2D Rect\n"
"string                          image_frame # Image coordinate Frame,        Required if x,y,w,h defined\n"
"int32                           x           # X coord in image space(pixel) of the initial point of the Rect\n"
"int32                           y           # Y coord in image space(pixel) of the initial point of the Rect\n"
"int32                           width       # Width of the Rect in pixels\n"
"int32                           height      # Height of the Rect in pixels\n"
"float32                         angle       # Angle [0 to 2*PI), allow rotated rects\n"
"\n"
"sensor_msgs/Image               roi_image\n"
"\n"
"############### Indicator information\n"
"uint8                          indicator_state # INDICATOR_LEFT = 0, INDICATOR_RIGHT = 1, INDICATOR_BOTH = 2, INDICATOR_NONE = 3\n"
"\n"
"############### Behavior State of the Detected Object\n"
"uint8                           behavior_state # FORWARD_STATE = 0, STOPPING_STATE = 1, BRANCH_LEFT_STATE = 2, BRANCH_RIGHT_STATE = 3, YIELDING_STATE = 4, ACCELERATING_STATE = 5, SLOWDOWN_STATE = 6\n"
"\n"
"#\n"
"string[]                        user_defined_info\n"
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
"MSG: std_msgs/ColorRGBA\n"
"float32 r\n"
"float32 g\n"
"float32 b\n"
"float32 a\n"
"\n"
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
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/PointCloud2\n"
"# This message holds a collection of N-dimensional points, which may\n"
"# contain additional information such as normals, intensity, etc. The\n"
"# point data is stored as a binary blob, its layout described by the\n"
"# contents of the \"fields\" array.\n"
"\n"
"# The point cloud data may be organized 2d (image-like) or 1d\n"
"# (unordered). Point clouds organized as 2d images may be produced by\n"
"# camera depth sensors such as stereo or time-of-flight.\n"
"\n"
"# Time of sensor data acquisition, and the coordinate frame ID (for 3d\n"
"# points).\n"
"Header header\n"
"\n"
"# 2D structure of the point cloud. If the cloud is unordered, height is\n"
"# 1 and width is the length of the point cloud.\n"
"uint32 height\n"
"uint32 width\n"
"\n"
"# Describes the channels and their layout in the binary data blob.\n"
"PointField[] fields\n"
"\n"
"bool    is_bigendian # Is this data bigendian?\n"
"uint32  point_step   # Length of a point in bytes\n"
"uint32  row_step     # Length of a row in bytes\n"
"uint8[] data         # Actual point data, size is (row_step*height)\n"
"\n"
"bool is_dense        # True if there are no invalid points\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/PointField\n"
"# This message holds the description of one point entry in the\n"
"# PointCloud2 message format.\n"
"uint8 INT8    = 1\n"
"uint8 UINT8   = 2\n"
"uint8 INT16   = 3\n"
"uint8 UINT16  = 4\n"
"uint8 INT32   = 5\n"
"uint8 UINT32  = 6\n"
"uint8 FLOAT32 = 7\n"
"uint8 FLOAT64 = 8\n"
"\n"
"string name      # Name of field\n"
"uint32 offset    # Offset from start of point struct\n"
"uint8  datatype  # Datatype enumeration, see above\n"
"uint32 count     # How many elements in the field\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PolygonStamped\n"
"# This represents a Polygon with reference coordinate frame and timestamp\n"
"Header header\n"
"Polygon polygon\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Polygon\n"
"#A specification of a polygon where the first and last points are assumed to be connected\n"
"Point32[] points\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point32\n"
"# This contains the position of a point in free space(with 32 bits of precision).\n"
"# It is recommeded to use Point wherever possible instead of Point32.  \n"
"# \n"
"# This recommendation is to promote interoperability.  \n"
"#\n"
"# This message is designed to take up less space when sending\n"
"# lots of points at once, as in the case of a PointCloud.  \n"
"\n"
"float32 x\n"
"float32 y\n"
"float32 z\n"
"================================================================================\n"
"MSG: autoware_msgs/LaneArray\n"
"int32 id\n"
"Lane[] lanes\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/Lane\n"
"Header header\n"
"int32 increment\n"
"int32 lane_id\n"
"Waypoint[] waypoints\n"
"\n"
"uint32 lane_index\n"
"float32 cost\n"
"float32 closest_object_distance\n"
"float32 closest_object_velocity\n"
"bool is_blocked\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/Waypoint\n"
"# global id\n"
"int32 gid \n"
"# local id\n"
"int32 lid\n"
"geometry_msgs/PoseStamped pose\n"
"geometry_msgs/TwistStamped twist\n"
"DTLane dtlane\n"
"int32 change_flag\n"
"WaypointState wpstate\n"
"\n"
"uint32 lane_id\n"
"uint32 left_lane_id\n"
"uint32 right_lane_id\n"
"uint32 stop_line_id\n"
"float32 cost\n"
"float32 time_cost\n"
"\n"
"# Lane Direction\n"
"# FORWARD				= 0\n"
"# FORWARD_LEFT	 		= 1\n"
"# FORWARD_RIGHT			= 2\n"
"# BACKWARD				= 3 \n"
"# BACKWARD_LEFT			= 4\n"
"# BACKWARD_RIGHT		= 5\n"
"# STANDSTILL	 		= 6\n"
"uint32 direction\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/TwistStamped\n"
"# A twist with reference coordinate frame and timestamp\n"
"Header header\n"
"Twist twist\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/DTLane\n"
"float64 dist\n"
"float64 dir\n"
"float64 apara\n"
"float64 r\n"
"float64 slope\n"
"float64 cant\n"
"float64 lw\n"
"float64 rw\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/WaypointState\n"
"int32 aid\n"
"uint8 NULLSTATE=0\n"
"\n"
"# lanechange\n"
"uint8 lanechange_state\n"
"\n"
"# bilinker\n"
"uint8 steering_state\n"
"uint8 STR_LEFT=1\n"
"uint8 STR_RIGHT=2\n"
"uint8 STR_STRAIGHT=3\n"
"uint8 STR_BACK=4\n"
"\n"
"uint8 accel_state\n"
"\n"
"uint8 stop_state\n"
"# 1 is stopline, 2 is stop which can only be released manually.\n"
"uint8 TYPE_STOPLINE=1\n"
"uint8 TYPE_STOP=2\n"
"\n"
"uint8 event_state\n"
"uint8 TYPE_EVENT_NULL = 0\n"
"uint8 TYPE_EVENT_GOAL = 1\n"
"uint8 TYPE_EVENT_MIDDLE_GOAL = 2\n"
"uint8 TYPE_EVENT_POSITION_STOP = 3\n"
"uint8 TYPE_EVENT_BUS_STOP = 4\n"
"uint8 TYPE_EVENT_PARKING = 5\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/Image\n"
"# This message contains an uncompressed image\n"
"# (0, 0) is at top-left corner of image\n"
"#\n"
"\n"
"Header header        # Header timestamp should be acquisition time of image\n"
"                     # Header frame_id should be optical frame of camera\n"
"                     # origin of frame should be optical center of camera\n"
"                     # +x should point to the right in the image\n"
"                     # +y should point down in the image\n"
"                     # +z should point into to plane of the image\n"
"                     # If the frame_id here and the frame_id of the CameraInfo\n"
"                     # message associated with the image conflict\n"
"                     # the behavior is undefined\n"
"\n"
"uint32 height         # image height, that is, number of rows\n"
"uint32 width          # image width, that is, number of columns\n"
"\n"
"# The legal values for encoding are in file src/image_encodings.cpp\n"
"# If you want to standardize a new string format, join\n"
"# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n"
"\n"
"string encoding       # Encoding of pixels -- channel meaning, ordering, size\n"
"                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n"
"\n"
"uint8 is_bigendian    # is this data bigendian?\n"
"uint32 step           # Full row length in bytes\n"
"uint8[] data          # actual matrix data, size is (step * rows)\n"
;
  }

  static const char* value(const ::autoware_msgs::DetectedObject_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.label);
      stream.next(m.score);
      stream.next(m.color);
      stream.next(m.valid);
      stream.next(m.space_frame);
      stream.next(m.pose);
      stream.next(m.dimensions);
      stream.next(m.variance);
      stream.next(m.velocity);
      stream.next(m.acceleration);
      stream.next(m.pointcloud);
      stream.next(m.convex_hull);
      stream.next(m.candidate_trajectories);
      stream.next(m.pose_reliable);
      stream.next(m.velocity_reliable);
      stream.next(m.acceleration_reliable);
      stream.next(m.image_frame);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.width);
      stream.next(m.height);
      stream.next(m.angle);
      stream.next(m.roi_image);
      stream.next(m.indicator_state);
      stream.next(m.behavior_state);
      stream.next(m.user_defined_info);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DetectedObject_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autoware_msgs::DetectedObject_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autoware_msgs::DetectedObject_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
    s << indent << "label: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.label);
    s << indent << "score: ";
    Printer<float>::stream(s, indent + "  ", v.score);
    s << indent << "color: ";
    s << std::endl;
    Printer< ::std_msgs::ColorRGBA_<ContainerAllocator> >::stream(s, indent + "  ", v.color);
    s << indent << "valid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.valid);
    s << indent << "space_frame: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.space_frame);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "dimensions: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.dimensions);
    s << indent << "variance: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.variance);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
    s << indent << "pointcloud: ";
    s << std::endl;
    Printer< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::stream(s, indent + "  ", v.pointcloud);
    s << indent << "convex_hull: ";
    s << std::endl;
    Printer< ::geometry_msgs::PolygonStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.convex_hull);
    s << indent << "candidate_trajectories: ";
    s << std::endl;
    Printer< ::autoware_msgs::LaneArray_<ContainerAllocator> >::stream(s, indent + "  ", v.candidate_trajectories);
    s << indent << "pose_reliable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.pose_reliable);
    s << indent << "velocity_reliable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.velocity_reliable);
    s << indent << "acceleration_reliable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.acceleration_reliable);
    s << indent << "image_frame: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.image_frame);
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
    s << indent << "angle: ";
    Printer<float>::stream(s, indent + "  ", v.angle);
    s << indent << "roi_image: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.roi_image);
    s << indent << "indicator_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.indicator_state);
    s << indent << "behavior_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.behavior_state);
    s << indent << "user_defined_info[]" << std::endl;
    for (size_t i = 0; i < v.user_defined_info.size(); ++i)
    {
      s << indent << "  user_defined_info[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.user_defined_info[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOWARE_MSGS_MESSAGE_DETECTEDOBJECT_H
