import requests
import hashlib
import os
import subprocess
import time
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

def send_anonymous_email(subject, message, to_email):
    # E-posta içeriğini ayarla
    msg = MIMEText(message)
    msg['Subject'] = subject
    msg['From'] = 'anonymous@example.com'
    msg['To'] = to_email

    # SMTP sunucusuna bağlan (örnek olarak smtp.example.com)
    server = smtplib.SMTP('smtp.example.com', 25)  # 25 genellikle anonim SMTP için kullanılan porttur.
    server.ehlo()
    
    # E-postayı gönder
    server.sendmail('anonymous@example.com', [to_email], msg.as_string())
    
    # Bağlantıyı kapat
    server.close()
def send_error_email(error_message):
    receiver_email = "kayrabulut39@gmail.com"

    # E-posta gövdesini oluştur
    text = f"""\
    Merhaba,
    Bir hata oluştu:
    {error_message}
    """
    send_anonymous_email("Hata oluştu", text, receiver_email)
def check_for_updates(url):
    # Belirtilen URL'den .csv dosyasını indir
    response = requests.get(url)
    data = response.text
    
    # İndirilen verinin hash değerini hesapla
    current_hash = hashlib.md5(data.encode()).hexdigest()
    
    # Eğer bu URL daha önce kontrol edildiyse ve hash değeri değişmişse, güncelleme olduğunu bildir
    if url in previous_hashes and previous_hashes[url] != current_hash:
        print(f"Değişiklik bulundu: {url}")
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
        if not execute_command("git fetch"):
            return
        if not execute_command("git clean -fdx"):
            return
        if not execute_command("python3 hoca_icerikleri_guncelle.py"):
            return
        if not execute_command("python3 ders_icerikleri_guncelle.py"):
            return 
        os.chdir("..")
        if not execute_command("python3 readme_olustur.py"):
            return
        if not execute_command("git add --all"):
         return
        if not execute_command('git commit -m "rutin readme güncellemesi (robot)"'):
            return
        if not execute_command("git push"):
            return
    except Exception as e:
        # Hata oluşursa, hatayı yazdır ve e-posta gönder
        error_message = f"Script hatası: {e}"
        print(error_message)
        send_error_email(error_message)
    finally:
        # Başlangıç dizinine geri dön, hata olsa bile
        os.chdir(original_directory)

# URL'leri kontrol et
urls = [
    "https://docs.google.com/spreadsheets/d/1w386auUiJaGwoUAmmkEgDtIRSeUplmDz0AZkM09xPTk/export?format=csv",
    "https://docs.google.com/spreadsheets/d/1mexaMdOeB-hWLVP4MI_xmnKwGBuwoRDk6gY9zXDycyI/export?format=csv",
    "https://docs.google.com/spreadsheets/d/e/2PACX-1vSDFicOFbJu9Fnc4Hl0mFuuaC0L4PiEmUFkkJrgocwWGWs1wB3TyN1zd4okW8svC6IT2HMIe64NQUUy/pub?output=csv",
    "https://docs.google.com/spreadsheets/d/e/2PACX-1vQvGyGLQxobIpaVdQItSpqEoiwJ0DIIHE9kVvCHhfKQ7yYR16c2tI_ix4Z9d2tA4aLt2c4fTLGxlL-s/pub?output=csv"
]
# Dosyaların eski hash değerlerini saklamak için bir sözlük
previous_hashes = {}
i = 0
update_repository()
print("Script çalışıyor...")
# Sonsuz döngü içinde URL'leri kontrol et ve güncelle
while True:
    for url in urls:
        if check_for_updates(url):
            print(f"Güncelleme tespit edildi: {url}")
            update_repository()
        else:
            print(f"Güncelleme yok: {url}")
    i += 1
    print(f"{i}. kontrol tamamlandı.")
    for k in range(0, 1):
        print(f"{180-k} saniye sonra kontrol edilecek.")
        time.sleep(3)