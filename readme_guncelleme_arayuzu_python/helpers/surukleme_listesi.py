from PyQt6.QtWidgets import (
    QListWidget,
    QAbstractItemView,
    QListWidgetItem,
    QLabel,
)
from PyQt6.QtCore import Qt, pyqtSignal
from PyQt6.QtGui import QDragEnterEvent, QDropEvent


def surukle_bilgi_etiketi(parent=None) -> QLabel:
    """Sürükle-bırak arayüzü için bilgi etiketi oluşturur"""
    bilgiLabel = QLabel("💡 Sıralamayı değiştirmek için öğeleri sürükleyip bırakın, düzenlemek için çift tıklayın", parent)
    bilgiLabel.setObjectName("surukleBilgiLabel")
    bilgiLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
    return bilgiLabel


class SuruklemeListe(QListWidget):
    """Sürükle-bırak ile öğe sıralaması yapılabilen liste widget'ı"""
    
    siralama_degisti = pyqtSignal()  # Sıralama değiştiğinde sinyal gönder
    
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setObjectName("suruklemeListe")  # QSS için object name
        self.setDragDropMode(QAbstractItemView.DragDropMode.InternalMove)
        self.setDefaultDropAction(Qt.DropAction.MoveAction)
        self.setSelectionMode(QAbstractItemView.SelectionMode.SingleSelection)
        self.setAcceptDrops(True)
        self.setDragEnabled(True)
    
    def dropEvent(self, event: QDropEvent):
        """Öğe bırakıldığında sıralama değişikliği sinyali gönder"""
        super().dropEvent(event)
        self.siralama_degisti.emit()


class SuruklemeListeItem(QListWidgetItem):
    """Sürüklenebilir liste öğesi"""
    
    def __init__(self, text: str, data=None, index: int = -1):
        super().__init__(text)
        self.setFlags(
            Qt.ItemFlag.ItemIsEnabled |
            Qt.ItemFlag.ItemIsSelectable |
            Qt.ItemFlag.ItemIsDragEnabled
        )
        # Özel veri saklama
        self._custom_data = data
        self._original_index = index
    
    @property
    def custom_data(self):
        return self._custom_data
    
    @custom_data.setter
    def custom_data(self, value):
        self._custom_data = value
    
    @property
    def original_index(self):
        return self._original_index
    
    @original_index.setter
    def original_index(self, value):
        self._original_index = value
