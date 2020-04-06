#include "ros/ros.h"
#include "fiona_pkg/CameraParameters_srv.h"
#include <cstring>

bool callbackROS(fiona_pkg::CameraParameters_srv::Request  &req, fiona_pkg::CameraParameters_srv::Response &res)
{
        if (req.IsOrtho == 1 && req.VisionAngle == 1.2f && req.nearClippingPlane == 2.25f && req.FarClippingPlane == 0.5f){
		res.camera_parameters = true;
        }
	else
		res.camera_parameters = false;

  	return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fiona_cameraparameters_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  ROS_INFO("fiona_service ready");
  ros::spin();

  return 0;
}
