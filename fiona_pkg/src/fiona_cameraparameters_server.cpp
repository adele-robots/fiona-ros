#include <ros/ros.h>
#include <fiona_pkg/CameraParameters_srv.h>
#include <cstring>

class ICameraParameters {
public:
        virtual void setCameraParameters(bool IsOrtho, float VisionAngle, float nearClippingPlane, float FarClippingPlane) = 0;
};

class DCameraParameters: public ICameraParameters
{ 
public:
	void setCameraParameters(bool IsOrtho, float VisionAngle, float nearClippingPlane, float FarClippingPlane){} 

}; 


bool callbackROS(fiona_pkg::CameraParameters_srv::Request  &req, fiona_pkg::CameraParameters_srv::Response &res)
{
        DCamera myCameraParameters;
        if (req.IsOrtho == 1)
                myCameraParameters.setCameraParameters(true, (float)req.VisionAngle, (float)req.nearClippingPlane, (float)req.FarClippingPlane);

        else
                myCameraParameters.setCameraParameters(false, (float)req.VisionAngle, (float)req.nearClippingPlane, (float)req.FarClippingPlane);

        res.camera_parameters = true;
        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_cameraparameters";
        if (node_name_empty) node_name = "server_cameraparameters";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
