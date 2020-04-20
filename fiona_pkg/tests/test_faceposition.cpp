#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <fiona_pkg/DetectedFacePositionConsumer_srv.h>

std::shared_ptr<ros::NodeHandle> nh;

TEST(TESTSuite, ValidFilename)
{
  ros::ServiceClient client = nh->serviceClient<fiona_pkg::DetectedFacePositionConsumer_srv>("fiona_service");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  fiona_pkg::DetectedFacePositionConsumer_srv srv;
  srv.request.isFaceDetected = 1;
  srv.request.x = 1.2;
  srv.request.y = 4.25;
  client.call(srv);

  EXPECT_EQ(true, srv.response.face_detected);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_faceposition");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

