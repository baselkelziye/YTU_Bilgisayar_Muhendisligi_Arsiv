import mimetypes
import os
import json


def get_all_image_file_paths(folder_path):
    file_paths = []
    
    for root, directories, files in os.walk(folder_path):
        for file in files:
            if is_file_image(file):
                file_paths.append(root + "/" + file)
    
    return file_paths

def is_file_image(file):
    mimetype = mimetypes.guess_type(file)[0]
    
    if mimetype is None:
        return False
    
    return "image" in mimetype

def write_to_json(destination_folder, file_name, data):
    if not os.path.exists(destination_folder):
        os.makedirs(destination_folder)
    
    with open(destination_folder + "/" + file_name, "w") as json_file:
        json.dump(data, json_file, indent = 2)