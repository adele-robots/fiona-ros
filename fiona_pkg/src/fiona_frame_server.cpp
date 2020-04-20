#include <ros/ros.h>
#include <fiona_pkg/FrameEventSubscriber_srv.h>
#include <cstring>


class IFrameEventSubscriber {
public:
	virtual void notifyFrameEvent() = 0;
};


class DFrameEventSubscriber: public IFrameEventSubscriber
{ 
public: 
	void notifyFrameEvent(){}
}; 


bool callbackROS(fiona_pkg::FrameEventSubscriber_srv::Request  &req, fiona_pkg::FrameEventSubscriber_srv::Response &res)
{
        DFrameEventSubscriber myFrameEventSubscriber;
        myFrameEventSubscriber.notifyFrameEvent();
        res.frame_subscriber = true;
        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_frame";
        if (node_name_empty) node_name = "server_frame";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
