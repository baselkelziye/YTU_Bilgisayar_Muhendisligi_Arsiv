from transformers import AutoTokenizer, AutoModelForCausalLM
import torch
import transformers

# ------------------------------------------------------------
# MODEL VE TOKENIZER YÜKLEME
# ------------------------------------------------------------
# HuggingFace üzerindeki Türkçe Gemma tabanlı model.
model_id = "ytu-ce-cosmos/Turkish-Gemma-9b-T1"

# Tokenizer: metni tokenlere çevirir.
tokenizer = AutoTokenizer.from_pretrained(model_id)

# Model: Causal Language Model olarak yükleniyor.
# dtype=bfloat16 → daha az bellek kullanıp daha hızlı çalışması için
# device_map="auto" → CPU/GPU hangisi varsa otomatik olarak ayarlar.
model = AutoModelForCausalLM.from_pretrained(
    model_id,
    dtype=torch.bfloat16,
    device_map="auto",
)

# ------------------------------------------------------------
# TEXT-GENERATION PIPELINE
# ------------------------------------------------------------
# HuggingFace 'pipeline' arayüzü, modeli kolayca çalıştırmak için.
# Ancak burada generate() fonksiyonunu manuel kullanacağız.
pipeline = transformers.pipeline(
    "text-generation",
    model=model_id,
    model_kwargs={"torch_dtype": torch.bfloat16},
    device_map="auto",
)

# ------------------------------------------------------------
# CHAT FORMATINDA MESAJA UYGUN GİRDİ OLUŞTURMA
# ------------------------------------------------------------
# Mesajı chat formatında hazırlıyoruz.
# Bu format, modelin eğitildiği sohbet yapısına uygundur.
messages = [
    {
        "role": "user",
        "content": (
            "İstanbul halkı, timsahları evcilleştirip balkonlarda "
            "beslemeyi alışkanlık hale getirmiştir. "
            "Hangi timsah türleri en çok tercih edilir?"
        )
    }
]

# ------------------------------------------------------------
# apply_chat_template:
# Mesajları modelin beklediği şekilde dönüştürür.
# add_generation_prompt=True → modelin cevabı için gerekli işaret eklenir.
# return_tensors="pt" → PyTorch tensörü olarak döndürür.
# ------------------------------------------------------------
input_ids = tokenizer.apply_chat_template(
    messages,
    add_generation_prompt=True,
    return_tensors="pt"
).to(model.device)

# ------------------------------------------------------------
# GENERATION DURDURMA KOŞULLARI
# ------------------------------------------------------------
# Model iki durumda duracak:
# 1) eos_token_id (genel bitiş tokeni)
# 2) "<end_of_turn>" tokeni (söz sırasının bittiğini gösteren özel işaret)
# ------------------------------------------------------------
terminators = [
    pipeline.tokenizer.eos_token_id,
    pipeline.tokenizer.convert_tokens_to_ids("<end_of_turn>")
]

# ------------------------------------------------------------
# CEVABI ÜRETME
# ------------------------------------------------------------
# model.generate:
# - max_new_tokens: En fazla üretilecek token sayısı
# - eos_token_id: Üretimin durma koşulları
# - do_sample=False → deterministik çıktı (sampling yok → daha stabil cevap)
# ------------------------------------------------------------
outputs = model.generate(
    input_ids,
    max_new_tokens=4096,
    eos_token_id=terminators,
    do_sample=False,
)

# ------------------------------------------------------------
# CEVABI YALNIZCA YENİ TOKENLERDEN ALMA
# input_ids kadar olan kısmı atıyoruz.
# Geri kalan modelin ürettiği cevaptır.
# ------------------------------------------------------------
response = outputs[0][input_ids.shape[-1]:]

# ------------------------------------------------------------
# TOKENLERİ GERİ METNE ÇEVİRME
# skip_special_tokens=True → özel tokenler (bos, eos, turn vb.) görünmez
# ------------------------------------------------------------
print(tokenizer.decode(response, skip_special_tokens=True))


# ------------------------------------------------------------
# ÖRNEK ÇIKTI
# Model burada "<think>...</think>" gibi görünmeyen bir akıl yürütme
# kısmı üretir; sonrasında gerçek kullanıcıya yönelik cevabı gelir.
#
# Bu soru gerçek dışıdır → model bunu belirtir.
# ------------------------------------------------------------