import sys
import json
from PyQt5.QtWidgets import QDialog, QVBoxLayout,QLabel, QDesktopWidget, QWidget, QPushButton, QHBoxLayout, QMessageBox, QTextEdit, QApplication, QScrollArea
JSON_DOSYASI = '../yazarin_notlari.json'
class YazarinNotlariWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Yazarın Notları Ekle/Düzenle')
        self.setGeometry(100, 100, 600, 400)  # Pencere boyutunu büyüt

        self.mainLayout = QVBoxLayout(self)  # Ana layout

        # Not ekleme butonu
        self.ekleBtn = QPushButton('Not Ekle', self)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Yeşil arka plan
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

    def notlariYukle(self):
        try:
            with open(JSON_DOSYASI, 'r', encoding='utf-8') as file:
                self.data = json.load(file)
                not_sayisi = len(self.data['aciklamalar'])  # Not sayısını hesapla
                self.notSayisiLabel.setText(f'Toplam {not_sayisi} not')  # Not sayısını etikette güncelle

                for idx, not_ in enumerate(self.data['aciklamalar']):
                    btn = QPushButton(f"Not {idx + 1}: {not_[:30]}...", self.scrollWidget)  # İlk 30 karakteri göster
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
            self.notInput.setText(self.data['aciklamalar'][self.idx])
        self.layout.addWidget(self.notInput)

        # Butonları yan yana koymak için QHBoxLayout kullan
        buttonLayout = QHBoxLayout()

        # Kaydet butonu
        if self.idx is not None:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.kaydetBtn.setStyleSheet("background-color: green;")
        buttonLayout.addWidget(self.kaydetBtn)

        if self.idx is not None:  # Var olan bir not düzenleniyorsa sil butonunu göster
            # Sil butonu
            self.silBtn = QPushButton('Notu Sil', self)
            self.silBtn.clicked.connect(self.notSil)
            self.silBtn.setStyleSheet("background-color: red;")
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
                self.data['aciklamalar'].append(yeni_not)
            else:  # Düzenleme modunda
                self.data['aciklamalar'][self.idx] = yeni_not

            try:
                with open(JSON_DOSYASI, 'w',encoding='utf-8') as file:
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
                del self.data['aciklamalar'][self.idx]
                self.kaydetVeKapat()
    def kaydetVeKapat(self):
        # Değişiklikleri kaydet ve pencereyi kapat
        try:
            with open(JSON_DOSYASI, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.notlariYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
