# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin yapısı: ikinci ödevin sunumları
  - Ders tümüyle öğrencilerin ikinci ödev sunumlarına ayrıldı. Hoca yeni konu anlatmadı; sunumlar sırasında sorular sordu, yöntem hatalarını gösterdi ve öneriler verdi.
  - Ödevin konusu: bir dil modelinin metin üretirken ardışık token'larda oluşturduğu gizli durum (hidden state) temsillerinin dizisi, yani "yörünge". Bu yörüngenin şeklinden hangi özellikler çıkarılabilir, bu özelliklerle neler tahmin edilebilir?
  - Ödevde problem iki yoldan çözülüyordu: öğrencinin kendi önerdiği özellikler ve bir yapay zekâ aracına (ChatGPT, Gemini, Claude vb.) çözdürülen özellikler. İki çözüm karşılaştırılıyordu.
- Yörüngenin elde edilmesi
  - Modele bir istem (prompt) verilir; model token token üretir. Her adımda son katmandaki son token'ın gizli durum vektörü saklanır. Sunumların çoğunda 50 yeni token üretildi.
  - Sonuç, her istem için $50 \times d$ boyutlu bir matristir ($d$: modelin gizli boyutu; ör. GPT-2 için 768, GPT-2 Medium ve Qwen3-0.6B için 1024, Qwen2.5-0.5B için 896, Qwen3-4B için 2560).
  - Sunumların çoğu iki model ve yaklaşık 1000 istem kullandı; böylece 2000 civarı yörünge oluştu.
- Yörüngeden çıkarılan özellik aileleri (sunumlarda en sık geçenler)
  - Adım (step) özellikleri: ardışık iki nokta arasındaki Öklid uzaklığı $\lVert h_{t+1}-h_t\rVert$; bunların ortalaması, standart sapması, en büyüğü, en küçüğü.
  - Toplam yol uzunluğu: $L=\sum_t \lVert h_{t+1}-h_t\rVert$.
  - Net yer değiştirme: $D=\lVert h_{50}-h_1\rVert$; düzlük (straightness/efficiency) oranı $R = D/(L+\varepsilon)$ (ekrandan, 00:42:15).
  - Açı özellikleri: ardışık adım vektörleri $\vec{AB}$ ve $\vec{BC}$ arasındaki açı; $\cos\theta = \dfrac{\vec{AB}\cdot\vec{BC}}{\lVert\vec{AB}\rVert\,\lVert\vec{BC}\rVert}$ (ekrandan, 01:34:45). 50 token'lık yörüngede 48 açı çıkar.
  - Eğrilik (curvature): ardışık adım vektörleri için $1-\cos\theta$; düz gidişte 0, dik dönüşte 1, tam geri dönüşte 2.
  - Norm özellikleri: gizli durum vektörlerinin kendi büyüklükleri ve bunların değişkenliği.
  - PCA tabanlı özellikler: açıklanan varyans oranları; toplam varyansın %90'ını açıklamak için gereken bileşen sayısı ("etkin boyut"); iki boyutlu izdüşümün kapladığı alan, dışbükey zarf alanı, yayılım.
  - Histogram özellikleri: adım uzunluklarının ve açıların histogramları.
- Tahmin görevleri
  - Model kimliği: yörüngeyi hangi model üretti?
  - İçerik: istemin konusu ya da kategorisi (spor/teknoloji, Dolly kategorileri, haber türleri), istemin dili (Türkçe/İngilizce), istem uzunluğu, bağlam (context) verilip verilmediği, örnekleme ayarı (deterministik/yaratıcı), yorum puanı (hız/lezzet iyi-kötü).
  - Sınıflandırıcılar: lojistik regresyon, Random Forest, LightGBM, XGBoost.
- Ortak bulgu
  - Model kimliği hemen bütün sunumlarda %95-100 doğrulukla tahmin edildi. Yörünge, modelin bir "parmak izi" gibi davranıyor; farklı modellerin gizli uzaylarının ölçeği ve normları zaten çok farklı.
  - Konu ya da kategori tahmini çok daha zayıf kaldı: iki sınıfta %50-70, sekiz sınıfta %30-53 civarı. Yalnız adım ve açı büyüklüğüne bakan geometrik özellikler anlamsal içeriği yeterince taşımıyor.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yöntemini anlatabilmek
  - Hoca neredeyse her sunumda "bu özellik nasıl hesaplanıyor?", "girdi ne?", "her nokta neyi ifade ediyor?" diye sordu. Bir özelliğin tanımını ve hesaplanışını bilmeden sonucu yorumlamak mümkün değildir.
  - Geometrik bir özellikten söz ederken bir şekille göstermek gerektiğini söyledi.
- Karşılaştırma aynı koşullarda yapılmalı
  - Öğrencinin çözümü ile yapay zekâ çözümü karşılaştırılacaksa aynı yörüngeler, aynı model ve aynı veri kümesi kullanılmalı. Yörüngeler bir kez üretilir, iki çözümün özellikleri bu aynı yörüngelerden çıkarılır.
  - Farklı veri, farklı model ya da farklı hedef sınıf kullanan iki çözüm için "hangisi daha iyi" denemez ("elmalarla armutlar").
- Ortalama almak sinyali yok eder
  - 48 açının ya da adım uzunluklarının yalnız ortalamasını almak yerine, örneğin 5-10 kutulu bir histogram kullanılmalı. Bir yöne ve öbür yöne yapılan büyük sıçramalar ortalamada birbirini götürür.
  - Ortalama bir eğri çizilirken standart sapma da gösterilmeli.
- Görselleştirme
  - Binlerce yörüngeyi aynı grafiğe çizmek hiçbir şey göstermez; az sayıda örnek seçilmeli ve karşılaştırılacak iki durum yan yana konmalı.
  - Görselleştirmede PCA yerine t-SNE ya da UMAP gibi araçlar daha iyi şekiller verir. Kümeleme için önce PCA yapmak gerekmez.
- Sonucu sayısallaştırmak
  - "Bu metin daha zor" gibi göze dayalı yargılar yerine, metnin o modele göre perpleksitesi hesaplanıp yörünge farkıyla ilişkisi ölçülebilir.
- Sınıf dengesi ve taban çizgisi
  - İki sınıflı bir görevde %50 şans düzeyidir; sekiz sınıflı dengeli bir görevde %12.5. Bir sınıf çok kalabalıksa o sınıfın yüksek doğruluğu bundan kaynaklanabilir.
- Bariz sonuçlar için zaman harcamamak
  - Uzun metinlerin yörüngesinin daha uzun olması beklenen bir sonuçtur; bunu bulunca başka bir soruya geçmek gerekir.

## Kısa Tekrar Notları

- Yörünge = üretim sırasında her adımdaki son token gizli durumlarının sırası; boyutu $T \times d$.
- Adım uzunluğu ardışık iki nokta arasındaki uzaklıktır, vektörün kendi normu değildir.
- Toplam yol $L$, net yer değiştirme $D$, düzlük $D/L$; $\varepsilon$ yalnız sıfıra bölmeyi önler.
- 50 noktalı bir yörüngede 49 adım ve 48 ardışık açı vardır.
- Model kimliği kolay, konu/kategori zor: geometri modelin mimarisini taşır, anlamı az taşır.
- Karışan kategoriler anlamca komşu olanlardı (summarization ile closed_qa, open_qa ile general_qa).
- Sıcaklık (temperature) yükselince yörünge daha fazla boyuta yayıldı ve yön değişimi arttı, ama fark küçüktü.
- Bağlam verilen istemlerde yörünge daha toplu, bağlamsız olanlarda daha sıçramalı göründü.
- Ortalama yerine histogram; ortalamanın yanında standart sapma.
- Aynı yörünge, aynı model, aynı veri üzerinde karşılaştırma.

## Detaylı Açıklamalar

- Yörünge kavramı
  - Model bir istemi okuduktan sonra bir token üretir. Bu üretimden hemen önce son katmanda kalan temsil, o adımın gizli durumudur. Üretilen token girdiye eklenir, model bir sonraki token'ı üretir ve yeni bir gizli durum oluşur. 50 adımın gizli durumları sırayla dizildiğinde yüksek boyutlu uzayda bir yol, yani yörünge ortaya çıkar.
  - Bir sunumda tek tek token vektörleri incelendiğinde ardışık token'larda aynı indislerde benzer tepeler görüldü (ekrandan, 02:13:30). Hoca bunun "bağlam" denen şey olduğunu, temsilin bir adımda bir yerden bambaşka bir yere zıplamadığını söyledi.
  - Bir sunum, metni modele kendi ürettirmek yerine gerçek metnin 51-100. kelimelerini okuturken oluşan gizli durumları da "orijinal yörünge" olarak aldı ve modelin kendi ürettiği yörüngeyle karşılaştırdı. GPT-2'de makale bazında fark belirgin çıktı; Qwen'de ayırt edici bir fark çıkmadı (ekrandan, 02:29:45).
- Model kimliği neden kolay?
  - Farklı modellerin gizli boyutları, normları ve adım büyüklükleri baştan farklıdır. Bir sunumda tek bir norm özelliğiyle (en küçük norm) %99.88 doğruluk elde edildi. Bir başka sunumda iki model arasında adım uzunluğu ölçeği 120'ye karşı 200 civarındaydı.
  - Bir sunumda iki modelin gizli boyutu farklıydı ve vektörler doğrusal ara değerlemeyle (linear interpolation) 1024'e indirildi. Bir başka sunumda yapay zekâ aracı, model tahmininde boyut farkının "sızıntı" yaratmaması için aynı gizli boyuta sahip iki model seçmeyi önerdi (Llama 3.2 1B ve SmolLM2 1.7B, ikisi de 2048).
- Kategori tahmini neden zor?
  - Adım ve açı büyüklükleri metnin ne hakkında olduğunu değil, modelin nasıl ilerlediğini anlatır. Derin öğrenme ve futbol hakkında üretilen metinlerde benzer adımlar ve benzer zikzaklar oluşabilir.
  - Sekiz Dolly kategorisinde öğrencinin 29 özelliği %30 civarında kalırken yapay zekânın yaklaşık 990 özellikli kümesi LR ve LightGBM ile %52-53'e çıktı (ekrandan, 01:48:15). Karışan sınıflar anlamca yakın olanlardı: summarization ↔ closed_qa ~%26, information_extraction → closed_qa/summarization ~%22, open_qa ↔ general_qa ~%22, brainstorming → creative_writing ~%14 (ekrandan, 01:51:15).
- Örnekleme ayarının etkisi (deterministik ve yaratıcı)
  - Bir sunumda aynı model (Qwen3 4B) bir kez açgözlü (greedy) çözümle, bir kez yüksek sıcaklıkla çalıştırıldı ve iki "karakter" gibi ele alındı.
  - Etkin boyut: yörüngedeki 50 noktaya PCA uygulanıp toplam varyansın %90'ını açıklayan bileşen sayısı sayıldı (ekrandan, 01:32:10). 1000 örneğin 504'ünde yaratıcı mod daha çok boyut kullandı, 281'inde deterministik mod, 215'inde eşit çıktı. Ortalamalar yakındı (yaklaşık 29'a 28).
  - Yön değişimi: 48 ardışık açının ortalaması yaratıcı modda biraz daha yüksek çıktı.
  - Hoca iki öneri yaptı: sıcaklığı kademeli artırıp geçişi gözlemek ve ortalama yerine açıların histogramını kullanmak.
  - Sunan öğrencinin gözlemi: sıcaklığın etkisi her adımda doğrudan değil, birikerek görülür; çünkü farklı seçilen ilk token'lar sonraki adımların bağlamını değiştirir.
- Bağlamın etkisi
  - Bir sunumda SQuAD sorularında soru tek başına ve soru + bağlam paragrafı ile verildi; her iki durumda da sonraki 50 token'ın yörüngesi alındı. Her adımda bin yörüngenin ortalaması çizildiğinde bağlamlı yörüngeler daha toplu, bağlamsızlar daha sıçramalı göründü (ekrandan, 00:59:10). Hoca ortalama yörüngenin ne anlama geldiğini sorguladı.
- Yörünge özelliği olarak hız ve "sarsıntı"
  - Bir yapay zekâ önerisi, ardışık token'lar arası uzaklığı birim zamanda alınan yol, yani hız saydı; "sarsıntı" (jerk) da hızdaki değişimlerin standart sapmasıydı (ekrandan, 03:07:00). Hoca, bin yörüngenin her adımdaki ortalamasının yanında bu ortalamanın standart sapmasının da gösterilmesini istedi.
- Yörüngeler arası benzerlik
  - Bir grup her yörüngeyi 50 adımın ortalamasıyla (mean pooling) tek bir 1024 boyutlu vektöre indirdi, 1000 × 1000 kosinüs benzerlik matrisini çıkardı ve bu matrisin satırlarını sınıflandırıcıya verdi (ekrandan, 02:56:30). Qwen ile OPT'nin aynı sorulara çizdiği yörüngelerin ortalama benzerliği %2.94'tü. Qwen'de yaratıcı yazım kendi içinde %41.03, genel bilgi %40.76, ikisi arası %39.32; OPT'de sırasıyla %62.92, %58.70, %59.94. BLOOMZ'de bütün yörüngeler neredeyse aynı noktaya düştü ("temsil çökmesi").
  - Hoca, ortalamayla bir yörüngenin tek noktaya indirildiğini, bunun artık yörüngenin şeklini değil konumunu kullandığını sorularıyla açığa çıkardı.
- Kod verimliliği
  - Bir sunumda öğrencinin iç içe döngülerle yazdığı uzaklık hesabı ile yapay zekânın NumPy/tensör işlemleriyle (`np.linalg.norm`, nokta çarpımı) yazdığı kod karşılaştırıldı. Vektörleştirilmiş kod donanımı paralel kullandığı için çok daha hızlıydı. Toplu işleme (batch) ve 4-bit kuantizasyon da çalışma süresini 4-4.5 saatten 30-40 dakikaya indirdi.
- Encoder ve decoder karşılaştırması
  - Bir sunumda BERT tabanlı modeller ile GPT-2 modelleri karşılaştırıldı; decoder'larda adımlar daha büyük çıktı. Hoca, modellerin parametre sayıları ve temsil ölçekleri farklıyken adım uzunluğu farkının mimariye bağlanmasından emin olmadığını söyledi. Sunumdaki Türkçe BERT modeli "Türkçeye ince ayar yapılmış" diye tanıtılmıştı; hoca bu modelin ince ayarla değil, sıfırdan Türkçe veriyle eğitildiğini düzeltti. <!-- BELİRSİZ: altyazıda model adı "Türk İş BERT" diye geçiyor; büyük olasılıkla BERTurk. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
