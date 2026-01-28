from PyQt6.QtWidgets import (
    QComboBox,
    QDialog,
    QPushButton,
    QSizePolicy,
    QHBoxLayout,
    QLineEdit,
    QMessageBox,
    QVBoxLayout,
    QLabel,
    QFileDialog,
)
from metin_islemleri import elideText
import json
import os
from PyQt6.QtCore import QCoreApplication
import shutil
from degiskenler import (
    KONFIGURASYON_JSON_NAME,
    DOKUMANLAR_REPO_YOLU_ANAHTARI,
    KONFIGURASYON_JSON_PATH,
    JSON_DOSYALARI_DEPOSU_DOSYA_YOLU,
    EKLE_BUTONU_STILI,
    BIR_UST_DIZIN,
    MAAS_ISTATISTIKLERI_TXT_ADI,
)


class KonfigurasyonDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.setMinimumWidth(600)
        self.initUI()

    def initUI(self):
        self.setWindowTitle("Konfigürasyon Düzenleyici")

        # Ana layout
        self.mainLayout = QVBoxLayout()
        self.comboBoxLayout = QHBoxLayout()
        self.jsonDepoLayout = QHBoxLayout()
        self.setLayout(self.mainLayout)

        # Sol tarafta seçenekler listesi
        self.comboBox = QComboBox()
        self.comboBox.currentIndexChanged.connect(self.onOptionSelected)
        self.comboBoxLayout.addWidget(self.comboBox)

        self.dokumanPushButton = QPushButton()
        self.dokumanPushButton.setVisible(False)
        self.dokumanPushButton.clicked.connect(self.repoSec)
        self.dokumanPushButton.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Fixed
        )
        # Sağ tarafta seçeneğin değerini gösterecek QLineEdit
        self.valueEdit = QLineEdit()
        self.valueEdit.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Fixed
        )
        self.comboBoxLayout.addWidget(self.valueEdit)
        self.comboBoxLayout.addWidget(self.dokumanPushButton)
        self.mainLayout.addLayout(self.comboBoxLayout)

        self.kaydetButton = QPushButton("Json Kaydet")
        self.kaydetButton.setStyleSheet(EKLE_BUTONU_STILI)
        self.kaydetButton.clicked.connect(self.konfKaydet)
        self.jsonDepoLabel = QLabel("Json Dosyaları Yolu")
        self.yol = self.dosya_yolu_olustur()
        self.jsonDepoButton = QPushButton(elideText(self.yol, max_length=80))
        self.jsonDepoButton.setToolTip(self.yol)
        self.jsonDepoButton.clicked.connect(self.jsonDepoSec)
        self.jsonDepoLayout.addWidget(self.jsonDepoLabel)
        self.jsonDepoLayout.addWidget(self.jsonDepoButton)
        self.mainLayout.addWidget(self.kaydetButton)
        self.mainLayout.addLayout(self.jsonDepoLayout)
        self.depoKaydet = QPushButton("Json Dosyaları Yolu Kaydet")
        self.depoKaydet.clicked.connect(self.depoDosyasiKaydet)
        self.depoKaydet.setStyleSheet(EKLE_BUTONU_STILI)
        self.mainLayout.addWidget(self.depoKaydet)
        self.readConfig()

    def klasorAc(self, button, baslangic):
        # Kullanıcıya bir klasör seçtirme ve seçilen klasörün yolunu alma
        secilenKlasorYolu = QFileDialog.getExistingDirectory(
            self, "Klasör Seç", baslangic
        )
        if secilenKlasorYolu:
            # Klasör seçildiyse, jsonDepoButton'un metnini güncelle
            button.setText(elideText(secilenKlasorYolu, max_length=80))
            button.setToolTip(secilenKlasorYolu)

    def repoSec(self):
        self.klasorAc(self.dokumanPushButton, self.dokumanPushButton.toolTip())

    def jsonDepoSec(self):
        self.klasorAc(self.jsonDepoButton, self.jsonDepoButton.toolTip())

    def dosya_kontrol_et_ve_degistir(self, secilenYol, dosya_adi):
        tam_yol = os.path.join(secilenYol, dosya_adi)
        if os.path.exists(tam_yol):
            # Kullanıcıya soru sor
            # Dosya adını ve uzantısını ayır
            dosya_adi, uzanti = os.path.splitext(tam_yol)

            # Yeni ad oluştur (_yedek ekleyerek)
            yeni_ad = f"{dosya_adi}_yedek{uzanti}"

            # Dosyanın adını değiştir
            os.rename(tam_yol, yeni_ad)
            QMessageBox.information(
                self,
                f"Dizinde {dosya_adi} dosyası tespit edildi",
                f"Bu dosyanın adı bilgilerinin kaynolmaması adına ihtiyaten {yeni_ad} olarak değiştirildi.",
            )

    def depoDosyasiKaydet(self):
        secilenYol = self.jsonDepoButton.toolTip()
        if secilenYol == self.yol:
            QMessageBox.critical(self, "Hata", "Farklı bir klasör seçmediniz...")
            return
        json_dosyalari = self.klasordeki_json_dosyalari(self.yol)
        json_dosyalari.append(MAAS_ISTATISTIKLERI_TXT_ADI)
        try:
            dokumanlar_goreceli_yol = self.config[DOKUMANLAR_REPO_YOLU_ANAHTARI]
            dokumanlar_gercek_yol = os.path.abspath(
                os.path.join(self.yol, dokumanlar_goreceli_yol)
            )
            # Mevcut çalışma dizinini al
            cwd = os.getcwd()
            cwd = os.path.join(cwd, BIR_UST_DIZIN)
            # Seçilen yolun, cwd'ye göre göreceli yolunu hesapla
            goreceliYol = os.path.relpath(secilenYol, cwd)
            dokumanlar_yeni_goreceli_yol = os.path.relpath(
                dokumanlar_gercek_yol, secilenYol
            ).replace(os.path.sep, "/")
            self.config[DOKUMANLAR_REPO_YOLU_ANAHTARI] = dokumanlar_yeni_goreceli_yol
            self.konfJsonaYaz()
            # İşletim sistemi farklılıklarını dikkate al
            goreceliYol = goreceliYol.replace(os.path.sep, "\n")
            # Göreceli yolu dosyaya kaydet
            with open(JSON_DOSYALARI_DEPOSU_DOSYA_YOLU, "w", encoding="utf-8") as dosya:
                dosya.write(goreceliYol)

            for jsonDosyasi in json_dosyalari:
                self.dosya_kontrol_et_ve_degistir(secilenYol, jsonDosyasi)
                if not self.dosyaKopyala(self.yol, jsonDosyasi, secilenYol):
                    QMessageBox.critical(
                        self, "Hata", f"{jsonDosyasi} dosyası kopyalanamadı"
                    )
            self.yol = secilenYol
            QMessageBox.information(
                self,
                "Başarılı",
                "Değişiklikler başarıyla kaydedildi. Uygulamayı yeniden başlatın...",
            )
            QCoreApplication.instance().quit()

        except Exception as e:
            QMessageBox.critical(
                self, "Hata", f"Depo dosyası güncellenirken bir hata oluştu: {e}"
            )

    def readConfig(self):
        try:
            with open(KONFIGURASYON_JSON_PATH, "r", encoding="utf-8") as file:
                self.config = json.load(file)
                for key in self.config.keys():
                    self.comboBox.addItem(key)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Konfigürasyon dosyası okunamadı: {e}")

    def konfKaydet(self):
        try:
            # Seçili anahtarın yeni değerini config sözlüğüne kaydetme
            selectedKey = self.comboBox.currentText()  # Seçili anahtar
            if selectedKey == DOKUMANLAR_REPO_YOLU_ANAHTARI:
                newValue = self.depo_yol_getir()
            else:
                newValue = (
                    self.valueEdit.text()
                )  # Kullanıcı tarafından girilen yeni değer
            if newValue == self.config[selectedKey]:
                QMessageBox.critical(self, "Hata", "Değeri değiştirmediniz...")
                return
            self.config[selectedKey] = newValue
            self.konfJsonaYaz()
            QMessageBox.information(
                self, "Başarılı", "Değişiklikler başarıyla kaydedildi."
            )

        except Exception as e:
            QMessageBox.critical(
                self, "Hata", f"Konfigürasyon dosyası kaydedilemedi: {e}"
            )

    def depo_yol_getir(self):
        return os.path.relpath(self.dokumanPushButton.text(), self.yol).replace(
            os.path.sep, "/"
        )

    def konfJsonaYaz(self):
        # Güncellenmiş config sözlüğünü JSON dosyasına yazma
        with open(KONFIGURASYON_JSON_PATH, "w", encoding="utf-8") as file:
            json.dump(self.config, file, ensure_ascii=False, indent=4)

    def onOptionSelected(self, index):
        if index >= 0:
            selectedKey = self.comboBox.itemText(index)
            if selectedKey == DOKUMANLAR_REPO_YOLU_ANAHTARI:
                self.valueEdit.setVisible(False)
                self.dokuman_repo_yol = os.path.join(
                    self.yol, self.config[DOKUMANLAR_REPO_YOLU_ANAHTARI]
                )
                self.dokuman_repo_yol = os.path.realpath(self.dokuman_repo_yol)
                self.dokumanPushButton.setText(
                    elideText(self.dokuman_repo_yol, max_length=80)
                )
                self.dokumanPushButton.setToolTip(self.dokuman_repo_yol)
                self.dokumanPushButton.setVisible(True)
            else:
                if self.valueEdit.isVisible() == False:
                    self.valueEdit.setVisible(True)
                    self.dokumanPushButton.setVisible(False)
                self.valueEdit.setText(self.config.get(selectedKey, ""))

    def dosya_yolu_olustur(self):
        try:
            # Dosya okuma
            with open(JSON_DOSYALARI_DEPOSU_DOSYA_YOLU, "r", encoding="utf-8") as dosya:
                icerik = dosya.read().strip().split("\n")
                # Dosya içeriğinden yolu parse etme
                relative_path = os.path.join(BIR_UST_DIZIN, *icerik)
                # Mevcut çalışma dizinini al
                cwd = os.getcwd()
                # CWD'ye göre tam yolu oluşturma
                tam_yol = os.path.join(cwd, relative_path)
                # İşletim sistemi farklılıklarını göz önünde bulundurarak doğru ayırıcıyı kullan
                tam_yol = os.path.normpath(tam_yol)
                return tam_yol
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Hata: {e}")
            return None

    def klasordeki_json_dosyalari(self, klasor_yolu):
        # JSON dosyalarını saklayacak bir liste oluştur
        json_dosyalari = []

        # Belirtilen klasördeki tüm dosya ve klasör isimlerini listele
        for dosya in os.listdir(klasor_yolu):
            # Eğer dosya .json uzantısına sahipse listeye ekle
            if dosya.endswith(".json"):
                json_dosyalari.append(dosya)

        return json_dosyalari

    def dosyaKopyala(self, eski_yol, dosya_adi, yeni_yol):
        try:
            # Eski dosyanın tam yolunu oluştur
            eski_dosya_yolu = os.path.join(eski_yol, dosya_adi)

            # Yeni dosyanın tam yolunu oluştur
            yeni_dosya_yolu = os.path.join(yeni_yol, dosya_adi)

            # Dosyayı eski yoldan yeni yola taşı
            shutil.copy(eski_dosya_yolu, yeni_dosya_yolu)
            return True
        except Exception as e:
            return False
