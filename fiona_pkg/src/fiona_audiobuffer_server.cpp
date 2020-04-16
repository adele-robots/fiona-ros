#include <ros/ros.h>
#include <fiona_pkg/AudioBuffer_srv.h>
#include <cstring>

class IAudioBuffer {
public:
        // All sizes in bytes, not samples of 16 bit words.
        virtual void queueAudioBuffer(char *buffer, int size) = 0;
        virtual void dequeueAudioBuffer(char *buffer, int size) = 0;
};

class DAudioBuffer: public IAudioBuffer
{ 
public:
	void queueAudioBuffer(char *buffer, int size){ std::cout << "queueAudioBuffer called!";}
        void dequeueAudioBuffer(char *buffer, int size){std::cout << "dequeueAudioBuffer called!";} 

}; 

bool callbackROS(fiona_pkg::AudioBuffer_srv::Request  &req, fiona_pkg::AudioBuffer_srv::Response &res)
{
        DAudioBuffer myAudioBuffer;
        if (!strcmp(req.selection.c_str(), "queue"))
        {
                myAudioBuffer.queueAudioBuffer((char*)req.buffer.c_str(), req.size);
                res.audiobuffer = true;
        }
        if (!strcmp(req.selection.c_str(), "dequeue"))
        {
                myAudioBuffer.dequeueAudioBuffer((char*)req.buffer.c_str(), req.size);
                res.audiobuffer = true;
        }
        else
                res.audiobuffer = false;

        return true;
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_audiobuffer";
        if (node_name_empty) node_name = "server_audiobuffer";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
