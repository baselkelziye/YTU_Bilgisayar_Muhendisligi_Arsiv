import json
import os
import difflib
import re
import sys
import bisect
import locale
import unicodedata

# Locale'i Türkçe'ye ayarla
locale.setlocale(
    locale.LC_ALL, "tr_TR.UTF-8"
)  # Sisteminize bağlı olarak bu değer değişebilir

# Mevcut dosyanın bulunduğu dizini al
current_directory = os.path.dirname(os.path.abspath(__file__))
# Göreceli yol (örneğin, bu dizinden 'readme_guncelleme_arayuzu_python' klasörüne giden yol)
relative_path = "readme_guncelleme_arayuzu_python"
# Göreceli yolu tam yola çevir
absolute_path = os.path.join(current_directory, relative_path)
# Tam yolu sys.path listesine ekle
sys.path.append(absolute_path)

from hoca_kisaltma_olustur import hoca_kisaltma_olustur
from degiskenler import *
from metin_islemleri import *
from konfigurasyon_json_kontrol import *
from cikti_yazdirma import custom_write, custom_write_error

if os.path.exists(ANA_README_YOLU):
    os.remove(ANA_README_YOLU)
unvanlarin_onceligi = {"Prof.": 1, "Doç.": 2, "Dr.": 3}

# LİNKLERİN TUTULDUĞU VERİELRİ KONTROL EDİP OLMAYAN DEĞERLERİ GÜNCELLEME
konfigurasyon_json_guncelle(KONFIGURASYON_JSON_NAME)
# GİRİŞ SAYFASI
GERI_BILDIRIM_KISMI = f""" ## 🗣️ Geri Bildirimde Bulunun

📬 Öğrenciler ve hocalar, derslerle ilgili hakaret içermeyen geri bildirimlerinizi aşağıdaki linkler aracılığıyla anonim olarak paylaşabilirsiniz.

- [✍️ **Hocalar için yorum linki**]({HOCA_YORULMALA_LINKI})
- [⭐ **Hocalar için yıldız linki**]({HOCA_OYLAMA_LINKI})
- [✍️ **Dersler için yorum linki**]({DERS_YORUMLAMA_LINKI})
- [⭐ **Dersler için yıldız linki**]({DERS_OYLAMA_LINKI})
"""


def gorustenTarihGetir(gorus):
    gorus_tarihi = ""
    if TARIH in gorus:
        ay = gorus.get(TARIH, {}).get(AY)
        ay = f"{ay}" if ay > 9 else f"0{ay}"
        gorus_tarihi = f"{ay}.{gorus.get(TARIH,{}).get(YIL)}"
        gorus_tarihi = f"ℹ️ Yorum **{gorus_tarihi}** tarihinde yapılmıştır."
    return gorus_tarihi


def hocayaOgrenciGorusuBasliginiYaz(f, hoca, girinti=""):
    gorusler = hoca.get(OGRENCI_GORUSLERI, [])
    if len(gorusler) > 0:
        for gorus in gorusler:
            f.write(
                f"  - 👤 **_{gorus[KISI].strip()}_**: {gorus[YORUM]} {gorustenTarihGetir(gorus)}\n"
            )
    f.write(
        f"  - ℹ️ Siz de [linkten]({HOCA_YORULMALA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n"
    )


def derseOgrenciGorusuBasliginiYaz(f, ders, girinti=""):
    gorusler = ders.get(OGRENCI_GORUSLERI, [])
    if len(gorusler) > 0:
        f.write(f"{girinti}- 💭 **Öğrenci Görüşleri:**\n")
        for gorus in gorusler:
            f.write(
                f"{girinti}  - 👤 **_{gorus[KISI].strip()}_**: {gorus[YORUM]} {gorustenTarihGetir(gorus)}\n"
            )
        f.write(
            f"{girinti}    - ℹ️ Siz de [linkten]({DERS_YORUMLAMA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n"
        )


def derseYildizYaz(f, kolaylik_puani, gereklilik_puani, girinti, oy_sayisi, yil=""):
    f.write(
        f"{girinti}  - ✅ {yil}Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(kolaylik_puani)}\n"
    )
    f.write(
        f"{girinti}  - 🎯 {yil}Ders Mesleki Açıdan Gerekli Mi: {puanlari_yildiza_cevir(gereklilik_puani)}\n"
    )
    f.write(
        f"{girinti}    - ℹ️ Yıldızlar {oy_sayisi} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n"
    )


def hocayaYildizYaz(
    f,
    anlatim_puani,
    kolaylik_puani,
    ogretme_puani,
    eglence_puani,
    girinti,
    oy_sayisi,
    yil="",
):
    f.write(
        f"{girinti}  - {yil}🎭 Dersi Zevkli Anlatır Mı:\t{puanlari_yildiza_cevir(anlatim_puani)}\n"
    )
    f.write(
        f"{girinti}  - {yil}🛣️ Dersi Kolay Geçer Miyim:\t{puanlari_yildiza_cevir(kolaylik_puani)}\n"
    )
    f.write(
        f"{girinti}  - {yil}🧠 Dersi Öğrenir Miyim:\t{puanlari_yildiza_cevir(ogretme_puani)}\n"
    )
    f.write(
        f"{girinti}  - {yil}🎉 Derste Eğlenir Miyim:\t{puanlari_yildiza_cevir(eglence_puani)}\n"
    )
    f.write(
        f"{girinti}    - ℹ️ Yıldızlar {oy_sayisi} oy üzerinden hesaplanmıştır. Siz de [linkten]({HOCA_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n"
    )


def hocaninYildizBasliginiYaz(f, hoca, girinti=""):
    f.write(f"{girinti}- ⭐ **Yıldız Sayıları:**\n")
    if OY_SAYISI in hoca and isinstance(hoca[OY_SAYISI], int) and hoca[OY_SAYISI] > 0:
        hocayaYildizYaz(
            f,
            hoca.get(ANLATIM_PUANI, 0),
            hoca.get(KOLAYLIK_PUANI, 0),
            hoca.get(OGRETME_PUNAI, 0),
            hoca.get(EGLENCE_PUANI, 0),
            girinti,
            hoca[OY_SAYISI],
        )
    else:
        f.write(
            f"{girinti}    - ℹ️ Henüz yıldız veren yok. Siz de [linkten]({HOCA_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n"
        )
        return
    ek_girinti = "  "
    if YILLARA_GORE_YILDIZ_SAYILARI in hoca:
        for yildiz_bilgileri in hoca[YILLARA_GORE_YILDIZ_SAYILARI]:
            yil = yildiz_bilgileri.get(YIL, "bilinmiyor")
            f.write(f"{girinti + ek_girinti}- 📅 *{yil} yılı için yıldız bilgileri*\n")
            hocayaYildizYaz(
                f,
                yildiz_bilgileri.get(ANLATIM_PUANI, 0),
                yildiz_bilgileri.get(KOLAYLIK_PUANI, 0),
                yildiz_bilgileri.get(OGRETME_PUNAI, 0),
                yildiz_bilgileri.get(EGLENCE_PUANI, 0),
                girinti + ek_girinti,
                yildiz_bilgileri.get(OY_SAYISI, 0),
                f"{yil} Yılında ",
            )


def dersinYildizBasliginiYaz(f, ders, girinti=""):
    f.write(f"{girinti}- ⭐ **Yıldız Sayıları:**\n")
    if OY_SAYISI in ders:
        kolaylik_puani = ders.get(KOLAYLIK_PUANI, 1)
        gereklilik_puani = ders.get(GEREKLILIK_PUANI, 1)
        derseYildizYaz(
            f, kolaylik_puani, gereklilik_puani, girinti, ders.get(OY_SAYISI, 0)
        )
    else:
        f.write(
            f"{girinti}    - ℹ️ Henüz yıldız veren yok. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n"
        )
        return
    ek_girinti = "  "
    if YILLARA_GORE_YILDIZ_SAYILARI in ders:
        for yildiz_bilgileri in ders[YILLARA_GORE_YILDIZ_SAYILARI]:
            yil = yildiz_bilgileri.get(YIL, "bilinmiyor")
            f.write(f"{girinti + ek_girinti}- 📅 *{yil} yılı için yıldız bilgileri*\n")
            derseYildizYaz(
                f,
                yildiz_bilgileri.get(KOLAYLIK_PUANI, 0),
                yildiz_bilgileri.get(GEREKLILIK_PUANI, 0),
                girinti + ek_girinti,
                yildiz_bilgileri.get(OY_SAYISI, 0),
                f"{yil} Yılında ",
            )


# Klasörler için benzerlik skoru hesaplayan fonksiyon
def benzerlik_skoru(str1, str2):
    return difflib.SequenceMatcher(None, str1, str2).ratio() * 100


def klasor_derinligi_bul(dosya_yolu):
    # Yolu bölümlere ayır
    bolumler = dosya_yolu.split(os.sep)

    # Derinliği hesapla
    derinlik = len(bolumler)

    return derinlik


# En iyi eşleşmeyi bulan fonksiyon
def en_iyi_eslesen_klasor_yolu_bul(baslangic_yolu, aranan_ad):
    en_iyi_eslesme = None
    en_yuksek_yuzde = 0

    for dizin_yolu, alt_dizinler, _ in os.walk(baslangic_yolu):
        for klasor_ad in alt_dizinler:
            # Eşleşme skoru hesaplama
            skor = benzerlik_skoru(aranan_ad.lower(), klasor_ad.lower())
            # Örneğin Matematik 1 için Matematik 2 döndürmesin diye ek kontrol
            # ilk kontrol Matematik 1 için Matematik 2'yi, ikinci kontrol Matematik 2 için Matematik 1'i döndürmesin diye
            if ("1" in aranan_ad and "2" in klasor_ad) or (
                "2" in aranan_ad and "1" in klasor_ad
            ):
                skor = 0
            # Her iki yüzde de %50'den büyükse, eşleşme olarak kabul et
            if (
                skor > en_yuksek_yuzde
                and klasor_derinligi_bul(dizin_yolu.replace(baslangic_yolu, "")) < 4
            ):
                en_yuksek_yuzde = skor
                en_iyi_eslesme = os.path.join(dizin_yolu, klasor_ad)
    return (
        None
        if (
            en_yuksek_yuzde < 88
            or (
                len(en_iyi_eslesme.split(os.sep)) < 3
                and "Projesi" not in en_iyi_eslesme
            )
        )
        else en_iyi_eslesme
    )


# GitHub'daki klasör için tam URL oluşturan fonksiyon
def yerel_yoldan_github_linkine(klasor_yolu, repo_url=VARSAYILAN_GITHUB_URL):
    """
    Yerel bir klasör yolunu GitHub reposundaki karşılık gelen klasörün URL'sine dönüştürür.
    Göreceli yolları (..) kaldırır ve boşlukları uygun bir şekilde değiştirir.

    :param klasor_yolu: Yerel sistemdeki klasör yolu (örn. "ders_notlari/ISL101").
    :param repo_url: GitHub'daki repository'nin URL'si.
    :return: GitHub'daki klasör için tam URL.
    """
    if klasor_yolu is None:
        return None
    klasor_yolu = klasor_yolu.replace(DOKUMANLAR_REPO_YOLU, "")
    # Göreceli yolları kaldır
    klasor_yolu = os.path.normpath(klasor_yolu)
    # Windows yollarını düzeltmek için (örn. "klasör\alt_klasör" -> "klasör/alt_klasör")
    klasor_yolu = klasor_yolu.replace("\\", "/")

    # Boşlukları "%20" ile değiştir
    klasor_yolu = klasor_yolu.replace(" ", "%20")

    # GitHub'daki tam URL'yi oluştur
    github_klasor_url = f"{repo_url}/tree/main/{klasor_yolu}"
    return github_klasor_url


def hoca_siralama_anahtari(hoca):
    # Hoca aktif görevde mi kontrolü
    aktif_gorevde_mi = hoca.get(HOCA_AKTIF_GOREVDE_MI, True)  # True/False değerini al
    aktiflik_onceligi = 0 if aktif_gorevde_mi else 1  # Aktif hocalar önce gelsin

    unvan = hoca[AD].split()[0]  # İsmin ilk kelimesini (unvanı) al
    unvan_onceligi = unvanlarin_onceligi.get(unvan, 4)  # Unvan önceliği

    # Önce aktiflik durumu, sonra unvan önceliği ve en son tam adı dikkate alarak tuple dön
    return (aktiflik_onceligi, unvan_onceligi, hoca[AD])


# JSON dosyasını okuyan fonksiyon
def json_oku(json_dosyasi):
    try:
        with open(json_dosyasi, "r", encoding="utf-8") as f:
            return json.load(f)
    except FileNotFoundError:
        return None


# txt dosyasını okuyan fonksiyon
def txt_oku(txt_dosyasi):
    try:
        with open(txt_dosyasi, "r", encoding="utf-8") as dosya:
            # Dosyanın tamamını oku
            return dosya.read()
    except FileNotFoundError:
        return None


def puanlari_yildiza_cevir(puan, max_yildiz_sayisi=10):
    puan = round(puan / 10) * 10  # Önce 10'a böl, yuvarla, sonra 10 ile çarp
    dolu_yildiz_sayisi = puan // 10  # Her 10 puan için 1 yıldız
    bos_yildiz_sayisi = max_yildiz_sayisi - dolu_yildiz_sayisi
    return "★" * dolu_yildiz_sayisi + "☆" * bos_yildiz_sayisi


# Bilgileri README'ye ekleyen fonksiyon
def hocalari_readme_ye_ekle(bilgiler):
    if HOCALAR not in bilgiler or len(bilgiler[HOCALAR]) != 0:
        bilgiler[HOCALAR] = [hoca for hoca in bilgiler[HOCALAR] if hoca[AD] != ""]
    else:
        custom_write_error("Hoca bilgileri bulunamadi.\n")
        return
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        if BOLUM_ADI in bilgiler:
            f.write(
                f"<details>\n<summary><b>🎓 {bilgiler[BOLUM_ADI]}</b></summary>\n\n"
            )
            f.write(f"\n\n\n## 🎓 {bilgiler[BOLUM_ADI]}\n")
        else:
            custom_write_error("Hocalar Bolum adi bulunamadi.\n")
        if BOLUM_ACIKLAMASI in bilgiler:
            f.write(f"📚 {bilgiler[BOLUM_ACIKLAMASI]}\n\n\n\n")
        else:
            custom_write_error("Hocalar Bolum aciklamasi bulunamadi.\n\n")
        en_populer_hoca_oy_sayisi = 0
        en_populer_hoca_adi = ""
        if EN_POPULER_HOCA in bilgiler and HOCA_ADI in bilgiler[EN_POPULER_HOCA]:
            en_populer_hoca_adi = bilgiler[EN_POPULER_HOCA][HOCA_ADI]
            if OY_SAYISI in bilgiler[EN_POPULER_HOCA]:
                en_populer_hoca_oy_sayisi = bilgiler[EN_POPULER_HOCA][OY_SAYISI]
            else:
                en_populer_hoca_oy_sayisi = 1
                custom_write_error("En populer hoca oy sayisi bulunamadi.\n")
        else:
            custom_write_error("En populer hoca bilgileri bulunamadi.\n")

        unvan_sayaci = 0
        baslik_str = "\n### {}\n"
        for hoca in sorted(bilgiler[HOCALAR], key=hoca_siralama_anahtari):
            if unvan_sayaci < len(unvanlar) and hoca[AD].startswith(
                unvanlar[unvan_sayaci]
            ):
                tmp_unvan = ""
                if unvan_sayaci == 0:
                    tmp_unvan = "Profesörler"
                elif unvan_sayaci == 1:
                    tmp_unvan = "Doçentler"
                elif unvan_sayaci == 2:
                    tmp_unvan = "Doktor Öğretim Üyeleri"
                else:
                    tmp_unvan = "Araştırma Görevlileri"

                f.write(baslik_str.format(tmp_unvan))
                unvan_sayaci += 1
            elif (
                unvan_sayaci == len(unvanlar)
                and hoca.get(HOCA_AKTIF_GOREVDE_MI, True) == False
            ):
                unvan_sayaci += 1
                f.write(baslik_str.format("Üniversitede Aktif Görevde Olmayan Hocalar"))

            if AD not in hoca:
                hoca[AD] = ""
            if OFIS not in hoca:
                hoca[OFIS] = ""
            if LINK not in hoca:
                hoca[LINK] = ""
            populer_isaret = (
                "👑" if AD in hoca and hoca[AD] == en_populer_hoca_adi else ""
            )
            hoca_emoji = "👨‍🏫" if hoca[ERKEK_MI] else "👩‍🏫"
            populer_bilgi = (
                f" En popüler hoca ({en_populer_hoca_oy_sayisi} oy)"
                if hoca[AD] == en_populer_hoca_adi
                else ""
            )
            f.write(
                f"\n\n\n#### {hoca_emoji} {hoca[AD].strip()} {populer_isaret}{populer_bilgi}\n"
            )
            f.write(f"- 🚪 **Ofis:** {hoca[OFIS]}\n")
            f.write(f"- 🔗 **Araştırma Sayfası:** [{hoca[LINK]}]({hoca[LINK]})\n")
            f.write(f"- 💬 **Öğrenci Görüşleri:**\n")
            hocayaOgrenciGorusuBasliginiYaz(f, hoca)
            f.write("- 📚 **Verdiği Dersler:**\n")
            if (
                DERSLER in hoca
                and isinstance(hoca[DERSLER], list)
                and len(hoca[DERSLER]) > 0
            ):
                for ders in hoca[DERSLER]:
                    if (
                        EN_POPULER_DERS in dersler
                        and ders != dersler[EN_POPULER_DERS][DERS_ADI]
                    ):
                        f.write(f"  - 📖 [{ders}]{baslik_linki_olustur(ders)}\n")
                    else:
                        populer_isaret = "👑"
                        populer_bilgi = (
                            f" En popüler ders ({dersler[EN_POPULER_DERS][OY_SAYISI] if EN_POPULER_DERS in dersler else 0} oy)"
                            if EN_POPULER_DERS in dersler
                            and ders == dersler[EN_POPULER_DERS][DERS_ADI]
                            else ""
                        )
                        ders_id = f"{ders} {populer_isaret}{populer_bilgi}"
                        f.write(f"  - 📖 [{ders}]{baslik_linki_olustur(ders_id)}\n")
            else:
                f.write("  - 📖 Ders bilgileri bulunamadı.\n")
            hocaninYildizBasliginiYaz(f, hoca)
            if hoca.get(HOCA_AKTIF_GOREVDE_MI, True) == False:
                f.write(f"- ℹ️ {VARSAYILAN_HOCA_AKTIF_GOREVDE_DEGIL_MESAJI}.\n")
        f.write("</details>\n\n")


def donem_siralamasi(donem_key):
    if donem_key == LISANSUSTU:
        return (1499, 1499)
    if donem_key == ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER:
        return (1500, 1500)
    if donem_key == "Mesleki Seçmeli":
        return (998, 998)  # Mesleki Seçmeli dersleri en sona koy
    try:
        yil, donem = donem_key.split(" - ")
        return (int(yil.split(".")[0]), 0 if donem == "Güz" else 1)
    except:
        return (999, 999)


def baslik_linki_olustur(baslik):
    # Emoji ve özel karakterleri kaldır
    baslik = re.sub(r"[^\w\s-]", "", baslik)
    # Boşlukları '-' ile değiştir
    baslik = baslik.replace(" ", "-").lower()
    # Oluşturulan linki döndür
    return f"(#-{baslik})"


def ders_siralama_anahtari(ders):
    return ders.get(AD, "Z").replace("İ", "i").lower()


def sıralı_ekle(liste, eleman, anahtar_fonksiyonu):
    # Elemanın karşılaştırma anahtarını hesapla
    eleman_anahtar = anahtar_fonksiyonu(eleman)
    # Liste içinde elemanın ekleneceği konumu bul
    konum = bisect.bisect_left([anahtar_fonksiyonu(x) for x in liste], eleman_anahtar)
    # Elemanı doğru konuma ekle
    liste.insert(konum, eleman)


# Dersleri yıl ve döneme göre gruplayıp README'ye ekleyen fonksiyon
def dersleri_readme_ye_ekle(dersler):
    if DERSLER not in dersler or not isinstance(dersler[DERSLER], list):
        dersler[DERSLER] = []
    gruplanmis_dersler = {}
    for ders in dersler[DERSLER]:
        if ders.get(GUNCEL_MI, True) == False:
            donem_key = ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER
        elif YIL in ders and ders[YIL] > 0:
            donem_key = f"{ders[YIL]}. Yıl - {ders[DONEM]}"
        elif TIP in ders:
            donem_key = ders[TIP]
        else:
            custom_write_error("Ders bilgileri bulunamadı.\n")
            continue
        if donem_key not in gruplanmis_dersler:
            gruplanmis_dersler[donem_key] = []
        sıralı_ekle(gruplanmis_dersler[donem_key], ders, ders_siralama_anahtari)
    en_populer_ders_oy_sayisi = 0
    en_populer_ders_adi = ""
    if EN_POPULER_DERS in dersler and DERS_ADI in dersler[EN_POPULER_DERS]:
        en_populer_ders_adi = dersler[EN_POPULER_DERS][DERS_ADI]
        if OY_SAYISI in dersler[EN_POPULER_DERS]:
            en_populer_ders_oy_sayisi = dersler[EN_POPULER_DERS][OY_SAYISI]

    en_populer_hoca_adi = (
        "" if EN_POPULER_HOCA not in hocalar else hocalar[EN_POPULER_HOCA][HOCA_ADI]
    )
    en_populer_hoca_oy_sayisi = (
        0 if EN_POPULER_HOCA not in hocalar else hocalar[EN_POPULER_HOCA][OY_SAYISI]
    )
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        f.write(f"<details>\n<summary><b>📖 {dersler['bolum_adi']}</b></summary>\n\n")
        f.write(f"\n\n\n## 📖 {dersler[BOLUM_ADI]}\n")
        f.write(f"📄 {dersler[BOLUM_ACIKLAMASI]}\n\n\n\n")

        for donem in sorted(gruplanmis_dersler.keys(), key=donem_siralamasi):
            f.write(f"\n### 🗓 {donem}\n")
            for ders in gruplanmis_dersler[donem]:
                f.write("\n\n")
                populer_isaret = "👑" if ders[AD] == en_populer_ders_adi else ""
                populer_bilgi = (
                    f" En popüler ders ({en_populer_ders_oy_sayisi} oy)"
                    if ders[AD] == en_populer_ders_adi
                    else ""
                )
                f.write(f"#### 📘 {ders[AD]} {populer_isaret}{populer_bilgi}\n")
                f.write(f"  - 🏷️ **Ders Tipi:** {ders[TIP]}\n")
                derseOgrenciGorusuBasliginiYaz(f, ders, girinti="  ")
                dersinYildizBasliginiYaz(f, ders, girinti="  ")

                if DERSI_VEREN_HOCALAR in ders and len(ders[DERSI_VEREN_HOCALAR]) > 0:
                    f.write("  - 👨‍🏫 👩‍🏫 **Dersi Yürüten Akademisyenler:**\n")
                    for hoca in ders[DERSI_VEREN_HOCALAR]:
                        hoca_kisaltma = hoca.get(KISALTMA, "")
                        hoca_ad = hoca.get(AD, "")
                        if hoca_ad != en_populer_hoca_adi:
                            f.write(
                                f"    - [{hoca_kisaltma}]{baslik_linki_olustur(hoca_ad)}\n"
                            )
                        elif en_populer_hoca_adi != "":
                            populer_isaret = "👑"
                            populer_bilgi = (
                                f" En popüler hoca ({en_populer_hoca_oy_sayisi} oy)"
                            )
                            hoca_id = f"{hoca_ad} {populer_isaret}{populer_bilgi}"
                            f.write(
                                f"    - [{hoca_kisaltma}]{baslik_linki_olustur(hoca_id)}\n"
                            )
                ders_klasor_yolu = en_iyi_eslesen_klasor_yolu_bul(
                    DOKUMANLAR_REPO_YOLU, ders[AD]
                )
                if ders_klasor_yolu is not None:
                    f.write(
                        f"  - 📂 [Ders Klasörü]({(yerel_yoldan_github_linkine(ders_klasor_yolu))})\n"
                    )
                if GUNCEL_MI in ders and not ders[GUNCEL_MI]:
                    f.write("  - ℹ️ Dersin içeriği güncel değil\n")
                    f.write(f"    - {dersler[GUNCEL_OLMAYAN_DERS_ACIKLAMASI]}\n")
        f.write("</details>\n\n")


# Giris bilgilerini README'ye ekleyen fonksiyon
def readme_ye_giris_ekle(giris_bilgileri):
    with open(ANA_README_YOLU, "w", encoding="utf-8") as f:
        f.write(
            f"# 📖 {giris_bilgileri['baslik']}\n\n"
        )  # Kitap emoji başlığı temsil eder
        f.write(f"{giris_bilgileri['aciklama']}\n\n")
        f.write(GERI_BILDIRIM_KISMI)
        f.write(TIKLANMA_SAYISI)
        f.write("<details>\n<summary><b>🗂 İçindekiler</b></summary>\n\n")
        f.write("## 🗂 İçindekiler\n\n")
        for item in giris_bilgileri["icindekiler"]:
            f.write(f"- 🔗 {item}\n")  # Link emojisi her madde için kullanılır
        f.write("</details>\n\n")


def readmeye_hocalar_icin_kisaltmalar_ekle(data):
    """
    Verilen hocalar listesi için kısaltmalar oluşturur ve bunları bir Markdown biçiminde döndürür.
    """
    kisaltmalar = {}
    for hoca in data[HOCALAR]:
        if AD in hoca and hoca[AD] != "":
            kisaltma = hoca_kisaltma_olustur(hoca[AD])
            kisaltmalar[kisaltma] = hoca[AD]
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        f.write(f"<details>\n<summary><b>🆎 Hoca Kısaltmaları</b></summary>\n\n")
        f.write("<h2 align='center'>🆎 Hoca Kısaltmaları</h2>\n\n")
        for kisaltma in sorted(kisaltmalar.keys()):
            ad = kisaltmalar[kisaltma]
            # Kısaltmayı kalın yap, emoji ile çevrele ve ad ile arasına tab benzeri boşluk ekle
            f.write(f"<p align='center'>🔹 <b>{kisaltma}</b> &emsp; {ad} 🔹</p>\n")
        f.write("</details>\n\n")


# Repo kullanimi bilgilerini README'ye ekleyen fonksiyon
def readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri):
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        f.write(
            f"<details>\n<summary><b>🛠 {repo_kullanimi_bilgileri[BASLIK]}</b></summary>\n\n"
        )
        f.write(
            f"\n\n\n## 🛠 {repo_kullanimi_bilgileri[BASLIK]}\n\n"
        )  # Araç kutusu emojisi
        f.write(f"### ⚙️ {repo_kullanimi_bilgileri[ACIKLAMA]}:\n")
        for aciklama in repo_kullanimi_bilgileri[ACIKLAMALAR]:
            f.write(f"- 📋 {aciklama}\n")  # Not defteri emojisi
        f.write(f"\n\n### 📝 {repo_kullanimi_bilgileri[TALIMAT]}:\n")  # Yazma emojisi
        for talimat in repo_kullanimi_bilgileri[TALIMATLAR]:
            f.write(f"- 👉 {talimat}\n")  # İşaret parmağı emojisi
        f.write("</details>\n\n")
        f.write(
            f"<details>\n<summary><b>🔍 {repo_kullanimi_bilgileri[KAVRAM]}</b></summary>\n\n"
        )
        f.write(f"\n\n## 🔍 {repo_kullanimi_bilgileri[KAVRAM]}\n")  # Büyüteç emojisi
        for kavram in sorted(
            repo_kullanimi_bilgileri[KAVRAMLAR],
            key=lambda x: unicodedata.normalize("NFKD", x[KAVRAM].lower()),
        ):
            f.write(
                f"- 💡 **{kavram[KAVRAM]}**\n"
            )  # Ampul emojisi, fikir veya kavramı temsil eder
            for aciklama in kavram[ACIKLAMALAR]:
                f.write(f"  - 📘 {aciklama}\n")  # Kitap emojisi, açıklamalar için
        f.write("</details>\n\n")


# Yazar notlarinı README'ye ekleyen fonksiyon
def readme_ye_yazar_notlari_ekle(yazar_notlari):
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        f.write(f"<details>\n<summary><b>🖋 {yazar_notlari['baslik']}</b></summary>\n\n")
        f.write(
            f"\n## 🖋 {yazar_notlari['baslik']}\n\n"
        )  # Kalem emoji, yazarı temsil eder
        for aciklama in yazar_notlari[ACIKLAMALAR]:
            f.write(
                f"- 📝 {aciklama}\n"
            )  # Not defteri ve kalem emoji, notlari ve düşünceleri temsil eder
        f.write("</details>\n\n")


def readme_katkida_bulunanlar_ekle(veri):
    veri[KATKIDA_BULUNANLAR] = sorted(
        veri[KATKIDA_BULUNANLAR],
        key=lambda x: (
            KATKIDA_BULUNMA_ORANI_DIZI.index(
                x.get(KATKIDA_BULUNMA_ORANI, KATKIDA_BULUNMA_ORANI_DIZI[-1])
            ),
            x["ad"],
        ),
    )
    # Katkı oranlarına göre emojiler (örnek)
    EMOJILER = [
        "👑",
        "🌟",
        "💫",
        "✨",
        "🔹",
        "",
    ]  # Bu listeyi ihtiyacınıza göre düzenleyin

    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        # Bölüm başlığını ortala
        f.write(f"<details>\n<summary><b>🤝 {veri['bolum_adi']}</b></summary>\n\n")
        f.write(f"<h2 align='center'>🤝 {veri['bolum_adi']}</h2>\n\n")
        f.write(f"{veri[BOLUM_ACIKLAMASI]}\n\n")
        for katkida_bulunan in veri[KATKIDA_BULUNANLAR]:
            oran = katkida_bulunan.get(
                KATKIDA_BULUNMA_ORANI, KATKIDA_BULUNMA_ORANI_DIZI[-1]
            )
            oran_index = KATKIDA_BULUNMA_ORANI_DIZI.index(oran)
            emoji = EMOJILER[oran_index]  # Katkı oranına göre emoji seçimi
            # Başlık seviyesini belirle
            header_size = min(oran_index + 1, 6)  # En fazla <h6> kullanılabilir
            header_tag = f"h{header_size}"
            # Katkıda bulunanların isimlerini belirlenen başlık etiketi ile yaz
            f.write(
                f"<{header_tag} align='center'>{emoji} <b><i>{katkida_bulunan.get(AD,'')}</i></b> {emoji}</{header_tag}>\n"
            )

            # İletişim bilgilerini yan yana yaz
            iletisim_bilgileri_html = " &nbsp".join(
                [
                    f"<a href='{bilgi.get(LINK, '')}'><b>{bilgi.get(BASLIK, '')}</b></a>"
                    for bilgi in katkida_bulunan.get(ILETISIM_BILGILERI, [])
                ]
            )
            if iletisim_bilgileri_html:
                f.write(f"<p align='center'>{iletisim_bilgileri_html}</p>\n")
            f.write("\n")
        f.write("</details>\n\n")


def readmeye_yildiz_gecmisi_ekle():
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        f.write(YILDIZ_GECMISI)


def readmeye_maas_istatistikleri_ekle(veri):
    MAAS_BASLIK = "Bölüm Mezunları Maaş İstatistikleri"
    with open(ANA_README_YOLU, "a", encoding="utf-8") as f:
        f.write(f"<details>\n<summary><b>💰 {MAAS_BASLIK}</b></summary>\n\n")
        f.write(f"<h2 align='center'>💰 {MAAS_BASLIK}</h2>\n\n")
        f.write(veri)
        f.write("\n</details>\n\n")


def sıralama_anahtarı(ders):
    yıl_sıralaması = [1, 2, 3, 4, 0]
    dönem_sıralaması = ["Güz", "Bahar", ""]

    yıl = (
        yıl_sıralaması.index(ders[YIL])
        if ders[YIL] in yıl_sıralaması
        else len(yıl_sıralaması)
    )
    dönem = (
        dönem_sıralaması.index(ders[DONEM])
        if ders[DONEM] in dönem_sıralaması
        else len(dönem_sıralaması)
    )
    ad = ders[AD].lower()

    return yıl, dönem, ad


"""
BURASI ANA README OLUŞTURMA KISMI
"""
custom_write("README.md olusturuluyor...\n")
# JSON dosyasından yazar notlarinı oku ve README'ye ekle
yazar_notlari = json_oku(YAZARIN_NOTLARI_JSON_NAME)
# JSON dosyasından repo kullanimi bilgilerini oku ve README'ye ekle
repo_kullanimi_bilgileri = json_oku(REPO_KULLANIMI_JSON_NAME)
# JSON dosyasından dersleri oku ve README'ye ekle
dersler = json_oku(DERSLER_JSON_NAME)
dersler[DERSLER] = sorted(dersler[DERSLER], key=sıralama_anahtarı)
# JSON dosyasından hocaları oku ve README'ye ekle
hocalar = json_oku(HOCALAR_JSON_NAME)
giris_bilgileri = json_oku(GIRIS_JSON_NAME)
katkida_bulunanlar = json_oku(KATKIDA_BULUNANLAR_JSON_NAME)
maas_istatistikleri = txt_oku(MAAS_ISTATISTIKLERI_TXT_NAME)
if giris_bilgileri is not None:
    custom_write("Giris bilgileri README'ye ekleniyor...\n")
    readme_ye_giris_ekle(giris_bilgileri)
else:
    custom_write("Giris bilgileri bulunamadi...\n")
if repo_kullanimi_bilgileri is not None:
    custom_write("Repo kullanimi README'ye ekleniyor...\n")
    readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri)
else:
    custom_write_error("Repo kullanimi bilgileri bulunamadi...\n")
if maas_istatistikleri is not None:
    custom_write("Maas istatistikleri README'ye ekleniyor...\n")
    readmeye_maas_istatistikleri_ekle(maas_istatistikleri)
if dersler is not None:
    custom_write("Ders bilgileri README'ye ekleniyor...\n")
    dersleri_readme_ye_ekle(dersler)
if hocalar is not None:
    custom_write("Hoca bilgileri README'ye ekleniyor...\n")
    hocalari_readme_ye_ekle(hocalar)
else:
    custom_write_error("Hoca bilgileri bulunamadi...\n")
if yazar_notlari is not None:
    custom_write("Yazar notlari README'ye ekleniyor...\n")
    readme_ye_yazar_notlari_ekle(yazar_notlari)
else:
    custom_write_error("Yazar notlari bulunamadi...\n")
if hocalar is not None:
    custom_write("Hoca kisaltmalari README'ye ekleniyor...\n")
    readmeye_hocalar_icin_kisaltmalar_ekle(hocalar)
else:
    custom_write_error("Hoca kisaltmalari bulunamadi...\n")
if katkida_bulunanlar is not None:
    custom_write("Katkida bulunanlar README'ye ekleniyor...\n")
    readme_katkida_bulunanlar_ekle(katkida_bulunanlar)
else:
    custom_write_error("Katkida bulunanlar bulunamadi...\n")
custom_write("Yildiz gecmisi README'ye ekleniyor...\n")
readmeye_yildiz_gecmisi_ekle()
"""
BURASI ANA README OLUŞTURMA KISMI
"""

"""
BURASI DERSLER README OLUŞTURMA KISMI
"""


def ders_klasorune_readme_olustur(ders, dosya_yolu, klasor_sonradan_olustu=False):
    with open(os.path.join(dosya_yolu, README_MD), "w", encoding="utf-8") as f:
        # Ders başlığı
        f.write(f"# 📚 {ders[AD]}\n\n")

        # Ders bilgileri
        f.write("## ℹ️ Ders Bilgileri\n\n")
        if ders.get(TIP, MESLEKI_SECMELI) != MESLEKI_SECMELI:
            f.write(f"- 📅 **Yıl:** {ders[YIL]}\n")
            f.write(f"- 📆 **Dönem:** {ders[DONEM]}\n")
        f.write(f"- 🏫 **Ders Tipi:** {ders[TIP]}\n")
        derseOgrenciGorusuBasliginiYaz(f, ders)
        dersinYildizBasliginiYaz(f, ders)
        if DERSE_DAIR_ONERILER in ders:
            # Derse dair öneriler
            f.write("## 📝 Derse Dair Öneriler\n\n")
            for oneriler in ders[DERSE_DAIR_ONERILER]:
                if len(oneriler[ONERILER]) > 0:
                    f.write(f"### 💡 Öneri sahibi: {oneriler[ONERI_SAHIBI]}\n")
                    for oneri in oneriler[ONERILER]:
                        f.write(f"- {oneri}\n")
        f.write("\n## 📖 Faydalı Olabilecek Kaynaklar\n\n")
        if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
            # Faydalı olabilecek kaynakları Türkçe alfabetik sıraya göre sırala
            sirali_kaynaklar = sorted(
                ders[FAYDALI_OLABILECEK_KAYNAKLAR],
                key=lambda x: unicodedata.normalize("NFKD", x).lower(),
            )

            # Sıralanmış kaynakları dosyaya yazdır
            for kaynak in sirali_kaynaklar:
                f.write(f"- 📄 {kaynak} ✨\n")

        f.write(GENEL_CIKMIS_SORULAR_METNI)
        f.write(f"  - ℹ️ {FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI}\n")
        if DERSI_VEREN_HOCALAR in ders and len(ders[DERSI_VEREN_HOCALAR]) > 0:
            f.write("\n## 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:\n")
            for hoca in ders[DERSI_VEREN_HOCALAR]:
                f.write(f"- {hoca[KISALTMA]}\n")
        if klasor_sonradan_olustu:
            f.write("\n## 😔 İçerik yok\n")
            f.write(f"- {dersler[DERS_KLASORU_BULUNAMADI_MESAJI]}\n")
        if GUNCEL_MI in ders and not ders[GUNCEL_MI]:
            f.write("\n## ℹ️ Dersin içeriği güncel değil\n")
            f.write(f"- {dersler[GUNCEL_OLMAYAN_DERS_ACIKLAMASI]}\n")


def dersin_donemini_getir(ders):
    if ders.get(YIL, 0) != 0 and ders.get(DONEM, "") != "":
        return {YIL: ders.get(YIL, 0), DONEM: ders.get(DONEM, "")}
    if ders.get(TIP, "") != "":
        return {DONEM_ADI: ders.get(TIP, "")}


def ders_klasoru_olustur(ders):
    donem = dersin_donemini_getir(ders)
    donem_yolu = donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU)
    ders_klasor_yolu = os.path.join(donem_yolu, ders.get(AD, ""))
    os.makedirs(ders_klasor_yolu, exist_ok=True)
    return ders_klasor_yolu


def klasorde_baska_dosya_var_mi(ders_klasoru):
    icerikler = os.listdir(ders_klasoru)
    # README.md dosyasını çıkar
    icerikler = [dosya for dosya in icerikler if dosya.lower() != "readme.md"]
    return (
        len(icerikler) > 0
    )  # Eğer içerikler listesi boş değilse, başka dosya var demektir.


if dersler is not None:
    custom_write("Dersler README.md olusturuluyor...\n")
    for ders in dersler[DERSLER]:
        custom_write(f"{ders[AD]} README.md olusturuluyor...\n")
        ders_klasoru = en_iyi_eslesen_klasor_yolu_bul(DOKUMANLAR_REPO_YOLU, ders[AD])
        if ders_klasoru is not None:
            baska_dosya_var_mi = klasorde_baska_dosya_var_mi(ders_klasoru)
            if not baska_dosya_var_mi:
                ders_klasorune_readme_olustur(
                    ders, ders_klasoru, klasor_sonradan_olustu=True
                )
            else:
                ders_klasorune_readme_olustur(
                    ders, ders_klasoru, klasor_sonradan_olustu=False
                )
        else:
            ders_klasoru = ders_klasoru_olustur(ders)
            ders_klasorune_readme_olustur(
                ders, ders_klasoru, klasor_sonradan_olustu=True
            )
        custom_write(f"{ders[AD]} README.md olusturuldu.\n")
else:
    custom_write_error("Ders bilgileri bulunamadı.\n")
"""
BURASI DERSLER README OLUŞTURMA KISMI
"""


"""
Burası Dönem Readme oluşturma kısmı
"""


def donemlere_gore_readme_olustur(donemler):
    # Her dönem için README.md oluştur
    for donem in donemler[DONEMLER]:
        custom_write(f"{donem[DONEM_ADI]} README.md olusturuluyor...\n")
        donem_dosya_yolu = donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU)
        os.makedirs(donem_dosya_yolu, exist_ok=True)
        dosya_yolu = os.path.join(donem_dosya_yolu, README_MD)
        with open(dosya_yolu, "w", encoding="utf-8") as f:
            f.write(f"# 📅 {donem[DONEM_ADI]}\n\n")  # Takvim emoji, dönemi temsil eder
            f.write("## 📝 Genel Tavsiyeler\n\n")
            # Not defteri ve kalem emoji, tavsiyeleri temsil eder
            for tavsiye in donem["genel_tavsiyeler"]:
                f.write(
                    f"- 💡 {tavsiye}\n"
                )  # Ampul emoji, fikir veya tavsiye temsil eder
            if donem.get(YIL, 0) != 0:
                f.write("## 📚 Dönemin Zorunlu Dersleri\n\n")
                # Kitap emoji, zorunlu dersleri temsil eder
        custom_write(f"{donem[DONEM_ADI]} README.md olusturuldu.\n")


def ders_bilgilerini_readme_ile_birlestir(
    dersler, donemler, guncel_olmayan_ders_aciklamasi
):
    # Her ders için ilgili dönem README'sine ekle
    for ders in dersler:
        custom_write(f"{ders[AD]} README.md donemine ekleniyor...\n")
        count = 0
        for donem in donemler:
            if (
                ders[TIP] == donem[DONEM_ADI]
                or ders[YIL] == donem[YIL]
                and ders[DONEM] == donem[DONEM]
                and not (ders[YIL] == 0 or ders[DONEM] == "")
            ):
                count += 1
                dosya_yolu = os.path.join(
                    donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU), README_MD
                )
                with open(dosya_yolu, "a", encoding="utf-8") as f:
                    f.write(
                        f"\n### 📘 {ders[AD]}\n\n"
                    )  # Kitap emoji, ders adını temsil eder
                    f.write(
                        "#### 📄 Ders Bilgileri\n\n"
                    )  # Kağıt emoji, ders bilgilerini temsil eder
                    f.write(f"- 📅 **Yıl:** {ders[YIL]}\n")
                    f.write(f"- 📆 **Dönem:** {ders[DONEM]}\n")
                    f.write(f"- 🏫 **Ders Tipi:** {ders[TIP]}\n")
                    derseOgrenciGorusuBasliginiYaz(f, ders)
                    dersinYildizBasliginiYaz(f, ders)

                    if DERSE_DAIR_ONERILER in ders:
                        f.write(
                            "#### 💡 Derse Dair Öneriler\n\n"
                        )  # Ampul emoji, önerileri temsil eder
                        for oneriler in ders[DERSE_DAIR_ONERILER]:
                            if len(oneriler[ONERILER]) > 0:
                                f.write(
                                    f"##### 📌 Öneri sahibi: {oneriler[ONERI_SAHIBI]}\n"
                                )  # Sabitleme pimi emoji, öneri sahibini temsil eder
                                for oneri in oneriler[ONERILER]:
                                    f.write(f"- {oneri}\n")
                    f.write("\n#### 📚 Faydalı Olabilecek Kaynaklar\n\n")
                    # Kitap emoji, kaynakları temsil eder
                    if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
                        # Faydalı olabilecek kaynakları Türkçe alfabetik sıraya göre sırala
                        sirali_kaynaklar = sorted(
                            ders[FAYDALI_OLABILECEK_KAYNAKLAR],
                            key=lambda x: unicodedata.normalize("NFKD", x).lower(),
                        )

                        # Sıralanmış kaynakları dosyaya yazdır
                        for kaynak in sirali_kaynaklar:
                            f.write(f"- 📄 {kaynak} ✨\n")
                    f.write(GENEL_CIKMIS_SORULAR_METNI)
                    f.write(f"  - ℹ️ {FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI}\n")
                    if (
                        DERSI_VEREN_HOCALAR in ders
                        and len(ders[DERSI_VEREN_HOCALAR]) > 0
                    ):
                        f.write("\n#### 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:\n")
                        # Kadın öğretmen emoji, akademisyenleri temsil eder (cinsiyete göre değişebilir)
                        for hoca in ders[DERSI_VEREN_HOCALAR]:
                            f.write(f"- {hoca[KISALTMA]}\n")
                    if GUNCEL_MI in ders and not ders[GUNCEL_MI]:
                        f.write("\n#### ℹ️ Dersin içeriği güncel değil\n")
                        f.write(f"- {guncel_olmayan_ders_aciklamasi}\n")
                if count > 1:
                    break
        custom_write(f"{ders[AD]} README.md donemine eklendi.\n")


donemler = json_oku(DONEMLER_JSON_NAME)
if donemler is not None:
    custom_write("Donem README'leri olusturuluyor...\n")
    custom_write("Donem bilgileri README'ye ekleniyor...\n")
    donemlere_gore_readme_olustur(donemler)
    custom_write("Ders bilgileri README'ye ekleniyor...\n")
    ders_bilgilerini_readme_ile_birlestir(
        dersler[DERSLER], donemler[DONEMLER], dersler[GUNCEL_OLMAYAN_DERS_ACIKLAMASI]
    )
else:
    custom_write_error("Donem bilgileri bulunamadi.\n")
