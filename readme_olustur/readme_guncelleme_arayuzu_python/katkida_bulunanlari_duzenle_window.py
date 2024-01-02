import locale
import json
from urllib.parse import urlparse
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QInputDialog,QDesktopWidget,QHBoxLayout, QPushButton, QMessageBox, QDialog, QLabel, QLineEdit, QScrollArea
from katkida_bulunan_ekle_window import KatkidaBulunanEkleWindow
from threadler import KatkiKaydetThread
from PyQt5.QtCore import Qt
from progress_dialog import CustomProgressDialog
JSON_YOLU = "../katkida_bulunanlar.json"
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
        self.title = 'Katkıda Bulunanları Ekle/Güncelle'
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setMinimumHeight(200)
        self.setMinimumWidth(600)
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.setStyleSheet("background-color: blue; color: white;")
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Ekle butonu
        self.ekleBtn = QPushButton("Ekle", self)
        self.ekleBtn.clicked.connect(self.acKatkidaBulunanEkle)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Yeşil arka plan
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
    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, katkida_bulunan in enumerate(self.data['katkida_bulunanlar']):
            widget = self.layout.itemAt(idx + 1).widget()
            katkida_bulunan_adi = katkida_bulunan['ad']
            if isinstance(widget, QPushButton):
                if query.lower() in katkida_bulunan_adi.lower():
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.data['katkida_bulunanlar']):
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
            self.katkidaBulunanSayisiLabel.setText(f'Toplam {len(self.data["katkida_bulunanlar"])} katkıda bulunan var.')  # Not sayısını etikette güncelle
    def jsonDosyasiniYukle(self):
        try:
            with open(JSON_YOLU, 'r', encoding='utf-8') as file:
                return json.load(file)
        except FileNotFoundError:
            return json.loads('{}')
    def butonlariYukle(self):
        # JSON dosyasını oku ve butonları oluştur
        self.data = self.jsonDosyasiniYukle()
        try:
            if 'katkida_bulunanlar' not in self.data:
                self.data['katkida_bulunanlar'] = []
            self.data['katkida_bulunanlar'] = sorted(
                        [kisi for kisi in self.data['katkida_bulunanlar'] if kisi['ad'].strip() and kisi['github_link'].strip()],
                        key=lambda kisi: locale.strxfrm(kisi['ad'].lower())
                    )


            katkidaBulunanSayisi = len(self.data['katkida_bulunanlar'])  # Toplam katkıda bulunan sayısı
            self.katkidaBulunanSayisiLabel = QLabel(f'Toplam {katkidaBulunanSayisi} katkıda bulunan var.')  # Sayıyı gösteren etiket
            self.katkidaBulunanSayisiLabel.setFixedHeight(20)
            self.layout.addWidget(self.katkidaBulunanSayisiLabel)

            for kisi in self.data['katkida_bulunanlar']:
                btn = QPushButton(kisi['ad'], self)
                btn.clicked.connect(lambda checked, a=kisi: self.duzenle(a))
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
        self.kisi = kisi
        self.data = data
        self.parent = parent
        self.title = "Katkıda Bulunanı Güncelle"
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        layout = QVBoxLayout(self)
        self.setMinimumSize(500, 200)
        self.resize(500, 200)

        # Ad ve GitHub Linki için giriş alanları
        self.ad_label = QLabel('Ad:')
        self.ad_input = QLineEdit(self.kisi['ad'])
        self.github_label = QLabel('GitHub Adı:')
        # Örnek bir GitHub linki
        github_link = self.kisi['github_link']

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
        self.kaydet_btn.setStyleSheet("background-color: green;")
        self.kaydet_btn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydet_btn)

        # Sil butonu
        self.sil_btn = QPushButton('Sil', self)
        self.sil_btn.setStyleSheet("background-color: red;")
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
    def sil(self):
        # Silme işlemini onayla
        emin_mi = QMessageBox.question(self, 'Onay', f'{self.kisi["ad"]} adlı kişiyi silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            try:
                # Kişiyi data listesinden sil
                index = self.data['katkida_bulunanlar'].index(self.kisi)  # Kişinin index'ini bul
                del self.data['katkida_bulunanlar'][index]  # Kişiyi listeden sil

                # JSON dosyasını güncelle (Eğer dosyaya kaydedilmesi gerekiyorsa)
                with open(JSON_YOLU, 'w',encoding='utf-8') as file:
                    json.dump(self.data, file, indent=4, ensure_ascii=False)

                # Ana penceredeki listeyi yenile
                self.parent.butonlariYenile()
                QMessageBox.information(self, 'Silindi', f'{self.kisi["ad"]} adlı kişi başarıyla silindi.')
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

            self.thread = KatkiKaydetThread(self.kisi, ad, github_kullanici_adi, self.data, JSON_YOLU,self)
            self.thread.finished.connect(self.islemSonucu)
            # ProgressDialog'u göster
            self.progressDialog.show()
            self.thread.start()
    def islemSonucu(self, success, message):
        self.progressDialog.hide()
        if success:
            QMessageBox.information(self, 'Başarılı', message)
            self.parent.butonlariYenile()  # Ana pencerenin butonlarını yenile
            self.close()
        else:
            QMessageBox.warning(self, 'Hata', message)