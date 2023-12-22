import pandas as pd
import os
import json
DERS_YILDIZLARI_DOSYASI = "https://docs.google.com/spreadsheets/d/12Gv8QS5py8jBmbylnyLCZdZ-oxCSsVlXZUVW4JvvHAE/export?format=csv"
DERS_YORUMLARI_DOSYASI = "https://docs.google.com/spreadsheets/d/1d9B_YSk6em2wBAR85PutZkNAoSy_ET1-ojcjU3ypLE8/export?format=csv"


def guncelle_ogrenci_gorusleri(data, sheets_url):
    # Google Sheets verisini indir
    df = pd.read_csv(sheets_url)

    # Her hoca için yorumları güncelle
    for index, row in df.iterrows():
        ders_adi = row['Ders Seç']
        kisi = row['İsmin Nasıl Gözüksün']
        yorum = row['Ders hakkındaki yorumun']

        for hoca in data['dersler']:
            if hoca['ad'] == ders_adi:
                # Eğer bu kisi için daha önce bir yorum yapılmışsa, güncelle
                gorus_var_mi = False
                for gorus in hoca['ogrenci_gorusleri']:
                    if gorus['kisi'] == kisi:
                        gorus['yorum'] = yorum
                        gorus_var_mi = True
                        break
                
                # Yeni yorum ekle
                if not gorus_var_mi:
                    hoca['ogrenci_gorusleri'].append({'kisi': kisi, 'yorum': yorum})
def guncelle_ders_yildizlari(data, sheets_url):
    
    # Veriyi indir ve DataFrame olarak oku
    yildizlar_df = pd.read_csv(sheets_url)


    # Sadece sayısal sütunları al ve ortalama hesapla
    yildizlar_numeric_columns = yildizlar_df.columns.drop(['Zaman damgası', 'Ders Seç'])  # Sayısal olmayan sütunları çıkar
    yildizlar_grouped = yildizlar_df.groupby('Ders Seç')[yildizlar_numeric_columns].mean()
    # Hocaların aldığı oyların (yani kaç defa seçildiğinin) frekansını hesapla
    en_dusuk_ortalama = yildizlar_grouped['Dersi geçmek ne kadar kolay?'].min()
    # En düşük ortalamanın dersini bul
    en_dusuk_ortalama_ders = yildizlar_grouped[yildizlar_grouped['Dersi geçmek ne kadar kolay?'] == en_dusuk_ortalama].index[0]
    
    ders_oy_sayisi = yildizlar_df['Ders Seç'].value_counts()
    
    en_dusuk_ortalama_ders_oy_sayisi = ders_oy_sayisi.max()

    # En yüksek oy sayısına sahip hocayı bul
    en_populer_ders = ders_oy_sayisi.idxmax()
    en_populer_ders_oy_sayisi = ders_oy_sayisi.max()
    data["en_populer_ders"] = {"ders_adi":en_populer_ders, "oy_sayisi":en_populer_ders_oy_sayisi}
    data["en_zor_ders"] = {"ders_adi":en_dusuk_ortalama_ders,"zorluk_puani":int((10 - en_dusuk_ortalama) * 10), "oy_sayisi":en_dusuk_ortalama_ders_oy_sayisi}
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

with open(json_file_path, 'w', encoding='utf-8') as file:
    json.dump(data, file, ensure_ascii=False, indent=4)