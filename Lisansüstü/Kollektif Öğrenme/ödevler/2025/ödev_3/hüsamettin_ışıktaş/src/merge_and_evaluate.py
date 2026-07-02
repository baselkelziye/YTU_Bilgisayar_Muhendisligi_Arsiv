"""
En iyi performans gösteren iki modelin birleştirilmesi ve değerlendirilmesi.
"""

import os
import glob
import json
import torch
from peft import PeftModel
import pandas as pd
from typing import List, Tuple

from .config import model_config, data_config, evaluation_config
from .model_setup import setup_model_and_data
from .evaluation import evaluate_model


def find_best_two_models(results_dir: str = "results") -> List[Tuple[str, float, str]]:
    """
    Results klasöründeki karşılaştırma dosyalarını tarar ve en iyi 2 modeli bulur.
    
    Returns:
        List[(model_name, accuracy, model_path)]
    """
    print(f"Sonuç dosyaları taranıyor: {results_dir} ...")
    
    # training_comparison_results_*.json dosyalarını bul
    pattern = os.path.join(results_dir, "training_comparison_results_*.json")
    files = glob.glob(pattern)
    
    model_performances = []
    
    for file_path in files:
        try:
            # Dosya adından model ismini çıkar (örn: training_comparison_results_short.json -> short)
            filename = os.path.basename(file_path)
            # "training_comparison_results_" prefixini ve ".json" suffixini at
            model_name = filename.replace("training_comparison_results_", "").replace(".json", "")
            
            with open(file_path, "r", encoding="utf-8") as f:
                data = json.load(f)
                
            # Accuracy değerini al
            accuracy = data.get("trained_model", {}).get("accuracy", 0.0)
            
            # Model yolunu tahmin et
            model_path = f"./models/reward_model_{model_name}"
            
            # Eğer model dosyası gerçekten varsa listeye ekle
            if os.path.exists(model_path):
                model_performances.append((model_name, accuracy, model_path))
            else:
                print(f"⚠️  Uyarı: {model_name} için sonuç var ama model dosyası bulunamadı ({model_path})")
                
        except Exception as e:
            print(f"Hata: {file_path} okunurken sorun oluştu - {e}")
    
    # Accuracy'ye göre sırala (büyükten küçüğe)
    sorted_models = sorted(model_performances, key=lambda x: x[1], reverse=True)
    
    return sorted_models[:2]


def merge_models(base_model, model1_info, model2_info):
    """
    İki LoRA modelini ağırlıklı ortalama ile birleştirir.
    
    Args:
        base_model: Base model objesi
        model1_info: (name, accuracy, path)
        model2_info: (name, accuracy, path)
    
    Returns:
        merged_model: Birleştirilmiş model
    """
    name1, acc1, path1 = model1_info
    name2, acc2, path2 = model2_info
    
    print(f"\nModeller birleştiriliyor:")
    print(f"  1. Model: {name1} (Accuracy: {acc1:.2f}%) - Path: {path1}")
    print(f"  2. Model: {name2} (Accuracy: {acc2:.2f}%) - Path: {path2}")
    
    # İlk adaptörü yükle
    print(f"  > '{name1}' adaptörü yükleniyor...")
    model = PeftModel.from_pretrained(
        base_model,
        path1,
        adapter_name=name1,
        dtype=torch.float16 if torch.cuda.is_available() else torch.float32
    )
    
    # İkinci adaptörü yükle
    print(f"  > '{name2}' adaptörü yükleniyor...")
    model.load_adapter(path2, adapter_name=name2)
    
    # Adaptörleri birleştir (Weighted Linear Combination)
    # Eşit ağırlık veriyoruz: 0.5 - 0.5
    print(f"  > Adaptörler birleştiriliyor (Weights: 0.5, 0.5)...")
    model.add_weighted_adapter(
        adapters=[name1, name2],
        weights=[0.5, 0.5],
        adapter_name="merged",
        combination_type="linear"
    )
    
    # Birleştirilmiş adaptörü aktif et
    model.set_adapter("merged")
    print(f"✓ Birleştirme tamamlandı. Aktif adaptör: 'merged'")
    
    return model


def main():
    print("="*60)
    print("MODEL BİRLEŞTİRME VE DEĞERLENDİRME")
    print("="*60)
    
    # 1. En iyi 2 modeli bul
    best_models = find_best_two_models()
    
    if len(best_models) < 2:
        print("\n❌ Yeterli model bulunamadı!")
        print(f"Bulunan model sayısı: {len(best_models)}")
        print("Lütfen önce en az 2 farklı ödül fonksiyonu ile eğitim yapın.")
        return
    
    print(f"\nEn iyi 2 model seçildi:")
    for i, (name, acc, path) in enumerate(best_models, 1):
        print(f"  {i}. {name} (Acc: {acc:.2f}%)")
        
    # 2. Base Modeli ve Test Verisini Yükle
    print("\nBase model ve test verisi yükleniyor...")
    base_model, tokenizer, _, test_dataset = setup_model_and_data()
    
    # Test Modu Kontrolü (Hızlı deneme için)
    if data_config.use_test_mode:
        test_size = int(len(test_dataset) * data_config.test_mode_fraction)
        test_dataset = test_dataset.select(range(test_size))
        print(f"⚠️  TEST MODU: Sadece {test_size} örnek kullanılacak.")
        
    # 3. Modelleri Birleştir
    merged_model = merge_models(base_model, best_models[0], best_models[1])
    
    # 4. Değerlendirme
    print("\n" + "="*60)
    print("BİRLEŞTİRİLMİŞ MODEL DEĞERLENDİRİLİYOR")
    print("="*60)
    
    merged_results, merged_accuracy, merged_format_accuracy = evaluate_model(merged_model, tokenizer, test_dataset)
    
    # 5. Sonuçları Kaydet
    output_suffix = f"merged_{best_models[0][0]}_{best_models[1][0]}"
    results_csv_path = f"results/trained_model_results_{output_suffix}.csv"
    results_json_path = f"results/trained_model_results_{output_suffix}.json"
    
    df_results = pd.DataFrame(merged_results)
    df_results.drop(columns=['model_output'], errors='ignore').to_csv(results_csv_path, index=False, encoding='utf-8-sig')
    df_results.to_json(results_json_path, orient='records', indent=2, force_ascii=False)
    
    print("\n" + "="*60)
    print("BİRLEŞTİRME SONUCU")
    print("="*60)
    print(f"Kullanılan Modeller: {best_models[0][0]} + {best_models[1][0]}")
    print(f"Merged Accuracy: {merged_accuracy:.2f}%")
    print(f"Merged Format Compliance: {merged_format_accuracy:.2f}%")
    print(f"Sonuçlar kaydedildi: {results_csv_path}")
    
    # Karşılaştırma Raporu
    print("\nPerformans Karşılaştırması:")
    print(f"  1. {best_models[0][0]}: {best_models[0][1]:.2f}%")
    print(f"  2. {best_models[1][0]}: {best_models[1][1]:.2f}%")
    print(f"  --> Merged Model: {merged_accuracy:.2f}%")
    
    if merged_accuracy > best_models[0][1]:
        print(f"  ✓ BAŞARILI! Birleştirme sonucu en iyi tekil modelden daha iyi (+{merged_accuracy - best_models[0][1]:.2f}%)")
    else:
        print(f"  - Birleştirme sonucu en iyi tekil modelden düşük ({merged_accuracy - best_models[0][1]:.2f}%)")


if __name__ == "__main__":
    main()
