"""
Base modeli (eğitilmemiş) test veri seti üzerinde değerlendirir.
Bu sonuçlar, eğitilmiş modellerle karşılaştırma (baseline) için kullanılır.
"""

import os
import json
import torch
import pandas as pd
from transformers import AutoTokenizer, AutoModelForCausalLM

from src.config import model_config, data_config, evaluation_config
from src.model_setup import setup_model_and_data
from src.evaluation import evaluate_model
from src.utils import generate_answer_with_model, parse_model_output

def main():
    print("="*60)
    print("BASELINE MODEL DEĞERLENDİRMESİ")
    print("="*60)
    
    # 1. Model ve Veri Setini Yükle
    # setup_model_and_data fonksiyonu base_model'i zaten yüklüyor
    # Ancak biz LoRA olmadan saf halini kullanmak istediğimizden emin olalım
    print("\nModel ve veri seti yükleniyor...")
    base_model, tokenizer, _, test_dataset = setup_model_and_data()
    
    # Modeli değerlendirme moduna al
    base_model.eval()
    
    # Test Modu Kontrolü (Hızlı deneme için config'den okur)
    if data_config.use_test_mode:
        test_size = int(len(test_dataset) * data_config.test_mode_fraction)
        test_dataset = test_dataset.select(range(test_size))
        print(f"\n⚠️  TEST MODU: Sadece {test_size} örnek kullanılacak.")
    
    # 2. Değerlendirme
    print(f"\nDeğerlendirme başlatılıyor ({len(test_dataset)} örnek)...")
    
    # Mevcut evaluate_model fonksiyonunu kullanıyoruz
    results, accuracy, format_accuracy = evaluate_model(base_model, tokenizer, test_dataset)
    
    # 3. Sonuçları Kaydet
    output_dir = os.path.join(data_config.results_dir, "baseline_results")
    os.makedirs(output_dir, exist_ok=True)
    
    # Dosya yolları
    csv_path = os.path.join(output_dir, "baseline_results.csv")
    json_path = os.path.join(output_dir, "baseline_results.json")
    summary_path = os.path.join(output_dir, "baseline_summary.json")
    
    # CSV Kaydet
    df = pd.DataFrame(results)
    df.drop(columns=['model_output'], errors='ignore').to_csv(csv_path, index=False, encoding='utf-8-sig')
    
    # JSON Kaydet
    with open(json_path, 'w', encoding='utf-8') as f:
        json.dump(results, f, ensure_ascii=False, indent=2)
        
    # Özet Kaydet
    summary = {
        "model_name": model_config.model_name,
        "accuracy": accuracy,
        "format_compliance": format_accuracy,
        "total_samples": len(test_dataset),
        "date": str(pd.Timestamp.now())
    }
    
    with open(summary_path, 'w', encoding='utf-8') as f:
        json.dump(summary, f, ensure_ascii=False, indent=2)
        
    print("\n" + "="*60)
    print("BASELINE SONUÇLARI")
    print("="*60)
    print(f"Model: {model_config.model_name}")
    print(f"Accuracy: {accuracy:.2f}%")
    print(f"Format Compliance: {format_accuracy:.2f}%")
    print(f"\nDosyalar kaydedildi:")
    print(f" -> {csv_path}")
    print(f" -> {summary_path}")

if __name__ == "__main__":
    main()
