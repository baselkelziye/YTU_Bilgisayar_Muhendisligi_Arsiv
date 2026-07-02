###**FAZ 1: Veri Hazırlığı ve Formatlama (Data Pipeline)**Modelin ne göreceği ve bizden ne beklediği bu aşamada belirlenir. GRPO, modelin "düşünce zinciri" (Chain of Thought) üretmesini bekler.

* **Hedef:** `turkish_mmlu` veri setini indirip, mantık/çıkarım odaklı olanları filtrelemek ve GRPO formatına dönüştürmek.
* **Yapılacaklar:**
1. `datasets` kütüphanesi ile veriyi çek.
2. **Filtreleme:** `subject` alanına göre mantık, matematik, fizik, bilgisayar bilimleri gibi kategorileri seç. (Tarih, hukuk gibi ezber konularını ele).
3. **Prompt Şablonu:** Veriyi şu formata çeviren bir fonksiyon yaz:
* *System:* "Soruyu adım adım düşünerek çöz. Cevabını `<cevap>` etiketi içine yaz."
* *User:* [Soru Metni] + [Şıklar]


4. **Split:** Rastgele karıştırıp 1000 satır `train`, 500 satır `test` olarak `.jsonl` veya HuggingFace Dataset formatında kaydet.


* **Çıktı:** `train_dataset` ve `test_dataset` objeleri.

###**FAZ 2: Base Model ve Temel Değerlendirme (Zero-Shot Baseline)**Eğitime başlamadan önce, modelin hiç eğitilmemiş halinin performansını ve değerlendirme kodunun çalışıp çalışmadığını görmeliyiz.

* **Hedef:** `ytu-ce-cosmos/turkish-gpt2-large-750m-instruct-v0.1` modelini yüklemek ve değerlendirme metriğini kurmak.
* **Yapılacaklar:**
1. Modeli ve Tokenizer'ı yükle.
2. **Test Fonksiyonu:** Test setindeki 500 soruyu modele sorup cevabı parse eden (ayrıştıran) bir script yaz.
3. Modelin şu anki (eğitimsiz) doğruluk oranını ölç. Bu senin "Baseline" skorun olacak.


* **Çıktı:** `baseline_results.csv` (Ham modelin başarısı).

###**FAZ 3: Standart Ödül Fonksiyonunun Kodlanması (The Core)**GRPO'nun kalbi burasıdır. Modelin ürettiği metni alıp puanlayan fonksiyonu yazacağız.

* **Hedef:** Python tabanlı, Regex kullanan sağlam bir ödül fonksiyonu.
* **Yapılacaklar:**
1. **Format Reward:** Model `<düşünce>...</düşünce>` ve `<cevap>...</cevap>` taglerini kullanmış mı?
2. **Accuracy Reward:** `<cevap>` içindeki harf (A, B, C, D) doğru şıkla (Ground Truth) eşleşiyor mu?
3. Bu fonksiyonu birkaç örnek string ile (doğru format/yanlış cevap, yanlış format/doğru cevap vb.) test et (Unit Test gibi).


* **Çıktı:** `def reward_function(prompts, completions, ...):` bloğu.

###**FAZ 4: GRPOTrainer Konfigürasyonu ve İlk Run (Training Setup)**TRL kütüphanesini kullanarak eğitim döngüsünü kuruyoruz.

* **Hedef:** Kodun hatasız bir şekilde eğitimi başlatabilmesi (OOM hatası almadan).
* **Yapılacaklar:**
1. **LoRA Ayarları:** 750M model küçük olsa da GRPO çoklu çıktı ürettiği için VRAM şişebilir. `peft` ile LoRA config hazırla.
2. **GRPO Config:**
* `num_generations`: 4 (veya VRAM yetmezse 2).
* `max_completion_length`: Modelin ne kadar uzun düşünebileceği.


3. **Dummy Run:** Sadece 1 batch (örneğin 4 soru) ile kodu çalıştır. Hata alıyor mu? Loss düşüyor mu? WandB logları akıyor mu?


* **Çıktı:** Çalışan bir `train.py` dosyası.

###**FAZ 5: Tam Eğitim ve Karşılaştırma (Execution)**Artık her şey hazır. Modeli tam veri setiyle eğitiyoruz.

* **Hedef:** Base kodun ürettiği ilk modeli (Standard Reward Model) elde etmek.
* **Yapılacaklar:**
1. 1000 soruluk train setiyle eğitimi başlat.
2. Eğitim bittikten sonra LoRA adaptörlerini kaydet.
3. Faz 2'deki değerlendirme scriptini bu yeni model üzerinde çalıştır.
4. Baseline (Faz 2) ile bu sonucu karşılaştır.


* **Çıktı:** `standard_reward_model_v1` ve performans raporu.

---

**Öneri:** Kodlamaya **Faz 1 (Veri Hazırlığı)** ile başlayalım. Çünkü veri formatı netleşmeden diğer fazlara geçemeyiz.

Hazır olduğunda "Faz 1'e başlayalım" demen yeterli.