# Ders 12 Çalışma Özeti

## Genel Konular

- Hiyerarşik kümeleme
  - Hiyerarşik kümeleme, örnekleri ağaç benzeri bir yapı içinde birleştirerek veya bölerek gruplar.
  - Sonuç dendrogram ile görselleştirilebilir.
- Agglomerative ve divisive yaklaşımlar
  - Agglomerative yöntem bottom-up çalışır; her örnek başlangıçta tek başına kümedir ve benzer kümeler adım adım birleştirilir.
  - Divisive yöntem top-down çalışır; tüm örnekler tek kümede başlar ve giderek alt kümelere ayrılır.
- Linkage yöntemleri
  - Single linkage, kümeler arasındaki en yakın iki noktanın mesafesini kullanır.
  - Complete linkage, en uzak iki noktanın mesafesini kullanır.
  - Average linkage, kümeler arası tüm nokta çiftlerinin ortalama uzaklığına dayanır.
- Küme uzaklığı ölçüleri
  - Minimum, maximum, mean ve average distance gibi farklı küme uzaklığı tanımları anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Agglomerative yaklaşımın daha sezgisel olması
  - Tekil örneklerden başlayıp benzerleri birleştirmek, divisive bölmeye göre daha kolay kurgulanır.
- Dendrogramın sadece çizim değil karar aracı olması
  - Hangi seviyede kesileceği, kaç küme elde edileceğini belirler.
- Küme-küme uzaklığı ile örnek-örnek uzaklığının farklılığı
  - Hiyerarşik yöntemde artık tek örneklerin değil, birden çok örnek içeren kümelerin arası ölçülür.

## Kısa Tekrar Notları

- Hiyerarşik kümeleme dendrogram üretir.
- Agglomerative: aşağıdan yukarıya birleştirme.
- Divisive: yukarıdan aşağıya bölme.
- Single linkage en yakın çift, complete linkage en uzak çift, average linkage ortalama uzaklık kullanır.
- Durma koşulu küme sayısı veya mesafe eşiği olabilir.

## Detaylı Açıklamalar

- Derste hiyerarşik kümeleme, K-means gibi doğrudan sabit sayıda küme üretmek yerine, verinin farklı ayrıntı seviyelerindeki gruplanmasını gösteren bir yöntem olarak anlatılır. Bu yapı, küme ilişkilerini görsel ve yorumlanabilir hale getirir.
- Agglomerative yöntemde başlangıçta her örnek atomik bir kümedir. En benzer iki küme birleştirilir ve bu işlem tekrarlandıkça daha büyük kümeler oluşur. Tüm örnekler tek kümede toplanana kadar süreç sürdürülebilir; ancak pratikte belirli sayıda küme kalınca veya mesafe eşiği aşılınca durulur.
- Divisive yöntem ters yönde çalışır. Başlangıçta tüm veri tek kümedir ve sonra alt gruplara ayrılır. Bu yaklaşım teorik olarak anlamlı olsa da hangi ayrımın yapılacağını belirlemek daha zor olduğu için agglomerative yaklaşım daha uygulanabilir görülür.
- Linkage seçimi sonuç üzerinde doğrudan etkilidir. Single linkage zincirleme etki yaratabilir; complete linkage daha sıkı kümeler üretme eğilimindedir; average linkage iki uç yaklaşım arasında denge sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
