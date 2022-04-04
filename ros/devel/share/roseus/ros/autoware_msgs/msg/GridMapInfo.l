;; Auto-generated. Do not edit!


(when (boundp 'autoware_msgs::GridMapInfo)
  (if (not (find-package "AUTOWARE_MSGS"))
    (make-package "AUTOWARE_MSGS"))
  (shadow 'GridMapInfo (find-package "AUTOWARE_MSGS")))
(unless (find-package "AUTOWARE_MSGS::GRIDMAPINFO")
  (make-package "AUTOWARE_MSGS::GRIDMAPINFO"))

(in-package "ROS")
;;//! \htmlinclude GridMapInfo.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "GRID_MAP_MSGS"))
  (ros::roseus-add-msgs "grid_map_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass autoware_msgs::GridMapInfo
  :super ros::object
  :slots (_header _map _trans ))

(defmethod autoware_msgs::GridMapInfo
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:map __map) (instance grid_map_msgs::GridMap :init))
    ((:trans __trans) (instance geometry_msgs::Transform :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _map __map)
   (setq _trans __trans)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:map
   (&rest __map)
   (if (keywordp (car __map))
       (send* _map __map)
     (progn
       (if __map (setq _map (car __map)))
       _map)))
  (:trans
   (&rest __trans)
   (if (keywordp (car __trans))
       (send* _trans __trans)
     (progn
       (if __trans (setq _trans (car __trans)))
       _trans)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; grid_map_msgs/GridMap _map
    (send _map :serialization-length)
    ;; geometry_msgs/Transform _trans
    (send _trans :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; grid_map_msgs/GridMap _map
       (send _map :serialize s)
     ;; geometry_msgs/Transform _trans
       (send _trans :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; grid_map_msgs/GridMap _map
     (send _map :deserialize buf ptr-) (incf ptr- (send _map :serialization-length))
   ;; geometry_msgs/Transform _trans
     (send _trans :deserialize buf ptr-) (incf ptr- (send _trans :serialization-length))
   ;;
   self)
  )

(setf (get autoware_msgs::GridMapInfo :md5sum-) "ffedeb0db1855084acbee985977e827c")
(setf (get autoware_msgs::GridMapInfo :datatype-) "autoware_msgs/GridMapInfo")
(setf (get autoware_msgs::GridMapInfo :definition-)
      "std_msgs/Header header
grid_map_msgs/GridMap map
geometry_msgs/Transform trans

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: grid_map_msgs/GridMap
# Grid map header
GridMapInfo info

# Grid map layer names.
string[] layers

# Grid map basic layer names (optional). The basic layers
# determine which layers from `layers` need to be valid
# in order for a cell of the grid map to be valid.
string[] basic_layers

# Grid map data.
std_msgs/Float32MultiArray[] data

# Row start index (default 0).
uint16 outer_start_index

# Column start index (default 0).
uint16 inner_start_index

================================================================================
MSG: grid_map_msgs/GridMapInfo
# Header (time and frame)
Header header

# Resolution of the grid [m/cell].
float64 resolution

# Length in x-direction [m].
float64 length_x

# Length in y-direction [m].
float64 length_y

# Pose of the grid map center in the frame defined in `header` [m].
geometry_msgs/Pose pose
================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: std_msgs/Float32MultiArray
# Please look at the MultiArrayLayout message definition for
# documentation on all multiarrays.

MultiArrayLayout  layout        # specification of data layout
float32[]         data          # array of data


================================================================================
MSG: std_msgs/MultiArrayLayout
# The multiarray declares a generic multi-dimensional array of a
# particular data type.  Dimensions are ordered from outer most
# to inner most.

MultiArrayDimension[] dim # Array of dimension properties
uint32 data_offset        # padding elements at front of data

# Accessors should ALWAYS be written in terms of dimension stride
# and specified outer-most dimension first.
# 
# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]
#
# A standard, 3-channel 640x480 image with interleaved color channels
# would be specified as:
#
# dim[0].label  = \"height\"
# dim[0].size   = 480
# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)
# dim[1].label  = \"width\"
# dim[1].size   = 640
# dim[1].stride = 3*640 = 1920
# dim[2].label  = \"channel\"
# dim[2].size   = 3
# dim[2].stride = 3
#
# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.

================================================================================
MSG: std_msgs/MultiArrayDimension
string label   # label of given dimension
uint32 size    # size of given dimension (in type units)
uint32 stride  # stride of given dimension
================================================================================
MSG: geometry_msgs/Transform
# This represents the transform between two coordinate frames in free space.

Vector3 translation
Quaternion rotation

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :autoware_msgs/GridMapInfo "ffedeb0db1855084acbee985977e827c")


