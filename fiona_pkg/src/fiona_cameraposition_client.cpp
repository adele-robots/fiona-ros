#include "ros/ros.h"
#include "fiona_pkg/CameraPosition_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_cameraposition_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::CameraPosition_srv>("fiona_service");
  	fiona_pkg::CameraPosition_srv srv;
	srv.request.x = atof(argv[1]); 
	srv.request.y = atof(argv[2]);
	srv.request.z = atof(argv[3]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.camera_position?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


