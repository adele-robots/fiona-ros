In order to build fiona_pkg on your local machine you need to hace ROS installed. This package has been tested with ROS melodic and kinetic but to get a correct performance with FIONA it is recommendable kinetic.

1. `git clone https://github.com/rachsc/fiona-ros`
2. Copy fiona_pkg to /your_path/catkin_ws/src
3. `source /your_ros_path/your_ros_version/setup.bash`
4. `catkin_make`
5. `roslaunch fiona_pkg fiona_"choose_one"_client args:="your_arguments_if_needed"`
