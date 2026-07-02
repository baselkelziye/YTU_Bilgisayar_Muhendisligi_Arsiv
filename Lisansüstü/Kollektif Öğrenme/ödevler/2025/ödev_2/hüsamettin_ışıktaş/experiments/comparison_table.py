#!/usr/bin/env python3
"""
Batch sonuçlarını karşılaştırmak için script
"""
import json
import os
from pathlib import Path

def load_all_metrics():
    """Tüm metrics_summary.json dosyalarını yükle"""
    base_dir = Path(__file__).parent
    results = []
    
    for embed_size in [128, 256, 1024]:
        embed_dir = base_dir / f"embed_size_{embed_size}"
        if not embed_dir.exists():
            continue
            
        for model_dir in embed_dir.iterdir():
            if not model_dir.is_dir():
                continue
                
            json_file = model_dir / "metrics_summary.json"
            if json_file.exists():
                with open(json_file, 'r', encoding='utf-8') as f:
                    data = json.load(f)
                    results.append(data)
    
    return results

def create_comparison_table():
    """Karşılaştırma tablosu oluştur"""
    results = load_all_metrics()
    
    # Markdown tablosu oluştur
    md_content = "# Model Karşılaştırma Tablosu\n\n"
    md_content += "Bu tablo tüm deneylerin sonuçlarını karşılaştırmaktadır.\n\n"
    
    # Her dataset tipi için ayrı tablo
    for dataset_type in ['title', 'abstract', 'concat']:
        md_content += f"## {dataset_type.upper()} Veriseti\n\n"
        
        # Tablo başlığı
        md_content += "| Model | Embed Size | Accuracy | F1 (Macro) | F1 (Weighted) | Precision | Recall | MAE | RMSE |\n"
        md_content += "|-------|------------|----------|------------|----------------|-----------|--------|-----|------|\n"
        
        # Verileri sırala: önce model, sonra embed_size
        sorted_results = sorted(results, key=lambda x: (x['_meta']['model'], x['_meta']['embed_size']))
        
        for result in sorted_results:
            model = result['_meta']['model']
            embed_size = result['_meta']['embed_size']
            metrics = result[dataset_type]
            
            md_content += f"| {model} | {embed_size} | "
            md_content += f"{metrics['accuracy']:.4f} | "
            md_content += f"{metrics['f1_macro']:.4f} | "
            md_content += f"{metrics['f1_weighted']:.4f} | "
            md_content += f"{metrics['precision_macro']:.4f} | "
            md_content += f"{metrics['recall_macro']:.4f} | "
            md_content += f"{metrics['mae']:.2f} | "
            md_content += f"{metrics['rmse']:.2f} |\n"
        
        md_content += "\n"
    
    # Genel özet tablosu - her model ve embed_size kombinasyonu için en iyi sonuçlar
    md_content += "## Genel Özet - En İyi Sonuçlar\n\n"
    md_content += "| Model | Embed Size | En İyi Dataset | Accuracy | F1 (Macro) | MAE | RMSE |\n"
    md_content += "|-------|------------|-----------------|----------|------------|-----|------|\n"
    
    # Her model-embed_size kombinasyonu için en iyi sonucu bul
    for model in ['Random Forest', 'Bagging', 'Random Subspace', 'PyTorch MLP']:
        for embed_size in [128, 256, 1024]:
            model_results = [r for r in results if r['_meta']['model'] == model and r['_meta']['embed_size'] == embed_size]
            if not model_results:
                continue
            
            result = model_results[0]
            best_dataset = None
            best_accuracy = -1
            
            for dataset_type in ['title', 'abstract', 'concat']:
                accuracy = result[dataset_type]['accuracy']
                if accuracy > best_accuracy:
                    best_accuracy = accuracy
                    best_dataset = dataset_type
            
            best_metrics = result[best_dataset]
            md_content += f"| {model} | {embed_size} | {best_dataset} | "
            md_content += f"{best_metrics['accuracy']:.4f} | "
            md_content += f"{best_metrics['f1_macro']:.4f} | "
            md_content += f"{best_metrics['mae']:.2f} | "
            md_content += f"{best_metrics['rmse']:.2f} |\n"
    
    md_content += "\n"
    
    # Embed size karşılaştırması
    md_content += "## Embed Size Karşılaştırması (Ortalama)\n\n"
    md_content += "| Embed Size | Title Acc | Abstract Acc | Concat Acc | Ortalama Acc |\n"
    md_content += "|------------|-----------|--------------|------------|--------------|\n"
    
    for embed_size in [128, 256, 1024]:
        size_results = [r for r in results if r['_meta']['embed_size'] == embed_size]
        if not size_results:
            continue
        
        title_acc = sum(r['title']['accuracy'] for r in size_results) / len(size_results)
        abstract_acc = sum(r['abstract']['accuracy'] for r in size_results) / len(size_results)
        concat_acc = sum(r['concat']['accuracy'] for r in size_results) / len(size_results)
        avg_acc = (title_acc + abstract_acc + concat_acc) / 3
        
        md_content += f"| {embed_size} | {title_acc:.4f} | {abstract_acc:.4f} | {concat_acc:.4f} | {avg_acc:.4f} |\n"
    
    md_content += "\n"
    
    # Model karşılaştırması
    md_content += "## Model Karşılaştırması (Ortalama)\n\n"
    md_content += "| Model | Title Acc | Abstract Acc | Concat Acc | Ortalama Acc |\n"
    md_content += "|-------|-----------|--------------|------------|--------------|\n"
    
    for model in ['Random Forest', 'Bagging', 'Random Subspace', 'PyTorch MLP']:
        model_results = [r for r in results if r['_meta']['model'] == model]
        if not model_results:
            continue
        
        title_acc = sum(r['title']['accuracy'] for r in model_results) / len(model_results)
        abstract_acc = sum(r['abstract']['accuracy'] for r in model_results) / len(model_results)
        concat_acc = sum(r['concat']['accuracy'] for r in model_results) / len(model_results)
        avg_acc = (title_acc + abstract_acc + concat_acc) / 3
        
        md_content += f"| {model} | {title_acc:.4f} | {abstract_acc:.4f} | {concat_acc:.4f} | {avg_acc:.4f} |\n"
    
    return md_content

if __name__ == "__main__":
    table = create_comparison_table()
    output_file = Path(__file__).parent / "comparison_table.md"
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(table)
    print(f"Karşılaştırma tablosu oluşturuldu: {output_file}")

