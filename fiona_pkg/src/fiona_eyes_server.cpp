#include <ros/ros.h>
#include <fiona_pkg/Eyes_srv.h>
#include <cstring>

class IEyes {
public:
	 virtual void rotateEye(float pan,float tilt) = 0;
};

class DEyes: public IEyes
{ 
public:
	void rotateEye(float pan,float tilt){} 

}; 


bool callbackROS(fiona_pkg::Eyes_srv::Request  &req, fiona_pkg::Eyes_srv::Response &res)
{
        DEyes myEyes;
        myEyes.rotateEye((float)req.pan, (float)req.tilt);
        res.eyes = true;
        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_eyes";
        if (node_name_empty) node_name = "server_eyes";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
