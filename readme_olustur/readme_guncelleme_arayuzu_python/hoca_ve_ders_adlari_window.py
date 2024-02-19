import sys
import json
import locale
from PyQt6.QtWidgets import (
    QApplication,
    QDialog,
    QHBoxLayout,
    QListWidget,
    QPushButton,
    QVBoxLayout,
    QMessageBox,
)
from degiskenler import *


class HocaDersAdlariWindow(QDialog):
    def __init__(self, parent=None):
        # Türkçe karakterler için locale ayarları
        locale.setlocale(locale.LC_ALL, "tr_TR.utf8")
        super().__init__(parent)  # parent'ı super fonksiyonuna geçir
        self.setModal(True)
        self.initUI()

    def initUI(self):
        self.setWindowTitle("Hocalar ve Dersler Listesi")
        self.setGeometry(100, 100, 800, 400)  # Pencere boyutunu ayarla

        # Ana yatay düzenleyici (layout)
        h_layout = QHBoxLayout()

        # Hocalar için dikey düzenleyici
        v_layout_hocalar = QVBoxLayout()
        self.hoca_listesi = QListWidget()
        self.hoca_listesi.addItems(self.hocalari_oku_ve_sirala(HOCALAR_JSON_PATH))
        hoca_kopyala_butonu = QPushButton("Hocaları Kopyala")
        hoca_kopyala_butonu.clicked.connect(lambda: self.kopyala(self.hoca_listesi))
        v_layout_hocalar.addWidget(self.hoca_listesi)
        v_layout_hocalar.addWidget(hoca_kopyala_butonu)

        # Dersler için dikey düzenleyici
        v_layout_dersler = QVBoxLayout()
        self.ders_listesi = QListWidget()
        self.ders_listesi.addItems(self.dersleri_oku_ve_sirala(DERSLER_JSON_PATH))
        ders_kopyala_butonu = QPushButton("Dersleri Kopyala")
        ders_kopyala_butonu.clicked.connect(lambda: self.kopyala(self.ders_listesi))
        v_layout_dersler.addWidget(self.ders_listesi)
        v_layout_dersler.addWidget(ders_kopyala_butonu)

        # Yatay düzenleyiciye dikey düzenleyicileri ekle
        h_layout.addLayout(v_layout_hocalar)
        h_layout.addLayout(v_layout_dersler)

        # Ana pencereye yatay düzenleyiciyi ekle
        self.setLayout(h_layout)

    def dersleri_oku_ve_sirala(self, dosya_adi):
        # Türkçe karakterlerin doğru sıralanabilmesi için Türkçe locale ayarını kullanacağız.
        # Sistem locale ayarlarınızın bu dili desteklediğinden emin olun.
        locale.setlocale(locale.LC_ALL, "tr_TR.utf8")

        def turkce_sirala(ders_listesi):
            """
            Verilen ders adlarını Türkçe karakterleri de dikkate alarak alfabetik sıraya dizer.
            """
            return sorted(ders_listesi, key=locale.strxfrm)

        with open(dosya_adi, "r", encoding="utf-8") as dosya:
            veri = json.load(dosya)

        # Ders adlarını içeren bir liste oluştur
        ders_adlari = [ders[AD] for ders in veri[DERSLER] if ders[AD]]
        ders_adlari = turkce_sirala(ders_adlari)
        return ders_adlari

    def hocalari_oku_ve_sirala(self, dosya_adi):
        # JSON dosyasını oku
        with open(dosya_adi, "r", encoding="utf-8") as file:
            data = json.load(file)

        def sirala_ve_ayir(hocalar_listesi):
            """
            Hocaların adlarını, ünvanlarına göre önceliklendirilmiş bir sırayla sıralar.
            Önce 'Prof. Dr.', sonra 'Doç. Dr.', ardından 'Dr.' ve son olarak ünvanı olmayanları sıralar.
            """

            def unvan_önceligi(hoca_adi):
                for idx, unvan in enumerate(unvanlar):
                    if hoca_adi.startswith(unvan):
                        # Listede bulunan ünvanın indeksini döndür (1 ekleyerek 1'den başlat)
                        return idx + 1
                # Eğer hiçbir unvan eşleşmiyorsa, listenin uzunluğu + 1 değerini ver
                return len(unvanlar) + 1

            # Hocaların adlarını önceliklere göre ve alfabetik sıraya göre sırala
            sirali_hocalar = sorted(
                hocalar_listesi,
                key=lambda hoca: (unvan_önceligi(hoca), locale.strxfrm(hoca)),
            )
            return sirali_hocalar

        # Hoca adlarını işle ve unvanları at
        hoca_names = [hoca[AD] for hoca in data[HOCALAR] if hoca[AD]]
        hoca_names = sirala_ve_ayir(hoca_names)
        return hoca_names

    def kopyala(self, liste_widget):
        # Tüm öğeleri kopyala
        kopyalanacak_metin = "\n".join(
            [liste_widget.item(i).text() for i in range(liste_widget.count())]
        )
        QApplication.clipboard().setText(kopyalanacak_metin)

        # Kopyalama işlemi başarılı mesajı
        QMessageBox.information(self, "Kopyalandı", "Listedeki tüm öğeler kopyalandı.")
