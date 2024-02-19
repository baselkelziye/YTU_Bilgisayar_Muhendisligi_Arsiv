import cv2
import numpy as np
from tqdm import tqdm 
from iterators import zigzag_iterator, row_rotate_iterator, column_rotate_iterator

DEBUG = True
img_num = 1
iterate_num = 1

def image_compressor(input_image_path, output_file_path, mode : int, pattern_iterator):
    # BMP resmini yükleyin
    
    compressed_data = np.array([], dtype=np.uint8)

    image_mode = mode // 3
    if image_mode < 2:
        bmp_image = cv2.imread(input_image_path, cv2.IMREAD_GRAYSCALE)
    else:
        bmp_image = cv2.imread(input_image_path)
    if image_mode == 0: #for B&W

        matris_iterator = pattern_iterator(bmp_image)

        current_color = 255
        count = 0

        
        for px_val in tqdm(matris_iterator):
            if px_val == current_color:
                count += 1
            else:
                while count >= 255:
                    compressed_data = np.append(compressed_data,np.uint8(255))
                    count -= 255
                compressed_data = np.append(compressed_data,np.uint8(count))
                current_color = px_val
                count = 1

        while count > 255:
            compressed_data = np.append(compressed_data,np.uint8(255))
            count -= 255
        
        compressed_data = np.append(compressed_data,np.uint8(count))  
    

    elif image_mode == 1: #for grayscale

        matris_iterator = pattern_iterator(bmp_image)

        
        current_color = bmp_image[0,0]
        count = 0

        #special character is 0. Its show that next value is pixel value if next value is not 0 or 00
        
        for px_val in tqdm(matris_iterator):
            if px_val == current_color:
                count += 1
            else:
                if count <3:
                    if current_color == 0:
                        tmp_array = np.array([current_color]*(2*count)) #hard multiple 0 case
                        compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                    else:
                        tmp_array = np.array([current_color] * count, dtype = np.uint8)
                        compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                else:#count >= 3 case
                    compressed_data = np.append(compressed_data,np.uint8(0))
                    while count >= 255:
                        compressed_data = np.append(compressed_data,np.uint8(255))
                        count -= 255
                    compressed_data = np.append(compressed_data, np.uint8(count))
                    compressed_data = np.append(compressed_data, np.uint8(current_color))

                current_color = px_val
                count = 1

        if count > 1:
            if count <3:
                if current_color == 0:
                    tmp_array = np.array([current_color]*(2*count)) #hard multiple 0 case
                    compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                else:
                    tmp_array = np.array([px_val] * count, dtype = np.uint8)
                    compressed_data = np.append(compressed_data, np.uint8(tmp_array))
            else:#count >= 3 case
                compressed_data = np.append(compressed_data,np.uint8(0))
                while count >= 255:
                    compressed_data = np.append(compressed_data,np.uint8(255))
                    count -= 255
                compressed_data = np.append(compressed_data, np.uint8(count))
                compressed_data = np.append(compressed_data, np.uint8(px_val))
        
    elif image_mode == 2:
        channels = [bmp_image[:,:,0], bmp_image[:,:,1], bmp_image[:,:,2]]
        i=0
        for channel in channels:
            compressed_data = np.array([], dtype=np.uint8)
            matris_iterator = pattern_iterator(channel)
            current_color = channel[0,0]
            count = 0

            #special character is 0. Its show that next value is pixel value if next value is not 0 or 00
            
            for px_val in tqdm(matris_iterator):
                if px_val == current_color:
                    count += 1
                else:
                    if count <3:
                        if current_color == 0:
                            tmp_array = np.array([current_color]*(2*count)) #hard multiple 0 case
                            compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                        else:
                            tmp_array = np.array([current_color] * count, dtype = np.uint8)
                            compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                    else:#count >= 3 case
                        compressed_data = np.append(compressed_data,np.uint8(0))
                        while count >= 255:
                            compressed_data = np.append(compressed_data,np.uint8(255))
                            count -= 255
                        compressed_data = np.append(compressed_data, np.uint8(count))
                        compressed_data = np.append(compressed_data, np.uint8(current_color))

                    current_color = px_val
                    count = 1

            if count > 1:
                if count <3:
                    if current_color == 0:
                        tmp_array = np.array([current_color]*(2*count)) #hard multiple 0 case
                        compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                    else:
                        tmp_array = np.array([px_val] * count, dtype = np.uint8)
                        compressed_data = np.append(compressed_data, np.uint8(tmp_array))
                else:#count >= 3 case
                    compressed_data = np.append(compressed_data,np.uint8(0))
                    while count >= 255:
                        compressed_data = np.append(compressed_data,np.uint8(255))
                        count -= 255
                    compressed_data = np.append(compressed_data, np.uint8(count))
                    compressed_data = np.append(compressed_data, np.uint8(px_val))

            new_filename = output_file_path.replace(".dat", "{0}.dat".format(i))
            i+=1
            #save compressed_data to file as binary
            with open(new_filename, "wb") as f:
                #add info to file
                height, width,_ = bmp_image.shape
                f.write(height.to_bytes(2, byteorder='big'))
                f.write(width.to_bytes(2, byteorder='big'))
                f.write(mode.to_bytes(1, byteorder='big'))

                f.write(compressed_data.tobytes())

            #test from file {DEBUG}
            if DEBUG == True:
                compressed_data_new = np.array([], dtype=np.uint8)
                with open(new_filename, "rb") as f:
                    #read and save as np array
                    height_i = int.from_bytes(f.read(2), "big")
                    width_i = int.from_bytes(f.read(2), "big")
                    mode_i = int.from_bytes(f.read(1), "big")

                    compressed_data_new = np.frombuffer(f.read(), dtype=np.uint8)
                print(f"DEBUG check written data result is {(compressed_data_new == compressed_data).all()}")        
            
            print(f"Sıkıştırma tamamlandı. Sıkıştırılmış veri '{new_filename}' adlı dosyada saklandı.")
    if image_mode != 2:
        with open(output_file_path, "wb") as f:
            #add info to file
            height, width = bmp_image.shape
            f.write(height.to_bytes(2, byteorder='big'))
            f.write(width.to_bytes(2, byteorder='big'))
            f.write(mode.to_bytes(1, byteorder='big'))

            f.write(compressed_data.tobytes())

        #test from file {DEBUG}
        if DEBUG == True:
            compressed_data_new = np.array([], dtype=np.uint8)
            with open(output_file_path, "rb") as f:
                #read and save as np array
                height_i = int.from_bytes(f.read(2), "big")
                width_i = int.from_bytes(f.read(2), "big")
                mode_i = int.from_bytes(f.read(1), "big")

                compressed_data_new = np.frombuffer(f.read(), dtype=np.uint8)
            print(f"DEBUG check written data result is {(compressed_data_new == compressed_data).all()}")        

        print(f"Sıkıştırma tamamlandı. Sıkıştırılmış veri '{output_file_path}' adlı dosyada saklandı.")



def get_img_num():
    return img_num
def get_iterate_num():
    return iterate_num



if __name__ == "__main__":
    # Örnek kullanım
    input_image_paths = ["bw_image.bmp", "gray_image.bmp", "color_table_image.bmp"]
    #RLE method dictionary that rle method string and function
    RLE_methods = [
        ("row_rotate", row_rotate_iterator),
        ("column_rotate", column_rotate_iterator),
        ("zigzag", zigzag_iterator)
    ]
    output_file_path  = "compressed_files"+ str(img_num) +"/" + RLE_methods[iterate_num][0] + "_compressed.dat"

    mod = img_num*3 + iterate_num
    
    image_compressor(input_image_paths[img_num], output_file_path, mod, RLE_methods[iterate_num][1])


