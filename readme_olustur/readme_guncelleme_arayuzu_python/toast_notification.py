"""
Geçici bildirim (Toast Notification) modülü.
Kullanıcıya kısa süreli mesajlar gösterir ve otomatik olarak kaybolur.
"""

from PyQt6.QtWidgets import QLabel, QWidget, QVBoxLayout, QApplication
from PyQt6.QtCore import QTimer, Qt


class ToastNotification(QWidget):
    """Geçici bildirim widget'ı - belirli süre sonra otomatik kapanır"""
    
    _instance = None
    _current_toast = None
    
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowFlags(
            Qt.WindowType.FramelessWindowHint |
            Qt.WindowType.WindowStaysOnTopHint |
            Qt.WindowType.Tool
        )
        self.setAttribute(Qt.WidgetAttribute.WA_TranslucentBackground)
        self.setAttribute(Qt.WidgetAttribute.WA_ShowWithoutActivating)
        
        layout = QVBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        
        self.label = QLabel()
        self.label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.label.setWordWrap(True)
        layout.addWidget(self.label)
        
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.fadeOut)
        
    def showMessage(self, message, msg_type="info", duration=2500):
        """
        Bildirimi göster.
        
        Args:
            message: Gösterilecek mesaj
            msg_type: Bildirim türü ('success', 'error', 'warning', 'info')
            duration: Görüntülenme süresi (milisaniye)
        """
        # Önceki toast varsa kapat
        if ToastNotification._current_toast and ToastNotification._current_toast != self:
            ToastNotification._current_toast.close()
        
        ToastNotification._current_toast = self
        
        self.label.setText(message)
        # QSS'den stil almak için objectName kullan
        self.label.setObjectName(f"toast-{msg_type}")
        # Stil değişikliğini uygula
        self.label.style().unpolish(self.label)
        self.label.style().polish(self.label)
        self.adjustSize()
        
        # Ekranın alt ortasına konumlandır
        self.positionToast()
        
        self.show()
        self.raise_()
        
        self.timer.start(duration)
        
    def positionToast(self):
        """Toast'ı parent widget'ın veya ekranın alt ortasına konumlandır"""
        if self.parent():
            parent_rect = self.parent().geometry()
            x = parent_rect.x() + (parent_rect.width() - self.width()) // 2
            y = parent_rect.y() + parent_rect.height() - self.height() - 50
        else:
            screen = QApplication.primaryScreen().geometry()
            x = (screen.width() - self.width()) // 2
            y = screen.height() - self.height() - 100
        
        self.move(x, y)
        
    def fadeOut(self):
        """Bildirimi kapat"""
        self.timer.stop()
        self.close()
        
    def close(self):
        """Bildirimi kapat"""
        self.timer.stop()
        if ToastNotification._current_toast == self:
            ToastNotification._current_toast = None
        super().close()


def show_toast(parent, message, msg_type="info", duration=2500):
    """
    Kolay kullanım için yardımcı fonksiyon.
    
    Args:
        parent: Üst widget
        message: Gösterilecek mesaj
        msg_type: Bildirim türü ('success', 'error', 'warning', 'info')
        duration: Görüntülenme süresi (milisaniye)
    """
    toast = ToastNotification(parent)
    toast.showMessage(message, msg_type, duration)
    return toast


def show_success(parent, message, duration=2500):
    """Başarı bildirimi göster"""
    return show_toast(parent, message, "success", duration)


def show_error(parent, message, duration=3000):
    """Hata bildirimi göster"""
    return show_toast(parent, message, "error", duration)


def show_warning(parent, message, duration=2500):
    """Uyarı bildirimi göster"""
    return show_toast(parent, message, "warning", duration)


def show_info(parent, message, duration=2500):
    """Bilgi bildirimi göster"""
    return show_toast(parent, message, "info", duration)
