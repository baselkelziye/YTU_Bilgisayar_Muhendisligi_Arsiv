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
EN_POPULER_DERS = "en_populer_ders"
DERS_ADI = "ders_adi"

## HOCAYA OZEL DEGISKENLER
ERKEK_MI = "erkek_mi"
HOCA_ADI = "hoca_adi"
EN_POPULER_HOCA = "en_populer_hoca"

## KATKIDA BULUNANLARA OZEL DEGISKENLER
KATKIDA_BULUNANLAR = "katkida_bulunanlar"
GITHUB_LINK = "github_link"
## GIRIS SAYFASINA OZEL DEGISKENLER
ICINDEKILER = "icindekiler"
## DONEM SAYFASINA OZEL DEGISKENLER
GENEL_TAVSIYELER = "genel_tavsiyeler"
# LINKLER
CIKMISLAR_LINKI = "https://drive.google.com/drive/folders/1LI_Bo7kWqI2krHTw0noUFl9crfZSlrZh"
HOCA_OYLAMA_LINKI = "https://forms.gle/s6ZMrQG4q578pEzm7"
HOCA_YORULMALA_LINKI = "https://forms.gle/WbwDxHUz6ebJA7t36"
DERS_OYLAMA_LINKI = "https://forms.gle/3njZjmhm215YCAxe6"
DERS_YORUMLAMA_LINKI = "https://forms.gle/SzNmK1w4rVaKE4ee8"
HOCA_OYLAMA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/1w386auUiJaGwoUAmmkEgDtIRSeUplmDz0AZkM09xPTk/export?format=csv"
HOCA_YORULMALA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/1mexaMdOeB-hWLVP4MI_xmnKwGBuwoRDk6gY9zXDycyI/export?format=csv"
DERS_OYLAMA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/e/2PACX-1vSDFicOFbJu9Fnc4Hl0mFuuaC0L4PiEmUFkkJrgocwWGWs1wB3TyN1zd4okW8svC6IT2HMIe64NQUUy/pub?output=csv"
DERS_YORUMLAMA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/e/2PACX-1vQvGyGLQxobIpaVdQItSpqEoiwJ0DIIHE9kVvCHhfKQ7yYR16c2tI_ix4Z9d2tA4aLt2c4fTLGxlL-s/pub?output=csv"


# VARSAYILAN DEGISKENLER
## HOCALAR
VARSAYILAN_HOCA_BOLUM_ACIKLAMASI = "Bu bölüm, Yıldız Teknik Üniversitesi X Mühendisliği bölümündeki hocaların detaylı bilgilerini içerir. Hocaların adları, ofis bilgileri, araştırma sayfalarının bağlantıları ve verdikleri bazı dersler bu bölümde listelenmektedir. Öğrenciler ve diğer ilgililer için hocalar hakkında temel bilgiler ve iletişim detayları sunulmaktadır. Hocaların puanlamaları tamamen subjektiftir ve  0-10 yıldız arasında yapılmıştır."  
VARSAYILAN_HOCA_BOLUM_ADI = "Hocalar"

## DERSLER
VARSAYILAN_DERS_BOLUM_ADI = "Dersler" 
VARSAYILAN_DERS_BOLUM_ACIKLAMASI = "Bu bölümde, tüm dersler hakkında detaylı bilgiler ve kaynaklar bulunmaktadır. Öğrenciler bu bölümü kullanarak ders materyallerine ve içeriklerine ulaşabilirler."           
VARSAYILAN_GUNCEL_OLMAYAN_DERS_ACIKLAMASI = "Bu ders artık müfredata dahil değildir. Ya tamamen kaldırılmış, ya ismi ve içeriği güncellenmiş ya da birleştirilmiş olabilir."
VARSAYILAN_DERS_KLASORU_BULUNAMADI_MESAJI =  "Henüz dersle alakalı bir döküman ne yazık ki yok. Katkıda bulunmak istersen lütfen bizimle iletişime geç..."      

## GIRIS SAYFASI
VARSAYILAN_GIRIS_BASLIK = "Yıldız Teknik Üniversitesi X Mühendisliği Ders Notları"
VARSAYILAN_GIRIS_ACIKLAMA = f"Bu repository, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği bölümünde verilen derslerin notları, örnek soruları ve ilgili kaynakları barındırmaktadır. Öğrencilerin dersleri daha etkin bir şekilde öğrenmelerini desteklemek amacıyla hazırlanmıştır. Hocalarla [yorum için bu link]({HOCA_YORULMALA_LINKI}) [yildiz için bu link]({HOCA_OYLAMA_LINKI}) ya da derslerle alakalı [yorum için bu link]({DERS_YORUMLAMA_LINKI}) [yildiz için bu link]({DERS_OYLAMA_LINKI}) hakaret içermeyen yorumlarını ve puanlamalarını bizimle anonim olarak paylaşabilirsin."

## KATKIDA BULUNANLAR
VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ADI = "Katkıda Bulunanlar"
VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ACIKLAMASI = "Bu bölümde reponun hazırlanmasında katkıda bulunan insanlar listelenmiştir. Siz de katkıda bulunmak isterseniz bizimle iletişime geçin. Ya da merge request gönderin."

## YAZARIN NOTLARI
VARSAYILAN_YAZARIN_NOTLARI_BOLUM_ADI = "Yazarın Notları"

## REPONUN KULLANIMI
VARSAYILAN_REPO_KULLANIMI_BOLUM_ADI = "Repo Kullanımı"
VARSAYILAN_TALIMATLAR_BOLUM_ADI = "Talimatlar"
VARSAYILAN_KAVRAMLAR_BOLUM_ADI = "Kavramlar"
VARSAYILAN_ACIKLAMALAR_BOLUM_ADI = "Açıklamalar"

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
GIRIS_JSON_NAME = "giris.json"
GIRIS_JSON_PATH = os.path.join("..", GIRIS_JSON_NAME)
DONEMLER_JSON_NAME = "donemler.json"
DONEMLER_JSON_PATH = os.path.join("..", DONEMLER_JSON_NAME)

# UNVAN KISALTMALARI
PROF_DR = "Prof. Dr."
DOC_DR = "Doç. Dr."
DR = "Dr."


# STİLLER

## BUTON STİLLERİ
EKLE_BUTONU_STILI = "background-color: green; color: white;"
SIL_BUTONU_STILI = "background-color: red; color: white;"
TEMIZLE_BUTONU_STILI = "background-color: orange; color: white;"
VEREN_EKLE_BUTONU_STILI = "background-color: lightblue;"
GUNCELLE_BUTTON_STILI = "background-color: blue; color: white;"
BASLIK_BUTON_STILI = "background-color: lightblue; color: black;"
ACIKLAMA_BUTON_STILI = "background-color: lightgreen; color: black;"


# JSON ANAHTARLARI

## HOCALAR
ANLATIM_PUANI = "anlatim_puani"
OGRETME_PUNAI = "ogretme_puani"
EGLENCE_PUANI = "eglence_puani"


# GOOGLE FORM DEĞİŞKENLERİ

## ORTAK
ZAMAN_DAMGASI = "Zaman damgası"

## DERSLER

DERS_SEC = "Ders Seç"
ISMIN_NASIL_GORUNSUN = "İsmin Nasıl Gözüksün"
DERS_HAKKINDAKI_YORUMUN = "Ders hakkındaki yorumun"
DERS_MESLEKI_ACIDAN_GEREKLI_MI = "Ders mesleki açıdan gerekli mi?"
DERSI_GECMEK_NE_KADAR_KOLAY = "Dersi geçmek ne kadar kolay?"

## HOCALAR
HOCA_SEC = "Hoca seç"
ISMIN_NASIL_GOZUKSUN_HOCA = "İsmin nasıl gözüksün"
HOCA_HAKKINDAKI_YORUMUN = 'Hoca hakkındaki yorumun'
DERSI_NE_KADAR_GÜZEL_ANLATIR = 'Dersi ne kadar güzel anlatır?'
DERSINI_GECMEK_NE_KADAR_KOLAYDIR = 'Dersini geçmek ne kadar kolaydır?'
DERSI_NE_KADAR_IYI__OGRETIR = 'Dersi ne kadar iyi öğretir?'
DERSI_NE_KADAR_EGLENCELI_ANLATIR = 'Dersi ne kadar eğlenceli anlatır?'

# DOSYA ADLARI
GOOGLE_FORM_GUNCELLE = "google_form_guncelle"
README_GUNCELLE = "readme_guncelle"
DEGISIKLIKLERI_GITHUBA_YOLLA = "degisiklikleri_githuba_yolla"
HOCA_ICERIKLERI_GUNCELLE = "hoca_icerikleri_guncelle"
RUTIN_KONTROL = "rutin_kontrol"
ARAYUZU_GITHULA_ESITLE = "arayuzu_githubla_esitle"
## BAT DOSYALARI
GOOGLE_FORM_GUNCELLE_BAT = GOOGLE_FORM_GUNCELLE + ".bat"
README_GUNCELLE_BAT = README_GUNCELLE + ".bat"
DEGISIKLIKLERI_GITHUBA_YOLLA_BAT = DEGISIKLIKLERI_GITHUBA_YOLLA + ".bat"
HOCA_ICERIKLERI_GUNCELLE_BAT = HOCA_ICERIKLERI_GUNCELLE + ".bat"
RUTIN_KONTROL_BAT = RUTIN_KONTROL + ".bat"
ARAYUZU_GITHULA_ESITLE_BAT = ARAYUZU_GITHULA_ESITLE + ".bat"
## SH DOSYALARI
GOOGLE_FORM_GUNCELLE_SH = GOOGLE_FORM_GUNCELLE + ".sh"
README_GUNCELLE_SH = README_GUNCELLE + ".sh"
DEGISIKLIKLERI_GITHUBA_YOLLA_SH = DEGISIKLIKLERI_GITHUBA_YOLLA + ".sh"
HOCA_ICERIKLERI_GUNCELLE_SH = HOCA_ICERIKLERI_GUNCELLE + ".sh"
RUTIN_KONTROL_SH = RUTIN_KONTROL + ".sh"
ARAYUZU_GITHULA_ESITLE_SH = ARAYUZU_GITHULA_ESITLE + ".sh"

# IKONLAR

## IKON ADLARI
IKON_PATH = "ikonlar"
SELCUKLU_ICO = "selcuklu.png"
OSMANLI_ICO = "osmanli.png"

## IKON YOLLARI
OSMANLI_ICO_PATH = os.path.join(IKON_PATH, OSMANLI_ICO)
SELCUKLU_ICO_PATH = os.path.join(IKON_PATH, SELCUKLU_ICO)

# DONEMLER
MESLEKI_SECMELI = "Mesleki Seçmeli"
GUZ = "Güz"
BAHAR = "Bahar"
SECMELI_4 = "Seçmeli 4"
SECMELI = "Seçmeli"
ZORUNLU = "Zorunlu"
DERS_TIPLERI = [ZORUNLU,SECMELI, SECMELI_4, MESLEKI_SECMELI]
DONEM_YILLARI = ['1', '2', '3', '4']
DONEMLER_DIZISI = [GUZ, BAHAR]
DONEMLER_DIZISI_YOKLA_BERABER = [YOK, GUZ, BAHAR]

# GİRİŞ SAYFASI
GERI_BILDIRIM_KISMI =f""" ## 🗣️ Geri Bildirimde Bulunun

📬 Öğrenciler ve hocalar, derslerle ilgili hakaret içermeyen geri bildirimlerinizi aşağıdaki linkler aracılığıyla anonim olarak paylaşabilirsiniz.

- [✍️ **Hocalar için yorum linki**]({HOCA_YORULMALA_LINKI})
- [⭐ **Hocalar için yıldız linki**]({HOCA_OYLAMA_LINKI})
- [✍️ **Dersler için yorum linki**]({DERS_YORUMLAMA_LINKI})
- [⭐ **Dersler için yıldız linki**]({DERS_OYLAMA_LINKI})
"""