from compress_huff import huffman_encode_multi_key_len

def degisken_uzunlukta_kodla(filename):
    for i in range(1,1000):
        frekans = i
        for j in range(2,10):
            new_freq = huffman_encode_multi_key_len(filename, frekans, max_key_length=j)
            if frekans != new_freq:
                frekans = new_freq

# Örnek kullanım
# en iyi değerler kucuk_test_encoded_key_len=2_min_freq=91.bin
filename = "kucuk_test.json"

# en iyi değerler 
filename = "test.json"

# en iyi değerler orta_test_encoded_key_len=2_min_freq=1.bin
#filename = "orta_test.json"

degisken_uzunlukta_kodla(filename)
