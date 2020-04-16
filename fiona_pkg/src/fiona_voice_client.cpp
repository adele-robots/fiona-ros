#include <ros/ros.h>
#include <fiona_pkg/Voice_srv.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_voice_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::Voice_srv>("fiona_service");
  	fiona_pkg::Voice_srv srv;
  	srv.request.select.assign(argv[1]);
	 srv.request.prompt.assign(argv[2]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.voice_say?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


