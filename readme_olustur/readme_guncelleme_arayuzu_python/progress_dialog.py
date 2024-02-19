from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QProgressDialog, QPushButton
from PyQt6.QtCore import QEvent


class CustomProgressDialog(QProgressDialog):
    def __init__(self, title, parent=None):
        super(CustomProgressDialog, self).__init__(title, None, 0, 0, parent)
        self.init_ui()

    def init_ui(self):
        # İptal butonunu kaldır
        self.setCancelButton(None)
        # Pencere başlık çubuğunu kaldır
        self.setWindowFlags(Qt.WindowType.Dialog | Qt.WindowType.FramelessWindowHint)

        self.setWindowModality(Qt.WindowModality.WindowModal)
        self.setMinimumDuration(0)
        self.setAutoClose(True)
        # Sürekli dönen bir hale getir
        self.setRange(0, 0)


class CustomProgressDialogWithCancel(CustomProgressDialog):
    def __init__(self, title, parent=None, fonksiyon=None):
        super().__init__(title, parent)
        self.fonksiyon = fonksiyon
        self.initUI()

    def initUI(self):
        # İptal butonunu oluştur ve bağla
        self.iptal_butonu = QPushButton("İptal", self)
        self.setCancelButton(self.iptal_butonu)
        # İptal butonunun tıklama olayını engellemek için event filter ekleyin
        self.iptal_butonu.installEventFilter(self)

    def eventFilter(self, obj, event):
        if obj == self.iptal_butonu and event.type() == QEvent.Type.MouseButtonPress:
            self.fonksiyon()
            return True

        return super().eventFilter(obj, event)
