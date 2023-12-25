from PyQt5.QtWidgets import QApplication, QProgressDialog, QProgressBar
from PyQt5.QtCore import Qt, QEvent

class CustomProgressDialog(QProgressDialog):
    def __init__(self, title, parent=None):
        super(CustomProgressDialog, self).__init__(title, None, 0, 0, parent)
        self.init_ui()

    def init_ui(self):
        # İptal butonunu kaldır
        self.setCancelButton(None)
        self.setWindowModality(Qt.WindowModal)
        self.setMinimumDuration(0)
        self.setAutoClose(True)

        # ProgressBar stilini özelleştir
        self.setStyleSheet("""
            QProgressBar {
                border: 2px solid grey;
                border-radius: 5px;
                text-align: center;
            }

            QProgressBar::chunk {
                background-color: #05B8CC;
                width: 20px;
            }""")

        # Sürekli dönen bir hale getir
        self.setRange(0, 0)

