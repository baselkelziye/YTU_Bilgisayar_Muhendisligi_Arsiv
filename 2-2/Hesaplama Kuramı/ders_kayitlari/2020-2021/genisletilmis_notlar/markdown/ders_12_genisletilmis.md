# Ders 12 Genişletilmiş Notu: Turing Makinesi Örnekleri, Biçimsel Tanım, Turing ile Tanınabilir Diller ve Fonksiyon Hesaplama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Turing Makinesinin Tekrarı
- 2. Durma, Kabul ve Ret
- 3. Örnek: $a^nb^n$ Dilini Tanıyan Turing Makinesi
- 4. Turing Makinesinin Biçimsel Tanımı
- 5. Turing ile Tanınabilir Diller
- 6. Turing Makinesiyle Fonksiyon Hesaplama
- 7. Örnek: $f(x, y) = x + y$
- 8. Örnek: $f(x) = 2x$

## 1. Turing Makinesinin Tekrarı

Hoca derse geçen haftanın kısa bir tekrarıyla başladı. Turing makineleri (Turing machines) şimdiye kadar gördüğümüz makinelerden daha güçlüdür. Düzenli dillerin (regular languages) ve bağlamdan bağımsız dillerin (context-free languages) kapsamadığı dilleri de kabul edebilirler. Tahtadaki örnek $a^nb^nc^n$ dilidir.

<!-- BELİRSİZ: Altyazıda yalnızca "something like that" geçiyor. Örnek dil kısa nottan alındı. -->

### 1.1 Makinenin Parçaları

Turing makinesindeki yenilik giriş şerididir (input tape). Giriş dizgisi başlangıçta şeridin ortasındadır. Okuma-yazma kafası (read-write head) girişin ilk sembolünü gösterir. Şerit iki yönde de sonsuzdur. Giriş dışında kalan her hücrede boş sembol (blank symbol, $\square$) vardır.

Geri kalan her şey önceki otomatlara çok benzer. Durumlar (states), geçişler (transitions), kabul olmayan durumlar (non-accepting states) ve kabul durumları (accepting states) vardır.

### 1.2 Bir Adımda Ne Olur?

Turing makinesi her adımda üç iş yapar: bir sembol okur, bir sembol yazar, sola ya da sağa gider. Diyagramda bu bilgi geçişin üstüne yazılır. Okunacak ve yazılacak sembol arasında bir ok vardır, onun yanında da yön bulunur. Örneğin $a \to b, R$ "$a$ oku, $b$ yaz, sağa git" demektir.

### 1.3 Anlık Tanım

Anlık tanım (instantaneous description), şeridin o anki içeriğini ve makinenin o anki durumunu birlikte gösterir. Yazım kuralı şöyledir: kafa hangi sembolü gösteriyorsa, durum o sembolün hemen önüne yazılır. Kafanın gösterdiği sembol ve ondan sonrakiler durumun sağında, öncekiler durumun solunda kalır. Hocanın tekrar örneğinde kafa $d$ sembolünü gösterir ve durum $q_0$'dır. Bu yüzden $q_0$, $d$'nin önüne yazılır.

<!-- BELİRSİZ: Tahtadaki şerit içeriğinin tamamı altyazıda okunmuyor, yalnız d sembolü ve q0 geçiyor. -->

### 1.4 Deterministiklik ve Diyagram Kuralı

Bu derste gördüğümüz Turing makineleri deterministiktir. Aynı girdi için yalnız tek bir şey olabilir. Boş geçiş (null transition) de yoktur. Hoca, derste ileride deterministik olmayan Turing makinelerinin (non-deterministic Turing machines) de görüleceğini söyledi. Onlar açıkça bu adla anılacak. "Turing makinesi" denince deterministik olan anlaşılır.

Deterministik sonlu otomatlarda (DFA) diyagramda her durum için bütün sembollerin ne yaptığını göstermek gerekiyordu. Turing makinesi deterministik olduğu halde bunu yapmayız, çünkü diyagram çok karışır. Yalnız geçişi olan semboller gösterilir.

## 2. Durma, Kabul ve Ret

### 2.1 Makine Ne Zaman Durur?

Turing makinesi, izleyecek geçiş kalmadığı durumda durur (halt). Bu iki biçimde olabilir:

- Durumdan dışarı hiç geçiş yoktur.
- Durumdan dışarı geçişler vardır, ama kafanın altındaki sembol için geçiş yoktur.

İki halde de makine çalışmayı keser. "Makine o durumda durdu" deriz.

### 2.2 Kabul Durumları

Turing makinelerinde kabul durumlarından dışarı geçiş yoktur. Az önceki kurala göre geçişi olmayan durumda makine durur. Bu yüzden kabul durumuna giren makine orada durur. Durum kabul durumu olduğu için de girişi kabul eder.

### 2.3 Üç Olası Sonuç

Hoca sonuçları şöyle özetledi:

- Makine bir kabul durumunda durursa giriş dizgisini kabul eder.
- Makine kabul olmayan bir durumda durursa girişi reddeder.
- Makine sonsuz döngüye (infinite loop) girerse kabul edemez. Hoca bu durumda da makinenin girişi reddettiğini söyledi.

> **Ders sonrası not:** Hoca ikinci maddeyi söylerken de "accept state" dedi (00:13:25). Doğrusu kabul **olmayan** durumdur. Sonsuz döngü için de hoca "reddeder" dedi. Bölüm 4.6'daki $L(M)$ tanımına göre kesin olan şudur: döngüye giren makine girişi kabul etmez, giriş $L(M)$'de değildir. Durarak reddetmekle hiç durmamak aynı şey değildir.

### 2.4 Giriş Tüketilmek Zorunda Değildir

Önceki otomatlardan bir fark daha vardır: giriş tamamen tüketilmek zorunda değildir. Kafa bir sembolü okur, yerine bir şey yazar ve sola da gidebilir. Bu yüzden hesaplamanın sonunda şeritte hâlâ giriş sembolleri kalabilir. Bazı sembollere hiç dokunulmamış da olabilir. Makine girişin başından başlayıp sonuna varmadan kabul edip durabilir.

## 3. Örnek: $a^nb^n$ Dilini Tanıyan Turing Makinesi

### 3.1 Dil

Hoca, evde bakılması istenen ama derste de üzerinden geçtiği daha karmaşık bir örneğe geldi. Dil $L = \{a^nb^n : n \ge 1\}$. Makinenin $ab$, $aabb$, $aaabbb$ gibi dizgileri kabul etmesi gerekir.

> **Ders sonrası not:** Hoca dili okurken "$n$ birden büyük" dedi (00:15:22). Hemen ardından verdiği $ab$ örneği $n = 1$'dir. Kısa nota göre tahtada da $n \ge 1$ yazıyor. Doğrusu $n \ge 1$'dir. Makinenin simülasyonu $ab$'yi kabul ediyor.

### 3.2 Temel Fikir: Eşleştirme

Sorun sayıları eşleştirmektir. Makine $a$ ve $b$ sayılarının aynı olduğunu görmelidir. Bunun için her $a$, kendisine karşılık gelen bir $b$ ile eşleştirilir. İlk $a$ ilk $b$ ile, yanındaki $a$ bir sonraki $b$ ile eşleşir.

Hoca neden sayaç kullanmadığımızı da açıkladı. Bu diyagramda $a$ ve $b$ sayılarını bir yerde saklamıyoruz. Turing makineleri çok güçlüdür, bunu aslında yapabilirler, ama makine çok karmaşık olur. Bu nedenle burada sayı tutmak yerine semboller eşleştirilir. Bütün $a$'lar birer $b$ ile eşleştiyse ve hiç $b$ kalmadıysa sayılar eşittir.

### 3.3 Algoritma

Hoca makinenin aslında bir algoritmaya denk olduğunu söyleyip önce algoritmayı yazdı:

- Tekrarla:
  - En soldaki $a$'yı $x$ ile değiştir.
  - En soldaki $b$'yi bul, $y$ ile değiştir.
- Başka $a$ ya da $b$ kalmayana kadar.
- Sonda eşleşmemiş bir $a$ ya da $b$ kaldıysa reddet.

$b$ yerine $y$ yazmanın anlamı şudur: bu hücre bir $b$ idi ve bir $a$ ile eşleşti.

### 3.4 Makine

Kabul durumu $q_4$'tür.

| Durum | Okunan | Yazılan | Hareket | Sonraki durum | Görev |
| :---: | :---: | :---: | :---: | :---: | :--- |
| $q_0$ | $a$ | $x$ | R | $q_1$ | En soldaki $a$'yı işaretle |
| $q_0$ | $y$ | $y$ | R | $q_3$ | $a$ kalmadı, fazla $b$ var mı bak |
| $q_1$ | $a$ | $a$ | R | $q_1$ | Sağa ilerle |
| $q_1$ | $y$ | $y$ | R | $q_1$ | Sağa ilerle |
| $q_1$ | $b$ | $y$ | L | $q_2$ | En soldaki $b$'yi işaretle |
| $q_2$ | $y$ | $y$ | L | $q_2$ | Geri dön |
| $q_2$ | $a$ | $a$ | L | $q_2$ | Geri dön |
| $q_2$ | $x$ | $x$ | R | $q_0$ | Döngünün başına dön |
| $q_3$ | $y$ | $y$ | R | $q_3$ | $y$'leri geç |
| $q_3$ | $\square$ | $\square$ | L | $q_4$ | Fazla $b$ yok, kabul |

Algoritmanın satırları makineye şöyle oturur:

- "En soldaki $a$'yı $x$ ile değiştir": $q_0 \to q_1$ geçişi. $aabb$ için şerit $xabb$ olur.
- "En soldaki $b$'yi bul": $q_1$ üzerindeki döngü. $a$ ya da $y$ gördükçe sağa gider, $b$ bulana kadar.
- "$b$'yi $y$ ile değiştir": $q_1 \to q_2$ geçişi. Bu geçişte sola gidildiği için kafa $y$'nin bir solundadır.
- Tekrar döngüsü: $q_2$ üzerindeki döngü $a$ ve $y$ gördükçe sola gider. $x$ görünce onu değiştirmeden sağa gider. Böylece kafa kalan ilk $a$'nın üstüne gelir ve $q_0$'a dönülür.

Hoca $q_2$ döngüsünün $aabb$ gibi küçük bir örnekte iyi görünmediğini, daha büyük bir örnekte daha iyi anlaşılacağını ekledi. Burada tek $a$ atlanır. Daha fazla $a$ olsaydı hepsi atlanırdı.

### 3.5 $aabb$ Üzerinde Hesaplama

Zaman sıfırda makine $q_0$ durumundadır ve giriş $aabb$'dir. Hesaplama aşağıdaki gibidir:

| Adım | Anlık tanım | Ne oldu? |
| :---: | :---: | :--- |
| 0 | $q_0aabb$ | Başlangıç |
| 1 | $xq_1abb$ | $a \to x$, sağa, $q_1$ |
| 2 | $xaq_1bb$ | $a$ atlanır, sağa |
| 3 | $xq_2ayb$ | $b \to y$, sola, $q_2$ |
| 4 | $q_2xayb$ | $a$ atlanır, sola |
| 5 | $xq_0ayb$ | $x$ görüldü, sağa, $q_0$. Bir tur bitti |
| 6 | $xxq_1yb$ | $a \to x$, sağa, $q_1$ |
| 7 | $xxyq_1b$ | $y$ atlanır, sağa |
| 8 | $xxq_2yy$ | $b \to y$, sola, $q_2$ |
| 9 | $xq_2xyy$ | $y$ atlanır, sola |
| 10 | $xxq_0yy$ | $x$ görüldü, sağa, $q_0$ |
| 11 | $xxyq_3y$ | $a$ kalmadı, $y$ görüldü, sağa, $q_3$ |
| 12 | $xxyyq_3\square$ | $y$ atlanır, sağa |
| 13 | $xxyq_4y$ | $\square$ görüldü, sola, $q_4$. Kabul |

Adım 10'da $q_0$'dayız ve bütün $a$'lar ile $b$'ler eşleşmiştir. Başka $a$ olsaydı bir tur daha dönerdik. Burada $a$ kalmadığı için büyük döngüden çıkıyoruz. $y$ gördüğümüz için $q_3$'e giden geçiş kullanılır.

$q_3$'ün görevi şudur: $a$'ların bittiğini biliyoruz, soru fazla $b$ olup olmadığıdır. Hocanın bu noktadaki örneği $aabbb$ gibi, $b$ sayısının fazla olduğu bir dizgidir. $q_3$ döngüsü $y$ gördükçe sağa gider. $y$'lerden sonra bir $b$ gelirse, $q_3$'te $b$ için geçiş yoktur. Makine $q_3$'te durur ve reddeder, çünkü $q_3$ kabul olmayan bir durumdur. $aabbb$ için makine $xxyyq_3b$ anlık tanımında durur. $b$ gelmezse sırada boş sembol vardır. Boş sembol geçişiyle kabul durumu $q_4$'e gidilir.

$q_4$'e gelince başka bir şey yapılmaz. Kabul durumuna ulaşan Turing makinesi durur ve kabul eder.

> **Hocanın vurgusu:** Anlık tanımları yazarken çok dikkatli ve odaklı olmak gerekir.

> **Ders sonrası not:** Hoca bu hesaplamayı yazarken adım 3'ten sonra yönü karıştırdı (00:30:17-00:31:21). Geçişte sola gitmişken $q_0$ yazdı, sonra fark edip o kısmı baştan yazdı. Adım 6'da da önce $q_0$ dedi, "$q_1$ olacak" diye düzeltti. Benzer biçimde adım 13'te önce $q_3$ dedi, $q_4$ olarak düzeltti. Yukarıdaki tablo doğru sıradır. Her satır simülasyonla doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Hoca fazla $b$'nin nerede yakalandığını gösterdi, fazla $a$'nın yerini göstermedi. Kalan bir $a$ için makine $q_1$'e geçer, $y$'leri geçer ve boş sembole varır. $q_1$'de boş sembol için geçiş yoktur, makine orada durur ve reddeder. Makine $\{a, b\}$ üzerinde uzunluğu 12'ye kadar bütün dizgilerde (8191 dizgi) simülasyonla denendi. Hepsinde durdu ve yalnız $a^nb^n$ ($n \ge 1$) dizgilerini kabul etti.

### 3.6 Ev Çalışması: $a^nb^nc^n$

Hoca, bu makineyi daha karmaşık bir dil için değiştirmenin çok zor olmaması gerektiğini söyledi. Çalışmayı öğrencilere bıraktı: önceki $M$ makinesini $\{a^nb^nc^n : n \ge 1\}$ dilini, yani $aaabbbccc$ gibi dizgileri kabul edecek biçimde değiştirin.

**Soru:** Buradaki $y$ mi olacak, $b$ mi dediniz? **Cevap:** Altyazıda cevap yok.

<!-- BELİRSİZ: 00:43:17'deki soru bir geçişteki yazılacak sembolle ilgili görünüyor. Hangi geçiş olduğu ve cevap altyazıda yok. -->

> **Ek bilgi (derste anlatılmadı):** Bir çözüm şudur: her turda bir $a$ $x$, bir $b$ $y$, bir $c$ $z$ olur. Geçişler: $q_0$'da $a \to x, R$ ile $q_1$, $y \to y, R$ ile $q_4$; $q_1$'de $a$ ve $y$ üzerinde sağa döngü, $b \to y, R$ ile $q_2$; $q_2$'de $b$ ve $z$ üzerinde sağa döngü, $c \to z, L$ ile $q_3$. $q_3$'te $a, b, y, z$ üzerinde sola döngü, $x \to x, R$ ile $q_0$; $q_4$'te $y$ ve $z$ üzerinde sağa döngü, $\square \to \square, L$ ile kabul durumu $q_5$. Makine $\{a, b, c\}$ üzerinde uzunluğu 10'a kadar bütün dizgilerde (88573 dizgi) simülasyonla denendi ve yalnız $abc$, $aabbcc$, $aaabbbccc$ dizgilerini kabul etti.

## 4. Turing Makinesinin Biçimsel Tanımı

Yeterince örnek gördükten sonra hoca biçimsel tanımlara geçti.

### 4.1 Geçiş Fonksiyonu

$q_1$'den $q_2$'ye giden, $a$ okuyup $b$ yazan ve sağa giden bir geçiş, tek bir geçiş fonksiyonu kaydı olarak şöyle yazılır:

$$\delta(q_1, a) = (q_2, b, R)$$

"$q_1$'deyken $a$ okunursa $q_2$'ye gidilir, $b$ yazılır, sağa gidilir" demektir. Geçiş fonksiyonunun genel biçimi $\delta: Q \times \Gamma \to Q \times \Gamma \times \{L, R\}$'dir.

<!-- BELİRSİZ: Genel biçim altyazıda sözlü geçmiyor; kısa nottan (tahtadan) alındı. -->

### 4.2 Yedili Tanım

Turing makinesi yedi öğeli bir yapıdır (7-tuple):

$$M = (Q, \Sigma, \Gamma, \delta, q_0, \square, F)$$

- $Q$: durumlar kümesi.
- $\Sigma$: giriş alfabesi (input alphabet), giriş sembollerinin kümesi.
- $\Gamma$: şerit alfabesi (tape alphabet), şerit sembollerinin kümesi.
- $\delta$: geçiş fonksiyonu.
- $q_0$: başlangıç durumu.
- $\square$: boş sembol. Hangi sembolün boş sembol olduğu tanımda belirtilir.
- $F$: kabul durumları kümesi.

Hoca bunlarda yeni bir şey olmadığını söyledi. Önceki otomatlardaki tanımlara benzer.

### 4.3 Anlık Tanım ve Hesaplama

Anlık tanımı daha önce görmüştük. Şeritte $c\,a\,b\,a$ varsa, kafa $b$'yi gösteriyorsa ve makine $q_1$'deyse anlık tanım $caq_1ba$ olur.

Hesaplama (computation), art arda gelen anlık tanımların listesidir. Bölüm 3.5'ten bir parça:

$$q_2xayb \vdash xq_0ayb \vdash xxq_1yb \vdash xxyq_1b$$

### 4.4 Kısa Gösterim

Önceki otomatlarda olduğu gibi burada da bir kısaltma vardır. Ara adımlar atlanıp yalnız ulaşılmak istenen sonuç yazılabilir:

$$q_2xayb \vdash^* xxyq_1b$$

### 4.5 Başlangıç Konfigürasyonu

Başlangıç konfigürasyonu (initial configuration), başlangıç durumunun ve okunacak dizginin yazılmasıyla elde edilir. Şeritte $\square\,a\,a\,b\,b\,\square$ durur, $q_0$ ilk elemanı gösterir: $q_0w$. Hoca, konfigürasyon (configuration) ile anlık tanımın aynı şey olduğunu söyledi. "Güncel konfigürasyon" ya da "güncel anlık tanım" denebilir.

### 4.6 Kabul Edilen Dil

Kabul edilen dil bu hesaplamalar cinsinden yazılabilir. Bir $M$ Turing makinesi için $L(M)$, şu dizgilerin kümesidir: başlangıç konfigürasyonundan başlanır, bir miktar hesaplamadan sonra kabul durumlarından birine varılır.

$$L(M) = \{ w : q_0w \vdash^* x_1 q_f x_2,\ q_f \in F \}$$

Burada $q_0$ başlangıç durumu, $q_f$ herhangi bir kabul durumudur. $x_1$ ve $x_2$, $q_f$'nin solunda ve sağında kalan dizgilerdir. Bölüm 2.4'te gördüğümüz gibi sonda şeritte sembol kalabilir.

## 5. Turing ile Tanınabilir Diller

Aradan sonra hoca önemli bir tanım verdi. Bir $L$ dili bir $M$ Turing makinesi tarafından kabul ediliyorsa, $L$ dili **Turing ile tanınabilirdir** (Turing recognizable).

Kaynaklarda aynı kavram için başka adlar da görülür: Turing ile kabul edilebilir (Turing acceptable) ve özyinelemeli sayılabilir (recursively enumerable).

Hoca bu tanımın şimdilik çok önemli olmadığını, ileride önem kazanacağını söyledi. İleride bundan biraz farklı olan Turing ile karar verilebilir dilleri (Turing decidable languages) göreceğiz.

> **Ek bilgi (derste anlatılmadı):** Fark, Bölüm 2.3'teki sonsuz döngü durumundan gelir. Turing ile tanınabilir bir dilde makine dildeki her dizgiyi kabul eder, ama dilde olmayan bir dizgide döngüye girebilir. Turing ile karar verilebilir bir dilde ise makine her girişte durur, kabul eder ya da reddeder. Bu nedenle "reddetme" ile "hiç durmama" ayrımı ileride önemlidir.

## 6. Turing Makinesiyle Fonksiyon Hesaplama

Turing makineleri çok güçlüdür, bilgisayarlar gibidirler. Bu yüzden onları fonksiyon hesaplamak için de kullanabiliriz.

### 6.1 Fonksiyon Hatırlatması

Bir fonksiyonun bir tanım kümesi (domain) $D$ ve bir sonuç bölgesi (result region) $S$ vardır. $f$ fonksiyonu, tanım kümesindeki bir $w$ parametresini alır ve onu $S$ içindeki bir değere götürür. Bu değere $f(w)$ deriz. Bir fonksiyonun birden fazla parametresi de olabilir. Örnek: $f(x, y) = x + y$.

<!-- BELİRSİZ: Altyazıda kümelerin yazımı "domen, DFA" ve "result region S" olarak geçiyor. Tahtadaki gösterim D_f ve S_f olabilir; burada kısa notla uyumlu olarak D ve S yazıldı. -->

### 6.2 Tam Sayıların Gösterimi

İşleri basit tutmak için şimdilik yalnız tam sayılar (integers) üzerinde çalışacağız. Aynı değeri farklı biçimlerde gösterebiliriz. Değer 5 olsun:

- Onluk gösterim (decimal): $5$.
- İkili gösterim (binary), taban 2: $101$ (ara adım eklendi).
- Tekli gösterim (unary): `11111`.

Tekli gösterim bu derste yenidir. Yalnız bir sembol vardır, o da 1'dir. Dizginin uzunluğu değerin kendisidir. Beş tane 1, 5 demektir.

> **Hocanın vurgusu:** Tekli gösterimi tercih ederiz, çünkü Turing makinesiyle işlem yapmak bu gösterimde daha kolaydır.

> **Ders sonrası not:** Hoca tanım kümesine "tam sayılar" dedi. Tekli gösterimde değer dizginin uzunluğu olduğu için yalnız negatif olmayan tam sayılar gösterilebilir.

### 6.3 Hesaplanabilir Fonksiyon

Bir fonksiyonu bir Turing makinesiyle hesaplayabiliyorsak ona hesaplanabilir (computable) deriz. Tanım şöyledir. Bir $f$ fonksiyonu için, tanım kümesi $D$'deki **her** $w$ dizgisinde aşağıdakileri sağlayan bir Turing makinesi varsa $f$ hesaplanabilirdir:

- Başlangıçta şeritte $w$ dizgisi ve iki yanında boş semboller vardır. Makine $q_0$'dadır ve kafa $w$'nin başındadır.
- Makine çalıştıktan sonra şeritte $f(w)$ dizgisi vardır.
- Kafa bu yeni değerin başındadır.
- Durum bir kabul durumudur.

Hoca aynı tanımı anlık tanımlarla da yazdı:

$$q_0w \vdash^* q_ff(w), \quad q_f \in F, \quad \text{her } w \in D \text{ için}$$

Sol taraf başlangıç konfigürasyonu, sağ taraf bitiş konfigürasyonudur (final configuration).

Hocanın küçük örneği $f(x) = 2x$'tir. Giriş tekli gösterimde `11`, yani 2 ise, hesaplamanın sonunda şeritte `1111`, yani 4 olmalıdır. Makine de bir $q_f$ durumunda, sonucun ilk sembolünde bulunmalıdır. İki kere iki dörttür.

## 7. Örnek: $f(x, y) = x + y$

$f(x, y) = x + y$ hesaplanabilirdir. Bunu bir makine vererek göstereceğiz. $x$ ve $y$ tam sayıdır.

### 7.1 Giriş ve Çıkış

İki parametre olduğu için onları ayırmanın bir yolu gerekir. Tekli gösterim kullandığımızdan ayırıcı olarak 0 seçilir.

- Giriş dizgisi: $x$ tane 1, sonra 0, sonra $y$ tane 1. Yani `1^x 0 1^y`.
- Çıkış dizgisi: $x + y$ tane 1, sonra 0. Yani `1^(x+y) 0`.

Sondaki 0 ihtiyaca göre gerekli olabilir ya da olmayabilir. Burada, sonucun daha sonra başka bir fonksiyonda kullanılabileceğini varsayıyoruz. Bu yüzden sona bir 0 konur ve sonraki hesaplamalara yardım eder. Bu 0 sayılmaz, yalnız ayırıcıdır. `110` dizgisi de `11` gibi 2 demektir.

Başlangıçta makine $q_0$'da ve ilk 1'in üstündedir. Şeridin geri kalanı boştur. Bittiğinde kafa yine ilk sembolün üstünde, durum da bir kabul durumu olmalıdır.

### 7.2 Temel Fikir ve Makine

Hoca şunu fark etmemizi istedi: aslında toplama yapmaya gerek yoktur. Ortadaki 0 yerine 1 yazmak ve en sondaki 1 yerine 0 yazmak yeter. Sonra başa dönülür.

Makinenin beş durumu vardır, $q_0$-$q_4$. Kabul durumu $q_4$'tür.

| Durum | Geçiş | Sonraki durum | Görev |
| :---: | :--- | :---: | :--- |
| $q_0$ | $1 \to 1, R$ | $q_0$ | $x$'in 1'lerini geç |
| $q_0$ | $0 \to 1, R$ | $q_1$ | Ayırıcıyı 1 yap |
| $q_1$ | $1 \to 1, R$ | $q_1$ | $y$'nin 1'lerini geç |
| $q_1$ | $\square \to \square, L$ | $q_2$ | Sona gelindi, bir geri dön |
| $q_2$ | $1 \to 0, L$ | $q_3$ | Son 1'i 0 yap |
| $q_3$ | $1 \to 1, L$ | $q_3$ | Başa dön |
| $q_3$ | $\square \to \square, R$ | $q_4$ | İlk sembole geç, kabul |

$q_1 \to q_2$ geçişinin mantığı şudur: son 1'i silmek istiyoruz, ama son 1'in üstünde olduğumuzu anlamak için önce bir boş sembol görmemiz gerekir. Boş sembolü gördükten sonra bir sola gidilince son 1'in üstüne geliriz.

$q_3$ için de benzer bir durum vardır. Makine başa geldiğini ancak boş sembol görünce anlar. O anda istenen yerde değildir, ilk sembolün bir solundadır. Bu yüzden bir sağa gider ve kabul durumuna girer.

### 7.3 $2 + 2$ Üzerinde Hesaplama

$x = 2$, $y = 2$ alalım. Başlangıç şeridi `11011`, beklenen sonuç `11110` ve kabul durumu $q_4$'tür.

| Adım | Anlık tanım | Ne oldu? |
| :---: | :---: | :--- |
| 0 | $q_011011$ | Başlangıç |
| 1 | $1q_01011$ | 1 geçilir |
| 2 | $11q_0011$ | 1 geçilir |
| 3 | $111q_111$ | $0 \to 1$, sağa, $q_1$ |
| 4 | $1111q_11$ | 1 geçilir |
| 5 | $11111q_1\square$ | 1 geçilir |
| 6 | $1111q_21$ | $\square$ görüldü, sola, $q_2$. Şeritte beş tane 1 var, dört istiyoruz |
| 7 | $111q_310$ | $1 \to 0$, sola, $q_3$ |
| 8 | $11q_3110$ | 1 geçilir, sola |
| 9 | $1q_31110$ | 1 geçilir, sola |
| 10 | $q_311110$ | 1 geçilir, sola |
| 11 | $q_3\square11110$ | Makine başta olduğunu bilmez, 1 gördüğü için bir sola daha gider |
| 12 | $q_411110$ | $\square$ görüldü, sağa, $q_4$. Kabul |

Sonuç `11110`'dur. 0 sayılmadığı için bu 4'tür, yani $x + y$. Kafa ilk semboldedir ve durum kabul durumudur.

> **Ders sonrası not:** Hoca adım 12'yi anlatırken bir an "sola" dedi (01:44:47), geçiş sağa gider. Aynı adımda önce $q_3$ yazıp $q_4$ olarak düzeltti. Tablo simülasyonla doğrulandı. Makine $0 \le x, y \le 30$ aralığındaki bütün çiftlerde de `1^(x+y) 0` üretti.

## 8. Örnek: $f(x) = 2x$

$f(x) = 2x$ de hesaplanabilirdir. Burada $x$ bir tam sayıdır. Giriş $x$ tane 1'dir (tekli gösterim). Çıkış $2x$ tane 1 olmalıdır. Hoca, fonksiyonun sayılarla konuştuğunu ama makinede gösterimin dizgi olduğunu hatırlattı. Çıkış dizgisi, $x$ dizgisinin iki kez yan yana yazılması gibidir.

Başlangıçta kafa ilk 1'in üstünde ve makine başlangıç durumundadır. Sonda yine kafa dizginin başında ve makine bir kabul durumunda olmalıdır.

### 8.1 Sözde Kod

Hoca bu noktada sözde kodu (pseudocode) tanıttı. Dersin bir yerinde, zaman kalırsa, otomatlar üzerinde çalışmayı bırakıp sözde kodlar ve algoritmalar cinsinden düşünmeye başlayacağız. Bu yüzden algoritmalar şimdiden devreye giriyor. Bu işi yapmanın farklı yolları olabilir. Hocanın kaynaklarda gördüğü yol şudur:

- Her 1'i `$` ile değiştir.
- Tekrarla:
  - En sağdaki `$`'ı bul, 1 ile değiştir.
  - Sağ uca git, bir 1 ekle.
- `$` kalmayana kadar.

Hoca bunu üç tane 1 üzerinde sözlü olarak gösterdi. Hedef altı tane 1'dir:

| Aşama | Şerit |
| :--- | :--- |
| Başlangıç | `111` |
| Her 1, `$` olur | `$$$` |
| En sağdaki `$` 1 olur, sona 1 eklenir | `$$11` |
| En sağdaki `$` 1 olur, sona 1 eklenir | `$1111` |
| En sağdaki `$` 1 olur, sona 1 eklenir | `111111` |

Her `$` bir 1 olarak geri döner ve sona bir 1 daha ekletir. Bu yüzden 1 sayısı iki katına çıkar. Hoca sözde kodun her satırının Turing makinesiyle bir biçimde yapılabileceğine dikkat çekti.

### 8.2 Makine

Makinenin durumları $q_0, q_1, q_2, q_3$'tür. Başlangıç durumu $q_0$, kabul durumu $q_3$'tür.

| Durum | Geçiş | Sonraki durum | Görev |
| :---: | :--- | :---: | :--- |
| $q_0$ | $1 \to \$, R$ | $q_0$ | Bütün 1'leri `$` yap |
| $q_0$ | $\square \to \square, L$ | $q_1$ | Sona gelindi |
| $q_1$ | $1 \to 1, L$ | $q_1$ | En sağdaki `$`'ı ara |
| $q_1$ | $\$ \to 1, R$ | $q_2$ | `$`'ı 1 yap |
| $q_2$ | $1 \to 1, R$ | $q_2$ | Sağ uca git |
| $q_2$ | $\square \to 1, L$ | $q_1$ | Sona 1 ekle |
| $q_1$ | $\square \to \square, R$ | $q_3$ | `$` kalmadı, kabul |

Makineyi parça parça okuyalım:

- **Birinci satır ($q_0$):** Başta bir miktar 1 vardır ve kafa en baştadır. 1 gördükçe `$` yazıp sağa gidilir. Boş sembole gelince birinci satır bitmiş demektir ve bir sola dönülür. Kafa artık en sağdaki `$`'ın üstündedir.
- **Döngünün başı ($q_1$):** Yürütmenin bir anında şeritte önce `$`'lar, sonra 1'ler, sonra boş sembol olur. $q_1$ bir döngünün başıdır. 1 gördükçe sola gidilir. `$` görülürse en sağdaki `$` bulunmuştur. Yerine 1 yazılır ve sağa gidilir.
- **Sağ uca gitme ($q_2$):** 1 gördükçe sağa gidilir. Boş sembol görülünce yerine 1 yazılır, sola gidilir ve $q_1$'e dönülür. Sözde kodun "sağ uca git, bir 1 ekle" satırı budur.
- **Döngüden çıkış:** Kafa $q_1$'de sola gide gide sol taraftaki boş sembole varırsa `$` kalmamış demektir. Boş sembol geri yazılır, sağa gidilir ve $q_3$'e girilir. Kafa dizginin ilk sembolündedir.

### 8.3 Kısa Geçiş Gösterimi

Hoca bu makineyi çizerken bir kısaltma tanıttı. Okunan sembol yeniden aynen yazılıyorsa ikinci yazmaya gerek yoktur. $1 \to 1, R$ yerine $1 \to R$ yazılabilir. Anlamı "1 oku, 1 yaz, sağa git"tir. Sola gidişte de aynısı geçerlidir.

<!-- BELİRSİZ: Altyazıda kısaltma "one R" diye okunuyor; ok içeren yazım kısa nottan alındı. 02:04:30-02:04:51 aralığında hoca tahtaya "bu yalnız şunun gösterimidir" diye bir şey daha yazıyor, altyazıda okunmuyor. -->

### 8.4 `11` Girişi Üzerinde Çalıştırma

Hoca çalıştırmayı derste yapmadı, `11` girişinin `1111` üretmesini kendi başımıza izlememizi istedi. Aşağıdaki adımlar derste yazılmadı (ara adımlar eklendi), simülasyonla üretildi.

| Adım | Anlık tanım | Ne oldu? |
| :---: | :---: | :--- |
| 0 | $q_011$ | Başlangıç |
| 1 | $\$q_01$ | $1 \to \$$ |
| 2 | $\$\$q_0\square$ | $1 \to \$$ |
| 3 | $\$q_1\$$ | $\square$ görüldü, sola, $q_1$ |
| 4 | $\$1q_2\square$ | `$` 1 oldu, sağa, $q_2$ |
| 5 | $\$q_111$ | Sona 1 eklendi, sola, $q_1$ |
| 6 | $q_1\$11$ | 1 geçilir, sola |
| 7 | $1q_211$ | `$` 1 oldu, sağa, $q_2$ |
| 8 | $11q_21$ | 1 geçilir, sağa |
| 9 | $111q_2\square$ | 1 geçilir, sağa |
| 10 | $11q_111$ | Sona 1 eklendi, sola, $q_1$ |
| 11 | $1q_1111$ | 1 geçilir, sola |
| 12 | $q_11111$ | 1 geçilir, sola |
| 13 | $q_1\square1111$ | 1 geçilir, sola |
| 14 | $q_31111$ | $\square$ görüldü, sağa, $q_3$. Kabul |

> **Ders sonrası not:** Hoca makineyi anlatmaya başlarken "her şeyi 1 ile değiştir" dedi (01:54:52). Doğrusu her 1'i `$` ile değiştirmektir; hemen ardından kendisi de öyle anlattı. Döngüden çıkışı anlatırken "1 de kalmaz" dedi (02:02:55-02:03:28). Doğrusu kafanın **solunda** 1 ve `$` kalmamasıdır; adım 13'te şeritte `1111` durur. Dersin sonunda altyazıda çıkış üç 1 olarak geçiyor (02:05:51), bu büyük olasılıkla altyazı hatasıdır. Doğru çıkış dört 1'dir. Makine $0 \le x \le 40$ aralığında simülasyonla denendi, hepsinde $2x$ tane 1 üretti.

## Dersin Toparlaması

Bu derste Turing makinesini önce örnekle, sonra biçimsel olarak gördük. Makine iki yönde sonsuz bir şerit üzerinde okur, yazar ve iki yöne gider. Geçişi kalmadığında durur. Kabul durumunda durursa girişi kabul eder. $a^nb^n$ örneği, sayaç yerine sembolleri işaretleyerek eşleştirmenin nasıl yapıldığını gösterdi. Biçimsel tarafta yedili tanım, anlık tanım, $\vdash^*$ ve $L(M)$ geldi. Bir dili kabul eden Turing makinesi varsa o dil Turing ile tanınabilirdir.

İkinci bölümde makineyi fonksiyon hesaplayan bir araç olarak kullandık. Tekli gösterimle $x + y$ ve $2x$ makinelerini kurduk. Bir fonksiyon, tanım kümesindeki her $w$ için $q_0w \vdash^* q_ff(w)$ sağlayan bir makine varsa hesaplanabilirdir. İleriye dönük iki bağlantı vardır: Turing ile karar verilebilir diller ve deterministik olmayan Turing makineleri görülecek. Makineler büyüdükçe de durum diyagramı yerine sözde kod ve algoritmalarla düşünülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
