#include <ros/ros.h>
#include <fiona_pkg/Renderizable_srv.h>
#include <cstring>

class IRenderizable {
public:
	virtual void render(void) = 0;
};

#endif

class DRenderizable: public IRenderizable
{ 
public: 
	void render(void){}
}; 

bool callbackROS(fiona_pkg::Renderizable_srv::Request  &req, fiona_pkg::Renderizable_srv::Response &res)
{
        DRenderizable myRenderizable;
        myRenderizable.render();
        res.render = true;
        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_render";
        if (node_name_empty) node_name = "server_render";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
