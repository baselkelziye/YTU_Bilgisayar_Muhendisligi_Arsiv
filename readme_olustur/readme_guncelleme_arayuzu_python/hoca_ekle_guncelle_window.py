import sys
import json
from PyQt5.QtWidgets import (QDialog, QVBoxLayout, QPushButton, QMessageBox, QComboBox, QLineEdit,QTextEdit, QLabel, QApplication, QHBoxLayout, QFrame, QScrollArea, QWidget)

JSON_DOSYASI = '../hocalar.json'

class HocaEkleGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Hocaları Ekle/Güncelle')
        self.setGeometry(100, 100, 800, 600)  # Pencere boyutunu büyüt

        self.mainLayout = QVBoxLayout(self)  # Ana layout

        # Hoca ekleme butonu
        self.ekleBtn = QPushButton('Hoca Ekle', self)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Yeşil arka plan
        self.ekleBtn.clicked.connect(self.hocaEkle)
        self.mainLayout.addWidget(self.ekleBtn)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)
        
        # Hocaları gösterecek iç içe geçmiş widget'lar oluştur
        self.scrollWidget = QWidget()
        self.hocalarLayout = QVBoxLayout(self.scrollWidget)
        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.hocalariYukle()

    def hocalariYukle(self):
        try:
            with open(JSON_DOSYASI, 'r') as file:
                self.data = json.load(file)
                for hoca in self.data['hocalar']:
                    if hoca['ad']:
                        btn = QPushButton(f"{hoca['ad']}", self.scrollWidget)
                        btn.clicked.connect(lambda checked, a=hoca: self.hocaDuzenle(a))
                        self.hocalarLayout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')

    def hocaEkle(self):
        # Yeni hoca ekleme penceresi
        self.hocaDuzenlemePenceresi = HocaDuzenlemeWindow(None, self.data, self)
        self.hocaDuzenlemePenceresi.show()

    def hocaDuzenle(self, hoca):
        # Mevcut hoca düzenleme penceresi
        self.hocaDuzenlemePenceresi = HocaDuzenlemeWindow(hoca, self.data, self)
        self.hocaDuzenlemePenceresi.show()

    def hocalariYenile(self):
        # Mevcut hoca butonlarını temizle
        for i in reversed(range(self.hocalarLayout.count())): 
            widgetToRemove = self.hocalarLayout.itemAt(i).widget()
            self.hocalarLayout.removeWidget(widgetToRemove)
            widgetToRemove.setParent(None)
        self.hocalariYukle()

# Hoca Düzenleme/Ekleme Penceresi
class HocaDuzenlemeWindow(QDialog):
    def __init__(self, hoca, data, parent):
        super().__init__()
        self.hoca = hoca
        self.data = data
        self.parent = parent
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Hoca Düzenle/Ekle')
        self.setGeometry(100, 100, 400, 600)  # Pencere boyutunu ayarla

        self.layout = QVBoxLayout(self)

        # Hoca adı için alan
        self.layout.addWidget(QLabel('Ad:'))
        self.adInput = QTextEdit(self.hoca['ad'] if self.hoca else '')
        self.layout.addWidget(self.adInput)

        # Hoca ofisi için alan
        self.layout.addWidget(QLabel('Ofis:'))
        self.ofisInput = QLineEdit(self.hoca['ofis'] if self.hoca else '')
        self.layout.addWidget(self.ofisInput)

        # Hoca linki için alan
        self.layout.addWidget(QLabel('Link:'))
        self.linkInput = QLineEdit(self.hoca['link'] if self.hoca else '')
        self.layout.addWidget(self.linkInput)

        # Hoca cinsiyet durumu için alan
        self.layout.addWidget(QLabel('Erkek mi?'))
        self.erkekMiInput = QComboBox(self)
        self.erkekMiInput.addItems(['Evet', 'Hayır'])
        if self.hoca:
            self.erkekMiInput.setCurrentIndex(0 if self.hoca['erkek_mi'] else 1)
        self.layout.addWidget(self.erkekMiInput)

        # Hoca dersleri için alan
        self.layout.addWidget(QLabel('Dersler (virgülle ayrılmış):'))
        self.derslerInput = QLineEdit(','.join(self.hoca['dersler']) if self.hoca and 'dersler' in self.hoca else '')
        self.layout.addWidget(self.derslerInput)

        # Diğer bilgiler ve dersler buraya eklenebilir

        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        self.kaydetBtn.setStyleSheet("background-color: green;")
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.layout.addWidget(self.kaydetBtn)

        if self.hoca:
            self.silBtn = QPushButton('Hocayı Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet("background-color: red;")
            self.layout.addWidget(self.silBtn)
    def kaydet(self):
        ad = self.adInput.toPlainText().strip()
        if not ad:
            QMessageBox.warning(self, 'Hata', 'Hoca adı boş olamaz!')
            return

        ofis = self.ofisInput.text().strip()
        link = self.linkInput.text().strip()
        erkek_mi = self.erkekMiInput.currentText() == 'Evet'
        dersler = [ders.strip() for ders in self.derslerInput.text().split(',') if ders.strip()]

        if self.hoca:  # Düzenleme modunda
            self.hoca.update({
                "ad": ad,
                "ofis": ofis,
                "link": link,
                "erkek_mi": erkek_mi,
                "dersler": dersler
            })
        else:  # Ekleme modunda
            yeni_hoca = {
                "ad": ad,
                "ofis": ofis,
                "link": link,
                "erkek_mi": erkek_mi,
                "dersler": dersler
            }
            self.data['hocalar'].append(yeni_hoca)

        self.kaydetVeKapat()
    def sil(self):
        # Hocayı sil
        emin_mi = QMessageBox.question(self, 'Onay', 'Hocayı silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes and self.hoca:
            self.data['hocalar'].remove(self.hoca)
            self.kaydetVeKapat()

    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            with open(JSON_DOSYASI, 'w') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.hocalariYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
