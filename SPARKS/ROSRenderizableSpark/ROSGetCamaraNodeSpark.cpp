#include "ROSRenderSpark.h"

#ifdef _WIN32
#else
extern "C"
Component *createComponent(char *componentInstanceName, char *componentType, ComponentSystem *componentSystem)
{
        if (!strcmp(componentType, "ROSGetCamaraNodeSpark"))
                return new ROSGetCamaraNodeSpark(componentInstanceName,componentSystem);
        else
                return NULL;
}
#endif

// Initializes the ROSGetCamaraNodeSpark component.

void ROSGetCamaraNodeSpark::init(void){
	ros::init(argc, argv, "fiona_server");
  	ros::NodeHandle n;
}

/// Uninitializes the ROSGetCamaraNodeSpark component.

void ROSGetCamaraNodeSpark::quit(void) {
}

void ROSGetCamaraNodeSpark::process(){
	ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
  	ros::spin();
}


bool callbackROS(fiona_pkg::Renderizable_srv::Request  &req, fiona_pkg::Renderizable_srv::Response &res)
{
	res.renderizable = myRenderizable->getCamaraNode();

  	return true;
}

