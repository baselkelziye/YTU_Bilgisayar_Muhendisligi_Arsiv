import sys
from typing import Callable
from PyQt6.QtWidgets import (
    QApplication,
    QWidget,
    QPushButton,
    QVBoxLayout,
    QMessageBox,
    QHBoxLayout,
    QLabel,
    QSpacerItem,
    QSizePolicy,
)
from PyQt6.QtGui import QIcon, QGuiApplication
from katkida_bulunanlari_duzenle_window import KatkidaBulunanGuncelleWindow
from yazarin_notlari_duzenle_window import YazarinNotlariWindow
from ders_ekle_guncelle_window import DersEkleGuncelleWindow
from hoca_ekle_guncelle_window import HocaEkleGuncelleWindow
from helpers.progress_dialog_helper import CustomProgressDialog
from degiskenler import (
    _MODULE_DIR, STIL_QSS, SELCUKLU_ICO_PATH, KONFIGURASYON_JSON_PATH
)
from degiskenler import *
from repo_kullanimi_window import RepoKullanimiDialog
from giris_ekle_guncelle_window import GirisEkleGuncelleWindow
from donem_ekle_guncelle_window import DonemEkleGuncelleWindow
from git_islemleri_window import GitIslemleriWindow
from konfigurasyon_json_kontrol import konfigurasyon_json_guncelle
import os
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
from konfigurasyon_window import KonfigurasyonDialog
from surum_yonetimi import VERSION



class MenuButton(QPushButton):
    """
    Ana menü için özelleştirilmiş buton sınıfı.
    Hem veriyi tutar hem de görselleştirme (buton) mantığını encapsule eder.
    """
    def __init__(self, text: str, color: str, function: Callable):
        super().__init__(text)
        
        # Buton stil ve fonksiyon atamaları
        self.setStyleSheet(color)
        self.clicked.connect(function)


class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = "Readme Düzenleyici"
        self.width = 540
        self.height = 200
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle(self.title)
        self.resize(self.width, self.height)
        layout = QVBoxLayout()
        
        # Version Info (Top Right)
        top_layout = QHBoxLayout()
        top_layout.addItem(
            QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)
        )
        version_label = QLabel(f"Sürüm: {VERSION}")
        version_label.setObjectName("versionLabel")
        top_layout.addWidget(version_label)
        layout.addLayout(top_layout)

        # Butonları oluştur
        self.buttons = [
            MenuButton("Giriş Güncelle", "background-color: #C0392B; color: white;", self.acGirisEkleGuncelle),
            MenuButton("Repo Kullanımı Düzenle", "background-color: #27AE60; color: white;", self.repoKullanimiDuzenle),
            MenuButton("Maaş İstatistikleri Düzenle", "background-color: #007BFF; color: white;", self.maasIstatistikleriDuzenle),
            MenuButton("Ders Ekle/Güncelle", "background-color: #2980B9; color: white;", self.acDersEkleGuncelle),
            MenuButton("Hoca Ekle/Güncelle", "background-color: #8E44AD; color: white;", self.acHocaEkleGuncelle),
            MenuButton("Yazarın Notları Ekle/Güncelle", "background-color: #F39C12; color: white;", self.acYazarinNotlari),
            MenuButton("Katkıda Bulunan Ekle/Güncelle", "background-color: #D35400; color: white;", self.acKatkidaBulunanEkleGuncelle),
            MenuButton("Dönem Ekle/Güncelle", "background-color: #16A085; color: white;", self.acDonemEkleGuncelle),
            MenuButton("Konfigürasyon Düzenle", "background-color: #9B59B6; color: white;", self.acKonfigurasyonDuzenle),
            MenuButton("Git İşlemleri", "background-color: #2C3E50; color: white;", self.gitIslemleri),
        ]

        self.progressDialog = CustomProgressDialog(
            "README.md dosyaları güncelleniyor...", self
        )
        self.progressDialog.close()

        # Butonları pencereye ekle
        for btn in self.buttons:
            layout.addWidget(btn)

        # Layout'u ayarla
        self.setLayout(layout)
        self.show()
        self.center()

    def acDonemEkleGuncelle(self):
        # Dönem Ekle/Güncelle penceresini aç
        self.donemEkleGuncelleWindow = DonemEkleGuncelleWindow(parent=self)
        self.donemEkleGuncelleWindow.show()

    def acKonfigurasyonDuzenle(self):
        # Dönem Ekle/Güncelle penceresini aç
        self.konfigurasyonDialog = KonfigurasyonDialog(parent=self)
        self.konfigurasyonDialog.show()

    def maasIstatistikleriDuzenle(self):
        if os.path.exists(MAAS_ISTATISTIKLERI_TXT_PATH):
            with open(MAAS_ISTATISTIKLERI_TXT_PATH, "r", encoding="utf-8") as dosya:
                icerik = dosya.read()
        else:
            icerik = ""
        yeni_icerik, ok = SatirAtlayanInputDialog.getMultiLineText(
            self,
            "Maaş İstatistikleri",
            "Maaş İstatistikleri Düzenleme",
            icerik,
            width=900,
            height=700,
        )
        if ok and icerik != yeni_icerik:
            # Yeni içeriği dosyaya yaz
            with open(MAAS_ISTATISTIKLERI_TXT_PATH, "w", encoding="utf-8") as dosya:
                dosya.write(yeni_icerik)
            QMessageBox.information(
                self, "Başarılı", "Maaş İstatistikleri güncellendi."
            )

    def repoKullanimiDuzenle(self):
        self.repoKullanimiGuncelleWindow = RepoKullanimiDialog(parent=self)
        self.repoKullanimiGuncelleWindow.show()

    def acGirisEkleGuncelle(self):
        # Giriş Güncelle penceresini aç
        self.girisEkleGuncelleWindow = GirisEkleGuncelleWindow(parent=self)
        self.girisEkleGuncelleWindow.show()

    def center(self):
        # Pencereyi ekranın ortasına al
        qr = self.frameGeometry()
        cp = QGuiApplication.instance().primaryScreen().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def acKatkidaBulunanEkleGuncelle(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.katkidaBulunanGuncelleWindow = KatkidaBulunanGuncelleWindow(parent=self)
        self.katkidaBulunanGuncelleWindow.show()

    def acYazarinNotlari(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.yazarinNotlariWindow = YazarinNotlariWindow(parent=self)
        self.yazarinNotlariWindow.show()

    def acHocaEkleGuncelle(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.hocaEkleGuncelleWindow = HocaEkleGuncelleWindow(parent=self)
        self.hocaEkleGuncelleWindow.show()

    def acDersEkleGuncelle(self):
        # Katkıda Bulunan Güncelle penceresini aç
        self.dersEkleGuncelleWindow = DersEkleGuncelleWindow(parent=self)
        self.dersEkleGuncelleWindow.show()

    def gitIslemleri(self):
        self.gitIslemleriWindow = GitIslemleriWindow(parent=self)
        self.gitIslemleriWindow.show()

    def onFinished(self):
        self.progressDialog.close()

    def onError(self, message):
        self.progressDialog.close()
        QMessageBox.critical(self, "Hata", f"Bir hata oluştu: {message}")


def main():
    """Ana uygulama giriş noktası."""
    # Çalıştırılabilir dosyanın yolunu ve dizinini belirle
    if getattr(sys, "frozen", False):
        # PyInstaller tarafından oluşturulmuş bir çalıştırılabilir dosya çalışıyorsa
        application_path = os.path.dirname(sys.executable)
        # Artık main, kök dizinde olduğu için bir üst dizine çıkmaya gerek yok
        os.chdir(application_path)
    konfigurasyon_json_guncelle(KONFIGURASYON_JSON_PATH)
    app = QApplication(sys.argv)
    # Stil dosyasını oku
    try:
        stil_yolu = os.path.join(_MODULE_DIR, STIL_QSS) if getattr(sys, 'frozen', False) else STIL_QSS
        with open(stil_yolu, "r", encoding="utf-8") as f:
            _style = f.read()
            app.setStyleSheet(_style)
    except:
        pass
    ex = App()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
