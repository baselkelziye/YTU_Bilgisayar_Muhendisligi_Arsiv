import requests
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
            with open(JSON_DOSYASI, 'r',encoding='utf-8') as file:
                self.data = json.load(file)

                def unvan_ve_isim_ayir(hoca):
                    # Ünvanları ve sıralama önceliklerini tanımla
                    unvanlar = {'Prof. Dr.': 1, 'Doç. Dr.': 2, 'Dr.': 3, '': 4}
                    ad = hoca['ad']
                    for unvan in unvanlar:
                        if ad.startswith(unvan):
                            return unvanlar[unvan], ad[len(unvan):].strip()  # Ünvanın önceliği ve adı döndür
                    return unvanlar[''], ad  # Eğer ünvan yoksa

                # Hocaları önce ünvanlarına, sonra adlarına göre sırala
                sorted_hocalar = sorted(self.data['hocalar'], key=lambda hoca: unvan_ve_isim_ayir(hoca))

                for hoca in sorted_hocalar:
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
        if self.hoca is not None:
            self.setWindowTitle('Hoca Düzenle')
        else:
            self.setWindowTitle('Hoca Ekle')
        self.setGeometry(100, 100, 400, 600)  # Pencere boyutunu ayarla

        self.layout = QVBoxLayout(self)
        # Ünvan için alan
        self.layout.addWidget(QLabel('Ünvan:'))
        self.unvanInput = QComboBox(self)
        unvanlar = ['Prof. Dr.', 'Doç. Dr.', 'Dr.']
        self.unvanInput.addItems(unvanlar)
        self.layout.addWidget(self.unvanInput)
        # Hoca adı için alan
        ad = self.hoca['ad'] if self.hoca else ''
        ad, unvan = self.ayiklaUnvan(ad)
         # Ünvanı ayarla
        if unvan in unvanlar:
            self.unvanInput.setCurrentIndex(unvanlar.index(unvan))
        self.layout.addWidget(QLabel('Ad:'))
        self.adInput = QLineEdit(ad)
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
        if self.hoca is not None:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        self.kaydetBtn.setStyleSheet("background-color: green;")
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.layout.addWidget(self.kaydetBtn)

        if self.hoca:
            self.silBtn = QPushButton('Hocayı Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet("background-color: red;")
            self.layout.addWidget(self.silBtn)
    def ayiklaUnvan(self, ad):
        unvanlar = ['Prof. Dr.', 'Doç. Dr.', 'Dr.']
        for unvan in unvanlar:
            if ad.startswith(unvan):
                return ad[len(unvan)+1:], unvan  # İsim ve ünvanı ayır
        return ad, ''  # Eğer ünvan yoksa
    def check_url(self, url):
        try:
            response = requests.head(url, allow_redirects=True, timeout=5)
            # Burada HTTP durum kodunu kontrol ediyoruz, 200 başarılı anlamına gelir.
            if response.status_code == 200:
                return True
            else:
                QMessageBox.critical(self, 'Geçersiz URL', f'URL geçerli değil veya erişilemiyor: {url}')
                return False
        except requests.RequestException as e:
            # Erişimde bir hata oluştuğunda hata mesajını göster
            QMessageBox.critical(self, 'Geçersiz URL', f'URL kontrolü sırasında bir hata oluştu: {e}')
            return False
    def kaydet(self):
        ad = self.adInput.text()
        if not ad:
            QMessageBox.warning(self, 'Hata', 'Hoca adı boş olamaz!')
            return

        ofis = self.ofisInput.text().strip()
        link = self.linkInput.text().strip()
        erkek_mi = self.erkekMiInput.currentText() == 'Evet'
        dersler = [ders.strip() for ders in self.derslerInput.text().split(',') if ders.strip()]
        if link and not self.check_url(link):
            QMessageBox.warning(self, 'Hata', 'Güncelleme başarısız!!!')
            return  # Eğer URL geçerli değilse fonksiyondan çık
        if self.hoca:  # Düzenleme modunda
            self.hoca.update({
                "ad":self.unvanInput.currentText() + " " + ad,
                "ofis": ofis,
                "link": link,
                "erkek_mi": erkek_mi,
                "dersler": dersler
            })
        else:  # Ekleme modunda
            yeni_hoca = {
                "ad":self.unvanInput.currentText()+ " " + ad,
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
            with open(JSON_DOSYASI, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.hocalariYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
