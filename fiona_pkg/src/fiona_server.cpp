#include "ros/ros.h"
#include "fiona_srv.h"
#include <cstring>

bool callbackROS(fiona_pkg::fiona_srv::Request  &req, fiona_pkg::fiona_srv::Response &res)
{
        if (strcmp((std::string)req.requestFromROS, "animation")){
		res.responseFromFIONA = "you wrote animation";
        }

  	return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fiona_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  ROS_INFO("fiona_service ready");
  ros::spin();

  return 0;
}
