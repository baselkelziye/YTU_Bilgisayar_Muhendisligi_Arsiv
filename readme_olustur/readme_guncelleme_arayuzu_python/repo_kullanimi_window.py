from PyQt6.QtWidgets import (
    QWidget,
    QScrollArea,
    QDialog,
    QLabel,
    QLineEdit,
    QInputDialog,
    QVBoxLayout,
    QPushButton,
    QInputDialog,
    QMessageBox,
    QHBoxLayout,
    QSizePolicy,
)
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
import json
from PyQt6.QtCore import Qt
from degiskenler import *
from metin_islemleri import kisaltMetin
from PyQt6.QtGui import QIcon


class TalimatDialog(QDialog):
    def __init__(self,parent=None ,json_dosyasi=REPO_KULLANIMI_JSON_PATH):
        super().__init__(parent)
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.setModal(True)
        self.initUI()
        if os.path.exists(OSMANLI_ICO_PATH):
            self.setWindowIcon(QIcon(OSMANLI_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Talimat Ekle/Düzenle")
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.layout.addWidget(self.clearFiltersButton)
        self.talimatSayisiLabel = QLabel(self)
        self.talimatSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.talimatSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.layout.addWidget(self.scrollArea)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)

        # ScrollArea için minimum boyutu belirle
        self.scrollArea.setMinimumSize(580, 300)

        self.yenile()

        # Ekle butonunu ekle
        self.ekleBtn = QPushButton("Talimat Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.ekleBtn.clicked.connect(self.talimatEkle)
        self.layout.addWidget(self.ekleBtn)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_F and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak talimat:")
            if ok:
                self.searchTalimat(text)

    def searchTalimat(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, kavram in enumerate(self.repo_data[TALIMATLAR]):
            layout = self.scrollLayout.itemAt(idx)
            if isinstance(layout, QHBoxLayout):
                match = query.replace('İ','i').lower() in kavram.replace('İ','i').lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data[TALIMATLAR]):
            self.clearFilters(is_clicked=False)
            return
        self.talimatSayisiLabel.setText(f"{size} talimat bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(
                self,
                "Filtreleri Temizle",
                "Filtreleri temizlemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
        if not is_clicked or reply == QMessageBox.StandardButton.Yes:
            for i in range(self.scrollLayout.count()):
                layout = self.scrollLayout.itemAt(i)
                if isinstance(
                    layout, QHBoxLayout
                ):  # Burayı QHBoxLayout olarak değiştirdik
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.talimatSayisiLabel.setText(
                f"Toplam {len(self.repo_data[TALIMATLAR])} talimat"
            )  # kavram sayısını etikette güncelle

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return {TALIMATLAR: []}

    def talimatListele(self):
        # Mevcut talimatları temizle
        self.temizle()
        self.talimatSayisiLabel.setText(
            f"Toplam {len(self.repo_data[TALIMATLAR])} talimat"
        )
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, talimat in enumerate(self.repo_data[TALIMATLAR]):
            talimatLayout = QHBoxLayout()

            talimatBtn = QPushButton(kisaltMetin(talimat), self)
            # talimatBtn.setToolTip(talimat)
            talimatBtn.clicked.connect(
                lambda checked, index=i: self.talimatDuzenle(index)
            )
            talimatBtn.setStyleSheet(GUNCELLE_BUTTON_STILI)
            talimatLayout.addWidget(talimatBtn, 3)
            talimatBtn.setMaximumWidth(500)

            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet(SIL_BUTONU_STILI)
            silBtn.clicked.connect(lambda checked, index=i: self.talimatSil(index))
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
        talimat = self.repo_data[TALIMATLAR][index]
        yeni_talimat, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Talimat Düzenle", "Talimat:", talimat
        )
        info_baslik = "İptal"
        info_mesaj = "Talimat düzenleme işlemi iptal edildi."
        if ok and yeni_talimat:
            # Kullanıcıya onay sorusu sor
            emin_mi = QMessageBox.question(
                self,
                "Onay",
                "Talimatı değiştirmek istediğinizden emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if emin_mi == QMessageBox.StandardButton.Yes:
                # Kullanıcı onay verirse, değişikliği yap
                self.repo_data[TALIMATLAR][index] = yeni_talimat
                self.jsonGuncelle()
                info_baslik = "Başarılı"
                info_mesaj = "Talimat düzenlendi."
        if ok and yeni_talimat == "":
            info_baslik = "Uyarı"
            info_mesaj = "Talimat boş bırakılamaz."
        QMessageBox.information(self, info_baslik, info_mesaj)

    def talimatSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu talimatı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            del self.repo_data[TALIMATLAR][index]
            self.jsonGuncelle()

    def talimatEkle(self):
        yeni_talimat, ok = SatirAtlayanInputDialog.getMultiLineText(self, "Talimat Ekle", "Yeni Talimat:")
        info_baslik = "İptal"
        info_mesaj = "Talimat ekleme işlemi iptal edildi."
        if ok and yeni_talimat:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Talimatı eklemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.repo_data[TALIMATLAR].append(yeni_talimat)
                self.jsonGuncelle()
                info_baslik = "Başarılı"
                info_mesaj = "Talimat eklendi."
        if ok and yeni_talimat == "":
            info_baslik = "Uyarı"
            info_mesaj = "Açıklama boş bırakılamaz."
        QMessageBox.information(self, info_baslik, info_mesaj)


    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()


class KavramDetayDialog(QDialog):
    def __init__(self, parent, repo_data, kavram_index, kavram_adi=None):
        super().__init__(parent)
        self.repo_data = repo_data
        self.kavram_index = kavram_index
        self.kavram_adi = kavram_adi
        self.kavram = self.repo_data[KAVRAMLAR][self.kavram_index]
        self.setModal(True)
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

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
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
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
        for i, aciklama in enumerate(self.kavram[ACIKLAMALAR]):
            aciklamaLayout = QHBoxLayout()

            aciklamaLabel = QLabel(kisaltMetin(aciklama), self)
            aciklamaLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
            aciklamaLabel.setToolTip(aciklama)
            aciklamaLabel.setWordWrap(True)
            aciklamaLabel.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)
            aciklamaLayout.addWidget(aciklamaLabel)

            duzenleBtn = QPushButton("Düzenle", self)
            duzenleBtn.setStyleSheet(GUNCELLE_BUTTON_STILI)
            duzenleBtn.clicked.connect(
                lambda checked, index=i: self.aciklamaDuzenle(index)
            )
            aciklamaLayout.addWidget(duzenleBtn)

            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet(SIL_BUTONU_STILI)
            silBtn.clicked.connect(lambda checked, index=i: self.aciklamaSil(index))
            aciklamaLayout.addWidget(silBtn)

            self.scrollLayout.addLayout(aciklamaLayout)

    def aciklamaDuzenle(self, index):
        eski_aciklama = self.kavram[ACIKLAMALAR][index]
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Düzenle", "Açıklama:", text=eski_aciklama
        )
        info_baslik = "İptal"
        info_mesaj = "Açıklama düzenleme işlemi iptal edildi."
        if ok and yeni_aciklama:
            # Kullanıcıya onay sorusu sor
            emin_mi = QMessageBox.question(
                self,
                "Onay",
                "Açıklamayı değiştirmek istediğinizden emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )

            if emin_mi == QMessageBox.StandardButton.Yes:
                # Kullanıcı onay verirse, değişikliği yap
                self.kavram[ACIKLAMALAR][index] = yeni_aciklama
                self.parent().jsonGuncelle()
                self.aciklamaListele()
                info_baslik = "Başarılı"
                info_mesaj = "Açıklama düzenlendi."
        if ok and yeni_aciklama == "":
            info_baslik = "Uyarı"
            info_mesaj = "Açıklama boş bırakılamaz."
        QMessageBox.information(self, info_baslik, info_mesaj)

    def aciklamaSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu açıklamayı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            del self.kavram[ACIKLAMALAR][index]
            self.parent().jsonGuncelle()
            self.aciklamaListele()

    def aciklamaEkle(self):
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Ekle", "Yeni Açıklama:"
        )
        info_baslik = "İptal"
        info_mesaj = "Açıklama ekleme işlemi iptal edildi."
        if ok and yeni_aciklama:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Açıklama eklemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.kavram[ACIKLAMALAR].append(yeni_aciklama)
                self.parent().jsonGuncelle()
                self.aciklamaListele()
                info_baslik = "Başarılı"
                info_mesaj = "Açıklama eklendi." 
        if ok and yeni_aciklama == "":
            info_baslik = "Uyarı"
            info_mesaj = "Açıklama boş bırakılamaz."     
        QMessageBox.information(self, info_baslik, info_mesaj)


class KavramDialog(QDialog):
    def __init__(self, json_dosyasi=REPO_KULLANIMI_JSON_PATH, parent = None):
        super().__init__(parent)
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.setModal(True)
        self.initUI()
        if os.path.exists(OSMANLI_ICO_PATH):
            self.setWindowIcon(QIcon(OSMANLI_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Kavram Ekle/Düzenle")
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.layout.addWidget(self.clearFiltersButton)
        self.kavramSayisiLabel = QLabel(self)
        self.kavramSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.kavramSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.layout.addWidget(self.scrollArea)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        # ScrollArea için minimum boyutu belirle
        self.scrollArea.setMinimumSize(650, 300)
        self.yenile()

        # Ekle butonunu ekle
        ekleBtn = QPushButton("Kavram Ekle", self)
        ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
        ekleBtn.clicked.connect(self.kavramEkle)
        self.layout.addWidget(ekleBtn)

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return {KAVRAMLAR: []}

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_F and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak kavram:")
            if ok:
                self.searchKavram(text)

    def searchKavram(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, kavram in enumerate(self.repo_data[KAVRAMLAR]):
            layout = self.scrollLayout.itemAt(idx)
            kavram = kavram[KAVRAM]
            if isinstance(layout, QHBoxLayout):
                match = query.replace('İ','i').lower() in kavram.replace('İ','i').lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data[KAVRAMLAR]):
            self.clearFilters(is_clicked=False)
            return
        self.kavramSayisiLabel.setText(f"{size} kavram bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(
                self,
                "Filtreleri Temizle",
                "Filtreleri temizlemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
        if not is_clicked or reply == QMessageBox.StandardButton.Yes:
            for i in range(self.scrollLayout.count()):
                layout = self.scrollLayout.itemAt(i)
                if isinstance(
                    layout, QHBoxLayout
                ):  # Burayı QHBoxLayout olarak değiştirdik
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.kavramSayisiLabel.setText(
                f"Toplam {len(self.repo_data[KAVRAMLAR])} kavram"
            )  # kavram sayısını etikette güncelle

    def kavramListele(self):
        self.temizle()
        self.kavramSayisiLabel.setText(
            f"Toplam {len(self.repo_data[KAVRAMLAR])} kavram"
        )
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, kavram in enumerate(self.repo_data[KAVRAMLAR]):
            kavramLayout = QHBoxLayout()

            # Kavram adını gösteren buton
            kavramBtn = QPushButton(kisaltMetin(kavram[KAVRAM]), self)
            kavramBtn.setToolTip(kavram[KAVRAM])
            kavramBtn.clicked.connect(
                lambda checked, index=i: self.kavramDuzenle(index)
            )
            kavramBtn.setStyleSheet("background-color: lightgreen; color: black;")
            kavramBtn.setMaximumWidth(500)
            kavramLayout.addWidget(kavramBtn, 3)

            # Kavramı düzenleme butonu
            duzenleBtn = QPushButton("Adı Düzenle", self)
            duzenleBtn.setStyleSheet(GUNCELLE_BUTTON_STILI)
            duzenleBtn.clicked.connect(
                lambda checked, index=i: self.kavramAdiDuzenle(index)
            )
            kavramLayout.addWidget(duzenleBtn, 1)

            # Kavramı silme butonu
            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet(SIL_BUTONU_STILI)
            silBtn.clicked.connect(lambda checked, index=i: self.kavramSil(index))
            kavramLayout.addWidget(silBtn, 1)

            self.scrollLayout.addLayout(kavramLayout)

    def kavramAdiDuzenle(self, index):
        eski_kavram = self.repo_data[KAVRAMLAR][index][KAVRAM]
        yeni_kavram, ok = QInputDialog.getText(
            self, "Kavram Adı Düzenle", "Kavram Adı:", text=eski_kavram
        )

        if ok and yeni_kavram:
            emin_mi = QMessageBox.question(
                self,
                "Onay",
                "Kavram adını değiştirmek istediğinizden emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if emin_mi == QMessageBox.StandardButton.Yes:
                self.repo_data[KAVRAMLAR][index][KAVRAM] = yeni_kavram
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
        self.yazarinNotlariWindow = KavramDetayDialog(
            self, self.repo_data, index, self.repo_data[KAVRAMLAR][index][KAVRAM]
        )
        self.yazarinNotlariWindow.show()

    def kavramSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu kavramı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            del self.repo_data[KAVRAMLAR][index]
            self.jsonGuncelle()

    def kavramEkle(self):
        yeni_kavram, ok = QInputDialog.getText(self, "Kavram Ekle", "Yeni Kavram:")
        if ok and yeni_kavram:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Kavram eklemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.repo_data[KAVRAMLAR].append({KAVRAM: yeni_kavram, ACIKLAMALAR: []})
                self.jsonGuncelle()

    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()


class AciklamaDialog(QDialog):
    def __init__(self, json_dosyasi=REPO_KULLANIMI_JSON_PATH, parent = None):
        super().__init__(parent)
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.setModal(True)
        self.initUI()
        if os.path.exists(OSMANLI_ICO_PATH):
            self.setWindowIcon(QIcon(OSMANLI_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Açıklama Ekle/Düzenle")
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.layout.addWidget(self.clearFiltersButton)
        self.aciklamaSayisiLabel = QLabel(self)
        self.aciklamaSayisiLabel.setText(
            f"Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama"
        )
        self.aciklamaSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.aciklamaSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollArea.setWidgetResizable(True)
        self.scrollLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.layout.addWidget(self.scrollArea)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.scrollArea.setMinimumSize(580, 300)
        self.yenile()

        # Ekle butonunu ekle
        ekleBtn = QPushButton("Açıklama Ekle", self)
        ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
        ekleBtn.clicked.connect(self.aciklamaEkle)
        self.layout.addWidget(ekleBtn)

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return {ACIKLAMALAR: []}

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_F and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak açıklama:")
            if ok:
                self.searchAciklama(text)

    def searchAciklama(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, aciklama in enumerate(self.repo_data[ACIKLAMALAR]):
            layout = self.scrollLayout.itemAt(idx)
            if isinstance(layout, QHBoxLayout):
                match = query.replace('İ','i').lower() in aciklama.replace('İ','i').lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data[ACIKLAMALAR]):
            self.clearFilters(is_clicked=False)
            return
        self.aciklamaSayisiLabel.setText(f"{size} açıklama bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(
                self,
                "Filtreleri Temizle",
                "Filtreleri temizlemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
        if not is_clicked or reply == QMessageBox.StandardButton.Yes:
            for i in range(self.scrollLayout.count()):
                layout = self.scrollLayout.itemAt(i)
                if isinstance(
                    layout, QHBoxLayout
                ):  # Burayı QHBoxLayout olarak değiştirdik
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.aciklamaSayisiLabel.setText(
                f"Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama"
            )  # Açıklama sayısını etikette güncelle self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama')  # Açıklama sayısını etikette güncelle

    def aciklamaListele(self):
        self.temizle()
        self.aciklamaSayisiLabel.setText(
            f"Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama"
        )  # Açıklama sayısını etikette güncelle self.aciklamaSayisiLabel.setText(f'Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama')  # Açıklama sayısını etikette güncelle
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, aciklama in enumerate(self.repo_data[ACIKLAMALAR]):
            aciklamaLayout = QHBoxLayout()

            aciklamaBtn = QPushButton(kisaltMetin(aciklama), self)
            # aciklamaBtn.setToolTip(aciklama)
            aciklamaBtn.clicked.connect(
                lambda checked, index=i: self.aciklamaDuzenle(index)
            )
            aciklamaBtn.setStyleSheet(GUNCELLE_BUTTON_STILI)
            aciklamaLayout.addWidget(aciklamaBtn, 3)
            aciklamaBtn.setMaximumWidth(500)
            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet(SIL_BUTONU_STILI)
            silBtn.clicked.connect(lambda checked, index=i: self.aciklamaSil(index))
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

    def aciklamaDuzenle(self, index):
        aciklama = self.repo_data[ACIKLAMALAR][index]
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Düzenle", "Açıklama:", aciklama
        )
        info_baslik = "İptal"
        info_mesaj = "Açıklama düzenleme işlemi iptal edildi."
        if ok and yeni_aciklama:
            emin_mi = QMessageBox.question(
                self,
                "Onay",
                "Açıklamayı değiştirmek istediğinizden emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if emin_mi == QMessageBox.StandardButton.Yes:
                self.repo_data[ACIKLAMALAR][index] = yeni_aciklama
                self.jsonGuncelle()
                info_baslik = "Başarılı"
                info_mesaj = "Açıklama düzenlendi."
        if ok and yeni_aciklama == "":
            info_baslik = "Uyarı"
            info_mesaj = "Açıklama boş bırakılamaz."
        QMessageBox.information(self, info_baslik, info_mesaj)

    def aciklamaSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu açıklamayı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            del self.repo_data[ACIKLAMALAR][index]
            self.jsonGuncelle()

    def aciklamaEkle(self):
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Ekle", "Yeni Açıklama:"
        )
        info_baslik = "İptal"
        info_mesaj = "Açıklama ekleme işlemi iptal edildi."
        if ok and yeni_aciklama:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Açıklama eklemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.repo_data[ACIKLAMALAR].append(yeni_aciklama)
                self.jsonGuncelle()
                info_baslik = "Başarılı"
                info_mesaj = "Açıklama eklendi."
        if ok and yeni_aciklama == "":
            info_baslik = "Uyarı"
            info_mesaj = "Açıklama boş bırakılamaz."
        QMessageBox.information(self, info_baslik, info_mesaj)
    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()


class RepoKullanimiDialog(QDialog):
    def __init__(self, json_dosyasi=REPO_KULLANIMI_JSON_PATH, parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.setMinimumSize(600, 300)
        self.json_dosyasi = json_dosyasi
        self.jsonKontrol()
        self.initUI()
        if os.path.exists(OSMANLI_ICO_PATH):
            self.setWindowIcon(QIcon(OSMANLI_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Repo Kullanımı Düzenleme")
        layout = QVBoxLayout(self)
        # Başlık Buton
        baslik = self.repo_data.get(BASLIK, VARSAYILAN_REPO_KULLANIMI_BOLUM_ADI)
        self.baslikBtn = QPushButton("Başlık: " + kisaltMetin(baslik), self)
        self.baslikBtn.setToolTip(baslik)
        self.baslikBtn.clicked.connect(self.baslikDuzenle)
        self.baslikBtn.setStyleSheet(BASLIK_BUTON_STILI)
        layout.addWidget(self.baslikBtn)
        # Talimat Ekle/Düzenle butonu
        talimatBtn = QPushButton("Talimat Ekle/Düzenle", self)
        talimatBtn.clicked.connect(self.acTalimatDialog)
        talimatBtn.setStyleSheet(
            "background-color: lightblue; color: black;"
        )  # Mavi renk
        layout.addWidget(talimatBtn)
        # Kavram Ekle/Düzenle butonu
        kavramBtn = QPushButton("Kavram Ekle/Düzenle", self)
        kavramBtn.clicked.connect(self.acKavramDialog)
        kavramBtn.setStyleSheet(
            "background-color: lightgreen; color: black;"
        )  # Yeşil renk
        layout.addWidget(kavramBtn)

        # Açıklama Ekle/Düzenle butonu
        aciklamaBtn = QPushButton("Açıklama Ekle/Düzenle", self)
        aciklamaBtn.clicked.connect(self.acAciklamaDialog)
        aciklamaBtn.setStyleSheet(
            "background-color: lightcoral; color: black;"
        )  # Kırmızı renk
        layout.addWidget(aciklamaBtn)

    def baslikDuzenle(self):
        eski_baslik = self.repo_data[BASLIK]
        yeni_baslik, ok = QInputDialog.getText(
            self, "Başlık Düzenle", "Başlık:", QLineEdit.EchoMode.Normal, eski_baslik
        )
        info_baslik = "İptal"
        info_mesaj = "Başlık düzenleme işlemi iptal edildi."
        if ok and yeni_baslik:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Başlığı değiştirmek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.repo_data[BASLIK] = yeni_baslik
                self.jsonGuncelle()
                self.baslikBtn.setText(
                    self.baslikBtn.text().replace(
                        eski_baslik, kisaltMetin(self.repo_data[BASLIK])
                    )
                )
                self.baslikBtn.setToolTip(self.repo_data[BASLIK])
                info_baslik = "Başarılı"
                info_mesaj = "Başlık düzenlendi."
        if ok and yeni_baslik == "":
            info_baslik = "Uyarı"
            info_mesaj = "Açıklama boş bırakılamaz."
        QMessageBox.information(self, info_baslik, info_mesaj)

    # JSON dosyasını oku
    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return {}

    # JSON dosyasını güncelle
    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)

    # JSON dosyasını kontrol et
    def jsonKontrol(self):
        self.repo_data = self.jsonVeriOku()
        if BASLIK not in self.repo_data:
            self.repo_data[BASLIK] = VARSAYILAN_REPO_KULLANIMI_BOLUM_ADI
        if TALIMAT not in self.repo_data:
            self.repo_data[TALIMAT] = VARSAYILAN_TALIMATLAR_BOLUM_ADI
        if KAVRAM not in self.repo_data:
            self.repo_data[KAVRAM] = VARSAYILAN_KAVRAMLAR_BOLUM_ADI
        if ACIKLAMA not in self.repo_data:
            self.repo_data[ACIKLAMA] = VARSAYILAN_ACIKLAMALAR_BOLUM_ADI
        if TALIMATLAR not in self.repo_data:
            self.repo_data[TALIMATLAR] = []
        if KAVRAMLAR not in self.repo_data:
            self.repo_data[KAVRAMLAR] = []
        if ACIKLAMALAR not in self.repo_data:
            self.repo_data[ACIKLAMALAR] = []
        self.jsonGuncelle()

    def acTalimatDialog(self):
        dialog = TalimatDialog()
        dialog.exec()

    def acKavramDialog(self):
        dialog = KavramDialog(parent=self)
        dialog.exec()

    def acAciklamaDialog(self):
        dialog = AciklamaDialog(parent=self)
        dialog.exec()
