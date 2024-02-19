import pandas as pd
import os
import json
import shutil
from icerik_kontrol import *
import sys
from csv_kontrol_et import csv_kontrol_et

# Mevcut dosyanın bulunduğu dizini al
current_directory = os.path.dirname(os.path.abspath(__file__))
# Göreceli yol (örneğin, bu dizinden 'readme_guncelleme_arayuzu_python' klasörüne giden yol)
relative_path = os.path.join("..", "readme_guncelleme_arayuzu_python")
# Göreceli yolu tam yola çevir
absolute_path = os.path.join(current_directory, relative_path)
# Tam yolu sys.path listesine ekle
sys.path.append(absolute_path)
from degiskenler import *
from cikti_yazdirma import custom_write, custom_write_error

custom_write("Ders içerikleri güncelleniyor...\n")

SLEEP_TIME = 10

DERS_YILDIZLARI_DOSYASI = DERS_OYLAMA_LINKI_CSV
DERS_YORUMLARI_DOSYASI = DERS_YORUMLAMA_LINKI_CSV


def guncelle_ogrenci_gorusleri(data, sheets_url):
    # Google Sheets verisini indir
    try:
        df = pd.read_csv(sheets_url)
    except Exception as e:
        custom_write_error(f"CSV dosyası okunurken hata oluştu: {e}")
        exit(1)
    # Mevcut sütun isimlerini alın
    mevcut_sutun_isimleri = df.columns

    # Yeni isimleri bir sözlük yapısında belirtin
    yeniden_adlandirma = {
        mevcut_sutun_isimleri[0]: ZAMAN_DAMGASI,
        mevcut_sutun_isimleri[1]: DERS_SEC,
        mevcut_sutun_isimleri[2]: ISMIN_NASIL_GORUNSUN,
        mevcut_sutun_isimleri[3]: DERS_HAKKINDAKI_YORUMUN,
    }

    # DataFrame'i yeniden adlandırın
    df = df.rename(columns=yeniden_adlandirma)

    if not csv_kontrol_et(
        df, [ZAMAN_DAMGASI, DERS_SEC, ISMIN_NASIL_GORUNSUN, DERS_HAKKINDAKI_YORUMUN]
    ):
        custom_write_error("CSV dosyası hatalı, script durduruluyor.\n")
        exit(1)
    df = df.dropna()  # NaN içeren tüm satırları kaldır
    # Her ders için yorumları güncelle
    for index, row in df.iterrows():
        ders_adi = row[DERS_SEC]
        kisi = row[ISMIN_NASIL_GORUNSUN]
        yorum = metin_sansurle(row.get(DERS_HAKKINDAKI_YORUMUN, ""))
        # icerikKontrol = IcerikKontrol("ders")
        if not pd.isna(yorum):  # and icerikKontrol.pozitif_mi(yorum):
            # yorum = icerikKontrol.metin_on_isleme(yorum)
            for ders in data[DERSLER]:
                if ders[AD] == ders_adi:
                    # Eğer bu kisi için daha önce bir yorum yapılmışsa, güncelle
                    gorus_var_mi = False
                    if OGRENCI_GORUSLERI not in ders:
                        ders[OGRENCI_GORUSLERI] = []
                    for gorus in ders[OGRENCI_GORUSLERI]:
                        if gorus[KISI].lower() == kisi.lower():
                            gorus[YORUM] = yorum
                            gorus[KISI] = kisi.lower().title()
                            gorus_var_mi = True
                            break

                    # Yeni yorum ekle
                    if not gorus_var_mi:
                        ders[OGRENCI_GORUSLERI].append(
                            {KISI: kisi.lower().title(), YORUM: yorum}
                        )
    # icerikKontrol.dosya_yaz()


def guncelle_ders_yildizlari(data, sheets_url):
    try:
        # Veriyi indir ve DataFrame olarak oku
        yildizlar_df = pd.read_csv(sheets_url)
    except Exception as e:
        custom_write_error(f"CSV dosyası okunurken hata oluştu: {e}\n")
        exit(1)
    # Mevcut sütun isimlerini alın
    mevcut_sutun_isimleri = yildizlar_df.columns

    # Yeni isimleri bir sözlük yapısında belirtin
    yeniden_adlandirma = {
        mevcut_sutun_isimleri[0]: ZAMAN_DAMGASI,
        mevcut_sutun_isimleri[1]: DERS_SEC,
        mevcut_sutun_isimleri[2]: DERSI_GECMEK_NE_KADAR_KOLAY,
        mevcut_sutun_isimleri[3]: DERS_MESLEKI_ACIDAN_GEREKLI_MI,
    }

    # DataFrame'i yeniden adlandırın
    yildizlar_df = yildizlar_df.rename(columns=yeniden_adlandirma)

    if not csv_kontrol_et(
        yildizlar_df,
        [
            ZAMAN_DAMGASI,
            DERS_SEC,
            DERSI_GECMEK_NE_KADAR_KOLAY,
            DERS_MESLEKI_ACIDAN_GEREKLI_MI,
        ],
    ):
        custom_write_error("CSV dosyası hatalı, script durduruluyor.\n")
        exit(1)

    # Sadece sayısal sütunları al ve ortalama hesapla
    yildizlar_numeric_columns = yildizlar_df.columns.drop(
        [ZAMAN_DAMGASI, DERS_SEC]
    )  # Sayısal olmayan sütunları çıkar
    yildizlar_grouped = yildizlar_df.groupby(DERS_SEC)[yildizlar_numeric_columns].mean()
    # Hocaların aldığı oyların (yani kaç defa seçildiğinin) frekansını hesapla
    ders_oy_sayisi = yildizlar_df[DERS_SEC].value_counts()
    # Eğer veri setinde hiç veri yoksa, hata vermesini önlemek için kontrol ekle
    if len(ders_oy_sayisi) > 0:
        en_populer_ders = ders_oy_sayisi.idxmax()
        en_populer_ders_oy_sayisi = ders_oy_sayisi.max()
    else:
        en_populer_ders = "MEVCUT DEĞİL"  # veya uygun bir varsayılan değer
        en_populer_ders_oy_sayisi = 0  # veya uygun bir varsayılan değer
    if data.get(EN_POPULER_DERS, {}).get(OY_SAYISI, 0) != int(
        en_populer_ders_oy_sayisi
    ):
        data[EN_POPULER_DERS] = {
            DERS_ADI: en_populer_ders,
            OY_SAYISI: int(en_populer_ders_oy_sayisi),
        }
    for ders in data[DERSLER]:
        name = ders.get(AD)
        if name in yildizlar_grouped.index:
            ders[KOLAYLIK_PUANI] = int(
                yildizlar_grouped.loc[name, DERSI_GECMEK_NE_KADAR_KOLAY] * 10
            )
            ders[GEREKLILIK_PUANI] = int(
                yildizlar_grouped.loc[name, DERS_MESLEKI_ACIDAN_GEREKLI_MI] * 10
            )
            ders[OY_SAYISI] = int(ders_oy_sayisi[name])


# JSON dosyasını oku
json_file_path = DERSLER_JSON_NAME  # JSON dosyasının yolu
with open(os.path.join(BIR_UST_DIZIN, json_file_path), "r", encoding="utf-8") as file:
    data = json.load(file)

guncelle_ogrenci_gorusleri(data, DERS_YORUMLARI_DOSYASI)
guncelle_ders_yildizlari(data, DERS_YILDIZLARI_DOSYASI)

json_file_name = os.path.basename(json_file_path)
with open(json_file_name, "w", encoding="utf-8") as file:
    json.dump(data, file, ensure_ascii=False, indent=4)
# Dosyayı kopyalamak için:
shutil.copy(json_file_name, os.path.join(BIR_UST_DIZIN, json_file_path))

custom_write("Ders içerikleri güncellendi.\n")
