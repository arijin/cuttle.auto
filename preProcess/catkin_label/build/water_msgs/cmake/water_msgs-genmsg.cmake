# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "water_msgs: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iwater_msgs:/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Igazebo_msgs:/opt/ros/melodic/share/gazebo_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/melodic/share/trajectory_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(water_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" NAME_WE)
add_custom_target(_water_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "water_msgs" "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" "geometry_msgs/Pose:geometry_msgs/Twist:geometry_msgs/Vector3:gazebo_msgs/ModelState:geometry_msgs/Point:geometry_msgs/Quaternion:std_msgs/Header"
)

get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" NAME_WE)
add_custom_target(_water_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "water_msgs" "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" "geometry_msgs/Pose:geometry_msgs/Twist:sensor_msgs/NavSatFix:geometry_msgs/Vector3:sensor_msgs/NavSatStatus:geometry_msgs/Point:geometry_msgs/Quaternion:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/gazebo_msgs/cmake/../msg/ModelState.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/water_msgs
)
_generate_msg_cpp(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/water_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(water_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/water_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(water_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(water_msgs_generate_messages water_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_cpp _water_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_cpp _water_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(water_msgs_gencpp)
add_dependencies(water_msgs_gencpp water_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS water_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/gazebo_msgs/cmake/../msg/ModelState.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/water_msgs
)
_generate_msg_eus(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/water_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(water_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/water_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(water_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(water_msgs_generate_messages water_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_eus _water_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_eus _water_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(water_msgs_geneus)
add_dependencies(water_msgs_geneus water_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS water_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/gazebo_msgs/cmake/../msg/ModelState.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/water_msgs
)
_generate_msg_lisp(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/water_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(water_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/water_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(water_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(water_msgs_generate_messages water_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_lisp _water_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_lisp _water_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(water_msgs_genlisp)
add_dependencies(water_msgs_genlisp water_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS water_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/gazebo_msgs/cmake/../msg/ModelState.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/water_msgs
)
_generate_msg_nodejs(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/water_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(water_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/water_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(water_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(water_msgs_generate_messages water_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_nodejs _water_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_nodejs _water_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(water_msgs_gennodejs)
add_dependencies(water_msgs_gennodejs water_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS water_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/gazebo_msgs/cmake/../msg/ModelState.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/water_msgs
)
_generate_msg_py(water_msgs
  "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/water_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(water_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/water_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(water_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(water_msgs_generate_messages water_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/ShipState.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_py _water_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/arijin/cuttle.auto/preProcess/catkin_label/src/robotx_label/water_msgs/msg/gpsPacket.msg" NAME_WE)
add_dependencies(water_msgs_generate_messages_py _water_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(water_msgs_genpy)
add_dependencies(water_msgs_genpy water_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS water_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/water_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/water_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(water_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(water_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(water_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET gazebo_msgs_generate_messages_cpp)
  add_dependencies(water_msgs_generate_messages_cpp gazebo_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/water_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/water_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(water_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(water_msgs_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(water_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET gazebo_msgs_generate_messages_eus)
  add_dependencies(water_msgs_generate_messages_eus gazebo_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/water_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/water_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(water_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(water_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(water_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET gazebo_msgs_generate_messages_lisp)
  add_dependencies(water_msgs_generate_messages_lisp gazebo_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/water_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/water_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(water_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(water_msgs_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(water_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET gazebo_msgs_generate_messages_nodejs)
  add_dependencies(water_msgs_generate_messages_nodejs gazebo_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/water_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/water_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/water_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(water_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(water_msgs_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(water_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET gazebo_msgs_generate_messages_py)
  add_dependencies(water_msgs_generate_messages_py gazebo_msgs_generate_messages_py)
endif()
