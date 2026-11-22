# Ders 8 Genişletilmiş Notu: Değişkenler ve Akış Diyagramı Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Değişkenler ve Sabitler
- 3. Akış Diyagramı Gösterimi
- 4. Örnek 1: Üç Sayının En Küçüğü
- 5. Akışın Analizle Doğrulanması
- 6. Örnek 2: Üçgenin Türü
- 7. Akışların Verimliliği
- 8. Örnek 3: ATM ve En Az Banknot
- 9. Deterministik ve Deterministik Olmayan Döngüler
- 10. Örnek 4: N Sayının Ortalaması
- 11. Örnek 5: N. Fibonacci Sayısı
- 12. Aynı Problemin Farklı Çözümleri: CISC ve RISC
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Önceki derste bir akış diyagramında hangi parçaların bulunduğu ve bu parçaların hangi şekillerle gösterildiği konuşulmuştu. Bu derste bunun üzerine çalışılır: basit problemler ortaya atılır ve bu problemlerin çözümünü gösteren akış diyagramları birlikte çizilir. Problemler basitten başlayıp yavaş yavaş karmaşıklaşır. Akışa geçmeden önce değişken ve sabit kavramları tekrar ele alınır.

Çizimler normalde tahtada ya da kâğıtta yapılan işlerdir; bu derste hoca tablet üzerinde çizdi. Hoca kendi çizimlerindeki yamukluğun ortamdan kaynaklandığını, öğrencilerden ise düzgün çizim beklediğini söyledi.

## 2. Değişkenler ve Sabitler

### 2.1 Değişken nedir?

Slayttaki tanım (ekrandan, 00:20:00):

- Değişkenler, bir bilgisayar programında başvurulacak ve üzerinde işlem yapılacak bilgiyi saklamak için kullanılır.
- Veriyi açıklayıcı bir adla etiketlemenin bir yolunu sağlar; böylece program hem okuyan için hem de yazan için daha anlaşılır olur.
- Değişkenleri bilgi tutan kaplar gibi düşünmek faydalıdır. Tek amaçları veriyi bellekte etiketlemek ve saklamaktır; bu veri program boyunca kullanılabilir.

Bir yazılım oluşturulurken akışla ilgili bileşenlerin (okuma, ekrana ya da bir yere yazma, kontrol yani `if`, döngüler) dışında temel ihtiyaçlardan biri değişkenlerdir. Daha önce harflerin, sayıların ve görüntünün bilgisayarda nasıl temsil edildiği ve nasıl saklandığı konuşulmuştu. Değişken bu işte yararlanılan temel birimdir.

Hoca değişkeni iki yönden açıkladı. Birinci bakışla değişken elimizdeki veriyi etiketlemektir. Tersinden bakınca bellekte belli bir bölgeyi etiketlemektir: "Bu bellek bölgesindeki veriyi sayı olarak, şu bölgedekini karakter olarak, şu bölgedekini gerçek sayı (floating point) olarak değerlendiriyorum" demenin yolu. Bu etiketler sayesinde "belleğin şurasında şu var, burasında bu var" diyebiliriz. Bunlara değişken denmesinin nedeni, etiketlenen bu bellek alanlarına yeni değerler yüklenebilmesidir.

### 2.2 Sabitler

Program ya da akış içinde doğrudan kullanılan her sayı bir sabittir. Sabit yalnız sayı olmak zorunda değildir; bir karakter de olabilir. `A` karakteri sabit olarak kullanılacaksa etrafına tek tırnak konur (`'A'`); böylece onun bir değişken adı değil sabit olduğu anlaşılır. `A = 5` gibi bir atamada 5'in sabit, `A`'nın değişken olduğu bilinir; atama `A`'ya yapılır.

### 2.3 Sol değer (LValue)

İfadelerde sol taraf "left value", kısaca LValue diye geçer. Derleyicinin vereceği uyarılarda bu terim sık görülür. Sol taraf bir bellek adresi olmak zorundadır; yani bir değişken ya da adreslenebilir bir alan olmalıdır. İşlem yapıldığında sonuç her zaman sola atanır. Dersin sonunda sağ taraf için de "right value" (RValue) terimi kullanıldı (bkz. Bölüm 10.3).

## 3. Akış Diyagramı Gösterimi

Derste kullanılan şekiller kareler üzerinden şöyledir:

- **Başla / Bitir:** içinde START ya da STOP yazan elips.
- **Girdi (okuma):** sol üst köşesi kesik dörtgen; içine okunan değişkenler yazılır (`a, b, c` ya da `N`).
- **İşlem:** dikdörtgen; içine atama yazılır (`AVG = 0`, `AVG = AVG + X`).
- **Karar:** iki ucu sivri, yatay altıgen benzeri kutu; içine koşul yazılır (`a < b`). Solda F (false), sağda T (true) dalı çıkar.
- **Çıktı:** alt kenarı dalgalı belge şekli; içine yazdırılacak değer ya da metin yazılır. Metin sabitleri tırnak içindedir (`'eşkenar'`).
- **For döngüsü:** iki satırlı kutu. Üst satırda solda döngü değişkeninin başlangıç ataması (`I ← 1`), çift çizgiden sonra sağda artım miktarı (`1`); alt satırda bitiş değeri (`N`) yazılır. Döngü gövdesi kutunun sağından çıkar ve sonunda kutuya geri döner; döngü bitince akış kutunun altından devam eder (ekrandan, 02:20:00).
- **Bağlantı noktası:** dallar birleşirken oklar bir noktada buluşur; sayfaya sığmayan akışlarda numaralı daireler kullanılabilir.

## 4. Örnek 1: Üç Sayının En Küçüğü

### 4.1 Problem

Slayttaki ilk örnek: "Please find the minimum of the given three numbers..." (ekrandan, 00:30:00). Üç sayı veriliyor; en küçüğünün hangisi olduğu bulunacak.

### 4.2 Tarif etme ve KISS

Bir öğrenci çözümü bir şampiyona (eleme) sistemine benzetti: rastgele iki sayı karşılaştırılır, kalan sayı "bay geçer", sonra kazananla karşılaştırılır. Hoca bu tarifin anlaşılmaz olduğunu söyledi ve sayılara `A`, `B`, `C` adlarının verilmesini istedi. İkinci bir öğrenci 1, 2, 3 değerleri üzerinden turnuva benzetmesiyle anlatınca hoca yine işi gereksiz karmaşıklaştırdığını belirtti.

> **Hocanın vurgusu:** Bu iş üç adımda çözülebilecek basit bir problemdir; ne kadar karışık tarif edilirse karşı tarafın anlaması o kadar zorlaşır. Mühendislikte bunun adı KISS'tir: "Keep It Simple", daha sert hâliyle "Keep It Stupidly Simple". Değerleri bilmek zorunda değilsiniz; elinizdeki değişkenlerle (A, B, C) tarif etmelisiniz.

Kullanıcıdan üç sayı alınacak; bu sayıları bilgisayarda ifade etmek ve kullanmak için üç değişken gerekir.

### 4.3 Akış

Sayılardan herhangi ikisi karşılaştırılır. Hangi ikisinin seçildiği önemli değildir; sırayla gitmek için `a` ile `b` seçildi. Hoca çizerken önce yanlışlıkla eşitlik yazdı, sonra küçüklük kontrolüne düzeltti.

- `a < b` doğruysa: `a`'nın `b`'den küçük olduğu bilinir, `c` ise bilinmiyor. `a < c` sorulur.
  - `a < c` doğruysa `a` hem `b`'den hem `c`'den küçüktür; sonuç `a`.
  - `a < c` yanlışsa `c ≤ a` ve `a < b`; sonuç `c`.
- `a < b` yanlışsa: küçük olan `b`'dir. Bu sefer `b < c` sorulur.
  - `b < c` doğruysa sonuç `b`.
  - `b < c` yanlışsa sonuç `c`.

Tamamlanmış akış (ekrandan, 01:00:00):

```text
START
  |
[ a, b, c ]                      (girdi)
  |
< a < b >
  F |                        T |
< b < c >                  < a < c >
  F |      T |               F |      T |
 (c)      (b)               (c)      (a)     (çıktı)
   \______/                   \______/
        \________________________/
                   |
                  STOP
```

### 4.4 Eşitlik durumu

**Soru:** Eşitlik durumu da kontrol edilmemeli mi?

**Cevap:** Hoca soruyu "3, 3'ten küçük müdür?" diye sordu. Cevap hayırdır; eşit olmaları sorunun cevabını değiştirmez, soru evet ya da hayır diye cevaplanır. Üç sayı da 3 ise en küçüğün 3 olduğu gerçeği değişmez. Amaç en küçük değeri bulmaktır; bu değerin `a`'da mı, `b`'de mi, `c`'de mi olduğu değil.

**Soru:** False dalında, solda `b < c` doğru olunca sonucun `c` olması gerekmiyor mu?

**Cevap:** En küçük sayı arandığı için `b < c` doğruysa sonuç `b`'dir. Hoca bu tür yapılarda doğruluğun nasıl anlaşılacağını göstermek için analiz yaptı (Bölüm 5).

## 5. Akışın Analizle Doğrulanması

Hoca çizilen akışın doğru olup olmadığını anlamanın yolunun analiz, yani akışı örnek değerlerle adım adım izlemek olduğunu söyledi. Kontroller sırayla numaralandı: 1 numara `a < b`, 2 numara `a < c` (ekrandan, 01:00:00).

- **(1, 2, 3):** Birinci kontrol `1 < 2` doğru, T dalına gidilir. İkinci kontrol `1 < 3` doğru. Sonuç 1.
- **(3, 3, 3):** Birinci kontrol `3 < 3` yanlış, F dalına gidilir. İkinci kontrol `b < c`, yani `3 < 3` yine yanlış. Sonuç `c`, yani 3.
- **(12, 7, 5):** `12 < 7` yanlış, F dalı. `7 < 5` yanlış, F dalı. Sonuç `c`, yani 5.

> **Hocanın vurgusu:** Yaptığınız işin doğru olduğunu gösteren bir örnek, onun doğru olduğunu ispatlamaya yetmez. Ama yanlış olduğunu gösteren tek bir örnek, yanlış olduğunun kesin kanıtıdır. "Şu şartta denedim, çalışıyor" yaklaşımıyla algoritmanıza bakmayın.

Bu akış, 1, 2 ve 3 değerlerinin 27 farklı üçlüsü için python ile denendi; her durumda yerleşik `min` ile aynı sonucu verdi.

## 6. Örnek 2: Üçgenin Türü

### 6.1 Kurallar

Bir üçgenin kenarları `a`, `b`, `c` olsun. Kenarlara göre üçgenler eşkenar, ikizkenar ve çeşitkenar diye adlandırılır; hiçbir kenarı diğerine benzemeyen üçgene çeşitkenar denir. İlk yazılan kural tablosu (ekrandan, 01:05:00):

- `a = b` ve `a ≠ c` ise ikizkenar
- `a = b` ve `b = c` ise eşkenar
- `a ≠ b` ve `b ≠ c` ise çeşitkenar

### 6.2 Eksik kurallar

**Soru:** Çeşitkenarda `a ≠ c` de olması gerekmiyor mu?

**Cevap:** Evet. `a ≠ b` ve `b ≠ c` bilgisi `a` ile `b`'nin, `b` ile `c`'nin farklı olduğunu söyler; ama `a` ile `c` arasındaki durum bilinmez. Yani bu iki kontrol üçgenin çeşitkenar olduğunu söylemeye yetmez. Kurala `a ≠ c` eklenir.

**Soru:** İkizkenar için başka kenar eşitlikleri de yok mu?

**Cevap:** Hoca öğrenciden kuralı "biri, diğeri" diye değil, adım adım yazdırmasını istedi. Sonuçta ikizkenar için iki durum daha eklendi (ekrandan, 01:15:00):

- `a = c` ve `b ≠ c` ise ikizkenar
- `b = c` ve `a ≠ b` ise ikizkenar

> **Hocanın vurgusu:** Bir şeyi tariflerken "biri, diğeri, öbürü, şöylesi, böylesi" diye anlatmayın. Her seferinde kuralı burada yazdığım gibi adım adım söyleyin.

### 6.3 Zincirleme eşitsizlik yazılmaz

**Soru:** Çeşitkenar için `a ≠ b ≠ c` diye yan yana yazılamaz mı?

**Cevap:** Olmaz. Bu matematiksel bir gösterimdir; bilgisayar sisteminde böyle bir koşul yoktur. Hoca tahtada bu yazımın üzerini çizip yanına "Math" yazdı (ekrandan, 01:15:00). En iyi ihtimalle `a ≠ b AND b ≠ c` diye yazılır; bunlar iki ayrı koşuldur. Eşitliği kontrol eden işlem yalnız iki işlenen (operand) alır, üç işlenenle çalışmaz. Farklı koşullar birlikte isteniyorsa mantıksal seviyede bağlanır: iki koşulun birden sağlanması isteniyorsa AND, birinin sağlanması yetiyorsa OR kullanılır.

**Soru:** `a ≠ b` sonucuna `x`, `b ≠ c` sonucuna `y` denip sonra `x` ile `y` karşılaştırılamaz mı?

**Cevap:** Bunun bir anlamı yoktur. `a ≠ b` zaten bir koşuldur (statement); en fazla sonucunu bir değişkene atayabilirsiniz. Bu sonuç bazı dillerde boolean, bazılarında tamsayıdır. Koşullara yeniden ad verip birbirine eşit olup olmadıklarına bakmak yalnız gereksiz karmaşa yaratır; akışta koşulları sırayla kontrol etmek zaten bütün olası sonuçlara ulaştırır.

### 6.4 Akış

Bir öğrenci çözümü adım adım anlattı, hoca çizdi: önce `a, b, c` okunur, `a` ile `b`'nin eşitliğine bakılır. Doğruysa `b` ile `c` karşılaştırılır; o da doğruysa eşkenar, değilse ikizkenar. `a` ile `b` eşit değilse `b` ile `c` karşılaştırılır; eşitse ikizkenar. O da değilse `a` ile `c` karşılaştırılır; eşitse ikizkenar, değilse çeşitkenar. Temize çekilmiş akışta ilk karar `b = a` diye yazılmıştır (ekrandan, 01:25:00 ve 01:30:00):

```text
START
  |
[ a, b, c ]
  |
< b = a >
  F |                                  T |
< b = c >                            < b = c >
  F |              T |                 F |            T |
< a = c >       'ikizkenar'        'ikizkenar'    'eşkenar'
  F |        T |
'çeşitkenar' 'ikizkenar'
  ... bütün dallar birleşir ... STOP
```

Bir öğrenci "farklı durumlarda geçerli olmayabilir" diye itiraz etmişti; akış tamamen çizilip son `a = c` kontrolü görülünce itiraz kalmadı.

Bu akış python ile 1, 2, 3 değerlerinin 27 üçlüsünde denendi; her durumda kenar eşitliklerinden beklenen türü verdi.

### 6.5 Üçgen olma koşulu

**Soru:** Verilen kenarların gerçekten bir üçgen oluşturup oluşturmadığı da kontrol edilmeli değil mi?

**Cevap:** Gerekir ama şu anki dert bu değildir. Problemde "bir üçgenin kenarları veriliyor" denmişse bundan kuşku duyulmaz. Gerçek hayatta bu tür hata ihtimallerini ayrıca ele almak gerekecek; şu an amaç probleme yaklaşmayı ve onu çözmeyi öğrenmektir. Hoca ayrıca soruyu "atıyorum" diye değil, bir örnekle sormanın daha iyi bir yaklaşım olduğunu söyledi.

## 7. Akışların Verimliliği

### 7.1 Sayaç yöntemi

Bir öğrenci farklı bir çözüm önerdi: `a, b, c`'ye ek olarak bir `x` değişkeni tanımlanır. `a` ile `b` eşitse `x` bir artırılır, `a` ile `c` eşitse yine artırılır, `b` ile `c` eşitse yine artırılır. Sonunda `x` 1 ise ikizkenar, 3 ise eşkenar, 0 ise çeşitkenar yazılır. Hoca bunu ekranın sağ tarafına ayrı bir kutuya yazdı ve "sakın bu yola girmeyin" dedi (ekrandan, 01:30:00).

> **Ders sonrası not:** Öğrenci önce "x 2 ise" diye de başladı. Bu yöntemde `x` yalnız 0, 1 ya da 3 olabilir: iki kenar eşitliği sağlanırsa üçüncüsü de kendiliğinden sağlanır, bu yüzden `x = 2` hiç oluşmaz (python ile 27 girdide kontrol edildi).

### 7.2 Karşılaştırma sayısı

Hoca önceki akıştaki yolları tek tek saydı (ekrandan, 01:35:00):

- 1. yol: `b = a` T, `b = c` T, eşkenar. 2 karşılaştırma.
- 2. yol: `b = a` T, `b = c` F, ikizkenar. 2 karşılaştırma.
- 3. yol: `b = a` F, `b = c` T, ikizkenar. 2 karşılaştırma.
- 4. yol: `b = a` F, `b = c` F, `a = c` T, ikizkenar. 3 karşılaştırma.
- 5. yol: `b = a` F, `b = c` F, `a = c` F, çeşitkenar. 3 karşılaştırma.

En iyi durumda 2, en kötü durumda 3 karşılaştırma yapılır. Kaba bir ortalama (ara adım eklendi):

$$\frac{2+2+2+3+3}{5} = \frac{12}{5} = 2{,}4$$

Hoca bunun yalnız fikir vermek için alınmış kaba bir ortalama olduğunu belirtti. Sayaç yönteminde ise her durumda altı kontrol yapılır: üç eşitlik kontrolü ve `x`'in değerine bakan üç kontrol.

### 7.3 İşlemlerin maliyeti

Hoca, ileride donanım derslerinde daha iyi görüleceğini söyleyerek her işlemin aynı sürede bitmediğini anlattı. Karede bir yanda çarpma, mod ve CMP (karşılaştırma), diğer yanda toplama ve çıkarma yazılıdır (ekrandan, 01:35:00).

- Aslında kontroller `if` ile değil, XOR ya da compare (karşılaştırma) gibi komutlarla yapılır. Hoca bu tür işlemlerin işlemci çevrimi (CPU cycle) bakımından daha uzun sürdüğünü söyledi.
- Toplama ve çıkarma çok daha hızlıdır. Toplama örneğin üç birimde yapılıyorsa artırma (increment) işleci bir birimde yapılır.
- Kaydırma (shift) tek çevrimde yapılır. Bir sayıyı ikiye bölmek yerine sağa bir kez kaydırmak aynı sonucu verir; bölme işleciyle örneğin 30 birim süren iş, kaydırmayla bir birimde biter.

Dolayısıyla kontroller karmaşıklığın bir parçasıdır ve kontrol sayısını artırmak bir sorundur.

> **Ders sonrası not:** Çoğu işlemcide karşılaştırma komutunun kendisi büyük olasılıkla bir çıkarma kadar hızlıdır; `if` yapısının asıl ek maliyeti, karşılaştırmanın ardından gelen koşullu dallanmadan kaynaklanır. Hocanın asıl mesajı olan "kontrol sayısını azaltmak verimliliği artırır" fikri yine geçerlidir.

### 7.4 Switch ile iyileştirme

Sayaç yöntemindeki son kontroller `x`'in üç farklı değerde olup olmadığına bakar. Bu, C ya da Java gibi bir dilde `if` yerine `switch` ile yapılabilir; arka planda bir karar tablosu (decision table) gibi, `if` kullanmadan uygulanabilir. Buna rağmen önerilen yöntem her durumda üç karşılaştırma ve ek olarak bu seçim yükünü taşır, bu yüzden verimli değildir.

> **Hocanın vurgusu:** Kâğıda çizdiğiniz akış daha basit görünebilir, ama onu bilgisayara çevirdiğinizde o kadar kolay olmayacaktır. Akışları ortaya koyarken bunların hepsini göz önünde bulundurmalısınız.

## 8. Örnek 3: ATM ve En Az Banknot

### 8.1 Problem

ATM'den 300 TL istendiğinde makine bir 100'lük ve bir 200'lük verebilir; bu, bakkalda bozdurması zor bir paradır. Genel olarak tersi programlanmadıysa birçok ATM istenen parayı en az banknotla ödeyecek şekilde çalışır. Bu davranış simüle edilecektir.

Banknotlar: 200, 100, 50, 20, 10 ve 5 TL. Problem: istenen parayı en az banknotla ödemek (ekrandan, 01:40:00). Karede girdi kutusunda `X`, altında öğrencinin önerisiyle yazılmış `KALAN = X MOD 200 ?` satırı vardır.

### 8.2 Derste konuşulan fikir

Bir öğrenci tutarın en büyük banknota göre modunun alınmasını, sonra kalanla bir alt banknota geçilmesini önerdi.

**Soru:** Mod alındığında 200'e bölümden kalanı değil, içinde kaç tane 200 olduğunu mu verir?

**Cevap:** Hayır, mod işlemi kalanı verir. <!-- BELİRSİZ: Hocanın burada verdiği sayısal örnek altyazıda "25'e göre modunu alsam, bana 20 verir" diye bozuk geçiyor; hangi sayıların kullanıldığı anlaşılamadı. -->

Bunun üzerine öğrenci yaklaşımını düzeltti: önce tutar 200'e tam bölünür ve 200'lük banknot adedi bulunup bir değişkene atanır; sonra mod alınarak kalan bulunur; kalan bir alt banknotla aynı işleme girer ve böyle bir zincir oluşur.

Hoca bu problemi derste quiz olarak verdi ve çözümünü çizmedi. Sorulara verdiği akademik cevaplar şunlardır:

- Çözüm belirli bir tutar (ör. 300 TL) üzerinden değil, genel olarak yapılmalıdır. Üçgen akışı da belirli kenar uzunlukları için değil, `a, b, c` değişkenleriyle çizilmişti.
- Döngü kullanmak serbesttir.
- Girdiye diyagramın dışında bir ad verilemez; diyagram dışı tanımlı değildir. Ara değişkenlere mümkün olduğunca açıklayıcı adlar verilmelidir.

### 8.3 Beklenen çıktı

Hoca daha sonra problemi yeniden tarif etti: istenen tutar örneğin 365 TL ise çıktı "bir 200'lük, bir 100'lük, bir 50'lik, bir 10'luk ve bir 5'lik" gibi olmalıdır. Yani verilen tutarın hangi banknotlarla ödeneceği dökülmelidir. İlk gönderilen çözümlerin bir kısmında `if` kullanımı düzgün olsa da akışın ürettiği sonuç ile istenen sonuç arasında hiçbir bağ olmadığını, bunun da problemi anlama ve ilişkilendirmeyle ilgili temel bir sorun olduğunu söyledi.

## 9. Deterministik ve Deterministik Olmayan Döngüler

Döngüler daha önce iki tipe ayrılmıştı:

- **Deterministik döngüler:** belirli sayıda iterasyon yapılır. Örneğin on sayının toplanması istenirse on sayı bir döngü içinde birbiri üzerine toplanır.
- **Deterministik olmayan döngüler:** kaç adım gidileceği, yani iterasyonun kaçıncı adımda duracağı bilinmez. Önceki derslerde konuşulan Newton'un karekök yönteminde gerçek karekök değerine kaç adımda ulaşılacağı bilinmez. Döngü bir şartın sağlanıp sağlanmadığına göre sürer: iki iterasyon arasındaki fark belli bir epsilon değerinden küçük olunca sonuç yeterli kabul edilir.

## 10. Örnek 4: N Sayının Ortalaması

### 10.1 Akışın kurulması

Belli sayıda sayının ortalaması bulunacaktır. Bu sayı genelde `N` diye gösterilir, çünkü önceden bilinmez: beş, üç ya da beş yüz olabilir.

1. Kaç elemanın okunacağı bilgisi alınır (`N` okunur). Bu bilgi kullanıcıdan, bir dosyadan, terminalden, hatta bir soketten gelebilir; önemli olan dışarıdan okuma yapıldığının belirtilmesidir.
2. Kaç adım gidileceği bilindiği için iş deterministiktir; bu yüzden for döngüsü kullanılır (`I ← 1 || 1`, bitiş `N`).
3. Her adımda dışarıdan yeni bir sayı (`X`) okunur.
4. Okunan sayılar `AVG` değişkeni üzerinde toplanır: `AVG = AVG + X`. Sayılar kendi üzerlerinde değil, ayrı bir değişkende toplanır.
5. Döngüden sonra ortalama bölmeyle bulunur: `AVG = AVG / N`, sonra `AVG` yazdırılır.

Karedeki ilk çizimde bu adımların yanına "Deterministik", "FOR", "kaç eleman okunacak bilgisi alınır", "yeni bir sayı okunuyor" ve "AVG üzerinde bu sayıları topluyoruz" notları düşülmüştür (ekrandan, 02:20:00).

### 10.2 İlklendirme hatası

Hoca ilk akışta bir hata olduğunu gösterdi. `N` dışarıdan okunduğu için ilklendirilmiştir; `X` de dışarıdan okunduğu için ilklendirilmiştir. Ama `AVG = AVG + X` satırına ilk gelindiğinde `AVG`'nin değeri hakkında hiçbir fikir yoktur. `AVG` döngü içinde sürekli değiştiği için, bilinen bir değere (sıfıra) döngüden önce getirilmelidir. Düzeltilmiş akış (ekrandan, 02:25:00):

```text
START
  |
[ N ]                       (girdi)
  |
AVG = 0
  |
+---------+-----+
| I <- 1  ||  1 | <-------------------+
+---------+-----+                     |
|       N       | --> [ X ] --> AVG = AVG + X
+---------------+
  |  (döngü bitince)
AVG = AVG / N
  |
(AVG)                       (çıktı)
  |
STOP
```

İki akış arasındaki temel fark `AVG`'nin ilklendirilmesidir.

### 10.3 LValue ve RValue

Bir atamada sol taraf LValue (left value), sağ taraf RValue (right value) olarak geçer. Bir değişken hiç sol tarafta değer almadan ilk kez sağ tarafta yer alıyorsa sorun vardır, çünkü ilk değeri bilinmez. Önceki örnekte `AVG` hem solda hem sağda yer alıyordu ve ilk göründüğü yer sağ taraftı; solda hiç ilklendirilmediği için değeri belirsizdi.

> **Hocanın vurgusu:** Akışta böyle bir şeyi atlarsanız bunu analiz yaparken fark edip düzeltmelisiniz. Böyle bir hatadan bazı programlama dilleri etkilenmez, bazıları etkilenir; bazılarında da değişkeni nasıl tanımladığınıza bağlıdır. Akışlarınızı çizerken buna dikkat edin.

## 11. Örnek 5: N. Fibonacci Sayısı

### 11.1 Fibonacci dizisi

Fibonacci sayıları bir sayı silsilesidir: her sayı kendinden önceki iki sayının toplamıdır ve dizi 1'den başlar. Karede formül ve dizi şöyledir (ekrandan, 02:30:00):

$$F_{i+1} = F_i + F_{i-1}$$

1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...

Örneğin 5 ile 8 toplanınca 13, 8 ile 13 toplanınca 21, 13 ile 21 toplanınca 34, 21 ile 34 toplanınca 55, 34 ile 55 toplanınca 89, 55 ile 89 toplanınca 144 elde edilir. İstenen: N. Fibonacci sayısını bulan algoritmanın akışını çizmek.

### 11.2 Bir öğrencinin akışı

Bir öğrenci akışı adım adım anlattı; hoca, öğrencinin "sonuçta, dörtgende" gibi belirsiz direktiflerini netleştirmesini isteyerek çizdi.

**Soru (hocanın tepkisi):** Öğrenci önce atamayı "second is equal to first plus second" diye sözle söyledi.

**Cevap:** Hoca bunun bugüne kadar gösterilen biçim olmadığını, atama ve toplamaları akıştaki gösterimle net söylemek gerektiğini belirtti; satır `SEC = FIRST + SEC` diye yazıldı.

Ortaya çıkan akış (ekrandan, 02:40:00):

```text
START
  |
[ N ]
  |
FIRST = 1
SEC   = 1
  |
+---------+-----+
| I <- 3  ||  1 | <------------------------+
+---------+-----+                          |
|       N       | --> SEC   = FIRST + SEC  |
+---------------+     FIRST = SEC - FIRST -+
  |  (döngü bitince)
(SEC)                       (çıktı)
  |
STOP
```

Öğrenci "ben böyle düşünüyorum, siz nasıl düşünüyorsunuz?" diye sorunca hoca şunu söyledi:

> **Hocanın vurgusu:** Bu "ben böyle hissediyorum, böyle düşünüyorum" işi değildir. Oturup analizini yaparsınız ve işin çalışıp çalışmadığını görürsünüz. "Bunun böyle olduğunu düşünüyorum" deyip nedenini anlatabiliyorsanız o zaman makul ve mantıklıdır.

### 11.3 N = 8 için izleme

Dizide sekizinci sayı 21'dir (1, 1, 2, 3, 5, 8, 13, 21). Akış `N = 8` için adım adım izlenir:

1. `N` 8 olarak okunur.
2. `FIRST = 1`, `SEC = 1` olur.
3. `I` 3 olarak atanır ve döngüye girilir. `SEC = FIRST + SEC = 1 + 1 = 2`; `FIRST = SEC - FIRST = 2 - 1 = 1`.
4. `I` 4 olur. `SEC = 1 + 2 = 3`; `FIRST = 3 - 1 = 2`.
5. `I` 5 olur. `SEC = 2 + 3 = 5`; `FIRST = 5 - 2 = 3`. (Hoca burada önce çıkarmayı ters yaptı, sonra düzeltti.)
6. `I` 6 olur, hâlâ 8'den küçük. `SEC = 3 + 5 = 8`; `FIRST = 8 - 3 = 5`.
7. `I` 7 olur. `SEC = 13`; `FIRST = 8`.
8. `I` 8 olur. `SEC = 21`; `FIRST = 13`.
9. `I` 9 olur, `N`'den büyüktür; döngüden çıkılır ve `SEC`, yani 21 yazdırılır.

Karede yazılan izleme tablosu (ekrandan, 02:45:00):

```text
I    FIRST   SEC
-    1       1
3    1       2
4    2       3
5    3       5
6    5       8
7    8       13
8    13      21
9    (çıkış)
```

Sonuç 21'dir; sekizinci Fibonacci sayısı 21 olduğu için akış bu girdide doğrudur. Bu izleme python ile tekrarlandı ve aynı ara değerler elde edildi; akış `N = 1` ile `N = 12` arasında da doğru diziyi verdi.

### 11.4 Uç durum: N = 1

`N = 1` için `FIRST` ve `SEC` 1'e atanır, `I` 3 olur. `I` zaten `N`'den büyük olduğu için döngüye hiç girilmez, `SEC` yani 1 yazdırılır. `N = 2` için de aynısı olur. Öğrenci bu durumları ayrıca `if` ile kontrol etmek yerine for döngüsünün ilklendirmesini uygun seçerek çözmüştür.

> **Hocanın vurgusu:** Bir for döngüsü illa 1'den başlamak zorunda değildir; 3'ten de, 5'ten de başlayabilir. Ürettiğiniz bütün akışları bu şekilde test etmelisiniz.

### 11.5 Yapıyı değiştirmek

Hoca, sonucu değiştirmeden yapıyı değiştirmenin bir yolu olup olmadığını sordu.

**Soru:** Döngüyü 1'den başlatıp içinde bir `C` değişkeni kullansak, `C = A + B`, sonra `B = C`, sonra `A = B` desek?

**Cevap:** Bu sırayla yapılırsa yanlış olur: `B`'ye `C` atandıktan sonra `B`'yi `A`'ya atamanın bir anlamı yoktur, iki değişken aynı değeri alır. Ayrıca döngüyü 1'den başlatmaya da gerek yoktur; değiştirilecek yer orası değildir.

**Soru:** Gövdede `SEC = FIRST + SEC` kalsa, ikinci satır `FIRST = SEC` olsa çıkarmadan kurtulup daha hızlı çalışmaz mı?

**Cevap:** Çıkarmadan kurtulursunuz ama sonuç değişir. 1 ile 1 toplanır, `SEC` 2 olur, `FIRST`'e de 2 yazılır. Sonraki turda 2 ile 2 toplanıp 4, sonra 8, 16 bulunur; akış Fibonacci sayılarını değil 2'nin kuvvetlerini üretir. Öğrencinin çözümünde hesaplanan değer her iki değişkene birden yazıldığı için bilgi kaybolur. Asıl çözümdeki çıkarmanın amacı, bir önceki turda bulunan değeri kaybetmeden arkadaki değişkene geri getirmektir. (Python ile kontrol: `N = 8`'e kadar 2, 4, 8, 16, 32, 64 üretilir.)

> **Hocanın vurgusu:** Hangi işlemi hangi sırayla yaptığınız her şeyi değiştirir. "Çıkarma fazla, atalım" mantığıyla iş yürümez; yapıyı değiştireceksiniz ama sonucu değiştirmeyeceksiniz.

### 11.6 Üç değişkenle kaydırma

Hoca formülü hatırlattı: her seferinde bir sayı ile bir önceki sayı toplanıp bir sonraki bulunur. 1 ile 1 toplanıp 2, 1 ile 2 toplanıp 3, 2 ile 3 toplanıp 5, 3 ile 5 toplanıp 8 bulunur; her adımda sayılar bir sola kaydırılır (ekrandan, 02:50:00 ve 02:55:00). Değerlere `a`, `b`, `c` denirse her adımda `a` ile `b` toplanıp `c` bulunur; bir sonraki adımda önceki turun `b` ve `c` değerleri toplanmalıdır. Bunun için `b`'deki değer `a`'ya, `c`'deki değer `b`'ye aktarılır:

```text
c = b + a
a = b
b = c
```

İzleme (ekrandan, 02:55:00):

- İlk tur: `c = 1 + 1 = 2`, `a = 1`, `b = 2`.
- İkinci tur: `c = 2 + 1 = 3`, `a = 2`, `b = 3`.

Bu yapıda toplama-çıkarma çifti yerine bir toplama ve iki atama vardır. Python ile kontrol edildi: ilk 12 terimde iki yapı da aynı diziyi üretir.

## 12. Aynı Problemin Farklı Çözümleri: CISC ve RISC

Hangi çözümün daha iyi olduğu duruma göre değişir. Hoca bunu bilgisayar mimarisiyle açıkladı; konunun ileride daha ayrıntılı işleneceğini söyledi.

- **CISC (Complex Instruction Set Computer):** Bir işlemin işlenenleri (operand) yazmaç-yazmaç, yazmaç-bellek, bellek-sabit (immediate), yazmaç-sabit olabilir; bellek-bellek her zaman olmayabilir. Yani bir toplama işlemine iki yazmaç değeri ya da bir yazmaç ve bellekteki bir değer verilebilir. Bu, uygulama açısından bazı yönlerden daha kolay olabilir, ama arka plandaki hız olarak çok daha yavaş çalışır. Karede CISC altında `R R`, `R B`, `B B` (yıldızlı), `R I`, `B I` çiftleri yazılıdır (ekrandan, 02:55:00).
- **RISC (Reduced Instruction Set Computer):** İşlem yalnız yazmaç-yazmaç (`R, R`) üzerinden yapılır. Değer bellekteyse önce bellekten yazmaca yüklenir (load), diğer işlenen de bellekteyse o da yüklenir. İkisi de yazmaçtayken işlem çok hızlı yapılır, sonra sonuç belleğe geri yazılır (store).

Fibonacci için çizilen iki yapı, hangi mimaride ve hangi ortamda çalışıldığına göre birbirinden daha iyi ya da daha kötü olabilir. Bunun için alt katmanı, yani kodun nerede çalışacağını bilmek gerekir.

> **Hocanın vurgusu:** Bu örneğin amacı birinin daha iyi olduğunu göstermek değildir. Bir sorunun birden fazla çözümü olabileceğini ve duruma, yerine göre bunların birbirinden daha verimli ya da daha kötü olabileceğini göstermektir.

## Örnek Sorular

**1. (ekrandan, 00:30:00)** Verilen üç sayının en küçüğünü bulan akış diyagramını çizin.

Çözüm (derste verildi): Bölüm 4.3'teki akış. `a < b` doğruysa `a < c` sorulur (T: `a`, F: `c`); yanlışsa `b < c` sorulur (T: `b`, F: `c`). (1, 2, 3) için 1, (3, 3, 3) için 3, (12, 7, 5) için 5 bulunur.

**2. (ekrandan, 01:20:00)** Kenarları `a`, `b`, `c` olan bir üçgenin çeşitkenar, eşkenar ya da ikizkenar olduğunu bulan akışı çizin.

Çözüm (derste verildi): Bölüm 6.4'teki akış. `b = a` ve `b = c` ise eşkenar; `b = a` ve `b ≠ c` ise ikizkenar; `b ≠ a` ve `b = c` ise ikizkenar; `b ≠ a`, `b ≠ c`, `a = c` ise ikizkenar; hiçbiri eşit değilse çeşitkenar.

**3. (derste sözlü, 01:29:55)** Üçgen akışında en iyi, en kötü ve ortalama kaç karşılaştırma yapılır? Sayaç yöntemi kaç kontrol yapar?

Çözüm (derste verildi): En iyi 2, en kötü 3, kaba ortalama $12/5 = 2{,}4$. Sayaç yöntemi her durumda 6 kontrol yapar.

**4. (ekrandan, 01:40:00)** Banknotlar 200, 100, 50, 20, 10 ve 5 TL'dir. İstenen tutarı en az banknotla ödeyen ve her banknottan kaç tane verileceğini yazdıran akışı çizin. (Derste quiz olarak verildi.)

> **Çözüm (derste verilmedi):** Derste konuşulan fikir doğrultusunda, `X` okunur; sırayla her banknot değeri `B` için `ADET = X / B` (tam bölme) hesaplanıp yazdırılır ve `X = X MOD B` ile kalan bulunur. Banknotlar büyükten küçüğe işlenir. 365 TL için sonuç: bir 200'lük, bir 100'lük, bir 50'lik, sıfır 20'lik, bir 10'luk, bir 5'lik (5 banknot). 310 TL için bir 200'lük, bir 100'lük ve bir 10'luk. Bu sonuçlar python ile kontrol edildi. 5'in katı olmayan tutarlarda en sonda bir kalan artar; problemde bu durum ele alınmadı.

**5. (ekrandan, 02:20:00)** Dışarıdan okunan `N` sayının ortalamasını bulan akışı çizin. Aşağıdaki akıştaki hata nedir: `N` oku, for `I ← 1 || 1` .. `N`: `X` oku, `AVG = AVG + X`; sonra `AVG = AVG / N`, `AVG` yazdır.

Çözüm (derste verildi): `AVG` ilklendirilmemiştir; ilk kez `AVG = AVG + X` satırının sağ tarafında kullanıldığı için değeri belirsizdir. `N` okunduktan sonra, döngüden önce `AVG = 0` eklenir.

**6. (ekrandan, 02:30:00)** N. Fibonacci sayısını bulan algoritmanın akışını çizin.

Çözüm (derste verildi): `FIRST = 1`, `SEC = 1`; for `I ← 3 || 1` .. `N`: `SEC = FIRST + SEC`, `FIRST = SEC - FIRST`; döngüden sonra `SEC` yazdırılır. `N = 8` için 21, `N = 1` ve `N = 2` için 1 verir.

**7. (derste sözlü, 02:45:37)** Fibonacci akışının gövdesinde `FIRST = SEC - FIRST` yerine `FIRST = SEC` yazılırsa ne olur?

Çözüm (derste verildi): İki değişken aynı değeri alır, bilgi kaybolur. Akış 2, 4, 8, 16, ... diye 2'nin kuvvetlerini üretir.

**8. (derste sözlü, 02:43:31)** Fibonacci akışında sonucu değiştirmeden yapıyı nasıl değiştirebilirsiniz?

Çözüm (derste verildi): Üç değişkenle kaydırma: `c = b + a`, `a = b`, `b = c`. Çıkarma işlemi ortadan kalkar; hangi yapının daha verimli olduğu mimariye (CISC/RISC) bağlıdır.

## Dersin Toparlaması

Bu derste değişkenin bellekte etiketlenmiş ve değeri değiştirilebilen bir alan olduğu, sabitin doğrudan yazılan değer olduğu ve atamanın sol tarafının adreslenebilir bir alan olması gerektiği tekrar edildi. Ardından akış diyagramı gösterimiyle beş problem ele alındı: üç sayının en küçüğü, üçgenin türü, ATM'de en az banknot, N sayının ortalaması ve N. Fibonacci sayısı. Her örnekte çözümün değişken adlarıyla, adım adım ve basit biçimde (KISS) tarif edilmesi, akışın örnek ve uç değerlerle izlenerek doğrulanması üzerinde duruldu. Matematikteki zincirleme koşulların bilgisayarda AND/OR ile ayrı koşullara bölündüğü, döngüde kullanılan toplam değişkeninin önceden ilklendirilmesi gerektiği gösterildi.

Dersin ikinci önemli fikri verimlilikti: aynı problemin farklı akışları farklı sayıda kontrol ve farklı maliyette işlem gerektirir. Üçgen akışı ortalama 2,4 karşılaştırma yaparken sayaç yöntemi her durumda altı kontrol yapar. Fibonacci için toplama-çıkarma kullanan yapı ile üç değişkenle kaydırma yapan yapı aynı sonucu verir; hangisinin daha iyi olduğu CISC ya da RISC gibi alttaki mimariye bağlıdır. ATM problemi derste çözülmedi; bir sonraki derste bu akışın üzerinden geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
