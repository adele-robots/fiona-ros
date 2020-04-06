#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Renderizable_srv.h"

#include "Component.h"
#include "IRenderizable.h"

#include <stdlib.h>

class ROSRenderSpark:
	public Component
{
public:
	ROSRenderSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IRenderizable *myRenderizable;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IRenderizable>(&myRenderizable);
	};

};

bool callbackROS(fiona_pkg::Renderizable_srv::Request  &req, fiona_pkg::Renderizable_srv::Response &res)
{
	IRenderizable *myRenderizable;
        myRenderizable->render();
	res.render = true;
        return true;
}


#endif
