
(cl:in-package :asdf)

(defsystem "water_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :gazebo_msgs-msg
               :geometry_msgs-msg
               :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ShipState" :depends-on ("_package_ShipState"))
    (:file "_package_ShipState" :depends-on ("_package"))
    (:file "gpsPacket" :depends-on ("_package_gpsPacket"))
    (:file "_package_gpsPacket" :depends-on ("_package"))
  ))