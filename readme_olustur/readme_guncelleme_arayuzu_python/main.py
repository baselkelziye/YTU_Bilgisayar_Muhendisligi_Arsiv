import sys
from PyQt5.QtWidgets import QApplication,QDesktopWidget, QWidget, QPushButton, QVBoxLayout, QMessageBox
from PyQt5.QtGui import QIcon
from katkida_bulunanlari_duzenle_window import KatkidaBulunanGuncelleWindow
from yazarin_notlari_duzenle_window import YazarinNotlariWindow
from ders_ekle_guncelle_window import DersEkleGuncelleWindow
from hoca_ekle_guncelle_window import HocaEkleGuncelleWindow
from progress_dialog import CustomProgressDialog
from degiskenler import SELCUKLU_ICO_PATH
from repo_kullanimi_window import RepoKullanimiDialog
from giris_ekle_guncelle_window import GirisEkleGuncelleWindow
from donem_ekle_guncelle_window import DonemEkleGuncelleWindow
from git_islemleri_window import GitIslemleriWindow
import os
class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'Readme Düzenleyici'
        self.width = 540
        self.height = 200
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))


    def initUI(self):
        self.setWindowTitle(self.title)
        self.resize(self.width, self.height)
        layout = QVBoxLayout()
        # Butonları oluştur
        self.buttons = [
            QPushButton('Giriş Güncelle'),
            QPushButton('Dönem Ekle/Güncelle'),
            QPushButton('Katkıda Bulunan Ekle/Güncelle'),
            QPushButton('Yazarın Notları Ekle/Güncelle'),
            QPushButton('Hoca Ekle/Güncelle'),
            QPushButton('Ders Ekle/Güncelle'),
            QPushButton('Repo Kullanımı Düzenle'),
            QPushButton('Git İşlemleri'),
        ]
        # Her düğme için farklı bir renk ayarla
        colors = ['#FF5733', '#33FF57', '#3357FF', '#F333FF', '#FFFF33', '#FF5733', '#33FF3F','#33FFF3']
        for button, color in zip(self.buttons, colors):
            button.setStyleSheet(f'background-color: {color};')
        self.progressDialog = CustomProgressDialog('README.md dosyaları güncelleniyor...', self)
        self.progressDialog.close()
        # Her butona tıklama işleyicisi ekle
        self.buttons[0].clicked.connect(self.acGirisEkleGuncelle)
        self.buttons[1].clicked.connect(self.acDonemEkleGuncelle)
        self.buttons[2].clicked.connect(self.acKatkidaBulunanEkleGuncelle)
        self.buttons[3].clicked.connect(self.acYazarinNotlari)
        self.buttons[4].clicked.connect(self.acHocaEkleGuncelle)
        self.buttons[5].clicked.connect(self.acDersEkleGuncelle)
        self.buttons[6].clicked.connect(self.repoKullanimiDuzenle)
        self.buttons[7].clicked.connect(self.gitIslemleri)
        # Butonları pencereye ekle
        for btn in self.buttons:
            layout.addWidget(btn)

        # Layout'u ayarla
        self.setLayout(layout)
        self.show()
        self.center()
    def acDonemEkleGuncelle(self):
        # Dönem Ekle/Güncelle penceresini aç
        self.donemEkleGuncelleWindow = DonemEkleGuncelleWindow()
        self.donemEkleGuncelleWindow.show()
    def repoKullanimiDuzenle(self):
        self.repoKullanimiGuncelleWindow = RepoKullanimiDialog()
        self.repoKullanimiGuncelleWindow.show()
    def acGirisEkleGuncelle(self):
        # Giriş Güncelle penceresini aç
        self.girisEkleGuncelleWindow = GirisEkleGuncelleWindow()
        self.girisEkleGuncelleWindow.show()
    def center(self):
        # Pencereyi ekranın ortasına al
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())
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
    def acDersEkleGuncelle(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.dersEkleGuncelleWindow = DersEkleGuncelleWindow()
        self.dersEkleGuncelleWindow.show()

    def gitIslemleri(self):
        self.gitIslemleriWindow = GitIslemleriWindow()
        self.gitIslemleriWindow.show()
    def onFinished(self):
        self.progressDialog.close()
        QMessageBox.information(self, 'Başarılı', 'README.md dosyaları güncellendi!')

    def onError(self, message):
        self.progressDialog.close()
        QMessageBox.critical(self, 'Hata', f'Bir hata oluştu: {message}')


if __name__ == '__main__':
        # Çalıştırılabilir dosyanın yolunu ve dizinini belirle
    if getattr(sys, 'frozen', False):
        # PyInstaller tarafından oluşturulmuş bir çalıştırılabilir dosya çalışıyorsa
        application_path = os.path.dirname(sys.executable)
        application_path = os.path.join(application_path, "..")
        os.chdir(application_path)

    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())
