from PyQt6.QtWidgets import (
    QLineEdit,
    QDialog,
    QPushButton,
    QVBoxLayout,
    QLabel,
    QMessageBox,
    QComboBox,
    QWidget,
    QScrollArea,
    QHBoxLayout,
    QSizePolicy,
)
from threadler import KatkiEkleThread
from progress_dialog import CustomProgressDialog
from degiskenler import *
from PyQt6.QtGui import QIcon
from PyQt6.QtCore import Qt
from close_event import closeEventHandler


class BaseKatkidaBulunanWindow(QDialog):
    def __init__(self, parent):
        super().__init__(parent)
        self.setModal(True)
        self.iletisim_bilgisi_sayisi = 0
        self.iletisim_bilgileri_dizisi = {}
        self.is_programmatic_close = False
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))

    def initUI(self):
        self.setMinimumSize(
            600, 400
        )  # Pencerenin en küçük olabileceği boyutu ayarlayın
        self.layout = QVBoxLayout()
        self.progressDialog = CustomProgressDialog("Kontrol Ediliyor...", self)
        self.progressDialog.close()
        # Ad ve GitHub Linki için giriş alanları
        self.ad_label = QLabel("Ad")
        self.ad_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.ad_input = QLineEdit()
        self.katkida_bulunma_orani_label = QLabel("Katkıda Bulunma Oranı")
        self.katkida_bulunma_orani_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.katkida_bulunma_orani = QComboBox()
        self.katkida_bulunma_orani.addItems(KATKIDA_BULUNMA_ORANI_DIZI)
        self.katkida_bulunma_orani.setCurrentText(KATKIDA_BULUNMA_ORANI_DIZI[-1])
        # Not ekleme butonu
        self.iletisimBilgisiEkleBtn = QPushButton("İletişim Bilgisi Ekle", self)
        self.iletisimBilgisiEkleBtn.setStyleSheet(
            EKLE_BUTONU_STILI
        )  # Yeşil arka plan, beyaz yazı
        self.iletisimBilgisiEkleBtn.clicked.connect(
            lambda: self.iletisimBilgisiEkle("", "")
        )
        # Not sayısını gösteren etiket
        self.iletisimBilgisiLabel = QLabel("Toplam 0 iletişim bilgisi")
        self.iletisimBilgisiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Kaydırılabilir alan oluştur
        self.scrollArea = QScrollArea(self)  # ScrollArea oluştur
        self.scrollArea.setWidgetResizable(True)

        # Linkleri gösterecek iç içe geçmiş widget'lar oluştur
        self.scrollWidget = QWidget()
        self.iletisimBilgisiLayout = QVBoxLayout(
            self.scrollWidget
        )  # Linkler için QVBoxLayout

        self.scrollArea.setWidget(self.scrollWidget)  # ScrollArea'ya widget ekle
        # Arayüze elemanları ekle
        self.layout.addWidget(self.ad_label)
        self.layout.addWidget(self.ad_input)
        self.layout.addWidget(self.katkida_bulunma_orani_label)
        self.layout.addWidget(self.katkida_bulunma_orani)
        self.layout.addWidget(self.iletisimBilgisiEkleBtn)
        self.layout.addWidget(self.iletisimBilgisiLabel)
        self.layout.addWidget(self.scrollArea)  # Ana layout'a ScrollArea ekle

        self.setLayout(self.layout)

    def iletisimBilgisiEkle(self, baslik="", link=""):
        self.iletisim_bilgisi_sayisi += 1
        text_layout = QHBoxLayout()

        # Başlık için QLabel ve QLineEdit oluştur
        label_baslik = QLabel("Başlık")
        label_baslik.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Fixed)
        iletisim_bilgisi_baslik = QLineEdit(baslik)
        iletisim_bilgisi_baslik.setSizePolicy(
            QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum
        )
        text_layout.addWidget(label_baslik)
        text_layout.addWidget(iletisim_bilgisi_baslik)

        # Link için QLabel ve QLineEdit oluştur
        label_link = QLabel("Link")
        label_link.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Fixed)
        iletisim_bilgisi_link = QLineEdit(link)
        iletisim_bilgisi_link.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum
        )
        text_layout.addWidget(label_link)
        text_layout.addWidget(iletisim_bilgisi_link)

        # Sil butonu ekle
        sil_butonu = QPushButton("Sil")
        sil_butonu.setSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)
        sil_butonu.setStyleSheet(SIL_BUTONU_STILI)
        sil_butonu.clicked.connect(lambda: self.silSatir(text_layout))
        text_layout.addWidget(sil_butonu)

        # Layout'u ana QVBoxLayout'e ekle
        self.iletisimBilgisiLayout.addLayout(text_layout)
        self.iletisimBilgisiLabel.setText(
            "Toplam {} iletişim bilgisi".format(self.iletisim_bilgisi_sayisi)
        )
        if baslik == "" and link == "":
            QMessageBox.information(
                self,
                "Bilgi",
                "İletişim bilgisi başarıyla eklendi! Göremiyorsanız aşağıya doğru kaydırın.",
            )

    def silSatir(self, layout):
        self.iletisim_bilgisi_sayisi -= 1
        # Belirtilen layout içindeki widget'ları temizle
        while layout.count():
            item = layout.takeAt(0)
            widget = item.widget()
            if widget is not None:
                widget.deleteLater()
        # Layout'u ana QVBoxLayout'den çıkar ve temizle
        self.iletisimBilgisiLayout.removeItem(layout)
        layout.deleteLater()
        self.iletisimBilgisiLabel.setText(
            "Toplam {} iletişim bilgisi".format(self.iletisim_bilgisi_sayisi)
        )

    def kaydet(self):
        ad = self.ad_input.text()
        if ad == "":
            QMessageBox.warning(self, "Hata", "Ad boş bırakılamaz!")
            return
        if not self.iletisimBilgileriYukle():
            return
        emin_mi = QMessageBox.question(
            self,
            "Onay",
            "Değişiklikleri kaydetmek istediğinden emin misin?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )

        if emin_mi == QMessageBox.StandardButton.Yes:
            self.thread = KatkiEkleThread(
                ad,
                self.kisi,
                self.iletisim_bilgileri_dizisi,
                KATKIDA_BULUNANLAR_JSON_PATH,
                self.katkida_bulunma_orani.currentText(),
                self.data,
                self,
            )
            self.thread.finished.connect(self.islemSonucu)
            # ProgressDialog'u göster
            self.progressDialog.show()
            self.thread.start()

    def iletisimBilgileriYukle(self):
        self.iletisim_bilgileri_dizisi[ILETISIM_BILGILERI] = []
        for i in range(self.iletisimBilgisiLayout.count()):
            # QVBoxLayout içindeki her bir QHBoxLayout'a eriş
            hbox_layout = self.iletisimBilgisiLayout.itemAt(i).layout()

            if hbox_layout is not None:
                iletisim_bilgisi_baslik = hbox_layout.itemAt(1).widget().text()
                iletisim_bilgisi_link = hbox_layout.itemAt(3).widget().text()
                if iletisim_bilgisi_baslik == "" or iletisim_bilgisi_link == "":
                    QMessageBox.warning(
                        self, "Hata", "İletişim bilgileri boş bırakılamaz!"
                    )
                    return False
                self.iletisim_bilgileri_dizisi[ILETISIM_BILGILERI].append(
                    {BASLIK: iletisim_bilgisi_baslik, LINK: iletisim_bilgisi_link}
                )
        return True


class KatkidaBulunanEkleWindow(BaseKatkidaBulunanWindow):
    def __init__(self, data, parent):
        self.title = "Katkıda Bulunan Ekle"
        super().__init__(parent)
        self.parent = parent
        self.kisi = None
        self.data = data

    def initUI(self):
        super().initUI()
        self.setWindowTitle(self.title)
        self.ekle_btn = QPushButton("Ekle", self)
        self.ekle_btn.setStyleSheet(EKLE_BUTONU_STILI)
        self.ekle_btn.clicked.connect(self.kaydet)
        self.layout.addWidget(self.ekle_btn)
        self.show()

    def closeEvent(self, event):
        closeEventHandler(self, event, self.is_programmatic_close)

    def islemSonucu(self, success, message):
        self.progressDialog.close()
        if success:
            QMessageBox.information(self, "Başarılı", message)
            # Gerekli güncellemeleri yapın ve pencereyi kapatın
            self.parent.butonlariYenile()
            self.is_programmatic_close = True
            self.close()
        else:
            QMessageBox.warning(self, "Hata", message)
