import json
import os
import difflib
import re

CIKMISLAR_LINKI = "https://drive.google.com/drive/folders/1LI_Bo7kWqI2krHTw0noUFl9crfZSlrZh"
ANA_README_YOLU = "../README.md"
YILDIZ_OYLAMA_LINKI = "https://forms.gle/s6ZMrQG4q578pEzm7"
HOCA_YORULMALA_LINKI = "https://forms.gle/WbwDxHUz6ebJA7t36"
DERS_OYLAMA_LINKI = "https://forms.gle/3njZjmhm215YCAxe6"
DERS_YORUMLAMA_LINKI = "https://forms.gle/SzNmK1w4rVaKE4ee8"
if os.path.exists(ANA_README_YOLU):
    os.remove(ANA_README_YOLU)
unvanlarin_onceligi = {"Prof.": 1, "Doç.": 2, "Dr.": 3}
def hoca_siralama_anahtari(hoca):
    unvan = hoca['ad'].split()[0]  # İsmin ilk kelimesini (unvanı) al
    return (unvanlarin_onceligi.get(unvan, 4), hoca['ad'])  # Unvan önceliği ve tam ad
# JSON dosyasından hocaların bilgilerini okuyan fonksiyon
def json_oku(json_dosyasi):
    with open(json_dosyasi, 'r') as f:
        return json.load(f)
def puanlari_yildiza_cevir(puan, max_yildiz_sayisi=10):
    if puan % 10 !=0:
        puan +=10
    dolu_yildiz_sayisi = puan // 10  # Her 10 puan için 1 yıldız
    bos_yildiz_sayisi = max_yildiz_sayisi - dolu_yildiz_sayisi
    return '★' * dolu_yildiz_sayisi + '☆' * bos_yildiz_sayisi
# Bilgileri README'ye ekleyen fonksiyon
def hocalari_readme_ye_ekle(bilgiler):
    bilgiler['hocalar'] = [hoca for hoca in bilgiler['hocalar'] if hoca['ad'] != '']
    with open(ANA_README_YOLU, 'a') as f:
        f.write(f"\n\n\n## 🎓 {bilgiler['bolum_adi']}\n")
        f.write(f"📚 {bilgiler['bolum_aciklamasi']}\n\n\n\n")
        en_populer_hoca_oy_sayisi = 0
        en_populer_hoca_adi = ""
        if 'en_populer_hoca' in bilgiler and 'hoca_adi' in bilgiler['en_populer_hoca']:
            en_populer_hoca_adi = bilgiler['en_populer_hoca']['hoca_adi']
            if 'oy_sayisi' in bilgiler['en_populer_hoca']:
                en_populer_hoca_oy_sayisi = bilgiler['en_populer_hoca']['oy_sayisi']
        
        for hoca in sorted(bilgiler['hocalar'], key=hoca_siralama_anahtari):
            populer_isaret = "👑" if hoca['ad'] == en_populer_hoca_adi else ""
            hoca_emoji = "👨‍🏫" if hoca['erkek_mi'] else "👩‍🏫"
            populer_bilgi = f" En popüler hoca ({en_populer_hoca_oy_sayisi} oy)" if hoca['ad'] == en_populer_hoca_adi else ""
            f.write(f"\n\n\n### {hoca_emoji} {hoca['ad']} {populer_isaret}{populer_bilgi}\n")
            f.write(f"- 🚪 **Ofis:** {hoca['ofis']}\n")
            f.write(f"- 🔗 **Araştırma Sayfası:** [{hoca['link']}]({hoca['link']})\n")
            f.write(f"- 💬 **Öğrenci Görüşleri:**\n")

            for gorus in hoca['ogrenci_gorusleri']:
                f.write(f"  - 👤 {gorus['kisi']}: {gorus['yorum']}\n")
            f.write(f"  - ℹ️ Siz de [linkten]({HOCA_YORULMALA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n")

            f.write("- 📚 **Verdiği Dersler:**\n")
            for ders in hoca["dersler"]:
                f.write(f"  - 📖 {ders}\n")
            f.write(f"- ⭐ **Yıldız Sayıları:**\n")
            if hoca['anlatim_puani'] != 0:
                f.write(f"  - 🎭 Dersi Zevkli Anlatır Mı:\t{puanlari_yildiza_cevir(hoca['anlatim_puani'])}\n")
                f.write(f"  - 🛣️ Dersi Kolay Geçer Miyim:\t{puanlari_yildiza_cevir(hoca['kolaylik_puani'])}\n")
                f.write(f"  - 🧠 Dersi Öğrenir Miyim:\t{puanlari_yildiza_cevir(hoca['ogretme_puani'])}\n")
                f.write(f"  - 🎉 Derste Eğlenir Miyim:\t{puanlari_yildiza_cevir(hoca['eglence_puani'])}\n")
            else:
                f.write("  - 🎭 Dersi Zevkli Anlatır Mı:\tbilinmiyor\n")
                f.write("  - 🛣️ Dersi Kolay Geçer Miyim:\tbilinmiyor\n")
                f.write("  - 🧠 Dersi Öğrenir Miyim:\tbilinmiyor\n")
                f.write("  - 🎉 Derste Eğlenir Miyim:\tbilinmiyor\n")
            if "oy_sayisi" in hoca:
                f.write(f"  - ℹ️ Yıldızlar {hoca['oy_sayisi']} oy üzerinden hesaplanmıştır. Siz de [linkten]({YILDIZ_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")


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
    for ders in dersler['dersler']:
        if ders['yil'] > 0:
            donem_key = f"{ders['yil']}. Yıl - {ders['donem']}"
        else:
            donem_key = ders['tip']
        if donem_key not in gruplanmis_dersler:
            gruplanmis_dersler[donem_key] = []
        gruplanmis_dersler[donem_key].append(ders)
    en_populer_ders_oy_sayisi = 0
    en_populer_ders_adi = ""
    if 'en_populer_ders' in dersler and 'ders_adi' in dersler['en_populer_ders']:
        en_populer_ders_adi = dersler['en_populer_ders']['ders_adi']
        if 'oy_sayisi' in dersler['en_populer_ders']:
            en_populer_ders_oy_sayisi = dersler['en_populer_ders']['oy_sayisi']
    
    with open(ANA_README_YOLU, 'a') as f:
        f.write(f"\n\n\n## 📚 {dersler['bolum_adi']} \n")
        f.write(f"📄 {dersler['bolum_aciklamasi']}\n\n\n\n")

        for donem in sorted(gruplanmis_dersler.keys(), key=donem_siralamasi):
            f.write(f"\n### 🗓 {donem}\n")
            for ders in gruplanmis_dersler[donem]:
                f.write("\n\n")
                populer_isaret = "👑" if ders['ad'] == en_populer_ders_adi else ""
                populer_bilgi = f" En popüler ders ({en_populer_ders_oy_sayisi} oy)" if ders['ad'] == en_populer_ders_adi else ""
                f.write(f"- 📘 **{ders['ad']}** {populer_isaret}{populer_bilgi}\n")
                f.write(f"  - 🏷️ **Ders Tipi:** {ders['tip']}\n")
                if 'ogrenci_gorusleri' in ders and ders['ogrenci_gorusleri']:
                    f.write(f"  - 💭 **Öğrenci Görüşleri:**\n")
                    for gorus in ders['ogrenci_gorusleri']:
                        f.write(f"    - 👤 {gorus['kisi']}: {gorus['yorum']}\n")
                    f.write(f"    - ℹ️ Siz de [linkten]({DERS_YORUMLAMA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n")

                f.write("  - ⭐ **Yıldız Sayıları:**\n")
                if 'kolaylik_puani' in ders:
                    f.write(f"    - ✅ Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(ders['kolaylik_puani'])}\n")
                if 'gereklilik_puani' in ders:
                    f.write(f"    - 🎯 Ders Mesleki Açıdan Gerekli Mi: {puanlari_yildiza_cevir(ders['gereklilik_puani'])}\n")
                if "oy_sayisi" in ders:
                    f.write(f"    - ℹ️ Yıldızlar {ders['oy_sayisi']} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
                else:
                    f.write(f"    - ℹ️ Yıldızlar {1} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.\n")
                
                    
                if "dersi_veren_hocalar" in ders:
                    f.write("  - 👨‍🏫 👩‍🏫 **Dersi Yürüten Akademisyenler:**\n")
                    for hoca in ders["dersi_veren_hocalar"]:
                        if hoca['ad'] != hocalar['en_populer_hoca']['hoca_adi']:
                            f.write(f"    - [{hoca['kisaltma']}]{baslik_linki_olustur(hoca['ad'])}\n")
                        else:
                            populer_isaret = "👑"
                            populer_bilgi = f" En popüler hoca ({hocalar['en_populer_hoca']['oy_sayisi']} oy)" if hoca['ad'] == hocalar['en_populer_hoca']['hoca_adi'] else ""
                            hoca_id = f'{hoca["ad"]} {populer_isaret}{populer_bilgi}'
                            f.write(f"    - [{hoca['kisaltma']}]{baslik_linki_olustur(hoca_id)}\n")

# Giriş bilgilerini README'ye ekleyen fonksiyon
def readme_ye_giris_ekle(giris_bilgileri):
    with open(ANA_README_YOLU, 'w') as f:
        f.write(f"# 📖 {giris_bilgileri['baslik']}\n\n")  # Kitap emoji başlığı temsil eder
        f.write(f"{giris_bilgileri['aciklama']}\n\n")
        f.write('<p align="center">\n<img src="https://komarev.com/ghpvc/?username=baselkelziye&label=Görüntülenme+Sayısı" width="400" height="auto"/>\n</p>\n\n')
        f.write("## 📌 İçindekiler\n\n")  # Sabitleme pimi içindekileri temsil eder
        for item in giris_bilgileri['icindekiler']:
            f.write(f"- 🔗 {item}\n")  # Link emojisi her madde için kullanılır
def hoca_kisaltma_olustur(isim):
    """
    Bir isimden kısaltma oluşturur ve unvanları (Doç. Dr., Prof. Dr., Dr. vb.) atar.
    Örneğin "Prof. Dr. Ahmet Elbir" için "AEL", "Dr. Göksel Biricik" için "GB" döndürür.
    """
    # Unvanları ve noktaları kaldır
    for unvan in ["Prof. Dr.", "Doç. Dr.", "Dr.", "Prof.", "Doç."]:
        isim = isim.replace(unvan, "")
    isim = isim.replace(".", "").strip()
    if "Elbir" in isim:
        return "AEL"
    if "Biricik" in isim:
        return "G1"
    # İsimleri ayır ve baş harfleri al
    parcalar = isim.split()
    if len(parcalar) == 1:  # Eğer sadece bir isim varsa
        return parcalar[0][:2].upper()
    else:
        # İlk iki ismin baş harflerini ve son ismin ilk harfini al
        kisaltma = ''.join(parca[0].upper() for parca in parcalar[:-1])
        kisaltma += parcalar[-1][0].upper()
        if len(parcalar[-1]) == 1:  # Eğer son isim sadece bir harf ise (örneğin "M.")
            kisaltma += str(len(parcalar))  # Sıra numarasını ekle (örneğin "MAG" yerine "MAG1")
        return kisaltma

def readmeye_hocalar_icin_kisaltmalar_ekle(data):
    """
    Verilen hocalar listesi için kısaltmalar oluşturur ve bunları bir Markdown biçiminde döndürür.
    """
    kisaltmalar = {}
    for hoca in data["hocalar"]:
        kisaltma = hoca_kisaltma_olustur(hoca["ad"])
        kisaltmalar[kisaltma] = hoca["ad"]
    with open(ANA_README_YOLU, 'a') as f:
        f.write("## 📚 Hoca Kısaltmaları\n\n")
        for kisaltma in sorted(kisaltmalar.keys()):
            ad = kisaltmalar[kisaltma]
            f.write(f"- {kisaltma} : {ad}\n")
# Repo kullanımı bilgilerini README'ye ekleyen fonksiyon
def readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri):
    with open(ANA_README_YOLU, 'a') as f:
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
    with open(ANA_README_YOLU, 'a') as f:
        f.write(f"\n## ✍️ {yazar_notlari['baslik']}\n\n")  # Kalem emoji, yazarı temsil eder
        for aciklama in yazar_notlari['aciklamalar']:
            f.write(f"- 📝 {aciklama}\n")  # Not defteri ve kalem emoji, notları ve düşünceleri temsil eder

def readme_katkida_bulunanlar_ekle(veri):
    with open(ANA_README_YOLU, 'a', encoding='utf-8') as f:
        f.write(f"\n\n## 🤝 {veri['bolum_adi']}\n\n")  # El sıkışma emoji, işbirliğini ve katkıyı temsil eder
        f.write(f"{veri['bolum_aciklamasi']}\n\n")
        for katkida_bulunan in veri['katkida_bulunanlar']:
            f.write(f"- 👤 {katkida_bulunan['ad']}\n  - 🔗 Github Adresi: {katkida_bulunan['github_link']}\n")  # Kişi ve link emojisi
"""
BURASI ANA README OLUŞTURMA KISMI
"""
# JSON dosyasından yazar notlarını oku ve README'ye ekle
yazar_notlari = json_oku('yazarin_notlari.json')
# JSON dosyasından repo kullanımı bilgilerini oku ve README'ye ekle
repo_kullanimi_bilgileri = json_oku('repo_kullanimi.json')
# JSON dosyasından dersleri oku ve README'ye ekle
dersler = json_oku('dersler.json')
# JSON dosyasından hocaları oku ve README'ye ekle
hocalar = json_oku('hocalar.json')
giris_bilgileri = json_oku('giris.json')
katkida_bulunanlar = json_oku('katkida_bulunanlar.json')

readme_ye_giris_ekle(giris_bilgileri)
readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri)
dersleri_readme_ye_ekle(dersler)
hocalari_readme_ye_ekle(hocalar)
readme_ye_yazar_notlari_ekle(yazar_notlari)
readmeye_hocalar_icin_kisaltmalar_ekle(hocalar)
readme_katkida_bulunanlar_ekle(katkida_bulunanlar)
"""
BURASI ANA README OLUŞTURMA KISMI
"""

"""
BURASI DERSLER README OLUŞTURMA KISMI
"""

def benzerlik_skoru(str1, str2):
    return difflib.SequenceMatcher(None, str1, str2).ratio() * 100
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
def ders_klasorune_readme_olustur(ders, dosya_yolu):
    with open(os.path.join(dosya_yolu,"README.md"), 'w', encoding='utf-8') as f:
        # Ders başlığı
        f.write(f"# 📚 {ders['ad']}\n\n")

        # Ders bilgileri
        f.write("## ℹ️ Ders Bilgileri\n\n")
        f.write(f"- 📅 **Yıl:** {ders['yil']}\n")
        f.write(f"- 📆 **Dönem:** {ders['donem']}\n")
        f.write(f"- 🏫 **Ders Tipi:** {ders['tip']}\n")
        if 'ogrenci_gorusleri' and ders['ogrenci_gorusleri']:
            f.write(f"- 💬 **Öğrenci Görüşleri:**\n")
            for gorus in ders['ogrenci_gorusleri']:
                f.write(f"  - 👤 {gorus['kisi']}: {gorus['yorum']}\n")
        f.write("- ⭐ **Yıldız Sayıları:**\n")
        f.write(f"  - 🛤️ **Kolaylık Puanı:** {puanlari_yildiza_cevir(ders['kolaylik_puani'])}\n")
        f.write(f"  - 🔑 **Gereklilik Puanı:** {puanlari_yildiza_cevir(ders['gereklilik_puani'])}\n\n")

        if "derse_dair_oneriler" in ders:
            # Derse dair öneriler
            f.write("## 📝 Derse Dair Öneriler\n\n")
            for oneriler in ders['derse_dair_oneriler']:
                f.write(f"### 💡 Öneri sahibi: {oneriler['oneri_sahibi']}\n")
                for oneri in oneriler['oneriler']:
                    f.write(f"- {oneri}\n")
        f.write("\n## 📖 Faydalı Olabilecek Kaynaklar\n\n")
        f.write(f"- 📄 [Çıkmış Sorular]({CIKMISLAR_LINKI})\n")
        if "faydali_olabilecek_kaynaklar" in ders:
            # Faydalı olabilecek kaynaklar
            for kaynak in ders['faydali_olabilecek_kaynaklar']:
                f.write(f"- {kaynak}\n")
        if "dersi_veren_hocalar" in ders:
            f.write("\n## 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:\n")
            for hoca in ders["dersi_veren_hocalar"]:
                f.write(f"- {hoca['kisaltma']}\n")

            
for ders in dersler['dersler']:
    ders_klasoru = en_iyi_eslesen_klasor_yolu_bul("../",ders["ad"])
    if ders_klasoru:
        ders_klasorune_readme_olustur(ders, ders_klasoru)
"""
BURASI DERSLER README OLUŞTURMA KISMI
"""


"""
Burası Dönem Readme oluşturma kısmı
"""

def donemlere_gore_readme_olustur(donemler):

    # Her dönem için README.md oluştur
    for donem in donemler['donemler']:
        dosya_yolu = os.path.join(donem['dosya_yolu'], 'README.md')
        with open(dosya_yolu, 'w', encoding='utf-8') as f:
            f.write(f"# 📅 {donem['donem_adi']}\n\n")  # Takvim emoji, dönemi temsil eder
            f.write("## 📝 Genel Tavsiyeler\n\n")  # Not defteri ve kalem emoji, tavsiyeleri temsil eder
            for tavsiye in donem['genel_tavsiyeler']:
                f.write(f"- 💡 {tavsiye}\n")  # Ampul emoji, fikir veya tavsiye temsil eder
            if donem["donem_adi"] != "Mesleki Seçmeli Dersler":
                f.write("## 📚 Dönemin Zorunlu Dersleri\n\n")  # Kitap emoji, zorunlu dersleri temsil eder

def ders_bilgilerini_readme_ile_birlestir(dersler, donemler):
    # Her ders için ilgili dönem README'sine ekle
    for ders in dersler:
        for donem in donemler:
            if ders['yil'] == donem['yil'] and ders['donem'] == donem['donem']:
                dosya_yolu = os.path.join(donem['dosya_yolu'], 'README.md')
                with open(dosya_yolu, 'a', encoding='utf-8') as f:
                    f.write(f"\n### 📘 {ders['ad']}\n\n")  # Kitap emoji, ders adını temsil eder
                    f.write("#### 📄 Ders Bilgileri\n\n")  # Kağıt emoji, ders bilgilerini temsil eder
                    f.write(f"- 📅 **Yıl:** {ders['yil']}\n")
                    f.write(f"- 📆 **Dönem:** {ders['donem']}\n")
                    f.write(f"- 🏫 **Ders Tipi:** {ders['tip']}\n")
                    if ders['ogrenci_gorusleri']:
                        f.write(f"- 💬 **Öğrenci Görüşleri:**\n")  # Konuşma balonu emoji, öğrenci görüşlerini temsil eder
                        for gorus in ders['ogrenci_gorusleri']:
                            f.write(f"  - 👤 {gorus['kisi']}: {gorus['yorum']}\n")  # Kişi emoji, öğrenciyi temsil eder
                    f.write(f"- ⭐ **Kolaylık Puanı:** {puanlari_yildiza_cevir(ders['kolaylik_puani'])}\n")
                    f.write(f"- 🔑 **Gereklilik Puanı:** {puanlari_yildiza_cevir(ders['gereklilik_puani'])}\n\n")

                    if "derse_dair_oneriler" in ders:
                        f.write("#### 💡 Derse Dair Öneriler\n\n")  # Ampul emoji, önerileri temsil eder
                        for oneriler in ders['derse_dair_oneriler']:
                            f.write(f"##### 📌 Öneri sahibi: {oneriler['oneri_sahibi']}\n")  # Sabitleme pimi emoji, öneri sahibini temsil eder
                            for oneri in oneriler['oneriler']:
                                f.write(f"- {oneri}\n")
                    f.write("\n#### 📚 Faydalı Olabilecek Kaynaklar\n\n")  # Kitap emoji, kaynakları temsil eder
                    if "faydali_olabilecek_kaynaklar" in ders:
                        for kaynak in ders['faydali_olabilecek_kaynaklar']:
                            f.write(f"- {kaynak}\n")
                    f.write(f"- 📄 [Çıkmış Sorular]({CIKMISLAR_LINKI})\n")
                    if "dersi_veren_hocalar" in ders:
                        f.write("\n#### 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:\n")  # Kadın öğretmen emoji, akademisyenleri temsil eder (cinsiyete göre değişebilir)
                        for hoca in ders["dersi_veren_hocalar"]:
                            f.write(f"- {hoca['kisaltma']}\n")

donemler = json_oku('donemler.json')
donemlere_gore_readme_olustur(donemler)
ders_bilgilerini_readme_ile_birlestir(dersler['dersler'], donemler['donemler'])
