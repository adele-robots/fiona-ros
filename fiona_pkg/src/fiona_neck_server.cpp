#include <ros/ros.h>
#include <fiona_pkg/Neck_srv.h>
#include <cstring>

class INeck {
public:
	 virtual void rotateHead(float pan,float tilt) = 0;
};

class DNeck: public INeck
{ 
public:
	void rotateHead(float pan,float tilt){} 

}; 


bool callbackROS(fiona_pkg::Neck_srv::Request  &req, fiona_pkg::Neck_srv::Response &res)
{
        DNeck myNeck;
        myNeck.rotateHead((float)req.pan, (float)req.tilt);
        res.neck = true;
        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_neck";
        if (node_name_empty) node_name = "server_neck";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
