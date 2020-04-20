#ifndef __ROSTalkerSpark_H
#define __ROSTalkerSpark_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include "Component.h"
#include <stdlib.h>

class ROSTalkerSpark:
	public Component,
{
public:
	ROSTalkerSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}


protected:
	void initializeRequiredInterfaces(){
	};

public:
	void init(void);
        void quit(void);
        void process(void);
};

#endif
