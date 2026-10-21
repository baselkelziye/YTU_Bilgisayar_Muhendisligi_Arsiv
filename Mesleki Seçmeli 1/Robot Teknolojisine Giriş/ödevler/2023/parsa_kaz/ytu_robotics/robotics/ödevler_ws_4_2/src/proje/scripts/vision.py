#!/usr/bin/env python3

import cv2
from pyzbar.pyzbar import decode
import numpy as np
import os


def detect_hazmat(frame, hazmat_images):
  try:
    # Using MatchTemplate to find the signs
    for sign_image in hazmat_images:
      # Apply template Matching
      res = cv2.matchTemplate(frame, sign_image, cv2.TM_CCOEFF_NORMED)
      threshold = 0.8
      loc = np.where(res >= threshold)
      for pt in zip(*loc[::-1]):
        cv2.rectangle(frame, pt, (pt[0] + 50, pt[1] + 50), (0, 0, 255), 2)
        cv2.putText(frame, "Hazmat", (pt[0], pt[1]-20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2, cv2.LINE_AA)
  except Exception as e:
    print(e)

def detect_objects(frame):
    # returns countours of the object
    kernel = np.ones((3,3), np.uint8)
    frame = cv2.dilate(frame, kernel, iterations=1)
    contours, _ = cv2.findContours(frame, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

    bbox = []
    for cnt in contours:
        x, y, w, h = cv2.boundingRect(cnt)
        area = cv2.contourArea(cnt)

        # filter out small objects
        if area/(w*h) > 0.5 and area > 100:
            # draw a blue rectangle on the object
            # cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
            bbox.append((x, y, x+w, y+h))

    cv2.imshow("Camera output - dialated", frame)
    return bbox


def preprocess_image(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    threshhold = 40
    _, bw = cv2.threshold(gray, threshhold, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

    # # detect all objects
    # bbox = detect_objects(bw)

    # for x, y, x2, y2 in bbox:
    #     # draw blue rectangle on the object
    #     cv2.rectangle(image, (x, y), (x2, y2), (255, 0, 0), 2)
    
    return bw, None #, bbox

def read_qrcode_zbar(frame):

    # frame_bw, _ = preprocess_image(frame)

    decodedObjects = decode(frame)

    for obj in decodedObjects:
        txt = obj.data.decode("utf-8")
        print(txt)

        (x, y, w, h) = obj.rect
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 8)
        cv2.putText(frame, txt, (x, y-20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
    
    return frame

def read_qrcode_with_bbox(frame):
    _, bbox = preprocess_image(frame)
    
    qrs = []
    for x, y, x2, y2 in bbox:
        # draw blue rectangle on the object
        cv2.rectangle(frame, (x, y), (x2, y2), (255, 0, 0), 2)

        roi = frame[y:y2, x:x2]
        decodedObjects = decode(roi)

        for obj in decodedObjects:
            txt = obj.data.decode("utf-8")
            print(txt)

            (x_local, y_local, w, h) = obj.rect
            x += x_local
            y += y_local
            
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 8)
            frame = cv2.putText(frame, txt, (x, y-20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
    
    return frame

def main():

    PATH = './'
    img_path = os.path.join(PATH, "img/")
    hazmat_images = []
    for image in os.listdir(img_path):
        hazmat_images.append(cv2.imread(img_path + image))


    cap = cv2.VideoCapture(0)
    while True:
        _, frame = cap.read()
        image = detect_hazmat(frame, hazmat_images)
        cv2.imshow("Camera output", image)
        cv2.waitKey(3) and 0xFF == ord('q')

if __name__ == '__main__':
    main()