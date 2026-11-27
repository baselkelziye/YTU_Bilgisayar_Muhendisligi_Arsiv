# Ders 2 Genişletilmiş Notu: Algoritma Analizinin Temelleri, Temel İşlem ve Asimptotik Gösterime Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Algoritma Analizi?
- 2. Bir Örnek: DFT ve FFT
- 3. Yerinde ve Kararlı Algoritmalar
- 4. Bilinen Fonksiyonlar ve Zaman-Bellek Ödünleşimi
- 5. Bilimsel Yöntem ve Deneysel Analiz
- 6. Çalışma Süresini Etkileyen Etkenler
- 7. Matematiksel Model: Maliyet ve Sıklık
- 8. Temel İşlem ve Tilde Gösterimi
- 9. Büyüme Dereceleri
- 10. Seçmeli Sıralama ve Kabarcık Sıralamasının Analizi
- 11. En İyi, Ortalama ve En Kötü Durum
- 12. Algoritmalar Kuramı: Üst Sınır, Alt Sınır, Optimallik
- 13. Bir Algoritmayı Analiz Etme Yöntemi
- 14. Asimptotik Gösterimlere Giriş
- 15. Big-O Gösterimi ve Kanıt Örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Neden Algoritma Analizi?

Bir algoritmayı analiz edebilmek için önce algoritmanın ve veri yapılarının ne olduğunu bilmek gerekir. Veri yapıları, algoritmanın tek başına verimli çözemediği durumlarda programlama dillerinin sağladığı yardımcı yapılardır; en basit örnekleri dizi ve yığındır (stack). Bu ders veri yapılarını tekrar etmek için değil, onların üzerine bir şey koymak için vardır.

Dönem boyunca iki ana araç kullanılacaktır: iteratif algoritmaların analizi ve özyinelemeli (rekürsif) algoritmaların analizi. Bunlar dersin amacı değil, aracıdır. İleride görülecek tasarım yöntemleri (böl ve yönet, azalt ve yönet, dinamik programlama gibi) karşımıza ya iteratif ya da özyinelemeli bir algoritma olarak çıkar ve analiz bu iki araçla yapılır.

> **Hocanın vurgusu:** Bu derste bir soru "$O(n\log n)$ karmaşıklıkla çözün" diye soruluyorsa $n^2$'lik bir çözüm, soru 30-40 puanlıksa ancak birkaç puan getirir. Yapısal programlama seviyesinde bir çözüm beklenmez.

Bir algoritma geliştirirken önce verimliliğini garanti etmek gerekir. Verimliliğin iki kaynağı vardır: zaman ve bellek. Ders slaytları R. Sedgewick ve K. Wayne'in *Algorithms, 4th Edition* kitabının "1.4 Analysis of Algorithms" bölümünden alınmıştır; bölümün başlıkları giriş, gözlemler, matematiksel modeller, büyüme derecesi sınıfları, algoritmalar kuramı ve bellektir (ekrandan, 00:15:00). Kitabın slaytları `algs4.cs.princeton.edu` adresinde bulunur.

Algoritmanın kalitesine bakınca akla ilk gelen soru, problemi ne kadar sürede çözdüğüdür (running time). Programlamaya giriş derslerinde kodun başına ve sonuna birer zamanlayıcı koyup farkı almak bir ölçüttür, ama kalitesi sorgulanabilir: algoritma bir sunucuda, kişisel bilgisayarda ya da gömülü bir sistemde çalışabilir. İşlemci hızı, bellek hızı, veri yolu hızı farklıdır ve hangisi darboğazsa algoritma ona göre çalışır. Bir bilgisayarda bir dakika süren iş başka birinde iki dakika sürebilir; bu, sistemler arası karşılaştırmayı engeller.

Algoritmaları analiz etmenin nedenleri slaytta şöyle sıralanır: performansı tahmin etmek, algoritmaları karşılaştırmak, bir performans garantisi vermek ve algoritmaların kuramsal temelini anlamak. Bu dersin hedefi böl ve yönet, dinamik programlama gibi farklı tasarım tekniklerini öğrenmek, bunları analiz etmek ve yeni problemlere uygulamaktır. Uygulamada en sık amaç ise performans hatalarından kaçınmaktır: "sistem yavaş çalışıyor" şikâyetinin arkasında çoğu zaman veri büyüyünce maliyeti hızla artan bir işlem (örneğin birkaç tablonun kartezyen çarpımı) vardır. Küçük veride sorun çıkarmayan bir sorgu, veri büyüyünce zaman aşımına düşebilir.

Bilgisayar mühendisi olarak hedef, kullandığımız ya da tasarladığımız algoritmanın olabildiğince hızlı yanıt vermesi ve belleği etkin kullanmasıdır; kısacası kaynakları etkin kullanmaktır.

## 2. Bir Örnek: DFT ve FFT

Bir ses sinyali, örnekleme frekansı ile süresinin çarpımı kadar elemanlı bir dizidir. Dakikalarca süren bir kayıtta milyonlarca örnek bulunur. Ayrık Fourier Dönüşümü (Discrete Fourier Transform, DFT) bu diziyi zaman düzleminden frekans düzlemine geçirir.

Hoca dönüşümü tahtada önce integral olarak yazdı, sonra bilgisayarda "integral" diye bir işlem olmadığını, integralin bir toplama olduğunu hatırlatarak toplam biçimine getirdi (ekrandan, 00:25:00):

$$\sum_{n} \sum_{n} x[n]\, e^{-j 2\pi f n}$$

Bir toplam frekanslar üzerinde, öteki örnekler üzerinde döner. Bilgisayarda bu, iç içe iki `for` döngüsüdür; ikisi de $0$'dan $n$'ye gittiği için toplam $n^2$ işlem gerekir.

> **Ek bilgi (derste anlatılmadı):** DFT'nin olağan biçimi $X[k] = \sum_{n=0}^{N-1} x[n]\, e^{-j 2\pi k n / N}$, $k = 0, \dots, N-1$'dir. Her $k$ için $N$ terimli bir toplam hesaplandığından doğrudan hesap $N^2$ çarpma-toplama ister.

Hocanın sayısal örneğinde 4 dakikalık bir kayıt $4 \times 60$ saniye ve saniyede 1 milyon örnekle $240 \times 10^6$ elemanlı bir dizi olarak alındı. Bu diziyi DFT'den geçirmek $(240 \times 10^6)^2 \approx 5.8 \times 10^{16}$ işlem ister; bilgisayarın bu kadar işlemi bitirmesi çok uzun sürer. Kayıt 14 ya da 24 dakika olsaydı iş daha da uzardı.

> **Ders sonrası not:** Hoca "1 kilohertz, yani saniyede 1 milyon örnek" dedi. 1 kHz saniyede 1000 örnek demektir; $240 \times 10^6$ örnek ancak saniyede 1 milyon örnekle (1 MHz) elde edilir. Büyük olasılıkla örnek yalnızca büyüklük fikri vermek için seçilmiştir.

Bu yüzden Hızlı Fourier Dönüşümü (Fast Fourier Transform, FFT) tasarlanmıştır: aynı sonucu $n\log n$ adımda verir. Algoritma analizinin uğraştığı soru budur: bir A algoritması, verilen girdi boyutuna göre çıktıyı kaç adımda üretir ve bunu yaparken ne kadar ek bellek harcar?

Tahtadaki özet şöyledir (ekrandan, 00:35:00):

| | A (DFT) | B (FFT) |
|---|---|---|
| Adım sayısı (# steps) | $n^2$ | $n\log n$ |
| Bellek | $M(n^2)$ | $M(n^3)$ |

Bellek değerleri hocanın tartışma için rastgele seçtiği değerlerdir, gerçek değerler değildir.

## 3. Yerinde ve Kararlı Algoritmalar

Önceki derste iki kavram konuşulmuştu: yerinde (in-place) çalışma ve kararlılık (stable). Bir öğrenci bu kavramın seçmeli sıralama (selection sort) üzerinden konuşulduğunu hatırlattı.

Seçmeli sıralama, küçükten büyüğe sıralarken önce en küçük elemanın gideceği yeri belirler, kalan elemanlar arasından en küçüğü bulur ve o yere koyar; sonra ikinci en küçük, üçüncü en küçük diye devam eder. Örneğin 1, 6, 8 gibi bir dizide ilk konum için aranan en küçük eleman zaten yerindedir; ama kontrol konmazsa algoritma bu elemanı kendisiyle yer değiştirir (geçici değişkene alır, sonra geri yazar). Hoca bu gereksiz yer değiştirmeyi kararlılık konusuyla ilişkilendirdi.

> **Ders sonrası not:** Kararlılık, eşit anahtarlı elemanların sıralamadan sonra da aynı göreli sırada kalması demektir. Elemanın kendisiyle yer değiştirmesi kararlılığı etkilemez. Seçmeli sıralama, uzak mesafeli yer değiştirmeler eşit elemanların sırasını bozabildiği için kararsızdır. Kodu `if (min != i)` ile korumak yalnızca gereksiz yer değiştirmeyi önler, algoritmayı kararlı yapmaz.

Yerinde çalışma, diziyi sıralamak için dizinin büyük bir kısmının (yarısının ya da tamamının) başka bir yere kopyalanıp kopyalanmadığıyla ilgilidir. Yer değiştirme için kullanılan tek bir geçici değişken sayılmaz. Seçmeli sıralamada elemanlar yerinde kalır ve yalnızca bir `temp` değişkeni kullanılır; bu yüzden algoritma yerindedir. İleride görülecek birleştirmeli sıralama (merge sort) yerinde değildir; sonradan yerinde çalışan sürümleri de geliştirilmiştir. Belleğin kısıtlı olduğu durumlarda tek bir bellek hücresi bile önemli olabilir.

## 4. Bilinen Fonksiyonlar ve Zaman-Bellek Ödünleşimi

Analizde amaç, girdi boyutu $n$'ye göre adım sayısını (number of steps) bulmaktır. DFT'de $n^2$ iç içe iki döngüden gelir. $n\log n$'de ise bir döngü doğrusal, içteki ise logaritmik artar.

Hesapları matematikten bildiğimiz fonksiyonlar cinsinden yazarız: trigonometrik, logaritmik, polinom ve üstel fonksiyonlar. Algoritma analizinde sık kullanılanlar, büyüklük sırasıyla şunlardır (ekrandan, 00:35:00):

$$1,\ \log n,\ n,\ n\log n,\ n^2,\ n^3,\ n^4,\ \dots,\ 2^n,\ 3^n,\ \dots,\ n!,\ n^n$$

Sabit fonksiyon birim zamanı, $n\log n$ doğrusal-logaritmik (linearithmic) büyümeyi gösterir. Adım sayısı süre yerine tercih edilir: aynı bilgisayarda bile o anda başka uygulamalar çalıştığı için süre güvenilir değildir.

Aynı yaklaşım bellek için de kullanılır: algoritmanın kullandığı bellek de girdi boyutunun bir fonksiyonu olarak yazılır. Hoca şu soruyu sordu: A algoritması $n^2$ adım ve $n^2$ bellek, B algoritması $n\log n$ adım ve $n^3$ bellek kullanıyorsa hangisini seçersiniz?

**Soru:** Bu, duruma bağlı değil mi? Kişisel bilgisayarda bir ödev yaparken seçilecek algoritma ile büyük bellekli bir sistemde seçilecek algoritma farklı olabilir. **Cevap:** Evet. FFT ya da DFT gömülü sistemlerde, FPGA üzerinde, kişisel bilgisayarda ya da sunucuda kullanılabilir. Bakılması gereken şey, $n\log n$ hızını veren algoritmanın $n^3$ bellek ihtiyacının sisteme sığıp sığmadığıdır. Belleğiniz yetiyorsa hızlı olanı seçersiniz ("param varsa İstanbul'dan Ankara'ya uçakla giderim"). Kimse $n\log n$ dururken $n^2$'yi seçmez, ama diğer kriter göz ardı edilmemelidir: algoritmayı bir Raspberry Pi üzerinde çalıştıracaksanız bellek yetmeyebilir.

Örneğin 4 MB belleği olan bir sistemde 3 MB'lık bir veri işlenecekse algoritmanın kesinlikle yerinde olması ya da bellek tüketiminin buna uygun olması gerekir. Yerinde olmayan bir algoritma belki 3 MB daha ister; o yer yoktur. Ya veriyi parçalayıp işlemek ya da başka bir çözüm bulmak gerekir.

Slaytta başka bir örnek olarak $N$ cisim simülasyonu (n-body simulation) verildi: $N$ cisim arasındaki kütle çekimini kaba kuvvetle simüle etmek $N^2$ adım ister; daha yeni bir algoritma bunu daha hızlı yapar. Web tarayıcılarında birkaç sekme açıkken bilgisayarın ısınması, belleğin tükenmesi ve bellek sızıntıları da aynı türden performans sorunlarıdır.

## 5. Bilimsel Yöntem ve Deneysel Analiz

Algoritmaları karşılaştırmak için bilimsel bir çerçeve kurulabilir mi? Bilimsel yöntem şu adımlardan oluşur:

- Gerçek dünyadan gözlem yapılır.
- Gözlemlerle tutarlı bir hipotez (model) kurulur.
- Hipotezle tahminler yapılır.
- Tahminler yeni gözlemlerle doğrulanır.

Süre ölçmek bu yönteme her zaman uymaz: aynı boyuttaki girdiyle bir sunucuda ve bir gömülü sistemde tutarsız süreler alınır ve bu sürelerden bir model çıkmaz.

### 5.1 3-SUM Problemi

$N$ farklı tam sayıdan oluşan bir dizide toplamı sıfır olan kaç üçlü vardır? Slayttaki örnek dizi $30, -40, -20, -10, 40, 0, 10, 5$'tir (ekrandan, 02:30:00). Bu dizide dört üçlü vardır: $(30, -40, 10)$, $(30, -20, -10)$, $(-40, 40, 0)$, $(-10, 0, 10)$. Problem hesaplamalı geometrideki problemlerle yakından ilişkilidir. Hocanın benzetmesiyle, bir dizinin en küçük elemanını bulmak sinyal işlemede en düşük frekansı bulmak gibi bir anlam taşır; sıfır toplamlı üçlüler de uygulamada bir anlam taşır.

Kaba kuvvet (brute-force) çözümünde üç iç içe döngü yazılır. Aynı elemanın iki kez seçilmemesi için `j`, `i`'nin bir sonrasından; `k` de `j`'nin bir sonrasından başlar (ekrandan, 00:45:00):

```java
public class ThreeSum
{
   public static int count(int[] a)
   {
      int N = a.length;
      int count = 0;
      for (int i = 0; i < N; i++)
         for (int j = i+1; j < N; j++)
            for (int k = j+1; k < N; k++)
               if (a[i] + a[j] + a[k] == 0)
                  count++;
      return count;
   }
   ...
}
```

Slayttaki notlar: üç döngü "her üçlüyü kontrol eder"; basitlik için tam sayı taşması göz ardı edilir. İçteki toplama ve karşılaştırma her adımda yapılır, `count++` ise yalnızca koşul doğruysa yapılır. Toplam işlem sayısı $N \cdot N \cdot N$'ye yakındır, yani $N^3$ mertebesindedir. DFT'de 1 milyon eleman için $10^{12}$ işlem gerekiyordu; burada $10^{18}$ gerekir. Basit görünen bir problem, kaba kuvvetle yazıldığında çok geç yanıt verir.

### 5.2 Süre Ölçümü

Program farklı girdi boyutlarıyla çalıştırılıp süreler ölçülür. 1000 sayılık girdide 70 üçlü bulunduğu söylendi <!-- BELİRSİZ: 1K, 2K, 4K girdileri için slayttaki süre ve üçlü sayıları karede görülmedi; altyazıda yalnız 1K için "70" geçiyor. -->. Ardından daha ayrıntılı bir ölçüm tablosu gösterildi (ekrandan, 00:50:00):

| $N$ | süre (saniye) |
|---|---|
| 250 | 0.0 |
| 500 | 0.0 |
| 1,000 | 0.1 |
| 2,000 | 0.8 |
| 4,000 | 6.4 |
| 8,000 | 51.1 |
| 16,000 | ? |

Başlarda artış dramatik görünmez, ama 2000'den sonra $N$ iki katına çıkınca süre yaklaşık 8 katına çıkar ($0.8 \to 6.4 \to 51.1$). Sebebi $N^3$'tür: $(2N)^3 = 8N^3$. Ölçüm anında işletim sistemi devrededir ve işlemcinin ne kadarını kullanacağımız belli değildir; buna deneysel (empirical) analiz denir.

Sonuçlar $T(N)$-$N$ grafiğine dökülüp bir eğri uydurulabilir (interpolasyon). Eksenler log-log ölçeğe alınınca noktalar eğimi yaklaşık 3 olan bir doğru üzerine düşer. Bu, $\log T(N) = b \log N + c$ biçiminde bir modeldir ve $T(N) = a N^b$ anlamına gelir. Regresyonun istatistiksel testi gibi konular sayısal analizin işidir; bu derste onlarla uğraşılmaz.

Slayttaki hipotez ve doğrulama şöyledir (ekrandan, 00:55:00):

- Hipotez: çalışma süresi yaklaşık $1.006 \times 10^{-10} \times N^{2.999}$ saniyedir. Çalışma süresinin büyüme derecesi yaklaşık $N^3$'tür.
- Tahminler: $N = 8000$ için 51.0 s, $N = 16000$ için 408.1 s.
- Gözlemler: $N = 8000$ için üç ölçümde 51.1, 51.0, 51.1 s; $N = 16000$ için 410.8 s. Hipotez doğrulanır.

$16000$ için tahmin, $8000$ için süreyi $2^3 = 8$ ile çarpmaya denk gelir ($51.0 \times 8 = 408$). Girdi dört katına çıksaydı süre $4^3 = 64$ katına çıkardı.

> **Hocanın vurgusu:** Sizden böyle bir deney yapıp model bulmanız istenmeyecek. Bu yöntem bilimsel yönteme uygundur, ama sonuç makineye bağlıdır, tam (exact) bir sonuç vermez ve her kod bu kadar düzenli `for` döngülerinden oluşmaz.

Daha hassas deneyler için $N$ ikişer katına çıkarılarak (250, 500, 1000, 2000, ...) ardışık sürelerin oranı ve bu oranın logaritması alınır ("doubling hypothesis"). Oran 8'e, logaritması 3'e yaklaştığından model $aN^b$ biçiminde, $b \approx 3$ olarak tahmin edilir.

## 6. Çalışma Süresini Etkileyen Etkenler

Sistemden bağımsız etkenler algoritma ve girdi verisidir. Algoritma her sistemde aynıdır; $n$ elemanlı girdi de Windows'ta ya da başka bir işletim sisteminde aynıdır.

Sisteme bağlı etkenler ise şunlardır:

- Donanım: işlemci hızı, bellek hızı, önbellek, veri yolu. Ortam sıcaklığı bile işlemcinin hızını etkileyebilir.
- Yazılım: derleyici türü, yorumlayıcı, çöp toplayıcı (garbage collector). Örneğin çöp toplayıcı yavaş çalışıyorsa yer açılana kadar ek gecikme olur.
- Sistem: işletim sistemi, ağ ve aynı kaynakları kullanan diğer uygulamalar.

Sisteme bağlı etkiler, algoritmanın deterministik davranışını bozan bir tür "bozucu etki" (interference) gibidir. Kötü haber, kesin bir ölçüm yapmanın zor olmasıdır. İyi haber, bunu gözlemden daha ucuz ve daha kolay yoldan, matematiksel modelle yapabilmemizdir.

## 7. Matematiksel Model: Maliyet ve Sıklık

Slayttaki model şudur (ekrandan, 01:15:00):

$$\text{Toplam çalışma süresi} = \sum_{\text{tüm işlemler}} \text{maliyet} \times \text{sıklık}$$

- Programı analiz edip işlemler kümesini belirlemek gerekir.
- Maliyet makineye ve derleyiciye bağlıdır.
- Sıklık algoritmaya ve girdi verisine bağlıdır.

Bu model D. Knuth'un *The Art of Computer Programming* kitaplarında (Fundamental Algorithms, Seminumerical Algorithms, Sorting and Searching, Combinatorial Algorithms) önerilmiştir.

İşlemler kümesine toplama, çıkarma, çarpma, karşılaştırma gibi işlemler girer. **Soru:** Çarpma mı daha maliyetlidir, toplama mı? **Cevap (bir öğrenci):** Çarpma. Hoca onayladı: çarpmanın kendine ait bir maliyet birimi vardır. Karşılaştırma da çıkarmaya benzer bir işlemdir.

Slayttaki ölçümler belirli bir makinede yapılmıştır: tam sayı toplama, tam sayı çarpma, kayan noktalı toplama gibi işlemlerin nanosaniye cinsinden süreleri listelenir; kayan noktalı toplama tam sayı toplamadan daha maliyetlidir. Farklı makinelerde ölçülen değerler karşılaştırılabilir ya da ortalamaları alınabilir. Ardından temel işlemlerin maliyetleri sabitlerle gösterilir: değişken tanımı $c_1$, atama $c_2$, ..., dizi uzunluğu (`a.length`) $c_5$, tek boyutlu dizi ayırma (`new int[N]`) $c_6 N$, iki boyutlu dizi ayırma (`new int[N][N]`) $c_7 N^2$ (ekrandan, 01:20:00).

Slayttaki uyarı: ilkel olmayan işlemler genellikle sabit zamandan fazlasını alır; acemilerin hatası olarak aşırı string birleştirme örneği verilir. İlkel işlemlerin doğrudan makine kodu karşılıkları (add, div gibi) vardır, daha üst seviyeli işlemler ise daha fazla iş yapar.

### 7.1 Örnek: 1-SUM

Soru: $N$ girdi boyutuna bağlı olarak kaç komut çalışır? (ekrandan, 01:20:00)

```java
int count = 0;
for (int i = 0; i < N; i++)
   if (a[i] == 0)
      count++;
```

- Değişken tanımı (`count` ve `i`): 2 kez.
- Atama (`count = 0`, `i = 0`): 2 kez.
- `i < N` karşılaştırması: $N+1$ kez. Örneğin $0$'dan $5$'e giden bir döngüde kontrol $0, 1, 2, 3, 4$ ve $5$ için yapılır, yani 6 kez; son kontrolde döngü biter.
- `a[i] == 0` karşılaştırması: $N$ kez.
- Dizi erişimi: $N$ kez.
- Artırma: `i++` her turda yapılır, `count++` yalnızca koşul doğruysa; toplam $N$ ile $2N$ arasındadır.

Hoca tahtada toplamı kabaca hesapladı: koşula bağlı `count++` dışındaki işlemler yaklaşık $4N + 4$ eder; koşula bağlı kısmın sayısı bilinmez ama en fazla $N$'dir. Bu yüzden toplam en fazla yaklaşık $5N + 4$ işlemdir. Her işlemin sayısı yukarıdaki maliyetlerle çarpılıp toplanırsa bir maliyet elde edilir.

### 7.2 Örnek: 2-SUM

Bu kez iki iç içe döngüyle toplamı sıfır olan ikililer sayılır (ekrandan, 01:25:00):

```java
int count = 0;
for (int i = 0; i < N; i++)
   for (int j = i+1; j < N; j++)
      if (a[i] + a[j] == 0)
         count++;
```

İç döngünün toplam dönüş sayısı:

$$0 + 1 + 2 + \dots + (N-1) = \frac{1}{2} N (N-1) = \binom{N}{2}$$

Slayttaki sıklık tablosu:

| İşlem | Sıklık |
|---|---|
| değişken tanımı | $N + 2$ |
| atama | $N + 2$ |
| `<` karşılaştırması | $\tfrac12 (N+1)(N+2)$ |
| `==` karşılaştırması | $\tfrac12 N (N-1)$ |
| dizi erişimi | $N (N-1)$ |
| artırma | $\tfrac12 N (N-1)$ ile $N (N-1)$ arası |

Her `if` iki dizi erişimi yaptığı için dizi erişimi `==` karşılaştırmasının iki katıdır. Slaytta bu sayımın "tam olarak yapılmasının sıkıcı" olduğu yazar. Üstelik her sütunu maliyetle çarpıp toplasak bile sonuç yine makineye bağlı kalır.

## 8. Temel İşlem ve Tilde Gösterimi

Bir algoritma bir makinede de öbüründe de aynıdır. `i = 0` ataması her makinede yapılır ve aradaki nanosaniyelik farklar önemsizdir. Bu ayrıntılarla uğraşmak, analizin içinde boğulmak ve yine de tam sonuca ulaşamamak demektir. Bunun yerine bazı temel işlemler (basic operation) "vekil" (proxy) olarak seçilir.

Hoca derste "proxy ne demek?" diye sordu; bir öğrenci "vekil sunucu" karşılığını söyledi. Vekil işlem, algoritmanın tamamına vekâlet eden, karakteristiğinden yola çıkarak bütün algoritmanın karmaşıklığını anlayabileceğimiz işlemdir.

2-SUM kodunda döngü değişkenleriyle ilgili işlemler döngünün doğasında olduğu için atılır. Her durumda yapılan asıl iş dizi erişimleri, toplama ve karşılaştırmadır. Slaytta temel işlem olarak dizi erişimi seçilmiştir; hocaya göre karşılaştırma da seçilebilir.

> **Hocanın vurgusu:** Sınavda, ödevde ya da bir algoritma gördüğünüzde ilk sorulacak soru şudur: bu algoritmanın temel işlemi nedir?

Temel işlemin sayısı, toplam ifadesindeki en yüksek dereceli terimi verir. Slayttaki örneklerde toplamlar $\tfrac16 N^3 + 20N + 16$ ya da $\tfrac16 N^3 + 100 N^{4/3} + 56$ gibi ifadelerdir. $N$ büyüdükçe $N^3$ terimi o kadar hızlı büyür ki diğer terimler önemsiz (negligible) kalır. $N$ küçükken de karmaşıklıkla uğraşmaya gerek yoktur: iki algoritmanın grafiği bir $N_0$ noktasına kadar birbirine yakın gidebilir, fark ondan sonra önem kazanır.

### 8.1 Tilde Gösterimi

İki fonksiyonun oranının limiti alınınca üç durum vardır: limit sabit bir değer, sıfır ya da sonsuzdur. Buna göre ya üstteki büyüktür, ya alttaki büyüktür ya da ikisi aşağı yukarı aynı hızda büyür.

> **Ek bilgi (derste anlatılmadı):** Sedgewick'in tanımıyla $f(N) \sim g(N)$, $\lim_{N\to\infty} f(N)/g(N) = 1$ demektir. Örneğin $\tfrac16 N^3 + 20N + 16 \sim \tfrac16 N^3$.

Tilde gösterimiyle 2-SUM tablosu sadeleşir: değişken tanımı ve atama $\sim N$, karşılaştırmalar $\sim \tfrac12 N^2$, dizi erişimi $\sim N^2$, artırma $\tfrac12 N^2$ ile $N^2$ arası. 3-SUM'da ise iç işlem $\binom{N}{3} = \dfrac{N(N-1)(N-2)}{3!}$ kez yapılır ve her biri 3 dizi erişimi içerir; dizi erişimi sayısı yaklaşık $\tfrac12 N^3$'tür. Slayttaki sonuç: "maliyet modeli ve tilde gösterimiyle sayımları basitleştirin" (ekrandan, 01:35:00).

### 8.2 Ayrık Toplamların Tahmini

Bu hesaplar için ayrık matematikten toplam formüllerini hatırlamak gerekir. Slayttaki yöntem toplamı integralle değiştirmektir (ekrandan, 01:35:00):

$$\sum_{i=1}^{N} i \sim \int_{x=1}^{N} x\,dx \sim \frac12 N^2$$

$$\sum_{i=1}^{N} i^k \sim \int_{x=1}^{N} x^k\,dx \sim \frac{1}{k+1} N^{k+1}$$

$$\sum_{i=1}^{N} \frac1i \sim \int_{x=1}^{N} \frac1x\,dx = \ln N$$

Üç katlı toplam için de aynı fikirle $\sum_{i=1}^{N}\sum_{j=i}^{N}\sum_{k=j}^{N} 1 \sim \tfrac16 N^3$ bulunur. Hoca iç toplamdan başlayarak terim sayısını "son terim eksi ilk terim bölü artış miktarı artı bir" kuralıyla yazdı ve açılımda baştaki terimin $n^3$'lü olduğunu, diğerlerinin $n^2$ ve daha düşük terimler olduğunu gösterdi.

Bir başka örnek olarak $\sum_{i=0}^{\infty} \left(\tfrac12\right)^i$ soruldu. Geometrik seri formülüyle sonuç $\dfrac{1}{1 - \tfrac12} = 2$'dir.

> **Hocanın vurgusu:** Bu toplam formüllerini hatırlamanız iyi olur; sınavda sorulabilir. Wolfram Alpha gibi araçlar toplam sembolünü yazınca sonucu kesir olarak verir; kontrol için kullanılabilir.

Sonuçta her işlemin sıklığı ile maliyeti çarpılıp toplanınca $T(N) \sim c N^3$ gibi bir ifade bulunur. Bu algoritmaları karşılaştırmak için kullanılabilir, ama $c$ hâlâ makineye ve platforma bağlıdır.

## 9. Büyüme Dereceleri

Fonksiyonların büyümesi önemlidir, çünkü girdi büyüdükçe algoritmanın nasıl davrandığını gösterir. Slayttaki tanım şudur (ekrandan, 01:40:00): bir $c > 0$ sabiti için $f(N) \sim c\,g(N)$ ise $f(N)$'nin büyüme derecesi $g(N)$'dir.

- Baştaki katsayı yok sayılır.
- Düşük dereceli terimler yok sayılır.

Örnek: aşağıdaki kodun çalışma süresinin büyüme derecesi $N^3$'tür.

```java
int count = 0;
for (int i = 0; i < N; i++)
   for (int j = i+1; j < N; j++)
      for (int k = j+1; k < N; k++)
         if (a[i] + a[j] + a[k] == 0)
            count++;
```

Döngüler $0$'dan $N$'ye üç kez tam dönseydi de sonuç $N^3$ olurdu. Burada iç döngüler daha az döner ve sayı yaklaşık $\tfrac16 N^3$ çıkar, ama bu da $N^3$ sınıfındadır.

### 9.1 Tipik Kod Kalıpları

- **Sabit (1):** tek bir işlem, örneğin bir toplama.
- **Logaritmik ($\log N$):** `while (N > 0)` döngüsünde $N$ her adımda yarıya iniyorsa değerler $N, N/2, N/4, N/8, \dots, N/2^k$ olur. Döngü $N/2^k = 1$ olunca biter. $N = 2^k$ eşitliğinin iki tarafının 2 tabanında logaritması alınırsa $k = \log_2 N$ bulunur. Yani döngü $\log_2 N$ adımda sonlanır.
- **Doğrusal ($N$):** $0$'dan $N$'ye birer birer artan tek döngü (döngü içinde $i$'ye başka müdahale yoksa).
- **Doğrusal-logaritmik ($N\log N$):** ileride görülecek birleştirmeli sıralama.
- **Karesel ($N^2$):** iç içe iki döngü.
- **Kübik ($N^3$):** iç içe üç döngü.
- **Üstel ($2^N$):** bütün alt kümeleri deneyen kapsamlı arama (exhaustive search).

> **Ders sonrası not:** Altyazıda logaritmik döngü için "iki üzeri n defa ilerleyince bu döngü sonlanacak" geçiyor; tahtadaki hesaba göre doğrusu döngünün $\log_2 n$ adımda sonlanmasıdır.

Slaytta üstel örnek verilmediği için hoca bir şifre örneği verdi (ekrandan, 01:45:00). Yalnızca 0 ve 1'den oluşan 20 haneli bir şifrede her hane için 2 seçenek vardır, toplam $2^{20}$ farklı şifre üretilebilir. ASCII tablosundaki 256 karakter kullanılırsa her hane için 256 seçenek vardır ve $256^{20}$ farklı şifre olur. Hane sayısı $n$ olursa olasılık sayısı $2^n$ ya da $256^n$ olur; karakter kümesi sabitken bile üstel büyür, karakter kümesi büyüyünce çok daha hızlı büyür. Bu bir permütasyon (sıralı diziliş) problemidir ve kapsamlı arama ile bütün olasılıklar denenir. Aynı şekilde 5 bitlik bir sayı $00000$'dan $11111$'e kadar $2^5 = 32$ farklı biçimde yazılabilir; $2^n$ buradan gelir.

## 10. Seçmeli Sıralama ve Kabarcık Sıralamasının Analizi

Analiz için çok bilinen iki sıralama algoritması seçildi: seçmeli sıralama (selection sort) ve kabarcık sıralaması (bubble sort). İkisi de bir diziyi artan ya da azalan sırada sıralar. Bu algoritmalar programlamaya giriş seviyesindedir; eksiği olanların tamamlaması beklenir.

### 10.1 Algoritmalar

Tahtadaki kodlar şunlardır (ekrandan, 01:50:00):

```c
/* Selection Sort */
for (i = 0; i < n - 1; i++)
{
    min = i;
    for (j = i + 1; j < n; j++)
    {
        if (array[min] > array[j])
            min = j;
    }
    if (min != i)
    {
        swap = array[i];
        array[i] = array[min];
        array[min] = swap;
    }
}
```

```c
/* Bubble Sort */
for (i = 0; i < n - 1; i++)
{
    for (j = 0; j < n - i - 1; j++)
    {
        if (array[j] > array[j+1])
        {
            swap = array[j];
            array[j] = array[j+1];
            array[j+1] = swap;
        }
    }
}
```

Seçmeli sıralamada dış döngü $0$'dan başlar ve son elemana kadar gitmesine gerek yoktur: sona gelindiğinde en büyük eleman zaten yerindedir. `min` başta `i`'yi gösterir; iç döngü `i+1`'den başlayarak kalan elemanlar arasından en küçüğün indisini bulur. En küçük eleman `i` konumundaki değilse (`min != i`) iki eleman yer değiştirir. Sonra `i` bir artar ve ikinci en küçük eleman aranır.

Kabarcık sıralamasında her turda yan yana iki eleman karşılaştırılır; sol eleman sağdakinden büyükse yer değiştirir. Hocanın örneği $6, 4, 8, 2, 3, 5, 3$ dizisidir. İlk tur şöyle ilerler:

- 6 ile 4: yer değiştirir → $4, 6, 8, 2, 3, 5, 3$
- 6 ile 8: değişmez.
- 8 ile 2: yer değiştirir → $4, 6, 2, 8, 3, 5, 3$
- 8 ile 3: yer değiştirir → $4, 6, 2, 3, 8, 5, 3$
- 8 ile 5: yer değiştirir → $4, 6, 2, 3, 5, 8, 3$
- 8 ile 3: yer değiştirir → $4, 6, 2, 3, 5, 3, 8$

Tur sonunda en büyük eleman (8) ötelene ötelene en sona itilmiştir. Her turda iç döngü $n - i - 1$'e kadar gider. $n$ elemanlı dizide $n-1$ tur yapılır; sonuç $2, 3, 3, 4, 5, 6, 8$'dir.

İki algoritma karşılaştırılınca: seçmeli sıralama önce en küçüğü arar, sonra onu tek bir uzun mesafeli yer değiştirmeyle yerine koyar. Kabarcık sıralaması ise gerektikçe her adımda komşu iki elemanı yer değiştirir; yer değiştirme işlemleri çok daha fazladır. İkisinde de karşılaştırma vardır; seçmeli sıralamada karşılaştırmanın sonucu bir indis, kabarcık sıralamasında bir yer değiştirmedir.

### 10.2 Seçmeli Sıralamanın Analizi

Bütün işlemler sayılabilir, ama bunun gereksiz olduğu söylenmişti. Yer değiştirme her zaman yapılmaz; olmazsa olmaz işlem en küçük (ya da en büyük) elemanı bulmak için yapılan karşılaştırmadır. Tahtadaki belirleme (ekrandan, 02:15:00):

- Temel işlem: karşılaştırma (`array[min] > array[j]`).
- Problem boyutu: $n$ elemanlı dizi.

Dış döngü $i = 0$'dan $n-2$'ye kadar gider (döngü koşulu `i < n - 1` olduğu için $n-1$ dahil değildir). İç döngü $j = i+1$'den $n-1$'e kadar gider. Karşılaştırma bir birimlik işlemdir:

$$T_1(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} 1$$

İç toplamda $j$'ye bağlı bir şey olmadığı için terim sayısı ile 1 çarpılır. Terim sayısı $(n-1) - (i+1) + 1 = n - i - 1$'dir:

$$T_1(n) = \sum_{i=0}^{n-2} (n - i - 1) = \sum_{i=0}^{n-2} n - \sum_{i=0}^{n-2} i - \sum_{i=0}^{n-2} 1$$

Toplamların her biri $n-1$ terimlidir. $\sum_{i=1}^{n} i = \dfrac{n(n+1)}{2}$ formülü kullanılırsa:

$$T_1(n) = n(n-1) - \frac{(n-2)(n-1)}{2} - (n-1)$$

Açılırsa:

$$T_1(n) = \frac{2n^2 - 2n - (n^2 - 3n + 2) - 2n + 2}{2} = \frac{n^2 - n}{2} = \frac{n(n-1)}{2}$$

Hoca tahtada payda eşitlerken birkaç işaret hatası yaptı, öğrencilerden kontrol etmelerini istedi ve sonunda $\dfrac{n(n-1)}{2}$ sonucuna ulaştı. Bu sonuç $n = 5$ için 10, $n = 10$ için 45 karşılaştırma verir; doğrudan sayımla aynıdır (ara adımlar python ile kontrol edildi).

### 10.3 Kabarcık Sıralamasının Analizi

Temel işlem yine karşılaştırmadır (`array[j] > array[j+1]`). Dış döngü $i = 0$'dan $n-2$'ye, iç döngü $j = 0$'dan $n - i - 2$'ye gider:

$$T_2(n) = \sum_{i=0}^{n-2} \sum_{j=0}^{n-i-2} 1 = \sum_{i=0}^{n-2} (n - i - 2 - 0 + 1) = \sum_{i=0}^{n-2} (n - i - 1)$$

Bu, seçmeli sıralamada bulunan ifadenin aynısıdır; yeniden çözmeye gerek yoktur:

$$T_2(n) = \frac{n(n-1)}{2}$$

Temel işlem cinsinden $T_1(n)$ ile $T_2(n)$ aynıdır ve ikisi de $n^2$'li bir fonksiyondur; düşük dereceli terimler ihmal edilirse $n^2$ mertebesindedir. Seçmeli sıralamanın daha uzun mesafeli yer değiştirme yaptığı için kısmen daha iyi çalışması, dizideki elemanların dağılımıyla ilgilidir; bu en iyi ve en kötü durum analiziyle ele alınacaktır.

### 10.4 İyileştirilmiş Kabarcık Sıralaması

Algoritmanın işlemleri iyileştirilemese de algoritmik bir iyileştirme yapılabilir. Fikir şudur: bir tur boyunca hiç yer değiştirme yapılmazsa dizi sıralanmış demektir ve kalan turlara gerek yoktur. Bunu anlamak için bir bayrak (flag) değişkeni kullanılır: tur başında 0 yapılır, yer değiştirme olursa 1 yapılır. Tur sonunda hâlâ 0 ise algoritma durur.

Bu kontrolü `for` döngüsünün koşuluna da koymak mümkündür (`//for(i=0;swapped && i<MAX;i++)`), ama hoca `while` döngüsünü daha uygun buldu. Hocanın önceden hazırladığı kod (ekrandan, 02:25:00):

```c
swapped = 1;   /* kodun üstüne elle yazıldı */
while (swapped && i < MAX) {
    swapped = 0;
    for (j = 0; j < MAX - i - 1; j++) {
        if (dizi[j] < dizi[j+1]) {
            tmp = dizi[j];
            dizi[j] = dizi[j+1];
            dizi[j+1] = tmp;
            swapped = 1;
        }
    }
    i++;
}
```

Döngüye girmeden önce `swapped` 1 yapılır ki en az bir tur kontrol edilsin. Aynı kod `do-while` ile de yazılabilir; hocanın dosyasında bu sürüm yorum satırı olarak duruyordu:

```c
do {
    swapped = 0;
    for (j = 0; j < MAX - i - 1; j++) {
        if (dizi[j] < dizi[j+1]) {
            tmp = dizi[j];
            dizi[j] = dizi[j+1];
            dizi[j+1] = tmp;
            swapped = 1;
        }
    }
    i++;
} while (swapped && i < MAX);
```

> **Ders sonrası not:** Ekrandaki koşul `dizi[j] < dizi[j+1]` olduğu için bu kod diziyi büyükten küçüğe sıralar. Kod derlenip $6, 4, 8, 2, 3, 5, 3$ dizisiyle denendiğinde sonuç $8, 6, 5, 4, 3, 3, 2$ çıktı. Küçükten büyüğe sıralamak için koşul `dizi[j] > dizi[j+1]` olmalıdır. Küçükten büyüğe sürüm sıralı bir girdide tek turda, $n-1$ karşılaştırmayla bitti.

Kuramsal olarak döngü sınırları önceki algoritmayla aynıdır ($i = 0$'dan $n-1$'e, $j = 0$'dan $n-i-2$'ye). Fark şudur: dizinin içindeki değerlerin dağılımı artık $T(n)$'yi etkiler. Bazı girdilerde yer değiştirmeye gerek kalmaz ve algoritma erken biter. Bu yüzden $T(n)$ tek bir fonksiyon değil, üç durumdan biridir (ekrandan, 02:25:00):

- En iyi durum (best case): en az kaç karşılaştırma gerekir?
- Ortalama durum (average case): ortalama kaç karşılaştırma gerekir?
- En kötü durum (worst case): en fazla kaç karşılaştırma gerekir?

Genellikle kendimizi en kötü duruma göre ayarlarız: dizinin değerlerine bakmadan en kötü durum için $T(n)$ kurulur ve algoritmalar bununla kıyaslanır.

## 11. En İyi, Ortalama ve En Kötü Durum

### 11.1 Sıralı Arama

**Soru:** $n$ elemanlı bir dizide sıralı aramada en kötü durumda kaç kontrol yapılır? **Cevap (bir öğrenci):** $n$ kez. **Soru:** Elemanların tekrar etmediği kabul edilirse en iyi durum nedir? **Cevap (bir öğrenci):** Bir kez, yani aranan eleman ilk bakılan elemandır.

En kötü durumda aranan eleman dizinin sonundadır ya da hiç yoktur. Sıralama algoritmalarında olduğu gibi arama algoritmalarında da en kötü durum esas alınır.

### 11.2 İkili Arama

İkili arama (binary search) bir ön koşul ister: dizi sıralı olmalıdır. Elemanlar tek tek aranmaz; ortadaki elemana bakılır. Aranan eleman ortadakinden büyükse sağ yarıya, küçükse sol yarıya geçilir ve orta eleman güncellenir. Böylece arama uzayı her adımda yarıya iner: önce $n/2$, sonra kalanın yarısı elenir.

Başta `lo = 0`, `hi = n - 1` ve `mid = (0 + n - 1) / 2`'dir. Eleman dizide varsa en kötü durumda $\log n$ adımda bulunur; yoksa en sona kadar bakılıp yaklaşık $\log n + 1$ kontrol yapılır. Örneğin 1024 elemanlı bir dizide $1024 = 2^{10}$ olduğundan en kötü durumda 10 adımda sonuca ulaşılır. Sıralı arama aynı dizide 1024 kontrol yapabilir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki çözümleme, ikili aramanın en kötü durumda yaptığı karşılaştırma sayısını $T(N) \le T(N/2) + 1$, $T(1) = 1$ yinelemesiyle verir. Yineleme ardışık uygulanınca $T(N) \le T(N/N) + 1 + \dots + 1 = 1 + \lg N$ bulunur (ekrandan, 02:30:00). Özyinelemeli analiz ilerleyen derslerde ayrıca işlenecektir.

**Soru:** İkili aramada en iyi durum nedir? Derste soru birkaç öğrenciye yöneltildi, sonra hoca cevapladı. **Cevap:** En iyi durumda eleman tek denemede bulunur: ilk bakılan eleman ortadaki elemandır ve aranan eleman odur. Sıralı aramada ise ilk bakılan eleman sıfırıncı elemandır.

> **Hocanın vurgusu:** İkili aramada ilk ya da son elemanı aramak en iyi durum değildir; tam tersine en kötü durumlardandır, çünkü ortadan başlayıp sağa ya da sola ilerlenir. En iyi durum ortadaki elemanın aranan eleman olmasıdır.

### 11.3 3-SUM için $N^2 \log N$ Algoritması

Sıralamanın ne işe yaradığı sık sorulur; 3-SUM bunun güzel bir örneğidir. Slayttaki algoritma (ekrandan, 02:30:00):

- Adım 1: $N$ (farklı) sayıyı sırala.
- Adım 2: her $a[i]$, $a[j]$ çifti için ikili aramayla $-(a[i] + a[j])$ ara.

Örnek girdi $30, -40, -20, -10, 40, 0, 10, 5$ sıralanınca $-40, -20, -10, 0, 5, 10, 30, 40$ olur. Sonra çiftler için arama yapılır:

- $(-40, -20)$: $60$ aranır, yok.
- $(-40, -10)$: $50$ aranır, yok.
- $(-40, 0)$: $40$ aranır, var.
- $(-40, 5)$: $35$ aranır, yok.
- $(-40, 10)$: $30$ aranır, var.

Çözümleme: adım 1 ekleme sıralamasıyla (insertion sort) $N^2$, adım 2 ikili aramayla $N^2 \log N$ sürer. Toplam büyüme derecesi $N^2 \log N$'dir. Kaba kuvvet $N^3$ iken sıralama ve ikili aramanın birleşimiyle $N^2 \log N$'e inilir. Deneyde $N = 8000$ için kaba kuvvet 51.1 saniye sürerken bu algoritma 0.96 saniye sürer; $N$ büyüdükçe fark daha da açılır.

> **Ders sonrası not:** Hoca, sıralama için daha iyi bir algoritma kullanılırsa toplamın $n \log^2 n$ gibi bir değere inebileceğini söyledi. Sıralama $N \log N$'e inse bile ikinci adım ($\tfrac12 N^2$ çift, her biri için $\log N$'lik ikili arama) değişmez; bu yüzden toplam yine $N^2 \log N$ olur.

### 11.4 Üç Durumun Tanımı

Bir algoritma analizinde üç durumla karşılaşılır. Durumlar yalnızca dizilerle sınırlı değildir; üzerinde çalışılan her verinin dağılımıyla ilgilidir. Ayrıntısı bir sonraki derste ekleme sıralaması üzerinden işlenecektir.

- **En iyi durum:** algoritmanın olabilecek en iyi çalışmasıdır ve bir alt sınır (lower bound) verir. Sıralı aramada 1, ikili aramada 1 karşılaştırma.
- **En kötü durum:** üst sınırı (upper bound) verir. Algoritmayı üstten saran bilinen bir fonksiyon en kötü durumu gösterir. Sıralı aramada $n$, ikili aramada yaklaşık $\log n$.
- **Ortalama durum:** aradaki durumlardır, rastgele girdiye karşılık gelir.

**Soru:** Sıralamada verinin dağılımı açısından en kötü durum nedir? **Cevap (bir öğrenci):** Küçükten büyüğe sıralayacaksak verinin büyükten küçüğe gelmesi. Hoca onayladı: ters sıralı girdi gerçekten en kötü durumdur; sürekli kontrol ve sürekli yer değiştirme yapılır. Beklenen sırada gelen girdi en iyi durumdur. Kabarcık ve seçmeli sıralama için en kötü durumda $n^2$ mertebesinde temel işlem yapılır; algoritma en iyi ve en kötü durum arasında bir yerde çalışır.

Aramada ortalama durum şöyle hesaplanır: elemanı birinci denemede bulma olasılığı, ikinci denemede bulma olasılığı, ..., $n$'inci denemede bulma olasılığı ve hiç bulamama olasılığı dikkate alınır; bunlardan $n$'ye bağlı bir ifade elde edilir.

**Soru:** Birleştirmeli sıralamanın en kötü durumu nedir? **Cevap (bir öğrenci):** $n\log n$. Hoca doğruladı. Hızlı sıralamada (quicksort) ise en kötü durum $n^2$'dir: pivot öyle seçilir ki sürekli yer değiştirmeyle uğraşılır. Bu, böl ve yönet konusunda tekrar ele alınacaktır.

Kaba kuvvet 3-SUM'da üç döngü her durumda tam döner, yani en iyi ve en kötü durum aynıdır. Slayttaki karşılaştırmada kaba kuvvet 3-SUM için ortalama ve en kötü durum $\sim \tfrac12 N^3$ dizi erişimi, ikili arama için $\sim \lg N$ karşılaştırmadır (ekrandan, 02:45:00).

> **Hocanın vurgusu:** Ortalama durum, en iyi ile en kötü durumun ortalaması değildir. Bazı kaynaklarda ortalama durum için "(en iyi + en kötü) / 2" denir, bu yanlıştır. Ortalama durum, probleme göre olasılıklarla ayrıca hesaplanır ve büyük problemlerde hesaplaması kolay değildir.

## 12. Algoritmalar Kuramı: Üst Sınır, Alt Sınır, Optimallik

Slayttaki özet (ekrandan, 02:45:00):

- Hedefler: bir problemin "zorluğunu" belirlemek ve "optimal" algoritmalar geliştirmek.
- Yaklaşım: analizde ayrıntıları bastırmak, yani sabit çarpana kadar analiz etmek; girdi modelindeki değişkenliği ortadan kaldırmak, yani en kötü duruma odaklanmak.
- Üst sınır: algoritmanın her girdi için performans garantisi.
- Alt sınır: hiçbir algoritmanın daha iyisini yapamayacağının kanıtı.
- Optimal algoritma: alt sınır = üst sınır (sabit çarpana kadar).

Hoca üst sınırı şöyle örnekledi: sıralama algoritmalarının en kötü durumunun $n^2$ olduğunu biliyoruz. Ek dizi kullanmayan ve en kötü durumda $n$ adımda sıralayan bir algoritma tasarlayıp yayımlarsanız "adınız tarihe altın harflerle yazılır"; söylediğiniz şey algoritmanızın üst sınırıdır. Bir sınıfta herkes aynı probleme bir algoritma geliştirse, her biri en kötü çalışma durumunu, yani üst sınırını söyleyecektir.

Alt sınır ise algoritmanın bundan daha az bir işle çalışamayacağını söyler. Karşılaştırmaya dayalı bir sıralamada temel işlem karşılaştırmaysa en az $n$ karşılaştırma gerekir: dizinin üzerinden en az bir kez geçmek zorundayız (kabarcık sıralamasındaki bir tur gibi). Üst sınır ile alt sınır ne kadar örtüşürse algoritma o kadar optimaldir. Alt sınırı $n$, üst sınırı $n^4$ olan bir algoritma tam optimal değildir.

## 13. Bir Algoritmayı Analiz Etme Yöntemi

Bir ödevde yazılan kod genellikle üç bölümden oluşur: girdi okuma, kodun algoritmik çekirdeği ve çıktı (dosyaya yazma, grafik arayüz). Girdi ve çıktı kısımları herkesin yaptığı işlerdir ve bu dersin kapsamında değildir. Analiz yalnızca algoritmik çekirdek için yapılır:

- Problemi belirleyin (örneğin bir çizge problemi).
- Temel işlemi belirleyin.
- Problem boyutunu (girdi boyutunu) belirleyin: $n$ elemanlı bir dizi, $n \times n$'lik bir matris, $V$ düğüm ve $E$ kenarlı bir çizge ya da bir ağaç.
- Temel işlemin sayısını problem boyutuna bağlı bir fonksiyon $T(n)$ olarak yazın.

> **Hocanın vurgusu:** "Burada $0$'dan $n-1$'e bir döngü var, içinde de kabaca $n$'lik bir döngü var, demek ki $O(n^2)$" demek istenmez. Temel işlem belirtilmeli ve bu derste yapılan toplam analizine benzer bir analiz yapılmalıdır.

Şimdilik bu yöntem iteratif algoritmalar için uygulanıyor; ayrıntısı sonraki derste işlenecek.

## 14. Asimptotik Gösterimlere Giriş

$T(n)$ bulunduktan sonra bazı budamalar yapılır, çünkü $n$ sonsuza giderken bazı ayrıntılar önemini kaybeder. Örneğin $T(n) = n^3 + 3n^2 + n + 5$ fonksiyonunun limiti $n^3$'ün limitiyle başa baş gider. $n$'nin büyük değerleri için bu fonksiyonu en iyi temsil eden $n^3$'tür; algoritma zaten $n^3$'lüdür ve alt terimleri yazmaya gerek yoktur.

$T(n)$'den yola çıkarak en iyi, en kötü ve ortalama durumu ortak bir dille, üst sınır, alt sınır ve sıkı sınır olarak gösteren asimptotik gösterimler kullanılır. $T(n)$ algoritmanın bulunan fonksiyonu, $f(n)$ ise $1, \log n, n, n\log n, n^2$ gibi bilinen fonksiyonlardan biri olsun. Tahtadaki özet (ekrandan, 03:15:00):

| Gösterim | Yazılış | Kabaca anlamı | |
|---|---|---|---|
| Big-O | $T(n) \in O(f(n))$ | $T(n) \le f(n)$ | üst sınır |
| Little-o | $T(n) \in o(f(n))$ | $T(n) < f(n)$ | |
| Big-Omega | $T(n) \in \Omega(f(n))$ | $T(n) \ge f(n)$ | alt sınır |
| Little-omega | $T(n) \in \omega(f(n))$ | $T(n) > f(n)$ | |
| Big-Theta | $T(n) \in \Theta(f(n))$ | $T(n) \approx f(n)$ | sıkı sınır |

Buradaki eşitsizlikler büyüme hızları arasındaki ilişkiyi kabaca anlatır; kesin tanımlar bir sonraki bölümde ve sonraki derste verilir. Big-O, algoritmanın en kötü ihtimalle $f(n)$ gibi davranacağını söyler. Big-Omega ise algoritmanın en az $f(n)$ kadar iş yapacağını, yani alt sınırı söyler. En çok $O$, $\Omega$ ve $\Theta$ kullanılır; "küçük" gösterimler pek kullanılmaz. Theta'nın küçük harfli bir karşılığı yoktur.

$\Theta$, $O$ ile $\Omega$'nın kesişimidir. Bir algoritma hem $O(n^2)$ hem $\Omega(n^2)$ ise $\Theta(n^2)$'dir. Temel işlemin sıklığı hakkında en kesin bilgiyi $\Theta$ verir: algoritma $n^2$'den aşağı da yukarı da gitmez. $T(n)$, $n^2 + 3n + 5$ ya da $n^2 - 5n - 7$ olabilir; ikisi de $\Theta(n^2)$'dir.

### 14.1 Asimptotik Analiz ve Büyüme Sırası

Matematikte asimptot, bir fonksiyonun yatayda, düşeyde ya da eğik olarak sonsuza giderken yaklaştığı doğrudur. Burada sonsuza giden şey $n$'dir: girdi çok büyüdüğünde ne olduğuna bakılır.

Slaytta bilinen fonksiyonların farklı girdi boyutları için değerleri bir tabloda verildi. Hocanın okuduğu değerlere göre $n = 10$ için $\log_2 n \approx 3.3$, $n \log_2 n \approx 33$ birim zamandır; $n$ 10'dan 100'e çıkınca $\log n$ yaklaşık iki katına çıkarken $2^n$ yaklaşık $10^3$'ten yaklaşık $10^{30}$'a çıkar <!-- BELİRSİZ: tablonun tamamı karede görülmedi; değerler altyazıdan alındı. -->. $n!$ daha da hızlı büyür.

**Soru:** En yavaş büyüyen fonksiyon hangisidir? Bir öğrenci önce $n$ dedi, sonra başka bir öğrenci sabit fonksiyon dedi. **Cevap:** Sabit fonksiyon (1). Sıralama şöyledir (ekrandan, 03:30:00):

$$1 \ll \log_2 n \ll n \ll n \log n \ll n^2 \ll n^3 \ll \dots \ll 2^n \ll 3^n \ll \dots \ll n!$$

Örneğin 1024 elemanlı sıralı bir dizide sıralı arama 1024 deneme yaparken ikili arama 10 denemede biter; $\log n$, $n$'den çok çok küçüktür. $n!$'den sonra $n!^{n!}$ gibi fonksiyonlar da yazılabilir, ama şimdiye kadar böyle bir problemle uğraşılmadı.

## 15. Big-O Gösterimi ve Kanıt Örnekleri

### 15.1 Tanım

Big-O gösterimi asimptotik üst sınırdır. Tahtadaki tanım (ekrandan, 03:30:00):

$$T(n) \le c \cdot f(n), \quad c > 0,\ n_0 > 0 \ \text{ise}\ \ T(n) \in O(f(n))$$

Tahtaya ayrıca "$c$, $n_0$: integer" ve kutu içinde "for all $n > 0$" yazıldı.

> **Hocanın vurgusu:** Sınavda bir algoritmanın üst sınırı sorulduğunda yalnızca $T(n) = n^2$ yazmak yetmez; $O(n^2)$, $O(n^3)$, $O(n\log n)$, hangisiyse onu yazmanız gerekir.

Tanımı yorumlaması istenen bir öğrenci şunu söyledi: $T(n)$, bir katsayı ile $f(n)$'nin çarpımından küçük ya da eşitse $T(n) \in O(f(n))$'dir; katsayı ve $n_0$ sıfırdan büyük tam sayılardır. Hoca bunu doğru buldu ve şu noktaları ekledi:

- $n_0 > 0$ ve tam sayı olduğundan en az 1'dir; ayrıca "$n_0 \ge 1$" yazmaya gerek yoktur.
- Girdi boyutu negatif olamaz; en az bir elemanlı bir dizi üzerinde çalışılır. Bazı kitaplarda bu ayrıca yazılır.
- Kitaplarda $c$ ve $n_0$ için "tanık" (witness) ya da "there exist positive constants" ifadeleri geçer.
- $T(n) \in O(f(n))$ olmasının tek şartı, bir $c$ ve bir $n_0$ bulmaktır; öyle ki $n_0$'dan büyük değerler için eşitsizlik sağlansın. Eşitsizliğin bütün $n$ değerleri için sağlanması gerekmez; tek bir $(c, n_0)$ örneği bulmak yeterlidir.
- Hiçbir $c$ bulunamaması, $T(n)$'nin $f(n)$'den daha hızlı büyüdüğü anlamına gelir. Örneğin $T(n) = n^3$ ve $f(n) = n^2$ ise $n = 1$'de ikisi eşittir, ama $n = 2$'den sonra $n^3$ hep baskın çıkar; $n^3$, $O(n^2)$ değildir.

> **Ders sonrası not:** Standart tanımda $c$ herhangi bir pozitif gerçel sabittir, tam sayı olması gerekmez. Eşitsizliğin "her $n > 0$ için" değil, yalnızca "$n \ge n_0$ olan her $n$ için" sağlanması gerekir; $n_0$'ın anlamı da budur. Tanım şöyle yazılır: $T(n) \in O(f(n)) \iff \exists\, c > 0,\ n_0 > 0:\ T(n) \le c\,f(n)\ \ \forall n \ge n_0$.

Grafik yorumu şöyledir: $T(n)$ bir eğri olsun. Bir $n_0$ noktasından sonra bu eğriyi üstten saran bir $c \cdot f(n)$ fonksiyonu bulunabiliyorsa $f(n)$ bir üst sınırdır. $c \cdot f(n)$, $n_0$'dan önce zaman zaman $T(n)$'nin altında kalabilir; önemli olan $n_0$'dan sonrasıdır. Bunun sezgisi sıralama algoritmalarıyla verildi: iki elemanlı bir dizi için $n^2$'lik bir algoritma hem yazması hem çalışması açısından belki daha kolaydır, ama eleman sayısı arttıkça $n\log n$'lik algoritma çok öne geçer. $n_0$ bu ayrışmanın başladığı noktadır.

### 15.2 Örnek: $\tfrac12 n^2 - 3n \in O(n^2)$

Tanım işletilerek gösterilir (ekrandan, 03:35:00):

$$\frac12 n^2 - 3n \le c \cdot n^2$$

Kesirle çalışmak zor olduğundan payda eşitlenir:

$$\frac{n^2 - 6n}{2} \le c \cdot n^2 \quad\Longrightarrow\quad n^2 - 6n \le 2c \cdot n^2$$

$c = 1$ seçilirse $n^2 - 6n \le 2n^2$, yani $-n^2 \le 6n$ olur. $n$ pozitif olduğundan iki taraf $n$'ye bölünebilir: $-n \le 6$. $n$'nin bütün pozitif değerlerinde sol taraf negatif olduğu için bu eşitsizlik her zaman doğrudur. Böylece $c = 1$ ile şart sağlanır ve $\tfrac12 n^2 - 3n \in O(n^2)$'dir.

### 15.3 Örnek: $3n^2 - 100n + 6$

Soru: $3n^2 - 100n + 6$, $O(n^2)$'nin elemanı mıdır? $O(n^3)$'ün? $O(n)$'nin? Bunlar kanıtlanacaksa tanım bu şekilde işletilmelidir.

$n^2$'li bir fonksiyonun $n^2$ de, $n^3$ de üst sınırıdır. $n$ ise üst sınır olamaz: hiçbir $c$ bulunamaz, çünkü $n$ arttıkça $n^2$'li bir ifade $n$'li bir ifadeden her zaman hızlı büyür; $n$ olsa olsa bir alt sınırdır.

Üst sınır için aday bulmanın pratik yolu tahtada şöyle verildi (ekrandan, 03:40:00):

- Sabitleri sil.
- Düşük dereceli terimleri sil.
- Katsayıları sil.

Geriye $n^2$ kalır. Bu algoritmayı yayımlayıp tanıtacak olsanız üst sınırı için en az $O(n^2)$ demeniz gerekir ve bunu kanıtlarsınız:

$$3n^2 - 100n + 6 \le c \cdot n^2$$

$c = 3$ seçilirse:

$$3n^2 - 100n + 6 \le 3n^2 \quad\Longrightarrow\quad 6 \le 100n$$

$3n^2$ terimleri birbirini götürür ve $100n$ karşıya atılır; $n$ pozitif olduğu için eşitsizliğin yönü değişmez. $n = 0$ için eşitsizlik sağlanmaz, ama $n = 1, 2, 3, \dots$ için hep sağlanır. $n_0$ seçmenin amacı da budur. $n_0 = 1$ ve $c = 3$ ile eşitsizlik tutarlıdır; bu yüzden $3n^2 - 100n + 6 \in O(n^2)$'dir.

Aynı fonksiyona $O(n^3)$ denebilir mi? Matematiksel olarak evet: $n^2$ için bir $c$ bulunduysa $n^3$ için haydi haydi bulunur. Örneğin $3n^2 - 100n + 6 \le c\,n^3$ eşitsizliği $n_0 = 4$ ve $c = 1$ ile sağlanır. Ama bu makul müdür?

**Soru:** Bu algoritmaya $O(n^3)$ demek doğru mu? **Cevap (bir öğrenci):** Değil, çünkü $n^2$ zaten sağlıyor ve $n^3$ çok daha büyük. Hoca onayladı: algoritmanın en kötü durumu zaten $n^2$ iken $n^3$ demek algoritmayı olduğundan kötü göstermektir. Matematiksel olarak $n^3$, $n^4$ ya da $2^n$ demek doğrudur, ama olabilecek en makul üst sınır $n^2$'dir. $n^2$'nin altındaki $n\log n$ ise olmaz; $n^2$ her zaman $n\log n$'den hızlı büyüdüğü için bir $c$ bulunamaz. Aynı şekilde $O(n\log n)$ ya da $O(\log n)$ için de $c$ bulunamaz.

> **Hocanın vurgusu:** Bulmak kolaydır, çünkü tek bir örnek göstermek yeterlidir. Bulamadığınızı göstermek ise ek matematiksel işlemler gerektirir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00). A algoritması (DFT) $n^2$ adım ve $M(n^2)$ bellek, B algoritması (FFT) $n\log n$ adım ve $M(n^3)$ bellek kullanıyor. Hangisini kullanırsınız?

> **Çözüm (derste verildi):** Sisteme bağlıdır. Bellek yetiyorsa daha hızlı olan B seçilir. Bellek kısıtlı bir sistemde (gömülü sistem, Raspberry Pi) B'nin bellek ihtiyacı sığmayabilir; o zaman A ya da yerinde çalışan başka bir çözüm gerekir.

**Soru 2** (ekrandan, 02:30:00). $30, -40, -20, -10, 40, 0, 10, 5$ dizisinde toplamı sıfır olan kaç üçlü vardır? Kaba kuvvet algoritmasının ve sıralama + ikili arama algoritmasının büyüme derecesi nedir?

> **Çözüm (derste verildi):** Dört üçlü vardır: $(30, -40, 10)$, $(30, -20, -10)$, $(-40, 40, 0)$, $(-10, 0, 10)$ (kaba kuvvet kodu derlenip çalıştırılarak doğrulandı). Kaba kuvvet $N^3$, sıralama + ikili arama $N^2 \log N$'dir.

**Soru 3** (ekrandan, 00:50:00 ve 00:55:00). Deneysel ölçümde $N = 8000$ için süre 51.1 saniye ve algoritmanın büyüme derecesi $N^3$ ise $N = 16000$ için süre ne olur?

> **Çözüm (derste verildi):** $N$ iki katına çıkınca süre $2^3 = 8$ katına çıkar: yaklaşık $51 \times 8 \approx 408$ saniye. Hipotez 408.1 s tahmin eder, gözlenen değer 410.8 s'dir.

**Soru 4** (ekrandan, 01:20:00). Aşağıdaki kodda, $N$ girdi boyutuna bağlı olarak her işlem kaç kez çalışır?

```java
int count = 0;
for (int i = 0; i < N; i++)
   if (a[i] == 0)
      count++;
```

> **Çözüm (derste verildi):** Değişken tanımı 2, atama 2, `<` karşılaştırması $N+1$, `==` karşılaştırması $N$, dizi erişimi $N$, artırma $N$ ile $2N$ arası. Toplam en fazla yaklaşık $5N + 4$ işlem.

**Soru 5** (derste sözlü, 01:37:46). $\sum_{i=0}^{\infty} \left(\tfrac12\right)^i$ toplamı kaçtır?

> **Çözüm (derste verildi):** Geometrik seri: $\dfrac{1}{1 - \tfrac12} = 2$.

**Soru 6** (ekrandan, 01:45:00). Yalnızca 0 ve 1'den oluşan 20 haneli kaç farklı şifre vardır? 256 karakterli ASCII kümesiyle 20 haneli kaç farklı şifre vardır? 5 bitlik kaç farklı sayı yazılabilir?

> **Çözüm (derste verildi):** $2^{20} = 1\,048\,576$; $256^{20}$; $2^5 = 32$. Hane sayısı $n$ olunca olasılık sayısı üstel büyür ($2^n$, $256^n$).

**Soru 7** (ekrandan, 02:15:00 ve 01:50:00). Seçmeli sıralama ve kabarcık sıralaması için temel işlem karşılaştırma, problem boyutu $n$ ise $T_1(n)$ ve $T_2(n)$ nedir?

> **Çözüm (derste verildi):** $T_1(n) = \sum_{i=0}^{n-2}\sum_{j=i+1}^{n-1} 1 = \sum_{i=0}^{n-2}(n-i-1) = \dfrac{n(n-1)}{2}$. $T_2(n) = \sum_{i=0}^{n-2}\sum_{j=0}^{n-i-2} 1 = \dfrac{n(n-1)}{2}$. Örneğin $n = 7$ için ikisi de 21 karşılaştırma yapar (kodlar derlenip $6, 4, 8, 2, 3, 5, 3$ dizisiyle sayıldı).

**Soru 8** (derste sözlü, 02:25:39 ve 02:34:25). $n$ elemanlı bir dizide sıralı aramanın en iyi ve en kötü durumu nedir? İkili aramanın en iyi durumu nedir?

> **Çözüm (derste verildi):** Sıralı arama: en iyi 1 (eleman ilk konumda), en kötü $n$ (eleman sonda ya da yok). İkili arama: en iyi 1 (aranan eleman ortadaki elemandır), en kötü yaklaşık $\log_2 n + 1$.

**Soru 9** (derste sözlü, 02:39:53 ve 02:42:03). Sıralamada verinin dağılımı açısından en kötü durum nedir? Birleştirmeli sıralama ve hızlı sıralamanın en kötü durumları nedir?

> **Çözüm (derste verildi):** Küçükten büyüğe sıralarken ters sıralı (büyükten küçüğe) girdi en kötü durumdur. Birleştirmeli sıralamanın en kötü durumu $n\log n$, hızlı sıralamanınki $n^2$'dir.

**Soru 10** (derste sözlü, 03:19:21). Sık kullanılan fonksiyonları büyüme hızına göre sıralayın; en yavaş büyüyen hangisidir?

> **Çözüm (derste verildi):** En yavaş büyüyen sabit fonksiyondur: $1 \ll \log n \ll n \ll n\log n \ll n^2 \ll n^3 \ll 2^n \ll 3^n \ll n!$.

**Soru 11** (ekrandan, 03:35:00). $T(n) = \tfrac12 n^2 - 3n \in O(n^2)$ olduğunu gösterin.

> **Çözüm (derste verildi):** $\tfrac12 n^2 - 3n \le c\,n^2 \Rightarrow n^2 - 6n \le 2c\,n^2$. $c = 1$ ile $-n^2 \le 6n$, yani $-n \le 6$; her pozitif $n$ için doğrudur.

**Soru 12** (ekrandan, 03:40:00). $3n^2 - 100n + 6$ fonksiyonu $O(n^2)$, $O(n^3)$, $O(n)$ sınıflarından hangilerine aittir? En makul üst sınır hangisidir?

> **Çözüm (derste verildi):** $c = 3$, $n_0 = 1$ ile $3n^2 - 100n + 6 \le 3n^2 \iff 6 \le 100n$ sağlandığından $O(n^2)$'dir. $c = 1$, $n_0 = 4$ ile $O(n^3)$'tür (eşitsizlik python ile $n = 1, \dots, 9999$ için de kontrol edildi). $O(n)$ ve $O(n\log n)$ değildir, çünkü hiçbir $c$ bulunamaz. En makul (en sıkı) üst sınır $O(n^2)$'dir.

## Dersin Toparlaması

Bu derste algoritma analizinin neden ve nasıl yapıldığı ele alındı. Çalışma süresini doğrudan ölçmek (deneysel analiz) bilimsel yönteme uygun bir yoldur ve 3-SUM örneğinde $N^3$ büyümesini doğru tahmin eder, ama sonuç makineye, derleyiciye ve sisteme bağlıdır. Knuth'un maliyet × sıklık modeli daha sistematiktir, ama bütün işlemleri saymak sıkıcıdır ve yine makineye bağlı kalır. Bu yüzden algoritmaya vekâlet eden tek bir temel işlem seçilir, sayımı tilde gösterimiyle sadeleştirilir ve sonuç $1, \log n, n, n\log n, n^2, n^3, 2^n, n!$ gibi bilinen büyüme sınıflarıyla ifade edilir. Seçmeli sıralama ve kabarcık sıralamasında temel işlem olan karşılaştırmanın sayısı $n(n-1)/2$ bulundu; iyileştirilmiş kabarcık sıralaması, girdinin dağılımının analizi nasıl etkilediğini gösterdi ve en iyi, ortalama ve en kötü durum kavramlarına geçildi.

Son bölümde asimptotik gösterimlere ($O$, $o$, $\Omega$, $\omega$, $\Theta$) giriş yapıldı ve Big-O'nun tanımı iki örnekle işletildi: uygun bir $c$ ve $n_0$ bulmak üst sınırı kanıtlamak için yeterlidir ve en makul üst sınır söylenmelidir. Bir sonraki derste asimptotik gösterimlere devam edilecek, ekleme sıralaması üzerinden iteratif algoritmaların en iyi ve en kötü durum analizi ayrıntılı işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
