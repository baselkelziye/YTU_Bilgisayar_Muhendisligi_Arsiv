# Ders 12 Genişletilmiş Notu: Dizide Arama Akışları ve Matrisler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dizide Verilen Değere Sahip Tüm Elemanları Bulmak
- 2. Akışın Analizi
- 3. Dizide Bir Değerin Olup Olmadığını Bulmak
- 4. İkili Arama Neden Burada Kullanılamaz?
- 5. Matris
- 6. Örnek: Matrisin Satır Toplamlarını Yeni Bir Diziye Aktarmak
- 7. Satır Toplamı Akışının Analizi
- 8. Matris ve Koordinat Sistemi

## 1. Dizide Verilen Değere Sahip Tüm Elemanları Bulmak

Ders, önceki derslerde konuşulan dizi kavramı ve döngülerle ilgili bir pratikle başladı. Hoca ekrana bir `A` dizisi yazdı (ekrandan, 00:20:00):

```text
indis :  1  2  3   4  5  6  7  8
A     :  3  5  7  11  8  7  6  5
```

### 1.1 Problem

İlk soru şuydu: "A dizisi içerisinde geçen ve 5 değerine sahip tüm elemanları bulan algoritmaya ait akış diyagramını çizin." Hoca soruyu yazdıktan sonra 5'in üstünü çizip yerine "verilen" yazdı. Böylece soru genelleşti: "Verilen `X` değerine sahip tüm elemanları bulan algoritmaya ait akış diyagramını çizin." `X` yerine 3 konursa 3'e eşit olanların, 7 konursa 7'ye eşit olanların hepsi bulunacaktır.

Hoca sorudaki "tüm" kelimesinin altını çizdi. Yalnız ilk geçeni bulmak ya da 5'in dizide geçip geçmediğini söylemek istenmiyor.

> **Hocanın vurgusu:** Her zaman size sorulan soruyu iyice irdeleyin, ne istediğine vakıf olmaya çalışın. Bu yalnız sınav için değil, bütün dersler ve günlük hayat için geçerlidir.

### 1.2 Çözüm fikri

Yapılması gereken, dizinin elemanlarını sırayla kontrol etmektir: birinci adımda birinci eleman, ikinci adımda ikinci eleman ve böyle devam. `X = 5` için: 3 ile 5 aynı mı? Değil, devam. 5 ile 5 aynı mı? Aynı; bu elemanın konumu ya ekrana yazdırılır ya da ayrı bir dizide saklanır. Sonra 7, 11, 8, 7, 6 tutmaz; sekizinci göz yine 5'tir ve o da bulunur.

Akışa başlamadan önce neyin okunacağı belirlenir: `N` elemanlı bir dizi okunacak, bir de aranan sayının ne olduğu okunmalıdır. Burada bir şart aranmıyor; bütün elemanlara tek tek bakılacak. Bu yüzden adım sayısı belli olan for döngüsü uygundur.

### 1.3 Akış

Hocanın çizdiği akış (ekrandan, 00:25:00):

```text
START
  |
[ N, A(N), X ]                       (girdi)
  |
[ I <- 1 || 1 ; bitiş N ]  <-----------------+
  | (döngü bitince)     | (döngü gövdesi)    |
STOP                < A(I) = X >             |
                     F |        T |          |
                       |      ( I )  (çıktı) |
                       +------+---+          |
                              +--------------+
```

Doğru kolunda yazdırılan şey elemanın değeri değil, indisi `I`'dır.

### 1.4 "Elemanları bulmak" ne demek?

Bir öğrenci, bir sayaç (`count`) tutup eşitlik olunca artırmayı, döngüden çıkınca da sayacı yazdırmayı önerdi. Hoca bunun bu soruya cevap olmadığını söyledi: soru kaç eleman olduğunu sormuyor, elemanları bulmayı istiyor. Bir dizinin içindeki elemanı tanımlayan şey dizideki konumudur. Bu yüzden hoca indisi ekrana yazdırmayı tercih etti. "X değerine sahip kaç eleman var?" diye sorulsaydı sayaç yöntemi doğru olurdu ve konumlar önemli olmazdı.

**Soru:** Akışta `X` yerine doğrudan 5 yazmıyor muyuz? **Cevap:** Hayır. Akışın hiçbir yerinde `X` yerine 5 yazılmıyor. 5 yalnızca örnekti. Kullanıcı değeri dışarıdan girene kadar `X`'in ne olacağı bilinmez; `X` de dizinin boyutu ve dizinin kendisi gibi kullanıcıdan alınır. Kullanıcı 5 verirse 5 aranır, 15 verirse dizide olmayan bir değer aranır.

## 2. Akışın Analizi

Analizde akıştaki değişkenler ve bunların durumları adım adım kontrol edilir; şartlar varsa onların sonuçları da izlenir. Burada izlenen değerler `I` ve `A(I) = X` karşılaştırmasıdır.

> **Hocanın vurgusu:** Analiz de bu işin bir parçasıdır ve sorulabilecek şeylerden biridir.

### 2.1 Birinci durum: X = 5

`N = 8`, `X = 5` (ekrandan, 00:30:00):

| `I` | `A(I)` | `A(I) = X`? | Çıktı |
|---|---|---|---|
| 1 | 3 | hayır | |
| 2 | 5 | evet | 2 |
| 3 | 7 | hayır | |
| 4 | 11 | hayır | |
| 5 | 8 | hayır | |
| 6 | 7 | hayır | |
| 7 | 6 | hayır | |
| 8 | 5 | evet | 8 |

Akış 2 ve 8 çıktılarını verir. Bu sonuç python ile de kontrol edildi.

### 2.2 İkinci durum: X = 15

Akış bir durumda çalışıyor diye her durumda çalıştığı söylenemez. Hoca parametreleri değiştirdi: `N` yine 8, `X = 15`. Bu kez sekiz karşılaştırmanın hiçbiri tutmaz ve program hiçbir çıktı üretmeden biter. Verilen eleman dizide yoksa program "sesini çıkarmaz". "İstenilen değer dizide bulunmamaktadır" ya da kısaca "yok" gibi bir mesaj verilebilirdi, ama bu akışta yoktur.

Bir öğrenci bunun için şunu önerdi: bir sayaç belirlenir, `if`'in doğru kolunda sayaç bir artırılır; döngüden çıkınca ikinci bir `if` ile sayacın sıfıra eşit olup olmadığı kontrol edilir; eşitse "aradığımız eleman yoktur" yazdırılır. Hoca bunu makul buldu ve denemelerini istedi.

**Soru:** Koşul gerçekleşince ekrana `I` basılıyor. Döngü tamamlandığında bu çıktı ekrandan kaybolur mu? **Cevap:** Hayır. Ekran tamponu özellikle temizlenmedikçe (flush ya da clear edilmedikçe) önceki çıktı kaybolmaz. Laboratuvarda terminalde bir komut yazınca çıktısı oluşur; sonraki komutu yazınca önceki çıktı hâlâ görünür. Normal şartlarda hiçbir terminal ya da çıktı sistemi daha önce yazılanı silip üstüne yazmaz.

## 3. Dizide Bir Değerin Olup Olmadığını Bulmak

### 3.1 Problem

Hoca yaklaşımı değiştirdi: "Verilen `X` değerinin verilen `N` elemanlı dizinin içinde olup olmadığını bulan algoritmaya ait akışı çizin." Yeni bir örnek dizi yazdı; dizi 3, 7, 14 ile başlıyordu ve ileride bir 7 daha geçiyordu.

<!-- BELİRSİZ: İkinci örnek dizinin tüm elemanları altyazıda karışık okunuyor (14, 21, 44, 2, 8, 7, 24, 6, 8 ve sonradan eklenen 9 geçiyor); bu ana denk gelen kare yok. -->

`X = 15` ise dizinin bütün elemanlarına bakılır ve sonunda "bu dizide yok" denir. `X = 7` ise birinci elemana bakılır, tutmaz; ikinci elemanda eşleşme olur ve iş biter. `X = 14` olsaydı üçüncü elemanda çıkılacaktı. Dizide ikinci bir 7 de vardır, ama soru yalnız elemanın dizide geçip geçmediğini soruyor; hangi indiste olduğu ya da birden fazla kez geçtiği (multiple occurrence) bu problemde ilgilenilen bir şey değildir.

Kötü durum, aranan elemanın dizide olmamasıdır; o zaman bütün dizi dolaşılır. Eleman dizideyse bütün diziyi dolaşmadan aramayı kesme şansı vardır. Yani bu iş belli bir şart boyunca yapılır: aranan sayının dizinin elemanına eşit olması durumunda döngüden çıkılır. Bu uzun tariften sonra hoca, problemin koşullu bir döngüyle (while) çözülmesi gerektiğini söyledi.

### 3.2 Akış

Hocanın çizdiği akış (ekrandan, 00:45:00):

```text
START
  |
[ N, A(N), X ]
  |
[ I = 0 ]                 (bilerek yapılan hata, aşağıya bakın)
  |
< I <= N AND A(I) != X >  --T-->  [ I = I + 1 ]  --+
  | F                             ^                |
  |                               +----------------+
< I > N >
  F |              T |
 ( ... )          ( ... )         (iki çıktı kutusu, içleri boş)
  +-------+--------+
          |
        STOP
```

Hoca iki çıktı kutusunun içini önce boş bıraktı ve öğrencilerin düşünmesini istedi. Bir öğrenci akış diyagramında AND ya da OR'un nasıl yazılacağını sordu; hoca, operatörler slaytlarında akış diyagramında mantıksal operatörlerin nasıl kullanılacağının anlatıldığını hatırlattı.

### 3.3 Bilerek yapılan hata: I = 0

Hoca akışta bilerek bir hata yaptığını, ama kimsenin yakalamadığını söyledi: `I = 0`. Bu derste diziler 1'den başlar; `N` elemanlı bir dizi için indis 1'den `N`'e kadar gider. Bu yüzden ilk değer `I = 1` olmalıdır (ekrandan, 00:50:00).

### 3.4 Çıktı kutularının doldurulması

Döngü, `I ≤ N` ve `A(I) ≠ X` oldukça `I`'yı bir artırarak devam eder. Son adımda `I = N` iken `A(N)` de `X`'e eşit değilse `I` bir daha artar ve `N + 1` olur; artık `I ≤ N` sağlanmadığı için döngüden çıkılır. Demek ki eleman dizide yoksa çıkışta `I > N` beklenir. Böylece (ekrandan, 00:50:00):

- `I > N` doğru (T) ise "YOK" yazdırılır.
- `I > N` yanlış (F) ise eleman bulunmuştur, "VAR" yazdırılır.

Python ile kontrol: birinci örnek dizide `X = 5` için döngü `I = 2`'de durur (VAR), `X = 15` için `I = 9 = N + 1` olur (YOK).

> **Ek bilgi (derste anlatılmadı):** Eleman yoksa son kontrolde `I = N + 1` olur ve `A(N + 1)` dizinin dışındadır. C gibi dillerde `&&` operatörü kısa devre (short-circuit) değerlendirilir: soldaki `I <= N` yanlışsa sağdaki `A(I) != X` hiç hesaplanmaz. Bu yüzden indis kontrolünün koşulun solunda yazılması önemlidir.

### 3.5 AND ile bağlanan iki koşul

Bir öğrenci, eleman dizide yoksa bu while döngüsünden hiç çıkılmayacağını, çıkmak için iki koşulun birden sağlanması gerektiğini düşündü. Hoca açıkladı: while döngüsünde yalnız `I < N` olsaydı, `I`, `N`'den küçük olduğu sürece işin yapılması beklenirdi. İkinci bir şart AND ile bağlanınca döngünün devam edebilmesi için iki şartın birlikte sağlanması gerekir: `I ≤ N` olacak ve `A(I)`, `X`'e eşit olmayacak. Bu iki şarttan biri sağlanmadığı anda döngüden çıkılır. OR olsaydı ikisinden biri yeterdi; AND iki koşulun birlikte olmasını ister. Hoca, öğrencinin karışıklığının soruya tersinden (negatiften) yaklaşıp koşulu da tersine çevirmemesinden kaynaklandığını söyledi.

Bir öğrenci `N + 1` ile ilgili bir soru sordu, hoca "ne gerek var, mantık ne?" diye karşılık verdi. Öğrenci sonra kendisi fark etti: sekiz elemanlı bir dizide `I` döngüden 9 olarak çıkabiliyor; bu durum çıkıştaki `I > N` kontrolüyle zaten değerlendiriliyor. <!-- BELİRSİZ: Öğrencinin sorusunun tam metni altyazıda bozuk ("while'dan N artı birden küçük veya eşit olarak"). -->

## 4. İkili Arama Neden Burada Kullanılamaz?

**Soru:** Daha hızlı bulmak için bu problemi ikili arama (binary search) ile yazabilir miyiz? **Cevap:** İkili arama sıralı bir dizi üzerinde çalışır. Sırasız bir dizide ikili arama teknik olarak mümkün değildir. Burada dizinin sıralı olduğu söylenmiyor. Ayrıca önce sorunun ne sorduğu, nasıl istediği ve şartları sağlanmalıdır; ikili arama, derinlik öncelikli arama (depth first) gibi konular ileride anlatılacaktır.

> **Hocanın vurgusu:** Önce bu problemi çözün, anlayın ve kendi başınıza analiz edebilir hale gelin; hızlandırma ondan sonra gelir.

## 5. Matris

### 5.1 Matris nedir?

Birbiriyle ilişkili elemanları bir arada tutan yapıya dizi denir ve dizi tek boyutta ilerler. Matris ise hem bu boyutta hem diğer boyutta ilerler; iki boyutlu bir dizi olarak düşünülebilir. Bir boyut satırlar, diğeri sütunlardır (ekrandan, 00:55:00).

Bir dizinin elemanına `A(I)` ile ulaşılır. Matriste iki indis gerekir: birinci indis satırı, ikinci indis sütunu gösterir. Örneğin dördüncü satır, beşinci sütundaki elemana erişmek için `M(4)(5)` yazılır.

Matrisle harita bilgisi ya da görüntü bilgisi tutulabilir. Görülen iki boyutlu resimlerin hepsi bir matris biçimindedir; yalnızca matrisin oluşturulması ya da bilginin tutulması açısından farklılık gösterirler. İleride görüntü işleme dersinde ya da yapısal programlamada bir resim dosyası açıldığında, ekrandaki resme bir matris olarak erişilebildiği görülecektir.

### 5.2 Matrisin okunması

Dizi okunurken önce `N`, sonra `A(N)` okunuyordu; bu aslında `N` okunduktan sonra bir for döngüsüyle elemanların tek tek okunmasının kısaltmasıydı. Matriste iki boyut vardır, bu yüzden iki boyut okunmalıdır: `N` satırdan oluşan ve her satırı `M` sütundan oluşan `A(N)(M)` matrisi.

Akışta gösterim (ekrandan, 01:00:00 ve 01:05:00):

```text
[ N, M ]                          (matrisin boyutları)
  |
[ I <- 1 || 1 ; bitiş N ]  <--------------------+
  |                                             |
  +--> [ J <- 1 || 1 ; bitiş M ]  <---------+   |
         |                                  |   |
         +--> [ A(I)(J) ]  (girdi) ---------+   |
         | (J döngüsü bitince) -----------------+
```

Matris satırlardan oluşur ve her satır aslında bir dizidir. Her satırda bir dizi okunur; bu iş satır sayısı kadar yapılır, bu yüzden dizi okuma döngüsü bir for döngüsünün içine daha alınır. Kısa okuma biçimi dizide olduğu gibi geçerlidir: `N, M, A(N)(M)`. Önce boyutlar, sonra matris okunur.

## 6. Örnek: Matrisin Satır Toplamlarını Yeni Bir Diziye Aktarmak

### 6.1 Problem

Aradan sonra hoca matrisle ilgili bir örnek verdi (ekrandan, 01:15:00): "Verilen bir matrisin satırlarının toplamını yeni bir diziye aktaran algoritmaya ait akışı çiziniz."

Ekranda 5'e 5 bir matris ve yanında bir dizi çizildi. Her satırdaki elemanlar toplanıp dizinin bir gözüne yazılacaktır. Hangi göze? Satır numarası ile yazılacak gözün numarası aynı olmalıdır ki işler takip edilebilir ve anlaşılır olsun: birinci satırın toplamı birinci göze, ikinci satırınki ikinci göze.

Adımlar:

1. Matrisin boyutları alınır.
2. Matris okunur.
3. Matristeki her satırın elemanlarının toplamı bulunur ve diziye atanır.
4. Toplamlar yazdırılır.

**Soru:** Yeni diziye her satırın toplamı mı, ortalaması mı yazılacak? **Cevap:** Toplamı. Hoca adımları yazarken dördüncü adıma yanlışlıkla "ortalamaları" yazmıştı; düzeltti.

### 6.2 İlk çizim

Hoca yerden tasarruf etmek için kısa okuma biçimini kullandı: `N, M, A(N)(M)`. Toplama için bir ara değişkene ihtiyaç vardır; adı `SUM` konuldu ve 0 değeri atandı. İlk çizim (ekrandan, 01:25:00):

```text
START
  |
[ N, M, A(N)(M) ]
  |
[ SUM = 0 ]
  |
[ I <- 1 || 1 ; bitiş N ]  <------------- (1)
  | (bitince)          | (gövde)
  |                    [ J <- 1 || 1 ; bitiş M ]  <----+
  |                      | (bitince)    | (gövde)      |
  |                     (1)            [ SUM = SUM + A(I)(J) ] --+
  |
[ I <- 1 || 1 ; bitiş N ] --> ( SUM ) (çıktı) --> geri
  | (bitince)
STOP
```

Hoca "oldu mu?" diye sordu; birkaç öğrenci olmadığını söyledi.

### 6.3 Hataların düzeltilmesi

Bir öğrenci, `I` döngüsü her döndüğünde `SUM`'ın bir diziye atılması gerektiğini söyledi. Hoca, öğrencinin "o döngünün içi", "şu ok" gibi ifadelerle anlatmaya çalışması üzerine şunu vurguladı:

> **Hocanın vurgusu:** Muğlak ifadeler kullanmayın. Akıştaki elemanların adları var: "`I` birden `N`'e kadar olan döngü", "`J` birden `M`'e kadar olan döngü" diyebilirsiniz. Kavramları yanlış kullanmak karşınızdakiyle yanlış anlaşmak demektir. Örneğin iki şeyi karşılaştırın denince "biri şöyleyken diğeri böyle" cevabı, hangisinin hangisi olduğunu söylemediği için anlamsızdır.

Öğrencinin önerisi, iç döngü bittikten sonra (bağlantı noktası 1'e giden okun üstüne) bir dizi gözüne `SUM`'ı yazmak ve sonra `SUM`'ı tekrar sıfırlamaktı. Öğrenci diziyi baştan "tanımlamak" gerektiğini düşünüyordu. Hoca daha önce konuşulan kuralı hatırlattı: bir değişken sağ tarafta kullanılacaksa, yani işleme girecekse, ilk değer ataması yapılır (`SUM` gibi). Bu dizi ise işleme sokulmuyor; her satırda oluşan değer ilgili göze yazılıyor. Bu yüzden diziye ayrıca ilk değer vermek gerekmez.

Hoca dizinin adını da değiştirdi. Öğrenci `K` demişti, ama `I, J, K, L` genelde indis olarak kullanılan harflerdir; değişkenler ve diziler için `A, B, C` ya da `X, Y, Z` gibi adlar kullanılır (ekrandan, 01:30:00). Böylece `A` matris, `B` dizi oldu.

`SUM`'ı hem döngüden önce hem iç döngüden sonra sıfırlamanın bir anlamı yoktur. Her satırda sıfırlanması gereken şey zaten `SUM`'dır. Bu yüzden döngüden önceki `SUM = 0` kaldırılır ve `I` döngüsünün gövdesinin başına, `J` döngüsünden önce konur. Ama bu tek başına yetmez; çıktıda `SUM` yazdırılıyordu, doğrusu `B(I)` yazdırmaktır.

Düzeltilmiş akış (ekrandan, 01:30:00 ve 01:35:00):

```text
START
  |
[ N, M, A(N)(M) ]
  |
[ I <- 1 || 1 ; bitiş N ]  <------------------------------ (1)
  | (bitince)          | (gövde)
  |                  [ SUM = 0 ]
  |                    |
  |                  [ J <- 1 || 1 ; bitiş M ]  <------+
  |                    | (bitince)   | (gövde)         |
  |                  [ B(I) = SUM ] [ SUM = SUM + A(I)(J) ] --+
  |                    |
  |                   (1)
  |
[ I <- 1 || 1 ; bitiş N ] --> ( B(I) ) (çıktı) --> geri
  | (bitince)
STOP
```

### 6.4 SUM yerine doğrudan B(I) kullanmak

Bir öğrenci `SUM`'ı tamamen kaldırmayı önerdi: `I` döngüsünün başında `B(I) = 0` denir ve `SUM` görülen her yere `B(I)` yazılır (ekranda bu öneri de işaretlendi, 01:35:00). Hoca bunun teknik olarak çalışacağını, ama bir sakıncası olduğunu söyledi. Bir dizinin elemanına ulaşmak, dizinin bir referans noktasından (başlangıcından) indisin gösterdiği kadar ileri gitmek şeklinde hesaplanır. Bu yüzden dizi elemanına erişmek tek bir değişkene erişmekten biraz daha zahmetlidir. Erişim çok kez tekrarlandığı için arada geçici bir değişken kullanmak daha verimli bir çözümdür ve hoca bu yüzden geçici değişkeni tercih ediyor.

### 6.5 Döngü değişkenini yeniden kullanmak

**Soru:** STOP'tan önceki for döngüsünde yine `I` harfini kullanmak sorun değil mi? Önceki döngüde de `I` `N`'e kadar gitmişti. **Cevap:** Sorun değil. For kutusundaki `I ← 1`, `I`'ya ilk değer olarak 1 atanması demektir. Önceki döngüden çıkıldığında `I` hangi değerde olursa olsun, bu noktaya gelince üzerine yazılır ve `I` yeniden 1'den başlar. Dıştaki büyük döngüde yapılacak her şey zaten bitmiştir. Sorun ancak şöyle bir durumda olurdu: iç döngüde `J` yerine `I` yazılsaydı, yani `I` indisinin kullanıldığı bir döngünün içinde ikinci bir `I ← 1..M` döngüsü kurulsaydı, ortalık karışırdı.

> **Hocanın vurgusu:** Döngü değişkenlerini tekrar tekrar kullanmaktan çekinmeyin, ama bu döngülerin birbirinden bağımsız olması gerekir. İç içe döngülerde aynı döngü değişkeni kullanılamaz.

## 7. Satır Toplamı Akışının Analizi

Analiz için `N = 4`, `M = 5` seçildi; değerlerin ne olduğunun şu an için önemi yoktur. Matris (ekrandan, 01:40:00):

$$
A = \begin{pmatrix}
1 & 2 & 3 & 4 & 5 \\
6 & 7 & 8 & 9 & 10 \\
11 & 12 & 13 & 14 & 15 \\
16 & 17 & 18 & 19 & 20
\end{pmatrix}
$$

İzlenen değişkenler `I`, `J`, `A(I)(J)`, `SUM` ve `B(I)`'dır. Hoca `SUM` sütununun daha hızlı değiştiği için iç döngü değişkeninin yanına yazılmasının daha iyi olacağını söyledi.

| `I` | `J` | `A(I)(J)` | `SUM` (önce → sonra) |
|---|---|---|---|
| 1 | 1 | 1 | 0 → 1 |
| 1 | 2 | 2 | 1 → 3 |
| 1 | 3 | 3 | 3 → 6 |
| 1 | 4 | 4 | 6 → 10 |
| 1 | 5 | 5 | 10 → 15 |

`J` döngüsü bitince `B(1) = 15` atanır. Sonra `I = 2` olur, `SUM` sıfırlanır, `J` yeniden 1'den başlar:

| `I` | `J` | `A(I)(J)` | `SUM` (önce → sonra) |
|---|---|---|---|
| 2 | 1 | 6 | 0 → 6 |
| 2 | 2 | 7 | 6 → 13 |
| 2 | 3 | 8 | 13 → 21 |
| 2 | 4 | 9 | 21 → 30 |
| 2 | 5 | 10 | 30 → 40 |

`B(2) = 40`. `I = 3` için `SUM` sırasıyla 11, 23, 36, 50, 65 olur ve `B(3) = 65` atanır (ekrandan, 01:45:00). Hoca zaman nedeniyle `I = 4` adımına girmedi.

> **Ders sonrası not:** Derste izlenmeyen dördüncü satırda `SUM` sırasıyla 16, 33, 51, 70, 90 olur ve `B(4) = 90` bulunur. Dört satırın toplamları 15, 40, 65, 90'dır; bu değerler python ile kontrol edildi.

> **Hocanın vurgusu:** Sizden bir akış istendiğinde adım adım, yılmadan, son değeri görene kadar analizinizi yapmalısınız. Analiz isteniyorsa bütün örnek tamamlanmalıdır. Örnekler 1'e 1, 2'ye 2 gibi kolaycı seçimler olmamalı; farklı durumları simüle edebilmelidir.

**Soru:** Döngülerin sırası farklı olabilir mi? Sanki sütunlar toplanıp bir satıra yazılıyormuş gibi anladım. **Cevap:** Analize bakılırsa `A(1)(1)`, `A(1)(2)`, `A(1)(3)`, `A(1)(4)`, `A(1)(5)` toplanıyor; yani bir satır toplanıyor. Bu, dış döngü satırları dolaştığı için olur. Döngülerin yerleri değiştirilirse sütunlar toplanmış olur, ama istenen bu değildir. Analiz tam da bunu görmek için yapılır.

## 8. Matris ve Koordinat Sistemi

**Soru:** Başta `N` ve `M` boyutlu bir matris okuduk; `N` x koordinatlarını, `M` y koordinatlarını mı belirtiyor? **Cevap:** Hayır. Bu bir koordinat sistemi değil, satır ve sütunları olan bir matristir. Görüntü olarak benzer gelebilir, ama koordinat sisteminde sıfır noktası köşededir, değerler y ekseninde yukarı doğru artar. Matriste ise insan matrisi yazarken sol üst köşeden başlar; birinci indis artınca bir alt satıra, ikinci indis artınca bir sonraki sütuna geçilir. Yani `N` bir eksene benzetilecekse x'e değil y'ye denk gelir ve üstelik yönü terstir; değerler aşağı doğru artar (ekrandan, 01:45:00). Matrisi koordinat sistemine oturtmak için koordinat sistemini aynalayıp ters çevirmek gerekir. Bu yüzden ikisi birbirinden ayrı tutulmalıdır.

## Örnek Sorular

**1. (ekrandan, 00:20:00)** `N` elemanlı `A` dizisinde verilen `X` değerine sahip tüm elemanları bulan algoritmaya ait akış diyagramını çizin. `A = 3, 5, 7, 11, 8, 7, 6, 5` için `X = 5` ve `X = 15` durumlarında analiz yapın.

Çözüm (derste verildi): Bölüm 1.3'teki akış. For döngüsü `I ← 1 || 1`, bitiş `N`; gövdede `A(I) = X` doğruysa `I` yazdırılır. `X = 5` için çıktı 2 ve 8; `X = 15` için hiç çıktı yoktur. "Yok" mesajı için bir sayaç doğru kolunda artırılıp döngüden sonra 0 olup olmadığı kontrol edilebilir.

**2. (derste sözlü, 00:35:05)** Verilen `X` değerinin verilen `N` elemanlı dizinin içinde olup olmadığını bulan algoritmaya ait akışı çizin.

Çözüm (derste verildi): Bölüm 3.2 ve 3.4'teki akış. `I = 1`; `I <= N AND A(I) ≠ X` oldukça `I = I + 1`; döngüden sonra `I > N` ise "YOK", değilse "VAR" yazdırılır. Hocanın çiziminde bilerek yazılan `I = 0` hatalıdır.

**3. (derste sözlü, 00:52:39)** Bu arama ikili arama (binary search) ile daha hızlı yapılabilir mi?

Çözüm (derste verildi): Hayır; ikili arama yalnız sıralı dizide çalışır ve soruda dizinin sıralı olduğu söylenmiyor.

**4. (ekrandan, 01:15:00)** Verilen bir matrisin satırlarının toplamını yeni bir diziye aktaran algoritmaya ait akışı çiziniz.

Çözüm (derste verildi): Bölüm 6.3'teki düzeltilmiş akış. `I ← 1..N` döngüsünde `SUM = 0`; `J ← 1..M` döngüsünde `SUM = SUM + A(I)(J)`; iç döngüden sonra `B(I) = SUM`; en sonda `I ← 1..N` ile `B(I)` yazdırılır. `N = 4`, `M = 5` ve elemanları 1'den 20'ye kadar olan matris için `B = 15, 40, 65, 90` (derste ilk üçü izlendi).

**5. (ekrandan, 01:50:00)** Verilen `N, M` boyutlu bir matrisin en küçük elemanını bulan algoritmaya ait akışı çizin. (Derste quiz olarak verildi.)

> **Çözüm (derste verilmedi):** Derste anlatılan gösterimle bir çözüm şöyledir: `N, M, A(N)(M)` okunur; `MIN = A(1)(1)` ataması yapılır; `I ← 1 || 1` bitiş `N` dış döngüsü ve onun içinde `J ← 1 || 1` bitiş `M` iç döngüsü kurulur; iç döngünün gövdesinde `A(I)(J) < MIN` sorulur, doğruysa `MIN = A(I)(J)` atanır; döngüler bitince `MIN` yazdırılır. `MIN` için 0 gibi sabit bir ilk değer seçilmemelidir, çünkü bütün elemanlar bu değerden büyükse yanlış sonuç verir; ilk değer matrisin bir elemanı olmalıdır. Python ile kontrol: 1'den 20'ye kadar olan 4'e 5 matriste sonuç 1, `[[4, -2, 9], [0, 7, -5]]` matrisinde sonuç -5.

## Dersin Toparlaması

Bu derste diziler üzerinde iki farklı arama sorusu karşılaştırıldı. "Verilen değere sahip tüm elemanları bul" sorusunda bütün elemanlara bakmak gerektiği için for döngüsü kullanıldı ve bulunan elemanların konumları (indisleri) yazdırıldı. "Verilen değer dizide var mı" sorusunda ise eleman bulununca aramayı kesmek mümkün olduğu için iki koşulun AND ile bağlandığı koşullu bir döngü kuruldu ve döngü çıkışında `I > N` kontrolüyle sonuç belirlendi. Her iki akış da farklı girdilerle adım adım analiz edildi; analiz, akışın her durumda doğru çalışıp çalışmadığını görmenin yoludur.

Ardından matris iki boyutlu dizi olarak tanıtıldı: birinci indis satır, ikinci indis sütundur ve matris iç içe iki for döngüsüyle okunur. Satır toplamlarını yeni bir diziye aktaran örnekte geçici değişkenin her satır başında sıfırlanması, sonucun satır numarasıyla aynı indisteki göze yazılması, bağımsız döngülerde indis değişkeninin yeniden kullanılabilmesi ve matrisin koordinat sisteminden farkı konuşuldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
