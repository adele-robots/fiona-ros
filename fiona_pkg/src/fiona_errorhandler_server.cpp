#include <ros/ros.h>
#include <fiona_pkg/AsyncFatalErrorHandler_srv.h>
#include <cstring>

class IErrorHandler {
public:
	virtual void handleError(char *msg) = 0;
};


class DErrorHandler: public IErrorHandler
{ 
public: 
        void handleError(char *msg){}
}; 

bool callbackROS(fiona_pkg::AsyncFatalErrorHandler_srv::Request  &req, fiona_pkg::AsyncFatalErrorHandler_srv::Response &res)
{
        DErrorHandler myErrorHandler;
        myErrorHandler.handleError((char*)req.msg.c_str());
        res.errorhandler = true ;

        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_errorhandler";
        if (node_name_empty) node_name = "server_errorhandler";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
