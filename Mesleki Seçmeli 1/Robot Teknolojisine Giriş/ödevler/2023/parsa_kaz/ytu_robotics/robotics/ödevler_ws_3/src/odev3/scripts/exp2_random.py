#!/usr/bin/env python3
import random, os, time, subprocess

poses_x = [1.2, 0.0]
poses_y = [1.2, 0.0, -1.2, -2.4, -3.6, -4.8, -6.0]
poses_Y = [3.14, 1.57, 0.0, -1.57]

pose_x_i = random.randint(0, 1)
pose_y_i = random.randint(0, 6)
pose_Y_i = random.randint(0, 3)
pose_args = "-x " + str(poses_x[pose_x_i]) + " -y " + str(poses_y[pose_y_i]) + " -Y " + str(poses_Y[pose_Y_i])

os.environ['RTG_POSE_ARGS'] = pose_args
#print(os.environ['RTG_POSE_ARGS'])
time.sleep(3)
os.system("roslaunch p3at_description spawn_p3at.launch")
