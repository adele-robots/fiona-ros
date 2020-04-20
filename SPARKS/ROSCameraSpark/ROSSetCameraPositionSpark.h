#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "CameraPosition_srv.h"

#include "Component.h"
#include "ICamera.h"

#include <stdlib.h>

class ROSSetCameraPositionSpark:
	public Component
{
public:
	ROSSetCameraPositionSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	ICamera *myCamera;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<ICamera>(&myCamera);
	};

};

bool callbackROS(fiona_pkg::CameraPosition_srv::Request  &req, fiona_pkg::CameraPosition_srv::Response &res)
{
	ICamera *myCamera;
        myCamera->setCameraPosition((float)req.x, (float)req.y, (float)req.z);
	res.camera_position = true;
        return true;
}


#endif
