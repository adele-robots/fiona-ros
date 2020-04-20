#include <ros/ros.h>
#include <fiona_pkg/ThreadProc_srv.h>
#include <cstring>

class IThreadProc {
public:
	virtual void process() = 0;
};

class DThreadProc: public IThreadProc
{ 
public: 
	void process(){}
}; 

bool callbackROS(fiona_pkg::ThreadProc_srv::Request  &req, fiona_pkg::ThreadProc_srv::Response &res)
{
        DThreadProc myThreadProc;
        myThreadProc.process();
        res.process = true;
        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_threadproc";
        if (node_name_empty) node_name = "server_threadproc";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
