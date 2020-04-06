#include "ros/ros.h"
#include "fiona_pkg/AudioBuffer_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_audiobuffer_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::AudioBuffer_srv>("fiona_service");
  	fiona_pkg::AudioBuffer_srv srv;
  	srv.request.buffer.assign(argv[1]);
	srv.request.size = atoll(argv[2]);
  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.audiobuffer?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


