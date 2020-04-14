#include "ROSGetStoredAudioSizeSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSGetStoredAudioSizeSpark"))
                return new ROSGetStoredAudioSizeSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSGetStoredAudioSizeSpark component.

void ROSGetStoredAudioSizeSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "audio_size";
        if (node_name_empty) node_name = "audio_size";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSGetStoredAudioSizeSpark component.

void ROSGetStoredAudioSizeSpark::quit(void) {
}

void ROSGetStoredAudioSizeSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


