import requests
import hashlib
import os
import subprocess
import time
import sys
sys.path.append(os.path.join(os.path.dirname(__file__), '..', "readme_guncelleme_arayuzu_python"))
from degiskenler import *
from konfigurasyon_json_kontrol import konfigurasyon_ilklendirme_islemleri
def check_for_updates(key, url):

    # Belirtilen URL'den .xlsx dosyasını indir
    response = requests.get(url)
    data = response.content

    # İndirilen verinin hash değerini hesapla
    current_hash = hashlib.md5(data).hexdigest()

    # Eğer bu URL daha önce kontrol edildiyse ve hash değeri değişmişse, güncelleme olduğunu bildir
    if url in previous_hashes and previous_hashes[url] != current_hash:
        print(f"Değişiklik bulundu: {key}")
        previous_hashes[url] = current_hash
        return True

    # Güncel hash değerini kaydet
    previous_hashes[url] = current_hash
    return False

def execute_command(command):
    print(f"Komut çalıştırılıyor: {command}")
    try:
        # Komutu çalıştır ve çıktıyı yakala
        result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        # Komut başarıyla çalıştıysa, çıktıyı yazdır
        print(result.stdout.decode())
    except subprocess.CalledProcessError as e:
        # Komut hata ile sonuçlanırsa, hatayı yazdır ve script'i durdur
        print(f"Komut hatası: {e.stderr.decode()}")
        return False
    return True

def update_repository():
    # Mevcut çalışma dizinini sakla
    original_directory = os.getcwd()
    print("Güncellemeler uygulanıyor...")
    # Git ve Python komutlarını sırayla çalıştır
    try:
        os.chdir("../..")
        if not execute_command("git fetch"):
            print("Fetch sırasında conflict oluştu, script durduruluyor.")
            return 
        if not execute_command("git reset --hard origin/main"):
            print("Reset sırasında conflict oluştu, script durduruluyor.")
            return
        if not execute_command("git pull"):
            print("Pull sırasında conflict oluştu, script durduruluyor.")
            return
        os.chdir(original_directory)
        if not execute_command("python3 hoca_icerikleri_guncelle.py"):
            print("Hoca içerikleri güncellenirken hata oluştu, script durduruluyor.")
            return
        if not execute_command("python3 ders_icerikleri_guncelle.py"):
            print("Ders içerikleri güncellenirken hata oluştu, script durduruluyor.")
            return 
        os.chdir("..")
        os.system("python3 readme_olustur.py")
        os.chdir("..")
        if not execute_command("git add --all"): 
            print("Git add sırasında conflict oluştu, script durduruluyor.")
            return
        if not execute_command('git commit -m "rutin readme güncellemesi (robot)"'): 
            print("Git commit sırasında conflict oluştu, script durduruluyor.")
            return
        if not execute_command("git push"):
            print("Git push sırasında conflict oluştu, script durduruluyor.")
            return
    except Exception as e:
        # Hata oluşursa, hatayı yazdır ve e-posta gönder
        error_message = f"Script hatası: {e}"
        print(error_message)
    finally:
        # Başlangıç dizinine geri dön, hata olsa bile
        os.chdir(original_directory)
konfigurasyon_ilklendirme_islemleri(KONFIGURASYON_JSON_PATH)
# URL'leri kontrol et        
urls = {
    "DERS YORUMLAMA": DERS_YORUMLAMA_LINKI_CSV,
    "HOCA YORUMLAMA": HOCA_YORULMALA_LINKI_CSV,
    "DERS ÖZELLİKLERİ OYLAMA":DERS_OYLAMA_LINKI_CSV, 
    "HOCA ÖZELLİKLERİ OYLAMA": HOCA_OYLAMA_LINKI_CSV
}

# Dosyaların son boyutlarını saklamak için bir sözlük
previous_hashes = {}
for key, url in urls.items():
    # URL'lerin hash değerlerini hesapla
    response = requests.get(url)
    data = response.content
    previous_hashes[url] = hashlib.md5(data).hexdigest()
update_repository()
i = 0
timeout = 180
div = 3
print("Script çalışıyor...")
# Sonsuz döngü içinde URL'leri kontrol et ve güncelle
while True:
    for key, url in urls.items():
        if check_for_updates(key,url):
            print(f"Güncelleme tespit edildi: {key}")
            update_repository()
        else:
            print(f"Güncelleme yok: {key}")
    i += 1
    print(f"{i}. kontrol tamamlandı.")
    for k in range(0, int(timeout/div)):
        print(f"{timeout-k*div} saniye sonra kontrol edilecek.", end='\r')  # '\r' ile satırın başına dön
        time.sleep(div)