#include "ros/ros.h"
#include "fiona_pkg/AudioBuffer_srv.h"
#include <cstring>

bool callbackROS(fiona_pkg::AudioBuffer_srv::Request  &req, fiona_pkg::AudioBuffer_srv::Response &res)
{
        if (!strcmp(req.buffer.c_str(), "audio") && req.size == 2){
		res.audiobuffer = true;
        }
	else
		res.audiobuffer = false;

  	return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fiona_audiobuffer_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  ROS_INFO("fiona_service ready");
  ros::spin();

  return 0;
}
