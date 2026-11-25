# Ders 1 Genişletilmiş Notu: Bilgisayar Donanımına Giriş, Boole Cebri, Minterm ve Maxterm, Karnaugh Haritası, Sayı Gösterimleri ve Multiplexer

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kapsamı
- 2. Komut Kümesi Mimarisi, Tek Çevrimli İşlemci ve Boru Hattı
- 3. Ön Bellek ve Sanal Bellek
- 4. Temel Lojik Kapılar
- 5. Tam (Complete) Kapı Kümeleri
- 6. Lojik Fonksiyonların İfade Biçimleri ve Fonksiyon Sayısı
- 7. Çoğunluk (Majority) Fonksiyonu
- 8. Boole Cebri Eşitlikleri
- 9. Minterm ve Maxterm ile Fonksiyon Yazma
- 10. Karnaugh Haritası ile İndirgeme
- 11. İşaretsiz ve İşaretli Sayı Gösterimleri
- 12. Multiplexer (MUX)
- Örnek Sorular

## 1. Dersin Amacı ve Kapsamı

Ders, devre teorisi, elektronik devreler ve lojik devreler derslerinin üzerine kurulan donanım dersidir. Bu yüzden Lojik Devreler dersindeki bilgilerin önemli bir kısmı hatırlanmalıdır. Temel amaç bir CPU'nun işleyişine ayrıntılı bakmaktır: işlemcinin içinde hangi birimler vardır, bu birimler nasıl çalışır, temel düzeyde nasıl tasarlanabilir. Ayrıca işlemcinin çevre birimleriyle nasıl haberleştiği ve bunun hangi arayüzlerle sağlandığı ele alınır. Dönem sonunda bir mikroişlemcinin iç yapısı, birimleri, bunların tasarım gereksinimleri ve tasarım kararlarının neye bağlı olduğu, donanım modüllerinin performansa nasıl katkı verdiği anlaşılmış olmalıdır.

Ekranda gösterilen haftalık plandaki konular şunlardır (ekrandan, 00:05:00):

- Bilgisayar donanımına giriş
- Kombinasyonel ve ardışıl lojik devreler
- Saklayıcı ve sayıcılar, programlanabilir yapılar (PLD, PLA, PAL)
- Bellek birimleri (RAM, ROM)
- Saklayıcı transfer işlemleri ve ortak veri yolu oluşturma
- Komut yapısı ve adresleme yöntemleri
- Merkezi işlem birimi tasarımı
- Merkezi işlem birimi tasarımı ve pipeline ile veri işleme
- Giriş/çıkış birimleri ve haberleşme
- Ön bellek yapısı ve eşleme (map) teknikleri
- Sanal bellek yapısı ve sayfa tabloları

Hoca planı şöyle açıkladı. Önce temel kapılardan başlayarak bir bitlik lojik bloklar hatırlanacak, sonra bunların modüler n bitlik versiyonları verilecek. Bilgisayar donanımında karşılaşılacak yazmaç (register) yapısı flip-flop'lara dayanır; bu temel hafıza elemanlarıyla ardışıl devre tasarımı ele alınacak. Lojikteki mantık bir adım ileri götürülerek donanım modüllerinin fonksiyon yapıları, fonksiyon tabloları ve daha büyük lojik tasarımlar incelenecek. Saklayıcı ve sayıcılar CPU içinde görev yapan bloklar olarak yeniden ele alınacak. Bellek birimlerinde iç yapı, tasarım özellikleri, veri yolu genişletme, adres yolu genişletme ve kapasite genişletme işlenecek.

Yazmaçların çalışma mantığı görüldükten sonra yazmaçlar arası transfer dili (register transfer language) üzerinden işlemler kurulacak: yazmaçtan yazmaca aktarma, iki yazmaçtaki değeri toplayıp sonucu bir yazmaca yazma, bir yazmaçtaki değeri döndürme ya da öteleme ve sonucu tekrar yazmaçta saklama. Bunlar, yalnız belirli bir işi yapacak şekilde sabit kodlanmış (hard-coded) yazmaç blokları üzerinde veri transferidir.

## 2. Komut Kümesi Mimarisi, Tek Çevrimli İşlemci ve Boru Hattı

### 2.1 Komut yapısı ve adresleme

Komut yapısı, bir işlemcinin desteklediği komut setinin hangi tür komutları içerdiğidir. Örneğin tamsayı toplama ve çıkarma destekleniyorsa bir toplayıcı-çıkarıcı devre yeterlidir. Tamsayı çarpma da destekleniyorsa arka planda uygun denetim işaretleri ve bir çarpma devresi bulunmalıdır. Buradan komut kümesi mimarisi (Instruction Set Architecture, ISA) ile donanımın birbirine ne kadar sıkı bağlı olduğu görülür.

Adresleme yöntemleri de bellek erişimi üzerinden doğrudan komut kümesine bağlıdır. Bellekte belirlenen bir referansa doğrudan erişmek bir komut grubu gerektirir. Bir referans adresi sabit tutup ondan belirli bir uzaklıktaki adreslere erişmek ise bellek arayüzünün denetim yapısını değiştirir ve bunu destekleyecek ayrı bir komut yapısı gerekir. Kısacası komut yapısı, bellek erişimi ve arka plandaki denetim ve donanım modülleri birbiriyle yakından ilişkilidir. Bir tasarımda komut sayısını belirleyen etkenlerden biri, denetim biriminin karmaşıklığına ne kadar izin verildiğidir.

Buraya kadarki konular mikroişlemcinin çekirdeği dışındaki yardımcı yapılardır.

### 2.2 Tek çevrimli işlemci

Merkezi işlem birimi kısmında basit komutları gerçekleyebilen bir işlemcinin tasarım senaryosu incelenecektir. Senaryo tek çevrimli (single cycle) bir işlemcidir: yürütülmek istenen her komut bir saat çevriminde tamamlanır. Bu güzel bir avantajdır, ama bedeli yürütülebilecek komut kümesinin dar olmasıdır. Örneğin çarpma, toplama ve kaydırma işlemlerinden oluşan bir süreçtir ve aynı denetim mantığı içinde bir çevrimde bitmesi mümkün değildir. Bu nedenle çok karmaşık komutları olmayan ama temel işlemleri yapabilen bir işlemci "hardwired" mimariyle tasarlanacak, farklı komut grupları için tasarım yeniden planlanacaktır.

### 2.3 Boru hattı (pipeline)

Boru hattının Türkçesi boru hattıdır. Fikri anlamak için hoca şu resmi kurdu: yazılan komutlar ROM tipi kalıcı bir bellekte sıralı durur. Bir işaretçi, sırada hangi komutun yürütüleceğini belirler. Basitlik için her komutun 1 bayt yer kapladığı düşünülebilir. Algoritmalar her zaman ardışık akmaz; dallanmalar ve fonksiyon çağrıları içerir. Akış ardışıksa işaretçi her adımda bir sonraki komutu gösterir; koşullu dallanma varsa gidilecek noktaya göre değeri birden büyük miktarda değişir.

Bir komutun yürütülmesi en az şu adımlardan oluşur:

- Komutu bellekten işlemciye getirme
- Komutu çözümleme (ne yapmak istediği anlaşılır, buna göre denetim işaretleri üretilir)
- İşlenenleri (operand) bellekten getirme
- Komutu yürütme (örneğin bellekten alınan veriyi 2 ile toplama)
- Sonucu belleğe geri yazma

Tasarıma göre bu süreç 4, 5 ya da 6 alt adımlı olabilir. Seri mimaride bir komut, ardışık bağlı bu beş bloğun ilkine girer, çıktısı ikinciye, oradan üçüncüye gider ve komut işlemciden çıkar. Bu sırada diğer bloklar boşta bekler. Avantajı tasarım karmaşıklığının düşüklüğü, dezavantajı blokların boş kalmasıdır.

Boru hattında, dallanma içermeyen sıralı komutlar için birinci komutun sonucu geri yazılırken ikinci komut yürütülür, üçüncünün işlenenleri alınır, dördüncü çözümlenir, beşinci bellekten getirilir. Bütün bloklar aynı anda farklı komutlarla aktiftir ve bu da verimi (throughput) artırır.

Dezavantajları da vardır. İlk komut koşullu dallanmaysa, sonucu belli olmadan işlenmeye başlanan ikinci, üçüncü, dördüncü ve beşinci komutlar başka bir yere dallanıldığında çöp olur. Ya da birinci komut bir yazmacın değerini değiştirecekken ikinci komut o yazmacın yeni değerini bekliyorsa, birincinin sonucu çıkmadan ikincinin yürütülmesinin anlamı yoktur. Bu iki durumu uygun biçimde ele alıp performansı artıran tasarımlar incelenecektir.

> **Ek bilgi (derste anlatılmadı):** Bu iki durum literatürde büyük olasılıkla denetim tehlikesi (control hazard) ve veri tehlikesi (data hazard) adlarıyla geçer; ileriki derslerde bu adlarla karşılaşılabilir.

## 3. Ön Bellek ve Sanal Bellek

### 3.1 Ön bellek (cache)

Mikroişlemci sıradaki komutu ana bellekten (main memory) çeker. Ana bellek, maliyet ve kapasite birlikte düşünülerek tasarlandığı için erişim süresi görece yüksektir. Bunu iyileştirmenin yolu ön bellektir.

Ön belleğin avantajı programların iki eğiliminden gelir:

- Bir dizi ya da matris tanımlanıp bir elemanına erişildiyse, sonraki döngüde o elemanın hemen komşusuna erişilme olasılığı çok yüksektir.
- Örneğin birden ona kadar sayıları toplayan bir döngüde biriktirici olarak kullanılan değişkene, yani aynı bellek bölgesine, farklı zamanlarda tekrar tekrar erişilir.

Bu yüzden ana bellek ile işlemci arasına daha küçük, hızlı ve maliyet açısından makul bir bellek bloğu konur. Bir bellek bölgesiyle işlem yapılacağında yalnız o nokta değil, belirli bir civarındaki içerik de bu küçük belleğe kopyalanır. İşlemci önce ön belleğe bakar; aranan adres oradaysa oradan alır, yoksa ana belleğe gidip ilgili bölgeyi ön belleğe kopyalar. Ortalamada erişim hızı kat mertebesinde artar.
<!-- BELİRSİZ: 00:21:17 civarında altyazıda ön bellek için "erişim süresini burada yüksek tutup" deniyor; bağlam ön belleğin hızlı (erişim süresi düşük) olduğu yönünde. Whisper ya da sözlü kayma olabilir. -->

Ana bellek büyük, ön bellek küçük kapasitelidir ve işlemci ana bellekteki her adrese erişebilir. Büyük kapasitedeki hangi adresin küçük bellekte hangi adrese eşleneceği bir tasarım sorusudur. Doğrudan eşleme, serbest eşleme ve kümeli eşleme gibi farklı tasarımlar vardır; ön belleğin performansı bunlara bağlı olarak değişir.

> **Hocanın vurgusu:** Performansa dayalı programlama yaparken çalışılan mimarinin ön bellek özelliklerini dikkate almak çok önemlidir. Hoca, kümeli ön bellek kullanan bir mimaride iki matrisin çarpımında matrislerdeki taramalar uygun sırada yapılmazsa işlem süresinin iki üç kat farklı çıktığını, ön bellek yapısı dikkate alınarak program tasarlanırsa bu örnekte 6 kata kadar hızlanma elde edilebildiğini söyledi.

### 3.2 Sanal bellek

Çalıştırılan programların önce ana belleğe yüklenmesi gerekir. Ana belleğe sığmayacak kadar büyük programlar ikincil bellek birimlerinde (sabit disk vb.) saklanır, çalıştırılacak kısmı parça parça ana belleğe taşınır. Ana bellek, ön bellek ve işlemci arasındaki akışa benzer biçimde ikincil bellek ile ana bellek arasında da bir bellek yönetimi vardır. Aynı problem burada da ortaya çıkar: ikincil bellekteki hangi blok ana bellekteki hangi adrese yerleşecek?

## 4. Temel Lojik Kapılar

Günümüz dijital bilgisayar mimarileri Boole cebrinin elektronik mantıkta uygulanmasıdır. Uygulamada lojik 0 ve lojik 1, kapıların giriş ve çıkışlarında belirli gerilim aralıklarıyla tanımlanır. Daha soyut düzeyde Boole cebri üç temel fonksiyonla karşılanır: AND, OR ve NOT. Bu üç işlemle herhangi bir lojik fonksiyon gerçeklenebilir.

Tahtadaki gösterimde $B = \{0, 1\}$ olmak üzere AND ve OR iki girişli olduğu için $B^2 \rightarrow B$, NOT ise tek girişli olduğu için $B \rightarrow B$ fonksiyonudur (ekrandan, 00:45:00):

| $x$ | $y$ | AND | OR |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 |

| $x$ | NOT |
|---|---|
| 0 | 1 |
| 1 | 0 |

AND yalnız iki giriş de 1 iken 1, OR yalnız iki giriş de 0 iken 0 verir. Bu kapıların arka planında CMOS transistörlerle kurulmuş bir devre vardır; ama iç yapı kara kutu gibi düşünüldüğünde kapı, tablodaki gibi çalışır.

Hoca tarihsel bir not da ekledi: Boole cebri elektromekanik düzeneklerle ve basınç deneylerinde kullanılan U tüplere benzer tüplü düzeneklerle de gerçeklenmiştir. Sovyet Rusya döneminde ise ikili değil üçlü bir mantık tanımlanmış ve elektronik olarak gerçeklenmiştir; −1, 0 ve 1 değerlerinden birini alabilen her basamağa bit yerine "trit" denir.
<!-- BELİRSİZ: 00:45:02-00:45:32 arası altyazı bozuk; tüplü düzeneğin ayrıntısı ve üçlü bilgisayarın adı net anlaşılmıyor. -->

Uygulamada karşılaşılan kapılar yalnız bu üçü değildir. Slayttaki maddeler (ekrandan, 00:45:00):

- NAND = AND + NOT; girişlerden en az biri 0 ise 1 verir. Gösterim $(x\cdot y)'$.
- NOR = OR + NOT; girişlerden en az biri 1 ise 0 verir. Gösterim $(x + y)'$.
- XOR, dışlayıcı-VEYA (exclusive-OR) fonksiyonunu gerçekler: $x'y + xy'$.
- NAND ve NOR, standart CMOS'ta AND ve OR'dan daha az transistör gerektirir.
- İşlevsellik doğruluk tablosuyla ifade edilebilir; doğruluk tablosu her olası giriş kombinasyonu için çıkışı listeler.

Hoca XOR'u örnek gösterdi: $x'y + xy'$ ifadesinde iki NOT, iki çarpma ve bir toplama vardır; ama üretim teknolojisi sayesinde bu beş işlem tek bir kara kutu kapı olarak elde edilir.

Doğruluk tablosunun kullanımı için hoca bir alarm sistemi örneği verdi: bir sensör kapının açık olup olmadığını, bir PIR sensörü içeride birinin olup olmadığını algılar. Belirli koşullar sağlandığında alarm fonksiyonu 1, diğer durumlarda 0 verir. Böyle bir senaryo doğruluk tablosuyla ya da AND, OR, NOT'a bağlı bir lojik fonksiyon olarak yazılabilir.

## 5. Tam (Complete) Kapı Kümeleri

Bütün lojik fonksiyonların gerçeklenebildiği kapı alt kümelerine tam küme (complete set) denir. Slayttaki tanım ve örnekler (ekrandan, 00:50:00):

- Bir kapı kümesi, yalnız kümedeki kapı türleri kullanılarak herhangi bir lojik fonksiyon gerçeklenebiliyorsa tamdır.
- Örnek tam kümeler: {AND, OR, NOT} (minimal tam küme değildir), {AND, NOT}, {OR, NOT}, {NAND}, {NOR}.
- Minimal tam küme: gereksiz elemanı olmayan tam küme.

{AND, OR, NOT} minimal değildir, çünkü OR çıkarılsa bile AND ve NOT ile OR fonksiyonu kurulabilir; kalan {AND, NOT} yine tamdır. Bu kümeden NOT da çıkarılırsa yalnız AND ile bütün fonksiyonlar gerçeklenemez. Benzer biçimde {AND, OR, NOT}'tan AND çıkarılırsa {OR, NOT} ile AND kurulabilir. Yalnız NAND ile AND, OR ve NOT kurulabildiği için {NAND} de tamdır. Bir kümeden herhangi bir eleman çıkarıldığında artık bütün fonksiyonlar gerçeklenemiyorsa o küme minimal tam kümedir.

### 5.1 AND ve NOT ile OR

**Soru:** AND ve NOT kullanarak OR kapısı yapılabilir mi, nasıl? **Cevap:** Bir öğrenci $x$ ve $y$'nin tümleyenlerinin kullanılacağını hatırladı; sohbetten de doğru cevap geldi. $x'$ ve $y'$ AND'lenir ve sonuca NOT uygulanır: $(x'\cdot y')'$. De Morgan kuralına göre dıştaki NOT içeri dağıtılırken her terim terslenir ve çarpma işlemi ikizi olan toplamaya dönüşür: $(x'\cdot y')' = x'' + y'' = x + y$. Bir şeyin değilinin değili kendisidir.

### 5.2 Yalnız NAND ile NOT, OR ve AND

NAND kapısının çıkışı $(x\cdot y)'$'dir. Bu kapıdan NOT, OR ve AND elde edildiği gösterilmelidir.

- NOT: NAND'in iki girişine de aynı $x$ bağlanırsa çıkış $(x\cdot x)' = x'$ olur.
- OR: $x$ bir NAND-NOT'a, $y$ başka bir NAND-NOT'a girer; çıkan $x'$ ve $y'$ üçüncü bir NAND'e verilir: $(x'\cdot y')' = x + y$.
- AND: $x$ ve $y$ bir NAND'e girer, çıkış $(xy)'$ olur. Bu, girişleri birleştirilmiş ikinci bir NAND'den geçirilince $\big((xy)'\big)' = xy$ elde edilir.

Aynı yaklaşım NOR kapısı için de geçerlidir.

## 6. Lojik Fonksiyonların İfade Biçimleri ve Fonksiyon Sayısı

Lojik fonksiyonlar birkaç biçimde ifade edilebilir (ekrandan, 01:00:00):

- Doğruluk tablosu
- Lojik ifade
- Grafik (şematik) biçim
- HDL kodu

### 6.1 Tek girişli fonksiyonlar

**Soru:** $f: B \rightarrow B$, yani bir girişli bir çıkışlı kaç farklı fonksiyon yazılabilir? **Cevap:** Önce 2 dendi, hoca 4 olduğunu gösterdi. Giriş 0 ya da 1 olabilir:

| $x$ | $f_0$ | $f_1$ | $f_2$ | $f_3$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 |

- $f_0 = 0$: giriş ne olursa olsun çıkış 0; $x$'e bağlı değildir.
- $f_1 = x$: ne girerse aynısı çıkar.
- $f_2 = x'$: ne girerse tersi çıkar.
- $f_3 = 1$: giriş ne olursa olsun çıkış 1.

### 6.2 İki girişli fonksiyonlar ve genel formül

**Soru:** $g: B^2 \rightarrow B$, yani $g(x, y)$ biçiminde kaç fonksiyon yazılabilir? **Cevap:** Bir öğrenci 16 dedi. Önce doğruluk tablosunun satır sayısı bulunur: her giriş iki değer alır, $2 \cdot 2 = 4$ satır. Her satırda $g$ iki değer alabilir; bu yüzden $2^4 = 16$ farklı fonksiyon vardır. Bunlar $g = 0$'dan $g = 1$'e kadar uzanır; bazıları yalnız $x$'e, bazıları yalnız $y$'ye, bazıları $x'$ ya da $y'$'ye bağlıdır, bazıları $x + y$, bazıları $x \cdot y$ gibidir.

Genel formül: $m$ girişli bir fonksiyonun doğruluk tablosu $2^m$ satırdır ve her satır iki değer alabildiğinden yazılabilecek farklı fonksiyon sayısı $2^{2^m}$'dir. Değerler ayrık (discrete) olduğu için $m$ değişkenli olası bütün lojik fonksiyonlar baştan bellidir ve baştan hesaplanabilir.

## 7. Çoğunluk (Majority) Fonksiyonu

Slayttaki örnek (ekrandan, 01:05:00): çoğunluk fonksiyonunun çıkışı, girişlerin çoğunluğu 1 olduğunda 1'dir; üç girişli versiyon kullanılır. Doğruluk tablosu (ekrandan, 01:10:00):

| $A$ | $B$ | $C$ | $F$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

Tablo yazılırken ilk sütun dörtlük, ikinci sütun ikilik periyotla, üçüncü sütun her satırda değişir.

### 7.1 Akıl yürütmeyle lojik ifade

Üç değişkenden herhangi ikisi seçildiğinde ikisi de 1 ise diğerine bakmaya gerek yoktur; çıkış 1'dir. Olası ikililer $AB$, $BC$ ve $AC$'dir. Her ikili için "ikisi de 1 iken 1, diğer durumlarda 0" veren fonksiyon gerekir.

**Soru:** Bu fonksiyon hangi kapıdır? **Cevap:** AND kapısı (sohbetten cevaplandı).

Herhangi bir ikiliden gelen 1, çıkışın 1 olması için yeterlidir. $AB$'den 0, $BC$'den 0 gelse bile $AC$'den 1 gelebilir. Herhangi biri 1 iken 1, hepsi 0 iken 0 veren kapı OR'dur. Bu yüzden ikililerin kararları OR ile birleştirilir:

$$F = AB + BC + AC$$

Şematik biçimde (ekrandan, 01:10:00) $A$ ve $B$ bir AND'e, $B$ ve $C$ ikinci bir AND'e, $A$ ve $C$ üçüncü bir AND'e girer; üç çıkış üç girişli bir OR'da toplanır.

Böylece sözel bir problem tanımlanmış, doğruluk tablosuyla gösterilmiş, belirli bir mantıkla lojik ifadeye dönüştürülmüş, ifade grafik olarak çizilmiş olur. Çizim ayrı devre elemanlarıyla kurulduğunda fiziksel olarak çalışan bir devre elde edilir.

### 7.2 Yalnız NAND ile çoğunluk fonksiyonu (şema üzerinden)

Bir hattın üzerine art arda iki NOT (yuvarlak) koymak bir şey değiştirmez, çünkü $x'' = x$. Her AND çıkışı ile OR girişi arasına iki NOT konur; biri AND'in çıkışına, diğeri OR'un girişine yaklaştırılır. Böylece AND'ler NAND'e dönüşür. Girişleri terslenmiş OR, yani $A' + B' + C'$, De Morgan ile tersten açılırsa: değilinin değili alınıp bir değil içeri dağıtılınca $(A\cdot B\cdot C)'$ elde edilir; bu da üç girişli bir NAND'dir. Sonuçta yapı üç adet iki girişli NAND ve bir adet üç girişli NAND'den oluşur.

### 7.3 Yalnız NAND ile çoğunluk fonksiyonu (ifade üzerinden)

Aynı sonuç lojik ifadeyle de bulunur: fonksiyonun iki kez değili alınır, değillerden biri De Morgan ile içeri dağıtılır:

$$F = (AB + BC + AC)'' = \big((AB)'\cdot(BC)'\cdot(AC)'\big)'$$

$X = (AB)'$, $Y = (BC)'$, $Z = (AC)'$ denirse $F = (XYZ)'$ olur; yani üç girişli bir NAND.

## 8. Boole Cebri Eşitlikleri

Slayttaki tablo (ekrandan, 01:15:00):

| Ad | AND versiyonu | OR versiyonu |
|---|---|---|
| Etkisiz eleman (identity) | $x\cdot 1 = x$ | $x + 0 = x$ |
| Tümleyen (complement) | $x\cdot x' = 0$ | $x + x' = 1$ |
| Değişme (commutative) | $x\cdot y = y\cdot x$ | $x + y = y + x$ |
| Dağılma (distribution) | $x\cdot(y+z) = xy + xz$ | $x + (y\cdot z) = (x+y)(x+z)$ |
| Değişmezlik (idempotent) | $x\cdot x = x$ | $x + x = x$ |
| Yutan eleman (null) | $x\cdot 0 = 0$ | $x + 1 = 1$ |

Hocanın açıklamaları:

- AND'in etkisiz elemanı lojik 1, OR'unki lojik 0'dır.
- AND'in yutan elemanı 0, OR'unki 1'dir. Tümleyen bu yutan elemana göre tanımlanır: $x$ ile AND'lendiğinde 0 veren değer $x'$'tür; $x$ ile OR'landığında 1 veren değer yine $x'$'tür.
- Değişme özelliğinde işlem sırası önemli değildir.
- Dağılma, sıradan cebirden farklıdır: sıradan cebirde çarpma toplama üzerine dağılır ama toplama çarpma üzerine dağılmaz. Boole cebrinde ise AND, OR üzerine, OR da AND üzerine dağılır.
- Bir değişkenin değilinin değili kendisidir: $(x')' = x$.
- $x\cdot(x + y) = x$: buradaki $y$'nin sonuca etkisi yoktur, sonuç yalnız $x$'e bağlıdır; OR versiyonu da vardır. Doğruluk tablosuyla göstermek kolay, ispatla göstermek biraz uğraştırıcıdır; hoca zorunlu olmayan bir alıştırma olarak bakılabileceğini söyledi.
- Birleşme (associative): aynı türden işlemlerde işlem sırasının önemi yoktur; hem AND hem OR için geçerlidir.
- Önceki örneklerde kullanılan De Morgan kuralı da hatırlatıldı.
<!-- BELİRSİZ: 01:16:46 civarında De Morgan kuralı anlatılırken altyazı bozuk ("OR işlemine ve AND işlemine dağılma özelliği"); kuralın slayttaki yazımı karede görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** De Morgan kuralları $(x\cdot y)' = x' + y'$ ve $(x + y)' = x'\cdot y'$ biçimindedir. Yutma (absorption) kuralının OR versiyonu $x + x\cdot y = x$'tir.

## 9. Minterm ve Maxterm ile Fonksiyon Yazma

Çoğunluk fonksiyonu akıl yürütmeyle çözülmüştü. Herhangi bir lojik problemde doğruluk tablosundan lojik ifadeye geçmek için izlenecek sistematik yollar vardır. Bunlardan biri doğruluk tablosundaki değerleri doğrudan kullanmaktır.

### 9.1 Mintermler ve çarpımlar toplamı

$n$ değişkenli bir $F(x_1, x_2, \dots, x_n)$ fonksiyonunun doğruluk tablosu $2^n$ satırdır (3 giriş için 8). Tablo bütün girişlerin 0 olduğu satırdan başlar, bütün girişlerin 1 olduğu satırda biter. Çıkışlar $f_0, f_1, \dots, f_{2^n-1}$ olsun; her biri 0 ya da 1'dir (ekrandan, 01:25:00).

Birinci satır ($0\,0\,\dots\,0$) için öyle bir çarpım terimi aranır ki yalnız bu satırda 1, diğer bütün satırlarda 0 versin.

**Soru:** Bu hangi fonksiyondur? **Cevap:** Bir öğrenci bütün değişkenlerin değillerinin AND'lendiği fonksiyon olduğunu söyledi: $x_1'\cdot x_2'\cdot x_3' \cdots x_n'$.

Bu terim $2^n$ satırlı tablonun yalnız bir satırını seçer. Bu satırda $F$'in $f_0$ olması istendiği için terim $f_0$ ile çarpılır. İkinci satır ($0\,0\,\dots\,0\,1$) için genel kural şudur: satırdaki değişken 0 ise tümleyeni, 1 ise kendisi yazılır. Böylece ikinci satır için $x_1' x_2' \cdots x_n$ terimi elde edilir ve $f_1$ ile çarpılır. Son satırda (hepsi 1) terim $x_1 x_2 \cdots x_n$ olur ve $f_{2^n-1}$ ile çarpılır. Hepsi toplanınca:

$$F(x_1, \dots, x_n) = x_1'x_2'\cdots x_n'\, f_0 + x_1'x_2'\cdots x_n\, f_1 + \dots + x_1x_2\cdots x_n\, f_{2^n-1}$$

Her satırda yalnız o satırın değerleri varken 1 üreten terime minterm denir. $x_1 x_2 \dots x_n$ bir $n$ basamaklı ikili sayı gibi düşünülürse, bu sayı $i$ değerini aldığında 1 veren terim $i$ numaralı mintermdir ($m_i$). Genel ifade (ekrandan, 01:40:00):

$$F(x_1, x_2, \dots, x_n) = \sum_{i=0}^{2^n-1} m_i\, f_i$$

$m_i$ şöyle yazılır: $i$ ikili olarak yazılır; 1 olan basamağın değişkeni olduğu gibi, 0 olan basamağınki tümleyenli gelir. Hocanın örneği (ekrandan, 01:40:00): 5 değişkenli bir fonksiyonda $1\,0\,1\,0\,1$ için terim $x_1 x_2' x_3 x_4' x_5$ olur. Bu sayı $16 + 4 + 1 = 21$ olduğundan bu terim 21 numaralı mintermdir.

$f_i = 0$ olan satırların mintermleri 0 ile çarpıldığı için ifadeden düşer. Bu yüzden fonksiyon yalnız çıkışı 1 olan mintermlerin (doğru mintermler) toplamı olarak yazılır. Bu, Lojik Devreler dersinden bilinen çarpımlar toplamı (sum of products) gösterimidir.

### 9.2 Maxtermler ve toplamlar çarpımı

Bu kez fonksiyon, $x$'lere bağlı toplam terimlerinin çarpımı olarak yazılır. Minterm bir satırda 1 veren çarpım terimiydi; şimdi her satır için yalnız o satırda 0, diğer bütün satırlarda 1 veren bir toplam terimi aranır. Sıfırıncı satır için bu terim $x_1 + x_2 + \dots + x_n$'dir; yalnız bütün $x$'ler 0 iken 0 verir. Bu terime $f_0$ eklenir. Sıfırıncı maxterm budur (ekrandan, 01:40:00).

Maxterm yazarken kural mintermin tersidir: satırda 0 görülen yerde değişken kendisi gibi kalır, 1 görülen yerde tümleyeni gelir. İkinci satır için $x_1 + x_2 + \dots + x_n' + f_1$, son satır için $x_1' + x_2' + \dots + x_n' + f_{2^n-1}$ yazılır ve bütün terimler çarpılır.

Neden çalışır? İlgilenilen satır dışındaki bir girişte maxterm 1 verir; $f_i$ ile 1'in toplamı 1'dir ve çarpmada 1 etkisizdir. Bu yüzden her girişte yalnız o satıra ait terim etkili olur. İlgili satırda maxterm 0 olur ve terimin değeri $f_i$'ye eşit kalır. Genel ifade:

$$F(x_1, x_2, \dots, x_n) = \prod_{i=0}^{2^n-1} (M_i + f_i)$$

> **Hocanın vurgusu:** $F = \sum m_i f_i$ ve $F = \prod (M_i + f_i)$ yazımları önemlidir, çünkü daha karmaşık lojik bloklar tanımlanırken iç yapılar bu formüllerden hareketle kurulacaktır.

> **Ders sonrası not:** Hoca maxterm formülünü önce $\prod M_i \cdot f_i$ biçiminde yazdı; bir öğrencinin "artı $f_i$ mi olmalı?" uyarısı üzerine doğru biçimin $\prod (M_i + f_i)$ olduğunu söyleyerek düzeltti.

### 9.3 Örnek: aynı fonksiyonun iki yazımı

Tahtadaki fonksiyon (ekrandan, 01:35:00):

| $x$ | $y$ | $F$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Mintermlerle:

$$F(x,y) = x'y'\cdot 0 + x'y\cdot 1 + xy'\cdot 1 + xy\cdot 0 = x'y + xy'$$

Çıkışı 0 olan satırlar düşer; geriye çıkışı 1 olan doğru mintermler kalır. Her terim bir çarpım terimidir ve terimler bir OR kapısında toplanır.

Maxtermlerle (aynı fonksiyon, $G$ denerek):

$$G = (x + y + 0)\,(x + y' + 1)\,(x' + y + 1)\,(x' + y' + 0)$$

Parantez içinde 1 olan terimler zaten 1 olur ve çarpmada etkisizdir. Toplamada 0 etkisiz olduğundan geriye yalnız çıkışı 0 olan satırların (yanlış maxtermlerin) terimleri kalır:

$$G = (x + y)(x' + y')$$

İki ifadenin aynı olduğu dağılma ile gösterilir (ara adım eklendi):

$$(x + y)(x' + y') = xx' + xy' + yx' + yy' = 0 + xy' + x'y + 0 = xy' + x'y$$

Yani fonksiyon hem çarpımlar toplamı hem de toplamlar çarpımı biçiminde yazılabilir.

## 10. Karnaugh Haritası ile İndirgeme

Çarpımlar toplamı ya da toplamlar çarpımı biçiminde yazılmış bir ifadeden bir terim çıkarıldığında sonuç değişmiyorsa fonksiyon indirgenebilir, yani içinde gereksiz terimler vardır. Bunları gidermenin yollarından biri Karnaugh haritasıdır; eliminasyon yöntemleri de vardır. Karnaugh haritasının amacı, bir değişkene göre paranteze alınabilecek durumları pratik biçimde yakalamaktır.

### 10.1 Örnek

Slayttaki örnek (ekrandan, 01:20:00; 01:45:00): değişkenler $x_1 x_2 x_3$ (tahtada $a, b, c$), doğru mintermler $m_0, m_2, m_4, m_5, m_6$'dır.

| $x_3 \backslash x_1x_2$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 1 ($m_0$) | 1 ($m_2$) | 1 ($m_6$) | 1 ($m_4$) |
| 1 | 0 ($m_1$) | 0 ($m_3$) | 0 ($m_7$) | 1 ($m_5$) |

Çarpımlar toplamı:

$$F = A'B'C' + A'BC' + AB'C' + AB'C + ABC'$$

Cebirsel indirgeme hocanın adımlarıyla:

- $A'B'C'$ ve $AB'C'$, $B'C'$ parantezine alınınca içeride $A + A' = 1$ kalır; çarpmada 1 etkisiz olduğundan $B'C'$ olur.
- Benzer biçimde $A'BC'$ ve $ABC'$, $BC'$ parantezine alınınca $BC'$ olur.
- Bir öğrenci dört terimin $C'$ altında toplanabileceğini söyledi: $B'C' + BC' = C'(B + B') = C'$. Yani $C$'nin 0 olduğu dört terim tek başına $C'$ ile temsil edilir.
- Geriye $AB'C$ kalır. $AB'C'$ terimi bir kez daha yazılırsa ($x + x = x$ olduğu için ifade değişmez), bu kopya $AB'C$ ile birleşir: $AB'(C + C') = AB'$.

Sonuç:

$$F = C' + AB'$$

Bu, slayttaki $f = \bar{x}_3 + x_1\bar{x}_2$ ile aynıdır. Bir terimin iki farklı indirgemede kullanılabildiği bu örnekte görülür.

### 10.2 Haritanın mantığı

Denklemle bu indirgemeleri görmek zordur; bu yüzden Karnaugh haritası kullanılır. Harita, değişkenlerin komşuluklarını, yani yalnız bir bitin değiştiği terimleri gösterir. Bir terimde $A$, diğerinde $A'$ varsa ve geri kalan bileşenler aynıysa, parantez alındığında $A + A'$ birbirini götürür. Bu yüzden sütun başlıkları 0, 1, 2, 3 sırasıyla değil, her adımda tek bit değişecek biçimde $00, 01, 11, 10$ sırasıyla yazılır. Birinci ve dördüncü sütun ($00$ ve $10$) arasında da tek bit fark vardır; bu yüzden kenarlar da komşudur.

Pratikte doğru mintermler 1'e 4'lük ya da 2'ye 2'lik bloklar halinde, ya da ikili olarak gruplanır. İkili grup bir değişkeni, dörtlü grup iki değişkeni eler. Sekiz hücrenin hepsi 1 ise fonksiyon zaten 1'e eşittir ve bütün değişkenlerden kurtulunur. Bir hücre birden fazla grupta kullanılabilir; denklemde bunun karşılığı terimi bir kez daha yazmaktır.

**Soru:** Dörtten fazla girdi, örneğin beş değişken varken harita nasıl kuruluyordu? **Cevap:** Dört değişkenlik iki harita sırt sırta konur: biri beşinci değişkenin 0, diğeri 1 olduğu duruma karşılık gelir ve iki haritanın karşılıklı hücreleri arasında da komşuluk vardır. Ancak dörtten fazla değişken için görsel olarak indirgeme çok zorlaşır; bu durumda Quine-McCluskey gibi başka yöntemler kullanılır.

## 11. İşaretsiz ve İşaretli Sayı Gösterimleri

Dijital sistem, değişkenleri ikili gösterimde görür. Bu gösterimin işaretli mi işaretsiz mi yorumlanacağı, kullanılan komuta bağlıdır. Örneğin işaretli bir komutta (çıkarma gibi) işlenen işaretli sayı olarak ele alınır; işaretsiz toplamada ise sayı işaretsiz kabul edilir ve elde taşması kontrol edilir. $n$ bitlik bir gösterimde her basamak 0 ya da 1'dir; gösterim budur, yorum ise ayrıdır. Gösterimler iki başlık altında toplanır: işaretsiz ve işaretli (ekrandan, 02:05:00).

### 11.1 İşaretsiz sayılar

$n$ bitlik işaretsiz bir sayıda en yüksek anlamlı bitten en düşük anlamlı bite kadar her basamağın bir ağırlığı vardır: $2^{n-1}, \dots, 2^1, 2^0$ (ekrandan, 02:10:00).

**Soru:** 8 bit işaretsiz yazılabilecek en küçük ve en büyük sayıların gösterimi ve ondalık karşılığı nedir? **Cevap:** En küçük: bütün bitler 0, $0000\,0000 = 0$. En büyük: bütün bitler 1, $1111\,1111 = 255$. Yani 8 bitlik işaretsiz gösterimde 0 ile 255 arası yazılır (ekrandan, 02:10:00).

İşaretli sayılar için günümüz dijital sistemlerinde kullanılan gösterim 2'ye tümleyendir. Başka gösterimler de vardır: 1'e tümleyen ve işaretli genlik.

### 11.2 İşaretli genlik (sign magnitude)

8 bitlik sayıda en yüksek anlamlı bit işareti belirler: 0 ise pozitif, 1 ise negatif. Geri kalan bitler genliği belirtir (ekrandan, 02:10:00).

- $1000\,0111$: sayı negatif, genlik 7; değer $-7$.
- $0111\,1111$: sayı pozitif, genlik 127; değer $+127$.

**Soru:** İşaretli genlikte yazılabilecek en küçük ve en büyük sayılar nedir? **Cevap:** Sohbetten $-128$ ile $+127$ cevabı geldi; hoca işaretli genlikte bunun doğru olmadığını söyledi. En büyük sayı pozitiftir (işaret biti 0) ve bütün genlik bitleri 1'dir: $0111\,1111 = +127$. En küçük sayı negatiftir ve genliği olabildiğince büyüktür: $1111\,1111 = -127$ (ekrandan, 02:15:00).

$-1$'den $-127$'ye 127 değer, $+1$'den $+127$'ye 127 değer vardır; toplam 254. 8 bitte 256 farklı gösterim olmalıdır.

**Soru:** Geri kalan iki gösterim nerede? **Cevap:** Bir öğrenci sıfırın iki kez gösterildiğini söyledi: $0000\,0000$ artı sıfır, $1000\,0000$ eksi sıfır gibidir (ekrandan, 02:15:00). Bu gösterimin uygulanması ve yorumlanması kolaydır ama iki sıfır gösterimi vardır; sorunu budur.

### 11.3 1'e tümleyen

En yüksek anlamlı bit yine işaret bitidir. Sayı pozitifse genlik kalan bitlerin kendisidir; negatifse genlik kalan bitlerin 1'e tümleyeniyle bulunur (ekrandan, 02:15:00).

- $0111\,1111$: pozitif, genlik 127; değer $+127$.
- $1111\,1111$: negatif, kalan bitlerin tersi $000\,0000$, genlik 0; değer "$-0$".
- $1111\,1110$: negatif, kalan bitlerin tersi $000\,0001$, genlik 1; değer $-1$.
- $1000\,0000$: negatif, kalan bitlerin tersi $111\,1111$, genlik 127; değer $-127$.

En büyük sayı $0111\,1111 = +127$, en küçük sayı $1000\,0000 = -127$'dir (ekrandan, 02:20:00). Yine $-1..-127$ ve $+1..+127$ olmak üzere 254 değer vardır; $0000\,0000$ ($+0$) ve $1111\,1111$ ($-0$) aynı sayının iki gösterimidir. Değerlendirmesi kolaydır ama iki sıfır olduğu için sorunludur.

### 11.4 2'ye tümleyen

En yüksek anlamlı bit işaret bitidir: 1 ise negatif, 0 ise pozitif. Sayı pozitifse genlik sayının kendisi, negatifse genlik kalan bitlerin 2'ye tümleyenidir. 2'ye tümleyen için önce 1'e tümleyen alınır, sonra 1 eklenir (ekrandan, 02:20:00).

- $0000\,1111$: pozitif; değer $+15$.
- $1000\,1111$: negatif. Kalan bitler $000\,1111$, 1'e tümleyeni $111\,0000$, 1 eklenince $111\,0001$. Bu $64 + 32 + 16 + 1 = 113$'tür; değer $-113$.

En büyük sayı pozitiftir ve genlik bitleri hep 1'dir: $0111\,1111 = +127$. En küçük sayı negatiftir; genliğin en büyük olması için kalan bitlerin 2'ye tümleyeni sonrası en büyük değer çıkmalıdır, bu da kalan bitlerin hepsinin 0 olmasıyla olur: $1000\,0000$. Kalan bitlerin 1'e tümleyeni $111\,1111 = 127$, 1 eklenince 128; değer $-128$.

Gösterim simetrik değildir: $-1..-128$ ve $+1..+127$ olmak üzere 255 sıfırdan farklı değer vardır ve sıfırın tek gösterimi vardır: sekiz adet 0 bitinden oluşan $0000\,0000$.

$1111\,1111$ incelendiğinde: kalan bitlerin 1'e tümleyeni $000\,0000$, 1 eklenince 1; sayı negatif olduğundan değer $-1$'dir. Buradan şu sonuç çıkar: $n$ bitlik bir sayı yalnız 1'lerden oluşuyorsa 2'ye tümleyen gösterimde her zaman $-1$'e eşittir.

### 11.5 İşaret genişletme (sign extension)

**Soru:** 4 bitlik 2'ye tümleyen $-1$ ($1111$), işareti ve değeri korunarak 8 bite nasıl genişletilir? **Cevap:** Sayının soluna bit sayısını tamamlayacak kadar 1 eklenir: $1111 \rightarrow 1111\,1111$. Bu da 8 bit olarak $-1$'e eşittir.

> **Hocanın vurgusu:** İşaret genişletme, tasarımlarda kullanılacak önemli bir özelliktir.

> **Ek bilgi (derste anlatılmadı):** İşaret genişletmenin genel kuralı, sayının işaret bitinin soldaki yeni bitlere kopyalanmasıdır; pozitif sayılarda soldan 0, negatif sayılarda soldan 1 eklenir.

## 12. Multiplexer (MUX)

### 12.1 Tanım ve adlandırma

Çoğullayıcı (multiplexer) kombinasyonel bir lojik bloktur. Şematik gösterimi bir yamuktur: sol tarafta girişler, sağ tarafta tek bir çıkış, dik kenarda seçim uçları vardır. $n$ adet seçim ucu varsa $2^n$ adet giriş ucu olur. Hoca iki şeye bakılacağını söyledi: yalnız fonksiyon tablosundan iç yapının tasarlanması ve yalnız MUX kullanarak lojik fonksiyonların gerçeklenmesi.

MUX'lar giriş sayısına göre adlandırılır: 4 girişli olana 4'e 1 (4x1) MUX denir.

**Soru:** 3'e 1 MUX olabilir mi? **Cevap:** Öğrenciler olamayacağını söyledi; hoca onayladı. Seçim ucu sayısı kadar $2^n$ giriş olacağı için MUX'lar 2, 4, 8 gibi 2'nin kuvveti kadar girişe sahiptir.

### 12.2 2'ye 1 MUX

İki giriş ($W_0$, $W_1$), bir seçim ucu ($S$) ve bir çıkış ($F$) vardır. $S = 0$ ise $F = W_0$, $S = 1$ ise $F = W_1$'dir. Minterm formülüyle:

$$F = S'\,W_0 + S\,W_1$$

İç yapıda $S$ bir NOT'tan geçip $W_0$ ile AND'lenir, $S$ ayrıca $W_1$ ile AND'lenir, iki AND çıkışı bir OR'da birleşerek $F$'yi verir.

### 12.3 4'e 1 MUX

Dört giriş ($W_0..W_3$), iki seçim ucu ($S_1$ daha anlamlı, $S_0$) ve bir çıkış vardır (ekrandan, 02:30:00):

| $S_1$ | $S_0$ | $F$ |
|---|---|---|
| 0 | 0 | $W_0$ |
| 0 | 1 | $W_1$ |
| 1 | 0 | $W_2$ |
| 1 | 1 | $W_3$ |

Dört giriş kaynağından hangisinin çıkışa aktarılacağını seçen bir yapıdır. Lojik ifade (ekrandan, 02:30:00):

$$F = S_1'S_0'\,W_0 + S_1'S_0\,W_1 + S_1S_0'\,W_2 + S_1S_0\,W_3$$

İç yapıda $S_1$ ve $S_0$'ın hem kendisi hem de NOT'lu hali sisteme verilir. $W_0$, $S_1'$ ve $S_0'$ bir AND'e girer; diğer üç terim de aynı biçimde kendi AND'lerine girer. Dört AND çıkışı bir OR'da birleşerek $F$'yi oluşturur. Böylece fonksiyon tablosu verilmiş bir kara kutunun iç yapısının nasıl gerçeklenebileceği ortaya çıkar.

### 12.4 MUX ile lojik fonksiyon gerçekleme

Herhangi bir lojik fonksiyon MUX ile gerçeklenebilir mi? İç kısımda yalnız MUX, lojik 0 ve lojik 1 kullanılarak denenir (ekrandan, 02:35:00).

Tek değişkenli fonksiyon: $x = 0$ iken 1, $x = 1$ iken 0 (yani $x'$). $x$ seçim ucuna bağlanır. $x = 0$ iken $W_0$ çıkışa aktarılır ve çıkış 1 olmalıdır, bu yüzden $W_0 = 1$. $x = 1$ iken $W_1$ aktarılır ve çıkış 0 olmalıdır, bu yüzden $W_1 = 0$.

İki değişkenli fonksiyon (ekrandan, 02:35:00):

| $x$ | $y$ | $F$ |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Bir öğrenci bunun XOR ya da XNOR kapısına benzediğini söyledi; hoca kapının adının değil tasarımın önemli olduğunu belirtti. AND, OR kullanılıp kullanılamayacağı soruldu; hoca bunların yasak olduğunu, MUX, sabitler ve gerekirse NOT kullanılabileceğini söyledi. İki alternatif vardır:

- Seçim $x$ ile: $x = 0$ satırlarında $F$, $y$'nin tersidir ($y = 0 \rightarrow 1$, $y = 1 \rightarrow 0$), bu yüzden $W_0 = y'$. $x = 1$ satırlarında $F$, $y$ ile aynı yönde değişir, bu yüzden $W_1 = y$.
- Seçim $y$ ile: $y = 0$ satırlarında $F = x'$, bu yüzden $W_0 = x'$. $y = 1$ satırlarında $F = x$, bu yüzden $W_1 = x$.

İki değişkenli bir fonksiyon 2'ye 1 MUX ile yapılırsa girişlere yazılabilecek değerler tek değişkenli dört fonksiyondan biridir: $0$, $1$, $y$, $y'$. Üç değişkenli bir fonksiyon 2'ye 1 MUX ile yapılırsa girişlere iki değişkenli fonksiyonlar yazılır ve bunlardan $2^{2^2} = 16$ tane vardır; iş karmaşıklaşır. Bu yüzden pratikte fonksiyonun değişken sayısı kadar seçim ucuna sahip bir MUX kullanmak daha uygundur; bir üst boyuttaki MUX ile de yapmak mümkündür.

Aynı fonksiyon 4'e 1 MUX ile: $x$ yüksek anlamlı seçim ucuna ($S_1$), $y$ düşük anlamlı seçim ucuna ($S_0$) bağlanır. $x = y = 0$ iken $W_0$ çıkışa gider ve çıkış 1 olmalıdır, bu yüzden $W_0 = 1$. $x = 0, y = 1$ iken çıkış 0 olmalıdır, $W_1 = 0$. Böylece $W_0..W_3 = 1, 0, 0, 1$ olur; doğruluk tablosu doğrudan girişlere yazılmış olur. Girişlere yazılan değerler hiç değişkeni olmayan lojik fonksiyonlardır, yani 0 ya da 1.

Özetle: hiç değişkeni olmayan fonksiyonlar 0 ve 1; tek değişkenli fonksiyonlar $0, 1, x, x'$; iki değişkenli fonksiyonlar 16 tanedir. Küçük MUX'larla daha büyük bir MUX'un nasıl kurulacağı ve decoder sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:52:24): Yalnız AND ve NOT kullanarak OR kapısı nasıl elde edilir?

> **Çözüm:** $x'$ ve $y'$ AND'lenip sonuca NOT uygulanır. De Morgan ile $(x'y')' = x + y$.

**Soru 2** (derste sözlü, 00:54:39): Yalnız NAND kapılarıyla NOT, OR ve AND nasıl kurulur?

> **Çözüm:** NOT: iki girişi birleştirilmiş NAND, $(xx)' = x'$. OR: $x'$ ve $y'$ (NAND-NOT'larla) bir NAND'e verilir, $(x'y')' = x + y$. AND: $(xy)'$ çıkışı bir NAND-NOT'tan geçirilir, $xy$.

**Soru 3** (derste sözlü, 00:59:13): $f: B \rightarrow B$ biçiminde kaç farklı fonksiyon yazılabilir?

> **Çözüm:** 4: $0$, $x$, $x'$, $1$.

**Soru 4** (derste sözlü, 01:01:53): $g: B^2 \rightarrow B$ biçiminde kaç farklı fonksiyon yazılabilir?

> **Çözüm:** Doğruluk tablosu $2^2 = 4$ satır, her satır 2 değer: $2^4 = 16$. Genel olarak $m$ giriş için $2^{2^m}$.

**Soru 5** (ekrandan, 01:10:00): Üç girişli çoğunluk fonksiyonunun doğruluk tablosunu, indirgenmiş ifadesini ve yalnız NAND ile gerçeklenmesini yazın.

> **Çözüm:** Çıkış sütunu 0, 0, 0, 1, 0, 1, 1, 1. $F = AB + BC + AC = \big((AB)'(BC)'(AC)'\big)'$: üç adet iki girişli NAND ve bir üç girişli NAND.

**Soru 6** (ekrandan, 01:35:00): Çıkışları sırasıyla 0, 1, 1, 0 olan $F(x, y)$'yi mintermler ve maxtermler cinsinden yazıp iki ifadenin eşit olduğunu gösterin.

> **Çözüm:** $F = x'y + xy'$; $G = (x + y)(x' + y')$. Çarpım açılınca $xx' + xy' + x'y + yy' = xy' + x'y$.

**Soru 7** (ekrandan, 01:45:00): Doğru mintermleri $m_0, m_2, m_4, m_5, m_6$ olan üç değişkenli fonksiyonu indirgeyin.

> **Çözüm:** $C = 0$ olan dört hücre $C'$ verir; $m_4$ ile $m_5$ ikilisi $AB'$ verir. $F = C' + AB'$ (slayttaki gösterimle $\bar{x}_3 + x_1\bar{x}_2$).

**Soru 8** (derste sözlü, 02:05:43): 8 bit işaretsiz yazılabilecek en küçük ve en büyük sayıların gösterimi ve ondalık karşılığı nedir?

> **Çözüm:** $0000\,0000 = 0$ ve $1111\,1111 = 255$.

**Soru 9** (derste sözlü, 02:08:30): İşaretli genlikte $0111\,1111$ kaçtır? Bu gösterimde en küçük ve en büyük sayılar nedir, 256 gösterimden eksik kalan ikisi nerededir?

> **Çözüm:** $+127$. Aralık $1111\,1111 = -127$ ile $0111\,1111 = +127$; 254 sıfırdan farklı değer vardır. Kalan iki gösterim $0000\,0000$ ($+0$) ve $1000\,0000$ ($-0$)'dır.

**Soru 10** (derste sözlü, 02:15:14): 1'e tümleyende en büyük ve en küçük sayıların ikili ve ondalık gösterimleri nedir?

> **Çözüm:** $0111\,1111 = +127$, $1000\,0000 = -127$. Sıfırın iki gösterimi vardır: $0000\,0000$ ve $1111\,1111$.

**Soru 11** (ekrandan, 02:20:00): 2'ye tümleyende $0000\,1111$ ve $1000\,1111$ kaçtır? En büyük ve en küçük sayılar nedir?

> **Çözüm:** $+15$ ve $-113$ ($111\,0000 + 1 = 111\,0001 = 113$). En büyük $0111\,1111 = +127$, en küçük $1000\,0000 = -128$.

**Soru 12** (derste sözlü, 02:21:26): 4 bitlik 2'ye tümleyen $-1$ sayısı, değeri korunarak 8 bite nasıl genişletilir?

> **Çözüm:** Soldan 1'lerle doldurulur: $1111 \rightarrow 1111\,1111$, yine $-1$.

**Soru 13** (derste sözlü, 02:24:34): 3'e 1 MUX olabilir mi?

> **Çözüm:** Hayır. $n$ seçim ucu $2^n$ girişe karşılık gelir; MUX'lar 2, 4, 8 ... girişlidir.

**Soru 14** (ekrandan, 02:35:00): Çıkışları sırasıyla 1, 0, 0, 1 olan $F(x, y)$'yi yalnız 2'ye 1 MUX, lojik sabitler ve NOT ile; ayrıca 4'e 1 MUX ile gerçekleyin.

> **Çözüm:** Seçim $x$: $W_0 = y'$, $W_1 = y$. Seçim $y$: $W_0 = x'$, $W_1 = x$. 4'e 1 MUX'ta $S_1 = x$, $S_0 = y$, $W_0..W_3 = 1, 0, 0, 1$.

## Dersin Toparlaması

Ders, bilgisayar donanımının genel resmiyle başladı: komut kümesi ile donanımın sıkı bağı, her komutu bir çevrimde bitiren basit işlemci, komutları adım adım örtüştürerek verimi artıran boru hattı ve bunun dallanma ile veri bağımlılığı sorunları, programların komşu ve tekrarlanan erişim eğiliminden yararlanan ön bellek ve ana belleğe sığmayan programlar için sanal bellek. Ardından bu konulara temel olacak lojik bilgiler tekrarlandı: temel kapılar, tam kapı kümeleri ve yalnız NAND ile tasarım, $2^{2^m}$ fonksiyon sayısı, çoğunluk fonksiyonu, Boole cebri eşitlikleri, minterm ve maxterm ile fonksiyon yazma, Karnaugh haritasıyla indirgeme.

Son kısımda işaretsiz sayılar ile işaretli genlik, 1'e tümleyen ve 2'ye tümleyen gösterimleri karşılaştırıldı; yalnız 2'ye tümleyende sıfırın tek gösterimi olduğu ve işaret genişletmenin nasıl yapıldığı görüldü. Multiplexer'ın iç yapısı minterm formülünden kuruldu ve MUX ile lojik fonksiyon gerçekleme örneklendi. Bir sonraki adım, küçük MUX'larla daha büyük MUX kurmak ve decoder'dır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
