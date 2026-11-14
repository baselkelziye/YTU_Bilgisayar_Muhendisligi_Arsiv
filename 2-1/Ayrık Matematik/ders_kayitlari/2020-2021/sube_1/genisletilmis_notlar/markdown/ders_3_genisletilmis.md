# Ders 3 Genişletilmiş Notu: Bool Cebri, Bool Fonksiyonları, Mintermler, Mantık Kapıları ve Karnaugh Haritaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Haftaların Tekrarı
- 2. Bool Cebri: Toplama, Çarpma ve Tümleyen
- 3. Bool İfadeleri ve Bool Fonksiyonları
- 4. Kaç Farklı Bool Fonksiyonu Vardır?
- 5. Bool Cebrinin Özdeşlikleri
- 6. Tablodan Fonksiyon Yazmak, Mintermler ve Çarpımların Toplamı
- 7. Mantık Kapılarıyla Devre Çizimi ve Yarım Toplayıcı
- 8. Karnaugh Haritasına Giriş
- 9. İki Değişkenli Karnaugh Haritaları
- 10. Üç Değişkenli Karnaugh Haritaları ve Gray Kodu
- 11. Dört Değişkenli Karnaugh Haritaları
- 12. Alıştırmaların Çözümü ve Gereksiz Grup Hatası
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Haftaların Tekrarı

Ders Zoom üzerinden yapıldı. Kaydın ilk dakikaları bağlantı beklemesi ve sohbetle geçer; asıl anlatım yaklaşık 00:04:00'te başlar. Hoca, dersin üçüncü haftasında olduklarını ve dönemin daha yarısına gelinmediğini söyleyerek önceki haftaları özetledi.

İlk hafta ayrık matematiğin ne olduğu, kullanım alanları ve nerelerde ihtiyaç duyulduğu konuşulmuştu. İkinci ve üçüncü haftalarda mantık ve ispat görülmüştü. Hoca bu bölümden aklında kalanları şöyle sıraladı:

- **Önerme (proposition):** Sonucu doğru (true) ya da yanlış (false) olan ifadedir. Önermeler birbirine bağlanarak mantıksal ifadeler yazılır. Bu dersin sonunda bu ifadelerin ya da fonksiyonların nasıl sadeleştirildiği görülecekti.
- **AND kapısı:** Çarpma işlemini yapar. Girişlerden birinin yanlış olması çıkışı yanlış yapar.
- **OR kapısı:** Toplama işlemini yapar. Girişlerden birinin doğru olması çıkışı doğru yapmaya yeter.
- **NOT kapısı:** Çıkış, girişin tersidir.
- **XOR (dışlayan veya):** Girişler aynıysa çıkış 0'dır. Hoca "XOR deyince aklımıza çıkarma gelsin" dedi (düzeltmesi Bölüm 7.4'te).
- **Koşullu önerme (if p then q):** Yalnız birinci önerme doğru, ikincisi yanlış olduğunda sonuç yanlıştır; diğer bütün durumlar doğrudur.
- **Çift koşullu önerme (if and only if):** Doğruluk tablosu XOR'un tam tersidir. Girişler aynıysa çıkış doğrudur.
- **Mantıksal denklik:** Aynı girişler için iki ya da daha fazla önerme aynı sonucu veriyorsa bunlar mantıksal olarak denktir.
- **Karşıt (converse):** $p \to q$ önermesinin karşıtı $q \to p$'dir.
- **Totoloji (tautology) ve çelişki (contradiction):** Girişler ne olursa olsun çıkış hep 1 ise totoloji, hep 0 ise çelişkidir.

Hoca ispat yöntemlerini de hatırlattı. **Doğrudan ispatta** $p$'nin doğru olduğu kabul edilip $q$ ispatlanır. **Dolaylı ispatta** "$q$ değildir" doğru kabul edilip "$p$ değildir" ispatlanır; bu ispat doğruysa asıl önermenin de doğru olduğu kabul edilir. **Tümevarımla ispatta** önce önermenin bir başlangıç değeri için doğru olduğu gösterilir; sonra bir $k$ değeri için doğru olduğu kabul edilip $k+1$ için de doğru olduğu ispatlanır.

Hoca son olarak bir paragraftaki olayları önermelere ayırıp metni matematiksel önermelerle yazabildiklerini hatırlattı. Önemli bir nokta olarak da "önermelerimiz hiçbir zaman negatif olmuyordu, pozitif olmak zorundaydı" dedi.

> **Ders sonrası not:** Bir önermenin değili de bir önermedir. Kastedilen büyük olasılıkla şudur: Bir metin önermelere ayrılırken temel önermeler olumlu cümle olarak seçilir, olumsuzluk $\neg$ ile gösterilir.

> **Ders sonrası not:** Hoca tekrar sırasında "contradiction" terimini bir kez de $p \to q$'dan türetilen önerme için kullandı ("$q$ ise $p$... tersini alıp inversini alıyordu"). $p \to q$ için $\neg q \to \neg p$ önermesinin adı ters-karşıttır (contrapositive). Çelişki (contradiction), her girişte yanlış olan önermedir. Hoca hemen ardından çelişkiyi bu doğru anlamıyla da tanımladı.

## 2. Bool Cebri: Toplama, Çarpma ve Tümleyen

Hoca Bool cebri (Boolean algebra) bölümünün slaytlarını bölümdeki bir başka öğretim üyesinin (Ahmet Hoca) hazırladığını söyledi. Lojik derslerinde bir ya da iki dönemde görülecek konunun burada kısa bir özetinin yapılacağını belirtti. Ayrık matematik, bilgisayar bilimlerindeki birçok konunun bir girişidir: olayların ayrık ve sonlu bir yapıdan sayısal (dijital) bir kavrama nasıl çevrildiği görülür.

Hoca, Bool cebrini Claude Shannon'ın ortaya attığını söyledi ve Shannon'ın 1916'da doğduğunu, bu yüzden konunun yüzyılımız içinde ortaya çıktığını ekledi.

> **Ders sonrası not:** Bool cebrini 19. yüzyılda George Boole kurdu (1847, 1854); cebir onun adını taşır. Claude Shannon (1916 doğumlu) 1937-1938'de bu cebri anahtarlama devrelerine uyguladı.

Hoca ardından konunun başlıklarını sıraladı: Bool fonksiyonları, mantık kapıları ve Karnaugh haritaları. Hoca "Karnaugh diyagramı" demeye alışkın olduğunu söyledi; İngilizcesi Karnaugh map olduğu için Türkçesi "harita"dır. Notta iki ad da aynı şeyi gösterir.

Bool cebri yalnız $B = \{0, 1\}$ değerleri üzerinde çalışır ve üç işlemi vardır:

- **Toplama (OR):** Girişlerden birinin 1 olması sonucu 1 yapar.
- **Çarpma (AND):** Kaynaklarda Bool çarpımı (Boolean product) adıyla da geçer. Girişlerden biri 0 ise sonuç 0'dır.
- **Tümleyen (complement):** Değerin tersidir. Hoca, tümleyenin üst çizgi ($\overline{x}$) gibi farklı gösterimlerle gelebileceğini hatırlattı.

### 2.1 Bool toplaması ile ikilik toplama farkı

Hoca, Bool toplamasını ikilik tabandaki aritmetik toplamayla karıştırmamak gerektiğini anlattı. İki tabanında $1 + 1 = 2$ olur; iki tabanında 2 yazılamadığı için 2 çıkarılır, sonuç 0 ve elde 1 kalır: $1 + 1 = 10_2$. Bool cebrinde ise toplama "veya" anlamındadır: "o veya bu", birinin olması yeterlidir. Bu yüzden Bool cebrinde $1 + 1 = 1$'dir.

### 2.2 Arama motoru örneği

Hoca OR ve AND'in günlük karşılığını bir arama motoru sorgusuyla gösterdi. Sorgu "İstanbul OR Ankara" ise sonuçta yalnız İstanbul geçen sayfalar, yalnız Ankara geçen sayfalar ve ikisinin birlikte geçtiği sayfalar gelir. Sorgu "İstanbul AND Ankara" ise gelen her sayfada iki kelimenin de geçmesi gerekir.

Arama motorlarındaki bu işlem bilgi getirimi (information retrieval) işlemidir. Bilgi getiriminde mantıksal modeller de, başka türden modeller de kullanılır. Hocaya göre arama motorlarının ilk çıkışı bu mantıksal modellerle olmuştu: iki kelime aranırken araya AND ya da OR konuyordu. Bugün artık böyle yapılmıyor.

### 2.3 Bir Bool ifadesinin değerini hesaplamak

Slayttaki örnekte bir ifadenin sonucu soruldu. Hoca işlem önceliğini hatırlattı: programlama dillerinde olduğu gibi önce parantez içi yapılır; parantezin üstünde tümleyen varsa önce o uygulanır. Sonra işlemler soldan sağa yürütülür.

<!-- BELİRSİZ: Slayttaki ifadenin tam yazılışı altyazıda okunmuyor. Hocanın adımlarına ve ders kitabındaki örneğe göre ifade büyük olasılıkla $1 \cdot 0 + \overline{(0 + 1)}$'dir. -->

Hocanın adımları:

$$1 \cdot 0 + \overline{(0 + 1)} = 0 + \overline{1} = 0 + 0 = 0$$

Parantez içindeki OR 1 verir, tümleyeni 0 olur. $1 \cdot 0$ çarpımı 0'dır. Sonuç $0 + 0 = 0$'dır.

## 3. Bool İfadeleri ve Bool Fonksiyonları

### 3.1 Tanım

$B = \{0, 1\}$ olsun. $B^n$, 0 ve 1'lerden oluşan bütün $n$ bitlik dizilerin kümesidir. Değerini $B$'den alan bir değişkene Bool değişkeni denir; alabileceği değerler 0 ya da 1'dir. $B^n$'den $B$'ye giden bir fonksiyona **$n$. dereceden Bool fonksiyonu** denir:

$$F: B^n \to B, \qquad F(x_1, x_2, \ldots, x_n), \quad x_i \in B, \; i = 1, \ldots, n$$

Hoca burada matematiksel gösterimden korkmamak gerektiğini vurguladı. Bir akademik makale okuduğunuzda ya da yazdığınızda insanlar bir şeyi sözle uzun uzun anlatmaz, hemen matematiksel gösterimini yazar. Bu gösterimler ilk bakışta karışık görünür, ama aslında sözle söylenen şeyin kısa yazılışıdır.

### 3.2 Doğruluk tablosuyla fonksiyon değeri

Derste hesaplanan fonksiyon $F(x, y, z) = xy + \overline{z}$ idi. Hoca, bu fonksiyonun sonucunun tablo olmadan da söylenebileceğini, ama hata yapma olasılığının artacağını söyledi. İfade on değişkenli olsaydı akıldan yapmak çok zor olurdu. Tablo ise bütün durumlarda fonksiyonun değerini rahatça gösterir.

Üç değişken için $2^3 = 8$ durum vardır. Hoca tabloyu kurmanın kuralını anlattı: En sağdaki sütun $2^0$ basamağıdır ve değeri birer birer değişir (0, 1, 0, 1, ...). Ortadaki sütun $2^1$ basamağıdır ve ikişer ikişer değişir. En soldaki sütun $2^2$ basamağıdır ve dörder dörder değişir. Dördüncü bir değişken olsaydı sekizer sekizer değişecekti. Satırlar ondalık olarak 0'dan 7'ye kadar gider.

> **Hocanın vurgusu:** Doğruluk tablosunu çizerken lütfen 0'dan başlayın: 000, 001, ... Hoca bazı kitapların neden 7'den başlayıp 0'a doğru gittiğini anlamadığını söyledi.

Hesap adımları: önce $xy$ sütunu hesaplanır (yalnız ikisi de 1 iken 1). Sonra $z$ sütununun tamamı ters çevrilip $\overline{z}$ bulunur. En son bu iki sütun OR'lanır; yalnız ikisinin de 0 olduğu satırlarda sonuç 0'dır.

| $x$ | $y$ | $z$ | $xy$ | $\overline{z}$ | $F = xy + \overline{z}$ |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 | 1 |

### 3.3 Günlük hayattan bir model: risk fonksiyonu

Hoca "bu çok basit, niye gösteriyorsunuz?" sorusuna bir örnekle cevap verdi. Değişkenler $x$ = dezenfektan, $y$ = maske, $z$ = özel araba olsun. Soru şudur: Bir vatandaş dışarı çıktığında hangi durumlarda riske maruz kalır, hangi durumlarda kalmaz? Bunu veren bir fonksiyon çıkarılması isteniyor.

Üç değişken için 8 farklı durum vardır: hem dezenfektan, hem maske, hem araba olabilir; hiçbiri olmayabilir; ve aradaki bütün kombinasyonlar. Fonksiyonu kurmak için riskli durumların kuralları verilmelidir. Hocanın verdiği kurallardan üçü:

- Maske yok, dezenfektan yok, ama arabayla iki ev arasında gidip geliniyor: riskli değil, fonksiyon değeri 0.
- Maske ve dezenfektan var, araba yok: riskli değil, 0.
- Yalnız dezenfektan var, maske ve araba yok: riskli, 1.

<!-- BELİRSİZ: Hoca tablonun geri kalan satırlarını tahtada doldurdu; altyazıda yalnız bu üç satır sözle geçiyor. Tablodaki 1 sayısının beş olduğu söyleniyor, ama hangi satırlar olduğu okunmuyor. -->

Bu kurallara bakılarak her satırın 1 mi 0 mı olduğuna karar verilir. Sonra fonksiyon yazılır: fonksiyonun 1 olduğu satırlar alınır ve terimler artıyla bağlanır. Örneğin bir satır $xyz$ terimini verir, bir başkası başka bir terimi verir ve bütün 1'ler böyle yazılır.

Hoca, tabloda beş tane 1 olduğu hâlde fonksiyonun beş terimle yazılmak zorunda olmadığını söyledi. Beş terimin hepsi yazılabilir; yazılan uzun ifade kısa ifadeye mantıksal olarak denktir. Bunu görmek için uzun ifadenin de tablosu çıkarılır ve aynı çıkışlar elde edilir. Kısa hâli ise dersin sonunda görülecek Karnaugh haritasıyla bulunur. Böylece olayı anlatan bir matematiksel model elde edilir: kişi hangi girişle gelirse gelsin değerler fonksiyonda yerine konur ve sonuç hemen çıkar. Hoca bu örnekle konunun kâğıt üzerinde kalan bir şey olmadığını, birçok problemin bu şekilde modellenebileceğini göstermek istedi.

### 3.4 Tümleyen, eşitlik, toplam ve çarpım

- Bir Bool fonksiyonu $F$'nin tümleyeni $\overline{F}$, fonksiyonun kendisinin tersidir.
- $n$ değişkenli iki Bool fonksiyonu $F$ ve $G$, bütün $b_1, \ldots, b_n \in B$ için $F(b_1, \ldots, b_n) = G(b_1, \ldots, b_n)$ ise eşittir. Hoca iki fonksiyonun aynı değişken kümesini kullanması gerektiğini vurguladı; farklı kümelerin elemanlarını kullanan fonksiyonlar arasında eşitlikten söz edilemez.
- Örnek: $xy$, $xy + 0$ ve $xy \cdot 1$ üç farklı Bool ifadesidir, ama aynı fonksiyonu gösterir. $x = y = 1$ için üçü de 1 verir: $1 \cdot 1 = 1$, $1 + 0 = 1$, $1 \cdot 1 = 1$.
- İki fonksiyonun toplamı $F + G$, her girişte değerlerinin OR'lanmasıdır. Çarpımı $FG$, değerlerinin AND'lenmesidir. Bu, iki fonksiyon aynı değişken kümesini kullanıyorsa rahatça yapılır.

## 4. Kaç Farklı Bool Fonksiyonu Vardır?

Slaytta $n$'nin değerine göre kaç farklı Bool fonksiyonu olduğu soruluyordu. Saymanın temel ilkelerinden çarpma ilkesine göre 0 ve 1'lerden oluşan farklı $n$ bitlik dizilerin sayısı $2^n$'dir. Bir Bool fonksiyonu bu $2^n$ girişin her birine 0 ya da 1 atar. Bu yüzden $n$. dereceden

$$2^{2^n}$$

farklı Bool fonksiyonu vardır.

İkinci dereceden bir fonksiyonun tanım kümesi dört ikiliden oluşur: (1,1), (1,0), (0,1), (0,0). $n$ yerine 2 konursa $2^2 = 4$, $2^4 = 16$ bulunur. Slaytta bu 16 fonksiyon $F_1$'den $F_{16}$'ya kadar yazılmıştı.

Hoca tablonun nasıl kurulduğunu şöyle anlattı: Dört girişli tabloyu 90 derece döndürün. Sanki dört değişkeniniz varmış gibi düşünün: her giriş satırı bir "değişken" olsun. Bu dört "değişken" için doğruluk tablosu kurar gibi yazın: bir sırada 1 ve 0'lar birer birer, bir sırada ikişer ikişer, bir sırada dörder dörder, bir sırada sekizer sekizer değişir. Böylece her sütun bir fonksiyon olur. Hoca sütunları ondalık olarak 15'ten 0'a kadar okudu: birinci fonksiyonun hepsi 1'dir (15), son fonksiyonun hepsi 0'dır (0).

> **Ders sonrası not:** Altyazıda slayttaki cümle "$2^n$ tane $n$. dereceden Bool fonksiyonu vardır" diye okunuyor. Doğrusu $2^{2^n}$'dir: $n = 1$ için 4, $n = 2$ için 16, $n = 3$ için 256. Hocanın $n = 2$ için bulduğu 16 sonucu doğrudur (Python ile kontrol edildi).

## 5. Bool Cebrinin Özdeşlikleri

Hoca, Boole'un yalnız $0 + 0 = 0$, $1 + 1 = 1$ gibi işlemleri değil, bu cebrin özdeşliklerini (Boolean identities) de verdiğini söyledi. Bunların çok önemli olduğunu vurguladı. Her birini $x$'e 0 ve 1 vererek tek tek kontrol etti.

| Özdeşlik | Ad (derste) |
| :-- | :-- |
| $\overline{\overline{x}} = x$ | Çift tümleyen (double complement) |
| $x + x = x$, $\; x \cdot x = x$ | Idempotent kanunu (hoca "değişmezlik kanunu" da dedi) |
| $x + 0 = x$, $\; x \cdot 1 = x$ | Birim eleman (identity) kanunu |
| $x + 1 = 1$, $\; x \cdot 0 = 0$ | Yutan eleman (domination) kanunu |
| $x + y = y + x$, $\; xy = yx$ | Değişme (commutative) |
| $x + (y + z) = (x + y) + z$, $\; x(yz) = (xy)z$ | Birleşme (associative) |
| $x + yz = (x + y)(x + z)$, $\; x(y + z) = xy + xz$ | Dağılma (distributive) |
| $\overline{xy} = \overline{x} + \overline{y}$, $\; \overline{x + y} = \overline{x}\,\overline{y}$ | De Morgan |
| $x + xy = x$, $\; x(x + y) = x$ | Yutma (absorption) |
| $x + \overline{x} = 1$, $\; x\overline{x} = 0$ | Tümleyen kuralı |

Hocanın kontrolleri:

- **Çift tümleyen:** $x = 1$ ise tümleyeni 0, onun tümleyeni 1'dir. Değerin değilinin değili kendisidir.
- **Idempotent:** $0 + 0 = 0$, $1 + 1 = 1$, $0 \cdot 0 = 0$, $1 \cdot 1 = 1$. Hep $x$'in kendisi çıkar.
- **Birim eleman:** $0 + 0 = 0$, $1 + 0 = 1$; $0 \cdot 1 = 0$, $1 \cdot 1 = 1$. Yine $x$'in kendisi.
- **Yutan eleman:** $x$ ne olursa olsun $x + 1 = 1$ ve $x \cdot 0 = 0$.
- **Tümleyen kuralı:** $x$ ister 0 ister 1 olsun, $x$ ile $\overline{x}$'ten biri mutlaka 1'dir; bu yüzden toplamları 1'dir. Biri mutlaka 0 olduğu için çarpımları 0'dır.
- **De Morgan:** Hoca kuralı şöyle özetledi: Parantezin tümleyeni alınınca her terimin tümleyeni alınır ve ortadaki işlem değişir; AND ise OR, OR ise AND olur.

### 5.1 Yutma özdeşliklerinin ispatı

Aradan sonra hoca yutma özdeşliklerini özdeşliklerle ispatladı:

$$x + xy = x(1 + y) = x \cdot 1 = x$$

$x$ ortak paranteze alınır. $1 + y$ yutan eleman kuralıyla her zaman 1'dir. $x \cdot 1$ birim eleman kuralıyla $x$'tir. Sol ve sağ taraf aynı çıkar; girişler ne olursa olsun bu iki ifade mantıksal olarak denktir.

$$x(x + y) = xx + xy = x + xy = x(1 + y) = x$$

Burada önce $x$ dağıtılır. $xx = x$ (idempotent) yazılır, sonra yine $x$ ortak paranteze alınır.

### 5.2 Dağılma özdeşliğini doğruluk tablosuyla göstermek

Hoca $x(y + z) = xy + xz$ eşitliği için şunu söyledi: Bu kuralları ezbere bilmiyorsanız ve böyle bir eşitliğin doğru olup olmadığı sorulursa, yapacağınız tek şey tablosunu çıkarmak ya da iki tarafın Karnaugh haritasını çizmektir. Üç değişken için sekiz satır vardır. Önce $y + z$ sütunu hesaplanır ve $x$ sütunuyla çarpılır. Sonra $xy$ ve $xz$ sütunları hesaplanıp toplanır. İki sonuç sütunu sekiz satırda da aynıdır; bu yüzden iki ifade mantıksal olarak denktir.

### 5.3 Derste çözülemeyen ispat: $x + yz = (x + y)(x + z)$

Hoca dağılmanın öbür biçimini, $x + yz = (x + y)(x + z)$ eşitliğini, özdeşliklerle ispatlamaya çalıştı ve takıldı. Sağ tarafı açmaya başladı: $(x + y)(x + z) = xx + xz + yx + yz$. Ardından $xx = x$ yazdı, ama sonrasında hangi kuralları kullanacağını kaçırdığını söyledi. "$y + z$'ye bir eklesem ne olur?" gibi denemeler yaptı ve bırakıp aradan sonra döneceğini söyledi.

Aradan sonra da çözümü göstermedi. Bir öğrenci "dağıtıp daha sonra absorpsiyon kuralını uyguladığımızda çıkıyor" diye ipucu vermeye başladı; hoca "söyleme" diyerek durdurdu. Bu ispatı Gmail adresine ilk gönderen üç öğrenciye bonus vereceğini söyledi. İspat "Örnek Sorular" bölümünde verilmiştir.

Hoca bu konuda şu görüşü vurguladı: Bu tür eşitlikleri özdeşliklerle ispatlamak çok el oyalar; çok basit bir örnek bile çok zaman alır. Kendisi bunları ya tabloyla ya da Karnaugh haritasıyla gösterir. Ama özdeşliklerle ispat yapılabileceği de akılda bulunmalıdır.

### 5.4 Mantık dilinde aynı özdeşlikler

Bir sonraki slayt aynı tablonun tekrarıydı: Artı ve nokta yerine "veya" ve "ve" bağlaçları kullanılmıştı. Dağılma, değişme, birleşme, tümleyen ve birim kurallarında hiçbir fark yoktur.

> **Ek bilgi (derste anlatılmadı):** Önermeler mantığındaki denklikler ile Bool cebri özdeşlikleri birebir karşılık gelir: $\lor$ yerine $+$, $\land$ yerine $\cdot$, $\neg p$ yerine $\overline{p}$, doğru (T) yerine 1, yanlış (F) yerine 0 yazılır. Bu yüzden önceki haftalarda görülen De Morgan ve dağılma kuralları burada aynı biçimde geçerlidir.

## 6. Tablodan Fonksiyon Yazmak, Mintermler ve Çarpımların Toplamı

### 6.1 Tablodan $F$ ve $G$ fonksiyonlarını yazmak

Slayttaki soru: Tabloda verilen $F$ ve $G$ fonksiyonlarını tanımlayan Bool ifadelerini bulunuz. Hoca bunu risk örneğine bağladı: Üç değişken vardır, bir olay verilmiştir ve verilen kısıtlara göre $F$'nin ve $G$'nin 1 ya da 0 olduğu durumlar tabloya yazılmıştır. İfade yazmak için fonksiyonun 1 olduğu satırlara bakılır.

- $F$ yalnız bir satırda 1'dir: $x$ var, $y$ yok, $z$ var. Bu yüzden $F(x, y, z) = x\overline{y}z$.
- $G$ iki satırda 1'dir: $x$ ve $y$'nin olduğu satır ile yalnız $y$'nin olduğu satır. Bu yüzden $G(x, y, z) = xy\overline{z} + \overline{x}y\overline{z}$.

<!-- BELİRSİZ: $G$'nin birinci satırında $z$'nin değeri altyazıda söylenmiyor ("X var, Y var"). Hocanın "sadece Y var" dediği satır $\overline{x}y\overline{z}$'dir. Ders kitabındaki aynı örnekte $G = xy\overline{z} + \overline{x}y\overline{z}$'dir; slayt büyük olasılıkla bu örnektir. -->

Hoca, yazılan ifadenin tek başına anlam taşımadığını, başına fonksiyonun adı ve değişkenleri, örneğin $G(x, y, z)$, mutlaka yazılması gerektiğini söyledi. Olay neye karşılık geliyorsa ifade de öyle okunur. Örneğin risk örneğinde bu ifade "dezenfektanın ve maskenin varsa ya da yalnız maskenin varsa" diye okunur.

### 6.2 Minterm

Bir Bool değişkeni ya da tümleyenine **literal**, $n$ değişkenin her birinden tam bir literal içeren $y_1 y_2 \cdots y_n$ çarpımına **minterm** denir (burada $y_i = x_i$ ya da $y_i = \overline{x_i}$). Hoca slayttaki tanımı okuduktan sonra mintermi Karnaugh haritası üzerinden anlattı.

Haritadaki gözler, haritanın üstünde ve solunda yazan değişkenleri temsil eder. İki değişken $A$ ve $B$ olsun. $A$ da $B$ de 1 ise bu durumun ondalık karşılığı $11_2 = 3$'tür. Bu gözün köşesine 3 yazılır. Artık bu göz "$A$ var, $B$ var" diye uzun uzun okunmaz; "minterm 3" denir ve herkes anlar. Minterm 3 demek $A$ = 1, $B$ = 1, yani $AB$ terimi demektir.

### 6.3 Çarpımların toplamı açılımı

Slayttaki soru: $F(x, y, z) = (x + y)\overline{z}$ için çarpımların toplamı açılımını (sum-of-products expansion) bulunuz.

<!-- BELİRSİZ: Hoca soruyu önce "toplamların çarpımı" diye okudu ve slaytta ifadenin bir kısmının kaydığını söyledi. Altyazıya göre istenen, fonksiyonun 1 olduğu değerlerden yazılan çarpımların toplamıdır. -->

**Tabloyla çözüm.** Üç değişkenin 8 durumu yazılır. Önce $x + y$ sütunu hesaplanır. Sonra $z$ sütununun tamamı ters çevrilerek $\overline{z}$ bulunur. Bu iki sütun AND'lenir. Fonksiyonun 1 olduğu satırlar:

| $x$ | $y$ | $z$ | $x + y$ | $\overline{z}$ | $F$ | Minterm |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 1 | 0 | 1 | 1 | 1 | 2: $\overline{x}y\overline{z}$ |
| 1 | 0 | 0 | 1 | 1 | 1 | 4: $x\overline{y}\,\overline{z}$ |
| 1 | 1 | 0 | 1 | 1 | 1 | 6: $xy\overline{z}$ |

Diğer beş satırda $F = 0$'dır. Sonuç:

$$F(x, y, z) = xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$$

**Özdeşliklerle çözüm.** Slayttaki adımlar:

1. Dağılma: $(x + y)\overline{z} = x\overline{z} + y\overline{z}$.
2. Birim eleman: Her terim 1 ile çarpılır. Bu 1, eksik değişkenin kendisiyle tümleyeninin toplamıdır ($a + \overline{a} = 1$). $x\overline{z}$ teriminde $y$ eksiktir, $y\overline{z}$ teriminde $x$ eksiktir: $x(y + \overline{y})\overline{z} + (x + \overline{x})y\overline{z}$.
3. Dağılma: $xy\overline{z} + x\overline{y}\,\overline{z} + xy\overline{z} + \overline{x}y\overline{z}$.
4. Idempotent ($a + a = a$): İki kez geçen $xy\overline{z}$ bir kez yazılır: $xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$.

Hoca 1 ile çarpmanın nedenini şöyle açıkladı: $y = 0$ ise $0 + 1 = 1$, $y = 1$ ise $1 + 0 = 1$'dir; $y$ ne olursa olsun $y + \overline{y} = 1$ olduğu için terimin değeri değişmez. Ama böylece fonksiyonun üç değişkenli terimleri ortaya çıkar. Slaytta "özdeşlik" diye geçen kuralın İngilizce adının identity law olduğunu bir öğrenci hatırlattı.

İki yöntem aynı sonucu verir. Hoca kendi deneyimini örnek gösterdi: Tabloyla yaparken hiç hata yapmadı, özdeşliklerle yaparken kuralların Türkçe adları yüzünden bocaladı. Bu yolla yazmanın zahmetli olduğunu, bazen bir terimin görülmediğini ya da fonksiyonun yanlış elde edildiğini söyledi. Tablo yapıldığında yanlış görme ihtimali çok düşer. Ters yön, yani uzun ifadeden kısa ifadeye dönmek ise daha da zordur; Karnaugh haritasıyla bu çok hızlı yapılır. Karnaugh haritaları da zaten bu işlemleri kolaylaştırmak için bulunmuştur.

> **Ders sonrası not:** Hoca tablodan 1 olan satırları okurken bir satırı "X yok, Y yok, Z var" diye okudu. Bu satırda ($z = 1$) $\overline{z} = 0$ olduğu için $F = 0$'dır. Doğru satırlar yalnız minterm 2, 4 ve 6'dır (Python ile kontrol edildi).

> **Ders sonrası not:** Slayttaki çözümün dağılma adımında son terimde $y$ eksik yazılmıştı. Hoca bunu fark etti ve terimi $\overline{x}y\overline{z}$ olarak düzeltti.

> **Ders sonrası not:** Hoca slayttaki "değişmezlik kanunu" adının $x + x = x$ kuralına karşılık geldiğini buldu. Bu kural İngilizcede idempotent law'dur; Türkçe kaynaklarda "tek kuvvet" ya da "eşgüçlülük" diye de geçer. Değişme (commutative) kuralı başka bir kuraldır.

## 7. Mantık Kapılarıyla Devre Çizimi ve Yarım Toplayıcı

Hoca bu bölümün ayrıntısının lojik (sayısal tasarım) dersinde görüleceğini, burada yalnız fikrin verileceğini söyledi.

### 7.1 Kapılar ve çok girişli kapı

OR kapısı, AND kapısı ve tümleyen alan inverter (NOT kapısı) gösterildi. Bir OR kapısı iki girişli çizilir, ama üç giriş varsa üç girişli tek bir OR kapısı çizilebilir. Ya da önce iki giriş bir OR kapısında toplanır, çıkışı üçüncü değişkenle birlikte ikinci bir OR kapısına verilir. İki gösterim aynı işi yapar.

### 7.2 Bir ifadeyi kapılarla çizmek

Bir ifade kapılarla çizilirken her işlem için bir kapı konur. Örneğin $\overline{x}y$ gibi bir terim için $x$ bir inverterdan geçirilir ve $y$ ile bir AND kapısına verilir. Terimlerin sonuçları bir OR kapısında toplanır. Slayttaki diğer örneklerde de aynı yol izlendi: $x$ ile $y$ toplanıp $\overline{x}$ ile çarpıldı; bir başka örnekte $x$, $y$, $z$ toplanıp tümleyenlerinin çarpımıyla AND'lendi.

<!-- BELİRSİZ: Slayttaki devre örneklerinin tam ifadeleri altyazıda okunmuyor. Hocanın anlatımına göre örnekler büyük olasılıkla $xy + \overline{x}y$, $(x + y)\overline{x}$ ve $(x + y + z)\overline{x}\,\overline{y}\,\overline{z}$ biçimindedir. -->

Hoca bir örnekte tümleyenin bir toplamın üzerinde olduğunu gösterdi ve şunu söyledi: Bunu tam slayttaki gibi kurmak zorunda değilsiniz. İfadeyi De Morgan ile açıp farklı bir kapı düzeniyle de gerçekleyebilirsiniz; bu konuda esneklik çoktur.

Aynı giriş birden fazla kapıya gidiyorsa dışarıdan yeni bir giriş açmaya gerek yoktur. Slayttaki bir gösterimde $x$ girişi yukarıdan alınıp başka bir kapıya, $y$ girişi de başka bir kapıya bağlanmıştı; dört ayrı girişe gerek yoktur, tel dallandırılır. Çizimde iki telin birbirinin üstünden geçmesi, bağlı oldukları anlamına gelmez.

### 7.3 Neden sadeleştirme?

Hoca sadeleştirmenin pratik nedenini anlattı. Bir ifadeyi gerçeklemek için iki OR kapısı ve beş NOT kapısı gerekebilir, ama elinizde o kadar kapı olmayabilir. Bu kadar malzeme kullanıldığında kartın (board) üzerinde de yer kalmaz. Fonksiyon sadeleştirildiğinde kapı sayısı birden düşer; örneğin OR, NOT ve AND kapısı sayıları bire inebilir. Karnaugh haritaları bu işe yarar: ne kadar sade ifade elde edilirse gerçeklemesi o kadar kolay olur.

### 7.4 Yarım toplayıcı

Hoca öğrencilere sayısal tasarım dersinde nerede olduklarını sordu. Bir öğrenci Karnaugh çizimlerini gördüklerini, ama devreleri ayrıntılı görmediklerini söyledi. Hoca o derste yarım toplayıcı (half adder), tam toplayıcı (full adder) ve çıkarıcı (subtractor) devreleri tasarlayacaklarını söyledi. **Yarım toplayıcı iki biti, tam toplayıcı üç biti toplar.**

İki bit $x$ ve $y$ toplanınca iki çıkış oluşur: toplam (sum, $s$) ve elde (carry, $c$). Hoca bunu onluk tabandaki toplamaya benzetti: $9 + 2 = 11$'de olduğu gibi, $1 + 1 = 2$ iki tabanında yazılamaz; elde 1 olur, toplam basamağına 0 yazılır.

| $x$ | $y$ | $c$ | $s$ |
| :-: | :-: | :-: | :-: |
| 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 |
| 0 | 0 | 0 | 0 |

Devreyi tasarlamak için toplamı veren bir devre ve eldeyi veren bir devre gerekir. Elde yalnız $x$ ve $y$'nin ikisi de 1 iken vardır: $c = xy$. Toplam için:

$$s = (x + y)\,\overline{(xy)} = x \oplus y$$

Hoca bunu $x = 1$, $y = 0$ için izledi: $x + y = 1$; $xy = 0$, inverterdan geçince 1; bu iki değer AND kapısından geçince $s = 1$ çıkar.

> **Ders sonrası not:** Hoca bu izlemenin son adımını "bir ile biri topladım" diye söyledi. Slayttaki devrede son kapı AND kapısıdır; $1 \cdot 1 = 1$ olur. Sonuç ($s = 1$) doğrudur.

> **Ders sonrası not:** Hoca tekrar kısmında XOR için "aklımıza çıkarma gelsin" demişti. Daha doğru ifade: XOR, 2'ye göre (modulo 2) toplamadır. Yarım toplayıcının toplam bitini verir. Girişler aynıysa 0, farklıysa 1'dir.

Hoca, lojik dersinde toplam ve elde çıkışlarının ayrı ayrı tasarlanıp birlikte kullanılacağını söyledi.

## 8. Karnaugh Haritasına Giriş

Dersin ikinci yarısında hoca, önceden kâğıt üzerinde çektiği dört videoyu Zoom'dan oynattı. Slaytla anlatmanın zor olduğunu, adım adım tahtaya yapıyormuş gibi anlatmak istediğini söyledi. Video paylaşımı ilk denemelerde çalışmadı; anlatım yaklaşık 01:40:00'te oturdu.

### 8.1 Tanım ve neden gerekli olduğu

Karnaugh haritası (Karnaugh map), Bool cebrindeki ifadeleri sadeleştirmek için kullanılan bir yöntemdir. Sadeleştirilecek ifade bir fonksiyondur ve 1, 2, 3, 4, 5, 6 değişkenli olabilir. Fonksiyonu daha az terimle ve daha az değişkenle ifade etmek işleri kolaylaştırır.

Fonksiyon Bool cebri kurallarıyla da sadeleştirilebilir. Ama bu daha zahmetlidir, hata yapma ihtimali daha yüksektir ve olması gereken en sade sonuç elde edilemeyebilir. Karnaugh haritaları bu işi hızlandırır ve hatadan daha arınmış hâle getirir.

Karnaugh haritasını Maurice Karnaugh 1953'te ortaya attı. Benzer bir yöntemi bir yıl önce, 1952'de Edward Veitch önermişti; Karnaugh bunu geliştirdi.

> **Ders sonrası not:** Altyazıda bu ad "Edward Wage" diye geçiyor. Doğru ad Edward Veitch'tir (Veitch diyagramı, 1952).

### 8.2 Kaç değişkene kadar?

Tek değişkenli bir fonksiyon, örneğin $F = A$, daha fazla sadeleştirilemez. Bu yüzden sadeleştirilecek fonksiyon en az iki değişkenlidir. Hocaya göre Karnaugh haritaları 6 değişkene kadar kullanılır. Ayrık matematik dersinde 4 değişkene kadar gösterilecek; daha fazlası lojik ve sayısal tasarım derslerinde görülecek.

## 9. İki Değişkenli Karnaugh Haritaları

### 9.1 Örnek 1: $F(A, B) = AB + \overline{A}B$

**Bool cebriyle.** $B$ ortak paranteze alınır: $F = B(A + \overline{A})$. $A$ ister 0 ister 1 olsun, $A + \overline{A} = 1$'dir: $A = 0$ ise $0 + 1 = 1$, $A = 1$ ise $1 + 0 = 1$. Sonuç $F = B \cdot 1 = B$. Terim sayısı az olduğu için bu kolaydı; terim sayısı arttıkça bu kadar hızlı yapılamaz. Bu yüzden Karnaugh haritası kullanılır.

**Haritayı çizmek.** İki değişken varsa $2^2 = 4$ durum vardır: $A$ ve $B$'nin ikisinin de olması, yalnız $A$'nın olması, yalnız $B$'nin olması, ikisinin de olmaması. Bunun dışında bir durum olamaz. Bu yüzden harita dört gözlüdür. Bir değişken üstte, öbürü solda yazılır; olmama durumu 0, olma durumu 1 ile etiketlenir.

**Mintermleri yerleştirmek.** Her gözün köşesine o gözün ondalık karşılığı yazılır. $A$ yok, $B$ yok: $00_2 = 0$. $A$ yok, $B$ var: $01_2 = 1$. $A$ var, $B$ yok: $10_2 = 2$. $A$ var, $B$ var: $11_2 = 3$.

| $B$ / $A$ | 0 | 1 |
| :-: | :-: | :-: |
| 0 | m0 | m2 |
| 1 | m1 | m3 |

**Fonksiyonu yerleştirmek.** Birinci terim $AB$: $A$'nın olduğu sütun ile $B$'nin olduğu satırın kesiştiği göz m3'tür; buraya 1 konur. İkinci terim $\overline{A}B$: $A$'nın olmadığı sütun ile $B$'nin olduğu satırın kesiştiği göz m1'dir; buraya da 1 konur. Fonksiyonda olmayan gözlere 0 yazılır.

Bu fonksiyon mintermlerle kısaca şöyle yazılır:

$$F(A, B) = \sum m(1, 3)$$

**Gruplamak.** Amaç 1'leri gruplamaktır. Ama gruplar rastgele seçilmez: 2'nin kuvvetleri cinsinden olabilecek en büyük gruplar kurulur. İki değişken için en büyük grup $2^2 = 4$'lüdür. Dört 1 yoktur. Bir aşağı inilir: $2^1 = 2$'li grup var mı? Var: $B$ satırındaki iki 1. Açıkta 1 kalmadığı için gruplama biter.

Gruplar her zaman satır ya da sütun boyunca düz, kare ya da dikdörtgen olmalıdır. Birbiriyle 90 derecelik açı yapan, "L" biçimli gruplar ya da çapraz (diagonal) gruplar alınamaz. Örneğin 2'nin kuvveti kadar dört tane 1 olsa bile, bunlar "L" biçiminde ya da çaprazda duruyorsa tek grup olarak alınmaz.

**Grubu okumak.** Grubun içindeki gözlerden sütun etiketlerine doğru yukarı çıkılır: Birinde $A$ var, öbüründe yok; ortak değişken yoktur. Satır etiketine bakılır: İkisinde de ortak olan $B$'nin olmasıdır. Grubun değeri $B$'dir. Sonuç Bool cebriyle bulunanla aynıdır:

$$F = B$$

### 9.2 Örnek 2: $F(A, B) = \sum m(0, 2, 3)$

Mintermler açık hâlde yazılırsa: m0 = $\overline{A}\,\overline{B}$, m2 = $A\overline{B}$, m3 = $AB$. Yani $F = \overline{A}\,\overline{B} + A\overline{B} + AB$. Haritada m0, m2 ve m3 gözlerine 1, m1 gözüne 0 konur.

Dörtlü grup yoktur, çünkü dört tane 1 yok. İkili grup aranır: Örneğin $A$ sütunundaki m2 ve m3 bir ikili gruptur. Ama açıkta m0 kaldı, devam edilmelidir.

Burada önemli bir soru var: Açıkta kalan 1 için hemen birli gruba ($2^0$) mi inilmeli, yoksa önce başka bir ikili grup aranmalı mı? Amaç alınabilecek en büyük grupları almak olduğu için önce başka ikili grup aranır. Burada yeni bir kural ortaya çıkar:

> **Hocanın vurgusu:** Alınabilecek en büyük grubu almaya yardım ediyorsa, daha önce gruplanmış bir 1 başka bir grupta tekrar kullanılabilir.

m0 ile m3 çaprazdır, birlikte alınamaz. Bu yüzden m0, daha önce gruplanmış m2 ile $\overline{B}$ satırında ikili grup olur. Hoca bunu ortak paranteze alınmış bir ifade gibi düşünmeyi önerdi: m2 iki grupta da geçer. Açıkta 1 kalmadı.

Hoca bir uyarı da ekledi: Bir dörtlü grup alındıktan sonra onun tamamen içinde kalan bir ikili grup ayrıca alınamaz. Grup içinde grup olur; büyük grup küçüğü olduğu gibi kapsar. Bu örnekte böyle bir kapsama yoktur.

Okuma: Dikey grup ($A$ sütunu) için sütundan yukarı çıkılır, ikisinde de $A$ vardır; satırlarda ortak değişken yoktur. Değeri $A$'dır. Yatay grup ($\overline{B}$ satırı) için sütunlarda ortak değişken yoktur; satırda ortak olan $B$'nin olmamasıdır. Değeri $\overline{B}$'dir.

$$F = A + \overline{B}$$

### 9.3 Örnek 3: $F(A, B) = \sum m(0, 1, 2, 3)$

Dört minterm de vardır; dört göze de 1 konur. $2^2 = 4$'lü bir grup vardır: bütün harita. Açıkta 1 kalmaz. Değişkenlerle yazılabilecek bütün durumlar fonksiyonda varsa sadeleştirilmiş hâl 1'dir:

$$F = 1$$

### 9.4 İki değişkenli haritaların özeti

Hoca videonun sonunda kuralları özetledi:

- Dört farklı durum olduğu için harita dört gözlüdür: $A$'nın olmaması ve olması, $B$'nin olmaması ve olması.
- Etiketler belirli bir kurala göre konur. Etiketler rastgele yerleştirilirse mintermler düzgün yerleşmez. Düzgün yerleştirilirse fonksiyon mintermlerle verildiğinde 1'ler hemen konur.
- Minterm, gözdeki değişkenlerin 0-1 değerlerinin ondalık karşılığıdır. Fonksiyon açık hâliyle ya da mintermler cinsinden verilebilir.
- Fonksiyonda olan mintermlere 1, olmayanlara 0 yazılır.
- Gruplamada önce değişken sayısına göre 2'nin en büyük kuvveti kadar gruplar aranır. Aynı büyüklükte bir değil iki, üç, dört grup çıkabilir. Önemli olan grupların birbirinin içinde kalmamasıdır.
- Çapraz ya da 90 derecelik açı yapan gruplar alınmaz.
- Okurken grubun sütunlarından ve satırlarından bakılır. Ortak olan değişkenler AND'lenir. Gruplar OR'lanarak sadeleştirilmiş hâl bulunur.

## 10. Üç Değişkenli Karnaugh Haritaları ve Gray Kodu

Üç değişkenli bir fonksiyonda en fazla $2^3 = 8$ terim (minterm) olabilir.

### 10.1 Bir terimde eksik değişken

Hocanın örnek fonksiyonu:

$$F(A, B, C) = AB + \overline{A}B + AC$$

Üç değişkenli bir fonksiyonda her terimin üç değişkeni de içermesi gerekmez. Örneğin $AC$ teriminde $B$ yoktur. Bu terim aslında $ABC + A\overline{B}C$ toplamıdır: $AC$ ortak paranteze alınırsa $AC(B + \overline{B}) = AC \cdot 1 = AC$ olur. Yani $AC$ terimi hem $B$'nin olduğu hem de olmadığı durumu içinde barındırır.

### 10.2 Haritanın çizimi ve Gray kodu

İlk iki değişken ($A$, $B$) üste, $C$ sola yazılır. Üstteki etiketler 00, 01, 11, 10 sırasıyla yazılır: $A$ yok $B$ yok, $A$ yok $B$ var, $A$ var $B$ var, $A$ var $B$ yok. Soldaki etiketler $C$ yok (0) ve $C$ var (1)'dir.

Bu etiketlerin ondalık karşılıkları 0, 1, 3, 2'dir. "Neden 0, 1, 2, 3 diye yazılmadı?" sorusunun cevabı Gray kodudur (Gray code).

Hoca önce üç bitlik ikilik (binary) kodu 0'dan 5'e kadar yazdı. İkilik kodda bir durumdan ötekine geçerken bazen 1, bazen 2, bazen 3 bit birden değişir: 0'dan 1'e geçerken 1 bit, 2'den 3'e geçerken 2 bit, 3'ten 4'e geçerken 3 bit değişir. Gray kodunda ise bir durumdan sonrakine geçerken yalnız bir bit değişir.

Gray kodunu yazarken her adımda yalnız bir bit değiştirilir ve değiştirilecek bit sağdan başlanarak aranır. Sağdaki biti değiştirmek önceki bir koda geri götürüyorsa bir soldaki bit denenir:

| Ondalık | İkilik | Gray |
| :-: | :-: | :-: |
| 0 | 000 | 000 |
| 1 | 001 | 001 |
| 2 | 010 | 011 |
| 3 | 011 | 010 |
| 4 | 100 | 110 |
| 5 | 101 | 111 |

Karnaugh haritasında gerçek bir sadeleştirme yapmak için etiketler Gray koduna göre, komşu iki göz yalnız bir bitte farklı olacak şekilde yerleştirilir: 00, 01, 11, 10. Etiketler rastgele konmaz.

> **Ek bilgi (derste anlatılmadı):** Gray sırasının sadeleştirmeyle ilişkisi şudur: Komşu iki göz tek bir değişkende farklı olduğu için bu iki gözün mintermlerinin toplamı, o değişken için $a + \overline{a} = 1$ özdeşliğiyle sadeleşir. Örneğin $\overline{A}BC + ABC = BC(\overline{A} + A) = BC$. Bir grubu "sütunlardan ve satırlardan bakıp ortak olanı almak" bu sadeleştirmenin kısa yoludur.

### 10.3 Mintermlerin yerleşimi

Gözlere mintermler yazılır. $C = 0$ satırında 0, 2, ... ve $C = 1$ satırında 1, 3, ... diye gider; ama üçüncü ve dördüncü sütunlar Gray kodu yüzünden yer değiştirdiği için mintermler de yer değiştirir:

| $C$ / $AB$ | 00 | 01 | 11 | 10 |
| :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 2 | 6 | 4 |
| 1 | 1 | 3 | 7 | 5 |

Hoca iki gözü kontrol etti. $A$, $B$, $C$ üçü de 1 ise $111_2 = 7$'dir. $A$ var, $B$ yok, $C$ var ise $101_2 = 5$'tir. Bu iki göz gerçekten 7 ve 5'tir.

### 10.4 Örnek 1: $F = AB + \overline{A}B + AC$

**Yerleştirme.**

- $AB$: $A$ ve $B$'nin olduğu sütun (11). $C$ hakkında bir şey söylenmiyor, yani hem $C$ hem $\overline{C}$ vardır. Sütunun iki gözüne de 1 konur: m6, m7.
- $\overline{A}B$: $A$'nın olmadığı ve $B$'nin olduğu sütun (01). Yine $C$'nin iki durumu da vardır: m2, m3.
- $AC$: $A$'nın olduğu sütunlar 11 ve 10'dur; $B$ yoktur, yani iki durumu da vardır. $C$'nin olduğu satırla kesişen gözler m7 ve m5'tir.

Hoca bunu mintermlerle de yazdı. $AB$ terimine $C$ eklenirse 7, $\overline{C}$ eklenirse 6 olur. $\overline{A}B$ terimine $C$ eklenirse 3, $\overline{C}$ eklenirse 2 olur. $AC$ terimine $B$ eklenirse 7, $\overline{B}$ eklenirse 5 olur. Hoca önce 2, 3, 5, 7 yazdı, sonra 6'nın eksik kaldığını fark edip ekledi:

$$F = \sum m(2, 3, 5, 6, 7)$$

Hoca, mintermleri küçükten büyüğe sıralı yazmanın yerleştirmeyi kolaylaştırdığını söyledi.

**Gruplama.** Sekizli grup yok, çünkü sekiz tane 1 yok. Dörtlü grup var: 01 ve 11 sütunlarındaki dört göz (m2, m3, m6, m7). Başka dörtlü yok. Hoca burada "yılan gibi", köşeleri 90 derece olan şekillerin grup olarak alınamayacağını tekrarladı. İkili gruba inilir. Açıkta tek bir 1 (m5) kaldı; kural gereği daha önce gruplanmış m7 ile ikili grup kurulur. Çapraz alınmaz.

**Okuma.** Dörtlü grubun iki sütununda da ortak olan $B$'dir; satırlarda ortak değişken yoktur. Değeri $B$'dir. İkili grubun sütunlarında ortak olan $A$'dır; satırında ortak olan $C$'dir. Değeri $AC$'dir.

$$F = B + AC$$

Hoca terim sayısının üçten ikiye düştüğünü, değişken sayısında da büyük azalma olduğunu söyledi (Python ile kontrol edildi).

### 10.5 Örnek 2: $F = \sum m(0, 1, 4, 5, 6, 7)$ ve kenar komşuluğu

Hoca etiketleri bundan sonra "A var, A yok" diye değil, 00, 01, 11, 10 diye yazacağını söyledi. m2 ve m3 dışında bütün gözlerde 1 vardır.

Sekizli grup yok. Dörtlü grup aranır: 11 ve 10 sütunları (m6, m7, m4, m5) bir dörtlüdür. Başka dörtlü yok gibi görünür, ama vardır. Hoca bunu haritayı katlayarak anlattı:

- Alt satır ile üst satır birleştirilebilir.
- Sol kenar ile sağ kenar birleştirilebilir.
- Satır ve sütun sayısı eşitse, harita bir bohça gibi hem yatay hem dikey katlanabilir; o zaman dört köşe bir araya gelir ve bir grup oluşturabilir.

Bu örnekte sağ ve sol kenar katlanırsa 00 sütunundaki iki 1 (m0, m1) ile 10 sütunundaki iki 1 (m4, m5) komşu olur ve bir dörtlü oluşur. Açıkta 1 kalmaz.

**Okuma.** Birinci dörtlünün sütunlarında ortak olan $A$'dır; satırlarda ortak yoktur: $A$. Kenarlardan birleşen dörtlünün sütunlarında ortak olan $B$'nin olmamasıdır; satırlarda ortak yoktur: $\overline{B}$.

$$F = A + \overline{B}$$

Hoca, aynı fonksiyonun açık hâlde altı terimle, her biri üç değişkenli yazılacağını hatırlattı; sadeleştirilmiş hâliyle çok daha hızlı çalışılır.

### 10.6 Örnek 3: $F = \sum m(1, 2, 3, 4, 5, 6, 7)$

Yalnız m0 gözünde 0 vardır. Sekizli grup yok. Dörtlü grup var: 11 ve 10 sütunları. Açıkta 1 kaldığı için devam edilir. Başka dörtlü aranır: Açıkta kalan üç 1 kendi başına bir dörtlü oluşturmaz, "yamuk" bir grup da alınamaz. Ama daha önce gruplanmış 1'ler kullanılarak 01 ve 11 sütunları bir dörtlü olur. Açıkta yine bir 1 (m1) kalır.

> **Hocanın vurgusu:** Burada dikkatsizlikle ikili ya da birli grup alırsanız yanlış yapmış olursunuz. Önce başka dörtlü var mı diye bakın.

Gerçekten başka dörtlü vardır: $C = 1$ satırının tamamı (m1, m3, m7, m5). Açıkta 1 kalmaz.

**Okuma.** 11 ve 10 sütunlarının dörtlüsü: yalnız $A$ ortak. Ortadaki dörtlü: yalnız $B$ ortak. Yatay dörtlü: dört sütunda ortak değişken yok, satırda $C$ ortak.

$$F = A + B + C$$

### 10.7 Videodaki ödev

Hoca üç değişkenli videonun sonunda bir ödev verdi: $F(A, B, C) = \sum m(0, 3, 4, 6, 7)$ fonksiyonunun sadeleştirilmiş hâli nedir? Çözüm derste verilmedi; "Örnek Sorular" bölümündedir.

## 11. Dört Değişkenli Karnaugh Haritaları

Hoca, üç değişkende her şey öğrenildiği için dört değişkenin artık kolay olduğunu söyledi. Dört değişkenle 16 farklı minterm olabilir.

Hoca önce değişkenlerle bir fonksiyon yazmaya başladı, terim uydurmakta zorlandığını söyledi. Sonra yerleştirmeyi kolaylaştırmak için fonksiyonu doğrudan mintermlerle vermeye karar verdi.

### 11.1 Haritanın çizimi

$A$, $B$ üste; $C$, $D$ sola yazılır. Üst etiketler Gray koduyla 00, 01, 11, 10'dur. Aynı kural $C$ ve $D$ için de uygulanır: 00, 01, 11, 10. Üç değişkende sütunlar yer değiştiriyordu; burada üçüncü ve dördüncü satırlar da yer değiştirir. Mintermler yerleştirilirken hem sütunda hem satırda atlama yapılır:

| $CD$ / $AB$ | 00 | 01 | 11 | 10 |
| :-: | :-: | :-: | :-: | :-: |
| 00 | 0 | 4 | 12 | 8 |
| 01 | 1 | 5 | 13 | 9 |
| 11 | 3 | 7 | 15 | 11 |
| 10 | 2 | 6 | 14 | 10 |

Hoca iki gözü kontrol etti. $A$, $B$, $C$, $D$ dördü de 1 ise $1111_2 = 15$'tir. $A$ var, $B$ yok, $C$ var, $D$ yok ise $1010_2 = 8 + 2 = 10$'dur.

### 11.2 Örnek 1: $F = \sum m(1, 5, 7, 9, 10, 11, 13, 15)$

On altılı grup yok, çünkü on altı 1 yok. Sekizli grup da kurulamaz. Dörtlü gruplar aranır. Hoca sırasıyla şu dörtlüleri aldı:

- 11 ve 10 sütunları ile 01 ve 11 satırları: m13, m15, m9, m11. Okunuşu $AD$.
- 01 ve 11 sütunları ile 01 ve 11 satırları: m5, m7, m13, m15. Okunuşu $BD$.
- 01 satırının tamamı: m1, m5, m13, m9. Dört sütunda ortak değişken yok; satırda $C$'nin olmaması ve $D$'nin olması ortak. Okunuşu $\overline{C}D$.

Başka dörtlü yoktur. Açıkta m10 kalır. İkili gruba inilir: m10, daha önce gruplanmış m11 ile ikili grup olur. Bu grubun sütununda $A$ var, $B$ yok; iki satırında da $C$ var. Okunuşu $A\overline{B}C$.

Hoca sonucu okurken önce "$AD$ artı..." diye başladı, sonra "pardon, şu yok" diyerek $AD$ terimini çıkardı:

$$F = A\overline{B}C + BD + \overline{C}D$$

$AD$ dörtlüsünün dört gözü de diğer gruplar tarafından kapsanır: m9 ve m13 $\overline{C}D$ ile, m15 $BD$ ile, m11 $A\overline{B}C$ ile. Bu yüzden $AD$ gereksiz bir gruptur; fonksiyonu değiştirmez, yalnız fazladan bir terim ekler. Hocanın verdiği üç terimli sonuç en kısa çözümdür (Python ile kontrol edildi). Bu tür gereksiz grup hatası Bölüm 12'de ayrıca vurgulandı.

### 11.3 Örnek 2: $F = \sum m(0, 2, 4, 5, 7, 8, 10)$ ve köşe grubu

Hoca soruyu sorarken, video sonunda anlaşılmayan yerleri sesli sormalarını istedi. Haritaya m0, m2, m4, m5, m7, m8, m10 gözlerine 1, diğerlerine 0 konur.

On altılı ve sekizli grup yok. Dörtlü grup var mı? Birçoğunun "yok" diyeceğini söyledi. Ama harita bohça gibi katlanınca, yani sağ ve sol kenar ile üst ve alt kenar birleştirilince, dört köşe (m0, m2, m8, m10) komşu olur ve bir dörtlü oluşturur. Başka dörtlü yoktur.

İkili gruplara inilir. Açıkta m4, m5, m7 kalmıştır. m7'nin tek komşu 1'i m5'tir; bu yüzden m5-m7 grubu alınır. m4 için iki seçenek vardır: m4-m5 ikilisi ya da m4-m0 ikilisi.

> **Hocanın vurgusu:** İki seçenekten birini alırım, ikisini birden kesinlikle almam. Daha önce gruplanmış bir 1, açıkta kalan başka bir 1'i gruplamak için gerekmiyorsa tekrar gruplanmaz.

Hoca m4-m5 ikilisini seçti.

**Okuma.**

- Köşe grubu: Sütunlarda ortak olan $B$'nin olmaması; satırlarda ortak olan $D$'nin olmaması. Değeri $\overline{B}\,\overline{D}$.
- m5-m7: $A$ yok, $B$ var; satırlarda yalnız $D$ ortak. Değeri $\overline{A}BD$.
- m4-m5: $A$ yok, $B$ var; satırlarda yalnız $C$'nin olmaması ortak. Değeri $\overline{A}B\overline{C}$.

$$F = \overline{B}\,\overline{D} + \overline{A}BD + \overline{A}B\overline{C}$$

m4 için öbür seçenek (m0-m4, yani $\overline{A}\,\overline{C}\,\overline{D}$) alınsaydı da en kısa çözüm elde edilirdi: $F = \overline{B}\,\overline{D} + \overline{A}BD + \overline{A}\,\overline{C}\,\overline{D}$. İki sonuç da aynı fonksiyonu verir (Python ile kontrol edildi).

> **Ders sonrası not:** Videoda köşe grubu "$B$'nin olmaması ve $D$'nin olması" diye, yani $\overline{B}D$ olarak okundu. Derste videoyu izlerken öğrenciler bunu fark etti. Hoca videoyu geri alıp hatasını kabul etti: köşelerde $D = 0$ olduğu için doğrusu $\overline{B}\,\overline{D}$'dir. Hoca düzeltmeyi USİS üzerinden e-postayla da duyurdu. $\overline{B}D$ ile yazılan sonuç fonksiyonu vermez (Python ile kontrol edildi).

## 12. Alıştırmaların Çözümü ve Gereksiz Grup Hatası

Dört değişkenli videonun sonunda hoca üç alıştırma verdi ve mintermlerin sırayla verilmek zorunda olmadığını söyledi. Öğrencilere beş dakika süre verdi, sonra çözüm videosunu oynattı.

### 12.1 Alıştırma 1: $F = \sum m(1, 3, 4, 5, 6, 7, 9, 11, 13, 15)$

On altılı grup yok. Sekizli grup var: 01 ve 11 satırlarının tamamı (m1, m5, m13, m9, m3, m7, m15, m11). Başka sekizli yok. Açıkta m4 ve m6 kalır. Daha önce gruplanmış 1'ler kullanılarak 01 sütununun tamamı (m4, m5, m7, m6) bir dörtlü olur. Açıkta 1 kalmaz.

**Okuma.** Sekizlinin dört sütununda ortak değişken yok; satırlarda ortak olan yalnız $D$'nin olmasıdır: $D$. Dörtlünün sütununda $A$ yok, $B$ var; dört satırda ortak değişken yok: $\overline{A}B$.

$$F = \overline{A}B + D$$

Bir öğrenci beş dakikada yalnız haritayı çizebildiğini söyledi. Hoca, kendisinin de zamanla tabloları silip yeniden kullanarak çalışmaya başladığını, ama anlayarak çözmeye devam etmek gerektiğini söyledi.

### 12.2 Alıştırma 2: $F = \sum m(1, 3, 9, 11, 12, 13, 14, 15)$

Bu örnekte hoca bilerek bir hata gösterdi. On altılı ve sekizli grup yok. Dörtlü gruplar aranırken önce bir dörtlü alındı, sonra ikinci bir dörtlü alındı. Ardından sağ ve sol kenar katlanınca komşu olan 1'lerden bir dörtlü daha bulundu. Açıkta 1 kalmadı.

"Bunu doğru sadeleştirdim diyebilir miyim?" Hayır: İlk alınan dörtlünün bütün gözleri, sonradan alınan iki dörtlünün içinde kalmaktadır. Bu grup çıkarılınca hiçbir 1 açıkta kalmaz; yani o grubun hiçbir anlamı yoktur.

<!-- BELİRSİZ: Gereksiz grubun adı altyazıda söylenmiyor. Bu fonksiyonda diğer iki dörtlü tarafından tamamen kapsanan tek dörtlü $AD$'dir (m9, m11, m13, m15). -->

Geriye iki grup kalır:

- 11 sütunu (m12, m13, m15, m14): sütunda $A$ ve $B$ ortak; satırlarda ortak yok. Değeri $AB$.
- Kenar komşuluğuyla 00 ve 10 sütunları ile 01 ve 11 satırları (m1, m3, m9, m11): sütunlarda $B$'nin olmaması ortak; satırlarda $D$ ortak. Değeri $\overline{B}D$.

$$F = AB + \overline{B}D$$

> **Hocanın vurgusu:** Bu çok önemli bir problemdir ve genelde yapılan bir hatadır. Grupları gördüğünüz anda hemen almayın. Sonunda bakın: Fazladan aldığınız bir grup var mı? Gereksiz bir grup kalırsa fonksiyon bir terim fazla olur; elde edilen ifade fonksiyonun sadeleşmiş hâli olmaz. Amaç, en az sayıda grupla ve alınabilecek en büyük, 2'nin kuvveti büyüklüğünde gruplarla sonuca ulaşmaktır.

Hoca uyarıyı bir kez daha tekrarladı: Bir dörtlüyü görmeden başka bir dörtlü alıp sonra kalan 1'leri ikili ya da dörtlü gruplarla tamamlarsanız, yalnız sadeleştirmiş, ama en sade sonucu bulamamış olursunuz.

Gereksiz grubun eklenmesi fonksiyonun değerini değiştirmez; $AB + \overline{B}D + AD$ da aynı fonksiyonu verir. Ama en kısa ifade iki terimlidir (Python ile kontrol edildi).

### 12.3 Alıştırma 3: $F = \sum m(2, 7, 8, 10, 12, 13, 14)$

Hoca bunun "oldukça kötü bir fonksiyon" olduğunu söyledi. On altılı ve sekizli grup yok.

- **Dörtlü:** 11 ve 10 sütunları ile 00 ve 10 satırları (m12, m14, m8, m10). Sütunlarda $A$ ortak; satırlarda $D$'nin olmaması ortak. Değeri $A\overline{D}$. Başka dörtlü yok.
- **İkili:** m13 yalnız m12 ile komşudur: 11 sütunu, 00 ve 01 satırları. Sütunda $A$ ve $B$ var; satırlarda $C$'nin olmaması ortak. Değeri $AB\overline{C}$. Hoca bazı çiftlerin "tek taraflı" alınamayacağını, kenarlardan birleşen grupların bohça biçiminde olması gerektiğini söyledi.
- **Birli:** m7'nin hiçbir komşusunda 1 yoktur. Değeri $\overline{A}BCD$.
- **m2:** Videoda m2 tek başına birli grup olarak alındı ($\overline{A}\,\overline{B}C\overline{D}$).

**Soru:** Sol alttaki 1'i (m2) alırken sağ ve solu birleştirseydik, sol alttaki ile sağ alttaki (m10) ikili grup olmaz mıydı? **Cevap:** Hoca videoyu geri alıp baktı ve öğrencinin haklı olduğunu söyledi. m2 tek başına alınamaz; sağ ve sol kenar komşu olduğu için m2 ve m10 birlikte ikili grup oluşturur. Bu grubun sütunlarında $B$'nin olmaması ortaktır; satırda $C$ var, $D$ yok. Değeri $\overline{B}C\overline{D}$'dir. Hoca öğrencilerin bu hatayı görmesine çok sevindiğini, videoları defalarca çektiğini ve emeğinin boşa gitmediğini hissettiğini söyledi.

Düzeltilmiş sonuç:

$$F = A\overline{D} + AB\overline{C} + \overline{A}BCD + \overline{B}C\overline{D}$$

> **Ders sonrası not:** Videodaki çözüm m2'yi tek başına alıyordu ($\overline{A}\,\overline{B}C\overline{D}$). Bu ifade de fonksiyonu doğru verir, ama sadeleştirme eksiktir. Doğru gruplama m2 ile m10'u kenar komşuluğuyla birleştirmektir: $\overline{B}C\overline{D}$. Düzeltilmiş sonuç dört terimli en kısa çözümdür (Python ile kontrol edildi). Hoca bu düzeltmeyi de USİS grubuna e-postayla göndereceğini söyledi.

### 12.4 Değişkenlerle mi, mintermlerle mi?

**Soru:** Dört değişkenli videonun başında grafiği çizerken önce "$ABC$ artı ..." diye bir fonksiyon yazılmıştı; o örnek ne oldu? **Cevap:** Hoca o fonksiyonu haritaya geçirmeyi zahmetli bulduğunu, örneği bırakıp mintermlerle yeni bir örnek yazdığını söyledi. Değişkenlerle yazılan bir fonksiyonda eksik değişkenleri bulup hangi mintermlere denk geldiğini çıkarmak gerekir.

> **Hocanın vurgusu:** Fonksiyonları mintermler cinsinden yazmak çok daha kolaydır; hata yapma olasılığı neredeyse kalmaz.

## Örnek Sorular

Bu derste video ve kare kullanılmadı. Aşağıdaki sorular derste sözlü olarak sorulan ya da hocanın verdiği sorulardır.

**1.** (derste sözlü, 00:14:56) Arama motoruna "İstanbul OR Ankara" sorgusu gönderilirse hangi sayfalar gelir? "İstanbul AND Ankara" gönderilirse hangileri gelir?

> **Çözüm (derste verildi):** OR sorgusunda yalnız İstanbul geçen, yalnız Ankara geçen ve ikisi birlikte geçen sayfalar gelir. AND sorgusunda yalnız iki kelimenin birlikte geçtiği sayfalar gelir.

**2.** (derste sözlü, 00:16:50) Slayttaki Bool ifadesinin değeri nedir? <!-- BELİRSİZ: İfadenin tam yazılışı altyazıda okunmuyor; hocanın adımlarına göre büyük olasılıkla $1 \cdot 0 + \overline{(0 + 1)}$'dir. -->

> **Çözüm (derste verildi):** $0 + 1 = 1$, tümleyeni 0; $1 \cdot 0 = 0$; $0 + 0 = 0$.

**3.** (derste sözlü, 00:32:22) $n = 1$, $n = 2$ ve $n = 3$ olduğunda kaç farklı Bool fonksiyonu yazılabilir?

> **Çözüm (derste verilmedi):** Derste yalnız $n = 2$ için $2^{2^2} = 2^4 = 16$ bulundu. Aynı kuralla $n = 1$ için $2^{2^1} = 4$, $n = 3$ için $2^{2^3} = 256$ fonksiyon vardır (Python ile kontrol edildi).

**4.** (derste sözlü, 00:44:03; bonus sorusu 01:10:36) $x + yz = (x + y)(x + z)$ eşitliğini Bool cebri özdeşlikleriyle ispatlayınız.

> **Çözüm (derste verilmedi):** Sağ taraf dağılma ile açılır:
> $$(x + y)(x + z) = xx + xz + yx + yz$$
> Idempotent ($xx = x$): $x + xz + xy + yz$.
> Yutma ($x + xz = x$): $x + xy + yz$.
> Yutma ($x + xy = x$): $x + yz$.
> Sağ taraf sol tarafa eşittir. Eşitlik sekiz girişte de doğruluk tablosuyla kontrol edildi (Python).

**5.** (derste sözlü, 01:12:06) Tabloda verilen $F$ ve $G$ fonksiyonlarını tanımlayan Bool ifadelerini bulunuz.

> **Çözüm (derste verildi):** $F$ yalnız $x = 1, y = 0, z = 1$ satırında 1'dir: $F(x, y, z) = x\overline{y}z$. $G$, "$x$ ve $y$ var" ve "yalnız $y$ var" satırlarında 1'dir: $G(x, y, z) = xy\overline{z} + \overline{x}y\overline{z}$. <!-- BELİRSİZ: $G$'nin birinci teriminde $z$'nin değeri altyazıda söylenmiyor; Bölüm 6.1'deki nota bakın. -->

**6.** (derste sözlü, 01:16:17) $F(x, y, z) = (x + y)\overline{z}$ için çarpımların toplamı açılımını bulunuz.

> **Çözüm (derste verildi):** $F = 1$ olan satırlar m2, m4 ve m6'dır: $F = xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$. Özdeşliklerle çözüm Bölüm 6.3'tedir.

**7.** (derste sözlü, 02:27:33; ödev) $F(A, B, C) = \sum m(0, 3, 4, 6, 7)$ fonksiyonunu Karnaugh haritasıyla sadeleştiriniz.

> **Çözüm (derste verilmedi):** Haritada $C = 0$ satırında m0, m6, m4; $C = 1$ satırında m3, m7 gözleri 1'dir. Dörtlü grup kurulamaz. İkili gruplar:
> - m0 ile m4, sağ-sol kenar komşuluğuyla: $\overline{B}\,\overline{C}$.
> - m3 ile m7: $BC$.
> - m6, m7 ile ($AB$) ya da m4 ile ($A\overline{C}$) gruplanabilir.
>
> $$F = \overline{B}\,\overline{C} + BC + AB \quad \text{ya da} \quad F = \overline{B}\,\overline{C} + BC + A\overline{C}$$
> İki sonuç da üç terimli en kısa çözümdür (Python ile bütün asal terim kombinasyonları denenerek kontrol edildi).

**8.** (derste sözlü, 02:42:42) $F(A, B, C, D) = \sum m(1, 3, 4, 5, 6, 7, 9, 11, 13, 15)$ fonksiyonunu sadeleştiriniz.

> **Çözüm (derste verildi, 02:51:00):** Sekizli grup $D$ ve dörtlü grup $\overline{A}B$: $F = \overline{A}B + D$.

**9.** (derste sözlü, 02:43:13) $F(A, B, C, D) = \sum m(1, 3, 9, 11, 12, 13, 14, 15)$ fonksiyonunu sadeleştiriniz.

> **Çözüm (derste verildi, 02:53:49):** $F = AB + \overline{B}D$. Diğer iki grubun içinde kalan dörtlü gereksizdir.

**10.** (derste sözlü, 02:43:43) $F(A, B, C, D) = \sum m(2, 7, 8, 10, 12, 13, 14)$ fonksiyonunu sadeleştiriniz.

> **Çözüm (derste verildi, 02:58:05; düzeltme 03:00:00):** $F = A\overline{D} + AB\overline{C} + \overline{A}BCD + \overline{B}C\overline{D}$. m2 ile m10 kenar komşuluğuyla birleştirilir.

## Dersin Toparlaması

Bu derste mantık konusundan Bool cebrine geçildi. Bool cebri yalnız 0 ve 1 üzerinde çalışır; toplama OR, çarpma AND, tümleyen NOT'tur ve $1 + 1 = 1$'dir. $n$ değişkenli bir Bool fonksiyonu $2^n$ girişin her birine 0 ya da 1 atar; bu yüzden $2^{2^n}$ farklı fonksiyon vardır. Bool özdeşlikleri (idempotent, birim, yutan eleman, dağılma, De Morgan, yutma) ifadeleri dönüştürmeye ve ispatlamaya yarar. Ama hoca, eşitlikleri göstermenin ve fonksiyon yazmanın en güvenli yolunun doğruluk tablosu olduğunu kendi deneyimiyle gösterdi. Tablodaki 1 satırlarının mintermleri toplanarak çarpımların toplamı açılımı elde edilir. Mantık kapılarıyla devre çizimi ve yarım toplayıcı örneği, sadeleştirmenin neden gerekli olduğunu gösterdi: daha az terim, daha az kapı demektir.

Dersin ikinci yarısında Karnaugh haritaları iki, üç ve dört değişken için işlendi. Etiketler Gray koduyla 00, 01, 11, 10 sırasında yazılır; mintermler buna göre yerleşir. Gruplar 2'nin kuvveti büyüklüğünde, kare ya da dikdörtgen olur; önce en büyük grup aranır. Daha büyük bir grup kurmaya yarıyorsa gruplanmış bir 1 tekrar kullanılabilir. Haritanın sağ-sol ve üst-alt kenarları komşudur; dört köşe de bir grup olabilir. Gruplar okunurken ortak değişkenler AND'lenir, gruplar OR'lanır. Son olarak gereksiz grup hatası, yani başka grupların tamamen kapsadığı bir grubun sonuca fazladan terim eklemesi, vurgulandı. Hoca, Karnaugh haritalarının daha fazla değişkenli hâllerinin lojik ve sayısal tasarım derslerinde görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
