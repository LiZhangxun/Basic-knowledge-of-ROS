# Install script for directory: /home/lizhangxun/LZX_LEARNING_ROS/src/learning_action2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lizhangxun/LZX_LEARNING_ROS/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/learning_action2/action" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/src/learning_action2/action/Fibonacci.action")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/learning_action2/msg" TYPE FILE FILES
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciAction.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciActionGoal.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciActionResult.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciActionFeedback.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciGoal.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciResult.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/learning_action2/msg/FibonacciFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/learning_action2/cmake" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/learning_action2/catkin_generated/installspace/learning_action2-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/include/learning_action2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/roseus/ros/learning_action2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/common-lisp/ros/learning_action2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/gennodejs/ros/learning_action2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/python2.7/dist-packages/learning_action2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/python2.7/dist-packages/learning_action2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/learning_action2/catkin_generated/installspace/learning_action2.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/learning_action2/cmake" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/learning_action2/catkin_generated/installspace/learning_action2-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/learning_action2/cmake" TYPE FILE FILES
    "/home/lizhangxun/LZX_LEARNING_ROS/build/learning_action2/catkin_generated/installspace/learning_action2Config.cmake"
    "/home/lizhangxun/LZX_LEARNING_ROS/build/learning_action2/catkin_generated/installspace/learning_action2Config-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/learning_action2" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/src/learning_action2/package.xml")
endif()

