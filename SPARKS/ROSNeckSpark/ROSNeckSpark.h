#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Neck_srv.h"

#include "Component.h"
#include "INeck.h"

#include <stdlib.h>

class ROSNeckSpark:
	public Component
{
public:
	ROSNeckSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	INeck *myNeck;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<INeck>(&myNeck);
	};

};

bool callbackROS(fiona_pkg::Neck_srv::Request  &req, fiona_pkg::Neck_srv::Response &res)
{
	INeck *myNeck;
        myNeck->rotateHead(req.pan, req.tilt);
	res.neck = true;
        return true;
}

#endif
