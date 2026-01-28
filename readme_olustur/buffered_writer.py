"""StringIO kullanarak yazma işlemlerini bufferla."""
import io
from typing import Optional


class BufferedReadmeWriter:
    """
    StringIO kullanarak yazma işlemlerini bufferla.
    
    Her write() çağrısında dosyaya yazmak yerine bellekte biriktir,
    save() çağrıldığında tek seferde dosyaya yaz.
    
    Performans: Çok sayıda syscall -> tek syscall
    """
    
    def __init__(self):
        self._buffer = io.StringIO()
    
    def write(self, content: str) -> "BufferedReadmeWriter":
        """
        İçeriği buffer'a yaz.
        
        Args:
            content: Yazılacak içerik
        
        Returns:
            self (chaining için)
        """
        self._buffer.write(content)
        return self
    
    def writeline(self, content: str = "") -> "BufferedReadmeWriter":
        """
        İçeriği yeni satırla birlikte yaz.
        
        Args:
            content: Yazılacak içerik
        
        Returns:
            self (chaining için)
        """
        self._buffer.write(content + "\n")
        return self
    
    def save(self, path: str) -> None:
        """
        Buffer içeriğini dosyaya yaz.
        
        Args:
            path: Hedef dosya yolu
        """
        with open(path, "w", encoding="utf-8") as f:
            f.write(self._buffer.getvalue())
    
    def append_to_file(self, path: str) -> None:
        """
        Buffer içeriğini mevcut dosyaya ekle.
        
        Args:
            path: Hedef dosya yolu
        """
        with open(path, "a", encoding="utf-8") as f:
            f.write(self._buffer.getvalue())
    
    def get_content(self) -> str:
        """Buffer içeriğini string olarak döndür."""
        return self._buffer.getvalue()
    
    def clear(self) -> None:
        """Buffer'ı temizle."""
        self._buffer = io.StringIO()
    
    def __len__(self) -> int:
        """Buffer'daki karakter sayısı."""
        return len(self._buffer.getvalue())
