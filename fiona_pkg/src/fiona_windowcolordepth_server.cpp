#include <ros/ros.h>
#include <fiona_pkg/WindowColorDepth_srv.h>
#include <cstring>

class IWindowColorDepth {
public:
	virtual int getColorDepth(void) = 0;
};

class DWindowColorDepth: public IWindowColorDepth
{ 
public:
	int getColorDepth(void){return 24;}
}; 

bool callbackROS(fiona_pkg::WindowColorDepth_srv::Request  &req, fiona_pkg::WindowColorDepth_srv::Response &res)
{
        DWindow myWindow;
        res.window_colordepth = myWindow.getColorDepth();

        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_windowcolordepth";
        if (node_name_empty) node_name = "server_windowcolordepth";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
