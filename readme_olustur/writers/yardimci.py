"""Yardımcı fonksiyonlar - Tüm writer'lar tarafından kullanılan ortak fonksiyonlar."""
import os
import re
import unicodedata
from typing import Optional, Any

import sys
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    TARIH, AY, YIL, DONEM, AD, HOCA_AKTIF_GOREVDE_MI,
    DOKUMANLAR_REPO_YOLU, VARSAYILAN_GITHUB_URL,
    LISANSUSTU, ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER
)

# Unvan öncelikleri
UNVAN_ONCELIKLERI = {"Prof.": 1, "Doç.": 2, "Dr.": 3}


def puanlari_yildiza_cevir(puan: float, max_yildiz_sayisi: int = 10) -> str:
    """
    Puanı yıldız gösterimine çevir.
    
    Args:
        puan: 0-100 arası puan
        max_yildiz_sayisi: Maksimum yıldız sayısı
    
    Returns:
        Yıldız string'i (örn: "★★★★★☆☆☆☆☆")
    """
    puan = round(puan / 10) * 10  # 10'a yuvarla
    dolu_yildiz_sayisi = int(puan // 10)
    bos_yildiz_sayisi = max_yildiz_sayisi - dolu_yildiz_sayisi
    return "★" * dolu_yildiz_sayisi + "☆" * bos_yildiz_sayisi


def baslik_linki_olustur(baslik: str) -> str:
    """
    Markdown başlık linkini oluştur.
    
    Args:
        baslik: Başlık metni
    
    Returns:
        Markdown link formatı (örn: "(#-baslik-adi)")
    """
    # Emoji ve özel karakterleri kaldır
    baslik = re.sub(r"[^\w\s-]", "", baslik)
    # Boşlukları '-' ile değiştir ve küçük harfe çevir
    baslik = baslik.replace(" ", "-").lower()
    return f"(#-{baslik})"


def gorustenTarihGetir(gorus: dict) -> str:
    """
    Görüşten tarih bilgisini formatla.
    
    Args:
        gorus: Görüş dict'i
    
    Returns:
        Formatlanmış tarih string'i
    """
    gorus_tarihi = ""
    if TARIH in gorus:
        ay = gorus.get(TARIH, {}).get(AY)
        ay = f"{ay}" if ay and ay > 9 else f"0{ay}" if ay else ""
        yil = gorus.get(TARIH, {}).get(YIL, "")
        if ay and yil:
            gorus_tarihi = f"ℹ️ Yorum **{ay}.{yil}** tarihinde yapılmıştır."
    return gorus_tarihi


def detay_etiketleri_olustur(baslik: str, girinti: str = "") -> tuple:
    """
    HTML details etiketlerini oluştur.
    
    Args:
        baslik: Detay başlığı
        girinti: Girinti string'i
    
    Returns:
        (açılış, kapanış) tuple'ı
    """
    acilis = f"{girinti}<details>\n"
    acilis += f"{girinti}<summary><b>{baslik}</b></summary>\n\n"
    kapanis = f"{girinti}</details>\n"
    return acilis, kapanis


def hoca_siralama_anahtari(hoca: dict) -> tuple:
    """
    Hoca sıralama anahtarı.
    
    Öncelik sırası:
    1. Aktif görevde olanlar
    2. Unvan sıralaması (Prof > Doç > Dr)
    3. Alfabetik ad
    
    Args:
        hoca: Hoca dict'i
    
    Returns:
        Sıralama tuple'ı
    """
    aktif_gorevde_mi = hoca.get(HOCA_AKTIF_GOREVDE_MI, True)
    aktiflik_onceligi = 0 if aktif_gorevde_mi else 1
    
    ad = hoca.get(AD, "")
    unvan = ad.split()[0] if ad else ""
    unvan_onceligi = UNVAN_ONCELIKLERI.get(unvan, 4)
    
    return (aktiflik_onceligi, unvan_onceligi, ad)


def ders_siralama_anahtari(ders: dict) -> str:
    """
    Ders sıralama anahtarı (alfabetik).
    
    Args:
        ders: Ders dict'i
    
    Returns:
        Sıralama string'i
    """
    return ders.get(AD, "Z").replace("İ", "i").lower()


def donem_siralamasi(donem_key: str) -> tuple:
    """
    Dönem sıralama anahtarı.
    
    Args:
        donem_key: Dönem anahtarı (örn: "1. Yıl - Güz")
    
    Returns:
        Sıralama tuple'ı
    """
    if donem_key == LISANSUSTU:
        return (1499, 1499)
    if donem_key == ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER:
        return (1500, 1500)
    if donem_key == "Mesleki Seçmeli":
        return (998, 998)
    
    try:
        yil, donem = donem_key.split(" - ")
        return (int(yil.split(".")[0]), 0 if donem == "Güz" else 1)
    except:
        return (999, 999)


def yerel_yoldan_github_linkine(
    klasor_yolu: Optional[str], 
    repo_url: str = VARSAYILAN_GITHUB_URL
) -> Optional[str]:
    """
    Yerel klasör yolunu GitHub URL'sine dönüştür.
    
    Args:
        klasor_yolu: Yerel klasör yolu
        repo_url: GitHub repo URL'si
    
    Returns:
        GitHub URL'si veya None
    """
    if klasor_yolu is None:
        return None
    
    klasor_yolu = klasor_yolu.replace(DOKUMANLAR_REPO_YOLU, "")
    klasor_yolu = os.path.normpath(klasor_yolu)
    klasor_yolu = klasor_yolu.replace("\\", "/")
    klasor_yolu = klasor_yolu.replace(" ", "%20")
    
    return f"{repo_url}/tree/main/{klasor_yolu}"


def sirali_ekle(liste: list, eleman: Any, anahtar_fonksiyonu: callable) -> None:
    """
    Elemanı sıralı listeye doğru konuma ekle.
    
    Args:
        liste: Hedef liste
        eleman: Eklenecek eleman
        anahtar_fonksiyonu: Sıralama anahtarı fonksiyonu
    """
    import bisect
    eleman_anahtar = anahtar_fonksiyonu(eleman)
    konum = bisect.bisect_left([anahtar_fonksiyonu(x) for x in liste], eleman_anahtar)
    liste.insert(konum, eleman)
