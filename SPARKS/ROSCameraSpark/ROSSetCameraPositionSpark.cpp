#include "ROSSetCameraPositionSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSSetCameraPositionSpark"))
                return new ROSSetCameraPositionSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSSetCameraPositionSpark component.

void ROSSetCameraPositionSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "cam_position";
        if (node_name_empty) node_name = "cam_position";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSSetCameraPositionSpark component.

void ROSSetCameraPositionSpark::quit(void) {
}

void ROSSetCameraPositionSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


