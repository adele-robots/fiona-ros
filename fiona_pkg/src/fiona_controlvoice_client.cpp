#include "ros/ros.h"
#include "fiona_pkg/ControlVoice_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_concurrent_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::ControlVoice_srv>("fiona_service");
  	fiona_pkg::ControlVoice_srv srv;
  	srv.request.voice_selection.assign(argv[1]);
  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.control_voice?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


