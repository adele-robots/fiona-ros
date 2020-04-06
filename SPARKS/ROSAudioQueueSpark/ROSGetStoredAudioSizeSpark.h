#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "AudioSize_srv.h"

#include "Component.h"
#include "IAudioQueue.h"

#include <stdlib.h>

class ROSGetStoredAudioSizeSpark:
	public Component
{
public:
	ROSGetStoredAudioSizeSpark(
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

bool callbackROS(fiona_pkg::AudioSize_srv::Request  &req, fiona_pkg::AudioSize_srv::Response &res)
{
	IAudioQueue *myAudioQueue;
        res.audiosize = myAudioQueue->getStoredAudioSize();

        return true;
}


#endif
