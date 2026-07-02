"""
Embedding Oluşturma Scripti

Bu script:
1. turkish-e5-large modelini yükler
2. Verisetindeki başlık ve özetler için embedding oluşturur (1024 boyutunda)
3. PCA ile embedding boyutunu 256'ya düşürür
4. 6 farklı veriseti oluşturur:
   - Train: başlık_embed (256), özet_embed (256), concat(başlık_embed, özet_embed) (512)
   - Test: başlık_embed (256), özet_embed (256), concat(başlık_embed, özet_embed) (512)
5. Sonuçları dataset/ klasörüne kaydeder
"""

import argparse
import os
import numpy as np
import torch
from transformers import AutoTokenizer, AutoModel
from datasets import load_from_disk
import pandas as pd
from tqdm import tqdm
from sklearn.decomposition import PCA
import joblib

# Cihaz seçimi (GPU varsa kullan)
DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Model bilgisi
MODEL_NAME = "ytu-ce-cosmos/turkish-e5-large"

# Giriş/çıkış dizinleri
INPUT_DIR = "dataset"
DEFAULT_OUTPUT_DIR = "dataset"

# Batch boyutu (GPU belleğine göre ayarlanabilir)
BATCH_SIZE = 16

# PCA hedef boyutu
PCA_TARGET_DIM = 256


def parse_args():
    """
    Komut satırı argümanlarını okur.

    Returns:
        argparse.Namespace: Argümanlar
    """
    parser = argparse.ArgumentParser(
        description="Turkish E5 Large modeliyle embedding oluşturur (PCA opsiyonel)."
    )
    parser.add_argument(
        "--output-dir",
        default=DEFAULT_OUTPUT_DIR,
        help="Embedding dosyalarının kaydedileceği kök dizin (varsayılan: dataset).",
    )
    parser.add_argument(
        "--pca-dim",
        type=int,
        default=PCA_TARGET_DIM,
        help="PCA sonrası hedef boyut (varsayılan: 256).",
    )
    parser.add_argument(
        "--skip-pca",
        dest="use_pca",
        action="store_false",
        help="PCA uygulama; modelden çıkan 1024 boyutlu embeddingleri kaydet.",
    )
    parser.set_defaults(use_pca=True)
    return parser.parse_args()


def load_model():
    """
    Turkish E5 Large modelini ve tokenizer'ı yükler.
    
    Returns:
        tuple: (tokenizer, model)
    """
    print(f"Model yükleniyor: {MODEL_NAME}")
    print(f"Cihaz: {DEVICE}")
    
    tokenizer = AutoTokenizer.from_pretrained(MODEL_NAME)
    model = AutoModel.from_pretrained(MODEL_NAME)
    model = model.to(DEVICE)
    model.eval()  # Değerlendirme moduna al
    
    print("Model yüklendi.")
    return tokenizer, model


def mean_pooling(model_output, attention_mask):
    """
    Token embeddinglerinden cümle embedding'i oluşturur (mean pooling).
    
    Args:
        model_output: Model çıktısı
        attention_mask: Dikkat maskesi
    
    Returns:
        torch.Tensor: Ortalama pooling sonucu
    """
    token_embeddings = model_output[0]  # İlk eleman token embeddingleri
    input_mask_expanded = attention_mask.unsqueeze(-1).expand(token_embeddings.size()).float()
    return torch.sum(token_embeddings * input_mask_expanded, 1) / torch.clamp(input_mask_expanded.sum(1), min=1e-9)


def create_embeddings(texts, tokenizer, model, batch_size=BATCH_SIZE):
    """
    Verilen metinler için embedding oluşturur.
    
    Args:
        texts: Embedding oluşturulacak metinler
        tokenizer: Tokenizer
        model: Model
        batch_size: Batch boyutu
    
    Returns:
        np.ndarray: Embedding matrisi (n_samples, embedding_dim)
    """
    all_embeddings = []
    
    # Batch'ler halinde işle
    for i in tqdm(range(0, len(texts), batch_size), desc="Embedding oluşturuluyor"):
        batch_texts = texts[i:i + batch_size]
        
        # E5 modeli için "query: " prefix'i ekle
        batch_texts = ["query: " + text for text in batch_texts]
        
        # Tokenize
        encoded = tokenizer(
            batch_texts,
            padding=True,
            truncation=True,
            max_length=512,
            return_tensors="pt"
        )
        encoded = {k: v.to(DEVICE) for k, v in encoded.items()}
        
        # Embedding oluştur
        with torch.no_grad():
            model_output = model(**encoded)
            embeddings = mean_pooling(model_output, encoded['attention_mask'])
            
            # Normalize et
            embeddings = torch.nn.functional.normalize(embeddings, p=2, dim=1)
        
        all_embeddings.append(embeddings.cpu().numpy())
    
    return np.vstack(all_embeddings)


def process_dataset(split_name, data, tokenizer, model):
    """
    Bir veriseti split'i için tüm embeddingleri oluşturur (PCA öncesi, 1024 boyutunda).
    
    Args:
        split_name: Split adı (train/test)
        data: Veriseti
        tokenizer: Tokenizer
        model: Model
    
    Returns:
        dict: Embedding verisetleri (1024 boyutunda)
    """
    print(f"\n{'='*60}")
    print(f"{split_name.upper()} VERİSETİ İŞLENİYOR")
    print(f"{'='*60}")
    
    # Başlıkları al (Türkçe öncelikli, yoksa İngilizce)
    titles = []
    for item in data:
        title = item['title_tr'] if item['title_tr'] else item['title_en']
        titles.append(title if title else "")
    
    # Özetleri al (Türkçe öncelikli, yoksa İngilizce)
    abstracts = []
    for item in data:
        abstract = item['abstract_tr'] if item['abstract_tr'] else item['abstract_en']
        abstracts.append(abstract if abstract else "")
    
    # Yılları al
    years = [item['year'] for item in data]
    
    print(f"Toplam kayıt: {len(titles)}")
    
    # Başlık embeddinglari
    print("\n1. Başlık embeddinglari oluşturuluyor...")
    title_embeddings = create_embeddings(titles, tokenizer, model)
    print(f"   Boyut: {title_embeddings.shape}")
    
    # Özet embeddinglari
    print("\n2. Özet embeddinglari oluşturuluyor...")
    abstract_embeddings = create_embeddings(abstracts, tokenizer, model)
    print(f"   Boyut: {abstract_embeddings.shape}")
    
    return {
        'title': title_embeddings,
        'abstract': abstract_embeddings,
        'years': np.array(years)
    }


def train_pca_models(train_title_embeddings, train_abstract_embeddings, target_dim=PCA_TARGET_DIM):
    """
    Train embedding'leri üzerinden PCA modellerini eğitir.
    
    Args:
        train_title_embeddings: Eğitim başlık embedding'leri (n_samples, 1024)
        train_abstract_embeddings: Eğitim özet embedding'leri (n_samples, 1024)
        target_dim: PCA hedef boyutu
    
    Returns:
        tuple: (title_pca_model, abstract_pca_model)
    """
    print(f"\n{'='*60}")
    print("PCA MODELLERİ EĞİTİLİYOR")
    print(f"{'='*60}")
    
    # Title için PCA
    print(f"\n1. Başlık embedding'leri için PCA eğitiliyor...")
    print(f"   Giriş boyutu: {train_title_embeddings.shape[1]}")
    title_pca = PCA(n_components=target_dim, random_state=42)
    title_pca.fit(train_title_embeddings)
    explained_variance_title = title_pca.explained_variance_ratio_.sum()
    print(f"   Çıkış boyutu: {target_dim}")
    print(f"   Açıklanan varyans: {explained_variance_title:.4f} ({explained_variance_title*100:.2f}%)")
    
    # Abstract için PCA
    print(f"\n2. Özet embedding'leri için PCA eğitiliyor...")
    print(f"   Giriş boyutu: {train_abstract_embeddings.shape[1]}")
    abstract_pca = PCA(n_components=target_dim, random_state=42)
    abstract_pca.fit(train_abstract_embeddings)
    explained_variance_abstract = abstract_pca.explained_variance_ratio_.sum()
    print(f"   Çıkış boyutu: {target_dim}")
    print(f"   Açıklanan varyans: {explained_variance_abstract:.4f} ({explained_variance_abstract*100:.2f}%)")
    
    return title_pca, abstract_pca


def apply_pca(embeddings, pca_model, embed_type="embedding"):
    """
    PCA modelini embedding'lere uygular.
    
    Args:
        embeddings: Embedding matrisi (n_samples, original_dim)
        pca_model: Eğitilmiş PCA modeli
        embed_type: Embedding tipi (loglama için)
    
    Returns:
        np.ndarray: PCA uygulanmış embedding matrisi (n_samples, target_dim)
    """
    transformed = pca_model.transform(embeddings)
    print(f"   {embed_type} PCA sonrası boyut: {embeddings.shape} -> {transformed.shape}")
    return transformed


def apply_pca_to_embeddings(train_embeddings, test_embeddings, title_pca, abstract_pca):
    """
    Train ve test embedding'lerine PCA uygular ve concat embedding'leri oluşturur.
    
    Args:
        train_embeddings: Eğitim embedding'leri (1024 boyutunda)
        test_embeddings: Test embedding'leri (1024 boyutunda)
        title_pca: Başlık için PCA modeli
        abstract_pca: Özet için PCA modeli
    
    Returns:
        tuple: ((train_title_256, train_abstract_256, train_concat_512), 
                (test_title_256, test_abstract_256, test_concat_512))
    """
    print(f"\n{'='*60}")
    print("PCA UYGULANIYOR")
    print(f"{'='*60}")
    
    # Train embedding'lerine PCA uygula
    print("\nTRAIN embedding'leri:")
    train_title_256 = apply_pca(train_embeddings['title'], title_pca, "Başlık")
    train_abstract_256 = apply_pca(train_embeddings['abstract'], abstract_pca, "Özet")
    
    # Train concat (256 + 256 = 512)
    train_concat_512 = np.concatenate([train_title_256, train_abstract_256], axis=1)
    print(f"   Birleştirilmiş embedding boyutu: {train_concat_512.shape}")
    
    # Test embedding'lerine PCA uygula
    print("\nTEST embedding'leri:")
    test_title_256 = apply_pca(test_embeddings['title'], title_pca, "Başlık")
    test_abstract_256 = apply_pca(test_embeddings['abstract'], abstract_pca, "Özet")
    
    # Test concat (256 + 256 = 512)
    test_concat_512 = np.concatenate([test_title_256, test_abstract_256], axis=1)
    print(f"   Birleştirilmiş embedding boyutu: {test_concat_512.shape}")
    
    # Sonuçları dict olarak döndür
    train_result = {
        'title': train_title_256,
        'abstract': train_abstract_256,
        'concat': train_concat_512,
        'years': train_embeddings['years']
    }
    
    test_result = {
        'title': test_title_256,
        'abstract': test_abstract_256,
        'concat': test_concat_512,
        'years': test_embeddings['years']
    }
    
    return train_result, test_result


def save_pca_models(title_pca, abstract_pca, output_dir):
    """
    PCA modellerini kaydeder.
    
    Args:
        title_pca: Başlık için PCA modeli
        abstract_pca: Özet için PCA modeli
        output_dir: Çıktı dizini
    """
    print(f"\n{'='*60}")
    print("PCA MODELLERİ KAYDEDİLİYOR")
    print(f"{'='*60}")
    
    os.makedirs(output_dir, exist_ok=True)
    
    title_pca_path = os.path.join(output_dir, "title_pca_model.joblib")
    abstract_pca_path = os.path.join(output_dir, "abstract_pca_model.joblib")
    
    joblib.dump(title_pca, title_pca_path)
    print(f"✓ {title_pca_path}")
    
    joblib.dump(abstract_pca, abstract_pca_path)
    print(f"✓ {abstract_pca_path}")


def save_embeddings(train_embeddings, test_embeddings, output_dir):
    """
    Embedding verisetlerini kaydeder.
    
    Args:
        train_embeddings: Eğitim embedding'leri (PCA sonrası)
        test_embeddings: Test embedding'leri (PCA sonrası)
        output_dir: Çıktı dizini
    """
    print(f"\n{'='*60}")
    print("EMBEDDİNGLER KAYDEDİLİYOR")
    print(f"{'='*60}")
    
    os.makedirs(output_dir, exist_ok=True)
    
    # 6 farklı veriseti kaydet
    datasets_info = [
        ('title', 'Başlık embedding (PCA: 256)'),
        ('abstract', 'Özet embedding (PCA: 256)'),
        ('concat', 'Birleştirilmiş embedding (256+256=512)')
    ]
    
    for embed_type, description in datasets_info:
        # Train verisi
        train_file = os.path.join(output_dir, f"train_{embed_type}_embeddings.npz")
        np.savez_compressed(
            train_file,
            embeddings=train_embeddings[embed_type],
            years=train_embeddings['years']
        )
        print(f"✓ {train_file}")
        print(f"  - {description}")
        print(f"  - Embedding boyutu: {train_embeddings[embed_type].shape}")
        
        # Test verisi
        test_file = os.path.join(output_dir, f"test_{embed_type}_embeddings.npz")
        np.savez_compressed(
            test_file,
            embeddings=test_embeddings[embed_type],
            years=test_embeddings['years']
        )
        print(f"✓ {test_file}")
        print(f"  - {description}")
        print(f"  - Embedding boyutu: {test_embeddings[embed_type].shape}")
        print()


def generate_embeddings_info(train_embeddings, test_embeddings, output_dir, *, use_pca, variant_name, base_dim, pca_dim):
    """
    Embedding bilgi dosyası oluşturur.
    
    Args:
        train_embeddings: Eğitim embedding'leri
        test_embeddings: Test embedding'leri
        output_dir: Çıktı dizini
    """
    title_dim = train_embeddings['title'].shape[1]
    concat_dim = train_embeddings['concat'].shape[1]
    info_text = f"""# Embedding Bilgileri

## Model Bilgisi

- **Model**: [{MODEL_NAME}](https://huggingface.co/{MODEL_NAME})
- **Embedding Varyantı**: {variant_name}
- **Başlık/Özet Embedding Boyutu**: {title_dim}
- **Birleştirilmiş Embedding Boyutu**: {concat_dim}

## Oluşturulan Verisetleri

| Dosya | Açıklama | Boyut |
|-------|----------|-------|
| train_title_embeddings.npz | Eğitim - Başlık embeddinglari | {train_embeddings['title'].shape} |
| train_abstract_embeddings.npz | Eğitim - Özet embeddinglari | {train_embeddings['abstract'].shape} |
| train_concat_embeddings.npz | Eğitim - Birleştirilmiş embeddingler | {train_embeddings['concat'].shape} |
| test_title_embeddings.npz | Test - Başlık embeddinglari | {test_embeddings['title'].shape} |
| test_abstract_embeddings.npz | Test - Özet embeddinglari | {test_embeddings['abstract'].shape} |
| test_concat_embeddings.npz | Test - Birleştirilmiş embeddingler | {test_embeddings['concat'].shape} |

## Kullanım

```python
import numpy as np

# Veriyi yükle
data = np.load('dataset/train_title_embeddings.npz')
X_train = data['embeddings']  # Embedding matrisi
y_train = data['years']       # Yıl etiketleri

print(f"X shape: {{X_train.shape}}")
print(f"y shape: {{y_train.shape}}")
```

## PCA Bilgisi
"""
    if use_pca:
        info_text += f"""
- **Orijinal Embedding Boyutu**: {base_dim} (turkish-e5-large model çıktısı)
- **PCA ile Düşürülmüş Boyut**: {pca_dim}
- **Concat Embedding Boyutu**: {2 * pca_dim} (Başlık + Özet)
- PCA modelleri `title_pca_model.joblib` ve `abstract_pca_model.joblib` olarak kaydedilmiştir.
"""
    else:
        info_text += f"""
- PCA uygulanmamıştır; modelden çıkan {base_dim} boyutlu embeddingler doğrudan kaydedilmiştir.
- Concat embedding boyutu {2 * base_dim} olarak hesaplanmıştır.
"""

    info_text += """
## Notlar

- Tüm embeddingler L2 normalize edilmiştir.
- E5 modeli için "query: " prefix'i kullanılmıştır.
- Boş başlık/özet durumunda boş string için embedding oluşturulmuştur.
- Türkçe metin yoksa İngilizce metin kullanılmıştır.
- PCA modelleri sadece PCA varyantı için train verisi üzerinden eğitilmiş, hem train hem test verisine uygulanmıştır.
"""
    
    with open(os.path.join(output_dir, "EMBEDDINGS_INFO.md"), "w", encoding="utf-8") as f:
        f.write(info_text)
    
    print(f"✓ {output_dir}/EMBEDDINGS_INFO.md")


def main(args):
    """
    Ana fonksiyon - embedding oluşturma sürecini yönetir.
    """
    print("=" * 60)
    print("EMBEDDİNG OLUŞTURMA (PCA ile boyut düşürme)")
    print("=" * 60)
    
    # 1. Verisetini yükle
    print("\nVeriseti yükleniyor...")
    dataset = load_from_disk(os.path.join(INPUT_DIR, "thesis_dataset"))
    print(f"Train: {len(dataset['train'])} kayıt")
    print(f"Test: {len(dataset['test'])} kayıt")
    
    # 2. Modeli yükle
    tokenizer, model = load_model()
    
    # 3. Train embeddinglari oluştur (1024 boyutunda)
    train_embeddings_raw = process_dataset("train", dataset['train'], tokenizer, model)
    
    # 4. Test embeddinglari oluştur (1024 boyutunda)
    test_embeddings_raw = process_dataset("test", dataset['test'], tokenizer, model)
    
    base_dim = train_embeddings_raw['title'].shape[1]
    variant_name = f"pca_{args.pca_dim}" if args.use_pca else f"raw_{base_dim}"
    variant_output_dir = os.path.join(args.output_dir, variant_name)
    os.makedirs(variant_output_dir, exist_ok=True)
    print(f"\nÇıktılar {variant_output_dir} dizinine kaydedilecek.")
    
    if args.use_pca:
        # 5. PCA modellerini train verisi üzerinden eğit
        title_pca, abstract_pca = train_pca_models(
            train_embeddings_raw['title'],
            train_embeddings_raw['abstract'],
            target_dim=args.pca_dim
        )
        
        # 6. PCA modellerini kaydet
        save_pca_models(title_pca, abstract_pca, variant_output_dir)
        
        # 7. Hem train hem test embedding'lerine PCA uygula ve concat oluştur
        train_embeddings, test_embeddings = apply_pca_to_embeddings(
            train_embeddings_raw,
            test_embeddings_raw,
            title_pca,
            abstract_pca
        )
    else:
        print("\nPCA atlanıyor; 1024 boyutlu embeddingler kullanılacak.")
        train_concat = np.concatenate(
            [train_embeddings_raw['title'], train_embeddings_raw['abstract']],
            axis=1
        )
        test_concat = np.concatenate(
            [test_embeddings_raw['title'], test_embeddings_raw['abstract']],
            axis=1
        )
        train_embeddings = {
            'title': train_embeddings_raw['title'],
            'abstract': train_embeddings_raw['abstract'],
            'concat': train_concat,
            'years': train_embeddings_raw['years']
        }
        test_embeddings = {
            'title': test_embeddings_raw['title'],
            'abstract': test_embeddings_raw['abstract'],
            'concat': test_concat,
            'years': test_embeddings_raw['years']
        }
    
    # 8. Embedding'leri kaydet
    save_embeddings(train_embeddings, test_embeddings, variant_output_dir)
    
    # 9. Bilgi dosyası oluştur
    generate_embeddings_info(
        train_embeddings,
        test_embeddings,
        variant_output_dir,
        use_pca=args.use_pca,
        variant_name=variant_name,
        base_dim=base_dim,
        pca_dim=args.pca_dim
    )
    
    print("\n" + "=" * 60)
    print("EMBEDDİNG OLUŞTURMA TAMAMLANDI")
    print("=" * 60)
    
    total_embeddings = (
        train_embeddings['title'].shape[0] + 
        train_embeddings['abstract'].shape[0] +
        test_embeddings['title'].shape[0] + 
        test_embeddings['abstract'].shape[0]
    )
    print(f"\nÖzet:")
    print(f"  - Toplam embedding sayısı: {total_embeddings}")
    print(f"  - Başlık/Özet embedding boyutu: {train_embeddings['title'].shape[1]}")
    print(f"  - Birleştirilmiş embedding boyutu: {train_embeddings['concat'].shape[1]}")


if __name__ == "__main__":
    cli_args = parse_args()
    main(cli_args)

