from PyQt6.QtWidgets import QMessageBox


def closeEventHandler(parent, event, is_programmatic_close, has_changes=True):
    """
    Pencere kapatma olayını yönetir.
    """
    if is_programmatic_close:
        event.accept()
        return
    
    if not has_changes:
        event.accept()
        return
    
    reply = QMessageBox.question(
        parent,
        "Kapat",
        "Değişiklikleri kaydetmeden kapatmak istediğine emin misin?",
        QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        QMessageBox.StandardButton.No,
    )
    
    if reply == QMessageBox.StandardButton.Yes:
        parent.is_programmatic_close = True  # Sonraki çağrılarda soru sorma
        event.accept()
    else:
        event.ignore()
