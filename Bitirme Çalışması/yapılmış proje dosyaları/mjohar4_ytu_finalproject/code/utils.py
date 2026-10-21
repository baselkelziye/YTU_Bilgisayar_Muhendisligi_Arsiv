import numpy as np
import matplotlib.pyplot as plt
import os
from PIL import Image
from keras import backend as K
import tensorflow as tf
import cv2
import pandas as pd
import math

from patchify import patchify,unpatchify
import tifffile as tif
from tqdm import tqdm
import time
from datetime import datetime
import datetime as dt
import pyvips


def get_patchifiable(img, patch_size=512):
  # Get the shape of the input image
  img_shape = img.shape
  
  # Calculate the output height and width based on the patch size
  out_h = img_shape[0] - (img_shape[0] - patch_size) % patch_size
  out_w = img_shape[1] - (img_shape[1] - patch_size) % patch_size
  
  # Crop the image to the calculated output dimensions
  img = img[:out_h, :out_w]
  return img

def get_scaled_with_width(img, width, show=False):
  # Calculate the new height based on the desired width while maintaining the original aspect ratio
  height = int(img.shape[0] * width / img.shape[1])

  # Define the dimensions of the resized image as a tuple (width, height)
  dim = (width, height)

  # Resize the image using the calculated dimensions and the INTER_AREA interpolation method
  resized = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)

  # If the `show` flag is set to True, display the resized image using OpenCV
  if show:
    cv2.imshow("resized", resized)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

  # Return the resized image
  return resized

def show_scaled_image(img, scale_percent, img_show=True, shapes_show=False, return_scaled=False):
  # If shapes_show flag is True, print the original dimensions of the image
  if shapes_show:
    print('Original Dimensions:', img.shape)
  
  # Calculate the new width and height based on the scale percentage
  width = int(img.shape[1] * scale_percent / 100)
  height = int(img.shape[0] * scale_percent / 100)
  
  # Define the dimensions of the resized image as a tuple (width, height)
  dim = (width, height)
    
  # Resize the image using the calculated dimensions and the INTER_AREA interpolation method
  resized = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)
  
  # If shapes_show flag is True, print the dimensions of the resized image
  if shapes_show:
    print('Resized Dimensions to show:', resized.shape)
  
  # If img_show flag is True, display the resized image using OpenCV
  if img_show:
    cv2.imshow("resized", resized)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
  if return_scaled:
    return resized

def get_iou(gt, mask, text, return_val=False):
    # Ensure both masks have the same size
    if gt.shape != mask.shape:
        print(f'mask1.shape: {gt.shape}, mask2.shape: {mask.shape}')
        raise ValueError("Mask shapes do not match")

    # Compute the intersection and union areas
    intersection = cv2.bitwise_and(gt, mask)
    union = cv2.bitwise_or(gt, mask)

    # Calculate the false negative (FN) mask
    FN = get_scaled_with_width(cv2.bitwise_xor(gt, intersection), 1200)

    # Calculate the false positive (FP) mask
    FP = get_scaled_with_width(cv2.bitwise_xor(mask, intersection), 1200)

    # Calculate the true positive (TP) mask
    TP = get_scaled_with_width(intersection, 1200)

    # Combine FP, TP, and FN masks into a single BGR image
    result_BGR = np.dstack((FP, TP, FN))

    # Overlay the intersection mask on the result image
    icolor = get_scaled_with_width(np.dstack((intersection, gt, intersection)), 1200)
    result_BGR = cv2.addWeighted(result_BGR, 0.7, icolor, 0.5, 0)

    # Calculate the IOU mask by blending the union and intersection masks
    iou_mask = cv2.addWeighted(union, 0.5, intersection, 0.5, 0)

    # Calculate the IOU value
    iou = np.count_nonzero(intersection) / np.count_nonzero(union)

    # Set the font and thickness scales based on image dimensions
    FONT_SCALE = 9e-4
    THICKNESS_SCALE = 9e-4

    height, width = result_BGR.shape[:-1]
    font_scale = min(width, height) * FONT_SCALE
    thickness = math.ceil(min(width, height) * THICKNESS_SCALE)

    # Add the IOU value and text to the result image
    result = cv2.putText(result_BGR, f'IOU: {round(iou, 3)}, {text}', (60, 60),
                         cv2.FONT_HERSHEY_SIMPLEX, font_scale, (20, 20, 255), thickness, cv2.LINE_AA)

    # Display the result image
    show_scaled_image(result, 100, img_show=False)
    print('IOU:', iou)

    # Return the IOU value, result image, and IOU mask if requested
    if return_val:
        return iou, result, iou_mask

def unet_evaluate(model, img, pixel_threshold=0.5):
  # Get patchifiable image
  img = get_patchifiable(img)
  
  # Create an empty mask
  mask = img.copy()
  mask = mask[:,:,0]*0
  
  # Patchify the image and mask
  patches_images = patchify(img, (512, 512, 3), step=512)
  masks_matrix = patchify(mask, (512, 512), step=512)
  
  # Iterate over patches
  for row in tqdm(range(patches_images.shape[0])):
    for col in range(patches_images.shape[1]):
      # Get single patch image
      single_img = patches_images[row, col, 0]
      
      # Normalize the image
      X_test = single_img / 255
      
      # Predict the mask using the model
      pred = model.predict(np.expand_dims(X_test, 0), verbose=0)
      
      # Apply pixel thresholding to obtain binary mask
      msk = pred.squeeze()
      msk[msk >= pixel_threshold] = 255
      msk[msk < pixel_threshold] = 0
      
      # Store the predicted mask in the masks matrix
      masks_matrix[row, col] = msk

  # Unpatchify the masks matrix to obtain the final mask
  mask = unpatchify(masks_matrix, mask.shape)
  
  return mask

def whole_img_iou(img_row, model, pix_acc_th, result_df):
    data_row = []
    # Append image file information to the data row
    data_row.append(img_row['img_file'])
    data_row.append(img_row['img_dims'])
    data_row.append(model['name'])
    data_row.append(model['trained_dataset_range'])
    data_row.append(pix_acc_th)

    # Read the image and ground truth
    im = cv2.imread(img_row['img_path'], cv2.IMREAD_COLOR)
    np_img = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    gt = pyvips.Image.tiffload(img_row['gt_path'])
    np_gt = gt.numpy()

    # Preprocess the image and ground truth
    np_gt = get_patchifiable(np_gt)
    np_img = get_patchifiable(np_img)

    # Evaluate the model on the image
    start_time = datetime.now()
    mask = unet_evaluate(model['model'], np_img, pixel_threshold=pix_acc_th)
    end_time = datetime.now()
    duration = end_time - start_time
    dt_string = start_time.strftime("%d/%m/%Y %H:%M:%S")

    # Calculate the IOU
    iou, result, iou_mask = get_iou(np_gt, mask,
                                    f"{model['name']}[{model['trained_dataset_range'][0]},{model['trained_dataset_range'][1]}], px_th:{pix_acc_th}",
                                    return_val=True)

    # Append IOU and time information to the data row
    data_row.append(round(iou, 4))
    data_row.append(dt_string)
    data_row.append(str(dt.timedelta(seconds=duration.total_seconds())))

    # Append the data row to the result dataframe
    result_df.loc[len(result_df)] = data_row

    # Print the data row
    print(data_row)

    return result, mask, result_df

def mean_iou(y_true, y_pred):
    # Extract the first channel of the true mask
    yt0 = y_true[:,:,:,0]
    
    # Threshold the predicted mask with a value of 0.7
    yp0 = K.cast(y_pred[:,:,:,0] > 0.7, 'float32')
    
    # Calculate the intersection and union of pixels
    inter = tf.math.count_nonzero(tf.logical_and(tf.equal(yt0, 1), tf.equal(yp0, 1)))
    union = tf.math.count_nonzero(tf.add(yt0, yp0))
    
    # Calculate the IOU
    iou = tf.where(tf.equal(union, 0), 1., tf.cast(inter/union, 'float32'))
    
    return iou

def dice_loss(y_true, y_pred):
    smooth = 1e-5
    
    # Calculate the intersection and union of pixels
    intersection = K.sum(y_true * y_pred, axis=[1, 2, 3])
    union = K.sum(y_true, axis=[1, 2, 3]) + K.sum(y_pred, axis=[1, 2, 3])
    
    # Calculate the Dice coefficient
    dice_coef = K.mean((2.0 * intersection + smooth) / (union + smooth), axis=0)
    
    # Calculate the Dice loss
    dice_loss = 1.0 - dice_coef
    
    return dice_loss

# to find the countors
def contourIntersect(original_image, contour1, contour2):
    # Two separate contours trying to check intersection on
    contours = [contour1, contour2]

    # Create image filled with zeros the same size of original image
    blank = np.zeros(original_image.shape[0:2])

    # Copy each contour into its own image and fill it with '1'
    image1 = cv2.drawContours(blank.copy(), contours, 0, 1)
    image2 = cv2.drawContours(blank.copy(), contours, 1, 1)

    # Use the logical AND operation on the two images
    # Since the two images had bitwise and applied to it,
    # there should be a '1' or 'True' where there was intersection
    # and a '0' or 'False' where it didnt intersect
    intersection = np.logical_and(image1, image2)

    # Check if there was a '1' in the intersection
    return intersection.any()


def get_circular_kernel(diameter):

    mid = (diameter - 1) / 2
    distances = np.indices((diameter, diameter)) - np.array([mid, mid])[:, None, None]
    kernel = ((np.linalg.norm(distances, axis=0) - mid) <= 0).astype(np.uint8)

    return kernel

def get_border(img):
    # Apply Gaussian blur to the image
    im = cv2.GaussianBlur(img, (5, 5), 0)

    # Apply median blur to the image
    im = cv2.medianBlur(img, 31)

    # Apply thresholding to create a binary image
    ret, th1 = cv2.threshold(im, 210, 255, cv2.THRESH_BINARY)

    # Apply morphological opening operation with circular kernel
    th1 = cv2.morphologyEx(th1, cv2.MORPH_OPEN, get_circular_kernel(55))

    # Find external contours in the thresholded image
    contours_th1, hierarchy_th1 = cv2.findContours(th1, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Compute areas of contours
    areas = [cv2.contourArea(c) for c in contours_th1]

    # Find the contour with the maximum area
    th1_max_index = np.argmax(areas)

    # Clear the thresholded image
    th1 = th1 * 0

    # Draw the contour with the maximum area on the thresholded image
    th1 = cv2.drawContours(th1, contours_th1, th1_max_index, 255, -1)

    # Create a kernel for morphological operations
    kernel = np.ones((455, 455), np.uint8)

    # Apply morphological gradient operation using the kernel
    gradient = cv2.morphologyEx(th1, cv2.MORPH_GRADIENT, kernel, borderType=cv2.BORDER_ISOLATED)

    # Perform bitwise AND operation between the inverted thresholded image and the gradient image
    border = cv2.bitwise_and(cv2.bitwise_not(th1), gradient)

    return border

def get_processed_predMask(row):
    # Load the image and prediction from the specified paths
    image = get_patchifiable(cv2.imread(row['img_path']))
    pred = get_patchifiable(cv2.imread(row['pred_path'], 0))
    
    # Convert the image to grayscale
    gray_img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Get the border of the grayscale image
    border = get_patchifiable(get_border(gray_img))
    
    # Find the external contours in the border image
    contours_ref, hierarchy_ref = cv2.findContours(border, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Find the external contours in the prediction image
    contours_query, hierarchy_query = cv2.findContours(pred, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Compute areas of reference contours
    areas = [cv2.contourArea(c) for c in contours_ref]
    
    # Find the index of the contour with the maximum area
    max_index = np.argmax(areas)
    
    # Get the contour with the maximum area
    cnt_ref = contours_ref[max_index]
    
    # Define a threshold area for filtering contours
    threshold_area = 3500
    
    # Create a list to store the indices of big contours
    big_contours_idx_list = []
    
    # Filter contours based on their area
    for i, cnt in enumerate(contours_query):
        area = cv2.contourArea(cnt)
        if area > threshold_area:
            big_contours_idx_list.append(i)
    
    print('search for intersect in', len(big_contours_idx_list), 'contours')
    
    # Create a list to store the filtered contour indices
    filtered_idx_list = []
    
    # Iterate over the big contours and check for intersection with the reference contour
    for idx in tqdm(big_contours_idx_list):
        result = contourIntersect(image, cnt_ref, contours_query[idx])
        if result:
            filtered_idx_list.append(idx)
    
    # Draw the filtered contours on the image
    for i in filtered_idx_list:
        cv2.drawContours(image, contours_query, i, (0, 0, 255), 20)
    
    # Extract the filtered contours
    contours_f = [contours_query[i] for i in filtered_idx_list]
    
    # Create a mask with zeros
    mask_res = np.zeros(image.shape[0:2])
    
    # Draw the filtered contours on the mask
    mask_res_1ch = cv2.drawContours(mask_res, contours_f, -1, (255), -1).astype('uint8')
    
    return mask_res_1ch

def get_merged_img(image, msk):
    # Convert image and mask to unsigned 8-bit integers
    image = image.astype(np.uint8)
    msk = msk.astype(np.uint8)
    # Convert mask to a 3-channel image by stacking the mask along the last axis
    msk = np.stack((msk,)*3, axis=-1)
    # Blend the image and mask using weighted addition
    final_result = cv2.addWeighted(image, 0.4, msk, 0.6, 0)
    
    return final_result

def calculate_iou_processed_mask(row):
    # Load the ground truth and before-processed mask
    np_gt = cv2.imread(row['gt_path'], 0)
    before_processed_msk = cv2.imread(row['pred_path'], 0)
    
    # Apply patchification to the ground truth
    np_gt = get_patchifiable(np_gt)
    
    # Calculate IoU and other metrics for the before-processed mask
    iou_before, result_before, _ = get_iou(np_gt, before_processed_msk, f"{row['models_name']}", return_val=True)
    
    # Get the processed mask using the provided function
    processed_msk = get_processed_predMask(row)
    
    # Calculate IoU and other metrics for the processed mask
    iou_after, result_after, _ = get_iou(np_gt, processed_msk, f"{row['models_name']}", return_val=True)
    
    return iou_before, result_before, iou_after, result_after, processed_msk