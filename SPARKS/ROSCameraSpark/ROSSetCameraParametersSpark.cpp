#include "ROSSetCameraParametersSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSSetCameraParametersSpark"))
                return new ROSSetCameraParametersSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSSetCameraParametersSpark component.

void ROSSetCameraParametersSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "cam_parameters";
        if (node_name_empty) node_name = "cam_paramters";
        ros::init(remaps, node_name, (uint32_t)0);  	
}

/// Uninitializes the ROSSetCameraParametersSpark component.

void ROSSetCameraParametersSpark::quit(void) {
}

void ROSSetCameraParametersSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}
