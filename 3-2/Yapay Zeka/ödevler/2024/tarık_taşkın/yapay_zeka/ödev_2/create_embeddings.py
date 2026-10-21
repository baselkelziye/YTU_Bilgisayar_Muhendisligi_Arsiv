import pandas as pd
import torch
from transformers import AutoTokenizer, AutoModel
from tqdm import tqdm

# Uygun GPU varsa kullanılır.
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Kullanılan cihaz: {device}")
print(torch.cuda.get_device_name(0))

def get_embeddings(text_list, tokenizer, model, batch_size=32):
    embeddings = []
    model.to(device)
    model.eval()

    for i in tqdm(range(0, len(text_list), batch_size)):
        batch = text_list[i:i+batch_size]
        inputs = tokenizer(batch, padding=True, truncation=True, return_tensors="pt", max_length=512)
        inputs = {k: v.to(device) for k, v in inputs.items()}

        with torch.no_grad():
            outputs = model(**inputs)

        last_hidden = outputs.last_hidden_state
        attention_mask = inputs['attention_mask']
        mask_expanded = attention_mask.unsqueeze(-1).expand(last_hidden.size()).float()
        sum_embeddings = torch.sum(last_hidden * mask_expanded, 1)
        sum_mask = torch.clamp(mask_expanded.sum(1), min=1e-9)
        mean_pooled = sum_embeddings / sum_mask

        embeddings.append(mean_pooled.cpu())

    return torch.cat(embeddings)


# Veriler yüklenir.
filename = "1k"
path = f"embeddings/{filename}_"
df = pd.read_excel(f"{filename}.xlsx")
df.columns = ['soru', 'gpt4o', 'deepseek', 'etiket'] 

questions = ["query: " + str(x) for x in df['soru']]
gpt4o_answers = ["passage: " + str(x) for x in df['gpt4o']]
deepseek_answers = ["passage: " + str(x) for x in df['deepseek']]

# Modeller
models = [
    ("e5", "intfloat/multilingual-e5-large-instruct"),
    ("cosmosE5", "ytu-ce-cosmos/turkish-e5-large"),
    ("jina", "jinaai/jina-embeddings-v3")
]

# Her modelin soru, gpt-4o, deepseek vektörleri oluşturulup kaydedilir.
for model_name, model_path in models:
    print(f"{model_name} için embedding başlıyor...")

    tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
    model = AutoModel.from_pretrained(model_path, trust_remote_code=True)

    q_emb = get_embeddings(questions, tokenizer, model)
    gpt_emb = get_embeddings(gpt4o_answers, tokenizer, model)
    deep_emb = get_embeddings(deepseek_answers, tokenizer, model)

    torch.save(q_emb, f"{path}{model_name}_questions.pt")
    torch.save(gpt_emb, f"{path}{model_name}_gpt4o.pt")
    torch.save(deep_emb, f"{path}{model_name}_deepseek.pt")

    print(f"{model_name} embeddingleri kaydedildi.\n")

print("Tüm embedding işlemleri tamamlandı.")