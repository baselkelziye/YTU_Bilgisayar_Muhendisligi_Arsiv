/*
BU DOSYAYI ISTEDIGINIZ GIBI DUZENLEYEBILIRSINIZ. ANCAK
DOSYANIN ISMINI DEGISTIRMEYINIZ (GRUP NUMARASI EKLEMESI HARIC)
YAYINLAYACAGINIZ cmd_vel MESAJI BU PROGRAMDAN YAYINLANMALIDIR.
*/

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/OccupancyGrid.h"
#include "sensor_msgs/LaserScan.h"

ros::Publisher cmd_vel_pub;
geometry_msgs::Twist cmd_vel;

void laserCallBack(const sensor_msgs::LaserScan::ConstPtr &laser)
{
	float left, leftFront, front, rightFront, right;

	right = laser->ranges[180];
	rightFront = laser->ranges[360];
	front = laser->ranges[540];
	leftFront = laser->ranges[720];
	left = laser->ranges[900];

	if (front > 0.8)
	{
		cmd_vel.linear.x = 0.50;

		if ((leftFront - rightFront) > 1)
		{
			cmd_vel.angular.z = 1.0;
		}

		else if ((leftFront - rightFront) > 0.5)
		{
			cmd_vel.angular.z = 0.5;
		}

		else if ((rightFront - leftFront) < 1)
		{
			cmd_vel.angular.z = -1.0;
		}

		else if ((rightFront - leftFront) < 0.5)
		{
			cmd_vel.angular.z = -0.5;
		}
	}

	else
	{
		cmd_vel.linear.x = 0.0;

		if (left > right)
		{
			cmd_vel.angular.z = 1;
		}

		else
		{
			cmd_vel.angular.z = -1;
		}
	}

	cmd_vel_pub.publish(cmd_vel);
}

void mapCallBack(const nav_msgs::OccupancyGrid::ConstPtr &map)
{

	cmd_vel_pub.publish(cmd_vel);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "man3_autonomy");
	ros::NodeHandle nh;

	cmd_vel.linear.y = 0.0;
	cmd_vel.linear.z = 0.0;
	cmd_vel.angular.x = 0.0;
	cmd_vel.angular.y = 0.0;

	ros::Subscriber map_ornek = nh.subscribe("/map", 1000, mapCallBack);
	ros::Subscriber sub_laser = nh.subscribe("/robot1/hokuyo", 1000, laserCallBack);

	cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/rtg/cmd_vel", 1000);

	ros::spin();

	return 0;
}
