
def generate_color_histogram(image, row, column):
    histogram = init_histogram()
    
    for i in range(row):
        for j in range(column):
            pixel = get_pixel(image, i, j)
            add_pixel_to_histogram(histogram, pixel)
    
    return normalize_histogram(histogram, row * column)

def init_histogram():
    red, green, blue = [0] * 256, [0] * 256, [0] * 256     
    return {'red': red, 'green': green, 'blue': blue }


def normalize_histogram(histogram, pixel_count):
    red, green, blue = extract_color_histograms_from_rgb_histogram(histogram)
    
    red[:] = [color_count / pixel_count for color_count in red]
    green[:] = [color_count / pixel_count for color_count in green]
    blue[:] = [color_count / pixel_count for color_count in blue]
    
    return histogram

def extract_color_histograms_from_rgb_histogram(histogram):
    return histogram['red'], histogram['green'], histogram['blue']    

def extract_rgb_from_pixel(pixel):
    return pixel['red'], pixel['green'], pixel['blue']

def add_pixel_to_histogram(histogram, pixel):
    red, green, blue = extract_rgb_from_pixel(pixel)
    histogram['red'][red] += 1
    histogram['green'][green] += 1
    histogram['blue'][blue] += 1


def get_pixel(image ,row, column):
    red =  image[row][column][0]
    green = image[row][column][1]
    blue = image[row][column][2]
    return {'red': red, 'green': green, 'blue': blue}