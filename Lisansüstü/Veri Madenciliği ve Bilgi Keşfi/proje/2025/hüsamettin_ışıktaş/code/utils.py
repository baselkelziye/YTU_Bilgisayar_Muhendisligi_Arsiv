import os
import pandas as pd
from datetime import datetime

def log_experiment(model_name, accuracy, sensitivity, seed, notes=""):
    """
    Deney sonuçlarını experiments_log.md dosyasına kaydeder.
    
    Args:
        model_name (str): Kullanılan modelin adı (örn: 'Logistic Regression')
        accuracy (float): Modelin doğruluk skoru (0-1 arası veya yüzde)
        sensitivity (float): Modelin duyarlılık (Recall) skoru
        seed (int): Random state seed değeri
        notes (str): Deneyle ilgili ek notlar
    """
    log_file = "experiments_log.md"
    
    # Dosya yoksa başlıkları oluştur
    if not os.path.exists(log_file):
        with open(log_file, "w") as f:
            f.write("| Tarih | Model | Seed | Accuracy (%) | Sensitivity (%) | Notlar |\n")
            f.write("|-------|-------|------|--------------|-----------------|--------|\n")
    
    # Tarih formatı
    date_str = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    
    # Yüzdelik formata çevirme (eğer 0-1 arasındaysa)
    if accuracy <= 1.0:
        accuracy *= 100
    if sensitivity <= 1.0:
        sensitivity *= 100
        
    # Log satırını oluştur
    log_entry = f"| {date_str} | {model_name} | {seed} | {accuracy:.2f} | {sensitivity:.2f} | {notes} |\n"
    
    # Dosyaya ekle
    with open(log_file, "a") as f:
        f.write(log_entry)

    print(f"✅ Deney sonucu kaydedildi: {model_name} (Acc: {accuracy:.2f}%, Sens: {sensitivity:.2f}%)")
