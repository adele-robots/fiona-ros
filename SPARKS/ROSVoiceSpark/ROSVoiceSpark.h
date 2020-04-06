#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "VoiceSay_srv.h"

#include "Component.h"
#include "IVoice.h"

#include <stdlib.h>

class ROSVoiceSpark:
	public Component
{
public:
	ROSVoiceSpark(
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
	if (!strcmp(req.select.c_str(), "say"))
	{	
		myVoice->sayThis((char*)req.prompt.c_str());
		res.voice_say = true;
        }
	if (!strcmp(req.select.c_str(), "stop"))
        {       
                myVoice->stopSpeech();
		res.voice_say = true;
        }
	if (!strcmp(req.select.c_str(), "wait"))
        {       
                myVoice->waitEndOfSpeech();
                res.voice_say = true;
        }
	else
                res.voice_say = false;
	
	return true;
}

#endif
