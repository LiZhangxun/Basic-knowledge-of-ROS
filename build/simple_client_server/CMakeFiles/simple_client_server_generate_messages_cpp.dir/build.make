# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lizhangxun/ROS_C++/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lizhangxun/ROS_C++/build

# Utility rule file for simple_client_server_generate_messages_cpp.

# Include the progress variables for this target.
include simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/progress.make

simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp: /home/lizhangxun/ROS_C++/devel/include/simple_client_server/AddTwoInts.h


/home/lizhangxun/ROS_C++/devel/include/simple_client_server/AddTwoInts.h: /opt/ros/kinetic/lib/gencpp/gen_cpp.py
/home/lizhangxun/ROS_C++/devel/include/simple_client_server/AddTwoInts.h: /home/lizhangxun/ROS_C++/src/simple_client_server/srv/AddTwoInts.srv
/home/lizhangxun/ROS_C++/devel/include/simple_client_server/AddTwoInts.h: /opt/ros/kinetic/share/gencpp/msg.h.template
/home/lizhangxun/ROS_C++/devel/include/simple_client_server/AddTwoInts.h: /opt/ros/kinetic/share/gencpp/srv.h.template
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lizhangxun/ROS_C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating C++ code from simple_client_server/AddTwoInts.srv"
	cd /home/lizhangxun/ROS_C++/src/simple_client_server && /home/lizhangxun/ROS_C++/build/catkin_generated/env_cached.sh /usr/bin/python2 /opt/ros/kinetic/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/lizhangxun/ROS_C++/src/simple_client_server/srv/AddTwoInts.srv -Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg -p simple_client_server -o /home/lizhangxun/ROS_C++/devel/include/simple_client_server -e /opt/ros/kinetic/share/gencpp/cmake/..

simple_client_server_generate_messages_cpp: simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp
simple_client_server_generate_messages_cpp: /home/lizhangxun/ROS_C++/devel/include/simple_client_server/AddTwoInts.h
simple_client_server_generate_messages_cpp: simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/build.make

.PHONY : simple_client_server_generate_messages_cpp

# Rule to build all files generated by this target.
simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/build: simple_client_server_generate_messages_cpp

.PHONY : simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/build

simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/clean:
	cd /home/lizhangxun/ROS_C++/build/simple_client_server && $(CMAKE_COMMAND) -P CMakeFiles/simple_client_server_generate_messages_cpp.dir/cmake_clean.cmake
.PHONY : simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/clean

simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/depend:
	cd /home/lizhangxun/ROS_C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lizhangxun/ROS_C++/src /home/lizhangxun/ROS_C++/src/simple_client_server /home/lizhangxun/ROS_C++/build /home/lizhangxun/ROS_C++/build/simple_client_server /home/lizhangxun/ROS_C++/build/simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simple_client_server/CMakeFiles/simple_client_server_generate_messages_cpp.dir/depend

