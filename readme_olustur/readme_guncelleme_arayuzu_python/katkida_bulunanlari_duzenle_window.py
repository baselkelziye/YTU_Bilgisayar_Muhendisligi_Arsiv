import requests
import json
from PyQt5.QtWidgets import QWidget, QVBoxLayout,QDesktopWidget,QHBoxLayout, QPushButton, QMessageBox, QDialog, QLabel, QLineEdit, QScrollArea
from katkida_bulunan_ekle_window import KatkidaBulunanEkleWindow
JSON_YOLU = "../katkida_bulunanlar.json"


class KatkidaBulunanGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.title = 'Katkıda Bulunanları Ekle/Güncelle'
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(100, 100, 600, 400)  # Pencere boyutunu ayarla

        self.mainLayout = QVBoxLayout(self)  # Ana layout

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
    def butonlariYukle(self):
        # JSON dosyasını oku ve butonları oluştur
        try:
            with open(JSON_YOLU, 'r') as file:
                self.data = json.load(file)
                for kisi in self.data['katkida_bulunanlar']:
                    btn = QPushButton(kisi['ad'], self)
                    btn.clicked.connect(lambda checked, a=kisi: self.duzenle(a))
                    self.layout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
    def acKatkidaBulunanEkle(self):
        # Katkıda Bulunan Ekle penceresini aç
        self.katkidaBulunanEkleWindow = KatkidaBulunanEkleWindow(self)
        self.katkidaBulunanEkleWindow.show()
    def butonlariYenile(self):
        # Mevcut butonları temizle
        for i in reversed(range(self.layout.count())): 
            widgetToRemove = self.layout.itemAt(i).widget()
            self.layout.removeWidget(widgetToRemove)
            widgetToRemove.setParent(None)
        
        # Yeniden butonları yükle
        self.butonlariYukle()

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
        self.github_label = QLabel('GitHub Linki:')
        self.github_input = QLineEdit(self.kisi['github_link'])

        # Butonlar için yatay layout
        buttonsLayout = QHBoxLayout()

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
                with open(JSON_YOLU, 'w') as file:
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
        # Değişiklikleri onayla ve kaydet
        emin_mi = QMessageBox.question(self, 'Onay', 'Değişiklikleri kaydetmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        
        if emin_mi == QMessageBox.Yes:
            yeni_github_link = self.github_input.text()
            # Linkin varlığını kontrol et
            try:
                response = requests.get(yeni_github_link)
                if response.status_code == 404:
                    QMessageBox.warning(self, 'Hata', 'GitHub linki geçerli değil!')
                    return
            except requests.exceptions.RequestException as e:
                QMessageBox.critical(self, 'Hata', f'GitHub linki kontrol edilirken bir hata oluştu: {e}')
                return

            # Değişiklikleri uygula ve JSON dosyasını güncelle
            self.kisi['ad'] = self.ad_input.text()
            self.kisi['github_link'] = yeni_github_link
            try:
                with open(JSON_YOLU, 'w') as file:
                    json.dump(self.data, file, ensure_ascii=False, indent=4)
                QMessageBox.information(self, 'Başarılı', 'Katkıda bulunan güncellendi!')
                self.parent.butonlariYenile()  # Ana pencerenin butonlarını yenile
                self.close()
            except Exception as e:
                QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
