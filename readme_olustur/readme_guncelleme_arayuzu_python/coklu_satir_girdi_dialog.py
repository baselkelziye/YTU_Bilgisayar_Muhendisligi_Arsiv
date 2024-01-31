from PyQt6.QtWidgets import QPushButton, QVBoxLayout, QTextEdit, QDialog, QHBoxLayout
from PyQt6.QtGui import QTextOption
from degiskenler import *
class SatirAtlayanInputDialog(QDialog):
    def __init__(self, parent, title, label, text=""):
        super().__init__(parent)

        self.setWindowTitle(title)
        self.textEdit = QTextEdit(self)
        self.textEdit.setWordWrapMode(QTextOption.WrapMode.WordWrap)  # Otomatik satır kaydırma
        self.textEdit.setPlainText(text)
        self.textEdit.setAcceptRichText(False)  # Zengin metin kabul etme

        self.layout = QVBoxLayout(self)
        self.layout.addWidget(self.textEdit)

        # Butonlar için yatay düzenleyici
        self.buttonLayout = QHBoxLayout()

        self.okButton = QPushButton("Tamam", self)
        self.okButton.clicked.connect(self.accept)
        self.okButton.setStyleSheet(EKLE_BUTONU_STILI)
        self.buttonLayout.addWidget(self.okButton)

        self.cancelButton = QPushButton("İptal", self)
        self.cancelButton.clicked.connect(self.reject)
        self.cancelButton.setStyleSheet(SIL_BUTONU_STILI)
        self.buttonLayout.addWidget(self.cancelButton)

        # Ana düzenleyiciye buton düzenleyicisini ekle
        self.layout.addLayout(self.buttonLayout)

    def getText(self):
        return self.textEdit.toPlainText()

    @staticmethod
    def getMultiLineText(parent, title, label, text=""):
        dialog = SatirAtlayanInputDialog(parent, title, label, text)
        result = dialog.exec()  # PyQt6'da exec_() yerine exec() kullanılır.
        if result == QDialog.DialogCode.Accepted:
            return dialog.getText(), True
        else:
            return "", False