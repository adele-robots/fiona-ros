#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "ThreadProc_srv.h"

//#include "ScriptingGeneral.h"

#include "Component.h"
#include "IThreadProc.h"

//#include <v8.h>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
//using namespace v8;

class ROSThreadProcSpark:
	public Component
{
public:
	ROSThreadProcSpark(
			char *instanceName,
			ComponentSystem *cs
			) : Component(instanceName, cs)
	{}

	void init(void);
	void quit(void);
	void process(void);

protected:
	IThreadProc *myThreadProc;

	void initializeRequiredInterfaces(){
		requestRequiredInterface<IThreadProc>(&myThreadProc);
	};

};

bool callbackROS(fiona_pkg::ThreadProc_srv::Request  &req, fiona_pkg::ThreadProc_srv::Response &res)
{
	IThreadProc *myThreadProc;
        myThreadProc->process();
	res.process = true;
        return true;
}

#endif
