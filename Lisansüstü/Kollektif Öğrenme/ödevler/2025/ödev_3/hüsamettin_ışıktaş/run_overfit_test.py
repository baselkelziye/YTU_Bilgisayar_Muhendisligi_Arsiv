import torch
from trl import GRPOConfig
import transformers
from src.model_setup import setup_model_and_data, setup_lora_model
from src.training import train_full_model
from src.utils import generate_answer_with_model
from src.callbacks import CustomProgressCallback
import logging

# Log seviyesini ayarla
logging.basicConfig(level=logging.INFO)

# Transformers loglarını sustur (sadece hata mesajları görünsün)
transformers.utils.logging.set_verbosity_error()

def run_overfit_test():
    print("="*60)
    print("OVERFITTING TESTİ (HIZLI DOĞRULAMA) BAŞLATILIYOR")
    print("Amaç: Modelin 15 örneklik küçük bir veri setini ezberleyip ezberleyemediğini kontrol etmek.")
    print("Beklenti: Loss azalmalı, Reward artmalı ve model doğru formatı kullanmalı.")
    print("="*60)

    # 1. Modeli ve veriyi yükle
    base_model, tokenizer, formatted_train_dataset, _ = setup_model_and_data()

    # 2. Sadece 15 örnek seç (Ezberlemesi kolay olsun)
    mini_dataset = formatted_train_dataset.select(range(15))
    
    # --- PROMPT MANİPÜLASYONU: Modele Kopya Ver ---
    def append_thought_token(example):
        # Prompt'un sonuna <düşünce> etiketini ekle
        example['prompt'] = example['prompt'] + "\n<düşünce>"
        return example
    
    mini_dataset = mini_dataset.map(append_thought_token)
    print(f"\nTest için {len(mini_dataset)} örnek seçildi ve promptlara <düşünce> eklendi.")
    # ---------------------------------------------

    # 3. LoRA Hazırlığı
    # Model kartındaki parametrelere yaklaşıyoruz (Rank artırıldı)
    # Orijinal model r=256, alpha=512 ile eğitilmiş.
    # Biz r=64, alpha=128 ile "orta karar" devam ediyoruz.
    from src.config import lora_config
    lora_config.r = 64
    lora_config.lora_alpha = 128
    
    model, _ = setup_lora_model(base_model)

    # 4. Overfit için özel konfigürasyon
    # Epoch sayısını artırıyoruz (15), böylece modelin ezberlemesi için şans veriyoruz.
    overfit_config = GRPOConfig(
        output_dir="results/overfit_test",
        run_name="grpo-overfit-test",
        learning_rate=2e-5,          # LR normale döndürüldü (5e-5 çok agresifti)
        adam_beta1=0.9,
        adam_beta2=0.99,
        weight_decay=0.1,
        warmup_ratio=0.1,
        lr_scheduler_type='cosine',
        logging_steps=1,             # Her adımda log gör
        bf16=torch.cuda.is_available() and torch.cuda.is_bf16_supported(),
        fp16=torch.cuda.is_available() and not torch.cuda.is_bf16_supported(),
        per_device_train_batch_size=8,
        gradient_accumulation_steps=1, # Update sık olsun
        num_generations=4,
        max_prompt_length=512,
        max_completion_length=512,
        num_train_epochs=15,         # 15 epoch döndür (iyice ezberlesin)
        save_steps=1000,             # Kaydetmeye gerek yok
        max_grad_norm=0.1,
        report_to="none",            # WandB vb. kapalı
        use_vllm=False               # VLLM kapalı
    )

    print("\nEğitim Konfigürasyonu:")
    print(f"  Epochs: {overfit_config.num_train_epochs} (Modelin veriyi defalarca görmesi için)")
    print(f"  Learning Rate: {overfit_config.learning_rate}")
    print(f"  Batch Size: {overfit_config.per_device_train_batch_size}")

    # 5. Eğitimi Başlat
    print("\nEğitim başlıyor... Lütfen 'reward' sütununun arttığını takip edin.")
    
    # Temiz loglama için callback listesi
    callbacks = [CustomProgressCallback()]
    
    trained_model, trainer = train_full_model(
        model, 
        tokenizer, 
        mini_dataset, 
        custom_config=overfit_config,
        callbacks=callbacks
    )

    if trained_model:
        print("\n" + "="*60)
        print("TEST SONUÇLARI VE KONTROL")
        print("="*60)
        
        # Eğitim verisi üzerinden bir örneği test et (Ezberlemiş mi?)
        print("\nEğitim verisinden bir örnek üzerinde test yapılıyor...")
        sample = mini_dataset[0]
        
        # Mesajları al
        messages = sample['messages']
        
        print(f"\nSoru: {messages[-1]['content']}")
        print(f"Doğru Cevap: {sample['correct_answer']}")
        
        # Model tahmini
        response = generate_answer_with_model(trained_model, tokenizer, messages)
        print(f"\nModel Cevabı:\n{'-'*20}\n{response}\n{'-'*20}")
        
        print("\nKARAR REHBERİ:")
        print("✅ BAŞARILI: Eğer Reward 1.0-2.0 seviyelerine çıktıysa ve yukarıdaki cevap doğru formattaysa (<düşünce>...<cevap>).")
        print("❌ BAŞARISIZ: Eğer Reward 0 civarında kaldıysa veya model anlamsız şeyler üretiyorsa.")
        print("\nBaşarılı ise, 3 saatlik eğitimi güvenle başlatabilirsiniz.")
    else:
        print("\nEğitim başlatılamadı veya hata aldı.")

if __name__ == "__main__":
    run_overfit_test()
