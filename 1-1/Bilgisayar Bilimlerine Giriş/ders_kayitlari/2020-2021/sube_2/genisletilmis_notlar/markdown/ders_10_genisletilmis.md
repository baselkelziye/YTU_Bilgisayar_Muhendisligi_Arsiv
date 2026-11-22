# Ders 10 Genişletilmiş Notu: Newton Yöntemiyle Karekök Akışı, While Döngüsü ve Dizilere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Newton Formülünün Hatırlatılması
- 2. Deterministik Döngü ile Koşula Bağlı Döngü
- 3. Karekök Akışının İlk Taslağı ve Hataları
- 4. Karekök Akışının Doğru Hali
- 5. Repeat Until, Goto, Continue ve Break Üzerine
- 6. Akış Diyagramının Sekiz Temel Şekli ve Çıktı Kutusu
- 7. Akışın Analizi ve Pratik
- 8. Bellekte Değişkenler ve Dizi Kavramı
- 9. Dizinin Ortalaması
- 10. Kısaltılmış Dizi Okuma Gösterimi
- 11. Diziyi Ters Çevirme Problemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Newton Formülünün Hatırlatılması

Ders, önceki haftalarda farklı problemler için akış diyagramı çizme çalışmasının devamıdır. Hoca, iki hafta kadar önce algoritmalar konuşulurken anlatılan **Newton formülünü** hatırlattı. Bu formül verilen bir sayının karekökünü adım adım yaklaşarak bulmak için kullanılır.

Karekökü aranan sayı $x$, bir önceki tahmin $old$ ve yeni tahmin $new$ olmak üzere:

$$new = \frac{old + \dfrac{x}{old}}{2}$$

Başlangıç (initial) değeri olarak $old = 1$ alınır. Her adımda bulunan yeni değer bir sonraki adımda eski değer olarak formüle konur.

### 1.1 1024 örneği

Hoca $x = 1024$ için ilk adımları tahtada hesapladı (ekrandan, 00:35:00):

- 1. adım: $old = 1$ için $new = (1 + 1024/1)/2 = 1025/2 = 512.5$.
- 2. adım: $old = 512.5$ için $new = \dfrac{512.5 + 1024/512.5}{2} = \dfrac{512.5 + 1.998}{2} = 257.249$.
- 3. adım: $old = 257.249$ ile aynı formül tekrar uygulanır.

Tahtadaki listede tahminler $512.5 \rightarrow 257.249 \rightarrow 130.xx \rightarrow 69.xx \rightarrow 42.xx \rightarrow 33.xx \rightarrow 32.xx \rightarrow 32.xx \rightarrow 32.xx$ diye ilerler ve $\sqrt{1024} = 32$ değerine yaklaşır (ekrandan, 00:20:00). Hoca ara değerleri yaklaşık söyledi; python ile kontrol edilen değerler şöyledir:

| Adım | old | new | $\lvert new - old\rvert$ |
|---|---|---|---|
| 1 | 1 | 512.5 | 511.5 |
| 2 | 512.5 | 257.249024 | 255.250976 |
| 3 | 257.249024 | 130.614802 | 126.634223 |
| 4 | 130.614802 | 69.227324 | 61.387478 |
| 5 | 69.227324 | 42.009586 | 27.217738 |
| 6 | 42.009586 | 33.192487 | 8.817098 |
| 7 | 33.192487 | 32.021421 | 1.171067 |
| 8 | 32.021421 | 32.000007 | 0.021414 |
| 9 | 32.000007 | 32.000000 | 0.000007 |

Her yinelemede ardışık iki tahmin arasındaki fark küçülür. Tahminler tam sayı değildir; 32'ye ulaşıldıktan sonra da ondalık kısım bir süre değişmeye devam eder.

> **Ek bilgi (derste anlatılmadı):** Bu formül, $f(t) = t^2 - x$ fonksiyonunun kökünü Newton-Raphson yöntemiyle aramanın özel halidir: $t_{k+1} = t_k - f(t_k)/f'(t_k) = (t_k + x/t_k)/2$. Aynı yöntem "Babil yöntemi" adıyla da bilinir.

## 2. Deterministik Döngü ile Koşula Bağlı Döngü

Hoca bu problemi önceki iki örnekle karşılaştırdı. **Ortalama** probleminde $N$ adet sayının ortalaması, **Fibonacci** probleminde $N$. Fibonacci sayısı aranıyordu. İkisinde de kaç adım yapılacağı baştan bellidir; bu yüzden bu işler deterministiktir ve adım sayısı belli olan `for` döngüsüyle kurulur.

Newton yönteminde ise durum farklıdır. Kaç adım sonra yeterince yaklaşılacağı baştan bilinmez. Her adımda bakılan şey, bir önceki tahminle aradaki farkın ne kadar küçüldüğüdür. Bu farka $\varepsilon$ denirse işlem, fark belirli bir $\varepsilon$ değerinin altına inene kadar sürdürülür. 512.5 ile 257.249 arasındaki yaklaşık 255'lik, 257 ile 130 arasındaki yaklaşık 127'lik, 130 ile 69 arasındaki yaklaşık 61'lik fark kabul edilebilir değildir. Kabul edilebilir bir değer örneğin $0.001$ olabilir.

- Yapılacak işin kaç adım olduğu biliniyorsa (örneğin her seferinde bin adımlık bir yineleme) `for` kullanılır.
- Tekrar bir koşulun sağlanmasına bağlıysa `while` kullanılır.

$\varepsilon$ elde edilecek sonucun **hassasiyetidir**. Hocanın tahtaya $0.001$ yazması hassasiyetin illa bu olması gerektiği anlamına gelmez; bu yüzden $\varepsilon$ da karekökü alınacak sayı gibi dışarıdan okunmalıdır.

**Soru (hocanın sorusu):** Karekök bulmak için dışarıdan neler okunmalı? **Cevap:** Önce karekökü bulunacak sayı. Hoca "kökünü almaya başlayacağımız nokta" gibi belirsiz tanımlar yerine "karekökü bulunacak sayı" gibi net ifade kullanılmasını istedi. İkinci girdi, yinelemeyi durduracak koşulu belirleyen $\varepsilon$'dur.

## 3. Karekök Akışının İlk Taslağı ve Hataları

Hoca öğrencilerin önerileriyle bir taslak akış çizdi (ekrandan, 00:30:00):

```text
START
  -> OKU: X, ε
  -> İŞLEM: old = 1
  -> WHILE abs(new - old) < ε
       doğru kolu: İŞLEM: new = (old + X/old)/2
                   (koşula geri dön)
  -> ÇIKTI: N, 'karekökü', new
  -> STOP
```

Matematikte alışılan mutlak değer işaretinin ($\lvert new - old \rvert$) yerine akışta `abs` (absolute) yazılır. Hoca, kimse itiraz etmeyince taslaktaki hataları tek tek gösterdi (ekrandan, 00:40:00):

- **İlk değersiz değişken:** `new` ne dışarıdan okundu ne de bir ilk değer aldı, ama koşulda `new - old` hesaplanıyor. Bellekte o an rastgele ne varsa o kullanılır. Örneğin `new` şans eseri 1 ise fark 0 olur, 0 da $\varepsilon$'dan küçük olduğundan döngü hiç çalışmaz.
- **Ters koşul:** Fark $\varepsilon$'dan küçükse istenen hassasiyete zaten ulaşılmıştır ve çıkılmalıdır. Döngü farkın $\varepsilon$'dan **büyük** olduğu sürece dönmelidir.
- **Tanımsız değişken:** Okunan değişken `X`, ama çıktıda `N` yazılmış. `N` hiçbir yerden gelmiyor; `X` olmalıdır.
- **Eksik aktarma:** Her yinelemede bulunan yeni değer bir sonraki yinelemede eski değer olur. Bunun için hesaplamadan sonra `old = new` aktarması yapılmalıdır.

> **Hocanın vurgusu:** Bir işlemdeki değişken ilk değere sahip olmadan o işlem yapılamaz. Önceki derste de benzer bir hata bilerek yapılmıştı.

### 3.1 Akış şekillerini karıştırmak

**Soru:** Bir öğrenci doğru/yanlış (true/false) kollarının nerede belirtildiğini sordu. **Cevap:** Hoca çizilen şeklin `if` değil `while` olduğunu hatırlattı. Öğrenilecek şekil sayısı yedi sekiz kadardır ve bu aşamada "bu if miydi, while mıydı" diye sorulmamalıdır. Akış diyagramı slaytları ve ders kayıtları tekrar incelenmelidir.

**Soru:** Bir öğrenci internette akış şekillerinin derstekinden farklı çizildiğini gördüğünü söyledi. **Cevap:** Akış diyagramları inşaat, elektrik ve bilgisayar mühendisliğinde kullanılır; bilgisayar mühendisliği içinde bile farklı çizim gelenekleri vardır. Bu derste geçerli olan derste anlatılan gösterimdir. Önce derste verilen slayt, not ve kayıtlara hakim olunmalı, ondan sonra başka kaynaklara bakılmalıdır.

> **Hocanın vurgusu:** Akış diyagramında derste anlatılan gösterim esastır. Başka kaynaklardaki gösterimlere takılmak kafa karıştırır.

### 3.2 `new` için ilk değer

**Soru:** `new` değişkenine başlangıçta hangi değer verilmeli; 0 ya da 1 olabilir mi? **Cevap:** Hoca önerileri tek tek inceledi:

- 1 verilirse $old = 1$ olduğundan fark 0 olur, 0 her durumda $\varepsilon$'dan küçük kalır ve döngüye hiç girilmez. Bu yüzden 1 verilemez.
- 0 verilirse fark 1 olur. $\varepsilon$ değerini kullanıcı verir ve ne gireceği bilinmez. Normalde $\varepsilon$ ne kadar küçükse sonuç o kadar hassas olacağından küçük bir değer beklenir, ama kullanıcı 1 girerse akış yine bozulur. 0 ile 0.5 arasında bir değer seçmek de aynı sorunu taşır.

Doğru çözüm bir öğrenciden geldi: `old = 1` atamasından hemen sonra Newton formülü bir kez uygulanarak `new` hesaplanır, sonra döngüye girilir. Böylece ilk yinelemenin sonucu elde edilmiş olur; döngüde koşul kontrol edilir ve aynı hesaplar tekrarlanır.

### 3.3 Neden mutlak değer?

**Soru:** Bir öğrenci farkın mutlak değerinin neden alındığını, farkın zaten negatif olmayacağını sordu. **Cevap:** İlk değer 1, ikincisi 512.5'tir; $512.5 - 1$ pozitiftir. Ancak sonra tahminler yukarıdan aşağı doğru iner: $257.249 - 512.5$ negatiftir ve bundan sonraki bütün farklar negatiftir. $\varepsilon$ ise pozitif bir değer olarak beklenir. Bu yüzden farkın mutlak değeri karşılaştırılır.

## 4. Karekök Akışının Doğru Hali

Bu tartışmalardan sonra derste bu akış üzerine bir quiz yapıldı (akış ve adım adım analiz istendi; bkz. Örnek Sorular). Quizden sonra akış öğrencilerle birlikte yeniden çizildi (ekrandan, 01:20:00 ve 01:25:00):

```text
START
  -> OKU: N, ε
  -> İŞLEM: old = 1
            new = (old + N/old)/2
  -> WHILE abs(new - old) > ε
       doğru kolu: İŞLEM: old = new
                          new = (old + N/old)/2
                   (koşula geri dön)
  -> ÇIKTI: N, 'karekök', new
  -> STOP
```

Adımlar:

- Dışarıdan $N$ sayısı ve koşulu belirleyecek $\varepsilon$ okunur.
- İlklendirme yapılır: `old` değişkenine 1 atanır, `new` formülle bir kez hesaplanır.
- Koşul: `new` ile `old` arasındaki farkın mutlak değeri $\varepsilon$'dan büyük olduğu sürece devam edilir. Fark $\varepsilon$'un altına düşünce istenen hassasiyete ulaşılmış olur.
- Döngü gövdesinde önce son bulunan yeni değer eskisine atanır (`old = new`), çünkü o değer bir sonraki yinelemede eski değerdir. Sonra yeni değer hesaplanır.
- Döngüden çıkınca sayı ve karekökü yazdırılır.

### 4.1 `while` yerine `if` ile geri dönüş

**Soru:** Bir öğrenci `while` yerine `if` koyup doğru kolunu yukarıdaki hesaplamaya geri bağlamayı önerdi. **Cevap:** Hoca önce bu yolla yinelemenin nasıl sağlanacağını sorguladı. Öneri netleşince, koşulun doğru kolunu yukarı götürüp bir işleme bağlayan bu yapının `if` değil `repeat until` olduğunu söyledi. `repeat until`, slaytlarda kullanılmaması istenen yapılardandır.

## 5. Repeat Until, Goto, Continue ve Break Üzerine

Hoca `repeat until` kullanılmamasının nedeninin ileride Assembly, işletim sistemleri, yapısal programlama ve süreç (proses) optimizasyonu dersleriyle daha net anlaşılacağını söyledi. `repeat until` ile zorlanarak bir şey yapılabilir, ama `repeat until` ile yapılabilen her şey `while` ile de yapılabilir; bu yüzden onu kullanmak gerekli değildir.

Benzer bir açıklamayı C programlama için de yaptı. Bir iki hafta içinde başlanacak C derslerinde `goto`, `continue` ve `break` komutları anlatılacak ama kullanılmamaları istenecek:

- Hocaya göre bu üç ifade optimizasyon düşmanıdır ve aslında C'de olmaması gereken ifadelerdir.
- C'de bulunmalarının nedeni tarihseldir: Assembly'den yüksek seviyeli dillere geçilirken Assembly'de yazanların birikimi boşa gitmesin diye bazı Assembly komut ve yapıları C'ye eklenmiştir.
- Dilin doğal akışına aykırıdırlar. En basit sakıncaları, işlemcinin pipeline yapısının düzgün çalışmasını engellemeleri ve optimize olması gereken kodu kötüleştirmeleridir.

> **Hocanın vurgusu:** Bu derste C'de `goto`, `continue` ve `break` kullanılmaz; akışlarda da `repeat until` kullanılmaz.

## 6. Akış Diyagramının Sekiz Temel Şekli ve Çıktı Kutusu

Hoca şu aşamada öğrenilmesi gereken sekiz temel şekli saydı (ekrandan, 01:30:00):

- Start
- Stop
- Okuma (read)
- İşlem (process)
- While
- Çıktı
- For
- If

Önce bu sekiz şekil öğrenilmeli ve bir problemin çözümü bunlarla, kendi başına ifade edilebilmelidir.

### 6.1 Çıktı kutusunda sabit ve değişken

**Soru:** Bir öğrenci çıktı kutusundaki "karekök" ifadesinin hiçbir yerde tanımlanmadığını, bunun sorun çıkarıp çıkarmayacağını sordu. **Cevap:** Çıktı kutusunda `N, 'karekök', new` yazılır. `N` doğrudan yazılır ve virgülle ayrılır; `'karekök'` tırnak içindedir. Tırnak, bunun bir değişken değil ekrana olduğu gibi yazılacak sabit bir karakter dizisi (string) olduğunu gösterir. Sonra yine virgül ve bir değişken (`new`) gelir. Değişkenler tırnaksız, ekranda olduğu gibi görünmesi istenen sabitler tırnak içinde yazılır. Sabit bir sayı (hocanın örneği 1453) da çıktıya yazılabilir.

## 7. Akışın Analizi ve Pratik

**Soru:** Bir öğrenci quizler için daha fazla süre verilip verilemeyeceğini sordu. **Cevap:** Hoca, üzerinde bu kadar konuşulmuş bir akışı yeniden çizmenin 25 dakikadan uzun sürmemesi gerektiğini, sürmüyorsa bunun temel nedeninin büyük olasılıkla pratik eksikliği olduğunu söyledi. Pratik için kişi kendi problemlerini ortaya atıp çizebilir ve çizdiğinin doğruluğunu analizle sınayabilir.

**Analiz** şu demektir: akıştaki değişkenlerin her adımdaki değeri bir tabloya yazılır. Karekök akışı için hocanın örneği $N = 1024$, $\varepsilon = 0.01$ idi. Tabloda `old`, `new` ve while koşulundaki fark sütunları olur: ilk satırda `old` 1, `new` 512.5, fark yaklaşık 511'dir; koşul sağlandığı için ikinci adıma geçilir; ikinci satırda `old` 512.5, `new` 257.249 olur ve bu böyle sürer (tablonun tamamı için 1.1 bölümündeki tablo ve Örnek Sorular). Bu sistematik inceleme hangi akışa yapılırsa yapılsın, akışın çalışıp çalışmadığını gösterir.

> **Hocanın vurgusu:** Akışla birlikte adım adım analiz de yapılmalıdır. Zamanla pratik kazanıldıkça bir problemin nasıl çözüleceği konusunda önceden fikir sahibi olunur ve hız artar.

## 8. Bellekte Değişkenler ve Dizi Kavramı

Şimdiye kadarki akışlarda hep tek değerli değişkenler kullanıldı: $x$, $y$ gibi, herhangi bir anda yalnız bir değer saklayabilen değişkenler. Hoca belleği alt alta hücrelerden oluşan bir dikdörtgenle gösterdi (ekrandan, 01:40:00). Her değişken bellekte belirli bir bölgeyi ifade eder; örneğin $x$ 1004 adresine, $y$ 100C adresine yerleşmiştir. Bu yerleştirmeyi programcı değil, derleyici ve işletim sistemi yapar.

Hoca adreslerin tamamen uydurma olduğunu vurguladı. Adresler 1000, 1004, 1008, 100C, 1010 diye 4'er artar, çünkü değişkenler 4 baytlık düşünülmüştür; 8 baytlık olsalardı 8'er artardı. Tek değişkenler bellekte birbirinden bağımsız, ardışık ya da farklı yerlerde durabilir.

> **Ek bilgi (derste anlatılmadı):** Adresler on altılık (hexadecimal) tabanda yazılmıştır. 1008'den 4 sonra gelen adres on altılıkta 100C, ondan 4 sonra gelen 1010'dur. Bu beş adres onluk tabanda 4096, 4100, 4104, 4108 ve 4112'ye karşılık gelir.

### 8.1 Dizi (array)

Birbiriyle ilişkili birden fazla değeri bir arada tutmak gereken durumlarda **dizi** kavramı kullanılır (ekrandan, 01:45:00). Dizi de bir değişkendir, ama bir de boyutu vardır. Örneğin `A(N)` $N$ elemanlı bir $A$ dizisini ifade eder. $N$'nin ne olduğu bilinmelidir; bilinmezse `new` ve `old` örneğinde olduğu gibi sorun çıkar.

Bellekte dizinin elemanları ardışık olarak dizilir: $A$'nın birinci, ikinci, üçüncü, dördüncü elemanı peş peşe gelir. Yani dizi, bellekte birbirini takip eden bir değişkenler grubudur.

Dizinin adı $A$ olabileceği gibi $B$, $C$, $N$, $X$ de olabilir. Ancak derste benimsenen bir adlandırma alışkanlığı vardır ve anlaşılırlığı artırır:

- $N$: bir sayıyı, bir kalabalığı (adet ya da boyut) ifade eder.
- $I, J, K$: döngü değişkenleri.
- $X, Y, Z$: tek başına bilinmeyen değerler.

Bir elemana erişmek için dizinin adı yazılır, parantez açılır ve bir **indis** verilir. Dizi $N$ elemanlıysa indis 1 ile $N$ arasında olabilir: `A(3)` üçüncü elemana, `A(4)` dördüncü elemana erişir. Böylece dizinin bütün elemanlarına adım adım erişilebilir.

## 9. Dizinin Ortalaması

İlk dizi örneği, $N$ elemanlı bir dizinin ortalamasını bulmaktır. Tek bir değişken bir okuma kutusuyla okunuyordu; dizide ise önce eleman sayısı $N$ okunmalı, sonra elemanlar tek tek okunmalıdır. Hocanın tahtadaki akışı (ekrandan, 01:55:00 ve 02:00:00):

```text
START
  -> OKU: N                      (eleman sayısı)
  -> FOR I <- 1 || 1, N
       gövde: OKU: A(I)
  -> İŞLEM: ORT = 0              (öğrencilerin atladığı ilk değer)
  -> (1) bağlantı dairesi
  -> FOR I <- 1 || 1, N
       gövde: İŞLEM: ORT = ORT + A(I)
  -> İŞLEM: ORT = ORT / N
  -> ÇIKTI: ORT
  -> STOP
```

### 9.1 For döngüsünün gösterimi

`I ← 1 || 1` ve altındaki `N` şu anlama gelir: `I`'nın ilk değeri 1'dir; yanındaki 1, `I`'nın her adımda birer birer artırılacağını söyler (2 yazılsaydı ikişer artardı); alttaki `N`, `I`'nın alacağı en büyük değerdir. Böylece döngü $N$ elemanlı dizinin elemanlarını birden başlayıp birer artarak $N$'ye kadar tek tek okur.

**Soru:** Bir öğrenci döngünün `I = N` olduğunda da bir kez daha dönüp dönmediğini sordu. **Cevap:** `I` 1'den başlar, 2, 3, 4 diye gider; `for` döngüsü bu işin $N$ adım yapılacağı anlamına gelir, yani son değer $N$'dir. $N$. adım da yapıldıktan sonra çıkılır; döngüden çıkışta `I` $N+1$ olur (ekrandan, 01:55:00). Aksi halde döngü $N-1$ adım olurdu.

**Soru:** Bir öğrenci yukarıdaki `for` döngüsünde `I`'nın değeri nasıl aldığını sordu. **Cevap:** Hoca gösterimi yeniden açıkladı: `I ← 1` ilk değer atamasıdır, yanındaki 1 artış miktarıdır, alttaki `N` en büyük değerdir. Döngü her adımda bir dizi elemanı okur.

### 9.2 Bağlantı daireleri

Akış sayfaya sığmadığında ya da çizgilerin fiziksel olarak birleşmesi zor olduğunda içine numara yazılan daireler kullanılır. Bir dairede biten akış, aynı numaralı dairenin bulunduğu yerden devam eder. Hoca bunun pek tercih edilmediğini söyledi: tek daire varken sorun yoktur, ama 1, 2, 3, 4, 5 diye çoğaldıkça akışın takip edilebilirliği kaybolur.

### 9.3 Toplam değişkenini sıfırlamak

> **Hocanın vurgusu:** Herkesin atladığı nokta `ORT = 0` ilk değeridir. `ORT = ORT + A(I)` işleminde `ORT` sağ tarafta işleme girer; ilk değeri özellikle atanmazsa çoğu zaman ne olduğu bilinmez ve çıkan sonuç gerçek sonuç olmaz.

Hoca toplamanın nasıl ilerlediğini şöyle gösterdi (ekrandan, 02:00:00): `ORT` 0 iken dizinin birinci elemanı 1 olsun, toplanınca `ORT` 1 olur. İkinci eleman 2 ise `ORT` 3 olur. Bir sonraki eleman yine 2 ise `ORT` 5 olur. Böylece önceki toplam ile yeni eleman toplanarak `ORT` üzerinde dizinin bütün elemanlarının toplamı bulunur. Ortalama istendiği için sonunda eleman sayısına bölünür ve sonuç yazdırılır.

### 9.4 Okuma ve toplama tek döngüde yapılabilir mi?

**Soru:** İki `for` döngüsü yerine okuma ve toplama tek döngüde yapılamaz mı? **Cevap:** Hoca "hayır" dedi. Çizim olarak toplama işlemini ilk döngünün içine koymanın bir engeli yoktur; ama bu iki iş ayrı operasyonlar olarak düşünülür:

- Okuma her zaman kullanıcının klavyeden girmesi değildir; bir diskten, bir dosyadan ya da bir porttan da olabilir. Bilgi gelirken arada başka katmanlardan geçilir.
- İşletim sistemleri dersinde görüleceği gibi süreçlerin farklı durumları (state) vardır. Çalışma durumundaki (running) bir sürecin işini bitirmesi istenir. Ama süreç bir G/Ç başlattığı anda işlemciden alınır ve bekleme kuyruğuna (wait queue) konur, yerine başka bir süreç seçilir.
- Okuma ile hesaplamayı aynı döngüye koymak optimizasyon gibi görünür, ama süreç sürekli işlemci, G/Ç ve bekleme arasında yer değiştirir ve gereksiz yük oluşur. Ayrı tutulduğunda hesaplama tek seferde yapılıp biter.

## 10. Kısaltılmış Dizi Okuma Gösterimi

Diziyi ters çevirme problemine geçerken hoca, okuma için bir kısaltma tanımladı (ekrandan, 02:10:00). Okuma kutusuna `N, A(N)` yazılır:

- Önce `N` isimli değişken okunur.
- Sonra $A$ dizisinin $N$ adet elemanı okunur.

Kural: önce $N$ okunmalı, sonra `A(N)` yazılmalıdır. Normalde bir işlem kutusunda `A(N)` yazmak dizinin $N$. elemanı anlamına gelir; ama okuma kutusunda önce `N` sonra `A(N)` yazılırsa bütün elemanların okunduğu kabul edilir. Bu, tek tek okuyan bir `for` çizme zahmetini ortadan kaldırır. Hoca bu kurala uyulmazsa yanlış yapılmış olacağını, çok boyutlu dizilerde bu kısaltmanın işi daha da kolaylaştıracağını söyledi.

## 11. Diziyi Ters Çevirme Problemi

Problem: dizinin elemanlarını ters sıraya çevirmek. Örnek dizi 7, 11, 44, 53, 67, 87; istenen sonuç 87, 67, 53, 44, 11, 7.

### 11.1 Dizinin boyutunu değiştirmemek

Bir öğrenci `while` döngüsü kurup $N$'yi sıfıra inene kadar birer azaltmayı önerdi. Hoca $N$'nin dizinin boyutu olduğunu hatırlattı: $N$ değiştirilirse dizinin boyut bilgisi kaybolur ve bir daha geri bulunamaz. Dizinin neresinde olunduğunu izlemek için ayrı bir indis değişkeni ($I$ ya da $J$) kullanılır; dizinin sonuna gelinip gelinmediği $N$ ile kontrol edilir.

> **Hocanın vurgusu:** Dizinin boyutunu tutan $N$, döngü sayacı olarak kullanılıp değiştirilmez.

### 11.2 İç içe iki for önerisi

Başka bir öğrenci iç içe iki `for` önerdi (ekrandan, 02:15:00):

```text
START
  -> OKU: N, A(N)
  -> FOR I <- 1 || 1, N
       gövde: FOR J <- N || -1, 1
                gövde: İŞLEM: A(I) = A(J)
  -> ÇIKTI: A(N)
  -> STOP
```

Öğrenci önce iç döngünün 0'a kadar inmesini önerdi, çünkü "listelerde indis sıfırdan başlıyordu". Hoca bu derste indisin 1'den başladığını gösterdi; alt sınır 1 oldu. İç döngü değişkeni için `I` yerine farklı bir değişken (`J`) kullanıldı. Çıktıda `A(N)` yazılması da tartışıldı: bu yazım $N$. eleman olarak anlaşılabilir. Hoca çıktının da `for` ile yazılmasını tercih ettiğini, ama şimdilik bunu kabul ettiğini söyledi.

Sonra akış 7, 11, 44, 53, 67, 87 ile izlendi ($N = 6$). `I = 1` iken `J` 6'dan 1'e iner ve her adımda `A(1)` üzerine yeni bir değer yazılır. Hocanın gösterdiği gibi değerler birbirinin üzerine yazılır ve en sonunda baştaki konuma 11 gelir; akış çalışmaz.

> **Ders sonrası not:** Hocanın tahtada söylediği ara değerler kayıtta net değil. Akış python ile izlendiğinde `I = 1` turundan sonra dizi 11, 11, 44, 53, 67, 87 olur; turlar sürdükçe bütün elemanlar 11'e döner (son durum 11, 11, 11, 11, 11, 11). Sonuç hocanınkiyle aynıdır: akış diziyi ters çevirmez.

### 11.3 Birinci kural: geçici değişkenle yer değiştirme

Hoca öğrencilerin çözüme ulaşması için iki noktaya dikkat çekti. İlki, iki değerin yerini değiştirmektir (ekrandan, 02:20:00). Birinci adımda 87 başa, 7 sona gitmelidir. Ama yalnız `A(1) = A(6)` ve `A(6) = A(1)` yazılırsa:

- `A(1) = A(6)` ile `A(1)` 87 olur; 7 kaybolur.
- `A(6) = A(1)` ile `A(6)`'ya yine 87 yazılır.
- Sonuç 87, 11, 44, 53, 67, 87 olur. Hocanın benzetmesiyle 87, Ajan Smith gibi her yere kendini kopyalar.

Doğrusu, `A(1)`'in değerini önce bir geçici değişkende saklamaktır:

```text
TMP  = A(1)      -> TMP  = 7
A(1) = A(6)      -> A(1) = 87
A(6) = TMP       -> A(6) = 7
```

Böylece iki değişkenin yeri değişir.

### 11.4 İkinci kural: yarıya kadar gitmek

İkinci nokta, kaç kez yer değiştirileceğidir. 7, 11, 44, 53, 67, 87 dizisinde:

- 1. adım: 1. ve 6. eleman değişir → 87, 11, 44, 53, 67, 7.
- 2. adım: 2. ve 5. eleman değişir → 87, 67, 44, 53, 11, 7.
- 3. adım: 3. ve 4. eleman değişir → 87, 67, 53, 44, 11, 7. Dizi tamamlandı.

Önerilen akıştaki gibi $N$ adım sürdürülürse:

- 4. adım: 4. ve 3. eleman yine değişir → 87, 67, 44, 53, 11, 7.
- 5. adım: 5. ve 2. eleman değişir → 87, 11, 44, 53, 67, 7.
- 6. adım: 6. ve 1. eleman değişir → 7, 11, 44, 53, 67, 87.

Yani $N$ adım yapılırsa çok iş yapılıp başlanan yere dönülür.

> **Ders sonrası not:** Hocanın 4. ve 5. adım için söylediği ara diziler kayıtta karışık duyuluyor. Yukarıdaki ara durumlar python ile kontrol edildi; hocanın vardığı sonuç (6. adımda dizinin başlangıç haline dönmesi) doğrudur.

### 11.5 Tek eleman sayısında

Hoca diziye bir eleman daha ekledi: 7, 11, 44, 53, 67, 87, 5 (ekrandan, 02:25:00). Eleman sayısı 7 olur. Birinci ile yedinci, ikinci ile altıncı, üçüncü ile beşinci değişir; ortadaki eleman (53) için bir şey yapmaya gerek yoktur. Böylece:

- $N = 6$ ise 3 adım,
- $N = 7$ ise yine 3 adım

ile dizi ters çevrilir. Hoca bu problemin akışının öğrenciler tarafından üzerinde düşünülmesini istedi ve konuyu sonraki derse bıraktı.

## Örnek Sorular

### Soru 1: Newton yöntemiyle karekök akışı ve analizi (quiz)

(ekrandan, 00:50:00; derste sözlü, 00:47:02 ve 00:49:01)

Verilen bir sayının karekökünü Newton formülüyle, kullanıcının verdiği $\varepsilon$ hassasiyetine göre bulan akış diyagramını çizin. Akışla birlikte adım adım analiz yapın: akıştaki değişkenlerin her adımdaki değerini gösterin (örnek olarak 1024 ya da başka bir değer kullanılabilir). Akış her durumda çalışmalıdır.

**Çözüm (derste verildi, 01:17:36-01:23:09):** Akış 4. bölümdeki gibidir (ekrandan, 01:25:00). Hocanın analiz örneğinde $N = 1024$, $\varepsilon = 0.01$ alınır (derste sözlü, 01:35:58):

| Adım | old | new | $\lvert new - old \rvert$ | Koşul ($> 0.01$) |
|---|---|---|---|---|
| İlklendirme | 1 | 512.5 | 511.5 | doğru, döngüye gir |
| 1 | 512.5 | 257.249 | 255.251 | doğru |
| 2 | 257.249 | 130.615 | 126.634 | doğru |
| 3 | 130.615 | 69.227 | 61.387 | doğru |
| 4 | 69.227 | 42.010 | 27.218 | doğru |
| 5 | 42.010 | 33.192 | 8.817 | doğru |
| 6 | 33.192 | 32.021 | 1.171 | doğru |
| 7 | 32.021 | 32.000007 | 0.021 | doğru |
| 8 | 32.000007 | 32.000000 | 0.000007 | yanlış, çık |

Çıktı: `1024 karekök 32.0` (yaklaşık). Derste ilk iki satır sözlü verildi; tablonun geri kalanı python ile hesaplandı.

### Soru 2: Karekök akışı için gereken girdiler

(derste sözlü, 00:23:22)

Newton yöntemiyle karekök bulan akışta dışarıdan hangi değerler okunmalıdır?

**Çözüm (derste verildi):** Karekökü bulunacak sayı ve hassasiyeti belirleyen $\varepsilon$. $\varepsilon$ yinelemenin durma koşulunu belirler; sabit olarak akışa yazılmaz, parametre olarak okunur.

### Soru 3: Taslak akıştaki hatalar

(ekrandan, 00:30:00; derste sözlü, 00:31:23)

3. bölümdeki taslak akışın (oku `X, ε`; `old = 1`; `while abs(new - old) < ε` iken `new = (old + X/old)/2`; yaz `N, 'karekökü', new`) hatalarını bulun.

**Çözüm (derste verildi, ekrandan, 00:40:00):**

- `new` ilk değer verilmeden kullanılıyor; `old = 1`'den sonra `new = (old + X/old)/2` bir kez hesaplanmalı.
- Koşul `< ε` değil `> ε` olmalı.
- Çıktıdaki `N` tanımsız; `X` olmalı.
- Döngü gövdesinde `old = new` aktarması eksik.

### Soru 4: Diziyi ters çevirme

(ekrandan, 02:15:00 ve 02:25:00; derste sözlü, 02:02:30)

$N$ elemanlı bir $A$ dizisini ters çeviren akışı çizin. Örnek: 7, 11, 44, 53, 67, 87 → 87, 67, 53, 44, 11, 7.

> **Çözüm (derste verilmedi):** Derste yalnız iki kural verildi (geçici değişkenle yer değiştirme ve yarıya kadar gitme); akış öğrencilere bırakıldı. Bu kurallarla kurulan bir çözüm aşağıdadır. `N/2`'nin tam kısmı alınır; $N = 6$ ve $N = 7$ için 3 olur. Akış python ile 6 ve 7 elemanlı örneklerde denendi: 7, 11, 44, 53, 67, 87 → 87, 67, 53, 44, 11, 7; 7, 11, 44, 53, 67, 87, 5 → 5, 87, 67, 53, 44, 11, 7.

```text
START
  -> OKU: N, A(N)
  -> FOR I <- 1 || 1, N/2 (tam kısmı)
       gövde: İŞLEM: TMP = A(I)
                     A(I) = A(N - I + 1)
                     A(N - I + 1) = TMP
  -> FOR I <- 1 || 1, N
       gövde: ÇIKTI: A(I)
  -> STOP
```

## Dersin Toparlaması

Bu derste koşula bağlı yinelemenin tipik örneği olan Newton yöntemiyle karekök bulma problemi ele alındı. Kaç adım gerektiği bilinmediği için döngü `while` ile kuruldu ve durma koşulu ardışık iki tahmin arasındaki farkın mutlak değerinin $\varepsilon$ hassasiyetinin altına inmesi olarak belirlendi. Taslak akış üzerinden ilk değer verilmeyen değişken, ters koşul, tanımsız değişken ve eksik `old = new` aktarması gibi sık yapılan hatalar gösterildi; doğru akışta `new` döngüden önce bir kez hesaplandı. Ayrıca `repeat until`, `goto`, `continue` ve `break` kullanılmaması gerektiği ve akışın sekiz temel şekli vurgulandı.

Dersin ikinci yarısında dizi kavramına geçildi: dizi, bellekte ardışık duran ve bir indisle erişilen değişkenler grubudur. Dizinin ortalaması akışında toplam değişkeninin sıfırlanması ve okuma ile hesaplamanın ayrı döngülerde tutulması üzerinde duruldu. Son olarak diziyi ters çevirme problemine başlandı; geçici değişkenle yer değiştirme ve yalnız dizinin yarısı kadar adım yapma kuralları verildi. Bu problemin akışı sonraki derste konuşulmaya devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
