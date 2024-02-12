from compress_huff import huffman_decode
import os

def degisken_uzunlukta_ac(filename, is_multi_key_len=False):
    with open(filename + ".json", 'r') as file:
        original_data = file.read()
    klasor_adi = os.path.join("encoded", filename)
    if is_multi_key_len:
        klasor_adi += "_multi_key_len"
    else:
        klasor_adi += "_mono_key_len"
    for i in range(1,1000):
        for j in range(2,10):
            decoded_file_path = huffman_decode(filename + f"_encoded_key_len={j}_min_freq={i}.bin",klasor_adi )
            if(original_data != open(decoded_file_path, 'r').read()):
                os.remove(decoded_file_path)
                encoded_file_path = decoded_file_path.replace("decoded", "encoded")
                encoded_file_path = encoded_file_path.replace("json", "bin")
                os.remove(encoded_file_path)
    return True

filename = "kucuk_test"
filename = "test"
#filename = "orta_test"

# multi key len için True değeri verilmeli
if degisken_uzunlukta_ac(filename,True):
    print("Açma işlemi başarılı")
else:
    print("Açma işlemi başarısız")