# Install script for directory: /home/lizhangxun/LZX_LEARNING_ROS/src/action_homework

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/action_homework/action" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/src/action_homework/action/robot_move.action")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/action_homework/msg" TYPE FILE FILES
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveAction.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveActionGoal.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveActionResult.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveActionFeedback.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveGoal.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveResult.msg"
    "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/action_homework/msg/robot_moveFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/action_homework/cmake" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/action_homework/catkin_generated/installspace/action_homework-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/include/action_homework")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/roseus/ros/action_homework")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/common-lisp/ros/action_homework")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/gennodejs/ros/action_homework")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/python2.7/dist-packages/action_homework")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/python2.7/dist-packages/action_homework")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/action_homework/catkin_generated/installspace/action_homework.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/action_homework/cmake" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/action_homework/catkin_generated/installspace/action_homework-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/action_homework/cmake" TYPE FILE FILES
    "/home/lizhangxun/LZX_LEARNING_ROS/build/action_homework/catkin_generated/installspace/action_homeworkConfig.cmake"
    "/home/lizhangxun/LZX_LEARNING_ROS/build/action_homework/catkin_generated/installspace/action_homeworkConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/action_homework" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/src/action_homework/package.xml")
endif()

