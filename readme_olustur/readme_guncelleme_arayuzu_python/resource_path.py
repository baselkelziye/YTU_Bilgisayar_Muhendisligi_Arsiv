"""
PyInstaller ile derlenmiş uygulamalarda kaynak dosyalarının yollarını doğru şekilde çözmek için yardımcı modül.
"""
import sys
import os


def get_resource_path(relative_path):
    """
    Kaynak dosyasının mutlak yolunu döndürür.
    PyInstaller ile paketlenmiş uygulamalarda _MEIPASS kullanır.
    Normal çalışmada script dizinini kullanır.
    
    Args:
        relative_path: Kaynak dosyasının göreli yolu
    
    Returns:
        str: Kaynak dosyasının mutlak yolu
    """
    if getattr(sys, 'frozen', False):
        # PyInstaller ile paketlenmiş
        base_path = sys._MEIPASS
    else:
        # Normal Python çalışması
        base_path = os.path.dirname(os.path.abspath(__file__))
    
    return os.path.join(base_path, relative_path)


def get_app_dir():
    """
    Uygulamanın çalıştığı dizini döndürür.
    PyInstaller ile paketlenmiş uygulamalarda executable'ın bulunduğu dizin.
    Normal çalışmada script dizini.
    
    Returns:
        str: Uygulama dizini
    """
    if getattr(sys, 'frozen', False):
        # PyInstaller ile paketlenmiş - executable'ın bulunduğu dizin
        return os.path.dirname(sys.executable)
    else:
        # Normal Python çalışması
        return os.path.dirname(os.path.abspath(__file__))


def get_data_dir():
    """
    Veri dosyalarının (JSON, vb.) bulunduğu dizini döndürür.
    Bu genellikle uygulamanın bir üst dizinidir.
    
    Returns:
        str: Veri dizini
    """
    if getattr(sys, 'frozen', False):
        # PyInstaller ile paketlenmiş - executable'ın bir üst dizini
        return os.path.dirname(sys.executable)
    else:
        # Normal Python çalışması - readme_guncelleme_arayuzu_python'un bir üst dizini
        return os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
