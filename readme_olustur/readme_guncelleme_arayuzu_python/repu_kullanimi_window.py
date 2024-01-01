from PyQt5.QtWidgets import QWidget,QScrollArea,QDialog, QLabel, QLineEdit, QInputDialog, QVBoxLayout, QPushButton, QApplication, QInputDialog, QMessageBox, QHBoxLayout
import json
from PyQt5.QtCore import Qt
class TalimatDialog(QDialog):
    def __init__(self, json_dosyasi='../repo_kullanimi.json'):
        super().__init__()
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.setModal(True)
        self.initUI()
    def initUI(self):
        self.setWindowTitle("Talimat Ekle/Düzenle")
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.setStyleSheet("background-color: blue; color: white;")  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.layout.addWidget(self.clearFiltersButton)
        self.talimatSayisiLabel = QLabel(self)
        self.talimatSayisiLabel.setText(f'Toplam {len(self.repo_data["talimatlar"])} talimat')
        self.layout.addWidget(self.talimatSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.layout.addWidget(self.scrollArea)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)

        # ScrollArea için minimum boyutu belirle
        self.scrollArea.setMinimumSize(580, 300)

        self.yenile()
        
        # Ekle butonunu ekle
        ekleBtn = QPushButton("Talimat Ekle", self)
        ekleBtn.setStyleSheet("background-color: green; color: white;")
        ekleBtn.clicked.connect(self.talimatEkle)
        self.layout.addWidget(ekleBtn)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak talimat:')
            if ok:
                self.searchTalimat(text)

    def searchTalimat(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, kavram in enumerate(self.repo_data['talimatlar']):
            layout = self.scrollLayout.itemAt(idx)
            if isinstance(layout, QHBoxLayout):
                match = query.lower() in kavram.lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data['talimatlar']):
            self.clearFilters(is_clicked=False)
            return
        self.talimatSayisiLabel.setText(f'{size} talimat bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                    'Filtreleri temizlemek istediğinize emin misiniz?', 
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.scrollLayout.count()):
                layout = self.scrollLayout.itemAt(i)
                if isinstance(layout, QHBoxLayout):  # Burayı QHBoxLayout olarak değiştirdik
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.talimatSayisiLabel.setText(f'Toplam {len(self.repo_data["talimatlar"])} talimat')  # kavram sayısını etikette güncelle
   
    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, 'r', encoding='utf-8') as file:
                return json.load(file)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
            return None

    def talimatListele(self):
        # Mevcut talimatları temizle
        self.temizle()
        self.talimatSayisiLabel.setText(f'Toplam {len(self.repo_data["talimatlar"])} talimat')
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, talimat in enumerate(self.repo_data["talimatlar"]):
            talimatLayout = QHBoxLayout()
            
            talimatBtn = QPushButton(talimat, self)
            talimatBtn.clicked.connect(lambda checked, index=i: self.talimatDuzenle(index))
            talimatBtn.setStyleSheet("background-color: lightgreen; color: black;")
            talimatLayout.addWidget(talimatBtn, 3)
            talimatBtn.setMaximumWidth(500)
            
            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet("background-color: red; color: white;")
            silBtn.clicked.connect(lambda checked, index=i: self.talimatSil(index))
            silBtn.setFixedWidth(50)
            talimatLayout.addWidget(silBtn, 1)
            
            self.scrollLayout.addLayout(talimatLayout)

    def temizle(self):
        while self.scrollLayout.count():
            layoutItem = self.scrollLayout.takeAt(0)
            if layoutItem.widget():
                layoutItem.widget().deleteLater()
            elif layoutItem.layout():
                self._clearLayout(layoutItem.layout())

    def _clearLayout(self, layout):
        while layout.count():
            item = layout.takeAt(0)
            widget = item.widget()
            if widget:
                widget.deleteLater()
            else:
                self._clearLayout(item.layout())
    def yenile(self):
        self.talimatListele()

    def talimatDuzenle(self, index):
        # Düzenleme dialogunu aç
        talimat = self.repo_data["talimatlar"][index]
        yeni_talimat, ok = QInputDialog.getText(self, "Talimat Düzenle", "Talimat:", QLineEdit.Normal, talimat)
        if ok and yeni_talimat:
            self.repo_data["talimatlar"][index] = yeni_talimat
            self.jsonGuncelle()


    def talimatSil(self, index):
        emin_mi = QMessageBox.question(self, 'Onay', 'Bu talimatı silmek istediğinize emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            del self.repo_data["talimatlar"][index]
            self.jsonGuncelle()

    def talimatEkle(self):
        yeni_talimat, ok = QInputDialog.getText(self, "Talimat Ekle", "Yeni Talimat:")
        if ok and yeni_talimat:
            self.repo_data["talimatlar"].append(yeni_talimat)
            self.jsonGuncelle()

    def jsonGuncelle(self):
        with open(self.json_dosyasi, 'w', encoding='utf-8') as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()
class KavramDetayDialog(QDialog):
    def __init__(self, parent, repo_data, kavram_index, kavram_adi=None):
        super().__init__(parent)
        self.repo_data = repo_data
        self.kavram_index = kavram_index
        self.kavram_adi = kavram_adi
        self.kavram = self.repo_data["kavramlar"][self.kavram_index]
        self.setModal(True)
        self.initUI()

    def initUI(self):
        if self.kavram_adi is None:
            self.setWindowTitle("Kavram Açıklamaları Düzenle")
        else:
            self.setWindowTitle(f"{self.kavram_adi} Açıklamaları Düzenle")
        self.layout = QVBoxLayout(self)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.scrollArea.setMinimumSize(650, 300)
        self.layout.addWidget(self.scrollArea)

        self.aciklamaListele()

        self.ekleBtn = QPushButton("Açıklama Ekle", self)
        self.ekleBtn.setStyleSheet("background-color: green; color: white;")
        self.ekleBtn.clicked.connect(self.aciklamaEkle)
        self.layout.addWidget(self.ekleBtn)

    def temizle(self):
        while self.scrollLayout.count():
            layoutItem = self.scrollLayout.takeAt(0)
            if layoutItem.widget():
                layoutItem.widget().deleteLater()
            elif layoutItem.layout():
                # Eğer layout içinde başka bir layout varsa, onu ve içindekileri temizle
                self.temizleIcLayout(layoutItem.layout())

    def temizleIcLayout(self, layout):
        while layout.count():
            item = layout.takeAt(0)
            widget = item.widget()
            if widget:
                widget.deleteLater()
            elif item.layout():
                self.temizleIcLayout(item.layout())

    def aciklamaListele(self):
        self.temizle()
        for i, aciklama in enumerate(self.kavram["aciklamalar"]):
            aciklamaLayout = QHBoxLayout()

            aciklamaLabel = QLabel(aciklama, self)
            aciklamaLabel.setWordWrap(True)
            aciklamaLabel.setFixedWidth(420)  # Maksimum yükseklik değerini istediğiniz bir değere ayarlayın
            aciklamaLayout.addWidget(aciklamaLabel)


            duzenleBtn = QPushButton("Düzenle", self)
            duzenleBtn.setStyleSheet("background-color: green; color: white;")
            duzenleBtn.clicked.connect(lambda checked, index=i: self.aciklamaDuzenle(index))
            aciklamaLayout.addWidget(duzenleBtn)

            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet("background-color: red; color: white;")
            silBtn.clicked.connect(lambda checked, index=i: self.aciklamaSil(index))
            aciklamaLayout.addWidget(silBtn)

            self.scrollLayout.addLayout(aciklamaLayout)

    def aciklamaDuzenle(self, index):
        eski_aciklama = self.kavram["aciklamalar"][index]
        yeni_aciklama, ok = QInputDialog.getText(self, "Açıklama Düzenle", "Açıklama:", text=eski_aciklama)
        
        if ok and yeni_aciklama:
            # Kullanıcıya onay sorusu sor
            emin_mi = QMessageBox.question(self, 'Onay', 'Açıklamayı değiştirmek istediğinizden emin misiniz?',
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

            if emin_mi == QMessageBox.Yes:
                # Kullanıcı onay verirse, değişikliği yap
                self.kavram["aciklamalar"][index] = yeni_aciklama
                self.parent().jsonGuncelle()
                self.aciklamaListele()


    def aciklamaSil(self, index):
        emin_mi = QMessageBox.question(self, 'Onay', 'Bu açıklamayı silmek istediğinize emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            del self.kavram["aciklamalar"][index]
            self.parent().jsonGuncelle()
            self.aciklamaListele()

    def aciklamaEkle(self):
        yeni_aciklama, ok = QInputDialog.getText(self, "Açıklama Ekle", "Yeni Açıklama:")
        if ok and yeni_aciklama:
            self.kavram["aciklamalar"].append(yeni_aciklama)
            self.parent().jsonGuncelle()
            self.aciklamaListele()
class KavramDialog(QDialog):
    def __init__(self, json_dosyasi='../repo_kullanimi.json'):
        super().__init__()
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.setModal(True)
        self.initUI()
        
    def initUI(self):
        self.setWindowTitle("Kavram Ekle/Düzenle")
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.setStyleSheet("background-color: blue; color: white;")  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.layout.addWidget(self.clearFiltersButton)
        self.kavramSayisiLabel = QLabel(self)
        self.layout.addWidget(self.kavramSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.layout.addWidget(self.scrollArea)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        # ScrollArea için minimum boyutu belirle
        self.scrollArea.setMinimumSize(650, 300)
        self.yenile()

        # Ekle butonunu ekle
        ekleBtn = QPushButton("Kavram Ekle", self)
        ekleBtn.setStyleSheet("background-color: green; color: white;")
        ekleBtn.clicked.connect(self.kavramEkle)
        self.layout.addWidget(ekleBtn)

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, 'r', encoding='utf-8') as file:
                return json.load(file)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
            return None
    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak açıklama:')
            if ok:
                self.searchKavram(text)

    def searchKavram(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, kavram in enumerate(self.repo_data['kavramlar']):
            layout = self.scrollLayout.itemAt(idx)
            kavram = kavram["kavram"]
            if isinstance(layout, QHBoxLayout):
                match = query.lower() in kavram.lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data['kavramlar']):
            self.clearFilters(is_clicked=False)
            return
        self.kavramSayisiLabel.setText(f'{size} kavram bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                    'Filtreleri temizlemek istediğinize emin misiniz?', 
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.scrollLayout.count()):
                layout = self.scrollLayout.itemAt(i)
                if isinstance(layout, QHBoxLayout):  # Burayı QHBoxLayout olarak değiştirdik
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.kavramSayisiLabel.setText(f'Toplam {len(self.repo_data["kavramlar"])} kavram')  # kavram sayısını etikette güncelle
   
    def kavramListele(self):
        self.temizle()
        self.kavramSayisiLabel.setText(f'Toplam {len(self.repo_data["kavramlar"])} kavram')
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, kavram in enumerate(self.repo_data["kavramlar"]):
            kavramLayout = QHBoxLayout()
            
            # Kavram adını gösteren buton
            kavramBtn = QPushButton(kavram["kavram"], self)
            kavramBtn.clicked.connect(lambda checked, index=i: self.kavramDuzenle(index))
            kavramBtn.setStyleSheet("background-color: lightgreen; color: black;")
            kavramBtn.setMaximumWidth(500)
            kavramLayout.addWidget(kavramBtn, 3)

            # Kavramı düzenleme butonu
            duzenleBtn = QPushButton("Adı Düzenle", self)
            duzenleBtn.setStyleSheet("background-color: orange; color: white;")
            duzenleBtn.clicked.connect(lambda checked, index=i: self.kavramAdiDuzenle(index))
            duzenleBtn.setFixedWidth(70)
            kavramLayout.addWidget(duzenleBtn, 1)
            
            # Kavramı silme butonu
            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet("background-color: red; color: white;")
            silBtn.clicked.connect(lambda checked, index=i: self.kavramSil(index))
            silBtn.setFixedWidth(50)
            kavramLayout.addWidget(silBtn, 1)
            
            self.scrollLayout.addLayout(kavramLayout)

    def kavramAdiDuzenle(self, index):
        eski_kavram = self.repo_data["kavramlar"][index]["kavram"]
        yeni_kavram, ok = QInputDialog.getText(self, "Kavram Adı Düzenle", "Kavram Adı:", text=eski_kavram)
        
        if ok and yeni_kavram:
            emin_mi = QMessageBox.question(self, 'Onay', 'Kavram adını değiştirmek istediğinizden emin misiniz?',
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
            if emin_mi == QMessageBox.Yes:
                self.repo_data["kavramlar"][index]["kavram"] = yeni_kavram
                self.jsonGuncelle()
                self.kavramListele()

    def temizle(self):
        while self.scrollLayout.count():
            layoutItem = self.scrollLayout.takeAt(0)
            if layoutItem.widget():
                layoutItem.widget().deleteLater()
            elif layoutItem.layout():
                self._clearLayout(layoutItem.layout())
    def _clearLayout(self, layout):
        while layout.count():
            item = layout.takeAt(0)
            widget = item.widget()
            if widget:
                widget.deleteLater()
            else:
                self._clearLayout(item.layout())
    def yenile(self):
        self.kavramListele()

    def kavramDuzenle(self, index):
        # Katkıda Bulunan Güncelle penceresini aç
        self.yazarinNotlariWindow = KavramDetayDialog(self, self.repo_data, index, self.repo_data["kavramlar"][index]["kavram"])
        self.yazarinNotlariWindow.show()

    def kavramSil(self, index):
        emin_mi = QMessageBox.question(self, 'Onay', 'Bu kavramı silmek istediğinize emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            del self.repo_data["kavramlar"][index]
            self.jsonGuncelle()

    def kavramEkle(self):
        yeni_kavram, ok = QInputDialog.getText(self, "Kavram Ekle", "Yeni Kavram:")
        if ok and yeni_kavram:
            self.repo_data["kavramlar"].append({"kavram": yeni_kavram, "aciklamalar": []})
            self.jsonGuncelle()

    def jsonGuncelle(self):
        with open(self.json_dosyasi, 'w', encoding='utf-8') as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()

class AciklamaDialog(QDialog):
    def __init__(self, json_dosyasi='../repo_kullanimi.json'):
        super().__init__()
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.setModal(True)
        self.initUI()
        
    def initUI(self):
        self.setWindowTitle("Açıklama Ekle/Düzenle")
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.setStyleSheet("background-color: blue; color: white;")  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.layout.addWidget(self.clearFiltersButton)
        self.aciklamaSayisiLabel = QLabel(self)
        self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data["aciklamalar"])} açıklama')
        self.layout.addWidget(self.aciklamaSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.layout.addWidget(self.scrollArea)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.scrollArea.setMinimumSize(580, 300)
        self.yenile()

        # Ekle butonunu ekle
        ekleBtn = QPushButton("Açıklama Ekle", self)
        ekleBtn.setStyleSheet("background-color: green; color: white;")
        ekleBtn.clicked.connect(self.aciklamaEkle)
        self.layout.addWidget(ekleBtn)

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, 'r', encoding='utf-8') as file:
                return json.load(file)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
            return None

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak açıklama:')
            if ok:
                self.searchAciklama(text)

    def searchAciklama(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, aciklama in enumerate(self.repo_data['aciklamalar']):
            layout = self.scrollLayout.itemAt(idx)
            if isinstance(layout, QHBoxLayout):
                match = query.lower() in aciklama.lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data['aciklamalar']):
            self.clearFilters(is_clicked=False)
            return
        self.aciklamaSayisiLabel.setText(f'{size} açıklama bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                    'Filtreleri temizlemek istediğinize emin misiniz?', 
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.scrollLayout.count()):
                layout = self.scrollLayout.itemAt(i)
                if isinstance(layout, QHBoxLayout):  # Burayı QHBoxLayout olarak değiştirdik
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data["aciklamalar"])} açıklama')  # Açıklama sayısını etikette güncelle self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data["aciklamalar"])} açıklama')  # Açıklama sayısını etikette güncelle
    def aciklamaListele(self):
        self.temizle()
        self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data["aciklamalar"])} açıklama')  # Açıklama sayısını etikette güncelle self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data["aciklamalar"])} açıklama')  # Açıklama sayısını etikette güncelle
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, aciklama in enumerate(self.repo_data["aciklamalar"]):
            aciklamaLayout = QHBoxLayout()
            
            aciklamaBtn = QPushButton(aciklama, self)
            aciklamaBtn.clicked.connect(lambda checked, index=i: self.aciklamaDuzenle(index))
            aciklamaBtn.setStyleSheet("background-color: lightgreen; color: black;")
            aciklamaLayout.addWidget(aciklamaBtn, 3)
            aciklamaBtn.setMaximumWidth(500)
            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet("background-color: red; color: white;")
            silBtn.clicked.connect(lambda checked, index=i: self.aciklamaSil(index))
            silBtn.setFixedWidth(50)
            aciklamaLayout.addWidget(silBtn, 1)
            
            self.scrollLayout.addLayout(aciklamaLayout)

    def temizle(self):
        while self.scrollLayout.count():
            layoutItem = self.scrollLayout.takeAt(0)
            if layoutItem.widget():
                layoutItem.widget().deleteLater()
            elif layoutItem.layout():
                self._clearLayout(layoutItem.layout())
    def _clearLayout(self, layout):
        while layout.count():
            item = layout.takeAt(0)
            widget = item.widget()
            if widget:
                widget.deleteLater()
            else:
                self._clearLayout(item.layout())

    def yenile(self):
        self.aciklamaListele()
        self.adjustSize()  # Pencere boyutunu içeriklere göre ayarla

    def aciklamaDuzenle(self, index):
        aciklama = self.repo_data["aciklamalar"][index]
        yeni_aciklama, ok = QInputDialog.getText(self, "Açıklama Düzenle", "Açıklama:", QLineEdit.Normal, aciklama)
        if ok and yeni_aciklama:
            self.repo_data["aciklamalar"][index] = yeni_aciklama
            self.jsonGuncelle()

    def aciklamaSil(self, index):
        emin_mi = QMessageBox.question(self, 'Onay', 'Bu açıklamayı silmek istediğinize emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            del self.repo_data["aciklamalar"][index]
            self.jsonGuncelle()

    def aciklamaEkle(self):
        yeni_aciklama, ok = QInputDialog.getText(self, "Açıklama Ekle", "Yeni Açıklama:")
        if ok and yeni_aciklama:
            self.repo_data["aciklamalar"].append(yeni_aciklama)
            self.jsonGuncelle()

    def jsonGuncelle(self):
        with open(self.json_dosyasi, 'w', encoding='utf-8') as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()

class RepoKullanimiDialog(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()
        
    def initUI(self):
        self.setWindowTitle("Repo Kullanımı Düzenleme")
        layout = QVBoxLayout(self)

        # Talimat Ekle/Düzenle butonu
        talimatBtn = QPushButton('Talimat Ekle/Düzenle', self)
        talimatBtn.clicked.connect(self.acTalimatDialog)
        talimatBtn.setStyleSheet("background-color: lightblue; color: black;")  # Mavi renk
        layout.addWidget(talimatBtn)

        # Kavram Ekle/Düzenle butonu
        kavramBtn = QPushButton('Kavram Ekle/Düzenle', self)
        kavramBtn.clicked.connect(self.acKavramDialog)
        kavramBtn.setStyleSheet("background-color: lightgreen; color: black;")  # Yeşil renk
        layout.addWidget(kavramBtn)

        # Açıklama Ekle/Düzenle butonu
        aciklamaBtn = QPushButton('Açıklama Ekle/Düzenle', self)
        aciklamaBtn.clicked.connect(self.acAciklamaDialog)
        aciklamaBtn.setStyleSheet("background-color: lightcoral; color: black;")  # Kırmızı renk
        layout.addWidget(aciklamaBtn)

    def acTalimatDialog(self):
        dialog = TalimatDialog()
        dialog.exec_()

    def acKavramDialog(self):
        dialog = KavramDialog()
        dialog.exec_()

    def acAciklamaDialog(self):
        dialog = AciklamaDialog()
        dialog.exec_()