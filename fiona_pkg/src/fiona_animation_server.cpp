#include "ros/ros.h"
#include "fiona_pkg/Animation_srv.h"
#include <cstring>

bool callbackROS(fiona_pkg::Animation_srv::Request  &req, fiona_pkg::Animation_srv::Response &res)
{
        if (!strcmp(req.avatarFilename.c_str(), "animation")){
		res.animation = true;
        }
	else
		res.animation = false;

  	return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fiona_animation_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  ROS_INFO("fiona_service ready");
  ros::spin();

  return 0;
}
