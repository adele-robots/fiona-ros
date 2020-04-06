cmake_minimum_required(VERSION 2.8.3)
project(fiona_pkg)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation)

## Declare ROS messages and services
add_message_files(DIRECTORY msg FILES MyMessages.msg)
add_service_files(DIRECTORY srv FILES Animation_srv.srv
					Application_srv.srv
					AsyncFatalErrorHandler_srv.srv
					AudioBuffer_srv.srv
					AudioSize_srv.srv
					CameraParameters_srv.srv
					CameraPosition_srv.srv
					CameraRotation_srv.srv
					Concurrent_srv.srv		
					ControlVoice_srv.srv	
					DetectedFacePositionConsumer_srv.srv
					Eyes_srv.srv
					FaceExpression_srv.srv
					FrameEventSubscriber_srv.srv	
					Neck_srv.srv
					Renderizable_srv.srv
					ThreadProc_srv.srv
					VoiceSay_srv.srv
					VoiceWaitStop_srv.srv
					WindowColorDepth_srv.srv
					Window_srv.srv
				       	fiona_srv.srv)

## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime)

## Build talker
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(fiona_talker src/fiona_talker.cpp)
target_link_libraries(fiona_talker ${catkin_LIBRARIES})
add_dependencies(fiona_talker fiona_pkg_generate_messages_cpp)

## Build client
add_executable(fiona_cameraparameters_client src/fiona_cameraparameters_client.cpp)
target_link_libraries(fiona_cameraparameters_client ${catkin_LIBRARIES})
add_dependencies(fiona_cameraparameters_client fiona_pkg_generate_messages.cpp)

## Build server
add_executable(fiona_cameraparameters_server src/fiona_cameraparameters_server.cpp)
target_link_libraries(fiona_cameraparameters_server ${catkin_LIBRARIES})
add_dependencies(fiona_cameraparameters_server fiona_pkg_generate_messages.cpp)
