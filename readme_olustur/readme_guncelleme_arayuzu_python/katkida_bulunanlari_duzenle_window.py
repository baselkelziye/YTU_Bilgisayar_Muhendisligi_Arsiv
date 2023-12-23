import requests
import json
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QPushButton, QMessageBox, QDialog, QLabel, QTextEdit, QScrollArea
from katkida_bulunan_ekle_window import KatkidaBulunanEkleWindow
JSON_YOLU = "../katkida_bulunanlar.json"


class KatkidaBulunanGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Katkıda Bulunanları Güncelle')
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
        self.katkidaBulunanEkleWindow = KatkidaBulunanEkleWindow()
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
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Katkıda Bulunanı Düzenle')
        layout = QVBoxLayout(self)

        self.ad_label = QLabel('Ad:')
        self.ad_input = QTextEdit(self.kisi['ad'])
        self.github_label = QLabel('GitHub Linki:')
        self.github_input = QTextEdit(self.kisi['github_link'])
        self.kaydet_btn = QPushButton('Değişiklikleri Kaydet', self)
        self.kaydet_btn.clicked.connect(self.kaydet)

        layout.addWidget(self.ad_label)
        layout.addWidget(self.ad_input)
        layout.addWidget(self.github_label)
        layout.addWidget(self.github_input)
        layout.addWidget(self.kaydet_btn)

        self.setLayout(layout)

    def kaydet(self):
        # Değişiklikleri onayla ve kaydet
        emin_mi = QMessageBox.question(self, 'Onay', 'Değişiklikleri kaydetmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        
        if emin_mi == QMessageBox.Yes:
            yeni_github_link = self.github_input.toPlainText().strip() 
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
            self.kisi['ad'] = self.ad_input.toPlainText().strip() 
            self.kisi['github_link'] = yeni_github_link
            try:
                with open(JSON_YOLU, 'w') as file:
                    json.dump(self.data, file, ensure_ascii=False, indent=4)
                QMessageBox.information(self, 'Başarılı', 'Katkıda bulunan güncellendi!')
                self.parent.butonlariYenile()  # Ana pencerenin butonlarını yenile
                self.close()
            except Exception as e:
                QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
