#include "ROSAudioBufferSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSAudioBufferSpark"))
                return new ROSAudioBufferSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSAudioBufferSpark component.

void ROSAudioBufferSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "audio_buffer";
        if (node_name_empty) node_name = "audio_buffer";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSAudioBufferSpark component.

void ROSAudioBufferSpark::quit(void) {
}

void ROSAudioBufferSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}
