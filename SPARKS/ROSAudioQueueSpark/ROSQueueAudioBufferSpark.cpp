#include "ROSQueueAudioBufferSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSQueueAudioBufferSpark"))
                return new ROSQueueAudioBufferSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSQueueAudioBufferSpark component.

void ROSQueueAudioBufferSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "fiona_service";
        if (node_name_empty) node_name = "";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSQueueAudioBufferSpark component.

void ROSQueueAudioBufferSpark::quit(void) {
}

void ROSQueueAudioBufferSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}
