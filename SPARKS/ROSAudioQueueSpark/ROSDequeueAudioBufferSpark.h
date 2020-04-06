#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "AudioBuffer_srv.h"

#include "Component.h"
#include "IAudioQueue.h"

#include <stdlib.h>

class ROSDequeueAudioBufferSpark:
	public Component
{
public:
	ROSDequeueAudioBufferSpark(
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
	IAudioQueue *myAudioQueue;
        myAudioQueue->dequeueAudioBuffer((char*)req.buffer.c_str(), req.size);
	res.audiobuffer = true;
        return true;
}

#endif
