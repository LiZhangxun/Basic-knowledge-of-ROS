
(cl:in-package :asdf)

(defsystem "delta_lidar-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Laser_distance" :depends-on ("_package_Laser_distance"))
    (:file "_package_Laser_distance" :depends-on ("_package"))
  ))