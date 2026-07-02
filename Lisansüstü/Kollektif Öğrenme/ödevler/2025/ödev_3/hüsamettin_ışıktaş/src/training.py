"""
GRPO eğitim fonksiyonları
Dummy run ve tam eğitim fonksiyonları
"""

import torch
from trl import GRPOConfig, GRPOTrainer
import transformers
from .config import training_config, data_config
from .reward_functions import create_reward_function_wrapper
from .callbacks import CustomProgressCallback


def dummy_run(model, tokenizer, formatted_train_dataset, reward_func_name="simple"):
    """
    Dummy run: 4 örnek ile hızlı test
    
    Args:
        model: Eğitilecek model
        tokenizer: Tokenizer
        formatted_train_dataset: Formatlanmış train dataset
        reward_func_name: Kullanılacak ödül fonksiyonu ismi
    
    Returns:
        bool: Başarılı ise True
    """
    # print("\n" + "="*60)
    # print("DUMMY RUN: 4 örnek ile test")
    # print("="*60)
    
    # İlk 4 örneği al
    dummy_dataset = formatted_train_dataset.select(range(4))
    # print(f"Dummy dataset boyutu: {len(dummy_dataset)}")
    
    # GRPO config'i dummy run için
    dummy_grpo_config = GRPOConfig(
        num_generations=training_config.dummy_num_generations,
        max_completion_length=training_config.dummy_max_completion_length,
        temperature=training_config.temperature,
        top_p=training_config.top_p,
        learning_rate=training_config.learning_rate,
        per_device_train_batch_size=1,
        gradient_accumulation_steps=2,
        num_train_epochs=1,
        max_steps=training_config.dummy_max_steps,
        logging_steps=1,
        save_steps=100,
        output_dir=training_config.dummy_output_dir,
        remove_unused_columns=False,
        report_to=training_config.report_to,
    )
    
    # print(f"\nDummy run config:")
    # print(f"  num_generations: {dummy_grpo_config.num_generations}")
    # print(f"  max_completion_length: {dummy_grpo_config.max_completion_length}")
    # print(f"  max_steps: {dummy_grpo_config.max_steps}")
    
    # Dummy reward fonksiyonu
    dummy_reward_function = create_reward_function_wrapper(dummy_dataset, reward_func_name)
    
    # print("\nDummy run başlatılıyor...")
    try:
        trainer = GRPOTrainer(
            model=model,
            args=dummy_grpo_config,
            train_dataset=dummy_dataset,
            reward_funcs=dummy_reward_function,
            processing_class=tokenizer,
        )
        
        # print("Trainer oluşturuldu. Eğitim başlatılıyor...")
        train_result = trainer.train()
        
        print("\n✓ Dummy run başarılı!")
        # print(f"  Loss: {train_result.training_loss:.4f}")
        # print("  Eğitim sistemi çalışıyor, tam eğitime geçilebilir.")
        return True
        
    except Exception as e:
        print(f"\n✗ Dummy run hatası: {e}")
        # print("  Hata detayları yukarıda gösterildi. Lütfen düzeltin.")
        import traceback
        traceback.print_exc()
        return False


def train_full_model(model, tokenizer, formatted_train_dataset, 
                     num_epochs: int = None, num_generations: int = None,
                     custom_config: GRPOConfig = None, callbacks: list = None,
                     reward_func_name="simple"):
    """
    Tam veri seti ile GRPO eğitimi
    
    Args:
        model: Eğitilecek model
        tokenizer: Tokenizer
        formatted_train_dataset: Formatlanmış train dataset
        num_epochs: Epoch sayısı (None ise config'den alınır)
        num_generations: Generation sayısı (None ise config'den alınır)
        custom_config: Özel GRPO config (None ise config'den oluşturulur)
        callbacks: İsteğe bağlı callback listesi
        reward_func_name: Kullanılacak ödül fonksiyonu ismi
    
    Returns:
        tuple: (trained_model, trainer) veya (None, None) hata durumunda
    """
    # print("\n" + "="*60)
    # print("TAM EĞİTİM BAŞLATILIYOR")
    # print("="*60)
    # print(f"Train dataset boyutu: {len(formatted_train_dataset)} örnek")
    
    if num_epochs is None:
        num_epochs = training_config.num_train_epochs
    if num_generations is None:
        num_generations = training_config.num_generations
    
    # Tam eğitim için GRPO config
    if custom_config is None:
        # Mixed precision ayarları
        use_bf16 = torch.cuda.is_available() and torch.cuda.is_bf16_supported()
        use_fp16 = torch.cuda.is_available() and not torch.cuda.is_bf16_supported()
        
        # GRPOConfig parametreleri - max_steps None ise ekleme
        config_params = {
            "num_generations": num_generations,
            "max_completion_length": training_config.max_completion_length,
            "temperature": training_config.temperature,
            "top_p": training_config.top_p,
            "learning_rate": training_config.learning_rate,
            "per_device_train_batch_size": training_config.per_device_train_batch_size,
            "gradient_accumulation_steps": training_config.gradient_accumulation_steps,
            "num_train_epochs": num_epochs,
            "logging_steps": training_config.logging_steps,
            "save_steps": training_config.save_steps,
            "output_dir": training_config.output_dir,
            "save_total_limit": training_config.save_total_limit,
            "remove_unused_columns": False,
            "report_to": training_config.report_to,
            "bf16": use_bf16,
            "fp16": use_fp16,
        }
        
        # max_steps sadece None değilse ekle
        if training_config.max_steps is not None:
            config_params["max_steps"] = training_config.max_steps
        
        full_grpo_config = GRPOConfig(**config_params)
    else:
        full_grpo_config = custom_config
    
    # print("\nTam eğitim GRPO Konfigürasyonu:")
    # print(f"  num_generations: {full_grpo_config.num_generations}")
    # print(f"  max_completion_length: {full_grpo_config.max_completion_length}")
    # print(f"  per_device_train_batch_size: {full_grpo_config.per_device_train_batch_size}")
    # print(f"  gradient_accumulation_steps: {full_grpo_config.gradient_accumulation_steps}")
    # print(f"  Effective batch size: {full_grpo_config.per_device_train_batch_size * full_grpo_config.gradient_accumulation_steps}")
    # print(f"  num_train_epochs: {full_grpo_config.num_train_epochs}")
    
    # Full reward fonksiyonu
    full_reward_function = create_reward_function_wrapper(formatted_train_dataset, reward_func_name)
    
    # Varsayılan callback (eğer dışarıdan verilmediyse)
    if callbacks is None:
        from .config import data_config
        # Logs klasörünü oluştur
        import os
        # Log dizinini ödül fonksiyonuna göre özelleştir
        log_dir = os.path.join(data_config.results_dir, f"logs_{reward_func_name}")
        os.makedirs(log_dir, exist_ok=True)
        callbacks = [CustomProgressCallback(log_dir=log_dir)]
    
    try:
        trainer = GRPOTrainer(
            model=model,
            args=full_grpo_config,
            train_dataset=formatted_train_dataset,
            reward_funcs=full_reward_function,
            processing_class=tokenizer,
            callbacks=callbacks,
        )
        
        # Varsayılan callback'leri temizle (eğer özel callback varsa)
        if callbacks:
            # Sadece PrinterCallback'i kaldırıyoruz, ProgressCallback (tqdm) kalıyor
            if trainer.pop_callback(transformers.trainer_callback.PrinterCallback):
                pass
        
        print("\nEğitim başlatılıyor...")
        # print("Bu işlem uzun sürebilir. Lütfen bekleyin...\n")
        
        train_result = trainer.train()
        
        # print("\n" + "="*60)
        print("✓ EĞİTİM TAMAMLANDI!")
        # print("="*60)
        print(f"Final training loss: {train_result.training_loss:.4f}")
        print(f"Train runtime: {train_result.metrics.get('train_runtime', 'N/A')} saniye")
        
        return model, trainer
        
    except Exception as e:
        print(f"\n✗ Eğitim hatası: {e}")
        import traceback
        traceback.print_exc()
        return None, None


def save_trained_model(model, tokenizer, output_dir: str = None):
    """
    Eğitilmiş LoRA adaptörlerini kaydeder
    
    Args:
        model: Eğitilmiş model
        tokenizer: Tokenizer
        output_dir: Kayıt dizini (None ise config'den alınır)
    """
    if output_dir is None:
        output_dir = data_config.standard_reward_model_dir
    
    import os
    print(f"\nModel kaydediliyor: {output_dir}")
    os.makedirs(output_dir, exist_ok=True)
    model.save_pretrained(output_dir)
    tokenizer.save_pretrained(output_dir)
    print(f"✓ Model kaydedildi: {output_dir}")
    print(f"  LoRA adaptörleri: {output_dir}/adapter_model.bin")
    print(f"  LoRA config: {output_dir}/adapter_config.json")
