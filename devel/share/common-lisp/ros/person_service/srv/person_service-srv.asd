
(cl:in-package :asdf)

(defsystem "person_service-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "s_c_person" :depends-on ("_package_s_c_person"))
    (:file "_package_s_c_person" :depends-on ("_package"))
  ))