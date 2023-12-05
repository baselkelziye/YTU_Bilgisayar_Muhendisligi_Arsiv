import json
import os

if os.path.exists('README.md'):
    os.remove('README.md')

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
    with open('README.md', 'a') as f:
        f.write(f"\n\n\n## {bilgiler['bolum_adi']}\n")
        f.write(f"{bilgiler['bolum_aciklamasi']}\n\n\n\n")
        for hoca in sorted(bilgiler['hocalar'], key=lambda x: x['ad']):
            f.write(f"\n\n\n### {hoca['ad']}\n")
            f.write(f"- **Ofis:** {hoca['ofis']}\n")
            f.write(f"- **Araştırma Sayfası:** [{hoca['link']}]({hoca['link']})\n")
            f.write(f"- **Hakkında:** {hoca['hakkinda']}\n")
            f.write("- **Verdiği Dersler:**\n")
            for ders in hoca["dersler"]:
                f.write(f"  - {ders}\n")
            f.write("- **Yıldız Sayıları:**\n")
            if hoca['anlatim_puani'] != 0:
                f.write(f"  - Dersi Zevkli Anlatır Mı: {puanlari_yildiza_cevir(hoca['anlatim_puani'])}\n")
                f.write(f"  - Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(hoca['kolaylik_puani'])}\n")
                f.write(f"  - Dersi Öğrenir Miyim: {puanlari_yildiza_cevir(hoca['ogretme_puani'])}\n")
                f.write(f"  - Derste Eğlenir Miyim: {puanlari_yildiza_cevir(hoca['eglence_puani'])}\n")
            else:
                f.write("  - Dersi Zevkli Anlatır Mı: bilinmiyor\n")
                f.write("  - Dersi Kolay Geçer Miyim: bilinmiyor\n")
                f.write("  - Dersi Öğrenir Miyim: bilinmiyor\n")
                f.write("  - Derste Eğlenir Miyim: bilinmiyor\n")


def donem_siralamasi(donem_key):
    if donem_key == "Mesleki Seçmeli":
        return (999, 999)  # Mesleki Seçmeli dersleri en sona koy
    yil, donem = donem_key.split(" - ")
    return (int(yil.split('.')[0]), 0 if donem == "Güz" else 1)

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

    with open('README.md', 'a') as f:
        f.write(f"\n\n\n## {dersler['bolum_adi']}\n")
        f.write(f"{dersler['bolum_aciklamasi']}\n\n\n\n")

        for donem in sorted(gruplanmis_dersler.keys(), key=donem_siralamasi):
            f.write(f"\n### {donem}\n")
            for ders in gruplanmis_dersler[donem]:
                f.write("\n\n")
                f.write(f"- **{ders['ad']}**\n")
                f.write(f"  - **Ders Tipi:** {ders['tip']}\n")
                f.write(f"  - **Hakkında:** {ders['hakkinda']}\n")
                f.write("  - **Yıldız Sayıları:**\n")
                f.write(f"    - Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(ders['kolaylik_puani'])}\n")
                f.write(f"    - Ders Mesleki Açıdan Gerekli Mi: {puanlari_yildiza_cevir(ders['gereklilik_puani'])}\n")
                if "dersi_veren_hocalar" in ders:
                    f.write("  - **Dersi Yürüten Akademisyenler:**\n")
                    for hoca in ders["dersi_veren_hocalar"]:
                        f.write(f"    - {hoca}\n")
# Giriş bilgilerini README'ye ekleyen fonksiyon
def readme_ye_giris_ekle(giris_bilgileri):
    with open('README.md', 'w') as f:
        f.write(f"# {giris_bilgileri['baslik']}\n\n")
        f.write(f"{giris_bilgileri['aciklama']}\n\n")
        f.write("## İçindekiler\n\n")
        for item in giris_bilgileri['icindekiler']:
            f.write(f"- {item}\n")
# Repo kullanımı bilgilerini README'ye ekleyen fonksiyon
def readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri):
    with open('README.md', 'a') as f:
        f.write(f"\n## {repo_kullanimi_bilgileri['baslik']}\n\n")
        f.write(f"{repo_kullanimi_bilgileri['aciklama']}\n")
        for talimat in repo_kullanimi_bilgileri['talimatlar']:
            f.write(f"- {talimat}\n")
# Yazar notlarını README'ye ekleyen fonksiyon
def readme_ye_yazar_notlari_ekle(yazar_notlari):
    with open('README.md', 'a') as f:
        f.write(f"\n## {yazar_notlari['baslik']}\n\n")
        for aciklama in yazar_notlari['aciklamalar']:
            f.write(f"- {aciklama}\n")
# JSON dosyasından yazar notlarını oku ve README'ye ekle
yazar_notlari = json_oku('yazarin_notlari.json')
# JSON dosyasından repo kullanımı bilgilerini oku ve README'ye ekle
repo_kullanimi_bilgileri = json_oku('repo_kullanimi.json')
# JSON dosyasından dersleri oku ve README'ye ekle
dersler = json_oku('dersler.json')
# JSON dosyasından hocaları oku ve README'ye ekle
hocalar = json_oku('hocalar.json')
giris_bilgileri = json_oku('giris.json')


readme_ye_giris_ekle(giris_bilgileri)
hocalari_readme_ye_ekle(hocalar)
dersleri_readme_ye_ekle(dersler)
readme_ye_repo_kullanimi_ekle(repo_kullanimi_bilgileri)
readme_ye_yazar_notlari_ekle(yazar_notlari)