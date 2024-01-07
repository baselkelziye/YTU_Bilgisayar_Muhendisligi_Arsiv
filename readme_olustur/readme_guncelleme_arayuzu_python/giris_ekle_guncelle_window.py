from yazarin_notlari_duzenle_window import YazarinNotlariWindow
from degiskenler import *
from PyQt5.QtWidgets import QLabel, QMessageBox, QPushButton, QDesktopWidget, QHBoxLayout, QDialog, QVBoxLayout, QTextEdit, QInputDialog
from metin_islemleri import kisaltMetin
import json

class GirisEkleGuncelleWindow(YazarinNotlariWindow):
    def __init__(self):
        super().__init__()
    def initUI(self):
        super().initUI()
        self.baslik_label = QLabel('Başlık:', self)
        self.mainLayout.insertWidget(1, self.baslik_label)
        self.baslik_duzenle_btn = QPushButton(kisaltMetin(self.data[BASLIK]), self)
        self.baslik_duzenle_btn.clicked.connect(lambda: self.aciklamaDuzenle(BASLIK))
        self.baslik_duzenle_btn.setToolTip(self.data[BASLIK])  # Tam metni araç ipucu olarak ekle
        self.mainLayout.insertWidget(2, self.baslik_duzenle_btn)
        self.aciklama_label = QLabel('Açıklama:', self)
        self.mainLayout.insertWidget(3, self.aciklama_label)
        self.aciklama_duzenle_btn = QPushButton(kisaltMetin(self.data[ACIKLAMA]), self)
        self.aciklama_duzenle_btn.setToolTip(self.data[ACIKLAMA])  # Tam metni araç ipucu olarak ekle
        self.aciklama_duzenle_btn.clicked.connect(lambda: self.aciklamaDuzenle(ACIKLAMA))
        self.mainLayout.insertWidget(4, self.aciklama_duzenle_btn) 
        self.ekleBtn.setText('İçindekiler Ekle')
        self.setWindowTitle('Giriş Güncelleme')
    def notlariYukle(self):
        self.data = self.jsonDosyasiniYukle()
        try:
            if ICINDEKILER not in self.data:
                self.data[ICINDEKILER] = []
            if BASLIK not in self.data:
                self.data[BASLIK] = VARSAYILAN_GIRIS_BASLIK
            if ACIKLAMA not in self.data:
                self.data[ACIKLAMA] = VARSAYILAN_GIRIS_ACIKLAMA
            icindekiler_sayisi = len(self.data[ICINDEKILER])  # Not sayısını hesapla
            self.notSayisiLabel.setText(f'Toplam {icindekiler_sayisi} içindekiler')  # Not sayısını etikette güncelle

            for idx, not_ in enumerate(self.data[ICINDEKILER]):
                btn = QPushButton(f"İçindekiler {idx + 1}: {kisaltMetin(not_)}", self.scrollWidget)  # İlk 30 karakteri göster
                btn.setToolTip(not_)  # Tam metni araç ipucu olarak ekle
                btn.clicked.connect(lambda checked, i=idx: self.notDuzenle(i))
                self.notlarLayout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
    def jsonDosyasiniYukle(self):
        try:
            with open(GIRIS_JSON_PATH, 'r', encoding='utf-8') as file:
                return json.load(file)
        except Exception as e:
            return json.loads('{}')
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
            self.notSayisiLabel.setText(f'Toplam {len(self.data[ICINDEKILER])} içindekiler')  # Not sayısını etikette güncelle
    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, not_ in enumerate(self.data[ICINDEKILER]):
            widget = self.notlarLayout.itemAt(idx).widget()
            if isinstance(widget, QPushButton):
                if query.lower() in not_.lower():
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.data[ICINDEKILER]):
            self.clearFilters(is_clicked=False)
            return
        self.notSayisiLabel.setText(f'{size} içindekiler bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()
    
    def aciklamaDuzenle(self, anahtar):
        eski_aciklama = self.data.get(anahtar, "")
        baslik = "Başlık" if anahtar == BASLIK else "Açıklama"
        yeni_aciklama, ok = QInputDialog.getMultiLineText(self, f'{baslik} Düzenle', 'Açıklama:', eski_aciklama)

        if ok and yeni_aciklama != eski_aciklama:
            self.data[anahtar] = yeni_aciklama
            if baslik == "Başlık":
                self.baslik_duzenle_btn.setText(kisaltMetin(yeni_aciklama))
                self.baslik_duzenle_btn.setToolTip(yeni_aciklama)
            else:
                self.aciklama_duzenle_btn.setText(kisaltMetin(yeni_aciklama))
                self.aciklama_duzenle_btn.setToolTip(yeni_aciklama)
            self.kaydet()

    def kaydet(self):
        try:
            with open(GIRIS_JSON_PATH, 'w', encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Açıklama güncellendi ve kaydedildi!')
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')

    def notEkle(self):
        self.duzenlemePenceresi = IcindekilerDuzenleWindow(None, self.data, self)
        self.duzenlemePenceresi.show()

    def notDuzenle(self, idx):
        self.duzenlemePenceresi = IcindekilerDuzenleWindow(idx, self.data, self)
        self.duzenlemePenceresi.show()
class IcindekilerDuzenleWindow(QDialog):
    def __init__(self, idx, data, parent):
        super().__init__()
        self.parent = parent
        self.idx = idx
        self.setModal(True)
        self.data = data
        self.initUI()

    def initUI(self):
        self.setWindowTitle('İçindekileri Düzenle' if self.idx is not None else 'İçindekiler Ekle')
        self.resize(400, 300)
        self.layout = QVBoxLayout(self)

        self.input = QTextEdit(self)
        if self.idx is not None and self.data:
            self.input.setText(self.data[ICINDEKILER][self.idx])
        self.layout.addWidget(self.input)

        buttonLayout = QHBoxLayout()
        self.kaydetBtn = QPushButton('Değişiklikleri Kaydet' if self.idx is not None else 'Ekle', self)
        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonLayout.addWidget(self.kaydetBtn)

        if self.idx is not None:
            self.silBtn = QPushButton('İçeriği Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet(SIL_BUTONU_STILI)
            buttonLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonLayout)
        self.center()

    def center(self):
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def kaydet(self):
        yeni_icindekiler = self.input.toPlainText().strip()
        if not yeni_icindekiler:
            QMessageBox.warning(self, 'Hata', 'İçindekiler boş olamaz!')
            return

        if self.idx is None:
            self.data[ICINDEKILER].append(yeni_icindekiler)
        else:
            self.data[ICINDEKILER][self.idx] = yeni_icindekiler

        self.kaydetVeKapat()

    def sil(self):
        if self.idx is not None:
            del self.data[ICINDEKILER][self.idx]
            self.kaydetVeKapat()

    def kaydetVeKapat(self):
        try:
            with open(GIRIS_JSON_PATH, 'w', encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'İçindekiler güncellendi!')
            self.parent.notlariYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')