#include <ros/ros.h>
#include <fiona_pkg/CameraParameters_srv.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_cameraparameters_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::CameraParameters_srv>("fiona_service");
  	fiona_pkg::CameraParameters_srv srv;
  	srv.request.IsOrtho = atoll(argv[1]);
	srv.request.VisionAngle = atof(argv[2]);
	srv.request.nearClippingPlane = atof(argv[3]);
	srv.request.FarClippingPlane = atof(argv[4]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.camera_parameters?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


