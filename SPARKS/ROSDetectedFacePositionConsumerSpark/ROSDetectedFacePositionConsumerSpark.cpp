#include "ROSDetectedFacePositionConsumerSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSDetectedFacePositionConsumerSpark"))
                return new ROSDetectedFacePositionConsumerSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSDetectedFacePositionConsumerSpark component.

void ROSDetectedFacePositionConsumerSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "detect_face"
        if (node_name_empty) node_name = "detect_face";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSDetectedFacePositionConsumerSpark component.

void ROSDetectedFacePositionConsumerSpark::quit(void) {
}

void ROSDetectedFacePositionConsumerSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


