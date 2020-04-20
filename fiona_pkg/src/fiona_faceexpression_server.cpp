#include <ros/ros.h>
#include <fiona_pkg/FaceExpression_srv.h>
#include <cstring>

class IFaceExpression {
public:
	virtual void setFaceExpression(char *expressionName,float intensity) = 0;
};


class DFaceExpression: public IFaceExpression
{ 
public: 
    	void setFaceExpression(char *expressionName,float intensity){}
}; 

bool callbackROS(fiona_pkg::FaceExpression_srv::Request  &req, fiona_pkg::FaceExpression_srv::Response &res)
{
        DFaceExpression myFaceExpression;
        myFaceExpression.setFaceExpression((char*)req.expressionName.c_str(), (float)req.intensity);
        res.face_expression = true;
        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_faceexpression";
        if (node_name_empty) node_name = "server_faceexpression";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
