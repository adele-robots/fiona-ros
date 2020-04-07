#include "ros/ros.h"
#include "fiona_pkg/Concurrent_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_concurrent_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::Concurrent_srv>("fiona_service");
  	fiona_pkg::Concurrent_srv srv;
  	srv.request.start_stop.assign(argv[1]);
  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.concurrent?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


