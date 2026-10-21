#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include <visualization_msgs/Marker.h>

visualization_msgs::Marker gezinge;
ros::Publisher trajectory_pub;

void odomCallBack(const nav_msgs::Odometry::ConstPtr& odom){
	gezinge.header.stamp = ros::Time::now();
	gezinge.points.push_back(odom->pose.pose.position);
	trajectory_pub.publish(gezinge);
}


int main(int argc, char **argv){
	ros::init(argc, argv, "gezinge_cizdirme");
	ros::NodeHandle nh;

	gezinge.header.frame_id = "trajectory";
	gezinge.ns = "traj";
	gezinge.action = visualization_msgs::Marker::ADD;
	gezinge.pose.orientation.w = 1.0;
	gezinge.id = 0;
	gezinge.type = visualization_msgs::Marker::LINE_STRIP;
	gezinge.scale.x = 0.1;
	gezinge.color.r = 0.0;
	gezinge.color.g = 1.0;
	gezinge.color.b = 1.0;
	gezinge.color.a = 1.0;

	ros::Subscriber odom_sub = nh.subscribe("/rtg/odom", 1000, odomCallBack);
	trajectory_pub = nh.advertise<visualization_msgs::Marker>("/trajectory", 1000);

	ros::spin();

	return 0;
}
