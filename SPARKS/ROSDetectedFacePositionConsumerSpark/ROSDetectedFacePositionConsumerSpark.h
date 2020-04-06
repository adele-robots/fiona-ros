#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "DetectedFacePositionConsumer_srv.h"

#include "Component.h"
#include "IDetectedFacePositionConsumer.h"

#include <stdlib.h>

class ROSDetectedFacePositionConsumerSpark:
	public Component
{
public:
	ROSDetectedFacePositionConsumerSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IDetectedFacePositionConsumer *myDetectedFacePositionConsumer;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IDetectedFacePositionConsumer>(&myDetectedFacePositionConsumer);
	};

};

bool callbackROS(fiona_pkg::DetectedFacePositionConsumer_srv::Request  &req, fiona_pkg::DetectedFacePositionConsumer_srv::Response &res)
{
	IDetectedFacePositionConsumer *myDetectedFacePositionConsumer;
	if (req.isFaceDetected == 1)
        	myDetectedFacePositionConsumer->consumeDetectedFacePosition(true, req.x, req.y);
	else
		myDetectedFacePositionConsumer->consumeDetectedFacePosition(false, req.x, req.y);

	res.face_detected = true;
        return true;
}

#endif
