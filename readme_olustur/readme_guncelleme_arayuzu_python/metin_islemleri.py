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


# Türkçe bağlaçlar/edatlar - başlık dışındaki konumlarda küçük harfle yazılır.
BAGLAC_KUCUK = {"ve", "ile", "ya", "veya", "için", "da", "de", "ki"}


def _turkce_kucult(kelime):
    """Kelimeyi Türkçe kurallarına göre küçült ('İ' -> 'i', 'I' -> 'ı')."""
    return kelime.replace("İ", "i").replace("I", "ı").lower()


def _turkce_bas_harf_buyut(kelime):
    """Kelimenin ilk harfini Türkçe kurallarına göre büyüt ('i' -> 'İ', 'ı' -> 'I')."""
    if not kelime:
        return kelime
    ilk = kelime[0]
    if ilk == "i":
        ilk = "İ"
    elif ilk == "ı":
        ilk = "I"
    else:
        ilk = ilk.upper()
    return ilk + kelime[1:]


def ders_adi_normalize(ad):
    """
    Ders/hoca/başlık adını normalize et: bağlaçlar küçük harf, diğer kelimeler
    büyük harfle başlar (ilk kelime daima büyük).

    Örn: "Temel Hak Ve Sorumluluklar" -> "Temel Hak ve Sorumluluklar",
         "uygarlık tarihi" -> "Uygarlık Tarihi",
         "mehmet fatih amasyalı" -> "Mehmet Fatih Amasyalı".

    Args:
        ad: Ders/hoca/başlık adı

    Returns:
        Normalize edilmiş ad
    """
    if not ad:
        return ad
    kelimeler = ad.split(" ")
    for i, kelime in enumerate(kelimeler):
        # İlk kelime hariç bağlaçlar küçük harf (mevcut yazıma duyarsız), diğerleri büyük
        if i > 0 and _turkce_kucult(kelime) in BAGLAC_KUCUK:
            kelimeler[i] = _turkce_kucult(kelime)
        else:
            kelimeler[i] = _turkce_bas_harf_buyut(kelime)
    return " ".join(kelimeler)
