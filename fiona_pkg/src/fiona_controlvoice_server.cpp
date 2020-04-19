#include <ros/ros.h>
#include <fiona_pkg/ControlVoice_srv.h>
#include <cstring>

class IControlVoice {
public:
	virtual void startSpeaking(void) = 0;
        virtual void stopSpeaking(void) = 0;
        virtual void startVoice(void) = 0;
};


class DControlVoice: public IAnimation
{ 
public: 
	void startSpeaking(void){}
        void stopSpeaking(void){}
        void startVoice(void){}
}; 

bool callbackROS(fiona_pkg::ControlVoice_srv::Request  &req, fiona_pkg::ControlVoice_srv::Response &res)
{
        DControlVoice myControlVoice;

        if (!strcmp(req.voice_selection.c_str(), "speaking")
        {
                myControlVoice.startSpeaking();
                res.control_voice = true;
		return true;
        }

        if (!strcmp(req.voice_selection.c_str(), "voice")
        {
                myControlVoice.startVoice();
                res.control_voice = true;
		return true;
        }

        if (!strcmp(req.voice_selection.c_str(), "nospeaking")
        {
                myControlVoice.stopSpeaking();
                res.control_voice = true;
		return true;
        }

        else{
                res.control_voice = false;
		return true;
	}
}

int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_controlvoice";
        if (node_name_empty) node_name = "server_controlvoice";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
