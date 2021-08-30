;; Auto-generated. Do not edit!


(when (boundp 'delta_lidar::Laser_distance)
  (if (not (find-package "DELTA_LIDAR"))
    (make-package "DELTA_LIDAR"))
  (shadow 'Laser_distance (find-package "DELTA_LIDAR")))
(unless (find-package "DELTA_LIDAR::LASER_DISTANCE")
  (make-package "DELTA_LIDAR::LASER_DISTANCE"))

(in-package "ROS")
;;//! \htmlinclude Laser_distance.msg.html


(defclass delta_lidar::Laser_distance
  :super ros::object
  :slots (_distance ))

(defmethod delta_lidar::Laser_distance
  (:init
   (&key
    ((:distance __distance) 0.0)
    )
   (send-super :init)
   (setq _distance (float __distance))
   self)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; float32 _distance
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _distance
     (setq _distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get delta_lidar::Laser_distance :md5sum-) "6e77fb10f0c8b4833ec273aa9ac74459")
(setf (get delta_lidar::Laser_distance :datatype-) "delta_lidar/Laser_distance")
(setf (get delta_lidar::Laser_distance :definition-)
      "float32 distance
")



(provide :delta_lidar/Laser_distance "6e77fb10f0c8b4833ec273aa9ac74459")


