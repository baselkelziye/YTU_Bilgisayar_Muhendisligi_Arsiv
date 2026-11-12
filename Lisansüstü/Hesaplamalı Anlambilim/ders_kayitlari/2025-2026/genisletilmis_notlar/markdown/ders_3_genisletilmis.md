# Ders 3 Genişletilmiş Notu: Birinci Ödev Sunumları: Türkçe Soru-Cevap Eşleştirmede Gömme Modellerinin Karşılaştırılması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi ve Ödevin Konusu
- 2. Deney Düzeni
- 3. Kullanılan Modeller
- 4. Kullanılan Veri Kümeleri
- 5. Sunumlardan Sayısal Sonuçlar
- 6. Türkçeye Özel İnce Ayarın Etkisi
- 7. Parametre Sayısı, Mimari ve Eğitim Amacı
- 8. Soru → Cevap ve Cevap → Soru Asimetrisi
- 9. t-SNE Grafiklerini Doğru Okumak
- 10. Ek Denemeler ve Ek Ölçütler
- 11. Başarıyı Artırma Önerileri

## 1. Dersin Çerçevesi ve Ödevin Konusu

Bu dersin tamamı birinci ödevin sunumlarına ayrıldı. Hoca yeni konu anlatmadı. Sunumların arasında ve sırasında sorular sordu, yorum yaptı ve bazı yanlış yorumları düzeltti. Bu not, sunumlarda ortaya çıkan akademik içeriği ve hocanın müdahalelerini bir araya getirir. Sunan kişiler "bir öğrenci" ya da "bir grup" diye anılır.

Hoca, sunumlarda ödevin giriş kısmının atlanmasını, her sunucunun kendi yaptığı kısma ve kendi yorumlarına odaklanmasını istedi. Bu yüzden ödevin tam metni derste okunmadı. Ortak çerçeve sunumlardan şöyle çıkıyor:

- **Görev:** Türkçe soru-cevap çiftlerinde, bir sorunun doğru cevabını (ve bir cevabın doğru sorusunu) metin gömme (embedding) vektörleri üzerinden bulmak.
- **Modeller:** MTEB (Massive Text Embedding Benchmark) sıralamasında üst sıralardaki, 1 milyar parametreden küçük beş model ve buna ek olarak YTÜ Cosmos ekibinin `ytu-ce-cosmos/turkish-e5-large` modeli. Sunumların çoğu "ilk 100" ifadesini kullandı; bir sunum ise "ilk %5" dedi. <!-- BELİRSİZ: model seçim ölçütü sunumlar arasında farklı anlatıldı (ilk 100 / ilk %5); ödev metni derste okunmadı. -->
- **Veri:** İki farklı Türkçe soru-cevap veri kümesi. Çoğu sunum her kümeden yaklaşık 1000 çift örnekledi.
- **Ölçüm:** Kosinüs benzerliği; soru → cevap ve cevap → soru yönlerinde top-1 ve top-5 başarısı; t-SNE ile görselleştirme.

> **Ek bilgi (derste anlatılmadı):** MTEB, metin gömme modellerini sınıflandırma, kümeleme, getirme (retrieval), anlamsal benzerlik gibi pek çok görevde aynı veri kümeleriyle karşılaştıran açık bir değerlendirme tablosudur. Büyük olasılıkla bugün de Hugging Face üzerinde güncellenen bir sıralama (leaderboard) olarak yayımlanmaktadır. Bir sunumda modellerin MTEB'deki "retrieval" sütununa ayrıca bakıldı; çünkü bu ödevdeki görev bir getirme görevidir.

## 2. Deney Düzeni

### 2.1 Gömme ve kosinüs benzerliği

Her soru ve her cevap seçilen modelle sabit uzunlukta bir vektöre dönüştürülür. İki metnin ne kadar benzediği bu vektörler arasındaki açıyla ölçülür. Bir sunumda formül şöyle verildi (ekrandan, 00:30:00):

$$\text{cosine\_similarity}(A,B) = \frac{A \cdot B}{\lVert A\rVert\,\lVert B\rVert}$$

Birçok sunum vektörlerin boyutunu da belirtti. Kullanılan modellerin çoğu 1024 boyutlu vektör üretirken EmbeddingGemma 768 boyutlu vektör üretiyordu.

### 2.2 İki yön: soru → cevap ve cevap → soru

Ölçüm iki yönde yapıldı (ekrandan, 00:30:00):

- **Soru → Cevap (Q2A):** Her soru için bütün cevaplar taranır ve benzerliğe göre sıralanır; en yakın 5 cevap alınır.
- **Cevap → Soru (A2Q):** Her cevap için bütün sorular taranır ve en yakın 5 soru alınır.

Bir sunumda yalnız soru → cevap yönü yapılmıştı. Bir başka sunumda iki yönün sonuçları slayta konmamıştı; hoca bunu sordu. İki yönün ikisi de ödevin parçasıdır ve aradaki fark veri kümesinin yapısı hakkında bilgi verir (Bölüm 8).

### 2.3 Top-1 ve top-5

- **Top-1 başarısı:** Modelin en yüksek benzerlik bulduğu ilk sonucun doğru eşleşme olma oranı.
- **Top-5 başarısı:** Doğru eşleşmenin, en yüksek benzerlikli ilk 5 sonuç içinde yer alma oranı.

Tanımdan dolayı top-5 her zaman top-1'den büyük ya da ona eşittir. Hoca bir sunumda "%1'lik başarı, %5'lik başarı ne demek?" diye sordu; sunan kişi top-1'de doğru cevabın ilk sırada, top-5'te ilk beş içinde aranması gerektiğini, ikinci ya da üçüncü sırada bulunan doğru cevabın da top-5'te isabet sayıldığını açıkladı (03:25:34). Birkaç sunum top-10'u da raporladı (ekrandan, 00:20:00).

### 2.4 Ön ekler ve talimat cümleleri

Bazı modeller, metnin ne olduğunu bilmek için bir ön ek (prefix) ya da görev cümlesi ister. Bir sunumun model tablosu bunu özetliyor (ekrandan, 02:20:45):

| Model | Kaynak | Parametre | Görev metni |
|---|---|---|---|
| multilingual-e5-large-instruct | intfloat | 560M | `Instruct: ...\nQuery: {q}` |
| bge-m3 | BAAI | 568M | yok |
| gte-multilingual-base | Alibaba-NLP | 305M | yok |
| paraphrase-ml-mpnet-v2 | sentence-transformers | 278M | yok |
| multilingual-e5-large | intfloat | 560M | `query: ` / `passage: ` |
| turkish-e5-large | ytu-ce-cosmos | 560M | `Instruct: ...\nQuery: {q}` |

E5 ailesinde soruya `query: `, cevaba `passage: ` eklenir. Instruct sürümlerinde ayrıca bir görev cümlesi verilir. Sunumlarda kullanılan görev cümleleri "verilen Türkçe soruya en uygun cevabı getir" anlamında İngilizce cümlelerdi; bir sunumda model sayfasında önerilen cümlenin aynen kullanıldığı söylendi. <!-- BELİRSİZ: görev cümlelerinin tam metni altyazıda bozuk geçiyor (01:50:18, 02:20:33). -->

Bir sunumda talimat dilinin etkisi denendi. Qwen3-Embedding modelinde talimatın dili değiştirilince bir veri kümesinde top-1 0.79'dan 0.91'e çıktı <!-- BELİRSİZ: altyazıda "İngilizce Türkçe yapınca" geçiyor; değişikliğin hangi yönde (İngilizceden Türkçeye mi, tersi mi) yapıldığı net değil. -->, ama yine de diğer modellerin 0.97-0.98 düzeyine ulaşmadı (00:36:24). Sunan kişi Qwen3'ün decoder tabanlı, diğerlerinin encoder tabanlı olmasını olası bir neden olarak gördü.

EmbeddingGemma'da soru ve cevap ayrı fonksiyonlarla kodlanır (ekrandan, 00:40:00):

```python
query_embeddings = model.encode_query(query)
document_embeddings = model.encode_document(documents)
```

Yani model soruyu bir arama sorgusu, cevabı aranacak bir belge gibi kodlar. Sunan öğrenci, bu rol ayrımının t-SNE'de soruların ve cevapların belirgin biçimde ayrı kümelenmesine yol açtığını düşündü.

### 2.5 Uygulama ayrıntıları

Bir sunumda arama için FAISS kütüphanesi kullanıldı. Vektörler `float32` türüne ve bellekte ardışık (contiguous) düzene getirildi. `IndexFlatIP` sınıfı iç çarpım (inner product) ile arama yapar. Vektörler önce normalize edildiği için iç çarpım kosinüs benzerliğine eşit oldu. Doğruluk, getirilen cevabın beklenen cevapla birebir metin eşleşmesiyle ölçüldü; bunun için büyük-küçük harf ve boşluk normalizasyonu yapıldı.

Başka bir sunumda PyTorch'un `topk` fonksiyonuyla ilk 1 ve ilk 5 aday alındı. Bazı sunumlarda veri önce temizlendi: büyük harfler küçültüldü, Türkçe "I/ı" dönüşümüne dikkat edildi, tekrar eden kayıtlar düzenli ifadeyle ayıklandı.

## 3. Kullanılan Modeller

Sunumlarda geçen modeller kabaca dört gruba ayrılabilir:

- **Türkçeye özel:** `ytu-ce-cosmos/turkish-e5-large`. `multilingual-e5-large` tabanından Türkçe veriyle ince ayar yapılmış bir model; bir sunumdaki tabloya göre yaklaşık 560M, bir başkasına göre yaklaşık 600M parametre.
- **Getirme odaklı çok dilli modeller:** `multilingual-e5-small/base/large` ve `multilingual-e5-large-instruct` (intfloat), `bge-m3` (BAAI), `gte-multilingual-base` (Alibaba-NLP), `Qwen3-Embedding-0.6B`, `embeddinggemma-300m` (Google), Jina v5 metin gömme modelleri (nano ve small), Snowflake arctic-embed, F2LLM, KaLM-mini, Octen-Embedding-0.6B, PIXIE-Rune, bir Perplexity gömme modeli, CodeFuse ve granite modelleri.
- **Paraphrase (eş anlamlı cümle) modelleri:** `paraphrase-multilingual-mpnet-base-v2`, `paraphrase-multilingual-MiniLM-L12-v2`, LaBSE, distiluse.
- **Diğer karşılaştırma modelleri:** Bir sunumda `intfloat/e5-large-v2` kullanıldı (ekrandan, 00:20:00). Bir başka sunumda çok dilli olmayan GTE-large modeli karşılaştırmaya eklendi.

BGE-M3'teki "M3" bir sunumda "çok dilli, çok işlevli, çok ayrıntı düzeyli" (multi-lingual, multi-functionality, multi-granularity) olarak açıklandı. Sunan kişi bu modelin çoklu vektör yapısı sayesinde kısa girdiden uzun girdiye kadar farklı metinleri iyi işleyebildiğini söyledi.

Bir sunumda üç model örnek olarak şöyle tanıtıldı (ekrandan, 03:00:00): `turkish-e5-large` (600M, Türkçe veri kümeleriyle ince ayarlanmış), `multilingual-e5-small` (100M, 12 katman, MTEB'de 55. sıra), `Octen-Embedding-0.6B` (600M, MTEB'de 253. sıra).

> **Ders sonrası not:** Bir sunumda BGE-M3 için "1 milyar parametreli model" dendi (00:13:44); başka bir sunumun tablosunda BGE-M3 568M parametre olarak verildi (ekrandan, 02:20:45). Bir başka sunumda EmbeddingGemma "300 milyar parametreli" diye anıldı (00:34:37); modelin adı (`embeddinggemma-300m`) büyük olasılıkla 300 milyon parametreyi gösterir.

## 4. Kullanılan Veri Kümeleri

Sunumlarda geçen veri kümeleri ve sunucuların bunlar hakkında yaptığı gözlemler:

- **TQuAD:** Türk-İslam bilim tarihi üzerine bir okuma-anlama kümesi; 681 başlık, 2332 paragraf ve 8308 soru-cevap çifti (ekrandan, 01:50:00). Cevaplar kısa ve sık sık soruda geçmeyen bir bağlama dayanıyor; bu yüzden en zor kümelerden biri oldu.
- **Aieyup Turkish-NLP-QA:** Türkiye'deki tarihi mekânlar ve turistik yerler üzerine 15000 soru-cevap çifti (ekrandan, 01:50:00). Sunan öğrenciye göre bu küme Google Gemini ile oluşturulmuştu.
- **XQuAD-TR:** SQuAD tarzı İngilizce kümenin Türkçe çevirisi; kısa sorular, ansiklopedik ve çoğu zaman kısa varlık (entity) cevapları.
- **GSM8K-TR:** Matematik problemlerinin Türkçe sürümü. Soru ile cevap arasındaki ilişki çok güçlü olduğu için başarı yüksek çıktı.
- **Türkçe Wikipedia ve WikiRAG-TR:** Genel ansiklopedik sorular. WikiRAG-TR'de konular birbirinden çok farklı olduğu için bütün modeller %99-100'e yakın sonuç verdi; bir sunum bu kümeyi "çok steril" diye niteledi.
- **Türkçe hukuk kümeleri:** Biri anayasa üzerine; bir diğeri Yargıtay kararları, mevzuat ve hukuki makalelerden derlenmiş 18305 çift; bir diğeri kullanıcıların gündelik dille sorduğu, avukatların resmî dille cevapladığı sorular. İlk ikisinde soru ve cevap aynı terimi paylaştığı için başarı yüksek; üçüncüsünde üslup farkı yüzünden düşük.
- **AIXR Turkish-QA:** Yazılım geliştirme, radyoloji ve tıbbi görüntüleme alanlarından sorular.
- **Tıp kümeleri:** Hastalıklar, patoloji ve tedaviler üzerine soru-cevaplar; bir kümede soruların hastane bölümü etiketi de vardı.
- **Diğerleri:** IMDB Türkçe film yorumları, iklim değişikliği ve tarım soru-cevapları, TR-Extractive-QA, Turkish MMLU, Nutuk üzerine sorular, Türkçe sınav soruları içeren bir küme ve bir bilgi yarışmasının soru-cevapları.

Bir grup, iyi bir deney için sorunun **bağlamdan bağımsız** (context independent) olması gerektiğini vurguladı. Soru, ek bir paragrafa ihtiyaç duymadan öznesini ve nesnesini kendi içinde taşımalı. Aksi hâlde model, sorunun neyi sorduğunu bilemez ve eşleştirme anlamsal olmaktan çıkar.

Bazı sunumlar kümeleri bilerek farklı zorlukta seçti. Örneğin soruda geçen kelimelerin cevapta da geçtiği "kolay" bir küme ile kelime örtüşmesi olmayan, üslubu farklı "zor" bir küme birlikte kullanıldı.

## 5. Sunumlardan Sayısal Sonuçlar

Aşağıdaki tablolar ekranda gösterilen slaytlardan alınmıştır. Her biri farklı bir öğrencinin kendi örneklemine aittir; tablolar birbirleriyle doğrudan karşılaştırılamaz.

### 5.1 Zor bir küme ve kolay bir küme

Bir sunumda XQuAD-TR ve TQuAD üzerinde soru → cevap yönünde sonuçlar (ekrandan, 01:30:00):

| Model | XQuAD-TR top-1 | XQuAD-TR top-5 | TQuAD top-1 | TQuAD top-5 |
|---|---|---|---|---|
| ytu-cosmos-e5 | %16.3 | %41.6 | %8.5 | %27.3 |
| multilingual-e5 | %9.6 | %30.1 | %4.2 | %15.7 |
| bge-m3 | %6.2 | %19.8 | %2.4 | %10.9 |
| mpnet | %5.6 | %20.2 | %1.0 | %3.7 |
| distiluse | %5.5 | %17.6 | %2.9 | %8.1 |
| labse | %3.4 | %10.1 | %1.9 | %5.2 |

Başka bir sunumda soru ve cevapların birbirine çok benzediği bir kümede sonuçlar (ekrandan, 02:50:00):

| Model | Q→A top-1 | Q→A top-5 | A→Q top-1 | A→Q top-5 |
|---|---|---|---|---|
| ytu-ce-cosmos/turkish-e5-large | %98.80 | %99.20 | %98.60 | %99.00 |
| multilingual-e5-small | %98.40 | %99.70 | %97.90 | %98.80 |
| multilingual-e5-base | %98.30 | %99.60 | %97.70 | %99.20 |
| BAAI/bge-m3 | %97.80 | %98.70 | %98.00 | %98.70 |
| paraphrase-multilingual-mpnet-base-v2 | %92.00 | %97.10 | %93.10 | %97.00 |
| paraphrase-multilingual-MiniLM-L12-v2 | %88.70 | %95.50 | %90.30 | %95.50 |

İki tablo, aynı modellerin veri kümesine göre %1'den %99'a kadar değişen başarı gösterebildiğini açıkça ortaya koyuyor. Kolay kümede bile paraphrase modelleri sonda kaldı.

### 5.2 Top-1, top-5 ve top-10 birlikte

Bir sunumda, hastane bölümü etiketi olan bir tıp kümesinde top-10 ve "etiket" sütunu da raporlandı (ekrandan, 00:20:00). "Etiket" sütunu, en yakın bulunan cevabın doğru cevapla aynı bölüme (ör. göz, kadın doğum) ait olma oranıdır:

| Model | Q→A top-1 | top-5 | top-10 | etiket | A→Q top-1 | top-5 | top-10 | etiket |
|---|---|---|---|---|---|---|---|---|
| ytu-ce-cosmos/turkish-e5-large | 34.81 | 51.06 | 58.65 | 79.13 | 36.44 | 54.04 | 59.71 | 68.37 |
| Qwen3-Embedding-0.6B | 18.37 | 30.87 | 36.44 | 62.12 | 20.87 | 34.81 | 41.83 | 55.1 |
| multilingual-e5-large | 28.46 | 42.12 | 49.71 | 68.08 | 33.94 | 51.15 | 58.08 | 66.92 |
| e5-large-v2 | 7.12 | 13.37 | 17.6 | 32.98 | 8.65 | 16.44 | 21.15 | 34.33 |
| multilingual-e5-base | 16.15 | 28.27 | 33.46 | 51.14 | 25.87 | 40.96 | 47.5 | 59.52 |
| multilingual-e5-small | 12.88 | 22.6 | 27.02 | 44.62 | 20.48 | 33.17 | 38.94 | 55.19 |

Sunan öğrenci, modellerin çoğu zaman doğru bölümü bulduğunu ama o bölümün içindeki doğru cevabı ilk sıraya koyamadığını söyledi. Tabloda etiket sütununun top-1'den çok yüksek olması bunu gösteriyor. `e5-large-v2` ise bütün sütunlarda açık ara geride kaldı.

### 5.3 Turkish MMLU

İngilizce sunulan bir çalışmada Turkish MMLU kümesinde cevap → soru yönü (ekrandan, 00:50:00):

| Model | top-1 (%) | top-5 (%) |
|---|---|---|
| multilingual-e5-large-instruct | 19.0 | 37.4 |
| PIXIE-Rune-v1.0 | 18.5 | 36.0 |
| turkish-e5-large | 17.8 | 34.5 |
| jina-embeddings-v5-text-nano | 16.2 | 34.0 |
| jina-embeddings-v5-text-small | 15.7 | 33.9 |
| Octen-Embedding-0.6B | 12.3 | 25.6 |

Bu sunumda soru ve cevapta aynı kök kelimeler ve dil bilgisi yapıları geçince modellerin bunlara aşırı duyarlı olduğu ("mirroring") gözlendi. İçinde başka bir dilden ifade geçen bir sınav sorusunu çok dilli modelin doğru cevaba bağlayabildiği de örnek olarak gösterildi. <!-- BELİRSİZ: bu sunumun büyük kısmı İngilizceydi ve altyazıda (00:42-00:53) tekrar eden anlamsız Türkçe satırlara dönüşmüş; yalnız ekrandaki tablo ve anlaşılır İngilizce cümleler alındı. -->

## 6. Türkçeye Özel İnce Ayarın Etkisi

Sunumların büyük çoğunluğunda `turkish-e5-large` birinci çıktı. Bir sunum TQuAD'da bu modelin kendisinden sonraki en iyi modelin neredeyse iki katı başarı gösterdiğini raporladı (ekrandan, 02:00:00). Sunucuların ortak açıklaması, modelin Türkçe metinlerle ince ayar yapılmış olmasıydı. Somut gözlemler:

- Gündelik dilde sorulan bir soru ile resmî dilde yazılmış bir cevap arasındaki üslup farkını diğer modellerden daha iyi kapattı. Bir hukuk kümesinde diğer modeller soruları ve cevapları t-SNE'de iki ayrı bloğa ayırırken bu modelde ayrışma daha azdı (ekrandan, 00:40:00).
- Eski kelimeler içeren Nutuk sorularında da Türkçeye özel modelin daha iyi olduğu görüldü; çünkü metindeki kelimelerin çoğu bugün de kullanılıyor.
- TQuAD'daki bir soruda kayıtlı cevap yalnız "kendi" idi. `turkish-e5-large` ise ilk sırada sorulan kişinin adını içeren cevabı getirdi. Üçüncü sırada da o kişinin eğitim hayatıyla ilişkili bir Alman arkeologla ilgili cevabı getirdi. LaBSE ise ilgisiz cevaplar getirdi. Sunan öğrenci, Türkçeye özel modelin varlıklar arasındaki anlamsal ilişkileri de yakaladığını düşündü.

Bu üstünlük her yerde geçerli değildi. Bir hukuk kümesinde BGE-M3 birinci, Cosmos üçüncü oldu. Bir iklim değişikliği kümesinde soru → cevap yönünde Jina (top-1 %41, top-5 %67) önde çıktı, cevap → soru yönünde Cosmos önde çıktı. Turkish MMLU'da `multilingual-e5-large-instruct` önde çıktı (Bölüm 5.3). Bir tıp-hukuk sunumunda `multilingual-e5` Türkçe modelden az farkla yüksek çıktı; sunan öğrenci bunu kümelerin Türkçeye özgü olmamasına bağladı. Bir sunum da Türkçeye özel modelin de her alanda (domain) iyi sonuç vereceğinin garanti olmadığını vurguladı.

## 7. Parametre Sayısı, Mimari ve Eğitim Amacı

### 7.1 Büyük model her zaman daha iyi değil

Birçok sunum aynı sonuca vardı: başarı parametre sayısıyla doğru orantılı değildir.

- 300M parametreli EmbeddingGemma bir sunumda yaklaşık 1 milyar parametreli olduğu söylenen BGE-M3'ten daha iyi sonuç verdi (bkz. Bölüm 3'teki ders sonrası not).
- Qwen3-Embedding-0.6B, MTEB'de en üstteki ve en çok parametreli modellerden biri olmasına rağmen birkaç sunumda sondan ikinci ya da en zayıf modellerden biri oldu.
- GTE, bir sunumda en az parametreli model olmasına rağmen daha büyük modelleri geçip üçüncü oldu. Başka bir sunumda ise 300M parametreli GTE-multi en düşük sonucu verdi.
- Bir hukuk kümesinde `multilingual-e5-large` ile `-base` aynı skoru verdi. Sunan öğrenci "işimize göre daha küçük bir model seçmek daha uygun olabilir" sonucuna vardı.

Buna karşılık boyutun etkili olduğu durumlar da vardı. Bir tıp kümesinde `multilingual-e5-small`'dan `-large`'a geçince top-1 yaklaşık %6.9'dan %13.5'e çıktı (00:59:41 ve 01:00:27). Aynı sunumdaki t-SNE grafikleri de büyük modelde soru ve cevapların biraz daha yaklaştığını gösterdi (ekrandan, 01:00:00).

Bir sunum, aynı ailede `instruct` sürümünün düz sürümden daha iyi olduğunu sonuç slaytına yazdı (ekrandan, 00:10:00). Bir diğeri talimat ayarının (instruction tuning) tutarlı biçimde 6-7 puan kazandırdığını raporladı.

### 7.2 Paraphrase modelleri neden geride kaldı

Paraphrase modelleri, aynı anlamı farklı kelimelerle anlatan iki cümleyi yaklaştırmak için eğitilmiştir. Bu **simetrik** bir görevdir: iki cümlenin rolü aynıdır. Soru-cevap eşleştirme ise **asimetrik** bir görevdir: kısa bir soru ile onu tamamlayan, çoğu zaman daha uzun bir cevap eşleştirilir; ikisi aynı anlamı taşımaz. Sunumların ortak yorumu buydu. Bir sunum, bu modellerin soru ile cevap arasındaki ilişkiye bakmak yerine "anlamı en yakın" vektörü seçtiğini; bir başkası ise biçime (format) daha bağımlı olduklarını söyledi.

Bir istisna da raporlandı: bir sunumda XQuAD-TR kümesinde `paraphrase-multilingual-mpnet` BGE-M3'ten ve E5'ten biraz yüksek çıktı. Sunan öğrenci bunu kendisi için şaşırtıcı buldu.

Bir sunumda Türkçeyi tanımayan bir modelin (mixedbread) ve çok küçük bir modelin (Snowflake arctic-embed xs) soruları ve cevapları anlamlarına göre değil, cümle yapılarına göre yerleştirdiği gözlendi. Sunan öğrenci bunu görüntü işlemedeki benzetmeyle açıkladı: nasıl ki görüntü işlemede önce kenarlar ve köşeler bulunur, küçük model de önce cümlenin yüzey yapısını yakalıyor.

> **Ek bilgi (derste anlatılmadı):** Getirme (retrieval) için eğitilen E5, BGE gibi modeller büyük olasılıkla zıtlıklı öğrenme (contrastive learning) ile, çok sayıda gerçek ya da üretilmiş (sorgu, ilgili belge) çiftiyle eğitilir. Bu sayede sorgu ile belge farklı biçimde yazılmış olsa bile yakın vektörlere gider. Paraphrase modelleri ise çoğunlukla eş anlamlı cümle çiftleriyle eğitilir; bu yüzden asimetrik soru-cevap görevinde zayıf kalmaları büyük olasılıkla eğitim verisinin türünden kaynaklanır.

### 7.3 Model ile veri kümesi uyumu

Bir öğrenci, Gemini ile oluşturulduğunu söylediği Aieyup kümesinde Google'ın EmbeddingGemma modelinin (Cosmos dışında) diğer çok dilli modellerden iyi olmasını, aynı ekosistemden gelen veri ile model arasındaki bir uyuma bağladı (ekrandan, 02:00:00). Sunan kişi bunun bir tahmin olduğunu açıkça belirtti.

## 8. Soru → Cevap ve Cevap → Soru Asimetrisi

Hemen her sunumda iki yönün sonuçları farklı çıktı. Yönün hangisinin daha başarılı olduğu veri kümesine göre değişti.

**Cevap → soru daha başarılıysa:** Cevaplar sorulardan uzun ve bilgi yüklüdür. Uzun metin daha çok anlamsal sinyal taşır ve daha ayırt edicidir. Bu yüzden bir cevaptan onun sorusunu bulmak, kısa bir sorudan doğru cevabı bulmaktan kolaydır. Hukuk kümesinde sorular kişiye özel ve gündelik, cevaplar ise genel ve resmîydi. Kiracı-ev sahibi gibi bir konuda pek çok cevap birbirine benzediği için sorudan cevaba gitmek zordu; cevaptan soruya gitmek ise daha kolaydı.

**Soru → cevap daha başarılıysa:** Cevaplar kısa ve birbirine çok benziyorsa (yıllar, adlar, şehirler), cevap vektörleri tek bir bölgede yığılır. Sorular ise birbirinden daha ayırt edicidir. Bir sunumda TQuAD'da Cosmos modelinde cevap → soru top-1 %16'da kalırken soru → cevap %27'ye çıktı. Bir başka sunumda ise "Ankara" gibi bir cevabın birçok sorunun cevabı olması cevap tarafında kümelenmeye ve hataya yol açtı.

Bir sunum bu durumu şöyle özetledi: modeller genelde kısa bir sorunun yoğun bir metnin anlamsal özüyle eşleşmesi için eğitilir. Bu yüzden soru → cevap yönü doğal yön sayılabilir. Ama cevap → soru yönünde yoğun metinden yola çıkıp sade bir soruyu seçmek, vektör konumu açısından zorlayıcı olabilir. Bu yönde BGE-M3'ün daha iyi olması, çoklu vektör yapısına ve uzun metni daha zengin özelliklerle kodlayabilmesine bağlandı.

Bir sunumda simetrik (soru ve cevap ikisi de kısa ve benzer) ve asimetrik (kısa soru, uzun paragraf cevap) iki küme karşılaştırıldı. Asimetrik kümede başarı belirgin biçimde düştü. Sunan öğrenci bunu, uzun bir cevabın tek bir vektöre sıkıştırılırken anlamın bir kısmının kaybolmasına bağladı. Bir başka sunum da, diyaloğa benzeyen asimetrik bir kümeye geçildiğinde yaklaşık %40'lık bir düşüş raporladı.

## 9. t-SNE Grafiklerini Doğru Okumak

Her sunumda soru ve cevap vektörleri t-SNE ile iki boyuta indirildi ve farklı renklerle çizildi. Bu grafiklerin nasıl okunacağı dersin en çok tartışılan konusu oldu.

> **Ek bilgi (derste anlatılmadı):** t-SNE, yüksek boyutlu noktaları iki boyuta indirirken öncelikle yerel komşulukları korumaya çalışır. Birbirine yakın noktalar grafikte de yakın kalır. Ama kümeler arasındaki uzaklıklar ve kümelerin boyutları büyük ölçüde yorumlanamaz. Yöntem büyük olasılıkla rastgele başlatıldığı ve "perplexity" gibi parametrelere duyarlı olduğu için aynı veri farklı çalıştırmalarda farklı görünebilir.

### 9.1 Ayrışma mı, iç içe geçme mi?

Sunumların çoğu, soruların ve cevapların iç içe geçtiği grafikleri başarılı, iki ayrı bloğa ayrıldığı grafikleri başarısız diye yorumladı. Bir öğrenci "noktalar arası uzaklık ne kadar fazlaysa, ayrı kümelenme ne kadar fazlaysa bu bizim için daha başarısız model anlamına geliyor" dedi (00:16:40). Ancak bir sunumun slaytında tersi yazıyordu: "Ayrışma ne kadar belirginse model o kadar iyi ayırt ediyor" (ekrandan, 02:24:25). Sunan öğrenci de iç içe geçmenin sorun olduğunu savundu.

Hoca burada araya girdi:

> **Hocanın vurgusu:** İç içe geçmenin kötü bir şey olduğunu söylemek zor. Bir soru alıyorsun; o soru bir nokta. O noktaya en yakın noktaları bulmaya çalışıyorsun. Sorular ve cevaplar birbirlerine çok uzak olsalar, o soruya doğru cevabın bulunma olasılığı epey düşer. Aynı sorunun doğru cevabının, yani doğru çiftlerin birbirine yakın olması gerekir.

Öğrenci üst üste binmenin çok fazla olduğunu ve sorular arasında da bir kümelenme beklediğini söyledi. Hoca "doğru soruyla doğru cevabın birbirine yakın olması lazım zaten" diyerek yorumunu tekrarladı (02:24:13 - 02:25:04).

### 9.2 Üst üste binmek de yetmez

Dersin sonundaki bir sunumda paraphrase modelinin grafiğinde iki kümenin eşleşmiş gibi göründüğü, ama bu modelin en kötü sonucu verdiği söylendi. Hoca şu soruyu sordu: "Eşleşmişler ama doğru şeylerle doğru şeyler mi eşleşmişler acaba?" Öğrenci, modelin yanlış çiftleri eşleştirdiğini doğruladı (03:30:15). Yani grafikte iç içe geçme gerekli olabilir ama yeterli değildir. Asıl ölçü, her noktanın en yakın komşusunun kendi doğru çifti olup olmadığıdır; bunu da top-1/top-5 sayıları gösterir.

Benzer bir gözlem başka bir sunumda da geldi. Bir modelin grafiği daha örtüşük görünmesine rağmen başarısı daha düşüktü. Sunan öğrenci bunu, yakın görünen noktaların yanlış kümelerle ve yanlış cevaplarla eşleşmesine bağladı. Bir MPNet grafiğinde de cevapların (0,0) çevresinde yığıldığı ve bunun homojen görünmesine rağmen başarıyı düşürdüğü söylendi.

### 9.3 Ayrışmış ama başarılı: ön ek sinyali

Tersi de görüldü. `multilingual-e5` bir sunumda soruları ve cevapları "bıçakla kesilmiş gibi" iki bloğa ayırdı (ekrandan, 02:30:00), ama top-5'te ikinci sırada geldi. Sunan öğrenciler iki açıklama önerdi:

- `query:` ve `passage:` ön eklerinin sinyali anlamsal içeriğin önüne geçiyor. Model vektörleri konuya göre değil, "soru mu cevap mı" diye kategorize ediyor.
- Model yine de aynı konudaki cevapları kendi içinde kümelediği için doğru cevabı ilk sırada bulamasa bile doğru konu kümesinden seçip top-5'i kurtarıyor.

Bir hilal örneği de verildi. Bir iklim kümesinde BGE-M3'ün grafiğinde cevaplar soruları bir hilal gibi sarmıştı. Sorular tek bir yerde kümelendiği için cevaptan soruya gitmek zorlaştı ve soru → cevap yönü daha başarılı oldu (02:56:26).

### 9.4 Konu kümeleri

Bazı sunumlar grafikleri soru/cevap yerine konuya göre de renklendirdi. Bir tıp kümesinde göz hastalıklarıyla ilgili sorular "kornea" gibi özel terimler yüzünden hafifçe ayrı kümelendi. Kategorileri tamamen farklı bir kümede ise her etiket ayrı bir kümede toplandı. Bir sunumda farklı alanlardan (yazılım, radyoloji, hukuk) gelen sorular aynı grafiğe konuldu. Başarılı modellerde hukuk açıkça ayrıldı, radyoloji ve tıp kendi aralarında biraz karıştı. Başarı düştükçe alanlar birbirine yaklaştı. Bir bilgi yarışması kümesinde de coğrafya ve bilim soruları anlamsal uzayda kendi bölgelerinde toplandı.

## 10. Ek Denemeler ve Ek Ölçütler

### 10.1 MRR, kategori uyumu ve güven skoru

Bir sunumda top-1 ve top-5'e ek olarak üç ölçüt daha raporlandı (ekrandan, 03:10:00):

| Model | Genel: top-1 | top-5 | MRR | Karma: top-1 | top-5 | MRR | kategori uyumu |
|---|---|---|---|---|---|---|---|
| Qwen3-0.6B | %3.60 | %8.80 | %5.36 | %6.60 | %14.10 | %9.49 | %46.52 |
| Multilingual-E5 | %9.90 | %21.70 | %14.35 | %11.60 | %25.50 | %16.49 | %54.18 |
| BGE-M3 | %6.70 | %16.10 | %9.95 | %7.50 | %18 | %11.28 | %44.82 |
| KaLM-Mini | %0.50 | %1.8 | %0.95 | %0.50 | %1.60 | %0.81 | %19.00 |
| Gemma-300M | %0.50 | %1.50 | %0.89 | %0.80 | %3.10 | %1.49 | %24.10 |
| YTÜ-Turkish-E5 | %12.30 | %27.20 | %17.66 | %15.80 | %33.40 | %22.12 | %54.04 |

"Genel" küme birbirinden bağımsız genel kültür sorularından, "karma" küme ise bilim, edebiyat, sanat gibi alt kategorilerden eşit sayıda alınmış sorulardan oluşuyordu. Karma kümede başarı arttı; sunan öğrenci bunu modelin en azından sorunun kategorisini anlayabilmesine bağladı. KaLM ve Gemma'nın neredeyse sıfır çıkması öğrenciyi de şaşırttı; kodda bir hata bulamadığını söyledi. Bu öğrencinin E5 dışındaki modellerde talimat kullanmadığı da not edilmeli.

Hoca MRR'nin nasıl hesaplandığını sordu. Soru-cevap Örnek Sorular bölümünde ayrıntılı verilmiştir. Kısaca: doğru cevap $r$. sıradaysa o soru $1/r$ puan alır, ilk 5'te yoksa 0 alır; bütün soruların puanları toplanıp soru sayısına bölünür. Tablodaki her satırda MRR'nin top-1 ile top-5 arasında kalması bu tanımla tutarlıdır (bkz. Örnek Sorular).

"Kategori uyumu", getirilen 5 cevaptan kaçının sorunun kategorisinden olduğunun ortalamasıdır. "Ortalama güven skoru" ise birinci adayın benzerliğinden ikinci adayın benzerliğinin çıkarılmasıyla bulunuyordu. Hoca bunun nasıl hesaplandığını sorunca öğrenci, bu skorun doğrulukla ilişkisi olmadığını ve başarıyı ölçmediğini sonradan fark ettiğini söyledi (03:09:09 - 03:09:23).

### 10.2 Kök çözümleme

Bir öğrenci skorları yükseltmek için metinleri köklerine indirgeyip deneyleri tekrarladı (ekrandan, 02:00:00):

- `turkish-e5-large` için top-1'e olumsuz, top-5'e olumlu etki etti.
- Çok dilli modellerde genelde tersi oldu. LaBSE'de etki görülmedi.
- Genel olarak etki beklenenden azdı.

Sunan öğrenci bunu, modellerin bağlama duyarlı (context-aware) olmasıyla açıkladı. Ekler atılınca anlam kaybı oluyor ve bu, kök çözümlemenin olası faydasını dengeliyor.

### 10.3 Etiket gürültüsü ve kısa cevaplar

TQuAD'daki "kendi" örneği (Bölüm 6), değerlendirmenin kendisinin de hatalı olabileceğini gösterdi. Kayıtlı cevap çok kısa ve bağlamsız olduğu için model aslında doğru bilgiyi içeren bir cevabı getirse bile yanlış sayıldı. Birçok sunum düşük TQuAD başarısını kısmen bu tür kısa, bağlama muhtaç cevaplara bağladı.

### 10.4 Aday havuzunun büyüklüğü

Bir sunum, bütün modellerin 15000 çiftlik kümede 8000 çiftlik kümeye göre daha düşük başarı göstermesini potansiyel cevap sayısıyla açıkladı (ekrandan, 02:00:00). Aday sayısı arttıkça doğru cevaba çok yakın çeldiricilerin sayısı da artar.

## 11. Başarıyı Artırma Önerileri

Bir sunum, ödevde elde edilen en iyi sonucun bile (TQuAD'da `turkish-e5-large` ile top-1 %7.799, top-5 %18.345) düşük olması üzerine iki iyileştirme önerdi (ekrandan, 01:58:30):

- **İki aşamalı getirme (two-stage retrieval):** Ödevde bi-encoder modellerle doğrudan top-1 ve top-5 aranıyor. Bunun yerine önce bi-encoder ile ilk 50 ya da 100 aday alınır, sonra bir cross-encoder modeliyle bu adaylar yeniden sıralanır. Slaytta iki mimari karşılaştırıldı:

```text
Bi-encoder:
  Girdi A -> SBERT -> Gömme A \
                               -> kosinüs benzerliği
  Girdi B -> SBERT -> Gömme B /
  (SBERT = BERT + pooling)

Cross-encoder:
  Girdi A + Girdi B -> BERT -> Sınıflandırıcı -> sınıflandırma skoru
```

- **Hibrit arama:** Vektör tabanlı arama, BM25 ve TF-IDF gibi anahtar kelime tabanlı aramayla birleştirilir. Böylece hem anlam tabanlı hem de özel ad tabanlı sorgularda daha iyi sonuç alınabilir.

Başka bir sunumda, ilk sırada yanlış, ilk beşte doğru cevap bulunan örnekler incelendi. Bir örnekte model "Cambridge" ve "kampüs" kelimelerinden bir üniversite cevabı beklemiş ve bunu ilk sıraya koymuştu; doğru cevap olan mekânı ise beşinci sıraya kadar getirebilmişti. Başka bir örnekte model "buhar" kelimesine takılıp yanlış cevabı seçmişti. Sunan öğrenci bunları **zorlu çeldiriciler** (hard negatives) diye niteledi. Çözüm olarak bir yeniden sıralayıcı (reranker), yani cross-encoder önerdi; çünkü modellerin bazı durumlarda aradığı varlığı (entity) kaybettiğini gözlemlemişti.

> **Ek bilgi (derste anlatılmadı):** Bi-encoder'da soru ve cevap ayrı ayrı kodlandığı için cevap vektörleri önceden hesaplanıp bir indekste saklanabilir; arama bu yüzden çok hızlıdır. Cross-encoder ise soru ile her adayı birlikte modele verdiği için iki metin arasındaki ilişkiyi daha ince yakalar, ama her aday için ayrı bir ileri geçiş (forward pass) gerekir. Bu yüzden pratikte büyük olasılıkla önce hızlı bi-encoder ile aday listesi daraltılır, sonra az sayıda aday cross-encoder ile yeniden sıralanır.

## Örnek Sorular

**Soru 1** (derste sözlü, 03:07:42 - 03:09:04; tablo ekrandan, 03:10:00): Bir sunumda top-1 ve top-5'in yanında MRR de raporlanmıştı. MRR nasıl hesaplanır? En çok kaç olabilir?

Derste sunan öğrenci önce şöyle anlattı: doğru cevap ilk sıradaysa 1, ikinci sıradaysa 1/2, üçüncüde 1/3, dördüncüde 1/4, beşincide 1/5 puan; ilk beşte yoksa 0. Hoca en büyük değeri sorunca öğrenci önce "bin olabilir" dedi, sonra puanları topladığını ve soru sayısına (1000) böldüğünü söyledi. Örneğin toplam 170 puan, 1000 soru için %17 eder. Hoca anladığını söyleyip sunuma devam ettirdi.

> **Çözüm (derste verilmedi):** Bu ölçüt "ilk 5'e kesilmiş ortalama ters sıra"dır (MRR@5): $\text{MRR@5} = \frac{1}{N}\sum_{i=1}^{N} \frac{1}{r_i}$. Burada $r_i$, $i$. sorunun doğru cevabının sırasıdır; doğru cevap ilk 5'te değilse terim 0 alınır. Toplam 1000'e kadar çıkabilir, ama ölçüt bu toplamın $N$'ye bölünmüş hâlidir. Bu yüzden en büyük değeri 1'dir (%100); bu değer bütün soruların doğru cevabı ilk sıradayken elde edilir. Örneğin 5 soruda doğru cevaplar 1., 2., hiç, 5. ve 1. sıradaysa $\text{MRR@5} = (1 + 0.5 + 0 + 0.2 + 1)/5 = 0.54$ olur. Tanım gereği her soru için top-1 isabeti $\le 1/r_i \le$ top-5 isabeti olduğundan, her zaman $\text{top-1} \le \text{MRR@5} \le \text{top-5}$ olur. Ekrandaki tablonun 12 satırının hepsi bu sıralamaya uyuyor (ör. YTÜ-Turkish-E5 genel kümede %12.30 ≤ %17.66 ≤ %27.20); bu kontrol python ile yapıldı.

**Soru 2** (derste sözlü, 03:25:34): "%1'lik başarı demek, %5'lik başarı demek ne demek?"

**Cevap (derste verildi):** Burada kastedilen top-1 ve top-5 başarısıdır. Top-1'de doğru cevabın, benzerliğe göre sıralanmış listenin ilk sırasında olup olmadığına bakılır. Top-5'te doğru cevabın en benzer ilk beş aday içinde olup olmadığına bakılır. İkinci ya da üçüncü sırada bulunan doğru cevap da top-5'te isabet sayıldığı için top-5'in daha yüksek çıkması normaldir.

**Soru 3** (derste sözlü, 02:24:13; slayt ekrandan, 02:24:25): Bir slaytta "Ayrışma ne kadar belirginse model o kadar iyi ayırt ediyor" yazıyordu. t-SNE grafiğinde soruların ve cevapların iç içe geçmesi kötü bir şey midir?

**Cevap (hocanın cevabı):** Hayır, bunu kötü saymak zor. Eşleştirmede bir soru noktasına en yakın noktalar aranır. Sorular ve cevaplar birbirinden uzak kümelere ayrılırsa doğru cevabın bulunma olasılığı düşer. İstenen, aynı sorunun doğru cevabının o soruya yakın olmasıdır.

**Soru 4** (derste sözlü, 03:30:15): Bir paraphrase modelinin t-SNE grafiğinde iki kümenin üst üste bindiği, yani "eşleşmiş" göründüğü hâlde bu model en kötü sonucu vermiş. Bu nasıl olur?

**Cevap (derste verildi):** Hoca "Eşleşmişler ama doğru şeylerle doğru şeyler mi eşleşmişler acaba?" diye sordu. Öğrenci modelin yanlış çiftleri eşleştirdiğini doğruladı. Grafikte noktaların karışık görünmesi, her sorunun en yakın komşusunun kendi doğru cevabı olduğu anlamına gelmez. Bunu ancak top-1/top-5 sayıları gösterir.

**Soru 5** (derste sözlü, 03:09:09 - 03:09:23): Bir sunumdaki "ortalama güven skoru" nasıl hesaplanıyor?

**Cevap (derste verildi):** Birinci adayın benzerliğinden ikinci adayın benzerliği çıkarılarak hesaplanıyordu. Sunan öğrenci, bu skorun doğrulukla bir ilişkisi olmadığını ve başarıyı ölçmediğini sonradan fark ettiğini söyledi.

## Dersin Toparlaması

Bu derste birinci ödevin sunumları yapıldı. Ödev, 1 milyar parametrenin altındaki metin gömme modellerini Türkçe soru-cevap eşleştirmede karşılaştırmaktı. Bunun için sorular ve cevaplar vektörlere çevrildi, kosinüs benzerliğiyle sıralandı, iki yönde top-1/top-5 başarısı ölçüldü ve sonuçlar t-SNE ile görselleştirildi. Sunumlardan çıkan ortak tablo şu: Türkçeye özel ince ayar yapılmış `turkish-e5-large` çoğu durumda en iyi sonucu verdi. Parametre sayısı tek başına belirleyici olmadı. Paraphrase modelleri, eğitim amaçları simetrik benzerlik olduğu için asimetrik soru-cevap görevinde geride kaldı. Başarıyı en çok etkileyen şey de veri kümesinin yapısıydı: kelime örtüşmesi, cevap uzunluğu, konu çeşitliliği, aday havuzunun büyüklüğü.

Hocanın müdahaleleri iki noktada toplandı. Birincisi, kullanılan ölçütün tanımı ve sınırı bilinmeli; top-1, top-5 ve MRR'nin ne ölçtüğü açık olmalı. İkincisi, t-SNE grafiği doğru okunmalı: soruların ve cevapların iç içe geçmesi kötü değildir, önemli olan her sorunun doğru cevabının ona yakın olmasıdır. Üst üste binme de tek başına başarı göstermez. Sunumlarda önerilen iki aşamalı getirme (bi-encoder ve ardından cross-encoder) ve hibrit arama ise bu ödevdeki düşük skorlu kümeler için doğal bir sonraki adım olarak öne çıktı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
