# Ders 6 Genişletilmiş Notu: Bilgisayarın Tarihçesi, Bilgisayar Organizasyonu ve Programlama Dilleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hesaplama Cihazlarından İlk Bilgisayarlara
- 2. İlk Elektronik Bilgisayarlar
- 3. Mainframe'ler
- 4. Kişisel Bilgisayarlar ve Mobil Cihazlar
- 5. Süper Bilgisayarlar, Paralel Hesaplama ve Sanallaştırma
- 6. Bilgisayar, Elektronik Cihaz ve Gömülü Sistem
- 7. Von Neumann Mimarisi ve İkili Sistem
- 8. Bilgisayar Organizasyonu: Donanım ve Yazılım
- 9. Donanım Birimleri ve Bellek Hiyerarşisi
- 10. Ana Bellek, ROM, BIOS ve İkincil Bellek
- 11. Veri Kapasite Birimleri
- 12. Analog ve Dijital Veri
- 13. Yazılım Katmanları
- 14. Programlama Dilleri
- 15. Derleyici ve Yorumlayıcı
- 16. Sayı Sistemlerine Giriş

## 1. Hesaplama Cihazlarından İlk Bilgisayarlara

Bilgisayar özünde bir hesaplama cihazıdır ve hesaplama cihazlarının temeli milattan önceye dayanır. Hepimizin ilkokulda saymayı öğrenirken kullandığı abaküs, hem sayıları temsil etmek hem de iki sayı arasında işlem yapmak için kullanılan bir yapıdır. Slayta göre bilinen en eski abaküs M.Ö. 300 yılında Babilliler tarafından kullanılmıştır (ekrandan, 00:10:00). Abaküs bugün hâlâ vardır, ama basit hesaplamalar için yola çıkan tasarımlar bugün çok farklı bir noktadadır.

Yaklaşık iki bin yıl boyunca birçok teorem ve buluş ortaya çıktı. Özellikle yoğun hesaplama ihtiyacı, örneğin logaritma tabloları gibi o dönem için çok zaman alan hesaplar, araştırmacıları bu işleri otomatikleştirecek tasarımlara yöneltti. Elektriğin henüz kullanılmadığı bu dönemde Charles Babbage tamamen mekanik, çarklardan ve millerden oluşan bir fark makinesi (Difference Engine) tasarladı. Bu fikirler geliştirilerek Analytical Engine'e dönüştü. Hocanın anlattığına göre bu makine bir ev büyüklüğündeydi, altı buhar makinesiyle besleniyordu, bilgiyi delikli kartlardan (punched card) alıyor ve işleyerek karmaşık matematiksel hesapları yapıyordu.

Analytical Engine'in iki ana görevi vardı:

- **Depolama:** Bilgileri saklama.
- **Hesaplama:** Saklanan bilgileri kullanarak hesap yapan çarklar.

Bu iki parça bugün bellek birimi (memory unit) ve merkezi işlem birimi (central processing unit, CPU) olarak karşımıza çıkar. Bir bilgisayar yalnız bu birimlerden oluşmaz, ama ilk mekanik tasarımda temel fikir buydu.

Bir donanım varsa onun üzerinde yapılacak işlerin de programlanması gerekir. Babbage'ın makinesi için bu işi yapan kişi Ada Byron'dır; makineye "hayat veren" bu kadın tarihe dünyanın ilk programcısı olarak geçmiştir.

> **Ders sonrası not:** Hoca bu fikirlerin "1700'lerin sonu, 1800'lerin başında" ortaya atılmaya başladığını söyledi. Babbage'ın Difference Engine tasarımı büyük olasılıkla 1820'lere, Analytical Engine tasarımı 1830'lara aittir; Analytical Engine onun döneminde tamamlanıp çalıştırılmamıştır. Ada Byron bugün daha çok Ada Lovelace adıyla bilinir.

## 2. İlk Elektronik Bilgisayarlar

Yaklaşık bir yüzyıl sonra elektriğin kullanımıyla birlikte 1900'lerin ortasında ilk elektronik bilgisayarlar ortaya çıktı. Slayttaki bilgiler (ekrandan, 00:15:00):

- Atanasoff ve Berry tarafından geliştirilen ABC computer ilk elektronik bilgisayardır (1939).
  - 1939: ilk prototip.
  - 1941: ilk üretim, Iowa State Üniversitesi fizik binasının bodrumu.
- İkincisi Newmann ve Flowers tarafından geliştirilen Colossus Mark I'dir (1943).

Hoca, bilgisayarın bir fizik binasında konumlandırılmasına dikkat çekti: O dönemde bilgisayar mühendisliği diye bir meslek yoktu. Bu cihazlar fizik ve matematikteki karmaşık hesapların insan gücüyle çok uzun sürmesi nedeniyle tasarlanıyordu.

Bu dönemde askeri ihtiyaçlar süreci hızlandırdı. Birçok teknoloji önce askeri alanda ortaya çıkıp sonra günlük hayata girmiştir. Hoca iki kullanım amacı saydı:

- **Şifreli mesajların çözülmesi:** Şifrelerin bir örüntüsü olduğu, belirli sayıda kombinasyon denenirse kırılabileceği görüldü. İnsanların günlerce uğraştığı bu işi kısa sürede yapmak savaşta avantaj sağlıyordu.
- **Atış hesapları:** Bir atışın hangi koordinata, ne hızla ve ne güçle yapılacağının hesabı normalde kâğıt üzerinde yapılıyordu; bunu hızlandırmak için bilgisayarlardan yararlanıldı.

Askeri amaçlı bu bilgisayarlardan edinilen tecrübe, bilgisayarların genel amaçlı işlerde de kullanılabileceğini gösterdi.

### 2.1 ENIAC: İlk Genel Amaçlı Bilgisayar

Slayttaki bilgiler (ekrandan, 00:20:00):

- 1946'da U. Penn.'de US Army için ENIAC.
- Electronic Numerical Integrator and Calculator.
- J. Presper Eckert (24 yaşında) ve John Mauchley.
- 30 ton ve 167 m².
- 500.000 dolar.
- Matematiksel hesaplar, hava tahmini ve atomik enerji hesapları.
- Veri girişi punched card'lar ile, programlama kabloları ve anahtarları elle değiştirerek.
- Decimal data ile çalışır.

Hoca, adından da anlaşılacağı gibi bu bilgisayarın temel işinin sayısal hesaplama olduğunu vurguladı. Bugün bilgisayarların belki en son işi hesap makinesi gibi çalışmaktır, ama algoritma tasarlarken de görüleceği gibi bütün güçlerini bu hesaplama yeteneğinden alırlar. 500.000 dolar satış fiyatı değil, üretim maliyetidir.

ENIAC'ı programlamak bugünkü gibi klavyeyle kod yazmak değildi. Bir işi yaptırmak için yüzlerce kablonun konumunu hesaplamak, kabloları bağlamak ve anahtarları elle ayarlamak gerekiyordu; ancak ondan sonra bilgisayar çalıştırılabiliyordu. Yanında bir operatör masası vardı ve örneğin bir fizik denklemini çözerken bilgisayarın uzun süre çalışması beklenirdi.

Bugünle en büyük fark şudur: Bugün bir bilgisayarı aynı anda birçok kişi kullanabilir. O yıllarda ise geniş bir alanı kaplayan bu bilgisayar aynı anda yalnız bir program çalıştırabiliyordu. İşler sıraya giriyor, bir iş bitince diğeri için kablolar yeniden yerleştiriliyordu. Buna rağmen karmaşık hesapları insan gücü yerine bu şekilde yapmak büyük bir avantajdı.

> **Ders sonrası not:** Hoca ve slayt ENIAC'ın açılımını "Electronic Numerical Integrator and Calculator" diye verdi; yaygın kabul edilen açılım büyük olasılıkla "Electronic Numerical Integrator and Computer"dır. Hoca alanı yaklaşık 170 m² dedi; slaytta 167 m² yazıyor. İkinci isim büyük olasılıkla "Mauchly" diye yazılır.

## 3. Mainframe'ler

Slayttaki bilgiler (ekrandan, 00:25:00):

- 1950'lerin sonları ile 1970'ler arasında çeşitli üreticiler tarafından üretilmiştir.
- IBM firmasının pazardaki etkinliği önce 700/7000 serisi, sonra 360 serisi cihazları üretmesiyle artmıştır.
- 1970'lerin başında piyasadaki küçülme şirket sayısını azaltmıştır.
- 1980'lerde mini bilgisayarlar etkin olmaya başlamıştır.
- 2012'de NASA son mainframe bilgisayarını kapatmıştır.
- IBM hâlâ mainframe üretimine devam etmektedir. Son sürüm: IBM z15 Mainframe.

Mainframe "ana sunucu" anlamına gelir, ama boyut olarak bugün Amazon ya da Google'ın sunucu odalarında rack'lere yerleştirilmiş sunuculardan farklıdır. Mainframe'ler saniyede trilyonlarca işlem yapabilen, normal bir kişisel bilgisayardan ya da sunucudan çok daha yüksek işlem (transaction) kapasitesine sahip cihazlardır. Öncüsü IBM'dir. Özellikle bankacılık ve finans gibi müşteri ve işlem sayısının çok olduğu alanlarda kullanılırlar. Hoca, bölümde de mainframe'lerin uzun yıllar web sunucusu, e-posta sunucusu ve öğrenci projelerini çalıştırmak için kullanıldığını anlattı.

Mainframe'lerin öne çıkan özellikleri:

- **Hot swap:** Sistem çalışırken bir modül, birim ya da disk takılıp çıkarılabilir.
- **Yüksek güvenlik standartları.**
- **Çok düşük hata riski.**
- **Milyonlarca iş ve kullanıcıyı aynı anda çalıştırabilme.**

Bu bilgisayarlar kapladıkları yer, maliyetleri, ürettikleri ısı ve boyutları nedeniyle kişiselleştirilebilir değildi. Slayttaki iki görsel bu değişimi gösterir (ekrandan, 00:30:00): Solda IBM 7094 mainframe'i, teyplerin, yazıcıların ve operatör konsollarının bulunduğu, klimalı geniş bir oda kaplar. Sağda IBM z13, bir rack kabinine yerleşmiştir: çıkarılabilir diskler, giriş-çıkış birimleri, işlemci, bellek bölümü, ağ kartları, soğutucu ve güç ünitesi raflara dizilmiştir. Hoca bunların eskiye göre 3-4 kat küçüldüğünü söyledi. Mainframe'in anlatılma nedeni, çok fazla kullanıcıya hizmet veren ve yoğun işlem gerektiren bir sistem kurulacaksa hâlâ bir seçenek olması ve bilgisayar tarihinin önemli bir yapı taşı olmasıdır.

Hoca burada bir hatırlatma yaptı: Bugün kullanıcı neredeyse yalnız ekran, fare ve klavye görür; kasa bile çoğu zaman ortada değildir. Ama bir masaüstü bilgisayarı açtığınızda ana kartın, slotların, bunlara takılabilecek parçaların ne olduğunu bilmek bir bilgisayar mühendisinden beklenir.

> **Hocanın vurgusu:** Bilgisayarı yalnız yazılım olarak kullanmak bilgisayar mühendisliğinin bakış açısını yansıtmaz; o zaman yazılım mühendisinden ya da programcıdan farkınız kalmaz. Dizüstü de olsa masaüstü de olsa donanımsal elektronik tasarım konusunda bilgi sahibi olmak çok önemlidir.

Mainframe'ler ve bugünkü sunucu odaları özel olarak klimalı tasarlanır, çünkü yoğun işlem yapan bu bilgisayarlar çok ısı üretir.

## 4. Kişisel Bilgisayarlar ve Mobil Cihazlar

1965'te Olivetti'nin ürettiği Programma 101 (P101) aslında gelişmiş bir masaüstü hesap makinesidir; bu yüzden tam bir kişisel bilgisayar sayılıp sayılamayacağı tartışılır. Önemi, üzerinde program saklayabilmesidir (stored program computer). Bugün de bazı hesap makinelerine program yazılıp saklanabilir ve sonra çalıştırılabilir. Programma 101, boyutu ve kişisel bir cihaz olması bakımından program saklayabilen ilk yapılardan biri olarak tarihte bir kilometre taşıdır.

1976'da Wozniak ve Jobs Apple'ın ilk adımlarını attı. Wozniak işe garajda bir hobi olarak başladı; Jobs "neden satmayalım" fikriyle geldi ve Apple I 666 dolarlık fiyatla kişisel bilgisayar olarak piyasaya çıktı. Bir klavyeyle girdi alan ve çıktıyı ekrandan veren çok basit bir yapıydı.

1980'lerde Commodore ve Amstrad gibi markalar klavye ve joystick ile özellikle oyun ve basit programlama amaçlı bilgisayarları yaygınlaştırdı. 1990'larda bilgisayarların birbirleriyle haberleşme yeteneği arttı; internetin ortaya çıkması ve modemle haberleşme kişisel bilgisayarları hızla masalara taşıdı. Kasa içinde ana kart, ekran kartı, işlemci, bellek ve sabit disk bulunan masaüstü PC'ler yaygınlaştı. 1990'ların sonunda radyo frekansıyla haberleşmenin girmesiyle mobilite kavramı gelişti; 2000'lerden sonra telefonların yetenekleri arttı, ardından dizüstü bilgisayarlar, tabletler ve giyilebilir cihazlar geldi.

Hoca kapasitedeki büyümeyi bir örnekle anlattı: O dönemde 6 GB'lık bir sabit disk korkunç büyük bir alan gibi görünürken bugün 6 GB RAM bile az sayılıyor. Bugün bir telefon, hatta bir saat, 1990'ların bilgisayarından çok daha fazla bellek ve işlem gücü sunabiliyor; bu birimler neredeyse her iki yılda bir katlanıyor.

## 5. Süper Bilgisayarlar, Paralel Hesaplama ve Sanallaştırma

Slayttaki tanım (ekrandan, 00:35:00):

- Karmaşık problemlerin birden fazla makine üzerinde eş zamanlı olarak (paralel) çözülmesini sağlayan bilgisayar kümeleri.
- Virtualization (sanallaştırma) ve parallel computing (paralel hesaplama).

Kişisel bilgisayarların yaygınlaşmasıyla paralel olarak süper bilgisayarlar gelişti. Hoca, ilk duyduğumuz süper bilgisayarlardan birinin satranç ustası Kasparov'la yapılan maçlardan tanındığını hatırlattı. Süper bilgisayarların en önemli yeteneği saniyede trilyonlarca işlem yapabilmeleridir. 8x8'lik bir satranç tahtasında taşların bütün hareket kombinasyonlarını, karşı tarafın olası hamlelerini ve sonraki hamleleri hesaplayarak insan beyninin bu kadar kısa sürede yapamayacağı bir öngörü yapabilirler. Kişisel bilgisayarla günler sürecek işler süper bilgisayarda saatler ya da dakikalar içinde yapılabilir. Bugün şifre kırmadan büyük asal sayıların hesaplanmasına, hava tahmininden denklem çözümüne ve fizik çalışmalarına kadar birçok alanda kullanılırlar.

> **Ek bilgi (derste anlatılmadı):** Kasparov'u 1997'deki maçta yenen bilgisayar büyük olasılıkla IBM'in Deep Blue adlı sistemidir. Slayttaki görselde IBM'in "Summit" süper bilgisayarı görünmektedir.

Ancak bilgisayarları fiziksel olarak yan yana koymak, kasa sayısını artırmak yer, ısı ve maliyet açısından sorun yarattı. İşlemciler saniyede milyonlarca, milyarlarca saykıl (cycle) üretebilir ve her saykılda bir komut çalışabilir. Fakat bakıldığında işlemcinin çoğu zaman en fazla yüzde 10, bazen yüzde 5 kullanıldığı görüldü. Buradan şu fikir doğdu: Bilgisayarları yan yana dizmek yerine aynı fiziksel bilgisayarı yazılım aracılığıyla farklı işler için tamamen farklı sunucular gibi kullanabilir miyiz? Bu fikir sanallaştırmayı (virtualization) doğurdu. Fiziksel cihaz almak yerine sanallaştırma programlarıyla bir fiziksel bilgisayar üzerinde, kapasitesine bağlı olarak birden çok sanal bilgisayar kurulup kullanılabilir. Bu, kaynakların daha verimli kullanılmasını, daha az ısı ve daha az elektronik atık üretilmesini sağlar.

Hoca elektronik atığın hâlâ büyük bir sorun olduğunu da ekledi: Telefonlar ve cihazlar çok sık değişiyor, yeni özellikler insanları yeni cihaz almaya yöneltiyor ve eskilerin önemli bir kısmı çöpe gidiyor ya da bir köşede kalıyor.

## 6. Bilgisayar, Elektronik Cihaz ve Gömülü Sistem

Bilgisayar bir elektronik cihazdır. Akıllı telefonlar, tabletler, dizüstü bilgisayarlar, sunucular, oyun konsolları, akıllı saatler, televizyonlar, hatta çamaşır ve bulaşık makineleri gibi elektronik aksamı olan her cihaz elektronik cihazdır. Bunların çoğu gömülü sistem olarak adlandırılır:

- **Gömülü sistem:** Belirli, spesifik görevleri yapmak üzere tasarlanmış elektronik cihaz.
- **Bilgisayar:** Çok sayıda farklı işi yapabilme yeteneğine sahip elektronik cihaz.

Telefon hayatımıza taşınabilir bir gömülü sistem olarak girdi, ama bugün akıllı telefonlar bir bilgisayara yakın iş yapma kapasitesine ulaştı. Bilgisayarın görevini tamamen yerine getiremese de fener, video ve ses kaydedici, fotoğraf makinesi, ölçüm cihazı gibi günlük hayatta gereken birçok cihazın yerini alıyor.

## 7. Von Neumann Mimarisi ve İkili Sistem

Bir elektronik cihazdan, bir bilgisayardan söz ediyorsak, bunun dayandığı temel bir mimari vardır: von Neumann mimarisi. Slayttaki maddeler (ekrandan, 00:45:00):

- Günümüz bilgisayar mimarisinin temeli.
- Program ve data tarafından paylaşılan tek bellek.
- Giriş/çıkış, bellek ve aritmetik birim merkezi işlem birimi tarafından idare edilir.
- İkili (binary) veri ile çalışır.

Slayttaki şemanın metin hâli:

```text
Input Device  --->  [ Central Processing Unit           ]  --->  Output Device
                    [   Control Unit                    ]
                    [   Arithmetic/Logic Unit           ]
                              |   ^
                              v   |
                    [ Memory Unit                       ]
```

Bu mimariye göre bir bilgisayarın:

- Girdi alabileceği bir birimi (input device),
- Ürettiği sonucu gösterebileceği bir çıkış birimi (output device),
- Bilgileri saklayabileceği bir bellek alanı (memory unit),
- Bu bilgileri işleyebileceği bir merkezi işlem birimi (CPU)

olmalıdır. CPU içinde iki birim vardır:

- **Aritmetik ve lojik birim (ALU):** Veriler üzerindeki temel matematiksel ve mantıksal işlemleri yapar. Hoca bunu, dünyadaki teknolojilerin altyapısını oluşturan hesaplama yeteneğinin kaynağı olarak tanımladı.
- **Kontrol birimi (Control Unit):** Hangi komutun hangi sırayla çalıştırılacağını yönetir, birimlere sinyal ve komut gönderir, diğer birimlerle bilgi alışverişini koordine eder.

> **Hocanın vurgusu:** Bugünkü mimarilerin çoğu bu temel mimarinin üzerine kurulmuştur. Mimari çok değişmemiş, ama çok gelişmiş ve yeni birimler eklenmiştir. Bu temel yapılardan biri eksik olursa diğer bütün parçalar olsa bile bir bilgisayarın çalışma ihtimali ortadan kalkar.

Bilgisayarlar bilgiyi saklarken 0 ve 1 kullanır. Bunun temel nedeni elektriğin var ya da yok olmasıdır: Bir sinyalde elektriğin varlığı 1'i, yokluğu 0'ı temsil eder. Bu, örneğin 0 V ve 5 V, 0 V ve 3,3 V ya da 0 V ve 12 V olarak düşünülebilir; ayrıntısı donanım derslerinde görülecektir. Bilgisayarlar resim, video, metin, sayı, harf, komut ve programların hepsini saklamak ve kendi birimleri arasında haberleşmek için ikili sayı sistemini kullanır. İnsanın anlayabileceği dilde bu 0 ve 1'dir; fiziksel düzeyde ise haberleşme elektriksel iletimle olur.

## 8. Bilgisayar Organizasyonu: Donanım ve Yazılım

Bazı üniversitelerde bu konu Computer Organization, Computer Architecture ya da bilgisayar donanımı gibi derslerde işlenir. Bilgisayar organizasyonu denince iki başlık öne çıkar (ekrandan, 00:50:00):

- **Donanım:** Bilgisayarın fiziksel bölümü; monitör, klavye, fare, entegreler, kartlar, kablolar.
- **Yazılım:** Bilgisayarın mantıksal bölümü; programlar, yani bilgisayarın gerçekleştireceği komutlar.

Donanım ve yazılım birbirinden ayrılamaz. Donanım olmazsa yazılımın hiçbir anlamı yoktur. Yazılım olmazsa donanım tek başına bazı temel işler için kullanılabilir, ama geliştirilecek yazılımlar sayesinde donanımdan çok daha fazlası elde edilir. Hoca bir bilgisayar mühendisinin hem donanımda hem yazılımda kendini geliştirmesinin sektörde fark yaratacağını söyledi.

### 8.1 Giriş-Çıkış Birimleri ve İnsan-Bilgisayar Etkileşimi

Bilgisayarda işlemci, ana (birincil) bellek ve elektrik yokken de veriyi saklayan ikincil bellek bulunur. Bunlara ek olarak çevre birimleri (I/O, input/output) vardır:

- **Giriş birimleri:** Klavye, fare, mikrofon, tarayıcı.
- **Çıkış birimleri:** Monitör, hoparlör, yazıcı.

Giriş-çıkış birimleri insanların bilgisayarla haberleşmesini sağlar. Bu konu bugün insan-bilgisayar etkileşimi (Human-Computer Interaction) adlı, giderek derinleşen özel bir alandır. Dokunmatik ekranlar ve sanal klavyeler, mikrofonla verilen sesli komutlar, hoparlörden gelen sesli bilgi, telefon üzerindeki ışıklar ve telefon çalarken titreşim de birer giriş ya da çıkış yoludur.

Bu birimlerin birleştiği yer ana karttır. Ana kartın üzerindeki slotlara ekran kartı ve ses kartı takılabilir. Bazı bileşenler System on Chip (SoC) denilen yapılarla ana karta entegre olarak gelir; bazıları, örneğin oyunları daha kaliteli oynamayı sağlayan GPU'lar, ayrı kart olarak eklenebilir. Bu birimler paralel ya da seri haberleşen bağlantılar üzerinden birbirine bağlanır.

## 9. Donanım Birimleri ve Bellek Hiyerarşisi

Slayttaki donanım birimleri (ekrandan, 01:10:00):

- Merkezi İşlem Birimi (Central Processing Unit)
- Ana Bellek (Main Memory)
- İkincil Bellek (Secondary Storage)
- Giriş Birimleri (Input Devices)
- Çıkış Birimleri (Output Devices)

Merkezi işlem birimi bilgisayarın beynidir; bütün hesaplamalar orada yapılır. İki parçadan oluşur: Kontrol birimi işlem akışını kontrol eder ve komutların yerine getirilmesinden sorumludur. Aritmetik lojik birim ise komutta yapılacak işe göre toplama, çıkarma, çarpma, bölme yapar; bir karar verme (karşılaştırma) söz konusuysa o da burada yapılır.

### 9.1 Register, Cache ve Ana Bellek

İşlemciye en yakın bellek birimi register'dır. Bir işlemcide duruma göre 8, 16 gibi onlar mertebesinde register bulunur. İki sayı toplanacaksa sayılar bellekten register'lara getirilir, işlem yapılacak birime gönderilir, işlem yapılır, sonuç yine register'a yazılır, sonra bazen cache'e, bazen ana belleğe gönderilerek olması gereken yere konur.

İşlemcide ikinci yakın birim ön bellek (cache) bölgesidir.

> **Hocanın vurgusu:** Yazılışa dikkat edin: Bildiğiniz "cash" (C, A, S, H) değil, "cache" diye yazılır. Bu, ön bellektir.

Cache kademelidir (birinci, ikinci, üçüncü seviye; L1, L2, L3) ve işlemciden işlemciye farklı boyutlardadır. İşlemci işlerini çok hızlı yapar, ama ana bellekten bilginin gelmesini beklemek zorunda kalır. Bu yüzden araya bir, hatta birkaç ara katman konmuştur.

Cache'in arkasından ana bellek gelir: DDR RAM, SDRAM gibi. Bunlar rastgele erişimli bellektir, yani istenen adrese doğrudan gidilerek erişilebilir ve elektrik olduğu sürece bilgiyi saklar. İşletim sistemi dahil bütün programlar bilgisayar açıldığında bu bölgeye yüklenir ve buradan çalıştırılır.

### 9.2 Bellek Piramidi

Slayttaki piramit (ekrandan, 01:15:00):

| Katman | Örnekler |
|---|---|
| Inboard Memory (tepe) | Registers, Cache, Main Memory |
| Outboard Storage (orta) | Magnetic Disk, CD-ROM, CD-RW, DVD+RW, DVD-RAM |
| Off-line Storage (taban) | Magnetic Tape, MO, WORM |

Piramidin solundaki ok yukarı doğru "Maliyet-Hız", sağdaki ok aşağı doğru "Kapasite" diye işaretlidir. Yukarı çıktıkça belleğe erişim hızı artar, ama bu maliyete yansır. Kapasite ise ters yönde değişir: Register kapasitesi en düşüktür, cache megabaytlar, ana bellek gigabaytlar, sabit diskler terabaytlar mertebesindedir. Off-line storage tamamen bilgisayardan bağımsız parçaları ifade eder.

Manyetik teyp (tape), arşivlenecek bilginin hızlıca yazıldığı ama tekrar erişilmek istendiğinde çok uzun sürede geri döndüğü bir ortamdır; bilgi şeritlere yazılır. Eski kasetleri bilenler bunu hatırlar: Eskiden müzik dijital değildi, manyetik teyplere kaydedilirdi. Bazı bankalar uzun vadeli bilgilerini hâlâ bu şekilde saklamayı tercih edebiliyor, ama günümüzde kullanımı azalıyor.

## 10. Ana Bellek, ROM, BIOS ve İkincil Bellek

### 10.1 Ana Bellek (RAM)

Slayttaki maddeler (ekrandan, 01:20:00):

- Rastgele Erişimli Bellek (Random Access Memory)
- Her biri 1 byte'lık hücrelerden oluşur.
- Her bellek hücresinin adresi vardır.
- Bu adreslerde veri veya komut saklanır.
- Saklanan bilgiler 0 ve 1'lerden oluşur.

Bilgisayar dünyasında ifade edilebilecek en küçük birim, binary digit'in kısaltması olan bittir. Bir bit ya 0 ya 1 saklar. 8 bit bir byte'ı oluşturur. Bellekte saklanabilecek en küçük birim ise bir byte'tır: Her adreslenebilir hücrede 8 bitlik bir byte saklanır ve adres bilgisi yazılarak istenen hücreye doğrudan erişilir. Bu hücrelerde hem veri hem de çalıştırılacak programların komutları saklanır; işlemci işleyişin nasıl olacağını bellekteki bu bilgileri okuyarak belirler. Ana bellek, bilgisayar kapatıldığında üzerindeki bütün bilgileri kaybeder.

İşletim sistemi normalde ikincil bellekte saklanır. Bilgisayar ilk çalıştığında ikincil bellekten birincil belleğe aktarılır ve bilgisayar çalıştığı sürece RAM'de işletim sisteminin işlerini koordine eden bilgiler yer alır.

### 10.2 ROM ve BIOS

Peki işletim sisteminin ikincil bellekten birincil belleğe yerleşmesini sağlayan, bilgisayarı başlatan küçük program nerededir? ROM (read-only memory) üzerindedir. Hangi komutun nereden çalıştırılacağı ve işletim sisteminin hangi bölgede olduğu bilgisi ROM'da yazılıdır. Bilgisayar her açılışta oradaki başlangıç işlerini okur ve bu yüzden hep aynı şekilde açılır.

BIOS (Basic Input Output System), donanımın bir işletim sistemi olmadan en temel düzeyde yapılandırılabildiği basit bir arayüz sunar. Örneğin bilgisayarın nereden boot edileceği (CD-ROM, flash bellek, harici disk, bilgisayardaki sabit disk ya da ağ) buradan değiştirilebilir.

Slayttaki bellek birimleri (ekrandan, 01:30:00):

- RAM (Random Access Memory): rastgele erişim mümkün, okuma/yazma yapılabilir.
- ROM (Read Only Memory): rastgele erişim mümkün, sadece okuma yapılabilir, genel olarak ana kartta bilgisayar ilk açıldığında gerekli komutları saklar.

ROM ağırlıklı olarak yalnız okunabilen bir bellektir, ama EPROM ve EEPROM gibi silinebilir (erasable), belli sayıda yeniden yazılabilen türevleri vardır. Bu, bir tür firmware gibi düşünülebilir: Bazı cihazların donanımsal yeteneği vardır ama yazılımsal olarak o yetenek yoktur; sonradan firmware güncellemesiyle eklenir. Örneğin bir televizyona gelen güncelleme, donanımın başka özelliklerinin kullanılmasını sağlayabilir.

**Soru:** BIOS'un ROM ile bir bağlantısı var mı?
**Cevap:** Evet. Bilgisayarın donanımsal ayarlarını, ikincil bellek takılı değilken bile yapabilmek için BIOS ayarlarının bellekten bağımsız bir yerde tutulması gerekir. Bunun için ROM ve EPROM kullanılan kaynaklardan biridir.

### 10.3 İkincil Bellek

İkincil bellek (secondary storage) bilgiyi elektrik olmadığında da saklar. Örnekler:

- Sabit disk (hard disk drive, HDD)
- CD ve DVD gibi optik ortamlar (yazılabilir ve yalnız okunabilir türleriyle)
- Flash bellekler, USB bellekler, SD kartlar
- Katı hal sürücüleri (solid state drive, SSD)
- Harici diskler (external drive)
- Uzun süreli saklama için teypler

HDD'de mekanik bir aksam vardır: Bir kol disk plakaları üzerinde ilgili veriye eriştiği için dönme ve kol hareketi gerekir. "Solid state" hareketli parça olmadığını ifade eder; SSD'de böyle bir harekete gerek yoktur, veri elektriksel olarak saklanır. HDD hâlâ daha ucuz ve kapasitesi daha yüksektir; SSD daha pahalı ve görece düşük kapasitelidir. Veri taşımada CD ve DVD'nin yerini büyük ölçüde flash bellekler ve harici diskler almıştır. Disket (floppy) sürücüler tarihe karışmış, optik sürücüler de yavaş yavaş kayboluyor.

> **Ders sonrası not:** Hoca bir yerde "Hard Disk Drive dediğimiz manyetik tape'ler" dedi. HDD manyetik disktir; manyetik teyp ise bellek piramidinin tabanındaki ayrı, sıralı erişimli bir arşiv ortamıdır.

İkincil bellekteki bilgiler kalıcıdır ve erişim rastgele ya da sıralı olabilir:

- **Rastgele erişim (random access):** İstenen bilgiye doğrudan ulaşılır. 100. adrese doğrudan gidilebilir.
- **Sıralı erişim (sequential access):** Bir bilgiye ulaşmak için önce diğer bilgilerden geçmek, onları okumak gerekir. 100. adrese ulaşmak için önce 99 adresin geçilmesi gerekebilir.

Hoca SSD'lerin belirli bir yazma kapasitesi olduğunun konuşulduğunu da ekledi: Bir adres yaklaşık 10.000 ile 100.000 kez yazılıp silindikten sonra oradaki bilginin iyi koşullarda saklanamayabileceği söyleniyor. Ancak günlük kullanımda bir adrese bu kadar çok yazmak sık rastlanan bir durum değildir; çoğunlukla veri yazılır ve daha çok okunur.

**Soru:** RAM'in DDR3 ya da DDR4 olması neyi etkiler?
**Cevap:** RAM teknolojisi sürekli değişiyor ve bunların bir veri yolu (bus) hızı vardır. DDR3 ile DDR4 arasında belleğe erişim hızları farklıdır; bu, bir veri işlemci tarafından istendiğinde bellekten işlemciye ne kadar sürede geleceğini kabaca belirler. Ayrıca bellek modüllerinin yapısını ve kullanım şeklini değiştiren tasarımlar da vardır; amaç bilgiyi mümkün olduğunca birlikte saklamak ve hızlı erişilebilir kılmaktır. Hoca iki nesil arasındaki ayrıntılı farkları ezbere bilmediğini, araştırılabileceğini söyledi.

> **Ders sonrası not:** Hoca güncel modüller için "2933 MHz, yaklaşık 1,9 GHz" dedi. DDR4-2933 gibi adlardaki sayı büyük olasılıkla saniyedeki veri aktarımı (MT/s) değeridir; DDR (Double Data Rate) saatin her iki kenarında veri aktardığı için gerçek saat frekansı bu değerin yaklaşık yarısıdır (yaklaşık 1466 MHz).

**Soru (öğrencinin yorumu):** C gibi bazı programlama dilleri RAM'deki adreslere ve oradaki bilgilere pointer'larla doğrudan erişmeye izin verir.
**Cevap:** Hoca bunun doğru olduğunu onayladı.

## 11. Veri Kapasite Birimleri

Bilgisayar dünyasında ikili sayı sistemi kullanıldığı için hesaplar genellikle ikinin kuvvetleri üzerinden yapılır:

$$2^{10}\ \text{byte} = 1024\ \text{byte} = 1\ \text{KB}$$
$$2^{20}\ \text{byte} = 1024\ \text{KB} = 1\ \text{MB}$$
$$2^{30}\ \text{byte} = 1\ \text{GB}, \qquad 2^{40}\ \text{byte} = 1\ \text{TB}$$

> **Hocanın vurgusu:** Burası önemli: 1 KB, 1000 byte değil 1024 byte'tır, çünkü hesap $2^{10}$ üzerinden yapılır.

Slayttaki tablo (ekrandan, 01:25:00):

| Unit | Value | Example |
|---|---|---|
| Kilobytes (KB) | 1,000 bytes | a paragraph of a text document |
| Megabytes (MB) | 1,000 Kilobytes | a small novel |
| Gigabytes (GB) | 1,000 Megabytes | Beethoven's 5th Symphony |
| Terabytes (TB) | 1,000 Gigabytes | all the X-rays in a large hospital |
| Petabytes (PB) | 1,000 Terabytes | half the contents of all US academic research libraries |
| Exabytes (EB) | 1,000 Petabytes | about one fifth of the words people have ever spoken |
| Zettabytes (ZB) | 1,000 Exabytes | as much information as there are grains of sand on all the world's beaches |
| Yottabytes (YB) | 1,000 Zettabytes | as much information as there are atoms in 7,000 human bodies |

Hoca tablodaki "Value" sütununda yazan binlerin doğru olmadığını, bunların 1024 olması gerektiğini söyleyerek düzeltti. Petabayttan sonra exabayt, zettabayt ve yottabayt gelir; hoca bunların ötesinde de adı belirlenmiş birimler olduğunu söyledi. Bir zettabaytı dünyadaki bütün kumsallardaki kum tanesi sayısıyla, bir yottabaytı 7000 insanın vücudundaki atom sayısıyla karşılaştıran örnekler kesin değerler değildir, ama büyüklüğü canlandırmak için kullanılır. Bugün evlerdeki disklerin bile terabaytlar mertebesinde olması, petabaytların rahatça konuşulmasını sağlıyor. Bunun en önemli nedenlerinden biri resim, video ve içerik çözünürlüğünün çok artmasıdır.

> **Ek bilgi (derste anlatılmadı):** Karışıklığı önlemek için IEC standardı ikinin kuvvetlerine ayrı adlar verir: 1 KiB (kibibyte) = 1024 byte, 1 MiB = $2^{20}$ byte. Bu standartta "kB" ise 1000 byte'tır. Disk üreticileri kapasiteyi çoğunlukla onluk (1000'lik) birimlerle verir.

## 12. Analog ve Dijital Veri

Bugün dijital dönüşüm çok önemli bir kavramdır. Hoca analog ile dijital arasındaki farkı kısaca anlattı:

- **Analog veri** fiziksel bir ortamda saklanır. Eskiden şarkılar teyplerde çalınır, kasetlerin şeritlerine kodlanırdı. 100 kaset üretmek için 100 parça malzeme gerekir; analog verinin bir kopyasını üretmek kolay değildir ve fiziksel alan kaplar.
- **Dijital veri** sayısal olarak kodlanır. Elektriğin sağladığı imkânla çok hızlı çoğaltılabilir, dağıtılabilir, değiştirilebilir ve paylaşılabilir. 100 kaset ile 100 şarkıyı saklamak arasında büyük bir fiziksel alan farkı vardır. Kamu kurumları da dijital dönüşümle belgeleri ikincil belleklerde saklıyor; milyonlarca klasör küçücük bir diske sığıyor.

Hoca bunu ders ortamıyla da örneklendirdi: Sınıfta konuşurken ses, ağızdan ve boğazdan çıkan titreşimlerin hava parçacıklarıyla aktarılmasıyla analog olarak iletilir. Çevrim içi derste ise ses ve görüntü bilgisayara analog olarak girer, bilgisayar bunu dijitale çevirir ve karşıya dijital olarak ulaşır. Bunun gecikme ya da kalite sorunu gibi dezavantajları olabilir, mimikleri yakalamak zorlaşabilir. Avantajı ise kaydın tekrar izlenebilmesidir; analog bir bilgiyi saklamak için eskiden ek kasetler gerekirdi.

Bugün kameralar insan gözünün gördüğü görüntü kalitesini büyük ölçüde yakalamıştır, ama her pikselin renk derinliği bir saklama maliyeti getirir ve bu da yukarıda söz edilen büyük veri boyutlarına yol açar.

## 13. Yazılım Katmanları

Yazılım denince ilk akla gelen işletim sistemidir. İşletim sistemi kaynakların yönetimini sağlayan, en üstte yer alan temel sistem yazılımıdır. Bilgisayar karmaşık işleri koordineli bir şekilde yapabiliyorsa bu işletim sistemi sayesindedir. Görevleri:

- İşlemlerin (proseslerin) yönetimi
- Bellek yönetimi
- Dosya organizasyonunun yönetimi
- Giriş-çıkış cihazlarıyla veri alışverişinin yönetimi
- Ağ yönetimi: diğer ağlara gönderilen ve oradan gelen bilgilerin yönetimi

Yazılımlar temelde iki başlık altında incelenir: sistem yazılımları ve uygulama yazılımları (application software). Program, bilgisayarın gerçekleştireceği komutları içeren ve kodlardan oluşan bir yapıdır. Çok farklı diller vardır, ama bilgisayarla anlaşabilmek için nihai program 0 ve 1'lerden oluşan makine diline dönüşmelidir.

Slayttaki katmanlı şemanın metin hâli (ekrandan, 01:35:00):

```text
User
Computersystem
  Application Software : games | education SW | library system | ...
  System Software      : compiler | editors | interpreter | databases | ...
                         Operating System
                           process-scheduling | memory-management |
                           file-management | device-drivers | ...
  Hardware             : machine language
                         micro programming
                         physical devices
```

En alt katmanda fiziksel cihazlar vardır ve bunlar sürücülerle (driver) yönetilir. Eskiden bilgisayara yeni bir kart takıldığında sürücüsünün bulunması ve güncellenmesi daha çok sorun olurdu; bugün işletim sistemleri bunu çoğunlukla arka planda kendisi yapıyor. Donanım düzeyinde fiziksel cihazlarla haberleşmenin yolu makine dilidir, yani 0 ve 1'lerin kombinasyonları. Donanımın üstünde iki katmandan oluşan sistem yazılımları vardır: işletim sistemi (dosya, işlem ve bellek yönetimi) ve onun üzerinde derleyici, editör, yorumlayıcı, veritabanı gibi yazılımlar. En üstte, işletim sisteminin üzerine kurulan ve kullanıcıların yüklediği uygulama yazılımları bulunur: müzik ve video oynatıcılar, web tarayıcıları, oyunlar gibi kişisel kullanıma yönelik bütün yazılımlar.

## 14. Programlama Dilleri

### 14.1 Makine Dili

Yazılım üretmek için program yazmak gerekir ve programın makine tarafından anlaşılabilmesi için temel bir dil olmalıdır: makine kodu (machine code). Bilgisayar mimarileri birbirinden farklı olsa da hepsi yapacakları işi 0 ve 1'lerle anlar ve ürettikleri sonucu 0 ve 1'lerle paylaşır; üst katmanlar bunu insanların anlayacağı biçime çevirir. 0 ve 1'lerin bir kombinasyonu toplamayı, bir başkası çarpmayı, bir başkası bir sayıyı ya da bir rengi ifade eder; renkler bir araya gelince resmi ifade eder. Bu kuralları öğrenerek bilgisayara yaptırmak istediğimiz işleri kodlarız. Bunun için önce bilgisayarın hangi işlemleri yapabildiğini, işlemcinin hangi komut setini kullandığını bilmek ve bu komut setine uygun dillerle program yazmak gerekir.

Makine dilinde bir dizi 1 ve 0'ın iki sayıyı toplamak için yazıldığını anlamak çok zordur; en küçük bir değer değişse başka bir bilgi ifade edilir. Bu yüzden makine dilini doğrudan kullanmak verimli değildir. Hoca ENIAC'taki kablo programlamasını hatırlattı: Bütün kabloların girdiği ve çıktığı bölgelerin ne işe yaradığını bilmek ve kombinasyonu doğru yapmak çok zaman alıyordu. Buradan, bu kombinasyonlara karşılık gelen, insanın daha iyi anlayıp anlatabileceği bir üst seviye dil üretme fikri doğdu.

### 14.2 Assembly Dilleri

Slayttaki maddeler (ekrandan, 01:40:00):

- Bilgisayar sadece makine kodunu anlar.
- Assembly program, makine koduna (object code) çevrilmeli.
- Çevirme işlemini assembler yapar.

```text
asm  --->  [ assembler ]  --->  obj
```

"Assembly dilleri" diye çoğul söylenmesinin nedeni, her işlemci mimarisinin farklı bir komut seti kullanmasıdır. Bilgisayarlar aşağı yukarı benzer işler yapar, ama bunun için kullandıkları komutlar farklıdır. Bir bilgisayara iş yaptırmak için o bilgisayarın işlemcisinin komut setine uygun assembly diliyle yazmak gerekir.

Örneğin iki sayıyı toplamak için

```text
add ax, bx
```

yazıldığında şu söylenmiş olur: ax register'ındaki sayıyı al, bx register'ındaki sayıyı al ve topla. Arka planda bu komut, o işlemci mimarisinde hangi 0-1 dizisine karşılık geliyorsa assembler bu sözel ifadeyi o object code'a, yani makine koduna dönüştürür.

Assembly alçak seviyeli bir programlama dilidir ve ileride ayrı bir derste işlenecektir. O derste işlemci mimarisi ve temel olarak iki tip mimari öğrenilecektir: RISC (Reduced Instruction Set Computer) ve CISC (Complex Instruction Set Computer). Assembly ile yazmak kolay değildir: Bir sıralama için bile 15-20 satır kod gerekir, oysa birçok dilde bir diziyi `sort` diyerek sıralamak mümkündür. Makine seviyesine çok yakın olduğu, uzun kod gerektirdiği ve bilen sayısı az olduğu için performans kaygısı olmadıkça kullanılmaktan kaçınılır.

### 14.3 Yüksek Seviyeli Diller

Sonra Fortran, Pascal, C, Java gibi yüksek seviyeli diller ortaya çıktı. Hocanın anlattıkları:

- **C:** Unix işletim sistemi C ile yazıldı. Sistem yazılımı yazılabilen, bilgisayarın kaynaklarını yönetebilen, pointer gibi güçlü bellek yönetimi araçları sunan, sistem seviyesine en yakın dillerden biridir; aynı zamanda insanlar tarafından rahat anlaşılır. Bu yüzden birçok kaynakta orta seviyeli dil olarak geçer. Bugün gömülü sistemlerde ve performans gerektiren işlerde yoğun olarak kullanılır. Çok eski olmasına rağmen popülerliğini koruyan ve üzerine başka diller geliştirilen özel bir dildir.
- **Java:** Nesneye dayalı bir programlama dilidir.
- **COBOL:** 1950'lerde kullanıldı; bazı bankalarda hâlâ var, ama yoğun kullanılmıyor.
- **FORTRAN:** Özellikle bilimsel, fiziksel ve matematiksel işlerde uzun yıllar kullanıldı; bugün çok yaygın değil.
- **Pascal:** Kuralları çok net, çok temiz bir dildir; uzun yıllar kullanıldı, artık sık rastlanmıyor.

> **Hocanın vurgusu:** Sektöre çıktığınızda birçoğunuz belki C kullanmayacaksınız, ama performans ve gömülü sistemler söz konusuysa C mutlaka karşınıza çıkacaktır. Temelleri öğrenildiğinde zor değildir ve bilgisayarı tamamen yönetebilmeyi sağlayan yeteneklere sahiptir.

### 14.4 Nesneye Dayalı Diller

Slayttaki maddeler (ekrandan, 01:45:00):

- Yazılımlar karmaşıklaştıkça daha efektif kodlama ihtiyacı.
- Nesneye dayalı programlama ile modüler ve yeniden kullanılabilir kodlar.
- İş yapan, birbirleriyle haberleşen nesneler (objeler) üzerine kurulu.

Önceki diller prosedürel (yapısal, structured) dillerdi. Hesaplama işlerinde ve sistemle iletişim gerektiren işlerde kullanılırlar, ama günlük hayattaki şeyleri modellemek bu dillerle kolay değildir. Araba, bilgisayar, bina, insan, hayvan gibi sınıfları ve türleri modelleyebilme ihtiyacından nesneye dayalı diller doğdu: Java, C++, Python (hocaya göre Python iki tarafı da olan bir dildir). Bu diller nesnelerin davranışlarını ve özelliklerini tanımlamayı, haberleşmelerini kolaylaştırmayı, yeniden kullanılabilir ve birbirinden türetilebilir kod üretmeyi sağlar. Özellikle 1990-2000 arasında C++ ve Java ile gerçekleşen dönüşüm sayesinde olay güdümlü programlama (event-driven programming) yaygınlaştı: Belirli bir sıralı akışı olmayan, düğmeler, pencereler ve kullanıcının tıklamaları üzerinden, yani grafik arayüzde (GUI) kullanıcının seçtiği kombinasyonlara göre yürüyen programlar.

### 14.5 Dil Seçimi

Algoritma tasarlamak çok önemlidir. Ancak bir problemi nasıl çözeceğimizi tarif ettikten sonra seçilen dil de bazı durumlarda önemlidir. Bazen Java, C ya da Python arasında fark edilmeyecek kadar küçük süre farkları olur. Ama çok büyük veriyle ya da gerçek hayata yakın olaylarla (event) çalışılıyorsa C seçilmez; çok yoğun işlem gerektiren bir durumda Java seçilmez; veriyle ilgili hazır kütüphaneler kullanılmak isteniyorsa, örneğin veri biliminde, Python seçilir. Bu yüzden dillerin ne amaçla yazıldığını ve yeteneklerini tanımak gerekir.

### 14.6 Dördüncü Nesil ve Özel Amaçlı Diller

Yüksek seviyeli dillerden sonra uygulamaya özel diller, yani dördüncü nesil diller gelir. Bunlar konuşma diline daha yakındır ve ne yapıldığı kolayca anlaşılır. Önemli bir örnek SQL'dir (Structured Query Language): Veritabanlarını sorgulamak, verilere ulaşmak ve güncellemek için kullanılır; `select`, `insert`, `update`, `delete` gibi komutları ve `from`, `into` gibi günlük dile yakın sözcükleri vardır. Hiç programlama bilmeyen biri bile kolayca öğrenip kod yazabilir.

Örneğin bir `select` ile veri alınırken verinin hangi dosyadan alındığı, nerede saklandığı, önce belleğe getirilip getirilmediği gibi konularla ilgilenilmez; yalnızca tabloda bilginin nerede olduğu bilinir ve "bana bu bilgiyi getir" ya da "şu bilgiyi bul ve güncelle" denir. Bu, geliştirmeyi çok hızlandırır ve bilgisayarı çok iyi bilmeyen kişilerin bile analist ya da operatör olarak çalışmasını, kendi problemlerini hazır paketlerle çözmesini mümkün kılar. Ancak her yeni katman yeni bir soyutlama katmanı (abstraction layer) demektir: Makine dilinden uzaklaştıkça kodun performansında düşüş ve çalışma hızında yavaşlama olur.

Son olarak yapay zekâ için özel geliştirilmiş diller ve kutu ile daire gibi şekillerle akış diyagramlarının gösterildiği, örneğin elektronik devre çiziminde kullanılan görsel diller vardır. Bunlar kendi alanlarına özgü işlerin alt seviyeden soyutlanmış biçimde yapılmasını ve yapılan işe odaklanılmasını kolaylaştırır. <!-- BELİRSİZ: Bu dil grubunun adı altyazıda "Konstantin Diller" diye bozuk geçiyor; doğru terim çıkarılamadı. -->

## 15. Derleyici ve Yorumlayıcı

Slayttaki maddeler (ekrandan, 01:50:00):

- Compiler (Derleyici): High-level bir dille program yazdığımız kaynak kodun makine koda dönüştürülmesini sağlar.
- Interpreter (Yorumlayıcı): Program bir seferde değil satır satır derlenir. Bir satır çalıştırıldıktan sonra bir sonraki satır çalıştırılır.
- Pek çok programlama dili hem derleyici hem yorumlayıcı ile çalışabilir.
- Derleyici ile çalışan diller: C, JAVA, C++..
- Yorumlayıcı ile çalışan diller: Basic, Lisp, MATLAB, SmallTalk..

Programlama dilleri kaynak kodu makine diline çevirmek için derleyiciden ya da yorumlayıcıdan, bazıları her ikisinden yararlanır:

- **Derleyici:** Kodun tamamı birlikte incelenir ve bir seferde makine diline çevrilir.
- **Yorumlayıcı:** Komut komut gidilir. Önce toplama çevrilir, sonra atama, sonra bir sonraki adımdaki karşılaştırma. Bütün kod bir seferde dönüştürülmez; çalıştıkça satır satır ilerlenir.

Hocaya göre derleyici tabanlı diller yorumlayıcı dillere göre performans açısından daha iyidir. C derlenen (compiled) bir dildir; Python yorumlanan (interpreted) bir dildir ve hocanın ifadesiyle C'nin üzerine inşa edilmiştir.

Yorumlanan diller neden vardır? Platformdan bağımsızlık (platform independence) sağlarlar ve uzun bir derleme süreci gerektirmezler; kod yazılır yazılmaz çalıştırılabilir. Derlenen dillerde bir değişiklik yapılıp çalıştırıldığında önce bütün kodun yeniden derlenmesi gerekir, aksi hâlde değişiklik yansımaz. Yorumlanan dillerde ise değişiklikten sonra baştan bir derleme yapılmaz, çünkü kod zaten satır satır makine diline çevrilerek çalıştırılır.

Hoca slaytta bir düzeltme yaptı: Java yalnız derleyici ile çalışan diller arasında gösterilmemelidir; Java hem derlenen hem yorumlanan bir dildir. C derleyici ile, MATLAB yorumlayıcı ile çalışır, Python yorumlanan bir dildir.

> **Ek bilgi (derste anlatılmadı):** Java kaynak kodu önce derleyiciyle platformdan bağımsız bir ara koda (bytecode) çevrilir; bu ara kod sonra Java Sanal Makinesi (JVM) tarafından yorumlanır ya da çalışma anında derlenir (JIT). Python'un en yaygın gerçekleştirimi olan CPython da C ile yazılmıştır; hocanın "C'nin üzerine inşa edilmiştir" ifadesi büyük olasılıkla buna işaret eder.

## 16. Sayı Sistemlerine Giriş

Dersin son bölümünde hoca tableti tahta gibi kullanarak sayı sistemlerine kısa bir giriş yaptı (ekrandan, 02:05:00 ve 02:10:00).

Sekiz bit yan yana yazıldığında bir byte oluşur ve bellekte erişilebilen bir adresteki bilgi bir byte'lıktır. Tahtadaki örnek:

```text
| 0 | 1 | 0 | 0 | 0 | 0 | 1 | 1 |   ->  1 byte (8 bit)
 2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
```

İkili sistemin yanında sekizli (octal), onlu (decimal) ve onaltılı (hexadecimal) sayı sistemleri vardır. Günlük hayatta onlu sistemi kullanırız: Rakamlar 0'dan 9'a kadar gider, sonra 10 yazılır. Sayı sistemleriyle çalışırken tabanı her zaman sayının yanına yazarız, örneğin $(1)_{10}$.

- **Onaltılı sistem:** 9'dan sonra A, B, C, D, E, F gelir; bunlar sırasıyla 10, 11, 12, 13, 14, 15'e karşılık gelir. Sonra $(10)_{16}$ yazılır ve bu 16'dır.
- **Sekizli sistem:** 7'ye kadar gider. 8 yazılmak istendiğinde $(10)_8$ yazılır ve bunun onluk karşılığı 8'dir.

Bunlar basamak kullanarak oluşturulmuş sayı sistemleridir ve her basamağın bir ağırlığı vardır. Onlu sistemde birler, onlar, yüzler basamağı $10^0, 10^1, 10^2$'dir. İkili sistemde sola doğru $2^0, 2^1, \dots, 2^7$, yani birler, ikiler, dörtler, sekizler basamağı diye ilerler. Aynısı sekizli sistem için de geçerlidir ($8^0, 8^1, \dots$). Bu tabanlar kullanılarak sistemler arasında dönüşüm yapılabilir; dönüşümler bir sonraki derste ayrıntılı işlenecektir.

### 16.1 İkiliden Onluğa Örnek

$(01000011)_2$ sayısının onluk karşılığı sorulduğunda sohbetten 67 cevabı geldi ve hoca bunu doğruladı:

$$(01000011)_2 = 1\cdot 2^6 + 1\cdot 2^1 + 1\cdot 2^0 = 64 + 2 + 1 = 67$$

### 16.2 Konumsal ve Konumsal Olmayan Sayı Sistemleri

Sayı sistemleri temelde ikiye ayrılır:

- **Konumsal (positional) sayı sistemleri:** İkili, sekizli, onlu, onaltılı.
- **Konumsal olmayan (non-positional) sayı sistemleri:** Örneğin Roma rakamları.

Roma rakamlarında basamak kavramı yoktur: I, II, III diye başlar, sonra 4'ün gösterimi değişir (IV), 9 için başka bir gösterim gelir (IX). Kuralları kendi içindedir ve basamaklar üzerinden dönüşüm yapılamaz; yine de birçok kaynakta hâlâ kullanılır. Bu derste ağırlıklı olarak ikili, onlu ve onaltılı sistem kullanılacak, sekizli sistem çok sık kullanılmayacaktır. İkili sistem bilgisayarın temeli olduğu için özellikle önemlidir.

### 16.3 Bir Byte ile Kaç Farklı Sayı Yazılır?

Tahtadaki notlar (ekrandan, 02:10:00):

```text
İşaretsiz Sayı Sistemi :  0 ... 255     } 256
İşaretli Sayı Sistemi  : -128 ... 127   } 256
2^8 -> 256
```

Bir byte'lık (8 bitlik) alanla işaretsiz sayı sisteminde yazılabilecek en küçük sayı 0, en büyük sayı 255'tir; yani 256 farklı sayı yazılabilir. İşaretli sayı sisteminde -128 ile 127 arası yazılabilir; bu da yine 256 değer eder. Kısacası 8 bitlik bir alanda $2^8 = 256$ farklı bilgi saklanabilir.

İşaretli sayı, eksi sayıların da saklanabilmesi demektir. Bunun için ayrı bir "eksi" sembolü kullanılmaz; 8 bitten biri sayının işareti için ayrılır, geriye 7 bit kalır. Bu yüzden yazılabilecek pozitif ya da negatif sayıların büyüklüğü yarıya düşer.

## Örnek Sorular

**Soru 1** (ekrandan, 02:05:00; derste sözlü, 02:03:58): İkili tabanda yazılmış $(01000011)_2$ sayısı onluk sistemde kaçtır?

> **Çözüm:** Değeri 1 olan bitlerin ağırlıkları toplanır: $2^6 + 2^1 + 2^0 = 64 + 2 + 1 = 67$. Derste sohbetten gelen 67 cevabı doğrulandı.

**Soru 2** (derste sözlü, 02:05:17): Konumsal olmayan (non-positional) bir sayı sistemine örnek veriniz.

> **Çözüm:** Roma rakamları. Basamak kavramı yoktur; örneğin 4 (IV) ve 9 (IX) kendine has kurallarla gösterilir.

**Soru 3** (derste sözlü, 02:06:31): Bir byte'lık alanla kaç farklı sayı yazılabilir? İşaretsiz ve işaretli sistemlerde aralık nedir?

> **Çözüm:** $2^8 = 256$ farklı değer. İşaretsiz: 0 ile 255; işaretli: -128 ile 127.

**Soru 4** (derste sözlü, 01:31:11): BIOS'un ROM ile bağlantısı var mıdır?

> **Çözüm:** Evet. BIOS ayarlarının bilgisayarın belleğinden ve ikincil bellekten bağımsız tutulması gerektiği için ROM/EPROM gibi kalıcı bellekler kullanılır.

**Soru 5** (derste sözlü, 01:33:32): RAM'in DDR3 ya da DDR4 olması neyi etkiler?

> **Çözüm:** Nesiller arasında belleğe erişim (veri yolu) hızı ve modül tasarımı farklıdır; bu, verinin bellekten işlemciye gelme süresini etkiler. Hoca ayrıntılı farkların araştırılabileceğini söyledi.

## Dersin Toparlaması

Bu derste bilgisayarın abaküsten Babbage'ın mekanik makinelerine, ABC, Colossus ve ENIAC gibi ilk elektronik bilgisayarlardan mainframe'lere, kişisel bilgisayarlara, mobil cihazlara ve süper bilgisayarlara uzanan tarihçesi izlendi. Ardından bugünkü bilgisayarların temelindeki von Neumann mimarisi (giriş, çıkış, bellek, kontrol birimi ve ALU'dan oluşan CPU), donanım-yazılım ayrımı, bellek hiyerarşisi, RAM, ROM, BIOS ve ikincil bellek türleri, ikinin kuvvetlerine dayanan veri kapasite birimleri ve analog-dijital farkı anlatıldı. Yazılım tarafında işletim sistemi, sistem ve uygulama yazılımları, makine dilinden assembly'ye, yüksek seviyeli, nesneye dayalı ve dördüncü nesil dillere uzanan programlama dili nesilleri ile derleyici-yorumlayıcı farkı ele alındı.

Ders, sayı sistemlerine kısa bir girişle bitti: konumsal ve konumsal olmayan sistemler, ikili bir sayının onluğa çevrilmesi ve bir byte'ta işaretsiz ve işaretli olarak saklanabilecek değer aralıkları. Hoca bir sonraki derste sayı sistemleri arasındaki dönüşümlerin, lojik kapıların, kesirli sayıların nasıl saklandığının (floating point) ve eksi sayıları saklama yöntemlerinin (one's complement, two's complement) işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
