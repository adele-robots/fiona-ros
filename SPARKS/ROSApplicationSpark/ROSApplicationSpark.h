#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Application_srv.h"

//#include "ScriptingGeneral.h"

#include "Component.h"
#include "IApplication.h"

//#include <v8.h>
#include <string>
#include <map>
#include <stdlib.h>
//using namespace std;
//using namespace v8;

class ROSApplicationSpark:
	public Component
{
public:
	ROSApplicationSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IApplication *myApplication;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IApplication>(&myApplication);
	};

};

bool callbackROS(fiona_pkg::Application_srv::Request  &req, fiona_pkg::Application_srv::Response &res)
{	
	IApplication *myApplication;
        myApplication->run();
	res.application = true;

        return true;
}

#endif
