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


def elideText(text, max_length=40):
    if text is None:
        return ""
    if len(text) <= max_length:
        return text
    else:
        keep_length = max_length - 3  # 3 karakter "..." için ayrıldı
        prefix_length = keep_length // 2
        suffix_length = keep_length - prefix_length
        return text[:prefix_length] + "..." + text[-suffix_length:]



def donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU=".."):
    if donem is not None and donem.get(YIL, 0) != 0 and donem.get(DONEM, "") != "":
        return os.path.join(
            DOKUMANLAR_REPO_YOLU,
            f"{donem.get(YIL,1)}-{donem_sayisi_getir(donem.get(DONEM,GUZ))}",
        )
    if donem is not None and donem.get(DONEM_ADI, "") != "":
        return os.path.join(DOKUMANLAR_REPO_YOLU, donem.get(DONEM_ADI, ""))
    return os.path.join(DOKUMANLAR_REPO_YOLU, MESLEKI_SECMELI_1)
