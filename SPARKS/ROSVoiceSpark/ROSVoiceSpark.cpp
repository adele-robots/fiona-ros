#include "ROSVoiceSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSVoiceSpark"))
                return new ROSVoiceSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSVoiceSpark component.

void ROSVoiceSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "voice";
        if (node_name_empty) node_name = "voice";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSVoiceSpark component.

void ROSVoiceSpark::quit(void) {
}

void ROSVoiceSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


