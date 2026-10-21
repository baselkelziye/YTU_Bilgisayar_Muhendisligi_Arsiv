#!/usr/bin/env python3

import rospy
import cv2
import numpy as np
import imutils
from pyzbar.pyzbar import decode, ZBarSymbol
import os
import sys


from sensor_msgs.msg import Image
from proje.msg import objectpx as objectpx_msg
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
OBJECT_TOPIC = "/obj"
# system arguments
# HAZMAT_DIR = ""

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



class CameraReader:

  def __init__(self, hazmat_dir, model_path):
      self.hazmat_templates = {}
      print("HAZMAT_DIR:", hazmat_dir)
      for file in os.listdir(hazmat_dir):
        if file.endswith(".png"):
          # Read image as BGR
          img = cv2.imread(os.path.join(hazmat_dir, file))
          self.hazmat_templates[file[:-4]] = img
      
      print(f"model_path: {model_path}")
      self.detector = cv2.wechat_qrcode_WeChatQRCode(model_path+"detect.prototxt",
                                                model_path+"detect.caffemodel",
                                                model_path+"sr.prototxt",
                                                model_path+"sr.caffemodel")
      print(f"WeChatQRCode loaded: {self.detector}")

    
  

  def preprocess_image(self, image, gray=True, blur=False, threshhold=60, removeBG=False, maskBarrel=False, verbose=False): 
    
    if removeBG:
      image = remove_bg(image)
      
    if maskBarrel:
      image = mask_barrel(image)


    # Convert to grayscale
    if gray:
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

  # def detect_polygons(self, frame):
  #   frame_bw = self.preprocess_image(frame, threshhold=-25, verbose=True)


  #   params = cv2.SimpleBlobDetector_Params()
  #   params.filterByArea = True
  #   params.minArea = 1024
  #   params.maxArea = 65536
  #   params.filterByCircularity = False
  #   params.filterByConvexity = True
  #   params.minConvexity = 0.5
  #   params.filterByInertia = False

  #   detector = cv2.SimpleBlobDetector_create(params)
  #   keypoints = detector.detect(frame_bw)
  #   # print(keypoints)

  #   for keypoint in keypoints:
  #     x = int(keypoint.pt[0])
  #     y = int(keypoint.pt[1])
  #     s = int(keypoint.size)
  #     cv2.rectangle(frame, (x-s, y-s), (x+s, y+s), (0, 255, 0), 2)
      
  #   return frame

  def detect_barrel(self, frame):
    # preprocess the image
    frame_bw = self.preprocess_image(frame, threshhold=25, maskBarrel=True)

    # detect the contours of the barrel
    contours, _ = cv2.findContours(frame_bw, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

    # filter out the contours that are too small
    contours = [cnt for cnt in contours if cv2.contourArea(cnt) > 10000]

    # draw the contours
    cv2.drawContours(frame, contours, -1, (0, 255, 255), 1)

    central_points = []
    # draw the bounding box
    for cnt in contours:
      x, y, w, h = cv2.boundingRect(cnt)
      cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
      cv2.putText(frame, 'Varil', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)
    
      # central point
      cx, cy = int(x + w/2) , int(y + h/2)
      # draw the central point
      cv2.circle(frame, (cx, cy), 1, (0, 0, 255), 2)

      central_points.append({'type': 'barrel', 'p': (cx, cy), 'txt': None})

    return frame, central_points


  def read_hazmat(self, frame, bbox, threshhold=0.8):
    # match the templates to the image
    frame_bbox = frame[bbox[1]:bbox[3], bbox[0]:bbox[2]]
    # frame_bbox = self.preprocess_image(frame_bbox, gray=True, threshhold=-35, removeBG=True, verbose=True)
    # cv2.imshow("HAZMAT", frame_bbox) # LOG
    

    w, h = bbox[3]-bbox[1], bbox[2]-bbox[0]
    # match the templates to the image

    best_match, score = None, 0
    for key, template in self.hazmat_templates.items():
      try: 
        # template = self.preprocess_image(template, gray=True, removeBG=True, threshhold=-1, verbose=True)
        template = imutils.rotate_bound(template, 45)
        template = cv2.resize(template, (h, w))

        result = cv2.matchTemplate(frame_bbox, template, cv2.TM_CCOEFF_NORMED)

        # save the best match score
        min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
        if max_val > score:
          score = max_val
          best_match = key

        # print("Template:", key, "Score:", max_val)
      
      except Exception as e:
        print(e)

    if threshhold and score < threshhold:
      return None

    print(f"Best match: {best_match} -Score:{score:.2f}")
    return best_match


  def read_qr(self, frame, bbox):
    # frame_bw = self.preprocess_image(frame, threshhold=-40, ,verbose=True)
    frame_bbox = frame[bbox[1]:bbox[3], bbox[0]:bbox[2]]
    cv2.imshow("QRCode - bbox", frame_bbox) # LOG
    decodedObjects = decode(frame_bbox, symbols=[ZBarSymbol.QRCODE])
    for obj in decodedObjects:
      txt = obj.data.decode("utf-8")
      print(txt)
      # (x, y, w, h) = obj.rect
      # cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 8)
      # cv2.putText(frame, txt, (x, y-20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
      return txt

    return None

  def read_qr_wechat(self, frame, bbox):
    # frame_bw = self.preprocess_image(frame, threshhold=-40, ,verbose=True)
    frame_bbox = frame[bbox[1]:bbox[3], bbox[0]:bbox[2]]
    cv2.imshow("QRCode - bbox", frame_bbox) # LOG
    res, points = self.detector.detectAndDecode(frame_bbox)
    
    if len(res) > 0:
      print(res[0]) # output the first result
      # # draw lines around the QR code
      # n = len(points)
      # for i in range(n):
      #   cv2.line(frame_bbox, tuple(points[0][i]), tuple(points[0][(i+1)%n]), (255,0,0), 5)
      return res[0]
    
    return None

  def find_signs(self, frame): # either hazmat or qr code
    # preprocess the image
    frame_bw = self.preprocess_image(frame, threshhold=-35, removeBG=True, verbose=True)

    # detect the contours
    contours, _ = cv2.findContours(frame_bw, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

    # filter out the contours that are too small or too big
    contours = [cnt for cnt in contours if cv2.contourArea(cnt) > 2500 and cv2.contourArea(cnt) < 100000]

    # Find the squares
    squares = []
    for cnt in contours:
        x, y, w, h = cv2.boundingRect(cnt)
        approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt,True),True)
        aspect_ratio = float(w) / h
        if len(approx)==4 and aspect_ratio >= 0.7 and aspect_ratio <= 1.3:
            # it's a square
            squares.append(cnt)
      
    central_points = []
    # detect the type of the sign by the angle
    for cnt in squares:
      angle = cv2.minAreaRect(cnt)[2] # angle of the rotated rectangle that fits
      x, y, w, h = cv2.boundingRect(cnt)
      cx, cy = int(x + w/2), int(y + h/2)
      if y==0 or y+h==frame.shape[0]: # ignore the squeres on the top and bottom of the frame
        continue
      if (angle > 35 and angle < 55) or (angle>-55 and angle<-35): # 45+-10
        # sign is a hazmat sign
        cv2.drawContours(frame, [cnt], -1, (0, 255, 255), 1)
        txt = self.read_hazmat(frame, (x, y, x+w, y+h), threshhold=0)
        if txt:
          cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2) # blue rectangle
          cv2.putText(frame, f'Hazmat-{txt}', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)
        else:
          cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2) # red rectangle
          cv2.putText(frame, 'Hazmat', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)
        central_points.append({'type': 'hazmat', 'p': (cx, cy), 'txt': txt})
      else:
        # sign is supposed to a QR code
        # txt = self.read_qr(frame, (x, y, x+w, y+h))
        txt = self.read_qr_wechat(frame, (x, y, x+w, y+h))
        cv2.drawContours(frame, [cnt], -1, (0, 255, 255), 1)
        if txt:
          cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
          cv2.putText(frame, txt, (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)
        else:
          cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2) # red rectangle
          cv2.putText(frame, 'QR', (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36,255,12), 2)
        central_points.append({'type': 'qr', 'p': (cx, cy), 'txt': txt})

    return frame, central_points


  def detect_objects(self, frame):
    # combine detect_barrel and find_signs
    frame, sign_cp = self.find_signs(frame)
    frame, barrel_cp = self.detect_barrel(frame)

    # merge the two lists
    central_points = sign_cp + barrel_cp
    

    return frame, central_points





class camera_1:

  def __init__(self):
    self.image_sub = rospy.Subscriber(CAMERA_TOPIC, Image, self.callback)
    self.image_pub = rospy.Publisher(CAMERA_TOPIC + "_output", Image, queue_size=10)
    self.object_pub = rospy.Publisher(OBJECT_TOPIC, objectpx_msg, queue_size=10)

    hazmat_dir = rospy.get_param("/camera_read/hazmat_dir")
    # load the wechat qrcode detector
    model_path = rospy.get_param("/camera_read/wechat_dir")
    camreader = CameraReader(hazmat_dir, model_path)
    self.cameraReader = camreader

    
    print(f"camera_1 initilized on {CAMERA_TOPIC}")
  
  def publish_frame(self, frame):
    bridge = CvBridge()
    try:
      self.image_pub.publish(bridge.cv2_to_imgmsg(frame, "bgr8"))
    except CvBridgeError as e:
      rospy.logerr(e)

  def publish_objects(self, central_points, framesize):
      try:
        msg = objectpx_msg()
        msg.header.stamp = rospy.Time.now()
        msg.cx = [point['p'][0] for point in central_points]
        msg.cy = [point['p'][1] for point in central_points]
        msg.type = [point['type'] for point in central_points]
        msg.text = [point['txt'] if point['txt'] is not None else '' for point in central_points]
        msg.frame_w = framesize[0]
        msg.frame_h = framesize[1]
        self.object_pub.publish(msg)
      except Exception as e:
        rospy.logerr(e)

  def callback(self,data):
    bridge = CvBridge()

    try:
      cv_image = bridge.imgmsg_to_cv2(data, desired_encoding="bgr8")
    except CvBridgeError as e:
      rospy.logerr(e)
      return None

    # get frame width and height
    w, h = cv_image.shape[:2]
    
    frame, central_points = self.cameraReader.detect_objects(cv_image)

    cv2.imshow(f"Camera output", frame)
    # publish the data

    self.publish_frame(frame)
    self.publish_objects(central_points, framesize=(w, h))



    cv2.waitKey(3)
  

def main():  

  rospy.init_node('camera_read', anonymous=False)

  camera_1()


  

  try:
    rospy.spin()
  except KeyboardInterrupt:
    rospy.loginfo("Shutting down")

  cv2.destroyAllWindows()

if __name__ == '__main__':
    main()