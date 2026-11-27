# Ders 6 Genişletilmiş Notu: Hashing: Hash Fonksiyonları ve Çakışma Çözümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arama işlemleri ve karmaşıklıkları
- 2. Hashing'in temel fikri
- 3. Hash fonksiyonunun özellikleri ve temel sorular
- 4. Yaygın hash fonksiyonları
- 5. Doğum günü paradoksu ve çakışma olasılığı
- 6. Farklı veri türlerinden key üretme
- 7. Çakışma çözümleri: açık adresleme
- 8. Çakışma çözümleri: ayrı zincirleme
- 9. Evrensel hashing
- 10. Doluluk oranı ve başarısız arama
- Örnek Sorular

## 1. Arama işlemleri ve karmaşıklıkları

Hashing, algoritma analizi açısından önemlidir çünkü zaman karmaşıklığını çok belirgin biçimde iyileştirme imkânı verir. Arama (search), sürekli yaptığımız bir işlemdir: bir sorgulama yapar, bir veri ararız. Verilerin çoğu bir nesne dizisi gibi saklandığı için dizi üzerinde düşünmek yeterlidir.

Hoca bilinen arama yöntemlerini şöyle sıraladı (ekrandan, 00:10:00):

- **Doğrusal (sıralı) arama:** Sıralı ya da sırasız bir dizide uygulanabilir.
- **İkili arama:** Dizinin sıralı olmasını gerektirir.
- **İnterpolasyon araması:** İkili aramanın iyileştirilmiş hâlidir. Her seferinde tam ortadaki elemana bakmak yerine daha uygun bir noktaya bakar. Dizinin sıralı ve düzgün dağılımlı (uniform distribution) olmasını bekler.
- **İkili arama ağacı (BST):** Veriler bir ağaca yerleştirilerek aranır.
- **Hashing:** Bu dersin konusu.

### 1.1 Karşılaştırma tablosu

Arama (S), ekleme (I) ve silme (D) temel işlemlerdir. Hoca tabloyu öğrencilerle birlikte doldurdu (ekrandan, 00:15:00):

| Yapı | En kötü S | En kötü I | En kötü D | Ortalama S | Ortalama I | Ortalama D |
|---|---|---|---|---|---|---|
| Sıralı (doğrusal) arama | $n$ | 1 | $n$ | $n/2$ | $n$ | $n/2$ |
| İkili arama | $\log N$ | $N$ | $N$ | $\log N$ | $N/2$ | $N/2$ |
| BST | $N$ | $N$ | $N$ | $\log N$ | $\log N$ | $\log N$ |
| Dengeli ağaç | $\log N$ | $\log N$ | $\log N$ | $\log N$ | $\log N$ | $\log N$ |

<!-- BELİRSİZ: dengeli ağacın ortalama sütunu karede tamamlanmamıştı; hoca bu satır için "hemen hemen çoğu işlem log n" dedi. -->

Doğrusal aramada en kötü durumda $n$ elemana bakmak gerekir; aranan eleman yoksa da $n$ elemana bakılıp bulunamadığı anlaşılır. Ekleme dizinin sonuna (ya da bağlı listenin başına) doğrudan yapılabildiği için 1 adımdır. Silmede ise önce silinecek eleman bulunmalıdır; bu yüzden $n$ adım gerekir.

**Soru:** Eklemede de bir yer bulmak gerekmez mi? **Cevap:** Sıralı ekleme kastediliyorsa gerekir, ama doğrusal aramada sıralı olma şartı yoktur. Eleman istenen bir yere doğrudan eklenebilir, yer aramaya gerek kalmaz.

İkili aramada arama $\log_2 n$ adımdır. Ekleme yapılırken dizinin sıralılığı bozulmamalıdır; eklenecek yer bilinmediği için en kötü durumda dizinin sonuna kadar gitmek gerekir. Silme de aynı şekildedir.

BST'de bir düğümden büyük değerler sağa, küçükler sola gider (tersi de kurgulanabilir, ama genel kabul budur). 4, 5, 6, 7, 8 değerleri sırayla eklenirse her eleman bir öncekinin sağına gelir ve ağaç bir bağlı listeden farksız hâle gelir (ekrandan, 00:15:00). Ağaç dengesizse arama, ekleme ve silme $n$ adıma çıkar. Ağaç dengeli olsaydı bu işlemler $\log n$ adımda, dengeyi bozmadan yapılabilirdi. BST'nin ortalama durumu, ağacın dengeye yakın olduğu durumdur.

> **Ders sonrası not:** Tabloda doğrusal aramanın en kötü eklemesi 1, ortalama eklemesi $n$ yazıldı. Bu iki değer birbiriyle tutarsız görünüyor. Büyük olasılıkla ortalama sütunda, aynı key'in tekrar eklenmediğini kontrol eden (önce arayan) ekleme kastedilmiştir.

Bu yapıların en iyisi bile $\log n$ düzeyindedir. Veri sayısı çok büyük olduğunda bu bile yetersiz kalabilir. Hashing, bazı durumlarda arama, ekleme ve silmeyi tek adımda yapma imkânı verir.

## 2. Hashing'in temel fikri

Hashing'i günlük hayatta farkında olmadan sık kullanırız. Örneğin bir sisteme giriş yaparken kullanıcı adı ile parolanın eşleştirilmesi bir veri tabanı sorgusuyla yapılır. Milyonlarca kayıt varsa bunları tek tek kontrol etmek ya da ikili arama için sıralı tutmak sorunludur. Hashing burada çok daha hızlı bir çözüm sunar: kayıtların bulunduğu bir uzay vardır ve bu kayıtlara erişmek için bir indeksleme, bir haritalama yapılır.

Derste örnekler genellikle tamsayı dizileri üzerinden verildi. Ama kayıt bir nesne gibi düşünülebilir: örneğin bir kitap nesnesinin birçok bilgisi ve bir de indis bilgisi vardır. İndisten bellek adresine gidilip nesnenin bütün bilgilerine erişilir. Bazen aynı indis değerini birden fazla kayıt gösterebilir; bu durumda o indisin alt alanlarından her ikisine de erişmek gerekir.

### 2.1 Doğrudan adres tablosu

En basit yol **doğrudan adres tablosudur** (direct address table). Dizilerde `a[3]` ya da `a[8]` gibi bir elemana doğrudan erişiriz (ekrandan, 00:20:00). Bunun statik olması gibi sorunları vardır. Hashing'de de benzer şekilde veri bir fonksiyona verilir, elde edilen sonuç bir indis (adres) olur ve veriye bu adresle erişilir.

### 2.2 Genel blok şeması

Hashing, bir $\langle key, value\rangle$ eşleştirmesidir (ekrandan, 00:20:00). Value bir nesnedir, key ise o nesneyi ayırt eden tekil tanımlayıcıdır (unique identifier). Şema şöyledir:

```text
key --> [hash fonksiyonu] --> adres --> hash tablosu (ilgili hücre)
```

Key her türlü veriden elde edilebilen yeni bir veridir. Önemli olan tekil olması ve çakışmayı (collision) en aza indirmesidir. Öğrenci numarası, vatandaşlık numarası gibi tekil kimlikler sıkça kullanılır, ama yalnızca bunlarla sınırlı değildir: bir kitabın ya da kişinin adı da tekil hâle getirilecek biçimde tasarlanıp hash fonksiyonundan geçirilebilir.

Hocanın örneğinde bir öğrenci numarası hash fonksiyonuna verildi ve fonksiyon indis olarak 3 üretti. Hash tablosu 0'dan başlar; numara 3 numaralı hücrede saklanır. Aramada aynı numara yine aynı fonksiyondan geçirilerek 3 numaralı hücreye gidilir.

## 3. Hash fonksiyonunun özellikleri ve temel sorular

Hash fonksiyonu, ikili arama ağacına ya da ikili aramaya gerek bırakmayacak kadar iyi çalışmalıdır. Ağaç kurmak gibi maliyetlerden kaçınılmalıdır. Hash fonksiyonu onlardan daha maliyetliyse hashing'in daha iyi olduğu iddia edilemez. Hoca istenen özellikleri şöyle sıraladı:

- **Hesaplaması ve gerçeklemesi kolay (easy to compute, easy to implement):** Getirdiği karmaşıklık diğer algoritmaların karmaşıklığını geçmemelidir.
- **Tutarlı (consistent):** Aynı key'e uygulandığında hep aynı indisi (örnekteki 3) vermelidir. Kararsızlık varsa sorun vardır.
- **Düzgün adres üretimi (uniform address generation):** Bir key için üretilen indis, mümkünse başka bir key için üretilmemelidir. Üretilirse felaket değildir, çözümleri vardır, ama maliyet artar.

Düzgün dağılım için genellikle **asal sayılar** kullanılır. Asal sayılar bölenleri ve modüler aritmetik açısından daha az çakışma üretir. Örneğin tablo boyutu $M = 10$ seçilir ve mod işlemi yapılırsa 3, 13 ve 23 aynı indisi (3) üretir.

Hoca hashing'in üç temel sorusunu yazdı:

- Tablo ne kadar büyük olmalı? (How big should the table be?)
- Hash fonksiyonu nasıl seçilmeli? (How to select a hash function?)
- Çakışma problemi nasıl aşılmalı? (How to overcome collision problem?)

Tablo boyutu için $M$, ilgilenilen eleman sayısı için $N$ kullanılır. Amaç ekleme, silme ve aramanın mümkünse $O(1)$ süreye inmesidir.

## 4. Yaygın hash fonksiyonları

İki temel yaklaşım vardır: bölme yöntemi (division method) ve çarpma yöntemi (multiplication method). İkisi de bir indis üretir ve veri bu indiste saklanır.

### 4.1 Bölme yöntemi

Bu yöntemde key'in $M$'ye göre modu alınır (ekrandan, 00:30:00):

$$h(key) = key \bmod M$$

Örnek: tablo boyutu $M = 7$ (hücreler 0-6).

- $key = 25$: $25 \bmod 7 = 4$ ($3 \cdot 7 = 21$, kalan 4). 25, 4 numaralı hücreye yazılır. Burada saklanan şey key de olabilir, value da.
- $key = 2$: $2 \bmod 7 = 2$. 2, 2 numaralı hücreye yazılır.
- 25 aranmak istendiğinde 25 aynı fonksiyondan geçirilir, 4 üretilir ve 4 numaralı hücredeki veri alınır. İstenirse değiştirilir ya da silinir. Aramada 0. ya da 1. elemana tek tek bakılmadı; en fazla bir bölme ve bir dizi erişimiyle, neredeyse $O(1)$ adımda iş bitti.
- $key = 4$: $4 \bmod 7 = 4$. Ama 4 numaralı hücre 25 tarafından kullanılıyor. **Çakışma** oluştu.

Çakışma hashing'in dezavantajlarından biridir; çözümleri ilerleyen bölümlerdedir. Bölme yöntemi, "kolay hesaplanmalı" şartını sağlayan basit bir fonksiyondur.

### 4.2 Çarpma yöntemi

$0 < A < 1$ aralığında sabit bir $A$ seçilir (ekrandan, 00:35:00):

$$h(key) = \left\lfloor M \cdot \big((key \cdot A) \bmod 1\big) \right\rfloor$$

Key önce $A$ ile çarpılır, sonucun 1'e göre modu (yani kesirli kısmı) alınır, $M$ ile çarpılır ve tabana yuvarlanır. Hoca formülü önce "$M$ ile çarp, sonra mod 1 al" diye yazdı, örneği çözerken düzeltti: mod 1 işlemi $key \cdot A$ çarpımına uygulanır.

Örnek kitaptan alındı: $M = 10000$, $key = 123456$, $A = \frac{\sqrt5 - 1}{2} \approx 0.61803$ (altın oranla ilişkili sabit; ispatlarına girilmedi).

- $123456 \cdot A = 76300.0041151\ldots$
- $(123456 \cdot A) \bmod 1 = 0.0041151\ldots$
- $10000 \cdot 0.0041151 = 41.151$
- $\lfloor 41.151 \rfloor = 41$

Yani 123456 key'i, 10000 hücreli tabloda 41 numaralı adrese yazılır.

**Soru:** 1'e göre mod almak bir şeyi değiştirir mi? **Cevap:** Ondalıklı bir sayı elde edildiği için değiştirir; mod 1 kesirli kısmı verir.

> **Ders sonrası not:** Tahtadaki ara değer ($76300.0041151$), $A$'nın tam değeriyle hesaplanmıştır. $A$ beş basamakta kesilip $0.61803$ alınırsa çarpım $76299.51168$ olur ve sonuç 41 değil 5116 çıkar (python ile doğrulandı). Bu yöntemde $A$'nın yeterli duyarlıkla alınması önemlidir.

Bölme yöntemine göre çarpma yöntemi dağılımı biraz daha iyileştirir, düzgünleştirir ve çakışmayı azaltır. Buna karşılık bir çarpma, bir mod ve tekrar bir çarpma içerdiği için işlem yükü artar.

## 5. Doğum günü paradoksu ve çakışma olasılığı

Çakışma olsa da veri yine yerleşmelidir; adres dolu diye eleman atılmaz, alternatif üretilir. Hoca bunu e-posta hesabı açarken "bu kullanıcı adı alınmış" denip alternatif önerilmesine benzetti. Çakışma olasılığını anlamak için **doğum günü paradoksu** kullanılır.

İki kişinin farklı günlerde doğma olasılığı (bir yıl 365 gün kabul edilerek) $\frac{364}{365}$'tir.

**Soru:** Olasılık $1/365$ ya da haftanın günlerine göre $1/7$ mi? **Cevap:** Doğum günü yılın günüdür. Aynı günde doğma değil farklı günlerde doğma soruluyor: biri bir günde doğmuşsa diğerinin farklı günde doğma olasılığı $364/365$'tir.

Üçüncü kişi için $363/365$ ile çarpılır. $k$ kişinin hepsinin farklı günlerde doğma olasılığı (ekrandan, 00:40:00):

$$\frac{364}{365} \cdot \frac{363}{365} \cdots \frac{365-(k-1)}{365}$$

Bunun 1'den farkı, en az iki kişinin aynı günde doğma olasılığıdır. Aynı mantık boyutu $M$ olan hash tablosuna $k$ key eklemeye uygulanır. Çakışmama olasılığı

$$\frac{M-1}{M} \cdot \frac{M-2}{M} \cdots \frac{M-(k-1)}{M} \approx e^{-k(k-1)/(2M)}$$

ile yaklaşık olarak bulunur. Çakışma olasılığını doğrudan bulmak zordur; çakışmama olasılığının 1'den farkı alınır:

$$P(\text{çakışma}) \approx 1 - e^{-k(k-1)/(2M)}$$

> **Ders sonrası not:** Hoca üsteki ifadeyi "$k$ çarpı $k-1$ bölü $m$" diye söyledi; yaygın yaklaşımda paydada $2M$ bulunur. Altyazıda adres uzayı $2^{30}$ olarak geçiyor, ama verilen 77.163 değeri $M = 2^{32}$ (yaklaşık 4 milyar, "4 GB'lık" alan) ile uyuşur: $\sqrt{2 \ln 2 \cdot 2^{32}} \approx 77163$. Bu yüzden büyük olasılıkla $2^{32}$ kastedilmiştir (python ile doğrulandı).

Hocanın verdiği istatistiğe göre yaklaşık 4 milyar adreslik bir alanda hashleme yapılırken 77.163. eklemeden sonra çakışma olasılığı %50'ye, yaklaşık 250.000. eklemeden sonra neredeyse %100'e çıkar ($1 - e^{-250000^2/2^{33}} \approx 0.9993$). Yani adres uzayı çok büyük olsa bile çakışma kaçınılmazdır.

## 6. Farklı veri türlerinden key üretme

Şimdiye kadar key hep sayıydı. Nesne yönelimli sistemlerde veriler tamsayı, kayan noktalı sayı, string ve Boolean gibi ilkel türlerden oluşur. Boolean 0 ve 1 olduğu için o da tamsayıdır. Bu türlerden key üretmek gerekir (ekrandan, 00:45:00).

### 6.1 Tamsayı ve kayan noktalı sayı

Tamsayı doğrudan kullanılır. Kayan noktalı sayı bir tamsayıya çevrilir:

- $x = 35.780$ gibi bir sayı için: $\text{round}(x \cdot 10000) \bmod m$.
- $0 \le x \le 1$ ise: $\text{round}(x \cdot m)$.

### 6.2 String

Stringler karakterlerden oluşur. "ELMA", "MALE" ve "ALME" stringlerinin ASCII kodları toplanıp mod alınırsa, toplamanın değişme özelliği yüzünden hepsi aynı sonucu verir ($E + L + M + A = M + A + L + E$). Bu çakışma demektir.

Hoca öğrencilere ne önerdiklerini sordu. Bir öğrenci karakterin konumunu hesaba katmayı önerdi; hoca bunu onayladı. Karakter, bulunduğu konuma göre farklı bir sayıyla çarpılırsa "E"ler birbirine karışmaz ve çakışma olasılığı azalır.

İlk yöntemde $i = 0$'dan $s-1$'e kadar her karakter için hash değeri bir sabitle çarpılır, karakterin sıra değeri (order) eklenir ve tablo uzunluğuna göre mod alınır:

$$h = (h \cdot c + \text{ord}(s_i)) \bmod m$$

<!-- BELİRSİZ: bu formül karede küçük önizlemede kaldı; sabitin adı ve tam yazımı altyazıdan kuruldu. -->

Bunun daha iyi hâli **Horner yöntemidir**. Asal bir $R$ sayısı seçilir (Java'da 31):

$$key = R^{L-1} \cdot str[0] + R^{L-2} \cdot str[1] + \dots + R^{0} \cdot str[L-1]$$

Burada $L$ stringin uzunluğudur. Sonra $hash = key \bmod M$ alınır. Karakteri sayıya çevirmek için örneğin `str[0] - 'A'` kullanılır; buna 1 eklenirse karakterin alfabedeki sırası elde edilir ('C' için 3).

> **Ders sonrası not:** Hoca 'C' karakterinin ASCII kodunu 68 dedi; doğrusu 67'dir ('A' = 65, 'D' = 68). `'C' - 'A' + 1 = 3` sonucu değişmez.

Hoca kodu şöyle yazdı (ekrandan, 00:50:00; karede döngü gövdesi `hash = R*hash+` diye kalmıştı, kalan kısım sözlü anlatımdan):

```c
length = strlen(s);
hash = 0;
for (i = 0; i < length; i++)
    hash = R * hash + (s[i] - 'A' + 1);
hash = hash % M;
```

Önce parantez içindeki karakter değeri hesaplanır, sonra hash $R$ ile çarpılıp eklenir. Hash değeri döngüde sürekli güncellenir, döngü bitince $M$'ye göre modu alınır. Bu, Horner formülünü üsleri ayrı ayrı hesaplamadan uygular. Hoca kendi yöntemimizi de tasarlayabileceğimizi söyledi (örneğin ikinci karakterin karesini alıp bir sayıyla çarpmak): bir yöntem çakışmayı iyi azaltıyorsa iyi bir yöntemdir.

> **Ek bilgi (derste anlatılmadı):** Bu kodla ($R = 31$, mod öncesi) "ELMA", "MALE" ve "ALME" için sırasıyla 160891, 388621 ve 41731 elde edilir; ASCII toplamı ise üçünde de 287'dir (python ile doğrulandı). Uzun stringlerde ara değer taşmasın diye mod işlemi her adımda da uygulanabilir.

### 6.3 Bileşik key

Doğum tarihi gibi birden fazla alandan oluşan key'ler (compound key) de vardır. Örneğin gün 31, yıl 2000 olan bir tarihte gün $R$ ile, ay $R^2$ ile, yıl $R^3$ ile çarpılıp toplanır ve sonra $\bmod M$ alınır. Kuvvetler farklı biçimde de dağıtılabilir (gün $R^3$, yıl $R$ gibi).

<!-- BELİRSİZ: örnek tarihin ay değeri altyazıda 07 ve 08 arasında karıştı. -->

Bütün bu tekniklerin amacı çakışmayı azaltmaktır. Ama hepsinde çakışma olasılığı vardır. Bundan sonraki konu, çakışma olduğunda ne yapılacağıdır.

## 7. Çakışma çözümleri: açık adresleme

Hash fonksiyonunun verdiği yer doluysa ne yapılabilir? Bir öğrenci bir sonraki yere, o da doluysa ondan sonrakine bakmayı önerdi. Hoca birer birer artırmak yerine farklı adımlarla (bir, iki, dört, sekiz sonrası gibi) bakmanın da mümkün olduğunu ekledi. Amaç, dizi tamamen dolmadıkça elemanı bir şekilde boş bir yere yerleştirmek ve beklemeyi azaltmaktır.

İki temel teknik vardır (ekrandan, 01:10:00):

- **Açık adresleme (open addressing)**, diğer adıyla closed hashing.
- **Ayrı zincirleme (separate chaining)**, diğer adıyla open hashing.

### 7.1 Parolalar ve hash fonksiyonları

Hoca açık adreslemeye geçmeden bir soru sordu: Bir sitede parolanızı unuttuğunuzda neden eski parola size gönderilmiyor da sıfırlama bağlantısı geliyor?

Bir öğrenci sistemin parolayı tutmadığını söyledi. Hoca güvenliğin yanında algoritmik karmaşıklığın da işin içinde olduğunu anlattı. Parola açık metin olarak saklansaydı sistem yöneticisi onu görebilirdi; parolanın sahibi dışında kimse ona erişememelidir. Bu yüzden parola kayıt sırasında bir hash fonksiyonundan geçirilir (MD5 ve 512 bitlik fonksiyonlar gibi). Hash'lenmiş değerin geri çözülmesi algoritmik olarak çok zordur; bu yüzden unutulan parola geri getirilmez, sıfırdan yenisi oluşturulur. Bu fonksiyonlar farklı kullanıcıların parolalarının çakışmamasına da dikkat eder.

> **Hocanın vurgusu:** Parolanızı unuttuğunuzda eski parolanızı size e-postayla geri gönderen bir sistem parolayı açık metin olarak saklıyordur. Böyle sitelerde kullandığınız parolayı banka gibi önemli hesaplarda kullanmayın.

### 7.2 Doğrusal yoklama (linear probing)

Key'in yeri doluysa bir sonraki hücreye, o da doluysa ondan sonrakine bakılır. Sona gelinirse başa dönülür. Bütün hücreler doluysa dizi dolmuştur ve ekleme yapılamaz. $i$, kaçıncı denemede yerleştirildiğini gösterir; ilk deneme $i = 0$'dır (ekrandan, 01:15:00):

$$hash(key, i) = (h'(key) + i) \bmod M$$

Örnek: $M = 7$, tabloda önceden 5 değeri 5 numaralı hücrede bulunuyor. Boş hücreler başlangıçta $-1$ gibi bir değerle doldurulur ki boş olup olmadığı anlaşılsın.

- **12 ekleme:**
  - $i = 0$: $12 \bmod 7 + 0 = 5$. Hücre 5 dolu, çakışma.
  - $i = 1$: $(12 + 1) \bmod 7 = 6$. Alternatif yazım: $(12 \bmod 7 + 1) \bmod 7 = 6$. Hücre 6 boş, 12 buraya yazılır.
- **19 ekleme:**
  - $i = 0$: $19 \bmod 7 + 0 = 5$. Dolu.
  - $i = 1$: $(19 + 1) \bmod 7 = 6$. Dolu.
  - $i = 2$: $(19 + 2) \bmod 7 = 0$. Boş, 19 buraya yazılır.

Son durumda tablo: hücre 0'da 19, hücre 5'te 5, hücre 6'da 12 (ekrandan, 01:15:00).

Hoca, ilk modu aldıktan sonra her adımda tekrar mod almanın gereksiz olduğunu, $(key + i) \bmod M$ biçiminin daha düzgün olduğunu söyledi. Adres üretimi şöyle özetlenebilir: key'den bir adres bulunur; adres dolu olduğu sürece `adres = (adres + 1) mod M` ile güncellenir. Birer birer artırmaya doğrusal yoklama denir. "Probe" bir şeyi araştırmak, deniz altında maden aramak gibi yoklamak anlamındadır.

### 7.3 Arama, ekleme ve silme

Çakışma olunca arama da değişir. İlk eleman $O(1)$'de yerleşti, ama 19 için üç deneme yapıldı. Tablo tamamen dolu olsaydı en kötü durum $O(n)$'e giderdi. Arama döngüsü şöyledir (ekrandan, 01:20:00):

```text
i = 0
h = key mod M
while (i < M AND hash[h] != key AND hash[h] != NULL)
    i = i + 1
    h = (h + 1) mod M
```

Döngü üç durumda biter: aranan key bulunur, boş bir hücreye gelinir ya da tablonun tamamı gezilir. Ekleme için döngüden sonra şu kontroller yapılır:

- $i == M$ doğruysa tablo doludur, ekleme yapılamaz.
- Değilse ve `hash[h] == NULL` ise key bu adrese yazılır: `hash[h] = key`.
- Değilse bu hücrede key zaten vardır; "daha önce eklenmiş" mesajı verilir.

**Silme:** 19 silinecekse önce yeri bulunur. Hücrede 19 kalmamalıdır; değerler pozitifse hücreye $-1$ gibi bir silindi işareti (deletion flag) konur. Bu, oraya yeni bir eleman eklenebileceğini gösterir.

**Yeniden hashleme (rehashing):** Tablo tamamen dolunca daha büyük boyutlu yeni bir tablo oluşturulur. Elemanlar yeni tabloya aynı indislerle kopyalanmaz; hepsi yeni tablonun boyutuna göre yeniden hashlenir.

> **Ek bilgi (derste anlatılmadı):** Silinen hücreyi tamamen boş (NULL) yapmak arama döngüsünü erken bitirir ve o hücreden sonra yerleşmiş elemanlar bulunamaz. Silindi işaretinin ayrı bir değer olması bu yüzden gereklidir: arama bu işaretin üzerinden geçer, ekleme ise oraya yazabilir.

### 7.4 Kümelenme problemi

Doğrusal yoklamada 5, 12 ve 19 için üretilen adresler 5, 6 ve 0 hücrelerinde yığıldı. Dizi dairesel düşünüldüğü için hep aynı bölgede kümelenme olur, diğer yerler genellikle boş kalır. Buna **kümelenme problemi** (problem of clustering) denir: elemanların tablonun belli bir bölgesinde toplanması.

### 7.5 Karesel yoklama (quadratic probing)

Bu yöntem birer birer değil, deneme sayısının karesi kadar ilerler: önce 0, sonra 1, sonra 4, sonra 9 sonraki hücreye bakılır. Genel tanım (ekrandan, 01:25:00):

$$h(k, i) = (h'(k) + c_1 \cdot i + c_2 \cdot i^2) \bmod M$$

Burada $c_1$ ve $c_2$ sabittir (ekranda $c_1 = 2$, $c_2 = 1$ yazıldı). Derste örnek için sade biçim kullanıldı:

$$h(k, i) = (h'(k) + i^2) \bmod M, \quad h'(k) = k \bmod M$$

Örnek: $M = 7$, 2 numaralı hücrede 2, 3 numaralı hücrede de bir değer var; 9 eklenecek.

- $i = 0$: $9 \bmod 7 = 2$. Hücre 2 dolu.
- $i = 1$: $(2 + 1^2) \bmod 7 = 3$. Hücre 3 dolu.
- $i = 2$: $(2 + 2^2) \bmod 7 = 6$. Hücre 6 boş, 9 buraya yazılır.

Hoca formülde $h'(k)$ yerine 2 ya da 9 yazmanın fark etmediğini vurguladı: modu bir kez almak yeterlidir, modüler aritmetikten $(9 + i^2) \bmod 7 = (2 + i^2) \bmod 7$'dir.

### 7.6 Çift hashing (double hashing)

İki hash fonksiyonu kullanılır (ekrandan, 01:30:00):

$$hash(k, i) = [h_1(k) + i \cdot h_2(k)] \bmod M$$
$$h_1(k) = k \bmod M, \qquad h_2(k) = 1 + (k \bmod K), \quad K < M$$

$h_1$ doğrusal yoklamadaki klasik fonksiyondur. $h_2$ ise elemanı doğrusal ya da karesel değil, belli bir adım boyuyla öteler. $K$ sabit bir sayıdır ve $M$'den küçük olmalıdır; $M$'den büyük ya da eşit olursa tablo boyutunun dışına taşan değerler üretir.

Örnek: $M = 13$, 14 eklenecek. $h_1(14) = 14 \bmod 13 = 1$. $i = 0$ denemesinde $(1 + 0 \cdot h_2) \bmod 13 = 1$, yani 14 adres 1'e eklenir. Bir sonraki elemanlar için de aynı işlemler yapılır. Bu yöntem çakışma olasılığını azaltır.

<!-- BELİRSİZ: hoca K = 5 seçip h2 değerini 4 olarak söyledi; formüle göre h2(14) = 1 + (14 mod 5) = 5 olur. i = 0 denemesinde sonuç değişmez. -->

## 8. Çakışma çözümleri: ayrı zincirleme

Bu yöntemde yine bir tablo boyutu vardır, ama tabloda değer değil **pointer** tutulur (ekrandan, 01:35:00). Hash fonksiyonu aynı indisi veren elemanlar kendi içinde gruplanır ve bir bağlı listede saklanır. Örneğin $\bmod 7$ ile 8, 15 ve 22 hep 1 indisini verir.

### 8.1 Bağlı listeye ekleme

Hoca bağlı listede en az maliyetli eklemenin nereye yapıldığını sordu. Bir öğrenci dizinin sonunu önerdi. Hoca bağlı listede sona gitmek için bütün listeyi gezmek gerektiğini hatırlattı; doğru cevap listenin başıdır (head).

- Önce 8 eklenir; 1 numaralı hücre 8'i gösterir.
- 15 eklenirken sona eklenseydi head'den 8'e, 8'den sona gidilirdi; bu kötüdür. Bunun yerine 15 başa eklenir ve 8'i gösterir.
- 22 eklenince hücre 22'yi, 22 de 15'i gösterir. Hücre ile 15 arasındaki eski bağ koparılır.

Başa ekleme (insert front) $O(1)$, sona ekleme (insert tail) $O(n)$'dir (ekrandan, 01:35:00). Sona eklemek gerekirse son düğümün adresi ayrıca saklanmalıdır.

### 8.2 Ayrı zincirlemede arama

8 aranıyorsa hash fonksiyonu 1'i verir, 1 numaralı listenin ilk elemanına bakılır.

- **En iyi durum:** Aranan eleman listenin başındadır, $O(1)$. Diğer hücrelere gidilmez.
- **En kötü durum:** Listenin sonuna kadar bakmak gerekir, $O(n)$. Yani hashing kullanmak her zaman tek adımda bulmak demek değildir.

Hoca Java'daki HashMap ve HashSet yapılarının da böyle adresler sakladığını hatırlattı. Bu derste ayrıntısına girilmeyen bir yaklaşım da bağlı liste yerine dengeli bir ikili ağaç kullanmaktır. Örneğin $\bmod 7$ ile 1 indisine düşen 8 köke gelir, 15 sağa, 1 sola gider. Böylece en kötü durum $n$'den $\log n$'e iner. Bu durumda tablonun, saklanan veri türünde (örneğin kitap) düğümler gösteren bir pointer dizisi olması gerekir.

### 8.3 C ile gerçekleme

Hoca yapıları şöyle tanımladı (ekrandan, 01:40:00):

```c
struct node {
    int key;
    char name[40];
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};
```

Ağaç kullanılsaydı `head` yerine kök ve düğümde `left`, `right` tutulurdu. `struct hash` içindeki sayaç önce `m` diye yazıldı; tablo boyutu $m$ ile karışmasın diye hoca adını `count` yaptı. `main` içinde $M$ kullanıcıdan `scanf("%d", &M);` ile alınır ve tablo `calloc` (ya da `malloc`) ile $M \cdot \text{sizeof(struct hash)}$ boyutunda açılır. Sonra tabloya key ve name ile ekleme, key ile silme ve key ile arama fonksiyonları çağrılır.

Ekleme fonksiyonu (ekrandan, 01:45:00; son üç satır sözlü anlatımdan, hocanın `hashTable` yerine `ht` yazılması gerektiği düzeltmesiyle):

```c
void insertToHash(struct hash *ht, int key, char name[], int m) {
    int hashIndex = key % m;
    struct node *newNode = createNode(key, name);
    if (!ht[hashIndex].head) {
        ht[hashIndex].head = newNode;
        ht[hashIndex].count = 1;
        return;
    }
    newNode->next = ht[hashIndex].head;
    ht[hashIndex].head = newNode;
    ht[hashIndex].count++;
}
```

Liste boşsa yeni düğüm doğrudan baş olur ve sayaç 1 yapılır. Değilse yeni düğümün `next`'i mevcut başı gösterir, baş yeni düğüm olur ve sayaç bir artırılır. Silme ve arama da bağlı liste işlemleri olduğu için hoca bunları ayrıntılı anlatmadı.

> **Ek bilgi (derste anlatılmadı):** Derste yazılmayan `createNode` ve bir arama fonksiyonu eklenerek bu kod tam bir programa dönüştürüldü, `gcc -Wall` ile derlendi ve $m = 7$ ile 8, 15, 22 eklenerek çalıştırıldı. 1 numaralı liste `22 15 8` sırasıyla oluştu, sayaç 3 oldu; 8 bulundu, 9 bulunamadı. Arama fonksiyonu `ht[key % m].head`'den başlayıp `key` eşleşene ya da liste bitene kadar `next` ile ilerler.

## 9. Evrensel hashing

Üçüncü yöntem **evrensel hashing**'dir (universal hashing) (ekrandan, 01:50:00). Elimizde $h_1(), h_2(), \dots, h_n()$ gibi birden fazla hash fonksiyonu vardır. Ekleme ya da silme yapılırken bunlardan biri rastgele seçilir (randomly choose a hash function), örneğin $h_i$. Veri bu fonksiyonla bir anahtara dönüştürülür ve yerine yerleşir.

Hoca bu yöntemi güvenlikle ilişkilendirdi: hangi fonksiyonla hash'lendiği doğrudan belli olmadığı için çözülmesi zorlaşır. Mod gibi basit bir fonksiyonun tersi bulunabilir; daha güçlü (robust) bir fonksiyon ve rastgele seçim güvenliği artırır.

> **Ders sonrası not:** Evrensel hashing'in ders kitaplarındaki asıl amacı büyük olasılıkla güvenlik değil performanstır: fonksiyon ailesinden rastgele seçim, kötü niyetli ya da kötü dağılımlı girdilere karşı bile beklenen çakışma sayısını düşük tutar. Fonksiyon bir tabloda bir kez seçilir ve o tablo boyunca aynı kalır; aksi halde aranan key bulunamaz. Parola saklamada ise MD5, SHA ailesi gibi kriptografik hash fonksiyonları kullanılır.

## 10. Doluluk oranı ve başarısız arama

### 10.1 $M$ ile $N$ ilişkisi

Hoca açık adresleme ve ayrı zincirlemede tablo boyutu $M$ ile eleman sayısı $N$ arasındaki ilişkiyi sordu (ekrandan, 01:50:00):

- **Açık adresleme:** $M > N$ olmalıdır. 10 hücreli tabloya 11. eleman eklenemez.
- **Ayrı zincirleme:** $M < N$ olabilir; her hücre bir liste tuttuğu için çok sayıda eleman az hücreye sığar.

**Doluluk oranı (load factor):**

$$\alpha = \frac{N}{M}$$

### 10.2 Yoklama sayısı tablosu

Hoca $\alpha$'ya göre ortalama yoklama (probe) sayılarını verdi:

| $\alpha$ | 0,1 | 0,2 | 0,3 | 0,5 | 0,9 |
|---|---|---|---|---|---|
| Ortalama yoklama sayısı | 1,11 | 1,28 | 1,52 | 2,5 | 50,5 |

Dizinin doluluğu arttıkça yoklama sayısı hızla artar. 2,5 ve altı kabul edilebilir; bu yüzden $\alpha = 0{,}5$ kullanılması önerilir. $N$ eleman için $M = 2N$ seçilir.

> **Ek bilgi (derste anlatılmadı):** Bu değerler, doğrusal yoklamada başarısız aramanın beklenen yoklama sayısı için bilinen $\frac12\left(1 + \frac{1}{(1-\alpha)^2}\right)$ formülüyle uyuşur: $\alpha = 0{,}1$ için 1,117; 0,5 için 2,5; 0,9 için 50,5 (python ile doğrulandı).

### 10.3 Başarısız arama olasılıkları

Başarısız aramada doluluk oranına göre şu olasılıklar yazıldı (ekrandan, 01:55:00):

- $P(\text{ilk hücre dolu}) = \alpha$
- $P(\text{boş hücre}) = 1 - \alpha$
- $P(\text{ilk iki hücre dolu}) \approx \alpha \cdot \alpha$
- $P(\text{yoklama 2. adımda biter}) = \alpha \cdot (1 - \alpha)$

Yoklamanın ikinci adımda bitmesi, ilk hücrenin dolu, ikincinin boş olması demektir. Hoca bunların büyük veriler üzerinde denenmiş istatistiksel sonuçlar olduğunu söyledi. Geometrik serilerle ilgili matematiksel türetmeye girmedi; kod açısından kullanmanın yeterli olduğunu belirtti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:40): Sıralı arama, ikili arama, BST ve dengeli ağaç için arama, ekleme ve silmenin en kötü ve ortalama durum maliyetleri nedir?

> **Çözüm (derste verildi):** Bölüm 1.1'deki tablo (ekrandan, 00:15:00). Örneğin sıralı aramada en kötü durum arama $n$, ekleme 1, silme $n$; dengesiz BST'de üç işlem de $N$; dengeli ağaçta üçü de $\log N$'dir.

**Soru 2** (ekrandan, 00:30:00): $M = 7$ olan bir tabloya bölme yöntemiyle sırasıyla 25, 2 ve 4 eklenecek. İndisler nedir, nerede çakışma olur?

> **Çözüm (derste verildi):** $25 \bmod 7 = 4$, $2 \bmod 7 = 2$, $4 \bmod 7 = 4$. 4 eklenirken 4 numaralı hücre 25 ile dolu olduğu için çakışma olur.

**Soru 3** (ekrandan, 00:35:00): Çarpma yöntemiyle $M = 10000$, $key = 123456$, $A = (\sqrt5-1)/2$ için hash değeri nedir?

> **Çözüm (derste verildi):** $123456 \cdot A = 76300.0041151\ldots$; kesirli kısım $0.0041151$; $10000 \cdot 0.0041151 = 41.151$; $\lfloor 41.151 \rfloor = 41$.

**Soru 4** (derste sözlü, 00:38:04): İki kişinin farklı günlerde doğma olasılığı nedir? $k$ kişi için nasıl genelleşir?

> **Çözüm (derste verildi):** İki kişi için $364/365$. $k$ kişi için $\prod_{j=1}^{k-1}\frac{365-j}{365}$; aynı günde doğan en az iki kişi olma olasılığı bunun 1'den farkıdır.

**Soru 5** (derste sözlü, 00:45:09): "ELMA", "MALE" ve "ALME" stringleri için ASCII toplamıyla hash üretmek neden kötüdür, ne önerirsiniz?

> **Çözüm (derste verildi):** Toplama değişme özelliğine sahip olduğu için üçü de aynı değeri (287) verir. Karakterin konumu hesaba katılmalıdır; örneğin Horner yöntemiyle her karakter $R$'nin farklı bir kuvvetiyle çarpılır.

**Soru 6** (ekrandan, 01:15:00): $M = 7$, 5 numaralı hücrede 5 varken doğrusal yoklamayla 12 ve 19 eklenirse nereye yerleşir?

> **Çözüm (derste verildi):** 12: $i = 0$ için 5 (dolu), $i = 1$ için 6. 19: $i = 0$ için 5, $i = 1$ için 6 (dolu), $i = 2$ için $(19+2) \bmod 7 = 0$.

**Soru 7** (ekrandan, 01:25:00): $M = 7$, 2 ve 3 numaralı hücreler doluyken karesel yoklamayla ($h(k,i) = (k \bmod 7 + i^2) \bmod 7$) 9 nereye yerleşir?

> **Çözüm (derste verildi):** $i = 0$: 2 (dolu); $i = 1$: 3 (dolu); $i = 2$: $(2 + 4) \bmod 7 = 6$.

**Soru 8** (derste sözlü, 01:32:39): Ayrı zincirlemede bağlı listeye en az maliyetli ekleme nereye yapılır?

> **Çözüm (derste verildi):** Listenin başına (head); $O(1)$. Sona ekleme son düğümün adresi tutulmadıkça $O(n)$'dir.

**Soru 9** (derste sözlü, 01:48:56): Açık adreslemede ve ayrı zincirlemede tablo boyutu $M$ ile eleman sayısı $N$ arasında nasıl bir ilişki olmalıdır?

> **Çözüm (derste verildi):** Açık adreslemede $M > N$; ayrı zincirlemede $M < N$ olabilir. Açık adresleme için $\alpha = N/M \approx 0{,}5$ önerilir.

**Soru 10** (derste sözlü, 01:56:10; kısa sınav sorusu): Özyinelemeli ve iteratif QuickSort algoritmalarının zaman ve bellek karmaşıklığını en iyi, en kötü ve ortalama durum için ayrı ayrı analiz edin. 12 elemanlı, rastgele dağılımlı bir dizi için seçtiğiniz bir pivota göre iki algoritmanın çalışmasını adım adım gösterin.

> **Çözüm (derste verilmedi):** Zaman: en iyi ve ortalama durumda bölmeler dengeli olduğu için $T(n) = 2T(n/2) + \Theta(n)$ ve $\Theta(n \log n)$; en kötü durumda (örneğin sıralı dizide uç eleman pivot seçilirse) $T(n) = T(n-1) + \Theta(n)$ ve $\Theta(n^2)$. Bellek: yerinde bölme yapıldığı için ek dizi gerekmez; özyinelemeli sürümde özyineleme yığını, iteratif sürümde açık yığın en iyi ve ortalama durumda $O(\log n)$, en kötü durumda $O(n)$ derinliğe ulaşır. Küçük alt diziyi önce işleyip büyüğü yığına atan sürümde yığın en kötü durumda da $O(\log n)$ kalır. Adım adım gösterim seçilen diziye ve pivota bağlıdır.

**Soru 11** (ekrandan, 02:00:00; ödev metni): Bir sözlükteki kelimeler açık adreslemeli bir hash tablosuna yerleştirilecek (çakışma için karesel yoklama, hash fonksiyonu olarak bölme yöntemi, doluluk oranı 0,6). Verilen kelime tabloda yoksa, kelimedeki her harf sırayla 'a'-'z' harfleriyle değiştirilip elde edilen kelimelerin tabloda olup olmadığına bakılacak ve bulunanlar öneri olarak yazılacak (ör. "sate" için "late", "same", "save"). Tablo boyutu $M$, $M \ge N/\alpha$ şartını sağlayan en küçük asal sayıdır; Horner yöntemindeki $R$, $M$'den küçük ilk asal sayıdır. Arama adım sayıları ikili aramayla karşılaştırılacak.

<!-- BELİRSİZ: ödevdeki kelimenin sayı karşılığını veren kod satırı karede yarım kaldı; M bağıntısı altyazıdan kuruldu. -->

> **Çözüm (derste verilmedi):** Ana adımlar: $N$ kelime için $M$ elle hesaplanır (en küçük asal $\ge N/0{,}6$). Her kelime Horner yöntemiyle sayıya çevrilir, $h'(k) = k \bmod M$ ve $h(k,i) = (h'(k) + i^2) \bmod M$ ile ilk boş hücreye yerleştirilir. Aramada aynı yoklama dizisi kelime bulunana ya da boş hücreye gelinene kadar izlenir ve adım sayısı sayılır. Kelime yoksa uzunluğu $L$ olan kelime için $25L$ aday üretilip her biri tabloda aranır. $\alpha = 0{,}6$ iken başarılı arama ortalama birkaç yoklamada biter; sıralı sözlükte ikili arama ise yaklaşık $\log_2 N$ karşılaştırma gerektirir (ör. 20.000 kelime için yaklaşık 15).

## Dersin Toparlaması

Bu derste arama işlemlerinin bilinen yöntemlerle en iyi $\log n$ düzeyinde kaldığı görüldü. Hashing'in key'i bir hash fonksiyonuyla doğrudan adrese çevirerek bu işlemleri $O(1)$'e yaklaştırdığı anlatıldı. İyi bir hash fonksiyonunun kolay hesaplanan, tutarlı ve adresleri düzgün dağıtan bir fonksiyon olması gerektiği; bölme ve çarpma yöntemleri; tamsayı, kayan noktalı sayı, string (Horner yöntemi) ve bileşik key'lerden indis üretme işlendi. Doğum günü paradoksuyla, adres uzayı çok büyük olsa bile çakışmanın kaçınılmaz olduğu gösterildi.

Çakışma çözümleri iki ana gruptan incelendi. Açık adreslemede doğrusal yoklama, karesel yoklama ve çift hashing; silindi işareti, yeniden hashleme ve kümelenme problemi ele alındı. Ayrı zincirlemede bağlı listeye başa ekleme ve C kodu yazıldı. Son olarak evrensel hashing, doluluk oranı $\alpha = N/M$ ve başarısız aramanın olasılıkları ele alındı. Dersin sonunda kalan konular olarak dinamik programlama, açgözlü (greedy) teknikler ve geri izleme (backtracking) anıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
