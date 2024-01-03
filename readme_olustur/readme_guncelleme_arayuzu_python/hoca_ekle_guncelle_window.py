import requests
import locale
import json
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QDialog,QVBoxLayout, QInputDialog,QSizePolicy, QPushButton,QProgressDialog, QMessageBox, QComboBox, QLineEdit,QTextEdit, QLabel, QApplication, QHBoxLayout, QFrame, QScrollArea, QWidget)
from threadler import HocaKaydetThread
from progress_dialog import CustomProgressDialog
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
JSON_DOSYASI = '../hocalar.json'
DERSLER_JSON_PATH = '../dersler.json'
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
class HocaEkleGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Hocaları Ekle/Güncelle')
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.setStyleSheet("background-color: blue; color: white;")  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Hoca ekleme butonu
        self.ekleBtn = QPushButton('Hoca Ekle', self)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Yeşil arka plan
        self.ekleBtn.clicked.connect(self.hocaEkle)
        self.mainLayout.addWidget(self.ekleBtn)

        # Hoca sayısını gösteren etiket
        self.hocaSayisiLabel = QLabel('Toplam 0 hoca')
        self.hocaSayisiLabel.setFixedHeight(20)
        self.mainLayout.addWidget(self.hocaSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)

        # Hocaları gösterecek iç içe geçmiş widget'lar oluştur
        self.scrollWidget = QWidget()
        self.hocalarLayout = QVBoxLayout(self.scrollWidget)
        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.hocalariYukle()
    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak hoca:')
            if ok:
                self.searchHocalar(text)
    # Filtreleri temizleme fonksiyonu
    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                    'Filtreleri temizlemek istediğinize emin misiniz?', 
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.hocalarLayout.count()):
                widget = self.hocalarLayout.itemAt(i).widget()
                if isinstance(widget, QPushButton):
                    widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.hocaSayisiLabel.setText(f'Toplam {len(self.data["hocalar"])} hoca')  # Hoca sayısını etikette güncelle
    def searchHocalar(self, query):
        if query == '':
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, hoca in enumerate(self.sorted_hocalar):
            hoca_ad = hoca['ad']
            widget = self.hocalarLayout.itemAt(idx).widget()
            if isinstance(widget, QPushButton):
                if query.lower() in hoca_ad.lower():
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.sorted_hocalar):
            self.clearFilters(is_clicked=False)
            return
        self.hocaSayisiLabel.setText(f'{size} hoca bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()
    def jsonDosyasiniYukle(self):
        try:
            with open(JSON_DOSYASI, 'r', encoding='utf-8') as file:
                return json.load(file)
        except Exception as e:
            return json.loads('{}')
    def hocalariYukle(self):
        self.data = self.jsonDosyasiniYukle()
        try:
            if 'bolum_adi' not in self.data:
                self.data['bolum_adi'] = 'Hocalar'
            if 'bolum_aciklamasi' not in self.data:
                self.data['bolum_aciklamasi'] = "Bu bölüm, Yıldız Teknik Üniversitesi X Mühendisliği bölümündeki hocaların detaylı bilgilerini içerir. Hocaların adları, ofis bilgileri, araştırma sayfalarının bağlantıları ve verdikleri bazı dersler bu bölümde listelenmektedir. Öğrenciler ve diğer ilgililer için hocalar hakkında temel bilgiler ve iletişim detayları sunulmaktadır. Hocaların puanlamaları tamamen subjektiftir ve  0-10 yıldız arasında yapılmıştır."
            if 'hocalar' not in self.data:
                self.data['hocalar'] = []
            hoca_sayisi = len(self.data['hocalar'])  # Hoca sayısını hesapla
            self.hocaSayisiLabel.setText(f'Toplam {hoca_sayisi} hoca')  # Hoca sayısını etikette güncelle
            def unvan_ve_isim_ayir(hoca):
                # Ünvanları ve sıralama önceliklerini tanımla
                unvanlar = {'Prof. Dr.': 1, 'Doç. Dr.': 2, 'Dr.': 3, '': 4}
                ad = hoca['ad']
                for unvan in unvanlar:
                    if ad.startswith(unvan):
                        return unvanlar[unvan], ad[len(unvan):].strip()  # Ünvanın önceliği ve adı döndür
                return unvanlar[''], ad  # Eğer ünvan yoksa

            # Hocaları önce ünvanlarına, sonra adlarına göre sırala
            self.sorted_hocalar = sorted(self.data['hocalar'], key=lambda hoca: unvan_ve_isim_ayir(hoca))

            for hoca in self.sorted_hocalar:
                if hoca['ad'] != '':
                    btn = QPushButton(f"{hoca['ad']}", self.scrollWidget)
                    btn.clicked.connect(lambda checked, a=hoca: self.hocaDuzenle(a))
                    self.hocalarLayout.addWidget(btn)
                else:
                    self.sorted_hocalar.remove(hoca)
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
        self.clearFiltersButton.hide()  # Temizle butonunu gizle

# Hoca Düzenleme/Ekleme Penceresi
class HocaDuzenlemeWindow(QDialog):
    def __init__(self, hoca, data, parent):
        super().__init__()
        self.hoca = hoca
        self.data = data
        self.parent = parent
        self.derslerComboBoxlar = []  # Hoca seçimi için ComboBox'lar listesi
        self.setModal(True)
        self.initUI()

    def initUI(self):
        if self.hoca is not None:
            self.setWindowTitle('Hoca Düzenle')
        else:
            self.setWindowTitle('Hoca Ekle')

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
        self.progressDialog = CustomProgressDialog('Kontrol Ediliyor...', self)
        self.progressDialog.close()
        # Diğer bilgiler ve dersler buraya eklenebilir
        self.dersler = self.dersleriYukle()
        # Derslerin sadece 'ad' alanını al ve adlarına göre sırala
        self.dersler = sorted([ders['ad'] for ders in self.dersler], key=locale.strxfrm)
        self.layout.addWidget(QLabel('Hocanın Verdiği Dersler'))
        
        # Hocalar için kaydırılabilir alan oluştur
        self.derslerScorllArea = QScrollArea(self)  # ScrollArea oluştur
        self.derslerScorllArea.setWidgetResizable(True)
        # Hocaların gösterileceği widget
        self.dersScrollWidget = QWidget()
        # ScrollArea genişliğini dersScrollWidget genişliğiyle sınırla
        self.dersScrollWidget.setMinimumWidth(self.derslerScorllArea.width())
        self.dersScrollWidget.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Expanding)
        self.derslerLayout = QVBoxLayout(self.dersScrollWidget)
        self.derslerScorllArea.setWidget(self.dersScrollWidget)  # ScrollArea'ya widget ekle
        self.layout.addWidget(self.derslerScorllArea)  # Ana layout'a ScrollArea ekle
        if self.hoca and 'dersler' in self.hoca:
            for ders in self.hoca['dersler']:
                self.dersEkleComboBox(ders)
        # Ekle (+) butonu
        self.ekleHocaBtn = QPushButton('Hocanın Verdiği Ders Ekle', self)
        self.ekleHocaBtn.setStyleSheet("background-color: lightblue;")
        self.ekleHocaBtn.clicked.connect(self.dersEkleComboBox)
        self.layout.addWidget(self.ekleHocaBtn)
        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        buttonsLayout = QHBoxLayout()

        if self.hoca is not None:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        self.kaydetBtn.setStyleSheet("background-color: green;")
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydetBtn)  # buttonsLayout'a Kaydet butonunu ekle

        if self.hoca:
            self.silBtn = QPushButton('Hocayı Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet("background-color: red;")
            buttonsLayout.addWidget(self.silBtn)  # buttonsLayout'a Sil butonunu ekle

        # Yatay düzeni ana düzene ekle
        self.layout.addLayout(buttonsLayout)
    def dersEkleComboBox(self,hoca_ders=None):
        if len(self.dersler) == 0:
            QMessageBox.critical(self, 'Hata', 'Herhangi bir ders bulunamadı. Lütfen önce ders ekleyin.')
            return
        # Yeni ComboBox oluştur
        comboBox = QComboBox(self)
        for ders in self.dersler:
            comboBox.addItem(ders)  # Ad ve kısaltmayı ekle

        # Eğer kısaltma verildiyse, onu ComboBox'da seç
        if hoca_ders:
            comboBox.setCurrentText(hoca_ders)

        # Sil (-) butonu
        silBtn = QPushButton('Hocanın Verdiği Dersi Sil', self)
        silBtn.setStyleSheet("background-color: rgb(255, 102, 102);")
        silBtn.clicked.connect(lambda: self.silDersComboBox(comboBox, silBtn))

        derslerLayout = QHBoxLayout()
        derslerLayout.addWidget(comboBox)
        derslerLayout.addWidget(silBtn)
        self.derslerLayout.addLayout(derslerLayout)  # Hoca layout'una ekle, bu self.hocaScrollWidget'a bağlı


        # ComboBox listesini güncelle
        self.derslerComboBoxlar.append((comboBox, silBtn))
    def silDersComboBox(self, comboBox, silBtn):
        # ComboBox ve sil butonunu kaldır
        self.derslerLayout.removeWidget(comboBox)
        comboBox.deleteLater()
        self.derslerLayout.removeWidget(silBtn)
        silBtn.deleteLater()
        # Listeden kaldır
        self.derslerComboBoxlar.remove((comboBox, silBtn))
    def secilenDersleriDondur(self):
        ders_listesi = []
        for derslerComboboxTuple in self.derslerComboBoxlar:
            comboBox = derslerComboboxTuple[0]
            ders_listesi.append(comboBox.currentText())

        return ders_listesi  # Ders listesini döndür


    def dersleriYukle(self):
        try:
            with open(DERSLER_JSON_PATH, 'r', encoding='utf-8') as file:
                ders_data = json.load(file)
            return ders_data['dersler']
        except Exception as e:
            return []
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
        self.thread = HocaKaydetThread(self.hoca, self.data, self)
        self.thread.finished.connect(self.islemTamamlandi)  # İşlem bittiğinde çağrılacak fonksiyon
        self.thread.error.connect(self.hataMesajiGoster)  # Hata mesajı sinyalini bağla
        # ProgressDialog'u göster
        self.progressDialog.show()
        self.thread.start()  # Thread'i başlat

    def islemTamamlandi(self):
        # ProgressBar'ı gizle ve gerekli güncellemeleri yap
        self.progressDialog.hide()
        self.kaydetVeKapat()  # Kaydetme işlemini tamamla
    def hataMesajiGoster(self, message):
        # ProgressBar'ı gizle ve gerekli güncellemeleri yap
        self.progressDialog.hide()
        QMessageBox.warning(self, 'Hata', message)
    def sil(self):
        # Hocayı sil
        emin_mi = QMessageBox.question(self, 'Onay', 'Hocayı silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes and self.hoca:
            self.data['hocalar'].remove(self.hoca)
            self.kaydetVeKapat()
    def derslereHocayiEkle(self):
        secilen_dersler = self.secilenDersleriDondur()
        ad = self.unvanInput.currentText() + " " + self.adInput.text()
        kisaltma = hoca_kisaltma_olustur(ad)
        try:
            with open(DERSLER_JSON_PATH, 'r', encoding='utf-8') as file:
                dersler_data = json.load(file)
        except Exception as e:
            dersler_data = {'dersler': []}  # JSON yükleme yerine doğrudan bir sözlük atayın

        try:
            for ders in dersler_data.get("dersler", []):
                # Eğer ders seçilen dersler listesindeyse ve hoca bu dersi vermiyorsa, hocayı ekleyin
                if ders['ad'] in secilen_dersler and not any(hoca['kisaltma'] == kisaltma for hoca in ders.get("dersi_veren_hocalar", [])):
                    ders.setdefault("dersi_veren_hocalar", []).append({"ad": ad, "kisaltma": kisaltma})
                # Eğer ders seçilen dersler listesinde değilse ve hoca bu dersi veriyorsa, hocayı çıkarın
                elif ders['ad'] not in secilen_dersler:
                    ders["dersi_veren_hocalar"] = [hoca for hoca in ders.get("dersi_veren_hocalar", []) if hoca['kisaltma'] != kisaltma]

            with open(DERSLER_JSON_PATH, 'w', encoding='utf-8') as file:
                json.dump(dersler_data, file, ensure_ascii=False, indent=4)

        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya işlenirken bir hata oluştu: {e}')

    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            self.derslereHocayiEkle()
            with open(JSON_DOSYASI, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            self.parent.hocalariYenile()
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
