; Auto-generated. Do not edit!


(cl:in-package learning_action-msg)


;//! \htmlinclude DoDishesResult.msg.html

(cl:defclass <DoDishesResult> (roslisp-msg-protocol:ros-message)
  ((total_dishes_cleaned
    :reader total_dishes_cleaned
    :initarg :total_dishes_cleaned
    :type cl:integer
    :initform 0))
)

(cl:defclass DoDishesResult (<DoDishesResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DoDishesResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DoDishesResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name learning_action-msg:<DoDishesResult> is deprecated: use learning_action-msg:DoDishesResult instead.")))

(cl:ensure-generic-function 'total_dishes_cleaned-val :lambda-list '(m))
(cl:defmethod total_dishes_cleaned-val ((m <DoDishesResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader learning_action-msg:total_dishes_cleaned-val is deprecated.  Use learning_action-msg:total_dishes_cleaned instead.")
  (total_dishes_cleaned m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DoDishesResult>) ostream)
  "Serializes a message object of type '<DoDishesResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DoDishesResult>) istream)
  "Deserializes a message object of type '<DoDishesResult>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DoDishesResult>)))
  "Returns string type for a message object of type '<DoDishesResult>"
  "learning_action/DoDishesResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DoDishesResult)))
  "Returns string type for a message object of type 'DoDishesResult"
  "learning_action/DoDishesResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DoDishesResult>)))
  "Returns md5sum for a message object of type '<DoDishesResult>"
  "58faa44dda59c6545bea63ff57491cbe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DoDishesResult)))
  "Returns md5sum for a message object of type 'DoDishesResult"
  "58faa44dda59c6545bea63ff57491cbe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DoDishesResult>)))
  "Returns full string definition for message of type '<DoDishesResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#定义结果信息result~%uint32 total_dishes_cleaned~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DoDishesResult)))
  "Returns full string definition for message of type 'DoDishesResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#定义结果信息result~%uint32 total_dishes_cleaned~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DoDishesResult>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DoDishesResult>))
  "Converts a ROS message object to a list"
  (cl:list 'DoDishesResult
    (cl:cons ':total_dishes_cleaned (total_dishes_cleaned msg))
))
