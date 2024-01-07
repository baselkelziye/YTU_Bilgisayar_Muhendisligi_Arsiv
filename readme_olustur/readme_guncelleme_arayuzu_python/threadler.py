import subprocess
from PyQt5.QtCore import QThread, pyqtSignal
import json
import requests
class ScriptRunnerThread(QThread):
    finished = pyqtSignal()
    error = pyqtSignal(str)

    def __init__(self, paths):
        QThread.__init__(self)
        self.google_forum_islemleri_path, self.readme_olustur_path = paths

    def run(self):
        try:
            subprocess.run('python3 hoca_icerikleri_guncelle.py\n', shell=True, cwd=self.google_forum_islemleri_path, check=True)
            subprocess.run('python3 ders_icerikleri_guncelle.py\n', shell=True, cwd=self.google_forum_islemleri_path, check=True)
            subprocess.run('python3 readme_olustur.py\n', shell=True, cwd=self.readme_olustur_path, check=True)
            self.finished.emit()
        except subprocess.CalledProcessError as e:
            self.error.emit(str(e))
# Uzun süren işlemi gerçekleştirecek thread sınıfı
class HocaKaydetThread(QThread):
    finished = pyqtSignal()  # İşlem bittiğinde sinyal göndermek için
    error = pyqtSignal(str)  # Hata mesajı için sinyal
    def __init__(self, hoca, data, parent):
        super().__init__()
        self.hoca = hoca
        self.data = data
        self.parent = parent

    def run(self):
        ad = self.parent.adInput.text()
        if not ad:
            self.error.emit('Hoca adı boş olamaz!')
            return

        ofis = self.parent.ofisInput.text().strip()
        link = self.parent.linkInput.text().strip()
        erkek_mi = self.parent.erkekMiInput.currentText() == 'Evet'
        dersler = self.parent.secilenDersleriDondur()
        if link and not self.parent.check_url(link):
            self.error.emit('Güncelleme başarısız!!!')
            return  # Eğer URL geçerli değilse fonksiyondan çık
        if self.hoca:  # Düzenleme modunda
            self.hoca.update({
                "ad":self.parent.unvanInput.currentText() + " " + ad,
                "ofis": ofis,
                "link": link,
                "erkek_mi": erkek_mi,
                "dersler": dersler
            })
        else:  # Ekleme modunda
            yeni_hoca = {
                "ad":self.parent.unvanInput.currentText()+ " " + ad,
                "ofis": ofis,
                "link": link,
                "erkek_mi": erkek_mi,
                "dersler": dersler
            }
            self.data['hocalar'].append(yeni_hoca)
        self.finished.emit()

class KatkiEkleThread(QThread):
    finished = pyqtSignal(bool, str)  # İşlem sonucu ve mesaj için sinyal

    def __init__(self, ad, github_kullanici_adi, JSON_DOSYASI,parent=None):
        super(KatkiEkleThread, self).__init__(parent)
        self.ad = ad
        self.github_kullanici_adi = github_kullanici_adi
        self.github_url = f"https://github.com/{self.github_kullanici_adi}"
        self.JSON_DOSYASI = JSON_DOSYASI

    def run(self):
        try:
            # JSON dosyasını aç ve oku
            try:
                with open(self.JSON_DOSYASI, 'r+', encoding='utf-8') as file:
                    data = json.load(file)
            except FileNotFoundError:
                data = {"katkida_bulunanlar": []}
            if 'bolum_adi' not in data:
                data['bolum_adi'] = 'Katkıda Bulunanlar'
            if 'bolum_aciklamasi' not in data:
                data['bolum_aciklamasi'] = "Bu bölümde reponun hazırlanmasında katkıda bulunan insanlar listelenmiştir. Siz de katkıda bulunmak isterseniz bizimle iletişime geçin. Ya da merge request gönderin."
           
            if not self.ad or not self.github_kullanici_adi:
                self.finished.emit(False, 'Ad ve GitHub kullanıcı adı boş olamaz!')
                return
            # Kontrolleri gerçekleştir
            if any(kisi['ad'].lower() == self.ad.lower() for kisi in data['katkida_bulunanlar']):
                self.finished.emit(False, 'Bu isim zaten mevcut!')
            elif any(kisi['github_link'] == self.github_url for kisi in data['katkida_bulunanlar']):
                self.finished.emit(False, 'Bu GitHub linki zaten eklenmiş!')
            else:
                # GitHub URL'sinin varlığını kontrol et
                response = requests.get(self.github_url)
                if response.status_code == 404:
                    self.finished.emit(False, 'GitHub kullanıcı adı geçerli değil!')
                    return
                
                # Yeni veriyi ekle ve dosyayı güncelle
                data['katkida_bulunanlar'].append({"ad": self.ad, "github_link": self.github_url})
                with open(self.JSON_DOSYASI, 'w', encoding='utf-8') as file:
                    json.dump(data, file, ensure_ascii=False, indent=4)
                self.finished.emit(True, 'Katkıda bulunan eklendi!')
        except Exception as e:
            self.finished.emit(False, f'Bir hata oluştu: {e}')
class KatkiKaydetThread(QThread):
    finished = pyqtSignal(bool, str)  # İşlem sonucu ve mesaj için sinyal

    def __init__(self, kisi, ad, github_kullanici_adi, data, JSON_YOLU,parent=None):
        super(KatkiKaydetThread, self).__init__(parent)
        self.kisi = kisi
        self.ad = ad
        self.github_kullanici_adi = github_kullanici_adi
        self.data = data
        self.github_url = "https://github.com/" + self.github_kullanici_adi
        self.JSON_YOLU = JSON_YOLU

    def run(self):
        # GitHub linkinin varlığını kontrol et
        try:
            response = requests.get(self.github_url)
            if response.status_code == 404:
                self.finished.emit(False, 'GitHub linki geçerli değil!')
                return
        except requests.exceptions.RequestException as e:
            self.finished.emit(False, f'GitHub linki kontrol edilirken bir hata oluştu: {e}')
            return

        # Değişiklikleri uygula ve JSON dosyasını güncelle
        self.kisi['ad'] = self.ad
        self.kisi['github_link'] = self.github_url
        try:
            with open(self.JSON_YOLU, 'w', encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            self.finished.emit(True, 'Katkıda bulunan güncellendi!')
        except Exception as e:
            self.finished.emit(False, f'Dosya yazılırken bir hata oluştu: {e}')
class CMDScriptRunnerThread(QThread):
    finished = pyqtSignal(str)
    error = pyqtSignal(str)

    def __init__(self, cmd):
        super().__init__()
        self.cmd = cmd

    def run(self):
        try:
            print(f'Komut: {self.cmd}')
            process = subprocess.Popen(self.cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, 
                                           creationflags=subprocess.CREATE_NO_WINDOW)
            
            # Çıktıyı ve hataları gerçek zamanlı olarak oku ve yazdır
            while True:
                output_line = process.stdout.readline()
                if output_line:
                    print(output_line.strip())  # Çıktıyı konsola yazdır
                error_line = process.stderr.readline()
                if error_line:
                    print(error_line.strip())  # Hataları konsola yazdır

                # İşlem bittiğinde döngüden çık
                if output_line == '' and error_line == '' and process.poll() is not None:
                    break
            print("bitti")
            # İşlem sonucunu kontrol et
            if process.returncode != 0:
                # Tüm hataları birleştir ve sinyal gönder
                errors = process.stderr.read().strip()
                self.error.emit(errors)
            else:
                # Tüm çıktıları birleştir ve sinyal gönder
                output = process.stdout.read().strip()
                self.finished.emit(output)

        except Exception as e:
            self.error.emit(str(e))
