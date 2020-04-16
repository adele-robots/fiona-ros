#include <ros/ros.h>
#include <fiona_pkg/Animation_srv.h>
#include <cstring>

#ifndef __I_ANIMATION_H
#define __I_ANIMATION_H

class IAnimation {
public:
        virtual void playAnimation(char *animationFileName) = 0;
};

#endif

class DAnimation: public IAnimation
{ 
public: 
    void  playAnimation(char *animationFileName) { std::cout << "fun() called"; } 
}; 


bool callbackROS(fiona_pkg::Animation_srv::Request  &req, fiona_pkg::Animation_srv::Response &res)
{
	DAnimation myAnimation;
	res.animation = false;
	myAnimation.playAnimation((char*)req.avatarFilename.c_str());
        res.animation = true;
        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_animation";
        if (node_name_empty) node_name = "server_animation";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
