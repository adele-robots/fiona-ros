#include "ROSApplicationSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSApplicationSpark"))
                return new ROSApplicationSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSApplicationSpark component.

void ROSApplicationSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "application";
        if (node_name_empty) node_name = "application";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSApplicationSpark component.

void ROSApplicationSpark::quit(void) {
}

void ROSApplicationSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


