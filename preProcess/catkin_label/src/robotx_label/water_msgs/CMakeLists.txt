cmake_minimum_required(VERSION 2.8.3)
project(water_msgs)

find_package(catkin REQUIRED COMPONENTS 
  message_generation
  std_msgs
  sensor_msgs
  geometry_msgs
  gazebo_msgs
)

add_message_files(
  DIRECTORY msg
  FILES
  ShipState.msg
  gpsPacket.msg

)
generate_messages(DEPENDENCIES std_msgs sensor_msgs geometry_msgs gazebo_msgs)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs sensor_msgs geometry_msgs gazebo_msgs
)
