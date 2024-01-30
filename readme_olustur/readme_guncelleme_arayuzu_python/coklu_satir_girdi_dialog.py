from PyQt5.QtWidgets import QPushButton, QVBoxLayout, QTextEdit, QDialog, QHBoxLayout
from degiskenler import *
class SatirAtlayanInputDialog(QDialog):
    def __init__(self, parent, title, label, text=""):
        super().__init__(parent)

        self.setWindowTitle(title)
        self.textEdit = QTextEdit(self)
        self.textEdit.setWordWrapMode(True)  # Otomatik satır kaydırma
        self.textEdit.setText(text)

        self.layout = QVBoxLayout(self)
        self.layout.addWidget(self.textEdit)

        # Butonlar için yatay düzenleyici
        self.buttonLayout = QHBoxLayout()

        self.okButton = QPushButton("Tamam", self)
        self.okButton.setStyleSheet(EKLE_BUTONU_STILI)
        self.okButton.clicked.connect(self.accept)
        self.buttonLayout.addWidget(self.okButton)

        self.cancelButton = QPushButton("İptal", self)
        self.cancelButton.setStyleSheet(SIL_BUTONU_STILI)
        self.cancelButton.clicked.connect(self.reject)
        self.buttonLayout.addWidget(self.cancelButton)

        # Ana düzenleyiciye buton düzenleyicisini ekle
        self.layout.addLayout(self.buttonLayout)

    def getText(self):
        return self.textEdit.toPlainText()

    @staticmethod
    def getMultiLineText(parent, title, label, text=""):
        dialog = SatirAtlayanInputDialog(parent, title, label, text)
        result = dialog.exec_()
        if result == QDialog.Accepted:
            return dialog.getText(), True
        else:
            return "", False
