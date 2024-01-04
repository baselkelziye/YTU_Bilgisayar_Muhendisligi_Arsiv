import os
# GENEL DEGISKENLER
## ORTAK DEGISKENLER
DERSLER = "dersler"
BOLUM_ADI = "bolum_adi"
BOLUM_ACIKLAMASI = "bolum_aciklamasi"
ONERILER = "oneriler"
AD = "ad"
HOCALAR = "hocalar"
DERSLER = "dersler"
YIL = "yil"
DONEM = "donem"
TIP = "tip"
YOK = "yok"
KISALTMA = "kisaltma"
BASLIK = "baslik"
ACIKLAMA = "aciklama"
TALIMAT = "talimat"
KAVRAM = "kavram"
KAVRAMLAR = "kavramlar"
TALIMATLAR = "talimatlar"
ACIKLAMALAR = "aciklamalar"
KISI = "kisi"
YORUM = "yorum"
LINK = "link"
OFIS = "ofis"
OY_SAYISI = "oy_sayisi"
DONEMLER = "donemler"
DOSYA_YOLU = "dosya_yolu"
DONEM_ADI = "donem_adi"
OGRENCI_GORUSLERI = "ogrenci_gorusleri"

## DERSE OZEL DEGISKENLER
DERS_KLASORU_BULUNAMADI_MESAJI = "ders_klasoru_bulunamadi_mesaji"
GUNCEL_OLMAYAN_DERS_ACIKLAMASI = "guncel_olmayan_ders_aciklamasi"
FAYDALI_OLABILECEK_KAYNAKLAR = "faydali_olabilecek_kaynaklar"
DERSE_DAIR_ONERILER = "derse_dair_oneriler"
KOLAYLIK_PUANI = "kolaylik_puani"
GEREKLILIK_PUANI = "gereklilik_puani"
DERSI_VEREN_HOCALAR = "dersi_veren_hocalar"
GUNCEL_MI = "guncel_mi"
ONERI_SAHIBI = "oneri_sahibi"

## HOCAYA OZEL DEGISKENLER
ERKEK_MI = "erkek_mi"
HOCA_ADI = "hoca_adi"
EN_POPULER_HOCA = "en_populer_hoca"

## KATKIDA BULUNANLAR
KATKIDA_BULUNANLAR = "katkida_bulunanlar"
GITHUB_LINK = "github_link"


# VARSAYILAN DEGISKENLER
## HOCALAR
VARSAYILAN_HOCA_BOLUM_ACIKLAMASI = "Bu bölüm, Yıldız Teknik Üniversitesi X Mühendisliği bölümündeki hocaların detaylı bilgilerini içerir. Hocaların adları, ofis bilgileri, araştırma sayfalarının bağlantıları ve verdikleri bazı dersler bu bölümde listelenmektedir. Öğrenciler ve diğer ilgililer için hocalar hakkında temel bilgiler ve iletişim detayları sunulmaktadır. Hocaların puanlamaları tamamen subjektiftir ve  0-10 yıldız arasında yapılmıştır."  
VARSAYILAN_HOCA_BOLUM_ADI = "Hocalar"

## DERSLER
VARSAYILAN_DERS_BOLUM_ADI = "Dersler" 
VARSAYILAN_DERS_BOLUM_ACIKLAMASI = "Bu bölümde, tüm dersler hakkında detaylı bilgiler ve kaynaklar bulunmaktadır. Öğrenciler bu bölümü kullanarak ders materyallerine ve içeriklerine ulaşabilirler."           
VARSAYILAN_GUNCEL_OLMAYAN_DERS_ACIKLAMASI = "Bu ders artık müfredata dahil değildir. Ya tamamen kaldırılmış, ya ismi ve içeriği güncellenmiş ya da birleştirilmiş olabilir."
VARSAYILAN_DERS_KLASORU_BULUNAMADI_MESAJI =  "Henüz dersle alakalı bir döküman ne yazık ki yok. Katkıda bulunmak istersen lütfen bizimle iletişime geç..."      

# DOSYA ADLARI
DERSLER_JSON_NAME = "dersler.json"
DERSLER_JSON_PATH = os.path.join("..", DERSLER_JSON_NAME)
HOCALAR_JSON_NAME = "hocalar.json"
HOCALAR_JSON_PATH = os.path.join("..", HOCALAR_JSON_NAME)
ANA_README_YOLU = os.path.join("..","README.md")
KATKIDA_BULUNANLAR_JSON_NAME = "katkida_bulunanlar.json"
KATKIDA_BULUNANLAR_JSON_PATH = os.path.join("..", KATKIDA_BULUNANLAR_JSON_NAME)
REPO_KULLANIMI_JSON_NAME = "repo_kullanimi.json"
REPO_KULLANIMI_JSON_PATH = os.path.join("..", REPO_KULLANIMI_JSON_NAME)
YAZARIN_NOTLARI_JSON_NAME = "yazarin_notlari.json"
YAZARIN_NOTLARI_JSON_PATH = os.path.join("..", YAZARIN_NOTLARI_JSON_NAME)


# UNVAN KISALTMALARI
PROF_DR = "Prof. Dr."
DOC_DR = "Doç. Dr."
DR = "Dr."

# LINKLER
CIKMISLAR_LINKI = "https://drive.google.com/drive/folders/1LI_Bo7kWqI2krHTw0noUFl9crfZSlrZh"
YILDIZ_OYLAMA_LINKI = "https://forms.gle/s6ZMrQG4q578pEzm7"
HOCA_YORULMALA_LINKI = "https://forms.gle/WbwDxHUz6ebJA7t36"
DERS_OYLAMA_LINKI = "https://forms.gle/3njZjmhm215YCAxe6"
DERS_YORUMLAMA_LINKI = "https://forms.gle/SzNmK1w4rVaKE4ee8"

