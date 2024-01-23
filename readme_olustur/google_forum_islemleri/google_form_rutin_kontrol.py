import requests
import hashlib
import os
import subprocess
import time
import sys

sys.path.append(
    os.path.join(os.path.dirname(__file__), "..", "readme_guncelleme_arayuzu_python")
)
from degiskenler import *


def check_for_updates(key, url):
    # Belirtilen URL'den .xlsx dosyasını indir
    response = requests.get(url)
    data = response.content

    # İndirilen verinin hash değerini hesapla
    current_hash = hashlib.md5(data).hexdigest()

    # Eğer bu URL daha önce kontrol edildiyse ve hash değeri değişmişse, güncelleme olduğunu bildir
    if url in previous_hashes and previous_hashes[url] != current_hash:
        sys.stdout.write(f"Değişiklik bulundu: {key}\n")
        previous_hashes[url] = current_hash
        return True

    # Güncel hash değerini kaydet
    previous_hashes[url] = current_hash
    return False


def execute_command(command):
    sys.stdout.write(f"Komut çalıştırılıyor: {command}\n")
    try:
        # Komutu çalıştır ve çıktıyı yakala
        result = subprocess.run(
            command,
            shell=True,
            check=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        # Komut başarıyla çalıştıysa, çıktıyı yazdır
        sys.stdout.write(result.stdout.decode()+ "\n")
    except subprocess.CalledProcessError as e:
        # Komut hata ile sonuçlanırsa, hatayı yazdır ve script'i durdur
        sys.stderr.write(f"Komut hatası: {e.stderr.decode()}\n")
        return False
    return True


def update_repository():
    # Mevcut çalışma dizinini sakla
    original_directory = os.getcwd()
    sys.stdout.write("Güncellemeler uygulanıyor...\n")
    readme_guncelle_komutu = f"python3 readme_olustur.py"
    # google form güncelle komutu
    google_form_guncelle_komutu = f"python3 hoca_icerikleri_guncelle.py && python3 ders_icerikleri_guncelle.py"
    # Git ve Python komutlarını sırayla çalıştır
    try:
        repo_yolu = os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        os.chdir(repo_yolu)
        stream = os.popen("git status")
        output = stream.read()
        if "nothing to commit, working tree clean" not in output:
            sys.stderr.write(
                "Dizinde değişiklikler var. Lütfen önce bu değişiklikleri commit yapın veya geri alın. Script durduruluyor."
            )
            exit(1)
        if not execute_command("git fetch"):
            sys.stderr.write("Fetch sırasında conflict oluştu, script durduruluyor.\n")
            return
        if not execute_command("git reset --hard origin/main"):
            sys.stderr.write("Reset sırasında conflict oluştu, script durduruluyor.\n")
            return
        if not execute_command("git pull"):
            sys.stderr.write("Pull sırasında conflict oluştu, script durduruluyor.\n")
            return
        os.chdir(original_directory)
        if not execute_command(google_form_guncelle_komutu):
            sys.stderr.write(
                "Google form içerikleri güncellenirken hata oluştu, script durduruluyor."
            )
            return
        os.chdir(BIR_UST_DIZIN)
        os.system(readme_guncelle_komutu)
        os.chdir(DOKUMANLAR_REPO_YOLU)
        if not execute_command("git add --all"):
            sys.stderr.write("Git add sırasında conflict oluştu, script durduruluyor.\n")
            return
        if not execute_command('git commit -m "rutin readme güncellemesi (robot)"'):
            sys.stderr.write("Git commit sırasında conflict oluştu, script durduruluyor.\n")
            return
        if not execute_command("git push"):
            sys.stderr.write("Git push sırasında conflict oluştu, script durduruluyor.\n")
            return
    except Exception as e:
        # Hata oluşursa, hatayı yazdır ve e-posta gönder
        error_message = f"Script hatası: {e}"
        sys.stderr.write(error_message)
    finally:
        # Başlangıç dizinine geri dön, hata olsa bile
        os.chdir(original_directory)


urls = {
    "DERS YORUMLAMA": DERS_YORUMLAMA_LINKI_CSV,
    "HOCA YORUMLAMA": HOCA_YORULMALA_LINKI_CSV,
    "DERS ÖZELLİKLERİ OYLAMA": DERS_OYLAMA_LINKI_CSV,
    "HOCA ÖZELLİKLERİ OYLAMA": HOCA_OYLAMA_LINKI_CSV,
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
sys.stdout.write("Script çalışıyor...\n")
# Sonsuz döngü içinde URL'leri kontrol et ve güncelle
while True:
    for key, url in urls.items():
        if check_for_updates(key, url):
            sys.stdout.write(f"Güncelleme tespit edildi: {key}\n")
            update_repository()
        else:
            sys.stdout.write(f"Güncelleme yok: {key}\n")
    i += 1
    sys.stdout.write(f"{i}. kontrol tamamlandı.\n")
    for k in range(0, int(timeout / div)):
        sys.stdout.write(
            f"{timeout-k*div} saniye sonra kontrol edilecek.\n"
        )  # '\r' ile satırın başına dön
        time.sleep(div)
