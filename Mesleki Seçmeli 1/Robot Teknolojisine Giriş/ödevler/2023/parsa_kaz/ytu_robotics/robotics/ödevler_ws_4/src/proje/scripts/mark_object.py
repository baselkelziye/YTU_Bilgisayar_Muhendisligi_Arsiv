#!/usr/bin/env python3

import rospy
import math

# import tf transformations
from tf.transformations import euler_from_quaternion

from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from proje.msg import objectpx
from visualization_msgs.msg import MarkerArray
from visualization_msgs.msg import Marker

'''
Determines the position of the object
based on the laser scan data and the robot's odometry and where the robot is looking at.
'''

ODOM = None
SCAN = None
OBJ = None

class ObjectMarker:

    def __init__(self):
        rospy.init_node('object_marker')
        self.odom_sub = rospy.Subscriber('/rtg/odom', Odometry, self.odom_callback)
        self.scan_sub = rospy.Subscriber('/rtg/hokuyo', LaserScan, self.scan_callback)
        self.obj_sub = rospy.Subscriber('/obj', objectpx, self.obj_callback)
        self.pub = rospy.Publisher('/obj/markers', MarkerArray, queue_size=10)

    def odom_callback(self, msg):
        self.robot_x = msg.pose.pose.position.x
        self.robot_y = msg.pose.pose.position.y

        # Get the robot's yaw angle
        orientation_ = msg.pose.pose.orientation
        quaternion = (orientation_.x, orientation_.y, orientation_.z, orientation_.w)
        roll, pitch, yaw = euler_from_quaternion(quaternion)

        self.robot_yaw = yaw # in radians (-pi to pi relative to the x-axis)

        # print("Robot position: ", self.robot_x, self.robot_y)
        # print("Robot yaw: ", self.robot_yaw)

    def scan_callback(self, msg):
        # Get the distance of the front laser that is looking at the object
        ''' 
        # LaserScan message details:
        #     Measurement steps 1081
        #     Detection angle 270°
        #     Angular resolution 0.25°
        #     Measurement range 0.12m to 3.5m
        #     Front laser index 540
        '''
        self.laser_ranges = msg.ranges
        # print("Laser ranges: len", len(self.laser_ranges))
        # self.laser_angle_increment = msg.angle_increment


    def publish_markers(self):

        # aux function to create a marker
        def create_marker(id=0, pose=(0,0,0), scale=0.2, type=0, rgb=(1.0,1.0,1.0), text=''):
            marker = Marker()
            marker.header.frame_id = "map"
            marker.type = type
            marker.color.r = rgb[0]
            marker.color.g = rgb[1]
            marker.color.b = rgb[2]
            marker.color.a = 1.0
            marker.id = id
            marker.action = marker.ADD
            marker.scale.x = scale
            marker.scale.y = scale
            marker.scale.z = scale
            marker.pose.orientation.x = 0.0
            marker.pose.orientation.y = 0.0
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
            marker.pose.position.x = pose[0]
            marker.pose.position.y = pose[1]
            marker.pose.position.z = pose[2]
            marker.text = text
            return marker

        # create a message for the marker array
        marker_array = MarkerArray()
        # create a marker for each object
        for i, obj in enumerate(self.objects):
            timestamp = rospy.Time.now()
            id = i + timestamp.secs // 20 # every 20 seconds, the id will be new
            marker = None
            if obj['type'] == 'barrel':
                marker = create_marker(id=id, pose=(obj['x'], obj['y'], 0.0), scale=0.3, 
                                       type=Marker.CYLINDER, rgb=(0.0,0.0,1.0))
            elif obj['type'] == 'hazmat':
                marker = create_marker(id=id, pose=(obj['x'], obj['y'], 0.0), scale=0.3, 
                                       type=Marker.CUBE, rgb=(1.0,0.0,0.0))
                text = 'Hazmat|'+obj['text'] if obj['text'] != '' else 'Hazmat'
                marker_text = create_marker(id=id+1000, pose=(obj['x'], obj['y'], 0.5), scale=0.2,
                                            type=Marker.TEXT_VIEW_FACING, rgb=(0.0,1.0,0.0), text=text)
                marker_array.markers.append(marker_text)
            else:
                marker = create_marker(id=i, pose=(obj['x'], obj['y'], 0.0), scale=0.3, 
                                       type=Marker.CUBE, rgb=(1.0,1.0,1.0))
                text = 'QR|'+obj['text'] if obj['text'] != '' else 'QR'
                marker_text = create_marker(id=id+1000, pose=(obj['x'], obj['y'], 0.5), scale=0.2,
                                            type=Marker.TEXT_VIEW_FACING, rgb=(0.0,1.0,0.0), text=text)
                marker_array.markers.append(marker_text)

            marker_array.markers.append(marker)

        # publish the marker array
        self.pub.publish(marker_array)


    def obj_callback(self, msg):
        # Get the related laser range based on the object's pixel position
        self.objects = []
        
        x_arr = msg.cx
        type_arr = msg.type
        text_arr = msg.text
        width = msg.frame_w

        for i, x in enumerate(x_arr):
            print(f"---- Object {i} ----")
            print(f"Type: {type_arr[i]}, Text: {text_arr[i]}")
            # Calculate the angle of the laser that is looking at the object
            angle = - x / width * 180 + 90 # relative to the middle pixel, counterclockwise
            print("Angle: ", angle)
            # Calculate the index of the laser that is looking at the object
            laser_index = int(angle / 0.25) + 540 # 540 is the index of the front laser
            print("Laser index: ", laser_index)
            # Get the range of the laser that is looking at the object
            obj_distance = self.laser_ranges[laser_index]
            print("Object distance: ", obj_distance)
            # Calculate the object's position
            obj_x = self.robot_x + obj_distance * math.cos(self.robot_yaw + math.radians(angle))
            obj_y = self.robot_y + obj_distance * math.sin(self.robot_yaw + math.radians(angle))
            print(f"Object position: {obj_x:.2f}, {obj_y:.2f}")

            self.objects.append({'type': type_arr[i], 'text': text_arr[i], 'x': obj_x, 'y': obj_y})


        self.publish_markers()
    


        

if __name__ == '__main__':
    obj_detector = ObjectMarker()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        rospy.loginfo("Shutting down object marker node.")
    except Exception as e:
        print(e)

