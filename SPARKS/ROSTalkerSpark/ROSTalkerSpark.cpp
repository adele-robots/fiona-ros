#include "ROSTalkerSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSTalkerSpark"))
                return new ROSTalkerSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSTalkerSpark component.

void ROSTalkerSpark::init(void){
	bool remap_name = true;
  	bool node_name_empty = true;
  	std::map<std::string, std::string> remaps;
  	if (remap_name) remaps["__name"] = "fiona_service";
  	std::string node_name = "talker";
  	if (node_name_empty) node_name = "talker";
  	ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSTalkerSpark component.

void ROSTalkerSpark::quit(void) {
}

void ROSTalkerSpark::process(){
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1);
        ros::Rate loop_rate(10);
        std_msgs::String msg;

        std::stringstream ss;
        ss << "Hello ROS, I am FIONA!";
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        while(chatter_pub.getNumSubscribers() == 0)
                loop_rate.sleep();

        while (ros::ok())
        {
                chatter_pub.publish(msg);
                ros::spinOnce();
        }

}


