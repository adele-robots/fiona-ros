#include <ros/ros.h>
#include <fiona_pkg/Application_srv.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_application_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::Application_srv>("fiona_service");
  	fiona_pkg::Application_srv srv;
  	srv.request.void_request.assign(argv[1]);
  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.application?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


