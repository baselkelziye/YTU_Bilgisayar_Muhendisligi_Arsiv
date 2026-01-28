from PyQt6.QtWidgets import QPushButton, QVBoxLayout, QTextEdit, QDialog, QHBoxLayout, QMessageBox
from PyQt6.QtGui import QTextOption
from degiskenler import *


class SatirAtlayanInputDialog(QDialog):
    def __init__(self, parent, title, label, text="", width=400, height=300):
        super().__init__(parent)
        self.resize(width, height)  # Diyalog penceresinin boyutunu ayarla
        self.setWindowTitle(title)
        self._original_text = text  # Orijinal metni sakla
        self.textEdit = QTextEdit(self)
        self.textEdit.setWordWrapMode(
            QTextOption.WrapMode.WordWrap
        )  # Otomatik satır kaydırma
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

    def hasChanges(self):
        """Metin değişip değişmediğini kontrol et."""
        return self.textEdit.toPlainText() != self._original_text

    def reject(self):
        """İptal butonuna basıldığında değişiklik kontrolü yap."""
        if self.hasChanges():
            reply = QMessageBox.question(
                self,
                "Değişiklikleri Kaydetmediniz",
                "Değişiklikler kaydedilmedi. Çıkmak istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if reply == QMessageBox.StandardButton.No:
                return  # İptal etme, dialog'da kal
        super().reject()

    @staticmethod
    def getMultiLineText(parent, title, label, text="", width=400, height=300):
        dialog = SatirAtlayanInputDialog(parent, title, label, text, width, height)
        result = dialog.exec()  # PyQt6'da exec_() yerine exec() kullanılır.
        if result == QDialog.DialogCode.Accepted:
            return dialog.getText(), True
        else:
            return "", False


class TekSatirInputDialog(QDialog):
    """Tek satırlık metin girişi için değişiklik kontrolü yapan dialog."""
    
    def __init__(self, parent, title, label, text="", width=300):
        super().__init__(parent)
        from PyQt6.QtWidgets import QLineEdit, QLabel
        
        self.resize(width, 100)
        self.setWindowTitle(title)
        self._original_text = text
        
        self.layout = QVBoxLayout(self)
        
        # Etiket
        self.label = QLabel(label, self)
        self.layout.addWidget(self.label)
        
        # Tek satırlık metin girişi
        self.lineEdit = QLineEdit(self)
        self.lineEdit.setText(text)
        self.layout.addWidget(self.lineEdit)
        
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
        
        self.layout.addLayout(self.buttonLayout)
    
    def getText(self):
        return self.lineEdit.text()
    
    def hasChanges(self):
        """Metin değişip değişmediğini kontrol et."""
        return self.lineEdit.text() != self._original_text
    
    def reject(self):
        """İptal butonuna basıldığında değişiklik kontrolü yap."""
        if self.hasChanges():
            reply = QMessageBox.question(
                self,
                "Değişiklikleri Kaydetmediniz",
                "Değişiklikler kaydedilmedi. Çıkmak istediğinize emin misiniz?",
                QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )
            if reply == QMessageBox.StandardButton.No:
                return
        super().reject()
    
    @staticmethod
    def getSingleLineText(parent, title, label, text="", width=300):
        """Tek satırlık metin girişi dialogunu göster ve sonucu döndür."""
        dialog = TekSatirInputDialog(parent, title, label, text, width)
        result = dialog.exec()
        if result == QDialog.DialogCode.Accepted:
            return dialog.getText(), True
        else:
            return "", False
