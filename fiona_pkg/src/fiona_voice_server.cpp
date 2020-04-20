#include <ros/ros.h>
#include <fiona_pkg/Voice_srv.h>
#include <cstring>

class IVoice {
public:
	virtual void sayThis(char *prompt) = 0;         /* Retorna sin esperar */
        virtual void waitEndOfSpeech(void) = 0;
        virtual void stopSpeech(void) = 0;

};


class DVoice: public IVoice
{ 
public: 
	void sayThis(char *prompt){}         
        void waitEndOfSpeech(void){}
        void stopSpeech(void){}
}; 

bool callbackROS(fiona_pkg::Voice_srv::Request  &req, fiona_pkg::Voice_srv::Response &res)
{
        DVoice myVoice;
        if (!strcmp(req.select.c_str(), "say"))
        {
                myVoice.sayThis((char*)req.prompt.c_str());
                res.voice_say = true;	
		return true;
        }
        if (!strcmp(req.select.c_str(), "stop"))
        {
                myVoice.stopSpeech();
                res.voice_say = true;
		return true;
        }
        if (!strcmp(req.select.c_str(), "wait"))
        {
                myVoice.waitEndOfSpeech();
                res.voice_say = true;
		return true;
        }
        else{
                res.voice_say = false;
		return true;
	}
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_voice";
        if (node_name_empty) node_name = "server_voice";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
