# Ders 6 Genişletilmiş Notu: Genetik Algoritmalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Lokal Arama Algoritmalarının Tekrarı
- 2. Genetik Algoritmaların Temel Kavramları
- 3. Genetik Algoritmanın Sözde Kodu
- 4. Sekiz Vezir Problemi İçin Genetik Algoritma
- 5. Seçim Türleri: Rulet Tekerleği ve Sıralama Seçimi
- 6. Farklı Olasılıklarla Seçim Nasıl Gerçekleştirilir
- 7. Gezgin Satıcı Problemi ve Çaprazlama Sorunu
- 8. Genetik Algoritmayla Fonksiyon Optimizasyonu
- 9. Genetik Algoritmanın Performansını Etkileyen Faktörler
- 10. Olumlu ve Olumsuz Yönler, Hiperparametre Ayarı
- 11. Uygulamalar: Alan Tarama ve İki Nokta Arası Yol
- 12. Birden Fazla İyilik Fonksiyonunu Birleştirmek
- 13. Ödev Problemi: Drone'larla Alan Tarama
- Örnek Sorular

## 1. Lokal Arama Algoritmalarının Tekrarı

### 1.1 Lokal aramayı öncekilerden ayıran nokta

Hoca derse bir önceki haftanın konusu olan lokal arama algoritmalarını hatırlatarak başladı. Daha önce görülen arama algoritmalarında (iki şehir arasındaki yol, sekiz taş problemi) kullanıcı başlangıcı ve hedefi verir; algoritmadan istenen bu ikisi arasındaki yolu bulmasıdır.

Lokal aramada durum farklıdır. Kullanıcı hedefin kendisini bilmez; yalnızca hedefin özelliklerini söyler. Sekiz vezir probleminde istenen, hiçbir vezirin birbirini tehdit etmediği bir tahtadır. Kullanıcı o tahtanın neye benzediğini bilmez, hatta böyle bir tahtanın var olup olmadığını bile bilmeyebilir. Algoritma yine bir başlangıçtan (rastgele olabilir) başlayıp adım adım ilerler, ama izlenen yolun çözümle ilgisi yoktur. Kullanıcıya yalnızca bulunan tahta söylenir; "şuradan başladım, şöyle buldum" kısmı kimseyi ilgilendirmez.

### 1.2 Tepe tırmanma

Tepe tırmanma algoritması bir başlangıç noktasında durur, oradan gidilebilecek durumları üretir ve bunların içinden değeri en yüksek olanı seçer. Buradaki değer, kullanıcının hedefe dair söylediği özelliklere göre hesaplanan, hedefe ne kadar yakın ya da uzak olunduğunu tahmin eden değerlendirme fonksiyonudur; yani sezgisel fonksiyondur. Seçilen komşunun değeri bulunulan noktanınkinden yüksekse oraya gidilir; aynı ya da düşükse gidilmez ve algoritma durur. Süreç basittir: bir noktada dur, etrafını tara, iyileştiren bir yer varsa oraya git, orada da aynısını yap.

Tepe tırmanma her tarafı göremez, yalnızca yakın çevresini görür. Sekiz vezir probleminde performansı şöyledir (ekrandan, 00:10:00):

- Rastgele başlangıç değerleriyle
- Denemelerin %14'ünde çözer
- %86'sında lokal bir maksimuma takılır
- $8^8 = 2^{24} \approx 17$ milyon durum vardır

Hoca burada şunu sordu: Deterministik bir algoritmayı aynı başlangıçla tekrar çalıştırırsak sonuç değişir mi? Değişmez. İçinde rastgelelik olan bir algoritmayı tekrar tekrar çalıştırırsak sonuç değişir. Tepe tırmanmada varılan yer başlangıç noktasına bağlıdır. Bu yüzden rastgele başlangıçlarla tekrarlamak, bir denemede çözülemeyen problemin başka bir denemede çözülmesini sağlayabilir. Bu durumda algoritmada bir sorun yoktur, yalnızca yanlış yerden başlanmıştır ("şanssızmışız").

Hoca tahtaya tek boyutlu bir fonksiyon çizerek bazı problemlerde çok şanslı olmak gerektiğini gösterdi. En iyi tepe dar bir aralıktaysa, ancak o aralığın içinden başlayan arama en iyi yere ulaşır; başka her yerden başlayan arama yakınındaki daha alçak tepelere takılır.

### 1.3 Çözüm alternatifleri

Tepe tırmanmanın bu sorununa karşı üç alternatif görülmüştü (ekrandan, 00:15:00):

- **Farklı başlangıçlarla tekrarlamak** (random-restart hill climbing).
- **Benzetimli tavlama** (simulated annealing): Sürekli iyileşme yerine arada kötüleşmeye izin verilir. Rastgele bir komşu üretilir; iyileşme varsa kabul edilir, yoksa bir olasılıkla kabul edilir. Bu olasılık iki şeye bağlıdır: zamana (başlangıçta kötüleşme daha kolay kabul edilir) ve kötüleşmenin büyüklüğüne (çok iyi bir yerden çok kötü bir yere götüren adımın kabul şansı çok düşüktür). Kabul edilen bir kötüleşme, biraz sonra daha iyi bir yere gitmeyi sağlayabilir.
- **Paralel tepe tırmanma** (local beam search): Tek bir dağcı yerine birden çok dağcı göndermek, yani tek bir çözüm yerine birçok çözümü birlikte takip etmek.

Bugünün konusu olan genetik algoritmalar da bu son fikre dayanır; hoca onları paralel tepe tırmanmanın bir versiyonu olarak tanıttı.

## 2. Genetik Algoritmaların Temel Kavramları

Slayttaki tanımlar şöyledir (ekrandan, 00:20:00):

- Genetik algoritmalar evrim mekanizmasına (en iyinin yaşaması) dayanır.
- Amaç, uygunluk fonksiyonunun (fitness function) maksimizasyonu ya da minimizasyonu, yani optimizasyonudur.
- Uygunluk fonksiyonu, toplumdaki her kromozomun / bireyin / durumun ne kadar iyi olduğunu gösteren fonksiyondur. Büyük değer iyi / uygun bireydir.
- K adet rastgele üretilmiş kromozom / durum / çözüm hipotezi ile başlanır. Durumlar kümesine popülasyon denir.
- Kromozom / durumlar sıralı ya da sırasız karakter kümeleriyle temsil edilir. Genelde sayılar ya da 0 ve 1'lerden oluşur.

### 2.1 Uygunluk fonksiyonu ve optimizasyon yönü

Hoca, uygunluk (uyumluluk) fonksiyonunun daha önce konuşulan sezgisel fonksiyondan farklı bir şey olmadığını, yalnızca jargonun farklı olduğunu vurguladı. Bir fonksiyon minimum yapılmaya çalışılıyorsa minimizasyon, maksimum yapılmaya çalışılıyorsa maksimizasyon yapılır.

Sekiz vezir örneğinde uygunluk olarak "birbirini tehdit eden vezir çifti sayısı" alınırsa bu sayı küçültülmeye çalışılır, minimizasyon yapılır; bulunulan yerden daha düşük yerlere gidilir. "Birbirini tehdit etmeyen vezir çifti sayısı" alınırsa maksimizasyon yapılır. Bir minimizasyon problemini maksimizasyona çevirmek (ya da tersi) oldukça basittir. Bu yüzden algoritmanın adı "tepe tırmanma" olsa da aynı yöntemle çukurlara da inilebilir.

### 2.2 Kromozom, birey, popülasyon

Lokal aramada sekiz vezir tahtası, her sütundaki vezirin kaçıncı satırda olduğunu gösteren sekiz rakamla ifade edilmişti. Genetik algoritmada bu durumların adı kromozom ya da bireydir. Kromozom, birey, durum, çözüm ve çözüm hipotezi birbirinin yerine kullanılabilen sözlerdir. Her biri tek başına problemin bir çözümüdür; birleşerek bir çözüm oluşturmazlar. Bireylerin oluşturduğu topluluğa popülasyon ya da toplum denir.

Algoritma K bireylik bir popülasyonla başlar, sonra yine K bireylik yeni bir nesil (jenerasyon) üretir. Önceki nesil "ölür": silinir, yerine yenisi yazılır. Sistem böyle nesil nesil ilerler. Paralel tepe tırmanmada da K durumla başlanıp onlardan yeni durumlar üretiliyor ve en iyi K tanesi seçiliyordu. İkisinin tek farkı, bir popülasyondan yeni popülasyona nasıl geçildiğidir.

### 2.3 Üç operatör

Paralel tepe tırmanmada üretilen bütün yeni durumlar "bir havuza konup" en iyileri seçiliyordu. Genetik algoritma bunu üç operatörle yapar:

- **Seçme (selection):** Bir sonraki nesli üretecek kromozomların mevcut K kromozom içinden seçilmesi.
- **Çaprazlama (crossover):** İki çözümün birleşerek yeni çözüm üretmesi. Hoca bunu anne, baba ve çocuk ilişkisine benzetti. Lise biyolojisindeki "kol bacak değişimi" gibi, anneden gelen bir parça ile babadan gelen başka bir parça birleşerek yeni bir gen dizisi oluşturur.
- **Mutasyon:** Kromozomun bazı değerlerinin rastgele değişmesi.

## 3. Genetik Algoritmanın Sözde Kodu

Ekrandaki sözde kod şöyledir (ekrandan, 00:25:00):

```text
function GENETIC_ALGORITHM(population, FITNESS-FN) return an individual
  input: population, a set of individuals
         FITNESS-FN, a function which determines the quality of the individual
  repeat
    new_population <- empty set
    loop for i from 1 to SIZE(population) do
      x <- RANDOM_SELECTION(population, FITNESS_FN)
      y <- RANDOM_SELECTION(population, FITNESS_FN)
      child <- REPRODUCE(x, y)
      if (small random probability) then child <- MUTATE(child)
      add child to new_population
    population <- new_population
  until some individual is fit enough or enough time has elapsed
  return the best individual
```

Algoritmaya popülasyon ve uygunluk fonksiyonu girer, dışarı tek bir birey çıkar. `repeat ... until` döngüsünün bitiş koşulu iki türlüdür:

- Popülasyondaki bireylerden biri yeterince iyidir: sekiz vezirde problem gerçekten çözülmüştür ya da başka bir problemde istenen eşiğin altına inilmiştir.
- Yeterince zaman geçmiştir: belli sayıda iterasyon yapılmıştır. Bu koşul gereklidir, çünkü belki istenen iyiliğe hiç erişilemeyecektir ve döngünün sonsuza kadar dönmesi istenmez.

Döngünün içinde önce boş bir yeni popülasyon oluşturulur. Eski popülasyonda kaç birey varsa, `for` döngüsünün her adımında bir yeni birey üretilir:

1. `RANDOM_SELECTION` ile popülasyondan x bireyi seçilir. Adı "random" olsa da tamamen rastgele değildir; içine uygunluk fonksiyonu da girer. Uygunluğu iyi olan bireyin seçilme olasılığı yüksek (örneğin %80), kötü olanınki düşüktür (örneğin %10).
2. Aynı şekilde y bireyi seçilir.
3. `REPRODUCE(x, y)` ile bu ikisinden bir çocuk üretilir.
4. Çocuk küçük bir olasılıkla mutasyona uğratılır.
5. Çocuk yeni popülasyona eklenir.

Döngü bitince yeni popülasyonda eski popülasyon kadar birey olur ve eski neslin üzerine doğrudan yeni nesil yazılır. `repeat` döngüsünden çıkınca popülasyondaki en iyi birey döndürülür.

Hoca bu algoritmanın tepe tırmanmaya çok benzediğini, aslında yalnızca `for` döngüsünün içinin farklı olduğunu söyledi. Paralel tepe tırmanmaya "local beam search" da denir. Hoca bu tür beam search yaklaşımlarına başka yerlerde de rastlanabileceğini, örneğin derin öğrenmede metin üretiminde kullanıldığını ekledi.

## 4. Sekiz Vezir Problemi İçin Genetik Algoritma

### 4.1 Kromozom gösterimi

Her sütunda bir vezir vardır; durum, her sütundaki vezirin satırıdır. 8 farklı değer alabilen bir bilgiyi tutmak için 3 bit yeter. 8 vezir olduğu için $8 \times 3 = 24$ bit herhangi bir tahtayı göstermeye yeter. Hoca, tahtada başka taşlar da olsaydı gösterimin bu kadar basit olamayacağını, burada yalnızca vezir olduğu için her sütundaki vezirin yerini bilmenin yettiğini belirtti. Slaytta kromozomlar 8 rakamlı diziler olarak yazılmıştır.

"24748552" kromozomu şu anlama gelir: birinci sütundaki vezir ikinci satırda, ikinci sütundaki vezir dördüncü satırda, üçüncü sütundaki vezir yedinci satırdadır ve böyle devam eder.

### 4.2 Uygunluk fonksiyonu

Uygunluk fonksiyonu: birbirini tehdit etmeyen vezir çiftlerinin sayısı (ekrandan, 00:30:00). Bu fonksiyon maksimum yapılmaya çalışılır.

- **En az 0:** Bütün vezirler aynı satıra, aynı sütuna ya da aynı köşegene dizilirse herkes birbirini tehdit eder.
- **En çok 28:** 8 vezirin ikili kombinasyonu $\binom{8}{2} = 8 \cdot 7 / 2 = 28$'dir; tehdit etmeyen çift sayısı bundan büyük olamaz. 28'e ulaşıldığında iş biter, ama 28'e yakın değerler de iyidir.

### 4.3 Adım adım bir nesil

Slayttaki örnek (AIMA kitabının şekli) dört bireylik bir popülasyonla bir nesil ilerler (ekrandan, 00:30:00 ve 00:35:00).

**(a) Başlangıç popülasyonu ve (b) uygunluk:**

| Birey | Kromozom | Uygunluk | Seçilme olasılığı |
|---|---|---|---|
| 1 | 24748552 | 24 | %31 |
| 2 | 32752411 | 23 | %29 |
| 3 | 24415124 | 20 | %26 |
| 4 | 32543213 | 11 | %14 |

Uygunluk değerleri doğrudan seçim için kullanılamaz; önce olasılığa çevrilmeleri gerekir. Büyük değerin seçilme olasılığı yüksek olsun istendiği için her değer toplama bölünür (normalizasyon), böylece hepsinin toplamı %100 olur:

$$\frac{24}{24+23+20+11} = \frac{24}{78} \approx \%31, \qquad \frac{23}{78} \approx \%29 \text{ vb.}$$

Dört uygunluk değerinin (24, 23, 20, 11) gerçekten bu kromozomların tehdit etmeyen çift sayısı olduğu python ile doğrulandı.

**(c) Seçim:** Olasılıklara göre dört seçim yapılmış: önce 2. birey, sonra 1. birey, sonra yine 2. birey, sonra 3. birey seçilmiş. Seçilenler: 32752411, 24748552, 32752411, 24415124. Dördüncü birey hiç seçilmemiştir; zaten seçilme olasılığı düşüktür. 2. birey iki kez seçilmiş, 1. birey bir kez; en yüksek olasılıklı bireyin daha çok seçileceği kesin değildir, çünkü seçim rastgeledir. Yüksek değerler yalnızca seçilme olasılığının yüksek olduğunu söyler. Bazı bireyler bu yüzden tekrar edebilir.

**(d) Çaprazlama:** Seçilenler ikişer ikişer eşlenir: 1 ile 2 bir çift, 3 ile 4 bir çift. Her çiftten iki yeni birey üretilir; birincinin sol tarafı ile ikincinin sağ tarafı, ikincinin sol tarafı ile birincinin sağ tarafı birleşir:

- 327 | 52411 ve 247 | 48552 (3. rakamdan sonra kesilmiş) → 32748552 ve 24752411
- 32752 | 411 ve 24415 | 124 (5. rakamdan sonra kesilmiş) → 32752124 ve 24415411

Sözde kodda her çiftten tek çocuk üretiliyordu; burada iki çocuk üretiliyor. Hoca ikisinin de olabileceğini söyledi. Her çiftten yalnız bir çocuk üretilecekse $n$ yerine $2n$ seçim yapmak gerekir.

**(e) Mutasyon:** 4 birey × 8 değer = 32 değer vardır. Örneğin %10'luk bir mutasyon oranıyla değerlerin yaklaşık %10'u rastgele seçilip rastgele başka değerlerle değiştirilir. Örnekte 3 nokta seçilmiştir:

- 32748552 → 32748**1**52
- 24752411 → 24752411 (değişmedi)
- 32752124 → 32**2**52124
- 24415411 → 2441541**7**

Böylece yeni popülasyon hazırdır. Bu popülasyon ilk popülasyonun yerine konur; uygunluklar yeniden hesaplanır, olasılıklar oluşturulur, seçim, çaprazlama ve mutasyon tekrarlanır. Süreç, popülasyondaki bir bireyin değeri 28 olana ya da en fazla nesil sayısı aşılana kadar döner.

### 4.4 Çaprazlamanın tahtadaki anlamı

Slaytta iki tahta ve çocukları görsel olarak gösterildi. 32752411 ve 24748552 tahtalarından, birinci kromozomun sol tarafı (3, 2, 7) ile ikinci kromozomun sağ tarafı alınarak 32748552 tahtası oluşur. Yani çocuk tahtanın ilk üç sütunu birinci ebeveynden, kalan beş sütunu ikinci ebeveynden gelir.

## 5. Seçim Türleri: Rulet Tekerleği ve Sıralama Seçimi

Kısa bir aradan sonra hoca kromozom seçim türlerine geçti. İki tür vardır: rulet tekerleği seçimi ve sıralama seçimi.

### 5.1 Rulet tekerleği seçimi

Az önce sekiz vezirde yapılan seçim rulet tekerleği seçimidir: uygunluk değerleri seçilme olasılıklarına çevrilir ($24 \to 31$, $23 \to 29$, $20 \to 26$, $11 \to 14$) ve bu olasılıklarla seçim yapılır (ekrandan, 00:50:00).

Hoca sonra uç bir durum sordu: Uygunluk değerleri 100, 1, 1, 1 olsaydı ne olurdu? Ekranda bu değerlerin olasılıkları "100 → 99" ve "1 → 0.33" diye yazıldı. Bir öğrenci "çok büyük ihtimalle sürekli birinci seçilir" diye cevap verdi.

> **Ders sonrası not:** Ekranda yazılan değerler kabaca bir tahmindi (hoca "99.9 gibi bir şeyler olacak" dedi). Doğrusu $100/103 \approx \%97.1$ ve $1/103 \approx \%0.97$'dir. Sonuç değişmez: birinci birey neredeyse her seçimde seçilir.

Bu durumda yeni popülasyonun hepsi birinci birey olur. Bir birey kendisiyle çaprazlanırsa nereden kesilirse kesilsin aynı birey çıkar; çaprazlamanın bir anlamı kalmaz ve iyileşmeye götürecek yeni bir şey üretilemez. Geriye yalnızca mutasyon kalır, o da küçük oynamalar yapar.

Hoca bunu tahtaya çizdiği bir fonksiyonla gösterdi (ekrandan, 00:55:00). Dört bireyden üçünün değeri çok düşük, birininki yüksek olsun. Hep aynı birey seçilip mutasyona uğratılırsa bir sonraki popülasyonun dört bireyi de o bireyin hemen etrafında toplanır. Herkesi aynı yere toplamanın bir anlamı yoktur:

> **Hocanın vurgusu:** Aynı dağın üzerine birden fazla dağcı göndermenin anlamı yok. Zaten onu bıraksanız o oraya çıkacak. Herkesi aynı yere toplayacaksanız o kadar çok çözümü birden takip etmenin anlamı kalmaz.

Hoca bunu iki boyutta çizdiğini, gerçekte işlemlerin çok daha yüksek boyutlarda yapıldığını da belirtti.

### 5.2 Sıralama seçimi

Bu sorunu çözmek için rulet tekerleğine ek olarak sıralama tabanlı seçim tanımlanmıştır. Sıralama seçiminde:

1. Popülasyon uygunluk değerine göre küçükten büyüğe sıralanır.
2. Her kromozoma sıra değeri, yeni uygunluk değeri olarak atanır.
3. Bu yeni uygunluklar yine toplamlarına bölünerek olasılığa çevrilir.

100, 1, 1, 1 örneğinde (ekrandan, 01:00:00):

| Orijinal uygunluk | Sıra (yeni uygunluk) | Olasılık |
|---|---|---|
| 1 | 1 | $1/10$ |
| 1 | 2 | $2/10$ |
| 1 | 3 | $3/10$ |
| 100 | 4 | $4/10$ |

Paydadaki 10, yeni uygunlukların toplamıdır ($1+2+3+4$). Artık en iyi birey %40, ötekiler %30, %20 ve %10 olasılıkla seçilir. Bir bireyin değeri tek başına ne kadar yüksek olursa olsun, hep onun seçilmesi engellenmiş, diğerlerine de seçilme şansı tanınmış olur.

Bu yöntemde bütün kromozomlara seçilme şansı verilir. Ancak en iyi kromozomların seçilme şansı diğerlerinden çok farklı olmadığı için çözüme yaklaşmak biraz yavaşlayabilir. Hoca bunların hepsinin bir tercih olduğunu, sonuçlarının problemden probleme değiştiğini söyledi; sıralama seçiminin rulet tekerleğinden her zaman daha iyi olduğu söylenemez.

## 6. Farklı Olasılıklarla Seçim Nasıl Gerçekleştirilir

Hoca, olasılıklara göre seçimin algoritmik olarak nasıl yapılacağını bir soruyla açtı (ekrandan, 01:00:00): N uzunluğunda bir dizi üretilecek; dizinin %85'i A, %15'i B olsun. Kullanıcı istediği anda bir tuşa basıp durduracak ve o ana kadar üretilmiş öğelerin yaklaşık %85'i A, %15'i B olacak.

**Soru:** Bunu nasıl bir yapıyla sağlarız?
**Cevap (bir öğrenci):** 1 ile 100 arasında rastgele bir değer üretilir; 85'ten küçükse A, büyükse B yazılır.

Hoca bu çözümü doğru buldu, ama bir eksiğini gösterdi: iki seçenek için tek bir karşılaştırma yetiyor, 20 farklı seçenek olsa "şundan büyük, şundan küçük" diye bir sürü `if` yazmak gerekir. Bunun yerine şöyle bir yol önerdi: Seçenekleri olasılıklarıyla orantılı sayıda içeren bir yardımcı dizi tanımlanır. Örneğin 10 elemanlı bir dizinin 7 elemanı A, 3 elemanı B olsun (bu %70-%30 eder). Sonra 1 ile dizi uzunluğu arasında rastgele bir indis seçilir ve o indisteki değer doğrudan yazılır. Bu yöntemde hiç `if` gerekmez ve seçenek sayısı ikiyle sınırlı değildir: yardımcı diziye az sayıda C ve D, biraz daha çok B ve en çok A konursa C ve D küçük, B daha büyük, A en büyük olasılıkla üretilir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki "Farklı Olasılıklarla Seçim" başlıklı slaytın küçük resminde de aynı fikir görülmektedir: seçilme şansları toplamı 100 olacak şekilde 1-100 aralığı parçalara bölünür, rastgele sayının düştüğü aralığın sahibi seçilir. Bu, rulet tekerleği seçiminin klasik gerçekleştirilme biçimidir.

## 7. Gezgin Satıcı Problemi ve Çaprazlama Sorunu

### 7.1 Problem

Gezgin satıcı malını satmak için bir şehirden ötekine gider; gideceği şehirlerin listesi bellidir. İstenen, bu şehirler için bir rota oluşturmaktır (ekrandan, 01:05:00):

- Rota her şehirden geçmeli.
- Toplam gidilen yol minimum olmalı.

Toplam yol minimum olsun denince aynı yerden iki kez geçmenin bir anlamı kalmaz. Hoca dört şehirli bir örnek çizdi ve hepsini birden başlatarak olası rotaları saydı: 1234 (1'den 2'ye, 2'den 3'e, 3'ten 4'e), 1243, 1324, 1432 ve diğerleri. Amaç bu rotaların içinden toplam yolu minimum olanı bulmaktır.

**Soru:** Aynı şehirden iki kez geçmek daha kısa bir sonuç veriyorsa yine de geçmemeli miyiz? Örneğin 2'den 4'e gitmenin maliyeti 10, 3'ten 4'e gitmenin maliyeti 2 ise 1, 3, 2'den sonra tekrar 3'e dönüp 4'e gitmek daha kısa olabilir.
**Cevap:** Aynı şehirden geçmek çok sorun değil; önemli olan bütün şehirleri gezmek ve minimum toplam yolu elde etmek. Ama aynı yerden tekrar tekrar geçerek minimum yolu elde etmek pek beklenen bir şey değildir; bu, problemin şartlarından biri de değildir.

### 7.2 Kromozom gösterimi

Kromozom, şehirlerin ziyaret sırasıdır. 8 şehir için slayttaki örnek kromozom (3 5 7 2 1 6 4 8) şunu söyler: 3'ten başla, 5'e git, sonra 7'ye, sonra 2'ye, sonra 1'e, sonra 6'ya ve böyle devam et. Hoca, tekrarlı bir rotanın daha kısa olduğu bir durum olsa bile başlangıcı başka bir şehirden seçerek bunun aşılabileceğini, dolayısıyla N şehir için N uzunluğunda bir sıranın minimum yolu temsil etmeye yettiğini söyledi.

### 7.3 MATLAB TSP demosu

Slaytta Amerika haritası üzerinde 40 rastgele nokta vardır (ekrandan, 01:10:00). Temsil 40 noktanın indisidir; bir kromozom, hangi noktaya hangi sırayla gidileceğini söyleyen 40 değerlik bir dizidir. Üç resim gösterilir:

- **T=0:** Başlangıç popülasyonundaki (örneğin 100 bireyden) en iyi birey. Yol çok iyi değildir; harita üzerinde uzak noktalar arasında sık sık atlar.
- **T=t:** t'inci nesildeki 100 bireyin en iyisi.
- **T=t+k:** Daha sonraki bir nesildeki en iyi birey. Yol belirgin biçimde kısalmıştır.

### 7.4 Standart çaprazlamanın sorunu

Gezgin satıcıyı gerçekten genetik algoritmayla çözmeye kalkınca çaprazlamada bir sorun çıkar. Slayttaki örnek (ekrandan, 01:10:00 küçük resim panelinden):

- CityList1 = (3 5 7 | 2 1 6 4 8)
- CityList2 = (2 5 7 | 6 8 1 3 4)

Standart (tek noktalı) çaprazlama uygulanırsa yeni nesil:

- (3 5 7 6 8 1 3 4): 3 iki kez var, 2 yok.
- (2 5 7 2 1 6 4 8): 2 iki kez var, 3 yok.

Çocuklar istenen özelliği taşımaz: bazı şehirler tekrar etmiş, bazıları hiç yoktur. Bu yüzden standart çaprazlama gezgin satıcıda işe yaramaz; iki bireyden çocuk üretmenin başka bir yolunu bulmak gerekir.

### 7.5 Uniform crossover

İlk olası çözüm uniform crossover'dır. Kromozom boyutunda rastgele 0 ve 1'lerden oluşan bir şablon (template) oluşturulur. P1 ve P2 ebeveynler, C1 ve C2 çocuklardır. Şablonda 1 olan indislerde değerler aynen alınır, 0 olan indislerde P1 ve P2'nin değerlerinin yeri değiştirilir. Hocanın gösterdiği 10 uzunluklu örnekte ilk indis 1 olduğu için A ve E yerinde kalır, ikinci indis 0 olduğu için B ile F yer değiştirir.

<!-- BELİRSİZ: Uniform crossover tablosunun tam değerleri karelerde okunamadı (yalnız küçük resim var). -->

**Soru (hoca):** Üretilen iki çocuk istediğimiz özelliği taşıyor mu, her şehri içeriyor mu?
**Cevap:** Hayır. Bir öğrencinin fark ettiği gibi ikinci çocukta G iki kez geçiyor. Birinci çocukta iki D ve iki C, ikinci çocukta iki G ve iki E vardır. Bir şey iki kez varsa başka bir şey eksik kalır. Uniform crossover da bu problemde çözüm oluşturmaz.

### 7.6 Sıra tabanlı çaprazlama (order-based crossover)

Slayttaki tanım (ekrandan, 01:15:00):

1. Kromozom boyutunda rastgele 1 ve 0'lardan oluşan şablon oluştur.
2. Child1 için: Şablonda 1 olan indislerin Parent1'deki değerlerini al, Child1'in aynı indisine koy. Child1'de bazı boşluklar kalır.
3. Şablonda 0 olan indislerin Parent1'deki değerlerini al (A D E G).
4. Bu listedekileri Parent2'deki sıralarına göre diz (E D G A).
5. Elde edilen diziyle Child1'in boşluklarını bu sırayla doldur.
6. Child2 için aynı prosedür: (E C F A) → (A C E F).

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| Parent 1 | A | B | C | D | E | F | G |
| Parent 2 | E | B | D | C | F | G | A |
| Template | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
| Child 1 | E | B | C | D | G | F | A |
| Child 2 | A | B | D | C | E | G | F |

**Child1 adım adım:** Şablonda 1 olan indisler 2, 3 ve 6'dır. Parent1'in bu indislerdeki değerleri B, C, F aynı yerlere konur: `_ B C _ _ F _`. Kalan Parent1 değerleri A, D, E, G'dir. Bunlar Parent2'de hangi sırayla geçiyor? Parent2'nin ilk elemanı E, sonra D geçer, sonra G, en sonda A. Hoca bu sırayı öğrencilere sorarak çıkardı. Sıralı liste E, D, G, A boşluklara yerleştirilir: E B C D G F A.

**Child2 adım adım:** Bu kez Parent2'nin şablonda 1 olan indislerdeki değerleri B, D, G yerinde kalır: `_ B D _ _ G _`. Kalanlar E, C, F, A'dır; bunlar Parent1'deki geçiş sırasına göre A, C, E, F olarak dizilir ve boşluklara konur: A B D C E G F.

Bu yöntemde bazı değerler olduğu gibi alınır, kalanların yalnızca yerleri değiştirilir. Bir ebeveynin bütün elemanları yine kullanıldığı için hiçbir şehir kaybolmaz ve hiçbir şehir iki kez tekrar etmez. İki çocuk python ile yeniden üretilerek doğrulandı.

### 7.7 Mona Lisa TSP

Slaytta 100 bin noktadan oluşan bir Mona Lisa resmi vardır: 100 bin noktayı elini kaldırmadan, en kısa yoldan birleştir (ekrandan, 01:20:00). Bu da bir gezgin satıcı problemidir.

**Soru (hoca):** Genetik algoritma ya da tepe tırmanma çalıştırdınız ve başlangıçtakilerden çok daha iyi bir çözüm buldunuz. Bu çözümün en iyi çözüm olduğundan emin olabilir miyiz?
**Cevap:** Olamayız; daha iyisi olabilir. Minimum yolun uzunluğunu bilmeden en iyiye ulaşıldığını söylemek mümkün değildir. Bu tür problemlerde süper bilgisayarlarla çalışılır ve "şu ana kadar bulunan en iyi yol budur" diye açıklanır; sonra başkaları daha iyi bir yol bulabilir.

**Soru (hoca):** Brute force ile çözmeye kalksak kaç olası yol var?
**Cevap (bir öğrenci):** 100 bin faktöriyel.

Hoca bunun o kadar büyük bir sayı olduğunu söyledi ki, evrenin başlangıcından beri bütün kaynaklar buna harcansaydı bile şu ana kadar çözüm bulunamazdı. Bu kadar büyük bir arama uzayında brute force anlamlı değildir. Mükemmel olmasa bile işe yarayan çözümlere hızlıca erişmek için lokal arama algoritmaları kullanılır; bunlar brute force'a ya da rastgele seçime göre kısa zamanda iyi sonuçlar verir.

> **Ek bilgi (derste anlatılmadı):** $100000!$ yaklaşık $10^{456573}$'tür, yani 456 bin basamaklı bir sayıdır (python ile $\ln\Gamma$ üzerinden hesaplandı). Kapalı bir turda başlangıç noktası ve yön önemsizse farklı tur sayısı $(n-1)!/2$'dir, ama bu da büyüklük mertebesini değiştirmez.

## 8. Genetik Algoritmayla Fonksiyon Optimizasyonu

### 8.1 Tek değişkenli fonksiyon

Slayttaki problem (ekrandan, 01:25:00):

- **Problem:** $f(x) = \cos(x/3) \cdot \sin(x/4)$, $x \in [0, 127]$ şeklinde verilen bir fonksiyonun maksimum değerini bulmak.
- **Gösterim:** 128 farklı değer için 7 bit yeterli.
- **Başlangıç:** a: 0000011, b: 1110111, c: 0010000, d: 0011010
- **Uygunluk kriteri:** $f(x)$

$x$ tam sayıdır; 0 ile 127 arasında 128 olası değer vardır. Burada uygunluk fonksiyonu $f$'nin kendisidir; zaten maksimum yapılmaya çalışılan odur.

**Soru (hoca):** Bunu brute force ile yapabilir miyiz?
**Cevap:** Evet. $x$ tam sayı olarak verildiği için 0'dan 127'ye kadar bütün değerler yerine konur, 128 değerin en yükseği seçilir. Ama $x$ tam sayı değilse ya da birden fazla değişken varsa arama uzayı korkunç büyüklüğe ulaşabilir.

Hoca, türevi alınabilen bir fonksiyonda genetik algoritmayla arama yapmanın çok iyi bir hareket olmayabileceğini vurguladı. Türev alınamayan yerler varsa ya da hiç türev alınamıyorsa ayrık (discrete) uzayda optimizasyon gerekebilir; sürekli (continuous) uzayda optimizasyon yapılabiliyorsa orada yapılmalıdır.

Slayttaki grafikte fonksiyonun çok sayıda lokal tepesi görülür. Başlangıç bireyleri (a, b, c, d) grafikte bazı noktalara karşılık gelir. Tepe tırmanma yapılırsa her başlangıç kendi yakınındaki tepeye takılır; en iyi tepeye ulaşmak için çok şanslı olmak gerekir. Hoca bu grafiği çizdirdikleri için bunu görebildiklerini, çizdirmeseler göremeyeceklerini de ekledi. Genetik algoritmada bireyler 0 ve 1'lerden oluşan değerlerle ifade edilir; iki birey istedikleri gibi çaprazlanabilir, burada gezgin satıcıdaki gibi sıra tabanlı bir çaprazlamaya gerek yoktur (sekiz vezirde de gerek yoktu). Dört sarı noktalık popülasyon nesiller boyunca adım adım ilerler ve belki sonunda bireylerden biri en iyi yere ulaşır.

### 8.2 Brute force'un hızla imkânsızlaşması

Hoca 128 değer için bu kadar uğraşmaya gerek olmadığını kabul etti. Ama fonksiyon iki değişkenli olsa ve her biri 128 değer alsa brute force ile $128 \times 128$ deneme gerekir. Değişken sayısı 3, 4, 10 olursa $128^{10}$ gibi sayılara, 100 değişkende çok daha büyük sayılara gelinir. Brute force'un uygun olduğu alandan çok hızlı uzaklaşılır; bu durumda genetik algoritma kullanmak gerekebilir.

### 8.3 İki değişkenli fonksiyon

Slaytta "Fonksiyon iki parametreli olursa?" sorusu ve $F(x,y) = x^2 - y^3 + xy^2$ örneği vardır (ekrandan, 01:25:00). İki değişken varken 14 bitlik bir kromozom kullanılabilir: ilk 7 bit birinci değişkenin ($x_1$), ikinci 7 bit ikinci değişkenin ($x_2$) değerini tutar. Uygunluk kriteri $f(x_1, x_2)$ olur. Slayttaki örnek bireyler (ekrandan, 01:30:00):

- B1: 0000011 0011010
- B2: 0010000 1110111

> **Hocanın vurgusu:** Buraları iyi dinleyin, çünkü ödevinizde bunlara benzeyen şeyler olabilir.

Çaprazlama, ebeveynlerin bir tarafı ve öteki tarafı alınarak tek noktadan yapılabilir. Ama hoca bir alternatif önerdi: her değişkenin ifade ettiği bit alanının içinde ayrı ayrı çaprazlama yapmak, yani ilk 7 bitlik parçaları kendi aralarında, ikinci 7 bitlik parçaları kendi aralarında farklı noktalardan çaprazlamak. Bu, bütün kromozomu tek bir noktadan kesmekten daha mantıklı olabilir.

> **Ders sonrası not:** Hoca bu kısımda "cross-validation" dedi; kastettiği çaprazlamadır (crossover). Cross-validation, makine öğrenmesinde bir modelin başarısını veriyi bölerek ölçme yöntemidir ve burada geçen işlemle ilgisi yoktur.

<!-- BELİRSİZ: Hocanın 01:30 civarında yazdığı değişken içi çaprazlama örneğinin (C1) bitleri karelerde okunamadı. -->

## 9. Genetik Algoritmanın Performansını Etkileyen Faktörler

Slayttaki faktörler (ekrandan, 01:35:00 ve 01:50:00):

- **Popülasyon büyüklüğü / kromozom sayısı:** Kromozom sayısını arttırmak çalışma zamanını arttırırken, azaltmak da kromozom çeşitliliğini yok eder.
- **Mutasyon oranı:** Kromozomlar birbirine benzemeye başladığında hâlâ çözüm noktalarının uzağında bulunuluyorsa, mutasyon işlemi GA'nın sıkıştığı yerden (tüm kromozomlar aynı platoda) kurtulmak için tek yoldur. Ancak yüksek bir değer vermek GA'nın kararlı bir noktaya ulaşmasını engelleyecektir.
- **Kaç noktalı çaprazlama yapılacağı:** Normal olarak çaprazlama tek noktada gerçekleştirilmekle beraber, yapılan araştırmalar bazı problemlerde çok noktalı çaprazlamanın çok yararlı olduğunu göstermiştir.
- **Çaprazlamanın sonucu elde edilen bireylerin nasıl değerlendirileceği:** Elde edilen iki bireyin birden kullanılıp kullanılmayacağı.
- **Durum kodlamasının nasıl yapıldığı:** Bir parametrenin doğrusal ya da logaritmik kodlanması GA'nın performansında önemli bir farka yol açabilir.
- **Başarı değerlendirmesinin nasıl yapıldığı:** Akıllıca yazılmamış bir değerlendirme işlevi çalışma zamanını uzatabileceği gibi çözüme hiçbir zaman ulaşmamasına da neden olabilir.

### 9.1 Popülasyon büyüklüğü

Kromozom sayısı arttıkça çeşitlilik artar, bu iyidir; ama hesaplama maliyeti de artar, bu kötüdür. Hoca, birey sayısı arttıkça maliyetin en azından doğrusal arttığını, karesel olmadığını söyledi; popülasyonu 10 katına çıkarınca çözüme ulaşma süresinin de yaklaşık 10 katına çıkması beklenir.

### 9.2 Mutasyon oranı

Bireyler birbirine benzemişse çaprazlama fazla çeşitlilik üretmez. Hoca tahtaya bütün bireylerin aynı yerde toplandığı bir durum çizdi: başka yerlerde daha iyi tepeler var, ama herkes bir bölgede toplanmış. Bireyler birbirine çok benzediği için çaprazlamayla yeni noktalar üretme şansı kalmaz; yeni yerlere gitmeyi yalnızca mutasyon sağlayabilir.

Öte yandan mutasyonun çok yüksek olması çaprazlamanın işini ortadan kaldırır. Çaprazlamanın anlamı, iki bireyden çözüm parçaları almaktır. Annenin ilk kısmı çok iyi, babanın ikinci kısmı çok iyiyse, bu ikisini birleştirmek her ikisinden de daha iyi bir çözüm üretebilir. Hoca sekiz vezir örneğine döndü: bir bireydeki 3-2-7 parçası kendi içinde iyi bir parça, diğerindeki 4-8-5-5-2 parçası da kendi içinde iyi bir parça olabilir; çaprazlama ikisini birleştirir.

> **Hocanın vurgusu:** Bütün crossover'ın amacı bu: kendi içinde anlamlı küçük lokal parçaları bir araya getirebilmek, farklı bireylerde bulunan kabiliyetleri bir araya toplayabilmek.

Çaprazlama kötü parçaları da birleştirebilir; ama seçim uygunluğa göre yapıldığı için iyi parçaları birleştirme olasılığı daha yüksektir.

Mutasyon %80 yapılırsa (bireylerin %80'i değişsin denirse) iş tamamen rastgeleliğe dayanır; o durumda çaprazlama yapmanın da anlamı kalmaz. Hoca çaprazlamanın aslında şart olmadığını, süreç yalnızca mutasyonla da ilerletilebileceğini söyledi. Ama mutasyon oranı tüm süreç boyunca çok yüksek kalırsa genetik algoritmanın kararlı bir yere oturmasını, bir çözüme doğru adım adım gitmesini engeller; uygunluk fonksiyonunda sürekli sıçramalar olur ve yavaş yavaş iyileşen bir süreç oluşmaz. Mutasyon, benzetimli tavlamadaki rastgele bir yere gitme olasılığına benzer. Başlangıçta yüksek tutulup zamanla azaltılır.

### 9.3 Tek ve çok noktalı çaprazlama

Hoca iki birey üzerinde gösterdi (ekrandan, 01:40:00):

- Ebeveynler: ABCDEFGH ve 12345678.
- **Tek noktadan** (3. karakterden sonra): ABC-DEFGH ve 123-45678 → ABC45678 ve 123DEFGH.
- **İki noktadan** (2. ve 6. karakterden sonra): AB-CDEF-GH ve 12-3456-78 → AB3456GH ve 12CDEF78.

Bu sonuçlar python ile doğrulandı. Birden fazla noktadan çaprazlama mümkündür ve sürecin başarısını etkileyen faktörlerden biridir.

### 9.4 Diğer faktörler

Çaprazlama sonucu iki birey elde edilir; ikisinin de mi yoksa yalnız birinin mi kullanılacağına karar vermek gerekir. Durum kodlaması, yani bireylerin nasıl ifade edildiği, ve uygunluk fonksiyonu da performansı belirler.

## 10. Olumlu ve Olumsuz Yönler, Hiperparametre Ayarı

### 10.1 Değerlendirme

- **Olumlu yönler:** Genetik algoritmaların çaprazlama ve mutasyon sayesinde lokal maksimumlardan ve platolardan kurtulma şansı vardır. Doğa temelli bir yaklaşımdır.
- **Olumsuz yönler:** Ayarlanabilir çok fazla parametreye sahiptir. Bir problemde gösterilen başarıyı başka bir problemde tekrarlamak zordur. Diğer yöntemlerden daha iyi olduğuna dair teorik, matematiksel bir kanıt yoktur.

### 10.2 Parametre ve hiperparametre

Hoca "ayarlanabilir çok fazla parametreye sahip olmak" ifadesinin ne anlama geldiğini açmak için parametre ile hiperparametreyi ayırdı.

- **Parametre:** Makine öğrenmesinde modellerin veriye bakarak kendilerinin öğrendiği değerlerdir. Yapay sinir ağları ağırlıklarını kendileri öğrenir, karar ağaçları uzayı nereden böleceklerini kendileri öğrenir, SVM karar sınırının nereden geçeceğini kendisi öğrenir.
- **Hiperparametre:** Algoritmanın kendisinin bulamadığı, kullanıcının söylediği değerlerdir. Yapay sinir ağlarında aktivasyon fonksiyonu, gizli katmandaki nöron sayısı, katman sayısı, başlangıç değerleri, öğrenme oranı; SVM'de çekirdek (kernel) fonksiyonunun seçimi; genetik algoritmalarda mutasyon oranı, kaç noktadan çaprazlama yapılacağı, popülasyon büyüklüğü ve durumların nasıl temsil edileceği hiperparametredir.

Kullanıcı hiperparametreleri verir; algoritma bu hiperparametrelere ve veriye göre parametreler için iyi olduğunu tahmin ettiği değerleri bulur.

### 10.3 Hiperparametre ayarı bir lokal arama problemidir

Hoca bir örnek kurdu (ekrandan, 01:45:00): sekiz vezir genetik algoritmayla çözülecek ve dört hiperparametre var; her biri 1 ile 100 arasında değer alabiliyor (HP1, HP2, HP3, HP4: 1–100). Amaç en iyi hiperparametre ayarını bulmaktır; örneğin HP1=32, HP2=43, HP3=78 ve HP4=99 olduğunda en iyi sonuç elde ediliyor olsun (hocanın uydurduğu değerler).

**Soru (hoca):** Bu süreç geçen hafta konuşulan hangi örneğe benziyor?
**Cevap:** Bir öğrenci önce hırsızın kilit açmasını önerdi; hoca bunun yanlış olduğunu söyledi. Doğrusu bozuk televizyon örneğidir. Neden? Çünkü her denemede hedefe ne kadar yaklaşıldığı ölçülebilir: belli bir hiperparametre ayarıyla sekiz vezir 100 kez çözdürülüp kaçının çözüldüğü görülebilir. İçeriden bilgi alınabildiği, yani bir sezgisel fonksiyon olduğu için kasa açmaya benzemez.

Yani elde bir lokal arama problemi vardır; bu problemi çözecek algoritmanın hiperparametrelerini optimize etmek için yeni bir lokal arama problemi kurulur. Bu yalnızca genetik algoritmalar için değil, çok hiperparametreli bütün modeller için geçerlidir; hepsinde bir hiperparametre ince ayarı (fine tuning) yapmak gerekir.

Bu her zaman kolay değildir. Tek bir hiperparametre ayarının uygunluğunu ölçmek uzun sürebilir: bazı yapay sinir ağlarının eğitimi bir hafta sürer. Bir noktanın iyiliğini ölçmek teorik olarak mümkündür ama bir hafta alır; oradan yapılabilecek pek çok hareket vardır (bir değeri 32'ye, diğerini 44'e çekmek gibi).

> **Hocanın vurgusu:** Adımlarınızın her birinin maliyeti arttığında strateji çok daha önemli hale gelir. "Rastgele denerim, tutar" diyebilirsiniz, ama kaç denemede tutturacaksınız ve her deneme size neye mal oluyor? Orası önemli.

Bir haftalık eğitim evde yapılıyorsa elektriğe, bulutta yapılıyorsa faturaya yansır. Sistematik ya da lokal arama yapmak daha iyi performans sağlama olasılığı olan yaklaşımlardır.

Hiperparametre sayısının artması bir algoritmayı daha esnek yapar, çözebileceği problem türü sayısını arttırır; ama onları optimize etmek başlı başına bir problem olur. Hoca bunu uçak kokpitine benzetti: her tarafta çok sayıda düğme vardır, çünkü kontrol edebilmek gerekir; ama uçağı uçurmayı öğrenmek de o ölçüde zorlaşır.

## 11. Uygulamalar: Alan Tarama ve İki Nokta Arası Yol

### 11.1 Bir alanı tarama

Geçen hafta görülen alan tarama problemi genetik algoritmayla ele alındı. Slayttaki tanım (ekrandan, 01:45:00, küçük resim panelinden):

- Amaç: N×N'lik bir alanda 8 yöne hareket, $N \cdot N - 1$ adet hareket, minimum açıda dönüşle maksimum alanı gez.
- Hareketler arası açı miktarı az olsun, yumuşak dönüşler yapsın.
- İyilik fonksiyonu 2 bileşene sahip: min(açı) ve max(alan).
- Temsil: $(N \cdot N - 1)$ adet yönleri belirten sayılar.

<!-- BELİRSİZ: Temsil maddesindeki yön sayılarının aralığı küçük resimde "0-8" gibi okunuyor, kesin değil. -->

Genetik algoritmayla çözüm adımları:

1. Rastgele P adet çözümle başla.
2. G kez: çözümlerden çaprazlama ve mutasyonla yeni P adet çözüm üret (çaprazlama iki noktadan yapılmış).
3. Üretilen çözümlerin iyilik değerlerini hesapla: dönüş açıları minimum, gezilen alan maksimum olsun.
4. Yeni nesil = eski neslin bir kısmı + yeni neslin bir kısmı.

Son madde, bu uygulamada şimdiye kadar anlatılandan farklı olan kısımdır: eski nesil tamamen silinmez; yeni neslin en iyileri ile eski neslin en iyileri (örneğin yarı yarıya) birleştirilir. Böylece bazı bireyler daha uzun yaşar.

Hoca bulunan çözümlerden birini gösterdi: popülasyon büyüklüğü 5000, %1'lik değişim. 8×8'lik bir alanda 64 nokta vardır; bunları gezmek için 63 uzunluğunda bir yön dizisi yeter. Her çözüm (1,1) noktasından başlar; dizi örneğin "7 7 7" (o yönde üç adım), "2 2 2 2", "1 1 1", "6 5 5", "6 1 1" gibi yönlerle ilerler. Ortadaki grafikte yatay eksen nesil indisidir (200 nesil ilerletilmiş). Kırmızı eğri o nesildeki 5000 bireyin ortalama uygunluğunu, mavi eğri o neslin en iyi bireyinin uygunluğunu gösterir. En iyi birey nesiller boyunca iyice iyileşmiştir; daha da iyileşebilir mi, muhtemelen evet.

> **Hocanın vurgusu:** Bu problemi iyi anlayın, çünkü ödeviniz bununla çok ilgili olacak.

### 11.2 İki nokta arası yol bulma

Yeni uygulamada başlangıç ve bitiş noktaları verilir: şu noktadan başla, şu noktada bitir. Yol yine maksimum alanı geçmeli ve minimum dönüş açısına sahip olmalı. Bu kez iyilik fonksiyonunun üç bileşeni vardır:

- min(açı)
- max(alan)
- max(sonun hedefe yakınlığı)

Hocanın hatırladığı kadarıyla başlangıç yaklaşık (50, 50), bitiş (55, 55) idi. Slayttaki ayarlar (ekrandan, 01:55:00):

```text
P=5000;   % popülasyon büyüklüğü
mu=0.005; % mutasyon oranı
G=500;    % nesil sayısı
cross=2;  % 2 noktadan çaprazlama
Yeni nesil: eskinin 1/4'ü ve yeni neslin 3/4'ü
```

Bulunan çözümlerin hepsi aynı yerden başlayıp aynı yerde bitiyor; bazıları önce aşağı inip sonra dönüyor, bazıları hedeften uzaklaşıp yakınlaşarak geziniyor. Son noktanın hedefe yakın olması istendiği için yollar hedeften çok fazla ayrılmıyor. Hangisinin en iyi çözüm olduğu ayrı bir konu; ama genetik algoritmayla farklı farklı çözümler üretilebiliyor.

## 12. Birden Fazla İyilik Fonksiyonunu Birleştirmek

Bu tür problemlerde birden fazla amaç (objective) ya da uygunluk fonksiyonunu birleştirmek gerekebilir. Slayttaki başlıklar (01:55:00 karesindeki küçük resim paneli) ve hocanın açıklamaları:

- **Ölçekler aynı değilse etkileri farklılaşır; normalize etmek gerekir.**
- **Min ↔ Maks dönüşümleri:** Örnekteki üç bileşenin bazıları maksimum (alan, hedefe yakınlık), bazıları minimum (açı) istenir. Önce hepsi ya minimuma ya maksimuma çevrilmelidir. Bunlar zor dönüşümler değildir; örneğin uzaklık yerine yakınlık alınırsa minimizasyon maksimizasyona çevrilir.
- **Önem dereceleri farklıysa ağırlıklı işlem gerekir:** Üç kriterin hepsi çözümü isteyen kişi için eşit derecede önemli olmayabilir. Daha önemli olanların ağırlığı arttırılmalıdır.
- **Birleştirme işlemi:** Toplama, çarpma, maksimum alma ya da minimum alma. Bunlar iyimser ya da kötümser birleştirmeler olarak değerlendirilebilir. Çarpmada bileşenlerden biri kötüyse çok iyi olan diğerlerini de götürür; birey ancak her bileşende iyiyse yüksek uygunluk alır. Maksimum ve minimum almanın davranışı da toplama ve çarpmaya benzer.

Hoca genetik programlamaya bu derste geçmedi; bir sonraki derste genetik programlamadan başlanacağını söyledi. Genetik programlama bazı operatörleri genetik algoritmayla paylaşır, ama yapmaya çalıştığı şey çok farklıdır: program yazmaya çalışır.

## 13. Ödev Problemi: Drone'larla Alan Tarama

Dersin son bölümünde hoca birinci ödevin problemini anlattı (ekrandan, 02:10:00 ve 02:15:00). Problem, alan tarama uygulamasının bir benzeridir:

- 9×9'luk bir alan X adet drone ile taranacaktır. Drone'ların izleyeceği X adet yol genetik algoritma ya da tepe tırmanma ile bulunacaktır.
- Drone'lara alan içinde ortak bir başlangıç ve bitiş konumu verilir. Ödev metnindeki ızgarada üç farklı başlangıç/bitiş noktası işaretlidir (sol alt köşe, alt kenarın ortası ve alanın ortası); diğer olası noktalar yapısal olarak bunların benzeridir. Her denemede bütün drone'lar aynı noktadan başlar ve aynı noktada bitirir.
- Maksimum alan tarayabilmek için drone'ların gittikleri yollar birbirinden mümkün olduğunca farklı olmalıdır.
- Keskin dönüşler hızı düşürme gerektirdiğinden dönüş açıları minimize edilmelidir.
- Drone'lar aynı anda harekete başlar. Farklı yüksekliklerde hareket ettikleri varsayılır, çarpışma durumları dikkate alınmaz (uygunluk fonksiyonuna çarpışmadan kaçınmayı eklemek zorunlu değildir).
- Her çözüm önerisi / birey, X·M uzunlukta, yönleri ifade eden bir sayı dizisinden oluşabilir: ilk M'lik kısım birinci drone'un, ikinci M'lik kısım ikinci drone'un yolunu gösterir.
- X = 1, 2, 4 değerleri için, üç farklı başlangıç/bitiş noktasıyla denemeler yapılır.
- Denemelerde şu hiperparametrelerden ikisi incelenir: değerlendirme fonksiyonu (en az iki farklı), popülasyon büyüklüğü, mutasyon oranı.
- Sonuçlar tablolar ve grafiklerle (örneğin nesiller ilerledikçe taranan alanın ve uygunluğun değişimi) gösterilir.

Hoca, tepe tırmanmada "popülasyon büyüklüğü" ve "mutasyon" kavramlarının nasıl anlaşılacağını açıkladı: tepe tırmanma paralel tepe tırmanma olarak ele alınabilir, böylece bir popülasyon olur; bir bireyden yeni birey de mutasyonla üretilebilir. Labirentte bir noktadan gidilebilecek yer sayısı 4 ya da 8 gibi küçüktür. Ama burada 63 uzunluğunda bir yol varsa, her elemanı değiştirerek tek adımda gidilebilecek komşu sayısı çok büyür (her eleman için yaklaşık 8 seçenek, toplam beş yüz küsur – altı yüz kadar komşu). Bu yüzden komşular mutasyonla üretilebilir ya da hepsi üretilip içlerinden seçim yapılabilir.

**Soru:** Bir dil kısıtlaması var mı, örneğin Python'da yazabilir miyiz?
**Cevap:** Yazılabilir; dil önemli değildir. Hoca yine de öğrencilik döneminde farklı diller denemenin iyi olduğunu söyledi ve bunu genetik algoritmaya bağladı: herkesin aynı tepenin üstünde olması kötüdür; bütün kabiliyetleri tek bir yerde toplamak yerine biraz dağıtmak, birinin beklenmedik bir yüksekliğe çıkarmasına yol açabilir.

**Soru:** Adım sayısında bir sınır var mı?
**Cevap:** Adım sınırını öğrenci belirler. Tek drone ile 9×9'luk alanı gezmek için 81 noktayı dolaşan yaklaşık 80 hareket yeter. İki drone varken her birine 80 adım vermek mantıklı değildir; adım sayısı düşürülmelidir, dört drone için daha da düşürülmelidir. Yani X'in 1, 2 ve 4 değerleri için adım sayıları aynı olmayacaktır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Sekiz vezir probleminde uygunluk fonksiyonu "birbirini tehdit etmeyen vezir çiftlerinin sayısı" olsun. Bu fonksiyonun alabileceği en küçük ve en büyük değer nedir? Uygunlukları 24, 23, 20, 11 olan dört bireyin rulet tekerleği seçim olasılıkları nedir?

> **Çözüm:** En küçük değer 0 (bütün vezirler aynı satır, sütun ya da köşegende), en büyük değer $\binom{8}{2} = 28$. Olasılıklar $f_i / 78$: $24/78 \approx \%31$, $23/78 \approx \%29$, $20/78 \approx \%26$, $11/78 \approx \%14$.

**Soru 2** (ekrandan, 00:35:00): 32752411 ve 24748552 bireyleri 3. rakamdan sonra, 32752411 ve 24415124 bireyleri 5. rakamdan sonra tek noktadan çaprazlanırsa hangi çocuklar elde edilir?

> **Çözüm:** İlk çiftten 32748552 ve 24752411, ikinci çiftten 32752124 ve 24415411.

**Soru 3** (derste sözlü, 00:49:06; ekrandan, 00:50:00): Uygunluk değerleri 100, 1, 1, 1 olan bir popülasyonda rulet tekerleği seçimi yapılırsa ne olur? Çaprazlama bu durumda işe yarar mı?

> **Çözüm:** Olasılıklar yaklaşık %97, %1, %1, %1 olur; yeni popülasyonun hemen hemen hepsi birinci birey olur. Bir birey kendisiyle çaprazlanınca aynı birey çıktığı için çaprazlama yeni bir şey üretmez, yalnızca mutasyonun küçük değişiklikleri kalır.

**Soru 4** (ekrandan, 01:00:00): Aynı popülasyonda (1, 1, 1, 100) sıralama seçimi uygulanırsa seçilme olasılıkları ne olur?

> **Çözüm:** Sıra değerleri 1, 2, 3, 4 yeni uygunluk olur; olasılıklar $1/10, 2/10, 3/10, 4/10$.

**Soru 5** (derste sözlü, 00:57:33; ekrandan, 01:00:00): N uzunluğunda, öğelerinin %85'i A, %15'i B olan bir dizi nasıl üretilir? Seçenek sayısı çoksa ne yapılır?

> **Çözüm:** 1-100 arası rastgele sayı üretip 85'ten küçükse A, değilse B yazılabilir. Çok seçenek varsa `if` zinciri yerine öğeleri olasılıklarıyla orantılı sayıda içeren bir yardımcı dizi kurulur ve bu diziden rastgele bir indis seçilir.

**Soru 6** (ekrandan, 01:10:00): CityList1 = (3 5 7 2 1 6 4 8) ve CityList2 = (2 5 7 6 8 1 3 4) bireylerine 3. elemandan sonra standart çaprazlama uygulanırsa ne olur? Gezgin satıcı için sorun nedir?

> **Çözüm:** Çocuklar (3 5 7 6 8 1 3 4) ve (2 5 7 2 1 6 4 8) olur. Birincisinde 3 iki kez geçer ve 2 yoktur; ikincisinde 2 iki kez geçer ve 3 yoktur. Rota her şehirden tam bir kez geçme özelliğini kaybeder.

**Soru 7** (ekrandan, 01:15:00): Parent1 = A B C D E F G, Parent2 = E B D C F G A, şablon = 0 1 1 0 0 1 0 için sıra tabanlı çaprazlamayla Child1 ve Child2'yi bulun.

> **Çözüm:** Child1: B, C, F yerinde kalır; A, D, E, G Parent2 sırasına göre E, D, G, A olur → E B C D G F A. Child2: B, D, G yerinde kalır; E, C, F, A Parent1 sırasına göre A, C, E, F olur → A B D C E G F.

**Soru 8** (ekrandan, 01:20:00): 100 bin noktadan oluşan Mona Lisa TSP'sinde bulunan bir çözümün en iyi çözüm olduğunu bilmek mümkün mü? Brute force ile kaç yol denemek gerekir?

> **Çözüm:** Hayır; minimum yolun uzunluğu bilinmeden bir çözümün en iyi olduğu söylenemez. Brute force ile $100000!$ yol denemek gerekir; bu pratikte imkânsızdır.

**Soru 9** (ekrandan, 01:25:00): $f(x) = \cos(x/3)\sin(x/4)$, $x \in [0, 127]$ tam sayı. Kaç bitlik gösterim gerekir? Başlangıç bireyleri a: 0000011, b: 1110111, c: 0010000, d: 0011010 hangi $x$ değerlerini gösterir? Fonksiyonun maksimumu nerededir?

> **Çözüm (derste verilmedi):** 128 değer için 7 bit yeterlidir. a = 3, b = 119, c = 16, d = 26; uygunlukları yaklaşık $f(3) \approx 0.368$, $f(119) \approx 0.385$, $f(16) \approx -0.440$, $f(26) \approx -0.156$. 128 değerin hepsi denenince (brute force) maksimum $x = 57$'de, $f(57) \approx 0.982$ bulunur (python ile hesaplandı).

**Soru 10** (ekrandan, 01:40:00): ABCDEFGH ve 12345678 bireylerini (a) 3. karakterden sonra tek noktadan, (b) 2. ve 6. karakterden sonra iki noktadan çaprazlayın.

> **Çözüm:** (a) ABC45678 ve 123DEFGH. (b) AB3456GH ve 12CDEF78.

**Soru 11** (derste sözlü, 01:45:12): Dört hiperparametresi olan (her biri 1-100 arası) bir genetik algoritmanın en iyi hiperparametre ayarını bulmak, geçen hafta konuşulan "hırsızın kasa açması" örneğine mi yoksa "bozuk televizyon" örneğine mi benzer? Neden?

> **Çözüm:** Bozuk televizyon örneğine benzer. Her ayarla algoritma çalıştırılıp başarısı (örneğin 100 denemede kaç kez çözdüğü) ölçülebilir; yani hedefe ne kadar yaklaşıldığını gösteren bir sezgisel fonksiyon vardır. Kasa açmada böyle bir ara bilgi yoktur. Bu yüzden hiperparametre ayarı bir lokal arama problemidir.

**Soru 12** (ekrandan, 02:10:00; ödev problemi): 9×9'luk bir alan X adet drone ile taranacak. Drone'lar ortak bir noktadan başlayıp aynı noktada bitirecek; yollar birbirinden mümkün olduğunca farklı olmalı, dönüş açıları minimize edilmeli, çarpışma dikkate alınmayacak. Her birey X·M uzunlukta yön dizisidir. X = 1, 2, 4 ve üç farklı başlangıç/bitiş noktası için yollar genetik algoritma ya da tepe tırmanma ile bulunacak; en az iki değerlendirme fonksiyonu, popülasyon büyüklüğü ve mutasyon oranından ikisi incelenecek.

> **Çözüm (derste verilmedi):** Derste yalnızca ipuçları verildi: tepe tırmanma paralel tepe tırmanma olarak ele alınabilir, komşular mutasyonla üretilebilir. Adım sayısı drone sayısına göre azaltılmalıdır; tek drone için yaklaşık 80 adım yeterken 2 ve 4 drone'da drone başına adım sayısı düşürülmelidir.

## Dersin Toparlaması

Bu derste lokal arama ailesinin son üyesi olarak genetik algoritmalar işlendi. Genetik algoritma, paralel tepe tırmanma gibi tek bir çözüm yerine bir popülasyonu takip eder; farkı yeni nesli üç operatörle üretmesidir. Seçme, uygunluğu yüksek bireyleri olasılıklı olarak öne çıkarır. Çaprazlama, farklı bireylerdeki iyi lokal parçaları birleştirir. Mutasyon ise bireyler birbirine benzediğinde çeşitliliği geri getirir. Sekiz vezir örneğinde bir neslin adım adım nasıl üretildiği görüldü. Rulet tekerleği seçiminin tek bir baskın bireye çöküş tehlikesi ve buna karşı sıralama seçimi tartışıldı. Gezgin satıcı probleminde standart ve uniform çaprazlamanın geçersiz rotalar ürettiği, sıra tabanlı çaprazlamanın bu sorunu çözdüğü gösterildi. Fonksiyon optimizasyonunda bit gösterimi ve çok değişkenli kromozomlar ele alındı.

Dersin ikinci yarısında genetik algoritmanın performansını belirleyen faktörler (popülasyon büyüklüğü, mutasyon oranı, çaprazlama noktası sayısı, kodlama ve değerlendirme fonksiyonu) ve bunların hiperparametre olarak ayarlanmasının kendisinin bir lokal arama problemi olduğu vurgulandı. Alan tarama ve iki nokta arası yol bulma uygulamaları, birden fazla iyilik fonksiyonunun normalize edilip ağırlıklandırılarak birleştirilmesi gereğini gösterdi ve doğrudan ödev problemine bağlandı. Bir sonraki derste genetik algoritmayla benzer operatörler kullanan ama program yazmayı amaçlayan genetik programlamaya geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
