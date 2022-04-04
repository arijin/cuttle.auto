// Auto-generated. Do not edit!

// (in-package autoware_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let grid_map_msgs = _finder('grid_map_msgs');
let std_msgs = _finder('std_msgs');
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class GridMapInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.map = null;
      this.trans = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('map')) {
        this.map = initObj.map
      }
      else {
        this.map = new grid_map_msgs.msg.GridMap();
      }
      if (initObj.hasOwnProperty('trans')) {
        this.trans = initObj.trans
      }
      else {
        this.trans = new geometry_msgs.msg.Transform();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GridMapInfo
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [map]
    bufferOffset = grid_map_msgs.msg.GridMap.serialize(obj.map, buffer, bufferOffset);
    // Serialize message field [trans]
    bufferOffset = geometry_msgs.msg.Transform.serialize(obj.trans, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GridMapInfo
    let len;
    let data = new GridMapInfo(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [map]
    data.map = grid_map_msgs.msg.GridMap.deserialize(buffer, bufferOffset);
    // Deserialize message field [trans]
    data.trans = geometry_msgs.msg.Transform.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += grid_map_msgs.msg.GridMap.getMessageSize(object.map);
    return length + 56;
  }

  static datatype() {
    // Returns string type for a message object
    return 'autoware_msgs/GridMapInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ffedeb0db1855084acbee985977e827c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
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
    # dim[0].label  = "height"
    # dim[0].size   = 480
    # dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)
    # dim[1].label  = "width"
    # dim[1].size   = 640
    # dim[1].stride = 3*640 = 1920
    # dim[2].label  = "channel"
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GridMapInfo(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.map !== undefined) {
      resolved.map = grid_map_msgs.msg.GridMap.Resolve(msg.map)
    }
    else {
      resolved.map = new grid_map_msgs.msg.GridMap()
    }

    if (msg.trans !== undefined) {
      resolved.trans = geometry_msgs.msg.Transform.Resolve(msg.trans)
    }
    else {
      resolved.trans = new geometry_msgs.msg.Transform()
    }

    return resolved;
    }
};

module.exports = GridMapInfo;
