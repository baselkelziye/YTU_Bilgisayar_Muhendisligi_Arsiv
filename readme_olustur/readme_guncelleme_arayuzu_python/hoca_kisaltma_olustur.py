from degiskenler import *


def hoca_kisaltma_olustur(isim):
    """
    Bir isimden kısaltma oluşturur ve unvanları (Doç. Dr., Prof. Dr., Dr. vb.) atar.
    Örneğin "Prof. Dr. Ahmet Elbir" için "AEL", "Dr. Göksel Biricik" için "GB" döndürür.
    """
    if not isim:
        return None
    # Unvanları ve noktaları kaldır
    for unvan in unvanlar:
        isim = isim.replace(unvan, "")
    isim = isim.replace(".", "").strip()
    if "Elbir" in isim:
        return "AEL"
    if "Biricik" in isim:
        return "G1"
    # İsimleri ayır ve baş harfleri al
    parcalar = isim.split()
    if len(parcalar) == 1:  # Eğer sadece bir isim varsa
        return parcalar[0][:2].upper()
    else:
        # İlk iki ismin baş harflerini ve son ismin ilk harfini al
        kisaltma = "".join(parca[0].upper() for parca in parcalar[:-1])
        kisaltma += parcalar[-1][0].upper()
        if len(parcalar[-1]) == 1:  # Eğer son isim sadece bir harf ise (örneğin "M.")
            kisaltma += str(
                len(parcalar)
            )  # Sıra numarasını ekle (örneğin "MAG" yerine "MAG1")
        return kisaltma
