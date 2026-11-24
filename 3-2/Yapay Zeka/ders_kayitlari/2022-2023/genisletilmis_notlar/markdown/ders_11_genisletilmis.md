# Ders 11 Genişletilmiş Notu: Makine Öğrenmesi 2: Özellik Seçimi ve Çıkarımı, Karar Ağaçları ve En Yakın K Komşu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Genel Veri Kümesi Yapısı: Sınıflandırma mı, Regresyon mu?
- 2. Özellik Belirleme: Neden Gerekli?
- 3. Filter Yöntemleri I: Entropi ve Bilgi Kazancı
- 4. Filter Yöntemleri II: Sinyalin Gürültüye Oranı
- 5. Filter Yöntemlerinin Sınırı
- 6. Wrapper Yöntemleri: Özellik Alt Kümesi Seçiciler
- 7. Yeni Özelliklerin Çıkarımı: PCA ve LDA
- 8. Hangi Yöntem? Bedava Öğle Yemeği Yok Teoremi
- 9. Doğrusal Sınıflandırıcı
- 10. Karar Ağaçları
- 11. Evrensel Yaklaşıklayıcılar ve Saflık Ölçütü
- 12. Yapay Sinir Ağlarına Kısa Bakış
- 13. Parametre ve Hiperparametre
- 14. En Yakın K Komşu
- Örnek Sorular

## 1. Genel Veri Kümesi Yapısı: Sınıflandırma mı, Regresyon mu?

Bu ders makine öğrenmesinin ikinci bölümüdür. Hoca derse, önceki derste de görülen genel veri kümesi tablosunu hatırlatarak başladı (ekrandan, 00:10:00). Gözetimli (supervised) algoritmalar, "şu örneğin çıktısı şudur" diye bizim söylediğimiz algoritmalardır ve bütün veri kümeleri aynı biçime çevrilir: satırlarda örnekler, sütunlarda özellikler (öz1, öz2, ..., öz d) ve en sonda çıkış vardır. $d$ özellik ve $N$ örnek varsa, $N$ örneğin her biri $d$ boyutlu uzayda bir noktadır.

Çıkışın tipine göre problem ikiye ayrılır: çıkış kategorik ise **sınıflandırma**, sayısal ise **regresyon**. Hoca sınıfa "kategorik ne demekti?" diye sordu. Öğrencilerden "sayısal olmayan değer" ve "sürekli değil" cevapları geldi. Hocanın vurguladığı temel nokta şuydu: kategorik değişkenin değerleri arasında **büyüklük-küçüklük ilişkisi yoktur**. Sayılar ise tam da aralarında bu ilişkiyi tanımladığımız şeylerdir.

> **Hocanın vurgusu:** Bir problemin sınıflandırma mı regresyon mu olduğuna etiketlerin isimlerine bakarak karar verilmez. Çıkış değerleri arasında anlamlı bir büyüklük-küçüklük ilişkisi kurulup kurulamayacağı düşünülmelidir.

Hoca bunu iki yönden örnekledi:

- **İsim gibi görünen ama sıralı olan çıkış:** Eğitim durumu (ilkokul, ortaokul, lise, üniversite mezunu) görünüşte isimdir. Ama aralarında doğal bir sıralama vardır; bu yüzden regresyon problemi olarak ele almak daha doğrudur.
- **Sayı gibi görünen ama kategorik olan çıkış:** Önceki dersin son örneğindeki rakam tanıma probleminde etiketler 0, 1, 2, ... gibi rakamlardır. Ama bunlar bir şeklin adıdır: 0'a 1 demek, 0'a 9 demekten daha küçük bir hata değildir. Bu bir sınıflandırma problemidir.
- **Gerçek kategorik örnekler:** Bir kişinin tuttuğu futbol takımı, kan grubu, yaşadığı şehir. Bunların arasında "şu şundan büyüktür" diye bir ilişki yoktur.

Problemi regresyon olarak ele almak, modele **hataların toleransını** söylemek demektir. Sınıflandırmada ilkokul mezununa ortaokul mezunu demek ile üniversite mezunu demek aynı büyüklükte hata sayılır. Regresyonda ise ilkokul = 1, ortaokul = 2, üniversite = 5 gibi değerler verildiğinde (hoca sayıları "sallıyorum" diyerek verdi), birinci hata 1, ikinci hata 5 büyüklüğündedir. Bu, problemi daha gerçekçi modellemektir.

## 2. Özellik Belirleme: Neden Gerekli?

Dersin ilk asıl konusu, tablonun özellikler kısmı üzerinde işlem yapmaktır. Bunun gerekçesi şudur: erişilebilen her bilgi, çözmeye çalıştığımız problem için anlamlı olmayabilir. Faydasız özellikler fazlalık ve gürültü yaratır.

### 2.1 Üç özellikli tablo örneği

Slaytta üç özellikli, A/B sınıflı küçük bir tablo vardı (ekrandan, 00:15:00). Slaytın sol tarafında da bir doktorun kişi bilgilerini içeren dosyalardan hastaları bulma görevi ve bakılabilecek bilgiler (ad soyad, doğum yeri, cinsiyet, kan tahlili, röntgen sonuçları) listeleniyordu; bu, her bilginin aynı derecede işe yaramadığını gösteren bir girişti.

| 1. Öz | 2. Öz | 3. Öz | Sınıf |
|---|---|---|---|
| 1 | 3 | 13 | A |
| 2 | 3 | 13 | B |
| 1 | 4 | 13 | A |
| 2 | 3 | 13 | B |

Slayttaki kurallar ve başarıları:

- "1.öz == 1 ise çıkış = A, değilse B": %100.
- "2.öz == 4 ise çıkış = A, değilse B": %75.
- 3. özellik her örnekte 13'tür; yalnız "çıkış = B" denebilir: %50.

Hoca "hangisi en iyi, hangisi en kötü?" diye sordu; bir öğrenci "bir en iyi, üç en kötü" dedi. Hoca ikinci özelliğin de bir şeyler söylediğini ama birincisi kadar olmadığını ekledi. Yani özelliklerin çıkışı tahmin etmedeki katkıları birbirinden farklı olabilir.

### 2.2 Levrek ve somon örneği

Denize atılan ağa, ağın genişliğinden geçebilen iki tür balık takılıyor: levrek ve somon. Ticari değerleri farklı olduğu için ayrılmaları gerekiyor. Bunun için bir düzenek kurulmuş: balıklar bir bant üzerinden teker teker geçiyor, bandın üstündeki kameradan alınan görüntülerden balıklara ait özellikler çıkarılıyor.

İlk özellik **uzunluk**. Her sınıf için uzunluk histogramı çizilir; histogramın her çubuğu, o uzunluktaki balıklardan kaç tane olduğunu gösterir. Yalnız uzunluk kullanılarak yazılabilecek kural şu biçimdedir: "Uzunluk eşikten büyükse bir sınıf, değilse öteki sınıf." Levrekler genel olarak daha uzun olduğundan büyük taraf levrek kabul edilir. Seçilen eşiğin üstünde kalan somonlar ve altında kalan levrekler hatalı sınıflanır. Farklı eşikler denenir; "en iyi eşik" en az hata yapan eşiktir. Bu örnekte sıfır hatalı bir eşik yoktur. <!-- BELİRSİZ: Histogram sayıları ve eşik değeri (altyazıda "17") karede doğrulanamadı. -->

İkinci özellik **parlaklık**tır. Aynı mantıkla onun için de minimum hatalı eşik bulunur; yine sıfır hata mümkün değildir. İki özelliğin minimum hataları yan yana konunca hangi özelliğin daha iyi olduğu görülebilir.

### 2.3 İki temel yaklaşım

Çok sayıda özellik olduğunda iki temel yaklaşım vardır (ekrandan, 00:20:00):

- **Var olan özelliklerden bazılarını seçmek.** Örneğin 20 özellikten 5'ini, 10'unu ya da 19'unu seçmek; hepsini bırakmak da mümkündür. Bunun iki yolu vardır:
  - Özellikleri tek tek değerlendirmek (**filter**).
  - Özellik alt kümeleri oluşturup sınıflandırıcılarla performanslarını ölçmek ve bu alt kümeleri iyileştirmek için değiştirmek (**wrapper**).
- **Var olan özelliklerin lineer birleşimlerinden yeni özellikler çıkarmak.** Örneğin 20 özellikten 10 yeni özellik üretmek; bunlar eski özelliklere eklenebilir ya da yalnız yenilerle devam edilebilir. Birleşimlerin lineer olması zorunlu değildir, ama derste lineer olanlar ele alındı.

## 3. Filter Yöntemleri I: Entropi ve Bilgi Kazancı

Filter yöntemleri, "elimizde yalnız bu özellik olsaydı nasıl bir performansımız olurdu?" sorusunu cevaplar. Özellik ile sınıf (ya da sonuç) arasındaki değişimi inceler: özellik değiştiğinde sınıf ne kadar değişiyorsa, özelliğin etkisi o kadar büyüktür. Derste iki filter yöntemi görüldü: kategorik özellikler için **bilgi kazancı** (information gain), sayısal özellikler için **sinyalin gürültüye oranı** (signal-to-noise ratio).

### 3.1 Entropi

Entropi düzensizliğin ölçüsüdür; yüksek entropi düzenin olmayışı demektir. Hoca termodinamiğin ikinci yasasını, yani düzenliden düzensize doğru gidişi hatırlattı. Makine öğrenmesindeki entropi ise bir kümenin elemanları üzerinden tanımlanır (ekrandan, 00:25:00):

$$E(S) = \sum_{i=1}^{c} -p_i \log_2 p_i$$

Burada $c$ kümedeki farklı (tekil) eleman sayısı, $p_i$ ise $i.$ değerin kümedeki oranıdır. Hoca slaytta üç küme yazarak sınıfla birlikte hesapladı:

- $\{A, A, B, B\}$: $c = 2$, $p_A = p_B = 1/2$.
  $E = -\left(\tfrac12 \log_2 \tfrac12 + \tfrac12 \log_2 \tfrac12\right) = -\left(-\tfrac12 - \tfrac12\right) = 1$.
- $\{A, B, A, B\}$: Bir öğrenci bunun aynı küme olduğunu fark etti. Sıralama entropiyi değiştirmez; entropi yine 1'dir.
- $\{C, A, D, B\}$: Bir öğrenci önce entropinin 0 olması gerektiğini düşündü; hoca bunun öyle olmadığını gösterdi. $c = 4$ ve her değerin oranı $1/4$'tür:
  $E = -4 \cdot \tfrac14 \log_2 \tfrac14 = -\log_2 \tfrac14 = 2$.

Hoca buradan, entropinin 0 ile 1 arasında değişen bir şey olmadığını vurguladı. Entropinin 0 ile 1 arasında değiştiği özel durum $c = 2$ durumudur: iki değerin oranları eşitse ($0.5$, $0.5$) düzensizlik ve entropi en yüksektir (1); kümede tek bir değer varsa entropi 0'dır. Hoca örnek olarak, bütün topları beyaz olan bir kutunun entropisinin 0 olduğunu söyledi.

> **Ders sonrası not:** Hoca entropinin "sıfırla sonsuz arasında" değiştiğini söyledi. Bu, farklı değer sayısı $c$ sınırsız artabildiği için doğrudur; belli bir $c$ için ise entropinin üst sınırı $\log_2 c$'dir ($c = 2$ için 1, $c = 4$ için 2).

### 3.2 Bilgi kazancı

Bilgi kazancının formülü, S eğitim kümesi içindeki A özelliğinin kazancıdır:

$$Gain(S, A) = E(S) - \sum_{v \in Values(A)} \frac{|S_v|}{|S|} E(S_v)$$

$Values(A)$, A özelliğinin alabildiği değerlerdir; $S_v$, A'nın $v$ değerini aldığı örneklerdir.

> **Hocanın vurgusu:** Bilgi kazancı tek bir değişken için hesaplanamaz. Tek bir değişkenin entropisi vardır, ama kazancı yoktur. Bilgi kazancı, bir özelliği bilmenin başka bir değişkeni (çıkışı) tahmin etmeye ne kadar katkı sağladığını gösterir. "Havanın piknik üzerindeki kazancı" anlamlıdır, "havanın kazancı" anlamsızdır.

### 3.3 Piknik örneği

Slayttaki veri, hava, nem, rüzgar ve su sıcaklığına göre pikniğe gidip gitmeme kararının verildiği 4 olaydır (ekrandan, 00:30:00). Olay numarası yalnız sırayı gösterir, özellik olarak kullanılmaz.

| Olay No | Hava | Nem | Rüzgar | Su sıcaklığı | Pikniğe gidildi mi? |
|---|---|---|---|---|---|
| 1 | güneşli | normal | güçlü | ılık | Evet |
| 2 | güneşli | yüksek | güçlü | ılık | Evet |
| 3 | yağmurlu | yüksek | güçlü | ılık | Hayır |
| 4 | güneşli | yüksek | güçlü | soğuk | Evet |

Adım adım:

- **Çıkışın entropisi:** Evet oranı $3/4$, hayır oranı $1/4$.
  $E(S) = -\left(\tfrac34 \log_2 \tfrac34 + \tfrac14 \log_2 \tfrac14\right) \approx 0.811$.
- **Havanın kazancı:** Hava güneşli olma oranı $3/4$'tür ve bu üç olayın üçünde de pikniğe gidilmiştir (oranlar $3/3$ ve $0$), entropi 0. Hava yağmurlu olma oranı $1/4$'tür ve bu olayda gidilmemiştir (oranlar $0$ ve $1$), entropi 0.
  $Gain(S, Hava) = 0.811 - \left(\tfrac34 \cdot 0 + \tfrac14 \cdot 0\right) = 0.811$.
  Kazancın çıkışın entropisine eşit olması, iki değişkenin birbirini tam açıkladığını gösterir: birine bakarak diğeri söylenebilir. Tabloya bakınca da havanın piknik kararını net gösterdiği görülür.
- **Rüzgarın kazancı:** Rüzgar hiç değişmemiştir (hepsi "güçlü"). Bu yüzden hiçbir şey söylememesi beklenir; hesaplanınca kazancı 0 çıkar.
- **Nem ve su sıcaklığı:** Hoca bunların bir şeyler söylediğini, ama hava kadar iyi olmadığını belirtti. Değerler derste söylenmedi; tablodan hesaplanınca (python ile kontrol edildi) ikisinin kazancı da $0.811 - \tfrac34 \cdot 0.918 \approx 0.123$ çıkar.

Bu yöntemle her özelliğin, tahmin edilmek istenen çıkış üzerindeki kazancı hesaplanır; özellikler kazanca göre sıralanır ve en büyükleri ya da belli bir eşiğin üstündekiler seçilir. Burada her özellik, elimizde yalnız o varmış gibi değerlendirilir: nemin kazancı hesaplanırken yalnız nem ve piknik sütunları kullanılır. Bilgi kazancı temelde kategorik girişler için kullanılır.

## 4. Filter Yöntemleri II: Sinyalin Gürültüye Oranı

Sayısal girişler için kullanılan yöntem sinyalin gürültüye oranıdır. Hoca önce önceki dersteki el yazısı ve kitap yazısı tanıma problemini hatırlattı. El yazısı tanıma daha zordur, çünkü sınıf içi örneklerin birbirine benzerliği daha azdır: bir harfin el yazısında çok sayıda varyasyonu vardır, kitap yazısında ise bu kadar yoktur. Sınıf içi benzerlik ne kadar fazla olursa o kadar iyidir. Sınıflar arası benzerlik ise problemi zorlaştırır: büyük O harfi ile sıfır birbirine çok benzediği için zor bir ayrımdır.

Sinyalin gürültüye oranı tam olarak bu iki fikri ölçer (ekrandan, 00:35:00). Amaç, sınıflar arası ayrılığı fazla, sınıf içi ayrılığı az olan özellikleri seçmektir:

$$S_i = \frac{|m_1 - m_2|}{d_1 + d_2}$$

- $m_1$: sınıf 1'deki $i.$ özelliklerin ortalaması; $m_2$: sınıf 2'deki $i.$ özelliklerin ortalaması. Pay "sinyal"dir.
- $d_1$, $d_2$: sınıf 1 ve sınıf 2'deki $i.$ özelliklerin standart sapması. Payda "gürültü"dür.
- $S$ değeri en yüksek olan özellikler seçilerek sınıflandırmada kullanılır.

Hoca sınıfa iki soru sordu. Sınıf ortalamaları arasındaki farkın büyük mü küçük mü olmasını isteriz? Büyük olmasını: sınıfların ortalamaları birbirinden uzak olsun. Standart sapma neyi ifade eder? Hoca "standart sapma" adını açıkladı: standarttan, yani ortalamadan sapmadır. Küçük standart sapma örneklerin ortalamaya yakın, yani sınıf içinde benzer olduğunu gösterir. Bu yüzden $d_1 + d_2$'nin küçük olmasını isteriz.

Slayttaki görsel örnekte (yeşil ve sarı daireler) iki karşılaştırma yapıldı:

- Standart sapmaları aynı olan iki problemden, ortalamaları birbirinden daha uzak olanı ($|m_1 - m_2|$ büyük olanı) daha kolaydır.
- Ortalamaları arasındaki fark aynı olan iki problemden, standart sapması küçük olanı daha kolaydır.

## 5. Filter Yöntemlerinin Sınırı

Hoca slayta yeşil ve kırmızı noktalardan oluşan dört grup çizdi (ekrandan, 00:40:00): sol üstte ve sol altta yeşil, sağ üstte ve sağ altta kırmızı gruplar vardı. Öz1'e göre yeşillerin ortalaması solda, kırmızılarınki sağdadır; aralarında belirgin bir mesafe vardır. Öz2'ye göre ise iki sınıfın ortalaması aynı yerdedir, $m_1 - m_2 = 0$. Bir öğrencinin de söylediği gibi bu durumda öz1 iyi, öz2 işe yaramaz bir özellik olarak görünür.

Sonra hoca grupların yerini değiştirerek her renkten birer grubun çapraz köşelerde durduğu bir düzen kurdu (XOR benzeri bir yerleşim). <!-- BELİRSİZ: Değiştirilmiş yerleşim kareye denk gelmedi; altyazıdaki anlatımdan aktarıldı. --> Bu durumda iki özellik için de $m_1 - m_2 = 0$ olur. Bir öğrenci de ortalamaların eşit olduğunu söyledi. Sinyalin gürültüye oranına göre iki özellik de hiçbir işe yaramaz.

Oysa iki özellik birlikte kullanılınca veri tam olarak sınıflandırılabilir. Örneğin hoca bölge sınırlarına 3 ve 2 değerlerini vererek şu türden bir kural yazdı:

```text
Eğer öz1 < 3 ve öz2 < 2 ise sınıf = yeşil
```

Her bölge için benzer kurallar yazılabilir. Ama filter yaklaşımı bunun yapılabileceğini söyleyemez.

> **Hocanın vurgusu:** Filter yöntemleri, tek başına işe yaramayan ama birlikte kullanıldığında işe yarayan özellikleri bulamaz. Bu yüzden özellikleri birlikte değerlendiren başka bir yaklaşıma, wrapper'lara ihtiyaç vardır.

## 6. Wrapper Yöntemleri: Özellik Alt Kümesi Seçiciler

Wrapper'lar özellikleri tek tek değil, birlikte kullanarak değerlendirir.

### 6.1 Arama uzayı

$N$ özellik için olası $2^N$ özellik alt kümesi vardır; her alt küme ayrı bir eğitim demektir (ekrandan, 01:05:00). Dört özellikli bir veri kümesinde (A, B, C, D) alt kümeler şunlardır (ekrandan, 01:00:00):

- Tekliler: A, B, C, D
- İkililer: AB, AC, AD, BC, BD, CD
- Üçlüler: ABC, ABD, BCD, ACD
- Dörtlü: ABCD
- Boş küme

Toplam 16 alt küme vardır. Grafikte her düğüm bir alt kümeyi 0/1 vektörüyle gösterir (örneğin 1,0,1,0 = 1. ve 3. özellik). Her alt küme ayrı bir veri kümesi gibi düşünülebilir: yalnız A verilip çıkış tahmin edilir, yalnız A ve B verilip çıkış tahmin edilir vb. Wrapper'ın verebileceği bütün cevaplar bu 16 düğümdür.

İdeal olarak bütün alt kümeleri oluşturup her birinin sınıflandırma performansını ölçmek ve en iyisini seçmek istenir. Özellik sayısı azsa bu mümkündür: 4 özellik için 16 deneme yeter. Ama $N = 100$ olduğunda $2^{100}$ alt kümeyi denemek mümkün değildir. Bu yüzden wrapper'lar önce bütün alt kümeleri oluşturup sonra seçmez.

### 6.2 Hiçbir özellik kullanmadan başarı: mantıklı atma

Arama boş kümeden başlar. Boş küme, hiçbir özelliğe bakmamak demektir; buna rağmen bir performans vardır. Yalnız sınıf sütununa bakarak yeni örneğin sınıfı tahmin edilebilir: eğitim kümesinde A ve B %50-%50 ise, test kümesinin de böyle olduğu varsayılarak %50 tutturulur. A %90, B %10 ise mantıklı tahmin her zaman A demektir ve %90 başarı elde edilir.

Bunun dayandığı varsayım, makine öğrenmesinin temel varsayımıdır: **gelecek geçmişe benzer**, yani eğitim ve test kümelerinin dağılımı değişmez. Yapılan her işin üzerine oturduğu varsayım budur.

> **Hocanın vurgusu:** Sınıflandırma başarısı (doğru tahmin oranı) tek başına bir ölçüt değildir; ancak mantıklı atma değeriyle birlikte anlam kazanır. Mantıklı atma %90 iken %90 başarılı bir modelin hiçbir anlamı yoktur. Buna karşılık 1000 sınıflı, sınıfların eşit dağıldığı bir problemde mantıklı atma binde birdir; orada %5 başarı oldukça iyidir. Önemli olan, şansı ne kadar ileri taşıdığınızdır.

Grafikte boş kümenin (0,0,0,0) başarısı 60'tır.

### 6.3 Adım adım wrapper: tepe tırmanma

Wrapper, her adımda bir özellik eklemeye çalışan iteratif bir süreçtir. Kohavi ve John (1997) kaynaklı grafikteki değerlerle (ekrandan, 01:05:00 ve 01:10:00):

- **Başlangıç:** Boş küme, başarı 60.
- **1. adım:** Dört özellikten biri eklenebilir. 1,0,0,0 → 65; 0,1,0,0 → 69; 0,0,1,0 → 70; 0,0,0,1 → 60. Mevcut durumdan (60) daha iyi olanlar vardır; en iyisi 70'tir. 3. özellik seçilir.
- **2. adım:** Geriye 3 hamle kalır: 1, 2 ya da 4 eklenebilir. 1,0,1,0 → 80; 0,1,1,0 → 70; 0,0,1,1 → 75. 80'e gitmek mantıklıdır; artık 1. ve 3. özellikler seçilidir.
- **3. adım:** Geriye 2 hamle kalır: 2 ya da 4 eklenebilir. 1,1,1,0 → 79; 1,0,1,1 → 65. İkisi de 80'den kötüdür.
- **Durma:** Daha fazla iyileşme olmadığı için algoritma durur. Wrapper'ın cevabı: 1. ve 3. özelliklerden oluşan alt küme iyi bir alt kümedir.

Hoca hangi algoritmanın çalıştırıldığını sordu. Öğrencilerden önce BFS, sonra en iyi öncelikli arama (best first search) önerisi geldi; hoca bunların benzediğini ama doğru olmadığını söyledi. Bir öğrenci sezgisel/lokal arama olduğunu söyledi, sonra başka bir öğrenci doğru cevabı verdi: **tepe tırmanma** (hill climbing). Bir yerde durulur, gidilebilecek yerler vardır; daha iyi bir yer varsa oraya gidilir ve iyileştiren yer kalmayana kadar devam edilir. Tepe tırmanma, lokal (sezgisel) arama algoritmalarından biridir.

### 6.4 Karmaşıklık, avantaj ve dezavantaj

$N$ özellik varken ilk adımda $N$ deneme, ikinci adımda $N - 1$ deneme yapılır; sona kadar gidilirse toplam $N + (N-1) + \dots + 1 = \tfrac{N(N+1)}{2}$, yani $O(N^2)$ mertebesindedir. Bir öğrencinin cevabıyla da doğrulandığı gibi, wrapper arama maliyetini $2^N$'den $N^2$'ye indirir. Avantajı budur: özellik sayısı çok fazla olsa da hesaplanabilir.

Dezavantajı, en iyi sonucu bulamayabilmesidir. Grafikte 1,1,0,0 alt kümesinin başarısı 90'dır, ama algoritma bunu hiç denemez. $2^N$ olasılık içinde yalnız $N^2$ kadarı denenir; $N$ küçükken bile denenmeyenlerin oranı çok büyüktür. Yine de diğer yol erişilemez olduğu için bununla idare etmek gerekir: problemi mükemmel değil ama çözmek isteriz. Arama uzayının çok büyük olduğu durumlarda lokal arama zaten standart yaklaşımdır.

> **Ek bilgi (derste anlatılmadı):** $N = 100$ için tepe tırmanma en fazla $100 \cdot 101 / 2 = 5050$ alt küme dener; bütün alt kümelerin sayısı ise $2^{100} \approx 1.27 \times 10^{30}$'dur.

### 6.5 İleri ve geri yön

Arama boş kümeden başlayıp her adımda bir özellik ekleyerek gidebileceği gibi (ileri yön), bütün özelliklerle başlayıp her adımda bir özellik silerek de gidebilir (geri yön). Hoca iki yönün aynı alt kümeye varıp varmayacağını sordu; bir öğrenci "varmayabilir" dedi. Doğrudur: lokal aramanın doğası budur.

## 7. Yeni Özelliklerin Çıkarımı: PCA ve LDA

İkinci büyük yaklaşım, var olan özelliklerin lineer birleşimlerinden yeni bir özellik uzayı oluşturmak ve verileri bu uzayda ifade etmektir. Slayttaki gösterim (ekrandan, 01:15:00):

```text
x1, x2, x3, x4, ..., x100

Y1 = w11*x1 + w12*x2 + w13*x3 + w14*x4 + w15
Y2 = w21*x1 + w22*x2 + w23*x3 + w24*x4 + w25
Y3 = w31*x1 + w32*x2 + w33*x3 + w34*x4 + w35
Y4 = w41*x1 + w42*x2 + w43*x3 + w44*x4 + w45
....
Y100 =
```

Her yeni özellik bütün eski özelliklerin lineer birleşimidir; yeni özellikleri birbirinden ayıran tek şey $w$ katsayılarıdır. 100 yeni özellik üretilebileceği gibi 5 ya da 1000 tane de üretilebilir. Asıl mesele, bu yeni özelliklerin nasıl bulunacağı ve hangi amaçla oluşturulacağıdır. Hoca bunun için çok sayıda yöntem olduğunu, derste yaygın iki tanesinin görüleceğini söyledi.

### 7.1 Temel bileşen analizi (PCA)

PCA (Principal Component Analysis), yeni özelliklerin standart sapmasının (varyansının) yüksek olmasını ister: veriler yeni özellik üzerinde mümkün olduğunca dağılsın. Ayrıca gereksiz (redundant) özellikler üretmemek için yeni özelliklerin birbirine **ortogonal** olmasını ister; $Y_1$ ve $Y_2$ birbiri cinsinden ifade edilemesin.

Slayttaki örnekte iki boyutlu ($x_1$, $x_2$) siyah bir nokta bulutuna PCA uygulanınca iki yeni boyut bulunur: C1 ve C2. İkisi de $x_1$ ile $x_2$'nin karışımıdır. C1'in seçilme nedeni, verileri C1 üzerine iz düşürünce dağılımın (varyansın) çok geniş olmasıdır; C2 üzerine iz düşürünce dağılım dardır. PCA önce C1'i bulur, geriye C2 kalır.

PCA orijinal veride kaç boyut varsa o kadar yeni boyut üretir. Kendisi doğrudan boyut indirgemez, ama ilk $k$ özelliği seçip kullanmak mümkündür. Örnekte yalnız C1'i kullanmak, iki boyuttan bir boyuta indirgemek demektir.

PCA'nın bir başka özelliği, hiçbir sınıf bilgisi kullanmamasıdır: **gözetimsiz** (unsupervised) bir yöntemdir ve yalnız varyansı en büyük yapmaya çalışır. Bunun sonucu slaytta kırmızı ve mavi noktalardan oluşan bir bulutla gösterildi: PCA'nın seçtiği birinci boyuta iz düşürülen veride iki sınıf birbirine girer. Yani PCA sınıflandırma için her zaman iyi sonuç vermez.

### 7.2 Doğrusal ayırtaç analizi (LDA)

PCA'nın alternatifi LDA'dır (Linear Discriminant Analysis, doğrusal ayırtaç analizi). PCA varyansı en büyük yapmaya çalışırken LDA **sınıflandırılabilirliği** en büyük yapmaya çalışır: veriler bulunan boyuta indirildiğinde sınıflar birbirinden ayrılabilsin. Bu yüzden LDA **gözetimli** (supervised) bir yöntemdir ve uygulanabilirliği daha azdır: sınıf bilgisi yoksa PCA kullanılabilir, LDA kullanılamaz.

> **Ek bilgi (derste anlatılmadı):** LDA'nın klasik (Fisher) biçimi, iz düşümünden sonra sınıf ortalamaları arasındaki uzaklığın sınıf içi dağılıma oranını en büyük yapan yönü arar. Bu, 4. bölümdeki sinyalin gürültüye oranı fikrinin tek bir özellik yerine özelliklerin lineer birleşimine uygulanmış hâli gibi düşünülebilir.

### 7.3 Doğrusal olmayan birleşimler

Hoca PCA ve LDA'nın ayrıntılarına girmedi, ama temel mantığın hepsinde aynı olduğunu vurguladı: yeni özellikler eski özelliklerin birleşimidir. Lineer birleşim, doğrusal olmayan bir $f$ fonksiyonundan geçirilebilir (ekrandan, 01:20:00):

```text
Y1 = f(w11*x1 + w12*x2 + w13*x3 + w14*x4 + w15)
Y2 = F(w21*x1) + F(w22*x2) + w23*x3 + w24*x4 + w25
```

$f$ doğrusal olmayan bir fonksiyon olursa lineer değil, doğrusal olmayan birleşimler bulunmuş olur. Bu yapı temelde bir yapay sinir ağına dönüşür.

## 8. Hangi Yöntem? Bedava Öğle Yemeği Yok Teoremi

Hoca çok sayıda yöntem olduğunu ve hangisinin ne zaman kullanılacağına dair kesin bir kural olmadığını söyledi. Bunu açıklayan, daha önce görülen **No Free Lunch** (bedava öğle yemeği yok) teoremidir: denemeden hangi yöntemin daha iyi olacağı bilinemez. Eldeki veri kümesine göre bazen bir yöntem, bazen başka bir yöntem daha iyi olur; her veri kümesinde diğerlerinin hepsinden daha iyi çalışan bir yöntem yoktur. Bu yalnız özellik seçimi için değil, regresyon, sınıflandırma ve kümeleme için de geçerlidir. Her durumda en iyi olan bir "usta algoritma" olsaydı yalnız o kalırdı; diğer yöntemlerin hepsinin varlığını sürdürmesi, her birinin farklı durumlarda daha başarılı olabilmesindendir.

## 9. Doğrusal Sınıflandırıcı

Sınıflandırmada amaç, sınıfları bilinen veriler varken yeni gelen bir örneğin (test örneğinin) sınıfını tahmin etmektir. Slayttaki örnekte mavi ve gri noktalar vardır; beyaz bir test noktası gelir ve sınıfı sorulur (ekrandan, 01:25:00). Bunun için bir model uydurmak gerekir. İlk model doğrusal sınıflandırıcıdır:

$$w_0 + w_1 x_1 + w_2 x_2 + \dots + w_d x_d \ge 0$$

Regresyon (eğitim) en az hata yapan $w_i$'leri bulmaya çalışır. Bunun iteratif yolları da, tek adımda bulan yolları da vardır; sonuçta iki sınıfı birbirinden ayıran bir doğru aranır. İki sınıfı aynı başarıyla ayıran birden çok doğru olabilir; aralarından seçim için çeşitli düzenlileştirme (regularization) yöntemleri vardır.

Doğrusal model her veriye uyum sağlayamaz: slayttaki veri kümesinde sıfır hatalı bir sonuç üretemez. İkiden fazla sınıf varsa tek bir doğruyla ayrım zaten yapılamaz.

> **Hocanın vurgusu:** İkiden fazla sınıflı her problem, belli sayıda iki sınıflı probleme indirgenerek çözülebilir. Yani tek bir doğrusal sınıflandırıcıyla değil, ama birden çok doğrusal sınıflandırıcının birlikte kullanılmasıyla çok sınıflı problemler de çözülebilir.

Doğrusal modelin kötü tarafı, her türlü veriye uyum sağlayamamasıdır; iyi tarafı basitliğidir. Basitliğin getirisi **yorumlanabilirliktir**. Doğrudaki $x_1, x_2, \dots, x_d$ özelliklerdir, $w$'ler onların katsayılarıdır. Bir katsayının artı ya da eksi, büyük ya da küçük olması modelin neye göre karar verdiğini açıklar. Örneğin $x_2$'nin katsayısı negatif ve büyükse, $x_2$ problem için önemli bir özelliktir ve o sınıfı negatif yönde etkiler: $x_2$ ne kadar küçükse o sınıf için o kadar iyidir. Böylece her özelliğin çıkışa etkisi doğrudan gözlenebilir ve kararlar kolayca yorumlanabilir.

## 10. Karar Ağaçları

### 10.1 Genel yapı

Karar ağaçları veriyi **böl ve yönet** stratejisiyle modeller: her adımda veriyi iki parçaya ayırır. Slayttaki örnekte iki özellik ($x$ ve $y$) ile şu türden kurallar vardı: $x$ 5'ten büyükse mavi; değilse ve $y$ 3'ten büyükse yine mavi; bunlar da değilse $x$ 2'den büyükse başka bir sınıf (hoca "green dedim, gray olması lazım" diyerek düzeltti) vb. Böyle bir kural yapısı bir ağacı temsil eder. <!-- BELİRSİZ: Bu slayttaki eşik değerleri ve sınıf adları karede doğrulanmadı. -->

Ürettikleri kurallar çok kolay anlaşılır: bir yapraktan yukarı doğru izlenerek hangi özelliklerin hangi eşik değerleri yüzünden çıkışın ne olduğu görülür. Bu yüzden karar ağaçları açıklanabilirlik açısından oldukça başarılıdır. Yapı, karar düğümleri ve yapraklardan oluşan hiyerarşik bir yapıdır.

### 10.2 Örnek veri

Hoca ağacın nasıl kurulduğunu bir örnekle gösterdi (ekrandan, 01:30:00). İki boyutlu uzayda 20 örnek vardır; her örneğin iki özelliği ve bir sınıfı (X ya da O) vardır. Yatay eksen $x_1$, dikey eksen $x_2$'dir. Satırlar $x_2$ değerleri, sütunlar $x_1$ değerleridir:

| $x_2$ \ $x_1$ | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 5 | O | X | X | X |
| 4 | O | X | X | X |
| 3 | O | O | O | X |
| 2 | O | O | O | X |
| 1 | X | X | O | O |

Bu veri kümesinde 10 X ve 10 O vardır. Doğrusal bir sınıflandırıcı burada çok başarılı olamaz.

### 10.3 Algoritma

Karar ağacı algoritması çok basittir:

- **Bölmeye gerek var mı?** Eldeki veri yeterince saf mı, yani aynı sınıftan örnekler mi içeriyor? Hem X hem O varsa saf değildir; bölünür.
- **Nereden bölünür?** Tek değişkenli (univariate) karar ağacında, ikiye bölerken yalnız **bir özellik ve bir eşik değeri** kullanılabilir. Bu en temel algoritmadır; düğümlerde çok değişkenli (multivariate) yapılar da kullanılabilir, ama derste bu konuya girilmedi. Bu kısıtla bölmeler eksenlere paralel çizgiler olur.
- **Aday bölmeler:** $x_1$ için 1.5, 2.5, 3.5; $x_2$ için 1.5, 2.5, 3.5, 4.5. Toplam 7 olası bölme vardır.
- **Seçim:** Her adaydan bölünür, iki tarafa çoğunluk sınıfı verilir ve hata sayılır; en az hatalı bölme seçilir.

Slayttaki hata değerleri (ekrandan, 01:35:00):

```text
X1 = 1.5 (7), 2.5 (8), 3.5 (7)
X2 = 1.5 (?), 2.5 (?), 3.5 (?), 4.5 (?)
```

$x_1 = 1.5$ için: sol tarafta ($x_1 = 1$) 4 O, 1 X vardır; sola O denir, 1 hata. Sağ tarafta 9 X, 6 O vardır; sağa X denir, 6 hata. Toplam 7. $x_1 = 2.5$ için: solda 6 O, 4 X (O denir, 4 hata); sağda 6 X, 4 O (X denir, 4 hata); toplam 8, daha kötü. $x_1 = 3.5$ için: solda 9 O, 6 X (6 hata); sağda 4 X, 1 O (1 hata); toplam 7.

Hoca $x_2$ değerlerini hesaplamadan "?" bıraktı ve örneği sürdürmek için en iyisinin $x_1 = 1.5$ olduğunu varsaydı ("şimdilik sallıyorum" diyerek).

> **Ders sonrası not:** $x_2$ bölmelerinin hataları python ile hesaplandığında $x_2 = 1.5 \to 10$, $2.5 \to 8$, $3.5 \to 6$, $4.5 \to 8$ çıkar. Yani bu ölçüte göre gerçekte en iyi ilk bölme $x_2 = 3.5$'tir (6 hata). Hoca $x_1 = 1.5$'i yalnız anlatım için seçtiğini belirtti.

### 10.4 Özyinelemeli bölme

Bölmeden sonra elde iki ayrı veri kümesi kalır ve her biri için aynı işlem tekrarlanır:

- **Sol taraf ($x_1 < 1.5$):** Hem O hem X var, bölmeye gerek var. Bütün örneklerin $x_1$ değeri aynı olduğu için $x_1$'e göre bölmek anlamsızdır; $x_2$'ye göre bölünür. $x_2 = 1.5$'ten bölmek sıfır hata verir: altta X, üstte O. İki parça da saftır; burada iş biter.
- **Sağ taraf ($x_1 > 1.5$):** Hâlâ karışıktır. Bu kez 6 olası bölme vardır ($x_1$ için 2.5 ve 3.5; $x_2$ için 1.5, 2.5, 3.5, 4.5). Her birinin hatası hesaplanır, en az hatalı olan seçilir; saf olmayan parçalar saf olana kadar bölünmeye devam eder.

Slayttaki son çizimde (ekrandan, 01:40:00) bölgeler şöyledir:

```text
x1 < 1.5:
    x2 < 1.5          -> X
    x2 > 1.5          -> O
x1 > 3.5:
    x2 < 1.5          -> O
    x2 > 1.5          -> X
1.5 < x1 < 3.5:
    x2 > 3.5          -> X
    x2 < 3.5:
        x1 > 2.5      -> O
        x1 < 2.5:
            x2 < 1.5  -> X
            x2 > 1.5  -> O
```

<!-- BELİRSİZ: Sağ taraftaki bölmelerin hangi sırayla yapıldığı altyazıdan ve kareden net çıkmıyor; yukarıdaki yapı yalnız son bölgeleri gösterir. -->

Sonuçta "özellik şu eşikten büyük mü küçük mü?" diye soran **karar düğümleri** ve en sonda "bu bölgeye düşen örnek X (ya da O) sınıfındandır" diyen **yapraklar** elde edilir. Yapraklar aynı seviyede olmak zorunda değildir. Düğümler yönlendirme yapılan, yapraklar karar verilen yerlerdir.

### 10.5 Test örneğinin sınıflandırılması

Ağaç kurulduktan sonra bir test örneğinin sınıfını bulmak çok kolaydır (ekrandan, 01:45:00):

- En tepedeki kök karar düğümünden başlanır.
- Bir yaprağa gelinceye kadar karar düğümlerindeki yönlendirmelere göre dallarda ilerlenir. Karar düğümünde tek bir özelliğin adı ve bir eşik değeri yer alır; verinin hangi dala gideceğine, o özelliğinin eşik değerinden büyük ya da küçük olmasına göre karar verilir.
- Verinin sınıfı, yaprağın temsil ettiği sınıf olarak belirlenir.

## 11. Evrensel Yaklaşıklayıcılar ve Saflık Ölçütü

### 11.1 Karar ağaçları esnek mi?

Hoca karar ağaçlarının esnek olup olmadığını sordu: her türlü eğitim kümesine %100 uyum sağlarlar mı? Doğrusal sınıflandırıcı az önceki eğitim kümesinde %100 başarılı bir model kuramıyordu; karar ağacı kurabildi. Bir öğrenci şu cevabı verdi: eğitim kümesinde tüm özellikleri aynı olup sınıfı farklı olan iki örnek yoksa, ağaç biraz uzun olsa da kesinlikle oluşturulabilir. Hoca bu cevabı onayladı: aynı noktada iki farklı sınıftan örnek olması dışındaki (çok nadir) durumlarda karar ağaçları eğitim kümesini tam olarak modelleyebilir. Karar ağaçları aşırı derecede esnek algoritmalardır.

### 11.2 Evrensel yaklaşıklayıcılar

Her türlü eğitim kümesine uyum sağlayabilen algoritmalara evrensel yaklaşıklayıcı (universal approximator) denir. Hoca örnekleri şöyle sıraladı:

- Karar ağaçları.
- Yapay sinir ağları.
- Daha sonra görülecek en yakın bir komşu (1-NN) algoritması.
- Sinyaller tarafında Fourier açılımları: yeterince terim alınırsa herhangi bir fonksiyon temsil edilebilir. Benzer şekilde (türevlenebilir fonksiyonlar için) Taylor serileri ve dalgacık (wavelet) açılımları. <!-- BELİRSİZ: Altyazıda "Tiger serileri" ve "Raylet" geçiyor; büyük olasılıkla Taylor serileri ve wavelet kastedildi. -->

> **Ek bilgi (derste anlatılmadı):** Literatürde "evrensel yaklaşıklama teoremi" genellikle yapay sinir ağları için, yeterli sayıda gizli nöronla sürekli fonksiyonların istenen doğrulukla yaklaşıklanabileceğini söyleyen sonuç için kullanılır. Hocanın derste kullandığı anlam daha geniştir: her eğitim kümesine tam uyum sağlayabilme.

### 11.3 Saflık ölçütü bir hiperparametredir

Karar ağaçlarındaki "bölmeye gerek var mı?" sorusunun cevabı bir hiperparametreye bağlıdır: **saflık**, yani bölgelerin ne kadar saf olması istendiği. "Her bölgede yalnız tek sınıftan örnek olsun" denebilir. Ama veride gürültü varsa bu kadar yüksek saflık istemek ağacın gereksiz yere büyümesine yol açar.

Hoca bunu bir çizimle gösterdi: yeşil örnekler bir tarafta, sarı örnekler öbür taraftadır ve tek bir kesikle ayrılabilir. Bir sarı örneğin yeşillerin arasına düştüğünü düşünün. Saflık ölçütü çok yüksekse ağaç bu noktanın çevresine de bölmeler çizmek zorunda kalır. O nokta anlamlı bir veriyse sorun yoktur, ama gürültüyse bu iyi bir şey değildir. Gürültüden kaçınmak mümkün değildir; ölçüm vb. süreçlerden gelir. Bu yüzden saflık ölçütünü %100 yapmak her zaman iyi bir fikir değildir. Saflık, daha önce anlatılan entropi üzerinden de ölçülebilir.

## 12. Yapay Sinir Ağlarına Kısa Bakış

Yapay sinir ağları, karar ağaçlarının eksenlere paralel basamaklı sınırları yerine daha karmaşık karar sınırları üretebilir. Hoca, çeşitli veri kümeleri üzerinde farklı yapay sinir ağları kurup eğitilebilen bir çevrim içi oyun alanı gösterdi ve öğrencilere orada denemeler yapmalarını önerdi. Orada orijinal özelliklerin ($x_1$, $x_2$) yanında karelerinin, çarpımlarının, hatta sinüslerinin de ek özellik olarak kullanılabildiği ve bunun özellikle yerel bölgeler elde etmede fayda sağladığı görülüyordu. <!-- BELİRSİZ: Gösterilen sitenin adı altyazıda geçmiyor ve kareye denk gelmedi. -->

Yapay sinir ağları katmanlardan oluşur; katmanlar arasında, bir katmanın çıkışlarını başka bir katmanın girişine dönüştüren ağırlıklar vardır. Bu ağırlıkların öğrenilmesi, ağın eğitimidir. Bu, doğrusal sınıflandırıcıdaki $w_0, w_1, \dots$ katsayılarının bulunmasına benzer; yalnız yapı daha karmaşıktır. Ağdaki her nöron, bir lineer perceptron ve onun üstünde doğrusal olmayan bir fonksiyondan oluşur. Amaç, istenen girişlere karşı istenen çıkışları üretecek ağırlıkları bulmaktır.

Bu arama sürekli bir uzayda yapılır ve bütün olası ağırlıkları denemek mümkün olmadığından mecburen lokal arama kullanılır. Sürekli uzayda, kategorik uzayda olmayan bir bilgi vardır: **gradyan**. Gradyan, hangi yöne gidilirse daha iyi olunacağına dair ipucu verir. Ağlar stokastik gradyan iniş (stochastic gradient descent) gibi temel algoritmalarla eğitilir. Hoca bunların ayrıntısından bu derste sorumlu olunmadığını belirtti.

## 13. Parametre ve Hiperparametre

En yakın K komşu algoritmasındaki $K$ bir hiperparametre olduğu için hoca burada bir parantez açtı.

- **Parametreler:** Algoritmaya bizim söylemediğimiz, algoritmanın kendisini verilen veriye uyumlu hâle getirmek için kendi optimize ettiği değişkenlerdir. Optimizasyon, verilen veriye ve kayıp (loss) fonksiyonuna göre yapılır.
- **Hiperparametreler:** Algoritmaya bizim söylediğimiz, bizim seçmemiz gereken değerlerdir. Örnekler:
  - Yapay sinir ağında kayıp fonksiyonu, gizli katman sayısı, aktivasyon fonksiyonu, öğrenme algoritması.
  - Karar ağacında saflık ölçütü ve her düğümde kaç özellik kullanılacağı (tek değişkenli mi, çok değişkenli mi).
  - En yakın K komşuda $K$'nin değeri.

Hiperparametrelerin değeri oldukça önemlidir: bir hiperparametre değeri için çok iyi eğitilen bir model, başka bir değer için iyi olmayabilir. Hiperparametre ince ayarı (fine tuning) bu yüzden ortaya çıkar. Hoca, genetik algoritmalar anlatılırken "çok fazla ayarlanabilir parametresi var" dendiğini hatırlattı ve doğru ifadenin "çok fazla hiperparametresi var" olduğunu söyledi. Sorun şudur: bir problem için iyi hiperparametreler bulunduğunda, başka bir problemde ya da biraz değiştirilmiş aynı problemde bu değerler aynı olmaz; ayarlama yeniden yapılmalıdır.

Hiperparametre sayısının çok olması bir açıdan iyidir: algoritma esnek olur ve çok farklı yapıdaki veri kümelerine uyum sağlayabilir. Öbür açıdan kötüdür: optimize etmek çok zorlaşır. Standart bir yapay sinir ağını eğitirken bile en az 20-30 hiperparametre vardır; çoğu için varsayılan değerlerle çalışmak zorunda kalınır. 10 hiperparametrenin her biri için 10 değer denemek istense bile deneme sayısı korkunç olur. Hiperparametre optimizasyonu için çeşitli teknikler vardır, ama hepsi yine lokal arama süreçleridir. Bir anlamda, bir şeyi optimize etmek için kullanılan modeli optimize etmek için bir model daha kurulmuş olur.

> **Ek bilgi (derste anlatılmadı):** 10 hiperparametrenin her biri için 10 değer denenirse tam ızgara araması $10^{10}$ eğitim gerektirir.

## 14. En Yakın K Komşu

"Bana arkadaşını söyle, sana kim olduğunu söyleyeyim" algoritması da denen en yakın K komşu (k-NN), anlatması en basit algoritmadır (ekrandan, 01:50:00). Eğitim süreci yoktur. Bir test örneğinin sınıfı sorulduğunda:

- Test örneğine en yakın $K$ eğitim örneği bulunur.
- Bu $K$ örneğin sınıflarına bakılır.
- En çok tekrarlanan sınıf, test örneğinin sınıfı olarak söylenir.

Slayttaki çöp adam örneğinde mavi kafalı test örneğinin sınıfı sorulur. En yakın 1 komşu kullanılırsa ona en yakın örnek A sınıfındandır ve cevap A olur. En yakın 3 komşu kullanılırsa çemberin içinde 2 B ve 1 A vardır ve cevap B olur.

Kodlanması çok kolaydır ve eğitim süreci yoktur.

### 14.1 k-NN her eğitim kümesine uyar mı?

Hoca bu algoritmanın her eğitim kümesine %100 uyum sağlayıp sağlayamayacağını sordu. Bir öğrenci önce "sağlamaz" dedi; hoca en yakın 1 komşu için düşünmeyi istedi. Gerekçe şudur: eğitim kümesinden bir örnek seçildiğinde, ona en yakın eğitim örneği kendisidir; algoritma ona kendi sınıfını söyler. Bu yüzden 1-NN'in eğitim kümesindeki başarısı %100'dür ve 1-NN bir evrensel yaklaşıklayıcıdır.

> **Hocanın vurgusu:** Evrensel yaklaşıklayıcı kavramı yalnız eğitim kümesi için geçerlidir: verilen her veriyi modelleyebilmek demektir. Test kümesi için böyle bir şey hiçbir algoritma için söylenemez.

Karar ağaçlarında da aynı şekilde eğitim kümesinde %100 kolayca yakalanabilir.

$K$ ne kadar küçükse esneklik o kadar fazladır. Hoca $K$'nin en fazla nereye kadar çıkabileceğini sordu: eğitim kümesindeki örnek sayısına kadar. Bu durumda algoritma bütün eğitim kümesinin çoğunluk sınıfını döndürür; bu da daha önce konuşulan **mantıklı atma**dır ve performansının yüksek olmayacağı açıktır. 1-NN'in eğitim kümesindeki performansı en yüksektir, ama test kümesindeki performansı hakkında bir şey söylenemez; bu tamamen veri kümesine bağlıdır. En yakın 1, 3 ya da 5 komşudan hangisinin daha iyi olacağı bilinmez; $K$ bir hiperparametredir. Algoritmanın birçok versiyonu vardır.

### 14.2 k-NN'in önemli sıkıntısı: model oluşturmaz

Avantajları esneklik ve eğitim olmamasıdır. Ama önemli bir sıkıntısı vardır: k-NN aslında bir model oluşturmaz. Daha önce, model oluşturmanın eğitim kümesini **sıkıştırmak** olduğu söylenmişti:

- Doğrusal sınıflandırıcıda test örneğinin sınıfını söylemek için yalnız $w$'ler gerekir.
- Karar ağacında yalnız ağacın kendisi gerekir.
- Yapay sinir ağında yalnız ağın kendisi gerekir.
- k-NN'de ise yeni bir test örneğinin sınıfını söylemek için **veri kümesinin kendisi** gerekir.

Burada sıkıştırma ve modelleme yoktur. Bu yüzden veri kümesi çok büyükse k-NN çok yüksek bellek gerektiren bir algoritmadır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:07:52): Kategorik değişken ne demektir? Eğitim durumu (ilkokul, ortaokul, lise, üniversite) çıkışı olan bir problem sınıflandırma mı, regresyon mu olarak ele alınmalıdır?

> **Çözüm:** Kategorik değişkenin değerleri arasında büyüklük-küçüklük ilişkisi yoktur. Eğitim durumu isim gibi görünse de sıralıdır; regresyon olarak ele almak daha doğrudur, çünkü bu, modele hataların büyüklüğünü (ilkokula ortaokul demek küçük, üniversite demek büyük hata) söyler.

**Soru 2** (ekrandan, 00:15:00): Aşağıdaki tabloda hangi özellik sınıfı tahmin etmede en iyi, hangisi en kötüdür?

| 1. Öz | 2. Öz | 3. Öz | Sınıf |
|---|---|---|---|
| 1 | 3 | 13 | A |
| 2 | 3 | 13 | B |
| 1 | 4 | 13 | A |
| 2 | 3 | 13 | B |

> **Çözüm:** 1. özellik en iyidir ("1.öz == 1 ise A, değilse B", %100). 2. özellik kısmen bilgi verir ("2.öz == 4 ise A, değilse B", %75). 3. özellik hiç bilgi vermez (her zaman B, %50).

**Soru 3** (ekrandan, 00:25:00): $\{A,A,B,B\}$, $\{A,B,A,B\}$ ve $\{C,A,D,B\}$ kümelerinin entropilerini hesaplayın. Entropi hangi özel durumda 0 ile 1 arasında değişir? Bütün topları beyaz olan bir kutunun entropisi nedir?

> **Çözüm:** $\{A,A,B,B\}$: $-(\tfrac12\log_2\tfrac12 + \tfrac12\log_2\tfrac12) = 1$. $\{A,B,A,B\}$ aynı kümedir: 1. $\{C,A,D,B\}$: $-4 \cdot \tfrac14\log_2\tfrac14 = 2$. Entropi farklı değer sayısı $c = 2$ iken 0 ile 1 arasında değişir. Tek renkli kutunun entropisi 0'dır.

**Soru 4** (ekrandan, 00:30:00): Piknik tablosunda (4 olay; hava: güneşli, güneşli, yağmurlu, güneşli; sonuç: evet, evet, hayır, evet; rüzgar hep güçlü) çıkışın entropisini, havanın ve rüzgarın piknik üzerindeki bilgi kazancını bulun.

> **Çözüm:** $E(S) = -(\tfrac34\log_2\tfrac34 + \tfrac14\log_2\tfrac14) \approx 0.811$. Hava: güneşli ve yağmurlu alt kümeleri saftır (entropi 0), $Gain = 0.811$. Rüzgar hiç değişmediği için $Gain = 0$.

**Soru 5** (derste sözlü, 00:34:37): Sinyalin gürültüye oranında $|m_1 - m_2|$'nin ve $d_1 + d_2$'nin büyük mü küçük mü olması istenir? Standart sapma neyi ifade eder?

> **Çözüm:** $|m_1 - m_2|$ büyük olmalıdır (sınıf ortalamaları uzak). Standart sapma ortalamadan sapmayı gösterir; $d_1 + d_2$ küçük olmalıdır (sınıf içi örnekler benzer).

**Soru 6** (ekrandan, 00:40:00; derste sözlü, 00:40:13): Yeşil gruplar solda, kırmızı gruplar sağda iken sinyalin gürültüye oranına göre öz1 mi, öz2 mi daha iyidir? Gruplar çapraz köşelere (XOR benzeri) yerleştirilirse ne olur? Bu iki özellikle veri sınıflandırılabilir mi?

> **Çözüm:** İlk düzende öz1 iyidir, öz2'de sınıf ortalamaları eşit olduğu için işe yaramaz. XOR benzeri düzende iki özellikte de sınıf ortalamaları eşittir, $m_1 - m_2 = 0$; filter'a göre ikisi de işe yaramaz. Oysa ikisi birlikte "öz1 < 3 ve öz2 < 2 ise yeşil" türü kurallarla veriyi tam sınıflandırır. Filter bunu söyleyemez; wrapper gerekir.

**Soru 7** (ekrandan, 01:05:00): Kohavi ve John (1997) grafiğinde wrapper boş kümeden (60) başlayıp her adımda bir özellik ekliyor. Hangi alt kümede durur? Bu hangi arama algoritmasıdır? $N$ özellik için karmaşıklığı nedir?

> **Çözüm:** 60 → {3} (70) → {1,3} (80); {1,2,3} = 79 ve {1,3,4} = 65 daha kötü olduğu için {1,3}'te durur. Algoritma tepe tırmanmadır. Deneme sayısı en fazla $N + (N-1) + \dots + 1$, yani $O(N^2)$'dir; $2^N$'den $N^2$'ye iner. Dezavantajı, {1,2} = 90 gibi daha iyi alt kümeleri hiç denemeyebilmesidir.

**Soru 8** (derste sözlü, 01:12:15): Wrapper boş kümeden başlayıp ekleyerek ve tüm özelliklerden başlayıp silerek çalıştırılırsa aynı alt kümeye varır mı?

> **Çözüm:** Varmayabilir; bu lokal aramanın doğasıdır.

**Soru 9** (ekrandan, 01:35:00): 20 örnekli X/O veri kümesinde (10.2'deki tablo) aday bölmeler $x_1 \in \{1.5, 2.5, 3.5\}$ ve $x_2 \in \{1.5, 2.5, 3.5, 4.5\}$'tir. Her bölmede iki tarafa çoğunluk sınıfı verilirse hata sayıları nedir?

> **Çözüm:** Derste $x_1$ için 1.5 → 7, 2.5 → 8, 3.5 → 7 bulundu; $x_2$ değerleri "?" bırakıldı.

> **Çözüm (derste verilmedi):** Python ile hesaplandığında $x_2 = 1.5 \to 10$, $2.5 \to 8$, $3.5 \to 6$, $4.5 \to 8$ çıkar. En az hatalı ilk bölme $x_2 = 3.5$'tir (6 hata).

**Soru 10** (derste sözlü, 01:37:29): Karar ağaçları esnek midir, yani her eğitim kümesine %100 uyum sağlayan bir karar ağacı oluşturulabilir mi?

> **Çözüm:** Evet; aynı özellik değerlerine sahip ama sınıfı farklı iki örnek olmadıkça karar ağacı her eğitim kümesini tam modelleyebilir. Bu yüzden evrensel yaklaşıklayıcıdır. Doğrusal sınıflandırıcı ise bunu yapamaz.

**Soru 11** (derste sözlü, 01:55:47): En yakın K komşu her eğitim kümesine %100 uyum sağlar mı? $K$ eğitim kümesindeki örnek sayısına eşit olursa ne olur? Test örneğini sınıflandırmak için neye ihtiyaç vardır?

> **Çözüm:** $K = 1$ için evet: her eğitim örneğinin en yakın komşusu kendisidir, eğitim başarısı %100'dür. $K = N$ olursa algoritma her zaman çoğunluk sınıfını döndürür (mantıklı atma). Sınıflandırma için veri kümesinin kendisi gerekir; k-NN model oluşturmaz, bu yüzden büyük veride çok bellek ister.

## Dersin Toparlaması

Bu derste makine öğrenmesinin ikinci bölümüne geçildi. Önce problemin sınıflandırma mı regresyon mu olduğunun, etiket adlarına göre değil çıkış değerleri arasındaki anlamlı sıralamaya göre belirlendiği vurgulandı. Ardından özellik işlemleri ele alındı. Filter yöntemleri (kategorik özellikler için entropiye dayalı bilgi kazancı, sayısal özellikler için sinyalin gürültüye oranı) her özelliği tek başına değerlendirir; bu yüzden yalnız birlikte işe yarayan özellikleri kaçırır. Wrapper yöntemleri özellik alt kümelerini sınıflandırıcı performansıyla değerlendirir ve $2^N$'lik arama uzayında tepe tırmanma ile $O(N^2)$ denemede iyi (ama en iyi olmayabilen) bir alt küme bulur. Yeni özellik çıkarımında PCA varyansı, LDA sınıf ayrılabilirliğini en büyük yapan lineer birleşimleri arar. Başarı oranlarının mantıklı atma referansıyla yorumlanması gerektiği ve No Free Lunch teoremi gereği her veride en iyi tek yöntemin olmadığı da vurgulandı.

Dersin ikinci yarısında sınıflandırma yöntemlerine geçildi: basit ve yorumlanabilir ama esnek olmayan doğrusal sınıflandırıcı; tek özellik ve tek eşikle özyinelemeli bölme yapan, eğitim kümesine tam uyabilen karar ağaçları; gradyanla lokal arama yapılarak eğitilen yapay sinir ağları ve eğitimi olmayan ama veri kümesini saklamak zorunda olan en yakın K komşu. Saflık ölçütü ve $K$ gibi hiperparametrelerin önemi ve ayarlanmalarının zorluğu tartışıldı. Hoca, bu konuların (makine öğrenmesi slaytlarının) sonraki derste tamamlanacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
