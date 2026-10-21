import pandas as pd
import matplotlib.pyplot as plt
import torch
from sentence_transformers import util

# Uygun GPU varsa kullanılır.
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Kullanılan cihaz: {device}")

# Veri yüklenir ve etiketleri ayarlanır.
file = "1k"
path = f"embeddings/{file}"
df = pd.read_excel(f"{file}.xlsx")
df.columns = ['soru', 'gpt4o', 'deepseek', 'etiket']

# Kullanılacak modeller listelenir.
models = ['e5', 'cosmosE5', 'jina']

# Her model için GPT ve DeepSeek cevapları benzerlikleri hesaplanır.
for model_name in models:
    print("\n######################################################\n")
    print(f"Model: {model_name}")

    # Soru, gpt-4o, deepseek cevap embeddinglei yüklenir.
    q_emb = torch.load(f"{path}_{model_name}_questions.pt", weights_only=True).to(device)
    gpt_emb = torch.load(f"{path}_{model_name}_gpt4o.pt", weights_only=True).to(device)
    deep_emb = torch.load(f"{path}_{model_name}_deepseek.pt", weights_only=True).to(device)

    # Başarı hesaplama
    top1_gpt, top5_gpt = 0, 0
    top1_deep, top5_deep = 0, 0

    top1_gpt_list, top5_gpt_list = [], []
    top1_deep_list, top5_deep_list = [], []

    for i in range(len(df)):
        # gpt-4o için cosine similarity hesaplanır.
        gpt_sim = util.cos_sim(q_emb[i], gpt_emb)[0]            # Soru ile gpt cevapları arasındaki benzerlik hesaplanır.
        gpt_top5 = torch.topk(gpt_sim, k=5).indices.tolist()    # En benzeyen cevaplar arasından ilk beşi seçilir.
        top1_gpt_list.append(gpt_top5[0] == i)
        top5_gpt_list.append(i in gpt_top5)
        if gpt_top5[0] == i: top1_gpt += 1      # En benzer cevaplardaki ilk indis sorununki ile aynıysa top-1 başarı arttırılır.
        if i in gpt_top5: top5_gpt += 1         # Sorunun indisi en benzer cevaplardaki ilk beş indisin içindeyse top-5 başarı arttırılır.

        # deepseek için cosine similarity hesaplanır.
        deep_sim = util.cos_sim(q_emb[i], deep_emb)[0]          # Soru ile deepseek cevapları arasındaki benzerlik hesaplanır.
        deep_top5 = torch.topk(deep_sim, k=5).indices.tolist()  # En benzeyen cevaplar arasından ilk beşi seçilir.
        top1_deep_list.append(deep_top5[0] == i)
        top5_deep_list.append(i in deep_top5)
        if deep_top5[0] == i: top1_deep += 1    # En benzer cevaplardaki ilk indis sorununki ile aynıysa top-1 başarı arttırılır.
        if i in deep_top5: top5_deep += 1       # Sorunun indisi en benzer cevaplardaki ilk beş indisin içindeyse top-5 başarı arttırılır.

    # GPT-4o ve DeepSeek top-1, top-5 başarıları hesaplanır.
    total = len(df)
    print(f"\n{model_name} Sonuçları:")
    print("GPT-4o Top-1:", round(top1_gpt / total, 4))
    print("GPT-4o Top-5:", round(top5_gpt / total, 4))
    print("DeepSeek Top-1:", round(top1_deep / total, 4))
    print("DeepSeek Top-5:", round(top5_deep / total, 4))

    # Etiketlere göre top-1, top-5 başarıları hesaplanır.
    df['top1_gpt-4o'] = top1_gpt_list
    df['top5_gpt-4o'] = top5_gpt_list
    df['top1_deepseek'] = top1_deep_list
    df['top5_deepseek'] = top5_deep_list

    grup_ortalama = df.groupby('etiket')[['top1_gpt-4o', 'top5_gpt-4o', 'top1_deepseek', 'top5_deepseek']].mean()

    print("\nEtiketlere Göre Başarı Ortalamaları:")
    print(grup_ortalama)

    # Başarı grafikleri çizilir.
    ax = grup_ortalama.plot(kind='bar', figsize=(10,5))
    plt.title(f"{model_name} - Etikete Göre Top-1 / Top-5 Başarı Oranları")
    plt.ylabel("Başarı Oranı")
    plt.xlabel("Etiket")
    plt.xticks(rotation=0)
    plt.ylim(0, 1.0)
    plt.grid(axis='y')
    plt.tight_layout()
    plt.savefig(f"{model_name}_basari_grafik.png")
    plt.close()

print("\nTüm modeller işlendi ve grafikler kaydedildi!")