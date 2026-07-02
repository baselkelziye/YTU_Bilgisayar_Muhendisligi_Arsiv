"""
Yardımcı fonksiyonlar
Veri formatlama, parsing ve diğer utility fonksiyonları
"""

import re
import torch
from typing import List, Tuple, Optional


def format_dataset_for_grpo(example, tokenizer=None):
    """
    Veri setini GRPO için hazırlar.
    """
    messages = example['messages']
    
    # Mesajları formatla (instruct format için - Model Card uyumlu)
    # Model System prompt desteklemiyor, veri setinde zaten User içine gömülü
    formatted_prompt = ""
    for msg in messages:
        role = msg["role"]
        content = msg["content"]
        # Rolleri basitçe haritala
        if role == "user":
            formatted_prompt += f"### Kullanıcı:\n{content}\n\n"
        elif role == "system": # Eski veri setinden kalma ihtimaline karşı
             formatted_prompt += f"### Sistem:\n{content}\n\n"
            
    formatted_prompt += "### Asistan:\n"
    
    # NOT: "Açıklama:" eklemesini KALDIRIYORUZ.
    # Modelin kendisinin "Açıklama:" formatını üretmesi gerekiyor,
    # aksi takdirde ödül fonksiyonu completion içinde bu tag'i bulamıyor ve ceza veriyor.
    
    return {
        "prompt": formatted_prompt,
        "messages": messages,  # Orijinal mesajları da tutalım
        "correct_answer": example['correct_answer']
    }


def get_correct_answers_from_dataset(dataset):
    """Dataset'ten correct_answer'ları çıkarır"""
    return [ex['correct_answer'] for ex in dataset]


def generate_answer_with_model(model, tokenizer, messages: list, max_new_tokens: int = 512, temperature: float = 0.7) -> str:
    """Model'e mesajları gönderip cevap üretir"""

    # Mesajları formatla (instruct format için - Model Card uyumlu)
    # Model System prompt desteklemiyor, veri setinde zaten User içine gömülü
    formatted_prompt = ""
    for msg in messages:
        role = msg["role"]
        content = msg["content"]
        # Rolleri basitçe haritala
        if role == "user":
            formatted_prompt += f"### Kullanıcı:\n{content}\n\n"
        elif role == "system": # Eski veri setinden kalma ihtimaline karşı
             formatted_prompt += f"### Sistem:\n{content}\n\n"
            
    formatted_prompt += "### Asistan:\n"

    # Modelin maksimum bağlam uzunluğunu al (GPT-2 için genelde 1024)
    max_ctx_length = getattr(getattr(model, "config", None), "n_positions", None)
    if max_ctx_length is None:
        max_ctx_length = getattr(getattr(model, "config", None), "max_position_embeddings", 1024)
    if max_ctx_length is None:
        max_ctx_length = 1024

    # Girdi prompt'unu tokenize et ve gerektiğinde kırp
    inputs = tokenizer(formatted_prompt, return_tensors="pt", truncation=True, max_length=max_ctx_length)

    # Girdi uzunluğuna göre güvenli max_new_tokens hesapla
    input_length = inputs["input_ids"].shape[-1]
    # En az 1 token üretilsin, bağlam + yeni token toplamı max_ctx_length'i geçmesin
    available_for_generation = max(max_ctx_length - input_length, 1)
    effective_max_new_tokens = min(max_new_tokens, available_for_generation)

    if torch.cuda.is_available():
        inputs = {k: v.to(model.device) for k, v in inputs.items()}

    with torch.no_grad():
        outputs = model.generate(
            **inputs,
            max_new_tokens=effective_max_new_tokens,
            temperature=temperature,
            do_sample=True,
            pad_token_id=tokenizer.eos_token_id,
            eos_token_id=tokenizer.eos_token_id,
        )
    
    # decode sadece yeni tokenları yap
    generated_ids = outputs[0][input_length:]
    generated_text = tokenizer.decode(generated_ids, skip_special_tokens=True).strip()
    
    return generated_text


def parse_model_output(text: str) -> Tuple[Optional[str], Optional[str], bool]:
    """
    Model çıktısından cevabı parse eder (Basit Format)
    
    Args:
        text: Model çıktısı
    
    Returns:
        tuple: (düşünce, cevap, format_uygun)
    """
    düşünce = None
    cevap = None
    format_uygun = False
    
    # Açıklama kısmını al
    düşünce_pattern = r'Açıklama:(.*?)(?=Cevap:|$)'
    düşünce_match = re.search(düşünce_pattern, text, re.DOTALL | re.IGNORECASE)
    if düşünce_match:
        düşünce = düşünce_match.group(1).strip()
    
    # 1. Öncelik: "Cevap: A" formatı (ideal format)
    cevap_pattern = r'Cevap:\s*([A-E])'
    cevap_match = re.search(cevap_pattern, text, re.IGNORECASE)
    if cevap_match:
        cevap = cevap_match.group(1).upper()
        format_uygun = True
    else:
        # 2. Alternatif formatlar (doğruluk için sayılır, format_uygun=False)
        alternative_patterns = [
            r"doğru\s+cevap\s+([A-E])",           # "doğru cevap A"
            r"cevap\s+([A-E])\s*'?(?:d[ıi]r|ol)", # "cevap A'dır", "cevap A olmalı"
            r"([A-E])\s+şıkkı\s*(?:doğru|cevap)", # "A şıkkı doğru"
            r"([A-E])\s+seçeneği",                # "A seçeneği"
            r"yanıt\s*:?\s*([A-E])",              # "yanıt: A" veya "yanıt A"
            r"sonuç\s*:?\s*([A-E])",              # "sonuç: A"
        ]
        
        for pattern in alternative_patterns:
            match = re.search(pattern, text, re.IGNORECASE)
            if match:
                cevap = match.group(1).upper()
                break
        
        # 3. Fallback: Metindeki son bağımsız A-E harfi
        if cevap is None:
            cevap_pattern_fallback = r'\b([A-E])\b'
            cevap_matches = re.findall(cevap_pattern_fallback, text, re.IGNORECASE)
            if cevap_matches:
                cevap = cevap_matches[-1].upper()
    
    return düşünce, cevap, format_uygun
