from PyQt6.QtCore import Qt, QObject
from PyQt6.QtWidgets import QProgressDialog, QPushButton, QWidget
from PyQt6.QtCore import QEvent
from typing import Callable, Optional


class CustomProgressDialog(QProgressDialog):
    """
    CustomProgressDialog sınıfı, QProgressDialog sınıfının özelleştirilmiş bir versiyonudur. Bu sınıf,
    sürekli dönen bir yükleme göstergesi oluşturur ve iptal butonunu kaldırır. Ayrıca, pencere başlık çubuğunu
    da kaldırarak daha minimal bir tasarım sağlar.
    """

    def __init__(self, title: str, parent: Optional[QWidget] = None) -> None:
        """
        CustomProgressDialog sınıfının kurucusudur.

        Parameters:
        title (str): Pencerenin başlığı olarak kullanılacak metin.
        parent (Optional[QWidget]): İsteğe bağlı olarak belirtilen ebeveyn widget.
        """
        super().__init__(parent)
        self.setLabelText(title)  # Pencerenin başlığını ayarla
        self.init_ui()  # Kullanıcı arayüzünü başlat

    def init_ui(self) -> None:
        """
        Kullanıcı arayüzünü başlatan yardımcı fonksiyon. Bu fonksiyon, iptal butonunu kaldırır,
        pencere başlık çubuğunu gizler ve sürekli dönen bir yükleme göstergesi oluşturur.
        """
        self.setCancelButton(None)  # İptal butonunu kaldır
        self.setWindowFlags(
            Qt.WindowType.Dialog | Qt.WindowType.FramelessWindowHint
        )  # Pencere başlık çubuğunu kaldır
        self.setWindowModality(Qt.WindowModality.WindowModal)  # Pencere modunu ayarla
        self.setMinimumDuration(0)  # Minimum süreyi 0 olarak ayarla
        self.setAutoClose(True)  # Otomatik kapanmayı etkinleştir
        self.setRange(0, 0)  # Sürekli dönen bir yükleme göstergesi oluştur


class CustomProgressDialogWithCancel(CustomProgressDialog):
    """
    CustomProgressDialogWithCancel sınıfı, CustomProgressDialog sınıfının iptal butonu eklenmiş versiyonudur.
    Bu sınıf, bir iptal butonu ile birlikte gelir ve iptal butonuna tıklama olayında belirli bir fonksiyonu çalıştırır.
    """

    def __init__(
        self,
        title: str,
        parent: Optional[QWidget] = None,
        fonksiyon: Callable[[], None] = None,
    ) -> None:
        """
        CustomProgressDialogWithCancel sınıfının kurucusudur.

        Parameters:
        title (str): Pencerenin başlığı olarak kullanılacak metin.
        parent (Optional[QWidget]): İsteğe bağlı olarak belirtilen ebeveyn widget.
        fonksiyon (Callable[[], None]): İptal butonuna tıklanınca çalıştırılacak fonksiyon.
        """
        super().__init__(title, parent)
        self.fonksiyon = fonksiyon  # İptal fonksiyonunu belirle
        self.initUI()  # Kullanıcı arayüzünü başlat

    def initUI(self) -> None:
        """
        Kullanıcı arayüzünü başlatan yardımcı fonksiyon. Bu fonksiyon, iptal butonunu oluşturur
        ve tıklama olayını engellemek için event filter ekler.
        """
        self.iptal_butonu = QPushButton("İptal", self)  # İptal butonunu oluştur
        self.setCancelButton(self.iptal_butonu)  # İptal butonunu ayarla
        self.iptal_butonu.installEventFilter(self)  # İptal butonuna event filter ekle

    def eventFilter(self, obj: QObject, event: QEvent) -> bool:
        """
        Olay filtresini işleyen fonksiyon. Eğer iptal butonuna tıklanırsa, belirlenen fonksiyonu çalıştırır.

        Parameters:
        obj (QObject): Olayın meydana geldiği nesne.
        event (QEvent): Gerçekleşen olay.

        Returns:
        bool: Olayın işlenip işlenmediğini belirten boolean değer.
        """
        if obj == self.iptal_butonu and event.type() == QEvent.Type.MouseButtonPress:
            if self.fonksiyon:
                self.fonksiyon()  # Belirlenen fonksiyonu çalıştır
            return True  # Olayı işlediğini belirt

        return super().eventFilter(obj, event)  # Olayı üst sınıfa ilet
