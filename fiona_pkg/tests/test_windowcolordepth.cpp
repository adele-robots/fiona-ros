#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <fiona_pkg/WindowColorDepth_srv.h>

std::shared_ptr<ros::NodeHandle> nh;

TEST(TESTSuite, ValidFilename)
{
  ros::ServiceClient client = nh->serviceClient<fiona_pkg::WindowColorDepth_srv>("fiona_service");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  fiona_pkg::WindowColorDepth_srv srv;
  srv.request.void_request = "run";
  client.call(srv);

  EXPECT_EQ(24, srv.response.window_colordepth);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_windowcolordepth");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

