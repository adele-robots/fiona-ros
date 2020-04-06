#ifndef __ROSSpark_H
#define __ROSSpark_H

#include "ros/ros.h"
#include "ControlVoice_srv.h"

//#include "ScriptingGeneral.h"

#include "Component.h"
#include "IControlVoice.h"

//#include <v8.h>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
//using namespace v8;

class ROSStartVoiceSpark:
	public Component
{
public:
	ROSStartVoiceSpark(
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
        myControlVoice->startVoice();
        res.control_voice = true;
        return true;
}

#endif
