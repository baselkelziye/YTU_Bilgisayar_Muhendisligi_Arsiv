import subprocess
from PyQt5.QtCore import QThread, pyqtSignal
import json
import requests
import select
from degiskenler import *
import subprocess
import threading
import queue
import sys


class ScriptRunnerThread(QThread):
    finished = pyqtSignal()
    error = pyqtSignal(str)

    def __init__(self, paths):
        QThread.__init__(self)
        self.google_forum_islemleri_path, self.readme_olustur_path = paths

    def run(self):
        try:
            subprocess.run(
                "python3 hoca_icerikleri_guncelle.py\n",
                shell=True,
                cwd=self.google_forum_islemleri_path,
                check=True,
            )
            subprocess.run(
                "python3 ders_icerikleri_guncelle.py\n",
                shell=True,
                cwd=self.google_forum_islemleri_path,
                check=True,
            )
            subprocess.run(
                "python3 readme_olustur.py\n",
                shell=True,
                cwd=self.readme_olustur_path,
                check=True,
            )
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
            self.error.emit("Hoca adı boş olamaz!")
            return

        ofis = self.parent.ofisInput.text().strip()
        link = self.parent.linkInput.text().strip()
        erkek_mi = self.parent.erkekMiInput.currentText() == "Evet"
        dersler = self.parent.secilenDersleriDondur()
        hoca_aktif_gorevde_mi = self.parent.aktifGorevdeInput.currentText() == "Evet"
        if link and not self.parent.check_url(link):
            self.error.emit("Güncelleme başarısız!!!")
            return  # Eğer URL geçerli değilse fonksiyondan çık
        if self.hoca:  # Düzenleme modunda
            self.hoca.update(
                {
                    AD: self.parent.unvanInput.currentText() + " " + ad,
                    OFIS: ofis,
                    LINK: link,
                    ERKEK_MI: erkek_mi,
                    DERSLER: dersler,
                    HOCA_AKTIF_GOREVDE_MI: hoca_aktif_gorevde_mi,
                }
            )
        else:  # Ekleme modunda
            yeni_hoca = {
                AD: self.parent.unvanInput.currentText() + " " + ad,
                OFIS: ofis,
                LINK: link,
                ERKEK_MI: erkek_mi,
                DERSLER: dersler,
                HOCA_AKTIF_GOREVDE_MI: hoca_aktif_gorevde_mi,
            }
            self.data[HOCALAR].append(yeni_hoca)
        self.finished.emit()


class KatkiEkleThread(QThread):
    finished = pyqtSignal(bool, str)  # İşlem sonucu ve mesaj için sinyal

    def __init__(self, ad, github_kullanici_adi, JSON_DOSYASI, parent=None):
        super(KatkiEkleThread, self).__init__(parent)
        self.ad = ad
        self.github_kullanici_adi = github_kullanici_adi
        self.github_url = f"https://github.com/{self.github_kullanici_adi}"
        self.JSON_DOSYASI = JSON_DOSYASI

    def run(self):
        try:
            # JSON dosyasını aç ve oku
            try:
                with open(self.JSON_DOSYASI, "r+", encoding="utf-8") as file:
                    data = json.load(file)
            except FileNotFoundError:
                data = {KATKIDA_BULUNANLAR: []}
            if BOLUM_ADI not in data:
                data[BOLUM_ADI] = "Katkıda Bulunanlar"
            if BOLUM_ACIKLAMASI not in data:
                data[
                    BOLUM_ACIKLAMASI
                ] = "Bu bölümde reponun hazırlanmasında katkıda bulunan insanlar listelenmiştir. Siz de katkıda bulunmak isterseniz bizimle iletişime geçin. Ya da merge request gönderin."

            if not self.ad or not self.github_kullanici_adi:
                self.finished.emit(False, "Ad ve GitHub kullanıcı adı boş olamaz!")
                return
            # Kontrolleri gerçekleştir
            if any(
                kisi[AD].lower() == self.ad.lower() for kisi in data[KATKIDA_BULUNANLAR]
            ):
                self.finished.emit(False, "Bu isim zaten mevcut!")
            elif any(
                kisi[GITHUB_LINK] == self.github_url
                for kisi in data[KATKIDA_BULUNANLAR]
            ):
                self.finished.emit(False, "Bu GitHub linki zaten eklenmiş!")
            else:
                # GitHub URL'sinin varlığını kontrol et
                response = requests.get(self.github_url)
                if response.status_code == 404:
                    self.finished.emit(False, "GitHub kullanıcı adı geçerli değil!")
                    return

                # Yeni veriyi ekle ve dosyayı güncelle
                data[KATKIDA_BULUNANLAR].append(
                    {AD: self.ad, GITHUB_LINK: self.github_url}
                )
                with open(self.JSON_DOSYASI, "w", encoding="utf-8") as file:
                    json.dump(data, file, ensure_ascii=False, indent=4)
                self.finished.emit(True, "Katkıda bulunan eklendi!")
        except Exception as e:
            self.finished.emit(False, f"Bir hata oluştu: {e}")


class KatkiKaydetThread(QThread):
    finished = pyqtSignal(bool, str)  # İşlem sonucu ve mesaj için sinyal

    def __init__(self, kisi, ad, github_kullanici_adi, data, JSON_YOLU, parent=None):
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
                self.finished.emit(False, "GitHub linki geçerli değil!")
                return
        except requests.exceptions.RequestException as e:
            self.finished.emit(
                False, f"GitHub linki kontrol edilirken bir hata oluştu: {e}"
            )
            return

        # Değişiklikleri uygula ve JSON dosyasını güncelle
        self.kisi[AD] = self.ad
        self.kisi[GITHUB_LINK] = self.github_url
        try:
            with open(self.JSON_YOLU, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            self.finished.emit(True, "Katkıda bulunan güncellendi!")
        except Exception as e:
            self.finished.emit(False, f"Dosya yazılırken bir hata oluştu: {e}")


def enqueue_output(out, queue, run_flag):
    while run_flag.is_set():
        line = out.readline()
        if line:
            queue.put(line)
        else:
            break
    out.close()


class CMDScriptRunnerThread(QThread):
    finished = pyqtSignal(str)
    error = pyqtSignal(str)
    info = pyqtSignal(str)

    def __init__(self, cmd, baslik=None):
        super().__init__()
        self.cmd = cmd
        self.calismaya_devam_et = True
        self.baslik = baslik

    def run(self):
        son_hata_mesaj = ""
        son_bilgi_mesaj = ""
        process = subprocess.Popen(
            self.cmd,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            encoding="utf-8",  # UTF-8 encoding ekledik.
        )
        q_stdout = queue.Queue()
        q_stderr = queue.Queue()

        run_flag = threading.Event()
        run_flag.set()

        t_stdout = threading.Thread(
            target=enqueue_output, args=(process.stdout, q_stdout, run_flag)
        )
        t_stderr = threading.Thread(
            target=enqueue_output, args=(process.stderr, q_stderr, run_flag)
        )

        t_stdout.start()
        t_stderr.start()

        try:
            while True:
                if not self.calismaya_devam_et:
                    mesaj = "İşlem kullanıcı tarafından iptal edildi."
                    bilgi = mesaj if self.baslik is None else f"{self.baslik}\n{mesaj}"
                    # Süreci durdur
                    process.terminate()  # ya da process.kill() kullanılabilir
                    self.error.emit(bilgi)
                    return

                # stdout ve stderr kuyruklarını kontrol et.
                while not q_stdout.empty():
                    son_bilgi_mesaj = q_stdout.get().strip()
                    self.info.emit(son_bilgi_mesaj)

                while not q_stderr.empty():
                    son_hata_mesaj = q_stderr.get().strip()
                    self.error.emit(son_hata_mesaj)

                # Süreç durumu kontrol et.
                if process.poll() is not None:
                    break  # Süreç tamamlandı.
            run_flag.clear()  # Bu, thread'lerin döngüsünü sonlandıracak.
            # Sürecin tamamlandığını ve thread'lerin sonlanmasını bekle
            t_stdout.join()
            t_stderr.join()

            # İşlem tamamlandığında çıkış kodunu kontrol et
            if process.returncode == 0:
                self.finished.emit(
                    f"İşlem başarıyla tamamlandı.\nSon Mesaj: {son_bilgi_mesaj}"
                )
            else:
                # stderr'den hata mesajlarını oku ve emit et
                if son_hata_mesaj == "":
                    son_hata_mesaj = son_bilgi_mesaj
                self.error.emit(
                    f"Komut başarısız oldu, çıkış kodu: {process.returncode}, Hata: {son_hata_mesaj}"
                )
        except Exception as e:
            self.error.emit(f"Hata oluştu: {str(e)}")

    def durdur(self):
        self.calismaya_devam_et = False
