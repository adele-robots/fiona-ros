cmake_minimum_required(VERSION 2.8.3)
project(fiona_pkg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")

#### Find catkin and any catkin packages ####
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation)

#### Declare ROS messages and services ####
add_message_files(DIRECTORY msg FILES Animation_msg.msg
                                      Application_msg.msg
                                      AsyncFatalErrorHandler_msg.msg
                                      AudioBuffer_msg.msg
                                      AudioSize_msg.msg
                                      CameraParameters_msg.msg
                                      CameraPosition_msg.msg
                                      CameraRotation_msg.msg
                                      Concurrent_msg.msg
                                      ControlVoice_msg.msg
                                      DetectedFacePositionConsumer_msg.msg
                                      Eyes_msg.msg
                                      FaceExpression_msg.msg
                                      FrameEventSubscriber_msg.msg
                                      Neck_msg.msg
                                      Renderizable_msg.msg
                                      ThreadProc_msg.msg
                                      Voice_msg.msg
                                      WindowColorDepth_msg.msg
                                      Window_msg.msg)

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
				      Voice_srv.srv
				      WindowColorDepth_srv.srv
				      Window_srv.srv)
 
				       

#### Generate added messages and services with any dependencies listed here ####
generate_messages(DEPENDENCIES std_msgs)
catkin_package(CATKIN_DEPENDS message_runtime)

### Rostest ###
find_package(rostest REQUIRED)

add_rostest_gtest(test_animation tests/test_animation.launch tests/test_animation.cpp)
target_link_libraries(test_animation ${catkin_LIBRARIES})
add_dependencies(test_animation fiona_animation_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_application tests/test_application.launch tests/test_application.cpp)
target_link_libraries(test_application ${catkin_LIBRARIES})
add_dependencies(test_application fiona_application_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_audiobuffer tests/test_audiobuffer.launch tests/test_audiobuffer.cpp)
target_link_libraries(test_audiobuffer ${catkin_LIBRARIES})
add_dependencies(test_audiobuffer fiona_audiobuffer_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_audiosize tests/test_audiosize.launch tests/test_audiosize.cpp)
target_link_libraries(test_audiosize ${catkin_LIBRARIES})
add_dependencies(test_audiosize fiona_audiosize_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_cameraparameters tests/test_cameraparameters.launch tests/test_cameraparameters.cpp)
target_link_libraries(test_cameraparameters ${catkin_LIBRARIES})
add_dependencies(test_cameraparameters fiona_cameraparameters_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#### Build listener ####
include_directories(include ${catkin_INCLUDE_DIRS})

#add_executable(fiona_listener src/fiona_listener.cpp)
#target_link_libraries(fiona_listener ${catkin_LIBRARIES})
#add_dependencies(fiona_listener ${${PROJECT_NAME}_EXPORTED_TARGETS})

#### Build clients ####
# Client for ROSAnimationSpark
add_executable(fiona_animation_client src/fiona_animation_client.cpp)
target_link_libraries(fiona_animation_client ${catkin_LIBRARIES})
add_dependencies(fiona_animation_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSApplicationSpark
add_executable(fiona_application_client src/fiona_application_client.cpp)
target_link_libraries(fiona_application_client ${catkin_LIBRARIES})
add_dependencies(fiona_application_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSAudioSpark/ROSAudioBufferSpark
add_executable(fiona_audiobuffer_client src/fiona_audiobuffer_client.cpp)
target_link_libraries(fiona_audiobuffer_client ${catkin_LIBRARIES})
add_dependencies(fiona_audiobuffer_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSAudioSpark/ROSAudioSizeSpark
add_executable(fiona_audiosize_client src/fiona_audiosize_client.cpp)
target_link_libraries(fiona_audiosize_client ${catkin_LIBRARIES})
add_dependencies(fiona_audiosize_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSCameraSpark/RosCameraParametersSpark
add_executable(fiona_cameraparameters_client src/fiona_cameraparameters_client.cpp)
target_link_libraries(fiona_cameraparameters_client ${catkin_LIBRARIES})
add_dependencies(fiona_cameraparameters_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSCameraSpark/ROSCameraPositionSpark
add_executable(fiona_cameraposition_client src/fiona_cameraposition_client.cpp)
target_link_libraries(fiona_cameraposition_client ${catkin_LIBRARIES})
add_dependencies(fiona_cameraposition_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSCameraSpark/ROSCameraRotationSpark
add_executable(fiona_camerarotation_client src/fiona_camerarotation_client.cpp)
target_link_libraries(fiona_camerarotation_client ${catkin_LIBRARIES})
add_dependencies(fiona_camerarotation_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSConcurrentSpark
add_executable(fiona_concurrent_client src/fiona_concurrent_client.cpp)
target_link_libraries(fiona_concurrent_client ${catkin_LIBRARIES})
add_dependencies(fiona_concurrent_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSControlVoiceSpark
add_executable(fiona_controlvoice_client src/fiona_controlvoice_client.cpp)
target_link_libraries(fiona_controlvoice_client ${catkin_LIBRARIES})
add_dependencies(fiona_controlvoice_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
#Client for ROSAsyncFatalErrorHandlerSpark
add_executable(fiona_errorhandler_client src/fiona_errorhandler_client.cpp)
target_link_libraries(fiona_errorhandler_client ${catkin_LIBRARIES})
add_dependencies(fiona_errorhandler_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSEyesSpark
add_executable(fiona_eyes_client src/fiona_eyes_client.cpp)
target_link_libraries(fiona_eyes_client ${catkin_LIBRARIES})
add_dependencies(fiona_eyes_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSFaceExpressionSpark
add_executable(fiona_faceexpression_client src/fiona_faceexpression_client.cpp)
target_link_libraries(fiona_faceexpression_client ${catkin_LIBRARIES})
add_dependencies(fiona_faceexpression_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSDetectedFacePositionConsumerSpark
add_executable(fiona_faceposition_client src/fiona_faceposition_client.cpp)
target_link_libraries(fiona_faceposition_client ${catkin_LIBRARIES})
add_dependencies(fiona_faceposition_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSFrameEventSubscriberSpark
add_executable(fiona_frame_client src/fiona_frame_client.cpp)
target_link_libraries(fiona_frame_client ${catkin_LIBRARIES})
add_dependencies(fiona_frame_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSNeckSpark
add_executable(fiona_neck_client src/fiona_neck_client.cpp)
target_link_libraries(fiona_neck_client ${catkin_LIBRARIES})
add_dependencies(fiona_neck_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSRenderizableSpark
add_executable(fiona_render_client src/fiona_render_client.cpp)
target_link_libraries(fiona_render_client ${catkin_LIBRARIES})
add_dependencies(fiona_render_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSThreadProcSpark
add_executable(fiona_threadproc_client src/fiona_threadproc_client.cpp)
target_link_libraries(fiona_threadproc_client ${catkin_LIBRARIES})
add_dependencies(fiona_threadproc_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Cient for ROSVoiceSpark
add_executable(fiona_voice_client src/fiona_voice_client.cpp)
target_link_libraries(fiona_voice_client ${catkin_LIBRARIES})
add_dependencies(fiona_voice_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSWindowSpark/ROSWindowSpark
add_executable(fiona_window_client src/fiona_window_client.cpp)
target_link_libraries(fiona_window_client ${catkin_LIBRARIES})
add_dependencies(fiona_window_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
# Client for ROSWindowSpark/ROSGetColorDepthSpark
add_executable(fiona_windowcolordepth_client src/fiona_windowcolordepth_client.cpp)
target_link_libraries(fiona_windowcolordepth_client ${catkin_LIBRARIES})
add_dependencies(fiona_windowcolordepth_client ${${PROJECT_NAME}_EXPORTED_TARGETS})

### Build servers (C++ version of the sparks) for rostest ###
add_executable(fiona_animation_server src/fiona_animation_server.cpp)
target_link_libraries(fiona_animation_server ${catkin_LIBRARIES})
add_dependencies(fiona_animation_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_application_server src/fiona_application_server.cpp)
target_link_libraries(fiona_application_server ${catkin_LIBRARIES})
add_dependencies(fiona_application_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_audiobuffer_server src/fiona_audiobuffer_server.cpp)
target_link_libraries(fiona_audiobuffer_server ${catkin_LIBRARIES})
add_dependencies(fiona_audiobuffer_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_audiosize_server src/fiona_audiosize_server.cpp)
target_link_libraries(fiona_audiosize_server ${catkin_LIBRARIES})
add_dependencies(fiona_audiosize_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_cameraparameters_server src/fiona_cameraparameters_server.cpp)
target_link_libraries(fiona_cameraparameters_server ${catkin_LIBRARIES})
add_dependencies(fiona_cameraparameters_server ${${PROJECT_NAME}_EXPORTED_TARGETS})
