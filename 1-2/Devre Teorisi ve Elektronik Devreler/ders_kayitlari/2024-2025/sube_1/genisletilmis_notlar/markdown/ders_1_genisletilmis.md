# Ders 1 Genişletilmiş Notu: Ölçü Birimleri, Temel Devre Kavramları, Devre Elemanları ve Ohm Yasası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. Ölçü Birimleri ve SI Önekleri
- 3. Birim Tutarlılığı, Yuvarlama ve Üslü Sayılar
- 4. Bilimsel ve Mühendislik Gösterimi
- 5. Elektrik Akımı ve Su Benzetmesi
- 6. Devre Elemanları ve Ölçü Aletleri
- 7. Bağımsız Kaynaklar, Polarite ve Güç
- 8. Bağımlı Kaynaklar
- 9. Pasif Elemanlar, Kablolar ve İdeal Varsayımlar
- 10. Yük ve Akım
- 11. Doğru Akım ve Alternatif Akım
- 12. Gerilim ve Güç
- 13. Ohm Yasası
- Örnek Sorular

## 1. Dersin Kapsamı

Bu ders, eskiden birinci sınıftaki Devre Teorisi ile ikinci sınıftaki Elektronik derslerinin birleştirilmesiyle oluşturulmuştur. İki dersin konuları azaltılmış ve tek ders içinde daha temel bir seviyede verilecek biçimde düzenlenmiştir. Hoca, dersin bilgisayar mühendisliği öğrencilerinin zorlandığı bir donanım dersi olduğunu, bu yüzden derste soru sormanın önemli olduğunu belirtti.

Dönemin ilk yarısı devre teorisine ayrılmıştır:

- **1. hafta:** Yük, akım, güç, enerji gibi temel kavramlar, devre elemanları ve Ohm yasası (bu ders).
- **2. hafta:** Kirchhoff'un akım yasası (KCL) ve gerilim yasası (KVL), seri-paralel bağlamalar, akım ve gerilim bölücü devreler.
- **3. hafta:** Çevre akımları (mesh) ve düğüm gerilimleri (node) analizi.
- **4. hafta:** Süperpozisyon teoremi, kaynak dönüşümü, Thevenin ve Norton teoremleri (ekrandan, 00:15:00).
- **5. hafta:** Enerji depolayan elemanlar (bobin ve kondansatör), bunların seri-paralel bağlanması ve DC davranışı (ekrandan, 00:15:00).
- **6. hafta:** Kaynaksız RL ve RC devreleri, RL ve RC devre analizi (ekrandan, 00:15:00).
- **7. hafta:** RLC devreleri; aşırı sönümlü, kritik sönümlü ve az sönümlü çözüm (ekrandan, 00:15:00).

Hoca, enerji depolayan elemanların DC ve AC analizinin ikisinin de mümkün olduğunu, ancak bu birleştirilmiş müfredatta alternatif akım analizinin çıkarıldığını, yalnız DC analiz yapılacağını söyledi.

> **Hocanın vurgusu:** KCL ve KVL bütün dönemi etkileyen konudur; elektronik devrelerin analizinde bile kullanılır, mutlaka öğrenilmelidir.

Dönemin ikinci yarısı elektroniktir. Hoca devre teorisi ile elektronik arasındaki temel ayrımı şöyle açıkladı: devre teorisi direnç, bobin, kondansatör gibi iletken elemanlarla, elektronik ise yarı iletken malzemelerle ilgilenir. Bu kısımda yarı iletkenin normal iletkenden farkı, diyot, BJT ve FET (MOSFET dahil) transistörler ve işlemsel yükselteç (op-amp) işlenecektir.

## 2. Ölçü Birimleri ve SI Önekleri

Hoca derse birimlerle başlamasının nedenini, öğrencilerin kiloohm ile megaohm gibi önekli değerleri toplarken, çarparken ya da bölerken sık hata yapması olarak açıkladı.

Dünyada kullanılan birimlerin bir standardı vardır: International System of Units (SI). Bu standart 1960'ta kabul edilmiştir ve temel birimleri tanımlar. Hocanın saydığı birimler şunlardır:

- Uzunluk (mesafe): metre
- Kütle: kilogram
- Zaman: saniye
- Elektrik akımı: amper
- Termodinamik sıcaklık: kelvin (günlük hayatta derece kullansak da bilimsel gösterim kelvindir)
- Işık şiddeti: kandela (monitör ve telefon ekranlarının parlaklığında da görülür)

> **Ders sonrası not:** Hoca yedinci temel birim olarak elektrik yükünü saydı. SI'nin yedinci temel birimi büyük olasılıkla madde miktarıdır (mol). Yükün birimi coulomb türetilmiş bir birimdir: $1\ \text{C} = 1\ \text{A}\cdot\text{s}$.

Bu birimler 10'un kuvvetleriyle ifade edilen öneklerle büyütülüp küçültülür. Örneğin 600 milyon milimetre, 600 bin metre yani 600 kilometredir ($600 \times 10^{6} \times 10^{-3}$ m $= 6 \times 10^{5}$ m). Bu derste en çok kullanılacak önekler şunlardır:

| Önek | Sembol | Çarpan | Derste nerede geçecek |
|---|---|---|---|
| giga | G | $10^{9}$ | gigahertz, gigabayt |
| mega | M | $10^{6}$ | megaohm |
| kilo | k | $10^{3}$ | kiloohm |
| mili | m | $10^{-3}$ | milisaniye, miliamper |
| mikro | $\mu$ | $10^{-6}$ | mikrohenri |
| nano | n | $10^{-9}$ | nanofarad (kondansatör) |
| piko | p | $10^{-12}$ | pikofarad (kondansatör) |

> **Hocanın vurgusu:** Mili ($10^{-3}$) ile mikro ($10^{-6}$) öğrenciler arasında çok karıştırılır.

## 3. Birim Tutarlılığı, Yuvarlama ve Üslü Sayılar

### 3.1 Denkleme doğru birimle değer koymak

Bir denkleme konan sayısal değer, denklemin beklediği birimde olmalıdır (ekrandan, 00:30:00). Slayttaki örnek hız denklemidir: $v = d/t$ ($v$ hız, $d$ mesafe, $t$ zaman). Hareket eden bir cisim için $d = 4000$ m ve $t = 1$ dk ölçülmüş, $v$ ise km/sa cinsinden isteniyor.

- **Yanlış cevap:** $v = 4000 / 1 = 4000$ km/sa. Burada bulunan şey aslında "metre/dakika"dır, istenen birim değildir.
- **Doğru cevap:** Önce taban birimler eşitlenir. Mesafe kilometreye ($4000 \times 10^{-3} = 4$ km), zaman saate ($1/60$ sa) çevrilir: $v = \dfrac{4000 \times 10^{-3}}{1/60} = 240$ km/sa.

Hoca aynı hatanın Ohm yasasında da yapıldığını söyledi: direnç kiloohm, akım kiloamper verilmişse ve ikisi doğrudan çarpılırsa bulunan değer volt olmaz; gerçek sonuç bunun $10^{3} \times 10^{3} = 10^{6}$ katıdır. Değerler önce kendi temel birimlerine getirilip öyle hesaplanmalıdır.

### 3.2 Yuvarlama

Bulunan akım ya da gerilim değeri ondalıklı çıkabilir. Bu değerler istenen hassasiyete göre yuvarlanır; soruda virgülden sonra kaç basamak isteneceği belirtilir. Yuvarlama doğru yapılmalıdır: atılan basamak 5 veya daha büyükse kalan son basamak bir artırılır. Hocanın örneğinde atılan basamak 9 olduğu için değer $3.2$ yazılmalıdır; $3.18$ gibi yanlış yuvarlanmış bir değer beklenen sonuçtan farklıdır. <!-- BELİRSİZ: yuvarlama slaydı karelerde görünmüyor; altyazıda örnek sayılar (0.372, 19, 3.2, 3.18) bozuk geçiyor, örneğin tam metni doğrulanamadı. -->

### 3.3 Üslü sayılarla işlem

Hoca bilinen kuralları hatırlattı:

- Paydadaki $10^{n}$ paya $10^{-n}$ olarak, $10^{-n}$ de $10^{n}$ olarak çıkar.
- Çarpmada üsler toplanır: $10^{a} \cdot 10^{b} = 10^{a+b}$.
- Bölmede üsler çıkarılır: $10^{a} / 10^{b} = 10^{a-b}$.
- Üssün üssünde üsler çarpılır: $(10^{a})^{b} = 10^{ab}$.
- Toplama ve çıkarmada önce 10'un kuvveti ortak yapılmalıdır.

## 4. Bilimsel ve Mühendislik Gösterimi

Sayıları göstermenin iki yaklaşımı vardır (ekrandan, 00:35:00).

**Bilimsel gösterim:** Ondalık noktanın solunda tek bir basamak bulunur ve bu basamak 1 ile 9 arasındadır. Solda 10 yazılamaz; 10 için 1 yazılır, sıfır sağa kaydırılır ve üs bir artırılır. $1/3 = 0.333\ldots$ bilimsel gösterimde solda en az 1 olması gerektiği için $3.33\text{E}{-1}$ diye yazılır.

$$\frac{1}{3} = 3.33\text{E}{-1}, \qquad \frac{1}{16} = 6.25\text{E}{-2}, \qquad \frac{2300}{2} = 1.15\text{E}3$$

**Mühendislik gösterimi:** Üs 3'ün katı olarak seçilir ve noktanın solunda 1 ile 3 basamak bulunur. Böylece değer doğrudan bir önekle okunabilir.

$$\frac{1}{3} = 333.33\text{E}{-3}, \qquad \frac{1}{16} = 62.50\text{E}{-3}, \qquad \frac{2300}{2} = 1.15\text{E}3$$

Hoca, sorularda genellikle bilimsel gösterimi kullandıklarını söyledi.

> **Ders sonrası not:** Hoca mühendislik gösterimini "virgülden sonra 3 basamak" diye anlattı ve $625.0\text{E}{-4}$ yazmanın da çok yanlış olmadığını söyledi. Bu değer sayısal olarak $1/16 = 0.0625$'e eşittir, ancak üs ($-4$) 3'ün katı olmadığı için büyük olasılıkla mühendislik gösterimi sayılmaz. Mühendislik gösteriminin ölçütü üssün 3'ün katı olmasıdır.

## 5. Elektrik Akımı ve Su Benzetmesi

### 5.1 Elektronlar ve akımın yönü

Bir besleme gerilimi olan yerde elektrik akımı oluşur. Malzemenin içindeki elektronlar negatif yüklüdür. Bir uca artı besleme yapıldığında negatif yüklü elektronlar artı uca doğru çekilir; eksi uç ise pozitif yükleri çeker. Elektronların hareket yönü elektron akımını gösterir. Devre teorisinde kullandığımız elektrik akımının yönü ise bunun tam tersidir: elektronlar artıya doğru giderken akım artıdan eksiye doğru akar.

Hoca bunu nötr bir malzemeyle açıkladı: başta iki pozitif yük iki negatif yükle dengededir. Sol tarafa artı yük verilip denge bozulunca negatif yükler o tarafa doğru kayar; elektron akımının tersi yönünde de elektrik akımı oluşur.

> **Ders sonrası not:** Hoca pozitif yükleri "protonlar" ve "holler" (delikler) diye birlikte andı. Metal bir iletkende hareket eden yük taşıyıcıları büyük olasılıkla yalnız elektronlardır, protonlar yerinde kalır. Delik (hole) kavramı yarı iletkenlere aittir ve elektronik kısmında anlatılacaktır.

### 5.2 Potansiyel fark

Elektrik akımı somut değil, soyut bir kavramdır. Bu yüzden akımın nasıl oluştuğunu, şiddetini ve enerjisini yorumlamak için su benzetmesi kullanılır (ekrandan, 00:40:00):

- Su yüksek seviyeden alçak seviyeye akar.
- Elektrik yüksek gerilimden düşük gerilime akar.

İki bardak arasında suyun akması için bir bardağın yukarıdan aşağıdakine boşaltılması gerekir. Aynı şekilde akım oluşması için gerilim farkı olmalıdır. İki nokta arasındaki gerilim farkına **potansiyel fark** denir. Bardak ne kadar yukarıdan boşaltılırsa akış o kadar güçlü olur; potansiyel fark ne kadar büyükse akım da o kadar büyük olur.

Hoca baraj örneğini de verdi: barajdaki su miktarı akışın şiddetini belirleyen birinci parametredir. İkinci parametre deliğin yeridir: delik yukarıda açılırsa akış daha yavaş ve kısa sürer, aşağıda açılırsa daha güçlü olur; bu, potansiyel enerjinin kinetik enerjiye dönüşmesiyle ilgilidir. Farklı yüksekliklerden düşen su damlalarının yere çarpma şiddetleri de farklıdır. Elektrikte de iki nokta arasındaki potansiyel "uçurum" büyüdükçe daha şiddetli bir akım geçer.

Sayısal örnek:

- Bir uçta 10 V, diğer uçta 2 V varsa potansiyel fark $10 - 2 = 8$ V'tur.
- Bir uçta +20 V, diğerinde −20 V varsa potansiyel fark $20 - (-20) = 40$ V'tur.

### 5.3 Referans noktası: toprak

Su örneğinde hep bir referans alınır: ikinci bardağın seviyesi, yer ya da deniz seviyesi. Elektrikte potansiyel farkın referans noktası **toprak (ground)** dur. Bir noktaya "12 V" demek, ölçü aletinin bir ucu o noktadayken diğer ucu toprağa bağlı olduğunda ölçülen değer demektir.

### 5.4 Akımın büyüklüğü

Aynı potansiyel farkta bile kaptaki su azsa düşük akım, su çoksa yüksek akım oluşur (ekrandan, 00:45:00). Akımın birimi **amper (A)** dir. Hocanın özetiyle, su benzetmesinde akım iki şeye bağlıdır: bardaktaki su miktarı ve bardaklar arasındaki yükseklik (potansiyel fark). Akımı şekillendiren üçüncü etken ise devre elemanlarının kendi dirençleridir.

## 6. Devre Elemanları ve Ölçü Aletleri

### 6.1 Sınıflandırma

Devre kurarken kullanılan bileşenler şöyle sınıflandırılır (ekrandan, 00:50:00):

- **Aktif elemanlar (kaynaklar):** Devreyi besleyen elemanlardır.
  - Bağımsız kaynaklar: gerilim kaynağı ve akım kaynağı.
  - Bağımlı kaynaklar: gerilim kaynağı ve akım kaynağı.
- **Pasif elemanlar:** Devredeki enerjiyi tüketen elemanlardır: direnç, kondansatör, bobin (indüktör).
- **Ölçü aletleri:** Ampermetre (akım ölçer), voltmetre (gerilim ölçer). İkisini birden yapan alete avometre denir.
- **Toprak:** Referans noktası.
- **Elektrik kablosu:** Bakır tel kablolar.
- **Anahtarlar** ve **koruma elemanları** (sigorta, fuse).

### 6.2 Ampermetre ve voltmetrenin bağlanması

Hoca, gerilim kaynağı ve dirençten oluşan basit bir devre çizerek anlattı.

**Ampermetre:** Akım, kablonun içinden geçen elektrik akımıdır. Bu akımı ölçmek için ölçü aleti devreye **seri** bağlanır: kablo açılır, aletin iki sivri ucu (prob) araya konur ve akım aletin içinden geçerek devreyi tamamlar. Ancak o zaman amper değeri okunur.

**Voltmetre:** Gerilim, bir elemanın üzerindeki değerdir (örneğin direncin üzerinde ne kadar gerilim düştüğü). Bu yüzden voltmetrenin probları ölçülecek elemana **paralel** bağlanır.

### 6.3 Avometrenin riski

Ampermetre ve voltmetre ayrı cihazlarsa sorun yoktur. Avometrede ise ikisi tek cihazdadır ve ölçüm türüne göre konum seçilir: gerilim için volt, akım için amper konumu. Hoca, yanlış konumda bağlantı yapılırsa (gerilim konumundayken seri ya da akım konumundayken paralel bağlamak) cihazın içindeki koruma sigortasının yandığını, cihaza bir şey olmadığını ama sigortanın değiştirilmesi gerektiğini anlattı.

> **Hocanın vurgusu:** Gerilim ölçerken voltmetre, akım ölçerken ampermetre konumuna getirmek ölçümlerde en çok dikkat edilmesi gereken noktadır.

> **Ek bilgi (derste anlatılmadı):** Ampermetrenin iç direnci çok küçük, voltmetreninki çok büyüktür. Bu yüzden asıl tehlikeli durum büyük olasılıkla akım konumundaki aletin bir elemana paralel bağlanmasıdır: alet neredeyse kısa devre gibi davranır, büyük akım çeker ve sigorta yanar. Gerilim konumundaki alet seri bağlanırsa yüksek iç direnci yüzünden devreden çok küçük akım geçer ve genellikle sigorta yanmaz.

## 7. Bağımsız Kaynaklar, Polarite ve Güç

### 7.1 Sembol

Bağımsız kaynaklar daire içinde gösterilir. Gerilim kaynağında artı ve eksi uç bellidir; akım kaynağında yön bir okla gösterilir. Pil sembolünde uzun çizgi her zaman artıyı, kısa çizgi eksiyi gösterir; üzerinde yazmasa bile böyledir.

### 7.2 Polarite ve pasif işaret kuralı

Bir devrede akım kaynağı ile gerilim kaynağı birlikte bulunabilir. Önemli kavram **polarizasyondur** (kutuplaşma): bir elemandan geçen akımın girdiği uç her zaman artı, çıktığı uç eksi kabul edilir.

Güç, akım ile gerilimin çarpımıdır. İşareti şöyle belirlenir:

- Akım bir elemanın artı ucundan giriyorsa o eleman gücü **tüketir** (absorbe eder). Gücü pozitif yazılır.
- Akım elemanın artı ucundan çıkıyorsa (eksi ucundan giriyorsa) o eleman güç **üretir**. Gücü negatif yazılır.

Hoca bunun "biraz ters mantık" gibi göründüğünü belirtti: üretenler negatif, tüketenler pozitif güçle gösterilir. Bir eleman kaynak bile olsa, akım artı ucundan giriyorsa o devrede tüketici gibi davranır.

### 7.3 Örnek 1: akım kaynağına bağlı eleman

3 A'lik bağımsız akım kaynağı, üzerinde 1 V düşen bir elemana doğrudan bağlıdır (ekrandan, 00:55:00). Akım kaynağının oku yukarı doğrudur; elemanın üst ucu artı, alt ucu eksidir.

- Paralel bağlı oldukları için kaynağın uçlarında da 1 V vardır, elemandan da 3 A geçer.
- Akım elemana artı ucundan girer. Eleman tüketicidir: $p_{\text{eleman}} = 3 \times 1 = +3$ W.
- Akım kaynaktan artı uçtan çıkar. Kaynak üreticidir: $p_{\text{kaynak}} = -3 \times 1 = -3$ W.

### 7.4 Enerjinin korunumu

Bir devrede kaç direnç, akım kaynağı ya da gerilim kaynağı olursa olsun, üreten ve tüketen elemanların güçleri toplamı sıfır olmalıdır. Buna enerjinin korunumu denir. Örnek 1'de $3 + (-3) = 0$ olur. Hoca bununla ilgili ayrıntılı örneklerin KCL ve KVL haftasında yapılacağını söyledi.

## 8. Bağımlı Kaynaklar

Bağımlı kaynakların bağımsızlardan farkı, daire yerine baklava (karo) biçiminde çizilmeleridir (ekrandan, 01:00:00). Akım kaynağında yine ok kullanılır. Üzerinde "5 V" gibi sabit bir değer yazmaz; sabit değer yazsaydı daire biçiminde çizilir ve bağımsız kaynak olurdu.

Üzerinde örneğin $5V_{R1}$ yazar. Bu, kaynağın $R_1$ direnci üzerindeki gerilimin 5 katı kadar gerilim ürettiği anlamına gelir. Kaynağın değerini bilmek için önce $R_1$ üzerindeki gerilim bulunur, sonra 5 ile çarpılır. Akım için de benzer biçimde, devredeki belirli bir akıma bağlı parametreli bir gösterim kullanılır.

Dört bağımlı kaynak türü vardır (ekrandan, 01:00:00):

- Gerilim kontrollü gerilim kaynağı (VCVS)
- Akım kontrollü gerilim kaynağı (CCVS)
- Gerilim kontrollü akım kaynağı (VCCS)
- Akım kontrollü akım kaynağı (CCCS)

## 9. Pasif Elemanlar, Kablolar ve İdeal Varsayımlar

### 9.1 Pasif elemanlar

- **Direnç (resistor):** Sembolü zikzaktır. Birimi ohm, gösterimi $\Omega$.
- **Bobin (indüktör):** Fiziksel olarak sık sarılmış bakır teldir; bunun nedeni akımla manyetik alan oluşturmaktır ve ilgili haftada anlatılacaktır. Sembolü de sarım teli gibidir. İçindeki değere indüktans denir. Birimi henri (H).
- **Kondansatör (kapasitör):** Kutuplu ve kutupsuz (mercimek tipi gibi) türleri vardır. Sembolü iki plakadır; kutuplu gösterim de buna benzer. Birimi farad (F).

Bu elemanların hepsinde önekler kullanılır: milihenri, mikrohenri, kiloohm, megaohm, nanofarad, pikofarad gibi.

### 9.2 Kablolar, toprak, anahtar, sigorta

Toprak sembolünün devre çizimlerinde farklı gösterimleri vardır. Anahtarlar açık-kapalı elemanlardır. Sigorta (fuse), avometrede en çok yanan parçadır.

### 9.3 AWG standardı

Teoride bir kablonun direncinden hiç bahsedilmez; kablo direnci sıfır olan ideal bir iletken (kısa devre) kabul edilir (ekrandan, 01:05:00). Pratikte ise kablonun uzunluğuna bağlı bir direnci vardır.

Kabloların akım taşıma kapasitesi çapına ya da kesit alanına bağlıdır. ABD'de kullanılan **AWG (American Wire Gauge)** standardı kablolara numara verir ve bir kablonun güvenle ne kadar akım taşıyabileceğini derecelendirir (ekrandan, 01:05:00):

- AWG standardı bakır, alüminyum ve diğer tel malzemelerini kapsar.
- Ev tesisatında tipik bakır kablo AWG 12 veya 14'tür.
- Telefon kablosu genellikle 22, 24 veya 26'dır (daha ince ve kırılgan, "zil teli").
- Numara büyüdükçe kablonun çapı küçülür, kablo incelir, direnci artar ve akım taşıma kapasitesi azalır.

Hocanın tablodan okuduğu değerler: AWG 24 kablonun çapı yaklaşık 0.5 mm, direnci metre başına yaklaşık 80 m$\Omega$; AWG 12 kablonun çapı yaklaşık 2 mm, direnci metre başına yaklaşık 5 m$\Omega$; AWG 1 yaklaşık 7 mm çapında, direnci çok düşük ama pratikte kullanımı zor bir kablo; AWG 39'un direnci metre başına yaklaşık 2.5 $\Omega$. Kalın kablonun direnci düşüktür ama dolaştırmak ve monte etmek zordur. <!-- BELİRSİZ: AWG tablosunun karesi yok; değerler altyazıdan alındı. -->

### 9.4 İdeal varsayımlar

Teoride şu kabuller yapılır:

- Kablodan geçen akım sıfır dirençle karşılaşır; bu yüzden bir kablo boyunca bütün noktalarda gerilim aynıdır. Gerçekte kablonun başı ile sonu arasında gerilim farkı olabilir.
- Akım ve gerilim kaynakları üzerlerinde yazan değeri tam olarak üretir. Gerçekte örneğin 9 V'luk bir pil hiçbir zaman tam 9 V vermez, 8.87 V gibi bir değer verebilir.
- Toprak sıfır volt kabul edilir.

## 10. Yük ve Akım

### 10.1 Yük

Yük, atom altı parçacıkların elektriksel özelliğidir (ekrandan, 01:10:00): elektronlar negatif, protonlar pozitif yüklüdür. Bir elektronun yükünün mutlak değeri $1.6 \times 10^{-19}$ C'dir. Yük $Q$ ya da $q$ ile gösterilir.

### 10.2 Büyük ve küçük harf kuralı

Devre teorisinde ve elektronikte bir sembolün büyük ya da küçük harfle yazılması anlam taşır (ekrandan, 01:10:00):

- **Büyük harf:** Kararlı durumdaki (steady-state) ya da sabit değeri gösterir. Kararlı durum kondansatör haftasında ayrıntılı incelenecektir.
- **Küçük harf:** Anlık ya da zamanla değişen değeri gösterir.

### 10.3 Akımın tanımı

Akım, elektron yüklerinin yer değiştirmesiyle oluşur. Bu sözlü tanımın formülü şudur:

$$i = \frac{dq}{dt}$$

Yani akım, yükün zamana göre değişim miktarıdır. Burada bütün harfler küçüktür, çünkü akım yük değişimine bağlı olarak zamanla değişen bir büyüklüktür. Büyük $I$ ise DC (doğru akım) durumunda kullanılır.

> **Hocanın vurgusu:** $i = dq/dt$ formülü önemlidir, bilinmesi gerekir.

Tersinden düşünülürse akımdan yük bulunabilir:

$$Q = \int_{t_1}^{t_2} i\,dt$$

Belirli bir $t_1$-$t_2$ aralığında integral alındığı için sonuç zamandan bağımsız bir yük miktarıdır; bu yüzden büyük $Q$ ile yazılır.

## 11. Doğru Akım ve Alternatif Akım

Hoca, bir besleme ve bir dirençten oluşan devre üzerinden önce polariteyi tekrarladı (ekrandan, 01:15:00): akım kaynağın artı ucundan çıkar ve dirence girdiği uçtan direnç artı polariteli olur. Direnç tüketicidir ($+P$), gerilim kaynağı üreticidir ($-P$).

**Doğru akım (DC):** DC gerilim kaynağıyla oluşturulur; gerilim zamandan bağımsız ve tek düzedir. Örneğin pil 9 V verir ve teoride bu değer zamanla değişmez; dolayısıyla akım da hiç değişmez.

**Alternatif akım (AC):** Gerilim kaynağı zamanla değişir; bir yarım periyotta artı, diğerinde eksi gerilim verir ve bu sürekli tekrarlanır.

Hocanın anlattığı avantajlar:

- DC daha kararlı ve daha kolay devre tasarımı sağlar. Telefon, dizüstü bilgisayar gibi cihazlar şebeke gerilimini 19 V gibi düşük seviyelere indirip DC ile çalışır.
- Uzun mesafelerde DC'yi aynı seviyede tutmak zordur; kablonun da bir direnci olduğu için gerilim mesafe uzadıkça düşer ve araya tekrarlayıcılar gerekir.
- AC'de faz kendini sürekli yeniler; yüksek gerilimde uzak mesafeye gidecek sinyallerde, gürültüden daha az etkilendiği için AC tercih edilir. Fabrikalarda üç fazlı sistemler kullanılır.

> **Ders sonrası not:** Hocanın "uzun mesafede DC'nin korunması zor" açıklaması tarihsel tercihi anlatıyor. Şebekede AC'nin yaygınlaşmasının ana nedeni büyük olasılıkla transformatörle gerilimin kolayca yükseltilip düşürülebilmesidir. Günümüzde çok uzun mesafeli iletimde yüksek gerilim DC (HVDC) hatları da kullanılmaktadır.

## 12. Gerilim ve Güç

### 12.1 Gerilim

Gerilim en basit hâliyle potansiyel farktır; iki nokta arasında bir fark varsa gerilimden söz edilebilir. Hoca bunu iki bataryayla gösterdi: 5 V'luk iki pil aynı uçları karşı karşıya gelecek biçimde bağlanırsa iki tarafta da 5 V olduğu için aralarında potansiyel fark yoktur; bu durumda gerilim sıfırdır.

Potansiyel fark, yük farklılığı olduğunda oluşur. Yük farklılığı varsa yükler bir yerden bir yere hareket eder ve bu hareket bir enerji ortaya çıkarır. Birim yük başına bu enerji değişimi gerilimdir:

$$v = \frac{dw}{dq} \quad (\text{J/C} = \text{V})$$

<!-- BELİRSİZ: hoca bu büyüklüğü "elektromotiv güç ... indiktif güç" diye adlandırdı; altyazı bozuk. Doğru terim büyük olasılıkla elektromotor kuvvettir (emk). -->

### 12.2 Gücün türetilmesi

Güç, enerjinin zamana göre değişimidir ve birimi watt (W) dur (ekrandan, 01:20:00). Zaman geçtiği hâlde enerji harcanmıyorsa güç sıfırdır. Zincir kuralıyla:

$$p = \frac{dw}{dt} = \frac{dw}{dq}\cdot\frac{dq}{dt} = v\,i$$

Buradaki $\dfrac{dq}{dt}$ akımdır (bölüm 10.3), $\dfrac{dw}{dq}$ ise gerilimdir (bölüm 12.1). $dq$ terimleri sadeleşir. Yani $P = VI$ formülü aslında "zamandaki enerji" tanımından çıkar.

> **Hocanın vurgusu:** $P = VI$ formülü bilinir, ama bu formülün buradan çıktığını bilmek konuları anlamak için önemlidir.

> **Ders sonrası not:** Hoca toparlarken "$V \cdot I$'yı $dV/dt$'den buluyoruz" dedi; doğrusu $p = dw/dt$'dir ($w$: enerji).

### 12.3 Güç işaretinin tekrarı ve korunum örneği

Akım bir elemanın artı ucundan giriyorsa (eşdeğer olarak eksi ucundan çıkıyorsa) eleman tüketicidir ve gücü artı işaretlidir. Akım artı ucundan çıkıyorsa (eksi ucundan giriyorsa) eleman üreteçtir ve gücü negatif işaretlidir. Bütün devrenin güçleri toplandığında enerjinin korunumundan sonuç sıfır olmalıdır.

Hocanın slayttaki örneği: bir bileşenin gücü $-2$ W'tır, dolayısıyla üreteçtir. Diğer iki bileşen tüketicidir ve toplam tüketim 8 W'tır. Toplamın sıfır olması için kalan bileşen $8 - 2 = 6$ W üretmelidir, yani gücü $-6$ W'tır. <!-- BELİRSİZ: bu slaydın karesi yok; iki tüketicinin tek tek değerleri altyazıdan okunamadı. -->

## 13. Ohm Yasası

### 13.1 Su benzetmesiyle Ohm yasası

Slayttaki devre 1 V'luk bir kaynak ve 1 $\Omega$'luk bir dirençten oluşur; akım kaynağın artı ucundan çıkıp devreyi dolaşır, direncin akımın girdiği ucu artıdır (ekrandan, 01:25:00). Yanında üstte bir kap, altta başka bir kap ve aralarında dar bir delikten akan su çizilmiştir. Hoca şu soruları sordu: "V'yi artırmak neye karşılık gelir? R'yi artırmak neye karşılık gelir?"

- **V'yi artırmak:** Üstteki suyu artırmak ya da kabı daha yukarıya kaldırmak.
- **R'yi artırmak:** Bir öğrenci "suyun aktığı deliği küçültmek" diye cevap verdi; hoca bunu onayladı. Delik daraldıkça su daha az akar.

Buradan $V = I \cdot R$ yasasına varılır:

- $R$ sabitken $V$ artırılırsa akım artar.
- $V$ sabitken $R$ artırılırsa akım azalır (delik daralır).
- $V$ sabitken $R$ azaltılırsa akım artar (delik genişler).

### 13.2 Sayısal örnek

10 V'luk kaynağa 4 k$\Omega$'luk bir direnç bağlıdır. Akım kaynağın artı ucundan çıkıp devreyi dolaşır; direncin akımın girdiği ucu artıdır. $I$ isteniyor. <!-- BELİRSİZ: bu örneğin karesi yok; değerler altyazıdan alındı. -->

- Verilen: $V = 10$ V, $R = 4\ \text{k}\Omega = 4 \times 10^{3}\ \Omega$ (kilo önekini temel birime çevirmek gerekir).
- İşlem: $I = \dfrac{V}{R} = \dfrac{10}{4 \times 10^{3}} = 2.5 \times 10^{-3}$ A.
- Sonuç: $I = 2.5$ mA.

Güçler:

- Kaynak (üreteç): $p = -V \cdot I = -10 \times 2.5\ \text{mA} = -25$ mW.
- Direnç (tüketici): $p = I^{2} R = (2.5 \times 10^{-3})^{2} \times 4 \times 10^{3} = +25$ mW (aynı sonuç $V \cdot I$ ile de bulunur).
- Toplam: $-25 + 25 = 0$.

> **Ders sonrası not:** Hoca güçleri hesaplarken bir an "artı 25 watt" ve "burası da artı 25 watt" dedi. Doğrusu direnç için $+25$ mW, kaynak için $-25$ mW'tır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Hareket eden bir cisim için $d = 4000$ m ve $t = 1$ dk ölçülmüştür. $v = d/t$ hızını km/sa cinsinden bulunuz.

> **Çözüm (derste verildi):** $4000/1 = 4000$ km/sa cevabı yanlıştır, çünkü birimler çevrilmemiştir. Doğrusu $v = \dfrac{4000 \times 10^{-3}\ \text{km}}{(1/60)\ \text{sa}} = 240$ km/sa.

**Soru 2** (ekrandan, 00:55:00): 3 A'lik bağımsız akım kaynağı (ok yukarı), üzerinde 1 V düşen bir elemana (üst uç +, alt uç −) doğrudan bağlıdır. Eleman ve kaynak için gücü bulunuz; hangisi üretir, hangisi tüketir?

> **Çözüm (derste verildi):** Akım elemana artı ucundan girer: $p_{\text{eleman}} = 3 \times 1 = +3$ W (tüketir). Akım kaynaktan artı uçtan çıkar: $p_{\text{kaynak}} = -3 \times 1 = -3$ W (üretir). Toplam $0$ W.

**Soru 3** (derste sözlü, 01:23:12): Bir devrede bir bileşenin gücü $-2$ W, iki bileşen toplam 8 W tüketiyor. Dördüncü bileşenin gücü nedir? <!-- BELİRSİZ: slayt karesi yok; soru metni altyazıdan kuruldu. -->

> **Çözüm (derste verildi):** Güçlerin toplamı sıfır olmalıdır: $-2 + 8 + p = 0 \Rightarrow p = -6$ W. Bileşen 6 W üreten bir üreteçtir.

**Soru 4** (ekrandan, 01:25:00): 1 V kaynak ve 1 $\Omega$ dirençli devre ile iki kap arasında akan su benzetmesinde, V'yi artırmak neye, R'yi artırmak neye karşılık gelir?

> **Çözüm (derste verildi):** V'yi artırmak üstteki suyu artırmak ya da kabı yükseltmektir. R'yi artırmak suyun aktığı deliği daraltmaktır. $V = IR$ gereği $R$ sabitken $V$ artınca akım artar, $V$ sabitken $R$ artınca akım azalır.

**Soru 5** (derste sözlü, 01:26:07): 10 V'luk kaynağa 4 k$\Omega$'luk direnç bağlıdır. Devre akımı $I$ nedir? Kaynağın ve direncin gücünü bulunuz.

> **Çözüm (derste verildi):** $I = 10 / (4 \times 10^{3}) = 2.5$ mA. Kaynak $-25$ mW üretir, direnç $+25$ mW tüketir.

## Dersin Toparlaması

Bu ilk ders, devre teorisinin geri kalanı için bir altyapı haftasıydı. Önce SI birimleri ve önekleri hatırlatıldı; birimleri temel birime çevirmeden hesap yapmanın, yanlış yuvarlamanın ve gösterim karışıklıklarının en sık hatalar olduğu vurgulandı. Ardından elektrik akımı su benzetmesiyle anlatıldı: akım için potansiyel fark gerekir, gerilim toprağa göre ölçülür, akımın yönü elektron hareketinin tersidir. Devre elemanları aktif (bağımsız ve bağımlı kaynaklar) ve pasif (direnç, bobin, kondansatör) olarak sınıflandırıldı; ampermetrenin seri, voltmetrenin paralel bağlandığı ve kablonun teoride ideal iletken sayıldığı açıklandı.

Dersin ikinci yarısında $i = dq/dt$, $v = dw/dq$ ve $p = dw/dt = vi$ tanımları kuruldu, pasif işaret kuralıyla güç işaretinin nasıl belirlendiği ve enerjinin korunumu gereği bir devredeki güçler toplamının sıfır olduğu gösterildi. Ders, su benzetmesinden Ohm yasasına ($V = IR$) geçilerek ve 10 V - 4 k$\Omega$ örneği çözülerek bitti. Bir sonraki ders KCL ve KVL konusudur; burada öğrenilen güç dengesi ve polarite kuralları orada sık sık kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
