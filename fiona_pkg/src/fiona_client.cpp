// Include the ROS C++ APIs
#include "ros/ros.h"
#include "fiona_pkg/fiona_srv.h"
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h> //for system()

using namespace std;

int main (int argc , char **argv) {
	system("ssh root@192.168.3.46 '/datos/script/script_ros/prueba.sh'");
	ros::init(argc, argv, "fiona_client");

  	ros::NodeHandle n;
	//system("ssh root@192.168.3.46 'bash -s' < /home/blade/catkin_ws/src/fiona_pkg/src/prueba2.sh"); //to start fiona
	ros::ServiceClient client = n.serviceClient<fiona_pkg::fiona_srv>("fiona_service");
  	fiona_pkg::fiona_srv srv;
  	srv.request.requestFromROS = atoll(argv[1]);
  	if (client.call(srv))
  	{
		ROS_INFO("Response: %s", (std::string)srv.response.responseFromFIONA);
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service fiona_service");
    		return 1;
  	}

  	return 0;
}







	/*string shell = "/home/blade/catkin_ws/src/fiona_pkg/src/avatar.sh";
	string runPath = "/home/blade/catkin_ws/src/fiona_pkg/src/Run";
	string sessionID = "";
	string avatarDirectory = "/home/blade/catkin_ws/src/fiona_pkg/src";
	string avatarFilename = "avatar.xml";

	// Announce this program to the ROS master as a "node" called "fiona_node"
	ros::init(argc,argv,"fiona_client");
	
	// Get the handle for node, this handle is required for interactions with system e.g. subscribing to topic.
	ros::NodeHandle n("~");

	// Start the node resource managers (communication, time, etc)
	ros::start();

	// Broadcast a simple log message
	system(shell + " " + runPath + " " + sessionID + " " + avatarDirectory + " " + avatarFilename);
        ROS_INFO_STREAM("Starting fiona node!");

	//Define rate for repeatable operations.
	ros::Rate loop_rate(50);
	while (ros::ok()) { //Check if ROS is working. If ROS master is stopped or there was sent signal to stop the system, ros::ok() returns false.
		ros::spinOnce(); //Process all incoming messages.
		loop_rate.sleep(); //Wait until defined time passes.
	}*/
	
