from yazarin_notlari_duzenle_window import YazarinNotlariWindow
from degiskenler import *
from PyQt6.QtWidgets import (
    QLabel,
    QLineEdit,
    QMessageBox,
    QPushButton,
    QHBoxLayout,
    QDialog,
    QVBoxLayout,
    QSizePolicy
)
from coklu_satir_girdi_dialog import SatirAtlayanInputDialog
from metin_islemleri import kisaltMetin
import json
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QIcon, QGuiApplication
import re


class GirisEkleGuncelleWindow(YazarinNotlariWindow):
    def __init__(self, parent):
        super().__init__(parent)

    def initUI(self):
        super().initUI()
        baslik = self.data.get(BASLIK, VARSAYILAN_GIRIS_BASLIK)
        aciklama = self.data.get(ACIKLAMA, VARSAYILAN_GIRIS_ACIKLAMA)
        self.baslikBtn.setText(kisaltMetin(baslik))
        self.baslikBtn.setToolTip(baslik)
        self.aciklama_label = QLabel("Açıklama", self)
        self.aciklama_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.insertWidget(3, self.aciklama_label)
        self.aciklama_duzenle_btn = QPushButton(kisaltMetin(aciklama), self)
        self.aciklama_duzenle_btn.setStyleSheet(ACIKLAMA_BUTON_STILI)
        self.aciklama_duzenle_btn.setToolTip(
            aciklama
        )  # Tam metni araç ipucu olarak ekle
        self.aciklama_duzenle_btn.clicked.connect(
            lambda: self.aciklamaDuzenle(ACIKLAMA)
        )
        self.mainLayout.insertWidget(4, self.aciklama_duzenle_btn)
        self.ekleBtn.setText("İçindekiler Ekle")
        self.setWindowTitle("Giriş Güncelleme")
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

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

            for idx, not_ in enumerate(self.data[ICINDEKILER]):
                btn_layout = QHBoxLayout()
                up_down_btn_layout = QVBoxLayout()
                btn = QPushButton(
                    f"İçindekiler {idx + 1}: {kisaltMetin(not_)}", self.scrollWidget
                )  # İlk 30 karakteri göster
                btn.setToolTip(not_)  # Tam metni araç ipucu olarak ekle
                btn.clicked.connect(lambda checked, i=idx: self.notDuzenle(i))
                sizePolicy = QSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Preferred)
                btn.setSizePolicy(sizePolicy)
                btn_layout.addWidget(btn)
                # Yukarı Taşı butonu
                upBtn = QPushButton("Yukarı çıkar", self.scrollWidget)
                upBtn.clicked.connect(lambda checked, i=idx: self.notTasi(i, i-1))
                upBtn.setStyleSheet(YUKARI_BUTON_STILI)
                up_down_btn_layout.addWidget(upBtn)

                # Aşağı Taşı butonu
                downBtn = QPushButton("Aşağı indir", self.scrollWidget)
                downBtn.setStyleSheet(ASAGI_BUTON_STILI)
                downBtn.clicked.connect(lambda checked, i=idx: self.notTasi(i, i+1))
                up_down_btn_layout.addWidget(downBtn)
                btn_layout.addLayout(up_down_btn_layout)
                self.notlarLayout.addLayout(btn_layout)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya okunurken bir hata oluştu: {e}")
    def notlariTemizle(self):
        # Layout içinde dolaş ve her bir item'ı sil
        for i in reversed(range(self.notlarLayout.count())): 
            layoutItem = self.notlarLayout.itemAt(i)
            # Eğer layout item bir widget'a sahipse, widget'ı sil
            if layoutItem.widget():
                widget = layoutItem.widget()
                self.notlarLayout.removeWidget(widget)  # Widget'ı layout'tan çıkar
                widget.deleteLater()  # Widget'ı bellekten tamamen sil
            # Eğer layout item başka bir layout ise, bu layout'u sil
            elif layoutItem.layout():
                subLayout = layoutItem.layout()
                self.layoutuTemizle(subLayout)  # Alt layout'u temizle
                subLayout.deleteLater()  # Alt layout'u bellekten tamamen sil
            # Eğer layout item bir spacer ise, onu çıkar
            elif layoutItem.spacerItem():
                self.notlarLayout.removeItem(layoutItem)  # Spacer item'ı layout'tan çıkar

    def layoutuTemizle(self, layout):
        # Verilen layout içinde dolaş ve her bir item'ı sil
        for i in reversed(range(layout.count())): 
            layoutItem = layout.itemAt(i)
            if layoutItem.widget():
                widget = layoutItem.widget()
                layout.removeWidget(widget)
                widget.deleteLater()
            elif layoutItem.layout():
                subLayout = layoutItem.layout()
                self.layoutuTemizle(subLayout)
                subLayout.deleteLater()
            elif layoutItem.spacerItem():
                layout.removeItem(layoutItem)

    def notlariYenile(self):
        self.notlariTemizle()
        self.notlariYukle()
        self.clearFiltersButton.hide()  # Temizle butonunu gizle
    def notTasi(self, idx, idx2):
        total_items = self.notlarLayout.count()

        # Negatif indeksleri dönüştür
        if idx < 0:
            idx += total_items
        if idx2 < 0:
            idx2 += total_items
        idx %= total_items
        idx2 %= total_items
        self.btnSwap(
            self.notlarLayout.itemAt(idx).layout().itemAt(0).widget(),  # Mevcut buton
            self.notlarLayout.itemAt(idx2).layout().itemAt(0).widget(),  # Bir alttaki buton
            idx,
            idx2
        )

    # buton swap işi
    def btnSwap(self, btn1, btn2, idx1, idx2):
        tmp_text = btn1.toolTip()
        btn1.setText(f"İçindekiler {idx1 + 1}: {kisaltMetin(btn2.toolTip())}")
        btn1.setToolTip(btn2.toolTip())
        btn2.setText(f"İçindekiler {idx2 + 1}: {kisaltMetin(tmp_text)}")
        btn2.setToolTip(tmp_text)
        self.data[ICINDEKILER][idx1], self.data[ICINDEKILER][idx2] = (
            self.data[ICINDEKILER][idx2],
            self.data[ICINDEKILER][idx1],
        )
        self.jsonKaydet()
    
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
            for i in range(self.notlarLayout.count()):
                layout = self.notlarLayout.itemAt(i)
                self.layoutGorunumDegistir(layout, True)
            self.clearFiltersButton.hide()  # Temizle butonunu gizle
            self.notSayisiLabel.setText(
                f"Toplam {len(self.data[ICINDEKILER])} içindekiler"
            )  # Not sayısını etikette güncelle

    def searchNotes(self, query):
        if not query:
            self.clearFilters(is_clicked=False)
            return
        size = 0
        for idx, not_ in enumerate(self.data[ICINDEKILER]):
            widget = self.notlarLayout.itemAt(idx).itemAt(0).widget()
            if isinstance(widget, QPushButton):
                if query.replace('İ','i').lower() in not_.replace('İ','i').lower():
                    self.layoutGorunumDegistir(self.notlarLayout.itemAt(idx), gorunum=True)
                    size += 1
                else:
                    self.layoutGorunumDegistir(self.notlarLayout.itemAt(idx), gorunum=False)
        if size == len(self.data[ICINDEKILER]):
            self.clearFilters(is_clicked=False)
            return
        self.notSayisiLabel.setText(f"{size} içindekiler bulundu")
        if query:
            self.clearFiltersButton.show()
        else:
            self.clearFiltersButton.hide()
    def layoutGorunumDegistir(self, layout, gorunum):
        for i in range(layout.count()):
            item = layout.itemAt(i)
            if item.widget() is not None:  # Eğer item bir widget ise
                widget = item.widget()
                if gorunum:
                    widget.show()
                else:
                    widget.hide()
            elif item.layout() is not None:  # Eğer item bir alt layout ise
                self.layoutGorunumDegistir(item.layout(), gorunum)  # Fonksiyon kendini rekürsif olarak çağırır

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
            QMessageBox.information(
                self, "Başarılı", "Açıklama güncellendi ve kaydedildi!"
            )
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")

    def notEkle(self):
        self.duzenlemePenceresi = IcindekilerDuzenleWindow(None, self.data,"",ICINDEKILER, GIRIS_JSON_PATH, self)
        self.duzenlemePenceresi.show()

    def notDuzenle(self, idx):
        self.duzenlemePenceresi = IcindekilerDuzenleWindow(idx, self.data, self.data.get(ICINDEKILER,[""])[idx],ICINDEKILER, GIRIS_JSON_PATH, self)
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
            del self.data[self.key][self.idx]
            self.kaydetVeKapat()

    def kaydetVeKapat(self):
        try:
            with open(self.json_path, "w", encoding="utf-8") as file:
                json.dump(self.data, file, ensure_ascii=False, indent=4)
            QMessageBox.information(self, "Başarılı", "İçindekiler güncellendi!")
            self.parent.notlariYenile()
            self.is_programmatic_close = True
            self.close()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Dosya yazılırken bir hata oluştu: {e}")
