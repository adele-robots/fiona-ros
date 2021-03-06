#include "ROSAsyncFatalErrorHandlerSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSAsyncFatalErrorHandlerSpark"))
                return new ROSAsyncFatalErrorHandlerSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSAsyncFatalErrorHandlerSpark component.

void ROSAsyncFatalErrorHandlerSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "error_handler";
        if (node_name_empty) node_name = "error_handler";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSAsyncFatalErrorHandlerSpark component.

void ROSAsyncFatalErrorHandlerSpark::quit(void) {
}

void ROSAsyncFatalErrorHandlerSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}

