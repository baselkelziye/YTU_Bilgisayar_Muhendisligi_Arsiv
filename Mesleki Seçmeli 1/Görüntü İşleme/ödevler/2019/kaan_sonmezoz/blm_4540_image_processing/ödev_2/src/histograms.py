import cv2

from color_histogram import generate_color_histogram 
from local_binary_pattern import generate_lbp_histogram
from file_operations import get_all_image_file_paths
from file_operations import write_to_json


def extract_histograms(source_path, destination_folder, file_name = "histograms.json"):
    image_histograms = create_histograms_for_all_images(source_path)
    
    write_to_json(destination_folder, file_name, image_histograms)

def create_histograms_for_all_images(folder_path):
    image_histograms = {'images': [] }
    image_paths = get_all_image_file_paths(folder_path)
    
    for i in range(len(image_paths)):
        print(i)
        
        histograms = create_histograms(image_paths[i])
        
        image_histograms['images'].append({
            'path': image_paths[i],
            'histograms': histograms
        })
    
    return image_histograms    
        

def create_histograms(file_path):
    image_rgb, row_rgb, column_rgb = read_image_rgb(file_path)
    image_gray,row_gray, column_gray = read_image_grayscale(file_path)
    
    rgb_histogram = generate_color_histogram(image_rgb, row_rgb, column_rgb)
    lbp_histogram = generate_lbp_histogram(image_gray, row_gray, column_gray)
    
    return { 'rgb':rgb_histogram, 'lbp': lbp_histogram }
    
def read_image_rgb(file_path):
    image = cv2.imread(file_path, cv2.IMREAD_COLOR)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    return image, image.shape[0], image.shape[1] 


def read_image_grayscale(file_path):
    image = cv2.imread(file_path, cv2.IMREAD_COLOR)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    return image, image.shape[0], image.shape[1]
