#include "ROSMakeCurrentopenGlThreadSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSMakeCurrentopenGlThreadSpark"))
                return new ROSMakeCurrentopenGlThreadSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSMakeCurrentopenGlThreadSpark component.

void ROSMakeCurrentopenGlThreadSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "fiona_service";
        if (node_name_empty) node_name = "";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSMakeCurrentopenGlThreadSpark component.

void ROSMakeCurrentopenGlThreadSpark::quit(void) {
}

void ROSMakeCurrentopenGlThreadSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


