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
include simple_callback_uselei/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include simple_callback_uselei/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include simple_callback_uselei/CMakeFiles/server.dir/flags.make

simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o: simple_callback_uselei/CMakeFiles/server.dir/flags.make
simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o: /home/lizhangxun/LZX_LEARNING_ROS/src/simple_callback_uselei/src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lizhangxun/LZX_LEARNING_ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/server.cpp.o -c /home/lizhangxun/LZX_LEARNING_ROS/src/simple_callback_uselei/src/server.cpp

simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/server.cpp.i"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lizhangxun/LZX_LEARNING_ROS/src/simple_callback_uselei/src/server.cpp > CMakeFiles/server.dir/src/server.cpp.i

simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/server.cpp.s"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lizhangxun/LZX_LEARNING_ROS/src/simple_callback_uselei/src/server.cpp -o CMakeFiles/server.dir/src/server.cpp.s

simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.requires:

.PHONY : simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.requires

simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.provides: simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.requires
	$(MAKE) -f simple_callback_uselei/CMakeFiles/server.dir/build.make simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.provides.build
.PHONY : simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.provides

simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.provides.build: simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o


# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/src/server.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: simple_callback_uselei/CMakeFiles/server.dir/build.make
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/libroscpp.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/librosconsole.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/librostime.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /opt/ros/kinetic/lib/libcpp_common.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server: simple_callback_uselei/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lizhangxun/LZX_LEARNING_ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server"
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simple_callback_uselei/CMakeFiles/server.dir/build: /home/lizhangxun/LZX_LEARNING_ROS/devel/lib/simple_callback_uselei/server

.PHONY : simple_callback_uselei/CMakeFiles/server.dir/build

simple_callback_uselei/CMakeFiles/server.dir/requires: simple_callback_uselei/CMakeFiles/server.dir/src/server.cpp.o.requires

.PHONY : simple_callback_uselei/CMakeFiles/server.dir/requires

simple_callback_uselei/CMakeFiles/server.dir/clean:
	cd /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : simple_callback_uselei/CMakeFiles/server.dir/clean

simple_callback_uselei/CMakeFiles/server.dir/depend:
	cd /home/lizhangxun/LZX_LEARNING_ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lizhangxun/LZX_LEARNING_ROS/src /home/lizhangxun/LZX_LEARNING_ROS/src/simple_callback_uselei /home/lizhangxun/LZX_LEARNING_ROS/build /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei /home/lizhangxun/LZX_LEARNING_ROS/build/simple_callback_uselei/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simple_callback_uselei/CMakeFiles/server.dir/depend

