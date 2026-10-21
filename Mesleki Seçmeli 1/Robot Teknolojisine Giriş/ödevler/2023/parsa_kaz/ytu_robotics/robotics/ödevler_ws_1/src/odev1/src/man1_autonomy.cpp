#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

#include <vector>
#define signof_compare(a, b) (a >= b) - (a < b) // 1 if a>=b, -1 if a<b

ros::Publisher cmd_vel_pub;
geometry_msgs::Twist cmd_vel;

void laserCallBack(const sensor_msgs::LaserScan::ConstPtr &laser)
{
	// ASAGIDA BULUNAN IF KOMUTU ORNEK OLARAK VERILMISTIR. SIZIN BURAYI DEGISTIRMENIZ BEKLENMEKTEDIR
	// BURDAN SONRASINI DEGISTIR

	/* Caner code

	float left, leftFront, front, rightFront, right;

	right = laser->ranges[180];
	rightFront = laser->ranges[360];
	front = laser->ranges[540];
	leftFront = laser->ranges[720];
	left = laser->ranges[900];

	if (front > 0.8)
	{
		cmd_vel.linear.x = 0.25;

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
			cmd_vel.angular.z = 0.5;
		}
	}
	*/

	// ros::Publisher log_info = nh.advertise<std_msgs::String>("/rtg/log", 1000) // #LOG

	std::vector<float> laser_ranges = laser->ranges;
	size_t range_size = laser_ranges.size();
	// float range_min = laser_msg->range_min, range_max = laser_msg->range_max;
	float range_front_laser = laser_ranges[range_size / 2];
	// int range_front_fov = 40; // 40 degrees, 70 degrees for left and right
	// int range_lr_fov_size = (180 - range_front_FOV) / 2 * range_size / 180; // = 420
	float range_left_min = 100, range_right_min = 100;
	float left_sum = 0.0, right_sum = 0.0;

	const float CRASH_DISTANCE = 0.25;
	const float MAXWALL_DISTANCE = 0.5;

	const float ANGULAR_STEP = 0.25;
	const float LINEAR_STEP = 0.5;

	// ROS_INFO("Range front: %f", range_front_laser);
	int range_area_size = range_size / 6;
	float right = laser_ranges[range_area_size],
		  rightFront = laser_ranges[2 * range_area_size],
		  front = laser_ranges[3 * range_area_size],
		  leftFront = laser_ranges[4 * range_area_size],
		  left = laser_ranges[5 * range_area_size];

	float range_right = std::copy(laser_ranges.begin(), laser_ranges.begin() + range_area_size);
	float range_rightFront = std::copy(laser_ranges.begin() + range_area_size, laser_ranges.begin() + 2 * range_area_size);
	float range_front = std::copy(laser_ranges.begin() + 2 * range_area_size, laser_ranges.begin() + 3 * range_area_size);
	float range_leftFront = std::copy(laser_ranges.begin() + 3 * range_area_size, laser_ranges.begin() + 4 * range_area_size);
	float range_left = std::copy(laser_ranges.begin() + 4 * range_area_size, laser_ranges.begin() + 5 * range_area_size);

	float right_avg = std::accumulate(range_right.begin(), range_right.end(), 0.0) / range_area_size;
	float rightFront_avg = std::accumulate(range_rightFront.begin(), range_rightFront.end(), 0.0) / range_area_size;
	float front_avg = std::accumulate(range_front.begin(), range_front.end(), 0.0) / range_area_size;
	float leftFront_avg = std::accumulate(range_leftFront.begin(), range_leftFront.end(), 0.0) / range_area_size;
	float left_avg = std::accumulate(range_left.begin(), range_left.end(), 0.0) / range_area_size;

	float right_min = *std::min_element(laser_ranges.begin(), laser_ranges.begin() + range_area_size);
	float rightFront_min = *std::min_element(laser_ranges.begin() + range_area_size, laser_ranges.begin() + 2 * range_area_size);
	float front_min = *std::min_element(laser_ranges.begin() + 2 * range_area_size, laser_ranges.begin() + 3 * range_area_size);
	float leftFront_min = *std::min_element(laser_ranges.begin() + 3 * range_area_size, laser_ranges.begin() + 4 * range_area_size);
	float left_min = *std::min_element(laser_ranges.begin() + 4 * range_area_size, laser_ranges.begin() + 5 * range_area_size);

	// float ranges_min = *std::min_element(laser_ranges.begin(), laser_ranges.end());

	// ROS_INFO("<R RF F LF L>: <%f %f %f %f %f>", right_avg, rightFront_avg, front_avg, leftFront_avg, left_avg);

	if (front_avg < CRASH_DISTANCE)
	{
		// robot crashed, turn
		ROS_INFO("[ROBOT] crashed, turning!");
		cmd_vel.linear.x = 0;
		cmd_vel.angular.z = signof_compare(left_avg, right_avg) * ANGULAR_STEP;
	}
	else if (front_avg < MAXWALL_DISTANCE || leftFront_avg < MAXWALL_DISTANCE || rightFront_avg < MAXWALL_DISTANCE)
	{
		// robot is close to a wall, turn
		ROS_INFO("[ROBOT] Close to a wall, turning!");
		cmd_vel.linear.x = LINEAR_STEP / 2;
		cmd_vel.angular.z = signof_compare(left_avg, right_avg) * ANGULAR_STEP;
	}
	else
	{
		// robot is safe, go forward
		ROS_INFO("[ROBOT] Safe, going forward!");
		cmd_vel.linear.x = LINEAR_STEP;
		cmd_vel.angular.z = 0.0;
	}

	// log_info.publish("Laser size: " + std::to_string(range_size)); // #LOG
	// BURDAN SONRASINA DOKUNMA

	cmd_vel_pub.publish(cmd_vel);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "man1_autonomy");
	ros::NodeHandle nh;

	cmd_vel.linear.y = 0.0;
	cmd_vel.linear.z = 0.0;
	cmd_vel.angular.x = 0.0;
	cmd_vel.angular.y = 0.0;

	ros::Subscriber laser_sub = nh.subscribe("/rtg/hokuyo", 1000, laserCallBack);
	cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/rtg/cmd_vel", 1000);

	ros::spin();

	return 0;
}
