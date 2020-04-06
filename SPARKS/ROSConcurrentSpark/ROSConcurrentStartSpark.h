#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "Concurrent_srv.h"

#include "Component.h"
#include "IConcurrent.h"

#include <stdlib.h>

class ROSConcurrentStartSpark:
	public Component
{
public:
	ROSConcurrentStartSpark(
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
        myConcurrent->start();
	res.concurrent = true;
        return true;
}

#endif
