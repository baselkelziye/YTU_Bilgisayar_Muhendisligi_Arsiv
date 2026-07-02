"""
Ana entry point
Tüm adımları sırayla çalıştırır
"""

import torch
import argparse
import sys
from peft import PeftModel

from .config import model_config, data_config, training_config, evaluation_config
from .reward_functions import test_reward_function
from .model_setup import setup_model_and_data, setup_lora_model
from .training import dummy_run, train_full_model, save_trained_model
from .evaluation import evaluate_model, compare_with_baseline


def parse_args():
    parser = argparse.ArgumentParser(description="GRPO Eğitimi")
    parser.add_argument("--reward_function", type=str, default="short", 
                        choices=["short", "long", "turkish", "connectives", "simple"],
                        help="Kullanılacak ödül fonksiyonu (short, long, turkish, connectives)")
    return parser.parse_args()


def main():
    """Ana fonksiyon: Tüm adımları sırayla çalıştırır"""
    
    # Argümanları parse et
    args = parse_args()
    reward_func_name = args.reward_function
    
    print("="*60)
    print(f"GRPO EĞİTİMİ BAŞLATIYOR - Ödül Fonksiyonu: {reward_func_name}")
    print("="*60)
    
    # Configleri güncelle (Dinamik isimlendirme)
    suffix = f"_{reward_func_name}"
    
    # Model kayıt dizinlerini güncelle
    original_model_dir = data_config.standard_reward_model_dir
    data_config.standard_reward_model_dir = f"./models/reward_model{suffix}"
    training_config.output_dir = f"./models/reward_model{suffix}/checkpoints"
    
    # Sonuç dosyalarını güncelle
    evaluation_config.trained_results_csv_path = f"results/trained_model_results{suffix}.csv"
    evaluation_config.trained_results_json_path = f"results/trained_model_results{suffix}.json"
    evaluation_config.comparison_results_path = f"results/training_comparison_results{suffix}.json"
    
    print(f"Ayarlar güncellendi:")
    print(f"  Model kayıt dizini: {data_config.standard_reward_model_dir}")
    print(f"  Checkpoint dizini: {training_config.output_dir}")
    print(f"  Sonuç CSV: {evaluation_config.trained_results_csv_path}")
    print(f"  Sonuç JSON: {evaluation_config.trained_results_json_path}")
    
    # FAZ 3: Ödül fonksiyonu testi
    # print("\n[FAZ 3] Ödül fonksiyonu test ediliyor...")
    test_reward_function()
    
    # Model ve veri setlerini yükle
    base_model, tokenizer, formatted_train_dataset, test_dataset = setup_model_and_data()
    
    # Test modu: Veri setinin %10'unu kullan (hızlı test için)
    if data_config.use_test_mode:
        original_size = len(formatted_train_dataset)
        test_size = int(original_size * data_config.test_mode_fraction)
        formatted_train_dataset = formatted_train_dataset.select(range(test_size))
        print(f"\n⚠️  TEST MODU AKTİF: Veri setinin %{data_config.test_mode_fraction*100:.0f}'u kullanılıyor")
        print(f"  Orijinal boyut: {original_size} örnek")
        print(f"  Test boyutu: {test_size} örnek")
        print(f"  Eğitim süresi yaklaşık {data_config.test_mode_fraction*100:.0f}% daha hızlı olacak\n")
    
    # LoRA modeli hazırla
    model, lora_config = setup_lora_model(base_model)
    
    # FAZ 4: Dummy run
    # print("\n[FAZ 4] Dummy run başlatılıyor...")
    # Ödül fonksiyonu ismini geçiriyoruz
    dummy_success = dummy_run(model, tokenizer, formatted_train_dataset, reward_func_name=reward_func_name)
    
    if not dummy_success:
        print("\n⚠️  Dummy run başarısız! Lütfen hataları düzeltin ve tekrar deneyin.")
        return
    
    # print("\n" + "="*60)
    # print("DUMMY RUN BAŞARILI - TAM EĞİTİME BAŞLANIYOR")
    # print("="*60)
    
    # FAZ 5: Tam eğitim
    # print("\n[FAZ 5] Tam eğitim başlatılıyor...")
    trained_model, trainer = train_full_model(
        model, tokenizer, formatted_train_dataset, 
        num_epochs=training_config.num_train_epochs, 
        num_generations=training_config.num_generations,
        reward_func_name=reward_func_name
    )
    
    if trained_model is None:
        print("\n⚠️  Eğitim başarısız!")
        return
    
    # Modeli kaydet
    save_trained_model(trained_model, tokenizer)
    
    # Eğitilmiş modeli yükle ve değerlendir
    print("\nEğitilmiş model yükleniyor...")
    # Clean up GPU memory before loading new model
    del model
    del trained_model
    del trainer
    torch.cuda.empty_cache()
    
    trained_model = PeftModel.from_pretrained(
        base_model,
        data_config.standard_reward_model_dir,
        dtype=torch.float16 if torch.cuda.is_available() else torch.float32
    )
    trained_model.eval()
    
    # Değerlendirme
    trained_results, trained_accuracy, trained_format_accuracy = evaluate_model(trained_model, tokenizer, test_dataset)
    
    # Baseline ile karşılaştır
    compare_with_baseline(trained_accuracy, trained_format_accuracy)
    
    print("\n" + "="*60)
    print("EĞİTİM VE DEĞERLENDİRME TAMAMLANDI")
    print("="*60)
    print("\nÖzet:")
    print(f"  ✓ Model eğitildi ve kaydedildi: {data_config.standard_reward_model_dir}")
    print(f"  ✓ Test seti değerlendirildi: {len(test_dataset)} örnek")
    print(f"  ✓ Final accuracy: {trained_accuracy:.2f}%")
    print(f"  ✓ Format compliance: {trained_format_accuracy:.2f}%")
    print(f"  ✓ Sonuçlar kaydedildi: {evaluation_config.trained_results_csv_path}")
    print("\nSıradaki adım: Alternatif ödül fonksiyonları ile eğitim")


if __name__ == "__main__":
    main()
