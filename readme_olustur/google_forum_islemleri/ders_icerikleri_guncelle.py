import pandas as pd
import os
import json
import shutil
from icerik_kontrol import *
DERS_YILDIZLARI_DOSYASI = "https://docs.google.com/spreadsheets/d/e/2PACX-1vSDFicOFbJu9Fnc4Hl0mFuuaC0L4PiEmUFkkJrgocwWGWs1wB3TyN1zd4okW8svC6IT2HMIe64NQUUy/pub?output=csv"
DERS_YORUMLARI_DOSYASI = "https://docs.google.com/spreadsheets/d/e/2PACX-1vQvGyGLQxobIpaVdQItSpqEoiwJ0DIIHE9kVvCHhfKQ7yYR16c2tI_ix4Z9d2tA4aLt2c4fTLGxlL-s/pub?output=csv"


def guncelle_ogrenci_gorusleri(data, sheets_url):
    # Google Sheets verisini indir
    df = pd.read_csv(sheets_url)
    df = df.dropna()  # NaN içeren tüm satırları kaldır
    # Her ders için yorumları güncelle
    for index, row in df.iterrows():
        ders_adi = row['Ders Seç']
        kisi = row['İsmin Nasıl Gözüksün']
        yorum = row['Ders hakkındaki yorumun']
        icerikKontrol = IcerikKontrol("ders")
        if not pd.isna(yorum) and icerikKontrol.pozitif_mi(yorum):
            yorum = icerikKontrol.metin_on_isleme(yorum)
            for ders in data['dersler']:
                if ders['ad'] == ders_adi:
                    # Eğer bu kisi için daha önce bir yorum yapılmışsa, güncelle
                    gorus_var_mi = False
                    if 'ogrenci_gorusleri' not in ders:
                        ders['ogrenci_gorusleri'] = []
                    for gorus in ders['ogrenci_gorusleri']:
                        if gorus['kisi'].lower() == kisi.lower():
                            gorus['yorum'] = yorum
                            gorus_var_mi = True
                            break
                    
                    # Yeni yorum ekle
                    if not gorus_var_mi:
                        ders['ogrenci_gorusleri'].append({'kisi': kisi, 'yorum': yorum})
    icerikKontrol.dosya_yaz()
def guncelle_ders_yildizlari(data, sheets_url):
    
    # Veriyi indir ve DataFrame olarak oku
    yildizlar_df = pd.read_csv(sheets_url)


    # Sadece sayısal sütunları al ve ortalama hesapla
    yildizlar_numeric_columns = yildizlar_df.columns.drop(['Zaman damgası', 'Ders Seç'])  # Sayısal olmayan sütunları çıkar
    yildizlar_grouped = yildizlar_df.groupby('Ders Seç')[yildizlar_numeric_columns].mean()
    # Hocaların aldığı oyların (yani kaç defa seçildiğinin) frekansını hesapla
    ders_oy_sayisi = yildizlar_df['Ders Seç'].value_counts()

    # En yüksek oy sayısına sahip hocayı bul
    en_populer_ders = ders_oy_sayisi.idxmax()
    en_populer_ders_oy_sayisi = ders_oy_sayisi.max()
    data["en_populer_ders"] = {"ders_adi":en_populer_ders, "oy_sayisi":int(en_populer_ders_oy_sayisi)}
    for ders in data['dersler']:
        name = ders.get('ad')
        if name in yildizlar_grouped.index:
            ders['kolaylik_puani'] = int(yildizlar_grouped.loc[name, 'Dersi geçmek ne kadar kolay?'] * 10)
            ders['gereklilik_puani'] = int(yildizlar_grouped.loc[name, 'Ders mesleki açıdan gerekli mi?'] * 10) 
            ders['oy_sayisi'] = int(ders_oy_sayisi[name])
# JSON dosyasını oku
json_file_path = 'dersler.json'  # JSON dosyasının yolu
with open(os.path.join("..",json_file_path), 'r', encoding='utf-8') as file:
    data = json.load(file)

guncelle_ogrenci_gorusleri(data,DERS_YORUMLARI_DOSYASI)
guncelle_ders_yildizlari(data, DERS_YILDIZLARI_DOSYASI)


with open(os.path.join(json_file_path), 'w', encoding='utf-8') as file:
    json.dump(data, file, ensure_ascii=False, indent=4)
# Dosyayı kopyalamak için:
shutil.copy(json_file_path, os.path.join("..",json_file_path))