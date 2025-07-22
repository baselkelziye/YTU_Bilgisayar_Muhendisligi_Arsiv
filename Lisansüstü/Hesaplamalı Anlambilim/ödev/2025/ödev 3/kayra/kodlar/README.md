# 🧑‍🔬  Turkish GPT-2 Fine-Tuning  

Bu depo turkish-gpt-2'nin ince ayarı için kod, veri ve dokümantasyonu içerir.  
Amaç; iki Türkçe GPT-2 modelini (*medium & large*) GPT-4o ve DeepSeek çıktılarıyla **instruction fine-tuning** edip,
50 adet özgün “sınama” sorusu üzerinden karşılaştırmaktır.  
Tüm kodlar, **Google Colab’da sorunsuz çalışacak** şekilde otomatik ortam kontrolleri (`is_colab()`) içerir.

## 📂 Dizin / Dosya Yapısı

| Yol / Dosya | Açıklama |
|-------------|----------|
| `tanım.pdf` | Ödev metni & teslim şartları. |
| `train.ipynb`  | 4 adet LoRA-tabanlı model eğitimi: <br>▸ Veri hazırlama <br>▸ Tokenizer / model yükleme <br>▸ Quantization (4-/8-/16-bit) <br>▸ Eğitim döngüsü & checkpoint yönetimi. |
| `sinama.ipynb` | İnference / karşılaştırma betiği: <br>▸ Eğitilen modelleri tek tek yükler <br>▸ `sinama_sorulari.csv` üzerindeki cevapları üretir <br>▸ Sonuçları `/sonuclar` klasörüne kaydeder. |
| `sinama_sorulari.csv` | 50 adet deneme sorusu. |
| `soru_cevap.csv` | GPT-4o & DeepSeek yanıtlarını içeren asıl fine-tuning veri seti (Google Sheets’ten dışa aktarılır). |
| `README.md` | Bu dosya. |
| `sonuclar/` | Her model için oluşturulan cevap CSV’leri. |

---

## 🔍 `sinama_sorulari.csv` Detayları  

| Sütun | İçerik |
|-------|--------|
| `soru`   | Sorunun tam metni (Türkçe). |
| `zorluk` | 1: Kolay &nbsp; 2: Orta &nbsp; 3: Zor |

Dosya; eğitim verisinde **yer almayan** elle oluşturduğum 50 sorudan oluşur ve model genellemesini sınamak için kullanılır.  
`sinama.ipynb`, bu CSV’yi okuyup her soruyu prompt biçimine dönüştürür:

```python
<SORU> … </SORU> <CEVAP> <|endoftext|>
```
Model EOS ürettiğinde durdurulur, böylece yalnızca yanıt kısmı kaydedilir.

## ⚡ Hızlı Başlangıç (Google Colab)

1. Depoyu Colab’a klonlayın  
   ```bash
   !git clone https://github.com/kaayra2000/turkish_gpt2_finetuning.git
   %cd odev-instruction-finetune
   ```
1. Gereksinimleri yükleyin

1. Eğitimi başlatın
    train.ipynb dosyasını açın ve `Runtime` > `Run all` ile çalıştırın.

1. Eğitimi tamamladıktan sonra `sinama.ipynb` dosyasını açın ve `Runtime` > `Run all` ile çalıştırın.
    Çıktılar `sonuclar/` klasörüne kaydedilecektir.

## 🏋️‍♂️ Eğitim Ayrıntıları

- **Model**: `turkish-gpt2-medium` ve `turkish-gpt2-large` (Hugging Face)
- **LoRA**: `peft` kütüphanesi ile ince ayar yapıldı.
- **Veri Kümesi**: `soru_cevap.csv` (GPT-4o ve DeepSeek yanıtları)
- **Eğitim Süresi**: 1-2 saat * model sayısı (Google Colab Pro)

## 🧪 Sınama Ayrıntıları

- **Model**: `turkish-gpt2-medium` ve `turkish-gpt2-large` (Hugging Face)
- **Sınama Soruları**: `sinama_sorulari.csv` (50 adet özgün soru)
- **Sınama Süresi**: 1-2 saat * model sayısı (Google Colab Pro)
- **Sonuçlar**: `sonuclar/` klasöründe her model için ayrı CSV dosyaları.