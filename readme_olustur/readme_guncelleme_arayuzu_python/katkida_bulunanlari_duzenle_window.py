import unicodedata
import json
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
from PyQt6.QtWidgets import (
    QWidget,
    QVBoxLayout,
    QInputDialog,
    QHBoxLayout,
    QPushButton,
    QMessageBox,
    QDialog,
    QLabel,
    QLineEdit,
    QScrollArea,
)
from katkida_bulunan_ekle_window import KatkidaBulunanEkleWindow
from PyQt6.QtCore import Qt
from degiskenler import *
from PyQt6.QtGui import QIcon
from metin_islemleri import kisaltMetin
from close_event import closeEventHandler
from katkida_bulunan_ekle_window import BaseKatkidaBulunanWindow
from toast_notification import show_success
from link_kontrol_window import LinkKontrolWindow
from undo_manager import UndoManager



class KatkidaBulunanGuncelleWindow(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.is_programmatic_close = False
        self.undo_manager = UndoManager()
        self.title = "Katkıda Bulunanları Ekle/Güncelle"
        # JSON dosyasını oku
        self.data = self.jsonDosyasiniYukle()
        if self.ilklendir():
            self.jsonDosyasiniKaydet()
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setMinimumHeight(450)
        self.setMinimumWidth(700)
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        # Filtreleme için arama kutusu
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Bölüm adı label
        self.bolumAdiLabel = QLabel("Bölüm Adı")
        self.bolumAdiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.bolumAdiLabel)
        # Bölüm adı düzenleme butonu
        bolum_adi = self.data.get(BOLUM_ADI, VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ADI)
        aciklama = self.data.get(
            BOLUM_ACIKLAMASI, VARSAYILAN_KATKIDA_BULUNANLAR_BOLUM_ACIKLAMASI
        )
        self.bolumAdiDuzenleBtn = QPushButton(kisaltMetin(bolum_adi), self)
        self.bolumAdiDuzenleBtn.setToolTip(
            bolum_adi
        )  # Tam metni araç ipucu olarak ekle
        self.bolumAdiDuzenleBtn.setStyleSheet(BASLIK_BUTON_STILI)
        self.bolumAdiDuzenleBtn.clicked.connect(self.bolumAdiDuzenle)
        self.mainLayout.addWidget(self.bolumAdiDuzenleBtn)
        # Bölüm açıklaması label
        self.bolumAciklamaLabel = QLabel("Bölüm Açıklaması")
        self.bolumAciklamaLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.bolumAciklamaLabel)
        # Bölüm açıklaması düzenleme butonu
        self.bolumAciklamaDuzenleBtn = QPushButton(kisaltMetin(aciklama), self)
        self.bolumAciklamaDuzenleBtn.setToolTip(
            aciklama
        )  # Tam metni araç ipucu olarak ekle
        self.bolumAciklamaDuzenleBtn.setStyleSheet(ACIKLAMA_BUTON_STILI)
        self.bolumAciklamaDuzenleBtn.clicked.connect(self.bolumAciklamasiDuzenle)
        self.mainLayout.addWidget(self.bolumAciklamaDuzenleBtn)
        # Ekle butonu
        self.ekleBtn = QPushButton("Katkıda Bulunan Ekle", self)
        self.ekleBtn.clicked.connect(self.acKatkidaBulunanEkle)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan
        self.mainLayout.addWidget(self.ekleBtn)

        # Kırık link kontrolü butonu
        self.linkKontrolBtn = QPushButton("🔗 Kırık Bağlantı Tetkiki", self)
        self.linkKontrolBtn.setStyleSheet(LINK_KONTROL_BUTONU_STILI)
        self.linkKontrolBtn.clicked.connect(self.kirikLinkKontrol)
        self.mainLayout.addWidget(self.linkKontrolBtn)

        self.katkidaBulunanSayisiLabel = QLabel(
            f"Toplam {0} katkıda bulunan var."
        )  # Sayıyı gösteren etiket
        self.katkidaBulunanSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.katkidaBulunanSayisiLabel)
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
        text, ok = QInputDialog.getText(
            self,
            "Bölüm Adı",
            "Bölüm adı: ",
            QLineEdit.EchoMode.Normal,
            self.data[BOLUM_ADI],
        )
        if ok:
            self.data[BOLUM_ADI] = text
            self.bolumAdiDuzenleBtn.setText(kisaltMetin(text))
            self.jsonDosyasiniKaydet()
            self.bolumAdiDuzenleBtn.setToolTip(text)
            show_success(self, "Bölüm adı başarıyla değiştirildi.")

    def bolumAciklamasiDuzenle(self):
        # Bölüm açıklamasını düzenle
        text, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Bölüm Açıklaması", "Bölüm açıklaması: ", self.data[BOLUM_ACIKLAMASI]
        )
        if ok:
            self.data[BOLUM_ACIKLAMASI] = text
            self.bolumAciklamaDuzenleBtn.setText(kisaltMetin(text))
            self.jsonDosyasiniKaydet()
            self.bolumAciklamaDuzenleBtn.setToolTip(text)
            show_success(self, "Bölüm açıklaması başarıyla değiştirildi.")

    def jsonDosyasiniKaydet(self):
        # JSON dosyasını güncelle
        with open(KATKIDA_BULUNANLAR_JSON_PATH, "w", encoding="utf-8") as file:
            json.dump(self.data, file, indent=4, ensure_ascii=False)

    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, katkida_bulunan in enumerate(self.data[KATKIDA_BULUNANLAR]):
            widget = self.layout.itemAt(idx).widget()
            if isinstance(widget, QPushButton):
                katkida_bulunan_adi = widget.toolTip()
                if (
                    query.replace("İ", "i").lower()
                    in katkida_bulunan_adi.replace("İ", "i").lower()
                ):
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.data[KATKIDA_BULUNANLAR]):
            self.clearFilters(is_clicked=False)
            return
        self.katkidaBulunanSayisiLabel.setText(f"{size} sonuç bulundu.")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def keyPressEvent(self, event):
        if (
            event.key() == Qt.Key.Key_Z
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            self.undoSil()
        elif (
            event.key() == Qt.Key.Key_F
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak kelime:")
            if ok:
                self.searchNotes(text)
        else:
            super().keyPressEvent(event)

    def undoSil(self):
        """Son silinen katkıda bulunanı geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, kisi, _ = deleted
            # Silinen kişiyi geri ekle
            if index <= len(self.data[KATKIDA_BULUNANLAR]):
                self.data[KATKIDA_BULUNANLAR].insert(index, kisi)
            else:
                self.data[KATKIDA_BULUNANLAR].append(kisi)
            self.jsonDosyasiniKaydet()
            self.butonlariYenile()
            show_success(self, "Katkıda bulunan geri alındı.")

    def clearFilters(self, is_clicked=True):
        for i in range(self.layout.count()):
            widget = self.layout.itemAt(i).widget()
            if isinstance(widget, QPushButton):
                widget.show()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        self.katkidaBulunanSayisiLabel.setText(
            f"Toplam {len(self.data[KATKIDA_BULUNANLAR])} katkıda bulunan var."
        )  # Not sayısını etikette güncelle

    def jsonDosyasiniYukle(self):
        try:
            with open(KATKIDA_BULUNANLAR_JSON_PATH, "r", encoding="utf-8") as file:
                return json.load(file)
        except FileNotFoundError:
            return json.loads("{}")

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
            [kisi for kisi in self.data[KATKIDA_BULUNANLAR] if kisi[AD].strip()],
            key=lambda kisi:  unicodedata.normalize('NFKD', kisi[AD]).lower(),
        )
        try:
            katkidaBulunanSayisi = len(
                self.data[KATKIDA_BULUNANLAR]
            )  # Toplam katkıda bulunan sayısı
            self.katkidaBulunanSayisiLabel.setText(
                f"Toplam {katkidaBulunanSayisi} katkıda bulunan var."
            )  # Sayıyı gösteren etiket

            for kisi in self.data[KATKIDA_BULUNANLAR]:
                btn = QPushButton(kisi[AD], self)
                btn.clicked.connect(lambda checked, a=kisi: self.duzenle(a))
                btn.setToolTip(json.dumps(kisi, indent=4))
                btn.setStyleSheet(GUNCELLE_BUTTON_STILI)
                self.layout.addWidget(btn)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya okunurken bir hata oluştu: {e}")

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
        self.katkidaBulunanEkleWindow = KatkidaBulunanEkleWindow(self.data, self)

    def duzenle(self, kisi):
        self.duzenlemePenceresi = KatkidaBulunanDuzenleWindow(kisi, self.data, self)
        self.duzenlemePenceresi.show()

    def kirikLinkKontrol(self):
        """Tüm katkıda bulunanların iletişim linklerini kontrol eder."""
        links = []
        for kisi in self.data.get(KATKIDA_BULUNANLAR, []):
            kisi_adi = kisi.get(AD, "Bilinmeyen Kişi")
            iletisim_bilgileri = kisi.get(ILETISIM_BILGILERI, [])
            for iletisim in iletisim_bilgileri:
                baslik = iletisim.get(BASLIK, "")
                link = iletisim.get(LINK, "")
                if link and link.strip():
                    links.append((f"{kisi_adi} - {baslik}", link))
        
        self.linkKontrolWindow = LinkKontrolWindow(
            links,
            title="Katkıda Bulunanlar Linkleri Kontrolü",
            parent=self
        )
        self.linkKontrolWindow.show()


class KatkidaBulunanDuzenleWindow(BaseKatkidaBulunanWindow):
    def __init__(self, kisi, data, parent):
        self.title = "Katkıda Bulunanı Güncelle"
        self.kisi = kisi
        self.data = data
        self.parent = parent
        super().__init__(parent)
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        super().initUI()
        self.setWindowTitle(self.title)
        self.ad_input.setText(self.kisi[AD])
        # Örnek bir GitHub linki
        self.iletisim_bilgileri = self.kisi.get(ILETISIM_BILGILERI, [])
        self.katkida_bulunma_orani.setCurrentText(
            self.kisi.get(KATKIDA_BULUNMA_ORANI, KATKIDA_BULUNMA_ORANI_DIZI[-1])
        )
        # Butonlar için yatay layout
        buttonsLayout = QHBoxLayout()
        # Değişiklikleri Kaydet butonu
        self.kaydet_btn = QPushButton("Değişiklikleri Kaydet", self)
        self.kaydet_btn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydet_btn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydet_btn)

        # Sil butonu
        self.sil_btn = QPushButton("Sil", self)
        self.sil_btn.setStyleSheet(SIL_BUTONU_STILI)
        self.sil_btn.clicked.connect(self.sil)
        buttonsLayout.addWidget(self.sil_btn)
        self.layout.addLayout(buttonsLayout)
        self.iletisimBilgileriniYukle()
        self.show()

    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close, self.hasChanges())

    def sil(self):
        # Silme işlemini onayla
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            f"{self.kisi[AD]} adlı kişiyi silmek istediğinden emin misin?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            try:
                # Kişiyi data listesinden sil
                index = self.data[KATKIDA_BULUNANLAR].index(
                    self.kisi
                )  # Kişinin index'ini bul
                
                # Silmeden önce undo için kaydet
                self.parent.undo_manager.push_deleted(index, self.kisi, "katkida_bulunan")
                
                del self.data[KATKIDA_BULUNANLAR][index]  # Kişiyi listeden sil

                # JSON dosyasını güncelle (Eğer dosyaya kaydedilmesi gerekiyorsa)
                with open(KATKIDA_BULUNANLAR_JSON_PATH, "w", encoding="utf-8") as file:
                    json.dump(self.data, file, indent=4, ensure_ascii=False)

                # Ana penceredeki listeyi yenile
                self.parent.butonlariYenile()
                self.is_programmatic_close = True
                show_success(self.parent, "Katkıda bulunan silindi. (Geri almak için Ctrl+Z)")
                self.close()

            except ValueError:
                # Eğer kişi listede bulunamazsa
                QMessageBox.critical(self, "Hata", "Silinecek kişi bulunamadı.")

    def islemSonucu(self, success, message):
        self.progressDialog.hide()
        if success:
            self.parent.butonlariYenile()  # Ana pencerenin butonlarını yenile
            self.is_programmatic_close = True
            show_success(self.parent, "Katkıda bulunan başarıyla güncellendi.")
            self.close()
        else:
            QMessageBox.warning(self, "Hata", message)

    def iletisimBilgileriniYukle(self):
        try:
            for idx, iletisim_bilgisi in enumerate(self.iletisim_bilgileri):
                baslik = iletisim_bilgisi.get(BASLIK, "")
                link = iletisim_bilgisi.get(LINK, "")
                self.iletisimBilgisiEkle(baslik, link)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya okunurken bir hata oluştu: {e}")
