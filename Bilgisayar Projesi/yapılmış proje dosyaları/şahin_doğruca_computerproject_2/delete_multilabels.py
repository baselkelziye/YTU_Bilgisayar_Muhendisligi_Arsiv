import json
from pathlib import Path
from collections import defaultdict


def find_multilabel_files(json_dir, images_dir=None, delete=False):
    """
    Birden fazla farklı sınıf içeren JSON dosyalarını bul ve listele

    Args:
        json_dir: JSON klasörü
        images_dir: Resim klasörü (opsiyonel, silinecekse gerekli)
        delete: True ise dosyaları sil
    """
    json_dir = Path(json_dir)
    if images_dir:
        images_dir = Path(images_dir)

    multilabel_files = defaultdict(list)

    print("🔍 Multi-label dosyalar aranıyor...\n")

    # Tüm JSON'ları tara
    for json_path in json_dir.glob("*.json"):
        try:
            with open(json_path, "r", encoding="utf-8") as f:
                data = json.load(f)

            # Sınıfları topla
            classes = set()
            for shape in data["shapes"]:
                label = shape["label"].lower().strip()
                classes.add(label)

            # Birden fazla farklı sınıf varsa
            if len(classes) > 1:
                class_combo = "_".join(sorted(classes))

                # İlişkili resim dosyasını bul
                image_name = data.get("imagePath", "")
                if not image_name:
                    image_name = json_path.stem
                else:
                    image_name = Path(image_name).name

                multilabel_files[class_combo].append(
                    {"json": json_path, "image": image_name, "classes": classes}
                )

        except Exception as e:
            print(f"❌ Hata ({json_path.name}): {e}")

    # Sonuçları göster
    if not multilabel_files:
        print("✅ Multi-label dosya bulunamadı!")
        return

    print(f"📊 Bulunan Multi-Label Kombinasyonlar:\n")

    total_files = 0
    for combo, files in sorted(multilabel_files.items()):
        print(f"🏷️  {combo}: {len(files)} örnek")
        for item in files:
            print(f"   📄 JSON: {item['json'].name}")
            print(f"   🖼️  Image: {item['image']}")
            print(f"   📋 Classes: {item['classes']}")
            print()
            total_files += len(files)

    print(f"📈 Toplam multi-label dosya: {total_files}\n")

    # Silme işlemi
    if delete:
        response = input("⚠️  Bu dosyaları silmek istediğinize emin misiniz? (yes/no): ")
        if response.lower() in ["yes", "y", "evet"]:
            deleted_count = 0

            for combo, files in multilabel_files.items():
                for item in files:
                    # JSON'u sil
                    try:
                        item["json"].unlink()
                        print(f"🗑️  Silindi: {item['json'].name}")
                        deleted_count += 1
                    except Exception as e:
                        print(f"❌ Silinemedi ({item['json'].name}): {e}")

                    # Resmi sil (varsa)
                    if images_dir:
                        # Tüm olası uzantıları dene
                        image_extensions = [".jpg", ".jpeg", ".png", ".bmp"]
                        image_stem = Path(item["image"]).stem

                        for ext in image_extensions:
                            img_path = images_dir / f"{image_stem}{ext}"
                            if img_path.exists():
                                try:
                                    img_path.unlink()
                                    print(f"🗑️  Silindi: {img_path.name}")
                                    deleted_count += 1
                                except Exception as e:
                                    print(f"❌ Silinemedi ({img_path.name}): {e}")
                                break

            print(f"\n✅ {deleted_count} dosya silindi!")
        else:
            print("❌ Silme işlemi iptal edildi.")
    else:
        print("💡 Silmek için delete=True parametresini kullanın")


# Kullanım
if __name__ == "__main__":
    JSON_DIR = "./data/temp_v2/JSON"
    IMAGES_DIR = "./data/temp_v2/IMAGES"

    # Sadece listele
    find_multilabel_files(JSON_DIR, IMAGES_DIR, delete=True)

    # Listele ve sil
    # find_multilabel_files(JSON_DIR, IMAGES_DIR, delete=True)
