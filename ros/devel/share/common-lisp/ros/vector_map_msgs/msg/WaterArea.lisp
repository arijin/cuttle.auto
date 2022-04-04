; Auto-generated. Do not edit!


(cl:in-package vector_map_msgs-msg)


;//! \htmlinclude WaterArea.msg.html

(cl:defclass <WaterArea> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (kid
    :reader kid
    :initarg :kid
    :type cl:integer
    :initform 0)
   (slid
    :reader slid
    :initarg :slid
    :type cl:integer
    :initform 0)
   (elid
    :reader elid
    :initarg :elid
    :type cl:integer
    :initform 0)
   (connectid
    :reader connectid
    :initarg :connectid
    :type cl:integer
    :initform 0))
)

(cl:defclass WaterArea (<WaterArea>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WaterArea>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WaterArea)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name vector_map_msgs-msg:<WaterArea> is deprecated: use vector_map_msgs-msg:WaterArea instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <WaterArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vector_map_msgs-msg:id-val is deprecated.  Use vector_map_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'kid-val :lambda-list '(m))
(cl:defmethod kid-val ((m <WaterArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vector_map_msgs-msg:kid-val is deprecated.  Use vector_map_msgs-msg:kid instead.")
  (kid m))

(cl:ensure-generic-function 'slid-val :lambda-list '(m))
(cl:defmethod slid-val ((m <WaterArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vector_map_msgs-msg:slid-val is deprecated.  Use vector_map_msgs-msg:slid instead.")
  (slid m))

(cl:ensure-generic-function 'elid-val :lambda-list '(m))
(cl:defmethod elid-val ((m <WaterArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vector_map_msgs-msg:elid-val is deprecated.  Use vector_map_msgs-msg:elid instead.")
  (elid m))

(cl:ensure-generic-function 'connectid-val :lambda-list '(m))
(cl:defmethod connectid-val ((m <WaterArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vector_map_msgs-msg:connectid-val is deprecated.  Use vector_map_msgs-msg:connectid instead.")
  (connectid m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WaterArea>) ostream)
  "Serializes a message object of type '<WaterArea>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'kid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'slid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'elid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'connectid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WaterArea>) istream)
  "Deserializes a message object of type '<WaterArea>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'kid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'slid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'elid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'connectid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WaterArea>)))
  "Returns string type for a message object of type '<WaterArea>"
  "vector_map_msgs/WaterArea")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WaterArea)))
  "Returns string type for a message object of type 'WaterArea"
  "vector_map_msgs/WaterArea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WaterArea>)))
  "Returns md5sum for a message object of type '<WaterArea>"
  "c3d76e4604dd439eb4bc0783df641df8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WaterArea)))
  "Returns md5sum for a message object of type 'WaterArea"
  "c3d76e4604dd439eb4bc0783df641df8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WaterArea>)))
  "Returns full string definition for message of type '<WaterArea>"
  (cl:format cl:nil "# Ver 1.00~%int32 id~%int32 kid~%int32 slid~%int32 elid~%int32 connectid~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WaterArea)))
  "Returns full string definition for message of type 'WaterArea"
  (cl:format cl:nil "# Ver 1.00~%int32 id~%int32 kid~%int32 slid~%int32 elid~%int32 connectid~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WaterArea>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WaterArea>))
  "Converts a ROS message object to a list"
  (cl:list 'WaterArea
    (cl:cons ':id (id msg))
    (cl:cons ':kid (kid msg))
    (cl:cons ':slid (slid msg))
    (cl:cons ':elid (elid msg))
    (cl:cons ':connectid (connectid msg))
))
