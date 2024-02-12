import json
from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import (
    QSizePolicy,
    QDialog,
    QInputDialog,
    QVBoxLayout,
    QPushButton,
    QMessageBox,
    QLineEdit,
    QLabel,
    QTextEdit,
    QComboBox,
    QScrollArea,
    QWidget,
    QHBoxLayout,
)
import locale
from PyQt6.QtGui import QIcon
from pathlib import Path
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
from degiskenler import *
from metin_islemleri import kisaltMetin
from close_event import closeEventHandler
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog

# Hoca adlarını ve kısaltmalarını hazırla
def hoca_sirala(hoca):
    ad = hoca[0].strip()
    # Ünvanı kontrol et ve bulunursa indeksini al, bulunamazsa None döndür
    unvan_indeksi = next((i for i, u in enumerate(unvanlar) if ad.startswith(u)), None)
    # Eğer ünvan bulunamazsa, listenin uzunluğunu + 1 kullan
    return (unvan_indeksi if unvan_indeksi is not None else len(unvanlar), ad)


class DersEkleGuncelleWindow(QDialog):
    def __init__(self,parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.parent = parent
        self.is_programmatic_close = False
        self.data = self.jsonDosyasiniYukle()
        if self.ilklendir():
            self.jsonKaydet()
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Ders Ekle/Güncelle")
        self.setMinimumSize(
            700, 200
        )  # Pencerenin en küçük olabileceği boyutu ayarlayın
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        self.clearFiltersButton = QPushButton("Filtreleri Temizle", self)
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)
        self.clearFiltersButton.clicked.connect(
            lambda: self.clearFilters(is_clicked=True)
        )
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Bölüm adı label
        self.bolumAdiLabel = QLabel(f"Bölüm Adı")
        self.bolumAdiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.bolumAdiLabel)
        bolum_adi = self.data.get(BOLUM_ADI, VARSAYILAN_DERS_BOLUM_ADI)
        aciklama = self.data.get(BOLUM_ACIKLAMASI, VARSAYILAN_DERS_BOLUM_ACIKLAMASI)
        # Bölüm adı buton
        self.bolumAdiBtn = QPushButton(f"{kisaltMetin(bolum_adi)}", self)
        self.bolumAdiBtn.clicked.connect(self.bolumAdiDuzenle)
        self.bolumAdiBtn.setStyleSheet(BASLIK_BUTON_STILI)
        self.bolumAdiBtn.setToolTip(bolum_adi)
        self.mainLayout.addWidget(self.bolumAdiBtn)
        # Bölüm açıklaması label
        self.bolumAciklamasiLabel = QLabel(f"Bölüm Açıklaması")
        self.bolumAciklamasiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.bolumAciklamasiLabel)
        # Bölüm açıklaması buton
        self.bolumAciklamasiBtn = QPushButton(f"{kisaltMetin(aciklama)}", self)
        self.bolumAciklamasiBtn.clicked.connect(self.bolumAciklamasiDuzenle)
        self.bolumAciklamasiBtn.setStyleSheet(ACIKLAMA_BUTON_STILI)
        self.bolumAciklamasiBtn.setToolTip(aciklama)
        self.mainLayout.addWidget(self.bolumAciklamasiBtn)
        # Ders ekleme butonu
        self.ekleBtn = QPushButton("Ders Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan
        self.ekleBtn.clicked.connect(self.dersEkle)
        self.mainLayout.addWidget(self.ekleBtn)

        # Ders sayısını gösteren etiket
        self.dersSayisiLabel = QLabel("Toplam 0 ders")
        self.dersSayisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.dersSayisiLabel)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)

        # Dersleri gösterecek widget
        self.scrollWidget = QWidget()
        self.derslerLayout = QVBoxLayout(self.scrollWidget)
        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        self.mainLayout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.dersleriYukle()

    def bolumAciklamasiDuzenle(self):
        yeni_baslik, ok = SatirAtlayanInputDialog.getMultiLineText(
            self,
            "Bölüm Açıklaması",
            "Bölüm Açıklamasını Giriniz:",
            self.data[BOLUM_ACIKLAMASI],
        )
        if ok:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Bölüm açıklamasını güncellemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.data[BOLUM_ACIKLAMASI] = yeni_baslik
                self.bolumAciklamasiBtn.setText(kisaltMetin(yeni_baslik))
                self.bolumAciklamasiBtn.setToolTip(yeni_baslik)
                self.jsonKaydet()
                QMessageBox.information(
                    self, "Başarılı", "Bölüm açıklaması güncellendi."
                )
            else:
                QMessageBox.information(
                    self, "İptal", "Bölüm açıklaması güncellenmedi."
                )

    def bolumAdiDuzenle(self):
        yeni_baslik, ok = QInputDialog.getText(
            self,
            "Bölüm Adı",
            "Bölüm Adını Giriniz:",
            QLineEdit.EchoMode.Normal,
            self.data[BOLUM_ADI],
        )
        if ok:
            cevap = QMessageBox.question(
                self,
                "Onay",
                "Bölüm adını güncellemek istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if cevap == QMessageBox.StandardButton.Yes:
                self.data[BOLUM_ADI] = yeni_baslik
                self.bolumAdiBtn.setText(kisaltMetin(yeni_baslik))
                self.bolumAdiBtn.setToolTip(yeni_baslik)
                self.jsonKaydet()
                QMessageBox.information(self, "Başarılı", "Bölüm adı güncellendi.")
            else:
                QMessageBox.information(self, "İptal", "Bölüm adı güncellenmedi.")

    def jsonKaydet(self):
        with open(DERSLER_JSON_PATH, "w", encoding="utf-8") as file:
            json.dump(self.data, file, ensure_ascii=False, indent=4)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_F and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            text, ok = QInputDialog.getText(self, "Arama", "Aranacak ders:")
            if ok:
                self.searchDersler(text)

    def searchDersler(self, query):
        size = 0
        layout_count = self.derslerLayout.count()
        for i in range(layout_count):
            layout = self.derslerLayout.itemAt(i)
            if isinstance(layout, QHBoxLayout):
                ders_ad = layout.itemAt(0).widget().toolTip()
                match = query.replace('İ','i').lower() in ders_ad.replace('İ','i').lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        if size == len(self.sorted_dersler):
            self.clearFilters(is_clicked=False)
            return
        self.dersSayisiLabel.setText(f"{size} ders bulundu")
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
            for i in range(self.derslerLayout.count()):
                layout = self.derslerLayout.itemAt(i)
                if isinstance(layout, QHBoxLayout):
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.dersSayisiLabel.setText(
                f"Toplam {len(self.data[DERSLER])} ders"
            )  # Ders sayısını etikette güncelle

    def jsonDosyasiniYukle(self):
        try:
            with open(DERSLER_JSON_PATH, "r", encoding="utf-8") as file:
                return json.load(file)
        except:
            return {}

    def ilklendir(self):
        ilklendirildi_mi = False
        if DERSLER not in self.data:
            self.data[DERSLER] = []
            ilklendirildi_mi = True
        if BOLUM_ADI not in self.data:
            self.data[BOLUM_ADI] = VARSAYILAN_DERS_BOLUM_ADI
            ilklendirildi_mi = True
        if BOLUM_ACIKLAMASI not in self.data:
            self.data[BOLUM_ACIKLAMASI] = VARSAYILAN_DERS_BOLUM_ACIKLAMASI
            ilklendirildi_mi = True
        if DERS_KLASORU_BULUNAMADI_MESAJI not in self.data:
            self.data[
                DERS_KLASORU_BULUNAMADI_MESAJI
            ] = VARSAYILAN_DERS_KLASORU_BULUNAMADI_MESAJI
            ilklendirildi_mi = True
        if GUNCEL_OLMAYAN_DERS_ACIKLAMASI not in self.data:
            self.data[
                GUNCEL_OLMAYAN_DERS_ACIKLAMASI
            ] = VARSAYILAN_GUNCEL_OLMAYAN_DERS_ACIKLAMASI
            ilklendirildi_mi = True
        return ilklendirildi_mi

    def dersleriYukle(self):
        try:
            # Öncelikle Türkçe locale'i dene
            locale.setlocale(locale.LC_ALL, "tr_TR.UTF-8")
        except locale.Error:
            try:
                # eğer sistemde tr dili yoksa linuxta böyle yüklenebilir
                # os.system('sudo locale-gen tr_TR.UTF-8')
                # Alternatif olarak başka bir Türkçe locale dene
                locale.setlocale(locale.LC_ALL, "tr_TR")
            except locale.Error:
                # Varsayılan locale'e geri dön
                locale.setlocale(locale.LC_ALL, "")
        try:
            self.data = self.jsonDosyasiniYukle()
            ders_sayisi = len(self.data[DERSLER])  # Ders sayısını hesapla
            self.dersSayisiLabel.setText(
                f"Toplam {ders_sayisi} ders"
            )  # Ders sayısını etikette güncelle

            # Dersleri ders adına göre Türkçe alfabetik olarak sırala (büyük/küçük harf duyarsız)
            self.sorted_dersler = sorted(
                self.data[DERSLER], key=lambda d: locale.strxfrm(d[AD].lower())
            )
            for ders in self.sorted_dersler:
                # Her ders için bir satır oluştur
                dersSatiri = QHBoxLayout()
                ders_adi = ders.get(AD, "")
                # Büyük ders butonu
                btnDers = QPushButton(
                    kisaltMetin(ders_adi, maks_uzunluk=30), self.scrollWidget
                )
                # hocaları alt alta ver
                tmp_tool_tip = f"{AD}:{ders.get(AD,'')}\n{YIL}:{ders.get(YIL, '')}\n{DONEM}:{ders.get(DONEM, '')}\n{GUNCEL_MI}:{ders.get(GUNCEL_MI, '')}\n{TIP}:{ders.get(TIP, '')}\n{DERSI_VEREN_HOCALAR}\n" + '\n'.join([hoca.get(AD,'') for hoca in ders.get(DERSI_VEREN_HOCALAR,[])])
                btnDers.setToolTip(tmp_tool_tip)
                btnDers.clicked.connect(lambda checked, a=ders: self.dersDuzenle(a))
                btnDers.setStyleSheet(GUNCELLE_BUTTON_STILI)
                dersSatiri.addWidget(btnDers)

                # Kaynak Ekle butonu
                btnKaynakEkle = QPushButton("Kaynak Ekle/Güncelle", self.scrollWidget)
                btnKaynakEkle.clicked.connect(
                    lambda checked, a=ders: self.kaynakEkle(a)
                )
                btnKaynakEkle.setStyleSheet(
                    EKLE_BUTONU_STILI
                )  # Yeşil renk, küçültülmüş genişlik
                dersSatiri.addWidget(btnKaynakEkle)

                # Öneri Ekle butonu
                btnOneriEkle = QPushButton("Öneri Ekle/Güncelle", self.scrollWidget)
                btnOneriEkle.clicked.connect(lambda checked, a=ders: self.oneriEkle(a))
                btnOneriEkle.setStyleSheet(
                    SIL_BUTONU_STILI
                )  # Kırmızı renk, küçültülmüş genişlik
                btnDers.setSizePolicy(QSizePolicy.Policy.MinimumExpanding, QSizePolicy.Policy.Fixed)
                dersSatiri.addWidget(btnOneriEkle)

                # Ders satırını dersler layout'una ekle
                self.derslerLayout.addLayout(dersSatiri)

        except Exception as e:
            QMessageBox.critical(self.parent, "Hata", f"Dosya okunurken bir hata oluştu: {e}")

    def oneriEkle(self, ders):
        # Öneri ekleme için KaynakVeOneriDuzenleyici sınıfını kullanarak bir pencere aç
        self.oneriDuzenleyiciPenceresi = KaynakVeOneriDuzenleyici(
            ders, DERSE_DAIR_ONERILER, self
        )
        self.oneriDuzenleyiciPenceresi.show()

    def kaynakEkle(self, ders):
        # Kaynak ekleme için KaynakVeOneriDuzenleyici sınıfını kullanarak bir pencere aç
        self.kaynakDuzenleyiciPenceresi = KaynakVeOneriDuzenleyici(
            ders, FAYDALI_OLABILECEK_KAYNAKLAR, self
        )
        self.kaynakDuzenleyiciPenceresi.show()

    def dersEkle(self):
        self.dersDuzenlemePenceresi = DersDuzenlemeWindow(None, self.data, self)
        self.dersDuzenlemePenceresi.show()

    def dersDuzenle(self, ders):
        self.dersDuzenlemePenceresi = DersDuzenlemeWindow(ders, self.data, self)
        self.dersDuzenlemePenceresi.show()

    def dersleriYenile(self):
        # Layout'taki tüm widget'ları temizle
        while self.derslerLayout.count():
            layoutItem = self.derslerLayout.takeAt(0)
            if layoutItem.widget() is not None:
                layoutItem.widget().deleteLater()
            elif layoutItem.layout() is not None:
                self.clearLayout(layoutItem.layout())

        self.dersleriYukle()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle

    def clearLayout(self, layout):
        while layout.count():
            item = layout.takeAt(0)
            widget = item.widget()
            if widget is not None:
                widget.deleteLater()
            else:
                self.clearLayout(item.layout())


class KaynakVeOneriDuzenleyici(QDialog):
    def __init__(self, ders, tur, parent):
        super().__init__(parent)
        self.ders = ders
        self.setModal(True)
        self.is_programmatic_close = False
        self.parent = parent
        self.tur = tur  # 'faydali_olabilecek_kaynaklar' veya 'derse_dair_oneriler'
        self.initUI()
        if os.path.exists(OSMANLI_ICO_PATH):
            self.setWindowIcon(QIcon(OSMANLI_ICO_PATH))

    def initUI(self):
        if self.tur == FAYDALI_OLABILECEK_KAYNAKLAR:
            self.setWindowTitle(f"{self.ders[AD]} - Kaynaklar")
        else:
            self.setWindowTitle(
                f"{self.ders[AD]} - {self.tur.replace('_', ' ').title()}"
            )

        self.layout = QVBoxLayout(self)

        # Ekle butonu
        self.ekleBtn = QPushButton("Ekle", self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Ekle butonunu yeşil yap
        self.ekleBtn.clicked.connect(self.yeniElemanEkle)
        self.layout.addWidget(self.ekleBtn)
        self.resize(600, 100)

        # Mevcut kaynaklar/öneriler için butonları oluştur
        self.elemanlariYukle()

    def elemanlariYukle(self):
        if self.tur in self.ders:
            for j, eleman in enumerate(self.ders[self.tur]):
                if self.tur == DERSE_DAIR_ONERILER:
                    if ONERILER in eleman:
                        for i, oneri in enumerate(eleman[ONERILER]):
                            satirLayout = QHBoxLayout()
                            label = QLabel(
                                f"Öneri Sahibi: {eleman[ONERI_SAHIBI]}", self
                            )
                            label.setAlignment(Qt.AlignmentFlag.AlignCenter)
                            satirLayout.addWidget(label)

                            # Bilgi (mesaj) butonu
                            infoBtn = QPushButton(kisaltMetin(oneri), self)
                            infoBtn.setToolTip(oneri)
                            infoBtn.clicked.connect(
                                lambda checked, a=eleman, j=j, i=i: self.elemanDuzenle(
                                    a, j, oneri_index=i
                                )
                            )
                            satirLayout.addWidget(infoBtn)
                            # Silme butonu
                            deleteBtn = QPushButton("Sil", self)
                            deleteBtn.setStyleSheet(
                                SIL_BUTONU_STILI
                            )  # Silme butonunu kırmızı yap
                            deleteBtn.clicked.connect(
                                lambda checked, a=eleman, j=j, i=i: self.elemanSil(
                                    a, oneri_index=i, sahip_index=j
                                )
                            )
                            satirLayout.addWidget(deleteBtn)
                            # Satır düzenini ana düzene ekle
                            self.layout.addLayout(satirLayout)

                else:
                    satirLayout = QHBoxLayout()
                    # Bilgi (mesaj) butonu
                    infoBtn = QPushButton(kisaltMetin(eleman), self)
                    infoBtn.setToolTip(eleman)
                    infoBtn.clicked.connect(
                        lambda checked, a=eleman, j=j: self.elemanDuzenle(
                            a, oneri_index=j
                        )
                    )
                    satirLayout.addWidget(infoBtn)

                    # Silme butonu
                    deleteBtn = QPushButton("Sil", self)
                    deleteBtn.setStyleSheet(
                        SIL_BUTONU_STILI
                    )  # Silme butonunu kırmızı yap
                    deleteBtn.clicked.connect(
                        lambda checked, a=eleman, j=j: self.elemanSil(a, oneri_index=j)
                    )
                    satirLayout.addWidget(deleteBtn)
                    # Satır düzenini ana düzene ekle
                    self.layout.addLayout(satirLayout)

    def elemanSil(self, eleman, sahip_index=None, oneri_index=None):
        # Kullanıcıya silme işlemi için onay sor
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Bu öğeyi silmek istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )

        if emin_mi == QMessageBox.StandardButton.Yes:
            # JSON dosyasını aç ve güncelle
            with open(DERSLER_JSON_PATH, "r+", encoding="utf-8") as file:
                data = json.load(file)

                # İlgili dersi data içinden bul
                ders = next((d for d in data[DERSLER] if d[AD] == self.ders[AD]), None)
                if ders and self.tur in ders:
                    if (
                        self.tur == DERSE_DAIR_ONERILER
                        and sahip_index is not None
                        and oneri_index is not None
                    ):
                        # İlgili öneriyi sil
                        del ders[self.tur][sahip_index][ONERILER][oneri_index]
                        if len(ders[self.tur][sahip_index][ONERILER]) < 1:
                            # Öneri sahibinin önerisi kalmadı, öneri sahibini de sil
                            del ders[self.tur][sahip_index]
                            if len(ders[self.tur]) < 1:
                                # Öneri kalmadı, alanı sil
                                del ders[self.tur]
                    elif self.tur != DERSE_DAIR_ONERILER and oneri_index is not None:
                        # İlgili kaynağı sil
                        del ders[self.tur][oneri_index]
                        if len(ders[self.tur]) < 1:
                            # Kaynak kalmadı, alanı sil
                            del ders[self.tur]
                    # Değişiklikleri dosyaya yaz
                    file.seek(0)
                    json.dump(data, file, ensure_ascii=False, indent=4)
                    file.truncate()

            # Arayüzü güncelle
            self.arayuzuGuncelle()
    def arayuzuGuncelle(self):
        # Ebeveyn sınıfın dersleri yenileme metodunu çağır
        if self.parent and hasattr(self.parent, "dersleriYenile"):
            self.parent.dersleriYenile()

            # Ebeveynin veri setinde güncellenmiş ders bilgisini bul
            guncellenmisDers = next(
                (
                    ders
                    for ders in self.parent.data[DERSLER]
                    if ders[AD] == self.ders[AD]
                ),
                None,
            )
            if guncellenmisDers:
                # self.ders'i güncellenmiş bilgiyle değiştir
                self.ders = guncellenmisDers

        # Mevcut butonları ve etiketleri temizle
        self.temizle()

        # Güncellenmiş ders bilgileriyle elemanları yeniden yükle
        self.elemanlariYukle()

    def temizle(self):
        # Ekleme butonunu koru ve diğer widget'ları kaldır
        for i in reversed(range(self.layout.count())):
            widget = self.layout.itemAt(i).widget()
            if (
                widget is not None and widget != self.ekleBtn
            ):  # Ekleme butonu değilse kaldır
                self.layout.removeWidget(widget)
                widget.deleteLater()

    def temizle(self):
        # Ekleme butonunu koru ve diğer widget'ları kaldır
        for i in reversed(range(self.layout.count())):
            layoutItem = self.layout.itemAt(i)

            if layoutItem.widget() == self.ekleBtn:
                # Ekleme butonunu koru
                continue

            if layoutItem.widget():
                # Eğer düzgün bir widget ise, kaldır
                widget = layoutItem.widget()
                self.layout.removeWidget(widget)
                widget.deleteLater()
            elif layoutItem.layout():
                # Eğer bir alt düzen (sub-layout) ise, onun içindeki widget'ları kaldır
                self.temizleAltDuzen(layoutItem.layout())

    def temizleAltDuzen(self, layout):
        # Alt düzen içindeki widget'ları kaldır
        for i in reversed(range(layout.count())):
            layoutItem = layout.itemAt(i)

            if layoutItem.widget():
                widget = layoutItem.widget()
                layout.removeWidget(widget)
                widget.deleteLater()
            elif layoutItem.layout():
                # İç içe başka bir alt düzen varsa, onu da temizle
                self.temizleAltDuzen(layoutItem.layout())

    def yeniElemanEkle(self):
        # Yeni eleman ekleme dialogunu aç
        self.eklemeDialogu = YeniElemanEklemeDialog(
            self.tur, parent=self, ders=self.ders
        )
        self.eklemeDialogu.show()

    def elemanDuzenle(self, eleman, sahip_index=None, oneri_index=None):
        # Mevcut elemanı düzenleme dialogunu aç
        self.duzenlemeDialogu = YeniElemanEklemeDialog(
            self.tur, sahip_index, oneri_index, eleman, parent=self, ders=self.ders
        )
        self.duzenlemeDialogu.show()


class YeniElemanEklemeDialog(QDialog):
    def __init__(
        self,
        tur,
        sahip_index=None,
        oneri_index=None,
        mevcutEleman=None,
        parent=None,
        ders=None,
    ):
        super().__init__(parent)
        self.tur = tur
        self.setModal(True)
        self.is_programmatic_close = False
        self.parent = parent
        self.sahip_index = sahip_index  # Güncellenecek önerinin indeksi
        self.oneri_index = oneri_index  # Güncellenecek önerinin indeksi
        self.mevcutEleman = mevcutEleman  # Güncellenecek mevcut eleman
        self.ders = ders
        self.initUI()
        if os.path.exists(OSMANLI_ICO_PATH):
            self.setWindowIcon(QIcon(OSMANLI_ICO_PATH))

    def initUI(self):
        self.layout = QVBoxLayout(self)
        self.setMinimumSize(
            400, 200
        )  # Pencerenin en küçük olabileceği boyutu ayarlayın
        # Öneri sahibi ve öneri için etiket ve metin alanı
        if self.tur == DERSE_DAIR_ONERILER:
            self.label = QLabel("Öneri Sahibi", self)
            self.label.setAlignment(Qt.AlignmentFlag.AlignCenter)
            self.layout.addWidget(self.label)
            self.sahibiEdit = QLineEdit(self)
            self.setWindowTitle(
                "Öneri Ekle" if self.oneri_index is None else "Öneri Güncelle"
            )
            if self.mevcutEleman:
                self.sahibiEdit.setText(self.mevcutEleman[ONERI_SAHIBI])
            self.layout.addWidget(self.sahibiEdit)
            self.label = QLabel("Öneri", self)
        else:
            self.label = QLabel("Kaynak", self)
            self.setWindowTitle(
                "Kaynak Ekle" if self.oneri_index is None else "Kaynak Güncelle"
            )
        self.label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(self.label)
        self.metinEdit = QTextEdit(self)
        if self.mevcutEleman and self.tur == DERSE_DAIR_ONERILER:
            self.metinEdit.setText(self.mevcutEleman[ONERILER][self.oneri_index])
        else:
            self.metinEdit.setText(self.mevcutEleman)
        self.layout.addWidget(self.metinEdit)

        # Kaydet butonu
        self.kaydetBtn = QPushButton("Kaydet", self)
        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.layout.addWidget(self.kaydetBtn)
    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_S and event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            self.kaydet()
    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close)

    def kaydet(self):
        oneriSahibi = (
            self.sahibiEdit.text() if self.tur == DERSE_DAIR_ONERILER else None
        )
        metin = self.metinEdit.toPlainText()
        if not oneriSahibi and self.tur == DERSE_DAIR_ONERILER:
            QMessageBox.warning(self, "Hata", "Kaynak boş olamaz!")
            return
        if (not oneriSahibi and self.tur == DERSE_DAIR_ONERILER) or not metin:
            QMessageBox.warning(self, "Hata", "Öneri sahibi ve öneri boş olamaz!")
            return
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            f"Değişiklikleri Kaydetmek İstediğine Emin Misin?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if emin_mi != QMessageBox.StandardButton.Yes:
            return
        # JSON dosyasını aç ve güncelle
        with open(DERSLER_JSON_PATH, "r+", encoding="utf-8") as file:
            data = json.load(file)

            ders = next(
                (ders for ders in data[DERSLER] if ders[AD] == self.ders[AD]), None
            )
            if not ders:
                print("Belirtilen adla ders bulunamadı!")
                return  # Ders bulunamazsa
            if self.tur != DERSE_DAIR_ONERILER:
                # Faydalı olabilecek kaynaklar için işlemler
                if self.oneri_index is None:
                    # Yeni kaynak ekle
                    if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
                        ders[FAYDALI_OLABILECEK_KAYNAKLAR].append(metin)
                    else:
                        ders[FAYDALI_OLABILECEK_KAYNAKLAR] = [metin]
                else:
                    # Mevcut kaynağı güncelle
                    ders[FAYDALI_OLABILECEK_KAYNAKLAR][self.oneri_index] = metin
            else:
                # Derse dair öneriler için işlemler
                if oneriSahibi:
                    # Mevcut öneri sahibi değerini al
                    mevcutSahibi = (
                        self.ders[DERSE_DAIR_ONERILER][self.sahip_index][ONERI_SAHIBI]
                        if self.sahip_index is not None
                        else None
                    )

                    if mevcutSahibi != oneriSahibi:
                        # Öneri sahibi değişti, eski öneriyi sil
                        if (
                            self.sahip_index is not None
                            and self.oneri_index is not None
                        ):
                            del ders[DERSE_DAIR_ONERILER][self.sahip_index][ONERILER][
                                self.oneri_index
                            ]
                            if (
                                len(
                                    ders[DERSE_DAIR_ONERILER][self.sahip_index][
                                        ONERILER
                                    ]
                                )
                                < 1
                            ):
                                del ders[DERSE_DAIR_ONERILER][self.sahip_index]
                        # Yeni sahip için öneriyi ekle veya mevcut sahibi bul
                        if "derse_dair_oneriler" in ders:
                            matched = next(
                                (
                                    o
                                    for o in ders[DERSE_DAIR_ONERILER]
                                    if o[ONERI_SAHIBI] == oneriSahibi
                                ),
                                None,
                            )
                        else:
                            ders[DERSE_DAIR_ONERILER] = []
                            matched = None
                        if not matched:
                            # Yeni sahibi ve öneriyi ekle
                            matched = {ONERI_SAHIBI: oneriSahibi, ONERILER: []}
                            ders[DERSE_DAIR_ONERILER].append(matched)
                    else:
                        # Öneri sahibi aynı, mevcut sahibi kullan
                        matched = ders[DERSE_DAIR_ONERILER][self.sahip_index]

                    # Öneri ekle veya güncelle
                    if self.oneri_index is None or mevcutSahibi != oneriSahibi:
                        # Yeni öneri ekle
                        matched[ONERILER].append(metin)
                    else:
                        # Mevcut öneriyi güncelle
                        matched[ONERILER][self.oneri_index] = metin
            # Dosyayı baştan aç, güncellenmiş veriyi yaz ve kapat
            file.seek(0)
            json.dump(data, file, ensure_ascii=False, indent=4)
            file.truncate()
        QMessageBox.information(self, "Başarılı", "Değişiklikler kaydedildi!")
        self.parent.arayuzuGuncelle()
        self.is_programmatic_close = True
        self.close()


class DersDuzenlemeWindow(QDialog):
    def __init__(self, ders, data, parent):
        super().__init__(parent)
        self.is_programmatic_close = False
        self.ders = ders
        self.data = data
        self.parent = parent
        self.setModal(True)
        self.hocalarComboBoxlar = []  # Hoca seçimi için ComboBox'lar listesi
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setWindowTitle("Ders Düzenle/Ekle")

        self.layout = QVBoxLayout(self)
        self.setMinimumSize(
            535, 570
        )  # Pencerenin en küçük olabileceği boyutu ayarlayın
        # Ders adı için alan
        ders_adi_label = QLabel("Ders Adı", self)
        ders_adi_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(ders_adi_label)
        self.adInput = QLineEdit(self.ders.get(AD, "") if self.ders else "")
        self.layout.addWidget(self.adInput)

        # Ders yılı için alan
        yil_label = QLabel("Yıl", self)
        yil_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(yil_label)
        self.yilInput = QComboBox(self)
        self.yilInput.addItems(["0", "1", "2", "3", "4"])
        if self.ders:
            self.yilInput.setCurrentIndex(self.ders.get(YIL, 0))
        self.layout.addWidget(self.yilInput)

        # Ders dönemi için alan
        donem_label = QLabel("Dönem", self)
        donem_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(donem_label)
        self.donemInput = QComboBox(self)
        self.donemInput.addItems(DONEMLER_DIZISI_YOKLA_BERABER)
        if self.ders:
            self.donemInput.setCurrentText(self.ders.get(DONEM, YOK))
        self.layout.addWidget(self.donemInput)
        ders_guncel_mi_label = QLabel("Ders Güncel Mi", self)
        ders_guncel_mi_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(ders_guncel_mi_label)
        self.guncelMi = QComboBox(self)
        self.guncelMi.addItems(["False", "True"])
        if self.ders:
            self.guncelMi.setCurrentText(
                "True"
                if "guncel_mi" in self.ders and self.ders["guncel_mi"]
                else "False"
            )
        self.layout.addWidget(self.guncelMi)

        # Ders tipi için alan
        tip_label = QLabel("Tip", self)
        tip_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(tip_label)
        self.tipInput = QComboBox(self)
        self.tipInput.addItems(DERS_TIPLERI)
        if self.ders:
            self.tipInput.setCurrentText(self.ders.get(TIP, DERS_TIPLERI[0]))
        self.layout.addWidget(self.tipInput)
        dersi_veren_hocalar_label = QLabel("Dersi Veren Hocalar", self)
        dersi_veren_hocalar_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.layout.addWidget(dersi_veren_hocalar_label)
        # Dersi veren hocalar için ComboBox'lar
        # Mevcut hocaları yükle
        try:
            with open(HOCALAR_JSON_PATH, "r", encoding="utf-8") as file:
                hoca_data = json.load(file)
        except:
            hoca_data = {HOCALAR: []}
        hoca_listesi = [
            (h[AD], hoca_kisaltma_olustur(h[AD]))
            for h in hoca_data[HOCALAR]
            if h[AD].strip() and hoca_kisaltma_olustur(h[AD]).strip()
        ]

        self.hoca_listesi = sorted(hoca_listesi, key=hoca_sirala)

        # Hocalar için kaydırılabilir alan oluştur
        self.hocaScrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.hocaScrollArea.setWidgetResizable(True)

        # Hocaların gösterileceği widget
        self.hocaScrollWidget = QWidget()
        self.hocalarLayout = QVBoxLayout(self.hocaScrollWidget)
        self.hocaScrollArea.setWidget(
            self.hocaScrollWidget
        )  # ScrollArea'ya widget ekle
        self.layout.addWidget(self.hocaScrollArea)  # Ana layout'a ScrollArea ekle
        if self.ders and DERSI_VEREN_HOCALAR in self.ders:
            for hoca in self.ders[DERSI_VEREN_HOCALAR]:
                self.ekleHocaComboBox(hoca)
        # Ekle (+) butonu
        self.ekleHocaBtn = QPushButton("Dersi Veren Hoca Ekle", self)
        self.ekleHocaBtn.setStyleSheet(VEREN_EKLE_BUTONU_STILI)
        self.ekleHocaBtn.clicked.connect(self.ekleHocaComboBox)
        self.layout.addWidget(self.ekleHocaBtn)

        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        buttonsLayout = QHBoxLayout()
        if self.ders:
            self.kaydetBtn = QPushButton("Değişiklikleri Kaydet", self)
        else:
            self.kaydetBtn = QPushButton("Ekle", self)

        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydetBtn)

        if self.ders:
            self.silBtn = QPushButton("Dersi Sil", self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet(SIL_BUTONU_STILI)
            buttonsLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonsLayout)

    # Kapatma tuşuna basılırsa emin misin diye sor
    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close)
    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_S and event.modifiers() == Qt.KeyboardModifier.ControlModifier:
            self.kaydet()
    def ekleHocaComboBox(self, hoca=None):
        if len(self.hoca_listesi) < 1:
            QMessageBox.warning(self, "Hata", "Hoca listesi boş!")
            return

        # Yeni ComboBox oluştur
        comboBox = QComboBox(self)
        for ad, kisaltma in self.hoca_listesi:
            comboBox.addItem(f"{ad} ({kisaltma})", kisaltma)  # Ad ve kısaltmayı ekle

        # Eğer kısaltma verildiyse, onu ComboBox'da seç
        if hoca:
            comboBox.setCurrentText(f"{hoca[AD]} ({hoca['kisaltma']})")

        # Sil (-) butonu
        silBtn = QPushButton("Dersi Veren Hocayı Sil", self)
        # Butonun genişliğini sabitle
        silBtn.setStyleSheet(SIL_BUTONU_STILI)
        silBtn.clicked.connect(lambda: self.silHocaComboBox(comboBox, silBtn))

        hocaLayout = QHBoxLayout()
        hocaLayout.addWidget(comboBox)
        hocaLayout.addWidget(silBtn)
        self.hocalarLayout.addLayout(
            hocaLayout
        )  # Hoca layout'una ekle, bu self.hocaScrollWidget'a bağlı

        # ComboBox listesini güncelle
        self.hocalarComboBoxlar.append((comboBox, silBtn))
        if not hoca:
            QMessageBox.information(self, "Bilgi", "Listeye bir hoca eklendi!")

    def silHocaComboBox(self, comboBox, silBtn):
        # ComboBox ve sil butonunu kaldır
        self.hocalarLayout.removeWidget(comboBox)
        comboBox.deleteLater()
        self.hocalarLayout.removeWidget(silBtn)
        silBtn.deleteLater()
        # Listeden kaldır
        self.hocalarComboBoxlar.remove((comboBox, silBtn))

    def kaydet(self):
        ad = self.adInput.text().strip()
        try:
            yil = int(self.yilInput.currentText())
        except:
            yil = 0
        donem = self.donemInput.currentText()
        guncel_mi = self.guncelMi.currentText() == "True"
        tip = self.tipInput.currentText()
        if (yil == 0 or donem == YOK) and tip == ZORUNLU:
            if yil == 0:
                QMessageBox.warning(
                    self, "Hata", "Yıl bilgisi olmayan dersler " + ZORUNLU + " olamaz!"
                )
                return
            else:
                QMessageBox.warning(
                    self, "Hata", "Dönem bilgisi olmayan dersler " + ZORUNLU + " olamaz!"
                )
                return
        cevap = QMessageBox.question(
            self,
            "Onay",
            "Değişiklikleri Kaydetmek İstediğine Emin Misin?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if cevap != QMessageBox.StandardButton.Yes:
            return
        # Seçili hocaların kısaltmalarını al
        hocalar_kisaltmalar = [
            combo.currentData() for combo, _ in self.hocalarComboBoxlar
        ]

        # Kısaltmaların benzersiz olup olmadığını kontrol et
        if len(hocalar_kisaltmalar) != len(set(hocalar_kisaltmalar)):
            QMessageBox.warning(
                self, "Hata", "Aynı hocayı birden fazla kez seçemezsiniz!"
            )
            return
        # Seçili hocaların kısaltmalarını al
        hocalar = [
            {KISALTMA: combo.currentData(), AD: combo.currentText().split(" (")[0]}
            for combo, _ in self.hocalarComboBoxlar
        ]

        # Ders adı boş olamaz kontrolü
        if not ad:
            QMessageBox.warning(self, "Hata", "Ders adı boş olamaz!")
            return

        # Mevcut dersleri kontrol et (yeni ders ekleniyorsa)
        if not self.ders and any(
            d[AD].lower() == ad.lower() for d in self.data[DERSLER]
        ):
            QMessageBox.warning(self, "Hata", "Bu isimde bir ders zaten var!")
            return

        # Dersi bulma ve güncelleme
        if self.ders:  # Düzenleme modunda
            # Mevcut dersin referansını bulun
            mevcut_ders = next((d for d in self.data[DERSLER] if d == self.ders), None)
            if mevcut_ders:
                # Yalnızca belirli alanları güncelleyin
                mevcut_ders[AD] = ad
                mevcut_ders[YIL] = yil
                mevcut_ders[DONEM] = donem if donem != YOK else ""
                mevcut_ders[TIP] = tip
                mevcut_ders[DERSI_VEREN_HOCALAR] = hocalar
                mevcut_ders[GUNCEL_MI] = guncel_mi
        else:  # Ekleme modunda
            # Ders bilgilerini güncelle veya yeni ders ekle
            ders_data = {
                AD: ad,
                YIL: yil,
                DONEM: donem,
                TIP: tip,
                DERSI_VEREN_HOCALAR: hocalar,
                GUNCEL_MI: guncel_mi,
            }
            self.data[DERSLER].append(ders_data)

        self.hocaDersleriniGuncelle(ad, hocalar)
        # Değişiklikleri kaydet
        self.kaydetVeKapat()

    def sil(self):
        if not self.ders:
            QMessageBox.warning(self, "Hata", "Silinecek ders bulunamadı!")
            return

        emin_mi = QMessageBox.question(
            self,
            "Onay",
            f"{self.ders[AD]} dersini silmek istediğinden emin misin?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if emin_mi == QMessageBox.StandardButton.Yes:
            self.data[DERSLER].remove(self.ders)
            self.kaydetVeKapat()

    def hocaDersleriniGuncelle(self, ders_adi, veren_hocalar):
        # JSON dosyasını aç ve verileri yükle
        json_dosyasi = Path(HOCALAR_JSON_PATH)
        if not json_dosyasi.exists():
            print("Hoca JSON dosyası bulunamadı.")
            return

        with open(json_dosyasi, "r", encoding="utf-8") as file:
            data = json.load(file)
        hoca_adlari = [hoca[AD] for hoca in veren_hocalar]
        # Hocalar listesinde dolaş
        for hoca in data.get(HOCALAR, []):
            hoca_adi = hoca.get(AD)
            mevcut_dersler = hoca.get(DERSLER, [])

            if hoca_adi in hoca_adlari:
                # Eğer hoca bu dersi zaten veriyorsa, devam et
                if ders_adi not in mevcut_dersler:
                    mevcut_dersler.append(ders_adi)
            else:
                # Eğer hoca bu dersi vermiyorsa ve ders listesinde varsa, çıkar
                if ders_adi in mevcut_dersler:
                    mevcut_dersler.remove(ders_adi)

            # Güncellenmiş ders listesini hoca profiline ekle
            hoca[DERSLER] = mevcut_dersler

        # Değişiklikleri JSON dosyasına yaz
        with open(json_dosyasi, "w", encoding="utf-8") as file:
            json.dump(data, file, ensure_ascii=False, indent=4)

    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            with open(DERSLER_JSON_PATH, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, "Başarılı", "Değişiklikler kaydedildi!")
            self.parent.dersleriYenile()
            self.is_programmatic_close = True
            self.close()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")
