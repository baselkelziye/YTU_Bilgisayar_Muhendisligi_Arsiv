import pandas as pd
import json
import locale
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

from degiskenler import DERSLER_JSON_PATH, DERSLER, AD
# Türkçe karakterlerin doğru sıralanabilmesi için Türkçe locale ayarını kullanacağız.
# Sistem locale ayarlarınızın bu dili desteklediğinden emin olun.
locale.setlocale(locale.LC_ALL, 'tr_TR.utf8')

def turkce_sirala(ders_listesi):
    """
    Verilen ders adlarını Türkçe karakterleri de dikkate alarak alfabetik sıraya dizer.
    """
    return sorted(ders_listesi, key=locale.strxfrm)
# JSON dosyasını oku
dosya_yolu = DERSLER_JSON_PATH
with open(dosya_yolu, 'r', encoding='utf-8') as dosya:
    veri = json.load(dosya)

# Ders adlarını içeren bir liste oluştur
ders_adlari = [ders[AD] for ders in veri[DERSLER] if ders[AD]]
ders_adlari = turkce_sirala(ders_adlari)

# Ders adlarını bir DataFrame'e dönüştür
df = pd.DataFrame(ders_adlari, columns=['Ders Adı'])

# DataFrame'i .csv dosyası olarak kaydet
csv_dosya_yolu = 'ders_adlari.csv'  # İstediğiniz dosya adı ve yolu
df.to_csv(csv_dosya_yolu, index=False)

print(f"'{csv_dosya_yolu}' olarak kaydedildi.")
