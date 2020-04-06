#include "ros/ros.h"
#include "fiona_pkg/WindowColorDepth_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_windowcolordepth_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::WindowColorDepth_srv>("fiona_service");
  	fiona_pkg::WindowColorDepth_srv srv;
  	srv.request.void_request.assign(argv[1]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.window_colordepth?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


