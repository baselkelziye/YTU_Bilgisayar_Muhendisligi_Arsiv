# Ders 1 Genişletilmiş Notu: Derse Giriş, Mikroişlemcilerin Tarihsel Gelişimi ve Temel Kavramlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. 8086 ve Minimum Mod
- 3. Mikroişlemcinin İhtiyaç Duyduğu Yardımcı Devreler
- 4. Hesaplamanın Tarihsel Gelişimi
- 5. Mikroişlemci Çağı: 4004'ten 8086'ya
- 6. 8086 ve 8088
- 7. Komut Kuyruğu ve Dallanma
- 8. 8086'nın Önemi ve Geriye Uyumluluk
- 9. CISC ve RISC
- 10. Genel Tanımlar: ALU, Yazmaç, Akümülatör
- 11. CPU, Mikroişlemci, Mikrodenetleyici ve SoC
- 12. Harvard ve Von Neumann Mimarisi
- 13. EPIC Mimarisi
- 14. Little Endian ve Big Endian
- 15. Veri, Adres ve Kontrol Yolları
- Örnek Sorular

## 1. Dersin Kapsamı

Dersin konusu Intel 8086 mikroişlemcisidir: iç yapısı, çalışma mantığı, assembly ile bağlantısı ve ardından çevre birimleri. Ders yalnız 8086'yı tanımakla kalmaz; mikroişlemcilere ilişkin genel kavramlar da verilir ve 286 ile sonraki mimarilerin 8086'dan nasıl ayrıldığına da bakılır. Assembly tarafında adresleme modları gibi konular, mikroişlemci tarafında gerekecek kadarıyla hatırlatılır. Hoca assembly dersini önceden almış olmanın bu ders için avantaj olduğunu, ön koşul olmasa da eksik olanların bu tarafı tamamlaması gerektiğini söyledi.

Slayttaki "Dersin Konusu" listesi şöyledir (ekrandan, 00:30:00):

- Genel tanımlar ve karşılaştırmalar
- 8086 µP minimum mod kullanımında: iç yapı, uç tanımları, yardımcı devreler, hafıza erişimi
- Arayüzler: 8255, 8251, 8254, DAC ve ADC, 8259

Hoca konuları şu sırayla tanıttı:

- **Giriş-çıkış birimlerinin programlanması:** Önce hazır entegre kullanmadan, özel (custom) olarak kurulan giriş-çıkış birimlerinin 8086'ya nasıl bağlanacağı (interface) ve nasıl programlanacağı.
- **8255 programlanabilir paralel arayüz:** Paralel giriş-çıkış için kullanılır. Buton, LED, yedi parçalı gösterge (seven segment), nokta matris ve tuş takımı (keypad) uygulamaları yapılır. Mod 0'da el sıkışma (handshaking) yoktur; Mod 1 ve Mod 2 el sıkışma sinyalleri içerir.
- **8251:** 8086'nın seri bir port üzerinden dış dünyaya veri göndermesini ve dışarıdan gelen seri veriyi almasını sağlayan seri haberleşme birimi.
- **8254:** Zamanlayıcı ve sayıcı entegresi. Her çevre biriminde olduğu gibi önce fiziki uç tanımları, uçların fonksiyonları, içindeki yazmaçlar ve görevleri, programlama akışı verilir; sonra örneklerle çalışması incelenir.
- **ADC ve DAC:** Analog değeri sayısala ve sayısal değeri analoga çeviren entegreler.
- **8259:** Kesme denetleyicisi (interrupt controller).
- **Bellek yapıları:** Bellek tipleri, 8086 ile arayüzü ve belleğin belirli adres aralıklarına yerleştirilmesi için adres çözümleme devresi.

### 1.1 Neden ADC ve DAC?

Fiziksel dünya analogdur: sıcaklık, basınç, gerilim gibi değerler süreklidir. Bu değerleri okumak, değerlendirmek ve denetlemek için önce ADC ile sayısala çevirmek gerekir. İşlemci hesaplamayı yaptıktan sonra sonucu bir motoru ya da fanı sürmek için kullanacaksa tekrar analog bir değer üretmesi gerekir; bu da DAC ile yapılır.

### 1.2 Yoklama ve Kesme

Hoca 8259'u tanıtırken iki yaklaşımı karşılaştırdı. Bir olayın gerçekleşip gerçekleşmediğini yazılımla kontrol ediyorsak, bunu örneğin bir denetim yazmacındaki bir bit üzerinden okuruz. Bit istenen değere gelmemişse yazmacı tekrar okuruz ve bu, değer gelene kadar boş bir döngüde sürer. Buna yoklama (polling) denir. Bu yapı işlemciyi aktif olarak yorar ve gereksiz işlem yükü oluşturur, bu yüzden pek istenmez.

Alternatifi kesme tabanlı çalışmadır. İşlemci şöyle ayarlanır: kesme istek ucundan bir istek geldiğinde o anda yürüttüğün işi kes, kesmeye ait alt programı yürüt, bitince yarıda bıraktığın işe devam et. Bunun için dış dünyadan kesme isteği oluşturacak bir arayüz gerekir. 8259 bunu sağlar; aynı işi özel kurulmuş arayüzlerle de yapmak mümkündür.

## 2. 8086 ve Minimum Mod

Ders boyunca 8086 **minimum modda** kullanılır. 8086 gerektiğinde 8087 matematik yardımcı işlemcisiyle (coprocessor) birlikte çalışabilir. Bu durumda birden fazla işlemcinin yollara hakim olması gerekir; 8086 yol denetimini diğerine devreder ve yapı karmaşıklaşır. Derste kurulacak devrelerde tek bir mikroişlemci, yani 8086'nın kendisi olacaktır. Minimum modun anlamı budur.

> **Ek bilgi (derste anlatılmadı):** 8086'da minimum ve maksimum mod, MN/MX̄ ucuna verilen lojik seviyeyle seçilir. Maksimum modda bazı kontrol uçları farklı işlev kazanır ve yol kontrol sinyalleri genellikle 8288 yol denetleyicisi üzerinden üretilir.

## 3. Mikroişlemcinin İhtiyaç Duyduğu Yardımcı Devreler

Hoca yardımcı devrelerin neden önemli olduğunu vurguladı: bir mikroişlemci, tanım gereği, yalnız enerji verildiğinde işlev gösteremez. 8086 üzerinden düşünürsek şunlara ihtiyaç vardır:

- **Saat darbesi üreteci:** İşlemcinin çalışması için gereken saat işaretini üretir.
- **Tutucular (latch):** 8086'da aynı uçtan farklı zamanlarda farklı işlevde değerler çıkar (zaman çoğullamalı uçlar). Bu farklı bilgilerin tutulup sisteme aktarılması için tutucu devreler gerekir.
- **Giriş-çıkış çevre birimleri:** İşlemcinin bir kullanıcısı vardır ve onunla etkileşmesi gerekir.
- **Program ve veri belleği:** Mikroişlemcinin içinde program saklanacak bir bellek yoktur. Programın çalıştırılabilmesi için uçlarına bellek elemanları bağlanmalıdır.

Bu yardımcı devreler varken enerji verildiğinde mikroişlemci işlev gösterebilir hale gelir.

## 4. Hesaplamanın Tarihsel Gelişimi

Hoca bugünkü mikroişlemcinin atası sayılabilecek hesaplama araçlarını sırasıyla anlattı: hesaplamayı otomatikleştiren önce mekanik, sonra elektrikli, elektromekanik, elektronik yapılar ve son olarak yarı iletken teknolojisiyle üretilen mikroişlemciler.

### 4.1 Mekanik Çağ

Slayta göre hesaplama için araç kullanımı MÖ 500'lü yıllara kadar uzanır ve Babilliler abaküsü kullanmıştır (ekrandan, 00:35:00). En basit hesaplama aracı, ilkokuldan bildiğimiz boncuklu abaküstür.

Ekranda gösterilen abaküs bir Çin abaküsüdür ve 16 tabanında kullanılır. Hoca burada öğrencilere boncukların değerinin nasıl hesaplandığını sordu (bkz. Örnek Sorular). Her çubuk bir onaltılık basamaktır. Karedeki abaküste her çubukta orta çizginin üstünde 2, altında 5 boncuk vardır. Üstteki her boncuk 5, alttaki her boncuk 1 değerindedir. Üstteki bir boncuk ortaya getirilince basamak değeri 5 olur, alttan eklenen her boncuk 1 ekler; böylece bir basamakta 15'e (F) kadar çıkılabilir. Hocanın ilginç bulduğu nokta, bu abaküsün 16 tabanında kullanılmasıdır.

Sonraki araç Pascal'ın dişlilerden oluşan mekanik hesap makinesidir (Pascaline). Basamaklar sağdan sola tek tek girilir. Örneğin 28 ile 35 toplanacaksa önce 28 girilir, sonra 35 eklenir: birler basamağı 5 birim döndürülür, onlar basamağı 3 birim döndürülür. Bir basamakta elde oluşursa dişli yapısı sayesinde bir sonraki basamak otomatik olarak bir birim daha döner. Yani içerideki dişli yapısı elde aktarımını sağlar.

> **Ders sonrası not:** Örnek altyazıda "28-35" ve bozuk bir anlatımla geçiyor; anlatılan işlem toplama olduğu için sonuç $28 + 35 = 63$ olur (birler basamağında $8 + 5 = 13$, elde 1).

Bir sonraki adım dokuma tezgahlarında delikli kart kullanımıdır. Desen, delikli kartlar üzerinden makineye bildirilir. Makinedeki iğneler bir deliğe denk gelirse delikten düşer ve o noktada ilmek oluşur; düşmezse ilmek oluşmaz. Önemli olan, makinenin nasıl çalışacağının dışarıdan programlanabilir bir arayüzle, yani delikli kartla denetlenebilmesidir.

Charles Babbage'ın Analytical Engine'i kavram olarak mekanik ve genel amaçlı bir bilgisayara tam karşılık gelir. Ancak teknik sıkıntılar yüzünden kendi döneminde tamamlanamamıştır.

### 4.2 Elektriksel Çağ

Slaytta şunlar yer alır (ekrandan, 00:40:00):

- 1800'lü yıllarda elektrik motoru Michael Faraday tarafından tasarlandı.
- Pascaline'in elektrik motorlu versiyonları geliştirildi.
- 1889 yılında Herman Hollerith elektrik motorlarıyla sürülen, veri işleyen bir makine geliştirdi.
- Bu makine 1890 Amerika nüfus sayımı sonuçlarının istatistik çıkarımı için kullanıldı.
- Veri girişinde delikli kartlar kullanılmıştı.

Hoca nüfus sayımında yaş, cinsiyet, aylık gelir, çocuk sayısı gibi bilgilerin sorulduğunu ve bunların delikli kartlara işlendiğini anlattı. Hollerith'in elektrik motorlu, elektromekanik cihazı, beş yıldan uzun sürecek bir değerlendirmeyi bunun yarısı kadar sürede bitirerek öne çıktı. Hollerith bu cihazı üretmek için Tabulating Machine adlı bir şirket kurdu; bu şirket bugünkü IBM'in temelini oluşturur.

### 4.3 Elektromekanik Dönem

1940'larda, savaş yıllarında, daha genel amaçlı ve daha hızlı programlanabilir cihazlar geliştirilmeye başlandı. Burada röle mantığıyla anahtarlama yapılır: röle açık ya da kapalı olarak iki farklı değer alabilir. Konrad Zuse'nin rölelerle gerçeklenmiş genel amaçlı bilgisayarı Z3, günümüz modern bilgisayarlarının temelini oluşturan ilk genel amaçlı bilgisayar olarak değerlendirilebilir.

### 4.4 Elektronik Çağ

Motor ve dişlilerle ya da rölelerle üretilen ikili değerlerin elektronik bileşenlerle de üretilebileceği görüldü. İlk elektronik bileşen vakum tüpüdür; bunlar elektronik olarak denetlenebilen anahtarlardır. Böylece daha az yer kaplayan, daha uzun çalışabilen ve daha az bozulan elektronik bilgisayarlar ortaya çıktı.

Hocaya göre ilk elektronik bilgisayar Colossus'tur. İkinci Dünya Savaşı'nda Almanların şifre sistemlerini çözmek için kullanıldı. Yalnız bu iş için geliştirildiği ve başka problemlerde kullanılamadığı için özel amaçlı bir bilgisayardır.

> **Ders sonrası not:** Hoca Colossus'u Alan Turing'e bağladı. Colossus büyük olasılıkla Tommy Flowers ve ekibi tarafından tasarlanmıştır; Turing'in adı daha çok şifre çözmede kullanılan elektromekanik Bombe makinesiyle anılır.

Genel amaçlı elektronik bilgisayar ise ENIAC'tır. Slayta göre (ekrandan, 00:45:00): genel amaçlı programlanabilir elektronik bilgisayar 1946'da Pensilvanya Üniversitesi'nde geliştirildi; adı Electronic Numerical Integrator and Calculator (ENIAC); büyük bir makine; 17000 vakum tüpü, 800 km kablo, 30 ton ağırlık, saniyede 100000 işlem.

ENIAC'ın programlanması, eski filmlerdeki telefon santrali operatörlerine benzer. Operatör bir fişi çekip başka bir sokete takarak hattı aktarır; ENIAC'ta da bir kablo bir soketten çıkarılıp başka sokete takılarak programın akışı yönlendirilir.

### 4.5 Yarı İletken Çağı

ENIAC gibi dev bir cihazda vakum tüplerinin ömrü yetersiz kalmaya başladı. Bu noktada yarı iletken teknolojisi keşfedildi ve geliştirildi. Önce transistörler bulundu. Transistör de elektronik olarak denetlenebilen bir anahtardır, ama boyutu, çektiği enerji, çalışma süresi ve dayanıklılığı bakımından vakum tüpünden çok üstündür. Ardından transistörlerin bir araya getirildiği entegre devreler geliştirildi.

## 5. Mikroişlemci Çağı: 4004'ten 8086'ya

### 5.1 Intel 4004

İlk mikroişlemci Intel'in 4004'üdür. Slayttaki özellikleri (ekrandan, 00:50:00):

- 4 bitlik mikroişlemci
- Adresleme kapasitesi: 4096 x 4 bit
- Komut seti 45 komuttan oluşuyor
- 30 gram ağırlığında
- Saniyede 50000 işlem (30 ton ENIAC saniyede 100000 işlem)
- Oyun ve küçük kontrol sistemlerinde kullanıldı
- Sonrasında daha yüksek frekanslı 4040 geliştirildi

Hoca 4004'ün hesap makinesi karmaşıklığındaki işler için kullanılabilecek ilk yarı iletken temelli mikroişlemci olduğunu söyledi.

> **Ders sonrası not:** Hoca 4004'ün "TTL yapısında" olduğunu söyledi, slaytta "RTL (direnç-transistör lojiği ile tasarlanmış)" yazıyor. 4004 büyük olasılıkla PMOS teknolojisiyle üretilmiş bir entegredir; iki ifade de tam doğru değildir.

**Bir mikroişlemcinin "4 bitlik" olması ne demek?** İşlemcinin içinde yazmaçlar (register) vardır; bunlar işlemlerin işlenenleri (operand) olarak kullanıldığı gibi işlem sonuçlarının saklandığı temel bellek birimleridir. Ayrıca işlemcinin dış dünyayla ve belleklerle haberleşmek için kullandığı veri uçları vardır. 4004'te 4 veri ucu vardır ve yazmaçları da 4 bitliktir. Bu yüzden 4 bitlik mikroişlemci denir.

**4096 x 4 ne anlama gelir?** 4096 adet bellek gözü vardır ve her gözde 4 bit saklanır. Hoca burada adres ve veri ucu sayısını sordu. Hesap şöyle kurulur: 4096 farklı durumu kaç bitle oluşturabiliriz? Bunun cevabı 4096'nın 2 tabanında logaritmasıdır:

$$4096 = 4 \cdot 1024 = 2^2 \cdot 2^{10} = 2^{12} \quad\Rightarrow\quad \log_2 4096 = 12$$

Demek ki 4096 farklı adres üretmek için 12 adres ucu gerekir. Bir göze erişildiğinde oradan 4 bit gelir; bu 4 bit tek seferde iki uç üzerinden aktarılamaz, 4 veri ucu gerekir. Sonuç: 12 adres ucu, 4 veri ucu.

> **Ders sonrası not:** Hoca soruyu sorarken bir an "4 tane adres ucu üzerinden" dedi (00:49:11); hemen ardından hesapla adres ucu sayısının 12 olduğunu gösterdi. Doğrusu 12'dir.

> **Ek bilgi (derste anlatılmadı):** Gerçek 4004 yongası, 12 bitlik adresi aynı 4 bitlik yol üzerinden üç parça halinde zaman çoğullamalı olarak gönderir. Derste yapılan hesap, mantıksal olarak gereken adres biti sayısını verir.

**45 komut için kaç bitlik komut kelimesi gerekir?** 45 komutun her biri birbirinden farklı (birbirinin varyasyonu değil) varsayılırsa: 5 bit $2^5 = 32$ farklı komut verir, yetmez. 6 bit $2^6 = 64$ farklı komut verir, yeter; $64 - 45 = 19$ kod kullanılmadan kalır. Cevap 6 bittir. Hoca günümüz işlemcilerinde varyasyonlarıyla birlikte komut sayısının binlere, on binlere vardığını da ekledi.

### 5.2 Intel 8008

Slayta göre (ekrandan, 00:55:00): 1971'de Intel 8008'i tanıttı; 8 bitlik bir mikroişlemci; 16 KB adresleme kapasitesi; toplamda 48 farklı komut; mikroişlemcilerin daha karmaşık sistemlerde kullanımı mümkün oldu.

8 bitlik olması, yazmaçlarının 8 bit ve veri yolunun 8 bit olması demektir.

> **Hocanın vurgusu:** Bu noktadan itibaren, aksi belirtilmedikçe her bellek gözünün 8 bit, yani 1 byte veri sakladığı varsayılacak. 4004'te gözler 4 bitlikti; o özel bir durumdu.

**16 KB için kaç adres ucu?** Her göz 1 byte olduğuna göre 16 KB, 16K adet göz demektir. Bilgisayar tarafında K = $2^{10}$ = 1024, M (mega) = $2^{20}$, G (giga) = $2^{30}$'dur. O halde:

$$16\text{K} = 2^4 \cdot 2^{10} = 2^{14}$$

14 bitin her birine 0 ya da 1 yazılarak en yüksek anlamlı basamak için 2, sonraki için 2, ... toplam $2 \cdot 2 \cdots 2 = 2^{14}$ farklı değer üretilebilir. Bu yüzden 14 adres ucu gerekir.

### 5.3 8080 ve Uç Uyumlu İşlemciler

8080'in adresleme kapasitesi 64 KB'dir. Bu dönemde yalnız Intel değil, başka firmalar da Intel'le uç uyumlu işlemciler üretti. Altair 8800 bilgisayarı da bu aileyle uyumlu bir işlemci kullanır; Bill Gates'in geliştirdiği BASIC diliyle bu bilgisayar üzerinden karşılaşılır.

## 6. 8086 ve 8088

Slayta göre (ekrandan, 01:00:00):

- 1978 yılında 8086 ve bir yıl sonra 8088 tanıtıldı.
- 16 bitlik mikroişlemciler.
- Komut yürütme süresi 400 ns (saniyede 2,5 milyon işlem).
- Adresleme kapasitesi 1 MB.
- 4 veya 6 byte'lık komut kuyruğu mevcut (sıradaki birkaç komutun birlikte okunması).
- Çarpma, bölme gibi komutların sunulması.
- Varyasyonları ile 20000'i bulan komut sayısı.

Slayttaki iki değer tutarlıdır: $1 / 400\,\text{ns} = 2{,}5 \times 10^6$ işlem/saniye.

Sonraki slayt (ekrandan, 01:10:00): 8086/8088 CISC mimarisindedir; yazmaç sayısında artış söz konusu; 8086 ve 8088 20 adet adres ucuna sahiptir; 8086 16, 8088 8 veri ucuna sahiptir.

İkisinin adres genişliği aynıdır: 20 adres ucu, $2^{20}$ = 1 MB. Fark veri yolundadır. 8088 16 bitlik bir veriye erişmek isterse bunu ancak iki çevrimde yapabilir. 8086'nın hem yazmaçları hem veri yolu 16 bit olduğu için ona doğrudan 16 bitlik demek kolaydır. 8088 ise veri yoluna bakılırsa 8 bitlik, yazmaçlarına bakılırsa 16 bitlik sayılabilir.

**Soru:** 8086'da adres ucu 20, veri ucu 16; ama 32 bitlik işlemcilerde ikisi de 32. Neden 8086'da farklı? **Cevap:** 32 adres ucuyla erişilebilen alan o dönemin bellekleri için yeterince büyüktü, daha ileri gitmeye gerek kalmadı. 32 bitlik bir işlemcide 32 bitlik adres yazmacı doğrudan adres yoluna, 32 bitlik veri yazmacı doğrudan veri uçlarına verilir; tasarım kolaydır. Zor olan, yazmaç genişliğinden daha geniş bir adres üretmektir. 16 bitlik 8086'da 20 bitlik adres üretmek için iki yazmaç birlikte kullanılır. Bunun nasıl yapıldığı ilerleyen derslerde anlatılacaktır.

## 7. Komut Kuyruğu ve Dallanma

İşlemci için en çok zaman alan işlerden biri, program belleğine gidip sıradaki komutu işlemcinin içine getirmektir. Getirildikten sonra bit dizisi çözülür, hangi kontrol işlemlerinin yürütüleceği belirlenir ve yürütülür; ama en maliyetli adım bellekten komut çekmektir. Yola çıkmak ve ilgili bellek birimini etkinleştirmek ek yük (overhead) getirir. Intel bu maliyeti azaltmak için komut kuyruğunu geliştirdi: bellek bir kez etkinleşmişken tek bir byte alıp dönmek yerine 4 veya 6 byte'lık komut bir seferde okunur ve işlemcinin içindeki kuyruğa konur.

Bu mantık, peş peşe ardışık komutlar yürütülürken çok iyi çalışır: bir sonraki adımda yürütülecek komut zaten işlemcinin içindedir.

**Soru:** Komut kuyruğu instruction cache mi? **Cevap:** Tam olarak değil. Kuyruk komutları yalnız sıralı olarak alır. Instruction cache ayrı bir yapıdır. Benzer bir işlev görebilirler ve ikisi bir arada da bulunabilir.

**Kuyruktaki komutlar ne zaman çöpe gider?** Sıradaki komut koşulsuz dallanma (JMP) ya da koşullu dallanma komutuysa işlemci hemen sonraki adresteki komuta değil, başka bir bölgedeki komuta gidecektir. Bu durumda kuyruğa çekilen komutlar kullanılamaz.

Günümüzde işlemciler için çalışılan konulardan biri, koşullu dallanmanın gerçekleşip gerçekleşmeyeceğini önceden tahmin etmektir: dallanma tahmini (branch prediction). Kuyruğa çekilen komutlar ve cache açısından önemlidir ve işlemcilerde donanım olarak gerçeklenir. Hoca ilgilenenlere bir de "dallanmasız kod yazımı" konusunu önerdi: koşullu dallanma komutu kullanmadan, kontrolleri başka yollarla yaparak program yazma yaklaşımı.

> **Ek bilgi (derste anlatılmadı):** Slayttaki "4 veya 6 byte" ayrımı iki işlemciye karşılık gelir: 8088'in komut kuyruğu 4 byte, 8086'nınki 6 byte'tır.

## 8. 8086'nın Önemi ve Geriye Uyumluluk

Günümüzde kullanılan Intel tabanlı işlemcilerin (örneğin masaüstündeki bir i9) geçmişe yönelik komut desteği vardır ve bu çizgi 8086'ya kadar uzanır. 8086'nın işleyiş mantığı öğrenilirse genel olarak mikroişlemciler anlaşılmış olur. Günümüz işlemcilerinin iç yapısı ise ders kapsamında incelenemeyecek kadar karmaşıktır; bu yüzden altyapı 8086 ile verilir. Günümüz bilgisayarları için de benzer çevre birimi analizleri yapılabilir, ama bunlar daha ileri konulardır.

**Soru:** Geriye yönelik destek nereye kadar gidiyor? **Cevap:** Hoca kesin bilmemekle birlikte en az 486'ya kadar gittiğini düşündüğünü söyledi: 486 için tanımlanmış assembly komutları bugünkü bilgisayarlarda da çalışır. Bugün 64 ve 32 bitlik programlar yazılabiliyor; 32 bitlik işlemciler 386/486 ile başlar. Ancak 8086, 80286 gibi 16 bitlik ve real mode kullanan işlemcilere yönelik programlar artık desteklenmez. Real mode belleğin tamamına erişebilmek demektir. Günümüzde her programın çalışacağı, yetkileri tanımlanmış bir bellek alanı vardır ve program bu alanın dışına çıkamaz. 8086 için yazılmış bir program bu güvenlik ve kısıtlamaları desteklemez.

> **Ders sonrası not:** Günümüz x86 işlemcileri büyük olasılıkla açılışta hâlâ real mode'da başlar ve 8086 komutlarını donanımda destekler; doğrudan çalışmayan, 16 bitlik real mode programların 64 bitlik işletim sistemi altında yürütülmesidir. Hocanın söylediği, işletim sistemi düzeyindeki bu kısıtlama olarak anlaşılmalıdır.

Sonraki işlemciler: 80286 ile erişilebilir kapasite 16 MB'a çıkar ($2^{24}$ bayt); 8086'ya benzer komutlarla bu alana erişmek için komutlarda ve yazmaçlarda farklılıklar gerekir. 80386 32 bitlik bir işlemcidir ve 32 adres ucuyla $2^{32} = 2^{30} \cdot 2^2$ = 4 GB adresleyebilir. Ardından Core ailesi gelir.

> **Ders sonrası not:** Hoca "8286" dedi; kastedilen 80286'dır.

## 9. CISC ve RISC

8086 ve 8088 CISC (Complex Instruction Set Computer) mimarisindedir. Karşılığı RISC'tir (Reduced Instruction Set Computer). Hoca slaytta RISC açılımını yanlış yazdığını belirtip düzeltti.

CISC'in özellikleri:

- Çarpma, bölme gibi karmaşık komutlar ve bunları destekleyen donanım vardır.
- Komutların yürütme süreleri farklıdır: örneğin toplama 2 saat çevriminde, çarpma 10 saat çevriminde gerçekleşebilir.
- Komutların boyları farklıdır: örneğin AX ile BX'i toplayan komut 2 byte, belleğin belirli bir bölgesinden veri okuyan bir MOV komutu 5 byte yer kaplayabilir.
- Karmaşık komutlar, süreler ve boylar nedeniyle işlemcinin içindeki kontrol devresi daha karmaşık tasarlanmak zorundadır. "Complex" adı buradan gelir.

RISC'te ise her komutun yürütme süresi bir, çok özel durumlarda iki saat çevrimidir ve her komutun boyu eşittir. Genelde çarpma gibi karmaşık komutlar bulunmaz; toplama, kaydırma ve lojik işlemlerin boyu ve süresi aynıdır.

Hocaya göre CISC daha çok genel amaçlı işlemcilerde, RISC daha temel seviyede, mikrodenetleyici seviyesindeki işlerde kullanılır. Cep telefonlarındaki mikrodenetleyiciler ya da SoC'ler temelde RISC mimarisindedir; komut genişlikleri, yürütme süreleri ve karmaşıklıkları CISC'e göre daha düşüktür.

**Soru:** (Bir öğrencinin CISC ve RISC'in basitliğiyle ilgili sorusu.) **Cevap:** Hoca basitliğin tek belirleyici olmadığını söyledi. CISC'te karmaşık bir komut kümesi gerçeklenmelidir; bu komutlar arka planda basit mikrokodlara dönüşse bile bunların peş peşe yürütülmesiyle gerçekleşir. RISC'te basit yapı zaten kendiliğinden vardır. İkisinin yürüttüğü kod ve komut kümesi kapsamı farklıdır.

<!-- BELİRSİZ: Öğrencinin sorusu altyazıya düşmedi (01:28:13-01:28:35); hoca da soruyu tam anlamadığını söyledi. -->

## 10. Genel Tanımlar: ALU, Yazmaç, Akümülatör

"Genel Tanımlar ve Karşılaştırmalar" slaytında şu kavramlar listelenir (ekrandan, 01:15:00): ALU, Register, CPU, µP, µC, SoC; Harvard arc., Von Neumann arc., CISC, RISC, EPIC; Little endian, Big endian, Data bus, Address bus, Control bus, Accumulator. Hoca bu kavramları öğrencilere sorarak işledi.

### 10.1 ALU ve Mikroişlemcinin Alt Birimleri

ALU, Arithmetic Logic Unit'tir: aritmetik ve lojik işlemlerin gerçekleştiği lojik devrelerdir. CPU ya da mikroişlemci ALU'yu kapsar; ALU onun bir alt birimidir.

Bir mikroişlemcinin içinde dört temel birim vardır:

- **ALU:** İşlemlerin gerçekleştiği birim.
- **Kontrol birimi:** Komut çözücü (instruction decoder) de bunun içinde sayılabilir.
- **Yazmaçlar (register):** İşlemlere işlenen olarak giren bellek elemanları.
- **Yollar:** Bu birimleri birbirine bağlayan yollar.

### 10.2 Yazmaç

Yazmaçlar bellek hiyerarşisinde işlem birimine en yakın olan, mikroişlemcinin içinde bulunan, en küçük kapasiteli ve en hızlı bellek birimleridir. İşlem sonuçlarının saklanması için de kullanılırlar.

### 10.3 Akümülatör

Akümülatör de bir yazmaç türüdür. 8086'da akümülatör AX'tir. Akümülatörü genel amaçlı bir yazmaçtan ayıran nedir? Hız değil: ikisine veri yazma, okuma ya da yola çıkarma hızları kabaca eşittir.

Fark, akümülatöre özel komutların ve donanımın bulunmasıdır. Hoca bunu 8086 komut kümesinden bir örnekle anlattı: aynı işlem BX üzerinden yapılınca 5 saat çevrimi sürüp 2 byte yer kaplarken, AX için tanımlı özel komutla 3 saat çevriminde yapılıp 1 byte yer kaplayabilir. Bu yüzden işlemler mümkün olduğunca akümülatör üzerinden yapılırsa daha hızlı çalışan bir program yazılmış olur.

<!-- BELİRSİZ: Hoca hangi komutu örnek aldığını söylemedi; 5/3 saat çevrimi ve 2/1 byte değerleri hocanın sözlü örneğidir, kareden doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** 8086'da bu farkın tipik örnekleri, akümülatöre özel kısa kodlamalardır: örneğin `ADD AX, imm16` veya `XCHG AX, reg` gibi komutların AX için ayrı, daha kısa makine kodları vardır; IN ve OUT komutları da yalnız AL/AX ile çalışır.

## 11. CPU, Mikroişlemci, Mikrodenetleyici ve SoC

**CPU ve mikroişlemci.** Mikroişlemci, yarı iletken teknolojisiyle birlikte CPU'nun içinde görev alan ayrık lojik devrelerin, ayrık entegrelerin tek bir çipte sunulmuş halidir. Yani CPU, mikroişlemcinin dağınık hali gibi düşünülebilir: ALU'nun ayrı, yazmaçların ayrı entegreler olarak bir anakart üzerinde bulunduğu durum da CPU'dur. CPU daha genel (ve daha ilkel olanı da kapsayan) bir kavramdır; mikroişlemci bir merkezi işlem biriminin bütün fonksiyonel birimlerinin tek bir entegrede sunulmuş halidir. Hoca bu karşılaştırmayı ekranda kutularla çizdi: ayrık birimlerden oluşan bir kart ile tek çip (ekrandan, 01:25:00).

**Mikroişlemci ve mikrodenetleyici.** Mikroişlemci tek başına enerji verilince çalışmaz; saat darbesi üreteci, yolları denetleyen yardımcı devreler, çevre birimleri ve bellek gerekir. Mikrodenetleyici bütün bu çevre birimlerini tek bir çipte sunan yapıdır. Mikroişlemci daha genel geçer bir işlem birimidir; mikrodenetleyici daha basit, günlük ve tekrarlı işleri yapmak için kullanılan, daha düşük kapasiteli bir birimdir. Mikroişlemci örnekleri: Motorola 6800, Intel 8086, Core işlemciler. Mikrodenetleyici örnekleri: Atmel firmasının mikrodenetleyicileri (Arduino kartlarında kullanılan ATmega gibi) ve PIC mikrodenetleyicileri.

**SoC (System on Chip).** Cep telefonlarında kullanılan yapının genel adıdır. Bir telefonun işlev görebilmesi için işlemci birimi, Wi-Fi modülü, GSM modülü, ekran sürme ve dokunmatik denetim birimi gerekir. Bunların tek bir çipte bir sistem olarak sunulduğu yapıya SoC denir. Mikrodenetleyiciden daha kapsamlı bir yapıdır.

## 12. Harvard ve Von Neumann Mimarisi

Bu iki mimari, program belleğinin veri belleğinden ayrı mı yoksa birleşik mi olduğuyla ilgilidir. Hoca ikisini ekranda çizdi.

**Harvard mimarisi.** İşlemci, program belleğiyle ayrı bir yol üzerinden, veri belleğiyle ayrı bir yol üzerinden haberleşir. Bu nedenle ayrı bir program adres ucu ve ayrı bir veri adres ucu olması gerekir. İki farklı yol grubu için ayrı denetleyiciler gerektiğinden denetim açısından daha karmaşıktır. Avantajı, program belleği ile veri belleğinin birbirine karışmamasıdır.

**Von Neumann mimarisi.** Program belleği ve veri belleği işlemciyle aynı yollar üzerinden haberleşir; aynı adres, veri ve kontrol uçlarıyla denetlenir. Kontrol birimleri daha azdır. Dezavantajı, program ile verinin birbirine karışabilmesidir: program da veri de RAM'dedir ve dikkatsiz durumlarda birbirini etkileyebilir.

8086 von Neumann mimarisindedir. Harvard mimarisine örnek olarak hoca PIC mikrodenetleyicilerini verdi; ekranda Harvard'ın yanına "Arm, Pic", von Neumann'ın yanına "8086" yazdı (ekrandan, 01:30:00).

## 13. EPIC Mimarisi

EPIC, birden çok komutun paralel ve hızlı yürütülmesine özelleşmiş bir mimaridir. RISC ve CISC'te birden fazla çekirdek olsa bile hangi komutların paralel yürütüleceğine donanım karar verir. EPIC'te ise paralel yürütülebilecek komutlar yazılım seviyesinde, derleyici tarafından belirlenir; böylece hangi komutların birlikte yürütülebileceği komut yürütülmeden önce bellidir. Örneği Intel'in Itanium mimarisidir.

## 14. Little Endian ve Big Endian

Her bellek gözünün 8 bit sakladığı varsayılmıştı. Ama 16, 32 ya da 64 bitlik veri tipleri de tanımlanabilir. Birden çok byte'tan oluşan bir veri belleğe nasıl yerleştirilir?

Hocanın örneği 12345678h değeridir. Her onaltılık basamak 4 bit olduğundan 8 basamak 32 bit eder. Bu değer 100h adresinden itibaren saklanacak; adresler 100h, 101h, 102h, 103h.

**Little endian:** Düşük anlamlı byte düşük adrese yerleşir. 8086 little endian çalışır. 100h adresine en düşük anlamlı byte olan 78h gelir:

```text
Adres   İçerik
100h    78h
101h    56h
102h    34h
103h    12h
```

**Big endian:** En yüksek anlamlı byte en düşük adrese yerleşir:

```text
Adres   İçerik
100h    12h
101h    34h
102h    56h
103h    78h
```

Yerleşim python ile kontrol edildi (`0x12345678` için little: 78 56 34 12, big: 12 34 56 78).

<!-- BELİRSİZ: Hocanın çizdiği bellek tablosu 5 dakikalık karelere düşmedi; değer altyazıdan alındı (01:30:28-01:33:10). Altyazıda 101h satırı ve big endian ara satırları bozuk. -->

## 15. Veri, Adres ve Kontrol Yolları

Bir mikroişlemcinin uçlarından fiziksel olarak dışarı çıkan üç yol vardır: veri yolu, adres yolu ve kontrol yolu. Bu yolların hepsi bütün çevre birimlerine ve bütün bellek birimlerine ulaştırılır.

Bütün birimler aynı yola bağlı olduğuna göre, aynı anda birden fazlası hatta veri çıkarsa çakışma olur. Bu yüzden işlemci her seferinde yalnız tek bir cihazla, çevre birimiyle ya da bellek birimiyle konuşabilmelidir. Bunu, verilen adres değerine göre yalnız o cihazı etkinleştiren adres çözümleme devreleri sağlar. Örneğin bir komut yürütülünce bir adres değeri çıkar; adres çözümleme devresi bu adrese göre hangi cihazla konuşulmak istendiğini belirler, o cihazı etkinleştirir ve diğerlerini devre dışı bırakır. Yine de işlemciden çıkan veri, adres ve kontrol işaretleri bütün cihazlara gider.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:34:08; abaküs ekranda, 00:35:00): Şekildeki 16 tabanında kullanılan Çin abaküsünde her çubuk bir onaltılık basamaktır. Boncukların değeri nasıl hesaplanır? Bir basamakta 15 (F) değeri üretilebilir mi?

> **Çözüm (derste verildi):** Üstteki boncukların her biri 5, alttakilerin her biri 1 değerindedir. Karedeki abaküste her çubukta üstte 2, altta 5 boncuk olduğundan en büyük değer $2 \cdot 5 + 5 \cdot 1 = 15$'tir; F üretilebilir.

**Soru 2** (derste sözlü, 00:49:32; ekrandan, 00:50:00): 4004'ün adresleme kapasitesi 4096 x 4 bittir. 4004'ün kaç adres ucu ve kaç veri ucu vardır?

> **Çözüm (derste verildi):** $4096 = 2^{12}$ olduğundan 12 adres ucu; her göz 4 bit olduğundan 4 veri ucu.

**Soru 3** (derste sözlü, 00:52:21): 4004'ün 45 komutu vardır. Bütün komutlar birbirinden farklı (varyasyon değil) kabul edilirse komut kelimesi en az kaç bit olmalıdır?

> **Çözüm (derste verildi):** $2^5 = 32 < 45 \le 64 = 2^6$, yani 6 bit. $64 - 45 = 19$ kod kullanılmaz.

**Soru 4** (derste sözlü, 00:55:05; ekrandan, 00:55:00): Her bellek gözü 1 byte ise 16 KB adresleme kapasitesine sahip 8008'in kaç adres ucu vardır?

> **Çözüm (derste verildi):** $16\text{K} = 2^4 \cdot 2^{10} = 2^{14}$ göz, yani 14 adres ucu.

**Soru 5** (derste sözlü, 01:07:14): Komut kuyruğuna alınan komutlar hangi durumda kullanılamaz, çöpe gider?

> **Çözüm (derste verildi):** Sıradaki komut koşulsuz (JMP) ya da koşullu bir dallanma komutuysa; işlemci sıradaki adrese değil başka bir bölgeye gideceği için kuyruktaki komutlar boşa gider.

**Soru 6** (derste sözlü, 01:11:47): RISC mimarisine örnek bir işlemci ya da mikrodenetleyici verin.

> **Çözüm (derste verildi):** Cep telefonlarında kullanılan mikrodenetleyiciler ve SoC'ler.

**Soru 7** (derste sözlü, 01:13:59 ve 01:14:40): ALU'nun açılımı nedir, CPU ile ilişkisi nedir? Bir mikroişlemcinin içindeki temel birimler nelerdir?

> **Çözüm (derste verildi):** Arithmetic Logic Unit; CPU (mikroişlemci) ALU'yu kapsar. Temel birimler: ALU, kontrol birimi (komut çözücü dahil), yazmaçlar ve bunları bağlayan yollar.

**Soru 8** (derste sözlü, 01:16:42 ve 01:16:57): 8086'da akümülatör hangi yazmaçtır? Akümülatör genel amaçlı bir yazmaçtan nasıl ayrılır?

> **Çözüm (derste verildi):** AX. Fark hızda değil, akümülatöre özel, daha kısa ve daha az saat çevrimi süren komutların ve donanımın bulunmasındadır.

**Soru 9** (derste sözlü, 01:18:58 ve 01:21:48): CPU, mikroişlemci ve mikrodenetleyici arasındaki fark nedir? Bir mikrodenetleyici örneği verin.

> **Çözüm (derste verildi):** CPU birimleri ayrık entegrelerle de kurulabilen genel kavramdır; mikroişlemci bu birimlerin tek çipte toplanmış halidir; mikrodenetleyici bunlara ek olarak saat, bellek ve giriş-çıkış gibi çevre birimlerini de tek çipte sunar. Örnek: Atmel ATmega (Arduino), PIC.

**Soru 10** (derste sözlü, 01:26:49): 8086 Harvard mimarisinde mi, von Neumann mimarisinde mi?

> **Çözüm (derste verildi):** Von Neumann.

**Soru 11** (derste sözlü, 01:30:28): 32 bitlik 12345678h değeri 100h adresinden itibaren 8086 belleğine yazılırsa 100h-103h adreslerinde ne bulunur? Big endian bir işlemcide ne olur?

> **Çözüm (derste verildi):** Little endian (8086): 100h = 78h, 101h = 56h, 102h = 34h, 103h = 12h. Big endian: 100h = 12h, 101h = 34h, 102h = 56h, 103h = 78h.

## Dersin Toparlaması

Bu ilk derste önce dersin kapsamı çizildi: 8086 minimum modda incelenecek, ardından 8255, 8251, 8254, ADC/DAC ve 8259 gibi çevre birimleri ile bellek arayüzü ve adres çözümleme ele alınacak. Yoklama ile kesme arasındaki fark ve bir mikroişlemcinin çalışması için gereken yardımcı devreler (saat üreteci, tutucular, çevre birimleri, bellek) bu yapının neden gerektiğini gösterdi. Abaküsten ENIAC'a, transistörden 4004, 8008 ve 8086'ya uzanan tarihçe üzerinden adres ucu sayısının $\log_2$ ile hesaplanması, komut kelimesi genişliği ve 8086 ile 8088 farkı işlendi.

Dersin ikinci yarısında temel kavramlar karşılaştırmalı olarak verildi: komut kuyruğu ve dallanma, CISC/RISC/EPIC, ALU, yazmaç ve akümülatör, CPU/mikroişlemci/mikrodenetleyici/SoC, Harvard ve von Neumann, little ve big endian ve ortak yollar üzerinde adres çözümlemenin rolü. 16 bitlik 8086'nın 20 bitlik adresi iki yazmaçla nasıl ürettiği ve zaman çoğullamalı uçlar sonraki derslerde ayrıntılı ele alınacak; kaydın sonunda ekranda kalan ikinci kavram slaytı da real mode, protected mode, virtual mode, prefetch queue, pipeline, offset memory model, time multiplexing, coprocessor ve cache kavramlarını listeliyor (ekrandan, 01:35:00); bu kayıtta bu kavramlar işlenmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
