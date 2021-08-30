cmake_minimum_required(VERSION 2.8.3)
project(delta_lidar)

set(delta_lidar_SDK_PATH "./sdk/")

FILE(GLOB delta_lidar_SDK_SRC 
  "${delta_lidar_SDK_PATH}/src/*.cpp"
)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rosconsole
  sensor_msgs
)

add_message_files(FILES
  Laser_distance.msg
)

generate_messages(DEPENDENCIES
  std_msgs
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
  ${delta_lidar_SDK_PATH}/include
  ${delta_lidar_SDK_PATH}/src
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime)

add_executable(delta_lidar_node src/node.cpp ${delta_lidar_SDK_SRC})
target_link_libraries(delta_lidar_node ${catkin_LIBRARIES} -lrt)

add_executable(delta_lidar_node_client src/client.cpp)
target_link_libraries(delta_lidar_node_client ${catkin_LIBRARIES})

install(TARGETS delta_lidar_node delta_lidar_node_client
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch rviz sdk
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  USE_SOURCE_PERMISSIONS
)




add_executable(distance_sub
  src/distance_sub.cpp
)
add_dependencies(distance_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(distance_sub
  ${catkin_LIBRARIES}
)