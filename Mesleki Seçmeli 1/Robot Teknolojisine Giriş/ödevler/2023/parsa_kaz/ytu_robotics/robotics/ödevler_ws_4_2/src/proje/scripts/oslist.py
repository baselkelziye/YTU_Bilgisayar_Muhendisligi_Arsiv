#!/usr/bin/env python3

import cv2
import rospy
import os

PATH = rospy.get_param("proje_path")

img_path = os.path.join(PATH, "img/")
sign_images = []
for image in os.listdir(img_path):
    print(image)
    sign_images.append(cv2.imread(img_path + image))

# show images in a frame
# cv2.imshow("Signs", sign_images[0])
print(len(sign_images))

while not rospy.is_shutdown():
    pass