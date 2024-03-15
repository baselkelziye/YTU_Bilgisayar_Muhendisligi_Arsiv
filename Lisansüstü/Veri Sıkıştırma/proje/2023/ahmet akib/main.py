from PIL import Image
from collections import Counter
from Node import Node
from binaryTree import BinaryTree
import numpy as np
from typing import List, Dict, Tuple
import pickle

# Bitmap resmi okuma ve piksel verilerini hazırlama
def read_image(file_path: str) -> Tuple[List[int], Tuple[int, int]]:
    img = Image.open(file_path)
    
    # Resmin renk modunu kontrol et ve gerektiğinde dönüştür
    print("info: Image mode is " + img.mode + "\n")

    data = img.getdata()

    # Eğer resim RGB ise her bir renk kanalını ayrı ayrı ele al, değilse doğrudan piksel değerlerini kullan
    if img.mode == 'RGB':
        channel = 3
        image_data = [color for pixel in data for color in pixel]
    else:  # Gri ölçekli veya tek kanallı bir resim için
        channel = 1
        image_data = list(data)

    return image_data, img.size, channel

def check_image_equality(image1: Image, image2: Image) -> bool:
    """
    Checks if two images are equal.

    Args:
        image1 (Image): The first image.
        image2 (Image): The second image.

    Returns:
        bool: True if the images are equal, False otherwise.
    """
    return image1.tobytes() == image2.tobytes()

class HuffmanCodingForImage:

    def __init__(self, file_path: str = 'proje/color_table_image.bmp', output_path: str = 'proje/sonuc_color_table_image.byteArray'):
        self.oppened_image, self.compressed_data = self.compress_image(file_path, output_path)
        self.channel = None

    def calculate_frequencies(self, image_data: List[int]) -> Dict[int, int]:
        freq_counter = Counter(image_data)
        freq_dict = dict(freq_counter)
        return freq_dict
    
    # Sıkıştırılmış veriyi kaydetme
    def save_compressed_data(self, image_data: List[int], codes: Dict[int, str], file_path: str) -> bytearray:
        # Sıkıştırılmış veriyi bit dizisi olarak oluştur
        encoded_bits = "".join(codes[pixel] for pixel in image_data)

        # Padding ekleyerek bit dizisinin uzunluğunu 8 bitin katına tamamla
        padding_size = (8 - len(encoded_bits) % 8) % 8
        encoded_bits_padded = encoded_bits + '0' * padding_size

        # Bit dizisini bytearray'a çevir
        b = bytearray()
        for i in range(0, len(encoded_bits_padded), 8):
            byte = int(encoded_bits_padded[i:i+8], 2)
            b.append(byte)

        # Bytearray'ı ikili dosyaya yaz
        with open(file_path, 'wb') as file:
            file.write(b)

        return b

    # Sıkıştırılmış veriyi açma
    def decode_image_data(self, encoded_data: bytearray, root: Node, size: Tuple[int, int]) -> Image:
        decoded_output = []
        current_node = root

        # Bayt dizisini bit dizisine dönüştür
        bit_string = ''.join(f'{byte:08b}' for byte in encoded_data)

        for bit in bit_string:
            current_node = current_node.left if bit == '0' else current_node.right
            # Yaprak düğüme ulaşıldıysa, ilgili karakteri çıkar ve ağacın köküne dön
            if current_node.isLeaf():
                decoded_output.append(current_node.char)
                current_node = root

        # Resmi doğru boyutlarda ve kanallarda yeniden şekillendir
                
        required_pixels = size[1] * size[0] * self.channel
        if len(decoded_output) < required_pixels:
            print("Warning: Padding bits found...")
            decoded_output += [decoded_output[-1]] * (required_pixels - len(decoded_output))
        elif len(decoded_output) > required_pixels:
            print("Warning: Extra bits found...")
            decoded_output = decoded_output[:required_pixels]
        if self.channel == 1:
            reshaped_image = np.array(decoded_output).reshape(size[1], size[0])
        else:
            reshaped_image = np.array(decoded_output).reshape(size[1], size[0], self.channel)
        return Image.fromarray(reshaped_image.astype('uint8'))
    
    def saveHeader(self, freq: Node, size: Tuple[int, int], file_path: str):
         #save root and size with pickle
        with open('data.pickle', 'wb') as f:
            pickle.dump((freq, size), f)

    def readHeader(self, file_path: str):
        #read root and size with pickle
        with open('data.pickle', 'rb') as f:
            freq, size = pickle.load(f)
        return freq, size


    # Ana sıkıştırma işlevi
    def compress_image(self, file_path: str, output_path: str) -> Tuple[None, bytearray]:
        image_data, size, self.channel = read_image(file_path)
        self.original_image = image_data.copy()
        freq = self.calculate_frequencies(image_data)
        huffmanTree = BinaryTree(freq)
        root = huffmanTree.root
        codes = huffmanTree.huffmanCodes
        self.saveHeader(freq, size, output_path)
        encoded_data = self.save_compressed_data(image_data, codes, output_path)
        return self.decode_image_data(encoded_data, root, size), encoded_data
    
    def decompress_image(self, file_path: str, output_path: str) -> Image:
        encoded_data = self.compressed_data
        freq, size = self.readHeader(file_path)
        huffmanTree = BinaryTree(freq)
        root = huffmanTree.root
        return self.decode_image_data(encoded_data, root, size)

if __name__ == "__main__":
    
    image_name = 'lioncolor_table_image'

    personel_comment = ""
    
    file_path = 'proje/'+image_name+'.bmp'
    output_path = 'proje/sonuc_'+image_name+"_"+personel_comment+'.byteArray'
    compressed = HuffmanCodingForImage(file_path=file_path, output_path=output_path)

    # Açılan resmi göster
    compressed.oppened_image.show()

    original_image = Image.open(file_path)

    # kayıbı hesapla
    equality = check_image_equality(original_image, compressed.oppened_image)
    print("info: Images equality: " + str(equality) + "\n")
    
    # Log dosyası oluştur
    with open('proje/log.txt', 'w') as file:
        log_file_name = 'proje/log_' + image_name +"_"+personel_comment+ '.txt'
        with open(log_file_name, 'w') as log_file:
            log_file.write("compressed file size:" + str(len(compressed.compressed_data)) + "\n original file size:" + str(len(original_image.tobytes())) + "\n lossless: " + str(equality))
            log_file.close()

