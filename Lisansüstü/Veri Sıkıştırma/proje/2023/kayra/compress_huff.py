import json
from collections import Counter
from huffman import *
import pickle
import os



MIN_FREQ = 200
MAX_COUNTER_LEN = 1689170626

# Filtreleme işlemini gerçekleştiren fonksiyon
def filter_keys_by_length_and_frequency(counter, min_freq=50, key_len=1):
    # Eğer anahtarın uzunluğu 'key_len' e eşitse veya frekansı 'min_freq' den büyükse sözlüğe eklenir.
    return {k: v for k, v in counter.items() if len(k) == key_len or v >= min_freq}

def unique_char_count(s):
    # Verilen string 's' içindeki benzersiz karakterlerin sayısını döndürür.
    return len(set(s))


def remove_unused_keys(cleaned_text, counter, length=1):
    tmp_counter = {k: v for k, v in counter.items() if len(k) == length}
    for key in list(tmp_counter.keys()):  # Anahtarlar listesini kopya alıyoruz çünkü sözlük boyutu değişecek
        if cleaned_text.count(key) == 0:
            del counter[key]
    return counter

# Anahtarların belirtilen uzunluktakilerini kaldıran fonksiyon
def reduce_counter(json_string, counter, max_key_length):
    # 'max_key_length' uzunluğuna sahip olan anahtarlar seçilir
    keys_to_remove = [k for k, v in counter.items() if len(k) == max_key_length]
    
    # Seçilen anahtarlar 'json_string' içerisinden kaldırılır
    for key in keys_to_remove:
        json_string = json_string.replace(key, "")
    
    # Kalan veri için frekans sayacı güncellenir
    return remove_unused_keys(json_string, counter)


def reduce_counter_multi_key_len(json_string, counter, max_key_length):
    for length in range(max_key_length, 0, -1):  # max_key_length'ten 1'e kadar olan değerleri dön
        # Belirli bir uzunluktaki anahtarları al
        keys_to_remove = [k for k, v in counter.items() if len(k) == length]
        # Bu anahtarları json_string'den kaldır
        tmp_json_str = json_string
        for key in keys_to_remove:
            tmp_json_str = json_string.replace(key, "")
        
        # Anahtarların temsil edebildiği tüm veriler json'dan silindikten sonra counter'ı güncelle
        for l in range(length-1, 0, -1):
            counter = remove_unused_keys(tmp_json_str, counter, l)

    return counter


# Frekans hesaplama işlemini yapan fonksiyon
def calculate_frequency(json_string, max_key_length, min_freq=MIN_FREQ):
    # Frekans sayacını tutan Counter nesnesi
    counter = Counter()

    # Tek karakterli anahtarlar için frekans hesaplama
    for i in range(0, len(json_string) - 1 + 1):
        key = json_string[i:i + 1]
        counter[key] += 1

    # Eğer max_key_length 2'den büyükse, çok karakterli anahtarlar için frekans hesaplama
    if max_key_length > 2:
        for i in range(0, len(json_string) - max_key_length + 1):
            key = json_string[i:i + max_key_length]
            counter[key] += 1

        while True:
            counter = filter_keys_by_length_and_frequency(counter, min_freq=min_freq,key_len=1)
            if len(counter) < MAX_COUNTER_LEN + unique_char_count(json_string):
                break
            min_freq *= 2

        # Kullanılmayan veya fazla olan anahtarları kaldır
        counter = reduce_counter(json_string, counter, max_key_length)

    return counter, min_freq


# Çoklu anahtar uzunlukları için frekans hesaplama fonksiyonu
def calculate_frequency_multi_key_len(json_string, max_key_length, min_freq=MIN_FREQ):
    # Karakter frekansını hesaplayacak sayaç
    counter = Counter()

    # Belirtilen maksimum anahtar uzunluğu için frekansları hesapla
    for j in range(1, max_key_length + 1):
        for i in range(0, len(json_string) - j + 1):
            key = json_string[i:i + j]
            counter[key] += 1

    # Minimum frekans ve anahtar uzunluğu ile filtreleme yap
    while True:
        filtered_counter = filter_keys_by_length_and_frequency(counter, min_freq=min_freq, key_len=1)
        # Filtrelenmiş sayaç boyutu belirtilen maksimum boyuttan küçük ise döngüden çık
        if len(filtered_counter) < MAX_COUNTER_LEN + unique_char_count(json_string):
            break
        # Aksi halde, minimum frekansı arttır
        min_freq *= 2

    # Frekansları azaltarak son halini al
    reduced_counter = reduce_counter_multi_key_len(json_string, filtered_counter, max_key_length)

    return reduced_counter, min_freq


# Huffman ağacından kodları oluşturan fonksiyon
def build_codes(root, current_code, codes):
    # Eğer ağacın bu dalı boşsa, işlem yapma
    if root is None:
        return
    
    # Eğer bu dalda bir karakter varsa, bu karakter için kod oluştur
    if root.char is not None:
        codes[root.char] = current_code
        return

    # Sol ve sağ dallar için kod oluşturma işlemini tekrar et
    build_codes(root.left, current_code + "0", codes)
    build_codes(root.right, current_code + "1", codes)


# Veriyi sıkıştıran fonksiyon
def compress(json_string, codes):
    compressed_data = ""  # Sıkıştırılmış veriyi tutacak olan değişken
    i = 0  # İndex değişkeni

    # Tüm json_string boyunca dön
    while i < len(json_string):
        j = 1  # anahtar uzunluğunu temsil eder

        # Eğer anahtar kodlarda yoksa, anahtarın uzunluğunu artır
        while i + j <= len(json_string) and json_string[i:i + j] not in codes:
            j += 1

        # Eğer bir anahtar bulunmuşsa
        if i + j <= len(json_string):
            compressed_data += codes[json_string[i:i + j]]  # Sıkıştırılmış veriye ekle
            i += j  # İndexi anahtarın uzunluğu kadar artır
        else:  # Eğer bu konumda geçerli bir anahtar bulunmamışsa
            i += 1  # İndexi 1 artır

    return compressed_data


# Sıkıştırılmış veriyi açan fonksiyon
def decompress(compressed_data, codes):
    # Kodları ters çevir (kod: anahtar)
    reverse_codes = {v: k for k, v in codes.items()}
    decoded_data = ""  # Açılmış veriyi tutacak değişken
    current_code = ""  # Şu anki kodu tutacak değişken

    # Tüm sıkıştırılmış veri boyunca dön
    for bit in compressed_data:
        current_code += bit  # Şu anki koda bir bit ekle

        # Eğer şu anki kod bir anahtara karşılık geliyorsa
        if current_code in reverse_codes:
            decoded_data += reverse_codes[current_code]  # Açılmış veriye ekle
            current_code = ""  # Şu anki kodu sıfırla

    return decoded_data


# Kodları bir dosyaya yazma işlemi
def write_codes_to_file(file, codes):
    pickle.dump(codes, file)  # pickle modülü ile kodları dosyaya yaz

# Kodları bir dosyadan okuma işlemi
def read_codes_from_file(file):
    return pickle.load(file)  # pickle modülü ile kodları dosyadan oku

# Huffman kodlamasını gerçekleştiren ana fonksiyon
def huffman_encode(filename, min_freq=MIN_FREQ, klasor="encoded", max_key_length=4):
    # max_key_length kontrolü
    if max_key_length < 2:
        max_key_length = 1
    
    # Dosyayı oku ve içeriğini json_string değişkenine kaydet
    with open(filename, 'r') as file:
        json_string = file.read()

    # Frekansları hesapla
    freq_counter, min_freq = calculate_frequency(json_string, max_key_length=max_key_length, min_freq=min_freq)

    # Huffman ağacını oluştur
    huffman_tree = build_huffman_tree(freq_counter)

    # Kodları oluştur
    codes = {}
    build_codes(huffman_tree, "", codes)

    # Veriyi sıkıştır
    compressed_data = compress(json_string, codes)

    # Padding ekle
    padding = 8 - len(compressed_data) % 8
    for _ in range(padding):
        compressed_data += "0"

    # Padding bilgisini ekle
    padded_info = "{0:08b}".format(padding)
    compressed_data = padded_info + compressed_data

    # Yeni dosya adını oluştur ve dosyayı kaydet
    new_file_name = os.path.join(klasor ,filename.replace(".json", "") + "_mono_key_len")
    os.makedirs(new_file_name, exist_ok=True)
    with open(os.path.join(new_file_name ,filename.replace(".json", f"_encoded_key_len={max_key_length}_min_freq={min_freq}.bin")), 'wb') as file:
        write_codes_to_file(file, codes)
        file.write(bytes(int(compressed_data[i:i+8], 2) for i in range(0, len(compressed_data), 8)))
    return min_freq  # min_freq değerini döndür
# Sıkıştırılmış dosyayı çözen fonksiyon (ilk versiyon)
def huffman_decode(encoded_filename):
    with open(encoded_filename, 'rb') as file:
        codes = read_codes_from_file(file)  # Kodları dosyadan oku
        byte_data = file.read()  # Bayt verilerini oku
        compressed_data = "".join(bin(byte)[2:].zfill(8) for byte in byte_data)

    # Padding bilgisini al ve sıkıştırılmış veriyi güncelle
    padding_info = compressed_data[:8]
    compressed_data = compressed_data[8:]
    padding = int(padding_info, 2)
    compressed_data = compressed_data[:-padding]

    # Veriyi çöz
    decoded_data = decompress(compressed_data, codes)

    # Çözülmüş veriyi yeni bir dosyaya yaz
    with open(encoded_filename.replace("_encoded.bin", "_decoded.json"), 'w') as file:
        file.write(decoded_data)

# Sıkıştırılmış dosyayı çözen fonksiyon (klasör destekli versiyon)
def huffman_decode(encoded_filename, encoded_klasor, klasor="decoded"):
    with open(os.path.join(encoded_klasor, encoded_filename), 'rb') as file:
        codes = read_codes_from_file(file)  # Kodları dosyadan oku
        byte_data = file.read()  # Bayt verilerini oku
        compressed_data = "".join(bin(byte)[2:].zfill(8) for byte in byte_data)

    # Padding bilgisini al ve sıkıştırılmış veriyi güncelle
    padding_info = compressed_data[:8]
    compressed_data = compressed_data[8:]
    padding = int(padding_info, 2)
    compressed_data = compressed_data[:-padding]

    # Veriyi çöz
    decoded_data = decompress(compressed_data, codes)

    # Çözülmüş dosyanın yeni adını oluştur ve klasörü hazırla
    decoded_filename = encoded_filename.replace("bin", "json")
    decoded_filename = decoded_filename.replace("encoded", "decoded")
    new_decoded_klasor = encoded_klasor.replace("encoded", klasor)
    os.makedirs(new_decoded_klasor, exist_ok=True)
    olusan_yer = os.path.join(new_decoded_klasor, decoded_filename)

    # Çözülmüş veriyi yeni bir dosyaya yaz
    with open(olusan_yer, 'w') as file:
        file.write(decoded_data)

    return olusan_yer  # Oluşan dosyanın yeri

# Çeşitli anahtar uzunlukları için Huffman kodlama yapan fonksiyon
def huffman_encode_multi_key_len(filename, min_freq=MIN_FREQ, klasor="encoded", max_key_length=4):
    # Anahtar uzunluğunu kontrol et
    if max_key_length < 2:
        max_key_length = 1

    try:
        # Dosyayı aç ve içeriği oku
        with open(filename, 'r') as file:
            json_string = file.read()
    except:
        return min_freq

    # Frekansları hesapla
    freq_counter, min_freq = calculate_frequency_multi_key_len(json_string, max_key_length=max_key_length, min_freq=min_freq)

    # Huffman ağacını oluştur
    huffman_tree = build_huffman_tree(freq_counter)
    codes = {}
    build_codes(huffman_tree, "", codes)
    
    # Veriyi sıkıştır
    compressed_data = compress(json_string, codes)
    
    # Padding ekle
    padding = 8 - len(compressed_data) % 8
    for _ in range(padding):
        compressed_data += "0"

    # Padding bilgisini ekleyerek veriyi tamamla
    padded_info = "{0:08b}".format(padding)
    compressed_data = padded_info + compressed_data

    # Yeni dosya adını oluştur ve sıkıştırılmış veriyi dosyaya yaz
    new_file_name = os.path.join(klasor ,filename.replace(".json", "") + "_multi_key_len")
    os.makedirs(new_file_name, exist_ok=True)
    with open(os.path.join(new_file_name ,filename.replace(".json", f"_encoded_key_len={max_key_length}_min_freq={min_freq}.bin")), 'wb') as file:
        write_codes_to_file(file, codes)
        file.write(bytes(int(compressed_data[i:i+8], 2) for i in range(0, len(compressed_data), 8)))
    
    return min_freq