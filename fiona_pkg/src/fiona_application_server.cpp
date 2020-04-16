#include <ros/ros.h>
#include <fiona_pkg/Application_srv.h>
#include <cstring>

#ifndef __I_APPLICATION_H
#define __I_APPLICATION_H

class IApplication {
public:
        virtual void run() = 0;
};

#endif

class DApplication: public IApplication
{ 
public: 
    void  run() { std::cout << "run() called"; } 
}; 


bool callbackROS(fiona_pkg::Application_srv::Request  &req, fiona_pkg::Application_srv::Response &res)
{
        res.application = false;
        DApplication myApplication;
        myApplication.run();
        res.application = true;

        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_application";
        if (node_name_empty) node_name = "server_application";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
