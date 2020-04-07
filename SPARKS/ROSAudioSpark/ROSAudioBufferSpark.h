#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "AudioBuffer_srv.h"

#include "Component.h"
#include "IAudioQueue.h"

#include <stdlib.h>

class ROSAudioBufferSpark:
	public Component
{
public:
	ROSAudioBufferSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IAudioQueue *myAudioQueue;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IAudioQueue>(&myAudioQueue);
	};

};

bool callbackROS(fiona_pkg::AudioBuffer_srv::Request  &req, fiona_pkg::AudioBuffer_srv::Response &res)
{
	res.audiobuffer = false;
	IAudioQueue *myAudioQueue;
	if (!strcmp(req.selection.c_str(), "queue"))
	{
        	myAudioQueue->queueAudioBuffer((char*)req.buffer.c_str(), req.size);
		res.audiobuffer = true;
	}
	if (!strcmp(req.selection.c_str(), "dequeue"))
        {
                myAudioQueue->dequeueAudioBuffer((char*)req.buffer.c_str(), req.size);
                res.audiobuffer = true;
        }
	else
		res.audiobuffer = false;

        return true;
}

#endif
