import requests
import hashlib
import os
import subprocess
import time
import sys
import threading

sys.path.append(
    os.path.join(os.path.dirname(__file__), "..", "readme_guncelleme_arayuzu_python")
)
from degiskenler import *
from cikti_yazdirma import custom_write, custom_write_error


def check_for_updates(key, url):
    # Belirtilen URL'den .xlsx dosyasını indir
    response = requests.get(url)
    data = response.content

    # İndirilen verinin hash değerini hesapla
    current_hash = hashlib.md5(data).hexdigest()

    # Eğer bu URL daha önce kontrol edildiyse ve hash değeri değişmişse, güncelleme olduğunu bildir
    if url in previous_hashes and previous_hashes[url] != current_hash:
        custom_write(f"Değişiklik bulundu: {key}\n")
        previous_hashes[url] = current_hash
        return True

    # Güncel hash değerini kaydet
    previous_hashes[url] = current_hash
    return False


def read_stream(stream, callback):
    while True:
        line = stream.readline()
        if not line:
            break
        callback(line)


def execute_command(command):
    custom_write(f"Komut çalıştırılıyor: {command}\n")
    try:
        # Komutu çalıştır
        with subprocess.Popen(
            command,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        ) as process:
            # Standart çıktı ve hata çıktısını okuyacak thread'leri oluştur
            stdout_thread = threading.Thread(
                target=read_stream, args=(process.stdout, custom_write)
            )
            stderr_thread = threading.Thread(
                target=read_stream, args=(process.stderr, custom_write_error)
            )

            # Thread'leri başlat
            stdout_thread.start()
            stderr_thread.start()

            # Thread'lerin işlemi tamamlamasını bekle
            stdout_thread.join()
            stderr_thread.join()

            # İşlem sonucunu kontrol et
            process.wait()
            if process.returncode != 0:
                raise subprocess.CalledProcessError(process.returncode, command)
    except subprocess.CalledProcessError as e:
        # Komut hata ile sonuçlanırsa, hatayı yazdır
        custom_write_error(f"Komut hatası: {e}\n")
        return False
    return True


def update_repository(deneme_sayisi=0):
    # Mevcut çalışma dizinini sakla
    original_directory = os.getcwd()
    custom_write("Güncellemeler uygulanıyor...\n")
    readme_guncelle_komutu = f"python3 {README_OLUSTUR_PY}"
    # google form güncelle komutu
    google_form_guncelle_komutu = f"python3 {HOCA_ICERIKLERI_GUNCELLE_PY} && python3 {DERS_ICERIKLERI_GUNCELLE_PY}"
    # Git ve Python komutlarını sırayla çalıştır
    try:
        repo_yolu = os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        os.chdir(repo_yolu)
        stream = os.popen("git status")
        output = stream.read()
        if "nothing to commit, working tree clean" not in output:
            custom_write_error(
                "Dizinde değişiklikler var. Lütfen önce bu değişiklikleri commit yapın veya geri alın. Script durduruluyor.\n"
            )
            exit(1)

        if not execute_command("git fetch --all"):
            custom_write_error(
                "Fetch sırasında conflict oluştu, script durduruluyor.\n"
            )
            return
        if not execute_command("git reset --hard origin/main"):
            custom_write_error(
                "Reset sırasında conflict oluştu, script durduruluyor.\n"
            )
            return
        os.chdir(original_directory)
        if not execute_command(google_form_guncelle_komutu):
            custom_write_error(
                "Google form içerikleri güncellenirken hata oluştu, script durduruluyor.\n"
            )
            return
        os.chdir(BIR_UST_DIZIN)
        os.system(readme_guncelle_komutu)
        os.chdir(DOKUMANLAR_REPO_YOLU)
        if not execute_command("git add --all"):
            custom_write_error("Git add işlemi başarısız...\n")
            return
        if not execute_command('git commit -m "rutin readme güncellemesi (robot)"'):
            custom_write_error(
                "Git commit işlemi başarısız, muhtemelen herhangi bir dosya değişmedi...\n"
            )
            return
        if not execute_command("git push"):
            custom_write_error("Git push işlemi başarısız...\n")
            return
        custom_write(f"{deneme_sayisi}. güncelleme başarıyla uygulandı.\n")
        time.sleep(10)
    except Exception as e:
        # Hata oluşursa, hatayı yazdır ve e-posta gönder
        error_message = f"Script hatası: {e}\n"
        custom_write_error(error_message)
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
guncelleme_sayisi = 0
timeout = 180
div = 3
custom_write("Script çalışıyor...\n")
# Sonsuz döngü içinde URL'leri kontrol et ve güncelle
while True:
    for key, url in urls.items():
        if check_for_updates(key, url):
            custom_write(f"Güncelleme tespit edildi: {key}\n")
            guncelleme_sayisi += 1
            update_repository(guncelleme_sayisi)
        else:
            custom_write(f"Güncelleme yok: {key}\n")
    i += 1
    for k in range(0, int(timeout / div)):
        custom_write(
            f"{timeout-k*div} saniye sonra kontrol edilecek. Kontol sayısı {i}\n"
        )  # '\r' ile satırın başına dön
        time.sleep(div)
