import os
import json
from PyQt5.QtWidgets import (QDialog, QVBoxLayout, QPushButton, QMessageBox, QLineEdit, QLabel, QApplication, QComboBox, QScrollArea, QWidget, QHBoxLayout)
import locale
JSON_PATH = '../dersler.json'
HOCA_JSON_PATH = '../hocalar.json'
def hoca_kisaltma_olustur(isim):
    """
    Bir isimden kısaltma oluşturur ve unvanları (Doç. Dr., Prof. Dr., Dr. vb.) atar.
    Örneğin "Prof. Dr. Ahmet Elbir" için "AEL", "Dr. Göksel Biricik" için "GB" döndürür.
    """
    if not  isim:
        return None
    # Unvanları ve noktaları kaldır
    for unvan in ["Prof. Dr.", "Doç. Dr.", "Dr.", "Prof.", "Doç."]:
        isim = isim.replace(unvan, "")
    isim = isim.replace(".", "").strip()
    if "Elbir" in isim:
        return "AEL"
    if "Biricik" in isim:
        return "G1"
    # İsimleri ayır ve baş harfleri al
    parcalar = isim.split()
    if len(parcalar) == 1:  # Eğer sadece bir isim varsa
        return parcalar[0][:2].upper()
    else:
        # İlk iki ismin baş harflerini ve son ismin ilk harfini al
        kisaltma = ''.join(parca[0].upper() for parca in parcalar[:-1])
        kisaltma += parcalar[-1][0].upper()
        if len(parcalar[-1]) == 1:  # Eğer son isim sadece bir harf ise (örneğin "M.")
            kisaltma += str(len(parcalar))  # Sıra numarasını ekle (örneğin "MAG" yerine "MAG1")
        return kisaltma
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
            # Öncelikle Türkçe locale'i dene
            locale.setlocale(locale.LC_ALL, 'tr_TR.UTF-8')
        except locale.Error:
            try:
                # eğer sistemde tr dili yoksa linuxta böyle yüklenebilir
                #os.system('sudo locale-gen tr_TR.UTF-8')
                # Alternatif olarak başka bir Türkçe locale dene
                locale.setlocale(locale.LC_ALL, 'tr_TR')
            except locale.Error:
                # Varsayılan locale'e geri dön
                locale.setlocale(locale.LC_ALL, '')
        try:

            with open(JSON_PATH, 'r', encoding='utf-8') as file:
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
    def __init__(self, ders,data, parent):
        super().__init__(parent)
        self.ders = ders
        self.data = data
        self.parent = parent
        self.setModal(True)
        self.hocalarComboBoxlar = []  # Hoca seçimi için ComboBox'lar listesi
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Ders Düzenle/Ekle')
        self.setGeometry(100, 100, 600, 400)  # Pencere boyutunu ayarla

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
        self.layout.addWidget(QLabel('Dersi Veren Hocalar'))
        # Dersi veren hocalar için ComboBox'lar
        # Mevcut hocaları yükle
        with open(HOCA_JSON_PATH, 'r',encoding='utf-8') as file:
            hoca_data = json.load(file)
        # Hoca adlarını ve kısaltmalarını hazırla
        self.hoca_listesi = [(h['ad'], hoca_kisaltma_olustur(h['ad'])) for h in hoca_data['hocalar']]
        # Hocalar için kaydırılabilir alan oluştur
        self.hocaScrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.hocaScrollArea.setWidgetResizable(True)
        
        # Hocaların gösterileceği widget
        self.hocaScrollWidget = QWidget()
        self.hocalarLayout = QVBoxLayout(self.hocaScrollWidget)
        self.hocaScrollArea.setWidget(self.hocaScrollWidget)  # ScrollArea'ya widget ekle
        self.layout.addWidget(self.hocaScrollArea)  # Ana layout'a ScrollArea ekle
        if self.ders and 'dersi_veren_hocalar' in self.ders:
            for hoca in self.ders['dersi_veren_hocalar']:
                self.ekleHocaComboBox(hoca)
        # Ekle (+) butonu
        self.ekleHocaBtn = QPushButton('Dersi Veren Hoca Ekle', self)
        self.ekleHocaBtn.setStyleSheet("background-color: lightblue;")
        self.ekleHocaBtn.clicked.connect(self.ekleHocaComboBox)
        self.layout.addWidget(self.ekleHocaBtn)

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

    def ekleHocaComboBox(self, hoca=None):
        

        # Yeni ComboBox oluştur
        comboBox = QComboBox(self)
        for ad, kisaltma in self.hoca_listesi:
            comboBox.addItem(f"{ad} ({kisaltma})", kisaltma)  # Ad ve kısaltmayı ekle

        # Eğer kısaltma verildiyse, onu ComboBox'da seç
        if hoca:
            comboBox.setCurrentText(f"{hoca['ad']} ({hoca['kisaltma']})")

        # Sil (-) butonu
        silBtn = QPushButton('Dersi Veren Hocayı Sil', self)
        silBtn.setStyleSheet("background-color: rgb(255, 102, 102);")
        silBtn.clicked.connect(lambda: self.silHocaComboBox(comboBox, silBtn))

        hocaLayout = QHBoxLayout()
        hocaLayout.addWidget(comboBox)
        hocaLayout.addWidget(silBtn)
        self.hocalarLayout.addLayout(hocaLayout)  # Hoca layout'una ekle, bu self.hocaScrollWidget'a bağlı


        # ComboBox listesini güncelle
        self.hocalarComboBoxlar.append((comboBox, silBtn))

    def silHocaComboBox(self, comboBox, silBtn):
        # ComboBox ve sil butonunu kaldır
        self.hocalarLayout.removeWidget(comboBox)
        comboBox.deleteLater()
        self.hocalarLayout.removeWidget(silBtn)
        silBtn.deleteLater()
        # Listeden kaldır
        self.hocalarComboBoxlar.remove((comboBox, silBtn))

    def kaydet(self):
        ad = self.adInput.text().strip()
        yil = int(self.yilInput.currentText())
        donem = self.donemInput.currentText()
        tip = self.tipInput.currentText()
        # Seçili hocaların kısaltmalarını al
        hocalar_kisaltmalar = [combo.currentData() for combo, _ in self.hocalarComboBoxlar]
        
        # Kısaltmaların benzersiz olup olmadığını kontrol et
        if len(hocalar_kisaltmalar) != len(set(hocalar_kisaltmalar)):
            QMessageBox.warning(self, 'Hata', 'Aynı hocayı birden fazla kez seçemezsiniz!')
            return
        # Seçili hocaların kısaltmalarını al
        hocalar = [{'kisaltma': combo.currentData(), 'ad': combo.currentText().split(' (')[0]}
                   for combo, _ in self.hocalarComboBoxlar]
        
        # Ders adı boş olamaz kontrolü
        if not ad:
            QMessageBox.warning(self, 'Hata', 'Ders adı boş olamaz!')
            return

        # Mevcut dersleri kontrol et (yeni ders ekleniyorsa)
        if not self.ders and any(d['ad'].lower() == ad.lower() for d in self.data['dersler']):
            QMessageBox.warning(self, 'Hata', 'Bu isimde bir ders zaten var!')
            return

        # Ders bilgilerini güncelle veya yeni ders ekle
        ders_data = {"ad": ad, "yil": yil, "donem": donem, "tip": tip, "dersi_veren_hocalar": hocalar}
        if self.ders:  # Düzenleme modunda
            self.data['dersler'].remove(self.ders)
            self.data['dersler'].append(ders_data)
        else:  # Ekleme modunda
            self.data['dersler'].append(ders_data)

        # Değişiklikleri kaydet
        self.kaydetVeKapat()

    def sil(self):
        if not self.ders:
            QMessageBox.warning(self, 'Hata', 'Silinecek ders bulunamadı!')
            return

        emin_mi = QMessageBox.question(self, 'Onay', f'{self.ders["ad"]} dersini silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            self.data['dersler'].remove(self.ders)
            self.kaydetVeKapat()

    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            with open(JSON_PATH, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.dersleriYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
