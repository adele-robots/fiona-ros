#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "FrameEventSubscriber_srv.h"

#include "Component.h"
#include "FrameEventSubscriber.h"

#include <stdlib.h>

class ROSFrameEventSubscriberSpark:
	public Component
{
public:
	ROSFrameEventSubscriberSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	FrameEventSubscriber *myFrameEventSubscriber;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<FrameEventSubscriber>(&myFrameEventSubscriber);
	};

};

bool callbackROS(fiona_pkg::FrameEventSubscriber_srv::Request  &req, fiona_pkg::FrameEventSubscriber_srv::Response &res)
{
	FrameEventSubscriber *myFrameEventSubscriber;
        myFrameEventSubscriber->notifyFrameEvent();
	res.frame_subscriber = true;
        return true;
}


#endif
