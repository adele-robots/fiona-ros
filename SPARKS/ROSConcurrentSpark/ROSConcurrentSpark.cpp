#include "ROSConcurrentSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSConcurrentSpark"))
                return new ROSConcurrentSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSConcurrentSpark component.

void ROSConcurrentSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "concurrent";
        if (node_name_empty) node_name = "concurrent";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSConcurrentSpark component.

void ROSConcurrentSpark::quit(void) {
}

void ROSConcurrentSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}

