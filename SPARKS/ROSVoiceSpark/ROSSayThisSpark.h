#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "VoiceSay_srv.h"

#include "Component.h"
#include "IVoice.h"

#include <stdlib.h>

class ROSSayThisSpark:
	public Component
{
public:
	ROSSayThisSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IVoice *myVoice;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IVoice>(&myVoice);
	};

};

bool callbackROS(fiona_pkg::VoiceSay_srv::Request  &req, fiona_pkg::VoiceSay_srv::Response &res)
{
        IVoice *myVoice;
	myVoice->sayThis((char*)req.prompt.c_str());
	res.voice_say = true;
        return true;
}

#endif
