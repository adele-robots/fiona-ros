#include <ros/ros.h>
#include <fiona-ros/fiona_pkg/FaceExpression_srv.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc , char **argv) {
	ros::init(argc, argv, "fiona_faceexpression_client");
  	ros::NodeHandle n;
	
	ros::ServiceClient client = n.serviceClient<fiona_pkg::FaceExpression_srv>("fiona_service");
  	fiona_pkg::FaceExpression_srv srv;
  	srv.request.expressionName.assign(argv[1]);
	srv.request.intensity = atof(argv[2]);

  	if (client.call(srv))
  	{
		 ROS_INFO("Response: %s", srv.response.face_expression?"true":"false");
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}


