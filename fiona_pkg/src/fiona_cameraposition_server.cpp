#include <ros/ros.h>
#include <fiona_pkg/CameraPosition_srv.h>
#include <cstring>

class ICameraPosition {
public:
	 virtual void setCameraPosition(float X,float Y,float Z) = 0;
};

class DCameraPosition: public ICameraPosition
{ 
public:
	void setCameraPosition(float X,float Y,float Z){} 

}; 


bool callbackROS(fiona_pkg::CameraPosition_srv::Request  &req, fiona_pkg::CameraPosition_srv::Response &res)
{
        DCameraPosition myCameraPosition;
        myCameraPosition.setCameraPosition((float)req.x, (float)req.y, (float)req.z);
        res.camera_position = true;
        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_cameraposition";
        if (node_name_empty) node_name = "server_cameraposition";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
