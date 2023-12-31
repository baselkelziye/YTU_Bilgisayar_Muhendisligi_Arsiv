import pandas as pd
import json
import os
import shutil

from icerik_kontrol import *
temel_puan = 30
# Google Sheets dosyasının URL'si
yildizlar_sheets_url = "https://docs.google.com/spreadsheets/d/1w386auUiJaGwoUAmmkEgDtIRSeUplmDz0AZkM09xPTk/export?format=csv"
def guncelle_ogrenci_gorusleri(data, sheets_url):
    # Google Sheets verisini indir
    df = pd.read_csv(sheets_url)
    df = df.dropna()  # NaN içeren tüm satırları kaldır
    
    # Her hoca için yorumları güncelle
    for index, row in df.iterrows():
        hoca_adi = row['Hoca seç']
        kisi = row['İsmin nasıl gözüksün']
        yorum = row['Hoca hakkındaki yorumun']
        icerikKontrol = IcerikKontrol("hoca")
        if not pd.isna(yorum) and icerikKontrol.pozitif_mi(yorum):
            yorum = icerikKontrol.metin_on_isleme(yorum)
            for hoca in data['hocalar']:
                if hoca['ad'] == hoca_adi:
                    # Eğer bu kisi için daha önce bir yorum yapılmışsa, güncelle
                    gorus_var_mi = False
                    if 'ogrenci_gorusleri' not in hoca:
                        hoca['ogrenci_gorusleri'] = []
                    for gorus in hoca['ogrenci_gorusleri']:
                        if gorus['kisi'].lower() == kisi.lower():
                            gorus['yorum'] = yorum
                            gorus_var_mi = True
                            break
                    
                    # Yeni yorum ekle
                    if not gorus_var_mi:
                        hoca['ogrenci_gorusleri'].append({'kisi': kisi.lower().title(), 'yorum': yorum})
    icerikKontrol.dosya_yaz()
# Google Sheets URL'si
yorumlar_sheets_url = "https://docs.google.com/spreadsheets/d/1mexaMdOeB-hWLVP4MI_xmnKwGBuwoRDk6gY9zXDycyI/export?format=csv"

# Veriyi indir ve DataFrame olarak oku
yildizlar_df = pd.read_csv(yildizlar_sheets_url)


# Sadece sayısal sütunları al ve ortalama hesapla
yildizlar_numeric_columns = yildizlar_df.columns.drop(['Zaman damgası', 'Hoca seç'])  # Sayısal olmayan sütunları çıkar
yildizlar_grouped = yildizlar_df.groupby('Hoca seç')[yildizlar_numeric_columns].mean()

# Hocaların aldığı oyların (yani kaç defa seçildiğinin) frekansını hesapla
hoca_oy_sayisi = yildizlar_df['Hoca seç'].value_counts()

# En yüksek oy sayısına sahip hocayı bul
en_populer_hoca = hoca_oy_sayisi.idxmax()
en_populer_hoca_oy_sayisi = hoca_oy_sayisi.max()

# JSON dosyasını oku
json_file_path = 'hocalar.json'  # JSON dosyasının yolu
with open(os.path.join("..",json_file_path), 'r', encoding='utf-8') as file:
    data = json.load(file)
data["en_populer_hoca"] = {"hoca_adi":en_populer_hoca, "oy_sayisi":int(en_populer_hoca_oy_sayisi)}
for hoca in data['hocalar']:
    name = hoca.get('ad')
    if name in yildizlar_grouped.index:
        hoca['anlatim_puani'] = int(yildizlar_grouped.loc[name, 'Dersi ne kadar güzel anlatır?'] * 10 * 0.7) + temel_puan
        hoca['kolaylik_puani'] = int(yildizlar_grouped.loc[name, 'Dersini geçmek ne kadar kolaydır?'] * 10 * 0.7) + temel_puan
        hoca['ogretme_puani'] = int(yildizlar_grouped.loc[name, 'Dersi ne kadar iyi öğretir?'] * 10* 0.7) + temel_puan
        hoca['eglence_puani'] = int(yildizlar_grouped.loc[name, 'Dersi ne kadar eğlenceli anlatır?'] * 10 * 0.7) + temel_puan
        hoca['oy_sayisi'] = int(hoca_oy_sayisi[name])

# Fonksiyonu çağır ve JSON dosyasını güncelle
guncelle_ogrenci_gorusleri(data, yorumlar_sheets_url)


with open(json_file_path, 'w', encoding='utf-8') as file:
    json.dump(data, file, ensure_ascii=False, indent=4)

# Dosyayı kopyalamak için:
shutil.copy(json_file_path, os.path.join("..",json_file_path))