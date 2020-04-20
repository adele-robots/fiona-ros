#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
        ros::init(argc, argv, "fiona_talker");
        ros::NodeHandle n;

        ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1);
        ros::Rate loop_rate(10);
        std_msgs::String msg;

        std::stringstream ss;
        ss << "Hello ROS, I am FIONA!";
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        while(chatter_pub.getNumSubscribers() == 0)
                loop_rate.sleep();

        while (ros::ok())
        {
                chatter_pub.publish(msg);
                ros::spinOnce();
        }


  return 0;
}

