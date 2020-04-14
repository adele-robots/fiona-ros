#include "ROSFaceExpressionSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSFaceExpressionSpark"))
                return new ROSFaceExpressionSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSFaceExpressionSpark component.

void ROSFaceExpressionSpark::init(void){
  	bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "face_expression";
        if (node_name_empty) node_name = "face_expression";
        ros::init(remaps, node_name, (uint32_t)0);
}

/// Uninitializes the ROSFaceExpressionSpark component.

void ROSFaceExpressionSpark::quit(void) {
}

void ROSFaceExpressionSpark::process(){
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


