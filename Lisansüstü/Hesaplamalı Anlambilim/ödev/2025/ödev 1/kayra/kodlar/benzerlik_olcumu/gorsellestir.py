import matplotlib.pyplot as plt
import numpy as np
import os
from typing import Dict
from dosya_islemleri import get_tsne_photo_path, get_example_tsne_photo_path, top1_top5_results_dir

def plot_t1_t5_scores(question_data, answer_data, question_color='blue', answer_color='red', 
                      title='Modellerin Top1 ve Top5 Puanları'):
    """
    top1 ve top5 puanlarını model bazında çizdirir.
    
    Args:
        question_data: Soru verileri
        answer_data: Cevap verileri
        question_color: Soru puanları için renk (varsayılan: mavi)
        answer_color: Cevap puanları için renk (varsayılan: kırmızı)
    """
    # Model isimlerini çıkart
    models = []
    for item in question_data:
        if item['model_name'] not in models:
            models.append(item['model_name'])
    
    # Verileri ayır
    q_top1_scores = []
    q_top5_scores = []
    a_top1_scores = []
    a_top5_scores = []
    
    for model in models:
        # Soru verileri
        for item in question_data:
            if item['model_name'] == model:
                q_top1_scores.append(item['top1_score'])
                q_top5_scores.append(item['top5_score'])
        
        # Cevap verileri
        for item in answer_data:
            if item['model_name'] == model:
                a_top1_scores.append(item['top1_score'])
                a_top5_scores.append(item['top5_score'])
    
    # Figure ve axes oluştur
    fig, ax = plt.subplots(figsize=(12, 8))
    
    # X ekseni pozisyonları
    x = np.arange(len(models))
    width = 0.2  # Bar genişliği
    
    # Barları çiz
    bar1 = ax.bar(x - width*1.5, q_top1_scores, width, label='Question Top1', color=question_color)
    bar2 = ax.bar(x - width/2, q_top5_scores, width, label='Question Top5', color=question_color, alpha=0.7)
    bar3 = ax.bar(x + width/2, a_top1_scores, width, label='Answer Top1', color=answer_color)
    bar4 = ax.bar(x + width*1.5, a_top5_scores, width, label='Answer Top5', color=answer_color, alpha=0.7)
    
    # Grafiği güzelleştir
    ax.set_ylabel('Puanlar (%)')
    ax.set_title(title)
    ax.set_xticks(x)
    ax.set_xticklabels(models, rotation=25, ha='right')  # Rotasyonu 25'e düşür
    
    # Legend'ı figure'ın sağ üst köşesine yerleştir, figür dışına taşarak çakışmayı önle
    ax.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
    
    ax.set_ylim(0, 1.1)  # Skorlar 0-1 arasında olduğu için
    
    # Y eksenine grid ekle
    ax.grid(axis='y', linestyle='--', alpha=0.7)
    
    # Her bar'ın üzerine değerini yaz
    def add_labels(bars):
        for bar in bars:
            height = bar.get_height()
            ax.annotate(f'{height:.2f}',
                        xy=(bar.get_x() + bar.get_width() / 2, height),
                        xytext=(0, 3),  # 3 points vertical offset
                        textcoords="offset points",
                        ha='center', va='bottom', fontsize=8)
    
    # Tüm barların üzerine değeri yaz
    add_labels(bar1)
    add_labels(bar2)
    add_labels(bar3)
    add_labels(bar4)
    
    plt.tight_layout()
    
    # Legend'ı çakışmadan göstermek için figürü ayarla
    plt.subplots_adjust(right=0.85)  # Sağ tarafta legend için yer aç
    
    plt.savefig(os.path.join(top1_top5_results_dir, "results.png"), dpi=300, bbox_inches='tight')
    plt.close()
def plot_two_tsne_results(tsne_result1, tsne_result2, save_prefix, idx: int,
                         label1="Kaynak Metin", label2="Modelin Benzer Bulduğu Metin",
                         color1="blue", color2="red", title = "t-SNE Görselleştirmesi",
                         figsize=(18, 8)):
    """
    İki farklı t-SNE sonucunu yan yana ayrı grafiklerde çizdirir.
    
    Args:
        tsne_result1: Birinci t-SNE sonucu (n_tokens1 x 2 boyutunda)
        tsne_result2: İkinci t-SNE sonucu (n_tokens2 x 2 boyutunda)
        save_prefix: Kaydedilecek dosya adının öneki
        idx: Kaydedilecek verinin indeksi
        label1: Birinci veri seti için etiket
        label2: İkinci veri seti için etiket
        color1: Birinci veri seti için renk
        color2: İkinci veri seti için renk
        title: Grafik başlığı
        figsize: Figür boyutu (genişlik, yükseklik)
    """
    font_size = 25
    # Liste tipindeki verileri NumPy dizisine dönüştür
    tsne_result1 = np.array(tsne_result1)
    tsne_result2 = np.array(tsne_result2)
    # Figürü ve alt grafikleri oluştur
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=figsize)
    # İlk t-SNE sonucunu sol grafikte çizgiyle bağlanmış noktalar olarak çiz
    ax1.plot(
        tsne_result1[:, 0],  # x koordinatları
        tsne_result1[:, 1],  # y koordinatları
        c=color1,
        alpha=0.7,
        linewidth=1.5,
        marker='o',
        markersize=6
    )
    
    # İkinci t-SNE sonucunu sağ grafikte çizgiyle bağlanmış noktalar olarak çiz
    ax2.plot(
        tsne_result2[:, 0],  # x koordinatları
        tsne_result2[:, 1],  # y koordinatları
        c=color2,
        alpha=0.7,
        linewidth=1.5,
        marker='o',
        markersize=6
    )
    
    # Sol grafik düzenlemeleri
    ax1.set_title(f"{label1} Token Gömmeleri", fontsize=font_size)
    ax1.set_xlabel("t-SNE Boyut 1", fontsize=font_size)
    ax1.set_ylabel("t-SNE Boyut 2", fontsize=font_size)
    ax1.grid(True, linestyle='--', alpha=0.5)
    
    # Sağ grafik düzenlemeleri
    ax2.set_title(f"{label2} Token Gömmeleri", fontsize=font_size)
    ax2.set_xlabel("t-SNE Boyut 1", fontsize=font_size)
    ax2.set_ylabel("t-SNE Boyut 2", fontsize=font_size)
    ax2.grid(True, linestyle='--', alpha=0.5)
    
    fig.suptitle(title, fontsize=font_size + 3)
    
    # Grafiği düzenle ve kaydet
    plt.tight_layout()
    
    file_path = get_example_tsne_photo_path(save_prefix)
    file_path = file_path.replace(".png", f"_idx-{idx}.png")
    if not os.path.exists(os.path.dirname(file_path)):
        os.makedirs(os.path.dirname(file_path))
    plt.savefig(file_path, dpi=300, bbox_inches='tight')
    plt.close()


def save_tsne_png(data: Dict, save_prefix: str, title: str, q_color='blue', a_color='yellow'):
    """
    t-SNE görselleştirme grafiği oluşturur ve kaydeder.
    
    Args:
        data: 'question_tsne' ve 'answer_tsne' noktalarını içeren sözlük
        save_prefix: Kaydedilen dosya için önek
        title: Grafik başlığı
        q_color: Soru noktaları için renk (varsayılan: mavi)
        a_color: Cevap noktaları için renk (varsayılan: sarı)
    
    Returns:
        Kaydedilen PNG dosyasının yolu
    """
    # Dosya yolunu al
    png_path = get_tsne_photo_path(save_prefix)
    
    # Yeni bir şekil oluştur
    plt.figure(figsize=(10, 8))
    
    # Veri noktalarını çıkar
    q_points = data.get("question_tsne", [])
    a_points = data.get("answer_tsne", [])
    
    # answer_tsne formatını kontrol et ve gerekirse düzelt
    if isinstance(a_points, str):
        try:
            # JSON formatında string olabilir, değilse boş liste kullan
            import json
            a_points = json.loads(a_points)
        except:
            a_points = []
    elif isinstance(a_points, list) and len(a_points) > 0 and not isinstance(a_points[0], list):
        a_points = [a_points]
    
    # Çizilecek nokta olup olmadığını kontrol et
    if not q_points and not a_points:
        raise ValueError("Verilen veride t-SNE noktası bulunamadı")
    
    # Soru noktalarını mavi yuvarlak olarak çiz
    if q_points:
        q_x = [point[0] for point in q_points if len(point) >= 2]
        q_y = [point[1] for point in q_points if len(point) >= 2]
        plt.scatter(q_x, q_y, color=q_color, marker='o', label='Sorular')
    
    # Cevap noktalarını sarı kare olarak çiz
    if a_points:
        # Her noktanın en az 2 değer içerdiğinden emin ol
        valid_points = [p for p in a_points if isinstance(p, list) and len(p) >= 2]
        if valid_points:
            a_x = [point[0] for point in valid_points]
            a_y = [point[1] for point in valid_points]
            plt.scatter(a_x, a_y, color=a_color, marker='s', label='Cevaplar')
    
    # Etiketler ve açıklamaları ekle
    plt.title(title, fontsize=18)
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    # Görüntüyü kaydet
    plt.savefig(png_path, dpi=300, bbox_inches='tight')
    plt.close()
    
    print(f"Görselleştirme kaydedildi: {png_path}")
    return png_path