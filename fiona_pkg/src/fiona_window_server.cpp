#include <ros/ros.h>
#include <fiona_pkg/Window_srv.h>
#include <cstring>

class IWindow {
public:
	virtual void show(void) = 0;
        virtual void hide(void) = 0;
        virtual void makeCurrentopenGlThread(void) = 0;
        virtual void openGlSwapBuffers(void) = 0;
};

class DWindow: public IWindow
{ 
public:
	void show(void){}
	void hide(void){}
	void makeCurrentopenGlThread(void){}
	void openGlSwapBuffers(void){} 
}; 

bool callbackROS(fiona_pkg::Window_srv::Request  &req, fiona_pkg::Window_srv::Response &res)
{
        DWindow myWindow;
        if(!strcmp(req.select.c_str(), "hide"))
        {
                myWindow.hide();
                res.window = true;
		return true;
        }
        if(!strcmp(req.select.c_str(), "show"))
        {
                myWindow.show();
                res.window = true;
		return true;
        }
        if(!strcmp(req.select.c_str(), "make"))
        {
                myWindow.makeCurrentopenGlThread();
                res.window = true;
		return true;
        }
        if(!strcmp(req.select.c_str(), "swap"))
        {
                myWindow.openGlSwapBuffers();
                res.window = true;
		return true;
        }
	else{
		res.window = false;
        	return true;
	}
}


int main(int argc, char **argv)
{
        bool remap_name = true;
        bool node_name_empty = true;
        std::map<std::string, std::string> remaps;
        if (remap_name) remaps["__name"] = "fiona_service";
        std::string node_name = "server_window";
        if (node_name_empty) node_name = "server_window";
        ros::init(remaps, node_name, (uint32_t)0);
  
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("fiona_service", callbackROS);
        ROS_INFO("fiona_service ready");
        ros::spin();

  return 0;
}
