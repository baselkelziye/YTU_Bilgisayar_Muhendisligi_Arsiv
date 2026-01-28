"""Bölüm yazıcı base class."""
from abc import ABC, abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


class SectionWriter(ABC):
    """
    Bölüm yazıcı abstract base class.
    
    Her README bölümü için bir writer sınıfı oluşturulur.
    Bu, Open/Closed Principle'a uygun bir yapı sağlar:
    - Yeni bölüm eklemek için mevcut kodu değiştirmek gerekmez
    - Sadece yeni bir SectionWriter alt sınıfı oluşturulur
    """
    
    @abstractmethod
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Bölümü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Bölüm için gerekli veriler
        """
        pass
    
    @property
    @abstractmethod
    def section_name(self) -> str:
        """Bölüm adı (logging için)."""
        pass
