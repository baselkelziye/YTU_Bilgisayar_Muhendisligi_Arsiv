import sys
import json
from PyQt5.QtWidgets import (QApplication, QDialog, QPushButton, QVBoxLayout, 
                             QTextEdit, QLabel, QMessageBox)
import requests  # requests modülünü içe aktar

JSON_DOSYASI = '../katkida_bulunanlar.json'

class KatkidaBulunanEkleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()
        
    def initUI(self):
        self.setWindowTitle('Katkıda Bulunan Ekle')
        layout = QVBoxLayout()
        
        # Ad ve GitHub Linki için giriş alanları
        self.name_label = QLabel('Ad:')
        self.name_input = QTextEdit()
        self.github_label = QLabel('GitHub Kullanıcı Adı:')
        self.github_input = QTextEdit()
        self.ekle_btn = QPushButton('Ekle', self)
        
        # Butona basıldığında ekleme işlevini çalıştır
        self.ekle_btn.clicked.connect(self.ekle)

        # Arayüze elemanları ekle
        layout.addWidget(self.name_label)
        layout.addWidget(self.name_input)
        layout.addWidget(self.github_label)
        layout.addWidget(self.github_input)
        layout.addWidget(self.ekle_btn)
        
        self.setLayout(layout)

    def ekle(self):
        # Giriş alanlarından bilgileri al
        ad = self.name_input.toPlainText().strip() 
        github_kullanici_adi = self.github_input.toPlainText().strip() 
        github_url = f"https://github.com/{github_kullanici_adi}"

        if ad and github_kullanici_adi:
            try:
                
                # JSON dosyasını aç ve oku
                with open(JSON_DOSYASI, 'r+') as file:
                    data = json.load(file)

                # Case insensitive karşılaştırma yaparak ad ve URL kontrol et
                if any(kisi['ad'].lower() == ad.lower() for kisi in data['katkida_bulunanlar']):
                    QMessageBox.warning(self, 'Hata', 'Bu isim zaten mevcut!')
                elif any(kisi['github_link'] == github_url for kisi in data['katkida_bulunanlar']):
                    QMessageBox.warning(self, 'Hata', 'Bu GitHub linki zaten eklenmiş!')
                else:
                    # GitHub URL'sinin varlığını kontrol et
                    response = requests.get(github_url)
                    if response.status_code == 404:
                        QMessageBox.warning(self, 'Hata', 'GitHub kullanıcı adı geçerli değil!')
                        return
                    # Yeni veriyi ekle ve dosyayı güncelle
                    data['katkida_bulunanlar'].append({"ad": ad, "github_link": github_url})
                    with open(JSON_DOSYASI, 'w') as file:
                        json.dump(data, file,ensure_ascii=False, indent=4)
                    QMessageBox.information(self, 'Başarılı', 'Katkıda bulunan eklendi!')
                    self.close()
            except Exception as e:
                QMessageBox.critical(self, 'Hata', f'Bir hata oluştu: {e}')
        else:
            QMessageBox.warning(self, 'Hata', 'Ad ve GitHub kullanıcı adı alanları boş bırakılamaz!')
