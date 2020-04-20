#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "ControlVoice_srv.h"

#include "Component.h"
#include "IControlVoice.h"

#include <stdlib.h>

class ROSControlVoiceSpark:
	public Component
{
public:
	ROSControlVoiceSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IControlVoice *myControlVoice;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IControlVoice>(&myControlVoice);
	};

};

bool callbackROS(fiona_pkg::ControlVoice_srv::Request  &req, fiona_pkg::ControlVoice_srv::Response &res)
{
	IControlVoice *myControlVoice;

	if (!strcmp(req.voice_selection.c_str(), "speaking"))
        {
                myControlVoice->startSpeaking();
        	res.control_voice = true;
		return true;
        }

        if (!strcmp(req.voice_selection.c_str(), "voice"))
        {
		myControlVoice->startVoice();
        	res.control_voice = true;
		return true;
        }

	if (!strcmp(req.voice_selection.c_str(), "nospeaking"))
        {
                myControlVoice->stopSpeaking();
                res.control_voice = true;
		return true;
        }

	else
	{
		res.control_voice = false;
		return true;
	}
}

#endif



