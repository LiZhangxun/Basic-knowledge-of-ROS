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
CMAKE_SOURCE_DIR = /home/lizhangxun/LZX_LEARNING_ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lizhangxun/LZX_LEARNING_ROS/build

# Include any dependencies generated for this target.
include learning_service/CMakeFiles/AddTwoints_Server.dir/depend.make

# Include the progress variables for this target.
include learning_service/CMakeFiles/AddTwoints_Server.dir/progress.make

# Include the compile flags for this target's objects.
include learning_service/CMakeFiles/AddTwoints_Server.dir/flags.make

learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o: learning_service/CMakeFiles/AddTwoints_Server.dir/flags.make
learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o: /home/lizhangxun/LZX_LEARNING_ROS/src/learning_service/src/AddTwoints_Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lizhangxun/LZX_LEARNING_ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o -c /home/lizhangxun/LZX_LEARNING_ROS/src/learning_service/src/AddTwoints_Server.cpp

learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.i"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lizhangxun/LZX_LEARNING_ROS/src/learning_service/src/AddTwoints_Server.cpp > CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.i

learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.s"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lizhangxun/LZX_LEARNING_ROS/src/learning_service/src/AddTwoints_Server.cpp -o CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.s

learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.requires:

.PHONY : learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.requires

learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.provides: learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.requires
	$(MAKE) -f learning_service/CMakeFiles/AddTwoints_Server.dir/build.make learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.provides.build
.PHONY : learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.provides

learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.provides.build: learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o


# Object files for target AddTwoints_Server
AddTwoints_Server_OBJECTS = \
"CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o"

# External object files for target AddTwoints_Server
AddTwoints_Server_EXTERNAL_OBJECTS =

/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: learning_service/CMakeFiles/AddTwoints_Server.dir/build.make
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/libroscpp.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/librosconsole.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/librostime.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /opt/ros/kinetic/lib/libcpp_common.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server: learning_service/CMakeFiles/AddTwoints_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lizhangxun/LZX_LEARNING_ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AddTwoints_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
learning_service/CMakeFiles/AddTwoints_Server.dir/build: /home/lizhangxun/LZX_LEARNING_ROS/devel/lib/learning_service/AddTwoints_Server

.PHONY : learning_service/CMakeFiles/AddTwoints_Server.dir/build

learning_service/CMakeFiles/AddTwoints_Server.dir/requires: learning_service/CMakeFiles/AddTwoints_Server.dir/src/AddTwoints_Server.cpp.o.requires

.PHONY : learning_service/CMakeFiles/AddTwoints_Server.dir/requires

learning_service/CMakeFiles/AddTwoints_Server.dir/clean:
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service && $(CMAKE_COMMAND) -P CMakeFiles/AddTwoints_Server.dir/cmake_clean.cmake
.PHONY : learning_service/CMakeFiles/AddTwoints_Server.dir/clean

learning_service/CMakeFiles/AddTwoints_Server.dir/depend:
	cd /home/lizhangxun/LZX_LEARNING_ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lizhangxun/LZX_LEARNING_ROS/src /home/lizhangxun/LZX_LEARNING_ROS/src/learning_service /home/lizhangxun/LZX_LEARNING_ROS/build /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service /home/lizhangxun/LZX_LEARNING_ROS/build/learning_service/CMakeFiles/AddTwoints_Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : learning_service/CMakeFiles/AddTwoints_Server.dir/depend

