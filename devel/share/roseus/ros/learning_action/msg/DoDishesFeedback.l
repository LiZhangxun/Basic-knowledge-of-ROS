;; Auto-generated. Do not edit!


(when (boundp 'learning_action::DoDishesFeedback)
  (if (not (find-package "LEARNING_ACTION"))
    (make-package "LEARNING_ACTION"))
  (shadow 'DoDishesFeedback (find-package "LEARNING_ACTION")))
(unless (find-package "LEARNING_ACTION::DODISHESFEEDBACK")
  (make-package "LEARNING_ACTION::DODISHESFEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude DoDishesFeedback.msg.html


(defclass learning_action::DoDishesFeedback
  :super ros::object
  :slots (_percent_complete ))

(defmethod learning_action::DoDishesFeedback
  (:init
   (&key
    ((:percent_complete __percent_complete) 0.0)
    )
   (send-super :init)
   (setq _percent_complete (float __percent_complete))
   self)
  (:percent_complete
   (&optional __percent_complete)
   (if __percent_complete (setq _percent_complete __percent_complete)) _percent_complete)
  (:serialization-length
   ()
   (+
    ;; float32 _percent_complete
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _percent_complete
       (sys::poke _percent_complete (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _percent_complete
     (setq _percent_complete (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get learning_action::DoDishesFeedback :md5sum-) "d342375c60a5a58d3bc32664070a1368")
(setf (get learning_action::DoDishesFeedback :datatype-) "learning_action/DoDishesFeedback")
(setf (get learning_action::DoDishesFeedback :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#定义周期反馈消息feedback
float32 percent_complete

")



(provide :learning_action/DoDishesFeedback "d342375c60a5a58d3bc32664070a1368")


