def kisaltMetin(metin, maks_uzunluk=70):
        """Metni belirtilen maksimum uzunlukta sınırlar ve gerekirse '...' ile kısaltır."""
        if len(metin) > maks_uzunluk:
            return metin[:maks_uzunluk - 3] + '...'
        return metin