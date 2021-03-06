// Auto-generated. Do not edit!

// (in-package autoware_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class VehicleLocation {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.lane_array_id = null;
      this.waypoint_index = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('lane_array_id')) {
        this.lane_array_id = initObj.lane_array_id
      }
      else {
        this.lane_array_id = 0;
      }
      if (initObj.hasOwnProperty('waypoint_index')) {
        this.waypoint_index = initObj.waypoint_index
      }
      else {
        this.waypoint_index = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VehicleLocation
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [lane_array_id]
    bufferOffset = _serializer.int32(obj.lane_array_id, buffer, bufferOffset);
    // Serialize message field [waypoint_index]
    bufferOffset = _serializer.int32(obj.waypoint_index, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VehicleLocation
    let len;
    let data = new VehicleLocation(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [lane_array_id]
    data.lane_array_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [waypoint_index]
    data.waypoint_index = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'autoware_msgs/VehicleLocation';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cba3770fc8eb8557ac8c63f4c0d3155b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int32 lane_array_id
    int32 waypoint_index
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new VehicleLocation(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.lane_array_id !== undefined) {
      resolved.lane_array_id = msg.lane_array_id;
    }
    else {
      resolved.lane_array_id = 0
    }

    if (msg.waypoint_index !== undefined) {
      resolved.waypoint_index = msg.waypoint_index;
    }
    else {
      resolved.waypoint_index = 0
    }

    return resolved;
    }
};

module.exports = VehicleLocation;
