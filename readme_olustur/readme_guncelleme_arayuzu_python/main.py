import sys
import subprocess
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout,QMessageBox
from katkida_bulunanlari_duzenle_window import KatkidaBulunanGuncelleWindow
from yazarin_notlari_duzenle_window import YazarinNotlariWindow
from hoca_ekle_guncelle_window import HocaEkleGuncelleWindow
class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 Butonlar'
        self.left = 100
        self.top = 100
        self.width = 320
        self.height = 200
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        layout = QVBoxLayout()

        # Butonları oluştur
        self.buttons = [
            QPushButton('Katkıda Bulunan Ekle/Güncelle'),
            QPushButton('Yazarın Notları Ekle/Güncelle'),
            QPushButton('Hoca Ekle/Güncelle'),
            QPushButton('Ders Ekle/Güncelle'),
            QPushButton('Readme Scripti Çalıştır')
        ]
        # Her butona tıklama işleyicisi ekle
        self.buttons[0].clicked.connect(self.acKatkidaBulunanEkleGuncelle)
        self.buttons[1].clicked.connect(self.acYazarinNotlari)
        self.buttons[2].clicked.connect(self.acHocaEkleGuncelle)
        self.buttons[4].clicked.connect(self.readmeScriptiCalistir)
        # Butonları pencereye ekle
        for btn in self.buttons:
            layout.addWidget(btn)

        # Layout'u ayarla
        self.setLayout(layout)
        self.show()
    def acKatkidaBulunanEkleGuncelle(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.katkidaBulunanGuncelleWindow = KatkidaBulunanGuncelleWindow()
        self.katkidaBulunanGuncelleWindow.show()
    def acYazarinNotlari(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.yazarinNotlariWindow = YazarinNotlariWindow()
        self.yazarinNotlariWindow.show()
    def acHocaEkleGuncelle(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.hocaEkleGuncelleWindow = HocaEkleGuncelleWindow()
        self.hocaEkleGuncelleWindow.show()

    def readmeScriptiCalistir(self):
        try:
            # Dizin yollarını belirleyin
            google_forum_islemleri_path = '../google_forum_islemleri'
            readme_olustur_path = '..'

            # Python script'lerini çalıştırın
            subprocess.run('python3 hoca_icerikleri_guncelle.py\n', shell=True, cwd=google_forum_islemleri_path)
            subprocess.run('python3 ders_icerikleri_guncelle.py\n', shell=True, cwd=google_forum_islemleri_path)
            subprocess.run('python3 readme_olustur.py\n', shell=True, cwd=readme_olustur_path)

            # İşlem tamamlandığında kullanıcıya bilgi ver
            QMessageBox.information(self, 'Başarılı', 'README.md dosyaları güncellendi!')

        except subprocess.CalledProcessError as e:
            # Hata oluşursa kullanıcıya hata mesajı göster
            QMessageBox.critical(self, 'Hata', f'Bir hata oluştu: {e}')



if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())
