# Ders 1 Genişletilmiş Notu: Algoritma Kavramı, Temel Problemler ve Veri Yapılarına Genel Bakış

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri, Kapsamı ve Kaynakları
- 2. Algoritma Nedir?
- 3. Algoritmanın İfade Biçimleri ve Özellikleri
- 4. OBEB Problemi Üzerinden Algoritma Karşılaştırması
- 5. Algoritma ve Problem İlişkisi, Seçmeli Sıralama
- 6. İyi Bilinen Hesaplama Problemleri
- 7. Algoritmalarla İlgili Temel Sorunlar
- 8. Algoritma Tasarım Stratejileri
- 9. Algoritma Analizi: Daha İyi Algoritma Var mı?
- 10. Önemli Problem Türleri
- 11. Temel Veri Yapıları
- 12. Çizgeler ve Ağaçlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yeri, Kapsamı ve Kaynakları

Algoritma analizi, lisans eğitiminde bir ders zincirinin son halkası gibidir. Birinci sınıfta algoritmaya giriş ve yapısal programlama derslerinde basit problemler, küçük verilerle ve çoğunlukla kaba kuvvetle (brute force, exhaustive search) çözülür. Örneğin 10 ya da 100 elemanlı bir dizi sıralanır ve performans ölçütü pek konuşulmaz.

Algoritmanın üç temel işlemi vardır: sıralı işlemler, koşullu işlemler ve tekrarlı işlemler. Dördüncüsü yoktur. Ancak yalnız bu üç yapıyla çoğu problem rahat çözülemez; programlama dillerinin sağladığı ek yapılara ihtiyaç vardır. Hoca bunu şöyle örnekledi: 100 öğrencinin notları arasından en büyüğü tek bir değişkenle bulunur. En büyük iki not için bir değişken daha, üç not için bir tane daha eklenir. Ama 1000 öğrenci içinden 50. en büyük not istenirse 50 değişken tanımlamak ve aralarındaki bütün "büyükse, küçükse" olasılıklarını yazmak anlamsız hale gelir. Diziler, matrisler ve listeler bu verileri kalıcı olarak birlikte saklar; saklanan veri üzerinde bir sıralama ya da arama algoritmasıyla 50. ya da 500. eleman kolayca bulunur. Veri yapıları dersi, klasik algoritmalarla çözülemeyen problemler için bu araçları verir.

Veri yapılarında önce tek boyutlu doğrusal yapılar (liste, kuyruk, yığın), sonra ağaçlar (ikili ağaç, heap, arama ağaçları) ve çizgeler görülür. Bu yapılar sık karşılaşılan problemlerde farklı algoritmalarla denenir: ikili arama ağacında arama, heap üzerinde heap sort, merge sort gibi böl ve yönet algoritmaları, çizgelerde temel gezinti işlemleri. Bu bilgiler bu derste bilinmiş kabul edilir; örneğin yığın yapısının ne olduğu ayrıca sorulmaz.

Dersin kendi içeriği iki parçadır. İlk parçada algoritmanın ne olduğu, nelerden oluştuğu, nasıl analiz edildiği ve analizden tasarıma nasıl geçildiği incelenir. İteratif ve özyinelemeli (rekürsif) algoritmaların analizi, merge sort ve quicksort gibi böl ve yönet algoritmalarının analizi, en iyi, en kötü ve ortalama durum kavramları bu kısımdadır. Dizi, hash, ağaç, çizge ve bağlı liste gibi yapılarda sık kullanılan algoritmaların (örneğin ağaçta preorder gezinme) analizine de bakılır. İkinci parçada tasarım yöntemleri gelir: kaba kuvvet, azaltarak yönetme, böl ve yönet, dönüştür ve yönet, dinamik programlama, geri izleme ve dal-sınır. Hoca bu yöntemlerin endüstri mühendisliği ve iktisat gibi alanlarda da öğretildiğini, bilgisayar mühendisliğinde ise algoritmik bakışla ele alındığını söyledi. Son kısımda P, NP, NP-complete ve NP-hard problem sınıfları ile bir algoritmanın alt sınırı (lower bound) konuşulur.

Ana kaynak Levitin'in "Introduction to the Design and Analysis of Algorithms" kitabıdır. Hoca kitabın dilinin anlaşılır olduğunu ve konuları sıralama algoritmaları gibi örnek olaylar üzerinden değil, problem çözme yöntemleri üzerinden işlediğini söyledi. Kitabın bölümleri: algoritmanın temelleri, analiz ve verimlilik, kaba kuvvet ve kapsamlı arama, azalt-böl-dönüştür ve yönet, dinamik programlama, açgözlü teknik, yer-zaman ödünleşimi, iteratif iyileştirme, algoritma gücünün sınırları (alt sınırlar, NP-complete), geri izleme ve dal-sınır. Sedgewick'in "Algorithms" kitabı örnek olaydan yönteme gider (sıralama, arama, çizgeler, dizgiler); güzel bir kitaptır ama dersin yapısına daha az uyar. Cormen ve arkadaşlarının "Introduction to Algorithms" kitabı hem veri yapılarını hem analizi çok ayrıntılı ve matematiksel biçimde işler; dinamik programlama, açgözlü algoritmalar, amortize analiz, B-ağaçları, ayrık kümeler ve çizge algoritmalarını içerir.

> **Hocanın vurgusu:** Bu dersten başarısız olmanın en önemli sebebi, sorunun ve sorudaki kısıtların anlaşılmamasıdır. Üçüncü sınıf bir derste, örneğin bir dizide arama için birinci sınıf düzeyinde bir çözüm değil, sorunun istediği algoritmik çözüm beklenir.

## 2. Algoritma Nedir?

Ekrandaki tanım (ekrandan, 01:25:00):

> An *algorithm* is a sequence of unambiguous instructions for solving a problem, i.e., for obtaining a required output for any legitimate input in a finite amount of time.

Yani algoritma, bir problemi çözmek, başka bir deyişle her geçerli girdi için istenen çıktıyı sonlu bir sürede elde etmek için kullanılan, belirsizlik içermeyen komutlar dizisidir. Slaytın altındaki şemada problem algoritmaya, algoritma "bilgisayar"a gider; bilgisayar girdiyi alır, çıktıyı verir.

**Belirsizlik içermeme.** Algoritma tanımlanmış ifadelerden oluşur. Bir çarpma işlemi için `x * x` yazmak bir algoritmanın parçası olabilir; ama "karesini al" demek, Türkçe ya da İngilizce olması fark etmeksizin, algoritma tanımına aykırıdır (ekrandan, 01:25:00). Çünkü algoritma en sonunda makine diline çevrilecek ya da bir programlama dili tarafından derlenecektir; o dilin kurallarına ve komut kümesine bağlı kalmak gerekir.

**Sıra.** Algoritma bir dizidir. Çözüm A, B, C adımlarını bu sırayla istiyorsa önce B'yi sonra A'yı yazmak doğru olmaz (ekranda A-B-C ve B-A-C sıraları yan yana yazıldı, 01:25:00).

**Amaç ve sonluluk.** Algoritma geliştirmenin amacı, gerçek dünya problemlerini soyutlama yöntemleri ve bilgisayarın hızından yararlanarak çözmektir. Algoritma geçerli bir girdi ile ona karşılık gelen çıktı arasında bir sistem kurar ve bunu sonlu bir zamanda yapar. Sonluluk, işlemin sonsuza gitmemesi, girdi boyutu çok büyüdüğünde de çıktıya ulaşma süresinin aşırı uzamaması demektir.

Genel akış şöyledir: gerçek dünyada bir problem vardır; bu problem nesneye dayalı, yapısal ya da başka bir mantıkla zihinde modellenir; sonra problemin çözümüne ilişkin en alt birim olan algoritmalar yazılır. Hoca algoritmayı çoğu zaman bir C fonksiyonu gibi düşüneceğini söyledi: `void` ya da bir değer döndüren, parametre alan bir `f` fonksiyonu. Bu fonksiyon iteratif olabilir ya da içinde yeniden `f` çağrısı yapan özyinelemeli bir fonksiyon olabilir. Burada kastedilen bir `main` ya da nesneye dayalı tasarımdaki bir sınıf değil, girdiyi alıp çıktıyı veren aradaki kısımdır.

## 3. Algoritmanın İfade Biçimleri ve Özellikleri

Hoca öğrencilere algoritmanın nasıl ifade edilebileceğini sordu. Sohbetten gelen cevaplar sözde kod (pseudocode) ve akış şemasıydı (flowchart); hoca programlama dilini ve sözlü anlatımı ekledi (ekrandan, 01:30:00).

Sözlü anlatıma örnek, katsayıları verilen ikinci dereceden bir denklemin çözümüdür: "$a$, $b$, $c$ katsayılarını alırım, diskriminantı hesaplarım, diskriminantın sıfıra eşit, sıfırdan büyük ya da küçük olmasına göre kökleri bulurum." Bu bir algoritmadır, ama "diskriminantı hesaplarım" ifadesi belirsizdir; diskriminantın nasıl hesaplanacağı söylenmemiştir. Doğrusu:

$$\Delta = b^2 - 4ac$$

diye açıkça yazmak ve kök formüllerini de tek tek vermektir:

$$x_{1,2} = \frac{-b \pm \sqrt{\Delta}}{2a}$$

Slayttaki özellikler (ekrandan, 01:30:00):

- Çeşitli biçimlerde ifade edilebilir (sözde kod, akış şeması, programlama dili, sözlü).
- Açıklık / belirsizlik içermeme (unambiguity / clearness).
- Etkinlik (effectiveness).
- Sonluluk / sonlanma (finiteness / termination).
- Doğruluk (correctness).

### 3.1 Etkinlik ve kaynaklar

Etkinlik, problemin hızlı çözülmesi ve kaynakların etkin kullanılmasıdır. Bilgisayar sistemlerinde iki temel kaynak vardır: zaman (işlemin CPU tarafından tamamlanma süresi) ve bellek (space, algoritma çalışırken harcanan bellek).

Hocanın benzetmesi: İstanbul'dan Ankara'ya birçok yoldan gidilebilir. Uçakla gidilirse çok para harcanır ama kısa sürede varılır; hiç para harcamak istemeyen yürür. Zaman ile para (ya da bellek) arasında bir ödünleşim (trade-off) vardır. Belleği kısıtlı bir cihazda (örneğin bir IoT cihazında) bellek etkinliği zamandan önce gelir; ikisi birden isteniyorsa donanım değiştirilir ya da farklı bir yaklaşım düşünülür.

### 3.2 Sonlanma ve doğruluk

Sonlanma, algoritmanın belli bir süre sonra durmasıdır. Hoca burada durma problemine (halting problem) değindi: verilen bir programın sonlanıp sonlanmayacağını tespit etme problemi hesaplama kuramında incelenir.

Doğruluk en temel özelliktir. Bir optimizasyon problemiyle uğraşılmıyorsa, örneğin bir sıralama algoritmasından ilk beklenti diziyi doğru sıralamasıdır. Algoritma doğru sonuç vermiyorsa etkinlik ya da diğer özellikler anlamsız kalır. Bu yüzden önce doğruluğa, sonra kısıtlara uyulup uyulmadığına, sonra zaman ve bellek etkinliğine bakılır.

Hoca analiz kavramını da burada açtı. Birinci sınıfta seçmeli sıralama yazılırken $i$'nin her değeri için $a[i]$'nin ve geçici swap değişkenlerinin nasıl değiştiği bir tabloda izlenir; bu bir değişken analizidir. Bu derste buna ek olarak, girdi boyutu büyüdükçe algoritmanın zaman ve bellek davranışı matematikteki fonksiyonlara benzer fonksiyonlarla ifade edilecek ve algoritmaların kalitesi bu fonksiyonlarla değerlendirilecektir.

## 4. OBEB Problemi Üzerinden Algoritma Karşılaştırması

Slayt, OBEB (en büyük ortak bölen, greatest common divisor, GCD) için Öklid algoritmasını ve "algoritma" sözcüğünün kaynağı olan 9. yüzyıl matematikçisi Muhammed ibn Musa el-Harezmi'yi anıyor (ekrandan, 01:35:00).

### 4.1 Ortaokul yöntemi

$\gcd(4, 18)$ için iki sayı yan yana yazılır ve en küçük asal 2'den başlanır (ekrandan, 01:40:00):

```text
 4   18 | 2  *   (ikisi de bölündü)
 2    9 | 2      (yalnız 2 bölündü)
 1    9 | 3
 1    3 | 3
 1    1
```

İki sayıyı birden bölen çarpanlar (yıldızlı olanlar) çarpılarak OBEB bulunur: $\text{OBEB}(4,18) = 2$. Aynı tablodan OKEK de çıkar; tablodaki bütün bölenlerin çarpımı alınır:

$$\text{OKEK}(4,18) = 3^2 \cdot 2^2 = 36$$

### 4.2 Ardışık tamsayı kontrolü

Hoca öğrencilere bunun programla nasıl yapılacağını sordu ve kendisi bir çözüm geliştirdi. OBEB iki sayının ikisinden de büyük olamaz; en fazla küçük sayıya eşittir. Bu yüzden önce $\min(4,18) = 4$ bulunur, sonra 4'ten geriye doğru iki sayıyı birden bölen bir sayı aranır (ekrandan, 01:40:00):

| $t$ | $4 \bmod t = 0$? | $18 \bmod t = 0$? | Sonuç |
|---|---|---|---|
| 4 | evet | hayır | devam |
| 3 | hayır | (bakmaya gerek yok) | devam |
| 2 | evet | evet | OBEB = 2 |

İlk sayı bölünmüyorsa ikincisine bakmaya gerek yoktur; algoritma bunu da ifade edebilir. Hoca, birer birer azaltma dışında başka adımlar da kullanılabileceğini not etti.

Slayttaki biçimi (ekrandan, 02:40:00):

```text
Consecutive integer checking algorithm
Step 1  Assign the value of min{m,n} to t
Step 2  Divide m by t. If the remainder is 0, go to Step 3;
        otherwise, go to Step 4
Step 3  Divide n by t. If the remainder is 0, return t and stop;
        otherwise, go to Step 4
Step 4  Decrease t by 1 and go to Step 2
```

Hoca bunu 4 ve 14 ile izledi: $t = 4$; $4 \bmod 4 = 0$ olduğu için 3. adıma geçilir; $14 \bmod 4 \ne 0$ olduğu için 4. adıma gidilir ve $t$ bir azaltılır. En kötü durumda $t$ 1'e kadar iner; 1 iki sayıyı da böldüğü için algoritma mutlaka sonlanır. Bu algoritma çoğu durumda Öklid algoritmasından yavaştır, çünkü sayılar büyüdükçe minimumdan geriye birer birer çok sayıda kontrol yapmak gerekir. Hızlandırmak için başka sıralarla ya da başka adımlarla denemek gibi bazı değişiklikler yapılabilir; hoca bunlara kaba kuvvet konusunda döneceklerini söyledi.

> **Ders sonrası not:** Hoca izleme sırasında önce "$t$'yi 1 artır" dedi, sonra "azalt" diye düzeltti. Slaytta da doğrusu yazıyor: $t$ bir azaltılır.

### 4.3 Üç temel yapı

Hoca bu çözümde hangi yapıların kullanıldığını sordu ve yapıları numaralandırdı: 1 sıralı, 2 koşullu, 3 tekrarlı (ekrandan, 01:45:00). Bir öğrenci 3 ve 2 dedi; hoca aslında üçünün de kullanıldığını açıkladı:

- **Tekrarlı (3):** Aranan sayı bulunana kadar ilerlemek gerekir. Ne zaman biteceği belli olmadığı için C'de `while` ya da `do-while` uygundur.
- **Koşullu (2):** Bölünüp bölünmediğinin kontrolü bir `if`'tir.
- **Sıralı (1):** Önce 4'ün, sonra 18'in $t$'ye bölünmesi ard arda yapılan işlemlerdir; mod işlemi ve eşitlik karşılaştırması da bu gruptadır.

Bu algoritma bir girdiye karşılık bir çıktı verir, sınırlı sayıda adımda biter, her adımı açıktır (mod, eşitlik `if` ile, döngü `while` ile ifade edilir). Bütün şartları sağladığı için bir algoritmadır.

### 4.4 Öklid algoritması

Öklid algoritması özyinelemeli bir yaklaşımdır. Büyük sayı sola, küçük sayı sağa yazılır; her adımda büyük sayının küçük sayıya bölümünden kalan hesaplanır ve ikinci sayı 0 olana kadar devam edilir:

$$\gcd(m, n) = \gcd(n,\ m \bmod n), \qquad \gcd(m, 0) = m$$

Ekrandaki örnek (ekrandan, 01:45:00):

$$\gcd(18,4) \to \gcd(4,\ 18 \bmod 4) = \gcd(4,2) \to \gcd(2,\ 4 \bmod 2) = \gcd(2,0) \Rightarrow \gcd(18,4) = 2$$

İlk yöntemde birçok bölme denemesi yapılmıştı. Burada her adımda yalnız bir mod işlemi ve bir kontrol vardır: hem her adımdaki iki kontrol bire düşer hem de adım sayısı azalır.

Küçük sayılarda fark görünmez (3 adıma karşı 4 adım). Fark büyük sayılarda ortaya çıkar. $\gcd(30, 858)$ için (ekrandan, 01:50:00):

| Adım | Bölme | Kalan | Yeni çift |
|---|---|---|---|
| 1 | $858 = 28 \cdot 30 + 18$ | 18 | $\gcd(30,18)$ |
| 2 | $30 = 1 \cdot 18 + 12$ | 12 | $\gcd(18,12)$ |
| 3 | $18 = 1 \cdot 12 + 6$ | 6 | $\gcd(12,6)$ |
| 4 | $12 = 2 \cdot 6 + 0$ | 0 | $\gcd(6,0)$ |

Sonuç $\gcd(858,30) = 6$'dır (Python ile doğrulandı). Ardışık tamsayı kontrolü ise 30'dan başlayıp 29, 28, ... diye 6'ya kadar 25 deneme yapar. Hoca, sayılar büyüdükçe bu farkın çok daha açılacağını vurguladı.

İki yöntem karşılaştırıldığında ikisi de doğru sonucu bulur, ikisi de sonlanır, ikisi de belirsizlik içermeyen adımlardan oluşur ve ikisi de programla ifade edilebilir; ortaokul yöntemi de zorlanırsa programlanabilir. Fark verimliliktedir. Bellek açısından ardışık kontrolde bir `min` değişkeni, Öklid'de bir geçici değişken gerekir; fark yoktur. Zaman açısından ise Öklid çok daha hızlıdır. Hoca Öklid algoritmasının logaritmik biçimde arttığını söyledi.

Hoca algoritmanın döngüyle nasıl kodlanacağını sözlü olarak anlattı: ikinci sayı sıfırdan farklı olduğu sürece önce mod alınıp geçici değişkene saklanır, küçük sayı büyük sayının yerine geçer, mod değeri küçük sayının yerine geçer. Derste ayrı bir program yazılmadı; aşağıdaki parça hocanın anlattığı adımların C karşılığıdır ve aynı mantık ajan tarafından Python ile denenmiştir:

```c
while (s2 != 0) {
    t  = s1 % s2;   /* önce mod alınır ve saklanır */
    s1 = s2;        /* küçük sayı büyüğün yerine geçer */
    s2 = t;         /* kalan küçük sayının yerine geçer */
}
/* OBEB s1'dedir */
```

> **Ek bilgi (derste anlatılmadı):** Öklid algoritmasının adım sayısı küçük sayının basamak sayısıyla orantılıdır, yani $O(\log \min(m,n))$ mertebesindedir. Ardışık tamsayı kontrolü ise en kötü durumda $\min(m,n)$ deneme yapar.

### 4.5 Genişletilmiş Öklid algoritması

Öklid algoritması geliştirilerek kriptolojide kullanılır. Örneğin ekrandaki $7x - 8y = 1$ eşitliğini sağlayan $x, y$ tamsayılarını bulmak istenir (ekrandan, 01:50:00); küçük sayılarda bu kolaydır, çok büyük sayılarda bir algoritma gerekir. Hoca, Öklid algoritmasının geriye doğru işletildiğini $\gcd(18,4)$ örneğiyle gösterdi: $18 = 4 \cdot 4 + 2$ ve $4 = 2 \cdot 2 + 0$ eşitlikleri geriye doğru kullanılarak katsayılara ulaşılır; katsayıların yanındaki değerler $x$ ve $y$'yi verir. Hoca "Extended Euclidean algorithm" konusuna bakılmasını, başka yerlerde de karşılarına çıkabileceğini söyledi.

Hoca adın yazımına da değindi: Türkçede "Öklid" diye yazılsa da adamın adı "Euclid"dir; kendi adımızın başka biçimde yazılmasından hoşlanmadığımız gibi.

### 4.6 Ortaokul yöntemi bir algoritma mıdır?

Slayttaki ortaokul prosedürü: $m$ ve $n$'nin asal çarpanlarını bul, ortak olanları bul, ortak çarpanları çarp. Hoca $\gcd(4, 24)$ ile izledi:

$$4 = 2^2, \qquad 24 = 2^3 \cdot 3, \qquad \text{ortak: } 2^2 \Rightarrow \gcd(4,24) = 4$$

Soru şudur: bu bir algoritma mıdır? "Asal çarpanları bul" adımı ayrıca tarif edilmelidir; bilgisayar kendisine 24 verilince bunun $2^3 \cdot 3$ olduğunu bilmez. Asal çarpanlara ayırma da döngülü bir süreçtir. Asal çarpanlar biliniyorsa geri kalan işlem basittir; asıl zorluk asal çarpanları bulmaktır. Bu, çok büyük asal sayı bulma problemine bağlanır.

Bir sayının asal olup olmadığını kontrol etmek için 2'den başlanıp sayının kareköküne kadar olan bölenler denenir. Bu kontrol hızlandırılabilir: 2'ye bakıldıktan sonra çift sayılara hiç bakılmaz, yalnız tek sayılara bakılır. Hoca bu bağlamda Eratosten kalburunu (sieve of Eratosthenes) andı. <!-- BELİRSİZ: Hocanın ortaokul yöntemi için söylediği "karekök n" karmaşıklığı ve kalbur için söylediği "O(n)" karmaşıklığı altyazıda dağınık; slayt karesi yok. -->

## 5. Algoritma ve Problem İlişkisi, Seçmeli Sıralama

Slayt (ekrandan, 02:05:00): problem → algoritma → "bilgisayar"; girdi (ya da örnek, instance) bilgisayara girer, çıktı alınır. Altta "algorithmic solution (different from a conventional solution)" yazıyor. Algoritma, problemin çözümüne yönelik sistematik bir adımlar listesidir.

### 5.1 Her problemin algoritması var mı?

Hoca burada "her problemin çözümü için bir algoritma var mıdır?" sorusunu sordu; bu, dersin sonundaki problem sınıflandırması (polinom zamanlı ve polinom olmayan problemler) konusuna bağlanır. Bir çözüm üretilebilir, ama sonluluk ya da etkinlik şartları sağlanmayabilir.

Örnek bir parola kırma problemidir. ASCII tablosunda 256 karakter olduğu kabul edilsin ve parola 100 karakterli olsun. Her konum için 256 olasılık vardır; sıra önemlidir (01 ile 10 farklıdır). Olası parola sayısı üsteldir:

$$256^{100}$$

Bu problemi polinom zamanda çözen bir algoritma geliştirmek mümkün değildir; tek tek denemek (kaba kuvvet) de zaman şartını sağlamaz. Üstelik birçok sistem yalnız üç dört yanlış denemeye izin verir; bu kadar büyük bir arama uzayı üç beş denemede taranamaz.

> **Ders sonrası not:** Hoca 100 haneli parolayı anlatırken bir yerde "256 üzeri 10" dedi; 100 karakter için doğrusu $256^{100}$'dür. Hoca bunu permütasyon problemi diye andı; karakterler tekrar edebildiği için bu büyük olasılıkla tekrarlı dizilim (her konum için 256 seçenek) olarak düşünülmelidir.

Bazen algoritma vardır ama verimliliği tartışmalıdır; ancak ana bilgisayarlarda ya da süper bilgisayarlarda çalıştırılabilir ve her yerde uygulanabilir değildir.

### 5.2 Sıralama örneği ve bellek

Sıralama probleminde veriler bellekte durur ve algoritmanın iki özelliğine bakılır: zaman ve bellek kullanımı. Bazı basit sıralama algoritmaları bellek açısından tutumludur (yalnız bir geçici swap değişkeni ister) ama zaman açısından sorun çıkarabilir. Merge sort ise ek bellek alanı ister: 5 eleman için bu önemli değildir, ama 4 GB RAM'de 3 GB'lık bir dizi merge sort ile sıralanamaz, çünkü 3 GB kadar ek yer gerekir.

### 5.3 Seçmeli sıralama

Slayttaki algoritma (ekrandan, 02:10:00):

```text
Input:  array a[1], ..., a[n]
Output: array a sorted in non-decreasing order
Algorithm:
for i = 1 to n
    swap a[i] with smallest of a[i], ..., a[n]
```

Slaytın altında "Is this unambiguous? Effective?" ve "See also pseudocode, section 3.1" yazıyor.

Algoritma birinci konum için bütün dizinin, ikinci konum için kalan elemanların en küçüğünü bulur ve yerine yazar. $a[i]$ zaten en küçük olabilir ya da başka bir eleman daha küçük olabilir; her durumda bir yer değiştirme yapılır ve $i$ bir artırılır.

**Belirsizlik.** "En küçüğü bul" adımı içinde gizli bir döngü vardır; bir dizinin en küçük elemanını bulmak ayrı bir problemdir. Bu adım ayrıca tanımlansa algoritma daha açık olurdu.

**Etkinlik.** Bir swap işlemi ve onun için bir ek bellek alanı vardır. İç içe iki döngü bulunur: biri elemanın yerleşeceği konumu gösterir, öteki en küçük elemanı arar. İkisi de kabaca $n$'ye kadar dönerse yaklaşık $n^2$ işlem yapılır. Küçük dizilerde yeterlidir, ama örneğin bir milyon elemanlı bir dizide çok yavaş kalır; daha uygun algoritmalar ileride görülecektir.

Swap için tahtada yazılan kod (ekrandan, 02:15:00):

```c
tmp  = a[i];
a[i] = a[j];   /* j: bulunan en küçük elemanın indisi */
a[j] = tmp;
```

### 5.4 Yerinde olma ve kararlılık

**Yerinde (in-place) olma:** Dizi bulunduğu yerde, başka bir yere taşınmadan sıralanabiliyorsa algoritma yerindedir. Counting sort diziyi başka bir alana taşır ve orada daha kısa sürede sıraladığını iddia eder; kendine göre dezavantajları vardır. Seçmeli sıralamada dizi yerinde durur, yalnız bir swap değişkeni gerekir; bu yüzden seçmeli sıralama yerindedir.

**Kararlılık (stability):** Hoca, 1, 6, 8, ... diye giden bir dizide en küçük elemanın zaten ilk konumdaki 1 olduğunu, buna rağmen algoritmanın onu geçici değişken üzerinden kendisiyle yer değiştirdiğini gösterdi (ekrandan, 02:15:00) ve kararsızlığı bu gereksiz yer değiştirmeyle açıkladı. Bir öğrencinin sorusu üzerine aynı örnek yeniden anlatıldı.

**Soru:** Kararlılığı tam anlayamadım. **Cevap:** Hoca örneği tekrarladı: dizi 1, 6, 8 diye gidiyor; ilk konum için en küçük eleman aranıyor ve bulunan eleman kendisi oluyor; `tmp = a[i]; a[i] = a[j]; a[j] = tmp;` ile değer geçici değişkene gidip geliyor ama hiçbir şey değişmiyor.

> **Ders sonrası not:** Hocanın kararlılık açıklaması kavramın tanımıyla örtüşmüyor. Bir sıralama algoritması, eşit anahtarlı elemanların girdideki göreli sırasını çıktıda koruyorsa kararlıdır. Bir elemanın kendisiyle yer değiştirmesi gereksiz bir işlemdir ama kararlılığı bozmaz. Seçmeli sıralamanın kararsız olmasının sebebi uzak yer değiştirmelerdir: $[2_a, 2_b, 1]$ dizisinde ilk adımda $2_a$ ile $1$ yer değiştirir ve sonuç $[1, 2_b, 2_a]$ olur; iki 2'nin sırası bozulmuştur. Sonuç (seçmeli sıralama kararlı değildir) doğrudur.

Hoca Wikipedia'daki sıralama algoritmaları tablosunu açarak kararlılık ve yerinde olma sütunlarını gösterdi. Tabloda seçmeli sıralamanın kararlı olmadığı yazıyor; bağlı liste ve $O(n)$ ek alan kullanılırsa kararlı hale getirilebileceği belirtiliyor. Quicksort genellikle yerinde yapılır; merge sort'un ayrıca yerinde bir sürümü vardır. Hoca, en iyi, ortalama ve en kötü durum ile bellek gereksinimi analizine ileride bakılacağını söyledi.

## 6. İyi Bilinen Hesaplama Problemleri

Slayttaki liste (ekrandan, 02:20:00):

- Sorting (sıralama)
- Searching (arama)
- Shortest paths in a graph (çizgede en kısa yollar)
- Minimum spanning tree (en küçük kapsayan ağaç)
- Primality testing (asallık testi)
- Traveling salesman problem (gezgin satıcı problemi)
- Knapsack problem (sırt çantası problemi)
- Chess (satranç)
- Towers of Hanoi (Hanoi kuleleri)
- Program termination (program sonlanması)

Slaytın altında: "Some of these problems don't have efficient algorithms, or algorithms at all!" (ekrandan, 02:25:00).

**Sıralama ve arama.** Sıralama, bir kez sıralayıp sonra kolay arama yapabilmek içindir; arama, sıralamanın hedefindedir.

**En kısa yol.** Bir noktadan bir noktaya en kısa kilometreyle, en hızlı yoldan ya da başka bir ölçüte göre gitmek istenir. Harita üzerinde yol bulma da ağdaki paketlerin en düşük maliyetle yönlendirilmesi de bu problemdir.

**En küçük kapsayan ağaç.** Bir mahalleye boru ya da elektrik hattı döşenecektir. Her sokağa ayrı hat çekmek gerekmez; bütün noktaları kapsayan ve gereksiz hatları atan en küçük yapı aranır. Bu bir küçültme problemidir ve ağlarda da karşılığı vardır.

**Asallık testi.** Güvenlikte çok büyük asal sayılara ihtiyaç vardır; şifreleme ne kadar büyük asallarla yapılırsa o kadar iyidir.

**Gezgin satıcı problemi.** Bir geziye gidildiğinde yapılacaklar listesindeki yerlerin hepsine gidilip başlangıç noktasına (örneğin otele) dönülmek istenir ve bunun en az maliyetle yapılması gerekir. Kaba kuvvet yaklaşımı bütün turları yazar. A, B, C şehirleri için yalnız iki tur vardır (ekrandan, 02:20:00):

```text
A - C - B - A
A - B - C - A
```

Çizge beş şehre (A, B, C, D, E) büyütüldüğünde turlar hızla çoğalır; ekranda yazılanlardan bazıları (ekrandan, 02:25:00):

```text
A - B - C - D - E - A
A - B - D - E - C - A
A - C - E - D - B - A
```

Her turun bir maliyeti (kilometre, para, zaman; o an hangi birim önemliyse) hesaplanır ve en küçük maliyetli tur seçilir. Türkiye'nin 81 ili için başlangıç ve bitiş aynı tutulduğunda $80!$ sıra denenmesi gerekir; yalnız bunları denemek bile bilgisayarın işlem kapasitesini aşar.

> **Ek bilgi (derste anlatılmadı):** Simetrik gezgin satıcı probleminde bir tur ile onun ters yönü aynı maliyettedir; bu yüzden başlangıç sabitlenmiş $n$ şehir için farklı tur sayısı $(n-1)!/2$'dir. Bu sayı da faktöriyel hızla büyür.

**Sırt çantası problemi.** Elde hacim (ve ağırlık) ile değer bilgisi olan nesneler ($V_1, V_2, \ldots$ hacimleri, $D_1, D_2, \ldots$ değerleri) ve $V$ kapasiteli bir torba vardır. Torba olabildiğince dolu olmalı, ama en değerli nesnelerle doldurulmalıdır ("yükte hafif pahada ağır"). Bütün olasılıklarla doldurup boşaltmak küçük problemde işe yarar gibi görünür; ama 500 nesne ve büyük bir kapasite olduğunda deneme yanılma içinden çıkılmaz hale gelir.

**Hanoi kuleleri.** Diskler A çubuğundan, B çubuğu aracı kullanılarak C çubuğuna, büyük disk küçüğün üstüne gelmeyecek biçimde taşınır. Disk sayısı arttıkça çözüm üstel ya da daha hızlı biçimde büyür. Fibonacci sayıları da hızla büyüyen bir örnek olarak anıldı.

**Program sonlanması.** Girdi olarak verilen bir programın sonlanıp sonlanmayacağını bulan bir program istenir. Basit programlarda bu yapılabilir; ama örneğin sırt çantası problemini çözen kötü bir program verildiğinde bitmesi beklenir ve bitmez, çünkü sonsuz (finite olmayan) bir algoritmayla karşı karşıya kalınabilir. Bu problemlerin bazılarının verimli algoritması yoktur, bazılarının hiç algoritması yoktur; büyüme o kadar hızlıdır ki algoritma geliştirmek mümkün olmaz.

## 7. Algoritmalarla İlgili Temel Sorunlar

Slayttaki başlıklar (ekrandan, 02:30:00):

- How to design algorithms (algoritma nasıl tasarlanır)
- How to express algorithms (nasıl ifade edilir)
- Proving correctness (doğruluk nasıl ispatlanır)
- Efficiency (or complexity) analysis: theoretical analysis, empirical analysis (verimlilik ya da karmaşıklık analizi: teorik ve deneysel)
- Optimality (optimallik)

### 7.1 Tasarım ve doğruluk

Algoritma tasarlamak için önce problemin tanımı bilinmelidir: girdi olarak hangi veriler kullanılacak, çıktı olarak ne elde edilecek. Sonra girdiden çıktıya götüren adımlar, sıralı, koşullu ve tekrarlı yapıların birleşimiyle kurulur. Bu adımlar sonlu ve belirsizlik içermeyen adımlar olmalı ve verimli çalışmalıdır.

Doğruluk, girdileri ve beklenen çıktıları bilinen test durumlarıyla sınanır. Test durumlarında doğru sonuç çıkıyorsa algoritmanın doğruluğu gösterilmiş sayılır. Uygulamaya konabilmesi için verimli olması ve diğer özellikleri de sağlaması gerekir.

Hoca tasarımın analizden geçtiğini söyledi ve bunu insanın öğrenmesine benzetti: üslü sayılar öğrenilecekse önce notasyon gibi parametreler zihinde analiz edilir, sonra bilinenlerden bilinmeyenlere bir yol kurulur. Algoritmada da bilinenler girdilerdir ve bilinmeyene doğru bir dizi işlem yapılır. Değişkenlerin analizi (doğruluk ispatında kullanılır) ile verimlilik analizi (zaman ve bellek) ayrı şeylerdir.

### 7.2 Kesin çözüm ve "optimal" çözüm

Tahtada "Proving correctness" başlığından iki dal çıkıyor: "Exact solution" ve "Optimal solution" (ekrandan, 02:30:00). Türkiye haritası için gezgin satıcı problemini düşünelim: kesin çözümü bulmak bugünkü bilgisayarlarla belki mümkün değildir.

**Soru (hoca):** Türkiye'deki bütün illeri dolaşmak sizce kaç kilometre eder? **Cevap:** Bir öğrenci tahminen 50.000 km dedi. Hoca, karayolları haritasındaki mesafelerle genetik algoritma ve karınca kolonisi algoritması kullanılarak yaklaşık 30.000 km civarında bir tur bulunduğunu aktardı. Bu yöntemler tam çözüm değildir: örneğin İstanbul'dan başlayıp her adımda en yakın ile (örneğin Kocaeli) geçerek bütün Türkiye gezilir ve başlangıca dönülür.

> **Ders sonrası not:** Hoca bu tür kabul edilebilir çözüme "optimal solution" dedi. Literatürde optimal çözüm en iyi (kesin) çözüm demektir; hocanın kastettiği büyük olasılıkla optimale yakın, yaklaşık (approximate) ya da sezgisel (heuristic) bir çözümdür.

### 7.3 Teorik ve deneysel analiz

**Teorik analiz:** Zaman ve bellek için, girdi boyutuna bağlı matematiksel fonksiyonlar kurulur: $T(n)$ zaman için, $S(n)$ ya da $M(n)$ bellek için (ekrandan, 02:30:00). Bu fonksiyonun $n$'nin farklı değerlerinde, özellikle $n \to \infty$ iken nasıl büyüdüğü incelenir. Bu dersin ağırlığı bu kısımdadır.

**Deneysel (empirical) analiz:** Algoritmanın başlangıcına ve bitişine bir zamanlayıcı konur; $t_1$ ve $t_2$ alınıp $t_2 - t_1$ hesaplanır. Deney birkaç kez ve farklı $n$ değerleriyle (10, 100, 10.000, ...) tekrarlanır ve süre farkının $n$'ye göre grafiği çizilir. Grafik doğrusal, üstel artan ya da bir yerden sonra sabit bir eğilim gösterebilir; buradan istatistiksel bir tahmin yürütülür. Bir başka yol, algoritmanın temel işlemini saymaktır: sıralamada temel işlem karşılaştırmadır; swap da onun bir sonraki adımıdır ve ne kadar az swap yapılırsa algoritma o kadar rahat çalışır. Swap yapılan bloğa bir sayaç konur ve farklı $n$ değerleri için sayaç değeri izlenir.

Önemli olan kaynakların ne kadar kullanıldığı ve sonuçların ne kadar doğru olduğudur. Kaynakları sınırsız kullanıp çok doğru sonuç almak bir seçenektir; kaynakları sınırlı kullanıp olabildiğince doğru sonuç almak başka bir seçenektir. Örneğin bütün illeri dolaşmak için 20.000 km'nin altında bir rota veren bir program, belki 13.000 km'lik bir rota olsa bile, kısa sürede sonuç istendiğinde yeterli olabilir.

## 8. Algoritma Tasarım Stratejileri

Slayttaki stratejiler (ekrandan, 02:35:00):

| Sol sütun | Sağ sütun |
|---|---|
| Brute force (kaba kuvvet) | Greedy approach (açgözlü yaklaşım) |
| Divide and conquer (böl ve yönet) | Dynamic programming (dinamik programlama) |
| Decrease and conquer (azaltarak yönet) | Backtracking and branch-and-bound (geri izleme, dal ve sınır) |
| Transform and conquer (dönüştür ve yönet) | Space and time tradeoffs (yer-zaman ödünleşimi) |

- **Kaba kuvvet:** Şimdiye kadar en çok kullanılan yaklaşımdır.
- **Böl ve yönet:** Örneğin merge sort'ta görülür; problem sürekli yarıya bölünür.
- **Azaltarak yönet:** En basit örneği özyinelemeli faktöriyeldir; $5!$ için $4!$, onun için $3!$ çağrılır, problem her adımda bir küçülür. Dersin başında Fibonacci için de $F(n) = F(n-1) + F(n-2)$ çağrılarıyla problemin bir alt değere küçültülerek çözüldüğü söylenmişti.
- **Dönüştür ve yönet:** Bilinen problemlere üretilmiş çözümleri, yeni problemi dönüştürerek kullanmaktır; örnekleri ileride gelecektir.
- **Açgözlü yaklaşım:** Optimizasyon algoritmalarına alan açan, ilk bakışta tam çözüm vermeyen ve çoğu zaman vermeyecek, ama kabul edilebilir bir toleransla sonuç veren algoritmaları içerir.
- **Dinamik programlama:** Böl ve yönet ile azaltarak yönetteki tekrarlı hesapları önleyen ve tam sonuca götürmeye çalışan bir tekniktir. Tahtadaki Fibonacci çağrı ağacı (ekrandan, 02:35:00):

```text
            fib(3)
           /      \
       fib(2)    fib(1)
       /    \
   fib(1)  fib(0)
```

$fib(1)$ iki kez hesaplanır. Bir değer bir kez hesaplandıktan sonra yeniden hesaplanması gereksizdir; $n$ büyüdükçe ağaç derinleşir ve tekrarlar çok artar. Dinamik programlama bu tekrarları önler.

> **Hocanın vurgusu:** Dinamik programlama önemli bir tekniktir, çok iyi bilmek gerekir.

- **Geri izleme, dal ve sınır, yer-zaman ödünleşimi:** Bazı algoritmalarda bellek bol kullanılarak zaman kısaltılır; bu tür analizler yapılacaktır.

## 9. Algoritma Analizi: Daha İyi Algoritma Var mı?

Slayt (ekrandan, 02:45:00):

- How good is the algorithm? time efficiency, space efficiency, correctness ignored in this course
- Does there exist a better algorithm? lower bounds, optimality

Bir algoritmanın iyiliği doğru sonuç vermesine, zamanı ve belleği etkin kullanmasına bağlıdır. Bir algoritmanın ötekinden iyi olup olmadığı alt sınırlarla ve kaynakların optimum kullanımıyla ölçülür.

Alt sınır örneği: sırasız bir dizide en büyük eleman aranıyor. Birinci elemandan başlayıp 2, 3, 4, 5 diye ilerlenir; son elemana bakmadan "en büyüğü buldum" denemez, ancak iddia edilmiş olur. Bu yüzden bütün elemanlara bakmak gerekir; bu, problemin alt sınırıdır. Dizi küçükten büyüğe sıralıysa en büyük eleman son elemandır ve tek bir bakışla bulunur. Elemanların dağılımına ve durumuna göre alt sınır düşebilir.

> **Ek bilgi (derste anlatılmadı):** Sırasız $n$ elemanlı bir dizide en büyüğü bulmak için her elemana en az bir kez bakılmalıdır; karşılaştırma sayısı olarak alt sınır $n-1$'dir ve basit doğrusal tarama bu sınıra ulaştığı için optimaldir.

Slayta göre bu derste doğruluk ispatları ve test durumları büyük ölçüde dışarıda bırakılır; tasarım konusu zaman ve bellek verimliliği ölçütleri üzerinden işlenir.

Hoca algoritmanın teorik ve pratik önemine de değindi: verinin çok arttığı, hızın çok önemli olduğu ve bilgisayarların hayatın her yerinde bulunduğu bir dönemde algoritma verimliliği vazgeçilmezdir. Örneğin bir görüntülü görüşme uygulamasının yaygınlaşması, görüntü aktarımında rakiplerinden daha iyi performans göstermesiyle ilgilidir.

## 10. Önemli Problem Türleri

Dersin geri kalanında sık kullanılan problem türleri incelenecektir:

- **Sıralama:** Sıralama algoritmalarının özellikleri ve hangi tasarım stratejisiyle ilişkili oldukları (azaltarak yönet, böl ve yönet vb.).
- **Arama:** Doğrusal arama şimdiye kadar kullanıldı; ikili arama (binary search) ve interpolasyon araması (interpolation search) da incelenecek. Dizi sıralıysa tek tek arama yapmaya gerek yoktur.
- **Dizgi işleme:** Bir dizgi içinde başka bir dizgi (örneğin "src") aranırken karakterler tek tek karşılaştırılır; eşleşmeyen karakterde kaydırılır. Karşılaştırmaya baştan mı sondan mı başlamanın daha mantıklı olduğu ayrıca incelenecektir.
- **Çizge problemleri:** Gezinti (traversal), en kısa yol, topolojik sıralama. Çizgeler web'de, haberleşmede, proje ve iş planlamada çok kullanılır. Yönlü bir çizgede hangi işin önce, hangisinin sonra yapılacağı topolojik sıralamayla bulunur.

Algoritmanın üç temel işlemi (sıralı: toplama, çıkarma, çarpma, bölme; koşullu: `if`; tekrarlı: `for`, `while`) her problemi çözmeye yetmez. Programlama dillerinde ve veri yapıları (data abstraction) dersinde öğrenilen bilgilere ihtiyaç vardır.

> **Hocanın vurgusu:** Bu veri yapılarının istisnasız hepsinin C kodunu yazabilmek gerekir. Bunlar bu derste amaç değil, problem çözmek için kullanılan araçlardır. Bir dizgi problemini bağlı liste üzerinden ya da bir çizge problemini yığın kullanarak çözmeniz istenebilir.

Hoca kendi bağlı liste, yığın, kuyruk, heap ve öncelik kuyruğu kodlarını bir kütüphane gibi hazır bulundurmayı önerdi. Bunun için C'de dinamik bellek (`malloc`, `calloc`), `struct`, pointer, struct pointer, dosya işlemleri (veriler genellikle dosyadan okunacak) ve fonksiyonlara bölme bilinmelidir (tahtada: Dyn., Struct, pointer, File, Fon.; ekrandan, 02:50:00).

## 11. Temel Veri Yapıları

Slayttaki liste (ekrandan, 02:50:00): list (array, linked list, string), stack, queue, priority queue/heap, graph, tree and binary tree, set and dictionary.

### 11.1 Dizi ve bağlı liste

**Dizi**, indislerle erişilen ve bellekte ardışık (contiguous) hücrelerde saklanan bir yapıdır. Bir elemanın adresi biliniyorsa bir sonrakinin adresi bir ekleyerek, bir öncekinin adresi bir çıkararak bulunur. Avantajı erişim kolaylığıdır; ek bir şey tutmaya gerek yoktur, bir indis değişkeni her şeyi halleder. Dezavantajı araya ekleme ve silmedir: araya bir eleman eklenecekse sondaki elemandan geriye doğru elemanlar birer kaydırılır (shift). Ayrıca dizinin kapasitesi yetersiz kalabilir ve bellek büyük bir bütünleşik alan vermeyebilir: 4 GB RAM'de 3 GB veri saklanmak istenir ama bellek dağınık olduğu için 3 GB'lık ardışık yer bulunamaz.

**Bağlı liste** (linked list) bellekte dağınık (non-contiguous) saklanır ve düğümler pointer'larla bağlanır. Her düğüm yalnız sonrakinin adresini tutuyorsa tek yönlü (single), hem öncekinin hem sonrakinin adresini tutuyorsa çift yönlü (double) bağlı listedir. Araya ekleme ve silme görece kolaydır: ilgili yere gelinir, önceki ve sonraki düğümler yeniden bağlanır, kaydırma gerekmez.

Bu iki yapı temeldir, çünkü diğer yapıların hepsi dizilerden ve bağlı listelerden türer.

### 11.2 Yığın, kuyruk ve öncelik kuyruğu

**Yığın (stack):** En son eklenen ilk alınır (LIFO); ekleme ve çıkarma yalnız tepeden yapılır (push, pop). Dizi ya da bağlı listeyle kurulabilir; dinamik olması isteniyorsa bağlı liste kullanılır.

**Kuyruk (queue):** Eklemenin arkadan, silmenin önden yapıldığı, ilk giren ilk çıkar (FIFO) esasına göre çalışan yapıdır (enqueue, dequeue). Normal dizide istenen yere eleman eklenip çıkarılabilirken yığın ve kuyrukta işlemler belli kurallara bağlıdır; yapılan şey dizileri ve bağlı listeleri farklı bir amaçla kullanmaktır.

**Öncelik kuyruğu (priority queue):** Veriler bir kuyrukta saklanır ama kuyruk verinin önceliğine göre düzenlenir; önceliği yüksek olan doğrudan sona değil, öne geçer. Daha çok heap ile kullanılır; heap sort gibi sıralama algoritmalarında ve özellikle paylaşımlı bilgisayarlardaki zamanlama (scheduling) uygulamalarında kullanılır. Görünüşü bir ağaç gibidir ama doğrudan bir dizi üzerinde de gerçekleştirilebilir.

## 12. Çizgeler ve Ağaçlar

### 12.1 Çizgelerin tanımı ve gösterimi

Slayt (ekrandan, 02:55:00):

- Bir çizge $G = \langle V, E \rangle$, iki kümeyle tanımlanır: köşe (vertex) adı verilen öğelerin sonlu kümesi $V$ ve kenar (edge) adı verilen köşe çiftlerinin kümesi $E$.
- Yönsüz ve yönlü çizgeler (digraph).
- "What's the maximum number of edges in an undirected graph with |V| vertices?"
- Tam (complete), yoğun (dense) ve seyrek (sparse) çizgeler; her köşe çifti bir kenarla bağlıysa çizge tamdır: $K_{|V|}$.

Hangi köşenin hangisiyle ilişkili olduğu bir 0-1 matrisiyle, ilişkinin maliyeti ya da derecesi bir uzaklık (distance) matrisiyle saklanır. Üç köşe için $3 \times 3$'lük bir matris yeter; yani iki boyutlu bir dizi kullanılır. Köşe çok, kenar az ise matris sıfırlarla dolar; buna seyrek matris ya da seyrek çizge denir. Bu durumda **komşuluk listesi** (adjacency list) daha uygundur: örneğin A'nın B ve C'ye, B'nin A ve C'ye komşu olduğu listelerle yazılır. Bağlı liste düğümünde birden fazla veri saklanabildiği için maliyet de yazılabilir (örneğin B'nin A'ya komşuluğu 5, C'ye komşuluğu 8). Matris biçimine **komşuluk matrisi** (adjacency matrix) denir.

**Ağırlıklı çizgede** kenarların bir maliyeti vardır: kilometre, para, zaman ya da başka bir birim. Bu birimin ne olduğu problemden çıkarılır ve çizge buna göre tasarlanıp bir matrisle saklanır.

### 12.2 Yol, bağlılık ve döngü

- **Yol (path):** $u$ köşesinden $v$ köşesine, ardışık köşeleri komşu olan köşeler dizisidir; A'dan B'ye bir yol bulma işidir.
- **Basit yol (simple path):** Bütün kenarları birbirinden farklı olan yol. Yolun uzunluğuna yol uzunluğu (path length) denir.
- **Bağlı çizge (connected graph):** Bütün köşeler birbirine bir biçimde bağlıysa çizge bağlıdır ve tek parçadır.
- **Bağlı bileşen (connected component):** Çizge birbirine bağlı olmayan parçalara ayrılmışsa her parça bir bağlı bileşendir; her biri kendi içinde bir alt çizge gibi düşünülür.
- **Döngü (cycle):** Bir köşeden başlayıp aynı köşeye geri dönülebiliyorsa çizgede döngü vardır. Döngü içermeyen çizgeye asiklik (acyclic) çizge denir; yönlü asiklik çizgeler (DAG) bu ders ve veri yapıları dersinde farklı biçimlerde incelenir.

> **Ek bilgi (derste anlatılmadı):** Hoca basit yolu önce "bütün köşeleri farklı", sonra düzelterek "bütün kenarları farklı" yol diye tanımladı. Kaynaklar arasında bu tanım değişir: bazı kitaplar basit yol için kenarların, birçoğu ise köşelerin tekrar etmemesini şart koşar.

### 12.3 Ağaçlar

Slayt (ekrandan, 03:00:00):

- Ağaç (ya da serbest ağaç, free tree) bağlı ve döngüsüz bir çizgedir.
- Orman (forest): döngüsü olmayan ama bağlı olması gerekmeyen çizge.
- Bir ağaçta her iki köşe arasında her zaman tam olarak bir basit yol vardır. Neden?
- Köklü ağaçlar: bu özellik sayesinde serbest ağaçta herhangi bir köşe seçilip kök kabul edilebilir.
- Köklü ağaçta seviyeler.

Slayttaki örnek ağacın kenarları: 1–3, 3–5, 1–2, 3–4. Bu ağaç 1 kök alınarak köklü ağaç gibi görülebilir (1, 3'ü ve 2'yi; 3 de 4'ü ve 5'i türetir); istenirse 3 de kök seçilebilir.

Ağaçta kenar sayısı köşe sayısının bir eksiğidir, çünkü döngü olmamalıdır:

$$|E| = |V| - 1$$

> **Ders sonrası not:** Hoca bir yerde "döngü yoksa ona ağaç diyeceğiz" dedi. Doğrusu, ağaç için çizgenin hem bağlı hem döngüsüz olması gerekir; bağlı olmayan döngüsüz çizge ormandır. Slaytta da bu ayrım yapılıyor.

**Terminoloji:** Bir düğümün yukarısındaki düğümler ata (ancestor), aşağısındakiler torun (descendant) düğümlerdir. Bir düğümün hemen üstündeki ebeveyn (parent), hemen altındaki çocuk (child), aynı ebeveynin çocukları kardeş (sibling) düğümlerdir. Çocuğu olmayan düğüm yapraktır. Bir düğüm ve altındaki her şey bir alt ağaçtır.

**Derinlik ve yükseklik:** Bir düğümün derinliği köke olan uzaklığıdır. Ağacın yüksekliği, en derin düğümün derinliğidir. Slayttaki örnekte en derin düğümler köke iki kenar uzaklıkta olduğu için yükseklik $h = 2$'dir. <!-- BELİRSİZ: Hoca önce örnek bir ağaçta en derin düğüm için "3" dedi, sonra slayttaki ağaç için h = 2 olduğunu söyledi; konuşulan ağaç karede görünmüyor. -->

**Sıralı ağaçlar:** Belli bir düzene göre sıralanmış ağaçlardır. **İkili ağaçta** (binary tree) her düğümün en çok iki çocuğu vardır. **İkili arama ağacında** (binary search tree) bir düğüme gelen değer düğümden büyükse sağa, küçükse (ya da eşitse) sola gider.

Örnek: 10, 18, 7, 24 sırasıyla eklensin. 10 köke oturur; 18 büyük olduğu için 10'un sağına; 7 küçük olduğu için 10'un soluna; 24 önce 10'un sağına, sonra 18'in sağına gider:

```text
        10
       /  \
      7    18
             \
              24
```

Bu mantık her zaman verimli değildir. 1, 2, 3, 4, 5 sırayla eklenirse ilk gelen 1 köke oturur ("tahta ilk oturan padişah olur"), sonrakiler hep büyük olduğu için hep sağa gider:

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
```

Ağaç doğrusal bir bağlı listeden farksız hale gelir. Bunu düzelten, ağacı kırıp sol ve sağ tarafı dengeleyen algoritmalar ileride görülecektir.

### 12.4 Araç çantası

Ayrık matematik, programlama ve veri yapıları derslerinde görülen bu yapılar, hocanın deyişiyle bu dersin "alet çantası"dır. Özyineleme de çok önemlidir ve yeri gelince yeniden anlatılacaktır. Derinlik öncelikli arama (DFS) yığın, genişlik öncelikli arama (BFS) kuyruk kullanır; DFS'yi kodlamak için yığın yapısını ve işlemlerini, BFS için kuyruk işlemlerini yazabilmek gerekir. Bu derste problemin çözüm yöntemi (burada kuyruk, burada yığın, burada ikili arama ağacı kullanılır) anlatılacak; araçları kullanarak problemi çözmek öğrenciye düşer.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:30:45): Fibonacci sayılarını özyinelemeli olarak hesaplarken nasıl bir çağrı yapılır?

Derste verilen cevap: $F(n) = F(n-1) + F(n-2)$. Problem bir alt değere küçültülerek çözülür; faktöriyel de benzerdir.

**Soru 2** (derste sözlü, 01:29:10): Algoritmanın ifade biçimlerine örnek veriniz.

Derste verilen cevap: sözde kod, akış şeması, programlama dili ve sözlü anlatım (ekrandan, 01:30:00).

**Soru 3** (derste sözlü, 01:37:19; ekrandan, 01:40:00): $\gcd(4,18)$'i bir programla nasıl bulursunuz? Kullandığınız çözümde sıralı (1), koşullu (2) ve tekrarlı (3) yapılardan hangileri vardır?

Derste verilen çözüm: $t = \min(4,18) = 4$'ten başlanır, $t$ iki sayıyı da bölene kadar bir azaltılır; $t = 2$'de durulur, OBEB 2'dir. Bir öğrenci 3 ve 2 dedi; hoca üçünün de kullanıldığını açıkladı: tekrarlı yapı (`while`), koşullu yapı (bölünebilme kontrolü için `if`), sıralı yapı (önce bir sayının, sonra ötekinin kalanının hesaplanması ve karşılaştırma).

**Soru 4** (ekrandan, 01:50:00): $\gcd(858, 30)$'u Öklid algoritmasıyla bulunuz.

Derste verilen çözüm:

$$\gcd(858,30) = \gcd(30,18) = \gcd(18,12) = \gcd(12,6) = \gcd(6,0) = 6$$

Ardışık tamsayı kontrolü aynı sonuca 30'dan 6'ya 25 denemede ulaşır.

**Soru 5** (ekrandan, 01:50:00): $7x - 8y = 1$ eşitliğini sağlayan $x, y$ tamsayılarını bulunuz.

> **Çözüm (derste verilmedi):** Genişletilmiş Öklid: $8 = 1 \cdot 7 + 1$, dolayısıyla $1 = 8 - 7$, yani $7 \cdot (-1) - 8 \cdot (-1) = 1$. Bir çözüm $x = -1$, $y = -1$'dir. Genel çözüm $x = -1 + 8k$, $y = -1 + 7k$'dir; örneğin $k = 1$ için $x = 7$, $y = 6$: $49 - 48 = 1$ (Python ile doğrulandı).

**Soru 6** (ekrandan, 02:10:00): Seçmeli sıralama algoritması (`for i = 1 to n: swap a[i] with smallest of a[i], ..., a[n]`) belirsizlik içermez mi? Etkin midir?

Derste verilen cevap: "En küçüğü bul" adımı gizli bir döngüdür ve ayrıca tanımlanması algoritmayı daha açık yapar. İç içe iki döngü nedeniyle kabaca $n^2$ işlem yapılır; küçük dizilerde yeterli, çok büyük dizilerde verimsizdir. Yalnız bir geçici değişken kullandığı için yerindedir; kararlı değildir.

**Soru 7** (derste sözlü, 02:28:18): Türkiye'deki bütün illeri dolaşıp başlangıca dönen bir tur sizce kaç kilometredir?

Derste: bir öğrenci tahminen 50.000 km dedi; hoca sezgisel yöntemlerle (genetik algoritma, karınca kolonisi) yaklaşık 30.000 km civarında bir tur bulunduğunu aktardı ve bunun kesin çözüm olmadığını vurguladı.

**Soru 8** (ekrandan, 02:55:00): $|V|$ köşeli yönsüz bir çizgede en fazla kaç kenar olabilir?

> **Çözüm (derste verilmedi):** Döngüsüz kenar (self-loop) ve çoklu kenar yoksa her köşe çifti en fazla bir kenarla bağlanır. Köşe çifti sayısı $\binom{|V|}{2} = \dfrac{|V|(|V|-1)}{2}$'dir; bu sayıya ulaşan çizge tam çizgedir ($K_{|V|}$). Örneğin 5 köşede en fazla 10 kenar olur.

**Soru 9** (ekrandan, 03:00:00): Bir ağaçta her iki köşe arasında neden tam olarak bir basit yol vardır?

> **Çözüm (derste verilmedi):** Ağaç bağlı olduğu için her iki köşe arasında en az bir yol vardır. İki farklı basit yol olsaydı, bu yolların ayrıldığı ve yeniden birleştiği köşeler arasındaki iki parça birlikte bir döngü oluştururdu; bu, ağacın döngüsüz olmasıyla çelişir. Bu yüzden yol tektir.

**Soru 10** (derste sözlü, 02:44:21): Hoca, ders sonrası çalışma olarak slayttaki asallık/kalbur algoritmasını izlemeyi (trace) ve değişken analizi yapmayı önerdi. <!-- BELİRSİZ: Hangi slaytın kastedildiği karelerde görünmüyor; altyazıda Eratosten kalburu anılıyor. -->

> **Çözüm (derste verilmedi):** Standart Eratosten kalburu $n = 25$ için: 2'den 25'e kadar sayılar yazılır. $p = 2$: 4, 6, ..., 24 silinir. $p = 3$: 9, 15, 21 silinir (6, 12, 18, 24 zaten silinmişti). $p = 5$: 25 silinir. $p^2 > 25$ olan ilk asal 7'dir, durulur. Kalan sayılar asaldır: 2, 3, 5, 7, 11, 13, 17, 19, 23 (Python ile doğrulandı).

## Dersin Toparlaması

Bu ilk derste algoritma, her geçerli girdi için sonlu sürede doğru çıktı üreten, belirsizlik içermeyen sıralı komutlar dizisi olarak tanımlandı; açıklık, etkinlik, sonluluk ve doğruluk özellikleri ile sözde kod, akış şeması, programlama dili ve sözlü anlatım gibi ifade biçimleri konuşuldu. OBEB problemi için ortaokul yöntemi, ardışık tamsayı kontrolü ve Öklid algoritması karşılaştırıldı: üçü de doğru ve sonlu, ama zaman verimlilikleri çok farklı. Seçmeli sıralama üzerinden belirsizlik, etkinlik, yerinde olma ve kararlılık kavramları tartışıldı. Sıralama, arama, en kısa yol, en küçük kapsayan ağaç, gezgin satıcı ve sırt çantası gibi temel problemler, bazı problemlerin verimli algoritmasının ya da hiç algoritmasının olmadığı fikriyle birlikte tanıtıldı.

Dersin ikinci yarısında algoritmalarla ilgili temel sorunlar (tasarım, ifade, doğruluk, teorik ve deneysel analiz, optimallik), tasarım stratejileri ve alt sınır kavramı özetlendi; sonra dizi, bağlı liste, yığın, kuyruk, öncelik kuyruğu, çizge ve ağaç yapıları bu dersin "alet çantası" olarak tekrar edildi. Sonraki derslerde iteratif ve özyinelemeli algoritmaların analizine, en iyi/en kötü/ortalama durum kavramlarına ve tasarım stratejilerine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
