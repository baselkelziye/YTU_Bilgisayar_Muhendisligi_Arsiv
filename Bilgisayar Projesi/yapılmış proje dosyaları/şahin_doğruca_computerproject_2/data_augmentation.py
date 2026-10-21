import os
import cv2
import yaml
import albumentations as A
from pathlib import Path
from tqdm import tqdm
import shutil
from collections import defaultdict
import numpy as np


class ClassSpecificAugmentation:
    def __init__(self, data_yaml_path, output_folder_name, target_count=200):
        """
        Class-specific offline augmentation for polygon segmentation

        Args:
            data_yaml_path: data.yaml dosyasının yolu
            output_folder_name: Yeni veri seti klasör adı (örn: "data_v2")
            target_count: Her sınıf için hedef görüntü sayısı
        """
        self.data_yaml_path = data_yaml_path
        self.output_folder_name = output_folder_name
        self.target_count = target_count
        self.load_config()
        self.setup_output_dirs()

    def load_config(self):
        """data.yaml dosyasını yükle"""
        with open(self.data_yaml_path, "r", encoding="utf-8") as f:
            self.config = yaml.safe_load(f)

        # Base path'i al
        if "path" in self.config:
            base_path = Path(self.config["path"])
        else:
            base_path = Path(self.data_yaml_path).parent

        # Orijinal yolları oluştur
        train_rel = Path(self.config["train"])
        val_rel = Path(self.config["val"])
        test_rel = Path(self.config["test"])

        # Eğer 'images' klasörü zaten path'te varsa, parent'ını al
        if train_rel.name == "images":
            self.train_path = base_path / train_rel.parent
        else:
            self.train_path = base_path / train_rel

        if val_rel.name == "images":
            self.val_path = base_path / val_rel.parent
        else:
            self.val_path = base_path / val_rel

        if test_rel.name == "images":
            self.test_path = base_path / test_rel.parent
        else:
            self.test_path = base_path / test_rel

        # Class isimlerini al
        self.class_names = self.config["names"]
        self.num_classes = self.config["nc"]

        print(f"✓ Config yüklendi: {self.num_classes} sınıf")
        print(f"  Orijinal Train: {self.train_path}")
        print(f"  Orijinal Valid: {self.val_path}")
        print(f"  Orijinal Test: {self.test_path}")

    def setup_output_dirs(self):
        """Yeni output klasörlerini oluştur"""
        # Output base path
        base_path = Path(self.data_yaml_path).parent
        self.output_base = base_path / self.output_folder_name

        # Yeni yollar
        self.output_train = self.output_base / "train"
        self.output_val = self.output_base / "valid"
        self.output_test = self.output_base / "test"

        print(f"\n✓ Yeni veri seti oluşturulacak:")
        print(f"  Output Train: {self.output_train}")
        print(f"  Output Valid: {self.output_val}")
        print(f"  Output Test: {self.output_test}")

        # Klasörleri oluştur
        for split_path in [self.output_train, self.output_val, self.output_test]:
            (split_path / "images").mkdir(parents=True, exist_ok=True)
            (split_path / "labels").mkdir(parents=True, exist_ok=True)

    def get_augmentation_pipeline(self, aggressive=True):
        """
        Augmentation pipeline oluştur (polygon-compatible)

        Args:
            aggressive: True ise daha agresif augmentation
        """
        if aggressive:
            # Train için agresif augmentation
            return A.Compose(
                [
                    A.Rotate(limit=30, p=0.8),
                    A.HorizontalFlip(p=0.5),
                    A.VerticalFlip(p=0.5),
                    A.RandomBrightnessContrast(
                        brightness_limit=0.3, contrast_limit=0.3, p=0.8
                    ),
                    A.OneOf(
                        [
                            A.GaussianBlur(blur_limit=(3, 7), p=1.0),
                            A.MedianBlur(blur_limit=5, p=1.0),
                            A.MotionBlur(blur_limit=7, p=1.0),
                        ],
                        p=0.3,
                    ),
                    A.ElasticTransform(alpha=50, sigma=5, p=0.3),
                    A.CLAHE(clip_limit=4.0, p=0.5),
                    A.RandomGamma(gamma_limit=(80, 120), p=0.3),
                    A.GaussNoise(p=0.3),
                    A.Sharpen(alpha=(0.2, 0.5), lightness=(0.5, 1.0), p=0.3),
                ],
                keypoint_params=A.KeypointParams(format="xy", remove_invisible=False),
            )
        else:
            # Valid/Test için hafif augmentation
            return A.Compose(
                [
                    A.Rotate(limit=10, p=0.5),
                    A.HorizontalFlip(p=0.5),
                    A.RandomBrightnessContrast(
                        brightness_limit=0.1, contrast_limit=0.1, p=0.5
                    ),
                ],
                keypoint_params=A.KeypointParams(format="xy", remove_invisible=False),
            )

    def parse_polygon_label(self, label_line):
        """
        Polygon formatındaki label'ı parse et

        Args:
            label_line: "class_id x1 y1 x2 y2 x3 y3 ..." formatında string

        Returns:
            class_id, keypoints (list of tuples)
        """
        parts = label_line.strip().split()
        if len(parts) < 7:  # En az class + 3 nokta (6 koordinat)
            return None, None

        class_id = int(parts[0])
        coords = [float(x) for x in parts[1:]]

        # Koordinatları (x, y) tuple'larına çevir
        keypoints = [(coords[i], coords[i + 1]) for i in range(0, len(coords), 2)]

        return class_id, keypoints

    def keypoints_to_polygon_string(self, class_id, keypoints):
        """
        Keypoint'leri YOLO polygon formatına çevir

        Args:
            class_id: Sınıf ID'si
            keypoints: [(x1, y1), (x2, y2), ...] formatında liste

        Returns:
            "class_id x1 y1 x2 y2 ..." formatında string
        """
        coords = []
        for x, y in keypoints:
            # Koordinatları [0, 1] aralığında tut
            x = max(0.0, min(1.0, x))
            y = max(0.0, min(1.0, y))
            coords.extend([f"{x:.6f}", f"{y:.6f}"])

        return f"{class_id} {' '.join(coords)}"

    def analyze_class_distribution(self, dataset_path):
        """Veri setindeki sınıf dağılımını analiz et"""
        images_path = dataset_path / "images"
        labels_path = dataset_path / "labels"

        class_counts = defaultdict(int)
        class_images = defaultdict(list)

        # Tüm label dosyalarını tara
        for label_file in labels_path.glob("*.txt"):
            with open(label_file, "r") as f:
                lines = f.readlines()

            # Bu görüntüdeki sınıfları say
            image_classes = set()
            for line in lines:
                if line.strip():
                    class_id, _ = self.parse_polygon_label(line)
                    if class_id is not None:
                        image_classes.add(class_id)

            # Her sınıf için bu görüntüyü kaydet
            for class_id in image_classes:
                class_counts[class_id] += 1
                class_images[class_id].append(label_file.stem)

        return class_counts, class_images

    def augment_image(
        self,
        img_path,
        label_path,
        transform,
        output_images_dir,
        output_labels_dir,
        output_name,
    ):
        """
        Tek bir görüntüyü ve polygon annotation'ını augment et

        Args:
            img_path: Orijinal görüntü yolu
            label_path: Orijinal label yolu
            transform: Augmentation pipeline
            output_images_dir: Output images klasörü
            output_labels_dir: Output labels klasörü
            output_name: Yeni dosya adı (uzantısız)
        """
        # Görüntüyü yükle
        img = cv2.imread(str(img_path))
        if img is None:
            print(f"  ⚠ Görüntü yüklenemedi: {img_path}")
            return False

        height, width = img.shape[:2]

        # Label'ları yükle (polygon format)
        polygons = []  # Her eleman: (class_id, keypoints_list)

        if label_path.exists():
            with open(label_path, "r") as f:
                for line in f:
                    if line.strip():
                        class_id, keypoints = self.parse_polygon_label(line)
                        if class_id is not None and keypoints is not None:
                            # Normalized koordinatları pixel koordinatlarına çevir
                            pixel_keypoints = [
                                (x * width, y * height) for x, y in keypoints
                            ]
                            polygons.append((class_id, pixel_keypoints))

        if not polygons:
            print(f"  ⚠ Annotation bulunamadı: {label_path}")
            return False

        try:
            # Tüm keypoint'leri tek bir liste halinde birleştir
            all_keypoints = []
            keypoint_class_ids = []
            keypoint_counts = []

            for class_id, keypoints in polygons:
                all_keypoints.extend(keypoints)
                keypoint_class_ids.extend([class_id] * len(keypoints))
                keypoint_counts.append(len(keypoints))

            # Augmentation uygula
            augmented = transform(image=img, keypoints=all_keypoints)

            # Augmented görüntüyü kaydet
            new_img_path = output_images_dir / f"{output_name}{img_path.suffix}"
            cv2.imwrite(str(new_img_path), augmented["image"])

            # Augmented keypoint'leri geri polygon'lara ayır
            aug_keypoints = augmented["keypoints"]
            new_height, new_width = augmented["image"].shape[:2]

            # Label'ı kaydet
            new_label_path = output_labels_dir / f"{output_name}.txt"
            with open(new_label_path, "w") as f:
                start_idx = 0
                for i, count in enumerate(keypoint_counts):
                    end_idx = start_idx + count
                    polygon_keypoints = aug_keypoints[start_idx:end_idx]
                    class_id = keypoint_class_ids[start_idx]

                    # Pixel koordinatlarını normalize et
                    normalized_keypoints = [
                        (x / new_width, y / new_height) for x, y in polygon_keypoints
                    ]

                    # YOLO polygon formatında yaz
                    polygon_str = self.keypoints_to_polygon_string(
                        class_id, normalized_keypoints
                    )
                    f.write(polygon_str + "\n")

                    start_idx = end_idx

            return True

        except Exception as e:
            print(f"  ⚠ Augmentation hatası ({img_path.name}): {e}")
            return False

    def copy_original_files(self, src_path, dst_path, split_name):
        """Orijinal dosyaları yeni klasöre kopyala"""
        print(f"\n📋 Orijinal {split_name} dosyaları kopyalanıyor...")

        src_images = src_path / "images"
        src_labels = src_path / "labels"
        dst_images = dst_path / "images"
        dst_labels = dst_path / "labels"

        # Görüntüleri kopyala
        for img_file in src_images.glob("*"):
            if img_file.suffix.lower() in [".jpg", ".jpeg", ".png", ".bmp"]:
                shutil.copy2(img_file, dst_images / img_file.name)

        # Label'ları kopyala
        for label_file in src_labels.glob("*.txt"):
            shutil.copy2(label_file, dst_labels / label_file.name)

        print(f"  ✓ {split_name} dosyaları kopyalandı")

    def augment_dataset(self, src_path, dst_path, split_name, augment_all=False):
        """
        Bir veri setini augment et

        Args:
            src_path: Kaynak veri seti yolu
            dst_path: Hedef veri seti yolu
            split_name: 'train', 'valid' veya 'test'
            augment_all: True ise tüm sınıfları augment et
        """
        print(f"\n{'='*60}")
        print(f"📊 {split_name.upper()} seti işleniyor...")
        print(f"{'='*60}")

        src_images = src_path / "images"
        src_labels = src_path / "labels"
        dst_images = dst_path / "images"
        dst_labels = dst_path / "labels"

        if not src_images.exists() or not src_labels.exists():
            print(f"⚠ Kaynak klasörler bulunamadı: {src_path}")
            return

        # Önce orijinal dosyaları kopyala
        self.copy_original_files(src_path, dst_path, split_name)

        # Sınıf dağılımını analiz et
        class_counts, class_images = self.analyze_class_distribution(src_path)

        print(f"\n📈 Orijinal dağılım:")
        total_images = (
            len(list(src_images.glob("*.jpg")))
            + len(list(src_images.glob("*.png")))
            + len(list(src_images.glob("*.jpeg")))
            + len(list(src_images.glob("*.bmp")))
        )
        for class_id in sorted(class_counts.keys()):
            count = class_counts[class_id]
            percentage = (count / total_images * 100) if total_images > 0 else 0
            class_name = (
                self.class_names[class_id]
                if class_id < len(self.class_names)
                else f"Class_{class_id}"
            )
            print(
                f"  {class_name} (Class {class_id}): {count} görüntü ({percentage:.1f}%)"
            )

        # Augmentation pipeline seç
        if split_name == "train":
            transform = self.get_augmentation_pipeline(aggressive=True)
        else:
            transform = self.get_augmentation_pipeline(aggressive=False)

        # Augmentation yap
        print(f"\n🔄 Augmentation başlıyor...")
        augmented_counts = defaultdict(int)

        if augment_all:
            # Valid/Test için: Tüm sınıfları hafifçe augment et
            multiplier = 2
            print(f"  Tüm sınıflar {multiplier}x çoğaltılacak")

            for img_file in tqdm(
                list(src_images.glob("*.jpg"))
                + list(src_images.glob("*.png"))
                + list(src_images.glob("*.jpeg"))
                + list(src_images.glob("*.bmp")),
                desc=f"  {split_name}",
            ):
                label_file = src_labels / f"{img_file.stem}.txt"

                for i in range(multiplier - 1):
                    output_name = f"{img_file.stem}_aug{i+1}"
                    success = self.augment_image(
                        img_file,
                        label_file,
                        transform,
                        dst_images,
                        dst_labels,
                        output_name,
                    )
                    if success:
                        augmented_counts["all"] += 1
        else:
            # Train için: Sadece az olan sınıfları çoğalt
            for class_id in sorted(class_counts.keys()):
                count = class_counts[class_id]
                class_name = (
                    self.class_names[class_id]
                    if class_id < len(self.class_names)
                    else f"Class_{class_id}"
                )

                if count >= self.target_count:
                    print(f"  ✓ {class_name}: {count} görüntü (yeterli)")
                    continue

                # Kaç kat çoğaltmak gerekiyor?
                multiplier = max(2, (self.target_count // count) + 1)
                needed = self.target_count - count

                print(
                    f"  🎯 {class_name}: {count} → {min(count * multiplier, self.target_count)} görüntü ({multiplier}x)"
                )

                # Bu sınıfa ait görüntüleri augment et
                class_image_list = class_images[class_id]
                augmented = 0

                for img_name in tqdm(
                    class_image_list, desc=f"    {class_name}", leave=False
                ):
                    # Görüntü dosyasını bul
                    img_file = None
                    for ext in [".jpg", ".png", ".jpeg", ".bmp"]:
                        potential_path = src_images / f"{img_name}{ext}"
                        if potential_path.exists():
                            img_file = potential_path
                            break

                    if img_file is None:
                        continue

                    label_file = src_labels / f"{img_name}.txt"

                    # multiplier kadar augmented versiyon oluştur
                    for i in range(multiplier - 1):
                        if augmented >= needed:
                            break

                        output_name = f"{img_name}_aug{i+1}_c{class_id}"
                        success = self.augment_image(
                            img_file,
                            label_file,
                            transform,
                            dst_images,
                            dst_labels,
                            output_name,
                        )

                        if success:
                            augmented += 1
                            augmented_counts[class_id] += 1

                    if augmented >= needed:
                        break

        # Yeni dağılımı göster
        print(f"\n✅ Augmentation tamamlandı!")
        new_class_counts, _ = self.analyze_class_distribution(dst_path)

        print(f"\n📊 Yeni dağılım:")
        new_total = (
            len(list(dst_images.glob("*.jpg")))
            + len(list(dst_images.glob("*.png")))
            + len(list(dst_images.glob("*.jpeg")))
            + len(list(dst_images.glob("*.bmp")))
        )
        for class_id in sorted(new_class_counts.keys()):
            count = new_class_counts[class_id]
            old_count = class_counts.get(class_id, 0)
            percentage = (count / new_total * 100) if new_total > 0 else 0
            change = count - old_count
            class_name = (
                self.class_names[class_id]
                if class_id < len(self.class_names)
                else f"Class_{class_id}"
            )
            print(
                f"  {class_name} (Class {class_id}): {count} görüntü ({percentage:.1f}%) [+{change}]"
            )

        print(f"\n📈 Toplam: {total_images} → {new_total} görüntü")

    def create_new_yaml(self):
        """Yeni data.yaml dosyası oluştur"""
        new_yaml_path = self.output_base / "data.yaml"

        new_config = self.config.copy()
        new_config["path"] = str(self.output_base.absolute())
        new_config["train"] = "train/images"
        new_config["val"] = "valid/images"
        new_config["test"] = "test/images"

        with open(new_yaml_path, "w", encoding="utf-8") as f:
            yaml.dump(new_config, f, default_flow_style=False, allow_unicode=True)

        print(f"\n✓ Yeni data.yaml oluşturuldu: {new_yaml_path}")

    def run(self, augment_train=True, augment_valid=False, augment_test=False):
        """
        Tüm augmentation işlemini çalıştır

        Args:
            augment_train: Train setini augment et (class-specific)
            augment_valid: Valid setini augment et (tüm sınıflar, hafif)
            augment_test: Test setini augment et (tüm sınıflar, hafif)
        """
        print(f"\n{'='*60}")
        print(f"🚀 POLYGON SEGMENTATION AUGMENTATION")
        print(f"{'='*60}")
        print(f"Output folder: {self.output_folder_name}")
        print(f"Target count: {self.target_count} görüntü/sınıf (train için)")
        print(f"Train augmentation: {'✓' if augment_train else '✗'}")
        print(f"Valid augmentation: {'✓' if augment_valid else '✗'}")
        print(f"Test augmentation: {'✓' if augment_test else '✗'}")

        # Onay al
        print(f"\n⚠ Yeni veri seti oluşturulacak: {self.output_base}")
        confirm = input("Devam etmek istiyor musunuz? (y/n): ")
        if confirm.lower() != "y":
            print("İşlem iptal edildi.")
            return

        # Train setini işle
        if augment_train:
            self.augment_dataset(
                self.train_path, self.output_train, "train", augment_all=False
            )

        # Valid setini işle
        if augment_valid:
            self.augment_dataset(
                self.val_path, self.output_val, "valid", augment_all=True
            )
        else:
            # Sadece kopyala
            self.copy_original_files(self.val_path, self.output_val, "valid")

        # Test setini işle
        if augment_test:
            print("\n⚠ UYARI: Test setini augment etmek önerilmez!")
            confirm = input("Devam etmek istediğinizden emin misiniz? (yes/no): ")
            if confirm.lower() == "yes":
                self.augment_dataset(
                    self.test_path, self.output_test, "test", augment_all=True
                )
            else:
                self.copy_original_files(self.test_path, self.output_test, "test")
        else:
            # Sadece kopyala
            self.copy_original_files(self.test_path, self.output_test, "test")

        # Yeni data.yaml oluştur
        self.create_new_yaml()

        print(f"\n{'='*60}")
        print(f"✅ TÜM İŞLEMLER TAMAMLANDI!")
        print(f"{'='*60}")
        print(f"Yeni veri seti: {self.output_base}")
        print(f"Yeni data.yaml: {self.output_base / 'data.yaml'}")


if __name__ == "__main__":
    # Kullanım
    augmenter = ClassSpecificAugmentation(
        data_yaml_path="data.yaml",  # Orijinal data.yaml yolu
        output_folder_name="data/data_v2_aug",  # Yeni klasör adı
        target_count=200,  # Her sınıftan hedef görüntü sayısı
    )

    # Çalıştır
    augmenter.run(
        augment_train=True,  # Train setini augment et (class-specific)
        augment_valid=False,  # Valid setini augment etme (önerilir)
        augment_test=False,  # Test setini augment etme (kesinlikle önerilmez!)
    )
