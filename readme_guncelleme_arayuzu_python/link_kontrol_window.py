"""
Kırık Link Kontrolü Modülü

Bu modül, uygulamadaki linklerin erişilebilirliğini kontrol etmek için
kullanılan pencere ve thread sınıflarını içerir.
"""

import requests
import webbrowser
from PyQt6.QtCore import QThread, pyqtSignal, Qt
from PyQt6.QtWidgets import (
    QDialog,
    QVBoxLayout,
    QHBoxLayout,
    QLabel,
    QScrollArea,
    QWidget,
    QPushButton,
    QProgressBar,
    QMessageBox,
    QApplication,
    QGroupBox,
)
from PyQt6.QtGui import QIcon
from degiskenler import SELCUKLU_ICO_PATH, LINK_KONTROL_BUTONU_STILI, SIL_BUTONU_STILI, EKLE_BUTONU_STILI
from screen_utils import apply_minimum_size
import os


class LinkKontrolThread(QThread):
    """
    Linkleri arka planda kontrol eden thread sınıfı.
    
    Signals:
        progress: (int, int) - (mevcut, toplam) ilerleme bilgisi
        result: (str, str, bool, str) - (sahip_adi, url, is_valid, error_message)
        finished_all: () - tüm kontroller tamamlandığında
    """
    progress = pyqtSignal(int, int)
    result = pyqtSignal(str, str, bool, str)
    finished_all = pyqtSignal()
    
    def __init__(self, links, parent=None):
        """
        Args:
            links: Liste of tuples (sahip_adi, url)
        """
        super().__init__(parent)
        self.links = links
        self.is_running = True
    
    def run(self):
        total = len(self.links)
        for i, (sahip_adi, url) in enumerate(self.links):
            if not self.is_running:
                break
            
            is_valid, error_msg = self.check_url(url)
            self.result.emit(sahip_adi, url, is_valid, error_msg)
            self.progress.emit(i + 1, total)
        
        self.finished_all.emit()
    
    def check_url(self, url, timeout=10):
        """
        Verilen URL'in erişilebilir olup olmadığını kontrol eder.
        
        Returns:
            tuple: (is_valid: bool, error_message: str or None)
        """
        # HTTP durum kodları için Türkçe açıklamalar
        HTTP_HATA_ACIKLAMALARI = {
            400: "Geçersiz İstek",
            401: "Yetkilendirme Gerekli",
            403: "Erişim Engellendi",
            404: "Sayfa Bulunamadı",
            405: "İzin Verilmeyen Metod",
            408: "İstek Zaman Aşımı",
            410: "Sayfa Kalıcı Olarak Kaldırıldı",
            429: "Çok Fazla İstek",
            500: "Sunucu Hatası",
            502: "Geçersiz Ağ Geçidi",
            503: "Hizmet Kullanılamıyor",
            504: "Ağ Geçidi Zaman Aşımı",
            999: "Bot Koruması (LinkedIn)",
        }
        
        if not url or url.strip() == "":
            return (False, "Boş URL")
        
        # User-Agent header ekle (bazı siteler bot koruması yapıyor)
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
            'Accept-Language': 'en-US,en;q=0.5',
            'Connection': 'keep-alive',
        }
        
        # LinkedIn özel durumu: LinkedIn bot koruması çok agresif
        is_linkedin = 'linkedin.com' in url.lower()
        
        try:
            # Session kullan - daha gerçekçi browser davranışı
            session = requests.Session()
            session.headers.update(headers)
            
            # GET request kullan (HEAD çoğu sitede engelleniyor)
            response = session.get(url, allow_redirects=True, timeout=timeout, stream=True)
            status_code = response.status_code
            response.close()  # Body indirme
            session.close()
            
            # Hata açıklaması al
            def get_error_msg(code):
                if code in HTTP_HATA_ACIKLAMALARI:
                    return HTTP_HATA_ACIKLAMALARI[code]
                return f"HTTP Hatası ({code})"
            
            # LinkedIn için özel kontrol
            if is_linkedin:
                if status_code in [200, 999, 302, 303, 307, 308]:
                    return (True, None)
                elif status_code in [404, 410]:
                    return (False, get_error_msg(status_code))
                else:
                    return (True, None)
            
            # Normal siteler için kontrol
            if status_code == 200:
                return (True, None)
            elif status_code in [301, 302, 303, 307, 308]:
                return (True, None)
            elif status_code == 403:
                return (True, None)
            else:
                return (False, get_error_msg(status_code))
        except requests.Timeout:
            return (False, "Zaman aşımı")
        except requests.ConnectionError:
            return (False, "Bağlantı hatası")
        except Exception as e:
            return (False, str(e))
    
    def stop(self):
        self.is_running = False


class LinkKontrolWindow(QDialog):
    """
    Link kontrol sonuçlarını gösteren pencere.
    """
    
    def __init__(self, links, title="Kırık Bağlantı Tetkiki", parent=None):
        """
        Args:
            links: Liste of tuples (sahip_adi, url) - kontrol edilecek linkler
            title: Pencere başlığı
            parent: Ana pencere
        """
        super().__init__(parent)
        self.links = links
        self.title = title
        self.kirik_link_sayisi = 0
        self.basarili_sayisi = 0
        self.kontrol_edilen = 0
        self.thread = None
        self.basarisiz_sonuclar = []  # Kopyalama için
        self.basarili_sonuclar = []   # Kopyalama için
        self.is_finished = False
        self.initUI()
        if os.path.exists(SELCUKLU_ICO_PATH):
            self.setWindowIcon(QIcon(SELCUKLU_ICO_PATH))
    
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setModal(True)
        apply_minimum_size(self, 900, 600)
        
        self.mainLayout = QVBoxLayout(self)
        
        # Başlık
        self.baslikLabel = QLabel("🔍 Kırık Bağlantı Tetkiki Sonuçları")
        self.baslikLabel.setStyleSheet("font-size: 16px; font-weight: bold;")
        self.baslikLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.baslikLabel)
        
        # İlerleme çubuğu
        self.progressBar = QProgressBar(self)
        self.progressBar.setMaximum(len(self.links))
        self.progressBar.setValue(0)
        self.mainLayout.addWidget(self.progressBar)
        
        # İlerleme etiketi
        self.progressLabel = QLabel(f"0 / {len(self.links)} tetkik edildi")
        self.progressLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.progressLabel)
        
        # İki sütunlu alan
        columnsLayout = QHBoxLayout()
        
        # Sol sütun: Başarısız (Kırık) Linkler
        self.basarisizGroup = QGroupBox("❌ Kırık Bağlantılar (0)")
        self.basarisizGroup.setStyleSheet("QGroupBox { font-weight: bold; color: #E74C3C; }")
        basarisizLayout = QVBoxLayout(self.basarisizGroup)
        
        self.basarisizScrollArea = QScrollArea()
        self.basarisizScrollArea.setWidgetResizable(True)
        self.basarisizScrollWidget = QWidget()
        self.basarisizSonuclarLayout = QVBoxLayout(self.basarisizScrollWidget)
        self.basarisizSonuclarLayout.setAlignment(Qt.AlignmentFlag.AlignTop)
        self.basarisizScrollArea.setWidget(self.basarisizScrollWidget)
        basarisizLayout.addWidget(self.basarisizScrollArea)
        
        # Başarısız kopyala butonu
        self.basarisizKopyalaBtn = QPushButton("📋 Kırık Bağlantıları Kopyala")
        self.basarisizKopyalaBtn.setStyleSheet("background-color: #E74C3C; color: white;")
        self.basarisizKopyalaBtn.clicked.connect(lambda: self.kopyala(False))
        self.basarisizKopyalaBtn.hide()
        basarisizLayout.addWidget(self.basarisizKopyalaBtn)
        
        columnsLayout.addWidget(self.basarisizGroup)
        
        # Sağ sütun: Başarılı Linkler
        self.basariliGroup = QGroupBox("✅ Erişilebilir Bağlantılar (0)")
        self.basariliGroup.setStyleSheet("QGroupBox { font-weight: bold; color: #27AE60; }")
        basariliLayout = QVBoxLayout(self.basariliGroup)
        
        self.basariliScrollArea = QScrollArea()
        self.basariliScrollArea.setWidgetResizable(True)
        self.basariliScrollWidget = QWidget()
        self.basariliSonuclarLayout = QVBoxLayout(self.basariliScrollWidget)
        self.basariliSonuclarLayout.setAlignment(Qt.AlignmentFlag.AlignTop)
        self.basariliScrollArea.setWidget(self.basariliScrollWidget)
        basariliLayout.addWidget(self.basariliScrollArea)
        
        # Başarılı kopyala butonu
        self.basariliKopyalaBtn = QPushButton("📋 Erişilebilir Bağlantıları Kopyala")
        self.basariliKopyalaBtn.setStyleSheet("background-color: #27AE60; color: white;")
        self.basariliKopyalaBtn.clicked.connect(lambda: self.kopyala(True))
        self.basariliKopyalaBtn.hide()
        basariliLayout.addWidget(self.basariliKopyalaBtn)
        
        columnsLayout.addWidget(self.basariliGroup)
        
        self.mainLayout.addLayout(columnsLayout)
        
        # Özet etiketi
        self.ozetLabel = QLabel("")
        self.ozetLabel.setStyleSheet("font-size: 14px; font-weight: bold; padding: 10px;")
        self.ozetLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.mainLayout.addWidget(self.ozetLabel)
        
        # Alt butonlar
        buttonLayout = QHBoxLayout()
        
        # Tümünü kopyala butonu
        self.tumunuKopyalaBtn = QPushButton("📋 Tümünü Kopyala")
        self.tumunuKopyalaBtn.setStyleSheet("background-color: #3498DB; color: white;")
        self.tumunuKopyalaBtn.clicked.connect(self.tumunuKopyala)
        self.tumunuKopyalaBtn.hide()
        buttonLayout.addWidget(self.tumunuKopyalaBtn)
        
        # Kapat butonu
        self.kapatBtn = QPushButton("Kapat")
        self.kapatBtn.setStyleSheet(SIL_BUTONU_STILI)
        self.kapatBtn.clicked.connect(self.kapatTiklandi)
        buttonLayout.addWidget(self.kapatBtn)
        
        self.mainLayout.addLayout(buttonLayout)
        
        # Kontrolü başlat
        self.kontrolBaslat()
    
    def kontrolBaslat(self):
        """Link kontrolünü başlatır."""
        if len(self.links) == 0:
            self.ozetLabel.setText("⚠️ Tetkik edilecek bağlantı bulunamadı!")
            self.ozetLabel.setStyleSheet("color: orange; font-size: 14px; font-weight: bold;")
            self.is_finished = True
            self.progressBar.hide()
            self.progressLabel.hide()
            return
        
        self.thread = LinkKontrolThread(self.links, self)
        self.thread.progress.connect(self.ilerlemeGuncelle)
        self.thread.result.connect(self.sonucEkle)
        self.thread.finished_all.connect(self.kontrolBitti)
        self.thread.start()
    
    def ilerlemeGuncelle(self, mevcut, toplam):
        """İlerleme çubuğunu günceller."""
        self.progressBar.setValue(mevcut)
        self.progressLabel.setText(f"{mevcut} / {toplam} tetkik edildi")
    
    def linkTiklandi(self, url):
        """Link tıklandığında browser'da aç."""
        webbrowser.open(url)
    
    def sonucEkle(self, sahip_adi, url, is_valid, error_msg):
        """Sonuç listesine yeni bir sonuç ekler."""
        self.kontrol_edilen += 1
        
        sonucWidget = QWidget()
        sonucLayout = QVBoxLayout(sonucWidget)
        sonucLayout.setContentsMargins(5, 5, 5, 5)
        
        # Durum ikonu ve sahip adı
        if is_valid:
            ikon = "✅"
            renk = "#27AE60"  # Yeşil
            target_layout = self.basariliSonuclarLayout
            self.basarili_sayisi += 1
            self.basarili_sonuclar.append(f"{sahip_adi}\n   {url}")
            self.basariliGroup.setTitle(f"✅ Erişilebilir Bağlantılar ({self.basarili_sayisi})")
        else:
            ikon = "❌"
            renk = "#E74C3C"  # Kırmızı
            target_layout = self.basarisizSonuclarLayout
            self.kirik_link_sayisi += 1
            self.basarisiz_sonuclar.append(f"{sahip_adi}\n   {url}\n   Hata: {error_msg}")
            self.basarisizGroup.setTitle(f"❌ Kırık Bağlantılar ({self.kirik_link_sayisi})")
        
        baslikLabel = QLabel(f"{ikon} <b>{sahip_adi}</b>")
        baslikLabel.setStyleSheet(f"color: {renk}; font-size: 12px;")
        sonucLayout.addWidget(baslikLabel)
        
        # Tıklanabilir URL
        urlLabel = QLabel(f"   <a href='{url}' style='color: #3498DB;'>{url}</a>")
        urlLabel.setStyleSheet("font-size: 10px;")
        urlLabel.setWordWrap(True)
        urlLabel.setTextInteractionFlags(Qt.TextInteractionFlag.TextBrowserInteraction)
        urlLabel.linkActivated.connect(self.linkTiklandi)
        sonucLayout.addWidget(urlLabel)
        
        # Hata mesajı (sadece başarısızlar için)
        if not is_valid and error_msg:
            hataLabel = QLabel(f"   ⚠️ {error_msg}")
            hataLabel.setStyleSheet("color: #E67E22; font-size: 10px;")
            sonucLayout.addWidget(hataLabel)
        
        target_layout.addWidget(sonucWidget)
    
    def kontrolBitti(self):
        """Kontrol tamamlandığında çağrılır."""
        self.is_finished = True
        self.tumunuKopyalaBtn.show()
        if self.kirik_link_sayisi > 0:
            self.basarisizKopyalaBtn.show()
        if self.basarili_sayisi > 0:
            self.basariliKopyalaBtn.show()
        
        self.progressLabel.setText(f"Tamamlandı! {self.kontrol_edilen} bağlantı tetkik edildi.")
        
        if self.kirik_link_sayisi == 0:
            self.ozetLabel.setText(f"✅ Tüm bağlantılar ({self.kontrol_edilen}) erişilebilir durumda!")
            self.ozetLabel.setStyleSheet("color: #27AE60; font-size: 14px; font-weight: bold; padding: 10px;")
        else:
            self.ozetLabel.setText(
                f"❌ {self.kirik_link_sayisi} kırık bağlantı tespit edildi! "
                f"({self.basarili_sayisi} bağlantı erişilebilir)"
            )
            self.ozetLabel.setStyleSheet("color: #E74C3C; font-size: 14px; font-weight: bold; padding: 10px;")
    
    def kopyala(self, basarili=True):
        """Seçilen kategorideki sonuçları panoya kopyalar."""
        if basarili:
            baslik = f"✅ Erişilebilir Bağlantılar ({self.basarili_sayisi})\n{'═' * 40}\n\n"
            sonuclar = "\n\n".join(self.basarili_sonuclar)
            mesaj = "Erişilebilir bağlantılar panoya kopyalandı!"
        else:
            baslik = f"❌ Kırık Bağlantılar ({self.kirik_link_sayisi})\n{'═' * 40}\n\n"
            sonuclar = "\n\n".join(self.basarisiz_sonuclar)
            mesaj = "Kırık bağlantılar panoya kopyalandı!"
        
        tam_metin = baslik + sonuclar
        
        clipboard = QApplication.clipboard()
        clipboard.setText(tam_metin)
        
        QMessageBox.information(self, "Kopyalandı", mesaj)
    
    def tumunuKopyala(self):
        """Tüm sonuçları panoya kopyalar."""
        baslik = f"🔍 {self.title}\n{'═' * 50}\n\n"
        
        kirik = ""
        if self.basarisiz_sonuclar:
            kirik = f"❌ KIRIK BAĞLANTILAR ({self.kirik_link_sayisi})\n{'-' * 40}\n"
            kirik += "\n\n".join(self.basarisiz_sonuclar)
            kirik += "\n\n"
        
        basarili = ""
        if self.basarili_sonuclar:
            basarili = f"✅ ERİŞİLEBİLİR BAĞLANTILAR ({self.basarili_sayisi})\n{'-' * 40}\n"
            basarili += "\n\n".join(self.basarili_sonuclar)
        
        ozet = f"\n\n{'═' * 50}\n"
        ozet += f"ÖZET: Toplam {self.kontrol_edilen} bağlantı | "
        ozet += f"Erişilebilir: {self.basarili_sayisi} | Kırık: {self.kirik_link_sayisi}"
        
        tam_metin = baslik + kirik + basarili + ozet
        
        clipboard = QApplication.clipboard()
        clipboard.setText(tam_metin)
        
        QMessageBox.information(self, "Kopyalandı", "Tüm sonuçlar panoya kopyalandı!")
    
    def kapatTiklandi(self):
        """Kapat butonuna tıklandığında çağrılır."""
        if not self.is_finished and self.thread and self.thread.isRunning():
            reply = QMessageBox.question(
                self,
                "Tetkik Devam Ediyor",
                "Bağlantı tetkiki hala devam ediyor!\n\nKapatmak istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No
            )
            if reply == QMessageBox.StandardButton.Yes:
                self.thread.stop()
                self.thread.wait()
                self.close()
        else:
            self.close()
    
    def closeEvent(self, event):
        """Pencere kapatılırken thread'i durdur."""
        if not self.is_finished and self.thread and self.thread.isRunning():
            reply = QMessageBox.question(
                self,
                "Tetkik Devam Ediyor",
                "Bağlantı tetkiki hala devam ediyor!\n\nKapatmak istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No
            )
            if reply == QMessageBox.StandardButton.Yes:
                self.thread.stop()
                self.thread.wait()
                event.accept()
            else:
                event.ignore()
        else:
            if self.thread and self.thread.isRunning():
                self.thread.stop()
                self.thread.wait()
            event.accept()
    
    def keyPressEvent(self, event):
        """Ctrl+C kısayolu."""
        if event.modifiers() & Qt.KeyboardModifier.ControlModifier:
            if event.key() == Qt.Key.Key_C:
                if self.is_finished:
                    self.tumunuKopyala()
