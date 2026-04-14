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
    QFrame,
)
from PyQt6.QtCore import Qt
from metin_islemleri import elideText
import json
import os
from PyQt6.QtCore import QCoreApplication
import shutil
from degiskenler import (
    KONFIGURASYON_JSON_NAME,
    DOKUMANLAR_REPO_YOLU_ANAHTARI,
    KONFIGURASYON_JSON_PATH,
    JSON_DOSYALARI_DEPOSU,
    EKLE_BUTONU_STILI,
    BIR_UST_DIZIN,
    MAAS_ISTATISTIKLERI_TXT_ADI,
    settings,
)


class DosyaCakismaDialog(QDialog):
    """
    SOLID SRP: Dosya çakışması durumunda kullanıcı seçimi almaktan sorumlu.
    Kullanıcı dostu arayüz ile seçenekleri sunar.
    """
    
    # Seçim sabitleri (OCP: Genişletilebilir)
    YEDEKLE = "yedekle"
    KORU = "koru"
    IPTAL = "iptal"
    
    def __init__(self, dosya_adi, parent=None):
        super().__init__(parent)
        self.dosya_adi = dosya_adi
        self.secim = None
        self._init_ui()
    
    def _init_ui(self):
        self.setWindowTitle("⚠️ Dosya Çakışması")
        self.setObjectName("dosyaCakismaDialog")
        self.setMinimumWidth(450)
        self.setModal(True)
        
        layout = QVBoxLayout(self)
        layout.setSpacing(15)
        layout.setContentsMargins(20, 20, 20, 20)
        
        # Uyarı başlığı
        baslik = QLabel(f"📁 '{self.dosya_adi}'")
        baslik.setObjectName("cakismaBaslik")
        baslik.setAlignment(Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(baslik)
        
        # Açıklama
        aciklama = QLabel(
            "Hedef dizinde bu dosya zaten mevcut.\n"
            "Ne yapmak istediğinizi seçin:"
        )
        aciklama.setObjectName("cakismaAciklama")
        aciklama.setAlignment(Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(aciklama)
        
        # Ayırıcı çizgi
        ayirici = QFrame()
        ayirici.setFrameShape(QFrame.Shape.HLine)
        ayirici.setObjectName("cakismaAyirici")
        layout.addWidget(ayirici)
        
        # Butonlar
        self._butonlari_ekle(layout)
    
    def _butonlari_ekle(self, layout):
        """SRP: Buton oluşturma - stiller QSS'ten alınır."""
        
        # Yedekle ve Taşı butonu
        self.yedekle_btn = QPushButton("📦 Mevcut Dosyayı Yedekle ve Taşı")
        self.yedekle_btn.setObjectName("yedekleBtn")
        self.yedekle_btn.setToolTip(
            "Mevcut dosya '_yedek' eki ile yeniden adlandırılır,\n"
            "ardından yeni dosya bu konuma taşınır."
        )
        self.yedekle_btn.clicked.connect(lambda: self._secim_yap(self.YEDEKLE))
        layout.addWidget(self.yedekle_btn)
        
        # Koru butonu
        self.koru_btn = QPushButton("🛡️ Mevcut Dosyayı Koru (Atla)")
        self.koru_btn.setObjectName("koruBtn")
        self.koru_btn.setToolTip(
            "Mevcut dosya olduğu gibi kalır,\n"
            "yeni dosya taşınmaz."
        )
        self.koru_btn.clicked.connect(lambda: self._secim_yap(self.KORU))
        layout.addWidget(self.koru_btn)
        
        # İptal butonu
        self.iptal_btn = QPushButton("❌ İptal")
        self.iptal_btn.setObjectName("iptalBtn")
        self.iptal_btn.setToolTip("Tüm işlemi iptal et.")
        self.iptal_btn.clicked.connect(lambda: self._secim_yap(self.IPTAL))
        layout.addWidget(self.iptal_btn)
    
    def _secim_yap(self, secim):
        """Kullanıcı seçimini kaydet ve diyaloğu kapat."""
        self.secim = secim
        self.accept()
    
    def kullanici_secimi_al(self):
        """Diyaloğu göster ve kullanıcı seçimini döndür."""
        self.exec()
        return self.secim if self.secim else self.IPTAL


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
        self.yol = JSON_DOSYALARI_DEPOSU
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
        """
        Hedef dizinde aynı isimde dosya varsa kullanıcıya seçenek sunar.
        SRP: Koordinasyon görevi - diyalog ve yedekleme işlemlerini delege eder.
        
        Returns:
            True: Dosya taşınmalı (mevcut yedeklendi veya mevcut yoktu)
            False: Dosya taşınmamalı (kullanıcı mevcut dosyayı korumak istedi)
            None: İşlem iptal edildi
        """
        tam_yol = os.path.join(secilenYol, dosya_adi)
        if not os.path.exists(tam_yol):
            return True  # Dosya mevcut değildi, taşınabilir
        
        # SRP: Diyalog sorumluluğu ayrı sınıfa delege edildi
        dialog = DosyaCakismaDialog(dosya_adi, parent=self)
        secim = dialog.kullanici_secimi_al()
        
        if secim == DosyaCakismaDialog.IPTAL:
            return None
        elif secim == DosyaCakismaDialog.KORU:
            return False
        elif secim == DosyaCakismaDialog.YEDEKLE:
            # Yedekleme işlemi - sessizce devam et
            yeni_ad = self._yedek_dosya_adi_olustur(tam_yol)
            os.rename(tam_yol, yeni_ad)
            return True
        
        return True

    def _yedek_dosya_adi_olustur(self, tam_yol):
        """SRP: Yedek dosya adı oluşturma sorumluluğu."""
        dosya_adi_base, uzanti = os.path.splitext(tam_yol)
        yeni_ad = f"{dosya_adi_base}_yedek{uzanti}"
        
        sayac = 1
        while os.path.exists(yeni_ad):
            yeni_ad = f"{dosya_adi_base}_yedek_{sayac}{uzanti}"
            sayac += 1
        
        return yeni_ad

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
            dokumanlar_yeni_goreceli_yol = os.path.relpath(
                dokumanlar_gercek_yol, secilenYol
            ).replace(os.path.sep, "/")
            self.config[DOKUMANLAR_REPO_YOLU_ANAHTARI] = dokumanlar_yeni_goreceli_yol
            self.konfJsonaYaz()
            
            # Ayarı QSettings'e kaydet
            settings.setValue("json_depo_yolu", secilenYol)


            for jsonDosyasi in json_dosyalari:
                sonuc = self.dosya_kontrol_et_ve_degistir(secilenYol, jsonDosyasi)
                if sonuc is None:
                    # Kullanıcı işlemi iptal etti
                    QMessageBox.warning(
                        self, "İptal", "İşlem kullanıcı tarafından iptal edildi."
                    )
                    return
                elif sonuc is False:
                    # Kullanıcı mevcut dosyayı korumak istedi, kopyalama atla
                    continue
                # sonuc True ise dosyayı kopyala
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
