// Auto-generated. Do not edit!

// (in-package vector_map_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class WaterArea {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
      this.kid = null;
      this.slid = null;
      this.elid = null;
      this.connectid = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('kid')) {
        this.kid = initObj.kid
      }
      else {
        this.kid = 0;
      }
      if (initObj.hasOwnProperty('slid')) {
        this.slid = initObj.slid
      }
      else {
        this.slid = 0;
      }
      if (initObj.hasOwnProperty('elid')) {
        this.elid = initObj.elid
      }
      else {
        this.elid = 0;
      }
      if (initObj.hasOwnProperty('connectid')) {
        this.connectid = initObj.connectid
      }
      else {
        this.connectid = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WaterArea
    // Serialize message field [id]
    bufferOffset = _serializer.int32(obj.id, buffer, bufferOffset);
    // Serialize message field [kid]
    bufferOffset = _serializer.int32(obj.kid, buffer, bufferOffset);
    // Serialize message field [slid]
    bufferOffset = _serializer.int32(obj.slid, buffer, bufferOffset);
    // Serialize message field [elid]
    bufferOffset = _serializer.int32(obj.elid, buffer, bufferOffset);
    // Serialize message field [connectid]
    bufferOffset = _serializer.int32(obj.connectid, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WaterArea
    let len;
    let data = new WaterArea(null);
    // Deserialize message field [id]
    data.id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [kid]
    data.kid = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [slid]
    data.slid = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [elid]
    data.elid = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [connectid]
    data.connectid = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'vector_map_msgs/WaterArea';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c3d76e4604dd439eb4bc0783df641df8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Ver 1.00
    int32 id
    int32 kid
    int32 slid
    int32 elid
    int32 connectid
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WaterArea(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.kid !== undefined) {
      resolved.kid = msg.kid;
    }
    else {
      resolved.kid = 0
    }

    if (msg.slid !== undefined) {
      resolved.slid = msg.slid;
    }
    else {
      resolved.slid = 0
    }

    if (msg.elid !== undefined) {
      resolved.elid = msg.elid;
    }
    else {
      resolved.elid = 0
    }

    if (msg.connectid !== undefined) {
      resolved.connectid = msg.connectid;
    }
    else {
      resolved.connectid = 0
    }

    return resolved;
    }
};

module.exports = WaterArea;
