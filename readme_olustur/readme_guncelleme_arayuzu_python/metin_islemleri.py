from degiskenler import *


def kisaltMetin(metin, maks_uzunluk=70):
    """Metni belirtilen maksimum uzunlukta sınırlar ve gerekirse '...' ile kısaltır."""
    if len(metin) > maks_uzunluk:
        return metin[: maks_uzunluk - 3] + "..."
    return metin


def donem_sayisi_getir(donem):
    if donem == GUZ:
        return 1
    elif donem == BAHAR:
        return 2
    return 0


def donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU=".."):
    if donem is not None and donem.get(YIL, 0) != 0 and donem.get(DONEM, "") != "":
        return os.path.join(
            DOKUMANLAR_REPO_YOLU,
            f"{donem.get(YIL,1)}-{donem_sayisi_getir(donem.get(DONEM,GUZ))}",
        )
    if donem is not None and donem.get(DONEM_ADI, "") != "":
        return os.path.join(DOKUMANLAR_REPO_YOLU, donem.get(DONEM_ADI, ""))
    return os.path.join(DOKUMANLAR_REPO_YOLU, MESLEKI_SECMELI_1)
