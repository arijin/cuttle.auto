// Auto-generated. Do not edit!

// (in-package water_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');
let gazebo_msgs = _finder('gazebo_msgs');

//-----------------------------------------------------------

class ShipState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.modelstate = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('modelstate')) {
        this.modelstate = initObj.modelstate
      }
      else {
        this.modelstate = new gazebo_msgs.msg.ModelState();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ShipState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [modelstate]
    bufferOffset = gazebo_msgs.msg.ModelState.serialize(obj.modelstate, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ShipState
    let len;
    let data = new ShipState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [modelstate]
    data.modelstate = gazebo_msgs.msg.ModelState.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += gazebo_msgs.msg.ModelState.getMessageSize(object.modelstate);
    return length;
  }

  static datatype() {
    // Returns string type for a message object
    return 'water_msgs/ShipState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '33096c68969bd500c544dae60549ddbb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    gazebo_msgs/ModelState modelstate
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
    MSG: gazebo_msgs/ModelState
    # Set Gazebo Model pose and twist
    string model_name           # model to set state (pose and twist)
    geometry_msgs/Pose pose     # desired pose in reference frame
    geometry_msgs/Twist twist   # desired twist in reference frame
    string reference_frame      # set pose/twist relative to the frame of this entity (Body/Model)
                                # leave empty or "world" or "map" defaults to world-frame
    
    
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
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
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
    const resolved = new ShipState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.modelstate !== undefined) {
      resolved.modelstate = gazebo_msgs.msg.ModelState.Resolve(msg.modelstate)
    }
    else {
      resolved.modelstate = new gazebo_msgs.msg.ModelState()
    }

    return resolved;
    }
};

module.exports = ShipState;
