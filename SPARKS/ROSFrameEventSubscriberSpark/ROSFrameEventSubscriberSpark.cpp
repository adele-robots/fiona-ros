#include "ROSFrameEventSubscriberSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSFrameEventSubscriberSpark"))
                return new ROSFrameEventSubscriberSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSFrameEventSubscriberSpark component.

void ROSFrameEventSubscriberSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "frame";
        if (node_name_empty) node_name = "frame";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSFrameEventSubscriberSpark component.

void ROSFrameEventSubscriberSpark::quit(void) {
}

void ROSFrameEventSubscriberSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}



