import os
import json
from keras.preprocessing.image import load_img, img_to_array
import pandas as pd

CONFIG_FILE_PATH = "./config.json"
IMAGE_FOLDER_PATH = "../data/oxbuild_images"

def read_config_file():
    with open(CONFIG_FILE_PATH, 'r') as json_file:
        configs = json.load(json_file)
    
    return configs

def read_image(image_path, image_size):    # image_size = (height, width)
    image = load_img(image_path, target_size = image_size)    
    return img_to_array(image)


def read_all_images(image_size):
    image_df = pd.DataFrame(columns = ['label', 'image'])
    read_count = 1
    files = os.listdir(IMAGE_FOLDER_PATH)
    for file in files:
        print("Reading file " + file)
        label = extract_class_label(file)
        image = read_image(IMAGE_FOLDER_PATH + '/' + file, image_size)
        
        normalize_image(image)
        
        image_df = image_df.append({"image": image, "label": label}, ignore_index = True)
        print("Finished reading ! Remaining: " + str(len(files) - read_count))
        read_count += 1
        
    return image_df
    
    
def extract_class_label(file_name):
    return "_".join(file_name.split("_")[:-1])

def normalize_image(image):
    for i in range(image.shape[0]):         ## height
        for j in range(image.shape[1]):     ## width
            image[i][j][0] /= 255
            image[i][j][1] /= 255
            image[i][j][2] /= 255
    
            
images = read_all_images('../data/oxbuild_images', (300, 300))