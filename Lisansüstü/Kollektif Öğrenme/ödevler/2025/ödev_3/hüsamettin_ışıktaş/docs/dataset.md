# Veri Seti Dokümantasyonu

## Genel Bakış

Bu veri seti, Turkish MMLU veri setinden filtrelenmiş ve GRPO (Group Relative Policy Optimization) formatına dönüştürülmüş 1500 örnekten oluşmaktadır.

- **Train Seti**: 1000 örnek
- **Test Seti**: 500 örnek
- **Toplam**: 1500 örnek

## Veri Seti Lokasyonu

Veri setleri `data/` klasöründe HuggingFace Dataset formatında kaydedilmiştir:

- `data/train_dataset/` - Eğitim seti
- `data/test_dataset/` - Test seti

## Veri Setini Yükleme

```python
from datasets import load_from_disk

# Veri setlerini yükle
train_dataset = load_from_disk("data/train_dataset")
test_dataset = load_from_disk("data/test_dataset")

print(f"Train: {len(train_dataset)} örnek")
print(f"Test: {len(test_dataset)} örnek")
```

## Veri Formatı

Her örnek aşağıdaki alanları içerir:

### Alanlar

1. **`messages`** (List[Dict]): Konuşma formatında mesajlar
   - `role`: "system" veya "user"
   - `content`: Mesaj içeriği

2. **`correct_answer`** (str): Doğru cevap şıkkı (A, B, C, D veya E)

3. **`bolum`** (str): Sorunun ait olduğu bölüm (örn: "YGS Denemeleri", "KPSS", "TUS")

4. **`konu`** (str veya None): Sorunun konusu (bazı örneklerde None olabilir)

5. **`original_answer_index`** (int): Orijinal veri setindeki cevap index'i (0-indexed)

### Örnek Veri Yapısı

```python
{
    "bolum": "TUS",
    "konu": None,
    "messages": [
        {
            "role": "system",
            "content": "Soruyu dikkatlice oku ve adım adım düşünerek çöz. \nDüşünme sürecini, mantıksal çıkarımlarını ve akıl yürütmeni <düşünce> etiketi içinde detaylı bir şekilde açıkla. \nSon olarak, ulaştığın cevabı <cevap> etiketi içinde belirt. Cevabın A, B, C, D veya E şıklarından biri olmalıdır.\n\nFormat:\n<düşünce>\nBurada düşünme sürecini, çıkarımlarını ve akıl yürütmeni yaz.\n</düşünce>\n<cevap>A</cevap>"
        },
        {
            "role": "user",
            "content": "Epigenetik ve fetal programlamaya göre, aşağıda gebelik haftası ve doğum ağırlığı verilen bebeklerin hangisinde ileri yaşlarda artmış tip 2 diabetes mellitus riski vardır?\n\nA. 41 hafta – 3.400 g\nB. 40 hafta – 2.300 g\nC. 39 hafta – 3.200 g\nD. 35 hafta – 2.400 g\nE. 32 hafta – 1.800 g"
        }
    ],
    "correct_answer": "B",
    "original_answer_index": 1
}
```

## Beklenen Model Çıktısı

Model, system prompt'una göre şu formatta çıktı üretmelidir:

```
<düşünce>
[Burada model düşünme sürecini, mantıksal çıkarımlarını ve akıl yürütmesini detaylı bir şekilde açıklar]
</düşünce>
<cevap>B</cevap>
```

## Filtreleme Kriterleri

Veri seti aşağıdaki kriterlere göre filtrelenmiştir:

### 1. Konu/Bölüm Filtreleme

Mantıksal çıkarım, problem çözme ve analitik düşünme gerektiren konular seçilmiştir:

**Tam Eşleşen Bölümler:**
- YGS Denemeleri
- KPSS
- KPSS Denemeleri
- Felsefe
- İktisat
- İşletme Yönetimi
- Sosyoloji
- Dış Ticaret
- TUS
- Yönetim Bİlişim Sistemleri
- Uluslararası Ticaret ve Lojistik Yöneticiliği
- İşletme

**Anahtar Kelime Bazlı Filtreleme:**
Bölüm veya konu alanında şu kelimelerden biri bulunan örnekler dahil edilmiştir:
- matematik, physics, fizik
- mantık, logic
- bilgisayar, computer
- mühendislik, engineering
- istatistik, statistics
- kimya, chemistry
- geometri, geometry
- analiz, analysis
- problem, çözme
- hesaplama, calculation
- denklem, equation
- cebir, algebra

### 2. Uzunluk Filtreleme

- **Minimum Uzunluk**: Soru + tüm secenekler toplamı en az 200 karakter olmalı
- Bu kriter, kısa ve basit soruların filtrelenmesini sağlar
- Böylece modelin düşünce zinciri oluşturabilmesi için yeterli içerik sağlanır

## Veri Seti İstatistikleri

### Bölüm Dağılımı (Train Seti)

- YGS Denemeleri: ~43%
- KPSS Denemeleri: ~20%
- TUS: ~10%
- Dış Ticaret: ~8%
- Diğer bölümler: ~19%

### Cevap Dağılımı

Tüm veri setinde cevaplar oldukça dengeli dağılmıştır:
- A: ~17%
- B: ~19%
- C: ~21%
- D: ~22%
- E: ~21%

### Metin Uzunluğu

- **Ortalama Soru Uzunluğu**: ~282 karakter
- **Medyan Soru Uzunluğu**: ~237 karakter
- **Ortalama Toplam Metin Uzunluğu** (Soru + Secenekler): ~384 karakter
- **Medyan Toplam Metin Uzunluğu**: ~328 karakter

## GRPO Eğitimi İçin Kullanım

Bu veri seti, GRPO (Group Relative Policy Optimization) algoritması ile model eğitimi için hazırlanmıştır.

### Önemli Notlar

1. **System Prompt**: Model, system prompt'una göre `<düşünce>` ve `<cevap>` etiketlerini kullanarak çıktı üretmelidir.

2. **Reward Function**: Eğitim sırasında, model çıktısının:
   - Format uygunluğu (etiket yapısına uygun mu?)
   - Doğruluk (cevap doğru mu?)
   
   kontrol edilmesi gerekir.

3. **Evaluation**: Test seti üzerinde:
   - Accuracy (doğru cevap yüzdesi)
   - Format compliance (format uygunluğu)
   metrikleri hesaplanabilir.

## Örnek Kullanım (HuggingFace Trainer)

```python
from transformers import AutoTokenizer
from datasets import load_from_disk

# Veri setini yükle
train_dataset = load_from_disk("data/train_dataset")
test_dataset = load_from_disk("data/test_dataset")

# Tokenizer yükle
tokenizer = AutoTokenizer.from_pretrained("ytu-ce-cosmos/turkish-gpt2-large-750m-instruct-v0.1")

# Örnek bir veri öğesi göster
example = train_dataset[0]
print("Bölüm:", example['bolum'])
print("System:", example['messages'][0]['content'])
print("User:", example['messages'][1]['content'])
print("Correct Answer:", example['correct_answer'])
```

## Notlar

- Veri seti seed=42 ile rastgele karıştırılmıştır
- Tüm sorular 5 şıklıdır (A, B, C, D, E)
- Veri seti Türkçe'dir
- Bazı örneklerde `konu` alanı `None` olabilir

