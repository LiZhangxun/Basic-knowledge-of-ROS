; Auto-generated. Do not edit!


(cl:in-package delta_lidar-msg)


;//! \htmlinclude Laser_distance.msg.html

(cl:defclass <Laser_distance> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass Laser_distance (<Laser_distance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Laser_distance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Laser_distance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delta_lidar-msg:<Laser_distance> is deprecated: use delta_lidar-msg:Laser_distance instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <Laser_distance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delta_lidar-msg:distance-val is deprecated.  Use delta_lidar-msg:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Laser_distance>) ostream)
  "Serializes a message object of type '<Laser_distance>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Laser_distance>) istream)
  "Deserializes a message object of type '<Laser_distance>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Laser_distance>)))
  "Returns string type for a message object of type '<Laser_distance>"
  "delta_lidar/Laser_distance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Laser_distance)))
  "Returns string type for a message object of type 'Laser_distance"
  "delta_lidar/Laser_distance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Laser_distance>)))
  "Returns md5sum for a message object of type '<Laser_distance>"
  "6e77fb10f0c8b4833ec273aa9ac74459")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Laser_distance)))
  "Returns md5sum for a message object of type 'Laser_distance"
  "6e77fb10f0c8b4833ec273aa9ac74459")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Laser_distance>)))
  "Returns full string definition for message of type '<Laser_distance>"
  (cl:format cl:nil "float32 distance~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Laser_distance)))
  "Returns full string definition for message of type 'Laser_distance"
  (cl:format cl:nil "float32 distance~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Laser_distance>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Laser_distance>))
  "Converts a ROS message object to a list"
  (cl:list 'Laser_distance
    (cl:cons ':distance (distance msg))
))
