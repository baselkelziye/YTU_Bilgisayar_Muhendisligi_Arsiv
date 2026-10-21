#!/usr/bin/env python3

import rospy
import cv2
import numpy as np
from pyzbar.pyzbar import decode
import os

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

"""

ros node.  /camera_read_obj

publish -> dffdfdf
when? Yesil rectangle cizildiginde

mapping.py:
subscribes to /camera_read_obj
-> X

"""



CAMERA_TOPIC = "/rtg/camera/rgb/image_raw"

# def detect_objects(frame):
#     # returns countours of the object
#     kernel = np.ones((3,3), np.uint8)
#     frame = cv2.dilate(frame, kernel, iterations=1)
#     contours, _ = cv2.findContours(frame, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

#     bbox = []
#     for cnt in contours:
#         x, y, w, h = cv2.boundingRect(cnt)
#         area = cv2.contourArea(cnt)

#         # filter out small objects
#         if area/(w*h) > (np.pi/4) and area > 200:
#             # draw a blue rectangle on the object
#             # cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
#             bbox.append((x, y, x+w, y+h))

#     # ros info bbox
#     print(bbox)

#     cv2.imshow("Camera output - dialated", frame)
#     return bbox
  
def remove_bg(frame):
  def _remove_bg(frame, colors, thresh=50):
    # Convert frame to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    r, g, b = colors

    # lower mask for wall
    lower = np.array([b-thresh,g-thresh,r-thresh])
    upper = np.array([b+thresh,g+thresh,r+thresh])
    # define range of blue color in hsv
    mask = cv2.inRange(hsv, lower, upper)

    # Apply mask to original frame
    mask = cv2.bitwise_not(mask)
    res = cv2.bitwise_and(frame,frame, mask= mask)

    return res

  frame = _remove_bg(frame, [65,100,30], thresh=70) # wooden wall
  # frame = remove_bg(frame, [110,20,10], thresh=30) # gray sky

  return frame

def mask_barrel(frame):
  # Convert frame to HSV color space
  hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
  # define range of wall color in hsv
  # r, g, b = np.array([65,100,30])
  r, g, b = [75,130,120]
  thresh = 50

  # lower mask for wall
  lower = np.array([b-thresh,g-thresh,r-thresh])
  upper = np.array([b+thresh,g+thresh,r+thresh])
  # define range of blue color in hsv
  mask = cv2.inRange(hsv, lower, upper)

  # Apply mask to original frame
  # mask = cv2.bitwise_not(mask)
  res = cv2.bitwise_and(frame,frame, mask= mask)

  return res


def preprocess_image(image, blur=False, threshhold=60, removeBG=False, maskBarrel=False, verbose=False): 
  
  if removeBG:
    image = remove_bg(image)
    
  if maskBarrel:
    image = mask_barrel(image)


  # Convert to grayscale
  image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
  # Blur the image for better detection
  if blur:
    image = cv2.GaussianBlur(image, (9,9), 0)
  # _, bw = cv2.threshold(gray, threshhold, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

  if threshhold > 0:
    _, image = cv2.threshold(image, threshhold, 255, cv2.THRESH_BINARY)
    
  # # detect all objects
  # bbox = detect_objects(bw)

  # for x, y, x2, y2 in bbox:
  #     # draw blue rectangle on the object
  #     cv2.rectangle(image, (x, y), (x2, y2), (255, 0, 0), 2)

  if verbose:
    cv2.imshow("Camera output - processed", image)

  # Return the processed image
  return image # , bbox

def detect_polygons(frame):
  frame_bw = preprocess_image(frame, threshhold=-25, verbose=True)


  params = cv2.SimpleBlobDetector_Params()
  params.filterByArea = True
  params.minArea = 1024
  params.maxArea = 65536
  params.filterByCircularity = False
  params.filterByConvexity = True
  params.minConvexity = 0.5
  params.filterByInertia = False

  detector = cv2.SimpleBlobDetector_create(params)
  keypoints = detector.detect(frame_bw)
  # print(keypoints)

  for keypoint in keypoints:
    x = int(keypoint.pt[0])
    y = int(keypoint.pt[1])
    s = int(keypoint.size)
    cv2.rectangle(frame, (x-s, y-s), (x+s, y+s), (0, 255, 0), 2)
    
  return frame

def detect_barrel(frame):
  # preprocess the image
  frame_bw = preprocess_image(frame, threshhold=25, maskBarrel=True, verbose=True)

  # detect the contours of the barrel
  contours, _ = cv2.findContours(frame_bw, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

  # filter out the contours that are too small
  contours = [cnt for cnt in contours if cv2.contourArea(cnt) > 5000]

  # draw the contours
  cv2.drawContours(frame, contours, -1, (0, 255, 0), 1)

  # draw the bounding box
  for cnt in contours:
    x, y, w, h = cv2.boundingRect(cnt)
    cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
    cv2.putText(frame, 'Varil', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)

  return frame

def detect_hazmat(frame):
  # preprocess the image
  frame_bw = preprocess_image(frame, threshhold=-40, removeBG=True,verbose=True)

  # detect the contours of the barrel
  contours, _ = cv2.findContours(frame_bw, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

  # filter out the contours that are too small
  contours = [cnt for cnt in contours if cv2.contourArea(cnt) > 2000]

  # filter only the contours that are diamond shaped
  for cnt in contours:
    x, y, w, h = cv2.boundingRect(cnt)
    approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt,True),True)
    if cv2.contourArea(cnt) > 2000 and len(approx) == 4:
      if w/h > 0.8 and w/h < 1.2:
        contours = [cnt]
        break

  # draw the contours
  cv2.drawContours(frame, contours, -1, (0, 255, 0), 1)

  # draw the bounding box
  for cnt in contours:
    x, y, w, h = cv2.boundingRect(cnt)
    cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
    cv2.putText(frame, 'Hazmat', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)

  return frame



def read_qrcode(frame):
  qcd = cv2.QRCodeDetector()
  
  frame_bw = preprocess_image(frame)

  try: 
    ret_qr, decoded, points, _ = qcd.detectAndDecodeMulti(frame_bw)
    if ret_qr:
      for txt, p in zip(decoded, points):
        if txt:
          print(txt)
          color = (0, 255, 0)
        else:
          color = (0, 0, 255)
          frame = cv2.polylines(frame, [p.astype(int)], True, color, 8)
          # print(p.shape) # (4, 2)
          x, y = int(p[0][0]) , int(p[0][1])
          frame = cv2.putText(frame, txt, (x, y-20), cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2, cv2.LINE_AA)
  except Exception as e:
    print(e)

  return frame

def read_qrcode_zbar(frame):
  decodedObjects = decode(frame)
  for obj in decodedObjects:
    txt = obj.data.decode("utf-8")
    print(txt)
    (x, y, w, h) = obj.rect
    cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 8)
    cv2.putText(frame, txt, (x, y-20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)

  return frame



class camera_1:

  def __init__(self):
    self.image_sub = rospy.Subscriber(CAMERA_TOPIC, Image, self.callback)
    # self.hazmat_images = hazmat_images

  def callback(self,data):
    bridge = CvBridge()

    try:
      cv_image = bridge.imgmsg_to_cv2(data, desired_encoding="bgr8")
    except CvBridgeError as e:
      rospy.logerr(e)
    
    # detect o
    image = detect_hazmat(cv_image)
    # resized_image = cv2.resize(image, ) 

    cv2.imshow("Camera output", image)

    cv2.waitKey(3)

def main():  

  camera_1()

  try:
    rospy.spin()
  except KeyboardInterrupt:
    rospy.loginfo("Shutting down")

  cv2.destroyAllWindows()

if __name__ == '__main__':
    rospy.init_node('camera_read', anonymous=False)
    main()