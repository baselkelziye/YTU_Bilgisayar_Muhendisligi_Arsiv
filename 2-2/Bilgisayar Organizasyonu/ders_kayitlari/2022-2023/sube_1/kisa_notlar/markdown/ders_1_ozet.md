# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı ve kapsamı
  - Ders, bir CPU'nun işleyişine ayrıntılı bakmayı amaçlar: işlemcinin içinde hangi birimler var, bunlar nasıl çalışır ve nasıl tasarlanabilir, işlemci çevre birimleriyle hangi arayüzlerle haberleşir.
  - Konu akışı (ekrandan, 00:05:00): bilgisayar donanımına giriş, kombinasyonel ve ardışıl lojik devreler, saklayıcı ve sayıcılar, programlanabilir yapılar (PLD, PLA, PAL), bellek birimleri (RAM, ROM), saklayıcı transfer işlemleri ve ortak veri yolu, komut yapısı ve adresleme yöntemleri, merkezi işlem birimi tasarımı, pipeline ile veri işleme, giriş/çıkış birimleri ve haberleşme, ön bellek yapısı ve eşleme (map) teknikleri, sanal bellek ve sayfa tabloları.
- Komut kümesi mimarisi (ISA) ile donanım ilişkisi
  - İşlemcinin desteklediği her komutun arka planda bir donanım ve denetim karşılığı olmalıdır. Örneğin tamsayı çarpma komutu desteklenecekse çarpma devresi ve uygun denetim gerekir.
  - Adresleme yöntemleri de komut kümesine bağlıdır: doğrudan bir adrese erişmek ile bir referans adrese göre belirli uzaklıktaki adrese erişmek farklı komut grupları ve farklı bellek denetimi gerektirir.
  - Komut sayısını sınırlayan şeylerden biri, denetim biriminin ne kadar karmaşık olmasına izin verildiğidir.
- Tek çevrimli (single cycle) işlemci
  - Her komut tek bir saat çevriminde tamamlanır. Avantajı tasarımın basitliğidir; bedeli komut kümesinin dar olmasıdır (örneğin toplama ve kaydırmalardan oluşan çarpma tek çevrimde bitmez). Bu mimari "hardwired" denetimle tasarlanacaktır.
- Boru hattı (pipeline) mantığı
  - Bir komutun yürütülmesi alt adımlara ayrılır: komutu bellekten getirme, çözümleme, işlenenleri (operand) getirme, yürütme, sonucu geri yazma. Tasarıma göre 4, 5 ya da 6 adım olabilir.
  - Seri yürütmede bir komut yalnız bir bloğu meşgul eder, diğer bloklar boşta bekler. Boru hattında her blok aynı anda farklı bir komut üzerinde çalışır; bu da verimi (throughput) artırır.
  - Sorunlar: koşullu dallanmada boru hattına alınmış sonraki komutlar boşa gider; bir komut önceki komutun değiştireceği yazmacı bekliyorsa önceki sonuç çıkmadan yürütülemez.
- Ön bellek (cache) ve sanal bellek
  - Ana bellek görece yavaştır. Programlar bir elemana eriştikten sonra büyük olasılıkla komşusuna erişir (dizi, matris) ve aynı değişkene tekrar tekrar erişir (döngüdeki biriktirici). Bu yüzden işlemci ile ana bellek arasına küçük ve hızlı bir bellek konur, erişilen adres ve çevresi buraya kopyalanır, işlemci önce buraya bakar.
  - Büyük bellekteki hangi adresin küçük bellekte nereye eşleneceği bir tasarım sorusudur: doğrudan eşleme, serbest (tam ilişkili) eşleme, kümeli eşleme.
  - Ana belleğe sığmayan programlar ikincil bellekte (disk) tutulur, çalışacak kısım parça parça ana belleğe taşınır; ikincil bellek ile ana bellek arasında da benzer bir eşleme problemi vardır.
- Temel lojik kapılar ve Boole cebri
  - Boole cebri AND, OR, NOT ile her lojik fonksiyonu ifade eder. AND ve OR $B^2 \rightarrow B$, NOT $B \rightarrow B$ fonksiyonudur ($B=\{0,1\}$) (ekrandan, 00:45:00).
  - NAND = AND + NOT, NOR = OR + NOT; NAND ve NOR, standart CMOS'ta AND ve OR'dan daha az transistör gerektirir (ekrandan, 00:45:00). XOR: $x'y + xy'$.
- Tam (complete) kapı kümeleri
  - Yalnız kümedeki kapı türleriyle her lojik fonksiyon gerçeklenebiliyorsa küme tamdır; gereksiz elemanı olmayan tam küme minimaldir (ekrandan, 00:50:00).
  - {AND, OR, NOT} tamdır ama minimal değildir; {AND, NOT}, {OR, NOT}, {NAND}, {NOR} örnek tam kümelerdir.
  - Yalnız NAND ile: girişleri birleştirilmiş NAND NOT verir; NAND'in arkasına NOT (NAND) konunca AND çıkar; girişleri terslenip NAND'e verilince $(x'y')' = x+y$ çıkar.
- Lojik fonksiyonların ifade biçimleri ve fonksiyon sayısı
  - Doğruluk tablosu, lojik ifade, grafik (şematik) biçim, HDL kodu (ekrandan, 01:00:00).
  - $m$ girişli bir fonksiyonun doğruluk tablosu $2^m$ satırdır; her satır 0 ya da 1 olabildiğinden yazılabilecek farklı fonksiyon sayısı $2^{2^m}$'dir (1 giriş: 4, 2 giriş: 16).
- Çoğunluk (majority) fonksiyonu
  - Üç girişten çoğunluğu 1 ise çıkış 1. Çıkış sütunu: 0, 0, 0, 1, 0, 1, 1, 1; indirgenmiş ifade $F = AB + BC + AC$ (ekrandan, 01:10:00).
  - Yalnız NAND ile: $F = \big((AB)'(BC)'(AC)'\big)'$, yani üç adet iki girişli NAND ve bir üç girişli NAND.
- Boole cebri eşitlikleri (ekrandan, 01:15:00)
  - Etkisiz eleman, tümleyen, değişme, dağılma, idempotent, yutan eleman (null); ayrıca değilin değili, yutma ($x(x+y)=x$), birleşme ve De Morgan.
- Minterm ve maxterm
  - Minterm: doğruluk tablosunun yalnız bir satırında 1 veren çarpım terimi; satırdaki 0 değişkenin tümleyeniyle, 1 kendisiyle yazılır. $F = \sum_{i=0}^{2^n-1} m_i f_i$ (ekrandan, 01:40:00).
  - Maxterm: yalnız bir satırda 0 veren toplam terimi; satırdaki 0 değişkenin kendisiyle, 1 tümleyeniyle yazılır. $F = \prod_{i=0}^{2^n-1} (M_i + f_i)$.
- Karnaugh haritası
  - Komşu hücrelerde yalnız bir bit değişir (00, 01, 11, 10). 2, 4, 8'lik komşu gruplar değişken eler; bir terim birden fazla grupta kullanılabilir (ekrandan, 01:45:00).
- İşaretli sayı gösterimleri (8 bit)
  - İşaretsiz: 0 ile 255 arası.
  - İşaretli genlik: −127 ile +127 arası; +0 ve −0 iki ayrı gösterimdir.
  - 1'e tümleyen: −127 ile +127 arası; yine iki sıfır vardır.
  - 2'ye tümleyen: −128 ile +127 arası; sıfırın tek gösterimi vardır. Günümüz sistemlerinde kullanılan budur.
- Multiplexer (MUX)
  - $n$ seçim ucu varsa $2^n$ giriş ucu vardır; bu yüzden 3'e 1 MUX olmaz (ekrandan, 02:30:00).
  - İç yapı minterm formülünden çıkar: 2'ye 1 MUX $F = S'W_0 + SW_1$; 4'e 1 MUX $F = S_1'S_0'W_0 + S_1'S_0W_1 + S_1S_0'W_2 + S_1S_0W_3$.
  - MUX ile herhangi bir lojik fonksiyon gerçeklenebilir (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- ISA ve donanım ilişkisi
  - Komut kümesi, bellek erişimi ve arka plandaki denetim ve donanım modülleri birbirine sıkı bağlıdır. Tasarım kararları buradan çıkar.
- Ön belleği dikkate alan programlama
  - Performans odaklı programlamada çalışılan mimarinin ön bellek özelliklerini bilmek çok önemlidir. Hoca, kümeli ön bellekli bir mimaride iki matris çarpımında taramaları ön belleğe uygun sırada yapmanın programı 6 kata kadar hızlandırabildiğini söyledi.
- Maxterm formülünün doğru yazımı
  - $F = \prod (M_i + f_i)$ biçimi önemlidir, çünkü daha karmaşık lojik blokların iç yapısı bu formüllerden kurulacaktır. Derste önce $M_i \cdot f_i$ yazıldı, bir öğrencinin uyarısıyla $M_i + f_i$ olarak düzeltildi.
- İşaret genişletme (sign extension)
  - 2'ye tümleyende yalnız 1'lerden oluşan her sayı −1'dir. 4 bitlik $1111$ sayısı değeri korunarak 8 bite genişletilirken soldan 1'lerle doldurulur: $1111\,1111$. Tasarımlarda kullanılacak önemli bir özelliktir.
- MUX boyutları
  - MUX'lar 2'nin kuvveti kadar girişe sahiptir (2, 4, 8 ...).

## Kısa Tekrar Notları

- Tek çevrimli işlemci: her komut bir saat çevriminde biter, komut kümesi dar olur.
- Boru hattı: getir, çöz, işlenen getir, yürüt, geri yaz; bloklar aynı anda farklı komutlarla çalışır. Dallanma ve veri bağımlılığı sorun yaratır.
- Ön bellek, uzamsal (komşu adres) ve zamansal (aynı adrese tekrar) erişim eğiliminden yararlanır.
- {NAND} ve {NOR} tek başına tam kümedir.
- $m$ girişli fonksiyon sayısı: $2^{2^m}$.
- Çoğunluk: $F = AB + BC + AC = \big((AB)'(BC)'(AC)'\big)'$.
- Çarpımlar toplamında yalnız çıkışı 1 olan (doğru) mintermler, toplamlar çarpımında yalnız çıkışı 0 olan (yanlış) maxtermler kalır.
- XOR örneği: $x'y + xy' = (x+y)(x'+y')$.
- Karnaugh sırası 00, 01, 11, 10 (Gray kodu).
- 8 bit aralıkları: işaretsiz 0..255; işaretli genlik ve 1'e tümleyen −127..+127 (iki sıfır); 2'ye tümleyen −128..+127.
- 2'ye tümleyen negatif sayının genliği: bitlerin 1'e tümleyeni + 1.
- $n$ seçim ucu, $2^n$ giriş; 4'e 1 MUX = dört minterm × giriş, OR ile birleşir.

## Detaylı Açıklamalar

Dersin giriş kısmında bilgisayar donanımının genel resmi çizildi. Lojik Devreler dersindeki tek bitlik bloklar burada modüler ve n bitlik hale getirilecek; yazmaçlar flip-flop'lara dayanır, ardışıl devreler bu hafıza elemanlarıyla kurulur. Yazmaçlar arası transfer dili (RTL) ile yazmaçtan yazmaca aktarma, iki yazmacı toplayıp sonucu yazmaca yazma, kaydırma gibi işlemler yapılacak, ardından komut yapısı ve adresleme yöntemleri incelenecek. Bu yapı taşları üzerine tek çevrimli bir işlemci tasarlanacak; tek çevrim, her komutun tek saat çevriminde bitmesi demektir ve bu, karmaşık komutlara izin vermez.

Boru hattı fikri bir komutun yürütülmesindeki adımlardan çıkar. Program kodu kalıcı bir bellekte durur, bir işaretçi (program sayacı) sıradaki komutu gösterir. Akış ardışıksa işaretçi bir sonraki komutu gösterir; dallanma ya da fonksiyon çağrısında işaretçinin değeri birden değişir. Komut getirilir, çözümlenir, gerekirse işlenenler bellekten alınır, işlem yürütülür ve sonuç belleğe geri yazılır. Seri yürütmede bu beş blok sırayla tek komutla meşgul olur. Boru hattında ise beşinci komut getirilirken dördüncü çözümlenir, üçüncünün işlenenleri alınır, ikinci yürütülür, birincinin sonucu yazılır. Hoca bunun dezavantajlarını da örnekledi: ilk komut koşullu dallanmaysa arkadan gelen komutlar çöpe gider; ikinci komut birincinin değiştireceği yazmacı bekliyorsa beklemek gerekir.

Ön bellek kısmında hoca iki gözlemi öne çıkardı: bir dizinin bir elemanına erişen program büyük olasılıkla bir sonraki döngüde komşu elemana erişir; birden ona kadar toplama yapan bir döngüdeki biriktirici değişkene ise farklı zamanlarda tekrar tekrar erişilir. Bu yüzden işlemci ile ana bellek arasına küçük, hızlı ve maliyeti makul bir bellek konur; erişilen adresin çevresi buraya kopyalanır, işlemci önce burada arar, yoksa ana bellekten getirir. Ortalama erişim hızı bu sayede kat kat artar.
<!-- BELİRSİZ: 00:21:17 civarında altyazıda ön bellek için "erişim süresini burada yüksek tutup" deniyor; bağlam ön belleğin hızlı olduğu yönünde, Whisper ya da sözlü kayma olabilir. -->

Lojik kısımda hoca önce kapıları fonksiyon olarak tanımladı: AND ve OR iki girişli olduğu için $B^2\rightarrow B$, NOT tek girişli olduğu için $B\rightarrow B$ fonksiyonudur. Tarihsel not olarak Boole cebrinin elektromekanik ve basınç tüplü düzeneklerle de gerçeklendiğini, Sovyet döneminde −1, 0, 1 değerli üçlü (ternary) mantıkla çalışan bir bilgisayar yapıldığını, burada her basamağa "trit" dendiğini anlattı.
<!-- BELİRSİZ: 00:45:02-00:45:32 arası tarihsel örnekler altyazıda bozuk; tüp düzeneğinin ayrıntısı ve üçlü bilgisayarın adı net değil. -->

Tam küme örneklerinde yalnız NAND ile üç temel kapı şöyle kuruldu: iki girişi birleştirilmiş NAND $(x\cdot x)' = x'$ verir. $(xy)'$ çıkışı bir NAND-NOT'tan geçirilince $xy$ elde edilir. $x$ ve $y$ önce NAND-NOT'larla terslenip bir NAND'e verilince $(x'y')' = x + y$ elde edilir. AND ve NOT ile OR da aynı De Morgan adımıyla elde edilir.

Çoğunluk fonksiyonunda hoca akıl yürütmeyle ilerledi: üç değişkenden herhangi ikisi 1 ise üçüncüye bakmaya gerek yoktur. Her ikili AND ile denetlenir ($AB$, $BC$, $AC$), sonuçlar OR ile birleştirilir. Şemada iki kat NOT eklenip ($x'' = x$) birer NOT kapıların çıkışına, diğerleri OR'un girişine kaydırılınca AND'ler NAND'e, girişleri terslenmiş OR da De Morgan ile üç girişli NAND'e dönüşür.

Minterm ve maxterm genel formülü tahtada türetildi (ekrandan, 01:25:00; 01:40:00). Örnek olarak $i=21$ için $10101_2$ yazılır, $m_{21} = x_1 x_2' x_3 x_4' x_5$ olur. XOR benzeri $F(x,y)$ (çıkışlar 0, 1, 1, 0) için mintermlerle $F = x'y + xy'$, maxtermlerle $G = (x+y)(x'+y')$ yazıldı; çarpım açılınca $xx' = 0$ ve $yy' = 0$ düştüğü için iki ifadenin eşit olduğu görüldü (ekrandan, 01:35:00).

Karnaugh örneğinde (ekrandan, 01:45:00) çıkışı 1 olan mintermler $m_0, m_2, m_4, m_5, m_6$'dır. Cebirsel yolda $A'B'C'$ ile $AB'C'$ birleşince $B'C'$, $A'BC'$ ile $ABC'$ birleşince $BC'$ kalır; $B'C' + BC' = C'$ olur. $AB'C'$ terimi bir kez daha yazılıp $AB'C$ ile birleştirilince $AB'$ çıkar. Sonuç $F = C' + AB'$, slayttaki $f = \bar{x}_3 + x_1\bar{x}_2$ ile aynıdır. Haritada aynı şey, bir bit değişen komşu hücreleri gruplamaktır.

Sayı gösterimlerinde 8 bit üzerinden çalışıldı (ekrandan, 02:15:00; 02:20:00). İşaretli genlikte $1000\,0111 = -7$, $0111\,1111 = +127$; $0000\,0000$ ve $1000\,0000$ ikisi de sıfırdır. 1'e tümleyende negatif sayının genliği kalan bitlerin tersidir: $1111\,1110 = -1$, $1000\,0000 = -127$, $1111\,1111 = -0$. 2'ye tümleyende negatif sayının genliği kalan bitlerin 1'e tümleyeni artı birdir: $0000\,1111 = +15$, $1000\,1111$ için $000\,1111 \rightarrow 111\,0000 \rightarrow 111\,0001 = 113$, yani $-113$; en küçük $1000\,0000 = -128$, en büyük $0111\,1111 = +127$.

MUX kısmında tek değişkenli $F = x'$ (çıkışlar 1, 0) için $x$ seçim ucuna bağlanır, $W_0 = 1$, $W_1 = 0$ verilir. İki değişkenli fonksiyon (çıkışlar 1, 0, 0, 1) 2'ye 1 MUX ve NOT ile iki yoldan kurulur: seçim $x$ ise $W_0 = y'$, $W_1 = y$; seçim $y$ ise $W_0 = x'$, $W_1 = x$. 4'e 1 MUX'ta $x$ yüksek, $y$ düşük anlamlı seçim ucuna bağlanır ve girişlere doğrudan doğruluk tablosu yazılır: $W_0..W_3 = 1, 0, 0, 1$ (ekrandan, 02:35:00). Üç değişkenli fonksiyon 2'ye 1 MUX ile yapılırsa girişlere iki değişkenli 16 fonksiyondan biri yazılır; bu yüzden değişken sayısına uygun MUX kullanmak daha pratiktir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
