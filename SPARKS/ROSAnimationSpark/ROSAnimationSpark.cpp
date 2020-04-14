#include "ROSAnimationSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSAnimationSpark"))
                return new ROSAnimationSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSAnimationSpark component.

void ROSAnimationSpark::init(void){
	bool remap_name = true;
  	bool node_name_empty = true;
  	std::map<std::string, std::string> remaps;
  	if (remap_name) remaps["__name"] = "fiona_service";
  	std::string node_name = "animation";
  	if (node_name_empty) node_name = "animation";
  	ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSAnimationSpark component.

void ROSAnimationSpark::quit(void) {
}

void ROSAnimationSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


