from PyQt6.QtWidgets import (
    QWidget,
    QDialog,
    QLabel,
    QLineEdit,
    QInputDialog,
    QVBoxLayout,
    QPushButton,
    QMessageBox,
    QSizePolicy,
)
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog, TekSatirInputDialog
import json
from PyQt6.QtCore import Qt
from degiskenler import *
from metin_islemleri import kisaltMetin
from PyQt6.QtGui import QIcon
from screen_utils import apply_minimum_size, calculate_scroll_area_size
from toast_notification import show_success
from undo_manager import UndoManager
from helpers.surukleme_listesi import SuruklemeListe, SuruklemeListeItem, surukle_bilgi_etiketi


class TalimatDialog(QDialog):
    def __init__(self, parent=None, json_dosyasi=REPO_KULLANIMI_JSON_PATH):
        super().__init__(parent)
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.undo_manager = UndoManager()
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

        # Bilgi etiketi
        self.bilgiLabel = surukle_bilgi_etiketi(self)
        self.layout.addWidget(self.bilgiLabel)

        # Sürükle-bırak listesi
        self.suruklemeListe = SuruklemeListe(self)
        self.suruklemeListe.itemDoubleClicked.connect(self.surukleListeItemDuzenle)
        self.suruklemeListe.siralama_degisti.connect(self.suruklemeSiralamaKaydet)
        # Minimum boyut
        w, h = calculate_scroll_area_size(580, 300)
        self.suruklemeListe.setMinimumSize(w, h)
        self.layout.addWidget(self.suruklemeListe)

        self.yenile()

        # Ekle butonunu ekle
        self.ekleBtn = QPushButton("Talimat Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.ekleBtn.clicked.connect(self.talimatEkle)
        self.layout.addWidget(self.ekleBtn)

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
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak talimat:")
            if ok:
                self.searchTalimat(text)
        else:
            super().keyPressEvent(event)

    def searchTalimat(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, talimat in enumerate(self.repo_data[TALIMATLAR]):
            item = self.suruklemeListe.item(idx)
            if item:
                match = query.replace("İ", "i").lower() in talimat.replace("İ", "i").lower()
                item.setHidden(not match)
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
        for i in range(self.suruklemeListe.count()):
            self.suruklemeListe.item(i).setHidden(False)
        self.clearFiltersButton.hide()
        self.talimatSayisiLabel.setText(
            f"Toplam {len(self.repo_data[TALIMATLAR])} talimat"
        )

    def jsonVeriOku(self):
        try:
            with open(self.json_dosyasi, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return {TALIMATLAR: []}

    def talimatListele(self):
        self.talimatSayisiLabel.setText(
            f"Toplam {len(self.repo_data[TALIMATLAR])} talimat"
        )
        self.clearFiltersButton.hide()

        # Sürükle-bırak listesini doldur
        self.suruklemeListe.clear()
        for i, talimat in enumerate(self.repo_data[TALIMATLAR]):
            item = SuruklemeListeItem(
                f"📋 {i + 1}: {kisaltMetin(talimat)}",
                data=talimat,
                index=i
            )
            item.setToolTip(talimat)
            self.suruklemeListe.addItem(item)

    def surukleListeItemDuzenle(self, item):
        """Sürükle-bırak listesinde çift tıklanan öğeyi düzenle"""
        idx = self.suruklemeListe.row(item)
        self.talimatDuzenle(idx)

    def suruklemeSiralamaKaydet(self):
        """Sürükle-bırak sonrası yeni sıralamayı kaydet"""
        yeni_siralama = []
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            yeni_siralama.append(item.custom_data)
        self.repo_data[TALIMATLAR] = yeni_siralama
        self.jsonGuncelle()
        # Sürükle-bırak listesindeki item metinlerini güncelle
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            item.setText(f"📋 {i + 1}: {kisaltMetin(item.custom_data)}")
        show_success(self, "Sıralama kaydedildi.")

    def yenile(self):
        self.talimatListele()

    def talimatDuzenle(self, index):
        # Düzenleme dialogunu aç
        talimat = self.repo_data[TALIMATLAR][index]
        yeni_talimat, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Talimat Düzenle", "Talimat:", talimat
        )
        if ok and yeni_talimat:
            if yeni_talimat == talimat:
                return  # Değişiklik yok
            self.repo_data[TALIMATLAR][index] = yeni_talimat
            self.jsonGuncelle()
            show_success(self, "Talimat başarıyla güncellendi.")
        elif ok and yeni_talimat == "":
            QMessageBox.warning(self, "Uyarı", "Talimat boş bırakılamaz.")

    def talimatSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu talimatı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            # Silmeden önce undo için kaydet
            silinen_talimat = self.repo_data[TALIMATLAR][index]
            self.undo_manager.push_deleted(index, silinen_talimat, "talimat")
            del self.repo_data[TALIMATLAR][index]
            self.jsonGuncelle()
            show_success(self, "Talimat başarıyla silindi. (Geri almak için Ctrl+Z)")

    def undoSil(self):
        """Son silinen talimatı geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, talimat, _ = deleted
            # Silinen talimatı orijinal yerine geri ekle
            if index <= len(self.repo_data[TALIMATLAR]):
                self.repo_data[TALIMATLAR].insert(index, talimat)
            else:
                self.repo_data[TALIMATLAR].append(talimat)
            self.jsonGuncelle()
            show_success(self, "Talimat geri alındı.")

    def talimatEkle(self):
        yeni_talimat, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Talimat Ekle", "Yeni Talimat:"
        )
        if ok and yeni_talimat:
            self.repo_data[TALIMATLAR].append(yeni_talimat)
            self.jsonGuncelle()
            show_success(self, "Talimat başarıyla eklendi.")
        elif ok and yeni_talimat == "":
            QMessageBox.warning(self, "Uyarı", "Talimat boş bırakılamaz.")

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
        # Değişiklik takibi için orijinal verilerin kopyasını sakla
        self._original_aciklamalar = list(self.kavram[ACIKLAMALAR])
        self.undo_manager = UndoManager()
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

        # Bilgi etiketi
        self.bilgiLabel = surukle_bilgi_etiketi(self)
        self.layout.addWidget(self.bilgiLabel)

        # Sürükle-bırak listesi
        self.suruklemeListe = SuruklemeListe(self)
        self.suruklemeListe.itemDoubleClicked.connect(self.surukleListeItemDuzenle)
        self.suruklemeListe.siralama_degisti.connect(self.suruklemeSiralamaKaydet)
        w, h = calculate_scroll_area_size(650, 300)
        self.suruklemeListe.setMinimumSize(w, h)
        self.layout.addWidget(self.suruklemeListe)

        self.aciklamaListele()

        self.ekleBtn = QPushButton("Açıklama Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.ekleBtn.clicked.connect(self.aciklamaEkle)
        self.layout.addWidget(self.ekleBtn)

    def surukleListeItemDuzenle(self, item):
        """Sürükle-bırak listesinde çift tıklanan öğeyi düzenle"""
        idx = self.suruklemeListe.row(item)
        self.aciklamaDuzenle(idx)

    def suruklemeSiralamaKaydet(self):
        """Sürükle-bırak sonrası yeni sıralamayı kaydet"""
        yeni_siralama = []
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            yeni_siralama.append(item.custom_data)
        self.kavram[ACIKLAMALAR] = yeni_siralama
        self.parent().jsonGuncelle()
        self._original_aciklamalar = list(self.kavram[ACIKLAMALAR])
        # Sürükle-bırak listesindeki item metinlerini güncelle
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            item.setText(f"💬 {i + 1}: {kisaltMetin(item.custom_data)}")
        show_success(self, "Sıralama kaydedildi.")

    def aciklamaListele(self):
        # Sürükle-bırak listesini doldur
        self.suruklemeListe.clear()
        for i, aciklama in enumerate(self.kavram[ACIKLAMALAR]):
            item = SuruklemeListeItem(
                f"💬 {i + 1}: {kisaltMetin(aciklama)}",
                data=aciklama,
                index=i
            )
            item.setToolTip(aciklama)
            self.suruklemeListe.addItem(item)

    def aciklamaDuzenle(self, index):
        eski_aciklama = self.kavram[ACIKLAMALAR][index]
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Düzenle", "Açıklama:", text=eski_aciklama
        )
        if ok and yeni_aciklama:
            if yeni_aciklama == eski_aciklama:
                return  # Değişiklik yok
            self.kavram[ACIKLAMALAR][index] = yeni_aciklama
            self.parent().jsonGuncelle()
            self._original_aciklamalar = list(self.kavram[ACIKLAMALAR])  # Güncel durumu kaydet
            self.aciklamaListele()
            show_success(self, "Açıklama başarıyla güncellendi.")
        elif ok and yeni_aciklama == "":
            QMessageBox.warning(self, "Uyarı", "Açıklama boş bırakılamaz.")

    def aciklamaSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu açıklamayı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            # Silmeden önce undo için kaydet
            silinen_aciklama = self.kavram[ACIKLAMALAR][index]
            self.undo_manager.push_deleted(index, silinen_aciklama, "aciklama")
            del self.kavram[ACIKLAMALAR][index]
            self.parent().jsonGuncelle()
            self._original_aciklamalar = list(self.kavram[ACIKLAMALAR])  # Güncel durumu kaydet
            self.aciklamaListele()
            show_success(self, "Açıklama başarıyla silindi. (Geri almak için Ctrl+Z)")

    def undoSil(self):
        """Son silinen açıklamayı geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, aciklama, _ = deleted
            # Silinen açıklamayı orijinal yerine geri ekle
            if index <= len(self.kavram[ACIKLAMALAR]):
                self.kavram[ACIKLAMALAR].insert(index, aciklama)
            else:
                self.kavram[ACIKLAMALAR].append(aciklama)
            self.parent().jsonGuncelle()
            self._original_aciklamalar = list(self.kavram[ACIKLAMALAR])
            self.aciklamaListele()
            show_success(self, "Açıklama geri alındı.")

    def keyPressEvent(self, event):
        if (
            event.key() == Qt.Key.Key_Z
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            self.undoSil()
        else:
            super().keyPressEvent(event)

    def aciklamaEkle(self):
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Ekle", "Yeni Açıklama:"
        )
        if ok and yeni_aciklama:
            self.kavram[ACIKLAMALAR].append(yeni_aciklama)
            self.parent().jsonGuncelle()
            self._original_aciklamalar = list(self.kavram[ACIKLAMALAR])  # Güncel durumu kaydet
            self.aciklamaListele()
            show_success(self, "Açıklama başarıyla eklendi.")
        elif ok and yeni_aciklama == "":
            QMessageBox.warning(self, "Uyarı", "Açıklama boş bırakılamaz.")

    def hasUnsavedChanges(self):
        """Kaydedilmemiş değişiklik olup olmadığını kontrol et."""
        return self.kavram[ACIKLAMALAR] != self._original_aciklamalar

    def closeEvent(self, event):
        """Pencere kapatılırken değişiklik kontrolü yap."""
        if self.hasUnsavedChanges():
            reply = QMessageBox.question(
                self,
                "Değişiklikleri Kaydetmediniz",
                "Değişiklikler kaydedilmedi. Çıkmak istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if reply == QMessageBox.StandardButton.No:
                event.ignore()
                return
        event.accept()

    def reject(self):
        """ESC tuşu veya dialog kapatma işlemi."""
        if self.hasUnsavedChanges():
            reply = QMessageBox.question(
                self,
                "Değişiklikleri Kaydetmediniz",
                "Değişiklikler kaydedilmedi. Çıkmak istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if reply == QMessageBox.StandardButton.No:
                return
        super().reject()


class KavramDialog(QDialog):
    def __init__(self, json_dosyasi=REPO_KULLANIMI_JSON_PATH, parent=None):
        super().__init__(parent)
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.undo_manager = UndoManager()
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

        # Bilgi etiketi
        self.bilgiLabel = surukle_bilgi_etiketi(self)
        self.layout.addWidget(self.bilgiLabel)

        # Sürükle-bırak listesi
        self.suruklemeListe = SuruklemeListe(self)
        self.suruklemeListe.itemDoubleClicked.connect(self.surukleListeItemDuzenle)
        self.suruklemeListe.siralama_degisti.connect(self.suruklemeSiralamaKaydet)
        w, h = calculate_scroll_area_size(650, 300)
        self.suruklemeListe.setMinimumSize(w, h)
        self.layout.addWidget(self.suruklemeListe)

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
        if (
            event.key() == Qt.Key.Key_Z
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            self.undoSil()
        elif (
            event.key() == Qt.Key.Key_F
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak kavram:")
            if ok:
                self.searchKavram(text)
        else:
            super().keyPressEvent(event)

    def searchKavram(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, kavram_obj in enumerate(self.repo_data[KAVRAMLAR]):
            item = self.suruklemeListe.item(idx)
            if item:
                kavram = kavram_obj[KAVRAM]
                match = query.replace("İ", "i").lower() in kavram.replace("İ", "i").lower()
                item.setHidden(not match)
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
        for i in range(self.suruklemeListe.count()):
            self.suruklemeListe.item(i).setHidden(False)
        self.clearFiltersButton.hide()
        self.kavramSayisiLabel.setText(
            f"Toplam {len(self.repo_data[KAVRAMLAR])} kavram"
        )

    def kavramListele(self):
        self.kavramSayisiLabel.setText(
            f"Toplam {len(self.repo_data[KAVRAMLAR])} kavram"
        )
        self.clearFiltersButton.hide()

        # Sürükle-bırak listesini doldur
        self.suruklemeListe.clear()
        for i, kavram in enumerate(self.repo_data[KAVRAMLAR]):
            item = SuruklemeListeItem(
                f"📚 {i + 1}: {kisaltMetin(kavram[KAVRAM])}",
                data=kavram,
                index=i
            )
            item.setToolTip(kavram[KAVRAM])
            self.suruklemeListe.addItem(item)

    def surukleListeItemDuzenle(self, item):
        """Sürükle-bırak listesinde çift tıklanan öğeyi düzenle"""
        idx = self.suruklemeListe.row(item)
        self.kavramDuzenle(idx)

    def suruklemeSiralamaKaydet(self):
        """Sürükle-bırak sonrası yeni sıralamayı kaydet"""
        yeni_siralama = []
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            yeni_siralama.append(item.custom_data)
        self.repo_data[KAVRAMLAR] = yeni_siralama
        self.jsonGuncelle()
        # Sürükle-bırak listesindeki item metinlerini güncelle
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            item.setText(f"📚 {i + 1}: {kisaltMetin(item.custom_data[KAVRAM])}")
        show_success(self, "Sıralama kaydedildi.")

    def kavramAdiDuzenle(self, index):
        eski_kavram = self.repo_data[KAVRAMLAR][index][KAVRAM]
        yeni_kavram, ok = TekSatirInputDialog.getSingleLineText(
            self, "Kavram Adı Düzenle", "Kavram Adı:", text=eski_kavram
        )

        if ok and yeni_kavram:
            if yeni_kavram == eski_kavram:
                return  # Değişiklik yok
            self.repo_data[KAVRAMLAR][index][KAVRAM] = yeni_kavram
            self.jsonGuncelle()
            self.kavramListele()
            show_success(self, "Kavram adı başarıyla güncellendi.")
        elif ok and yeni_kavram == "":
            QMessageBox.warning(self, "Uyarı", "Kavram adı boş bırakılamaz.")

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
            # Silmeden önce undo için kaydet
            silinen_kavram = self.repo_data[KAVRAMLAR][index]
            self.undo_manager.push_deleted(index, silinen_kavram, "kavram")
            del self.repo_data[KAVRAMLAR][index]
            self.jsonGuncelle()
            show_success(self, "Kavram başarıyla silindi. (Geri almak için Ctrl+Z)")

    def undoSil(self):
        """Son silinen kavramı geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, kavram, _ = deleted
            # Silinen kavramı orijinal yerine geri ekle
            if index <= len(self.repo_data[KAVRAMLAR]):
                self.repo_data[KAVRAMLAR].insert(index, kavram)
            else:
                self.repo_data[KAVRAMLAR].append(kavram)
            self.jsonGuncelle()
            show_success(self, "Kavram geri alındı.")

    def kavramEkle(self):
        yeni_kavram, ok = QInputDialog.getText(self, "Kavram Ekle", "Yeni Kavram:")
        if ok and yeni_kavram:
            self.repo_data[KAVRAMLAR].append({KAVRAM: yeni_kavram, ACIKLAMALAR: []})
            self.jsonGuncelle()
            show_success(self, "Kavram başarıyla eklendi.")

    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()


class AciklamaDialog(QDialog):
    def __init__(self, json_dosyasi=REPO_KULLANIMI_JSON_PATH, parent=None):
        super().__init__(parent)
        self.json_dosyasi = json_dosyasi
        self.repo_data = self.jsonVeriOku()
        self.undo_manager = UndoManager()
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
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)
        self.clearFiltersButton.hide()
        self.layout.addWidget(self.clearFiltersButton)
        self.aciklamaSayisiLabel = QLabel(self)
        self.aciklamaSayisiLabel.setText(
            f"Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama"
        )
        self.aciklamaSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.aciklamaSayisiLabel)

        # Bilgi etiketi
        self.bilgiLabel = surukle_bilgi_etiketi(self)
        self.layout.addWidget(self.bilgiLabel)

        # Sürükle-bırak listesi
        self.suruklemeListe = SuruklemeListe(self)
        self.suruklemeListe.itemDoubleClicked.connect(self.surukleListeItemDuzenle)
        self.suruklemeListe.siralama_degisti.connect(self.suruklemeSiralamaKaydet)
        w, h = calculate_scroll_area_size(580, 300)
        self.suruklemeListe.setMinimumSize(w, h)
        self.layout.addWidget(self.suruklemeListe)

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
        if (
            event.key() == Qt.Key.Key_Z
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            self.undoSil()
        elif (
            event.key() == Qt.Key.Key_F
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak açıklama:")
            if ok:
                self.searchAciklama(text)
        else:
            super().keyPressEvent(event)

    def searchAciklama(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, aciklama in enumerate(self.repo_data[ACIKLAMALAR]):
            item = self.suruklemeListe.item(idx)
            if item:
                match = (
                    query.replace("İ", "i").lower()
                    in aciklama.replace("İ", "i").lower()
                )
                item.setHidden(not match)
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
        for i in range(self.suruklemeListe.count()):
            self.suruklemeListe.item(i).setHidden(False)
        self.clearFiltersButton.hide()
        self.aciklamaSayisiLabel.setText(
            f"Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama"
        )

    def aciklamaListele(self):
        self.aciklamaSayisiLabel.setText(
            f"Toplam {len(self.repo_data[ACIKLAMALAR])} açıklama"
        )
        self.clearFiltersButton.hide()

        # Sürükle-bırak listesini doldur
        self.suruklemeListe.clear()
        for i, aciklama in enumerate(self.repo_data[ACIKLAMALAR]):
            item = SuruklemeListeItem(
                f"📝 {i + 1}: {kisaltMetin(aciklama)}",
                data=aciklama,
                index=i
            )
            item.setToolTip(aciklama)
            self.suruklemeListe.addItem(item)

    def surukleListeItemDuzenle(self, item):
        """Sürükle-bırak listesinde çift tıklanan öğeyi düzenle"""
        idx = self.suruklemeListe.row(item)
        self.aciklamaDuzenle(idx)

    def suruklemeSiralamaKaydet(self):
        """Sürükle-bırak sonrası yeni sıralamayı kaydet"""
        yeni_siralama = []
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            yeni_siralama.append(item.custom_data)
        self.repo_data[ACIKLAMALAR] = yeni_siralama
        self.jsonGuncelle()
        # Sürükle-bırak listesindeki item metinlerini güncelle
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            item.setText(f"📝 {i + 1}: {kisaltMetin(item.custom_data)}")
        show_success(self, "Sıralama kaydedildi.")

    def yenile(self):
        self.aciklamaListele()

    def aciklamaDuzenle(self, index):
        aciklama = self.repo_data[ACIKLAMALAR][index]
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Düzenle", "Açıklama:", aciklama
        )
        if ok and yeni_aciklama:
            if yeni_aciklama == aciklama:
                return  # Değişiklik yok
            self.repo_data[ACIKLAMALAR][index] = yeni_aciklama
            self.jsonGuncelle()
            show_success(self, "Açıklama başarıyla güncellendi.")
        elif ok and yeni_aciklama == "":
            QMessageBox.warning(self, "Uyarı", "Açıklama boş bırakılamaz.")

    def aciklamaSil(self, index):
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu açıklamayı silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            # Silmeden önce undo için kaydet
            silinen_aciklama = self.repo_data[ACIKLAMALAR][index]
            self.undo_manager.push_deleted(index, silinen_aciklama, "aciklama")
            del self.repo_data[ACIKLAMALAR][index]
            self.jsonGuncelle()
            show_success(self, "Açıklama başarıyla silindi. (Geri almak için Ctrl+Z)")

    def undoSil(self):
        """Son silinen açıklamayı geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, aciklama, _ = deleted
            # Silinen açıklamayı orijinal yerine geri ekle
            if index <= len(self.repo_data[ACIKLAMALAR]):
                self.repo_data[ACIKLAMALAR].insert(index, aciklama)
            else:
                self.repo_data[ACIKLAMALAR].append(aciklama)
            self.jsonGuncelle()
            show_success(self, "Açıklama geri alındı.")

    def aciklamaEkle(self):
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, "Açıklama Ekle", "Yeni Açıklama:"
        )
        if ok and yeni_aciklama:
            self.repo_data[ACIKLAMALAR].append(yeni_aciklama)
            self.jsonGuncelle()
            show_success(self, "Açıklama başarıyla eklendi.")
        elif ok and yeni_aciklama == "":
            QMessageBox.warning(self, "Uyarı", "Açıklama boş bırakılamaz.")

    def jsonGuncelle(self):
        with open(self.json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(self.repo_data, file, indent=4, ensure_ascii=False)
        self.yenile()


class RepoKullanimiDialog(QDialog):
    def __init__(self, json_dosyasi=REPO_KULLANIMI_JSON_PATH, parent=None):
        super().__init__(parent)
        self.setModal(True)
        apply_minimum_size(self, 600, 300)  # Ekrana göre dinamik boyut
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
        if ok and yeni_baslik:
            if yeni_baslik == eski_baslik:
                return  # Değişiklik yok
            self.repo_data[BASLIK] = yeni_baslik
            self.jsonGuncelle()
            self.baslikBtn.setText(
                self.baslikBtn.text().replace(
                    eski_baslik, kisaltMetin(self.repo_data[BASLIK])
                )
            )
            self.baslikBtn.setToolTip(self.repo_data[BASLIK])
            show_success(self, "Başlık başarıyla güncellendi.")
        elif ok and yeni_baslik == "":
            QMessageBox.warning(self, "Uyarı", "Başlık boş bırakılamaz.")

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
        dialog = TalimatDialog(parent=self)
        dialog.exec()

    def acKavramDialog(self):
        dialog = KavramDialog(parent=self)
        dialog.exec()

    def acAciklamaDialog(self):
        dialog = AciklamaDialog(parent=self)
        dialog.exec()
