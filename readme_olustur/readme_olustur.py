import json
import os
import difflib
import re
import sys
# Mevcut dosyanın bulunduğu dizini al
current_directory = os.path.dirname(os.path.abspath(__file__))
# Göreceli yol (örneğin, bu dizinden 'readme_guncelleme_arayuzu_python' klasörüne giden yol)
relative_path = 'readme_guncelleme_arayuzu_python'
# Göreceli yolu tam yola çevir
absolute_path = os.path.join(current_directory, relative_path)
# Tam yolu sys.path listesine ekle
sys.path.append(absolute_path)

from hoca_kisaltma_olustur import hoca_kisaltma_olustur
from degiskenler import *

if os.path.exists(ANA_README_YOLU):
    os.remove(ANA_README_YOLU)
unvanlarin_onceligi = {"Prof.": 1, "Doç.": 2, "Dr.": 3}

# Klasörler için benzerlik skoru hesaplayan fonksiyon
def benzerlik_skoru(str1, str2):
    return difflib.SequenceMatcher(None, str1, str2).ratio() * 100
# En iyi eşleşmeyi bulan fonksiyon
def en_iyi_eslesen_klasor_yolu_bul(baslangic_yolu, aranan_ad):
    en_iyi_eslesme = None
    en_yuksek_yuzde = 0

    for dizin_yolu, alt_dizinler, _ in os.walk(baslangic_yolu):
        for klasor_ad in alt_dizinler:
            # Eşleşme skoru hesaplama
            skor = benzerlik_skoru(aranan_ad,klasor_ad)
            # Her iki yüzde de %50'den büyükse, eşleşme olarak kabul et
            if skor > en_yuksek_yuzde:
                en_yuksek_yuzde = skor
                en_iyi_eslesme = os.path.join(dizin_yolu, klasor_ad)

    return None if (en_yuksek_yuzde < 71 or (len(en_iyi_eslesme.split(os.sep)) < 3 and "Projesi" not in en_iyi_eslesme)) else en_iyi_eslesme

# GitHub'daki klasör için tam URL oluşturan fonksiyon
def yerel_yoldan_github_linkine(klasor_yolu, repo_url="https://github.com/baselkelziye/YTU_Bilgisayar_Muhendisligi_Arsiv"):
    """
    Yerel bir klasör yolunu GitHub reposundaki karşılık gelen klasörün URL'sine dönüştürür.
    Göreceli yolları (..) kaldırır ve boşlukları uygun bir şekilde değiştirir.

    :param klasor_yolu: Yerel sistemdeki klasör yolu (örn. "ders_notlari/ISL101").
    :param repo_url: GitHub'daki repository'nin URL'si.
    :return: GitHub'daki klasör için tam URL.
    """
    if klasor_yolu is None:
        return None
    klasor_yolu = klasor_yolu.replace("..", "")
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
    unvan = hoca[AD].split()[0]  # İsmin ilk kelimesini (unvanı) al
    return (unvanlarin_onceligi.get(unvan, 4), hoca[AD])  # Unvan önceliği ve tam ad
# JSON dosyasından hocaların bilgilerini okuyan fonksiyon
def json_oku(json_dosyasi):
    with open(json_dosyasi, 'r', encoding='utf-8') as f:
        return json.load(f)
def puanlari_yildiza_cevir(puan, max_yildiz_sayisi=10):
    if puan % 10 !=0:
        puan +=10
    dolu_yildiz_sayisi = puan // 10  # Her 10 puan için 1 yıldız
    bos_yildiz_sayisi = max_yildiz_sayisi - dolu_yildiz_sayisi
    return '★' * dolu_yildiz_sayisi + '☆' * bos_yildiz_sayisi
# Bilgileri README'ye ekleyen fonksiyon
def hocalari_readme_ye_ekle(bilgiler):
    bilgiler[HOCALAR] = [hoca for hoca in bilgiler[HOCALAR] if hoca[AD] != '']
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write(f"\n\n\n## 🎓 {bilgiler['bolum_adi']}\n")
        f.write(f"📚 {bilgiler['bolum_aciklamasi']}\n\n\n\n")
        en_populer_hoca_oy_sayisi = 0
        en_populer_hoca_adi = ""
        if EN_POPULER_HOCA in bilgiler and HOCA_ADI in bilgiler[EN_POPULER_HOCA]:
            en_populer_hoca_adi = bilgiler[EN_POPULER_HOCA][HOCA_ADI]
            if OY_SAYISI in bilgiler[EN_POPULER_HOCA]:
                en_populer_hoca_oy_sayisi = bilgiler[EN_POPULER_HOCA][OY_SAYISI]
        
        for hoca in sorted(bilgiler[HOCALAR], key=hoca_siralama_anahtari):
            populer_isaret = "👑" if hoca[AD] == en_populer_hoca_adi else ""
            hoca_emoji = "👨‍🏫" if hoca[ERKEK_MI] else "👩‍🏫"
            populer_bilgi = f" En popüler hoca ({en_populer_hoca_oy_sayisi} oy)" if hoca[AD] == en_populer_hoca_adi else ""
            f.write(f"\n\n\n### {hoca_emoji} {hoca[AD]} {populer_isaret}{populer_bilgi}\n")
            f.write(f"- 🚪 **Ofis:** {hoca[OFIS]}\n")
            f.write(f"- 🔗 **Araştırma Sayfası:** [{hoca[LINK]}]({hoca[LINK]})\n")
            f.write(f"- 💬 **Öğrenci Görüşleri:**\n")

            for gorus in hoca[OGRENCI_GORUSLERI]:
                f.write(f"  - 👤 {gorus[KISI]}: {gorus[YORUM]}\n")
            f.write(f"  - ℹ️ Siz de [linkten]({HOCA_YORULMALA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n")

            f.write("- 📚 **Verdiği Dersler:**\n")
            for ders in hoca[DERSLER]:
                if ders != dersler['en_populer_ders']['ders_adi']:
                    f.write(f"  - 📖 [{ders}]{baslik_linki_olustur(ders)}\n")
                else:
                    populer_isaret = "👑"
                    populer_bilgi = f" En popüler ders ({dersler['en_populer_ders'][OY_SAYISI]} oy)" if ders == dersler['en_populer_ders']['ders_adi'] else ""
                    ders_id = f'{ders} {populer_isaret}{populer_bilgi}'
                    f.write(f"  - 📖 [{ders}]{baslik_linki_olustur(ders_id)}\n")
            f.write(f"- ⭐ **Yıldız Sayıları:**\n")
            if hoca['anlatim_puani'] != 0:
                f.write(f"  - 🎭 Dersi Zevkli Anlatır Mı:\t{puanlari_yildiza_cevir(hoca['anlatim_puani'])}\n")
                f.write(f"  - 🛣️ Dersi Kolay Geçer Miyim:\t{puanlari_yildiza_cevir(hoca[KOLAYLIK_PUANI])}\n")
                f.write(f"  - 🧠 Dersi Öğrenir Miyim:\t{puanlari_yildiza_cevir(hoca['ogretme_puani'])}\n")
                f.write(f"  - 🎉 Derste Eğlenir Miyim:\t{puanlari_yildiza_cevir(hoca['eglence_puani'])}\n")
            else:
                f.write("  - 🎭 Dersi Zevkli Anlatır Mı:\tbilinmiyor\n")
                f.write("  - 🛣️ Dersi Kolay Geçer Miyim:\tbilinmiyor\n")
                f.write("  - 🧠 Dersi Öğrenir Miyim:\tbilinmiyor\n")
                f.write("  - 🎉 Derste Eğlenir Miyim:\tbilinmiyor\n")
            if OY_SAYISI in hoca:
                f.write(f"  - ℹ️ Yıldızlar {hoca[OY_SAYISI]} oy üzerinden hesaplanmıştır. Siz de [linkten]({HOCA_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
            else:
                f.write(f"  - ℹ️ Yıldızlar 1 oy üzerinden hesaplanmıştır. Siz de [linkten]({HOCA_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
            

def donem_siralamasi(donem_key):
    if donem_key == "Mesleki Seçmeli":
        return (999, 999)  # Mesleki Seçmeli dersleri en sona koy
    yil, donem = donem_key.split(" - ")
    return (int(yil.split('.')[0]), 0 if donem == "Güz" else 1)

def baslik_linki_olustur(baslik):
    # Emoji ve özel karakterleri kaldır
    baslik = re.sub(r'[^\w\s-]', '', baslik)
    # Boşlukları '-' ile değiştir
    baslik = baslik.replace(' ', '-').lower()
    # Oluşturulan linki döndür
    return f"(#-{baslik})"
# Dersleri yıl ve döneme göre gruplayıp README'ye ekleyen fonksiyon
def dersleri_readme_ye_ekle(dersler):
    gruplanmis_dersler = {}
    for ders in dersler[DERSLER]:
        if ders[YIL] > 0:
            donem_key = f"{ders[YIL]}. Yıl - {ders[DONEM]}"
        else:
            donem_key = ders[TIP]
        if donem_key not in gruplanmis_dersler:
            gruplanmis_dersler[donem_key] = []
        gruplanmis_dersler[donem_key].append(ders)
    en_populer_ders_oy_sayisi = 0
    en_populer_ders_adi = ""
    if 'en_populer_ders' in dersler and 'ders_adi' in dersler['en_populer_ders']:
        en_populer_ders_adi = dersler['en_populer_ders']['ders_adi']
        if OY_SAYISI in dersler['en_populer_ders']:
            en_populer_ders_oy_sayisi = dersler['en_populer_ders'][OY_SAYISI]
    
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write(f"\n\n\n## 📚 {dersler['bolum_adi']} \n")
        f.write(f"📄 {dersler['bolum_aciklamasi']}\n\n\n\n")

        for donem in sorted(gruplanmis_dersler.keys(), key=donem_siralamasi):
            f.write(f"\n### 🗓 {donem}\n")
            for ders in gruplanmis_dersler[donem]:
                f.write("\n\n")
                populer_isaret = "👑" if ders[AD] == en_populer_ders_adi else ""
                populer_bilgi = f" En popüler ders ({en_populer_ders_oy_sayisi} oy)" if ders[AD] == en_populer_ders_adi else ""
                f.write(f"#### 📘 {ders[AD]} {populer_isaret}{populer_bilgi}\n")
                f.write(f"  - 🏷️ **Ders Tipi:** {ders[TIP]}\n")
                if OGRENCI_GORUSLERI in ders and ders[OGRENCI_GORUSLERI]:
                    f.write(f"  - 💭 **Öğrenci Görüşleri:**\n")
                    for gorus in ders[OGRENCI_GORUSLERI]:
                        f.write(f"    - 👤 {gorus[KISI]}: {gorus[YORUM]}\n")
                    f.write(f"    - ℹ️ Siz de [linkten]({DERS_YORUMLAMA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n")

                f.write("  - ⭐ **Yıldız Sayıları:**\n")
                if KOLAYLIK_PUANI in ders:
                    f.write(f"    - ✅ Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(ders[KOLAYLIK_PUANI])}\n")
                if GEREKLILIK_PUANI in ders:
                    f.write(f"    - 🎯 Ders Mesleki Açıdan Gerekli Mi: {puanlari_yildiza_cevir(ders[GEREKLILIK_PUANI])}\n")
                if OY_SAYISI in ders:
                    f.write(f"    - ℹ️ Yıldızlar {ders[OY_SAYISI]} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
                else:
                    f.write(f"    - ℹ️ Yıldızlar {1} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
                
                    
                if DERSI_VEREN_HOCALAR in ders and len(ders[DERSI_VEREN_HOCALAR]) > 0:
                    f.write("  - 👨‍🏫 👩‍🏫 **Dersi Yürüten Akademisyenler:**\n")
                    for hoca in ders[DERSI_VEREN_HOCALAR]:
                        if hoca[AD] != hocalar[EN_POPULER_HOCA][HOCA_ADI]:
                            f.write(f"    - [{hoca[KISALTMA]}]{baslik_linki_olustur(hoca[AD])}\n")
                        else:
                            populer_isaret = "👑"
                            populer_bilgi = f" En popüler hoca ({hocalar[EN_POPULER_HOCA][OY_SAYISI]} oy)" if hoca[AD] == hocalar[EN_POPULER_HOCA][HOCA_ADI] else ""
                            hoca_id = f'{hoca[AD]} {populer_isaret}{populer_bilgi}'
                            f.write(f"    - [{hoca[KISALTMA]}]{baslik_linki_olustur(hoca_id)}\n")
                ders_klasor_yolu = en_iyi_eslesen_klasor_yolu_bul("..", ders[AD])
                if ders_klasor_yolu is not None:
                    f.write(f"  - 📂 [Ders Klasörü]({(yerel_yoldan_github_linkine(ders_klasor_yolu))})\n")
                if GUNCEL_MI in ders and not ders[GUNCEL_MI]:
                    f.write("  - ℹ️ Dersin içeriği güncel değil\n")
                    f.write(f"    - {dersler[GUNCEL_OLMAYAN_DERS_ACIKLAMASI]}\n")
# Giriş bilgilerini README'ye ekleyen fonksiyon
def readme_ye_giris_ekle(giris_bilgileri):
    with open(ANA_README_YOLU, 'w',encoding='utf-8') as f:
        f.write(f"# 📖 {giris_bilgileri['baslik']}\n\n")  # Kitap emoji başlığı temsil eder
        f.write(f"{giris_bilgileri['aciklama']}\n\n")
        f.write('<p align="center">\n<img src="https://komarev.com/ghpvc/?username=baselkelziye&label=Görüntülenme+Sayısı" width="400" height="auto"/>\n</p>\n\n')
        f.write("## 📌 İçindekiler\n\n")  # Sabitleme pimi içindekileri temsil eder
        for item in giris_bilgileri['icindekiler']:
            f.write(f"- 🔗 {item}\n")  # Link emojisi her madde için kullanılır
def readmeye_hocalar_icin_kisaltmalar_ekle(data):
    """
    Verilen hocalar listesi için kısaltmalar oluşturur ve bunları bir Markdown biçiminde döndürür.
    """
    kisaltmalar = {}
    for hoca in data[HOCALAR]:
        kisaltma = hoca_kisaltma_olustur(hoca[AD])
        kisaltmalar[kisaltma] = hoca[AD]
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write("## 📚 Hoca Kısaltmaları\n\n")
        for kisaltma in sorted(kisaltmalar.keys()):
            ad = kisaltmalar[kisaltma]
            f.write(f"- {kisaltma} : {ad}\n")
# Repo kullanımı bilgilerini README'ye ekleyen fonksiyon
def readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri):
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write(f"\n\n\n## 🛠 {repo_kullanimi_bilgileri['baslik']}\n\n")  # Araç kutusu emojisi
        f.write(f"{repo_kullanimi_bilgileri['aciklama']}\n")
        for aciklama in repo_kullanimi_bilgileri['aciklamalar']:
            f.write(f"- 📋 {aciklama}\n")  # Not defteri emojisi
        f.write(f"\n\n📝 {repo_kullanimi_bilgileri['talimat']}\n")  # Yazma emojisi
        for talimat in repo_kullanimi_bilgileri['talimatlar']:
            f.write(f"- 👉 {talimat}\n")  # İşaret parmağı emojisi
        f.write(f"\n\n🔍 {repo_kullanimi_bilgileri['kavram']}\n")  # Büyüteç emojisi
        for kavram in sorted(repo_kullanimi_bilgileri['kavramlar'], key=lambda x: x['kavram'].lower()):
            f.write(f"- 💡 {kavram['kavram']}\n")  # Ampul emojisi, fikir veya kavramı temsil eder
            for aciklama in kavram['aciklamalar']:
                f.write(f"  - 📘 {aciklama}\n")  # Kitap emojisi, açıklamalar için

# Yazar notlarını README'ye ekleyen fonksiyon
def readme_ye_yazar_notlari_ekle(yazar_notlari):
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write(f"\n## ✍️ {yazar_notlari['baslik']}\n\n")  # Kalem emoji, yazarı temsil eder
        for aciklama in yazar_notlari['aciklamalar']:
            f.write(f"- 📝 {aciklama}\n")  # Not defteri ve kalem emoji, notları ve düşünceleri temsil eder

def readme_katkida_bulunanlar_ekle(veri):
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write(f"\n\n## 🤝 {veri['bolum_adi']}\n\n")  # El sıkışma emoji, işbirliğini ve katkıyı temsil eder
        f.write(f"{veri['bolum_aciklamasi']}\n\n")
        for katkida_bulunan in veri['katkida_bulunanlar']:
            f.write(f"- 👤 {katkida_bulunan[AD]}\n  - 🔗 Github Adresi: {katkida_bulunan['github_link']}\n")  # Kişi ve link emojisi
def sıralama_anahtarı(ders):
    yıl_sıralaması = [1, 2, 3, 4, 0]
    dönem_sıralaması = ['Güz', 'Bahar', '']

    yıl = yıl_sıralaması.index(ders[YIL]) if ders[YIL] in yıl_sıralaması else len(yıl_sıralaması)
    dönem = dönem_sıralaması.index(ders[DONEM]) if ders[DONEM] in dönem_sıralaması else len(dönem_sıralaması)
    ad = ders[AD].lower()

    return yıl, dönem, ad
"""
BURASI ANA README OLUŞTURMA KISMI
"""
print("README.md oluşturuluyor...")
# JSON dosyasından yazar notlarını oku ve README'ye ekle
yazar_notlari = json_oku('yazarin_notlari.json')
# JSON dosyasından repo kullanımı bilgilerini oku ve README'ye ekle
repo_kullanimi_bilgileri = json_oku('repo_kullanimi.json')
# JSON dosyasından dersleri oku ve README'ye ekle
dersler = json_oku('dersler.json')
dersler[DERSLER] = sorted(dersler[DERSLER], key=sıralama_anahtarı)
# JSON dosyasından hocaları oku ve README'ye ekle
hocalar = json_oku('hocalar.json')
giris_bilgileri = json_oku('giris.json')
katkida_bulunanlar = json_oku('katkida_bulunanlar.json')
print("Giriş bilgileri README'ye ekleniyor...")
readme_ye_giris_ekle(giris_bilgileri)
print("Repo kullanımı README'ye ekleniyor...")
readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri)
print("Ders bilgileri README'ye ekleniyor...")
dersleri_readme_ye_ekle(dersler)
print("Hoca bilgileri README'ye ekleniyor...")
hocalari_readme_ye_ekle(hocalar)
print("Yazar notları README'ye ekleniyor...")
readme_ye_yazar_notlari_ekle(yazar_notlari)
print("Hoca kısaltmaları README'ye ekleniyor...")
readmeye_hocalar_icin_kisaltmalar_ekle(hocalar)
print("Katkıda bulunanlar README'ye ekleniyor...")
readme_katkida_bulunanlar_ekle(katkida_bulunanlar)
"""
BURASI ANA README OLUŞTURMA KISMI
"""

"""
BURASI DERSLER README OLUŞTURMA KISMI
"""
print("Dersler README.md oluşturuluyor...")
def ders_klasorune_readme_olustur(ders, dosya_yolu, klasor_sonradan_olustu = False):
    with open(os.path.join(dosya_yolu,"README.md"), 'w', encoding='utf-8') as f:
        # Ders başlığı
        f.write(f"# 📚 {ders[AD]}\n\n")

        # Ders bilgileri
        f.write("## ℹ️ Ders Bilgileri\n\n")
        f.write(f"- 📅 **Yıl:** {ders[YIL]}\n")
        f.write(f"- 📆 **Dönem:** {ders[DONEM]}\n")
        f.write(f"- 🏫 **Ders Tipi:** {ders[TIP]}\n")
        if OGRENCI_GORUSLERI in ders and ders[OGRENCI_GORUSLERI]:
            f.write(f"- 💬 **Öğrenci Görüşleri:**\n")
            for gorus in ders[OGRENCI_GORUSLERI]:
                f.write(f"  - 👤 {gorus[KISI]}: {gorus[YORUM]}\n")
        f.write("- ⭐ **Yıldız Sayıları:**\n")
        if KOLAYLIK_PUANI in ders:
            f.write(f"  - 🛤️ **Kolaylık Puanı:** {puanlari_yildiza_cevir(ders[KOLAYLIK_PUANI])}\n")
            f.write(f"  - 🔑 **Gereklilik Puanı:** {puanlari_yildiza_cevir(ders[GEREKLILIK_PUANI])}\n\n")
        else:
            f.write(f"  - 🛤️ **Kolaylık Puanı:** {puanlari_yildiza_cevir(1)}\n")
            f.write(f"  - 🔑 **Gereklilik Puanı:** {puanlari_yildiza_cevir(1)}\n\n")
        if OY_SAYISI in ders:
            f.write(f"    - ℹ️ Yıldızlar {ders[OY_SAYISI]} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
        else:
            f.write(f"    - ℹ️ Yıldızlar {1} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
        
        if DERSE_DAIR_ONERILER in ders:
            # Derse dair öneriler
            f.write("## 📝 Derse Dair Öneriler\n\n")
            for oneriler in ders[DERSE_DAIR_ONERILER]:
                if len(oneriler[ONERILER]) > 0:
                    f.write(f"### 💡 Öneri sahibi: {oneriler[ONERI_SAHIBI]}\n")
                    for oneri in oneriler[ONERILER]:
                        f.write(f"- {oneri}\n")
        f.write("\n## 📖 Faydalı Olabilecek Kaynaklar\n\n")
        f.write(f"- 📄 [Çıkmış Sorular]({CIKMISLAR_LINKI})\n")
        if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
            # Faydalı olabilecek kaynaklar
            for kaynak in ders[FAYDALI_OLABILECEK_KAYNAKLAR]:
                f.write(f"- {kaynak}\n")
        if DERSI_VEREN_HOCALAR in ders and len(ders[DERSI_VEREN_HOCALAR]) > 0:
            f.write("\n## 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:\n")
            for hoca in ders[DERSI_VEREN_HOCALAR]:
                f.write(f"- {hoca[KISALTMA]}\n")
        if klasor_sonradan_olustu:
            f.write("\n## 😔 İçerik yok\n")
            f.write(f"- {dersler['ders_klasoru_bulunamadi_mesaji']}\n")
        if GUNCEL_MI in ders and not ders[GUNCEL_MI]:
            f.write("\n## ℹ️ Dersin içeriği güncel değil\n")
            f.write(f"- {dersler[GUNCEL_OLMAYAN_DERS_ACIKLAMASI]}\n")
def ders_klasoru_olustur(ders):
    if ders[DONEM] == "":
        yol = os.path.join("..","Mesleki Seçmeli")
        ders_klasor_yolu = os.path.join(yol,ders[AD])
    elif ders[TIP] == "Seçmeli 4":
        ders_klasor_yolu = os.path.join("..",ders[AD])
    elif ders[DONEM] == "Güz":
        ders_klasor_yolu = os.path.join("..",f"{ders[YIL]}-1",ders[AD])
    else:
        ders_klasor_yolu = os.path.join("..",f"{ders[YIL]}-2",ders[AD])
    os.makedirs(ders_klasor_yolu, exist_ok=True)
    return ders_klasor_yolu
def klasorde_baska_dosya_var_mi(ders_klasoru):
    icerikler = os.listdir(ders_klasoru)
    # README.md dosyasını çıkar
    icerikler = [dosya for dosya in icerikler if dosya.lower() != "readme.md"]
    return len(icerikler) > 0  # Eğer içerikler listesi boş değilse, başka dosya var demektir.
            
for ders in dersler[DERSLER]:
    print(f"{ders[AD]} README.md oluşturuluyor...")
    ders_klasoru = en_iyi_eslesen_klasor_yolu_bul("..",ders[AD])
    if ders_klasoru is not None:
        baska_dosya_var_mi= klasorde_baska_dosya_var_mi(ders_klasoru)
        if not baska_dosya_var_mi:
            ders_klasorune_readme_olustur(ders, ders_klasoru, klasor_sonradan_olustu = True)
        else:
            ders_klasorune_readme_olustur(ders, ders_klasoru, klasor_sonradan_olustu = False)
    else:
        ders_klasoru = ders_klasoru_olustur(ders)
        ders_klasorune_readme_olustur(ders, ders_klasoru, klasor_sonradan_olustu = True)
    print(f"{ders[AD]} README.md oluşturuldu.")
"""
BURASI DERSLER README OLUŞTURMA KISMI
"""


"""
Burası Dönem Readme oluşturma kısmı
"""
print("Dönem README'leri oluşturuluyor...")
def donemlere_gore_readme_olustur(donemler):

    # Her dönem için README.md oluştur
    for donem in donemler[DONEMLER]:
        print(f"{donem[DONEM_ADI]} README.md oluşturuluyor...")
        dosya_yolu = os.path.join(donem[DOSYA_YOLU], 'README.md')
        with open(dosya_yolu, 'w', encoding='utf-8') as f:
            f.write(f"# 📅 {donem[DONEM_ADI]}\n\n")  # Takvim emoji, dönemi temsil eder
            f.write("## 📝 Genel Tavsiyeler\n\n")  # Not defteri ve kalem emoji, tavsiyeleri temsil eder
            for tavsiye in donem['genel_tavsiyeler']:
                f.write(f"- 💡 {tavsiye}\n")  # Ampul emoji, fikir veya tavsiye temsil eder
            if donem[DONEM_ADI] != "Mesleki Seçmeli Dersler":
                f.write("## 📚 Dönemin Zorunlu Dersleri\n\n")  # Kitap emoji, zorunlu dersleri temsil eder
        print(f"{donem[DONEM_ADI]} README.md oluşturuldu.")

def ders_bilgilerini_readme_ile_birlestir(dersler, donemler, guncel_olmayan_ders_aciklamasi):
    # Her ders için ilgili dönem README'sine ekle
    for ders in dersler:
        print(f"{ders[AD]} README.md dönemine ekleniyor...")
        for donem in donemler:
            if ders[YIL] == donem[YIL] and ders[DONEM] == donem[DONEM]:
                dosya_yolu = os.path.join(donem[DOSYA_YOLU], 'README.md')
                with open(dosya_yolu, 'a', encoding='utf-8') as f:
                    f.write(f"\n### 📘 {ders[AD]}\n\n")  # Kitap emoji, ders adını temsil eder
                    f.write("#### 📄 Ders Bilgileri\n\n")  # Kağıt emoji, ders bilgilerini temsil eder
                    f.write(f"- 📅 **Yıl:** {ders[YIL]}\n")
                    f.write(f"- 📆 **Dönem:** {ders[DONEM]}\n")
                    f.write(f"- 🏫 **Ders Tipi:** {ders[TIP]}\n")
                    if OGRENCI_GORUSLERI in ders and ders[OGRENCI_GORUSLERI]:
                        f.write(f"- 💬 **Öğrenci Görüşleri:**\n")  # Konuşma balonu emoji, öğrenci görüşlerini temsil eder
                        for gorus in ders[OGRENCI_GORUSLERI]:
                            f.write(f"  - 👤 {gorus[KISI]}: {gorus[YORUM]}\n")  # Kişi emoji, öğrenciyi temsil eder
                    if KOLAYLIK_PUANI in ders:
                        f.write(f"- ⭐ **Kolaylık Puanı:** {puanlari_yildiza_cevir(ders[KOLAYLIK_PUANI])}\n")
                        f.write(f"- 🔑 **Gereklilik Puanı:** {puanlari_yildiza_cevir(ders[GEREKLILIK_PUANI])}\n\n")
                    else:
                        f.write(f"- ⭐ **Kolaylık Puanı:** {puanlari_yildiza_cevir(1)}\n")
                        f.write(f"- 🔑 **Gereklilik Puanı:** {puanlari_yildiza_cevir(1)}\n\n")
                    if OY_SAYISI in ders:
                        f.write(f"    - ℹ️ Yıldızlar {ders[OY_SAYISI]} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
                    else:
                        f.write(f"    - ℹ️ Yıldızlar {1} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
                    
                    if DERSE_DAIR_ONERILER in ders:
                        f.write("#### 💡 Derse Dair Öneriler\n\n")  # Ampul emoji, önerileri temsil eder
                        for oneriler in ders[DERSE_DAIR_ONERILER]:
                            if len(oneriler[ONERILER]) > 0:
                                f.write(f"##### 📌 Öneri sahibi: {oneriler[ONERI_SAHIBI]}\n")  # Sabitleme pimi emoji, öneri sahibini temsil eder
                                for oneri in oneriler[ONERILER]:
                                    f.write(f"- {oneri}\n")
                    f.write("\n#### 📚 Faydalı Olabilecek Kaynaklar\n\n")  # Kitap emoji, kaynakları temsil eder
                    if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
                        for kaynak in ders[FAYDALI_OLABILECEK_KAYNAKLAR]:
                            f.write(f"- {kaynak}\n")
                    f.write(f"- 📄 [Çıkmış Sorular]({CIKMISLAR_LINKI})\n")
                    if DERSI_VEREN_HOCALAR in ders and len(ders[DERSI_VEREN_HOCALAR]) > 0:
                        f.write("\n#### 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:\n")  # Kadın öğretmen emoji, akademisyenleri temsil eder (cinsiyete göre değişebilir)
                        for hoca in ders[DERSI_VEREN_HOCALAR]:
                            f.write(f"- {hoca[KISALTMA]}\n")
                    if GUNCEL_MI in ders and not ders[GUNCEL_MI]:
                        f.write("\n#### ℹ️ Dersin içeriği güncel değil\n")
                        f.write(f"- {guncel_olmayan_ders_aciklamasi}\n")
        print(f"{ders[AD]} README.md dönemine eklendi.")

donemler = json_oku('donemler.json')
print("Dönem bilgileri README'ye ekleniyor...")
donemlere_gore_readme_olustur(donemler)
print("Ders bilgileri README'ye ekleniyor...")
ders_bilgilerini_readme_ile_birlestir(dersler[DERSLER], donemler[DONEMLER], dersler[GUNCEL_OLMAYAN_DERS_ACIKLAMASI])
