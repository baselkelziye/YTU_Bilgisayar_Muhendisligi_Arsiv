from PIL import Image
import sys


def rle_decode(f):

    # Geriye kalan veriyi bytes olarak oku
    byte_data = f.read()

    decoded_data = []
    i = 0
    while i < len(byte_data):
        if byte_data[i] == 255:
            count = byte_data[i+1]
            value = byte_data[i+2]
            if value == 254:
                value = 255
            decoded_data.extend([value] * count)
            i += 3
        else:
            decoded_data.append(byte_data[i])
            i += 1

    return decoded_data

def rle_encode(data):
    encoded = []
    i = 0
    while i < len(data):
        if i + 2 < len(data) and data[i] == data[i+1] == data[i+2]:
            count = 3
            while i + count < len(data) and data[i] == data[i+count]:
                count += 1
            while count >= 255:
                encoded.append(255)
                encoded.append(254)
                count -= 254
                if data[i] == 255:
                    encoded.append(254)
                else:
                    encoded.append(data[i])
                i += 254
            encoded.append(255)
            encoded.append(count)
            if data[i] == 255:
                encoded.append(254)
            else:
                encoded.append(data[i])
            i += count
        else:
            if data[i] == 255:
                encoded.append(254)
            else:
                encoded.append(data[i])
            i += 1
    return encoded
def rle_image_compress_row_row(img_path, output_path):
    image = Image.open(img_path)
    width, height = image.size

    # RGB, Gray Scale ve Black & White kontrolü
    if image.mode == 'RGB':
        channels = image.split()
        encoded_channels = []
        for channel in channels:
            encoded_channels.append(rle_encode(list(channel.getdata())))
        with open(output_path, 'wb') as f:
            f.write(f"{width} {height} {image.mode}\n".encode('utf-8'))
            for ec in encoded_channels:
                for pair in ec:
                    f.write(int.to_bytes(pair, byteorder='big', length=1))
    elif image.mode in ['L', '1']:  # L: Gray scale, 1: Black & White
        encoded = rle_encode(list(image.getdata()))
        with open(output_path, 'wb') as f:
            f.write(f"{width} {height} {image.mode}\n".encode('utf-8'))
            for en in encoded:
                f.write(int.to_bytes(en, byteorder='big', length=1))
    else:
        print(f'{image.mode} bulunamadı')


def rle_image_decompress_row_row(rle_path):
    with open(rle_path, 'rb') as f:
        width, height, img_mode = f.readline().decode('utf-8').strip().split()
        width, height = int(width), int(height)
        img_size = (width, height)
        img_len = width * height
        if img_mode == 'RGB':
            channels_data = []
            all_colors = rle_decode(f)
            R_C = all_colors[0:img_len]
            G_C = all_colors[img_len:2*img_len]
            B_C = all_colors[2*img_len:] 
            img_channel_R = Image.new('L', img_size)
            img_channel_G = Image.new('L', img_size)
            img_channel_B = Image.new('L', img_size)
            img_channel_R.putdata(R_C)
            img_channel_G.putdata(G_C)
            img_channel_B.putdata(B_C)
            channels_data.append(img_channel_R)
            channels_data.append(img_channel_G)
            channels_data.append(img_channel_B)
            image = Image.merge('RGB', channels_data)
        else:  # Gray Scale veya Black & White için
            data = rle_decode(f)
            image = Image.new(img_mode, img_size)
            image.putdata(data)

    image.show()
    return image


def rle_image_compress_column_column(img_path, output_path):
    image = Image.open(img_path)
    width, height = image.size

    def column_data(image):
        pixels = list(image.getdata())
        for x in range(image.width):
            for y in range(image.height):
                yield pixels[y * image.width + x]

    if image.mode == 'RGB':
        channels = image.split()
        encoded_channels = []
        for channel in channels:
            encoded_channels.append(rle_encode(list(column_data(channel))))
        with open(output_path, 'wb') as f:
            f.write(f"{width} {height} {image.mode}\n".encode('utf-8'))
            for ec in encoded_channels:
                for pair in ec:
                        f.write(int.to_bytes(pair, byteorder='big', length=1))
    elif image.mode in ['L', '1']:  # L: Gray scale, 1: Black & White
        encoded = rle_encode(list(column_data(image)))
        with open(output_path, 'wb') as f:
            f.write(f"{width} {height} {image.mode}\n".encode('utf-8'))
            for en in encoded:
                f.write(int.to_bytes(en, byteorder='big', length=1))
    else:
        print(f'{image.mode} bulunamadı')

def rle_image_decompress_column_column(rle_path):
    with open(rle_path, 'rb') as f:
        width, height, img_mode = f.readline().decode('utf-8').strip().split()
        width, height = int(width), int(height)
        img_size = (width, height)

        def set_column_data(image, data):
            pixels = list(image.getdata())
            data_iter = iter(data)
            for x in range(image.width):
                for y in range(image.height):
                    pixels[y * image.width + x] = next(data_iter)
            image.putdata(pixels)
        img_len = width * height
        if img_mode == 'RGB':
            channels_data = []
            all_colors = rle_decode(f)
            R_C = all_colors[0:img_len]
            G_C = all_colors[img_len:2*img_len]
            B_C = all_colors[2*img_len:] 
            img_channel_R = Image.new('L', img_size)
            img_channel_G = Image.new('L', img_size)
            img_channel_B = Image.new('L', img_size)
            img_channel_R.putdata(R_C)
            img_channel_G.putdata(G_C)
            img_channel_B.putdata(B_C)
            channels_data.append(img_channel_R)
            channels_data.append(img_channel_G)
            channels_data.append(img_channel_B)
            images = [Image.new('L', img_size) for _ in channels_data]
            for image, data in zip(images, [R_C, G_C, B_C]):
                set_column_data(image, data)
            image = Image.merge('RGB', images)
        else:  # Gray Scale or Black & White
            data = rle_decode(f)
            image = Image.new(img_mode, img_size)
            set_column_data(image, data)

    image.show(rle_path)
    return image



def zigzag_flatten(matrix):
    rows, cols = len(matrix), len(matrix[0])
    result = []
    for d in range(rows + cols - 1):
        if d % 2 == 0:
            row = min(d, rows - 1)
            col = max(0, d - rows + 1)
            while row >= 0 and col < cols:
                result.append(matrix[row][col])
                row -= 1
                col += 1
        else:
            col = min(d, cols - 1)
            row = max(0, d - cols + 1)
            while col >= 0 and row < rows:
                result.append(matrix[row][col])
                row += 1
                col -= 1
    return result

def zigzag_reshape(data, rows, cols):
    matrix = [[None] * cols for _ in range(rows)]
    iter_data = iter(data)
    for d in range(rows + cols - 1):
        if d % 2 == 0:
            row = min(d, rows - 1)
            col = max(0, d - rows + 1)
            while row >= 0 and col < cols:
                matrix[row][col] = next(iter_data)
                row -= 1
                col += 1
        else:
            col = min(d, cols - 1)
            row = max(0, d - cols + 1)
            while col >= 0 and row < rows:
                matrix[row][col] = next(iter_data)
                row += 1
                col -= 1
    return matrix

def rle_image_compress_zigzag(img_path, output_path):
    image = Image.open(img_path)
    width, height = image.size

    def get_zigzag_data(image):
        matrix = [list(image.getdata())[i * width: (i + 1) * width] for i in range(height)]
        return zigzag_flatten(matrix)

    with open(output_path, 'wb') as f:
        f.write(f"{width} {height} {image.mode}\n".encode('utf-8'))
        if image.mode == 'RGB':
            channels = image.split()
            encoded_channels = []
            for channel in channels:
                encoded_channels.append(rle_encode(list(get_zigzag_data(channel))))
            with open(output_path, 'wb') as f:
                f.write(f"{width} {height} {image.mode}\n".encode('utf-8'))
                for ec in encoded_channels:
                    for pair in ec:
                            f.write(int.to_bytes(pair, byteorder='big', length=1))
        else:  # Gray Scale or Black & White
            data = get_zigzag_data(image)
            encoded = rle_encode(data)
            for en in encoded:
                f.write(int.to_bytes(en, byteorder='big', length=1))

def rle_image_decompress_zigzag(rle_path):
    with open(rle_path, 'rb') as f:
        width, height, img_mode = f.readline().decode('utf-8').strip().split()
        width, height = int(width), int(height)
        img_size = (width, height)

        def set_zigzag_data(image, data):
            matrix = zigzag_reshape(data, height, width)
            flat_data = [pixel for row in matrix for pixel in row]
            image.putdata(flat_data)
        img_len = width * height
        if img_mode == 'RGB':
            channels_data = []
            all_colors = rle_decode(f)
            R_C = all_colors[0:img_len]
            G_C = all_colors[img_len:2*img_len]
            B_C = all_colors[2*img_len:] 
            img_channel_R = Image.new('L', img_size)
            img_channel_G = Image.new('L', img_size)
            img_channel_B = Image.new('L', img_size)
            img_channel_R.putdata(R_C)
            img_channel_G.putdata(G_C)
            img_channel_B.putdata(B_C)
            channels_data.append(img_channel_R)
            channels_data.append(img_channel_G)
            channels_data.append(img_channel_B)
            images = [Image.new('L', img_size) for _ in channels_data]
            for image, data in zip(images, [R_C, G_C, B_C]):
                set_zigzag_data(image, data)
            image = Image.merge('RGB', images)
        else:  # Gray Scale or Black & White
            data = rle_decode(f)
            image = Image.new(img_mode, img_size)
            set_zigzag_data(image, data)

    image.show()
    return image



foto_adlari = ['Black&White.bmp', 'Color-Table.bmp','Gray-Scale.bmp']
foto_yollari = ['black_white','color_table','gray_scale']
dosya_adlari = ['row_row_rotate','column_column_rotate','zig_zag']



for i in range(0,3):
    if len(sys.argv) <= 1 or sys.argv[1] == "1"or sys.argv[1] == "-2":
        rle_image_compress_row_row(foto_adlari[i], f"{foto_yollari[i]}/{dosya_adlari[0]}.rle")
    if len(sys.argv) <= 1 or (sys.argv[1] != "-2" and ( sys.argv[1] == "-1" or sys.argv[1] == "0" or sys.argv[1] == "1" )):
        rle_image_decompress_row_row(f"{foto_yollari[i]}/{dosya_adlari[0]}.rle")

for i in range(0,3):
    if len(sys.argv) <= 1 or sys.argv[1] == "2"or sys.argv[1] == "-2":
        rle_image_compress_column_column(foto_adlari[i], f"{foto_yollari[i]}/{dosya_adlari[1]}.rle")
    if len(sys.argv) <= 1 or (sys.argv[1] != "-2" and (sys.argv[1] == "-1" or sys.argv[1] == "3" or sys.argv[1] == "2")):
        rle_image_decompress_column_column(f"{foto_yollari[i]}/{dosya_adlari[1]}.rle")

for i in range(0,3):
    if len(sys.argv) <= 1 or sys.argv[1] == "4" or sys.argv[1] == "-2":
        rle_image_compress_zigzag(foto_adlari[i], f"{foto_yollari[i]}/{dosya_adlari[2]}.rle")
    if len(sys.argv) <= 1 or (sys.argv[1] != "-2" and (sys.argv[1] == "-1" or sys.argv[1] == "4" or sys.argv[1] == "5")):
        rle_image_decompress_zigzag(f"{foto_yollari[i]}/{dosya_adlari[2]}.rle")
