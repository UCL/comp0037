cmake_minimum_required(VERSION 2.8.3)
project(stdr_dynamic_obstacle)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  nodelet
  tf
  stdr_msgs
  stdr_parser
  geometry_msgs
  sensor_msgs
  nav_msgs
)



include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    stdr_handle_dynamic_obstacle
  CATKIN_DEPENDS
    roscpp
    nodelet
    tf
    stdr_msgs
    stdr_parser
    geometry_msgs
    sensor_msgs
    nav_msgs
#  DEPENDS system_lib
)

######################### Sensors ######################################
#add_library(stdr_sensor_base src/sensors/sensor_base.cpp)
#target_link_libraries(stdr_sensor_base ${catkin_LIBRARIES})

#add_library(stdr_sonar src/sensors/sonar.cpp)
#add_dependencies(stdr_sonar ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_sonar ${catkin_LIBRARIES} stdr_sensor_base)

#add_library(stdr_rfid_reader src/sensors/rfid_reader.cpp)
#add_dependencies(stdr_rfid_reader ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_rfid_reader ${catkin_LIBRARIES} stdr_sensor_base)

#add_library(stdr_co2_sensor src/sensors/co2.cpp)
#add_dependencies(stdr_co2_sensor ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_co2_sensor ${catkin_LIBRARIES} stdr_sensor_base)

#add_library(stdr_microphone_sensor src/sensors/microphone.cpp)
#add_dependencies(stdr_microphone_sensor ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_microphone_sensor ${catkin_LIBRARIES} stdr_sensor_base)

#add_library(stdr_thermal_sensor src/sensors/thermal.cpp)
#add_dependencies(stdr_thermal_sensor ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_thermal_sensor ${catkin_LIBRARIES} stdr_sensor_base)

#add_library(stdr_laser src/sensors/laser.cpp)
#add_dependencies(stdr_laser ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_laser ${catkin_LIBRARIES} stdr_sensor_base)

###################### Motion Controller ###############################
#add_library(stdr_ideal_motion_controller src/motion/ideal_motion_controller.cpp)
#add_dependencies(stdr_ideal_motion_controller ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_ideal_motion_controller ${catkin_LIBRARIES})

#add_library(stdr_omni_motion_controller src/motion/omni_motion_controller.cpp)
#add_dependencies(stdr_omni_motion_controller ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_omni_motion_controller ${catkin_LIBRARIES})

######################### Dynamic_Obstacle ########################################
#add_library(stdr_dynamic_obstacle_nodelet src/stdr_dynamic_obstacle.cpp)
#add_dependencies(stdr_dynamic_obstacle_nodelet ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
#target_link_libraries(stdr_dynamic_obstacle_nodelet ${catkin_LIBRARIES}
#    stdr_laser
#    stdr_sonar
#    stdr_rfid_reader
#    stdr_co2_sensor
#    stdr_thermal_sensor
#    stdr_microphone_sensor
#    stdr_ideal_motion_controller
#    stdr_omni_motion_controller
#)

######################### HandleDynamic_Obstacle ##################################
add_library(stdr_handle_dynamic_obstacle src/handle_dynamic_obstacle.cpp)
add_dependencies(stdr_handle_dynamic_obstacle ${stdr_msgs_EXPORTED_TARGETS}) # wait for stdr_msgs to be build
target_link_libraries(stdr_handle_dynamic_obstacle ${catkin_LIBRARIES})

####################### Dynamic_Obstacle Handler ##################################
add_executable(dynamic_obstacle_handler src/handle_dynamic_obstacle_node.cpp)
target_link_libraries(dynamic_obstacle_handler
  ${catkin_LIBRARIES}
  stdr_handle_dynamic_obstacle
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)

install(FILES dynamic_obstacle_plugins.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

# Install libraries
install(TARGETS
#    stdr_sensor_base
#    stdr_sonar
#    stdr_rfid_reader
#    stdr_co2_sensor
#    stdr_microphone_sensor
#    stdr_thermal_sensor
#    stdr_laser
#    stdr_ideal_motion_controller
#    stdr_omni_motion_controller
    stdr_handle_dynamic_obstacle
#    stdr_dynamic_obstacle_nodelet
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

# Install headers
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

# Install excecutables
install(TARGETS dynamic_obstacle_handler
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
