#include <ros/ros.h>
#include <fiona_pkg/CameraRotation_srv.h>
#include <cstring>

class ICameraRotation {
public:
	 virtual void setCameraRotation(float X,float Y,float Z) = 0;
};

class DCameraRotation: public ICameraRotation
{ 
public:
	void setCameraRotation(float X,float Y,float Z){} 

}; 


bool callbackROS(fiona_pkg::CameraRotation_srv::Request  &req, fiona_pkg::CameraRotation_srv::Response &res)
{
        DCameraRotation myCameraRotation;
        myCameraRotation.setCameraRotation((float)req.x, (float)req.y, (float)req.z);
        res.camera_rotation = true;
        return true;
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_camerarotation";
        if (node_name_empty) node_name = "server_camerarotation";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
