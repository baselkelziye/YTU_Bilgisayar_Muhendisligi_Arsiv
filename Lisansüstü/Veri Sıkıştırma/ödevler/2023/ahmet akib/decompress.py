from tqdm import tqdm
import numpy as np
import cv2
from compress import get_iterate_num



def image_decompress(raw_file_address):

    # read raw data
    raw_data = np.array([], dtype=np.uint8)
    with open(raw_file_address, "rb") as f:
        img_height = int.from_bytes(f.read(2), "big")
        img_width = int.from_bytes(f.read(2), "big")
        img_mode = int.from_bytes(f.read(1), "big")
        raw_data = np.frombuffer(f.read(), dtype=np.uint8)

    img_format = img_mode // 3
    iterate_format = img_mode % 3

    composer = GB_composer_arr[iterate_format][1]
    
    #case 255

    if img_format == 0:
        #extend data to 800x800 flatten
        #   note that data start with white [255]
        middle_data = open_data_BW(raw_data)
        current_color = 255
        flat_image = np.array([],np.uint64)
        sil = 0
        for i in tqdm(middle_data):
            sil += i
            temp_array = np.array([current_color] * i,np.uint64)
            flat_image = np.append(flat_image, temp_array)
            current_color = 255 - current_color

    elif img_format == 1:
        flat_image = open_data_GS(raw_data)
        flat_image = np.append(flat_image, 0)




    #compose flat data to image
    img = composer(flat_image, img_height, img_width)
    return img



#composer functions
def decompose_by_row_rotate(data,rows,cols): 
    
    decompressed_image = np.zeros((rows, cols), dtype=np.uint8)

    for i in range(rows):
        if i % 2 == 0:
            decompressed_image[i, :] = data[i*cols:((i+1)*cols)]
        else:
            decompressed_image[i, :] = data[i*cols:((i+1)*cols)][::-1]

    return decompressed_image

def decompose_by_column_rotate(data,rows,cols):
    decompressed_image = np.zeros((rows, cols), dtype=np.uint8)

    for i in range(cols):
        if i % 2 == 0:
            decompressed_image[:, i] = data[i*rows:((i+1)*rows):1]
        else:
            decompressed_image[:, i] = data[i*rows:((i+1)*rows)][::-1]

    return decompressed_image

def decompose_by_zigzag(data, rows, cols):
    decompressed_image = np.zeros((rows, cols), dtype=np.uint8)
    index = 0  # Add this line

    for i in range(rows + cols - 1):
        if i % 2 == 0:
            for row in range(max(0, i - cols + 1), min(i + 1, rows)):
                decompressed_image[row, i - row] = data[index]  # Use index
                index += 1  # Update index
        else:
            for col in range(max(0, i - rows + 1), min(i + 1, cols)):
                decompressed_image[i - col, col] = data[index]  # Use index
                index += 1  # Update index

    return decompressed_image

GB_composer_arr = [("row_rotate",decompose_by_row_rotate), ("column_rotate",decompose_by_column_rotate), ("zigzag",decompose_by_zigzag)]
#end composer functions

def open_data_BW(raw_data): #open matris for 255 case
    tmp_sum = 0
    middle_data = np.array([])
    for i in raw_data:
        if i == 255:
            tmp_sum += 255
        else:
            tmp_sum += i
            middle_data = np.append(middle_data, tmp_sum)
            tmp_sum = 0
    if tmp_sum != 0:
        middle_data = np.append(middle_data, tmp_sum)
    return middle_data.astype(int)
        
# def open_data_GS(raw_data):

#     max_iter = len(raw_data)  # Maksimum iterasyon sayısı
#     pbar = tqdm(total=max_iter, desc="Process")

#     i = 0
#     val = 0
#     middle_data = np.array([])
#     while i < len(raw_data):
#         percent_complete = (i / max_iter) * 100
#         pbar.set_postfix({"% Done": percent_complete}, refresh=True)
#         pbar.update(1)  # Progress bar'ı güncelle
        
#         val = raw_data[i]
#         z_count = 0
#         while val == 0:
#             z_count += 1
#             i += 1
#             val=raw_data[i]
#         if (z_count // 2) > 0:
#             tmp_array = np.array([0] * (z_count // 2))
#             middle_data = np.append(middle_data, tmp_array)
#         if z_count % 2 == 1:
#             tmp_sum = 0
#             while val == 255:
#                 tmp_sum += 255
#                 i += 1
#                 val = raw_data[i]
            
#             tmp_sum += val
#             i += 1
#             val = raw_data[i]
#             tmp_array = np.array([val] * tmp_sum    )
#             middle_data = np.append(middle_data, tmp_array)
#         else:
#             #singular case
#             middle_data = np.append(middle_data, val)
#         i += 1
#     return middle_data.astype(int)

def open_data_GS(raw_data):
    max_iter = len(raw_data)
    pbar = tqdm(total=max_iter, desc="Process")

    i = 0
    middle_data = []
    while i < len(raw_data):
        percent_complete = (i / max_iter) * 100
        pbar.set_postfix({"% Done": percent_complete}, refresh=True)
        pbar.update(1)

        val = raw_data[i]
        z_count = 0

        while val == 0:
            z_count += 1
            i += 1
            val = raw_data[i]

        if (z_count // 2) > 0:
            middle_data.extend([0] * (z_count // 2))

        tmp_sum = 0
        if z_count % 2 == 1:
            while val == 255:
                tmp_sum += 255
                i += 1
                val = raw_data[i]
            tmp_sum += val
            i += 1

        middle_data.extend([val] * tmp_sum if tmp_sum else [val])

        i += 1

    pbar.close()
    return np.array(middle_data, dtype=int)     

        


            

if __name__ == "__main__":
    parent_file = "compressed_files1/"
    iterator_names = ["row_rotate", "column_rotate", "zigzag"]
    iterator_id = get_iterate_num()
    raw_file_address = parent_file + iterator_names[iterator_id] + "_compressed.dat"

    decompressed_image = image_decompress(raw_file_address)

    cv2.imwrite('decompressed_image.png', decompressed_image)

    # Görselleştirme
    cv2.imshow('Decompressed Image', decompressed_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
