import sys

# Global callback for thread progress updates
_progress_callback = None
# Global stop flag for cancellation
_stop_requested = False


def set_progress_callback(callback):
    """Thread'den progress dialog'a mesaj göndermek için callback ayarla."""
    global _progress_callback
    _progress_callback = callback


def clear_progress_callback():
    """Callback'i temizle."""
    global _progress_callback, _stop_requested
    _progress_callback = None
    _stop_requested = False


def request_stop():
    """Durdurma isteği gönder."""
    global _stop_requested
    _stop_requested = True


def is_stop_requested():
    """Durdurma isteği var mı kontrol et."""
    return _stop_requested


def custom_write(message):
    # Eğer callback ayarlanmışsa, ona da gönder
    if _progress_callback:
        _progress_callback(message.strip())
    sys.stdout.write(message)
    sys.stdout.flush()


def custom_write_error(message):
    # Eğer callback ayarlanmışsa, ona da gönder
    if _progress_callback:
        _progress_callback(f"HATA: {message.strip()}")
    sys.stderr.write(message)
    sys.stderr.flush()


