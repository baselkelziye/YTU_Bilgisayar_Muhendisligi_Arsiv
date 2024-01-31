from PyQt6.QtWidgets import QMessageBox


def closeEventHandler(parent, event, is_programmatic_close):
    if is_programmatic_close:
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
        event.accept()
        QMessageBox.information(parent, "İptal", "Değişiklikler kaydedilmedi.")
    else:
        event.ignore()
