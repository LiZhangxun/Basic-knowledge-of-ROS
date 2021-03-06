// Auto-generated. Do not edit!

// (in-package action_homework.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class robot_moveResult {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.finalpose_x = null;
      this.finalpose_y = null;
    }
    else {
      if (initObj.hasOwnProperty('finalpose_x')) {
        this.finalpose_x = initObj.finalpose_x
      }
      else {
        this.finalpose_x = 0.0;
      }
      if (initObj.hasOwnProperty('finalpose_y')) {
        this.finalpose_y = initObj.finalpose_y
      }
      else {
        this.finalpose_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robot_moveResult
    // Serialize message field [finalpose_x]
    bufferOffset = _serializer.float32(obj.finalpose_x, buffer, bufferOffset);
    // Serialize message field [finalpose_y]
    bufferOffset = _serializer.float32(obj.finalpose_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robot_moveResult
    let len;
    let data = new robot_moveResult(null);
    // Deserialize message field [finalpose_x]
    data.finalpose_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [finalpose_y]
    data.finalpose_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'action_homework/robot_moveResult';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '70fbee4bb3e7c94c5c08525cb743c16d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    #??????????????????result
    float32 finalpose_x
    float32 finalpose_y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robot_moveResult(null);
    if (msg.finalpose_x !== undefined) {
      resolved.finalpose_x = msg.finalpose_x;
    }
    else {
      resolved.finalpose_x = 0.0
    }

    if (msg.finalpose_y !== undefined) {
      resolved.finalpose_y = msg.finalpose_y;
    }
    else {
      resolved.finalpose_y = 0.0
    }

    return resolved;
    }
};

module.exports = robot_moveResult;
