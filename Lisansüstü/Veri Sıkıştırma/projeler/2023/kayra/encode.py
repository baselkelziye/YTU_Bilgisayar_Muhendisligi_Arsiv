from compress_huff import huffman_encode

def degisken_uzunlukta_kodla(filename):
    for i in range(1,1000):
        frekans = i
        for j in range(2,10):
            new_freq = huffman_encode(filename, frekans, max_key_length=j)
            if frekans != new_freq:
                frekans = new_freq


# en iyi değerler kucuk_test_encoded_key_len=2_min_freq=1.bin
filename = "kucuk_test.json"
filename = "test.json"
#filename = "orta_test.json"

# en iyi değerler orta_test_encoded_key_len=4_min_freq=75.bin
#filename = "orta_test.json"
"""
En iyi performans (min_freq 1'den 1000'e kadar,max_key_length 1'den 10' kadar  denendi )

filename = "kucuk_test.json"
degisken_uzunlukta_kodla(filename)

# en iyi değerler orta_test_encoded_key_len=4_min_freq=75.bin
filename = "orta_test.json"
degisken_uzunlukta_kodla(filename)


filename = "test.json"
degisken_uzunlukta_kodla(filename)
""" 
degisken_uzunlukta_kodla(filename)
