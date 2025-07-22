# TurkNLP-ModelBench
not defterleri Google Colab üzerinde rahatça çalışabilecek şekilde tasarlanmıştır. Bu not defterleri, Türkçe doğal dil işleme (NLP) görevleri için veri kümesi parçalama, büyük dil modellerinin (LLM) değerlendirilmesi ve makine öğrenmesi (ML) modellerinin eğitimi ve değerlendirilmesi gibi işlemleri gerçekleştirmek için kullanılmaktadır.

## 1. Veri Kümesi Parçalama (veri_kumesi_parcala.ipynb)

Bu not defteri, Türkçe doğal dil işleme görevleri için veri kümelerini hazırlamaktan sorumludur. Temel işlevi, HuggingFace'den TrGLUE veri koleksiyonunu yükleyerek belirli boyutlarda eğitim ve sınama alt kümelerini oluşturmaktır.

### Fonksiyonlar ve İşlevler:

- **veri_kumesi_yukle(koleksiyon_adi, veri_kumesi_adi)**: HuggingFace'den belirtilen koleksiyon ve veri kümesini yükler
- **boyut_kontrol(veri_kumesi, veri_kumesi_parca_boyutu)**: Veri kümesi boyutunu kontrol eder
- **veri_kumesi_parcala(veri_kumesi, egitim_boyutu, sinama_boyutu, tohum_degeri)**: Veri kümesini eğitim ve sınama alt kümelerine ayırır
- **alt_kume_olustur(veri_kumesi, boyut, rng)**: İstenen boyutta dengeli bir alt küme oluşturur
- **veri_kumesi_kaydet(veri_kumesi, dosya_adi)**: Veri kümesini CSV dosyası olarak kaydeder
- **veri_kumesi_dict_kaydet(veri_kumesi_dict, dosya_adi)**: Veri kümesi bilgilerini JSON dosyası olarak kaydeder

### İş Akışı:

1. TrGLUE koleksiyonundan SST2 ve CoLA veri kümelerini yükler
2. SST2 için 5.000 eğitim, 1.000 sınama örneği ayırır
3. CoLA için 5.000 eğitim örneği ayırır ve orijinal sınama kümesini kullanır
4. Tüm örnekleri 0 ve 1 etiketleri arasında dengeli olacak şekilde dağıtır
5. Sonuçları CSV ve JSON dosyaları olarak `veri_kumeleri` dizinine kaydeder

## 2. LLM Değerlendirme Hesaplaması (llms_eval_calculate.ipynb)

Bu not defteri, büyük dil modellerinin (LLM) farklı "shot" yaklaşımlarıyla (zero-shot, few-shot) başarımlarını değerlendirir.

### Sınıflar ve Fonksiyonlar:

- **EtiketMetni**: Talimat şablonlarını oluşturan temel sınıf
- **SST2EtiketMetni**: SST2 veri kümesi için etiket ve örnek metinlerini içeren alt sınıf
- **COLAEtiketMetni**: CoLA veri kümesi için etiket ve örnek metinlerini içeren alt sınıf
- **tahmin_kontrol_et**: Modelin doğru tahmin yapıp yapmadığını kontrol eder
- **tek_shot_dogruluk_hesapla**: Belirli bir "shot" tipi için doğruluk oranını hesaplar
- **model_dogruluk_hesapla**: Modelin tüm veri kümeleri üzerindeki doğruluk oranını hesaplar

### İş Akışı:

1. Veri kümelerini yükler
2. Her model için zero-shot, 3-shot ve 5-shot sınamalarını gerçekleştirir
3. Sonuçları `shot_sonuclari` dizinindeki JSON dosyalarına kaydeder
4. Sonuçları görselleştirir ve `shot_sonuclari` dizinine kaydeder

### Varsayılan Değerlendirilecek Modeller:

- malhajar/Mistral-7B-Instruct-v0.2-turkish
- ytu-ce-cosmos/Turkish-Llama-8b-Instruct-v0.1
- sayhan/Mistral-7B-Instruct-v0.2-turkish-GGUF

## 3. Makine Öğrenmesi (ML) Modelleri Eğitim ve Değerlendirme (ml_models_train_eval.ipynb)

Bu not defteri, metin gömme (embedding) modellerini kullanarak makine öğrenmesi modellerini eğitir ve değerlendirir.

### Fonksiyonlar ve İş Akışı:

- **get_token_embedding**: Model ve tokenizer kullanarak bir metnin gömme vektörünü hesaplar
- **calculate_and_save_model_embeddings_specific_dataset**: Belirtilen model ve veri kümesi için gömmeleri hesaplar ve kaydeder
- **model_getir**: Gömme boyutuna ve model tipine göre makine öğrenmesi modeli oluşturur
- **model_egit**: Makine öğrenmesi modelini gömme vektörleriyle eğitir
- **model_basari_hesapla**: Modelin sınama veri kümesindeki başarım ölçütlerini hesaplar

### İş Akışı:

1. Çeşitli gömme modelleri yükler
2. Eğitim ve sınama veri kümeleri için gömmeleri hesaplar ve `gomme` dizinine kaydeder
3. Farklı makine öğrenmesi modellerini (Random Forest, Logistic Regression, SVM) eğitir
4. Modellerin başarımlarını değerlendirir ve ölçütlerini (doğruluk, kesinlik, hassasiyet, F1 skoru) hesaplar
5. Sonuçları görselleştirerek `gomme_basarim` dizinine kaydeder, farklı gömme modellerinin ve makine öğrenmesi algoritmalarının başarımlarını karşılaştırır

### Varsayılan Kullanılacak Gömme Modelleri:

- intfloat/multilingual-e5-base (278M parametre)
- ibm-granite/granite-embedding-107m-multilingual (107M parametre)
- intfloat/multilingual-e5-small (118M parametre)
- sentence-transformers/paraphrase-multilingual-MiniLM-L12-v2 (118M parametre)
- shibing624/text2vec-base-multilingual (118M parametre)

### Karşılaştırılan Makine Öğrenmesi Algoritmaları:

- Rastgele Orman (Random Forest)
- Lojistik Regresyon (Logistic Regression)
- Destek Vektör Makineleri (Support Vector Machines)