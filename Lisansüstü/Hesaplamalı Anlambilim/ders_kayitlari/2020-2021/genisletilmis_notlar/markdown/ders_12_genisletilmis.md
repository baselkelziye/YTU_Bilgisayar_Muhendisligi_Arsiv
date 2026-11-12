# Ders 12 Genişletilmiş Notu: Görsel Anlambilim: Resim Tanımı Üretme, Görsel Soru Cevaplama ve Karşıtsal Öğrenme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Görsel Anlambilim ve Çok Kipli Veri
- 2. Self-Supervised Öğrenmeye Kısa Bir Giriş
- 3. Resim Tanımı Üretme: İki Yaklaşım
- 4. Birinci Yaklaşım: Every Picture Tells a Story ve BabyTalk
- 5. İkinci Yaklaşım: Show and Tell
- 6. Video Tanımlama
- 7. Görsel Soru Cevaplama (VQA)
- 8. VQA Veri Kümesine Eleştiriler ve Güncelleme
- 9. Karşıtsal Öğrenme ve SimCLR
- 10. Genel Değerlendirme: Neredeyiz?
- 11. Proje Danışmanlığı: İki Boyutlu Kelime Temsilleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Görsel Anlambilim ve Çok Kipli Veri

Dönemin son dersinin konusu görsel anlambilimdir. Şimdiye kadar anlambilim hep metin üzerinde görüldü. Bu derste konunun çok kipli (multimodal) hâline geçiliyor. Multimodal, veri kümesinin içinde birden fazla kipte (modalite) veri olması demektir.

Hoca kipleri "veri yapısı türü" gibi düşünmeyi önerdi. Ses sinyali bir kiptir, durağan görüntü başka bir kiptir, video başka bir kiptir, metin başka bir kiptir, veri tabanındaki tablo verisi de başka bir kiptir.

Son zamanlarda çok ilgi gören bu alanda temel fikir, birden fazla kipe sahip veri kümelerini birlikte kullanmaktır. İnsanlar da kabaca böyle çalışır: görsel, işitsel, dokunsal, koku gibi birçok kipten gelen bilgi aynı anda gelir ve birleşerek karar verme sürecine katılır. Alan, tek kip yerine birden fazla kipten aynı anda yararlanmanın daha başarılı sonuç vereceği varsayımıyla ilerler.

Derste "görsel" kısım yalnız resim değildir; elimizde resim + metin olacaktır. Bir resmi anlatan bir cümle ya da cümleler, genel olarak bir metin bulunur. İçerik slaytında dört başlık vardır (ekrandan, 00:09:40):

- Resim Tanımı Üretme
- Video Tanımlama (videoyu bir metinle anlatmak)
- Görsel Soru Cevaplama (Visual Question Answering)
- Karşıtsal Öğrenme (Contrastive Learning)

Görsel soru cevaplamada, daha önce gördüğümüz metin tabanlı soru cevaplamadaki paragrafın yerini bir resim alır. Bir resim ve ona sorulan bir soru vardır; cevap bulunur ya da seçilir.

## 2. Self-Supervised Öğrenmeye Kısa Bir Giriş

Karşıtsal öğrenme, son zamanlarda çok popüler olan self-supervised (kendi kendine denetimli) yaklaşımların bir örneğidir. Hoca bunu üç öğrenme türünü karşılaştırarak anlattı:

- Supervised learning: her verinin etiketinin (çıkışının) ne olması gerektiğini biz söyleriz.
- Unsupervised learning: böyle bir şey söylemeyiz; kümeleme gibi işler yapılır.
- Self-supervised learning: yine etiketli veri vardır, ama bu etiketler insan tarafından sağlanmaz.

İnsan eliyle etiketleme oldukça sorunlu bir iştir (pahalıdır, doğruluğu tartışmalıdır, "bir sürü hikâyesi vardır"). Bu yüzden veri kümelerinde self-supervised yaklaşımlar çok önem kazandı.

Şimdiye kadar gördüklerimiz içinde en yakın örnek BERT'tir. BERT'te cümlenin içindeki bir kelime ya da bir alan kapatılır ve model onu tahmin eder. Bu veri kümesini kurmak çok kolaydır: bir cümle alınır, bir kelime kapatılır, kapatılan kelime etikettir. İnsanın etiketlemesine gerek yoktur.

## 3. Resim Tanımı Üretme: İki Yaklaşım

Resim tanımı üretmede (image captioning) iki yaklaşım vardır (ekrandan, 00:12:15):

1. Resimden CNN vb. dedektörlerle objeleri ve özelliklerini bul. Sonra bunlardan dil modeli vb. ile cümleleri üret. Bu iki aşamalı bir işlemdir: önce resmin içindeki kategoriler/nesneler çıkarılır, sonra bunlar kullanılarak cümle kurulur.
2. Problemi diller arası çeviri olarak ele al: görsel bir dilden metne çeviri. Bu uçtan uca (end-to-end) bir sistemdir. Makine çevirisinde girdi bir dil, çıktı başka bir dildir; burada da öyledir, yalnız girdinin kipi farklıdır. Girdi resim, çıktı metindir. Tek aşamalı bir mimari olarak tasarlanır.

## 4. Birinci Yaklaşım: Every Picture Tells a Story ve BabyTalk

### 4.1 Every Picture Tells a Story

Bu çalışma birinci yaklaşıma örnektir (ekrandan, 00:13:40). Slayttaki tanım şöyledir: resimleri ve cümleleri en benzedikleri (obje, eylem, yer) üçlüleriyle ifade eder; hazır listeler üzerinde çalışır; resim ile hazır cümlelerden birini eşler.

Şemada üç uzay vardır:

- Image Space (resim uzayı): resimler buradadır.
- Sentence Space (cümle uzayı): cümleler buradadır. Slayttaki örnekler: "A yellow bus is parking in the street.", "There is a small plane flying in the sky.", "An old fishing ship sailing in a blue sea.", "The train is moving on rails close to the station.", "An adventurous man riding a bike in a forest."
- Meaning Space (anlam uzayı): ikisinin eşleştiği yerdir. Buradaki üçlüler: `<bus, park, street>`, `<plane, fly, sky>`, `<ship, sail, sea>`, `<train, move, rail>`, `<bike, ride, grass>`.

Sistem resim uzayından bazı şeyler çıkarır, cümle uzayından da cümleleri ifade eden bazı şeyler çıkarır ve ikisini anlam uzayında eşleştirmeye çalışır. Amaç, hem resimlerle hem metinlerle mümkün olduğunca uyumlu üçlüler bulmaktır.

Önemli nokta: burada üretim yoktur. Elde örneğin milyonlarca hazır cümle vardır. Bir resim geldiğinde, bu cümleler içinden o resmi en iyi tanımlayan cümle seçilir. Bu bir seçim sürecidir.

Üçlüler özne, eylem ve yer üzerinden kurulur: "biri bir yerde bir şey yapıyor". Gemi denizde yol alıyor, uçak gökyüzünde uçuyor, otobüs caddeye park etmiş, tren raylarda hareket ediyor. Bu yapı yüzünden yöntem kısıtlıdır: yalnız bu türden cümleleri seçebilir, çok ayrıntılı bir tanım (caption) üretemez.

> **Ders sonrası not:** Hoca bu çalışmanın 2015-2016 civarında olması gerektiğini söyledi. Slayttaki çalışma (Farhadi ve arkadaşları, "Every Picture Tells a Story: Generating Sentences from Images") büyük olasılıkla 2010 tarihlidir; yani aşağıdaki 2011 tarihli BabyTalk'tan da eskidir.

### 4.2 BabyTalk

BabyTalk da birinci yaklaşıma örnektir ve 2011 tarihli, deep learning öncesi bir çalışmadır (ekrandan, 00:16:50). Slayttaki maddeler:

- (resim, tanım) ikililerine ihtiyaç duymaz. Hazır obje, özellik ve konum listeleri üzerinde çalışır.
- Deep learning öncesi: deformable part models + SVM.

Slayttaki işleyiş altı adımdır. Örnek resimde bir kişi, bir köpek ve bir kanepe vardır:

```text
Input Image
  -> 1) Objects/Stuff : a) dog, b) person, c) sofa
  -> 2) Attributes    : her obje için brown, striped, furry, wooden, feathered olasılıkları
                        (ör. sofa için brown 0.94)
  -> 3) Prepositions  : her obje çifti için near, against, beside olasılıkları
  -> 4) Constructed CRF
  -> 5) Predicted Labeling:
         <<null,person_b>,against,<brown,sofa_c>>
         <<null,dog_a>,near,<null,person_b>>
         <<null,dog_a>,beside,<brown,sofa_c>>
  -> 6) Generated Sentences
```

Önce objeler çıkarılır (köpek, kişi, kanepe). Sonra her birinin özellik listelerinde en yüksek olasılıklı olduğu özellikler bulunur. Sonra birbirlerine göre konumları bulunur. Bunlar bir CRF ile birleştirilir ve şu tür bir cümle üretilir (ekrandan, 00:16:50):

"This is a photograph of one person and one brown sofa and one dog. The person is against the brown sofa. And the dog is near the person, and beside the brown sofa."

Hoca iki yöntemi şöyle karşılaştırdı: Every Picture Tells a Story "kim/ne, nerede, ne yapıyor" sorusuna odaklanır. BabyTalk ise "resmin içinde neler var, bunların birbirine göre konumları ne" bilgisini çıkarır ve bunu anlatan basit gramerli cümleler üretir.

> **Ek bilgi (derste anlatılmadı):** CRF (Conditional Random Field), birbirine bağlı etiketlerin ortak olasılığını modelleyen bir grafik modeldir. BabyTalk'ta düğümler objeler, özellikler ve edatlardır; CRF bunların birlikte en tutarlı etiketlemesini seçer.

## 5. İkinci Yaklaşım: Show and Tell

### 5.1 Uçtan uca model ve optimizasyon

İkinci yaklaşıma örnek, 2014 tarihli Show and Tell çalışmasıdır (ekrandan, 00:18:05). Bu uçtan uca bir sistemdir: bir resim verilir ve resimden doğrudan bir metin üretilmesi istenir. Tabii bunun için elde (resim, metin) ikilileri vardır.

<!-- BELİRSİZ: Altyazıda çalışma "Chauventer 2014" diye geçiyor; slayt başlığı "Show and Tell", kaynak arxiv 1411.4555. Hocanın söylediği ad (büyük olasılıkla yazarın adı) anlaşılamadı. -->

İşleyiş şöyledir: resim bir CNN'e verilir. CNN bu resme ait bir tanımlayıcı (descriptor), yani resmi ifade eden bir vektör üretir. Sonra bu vektör bir RNN'e verilir. RNN'in LSTM, GRU vb. olması önemli değildir. Bu RNN'den bir cümle üretmesi beklenir. Slayttaki örnek: pazar yerinde bir resim → "Vision Deep CNN" → "Language Generating RNN" → "A group of people shopping at an outdoor market. There are many vegetables at the fruit stand."

Önceki yöntemlerdeki "önce şunları bulalım, sonra şunları" gibi adım adım işlem yoktur. Tek adımda girdi verilir ve bir metin üretilmesi istenir.

Optimizasyon (ekrandan, 00:18:05):

$$\theta^\star = \arg\max_\theta \sum_{(I,S)} \log p(S \mid I;\theta)$$

- $I$: resim
- $S$: resmin doğru tanımı
- $\theta$: model parametreleri

Yani eğitim kümesindeki $(I, S)$ ikilileri için olasılığı en büyük yapan $\theta$ aranır. Hem CNN'in hem RNN'in ağırlıkları birlikte optimize edilir.

$N$ uzunluğundaki bir tanımın olasılığı, zincir kuralıyla kelime kelime yazılır:

$$\log p(S \mid I) = \sum_{t=0}^{N} \log p(S_t \mid I, S_0, \dots, S_{t-1})$$

Her kelimenin olasılığı resme ve kendinden önceki bütün kelimelere bağlıdır.

### 5.2 Mimari

Mimari slaytı (ekrandan, 00:19:10) şunları söyler:

- CNN çıkışı LSTM'e giriştir.
- CNN parametreleri pre-trained ile başlar.
- $S_t$: one-hot vektör.
- $W_e$: word embedding katmanı.
- 512 LSTM hücresi vardır.

Diyagramın metne dökülmüş hâli:

```text
image -> CNN -> LSTM (ilk adım, resim vektörü)
S_0 -> W_e S_0 -> LSTM -> p_1 -> log p_1(S_1)
S_1 -> W_e S_1 -> LSTM -> p_2 -> log p_2(S_2)
...
S_{N-1} -> W_e S_{N-1} -> LSTM -> p_N -> log p_N(S_N)
```

Resim CNN'e verilir; CNN olarak ResNet ya da Inception gibi bir mimari kullanılır. <!-- BELİRSİZ: Hoca hangisi olduğunu tam hatırlamadığını söyledi (00:19:07). --> CNN ağırlıkları sıfırdan başlatılmaz. Çünkü "şu resimden şu tanım" türünde ikililerden elde çok fazla olmayabilir. Bu yüzden ImageNet gibi çok büyük bir veri kümesinde daha önce eğitilmiş bir mimariden başlanır; yani burada bir transfer learning vardır.

Kelimeler tarafında $S_t$'ler one-hot vektörlerdir. $W_e$ word embedding matrisidir; one-hot vektör bununla çarpılınca kelimenin embedding'i elde edilir. LSTM bir yandan resim vektörünü alır, bir yandan da kelimeler birer birer beslenir ve her adımda bir sonraki kelimenin olasılık dağılımı üretilir.

> **Ek bilgi (derste anlatılmadı):** Show and Tell makalesinde büyük olasılıkla GoogLeNet/Inception ailesinden bir CNN kullanılmıştır. Resim vektörü LSTM'e yalnız ilk adımda verilir; sonraki adımlarda yalnız kelime embedding'leri girer.

### 5.3 Tanım üretimi: sampling ve beam search

Eğitimden sonra tanım üretmek için iki yol vardır (ekrandan, 00:20:36). Hoca bu kısmın kritik olmadığını söyleyip hızlı geçti:

- Sampling: $p_1$'e göre bir kelime seç, sonra $p_2$, $p_3$, ... ile devam et.
- Beam search: o ana kadarki en olası 20 cümleyi tut. Olasılık hesabı $S = \arg\max_{S'} p(S' \mid I)$.
- Üretilen 20 cümleden en olası olanı seçildiğinde, bunların %80'i eğitim kümesindeki cümlelerdendir.

Son madde önemlidir: model çoğu zaman yeni bir cümle kurmak yerine eğitimde gördüğü cümleleri tekrar üretir.

### 5.4 Sonuçlar

Sonuç slaytında (ekrandan, 00:21:00) örnekler dört gruba ayrılmıştır: hatasız tanımlananlar, küçük hatalarla tanımlananlar ("Describes with minor errors"), resimle biraz ilgili olanlar ("Somewhat related to the image") ve resimle ilgisiz olanlar ("Unrelated to the image"). Slayttaki tanımlardan bazıları: "A group of young people playing a game of frisbee.", "Two hockey players are fighting over the puck.", "A little girl in a pink hat is blowing bubbles.", "A herd of elephants walking across a dry grass field.", "A close up of a cat laying on a couch.", "A red motorcycle parked on the side of the road.", "A yellow school bus parked in a parking lot.", "A refrigerator filled with lots of food and drinks."

Kötü örneklerin bir kısmında tanımın resimle hiç alakası yoktur; bir kısmında alakalıdır ama bariz biçimde yanlıştır; bir kısmında küçük hatalar vardır; bir kısmında tanım tamdır. Hoca, "A refrigerator filled with lots of food and drinks." tanımını "enteresan" bir hata olarak gösterdi: karede bu tanımın verildiği resim, üzerinde çıkartmalar olan bir trafik levhasıdır ve slaytta "resimle ilgisiz" grubundadır (ekrandan, 00:21:00).

> **Hocanın vurgusu:** Bu sistemler eğitim kümesine çok bağlıdır. Eğitim kümesindeki resimlere benzeyen, onlarla aynı kavramda olan resimlerde iyi çalışırlar; ama çok şaşırtıcı sonuçların da çıkabileceğini unutmamak gerekir.

## 6. Video Tanımlama

Hoca bu kısmı kabaca geçti. Slayttaki tanım (ekrandan, 00:21:50): yine çeviri sistemi tabanlıdır. 2D filtrelerle resimlerden, 3D filtrelerle video küplerinden (resimlerin arkaya doğru dizili hâli) özellik çıkarır.

Diyagramın metne dökülmüş hâli:

```text
input video -> frames -> image MIL model -> kelimeler (young, child, floor, little) -> A_i
            -> video  -> video MIL model -> kelimeler (cleaning, doing, machine, boy) -> A_v
A_i, A_v -> Transfer Unit -> LSTM -> LSTM -> w_{t+1}
input sentence: "a boy is cleaning the floor" -> w_t -> LSTM
```

Bir girdi videosu ve (eğitimde) bir girdi cümlesi vardır; sistem bu cümleyi üretmeyi öğrenir. Ara temsilin içinde hem kavramlar (kelimeler) hem vektörler vardır. Temel fark, tek bir resim yerine ardışık birçok resmin kullanılmasıdır.

## 7. Görsel Soru Cevaplama (VQA)

### 7.1 Görev ve gerekli kabiliyetler

Görsel soru cevaplamada bir resim (örneğin bir mutfak) verilir, ona çeşitli sorular sorulur ve sistemin cevapları bulması istenir. Bu iş için oldukça kapsamlı veri kümeleri ve leaderboard'lar vardır.

Gerekli kabiliyetler slaytı (ekrandan, 00:23:00) soruları türlerine ayırır:

- Nesne tanıma: "What kind of cheese is on the pizza?", "How many bikes are there?"
- Aktivite tanıma: "Is this man crying?"
- Hayat bilgisi ve çıkarım: "Is this a vegetarian pizza?", "Does this person have 20/20 vision?", "Is this person expecting company?"

Resimlerin altındaki örnek sorular: "What color are her eyes?", "What is the mustache made of?" (bıyık bir muzdan yapılmış), "How many slices of pizza are there?", "Is this a vegetarian pizza?", "Is this person expecting company?" (piknik örtüsü serilmiş bir sahne), "What is just under the tree?", "Does it appear to be rainy?", "Does this person have 20/20 vision?" (gözlüklü bir kişi; cevap "hayır" olmalı).

Hoca bu örneklerle görevin ne kadar zor olduğunu gösterdi: sistem nesneleri tanımalı, kaç tane olduklarını sayabilmeli, aktiviteyi tanımalı (bu kişi ağlıyor mu?) ve hayat bilgisiyle çıkarım yapabilmelidir (gözlük takan biri 20/20 göremez; iki kişilik sofra kurmuş biri birini bekliyordur).

### 7.2 Yöntem ve baseline sonuçları

Yöntem slaytı (ekrandan, 00:24:40):

- Frekansı en yüksek olan ilk $K = 1000$ cevap alınır; problem 1000 sınıflı bir sınıflandırma problemine dönüşür.
- Sorular bag of words (1030 boyut), resimler VGGNet (4096 boyut) ile kodlanmıştır.
- MLP ve LSTM kullanılmıştır.
- Giriş: soru, resim, soru + resim.
- Baseline sonuçları: resimlerin etkisi çok değil!

Cevap biçimi iki türlüdür. Open-answer'da cevap üretilir: "yes/no", bir sayı ya da başka bir metin üretmek gerekir. Multiple-choice'ta ise seçenekler arasından seçim yapılır: yes/no'yu, bir sayıyı ya da başka bir şeyi seçmek gerekir. Hoca bunu "bunlar üretim, bunlar seçim" diye özetledi.

> **Ders sonrası not:** Hoca bir yerde multiple-choice'un "yes/no diye de geçtiğini" söyledi. Tabloda Yes/No, Number ve Other sütunları hem Open-Answer hem Multiple-Choice altında yer alır; yani Yes/No bir soru türüdür, cevap biçimi değildir. Hocanın hemen sonraki "üretim / seçim" açıklaması doğrudur.

Baseline tablosu (ekrandan, 00:24:40):

| Girdi | OA All | OA Yes/No | OA Number | OA Other | MC All | MC Yes/No | MC Number | MC Other |
|---|---|---|---|---|---|---|---|---|
| Question | 48.09 | 75.66 | 36.70 | 27.14 | 53.68 | 75.71 | 37.05 | 38.64 |
| Image | 28.13 | 64.01 | 00.42 | 03.77 | 30.53 | 69.87 | 00.45 | 03.76 |
| Q+I | 52.64 | 75.55 | 33.67 | 37.37 | 58.97 | 75.59 | 34.35 | 50.33 |
| LSTM Q | 48.76 | 78.20 | 35.68 | 26.59 | 54.75 | 78.22 | 36.82 | 38.78 |
| LSTM Q+I | 53.74 | 78.94 | 35.24 | 36.42 | 57.17 | 78.95 | 35.80 | 43.41 |

(OA: Open-Answer, MC: Multiple-Choice.)

Tablodan "resmin etkisi çok değil" sonucu şöyle okunur (farklar python ile hesaplandı):

- Open-answer, tüm sorular: yalnız soru 48,09, soru + resim 52,64. Resim eklemek yalnız 4,55 puan kazandırıyor. LSTM'de 48,76'dan 53,74'e, 4,98 puan.
- Yes/No sorularında resim neredeyse hiç katkı vermiyor: 75,66 → 75,55 (−0,11).
- Number sorularında resim eklenince doğruluk düşüyor bile: 36,70 → 33,67 (−3,03).
- En büyük kazanç Other türünde: 27,14 → 37,37 (+10,23); multiple-choice'ta 38,64 → 50,33 (+11,69).
- Yalnız resim verildiğinde Number ve Other doğrulukları %0,4-3,8 düzeyinde kalıyor.

Yani soru tek başına cevabın büyük kısmını veriyor. Bu da bir sonraki bölümdeki eleştirilere götürür.

### 7.3 Arka kapılar ve iyi bir veri kümesinin özelliği

Hoca burada önceki haftalarda konuşulan "arka kapı" konusunu hatırlattı. Makine öğrenmesi algoritmalarına ne yapmaları gerektiğini, yani girdi-çıktı eşlemesini söyleyebiliriz: "böyle bir giriş gelince böyle bir çıkış üret". Ama nasıl yapmaları gerektiğini söyleyemeyiz. Bu anormal de değildir: nasıl yapılacağını bilsek, öğrenen bir sisteme ihtiyaç duymadan doğrudan kodlardık.

Bu yüzden sistem kısa yollar (arka kapılar) bulabilir. Bunu yakalamak için girdiler üzerinde denemeler yapılır:

- Eğitimi biten sisteme yalnız soruyu verip resmi vermemek. Doğru cevap vermemesi beklenir.
- Tersine, yalnız resmi verip soruyu vermemek.

> **Hocanın vurgusu:** Beklenen şey, resim + soru birlikte verildiğinde sistemin iyi çalışması, herhangi biri eksik olduğunda iyi çalışmamasıdır. Yalnız soruya ya da yalnız resme bakarak doğru cevap üretilebiliyorsa, o veri kümesi istediğimiz şeyi pek karşılamıyor demektir.

## 8. VQA Veri Kümesine Eleştiriler ve Güncelleme

### 8.1 Eleştiriler

İlk VQA veri kümesi için slayttaki eleştiriler (ekrandan, 00:27:45):

- "What sport is" ile başlayan soruların %41'inin cevabı "tenis".
- "How many" ile başlayan soruların %39'unun cevabı "2".
- "Bu resimde balık var mı?" sorusu ancak resimde balık varsa soruluyor. "Bu resimde X var mı?" sorularının %81'inin cevabı "evet".

Birinci maddenin neden kötü olduğu derste soruldu ve cevaplandı: böyle bir soru gelince sistem doğrudan "tenis" der ve bu tür soruların en az %41'inde doğru olur. Bu, veri kümesi açısından kötü bir yanlılıktır.

Üçüncü maddenin nedeni veri kümesinin nasıl kurulduğudur. Sorular crowdsourcing ile üretilmiştir: insanlara bir resim verilir ve "bu resme bakarak cevaplanabilecek sorular yazın" denir. İnsanlar doğal olarak resimde gördükleri şeyleri sorar; balık yoksa "balık var mı?" diye sormazlar. Sonuç olarak "X var mı?" sorularının cevabı çoğunlukla "evet" olur.

Bu kümede iyi başarılar elde edilmişti, ama küme bu nedenlerle çok eleştiri aldı.

### 8.2 Veri kümesinde güncelleme

Eleştirilerden sonra veri kümesi güncellendi (ekrandan, 00:29:30). Amaçlar:

- Sorularla cevaplar arasındaki düzenlilikleri ortadan kaldırmak.
- Resme bakmadan doğru cevap verebilmeyi önlemek.
- Bu tarz sistemlerin başarılarının abartılmamasını sağlamak.

Çözüm: aynı sorunun farklı resimler için farklı cevaplarının olduğu bir benchmark. Slayttaki örnekler:

| Soru | 1. resimde cevap | 2. resimde cevap |
|---|---|---|
| Who is wearing glasses? | man | woman |
| Where is the child sitting? | fridge | arms |
| Is the umbrella upside down? | yes | no |
| How many children are in the bed? | 2 | 1 |

Slaytta ayrıca "What game is this?" sorusu için cevabı tenis olmayan bir resim seçme arayüzü ve kırmızıyla "Yeterli mi? Başka ne yapılabilir?" sorusu vardır.

Böyle bir küme kurulunca sistem yalnız soruya bakarak cevap veremez. Çünkü yalnız soruya bakan bir sistem için gördüğü bütün seçeneklerin olasılıkları birbirine eşittir; örneğin "man" %50, "woman" %50. Çocuk aynı soruda bir resimde buzdolabının içinde, öbüründe annesinin kollarında oturur; cevap ancak resme bakılarak verilebilir.

Bu güncellemeler sayesinde veri kümesi "daha iyi" hâle geldi. Hoca bunun anlamını şöyle açıkladı: algoritmalar bu kümede daha kötü çalışır hâle geldi. Özgün kümede çok yüksek başarıya ulaşan sistemlerin başarısı yeni kümede oldukça düştü. Yani yeni küme, sistemin gerçekten resmi anlayıp anlamadığını daha iyi ölçer.

## 9. Karşıtsal Öğrenme ve SimCLR

### 9.1 Karşıtsal öğrenme

Karşıtsal öğrenmenin slayttaki tanımı (ekrandan, 00:31:30):

- Contrastive Learning: iki girdi için "benzer" ya da "değil" diyebilmek.
- Çözüm: benzer olanlar için benzer, farklı olanlar için farklı çıktılar üretebilmek.
- Eğitim kümesini oluşturmada eğiticili ve eğiticisiz yöntemler var.
- Eğiticili: farklı 2 kedi resmi benzesin, 1 kedi ve 1 balık benzemesin.

Eğiticili yöntemde iki kedi resmi verilince sistem "benzer", bir kedi ve bir balık verilince "benzer değil" demelidir. Bunun için etiketler bilinmelidir: hangi resmin kedi, hangisinin balık olduğu. Ancak böylece aynı sınıftan iki örnek "benzer", farklı sınıflardan iki örnek "benzer değil" diye etiketlenebilir. Bu yapılabilir ve yapılmış çalışmalar da vardır, ama eğiticili olması bir sıkıntıdır.

### 9.2 SimCLR

Eğiticili olma sorununu aşmak için önerilen bir yöntem SimCLR'dir. Hoca bunun Hinton'ın son çalışmalarından biri olduğunu söyledi. Slayttaki maddeler (ekrandan, 00:32:50):

- Self-supervised, eğiticisiz; eğitim kümesi üretme yöntemi ölçeklenebilir.
- Aynı resim içindeki resim parçaları (transform edilmiş hâlleri) benzer temsillere, farklı resimlerdekiler farklı temsillere sahip olsun.
- Eğitim sonrası temsiller istenilen görevde kullanılabilir.

SimCLR'in amacı tamamen eğiticisiz bir şekilde pre-trained bir model oluşturmaktır. İşleyiş:

1. Bir resim alınır.
2. Bu resmin içinden rastgele iki parça kırpılır (crop).
3. Sistem renklere takılmasın diye bu parçalara çeşitli dönüşümler uygulanır: renk ağırlıklarını değiştirmek, gri tonlamaya çevirmek, kenar bulma (edge detection) gibi klasik dönüşümler (augmentation).
4. Dönüştürülmüş parçalar CNN'e, sonra MLP'ye verilir ve her biri için bir temsil üretilir.
5. Aynı resimden gelen iki parçanın temsilleri birbirine yaklaştırılır (slaytta "attract"); farklı resimlerden gelen parçaların temsilleri birbirinden uzaklaştırılır ("repel").

Slayttaki örnekte bir köpek resmi ve bir sandalye resmi vardır. Köpek resminden kırpılan iki parça (biri renkleri değiştirilmiş) birbirine yakın olmalıdır; sandalye resminden kırpılan iki parça (biri yeşilleştirilmiş, biri grileştirilmiş) birbirine yakın olmalıdır. Ama köpek parçalarıyla sandalye parçaları birbirinden uzak olmalıdır.

Güzelliği self-supervised olmasıdır. Bu şekilde pre-trained bir model kurulduktan sonra, transfer learning ile istenen başka bir görevde kullanılabilir. Bütün resim de kullanılabilir, parçaların temsilleri bulunup birleştirilerek de kullanılabilir. Sonuçta sisteme farklı köpek resimleri etiketli olarak verilmeden, resmin kendi içindeki ilişkilerden köpeği, kediyi tanıyabilen bir model elde edilir.

### 9.3 SimCLR'in sınırı

Yöntem içinde tek bir obje olan resimler için oldukça iyi görünür. Ama resimde birden fazla obje varsa sorun çıkar. Örneğin üstte bir kedi, altta bir köpek olsun. Yukarıdan bir parça, aşağıdan bir parça kırpılırsa sistem kedi ile köpeğin temsillerini birbirine benzetmeye zorlanır. Bu yüzden böyle durumlarda çok iyi bir yaklaşım değildir. Yine de ImageNet ya da CIFAR gibi klasik benchmark'larda oldukça verimli çalıştığı gösterilmiştir.

### 9.4 Resim-metin ikilileri ve yalnız metin

Slayttaki sorular (ekrandan, 00:36:50): "Resim-metin ikilileri üzerinde nasıl çalıştırabiliriz? Bir cevap: https://openai.com/blog/clip/. Peki sadece metinler üzerinde?"

Elde hem resimler hem bunlara karşılık gelen caption'lar varken karşıtsal öğrenmeyi farklı kipli yapılarda nasıl çalıştırırız sorusunun bir cevabı OpenAI'ın CLIP çalışmasıdır. Hoca bunu incelemeyi önerdi.

Yalnız metin üzerinde ise henüz çok iyi sonuç yoktur; hoca kendilerinin de bunun üzerinde uğraştığını söyledi. Fikir şöyle olabilir: bir cümlenin farklı parçaları birbirine yakın, farklı cümlelerin parçaları birbirine uzak olsun. Ama bu, resimlerdeki kadar iyi çalışmaz. Çünkü bir cümlenin tamamı tek bir şeyi anlatmaz; cümlenin bir parçası bir şeyi, başka bir parçası başka bir şeyi anlatır. Resmin bir parçasına bakıp resmin bütünü hakkında bir şey söyleyebilirsiniz, ama cümlenin yalnız bir parçasına bakıp bütüne dair bir şey söylemek daha güçtür. Cümleler, içinde birden fazla nesne olan resimler gibidir; yani 9.3'teki sınırla aynı soruna düşer. Fikir oldukça eskidir, uygulaması oldukça güçtür.

Hoca, slayttaki kaynaklardan Hinton'la yapılmış söyleşinin dökümünü (eye-on.ai) incelemeyi önerdi; orada Hinton son zamanlarda neyle uğraştığını ve bu fikrin hikâyesini anlatıyor.

> **Ek bilgi (derste anlatılmadı):** CLIP (Contrastive Language-Image Pre-training) bir resim kodlayıcı ve bir metin kodlayıcıyı birlikte eğitir. Bir yığındaki doğru (resim, caption) çiftlerinin temsilleri birbirine yaklaştırılır, yanlış eşleşmelerinki uzaklaştırılır. Böylece SimCLR'deki "aynı resmin iki parçası" yerine "bir resim ve onun metni" pozitif çift olur. Büyük olasılıkla 2021 başında yayımlanmıştır.

## 10. Genel Değerlendirme: Neredeyiz?

Son slayt (ekrandan, 00:39:05):

- 5 yıl içinde büyük gelişim.
- Sebepleri:
  - Nesne tanıyıcıların başarısının artışı.
  - Etiketli veri kümelerinin artışı.
  - Self supervised yöntemlerdeki gelişmeler.
- Dikkat: başarıları / veri kümelerini iyi incelemek gerekiyor.
- Aşağıda neler oluyor?

> **Hocanın vurgusu:** Self-supervised konusu çok önemlidir. Unsupervised değil, self-supervised; buna dikkat edin. Yine etiketli bir öğrenme yapılır, ama etiketleri sistem kendisi elde eder. Ayrıca başarıları ve veri kümelerini iyi incelemek, arka kapılar meselesini akıldan çıkarmamak gerekir.

Hoca daha gidilecek çok yol olduğunu iki resimle gösterdi. Birincisinde birkaç kişi bir odadadır. Günümüz teknolojisi bu resimde insanları, yerdeki halıyı, lambaları, eski tip bir tartıyı, aynayı bulabilir; her kişinin vücut duruşunu, yüz ifadesinden mutlu ya da üzgün olduğunu söyleyebilir. Ama resimde "ne olduğunu" anlatmak başka bir iştir. Resimde bir kişi tartıya çıkmıştır, Obama da arkadan ayağıyla tartıya basmaktadır.

Bu resmin tanımını üretmek için sistemin tartının ağırlık ölçtüğünü bilmesi yetmez; tartının nasıl çalıştığını da bilmesi gerekir: üzerine biri çıkınca bir şey olur, arkadan biri basarsa ölçülen değer artar, tartıdaki kişi "kilo aldım" diye şaşırır ve bu yüzden olay komiktir. Bunu tarif edebilmek çok zordur.

İkinci resimde bir bomba imha uzmanı işinin başındadır; arkasında bir arkadaşı elinde bir kese kâğıdıyla onu patlatmaya hazırlanır. Hoca bunun zalimce bir şaka olduğunu söyledi. Resimdeki nesneleri bulmak kolaydır: kum, kürek, belki bir bomba, bomba imha uzmanı, elinde kese kâğıdı olan bir kişi. Ama bunun bir şaka olduğunu anlamak için dünya kadar ek bilgi gerekir. Hocanın değerlendirmesiyle, resimde ne olduğunu anlatmak için daha epey uzun bir yol vardır.

> **Ek bilgi (derste anlatılmadı):** Obama'nın tartıya ayağıyla bastığı fotoğraf, bilgisayarlı görmenin sınırlarını anlatmak için büyük olasılıkla Andrej Karpathy'nin 2012 tarihli bir blog yazısıyla tanınmıştır. Yazının ana fikri derstekiyle aynıdır: nesneleri tanımak, sahneyi "anlamaktan" çok uzaktır.

## 11. Proje Danışmanlığı: İki Boyutlu Kelime Temsilleri

Ders bittikten sonra hoca proje sorusu olup olmadığını sordu. Bir öğrenci kendi projesinin akademik bir sorusunu ekran paylaşarak anlattı. Bu bölüm yalnız tartışmanın akademik kısmını içerir.

Öğrencinin konusu iki boyutlu kelime embedding'leridir. Daha önce hocayla konuştukları gibi, fastText vektörlerini sonradan yeniden şekillendirmek (reshape) yerine, embedding'leri baştan iki boyutlu (reshape edilmiş) hâlleriyle eğitmeyi deniyordu.

Yaklaşımı şöyleydi:

- Çıkış noktası, Keras ile yazılmış bir skip-gram modelidir. Bu modelde girdi kelime (input word) ve bağlam kelime (context word) embedding'leri alınır, nokta çarpımları (dot product) hesaplanır ve çıktının 1 (gerçek bağlam) mı yoksa negatif örnekleme ile seçilmiş 0 mı olduğu öğrenilir.
- Öğrenci bu modeli çok değiştirmeden "2DimWE" adlı bir Keras katmanı yazdı. Katmanın içinde iki embedding katmanı vardır: birinci embedding katmanının çıkardığı değerler ikinci embedding katmanıyla tekrar embed edilir. İki kez embed edildiği için her kelime iki boyutlu bir dizi (matris) olur.
- Birinci embedding'in her elemanı belli bir tamsayı aralığına çekilip tamsayıya çevrilir ki ikinci embedding katmanına indeks olarak verilebilsin. <!-- BELİRSİZ: Altyazıda aralık "0.255 veya 0.1000" diye geçiyor; büyük olasılıkla 0-255 ya da 0-1000 aralığı kastediliyor (00:44:15). -->
- Sonra bu iki boyutlu temsil düzleştirilir (flatten). Amaç skip-gram'ın nokta çarpımlı yapısını bozmamaktır; aksi hâlde ağ skip-gram'dan çok uzaklaşır.
- Sistem iki boyutlu temsilleri öğrenebiliyor, ama yakınsama (convergence) sorunu var; çok iyi yakınsamıyor ya da öğrenemiyor olabilir.

Hoca yaklaşımı özetledi: kelimeler önce iki boyutlu bir temsile çevriliyor ve öğrenilen şey, kelimelerin iyi bir iki boyutlu temsilidir; yeni katmandaki iki embedding birlikte kelimelerin iki boyutlu gösterimini oluşturur.

**Soru:** Eğitimde temsil düzleştiriliyor; sonraki görevde de düzleştirilmiş hâli mi kullanılmalı?

**Cevap:** Hoca, düzleştirmenin yalnız skip-gram eğitimini bozmamak için yapıldığını kabul etti. Ama gerçek kullanımda, örneğin bir sınıflandırma probleminde, temsil düzleştirilmeden kendi iki boyutlu hâliyle kullanılmalıdır. Bir cümle, bu iki boyutlu karelerin yan yana gelmesiyle oluşan bir resim gibi olur ve üzerinde CNN filtreleri (örneğin 5x5) gezdirilir.

**Soru:** Bir cümledeki kelimelerin iki boyutlu temsilleri üst üste eklenip ortalama alınarak mı birleştirilmeli, yoksa birleştirilerek (concatenate) mi?

**Cevap:** Üst üste eklemenin pek anlamı yoktur. Temsiller yan yana konarak birleştirilmeli (concatenate); bir maksimum cümle uzunluğu belirlenir ve boş kalan kısımlar sıfırla doldurulur, tıpkı resimlerde yapıldığı gibi.

Öğrenci yöntemin riskli olduğunu, çalışmayabileceğini söyledi. Hoca bunun mümkün olduğunu, daha iyi çalışırsa çok iyi olacağını, mevcut yöntem kadar çalışsa da bunun da bir sonuç olduğunu söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:27:45; derste sözlü, 00:27:39): VQA veri kümesinde "What sport is" ile başlayan soruların %41'inin cevabı "tenis"tir. Bu iyi bir şey mi? Neden?

> **Çözüm (derste verildi):** Değildir. Böyle bir soru gelince sistem resme bakmadan doğrudan "tenis" diyebilir ve bu tür soruların en az %41'inde doğru olur. Bu, veri kümesinde bir yanlılıktır; sistemin başarısını abartır. Aynı durum "How many" sorularının %39'unun "2" olması ve "X var mı?" sorularının %81'inin "evet" olması için de geçerlidir.

**Soru 2** (ekrandan, 00:24:40): Baseline tablosuna göre "resimlerin etkisi çok değil" iddiası nereden çıkıyor?

> **Çözüm (derste verilmedi; farklar python ile hesaplandı):** Open-answer tüm sorularda yalnız soru 48,09, soru + resim 52,64 doğruluk verir; resmin katkısı 4,55 puandır (LSTM'de 48,76 → 53,74, 4,98 puan). Yes/No sorularında katkı −0,11, Number sorularında −3,03 puandır. Yalnız Other türünde belirgin bir kazanç vardır (+10,23). Yani cevabın büyük kısmı tek başına sorudan tahmin edilebilmektedir.

**Soru 3** (ekrandan, 00:29:30): VQA veri kümesi, sistemin resme bakmadan cevap vermesini önlemek için nasıl güncellendi?

> **Çözüm (derste verildi):** Aynı sorunun farklı resimler için farklı cevaplarının olduğu bir benchmark kuruldu (ör. "Who is wearing glasses?" → man / woman; "How many children are in the bed?" → 2 / 1). Yalnız soruya bakan bir sistem için bütün cevaplar eşit olasılıklı olur, bu yüzden resme bakmak zorunlu hâle gelir. Güncellenmiş kümede sistemlerin başarısı belirgin biçimde düştü.

**Soru 4** (ekrandan, 00:32:50; derste sözlü, 00:36:38 ve 00:37:09): SimCLR'deki karşıtsal öğrenme resim-metin ikilileri üzerinde nasıl çalıştırılabilir? Peki yalnız metinler üzerinde?

> **Çözüm (derste verildi):** Resim-metin ikilileri için bir cevap OpenAI'ın CLIP çalışmasıdır. Yalnız metinde henüz çok iyi sonuç yoktur: bir cümlenin farklı parçaları birbirine yakın, farklı cümlelerin parçaları uzak olsun denebilir; ama cümlenin parçaları farklı şeyler anlattığı için, bir parçaya bakıp bütün hakkında bir şey söylemek zordur. Cümleler, içinde birden fazla nesne olan resimlere benzer.

**Soru 5** (derste sözlü, 00:40:28): Obama'nın tartıya arkadan ayağıyla bastığı resmin tanımını (image captioning) üretmek için sisteme neler gerekir?

> **Çözüm (derste verildi):** Bir öğrenci, sistemin tartının nasıl çalıştığını ve ağırlık ölçtüğünü bilmesi gerektiğini söyledi. Hoca, tartının ölçüm yaptığını bilmenin yetmediğini, nasıl çalıştığını da bilmek gerektiğini ekledi: üzerine biri çıkınca değer gösterir, arkadan biri basarsa değer artar, tartıdaki kişi kilo aldığını sanıp şaşırır; olayın komik olduğu buradan anlaşılır. Yani nesneleri tanımanın ötesinde dünya bilgisi ve çıkarım gerekir.

## Dersin Toparlaması

Bu derste anlambilim, metinden resim + metin ikililerine taşındı. Resim tanımı üretmede iki yaklaşım görüldü: önce nesneleri ve özellikleri bulup sonra cümle kuran iki aşamalı yöntemler (hazır cümle seçen Every Picture Tells a Story, CRF ile şablon cümle kuran BabyTalk) ve resmi doğrudan cümleye "çeviren" uçtan uca Show and Tell (pre-trained CNN + LSTM). Video tanımlama aynı çeviri fikrini ardışık karelere ve 3D filtrelere genişletir. Görsel soru cevaplamada resim, metin tabanlı soru cevaplamadaki paragrafın yerini alır; ama ilk VQA kümesindeki yanlılıklar sistemlerin resme bakmadan iyi sonuç almasına izin verdi ve aynı soruya farklı resimlerde farklı cevap gerektiren yeni benchmark, bu başarının abartılı olduğunu gösterdi.

Son olarak self-supervised bir yöntem olan karşıtsal öğrenme ve SimCLR görüldü: aynı resmin dönüştürülmüş parçaları yakın, farklı resimlerin parçaları uzak temsillere sahip olur; bu fikir CLIP ile resim-metin ikililerine taşınmıştır, yalnız metinde ise henüz zordur. Hocanın kapanış mesajı iki yönlüdür: son yıllarda nesne tanıma, etiketli veri ve self-supervised yöntemler sayesinde büyük ilerleme oldu; ama başarılar ve veri kümeleri arka kapılar açısından dikkatle incelenmeli ve bir resimde "ne olduğunu" anlatmak için daha uzun bir yol vardır. Bu ders dönemin son dersiydi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
