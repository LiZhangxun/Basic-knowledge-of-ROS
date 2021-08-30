// Auto-generated. Do not edit!

// (in-package turtle_actionlib.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ShapeResult {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.interior_angle = null;
      this.apothem = null;
    }
    else {
      if (initObj.hasOwnProperty('interior_angle')) {
        this.interior_angle = initObj.interior_angle
      }
      else {
        this.interior_angle = 0.0;
      }
      if (initObj.hasOwnProperty('apothem')) {
        this.apothem = initObj.apothem
      }
      else {
        this.apothem = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ShapeResult
    // Serialize message field [interior_angle]
    bufferOffset = _serializer.float32(obj.interior_angle, buffer, bufferOffset);
    // Serialize message field [apothem]
    bufferOffset = _serializer.float32(obj.apothem, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ShapeResult
    let len;
    let data = new ShapeResult(null);
    // Deserialize message field [interior_angle]
    data.interior_angle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [apothem]
    data.apothem = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtle_actionlib/ShapeResult';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b06c6e2225f820dbc644270387cd1a7c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    #result definition
    float32 interior_angle
    float32 apothem
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ShapeResult(null);
    if (msg.interior_angle !== undefined) {
      resolved.interior_angle = msg.interior_angle;
    }
    else {
      resolved.interior_angle = 0.0
    }

    if (msg.apothem !== undefined) {
      resolved.apothem = msg.apothem;
    }
    else {
      resolved.apothem = 0.0
    }

    return resolved;
    }
};

module.exports = ShapeResult;