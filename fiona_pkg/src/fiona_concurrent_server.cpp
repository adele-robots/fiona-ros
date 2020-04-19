#include <ros/ros.h>
#include <fiona_pkg/Concurrent_srv.h>
#include <cstring>

class IConcurrent {
public:
	virtual void start() = 0;
        virtual void stop() = 0;
};


class DConcurrent: public IAnimation
{ 
public: 
    	void start(){}
	void stop(){}
}; 

bool callbackROS(fiona_pkg::Concurrent_srv::Request  &req, fiona_pkg::Concurrent_srv::Response &res)
{
        DConcurrent myConcurrent;
        if (!strcmp(req.start_stop.c_str(), "start")
        {
                myConcurrent.start();
                res.concurrent = true;
		return true;
        }

        if (!strcmp(req.start_stop.c_str(), "stop")
        {
                myConcurrent.stop();
                res.concurrent = true;
		return true;
        }

        else
                res.concurrent = false;
		return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_concurrent";
        if (node_name_empty) node_name = "server_concurrent";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
