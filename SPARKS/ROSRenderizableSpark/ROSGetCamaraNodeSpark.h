#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Renderizable_srv.h"

//#include "ScriptingGeneral.h"

#include "Component.h"
#include "IRenderizable.h"

//#include <v8.h>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
//using namespace v8;

class ROSGetCamaraNodeSpark:
	public Component
{
public:
	ROSGetCamaraNodeSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);
	bool callbackROS(fiona_pkg::Renderizable_srv::Request  &req, fiona_pkg::Renderizable_srv::Response &res);

protected:
	IRenderizable *myRenderizable;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IRenderizable>(&myRenderizable);
	};

};

#endif
