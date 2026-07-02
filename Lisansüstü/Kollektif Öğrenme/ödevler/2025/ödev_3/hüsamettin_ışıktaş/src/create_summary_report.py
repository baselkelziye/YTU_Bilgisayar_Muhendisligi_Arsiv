"""
Tüm eğitim ve test sonuçlarını toplayıp özet bir rapor oluşturur.
"""

import json
import glob
import os
import pandas as pd

def main():
    results_dir = "results"
    
    # 1. Baseline Sonuçlarını Oku
    baseline_path = os.path.join(results_dir, "baseline_results", "baseline_summary.json")
    baseline_acc = 0
    baseline_fmt = 0
    
    if os.path.exists(baseline_path):
        try:
            with open(baseline_path, 'r', encoding='utf-8') as f:
                data = json.load(f)
                baseline_acc = data.get('accuracy', 0)
                baseline_fmt = data.get('format_compliance', 0)
        except Exception as e:
            print(f"Baseline okuma hatası: {e}")
            
    records = []
    # Baseline'ı listeye ekle
    records.append({
        "Model": "Baseline (Eğitimsiz)",
        "Reward Function": "-",
        "Accuracy (%)": baseline_acc,
        "Format Compliance (%)": baseline_fmt,
        "Diff (Acc)": 0.0
    })
    
    # 2. Diğer Tüm Sonuçları Tara
    # Pattern: training_comparison_results_*.json
    pattern = os.path.join(results_dir, "training_comparison_results_*.json")
    files = glob.glob(pattern)
    
    print(f"Bulunan sonuç dosyası sayısı: {len(files)}")
    
    for fpath in files:
        try:
            fname = os.path.basename(fpath)
            # Dosya adından model ismini çıkar
            # Örn: training_comparison_results_short.json -> short
            # Örn: training_comparison_results_merged_short_long.json -> merged_short_long
            model_name = fname.replace("training_comparison_results_", "").replace(".json", "")
            
            with open(fpath, 'r', encoding='utf-8') as f:
                data = json.load(f)
            
            # Verileri çek
            trained_data = data.get('trained_model', {})
            acc = trained_data.get('accuracy', 0)
            fmt = trained_data.get('format_compliance', 0)
            
            # Baseline'a göre fark
            diff = acc - baseline_acc
            
            # Reward Function tipini belirle
            if "merged" in model_name:
                rf_type = "MERGED"
            else:
                rf_type = model_name
            
            records.append({
                "Model": model_name,
                "Reward Function": rf_type,
                "Accuracy (%)": acc,
                "Format Compliance (%)": fmt,
                "Diff (Acc)": diff
            })
            
        except Exception as e:
            print(f"Dosya okuma hatası ({fpath}): {e}")
    
    # 3. Tabloyu Oluştur ve Sırala
    if not records:
        print("Hiçbir sonuç bulunamadı!")
        return

    df = pd.DataFrame(records)
    
    # Accuracy'ye göre sırala (Yüksekten düşüğe)
    # Baseline'ı en altta veya en üstte tutmak yerine puana göre sıralıyoruz
    df = df.sort_values(by="Accuracy (%)", ascending=False)
    
    # 4. Kaydet
    # CSV olarak
    csv_path = os.path.join(results_dir, "FINAL_LEADERBOARD.csv")
    df.to_csv(csv_path, index=False, encoding='utf-8-sig')
    
    # Markdown olarak (Okunabilir rapor)
    md_path = os.path.join(results_dir, "FINAL_LEADERBOARD.md")
    with open(md_path, 'w', encoding='utf-8') as f:
        f.write("# 🏆 Model Liderlik Tablosu\n\n")
        f.write(f"Oluşturulma Tarihi: {pd.Timestamp.now()}\n\n")
        f.write(df.to_markdown(index=False))
        f.write("\n\n*Diff (Acc): Baseline modele göre doğruluk farkı.*\n")
    
    # Konsola yazdır
    print("\n" + "="*60)
    print("🏆 MODEL LİDERLİK TABLOSU")
    print("="*60)
    print(df.to_string(index=False))
    print("\n" + "="*60)
    print(f"Raporlar kaydedildi:\n -> {csv_path}\n -> {md_path}")

if __name__ == "__main__":
    main()
