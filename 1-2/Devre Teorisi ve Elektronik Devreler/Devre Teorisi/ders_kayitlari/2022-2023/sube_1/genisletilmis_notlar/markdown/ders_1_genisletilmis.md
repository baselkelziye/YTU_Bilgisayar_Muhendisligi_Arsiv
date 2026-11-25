# Ders 1 Genişletilmiş Notu: Devre Teorisine Giriş: SI Birimleri, Yük-Akım-Gerilim-Güç, Devre Elemanları ve AC/DC İşaretler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Devre teorisi nedir: soyutlama katmanları
- 2. Dersin kapsamı: analiz ve tasarım
- 3. SI birim sistemi, önekler ve birim dönüşümü
- 4. Anlamlı basamak, doğruluk ve yuvarlama
- 5. Elektrik akımı ve elektron akımı
- 6. Referans gerilim (toprak) ve düğüm gerilimi
- 7. Devre bileşenleri: aktif ve pasif elemanlar
- 8. Ölçü aletleri, kablo, anahtar ve sigorta
- 9. Bağımsız kaynaklar ve güç işareti
- 10. Bağımlı kaynaklar
- 11. Pasif elemanlar ve DC davranışları
- 12. Toprak sembolleri, kablolar ve tanım bağıntısı
- 13. Akım akışı kuralları ve Ohm yasasına giriş
- 14. Yük, akım, DC ve AC işaretler
- 15. Gerilim, güç ve enerji

## 1. Devre teorisi nedir: soyutlama katmanları

Elektriksel ve manyetik olayların hepsini açıklayan temel teori elektromanyetik dalga teorisidir. Bu teori bir dalga denkleminin çözümünü gerektirir: denklem hem zamana hem de konuma ($x$, $y$, $z$) bağlı bir diferansiyel denklemdir. Küçük bir problem için bile uğraştırıcıdır; büyük ölçekte çözmek pratikte çok zordur.

Bu yüzden katmanlı bir soyutlama önerilmiştir. Basit elemanlardan karmaşık yapılara doğru her seviye bir "kara kutu" (black box) olarak tanımlanır: içinin nasıl çalıştığıyla uğraşılmaz, yalnız uçlarındaki davranış tarif edilir.

- **Birinci seviye: devre elemanları.** Direnç, aslında elektromanyetik alan denklemleriyle çözülebilecek bir yapıdır. Ama devre teorisinde yalnız şöyle tanımlanır: uçlarına uygulanan gerilim ile üzerinden geçen akım, direnç değeriyle orantılıdır. Bu tanım deneyden gelir; belirli bir değer aralığında elemanın doğrusal olduğu ve gerilim/akım oranının sabit kaldığı görülür.
- **Lojik kapılar.** İleride Lojik Devreler dersinde görülecek kapılar, içinde çok sayıda transistör ve kapasite barındırır; ama kapı seviyesinde yalnız giriş-çıkış davranışıyla tanımlanır.
- **Entegre devreler.** Bir ALU pek çok kapıdan oluşur; kara kutu olarak bakıldığında A ve B ikili sayılarını alıp toplamını yine ikili sayı olarak üreten bir bloktur.
- **Daha üst seviyeler.** Mikroişlemci, mikrodenetleyici, alt sistem ve sistem seviyeleri de aynı mantıkla soyutlanır.

Devre teorisi, en temel fiziksel gerçeklik olan elektromanyetik dalga teorisinden gelen çözümlemeleri bir seviye yukarı taşır ve tekil, basit devre elemanlarının davranışını tanımlar.

## 2. Dersin kapsamı: analiz ve tasarım

Ders şu sırayla ilerler:

- Temel, basit devre elemanları ve bunların DC kaynaklar altındaki davranışı.
- Enerji depolayan elemanlar (kapasite ve endüktans). Önce uzun süre kaynağa bağlı kaldıktan sonraki **sürekli hal**, sonra kaynağın bağlandığı andaki **geçici hal** incelenir. İlk enerjisi olan ve olmayan durumlar ayrı ayrı ele alınır.
- RL ve RC devreleri birinci dereceden, RLC devreleri ikinci dereceden diferansiyel denklem üretir. Diferansiyel denklem dersi henüz görülmemiş olsa da çözüm yöntemi altyapısıyla birlikte verilecektir.
- AC (sinüzoidal) kaynaklı devreler. Zaman domeninde çözüm diferansiyel denklemlere götürür. Sabit frekanslı sinüzoidal kaynak olduğunda **fazör uzayına** geçilir; orada elemanlar basit cebirsel bağıntılarla tanımlanır ve AC devre analizi kolaylaşır.
- Devre teoremleri: karmaşık bir devrenin çözümünü basitleştiren yöntemler. Hem zaman domeninde hem fazör uzayında tekrar edilir; hangi yöntemin hangi devreye uygun olduğu tartışılır.
- İşlemsel kuvvetlendirici (op-amp). Devre teorisi yalnız iki uçlu elemanlar için değil, $N$ terminalli herhangi bir eleman için tanımlanabilir; op-amp böyle çok terminalli bir eleman olarak tanım bağıntısından hareketle çözümlenecektir.
- Zaman kalırsa süzgeç (filtre) tasarımı ve analizi.

Dersin bir hedefi de **tasarımdır**. Analizde bir devre verilir ve davranışı çözülür; tasarımda bir gereksinim verilir ve onu sağlayan devre kurulur.

**Örnek (tasarım fikri):** Elimizde 12 V'luk bir kaynak var, 5 V'a ihtiyacımız var. En basit çözüm bir gerilim bölücüdür. Ancak gerilim bölücü güç kaybı yüksek, verimsiz bir çözümdür; elektronik devreler de işin içine girdiğinde daha verimli çözümler kurulabilir.

## 3. SI birim sistemi, önekler ve birim dönüşümü

Derste SI birim sistemi kullanılır. Temel birimler:

| Büyüklük | Birim |
|---|---|
| Uzunluk | metre (m) |
| Kütle | kilogram (kg) |
| Zaman | saniye (s) |
| Akım | amper (A) |
| Sıcaklık | kelvin (K) |
| Yük | coulomb (C) |

Bir hesap yapılırken bütün değerler temel birimlere çevrilmelidir. Örneğin öz direnç hesabında uzunluk metre, kesit alanı metrekare cinsinden olmalıdır.

### 3.1 Önekler

Çok büyük ve çok küçük değerler, temel birimin önüne 10'un kuvvetini gösteren bir önek getirilerek yazılır (ekrandan, 00:55:00):

| Çarpan | Önek | Sembol |
|---|---|---|
| $10^{18}$ | exa | E |
| $10^{15}$ | peta | P |
| $10^{12}$ | tera | T |
| $10^{9}$ | giga | G |
| $10^{6}$ | mega | M |
| $10^{3}$ | kilo | k |
| $10^{2}$ | hecto | h |
| $10$ | deka | da |
| $10^{-1}$ | deci | d |
| $10^{-2}$ | centi | c |
| $10^{-3}$ | milli | m |
| $10^{-6}$ | micro | $\mu$ |
| $10^{-9}$ | nano | n |
| $10^{-12}$ | pico | p |
| $10^{-15}$ | femto | f |
| $10^{-18}$ | atto | a |

Slayttaki örnekte aynı uzaklık üç biçimde yazılmıştır: 600 000 000 mm = 600 000 m = 600 km (ekrandan, 00:55:00). Derste en sık karşılaşılacak aralık mili-, mikro-, nano- ve piko- ile kilo-, mega- gibi binerli adımlardır; deka ve hekto 10 ve 100 kat için kullanılır.

### 3.2 Birim dönüşümü örneği

Hız, mesafe bölü zamandır. Çıktı birimi belirtilmemişse SI'da m/s kullanılır; belirtilmişse o birime dönüştürülür.

**Örnek:** 4000 m'lik mesafeyi 1 dakikada kat eden bir cismin hızı km/h cinsinden nedir?

- Verilen: $d = 4000$ m, $t = 1$ dk.
- Dönüşüm: $4000\ \text{m} = 4\ \text{km}$, $1\ \text{dk} = \dfrac{1}{60}\ \text{h}$.
- İşlem: $v = \dfrac{4\ \text{km}}{1/60\ \text{h}} = 240\ \text{km/h}$.

### 3.3 Birimlerin fiziksel tanımları

Bazı birimler sabit bir fiziksel gerçekliğe dayanarak tanımlanır. Saniye önce bir günün belirli bir kesri olarak tanımlanmıştı; bu tanım yeterince kararlı olmadığı için sezyum atomunun belirli sayıda (yaklaşık 9 milyar) titreşimine dayalı bir tanıma geçildi. Bu titreşim ortam koşullarından neredeyse etkilenmediği için standart bir tanım sağlar.

## 4. Anlamlı basamak, doğruluk ve yuvarlama

Slayttaki ayrım (ekrandan, 01:00:00):

- **Tam sayılar (exact):** sayılarak elde edilir, örneğin 12 elma.
- **Yaklaşık sayılar (approximate):** laboratuvarda okunan her değer yaklaşık kabul edilmelidir.
- **Hassasiyet (precision):** bir okumada bulunan anlamlı basamak sayısıyla belirlenir.
- **Doğruluk (accuracy):** ölçülen değerin standart ya da bilinen değere yakınlığıdır.
- Yaklaşık sayılarda uygun doğruluk düzeyine karar verilip sonuç yuvarlanır. Örnek: $3.186 \cong 3.19 \cong 3.2$.

Yuvarlama kuralı: atılacak basamak 5 ve üzerindeyse bir önceki (daha anlamlı) basamak bir artırılır; 0-4 arasındaysa önceki basamak olduğu gibi bırakılır. Çok küçük değerlerle çalışırken de en az iki anlamlı basamak korunmalıdır.

**Bilimsel gösterim:** birler basamağında bir rakam, ondalık noktadan sonra en az iki anlamlı basamak ve değeri koruyan $\times 10^{n}$ çarpanı. Örneğin bir elektronun yükü $1.60 \times 10^{-19}$ C gibi yazılır.

## 5. Elektrik akımı ve elektron akımı

Bir potansiyel fark olduğunda elektronlar bir bölgede yoğun, başka bir bölgede seyrektir. Bu fark, elektronların yer değiştirmesiyle eşitlenmeye çalışır. Elektron negatif yüklü olduğu için az elektron bulunan tarafa doğru gider.

Slayttaki çizim (ekrandan, 01:05:00): bir atom, iki pozitif yüklü çekirdek ve çevresinde iki elektronla gösterilmiştir. Bir iletken içinde elektronlar bir atomdan diğerine kaydığında, elektronlarını kaybeden atomlar net pozitif yüklü kalır. Elektronlar bir yöne giderken, sanki pozitif yükler ters yöne gidiyormuş gibi bir durum oluşur; "electricity" oku bu sanal pozitif yük hareketinin yönünü gösterir.

Bu soyutlama seviyesinde:

- Elektron akışı ile elektrik akımının yönü terstir.
- Dış devrede elektronlar negatif terminalden pozitif terminale akarken, elektrik akımı pozitif terminalden negatif terminale doğru tanımlanır.

Gerçek fiziksel durum tam olarak bu kadar basit değildir; bu, devre teorisinin seçtiği soyutlamadır.

**Soru:** Pilin içinde elektronlar hangi yönde hareket eder? **Cevap:** Dış devrede (kabloda ve dirençte) elektronlar eksi terminalden artı terminale gider. Pilin içinde ise artı terminal elektronları iter; net elektron yer değiştirmesinin pozitif terminalden negatif terminale doğru olduğu kabul edilebilir. Böylece dış devredeki elektron akışı, tanımlanan akım yönünün tersinde olur.

### 5.1 Su ve yükseklik analojisi

Hoca akımı kinetik ve potansiyel enerji ikilisiyle açıkladı:

- Potansiyel enerji için bir seviye farkı gerekir. Su ne kadar yüksekten dökülürse yere çarptığındaki hızı o kadar büyük olur. Bu, bir elemanın uçlarına uygulanan elektrik potansiyeline karşılık gelir: potansiyel ne kadar yüksekse akım o kadar büyük olur.
- Dökülen su miktarı ne kadar fazlaysa akan su da o kadar fazladır. Bu da serbest elektron miktarına karşılık gelir. Serbest elektron miktarı malzemenin öz direnciyle ilişkilidir: malzeme elektronlarını ne kadar kolay serbest bırakıyorsa akım o kadar artar.

Sonuç olarak akımı iki şey birlikte belirler: elektronların ne kadar serbest olduğu ve onları hareket ettirmek için ne kadar büyük bir potansiyel uygulandığı.

Elektrik potansiyeli, birim yükü belirli bir mesafe hareket ettirmek için harcanması gereken enerjidir. Potansiyel ne kadar yüksekse sabit mesafede o kadar çok yük hareket ettirilebilir ya da aynı yük o kadar uzun mesafe taşınabilir.

## 6. Referans gerilim (toprak) ve düğüm gerilimi

Slayt (ekrandan, 01:10:00): Yükseklik normalde deniz seviyesine göre ölçülür. Benzer şekilde bir noktanın elektrik potansiyeli de toprağın (ground) potansiyeline göre ölçülür. Gerilimin birimi volttur (V) ve toprak her zaman 0 V'tur.

### 6.1 Neden tek bir referans?

İki terminalli bir eleman, örneğin bir direnç düşünelim. Her iki ucu için bir gerilim seviyesi tanımlanabilir. Uçlardan biri referans kabul edilirse diğer ucun gerilimi doğrudan elemanın uçlarına uygulanan gerilimi verir. Bunu bütün elemanlara yaydığımızda, birbirine seri ya da paralel bağlı elemanların referansları birbirine bağımlı hale gelir. Çok sayıda referans koymak yerine bütün devre için tek bir sabit referans seçip bütün terminal gerilimlerini ona göre ifade etmek yeterlidir.

Top analojisi: Bir topun hızını, bırakıldığı seviye ile düştüğü seviye arasındaki fark belirler. Bu iki seviye başka bir genel referansa (toprak) göre de tanımlanabilir. Buradan iki kavram çıkar:

- **Düğüm gerilimi:** bir noktanın genel referansa göre gerilimi.
- **Eleman gerilimi:** bir elemanın iki terminali arasındaki gerilim farkı, yani iki düğüm geriliminin farkı.

Referans 0 V seçilir. Referans 10 V seçilseydi sonuç değişmezdi, ama her düğüm için 10 V çıkarma işlemi yapmak gerekirdi; 0 V seçmek bu fazladan işi ortadan kaldırır.

### 6.2 Derste sorulan soru: iki ayrı referanslı devre

**Soru (derste sözlü, 01:12:13):** Birbirine bağlı olmayan iki devre olsun. Her biri kendi referansına göre (her birinde kendi referansı 0 V kabul edilerek) sorunsuz çözülebiliyor. Ama mutlak olarak bu iki referans farklı seviyelerde. Bu iki devre birbirine kaskat bağlanacak (birinin çıkışı diğerinin girişi olacak) olursa iki farklı referans sistemi ortaya çıkar. Bu sorun nasıl giderilir?

Öğrencilerden gelen öneriler tartışıldı:

- Aradaki farkı devrelerden birinin bütün düğümlerinden çıkarmak: hesap olarak mümkün, ama hoca iki ayrı referans tutmak yerine tek bir referans istiyor.
- Devrelerin dışında "evrensel" üçüncü bir referans seçmek: bu kez üç referans olur, istenen bu değil.
- İki referansın ortasını almak: yine bütün elemanlardan bir değer çıkarmak gerekir.

**Cevap:** İki devrenin toprakları (GND) bir kabloyla birbirine bağlanır. Böylece ikisi aynı seviyeye gelir ve tek bir ortak referans oluşur. Referans seviyesi farklı devre bloklarıyla çalışırken bunları ortak referansa getirmenin yolu topraklarını birleştirmektir. Sohbetten gelen bir cevap buna çok yaklaşmıştı.

**Soru:** Toprakları birleştirmek tam olarak ne demek, bağlayınca ne olur? **Cevap:** Pratikte bir devrenin GND ucu ile diğerinin GND ucu kabloyla bağlanır. Mutlak olarak farklı seviyelerde olan iki referans böylece aynı seviyeye gelir. Örneğin bir devrede yüklü kalmış bir kondansatör o devrenin referansını diğerine göre daha yüksek bir seviyede tutuyor olabilir; iki devre aynı mantıkla çalışabilir durumda olsa da aradaki bu referans farkının bizim için bir anlamı yoktur ve kabloyla bağlanarak yok edilir.

## 7. Devre bileşenleri: aktif ve pasif elemanlar

Slayttaki genel liste (ekrandan, 01:20:00):

- Aktif elemanlar
  - Bağımsız güç kaynakları: gerilim, akım
  - Bağımlı güç kaynakları: gerilim, akım
- Pasif elemanlar
  - Direnç (resistor)
  - Kapasite (capacitor)
  - Endüktans (inductor)
- Ölçü aletleri
  - Ampermetre: akım ölçer
  - Voltmetre: gerilim ölçer
- Toprak (ground): referans noktası
- Elektrik kablosu (electric wire)
- Anahtar (switch)
- Koruma elemanı: sigorta (fuse)

**Aktif ve pasif ayrımı:** Aktif elemanlar devreye güç verir, pasif elemanlar güç tüketir. Notasyon olarak, hesaplandığında gücü negatif çıkan elemanlar aktif (güç veren), gücü pozitif çıkan elemanlar pasif (güç tüketen) olarak değerlendirilir.

> **Hocanın vurgusu:** Gücün işareti elemanın güç verip vermediğini gösterir: negatif güç güç verir, pozitif güç güç tüketir. Bu önemlidir.

Pasif elemanlardan kapasite ve endüktans **ilk enerjiye** sahip olabilir: kapasite devreye yüklü olarak bağlanmışsa ya da endüktans bir ilk akımla bağlanmışsa. Ama net olarak bunlar enerji tüketen elemanlardır.

## 8. Ölçü aletleri, kablo, anahtar ve sigorta

### 8.1 Ampermetre

Ampermetre bir koldan geçen akımı ölçer. Hoca bir gerilim kaynağı, bir direnç ve toprak bağlantısı olan basit bir devre çizdi (ekrandan, 01:25:00):

- Gerilim kaynağı ($+$ üstte), kaynağın üst ucundan bir direnç, direncin ardından ampermetre (daire içinde A) ve dönüş yolu kaynağın alt ucuna bağlı. Alt hatta toprak sembolü var.
- Direncin uçlarına paralel bağlı bir voltmetre (daire içinde V).

Bir kolun akımını ölçmek için o kol kesilir ve ampermetre araya **seri** bağlanır.

**Soru (derste sözlü, 01:22:57):** Ampermetre nasıl bağlanmalı ve iç direnci ne olmalı? **Cevap:** Seri bağlanmalı. Ölçülecek akımı değiştirmemesi için ideal durumda iç direnci sıfır olmalıdır.

### 8.2 Voltmetre

Voltmetre iki terminal arasındaki gerilim farkını ölçer; ölçülen elemana **paralel** bağlanır.

**Soru (derste sözlü, 01:24:34):** Akım en düşük dirençli yolu tercih ettiğine göre, voltmetrenin iç direnci nasıl olmalı? **Cevap:** Akım voltmetreden neredeyse hiç geçmemeli; ideal durumda iç direnci sonsuz olmalıdır.

### 8.3 Eşdeğer devreler

- İç direnci sıfır olan ideal eleman kablo gibidir: ampermetre bir **kısa devre** elemanı gibi çalışır.
- İç direnci sonsuz olan ideal eleman bağlantısı kopuk iki uç gibidir: voltmetre bir **açık devre** elemanı gibi çalışır.

### 8.4 Voltmetre neyi ölçer?

Aynı devrede direncin kaynak tarafındaki düğüm $V_1$, diğer tarafı $V_2$ olsun; ikisi de alt hattaki toprağa (0 V) göre tanımlıdır (ekrandan, 01:30:00). Voltmetrenin ölçtüğü değer $V_1 - V_2$'dir. Bu çizim düğüm gerilimi ile eleman gerilimi arasındaki farkı doğrudan gösterir.

Sohbetten gelen bir soru üzerine hoca şunu açıkladı: Pilin artı ya da eksi ucu belirleyici değildir; belirleyici olan voltmetrenin referans yönleridir. Pratikte voltmetrenin kırmızı (artı ölçme referansı) ve siyah (eksi ölçme referansı) iki probu vardır. Ölçülen değer, kırmızı probun bağlandığı düğümün geriliminden siyah probun bağlandığı düğümün gerilimi çıkarılarak bulunur.

> **Hocanın vurgusu:** $V_1$ düğümünün gerilim kaynağına yakın olması onu daha büyük ya da daha pozitif yapmaz. Bu basit devrede $V_1$ daha büyük olur; ama karmaşık bir devrede $V_2$ başka bir taraftan daha yüksek bir kaynağa yakın olabilir ve voltmetre negatif bir değer okuyabilir. Önceden bir beklenti olmamalıdır.

### 8.5 Kablo

Kablo idealde sıfır iç dirençli bir kısa devre elemanı olarak düşünülür.

### 8.6 Anahtar

Anahtar iki terminalli bir elemandır. Yanında bir ok ve "$t = 0$" yazan anahtar şu anlama gelir: $-\infty$'dan $t = 0^-$ anına kadar anahtar açıktır (bağlantı yok), $t = 0$ anında kapalı konuma gelir. Anahtarlarla özellikle geçici hal ve AC analizinde karşılaşılacaktır. "Açık" ve "kapalı" ifadeleri karışabilir: açık, yolun kesildiği; kapalı, yolun tamamlandığı durumdur.

### 8.7 Sigorta

Sigorta direnç benzeri bir sembolle gösterilir ve üzerinde dayanabileceği akım değeri yazar. Görevi akım korumasıdır. Devre belirli akımlarla çalışacak şekilde tasarlanmıştır; gürültü, anlık yüklenme gibi sebeplerle akım aniden artarsa elemanlar zarar görebilir. Akım sınırı aştığında sigorta yanar ve akım sağlayan kısmı devreden ayırır.

- Normalde kısa devre elemanı gibi çalışır.
- Taşıyabileceğinden fazla akımda yanarak açık devre elemanı olur.

**Soru (derste sözlü, 01:31:35):** Koruma işlevini yapabilmesi için sigorta koruyacağı elemana nasıl bağlanmalı? **Cevap:** Seri.

## 9. Bağımsız kaynaklar ve güç işareti

### 9.1 İdeal gerilim ve akım kaynağı

Slayt (ekrandan, 01:35:00):

- **Bağımsız gerilim kaynağı**, ne kadar akım gerekirse gereksin devreye DC ya da zamanla değişen bir gerilim verir.
- **Bağımsız akım kaynağı**, ne kadar gerilim gerekirse gereksin devreye DC ya da AC bir akım verir.

> **Hocanın vurgusu:** İdeal gerilim kaynağının devreye verdiği gerilim sabittir, ama ucundan çekilen akımı bağlandığı devre belirler. İdeal akım kaynağının verdiği akım sabittir, ama uçlarındaki gerilimi bağlandığı devre belirler.

**Semboller:**

- Pil (DC kaynak) sembolünde uzun çizgi pozitif, kısa çizgi negatif terminaldir.
- Daire içindeki gerilim kaynağı sembolünde $+$ ve $-$ terminaller mutlaka belirtilmelidir. İki sembol de geçerlidir ve DC kaynağı gösterir.
- Bağımsız akım kaynağı daire içinde bir okla gösterilir; ok, kaynağın devreye verdiği akımın yönüdür.
- AC gerilim kaynağı ayrı bir sembolle (daire içinde sinüs) gösterilir.

**Soru:** Slayttaki "time varying" ne demek? **Cevap:** Zamana göre değişen kaynak, yani AC kaynaktır. DC kaynak $t$ anında açıldıktan sonra sabit bir $V_0$ verir; zamanla değişen kaynak ise örneğin sinüzoidal bir işaret verir. Dersin büyük kısmı DC kaynaklarla, sonraki kısmı AC kaynaklarla ilerleyecektir.

### 9.2 Örnek 1: akım kaynağı ve eleman

Devre (ekrandan, 01:40:00, 01:45:00 ve 02:05:00):

```text
      +-----------+
      |           |
     (↑) 3 A    [eleman]  + üstte
      |           |       1 V
      |           |       - altta
      +-----------+
```

- 3 A'lik bağımsız akım kaynağı (ok yukarı) ile kırmızı gösterilen bir eleman paralel bağlıdır.
- Elemanın uçlarında, üst uç $+$ olacak şekilde, 1 V gerilim düşümü vardır. Eleman varsayımsal bir elemandır; bu devrede gerilimi sabit 1 V'tur (voltmetrenin kırmızı probu üst uca, siyah probu alt uca bağlanmış ve $+1$ V okunmuş gibi düşünülebilir).

**Adım 1: akım kaynağının gerilimi.** Eleman ile akım kaynağı paralel olduğu için akım kaynağının uçlarında da aynı yönde 1 V vardır. Yani akım kaynağının gerilimini bağlı olduğu eleman belirlemiştir.

**Adım 2: akım kaynağının gücü.** Kaynağın verdiği 3 A, kaynağın gerilim referansının $-$ ucundan girip $+$ ucundan çıkar. Slayttaki pasif işaret kuralı: akım bağımsız akım kaynağının üzerindeki gerilim düşümünün $+$ ucundan çıkıyorsa güç şöyledir:

$$p = -3\ \text{A} \cdot (1\ \text{V}) = -3\ \text{W}$$

Hoca bunu tahtada şöyle de gösterdi: akım yönünde kaynağın üzerinden geçerken kat edilen gerilim $-1$ V'tur, yani $3\ \text{A}\cdot(-1\ \text{V}) = -3$ W. Amper çarpı volt güç birimidir (watt). Negatif güç, kaynağın devreye 3 W güç verdiğini gösterir.

**Adım 3: elemanın gücü.** Aynı 3 A, kırmızı elemanın $+$ ucundan girip $-$ ucundan çıkar. Slayttaki kural: akım elemanın üzerindeki gerilim düşümünün $+$ ucundan giriyorsa

$$p = 3\ \text{A} \cdot (1\ \text{V}) = 3\ \text{W}$$

Pozitif güç, elemanın 3 W tükettiğini gösterir.

**Adım 4: enerjinin korunumu.**

$$\sum p = p_{\text{akım kaynağı}} + p_{\text{eleman}} = -3 + 3 = 0\ \text{W}$$

Bu kapalı çevrimde tek bir güç üreten ve tek bir güç tüketen eleman vardır; dışarıdan enerji girip çıkmadığı için güçlerin toplamı sıfır olmalıdır ve öyledir.

Bu örnekten çıkan sonuçlar:

- Bir bağımsız kaynağın uçlarındaki gerilimi diğer elemanlar belirler.
- Bağımsız kaynakların gücünün negatif çıkması normaldir; bu, kaynağın devreye güç verdiğini gösterir.
- Güç veren elemanların gücü negatif, güç harcayanlarınki pozitiftir.

**Soru:** Eksi 3 W ile artı 3 W toplanınca neden sıfır oluyor? (Ara sonrası öğrenci sorusu, 02:01:50) **Cevap:** Hoca yukarıdaki adımları tekrar etti: akım kaynağı için akım, gerilim referansının $-$ ucundan $+$ ucuna doğru akar ve güç $-3$ W olur; eleman için akım $+$ ucundan $-$ ucuna akar ve güç $+3$ W olur. Kapalı çevreye dışarıdan enerji girmediği ve çıkmadığı için toplam güç sıfırdır.

### 9.3 Gücü pozitif çıkan bağımsız kaynak

**Soru (derste sözlü, 01:42:29):** Birden fazla bağımsız kaynağın bulunduğu karmaşık bir devrede, bağımsız kaynaklardan birinin gücü pozitif çıkabilir. Bunun anlamı nedir? Pratikte bir örnek verilebilir mi?

**Cevap:** Pozitif güç, o kaynağın güç tükettiği anlamına gelir. Pratik örnek şarj edilebilir piltir: bir LED'e bağlandığında devreye enerji verir ve LED'i yakar; şarj cihazına bağlandığında uçlarındaki gerilim hâlâ vardır, ama şarj olur, yani enerji tüketir. Sohbetten gelen powerbank örneği de doğrudur.

## 10. Bağımlı kaynaklar

Bağımlı kaynak bir gerilim kaynağı ya da bir akım kaynağı gibi çalışır. Farkı, devreye verdiği değerin devrenin başka bir kolundaki ya da noktasındaki bir akım veya gerilime bağlı olmasıdır.

- Bağımsız kaynaklar daire, bağımlı kaynaklar **eşkenar dörtgen** (baklava) sembolüyle çizilir.
- Bağımlı gerilim kaynağında $+$ ve $-$ terminaller işaretlenir; bağımlı akım kaynağında verdiği akımın yönü okla gösterilir.

Dört tür bağımlı kaynak vardır:

| Tür | Kontrol eden büyüklük | Örnek değer | İngilizce adı |
|---|---|---|---|
| Gerilim kontrollü gerilim kaynağı | başka yerdeki gerilim | $k\,V_x$ | Voltage Controlled Voltage Source (VCVS) |
| Akım kontrollü gerilim kaynağı | başka yerdeki akım | $k\,I_1$ | Current Controlled Voltage Source (CCVS) |
| Gerilim kontrollü akım kaynağı | başka yerdeki gerilim | $k\,V_x$ | Voltage Controlled Current Source (VCCS) |
| Akım kontrollü akım kaynağı | başka yerdeki akım | $k\,I_2$ | Current Controlled Current Source (CCCS) |

> **Ders sonrası not:** Hoca akım kontrollü gerilim kaynağını tanımlarken bir yerde "bağlı olduğu noktaya akım sağlayan bir eleman" dedi; doğrusu, bu kaynak başka bir koldaki akımla orantılı bir **gerilim** sağlar (söz sürçmesi; aynı derste sonradan doğru tanım verildi).

### 10.1 Ara sonrası tekrar: bağımlı kaynaklı bir devre

Öğrencilerin isteği üzerine hoca aradan sonra bağımlı kaynakları bir devre üzerinden tekrar anlattı (02:05:49 civarı). Çizilen devrede sırasıyla bir bağımsız gerilim kaynağı, bir direnç, ikinci bir direnç, bir bağımlı akım kaynağı, üçüncü bir direnç ve son olarak bir bağımlı gerilim kaynağı vardı. <!-- BELİRSİZ: devrenin tam bağlantı şekli (hangi elemanların seri, hangilerinin paralel olduğu) altyazıdan çıkarılamadı; bu anın karesi yok. -->

- Bir koldaki akıma $I_1$, bir direncin gerilim düşümüne $V_1$ dendi.
- Değeri $k\,V_1$ olan akım kaynağı (ok işaretinden akım kaynağı olduğu anlaşılır): başka bir noktadaki gerilime bağlı akım verir, yani **gerilim kontrollü akım kaynağıdır**.
- Değeri $m\,I_1$ olan gerilim kaynağı: başka bir koldaki akımla orantılı gerilim verir, yani **akım kontrollü gerilim kaynağıdır**.
- Akım kaynağının değeri $n\,I_2$ gibi bir akım olsaydı **akım kontrollü akım kaynağı**, gerilim kaynağının değeri $t\,V_2$ gibi bir gerilim olsaydı **gerilim kontrollü gerilim kaynağı** olurdu.

## 11. Pasif elemanlar ve DC davranışları

### 11.1 Pasif elemanlarda enerji

Slayt (ekrandan, 02:10:00): Pasif elemanlardaki gerilim düşümünün ve akımın büyüklüğü, devrede bulunan ya da yakın zamanda bağlanmış gerilim ve akım kaynaklarına bağlıdır. Bu elemanlar gücü hemen harcayabilir ya da geçici olarak depolayıp daha sonra devreye geri verebilir.

- Direncin enerji depolama özelliği yoktur.
- Kapasite daha önce yüklenmişse belirli bir yüke sahiptir; devreye o haliyle bağlanırsa bir ilk enerjisi olur.
- Endüktans sargılardan oluşur; o an sargılarda dolaşan akım nedeniyle bir ilk enerjisi olabilir.
- Bu ilk enerji, ilk koşul olarak devrede etki gösterir. Anlık olarak enerji depolanabilir, ama nihai olarak pasif elemanlar enerji tüketir.

### 11.2 Pil ve akım kaynağı (öğrenci soruları)

**Soru:** Pil akım kaynağı mı, gerilim kaynağı mı? **Cevap:** Pil ideal olmayan bir bağımsız gerilim kaynağıdır. AA kalem pilin üzerinde 1.5 V yazar; ideal olsaydı devreye her zaman 1.5 V verirdi. Ama pilin bir iç direnci vardır: fazla akım çekilmeye çalışıldığında bu iç direnç enerjinin bir kısmını tüketir, gücün bir kısmı içeride ısı olarak harcanır ve tamamı dışarı aktarılamaz.

**Soru:** Gerilim kaynağına pil örnek oluyorsa akım kaynağına ne örnek olur? **Cevap:** Akım kaynağı, devreye sabit akım verebilen elektronik devrelerle elde edilir. Örneğin akım aynası, genel bir ifadeyle bir noktadaki akımı başka bir noktaya birebir kopyalayan bir elektronik devredir ve aynaladığı nokta için sabit bir akım sağlar. Akım kaynağı pil gibi hazır bir eleman olarak görülmez. Ayrıca ayarlı güç kaynakları (power supply) sabit akım modunda bağımsız akım kaynağı, sabit gerilim modunda bağımsız gerilim kaynağı gibi düşünülebilir.

Bir öğrenci yorumu üzerine hoca şunu ekledi: İdeal olmayan bir gerilim kaynağının gerilimi, çekilen akımla birlikte biraz düşer. Ama bu iki kavram karıştırılmamalıdır: gerilimi sabit kalmayan bir gerilim kaynağı, iç direnci yüzünden akım kaynağı sayılmaz.

### 11.3 Pasif elemanların sembolleri ve birimleri

Slayt (ekrandan, 02:15:00):

| Eleman | Sembol | Birim |
|---|---|---|
| Direnç (resistor) | zikzak (üçgen dişli) çizgi | ohm ($\Omega$) |
| Endüktans (inductor) | art arda yarım çemberler (sargılar) | henry (H) |
| Kapasite (capacitor) | karşılıklı iki paralel plaka | farad (F) |

### 11.4 DC kaynağa bağlı endüktans ve kapasite

**Soru (derste sözlü, 02:14:44):** Bir endüktansın uçlarına DC bir gerilim kaynağı bağlanıp belirli bir süre beklenirse, endüktansın uçlarına bağlanan voltmetre ne okur?

**Cevap:** Sıfır. Endüktans sarılmış bir teldir; DC şartlarda kısa devre gibi davranır. Sembolü de bunu çağrıştırır.

AC kaynak bağlansaydı durum değişirdi: endüktans bu kez dirence benzer bir davranış gösterir ve geçirdiği akım zamana göre farklılık gösterir.

**Soru:** AC'de endüktans neden direnç gösterir? **Cevap:** Endüktansın tanım bağıntısında üzerinden geçen akım ile uç geriliminin integrali arasında doğrusal bir ilişki vardır. AC işarette gerilim değiştikçe akım onu geriden izleyerek değişir; akım ile gerilim arasında bir fark oluşur ve bu fark dirence benzer bir davranışa yol açar. DC şartlarda bu davranışa direnç denir; AC şartlarda ise **empedans** denir (hoca önce "endüktans" deyip "empedans" diye düzeltti). Aynı durum kapasite için de geçerlidir.

> **Ek bilgi (derste anlatılmadı):** Endüktansın tanım bağıntısı $v = L\,\dfrac{di}{dt}$, yani $i(t) = \dfrac{1}{L}\int v\,dt$ biçimindedir. DC kararlı halde $di/dt = 0$ olduğu için $v = 0$ olur; bu da kısa devre davranışını açıklar. Bu bağıntılar ileriki haftalarda ayrıntılı işlenecektir.

**Soru (derste sözlü, 02:17:53):** Bir kapasiteye DC bir işaret bağlanıp belirli bir süre beklendikten sonra uçlarına voltmetre bağlanırsa ne ölçülür?

**Cevap:** Sıfır olmaz, sonsuz da olmaz; kapasitenin uçlarına kaç voltluk bir kaynak bağlandıysa o değer okunur. Kapasitenin sembolü açık devre gibidir; uzun süre sonra kapasiteden akım geçmez, devredeki başka elemanlarda gerilim düşümü olmaz ve voltmetre aslında gerilim kaynağının uçlarını ölçer.

> **Hocanın vurgusu:** Endüktans DC şartlarda kısa devre gibi, kapasite DC şartlarda açık devre gibi davranır. Şematik semboller bu davranışı da tanımlar; not edilmeli.

## 12. Toprak sembolleri, kablolar ve tanım bağıntısı

### 12.1 Diğer temel devre elemanlarının sembolleri

Slayt (ekrandan, 02:20:00):

- **Kablo:** düz bir çizgiyle gösterilir; idealde iç direnci sıfırdır.
- **Toprak:** farklı semboller vardır: earth, chassis, ground (içi boş üçgen), ground (dolu üçgen), analog ground, digital ground. Karmaşık sistemlerde analog toprak, dijital toprak ya da iki sistem arasındaki şase gibi birden fazla referans olabilir. Derste kullanılacak sabit referans earth sembolüdür (yatay çizgileri aşağı doğru kısalan sembol).
- **Anahtar:** açık (open) durumda kontak kalkıktır; kapalı (closed) durumda kontak yolu tamamlar.
- **Sigorta:** IEEE/ANSI standardında dikdörtgen, IEC standardında içinden çizgi geçen dikdörtgen, başka bir IEEE/ANSI gösteriminde iki yuvarlak uç arasında dalgalı çizgi ve eski sembolde iki yuvarlak arasında çapraz bir şekil.

Slayt (ekrandan, 02:25:00): Earth ground, fiziksel olarak toprağın kendisine bağlı topraktır; evlerde evin hemen yanında toprağa çakılmış metal bir boruya bağlanan bir kablo vardır ve yeşil kılıflı ya da çıplak bakır kablolar bu boruya bağlanır. Referans toprak ya da ortak uç (common) ise devrede gerilimin sıfıra eşit olduğu noktayı göstermek için kullanılır.

### 12.2 Kablo seçimi

Pratik sistemlerde kablolama önemlidir. Yüksek akım çekilmesi muhtemel durumlarda, örneğin yüksek akım verebilen bir lityum-polimer (LiPo) pilden besleme yapılırken, çekilecek akımı taşıyabilecek kesit alanına sahip kablolar kullanılmalıdır. Bunun için standartlar vardır; en bilineni AWG standardıdır. Standart numaraya göre kablonun kalınlığı ve taşıyabileceği akım değişir. Uyulmazsa, uzun süre çalışan bir sistemde kapasitesinden yüksek akım taşıyan kabloların dış kaplamaları ısınır ve yanık kokusu duyulabilir. Bu yüzden sistemdeki akımlar belirlenip uygun kesitte kablolar seçilmelidir.

> **Ek bilgi (derste anlatılmadı):** AWG (American Wire Gauge) numarası büyüdükçe kablo incelir; yani küçük AWG numarası daha kalın ve daha yüksek akım taşıyabilen kabloyu gösterir.

### 12.3 Tanım bağıntısı ve terminal sayısı

Çok terminalli bir elemanın terminallerinden biri referans tutulup diğer bütün gerilimler ona göre tanımlanabilir; potansiyel enerjinin bir yer seviyesine göre belirlenmesi gibi.

**Soru (derste sözlü, 02:24:04):** İki terminalli bir elemanın kaç tanım bağıntısı olmalıdır?

**Cevap:** Bir. Tanım bağıntısı, bir elemanın uçlarındaki akım ve gerilim değerleri arasındaki ilişkiyi veren denklemdir. Direnç için uç gerilimi akıma bölündüğünde elemana özgü sabit bir değer elde edilir; gerilim artırılırsa akım da artar ama oran sabit kalır:

$$\frac{V}{I} = R$$

Açıklama (öğrencinin tekrar istemesi üzerine): Direncin iki ucu vardır; elemanı tanımlamak için ilk bakışta $V_1$, $I_1$, $V_2$, $I_2$ değerlerini içeren denklemler gerekir.

- Bir uçtan giren akım diğer uçtan çıkan akıma eşittir ($I_1 = I_2$); bu bir değişkeni eler.
- $V_1$ ve $V_2$ için iki ayrı bağıntı gerekmez: $V_1 - V_2$ farkı akıma oranlanınca tek bağıntı yeter.
- Gizli ikinci bağıntı, $V_2$'nin referans (0 V) kabul edilmesidir.

Genelleme: $N$ terminalli bir eleman için $N-1$ ayrık tanım bağıntısı yeterlidir. $N$'inci bağıntı, terminallerden birinin 0 V referans seçilmesiyle arka planda kendiliğinden ortaya çıkar. Üç terminalli eleman için iki, on terminalli eleman için dokuz tanım bağıntısı yeterlidir.

Kapasite de iki terminalli bir elemandır, dolayısıyla tek bir tanım bağıntısı yeterlidir:

$$q = C\,v \quad\Longrightarrow\quad \int i\,dt = C\,v$$

Burada yük, zamana göre birikmiş akım olarak düşünülmüştür.

### 12.4 Genel kurallar

- İdeal bir kablonun, kesintisiz olduğu sürece herhangi iki noktası arasındaki gerilim her zaman sıfırdır. (Örnek 1'deki devrede kablonun iki ucu arasında 0 V ölçülür; elemanın iki ucu arasındaki 1 V ise kabloyla değil elemanla ilgilidir.)
- İdeal gerilim kaynağı, bağlı olduğu noktalarda devreye yazılı değerinde gerilim sağlar.
- İdeal akım kaynağı, bağlı olduğu noktadan devreye yazılı değerinde akım sağlar.
- Referans her zaman 0 V alınmak zorunda değildir, ama 0 V almak mantıklıdır; aksi halde eleman sayısı kadar çıkarma işlemi gerekir.

## 13. Akım akışı kuralları ve Ohm yasasına giriş

Slayt (ekrandan, 02:35:00), "Electric Flow Rule":

- Bir yol varsa elektrik akımı yüksek gerilimden düşük gerilime akar.
- Akım elektrik kablosundan serbestçe geçebilir.
- Akım bir dirençten, Ohm yasasının belirlediği miktarda geçer.
- Akım bir gerilim kaynağından, devredeki diğer elemanlara bağlı miktarda geçer.
- Akım bir akım kaynağından, kaynağın değeri kadar geçer.

Akım daha düşük dirençli, daha serbest geçebileceği yolu tercih eder. Paralel bağlı dirençlerde büyük dirençten küçük, küçük dirençten büyük akım geçer; bu, çözülen devrelerde sonucu kontrol etmek için kullanılabilir.

Bir direncin uçlarına bağlanan gerilim kaynağının değeri artırılırsa akım artar, azaltılırsa akım azalır ve bu değişim gerilimdeki değişimle birebir orantılıdır. Dolayısıyla bir direnç için uç gerilimi ile akımın oranı o elemana özgü sabit bir değerdir: direnç değeri. Bu Ohm yasasına girişti.

Deneyler şunu da gösterir:

- Aynı malzemeden daha uzun bir parça kullanılırsa direnç artar, daha kısa bir parça kullanılırsa azalır.
- Kesit alanı küçüldükçe direnç artar, büyüdükçe azalır.
- Bunların yanında malzemenin kendi özelliği olan **öz direnç** etkilidir: malzemenin elektronlarını ne kadar kolay serbest bıraktığı.

> **Ek bilgi (derste anlatılmadı):** Bu ilişkiler $R = \rho\,\dfrac{L}{A}$ formülüyle ifade edilir; $\rho$ öz direnç ($\Omega\cdot$m), $L$ uzunluk (m), $A$ kesit alanı (m$^2$). Formül sonraki derslerde işlenecek konular arasındadır.

**Soru (derste sözlü, 02:35:03):** Yalnız pasif elemanlardan oluşan karmaşık bir devrede tek aktif eleman bir gerilim kaynağıysa, kaynaktan geçen akımı ne belirler? **Cevap:** Gerilim kaynağı kendi üzerinden geçecek akımı belirleyemez; akımı devredeki diğer elemanlar belirler. Akım kaynağında ise tersi geçerlidir: kaynağın verdiği akım devre ne olursa olsun yazılı değerdedir, ama üzerindeki gerilim düşümünü bağlı olduğu diğer elemanlar belirler.

> **Hocanın vurgusu:** "Bir gerilim kaynağının akımı ve gerilimi bulunduğu devreden bağımsız olarak sabittir" diye bir ön kabul kesinlikle olmamalıdır. İdeal durumda yalnız gerilimi sabittir.

## 14. Yük, akım, DC ve AC işaretler

### 14.1 Yük

Yük, atom mertebesindeki pozitif ve negatif yüklü parçacıklar arasındaki etkileşimi tanımlayan kavramdır. Bir elektronun taşıdığı yük $1.6 \times 10^{-19}$ C'dir.

**Notasyon:** Ders boyunca büyük harfler ($V$, $I$, $Q$) zamanla değişmeyen DC büyüklükleri gösterir. Küçük harfler ($v(t)$, $i(t)$, $q(t)$) zamana bağlı değişen büyüklükleri gösterir; parantez içindeki $t$ bazen yazılmayabilir.

### 14.2 Akım

Akım, birim zamandaki net yük değişimidir. Kapalı bir yüzeyden içeri giren ve dışarı çıkan yüklerin birim zamandaki net miktarı akım olarak adlandırılır. Yük coulomb, zaman saniye cinsinden olduğu için akımın birimi C/s, yani amperdir (ekrandan, 02:40:00):

$$i = \frac{dq}{dt} \qquad \left(\text{ayrık zamanda } \frac{\Delta q}{\Delta t}\right)$$

Aynı ilişki integral biçiminde de yazılabilir: $dt$ karşı tarafa alınıp iki tarafın integrali alınırsa, $t_1$ ile $t_2$ arasındaki net yük akımın integraline eşittir:

$$Q = \int_{t_1}^{t_2} i\,dt$$

### 14.3 DC ve AC

- **DC (direct current):** değeri zamana bağlı değildir. Örneğin $V_1$ adlı bir gerilim kaynağının değeri 1 V ise, hangi anda bakılırsa bakılsın 1 V'tur.
- **AC (alternating current):** zamana bağlı değişen büyüklüktür ve küçük harfle yazılır. Hocanın örneği:

$$v_1(t) = 10\sin\!\left(2\pi \cdot 1000\, t + \frac{\pi}{2}\right)$$

Burada $f = 1000$ Hz seçilmiştir; ifade $t$'ye bağlı olduğu için zamanla değişir.

### 14.4 Sinüzoidal işaretin parametreleri

Hoca bir beyaz tahta üzerinde, temel işaret olarak $5\sin(10t)$ alıp üç karşılaştırma yaptı (ekrandan, 02:45:00 ve 02:50:00).

**Karşılaştırma 1: DC bileşen.** İkinci işaret, birincinin yukarı kaydırılmış haliydi.

- Soru (derste sözlü, 02:43:25): Bu iki işaret arasındaki fark nedir? İkinci işaretin içinde de $5\sin(10t)$ terimi var mı?
- Cevap: Evet, var; ikinciye sabit bir değer eklenmiştir. $5\sin(10t)$ işareti $-5$ ile $5$ arasında değişir. Minimum değeri sıfıra taşımak için $+5$ eklenir:

$$v(t) = 5 + 5\sin(10t)$$

- $5$ bu işaretin **DC bileşeni**, $5\sin(10t)$ ise **AC bileşenidir**. Bir işaret içinde DC ve AC bileşen birlikte bulunabilir.
- DC bileşenin bir başka tanımı: işaretin bir periyottaki ortalaması. Saf sinüsün bir periyodunun yarısı pozitif, yarısı negatiftir; altında kalan alanlar toplanınca sıfır olur, yani sinüzoidal işaretin ortalaması sıfırdır. Yukarı kaydırılmış işaretin ortalaması ise sinüs bileşeninden 0, DC bileşenden 5 olmak üzere 5 V'tur.

**Karşılaştırma 2: genlik ve frekans.** İkinci işaret daha yüksek bir değere kadar salınıyor ve daha yavaş değişiyordu.

- Genlik değişmiştir: alttaki işaret $-5$ ile $5$ arasında değişirken üstteki daha yüksek bir tepe değerine çıkar.
- Frekans azalmıştır: işaretin $0$ ile $2\pi$ arasını geçmesi, yani bir periyodu tamamlaması daha uzun sürer. Bu yüzden $t$'nin katsayısı küçülmelidir; hoca "$5t$ gibi bir şey" dedi.

<!-- BELİRSİZ: ikinci işaretin genlik değeri altyazıda net değil ("10, 5 farklı bir değere kadar"); hoca genliği değiştirmek istemediğini ama çizimde değiştiğini söyledi. -->

**Karşılaştırma 3: faz.** İkinci işaret birinciyle aynı genlik ve aynı frekansa sahipti, yalnız zamanda kaymıştı. Tahtadaki ifadeler: $5\sin(10t + \phi)$ ve $5\sin(10t)$ (ekrandan, 02:50:00).

- Zamandaki kayma faz açısı olarak ortaya çıkar.
- Normalde $t = 0$'da $\sin(0) = 0$'dır; faz eklenince $t = 0$'da $\sin(\phi)$ elde edilir. Sinüsün sıfıra gelmesi için farklı bir zaman geçmesi gerekir; iki işaret birbirini ileri-geri bir şekilde takip eder.

Böylece sinüzoidal bir işaretin dört parametresi tanımlanmış oldu: **DC bileşen, genlik, frekans ve faz açısı**.

> **Ek bilgi (derste anlatılmadı):** $A\sin(\omega t + \phi)$ biçimindeki bir işarette $\omega$ açısal frekanstır (rad/s) ve periyot $T = 2\pi/\omega$'dır. Örneğin $5\sin(10t)$ için $T = 2\pi/10 \approx 0.628$ s, $5\sin(5t)$ için $T \approx 1.257$ s'dir; katsayı küçülünce periyot uzar.

## 15. Gerilim, güç ve enerji

### 15.1 Gerilim

Gerilim (potansiyel), bir birim yükü belirli bir mesafe hareket ettirmek için gereken enerjidir. Potansiyel ne kadar yüksekse bir birim yükü o kadar uzağa hareket ettirebilir. Bu yüzden potansiyel farkı, enerjideki değişimin yükteki değişime oranı olarak ifade edilir:

$$v = \frac{dw}{dq}$$

### 15.2 Güç

Güç, birim zamandaki enerji tüketimidir. İfade $dq$ ile çarpılıp bölünerek yeniden düzenlenirse:

$$p = \frac{dw}{dt} = \frac{dw}{dq}\cdot\frac{dq}{dt} = v\,i$$

Birinci çarpan birim yük başına harcanan enerji, yani gerilim; ikinci çarpan birim zamandaki net yük değişimi, yani akımdır. Örnek 1'de kullanılan "güç = akım çarpı gerilim" ifadesi burada tam tanımıyla verilmiş oldu.

### 15.3 Enerji

Enerji, belirli bir zaman aralığında harcanan toplam güçtür; gücün o aralıktaki integralidir (ekrandan, 02:55:00):

$$w = \int_{t_1}^{t_2} p\,dt = \int_{t_1}^{t_2} v\,i\,dt$$

Slayta göre elektrik şirketinin sayaçta ölçtüğü enerji birimi kilowatt-saattir: $1\ \text{kWh} = 3.6\ \text{MJ}$ ($1000\ \text{W} \times 3600\ \text{s} = 3.6 \times 10^{6}$ J; ara adım eklendi).

## Örnek Sorular

**Soru 1** (ekrandan, 01:40:00 ve 01:45:00): 3 A'lik bağımsız akım kaynağı (ok yukarı), uçlarında 1 V gerilim düşümü olan bir elemana ($+$ üstte) paralel bağlıdır. Akım kaynağının ve elemanın güçlerini bulun; enerjinin korunduğunu gösterin.

> **Çözüm (derste verildi):** Paralel bağlantı nedeniyle akım kaynağının uçlarında da 1 V vardır. Akım kaynağın $+$ ucundan çıktığı için $p_{\text{kaynak}} = -3\ \text{A}\cdot 1\ \text{V} = -3$ W (güç verir). Akım elemanın $+$ ucundan girdiği için $p_{\text{eleman}} = 3\ \text{A}\cdot 1\ \text{V} = 3$ W (güç tüketir). $\sum p = -3 + 3 = 0$ W.

**Soru 2** (derste sözlü, 00:56:07): 4000 m'lik mesafeyi 1 dakikada kat eden bir cismin hızı kaç km/h'tir?

> **Çözüm (derste verildi):** $4000$ m $= 4$ km, $1$ dk $= 1/60$ h; $v = 4 / (1/60) = 240$ km/h.

**Soru 3** (derste sözlü, 01:12:13): Ayrı referanslarla çalışan iki devre birbirine kaskat bağlanacaksa referans farkı nasıl giderilir?

> **Çözüm (derste verildi):** İki devrenin toprakları (GND) bir kabloyla birleştirilir; böylece tek bir ortak referans oluşur.

**Soru 4** (derste sözlü, 01:22:57 ve 01:24:34): Ampermetre ve voltmetre devreye nasıl bağlanır, ideal iç dirençleri ne olmalıdır?

> **Çözüm (derste verildi):** Ampermetre seri bağlanır, ideal iç direnci sıfırdır (kısa devre). Voltmetre paralel bağlanır, ideal iç direnci sonsuzdur (açık devre).

**Soru 5** (derste sözlü, 01:31:35): Sigorta koruyacağı elemana nasıl bağlanmalıdır?

> **Çözüm (derste verildi):** Seri.

**Soru 6** (derste sözlü, 01:42:29): Birden fazla bağımsız kaynaklı bir devrede bir bağımsız kaynağın gücü pozitif çıkarsa bu ne anlama gelir? Pratik bir örnek verin.

> **Çözüm (derste verildi):** Kaynak güç tüketiyordur. Örnek: şarj olan şarj edilebilir pil ya da powerbank.

**Soru 7** (derste sözlü, 02:14:44 ve 02:17:53): DC bir gerilim kaynağına uzun süre bağlı kalmış bir endüktansın ve bir kapasitenin uçlarında voltmetre ne okur?

> **Çözüm (derste verildi):** Endüktansta 0 V (kısa devre gibi davranır); kapasitede kaynak gerilimi (açık devre gibi davranır).

**Soru 8** (derste sözlü, 02:24:04): İki terminalli bir eleman için kaç tanım bağıntısı gerekir? $N$ terminalli eleman için?

> **Çözüm (derste verildi):** İki terminalli eleman için bir ($V/I = R$ gibi); $N$ terminalli eleman için $N-1$. Eksik bağıntı, bir terminalin 0 V referans seçilmesiyle sağlanır.

**Soru 9** (derste sözlü, 02:35:03): Yalnız pasif elemanlı bir devrede tek aktif eleman bir gerilim kaynağıysa, kaynaktan geçen akımı ne belirler?

> **Çözüm (derste verildi):** Devredeki diğer elemanlar. Gerilim kaynağı yalnız gerilimini sabit tutar.

**Soru 10** (ekrandan, 02:45:00; derste sözlü, 02:43:25): $5\sin(10t)$ işareti, minimumu 0 olacak şekilde yukarı kaydırılırsa denklemi ne olur? İki işaretin DC bileşenleri nedir?

> **Çözüm (derste verildi):** $5 + 5\sin(10t)$. Saf sinüsün DC bileşeni (bir periyottaki ortalaması) 0, kaydırılmış işaretinki 5'tir.

## Dersin Toparlaması

Bu ilk derste devre teorisinin, elektromanyetik dalga teorisinin üzerine kurulmuş bir soyutlama katmanı olduğu ve elemanların uçlarındaki akım-gerilim davranışıyla tanımlandığı anlatıldı. SI birimleri ve önekleri, birim dönüşümü, anlamlı basamak ve yuvarlama kuralları hatırlatıldı. Ardından elektrik akımının elektron akışına ters yönde tanımlandığı, gerilimin tek bir 0 V referansa (toprak) göre ölçüldüğü ve eleman geriliminin iki düğüm geriliminin farkı olduğu üzerinde duruldu.

Devre bileşenleri aktif (bağımsız ve bağımlı kaynaklar) ve pasif (R, L, C) olarak ayrıldı; ideal gerilim kaynağının yalnız gerilimini, ideal akım kaynağının yalnız akımını sabit tuttuğu tekrar tekrar vurgulandı. Örnek 1 üzerinden pasif işaret kuralı ve enerjinin korunumu ($\sum p = 0$) gösterildi. Ampermetrenin seri ve kısa devre, voltmetrenin paralel ve açık devre gibi davrandığı; endüktansın DC'de kısa devre, kapasitenin DC'de açık devre olduğu görüldü. $N$ terminalli bir eleman için $N-1$ tanım bağıntısının yeterli olduğu açıklandı. Son olarak $i = dq/dt$, $v = dw/dq$, $p = vi$ ve $w = \int p\,dt$ bağıntıları ile sinüzoidal işaretin dört parametresi (DC bileşen, genlik, frekans, faz) verildi. Ders planına göre sonraki derste Kirchhoff yasaları, seri-paralel bağlama ile gerilim ve akım bölücüler işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
