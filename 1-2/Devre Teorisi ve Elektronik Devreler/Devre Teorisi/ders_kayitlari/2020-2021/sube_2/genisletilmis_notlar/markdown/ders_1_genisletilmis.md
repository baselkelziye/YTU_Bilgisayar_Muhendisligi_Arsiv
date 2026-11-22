# Ders 1 Genişletilmiş Notu: Devre Teorisine Giriş: Birimler, Devre Elemanları ve Ohm Yasası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. Ölçü Birimleri ve SI Önekleri
- 3. Anlamlı Basamak, Doğruluk ve Yuvarlama
- 4. Üslü Sayılarla İşlem, Bilimsel ve Mühendislik Gösterimi
- 5. Elektrik Akımı ve Elektron Akımı
- 6. Potansiyel Fark: Su ve Yükseklik Benzetmesi
- 7. Devre Elemanlarına Genel Bakış
- 8. Bağımsız ve Bağımlı Güç Kaynakları
- 9. Gerilim Kaynağı, Akım Kaynağı ve İlk Güç Dengesi
- 10. Pasif Elemanlar: Direnç, Bobin, Kondansatör
- 11. Toprak, Kablo, Anahtar ve Sigorta
- 12. Kablo Standardı: AWG
- 13. Ders Boyunca Kabul Edilecek Kurallar
- 14. Yük, Akım, DC ve AC
- 15. Gerilim, Güç ve Enerji
- 16. Pozitif ve Negatif Güç, Enerjinin Korunumu
- 17. Ohm Yasası
- 18. Negatif Gerilim ve Akım, Ölçü Aletlerinin Bağlanması
- 19. Pasif İşaret Kuralı ve Örnek
- 20. Kaynaklar da Güç Tüketebilir

## 1. Dersin Kapsamı

Devre teorisi, elektronik ya da elektrik mühendisliği bölümlerinde iki dönemlik (Devre Teorisi 1 ve 2) bir ders olarak okutulur. Bilgisayar mühendisliğinde ise amaç devre mantığının anlaşılmasıdır: doğru akım (DC) analiziyle başlanır, sonra alternatif akım (AC) analizine kısaca girilir. Hoca konuların birbirine bağlı olduğunu, özellikle düğüm gerilimleri ve çevre akımları analizinin, Thevenin ve Norton teoremlerinin ilerideki her şeyin temeli olduğunu söyledi. İşlemsel yükselteçler (op-amp) öğrencilerin en kolay anladığı konu olarak anıldı; RL, RC ve RLC devreleri ile frekans düzlemindeki analiz ise birbirinin üzerine kurulduğu için birini kaçırmak ötekini anlamayı zorlaştırır.

Hoca dersin genel olarak zor görüldüğünü, ama aslında zorluğun ince noktalardan geldiğini vurguladı: akımın yönünü ters almak bütün soruyu götürebilir.

> **Hocanın vurgusu:** Bu derste hataların çoğu birim, akım yönü ve işaret gibi küçük noktalardan çıkar; bu temeller ilk haftadan oturtulmalıdır.

## 2. Ölçü Birimleri ve SI Önekleri

Dersin ilk akademik konusu birimlerdir. Bir sayısal sonuç verirken yalnız "5" demek yetmez; 5 neyin beşidir? Sorularda akım istendiğinde "akım eşittir 5" yazıp geçmek en sık yapılan hatalardan biridir. Uzunluk için metre, kütle için kilogram nasıl kullanılıyorsa, devrelerde de her büyüklüğün birimi yazılmalıdır: 5 amper, 5 milivolt gibi. Derste en çok kullanılacak birimler akım için amper, gerilim için volt ve zaman için saniye ile alt birimleridir (milisaniye, mikrosaniye).

SI biriminin büyük üstünlüğü, büyük ve küçük birimleri temel birime 10'un kuvvetleri cinsinden öneklerle bağlamasıdır. Slaytta aynı uzaklık üç biçimde verilmiştir: 600 000 000 mm, 600 000 m ve 600 km (ekrandan, 00:35:00). Slayttaki tabloda derste kullanılacak önekler kırmızıyla işaretlenmiştir:

| Çarpan | Önek | Sembol |
|---|---|---|
| $10^{9}$ | giga | G |
| $10^{6}$ | mega | M |
| $10^{3}$ | kilo | k |
| $10^{-3}$ | mili | m |
| $10^{-6}$ | mikro | $\mu$ |
| $10^{-9}$ | nano | n |
| $10^{-12}$ | piko | p |

Nano ve piko daha çok kondansatör ve RLC yapılarında karşımıza çıkacaktır. Tablonun geri kalanı (exa, peta, tera, hecto, deka, deci, centi, femto, atto) bu derste kullanılmaz.

> **Hocanın vurgusu:** Mili ($10^{-3}$) ile mikro ($10^{-6}$) sürekli karıştırılıyor. Sonuç 5 mA olması gerekirken 5 $\mu$A yazılıyor. Elle yazılan $\mu$ sembolü m'ye benzetilip mili diye, düz yazılan m de mikro diye okunabiliyor. Bu tek hata bütün soruyu götürür.

### 2.1 Birim dönüştürme

Hoca birim dönüştürmeyi bir hız örneğiyle anlattı. Bir araç 4000 metreyi bir dakikada alıyorsa ve hızı kilometre/saat cinsinden soruluyorsa, cevap "4000 bölü 1" değildir. Önce 4000 metre kilometreye, bir dakika saate çevrilir, sonra bölme yapılır. Devre sorularında da aynısı geçerlidir: gerilim volt, direnç kiloohm olarak verilmiş ve akım amper olarak isteniyorsa, değerler önce aynı düzeye getirilir.

Kural iki adımdır:

- Denklemdeki her değişkenin birimi aynı "dili" konuşmalıdır; hesaptan önce bütün büyüklükler aynı birim düzeyine getirilir.
- Sonuç, istenen birime çevrilerek yazılır. Akım amper olarak bulunmuş ama miliamper isteniyorsa sonuç miliampere dönüştürülür.

> **Ek bilgi (derste anlatılmadı):** Hız örneğinin sonucu büyük olasılıkla $4\ \text{km} / (1/60)\ \text{sa} = 240$ km/sa'tir. Derste sonuç söylenmedi, yalnız yöntem anlatıldı.

## 3. Anlamlı Basamak, Doğruluk ve Yuvarlama

Bilimde sayılar iki türlüdür (ekrandan, 00:40:00):

- **Tam (exact) sayılar:** 12 elma gibi. 12.5 elma olamaz.
- **Yaklaşık (approximate) sayılar:** Laboratuvarda alınan her okuma yaklaşık kabul edilir.

Hoca elektrik devrelerinde değerlerin genelde yaklaşık söylendiğini açıkladı: belirli bir $t$ anında ölçülen değer her zaman geçerli olan değer değildir, değişkenlik gösterebilir. Bir okumanın hassasiyeti (precision) içerdiği anlamlı basamak sayısıyla belirlenir. Doğruluk (accuracy) ise ölçülen değerin standart ya da bilinen değere yakınlığıdır. Yaklaşık sayılarda uygun doğruluk düzeyine karar verilip sonuç yuvarlanır (round off). Slayttaki örnek: $3.186 \cong 3.19 \cong 3.2$. Devre teorisinde kabul edilen yuvarlama noktadan sonra iki basamaktır; yani 3.186 yerine 3.19 yazılır.

## 4. Üslü Sayılarla İşlem, Bilimsel ve Mühendislik Gösterimi

### 4.1 Önekli büyüklüklerle işlem

Önekler 10'un kuvvetleri olduğu için, önekli büyüklüklerle işlem üslü sayılarla işlem gibidir. Örneğin kiloohmu ohma çevirmek için $10^{3}$ ile çarpılır. Toplama ve çıkarmada üslerin eşit olması gerekir; çarpmada katsayılar çarpılır, üsler toplanır; bölmede katsayılar bölünür, üsler çıkarılır.

Hoca örnek olarak 5 k$\Omega$ ile 3 M$\Omega$'un toplanmasını verdi: ikisi de ohm düzeyine indirilip üslü biçimde toplanır.

> **Ders sonrası not:** Hoca toplamı "3 çarpı 10 üzeri 3 artı 5 çarpı 10 üzeri 6" diye söyledi; katsayıları yer değiştirmiş. Doğrusu $5\ \text{k}\Omega + 3\ \text{M}\Omega = 5\times10^{3} + 3\times10^{6} = 3.005\times10^{6}\ \Omega = 3.005\ \text{M}\Omega$'dur.

### 4.2 Bilimsel ve mühendislik gösterimi

İki gösterim de 10'un kuvvetlerini kullanır, ama mantis (çarpan) ya da ölçek çarpanı (10'un kuvveti) üzerinde farklı kısıtları vardır (ekrandan, 00:45:00):

- **Bilimsel gösterim:** Ondalık nokta, 1'e eşit ya da büyük ve 10'dan küçük ilk basamaktan hemen sonra gelir. Yani noktadan önce tek bir basamak vardır.
- **Mühendislik gösterimi:** 10'un bütün kuvvetleri 3'ün katı olmalıdır; mantis 1'e eşit ya da büyük ve 1000'den küçüktür. Noktadan önce en fazla üç basamak bulunur.

Hesap makinelerinde ve bilgisayarlarda görülen E gösterimi de 10'un kuvvetidir: E3 $10^{3}$, E-3 $10^{-3}$ demektir. Hoca sınavda hangi gösterimin kullanılacağı konusunda bir kriter koymayacaklarını, ama bunun bilinmesi gereken bir temel olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Mühendislik gösterimindeki üsler 3'ün katı olduğu için doğrudan öneklere karşılık gelir: $2.5\times10^{-3}$ A $= 2.5$ mA, $47\times10^{3}\ \Omega = 47$ k$\Omega$ gibi.

## 5. Elektrik Akımı ve Elektron Akımı

Devre teorisinin ilk temeli elektriğin ne olduğudur. Elektriği oluşturan şey, elektronların bir iletken (örneğin kablonun içi) boyunca hareketidir. Slayttaki şekilde artı yüklü çekirdek ve çevresindeki eksi yüklü elektronlardan oluşan atomlar, mavi bir kablo içinde gösterilmiştir (ekrandan, 00:50:00). Alttaki çizimde bir tarafta elektronlar birikmiş, diğer tarafta eksik kalmıştır.

Elektronlar çok oldukları yerden az oldukları yere doğru hareket eder; bunun nedeni dengeyi sağlamaktır. Elektronlar artı uca doğru çekilir.

Burada iki kavram ayrılır:

- **Doğal akım (natural current) ya da elektron akımı:** Elektronların hareket yönündeki akımdır, üstü çizgili $\bar{I}$ ile gösterilir.
- **Elektrik akımı:** Elektron akımının tam tersi yönündeki akımdır, $I$ ile gösterilir. Bu ders boyunca kullanılan akım budur.

> **Hocanın vurgusu:** Elektrik akımı, elektronların hareketinin tersi yönündedir. Sorularda her zaman bu akım ($I$) kullanılır.

## 6. Potansiyel Fark: Su ve Yükseklik Benzetmesi

Elektrik gözle görülmediği için bazı kavramları oturtmak zordur. Bu yüzden derste önerilen kitaplardan birinde de kullanılan su benzetmesine başvuruldu.

### 6.1 İki bardak

Bir bardaktan ötekine su dökmek için birinci bardağın daha yukarıda olması gerekir. Yukarıdaki suyun potansiyel enerjisi kinetik enerjiye dönüşür ve su akar. Aynı şekilde, bir iletken içinde elektronların hareket edebilmesi için bir tarafta daha yüksek, diğer tarafta daha düşük gerilim olmalıdır. Hoca bunu bir tarafta daha fazla, diğer tarafta daha az elektron bulunması olarak anlattı. İki nokta arasındaki bu farka **potansiyel fark** denir.

Özetle: elektrik için elektronların hareket etmesi, elektronların hareket etmesi için de iki nokta arasında potansiyel fark gerekir.

Su akışı iki yolla güçlendirilebilir:

- **Bardağı daha yukarı taşımak:** Yükseklik farkı artar, su daha güçlü iner. Devrede bu, potansiyel farkın artırılmasına karşılık gelir; akım artar.
- **Bardaktaki suyu artırmak:** Yükseklik aynı kalsa da aynı sürede daha fazla su boşalır. Hoca bunu elektron sayısının artırılmasına benzetti; bu da daha fazla akım demektir.

Aynı yükseklikte biri dolu, biri yarım dolu iki bardak çevrildiğinde dolu olanın debisi daha yüksektir. Yüksek akım da içinden daha fazla elektronun geçtiği akımdır.

Hoca barajları da örnek verdi: barajın amacı, yüksekte tutulan suyun potansiyel enerjisini kinetik enerjiye çevirip kullanmaktır.

### 6.2 Damla ve referans noktası

Slaytta iki farklı yükseklikten düşen iki su damlası vardır ve hangisinin yere daha büyük kuvvetle çarpacağı sorulur (ekrandan, 00:55:00). Yüksekten bırakılan damlanın potansiyel enerjisi daha büyüktür, bu enerji kinetik enerjiye dönüştüğünde çarpma etkisi de daha büyük olur. Slayttaki not: elektrik potansiyeli, su damlasının referans zeminden yüksekliğine benzetilebilir.

Yüksekliği ölçmek için bir zemin gerektiği gibi, devrelerde de bir referans noktası alınır: **toprak (ground)**. Akım oluşması için devreyi besleyen kaynağın bir tarafına daha düşük potansiyelli bir nokta konmalıdır; bu nokta devrelerde her zaman topraktır ve gerilimi 0 V kabul edilir. Bir pilin 9 V olması, içindeki yüklerin toprağa göre potansiyel farkının 9 V olması demektir.

## 7. Devre Elemanlarına Genel Bakış

Bu derste kullanılacak devre elemanları slaytta dört grupta verilmiştir (ekrandan, 01:00:00). Hoca ikinci sınıftaki elektronik dersinde bunlara ek elemanlar geleceğini, devre teorisinde ise yalnız bunların kullanılacağını söyledi.

- **Aktif elemanlar:** Devreyi besleyen elemanlardır. Bunlar olmazsa devrede akım oluşmaz ya da oluşsa bile geçicidir ve bir süre sonra tamamen söner. Bağımsız ve bağımlı güç kaynakları (gerilim ve akım) bu gruptadır.
- **Pasif elemanlar:** Devrenin ürettiği enerjiyi tüketen ("sömüren") elemanlardır: direnç, kondansatör (kapasitör), bobin (indüktör).
- **Ölçü aletleri:** Ampermetre akımı, voltmetre gerilimi ölçer.
- **Diğerleri:** Toprak (referans noktası), elektrik kablosu, anahtar (switch) ve koruyucu eleman olarak sigorta (fuse).

Devre tasarım programlarında da bir referans noktası belirtilmelidir; aksi söylenmedikçe referans, 0 V kabul edilen topraktır. Kablo devreyi kurmak için gereken bileşendir. Anahtar devredeki akımı açıp kapar. Sigorta ise akımdaki ani yükselme ve düşmelerde direnç, kondansatör, bobin gibi elemanları korur.

Hoca sigortanın önemini laboratuvardan bir örnekle anlattı: ölçü aletini yanlış bağlayan öğrenci aletin içindeki sigortayı yakar. Sigorta yanmasaydı ölçü aletinin kendi devresi yanacaktı. Sigortanın maliyeti birkaç lirayken ölçü aletininki yüzlerce liradır.

## 8. Bağımsız ve Bağımlı Güç Kaynakları

### 8.1 Bağımsız kaynaklar

"Güç kaynağı" denince akla hep pil, batarya, yani gerilim kaynağı gelir. Ama güç yalnız gerilimle ilgili değildir; güç formülünde akım da vardır. Bu yüzden bir akım kaynağı da güç kaynağıdır. Bir devreyi akımla beslemek bir gerilim oluşmasına, gerilim de potansiyel farka yol açar; potansiyel fark olmadan da akım oluşmaz. Bu kavramlar iç içedir.

Bağımsız kaynak, değeri hiçbir değişkene bağlı olmayan kaynaktır. Sorularda yanında 5 V, 3 V ya da 3 A yazar ve bu kaynak devreye her zaman o değeri verir.

### 8.2 Bağımlı kaynaklar

Bağımlı kaynak eşkenar dörtgen (baklava) sembolüyle çizilir (ekrandan, 01:05:00). Bağımsız kaynağın yuvarlak sembolünde olduğu gibi içine gerilim kaynağıysa artı-eksi, akım kaynağıysa ok konur. Okun ucu her zaman artı tarafı gösterir.

Bağımlı kaynağın yanına sabit bir değer yazılmaz; değeri devredeki başka bir büyüklüğe bağlıdır. Hoca slayta şu örneği çizdi: devrede bir $V_1$ gerilimi var ve baklava sembollü gerilim kaynağının yanına $5V_1$ yazılmış. Bu kaynak her an $V_1$'in beş katını verir. $V_1 = 5$ V ise kaynağın gerilimi

$$5V_1 = 5 \cdot 5 = 25\ \text{V}$$

olur. Kontrol eden büyüklüğün bir kaynak olması gerekmez. Örneğin bir $R_1$ direncinin üzerindeki gerilim $V_{R1}$ ise kaynağa $5V_{R1}$ yazılabilir; bu yine gerilim kontrollü bir gerilim kaynağıdır, ama kontrol eden gerilim direncin gerilimidir.

Dört tür bağımlı kaynak vardır:

| Kısaltma | Ad | Kontrol eden | Verdiği |
|---|---|---|---|
| VCVS | Voltage controlled voltage source | gerilim | gerilim |
| CCVS | Current controlled voltage source | akım | gerilim |
| VCCS | Voltage controlled current source | gerilim | akım |
| CCCS | Current controlled current source | akım | akım |

## 9. Gerilim Kaynağı, Akım Kaynağı ve İlk Güç Dengesi

Öğrencilerin kafasında sık oluşan bir soru şudur: devreye zaten gerilim veriyoruz ve gerilimden bir akım doğuyor; akım kaynağı neden var? Hoca bunu şöyle açıkladı: gerilim kaynağı devreye gerilim, akım kaynağı akım beslemesi verir ve ikisi aynı devrede birlikte bulunabilir. Akım kaynağı, gerilim kaynağından doğan akımı destekleyen bir kaynak gibi düşünülebilir. Akım kaynağı bulunan bir devrede akımın yönünü akım kaynağı belirler; devrede gerilim kaynağı bulunması bu yönü değiştirmez. Gerilim kaynağı ise devrede kutuplaşmaya yol açar: ileride görülecek sorularda bir direncin uçlarının artı-eksi işaretlerini belirleyen şey gerilim kaynağının uçları olacaktır.

### 9.1 Örnek 1: akım kaynağı ve eleman

Slaytta 3 A'lik bir bağımsız akım kaynağı, üzerinde 1 V düşen kırmızı bir elemana doğrudan bağlanmıştır (ekrandan, 01:10:00). Akım kaynağının oku yukarıyı, yani artı ucu gösterir; elemanın üst ucu artı, alt ucu eksidir.

Hoca aynı sayfaya bir pil ve ampul devresi çizerek akım yönünü açıkladı. Kablonun içine yakından bakıldığında elektronlar vardır. Pilin artı ucu bağlandığı anda elektronlar artı uca doğru hareket eder; bu elektron akımıdır. Elektrik akımı $I$ ise bunun tersine, pilin artı ucundan çıkıp devreyi dolaşarak eksi uca girer. Yani besleme yapan kaynakta akım artı uçtan çıkar, eksi uca girer.

Örnekte akım kaynağın artı ucundan çıkıp devreyi dolaşır. Devreye takılan diğer elemanlar bu enerjiyi tüketir; tükettikleri için kutupları kaynağınkinin tersi yönde olur, yani akım elemana artı ucundan girer. Elemanın üzerindeki 1 V'un kutuplanmasını sağlayan şey akım kaynağıdır.

Bu örnekte ilk kez enerji (güç) dengesi kuruldu. Güç $P = V\cdot I$ ile hesaplanır:

- Kaynağın gücü: $3\ \text{A} \cdot 1\ \text{V} = 3$ W (üretim).
- Elemanın gücü: $3\ \text{A} \cdot 1\ \text{V} = 3$ W (tüketim).

Biri üretir, biri tüketir ve ikisinin büyüklüğü aynıdır. Üretilen ve tüketilen güçlerin toplamının sıfır olması kuralı ileride Kirchhoff yasalarında (KCL, KVL) tekrar kullanılacaktır.

## 10. Pasif Elemanlar: Direnç, Bobin, Kondansatör

Pasif elemanlar kaynakların verdiği enerjiyi tüketir. Bu tüketim anında olabilir (direnç) ya da enerji bir süre eleman üzerinde tutulup sonra yavaşça bırakılabilir (kondansatör ve bobin). Bobin bunu akımla, kondansatör gerilimle yapar. Slayttaki tablo (ekrandan, 01:15:00):

| Eleman | Sembol | Birim |
|---|---|---|
| Direnç (resistor) | zikzak çizgi | ohm ($\Omega$) |
| Bobin (inductor) | art arda yarım halkalar | henry (H) |
| Kondansatör (capacitor) | iki paralel kısa çizgi | farad (F) |

### 10.1 Direnç ve renk kodu

Direncin gövdesindeki renk bantları değerini gösterir (color code). Hoca renk sırasını akılda tutmak için "Sokakta Sayamam" gibi bir kısaltma kullanıldığını söyledi; her rengin onluk düzende bir ağırlığı vardır. Ezberlemeye gerek olmadığını, laboratuvarda da tablonun hazır verildiğini ekledi.

Okuma kuralı:

- İlk iki bant doğrudan basamakları verir (renklerin sıra numarası: 0, 1, 2, ...).
- Üçüncü bant çarpandır: $10^{n}$, burada $n$ o rengin sıra numarasıdır.

Hoca slayttaki direnç için tahtaya basamakları ve çarpanı "1 0 × 10" diye yazdı (ekrandan, 01:15:00). Bu, $10 \times 10^{1} = 100\ \Omega$ demektir. Benzer şekilde 1 M$\Omega$ bir milyon ohm demektir.

> **Ders sonrası not:** Hoca sonucu "110'luk bir direnç" diye söyledi; tahtadaki $10\times10^{1}$ hesabının sonucu 100 $\Omega$'dur. Hoca renklerin sırasını da karışık saydı (siyah, kırmızı, kahverengi, ...) ve mavinin çarpanının $10^{6}$ mı $10^{7}$ mi olduğundan emin olmadığını söyledi. Standart renk kodunda sıra büyük olasılıkla siyah 0, kahverengi 1, kırmızı 2, turuncu 3, sarı 4, yeşil 5, mavi 6, mor 7, gri 8, beyaz 9'dur; yani mavinin çarpanı $10^{6}$'dır.

Simülasyon ortamında direnç zikzaklı bir tel olarak gösterilir ve yanına değeri yazılır.

### 10.2 Bobin

Bobin (indüktör) bakır telin çok sık sarılmasıyla yapılır. Hoca bobinin akımı üzerinde depoladığını söyledi: sarımlardan geçen akım bir manyetik alan oluşturur ve akım bu yapıda bir süre "hapsolur"; bobin akımı biriktirip sonra yavaşça söndürür. Ayrıntısı ilerideki bobin konusunda anlatılacak. Sembolü sarım şeklini andırır, birimi henry'dir (H).

### 10.3 Kondansatör

Kondansatörün (kapasitör) kutuplu, kutupsuz, mercimek gibi pek çok çeşidi vardır. Kutuplu kondansatörlerde sembolün yanına artı-eksi konur ya da plakalardan biri uzun çizilir; uzun olan artı, kısa olan eksi uca karşılık gelir. Fiziksel kutuplu kondansatörde gövdedeki eksi işaretli şeridin yanındaki bacak eksi, diğeri artı bacaktır. Birimi farad'dır (F).

## 11. Toprak, Kablo, Anahtar ve Sigorta

Slaytta bu elemanların fotoğrafları ve sembolleri bir arada verilmiştir (ekrandan, 01:20:00).

- **Elektrik kablosu:** Düz bir çizgiyle gösterilir. Farklı standartları ve iletimi etkileyen özellikleri vardır.
- **Toprak:** Minarelerin dibine yıldırımdan korunmak için toprağa çakılan büyük metal çubuk gibi düşünülebilir. Sembolü toprağa çakılmış bir çubuğu andırır. Slaytta earth, chassis, iki tür ground, analog ground ve digital ground sembolleri vardır.
- **Anahtar:** Açık ve kapalı konumlarıyla gösterilir; akımı kesme ya da iletmeye devam etme işlevi görür.
- **Sigorta:** Farklı standartlarda farklı sembolleri vardır (IEEE/ANSI, IEC, eski sembol); hoca IEC sembolünün daha çok kullanıldığını işaretledi.

**Soru:** Sembollerde iki farklı "ground" (biri içi boş, biri dolu ok) var. Aralarındaki fark nedir?
**Cevap:** Hepsi topraktır; farklı devre çizimlerinde farklı semboller görülebilir ama aynı anlama gelir. Devrede hangisi kullanılırsa kullanılsın fark yoktur.

### 11.1 Kapalı devre ve anahtar

Akımın oluşması için elektronların hareket etmesi, bunun için de kapalı devre (closed circuit) gerekir: kablo dolaşıp başladığı yere geri dönmelidir. Bir gerilim kaynağı, bir direnç ve toprak bağlantısından oluşan devre kapalıdır; akım artı uçtan çıkıp eksi uca döner. Çevrime bir anahtar eklenip açıldığında kapalı çevrim (closed loop) açılır ve akım kesilir. Anahtarın mantığı budur: açma-kapama (on-off).

İki anahtarlama türü vardır:

- **Mekanik:** Butonlar, ışıkları açıp kapadığımız duvar anahtarları.
- **Elektronik:** Kızılötesi sinyal göndererek ya da sensör verisi okuyarak yapılan açma-kapama.

### 11.2 Sigorta türleri

Şebekede akım bazı saatlerde ani yükselebilir, bazı saatlerde düşebilir; bu durum beslenen cihazlara zarar verebilir. Bunu önlemek için iki tür koruma vardır: akımı aniden kesenler ve kesmeyi zamana yayarak yavaşça yapanlar. İkinci tür genellikle yüksek akımlı durumlarda kullanılır, çünkü akımı kendi içinde söndürerek yavaş yavaş korumaya alır.

## 12. Kablo Standardı: AWG

Kablolar için American Wire Gauge (AWG) standardı kullanılır. Bu numara kablonun kesit alanına göre verilir. Slayttaki tabloda her AWG numarası için inç ve milimetre cinsinden çap ile mm$^2$ cinsinden kesit alanı vardır (ekrandan, 01:25:00). Tablodan bazı değerler:

| AWG | Çap (mm) | Kesit (mm$^2$) |
|---|---|---|
| 0000 (4/0) | 11.7 | 107 |
| 12 | 2.05 | 3.31 |
| 14 | 1.63 | 2.08 |
| 22 | 0.65 | 0.33 |
| 24 | 0.51 | 0.20 |

Evlerdeki elektrik tesisatında 12-14 AWG, ince telefon kablolarında 22-24 AWG kablolar kullanılır. Kablo inceldikçe AWG numarası büyür ve kablonun taşıyabileceği akım azalır. Numara ne kadar küçükse kesit o kadar geniştir ve kablo o kadar yüksek akımı taşıyabilir. En küçük numaralı 0000 kablo en fazla yükü taşıyabilen kablodur. Ev kablolarında kesit yaklaşık 3 mm$^2$, telefon hatlarında yaklaşık 0.2 mm$^2$ civarındadır; bu yüzden taşıdıkları yük aynı değildir ve kablo, taşınacak yüke göre seçilir.

> **Ders sonrası not:** Hoca 0000 AWG kablo için "10 santimlik bir kablo" dedi. Slayttaki tabloya göre bu kablonun çapı 11.7 mm, yani yaklaşık 1.2 cm'dir.

Numaralandırmanın kesit alanına göre yapılmasının nedeni, kesit büyüdükçe kablonun direncinin azalmasıdır. Hoca bir maddenin direncinin içindeki malzemeye (katkı maddelerine), kesit alanına ve uzunluğuna bağlı olduğunu, bunun ayrıntısına bir sonraki derste girileceğini söyledi. Kesit küçüldükçe direnç (rezistif etki) artar ve kablo daha az yük taşır.

## 13. Ders Boyunca Kabul Edilecek Kurallar

Aradan sonra hoca, ders kapsamındaki bütün sorularda geçerli olacak ön kabulleri sıraladı. Bunlar gerçek hayatta tam olarak doğru değildir, ama teorik çözümler için standart kabullerdir.

- **Kabloda kayıp yoktur.** Gerçekte kablo boyunca milivoltlar düzeyinde de olsa bir kayıp olur. Sorularda ise kablo ne kadar uzun olursa olsun, başındaki ve sonundaki gerilim aynıdır; kablonun her yerinde aynı gerilim ölçülür.
- **Kaynaklar idealdir.** Gerçekte bir gerilim kaynağından 5 V almak için iç direnç yüzünden onu 5.2 V gibi bir değere ayarlamak gerekebilir. Teoride kaynağın uçlarında her zaman üzerinde yazan gerilim vardır. Akım kaynağından da her zaman üzerinde yazan akım geçer.
- **Toprak her zaman 0 V'tur.**

Slayttaki elektrik akışı kuralları (ekrandan, 01:45:00):

- Bir yol varsa elektrik akımı yüksek gerilimden düşük gerilime akar.
- Akım elektrik kablosundan serbestçe, hiçbir dirençle karşılaşmadan geçer.
- Akım bir dirençten Ohm yasasına göre belirlenen miktarda geçer; akım geçerken direnç üzerinde $R$ değerine bağlı bir gerilim düşümü (birikimi) olur.
- Akım bir gerilim kaynağından devredeki diğer elemanlara bağlı miktarda geçer.
- Akım bir akım kaynağından kendi değeri kadar geçer.

## 14. Yük, Akım, DC ve AC

### 14.1 Yük

Yük, elektronlar ve protonlarla ilgilidir. Elektrik akımı elektronların hareketiyle oluşur; elektronlar protonlara doğru hareket eder ve bu hareket yüklerin eşit dağılması içindir. Yük $Q$ ile gösterilir, birimi coulomb'dur (C). Yük kavramı en çok kondansatör konusunda kullanılacaktır. Büyük harf $Q$ ve küçük harf $q$ arasındaki ayrımı hoca, büyük harfin kararlı durumu, küçük harfin kararlı duruma ulaşmadan önceki (zamanla değişen) durumu göstermesi olarak anlattı.

### 14.2 Akım

Elektronlar hareket ediyorsa yükler değişiyor demektir. Akım, yükün zaman içindeki değişimidir. "Değişim" matematikte türeve karşılık gelir:

$$i = \frac{dq}{dt}$$

Türev, bir zamandan ötekine ne kadar değişim olduğunu söyler. İki noktadaki yük eşitse, ne kadar beklenirse beklensin yük değişmez, elektronlar hareket etmez ve akım sıfır olur. Akım için önce yük farkı olmalı, sonra bu farkın dengeye gelmesi için geçen sürede akım oluşur. Doğru akımda büyük $I$, zamanla değişen akımda küçük $i$ kullanılır.

### 14.3 DC ve AC

Slaytta solda bir DC kaynak (pil) ve bir direnç, sağda bir AC kaynak ve bir direnç vardır; altlarında gerilimin zamana göre grafikleri çizilmiştir (ekrandan, 01:50:00).

- **Doğru akım (DC):** Bütün zaman boyunca tek bir değerdedir. 5 V'luk bir pil bağlandığında (pilin zamanla boşalması şimdilik düşünülmeden) $R$ direncinden sabit bir akım geçer. Grafik yatay bir çizgidir.
- **Alternatif akım (AC):** Zamana göre değişir; her zaman aralığında farklı bir değer alır. Grafik sinüs biçimindedir ve pozitif-negatif değerler arasında gidip gelir.

Prizlerdeki şebeke akımı AC, bataryalar gibi depolanması kolay sistemlerdeki akım ise DC'dir. AC'nin en büyük üstünlüğü, elektriğin uzak bölgelere taşınmasının DC'ye göre çok daha kolay olmasıdır. Hoca bunu "elektriğin babası Tesla mı Edison mu?" tartışmasıyla bağladı: Edison ampul örneğinde olduğu gibi doğru akımla çalışmış, Tesla ise alternatif akımı kontrol edebilmesiyle çığır açmıştır. AC'ye ilerideki derslerde ayrıntılı dönülecek.

## 15. Gerilim, Güç ve Enerji

### 15.1 Gerilim

Ohm yasasında gerilimin bir formülü vardır, ama fiziksel olarak volt, yükteki değişimin oluşturduğu enerji değişimidir:

$$v = \frac{dw}{dq}$$

Yani 1 coulomb'luk yük değişimine karşılık ne kadar enerji değişimi oluyorsa, gerilim odur.

### 15.2 Güç

Fizikte güç, birim zamanda yapılan iş ya da birim zamandaki enerji değişimidir. Gücün birimi watt'tır (W). Slayttaki türetme (ekrandan, 01:55:00):

$$p = \frac{dw}{dt} = \frac{dw}{dq}\cdot\frac{dq}{dt} = v\,i$$

Ortadaki iki kesirden birincisi gerilimi ($dw/dq$), ikincisi akımı ($dq/dt$) verir; $dq$'lar sadeleşince $dw/dt$ kalır. Bu yüzden güç gerilim ile akımın çarpımıdır. Hoca gücü enerji üzerinden değil, genellikle $P = VI$ bağıntısıyla hesaplayacaklarını söyledi.

Hoca bu noktada elektromotor kuvvetten de söz etti: yüklerin ($q$) hareket edebilmesini sağlayan etkidir.

### 15.3 Enerji

Enerji, gücün zamanla çarpımıdır. Güç zamanla değişiyorsa çarpım yerine integral alınır:

$$w = \int_{t_1}^{t_2} p\,dt = \int_{t_1}^{t_2} v\,i\,dt$$

İntegral kümülatif toplam demektir: $v\cdot i$'nin $t_1$ ile $t_2$ arasındaki toplamı. Türev ise fark almaktır.

## 16. Pozitif ve Negatif Güç, Enerjinin Korunumu

### 16.1 İşaret kuralı

Devrelerde güç artı ya da eksi işaretli olabilir ve işaret iki bilgi verir:

- **Pozitif güç:** Eleman gücü tüketiyor (absorbe ediyor). Örneğin 1 A'lik akımın geçtiği ve 1 V düşen bir direnç $P = 1\ \text{A}\cdot 1\ \text{V} = 1$ W tüketir. Direnç pasif eleman olduğu için gücü tüketmek üzere vardır. Akım direnç artı ucundan giriyorsa direnç tüketicidir.
- **Negatif güç:** Eleman gücü üretiyor. Slayttaki örnekte (ekrandan, 02:00:00) 1 A'lik akım kırmızı elemanın artı ucundan çıkar, elemanın üzerinde 1 V vardır; güç $P = -1$ W'tır. Hoca bu elemanın bir güç kaynağı gibi düşünülmesini istedi. Sağdaki ikinci şekilde akım ters yönde ve kutuplar da ters işaretlidir.

Bunun daha "bilimsel" açıklaması şudur: $P = V\cdot I$ hesabında, akım elemanın artı ucundan çıkıyorsa akımın yönü o elemana göre eksidir; bu yüzden hesaba $-1\ \text{A}\cdot 1\ \text{V}$ yazılır ve güç eksi çıkar.

Kural:

- Kutuplanmış bir elemanda akım artı uçtan giriyorsa eleman gücü tüketir, işareti artıdır.
- Akım artı uçtan çıkıyorsa eleman üreticidir, işareti eksidir. Bu doğal durumdur: elektronlar artı uca doğru hareket ettiği için akım üreticinin artı ucundan çıkar.

> **Hocanın vurgusu:** "Üreten artıdır" yanılgısı hep karışıyor. Üreten elemanların gücü eksi işaretle gösterilir. Bu çok önemli bir noktadır.

### 16.2 Enerjinin korunumu

Bir devrede elemanlar ne olursa olsun, enerjiyi üretenler ve tüketenler vardır ve aralarında bir denge kurulur. Enerjinin korunumu yasasına göre bir kapalı devredeki bütün güçlerin toplamı sıfırdır:

$$\sum P = 0$$

Derste gösterilen örnekte elemanlardan birinin gücü $-2$ W (üretici), birininki $+3$ W (tüketici) olarak yazılmıştı ve bilinmeyen bir elemanın gücü soruldu. <!-- BELİRSİZ: Bu örneğin karesi yok; üçüncü elemanın +5 W olduğu altyazıdaki "3-5 daha 8" ifadesinden çıkarıldı. --> Tüketilen toplam güç $3 + 5 = 8$ W, üretilen güç 2 W olduğuna göre, korunum için bilinmeyen elemanın 6 W üretmesi, yani gücünün $-6$ W olması gerekir:

$$-2 + 3 + 5 + P_x = 0 \;\Rightarrow\; P_x = -6\ \text{W}$$

## 17. Ohm Yasası

### 17.1 Leğen benzetmesi

Basit bir DC devrede 1 V'luk bir gerilim kaynağı ve 1 $\Omega$'luk bir direnç vardır. Devrenin DC olduğu, kaynağın AC sembolüyle değil batarya sembolüyle çizilmesinden anlaşılır. Akımın yönü baştan belirlenir: akım kaynağın artı ucundan çıkar.

Akımın büyüklüğünün neye bağlı olduğunu anlamak için hoca şu benzetmeyi kullandı: yukarıda dibinde delik olan bir leğen, aşağıda da suyun aktığı ikinci bir leğen düşünün. Delik büyüdükçe akış artar, küçüldükçe azalır. Deliğin boyutu direnç değerine karşılık gelir: direnç arttıkça delik daralır. 10 $\Omega$'luk dirençten 1 $\Omega$'luk dirençten daha az akım geçer. Gerilim ise yukarıdaki leğendeki su miktarıdır: direnç sabitken su ne kadar çoksa akış o kadar hızlıdır.

İkisi arasında bir denge vardır:

- Gerilim artarsa akım artar; gerilim azalırsa akım azalır.
- Direnç artarsa akım azalır; direnç azalırsa akım artar.

Hoca direnci bir "dikenli yol" olarak da anlattı: yolda ne kadar çok diken varsa o yoldan geçmek o kadar zordur. 1 $\Omega$ az dikenli, 10 ya da 100 $\Omega$ daha dikenli bir yoldur.

### 17.2 Yasa

Bu benzetme Ohm yasasına götürür (ekrandan, 02:05:00):

$$V = I R$$

Gerilim (volt) eşittir akım (amper) çarpı direnç (ohm). Slayttaki not: bu bağıntı yalnız direnç için kullanılır. İleride AC devrelerde empedans hesabı yapılacak; o zaman $R$ yerine $Z$ gelecek ya da kondansatör akımı gibi farklı ifadeler kullanılacaktır. Ama Norton, Thevenin, süperpozisyon, KCL ve KVL gibi ileride görülecek bütün yöntemlerin temelinde $V = IR$ vardır.

Gerilim sabitken direnç artarsa akım düşer. Hoca ayrıca direnç ve akım arttıkça direnç üzerinde toplanan gerilimin de artacağını, bu gerilimin güç bakımından üretici tarafından karşılanması gerektiğini söyledi.

### 17.3 Örnek: 2 $\Omega$ ve 2 A

Slayttaki örnekte 2 $\Omega$'luk bir dirençten soldan sağa 2 A geçmektedir; sağ ucun gerilimi $x$ volttur (ekrandan, 02:05:00).

- Direnç üzerindeki gerilim düşümü: $V = IR = 2 \cdot 2 = 4$ V.
- Akım sol uçtan girdiğine göre sol uç daha yüksek potansiyeldedir: $x + 4$ volt.

Direnç önceki noktadaki gerilimin 4 V'unu tüketir, geriye $x$ volt kalır. Slayttaki not: teorik olarak elektrik kablosunun direnci 0 $\Omega$'dur.

### 17.4 Örnek: 1 V ve 1 $\Omega$

Slaytta 1 V'luk kaynak ve 1 $\Omega$'luk direnç vardır; üst kablonun gerilimi $x+1$, alt kablonun gerilimi $x$ volttur (ekrandan, 02:10:00). Kablonun her yerinde aynı gerilim olduğu kabulü burada görülür: üst kablonun iki ucu da $x+1$, alt kablonun iki ucu da $x$ volttur. Direnç üzerinde 1 V söner. Hoca tahtaya direncin gücünü yazdı: 1 A geçtiği düşünülürse $P = i\cdot v = +1$ W.

**Soru:** Direnç üzerinde 1 V azalıyor. Burada bir enerji kaybı olmuyor mu, bu enerjinin korunumu yasasına ters değil mi? Enerji yok mu oluyor?
**Cevap:** Enerji direnç üzerinde sönümlenir. Direnç $+1$ W tüketir, kaynak 1 W üretir; kaynağın ürettiğinin hepsini bu direnç tüketir ve toplam sıfırdır.

**Soru:** Bu, oraya bir ampul takmak gibi mi? Ampul 1 V'u tüketir ve sıfıra gider mi?
**Cevap:** Benzer bir durumdur. Oraya bir ampul takılırsa ampul 1 W'lık güçle yanar. "Tüketir" demek bir kez tüketip bitirmesi değildir: kaynak beslediği sürece ampul 1 W tüketmeye ve yanmaya devam eder, besleme kesildiğinde güç sıfıra iner ve ampul söner.

**Soru:** Ampul ile direnç aynı işi mi görür?
**Cevap:** LED ampuller dışında, eski tip akkor ampuller içinde bir direnç bulunan elemanlardır. Enerji o özel direncin üzerinde sönümlenir; ısıya, ısı da ışığa dönüşür. Bu devrede 1 W'lık enerjiyi tüketen eleman ampuldür. Gerçek hayatta kabloların uzunluğu ve tesisatın yalıtımı gibi etkenler de vardır, ama teoride kabloda sönüm yoktur; rezistif etki yalnız dirençtedir.

### 17.5 Birden fazla direnç

Hoca birden fazla direncin kullanıldığı bir durumu da anlattı: kaynağın ürettiği güç, dirençler arasında değerlerine göre paylaşılır. Örneğin 1 W üretim varsa ($-1$ W), dirençlerden biri 0.5 W tüketiyorsa diğeri de kalan 0.5 W'ı tüketmek zorundadır. Üniversiteye hazırlık sorularındaki "hangi ampul daha parlak yanar?" türü soruların mantığı da budur: seri bağlı ampuller enerjiyi ortaklaşa tüketir ve her biri daha sönük yanar. Paralel bağlantı ilerideki derslerde incelenecek; hepsi enerji dengesi üzerinden analiz edilecek.

### 17.6 Toprak bağlantısı ve açık devre

Bir ucu toprağa bağlanan devrede toprak tarafı 0 V, diğer taraf 1 V olur; direnç gerilimi üzerinde toplar. Hoca kapalı devre oluşturmayan (açık) bir örnekte de bir ucun toprak olduğu için 0 V olduğunu söyledi. Açık uçta 1 V okunabilmesi için ölçü aletinin bir probu o noktaya, diğer probu toprağa bağlanmalıdır; ölçü aleti bir referans noktası almalıdır. Bu durumda devreyi ölçü aleti tamamlar ve 1 V okunur; aksi halde açık devrede 1 V okunamaz. Toprak tarafına bağlanan ölçü aleti ise 0 V okur.

## 18. Negatif Gerilim ve Akım, Ölçü Aletlerinin Bağlanması

### 18.1 Negatif gerilim ve akım

Slayttaki şekilde (ekrandan, 02:15:00) üst kutuplu "2 V" ile ters kutuplu "$-2$ V" aynı şeydir; sağa doğru 1 A ile sola doğru $-1$ A da aynı şeydir. Bir pili ters takmak $-9$ V vermek demektir. Hoca bunu bir direnç ve voltmetreyle anlattı: 2 V'luk bir kaynak dirence bağlanınca akım bir yönde akar. Voltmetrenin probları kaynağın kutuplarıyla aynı yönde bağlanırsa 2 V, ters yönde bağlanırsa $-2$ V okunur. Gerilimin eksi çıkması ters bağlanmış olduğu anlamına gelir. Akım için de aynısı geçerlidir.

### 18.2 Voltmetre ve ampermetre

- **Gerilim ölçümü:** Voltmetre, gerilimi ölçülecek elemana **paralel** bağlanır.
- **Akım ölçümü:** Ampermetre devreye **seri** bağlanır.

Aynı devrede ampermetre ters yönde bağlanırsa okunan değer zıt işaretli olur, çünkü akımın yönü aletin yönüne göre terstir. Akımın yönü gerilim kaynağının artı-eksi uçlarına göre belirlenir; hoca bunun ilerideki sorularda daha iyi oturacağını söyledi.

## 19. Pasif İşaret Kuralı ve Örnek

Güç $P = VI$, birimi watt'tır. Kutuplanmış bir elemanın uçlarında:

- Akım artı uçtan giriyorsa eleman tüketir; gücü $+P$ watt yazılır.
- Akım artı uçtan çıkıyorsa (eksi uçtan girip artı uçtan çıkıyorsa) eleman üretir; gücü $-P$ watt yazılır.

Slayttaki özet (ekrandan, 02:25:00): tüketilen (absorb) gücün işareti artı, üretilen (generate) gücün işareti eksidir.

### 19.1 Örnek: 10 V ve 4 k$\Omega$

Slaytta 10 V'luk bir gerilim kaynağı ve 4 k$\Omega$'luk bir direnç vardır (ekrandan, 02:20:00).

**Akım:** Ohm yasasından

$$V = IR \;\Rightarrow\; 10 = 4\times10^{3}\cdot I \;\Rightarrow\; I = \frac{10}{4000} = 2.5\times10^{-3}\ \text{A} = 2.5\ \text{mA}$$

Burada kilo öneki $10^{3}$ olarak yerine yazılmıştır.

**Yön ve kutuplar:** Kaynağın kutuplarına göre akım artı uçtan çıkar ve devreyi saat yönünde dolaşır. Devrede başka eleman olmadığı için kaynağın ürettiği gücü direnç tüketir. Tüketen elemanlarda akım artı uçtan girip eksi uçtan çıktığı için direncin akımın girdiği üst ucu artı, alt ucu eksi işaretlenir.

**Güç:**

$$P = V\cdot I = 10 \cdot 2.5\times10^{-3} = 25\times10^{-3}\ \text{W} = 25\ \text{mW}$$

Kaynak 25 mW üretir ($-25$ mW), direnç 25 mW tüketir ($+25$ mW); toplam sıfırdır.

**Soru:** $R$ yerine $4\times10^{3}$ yazdınız; sonuçtaki $10^{-3}$ nereden geldi, $10^{-2}$ olmuyor mu?
**Cevap:** Paydadaki $10^{3}$ paya geçince $10^{-3}$ olur: $10 / (4\times10^{3}) = 2.5\times10^{-3}$. Sonuç 2.5 olarak yazıldığı için üs $-3$'tür; 0.25 yazılsaydı $0.25\times10^{-2}$ denebilirdi.

## 20. Kaynaklar da Güç Tüketebilir

Ders sonunda bir öğrencinin isteğiyle güç üreten ve tüketen elemanların listelendiği slayta dönüldü. Güç üreten (generate) elemanlar bağımsız gerilim kaynakları, bağımlı gerilim kaynakları ve akım kaynakları olabilir. İleride görüleceği gibi kondansatör ve bobin de bir süre güç üretebilir. Güç tüketen (absorb) elemanlarda direnç kesindir; kondansatör de güç tüketebilir.

Asıl karışıklık şuradadır: bağımsız ya da bağımlı gerilim ve akım kaynakları da yeri geldiğinde güç tüketebilir. Örneğin ters bağlanmış bir kaynak. Hoca birkaç kaynak ve bir direnç içeren bir devre çizdi ve akımı $I$ ile bir yönde işaretledi. Bu akım yönüne göre akımın artı ucundan çıktığı kaynaklar güç üretir; akımın artı ucundan girdiği direnç ve ters bağlanmış kaynak ise güç tüketir, çünkü o kaynakta akımın yönüyle kutupları arasında bir zıtlık vardır. Hatta bazı durumlarda bir direnç bile (daha güçlü bir kaynak tarafından önceden kutuplanmışsa) üretici gibi görünebilir; bu ileride ayrıntılı incelenecek.

> **Hocanın vurgusu:** Artı-eksi işaretleri hem akımın yönünü hem de bir elemanın güç üretip üretmediğini belirlediği için kritik öneme sahiptir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:55:00): İki farklı yükseklikten bırakılan iki su damlasından hangisi yere daha büyük kuvvetle çarpar?

> **Çözüm:** Daha yüksekten bırakılan damla. Potansiyel enerjisi daha büyüktür; bu enerji kinetik enerjiye dönüştüğünde çarpma etkisi daha büyük olur. Elektrik potansiyeli de damlanın referans zeminden (topraktan) yüksekliğine benzetilir.

**Soru 2** (derste sözlü, 01:04:12): Değeri $5V_1$ olan bir gerilim kontrollü gerilim kaynağında $V_1 = 5$ V ise kaynağın gerilimi nedir?

> **Çözüm:** $5V_1 = 5\cdot 5 = 25$ V.

**Soru 3** (ekrandan, 01:10:00): 3 A'lik bağımsız bir akım kaynağı, üzerinde 1 V düşen bir elemana doğrudan bağlanmıştır. Kaynağın ve elemanın gücü nedir?

> **Çözüm:** Akım kaynağın artı ucundan çıkar, elemanın artı ucundan girer. Kaynak: $P = -(3\cdot 1) = -3$ W (üretir). Eleman: $P = +3$ W (tüketir). Toplam sıfırdır.

**Soru 4** (derste sözlü, 02:01:36): Bir kapalı devrede elemanların güçleri $-2$ W, $+3$ W ve $+5$ W'tır. Dördüncü elemanın gücü ne olmalıdır? <!-- BELİRSİZ: Karesi yok; +5 W değeri altyazıdan çıkarıldı. -->

> **Çözüm:** $-2 + 3 + 5 + P_x = 0 \Rightarrow P_x = -6$ W; dördüncü eleman 6 W üretir.

**Soru 5** (ekrandan, 02:05:00): 2 $\Omega$'luk bir dirençten 2 A geçmektedir ve akımın çıktığı ucun gerilimi $x$ volttur. Akımın girdiği ucun gerilimi nedir?

> **Çözüm:** $V = IR = 2\cdot 2 = 4$ V; akımın girdiği uç $x + 4$ volttur.

**Soru 6** (ekrandan, 02:20:00): 10 V'luk bir gerilim kaynağına 4 k$\Omega$'luk bir direnç bağlanmıştır. Akımı ve kaynağın ürettiği, direncin tükettiği gücü bulun.

> **Çözüm:** $I = 10 / (4\times10^{3}) = 2.5\times10^{-3}$ A $= 2.5$ mA. $P = 10\cdot 2.5\times10^{-3} = 25$ mW. Kaynak $-25$ mW (üretir), direnç $+25$ mW (tüketir).

## Dersin Toparlaması

Bu ilk derste devre teorisinin dili kuruldu. Önce birimlerin ve SI öneklerinin önemi, birim dönüştürme adımları, yuvarlama, bilimsel ve mühendislik gösterimi anlatıldı. Ardından elektriğin elektronların hareketiyle oluştuğu, elektrik akımının elektron akımının tersi yönünde olduğu ve akım için potansiyel fark ile kapalı devre gerektiği su benzetmeleriyle açıklandı. Devre elemanları tanıtıldı: bağımsız ve bağımlı kaynaklar (VCVS, CCVS, VCCS, CCCS), direnç, bobin, kondansatör, toprak, kablo, anahtar, sigorta ve AWG kablo standardı. Ders boyunca geçerli olacak kabuller (kayıpsız kablo, ideal kaynak, 0 V toprak) ortaya kondu.

Son bölümde yük, akım ($i = dq/dt$), gerilim ($v = dw/dq$), güç ($p = vi$) ve enerji ($w = \int p\,dt$) tanımlandı; pasif işaret kuralı (tüketilen güç artı, üretilen güç eksi) ve enerjinin korunumu ($\sum P = 0$) verildi. Ohm yasası ($V = IR$) örneklerle uygulandı. Hoca bir sonraki derste direncin malzemeye, kesite ve uzunluğa bağlılığının ayrıntısına girileceğini; Kirchhoff akım ve gerilim yasalarının da bu güç dengesi fikri üzerine kurulacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
