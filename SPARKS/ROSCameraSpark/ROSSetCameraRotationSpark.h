#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "CameraRotation_srv.h"

//#include "ScriptingGeneral.h"

#include "Component.h"
#include "ICamera.h"

//#include <v8.h>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
//using namespace v8;

class ROSSetCameraRotationSpark:
	public Component
{
public:
	ROSSetCameraRotationSpark(
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

bool callbackROS(fiona_pkg::CameraRotation_srv::Request  &req, fiona_pkg::CameraRotation_srv::Response &res)
{
	ICamera *myCamera;
        myCamera->setCameraRotation(req.x, req.y, req.z);
	res.camera_rotation = true;
        return true;
}

#endif
