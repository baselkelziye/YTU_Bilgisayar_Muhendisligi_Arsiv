# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin yapısı: birinci ödevin sunumları
  - Ders tümüyle öğrencilerin birinci ödev sunumlarına ayrıldı. Hoca konu anlatmadı; sunumlar sırasında sorular sordu ve yorum yaptı.
  - Ödevin konusu, sunumların ortak çerçevesinden anlaşıldığı kadarıyla: 1 milyar parametrenin altındaki metin gömme (embedding) modellerini Türkçe soru-cevap eşleştirme görevinde karşılaştırmak.
- Ödevin ortak deney düzeni
  - Modeller: MTEB (Massive Text Embedding Benchmark) sıralamasının üst sıralarından seçilen, 1 milyar parametreden küçük beş model ile YTÜ Cosmos ekibinin `ytu-ce-cosmos/turkish-e5-large` modeli.
  - Veri: iki Türkçe soru-cevap veri kümesi. Çoğu sunumda her kümeden yaklaşık 1000 soru-cevap çifti örneklendi.
  - Benzerlik: her soru ve cevap bir vektöre dönüştürülür, vektörler arasında kosinüs benzerliği hesaplanır.
    - $\text{cos}(A,B) = \dfrac{A \cdot B}{\lVert A\rVert\,\lVert B\rVert}$ (ekrandan, 00:30:00)
  - İki yön ölçülür (ekrandan, 00:30:00):
    - Soru → Cevap (Q2A): her soru için bütün cevaplar taranır, en yakın 5 cevap bulunur.
    - Cevap → Soru (A2Q): her cevap için bütün sorular taranır, en yakın 5 soru bulunur.
  - Başarı ölçüleri:
    - Top-1: en yüksek benzerlikli ilk sonucun doğru eşleşme olma oranı.
    - Top-5: doğru eşleşmenin en yüksek benzerlikli ilk 5 sonuç içinde yer alma oranı.
  - Görselleştirme: soru ve cevap vektörleri t-SNE ile iki boyuta indirilip aynı grafikte farklı renklerle çizildi.
- Kullanılan modeller (sunumlardan, ekrandan doğrulananlar)
  - `ytu-ce-cosmos/turkish-e5-large` (yaklaşık 560M parametre, Türkçe veriyle ince ayar yapılmış E5).
  - `intfloat/multilingual-e5-large`, `-base`, `-small` ve `multilingual-e5-large-instruct`.
  - `BAAI/bge-m3` (568M), `Alibaba-NLP/gte-multilingual-base` (305M), `Qwen3-Embedding-0.6B`, `google/embeddinggemma-300m`, Jina v5 metin gömme modelleri, Snowflake arctic-embed, F2LLM, KaLM-mini, Octen-Embedding-0.6B.
  - Paraphrase modelleri: `paraphrase-multilingual-mpnet-base-v2` (278M), `paraphrase-multilingual-MiniLM-L12-v2`, LaBSE, distiluse.
- Kullanılan veri kümeleri (örnekler)
  - TQuAD (Türk-İslam bilim tarihi; 681 başlık, 2332 paragraf, 8308 soru-cevap çifti; ekrandan, 01:50:00), XQuAD-TR, GSM8K-TR, Türkçe Wikipedia ve WikiRAG-TR, Türkçe hukuk soru-cevap kümeleri, AIXR Turkish-QA, IMDB Türkçe yorumlar, iklim değişikliği soru-cevap, TR-Extractive-QA, Turkish MMLU, tıp soru-cevap kümeleri, bir bilgi yarışmasının soru-cevapları.
- Ön ek (prefix) ve talimat (instruction)
  - E5 ailesi soruya `query: `, cevaba `passage: ` ön eki ister. Instruct sürümleri `Instruct: ...\nQuery: {q}` biçiminde görev cümlesi alır (ekrandan, 02:20:45).
  - BGE-M3, GTE ve paraphrase modelleri ön ek almaz.
  - EmbeddingGemma soruyu `encode_query`, cevabı `encode_document` ile ayrı rollerde kodlar (ekrandan, 00:40:00).
- Ortak bulgular
  - Türkçeye özel ince ayarlı `turkish-e5-large` çoğu veri kümesinde ve yönde ilk sıradaydı.
  - Başarı parametre sayısıyla doğru orantılı çıkmadı; mimari, eğitim verisi ve eğitim amacı belirleyici oldu.
  - Veri kümesinin yapısı başarıyı modelden daha çok etkiledi: soru ile cevap aynı kelimeleri paylaşıyorsa başarı çok yüksek (yaklaşık %98-99), cevaplar kısa ya da tek kelimeyse ve konular birbirine benziyorsa düşük (bazı kümelerde top-1 %10'un altında).
  - Yön farkı: cevaplar uzun ve bilgi yüklüyse cevap → soru yönü daha başarılı; cevaplar kısa ve birbirine benziyorsa (yıllar, adlar) soru → cevap yönü daha başarılı.
  - Paraphrase modelleri soru-cevap eşleştirmede geride kaldı.
  - Top-5 başarısı top-1'den belirgin biçimde yüksekti; model doğru konuya gidip doğru çifti ilk sıraya koyamayabiliyor.

## Hocanın Özellikle Vurguladığı Kısımlar

- t-SNE'de soru ve cevapların iç içe geçmesi kötü bir şey değildir
  - Bir sunumda "soru ve cevaplar ne kadar ayrışırsa model o kadar iyi" yorumu yapıldı (ekrandan, 02:24:25). Hoca buna itiraz etti.
  - Bir soru noktası alınır ve ona en yakın noktalar aranır. Sorular ve cevaplar birbirinden uzak kümelere ayrılırsa doğru cevabın bulunma olasılığı düşer. İstenen, aynı sorunun doğru cevabının o soruya yakın olmasıdır.
- Üst üste binme de tek başına başarı göstermez
  - Grafikte soru ve cevaplar karışık görünse bile asıl soru, doğru sorunun doğru cevapla eşleşip eşleşmediğidir. Bu ancak top-1/top-5 sayılarıyla anlaşılır.
- Ölçütün tanımı ve sınırı bilinmeli
  - Hoca bir sunumda MRR'nin nasıl hesaplandığını ve en çok kaç olabileceğini sordu. Ortalama alınan bir başarı ölçüsünün üst sınırı bilinmeden yorumlanamaz.
  - Top-1 ve top-5'in ne anlama geldiğini de sordu: top-1 doğru cevabın ilk sırada, top-5 ilk beş içinde olmasıdır.
- Her iki yön de raporlanmalı
  - Soru → cevap ve cevap → soru yönlerinin ikisi de ödevin parçasıdır; yön farkı veri kümesinin yapısı hakkında bilgi verir.

## Kısa Tekrar Notları

- Görev: soruyu ve cevabı vektöre çevir, kosinüs benzerliğiyle en yakın adayları sırala, top-1 ve top-5'i hesapla.
- Top-5 her zaman top-1'den büyük ya da ona eşittir.
- MRR@5: doğru cevap $r$. sıradaysa $1/r$ puan, ilk 5'te yoksa 0; bütün soruların ortalaması. En büyük değeri 1'dir (%100).
- Türkçeye özel ince ayar (`turkish-e5-large`) genellikle en iyi sonucu verdi.
- Parametre sayısı tek başına belirleyici değil.
- Soru-cevap arasında kelime örtüşmesi yüksekse eşleştirme kolay; kısa, tek kelimelik ya da bağlama muhtaç cevaplarda zor.
- Aynı konudan çok benzer sorular (hukuk, iklim, C bellek yönetimi) modelleri şaşırtır.
- Paraphrase modelleri simetrik anlam benzerliği için eğitilmiştir; asimetrik soru-cevap getirmede zayıftır.
- E5 ön ekleri ve talimat cümlesi başarıyı genelde artırdı, ama t-SNE'de soru ve cevapları keskin biçimde iki bloğa ayırabildi.
- t-SNE'de iç içe geçme kötü değildir; önemli olan doğru çiftin yakınlığıdır.
- İyileştirme önerileri: bi-encoder ile ilk 50-100 aday, ardından cross-encoder ile yeniden sıralama; BM25/TF-IDF ile vektör aramayı birleştiren hibrit arama.

## Detaylı Açıklamalar

- Ödevde neyin ölçüldüğü
  - Bir soru-cevap kümesinde her sorunun bir doğru cevabı vardır. Model bütün soruları ve cevapları aynı vektör uzayına gömer. Soru → cevap yönünde her soru vektörü bütün cevap vektörleriyle karşılaştırılır ve benzerliğe göre sıralanır. Doğru cevap ilk sıradaysa top-1'e, ilk beşteyse top-5'e bir isabet sayılır. Cevap → soru yönünde aynı işlem cevaplardan sorulara yapılır.
  - Bir sunumda vektörler L2 ile normalize edilip FAISS kütüphanesinin `IndexFlatIP` (iç çarpım) indeksine konuldu. Normalize vektörlerde iç çarpım kosinüs benzerliğine eşittir.
  - Bir sunumda top-1 ve top-5'in yanında MRR, "kategori uyumu" (getirilen 5 cevaptan kaçının sorunun kategorisinden olduğu) ve "ortalama güven skoru" (birinci ile ikinci adayın benzerlik farkı) da raporlandı. Sunan kişi güven skorunun başarıyı ölçmediğini kendisi belirtti.
- Neden `turkish-e5-large` öne çıktı
  - Model, `multilingual-e5-large` tabanından Türkçe veriyle ince ayar yapılarak elde edilmiştir. Sunumların çoğu bunu, Türkçe üslup farklarını (gündelik soru dili ile resmî cevap dili) ve Türkçe bağlamı daha iyi yakalamasına bağladı.
  - Her yerde birinci değildi: bir hukuk kümesinde BGE-M3, bir iklim kümesinde soru → cevap yönünde Jina, Turkish MMLU'da cevap → soru yönünde `multilingual-e5-large-instruct` önde çıktı. Turkish MMLU tablosu (cevap → soru, top-1/top-5): multilingual-e5-large-instruct 19.0/37.4, PIXIE-Rune-v1.0 18.5/36.0, turkish-e5-large 17.8/34.5, jina-v5-nano 16.2/34.0, jina-v5-small 15.7/33.9, Octen-0.6B 12.3/25.6 (ekrandan, 00:50:00).
- Parametre sayısı ve mimari
  - 300M parametreli EmbeddingGemma bazı kümelerde daha büyük modelleri geçti. 600M parametreli Qwen3-Embedding beklenenden zayıf kaldı. Bir tıp kümesinde `multilingual-e5-small`'dan `-large`'a geçince top-1 yaklaşık %6.9'dan %13.5'e çıktı. Yani boyut bazen yardımcı oluyor, ama tek başına sıralamayı belirlemiyor.
- Veri kümesinin etkisi
  - Kolay kümeler: soruda geçen kavram cevapta da geçiyor (ör. "istihkak davasının amacı nedir?" → "istihkak davasının amacı ..."), ya da konular birbirinden çok farklı (WikiRAG-TR, GSM8K-TR). Bir sunumda tek bir kümede altı modelin hepsi top-1'de %88-99 arasında kaldı (ekrandan, 02:50:00).
  - Zor kümeler: cevaplar tek kelime ya da yıl (TQuAD), soruda olmayan bir bağlama dayanıyor, aynı konudan çok sayıda benzer soru var, ya da soru gündelik dille, cevap resmî hukuk diliyle yazılmış. İki ayrı sunumda TQuAD'da en iyi model (`turkish-e5-large`) bile soru → cevap top-1'de yaklaşık %8'de kaldı (%8.5 ve %7.8; ekrandan, 01:30:00 ve 01:58:30).
  - Aday havuzu büyüdükçe (8000'e karşı 15000 çift) doğru cevabı ilk sıraya koymak zorlaşır.
  - Etiket gürültüsü de olabilir: TQuAD'daki bir soruda kayıtlı cevap yalnız "kendi" idi; model kişinin adını içeren, aslında doğru olan bir cevabı getirdi ama yanlış sayıldı.
- Yön asimetrisi
  - Uzun cevaplar daha çok anlamsal sinyal taşır; bu yüzden bir cevaptan onun sorusunu bulmak kolaylaşır.
  - Cevaplar kısa ve birbirine çok benziyorsa (çok sayıda yıl ya da ad), cevap tarafı tek bir bölgede yığılır ve cevaptan soruya gitmek zorlaşır; bu durumda soru → cevap yönü daha başarılı çıktı.
- Paraphrase modelleri
  - Bu modeller "aynı anlamı farklı kelimelerle söyleyen iki cümle"yi yaklaştırmak için eğitilmiştir (simetrik görev). Soru ile cevap aynı anlamı taşımaz, biri diğerini tamamlar (asimetrik görev). Bu yüzden paraphrase modelleri çoğu sunumda son sıralarda kaldı. Bir sunumda XQuAD-TR'de beklenmedik biçimde BGE-M3'ü geçen bir mpnet sonucu da raporlandı.
- t-SNE grafikleri nasıl okunmalı
  - Sunumlarda grafikler genelde "iç içe = iyi, ayrışmış = kötü" diye yorumlandı. Bazı sunumlar bunun tersini savundu. Hoca, doğru çiftlerin yakın olmasının esas olduğunu söyledi.
  - Grafik ile sayılar çelişebildi. `multilingual-e5` grafikte soruları ve cevapları "bıçakla kesilmiş gibi" iki bloğa ayırdı, ama top-5'te ikinci oldu. Sunan kişi bunu, `query:`/`passage:` ön ek sinyalinin konunun önüne geçmesine bağladı. Tersine, karışık görünen bazı grafiklerde başarı düşüktü, çünkü yakın duran noktalar yanlış çiftlerdi.
- Kök çözümleme
  - Bir sunumda metinler köklerine indirgenip yeniden denendi. Etki küçüktü ve modele göre işaret değiştirdi. Bağlama duyarlı modellerde ekleri atmak anlam kaybına yol açabildi.
- İyileştirme önerileri (ekrandan, 01:58:30)
  - İki aşamalı getirme: bi-encoder ile ilk 50-100 aday alınır, ardından soru ve aday birlikte bir cross-encoder'a verilip yeniden sıralanır.
  - Hibrit arama: vektör tabanlı arama ile BM25/TF-IDF gibi anahtar kelime tabanlı arama birleştirilir; özel ad içeren sorgularda faydalıdır.
  - Bir sunumda, ilk sırada yanlış ama ilk beşte doğru cevap bulunan örnekler "zorlu çeldiriciler" (hard negatives) olarak yorumlandı ve yeniden sıralayıcı önerildi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
