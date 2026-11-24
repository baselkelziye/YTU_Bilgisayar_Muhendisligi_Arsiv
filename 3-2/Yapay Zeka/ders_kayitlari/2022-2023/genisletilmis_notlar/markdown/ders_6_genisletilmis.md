# Ders 6 Genişletilmiş Notu: Genetik Algoritmalar ve Genetik Programlama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Lokal Arama Algoritmalarının Tekrarı
- 2. Genetik Algoritmanın Temel Kavramları
- 3. Genetik Algoritmanın Sözde Kodu
- 4. 8 Vezir Problemi Üzerinde Bir Nesil
- 5. Kromozom Seçim Türleri
- 6. Gezgin Satıcı Problemi ve Permütasyon Çaprazlamaları
- 7. Optimal Çözümü Bilmek Mümkün mü?
- 8. Genetik Algoritma ile Fonksiyon Optimizasyonu
- 9. Performansı Etkileyen Faktörler ve Değerlendirme
- 10. Uygulamalar: Alan Tarama ve İki Nokta Arası Yol
- 11. İyilik Fonksiyonlarının Birleştirilmesi
- 12. Genetik Programlama
- Örnek Sorular

## 1. Lokal Arama Algoritmalarının Tekrarı

Ders, önceki haftada başlanan lokal arama algoritmalarının kısa bir tekrarıyla açıldı. Lokal arama algoritmalarının önceki haftalarda görülen algoritmalarla hem benzerlikleri hem farkları vardır. Benzerliklerden biri sezgisel olmalarıdır. Sezgiden kastedilen, o anda bulunulan durumun hedefe ne kadar uygun, ne kadar yakın ya da uzak olduğunu tahmin etmeyi sağlayan bir fonksiyon ya da bilgidir.

### 1.1 Asıl fark: çözülen problem türü

Hoca, lokal arama algoritmalarını öncekilerden ayıran çok daha temel bir farkın ne olduğunu sordu.

**Soru:** Lokal arama algoritmaları optimal olmadıkları için mi farklıydı? **Cevap:** Muhtemelen optimal değiller, bu doğru; ama optimal olmayan algoritmalar daha önce de görüldü. Asıl fark, hangi tür problemlere çözüm bulduklarıdır.

Önceki algoritmaların hepsinde bir başlangıç ve bir hedef verilir, istenen bu ikisi arasındaki yoldur (path). Yol zaten bir operatör dizisidir: A şehrinden B şehrine giden yol ya da bir problemi bir durumdan başka bir duruma dönüştürmek için uygulanacak operatörler. Lokal aramada ise başlangıç ve bitiş verilmez; yalnız istenen duruma dair bazı özellikler söylenir ve bu özellikler sezgi olarak kullanılır. Yine bir başlangıç durumundan başlanıp hedefe doğru ilerlenir, ama kullanıcı oraya nasıl varıldığıyla ilgilenmez. Kullanıcının isteği "bana şu şartı sağlayan, şu fonksiyonu minimize eden bir durum bul" biçimindedir.

Slayttaki tanım şöyledir (ekrandan, 00:10:00):

- Birçok optimizasyon probleminde hedefe giden yol / uygulanan hareketler önemsizdir. Hedef durumun kendisi istenen çözümdür.
- Amaç, arama uzayında istenen kısıtlara / özelliklere sahip ya da fayda fonksiyonunu maksimum yapan durumu bulmaktır. Örnek: n-vezir, zirve bulma.
- Bu durumlarda lokal arama algoritmaları kullanılır.
- Hafızada sadece mevcut durum tutulur ve düzeltilmeye çalışılır.
- Çok az hafıza gerekir.

n-vezir probleminde kullanıcının tek derdi, n veziri n×n'lik bir satranç tahtasına hiçbiri diğerini tehdit etmeyecek şekilde yerleştirmektir. Rastgele bir yerden başlanır, adım adım ilerlenir ve belki sonunda bir çözüm bulunur; ama kullanıcı nereden başlandığını, hangi operatörlerin kullanıldığını sormaz. Yaklaşım tamamen çözüm odaklıdır.

### 1.2 Tepe tırmanma

Lokal arama algoritmalarının en temeli tepe tırmanmadır. Bir fonksiyon maksimize ediliyorsa tepe tırmanma, tersi yapılıyorsa "yokuş inme" diye düşünülebilir. Ana fikir: her zaman şimdiki durumu en fazla geliştiren yönde adım at. Bu, yoğun siste Everest'e tırmanmaya benzetilmişti, çünkü etraf çok az görülür.

Hoca, bütün alanı görüp en yüksek zirveye doğrudan gitmenin gerçek hayatta bazen mümkün olabileceğini, ama bilgisayarda uğraşılan problemlerde mümkün olmadığını söyledi. Bu problemler genelde iki boyutlu değildir ve arama uzayı çok büyüktür; bütün alanı değerlendirmek imkansızdır. Yapılabilecek en fazla şey, bulunulan noktadan başlayıp iyileştiren yöne adımlar atmaktır. Tepe tırmanmanın tepede olduğunu sanıp aslında tepede olmayabileceği (lokal maksimuma takılma), 8 vezirde performansının çok iyi olmayabileceği önceki derste görülmüştü.

### 1.3 Çözüm alternatifleri

Slayttaki alternatifler şunlardır (ekrandan, 00:15:00):

- Tepe tırmanmayı farklı başlangıçlarla tekrarlamak (random-restart hill climbing)
- Benzetimli tavlama (simulated annealing)
- Paralel tepe tırmanma (local beam search)

Lokal arama algoritmalarının tamamı başlangıç durumuna bağlıdır: başlangıç değişince varılan yer değişir. Hoca bir eğri üzerinde farklı noktalardan başlayınca farklı tepelere varıldığını gösterdi. Bu yüzden farklı çözümlere ulaşmanın en çok tercih edilen yolu farklı başlangıçlar kullanmaktır.

Benzetimli tavlamada fikir, her zaman iyileştirme yapmak yerine ara sıra konforu bozan, kötüleştiren adımlara izin vermektir. Hoca bunu gerçek hayattaki "konfor alanından çıkmak" sözüne benzetti: sizi biraz kötüye götüren, biraz yoran bir şey sonunda daha iyi bir şeye yol açabilir. Yöntemin çıkış noktası demirin soğutulmasıdır.

Paralel tepe tırmanma ise tek bir dağcı yerine birçok dağcı göndererek daha geniş bir alanın taranmasını sağlar. Bugünkü konu, genetik algoritmalar, bu fikrin üzerine oturur: yapı aynıdır, yalnız yeni bireylerin (yeni çözümlerin) üretilme mekanizması farklıdır.

### 1.4 Sezginin rolü: televizyon ve kasa

Hoca önceki derste anlatılan bozuk televizyon ve kasa örneğini hatırlattı.

**Soru:** Kasa ile televizyonun farkı neydi? **Cevap (bir öğrenci):** Birinde değişimi görebiliyorduk. **Hocanın açıklaması:** Televizyonun düğmeleri çevrilince ekrandaki değişim görülür. Bu değişim görüntünün iyileşip kötüleştiğini, yani hedefe yaklaşılıp uzaklaşıldığını gösterir; yani bir sezgi verir. Kasada böyle bir geri bildirim yoktur; açmaya yaklaşılıp uzaklaşıldığı görülmez, bu yüzden sezgisel arama yapılamaz, kör arama gerekir. Eski filmlerde kasayı stetoskopla dinleyenler aslında sezgi edinmeye çalışır.

> **Hocanın vurgusu:** Sezgiler problemi daha iyi çözmeyi sağlamaz, daha hızlı çözmeyi sağlar.

## 2. Genetik Algoritmanın Temel Kavramları

Genetik algoritmaların kendine özgü bir jargonu vardır. Önceki derslerde "durum" ya da "çözüm" denilen şeye burada kromozom ya da birey denir. Kromozom ya da birey görülen yerde kastedilen bir çözüm önerisidir.

Slayttaki tanımlar şöyledir (ekrandan, 00:20:00):

- Genetik algoritmalar evrim mekanizmasına (en iyinin yaşaması) dayanır.
- Amaç, uygunluk fonksiyonunun (fitness function) maksimizasyonu / minimizasyonu (optimizasyonu)dur.
- Uygunluk fonksiyonu: toplumdaki her kromozomun / bireyin / durumun ne kadar iyi olduğunu gösteren fonksiyondur. Büyük değer iyi / uygun bireydir.
- K adet rastgele üretilmiş kromozom / durum / çözüm hipotezi ile başlar. Durumlar kümesine popülasyon denir.
- Kromozom / durumlar sıralı ya da sırasız karakter kümeleri ile temsil edilir. Genelde sayılar ya da 0 ve 1'lerden oluşur.

Fitness fonksiyonu, lokal aramadaki sezgisel fonksiyonun karşılığıdır: çözümün bizim açımızdan iyiliğini ölçer. Büyük değerin iyi sayılması bir tercihtir; minimizasyon yapılıyorsa küçük olan iyi kabul edilir.

Toplum ya da popülasyon birden çok bireyden oluşan yapıdır. Paralel tepe tırmanmada tek dağcı yerine K dağcı gönderiliyordu; bu K dağcı, burada K bireylik bir popülasyona karşılık gelir. K adet rastgele kromozomla başlamak da paralel tepe tırmanmadaki K rastgele başlangıçla aynıdır.

Paralel tepe tırmanmada K çözümden gidilebilecek yeni çözümler bulunur, bunların içinden fitness'a göre yine K tanesi seçilir ve böyle devam edilir. Genetik algoritmanın paralel tepe tırmanmadan farkı yalnız K bireyden yeni K bireyin üretilme sürecidir. Bu süreçte üç işlem vardır: seçme (selection), çaprazlama (crossover) ve mutasyon.

## 3. Genetik Algoritmanın Sözde Kodu

Slayttaki algoritma şöyledir (ekrandan, 00:25:00; kaynak: AIMA sözde kodu):

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

Fonksiyon bir popülasyon ve bir fitness fonksiyonu alır, popülasyonun içinden bir birey döndürür. `repeat ... until` döngüsü, en az bir birey yeterince iyi olana kadar ya da önceden belirlenen süre geçene kadar sürer.

Döngünün içinde önce boş bir yeni popülasyon kurulur. İç döngü popülasyon büyüklüğü kadar döner. Her turun sonunda bir çocuk üretilip yeni popülasyona eklendiği için iç döngü bittiğinde yeni popülasyonda eski popülasyon kadar yeni çözüm olur. Sonra yeni popülasyon eskisinin yerine yazılır: bir önceki nesil "öldürülüp" yerine yeni nesil getirilir. Dış döngünün her turu bir nesil geçişidir. Döngüden çıkınca popülasyonun en iyi bireyi çıktı olarak verilir.

### 3.1 "Random selection" tamamen rastgele değildir

İç döngüde popülasyondan iki birey seçilir. Hoca, buradaki "random selection" ifadesinin çok doğru olmadığını vurguladı: seçim tamamen rastgele değil, fitness fonksiyonuna göre rastgeledir. Örneğin 100 bireylik bir popülasyondan yeni 100 birey üretilecekse, bu neslin hangi bireylerinin üretime katılacağına karar verilmelidir. Bir fitness fonksiyonu optimize edildiği için fitness'ı yüksek olanları almak mantıklıdır ki çözümler daha da iyileşsin. Tamamen rastgele seçim yapılırsa bir ilerleme görülmez. Bunun yerine fitness değerine göre her bireye bir seçilme olasılığı verilir.

Seçilen iki bireyden bir çocuk üretilir, çocuk küçük bir olasılıkla mutasyona uğratılır ve yeni popülasyona eklenir.

> **Hocanın vurgusu:** Genetik algoritma paralel tepe tırmanmaya çok benzer; tek fark K bireyden yeni K bireyin üretim sürecidir. Ana fikir aynıdır.

## 4. 8 Vezir Problemi Üzerinde Bir Nesil

Önceki derste tepe tırmanmayla çözülen 8 vezir problemi bu kez genetik algoritmayla ele alındı. Slayttaki şekil bir neslin bütün adımlarını gösterir (ekrandan, 00:30:00).

### 4.1 Kodlama

Her birey bir tahtadır ve 8 rakamla gösterilir. 24748552 bireyinde ilk rakam 2, birinci sütunun ikinci satırında vezir olduğunu; ikinci rakam 4, ikinci sütunun dördüncü satırında vezir olduğunu; üçüncü rakam 7, üçüncü sütunun yedinci satırında vezir olduğunu gösterir. Yani dizi, sekiz vezirin her sütunda bulunduğu satır indisleridir.

### 4.2 Fitness fonksiyonu

Uygunluk fonksiyonu, birbirini tehdit etmeyen vezir çiftlerinin sayısıdır. Hoca burada "tehdit eden" değil "tehdit etmeyen" çiftlerin sayıldığına dikkat çekti. En küçük değer 0, en büyük değer 8'in ikili kombinasyonu kadardır:

$$\binom{8}{2} = \frac{8 \times 7}{2} = 28$$

Bu sayı maksimize edilir; amaç, mümkünse fitness'ı 28 olan bir tahta bulmaktır. Tehdit eden çiftler sayılsaydı minimize edilirdi.

### 4.3 Bir neslin adımları

Şekildeki adımlar şöyledir (ekrandan, 00:30:00; fitness değerleri python ile doğrulandı):

| (a) Başlangıç popülasyonu | (b) Fitness | Olasılık | (c) Seçim | (d) Çaprazlama | (e) Mutasyon |
|---|---|---|---|---|---|
| 24748552 | 24 | %31 | 32752411 | 32748552 | 32748152 |
| 32752411 | 23 | %29 | 24748552 | 24752411 | 24752411 |
| 24415124 | 20 | %26 | 32752411 | 32752124 | 32252124 |
| 32543213 | 11 | %14 | 24415124 | 24415411 | 24415417 |

Adımlar:

1. Her birey için fitness hesaplanır: 24, 23, 20, 11.
2. Fitness değerleri, toplamları 1 olsun diye toplamlarına bölünerek seçilme olasılıklarına çevrilir:

$$\frac{24}{24+23+20+11} = \frac{24}{78} \approx \%31, \qquad \frac{23}{78} \approx \%29, \qquad \frac{20}{78} \approx \%26, \qquad \frac{11}{78} \approx \%14$$

3. Bu olasılıklarla dört seçim yapılır. Birinci birey bir kez, ikinci birey iki kez, üçüncü birey bir kez seçilmiş; dördüncü hiç seçilmemiştir. Hoca bunun olağan olduğunu söyledi: %31 ya da %14 olasılık kesin seçilme ya da kesin seçilmeme anlamına gelmez. Burada %29'luk birey iki kez, %31'lik birey bir kez seçilmiştir.
4. Seçilenler çiftler halinde eşlenir. Her çift rastgele bir noktadan bölünür; birinin sol parçası ile diğerinin sağ parçası birleştirilerek iki çocuk üretilir. Birinci çiftte kesim üçüncü rakamdan sonra (327|52411 ve 247|48552 → 32748552, 24752411), ikinci çiftte beşinci rakamdan sonradır (32752|411 ve 24415|124 → 32752124, 24415411).
5. Mutasyon küçük bir olasılıkla rakamları rastgele başka bir rakamla değiştirir. Hoca, oran %10 olsa elimizdeki 32 rakamdan yaklaşık 3'ünün değişeceğini söyledi. Şekilde üç rakam değişmiştir: 32748552 → 32748152, 32752124 → 32252124, 24415411 → 24415417. Hoca bunu "5'i 1, 7'yi 2, 1'i 7 yapmış" diye okudu.

### 4.4 Çaprazlama tahtada ne demektir?

Hoca, 8 vezirde çaprazlamanın gerçekte neye karşılık geldiğini tahta resimleriyle gösterdi. İki tahtanın birinin sol sütunları ile diğerinin sağ sütunları birleştirilir; ortaya yeni bir tahta çıkar. Bunun daha iyi mi daha kötü mü olduğu ayrı bir konudur. Diğer parçalar birleştirilerek ikinci bir çocuk da üretilebilir. Bazı uygulamalar bir çiftten iki çocuk, bazıları tek çocuk üretir; bu, probleme göre deneme yanılmayla belirlenir.

**Soru:** Birinci aşamadan ikinciye geçerken birinciyle ikinci çaprazlandı, sonra dördüncü kullanılmadı, ikinciyle üçüncü kullanıldı. Bu, olasılığa göre rastgele bir seçim mi; yani birle üç, birle dört de olabilir miydi? **Cevap:** Evet, tamamen rastgeledir. "Bu olasılıklarla bana rastgele dört birey seç" denir. Seçilenlerin sırasının bir anlamı yoktur; birle üç ya da birle dört de eşlenebilirdi.

## 5. Kromozom Seçim Türleri

Hoca seçim türlerini anlatmak için ekrana yeni bir örnek yazdı (ekrandan, 00:40:00). Dört bireyin fitness değerleri toplamları 100 olacak şekilde seçildi: A = 90, B = 2, C = 5, D = 3.

### 5.1 Rulet tekeri seçimi

Fitness değerine doğrudan bağlı olasılık hesabına rulet tekeri seçimi denir. Bu örnekte olasılıklar:

| Birey | Fitness | Olasılık |
|---|---|---|
| A | 90 | %90 |
| B | 2 | %2 |
| C | 5 | %5 |
| D | 3 | %3 |

Bu olasılıklarla seçim yapılırsa neredeyse hep A seçilir. A, örneğin [3 2 7 8 1 5 6 4] gibi bir birey olsun. Dört seçimin dördü de A olursa iki A eşlendiğinde nereden bölünürse bölünsün çaprazlama yine A'nın kendisini verir. Böyle bir seçim crossover'ın işe yarama şansını büyük ölçüde azaltır ve iş tamamen mutasyona kalır.

### 5.2 Sıralama seçimi

Sıralama seçiminde fitness değerleri aynı kalır ama doğrudan kullanılmaz. Bireyler iyiliklerine göre sıralanır; en düşük fitness'a 1, ondan büyüğüne 2, sonra 3, en büyüğüne 4 verilir. Olasılık sıra numarasının sıra toplamına bölünmesiyle bulunur:

| Birey | Fitness | Sıra | Hesap | Olasılık |
|---|---|---|---|---|
| A | 90 | 4 | $4/(1+2+3+4)$ | %40 |
| B | 2 | 1 | $1/(1+2+3+4)$ | %10 |
| C | 5 | 3 | $3/(1+2+3+4)$ | %30 |
| D | 3 | 2 | $2/(1+2+3+4)$ | %20 |

Rulet tekeri seçiminde fitness değerleri doğrudan olasılığa çevrilirken burada önce sıralama yapılır, en kötüye en küçük, en iyiye en büyük rakam verilir ve olasılıklar bu sıralara göre hesaplanır. Böylece bireyler arasındaki farklar çok daha küçülür.

Hoca iki yaklaşımı şöyle karşılaştırdı: rulet tekeri seçimi "hep iyi olan kazansın" fikrine odaklanır. Bu durumda popülasyondaki herkes optimizasyon yüzeyinin çok dar bir alanına, aynı dağın etrafına sıkışabilir. Sıralama seçimi ise çeşitliliği artırmaya yönelik bir yaklaşımdır; çaprazlamanın bireyleri farklı yerlere götürebilmesine fırsat verir.

### 5.3 Soru-cevap: baskın bir bireyi çaprazlamak

**Soru:** Biri %90, biri %5 iken A ile B'yi çaprazlamak çok verimsiz değil mi; burada başka bir yöntem kullanmak daha mantıklı olmaz mı? **Cevap:** Hoca soruyu geri çevirdi: 90'lık birey kiminle çaprazlansın? Kiminle çaprazlanırsa çaprazlansın büyük olasılıkla 90'dan düşük bir şey çıkacaktır. Yine de daha iyi bir şey çıkma ihtimali üzerinde durulur; amaç %90 değerini daha da iyileştirmektir. Bu örnekte bir birey çok iyi, ötekiler çok kötü olduğu için çaprazlamadan büyük olasılıkla bir şey çıkmaz. Bu durumda diğer mekanizmaya, mutasyona bakılır: A mutasyona uğratılırsa belki daha iyi bir şey elde edilir.

## 6. Gezgin Satıcı Problemi ve Permütasyon Çaprazlamaları

Aradan sonra lokal arama problemlerinin en ünlülerinden biri olan gezgin satıcı problemine (TSP) geçildi.

### 6.1 Problem

Bir satıcının gitmek istediği belirli şehirler vardır ve hepsine gitmek ister. Bulunması gereken, şehirlerin hangi sırayla ziyaret edileceğidir. Amaç toplam yolun minimum olmasıdır; çok benzin ve zaman harcanmasın. Yani N şehir hangi sırayla birleştirilirse rotanın uzunluğu en kısa olur?

Problem her türlü lokal arama algoritmasıyla çözülebilir; derste genetik algoritmayla ele alındı.

### 6.2 Kodlama ve fitness

Sekiz şehir için birey, şehirlerin bir sıralamasıdır. Örneğin bir çözüm önerisi "3 numaralı şehirden başla, oradan 5'e, 5'ten 7'ye, 7'den 2'ye git ..." diye okunur. Bir çözüm önerisinin iyiliği, art arda gelen şehirler arasındaki mesafelerin toplamıdır: 3 ile 5 arası, artı 5 ile 7 arası, artı 7 ile 2 arası, ... Bu toplam rota uzunluğu fitness değeridir ve burada küçük olan iyidir.

Slayttaki demo 40 rastgele noktalık bir harita üzerindedir (ekrandan, 01:00:00, slayt önizlemesi). Popülasyon büyüklüğü 100 olsun. Her birey 1'den 40'a kadar sayıların rastgele karıştırılmış halidir; bütün şehirlerden geçmesi gerektiği için her çözüm önerisi böyle bir permütasyon olmak zorundadır. Şekillerde birinci nesildeki en iyi bireyin rotası çok karışıktır; daha sonraki nesillerdeki (örneğin 50. ve 100. nesil) en iyi bireylerin rotaları belirgin biçimde düzelir.

### 6.3 Standart çaprazlamanın sorunu

Standart çaprazlama bu probleme doğrudan uygulanırsa sorun çıkar. Slayttaki örnek (ekrandan, 01:00:00, slayt önizlemesi):

```text
CityList1  (3 5 7 | 2 1 6 4 8)
CityList2  (2 5 7 | 6 8 1 3 4)

Standart crossover sonrası yeni nesil:
CityList1  (3 5 7 6 8 1 3 4)
CityList2  (2 5 7 2 1 6 4 8)
```

Üretilen listeler çözüm önerisi değildir, çünkü bir çözümün her şehirden geçmesi gerekir. Yukarıdaki çocuk 2'den hiç geçmez, 3'ten iki kez geçer; aşağıdaki çocuk 3'ten geçmez, 2'den iki kez geçer. Standart çaprazlama çözüm üretemez; çaprazlama işleminin değiştirilmesi gerekir.

### 6.4 Uniform crossover

Uniform crossover'da kromozom boyutunda rastgele 0 ve 1'lerden oluşan bir şablon (template) oluşturulur. Şablondaki 0'lar için P1 ve P2'nin değerleri yer değiştirir; 1'ler için değerler aynen alınır. Slayttaki örnek (ekrandan, 01:00:00):

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| P1 | A | B | C | D | E | F | G | H | I | J |
| P2 | E | F | J | H | B | C | I | A | D | G |
| T | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 | 1 |
| C1 | A | F | C | D | B | C | I | H | D | J |
| C2 | E | B | J | H | E | F | G | A | I | G |

Örneğin birinci konumda T = 1 olduğu için C1'e A, C2'ye E aynen kopyalanır; ikinci konumda T = 0 olduğu için yerler değişir: C1'e F, C2'ye B gelir (python ile doğrulandı).

**Soru:** Bu, gezgin satıcıya bir çözüm oldu mu? **Cevap:** Olmadı. C1'de C ve D, C2'de E ve G tekrar eder. Bu çaprazlama da istenen şeyi sağlamaz.

### 6.5 Sıra tabanlı (order-based) crossover

Sıra tabanlı crossover'ın başlangıcı uniform crossover'a benzer: yine rastgele bir 0-1 şablonu oluşturulur. Slayttaki adımlar (ekrandan, 01:05:00):

- Kromozom boyutunda rastgele 1 ve 0'lardan oluşan template oluştur.
- Child1 için:
  - Template'de 1 olan indislerin Parent1'deki değerlerini al, Child1'in aynı indisine koy. Child1'de bazı boşluklar kalır.
  - Template'de 0 olan indislerin Parent1'deki değerlerini al (A D E G).
  - Bu listedekileri Parent2'deki sıralarına göre diz (E D G A).
  - Elde edilen diziyle Child1'in boşluklarını bu sırayla doldur.
- Child2 için aynı prosedür uygulanır: (E C F A) → (A C E F).

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| Parent 1 | A | B | C | D | E | F | G |
| Parent 2 | E | B | D | C | F | G | A |
| Template | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
| Child 1 | E | B | C | D | G | F | A |
| Child 2 | A | B | D | C | E | G | F |

Child1'in adım adım kurulması:

1. Template'de 1 olan konumlar 2, 3 ve 6'dır. Parent1'deki B, C, F aynı konumlara yazılır: `_ B C _ _ F _`.
2. 0 olan konumlar 1, 4, 5 ve 7'dir. Parent1'de bu konumlardaki değerler A, D, E, G'dir.
3. Bu dört harf Parent2'de hangi sırayla geçiyorsa o sıraya dizilir. Parent2'de önce E, sonra D, sonra G, en sonda A gelir: E D G A.
4. Boşluklar bu sırayla doldurulur: `E B C D G F A`.

Child2 için de Parent2'nin 1 olan konumlarındaki B, D, G aynen kalır; 0 olan konumlardaki E, C, F, A ise Parent1'deki sıralarına göre A, C, E, F diye dizilip boşluklara konur: `A B D C E G F` (python ile doğrulandı).

**Soru:** Bu bir çözüm mü? **Cevap:** Evet. Her şehre ulaşılır ve şehirler tekrar etmez. Bunun garantisi şudur: Child1, Parent1'in bir kısmı aynı yerde duran (B, C, F), geri kalanının yalnız yeri karıştırılmış halidir. Parent2'den Parent1'e değer aktarılmaz; değişiklikler Parent1'in kendi içinde yapılır. Child2 de aynı şekilde Parent2'nin kendi içinde yeniden düzenlenmesiyle oluşur. Bu sayede tekrarlı şehir çıkmaz.

### 6.6 Soru-cevaplar

**Soru:** Template rastgele oluşturuluyor. Parent1'in başarısı çok yüksekken template tamamen 0 gelirse her şey karıştırılır; o zaman başarı öncekine göre artmamış olur, değil mi? **Cevap:** Doğru. Child1 ve Child2'nin Parent1 ve Parent2'den daha iyi olacağına dair bir şart yoktur. Temenni budur, ama bu algoritmalar bunu hiçbir şekilde garanti etmez; her nesilde mutlaka ilerleme olacak diye bir şey yoktur. İlerlemeyi sağlamak için algoritmaya ekler yapılabilir; bunun bir örneği ileride görüldü (bkz. Bölüm 10).

**Soru:** İki ebeveyn kullanılıyor ama burada çaprazlama yok gibi; o zaman iki ebeveyne gerek var mı? **Cevap:** Var, çünkü karıştırma rastgele yapılmaz; Parent2'deki sıra kullanılır. Parent2 hiç kullanılmasaydı ikili olmanın anlamı kalmazdı; Parent1 kendi içinde değiştirilerek yeni çocuklar üretilebilirdi.

## 7. Optimal Çözümü Bilmek Mümkün mü?

Sonraki slaytta gezgin satıcı probleminin Mona Lisa versiyonu gösterildi (ekrandan, 01:10:00). Resimde 100 bin nokta vardır; kimi yerler daha yoğun, kimi yerler daha seyrektir. Noktalar elini kaldırmadan tek bir çizgiyle birleştirilmiştir. Yani bu, 100 bin şehirli bir gezgin satıcı problemidir. Slayttaki sorular şunlardır:

- 100 bin noktayı elini kaldırmadan birleştir. En kısa yol?
- Bir çözümün en iyi çözüm olduğunu bilmek mümkün mü?

**Soru:** Bulunan çözümün en iyi çözüm olduğu söylenebilir mi? **Cevap (bir öğrenci):** Büyük ihtimalle söylenemez; bir şehre gelindiği anda diğer olasılıklar elenmiş olur ve geri dönülemez. **Hocanın açıklaması:** Daha iyi bir çözüm olmadığını kanıtlamak için bütün olasılıkları ortaya koymak gerekir. Bu olasılıkların sayısı 100 bin faktöriyeldir. Bu kadar seçeneği denemek hiçbir şekilde mümkün değildir. 40 faktöriyel belki bir şekilde hesaplanabilir, ama 100 bin noktalı bir problemde bulunan çözümün en iyi çözüm olduğu asla bilinemez.

> **Ek bilgi (derste anlatılmadı):** Başlangıç şehri sabitlenir ve yön önemsiz sayılırsa N şehirli simetrik TSP'de farklı tur sayısı $(N-1)!/2$ olur. Bu sayı da faktöriyel düzeyinde büyüdüğü için hocanın vardığı sonuç değişmez. Örneğin $40! \approx 8{,}16 \times 10^{47}$'dir.

**Soru:** Algoritma küçük uzaylarda denenip en iyi yolu buluyorsa, büyük uzaylarda da en iyi çözümü bulduğu varsayılamaz mı? **Cevap:** Hayır. Bu NP tarzında bir problemdir; olası durum sayısı faktöriyeldir. Küçük uzayda iyi çalışan bir yöntemin büyük uzayda da en iyiyi bulacağı söylenemez; kaldı ki küçük uzayda bile en iyiyi bulduğu garanti edilemez.

**Soru (devam):** Algoritmayı her biri 40 elemanlı çok sayıda örnekte çalıştırdım ve hepsinde en iyi yolu biliyorum, hesapladım. **Cevap:** Yine emin olunamaz. Muhtemelen iyi bir algoritmadır ve bulduğu çözüm muhtemelen iyi olacaktır. Ama konu, bulunan bir çözümün en iyi çözüm olduğunu bilmenin mümkün olup olmadığıdır.

### 7.1 Pratikte optimalliğin anlamı

Hoca bunun pratikte pek bir anlamı olmadığını ekledi. Bu tür bir problemin optimal çözümüne kimin ihtiyacı olur? Gezgin satıcı bir rota ister; ona "bir dakika bekle" deyip bir rota vermek mümkündür. "Bir ay daha bekle, belki 3-5 kilometre daha kısa bir rota bulacağım" denirse satıcı büyük ihtimalle kabul etmez. Gerçek hayatta yapılan, pratik sürede bulunan, yeterince uygun ve kabul edilebilir bir çözümle yola devam etmektir.

> **Hocanın vurgusu:** Lokal arama algoritmalarının amacı, arama uzayının çok büyük olduğu durumlarda kullanıcıya kabul edilebilir bir sürede yeterince iyi bir çözüm sunmaktır. Optimal çözüm sunmak gibi bir vaatleri yoktur; tasarım amaçları bu değildir.

## 8. Genetik Algoritma ile Fonksiyon Optimizasyonu

Bir sonraki örnek bir fonksiyonun maksimumunu bulmaktır. Slayttaki tanım (ekrandan, 01:15:00):

- **Problem:** $f(x) = \cos(x/3) \cdot \sin(x/4)$, $x \in [0, 127]$ şeklinde verilen bir fonksiyonun maksimum değerini bulmak.
- **Gösterim:** 128 farklı değer için 7 bit yeterli.
- **Başlangıç:** a: 0000011, b: 1110111, c: 0010000, d: 0011010.
- **Uygunluk kriteri:** $f(x)$.
- **Ek soru:** Fonksiyon iki parametreli olursa? $F(x,y) = x^2 - y^3 + xy^2$.

$x$, 0'dan 127'ye kadar tam sayılardır; 128 değerin hangisinde fonksiyonun maksimum olduğu aranır. Hoca, slayttaki grafiğe bakınca bu fonksiyonun lokal arama algoritmaları için hiç güzel bir uzay olmadığını gösterdi: çok sayıda lokal maksimum ve minimum vardır, küçük değişiklikler sonucu çok etkiler. Optimizasyon için elverişsiz bir fonksiyondur.

Yine de çözülebilir. 128 farklı değer ikili karşılıklarıyla temsil edilir; başlangıçtaki dört birey a = 3, b = 119, c = 16, d = 26 değerlerine karşılık gelir. Bu dört bireyden adım adım yeni dört birey bulunarak ilerlenir. Bu kodlamada gezgin satıcıdaki gibi bir crossover sorunu yoktur.

Ancak bu örnekte arama uzayı zaten çok küçüktür: yalnız 128 tam sayı değeri vardır ve hepsini denemek mümkündür. Hoca bunu yalnız örnek olarak verdiğini söyledi. Gerçekte fonksiyonlar genellikle tam sayılı ve tek parametreli olmaz. İki parametre ($x$ ve $y$) olunca tam sayılarla bile uzay $128 \times 128$'e çıkar. Tam sayılardan kurtulmak istenirse bir hassasiyet (precision) değeri kullanmak gerekir, çünkü kromozomun boyutu bir şekilde tanımlanmalıdır: virgülden sonra kaç basamak gidileceği belirlenmezse sonsuz uzunlukta bir kromozom gerekir. Çözünürlük arttıkça ya da $x$-$y$, $x$-$y$-$z$ gibi daha çok parametre eklendikçe bütün uzayı taramak imkansız hale gelir; o zaman genetik algoritma ya da diğer lokal arama algoritmaları kullanılır.

> **Ek bilgi (derste anlatılmadı):** Uzay küçük olduğu için tam tarama yapılabilir; python ile 0-127 aralığı tarandığında maksimum büyük olasılıkla $x = 57$'de, $f(57) \approx 0{,}982$ olarak bulunur.

Sonraki slayttaki "GA ile 8 taş: çözüm yolunu da bulmak" örneği derste geçildi; hoca öğrencilerin kendilerinin bakabileceğini söyledi.

## 9. Performansı Etkileyen Faktörler ve Değerlendirme

### 9.1 Performansı etkileyen faktörler

Slaytlardaki faktörler ve hocanın açıklamaları şöyledir (ekrandan, 01:20:00, slayt önizlemesi):

- **Popülasyon büyüklüğü / kromozom sayısı:** Kromozom sayısını artırmak çalışma zamanını artırır, ama çeşitliliğin korunmasını sağlar. Azaltmak çeşitliliği yok eder.
- **Mutasyon oranı:** Kromozomlar birbirine benzemeye başladığında hâlâ çözüm noktasının uzağında bulunuluyorsa, mutasyon GA'nın sıkıştığı yerden (örneğin bütün kromozomların aynı platoda olduğu durumdan) kurtulmasının tek yoludur. Ama çok yüksek bir değer GA'nın kararlı bir noktaya ulaşmasını engeller.
- **Kaç noktadan çaprazlama yapılacağı:** Normalde çaprazlama tek noktadan yapılır, ama bazı problemlerde çok noktalı çaprazlamanın yararlı olduğu gösterilmiştir.
- **Çaprazlama sonucu elde edilen bireylerin nasıl değerlendirileceği:** Elde edilen iki bireyin birden kullanılıp kullanılmayacağı.
- **Durumun nasıl kodlandığı:** Bir parametrenin doğrusal ya da logaritmik kodlanması performansta önemli bir fark yaratabilir.
- **Başarı değerlendirmesinin nasıl yapıldığı:** Akıllıca yazılmamış bir değerlendirme işlevi çalışma zamanını uzatabileceği gibi çözüme hiç ulaşılamamasına da neden olabilir.

Hoca mutasyon oranını benzetimli tavlamadaki sıcaklığa benzetti. Benzetimli tavlamada başlangıçta kötüleşmeyi kabul etme ihtimali yüksektir, zamanla azaltılır ve sonunda yalnız iyileşmeler kabul edilir. Mutasyon oranı da genelde başlangıçta yüksek tutulur, zamanla azaltılır.

Mutasyon bulunulan yerden daha kötü bir yere gitmeye de yol açabilir. Hoca önemli bir farka dikkat çekti: genetik algoritmada "mutasyon iyileştirdiyse kabul et, iyileştirmediyse reddet" gibi bir mekanizma yoktur. Kötü bir birey ancak seçilmediği için bir sonraki nesle kendini aktaramaz.

Örnek olarak hoca bütün bireylerin küçük bir tepenin üstünde ya da bir düzlükte (platoda) toplandığı bir durumu çizdi. Bu durumda crossover pek işe yaramaz, çünkü bireyler birbirine çok benzer. O zaman mutasyon gibi operatörler devreye girer. Seçme de bir operatör sayılabilir, ama değişiklik yapan iki operatör crossover ve mutasyondur. İki farklı değiştirme mekanizmasının olmasının avantajı, biri işe yaramadığında diğerinin müdahale edebilmesidir.

### 9.2 Değerlendirme

Slayttaki değerlendirme (ekrandan, 01:20:00):

- **Pozitif yönleri**
  - Crossover ve mutasyon sayesinde lokal maksimum ve platolardan kurtulabilir.
  - Doğa temelli.
- **Negatif yönleri**
  - Ayarlanabilir çok fazla parametreye sahip; bir problemde gösterdiği başarıyı başka bir problemde tekrarlaması zor.
  - Bazı problem türleri için iyi, ama tepe tırmanmayı farklı başlangıçlarla tekrarlamaktan ya da paralel tepe tırmanmadan daha iyi olduğuna dair matematiksel bir kanıt yok.

Hoca "kurtulur" değil "kurtulabilir" denildiğinin altını çizdi. Çok sayıda hiperparametre olduğu ve sonuç bunların hepsine bağlı olduğu için bir problemdeki başarı başka problemde zor tekrarlanır. Bazı problemleri genetik algoritma iyi çözer, bazılarını diğer yöntemler.

## 10. Uygulamalar: Alan Tarama ve İki Nokta Arası Yol

### 10.1 Az dönüşle alan tarama

Önceki derste tepe tırmanmayla çözülen bir problem bu kez genetik algoritmayla ele alındı: bir alanı taramak, ama bunu yaparken dönüş açılarını küçük tutmak. Hoca bir drone örneği verdi; aynı şey bir yer aracı için de düşünülebilir. Ne kadar keskin dönüş yapılırsa hızın o kadar düşürülmesi gerekir; hareket ne kadar yumuşaksa araç o kadar hızlı gidebilir. Bu yüzden iki hedef vardır: hareketler arasındaki açı miktarı az olsun (yumuşak dönüşler) ve geniş bir alan geçilsin.

Önceki derste tepe tırmanmada tek bir çözümle başlanmış, iyileştirilemeyene kadar iyileştirilmiş, sonra random restart yapılmıştı. Genetik algoritmada ise:

- P adet çözümle başlanır.
- G kez: çözümlerden çaprazlama ve mutasyonla yeni P adet çözüm üretilir. Çaprazlama iki noktadan yapılır.
- Üretilen çözümlerin iyilik değerleri hesaplanır.
- Yeni nesil alınırken eski neslin bir kısmı ve yeni neslin bir kısmı alınır.

Son adım hocanın dikkat çektiği ilginç bir değişikliktir. Orijinal algoritmada eski neslin bir kısmını tutmak yoktur. Burada eski nesilden iyi olanlar popülasyonda tutulur, onlara bir nesil daha yaşama şansı verilir; yeni üretilen neslin de tamamı değil, bir kısmı (büyük olasılıkla en iyileri) alınır. Bu, Bölüm 6.6'da sorulan "ilerlemeyi garanti etmek için ek yapılabilir mi" sorusunun bir örneğidir.

Slayttaki sonuçta kullanılan hiperparametreler (ekrandan, 01:25:00, slayt önizlemesi):

- P = 5000 (popülasyon büyüklüğü)
- mu = 0,01 (mutasyon oranı)
- G = 200 (nesil sayısı)
- cross = 2 (2 noktadan çaprazlama)
- Yeni nesil: eski ve yeni neslin en iyi yarıları

Grafikte rastgele başlangıç çözümlerinden biri, süreç boyunca popülasyonun ortalama fitness'ı (kırmızı) ve her nesildeki en iyi bireyin fitness'ı (mavi) ile 200. nesilde bulunan en iyi çözüm gösterilir. Burada fitness ne kadar küçükse o kadar iyidir. Slaytta çözüm, 8 yönü 1-8 diye numaralayan bir pusula şekli ve bir sayı tablosuyla da verilmiştir; yani kromozom büyük olasılıkla her adımın yönünü gösteren rakamlardan oluşur.

<!-- BELİRSİZ: Slayttaki sayı tablosu yalnız küçük önizlemede göründüğü için değerleri okunamadı. -->

### 10.2 İki nokta arası yol bulma

İkinci uygulamada N×N'lik bir alanda verilen iki nokta arasında yol bulunur. İyilik fonksiyonu üç bileşenlidir (ekrandan, 01:25:00, slayt önizlemesi):

- min(açı): dönüşler yumuşak olsun.
- max(alan): olabildiğince çok yer gezilsin.
- max(sonun hedefe yakınlığı): varılan yer hedefe yakın olsun.

Hoca, yolların neden dümdüz gitmediğinin sorulabileceğini söyledi. Amaç dümdüz gitmek değildir; devriye atar gibi olabildiğince çok yer gezmek istenir. Her adımın süresi bellidir ve belirli sayıda adım atılır; aynı yerden bir daha geçmeden en fazla yeri gezmek ve bunu en az açı dönüşüyle yapmak hedeflenir. Yani bir A noktasından bir B noktasına yol bulmak için de genetik algoritma kullanılabilir.

Bu uygulamada kullanılan ayarlar (ekrandan, 01:25:00):

- P = 5000 (popülasyon büyüklüğü)
- mu = 0,005 (mutasyon oranı)
- G = 500 (nesil sayısı)
- cross = 2 (2 noktadan çaprazlama)
- Yeni nesil: eskinin 1/4'ü ve yeni neslin 3/4'ü

Slayttaki "genetik_path_bulma.m" adımlarına göre iyilik değeri hesaplanırken dönüş açıları toplanır, gidilen farklı nokta sayısı toplanır ve hedefe yakınlık ölçülür (ekrandan, 01:25:00, slayt önizlemesi).

## 11. İyilik Fonksiyonlarının Birleştirilmesi

Üç bileşenli iyilik fonksiyonu, birden fazla bileşenin nasıl birleştirileceği sorusunu getirir. Slayttaki maddeler (ekrandan, 01:30:00, slayt önizlemesi):

- Ölçekleri aynı değilse etkilerini farklılaştırır, normalize etmek gerekir.
- Min ↔ Max dönüşümleri?
- Önem dereceleri farklı ise ağırlıklı işlem gerekir.
- Toplama
- Çarpma
- Maksimum alma
- Minimum alma

Hoca iki tehlikeye dikkat çekti. Birincisi yöndür: bileşenlerden biri minimize, diğeri maksimize edilmek istenirken ikisi doğrudan toplanırsa makul bir hareket yapılmış olmaz. Bir tanesinin minimizasyonu ile diğerinin maksimizasyonu aynı anda istenirken tek bir yapı kurmak zordur; min ve max'ın birbirine dönüştürülmesi gerekir.

İkincisi ölçektir. Örneğin bütün süreç boyunca dönülen toplam açı 500 ile 5000 arasında değişsin, gezilen alan sayısı ise 0 ile 50 arasında olsun. Bunlar doğrudan toplanırsa 5000'lik bileşenin etkisi artırılmış olur. Bu bilerek isteniyorsa sorun yoktur, ama yanlışlıkla yapılıyorsa kötüdür; ölçekler farklıysa normalize etmek gerekir. Bileşenlerin önem dereceleri farklıysa ağırlıklandırma da yapılabilir. Birleştirme toplama, çarpma, maksimum ya da minimum alma ile yapılabilir.

## 12. Genetik Programlama

Dersin son konusu genetik programlamaydı. Hoca bunun genetik algoritma olmadığını vurguladı.

> **Hocanın vurgusu:** Genetik programlama genetik algoritma değildir. İsimleri benzer ama aynı şey değillerdir. Yine de tamamen bağımsız iki alan da değildir: genetik programlama, "genetik algoritmalar program yazabilir mi?" sorusu üzerine çalışılan alandır.

### 12.1 Parse ağaçları üzerinde crossover

Slayttaki maddeler (ekrandan, 01:30:00):

- Genetik algoritma değil.
- Programlama dillerindeki her geçerli program bir parse tree ile ifade edilebilir. Elimizde n adet program/ağaç olsa, bunları kullanıp yeni programlar üretebiliriz.
- Program program yazacak.
- En basiti, bir kelime bir işlemin işlem kısmı: şu sayıları kullanarak şu sayıyı üretin.
- Yine crossover, mutasyon ile yeni ağaçlar üretiliyor.

Derleyici bir programı parçalayıp parse ağacını oluşturur. Slayttaki şekilde iki işlem ağacı vardır ve aralarında "kol bacak değişimi" yapılır: bir ağaçta seçilen bir alt ağaç ile diğer ağaçta seçilen bir alt ağaç yer değiştirir. Şekildeki ağaçlar şöyle okunur (ekrandan, 01:30:00):

```text
Ebeveyn 1:  (x * x) - ((x * y) * 2)      değiştirilen alt ağaç: (x * y)
Ebeveyn 2:  ((x * x) + y) / 2            değiştirilen alt ağaç: ((x * x) + y)

Çocuk 1:    (x * x) - (((x * x) + y) * 2)
Çocuk 2:    (x * y) / 2
```

Hocanın da söylediği gibi ikinci ağaç $(x^2 + y)/2$ gibi bir matematiksel ifadedir; iki ifadeden yine iki matematiksel ifade elde edilir. Ağaç yapısı üzerinde çalışıldığı için crossover ve mutasyon tipleri dizilerdekinden farklı olabilir, ama özünde yine crossover ve mutasyon içeren değişiklikler yapılır. Fark, bu değişikliklerin bir dizi üzerinde değil bir ağaç üzerinde yapılmasıdır, çünkü amaç program yazmaktır.

### 12.2 Zorluk dereceleri ve sorunlar

Slayttaki ikinci genetik programlama sayfası (ekrandan, 01:30:00, slayt önizlemesi):

- Biraz zoru: 10 elemanlı herhangi bir diziyi sıralayacak kodu üretmek.
- Biraz daha zoru: N elemanlı bir diziyi sıralayan kodu üretmek.
- En zoru: herhangi bir görev tanımını koda dönüştürmek.
- Sorunlar:
  - Uygunluk fonksiyonu: K adet görevden (şu girdi için çıktı şu olmalı ikilileri) kaçını başardığı.
  - 10 görevin 7'sini başaran 9'unu başarana göre daha mı kötü?
  - Küçük değişikliklerin büyük etkileri: < → > çok şey değiştirir.
  - Aynı işi yapan kodlar arası karşılaştırma?
  - Gereksiz kod blokları.

"Şu sayılardan şu sayıyı üret" probleminden biraz daha zoru, 10 elemanlı herhangi bir diziyi sıralayan kodu genetik programlamayla üretmektir. Hoca burada üretilen bir programın fitness fonksiyonunun ne olacağını sordu. Cevap slaytta yazılıdır: 10 elemanlı çok sayıda dizi oluşturulur, programın bu K görevden yüzde kaçını başardığı uygunluk olarak kullanılabilir. N elemanlı bir diziyi sıralayan kodu üretmek daha da zordur. En zoru, herhangi bir görev tanımını koda dönüştürmektir; hoca bunun günümüzde, genetik programlamayla olmasa bile, yapılmaya çalışıldığını ve başarılar elde edilmeye başlandığını söyledi.

Bu işlerde ortaya çıkan sorunlar şunlardır. Uygunluk fonksiyonu olarak K görevden kaçının başarıldığı kullanılırsa, 10 görevin 7'sini başaran bir kodun 9'unu başarana göre gerçekten daha kötü olup olmadığı soru işaretidir. Örneğin küçükten büyüğe doğru sıralama yapan bir kodda minicik bir değişiklik, bir "küçüktür" işaretini "büyüktür" yapmak, 10 görevin 10'unu başaran kodu 10 görevin 0'ını başarır hale getirebilir. Yani fitness yüzeyi çok düzensizdir. Aynı işi yapan kodların karşılaştırılması ve gereksiz kod bloklarının oluşması da sorundur.

## Örnek Sorular

**1. (ekrandan, 00:30:00)** 8 vezir probleminde birey, her sütundaki vezirin satır numarasını veren 8 rakamlık dizidir. Fitness birbirini tehdit etmeyen vezir çiftlerinin sayısıdır. Popülasyon 24748552, 32752411, 24415124, 32543213 ise fitness değerleri ve rulet tekeri seçim olasılıkları nedir? Fitness'ın en büyük değeri kaçtır?

> **Çözüm:** Fitness değerleri 24, 23, 20, 11'dir; toplam 78'dir. Olasılıklar $24/78 \approx \%31$, $23/78 \approx \%29$, $20/78 \approx \%26$, $11/78 \approx \%14$ olur. En büyük değer $\binom{8}{2} = 8 \cdot 7/2 = 28$'dir.

**2. (ekrandan, 00:40:00)** Dört bireyin fitness değerleri A = 90, B = 2, C = 5, D = 3'tür. Rulet tekeri seçimi ve sıralama seçimiyle seçilme olasılıklarını hesaplayın. Rulet tekeri seçiminin sakıncası nedir?

> **Çözüm:** Rulet tekeri: A %90, B %2, C %5, D %3. Sıralama seçimi: sıralar A = 4, B = 1, C = 3, D = 2; olasılıklar sıra/10, yani A %40, B %10, C %30, D %20. Rulet tekerinde neredeyse hep A seçilir; aynı bireyler çaprazlanınca yeni birey çıkmaz ve iş mutasyona kalır. Sıralama seçimi çeşitliliği korur.

**3. (ekrandan, 01:00:00)** P1 = A B C D E F G H I J, P2 = E F J H B C I A D G ve şablon T = 1 0 1 1 0 0 0 1 0 1 için uniform crossover sonucu C1 ve C2 nedir? Bu çocuklar gezgin satıcı problemi için çözüm müdür?

> **Çözüm:** C1 = A F C D B C I H D J, C2 = E B J H E F G A I G. Çözüm değildir: C1'de C ve D, C2'de E ve G tekrar eder (bazı şehirlere hiç uğranmaz).

**4. (ekrandan, 01:05:00)** Parent1 = A B C D E F G, Parent2 = E B D C F G A, Template = 0 1 1 0 0 1 0 için sıra tabanlı crossover ile Child1 ve Child2'yi bulun. Gezgin satıcıya çözüm müdür?

> **Çözüm:** Child1: 1'li konumlardan B, C, F aynen; 0'lı konumlardaki A, D, E, G Parent2 sırasına göre E, D, G, A diye dizilir: E B C D G F A. Child2: Parent2'nin B, D, G'si aynen; E, C, F, A Parent1 sırasına göre A, C, E, F diye dizilir: A B D C E G F. İkisi de geçerli permütasyondur, yani çözümdür; şehirler tekrar etmez.

**5. (ekrandan, 01:10:00)** 100 bin noktayı elini kaldırmadan birleştiren en kısa yol nedir? Bulunan bir çözümün en iyi çözüm olduğunu bilmek mümkün mü?

> **Çözüm (derste sözlü):** Mümkün değildir. En iyi olduğunu kanıtlamak için bütün olasılıkları denemek gerekir; sayıları 100 bin faktöriyel düzeyindedir. Lokal arama zaten optimal çözüm vaat etmez, kabul edilebilir sürede yeterince iyi bir çözüm hedefler.

**6. (ekrandan, 01:15:00)** $f(x) = \cos(x/3)\sin(x/4)$, $x \in [0, 127]$ fonksiyonunun maksimumu genetik algoritmayla aranacaktır. Kaç bitlik kromozom gerekir? Başlangıç bireyleri a = 0000011, b = 1110111, c = 0010000, d = 0011010 hangi $x$ değerlerine karşılık gelir? Fonksiyon iki parametreli olursa ($F(x,y) = x^2 - y^3 + xy^2$) ne değişir?

> **Çözüm (derste verilmedi):** 128 değer için 7 bit yeterlidir. a = 3, b = 119, c = 16, d = 26. İki parametrede tam sayılarla bile uzay $128 \times 128$ olur ve kromozom iki parametreyi birlikte kodlamalıdır (örneğin 7 + 7 = 14 bit); hassasiyet ve parametre sayısı arttıkça tam tarama imkansızlaşır. Tam tarama ile 0-127 aralığında maksimum $x = 57$, $f(57) \approx 0{,}982$ bulunur (python ile hesaplandı).

**7. (derste sözlü, 01:31:30)** Genetik programlamayla 10 elemanlı herhangi bir diziyi sıralayan kod üretilecekse, üretilen bir programın fitness fonksiyonu ne olabilir?

> **Çözüm:** Çok sayıda 10 elemanlı test dizisi oluşturulur; programın bu K görevden yüzde kaçını doğru sıraladığı uygunluk olarak kullanılır. Ancak bu ölçüt yanıltıcı olabilir: tek bir karşılaştırma işaretini değiştirmek başarıyı 10'da 10'dan 10'da 0'a düşürebilir.

## Dersin Toparlaması

Bu derste lokal arama algoritmalarının en bilinenlerinden biri olan genetik algoritma ele alındı. Genetik algoritma, paralel tepe tırmanma gibi K çözümle çalışır; farkı yeni K çözümün seçme, çaprazlama ve mutasyonla üretilmesidir. 8 vezir örneğinde bir neslin bütün adımları sayısal olarak izlendi; rulet tekeri ve sıralama seçimlerinin çeşitlilik üzerindeki etkisi karşılaştırıldı. Gezgin satıcı probleminde standart ve uniform crossover'ın geçersiz rotalar ürettiği, sıra tabanlı crossover'ın ise her zaman geçerli bir permütasyon verdiği gösterildi. 100 bin noktalı Mona Lisa örneğiyle büyük uzaylarda optimalliğin kanıtlanamayacağı ve lokal aramanın amacının makul sürede yeterince iyi bir çözüm olduğu vurgulandı.

Ardından fonksiyon optimizasyonu, alan tarama ve iki nokta arası yol bulma uygulamaları, performansı etkileyen faktörler, genetik algoritmanın güçlü ve zayıf yanları ve birden çok iyilik bileşeninin birleştirilmesi işlendi. Son olarak genetik algoritmadan farklı bir alan olan genetik programlama, parse ağaçları üzerinde crossover ve program üretmenin zorlukları üzerinden tanıtıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
