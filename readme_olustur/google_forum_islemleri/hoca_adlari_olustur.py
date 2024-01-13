import json
import csv
import sys
import os
# Mevcut dosyanın bulunduğu dizini al
current_directory = os.path.dirname(os.path.abspath(__file__))
# Göreceli yol (örneğin, bu dizinden 'readme_guncelleme_arayuzu_python' klasörüne giden yol)
relative_path = os.path.join("..", "readme_guncelleme_arayuzu_python")
# Göreceli yolu tam yola çevir
absolute_path = os.path.join(current_directory, relative_path)
# Tam yolu sys.path listesine ekle
sys.path.append(absolute_path)

from degiskenler import *
"""
    Google forumlar için hoca adları csv dosyası oluşturur.
"""
# Dosya yolu
json_file_path = HOCALAR_JSON_PATH  # JSON dosyasının yolu

# JSON dosyasını oku
with open(json_file_path, 'r', encoding='utf-8') as file:
    data = json.load(file)
def sirala_ve_ayir(hocalar_listesi):
    """
    Hocaların adlarını, ünvanlarına göre önceliklendirilmiş bir sırayla sıralar.
    Önce 'Prof. Dr.', sonra 'Doç. Dr.', ardından 'Dr.' ve son olarak ünvanı olmayanları sıralar.
    """
    def unvan_önceligi(hoca_adi):
        for idx, unvan in enumerate(unvanlar):
            if hoca_adi.startswith(unvan):
                # Listede bulunan ünvanın indeksini döndür (1 ekleyerek 1'den başlat)
                return idx + 1
        # Eğer hiçbir unvan eşleşmiyorsa, listenin uzunluğu + 1 değerini ver
        return len(unvanlar) + 1

    # Hocaların adlarını önceliklere göre ve alfabetik sıraya göre sırala
    sirali_hocalar = sorted(hocalar_listesi, key=lambda hoca: (unvan_önceligi(hoca), hoca))
    return sirali_hocalar

# Hoca adlarını işle ve unvanları at
hoca_names = [hoca[AD] for hoca in data[HOCALAR] if hoca[AD]]
hoca_names = sirala_ve_ayir(hoca_names)
# CSV dosyası oluştur
csv_file_path = 'hoca_listesi.csv'  # Oluşturulacak CSV dosyasının yolu
with open(csv_file_path, 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    # Sütun başlığını yaz
    writer.writerow(['Hoca Adı'])
    # Her hocanın adını yaz
    for name in hoca_names:
        if name:
            writer.writerow([name])
