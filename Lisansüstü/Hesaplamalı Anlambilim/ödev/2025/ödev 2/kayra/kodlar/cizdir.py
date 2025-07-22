import matplotlib.pyplot as plt
import numpy as np
import os
from dizin_yardimcisi import    get_shot_file_dir, get_dogruluk_png_yolu, get_precision_png_yolu, \
                                get_recall_png_yolu, get_f1_score_png_yolu, get_confusion_matrix_png_yolu
import seaborn as sns
def model_shot_puanlari_cizdir(baslik: str, veri_listesi: list, dosya_on_eki: str = "sst2", renkler: list = None) -> tuple:
    """
    Modellerin zero-shot, 3-shot ve 5-shot doğruluk oranlarını gösteren bar chart oluşturur.
    
    Args:
        baslik: Grafiğin başlığı
        veri_listesi: Her bir elemanında model_name ve doğruluk verileri bulunan sözlükler listesi
        dosya_on_eki: Kaydedilecek dosyanın ön eki (default: "sst2")
        renkler: Çubuk renklerinin listesi (default: ['#4285F4', '#34A853', '#FBBC05'])
    
    Returns:
        fig, ax: Matplotlib figür ve eksen nesneleri
    """

    # Model adlarını ve puanları çıkar
    model_adlari = [item['model_name'] for item in veri_listesi]
    zero_shot_puanlari = [item['zero_shot']['accuracy'] for item in veri_listesi]
    three_shot_puanlari = [item['3_shot']['accuracy'] for item in veri_listesi]
    five_shot_puanlari = [item['5_shot']['accuracy'] for item in veri_listesi]
    
    # Çubuklar için konumları ayarla
    x = np.arange(len(model_adlari))
    cubuk_genisligi = 0.25
    
    # Figür ve eksen oluştur
    fig, ax = plt.subplots(figsize=(10, 6))
    
    # Eğer renkler belirtilmemişse varsayılan renkleri kullan
    if renkler is None:
        renkler = ['#4285F4', '#34A853', '#FBBC05']
    
    # Çubukları oluştur
    bars1 = ax.bar(x - cubuk_genisligi, zero_shot_puanlari, cubuk_genisligi, label='Zero Shot', color=renkler[0])
    bars2 = ax.bar(x, three_shot_puanlari, cubuk_genisligi, label='3 Shot', color=renkler[1])
    bars3 = ax.bar(x + cubuk_genisligi, five_shot_puanlari, cubuk_genisligi, label='5 Shot', color=renkler[2])
    
    # Çubukların üzerine değerleri ekle
    for bar in bars1 + bars2 + bars3:
        yukseklik = bar.get_height()
        ax.annotate(f'{yukseklik:.3f}',
                    xy=(bar.get_x() + bar.get_width() / 2, yukseklik),
                    xytext=(0, 3),
                    textcoords="offset points",
                    ha='center', va='bottom',
                    fontsize=10)
    
    # En yüksek puanı bul ve y ekseni limitini ayarla
    max_puan = max(zero_shot_puanlari + three_shot_puanlari + five_shot_puanlari)
    ax.set_ylim(0, max_puan * 1.1)  # Y eksenini %10 artır
    
    # Grafiği özelleştir
    ax.set_title(baslik, fontsize=20, pad=20)
    ax.set_xlabel('Model', fontsize=16, labelpad=10)
    ax.set_ylabel('Doğruluk Oranı', fontsize=18, labelpad=10)
    ax.set_xticks(x)
    ax.set_xticklabels(model_adlari, fontsize=12, rotation=20, ha='center')
    
    # Y eksenini yüzde olarak formatla
    ax.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'%{x*100:.0f}'))
    
    # Izgara ekle
    ax.yaxis.grid(True, linestyle='--', alpha=0.7)
    
    # Lejantı grafiğin dışına al
    ax.legend(fontsize=12, loc='upper left', bbox_to_anchor=(1, 1))
    
    # Düzeni ayarla
    plt.tight_layout()
    
    # Grafik kaydetme dizini
    plt_dir = get_shot_file_dir()
    if not os.path.exists(plt_dir):
        os.makedirs(plt_dir)
    
    # Grafiği kaydet
    plt_path = f"{plt_dir}/{dosya_on_eki}_model_puanlari.png"
    plt.savefig(plt_path, bbox_inches='tight')
    
    plt.close()


def gomme_modeli_basari_puanlari_cizdir(title, data, veri_kumesi_adi, colors=['#8B4513', '#8B0000', '#006400'], 
                        x_label='Gömme Modeli', y_label='Doğruluk Oranı', figsize=(14,8)):  # Figsize'ı büyüttüm
    """
    Her bir gömme modelinin makine öğrenmesi modellerine ait doğruluk oranlarını çizdirir.

    Parameters:
    - title (str): Grafiğin başlığı.
    - data (dict): Gömme modelleri ve bunlara ait makine öğrenmesi modellerinin sonuçlarını içeren sözlük.
    - colors (list): Çubukların renkleri.
    - x_label (str): X ekseninin etiketi.
    - y_label (str): Y ekseninin etiketi.
    - figsize (tuple): Grafiğin boyutu.
    """

    embedding_models = list(data.keys())
    ml_models = set()
    for emb in data:
        ml_models.update(data[emb].keys())
    ml_models = sorted(ml_models)

    num_ml_models = len(ml_models)
    num_embeddings = len(embedding_models)

    # Doğruluk oranlarını tutacak matris
    accuracy_matrix = np.zeros((num_embeddings, num_ml_models))

    for i, emb in enumerate(embedding_models):
        for j, ml in enumerate(ml_models):
            accuracy = data[emb].get(ml, {}).get('accuracy')
            if accuracy is not None:
                accuracy_matrix[i, j] = accuracy
            else:
                accuracy_matrix[i, j] = 0.0  # Eğer değer yoksa 0 olarak kabul et

    # Çubukların pozisyonlarını ayarla
    bar_width = 0.7 / num_ml_models  # Bar genişliklerini azaltalım
    x_indices = np.arange(num_embeddings)

    # Figür boyutunu arttırdım ve alt boşluk ekledim
    fig, ax = plt.subplots(figsize=figsize)
    plt.subplots_adjust(bottom=0.25, top=0.85)  # X ekseni için daha fazla alan
    max_accuracy = np.max(accuracy_matrix)
    ax.set_ylim(0, min(1.0, max_accuracy * 1.15))
    for idx, ml_model in enumerate(ml_models):
        accuracies = accuracy_matrix[:, idx]
        positions = x_indices - 0.35 + (idx + 0.5) * bar_width
        color = colors[idx % len(colors)]
        bars = ax.bar(positions, accuracies, width=bar_width, label=ml_model, color=color)
        
        # Çubukların üzerine değerleri ekle - yüksekliği biraz ayarlayalım
        for bar in bars:
            height = bar.get_height()
            ax.annotate(f'{height:.3f}',
                        xy=(bar.get_x() + bar.get_width() / 2, height),
                        xytext=(0, 3),
                        textcoords="offset points",
                        ha='center', va='bottom',
                        fontsize=9,  # Punto boyutunu küçülttüm
                        rotation=90)  # Dikey yazdıralım

    # Başlık ve eksen etiketleri için puntosunu ayarla
    ax.set_title(title, fontsize=20, pad=20)
    ax.set_xlabel(x_label, fontsize=16, labelpad=10)
    ax.set_ylabel(y_label, fontsize=18, labelpad=10)

    # Y eksenini yüzde olarak formatla
    ax.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'%{x*100:.0f}'))

    # Izgara ekle
    ax.yaxis.grid(True, linestyle='--', alpha=0.7)

    ax.set_xticks(x_indices)
    # X eksen etiketlerini 20 derece döndür ve daha fazla yer aç
    ax.set_xticklabels(embedding_models, fontsize=11, rotation=20, ha='right')

    # Lejantı grafiğin tamamen dışına çıkaralım
    ax.legend(fontsize=11, loc='upper left', bbox_to_anchor=(1.01, 1), borderaxespad=0.)

    plt.tight_layout()
    plt.savefig(f"{get_dogruluk_png_yolu(veri_kumesi_adi)}", bbox_inches='tight')  # bbox_inches='tight' eklendi
    plt.close()

def gomme_modeli_precision_puanlari_cizdir(title, data, veri_kumesi_adi, colors=['#8B4513', '#8B0000', '#006400'], 
                        x_label='Gömme Modeli', y_label='Keskinlik (Precision) Puanı', figsize=(14,8)):
    """
    Her bir gömme modelinin makine öğrenmesi modellerine ait precision puanlarını çizdirir.

    Parameters:
    - title (str): Grafiğin başlığı.
    - data (dict): Gömme modelleri ve bunlara ait makine öğrenmesi modellerinin sonuçlarını içeren sözlük.
    - colors (list): Çubukların renkleri.
    - x_label (str): X ekseninin etiketi.
    - y_label (str): Y ekseninin etiketi.
    - figsize (tuple): Grafiğin boyutu.
    """

    embedding_models = list(data.keys())
    ml_models = set()
    for emb in data:
        ml_models.update(data[emb].keys())
    ml_models = sorted(ml_models)

    num_ml_models = len(ml_models)
    num_embeddings = len(embedding_models)

    # Precision puanlarını tutacak matris
    precision_matrix = np.zeros((num_embeddings, num_ml_models))

    for i, emb in enumerate(embedding_models):
        for j, ml in enumerate(ml_models):
            precision = data[emb].get(ml, {}).get('precision')
            if precision is not None:
                precision_matrix[i, j] = precision
            else:
                precision_matrix[i, j] = 0.0  # Eğer değer yoksa 0 olarak kabul et

    # Çubukların pozisyonlarını ayarla
    bar_width = 0.7 / num_ml_models  # Bar genişliklerini azaltalım
    x_indices = np.arange(num_embeddings)

    # Figür boyutunu arttırdım ve alt boşluk ekledim
    fig, ax = plt.subplots(figsize=figsize)
    plt.subplots_adjust(bottom=0.25, top=0.85)  # X ekseni için daha fazla alan
    max_accuracy = np.max(precision_matrix)
    ax.set_ylim(0, min(1.0, max_accuracy * 1.15))
    for idx, ml_model in enumerate(ml_models):
        precision_values = precision_matrix[:, idx]
        positions = x_indices - 0.35 + (idx + 0.5) * bar_width
        color = colors[idx % len(colors)]
        bars = ax.bar(positions, precision_values, width=bar_width, label=ml_model, color=color)
        
        # Çubukların üzerine değerleri ekle
        for bar in bars:
            height = bar.get_height()
            ax.annotate(f'{height:.3f}',
                        xy=(bar.get_x() + bar.get_width() / 2, height),
                        xytext=(0, 3),
                        textcoords="offset points",
                        ha='center', va='bottom',
                        fontsize=9,
                        rotation=90)

    # Başlık ve eksen etiketleri için puntosunu ayarla
    ax.set_title(title, fontsize=20, pad=20)
    ax.set_xlabel(x_label, fontsize=16, labelpad=10)
    ax.set_ylabel(y_label, fontsize=18, labelpad=10)

    # Y eksenini yüzde olarak formatla
    ax.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'%{x*100:.0f}'))

    # Izgara ekle
    ax.yaxis.grid(True, linestyle='--', alpha=0.7)

    ax.set_xticks(x_indices)
    # X eksen etiketlerini 20 derece döndür ve daha fazla yer aç
    ax.set_xticklabels(embedding_models, fontsize=11, rotation=20, ha='right')

    # Lejantı grafiğin tamamen dışına çıkaralım
    ax.legend(fontsize=11, loc='upper left', bbox_to_anchor=(1.05, 1), borderaxespad=0.)

    plt.tight_layout()
    plt.savefig(get_precision_png_yolu(veri_kumesi_adi), bbox_inches='tight')
    plt.close()


def gomme_modeli_recall_puanlari_cizdir(title, data, veri_kumesi_adi, colors=['#8B4513', '#8B0000', '#006400'], 
                        x_label='Gömme Modeli', y_label='Geri Çağırma (Recall) Puanı', figsize=(14,8)):
    """
    Her bir gömme modelinin makine öğrenmesi modellerine ait recall puanlarını çizdirir.

    Parameters:
    - title (str): Grafiğin başlığı.
    - data (dict): Gömme modelleri ve bunlara ait makine öğrenmesi modellerinin sonuçlarını içeren sözlük.
    - colors (list): Çubukların renkleri.
    - x_label (str): X ekseninin etiketi.
    - y_label (str): Y ekseninin etiketi.
    - figsize (tuple): Grafiğin boyutu.
    """

    embedding_models = list(data.keys())
    ml_models = set()
    for emb in data:
        ml_models.update(data[emb].keys())
    ml_models = sorted(ml_models)

    num_ml_models = len(ml_models)
    num_embeddings = len(embedding_models)

    # Recall puanlarını tutacak matris
    recall_matrix = np.zeros((num_embeddings, num_ml_models))

    for i, emb in enumerate(embedding_models):
        for j, ml in enumerate(ml_models):
            recall = data[emb].get(ml, {}).get('recall')
            if recall is not None:
                recall_matrix[i, j] = recall
            else:
                recall_matrix[i, j] = 0.0  # Eğer değer yoksa 0 olarak kabul et

    # Çubukların pozisyonlarını ayarla
    bar_width = 0.7 / num_ml_models
    x_indices = np.arange(num_embeddings)

    # Figür boyutunu arttırdım ve alt boşluk ekledim
    fig, ax = plt.subplots(figsize=figsize)
    plt.subplots_adjust(bottom=0.25, top=0.85)  # X ekseni için daha fazla alan
    max_accuracy = np.max(recall_matrix)
    ax.set_ylim(0, min(1.0, max_accuracy * 1.15))
    for idx, ml_model in enumerate(ml_models):
        recall_values = recall_matrix[:, idx]
        positions = x_indices - 0.35 + (idx + 0.5) * bar_width
        color = colors[idx % len(colors)]
        bars = ax.bar(positions, recall_values, width=bar_width, label=ml_model, color=color)
        
        # Çubukların üzerine değerleri ekle
        for bar in bars:
            height = bar.get_height()
            ax.annotate(f'{height:.3f}',
                        xy=(bar.get_x() + bar.get_width() / 2, height),
                        xytext=(0, 3),
                        textcoords="offset points",
                        ha='center', va='bottom',
                        fontsize=9,
                        rotation=90)

    # Başlık ve eksen etiketleri için puntosunu ayarla
    ax.set_title(title, fontsize=20, pad=20)
    ax.set_xlabel(x_label, fontsize=16, labelpad=10)
    ax.set_ylabel(y_label, fontsize=18, labelpad=10)

    # Y eksenini yüzde olarak formatla
    ax.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'%{x*100:.0f}'))

    # Izgara ekle
    ax.yaxis.grid(True, linestyle='--', alpha=0.7)

    ax.set_xticks(x_indices)
    # X eksen etiketlerini 20 derece döndür ve daha fazla yer aç
    ax.set_xticklabels(embedding_models, fontsize=11, rotation=20, ha='right')

    # Lejantı grafiğin tamamen dışına çıkaralım
    ax.legend(fontsize=11, loc='upper left', bbox_to_anchor=(1.05, 1), borderaxespad=0.)

    plt.tight_layout()
    plt.savefig(get_recall_png_yolu(veri_kumesi_adi), bbox_inches='tight')
    plt.close()


def gomme_modeli_f1_puanlari_cizdir(title, data, veri_kumesi_adi, colors=['#8B4513', '#8B0000', '#006400'], 
                        x_label='Gömme Modeli', y_label='F1 Puanı', figsize=(14,8)):
    """
    Her bir gömme modelinin makine öğrenmesi modellerine ait F1 puanlarını çizdirir.

    Parameters:
    - title (str): Grafiğin başlığı.
    - data (dict): Gömme modelleri ve bunlara ait makine öğrenmesi modellerinin sonuçlarını içeren sözlük.
    - colors (list): Çubukların renkleri.
    - x_label (str): X ekseninin etiketi.
    - y_label (str): Y ekseninin etiketi.
    - figsize (tuple): Grafiğin boyutu.
    """

    embedding_models = list(data.keys())
    ml_models = set()
    for emb in data:
        ml_models.update(data[emb].keys())
    ml_models = sorted(ml_models)

    num_ml_models = len(ml_models)
    num_embeddings = len(embedding_models)

    # F1 puanlarını tutacak matris
    f1_matrix = np.zeros((num_embeddings, num_ml_models))

    for i, emb in enumerate(embedding_models):
        for j, ml in enumerate(ml_models):
            f1 = data[emb].get(ml, {}).get('f1')
            if f1 is not None:
                f1_matrix[i, j] = f1
            else:
                f1_matrix[i, j] = 0.0  # Eğer değer yoksa 0 olarak kabul et

    # Çubukların pozisyonlarını ayarla
    bar_width = 0.7 / num_ml_models
    x_indices = np.arange(num_embeddings)

    # Figür boyutunu arttırdım ve alt boşluk ekledim
    fig, ax = plt.subplots(figsize=figsize)
    plt.subplots_adjust(bottom=0.25, top=0.85)  # X ekseni için daha fazla alan
    max_accuracy = np.max(f1_matrix)
    ax.set_ylim(0, min(1.0, max_accuracy * 1.15))
    for idx, ml_model in enumerate(ml_models):
        f1_values = f1_matrix[:, idx]
        positions = x_indices - 0.35 + (idx + 0.5) * bar_width
        color = colors[idx % len(colors)]
        bars = ax.bar(positions, f1_values, width=bar_width, label=ml_model, color=color)
        
        # Çubukların üzerine değerleri ekle
        for bar in bars:
            height = bar.get_height()
            ax.annotate(f'{height:.3f}',
                        xy=(bar.get_x() + bar.get_width() / 2, height),
                        xytext=(0, 3),
                        textcoords="offset points",
                        ha='center', va='bottom',
                        fontsize=9,
                        rotation=90)

    # Başlık ve eksen etiketleri için puntosunu ayarla
    ax.set_title(title, fontsize=20, pad=20)
    ax.set_xlabel(x_label, fontsize=16, labelpad=10)
    ax.set_ylabel(y_label, fontsize=18, labelpad=10)

    # Y eksenini yüzde olarak formatla
    ax.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'%{x*100:.0f}'))

    # Izgara ekle
    ax.yaxis.grid(True, linestyle='--', alpha=0.7)

    ax.set_xticks(x_indices)
    # X eksen etiketlerini 20 derece döndür ve daha fazla yer aç
    ax.set_xticklabels(embedding_models, fontsize=11, rotation=20, ha='right')

    # Lejantı grafiğin tamamen dışına çıkaralım
    ax.legend(fontsize=11, loc='upper left', bbox_to_anchor=(1.05, 1), borderaxespad=0.)

    plt.tight_layout()
    plt.savefig(get_f1_score_png_yolu(veri_kumesi_adi), bbox_inches='tight')
    plt.close()

def gomme_modeli_conf_matris_cizdir(title, data, veri_kumesi_adi, ml_model_adi, model_adi, model_dosya_adi_on_eki):
    """
    Belirli bir gömme modeli ve makine öğrenmesi modeline ait confusion matrix'i çizdirir.

    Parameters:
    - title (str): Grafiğin başlığı.
    - data (dict): Gömme modelleri ve bunlara ait makine öğrenmesi modellerinin sonuçlarını içeren sözlük.
    - veri_kumesi_adi (str): Veri kümesinin adı (örn. 'cola', 'sst2').
    - ml_model_adi (str): Makine öğrenmesi modelinin adı.
    - model_adi (str): Gömme modelinin adı.
    """
    try:
        # Veri setinden confusion matrix'i al
        conf_matrix = np.array(data[model_adi][ml_model_adi]['confusion_matrix'])
        
        # Boyutu kontrol et (2x2 olması beklenir)
        if conf_matrix.shape != (2, 2):
            print(f"Hata: {model_adi} modeli için {ml_model_adi} confusion matrix'i 2x2 boyutunda değil.")
            return
        
        # Confusion matrix değerlerini al
        tn, fp = conf_matrix[0]  # True Negative, False Positive
        fn, tp = conf_matrix[1]  # False Negative, True Positive
        
        # Toplam örnek sayısını hesapla
        total = tn + fp + fn + tp
        
        # Figür oluştur
        plt.figure(figsize=(10, 8))
        
        # Confusion matrix'i normalize et (yüzde değerleri için)
        conf_matrix_norm = conf_matrix / total
        
        # Heatmap oluştur
        sns.heatmap(conf_matrix, annot=True, fmt="d", cmap=sns.color_palette("Blues", as_cmap=True),
                   xticklabels=['Negatif Tahmin', 'Pozitif Tahmin'],
                   yticklabels=['Gerçek Negatif', 'Gerçek Pozitif'])
        
        # İkinci bir eksen ekleyerek yüzde değerlerini göster
        ax2 = plt.gca()
        for i in range(2):
            for j in range(2):
                ax2.text(j+0.5, i+0.7, f'({conf_matrix_norm[i, j]:.1%})', 
                         ha="center", va="center", fontsize=12)
        
        # Başlık ve etiketler
        plt.title(f"{title}\n{model_adi} - {ml_model_adi}", fontsize=16, pad=20)
        plt.ylabel('Gerçek Sınıf', fontsize=14)
        plt.xlabel('Tahmin Edilen Sınıf', fontsize=14)
        
        plt.tight_layout()

        plt.savefig(get_confusion_matrix_png_yolu(veri_kumesi_adi, model_dosya_adi_on_eki, ml_model_adi), bbox_inches='tight')
        plt.close()
        
    except Exception as e:
        print(f"Hata oluştu: {e}")
        print(f"Veri kümesi: {veri_kumesi_adi}, Model: {model_adi}, ML Modeli: {ml_model_adi}")