#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "FaceExpression_srv.h"

#include "Component.h"
#include "IFaceExpression.h"

#include <stdlib.h>

class ROSFaceExpressionSpark:
	public Component
{
public:
	ROSFaceExpressionSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IFaceExpression *myFaceExpression;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IFaceExpression>(&myFaceExpression);
	};

};

bool callbackROS(fiona_pkg::FaceExpression_srv::Request  &req, fiona_pkg::FaceExpression_srv::Response &res)
{
        IFaceExpression *myFaceExpression;
	myFaceExpression->setFaceExpression((char*)req.expressionName.c_str(), (float)req.intensity);
	res.face_expression = true;
        return true;
}

#endif
