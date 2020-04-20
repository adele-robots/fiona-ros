# ROSTEST
Steps followed for testing services:

1. Create ROS-node equivalents in fiona_pkg/src for ROS-Sparks servers of SPARKS folder, e.g., fiona_animation_server.cpp.

2. Create tests folder inside fiona_pkg.

3. Write  a rostest and a launch file for each service, e.g., test_animation.cpp adn test_animation.launch.
   
   On C++ file, we write the code of the client-node and test it against the server node created on step 1.
   
   On launch file, we launch the server node and its test node.

4. Add this lines to package.xml:

    `<build_depend>rostest</build_depend>`
    
    `<build_export_depend>rostest</build_export_depend>`
    
    `<exec_depend>rostest</exec_depend>`

5. Add this lines for each test to CMakeFiles.txt:
    
    `find_package(rostest REQUIRED)`
    
    `add_rostest_gtest(test_animation tests/test_animation.launch tests/test_animation.cpp)`
    
    `target_link_libraries(test_animation ${catkin_LIBRARIES})`
    
    `add_dependencies(test_animation fiona_animation_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})`
    
    `add_executable(fiona_animation_server src/fiona_animation_server.cpp)`
    
    `target_link_libraries(fiona_animation_server ${catkin_LIBRARIES})`
    
    `add_dependencies(fiona_animation_server ${${PROJECT_NAME}_EXPORTED_TARGETS})`

6. `cd /your_path/catkin_ws`

7. `catkin_make`

8. `cd /your_path/catkin_ws/build`

9. `make run_tests`

# CONTINUOUS INTEGRATION
We have uses Travis CI to build and test this project and all the previous tests. So, with each git push, travis would build the project and test it.
