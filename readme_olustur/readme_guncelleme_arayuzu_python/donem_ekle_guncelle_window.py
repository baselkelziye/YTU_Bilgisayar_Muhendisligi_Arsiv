from repo_kullanimi_window import TalimatDialog
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


class DonemEkleGuncelleWindow(TalimatDialog):
    def __init__(self, parent=None):
        super().__init__(parent,json_dosyasi=DONEMLER_JSON_PATH)
        self.setWindowTitle("Dönem Ekle/Güncelle")
        self.ekleBtn.clicked.disconnect()
        self.ekleBtn.setText("Dönem Ekle")
        self.ekleBtn.clicked.connect(self.donemEkle)
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

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
            donembtn.setMaximumWidth(500)

            silBtn = QPushButton("Sil", self)
            silBtn.setStyleSheet(SIL_BUTONU_STILI)
            silBtn.clicked.connect(lambda checked, index=i: self.talimatSil(index))
            donemLayout.addWidget(silBtn, 1)

            self.scrollLayout.addLayout(donemLayout)

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

    def talimatSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu dönemi silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            del self.repo_data[DONEMLER][index]
            self.jsonGuncelle()

    def searchDonem(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, donem in enumerate(self.repo_data[DONEMLER]):
            layout = self.scrollLayout.itemAt(idx)
            donem_adi = donem[DONEM_ADI]
            if isinstance(layout, QHBoxLayout):
                match = query.replace('İ','i').lower() in donem_adi.replace('İ','i').lower()
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
        if event.key() == Qt.Key.Key_F and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak talimat:")
            if ok:
                self.searchDonem(text)


class DonemDuzenlemeWindow(QDialog):
    def __init__(self, donem, data, parent, index=None):
        super().__init__(parent)
        self.setModal(True)
        self.index = index
        self.donem = donem
        self.data = data
        self.parent = parent
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))
        self.setWindowTitle("Dönem Düzenle")
        self.initUI()

    def initUI(self):
        self.setWindowTitle("Dönem Düzenleme Arayüzü")
        self.setMinimumSize(
            500, 200
        )  # Pencerenin en küçük olabileceği boyutu ayarlayın
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
        silBtn.setMaximumWidth(40)  # Butonun genişliğini sabitle
        silBtn.setStyleSheet(SIL_BUTONU_STILI)
        silBtn.setText("Sil")
        silBtn.clicked.connect(lambda: self.silTavsiye(editLabel, silBtn))

        # Tavsiye layout'u oluştur
        tavsiyeLayout = QHBoxLayout()
        tavsiyeLayout.addWidget(editLabel)
        tavsiyeLayout.addWidget(silBtn)
        self.tavsiyelerLayout.addLayout(tavsiyeLayout)

    def silTavsiye(self, editLabel, silBtn):
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
        if event.key() == Qt.Key.Key_S and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            self.kaydet()
    def kaydet(self):
        cevap = QMessageBox.question(
            self,
            "Onay",
            "Değişiklikleri kaydetmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if cevap == QMessageBox.StandardButton.No:
            return
        if not self.girdiKontrol():
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
        QMessageBox.information(self, "Başarılı", "Değişiklikler kaydedildi.")
        self.parent.talimatListele()
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
