import json
from PyQt5.QtWidgets import (QDialog, QVBoxLayout, QPushButton, QMessageBox, QLineEdit, QLabel, QTextEdit, QComboBox, QScrollArea, QWidget, QHBoxLayout)
import locale
from pathlib import Path
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
JSON_PATH = '../dersler.json'
HOCA_JSON_PATH = '../hocalar.json'

# Hoca adlarını ve kısaltmalarını hazırla
unvanlar = {'Prof. Dr.': 1, 'Doç. Dr.': 2, 'Dr.': 3}
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

        self.mainLayout = QVBoxLayout(self)  # Ana layout

        # Ders ekleme butonu
        self.ekleBtn = QPushButton('Ders Ekle', self)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Yeşil arka plan
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

            with open(JSON_PATH, 'r', encoding='utf-8') as file:
                self.data = json.load(file)
                ders_sayisi = len(self.data['dersler'])  # Ders sayısını hesapla
                self.dersSayisiLabel.setText(f'Toplam {ders_sayisi} ders')  # Ders sayısını etikette güncelle

                # Dersleri ders adına göre Türkçe alfabetik olarak sırala (büyük/küçük harf duyarsız)
                sorted_dersler = sorted(self.data['dersler'], key=lambda d: locale.strxfrm(d['ad'].lower()))
                for ders in sorted_dersler:
                    # Her ders için bir satır oluştur
                    dersSatiri = QHBoxLayout()

                    # Büyük ders butonu
                    btnDers = QPushButton(f"{ders['ad']}", self.scrollWidget)
                    btnDers.clicked.connect(lambda checked, a=ders: self.dersDuzenle(a))
                    btnDers.setStyleSheet("QPushButton {background-color: blue; color: white;}")
                    btnDers.setMinimumWidth(350)
                    dersSatiri.addWidget(btnDers)

                    # Kaynak Ekle butonu
                    btnKaynakEkle = QPushButton("Kaynak Ekle/Güncelle", self.scrollWidget)
                    btnKaynakEkle.clicked.connect(lambda checked, a=ders: self.kaynakEkle(a))
                    btnKaynakEkle.setStyleSheet("background-color: green;")  # Yeşil renk, küçültülmüş genişlik
                    dersSatiri.addWidget(btnKaynakEkle)

                    # Öneri Ekle butonu
                    btnOneriEkle = QPushButton("Öneri Ekle/Güncelle", self.scrollWidget)
                    btnOneriEkle.clicked.connect(lambda checked, a=ders: self.oneriEkle(a))
                    btnOneriEkle.setStyleSheet("background-color: red;")  # Kırmızı renk, küçültülmüş genişlik
                    dersSatiri.addWidget(btnOneriEkle)

                    # Ders satırını dersler layout'una ekle
                    self.derslerLayout.addLayout(dersSatiri)


        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya okunurken bir hata oluştu: {e}')
    def oneriEkle(self, ders):
        # Öneri ekleme için KaynakVeOneriDuzenleyici sınıfını kullanarak bir pencere aç
        self.oneriDuzenleyiciPenceresi = KaynakVeOneriDuzenleyici(ders, 'derse_dair_oneriler', self)
        self.oneriDuzenleyiciPenceresi.show()
    def kaynakEkle(self, ders):
        # Kaynak ekleme için KaynakVeOneriDuzenleyici sınıfını kullanarak bir pencere aç
        self.kaynakDuzenleyiciPenceresi = KaynakVeOneriDuzenleyici(ders, 'faydali_olabilecek_kaynaklar', self)
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
        if self.tur == 'faydali_olabilecek_kaynaklar':
            self.setWindowTitle(f"{self.ders['ad']} - Kaynaklar")
        else:
            self.setWindowTitle(f"{self.ders['ad']} - {self.tur.replace('_', ' ').title()}")

        self.layout = QVBoxLayout(self)

        # Ekle butonu
        self.ekleBtn = QPushButton('Ekle', self)
        self.ekleBtn.setStyleSheet("background-color: green;")  # Ekle butonunu yeşil yap
        self.ekleBtn.clicked.connect(self.yeniElemanEkle)
        self.layout.addWidget(self.ekleBtn)
        self.resize(600, 100)

        # Mevcut kaynaklar/öneriler için butonları oluştur
        self.elemanlariYukle()
 

    def elemanlariYukle(self):
        if self.tur in self.ders:
            for j, eleman in enumerate(self.ders[self.tur]):
                if self.tur == 'derse_dair_oneriler':
                    if 'oneriler' in eleman:
                        for i, oneri in enumerate(eleman['oneriler']):
                            satirLayout = QHBoxLayout()
                            label = QLabel(f"Öneri Sahibi: {eleman['oneri_sahibi']}", self)
                            satirLayout.addWidget(label)

                            # Bilgi (mesaj) butonu
                            infoBtn = QPushButton(oneri, self)
                            infoBtn.clicked.connect(lambda checked, a=eleman, j=j, i=i: self.elemanDuzenle(a, j, oneri_index=i))
                            satirLayout.addWidget(infoBtn)
                            # Silme butonu
                            deleteBtn = QPushButton("Sil", self)
                            deleteBtn.setStyleSheet("background-color: red; color: white;")  # Silme butonunu kırmızı yap
                            deleteBtn.clicked.connect(lambda checked, a=eleman, j=j, i=i: self.elemanSil(a, oneri_index=i, sahip_index=j))
                            satirLayout.addWidget(deleteBtn)
                            # Satır düzenini ana düzene ekle
                            self.layout.addLayout(satirLayout)

                else:
                    satirLayout = QHBoxLayout()
                    # Bilgi (mesaj) butonu
                    infoBtn = QPushButton(eleman, self)
                    infoBtn.clicked.connect(lambda checked, a=eleman, j=j: self.elemanDuzenle(a, oneri_index=j))
                    satirLayout.addWidget(infoBtn)

                    # Silme butonu
                    deleteBtn = QPushButton("Sil", self)
                    deleteBtn.setStyleSheet("background-color: red; color: white;")  # Silme butonunu kırmızı yap
                    deleteBtn.clicked.connect(lambda checked, a=eleman, j=j: self.elemanSil(a, oneri_index=j))
                    satirLayout.addWidget(deleteBtn)
                    # Satır düzenini ana düzene ekle
                    self.layout.addLayout(satirLayout)

    def elemanSil(self, eleman, sahip_index=None, oneri_index=None):
        # Kullanıcıya silme işlemi için onay sor
        emin_mi = QMessageBox.question(self, 'Onay', 'Bu öğeyi silmek istediğinize emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

        if emin_mi == QMessageBox.Yes:
            # JSON dosyasını aç ve güncelle
            with open(JSON_PATH, 'r+', encoding='utf-8') as file:
                data = json.load(file)

                # İlgili dersi data içinden bul
                ders = next((d for d in data['dersler'] if d['ad'] == self.ders['ad']), None)
                if ders and self.tur in ders:
                    if self.tur == 'derse_dair_oneriler' and sahip_index is not None and oneri_index is not None:
                        # İlgili öneriyi sil
                        del ders[self.tur][sahip_index]['oneriler'][oneri_index]
                        if len(ders[self.tur][sahip_index]['oneriler']) < 1:
                            # Öneri sahibinin önerisi kalmadı, öneri sahibini de sil
                            del ders[self.tur][sahip_index]
                            if len(ders[self.tur]) < 1:
                                # Öneri kalmadı, alanı sil
                                del ders[self.tur]
                    elif self.tur != 'derse_dair_oneriler' and oneri_index is not None:
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
            guncellenmisDers = next((ders for ders in self.parent.data['dersler'] if ders['ad'] == self.ders['ad']), None)
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

        # Öneri sahibi ve öneri için etiket ve metin alanı
        if self.tur == 'derse_dair_oneriler':
            self.label = QLabel('Öneri Sahibi:', self)
            self.layout.addWidget(self.label)
            self.sahibiEdit = QLineEdit(self)
            if self.mevcutEleman:
                self.sahibiEdit.setText(self.mevcutEleman['oneri_sahibi'])
            self.layout.addWidget(self.sahibiEdit)
            self.label = QLabel('Öneri:', self)
        else:
            self.label = QLabel('Kaynak:', self)


        self.layout.addWidget(self.label)
        self.metinEdit = QTextEdit(self)
        if self.mevcutEleman and self.tur == 'derse_dair_oneriler':
            self.metinEdit.setText(self.mevcutEleman['oneriler'][self.oneri_index])
        else:
            self.metinEdit.setText(self.mevcutEleman)
        self.layout.addWidget(self.metinEdit)

        # Kaydet butonu
        self.kaydetBtn = QPushButton('Kaydet', self)
        self.kaydetBtn.clicked.connect(self.kaydet)
        self.layout.addWidget(self.kaydetBtn)

    def kaydet(self):
        oneriSahibi = self.sahibiEdit.text() if self.tur == 'derse_dair_oneriler' else None
        metin = self.metinEdit.toPlainText()
        if (not oneriSahibi and self.tur == 'derse_dair_oneriler') or not metin:
            QMessageBox.warning(self, 'Hata', 'Öneri sahibi ve öneri boş olamaz!')
            return
        emin_mi = QMessageBox.question(self, 'Onay', f'Değişiklikleri Kaydetmek İstediğine Emin Misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi != QMessageBox.Yes:
            return
        # JSON dosyasını aç ve güncelle
        with open(JSON_PATH, 'r+', encoding='utf-8') as file:
            data = json.load(file)

            ders = next((ders for ders in data['dersler'] if ders['ad'] == self.ders['ad']), None)
            if not ders:
                print("Belirtilen adla ders bulunamadı!")
                return  # Ders bulunamazsa
            if self.tur != 'derse_dair_oneriler':
                # Faydalı olabilecek kaynaklar için işlemler
                if self.oneri_index is None:
                    # Yeni kaynak ekle
                    if "faydali_olabilecek_kaynaklar" in ders:
                        ders['faydali_olabilecek_kaynaklar'].append(metin)
                    else:
                        ders['faydali_olabilecek_kaynaklar'] = [metin]
                else:
                    # Mevcut kaynağı güncelle
                    ders['faydali_olabilecek_kaynaklar'][self.oneri_index] = metin
            else:
                # Derse dair öneriler için işlemler
                if oneriSahibi:
                    # Mevcut öneri sahibi değerini al
                    mevcutSahibi = self.ders['derse_dair_oneriler'][self.sahip_index]['oneri_sahibi'] if self.sahip_index is not None else None

                    if mevcutSahibi != oneriSahibi:
                        # Öneri sahibi değişti, eski öneriyi sil
                        if self.sahip_index is not None and self.oneri_index is not None:
                            del ders['derse_dair_oneriler'][self.sahip_index]['oneriler'][self.oneri_index]
                            if len(ders['derse_dair_oneriler'][self.sahip_index]['oneriler']) < 1:
                                del ders['derse_dair_oneriler'][self.sahip_index]
                        # Yeni sahip için öneriyi ekle veya mevcut sahibi bul
                        if "derse_dair_oneriler" in ders:
                            matched = next((o for o in ders['derse_dair_oneriler'] if o['oneri_sahibi'] == oneriSahibi), None)
                        else:
                            ders['derse_dair_oneriler'] = []
                            matched = None
                        if not matched:
                            # Yeni sahibi ve öneriyi ekle
                            matched = {'oneri_sahibi': oneriSahibi, 'oneriler': []}
                            ders['derse_dair_oneriler'].append(matched)
                    else:
                        # Öneri sahibi aynı, mevcut sahibi kullan
                        matched = ders['derse_dair_oneriler'][self.sahip_index]

                    # Öneri ekle veya güncelle
                    if self.oneri_index is None or mevcutSahibi != oneriSahibi:
                        # Yeni öneri ekle
                        matched['oneriler'].append(metin)
                    else:
                        # Mevcut öneriyi güncelle
                        matched['oneriler'][self.oneri_index] = metin
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

        # Ders adı için alan
        self.layout.addWidget(QLabel('Ders Adı:'))
        self.adInput = QLineEdit(self.ders['ad'] if self.ders else '')
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

        # Ders tipi için alan
        self.layout.addWidget(QLabel('Tip:'))
        self.tipInput = QComboBox(self)
        self.tipInput.addItems(['Zorunlu', 'Seçmeli', 'Seçmeli4', 'Mesleki Seçmeli'])
        if self.ders:
            self.tipInput.setCurrentText(self.ders['tip'])
        self.layout.addWidget(self.tipInput)
        self.layout.addWidget(QLabel('Dersi Veren Hocalar'))
        # Dersi veren hocalar için ComboBox'lar
        # Mevcut hocaları yükle
        with open(HOCA_JSON_PATH, 'r',encoding='utf-8') as file:
            hoca_data = json.load(file)

        hoca_listesi = [
            (h['ad'], hoca_kisaltma_olustur(h['ad']))
            for h in hoca_data['hocalar']
            if h['ad'].strip() and hoca_kisaltma_olustur(h['ad']).strip()
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
        if self.ders and 'dersi_veren_hocalar' in self.ders:
            for hoca in self.ders['dersi_veren_hocalar']:
                self.ekleHocaComboBox(hoca)
        # Ekle (+) butonu
        self.ekleHocaBtn = QPushButton('Dersi Veren Hoca Ekle', self)
        self.ekleHocaBtn.setStyleSheet("background-color: lightblue;")
        self.ekleHocaBtn.clicked.connect(self.ekleHocaComboBox)
        self.layout.addWidget(self.ekleHocaBtn)

        # Kaydet ve Sil butonları (sil butonu sadece düzenleme modunda görünür)
        buttonsLayout = QHBoxLayout()
        if self.ders:
            self.kaydetBtn = QPushButton('Değişiklikleri Kaydet', self)
        else:
            self.kaydetBtn = QPushButton('Ekle', self)
        
        self.kaydetBtn.setStyleSheet("background-color: green;")
        self.kaydetBtn.clicked.connect(self.kaydet)
        buttonsLayout.addWidget(self.kaydetBtn)

        if self.ders:
            self.silBtn = QPushButton('Dersi Sil', self)
            self.silBtn.clicked.connect(self.sil)
            self.silBtn.setStyleSheet("background-color: red;")
            buttonsLayout.addWidget(self.silBtn)

        self.layout.addLayout(buttonsLayout)

    def ekleHocaComboBox(self, hoca=None):
        

        # Yeni ComboBox oluştur
        comboBox = QComboBox(self)
        for ad, kisaltma in self.hoca_listesi:
            comboBox.addItem(f"{ad} ({kisaltma})", kisaltma)  # Ad ve kısaltmayı ekle

        # Eğer kısaltma verildiyse, onu ComboBox'da seç
        if hoca:
            comboBox.setCurrentText(f"{hoca['ad']} ({hoca['kisaltma']})")

        # Sil (-) butonu
        silBtn = QPushButton('Dersi Veren Hocayı Sil', self)
        silBtn.setStyleSheet("background-color: rgb(255, 102, 102);")
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
        tip = self.tipInput.currentText()
        # Seçili hocaların kısaltmalarını al
        hocalar_kisaltmalar = [combo.currentData() for combo, _ in self.hocalarComboBoxlar]
        
        # Kısaltmaların benzersiz olup olmadığını kontrol et
        if len(hocalar_kisaltmalar) != len(set(hocalar_kisaltmalar)):
            QMessageBox.warning(self, 'Hata', 'Aynı hocayı birden fazla kez seçemezsiniz!')
            return
        # Seçili hocaların kısaltmalarını al
        hocalar = [{'kisaltma': combo.currentData(), 'ad': combo.currentText().split(' (')[0]}
                   for combo, _ in self.hocalarComboBoxlar]
    
        # Ders adı boş olamaz kontrolü
        if not ad:
            QMessageBox.warning(self, 'Hata', 'Ders adı boş olamaz!')
            return

        # Mevcut dersleri kontrol et (yeni ders ekleniyorsa)
        if not self.ders and any(d['ad'].lower() == ad.lower() for d in self.data['dersler']):
            QMessageBox.warning(self, 'Hata', 'Bu isimde bir ders zaten var!')
            return

        # Dersi bulma ve güncelleme
        if self.ders:  # Düzenleme modunda
            # Mevcut dersin referansını bulun
            mevcut_ders = next((d for d in self.data['dersler'] if d == self.ders), None)
            if mevcut_ders:
                # Yalnızca belirli alanları güncelleyin
                mevcut_ders["ad"] = ad
                mevcut_ders["yil"] = yil
                mevcut_ders["donem"] = donem if donem != 'Yok' else ''
                mevcut_ders["tip"] = tip
                mevcut_ders["dersi_veren_hocalar"] = hocalar
        else:  # Ekleme modunda
            # Ders bilgilerini güncelle veya yeni ders ekle
            ders_data = {"ad": ad, "yil": yil, "donem": donem, "tip": tip, "dersi_veren_hocalar": hocalar}
            self.data['dersler'].append(ders_data)
    

        self.hocaDersleriniGuncelle(ad, hocalar)
        # Değişiklikleri kaydet
        self.kaydetVeKapat()

    def sil(self):
        if not self.ders:
            QMessageBox.warning(self, 'Hata', 'Silinecek ders bulunamadı!')
            return

        emin_mi = QMessageBox.question(self, 'Onay', f'{self.ders["ad"]} dersini silmek istediğinden emin misin?', QMessageBox.Yes | QMessageBox.No)
        if emin_mi == QMessageBox.Yes:
            self.data['dersler'].remove(self.ders)
            self.kaydetVeKapat()
    def hocaDersleriniGuncelle(self, ders_adi, veren_hocalar):
        # JSON dosyasını aç ve verileri yükle
        json_dosyasi = Path(HOCA_JSON_PATH)
        if not json_dosyasi.exists():
            print("Hoca JSON dosyası bulunamadı.")
            return

        with open(json_dosyasi, 'r', encoding='utf-8') as file:
            data = json.load(file)
        hoca_adlari = [hoca["ad"] for hoca in veren_hocalar]
        # Hocalar listesinde dolaş
        for hoca in data.get("hocalar", []):
            hoca_adi = hoca.get("ad")
            mevcut_dersler = hoca.get("dersler", [])

            if hoca_adi in hoca_adlari:
                # Eğer hoca bu dersi zaten veriyorsa, devam et
                if ders_adi not in mevcut_dersler:
                    mevcut_dersler.append(ders_adi)
            else:
                # Eğer hoca bu dersi vermiyorsa ve ders listesinde varsa, çıkar
                if ders_adi in mevcut_dersler:
                    mevcut_dersler.remove(ders_adi)

            # Güncellenmiş ders listesini hoca profiline ekle
            hoca["dersler"] = mevcut_dersler

        # Değişiklikleri JSON dosyasına yaz
        with open(json_dosyasi, 'w', encoding='utf-8') as file:
            json.dump(data, file, ensure_ascii=False, indent=4)
    def kaydetVeKapat(self):
        # Değişiklikleri JSON dosyasına kaydet ve pencereyi kapat
        try:
            with open(JSON_PATH, 'w',encoding='utf-8') as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, 'Başarılı', 'Değişiklikler kaydedildi!')
            self.parent.dersleriYenile()
            self.close()
        except Exception as e:
            QMessageBox.critical(self, 'Hata', f'Dosya yazılırken bir hata oluştu: {e}')
