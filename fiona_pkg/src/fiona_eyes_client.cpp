#include <ros/ros.h>
#include <fiona_pkg/Eyes_srv.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_eyes_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::Eyes_srv>("fiona_service");
  	fiona_pkg::Eyes_srv srv;
	srv.request.pan = atof(argv[1]);
	srv.request.tilt = atof(argv[2]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.eyes?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


