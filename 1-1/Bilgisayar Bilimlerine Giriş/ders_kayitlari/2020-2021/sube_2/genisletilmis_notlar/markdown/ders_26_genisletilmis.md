# Ders 26 Genişletilmiş Notu: Akış Hataları, Karakter Dizilerinde Arama ve C'de String

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Akış diyagramlarında sık görülen hatalar
- 2. Kümelerde kesişim ve döngü seçimi
- 3. Sonsuz döngü ve kullanıcıdan sürekli girdi alma
- 4. Akış diyagramının neden öğretildiği
- 5. Matris okuma ve karakterlerden oluşan matrisler
- 6. Karakter matrisinde bir karakterin bütün konumlarını bulma
- 7. Kelime içinde bir harfin geçip geçmediğini bulma
- 8. C'de string ve null karakteri
- 9. string.h fonksiyonları
- 10. Tek karakter, karakter karakter ve string okuma
- 11. Sayıyı ikilik tabanda yazdırma: bit işlemleri
- 12. Matrise sütun eklemek mi, ayrı dizi mi?
- 13. Algoritmanın verimliliği

## 1. Akış diyagramlarında sık görülen hatalar

Dersin ilk yarısında hoca, öğrencilerin akış diyagramlarında sık gördüğü mantık ve gösterim hatalarını tek tek ele aldı. Bu hataların ortak noktası iki tanedir: derste anlatılan gösterimin dışına çıkmak ve değişkenlerin nasıl davrandığını yanlış kurmak.

### 1.1 İki sıralı diziyi birleştirmede indisler

İki sıralı dizi üçüncü bir dizide birleştirilirken her adımda iki dizinin o anki elemanları karşılaştırılır ve küçük olan üçüncü diziye taşınır. Örneğin `A(I) < B(J)` ise `A(I)` C'nin sıradaki gözüne konur. Bundan sonra A'nın bir sonraki elemanına bakılacağı için `I = I + 1` yapılır.

B'nin indisi `J` için hiçbir şey yazmaya gerek yoktur. Bazı öğrenciler, bir şey yazılmazsa indisin "yuvadan uçacağını" ya da değerinin değişeceğini düşünüp `J = J` gibi atamalar yazmıştı. Değişken, ona yeni bir değer atanmadıkça değerini korur. `J = J` yazmak gereksizdir.

Aynı türden bir indis manipülasyonu iki kümenin kesişimini bulma sorusunda da gerekir.

### 1.2 İki dizinin adı farklı olmalıdır

İki diziyle çalışılan sorularda (sıralı iki diziyi birleştirme, kesişim kümesi) dizilerin adları birbirinden farklı olmalıdır. A ve B, X ve Y, A ve Z olabilir; önemli olan aynı olmamalarıdır. Hem N elemanlı bir A dizisi hem de M elemanlı bir A dizisi aynı anda okunamaz. İkisi de A olur ve sonra hangisine başvurulduğu ayırt edilemez.

### 1.3 En büyük ikinci elemanı bulmada gereksiz işlemler

En büyük ikinci elemanı bulma sorusunda bazı öğrenciler önce A'nın en büyük elemanını bulmuş, döngüden çıkmış, sonra A ile aynı uzunlukta bir B dizisi oluşturup A'nın bütün elemanlarından en büyük değeri çıkararak B'ye atamaya çalışmıştı. Bu, akışta tek bir kutuda `B(N) = A(N) - max` gibi yazılmıştı.

Hoca iki sorun gösterdi. Birincisi, böyle bir işlem yapılacak olsa bile tek satırda yapılamaz; bir döngü açılıp elemanlar tek tek işlenmelidir. İkincisi, mantık olarak böyle bir ara diziye hiç gerek yoktur; tamamen zaman kaybıdır.

### 1.4 Verilen diziyi değiştirmemek

Birçok öğrenci soruları çözerken kendisine verilen diziyi değiştirme, bozma eğilimindeydi. Çoğu zaman size verilen bilgi üzerinde oynayabileceğiniz bir bilgi değildir. Sıralama gibi diziyi yerinde düzenlemeyi gerektiren bir iş istenmedikçe dizinin elemanları değiştirilmez. Arama yaparken bakılan eleman "bu değil" diye silinmez, değerine sıfır ya da başka bir şey atanmaz, yeri değiştirilmez.

### 1.5 Şekillerin kullanımı

Hoca, slaytlarda açıkça gösterilen kurallara uyulmadığını söyledi:

- Input (giriş) şekline yukarıdan girilir, aşağıdan çıkılır. Yandan girip öbür yandan çıkan ya da yandan ve alttan girip diğer yandan çıkan bağlantılar yanlıştır.
- Yamuk yerine eşkenar dörtgen gibi derste kullanılmayan şekiller çizilmemelidir.
- Karar ve döngü şekillerinin çıkışlarında `T` ve `F` etiketi unutulmamalıdır. "Evet/hayır", "doğru/yanlış" gibi kendi gösterimini kurmak kabul edilmez.

Hoca ayrıca, `if` ve `while` yapılarında bütünlüğü olmayan akışlar gördüğünü anlattı. Tahtada bir örnek canlandırdı: `START` ile başlayan, bir giriş kutusu ve bir karar şekli içeren, karar şeklinin `T` çıkışı doğrudan `STOP`'a giden, `F` çıkışı ise belirsiz biçimde aşağı devam eden bir akış (ekrandan, 00:45:00). Böyle bir yapıda tutarlı bir sistematik yoktur.

### 1.6 Döngü çıkışları ve bağlantı yuvarlakları

Kesişim örneğini çizerken hoca, bir `for` döngüsünün çıkışını "uzay boşluğuna gönderen" çok sayıda öğrenci gördüğünü söyledi. Döngünün çıkışı akışın devamına bağlanmalıdır; boşta bırakılan çıkış akışı anlamsız kılar.

Tahtada çok sayıda bağlantı yuvarlağı (connector) kullandığını da belirtti ve bunun okunabilirliği bozduğunu, kendisinin yalnız elektronik ortamda yer sıkıştığı için başvurduğunu söyledi. Kâğıtlarda gördüğü bir örneği canlandırdı: akış bir yerden 1 numaralı bağlantıya gidiyor, başka yerde 2 ve 3 başlıyor, 4 başka bir parçaya bağlanıyor ve sonunda `STOP`. Hocanın benzetmesiyle bu, büyük resmi oluşturup sonra puzzle parçalarına bölmek ve "hadi hocam birleştir" demektir. Böyle akış olmaz.

## 2. Kümelerde kesişim ve döngü seçimi

Hoca kesişim sorusunu bir örnekle canlandırdı (ekrandan, 01:00:00):

$$A = \{3, 5, 7, 8, 11\}, \qquad B = \{3, 4, 8, 41\}$$

Soru şuydu: A'dan 3'ü aldınız; B'nin bütün elemanlarına bakacak mısınız? Bir öğrencinin "hayır" cevabını hoca doğru buldu. Elemanlar her zaman sayı olmayabilir, bu yüzden "büyük olan sayıya kadar bak" gibi bir yaklaşım genel değildir. Asıl olan, bir eşleşme bulunmadığı sürece bakmaya devam etmektir. Hoca örnekte elemanları kolaylık olsun diye sıralı yazdı; küme olduğu için sıralı olmak zorunda değildir.

Tahtadaki çizimde dış döngü `I ← 1, N` (A'nın elemanları), iç döngü `J ← 1, M` (B'nin elemanları) ve içte bir `T`/`F` karar şekli vardı; döngüler 1 ve 2 numaralı bağlantılarla kapatılmıştı (ekrandan, 01:00:00).

Değerlendirme: A'yı seçtiyseniz A'nın bütün elemanlarını B'dekilerle karşılaştıracağınız için dıştaki döngünün `for` olması uygundur. Ama içteki döngü bütün B'yi gezen bir `for` olmamalıdır. Eşitlik bulunana kadar ya da eşitlik olmadığı sürece dönen koşullu bir döngü kurulmalıdır. Hocaya göre bu mantığın akla gelmesi beklenir.

Bu örnekte kesişim $\{3, 8\}$'dir (python ile kontrol edildi).

## 3. Sonsuz döngü ve kullanıcıdan sürekli girdi alma

Bir öğrenci, sudoku yazmaya çalıştığını ve kullanıcıdan aldığı her sayıyı bir `for` döngüsünde okumak zorunda olup olmadığını sordu. Hoca önce amacı netleştirdi: öğrenci sudokuyu kendi kendine çözen bir program değil, birinin elektronik ortamda sudoku oynamasını sağlayan bir program yazıyordu. Program bazı hücreleri hazır gösterecek, gerisini kullanıcı girecek, kurala uymayan girişte tekrar sayı isteyecekti.

**Soru:** Kullanıcıdan aldığım her sayıyı `for` döngüsünde okumak zorunda mıyım?
**Cevap:** Bu sistemde her seferinde bir bilgi almak işin doğasıdır. Bunun için daha önce `while` ve `for` konuşulurken anlatılan sonsuz döngü kullanılır. Örneğin bir sunucu programı elektrik kesilene, sistem çökene ya da yönetici servisi durdurana kadar çalışır. C'de bu `while(1)` ile ya da üç ifadesi de boş bırakılmış `for(;;)` ile yazılır. Sudoku programı da benzer biçimde, ama "daha insaflı" bir koşulla dönmelidir: oyun bitene (her yer dolana) ya da kullanıcı çıkmak isteyene kadar.

Hoca bunu akışta şöyle çizdi (ekrandan, 00:45:00):

```text
+--> [ DONE ≠ 1 AND EXIT ≠ 1 ]  (döngü şekli)
|          |
|       [ INPUT ]           girdi okunur
|          |
|      harf mi, sayı mı?
|        - 'q' ya da 'e' ise: EXIT = 1, döngünün başına dön
|        - sayı ise: koordinatlar okunur, sayı yerleştirilir
|          |
+----------+
```

Hoca bunun yalnız genel görünümü verdiğini, arada başka kontroller de olacağını belirtti. Fikir şudur: bir döngü içinde oku, işle, gerekiyorsa daha fazlasını oku; çıkılacaksa ilgili işlemi yapıp hemen döngünün başına dön.

**Ek açıklama (derste sonra geldi):** Hoca karakter karşılaştırmasını anlatırken bu örneğe döndü. Dışarıdan bir `Z` değişkenine karakter okunur. `Z = 'q'` ise `EXIT = 1` yapılır. Döngünün başına dönüldüğünde `EXIT` 1 olduğu için döngüden çıkılır ve iş biter.

## 4. Akış diyagramının neden öğretildiği

Bir öğrenci, test biçimindeki bir sınavda akışın nasıl sorulabileceğini merak etti. Hoca bu vesileyle akış diyagramının neden öğretildiğini açıkladı.

Akış diyagramı belli bir düşünme yeteneği ve sistematiği kazandırmak için öğretilir. Bu sistematiğe sahip olmadan da birçok şey yapılabilir, ama yapılan iş "yarım yamalak" olur. Hocaya göre iyi ya da başarılı bir mühendisi belirleyen şey bildiği teknoloji değil, bu sistematik düşünce yapısına hâkim olmaktır. Birinci sınıfta öğrencilere o anki popüler teknolojiler öğretilebilirdi; ama o teknoloji, dil ya da cihaz ortadan kalktığında geriye bir şey kalmaz. Belgesi olmayan, çok niş bir sorunla karşılaşıldığında da insanı kurtaracak olan bu düşünme biçimidir.

> **Hocanın vurgusu:** Akış mantığına vâkıf olmadan iyi bir mühendis olunmaz. Çalışırken olaylara bu açıdan bakın.

## 5. Matris okuma ve karakterlerden oluşan matrisler

Dersin ikinci yarısında konu sayılardan karakterlere geçti. Şimdiye kadar matrisler üzerinde hep sayılarla işlem yapılmıştı; bu sefer karakterler üzerinde işlem yapılacaktı.

### 5.1 Matris nasıl okunur

Matris okunurken önce boyutları (N, M), sonra iç içe iki döngüyle elemanları okunur: `I ← 1, N` dış döngüsü, `J ← 1, M` iç döngüsü ve içte `A(I)(J)` okuma kutusu. Hoca bunun kısaltması olarak daha önce tek bir giriş kutusunda `N, M, A(N)(M)` yazılabileceğini söylediğini hatırlattı (ekrandan, 01:15:00).

Bu kısaltmanın sınırlarını da netleştirdi:

- Bu kısaltma yalnız okuma içindir. Çıktı alırken bütün matrisi tek kutuda böyle yazdırabileceğinizi söylemedi.
- `A(N)(M)`'nin `N` ve `M`'den önce yazılabileceğini de söylemedi; bu yanlıştır.

### 5.2 Matrisin elemanları karakter olabilir

Matris sayılardan oluşabileceği gibi karakterlerden de oluşabilir. Hoca ilk derslerdeki encoding konusunu hatırlattı: karakterler, onluk sayılar ve kayan noktalı sayılar bellekte 0 ve 1'lerden oluşan ikilik sayılarla tutulur. Bu yüzden işlem yapılan şey yalnız sayılarla sınırlı değildir.

Tahtada iki 4×5'lik matris örneği vardı: biri `3, 5, 7, 9, 17, 41, 23` gibi sayılarla, diğeri `'A'`, `'B'`, `'Y'`, `'Z'`, `'X'`, `'K'` gibi karakterlerle doldurulmuştu (ekrandan, 01:20:00).

### 5.3 Çıktıda değişken ve metin

Hoca akıştaki çıktı gösterimini de hatırlattı (ekrandan, 01:20:00):

- Ekrana bir değişkenin değeri yazılacaksa değişkenin adı tırnaksız yazılır: `X` ya da `X, N`.
- Ekrana bir metin mesajı yazılacaksa metin tırnak içine alınır: `'Merhaba'`.

Bu kurala uyan öğrenciler çoğunluktaydı, ama uymayanlar da vardı.

## 6. Karakter matrisinde bir karakterin bütün konumlarını bulma

### 6.1 Problem ve akış

Problem: Okunan karakter matrisinde `X` karakterinin (İngiliz alfabesindeki X harfi) geçtiği bütün yerleri bulmak. Yapılacak iş sayısal matristekinin aynısıdır: bütün matris taranır, `X`'e eşit olan göz varsa satır ve sütun numarası ekrana yazdırılır ya da ayrı bir diziye alınır.

Hocanın tahtaya çizdiği akış (ekrandan, 01:20:00 ve 01:25:00):

```text
START
  |
[ N, M, A(N)(M) ]           (giriş)
  |
[ K = 1 ]                   (sonradan eklendi)
  |
I ← 1, N  (adım 1)
  |
  J ← 1, M  (adım 1)
    |
    < A(I)(J) = 'X' >
      T: B(1)(K) = I
         B(2)(K) = J
         K = K + 1
      F: (bir şey yapma)
    |
  (J döngüsü sonu)
  |
(I döngüsü sonu)
```

Sonuçlar iki satırlı bir B matrisinde tutulur: birinci satır bulunan konumların satır numaralarını (`I`), ikinci satır sütun numaralarını (`J`) içerir. B'nin her sütunu bir eşleşmedir.

### 6.2 Bulunan hata: K ilklendirilmemiş

Hoca ilk çizimde kasıtlı ya da kasıtsız bir hata bulunduğunu söyleyip öğrencilere sordu. Öğrencilerin bulduğu hata şuydu: `K` değişkenine ilk değer verilmemişti. Döngüler başlamadan önce `K = 1` olarak ilklendirilmelidir. Ayrıca her eşleşmeden sonra `K = K + 1` yapılmalıdır.

**Soru:** Neden `while` ile çizmedik? `X`'i bulunca hemen çıksın.
**Cevap:** Soru ilk `X`'i bulmak değil, geçen bütün `X`'leri bulmaktır.

**Soru:** O zaman dizinin sonuna kadar gidip her `X`'te bir çıkış yapamaz mıyız; tek tek taramak yerine yalnız `X` olanları çıkarsak?
**Cevap:** Hangi elemanların `X` olduğunu anlamak için hepsine tek tek bakmak zorundasınız. Birden fazla `X` aranıyorsa yapılabilecek başka bir şey yoktur.

### 6.3 K neyi gösterir ve neden K - 1

`K` bir'den başladığına göre her an neyi gösterir? Bir sonraki boş gözü. İlk eşleşmede `B(1)(1)` ve `B(2)(1)` doldurulur ve `K` 2 olur. Bu anda B'nin ikinci gözü henüz dolu değildir. Yani `K` her zaman bir ileride durur.

Bu yüzden B'deki sonuçları yazdıracak döngünün üst sınırı `K` değil, `K - 1` olmalıdır. Hoca, aynı hatayı birçok öğrencinin daha önce de yaptığını hatırlattı.

### 6.4 Karakter sabiti ve karakter değişkeni

Sayılar ya da karakterler üzerinde işlem yapmak arasında büyük bir fark yoktur. Tek fark şudur:

- Gerçekten belirli bir karakteri kontrol ediyorsanız, onun karakter olduğunu belirtmek için etrafına apostrof (tırnak) konur: `A(I)(J) = 'X'`.
- Karakter değeri taşıyan bir değişkenle karşılaştırma yapıyorsanız tırnak gerekmez. Örneğin aranan karakter dışarıdan `Z` adlı bir değişkene okunduysa koşul `A(I)(J) = Z` olur.

**Soru:** `Z`'yi harf olarak okuyabilir miyiz? O zaman tırnağa gerek olmuyor, değil mi?
**Cevap:** `Z`'yi kullanıp onun üzerinden devam edecekseniz tırnak gerekmez. Dışarıdan bir karakter okunur ve bir değişkende tutulur; çalışma anında bu `a` da olabilir, `@` da, `!` da (ekrandan, 01:35:00). Ne olduğu önemli değildir; karşılaştırma değişkenle yapılır. Sudoku örneğinde beklenen `q` ya da `e` tuşuydu: `Z = 'q'` ise `EXIT = 1` yapılır (bkz. Bölüm 3).

## 7. Kelime içinde bir harfin geçip geçmediğini bulma

### 7.1 Kelime bir karakter dizisidir

Dışarıdan okunan karakterler her zaman tek karakter olmak zorunda değildir: kelime, cümle, paragraf ya da büyük bir metin de okunabilir. Hoca "kelime" sözcüğünü ve "Bugün hava çok güzel" cümlesini yazdı. Bu yapılar aslında her zaman okunan dizilere benzer: `k, e, l, i, m, e`. Cümledeki boşluklar da birer karakterdir: klavyede space'e basınca girilen karakter.

Yani `N, A(N)` biçiminde okunan bir dizi `1, 3, 9, 47, 62, 17` gibi sayılar içerebileceği gibi `'a'`, `'l'`, `'i'` gibi karakterler de içerebilir (ekrandan, 01:45:00). Bunlar üzerinde arama yapılırken aynı yapı kullanılır.

### 7.2 Bir öğrencinin önerisi ve sorunun asıl isteği

Soru: Verilen bir kelime içinde istenen harfin geçip geçmediğini bulan algoritmanın akışını çizin.

Bir öğrenci şu çözümü önerdi: bir kontrol değişkenine sıfır atanır, `for` döngüsüyle dizinin elemanları gezilir, `X`'e eşit eleman görülünce kontrol değişkeni artırılır; sonunda kontrol sıfırdan farklıysa harf geçiyor, değilse geçmiyor denir.

Hoca, öğrencinin konuşurken bir terslik sezdiğini fark etti ve sorunun ne istediğine dikkat çekti: harfin kaç kere geçtiği ya da nerelerde geçtiği sorulmuyor, yalnız geçip geçmediği soruluyor. Dolayısıyla bir yerde geçiyor olması yeterlidir. Öğrenci bunun üzerine `if`'in içinde, doğru durumda doğrudan çıktı verilebileceğini söyledi. Hoca bunun da hâlâ yanlış yer olduğunu, çünkü burada `for` döngüsünün hiç kullanılmayacağını söyledi.

### 7.3 Doğru akış

Hocanın çizdiği akış (ekrandan, 01:45:00):

```text
START
  |
[ N, A(N), X ]              (giriş)
  |
[ I = 1 ]                   (sonradan eklendi)
  |
+-> < A(I) ≠ X AND I <= N >   (döngü şekli)
|       |
|   [ I = I + 1 ]
|       |
+-------+
  |
(döngüden çıkış)
  |
< I > N >
  T: harf YOK
  F: harf VAR
```

İlk çizimde `I = 1` ilklendirmesi eksikti; hoca bunu hata olarak gösterip ekledi. Döngüden çıkınca `I > N` kontrol edilir.

**Soru:** `I`, `N`'den büyükse ne demektir?
**Cevap:** Bir öğrenci önce harfin kelimede var olduğu anlamına geldiğini söyledi, sonra düzeltti: `I > N` ise harf yoktur, çünkü kelimenin bütün harfleri tek tek kontrol edilmiş ve hiçbiri eşleşmemiştir. Hoca bu düzeltmeyi onayladı.

Hoca bu akışı kısaltarak ve "odun programcı kafasıyla" basit yazdığını, daha ayrıntılı ve düzgün yazılmasının daha hoş olacağını, ama olayın bundan ibaret olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu akış C'ye aktarılırken koşulların sırası önemlidir. `I = N + 1` olduğunda `A(I)` dizinin dışında kalır. C'de `&&` soldan sağa ve kısa devreyle değerlendirildiği için koşul `i <= n && a[i] != x` sırasıyla yazılırsa dizinin dışındaki eleman hiç okunmaz.

### 7.4 Analiz: "Terminator" ve `t`

Hoca akışın doğruluğunu analizle gösterdi. Analiz, değişkenlerin değerlerini ve kontrollerin durumunu sistematik biçimde yazmaktır.

Verilen: kelime "Terminator", $N = 10$, aranan $X = $ `t` (küçük harf). Başlangıçta $I = 1$ (ekrandan, 01:50:00 ve 01:55:00).

| I | A(I) ≠ X | I <= N | Sonuç |
|---|----------|--------|-------|
| 1 | T ≠ t (doğru) | 1 <= 10 (doğru) | döngüde kal, I = 2 |
| 2 | e ≠ t (doğru) | 2 <= 10 (doğru) | I = 3 |
| 3 | r ≠ t (doğru) | 3 <= 10 (doğru) | I = 4 |
| 4 | m ≠ t (doğru) | 4 <= 10 (doğru) | I = 5 |
| 5 | i ≠ t (doğru) | 5 <= 10 (doğru) | I = 6 |
| 6 | n ≠ t (doğru) | 6 <= 10 (doğru) | I = 7 |
| 7 | a ≠ t (doğru) | 7 <= 10 (doğru) | I = 8 |
| 8 | t ≠ t (yanlış) | 8 <= 10 (doğru) | döngüden çık |

Koşul AND ile bağlı olduğu için ikisinden biri yanlış olunca döngüden çıkılır. Çıkıştaki $I = 8$ için $8 > 10$ yanlıştır, akış `F` dalına gider ve sonuç 'VAR' olur (ekrandan, 01:55:00). Python ile aynı döngü çalıştırıldığında da $I = 8$ ve sonuç VAR çıktı.

**Büyük ve küçük harf:** İlk adımda `T ≠ t` doğru mudur sorusuna öğrenciler doğru cevabını verdi. Büyük `T` ile küçük `t` ikimiz için de "t" harfidir, ama encoding'de farklı sayılarla ifade edilir. Birçok programlama dili büyük-küçük harfe duyarlı (case sensitive) olduğu için ikisi eşit değildir.

### 7.5 Analizde sık yapılan hatalar

Hoca analizlerde sık gördüğü hataları da anlattı:

- Bazı öğrenciler analiz tablosunda `I` sütunu yerine `N` yazmış ve her satıra 10, 10, 10 diye değişmeyen değeri tekrar etmişti. Değişmeyen bir şeyi her adımda yazmanın anlamı yoktur.
- Neyin, ne zaman, neyin sonucuna bağlı olarak değiştiği takip edilmelidir: değişkenler, kontroller ve kontrollerden sonra değişkenlerin aldığı değerler.
- Bazı öğrenciler analiz alanını doldurmak için rastgele değerler yazmış ve akışlarındaki hatayı analizde görememişti. Bu, "zaten böyle olacak" diye kendini şartlandırmaktan kaynaklanır.

> **Hocanın vurgusu:** Düzgün analiz yapabilmek bu işin ciddi parçalarından biridir. Böyle göstermelik analizlerin kimseye faydası yoktur.

## 8. C'de string ve null karakteri

### 8.1 Sayı dizisi ile karakter dizisi

C'de 10 elemanlı bir sayı dizisi (tahtadaki örnek: `3, 5, 8, 77, 41, 61, 52, 77, 16, 23`) okunurken önce 10 değeri okunur, sonra dizinin gözleri tek tek okunur (ekrandan, 02:00:00). Karakter dizileri için ise programlama dilleri genelde farklı bir yapı sunar: **string**. String'in gerçekleştirimi ve ele alınışı dilden dile değişir.

### 8.2 C'de string okuma

C'de string okumak için `scanf`'te `%d` yerine `%s` kullanılır. `%d` onluk bir sayı, `%s` bir string okunacağını söyler. Ardından string'in okunacağı dizinin adı verilir (ekrandan, 02:00:00):

```c
char word[100];
scanf("%s", word);
```

`word` karakter tipinde olmalı ve bir boyutu olmalıdır. Boyut, dizilerde olduğu gibi, sorun çıkmasın diye mümkün olduğunca büyük seçilir.

### 8.3 Null karakteri

Dışarıdan "ali" girildiğini düşünelim. Bu kelime üç karakterden oluşur, ama C'deki gerçekleştirim gereği dört göz kaplar (ekrandan, 02:00:00):

```text
word[0] = 'a'
word[1] = 'l'
word[2] = 'i'
word[3] = '\0'   (null)
```

C'de bir karakter dizisinin string olarak, bütün halinde işlenebilmesi için sonunda bir null karakteri bulunmalıdır. Null karakteri "mutlak sıfır"dır: sayısal değeri sıfır olan karakter. Encoding'de her karakterin bir sayısal karşılığı vardır; örneğin `@` işaretinin karşılığı 64'tür. `'0'` diye karakter olarak yazılan sıfırın encoding'deki karşılığı başka bir sayıdır. Tek başına sayı olarak yazılan sıfır ise gerçekten sıfırdır; buna null denir.

> **Ek bilgi (derste anlatılmadı):** ASCII tablosunda `'0'` karakterinin sayısal değeri 48'dir. Null karakteri C'de `'\0'` diye yazılır ve değeri 0'dır.

`scanf`, `%s` ile okuma yaptığında girilen karakterlerin ardından otomatik olarak sona bir null ekler. Örneğin girilen bir ad beş harfliyse beş göz harflerle dolar ve altıncı göze sıfır yazılır.

### 8.4 String'i yazdırmak ve null-terminated kavramı

Okunan ya da oluşturulan bir string `printf`'in `%s` biçim belirleyicisiyle yazdırılır (ekrandan, 02:05:00):

```c
printf("%s", word);
```

`printf` null karakterini görene kadar yazdırır. C'deki bütün kopyalama ve string işleme işlemleri bu sonlandırıcıya dayanır. Benzer şekilde, 100 karakterlik bir dizinin içine bir mesaj yazıp sonuna null konursa null'a kadar olan kısım bir bütün string gibi ele alınır.

Dizide hiçbir yerde sıfır yoksa (string null-terminated değilse) ekrana ne çıkacağı belli değildir: anlamsız karakterler yazılabilir, hiçbir şey yazılmayabilir, ortalık birbirine girebilir. Bu yüzden C'de string kavramı her zaman **null-terminated** olarak anılır. Hoca bu noktanın kafa karıştırabileceğini, üzerinde pratik yapmak gerektiğini söyledi.

## 9. string.h fonksiyonları

C, stringler üzerinde işlem yapmak için `string.h` kütüphanesini sağlar. Giriş-çıkış fonksiyonları için `#include <stdio.h>` yazıldığı gibi, string fonksiyonları için `#include <string.h>` yazılır (ekrandan, 02:05:00).

### 9.1 strlen

`x = strlen(word);` string'in kaç karakterden oluştuğunu `x`'e atar. Hoca bunun aslında ne yaptığını C koduyla gösterdi (ekrandan, 02:05:00):

```c
i = 0;
while (word[i])
    i++;
```

"ali" için izleme:

- `word[0]` = `'a'`, sıfırdan farklı, koşul doğru, `i` = 1.
- `word[1]` = `'l'`, sıfırdan farklı, `i` = 2.
- `word[2]` = `'i'`, sıfırdan farklı, `i` = 3.
- `word[3]` = null, koşul yanlış, döngüden çıkılır. Sonuç `i = 3`.

Yani `strlen` null karakterini görüp görmediğini kontrol ede ede ilerler ve gördüğünde durur. C'de string okurken akıştaki gibi "önce boyut, sonra elemanlar" okunmaz; string doğrudan okunur, uzunluk gerekiyorsa sonradan bulunur.

Bu döngü ve `strlen` küçük bir C programında `gcc -Wall` ile derlenip "ali" girdisiyle denendi; ikisi de 3 verdi.

### 9.2 strcpy, strtok ve güvenlik

- `strcpy`: bir stringi başka bir stringe kopyalar.
- `strtok`: bir stringi tokenlarına, yani parçalara ayırır.

Hoca, ileriki yıllarda alınacak güvenlik dersine değinerek `strcpy`'nin kontrolsüz bir kopyalama fonksiyonu olduğunu ve bu yüzden güvenli olmadığını söyledi. Bunun üzerinden buffer overflow saldırıları yapılabilir. Yerine `strncpy` kullanılmalıdır: bu fonksiyona en fazla kaç karakter kopyalanacağı da verilir (örneğin 16). Null karakteri görülmese bile o sayıya ulaşınca kopyalama durur.

Saldırının mantığı şudur: bir değişkenin üzerine, olması gerekenden uzun bir şey yazılır, böylece bellekte yanındaki bazı değerlerin üzerine yazılır ve fonksiyondan dönülürken yetki alanının dışındaki bir yere erişilmeye çalışılır.

> **Ders sonrası not:** Hoca, `man strcpy` sayfasında bu fonksiyonun deprecated (kullanımdan kaldırılmış) olarak geçtiğini söyledi. C standardında `strcpy` büyük olasılıkla resmi olarak kaldırılmış değildir; man sayfası daha çok taşma riskine karşı uyarır. Ayrıca `strncpy` sınıra ulaştığında hedefin sonuna null koymaz, bu yüzden onu kullanırken de sonlandırıcıyı ayrıca kontrol etmek gerekir.

Hoca dönemin son dersi olduğu için ayrıntıya girmedi; stringlerin yapısal programlama derslerinde daha ayrıntılı işleneceğini söyledi.

## 10. Tek karakter, karakter karakter ve string okuma

Bir öğrenci harf okumayla ilgili bir soru sorunca hoca farkı örnekle toparladı. Tanım (ekrandan, 02:15:00):

```c
char x, word[10];
```

`x` tek bir karakter tutar, `word` on karakter tutar. Bir tamsayı dizisi olsaydı da biri tek, diğeri on tamsayı tutardı. Üç farklı okuma biçimi gösterildi (ekrandan, 02:15:00):

```c
/* 1) tek karakter */
printf("stroke a key\n");
scanf("%c", &x);

/* 2) on bağımsız karakter, tek tek */
for (i = 0; i < 10; i++) {
    printf(" ... ");
    scanf("%c", &word[i]);
}

/* 3) tek seferde bir kelime */
printf("enter a word");
scanf("%s", word);
```

Farklar:

- Birincisinde yalnız `x` değişkenine `'a'`, `'b'` ya da `'c'` gibi bir değer atanır.
- İkincisinde `word`'ün her gözüne, son göz dahil, birer karakter atanır. Burada string okunacağı söylenmediği için sona null eklenmez.
- Üçüncüsünde örneğin "kelime" girilirse harfler yazılır ve sonuna sıfır konur. `%s` bir string okunacağını söyler; C'de string null-terminated olduğu için girilen her şeyin sonuna bir null eklenmeye çalışılır.

### 10.1 Ayrılan alandan uzun girdi

Hoca "eklenmeye çalışılır" ifadesini bilerek kullandığını söyledi. `word` için 10 göz ayrıldığını ve kullanıcının "Çekoslovakya" girdiğini düşünün. Bu kelime 12 harftir. İlk on harf `word[0]`'dan `word[9]`'a kadar yazılır, sonrası dizinin dışına, hocanın deyişiyle "uzay boşluğuna" gider. Null karakterine de yer kalmaz. Bu string sonra `%s` ile yazdırılmak istenirse her şey bozulur (ekrandan, 02:15:00).

> **Hocanın vurgusu:** Ayrılan alandan büyük bir girdi gelirse program kontrolünüzün dışına çıkar; buna dikkat edin.

### 10.2 Akışta kelime, C'de string

**Soru:** C'de kelimenin harf sayısını ayrıca okuyacak mıyız?
**Cevap:** Hayır. Akışta kelime `N` ve `WORD(N)` biçiminde gösterilip öyle okunur. C'ye aktarırken ise kelime doğrudan string olarak okunur ve onun üzerinden devam edilir. Akış evrenseldir; oradaki kararları, yapıyı ve düzeni ilgili programlama diline aktarmak programcının sorumluluğundadır.

Hoca bu noktada akışlarda C sözdizimi kullanılmasının yanlış olduğunu bir kez daha hatırlattı.

### 10.3 scanf'te neden & yok

**Soru:** String okurken `word`'ün yanına `&` işareti neden yazılmadı?
**Cevap:** `word` bir karakter dizisidir; `char word[10];` ile on elemanlı olarak tanımlanır. C standardına göre dizi adı tek başına kullanıldığında zaten bir adres gösterir: dizinin sıfırıncı elemanının başlangıç adresi. Bu yüzden `&word[0]` yazmakla `word` yazmak arasında fark yoktur. `%s` verildiğinde null-terminated bir karakter dizisi okunacağı söylenir; yanına dizinin başlangıç adresi verilir ve terminalden yazılanlar o adresten başlayarak, sondaki null'a kadar tek tek kopyalanır. Tamsayı dizisi okunurken ise elemanlar `%d` ile tek tek okunur.

> **Ek bilgi (derste anlatılmadı):** Teknik olarak dizi adı bir pointer değişkeni değildir; çoğu ifadede ilk elemanın adresine dönüşür (array-to-pointer conversion). `sizeof(word)` gibi istisnalarda dizinin tamamını temsil eder. Derste anlatılan kullanım için iki görüş aynı sonucu verir.

## 11. Sayıyı ikilik tabanda yazdırma: bit işlemleri

Bir öğrenci, onluk sayıyı ikilik tabana ve ikilik sayıyı onluk tabana çeviren programını ekranda paylaştı. Program 99 için `110 0011`, 65 için `100 0001`, `10101` ikilik girdisi için 21 çıktısını veriyordu (ekrandan, 02:20:00 ve 02:25:00). Hoca programın çalıştığını, ama yöntemin yanlış olduğunu söyledi.

### 11.1 Programdaki yaklaşım

- İkilikten onluğa kısımda ikilik sayı aslında bir tamsayı olarak (`%d` ile) okunuyor, sonra 10'a göre mod ve bölmeyle basamaklarına ayrılıp `pow(2, k)` ile toplanıyordu (ekrandan, 02:20:00). Hoca, burada ikilik bir sayı girilmediğini, bir tamsayının ikiliğe "yontulmaya" çalışıldığını söyledi.
- Onluktan ikiliğe kısımda sayı sıfırdan büyük olduğu sürece 2'ye göre modu alınıp bir diziye yazılıyor, sayı 2'ye bölünüyordu (ekrandan, 02:25:00).

Hocaya göre mod alma, bölme ve çarpmayla birlikte iş yükü açısından en pahalı aritmetik işlemdir. Bunun yerine operatörler konusunda görülen bit işlemleri (AND, OR, shift) kullanılmalıdır.

### 11.2 Onluktan ikiliğe: maske ve sola kaydırma

Örnek: 99. Sekiz bit olarak, en yüksek anlamlı bit 128'den başlayarak yazılırsa `0 1 1 0 0 0 1 1` olur.

Yöntem:

1. Değeri 1 olan bir maske oluşturulur: `00000001`. Bütün bitleri sıfır, yalnız en sondaki bit birdir.
2. Maske ile girilen sayı AND'lenir. Bu, sayının son bitini maskeler: sonuç sıfırdan farklıysa son bit 1, sıfırsa 0'dır.
3. Maske bir bit sola kaydırılır (artık 2'yi temsil eder) ve tekrar AND alınır.
4. İşlem bütün bitler için tekrarlanır.

99 için çıkan bitler sondan başa doğru: 1, 1, 0, 0, 0, 1, 1, 0. Hoca da "sondaki iki bit 1, sonra üç kez 0, sonra 1, 1" diye anlattı. Her çıkan bit ekrana yazılabilir. Bir diziye atamak, iş yalnız ekrana yazdırmaksa makul değildir.

Python ile kontrol: $99 = 64 + 32 + 2 + 1$, 8 bitlik yazımı `01100011`; maskeyle sondan başa okunan bitler `1, 1, 0, 0, 0, 1, 1, 0`. $65$'in ikilik yazımı `1000001`, `10101`'in onluk değeri 21.

Hoca ayrıca bu değişkenlerin `unsigned` tanımlanmasını beklediğini söyledi.

### 11.3 İkilikten onluğa: sola kaydırma ve OR

İkilik sayı dışarıdan alınacaksa iki yol var:

- Bir dizi tanımlanır, her gözü bir basamak gibi ele alınır ve basamak değerleriyle çarpılarak toplanır.
- Daha güzeli: tek bir değişken tutulur. Her yeni bit girildiğinde tutulan değer bir bit kaydırılır ve yeni bit OR işlemiyle ucuna eklenir. Hangi yöne kaydırılacağı bitlerin hangi sırayla (yüksek anlamlıdan düşüğe ya da tersi) girildiğine bağlıdır.

> **Ek bilgi (derste anlatılmadı):** Bitler en yüksek anlamlıdan başlayarak girildiğinde her adım `r = (r << 1) | bit` olur. `1100011` bitleri bu şekilde işlenince 99 elde edilir (python ile kontrol edildi).

Hoca bu örnekten genel bir sonuç çıkardı: bir program çalışıyor ve doğru sonuç üretiyor olabilir, ama bu işi yapmanın doğru yolu o olmayabilir.

## 12. Matrise sütun eklemek mi, ayrı dizi mi?

**Soru:** N×M bir matriste satırların toplamları yeni bir sütun oluşturacak ve aynı matrisin içinde tutulacak. Bu toplamları yazmak için eski matriste bir boşluk yaratmam gerekiyor mu?
**Cevap:** Matris zaten N×M'liktir ve bu istek onun boyutunun dışına, M+1'inci sütuna taşmak demektir. Bunun yerine toplamları ayrı, tek boyutlu bir dizide tutmak çok daha mantıklıdır.

Hoca bunu mühendislik açısından da açıkladı. Bazı programlama dillerinde tek satırlık bir komutla matrise sütun eklenebilir. Ama arka planda şu olur: eski matris kenarda tutulur, bir sütun fazlası olan yeni bir matris oluşturulur, eski matris yeniye kopyalanır. Programlama dili size daha soyut bir görünüm sunar; olayın doğası değişmez.

Dinamik bellek ayırma ile örnek: kullanıcı 1000 eleman istediyse işletim sisteminden 1000 tamsayılık yer alınır. Sonradan 10 eleman daha eklemek istenirse 1010'luk yeni bir yer açılır, 1000'lik kısım buraya kopyalanır, eski alan bırakılır. Bu sırada ihtiyaç 1010 iken bir süre $1000 + 1010 = 2010$ elemanlık yer kullanılmış olur.

Sık ekleme gereken büyük kayıtlar (örneğin bir bankanın bütün müşteri bilgileri) için dizi yerine **bağlı liste** (linked list) kullanılır. Araya, başa ya da sona bir eleman eklenirken bütün dizi yeniden ayrılmaz; yalnız yeni eleman için bellek ayrılır ve önündeki ile arkasındaki elemanın bağlantıları değiştirilir.

Hoca, bazı öğrencilerin akış çizimi kolay olsun diye tuhaf kestirmelere başvurduğunu da söyledi. Doğru yaklaşım, arka tarafta bilgisayar mimarisi açısından makul olan yöntemi seçip akışı ona göre çözmektir. Toplamlar dikey bir dizi gibi düşünülerek de tutulabilir. Sonra plan, hangi programlama dilinde yazılacaksa o dilin sunduğu imkânlara göre programlanır.

## 13. Algoritmanın verimliliği

**Soru:** Yazdığımız algoritmanın çalışıp çalışmadığını analizle kontrol ediyoruz; peki verimli (efektif) olup olmadığını nasıl anlarız?
**Cevap:** Üzerine başka açılardan düşünerek. Bu yetenek yavaş yavaş gelişir. Örneğin yapılan bir atamanın bilgisayarın çalışma biçimine uygun olup olmadığı sorgulanmalıdır. Hoca akışlarda gördüğü iki örneği verdi: kümelerdeki gibi `X ∈ A` biçiminde işlemler ve `A(I) = B(I) = X` gibi AND ile bağlanmamış zincir karşılaştırmalar. Bunlar bilgisayarın çalışma yapısına henüz yaklaşılmadığını gösterir. Şu an beklenen, bir soruna çözüm olarak kurulan algoritmayı akışa düzgün aktarabilmek ve C'de kodlayabilmektir. Bilgisayar mimarisi, işletim sistemi ve programlama dilleri bilgisi arttıkça daha verimli çözümler kendiliğinden bulunmaya başlar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:55:19; ekrandan, 01:00:00)

$A = \{3, 5, 7, 8, 11\}$ ve $B = \{3, 4, 8, 41\}$ kümelerinin kesişimini bulmak için nasıl bir yöntem kullanılmalıdır? A'dan 3'ü aldığınızda B'nin bütün elemanlarına bakacak mısınız?

> **Çözüm:** Hayır. A'nın her elemanı için dış döngü `for` olabilir. B'de ise eşleşme bulunmadığı sürece (ve B'nin sonuna gelinmediği sürece) dönen koşullu bir döngüyle arama yapılır. Eşleşme bulunursa eleman kesişime eklenir. Kesişim $\{3, 8\}$'dir.

**Soru 2** (ekrandan, 01:20:00 ve 01:25:00)

N×M boyutlu bir karakter matrisinde `X` karakterinin geçtiği bütün yerlerin satır ve sütun numaralarını iki satırlı bir B matrisine yazan akışı çizin. Tahtadaki ilk çizimde bir hata vardır; bulun.

> **Çözüm (derste verildi):** Matris `I ← 1, N` ve `J ← 1, M` döngüleriyle taranır. `A(I)(J) = 'X'` ise `B(1)(K) = I`, `B(2)(K) = J`, `K = K + 1`. Hata: `K` ilklendirilmemişti; döngülerden önce `K = 1` yazılmalıdır. Sonuçlar yazdırılırken döngü `K - 1`'e kadar gider, çünkü `K` bir sonraki boş gözü gösterir.

**Soru 3** (derste sözlü, 01:41:12; ekrandan, 01:45:00 ve 01:55:00)

Verilen bir kelime içinde istenen harfin geçip geçmediğini bulan algoritmanın akışını çizin. "Terminator" kelimesi ve `t` harfi için analiz edin.

> **Çözüm (derste verildi):** `I = 1`; `A(I) ≠ X AND I <= N` olduğu sürece `I = I + 1`. Döngüden çıkınca `I > N` ise harf YOK, değilse VAR. Analiz: $N = 10$; $I = 1$'de `T ≠ t` doğrudur (büyük ve küçük harf farklıdır). $I$ 8 olduğunda `t ≠ t` yanlış olur ve döngüden çıkılır. $8 > 10$ yanlış olduğu için sonuç VAR.

**Soru 4** (ekrandan, 02:15:00)

`char x, word[10];` tanımı için aşağıdaki üç okuma arasındaki fark nedir? `word` için 12 harfli bir kelime girilirse ne olur?

```c
scanf("%c", &x);
for (i = 0; i < 10; i++) scanf("%c", &word[i]);
scanf("%s", word);
```

> **Çözüm (derste verildi):** Birincisi yalnız tek bir karakter okur. İkincisi on gözün her birine bir karakter yazar ve sona null eklemez. Üçüncüsü bir kelimeyi string olarak okur ve sonuna null eklemeye çalışır. 12 harfli kelimede ilk on harf `word[0]`..`word[9]`'a yazılır, sonrası dizinin dışına taşar ve null'a yer kalmaz. `%s` ile yazdırma hatalı sonuç verir.

**Soru 5** (derste sözlü, 02:18:55; ekrandan, 02:25:00)

Girilen bir onluk sayının (örneğin 99) ikilik yazımı mod almadan nasıl ekrana basılır?

> **Çözüm (derste verildi):** Değeri 1 olan bir maske sayıyla AND'lenir; sonuç sıfırdan farklıysa o bit 1'dir. Maske her adımda bir bit sola kaydırılır. 99 için bitler sondan başa 1, 1, 0, 0, 0, 1, 1, 0 çıkar; 8 bitlik yazımı `01100011`'dir.

**Soru 6** (derste sözlü, 02:26:23)

N×M bir matrisin satır toplamları hesaplanacak. Toplamları matrisin içinde yeni bir sütuna mı yazmak gerekir?

> **Çözüm (derste verildi):** Hayır. Matrisin boyutunun dışına taşmak yerine toplamlar ayrı, tek boyutlu bir dizide tutulur. Boyut büyütmek arka planda yeni yer açma ve kopyalama demektir.

## Dersin Toparlaması

Dersin ilk yarısında akış diyagramlarında sık yapılan hatalar ele alındı: gereksiz indis atamaları, aynı adlı diziler, verilen diziyi değiştirmek, derste anlatılan şekillere ve `T`/`F` etiketlerine uymamak, döngü çıkışlarını boşta bırakmak ve parçalara bölünmüş akışlar. Kesişim örneğinde iç aramanın bütün diziyi gezen bir `for` değil, eşleşme yokken dönen koşullu bir döngü olması gerektiği gösterildi. Sudoku sorusu üzerinden de kullanıcıdan sürekli girdi alan sonsuz döngü yapısı kuruldu.

İkinci yarıda sayılardan karakterlere geçildi. Karakter matrisinde bir karakterin bütün konumları bulundu; bu örnekte sayaç ilklendirmesi ve `K - 1` sınırı vurgulandı. Kelime içinde harf aramada sorunun yalnız varlığı sorduğu, bu yüzden ilk eşleşmede duran bir döngünün yettiği "Terminator" analiziyle gösterildi. Ardından C'de stringlerin null-terminated yapısı, `scanf`/`printf` ile `%s` kullanımı, `strlen`'in iç mantığı, `strcpy`'nin güvenlik sorunu ve ayrılan alandan uzun girdinin yarattığı taşma anlatıldı. Son olarak ikilik dönüşümde mod yerine bit işlemlerinin, matrise sütun eklemek yerine ayrı dizinin ve sık eklemede bağlı listenin neden tercih edildiği konuşuldu. Hoca stringlerin ayrıntısının yapısal programlama derslerinde işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
