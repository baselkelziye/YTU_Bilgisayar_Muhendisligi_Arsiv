import json
import os
import shutil
from pathlib import Path
from collections import defaultdict
import hashlib
import random
import re
from sklearn.model_selection import train_test_split


class LabelMeToYOLO:
    def __init__(
        self,
        images_dir,
        json_dir,
        output_dir,
        train_ratio=0.7,
        val_ratio=0.15,
        test_ratio=0.15,
    ):
        self.images_dir = Path(images_dir)
        self.json_dir = Path(json_dir)
        self.output_dir = Path(output_dir)

        # Split oranları
        self.train_ratio = train_ratio
        self.val_ratio = val_ratio
        self.test_ratio = test_ratio

        # YOLO klasör yapısı
        self.splits = ["train", "valid", "test"]
        for split in self.splits:
            (self.output_dir / split / "images").mkdir(parents=True, exist_ok=True)
            (self.output_dir / split / "labels").mkdir(parents=True, exist_ok=True)

        self.class_names = set()
        self.stats = {
            "total_images": 0,
            "total_jsons": 0,
            "matched": 0,
            "duplicate_images": 0,
            "duplicate_jsons": 0,
            "unmatched_images": 0,
            "unmatched_jsons": 0,
        }
        # Yeni isimleri tutmak için eşleştirme tablosu
        self.new_filename_map = {}

    def get_file_hash(self, filepath):
        """Dosyanın hash'ini hesapla (kopya kontrolü için)"""
        hash_md5 = hashlib.md5()
        with open(filepath, "rb") as f:
            for chunk in iter(lambda: f.read(4096), b""):
                hash_md5.update(chunk)
        return hash_md5.hexdigest()

    def normalize_filename(self, filename):
        """Dosya adını normalize et (uzantısız) - LabelMe'deki ekleri temizlemek için eski metot"""
        # Uzantıyı kaldır
        name = Path(filename).stem
        # (1), (2) gibi ekleri kaldır
        if name.endswith(")") and "(" in name:
            base = name.rsplit("(", 1)[0]
            return base
        return name

    def normalize_filename_strict(self, filename):
        """
        Dosya adını sıkı kurallara göre normalize et:
        1. Türkçe karakterleri İngilizce karşılıklarına çevir.
        2. Boşlukları ve özel karakterleri alt çizgiye çevir.
        3. Uzantıyı koru.
        """
        path = Path(filename)
        stem = path.stem
        suffix = path.suffix.lower()

        # 1. Türkçe karakterleri İngilizce karşılıklarına çevir
        tr_to_en = {
            "ç": "c",
            "ğ": "g",
            "ı": "i",
            "ö": "o",
            "ş": "s",
            "ü": "u",
            "Ç": "C",
            "Ğ": "G",
            "İ": "I",
            "Ö": "O",
            "Ş": "S",
            "Ü": "U",
        }
        for tr, en in tr_to_en.items():
            stem = stem.replace(tr, en)

        # 2. Geriye kalan özel karakterleri ve boşlukları alt çizgiye çevir
        # Alfabetik, sayısal ve alt çizgi dışındaki her şeyi alt çizgiye çevir
        stem = re.sub(r"[^\w-]", "_", stem)

        # Ardışık alt çizgileri tek bir alt çizgiye indir
        stem = re.sub(r"__+", "_", stem)

        # Başlangıç ve sondaki alt çizgileri kaldır
        stem = stem.strip("_")

        # Tamamen boş kalırsa 'normalized_file' olarak adlandır
        if not stem:
            stem = "normalized_file"

        new_name = f"{stem}{suffix}"
        return new_name

    def find_image_files(self):
        """Tüm resim dosyalarını bul, kopyaları tespit et ve isimleri normalize et"""
        image_extensions = {".jpg", ".jpeg", ".png", ".bmp"}
        images = {}
        image_hashes = defaultdict(list)

        original_to_new_path = {}

        for ext in image_extensions:
            for img_path in self.images_dir.glob(f"*{ext}"):
                # Orijinal dosya adını kaydet
                original_name = img_path.name

                # Yeni, normalize edilmiş adı oluştur
                new_name = self.normalize_filename_strict(original_name)

                # Çakışma kontrolü (farklı orijinal isimler aynı yeni isme dönüşmüş olabilir)
                if new_name in images:
                    # Basit bir çözüm olarak, çakışan ismin sonuna bir sayaç ekleyelim
                    i = 1
                    temp_new_name = new_name
                    while temp_new_name in images:
                        i += 1
                        temp_new_name = (
                            f"{Path(new_name).stem}_{i}{Path(new_name).suffix}"
                        )
                    new_name = temp_new_name

                # Bellekte orijinal Path yerine yeni adı kullanıyoruz
                images[new_name] = img_path
                self.new_filename_map[img_path] = (
                    new_name  # Orijinal Path -> Yeni İsim eşleşmesi
                )

                img_hash = self.get_file_hash(img_path)
                image_hashes[img_hash].append(new_name)

        # Kopyaları tespit et (Yeni isimler üzerinden)
        for hash_val, file_list in image_hashes.items():
            if len(file_list) > 1:
                self.stats["duplicate_images"] += len(file_list) - 1
                print(f"⚠️  Kopya resimler bulundu: {file_list}")

        self.stats["total_images"] = len(images)
        return images

    def find_json_files(self):
        """Tüm JSON dosyalarını bul ve kopyaları tespit et"""
        jsons = {}
        json_hashes = defaultdict(list)

        for json_path in self.json_dir.glob("*.json"):
            jsons[json_path.name] = json_path
            json_hash = self.get_file_hash(json_path)
            json_hashes[json_hash].append(json_path.name)

        # Kopyaları tespit et
        for hash_val, file_list in json_hashes.items():
            if len(file_list) > 1:
                self.stats["duplicate_jsons"] += len(file_list) - 1
                print(f"⚠️  Kopya JSON'lar bulundu: {file_list}")

        self.stats["total_jsons"] = len(jsons)
        return jsons

    def match_files(self, images, jsons):
        """Resim ve JSON dosyalarını eşleştir (Artık 'images' normalize edilmiş isimleri kullanıyor)"""
        matches = []

        # images sözlüğü: {yeni_ad: orijinal_path}
        # self.new_filename_map sözlüğü: {orijinal_path: yeni_ad}

        for json_name, json_path in jsons.items():
            try:
                with open(json_path, "r", encoding="utf-8") as f:
                    data = json.load(f)

                    # 1. JSON'daki imagePath'i kontrol ederek eşleştir (orijinal isim üzerinden)
                    image_path_in_json = data.get("imagePath", "")
                    image_name_in_json = Path(image_path_in_json).name

                    # Orijinal Resim dosya adına karşılık gelen yeni ismi bulmaya çalış
                    matched_new_name = None
                    matched_original_path = None

                    # Orijinal resim adına göre eşleşen orijinal yolu bul
                    original_image_path = None

                    # find_image_files'da orijinal adı kullanmadığımız için, önce orijinal adı alıp
                    # onun Path'ini bulup, Path'ten yeni adına gitmek daha mantıklı.

                    # Hata: images sözlüğünde orijinal isimler yok. Tüm resim Path'lerini taramalıyız.
                    all_original_image_paths = [
                        p
                        for p in self.new_filename_map.keys()
                        if p.name == image_name_in_json
                    ]

                    if all_original_image_paths:
                        # Eğer bir resim bulunursa (genellikle 1 tane olmalı)
                        original_image_path = all_original_image_paths[0]
                        matched_new_name = self.new_filename_map.get(
                            original_image_path
                        )
                        matched_original_path = original_image_path

                    if matched_new_name and matched_new_name in images:
                        # Eşleşme bulundu
                        matches.append(
                            (matched_original_path, json_path, matched_new_name)
                        )  # (orijinal_resim_path, json_path, yeni_resim_adı)
                        continue

                    # 2. Alternatif: JSON dosya adına göre eşleştir (normalize edilmiş isimler üzerinden)
                    json_base_original = self.normalize_filename(
                        json_name
                    )  # LabelMe'nin (1) (2) eklerini temizle

                    for new_img_name, original_img_path in images.items():
                        # Orijinal Resim dosya adının (uzantısız) normalize edilmiş halini al (eski metotla)
                        img_base_original = self.normalize_filename(
                            original_img_path.name
                        )

                        if json_base_original == img_base_original:
                            # Eşleşme bulundu
                            matches.append(
                                (original_img_path, json_path, new_img_name)
                            )  # (orijinal_resim_path, json_path, yeni_resim_adı)
                            break
            except Exception as e:
                print(f"❌ JSON okuma hatası ({json_name}): {e}")

        self.stats["matched"] = len(matches)
        return matches

    def polygon_to_yolo(self, points, img_width, img_height):
        """Polygon koordinatlarını YOLO formatına çevir"""
        # Normalize et ve düzleştir
        normalized = []
        for x, y in points:
            normalized.append(x / img_width)
            normalized.append(y / img_height)
        return normalized

    def get_json_classes(self, json_path):
        """JSON dosyasındaki tüm sınıfları al"""
        try:
            with open(json_path, "r", encoding="utf-8") as f:
                data = json.load(f)
            classes = set()
            for shape in data["shapes"]:
                label = shape["label"].lower().strip()
                classes.add(label)
            return classes
        except:
            return set()

    def stratified_split(self, matches):
        """Sınıf dengesini koruyarak veriyi böl"""
        print(f"\n📊 Sınıf dengeli split yapılıyor...")

        # Her örnek için sınıf bilgisini topla
        sample_classes = []
        for original_img_path, json_path, new_img_name in matches:
            classes = self.get_json_classes(json_path)
            # Multi-label için en yaygın sınıfı kullan veya birleştir
            class_label = "_".join(sorted(classes)) if classes else "unknown"
            sample_classes.append(class_label)

        # Sınıf dağılımını göster
        class_counts = defaultdict(int)
        for cls in sample_classes:
            class_counts[cls] += 1

        print(f"\n   Sınıf Dağılımı:")
        for cls, count in sorted(class_counts.items()):
            print(f"   - {cls}: {count} örnek")

        # Stratified split (sklearn kullanarak)
        indices = list(range(len(matches)))

        # İlk olarak train ve temp (val+test) olarak ayır
        train_indices, temp_indices = train_test_split(
            indices,
            test_size=(self.val_ratio + self.test_ratio),
            random_state=42,
            stratify=sample_classes,
        )

        # Temp'i val ve test olarak ayır
        temp_classes = [sample_classes[i] for i in temp_indices]
        val_size = self.val_ratio / (self.val_ratio + self.test_ratio)

        val_indices, test_indices = train_test_split(
            temp_indices,
            test_size=(1 - val_size),
            random_state=42,
            stratify=temp_classes,
        )

        # İndekslere göre matches'i ayır
        train_matches = [matches[i] for i in train_indices]
        val_matches = [matches[i] for i in val_indices]
        test_matches = [matches[i] for i in test_indices]

        print(f"\n   ✅ Split Sonuçları:")
        print(
            f"   - Train: {len(train_matches)} örnek ({len(train_matches)/len(matches)*100:.1f}%)"
        )
        print(
            f"   - Valid: {len(val_matches)} örnek ({len(val_matches)/len(matches)*100:.1f}%)"
        )
        print(
            f"   - Test: {len(test_matches)} örnek ({len(test_matches)/len(matches)*100:.1f}%)"
        )

        return {"train": train_matches, "valid": val_matches, "test": test_matches}

    def convert_json_to_yolo(self, json_path, output_path, class_to_id, new_img_name):
        """Tek bir JSON dosyasını YOLO formatına çevir ve imagePath'i güncelle"""
        try:
            with open(json_path, "r", encoding="utf-8") as f:
                data = json.load(f)

            # --- Güncelleme Başlangıcı ---
            # JSON içindeki imagePath'i yeni, normalize edilmiş dosya adı ile güncelle
            data["imagePath"] = new_img_name

            # JSON dosyasını *aynı yere* güncellenmiş haliyle kaydet (opsiyonel ama tutarlılık için iyi)
            # Not: Bu, orijinal JSON dosyasını kalıcı olarak değiştirir. Geriye dönük uyumluluk için dikkatli olunmalıdır.
            with open(json_path, "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4)
            # --- Güncelleme Sonu ---

            img_width = data["imageWidth"]
            img_height = data["imageHeight"]

            yolo_annotations = []

            for shape in data["shapes"]:
                label = shape["label"].lower().strip()  # Lowercase + boşlukları temizle
                points = shape["points"]

                # Sınıf ID'si
                if label not in class_to_id:
                    class_to_id[label] = len(class_to_id)
                class_id = class_to_id[label]

                # YOLO formatına çevir (Sadece Polygon destekliyoruz, LabelMe'nin Bounding Box'u da aslında 2 noktalı bir Polygon'dur)
                yolo_coords = self.polygon_to_yolo(points, img_width, img_height)

                # YOLO satırı: <class_id> <x1> <y1> <x2> <y2> ... <xn> <yn>
                line = f"{class_id} " + " ".join(
                    [f"{coord:.6f}" for coord in yolo_coords]
                )
                yolo_annotations.append(line)

            # YOLO dosyasına yaz
            with open(output_path, "w") as f:
                f.write("\n".join(yolo_annotations))

            return True
        except Exception as e:
            print(f"❌ Dönüştürme/JSON Güncelleme hatası ({json_path.name}): {e}")
            return False

    def create_yaml(self, class_to_id):
        """YOLO için data.yaml dosyası oluştur"""
        yaml_content = f"""# YOLO Dataset Configuration
path: {self.output_dir.absolute()}
train: train/images
val: valid/images
test: test/images

# Classes
nc: {len(class_to_id)}
names: {list(class_to_id.keys())}
"""
        yaml_path = self.output_dir / "data.yaml"
        with open(yaml_path, "w", encoding="utf-8") as f:
            f.write(yaml_content)
        print(f"✅ data.yaml oluşturuldu: {yaml_path}")

    def convert(self):
        """Ana dönüştürme işlemi"""
        print("🔍 Dosyalar taranıyor...")

        # Dosyaları bul (Resim dosyaları bu aşamada normalize edilmiş yeni isimlere eşlenir)
        images = self.find_image_files()  # {yeni_ad: orijinal_path}
        jsons = self.find_json_files()

        print(f"\n📊 İstatistikler:")
        print(f"   Toplam resim: {self.stats['total_images']}")
        print(f"   Toplam JSON: {self.stats['total_jsons']}")
        print(f"   Kopya resim: {self.stats['duplicate_images']}")
        print(f"   Kopya JSON: {self.stats['duplicate_jsons']}")

        # Eşleştir
        print(f"\n🔗 Dosyalar eşleştiriliyor...")
        # matches: (orijinal_resim_path, json_path, yeni_resim_adı)
        matches = self.match_files(images, jsons)

        print(f"   ✅ Eşleşen çift: {len(matches)}")
        print(f"   ⚠️  Eşleşmeyen resim: {self.stats['total_images'] - len(matches)}")
        print(f"   ⚠️  Eşleşmeyen JSON: {self.stats['total_jsons'] - len(matches)}")

        if len(matches) == 0:
            print("❌ Hiç eşleşme bulunamadı!")
            return

        # Stratified split yap
        split_matches = self.stratified_split(matches)

        # Dönüştür ve kaydet
        print(f"\n🔄 YOLO formatına dönüştürülüyor...")
        class_to_id = {}

        for split_name, split_data in split_matches.items():
            print(f"\n   📁 {split_name.upper()} seti işleniyor...")
            success_count = 0

            # split_data: (orijinal_img_path, json_path, new_img_name)
            for original_img_path, json_path, new_img_name in split_data:
                # Resmi yeni, normalize edilmiş adıyla kopyala
                output_img = self.output_dir / split_name / "images" / new_img_name
                shutil.copy2(
                    original_img_path, output_img
                )  # Orijinal yoldan oku, yeni yola yaz

                # JSON'u YOLO formatına çevir
                # Label dosya adı (uzantısız) resim dosya adıyla (uzantısız) aynı olmalı
                output_label = (
                    self.output_dir
                    / split_name
                    / "labels"
                    / f"{Path(new_img_name).stem}.txt"
                )

                # Yeni resim adını JSON güncellemesi için fonksiyona iletiyoruz
                if self.convert_json_to_yolo(
                    json_path, output_label, class_to_id, new_img_name
                ):
                    success_count += 1

            print(f"      ✅ Başarıyla dönüştürülen: {success_count}/{len(split_data)}")

        # Classes dosyası oluştur
        classes_path = self.output_dir / "classes.txt"
        with open(classes_path, "w", encoding="utf-8") as f:
            for class_name in sorted(class_to_id.keys()):
                f.write(f"{class_name}\n")
        print(f"\n✅ classes.txt oluşturuldu")

        # YAML dosyası oluştur
        self.create_yaml(class_to_id)

        # Final istatistikler
        print(f"\n✨ Dönüştürme tamamlandı!")
        print(f"   📂 Çıktı dizini: {self.output_dir}")
        print(f"   🏷️  Sınıf sayısı: {len(class_to_id)}")
        print(f"   📋 Sınıflar: {list(class_to_id.keys())}")
        print(f"\n   📊 Final Dataset:")
        print(f"   - train/images: {len(split_matches['train'])} resim")
        print(f"   - valid/images: {len(split_matches['valid'])} resim")
        print(f"   - test/images: {len(split_matches['test'])} resim")


# Kullanım
if __name__ == "__main__":
    # Dizinleri belirt
    IMAGES_DIR = "./data/temp_v2/IMAGES"  # Resim klasörünüz
    JSON_DIR = "./data/temp_v2/JSON"  # JSON klasörünüz
    OUTPUT_DIR = "./data/data_v2"  # Çıktı klasörü

    # Dönüştürücüyü başlat (70% train, 15% valid, 15% test)
    converter = LabelMeToYOLO(
        IMAGES_DIR,
        JSON_DIR,
        OUTPUT_DIR,
        train_ratio=0.7,
        val_ratio=0.15,
        test_ratio=0.15,
    )
    converter.convert()
