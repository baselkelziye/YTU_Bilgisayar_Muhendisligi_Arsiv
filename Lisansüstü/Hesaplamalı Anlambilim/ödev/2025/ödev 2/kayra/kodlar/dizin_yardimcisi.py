import os
import pandas as pd
import json
from enum import Enum

class ShotType(Enum):
    ZERO_SHOT = "zero_shot"
    THREE_SHOT = "3_shot"
    FIVE_SHOT = "5_shot"

def kok_dizini_al() -> str:
    """
    Bu fonksiyon dosyanın bulunduğu dizini döndürür.
    """
    return os.path.dirname(os.path.abspath(__file__))

def veri_kumesi_dizin_al() -> str:
    """
    Bu fonksiyon veri kümelerinin bulunduğu dizini döndürür.
    """
    return os.path.join(kok_dizini_al(), "veri_kumeleri")

def json_oku(dosya_yolu: str) -> dict:
    """
    JSON dosyasını okur ve içeriğini döndürür.
    
    Argümanlar:
        dosya_yolu: Okunacak JSON dosyasının yolu
        
    Dönüş:
        dosya_icerigi: JSON dosyasının içeriği (dict)
    """
    # Dosya var mı kontrol et
    if not os.path.exists(dosya_yolu):
        return {}
    
    # JSON dosyasını oku
    with open(dosya_yolu, "r", encoding="utf-8") as f:
        dosya_icerigi = json.load(f)
    
    return dosya_icerigi

def jsona_yaz(dosya_yolu: str, icerik: dict) -> None:
    """
    JSON dosyasına verilen içeriği yazar.
    
    Argümanlar:
        dosya_yolu: Yazılacak JSON dosyasının yolu
        icerik: JSON dosyasına yazılacak içerik (dict)
    """
    # JSON dosyasına yaz
    with open(dosya_yolu, "w", encoding="utf-8") as f:
        json.dump(icerik, f, indent=4)

def get_shot_file_dir(shot_sonuc_dizini_yolu: str = "shot_sonuclari") -> str:
    """
    Argümanlar:
        shot_sonuc_dizini_yolu: Shot sonuçlarının kaydedileceği klasör yolu (varsayılan: "shot_sonuclari")
    Returns:
        dosya_yolu: Shot sonuçlarının kaydedileceği klasörün yolu
    """
    
    kok_dizin = kok_dizini_al()
    sonuc_klasor_yolu = os.path.join(kok_dizin, shot_sonuc_dizini_yolu)
    return sonuc_klasor_yolu
def get_shot_file_path(model_dosya_adi_on_eki: str, veri_kumesi_adi: str, shot_sonuc_dizini_yolu: str = "shot_sonuclari") -> str:
    """
    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi: Veri kümesi adı
        shot_sonuc_dizini_yolu: Shot sonuçlarının kaydedileceği klasör yolu (varsayılan: "shot_sonuclari")
    Returns:
        dosya_yolu: Shot sonuçlarının kaydedileceği JSON dosyasının yolu
    """

    kok_dizin = kok_dizini_al()
    sonuc_klasor_yolu = get_shot_file_dir(shot_sonuc_dizini_yolu)
    shot_dosya_adi = f"{veri_kumesi_adi}_{model_dosya_adi_on_eki}_shot_sonuclari.json"
    # Tam dosya yolunu oluştur
    dosya_yolu = os.path.join(sonuc_klasor_yolu, shot_dosya_adi) 
    return dosya_yolu
def shot_sonucu_mevcut_mu(model_dosya_adi_on_eki: str, veri_kumesi_adi: str, shot_tipi: ShotType, klasor_yolu: str="shot_sonuclari") -> bool:
    """
    Shot sonuçlarının mevcut olup olmadığını kontrol eder.
    
    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi: Veri kümesi adı
        shot_tipi: Shot tipi (örneğin, "zero-shot" veya "few-shot")
        klasor_yolu: Shot sonuçlarının bulunduğu klasör yolu (varsayılan: "shot_sonuclari")
        
    Dönüş:
        mevcut_mu: Shot sonuçları mevcutsa True, aksi halde False
    """
    
    # Tam dosya yolunu oluştur
    dosya_yolu = get_shot_file_path(model_dosya_adi_on_eki, veri_kumesi_adi, klasor_yolu)
    
    varolan_shot_sonuclari = json_oku(dosya_yolu)
    return shot_tipi.value in varolan_shot_sonuclari
def shot_sonuc_oku(model_dosya_adi_on_eki: str, veri_kumesi_adi: str, klasor_yolu: str="shot_sonuclari") -> dict:
    """
    Shot sonuçlarını okur ve döndürür.
    
    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi: Veri kümesi adı
        klasor_yolu: Shot sonuçlarının bulunduğu klasör yolu (varsayılan: "shot_sonuclari")
    
    Dönüş:
        shot_sonuclari: Shot sonuçları listesi
    """
    
    # Tam dosya yolunu oluştur
    dosya_yolu = get_shot_file_path(model_dosya_adi_on_eki, veri_kumesi_adi, klasor_yolu)
    
    # JSON dosyasını oku
    shot_sonuclari = json_oku(dosya_yolu)
    
    return shot_sonuclari
def shot_sonucu_kaydet(shot_sonucu: dict, shot_tipi: ShotType, model_dosya_adi_on_eki: str,
                       veri_kumesi_adi: str, model_adi: str, shot_sonuc_dizini_yolu: str="shot_sonuclari") -> None:
    """
    Shot sonuçlarını JSON dosyası olarak kaydeder.
    
    Argümanlar:
        shot_sonucu: Kaydedilecek shot sonuçları
        model_dosya_adi_on_eki: Model adı
        shot_tipi: Shot tipi
        veri_kumesi_adi: Veri kümesi adı
        model_adi: Model adı
        shot_sonuc_dizini_yolu: Shot sonuçlarının kaydedileceği klasör yolu (varsayılan: "shot_sonuclari")
    """
    
    # Tam dosya yolunu oluştur
    dosya_yolu = get_shot_file_path(model_dosya_adi_on_eki, veri_kumesi_adi, shot_sonuc_dizini_yolu)
    # dizin yoksa oluştur
    if not os.path.exists(os.path.dirname(dosya_yolu)):
        os.makedirs(os.path.dirname(dosya_yolu))
    # dosya varsa varolan içeriği oku
    varolan_shot_sonuclari = json_oku(dosya_yolu)
    varolan_shot_sonuclari["model_name"] = model_adi
    varolan_shot_sonuclari[shot_tipi.value] = shot_sonucu

    # JSON dosyasına yaz
    jsona_yaz(dosya_yolu, varolan_shot_sonuclari)
    
    print(f"'{os.path.basename(dosya_yolu)}' dosyası başarıyla kaydedildi.")


def veri_kumesi_adlari_listele(klasor_yolu: str) -> list:
    """
    Verilen klasördeki veri kümesi adlarını liste şeklinde döndürür.
    
    Parametreler:
        klasor_yolu: Veri kümelerinin bulunduğu klasörün yolu
        
    Dönüş:
        veri_kumesi_adlari: Veri kümesi adlarının listesi (tekrarsız)
    """
    # Dizindeki tüm dosyaları listele
    dosyalar = os.listdir(klasor_yolu)
    
    # Veri kümesi adlarını saklamak için boş küme (tekrarları önlemek için)
    veri_kumesi_adlari_kumesi = set()
    
    # Her dosyayı kontrol et
    for dosya in dosyalar:
        if dosya.endswith('.csv'):
            # "_egitim.csv" veya "_sinama.csv" son eklerini çıkar
            if "_egitim.csv" in dosya:
                veri_kumesi_adi = dosya.replace("_egitim.csv", "")
                veri_kumesi_adlari_kumesi.add(veri_kumesi_adi)
            elif "_sinama.csv" in dosya:
                veri_kumesi_adi = dosya.replace("_sinama.csv", "")
                veri_kumesi_adlari_kumesi.add(veri_kumesi_adi)
    
    # Kümeyi listeye dönüştür
    veri_kumesi_adlari = list(veri_kumesi_adlari_kumesi)
    
    return veri_kumesi_adlari

def veri_kumesi_yukle(veri_kumesi_adi: str, egitim_kumesi_mi: bool, klasor_yolu: str="veri_kumeleri") -> pd.DataFrame:
    """
    Belirtilen veri kümesini DataFrame olarak yükler.
    
    Parametreler:
        veri_kumesi_adi: Yüklenecek veri kümesinin adı
        egitim_kumesi_mi: Eğitim kümesi ise True, sınama kümesi ise False
        klasor_yolu: Veri kümelerinin bulunduğu klasörün yolu (varsayılan: "veri_kumeleri")
        
    Dönüş:
        df: Yüklenen veri kümesi DataFrame'i
    """
    # Dosya adını oluştur
    if egitim_kumesi_mi:
        dosya_adi = f"{veri_kumesi_adi}_egitim.csv"
    else:
        dosya_adi = f"{veri_kumesi_adi}_sinama.csv"
    
    # Tam dosya yolunu oluştur
    dosya_yolu = os.path.join(klasor_yolu, dosya_adi)
    
    # Dosyanın varlığını kontrol et
    if not os.path.exists(dosya_yolu):
        raise FileNotFoundError(f"Dosya bulunamadı: {dosya_yolu}")
    
    # CSV dosyasını yükle
    df = pd.read_csv(dosya_yolu)
    
    print(f"'{dosya_adi}' dosyası başarıyla yüklendi. Boyut: {df.shape}")
    
    return df

def gomme_dizin_adi_al() -> str:
    """
    Bu fonksiyon gomme dizin adını döndürür.
    """
    return "gomme"

def gomme_dizini_al() -> str:
    """
    Bu fonksiyon gomme dizinini döndürür.
    """
    return os.path.join(kok_dizini_al(), gomme_dizin_adi_al())

def gomme_sonucu_dosya_adi_al(model_dosya_adi_on_eki: str, veri_kumesi_adi_on_eki: str) -> str:
    """
    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi_on_eki: Veri kümesi adı
    Returns:
        gomme_dosya_adi: Gomme sonuçlarının kaydedileceği JSON dosyasının adı
    """

    gomme_dosya_adi = f"{veri_kumesi_adi_on_eki}_{model_dosya_adi_on_eki}_gomme_sonucu.json"
    return gomme_dosya_adi


def gomme_sonucu_yolu_al(model_dosya_adi_on_eki: str, veri_kumesi_adi_on_eki: str) -> str:
    """
    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi_on_eki: Veri kümesi adı
    Returns:
        dosya_yolu: Gomme sonuçlarının kaydedileceği JSON dosyasının yolu
    """
    
    kok_dizin = kok_dizini_al()
    sonuc_klasor_yolu = os.path.join(kok_dizin, gomme_dizin_adi_al())
    gomme_dosya_adi = gomme_sonucu_dosya_adi_al(model_dosya_adi_on_eki, veri_kumesi_adi_on_eki)
    # Tam dosya yolunu oluştur
    dosya_yolu = os.path.join(sonuc_klasor_yolu, gomme_dosya_adi) 
    return dosya_yolu

def gomme_sonucu_ekle(gomme_sonucu: dict, model_dosya_adi_on_eki: str, veri_kumesi_adi_on_eki: str) -> None:
    """
    Gömme sonucunu belirtilen dosyaya JSONL formatında kaydeder.
    Eğer dosya zaten mevcutsa, yeni veriyi sona ekler.

    Argümanlar:
        gomme_sonucu: Kaydedilecek gömme sonucu (dictionary formatında)
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi_on_eki: Veri kümesi adı
    """
    # Tam dosya yolunu oluştur
    dosya_yolu = gomme_sonucu_yolu_al(model_dosya_adi_on_eki, veri_kumesi_adi_on_eki)
    
    # Dizin yoksa oluştur
    gomme_dizini = os.path.dirname(dosya_yolu)
    if not os.path.exists(gomme_dizini):
        os.makedirs(gomme_dizini)
    
    # JSON satırını oluştur ve dosyaya ekle
    with open(dosya_yolu, 'a', encoding='utf-8') as f:
        # Her satıra bir JSON nesnesi şeklinde ekle (JSONL formatı)
        json_satir = json.dumps(gomme_sonucu, ensure_ascii=False)
        f.write(json_satir + '\n')


def gomme_sonucu_mevcut_mu(model_dosya_adi_on_eki: str, veri_kumesi_adi_on_eki: str) -> bool:
    """
    Gömme sonuçlarının mevcut olup olmadığını kontrol eder.

    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi_on_eki: Veri kümesi adı
    
    Dönüş:
        mevcut_mu: Gömme sonuçları mevcutsa True, aksi halde False
    """
    
    # Tam dosya yolunu oluştur
    dosya_yolu = gomme_sonucu_yolu_al(model_dosya_adi_on_eki, veri_kumesi_adi_on_eki)
    
    return os.path.exists(dosya_yolu)

def hesaplanan_gomme_sayisi_al(model_dosya_adi_on_eki: str, veri_kumesi_adi_on_eki: str) -> int:
    """
    Gömme sonuçlarının mevcut olup olmadığını kontrol eder ve mevcutsa hesaplanan gömme sayısını döndürür.

    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi_on_eki: Veri kümesi adı
    
    Dönüş:
        hesaplanan_gomme_sayisi: Hesaplanan gömme sayısı
    """
    
    # Gömme sonucu mevcut değilse 0 döndür
    if not gomme_sonucu_mevcut_mu(model_dosya_adi_on_eki, veri_kumesi_adi_on_eki):
        return 0
    
    # Tam dosya yolunu oluştur
    dosya_yolu = gomme_sonucu_yolu_al(model_dosya_adi_on_eki, veri_kumesi_adi_on_eki)
    
    # Dosyayı aç ve satır sayısını döndür
    with open(dosya_yolu, 'r', encoding='utf-8') as f:
        satirlar = f.readlines()
    
    return len(satirlar)
def gomme_bilgisi_oku(model_dosya_adi_on_eki: str, veri_kumesi_adi_on_eki: str) -> list:
    """
    Gömme sonuçlarını okur ve döndürür.

    Argümanlar:
        model_dosya_adi_on_eki: Model adı
        veri_kumesi_adi_on_eki: Veri kümesi adı
    
    Dönüş:
        gomme_sonuclari: Gömme sonuçları listesi
    """
    
    # Tam dosya yolunu oluştur
    dosya_yolu = gomme_sonucu_yolu_al(model_dosya_adi_on_eki, veri_kumesi_adi_on_eki)
    if not os.path.exists(dosya_yolu):
        return []
    # Dosyayı aç ve satırları oku
    with open(dosya_yolu, 'r', encoding='utf-8') as f:
        satirlar = f.readlines()
    
    # Her satırı JSON nesnesine dönüştür
    gomme_sonuclari = [json.loads(satir) for satir in satirlar]
    
    return gomme_sonuclari
def gomme_basarim_dizin_adi_al() -> str:
    """
    Bu fonksiyon gomme doğruluk dizinini döndürür.
    """
    return "gomme_basarim"

def gomme_basarim_dizini_al() -> str:
    """
    Bu fonksiyon gomme doğruluk dizinini döndürür.
    """
    return os.path.join(kok_dizini_al(), gomme_basarim_dizin_adi_al())

def gomme_basarim_dosya_adi_al() -> str:
    """
    Bu fonksiyon gomme doğruluk dosya adını döndürür.
    """
    return "gomme_basarim_sonuclari.json"
def gomme_basarim_dosya_yolu_al() -> str:
    """
    Bu fonksiyon gomme doğruluk dosya yolunu döndürür.
    """
    dizin = gomme_basarim_dizini_al()
    dosya_adi = gomme_basarim_dosya_adi_al()
    return os.path.join(dizin, dosya_adi)


def gomme_basarimi_var_mi(ml_modeli_adi: str, gomme_modeli_adi: str, veri_kumesi_adi: str) -> bool:
    """
    Gömme doğruluk sonucunun mevcut olup olmadığını kontrol eder.

    Argümanlar:
        ml_modeli_adi: ML modeli adı
        gomme_modeli_adi: Gömme modeli adı
        veri_kumesi_adi: Veri kümesi adı
    
    Dönüş:
        mevcut_mu: Gömme doğruluk sonucu mevcutsa True, aksi halde False
    """
    gomme_basarimlari = gomme_basarimlari_oku()
    if veri_kumesi_adi not in gomme_basarimlari:
        return False
    if gomme_modeli_adi not in gomme_basarimlari[veri_kumesi_adi]:
        return False
    if ml_modeli_adi not in gomme_basarimlari[veri_kumesi_adi][gomme_modeli_adi]:
        return False
    if len(gomme_basarimlari[veri_kumesi_adi][gomme_modeli_adi][ml_modeli_adi]) == 0:
        return False
    return True
    

def gomme_basarimi_kaydet(dogruluk_sonucu: dict, ml_modeli_adi: str, gomme_modeli_adi: str, veri_kumesi_adi: str):
    """
    Gömme doğruluk sonucunu belirtilen dosyaya JSON biçiminde kaydeder.
    Eğer dosya zaten mevcutsa, yeni veriyi sona ekler.

    Argümanlar:
        dogruluk_sonucu: Gömme doğruluk sonucu
        ml_modeli_adi: ML modeli adı
        gomme_modeli_adi: Gömme modeli adı
        veri_kumesi_adi: Veri kümesi adı
    """
    gomme_basarimlari = gomme_basarimi_ekle(dogruluk_sonucu, ml_modeli_adi, gomme_modeli_adi, veri_kumesi_adi)
    gomme_basarimi_yaz(gomme_basarimlari)

def gomme_basarimi_ekle(dogruluk_sonucu: dict, ml_modeli_adi: str, gomme_modeli_adi: str, veri_kumesi_adi: str) -> dict:
    """
    Gömme doğruluk sonucunu belirtilen dosyaya JSON biçiminde ekler.

    Argümanlar:
        dogruluk_sonucu: Gömme doğruluk sonucu
        ml_modeli_adi: ML modeli adı
        gomme_modeli_adi: Gömme modeli adı
        veri_kumesi_adi: Veri kümesi adı
    """
    gomme_basarimlari = gomme_basarimlari_oku()
    if veri_kumesi_adi not in gomme_basarimlari:
        gomme_basarimlari[veri_kumesi_adi] = {}
    if gomme_modeli_adi not in gomme_basarimlari[veri_kumesi_adi]:
        gomme_basarimlari[veri_kumesi_adi][gomme_modeli_adi] = {}
    gomme_basarimlari[veri_kumesi_adi][gomme_modeli_adi][ml_modeli_adi] = dogruluk_sonucu
    return gomme_basarimlari


def gomme_basarimlari_oku() -> dict:
    """
    Gömme doğruluk sonuçlarını okur ve döndürür.

    Dönüş:
        dogruluk_sonuclari: Gömme doğruluk sonuçları
    """
    # Tam dosya yolunu oluştur
    dosya_yolu = gomme_basarim_dosya_yolu_al()
    
    # JSON dosyasını oku
    dogruluk_sonuclari = json_oku(dosya_yolu)
    
    return dogruluk_sonuclari
def gomme_basarimi_yaz(dogruluk_sonuclari: dict):
    """
    Gömme doğruluk sonuçlarını belirtilen dosyaya JSON biçiminde kaydeder.

    Argümanlar:
        dogruluk_sonuclari: Gömme doğruluk sonuçları
    """
    # Tam dosya yolunu oluştur
    dosya_yolu = gomme_basarim_dosya_yolu_al()
    if not os.path.exists(os.path.dirname(dosya_yolu)):
        os.makedirs(os.path.dirname(dosya_yolu))
    # JSON dosyasına yaz
    jsona_yaz(dosya_yolu, dogruluk_sonuclari)

def get_dogruluk_png_yolu(veri_kumesi_adi: str) -> str:
    """
    Gömme doğruluk grafiğinin dosya yolunu döndürür.

    Argümanlar:
        veri_kumesi_adi: Veri kümesi adı
    
    Dönüş:
        dosya_yolu: Gömme doğruluk grafiğinin dosya yolu
    """
    gomme_dogruluk_dizini = gomme_basarim_dizini_al()
    return os.path.join(gomme_dogruluk_dizini, f"{veri_kumesi_adi}_dogruluk.png")
def get_f1_score_png_yolu(veri_kumesi_adi: str) -> str:
    """
    Gömme F1 skoru grafiğinin dosya yolunu döndürür.

    Argümanlar:
        veri_kumesi_adi: Veri kümesi adı
    
    Dönüş:
        dosya_yolu: Gömme F1 skoru grafiğinin dosya yolu
    """
    gomme_dogruluk_dizini = gomme_basarim_dizini_al()
    return os.path.join(gomme_dogruluk_dizini, f"{veri_kumesi_adi}_f1_skoru.png")
def get_precision_png_yolu(veri_kumesi_adi: str) -> str:
    """
    Gömme precision grafiğinin dosya yolunu döndürür.

    Argümanlar:
        veri_kumesi_adi: Veri kümesi adı
    
    Dönüş:
        dosya_yolu: Gömme precision grafiğinin dosya yolu
    """
    gomme_dogruluk_dizini = gomme_basarim_dizini_al()
    return os.path.join(gomme_dogruluk_dizini, f"{veri_kumesi_adi}_precision.png")
def get_recall_png_yolu(veri_kumesi_adi: str) -> str:
    """
    Gömme recall grafiğinin dosya yolunu döndürür.

    Argümanlar:
        veri_kumesi_adi: Veri kümesi adı

    Dönüş:
        dosya_yolu: Gömme recall grafiğinin dosya yolu
    """
    gomme_dogruluk_dizini = gomme_basarim_dizini_al()
    return os.path.join(gomme_dogruluk_dizini, f"{veri_kumesi_adi}_recall.png")

def get_confusion_matrix_dizini() -> str:
    """
    Gömme confusion matrix grafiğinin dizinini döndürür.

    Dönüş:
        dosya_yolu: Gömme confusion matrix grafiğinin dizini
    """
    return os.path.join(gomme_basarim_dizini_al(), "confusion_matrix")
def get_confusion_matrix_png_yolu(veri_kumesi_adi: str, model_dosya_adi_on_eki: str, ml_model_adi: str) -> str:
    """
    Gömme confusion matrix grafiğinin dosya yolunu döndürür.

    Argümanlar:
        veri_kumesi_adi: Veri kümesi adı
        model_dosya_adi_on_eki: Gömme modeli adı
        ml_model_adi: ML modeli adı
    
    Dönüş:
        dosya_yolu: Gömme confusion matrix grafiğinin dosya yolu
    """
    dizin = get_confusion_matrix_dizini()
    if not os.path.exists(dizin):
        os.makedirs(dizin)
    return os.path.join(dizin, f"{veri_kumesi_adi}_{model_dosya_adi_on_eki}_{ml_model_adi}_confusion_matrix.png")
