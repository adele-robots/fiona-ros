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

add_rostest_gtest(test_cameraposition tests/test_cameraposition.launch tests/test_cameraposition.cpp)
target_link_libraries(test_cameraposition ${catkin_LIBRARIES})
add_dependencies(test_cameraposition fiona_cameraposition_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_camerarotation tests/test_camerarotation.launch tests/test_camerarotation.cpp)
target_link_libraries(test_camerarotation ${catkin_LIBRARIES})
add_dependencies(test_camerarotation fiona_camerarotation_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_concurrent tests/test_concurrent.launch tests/test_concurrent.cpp)
target_link_libraries(test_concurrent ${catkin_LIBRARIES})
add_dependencies(test_concurrent fiona_concurrent_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_controlvoice tests/test_controlvoice.launch tests/test_controlvoice.cpp)
target_link_libraries(test_controlvoice ${catkin_LIBRARIES})
add_dependencies(test_controlvoice fiona_controlvoice_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_errorhandler tests/test_errorhandler.launch tests/test_errorhandler.cpp)
target_link_libraries(test_errorhandler ${catkin_LIBRARIES})
add_dependencies(test_errorhandler fiona_errorhandler_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_eyes tests/test_eyes.launch tests/test_eyes.cpp)
target_link_libraries(test_eyes ${catkin_LIBRARIES})
add_dependencies(test_eyes fiona_eyes_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_faceexpression tests/test_faceexpression.launch tests/test_faceexpression.cpp)
target_link_libraries(test_faceexpression ${catkin_LIBRARIES})
add_dependencies(test_faceexpression fiona_faceexpression_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_faceposition tests/test_faceposition.launch tests/test_faceposition.cpp)
target_link_libraries(test_faceposition ${catkin_LIBRARIES})
add_dependencies(test_faceposition fiona_faceposition_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_frame tests/test_frame.launch tests/test_frame.cpp)
target_link_libraries(test_frame ${catkin_LIBRARIES})
add_dependencies(test_frame fiona_frame_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_neck tests/test_neck.launch tests/test_neck.cpp)
target_link_libraries(test_neck ${catkin_LIBRARIES})
add_dependencies(test_neck fiona_neck_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_rostest_gtest(test_render tests/test_render.launch tests/test_render.cpp)
target_link_libraries(test_render ${catkin_LIBRARIES})
add_dependencies(test_render fiona_render_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

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

add_executable(fiona_cameraposition_server src/fiona_cameraposition_server.cpp)
target_link_libraries(fiona_cameraposition_server ${catkin_LIBRARIES})
add_dependencies(fiona_cameraposition_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_camerarotation_server src/fiona_camerarotation_server.cpp)
target_link_libraries(fiona_camerarotation_server ${catkin_LIBRARIES})
add_dependencies(fiona_camerarotation_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_concurrent_server src/fiona_concurrent_server.cpp)
target_link_libraries(fiona_concurrent_server ${catkin_LIBRARIES})
add_dependencies(fiona_concurrent_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_controlvoice_server src/fiona_controlvoice_server.cpp)
target_link_libraries(fiona_controlvoice_server ${catkin_LIBRARIES})
add_dependencies(fiona_controlvoice_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_errorhandler_server src/fiona_errorhandler_server.cpp)
target_link_libraries(fiona_errorhandler_server ${catkin_LIBRARIES})
add_dependencies(fiona_errorhandler_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_eyes_server src/fiona_eyes_server.cpp)
target_link_libraries(fiona_eyes_server ${catkin_LIBRARIES})
add_dependencies(fiona_eyes_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_faceexpression_server src/fiona_faceexpression_server.cpp)
target_link_libraries(fiona_faceexpression_server ${catkin_LIBRARIES})
add_dependencies(fiona_faceexpression_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_faceposition_server src/fiona_faceposition_server.cpp)
target_link_libraries(fiona_faceposition_server ${catkin_LIBRARIES})
add_dependencies(fiona_faceposition_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_frame_server src/fiona_frame_server.cpp)
target_link_libraries(fiona_frame_server ${catkin_LIBRARIES})
add_dependencies(fiona_frame_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_neck_server src/fiona_neck_server.cpp)
target_link_libraries(fiona_neck_server ${catkin_LIBRARIES})
add_dependencies(fiona_neck_server ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(fiona_render_server src/fiona_render_server.cpp)
target_link_libraries(fiona_render_server ${catkin_LIBRARIES})
add_dependencies(fiona_render_server ${${PROJECT_NAME}_EXPORTED_TARGETS})
