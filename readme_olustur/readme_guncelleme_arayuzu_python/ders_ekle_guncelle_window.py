import sys
import json
from PyQt5.QtWidgets import (QDialog, QVBoxLayout, QPushButton, QMessageBox, QLineEdit, QLabel, QApplication, QComboBox, QScrollArea, QWidget, QHBoxLayout)
import locale
JSON_PATH = '../dersler.json'
HOCA_JSON_PATH = '../hocalar.json'

class DersEkleGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Ders Ekle/Güncelle')
        self.setGeometry(100, 100, 800, 600)  # Pencere boyutunu ayarla

        self.mainLayout = QVBoxLayout(self)  # Ana layout

        # Ders ekleme butonu
        self.ekleBtn = QPushButton('Ders Ekle', self)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Yeşil arka plan
        self.ekleBtn.clicked.connect(self.dersEkle)
        self.mainLayout.addWidget(self.ekleBtn)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)
        
        # Dersleri gösterecek widget
        self.scrollWidget = QWidget()
        self.derslerLayout = QVBoxLayout(self.scrollWidget)
        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.dersleriYukle()

   
    def dersleriYukle(self):
        try:
            # Türkçe karakterlere göre sıralama için locale ayarla
            locale.setlocale(locale.LC_ALL, 'tr_TR.UTF-8')

            with open(JSON_PATH, 'r') as file:
                self.data = json.load(file)
                # Dersleri ders adına göre Türkçe alfabetik olarak sırala (büyük/küçük harf duyarsız)
                sorted_dersler = sorted(self.data['dersler'], key=lambda d: locale.strxfrm(d['ad'].lower()))

                for ders in sorted_dersler:
                    btn = QPushButton(f"{ders['ad']}", self.scrollWidget)
                    btn.clicked.connect(lambda checked, a=ders: self.dersDuzenle(a))
                    self.derslerLayout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')


    def dersEkle(self):
        self.dersDuzenlemePenceresi = DersDuzenlemeWindow(None, self.data, self)
        self.dersDuzenlemePenceresi.show()

    def dersDuzenle(self, ders):
        self.dersDuzenlemePenceresi = DersDuzenlemeWindow(ders, self.data, self)
        self.dersDuzenlemePenceresi.show()

    def dersleriYenile(self):
        for i in reversed(range(self.derslerLayout.count())): 
            widgetToRemove = self.derslerLayout.itemAt(i).widget()
            self.derslerLayout.removeWidget(widgetToRemove)
            widgetToRemove.setParent(None)
        self.dersleriYukle()

class DersDuzenlemeWindow(QDialog):
    def __init__(self, ders, data, parent):
        super().__init__()
        self.ders = ders
        self.data = data
        self.parent = parent
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Ders Düzenle/Ekle')
        self.setGeometry(100, 100, 400, 600)  # Pencere boyutunu ayarla

        self.layout = QVBoxLayout(self)

        # Ders adı için alan
        self.layout.addWidget(QLabel('Ders Adı:'))
        self.adInput = QLineEdit(self.ders['ad'] if self.ders else '')
        self.layout.addWidget(self.adInput)

        # Ders yılı için alan
        self.layout.addWidget(QLabel('Yıl:'))
        self.yilInput = QComboBox(self)
        self.yilInput.addItems(['1', '2', '3', '4'])
        if self.ders:
            self.yilInput.setCurrentIndex(self.ders['yil'] - 1)
        self.layout.addWidget(self.yilInput)

        # Ders dönemi için alan
        self.layout.addWidget(QLabel('Dönem:'))
        self.donemInput = QComboBox(self)
        self.donemInput.addItems(['Güz', 'Bahar'])
        if self.ders:
            self.donemInput.setCurrentText(self.ders['donem'])
        self.layout.addWidget(self.donemInput)

        # Ders tipi için alan
        self.layout.addWidget(QLabel('Tip:'))
        self.tipInput = QComboBox(self)
        self.tipInput.addItems(['Zorunlu', 'Seçmeli', 'Seçmeli4', 'Mesleki Seçmeli'])
        if self.ders:
            self.tipInput.setCurrentText(self.ders['tip'])
        self.layout.addWidget(self.tipInput)

        # Dersi veren hocalar için alan
        self.layout.addWidget(QLabel('Dersi Veren Hocalar (Kısaltma):'))
        self.hocalarInput = QLineEdit(','.join(hoca['kisaltma'] for hoca in self.ders['dersi_veren_hocalar']) if self.ders and 'dersi_veren_hocalar' in self.ders else '')
        self.layout.addWidget(self.hocalarInput)

        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        buttonsLayout = QHBoxLayout()
        if self.ders:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        
        self.kaydetBtn.setStyleSheet("background-color: green;")
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydetBtn)

        if self.ders:
            self.silBtn = QPushButton('Dersi Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet("background-color: red;")
            buttonsLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonsLayout)

    def kaydet(self):
        ad = self.adInput.text().strip()
        yil = int(self.yilInput.currentText())
        donem = self.donemInput.currentText()
        tip = self.tipInput.currentText()
        hocalar = [{'kisaltma': hoca.strip()} for hoca in self.hocalarInput.text().split(',') if hoca.strip()]

        # Ders adı boş olamaz kontrolü
        if not ad:
            QMessageBox.warning(self, 'Hata', 'Ders adı boş olamaz!')
            return

        # Mevcut dersleri kontrol et
        if any(ders['ad'].lower() == ad.lower() for ders in self.data['dersler'] if ders != self.ders):
            QMessageBox.warning(self, 'Hata', 'Bu isimde bir ders zaten var!')
            return

        # Ders ekleme veya güncelleme işlemi için onay iste
        onay_mesaji = 'Dersi güncellemek istediğinden emin misin?' if self.ders else 'Yeni dersi eklemek istediğinden emin misin?'
        emin_mi = QMessageBox.question(self, 'Onay', onay_mesaji, QMessageBox.Yes | QMessageBox.No)

        if emin_mi == QMessageBox.Yes:
            # Ders bilgilerini güncelle veya yeni ders ekle
            if self.ders:  # Düzenleme modunda
                self.ders.update({"ad": ad, "yil": yil, "donem": donem, "tip": tip, "dersi_veren_hocalar": hocalar})
            else:  # Ekleme modunda
                yeni_ders = {"ad": ad, "yil": yil, "donem": donem, "tip": tip, "dersi_veren_hocalar": hocalar}
                self.data['dersler'].append(yeni_ders)

            # Değişiklikleri kaydet
            self.kaydetVeKapat()
        else:
            # Kullanıcı işlemi iptal etti
            QMessageBox.information(self, 'İptal Edildi', 'İşlem iptal edildi.')


    def sil(self):
        # Dersi sil
        emin_mi = QMessageBox.question(self, 'Onay', f'{self.ders["ad"]} dersini silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes and self.ders:
            self.data['dersler'].remove(self.ders)
            self.kaydetVeKapat()

    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            with open(JSON_PATH, 'w') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.dersleriYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
