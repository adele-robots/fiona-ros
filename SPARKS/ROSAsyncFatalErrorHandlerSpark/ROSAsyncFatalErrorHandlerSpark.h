#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "AsyncFatalErrorHandler_srv.h"

#include "Component.h"
#include "IAsyncFatalErrorHandler.h"

#include <stdlib.h>

class ROSAsyncFatalErrorHandlerSpark:
	public Component
{
public:
	ROSAsyncFatalErrorHandlerSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IAsyncFatalErrorHandler *myAsyncFatalErrorHandler;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IAsyncFatalErrorHandler>(&myAsyncFatalErrorHandler);
	};

};

bool callbackROS(fiona_pkg::AsyncFatalErrorHandler_srv::Request  &req, fiona_pkg::AsyncFatalErrorHandler_srv::Response &res)
{
	IAsyncFatalErrorHandler *myAsyncFatalErrorHandler;
        myAsyncFatalErrorHandler->handleError((char*)req.msg.c_str());
	res.errorhandler = true ;

        return true;
}


#endif
