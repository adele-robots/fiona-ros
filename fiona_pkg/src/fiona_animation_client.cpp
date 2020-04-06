#include "ros/ros.h"
#include "fiona_pkg/Animation_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_animation_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::Animation_srv>("fiona_service");
  	fiona_pkg::Animation_srv srv;
  	srv.request.avatarFilename.assign(argv[1]);
  	if (client.call(srv))
  	{
		 ROS_INFO("Response to animation: %s", srv.response.animation?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


