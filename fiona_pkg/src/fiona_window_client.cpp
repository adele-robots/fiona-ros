#include <ros/ros.h>
#include <fiona_pkg/Window_srv.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_window_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::Window_srv>("fiona_service");
  	fiona_pkg::Window_srv srv;
  	srv.request.select.assign(argv[1]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.window?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


