#ifndef __ROSAnimationSpark_H
#define __ROSAnimationSpark_H

#include "ros/ros.h"
#include "Animation_srv.h"

#include "Component.h"
#include "IAnimation.h"

#include <stdlib.h>

class ROSAnimationSpark:
	public Component,
	public IAnimation
{
public:
	ROSAnimationSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}


protected:
	IAnimation *myAnimation;
	void initializeRequiredInterfaces(){
		requestRequiredInterface<IAnimation>(&myAnimation);
	};

public:
	void init(void);
        void quit(void);
        void process(void);
	//IAnimation implementation
        void  playAnimation(char *animationFileName);
};

bool callbackROS(fiona_pkg::Animation_srv::Request  &req, fiona_pkg::Animation_srv::Response &res)
{
	IAnimation *myAnimation;
        myAnimation->playAnimation((char*)req.avatarFilename.c_str());
	res.animation = true;
        return true;
}

#endif
