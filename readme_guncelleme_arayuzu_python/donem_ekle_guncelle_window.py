from PyQt6.QtWidgets import (
    QPushButton,
    QHBoxLayout,
    QMessageBox,
    QScrollArea,
    QWidget,
    QInputDialog,
    QLineEdit,
    QComboBox,
    QLabel,
    QVBoxLayout,
    QDialog,
)
from degiskenler import *
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QIcon
import json
from screen_utils import apply_minimum_size, calculate_scroll_area_size
from close_event import closeEventHandler
from toast_notification import show_success
from undo_manager import UndoManager


class DonemEkleGuncelleWindow(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.json_dosyasi = DONEMLER_JSON_PATH
        self.repo_data = self.jsonVeriOku()
        self.undo_manager = UndoManager()
        self.setModal(True)
        self.jsonKontrol()
        self.initUI()
        self.setWindowTitle("Dönem Ekle/Güncelle")
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.layout = QVBoxLayout(self)
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)
        self.clearFiltersButton.hide()
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
        self.scrollArea.setHorizontalScrollBarPolicy(
            Qt.ScrollBarPolicy.ScrollBarAlwaysOff
        )

        # ScrollArea için minimum boyutu dinamik olarak belirle
        w, h = calculate_scroll_area_size(580, 300)
        self.scrollArea.setMinimumSize(w, h)

        self.yenile()

        # Ekle butonunu ekle
        self.ekleBtn = QPushButton("Dönem Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.ekleBtn.clicked.connect(self.donemEkle)
        self.layout.addWidget(self.ekleBtn)

    def talimatListele(self):
        # Mevcut dönemleri temizle
        self.temizle()
        self.talimatSayisiLabel.setText(
            f"Toplam {len(self.repo_data.get(DONEMLER,[]))} dönem"
        )
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        for i, donem in enumerate(self.repo_data.get(DONEMLER, [])):
            donemLayout = QHBoxLayout()

            donembtn = QPushButton(donem[DONEM_ADI], self)
            donembtn.clicked.connect(lambda checked, index=i: self.donemDuzenle(index))
            donembtn.setStyleSheet(GUNCELLE_BUTTON_STILI)
            donemLayout.addWidget(donembtn, 3)

            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet(SIL_BUTONU_STILI)
            silBtn.clicked.connect(lambda checked, index=i: self.talimatSil(index))
            donemLayout.addWidget(silBtn, 1)

            self.scrollLayout.addLayout(donemLayout)

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

    def jsonKontrol(self):
        if DONEMLER not in self.repo_data:
            self.repo_data[DONEMLER] = []
            self.jsonGuncelle()

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return {DONEMLER: []}

    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()

    def talimatSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu dönemi silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            # Silmeden önce undo için kaydet
            silinen_donem = self.repo_data[DONEMLER][index]
            self.undo_manager.push_deleted(index, silinen_donem, "donem")
            del self.repo_data[DONEMLER][index]
            self.jsonGuncelle()
            show_success(self, "Dönem silindi. (Geri almak için Ctrl+Z)")

    def searchDonem(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, donem in enumerate(self.repo_data[DONEMLER]):
            layout = self.scrollLayout.itemAt(idx)
            donem_adi = donem[DONEM_ADI]
            if isinstance(layout, QHBoxLayout):
                match = (
                    query.replace("İ", "i").lower()
                    in donem_adi.replace("İ", "i").lower()
                )
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.repo_data[DONEMLER]):
            self.clearFilters(is_clicked=False)
            return
        self.talimatSayisiLabel.setText(f"{size} dönem bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def clearFilters(self, is_clicked=True):
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
            f"Toplam {len(self.repo_data[DONEMLER])} dönem"
        )  # kavram sayısını etikette güncelle

    def donemEkle(self):
        # Yeni donem ekleme penceresi
        self.donemDuzenlemePenceresi = DonemDuzenlemeWindow(None, self.repo_data, self)
        self.donemDuzenlemePenceresi.show()

    def donemDuzenle(self, index):
        # Mevcut donem düzenleme penceresi
        self.donemDuzenlemePenceresi = DonemDuzenlemeWindow(
            self.repo_data[DONEMLER][index], self.repo_data, self, index
        )
        self.donemDuzenlemePenceresi.show()

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
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak dönem:")
            if ok:
                self.searchDonem(text)
        else:
            super().keyPressEvent(event)

    def undoSil(self):
        """Son silinen dönemi geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, donem, _ = deleted
            # Silinen dönemi orijinal yerine geri ekle
            if index <= len(self.repo_data[DONEMLER]):
                self.repo_data[DONEMLER].insert(index, donem)
            else:
                self.repo_data[DONEMLER].append(donem)
            self.jsonGuncelle()
            show_success(self, "Dönem geri alındı.")


class DonemDuzenlemeWindow(QDialog):
    def __init__(self, donem, data, parent, index=None):
        super().__init__(parent)
        self.setModal(True)
        self.is_programmatic_close = False
        self.index = index
        self.donem = donem
        self.data = data
        self.parent = parent
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))
        self.setWindowTitle("Dönem Düzenle")
        self.initUI()
        # Başlangıç değerlerini kaydet
        self.saveInitialState()

    def initUI(self):
        self.setWindowTitle("Dönem Düzenleme Arayüzü")
        apply_minimum_size(self, 500, 350)  # Ekrana göre dinamik boyut
        # Ana layout
        self.mainLayout = QVBoxLayout()
        # Dönem adı
        donemAdiLayout = QHBoxLayout()
        self.donemAdiLabel = QLabel("Dönem Adı", self)
        self.donemAdiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.donemAdiLineEdit = QLineEdit(self)
        donemAdiLayout.addWidget(self.donemAdiLabel)
        donemAdiLayout.addWidget(self.donemAdiLineEdit)
        self.mainLayout.addLayout(donemAdiLayout)
        # Yıl seçimi
        yilLayout = QHBoxLayout()
        self.yilLabel = QLabel("Yıl", self)
        self.yilLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.yilComboBox = QComboBox(self)
        self.yilComboBox.addItems(DONEM_YILLARI)  # 0'dan 4'e yıllar
        yilLayout.addWidget(self.yilLabel)
        yilLayout.addWidget(self.yilComboBox)
        self.mainLayout.addLayout(yilLayout)

        # Dönem seçimi
        donemLayout = QHBoxLayout()
        self.donemLabel = QLabel("Dönem", self)
        self.donemLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.donemComboBox = QComboBox(self)
        self.donemComboBox.addItems(DONEMLER_DIZISI_YOKLA_BERABER)  # Dönemler
        donemLayout.addWidget(self.donemLabel)
        donemLayout.addWidget(self.donemComboBox)
        self.mainLayout.addLayout(donemLayout)

        # Hocalar için kaydırılabilir alan oluştur
        self.tavsiyelerScrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.tavsiyelerScrollArea.setWidgetResizable(True)
        # Hocaların gösterileceği widget
        self.tavsiyeScrollWidget = QWidget()
        # ScrollArea genişliğini dersScrollWidget genişliğiyle sınırla
        self.tavsiyeScrollWidget.setMinimumWidth(self.tavsiyelerScrollArea.width())

        self.tavsiyelerLayout = QVBoxLayout(self.tavsiyeScrollWidget)
        self.tavsiyelerScrollArea.setWidget(
            self.tavsiyeScrollWidget
        )  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.tavsiyelerScrollArea)
        # Ekle (+) butonu
        self.ekleTavsiyeBtn = QPushButton("Genel Tavsiye Ekle", self)
        self.ekleTavsiyeBtn.setStyleSheet(VEREN_EKLE_BUTONU_STILI)
        self.ekleTavsiyeBtn.clicked.connect(self.tavsiyeEkleLabel)
        self.kaydet_btn = QPushButton("Kaydet", self)
        self.kaydet_btn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydet_btn.clicked.connect(self.kaydet)
        self.mainLayout.addWidget(self.ekleTavsiyeBtn)
        self.mainLayout.addWidget(self.kaydet_btn)
        self.yukle()
        # Ana layout'u pencereye ata
        self.setLayout(self.mainLayout)

    def yukle(self):
        if self.donem and GENEL_TAVSIYELER in self.donem:
            for tavsiye in self.donem[GENEL_TAVSIYELER]:
                self.tavsiyeEkleLabel(tavsiye)
            self.donemAdiLineEdit.setText(self.donem.get(DONEM_ADI, ""))
            self.yilComboBox.setCurrentText(str(self.donem.get(YIL, 1)))
            donem_index = self.donemComboBox.findText(self.donem.get(DONEM, ""))
            # Eğer indeks geçerliyse, combobox'ı bu indekse ayarlayın
            if donem_index != -1:
                self.donemComboBox.setCurrentIndex(donem_index)

    def tavsiyeEkleLabel(self, tavsiye=None):
        # Yeni QLineEdit oluştur
        editLabel = QLineEdit(self)
        if tavsiye:
            editLabel.setText(tavsiye)  # Eğer tavsiye varsa, onu QLineEdit'da göster

        # Sil (-) butonu
        silBtn = QPushButton("-", self)
        silBtn.setStyleSheet(SIL_BUTONU_STILI)
        silBtn.setText("Sil")
        silBtn.clicked.connect(lambda: self.silTavsiye(editLabel, silBtn))

        # Tavsiye layout'u oluştur
        tavsiyeLayout = QHBoxLayout()
        tavsiyeLayout.addWidget(editLabel)
        tavsiyeLayout.addWidget(silBtn)
        self.tavsiyelerLayout.addLayout(tavsiyeLayout)

    def silTavsiye(self, editLabel, silBtn):
        # Onay sor
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu tavsiyeyi silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            # Tavsiyeyi ve butonu layout'tan kaldır
            editLabel.deleteLater()
            silBtn.deleteLater()

    def girdiKontrol(self):
        donem_adi = self.donemAdiLineEdit.text().strip()
        if not donem_adi:
            QMessageBox.warning(self, "Hata", "Dönem adı boş olamaz!")
            return False
        yil = int(self.yilComboBox.currentText())
        donem_data = self.donemComboBox.currentText()
        for index, donem in enumerate(self.data.get(DONEMLER, [])):
            if donem.get(YIL, -1) == yil and donem.get(DONEM, "") == donem_data:
                if self.index is None or index != self.index:
                    QMessageBox.warning(
                        self, "Hata", "Bu yıl-dönem ikilisi zaten mevcut!"
                    )
                    return False
                else:
                    break
        return True

    def keyPressEvent(self, event):
        if (
            event.key() == Qt.Key.Key_S
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            self.kaydet()

    def saveInitialState(self):
        """Başlangıç değerlerini kaydet"""
        self.initial_donem_adi = self.donemAdiLineEdit.text()
        self.initial_yil = self.yilComboBox.currentText()
        self.initial_donem = self.donemComboBox.currentText()
        self.initial_tavsiyeler = self.getTavsiyeler()

    def getTavsiyeler(self):
        """Mevcut tavsiyeleri al"""
        tavsiyeler = []
        tum_widgets = topluWidgetBul(self.tavsiyelerLayout)
        for widget in tum_widgets:
            if isinstance(widget, QLineEdit):
                tavsiyeler.append(widget.text().strip())
        return tavsiyeler

    def hasChanges(self):
        """Değişiklik olup olmadığını kontrol et"""
        return (
            self.donemAdiLineEdit.text() != self.initial_donem_adi or
            self.yilComboBox.currentText() != self.initial_yil or
            self.donemComboBox.currentText() != self.initial_donem or
            self.getTavsiyeler() != self.initial_tavsiyeler
        )

    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close, self.hasChanges())

    def kaydet(self):
        if not self.girdiKontrol():
            return
        if not self.hasChanges():
            self.is_programmatic_close = True
            self.close()
            return
        yil = int(self.yilComboBox.currentText())
        donem = self.donemComboBox.currentText()
        donem = "" if donem == YOK else donem
        genel_tavsiyeler = []
        tum_widgets = topluWidgetBul(self.tavsiyelerLayout)
        donem_adi = self.donemAdiLineEdit.text().strip()
        for widget in tum_widgets:
            if isinstance(widget, QLineEdit):
                genel_tavsiyeler.append(widget.text().strip())
        data = {
            DONEM_ADI: donem_adi,
            YIL: yil,
            DONEM: donem,
            GENEL_TAVSIYELER: genel_tavsiyeler,
        }
        if self.index is None:
            self.data[DONEMLER].append(data)
        else:
            self.data[DONEMLER][self.index] = data
        self.parent.jsonGuncelle()
        self.parent.talimatListele()
        self.is_programmatic_close = True
        show_success(self.parent, "Dönem başarıyla kaydedildi.")
        self.close()


def topluWidgetBul(layout):
    widgets = []
    for i in range(layout.count()):
        item = layout.itemAt(i)
        if isinstance(
            item, QHBoxLayout
        ):  # Eğer item bir layout ise, özyinelemeli olarak widget'ları bul
            widgets.extend(topluWidgetBul(item.layout()))
        else:
            widget = item.widget()
            if widget:  # Eğer widget varsa listeye ekle
                widgets.append(widget)
    return widgets
