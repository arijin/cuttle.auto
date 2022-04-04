; Auto-generated. Do not edit!


(cl:in-package water_msgs-msg)


;//! \htmlinclude ShipState.msg.html

(cl:defclass <ShipState> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (modelstate
    :reader modelstate
    :initarg :modelstate
    :type gazebo_msgs-msg:ModelState
    :initform (cl:make-instance 'gazebo_msgs-msg:ModelState)))
)

(cl:defclass ShipState (<ShipState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ShipState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ShipState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name water_msgs-msg:<ShipState> is deprecated: use water_msgs-msg:ShipState instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ShipState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader water_msgs-msg:header-val is deprecated.  Use water_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'modelstate-val :lambda-list '(m))
(cl:defmethod modelstate-val ((m <ShipState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader water_msgs-msg:modelstate-val is deprecated.  Use water_msgs-msg:modelstate instead.")
  (modelstate m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ShipState>) ostream)
  "Serializes a message object of type '<ShipState>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'modelstate) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ShipState>) istream)
  "Deserializes a message object of type '<ShipState>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'modelstate) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ShipState>)))
  "Returns string type for a message object of type '<ShipState>"
  "water_msgs/ShipState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ShipState)))
  "Returns string type for a message object of type 'ShipState"
  "water_msgs/ShipState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ShipState>)))
  "Returns md5sum for a message object of type '<ShipState>"
  "33096c68969bd500c544dae60549ddbb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ShipState)))
  "Returns md5sum for a message object of type 'ShipState"
  "33096c68969bd500c544dae60549ddbb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ShipState>)))
  "Returns full string definition for message of type '<ShipState>"
  (cl:format cl:nil "std_msgs/Header header~%gazebo_msgs/ModelState modelstate~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: gazebo_msgs/ModelState~%# Set Gazebo Model pose and twist~%string model_name           # model to set state (pose and twist)~%geometry_msgs/Pose pose     # desired pose in reference frame~%geometry_msgs/Twist twist   # desired twist in reference frame~%string reference_frame      # set pose/twist relative to the frame of this entity (Body/Model)~%                            # leave empty or \"world\" or \"map\" defaults to world-frame~%~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ShipState)))
  "Returns full string definition for message of type 'ShipState"
  (cl:format cl:nil "std_msgs/Header header~%gazebo_msgs/ModelState modelstate~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: gazebo_msgs/ModelState~%# Set Gazebo Model pose and twist~%string model_name           # model to set state (pose and twist)~%geometry_msgs/Pose pose     # desired pose in reference frame~%geometry_msgs/Twist twist   # desired twist in reference frame~%string reference_frame      # set pose/twist relative to the frame of this entity (Body/Model)~%                            # leave empty or \"world\" or \"map\" defaults to world-frame~%~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ShipState>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'modelstate))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ShipState>))
  "Converts a ROS message object to a list"
  (cl:list 'ShipState
    (cl:cons ':header (header msg))
    (cl:cons ':modelstate (modelstate msg))
))
