# Install script for directory: /home/lizhangxun/LZX_LEARNING_ROS/src/ros_tutorials_topic

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_tutorials_topic/msg" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/src/ros_tutorials_topic/msg/MsgTutorial.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_tutorials_topic/cmake" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/ros_tutorials_topic/catkin_generated/installspace/ros_tutorials_topic-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/include/ros_tutorials_topic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/roseus/ros/ros_tutorials_topic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/common-lisp/ros/ros_tutorials_topic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/share/gennodejs/ros/ros_tutorials_topic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/python2.7/dist-packages/ros_tutorials_topic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/python2.7/dist-packages/ros_tutorials_topic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/ros_tutorials_topic/catkin_generated/installspace/ros_tutorials_topic.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_tutorials_topic/cmake" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/build/ros_tutorials_topic/catkin_generated/installspace/ros_tutorials_topic-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_tutorials_topic/cmake" TYPE FILE FILES
    "/home/lizhangxun/LZX_LEARNING_ROS/build/ros_tutorials_topic/catkin_generated/installspace/ros_tutorials_topicConfig.cmake"
    "/home/lizhangxun/LZX_LEARNING_ROS/build/ros_tutorials_topic/catkin_generated/installspace/ros_tutorials_topicConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_tutorials_topic" TYPE FILE FILES "/home/lizhangxun/LZX_LEARNING_ROS/src/ros_tutorials_topic/package.xml")
endif()

