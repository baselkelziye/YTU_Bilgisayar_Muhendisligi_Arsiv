#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

// Receive Laser messages
void cb(const sensor_msgs::LaserScanConstPtr &_msg)
{
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "p3at");

  ros::NodeHandle nh;

  // Advertise on the cmd_vel topic to control the pioneer3at
  ros::Publisher cmdVelPub = nh.advertise<geometry_msgs::Twist>(
      "/cmd_vel", 1000);

  geometry_msgs::Twist msg;
  msg.linear.x = 1.0;

  // Subscribe to the /hokuyo laser topic
  ros::Subscriber sub = nh.subscribe("/hokuyo", 1000, cb);

  ros::Rate rate(20);

  // Move the pioneer3at
  while (ros::ok())
  {
    cmdVelPub.publish(msg);
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
