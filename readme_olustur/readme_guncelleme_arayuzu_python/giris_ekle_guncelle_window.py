from degiskenler import *
from PyQt6.QtWidgets import (
    QLabel,
    QLineEdit,
    QMessageBox,
    QPushButton,
    QHBoxLayout,
    QDialog,
    QVBoxLayout,
    QSizePolicy,
    QInputDialog,
    QWidget,
    QScrollArea,
)
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
from metin_islemleri import kisaltMetin
import json
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QIcon, QGuiApplication
import re
from helpers.surukleme_listesi import SuruklemeListe, SuruklemeListeItem, surukle_bilgi_etiketi
from close_event import closeEventHandler
from screen_utils import apply_minimum_size
from toast_notification import show_success
from undo_manager import UndoManager


class GirisEkleGuncelleWindow(QDialog):
    def __init__(self, parent):
        super().__init__(parent)
        self.setModal(True)
        self.is_programmatic_close = False
        self.undo_manager = UndoManager()
        self.data = self.jsonDosyasiniYukle()
        if self.ilklendir():
            self.jsonKaydet()
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Giriş Güncelleme")
        apply_minimum_size(self, 800, 600)  # Ekrana göre dinamik boyut
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        # Filtreleme için QLineEdit oluştur
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Başlık etiketi
        self.baslikLabel = QLabel("Başlık")
        self.baslikLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.baslikLabel)
        # Başlık butonu
        baslik = self.data.get(BASLIK, VARSAYILAN_GIRIS_BASLIK)
        self.baslikBtn = QPushButton(kisaltMetin(baslik), self)
        self.baslikBtn.setStyleSheet(BASLIK_BUTON_STILI)
        self.baslikBtn.clicked.connect(self.baslikDuzenle)
        self.baslikBtn.setToolTip(baslik)
        self.mainLayout.addWidget(self.baslikBtn)

        # Açıklama etiketi ve butonu
        aciklama = self.data.get(ACIKLAMA, VARSAYILAN_GIRIS_ACIKLAMA)
        self.aciklama_label = QLabel("Açıklama", self)
        self.aciklama_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.aciklama_label)
        self.aciklama_duzenle_btn = QPushButton(kisaltMetin(aciklama), self)
        self.aciklama_duzenle_btn.setStyleSheet(ACIKLAMA_BUTON_STILI)
        self.aciklama_duzenle_btn.setToolTip(
            aciklama
        )  # Tam metni araç ipucu olarak ekle
        self.aciklama_duzenle_btn.clicked.connect(
            lambda: self.aciklamaDuzenle(ACIKLAMA)
        )
        self.mainLayout.addWidget(self.aciklama_duzenle_btn)

        # Not ekleme butonu
        self.ekleBtn = QPushButton("İçindekiler Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan, beyaz yazı
        self.ekleBtn.clicked.connect(self.notEkle)
        self.mainLayout.addWidget(self.ekleBtn)  # Ana layout'a ekle butonunu ekle

        # Not sayısını gösteren etiket
        self.notSayisiLabel = QLabel("Toplam 0 içindekiler")
        self.notSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.notSayisiLabel)

        # Bilgi etiketi
        self.bilgiLabel = surukle_bilgi_etiketi(self)
        self.mainLayout.addWidget(self.bilgiLabel)

        # Sürükle-bırak listesi
        self.suruklemeListe = SuruklemeListe(self)
        self.suruklemeListe.itemDoubleClicked.connect(self.surukleListeItemDuzenle)
        self.suruklemeListe.siralama_degisti.connect(self.suruklemeSiralamaKaydet)
        self.mainLayout.addWidget(self.suruklemeListe)

        self.notlariYukle()

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
        """Son silinen içindekileri geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, icindekiler, _ = deleted
            # Silinen içindekileri geri ekle
            if index <= len(self.data[ICINDEKILER]):
                self.data[ICINDEKILER].insert(index, icindekiler)
            else:
                self.data[ICINDEKILER].append(icindekiler)
            self.jsonKaydet()
            self.notlariYenile()
            show_success(self, "İçindekiler geri alındı.")

    def ilklendir(self):
        ilklendirildi = False
        if ICINDEKILER not in self.data:
            self.data[ICINDEKILER] = []
            ilklendirildi = True
        if BASLIK not in self.data:
            self.data[BASLIK] = VARSAYILAN_GIRIS_BASLIK
            ilklendirildi = True
        if ACIKLAMA not in self.data:
            self.data[ACIKLAMA] = VARSAYILAN_GIRIS_ACIKLAMA
            ilklendirildi = True
        return ilklendirildi

    def notlariYukle(self):
        self.data = self.jsonDosyasiniYukle()
        try:
            icindekiler_sayisi = len(self.data[ICINDEKILER])  # Not sayısını hesapla
            self.notSayisiLabel.setText(
                f"Toplam {icindekiler_sayisi} içindekiler"
            )  # Not sayısını etikette güncelle

            # Sürükle-bırak listesini doldur
            self.suruklemeListe.clear()
            for idx, not_ in enumerate(self.data[ICINDEKILER]):
                item = SuruklemeListeItem(
                    f"📌 {idx + 1}: {kisaltMetin(not_)}",
                    data=not_,
                    index=idx
                )
                item.setToolTip(not_)
                self.suruklemeListe.addItem(item)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya okunurken bir hata oluştu: {e}")

    def surukleListeItemDuzenle(self, item):
        """Sürükle-bırak listesinde çift tıklanan öğeyi düzenle"""
        idx = self.suruklemeListe.row(item)
        self.notDuzenle(idx)

    def suruklemeSiralamaKaydet(self):
        """Sürükle-bırak sonrası yeni sıralamayı kaydet"""
        yeni_siralama = []
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            yeni_siralama.append(item.custom_data)
        self.data[ICINDEKILER] = yeni_siralama
        self.jsonKaydet()
        # Sürükle-bırak listesindeki item metinlerini güncelle
        for i in range(self.suruklemeListe.count()):
            item = self.suruklemeListe.item(i)
            item.setText(f"📌 {i + 1}: {kisaltMetin(item.custom_data)}")
        show_success(self, "Sıralama kaydedildi.")

    def notlariYenile(self):
        self.notlariYukle()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle

    def jsonDosyasiniYukle(self):
        try:
            with open(GIRIS_JSON_PATH, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return json.loads("{}")

    def jsonKaydet(self):
        try:
            with open(GIRIS_JSON_PATH, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")

    # Filtreleri temizleme fonksiyonu
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
            # Tüm öğeleri göster
            for i in range(self.suruklemeListe.count()):
                self.suruklemeListe.item(i).setHidden(False)
            self.clearFiltersButton.hide()
            self.notSayisiLabel.setText(
                f"Toplam {len(self.data[ICINDEKILER])} içindekiler"
            )

    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, not_ in enumerate(self.data[ICINDEKILER]):
            item = self.suruklemeListe.item(idx)
            if item:
                if query.replace("İ", "i").lower() in not_.replace("İ", "i").lower():
                    item.setHidden(False)
                    size += 1
                else:
                    item.setHidden(True)
        if size == len(self.data[ICINDEKILER]):
            self.clearFilters(is_clicked=False)
            return
        self.notSayisiLabel.setText(f"{size} içindekiler bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def baslikDuzenle(self):
        self.aciklamaDuzenle(BASLIK)

    def aciklamaDuzenle(self, anahtar):
        eski_aciklama = self.data.get(anahtar, "")
        baslik = "Başlık" if anahtar == BASLIK else "Açıklama"
        yeni_aciklama, ok = SatirAtlayanInputDialog.getMultiLineText(
            self, f"{baslik} Düzenle", "Açıklama:", eski_aciklama
        )

        if ok and yeni_aciklama != eski_aciklama:
            self.data[anahtar] = yeni_aciklama
            if baslik == "Başlık":
                self.baslikBtn.setText(kisaltMetin(yeni_aciklama))
                self.baslikBtn.setToolTip(yeni_aciklama)
            else:
                self.aciklama_duzenle_btn.setText(kisaltMetin(yeni_aciklama))
                self.aciklama_duzenle_btn.setToolTip(yeni_aciklama)
            self.kaydet()

    def kaydet(self):
        try:
            with open(GIRIS_JSON_PATH, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            show_success(self, "Açıklama güncellendi ve kaydedildi!")
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")

    def notEkle(self):
        self.duzenlemePenceresi = IcindekilerDuzenleWindow(
            None, self.data, "", ICINDEKILER, GIRIS_JSON_PATH, self
        )
        self.duzenlemePenceresi.show()

    def notDuzenle(self, idx):
        self.duzenlemePenceresi = IcindekilerDuzenleWindow(
            idx,
            self.data,
            self.data.get(ICINDEKILER, [""])[idx],
            ICINDEKILER,
            GIRIS_JSON_PATH,
            self,
        )
        self.duzenlemePenceresi.show()


class IcindekilerDuzenleWindow(QDialog):
    def __init__(self, idx, data, metin, key, json_path, parent):
        super().__init__(parent)
        self.parent = parent
        self.idx = idx
        self.setModal(True)
        self.data = data
        self.key = key
        self.json_path = json_path
        self.is_programmatic_close = False
        eslesme = re.search(capa_deseni, metin)
        self.capa = None
        self.baslik = None
        # eşleşme var mı kontrolü
        if eslesme:
            self.baslik = eslesme.group(1)
            # eşleşme iki tane varsa ikincisi çapa oluyor büyüktür 2 kontrolü
            if eslesme.lastindex > 1:
                self.capa = eslesme.group(2)
        self.initUI()
        self.saveInitialState()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle(
            "İçindekileri Düzenle" if self.idx is not None else "İçindekiler Ekle"
        )
        self.resize(400, 300)
        self.layout = QVBoxLayout(self)
        # başlık için label bileşeni
        self.baslik_label = QLabel("İçerik Başlığı", self)
        self.baslik_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.baslik_label.setToolTip("İçerik başlığı giriniz. (Örneği Hocalar)")
        self.layout.addWidget(self.baslik_label)
        # başlık için line edit bileşeni
        self.baslik_input = QLineEdit(self)
        if self.baslik is not None:
            self.baslik_input.setText(self.baslik)
        self.layout.addWidget(self.baslik_input)
        # başlığa ait çapa için label bileşeni
        self.capa_label = QLabel("İçerik Çapası", self)
        self.capa_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.capa_label.setToolTip(
            "İçerik çapası giriniz. (Örneği hocalar) Çapa, içerik başlığına tıklanınca sayfanın o kısmına gitmek için kullanılır."
        )
        self.layout.addWidget(self.capa_label)
        # başlığa ait çapa için line edit bileşeni
        self.capa_input = QLineEdit(self)
        if self.capa is not None:
            self.capa_input.setText(self.capa)
        self.layout.addWidget(self.capa_input)

        buttonLayout = QHBoxLayout()
        self.kaydetBtn = QPushButton(
            "Değişiklikleri Kaydet" if self.idx is not None else "Ekle", self
        )
        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonLayout.addWidget(self.kaydetBtn)

        if self.idx is not None:
            self.silBtn = QPushButton("İçeriği Sil", self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet(SIL_BUTONU_STILI)
            buttonLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonLayout)
        self.center()

    def center(self):
        # Pencereyi ekranın ortasına al
        qr = self.frameGeometry()
        cp = QGuiApplication.instance().primaryScreen().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def saveInitialState(self):
        """Başlangıç değerlerini kaydet"""
        self.initial_baslik = self.baslik_input.text()
        self.initial_capa = self.capa_input.text()

    def hasChanges(self):
        """Değişiklik olup olmadığını kontrol et"""
        return (
            self.baslik_input.text() != self.initial_baslik or
            self.capa_input.text() != self.initial_capa
        )

    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close, self.hasChanges())

    def kaydet(self):
        baslik = self.baslik_input.text().strip()
        if not baslik:
            QMessageBox.warning(self, "Hata", "Başlık boş olamaz!")
            return
        capa = self.capa_input.text().strip()
        if not capa:
            QMessageBox.warning(self, "Hata", "Çapa boş olamaz!")
            return
        yeni_icindekiler = f"[{baslik}]({capa})"
        if self.idx is None:
            self.data[self.key].append(yeni_icindekiler)
        else:
            self.data[self.key][self.idx] = yeni_icindekiler

        self.kaydetVeKapat()

    def sil(self):
        if self.idx is not None:
            emin_mi = QMessageBox.question(
                self,
                "Silme Onayı",
                "Bu içeriği silmek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if emin_mi == QMessageBox.StandardButton.Yes:
                # Silmeden önce undo için kaydet
                silinen_icindekiler = self.data[self.key][self.idx]
                self.parent.undo_manager.push_deleted(self.idx, silinen_icindekiler, "icindekiler")
                del self.data[self.key][self.idx]
                self.kaydetVeKapat(silindi=True)

    def kaydetVeKapat(self, silindi=False):
        try:
            with open(self.json_path, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            self.parent.notlariYenile()
            self.is_programmatic_close = True
            if silindi:
                show_success(self.parent, "İçindekiler silindi! (Geri almak için Ctrl+Z)")
            else:
                show_success(self.parent, "İçindekiler başarıyla kaydedildi.")
            self.close()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")
