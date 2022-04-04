;; Auto-generated. Do not edit!


(when (boundp 'water_msgs::ShipState)
  (if (not (find-package "WATER_MSGS"))
    (make-package "WATER_MSGS"))
  (shadow 'ShipState (find-package "WATER_MSGS")))
(unless (find-package "WATER_MSGS::SHIPSTATE")
  (make-package "WATER_MSGS::SHIPSTATE"))

(in-package "ROS")
;;//! \htmlinclude ShipState.msg.html
(if (not (find-package "GAZEBO_MSGS"))
  (ros::roseus-add-msgs "gazebo_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass water_msgs::ShipState
  :super ros::object
  :slots (_header _modelstate ))

(defmethod water_msgs::ShipState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:modelstate __modelstate) (instance gazebo_msgs::ModelState :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _modelstate __modelstate)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:modelstate
   (&rest __modelstate)
   (if (keywordp (car __modelstate))
       (send* _modelstate __modelstate)
     (progn
       (if __modelstate (setq _modelstate (car __modelstate)))
       _modelstate)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; gazebo_msgs/ModelState _modelstate
    (send _modelstate :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; gazebo_msgs/ModelState _modelstate
       (send _modelstate :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; gazebo_msgs/ModelState _modelstate
     (send _modelstate :deserialize buf ptr-) (incf ptr- (send _modelstate :serialization-length))
   ;;
   self)
  )

(setf (get water_msgs::ShipState :md5sum-) "33096c68969bd500c544dae60549ddbb")
(setf (get water_msgs::ShipState :datatype-) "water_msgs/ShipState")
(setf (get water_msgs::ShipState :definition-)
      "std_msgs/Header header
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
                            # leave empty or \"world\" or \"map\" defaults to world-frame


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
")



(provide :water_msgs/ShipState "33096c68969bd500c544dae60549ddbb")


