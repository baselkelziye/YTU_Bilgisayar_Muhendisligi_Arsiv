"""Klasör yapısını cache'leyen modül - Performans optimizasyonu için."""
import os
import difflib
from typing import Optional


class FolderCache:
    """
    Klasör yapısını bir kez tarayıp cache'leyen sınıf.
    
    Her ders için os.walk() çağırmak yerine, başlangıçta tüm klasör yapısını
    indexleyip sonraki aramalarda cache'den döndürür.
    
    Performans: O(n × m) -> O(m + n)
    """
    
    def __init__(self, base_path: str, max_depth: int = 4):
        """
        Args:
            base_path: Taranacak ana dizin yolu
            max_depth: Maksimum derinlik (varsayılan: 4)
        """
        self._base_path = base_path
        self._max_depth = max_depth
        self._cache: dict[str, str] = {}  # normalized_name -> full_path
        self._cache_by_basename: dict[str, list[str]] = {}  # basename_lower -> [full_paths]
        self._build_cache()
    
    def _build_cache(self) -> None:
        """Tek seferde tüm klasörleri indexle."""
        if not os.path.exists(self._base_path):
            return
            
        for root, dirs, _ in os.walk(self._base_path):
            # Derinlik kontrolü
            relative_path = root.replace(self._base_path, "").lstrip(os.sep)
            depth = len(relative_path.split(os.sep)) if relative_path else 0
            
            if depth >= self._max_depth:
                dirs[:] = []  # Derine inmeyi durdur
                continue
            
            for d in dirs:
                if d.startswith('.'):  # Gizli klasörleri atla
                    continue
                    
                full_path = os.path.join(root, d)
                basename_lower = d.lower()
                
                # Ana cache
                self._cache[basename_lower] = full_path
                
                # Basename bazlı liste (aynı isimde birden fazla klasör olabilir)
                if basename_lower not in self._cache_by_basename:
                    self._cache_by_basename[basename_lower] = []
                self._cache_by_basename[basename_lower].append(full_path)
    
    @staticmethod
    def _similarity_score(str1: str, str2: str) -> float:
        """İki string arasındaki benzerlik skorunu hesapla."""
        return difflib.SequenceMatcher(None, str1, str2).ratio() * 100
    
    def _check_numeric_conflict(self, search_name: str, folder_name: str) -> bool:
        """
        Matematik 1 için Matematik 2'yi döndürmemek gibi numerik çakışmaları kontrol et.
        
        Returns:
            True: Çakışma var, bu klasör kullanılmamalı
            False: Çakışma yok
        """
        has_1_in_search = "1" in search_name
        has_2_in_search = "2" in search_name
        has_1_in_folder = "1" in folder_name
        has_2_in_folder = "2" in folder_name
        
        if (has_1_in_search and has_2_in_folder) or (has_2_in_search and has_1_in_folder):
            return True
        return False
    
    def find_best_match(self, name: str, threshold: float = 88.0) -> Optional[str]:
        """
        Cache üzerinden en iyi eşleşmeyi bul.
        
        Args:
            name: Aranacak klasör adı
            threshold: Minimum benzerlik skoru (varsayılan: 88%)
        
        Returns:
            Bulunan klasörün tam yolu veya None
        """
        if not name:
            return None
            
        normalized = name.lower()
        
        # 1. Önce exact match dene
        if normalized in self._cache:
            return self._cache[normalized]
        
        # 2. Fuzzy match
        best_score = 0.0
        best_path: Optional[str] = None
        
        for cached_name, paths in self._cache_by_basename.items():
            # Numerik çakışma kontrolü
            if self._check_numeric_conflict(normalized, cached_name):
                continue
            
            score = self._similarity_score(normalized, cached_name)
            
            if score > best_score:
                best_score = score
                # En sığ olanı tercih et (daha az path segment)
                best_path = min(paths, key=lambda p: p.count(os.sep))
        
        # Threshold kontrolü
        if best_score >= threshold:
            # Projesi olmayan klasörlerin path segmenti kontrolü
            if best_path and len(best_path.split(os.sep)) < 3 and "Projesi" not in best_path:
                return None
            return best_path
        
        return None
    
    def get_all_folders(self) -> dict[str, str]:
        """Tüm cache'lenmiş klasörleri döndür."""
        return self._cache.copy()
    
    @property
    def folder_count(self) -> int:
        """Cache'deki toplam klasör sayısı."""
        return len(self._cache)
