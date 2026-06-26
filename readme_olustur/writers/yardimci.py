"""Yardımcı fonksiyonlar - Tüm writer'lar tarafından kullanılan ortak fonksiyonlar."""
import os
import re
import unicodedata
import urllib.parse
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
    Yerel klasör yolunu relative URL'ye dönüştür.
    
    Args:
        klasor_yolu: Yerel klasör yolu
        repo_url: GitHub repo URL'si
    
    Returns:
        Göreceli URL veya None
    """
    if klasor_yolu is None:
        return None
    
    klasor_yolu = klasor_yolu.replace(DOKUMANLAR_REPO_YOLU, "")
    klasor_yolu = os.path.normpath(klasor_yolu)
    klasor_yolu = klasor_yolu.replace("\\", "/")
    klasor_yolu = klasor_yolu.lstrip("/")

    # Her bir path bileşenini ayrı ayrı encode et (parantez, Türkçe karakter vb.)
    parcalar = klasor_yolu.split("/")
    encode_edilmis_parcalar = [
        urllib.parse.quote(p, safe="") for p in parcalar
    ]
    klasor_yolu = "/".join(encode_edilmis_parcalar)

    return f"./{klasor_yolu}"


# Ders/hoca/başlık adı normalizasyonu tek bir yerde (giriş arayüzü de aynı
# fonksiyonu kullanır): bağlaçlar küçük, diğer kelimeler büyük harfle başlar.
from metin_islemleri import (  # noqa: E402
    ders_adi_normalize, BAGLAC_KUCUK, _turkce_kucult, _turkce_bas_harf_buyut,
)


def _repo_goreceli_yol(klasor_yolu: str) -> str:
    """Klasörün repo köküne göre decode edilmiş göreceli yolu (örn: '1-2/Devre ...')."""
    yol = klasor_yolu.replace(DOKUMANLAR_REPO_YOLU, "")
    yol = os.path.normpath(yol).replace("\\", "/").lstrip("/")
    return "" if yol == "." else yol


def _karsilastirma_normu(metin: str) -> str:
    """Büyük/küçük harf ve Türkçe aksanlardan bağımsız karşılaştırma anahtarı."""
    return "".join(
        c for c in unicodedata.normalize("NFKD", metin.casefold())
        if not unicodedata.combining(c)
    )


_ust_dizinler_cache: Optional[set] = None


def _repo_ust_dizinleri() -> set:
    """Repo kökündeki üst düzey klasör adları (linkin repo köküne göreceli olup olmadığını ayırt etmek için)."""
    global _ust_dizinler_cache
    if _ust_dizinler_cache is None:
        try:
            _ust_dizinler_cache = {
                _karsilastirma_normu(ad) for ad in os.listdir(DOKUMANLAR_REPO_YOLU)
                if os.path.isdir(os.path.join(DOKUMANLAR_REPO_YOLU, ad))
            }
        except OSError:
            _ust_dizinler_cache = set()
    return _ust_dizinler_cache


def _goreceli_yol(hedef: str, base_rel: str) -> str:
    """
    `hedef` (repo köküne göreceli) yolunu, `base_rel` klasörüne göreceli hale getir.

    `os.path.relpath`'in aksine ortak önek karşılaştırması harf/aksan duyarsızdır;
    böylece JSON yolundaki harf büyüklüğü disk ile farklı olsa bile ("İçin" vs
    "için") doğru sayıda '../' üretilir ve eşleşen önek atılır.
    """
    base_parcalar = [p for p in base_rel.split("/") if p]
    hedef_parcalar = [p for p in hedef.split("/") if p]
    ortak = 0
    while (ortak < len(base_parcalar) and ortak < len(hedef_parcalar) and
           _karsilastirma_normu(base_parcalar[ortak]) == _karsilastirma_normu(hedef_parcalar[ortak])):
        ortak += 1
    yukari = [".."] * (len(base_parcalar) - ortak)
    asagi = hedef_parcalar[ortak:]
    parcalar = yukari + asagi
    if not parcalar:
        return "./"
    if parcalar[0] == "..":
        return "/".join(parcalar)
    return "./" + "/".join(parcalar)


def _disk_yol_duzelt(base_klasor_yolu: str, goreceli: str) -> str:
    """
    Göreceli yolun bileşenlerini gerçek diskteki klasör/dosya adlarıyla düzelt.

    JSON yolundaki harf büyüklüğü disk ile farklı olsa bile ("İçin" -> "için")
    diskte eşleşen ada göre düzeltir. Eşleşme bulunamayan ilk bileşenden sonrası
    (ör. gerçekte var olmayan bir klasör adı) olduğu gibi bırakılır.
    """
    suanki = base_klasor_yolu
    sonuc = []
    bozuk = False
    for parca in goreceli.split("/"):
        if parca in ("..", "."):
            sonuc.append(parca)
            if parca == "..":
                suanki = os.path.dirname(suanki)
            continue
        if not bozuk:
            try:
                eslesen = next(
                    (ad for ad in os.listdir(suanki)
                     if _karsilastirma_normu(ad) == _karsilastirma_normu(parca)),
                    None,
                )
            except OSError:
                eslesen = None
            if eslesen is not None:
                sonuc.append(eslesen)
                suanki = os.path.join(suanki, eslesen)
                continue
            bozuk = True
        sonuc.append(parca)
    return "/".join(sonuc)


def kaynak_linklerini_goreceli_yap(
    metin: str,
    base_klasor_yolu: Optional[str],
    ders_klasor_yolu: Optional[str] = None,
) -> str:
    """
    Metindeki markdown linklerini, README'nin bulunduğu klasöre göreceli yap.

    `dersler.json` içindeki kaynak linkleri iki biçimde tutulur:
      1. Repo köküne göreceli (ilk bileşeni repo kökündeki bir üst klasör olanlar,
         örn `./3-1/.../altyazilar/`). Ana README için doğrudur.
      2. Dersin kendi klasörüne göreceli (örn `./ders_kayitlari/`,
         `./alt seviye programlama/ders_kayitlari/`).

    Ders README'si dersin kendi klasöründe olduğundan (2) tipi linkler olduğu gibi
    doğrudur ve dokunulmaz. Dönem README'si ise daha üstte (dönem klasöründe)
    olduğundan (2) tipi linkler, dersin gerçekte bulunduğu klasör (`ders_klasor_yolu`)
    üzerinden çözülüp dönem klasörüne göre yeniden yazılır. Böylece bir ders başka
    bir dönemin klasöründe duruyor olsa bile (örn Mesleki Seçmeli olarak listelenen
    "Ağ Teknolojileri"nin `3-2/.../ağ teknolojileri` altında olması) link gerçek
    konuma '../' ile doğru şekilde bağlanır.

    Args:
        metin: İçinde markdown link(ler)i olabilen serbest metin
        base_klasor_yolu: README'nin bulunduğu klasörün yerel yolu
        ders_klasor_yolu: Dersin gerçekte bulunduğu klasör. Verilmezse base ile aynı
            kabul edilir (ders README'si durumu -> ders klasörüne göreceli linkler
            değişmez).

    Returns:
        Linkleri göreceli hale getirilmiş metin
    """
    if not base_klasor_yolu:
        return metin
    base_rel = _repo_goreceli_yol(base_klasor_yolu)
    if not base_rel:
        return metin
    ders_rel = _repo_goreceli_yol(ders_klasor_yolu) if ders_klasor_yolu else base_rel
    ust_dizinler = _repo_ust_dizinleri()

    def _degistir(eslesme: "re.Match") -> str:
        url = eslesme.group(1)
        if not url.startswith("./"):
            return eslesme.group(0)
        hedef = urllib.parse.unquote(url[2:])
        son_egik = "/" if hedef.endswith("/") else ""
        hedef = hedef.rstrip("/")
        ilk = hedef.split("/")[0] if hedef else ""
        if ilk and _karsilastirma_normu(ilk) in ust_dizinler:
            repo_rel = hedef  # zaten repo köküne göreceli
        else:
            # Dersin kendi klasörüne göreceli link
            if ders_rel == base_rel:
                return eslesme.group(0)  # ders README'si: olduğu gibi doğru
            repo_rel = f"{ders_rel}/{hedef}" if hedef else ders_rel
        goreceli = _goreceli_yol(repo_rel, base_rel)
        goreceli = _disk_yol_duzelt(base_klasor_yolu, goreceli)
        yeni = "/".join(urllib.parse.quote(p, safe="") for p in goreceli.split("/"))
        return f"]({yeni}{son_egik})"

    return re.sub(r"\]\(([^)]+)\)", _degistir, metin)


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
