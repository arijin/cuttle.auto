; Auto-generated. Do not edit!


(cl:in-package autoware_msgs-msg)


;//! \htmlinclude GridMapInfo.msg.html

(cl:defclass <GridMapInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (map
    :reader map
    :initarg :map
    :type grid_map_msgs-msg:GridMap
    :initform (cl:make-instance 'grid_map_msgs-msg:GridMap))
   (trans
    :reader trans
    :initarg :trans
    :type geometry_msgs-msg:Transform
    :initform (cl:make-instance 'geometry_msgs-msg:Transform)))
)

(cl:defclass GridMapInfo (<GridMapInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GridMapInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GridMapInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name autoware_msgs-msg:<GridMapInfo> is deprecated: use autoware_msgs-msg:GridMapInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <GridMapInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_msgs-msg:header-val is deprecated.  Use autoware_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'map-val :lambda-list '(m))
(cl:defmethod map-val ((m <GridMapInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_msgs-msg:map-val is deprecated.  Use autoware_msgs-msg:map instead.")
  (map m))

(cl:ensure-generic-function 'trans-val :lambda-list '(m))
(cl:defmethod trans-val ((m <GridMapInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_msgs-msg:trans-val is deprecated.  Use autoware_msgs-msg:trans instead.")
  (trans m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GridMapInfo>) ostream)
  "Serializes a message object of type '<GridMapInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'map) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'trans) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GridMapInfo>) istream)
  "Deserializes a message object of type '<GridMapInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'map) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'trans) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GridMapInfo>)))
  "Returns string type for a message object of type '<GridMapInfo>"
  "autoware_msgs/GridMapInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GridMapInfo)))
  "Returns string type for a message object of type 'GridMapInfo"
  "autoware_msgs/GridMapInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GridMapInfo>)))
  "Returns md5sum for a message object of type '<GridMapInfo>"
  "ffedeb0db1855084acbee985977e827c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GridMapInfo)))
  "Returns md5sum for a message object of type 'GridMapInfo"
  "ffedeb0db1855084acbee985977e827c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GridMapInfo>)))
  "Returns full string definition for message of type '<GridMapInfo>"
  (cl:format cl:nil "std_msgs/Header header~%grid_map_msgs/GridMap map~%geometry_msgs/Transform trans~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: grid_map_msgs/GridMap~%# Grid map header~%GridMapInfo info~%~%# Grid map layer names.~%string[] layers~%~%# Grid map basic layer names (optional). The basic layers~%# determine which layers from `layers` need to be valid~%# in order for a cell of the grid map to be valid.~%string[] basic_layers~%~%# Grid map data.~%std_msgs/Float32MultiArray[] data~%~%# Row start index (default 0).~%uint16 outer_start_index~%~%# Column start index (default 0).~%uint16 inner_start_index~%~%================================================================================~%MSG: grid_map_msgs/GridMapInfo~%# Header (time and frame)~%Header header~%~%# Resolution of the grid [m/cell].~%float64 resolution~%~%# Length in x-direction [m].~%float64 length_x~%~%# Length in y-direction [m].~%float64 length_y~%~%# Pose of the grid map center in the frame defined in `header` [m].~%geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32MultiArray~%# Please look at the MultiArrayLayout message definition for~%# documentation on all multiarrays.~%~%MultiArrayLayout  layout        # specification of data layout~%float32[]         data          # array of data~%~%~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%================================================================================~%MSG: geometry_msgs/Transform~%# This represents the transform between two coordinate frames in free space.~%~%Vector3 translation~%Quaternion rotation~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GridMapInfo)))
  "Returns full string definition for message of type 'GridMapInfo"
  (cl:format cl:nil "std_msgs/Header header~%grid_map_msgs/GridMap map~%geometry_msgs/Transform trans~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: grid_map_msgs/GridMap~%# Grid map header~%GridMapInfo info~%~%# Grid map layer names.~%string[] layers~%~%# Grid map basic layer names (optional). The basic layers~%# determine which layers from `layers` need to be valid~%# in order for a cell of the grid map to be valid.~%string[] basic_layers~%~%# Grid map data.~%std_msgs/Float32MultiArray[] data~%~%# Row start index (default 0).~%uint16 outer_start_index~%~%# Column start index (default 0).~%uint16 inner_start_index~%~%================================================================================~%MSG: grid_map_msgs/GridMapInfo~%# Header (time and frame)~%Header header~%~%# Resolution of the grid [m/cell].~%float64 resolution~%~%# Length in x-direction [m].~%float64 length_x~%~%# Length in y-direction [m].~%float64 length_y~%~%# Pose of the grid map center in the frame defined in `header` [m].~%geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32MultiArray~%# Please look at the MultiArrayLayout message definition for~%# documentation on all multiarrays.~%~%MultiArrayLayout  layout        # specification of data layout~%float32[]         data          # array of data~%~%~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%================================================================================~%MSG: geometry_msgs/Transform~%# This represents the transform between two coordinate frames in free space.~%~%Vector3 translation~%Quaternion rotation~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GridMapInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'map))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'trans))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GridMapInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'GridMapInfo
    (cl:cons ':header (header msg))
    (cl:cons ':map (map msg))
    (cl:cons ':trans (trans msg))
))
