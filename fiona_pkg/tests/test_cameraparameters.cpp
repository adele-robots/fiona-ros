#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <fiona_pkg/CameraParameters_srv.h>

std::shared_ptr<ros::NodeHandle> nh;

TEST(TESTSuite, ValidFilename)
{
  ros::ServiceClient client = nh->serviceClient<fiona_pkg::CameraParameters_srv>("fiona_service");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  fiona_pkg::CameraParameters_srv srv;
  srv.request.IsOrtho = 1;
  srv.request.VisionAngle = 1.2;
  srv.request.nearClippingPlane = 4.25;
  srv.request.FarClippingPlane = 6.8;
  client.call(srv);

  EXPECT_EQ(true, srv.response.camera_parameters);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_cameraparameters");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

