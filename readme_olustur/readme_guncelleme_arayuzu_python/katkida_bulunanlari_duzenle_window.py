import locale
import json
from urllib.parse import urlparse
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QInputDialog,QDesktopWidget,QHBoxLayout, QPushButton, QMessageBox, QDialog, QLabel, QLineEdit, QScrollArea
from katkida_bulunan_ekle_window import KatkidaBulunanEkleWindow
from threadler import KatkiKaydetThread
from PyQt5.QtCore import Qt
from progress_dialog import CustomProgressDialog
from degiskenler import *
from PyQt5.QtGui import QIcon
from metin_islemleri import kisaltMetin
from close_event import closeEventHandler
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

class KatkidaBulunanGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.is_programmatic_close = False
        self.title = 'Katkıda Bulunanları Ekle/Güncelle'
        # JSON dosyasını oku
        self.data = self.jsonDosyasiniYukle()
        if self.ilklendir():
            self.jsonDosyasiniKaydet()
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setMinimumHeight(200)
        self.setMinimumWidth(600)
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        # Filtreleme için arama kutusu
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Bölüm adı label
        self.bolumAdiLabel = QLabel('Bölüm Adı: ')
        self.mainLayout.addWidget(self.bolumAdiLabel)
        # Bölüm adı düzenleme butonu
        bolum_adi = self.data.get(BOLUM_ADI, VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ADI)
        aciklama = self.data.get(BOLUM_ACIKLAMASI, VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ACIKLAMASI)
        self.bolumAdiDuzenleBtn = QPushButton(kisaltMetin(bolum_adi), self)
        self.bolumAdiDuzenleBtn.setToolTip(bolum_adi)  # Tam metni araç ipucu olarak ekle
        self.bolumAdiDuzenleBtn.setStyleSheet(BASLIK_BUTON_STILI)
        self.bolumAdiDuzenleBtn.clicked.connect(self.bolumAdiDuzenle)
        self.mainLayout.addWidget(self.bolumAdiDuzenleBtn)
        # Bölüm açıklaması label
        self.bolumAciklamaLabel = QLabel('Bölüm Açıklaması: ')
        self.mainLayout.addWidget(self.bolumAciklamaLabel)
        # Bölüm açıklaması düzenleme butonu
        self.bolumAciklamaDuzenleBtn = QPushButton(kisaltMetin(aciklama), self)
        self.bolumAciklamaDuzenleBtn.setToolTip(aciklama)  # Tam metni araç ipucu olarak ekle
        self.bolumAciklamaDuzenleBtn.setStyleSheet(ACIKLAMA_BUTON_STILI)
        self.bolumAciklamaDuzenleBtn.clicked.connect(self.bolumAciklamasiDuzenle)
        self.mainLayout.addWidget(self.bolumAciklamaDuzenleBtn)
        # Ekle butonu
        self.ekleBtn = QPushButton("Katkıda Bulunan Ekle", self)
        self.ekleBtn.clicked.connect(self.acKatkidaBulunanEkle)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan
        self.mainLayout.addWidget(self.ekleBtn)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)
        
        # Butonları gösterecek widget
        self.scrollWidget = QWidget()
        self.layout = QVBoxLayout(self.scrollWidget)
        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.butonlariYukle()
    def bolumAdiDuzenle(self):
        # Bölüm adını düzenle
        text, ok = QInputDialog.getText(self, 'Bölüm Adı', 'Bölüm adı: ', QLineEdit.Normal, self.data[BOLUM_ADI])
        if ok:
            cevap = QMessageBox.question(self, 'Onay', f'Bölüm adını "{text}" olarak değiştirmek istediğine emin misin?', QMessageBox.Yes | QMessageBox.No)
            if cevap == QMessageBox.Yes:
                self.data[BOLUM_ADI] = text
                self.bolumAdiDuzenleBtn.setText(kisaltMetin(text))
                self.jsonDosyasiniKaydet()
                self.bolumAdiDuzenleBtn.setToolTip(text)
                QMessageBox.information(self, 'Başarılı', 'Bölüm adı başarıyla değiştirildi.')
            else:
                QMessageBox.information(self, 'İptal', 'Bölüm adı değiştirilmedi.')
    def bolumAciklamasiDuzenle(self):
        # Bölüm açıklamasını düzenle
        text, ok = QInputDialog.getMultiLineText(self, 'Bölüm Açıklaması', 'Bölüm açıklaması: ', self.data[BOLUM_ACIKLAMASI])
        if ok:
            cevap = QMessageBox.question(self, 'Onay', f'Bölüm açıklamasını "{text}" olarak değiştirmek istediğine emin misin?', QMessageBox.Yes | QMessageBox.No)
            if cevap == QMessageBox.Yes:
                self.data[BOLUM_ACIKLAMASI] = text
                self.bolumAciklamaDuzenleBtn.setText(kisaltMetin(text))
                self.jsonDosyasiniKaydet()
                self.bolumAciklamaDuzenleBtn.setToolTip(text)
                QMessageBox.information(self, 'Başarılı', 'Bölüm açıklaması başarıyla değiştirildi.')
            else:
                QMessageBox.information(self, 'İptal', 'Bölüm açıklaması değiştirilmedi.')
    def jsonDosyasiniKaydet(self):
        # JSON dosyasını güncelle
        with open(KATKIDA_BULUNANLAR_JSON_PATH, 'w', encoding='utf-8') as file:
            json.dump(self.data, file, indent=4, ensure_ascii=False)
    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, katkida_bulunan in enumerate(self.data[KATKIDA_BULUNANLAR]):
            widget = self.layout.itemAt(idx + 1).widget()
            katkida_bulunan_adi = katkida_bulunan[AD]
            if isinstance(widget, QPushButton):
                if query.lower() in katkida_bulunan_adi.lower():
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.data[KATKIDA_BULUNANLAR]):
            self.clearFilters(is_clicked=False)
            return
        self.katkidaBulunanSayisiLabel.setText(f'{size} sonuç bulundu.')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()
    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak kelime:')
            if ok:
                self.searchNotes(text)

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                        'Filtreleri temizlemek istediğinize emin misiniz?', 
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.layout.count()):
                widget = self.layout.itemAt(i).widget()
                if isinstance(widget, QPushButton):
                    widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.katkidaBulunanSayisiLabel.setText(f'Toplam {len(self.data[KATKIDA_BULUNANLAR])} katkıda bulunan var.')  # Not sayısını etikette güncelle
    def jsonDosyasiniYukle(self):
        try:
            with open(KATKIDA_BULUNANLAR_JSON_PATH, 'r', encoding='utf-8') as file:
                return json.load(file)
        except FileNotFoundError:
            return json.loads('{}')
    def ilklendir(self):
        ilklendirildi_mi = False
        if KATKIDA_BULUNANLAR not in self.data:
            self.data[KATKIDA_BULUNANLAR] = []
            ilklendirildi_mi = True
        if BOLUM_ADI not in self.data:
            self.data[BOLUM_ADI] = VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ADI
            ilklendirildi_mi = True
        if BOLUM_ACIKLAMASI not in self.data:
            self.data[BOLUM_ACIKLAMASI] = VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ACIKLAMASI
            ilklendirildi_mi = True
        return ilklendirildi_mi
    def butonlariYukle(self):
        # JSON dosyasını oku ve butonları oluştur
        self.data = self.jsonDosyasiniYukle()
        self.data[KATKIDA_BULUNANLAR] = sorted(
            [kisi for kisi in self.data[KATKIDA_BULUNANLAR] if kisi[AD].strip() and kisi[GITHUB_LINK].strip()],
            key=lambda kisi: locale.strxfrm(kisi[AD].lower())
        )
        try:
            katkidaBulunanSayisi = len(self.data[KATKIDA_BULUNANLAR])  # Toplam katkıda bulunan sayısı
            self.katkidaBulunanSayisiLabel = QLabel(f'Toplam {katkidaBulunanSayisi} katkıda bulunan var.')  # Sayıyı gösteren etiket
            self.layout.addWidget(self.katkidaBulunanSayisiLabel)

            for kisi in self.data[KATKIDA_BULUNANLAR]:
                btn = QPushButton(kisi[AD], self)
                btn.clicked.connect(lambda checked, a=kisi: self.duzenle(a))
                btn.setStyleSheet(GUNCELLE_BUTTON_STILI)
                self.layout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')

    def butonlariYenile(self):
        # Mevcut butonları temizle
        for i in reversed(range(self.layout.count())): 
            widgetToRemove = self.layout.itemAt(i).widget()
            self.layout.removeWidget(widgetToRemove)
            widgetToRemove.setParent(None)
        
        # Yeniden butonları yükle
        self.butonlariYukle()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
    def acKatkidaBulunanEkle(self):
        # Katkıda Bulunan Ekle penceresini aç
        self.katkidaBulunanEkleWindow = KatkidaBulunanEkleWindow(self)

    def duzenle(self, kisi):
        self.duzenlemePenceresi = KatkidaBulunanDuzenleWindow(kisi, self.data, self)
        self.duzenlemePenceresi.show()

class KatkidaBulunanDuzenleWindow(QDialog):
    def __init__(self, kisi, data, parent):
        super().__init__()
        self.is_programmatic_close = False
        self.kisi = kisi
        self.data = data
        self.parent = parent
        self.title = "Katkıda Bulunanı Güncelle"
        self.setModal(True)
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle(self.title)
        layout = QVBoxLayout(self)
        self.setMinimumSize(500, 200)
        self.resize(500, 200)

        # Ad ve GitHub Linki için giriş alanları
        self.ad_label = QLabel('Ad:')
        self.ad_input = QLineEdit(self.kisi[AD])
        self.github_label = QLabel('GitHub Adı:')
        # Örnek bir GitHub linki
        github_link = self.kisi[GITHUB_LINK]

        # URL'yi ayrıştır
        parsed_link = urlparse(github_link)

        # Path'i '/' karakterine göre böl ve son parçayı al (genellikle kullanıcı adı)
        github_user = parsed_link.path.strip('/').split('/')[-1]
        self.github_input = QLineEdit(github_user)

        # Butonlar için yatay layout
        buttonsLayout = QHBoxLayout()
        self.progressDialog = CustomProgressDialog('Kontrol Ediliyor...', self)
        self.progressDialog.close()
        # Değişiklikleri Kaydet butonu
        self.kaydet_btn = QPushButton('Değişiklikleri Kaydet', self)
        self.kaydet_btn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydet_btn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydet_btn)

        # Sil butonu
        self.sil_btn = QPushButton('Sil', self)
        self.sil_btn.setStyleSheet(SIL_BUTONU_STILI)
        self.sil_btn.clicked.connect(self.sil)
        buttonsLayout.addWidget(self.sil_btn)

        # Arayüze elemanları ekle
        layout.addWidget(self.ad_label)
        layout.addWidget(self.ad_input)
        layout.addWidget(self.github_label)
        layout.addWidget(self.github_input)
        layout.addLayout(buttonsLayout)  # Butonlar için yatay layout'u ekle

        self.setLayout(layout)
        self.center()
        self.show()
    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close)
    def sil(self):
        # Silme işlemini onayla
        emin_mi = QMessageBox.question(self, 'Onay', f'{self.kisi[AD]} adlı kişiyi silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            try:
                # Kişiyi data listesinden sil
                index = self.data[KATKIDA_BULUNANLAR].index(self.kisi)  # Kişinin index'ini bul
                del self.data[KATKIDA_BULUNANLAR][index]  # Kişiyi listeden sil

                # JSON dosyasını güncelle (Eğer dosyaya kaydedilmesi gerekiyorsa)
                with open(KATKIDA_BULUNANLAR_JSON_PATH, 'w',encoding='utf-8') as file:
                    json.dump(self.data, file, indent=4, ensure_ascii=False)

                # Ana penceredeki listeyi yenile
                self.parent.butonlariYenile()
                QMessageBox.information(self, 'Silindi', f'{self.kisi[AD]} adlı kişi başarıyla silindi.')
                self.is_programmatic_close = True
                self.close()

            except ValueError:
                # Eğer kişi listede bulunamazsa
                QMessageBox.critical(self, 'Hata', 'Silinecek kişi bulunamadı.')

    def center(self):
        # Pencereyi ekranın ortasına al
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def kaydet(self):
        emin_mi = QMessageBox.question(self, 'Onay', 'Değişiklikleri kaydetmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        
        if emin_mi == QMessageBox.Yes:
            ad = self.ad_input.text()
            github_kullanici_adi = self.github_input.text()

            self.thread = KatkiKaydetThread(self.kisi, ad, github_kullanici_adi, self.data, KATKIDA_BULUNANLAR_JSON_PATH,self)
            self.thread.finished.connect(self.islemSonucu)
            # ProgressDialog'u göster
            self.progressDialog.show()
            self.thread.start()
    def islemSonucu(self, success, message):
        self.progressDialog.hide()
        if success:
            QMessageBox.information(self, 'Başarılı', message)
            self.parent.butonlariYenile()  # Ana pencerenin butonlarını yenile
            self.is_programmatic_close = True
            self.close()
        else:
            QMessageBox.warning(self, 'Hata', message)