#include "ROSRenderSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSRenderSpark"))
                return new ROSRenderSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSRenderSpark component.

void ROSRenderSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "fiona_service";
        if (node_name_empty) node_name = "";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSRenderSpark component.

void ROSRenderSpark::quit(void) {
}

void ROSRenderSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


