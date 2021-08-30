;; Auto-generated. Do not edit!


(when (boundp 'person_service::s_c_person)
  (if (not (find-package "PERSON_SERVICE"))
    (make-package "PERSON_SERVICE"))
  (shadow 's_c_person (find-package "PERSON_SERVICE")))
(unless (find-package "PERSON_SERVICE::S_C_PERSON")
  (make-package "PERSON_SERVICE::S_C_PERSON"))
(unless (find-package "PERSON_SERVICE::S_C_PERSONREQUEST")
  (make-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(unless (find-package "PERSON_SERVICE::S_C_PERSONRESPONSE")
  (make-package "PERSON_SERVICE::S_C_PERSONRESPONSE"))

(in-package "ROS")





(intern "*UNKNOWN*" (find-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(shadow '*UNKNOWN* (find-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(defconstant person_service::s_c_personRequest::*UNKNOWN* 0)
(intern "*MALE*" (find-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(shadow '*MALE* (find-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(defconstant person_service::s_c_personRequest::*MALE* 1)
(intern "*FEMALE*" (find-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(shadow '*FEMALE* (find-package "PERSON_SERVICE::S_C_PERSONREQUEST"))
(defconstant person_service::s_c_personRequest::*FEMALE* 2)
(defclass person_service::s_c_personRequest
  :super ros::object
  :slots (_name _age _sex ))

(defmethod person_service::s_c_personRequest
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:sex __sex) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _sex (round __sex))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _age
    1
    ;; uint8 _sex
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _age
       (write-byte _age s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass person_service::s_c_personResponse
  :super ros::object
  :slots (_result ))

(defmethod person_service::s_c_personResponse
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass person_service::s_c_person
  :super ros::object
  :slots ())

(setf (get person_service::s_c_person :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get person_service::s_c_person :datatype-) "person_service/s_c_person")
(setf (get person_service::s_c_person :request) person_service::s_c_personRequest)
(setf (get person_service::s_c_person :response) person_service::s_c_personResponse)

(defmethod person_service::s_c_personRequest
  (:response () (instance person_service::s_c_personResponse :init)))

(setf (get person_service::s_c_personRequest :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get person_service::s_c_personRequest :datatype-) "person_service/s_c_personRequest")
(setf (get person_service::s_c_personRequest :definition-)
      "string name
uint8 age
uint8 sex

uint8 unknown=0
uint8 male=1
uint8 female=2
---
string result
")

(setf (get person_service::s_c_personResponse :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get person_service::s_c_personResponse :datatype-) "person_service/s_c_personResponse")
(setf (get person_service::s_c_personResponse :definition-)
      "string name
uint8 age
uint8 sex

uint8 unknown=0
uint8 male=1
uint8 female=2
---
string result
")



(provide :person_service/s_c_person "c198113e7dd9cc5c9fd5f271c8479b39")


