#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "WindowColorDepth_srv.h"

#include "Component.h"
#include "IWindow.h"

#include <stdlib.h>

class ROSGetColorDepthSpark:
	public Component
{
public:
	ROSGetColorDepthSpark(
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

bool callbackROS(fiona_pkg::WindowColorDepth_srv::Request  &req, fiona_pkg::WindowColorDepth_srv::Response &res)
{
        IWindow *myWindow;
        res.window_colordepth = myWindow->getColorDepth();

        return true;
}


#endif
