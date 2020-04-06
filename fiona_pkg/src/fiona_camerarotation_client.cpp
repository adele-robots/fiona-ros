#include "ros/ros.h"
#include "fiona_pkg/CameraRotation_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_camerarotation_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::CameraRotation_srv>("fiona_service");
  	fiona_pkg::CameraRotation_srv srv;
	srv.request.x = atof(argv[1]); 
	srv.request.y = atof(argv[2]);
	srv.request.z = atof(argv[3]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.camera_rotation?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


