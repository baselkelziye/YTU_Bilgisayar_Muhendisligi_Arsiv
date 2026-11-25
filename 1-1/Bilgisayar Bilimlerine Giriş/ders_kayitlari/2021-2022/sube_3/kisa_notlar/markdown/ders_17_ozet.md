# Ders 17 Çalışma Özeti

## Genel Konular

- Bilgisayar için bilgi: tanımlayıcı ve buyurucu bilgi
  - Tanımlayıcı bilgi (declarative knowledge): insanın bildiği ya da çıkarabildiği gerçeklerin "bu böyledir" biçimindeki ifadesi; örneğin suyun belirli sıcaklıklar arasında sıvı olması (ekrandan, 00:15:00).
  - Bilgisayar bu gerçekleri bilemez; yalnız işlemcinin komut kümesinde tanımlı eylemleri çok yüksek hızda ve hatasız çalıştırabilir.
  - Buyurucu bilgi (imperative knowledge): bilgiyi, sonucu elde etmek üzere kesin, tek anlamlı komutlar (buyruklar) halinde ifade etmek. Bilgisayarlı hesaplamanın özünde tanımlayıcı bilginin buyurucu bilgiye dönüştürülmesi vardır.
  - Yumurta pişirme tarifi örneği: tarif bir buyurucu bilgidir, ama tava, ateşin derecesi, yağ miktarı, kabukların ne olacağı ve ne zaman durulacağı kesin söylenmezse herkes aynı şeyi anlamaz.
- Algoritmanın tanımı (ekrandan, 00:20:00)
  - Bir problemi çözmek için takip edilecek, sonlu sayıda adımdan oluşan çözüm akışının ifadesi.
  - Bir problemin mantıksal çözümünün adım adım nasıl gerçekleştirileceğinin tanımlanması. Sözle ifade edilebilir; herkesin aynı anlamı çıkarması için tanımlı sembollerden oluşan akış diyagramları kullanılabilir.
  - Belirli bir problemi çözmek için art arda uygulanacak kesin direktiflerden oluşan sonlu bir kümedir; mantıklı ve doğru tüm girdiler için doğrudur ve doğru çıktıyı sonlu bir zamanda üretir. Bunun dışındaki durumlar algoritma değildir.
  - Doğal dilin belirsizliği: "Flying planes can be dangerous" cümlesi hem "uçan uçaklar tehlikeli olabilir" hem "uçak uçurmak tehlikeli olabilir" diye okunabilir. Bu belirsizlik akış diyagramı gibi görsel ve tanımlı bir gösterime ihtiyaç doğurur.
- Algoritma kelimesinin kökeni (ekrandan, 00:25:00)
  - Ebû Ca'fer Muhammed bin Mûsâ el-Hârizmî (d. 780, Harezm; ö. 850, Bağdat), Pers gökbilimci ve matematikçi.
  - 825 yılında Arapça "Hisab al-jabr w'al-muqabala" adlı eser ("Hint rakamları ile hesap"); 1300'lerde Latinceye çeviri: "Algoritmi de numero Indorum". "Algoritma" ve "cebir" (algebra) kelimeleri buradan gelir.
  - Ders sonrası not: Hoca ve slayt cebir kitabıyla Hint rakamları kitabını tek eser gibi anlattı; büyük olasılıkla bunlar el-Hârizmî'nin iki ayrı eseridir ve "Algoritmi de numero Indorum" Hint rakamlarıyla hesap üzerine olan eserin Latince çevirisinin adıdır.
- Tanımdan direktife: Newton'ın karekök algoritması (ekrandan, 00:35:00)
  - Karekökün deklarasyonu: $y \cdot y = x$ (çıktının karesi girdiye eşittir). Bu tanım bilgisayara doğrudan anlatılamaz; adım adım komutlara dönüştürülmelidir.
  - Algoritma: 0. Başla. 1. $x$'i oku. 2. Eşik değeri $e$'yi oku. 3. Rastgele bir pozitif tamsayı $r$ oluştur. 4. $(r \cdot r - x) > e$ olduğu sürece: 4.1. $r$'yi $r$ ve $x/r$'nin ortalamasıyla güncelle. 5. $r$'yi yazdır. 6. Dur.
  - Koşulda mutlak değer olmalıdır: $|r \cdot r - x| > e$ (hoca sözlü olarak belirtti).
  - Örnek: $x = 16$, $e = 0.001$, $r = 3$; $r$ değerleri $3 \to 4.17 \to 4.0035 \to 4.000002$; çıktı 4'e çok yakın ama tam 4 değil.
  - Eşik sıfır verilirse (özellikle irrasyonel köklerde) algoritma sonlanmayabilir; eşik, "bu kadar yaklaşmak yeterli" demektir.
- Algoritmanın özellikleri
  - Anlaşılır olmak: adımlar, girdiler ve çıktılar net ve tek anlamlı olmalı.
  - Girdi: sıfır ya da daha fazla, iyi tanımlanmış girdi (örneğin rastgele sayı üretme girdi almayabilir). Tanım kümesi açıkça belirtilmeli (örneğin "yalnız pozitif tam sayılarla çalışır").
  - Çıktı: en az bir, iyi tanımlanmış çıktı.
  - Sonlanma: belirli bir adımdan sonra durmalı.
  - Yapılabilirlik: eldeki imkanlarla (işlemci sayısı, bellek) gerçekleştirilebilir olmalı.
  - Bağımsızlık: programlama dilinden bağımsız tanımlanmalı. Algoritma bir dilde yazıldığında program adını alır.
- Algoritma tasarımı: Polya'nın problem çözme adımları (ekrandan, 00:45:00)
  - 1. Problemi anlamak, 2. Çözüm planı oluşturmak, 3. Planı uygulamak (test), 4. Sonucu değerlendirmek (analiz).
  - İlk iş problemi makul (anlaşılır, açıklanabilir) biçimde tanımlamaktır.
  - Örnek: ön sıradaki en yaşlı öğrenciyi bulmak. Ön koşul: ön sırada öğrenci olmalı. Hedef: en yaşlıyı bulmak; herkes gerçek doğum gününü verir, aynı gün doğanlar aynı yaştadır, birden fazla en yaşlı varsa herhangi birini bildirmek yeterlidir.
  - Çözüm 1 (sıralı): soldan başla, ilk öğrencinin adını ve yaşını tahtaya yaz; sırada öğrenci olduğu sürece sor, daha yaşlıysa tahtadakini silip yenisini yaz; sonunda tahtadakini oku (ekrandan, 00:50:00).
  - Çözüm 2 (eleme turu): ön sırada birden fazla öğrenci olduğu sürece öğrencileri ikişerli grupla, tek kalanı tut, her çiftte genç olanı sıradan kaldır; kalan öğrenciyi yaz (ekrandan, 00:55:00).
- Sonucu değerlendirmek: algoritma analizi (ekrandan, 01:00:00)
  - "Daha iyi" hedefe göre değişir: kolay uygulanabilirlik, belirli bir girdi/ortam koşulu, hız, az yer harcama. Hız ile bellek arasında sık sık ödünleşim (trade-off) vardır.
  - Çözüm 1'de iş öğrenci sayısıyla doğru orantılıdır (7 öğrenci için 7 iş).
  - Çözüm 2'de de toplam 7 karşılaştırma yapılır, ama bir turdaki karşılaştırmalar aynı anda yapılabilirse süre tur sayısıyla, yani $\log_2 n$ ile orantılıdır (7-8 öğrenci için 3 tur). Öğrenci sayısı iki katına çıkınca süre yalnız bir tur artar.
  - Karşılaştırma başına 5 saniye ile: Çözüm 1 için $5n$ (100 öğrenci 500 s, 1 milyon öğrenci 5 milyon s); Çözüm 2 için $5\log_2 n$ (100 öğrenci yaklaşık 33 s, 1 milyon öğrenci yaklaşık 100 s).
- Algoritmayı ifade etmek (ekrandan, 01:20:00)
  - Düz yazı (etken ve buyuran cümleler): okuyanlar farklı yorumlayabilir.
  - Sözde kod (pseudocode): günümüzde özellikle ayrıntıdan kaçınırken sık kullanılır.
  - Akış diyagramı: görsel ve evrensel semboller kullandığı için herkes aynı şeyi anlar.
- Akış diyagramı bileşenleri (ekrandan, 01:25:00)
  - Başla/Bitir (Start/Stop): kenarları yuvarlatılmış dörtgen ya da elips. Her algoritmanın tek bir başlangıcı ve mutlaka bir sonu olur.
  - Girdi (okuma): sol üst köşesi çentikli dikdörtgen; delikli kartı (punch card) temsil eder. Değişkenler virgülle ayrılır; dizi okumak için `A(N)` gösterimi kullanılabilir, ama `A(N)`'den önce `N` okunmalıdır (ekrandan, 01:35:00). Paralelkenar da bazı kaynaklarda girdi için kullanılır; bu derste kullanılmaz.
  - Çıktı: alt kenarı dalgalı dikdörtgen; yazıcı kağıdını temsil eder. Ekran çıktısı için kullanılan katot ışınlı tüp biçimli sembol bu derste kullanılmaz.
  - Bağlantılar: yönlü, köşeli çizilen oklar; karmaşık diyagramlarda numaralı çemberler (bağlayıcılar).
  - İşlem: dikdörtgen; bir kutuda birden çok işlem olabilir. Dile özgü sözdizimi kullanılmaz (`A = A + 1` doğru, `A++` yanlış).
  - Karar (if): altıgen; içindeki ifade doğru/yanlış üretir. T ve F kolları mutlaka işaretlenir, tüm kararlarda aynı tarafta tutulmaya çalışılır. Doğru kolu zorunlu, yanlış kolu isteğe bağlıdır (ekrandan, 01:40:00).
  - For döngüsü: üç bölmeli dikdörtgen (başlangıç, son koşul, adım); adım negatif olabilir (ekrandan, 01:45:00).
  - While döngüsü: altıgen içinde koşul; bilinmeyen sayıda iterasyon (ekrandan, 01:50:00).
- Sözde kod ve yapısal programlama (ekrandan, 01:55:00)
  - Her algoritma üç yapıyla ifade edilebilir: dizilim (sequence), seçim (selection), döngü (loop).
  - Sözde kodda başlık (algoritma adı, amaç, ön/son koşul, dönüş değeri) ve numaralandırılmış, girintili gövde bulunur.
- Akış diyagramı örnekleri (Zoom beyaz tahtası)
  - $n$ sayının toplamı ve ortalaması; $f = \sum_{x=1}^{n} 1/x^2$; Öklid algoritmasıyla OBEB.

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritmik düşünme yalnız okuyarak öğrenilmez
  - En önemlisi çok alıştırma yapmak, problemlere farklı yaklaşımlarla algoritmik çözüm üretmeye çalışmaktır.
- Sonluluk
  - Algoritma mutlaka bir yerde durmalıdır; while döngüsünde koşulu değiştiren bir işlem yoksa sonsuz döngü oluşur.
- Değer atamadan değişken kullanılmaz
  - Bir değişken önce okunmalı ya da ilk değeri atanmalıdır; bilinen değerlerden hesaplanarak atanıyorsa ayrıca sıfırlamaya gerek yoktur.
- Dile bağımlı ifade yasak
  - Akış diyagramında `x++` gibi bir dile özgü operatör kullanılmaz; `x = x + 1` yazılır.
- T/F kolları
  - Her kararda T ve F işaretlenmeli; yalnız yanlış kolunda işlem olan karar çizilmez, koşul tersine çevrilir (örneğin `x < 0` yerine `x >= 0`).
- Test etmek ve uç değerler
  - Ortalama örneğinde $n = 0$ girilince sıfıra bölme hatası çıkar; uç değerler mutlaka denenmelidir.
- Sembol seçimi
  - Bu derste girdi için delikli kart, çıktı için kağıt sembolü, karar için altıgen kullanılır; eşkenar dörtgen ve paralelkenar başka kaynaklarda görülebilir.

## Kısa Tekrar Notları

- Tanımlayıcı bilgi: "ne olduğu"; buyurucu bilgi: "nasıl yapılacağı". Algoritma, tanımlayıcı bilginin buyurucu bilgiye dönüştürülmesidir.
- Algoritma: problem için, sonlu sayıda, kesin adımdan oluşan, doğru girdilerde doğru çıktıyı sonlu zamanda üreten akış.
- Özellikler: anlaşılırlık, 0+ girdi, 1+ çıktı, sonlanma, yapılabilirlik, dilden bağımsızlık.
- "Algoritma" kelimesi el-Hârizmî'nin adının Latince çevirisinden ("Algoritmi") gelir.
- Newton karekök: $r \leftarrow (r + x/r)/2$, $|r^2 - x| \le e$ olunca dur.
- Polya: anla, planla, uygula (test et), değerlendir (analiz et).
- Sıralı en büyük arama: $n$ ile doğru orantılı; paralel eleme turu: $\log_2 n$ tur.
- Akış diyagramı: başla/bitir (yuvarlak), girdi (çentikli kart), çıktı (dalgalı kağıt), işlem (dikdörtgen), karar (altıgen, T/F), for (üç bölmeli dikdörtgen), while (altıgen + geri dönüş oku), bağlayıcı (numaralı çember).
- Döngü değişkenleri genellikle $i, j, k, l$; eleman sayıları için $m, n$.
- For döngüsünden çıkıldığında döngü değişkeni son değerinin bir adım ötesindedir ($j = 1..5$ adım 1 ise çıkışta $j = 6$).
- OBEB (Öklid): kalan sıfır olana kadar $x \leftarrow y$, $y \leftarrow k$, $k \leftarrow x \bmod y$; sonuç $y$.

## Detaylı Açıklamalar

- Bilgi türleri ve algoritma
  - İnsan, tahtayı silmek ya da yumurta pişirmek gibi işleri adım adım anlatmaya ihtiyaç duymadan bilir. Bilgisayar ise yalnız toplama, çıkarma, belleğe yazma/okuma ve büyüktür/küçüktür gibi lojik karşılaştırmaları bilir. Bu yüzden "y çarpı y eşittir x" gibi bir tanımı bilgisayara olduğu gibi veremeyiz; sonucu üreten adımları tanımlamamız gerekir. Hocanın sınıfta yaptığı yumurta pişirme denemesinde verilen tarif bir "birinci adım" içinde dört-beş ayrı iş barındırıyordu ve yumurtanın nasıl kırılacağı, ne zaman durulacağı gibi noktalar eksikti. İyi bir buyurucu tanım, durma noktası dahil her şeyi kesin olarak söyler.
- Newton'ın karekök algoritmasının işletilmesi (ekrandan, 00:35:00)
  - $x = 16$, $e = 0.001$, başlangıç $r = 3$ alınır.

    | $r$ | $r \cdot r$ | $x/r$ | $(r + x/r)/2$ |
    |---|---|---|---|
    | 3 | 9 | 16/3 | 4.17 |
    | 4.17 | 17.36 | 3.837 | 4.0035 |
    | 4.0035 | 16.0277 | 3.997 | 4.000002 |

  - Her satırda $|r^2 - 16|$ eşikten büyük olduğu için $r$ güncellenir; son değerde fark eşiğin altına düşer, döngüden çıkılır ve yaklaşık 4.000002 yazdırılır. Eşik küçültülürse döngü daha çok çalışır ve sonuç 4'e daha çok yaklaşır; ama bilgisayardaki sayıların hassasiyeti sınırlıdır (8, 16, 32 bit ve taşma konusu).
  - Ders sonrası not: Slayttaki ara değerler yuvarlanmıştır. Python ile hesaplandığında ikinci güncelleme yaklaşık 4.00333, üçüncü güncelleme yaklaşık 4.0000014 çıkar; sonuç değişmez.
  - Ders sonrası not: Slayttaki koşul $(r \cdot r - x) > e$ biçimindedir. Mutlak değer olmadan $r = 3$ için $9 - 16 = -7$ eşikten küçük olduğundan döngüye hiç girilmezdi; hocanın sözlü belirttiği gibi koşul $|r \cdot r - x| > e$ olmalıdır.
- En yaşlı öğrenci problemi ve analiz
  - Çözüm 1'de her öğrenciye sırayla sorulur ve en yaşlının kaydı tahtada tutulur; 7 öğrenci için 7 sorgu gerekir. Çözüm 2'de öğrenciler ikişer eşleşir, her çiftte genç olan elenir, tek kalan öğrenci karşılaştırmasız bir sonraki tura geçer. 7 öğrenci için turlar 4, 2 ve 1 karşılaştırmadan oluşur; toplam yine 7 karşılaştırmadır. Fark, bir turdaki karşılaştırmaların aynı anda (paralel) yapılabilmesidir: yeterli işlem kapasitesi varsa süre 3 sorgu zamanıdır. Tek işlemcili bir ortamda bu avantaj ortadan kalkar; o zaman daha basit olan Çözüm 1 tercih edilir.
  - Ders sonrası not: Slayttaki şekilde 8 öğrenci vardır ve 4 + 2 + 1 = 7 karşılaştırma bu şekle uyar. Tam 7 öğrenci olsaydı turlar 3 + 2 + 1 = 6 karşılaştırma olurdu (sıralı çözümde de ilk öğrenci karşılaştırmasız yazıldığından $n - 1$ karşılaştırma yeterlidir); tur sayısı her iki durumda 3'tür.
  - Karşılaştırma başına 5 saniye varsayımıyla Çözüm 1'in süresi $5n$ ile doğrusal artar. Çözüm 2'nin süresi $5\log_2 n$'dir: 100 öğrenci için yaklaşık 33 saniye (hoca yuvarlayarak 35 dedi), 200 ve 400 öğrenci için her seferinde yaklaşık 5 saniye daha, 1 milyon öğrenci için yaklaşık 100 saniye. Girdi büyüdükçe logaritmik çözüm çok daha avantajlı hale gelir.
- Akış diyagramı sembollerinin tarihçesi
  - Girdi sembolündeki sol üst çentik, eski bilgisayarlarda veri girmek için kullanılan delikli kartların okuyucuya ters takılmasını önleyen çentiğinden gelir (SIM kart mantığı). Çıktı sembolünün dalgalı alt kenarı, monitörsüz ana bilgisayar döneminde çıktıların yazıcıdan kağıda basılmasını temsil eder. Bazı kaynaklarda görülen ekran çıktısı sembolü, tüplü (katot ışınlı) monitörün yandan görünüşüne benzer.
  - Karar için eşkenar dörtgen kullanılmasının nedeni, FORTRAN'daki aritmetik if yapısının üç çıkışlı olmasıdır: fark pozitifse bir yöne, negatifse başka yöne, sıfırsa (eşitlik) üçüncü yöne gidilirdi. Günümüzde koşul yalnız doğru ya da yanlış olduğundan bu derste altıgen kullanılır.
- Döngüler
  - For döngüsünde ilk değer ($j \leftarrow 1$), son koşul ($N$) ve adım (1) üç bölmede yazılır. $N = 5$ ve adım 1 için $j$ sırasıyla 1, 2, 3, 4, 5 değerlerini alır, blok 5 kez çalışır, çıkışta $j = 6$ olur. Adım 2 ise $j$ = 1, 3, 5 olur ve çıkışta $j = 7$'dir. $j = N$'den 1'e adım $-1$ ile 5, 4, 3, 2, 1 değerleri alınır.
  - While döngüsünde koşul her turda yeniden kontrol edilir. $j = 1$, $n = 3$, koşul $j < n$ ve gövde yalnız `A = A + 1` ise $j$ hiç değişmediği için döngü sonsuza kadar döner. Gövdeye `j = j + 1` eklenince $j$ = 1, 2 için çalışır ve $j = 3$ olunca çıkılır.
  - Döngüler iç içe kullanılabilir (örneğin bir for döngüsünün içinde while). İç içe üç döngüden fazlası genellikle algoritmayı gereksiz karmaşıklaştırır.
- Sözde kod
  - Örnek sözde kod (ekrandan, 01:55:00): `Algorithm sample (pageNumber)` başlığı, amaç ("This algorithm reads a file and prints a report."), Pre/Post koşulları ve `Return` satırından sonra numaralı gövde gelir: dosya sonu gelene kadar döngü (`loop (not end of file)`), içinde dosyayı oku, sayfa doluysa (`if (full page)`) sayfa numarasını artır ve sayfa başlığını yaz, rapor satırını yaz, satır sayacını artır; döngü bitince satır sayısını döndür.
  - Atama `←` ya da `=` ile, eşitlik kontrolü tek `=` ile gösterilir; seçim `if ... else ... end if`, döngüler `while`, `do ... while`, `repeat ... until` ve `for` ile yazılır.
  - Ders sonrası not: Hoca üç yapı (dizilim, seçim, döngü) sonucunu yapısal programlamayı öneren Dijkstra'ya bağladı; bu sonucun ispatı genellikle Böhm ve Jacopini'ye (1966) atfedilir, Dijkstra ise yapısal programlamanın savunucusu olarak bilinir.
- Örnek 1: $n$ sayının toplamı ve ortalaması (ekrandan, 02:10:00)
  - Akış: Start → `N` oku → `top = 0`, `ort = 0` → for `i = 1`'den `N`'e adım 1: `S` oku, `top = top + S` → `ort = top / N` → `top, ort` yazdır → Stop.
  - Test ($N = 3$, girdiler 2, 3, 4): `top` sırasıyla 2, 5, 9; döngüden `i = 4` ile çıkılır; `ort = 9/3 = 3`; çıktı 9 ve 3.
  - $N = 0$ testinde döngüye girilmez, `ort = 0/0` sıfıra bölme hatası verir. Düzeltme: `N` okunduktan sonra `N > 0` kararı eklenir; doğru kolunda hesaplama yapılır, yanlış kolunda "hata" yazdırılır, iki kol birleşip devam eder.
- Örnek 2: $f = \sum_{x=1}^{n} \frac{1}{x^2}$ (ekrandan, 02:20:00)
  - Akış: Start → `N` oku → `x = 1`, `f = 0` → while `x <= N`: `f = f + 1/(x*x)`, `x = x + 1` → `f` yazdır → Stop.
  - $N = 0$ için döngüye girilmez, çıktı 0 olur. Teorik çözümde taşma (overflow) dikkate alınmaz.
  - Alternatif: while döngüsü yerine `x = 1`'den `N`'e for döngüsü kullanılır; o zaman `x = x + 1` gerekmez. İki çözümün karmaşıklığı aynıdır.
- Örnek 3: OBEB, Öklid algoritması (ekrandan, 02:35:00)
  - Akış: Start → `x, y` oku → `k = x mod y` → while `k ≠ 0`: `x = y`, `y = k`, `k = x mod y` → `y` yazdır → Stop. `mod` yerine `%` da yazılabilir, ama `mod` daha açıktır.
  - Test ($x = 36$, $y = 24$): $k = 12$; $k \ne 0$ olduğu için $x = 24$, $y = 12$, $k = 24 \bmod 12 = 0$; döngüden çıkılır ve $y = 12$ yazdırılır.
  - Kalan her adımda küçüldüğü için sıfıra ulaşmak ve algoritmanın sonlanması garantidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
