#include <ros/ros.h>
#include <fiona_pkg/AudioSize_srv.h>
#include <cstring>

class IAudioSize {
public:
        // All sizes in bytes, not samples of 16 bit words.
	virtual int getStoredAudioSize() = 0;
};

class DAudioSize: public IAudioSize
{ 
public:
	int getStoredAudioSize(){return 16;}
}; 

bool callbackROS(fiona_pkg::AudioSize_srv::Request  &req, fiona_pkg::AudioSize_srv::Response &res)
{
        DAudioSize myAudioSize;
        res.audiosize = myAudioSize.getStoredAudioSize();

        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_audiosize";
        if (node_name_empty) node_name = "server_audiosize";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
