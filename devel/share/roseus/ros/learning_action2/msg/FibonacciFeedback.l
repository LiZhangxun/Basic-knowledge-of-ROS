;; Auto-generated. Do not edit!


(when (boundp 'learning_action2::FibonacciFeedback)
  (if (not (find-package "LEARNING_ACTION2"))
    (make-package "LEARNING_ACTION2"))
  (shadow 'FibonacciFeedback (find-package "LEARNING_ACTION2")))
(unless (find-package "LEARNING_ACTION2::FIBONACCIFEEDBACK")
  (make-package "LEARNING_ACTION2::FIBONACCIFEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude FibonacciFeedback.msg.html


(defclass learning_action2::FibonacciFeedback
  :super ros::object
  :slots (_sequence ))

(defmethod learning_action2::FibonacciFeedback
  (:init
   (&key
    ((:sequence __sequence) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _sequence __sequence)
   self)
  (:sequence
   (&optional __sequence)
   (if __sequence (setq _sequence __sequence)) _sequence)
  (:serialization-length
   ()
   (+
    ;; int32[] _sequence
    (* 4    (length _sequence)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _sequence
     (write-long (length _sequence) s)
     (dotimes (i (length _sequence))
       (write-long (elt _sequence i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _sequence
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _sequence (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _sequence i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get learning_action2::FibonacciFeedback :md5sum-) "b81e37d2a31925a0e8ae261a8699cb79")
(setf (get learning_action2::FibonacciFeedback :datatype-) "learning_action2/FibonacciFeedback")
(setf (get learning_action2::FibonacciFeedback :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#feedback
int32[] sequence

")



(provide :learning_action2/FibonacciFeedback "b81e37d2a31925a0e8ae261a8699cb79")


