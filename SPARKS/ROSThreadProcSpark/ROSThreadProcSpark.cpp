#include "ROSThreadProcSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSThreadProcSpark"))
                return new ROSThreadProcSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSThreadProcSpark component.

void ROSThreadProcSpark::init(void){
	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "thread_proc";
        if (node_name_empty) node_name = "thread_poc";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSThreadProcSpark component.

void ROSThreadProcSpark::quit(void) {
}

void ROSThreadProcSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


