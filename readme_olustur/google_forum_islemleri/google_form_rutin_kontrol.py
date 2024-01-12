import requests
import hashlib
import os
import subprocess
import time
import json
import sys
sys.path.append(os.path.join(os.path.dirname(__file__), '..', "readme_guncelleme_arayuzu_python"))
from degiskenler import *
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
    readme_guncelle_sc = README_GUNCELLE_BAT if sys.platform.startswith('win') else README_GUNCELLE_SH
    google_form_guncelle_sc = GOOGLE_FORM_GUNCELLE_BAT if sys.platform.startswith('win') else GOOGLE_FORM_GUNCELLE_SH
    # Git ve Python komutlarını sırayla çalıştır
    try:
        repo_yolu = os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        os.chdir(repo_yolu)
        stream = os.popen('git status')
        output = stream.read()
        if "nothing to commit, working tree clean" not in output:
            print("Dizinde değişiklikler var. Lütfen önce bu değişiklikleri commit yapın veya geri alın. Script durduruluyor.")
            time.sleep(10)
            exit(1)
        if not execute_command("git fetch"):
            print("Fetch sırasında conflict oluştu, script durduruluyor.")
            return 
        if not execute_command("git reset --hard origin/main"):
            print("Reset sırasında conflict oluştu, script durduruluyor.")
            return
        if not execute_command("git pull"):
            print("Pull sırasında conflict oluştu, script durduruluyor.")
            return
        os.chdir(os.path.join(original_directory, BIR_UST_DIZIN))
        if not execute_command(google_form_guncelle_sc):
            print("Google form içerikleri güncellenirken hata oluştu, script durduruluyor.")
            return
        os.system(readme_guncelle_sc)
        os.chdir(DOKUMANLAR_REPO_YOLU)
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
urls = {
    "DERS YORUMLAMA": DERS_YORUMLAMA_LINKI_CSV,
    "HOCA YORUMLAMA": HOCA_YORULMALA_LINKI_CSV,
    "DERS ÖZELLİKLERİ OYLAMA": DERS_OYLAMA_LINKI_CSV,
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