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

# Include any dependencies generated for this target.
include simple_client_server/CMakeFiles/AddTwoints_Client.dir/depend.make

# Include the progress variables for this target.
include simple_client_server/CMakeFiles/AddTwoints_Client.dir/progress.make

# Include the compile flags for this target's objects.
include simple_client_server/CMakeFiles/AddTwoints_Client.dir/flags.make

simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o: simple_client_server/CMakeFiles/AddTwoints_Client.dir/flags.make
simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o: /home/lizhangxun/ROS_C++/src/simple_client_server/src/AddTwoints_Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lizhangxun/ROS_C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o"
	cd /home/lizhangxun/ROS_C++/build/simple_client_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o -c /home/lizhangxun/ROS_C++/src/simple_client_server/src/AddTwoints_Client.cpp

simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.i"
	cd /home/lizhangxun/ROS_C++/build/simple_client_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lizhangxun/ROS_C++/src/simple_client_server/src/AddTwoints_Client.cpp > CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.i

simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.s"
	cd /home/lizhangxun/ROS_C++/build/simple_client_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lizhangxun/ROS_C++/src/simple_client_server/src/AddTwoints_Client.cpp -o CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.s

simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.requires:

.PHONY : simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.requires

simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.provides: simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.requires
	$(MAKE) -f simple_client_server/CMakeFiles/AddTwoints_Client.dir/build.make simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.provides.build
.PHONY : simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.provides

simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.provides.build: simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o


# Object files for target AddTwoints_Client
AddTwoints_Client_OBJECTS = \
"CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o"

# External object files for target AddTwoints_Client
AddTwoints_Client_EXTERNAL_OBJECTS =

/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: simple_client_server/CMakeFiles/AddTwoints_Client.dir/build.make
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/libroscpp.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/librosconsole.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/librostime.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /opt/ros/kinetic/lib/libcpp_common.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client: simple_client_server/CMakeFiles/AddTwoints_Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lizhangxun/ROS_C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client"
	cd /home/lizhangxun/ROS_C++/build/simple_client_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AddTwoints_Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simple_client_server/CMakeFiles/AddTwoints_Client.dir/build: /home/lizhangxun/ROS_C++/devel/lib/simple_client_server/AddTwoints_Client

.PHONY : simple_client_server/CMakeFiles/AddTwoints_Client.dir/build

simple_client_server/CMakeFiles/AddTwoints_Client.dir/requires: simple_client_server/CMakeFiles/AddTwoints_Client.dir/src/AddTwoints_Client.cpp.o.requires

.PHONY : simple_client_server/CMakeFiles/AddTwoints_Client.dir/requires

simple_client_server/CMakeFiles/AddTwoints_Client.dir/clean:
	cd /home/lizhangxun/ROS_C++/build/simple_client_server && $(CMAKE_COMMAND) -P CMakeFiles/AddTwoints_Client.dir/cmake_clean.cmake
.PHONY : simple_client_server/CMakeFiles/AddTwoints_Client.dir/clean

simple_client_server/CMakeFiles/AddTwoints_Client.dir/depend:
	cd /home/lizhangxun/ROS_C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lizhangxun/ROS_C++/src /home/lizhangxun/ROS_C++/src/simple_client_server /home/lizhangxun/ROS_C++/build /home/lizhangxun/ROS_C++/build/simple_client_server /home/lizhangxun/ROS_C++/build/simple_client_server/CMakeFiles/AddTwoints_Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simple_client_server/CMakeFiles/AddTwoints_Client.dir/depend

