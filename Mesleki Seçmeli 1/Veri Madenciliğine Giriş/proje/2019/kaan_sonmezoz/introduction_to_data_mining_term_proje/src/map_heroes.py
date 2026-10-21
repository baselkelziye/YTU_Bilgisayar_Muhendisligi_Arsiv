import json
import os
import csv

HEROES_FILE_PATH = "../data/heroes.json"
TEST_DATASET_PATH = "../data/dota2Dataset/dota2Test.csv"
TRAIN_DATASET_PATH = "../data/dota2Dataset/dota2Train.csv"

OUTPUT_FOLDER = "../data/with-headers"

def extract_file_name_from_path(file_path):    
    return os.path.basename(file_path)

def get_headers():
    headers = ["team_won", "cluster_id", "game_mode", "game_type"]
    
    with open(HEROES_FILE_PATH) as json_file:
        heroes = json.load(json_file)['heroes']
    
    hero_count = len(heroes)
    print(hero_count)
    
    for i in range(hero_count):
        headers.append(heroes[i]['name'])
    
    return headers
    
def add_headers_to_file(input_path, headers, output_path):
    with open(output_path, 'w', newline = '') as output:
        writer = csv.writer(output)
        writer.writerow(headers)
        
        with open(input_path, 'r', newline = '') as input_file:
            reader = csv.reader(input_file)
            writer.writerows(row for row in reader)
    

if not os.path.exists(OUTPUT_FOLDER):
    os.makedirs(OUTPUT_FOLDER)

test_file_name = extract_file_name_from_path(TEST_DATASET_PATH)
train_file_name = extract_file_name_from_path(TRAIN_DATASET_PATH)
headers = get_headers()

add_headers_to_file(TEST_DATASET_PATH, headers, OUTPUT_FOLDER + "/" + test_file_name)
add_headers_to_file(TRAIN_DATASET_PATH, headers, OUTPUT_FOLDER + "/" + train_file_name)
            
    



