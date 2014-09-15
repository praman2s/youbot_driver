project(youbot_driver)
cmake_minimum_required(VERSION 2.6)

########### CATKIN SPECIFIC ######## 
find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package(
  INCLUDE_DIRS 
    include/
  LIBRARIES
    soem
    YouBotDriver
)


option(USE_ROS "Enable ROS as compile tool" OFF)

########### ROS ###########
set(ROS_ROOT_PATH $ENV{ROS_ROOT})
if(DEFINED ROS_ROOT_PATH AND USE_ROS MATCHES ON)
  include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
  rosbuild_init()
  add_definitions(-DUSE_ROS_LOGGING)
endif()

########### cmake configuration and compiler flags ###########
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_FLAGS_DEBUG "-fPIC -Wall -g")
set(CMAKE_CXX_FLAGS_DEBUG "-fPIC -Wall -g")
set(CMAKE_C_FLAGS_RELEASE "-fPIC -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-fPIC -Wall")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) #static libraries
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #executables
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) #dynamic libraries (plugins)

# find required and optional dependencies

########### Boost ###########
#set(Boost_USE_STATIC_LIBS ON)
set(Boost_ADDITIONAL_VERSIONS "1.39" "1.39.0" "1.40" "1.40.0" "1.41" "1.41.0" "1.42" "1.42.0")
find_package(Boost REQUIRED COMPONENTS thread date_time filesystem system regex)
if(Boost_FOUND)
  link_libraries(boost_thread boost_date_time boost_filesystem boost_system boost_regex)
  message(STATUS "SUCCESSFUL: Boost found")
else()
  message(STATUS "ERROR: Boost not found")
endif()

########### Simple Open EtherCAT Master Library ###########
add_subdirectory(src/soem)

include_directories(
 ${PROJECT_SOURCE_DIR}/include
)

########### CppUnit and tests ###########
find_package(CppUnit)
if(CppUnit_FOUND)
	message(STATUS "SUCCESSFUL: CPP_UNIT found")
  add_subdirectory(src/test)
#else()
#	message(STATUS "WARNING: CPP_UNIT not found")
endif()

########### youBot display example application ###########
add_subdirectory(src/display)


set(YOUBOT_DRIVER_SRC
  ${PROJECT_SOURCE_DIR}/src/youbot/EthercatMaster.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/EthercatMasterWithThread.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/EthercatMasterWithoutThread.cpp
  ${PROJECT_SOURCE_DIR}/src/generic/Logger.cpp
  ${PROJECT_SOURCE_DIR}/src/generic/ConfigFile.cpp
  ${PROJECT_SOURCE_DIR}/src/generic/PidController.cpp
  ${PROJECT_SOURCE_DIR}/src/generic-joint/JointData.cpp
  ${PROJECT_SOURCE_DIR}/src/generic-joint/JointTrajectory.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotJoint.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/JointLimitMonitor.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotBase.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotManipulator.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotGripper.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotGripperBar.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotGripperParameter.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/DataTrace.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/GripperDataTrace.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotJointParameter.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotJointParameterReadOnly.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/YouBotJointParameterPasswordProtected.cpp
  ${PROJECT_SOURCE_DIR}/src/youbot/JointTrajectoryController.cpp
  ${PROJECT_SOURCE_DIR}/src/base-kinematic/FourSwedishWheelOmniBaseKinematic.cpp
  ${PROJECT_SOURCE_DIR}/src/base-kinematic/FourSwedishWheelOmniBaseKinematicConfiguration.cpp
  ${PROJECT_SOURCE_DIR}/src/base-kinematic/FourSwedishWheelOmniBaseDynamic.cpp
  ${PROJECT_SOURCE_DIR}/src/base-kinematic/FourSwedishWheelOmniBaseDynamicConfiguration.cpp
)


set(YOUBOT_DRIVER_HEADERS
  include/youbot/EthercatMaster.hpp
  include/youbot/EthercatMasterInterface.hpp
  include/youbot/EthercatMasterWithThread.hpp
  include/youbot/EthercatMasterWithoutThread.hpp
  include/youbot/YouBotGripper.hpp
  include/youbot/YouBotGripperBar.hpp
  include/youbot/YouBotGripperParameter.hpp
  include/youbot/YouBotBase.hpp
  include/youbot/YouBotManipulator.hpp
  include/youbot/YouBotJoint.hpp
  include/youbot/JointLimitMonitor.hpp
  include/youbot/YouBotJointParameterReadOnly.hpp
	include/youbot/YouBotJointParameterPasswordProtected.hpp
  include/youbot/YouBotJointParameter.hpp
  include/youbot/YouBotSlaveMailboxMsg.hpp
  include/youbot/YouBotSlaveMsg.hpp
  include/youbot/ProtocolDefinitions.hpp
  include/youbot/YouBotJointStorage.hpp
  include/youbot/DataTrace.hpp
  include/youbot/GripperDataTrace.hpp
  include/youbot/JointTrajectoryController.hpp
  include/base-kinematic/FourSwedishWheelOmniBaseKinematic.hpp
  include/base-kinematic/FourSwedishWheelOmniBaseKinematicConfiguration.hpp
  include/base-kinematic/WheeledBaseKinematic.hpp
  include/base-kinematic/FourSwedishWheelOmniBaseDynamic.hpp
  include/base-kinematic/FourSwedishWheelOmniBaseDynamicConfiguration.hpp
  include/base-kinematic/WheeledBaseDynamic.hpp
  include/generic/Exceptions.hpp
  include/generic/Logger.hpp
  include/generic/Time.hpp
  include/generic/Units.hpp
  include/generic/ConfigFile.hpp
  include/generic/PidController.hpp
  include/generic/dataobjectlockfree/DataObjectLockFree.hpp
  include/generic/dataobjectlockfree/target.hpp
  include/generic/dataobjectlockfree/os/oro_arch.h
  include/generic/dataobjectlockfree/os/oro_gcc/oro_arch.h
  include/generic/dataobjectlockfree/os/oro_i386/oro_arch.h
  include/generic/dataobjectlockfree/os/oro_msvc/oro_arch.h
  include/generic/dataobjectlockfree//os/oro_powerpc/oro_arch.h  
  include/generic/dataobjectlockfree/os/oro_powerpc/oro_atomic.h  
  include/generic/dataobjectlockfree/os/oro_powerpc/oro_system.h
  include/generic/dataobjectlockfree/os/oro_x86_64/oro_arch.h
  include/generic-gripper/Gripper.hpp
  include/generic-gripper/GripperData.hpp
  include/generic-gripper/GripperParameter.hpp
  include/generic-joint/Joint.hpp
  include/generic-joint/JointData.hpp
  include/generic-joint/JointTrajectory.hpp
  include/generic-joint/JointParameter.hpp
  include/one-dof-gripper/OneDOFGripper.hpp
  include/one-dof-gripper/OneDOFGripperData.hpp
)

set(YOUBOT_DRIVER_CONFIG
  ${PROJECT_SOURCE_DIR}/config/youbot-ethercat.cfg
  ${PROJECT_SOURCE_DIR}/config/youbot-base.cfg
  ${PROJECT_SOURCE_DIR}/config/youbot-manipulator.cfg
)

if(DEFINED ROS_ROOT_PATH AND USE_ROS MATCHES ON)
  rosbuild_add_library(YouBotDriver ${YOUBOT_DRIVER_SRC})
else()
  add_library(YouBotDriver ${YOUBOT_DRIVER_SRC})
endif()

target_link_libraries(YouBotDriver soem)
add_library(YouBotDriverShared SHARED "")
set_target_properties(YouBotDriverShared PROPERTIES OUTPUT_NAME "YouBotDriver")
set_target_properties(YouBotDriverShared PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(YouBotDriverShared -Wl,-whole-archive YouBotDriver soem -Wl,-no-whole-archive)

macro(INSTALL_HEADERS_WITH_DIRECTORY HEADER_LIST)
  foreach(HEADER ${${HEADER_LIST}})
    string(REGEX MATCH "(.*)[/\\]" DIR ${HEADER})
    install(FILES ${HEADER} DESTINATION include/youbot/youbot/${DIR})
  endforeach()
endmacro()

macro(INSTALL_CONFIG_WITH_DIRECTORY CONFIG_LIST)
  foreach(CONFIG ${${CONFIG_LIST}})
    string(REGEX MATCH "(.*)[/\\]" DIR ${CONFIG})
    install(FILES ${CONFIG} DESTINATION config)
  endforeach()
endmacro()

INSTALL_HEADERS_WITH_DIRECTORY(YOUBOT_DRIVER_HEADERS)
INSTALL_CONFIG_WITH_DIRECTORY(YOUBOT_DRIVER_CONFIG)
install(TARGETS YouBotDriver YouBotDriverShared RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)


#ADD_EXECUTABLE(YouBot_test
#  ${PROJECT_SOURCE_DIR}/Test_commutation.cpp
#)

#target_link_libraries(YouBot_test YouBotDriver)

