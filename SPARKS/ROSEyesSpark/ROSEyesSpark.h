#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Eyes_srv.h"

#include "Component.h"
#include "IEyes.h"

#include <stdlib.h>

class ROSEyesSpark:
	public Component
{
public:
	ROSEyesSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IEyes *myEyes;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IEyes>(&myEyes);
	};

};

bool callbackROS(fiona_pkg::Eyes_srv::Request  &req, fiona_pkg::Eyes_srv::Response &res)
{
	IEyes *myEyes;
        myEyes->rotateEye(req.pan, req.tilt);
	res.eyes = true;
        return true;
}

#endif
