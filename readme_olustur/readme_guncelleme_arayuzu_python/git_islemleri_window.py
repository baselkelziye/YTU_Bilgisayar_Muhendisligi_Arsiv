import sys
import os
import textwrap
from PyQt6.QtWidgets import QDialog, QVBoxLayout, QPushButton, QMessageBox, QApplication
from degiskenler import *
from helpers.progress_dialog_helper import CustomProgressDialogWithCancel
from threadler import CMDScriptRunnerThread, PythonFunctionRunnerThread
from PyQt6.QtGui import QIcon
from hoca_ve_ders_adlari_window import HocaDersAdlariWindow
from git_helper import GitDialog, GitHelper
from screen_utils import apply_minimum_size

# google_forum_islemleri modüllerini import etmek için path ekle
_google_form_path = os.path.join(os.path.dirname(__file__), '..', 'google_forum_islemleri')
if _google_form_path not in sys.path:
    sys.path.insert(0, _google_form_path)

# readme_olustur modülünü import etmek için path ekle
_parent_path = os.path.join(os.path.dirname(__file__), '..')
if _parent_path not in sys.path:
    sys.path.insert(0, _parent_path)


class GitIslemleriWindow(QDialog):
    def __init__(self, parent=None):
        super(GitIslemleriWindow, self).__init__(parent)
        self.setModal(True)
        self.setWindowTitle("Git İşlemleri")
        apply_minimum_size(self, 400, 400)  # Ekrana göre dinamik boyut
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

    def run_script(self, script_path, baslik, islem="", dizin=BIR_UST_DIZIN, arayuz_guncelleme=False):
        self.original_dir = os.getcwd()
        os.chdir(dizin)
        self.progress_dialog = CustomProgressDialogWithCancel(
            baslik, self, self.thread_durduruluyor
        )
        # Thread'i başlat
        self.thread = CMDScriptRunnerThread(script_path, islem)
        if arayuz_guncelleme:
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

    def run_python_function(self, functions, baslik, islem="", dizin=None):
        """
        Python fonksiyonlarını subprocess yerine doğrudan çalıştırır.
        PyInstaller ile derlenmiş uygulamalarda çalışması için tasarlanmıştır.
        
        Args:
            functions: Çalıştırılacak fonksiyonların listesi
            baslik: Progress dialog başlığı
            islem: İşlem açıklaması (onay dialog için)
            dizin: Çalışma dizini (None ise değiştirilmez)
        """
        self.original_dir = os.getcwd()
        if dizin:
            os.chdir(dizin)
        
        self.progress_dialog = CustomProgressDialogWithCancel(
            baslik, self, self.thread_durduruluyor
        )
        
        # PythonFunctionRunnerThread'i başlat
        self.thread = PythonFunctionRunnerThread(functions, islem)
        self.thread.finished.connect(self.on_finished)
        self.thread.error.connect(self.on_error)
        self.thread.info.connect(self.info)
        self.thread.start()
        self.progress_dialog.show()

    def update_google_form(self):
        # Modülleri dinamik olarak import et
        from google_forum_islemleri.hoca_icerikleri_guncelle import main as hoca_main
        from google_forum_islemleri.ders_icerikleri_guncelle import main as ders_main
        
        yol = os.path.join(BIR_UST_DIZIN, GOOGLE_FORM_ISLEMLERI)
        self.run_python_function(
            [hoca_main, ders_main],
            baslik="Google Form Güncelleniyor...",
            islem="Google Form Güncelleme",
            dizin=yol,
        )

    def update_readme(self):
        # Modülü dinamik olarak import et
        from readme_olustur import main as readme_main
        
        yol = BIR_UST_DIZIN
        self.run_python_function(
            [readme_main],
            baslik="README.md Güncelleniyor...",
            islem="README.md Güncelleme",
            dizin=yol,
        )


    def push_changes(self):
        yol = os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        if len(GitHelper.git_status(yol)) == 0:
            QMessageBox.information(
                self, "Temiz", "Şu anda herhangi bir değişiklik yok"
            )
            return
        gitDialog = GitDialog(yol, self)
        gitDialog.show()
        # Uygulamanın olay döngüsünü zorla işleyin
        QApplication.processEvents()
        gitDialog.getStatusToInterface()

    def update_dosyalar_repo(self):
        repo_yolu = os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        degisiklik_var = not self.git_degisiklik_kontrol(repo_yolu)
        
        if degisiklik_var:
            cevap = QMessageBox.question(
                self,
                "Değişiklikler Tespit Edildi",
                "Dizinde kaydedilmemiş değişiklikler var.\n\n"
                "Değişiklikler geçici olarak saklanacak (stash), güncelleme yapılacak ve sonra geri yüklenecek.\n\n"
                "Devam etmek istiyor musunuz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.No:
                QMessageBox.information(self, "İptal", "İşlem iptal edildi.")
                return
            # Stash (untracked dahil), pull --rebase, stash pop komutları
            komut = f'git -C "{repo_yolu}" stash push --include-untracked -m "auto-stash-before-update" && git -C "{repo_yolu}" pull --rebase; git -C "{repo_yolu}" stash pop || true'
        else:
            komut = f'git -C "{repo_yolu}" pull --rebase'
        
        self.run_script(
            komut,
            baslik="Dosya Değişiklikleri Github'dan Çekiliyor...",
            islem="Dosya Değişikliklerini Github'dan Çekme",
        )

    def update_interface(self):
        degisiklik_var = not self.git_degisiklik_kontrol()
        
        if degisiklik_var:
            cevap = QMessageBox.question(
                self,
                "Değişiklikler Tespit Edildi",
                "Yerelde değişiklikleriniz var.\n\n"
                "Değişiklikler geçici olarak saklanacak (stash), güncelleme yapılacak ve sonra geri yüklenecek.\n\n"
                "Devam etmek istiyor musunuz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.No:
                QMessageBox.information(self, "İptal", "İşlem iptal edildi.")
                return
            # Stash (untracked dahil), pull --rebase, stash pop komutu (güvenli güncelleme)
            # --include-untracked: untracked dosyaları da saklar
            # || true: stash başarısız olsa bile devam et (zaten değişiklik olmayabilir)
            komut = "git stash push --include-untracked -m 'auto-stash-before-update' && git pull --rebase; git stash pop || true"
        else:
            # Değişiklik yoksa sadece pull --rebase
            komut = "git pull --rebase"
        
        self.run_script(
            komut,
            baslik="Arayüz Kodları Güncelleniyor...",
            islem="Arayüz Kodları Güncelleme",
            arayuz_guncelleme=True,
        )

    def interface_updated_succesfully(self, output):
        self.progress_dialog.close()
        self.thread.wait()
        del self.thread
        del self.progress_dialog
        os.chdir(self.original_dir)
        QMessageBox.information(
            self,
            "Bilgi",
            "Arayüz kodları güncellendi. Lütfen programı yeniden başlatın.",
        )
        sys.exit()

    def start_routine_check(self):
        # Sadece dokümanlar reposunda değişiklik kontrolü yap
        dokumanlar_repo_yolu = os.path.join(BIR_UST_DIZIN, DOKUMANLAR_REPO_YOLU)
        
        dokumanlar_dizin_temiz = self.git_degisiklik_kontrol(dokumanlar_repo_yolu)
        
        if not dokumanlar_dizin_temiz:
            QMessageBox.warning(
                self, 
                "Uyarı", 
                "Dokümanlar dizininde kaydedilmemiş değişiklikler var.\n\n"
                "Rutin kontrol sırasında dosyalar değişebilir. Lütfen önce değişiklikleri commit yapın veya geri alın."
            )
            return
        
        # Modülü dinamik olarak import et
        from google_forum_islemleri.google_form_rutin_kontrol import main as rutin_main
        
        yol = os.path.join(BIR_UST_DIZIN, GOOGLE_FORM_ISLEMLERI)
        self.run_python_function(
            [rutin_main],
            baslik="Rutin Kontrol Yapılıyor...",
            islem="Rutin Kontrol",
            dizin=yol,
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
