#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <fiona_pkg/AsyncFatalErrorHandler_srv.h>

std::shared_ptr<ros::NodeHandle> nh;

TEST(TESTSuite, ValidFilename)
{
  ros::ServiceClient client = nh->serviceClient<fiona_pkg::AsyncFatalErrorHandler_srv>("fiona_service");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  fiona_pkg::AsyncFatalErrorHandler_srv srv;
  srv.request.msg = "error";
  client.call(srv);

  EXPECT_EQ(true, srv.response.errorhandler);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_errorhandler");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

