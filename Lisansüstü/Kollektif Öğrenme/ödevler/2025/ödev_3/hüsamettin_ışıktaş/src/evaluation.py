"""
Model değerlendirme fonksiyonları
Test seti değerlendirme ve baseline karşılaştırma
"""

import os
import json
import pandas as pd
from tqdm import tqdm

from .config import evaluation_config, data_config
from .utils import generate_answer_with_model, parse_model_output


def evaluate_model(model, tokenizer, test_dataset):
    """
    Eğitilmiş modeli test seti üzerinde değerlendirir
    
    Args:
        model: Eğitilmiş model
        tokenizer: Tokenizer
        test_dataset: Test dataset
    
    Returns:
        tuple: (trained_results, trained_accuracy, trained_format_accuracy)
    """
    # print("\n" + "="*60)
    # print("EĞİTİLMİŞ MODELİ DEĞERLENDİRME")
    # print("="*60)
    
    # print("Test seti değerlendiriliyor (eğitilmiş model ile)...")
    # print(f"Toplam {len(test_dataset)} örnek işlenecek.\n")
    
    trained_results = []
    
    for i, example in enumerate(tqdm(test_dataset, desc="Değerlendirme")):
        model_output = generate_answer_with_model(
            model, tokenizer, example['messages'], 
            max_new_tokens=evaluation_config.max_new_tokens
        )
        düşünce, predicted_answer, format_uygun = parse_model_output(model_output)
        
        result = {
            'index': i,
            'bolum': example.get('bolum', 'unknown'),
            'konu': example.get('konu', None),
            'correct_answer': example['correct_answer'],
            'predicted_answer': predicted_answer,
            'is_correct': (predicted_answer == example['correct_answer']) if predicted_answer else False,
            'format_uygun': format_uygun,
            'düşünce_length': len(düşünce) if düşünce else 0,
            'model_output': model_output,  # Tam model çıktısını da kaydet
        }
        trained_results.append(result)
    
    # print(f"\nDeğerlendirme tamamlandı. {len(trained_results)} örnek işlendi.")
    
    # Sonuçları analiz et
    df_trained = pd.DataFrame(trained_results)
    
    total = len(df_trained)
    correct = df_trained['is_correct'].sum()
    format_compliant = df_trained['format_uygun'].sum()
    
    trained_accuracy = correct / total * 100
    trained_format_accuracy = format_compliant / total * 100
    
    print("\n" + "="*60)
    print("EĞİTİLMİŞ MODEL DEĞERLENDİRME SONUÇLARI")
    print("="*60)
    print(f"\n📊 GENEL İSTATİSTİKLER:")
    print(f"  Toplam örnek sayısı: {total}")
    print(f"  Doğru cevap sayısı: {correct}")
    print(f"  Format uygun örnek sayısı: {format_compliant}")
    
    print(f"\n✅ DOĞRULUK METRİKLERİ:")
    print(f"  Accuracy: {trained_accuracy:.2f}%")
    print(f"  Format Compliance: {trained_format_accuracy:.2f}%")
    
    # Sonuçları kaydet
    os.makedirs(data_config.results_dir, exist_ok=True)
    
    # CSV olarak kaydet (model_output olmadan, çünkü CSV'de uzun metinler sorun olabilir)
    results_csv_path = evaluation_config.trained_results_csv_path
    df_trained_csv = df_trained.drop(columns=['model_output'])
    df_trained_csv.to_csv(results_csv_path, index=False, encoding='utf-8-sig')
    print(f"\n✓ Sonuçlar CSV olarak kaydedildi: {results_csv_path}")
    
    # JSON olarak kaydet (tam çıktı ile, baseline_results.json gibi)
    results_json_path = evaluation_config.trained_results_json_path
    df_trained.to_json(results_json_path, orient='records', indent=2, force_ascii=False)
    print(f"✓ Sonuçlar JSON olarak kaydedildi: {results_json_path} (tam çıktı için önerilir)")
    
    return trained_results, trained_accuracy, trained_format_accuracy


def compare_with_baseline(trained_accuracy, trained_format_accuracy):
    """
    Baseline sonuçları ile karşılaştırma yapar
    
    Args:
        trained_accuracy: Eğitilmiş model accuracy
        trained_format_accuracy: Eğitilmiş model format accuracy
    """
    baseline_summary_path = evaluation_config.baseline_summary_path
    
    try:
        with open(baseline_summary_path, "r", encoding="utf-8") as f:
            baseline_summary = json.load(f)
        
        baseline_accuracy = baseline_summary.get('accuracy', 0)
        baseline_format = baseline_summary.get('format_compliance', 0)
        
        print("\n" + "="*60)
        print("BASELINE vs EĞİTİLMİŞ MODEL KARŞILAŞTIRMASI")
        print("="*60)
        
        print(f"\n📊 ACCURACY KARŞILAŞTIRMASI:")
        print(f"  Baseline (Eğitimsiz):     {baseline_accuracy:.2f}%")
        print(f"  Eğitilmiş Model:          {trained_accuracy:.2f}%")
        improvement = trained_accuracy - baseline_accuracy
        if baseline_accuracy > 0:
            print(f"  İyileşme:                  {improvement:+.2f}% ({improvement/baseline_accuracy*100:+.1f}% göreceli)")
        else:
            print(f"  İyileşme:                  {improvement:+.2f}%")
        
        print(f"\n📋 FORMAT COMPLIANCE KARŞILAŞTIRMASI:")
        print(f"  Baseline (Eğitimsiz):     {baseline_format:.2f}%")
        print(f"  Eğitilmiş Model:          {trained_format_accuracy:.2f}%")
        format_improvement = trained_format_accuracy - baseline_format
        if baseline_format > 0:
            print(f"  İyileşme:                  {format_improvement:+.2f}% ({format_improvement/baseline_format*100:+.1f}% göreceli)")
        else:
            print(f"  İyileşme:                  {format_improvement:+.2f}%")
        
        # Sonuçları JSON olarak kaydet
        # Not: Hem baseline_format hem de trained_format_accuracy yüzde olarak kaydedilmiş
        # (örn: 0.4 = 0.4%, 0.8 = 0.8%)
        comparison_results = {
            "baseline": {
                "accuracy": baseline_accuracy,  # Yüzde olarak (örn: 13.2 = 13.2%)
                "format_compliance": baseline_format  # Yüzde olarak (örn: 0.4 = 0.4%)
            },
            "trained_model": {
                "accuracy": float(trained_accuracy),  # Yüzde olarak (örn: 10.4 = 10.4%)
                "format_compliance": float(trained_format_accuracy)  # Yüzde olarak (örn: 0.8 = 0.8%)
            },
            "improvement": {
                "accuracy_absolute": float(improvement),
                "accuracy_relative_percent": float(improvement/baseline_accuracy*100) if baseline_accuracy > 0 else 0,
                "format_absolute": float(format_improvement),
                "format_relative_percent": float(format_improvement/baseline_format*100) if baseline_format > 0 else 0
            }
        }
        
        os.makedirs(data_config.results_dir, exist_ok=True)
        comparison_json_path = evaluation_config.comparison_results_path
        with open(comparison_json_path, "w", encoding="utf-8") as f:
            json.dump(comparison_results, f, ensure_ascii=False, indent=2)
        
        print(f"\n✓ Karşılaştırma sonuçları kaydedildi: {comparison_json_path}")
        
    except FileNotFoundError:
        print(f"\n⚠️  Baseline sonuçları bulunamadı ({baseline_summary_path})")
        print("  Baseline değerlendirmeyi çalıştırdığınızdan emin olun.")
        print(f"  Eğitilmiş model accuracy: {trained_accuracy:.2f}%")
