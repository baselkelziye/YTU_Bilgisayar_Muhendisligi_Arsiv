"""
Undo Manager - Silme işlemlerini geri alma yöneticisi

Bu modül, silinen öğelerin geri alınmasını sağlar.
Ctrl+Z ile son silinen öğe geri eklenir.
"""

import copy


class UndoManager:
    """Her pencere için silme işlemlerini geri alma yöneticisi"""
    
    def __init__(self, max_undo_count=10):
        """
        Args:
            max_undo_count: Maksimum geri alma sayısı
        """
        self.deleted_items = []  # [(index, item_data, item_type), ...]
        self.max_undo_count = max_undo_count
    
    def push_deleted(self, index, item_data, item_type="item"):
        """
        Silinen öğeyi kaydet
        
        Args:
            index: Öğenin silindiği index pozisyonu
            item_data: Silinen öğenin verisi (deep copy yapılır)
            item_type: Öğe tipi (opsiyonel, loglama için)
        """
        # Deep copy yaparak orijinal verinin değişmemesini sağla
        saved_data = copy.deepcopy(item_data)
        self.deleted_items.append((index, saved_data, item_type))
        
        # Maksimum sayıyı aşarsa en eskiyi sil
        if len(self.deleted_items) > self.max_undo_count:
            self.deleted_items.pop(0)
    
    def pop_deleted(self):
        """
        Son silinen öğeyi al
        
        Returns:
            tuple: (index, item_data, item_type) veya None
        """
        if self.deleted_items:
            return self.deleted_items.pop()
        return None
    
    def can_undo(self):
        """
        Geri alınacak öğe var mı?
        
        Returns:
            bool: Geri alınabilecek öğe varsa True
        """
        return len(self.deleted_items) > 0
    
    def clear(self):
        """Undo geçmişini temizle"""
        self.deleted_items.clear()
    
    def get_undo_count(self):
        """
        Geri alınabilecek öğe sayısı
        
        Returns:
            int: Öğe sayısı
        """
        return len(self.deleted_items)
