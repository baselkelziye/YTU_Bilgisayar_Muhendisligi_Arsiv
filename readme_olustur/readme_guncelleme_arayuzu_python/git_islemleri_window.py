import sys
import os
import subprocess
from PyQt5.QtWidgets import QDialog, QVBoxLayout, QPushButton
from degiskenler import *
class GitIslemleriWindow(QDialog):
    def __init__(self):
        super(GitIslemleriWindow, self).__init__()
        self.setModal(True)
        self.setWindowTitle("Git İşlemleri")
        self.setMinimumSize(300, 200)
        # Dialog layout
        self.layout = QVBoxLayout()


        # Butonlar ve renkler
        self.buttons = [
            QPushButton("Google Form Güncelle"),
            QPushButton("Readme Güncelle"),
            QPushButton("Değişiklikleri Github'a Pushla"),
            QPushButton("Arayüz Kodlarını Güncelle"),
            QPushButton("Rutin Kontrolü Başlat")
        ]

        self.colors = [
            "background-color: red;",
            "background-color: green;",
            "background-color: blue;",
            "background-color: yellow;",
            "background-color: pink;"
        ]

        # Buton fonksiyonları
        self.functions = [
            self.update_google_form,
            self.update_readme,
            self.push_changes,
            self.update_interface,
            self.start_routine_check
        ]
        # Butonları dialog'a ekleme, renklendirme ve bağlama
        for btn, color, func in zip(self.buttons, self.colors, self.functions):
            btn.setStyleSheet(color)
            self.layout.addWidget(btn)
            btn.clicked.connect(func)

        self.setLayout(self.layout)

        # İşletim sistemi kontrolü
        self.is_windows = sys.platform.startswith('win')

    def run_script(self, script_name):
        # Üst dizine çık
        parent_dir = os.path.dirname(os.path.abspath(__file__))
        script_path = os.path.join(parent_dir, script_name)
        
        # İşletim sistemine göre komutu seç ve çalıştır
        if self.is_windows:
            subprocess.run(["cmd.exe", "/c", script_path])
        else:
            subprocess.run(["/bin/bash", script_path])

    def update_google_form(self):
        self.run_script(GOOGLE_FORM_GUNCELLE_BAT if self.is_windows else GOOGLE_FORM_GUNCELLE_SH)

    def update_readme(self):
        self.run_script(README_GUNCELLE_BAT if self.is_windows else README_GUNCELLE_SH)

    def push_changes(self):
        self.run_script(DEGISIKLIKLERI_GITHUBA_YOLLA_BAT if self.is_windows else DEGISIKLIKLERI_GITHUBA_YOLLA_SH)

    def update_interface(self):
        self.run_script(ARAYUZU_GITHULA_ESITLE_BAT if self.is_windows else ARAYUZU_GITHULA_ESITLE_SH)

    def start_routine_check(self):
        self.run_script(RUTIN_KONTROL_BAT if self.is_windows else RUTIN_KONTROL_SH)
