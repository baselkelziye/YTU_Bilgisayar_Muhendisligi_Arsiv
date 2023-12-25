import json
from PyQt5.QtWidgets import (QDialog, QVBoxLayout, QPushButton, QMessageBox, QLineEdit, QLabel, QApplication, QComboBox, QScrollArea, QWidget, QHBoxLayout)
import locale
from pathlib import Path
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
JSON_PATH = '../dersler.json'
HOCA_JSON_PATH = '../hocalar.json'

# Hoca adlarını ve kısaltmalarını hazırla
unvanlar = {'Prof. Dr.': 1, 'Doç. Dr.': 2, 'Dr.': 3}
def hoca_sirala(hoca):
    ad = hoca[0].strip()
    unvan = next((u for u in unvanlar if ad.startswith(u)), None)
    return (unvanlar.get(unvan, 4), ad)
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

        # Ders sayısını gösteren etiket
        self.dersSayisiLabel = QLabel('Toplam 0 ders')
        self.dersSayisiLabel.setFixedHeight(20)
        self.mainLayout.addWidget(self.dersSayisiLabel)

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
                ders_sayisi = len(self.data['dersler'])  # Ders sayısını hesapla
                self.dersSayisiLabel.setText(f'Toplam {ders_sayisi} ders')  # Ders sayısını etikette güncelle

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
        self.yilInput.addItems(['0','1', '2', '3', '4'])
        if self.ders:
            self.yilInput.setCurrentIndex(self.ders['yil'])
        self.layout.addWidget(self.yilInput)

        # Ders dönemi için alan
        self.layout.addWidget(QLabel('Dönem:'))
        self.donemInput = QComboBox(self)
        self.donemInput.addItems(['Yok','Güz', 'Bahar'])
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

        hoca_listesi = [
            (h['ad'], hoca_kisaltma_olustur(h['ad']))
            for h in hoca_data['hocalar']
            if h['ad'].strip() and hoca_kisaltma_olustur(h['ad']).strip()
        ]

        self.hoca_listesi = sorted(hoca_listesi, key=hoca_sirala)

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
        try:
            yil = int(self.yilInput.currentText())
        except:
            yil = 0
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

        # Dersi bulma ve güncelleme
        if self.ders:  # Düzenleme modunda
            # Mevcut dersin referansını bulun
            mevcut_ders = next((d for d in self.data['dersler'] if d == self.ders), None)
            if mevcut_ders:
                # Yalnızca belirli alanları güncelleyin
                mevcut_ders["ad"] = ad
                mevcut_ders["yil"] = yil
                mevcut_ders["donem"] = donem if donem != 'Yok' else ''
                mevcut_ders["tip"] = tip
                mevcut_ders["dersi_veren_hocalar"] = hocalar
        else:  # Ekleme modunda
            # Ders bilgilerini güncelle veya yeni ders ekle
            ders_data = {"ad": ad, "yil": yil, "donem": donem, "tip": tip, "dersi_veren_hocalar": hocalar}
            self.data['dersler'].append(ders_data)
    

        self.hocaDersleriniGuncelle(ad, hocalar)
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
    def hocaDersleriniGuncelle(self, ders_adi, veren_hocalar):
        # JSON dosyasını aç ve verileri yükle
        json_dosyasi = Path(HOCA_JSON_PATH)
        if not json_dosyasi.exists():
            print("Hoca JSON dosyası bulunamadı.")
            return

        with open(json_dosyasi, 'r', encoding='utf-8') as file:
            data = json.load(file)
        hoca_adlari = [hoca["ad"] for hoca in veren_hocalar]
        # Hocalar listesinde dolaş
        for hoca in data.get("hocalar", []):
            hoca_adi = hoca.get("ad")
            mevcut_dersler = hoca.get("dersler", [])

            if hoca_adi in hoca_adlari:
                # Eğer hoca bu dersi zaten veriyorsa, devam et
                if ders_adi not in mevcut_dersler:
                    mevcut_dersler.append(ders_adi)
            else:
                # Eğer hoca bu dersi vermiyorsa ve ders listesinde varsa, çıkar
                if ders_adi in mevcut_dersler:
                    mevcut_dersler.remove(ders_adi)

            # Güncellenmiş ders listesini hoca profiline ekle
            hoca["dersler"] = mevcut_dersler

        # Değişiklikleri JSON dosyasına yaz
        with open(json_dosyasi, 'w', encoding='utf-8') as file:
            json.dump(data, file, ensure_ascii=False, indent=4)
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
