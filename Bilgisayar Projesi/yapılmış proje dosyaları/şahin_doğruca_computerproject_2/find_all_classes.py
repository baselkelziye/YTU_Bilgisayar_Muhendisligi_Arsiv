import json
from pathlib import Path
from tqdm import tqdm
import re  # Kopya desenini bulmak için eklendi

# --- AYAR: JSON DOSYALARININ OLDUĞU KLASÖR ---
JSON_DIR = Path("./data/temp_v2/JSON")
# ---------------------------------------------------


def find_unique_labels_filtered(json_dir):
    """
    Belirtilen klasördeki .json dosyalarını tarar ve benzersiz 'label' isimlerini bulur.
    'dosya(1).json' gibi kopya dosyaları GÖRMEZDEN GELİR.
    """

    unique_labels = set()
    # Kopya dosyaları tanımak için regex deseni: (rakamlar).json
    copy_pattern = re.compile(r"\(\d+\)\.json$")

    json_files = list(json_dir.glob("*.json"))

    if not json_files:
        print(f"Hata: '{json_dir}' klasöründe hiç .json dosyası bulunamadı.")
        return

    print(f"'{json_dir}' klasöründeki toplam {len(json_files)} dosya taranıyor...")

    processed_files_count = 0
    for json_path in tqdm(json_files):

        # --- FİLTRELEME ---
        # Eğer dosya adı kopya desenine uyuyorsa, bu dosyayı atla
        if copy_pattern.search(json_path.name):
            continue
        # --------------------

        try:
            with open(json_path, "r", encoding="utf-8") as f:
                data = json.load(f)

            if "shapes" in data and isinstance(data["shapes"], list):
                for shape in data["shapes"]:
                    if "label" in shape:
                        unique_labels.add(shape["label"].lower())

            processed_files_count += 1

        except Exception as e:
            print(f"\nUyarı: {json_path.name} dosyası okunurken hata oluştu: {e}")

    # --- SONUÇLARI GÖSTER ---
    print(
        f"\nTarama tamamlandı. {len(json_files)} dosyadan {processed_files_count} adedi (orijinal olanlar) işlendi."
    )
    if not unique_labels:
        print("İşlenen dosyalarda hiçbir etiket (label) bulunamadı.")
    else:
        print(f"Bulunan toplam {len(unique_labels)} adet benzersiz sınıf:")

        sorted_labels = sorted(list(unique_labels))
        for label in sorted_labels:
            print(f"- {label}")

        print("\n" + "=" * 30)
        print(" Dönüştürme script'i için CLASS_MAP taslağı:")
        print("CLASS_MAP = {")
        for i, label in enumerate(sorted_labels):
            print(f'    "{label}": {i},')
        print("}")
        print("=" * 30)


# Script'i çalıştır
if __name__ == "__main__":
    find_unique_labels_filtered(JSON_DIR)
