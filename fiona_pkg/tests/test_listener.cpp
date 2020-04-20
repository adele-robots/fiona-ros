#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <gtest/gtest.h>

std::shared_ptr<ros::NodeHandle> nh;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  EXPECT_EQ("Hello ROS, I am FIONA!", msg->data);
  ros::shutdown();
}

TEST(TESTSuite, HelloWorlSubscriber)
{
  ros::Subscriber sub = nh->subscribe("chatter", 1, chatterCallback);

  ros::spin();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_listener");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

