import subprocess
from PyQt6.QtCore import QThread, pyqtSignal
import json
import requests
from degiskenler import *
import subprocess
import threading
import queue


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

    def __init__(
        self,
        ad,
        kisi,
        iletisim_bilgileri,
        JSON_DOSYASI,
        katkida_bulunma_orani,
        data,
        parent=None,
    ):
        super(KatkiEkleThread, self).__init__(parent)
        self.ad = ad
        self.kisi = kisi
        self.data = data
        self.katkida_bulunma_orani = katkida_bulunma_orani
        self.iletisim_bilgileri = iletisim_bilgileri
        self.JSON_DOSYASI = JSON_DOSYASI

    def run(self):
        try:
            if BOLUM_ADI not in self.data:
                self.data[BOLUM_ADI] = "Katkıda Bulunanlar"
            if BOLUM_ACIKLAMASI not in self.data:
                self.data[BOLUM_ACIKLAMASI] = (
                    "Bu bölümde reponun hazırlanmasında katkıda bulunan insanlar listelenmiştir. Siz de katkıda bulunmak isterseniz bizimle iletişime geçin. Ya da merge request gönderin."
                )

            if not self.ad:
                self.finished.emit(False, "Ad kullanıcı adı boş olamaz!")
                return
            """
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
            else:"""
            # GitHub URL'sinin varlığını kontrol et
            for iletisim_bilgileri in self.iletisim_bilgileri[ILETISIM_BILGILERI]:
                link = iletisim_bilgileri.get(LINK, None)
                response = requests.get(link)
                if response.status_code == 404:
                    self.finished.emit(False, f"{link} linki geçerli değil!")
                    return

            # Değişiklikleri uygula ve JSON dosyasını güncelle
            if self.kisi is not None:
                self.kisi[AD] = self.ad
                self.kisi[ILETISIM_BILGILERI] = self.iletisim_bilgileri[
                    ILETISIM_BILGILERI
                ]
                self.kisi[KATKIDA_BULUNMA_ORANI] = self.katkida_bulunma_orani
                mesaj = "Katkıda bulunan güncellendi!"
            else:
                # Yeni veriyi ekle ve dosyayı güncelle
                self.data[KATKIDA_BULUNANLAR].append(
                    {
                        AD: self.ad,
                        ILETISIM_BILGILERI: self.iletisim_bilgileri[ILETISIM_BILGILERI],
                        KATKIDA_BULUNMA_ORANI: self.katkida_bulunma_orani,
                    }
                )
                mesaj = "Katkıda bulunan eklendi!"
            with open(self.JSON_DOSYASI, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            self.finished.emit(True, mesaj)
        except Exception as e:
            self.finished.emit(False, f"Bir hata oluştu: {e}")


def enqueue_output(out, queue):

    for line in iter(out.readline, ""):
        try:
            queue.put(line)
        except:
            queue.put("Çözümlenemeyen karakter kodlaması")
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
            encoding=default_encoding,
        )
        q_stdout = queue.Queue()
        q_stderr = queue.Queue()

        t_stdout = threading.Thread(
            target=enqueue_output, args=(process.stdout, q_stdout)
        )
        t_stderr = threading.Thread(
            target=enqueue_output, args=(process.stderr, q_stderr)
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
                    tmp_msj = q_stdout.get().strip()
                    if tmp_msj != "":
                        son_bilgi_mesaj = tmp_msj
                        self.info.emit(son_bilgi_mesaj)

                while not q_stderr.empty():
                    tmp_msj = q_stderr.get().strip()
                    if tmp_msj != "":
                        son_hata_mesaj = tmp_msj
                        self.info.emit(son_hata_mesaj)

                # Süreç durumu kontrol et.
                if process.poll() is not None:
                    break  # Süreç tamamlandı.

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


class PythonFunctionRunnerThread(QThread):
    """
    Python fonksiyonlarını subprocess yerine doğrudan çalıştıran thread.
    PyInstaller ile derlenmiş uygulamalarda kullanılmak üzere tasarlanmıştır.
    """
    finished = pyqtSignal(str)
    error = pyqtSignal(str)
    info = pyqtSignal(str)

    def __init__(self, functions, baslik=None):
        """
        Args:
            functions: Çalıştırılacak fonksiyonların listesi (callable veya tuple(callable, args, kwargs))
            baslik: Progress dialog için başlık
        """
        super().__init__()
        self.functions = functions if isinstance(functions, list) else [functions]
        self.calismaya_devam_et = True
        self.baslik = baslik

    def _emit_info(self, message):
        """custom_write callback'i - mesajları info sinyaline yönlendir."""
        if message:
            self.info.emit(message)

    def run(self):
        from cikti_yazdirma import set_progress_callback, clear_progress_callback
        
        son_bilgi_mesaj = ""
        try:
            # Callback'i ayarla - custom_write çağrıları artık info sinyaline gidecek
            set_progress_callback(self._emit_info)
            
            for func_item in self.functions:
                if not self.calismaya_devam_et:
                    mesaj = "İşlem kullanıcı tarafından iptal edildi."
                    self.error.emit(mesaj)
                    return

                # Fonksiyon bilgisini ayrıştır
                if callable(func_item):
                    func = func_item
                    args = ()
                    kwargs = {}
                elif isinstance(func_item, tuple):
                    func = func_item[0]
                    args = func_item[1] if len(func_item) > 1 else ()
                    kwargs = func_item[2] if len(func_item) > 2 else {}
                else:
                    self.error.emit(f"Geçersiz fonksiyon öğesi: {func_item}")
                    return

                # Fonksiyon adını kaydet (sonuç mesajı için)
                func_name = getattr(func, '__name__', str(func))
                son_bilgi_mesaj = f"{func_name} tamamlandı"

                # Fonksiyonu çalıştır (fonksiyon kendi progress mesajlarını gönderecek)
                func(*args, **kwargs)

            self.finished.emit(f"İşlem başarıyla tamamlandı.\n{son_bilgi_mesaj}")

        except SystemExit as e:
            # SystemExit'i yakala (exit(1) çağrıları için)
            if e.code != 0:
                self.error.emit(f"İşlem hata ile sonlandı (kod: {e.code})")
            else:
                self.finished.emit(f"İşlem başarıyla tamamlandı.\n{son_bilgi_mesaj}")
        except Exception as e:
            self.error.emit(f"Hata oluştu: {str(e)}")
        finally:
            # Callback'i temizle
            clear_progress_callback()

    def durdur(self):
        from cikti_yazdirma import request_stop
        self.calismaya_devam_et = False
        request_stop()  # Uzun süren fonksiyonların kontrol edebileceği global flag


