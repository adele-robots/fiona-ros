#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "VoiceWaitStop_srv.h"

#include "Component.h"
#include "IVoice.h"

#include <stdlib.h>

class ROSStopSpeechSpark:
	public Component
{
public:
	ROSStopSpeechSpark(
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

bool callbackROS(fiona_pkg::VoiceWaitStop_srv::Request  &req, fiona_pkg::VoiceWaitStop_srv::Response &res)
{
	IVoice *myVoice;
        myVoice->stopSpeech();
	res.voice_waitstop = true;
        return true;
}


#endif
