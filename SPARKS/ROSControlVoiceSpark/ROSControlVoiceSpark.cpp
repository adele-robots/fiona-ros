#include "ROSControlVoiceSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSControlVoiceSpark"))
                return new ROSControlVoiceSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSControlVoiceSpark component.

void ROSControlVoiceSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "control_voice";
        if (node_name_empty) node_name = "control_voice";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSControlVoiceSpark component.

void ROSControlVoiceSpark::quit(void) {
}

void ROSControlVoiceSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}

