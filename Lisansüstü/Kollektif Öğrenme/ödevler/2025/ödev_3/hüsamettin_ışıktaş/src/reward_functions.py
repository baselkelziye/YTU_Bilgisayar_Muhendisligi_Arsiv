"""
Ödül fonksiyonları
Basitleştirilmiş format için ödül fonksiyonu ve varyasyonları.
"""

import re
from typing import List

# Tutarlı ölçekler için sabitler
SPAM_PENALTY = -3.0  # Tekrarlayan başlıklar
MULTIPLE_ANSWER_PENALTY = -5.0  # Birden fazla farklı şık
CORRECT_ANSWER_REWARD = 2.0  # Doğru cevap
FORMAT_BROKEN_PENALTY = -2.0  # Bozuk format
MIN_WORD_PENALTY = -1.0  # Çok kısa açıklama (< 5 kelime)


def check_repetition(text: str) -> float:
    """
    Tekrar eden n-gram kontrolü.
    Anlamsız tekrarları cezalandırır.
    
    Returns:
        float: Ceza puanı (0 veya negatif)
    """
    if not text:
        return 0
    
    words = text.lower().split()
    if len(words) < 6:
        return 0
    
    # 3-gram tekrar kontrolü
    trigrams = [tuple(words[i:i+3]) for i in range(len(words)-2)]
    if len(trigrams) == 0:
        return 0
    
    unique_ratio = len(set(trigrams)) / len(trigrams)
    
    if unique_ratio < 0.4:  # %40'tan az benzersiz trigram = çok tekrar
        return -2.0
    elif unique_ratio < 0.6:  # %60'tan az = orta tekrar
        return -0.5
    return 0


def check_spam_and_format(completion: str, correct_answer: str) -> tuple[float, str, str]:
    """
    Spam kontrolü, format kontrolü ve cevap çıkarma işlemlerini yapar.
    Ortak ceza/ödül mantığını içerir.
    
    Returns:
        score: Şu ana kadar hesaplanan ceza/ödül puanı
        predicted_answer: Tahmin edilen cevap (varsa)
        aciklama_text: Açıklama metni (varsa)
    """
    score = 0.0
    
    # 0. Spam ve Tekrar Kontrolü
    cevap_count = completion.count("Cevap:")
    aciklama_count = completion.count("Açıklama:")
    
    if cevap_count > 1 or aciklama_count > 1:
        score += SPAM_PENALTY  # Tekrarlayan başlıklar
        
    # Şık deneme kontrolü (Birden fazla farklı şıkkı Cevap olarak sunma)
    cevap_pattern = r'Cevap:\s*([A-E])'
    found_answers = re.findall(cevap_pattern, completion, re.IGNORECASE)
    unique_answers = set([a.upper() for a in found_answers])
    
    if len(unique_answers) > 1:
        score += MULTIPLE_ANSWER_PENALTY  # Birden fazla farklı şık
        
    # 1. Format ve Cevap Çıkarma
    aciklama_start = completion.find("Açıklama:")
    cevap_start = completion.find("Cevap:")
    
    predicted_answer = None
    aciklama_text = ""
    
    if aciklama_start != -1 and cevap_start != -1 and aciklama_start < cevap_start:
        # Açıklama metnini al
        aciklama_text = completion[aciklama_start+9:cevap_start].strip()
        
        # Minimum kelime kontrolü
        word_count = len(aciklama_text.split()) if aciklama_text else 0
        if word_count < 5:
            score += MIN_WORD_PENALTY  # Çok kısa açıklama
        
        # Tekrar kontrolü
        score += check_repetition(aciklama_text)
        
        # Cevabı al
        cevap_part = completion[cevap_start:].strip()
        match = re.search(r'Cevap:\s*([A-E])', cevap_part, re.IGNORECASE)
        
        if match:
            predicted_answer = match.group(1).upper()
            if predicted_answer == correct_answer.upper():
                score += CORRECT_ANSWER_REWARD  # Doğru cevap
        else:
            score -= 1.0  # Cevap formatı bozuk (Şık belirtmemiş)
    else:
        # Format bozuksa ağır ceza
        score += FORMAT_BROKEN_PENALTY
        
    return score, predicted_answer, aciklama_text


def reward_function_short(completions: List[str], correct_answers: List[str]) -> List[float]:
    """
    Fonksiyon 1: Kısa Cevap
    - Doğru cevapta ödül
    - Kelime sayısı: 7-30 arası ideal
    - < 7: ceza, > 30: ceza
    - Şık belirtmezse ceza
    - Spam cezası
    """
    rewards = []
    
    for completion, correct_answer in zip(completions, correct_answers):
        reward, predicted_answer, aciklama_text = check_spam_and_format(completion, correct_answer)
        
        # Eğer format düzgünse kelime sayısı kontrolü yap
        if aciklama_text:
            word_count = len(aciklama_text.split())
            
            if 7 <= word_count <= 30:
                reward += 1.0 # İdeal aralık ödülü
            else:
                # Soft ceza: Aralıktan uzaklaştıkça artan ceza
                if word_count < 7:
                    diff = 7 - word_count
                    reward -= diff * 0.2 # Her eksik kelime için 0.2 ceza
                else: # > 30
                    diff = word_count - 30
                    reward -= diff * 0.1 # Her fazla kelime için 0.1 ceza
        
        rewards.append(float(reward))
        
    return rewards


def reward_function_long(completions: List[str], correct_answers: List[str]) -> List[float]:
    """
    Fonksiyon 2: Uzun Cevap
    - Doğru cevapta ödül
    - Kelime sayısı: 20-100 arası ideal
    - < 20: ceza, > 100: ceza
    - Şık belirtmezse ceza
    - Spam cezası
    """
    rewards = []
    
    for completion, correct_answer in zip(completions, correct_answers):
        reward, predicted_answer, aciklama_text = check_spam_and_format(completion, correct_answer)
        
        if aciklama_text:
            word_count = len(aciklama_text.split())
            
            if 20 <= word_count <= 100:
                reward += 1.0 # İdeal aralık ödülü
            else:
                if word_count < 20:
                    diff = 20 - word_count
                    reward -= diff * 0.1 
                else: # > 100
                    diff = word_count - 100
                    reward -= diff * 0.05 
        
        rewards.append(float(reward))
        
    return rewards


def reward_function_turkish(completions: List[str], correct_answers: List[str]) -> List[float]:
    """
    Fonksiyon 3: Türkçe Karakter
    - Doğru cevapta ödül
    - Türkçe karakter (ğ,ü,ş,ı,ö,ç) oranı > %3 ise ödül
    - Yabancı karakter (q,w,x) oranı > %10 ise ceza
    """
    rewards = []
    tr_chars = set("ğüşıöçĞÜŞİÖÇ")
    en_chars = set("qwxQWX")
    
    for completion, correct_answer in zip(completions, correct_answers):
        reward, predicted_answer, aciklama_text = check_spam_and_format(completion, correct_answer)
        
        if aciklama_text:
            total_len = len(aciklama_text)
            if total_len > 0:
                tr_count = sum(1 for c in aciklama_text if c in tr_chars)
                en_count = sum(1 for c in aciklama_text if c in en_chars)
                
                tr_ratio = tr_count / total_len
                en_ratio = en_count / total_len
                
                # Türkçe karakter ödülü (eşik %3'e düşürüldü)
                if tr_ratio > 0.03:
                    reward += 1.0
                
                # Yabancı karakter cezası (sadece %10 üzerinde)
                if en_ratio > 0.10:
                    reward -= 2.0
                    
        rewards.append(float(reward))
        
    return rewards


def reward_function_connectives(completions: List[str], correct_answers: List[str]) -> List[float]:
    """
    Fonksiyon 4: Bağlaçlar
    - Doğru cevapta ödül
    - Sebep-sonuç bağlaçları kullanımı
    - Max 3 bağlaca kadar ödül, fazlası ceza
    """
    rewards = []
    connectives = ["çünkü", "sebebiyle", "dolayısıyla", "yani", "bu yüzden", "nedeniyle", "sonuç olarak"]
    
    for completion, correct_answer in zip(completions, correct_answers):
        reward, predicted_answer, aciklama_text = check_spam_and_format(completion, correct_answer)
        
        if aciklama_text:
            text_lower = aciklama_text.lower()
            count = 0
            for conn in connectives:
                count += text_lower.count(conn)
            
            if count <= 3:
                reward += count * 0.5 # Her bağlaç için 0.5 ödül (max 1.5)
            else:
                reward += 1.5 # İlk 3'ü için ödül
                excess = count - 3
                reward -= excess * 0.5 # Fazlası için ceza
                
        rewards.append(float(reward))
        
    return rewards


def reward_function_simple(completions: List[str], correct_answers: List[str]) -> List[float]:
    """
    Basitleştirilmiş format için ödül fonksiyonu.
    
    Beklenen Format:
    Açıklama: ...
    Cevap: [A-E]
    
    Args:
        completions: Model çıktıları
        correct_answers: Doğru cevaplar
    
    Returns:
        rewards: Ödül skorları
    """
    rewards = []
    
    for completion, correct_answer in zip(completions, correct_answers):
        reward = 0.0
        
        # 0. Spam ve Tekrar Kontrolü (tutarlı ölçekler)
        cevap_count = completion.count("Cevap:")
        aciklama_count = completion.count("Açıklama:")
        
        if cevap_count > 1 or aciklama_count > 1:
            reward += SPAM_PENALTY
            
        # Şık deneme kontrolü
        cevap_pattern = r'Cevap:\s*([A-E])'
        found_answers = re.findall(cevap_pattern, completion, re.IGNORECASE)
        unique_answers = set([a.upper() for a in found_answers])
        
        if len(unique_answers) > 1:
            reward += MULTIPLE_ANSWER_PENALTY
            
        # 1. Format Kontrolü (Açıklama ve Cevap başlıkları)
        has_aciklama = "Açıklama:" in completion
        has_cevap = "Cevap:" in completion
        
        if has_aciklama:
            reward += 0.2
        else:
            reward -= 0.1
            
        if has_cevap:
            reward += 0.2
        else:
            reward -= 0.1
            
        # Sıralama Kontrolü: Açıklama, Cevap'tan önce gelmeli
        if has_aciklama and has_cevap:
            idx_aciklama = completion.find("Açıklama:")
            idx_cevap = completion.find("Cevap:")
            
            if idx_aciklama < idx_cevap:
                reward += 0.5  # Doğru sıralama bonusu
                
                # Açıklama metnini çıkar ve kontrol et
                aciklama_text = completion[idx_aciklama+9:idx_cevap].strip()
                word_count = len(aciklama_text.split()) if aciklama_text else 0
                
                # Minimum kelime kontrolü
                if word_count < 5:
                    reward += MIN_WORD_PENALTY
                
                # Tekrar kontrolü
                reward += check_repetition(aciklama_text)
            else:
                reward -= 0.2  # Yanlış sıralama cezası
            
        # 2. Cevap Çıkarma
        predicted_answer = None
        match = re.search(cevap_pattern, completion, re.IGNORECASE)
        
        if match:
            predicted_answer = match.group(1).upper()
            reward += 0.2  # Formatı doğru uyguladığı için ekstra puan
        else:
            # Fallback: Son kısımdaki harfe bak
            fallback = re.findall(r'\b([A-E])\b', completion[-50:])
            if fallback:
                predicted_answer = fallback[-1].upper()
        
        # 3. Doğruluk Kontrolü (tutarlı ölçek)
        if predicted_answer and predicted_answer == correct_answer.upper():
            reward += CORRECT_ANSWER_REWARD
            
        # Ölçek çarpanı kaldırıldı (tutarlılık için)
        rewards.append(float(reward))
        
    return rewards


REWARD_FUNCTIONS = {
    "short": reward_function_short,
    "long": reward_function_long,
    "turkish": reward_function_turkish,
    "connectives": reward_function_connectives,
    "simple": reward_function_simple
}


def test_reward_function():
    """Ödül fonksiyonlarını unit testlerle doğrular"""
    print("="*60)
    print("ÖDÜL FONKSİYONLARI TEST EDİLİYOR")
    print("="*60)
    
    # Normal test case
    test_case = {
        "completion": "Açıklama: Bu soruyu analiz ediyorum çünkü yani dolayısıyla cevap bu olmalı.\nCevap: B",
        "correct_answer": "B"
    }
    
    print("\n📝 Test 1: Normal Completion (Doğru cevap, 3 bağlaç)")
    print(f"   Input: {test_case['completion'][:60]}...")
    
    r_short = reward_function_short([test_case["completion"]], [test_case["correct_answer"]])[0]
    r_long = reward_function_long([test_case["completion"]], [test_case["correct_answer"]])[0]
    r_tr = reward_function_turkish([test_case["completion"]], [test_case["correct_answer"]])[0]
    r_conn = reward_function_connectives([test_case["completion"]], [test_case["correct_answer"]])[0]
    r_simple = reward_function_simple([test_case["completion"]], [test_case["correct_answer"]])[0]
    
    print(f"   Short: {r_short:.2f} | Long: {r_long:.2f} | Turkish: {r_tr:.2f} | Connectives: {r_conn:.2f} | Simple: {r_simple:.2f}")
    
    # Spam test case
    spam_case = {
        "completion": "Açıklama: Test\nCevap: A\nAçıklama: Test2\nCevap: B",
        "correct_answer": "A"
    }
    
    print("\n🚫 Test 2: Spam Completion (Tekrarlayan başlıklar + farklı şıklar)")
    r_spam = reward_function_simple([spam_case["completion"]], [spam_case["correct_answer"]])[0]
    print(f"   Simple Reward: {r_spam:.2f} (beklenen: negatif)")
    
    # Tekrar test case
    repeat_case = {
        "completion": "Açıklama: çünkü çünkü çünkü çünkü çünkü çünkü çünkü çünkü\nCevap: B",
        "correct_answer": "B"
    }
    
    print("\n🔄 Test 3: Tekrarlı Completion (Anlamsız tekrar)")
    r_repeat = reward_function_connectives([repeat_case["completion"]], [repeat_case["correct_answer"]])[0]
    print(f"   Connectives Reward: {r_repeat:.2f} (beklenen: düşük veya negatif)")
    
    # Kısa test case
    short_case = {
        "completion": "Açıklama: Evet\nCevap: C",
        "correct_answer": "C"
    }
    
    print("\n📏 Test 4: Çok Kısa Completion (< 5 kelime)")
    r_too_short = reward_function_short([short_case["completion"]], [short_case["correct_answer"]])[0]
    print(f"   Short Reward: {r_too_short:.2f} (beklenen: cezalı)")
    
    print("\n" + "="*60)
    print("✓ Tüm ödül fonksiyonu testleri tamamlandı!")
    print("="*60)


def create_reward_function_wrapper(dataset, reward_func_name="short"):
    """
    Dataset için reward function wrapper oluşturur.
    
    Args:
        dataset: HuggingFace dataset
        reward_func_name: Kullanılacak ödül fonksiyonu ismi
    
    Returns:
        grpo_reward_function: GRPO için uygun ödül fonksiyonu
    """
    reward_func = REWARD_FUNCTIONS.get(reward_func_name, reward_function_short)
    # print(f"Kullanılan Ödül Fonksiyonu: {reward_func_name}")
    
    correct_answers_list = [ex['correct_answer'] for ex in dataset]
    
    def grpo_reward_function(completions, prompts=None, **kwargs):
        """
        GRPO için ödül fonksiyonu.
        """
        num_completions = len(completions)
        
        if "indices" in kwargs:
            indices = kwargs["indices"][:num_completions]
        elif prompts is not None:
            indices = list(range(min(len(prompts), num_completions)))
        else:
            indices = list(range(num_completions))
        
        current_correct_answers = []
        for idx in indices:
            if idx < len(correct_answers_list):
                current_correct_answers.append(correct_answers_list[idx])
            else:
                current_correct_answers.append("A")
        
        if len(current_correct_answers) < num_completions:
            needed = num_completions - len(current_correct_answers)
            current_correct_answers.extend(correct_answers_list[:needed])
        
        current_correct_answers = current_correct_answers[:num_completions]
        
        return reward_func(completions, current_correct_answers)
    
    return grpo_reward_function
