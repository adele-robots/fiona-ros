#include <ros/ros.h>
#include <fiona_pkg/DetectedFacePositionConsumer_srv.h>
#include <cstring>

class IFacePosition {
public:
	virtual void consumeDetectedFacePosition(bool isFaceDetected, double x, double y) = 0;
};

class DFacePosition: public IFacePosition
{ 
public:
	void consumeDetectedFacePosition(bool isFaceDetected, double x, double y){}
}; 


bool callbackROS(fiona_pkg::DetectedFacePositionConsumer_srv::Request  &req, fiona_pkg::DetectedFacePositionConsumer_srv::Response &res)
{
        DFacePosition myFacePosition;
        if (req.isFaceDetected == 1){
                myFacePosition.consumeDetectedFacePosition(true, (double)req.x, (double)req.y);
        	res.face_detected = true;
        	return true;
	}
	else{
                myFacePosition.consumeDetectedFacePosition(false, (double)req.x, (double)req.y);
		res.face_detected = true;
        	return true;
	}
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_faceposition";
        if (node_name_empty) node_name = "server_faceposition";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
