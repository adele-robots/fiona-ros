#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Window_srv.h"

#include "Component.h"
#include "IWindow.h"

#include <stdlib.h>

class ROSShowSpark:
	public Component
{
public:
	ROSShowSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IWindow *myWindow;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IWindow>(&myWindow);
	};

};

bool callbackROS(fiona_pkg::Window_srv::Request  &req, fiona_pkg::Window_srv::Response &res)
{
	IWindow *myWindow;
        myWindow->show();
	res.window = true;
        return true;
}

#endif
