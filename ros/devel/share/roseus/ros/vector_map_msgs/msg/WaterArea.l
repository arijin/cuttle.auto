;; Auto-generated. Do not edit!


(when (boundp 'vector_map_msgs::WaterArea)
  (if (not (find-package "VECTOR_MAP_MSGS"))
    (make-package "VECTOR_MAP_MSGS"))
  (shadow 'WaterArea (find-package "VECTOR_MAP_MSGS")))
(unless (find-package "VECTOR_MAP_MSGS::WATERAREA")
  (make-package "VECTOR_MAP_MSGS::WATERAREA"))

(in-package "ROS")
;;//! \htmlinclude WaterArea.msg.html


(defclass vector_map_msgs::WaterArea
  :super ros::object
  :slots (_id _kid _slid _elid _connectid ))

(defmethod vector_map_msgs::WaterArea
  (:init
   (&key
    ((:id __id) 0)
    ((:kid __kid) 0)
    ((:slid __slid) 0)
    ((:elid __elid) 0)
    ((:connectid __connectid) 0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _kid (round __kid))
   (setq _slid (round __slid))
   (setq _elid (round __elid))
   (setq _connectid (round __connectid))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:kid
   (&optional __kid)
   (if __kid (setq _kid __kid)) _kid)
  (:slid
   (&optional __slid)
   (if __slid (setq _slid __slid)) _slid)
  (:elid
   (&optional __elid)
   (if __elid (setq _elid __elid)) _elid)
  (:connectid
   (&optional __connectid)
   (if __connectid (setq _connectid __connectid)) _connectid)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; int32 _kid
    4
    ;; int32 _slid
    4
    ;; int32 _elid
    4
    ;; int32 _connectid
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; int32 _kid
       (write-long _kid s)
     ;; int32 _slid
       (write-long _slid s)
     ;; int32 _elid
       (write-long _elid s)
     ;; int32 _connectid
       (write-long _connectid s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _kid
     (setq _kid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _slid
     (setq _slid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _elid
     (setq _elid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _connectid
     (setq _connectid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get vector_map_msgs::WaterArea :md5sum-) "c3d76e4604dd439eb4bc0783df641df8")
(setf (get vector_map_msgs::WaterArea :datatype-) "vector_map_msgs/WaterArea")
(setf (get vector_map_msgs::WaterArea :definition-)
      "# Ver 1.00
int32 id
int32 kid
int32 slid
int32 elid
int32 connectid

")



(provide :vector_map_msgs/WaterArea "c3d76e4604dd439eb4bc0783df641df8")


