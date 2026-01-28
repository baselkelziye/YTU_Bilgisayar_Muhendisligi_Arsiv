import pandas as pd
import json
import os
import shutil
try:
    from google_forum_islemleri.icerik_kontrol import *
    from google_forum_islemleri.csv_kontrol_et import csv_kontrol_et
except ImportError:
    from icerik_kontrol import *
    from csv_kontrol_et import csv_kontrol_et
import sys

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

SLEEP_TIME = 10


def guncelle_ogrenci_gorusleri(data, sheets_url):
    try:
        # Google Sheets verisini indir
        df = pd.read_csv(sheets_url)
        df.to_csv(HOCALAR_YORUM_CSV_PATH, index=False)
    except Exception as e:
        custom_write_error(f"CSV dosyası okunurken hata oluştu: {e}\n")
        raise SystemExit(1)
    # Öncelikle mevcut sütun isimlerini alın
    mevcut_sutun_isimleri = df.columns
    # Yeni isimleri bir sözlük yapısında belirtin
    yeniden_adlandirma = {
        mevcut_sutun_isimleri[0]: ZAMAN_DAMGASI,
        mevcut_sutun_isimleri[1]: HOCA_SEC,
        mevcut_sutun_isimleri[2]: ISMIN_NASIL_GOZUKSUN_HOCA,
        mevcut_sutun_isimleri[3]: HOCA_HAKKINDAKI_YORUMUN,
    }

    # DataFrame'i yeniden adlandırın
    df = df.rename(columns=yeniden_adlandirma)
    if not csv_kontrol_et(
        df,
        [ZAMAN_DAMGASI, HOCA_SEC, ISMIN_NASIL_GOZUKSUN_HOCA, HOCA_HAKKINDAKI_YORUMUN],
    ):
        custom_write_error("CSV dosyası hatalı, script durduruluyor.\n")
        raise SystemExit(1)
    df = df.dropna()  # NaN içeren tüm satırları kaldır

    # Her hoca için yorumları güncelle
    for index, row in df.iterrows():
        hoca_adi = row[HOCA_SEC]
        kisi = row[ISMIN_NASIL_GOZUKSUN_HOCA]
        # Yorumu alma ve sansürleme işlemi
        yorum = metin_sansurle(row.get(HOCA_HAKKINDAKI_YORUMUN, ""))
        yorum_tarihi = pd.to_datetime(
            row.iloc[0], format="%d.%m.%Y %H:%M:%S"
        )  # tarih bilgisi
        yorum_tarihi = {
            YIL: yorum_tarihi.year,
            AY: yorum_tarihi.month,
            GUN: yorum_tarihi.day,
        }
        # icerikKontrol = IcerikKontrol("hoca")
        if not pd.isna(yorum):  # and icerikKontrol.pozitif_mi(yorum):
            # yorum = icerikKontrol.metin_on_isleme(yorum)
            for hoca in data[HOCALAR]:
                if hoca[AD] == hoca_adi:
                    # Eğer bu kisi için daha önce bir yorum yapılmışsa, güncelle
                    gorus_var_mi = False
                    if OGRENCI_GORUSLERI not in hoca:
                        hoca[OGRENCI_GORUSLERI] = []
                    for gorus in hoca[OGRENCI_GORUSLERI]:
                        if gorus[KISI].lower() == kisi.lower():
                            gorus[YORUM] = yorum
                            gorus[KISI] = kisi.lower().title()
                            gorus[TARIH] = yorum_tarihi
                            gorus_var_mi = True
                            break

                    # Yeni yorum ekle
                    if not gorus_var_mi:
                        hoca[OGRENCI_GORUSLERI].append(
                            {
                                KISI: kisi.lower().title(),
                                YORUM: yorum,
                                TARIH: yorum_tarihi,
                            }
                        )
    # icerikKontrol.dosya_yaz()


def yillaraGoreYildizSayisiDondur(yildizlar_yil_hoca_grouped, ad):
    # Hoca adına ve yıla göre gruplanmış veriden, belirtilen hoca için verileri filtrele
    hoca_filtr = yildizlar_yil_hoca_grouped.xs(ad, level=HOCA_SEC, drop_level=False)

    # Filtrelenmiş veri üzerinde iterasyon yaparak her bir yıl için ders değerlendirmelerini topla
    yildizlar_listesi = []
    for yil, row in hoca_filtr.iterrows():
        yildizlar = {
            ANLATIM_PUANI: int(row[DERSI_NE_KADAR_GUZEL_ANLATIR] * YILDIZ_KATSAYISI),
            KOLAYLIK_PUANI: int(
                row[DERSINI_GECMEK_NE_KADAR_KOLAYDIR] * YILDIZ_KATSAYISI
            ),
            OGRETME_PUNAI: int(row[DERSI_NE_KADAR_IYI__OGRETIR] * YILDIZ_KATSAYISI),
            EGLENCE_PUANI: int(
                row[DERSI_NE_KADAR_EGLENCELI_ANLATIR] * YILDIZ_KATSAYISI
            ),
            YIL: yil[1],
            OY_SAYISI: int(row[OY_SAYISI]),
        }
        yildizlar_listesi.append(yildizlar)

    return yildizlar_listesi


def main():
    """
    Hoca içeriklerini Google Form verilerinden güncelleyen ana fonksiyon.
    Bu fonksiyon doğrudan çağrılabilir veya modül olarak import edilebilir.
    """
    custom_write("Hoca içerikleri güncelleniyor...\n")
    
    # Google Sheets dosyasının URL'si
    yildizlar_sheets_url = HOCA_OYLAMA_LINKI_CSV
    
    # Google Sheets URL'si
    yorumlar_sheets_url = HOCA_YORULMALA_LINKI_CSV

    # Veriyi indir ve DataFrame olarak oku
    try:
        yildizlar_df = pd.read_csv(yildizlar_sheets_url)
        yildizlar_df.to_csv(HOCALAR_YILDIZ_CSV_PATH, index=False)
    except Exception as e:
        custom_write_error(f"CSV dosyası okunurken hata oluştu: {e}\n")
        raise SystemExit(1)
    # Mevcut sütun isimlerini alın
    mevcut_sutun_isimleri = yildizlar_df.columns

    # Yeni isimleri bir sözlük yapısında belirtin
    yeniden_adlandirma = {
        mevcut_sutun_isimleri[0]: ZAMAN_DAMGASI,
        mevcut_sutun_isimleri[1]: HOCA_SEC,
        mevcut_sutun_isimleri[2]: DERSI_NE_KADAR_GUZEL_ANLATIR,
        mevcut_sutun_isimleri[3]: DERSINI_GECMEK_NE_KADAR_KOLAYDIR,
        mevcut_sutun_isimleri[4]: DERSI_NE_KADAR_IYI__OGRETIR,
        mevcut_sutun_isimleri[5]: DERSI_NE_KADAR_EGLENCELI_ANLATIR,
    }

    # DataFrame'i yeniden adlandırın
    yildizlar_df = yildizlar_df.rename(columns=yeniden_adlandirma)

    if not csv_kontrol_et(
        yildizlar_df,
        [
            ZAMAN_DAMGASI,
            HOCA_SEC,
            DERSI_NE_KADAR_GUZEL_ANLATIR,
            DERSINI_GECMEK_NE_KADAR_KOLAYDIR,
            DERSI_NE_KADAR_IYI__OGRETIR,
            DERSI_NE_KADAR_EGLENCELI_ANLATIR,
        ],
    ):
        custom_write_error("CSV dosyası hatalı, script durduruluyor.\n")
        raise SystemExit(1)

    yildizlar_df = yildizlar_df.dropna()
    # Sadece sayısal sütunları al ve ortalama hesapla
    yildizlar_numeric_columns = yildizlar_df.columns.drop(
        [ZAMAN_DAMGASI, HOCA_SEC]
    )  # Sayısal olmayan sütunları çıkar
    yildizlar_grouped = yildizlar_df.groupby(HOCA_SEC)[yildizlar_numeric_columns].mean()
    # Yorum tarihinden yılı çıkarıp yeni bir sütun oluştur
    yildizlar_df[YIL] = pd.to_datetime(
        yildizlar_df.iloc[:, 0], format="%d.%m.%Y %H:%M:%S"
    ).dt.year

    # bunun amacı yıllara göre ortalama yansıtabilmek
    yildizlar_yil_hoca_grouped = yildizlar_df.groupby([HOCA_SEC, YIL])[
        yildizlar_numeric_columns
    ].mean()

    # Grup boyutlarını hesapla ve bir sütun olarak ekle
    grup_boyutlari = yildizlar_df.groupby([HOCA_SEC, YIL]).size().rename(OY_SAYISI)

    # Ortalamalar ve grup boyutları DataFrame'lerini birleştir
    yildizlar_yil_hoca_grouped = yildizlar_yil_hoca_grouped.join(grup_boyutlari)

    # Hocaların aldığı oyların (yani kaç defa seçildiğinin) frekansını hesapla
    hoca_oy_sayisi = yildizlar_df[HOCA_SEC].value_counts()

    # Eğer veri setinde hiç veri yoksa, hata vermesini önlemek için kontrol ekle
    if len(hoca_oy_sayisi) > 0:
        en_populer_hoca = hoca_oy_sayisi.idxmax()
        en_populer_hoca_oy_sayisi = hoca_oy_sayisi.max()
    else:
        en_populer_hoca = "MEVCUT DEĞİL"  # veya uygun bir varsayılan değer
        en_populer_hoca_oy_sayisi = 0  # veya uygun bir varsayılan değer

    # JSON dosyasını oku
    json_file_path = HOCALAR_JSON_NAME  # JSON dosyasının yolu
    with open(os.path.join(BIR_UST_DIZIN, json_file_path), "r", encoding="utf-8") as file:
        data = json.load(file)
    # en popüler hoca aynı oy sayısına sahip başka hoca varsa değişmesin
    if data.get(EN_POPULER_HOCA, {}).get(OY_SAYISI, 0) != int(en_populer_hoca_oy_sayisi):
        data[EN_POPULER_HOCA] = {
            HOCA_ADI: en_populer_hoca,
            OY_SAYISI: int(en_populer_hoca_oy_sayisi),
        }
    for hoca in data[HOCALAR]:
        name = hoca.get(AD, "")
        if name in yildizlar_grouped.index:
            hoca[ANLATIM_PUANI] = int(
                yildizlar_grouped.loc[name, DERSI_NE_KADAR_GUZEL_ANLATIR] * YILDIZ_KATSAYISI
            )
            hoca[KOLAYLIK_PUANI] = int(
                yildizlar_grouped.loc[name, DERSINI_GECMEK_NE_KADAR_KOLAYDIR]
                * YILDIZ_KATSAYISI
            )
            hoca[OGRETME_PUNAI] = int(
                yildizlar_grouped.loc[name, DERSI_NE_KADAR_IYI__OGRETIR] * YILDIZ_KATSAYISI
            )
            hoca[EGLENCE_PUANI] = int(
                yildizlar_grouped.loc[name, DERSI_NE_KADAR_EGLENCELI_ANLATIR]
                * YILDIZ_KATSAYISI
            )
            hoca[OY_SAYISI] = int(hoca_oy_sayisi[name])
        if name in yildizlar_yil_hoca_grouped.index:
            hoca[YILLARA_GORE_YILDIZ_SAYILARI] = yillaraGoreYildizSayisiDondur(
                yildizlar_yil_hoca_grouped, ad=name
            )

    # Fonksiyonu çağır ve JSON dosyasını güncelle
    guncelle_ogrenci_gorusleri(data, yorumlar_sheets_url)

    json_file_name = os.path.basename(json_file_path)
    with open(json_file_name, "w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=4)

    # Dosyayı kopyalamak için:
    shutil.copy(json_file_name, os.path.join(BIR_UST_DIZIN, json_file_path))
    custom_write("Hoca içerikleri güncellendi.\n")


if __name__ == "__main__":
    main()

