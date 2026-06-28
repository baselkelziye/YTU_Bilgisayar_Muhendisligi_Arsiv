# Lojik Devreler Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

### Genel Bilgiler

* **Ders:** Lojik Devreler
* **Hoca:** Doç. Dr. Gökhan Bilgin
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Sayısal işaret işleme temelleri ve örnekleme (sampling) tekrarı | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Lojik devrelerin temeli | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 4** | Lojik fonksiyonların indirgenmesi | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 4 (Lab)** | Minterm tabanlı fonksiyon oluşturma | [Özet](altyazi_ozetleri/ders_4_lab_ozet.md) | [PDF (İndir)](ders_4_lab_ozet.pdf) |
| **Ders 5** | NAND ve NOR ile temel kapıların gerçekleştirilmesi | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 5 (Lab)** | Kişiye özel lojik fonksiyon çıkarma | [Özet](altyazi_ozetleri/ders_5_lab_ozet.md) | [PDF (İndir)](ders_5_lab_ozet.pdf) |
| **Ders 6** | Kombinasyonel devre tasarımı | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 6 (Lab)** | Karnaugh haritası ile sadeleştirme uygulaması | [Özet](altyazi_ozetleri/ders_6_lab_ozet.md) | [PDF (İndir)](ders_6_lab_ozet.pdf) |
| **Ders 8** | Kombinasyonel devre bloklarının devamı | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 8 (Lab)** | Minterm ve maksterm ifadeleri | [Özet](altyazi_ozetleri/ders_8_lab_ozet.md) | [PDF (İndir)](ders_8_lab_ozet.pdf) |
| **Ders 9** | Sıralı devrelere giriş | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 9 (Lab)** | Sıralı devre uygulamaları | [Özet](altyazi_ozetleri/ders_9_lab_ozet.md) | [PDF (İndir)](ders_9_lab_ozet.pdf) |
| **Ders 10** | Flip-flop türleri ve çalışma mantıkları | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 10 (Lab)** | Sayaç ve durum devresi uygulaması | [Özet](altyazi_ozetleri/ders_10_lab_ozet.md) | [PDF (İndir)](ders_10_lab_ozet.pdf) |
| **Ders 11** | Sayaç devrelerinin analizi | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 11 (Lab)** | Sayaç tasarımının uygulamalı kontrolü | [Özet](altyazi_ozetleri/ders_11_lab_ozet.md) | [PDF (İndir)](ders_11_lab_ozet.pdf) |
| **Ders 12** | Sıralı devre tasarım adımları | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 12 (Lab)** | Durum makinesi tasarımı uygulaması | [Özet](altyazi_ozetleri/ders_12_lab_ozet.md) | [PDF (İndir)](ders_12_lab_ozet.pdf) |
| **Ders 13** | Register yapıları | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 13 (Lab)** | Flip-flop, sayaç ve register uygulamaları | [Özet](altyazi_ozetleri/ders_13_lab_ozet.md) | [PDF (İndir)](ders_13_lab_ozet.pdf) |

## Derslerin Detaylı Özetleri ve Kazanımları

### Ders 1: Sayısal işaret işleme temelleri ve örnekleme (sampling) tekrarı

#### Genel Konular

- Sayısal işaret işleme temelleri ve örnekleme (sampling) tekrarı
  - Sürekli (analog) işaretlerin ayrık (discrete) hale getirilmesi gerekliliği.
  - İki örnekleme arasında geçen süre: sampling period (TS).
  - TS'nin çok geniş (seyrek) olması: hafıza ve işlem gücü avantajı, ancak işaretin orijinalliğini kaybetme riski.
  - TS'nin çok dar (sık) olması: hafıza ve hesap gücü (computing) açısından dezavantaj.
- Fourier Analizi
  - Joseph Fourier'in (1800'ler) katkısı: herhangi bir işaret/fonksiyon, farklı frekanslara sahip sonsuz sayıda sinüzoidal bileşenin toplamı şeklinde yazılabilir.
  - Matematiksel gösterim: x(t) = ∫ A(f) · sin(2πft) df (sıfırdan sonsuza frekans aralığı).
  - Her sinüzoidal bileşenin katkısı frekansa bağlı genlik katsayıları (A(f)) ile ifade edilir.
  - Faz farkı (φ) da bileşenler arasında farklılık yaratabilir.
- Sinüzoidal İşaretin Temel Parametreleri
  - Genlik (A): −A ile +A arasındaki salınım.
  - Frekans (f): birim zamanda (1 saniyede) kendini tekrar etme sayısı. Birimi Hertz (Hz).
  - Periyot (T): bir çevrimin tamamlanması için geçen süre, T = 1/f. Frekans ile ters orantılı.
  - Faz (φ): işaretin başlangıç kayması. Sinüs ve kosinüs aynı fonksiyonun aralarındaki φ = 90° faz farkı olan halleridir.
  - Genel ifade: x(t) = A · sin(ωt + φ) = A · sin(2πft + φ). ω = 2πf (radyan cinsinden açısal frekans).
- DC (Doğru Akım) ve AC (Alternatif Akım) Kavramları
  - DC: sabit değer alan, frekansı sıfır olan, salınım yapmayan işaret. Genellikle işaretin ortalamasını verir.
  - AC: salınım yapan, frekansı sıfırdan büyük işaret. Sıfır ortalamalıdır.
  - Bir işaret = DC bileşen (ortalama) + AC bileşen (salınım) şeklinde ayrıştırılabilir. AC bileşen DC seviyesinin üzerine binmiş gibi düşünülür.
  - Şehir şebekesi örnek: Avrupa 220V/50Hz, Amerika 110V/60Hz.
  - Adlandırma tarihsel olarak güç (akım) işaretlerinden gelir, "current" akımı ifade eder.
- Örnekleme Teoremi ve Nyquist Kriteri
  - Gerçek işaretler sonsuz frekansa sahip değildir; kaynağın fiziksel sınırlamaları nedeniyle bir maksimum frekans (fmax) vardır (insan sesi ~4 kHz).
  - En kötü durum (worst case) en yüksek frekanslı sinüzoidal bileşende oluşur: bir çevrimde sadece iki tepe noktası örneklenir.
  - Daha düşük frekanslı bileşenlerde bir çevrimde daha fazla örnek alınır → daha iyi temsil edilir.
  - fmax ile TS arasındaki ilişki: en yüksek frekanslı bileşenin bir çevrim süresi Tmax = 1/fmax olup, iki örnek arası TS ile Tmax arasında TS ≤ Tmax/2 ilişkisi aranır (Nyquist).

#### Hocanın Özellikle Vurguladığı Kısımlar

- Örnekleme sıklığı (TS) belirleme
  - Optimal TS değeri: olabilecek maksimum genişlikte olmalı, ancak işaretin temel özelliklerini kaybetmemeli. Dengenin Fourier analizi ve Nyquist kriteri ile kurulması.
- En yüksek frekanslı bileşenin kritik rolü
  - Örnekleme kalitesini belirleyen en kritik unsur fmax'tır; hoca bunu özellikle görsel olarak anlatmış, "en kötü durum burada oluşuyor" diyerek altını çizmiş.
- Frekans-Periyot ters ilişkisi
  - Yüksek frekans → düşük T, düşük frekans → yüksek T. Sınavda bu temel ilişkiyi sorgulayabilecek bir soru gelebilir.

#### Detaylı Açıklamalar

Derste lojik devrelerin altyapısını oluşturan sayısal işaret işleme (digital signal processing) kavramları işlenmiştir. Fiziksel dünyadaki işaretler sürekli (analog) yapıdadır ve herhangi iki an arasında sonsuz sayıda değer alır. Bilgisayar bu işaretleri işleyebilmek için ayrıklaştırmaya (discretization) ihtiyaç duyar. İlk adım örnekleme (sampling)'dir. Örnekleme, belirli zaman aralıklarında (TS) işaretin değerini alıp kaydetme işlemidir. TS değerinin belirlenmesi için Fourier analizinden yararlanılır: işaret, farklı frekanslara sahip sinüzoidal bileşenlere ayrıştırılır. Bu bileşenlerden en yüksek frekansa sahip olan (fmax), örnekleme aralığını belirleyen temel unsurdur. Teorik olarak TS'nin, fmax frekansındaki bileşenin periyodunun yarısından küçük veya eşit olması gerekir (Nyquist-Shannon örnekleme teoremi). Eğer TS bu değerden büyük olursa aliasing (örtüşme) meydana gelir ve orijinal işaret kaybedilir. Gerçek hayatta işaretler sonsuz frekans içermez; kaynağın fiziksel karakteristiği bir üst sınır belirler. İnsan sesi için bu sınır yaklaşık 4 kHz'dir.

DC/AC ayrımı da temel bir kavram olarak işlenmiştir. Herhangi bir işaret, sabit bir DC seviye ile sıfır ortalamalı AC salınımın toplamı şeklinde modellenebilir. Bu ayrım Fourier analizindeki f=0 bileşenine (DC) ve f>0 bileşenlerine (AC harmonikleri) karşılık gelir.
### Ders 2: Lojik devrelerin temeli

#### Genel Konular

- Lojik devrelerin temeli
  - Lojik devreler ikili işaretler ve ikili kodlanmış veriler üzerinde çalışır.
  - Değişkenler yalnızca `0` ve `1` değerlerini alır; bu değerler devrelerde düşük/yüksek gerilim, açık/kapalı anahtar veya yok/var durumlarıyla yorumlanabilir.
- Boolean cebri
  - Boolean cebri klasik cebire benzeyen, fakat iki değerli değişkenler ve kendine özgü aksiyomlarla çalışan matematiksel yapıdır.
  - Lojik kapıların davranışı Boolean cebriyle ifade edilir.
- Temel lojik kapılar
  - AND kapısı yalnızca bütün girişler `1` olduğunda `1` üretir.
  - OR kapısı girişlerden en az biri `1` olduğunda `1` üretir.
  - NOT kapısı tek girişin tümleyenini üretir; `0` değerini `1`, `1` değerini `0` yapar.
- Türetilmiş kapılar
  - NAND, AND işleminin tümleyenidir.
  - NOR, OR işleminin tümleyenidir.
  - XOR girişler farklı olduğunda `1`, aynı olduğunda `0` üretir.
  - XNOR girişler aynı olduğunda `1`, farklı olduğunda `0` üretir.
- Kümeler cebri ile ilişki
  - AND işlemi kümelerde kesişime, OR işlemi birleşime, NOT işlemi tümlemeye karşılık gelir.
  - Evrensel küme `1`, boş küme `0` ile temsil edilebilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Doğruluk tablosu kapı davranışını belirleyen temel araçtır.
  - Girişlerin aldığı her kombinasyon için çıkış açıkça yazılmalıdır.
- AND ve OR kapılarının anahtarlı devre karşılıkları iyi anlaşılmalıdır.
  - AND için anahtarlar seri, OR için anahtarlar paralel düşünülür.
- Zaman diyagramlarında çıkış, girişlerin değişim noktalarına göre parça parça belirlenir.
  - AND çıkışı yalnızca iki girişin aynı anda `1` olduğu aralıklarda `1` olur.
  - OR çıkışı iki girişin de `0` olduğu aralık dışında `1` olur.
- XOR ve XNOR kavramları karıştırılmamalıdır.
  - XOR farklılık, XNOR eşdeğerlik kontrolü gibi düşünülebilir.

#### Detaylı Açıklamalar

- Boolean cebrinde her değişken bir bitlik bilgiyi temsil eder. Bu nedenle iki girişli bir kapıda dört olası giriş durumu vardır: `00`, `01`, `10`, `11`. Kapıların doğruluk tabloları bu dört durum üzerinden kurulur.
- AND kapısı seri anahtar devresiyle modellenebilir. İki anahtarın da kapalı olması durumunda devreden akım geçer ve çıkış `1` olur. Bu model, AND işleminin “bütün koşullar sağlanmalı” mantığını açıklar.
- OR kapısı paralel anahtar devresiyle modellenebilir. Anahtarlardan herhangi biri kapalı olduğunda akım için yol oluşur ve çıkış `1` olur. Bu model, OR işleminin “en az bir koşul yeterli” mantığını gösterir.
- NOT kapısı girişin tersini üretir. Lojik yorumda bu, bir durumun yokluğunu varlığa veya varlığını yokluğa çevirmek anlamına gelir.
- Türetilmiş kapılar temel kapılardan elde edilir. NAND ve NOR özellikle önemlidir; çünkü birçok devre yalnızca bu kapılar kullanılarak kurulabilir. XOR ve XNOR ise eşitlik/farklılık ilişkilerini ifade ettiği için karşılaştırma ve aritmetik devrelerde sık kullanılır.
### Ders 4: Lojik fonksiyonların indirgenmesi

#### Genel Konular

- Lojik fonksiyonların indirgenmesi
  - Amaç, fonksiyonun doğruluk tablosundaki çıkışları değiştirmeden daha az terimli ve daha düşük maliyetli ifade elde etmektir.
  - Daha az terim daha az kapı, daha az bağlantı ve daha sade devre anlamına gelir.
- İndirgeme yöntemleri
  - Görüşe dayalı indirgeme Boolean cebri kurallarını sezgisel kullanır.
  - Karnaugh haritası komşu `1` veya `0` gruplarını kullanarak sistematik sadeleştirme sağlar.
  - Quine-McCluskey yöntemi daha algoritmik ve tablo tabanlı bir yaklaşımdır.
- Boolean cebri kuralları
  - Ortak paranteze alma, tümleyen ilişkisi, `A + A' = 1`, `A · A' = 0` gibi özdeşlikler indirgemede kullanılır.
  - De Morgan kuralları çarpım ve toplam işlemlerini tümleyen altında birbirine dönüştürür.
- Kanonik gösterimler
  - Minimum terimler biçimi fonksiyonun `1` olduğu satırlar üzerinden yazılır.
  - Maksimum terimler biçimi fonksiyonun `0` olduğu satırlar üzerinden yazılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- İndirgeme yapılırken fonksiyonun çıkışı değişmemelidir.
  - Sadeleşen ifade ile ilk ifade aynı doğruluk tablosunu üretmelidir.
- Görüşe dayalı indirgeme kesin biçimde en küçük sonucu garanti etmeyebilir.
  - Ara bir sadeleşmede durmak yerine ifadenin daha da indirgenip indirgenemeyeceği kontrol edilmelidir.
- De Morgan dönüşümlerinde işaret değişimi dikkatle takip edilmelidir.
  - Tümleyen alınırken AND, OR'a; OR, AND'e dönüşür ve terimler tek tek tümleyenlenir.
- Minterm açılımında ikili sayının her biti değişkenin düz veya tümleyen halini belirler.

#### Detaylı Açıklamalar

- Lojik fonksiyon indirgeme, devre tasarımında maliyet ve karmaşıklığı azaltmak için kullanılır. Örneğin çok sayıda AND, OR ve NOT kapısı gerektiren bir ifade, doğru sadeleştirme ile daha az kapıyla kurulabilir.
- Görüşe dayalı indirgemede ifadedeki ortak çarpanlar aranır. Ortak paranteze alma, tümleyen çiftlerini fark etme ve De Morgan uygulama temel araçlardır. Bu yöntem hızlıdır; ancak öğrencinin Boolean cebri kurallarını iyi görmesini gerektirir.
- Kanonik gösterimlerde fonksiyon, doğruluk tablosundaki satır numaralarıyla ifade edilebilir. `F(x,y,z)=Σm(0,4)` biçimi fonksiyonun 0 ve 4 numaralı mintermlerde `1` olduğunu anlatır. Bu satırlar ikili karşılıklarına çevrilerek açık çarpım terimleri yazılır.
- Karnaugh haritası, komşuluk ilişkilerini görsel hale getirir. Komşu `1` grupları büyüdükçe sadeleşen terimde daha fazla değişken elenir. Bu nedenle en büyük geçerli grupları seçmek önemlidir.
### Ders 4 (Lab): Minterm tabanlı fonksiyon oluşturma

#### Genel Konular

- Minterm tabanlı fonksiyon oluşturma
  - Öğrenciye verilen sayısal değerlere göre minterm numaraları belirlenir.
  - Mintermler doğruluk tablosunda fonksiyonun `1` olduğu satırları gösterir.
- Doğruluk tablosu hazırlama
  - Üç girişli bir fonksiyonda tüm `x, y, z` kombinasyonları yazılır.
  - Seçilen mintermlere karşılık gelen satırlarda çıkış `1`, diğerlerinde `0` olur.
- Kapı türüne göre gerçekleme
  - Fonksiyon sadeleştirildikten sonra istenen kapı türüyle devre kurulmalıdır.
  - OR, AND, NOR gibi kapılar ve gerekli NOT kapıları kullanılarak eşdeğer devre elde edilir.
- Simülasyonla doğrulama
  - Kurulan devre, doğruluk tablosuyla karşılaştırılarak kontrol edilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Devre sadeleştirilmiş ifadeye göre kurulmalıdır.
  - Gereksiz uzun kanonik ifade doğrudan çizilmek yerine önce sadeleştirme yapılmalıdır.
- Çözümde minterm ifadesi, doğruluk tablosu ve seçilen kapı türü açık olmalıdır.
  - Devre çizimi tek başına yeterli değildir; hangi fonksiyonun gerçekleştirildiği gösterilmelidir.
- Simülasyonda yalnızca şekil değil, çalışan devre ve çıkış kontrolü önemlidir.

#### Detaylı Açıklamalar

- Laboratuvar içeriği, teoride öğrenilen minterm, doğruluk tablosu ve kapı gerçekleme ilişkisini uygulamaya taşır. Önce fonksiyonun hangi giriş kombinasyonlarında `1` verdiği belirlenir. Ardından bu fonksiyon açık minterm toplamı olarak yazılır.
- Sonraki adım, fonksiyonu Boolean cebri veya Karnaugh haritası ile sadeleştirmektir. Sadeleşmiş ifade hangi kapılarla kurulacaksa ona uygun dönüşümler yapılır. Örneğin yalnızca belirli bir kapı türü kullanılacaksa De Morgan dönüşümleri ve NOT elde etme yöntemleri devre tasarımında kullanılır.
- Simülasyon programında girişler değiştirilerek çıkışın doğruluk tablosuyla uyuşup uyuşmadığı gözlenir. Bu adım, cebirsel çözümün devre düzeyinde doğru çalıştığını doğrular.
### Ders 5: NAND ve NOR ile temel kapıların gerçekleştirilmesi

#### Genel Konular

- NAND ve NOR ile temel kapıların gerçekleştirilmesi
  - NAND veya NOR kapısının girişleri birleştirilerek NOT kapısı elde edilebilir.
  - AND ve OR kapıları, NAND/NOR ve De Morgan dönüşümleriyle kurulabilir.
- Aynı tür kapılarla devre tasarımı
  - NAND ve NOR kapıları fiziksel gerçekleme ve çip kullanımı açısından avantajlıdır.
  - Aynı tür kapılarla tasarım, bağlantı karmaşıklığını ve çip sayısını azaltabilir.
- Çarpımlar toplamı biçimi
  - Fonksiyon, AND terimlerinin OR ile toplanması şeklinde ifade edilir.
  - Bu biçim NAND-NAND gerçeklemeye doğal olarak uygundur.
- Karnaugh haritası ile indirgeme
  - Fonksiyon önce Karnaugh haritasıyla sadeleştirilir, sonra seçilen kapı türüyle gerçekleştirilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Önce indirgeme, sonra devre gerçekleme yapılmalıdır.
  - Sadeleştirilmemiş ifadeyi doğrudan kurmak gereksiz kapı kullanımına yol açar.
- NAND/NOR dönüşümlerinde De Morgan kuralları merkezi rol oynar.
  - Çarpımlar toplamı NAND yapısına, toplamlar çarpımı NOR yapısına uygun biçimde dönüştürülebilir.
- Kapı sayısı kadar çip içindeki kapı yerleşimi de önemlidir.
  - Tek bir entegre içindeki kapıların verimli kullanılması devre maliyetini azaltır.

#### Detaylı Açıklamalar

- NAND ve NOR kapıları evrensel kapılardır; yani temel lojik işlemler yalnızca bu kapılarla kurulabilir. NOT işlemi, kapının iki girişine aynı değişken verilerek elde edilir. Bu yöntem hem NAND hem NOR için geçerlidir.
- AND kapısı NAND çıkışının tekrar tümleyenlenmesiyle elde edilir. OR kapısı ise De Morgan dönüşümüyle girişlerin tümleyenlerinin NAND'lanması veya NOR çıkışının tümleyenlenmesi gibi yaklaşımlarla kurulabilir.
- Çarpımlar toplamı biçimindeki bir fonksiyon NAND ile gerçekleştirilirken önce her çarpım teriminin NAND çıkışı alınır. Son katmanda bu ara sonuçlar tekrar NAND'lanarak OR etkisi De Morgan üzerinden sağlanır. Böylece AND-OR devresi yerine NAND-NAND yapısı elde edilir.
- Karnaugh haritası örneklerinde `1` olan hücreler en büyük gruplar halinde seçilir. Her grup, değişmeyen değişkenlerden oluşan bir sade terim üretir. Bu terimler sonradan seçilen kapı teknolojisine uygun biçimde dönüştürülür.
### Ders 5 (Lab): Kişiye özel lojik fonksiyon çıkarma

#### Genel Konular

- Kişiye özel lojik fonksiyon çıkarma
  - Sayısal değerlerden minterm kümesi oluşturulur.
  - Aynı minterm tekrar ederse farklı satır elde etmek için uygun düzeltme yapılır.
- Minterm ifadesi ve doğruluk tablosu
  - Fonksiyon `Σm(...)` biçiminde yazılır.
  - Doğruluk tablosu, minterm kümesinin doğru yorumlanıp yorumlanmadığını gösterir.
- Kapı türüne göre sade devre tasarımı
  - Seçilen kapı türü öğrenciye göre değişebilir.
  - Fonksiyonun sadeleştirilmiş hali, istenen kapı yapısına dönüştürülür.
- Simülasyon doğrulaması
  - Devre girişleri denenerek teorik doğruluk tablosuyla karşılaştırılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Tek sorunun birden fazla aşaması vardır.
  - Fonksiyon çıkarma, doğruluk tablosu, sadeleştirme ve devre gerçekleme birlikte değerlendirilir.
- Kapı seçimi ve minterm çıkarımı karıştırılmamalıdır.
  - Minterm belirleme farklı mod işlemine, kapı seçimi farklı mod işlemine dayanabilir.
- Programda devre çalışır halde gösterilmelidir.
  - Statik ekran görüntüsü yerine giriş-çıkış davranışı kontrol edilmelidir.

#### Detaylı Açıklamalar

- Laboratuvar çalışması, öğrencinin kendi fonksiyonunu üretip uçtan uca devreye dönüştürmesini hedefler. Sayısal işlemlerle bulunan minterm değerleri önce fonksiyon biçiminde yazılır. Sonra bu fonksiyona karşılık gelen doğruluk tablosu oluşturulur.
- Fonksiyon sadeleştirildikten sonra kullanılacak kapı türüne uygun dönüşüm yapılır. Örneğin yalnızca NOR veya NAND türü kapılarla gerçekleme isteniyorsa De Morgan kuralları kullanılır ve gerekli tümleyenler kapı girişleri birleştirilerek elde edilir.
- Simülasyon doğrulaması, teorik çözüm ile devre davranışı arasındaki bağı kurar. Giriş kombinasyonları sırayla denenir ve çıkış değerlerinin doğruluk tablosundaki değerlerle uyumlu olması beklenir.
### Ders 6: Kombinasyonel devre tasarımı

#### Genel Konular

- Kombinasyonel devre tasarımı
  - Çıkışlar yalnızca o andaki girişlere bağlıdır; bellek etkisi yoktur.
  - Fonksiyon çıkarma, sadeleştirme ve kapı düzeyinde gerçekleme birlikte ele alınır.
- Kodlayıcı ve kod çözücü yapıları
  - Decoder, ikili giriş bilgisini tekil çıkış hatlarına dönüştürür.
  - Encoder, aktif giriş bilgisini ikili koda dönüştürür.
- Multiplexer ve demultiplexer
  - Multiplexer seçme girişlerine göre çok sayıda girişten birini çıkışa aktarır.
  - Demultiplexer tek girişi seçme hatlarına göre çıkışlardan birine yönlendirir.
- Aritmetik devrelere giriş
  - Toplayıcı ve çıkarıcı devreler Boolean fonksiyonlarıyla kurulur.
  - Yarım toplayıcı, tam toplayıcı, yarım çıkarıcı ve tam çıkarıcı mantığı temel alınır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Kombinasyonel devrelerde doğruluk tablosu tasarımın başlangıç noktasıdır.
  - Her çıkış için ayrı Boolean ifade çıkarılmalıdır.
- Decoder, encoder ve multiplexer hazır blok gibi düşünülse de iç yapıları kapı düzeyinde anlaşılmalıdır.
- Toplayıcı devrelerde toplam ve elde çıkışı ayrı fonksiyonlardır.
  - XOR toplam bitinde, AND/OR yapıları elde bitinde sık kullanılır.

#### Detaylı Açıklamalar

- Kombinasyonel devre tasarımında önce problem giriş ve çıkış değişkenleriyle modellenir. Ardından doğruluk tablosu oluşturulur, her çıkış için Boolean ifade yazılır ve sadeleştirme yapılır.
- Decoder devreleri, özellikle minterm üretimi açısından önemlidir. Her çıkış belirli bir giriş kombinasyonuna karşılık gelir. Bu nedenle decoder çıkışları OR kapılarıyla birleştirilerek istenen fonksiyonlar oluşturulabilir.
- Multiplexer devreleri fonksiyon gerçekleştirme amacıyla da kullanılabilir. Seçme hatları değişkenlerin bir kısmını temsil ederken veri girişlerine sabit `0`, `1` veya diğer değişkenler bağlanabilir.
- Toplayıcı ve çıkarıcı devreler aritmetik işlemlerin lojik kapılarla kurulabileceğini gösterir. Toplam/fark bitleri çoğunlukla XOR mantığına, elde/borç bitleri ise AND-OR kombinasyonlarına dayanır.
### Ders 6 (Lab): Karnaugh haritası ile sadeleştirme uygulaması

#### Genel Konular

- Karnaugh haritası ile sadeleştirme uygulaması
  - Fonksiyonun `1` olduğu hücreler haritaya yerleştirilir.
  - Komşu hücreler en büyük gruplar halinde seçilir.
- Kapı düzeyinde devre kurulumu
  - Sadeleşmiş ifade seçilen kapı türüne göre dönüştürülür.
  - NOT gereksinimleri kapı girişleri birleştirilerek veya ayrı tümleyen kapısıyla sağlanır.
- Simülasyon tabanlı kontrol
  - Devre çıkışları doğruluk tablosundaki beklenen değerlerle karşılaştırılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Karnaugh haritasında amaç bütün `1`leri kapsamak ve gereksiz grup oluşturmamaktır.
- Büyük gruplar daha fazla değişkenin elenmesini sağlar.
- Devre doğrulaması için yalnızca çizim değil, giriş kombinasyonları üzerinden test gerekir.

#### Detaylı Açıklamalar

- Laboratuvar çalışmasında teorik sadeleştirme pratiğe aktarılır. Minterm değerleri Karnaugh haritasına yerleştirilir ve fonksiyonun en sade hali bulunur.
- Sadeleşmiş ifade doğrudan standart AND-OR kapılarıyla kurulabileceği gibi NAND veya NOR gibi tek tip kapılarla da kurulabilir. Bu durumda De Morgan dönüşümleri devre gerçekleme aşamasında kullanılır.
- Simülasyonda tüm giriş kombinasyonlarının denenmesi, hem Karnaugh sadeleştirmesinin hem de devre bağlantılarının doğru olduğunu gösterir.
### Ders 8: Kombinasyonel devre bloklarının devamı

#### Genel Konular

- Kombinasyonel devre bloklarının devamı
  - Decoder, encoder ve seçici devreler farklı tasarım problemlerinde yeniden kullanılır.
  - Hazır blokların giriş-çıkış ilişkisi doğruluk tablolarıyla açıklanır.
- Aritmetik devreler
  - Yarım ve tam toplayıcı yapıları çok bitli toplama devrelerinin temelini oluşturur.
  - Çıkarıcı devrelerde fark ve borç çıkışları ayrı Boolean fonksiyonlarıdır.
- Paralel toplama mantığı
  - Çok bitli toplamada her basamak bir önceki basamağın elde çıkışını kullanır.
  - Elde yayılımı gecikme ve tasarım karmaşıklığı açısından önemlidir.
- Fonksiyonların bloklarla gerçekleştirilmesi
  - Decoder veya multiplexer kullanarak Boolean fonksiyonları kurulabilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Aritmetik devrelerde her çıkış bağımsız analiz edilmelidir.
  - Toplam/fark ile elde/borç aynı fonksiyon değildir.
- Çok bitli devreler tek bitlik yapıların düzenli bağlanmasıyla oluşur.
- Hazır blok kullanımı, kapı düzeyindeki mantığın anlaşılmasını gereksiz kılmaz.

#### Detaylı Açıklamalar

- Toplayıcı devrelerin temelinde XOR ve AND işlemleri bulunur. İki bitin toplam biti XOR ile, elde biti AND ile ifade edilir. Giriş eldesi eklendiğinde tam toplayıcı yapısı ortaya çıkar.
- Tam toplayıcılar kademeli bağlanarak çok bitli paralel toplayıcı oluşturulur. Her basamak kendi toplam bitini üretirken elde çıkışını bir sonraki basamağa aktarır.
- Çıkarıcı devrelerde fark biti, girişlerin farklılığına bağlıdır; borç biti ise çıkarılan değerin mevcut bitten büyük olduğu durumları temsil eder. Bu nedenle borç fonksiyonu ayrı analiz edilmelidir.
- Decoder ve multiplexer gibi bloklar, yalnızca belirli bir iş yapan elemanlar değil, genel Boolean fonksiyonları gerçekleştirmek için de kullanılabilen yapı taşlarıdır.
### Ders 8 (Lab): Minterm ve maksterm ifadeleri

#### Genel Konular

- Minterm ve maksterm ifadeleri
  - Fonksiyonun `1` olduğu satırlar minterm toplamıyla, `0` olduğu satırlar maksterm çarpımıyla gösterilir.
  - İki gösterim aynı fonksiyonu farklı açıdan tanımlar.
- Karnaugh haritası kullanımı
  - `1` grupları üzerinden çarpımlar toplamı, `0` grupları üzerinden toplamlar çarpımı elde edilebilir.
- Devre gerçekleme
  - Sadeleşen fonksiyon, kapı düzeyinde veya tek tip kapılarla kurulabilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Minterm ve maksterm karıştırılmamalıdır.
  - Minterm `1` satırlarını, maksterm `0` satırlarını esas alır.
- Karnaugh haritasında doğru satır/sütun yerleşimi sonuç için kritiktir.
- Devrenin doğruluk tablosu ile uyumlu olması gerekir.

#### Detaylı Açıklamalar

- Laboratuvar içeriği, fonksiyonun iki kanonik biçimini uygulamalı olarak kullanmayı hedefler. Minterm biçimi, fonksiyonun hangi satırlarda `1` olduğunu doğrudan gösterir. Maksterm biçimi ise fonksiyonun `0` olduğu satırlar üzerinden kurulur.
- Karnaugh haritası iki biçimi de sadeleştirmek için kullanılabilir. `1`lerin gruplandırılması çarpımlar toplamı biçiminde sade terimler verirken, `0`ların gruplandırılması toplamlar çarpımı biçiminde sade çarpanlar verir.
- Devre kurulumunda seçilen sade biçime uygun kapı yapısı tercih edilir. SOP genellikle AND-OR veya NAND-NAND, POS ise OR-AND veya NOR-NOR yapısına uygundur.
### Ders 9: Sıralı devrelere giriş

#### Genel Konular

- Sıralı devrelere giriş
  - Sıralı devrelerde çıkış yalnızca mevcut girişlere değil, devrenin önceki durumuna da bağlıdır.
  - Bu yapı bellek elemanlarını gerektirir.
- Latch ve flip-flop kavramları
  - Latch seviye duyarlı, flip-flop kenar duyarlı bellek elemanı olarak ele alınır.
  - SR, JK, D ve T türleri farklı giriş-durum ilişkileriyle çalışır.
- Senkron ve asenkron davranış
  - Senkron devrelerde durum değişimi saat işaretiyle kontrol edilir.
  - Asenkron girişler saatten bağımsız olarak çıkışı etkileyebilir.
- Register kavramı
  - Birden fazla flip-flop birlikte kullanılarak çok bitli veri saklanır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Sıralı devrelerde zaman ve önceki durum kavramı temel farktır.
  - Kombinasyonel devrede bellek yokken, sıralı devrede durum bilgisi vardır.
- Flip-flop doğruluk/uyarma tabloları iyi öğrenilmelidir.
  - Her flip-flop türünün girişleri farklı anlam taşır.
- Saat işaretinin aktif kenarı veya seviyesi doğru yorumlanmalıdır.

#### Detaylı Açıklamalar

- Sıralı devreler, dijital sistemlerde bellek ve zamanlama ihtiyacını karşılar. Bir çıkışın değeri yalnızca o andaki girişlerden değil, saklanan durumdan da etkilenir. Bu nedenle durum değişkenleri devre analizinde önemli yer tutar.
- SR latch temel bellek yapılarından biridir. Set ve reset girişleri çıkışı belirler; bazı giriş kombinasyonları yasak veya belirsiz kabul edilir. JK flip-flop bu belirsizliği toggle davranışıyla giderir.
- D flip-flop, tek veri girişine sahip olduğu için register ve bellek tasarımlarında yaygın kullanılır. Saat kenarında girişteki veri çıkışa aktarılır ve bir sonraki etkin saate kadar saklanır.
- T flip-flop giriş aktif olduğunda durum değiştirir. Bu özellik sayaç tasarımlarında kullanışlıdır.
### Ders 9 (Lab): Sıralı devre uygulamaları

#### Genel Konular

- Sıralı devre uygulamaları
  - Bellek elemanları kullanılarak durum tutan devreler kurulabilir.
  - Flip-flop girişleri devrenin bir sonraki durumunu belirler.
- Doğruluk ve durum tablosu ilişkisi
  - Sıralı devrelerde mevcut durum, girişler ve sonraki durum birlikte tabloya yazılır.
- Simülasyonla saatli devre kontrolü
  - Saat darbeleri uygulanarak durum geçişleri gözlenir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Sıralı devrelerde sadece anlık çıkışa bakmak yeterli değildir.
  - Durum geçişleri adım adım izlenmelidir.
- Flip-flop türüne göre uyarma girişleri doğru verilmelidir.
- Saat sinyali olmadan beklenen durum değişimi oluşmayabilir.

#### Detaylı Açıklamalar

- Laboratuvar çalışması, flip-flopların soyut doğruluk tablolarından gerçek devre davranışına geçişi amaçlar. Öğrenci mevcut durum, girişler ve sonraki durum arasındaki ilişkiyi kurar.
- Simülasyonda saat işareti uygulanarak devrenin her darbede nasıl değiştiği gözlenir. Bu gözlem, sıralı devrelerde zamanlama kavramının neden kritik olduğunu gösterir.
- Tasarımda yanlış flip-flop girişleri veya eksik saat bağlantısı devrenin beklenen sırayı izlememesine neden olabilir. Bu yüzden uyarma tablosu ve bağlantı doğrulaması birlikte yapılmalıdır.
### Ders 10: Flip-flop türleri ve çalışma mantıkları

#### Genel Konular

- Flip-flop türleri ve çalışma mantıkları
  - SR, JK, D ve T flip-flopların giriş-çıkış ilişkileri karşılaştırılır.
  - Her flip-flop türü farklı durum değiştirme davranışı gösterir.
- Uyarma tabloları
  - İstenen durum geçişini sağlamak için flip-flop girişlerinin ne olması gerektiği belirlenir.
  - Mevcut durum ve sonraki durumdan giriş koşulları çıkarılır.
- Sayaç tasarımına giriş
  - Flip-floplar birlikte kullanılarak belirli sırayla durum değiştiren sayaçlar kurulabilir.
  - Senkron sayaçlarda flip-floplar ortak saat işaretiyle tetiklenir.
- Durum diyagramı ve durum tablosu
  - Sıralı devre davranışı durumlar ve geçişler üzerinden modellenir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Flip-flop karakteristik tablosu ile uyarma tablosu aynı şey değildir.
  - Karakteristik tablo girişten sonraki durumu, uyarma tablosu istenen geçiş için gereken girişi verir.
- Sayaç tasarımında kullanılmayan durumlar dikkate alınmalıdır.
  - Devrenin istenmeyen durumlara girmesi halinde nasıl davranacağı tasarım açısından önemlidir.
- Senkron tasarımda tüm flip-flopların aynı saatle tetiklenmesi beklenir.

#### Detaylı Açıklamalar

- Sıralı devre tasarımında ilk adım, devrenin hangi durumlar arasında geçiş yapacağını belirlemektir. Bu bilgi durum diyagramı veya durum tablosu ile gösterilir.
- Flip-flop seçildikten sonra her durum biti için uyarma tablosu kullanılır. Örneğin D flip-flopta tasarım daha doğrudandır; çünkü `D` girişi bir sonraki durum değerine eşittir. JK ve T flip-floplarda ise geçişe göre giriş koşulları çıkarılır.
- Sayaçlar, belirli bir durum dizisini saat darbeleriyle izleyen sıralı devrelerdir. Senkron sayaçlarda bütün flip-floplar aynı anda tetiklenir; bu, asenkron yapılara göre zamanlama analizini daha düzenli hale getirir.
- Kullanılmayan durumlar için devrenin güvenli biçimde geçerli durumlara dönmesi veya bu durumların önemsiz kabul edilmesi tasarım tercihine bağlıdır.
### Ders 10 (Lab): Sayaç ve durum devresi uygulaması

#### Genel Konular

- Sayaç ve durum devresi uygulaması
  - Flip-floplar kullanılarak belirli durum dizisi üreten devre tasarlanır.
  - Mevcut durumdan sonraki duruma geçişler tabloyla gösterilir.
- Uyarma girişlerinin bulunması
  - Seçilen flip-flop türüne göre giriş değerleri uyarma tablosundan çıkarılır.
- Simülasyonda durum izleme
  - Saat darbeleri uygulanarak çıkışların beklenen sırayı izleyip izlemediği kontrol edilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Devrenin çalışması saat darbeleri üzerinden doğrulanmalıdır.
- Flip-flop girişleri rastgele değil, uyarma tablosuna göre bağlanmalıdır.
- Durum sırası teorik tabloyla uyumlu olmalıdır.

#### Detaylı Açıklamalar

- Laboratuvar çalışması, sıralı devre tasarım adımlarını uygulamaya dönüştürür. Önce istenen sayma veya durum geçiş sırası belirlenir. Daha sonra bu sıra mevcut durum ve sonraki durum tablosuna çevrilir.
- Seçilen flip-flop türüne göre her bit için gerekli giriş fonksiyonları çıkarılır. Bu fonksiyonlar sadeleştirilip kapı devresi olarak kurulur.
- Simülasyonda saat darbeleri uygulanarak devrenin her adımda hangi duruma geçtiği gözlenir. Doğru tasarımda durumlar teorik sırayla ilerler.
### Ders 11: Sayaç devrelerinin analizi

#### Genel Konular

- Sayaç devrelerinin analizi
  - Sayaçlar flip-flop çıkışlarının belirli bir sırada değişmesiyle çalışır.
  - Durum geçiş tablosu ve çıkış dizisi üzerinden analiz yapılır.
- Senkron ve asenkron sayaç farkları
  - Asenkron sayaçlarda bir flip-flop çıkışı diğerinin saatini tetikleyebilir.
  - Senkron sayaçlarda tüm flip-floplar ortak saat işaretine bağlıdır.
- Mod kavramı
  - Sayaç mod değeri, sayaç devresinin kaç farklı durumdan geçtiğini belirtir.
  - Mod-N sayaçlar N durumluk döngü üretir.
- Resetleme ve başlangıç durumu
  - Sayaçların belirli bir durumdan başlaması veya belirli durumda sıfırlanması gerekebilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Sayaçlarda durum sırası yalnızca ikili sayma olmak zorunda değildir.
  - Tasarım istenen durum dizisine göre yapılabilir.
- Asenkron yapılarda gecikme etkileri senkron yapılara göre daha belirgin olabilir.
- Mod değeri ve kullanılan flip-flop sayısı birlikte düşünülmelidir.

#### Detaylı Açıklamalar

- Sayaçlar, dijital sistemlerde zamanlama, adresleme ve kontrol amaçlarıyla kullanılır. Bir sayaç devresinin davranışı, flip-flop çıkışlarının oluşturduğu durum dizisiyle tanımlanır.
- Asenkron sayaçlarda ilk flip-flop saatle tetiklenirken sonraki flip-floplar önceki çıkışlardan tetiklenebilir. Bu yapı basittir; ancak kademeli gecikmeler nedeniyle yüksek hızlı tasarımlarda sınırlamalar doğurabilir.
- Senkron sayaçlarda bütün flip-floplar aynı saat kenarında tetiklenir. Bu nedenle giriş fonksiyonlarının tasarımı daha fazla analiz gerektirse de zamanlama davranışı daha kontrollüdür.
- Mod-N sayaç tasarımında kullanılmayan durumlar oluşabilir. Bu durumların resetlenmesi veya geçerli döngüye yönlendirilmesi güvenilir çalışma için önemlidir.
### Ders 11 (Lab): Sayaç tasarımının uygulamalı kontrolü

#### Genel Konular

- Sayaç tasarımının uygulamalı kontrolü
  - Durum geçişleri simülasyon ortamında gözlenir.
  - Çıkışların beklenen mod ve sıra ile ilerleyip ilerlemediği incelenir.
- Flip-flop bağlantılarının doğrulanması
  - Saat, reset ve giriş bağlantıları çalışma için kritik öneme sahiptir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Saat bağlantısı ve reset davranışı yanlışsa sayaç doğru çalışmaz.
- Devre yalnızca ilk durumda değil, tüm durum döngüsü boyunca test edilmelidir.

#### Detaylı Açıklamalar

- Bu laboratuvar içeriği, sayaç devresinin pratikte nasıl doğrulanacağını öne çıkarır. Öğrenci yalnızca devreyi kurmakla kalmaz, saat darbeleri sonucunda oluşan durumları da izler.
- Reset ve başlangıç koşulu, sayaçların doğru döngüden başlaması için önemlidir. Yanlış reset bağlantısı sayaç dizisinin beklenmeyen bir durumdan başlamasına veya geçersiz durumda kalmasına neden olabilir.
### Ders 12: Sıralı devre tasarım adımları

#### Genel Konular

- Sıralı devre tasarım adımları
  - Problem durumlarla modellenir.
  - Durum diyagramı, durum tablosu, flip-flop uyarma tablosu ve çıkış fonksiyonları oluşturulur.
- Sayaç ve durum makinesi tasarımı
  - Belirli bir diziyi üreten veya belirli girişlere göre durum değiştiren devreler analiz edilir.
  - Kullanılmayan durumlar ve reset davranışı tasarımın parçasıdır.
- Karnaugh haritası ile giriş fonksiyonlarını sadeleştirme
  - Flip-flop girişleri için çıkarılan Boolean fonksiyonlar harita ile sadeleştirilir.
- Aritmetik ve kontrol mantığı ilişkisi
  - Kombinasyonel bloklar, sıralı devrelerin giriş/çıkış mantığında kullanılabilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Sıralı devre tasarımında adımlar atlanmamalıdır.
  - Durum diyagramından doğrudan devreye geçmek hata riskini artırır.
- Uyarma tablosu seçilen flip-flop türüne bağlıdır.
  - Aynı durum geçişi D, JK veya T flip-flop için farklı giriş fonksiyonları gerektirebilir.
- Kullanılmayan durumlar önemsiz kabul edilse bile tasarımda bilinçli ele alınmalıdır.

#### Detaylı Açıklamalar

- Sıralı devre tasarımında ilk olarak devrenin kaç duruma ihtiyaç duyduğu belirlenir. Durum sayısı, gerekli flip-flop sayısını doğrudan etkiler. `n` flip-flop ile en fazla `2^n` durum kodlanabilir.
- Durum kodlaması yapıldıktan sonra mevcut durum, girişler ve sonraki durum ilişkisi tabloya dökülür. Çıkışlar Moore veya Mealy yaklaşımına göre yalnızca duruma ya da durumla birlikte girişlere bağlı olabilir.
- Flip-flop türü seçildiğinde her durum biti için gerekli giriş fonksiyonları çıkarılır. Bu fonksiyonlar Karnaugh haritasıyla sadeleştirilir ve kapı düzeyinde kurulur.
- Tasarım doğrulamasında yalnızca geçerli durumlar değil, kullanılmayan durumlara girildiğinde devrenin ne yaptığı da incelenmelidir. Bu yaklaşım daha güvenilir devreler tasarlamayı sağlar.
### Ders 12 (Lab): Durum makinesi tasarımı uygulaması

#### Genel Konular

- Durum makinesi tasarımı uygulaması
  - İstenen davranış durum tablosuna dönüştürülür.
  - Flip-flop giriş fonksiyonları çıkarılır ve sadeleştirilir.
- Karnaugh haritası ile sıralı devre sadeleştirmesi
  - Sonraki durum ve çıkış fonksiyonları ayrı ayrı haritalanır.
- Flip-flop tabanlı devre simülasyonu
  - Saat darbeleriyle durum geçişlerinin doğru olup olmadığı kontrol edilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Sonraki durum fonksiyonları ve çıkış fonksiyonları karıştırılmamalıdır.
- Her flip-flop girişi için ayrı sadeleştirme yapılmalıdır.
- Simülasyon, tüm durum döngüsünü kapsamalıdır.

#### Detaylı Açıklamalar

- Laboratuvar çalışması, sıralı devre tasarım sürecinin uygulamalı halidir. Öğrenci önce beklenen davranışı durumlara ayırır, sonra bu durumları ikili kodlarla temsil eder.
- Mevcut durumdan sonraki duruma geçiş için seçilen flip-flopun hangi girişlere ihtiyaç duyduğu belirlenir. Bu giriş fonksiyonları Karnaugh haritalarıyla sadeleştirilerek daha az kapılı devre elde edilir.
- Simülasyon aşamasında devreye saat darbeleri verilir ve çıkışların istenen sırayı takip edip etmediği kontrol edilir. Bu test, teorik tablo ile pratik devreyi karşılaştırır.
### Ders 13: Register yapıları

#### Genel Konular

- Register yapıları
  - Register, birden fazla flip-flop kullanarak çok bitli veri saklayan devredir.
  - Paralel yükleme, kaydırma ve temizleme gibi kontrol girişleri bulunabilir.
- Kaydırmalı registerlar
  - Veri seri veya paralel biçimde girip çıkabilir.
  - Sağa/sola kaydırma işlemleri bitlerin konumunu saat darbeleriyle değiştirir.
- Sayaç ve register ilişkisi
  - Flip-flop tabanlı yapılar hem sayma hem saklama amacıyla kullanılabilir.
- Senkron/asenkron kontrol girişleri
  - Clear, preset, load gibi girişlerin saatle ilişkisi devre davranışını belirler.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Registerlarda her bit bir flip-flop ile saklanır.
  - Çok bitli veri için flip-floplar birlikte çalışır.
- Kaydırma işlemi veri aktarım yönüne göre yorumlanmalıdır.
  - Seri giriş ve seri çıkış yapıları bit akışını zamana yayar.
- Kontrol girişlerinin önceliği ve senkron/asenkron oluşu tasarımda önemlidir.

#### Detaylı Açıklamalar

- Registerlar dijital sistemlerde geçici veri saklamak için kullanılır. Her flip-flop bir biti tutar; dört bitlik register için dört flip-flop gerekir. Saat işaretiyle veri saklanır veya güncellenir.
- Kaydırmalı registerlar, saklanan bitleri her saat darbesinde bir konum sağa veya sola taşır. Bu yapı seri-paralel dönüşüm, veri geciktirme ve basit aritmetik kaydırma işlemlerinde kullanılabilir.
- Paralel yüklemeli registerlarda tüm bitler aynı anda register içine alınır. Seri girişli yapılarda ise veri bit bit alınır ve istenen konuma kaydırılır.
- Kontrol girişlerinin senkron veya asenkron olması önemlidir. Asenkron clear gibi girişler saat beklemeden register içeriğini değiştirebilirken, senkron load saat kenarında etkili olur.
### Ders 13 (Lab): Flip-flop, sayaç ve register uygulamaları

#### Genel Konular

- Flip-flop, sayaç ve register uygulamaları
  - Sıralı devre elemanları simülasyon ortamında kurulur ve test edilir.
  - Saat, reset, yükleme ve çıkış davranışları gözlenir.
- Karnaugh haritası destekli tasarım
  - Giriş fonksiyonları sadeleştirilerek daha az kapılı devreler oluşturulur.
- Çalışan devre üzerinden doğrulama
  - Tasarlanan devrenin tüm durumları ve kontrol girişleri denenir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Register ve sayaç devrelerinde saat davranışı mutlaka izlenmelidir.
- Kontrol girişleri doğru bağlanmadığında devre teorik tasarımdan farklı çalışır.
- Simülasyonda yalnızca tek giriş durumu değil, tüm durum dizisi test edilmelidir.

#### Detaylı Açıklamalar

- Laboratuvar çalışması, dönem boyunca işlenen kombinasyonel ve sıralı devre bilgilerini birleştirir. Öğrenci flip-flop tabanlı bir devreyi tasarlar, giriş fonksiyonlarını sadeleştirir ve simülasyonla doğrular.
- Register veya sayaç benzeri yapılarda devrenin doğru çalışması için saat ve kontrol girişleri kritik önemdedir. Her saat darbesinden sonra çıkışların beklenen duruma geçip geçmediği kontrol edilmelidir.
- Karnaugh haritası, sıralı devrelerde flip-flop giriş fonksiyonlarının sadeleştirilmesinde kullanılır. Bu sayede daha az kapı ile aynı davranışı veren devreler kurulabilir.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
