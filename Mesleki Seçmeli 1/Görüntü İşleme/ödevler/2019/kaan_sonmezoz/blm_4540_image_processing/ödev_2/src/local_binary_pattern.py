def generate_lbp_histogram(image, row_count, column_count):
    histogram = init_histogram()    
    count = 0
    
    for center_row in range(1, row_count - 1):
        for center_column in range(1, column_count - 1):
            add_pixel_to_histogram(histogram, image, center_row, center_column)
            count += 1
    
    return normalize_histogram(histogram, count)
    

def init_histogram():
    return [0] * 256

def get_pixel(image ,row, column):
    return image[row][column]


def add_pixel_to_histogram(histogram, image, row, column):
    center_pixel = get_pixel(image, row + 1, column + 1)
    neighbours = extract_neighbour_pixels(image, row, column)
    encoding = generate_binary_encoding(neighbours, center_pixel)
    index = binary_encoding_to_int(encoding)
    histogram[index] += 1



"""
        
        Bir resmin pixeldekilerinin numaralandirilmasi
        bu numaralandırılma listedeki indisine denk düşer ve aynı
        zamanda ikinin kuvvetine denk düşer
    

            +---+---+---+
            | 0 | 1 | 2 |
            +---+---+---+
            | 3 |   | 4 |
            +---+---+---+
            | 5 | 6 | 7 |
            +---+---+---+
            


"""


def extract_neighbour_pixels(image, center_row, center_column):
    neighbour_pixels = []
    
    left_upper_pixel = get_pixel(image, center_row - 1, center_column - 1)
    center_upper_pixel = get_pixel(image, center_row - 1, center_column)
    right_upper_pixel = get_pixel(image, center_row - 1, center_column + 1)
    
    left_pixel = get_pixel(image, center_row, center_column - 1)
    right_pixel = get_pixel(image, center_row, center_column + 1)
    
    left_lower_pixel = get_pixel(image, center_row + 1, center_column - 1)
    center_lower_pixel = get_pixel(image, center_row + 1, center_column)
    right_lower_pixel = get_pixel(image, center_row + 1, center_column + 1)
    
    neighbour_pixels.append(left_upper_pixel)
    neighbour_pixels.append(center_upper_pixel)
    neighbour_pixels.append(right_upper_pixel)
    neighbour_pixels.append(left_pixel)
    neighbour_pixels.append(right_pixel)
    neighbour_pixels.append(left_lower_pixel)
    neighbour_pixels.append(center_lower_pixel)
    neighbour_pixels.append(right_lower_pixel)
    
    return neighbour_pixels

def generate_binary_encoding(neighbour_pixels, center_pixel):
    encoding = ""
    
    for i in range(len(neighbour_pixels)):
        binary = compare_neighbour_to_center(neighbour_pixels[i], center_pixel)
        encoding = encoding + binary
    
    return encoding
    
def compare_neighbour_to_center(neighbour, center):
     return "1" if center >= neighbour else "0"

def binary_encoding_to_int(encoding):
    value = 0
    
    bit_length = len(encoding)
    
    for i in range(bit_length):
        multiplier = 2 ** i
        value += int(encoding[i]) * multiplier
    
    return value

def normalize_histogram(histogram, total_pixel_count):
    histogram[:] = [pixel_count / total_pixel_count for pixel_count in histogram]
    
    return histogram
