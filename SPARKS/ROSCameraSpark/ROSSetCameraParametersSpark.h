#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "CameraParameters_srv.h"

#include "Component.h"
#include "ICamera.h"

#include <stdlib.h>

class ROSSetCameraParametersSpark:
	public Component
{
public:
	ROSSetCameraParametersSpark(
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

bool callbackROS(fiona_pkg::CameraParameters_srv::Request  &req, fiona_pkg::CameraParameters_srv::Response &res)
{
	ICamera *myCamera;
	if ((long int)req.IsOrtho == (long int)1)
	{
		myCamera->setCameraParameters(true, (float)req.VisionAngle, (float)req.nearClippingPlane, (float)req.FarClippingPlane);
		res.camera_parameters = true;
        	return true;
	}

	if ((long int)req.IsOrtho == 0)
	{
        	myCamera->setCameraParameters(false, (float)req.VisionAngle, (float)req.nearClippingPlane, (float)req.FarClippingPlane);
		res.camera_parameters = true;
        	return true;
	}
	
	else
	{
		res.camera_parameters = false;
        	return true;
	}
}


#endif
