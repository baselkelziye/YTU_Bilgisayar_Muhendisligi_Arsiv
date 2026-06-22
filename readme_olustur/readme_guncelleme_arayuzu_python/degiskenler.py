import os, json, sys
from github_metin_islemleri import github_kullanici_adi_getir, hash_url_39

# GENEL DEGISKENLER
## ORTAK DEGISKENLER
DERSLER = "dersler"
BOLUM_ADI = "bolum_adi"
BOLUM_ACIKLAMASI = "bolum_aciklamasi"
ONERILER = "oneriler"
NFKD = "NFKD"
AD = "ad"
HOCALAR = "hocalar"
DERSLER = "dersler"
YIL = "yil"
AY = "ay"
GUN = "gun"
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
TARIH = "tarih"
LINK = "link"
OFIS = "ofis"
OY_SAYISI = "oy_sayisi"
YILLARA_GORE_YILDIZ_SAYILARI = "yillara_gore_yildiz_sayilari"
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
KATKIDA_BULUNMA_ORANI = "katkida_bulunma_orani"
ILETISIM_BILGILERI = "iletisim_bilgileri"
## GIRIS SAYFASINA OZEL DEGISKENLER
ICINDEKILER = "icindekiler"
## DONEM SAYFASINA OZEL DEGISKENLER
GENEL_TAVSIYELER = "genel_tavsiyeler"

# ÇAPA DESENİ
capa_deseni = r"\[(.*?)\]\((.*?)\)"

# LINKLER
GITHUB_URL_ANAHTARI = "github_url"
CIKMISLAR_ANAHTARI = "cikmislar"
HOCA_YORUMLAMA_ANAHTARI = "hoca_yorumlama"
HOCA_OYLAMA_ANAHTARI = "hoca_oylama"
DERS_YORUMLAMA_ANAHTARI = "ders_yorumlama"
DERS_OYLAMA_ANAHTARI = "ders_oylama"
DERS_OYLAMA_CSV_ANAHTARI = "ders_oylama_csv"
DERS_YORUMLAMA_CSV_ANAHTARI = "ders_yorumlama_csv"
HOCA_OYLAMA_CSV_ANAHTARI = "hoca_oylama_csv"
HOCA_YORUMLAMA_CSV_ANAHTARI = "hoca_yorumlama_csv"

# VARSAYILAN DEGISKENLER
## HOCALAR
VARSAYILAN_HOCA_BOLUM_ACIKLAMASI = "Bu bölüm, Yıldız Teknik Üniversitesi X Mühendisliği bölümündeki hocaların detaylı bilgilerini içerir. Hocaların adları, ofis bilgileri, araştırma sayfalarının bağlantıları ve verdikleri bazı dersler bu bölümde listelenmektedir. Öğrenciler ve diğer ilgililer için hocalar hakkında temel bilgiler ve iletişim detayları sunulmaktadır. Hocaların puanlamaları tamamen subjektiftir ve  0-10 yıldız arasında yapılmıştır."
VARSAYILAN_HOCA_BOLUM_ADI = "Hocalar"
VARSAYILAN_HOCA_AKTIF_GOREVDE_DEGIL_MESAJI = "Bu hoca artık aktif görevde değil. Ya emekli olmuş ya da başka bir üniversiteye geçmiş olabilir."

## DERSLER
VARSAYILAN_DERS_BOLUM_ADI = "Dersler"
VARSAYILAN_DERS_BOLUM_ACIKLAMASI = "Bu bölümde, tüm dersler hakkında detaylı bilgiler ve kaynaklar bulunmaktadır. Öğrenciler bu bölümü kullanarak ders materyallerine ve içeriklerine ulaşabilirler."
VARSAYILAN_GUNCEL_OLMAYAN_DERS_ACIKLAMASI = "Bu ders artık müfredata dahil değildir. Ya tamamen kaldırılmış, ya ismi ve içeriği güncellenmiş ya da birleştirilmiş olabilir."
VARSAYILAN_DERS_KLASORU_BULUNAMADI_MESAJI = "Henüz dersle alakalı bir döküman ne yazık ki yok. Katkıda bulunmak istersen lütfen bizimle iletişime geç..."

## GIRIS SAYFASI
VARSAYILAN_GIRIS_BASLIK = "Yıldız Teknik Üniversitesi X Mühendisliği Ders Notları"
VARSAYILAN_GIRIS_ACIKLAMA = f"Bu repository, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği bölümünde verilen derslerin notları, örnek soruları ve ilgili kaynakları barındırmaktadır. Öğrencilerin dersleri daha etkin bir şekilde öğrenmelerini desteklemek amacıyla hazırlanmıştır."

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

FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI = "Kaynaklar öğrenciler tarafından oluşturulmuştur. Bundan dolayı içeriklerin doğruluğu garanti edilemez."

# DOSYA ADLARI
KARA_LISTE_TXT = "karaliste.txt"
STIL_QSS = "stil.qss"
README_MD = "README.md"

# PyInstaller uyumlu yol hesaplama
def _get_base_paths():
    """
    PyInstaller ve normal Python çalışması için temel yolları hesapla.
    Returns:
        tuple: (module_dir, project_root, bir_ust_dizin, internal_root)
    """
    if getattr(sys, 'frozen', False):
        # PyInstaller ile paketlenmiş
        # _MEIPASS: paket içindeki dosyalar (geçici dizin)
        bundle_dir = sys._MEIPASS
        # executable dir: artık proje kökü (kullanıcının çalıştığı dizin)
        exe_dir = os.path.dirname(sys.executable)
        
        # Proje kökü: executable'ın bulunduğu dizin (çıktıların yazılacağı yer)
        project_root = exe_dir
        # Paket içindeki modül dizini
        module_dir = bundle_dir
        # BIR_UST_DIZIN: executable'ın bulunduğu dizin (çıktılar buraya)
        bir_ust_dizin = project_root
        # INTERNAL_ROOT: Paketlenmiş kaynak dosyaları (google_forum_islemleri vs.)
        internal_root = bundle_dir
    else:
        # Normal Python çalışması
        # Bu dosyanın bulunduğu dizin (readme_guncelleme_arayuzu_python)
        module_dir = os.path.dirname(os.path.abspath(__file__))
        # Proje kökü (bir üst dizin)
        project_root = os.path.dirname(module_dir)
        # Göreli yol olarak ".." kullanılabilir ama mutlak yol daha güvenli
        bir_ust_dizin = project_root
        # Normal çalışmada internal root proje köküdür
        internal_root = project_root
    
    return module_dir, project_root, bir_ust_dizin, internal_root

_MODULE_DIR, _PROJECT_ROOT, BIR_UST_DIZIN, INTERNAL_ROOT = _get_base_paths()

# Göreli yol olarak da sakla (bazı yerler hala bunu bekliyor olabilir)
BIR_UST_DIZIN_GORELI = ".."


try:
    from PyQt6.QtCore import QSettings
except ImportError:
    class QSettings:
        def __init__(self, *args, **kwargs):
            pass
        def value(self, key, default=None):
            if key == "json_depo_yolu":
                return "."
            return default

GOOGLE_FORM_ISLEMLERI = "google_forum_islemleri"

settings = QSettings("YTU_Arsiv", "Readme_Guncelleyici")
JSON_DOSYALARI_DEPOSU = settings.value("json_depo_yolu", ".")

# QSettings'den gelen değer string olmayabilir, garanti edelim
if not isinstance(JSON_DOSYALARI_DEPOSU, str):
    JSON_DOSYALARI_DEPOSU = str(JSON_DOSYALARI_DEPOSU)

README_GUNCELLEME_PYTHON = "readme_guncelleme_arayuzu_python"

DERSLER_JSON_NAME = "dersler.json"
DERSLER_JSON_NAME = os.path.join(JSON_DOSYALARI_DEPOSU, DERSLER_JSON_NAME)
DERSLER_JSON_PATH = os.path.join(BIR_UST_DIZIN, DERSLER_JSON_NAME)


HOCALAR_JSON_NAME = "hocalar.json"
HOCALAR_JSON_NAME = os.path.join(JSON_DOSYALARI_DEPOSU, HOCALAR_JSON_NAME)
HOCALAR_JSON_PATH = os.path.join(BIR_UST_DIZIN, HOCALAR_JSON_NAME)

KONFIGURASYON_JSON_NAME = "konfigurasyon.json"
KONFIGURASYON_JSON_NAME = os.path.join(JSON_DOSYALARI_DEPOSU, KONFIGURASYON_JSON_NAME)
KONFIGURASYON_JSON_PATH = os.path.join(BIR_UST_DIZIN, KONFIGURASYON_JSON_NAME)

KATKIDA_BULUNANLAR_JSON_NAME = "katkida_bulunanlar.json"
KATKIDA_BULUNANLAR_JSON_NAME = os.path.join(
    JSON_DOSYALARI_DEPOSU, KATKIDA_BULUNANLAR_JSON_NAME
)
KATKIDA_BULUNANLAR_JSON_PATH = os.path.join(BIR_UST_DIZIN, KATKIDA_BULUNANLAR_JSON_NAME)

MAAS_ISTATISTIKLERI_TXT_ADI = "maas_istatistikleri.txt"
MAAS_ISTATISTIKLERI_TXT_NAME = os.path.join(
    JSON_DOSYALARI_DEPOSU, MAAS_ISTATISTIKLERI_TXT_ADI
)
MAAS_ISTATISTIKLERI_TXT_PATH = os.path.join(BIR_UST_DIZIN, MAAS_ISTATISTIKLERI_TXT_NAME)

REPO_KULLANIMI_JSON_NAME = "repo_kullanimi.json"
REPO_KULLANIMI_JSON_NAME = os.path.join(JSON_DOSYALARI_DEPOSU, REPO_KULLANIMI_JSON_NAME)
REPO_KULLANIMI_JSON_PATH = os.path.join(BIR_UST_DIZIN, REPO_KULLANIMI_JSON_NAME)

YAZARIN_NOTLARI_JSON_NAME = "yazarin_notlari.json"
YAZARIN_NOTLARI_JSON_NAME = os.path.join(
    JSON_DOSYALARI_DEPOSU, YAZARIN_NOTLARI_JSON_NAME
)
YAZARIN_NOTLARI_JSON_PATH = os.path.join(BIR_UST_DIZIN, YAZARIN_NOTLARI_JSON_NAME)

GIRIS_JSON_NAME = "giris.json"
GIRIS_JSON_NAME = os.path.join(JSON_DOSYALARI_DEPOSU, GIRIS_JSON_NAME)
GIRIS_JSON_PATH = os.path.join(BIR_UST_DIZIN, GIRIS_JSON_NAME)

DONEMLER_JSON_NAME = "donemler.json"
DONEMLER_JSON_NAME = os.path.join(JSON_DOSYALARI_DEPOSU, DONEMLER_JSON_NAME)
DONEMLER_JSON_PATH = os.path.join(BIR_UST_DIZIN, DONEMLER_JSON_NAME)

HOCALAR_YILDIZ_CSV_ADI = "HOCALAR_YILDIZLARI_DOSYASI.csv"
HOCALAR_YORUM_CSV_ADI = "HOCALAR_YORUMLARI_DOSYASI.csv"
DERSLER_YILDIZ_CSV_ADI = "DERSLER_YILDIZLARI_DOSYASI.csv"
DERSLER_YORUM_CSV_ADI = "DERS_YORUMLARI_DOSYASI.csv"

HOCALAR_YILDIZ_CSV_PATH = os.path.join(
    BIR_UST_DIZIN, JSON_DOSYALARI_DEPOSU, HOCALAR_YILDIZ_CSV_ADI
)
HOCALAR_YORUM_CSV_PATH = os.path.join(
    BIR_UST_DIZIN, JSON_DOSYALARI_DEPOSU, HOCALAR_YORUM_CSV_ADI
)
DERSLER_YILDIZ_CSV_PATH = os.path.join(
    BIR_UST_DIZIN, JSON_DOSYALARI_DEPOSU, DERSLER_YILDIZ_CSV_ADI
)
DERSLER_YORUM_CSV_PATH = os.path.join(
    BIR_UST_DIZIN, JSON_DOSYALARI_DEPOSU, DERSLER_YORUM_CSV_ADI
)

DOKUMANLAR_REPO_YOLU_ANAHTARI = "dokumanlar_repo_yolu"
try:
    if os.path.exists(KONFIGURASYON_JSON_PATH):
        tmp_konf_path = KONFIGURASYON_JSON_PATH
    elif os.path.exists(KONFIGURASYON_JSON_NAME):
        tmp_konf_path = KONFIGURASYON_JSON_NAME
    with open(tmp_konf_path, "r", encoding="utf-8") as konf_dosyasi:
        tmp_konf = json.load(konf_dosyasi)
        VARSAYILAN_GITHUB_URL = tmp_konf[GITHUB_URL_ANAHTARI]
        DOKUMANLAR_REPO_YOLU = os.path.join(
            JSON_DOSYALARI_DEPOSU, tmp_konf[DOKUMANLAR_REPO_YOLU_ANAHTARI]
        )
        CIKMISLAR_LINKI = tmp_konf[CIKMISLAR_ANAHTARI]
        HOCA_OYLAMA_LINKI = tmp_konf[HOCA_OYLAMA_ANAHTARI]
        HOCA_YORULMALA_LINKI = tmp_konf[HOCA_YORUMLAMA_ANAHTARI]
        DERS_OYLAMA_LINKI = tmp_konf[DERS_OYLAMA_ANAHTARI]
        DERS_YORUMLAMA_LINKI = tmp_konf[DERS_YORUMLAMA_ANAHTARI]
        HOCA_OYLAMA_LINKI_CSV = tmp_konf[HOCA_OYLAMA_CSV_ANAHTARI]
        HOCA_YORULMALA_LINKI_CSV = tmp_konf[HOCA_YORUMLAMA_CSV_ANAHTARI]
        DERS_OYLAMA_LINKI_CSV = tmp_konf[DERS_OYLAMA_CSV_ANAHTARI]
        DERS_YORUMLAMA_LINKI_CSV = tmp_konf[DERS_YORUMLAMA_CSV_ANAHTARI]

except:
    print("Konfigurasyon dosyası bulunamadı. Varsayılan konfigurasyonlar kullanılacak.")
    DOKUMANLAR_REPO_YOLU = os.path.join(JSON_DOSYALARI_DEPOSU, BIR_UST_DIZIN)
    CIKMISLAR_LINKI = (
        "https://drive.google.com/drive/folders/1LI_Bo7kWqI2krHTw0noUFl9crfZSlrZh"
    )
    HOCA_OYLAMA_LINKI = "https://forms.gle/s6ZMrQG4q578pEzm7"
    HOCA_YORULMALA_LINKI = "https://forms.gle/WbwDxHUz6ebJA7t36"
    DERS_OYLAMA_LINKI = "https://forms.gle/3njZjmhm215YCAxe6"
    DERS_YORUMLAMA_LINKI = "https://forms.gle/SzNmK1w4rVaKE4ee8"
    HOCA_OYLAMA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/1w386auUiJaGwoUAmmkEgDtIRSeUplmDz0AZkM09xPTk/export?format=csv"
    HOCA_YORULMALA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/1mexaMdOeB-hWLVP4MI_xmnKwGBuwoRDk6gY9zXDycyI/export?format=csv"
    DERS_OYLAMA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/e/2PACX-1vSDFicOFbJu9Fnc4Hl0mFuuaC0L4PiEmUFkkJrgocwWGWs1wB3TyN1zd4okW8svC6IT2HMIe64NQUUy/pub?output=csv"
    DERS_YORUMLAMA_LINKI_CSV = "https://docs.google.com/spreadsheets/d/e/2PACX-1vQvGyGLQxobIpaVdQItSpqEoiwJ0DIIHE9kVvCHhfKQ7yYR16c2tI_ix4Z9d2tA4aLt2c4fTLGxlL-s/pub?output=csv"
    VARSAYILAN_GITHUB_URL = (
        "https://github.com/baselkelziye/YTU_Bilgisayar_Muhendisligi_Arsiv"
    )
GENEL_CIKMIS_SORULAR_METNI = f"- 📄 [Genel Çıkmış Sorular]({CIKMISLAR_LINKI})\n"


ANA_README_YOLU = os.path.join(DOKUMANLAR_REPO_YOLU, README_MD)
# UNVAN KISALTMALARI
PROF_DR = "Prof. Dr."
DOC_DR = "Doç. Dr."
DR = "Dr."
ARS_GRV = "Arş. Grv."
unvanlar = [PROF_DR, DOC_DR, DR, ARS_GRV]

# STİLLER

## BUTON STİLLERİ
EKLE_BUTONU_STILI = "background-color: #27AE60; color: white;"  # Yeşil
SIL_BUTONU_STILI = "background-color: #C0392B; color: white;"  # Kırmızı
TEMIZLE_BUTONU_STILI = "background-color: #F39C12; color: white;"  # Turuncu
VEREN_EKLE_BUTONU_STILI = "background-color: #3498DB; color: white;"  # Açık Mavi
GUNCELLE_BUTTON_STILI = "background-color: #2980B9; color: white;"  # Mavi
BASLIK_BUTON_STILI = "background-color: #95A5A6; color: white;"  # Açık Gri
ACIKLAMA_BUTON_STILI = "background-color: #2ECC71; color: white;"  # Açık Yeşil
YUKARI_BUTON_STILI = "background-color: #2ecc71; color: white;"  # Açık Yeşil
ASAGI_BUTON_STILI = "background-color: #95a5a6; color: white;"  # Gri
LINK_KONTROL_BUTONU_STILI = "background-color: #E67E22; color: white;"  # Turuncu


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
HOCA_AKTIF_GOREVDE_MI = "hoca_aktif_gorevde_mi"
ISMIN_NASIL_GOZUKSUN_HOCA = "İsmin nasıl gözüksün"
HOCA_HAKKINDAKI_YORUMUN = "Hoca hakkındaki yorumun"
DERSI_NE_KADAR_GUZEL_ANLATIR = "Dersi ne kadar güzel anlatır?"
DERSINI_GECMEK_NE_KADAR_KOLAYDIR = "Dersini geçmek ne kadar kolaydır?"
DERSI_NE_KADAR_IYI__OGRETIR = "Dersi ne kadar iyi öğretir?"
DERSI_NE_KADAR_EGLENCELI_ANLATIR = "Dersi ne kadar eğlenceli anlatır?"

YILDIZ_KATSAYISI = 10

# DOSYA ADLARI
GOOGLE_FORM_GUNCELLE = "google_form_guncelle"
README_GUNCELLE = "readme_guncelle"
DEGISIKLIKLERI_GITHUBA_YOLLA = "degisiklikleri_githuba_yolla"
DEGISIKLIKLERI_GITHUBDAN_CEK = "degisiklikleri_githubdan_cek"
RUTIN_KONTROL = "rutin_kontrol"
ARAYUZU_GITHULA_ESITLE = "arayuzu_githubla_esitle"
## BAT DOSYALARI
GOOGLE_FORM_GUNCELLE_BAT = GOOGLE_FORM_GUNCELLE + ".bat"
README_GUNCELLE_BAT = README_GUNCELLE + ".bat"
DEGISIKLIKLERI_GITHUBA_YOLLA_BAT = DEGISIKLIKLERI_GITHUBA_YOLLA + ".bat"
DEGISIKLIKLERI_GITHUBDAN_CEK_BAT = DEGISIKLIKLERI_GITHUBDAN_CEK + ".bat"
RUTIN_KONTROL_BAT = RUTIN_KONTROL + ".bat"
ARAYUZU_GITHULA_ESITLE_BAT = ARAYUZU_GITHULA_ESITLE + ".bat"
## SH DOSYALARI
GOOGLE_FORM_GUNCELLE_SH = GOOGLE_FORM_GUNCELLE + ".sh"
README_GUNCELLE_SH = README_GUNCELLE + ".sh"
DEGISIKLIKLERI_GITHUBA_YOLLA_SH = DEGISIKLIKLERI_GITHUBA_YOLLA + ".sh"
DEGISIKLIKLERI_GITHUBDAN_CEK_SH = DEGISIKLIKLERI_GITHUBDAN_CEK + ".sh"
RUTIN_KONTROL_SH = RUTIN_KONTROL + ".sh"
ARAYUZU_GITHULA_ESITLE_SH = ARAYUZU_GITHULA_ESITLE + ".sh"

# IKONLAR

## IKON ADLARI
IKON_PATH_GORELI = "ikonlar"
# PyInstaller için mutlak yol (ikonlar modül dizininde)
IKON_PATH = os.path.join(_MODULE_DIR, IKON_PATH_GORELI)
SELCUKLU_ICO = "selcuklu.png"
OSMANLI_ICO = "osmanli.png"
SAVE_ICO = "save.png"
DELETE_ICO = "delete.png"
INFO_ICO = "info.png"
RESTORE_ICO = "restore.jpeg"

## IKON YOLLARI
OSMANLI_ICO_PATH = os.path.join(IKON_PATH, OSMANLI_ICO)
SELCUKLU_ICO_PATH = os.path.join(IKON_PATH, SELCUKLU_ICO)
SAVE_ICO_PATH = os.path.join(IKON_PATH, SAVE_ICO)
DELETE_ICO_PATH = os.path.join(IKON_PATH, DELETE_ICO)
INFO_ICO_PATH = os.path.join(IKON_PATH, INFO_ICO)
RESTORE_ICO_PATH = os.path.join(IKON_PATH, RESTORE_ICO)

# DONEMLER
MESLEKI_SECMELI = "Mesleki Seçmeli"
GUZ = "Güz"
BAHAR = "Bahar"
SECMELI_4 = "Seçmeli 4"
SECMELI = "Seçmeli"
ZORUNLU = "Zorunlu"
UNIVERSITE_SOSYAL_SECMELI = "Üniversite Sosyal Seçmeli"
UNIVERSITE_MESLEKI_SECMELI = "Üniversite Mesleki Seçmeli"
SOSYAL_SECMELI_1 = "Sosyal Seçmeli 1"
MESLEKI_SECMELI_1 = "Mesleki Seçmeli 1"
MESLEKI_SECMELI_2 = "Mesleki Seçmeli 2"
LISANSUSTU = "Lisansüstü"
DERS_TIPLERI = [
    ZORUNLU,
    MESLEKI_SECMELI,
    MESLEKI_SECMELI_1,
    MESLEKI_SECMELI_2,
    UNIVERSITE_MESLEKI_SECMELI,
    SECMELI,
    SOSYAL_SECMELI_1,
    UNIVERSITE_SOSYAL_SECMELI,
    LISANSUSTU,
]
DONEM_YILLARI = ["0", "1", "2", "3", "4"]
KATKIDA_BULUNMA_ORANI_DIZI = ["Çok", "Orta Üst", "Orta", "Orta Alt", "Az", "Çok Az"]
DONEMLER_DIZISI = [GUZ, BAHAR]
DONEMLER_DIZISI_YOKLA_BERABER = [YOK, GUZ, BAHAR]

ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER = "Artık Güncel Müfredata Dahil Olmayan Dersler"

# KONFIGURASYON
ANAHTAR_VE_LINKLER = {
    HOCA_YORUMLAMA_ANAHTARI: HOCA_YORULMALA_LINKI,
    HOCA_OYLAMA_ANAHTARI: HOCA_OYLAMA_LINKI,
    DERS_YORUMLAMA_ANAHTARI: DERS_YORUMLAMA_LINKI,
    DERS_OYLAMA_ANAHTARI: DERS_OYLAMA_LINKI,
    DERS_OYLAMA_CSV_ANAHTARI: DERS_OYLAMA_LINKI_CSV,
    DERS_YORUMLAMA_CSV_ANAHTARI: DERS_YORUMLAMA_LINKI_CSV,
    HOCA_OYLAMA_CSV_ANAHTARI: HOCA_OYLAMA_LINKI_CSV,
    HOCA_YORUMLAMA_CSV_ANAHTARI: HOCA_YORULMALA_LINKI_CSV,
    GITHUB_URL_ANAHTARI: VARSAYILAN_GITHUB_URL,
    DOKUMANLAR_REPO_YOLU_ANAHTARI: DOKUMANLAR_REPO_YOLU.replace(
        JSON_DOSYALARI_DEPOSU, ""
    ).lstrip("\\/"),
    CIKMISLAR_ANAHTARI: CIKMISLAR_LINKI,
}


# KARA LİSTE OKUMA
KARA_LISTE = []
try:
    with open(
        os.path.join(INTERNAL_ROOT, GOOGLE_FORM_ISLEMLERI, KARA_LISTE_TXT),
        "r",
        encoding="utf-8",
    ) as kara_liste_dosyasi:
        for line in kara_liste_dosyasi:
            KARA_LISTE.append(line.strip().lower())
except FileNotFoundError:
    print(f"⚠️ UYARI: Karaliste dosyası bulunamadı! Küfür filtreleme devre dışı. Beklenen yol: {os.path.join(INTERNAL_ROOT, GOOGLE_FORM_ISLEMLERI, KARA_LISTE_TXT)}")
    KARA_LISTE = []

# gitgub'dan sonraki kısmını al
YILDIZ_URL = VARSAYILAN_GITHUB_URL.split("github.com/")[1]
YILDIZ_GECMISI = f"""
## Yıldız Geçmişi
[![Star History Chart](https://api.star-history.com/svg?repos={YILDIZ_URL}&type=Date)](https://star-history.com/#{YILDIZ_URL}&Date)
"""

GITHUB_KULLANICI_ADI = github_kullanici_adi_getir(VARSAYILAN_GITHUB_URL)
GITHUB_KULLANICI_ADI = (
    GITHUB_KULLANICI_ADI
    if GITHUB_KULLANICI_ADI == "baselkelziye"
    else hash_url_39(VARSAYILAN_GITHUB_URL)
)
TIKLANMA_SAYISI = f'<p align="center">\n<img src="https://komarev.com/ghpvc/?username={GITHUB_KULLANICI_ADI}&label=Görüntülenme+Sayısı&abbreviated=true&style=for-the-badge&color=orange" width="400" height="auto"/>\n</p>\n\n'
default_encoding = sys.getdefaultencoding()


# PY DOSYALARI
README_OLUSTUR_PY = "readme_olustur.py"
HOCA_ICERIKLERI_GUNCELLE_PY = "hoca_icerikleri_guncelle.py"
DERS_ICERIKLERI_GUNCELLE_PY = "ders_icerikleri_guncelle.py"
RUTIN_KONTROL_PY = "google_form_rutin_kontrol.py"
