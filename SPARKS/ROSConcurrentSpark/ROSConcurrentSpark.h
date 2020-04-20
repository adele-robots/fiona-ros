#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Concurrent_srv.h"

#include "Component.h"
#include "IConcurrent.h"

#include <stdlib.h>

class ROSConcurrentSpark:
	public Component
{
public:
	ROSConcurrentSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IConcurrent *myConcurrent;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IConcurrent>(&myConcurrent);
	};

};

bool callbackROS(fiona_pkg::Concurrent_srv::Request  &req, fiona_pkg::Concurrent_srv::Response &res)
{
	IConcurrent *myConcurrent;
	if (!strcmp(req.start_stop.c_str(), "start"))
	{
        	myConcurrent->start();
		res.concurrent = true;
		return true;
        }
	
	if (!strcmp(req.start_stop.c_str(), "stop"))
        {
                myConcurrent->stop();
                res.concurrent = true;
		return true;
        }

	else
	{
		res.concurrent = false;
		return true;
	}
}

#endif
