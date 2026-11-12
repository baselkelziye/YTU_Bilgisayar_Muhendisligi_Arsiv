# Ders 5 Genişletilmiş Notu: İkinci Ödev Sunumları: Dil Modellerinde Gizli Durum Yörüngelerinin Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi ve Ödevin Konusu
- 2. Yörünge Nasıl Elde Edilir?
- 3. Kullanılan Modeller ve Veri Kümeleri
- 4. Yörüngeden Çıkarılan Özellikler
- 5. Tahmin Görevleri ve Sonuçlar
- 6. Örnekleme Ayarının Etkisi: Deterministik ve Yaratıcı Mod
- 7. Bağlamın Etkisi
- 8. Yörüngeler Arası Benzerlik ve Orijinal Metinle Karşılaştırma
- 9. Farklı Yaklaşımlar
- 10. Kendi Çözümü ve Yapay Zekâ Çözümü
- 11. Hocanın Yöntem Uyarıları

## 1. Dersin Çerçevesi ve Ödevin Konusu

Bu dersin tamamı ikinci ödevin sunumlarına ayrıldı. Hoca yeni konu anlatmadı; her sunumda sorular sordu, yöntem hatalarını gösterdi ve nasıl daha iyi yapılabileceğini söyledi. Bu not, sunumlardaki akademik içeriği ve hocanın müdahalelerini bir araya getirir. Sunanlar "bir öğrenci" ya da "bir grup" diye anılır.

Hoca dersin başında ödevi şöyle özetledi: bir yörüngenin şeklinden hangi özellikler çıkarılabilir ve bu özelliklerle neler tahmin edilebilir? Herkesin farklı bir yaklaşım geliştirmesini beklediğini, bu yüzden sunumlarda farklı fikirler görmeyi umduğunu söyledi. Ödevde ikinci bir boyut daha vardı: problemi hem öğrencinin kendisinin çözmesi hem de bir yapay zekâ aracına çözdürmesi, sonra bu iki çözümü karşılaştırması bekleniyordu.

Bir öğrencinin sunumunun ortasında yaptığı özet, ödevin çerçevesini iyi veriyor (02:12:27): model bir token üretir, sonra bir token daha üretir. Her token üretilmeden önce elde bir son temsil, yani gizli durum (hidden state) kalır. Bu gizli durumlar sırayla dizildiğinde bir yörünge oluşur. Soru, bu yörüngenin analiziyle dil modeli hakkında neler söylenebileceğidir: neler tahmin edilebilir, hangi özellikler çıkarılabilir?

Sunumlarda tekrar eden yapı şöyleydi:

- **Veri:** Bir istem (prompt) kümesi; çoğunlukla 1000 istem.
- **Modeller:** İki (bazen üç ya da beş) küçük dil modeli.
- **Yörüngeler:** Her istem için her modelde 50 yeni token'lık bir yörünge.
- **Özellikler:** Yörüngenin şeklini özetleyen sayılar.
- **Tahmin:** Bu özelliklerden model kimliğini ve istemle ilgili bir bilgiyi (konu, kategori, dil vb.) sınıflandırmak.
- **Karşılaştırma:** Öğrencinin özellikleri ile yapay zekâ aracının önerdiği özelliklerin başarısı.

## 2. Yörünge Nasıl Elde Edilir?

### 2.1 Hocanın soruları

İlk sunumda hoca, yörüngenin nasıl elde edildiğini adım adım sordu (00:04:20 - 00:07:54). Sunan grup önce "modelle beraber yörünge elde etme fonksiyonları vardı" dedi. Hoca bunun ne demek olduğunu sorunca şu tarif ortaya çıktı:

1. İstem modele bütünüyle verilir.
2. Model istemin ardından gelecek bir token'ı tahmin eder. Bu sırada son katmanda bir gizli durum vektörü oluşur.
3. Üretilen token girdiye eklenir; model bir sonraki token'ı üretir. Her yeni token bir öncekilerin üzerine kurulur.
4. Bu işlem belirlenen sayıda (bu grupta en az 50, en çok 80 token) tekrarlanır.

Bu grupta Qwen2.5 0.5B için yörünge matrisi $80 \times 896$, Falcon-H1 0.5B için $80 \times 1024$ boyutundaydı. Satır sayısı üretilen token sayısı, sütun sayısı modelin gizli boyutudur. <!-- BELİRSİZ: aynı grup "50'şer 50'şer kaydıra kaydıra" da dedi; kayan pencere kullanılıp kullanılmadığı altyazıdan anlaşılmıyor. -->

Sunumların çoğu 50 token üretti ve her adımda son katmandaki son token'ın vektörünü aldı. Böylece her yörünge $50 \times d$ boyutlu bir matris oldu. Örneğin 1000 yörünge ve $d=1024$ için veri $1000 \times 50 \times 1024$ boyutundadır.

### 2.2 Farklı toplama biçimleri

- Bir sunumda model 60 adım çalıştırıldı ve her adımda son katmanın son vektörü saklandı; 1000 örnek için 60 000 vektör oluştu.
- Bir sunumda model tüm girdiyi gördükten sonra ürettiği token'ı yeniden girdiye ekleyerek döngüyle ilerledi (yorum puanı sunumu).
- Bir sunumda yörünge iki yoldan çıkarıldı: (a) 100 kelimelik bir metnin ilk 50 kelimesi verildi ve model devamını kendisi üretti; (b) 100 kelimenin tamamı aynı anda verildi ve 51-100. konumlardaki gizli durumlar alındı. İkinci yörünge, modelin gerçek metni "okurken" oluşturduğu temsillerdir. Hoca, (b)'de modele kendi ürettiğinin değil orijinal metnin verildiğini teyit etti (02:27:39 - 02:27:54).

### 2.3 Yörüngenin başlangıç noktası

Bir sunumda bütün yörüngelerin grafikte aynı noktadan başladığı görüldü. Hoca bunun nasıl olduğunu sordu. Sunan öğrenci, soru sorulduğunda modellerin genelde benzer bir başlangıçla cevaplamaya başladığını tahmin etti (01:14:39 - 01:14:43). Bu bir varsayım olarak kaldı.

## 3. Kullanılan Modeller ve Veri Kümeleri

### 3.1 Modeller

Sunumlarda geçen modeller ve sunumlarda söylenen gizli boyutları:

- GPT-2 (768), GPT-2 Medium (1024), GPT-2 Large, GPT-2 XL (1.5B; bir sunumda 8-bit kuantize edildi), DistilGPT-2.
- GPT-Neo, Pythia (160M ve 1.4B sürümleri geçti), OPT, BLOOMZ.
- Qwen2.5 0.5B (896), Qwen2.5 1.5B (yaklaşık 1500), Qwen3 0.6B (1024), Qwen3 4B (2560).
- Llama 3.2 1B (2048), SmolLM2 1.7B (2048), Falcon-H1 0.5B (1024).
- YTÜ Cosmos ekibinin Türkçe GPT-2 modelleri (`ytu-ce-cosmos/turkish-gpt2-large` ekrandan, 02:13:30) ve Hugging Face'te paylaşılmış başka bir Türkçe GPT-2 modeli; ikisi de yaklaşık 0.1 milyar parametreli ve 12 transformer katmanlıydı.
- Gemma 2 tabanlı modeller ve bir sunumda Türkçe BERT ile çok dilli BERT (encoder modeller).

> **Ders sonrası not:** Bir sunumda iki Gemma 2 modelinin gizli boyutları "biri 3800 küsür, diğeri 2000 küsür" diye verildi; hoca ikisinin de Gemma 2 olmasına şaşırdı (02:19:12 - 02:19:38). Aynı ailenin farklı büyüklükleri farklı gizli boyutlara sahip olabilir. Büyük olasılıkla Gemma 2 2B'nin gizli boyutu 2304, 9B'nin 3584'tür; sunumdaki sayılar bu değerlere yakındır.

> **Ders sonrası not:** Bir sunumda GPT-2 Medium ile Pythia'nın ikisinin de gizli boyutunun 1024 olduğu söylendi; slaytta ise Pythia-1.4B yazıyordu (ekrandan, 03:44:30). Büyük olasılıkla Pythia-1.4B'nin gizli boyutu 2048'dir; 1024 boyutlu olan sürüm Pythia-410M'dir.

### 3.2 Veri kümeleri

- Kendi yazdıkları ya da şablonla ürettikleri istemler: 24 Türkçe + 16 İngilizce istem (her biri 30 kez çalıştırılarak); 10 kategoride 10 şablonla soru cümleleri (ör. "Explain the central idea of ..." + "The fall of Constantinople"); teknoloji ve film üzerine "şu konuyu şu düzeydeki birine anlat" türünden dinamik istemler.
- Databricks Dolly 15K: sekiz kategori (brainstorming, classification, closed_qa, creative_writing, general_qa, information_extraction, open_qa, summarization).
- SQuAD (soru + bağlam paragrafı), Yahoo Answers Topics, AG News (dünya, spor, iş, bilim-teknoloji), WikiText-103 / Salesforce WikiText, Türkçe Wikipedia.
- IMDB film yorumları, Türkçe film/dizi özetleri, Türkçe haber başlıkları, Türkçe talimat (instruction) veri kümesi, GSM8K-TR (adım adım çözülen matematik problemleri), Türkçe restoran yorumları (hız, lezzet ve servis puanlarıyla).

Bir grup, Dolly'den yaratıcı yazım ve genel soru-cevap kategorilerini özellikle seçti: yaratıcı istemlerde model en azından 50 token'lık bir uzunluğa ulaşır, genel soru-cevap ise yaratıcı olmayan bir karşıt grup oluşturur.

## 4. Yörüngeden Çıkarılan Özellikler

### 4.1 Adım, yol ve yer değiştirme

Bir sunumun slaytında tanımlar şöyle verildi (ekrandan, 00:42:15):

- Adım vektörü: $s_i = h_{i+1} - h_i$
- Toplam yol uzunluğu: $L = \sum_i \lVert h_{i+1} - h_i \rVert$
- Net yer değiştirme (displacement): $D = \lVert h_{50} - h_1 \rVert$
- Düzlük oranı (straightness): $R = D / (L + \varepsilon)$

$R$ bire yakınsa yörünge neredeyse düz bir çizgi gibi ilerlemiştir; küçükse çok dolanmıştır. Bu oran başka sunumlarda "efficiency" (kuş uçuşu mesafenin toplam yola oranı, doğrusallık; ekrandan, 04:14:10) ya da "linearity" diye geçti. Bir yapay zekâ çözümü bunun tersini, "tortuosity" (kıvrımlılık) ölçüsünü önerdi: yörünge başlangıçtan bitişe düz gitmek yerine ne kadar dolanıyorsa o kadar yüksektir (ekrandan, 01:21:05).

Hoca $\varepsilon$'un ne olduğunu ve neden "kararlılık" için eklendiğini sordu (00:42:45). Sunan öğrenci formülü bir makaleden aldığını, $\varepsilon$ üzerinde düşünmediğini söyledi. Bu sorunun cevabı Örnek Sorular bölümündedir.

Adım uzunluklarından türetilen özellikler: ortalama, standart sapma, en büyük, en küçük adım. Bir grup bunlara "kinematik özellikler" dedi (ekrandan, 03:12:20).

### 4.2 Açı, kosinüs ve eğrilik

Bir sunumda ardışık üç nokta $A, B, C$ için açı şöyle tanımlandı (ekrandan, 01:34:45):

$$\cos\theta = \frac{\vec{AB} \cdot \vec{BC}}{\lVert \vec{AB} \rVert \, \lVert \vec{BC} \rVert}$$

Açı 0'a yakınsa model aynı yönde devam ediyor, yani düz gidiyordur. 50 token'lık bir yörüngede 49 adım vektörü ve 48 açı vardır.

İki farklı kosinüs kullanımı sunumlarda sık karıştı:

- **Ardışık noktalar arası kosinüs:** $\cos(h_t, h_{t+1})$. Bu, iki temsilin ne kadar benzediğini söyler.
- **Ardışık adımlar arası kosinüs:** $\cos(s_t, s_{t+1})$. Bu, yörüngenin yön değiştirip değiştirmediğini söyler. Bir öğrenci bunu "farkların benzerliği bana hareket yönünü veriyor" diye anlattı.

Eğrilik (curvature) bir sunumda $1-\cos\theta$ olarak hesaplandı (04:14:32). Sunan öğrencinin anlattığı gibi: adımlar aynı yöndeyse değer 0, aralarında 90 derece varsa 1, yörünge 180 derece geri döndüyse 2 olur. Python ile kontrol: $1-\cos(\pi/2)=1$, $1-\cos(\pi)=2$.

Bir grup ayrıca başlangıç ile bitiş vektörleri arasındaki kosinüsü ($v_{50}$ ve $v_1$) bir "başlangıç-bitiş açısı sapması" özelliği olarak kullandı (ekrandan, 03:12:20).

### 4.3 Norm ve "enerji"

Gizli durum vektörünün kendi uzunluğu (normu) da özellik olarak kullanıldı. Bir sunumda yapay zekânın eklediği "durum normlarının standart sapması" (`norm_std`) model kimliğinde en önemli özellik çıktı (önem 0.271; ekrandan, 01:21:05).

İlk sunumda "global enerji" diye bir özellik geçti. Hoca bunun ne olduğunu sordu (00:12:45 - 00:13:43); sunan öğrenci net bir tanım veremedi. Başka bir sunumun yapay zekâ özellik kümesinde aynı adla "adımların karelerinin toplamı" tanımı vardı (ekrandan, 00:53:00).

### 4.4 PCA tabanlı özellikler

- **Açıklanan varyans oranları:** Bir grup, yörüngenin iki boyutlu temsilindeki en önemli ve ikinci en önemli yönün açıkladığı varyansı ("Explained Variance 1 ve 2") özellik olarak aldı ve yörüngenin ne kadar kararlı ya da yayılmış olduğunu gösterdiğini söyledi (ekrandan, 00:17:30). Hoca "en önemli yön ne demek?" diye sorduğunda grup açıklayamadı.
- **Etkin boyut (effective dimensionality):** Yörüngedeki 50 noktaya PCA uygulanır ve toplam varyansın %90'ını açıklamak için kaç bileşen gerektiği sayılır. Model 2560 boyutlu bir uzayda hareket eder, ama asıl soru gerçekte kaç boyut kullandığıdır. Düşük değer yörüngenin dar bir alt uzayda kaldığını, yüksek değer daha fazla boyuta yayıldığını gösterir (ekrandan, 01:32:10).
- **İki boyutlu izdüşümün şekli:** PCA ile iki boyuta indirilen yörüngenin kapladığı alan, dışbükey zarf (convex hull) alanı, onu içine alan en küçük dikdörtgenin alanı, merkezden yayılım.
- **"Silindir mi tepsi mi?":** Bir sunumda PCA, 1024 boyutlu yörüngeyi 2-3 boyuta sıkıştırıp modelin "düşünce sürecinin" genel hacmini gösteren bir araç olarak kullanıldı: üretilen 50 kelime dar bir silindir gibi mi uzanıyor (konu dar ve belirli), yoksa geniş bir tepsi gibi mi yayılıyor (konu dağınık ve çeşitli) (ekrandan, 02:24:40).

> **Ek bilgi (derste anlatılmadı):** PCA, noktaların kovaryans matrisinin özvektörlerini bulur. En büyük özdeğere ait özvektör, verinin en çok değiştiği yöndür; ikincisi buna dik olan ve kalan varyansın en çoğunu taşıyan yöndür. Her bileşenin "açıklanan varyans oranı", o özdeğerin bütün özdeğerlerin toplamına oranıdır. Hocanın sorduğu "en önemli yön" bu birinci temel bileşendir.

### 4.5 Histogram özellikleri

Bir sunumda adım uzunlukları ve açılar 10 kutulu histogramlara konup özellik vektörü yapıldı (ekrandan, 00:53:00). Hoca bu yaklaşımı başka bir sunumda kendisi de önerdi (Bölüm 6.3). Aynı sunumda "varyans" diye bir özellik vardı; hoca nasıl hesaplandığını sorunca öğrenci 1024 boyutun ilk üçünün alındığını, bunun rastgele bir seçim olduğunu söyledi.

Hoca bu sunumda iki özellik kümesinin hangi ölçüte göre "Küme 1" ve "Küme 2" diye ayrıldığını da sordu. Öğrenci ödevde iki küme istendiği için böyle ayırdığını söyleyince hoca, ayrımın bir mantığı yoksa "küme 1 küme 2'den daha iyi" gibi bir yorumun anlamlı olmayacağını belirtti (00:53:25 - 00:54:05).

### 4.6 Hız, ivme, sarsıntı ve entropi

Yapay zekâ araçlarının önerilerinde sık geçen bir bakış, ardışık token'lar arası uzaklığı birim zamanda alınan yol, yani hız saymaktır.

- **Hız:** $\lVert h_{t+1} - h_t \rVert$; her adım bir birim zaman kabul edilir.
- **Sarsıntı:** Hızdaki değişimlerin standart sapması. Model bir kelimede çok hızlı, bir kelimede çok yavaş gidiyorsa sarsıntı yüksek çıkar (ekrandan, 03:07:00).
- **Semantik gradyan (ivme):** Ardışık adımlar arasındaki L2 mesafe farkının token indeksine oranlanmış değişim hızı. Önerinin yorumu: sabit gradyan tutarlı bir akış, azalan gradyan cevabın sonuna doğru anlamsal sapma, dalgalı gradyan fikirler arası sıçrama demektir (ekrandan, 02:51:20).
- **Yörünge entropisi:** Ardışık üç token arasındaki yönsel değişimlerin (kosinüs mesafesi) varyansı. Düşükse doğrusal bir akıl yürütme, yüksekse sık ve keskin yön değişimi ve bağlam kaybı olarak yorumlandı (ekrandan, 02:51:20).

Bu yorumlar yapay zekâ aracının önerileriydi; derste doğrulanmadı.

## 5. Tahmin Görevleri ve Sonuçlar

### 5.1 Model kimliği

Hemen bütün sunumlarda yörünge özelliklerinden modeli tahmin etmek %95-100 doğrulukla başarıldı. Birkaç örnek:

- Qwen2.5 0.5B ve Falcon-H1: %100. Sunan grup, yörünge yapılarının birbirinden çok farklı olduğunu söyledi.
- Llama 3.2 1B ve SmolLM2: LR, Random Forest ve LightGBM ile %100. Yalnız bir norm özelliğiyle (en küçük norm) %99.88.
- GPT-2 ve Pythia, GPT-2 ve GPT-Neo, Qwen ve GPT-2 Medium: %100'e yakın. Bir grubun kendi özellikleriyle %100, yapay zekânın özellikleriyle %99.3 (ekrandan, 04:26:35).

Bir öğrenci, yalnız iki özellikle (ardışık Öklid uzaklığı ve ardışık kosinüs benzerliğinin ortalaması ve varyansı; toplam dört sayı) bile sınıflandırmanın çok kolay olduğunu gördü. Verileri incelediğinde iki modelin "farklı uzaylarda" hareket ettiğini fark etti. Sonuç olarak yörünge, modelin bir parmak izi gibi davranıyor.

Bir sunumda, model tahmininde boyut farkının bir "sızıntı" yaratmaması için yapay zekâ aracı aynı gizli boyuta sahip iki model seçilmesini önerdi (Llama ve SmolLM2, ikisi de 2048). Hoca "boyut sızıntısı" teriminin ne demek olduğunu sordu; öğrenci gizli boyut farkının sonucu etkilememesini kastettiğini söyledi.

### 5.2 Dil tahmini

Türkçe ve İngilizce istemlerden oluşan bir kümede dil tahmini %86-90 civarında çıktı ve üç farklı tohumda (seed) standart sapma düşük kaldı. Görselleştirmede modeller doğrusal olarak ayrılırken diller daha "topak topak" dağıldı. Önemli özelliklere bakıldığında model kimliği için global özellikler (bütün yörünge boyunca gizli durumların genel büyüklüğü ve dağılımı), dil tahmini için geometrik özellikler (yörüngenin adım adım izlediği yolun şekli) öne çıktı (ekrandan, 00:11:10).

### 5.3 Konu ve kategori tahmini

Konu ya da kategori tahmini bütün sunumlarda modelden çok daha zayıf kaldı:

- İki konu (spor/teknoloji, derin öğrenme/futbol): şans düzeyi %50 iken sonuçlar %50-70 arasında.
- Beş kategori (science, sport, travel, technology, story): öğrencinin geometrik özellikleriyle %74 civarı. <!-- BELİRSİZ: altyazıda "%74 doğruluk ... ilk model birdi" deniyor; %74'ün hangi model ve görev için olduğu net değil. -->
- On kategori: "çok zayıf". Sunan öğrenci, iki kategoride %60-70 gibi bir sonucun yanıltıcı olabileceğini, bu yüzden kategori sayısını artırdığını söyledi.
- AG News (dört sınıf): Random Forest ile ham uzaklık dizileri kullanıldığında doğruluk %37 civarında kaldı; en iyi sınıf bilim-teknoloji oldu.
- Dolly (sekiz sınıf, şans düzeyi $1/8 = 12.5\%$): öğrencinin 29 özelliği LR/RF/LightGBM ile %29.7 / %31.6 / %30.7; yapay zekânın yaklaşık 990 özelliği %52.2 / %43.6 / %52.7 (ekrandan, 01:48:15).

Dolly sunumunda karışıklık matrisinde hatalar anlamca komşu sınıflara düştü (ekrandan, 01:51:15):

| Sürekli karışan çiftler (LightGBM, yapay zekâ özellikleri) | Oran |
|---|---|
| summarization ↔ closed_qa | ~%26 |
| information_extraction → closed_qa / summarization | ~%22 |
| open_qa ↔ general_qa | ~%22 |
| brainstorming → creative_writing | ~%14 |

Sunan öğrencinin yorumu: summarization ve closed_qa'nın ikisi de bir metinden bir şey çıkararak cevap ürettiği için yapı olarak birbirine benziyor. Random Forest'ın çok sayıda özellikte LR ve LightGBM'in gerisinde kalmasını ise slayt, yüksek boyutlu ve PCA ile döndürülmüş özelliklerin eksenlere paralel kesimler yapan ağaçlarla kötü uyuşmasına bağladı.

Bir grup, Qwen3 0.6B ve GPT-2 Medium'la iki istem türünü (teknoloji / film) kendi üç özelliğiyle %90.3, yapay zekânın özellikleriyle %66 doğrulukla ayırdı (ekrandan, 04:26:35). Kendi özellikleri ortalama kosinüs benzerliği ile PCA izdüşümünde x ve y eksenlerindeki standart sapmaydı.

Sunanların genel yorumu: yalnız adımların büyüklüğü ve açıları verildiğinde model, derin öğrenme ve futbol hakkında benzer adımlar atar ve benzer zikzaklar çizer. Bu yüzden geometrik özellikler model kimliği için iyi bir parmak izidir ama anlamsal ayrıştırma için yetmez.

### 5.4 İstem uzunluğu

Bir öğrenci istemleri uzunluğa göre üç sınıfa ayırdı (30 token'dan kısa, 30-80 arası, 80'den uzun) ve uzunluğun yörüngeden tahmin edilip edilemeyeceğine baktı. Uzun istemler %85 doğrulukla tahmin edildi. Hoca, uzun sınıftaki örnek sayısının (304) etkisini sordu; bir sınıf kalabalıksa sınıflandırıcı o sınıfı daha sık söyleyerek yüksek doğruluk alabilir (03:53:54 - 03:54:05). Model kimliğinde en etkili özellik ilk beş PCA bileşeninin toplam varyansı oldu.

### 5.5 Yorum puanı

Bir öğrenci restoran yorumlarında, yorum metninin yörüngesinden kullanıcının hıza ve lezzete verdiği puanın "iyi" mi "kötü" mü olduğunu tahmin etmeye çalıştı. Fikri şuydu: kullanıcı hıza kötü puan verdiyse metinde de hızdan kötü bahsetmesi olasıdır; bu bilgi yörüngeye yansıyor mu? Puanlar 8'den büyükse "iyi", 3 ve altıysa "kötü" sayıldı; orta sınıf, tahmini %30-40'larda bıraktığı için çıkarıldı. Sınıflar dengesiz olduğu için alt örnekleme (undersampling) yapıldı.

Beş özellik türetildi: normalize ortalama Öklid uzaklığı (`avg_dist_norm`), ortalama kosinüs (`avg_cos`), kosinüsün standart sapması (`std_cos`), verimlilik (`efficiency`) ve ortalama eğrilik (`avg_curvature`). Diğerleriyle yüksek korelasyon gösteren `avg_cos` ve `std_cos` elendi (ekrandan, 04:14:10). Uzaklık ve eğrilik birlikte kullanılınca başarı %60'ın üzerine çıktı; hız tahmininde verimlilik ve eğrilik bir fark yarattı.

Hoca, olumlu ve olumsuz iki örneğin yörüngelerini karşılaştıran grafikte iki yörüngenin benzer olduğunu ve "aynı yere vardığını", büyük modelde ise daha çok bir öteleme gördüğünü söyledi (04:18:38 - 04:19:13).

## 6. Örnekleme Ayarının Etkisi: Deterministik ve Yaratıcı Mod

### 6.1 Fikir

Bir öğrenci iki farklı model yerine aynı modeli (Qwen3 4B) iki farklı örnekleme ayarıyla kullandı: biri açgözlü (greedy), yani deterministik mod; diğeri yüksek sıcaklıklı (temperature 1.5), yani yaratıcı mod. Fikir, modellerin farklı "karakterleri" olabileceği gözleminden çıkmıştı. Soru: yörüngeden modelin karakteri tahmin edilebilir mi?

Örnek bir istemde ("bir farenin gözünden bir sabahı üç cümleyle anlat") deterministik mod bile beklenenden yaratıcı bir cevap verdi; yaratıcı modda ise daha alışılmadık kelimeler görüldü.

### 6.2 İki özellik ve sonuçlar

- **Etkin boyut (Bölüm 4.4):** Hipotez, yaratıcı modun beklenmedik token'lar seçtiği için daha fazla boyuta yayılacağıydı. 1000 örneğin 504'ünde yaratıcı mod, 281'inde deterministik mod daha çok boyut kullandı; 215'inde eşit çıktı (toplam 1000). Ortalamalar yakındı (yaklaşık 29'a 28), ama bin örnek üzerinden bakınca yaratıcı mod belirgin biçimde ayrıştı. Bazı istemlerde fark 20 bileşene yaklaştı.
- **Yön değişimi varyansı (Bölüm 4.2):** Hipotez, yüksek varyansın tutarsız açılar yani yaratıcı model anlamına geleceğiydi. 48 açının ortalaması yaratıcı modda biraz daha yüksek çıktı.

Sunan öğrenci bir makine öğrenmesi sınıflandırıcısı kullanmadı; yalnız iki modun dağılımlarını karşılaştırdı.

### 6.3 Hocanın önerileri

**Kademeli sıcaklık:** Hoca iki mod arasındaki farkın çok bariz olmadığını söyledi ve sıcaklığın kademeli artırılmasını önerdi: düz bir mod, yaratıcı bir mod, daha da "çılgın" bir mod... Böylece bir uçtan öbür uca bir geçiş görülebilir (01:37:09).

**Ortalama yerine histogram:** Hoca, 48 açının ortalamasını almak yerine bu 48 değerin örneğin 5 ya da 10 kutulu bir histogramını almayı önerdi (01:38:31 - 01:39:14).

> **Hocanın vurgusu:** Büyükleri ve küçüklerin hepsini ortalamaya hapsettiğinizde sinyal kaybedersiniz. Bir tarafa sıçrar, öbür tarafa sıçrar; bunların ortalamasını aldığınızda hepsi aynı yere gelir. Histogramın bir şekli çıkar ve bu çok daha iyi bir şeydir.

**Öğrencinin gözlemi:** Sıcaklığın etkisi doğrudan değil birikerek görülür. Deterministik mod beklenen bir token seçer, yaratıcı mod ilginç bir token seçer; ama otuzuncu token üretilirken önceki yirmi dokuz token iki modda farklı yöne gitmiştir. Gizli durumlar seçilen token'ları değil, o token'larla değişen bağlamı yansıtır. Öğrenci ayrıca veri kümesinin (ör. "en çok kahve ihraç eden beş ülke" gibi yaratıcılık gerektirmeyen sorular) ve modelin küçüklüğünün farkı azaltmış olabileceğini söyledi.

## 7. Bağlamın Etkisi

Bir öğrenci SQuAD'dan sorular aldı ve iki koşul oluşturdu: (a) yalnız soru, (b) soru + cevabı içerebilecek bağlam paragrafı. Hoca, bağlam verilen yörüngelerin daha uzun olup olmayacağını sordu. Öğrenci, iki koşulda da istemden sonra üretilen 50 token'ın yörüngesini aldığını, bu yüzden uzunluğun aynı olduğunu açıkladı (00:51:14 - 00:52:08).

Sonuçta bağlam verilen (kırmızı) yörüngeler daha toplu, bağlamsız (mavi) yörüngeler daha sıçramalı göründü. Öğrenci bunu modelin bağlam varken daha az rastgele token ürettiği biçiminde yorumladı (ekrandan, 00:59:10).

"Ortalama yörünge" şöyle hesaplandı: bin yörüngenin her adımındaki vektörlerin boyut boyut ortalaması alındı; sonuç tek bir 50 adımlık yörünge oldu ve iki boyuta indirilip çizildi. Hoca bu açıklamayı anlamadığını söyledi (00:59:52).

Aynı sunumda öğrencinin kendi çözümü ile yapay zekâ çözümünün yörünge grafikleri farklı çıktı. Hoca burada önemli bir noktaya dikkat çekti: yörüngeler bir kez üretilir ve iki çözümün özellikleri bu aynı yörüngelerden çıkarılır; iki çözümde farklı yörünge oluşmamalıdır (00:56:34 - 00:58:12).

## 8. Yörüngeler Arası Benzerlik ve Orijinal Metinle Karşılaştırma

### 8.1 Kosinüs benzerlik matrisi

Bir grup üç model (Qwen, OPT, BLOOMZ) ve Dolly'den yaratıcı yazım ile genel soru-cevap kategorilerini kullandı. Her 50 adımlık yörünge, adım vektörlerinin ortalaması alınarak (mean pooling) tek bir 1024 boyutlu temsil vektörüne indirildi. 1000 yörünge için 1000 × 1000 boyutlu bir kosinüs benzerlik matrisi hesaplandı (ekrandan, 02:56:30):

| Ölçüm | Değer |
|---|---|
| Qwen ve OPT'nin aynı sorulara çizdiği yörüngelerin ortalama benzerliği | %2.94 |
| Qwen: yaratıcı yazım kendi içinde | %41.03 |
| Qwen: genel bilgi kendi içinde | %40.76 |
| Qwen: yaratıcı yazım ile genel bilgi arası | %39.32 |
| OPT: yaratıcı yazım kendi içinde | %62.92 |
| OPT: genel bilgi kendi içinde | %58.70 |
| OPT: yaratıcı yazım ile genel bilgi arası | %59.94 |

<!-- BELİRSİZ: altyazıda Qwen'in iki görev arası benzerliği "%9.32" diye geçiyor; slaytta %39.32 yazıyor, slayttaki değer alındı. -->

Grubun yorumu: Qwen'de iki görev arası benzerlik, görevlerin kendi içindeki benzerliğinden düşük; yani görevleri az da olsa ayırıyor. OPT'de ise görevler arası benzerlik kendi içindeki benzerlikle aynı düzeyde. BLOOMZ'de benzerlik neredeyse 1'di; yörüngeler tek bir noktaya çöktü ("temsil çökmesi"). Grup bunu, 50 token'a zorlanan modelin daha kısa cevap verip çıkmak isteyince gürültü eklemesine ya da tam tersine yarıda kesilmesine bağladı. Benzerlik matrisinin satırları XGBoost'a verildiğinde model tahmini %100, görev tahmini %70 civarında çıktı.

Hoca girdinin ne olduğunu sordu ve cevabı netleştirdi: her yörüngenin diğer bütün yörüngelere benzerliği, yani 1000 sayılık bir vektör sınıflandırıcıya veriliyor (03:00:09 - 03:00:47). Daha önce de t-SNE grafiğindeki her noktanın neyi temsil ettiğini sormuş ve bir yörüngenin 50 adımın ortalamasıyla tek bir noktaya dönüştürüldüğünü öğrenmişti (02:53:17 - 02:55:23). Ortalama alındığında yörüngenin şekli değil, uzaydaki ortalama konumu kullanılmış olur.

### 8.2 Orijinal metin ile modelin ürettiği metin

Bölüm 2.2'deki iki yörünge türünü kullanan sunumda soru şuydu: modelin kendi ürettiği yörünge ile orijinal metnin yörüngesi arasındaki fark, makalenin zorluğuna göre değişir mi? Her makale için ortalama L2 mesafe hesaplandı. GPT-2'de makaleler arasında belirgin farklar çıktı; Qwen'de mesafeler hep yüksek ve birbirine yakındı (ekrandan, 02:29:45). Öğrenci, bazı makalelerin daha teknik ve karışık, bazılarının ise ilerleyişi daha tahmin edilebilir olduğunu söyledi.

Hoca iki öneri yaptı:

- **Perpleksiteyle sayısallaştırmak:** "Zor" ve "kolay" yargısını göze bırakmak öznel kalır. Her metnin o modele göre perpleksitesi hesaplanıp yörünge farkıyla ne kadar uyumlu olduğu ölçülebilirdi (02:30:50 - 02:31:14).
- **Sıralamanın yanılttığı:** Grafik kırmızı (GPT-2) değerlere göre sıralandığı için çok düzenli, mavi (Qwen) değerler ise dağınık görünüyor. Maviye göre sıralansaydı mavi de düzenli görünürdü (02:31:37 - 02:32:14).

> **Ek bilgi (derste anlatılmadı):** Perpleksite, bir dil modelinin bir metindeki token'lara verdiği olasılıkların geometrik ortalamasının tersidir: $\text{PPL} = \exp\left(-\frac{1}{N}\sum_{i=1}^{N}\log p(x_i \mid x_{<i})\right)$. Değer küçükse metin model için beklenen, büyükse beklenmedik bir metindir. Hocanın dediği gibi, bir metnin model için ne kadar "zor" olduğunu tek bir sayıyla verir.

Aynı sunumda iki ek deneme vardı: rastgele eşlenen iki yörüngenin aynı makaleden olup olmadığını tahmin etmek (sonuç şans düzeyinde kaldı) ve 63 makaleyi etiketsiz kümelemek (yaklaşık 0.3 civarında kaldı). Hoca kümelemeden önce PCA yapmaya gerek olmadığını söyledi.

## 9. Farklı Yaklaşımlar

### 9.1 Token'dan token tahmini

Bir öğrenci sınıflandırma yerine farklı bir soru sordu: yörüngenin ilk beş vektörüyle altıncı vektör bir formülle tahmin edilebilir mi? Sonra bu altıncı tahmin pencereye eklenir ve yedinci tahmin edilir. Formül ekranda şöyleydi (ekrandan, 03:32:40):

```text
fark_i       = token[i+1] - token[i]          (i = 0..3, beşli pencerede)
fark_i_n     = normalize(fark_i)
fark_ortalama = (0.5*fark1_n + 0.6*fark2_n + 0.7*fark3_n + 1*fark4_n) / 2.8

benzerlik_i  = cos(token[i], token[i+1])
benzerlik_ortalama = (0.5*b1 + 0.6*b2 + 0.7*b3 + 1*b4) / 2.8

fark_benzerlik_i = cos(fark_i, fark_{i+1})       ("hareket yönü")
fark_benzerlik_ortalama = (0.5*fb1 + 0.6*fb2 + 1*fb3) / 2.1

lamb      = benzerlik_ortalama + fark_benzerlik_ortalama
yeni_token = 0.9 * token[-1] + lamb * fark_ortalama
```

Ağırlıklar en son farka en çok önem verecek biçimde seçildi; bölenler ağırlıkların toplamıdır ($0.5+0.6+0.7+1=2.8$, $0.5+0.6+1=2.1$). Öğrencinin anlattığına göre son satırdaki çarpımlı yapıyı bir sohbet botu önerdi; kendi ilk fikri farklıydı.

Hoca iki soru sordu. Birincisi: "Yapay zekânın dediğine inanmayıp kendi fikrinin peşinden gidip sonucu gördün mü?" Öğrenci zaman bulamadığını söyledi. İkincisi: üretilen "yeni token" bir kimlik numarası mı? Öğrenci, hesabın tamamen gömme vektörleri üzerinde yapıldığını, tahmin edilen vektörün token'a dönüştürülmeden modelin gerçek vektörüyle karşılaştırıldığını açıkladı.

Sonuçta tahmin edilen yörünge bazı örneklerde modelin yörüngesine çok benzedi, bazılarında bambaşka çıktı. Öğrenci ani kırılmaları, her token'ın bir kelime olmamasına (noktalama işaretleri, ekler) bağladı. Pencereyi Markov modelindeki koşullu olasılığa benzetti ve 5 yerine 10 vektörlük pencere ya da farklı katsayılar denemenin, ayrıca birkaç vektörü bir yapay sinir ağına verip sonrakini tahmin ettirmenin yeni sorular olduğunu söyledi.

Hoca, öğrencinin "ben farklı anlamışım" demesine şöyle cevap verdi: herkesin aynı şeyi anlaması beklenmiyordu; ödev böyle bir ödevdi.

### 9.2 Lyapunov üssü fikri

Bir öğrenci, yörüngeyi bir zaman serisi gibi düşünüp Lyapunov üssüyle analiz etmeyi önerdi. Öğrencinin yorumu: değer sıfıra yaklaşıyorsa sistem sürekli aynı kelimeleri üretiyor olabilir; GPT-2'nin farklı konularda bile aynı cümleleri tekrarladığını gözlemlemişti. Bu fikir denenmedi.

> **Ek bilgi (derste anlatılmadı):** Lyapunov üssü, dinamik bir sistemde başlangıçta çok yakın iki yörüngenin zamanla hangi hızda birbirinden uzaklaştığını ölçer. Pozitif değer başlangıç koşullarına duyarlı (kaotik) bir davranışı, negatif değer yörüngelerin birbirine yaklaştığı kararlı bir davranışı gösterir. Bir dil modelinde bu, büyük olasılıkla girdideki küçük bir değişikliğin üretimi ne kadar saptırdığını ölçmeye karşılık gelir.

### 9.3 Encoder ve decoder

Bir öğrenci beş model kullandı: Türkçe BERT, çok dilli BERT ve farklı büyüklükte ve ince ayar türünde GPT-2'ler. İki veri kümesini (GSM8K-TR ve bir haber kümesi) karşılaştırdı. Bulgular:

- İki veri kümesinde ortalama adım uzunluğu ve yön değişimi neredeyse aynıydı. Yalnız toplam yol uzunluğu farklıydı; haber metinleri daha uzundu.
- Decoder modellerde adımlar daha büyüktü. Öğrenci bunu decoder'ın her token'dan sonra yenisini tahmin etmesine, encoder'ın ise bütün token'ları aynı anda iki yönlü görmesine bağladı.

Hocanın yorumları:

- Uzun metinlerde toplam yol uzunluğunun daha uzun çıkması zaten bellidir; anlamlı bir bulgu değildir. Bunu görünce başka bir soruya geçmek gerekirdi (04:04:29 - 04:05:19).
- Adım uzunluğu farkını mimariye bağlamak kolay değildir; modellerin parametre sayıları ve temsilleri farklıdır (04:07:51 - 04:08:29).
- Sunumda Türkçe BERT modeli "Türkçeye ince ayar yapılmış" diye tanıtıldı; hoca bu modelin sıfırdan Türkçe veriyle eğitildiğini düzeltti (04:09:05 - 04:09:12). <!-- BELİRSİZ: altyazıda model adı "Türk İş BERT" diye geçiyor; büyük olasılıkla BERTurk. -->

Bir hipotez de en büyük adımların ve yön değişimlerinin hangi token'larda olduğunu incelemekti. Öğrenci, "artır" ya da "azalt" gibi sonucu değiştiren kelimelerde adımın ve yönün değiştiğini gözlemlediğini söyledi. Hoca örneklerden birinin mantıklı görünmediğini, ama adım uzunluğunun aynı çıktığını belirtti (04:06:13 - 04:06:23).

### 9.4 Kod verimliliği

Bir sunumda öğrencinin özellik kodu ile yapay zekânın yazdığı kod yan yana kondu. Öğrenci uzaklıkları iç içe döngülerle hesaplamıştı; yapay zekâ NumPy'ın `linalg.norm` ve nokta çarpımı gibi hazır, tensör üzerinde çalışan işlemlerini kullandı. Öğrencinin vurguladığı gibi iç içe döngüler donanımı paralel kullanamadığı için büyük zaman kaybına yol açar.

Başka bir sunumda öğrencinin seri çalışan kodu 4-4.5 saat sürdü; yapay zekâ kodu 8'lik toplu işleme (batch) ve 4-bit NormalFloat kuantizasyonu kullanarak 30-40 dakikada bitti. Kuantizasyon, toplu işlemenin artırdığı ekran kartı belleği kullanımını dengelemek için gerekiyordu.

## 10. Kendi Çözümü ve Yapay Zekâ Çözümü

Hoca hemen her sunumda iki soru sordu: "Bu özellikleri sen mi önerdin, yapay zekâ mı?" ve "Kodu sen mi yazdın?" Ödevin amacı iki çözümü ayrı ayrı yapıp karşılaştırmaktı. Sunumlarda görülen durumlar:

- Bazı gruplar iki çözümü ayırmamıştı; tek bir ortak çözüm sunuldu.
- Bazı sunumlarda yapay zekâ çözümü farklı model ya da farklı veri kümesi kullandı. Hoca "O zaman bunları nasıl karşılaştıracaksın?" diye sordu (00:24:57).
- Bir sunumda yapay zekâ çözümü öğrencinin tahmin etmediği başka sınıfları (ör. "dünya bilgisi mi akıl yürütme mi?") tahmin etti. Öğrenci "iki tahmini ben, iki tahmini o yapacak" diye anladığını söyledi. Hoca bu durumda hangi özellik kümesinin daha iyi olduğunun söylenemeyeceğini belirtti (04:40:10 - 04:40:29).
- Bir başka sunumda da veri kümeleri farklı olduğu için hoca "Yine elmalar ve armutlar durumu var" dedi (04:46:27).
- Bazı sunumlarda yapay zekâ özellikleri daha başarılı çıktı (Dolly'de kategori tahmini), bazılarında öğrencininkiler (istem türü tahmininde %90.3'e %66).

> **Hocanın vurgusu:** Karşılaştırma aynı yörüngeler, aynı modeller ve aynı tahmin hedefi üzerinde yapılmalıdır. Biri bir şeyi, öbürü başka bir şeyi tahmin ederse "bu ondan daha iyidir" denemez.

Hocanın sık sorduğu bir diğer şey, öğrencinin kendi yazdığı kodu açıklayabilmesiydi. Bir sunumda PCA kodundaki `trajectory.shape[0]` ve `shape[1]`'in ne olduğunu açıklayamayan öğrenciye hoca, bunun "destek almak" olmadığını söyledi.

## 11. Hocanın Yöntem Uyarıları

Sunumlar boyunca hocanın tekrar ettiği yöntem uyarıları şunlardır:

### 11.1 Her noktanın ve her özelliğin anlamı bilinmeli

Hoca neredeyse her grafikte "buradaki bir nokta neyi ifade ediyor?" diye sordu. Bir nokta bir token mı, bir yörünge mi, bir yörüngenin ortalaması mı? Bu belli olmadan grafik yorumlanamaz. Aynı biçimde her özellik için "nasıl hesaplanıyor, tek bir sayı mı?" sorusunun cevabı bilinmeli. Örneğin 768 boyutlu 50 noktadan "merkezden uzaklığın varyansı"nın nasıl tek bir sayıya dönüştüğünü bilmeyen bir sunucuya hoca, bildiklerini anlatarak devam etmesini söyledi.

Hoca, geometrik özelliklerden söz edilirken bir şekil koymanın zor olmadığını da belirtti (00:19:16).

### 11.2 Adım uzunluğu ile norm aynı şey değildir

Bir sunumda "step distance" vektörün kendi büyüklüğü diye anlatıldı. Hoca "Emin misin?" diye sordu ve öğrenci, ardışık iki nokta arasındaki mesafe olduğunu düzeltti (03:44:51 - 03:45:16). Adım uzunluğu $\lVert h_{t+1}-h_t\rVert$, norm ise $\lVert h_t\rVert$'dir.

### 11.3 Ortalama değil dağılım

Ortalama almak sıçramaları birbirine karıştırır (Bölüm 6.3). Ortalama bir eğri çizilecekse standart sapması da gösterilmelidir. Bir grubun bin yörüngenin her adımdaki ortalama hızını çizdiği grafikte hoca, bu ortalamanın standart sapmasının da konmasını istedi; grubun "sarsıntı" dediği standart sapma ise başka bir şeydi (yörünge içindeki hız değişimleri) (03:08:22 - 03:08:57).

### 11.4 Görselleştirme

- Bütün yörüngeleri tek grafiğe çizmek hiçbir şey göstermez. Her iki durumdan aynı 10 örneği seçip yan yana koymak daha anlaşılır olur (01:58:01 - 01:58:33).
- Karşılaştırılan iki modelin grafikleri yan yana konmalı.
- Neden PCA? Hoca, t-SNE ve UMAP gibi çok daha iyi boyut düşürme ve görselleştirme araçları olduğunu, bunların muhtemelen daha iyi şekiller vereceğini söyledi (02:34:39 - 02:35:14).
- İki benzer görünen yörüngenin neden bu kadar benzediğini anlamak için istemin ve üretilen metnin de yazılması gerekirdi (04:34:57 - 04:35:07).

> **Ek bilgi (derste anlatılmadı):** PCA doğrusal bir izdüşümdür; en çok varyansı koruyan eksenleri seçer ve uzak noktalar arasındaki büyük yapıyı korur. t-SNE ve UMAP doğrusal olmayan yöntemlerdir; yüksek boyuttaki komşulukları iki boyutta korumaya çalışırlar, bu yüzden kümeleri genelde daha belirgin gösterirler. Buna karşılık bu yöntemlerde kümeler arası uzaklıklar ve kümelerin büyüklükleri doğrudan yorumlanamaz.

### 11.5 Taban çizgisi ve sınıf dengesi

İki sınıflı bir görevde %50 şans düzeyidir; sekiz sınıflı dengeli bir görevde $1/8 = 12.5\%$ (Dolly sunumunda bu baseline açıkça kondu). Bir sınıfın örnek sayısı diğerlerinden çoksa o sınıfın yüksek doğruluğu bundan kaynaklanabilir (Bölüm 5.4).

### 11.6 Görev seçiminin gerekçesi

Hoca bir sunucuya görevlerin ne olduğunu değil, neden bu görevleri seçtiğini sordu (02:01:22). Bir başka sunucu, model kimliğinin ilk akla gelen görev olduğunu, kategoriyi de hocanın ödevi anlatırken söylediği örneklerden seçtiğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:04:20 - 00:07:42): Bir istemden yörünge nasıl elde edilir?

**Cevap (derste verildi):** İstem modele verilir. Model istemin ardından gelecek token'ı tahmin eder; bu sırada son katmanda son token için bir gizli durum vektörü oluşur. Üretilen token girdiye eklenir ve model bir sonrakini üretir. Bu işlem belirlenen sayıda (sunumların çoğunda 50 token) tekrarlanır. Her adımın gizli durumu sırayla dizildiğinde $T \times d$ boyutlu yörünge matrisi elde edilir; ör. Qwen2.5 0.5B'de 80 token için $80 \times 896$.

**Soru 2** (derste sözlü, 00:42:45 - 00:43:02; formül ekrandan, 00:42:15): Düzlük oranı $R = D/(L+\varepsilon)$ formülündeki $\varepsilon$ nedir, neden "kararlılık" için eklenir?

> **Çözüm (derste verilmedi):** $\varepsilon$ çok küçük pozitif bir sayıdır (ör. $10^{-8}$). Tek görevi sayısal kararlılıktır: toplam yol $L$ sıfır ya da sıfıra çok yakınsa (bütün adımlar boyunca temsil hiç değişmemişse) paydanın sıfır olmasını ve sonucun tanımsız ya da sonsuz çıkmasını önler. $L$ normal büyüklükteyken $R$'nin değerini fark edilir biçimde değiştirmez. $D \le L$ olduğu için (üçgen eşitsizliği) $R$ her zaman 0 ile 1 arasındadır; 1 düz bir çizgiyi gösterir.

**Soru 3** (derste sözlü, 00:51:14 - 00:52:08): Yalnız soru verilen yörüngeler kısa, soru ve bağlam verilen yörüngeler uzun olmaz mı?

**Cevap (derste verildi):** Hayır. Her iki koşulda da istemden sonra üretilen 50 token'ın yörüngesi alındı. İstemin uzunluğu yörüngenin uzunluğunu değil, yörüngenin hangi bağlamla başladığını değiştirir.

**Soru 4** (derste sözlü, 01:35:19 - 01:39:14; slayt ekrandan, 01:34:45): 50 token'lık bir yörüngeden kaç açı çıkar ve bu açılar nasıl özetlenmeli?

**Cevap (derste verildi):** 50 noktadan 49 adım vektörü, ardışık adım çiftlerinden de 48 açı çıkar. Sunumda bu 48 açının ortalaması alındı. Hoca, ortalamanın büyük ve küçük sıçramaları birbirine karıştırdığını, bunun yerine 48 değerin 5 ya da 10 kutulu bir histogramının alınmasını ve tahminin bu histogram üzerinden yapılmasını önerdi.

**Soru 5** (derste sözlü, 02:04:12 - 02:05:19): Bir yörünge 50 tane 768 boyutlu noktadan oluşuyor. "Merkezden uzaklıkların varyansı" nasıl tek bir sayı olarak hesaplanır?

> **Çözüm (derste verilmedi):** Önce yörüngenin ağırlık merkezi bulunur: $c = \frac{1}{50}\sum_{t=1}^{50} h_t$ (768 boyutlu bir vektör). Sonra her noktanın merkeze Öklid uzaklığı hesaplanır: $d_t = \lVert h_t - c \rVert$; bu 50 tane sayıdır. Son olarak bu 50 sayının varyansı alınır: $\frac{1}{50}\sum_t (d_t - \bar d)^2$. Sonuç her yörünge için tek bir sayıdır. Küçükse noktalar merkez etrafında bir küre kabuğu gibi eşit uzaklıkta, büyükse bazıları merkeze yakın bazıları uzaktadır. Derste sunan öğrenci bunu açıklayamadı.

**Soru 6** (derste sözlü, 02:06:10 - 02:06:46): Yörünge görselleştirmesinde "verinin en çok değiştiği iki yönü bulmak" ne demektir ve PCA neye uygulanır?

> **Çözüm (derste verilmedi):** PCA'ya uygulanan veri, her satırı bir nokta olan bir matristir. Tek bir yörüngede bu $50 \times d$ matrisidir; bütün yörüngeler birlikte çizilecekse bütün noktalar alt alta konur. Veriden ortalama çıkarılır, kovaryans matrisi hesaplanır ve özvektörleri bulunur. En büyük iki özdeğere ait özvektörler, noktaların en çok yayıldığı iki diktir yöndür. Her nokta bu iki yöne izdüşürülerek iki boyutlu bir koordinat elde edilir. Bir yörüngeye ayrı ayrı PCA uygulanırsa her yörünge kendi eksenlerinde çizilir ve yörüngeler aynı grafikte karşılaştırılamaz; bu yüzden ortak bir PCA'nın mı yoksa ayrı PCA'ların mı kullanıldığı belirtilmelidir. Hocanın sorusu tam bu ayrımı hedefliyordu.

**Soru 7** (derste sözlü, 03:44:09 - 03:45:16): "Step distance" nedir? Vektörün kendi büyüklüğü müdür?

**Cevap (derste verildi):** Hayır. Ardışık iki noktanın arasındaki mesafedir: $\lVert h_{t+1} - h_t \rVert$. Vektörün kendi büyüklüğü normdur ($\lVert h_t\rVert$) ve ayrı bir özelliktir.

**Soru 8** (derste sözlü, 02:30:24 - 02:31:14): Modelin ürettiği metin ile orijinal metin arasındaki yörünge farkının makalenin "zorluğu" ile ilişkisi nasıl ölçülür?

**Cevap (hocanın cevabı):** Göze bakarak "bu metin daha zor" demek özneldir. Her metnin o modele göre perpleksitesi hesaplanabilir. Perpleksite, metnin model için ne kadar beklenmedik olduğunu söyler. Sonra yörünge farkı ile perpleksite arasındaki uyum ölçülür.

**Soru 9** (derste sözlü, 03:19:48 - 03:21:31): Random Forest'a girdi olarak kaç özellik verildi?

**Cevap (derste verildi):** 50 token'lık yörüngede ardışık token'lar arası 49 uzaklık değeri hesaplandı ve her biri ayrı bir özellik olarak verildi; yani 49 özellik. Başka özellik kullanılmadı. Aynı sunumda yapay zekâ çözümü bu 49 uzaklığa 48 ardışık kosinüs değerini ekleyip 97 boyutlu bir vektör kullandı ($49 + 48 = 97$).

**Soru 10** (derste sözlü, 03:53:54 - 03:54:05): İstem uzunluğu tahmininde uzun istemler neden daha iyi (%85) tahmin edildi?

**Cevap (derste verildi):** Uzun sınıfta 304 örnek vardı. Hoca örnek sayısının büyük etkisi olduğunu, sınıflandırıcının hepsine "uzun" dese bile bu sınıfta yüksek doğruluk alacağını söyledi. Sınıf dengesi kontrol edilmeden sınıf bazlı doğruluk yorumlanmamalıdır.

**Soru 11** (derste sözlü, 04:40:10 - 04:40:29): Öğrencinin özellikleri bir şeyi, yapay zekânın özellikleri başka bir şeyi tahmin ediyorsa hangi özellik kümesinin daha iyi olduğu söylenebilir mi?

**Cevap (derste verildi):** Hayır. Karşılaştırma ancak aynı modeller, aynı yörüngeler ve aynı tahmin hedefi üzerinde yapılabilir.

## Dersin Toparlaması

Bu derste ikinci ödevin sunumları yapıldı. Ödev, dil modelinin metin üretirken ardışık adımlarda oluşturduğu gizli durumları bir yörünge olarak ele alıyor ve bu yörüngenin şeklinden özellik çıkarmayı istiyordu. Sunumlarda en sık kullanılan özellikler adım uzunlukları, toplam yol, net yer değiştirme ve düzlük oranı, ardışık açılar ve eğrilik, normlar, PCA tabanlı yayılım ölçüleri ve histogramlardı. Bütün sunumlarda ortak sonuç aynıydı: yörünge, hangi modelin ürettiğini neredeyse kusursuz ele veriyor; ama istemin konusu ya da kategorisi hakkında çok daha az bilgi taşıyor. Kategori tahmininde karışıklıklar anlamca komşu sınıflara düştü.

Hocanın asıl katkısı yöntem üzerineydi: bir özelliğin nasıl hesaplandığını ve bir grafikteki noktanın neyi temsil ettiğini bilmek; karşılaştırmayı aynı yörüngeler, aynı model ve aynı hedef üzerinde yapmak; ortalama yerine dağılıma (histogram, standart sapma) bakmak; daha iyi görselleştirme araçları kullanmak; "zor" gibi öznel yargıları perpleksite gibi ölçülerle sayısallaştırmak; şans düzeyini ve sınıf dengesini göz önünde tutmak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
