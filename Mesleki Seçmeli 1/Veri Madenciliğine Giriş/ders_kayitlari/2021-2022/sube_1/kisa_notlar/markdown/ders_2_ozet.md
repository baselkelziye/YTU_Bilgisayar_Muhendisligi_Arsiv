# Ders 2 Çalışma Özeti

## Genel Konular

- Doküman verisi ve terim vektörü
  - Her doküman tek bir satır olarak tutulur; sütunlar terimlerdir ve hücrede o terimin dokümanda kaç kez geçtiği yazılır (terim vektörü).
  - Kelime sayısı çok olduğu için sütun (attribute) sayısı çok büyür. Bu yüzden bir eşik (threshold) belirlenir; örneğin eşik 3 ise bin dokümanda toplam 3'ten az geçen kelimeler atılır.
- Transaction (işlem) verisi
  - Market alışverişi, banka işlemleri gibi kayıtlardır. Her transaction bir müşteriyi değil, bir işlemi gösterir; aynı müşteri art arda birkaç transaction yapmış olabilir.
  - Genellikle market sepeti analizinde (hangi ürünler birlikte satılır) kullanılır; bu konu ileride birliktelik analizinde (association analysis) görülecektir.
- Transaction verisinin kayıt (record) verisine çevrilmesi
  - Slayttaki örnek (ekrandan, 00:05:00): TID 1: Bread, Coke, Milk; TID 2: Beer, Bread; TID 3: Beer, Coke, Diaper, Milk; TID 4: Beer, Bread, Diaper, Milk; TID 5: Coke, Diaper, Milk.
  - Kayıt verisinde her ürün bir sütundur (Bread?, Coke?, Milk?, Diaper?, Beer?); ürün varsa 1, yoksa 0 yazılır. Bunlar asimetrik niteliklerdir.
  - Liste biçimi az yer, 0/1 tablo biçimi çok yer kaplar. Gerçek veride yüzlerce ya da binlerce sütun olur, bir işlemde alınan ürün sayısı (ör. 5) sütun sayısına göre çok küçüktür; matrisin çoğu 0 olur ve buna seyrek matris (sparse matrix) denir.
  - Hoca bunu grafların komşuluk matrisi ve komşuluk listesi gösterimine benzetti.
- Verinin temel istatistiksel tanımları
  - İstatistikler, veriyi hiç tanımayan veri bilimciye veri hakkında ön bilgi verir: dağılımı, verideki değişiklikleri (ör. paradan sıfır atılması, saat uygulaması gibi kolon değerlerinin bir anda değişmesi) fark ettirir.
  - Bütün bu ölçüler tek bir attribute (tek bir kolon) için hesaplanır.
  - Merkezi eğilim (central tendency): mean, median, mode, midrange.
  - Yayılım (dispersion): range, çeyrekler (quartiles), IQR, varyans, standart sapma.
- Merkezi eğilim ölçüleri
  - Aritmetik ortalama: $\bar{x} = \frac{1}{n}\sum_{i=1}^{n} x_i$.
  - Ağırlıklı ortalama: $\bar{x} = \frac{\sum_{i=1}^{n} w_i x_i}{\sum_{i=1}^{n} w_i}$; değerin önemi başka bir şeye (ör. dersin AKTS'sine) bağlıysa kullanılır.
  - Kırpılmış ortalama (trimmed mean): uç değerler kesilip atıldıktan sonra alınan ortalamadır; ortalama uç değerlere (outlier) çok duyarlı olduğu için kullanılır (ekrandan, 00:10:00).
  - Medyan: veri sıralanır, ortadaki değer alınır; eleman sayısı çiftse ortadaki iki değerin ortalaması alınır. Sayısal veriye ve sıralı (ordinal) kategorik veriye uygulanabilir.
  - Mod: en sık geçen değerdir. Her değer bir kez geçiyorsa mod yoktur. Bir, iki, üç modlu veriler unimodal, bimodal, trimodal diye adlandırılır (ekrandan, 00:15:00).
  - Hangi ölçü hangi nitelik için: sayısal → mean, median, mode; nominal → mode; ordinal → mode, median (ekrandan, 00:15:00).
- Simetrik ve çarpık dağılımlar
  - Simetrik dağılımda mean, median ve mode aynı ya da çok yakındır.
  - Zor sınav örneği (çoğu düşük not, sağda az sayıda yüksek not): mode < median < mean.
  - Kolay sınav örneği (çoğu yüksek not, solda birkaç düşük not): mean < median < mode.
- Yayılım ölçüleri (ekrandan, 00:25:00)
  - Range = maksimum − minimum.
  - Çeyrekler: Q1 (25. yüzdelik), Q2 = medyan, Q3 (75. yüzdelik). IQR = Q3 − Q1, ortadaki %50'nin aralığıdır.
  - Beş sayı özeti (five number summary): Minimum, Q1, Median, Q3, Maximum.
  - Varyans: $\sigma^2 = \frac{1}{n}\sum_{i=1}^{n}(x_i-\mu)^2$ (popülasyon), $s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(x_i-\mu)^2$ (örneklem). Standart sapma varyansın karekökü.
  - Aykırı değer (outlier): $Q1 - 1.5\cdot IQR$ altında ya da $Q3 + 1.5\cdot IQR$ üstünde kalan değerler.
- Kutu grafiği (boxplot) (ekrandan, 00:30:00)
  - Kutunun uçları Q1 ve Q3'tür, kutu boyu IQR'dir; kutu içindeki çizgi medyandır.
  - Kutudan çıkan iki çizgi aykırı değerler hariç en küçük ve en büyük gözleme (lower/upper extreme) uzanır; aykırı değerler ayrıca nokta olarak gösterilir. Aykırı değer yoksa uçlar minimum ve maksimumdur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Transaction verisi neden liste biçiminde tutulur
  - 0/1 tablo hızlı erişim sağlar ama çok yer kaplar; liste satır satır okunduğu için daha yavaştır. Model bir kez eğitildiğinden hız çok kritik değildir, asıl sorun verinin belleğe sığmamasıdır; bu yüzden liste tercih edilir.
- Ortalama uç değerlere duyarlıdır
  - Aykırı değerler çıkarılıp ortalama alınabilir (trimmed mean). Aykırı değerler istatistiksel olarak IQR ile belirlenebilir.
- Medyanın ordinal veride anlamı
  - Örneğin kahve boyları (küçük, orta, büyük) sıralanıp medyana bakılırsa "alanların yarısı orta ve daha küçük almış" gibi bir bilgi elde edilir; mod bu bilgiyi vermez.
- Mod hesabı
  - $O(n^2)$ ile her eleman için sayarak ya da $O(n \log n)$ ile sıralayıp sıralı dizi üzerinden bir kez geçerek bulunur.
  - Her şey bir kez geçiyorsa "mod yoktur" denir, "hepsidir" denmez.
  - Ders sonrası not: hoca, 5 kez geçen üç değer olduğunda "modu yine 5'tir" dedi; 5 burada en yüksek frekanstır, mod ise 5 kez geçen üç değerin kendisidir (trimodal).
- Q1 ve Q3'ü bulurken önce medyan bulunur
  - Önce medyan bulunur, veri medyandan iki yarıya bölünür, her yarının medyanı Q1 ve Q3'ü verir. Hoca örnekte veriyi doğrudan dört eşit parçaya bölerek hata yaptığını söyledi ve bu hatanın yapılmamasını istedi.
- Her dağılımın kendi standart sapması vardır
  - "Standart" sapma tek bir sabit değer değildir; her dağılım için ayrı hesaplanır.

## Kısa Tekrar Notları

- Doküman verisi: satır = doküman, sütun = terim, hücre = geçme sayısı; az geçen terimler eşikle atılır.
- Transaction verisi 0/1 tabloya çevrilebilir ama tablo seyrek ve büyük olur; liste biçimi az yer kaplar.
- Merkezi eğilim: mean, weighted mean, trimmed mean, median, mode, midrange.
- Çift sayıda elemanda medyan = ortadaki iki elemanın ortalaması.
- Mod: en sık değer; hepsi bir kez geçiyorsa mod yok; unimodal, bimodal, trimodal.
- Nominal → mode; ordinal → mode, median; sayısal → mean, median, mode.
- Simetrik: mean ≈ median ≈ mode. Sağa çarpık (zor sınav): mode < median < mean. Sola çarpık (kolay sınav): mean < median < mode.
- Range = max − min; IQR = Q3 − Q1; beş sayı özeti: min, Q1, median, Q3, max.
- Varyans: popülasyonda $n$'ye, örneklemde $n-1$'e bölünür; standart sapma karekökü.
- Aykırı değer: $Q3 + 1.5\cdot IQR$ üstü ya da $Q1 - 1.5\cdot IQR$ altı.
- Boxplot: kutu Q1–Q3, içteki çizgi medyan, bıyıklar aykırılar hariç en küçük ve en büyük değer, aykırılar nokta.
- Tüm değerleri aynı olan verinin standart sapması 0'dır (ör. {1,1,1,1}).

## Detaylı Açıklamalar

- **Doküman ve transaction verisi.** Doküman verisinde her doküman bir satırdır ve her terimin kaç kez geçtiği sayılır; bu satıra terim vektörü denir. Terim sayısı çok büyük olduğu için çok nadir geçen terimler bir eşik değeriyle atılır, böylece veri gereksiz yere büyütülmez. Transaction verisinde ise her satır bir işlemdir ve o işlemde alınan ürünler listelenir. Bu veri, ürün başına bir sütun açılıp 1/0 yazılarak kayıt verisine çevrilebilir (ekrandan, 00:05:00). Ancak gerçek uygulamalarda ürün sayısı yüzler ya da binlerle ifade edilirken bir sepette birkaç ürün bulunur; ortaya çoğu 0 olan bir seyrek matris çıkar. Hoca bunu graflardaki komşuluk matrisi ile komşuluk listesi seçimine benzetti: graf çok yoğunsa (ör. tam graf) iki gösterim aynı boyuta yaklaşır, seyrekse liste çok daha az yer kaplar. Listeyle bir elemana erişmek daha yavaştır, fakat model bir kez eğitildiği için hızdan çok bellek önemlidir.
- **İstatistiksel tanımların amacı.** Veri madenciliğine başlamadan önce verinin genel yapısını anlamak gerekir. Veriyi toplayan kişi (bankacı, meteoroloji mühendisi vb.) veriye farklı gözle bakar; veri bilimci için ortalama, medyan, çeyrekler gibi ölçüler verinin nasıl dağıldığını ve zaman içinde nasıl değiştiğini gösterir. Örneğin uzun süre toplanmış bir parasal veride paradan sıfır atılması ya da saat verisinde ileri/geri saat uygulaması, kolon değerlerinde ani bir kırılma yaratır.
- **Merkezi eğilim örneği (ekrandan, 00:20:00).**
  - attr1 = {2,4,4,6,8,24}: toplam 48, mean = 48/6 = 8; eleman sayısı çift olduğu için medyan = (4+6)/2 = 5; mod = 4.
  - attr2 = {2,4,7,10,12}: mean = 35/5 = 7; medyan = 7; her değer bir kez geçtiği için mod yoktur.
  - attr3 = {xs,s,s,s,m,m,l}: ordinal veri olduğu için mean hesaplanamaz; sıralı 7 elemanın ortası s olduğundan medyan = s; en çok geçen s olduğundan mod = s. Eleman sayısı çift olsaydı ortadaki iki değerin ortalaması alınamayacağı için bazı araçlar "medyan yok" der, bazıları ortadaki iki değer aynıysa o değeri verir.
- **Yayılım örneği (ekrandan, 00:35:00).** attr1 = {2,3,4,5,6,7,8,9} ve attr2 = {1,5,9,10,11,12,18,30}. Hesaplamadan hangisinin standart sapmasının büyük olduğu sorulduğunda cevap attr2'dir: attr1 birer birer artarken attr2'deki 30 ortalamadan çok uzaktır. Çeyrekler: attr1 için Q1 = (3+4)/2 = 3.5, Q3 = (7+8)/2 = 7.5, IQR = 4; attr2 için Q1 = (5+9)/2 = 7, Q3 = (12+18)/2 = 15, IQR = 8. Aykırı değer için $15 + 1.5\cdot 8 = 27$ sınırına bakılır; 30 > 27 olduğundan 30 aykırı değerdir. Standart sapması sıfır olan 4 elemanlı veri kümesi örneği {1,1,1,1}'dir; bütün değerler ortalamaya eşit olduğu için sapma yoktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
