"""
Ekran çözünürlüğüne göre dinamik boyut hesaplama yardımcı modülü.

Bu modül, pencere boyutlarını kullanıcının ekran çözünürlüğüne göre
oranlanmış şekilde hesaplar.
"""

from PyQt6.QtGui import QGuiApplication


def get_screen_size():
    """
    Mevcut ekranın kullanılabilir boyutunu döndürür.
    
    Returns:
        tuple: (genişlik, yükseklik) piksel cinsinden veya None eğer ekran alınamazsa
    """
    try:
        app = QGuiApplication.instance()
        if app is None:
            return None
        
        screen = QGuiApplication.primaryScreen()
        if screen is None:
            return None
            
        geometry = screen.availableGeometry()
        return geometry.width(), geometry.height()
    except Exception:
        return None


def calculate_minimum_size(base_width, base_height, reference_width=1920, reference_height=1080):
    """
    Referans çözünürlüğe göre oranlanmış minimum boyut döndürür.
    
    Pencere boyutunu ekranın yüzdesine göre hesaplar.
    Örneğin: base_width=500 ve reference_width=1920 ise, pencere ekran genişliğinin %26'sı kadar olur.
    
    Args:
        base_width: Temel genişlik (referans çözünürlük için)
        base_height: Temel yükseklik (referans çözünürlük için)
        reference_width: Referans ekran genişliği (varsayılan 1920)
        reference_height: Referans ekran yüksekliği (varsayılan 1080)
    
    Returns:
        tuple: (hesaplanan_genişlik, hesaplanan_yükseklik)
    """
    screen_size = get_screen_size()
    
    # Eğer ekran boyutu alınamazsa (QApplication henüz başlatılmamış), 
    # base değerleri olduğu gibi döndür
    if screen_size is None:
        return base_width, base_height
    
    screen_w, screen_h = screen_size
    
    # Pencere boyutunu ekranın yüzdesine göre hesapla
    # base_width/reference_width = hedef genişlik oranı
    width_percent = base_width / reference_width
    height_percent = base_height / reference_height
    
    # Hesaplanan boyutlar
    calc_width = int(screen_w * width_percent)
    calc_height = int(screen_h * height_percent)
    
    # Minimum değerler (çok küçük olmasın)
    calc_width = max(calc_width, 300)
    calc_height = max(calc_height, 150)
    
    return calc_width, calc_height


def calculate_scroll_area_size(base_width, base_height):
    """
    Kaydırılabilir alanlar için boyut hesaplar.
    
    Args:
        base_width: Temel genişlik
        base_height: Temel yükseklik
    
    Returns:
        tuple: (hesaplanan_genişlik, hesaplanan_yükseklik)
    """
    return calculate_minimum_size(base_width, base_height)


def apply_minimum_size(widget, base_width, base_height, reference_width=1920, reference_height=1080):
    """
    Widget'a ekran çözünürlüğüne göre oranlanmış minimum boyut uygular.
    Aynı zamanda başlangıç boyutunu da ayarlar.
    
    Args:
        widget: Boyutlandırılacak QWidget (QDialog, QMainWindow vb.)
        base_width: Temel genişlik (referans çözünürlük için)
        base_height: Temel yükseklik (referans çözünürlük için)
        reference_width: Referans ekran genişliği (varsayılan 1920)
        reference_height: Referans ekran yüksekliği (varsayılan 1080)
    """
    w, h = calculate_minimum_size(base_width, base_height, reference_width, reference_height)
    widget.setMinimumSize(w, h)
    widget.resize(w, h)  # Başlangıç boyutunu da ayarla

