#include "ros/ros.h"
#include "fiona_pkg/DetectedFacePositionConsumer_srv.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_faceposition_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::DetectedFacePositionConsumer_srv>("fiona_service");
  	fiona_pkg::DetectedFacePositionConsumer_srv srv;
  	srv.request.isFaceDetected = atoll(argv[1]);
	srv.request.x = atof(argv[2]);
	srv.request.y = atof(argv[3]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.face_detected?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


