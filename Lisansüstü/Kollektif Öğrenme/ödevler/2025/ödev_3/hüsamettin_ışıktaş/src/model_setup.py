"""
Model ve LoRA setup fonksiyonları
Model yükleme, LoRA konfigürasyonu ve veri seti hazırlama
"""

import torch
from datasets import load_from_disk
from transformers import AutoTokenizer, AutoModelForCausalLM
from peft import LoraConfig, get_peft_model, TaskType

from .config import model_config, lora_config, data_config
from .utils import format_dataset_for_grpo


def setup_model_and_data(model_name: str = None):
    """
    Modeli ve veri setlerini yükler
    
    Args:
        model_name: Model adı (None ise config'den alınır)
    
    Returns:
        tuple: (base_model, tokenizer, formatted_train_dataset, test_dataset)
    """
    if model_name is None:
        model_name = model_config.model_name
    
    # print("\n" + "="*60)
    # print("MODEL VE VERİ SETİ YÜKLEME")
    # print("="*60)
    
    # Veri setlerini yükle
    # print("\nVeri setleri yükleniyor...")
    train_dataset = load_from_disk(data_config.train_dataset_path)
    test_dataset = load_from_disk(data_config.test_dataset_path)
    
    # print(f"Train seti: {len(train_dataset)} örnek")
    # print(f"Test seti: {len(test_dataset)} örnek")
    
    # Model ve tokenizer'ı yükle
    print(f"\nModel yükleniyor: {model_name}")
    tokenizer = AutoTokenizer.from_pretrained(model_name)
    
    # Dtype belirleme
    if model_config.use_cuda and torch.cuda.is_available():
        if model_config.dtype == "float16":
            dtype = torch.float16
        elif model_config.dtype == "bfloat16":
            dtype = torch.bfloat16
        else:
            dtype = torch.float32
    else:
        dtype = torch.float32
    
    base_model = AutoModelForCausalLM.from_pretrained(
        model_name,
        dtype=dtype,
        device_map="auto" if (model_config.use_cuda and torch.cuda.is_available()) else None
    )
    
    if tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token
    
    print(f"Model yüklendi. Cihaz: {next(base_model.parameters()).device}")
    # print(f"CUDA kullanılabilir: {torch.cuda.is_available()}")
    # if torch.cuda.is_available():
    #     print(f"GPU: {torch.cuda.get_device_name(0)}")
    #     print(f"VRAM: {torch.cuda.get_device_properties(0).total_memory / 1024**3:.2f} GB")
    
    # Veri setini formatla
    # print("\nVeri seti GRPO formatına dönüştürülüyor...")
    # Tokenizer'ı fn_kwargs ile geçiyoruz
    formatted_train_dataset = train_dataset.map(
        format_dataset_for_grpo, 
        remove_columns=train_dataset.column_names,
        fn_kwargs={"tokenizer": tokenizer}
    )
    # print(f"Formatlanmış train seti: {len(formatted_train_dataset)} örnek")
    
    return base_model, tokenizer, formatted_train_dataset, test_dataset


def setup_lora_model(base_model, custom_lora_config=None):
    """
    LoRA konfigürasyonunu hazırlar ve modele uygular
    
    Args:
        base_model: Base model
        custom_lora_config: Özel LoRA config (None ise global config kullanılır)
    
    Returns:
        tuple: (model, lora_config)
    """
    # print("\n" + "="*60)
    # print("LORA KONFİGÜRASYONU")
    # print("="*60)
    
    if custom_lora_config is None:
        config = lora_config
    else:
        config = custom_lora_config
    
    lora_config_obj = LoraConfig(
        task_type=TaskType.CAUSAL_LM,
        r=config.r,
        lora_alpha=config.lora_alpha,
        lora_dropout=config.lora_dropout,
        target_modules=config.target_modules,
        bias=config.bias,
    )
    
    # print("\nLoRA konfigürasyonu:")
    # print(f"  r (rank): {lora_config_obj.r}")
    # print(f"  alpha: {lora_config_obj.lora_alpha}")
    # print(f"  dropout: {lora_config_obj.lora_dropout}")
    # print(f"  target_modules: {lora_config_obj.target_modules}")
    
    # LoRA'yı modele uygula
    model = get_peft_model(base_model, lora_config_obj)
    model.print_trainable_parameters()
    
    return model, lora_config_obj
