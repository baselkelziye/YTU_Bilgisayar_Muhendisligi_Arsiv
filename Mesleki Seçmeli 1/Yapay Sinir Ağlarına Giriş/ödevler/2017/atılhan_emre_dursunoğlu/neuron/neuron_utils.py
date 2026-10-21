import os

from PIL import Image
import numpy as np

#gets images from directory and returns images as numpy array, associated classes and all of the classes
def get_images_as_inputs(directory, input_count):
    images = os.listdir(directory)

    total_classes = 0
    classes = dict()

    _inputs = []
    outputs = []

    #get filenames
    for filename in images:
        class_name = filename.split(" ")[0]

        if class_name not in classes:
            classes[class_name] = total_classes
            total_classes += 1

        outputs.append(classes[class_name])
        file_dir = os.path.join(directory, filename)
        _inputs.append(np.append(read_as_bw(file_dir, input_count), 1))


    return _inputs, outputs, classes


def read_as_bw(filename, input_count):
    col = Image.open(filename)
    gray = col.convert('L')

    # Let numpy do the heavy lifting for converting pixels to pure black or white
    bw = np.asarray(gray).copy()

    # Pixel range is 0...255, 256/2 = 128
    bw[bw < 128] = 0    # Black
    bw[bw >= 128] = 1   # White

    return np.resize(bw, input_count)



