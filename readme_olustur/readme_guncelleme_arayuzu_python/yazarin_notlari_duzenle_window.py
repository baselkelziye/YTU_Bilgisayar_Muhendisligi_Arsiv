import sys
import json
from PyQt5.QtWidgets import QDialog,QVBoxLayout, QInputDialog,QLabel, QDesktopWidget, QWidget, QPushButton, QHBoxLayout, QMessageBox, QTextEdit, QApplication, QScrollArea
from PyQt5.QtCore import Qt
from degiskenler import *
from metin_islemleri import kisaltMetin
from PyQt5.QtGui import QIcon
class YazarinNotlariWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle('Yazarın Notları Ekle/Düzenle')
        self.setMinimumSize(500, 200)  # Pencerenin en küçük olabileceği boyutu ayarlayın
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Not ekleme butonu
        self.ekleBtn = QPushButton('Not Ekle', self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan, beyaz yazı
        self.ekleBtn.clicked.connect(self.notEkle)
        self.mainLayout.addWidget(self.ekleBtn)  # Ana layout'a ekle butonunu ekle

        # Not sayısını gösteren etiket
        self.notSayisiLabel = QLabel('Toplam 0 not')
        self.notSayisiLabel.setFixedHeight(20)
        self.mainLayout.addWidget(self.notSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)

        # Notları gösterecek iç içe geçmiş widget'lar oluştur
        self.scrollWidget = QWidget()
        self.notlarLayout = QVBoxLayout(self.scrollWidget)  # Notlar için QVBoxLayout

        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.notlariYukle()
    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak kelime:')
            if ok:
                self.searchNotes(text)
    # Filtreleri temizleme fonksiyonu
    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                    'Filtreleri temizlemek istediğinize emin misiniz?', 
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.notlarLayout.count()):
                widget = self.notlarLayout.itemAt(i).widget()
                if isinstance(widget, QPushButton):
                    widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.notSayisiLabel.setText(f'Toplam {len(self.data[ACIKLAMALAR])} not')  # Not sayısını etikette güncelle
    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, not_ in enumerate(self.data[ACIKLAMALAR]):
            widget = self.notlarLayout.itemAt(idx).widget()
            if isinstance(widget, QPushButton):
                if query.lower() in not_.lower():
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.data[ACIKLAMALAR]):
            self.clearFilters(is_clicked=False)
            return
        self.notSayisiLabel.setText(f'{size} not bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()
    def jsonDosyasiniYukle(self):
        try:
            with open(YAZARIN_NOTLARI_JSON_PATH, 'r', encoding='utf-8') as file:
                return json.load(file)
        except Exception as e:
            return json.loads('{}')
    def notlariYukle(self):
        self.data = self.jsonDosyasiniYukle()
        try:
            if ACIKLAMALAR not in self.data:
                self.data[ACIKLAMALAR] = []
            if BASLIK not in self.data:
                self.data[BASLIK] = 'Yazarın Notları'
            not_sayisi = len(self.data[ACIKLAMALAR])  # Not sayısını hesapla
            self.notSayisiLabel.setText(f'Toplam {not_sayisi} not')  # Not sayısını etikette güncelle

            for idx, not_ in enumerate(self.data[ACIKLAMALAR]):
                btn = QPushButton(f"Not {idx + 1}: {kisaltMetin(not_)}", self.scrollWidget)  # İlk 30 karakteri göster
                btn.setToolTip(not_)  # Tam metni araç ipucu olarak ekle
                btn.clicked.connect(lambda checked, i=idx: self.notDuzenle(i))
                self.notlarLayout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')




    def notlariYenile(self):
        # Sadece notları içeren layout'u temizle
        for i in reversed(range(self.notlarLayout.count())): 
            widgetToRemove = self.notlarLayout.itemAt(i).widget()
            self.notlarLayout.removeWidget(widgetToRemove)
            widgetToRemove.setParent(None)
        self.notlariYukle()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle

    def notEkle(self):
        self.duzenlemePenceresi = NotDuzenleWindow(None, self.data, self)
        self.duzenlemePenceresi.show()

    def notDuzenle(self, idx):
        self.duzenlemePenceresi = NotDuzenleWindow(idx, self.data, self)
        self.duzenlemePenceresi.show()

class NotDuzenleWindow(QDialog):
    def __init__(self, idx, data, parent):
        super().__init__()
        self.idx = idx
        self.data = data
        self.parent = parent
        self.setModal(True)
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        if self.idx is not None:  # Düzenleme modunda
            self.setWindowTitle('Not Düzenle')
        else:
            self.setWindowTitle('Not Ekle')
        self.resize(400, 300)  # Pencereyi daha büyük aç
        self.layout = QVBoxLayout(self)

        # QTextEdit ile çok satırlı metin alanı oluştur
        self.notInput = QTextEdit(self)
        if self.idx is not None:  # Düzenleme modunda
            self.notInput.setText(self.data[ACIKLAMALAR][self.idx])
        self.layout.addWidget(self.notInput)

        # Butonları yan yana koymak için QHBoxLayout kullan
        buttonLayout = QHBoxLayout()

        # Kaydet butonu
        if self.idx is not None:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)
        buttonLayout.addWidget(self.kaydetBtn)

        if self.idx is not None:  # Var olan bir not düzenleniyorsa sil butonunu göster
            # Sil butonu
            self.silBtn = QPushButton('Notu Sil', self)
            self.silBtn.clicked.connect(self.notSil)
            self.silBtn.setStyleSheet(SIL_BUTONU_STILI)
            buttonLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonLayout)  # Buton düzenini ana düzene ekle
        self.center()  # Pencereyi ekranın merkezine yerleştir.

    def center(self):
        # Pencereyi ekranın ortasına al
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def kaydet(self):
        yeni_not = self.notInput.toPlainText().strip() 
        if not yeni_not:  # Boş not kontrolü
            QMessageBox.warning(self, 'Hata', 'Not boş olamaz!')
            return
        if self.idx is not None:
            emin_mi = QMessageBox.question(self, 'Onay', 'Değişiklikleri kaydetmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        else:
            emin_mi = QMessageBox.question(self, 'Onay', 'Eklemek istediğine emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            yeni_not = self.notInput.toPlainText().strip()
            if self.idx is None:  # Ekleme modunda
                self.data[ACIKLAMALAR].append(yeni_not)
            else:  # Düzenleme modunda
                self.data[ACIKLAMALAR][self.idx] = yeni_not

            try:
                with open(YAZARIN_NOTLARI_JSON_PATH, 'w',encoding='utf-8') as file:
                    json.dump(self.data, file, ensure_ascii=False, indent=4)
                QMessageBox.information(self, 'Başarılı', 'Yazarın notları güncellendi!')
                self.parent.notlariYenile()
                self.close()
            except Exception as e:
                QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
    def notSil(self):
        # Not silme işlevi
        if self.idx is not None:
            emin_mi = QMessageBox.question(self, 'Onay', 'Notu silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
            if emin_mi == QMessageBox.Yes:
                del self.data[ACIKLAMALAR][self.idx]
                self.kaydetVeKapat()
    def kaydetVeKapat(self):
        # Değişiklikleri kaydet ve pencereyi kapat
        try:
            with open(YAZARIN_NOTLARI_JSON_PATH, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.notlariYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
