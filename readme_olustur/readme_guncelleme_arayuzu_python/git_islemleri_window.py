import sys
import os
import textwrap
from PyQt6.QtWidgets import (
    QDialog,
    QVBoxLayout,
    QPushButton,
    QMessageBox,
)
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
from degiskenler import *
from progress_dialog import CustomProgressDialogWithCancel
from threadler import CMDScriptRunnerThread
from PyQt6.QtGui import QIcon
from hoca_ve_ders_adlari_window import HocaDersAdlariWindow


class GitIslemleriWindow(QDialog):
    def __init__(self, parent=None):
        super(GitIslemleriWindow, self).__init__(parent)
        self.setModal(True)
        self.setWindowTitle("Git İşlemleri")
        self.setMinimumSize(300, 200)
        # Dialog layout
        self.layout = QVBoxLayout()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

        # Butonlar ve renkler
        self.buttons = [
            QPushButton("Google Form Güncelle"),
            QPushButton("Readme Güncelle"),
            QPushButton("Arayüz Kodlarını Güncelle"),
            QPushButton("Dosya Değişikliklerini Github'dan Çek"),
            QPushButton("Rutin Kontrolü Başlat"),
            QPushButton("Hoca/Ders Adlarını Al (Google Form'a Kopyalamak İçin)"),
            QPushButton("Değişiklikleri Github'a Pushla"),
        ]

        self.colors = [
            "background-color: #C0392B; color: white;",  # Kırmızı
            "background-color: #27AE60; color: white;",  # Yeşil
            "background-color: #1ABC9C; color: white;",  # Açık Mavi/Turkuaz
            "background-color: #F1C40F; color: black;",  # Sarı
            "background-color: #FF69B4; color: white;",  # Pembe
            "background-color: #8E44AD; color: white;",  # Mor
            "background-color: #3498DB; color: white;",  # Mavi
        ]

        # Buton fonksiyonları
        self.functions = [
            self.update_google_form,
            self.update_readme,
            self.update_interface,
            self.update_dosyalar_repo,
            self.start_routine_check,
            self.hoca_ders_adlari_ac,
            self.push_changes,
        ]
        # Butonları dialog'a ekleme, renklendirme ve bağlama
        for btn, color, func in zip(self.buttons, self.colors, self.functions):
            btn.setStyleSheet(color)
            self.layout.addWidget(btn)
            btn.clicked.connect(func)

        self.setLayout(self.layout)

        # İşletim sistemi kontrolü
        self.is_windows = sys.platform.startswith("win")

    def hoca_ders_adlari_ac(self):
        hoca_ders_adlari_window = HocaDersAdlariWindow(self)
        hoca_ders_adlari_window.exec()

    def run_script(self, script_path, baslik, islem="", dizin=BIR_UST_DIZIN):
        cevap = QMessageBox.question(
            self,
            "Onay",
            f"{islem} işlemini başlatmak istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if cevap == QMessageBox.StandardButton.No:
            QMessageBox.information(self, "İptal", "İşlem iptal edildi.")
            return
        self.original_dir = os.getcwd()
        os.chdir(dizin)
        self.progress_dialog = CustomProgressDialogWithCancel(
            baslik, self, self.thread_durduruluyor
        )
        # Thread'i başlat
        self.thread = CMDScriptRunnerThread(script_path, islem)
        if script_path == "git fetch --all && git reset --hard origin/main":
            self.thread.finished.connect(self.interface_updated_succesfully)
        else:
            self.thread.finished.connect(self.on_finished)
        self.thread.error.connect(self.on_error)
        self.thread.info.connect(self.info)
        self.thread.start()
        self.progress_dialog.show()

    def thread_durduruluyor(self):
        cevap = QMessageBox.question(
            self,
            "Onay",
            f"İşlemi durdurmak istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if cevap == QMessageBox.StandardButton.No:
            return
        self.progress_dialog.setLabelText("İşlem durduruluyor...")
        self.progress_dialog.setCancelButton(None)
        self.thread.durdur()

    def on_finished(self, output):
        self.progress_dialog.close()
        self.thread.wait()
        del self.thread
        del self.progress_dialog
        QMessageBox.information(self, "Başarılı", output)
        os.chdir(self.original_dir)

    def on_error(self, errors):
        self.progress_dialog.close()
        self.thread.quit()
        del self.thread
        del self.progress_dialog
        QMessageBox.critical(self, "Hata", errors)
        os.chdir(self.original_dir)

    def info(self, message, maxlen=35):
        # Mesajı belirli bir uzunlukta parçalara ayır, kelimeleri tam böl
        wrapped_message = textwrap.fill(message, maxlen)

        # Güncellenmiş mesajı etiket metni olarak ayarla
        self.progress_dialog.setLabelText(wrapped_message)

    def update_google_form(self):
        komut = f"python3 {HOCA_ICERIKLERI_GUNCELLE_PY}"
        komut += f" && python3 {DERS_ICERIKLERI_GUNCELLE_PY}"
        yol = os.path.join(BIR_UST_DIZIN, GOOGLE_FORM_ISLEMLERI)
        self.run_script(
            komut,
            baslik="Google Form Güncelleniyor...",
            islem="Google Form Güncelleme",
            dizin=yol,
        )

    def update_readme(self):
        # bir üst dizine geçip python3 readme_olustur.py çalışıp geri ana dizzine gelcez
        komut = f"python3 {README_OLUSTUR_PY}"
        yol = BIR_UST_DIZIN
        # workind dir değişecek
        self.run_script(
            komut,
            baslik="README.md Güncelleniyor...",
            islem="README.md Güncelleme",
            dizin=yol,
        )

    def push_changes(self):
        commit_mesaji, ok_pressed = SatirAtlayanInputDialog.getMultiLineText(
            self, "Commit Mesajı", "Lütfen commit mesajını giriniz:"
        )
        if not ok_pressed:
            QMessageBox.information(self, "İptal", "İşlem iptal edildi.")
            return
        if not commit_mesaji:
            QMessageBox.critical(self, "Hata", "Lütfen commit mesajını giriniz.")
            return
        # burada git -C komtutu çalışacak önce git reposu mu diye kontrol edilecek
        komut = f"git -C {DOKUMANLAR_REPO_YOLU} add --all"
        komut = komut + f' && git -C {DOKUMANLAR_REPO_YOLU} commit -m "{commit_mesaji}"'
        komut = komut + f" && git -C {DOKUMANLAR_REPO_YOLU} push"
        self.run_script(
            komut,
            baslik="Dosya Değişiklikleri Github'a Pushlanıyor...",
            islem="Dosya Değişikliklerini Github'a Pushlama",
        )

    def update_dosyalar_repo(self):
        if not self.git_degisiklik_kontrol(
            os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        ):
            QMessageBox.critical(
                None,
                "Hata",
                "Dizinde değişiklikler var. Lütfen önce bu değişiklikleri commit yapın veya geri alın.",
            )
            return
        komut = f"git -C {DOKUMANLAR_REPO_YOLU} pull"
        self.run_script(
            komut,
            baslik="Dosya Değişiklikleri Github'dan Çekiliyor...",
            islem="Dosya Değişikliklerini Github'dan Çekme",
        )

    def update_interface(self):
        if not self.git_degisiklik_kontrol():
            cevap = QMessageBox.question(
                self,
                "Onay",
                f"Yerelde değişiklikleriniz var ve işleme devam ederseniz değişiklikleriniz silinecek. Devam etmek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.No:
                QMessageBox.information(self, "İptal", "İşlem iptal edildi.")
                return
        # hard reset komutu
        komut = "git fetch --all && git reset --hard origin/main"
        self.run_script(
            komut,
            baslik="Arayüz Kodları Güncelleniyor...",
            islem="Arayüz Kodları Güncelleme",
        )

    def interface_updated_succesfully(self):
        QMessageBox.information(
            self,
            "Bilgi",
            "Arayüz kodları güncellendi. Lütfen programı yeniden başlatın.",
        )
        sys.exit()

    def start_routine_check(self):
        komut = f"python3 {RUTIN_KONTROL_PY}"
        yol = os.path.join(BIR_UST_DIZIN, GOOGLE_FORM_ISLEMLERI)
        self.run_script(
            komut, baslik="Rutin Kontrol Yapılıyor...", islem="Rutin Kontrol", dizin=yol
        )

    def git_degisiklik_kontrol(self, git_dizin_yolu="."):
        # ilk dizini kaydet
        original_dir = os.getcwd()
        # Git status kontrolü
        os.chdir(git_dizin_yolu)
        stream = os.popen("git status")
        output = stream.read()
        degisiklik_var_mi = False
        # Değişiklik olup olmadığını kontrol et
        if "nothing to commit, working tree clean" not in output:
            degisiklik_var_mi = True
        # İlk dizine geri dön
        os.chdir(original_dir)
        return degisiklik_var_mi == False
