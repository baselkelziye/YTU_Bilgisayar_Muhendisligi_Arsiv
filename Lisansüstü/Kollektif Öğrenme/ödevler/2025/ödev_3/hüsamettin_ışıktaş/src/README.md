# Modüler GRPO Eğitim Sistemi

Bu klasör, GRPO eğitim sisteminin modüler yapıya geçirilmiş halini içerir.

## 📁 Dosya Yapısı

```
src/
├── __init__.py           # Paket tanımlaması
├── config.py             # Tüm konfigürasyonlar (hyperparameter'lar)
├── reward_functions.py   # Ödül fonksiyonları (standart + alternatifler)
├── utils.py              # Yardımcı fonksiyonlar (parsing, formatting)
├── model_setup.py        # Model ve LoRA setup
├── training.py           # GRPO eğitim fonksiyonları
├── evaluation.py         # Model değerlendirme
└── main.py               # Ana entry point
```

## 🚀 Kullanım

### Basit Kullanım (Ana Script)

```bash
python grpo_training.py
```

Bu komut, `src/main.py`'deki `main()` fonksiyonunu çalıştırır ve tüm eğitim sürecini başlatır.

### Modüler Kullanım

```python
from src.main import main
main()
```

### Özel Konfigürasyon ile Kullanım

```python
from src.config import training_config, model_config
from src.model_setup import setup_model_and_data, setup_lora_model
from src.training import train_full_model

# Konfigürasyonu değiştir
training_config.num_epochs = 5
training_config.learning_rate = 2e-5

# Model ve veri yükle
base_model, tokenizer, train_dataset, test_dataset = setup_model_and_data()

# LoRA setup
model, lora_config = setup_lora_model(base_model)

# Eğitim
trained_model, trainer = train_full_model(
    model, tokenizer, train_dataset,
    num_epochs=5,
    num_generations=4
)
```

### Özel Ödül Fonksiyonu ile Eğitim

```python
from src.reward_functions import create_reward_function_wrapper
from src.training import train_full_model

# Kendi ödül fonksiyonunuzu tanımlayın
def my_custom_reward(completions, correct_answers):
    # ... özel ödül mantığı
    return rewards

# Wrapper oluştur
custom_reward_wrapper = create_reward_function_wrapper(
    train_dataset, 
    reward_func=my_custom_reward
)

# Eğitimde kullan
# (training.py içinde reward_func parametresi eklenebilir)
```

## 📝 Modül Açıklamaları

### `config.py`
Tüm hyperparameter'lar ve ayarlar burada merkezileştirilmiştir:
- `ModelConfig`: Model ayarları
- `LoRAConfig`: LoRA konfigürasyonu
- `TrainingConfig`: Eğitim ayarları
- `DataConfig`: Veri seti yolları
- `EvaluationConfig`: Değerlendirme ayarları

### `reward_functions.py`
- `reward_function_base()`: Standart ödül fonksiyonu
- `test_reward_function()`: Unit testler
- `create_reward_function_wrapper()`: GRPO için wrapper oluşturur

**Not:** Alternatif ödül fonksiyonları buraya eklenebilir.

### `utils.py`
Yardımcı fonksiyonlar:
- `format_dataset_for_grpo()`: Dataset formatlama
- `generate_answer_with_model()`: Model ile cevap üretme
- `parse_model_output()`: Model çıktısını parse etme

### `model_setup.py`
- `setup_model_and_data()`: Model ve dataset yükleme
- `setup_lora_model()`: LoRA konfigürasyonu

### `training.py`
- `dummy_run()`: Hızlı test için dummy run
- `train_full_model()`: Tam eğitim
- `save_trained_model()`: Model kaydetme

### `evaluation.py`
- `evaluate_model()`: Test seti değerlendirme
- `compare_with_baseline()`: Baseline ile karşılaştırma

### `main.py`
Ana entry point. Tüm adımları sırayla çalıştırır:
1. Ödül fonksiyonu testi
2. Model ve veri yükleme
3. LoRA setup
4. Dummy run
5. Tam eğitim
6. Değerlendirme
7. Baseline karşılaştırması

## 🔧 Konfigürasyon Değiştirme

Tüm ayarlar `src/config.py` dosyasında merkezileştirilmiştir:

```python
from src.config import training_config, model_config

# Eğitim ayarları
training_config.num_epochs = 5
training_config.learning_rate = 2e-5
training_config.num_generations = 4

# Model ayarları
model_config.model_name = "farklı-model-adı"
model_config.dtype = "bfloat16"
```

## 📦 Alternatif Ödül Fonksiyonları Ekleme

1. `src/reward_functions.py` dosyasına yeni fonksiyon ekleyin:

```python
def reward_function_1(completions, correct_answers):
    """Alternatif ödül fonksiyonu 1"""
    # ... ödül mantığı
    return rewards
```

2. `create_reward_function_wrapper()` ile kullanın:

```python
from src.reward_functions import create_reward_function_wrapper, reward_function_1

wrapper = create_reward_function_wrapper(
    dataset, 
    reward_func=reward_function_1
)
```

## 🎯 Avantajlar

✅ **Modüler Yapı**: Her modül bağımsız ve yeniden kullanılabilir  
✅ **Merkezi Konfigürasyon**: Tüm ayarlar tek yerde  
✅ **Kolay Genişletme**: Yeni ödül fonksiyonları kolayca eklenebilir  
✅ **Test Edilebilir**: Her modül bağımsız test edilebilir  
✅ **Temiz Kod**: Kod daha okunabilir ve bakımı kolay  

## 🔄 Eski Kod ile Uyumluluk

Eski `grpo_training.py` dosyası hala çalışır, ancak artık modüler yapıyı kullanır. 
Eski kodunuz varsa, aynı şekilde çalışmaya devam edecektir.
