import os
import json

from histograms import extract_histograms
from file_operations import get_all_image_file_paths
from file_operations import write_to_json
from histograms import create_histograms

TEST_IMAGES_PATH = "../data/test"
HISTOGRAM_FILE_NAME = "histograms.json"
TRAIN_IMAGES_PATH = "../data/train"

HISTOGRAM_PATH = os.path.realpath(TRAIN_IMAGES_PATH) + "/" + HISTOGRAM_FILE_NAME



def find_the_most_similar_five_images_for_the_all_images(train_images):
    most_similar_images = {'images': []}
    
    test_image_paths = get_all_image_file_paths(TEST_IMAGES_PATH)
    
    for i in range(len(test_image_paths)):
        rgb_most_similar, lbp_most_similar = find_the_most_similar_five_images(test_image_paths[i], train_images) 
        most_similar_images['images'].append({
                'path': test_image_paths[i],
                'rgb': rgb_most_similar,
                'lbp': lbp_most_similar
        })
    
    return most_similar_images
    
    


def find_the_most_similar_five_images(test_image_path, train_images): ## returns in ascending order
    train_file_paths, train_histograms = extract_file_paths_and_histograms(train_images)
    
    print("File_paths and histograms extracted !")
    
    rgb_distances, lbp_distances = calculate_all_manhattan_distances_for(test_image_path, train_histograms)

    rgb_indices = []
    lbp_indices = []
    
    rgb_least_similar_files = []
    lbp_least_similar_files = []
    
    rgb_indices = sort_ascending_order(rgb_distances)
    lbp_indices = sort_ascending_order(lbp_distances)
    
    for i in range(5):
        rgb_least_similar_files.append(train_file_paths[rgb_indices[i]])
        lbp_least_similar_files.append(train_file_paths[lbp_indices[i]])
    
    
    
    return rgb_least_similar_files, lbp_least_similar_files
        

def sort_ascending_order(distances):
    indices = []
    
    for i in range(len(distances) - 1):
        min_value = distances[i]
        min_index = i
        
        for j in range(i+1, len(distances)):
            if min_value >= distances[j] and not j in indices: 
                min_index = j
                min_value = distances[j]
        
        indices.append(min_index)
    
    return indices            
        

def extract_file_paths_and_histograms(train_images):
    file_paths = []
    histograms = []
    
    for i in range(len(train_images)):
        file_paths.append(train_images[i]['path'])
        histograms.append({
        'rgb': train_images[i]['histograms']['rgb'],
        'lbp': train_images[i]['histograms']['lbp'],
    })
    
    return file_paths, histograms

def calculate_all_manhattan_distances_for(test_image_path, train_histograms):
    rgb_distances = []
    lbp_distances = []
    
    for i in range(len(train_histograms)):
        print("Calculating distance histogram: " + str(i+1))
        print("Total histogram: " + str(len(train_histograms)))
        distances = calculate_manhattan_distance(test_image_path, train_histograms[i])
        rgb_distances.append(distances['rgb'])
        lbp_distances.append(distances['lbp'])
    
    return rgb_distances, lbp_distances


def calculate_manhattan_distance(test_image_path, histogram):    
    test_histogram = create_histograms(test_image_path)
    
    test_lbp_histogram, test_rgb_histogram = test_histogram['lbp'], test_histogram['rgb']
    lbp_histogram, rgb_histogram = histogram['lbp'], histogram['rgb']
    
    
    return {
            'rgb': calculate_manhattan_distance_for_rgb(test_rgb_histogram, rgb_histogram),
            'lbp': calculate_manhattan_distance_for_lbp(test_lbp_histogram, lbp_histogram)
    }
    

def calculate_manhattan_distance_for_rgb(rgb_histogram1, rgb_histogram2):
    red_distance, green_distance, blue_distance  = 0, 0, 0
    
    color_levels = len(rgb_histogram1['red'])
    
    for i in range(color_levels):
        red_distance += abs(rgb_histogram1['red'][i] - rgb_histogram2['red'][i])
        green_distance += abs(rgb_histogram1['green'][i] - rgb_histogram2['green'][i])
        blue_distance += abs(rgb_histogram1['blue'][i] - rgb_histogram2['blue'][i])
    
    return red_distance + green_distance + blue_distance
    

def calculate_manhattan_distance_for_lbp(lbp_histogram_1, lbp_histogram_2):
    lbp_distance = 0
    
    
    for i in range(len(lbp_histogram_1)):
        lbp_distance += abs(lbp_histogram_1[i] - lbp_histogram_2[i])
    
    return lbp_distance
    

if not os.path.exists(HISTOGRAM_PATH):
    print("Started creating histograms !")
    extract_histograms(TRAIN_IMAGES_PATH, TRAIN_IMAGES_PATH, HISTOGRAM_FILE_NAME)


with open(TRAIN_IMAGES_PATH + "/" + HISTOGRAM_FILE_NAME) as json_file:
    print("Histograms have been already created !.")
    train_images = json.load(json_file)['images']


most_similar_images = find_the_most_similar_five_images_for_the_all_images(train_images)

write_to_json(TEST_IMAGES_PATH, "result.json", most_similar_images)

with open(TEST_IMAGES_PATH + "/result.json") as json_file:
    results = json.load(json_file)['images']

accuracy = {'accordion': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} },
            'dalmatian': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} },
            'water_lilly': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} },
            'dolphin': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} },
            'wild_cat': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} },
            'leopards': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} },
            'schooner': {'lbp': {'true': 0, 'false': 0}, 'rgb': {'true': 0, 'false': 0} }
           }

for i in range(len(results)):
    className = results[i]["path"].split("/")[-2]
    
    if any(className in result for result in results[i]["lbp"]):
        accuracy[className]["lbp"]["true"] +=1
    else:
        accuracy[className]["lbp"]["false"] +=1
        
    if any(className in result for result in results[i]["rgb"]):
        accuracy[className]["rgb"]["true"] +=1
    else:
        accuracy[className]["rgb"]["false"] +=1

write_to_json(TEST_IMAGES_PATH, "result_accuracy.json", accuracy)
