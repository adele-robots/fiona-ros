#include "ROSSetCameraRotationSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSSetCameraRotationSpark"))
                return new ROSSetCameraRotationSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSSetCameraRotationSpark component.

void ROSSetCameraRotationSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "cam_rotation";
        if (node_name_empty) node_name = "cam_rotation";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSSetCameraRotationSpark component.

void ROSSetCameraRotationSpark::quit(void) {
}

void ROSSetCameraRotationSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


