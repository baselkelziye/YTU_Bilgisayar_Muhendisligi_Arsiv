import requests
import unicodedata
import json
import copy
from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import (
    QDialog,
    QVBoxLayout,
    QInputDialog,
    QSizePolicy,
    QPushButton,
    QMessageBox,
    QComboBox,
    QLineEdit,
    QLabel,
    QHBoxLayout,
    QScrollArea,
    QWidget,
)
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
from threadler import HocaKaydetThread
from helpers.progress_dialog_helper import CustomProgressDialog
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
from degiskenler import *
from PyQt6.QtGui import QIcon
from metin_islemleri import kisaltMetin
from screen_utils import apply_minimum_size
from close_event import closeEventHandler
from toast_notification import show_success
from link_kontrol_window import LinkKontrolWindow
from undo_manager import UndoManager


class HocaEkleGuncelleWindow(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.is_programmatic_close = False
        self.undo_manager = UndoManager()
        self.data = self.jsonDosyasiniYukle()
        self.initial_data = copy.deepcopy(self.data)
        if self.ilklendir():
            self.jsonKaydet()
            self.initial_data = copy.deepcopy(self.data)
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Hocaları Ekle/Güncelle")
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        apply_minimum_size(self, 800, 600)  # Ekrana göre dinamik boyut
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)  # Mavi arka plan
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        bolum_adi = self.data.get(BOLUM_ADI, VARSAYILAN_HOCA_BOLUM_ADI)
        aciklama = self.data.get(BOLUM_ACIKLAMASI, VARSAYILAN_HOCA_BOLUM_ACIKLAMASI)
        # Bölüm adı label
        self.bolumAdiLabel = QLabel("Bölüm Adı")
        self.bolumAdiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.bolumAdiLabel)
        # Bölüm adı buton
        self.bolumAdiBtn = QPushButton(kisaltMetin(bolum_adi))
        self.bolumAdiBtn.setStyleSheet(BASLIK_BUTON_STILI)
        self.bolumAdiBtn.clicked.connect(self.bolumAdiDuzenle)
        self.bolumAdiBtn.setToolTip(bolum_adi)
        self.mainLayout.addWidget(self.bolumAdiBtn)
        # Bölüm açıklaması label
        self.bolumAciklamasiLabel = QLabel("Bölüm Açıklaması")
        self.bolumAciklamasiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.bolumAciklamasiLabel)
        # Bölüm açıklaması buton
        self.bolumAciklamasiBtn = QPushButton(kisaltMetin(aciklama))
        self.bolumAciklamasiBtn.setStyleSheet(ACIKLAMA_BUTON_STILI)
        self.bolumAciklamasiBtn.clicked.connect(self.bolumAciklamaDuzenle)
        self.bolumAciklamasiBtn.setToolTip(aciklama)
        self.mainLayout.addWidget(self.bolumAciklamasiBtn)
        # Hoca ekleme butonu
        self.ekleBtn = QPushButton("Hoca Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan
        self.ekleBtn.clicked.connect(self.hocaEkle)
        self.mainLayout.addWidget(self.ekleBtn)

        # Kırık link kontrolü butonu
        self.linkKontrolBtn = QPushButton("🔗 Kırık Bağlantı Tetkiki", self)
        self.linkKontrolBtn.setStyleSheet(LINK_KONTROL_BUTONU_STILI)
        self.linkKontrolBtn.clicked.connect(self.kirikLinkKontrol)
        self.mainLayout.addWidget(self.linkKontrolBtn)

        # Hoca sayısını gösteren etiket
        self.hocaSayisiLabel = QLabel("Toplam 0 hoca")
        self.hocaSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.hocaSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)

        # Hocaları gösterecek iç içe geçmiş widget'lar oluştur
        self.scrollWidget = QWidget()
        self.hocalarLayout = QVBoxLayout(self.scrollWidget)
        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.hocalariYukle()

    def bolumAciklamaDuzenle(self):
        eski_deger = self.data[BOLUM_ACIKLAMASI]
        text, ok = SatirAtlayanInputDialog.getMultiLineText(
            self,
            "Bölüm Açıklaması",
            "Bölüm açıklaması:",
            text=eski_deger,
        )
        if ok:
            if text == eski_deger:
                return  # Değişiklik yok
            self.data[BOLUM_ACIKLAMASI] = text
            self.bolumAciklamasiBtn.setText(kisaltMetin(text))
            self.bolumAciklamasiBtn.setToolTip(text)
            self.jsonKaydet()
            show_success(self, "Bölüm açıklaması başarıyla güncellendi.")

    def bolumAdiDuzenle(self):
        eski_deger = self.data[BOLUM_ADI]
        text, ok = QInputDialog.getText(
            self,
            "Bölüm Adı",
            "Bölüm adı:",
            QLineEdit.EchoMode.Normal,
            text=eski_deger,
        )
        if ok:
            if text == eski_deger:
                return  # Değişiklik yok
            self.data[BOLUM_ADI] = text
            self.bolumAdiBtn.setText(kisaltMetin(text))
            self.bolumAdiBtn.setToolTip(text)
            self.jsonKaydet()
            show_success(self, "Bölüm adı başarıyla güncellendi.")

    def jsonKaydet(self):
        with open(HOCALAR_JSON_PATH, "w", encoding="utf-8") as file:
            json.dump(self.data, file, ensure_ascii=False, indent=4)

    def hasChanges(self):
        return self.data != self.initial_data

    def closeEvent(self, event):
        # Bu pencere değişiklikleri anında kaydediyor, soru sormadan kapat
        event.accept()

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
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak hoca:")
            if ok:
                self.searchHocalar(text)
        else:
            super().keyPressEvent(event)

    def undoSil(self):
        """Son silinen hocayı geri al"""
        if not self.undo_manager.can_undo():
            return
        deleted = self.undo_manager.pop_deleted()
        if deleted:
            index, hoca, _ = deleted
            # Silinen hocayı geri ekle
            if index <= len(self.data[HOCALAR]):
                self.data[HOCALAR].insert(index, hoca)
            else:
                self.data[HOCALAR].append(hoca)
            self.jsonKaydet()
            self.hocalariYenile()
            show_success(self, "Hoca geri alındı.")

    # Filtreleri temizleme fonksiyonu
    def clearFilters(self, is_clicked=True):
        for i in range(self.hocalarLayout.count()):
            widget = self.hocalarLayout.itemAt(i).widget()
            if isinstance(widget, QPushButton):
                widget.show()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
        self.hocaSayisiLabel.setText(
            f"Toplam {len(self.data[HOCALAR])} hoca"
        )  # Hoca sayısını etikette güncelle

    def searchHocalar(self, query):
        if query == "":
            self.clearFilters(is_clicked=False)
            return
        size = 0
        layout_count = self.hocalarLayout.count()
        for i in range(layout_count):
            widget = self.hocalarLayout.itemAt(i).widget()
            if isinstance(widget, QPushButton):
                hoca_ad = widget.text()
                if query.replace("İ", "i").lower() in hoca_ad.replace("İ", "i").lower():
                    widget.show()
                    size += 1
                else:
                    widget.hide()
        if size == len(self.sorted_hocalar):
            self.clearFilters(is_clicked=False)
            return
        self.hocaSayisiLabel.setText(f"{size} hoca bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()

    def jsonDosyasiniYukle(self):
        try:
            with open(HOCALAR_JSON_PATH, "r", encoding="utf-8") as file:
                return json.load(file)
        except Exception as e:
            return json.loads("{}")

    def ilklendir(self):
        ilklendirildi_mi = False
        if BOLUM_ADI not in self.data:
            self.data[BOLUM_ADI] = VARSAYILAN_HOCA_BOLUM_ADI
            ilklendirildi_mi = True
        if BOLUM_ACIKLAMASI not in self.data:
            self.data[BOLUM_ACIKLAMASI] = VARSAYILAN_HOCA_BOLUM_ACIKLAMASI
            ilklendirildi_mi = True
        if HOCALAR not in self.data:
            self.data[HOCALAR] = []
            ilklendirildi_mi = True
        return ilklendirildi_mi

    def hocalariYukle(self):
        self.data = self.jsonDosyasiniYukle()
        try:
            hoca_sayisi = len(self.data[HOCALAR])  # Hoca sayısını hesapla
            self.hocaSayisiLabel.setText(
                f"Toplam {hoca_sayisi} hoca"
            )  # Hoca sayısını etikette güncelle

            def turkce_kucult(text):
                # Unicode normalizasyonu
                text = unicodedata.normalize("NFKD", text)
                # Türkçe İ ve ı harflerinin doğru dönüşümü için özel durum
                text = text.lower().strip()
                return text

            def unvan_ve_isim_ayir(hoca):
                # Ünvanları ve sıralama önceliklerini tanımla
                ad = hoca[AD]
                for idx, unvan in enumerate(unvanlar):
                    if ad.startswith(unvan):
                        # Ünvanın indeksi (önceliği) ve adı döndür
                        return idx, turkce_kucult(ad[len(unvan) :])

                # Eğer ünvan yoksa, listenin uzunluğu ve adı döndür
                return len(unvanlar), turkce_kucult(ad)

            # Hocaları önce ünvanlarına, sonra adlarına göre sırala
            self.sorted_hocalar = sorted(
                self.data[HOCALAR], key=lambda hoca: unvan_ve_isim_ayir(hoca)
            )

            for hoca in self.sorted_hocalar:
                if hoca[AD] != "":
                    btn = QPushButton(f"{hoca[AD]}", self.scrollWidget)
                    btn.clicked.connect(lambda checked, a=hoca: self.hocaDuzenle(a))
                    # derslerini alt alta ver
                    tmp_tool_tip = f"{AD}: {hoca.get(AD,'')}\n"
                    tmp_tool_tip += f"{OFIS}: {hoca.get(OFIS,'')}\n"
                    tmp_tool_tip += f"{LINK}: {hoca.get(LINK,'')}\n"
                    tmp_tool_tip += f"{HOCA_AKTIF_GOREVDE_MI}: {hoca.get(HOCA_AKTIF_GOREVDE_MI,'')}\n"
                    tmp_tool_tip += f"{ERKEK_MI}: {hoca[ERKEK_MI]}\n"
                    tmp_tool_tip += f"{DERSLER}\n" + "\n".join(
                        [ders for ders in hoca.get(DERSLER, [])]
                    )
                    btn.setToolTip(tmp_tool_tip)
                    btn.setStyleSheet(GUNCELLE_BUTTON_STILI)
                    self.hocalarLayout.addWidget(btn)
                else:
                    self.sorted_hocalar.remove(hoca)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya okunurken bir hata oluştu: {e}")

    def hocaEkle(self):
        # Yeni hoca ekleme penceresi
        self.hocaDuzenlemePenceresi = HocaDuzenlemeWindow(None, self.data, self)
        self.hocaDuzenlemePenceresi.show()

    def hocaDuzenle(self, hoca):
        # Mevcut hoca düzenleme penceresi
        self.hocaDuzenlemePenceresi = HocaDuzenlemeWindow(hoca, self.data, self)
        self.hocaDuzenlemePenceresi.show()

    def hocalariYenile(self):
        # Mevcut hoca butonlarını temizle
        for i in reversed(range(self.hocalarLayout.count())):
            widgetToRemove = self.hocalarLayout.itemAt(i).widget()
            self.hocalarLayout.removeWidget(widgetToRemove)
            widgetToRemove.setParent(None)
        self.hocalariYukle()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle

    def kirikLinkKontrol(self):
        """Tüm hocaların linklerini kontrol eder."""
        links = []
        for hoca in self.data.get(HOCALAR, []):
            hoca_adi = hoca.get(AD, "Bilinmeyen Hoca")
            link = hoca.get(LINK, "")
            if link and link.strip():
                links.append((hoca_adi, link))
        
        self.linkKontrolWindow = LinkKontrolWindow(
            links,
            title="Hoca Linkleri Kontrolü",
            parent=self
        )
        self.linkKontrolWindow.show()


# Hoca Düzenleme/Ekleme Penceresi
class HocaDuzenlemeWindow(QDialog):
    def __init__(self, hoca, data, parent):
        super().__init__(parent)
        self.hoca = hoca
        self.data = data
        self.parent = parent
        self.derslerComboBoxlar = []  # Hoca seçimi için ComboBox'lar listesi
        self.setModal(True)
        self.is_programmatic_close = False
        self.initUI()
        self.saveInitialState()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        if self.hoca is not None:
            self.setWindowTitle("Hoca Düzenle")
        else:
            self.setWindowTitle("Hoca Ekle")
        apply_minimum_size(self, 600, 650)  # Ekrana göre dinamik boyut
        self.layout = QVBoxLayout(self)
        # Ünvan için alan
        self.unvan_label = QLabel("Ünvan")
        self.unvan_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.unvan_label)
        self.unvanInput = QComboBox(self)
        self.unvanInput.addItems(unvanlar)
        self.layout.addWidget(self.unvanInput)
        # Hoca adı için alan
        ad = self.hoca[AD] if self.hoca else ""
        ad, unvan = self.ayiklaUnvan(ad)
        # Ünvanı ayarla
        if unvan in unvanlar:
            self.unvanInput.setCurrentIndex(unvanlar.index(unvan))
        self.ad_label = QLabel("Ad")
        self.ad_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.ad_label)
        self.adInput = QLineEdit(ad)
        self.layout.addWidget(self.adInput)

        # Hoca ofisi için alan
        self.ofis_label = QLabel("Ofis")
        self.ofis_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.ofis_label)
        self.ofisInput = QLineEdit(self.hoca.get(OFIS, "") if self.hoca else "")
        self.layout.addWidget(self.ofisInput)

        # Hoca linki için alan
        self.link_label = QLabel("Link")
        self.link_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.link_label)
        self.linkInput = QLineEdit(self.hoca.get(LINK, "") if self.hoca else "")
        self.layout.addWidget(self.linkInput)
        # Hoca aktif görevde mi için alan
        self.aktif_mi_label = QLabel("Aktif görevde mi?")
        self.aktif_mi_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.aktif_mi_label)
        self.aktifGorevdeInput = QComboBox(self)
        self.aktifGorevdeInput.addItems(["Evet", "Hayır"])
        if self.hoca:
            self.aktifGorevdeInput.setCurrentIndex(
                0 if self.hoca.get(HOCA_AKTIF_GOREVDE_MI, True) else 1
            )
        self.layout.addWidget(self.aktifGorevdeInput)
        # Hoca cinsiyet durumu için alan
        self.erkek_mi_label = QLabel("Erkek mi?")
        self.erkek_mi_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.erkek_mi_label)
        self.erkekMiInput = QComboBox(self)
        self.erkekMiInput.addItems(["Evet", "Hayır"])
        if self.hoca:
            self.erkekMiInput.setCurrentIndex(0 if self.hoca.get(ERKEK_MI, "") else 1)
        self.layout.addWidget(self.erkekMiInput)
        self.progressDialog = CustomProgressDialog("Kontrol Ediliyor...", self)
        self.progressDialog.close()
        # Diğer bilgiler ve dersler buraya eklenebilir
        self.dersler = self.dersleriYukle()
        # Derslerin sadece AD alanını al ve adlarına göre sırala
        self.dersler = sorted(
            [ders[AD] for ders in self.dersler],
            key=lambda x: unicodedata.normalize(NFKD, x),
        )
        self.hocanin_verdig_dersler_label = QLabel("Hocanın Verdiği Dersler")
        self.hocanin_verdig_dersler_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.hocanin_verdig_dersler_label)

        # Hocalar için kaydırılabilir alan oluştur
        self.derslerScorllArea = QScrollArea(self)  # ScrollArea oluştur
        self.derslerScorllArea.setWidgetResizable(True)
        # Hocaların gösterileceği widget
        self.dersScrollWidget = QWidget()
        # ScrollArea genişliğini dersScrollWidget genişliğiyle sınırla
        self.derslerLayout = QVBoxLayout(self.dersScrollWidget)
        self.derslerScorllArea.setWidget(
            self.dersScrollWidget
        )  # ScrollArea'ya widget ekle
        self.layout.addWidget(self.derslerScorllArea)  # Ana layout'a ScrollArea ekle
        if self.hoca and DERSLER in self.hoca:
            for ders in self.hoca[DERSLER]:
                self.dersEkleComboBox(ders)
        # Ekle (+) butonu
        self.ekleHocaBtn = QPushButton("Hocanın Verdiği Ders Ekle", self)
        self.ekleHocaBtn.setStyleSheet(VEREN_EKLE_BUTONU_STILI)
        self.ekleHocaBtn.clicked.connect(self.dersEkleComboBox)
        self.layout.addWidget(self.ekleHocaBtn)
        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        buttonsLayout = QHBoxLayout()

        if self.hoca is not None:
            self.kaydetBtn = QPushButton("Değişiklikleri Kaydet", self)
        else:
            self.kaydetBtn = QPushButton("Ekle", self)
        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydetBtn)  # buttonsLayout'a Kaydet butonunu ekle

        if self.hoca:
            self.silBtn = QPushButton("Hocayı Sil", self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet(SIL_BUTONU_STILI)
            buttonsLayout.addWidget(self.silBtn)  # buttonsLayout'a Sil butonunu ekle

        # Yatay düzeni ana düzene ekle
        self.layout.addLayout(buttonsLayout)

    def keyPressEvent(self, event):
        if (
            event.key() == Qt.Key.Key_S
            and event.modifiers() & Qt.KeyboardModifier.ControlModifier
        ):
            self.kaydet()

    def saveInitialState(self):
        """Başlangıç değerlerini kaydet"""
        self.initial_unvan = self.unvanInput.currentText()
        self.initial_ad = self.adInput.text()
        self.initial_ofis = self.ofisInput.text()
        self.initial_link = self.linkInput.text()
        self.initial_aktif = self.aktifGorevdeInput.currentText()
        self.initial_erkek = self.erkekMiInput.currentText()
        self.initial_dersler = self.secilenDersleriDondur()

    def hasChanges(self):
        """Değişiklik olup olmadığını kontrol et"""
        return (
            self.unvanInput.currentText() != self.initial_unvan or
            self.adInput.text() != self.initial_ad or
            self.ofisInput.text() != self.initial_ofis or
            self.linkInput.text() != self.initial_link or
            self.aktifGorevdeInput.currentText() != self.initial_aktif or
            self.erkekMiInput.currentText() != self.initial_erkek or
            self.secilenDersleriDondur() != self.initial_dersler
        )

    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close, self.hasChanges())

    def dersEkleComboBox(self, hoca_ders=None):
        if len(self.dersler) == 0:
            QMessageBox.critical(
                self, "Hata", "Herhangi bir ders bulunamadı. Lütfen önce ders ekleyin."
            )
            return
        # Yeni ComboBox oluştur
        comboBox = QComboBox(self)
        for ders in self.dersler:
            comboBox.addItem(ders)  # dersi ekle

        # Eğer ders verildiyse, onu ComboBox'da seç
        if hoca_ders:
            comboBox.setCurrentText(hoca_ders)

        # Sil (-) butonu
        silBtn = QPushButton("Hocanın Verdiği Dersi Sil", self)
        # Butonun boyutunu maksimuma ayarla
        sizePolicy = QSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
        )
        silBtn.setSizePolicy(sizePolicy)
        silBtn.setStyleSheet(SIL_BUTONU_STILI)
        silBtn.clicked.connect(lambda: self.silDersComboBox(comboBox, silBtn))

        derslerLayout = QHBoxLayout()
        derslerLayout.addWidget(comboBox)
        derslerLayout.addWidget(silBtn)
        self.derslerLayout.addLayout(
            derslerLayout
        )  # Hoca layout'una ekle, bu self.hocaScrollWidget'a bağlı

        # ComboBox listesini güncelle
        self.derslerComboBoxlar.append((comboBox, silBtn))

    def silDersComboBox(self, comboBox, silBtn):
        # ComboBox ve sil butonunu kaldır
        self.derslerLayout.removeWidget(comboBox)
        comboBox.deleteLater()
        self.derslerLayout.removeWidget(silBtn)
        silBtn.deleteLater()
        # Listeden kaldır
        self.derslerComboBoxlar.remove((comboBox, silBtn))

    def secilenDersleriDondur(self):
        ders_listesi = []
        for derslerComboboxTuple in self.derslerComboBoxlar:
            comboBox = derslerComboboxTuple[0]
            ders_listesi.append(comboBox.currentText())

        return ders_listesi  # Ders listesini döndür

    def dersleriYukle(self):
        try:
            with open(DERSLER_JSON_PATH, "r", encoding="utf-8") as file:
                ders_data = json.load(file)
            return ders_data[DERSLER]
        except Exception as e:
            return []

    def ayiklaUnvan(self, ad):
        for unvan in unvanlar:
            if ad.startswith(unvan):
                return ad[len(unvan) + 1 :], unvan  # İsim ve ünvanı ayır
        return ad, ""  # Eğer ünvan yoksa

    def check_url(self, url):
        try:
            response = requests.head(url, allow_redirects=True, timeout=5)
            # Burada HTTP durum kodunu kontrol ediyoruz, 200 başarılı anlamına gelir.
            if response.status_code == 200:
                return True
            else:
                QMessageBox.critical(
                    self, "Geçersiz URL", f"URL geçerli değil veya erişilemiyor: {url}"
                )
                return False
        except requests.RequestException as e:
            # Erişimde bir hata oluştuğunda hata mesajını göster
            QMessageBox.critical(
                self, "Geçersiz URL", f"URL kontrolü sırasında bir hata oluştu: {e}"
            )
            return False

    def kaydet(self):

        self.thread = HocaKaydetThread(self.hoca, self.data, self)
        self.thread.finished.connect(
            self.islemTamamlandi
        )  # İşlem bittiğinde çağrılacak fonksiyon
        self.thread.error.connect(self.hataMesajiGoster)  # Hata mesajı sinyalini bağla
        # ProgressDialog'u göster
        self.progressDialog.show()
        self.thread.start()  # Thread'i başlat

    def islemTamamlandi(self):
        # ProgressBar'ı gizle ve gerekli güncellemeleri yap
        self.progressDialog.hide()
        self.kaydetVeKapat()  # Kaydetme işlemini tamamla

    def hataMesajiGoster(self, message):
        # ProgressBar'ı gizle ve gerekli güncellemeleri yap
        self.progressDialog.hide()
        QMessageBox.warning(self, "Hata", message)

    def sil(self):
        # Hocayı sil
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Hocayı silmek istediğinden emin misin?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes and self.hoca:
            # Silmeden önce undo için kaydet
            hoca_index = self.data[HOCALAR].index(self.hoca)
            self.parent.undo_manager.push_deleted(hoca_index, self.hoca, "hoca")
            self.data[HOCALAR].remove(self.hoca)
            self.kaydetVeKapat(silindi=True)

    def derslereHocayiEkle(self):
        secilen_dersler = self.secilenDersleriDondur()
        ad = self.unvanInput.currentText() + " " + self.adInput.text()
        kisaltma = hoca_kisaltma_olustur(ad)
        try:
            with open(DERSLER_JSON_PATH, "r", encoding="utf-8") as file:
                dersler_data = json.load(file)
        except Exception as e:
            dersler_data = {
                DERSLER: []
            }  # JSON yükleme yerine doğrudan bir sözlük atayın

        try:
            for ders in dersler_data.get(DERSLER, []):
                # Eğer ders seçilen dersler listesindeyse ve hoca bu dersi vermiyorsa, hocayı ekleyin
                if ders[AD] in secilen_dersler and not any(
                    hoca[KISALTMA] == kisaltma
                    for hoca in ders.get(DERSI_VEREN_HOCALAR, [])
                ):
                    ders.setdefault(DERSI_VEREN_HOCALAR, []).append(
                        {AD: ad, KISALTMA: kisaltma}
                    )
                # Eğer ders seçilen dersler listesinde değilse ve hoca bu dersi veriyorsa, hocayı çıkarın
                elif ders[AD] not in secilen_dersler:
                    ders[DERSI_VEREN_HOCALAR] = [
                        hoca
                        for hoca in ders.get(DERSI_VEREN_HOCALAR, [])
                        if hoca[KISALTMA] != kisaltma
                    ]

            with open(DERSLER_JSON_PATH, "w", encoding="utf-8") as file:
                json.dump(dersler_data, file, ensure_ascii=False, indent=4)

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya işlenirken bir hata oluştu: {e}")

    def kaydetVeKapat(self, silindi=False):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            self.derslereHocayiEkle()
            with open(HOCALAR_JSON_PATH, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            self.parent.hocalariYenile()
            self.is_programmatic_close = True
            if silindi:
                show_success(self.parent, "Hoca başarıyla silindi. (Geri almak için Ctrl+Z)")
            else:
                show_success(self.parent, "Hoca başarıyla kaydedildi.")
            self.close()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")
