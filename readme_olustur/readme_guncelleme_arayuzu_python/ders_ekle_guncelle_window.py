import json
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QDialog,QInputDialog, QVBoxLayout, QPushButton, QMessageBox, QLineEdit, QLabel, QTextEdit, QComboBox, QScrollArea, QWidget, QHBoxLayout)
import locale
from pathlib import Path
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
from degiskenler import *
from metin_islemleri import kisaltMetin
# Hoca adlarını ve kısaltmalarını hazırla
unvanlar = {PROF_DR: 1, DOC_DR: 2, DR: 3}
def hoca_sirala(hoca):
    ad = hoca[0].strip()
    unvan = next((u for u in unvanlar if ad.startswith(u)), None)
    return (unvanlar.get(unvan, 4), ad)
class DersEkleGuncelleWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Ders Ekle/Güncelle')
        self.setMinimumSize(700, 200)  # Pencerenin en küçük olabileceği boyutu ayarlayın
        self.mainLayout = QVBoxLayout(self)  # Ana layout
        self.clearFiltersButton = QPushButton('Filtreleri Temizle', self)
        self.clearFiltersButton.setStyleSheet(TEMIZLE_BUTONU_STILI)
        self.clearFiltersButton.clicked.connect(lambda: self.clearFilters(is_clicked=True))
        self.clearFiltersButton.hide()  # Başlangıçta temizle butonunu gizle
        self.mainLayout.addWidget(self.clearFiltersButton)
        # Ders ekleme butonu
        self.ekleBtn = QPushButton('Ders Ekle', self)
        self.ekleBtn.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil arka plan
        self.ekleBtn.clicked.connect(self.dersEkle)
        self.mainLayout.addWidget(self.ekleBtn)

        # Ders sayısını gösteren etiket
        self.dersSayisiLabel = QLabel('Toplam 0 ders')
        self.dersSayisiLabel.setFixedHeight(20)
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

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F and event.modifiers() & Qt.ControlModifier:
            text, ok = QInputDialog.getText(self, 'Arama', 'Aranacak ders:')
            if ok:
                self.searchDersler(text)
    def searchDersler(self, query):
        size = 0
        for idx, ders in enumerate(self.sorted_dersler):
            layout = self.derslerLayout.itemAt(idx)
            if isinstance(layout, QHBoxLayout):
                match = query.lower() in ders[AD].lower()
                for i in range(layout.count()):
                    widget = layout.itemAt(i).widget()
                    if widget:
                        widget.setVisible(match)
                if match:
                    size += 1
        self.dersSayisiLabel.setText(f'{size} ders bulundu')
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()
    def clearFilters(self, is_clicked=True):
        if is_clicked:
            reply = QMessageBox.question(self, 'Filtreleri Temizle', 
                                        'Filtreleri temizlemek istediğinize emin misiniz?', 
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if not is_clicked or reply == QMessageBox.Yes:
            for i in range(self.derslerLayout.count()):
                layout = self.derslerLayout.itemAt(i)
                if isinstance(layout, QHBoxLayout):
                    for j in range(layout.count()):
                        widget = layout.itemAt(j).widget()
                        if widget:
                            widget.show()
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.dersSayisiLabel.setText(f'Toplam {len(self.data[DERSLER])} ders')  # Ders sayısını etikette güncelle
    def jsonDosyasiniYukle(self):
        try:
            with open(DERSLER_JSON_PATH, 'r', encoding='utf-8') as file:
                return json.load(file)
        except:
            return {}
    def dersleriYukle(self):
        try:
            # Öncelikle Türkçe locale'i dene
            locale.setlocale(locale.LC_ALL, 'tr_TR.UTF-8')
        except locale.Error:
            try:
                # eğer sistemde tr dili yoksa linuxta böyle yüklenebilir
                #os.system('sudo locale-gen tr_TR.UTF-8')
                # Alternatif olarak başka bir Türkçe locale dene
                locale.setlocale(locale.LC_ALL, 'tr_TR')
            except locale.Error:
                # Varsayılan locale'e geri dön
                locale.setlocale(locale.LC_ALL, '')
        try:
            self.data = self.jsonDosyasiniYukle()
            if DERSLER not in self.data:
                self.data[DERSLER] = []
            if BOLUM_ADI not in self.data:
                self.data[BOLUM_ADI] = VARSAYILAN_DERS_BOLUM_ADI
            if BOLUM_ACIKLAMASI not in self.data:
                self.data[BOLUM_ACIKLAMASI] = VARSAYILAN_DERS_BOLUM_ACIKLAMASI
            if DERS_KLASORU_BULUNAMADI_MESAJI not in self.data:
                self.data[DERS_KLASORU_BULUNAMADI_MESAJI] = VARSAYILAN_DERS_KLASORU_BULUNAMADI_MESAJI
            if GUNCEL_OLMAYAN_DERS_ACIKLAMASI not in self.data:
                self.data[GUNCEL_OLMAYAN_DERS_ACIKLAMASI] = VARSAYILAN_GUNCEL_OLMAYAN_DERS_ACIKLAMASI
                

            ders_sayisi = len(self.data[DERSLER])  # Ders sayısını hesapla
            self.dersSayisiLabel.setText(f'Toplam {ders_sayisi} ders')  # Ders sayısını etikette güncelle

            # Dersleri ders adına göre Türkçe alfabetik olarak sırala (büyük/küçük harf duyarsız)
            self.sorted_dersler = sorted(self.data[DERSLER], key=lambda d: locale.strxfrm(d[AD].lower()))
            for ders in self.sorted_dersler:
                # Her ders için bir satır oluştur
                dersSatiri = QHBoxLayout()

                # Büyük ders butonu
                btnDers = QPushButton(f"{ders[AD]}", self.scrollWidget)
                btnDers.clicked.connect(lambda checked, a=ders: self.dersDuzenle(a))
                btnDers.setStyleSheet(GUNCELLE_BUTTON_STILI)
                btnDers.setMinimumWidth(350)
                dersSatiri.addWidget(btnDers)

                # Kaynak Ekle butonu
                btnKaynakEkle = QPushButton("Kaynak Ekle/Güncelle", self.scrollWidget)
                btnKaynakEkle.clicked.connect(lambda checked, a=ders: self.kaynakEkle(a))
                btnKaynakEkle.setStyleSheet(EKLE_BUTONU_STILI)  # Yeşil renk, küçültülmüş genişlik
                dersSatiri.addWidget(btnKaynakEkle)

                # Öneri Ekle butonu
                btnOneriEkle = QPushButton("Öneri Ekle/Güncelle", self.scrollWidget)
                btnOneriEkle.clicked.connect(lambda checked, a=ders: self.oneriEkle(a))
                btnOneriEkle.setStyleSheet(SIL_BUTONU_STILI)  # Kırmızı renk, küçültülmüş genişlik
                dersSatiri.addWidget(btnOneriEkle)

                # Ders satırını dersler layout'una ekle
                self.derslerLayout.addLayout(dersSatiri)


        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
    
    def oneriEkle(self, ders):
        # Öneri ekleme için KaynakVeOneriDuzenleyici sınıfını kullanarak bir pencere aç
        self.oneriDuzenleyiciPenceresi = KaynakVeOneriDuzenleyici(ders, DERSE_DAIR_ONERILER, self)
        self.oneriDuzenleyiciPenceresi.show()
    def kaynakEkle(self, ders):
        # Kaynak ekleme için KaynakVeOneriDuzenleyici sınıfını kullanarak bir pencere aç
        self.kaynakDuzenleyiciPenceresi = KaynakVeOneriDuzenleyici(ders, FAYDALI_OLABILECEK_KAYNAKLAR, self)
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
        super().__init__()
        self.ders = ders
        self.setModal(True)
        self.parent = parent
        self.tur = tur  # 'faydali_olabilecek_kaynaklar' veya 'derse_dair_oneriler'
        self.initUI()

    def initUI(self):
        if self.tur == FAYDALI_OLABILECEK_KAYNAKLAR:
            self.setWindowTitle(f"{self.ders[AD]} - Kaynaklar")
        else:
            self.setWindowTitle(f"{self.ders[AD]} - {self.tur.replace('_', ' ').title()}")

        self.layout = QVBoxLayout(self)

        # Ekle butonu
        self.ekleBtn = QPushButton('Ekle', self)
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
                            label = QLabel(f"Öneri Sahibi: {eleman[ONERI_SAHIBI]}", self)
                            satirLayout.addWidget(label)

                            # Bilgi (mesaj) butonu
                            infoBtn = QPushButton(kisaltMetin(oneri), self)
                            infoBtn.setToolTip(oneri)
                            infoBtn.clicked.connect(lambda checked, a=eleman, j=j, i=i: self.elemanDuzenle(a, j, oneri_index=i))
                            satirLayout.addWidget(infoBtn)
                            # Silme butonu
                            deleteBtn = QPushButton("Sil", self)
                            deleteBtn.setStyleSheet(SIL_BUTONU_STILI)  # Silme butonunu kırmızı yap
                            deleteBtn.clicked.connect(lambda checked, a=eleman, j=j, i=i: self.elemanSil(a, oneri_index=i, sahip_index=j))
                            satirLayout.addWidget(deleteBtn)
                            # Satır düzenini ana düzene ekle
                            self.layout.addLayout(satirLayout)

                else:
                    satirLayout = QHBoxLayout()
                    # Bilgi (mesaj) butonu
                    infoBtn = QPushButton(kisaltMetin(eleman), self)
                    infoBtn.setToolTip(eleman)
                    infoBtn.clicked.connect(lambda checked, a=eleman, j=j: self.elemanDuzenle(a, oneri_index=j))
                    satirLayout.addWidget(infoBtn)

                    # Silme butonu
                    deleteBtn = QPushButton("Sil", self)
                    deleteBtn.setStyleSheet(SIL_BUTONU_STILI)  # Silme butonunu kırmızı yap
                    deleteBtn.clicked.connect(lambda checked, a=eleman, j=j: self.elemanSil(a, oneri_index=j))
                    satirLayout.addWidget(deleteBtn)
                    # Satır düzenini ana düzene ekle
                    self.layout.addLayout(satirLayout)

    def elemanSil(self, eleman, sahip_index=None, oneri_index=None):
        # Kullanıcıya silme işlemi için onay sor
        emin_mi = QMessageBox.question(self, 'Onay', 'Bu öğeyi silmek istediğinize emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

        if emin_mi == QMessageBox.Yes:
            # JSON dosyasını aç ve güncelle
            with open(DERSLER_JSON_PATH, 'r+', encoding='utf-8') as file:
                data = json.load(file)

                # İlgili dersi data içinden bul
                ders = next((d for d in data[DERSLER] if d[AD] == self.ders[AD]), None)
                if ders and self.tur in ders:
                    if self.tur == DERSE_DAIR_ONERILER and sahip_index is not None and oneri_index is not None:
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
        if self.parent and hasattr(self.parent, 'dersleriYenile'):
            self.parent.dersleriYenile()

            # Ebeveynin veri setinde güncellenmiş ders bilgisini bul
            guncellenmisDers = next((ders for ders in self.parent.data[DERSLER] if ders[AD] == self.ders[AD]), None)
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
            if widget is not None and widget != self.ekleBtn:  # Ekleme butonu değilse kaldır
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
        self.eklemeDialogu = YeniElemanEklemeDialog(self.tur, parent=self, ders=self.ders)
        self.eklemeDialogu.show()

    def elemanDuzenle(self, eleman, sahip_index=None, oneri_index=None):
        # Mevcut elemanı düzenleme dialogunu aç
        self.duzenlemeDialogu = YeniElemanEklemeDialog(self.tur, sahip_index, oneri_index, eleman, parent=self, ders=self.ders)
        self.duzenlemeDialogu.show()
class YeniElemanEklemeDialog(QDialog):
    def __init__(self, tur,sahip_index=None , oneri_index=None, mevcutEleman=None, parent=None, ders=None):
        super().__init__()
        self.tur = tur
        self.setModal(True)
        self.parent = parent
        self.sahip_index = sahip_index  # Güncellenecek önerinin indeksi
        self.oneri_index = oneri_index  # Güncellenecek önerinin indeksi
        self.mevcutEleman = mevcutEleman  # Güncellenecek mevcut eleman
        self.ders = ders
        self.initUI()

    def initUI(self):
        self.layout = QVBoxLayout(self)
        self.setMinimumSize(400, 200)  # Pencerenin en küçük olabileceği boyutu ayarlayın
        # Öneri sahibi ve öneri için etiket ve metin alanı
        if self.tur == DERSE_DAIR_ONERILER:
            self.label = QLabel('Öneri Sahibi:', self)
            self.layout.addWidget(self.label)
            self.sahibiEdit = QLineEdit(self)
            if self.mevcutEleman:
                self.sahibiEdit.setText(self.mevcutEleman[ONERI_SAHIBI])
            self.layout.addWidget(self.sahibiEdit)
            self.label = QLabel('Öneri:', self)
        else:
            self.label = QLabel('Kaynak:', self)


        self.layout.addWidget(self.label)
        self.metinEdit = QTextEdit(self)
        if self.mevcutEleman and self.tur == DERSE_DAIR_ONERILER:
            self.metinEdit.setText(self.mevcutEleman[ONERILER][self.oneri_index])
        else:
            self.metinEdit.setText(self.mevcutEleman)
        self.layout.addWidget(self.metinEdit)

        # Kaydet butonu
        self.kaydetBtn = QPushButton('Kaydet', self)
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.layout.addWidget(self.kaydetBtn)

    def kaydet(self):
        oneriSahibi = self.sahibiEdit.text() if self.tur == DERSE_DAIR_ONERILER else None
        metin = self.metinEdit.toPlainText()
        if (not oneriSahibi and self.tur == DERSE_DAIR_ONERILER) or not metin:
            QMessageBox.warning(self, 'Hata', 'Öneri sahibi ve öneri boş olamaz!')
            return
        emin_mi = QMessageBox.question(self, 'Onay', f'Değişiklikleri Kaydetmek İstediğine Emin Misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi != QMessageBox.Yes:
            return
        # JSON dosyasını aç ve güncelle
        with open(DERSLER_JSON_PATH, 'r+', encoding='utf-8') as file:
            data = json.load(file)

            ders = next((ders for ders in data[DERSLER] if ders[AD] == self.ders[AD]), None)
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
                    mevcutSahibi = self.ders[DERSE_DAIR_ONERILER][self.sahip_index][ONERI_SAHIBI] if self.sahip_index is not None else None

                    if mevcutSahibi != oneriSahibi:
                        # Öneri sahibi değişti, eski öneriyi sil
                        if self.sahip_index is not None and self.oneri_index is not None:
                            del ders[DERSE_DAIR_ONERILER][self.sahip_index][ONERILER][self.oneri_index]
                            if len(ders[DERSE_DAIR_ONERILER][self.sahip_index][ONERILER]) < 1:
                                del ders[DERSE_DAIR_ONERILER][self.sahip_index]
                        # Yeni sahip için öneriyi ekle veya mevcut sahibi bul
                        if "derse_dair_oneriler" in ders:
                            matched = next((o for o in ders[DERSE_DAIR_ONERILER] if o[ONERI_SAHIBI] == oneriSahibi), None)
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
        QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
        self.parent.arayuzuGuncelle()
        self.close()

class DersDuzenlemeWindow(QDialog):
    def __init__(self, ders,data, parent):
        super().__init__(parent)
        self.ders = ders
        self.data = data
        self.parent = parent
        self.setModal(True)
        self.hocalarComboBoxlar = []  # Hoca seçimi için ComboBox'lar listesi
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Ders Düzenle/Ekle')

        self.layout = QVBoxLayout(self)
        self.setMinimumSize(400, 200)  # Pencerenin en küçük olabileceği boyutu ayarlayın
        # Ders adı için alan
        self.layout.addWidget(QLabel('Ders Adı:'))
        self.adInput = QLineEdit(self.ders[AD] if self.ders else '')
        self.layout.addWidget(self.adInput)

        # Ders yılı için alan
        self.layout.addWidget(QLabel('Yıl:'))
        self.yilInput = QComboBox(self)
        self.yilInput.addItems(['0','1', '2', '3', '4'])
        if self.ders:
            self.yilInput.setCurrentIndex(self.ders['yil'])
        self.layout.addWidget(self.yilInput)

        # Ders dönemi için alan
        self.layout.addWidget(QLabel('Dönem:'))
        self.donemInput = QComboBox(self)
        self.donemInput.addItems(['Yok','Güz', 'Bahar'])
        if self.ders:
            self.donemInput.setCurrentText(self.ders['donem'])
        self.layout.addWidget(self.donemInput)
        self.layout.addWidget(QLabel('Ders Güncel Mi:'))
        self.guncelMi = QComboBox(self)
        self.guncelMi.addItems(['False','True'])
        if self.ders:
            self.guncelMi.setCurrentText('True' if 'guncel_mi' in self.ders and self.ders['guncel_mi'] else 'False')
        self.layout.addWidget(self.guncelMi)

        # Ders tipi için alan
        self.layout.addWidget(QLabel('Tip:'))
        self.tipInput = QComboBox(self)
        self.tipInput.addItems(['Zorunlu', 'Seçmeli', 'Seçmeli 4', 'Mesleki Seçmeli'])
        if self.ders:
            self.tipInput.setCurrentText(self.ders['tip'])
        self.layout.addWidget(self.tipInput)
        self.layout.addWidget(QLabel('Dersi Veren Hocalar'))
        # Dersi veren hocalar için ComboBox'lar
        # Mevcut hocaları yükle
        try:
            with open(HOCALAR_JSON_PATH, 'r',encoding='utf-8') as file:
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
        self.hocaScrollArea.setWidget(self.hocaScrollWidget)  # ScrollArea'ya widget ekle
        self.layout.addWidget(self.hocaScrollArea)  # Ana layout'a ScrollArea ekle
        if self.ders and DERSI_VEREN_HOCALAR in self.ders:
            for hoca in self.ders[DERSI_VEREN_HOCALAR]:
                self.ekleHocaComboBox(hoca)
        # Ekle (+) butonu
        self.ekleHocaBtn = QPushButton('Dersi Veren Hoca Ekle', self)
        self.ekleHocaBtn.setStyleSheet(VEREN_EKLE_BUTONU_STILI)
        self.ekleHocaBtn.clicked.connect(self.ekleHocaComboBox)
        self.layout.addWidget(self.ekleHocaBtn)

        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        buttonsLayout = QHBoxLayout()
        if self.ders:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        
        self.kaydetBtn.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydetBtn)

        if self.ders:
            self.silBtn = QPushButton('Dersi Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet(SIL_BUTONU_STILI)
            buttonsLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonsLayout)

    def ekleHocaComboBox(self, hoca=None):
        if len(self.hoca_listesi) < 1:
            QMessageBox.warning(self, 'Hata', 'Hoca listesi boş!')
            return

        # Yeni ComboBox oluştur
        comboBox = QComboBox(self)
        for ad, kisaltma in self.hoca_listesi:
            comboBox.addItem(f"{ad} ({kisaltma})", kisaltma)  # Ad ve kısaltmayı ekle

        # Eğer kısaltma verildiyse, onu ComboBox'da seç
        if hoca:
            comboBox.setCurrentText(f"{hoca[AD]} ({hoca['kisaltma']})")

        # Sil (-) butonu
        silBtn = QPushButton('Dersi Veren Hocayı Sil', self)
        silBtn.setStyleSheet(SIL_BUTONU_STILI)
        silBtn.clicked.connect(lambda: self.silHocaComboBox(comboBox, silBtn))

        hocaLayout = QHBoxLayout()
        hocaLayout.addWidget(comboBox)
        hocaLayout.addWidget(silBtn)
        self.hocalarLayout.addLayout(hocaLayout)  # Hoca layout'una ekle, bu self.hocaScrollWidget'a bağlı


        # ComboBox listesini güncelle
        self.hocalarComboBoxlar.append((comboBox, silBtn))

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
        # Seçili hocaların kısaltmalarını al
        hocalar_kisaltmalar = [combo.currentData() for combo, _ in self.hocalarComboBoxlar]
        
        # Kısaltmaların benzersiz olup olmadığını kontrol et
        if len(hocalar_kisaltmalar) != len(set(hocalar_kisaltmalar)):
            QMessageBox.warning(self, 'Hata', 'Aynı hocayı birden fazla kez seçemezsiniz!')
            return
        # Seçili hocaların kısaltmalarını al
        hocalar = [{'kisaltma': combo.currentData(), AD: combo.currentText().split(' (')[0]}
                   for combo, _ in self.hocalarComboBoxlar]
    
        # Ders adı boş olamaz kontrolü
        if not ad:
            QMessageBox.warning(self, 'Hata', 'Ders adı boş olamaz!')
            return

        # Mevcut dersleri kontrol et (yeni ders ekleniyorsa)
        if not self.ders and any(d[AD].lower() == ad.lower() for d in self.data[DERSLER]):
            QMessageBox.warning(self, 'Hata', 'Bu isimde bir ders zaten var!')
            return

        # Dersi bulma ve güncelleme
        if self.ders:  # Düzenleme modunda
            # Mevcut dersin referansını bulun
            mevcut_ders = next((d for d in self.data[DERSLER] if d == self.ders), None)
            if mevcut_ders:
                # Yalnızca belirli alanları güncelleyin
                mevcut_ders[AD] = ad
                mevcut_ders[YIL] = yil
                mevcut_ders[DONEM] = donem if donem != YOK else ''
                mevcut_ders[TIP] = tip
                mevcut_ders[DERSI_VEREN_HOCALAR] = hocalar
                mevcut_ders[GUNCEL_MI] = guncel_mi
        else:  # Ekleme modunda
            # Ders bilgilerini güncelle veya yeni ders ekle
            ders_data = {AD: ad, YIL: yil, DONEM: donem, TIP: tip, DERSI_VEREN_HOCALAR: hocalar, GUNCEL_MI: guncel_mi}
            self.data[DERSLER].append(ders_data)
    

        self.hocaDersleriniGuncelle(ad, hocalar)
        # Değişiklikleri kaydet
        self.kaydetVeKapat()

    def sil(self):
        if not self.ders:
            QMessageBox.warning(self, 'Hata', 'Silinecek ders bulunamadı!')
            return

        emin_mi = QMessageBox.question(self, 'Onay', f'{self.ders[AD]} dersini silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            self.data[DERSLER].remove(self.ders)
            self.kaydetVeKapat()
    def hocaDersleriniGuncelle(self, ders_adi, veren_hocalar):
        # JSON dosyasını aç ve verileri yükle
        json_dosyasi = Path(HOCALAR_JSON_PATH)
        if not json_dosyasi.exists():
            print("Hoca JSON dosyası bulunamadı.")
            return

        with open(json_dosyasi, 'r', encoding='utf-8') as file:
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
        with open(json_dosyasi, 'w', encoding='utf-8') as file:
            json.dump(data, file, ensure_ascii=False, indent=4)
    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            with open(DERSLER_JSON_PATH, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.dersleriYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
