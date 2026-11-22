# Ders 19 Genişletilmiş Notu: FET'lere Giriş (JFET, D-Type ve E-Type MOSFET)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. BJT'den FET'e geçiş
- 2. FET ile BJT karşılaştırması
- 3. FET türleri
- 4. JFET'in yapısı ve polarlanması
- 5. VGS = 0 iken JFET karakteristiği ve pinch-off
- 6. VGS'nin etkisi ve ikinci pinch-off
- 7. p-kanal JFET ve JFET sembolleri
- 8. Shockley denklemi ve transfer eğrisi
- 9. Veri sayfası değerleri ve JFET testi
- 10. D-type MOSFET
- 11. E-type MOSFET
- 12. Statik elektrik, VMOS ve CMOS
- 13. Özet tablo ve ders sonu sorusu
- Örnek Sorular
- Dersin Toparlaması

## 1. BJT'den FET'e geçiş

Hoca dersin amacının alan etkili transistörlere (FET) giriş yapmak ve konuyu bu derste bitirmek olduğunu, JFET ve MOSFET yapılarına bakılacağını söyledi. Önceki derslerde diyot ve bipolar eklemli transistör (BJT) bitirilmiş, BJT ile ilgili örnekler çözülmüştü.

BJT için öne çıkan nitelik, onun akım kontrollü bir eleman olmasıydı. BJT, npn ya da pnp yapısındaki bir transistördür. Baz akımı $I_B$ üzerinden kolektör ve emetör akımları bulunur:

$$I_C = \beta I_B, \qquad I_E = I_C + I_B$$

BJT derslerinde $V_{BE}$ ve $V_{CE}$ gibi gerilimler birçok örnekte hesaplanmıştı. Hepsinde ortak nokta, $I_C$'nin $I_B$'ye göre değişmesiydi; yani kontrol akım üzerindendi. FET'te ise kontrol gerilim üzerinden olacaktır.

## 2. FET ile BJT karşılaştırması

Hoca karşılaştırmayı slayttan anlattı (ekrandan, 00:15:00).

**Benzerlikler:**

- İkisi de yükselteç (amplifier) olarak kullanılır.
- İkisi de anahtarlama elemanı olarak kullanılır; laboratuvarda yapılan anahtarlama devreleri buna örnektir.
- İkisi de empedans uydurma (impedance matching) devrelerinde kullanılabilir. Hoca bu konuya BJT'de çok az değinildiğini, gerilim bölücü mantığıyla çalışan bir yaklaşım olduğunu ve çok önemli olmadığını söyledi.

**Farklar:**

- FET gerilim kontrollü, BJT akım kontrollüdür. FET'in adı Field Effect Transistor (alan etkili transistör) ifadesinden gelir.
- FET'in giriş empedansı yüksektir, BJT'nin kazancı yüksektir. BJT'de kondansatörler çıkarılarak DC analiz yapılmış, yükselteç olarak çalışmasından da söz edilmişti; orada yüksek kazançlar söz konusuydu. FET'te ise giriş empedansı çok yüksek olduğu için, BJT'deki baz akımına karşılık gelen bir akım FET'in gate ucunda oluşmaz. Gerilim kontrollü olmasının mantığı da buradan çıkar.
- FET sıcaklık değişimlerinden daha az etkilenir ve tümleşik devrelerde (IC) daha kolay gerçeklenir.
- FET statik elektriğe BJT'den daha duyarlıdır.

Hoca gerilim kontrolünün akım kontrolünden genelde daha iyi olduğunu, çünkü akımın sıcaklıktan etkilendiğini, sıcaklığın direnç üzerinden etkisi bulunduğunu söyledi. FET'in en büyük dezavantajı ise gerilim kontrollü olduğu için statik enerjiden etkilenmesidir. Kapı koluna dokununca çarpılmak gibi, insanın üzerindeki statik elektrik FET'teki değerlerin kaymasına yol açabilir. Bunun çözümü iyi bir yalıtımdır.

## 3. FET türleri

BJT'nin npn ve pnp tipleri malzeme yapısından doğan bir çeşitlenmeydi. FET'lerde de n ve p yapılar olacaktır, ama bunun üstünde kullanıma göre bir sınıflandırma daha vardır:

- **JFET (Junction FET, eklemli FET):** En temel FET tipidir. Adındaki J, BJT'deki gibi "junction" (eklem) anlamına gelir.
- **MOSFET (Metal Oxide Semiconductor FET):** İç yapısında bir metal oksit katmanı bulunur. İki alt türü vardır:
  - D-type (depletion, azaltmalı) MOSFET
  - E-type (enhancement, çoğaltmalı) MOSFET

FET'lerde BJT'deki gibi "npn transistör, pnp transistör" denmez. FET'te önemli olan kanaldır: drain ile source uçları arasındaki yarı iletkenin tipi. Bu yüzden n-kanal FET ve p-kanal FET denir.

## 4. JFET'in yapısı ve polarlanması

### 4.1 Yapı ve uçlar

n-kanal JFET'te drain (D) ve source (S) n-kanalın iki ucuna, gate (G) ise kanalın iki yanındaki p tipi malzemeye bağlıdır (ekrandan, 00:20:00). p ile n'nin birleştiği yerlerde, diyotta ve transistörde olduğu gibi tükenme bölgesi (depletion region) vardır. Hoca bütün yarı iletken yapılarda mantığın aynı olduğunu hatırlattı: diyotta doğru polarmada tükenme bölgesi kapanıyordu, transistörde baz-emetör doğru, baz-kolektör ters polarmalıydı. JFET'te de amaç kanalın boyutunu değiştirmektir; bu, gate tarafındaki iki tükenme bölgesi üzerinden yapılır.

Uçların adları değişmiştir. BJT'deki karşılıklar:

- baz (base) → gate
- kolektör (collector) → drain
- emetör (emitter) → source

### 4.2 Musluk benzetmesi

Hoca çalışma ilkesini bir musluk benzetmesiyle anlattı. Source Türkçede "kaynak" demektir; bir su kaynağında suyun çıktığı yer gibi, elektron akışının başladığı yer olarak düşünülmelidir. Drain, akışın gittiği yerdir; bir gider gibi. Gate ise source'tan gelen elektronların miktarını ayarlayan musluktur; aradaki kanalın genişliğini değiştirir.

### 4.3 Drain-source polarlaması

Hoca drain ile source arasına bir batarya, gate ile source arasına da ayrı bir kaynak bağlayacağını, şimdilik gate-source'u göz ardı ederek drain-source kaynağının nasıl bağlanması gerektiğini sordu (ekrandan, 00:25:00).

**Soru:** Elektronların source'tan drain'e akması için drain-source arasına nasıl bir polarma uygulanmalıdır?

**Cevap:** Bir öğrenci source'a eksi, drain'e artı bağlanması gerektiğini söyledi. Hoca bunu doğruladı: drain artı olmalıdır ki elektronları çeksin, source eksi olmalıdır ki elektronları itsin.

Elektronlar source'tan drain'e akarken akım, elektron akışının tersi yönünde, drain'den source'a doğru olur. Bu akıma drain akımı $I_D$ denir. Özetle n-kanal bir FET'in çalışması için drain artı, source eksi olacak biçimde $V_{DS}$ uygulanır.

## 5. VGS = 0 iken JFET karakteristiği ve pinch-off

### 5.1 VDS artırılınca ne olur

Gate ile source arasındaki gerilim sıfır alınsın ($V_{GS} = 0$, gate'e bir şey bağlanmamış gibi) ve $V_{DS}$ zamanla 1 V, 2 V, 3 V, 4 V diye artırılsın. Hoca bunu şöyle açıkladı: drain'den artı verilip elektronlar çekiliyor, source'tan eksi verilip itiliyor, ama kanalın yanında p bölgesi duruyor ve bu bölge sönümlenmiyor. Denge için tükenme bölgesi, artan gerilime bağlı olarak genişler. Ne kadar fazla gerilim verilirse tükenme bölgesi o kadar büyür.

Akım eğrisi başlangıçta hızla yükselir. Bu bölgede kanal henüz bir direnç gibi davranır; bu yüzden bu bölgeye ohmik bölge (ohmic region) denir. Belli bir noktadan sonra kanal kıstırılır ve akım artık artmaz; bu bölgeye doyum bölgesi (saturation region) denir (ekrandan, 00:35:00).

> **Ders sonrası not:** Hoca hortum benzetmesiyle "hortumu sıkınca su daha şiddetli akar; burada da kanalı kısarak akımı büyütüyoruz, tükenme bölgesi büyüdüğü için $I_D$ artıyor" dedi, bir yerde de bu noktada $I_D$'nin sıfır olacağını söyledi. Doğrusu: ohmik bölgede $I_D$, $V_{DS}$ arttığı için artar; kanalın daralması akımı artırmaz, tersine kanal direncini büyütür ve eğrinin yatıklaşmasına yol açar (slaytta da "Increasing resistance due to narrowing channel" yazar, ekrandan 00:30:00). Pinch-off noktasında $I_D$ sıfır değildir, en büyük değeri $I_{DSS}$'dir. Hoca da hemen ardından bunu belirtti.

### 5.2 Pinch-off, VP ve IDSS

Kanalın neredeyse kapandığı noktaya pinch-off (kıstırma, hocanın deyişiyle kesim noktası) denir. $V_{GS} = 0$ iken bu noktadaki $V_{DS}$ değeri pinch-off gerilimi $V_P$'dir (ekrandan, 00:30:00). Bu noktada ulaşılan akım, o FET'te $V_{GS} = 0$ için elde edilebilecek en büyük akımdır. Buna $I_{DSS}$ (drain-source doyum akımı, saturation) denir.

$I_{DSS}$ önemlidir, çünkü FET'in $I_D$'yi kontrol edebildiği üst sınırdır. Kanalın tamamen kapanması gerçekte imkânsızdır; aradaki ince yoldan geçen akım, alınabilecek en büyük akımdır. Grafikte eğrinin neden sıfıra inmediği de buradan anlaşılır: tamamen kapanmadan önce akımın artık artamadığı nokta pinch-off'tur.

Slayttaki grafikte $V_{GS} = 0$ V eğrisi için $I_{DSS} = 8$ mA'dir ve $V_P$ yaklaşık 4-5 V civarındadır (ekrandan, 00:35:00).

> **Ders sonrası not:** Slayttaki "Any further increase in $V_{GS}$ does not produce any increase in $I_D$" cümlesinde $V_{GS}$ büyük olasılıkla $V_{DS}$ olmalıdır; hoca da anlatımda drain-source gerilimi üzerinden açıkladı (ekrandan, 00:30:00).

### 5.3 Breakdown

$I_{DSS}$'ye ulaşıldıktan sonra $V_{DS}$ artırılmaya devam edilirse (grafikte sağa gidilirse) breakdown olur: $I_D$ kontrolsüz biçimde artar ve FET bozulur (ekrandan, 00:35:00). Hocanın örneği: $V_{GS} = -2$ V iken $V_{DS}$ 25 V'tan 30 V'a çıkarılırsa FET bozulur ve $I_D$ artık kontrol edilemez.

> **Ders sonrası not:** Hoca $V_{GS}$ $-2$ V yerine $-1$ V ya da 0 V verilseydi breakdown'a daha erken gidileceğini söyledi. Büyük olasılıkla doğrusu terstir: kırılma, gate-drain ekleminin ters gerilimi $V_{DG} = V_{DS} - V_{GS}$ kırılma değerine ulaşınca olur. $V_{GS}$ daha negatif oldukça aynı $V_{DG}$'ye daha küçük $V_{DS}$ ile ulaşılır; yani kırılma daha düşük $V_{DS}$'de görülür.

## 6. VGS'nin etkisi ve ikinci pinch-off

### 6.1 Gate-source ters polarması

n-kanal JFET'te drain ve source n tipi, gate p tipidir. Gate-source arasına negatif gerilim verilirse (gate eksi, source artı) tükenme bölgesinin büyümesine katkı sağlanır (ekrandan, 01:10:00; slaytta "As $V_{GS}$ becomes more negative, the depletion region increases" yazar). Hoca bunu denge kavramıyla açıkladı: gate'teki p malzemenin bir kısmı sönümlenir ve denge daha erken kurulur. Sonuç olarak:

- Pinch-off daha düşük bir $V_{DS}$ değerinde gerçekleşir.
- $V_{DS}$ artırılsa bile doyum akımı $I_{DSS}$'nin altında kalır ($I_D < I_{DSS}$).

Slayttaki karakteristikte $V_{GS} = 0, -1, -2, -3$ V eğrileri sırasıyla yaklaşık 8; 4,5; 2; 0,5 mA'de doyuma ulaşır (ekrandan, 00:35:00). Pinch-off noktalarının geometrik yeri (locus of pinch-off values) kesikli bir eğri olarak çizilmiştir; bu eğrinin solu ohmik bölge, sağı doyum bölgesidir.

> **Ek bilgi (derste anlatılmadı):** Standart açıklamada n-kanal JFET'te gate-kanal eklemi ters polarmalandığında tükenme bölgesi kanalın içine doğru genişler ve kanalın iletken kesiti daralır. Bu yüzden aynı $V_{DS}$ için daha az akım geçer. Gate eklemi ters polarmalı olduğundan gate akımı pratikte sıfırdır ($I_G = 0$).

### 6.2 İkinci pinch-off: VGS(off)

$V_{GS}$ yeterince negatif yapılırsa, drain-source polarmasına gerek kalmadan tükenme bölgesi kanalı kapatır. Hocanın örneğinde $-4$ V verildiğinde drain-source arası ne olursa olsun akım geçmez. Bu gerilime ikinci pinch-off noktası ya da $V_{GS(\text{off})}$ denir; slayttaki örnekte $V_{GS} = -4\ \text{V} = V_P$'dir (ekrandan, 00:35:00).

Hoca iki pinch-off'u şöyle ayırdı:

- Birinci pinch-off: $V_{GS} = 0$ iken $I_D$'nin $I_{DSS}$'ye eşit olduğu $V_{DS}$ değeri. $I_{DSS}$'yi belirler.
- İkinci pinch-off: $V_{DS}$'ye bakmaksızın $I_D$'yi sıfırlayan $V_{GS}$ değeri ($V_{GS(\text{off})}$).

Bir problemi çözmek için iki şeyin bilinmesi gerekir: $I_{DSS}$ ve $V_P$. Bunlar bu iki pinch-off üzerinden bulunur. Slaytta iç dirençle ilgili bir formül de vardı; hoca ona girmeye gerek olmadığını söyledi.

## 7. p-kanal JFET ve JFET sembolleri

### 7.1 p-kanal JFET

p-kanal JFET'te yapı aynıdır, yalnız polariteler terstir. Hoca slayttaki artı-eksi işaretlerinin yanlış yazıldığını, şeklin ise doğru olduğunu söyledi. Bu kez pozitif yüklerin (deliklerin) hareketi söz konusudur ve source'tan drain'e doğrudur. $V_{DS}$ negatif uygulanır; grafikte $V_{DS}$ eksi değerlerle gösterilir. $V_{DS}$'nin büyüklüğü arttıkça $I_D$, $I_{DSS}$'ye ulaşana kadar artar.

Gate burada n tipidir. Bu yüzden akımı azaltmak için $V_{GS}$ pozitif yapılır: $V_{GS} = 0$ iken akım en yüksektir, $+1$ V, $+2$ V ... verildikçe azalır ve pinch-off daha erken gelir. Breakdown da aynı biçimde geçerlidir: belli bir noktadan sonra $V_{DS}$'yi artırmak JFET'i bozar.

**Soru:** Gate'e negatif bağlanırsa pinch-off'a daha mı geç ulaşılır?

**Cevap:** Hoca, (p-kanal JFET'te) gate'e negatif vermenin tükenme bölgesini küçültmek demek olduğunu söyledi: dengede olan bölge dengesiz duruma gelir; tükenme bölgesinin oluşması için bir tarafın yükünün fazla olması gerekir. Benzetme olarak barajı verdi: barajın önüne ne kadar çok kum atılırsa o kadar çok su birikir.

### 7.2 Semboller

Hoca sembollerin de bilinmesi gerektiğini belirtti (ekrandan, 00:40:00). Ok her zaman n tipi bölgeyi gösterir; bu kural transistörde, JFET'te ve MOSFET'te geçerlidir. FET'lerde kanaldan söz edildiği için, ok içeri bakıyorsa drain-source kanalı n tipidir, yani n-kanal JFET'tir. Ok dışarı bakıyorsa p-kanaldır.

Hoca BJT sembolünü de hatırlattı: emetördeki ok içeri (baza) bakıyorsa baz n tipidir ve transistör pnp'dir; dışarı bakıyorsa npn'dir.

Sembol üzerinde n-kanal için kural yinelenir: drain artı, source eksi beslenir. Gate p tipi olduğundan, $I_D$'yi daha düşük seviyelerde ayarlamak için gate-source ters polarmalı bağlanır.

## 8. Shockley denklemi ve transfer eğrisi

### 8.1 Denklem ve uç noktaları

E-type MOSFET dışındaki bütün FET'lerde (JFET ve D-type MOSFET) kullanılacak denklem şudur (ekrandan, 00:55:00 ve 01:05:00):

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

Hoca denklemi iki uç noktada inceledi:

- $V_{GS} = 0$ ise $V_{GS}/V_P = 0$, parantez $1$ olur, karesi $1$'dir: $I_D = I_{DSS}$. Bu, $V_{GS} = 0$ iken $I_D$'nin $I_{DSS}$'ye eşit olduğu sözüyle uyumludur.
- $V_{GS} = V_P$ ise $V_P/V_P = 1$, parantez $1 - 1 = 0$ olur: $I_D = 0$. Gate-source'a pinch-off gerilimi verildiğinde tükenme bölgesi kanalı kapattığı için akım $V_{DS}$'ye bakmaksızın sıfırdır.

Denklem, iki uç noktada anlatılanları doğrular. $I_D$ burada $V_{GS}$'ye bağlı olarak geçmesi beklenen akımdır.

### 8.2 Transfer eğrisi

Transfer eğrisi, belirli bir $V_{GS}$ için $I_D$ değerini gösterir (ekrandan, 00:45:00). Sağdaki çıkış karakteristiği ($I_D$-$V_{DS}$) ile soldaki transfer eğrisi ($I_D$-$V_{GS}$) aynı şeyi söyler; yalnız doyum bölgesindeki değerler sola taşınmıştır. $V_{GS} = 0$ iken $I_D = I_{DSS} = 8$ mA, $V_{GS} = V_P = -4$ V iken $I_D = 0$'dır. Aradaki değerler denklemden gelir. Slayttaki değerlerle (python ile doğrulandı):

| $V_{GS}$ (V) | $1 - V_{GS}/V_P$ | $I_D$ (mA) |
|---|---|---|
| 0 | 1 | 8 |
| $-1$ | 0,75 | 4,5 |
| $-2$ | 0,5 | 2 |
| $-3$ | 0,25 | 0,5 |
| $-4$ | 0 | 0 |

### 8.3 Üç adımlı çizim

Hoca transfer eğrisinin üç adımda çizildiğini söyledi:

1. $V_{GS} = 0$ iken $I_D = I_{DSS}$ olmalıdır. Örneğin $V_{DS} = 5$ V civarında, $V_{GS} = 0$ için akım $I_{DSS}$'dir; bu, eğrinin $I_D$ eksenini kestiği noktayı verir.
2. Akımın sıfır olduğu nokta bulunur: gate-source geriliminin tek başına kanalı kapattığı nokta, yani $V_{GS} = V_P$. Bu, eğrinin $V_{GS}$ eksenini kestiği noktadır.
3. Aradaki eğrinin biçimini görmek için birkaç farklı $V_{GS}$ değerinde $I_D$ hesaplanır.

Hoca birinci adımda pinch-off noktasındaki $V_{GS}$'nin aslında önemsiz olduğunu, çünkü $V_{GS} = 0$ olduğundan $0/V_P$'nin her durumda sıfır çıkacağını da belirtti.

### 8.4 Kestirme değerler

Slaytta bazı kestirme değerler yazar; hoca bunların denklemden çıktığını ve ezberlenmesine gerek olmadığını söyledi (ekrandan, 00:55:00 ve 01:05:00):

- $V_{GS} = V_P/2$ ise $I_D = I_{DSS}(1 - 1/2)^2 = I_{DSS}/4$.
- $V_{GS} \approx 0{,}3V_P$ ise $I_D = I_{DSS}(1 - 0{,}3)^2 = 0{,}49\,I_{DSS} \approx I_{DSS}/2$.

## 9. Veri sayfası değerleri ve JFET testi

Hoca bir JFET'in veri sayfasında (datasheet) karakteristiklerin yazdığını gösterdi. Okuduğu değerler:

- Cut-off gerilimi, yani $V_{GS(\text{off})}$ ya da ikinci pinch-off. <!-- BELİRSİZ: hoca "burada 15'miş" ve "gate source voltage ... 15 VDC" dedi; veri sayfası slaytının karesi yok, değer ve birim doğrulanamadı. -->
- $I_{DSS}$ en çok 5 mA'dir. Bu değerler türe, sıcaklığa ve başka koşullara göre değişebilir.
- Gate-source kırılma gerilimi ($V_{GSS}$ diye okundu) $-25$ V'tur; gate-source arasına $-25$ V verilirse eleman bozulur.
- En büyük değerler (maximum ratings) tablosunda drain-source gerilimi en çok 25 V'tur; aşılırsa breakdown olur.
- Bacak numaraları (hangi bacağın drain, hangisinin source olduğu) da veri sayfasında yazar.

Bir p-kanal JFET örneğinde hoca, FET'lerin üstünde yalıtımı artırmak için bir kılıf bulunduğunu, çünkü statik enerjiden çok etkilendiklerini söyledi. p-kanalda ok dışarı bakar.

JFET'leri test etmek BJT'lere göre daha zordur. BJT'de akımın geçip geçmediğine bakan basit test cihazları vardır; FET gerilim tabanlı olduğu için bunlar yeterli değildir. Özel FET test cihazları ve daha ayrıntılı devreler kullanılır.

## 10. D-type MOSFET

### 10.1 Yapı

FET'lerin ikinci büyük grubu MOSFET'lerdir (ekrandan, 00:50:00). Slayta göre MOSFET'ler JFET'e benzer özelliklere ve onları çok kullanışlı yapan ek özelliklere sahiptir. İki türü vardır: depletion-type (D-type) ve enhancement-type (E-type).

D-type MOSFET'te yine bir kanal yapısı vardır ve adı kanala göre verilir: n-kanal D-type MOSFET'te drain ile source'u birbirine bağlayan kanal n tipidir. Bunun dışında substrate (alttaş) denen bir bacak daha vardır; bu bacak p tipi malzemeye bağlıdır. Silisyum dioksit (SiO$_2$) katmanı adındaki "metal oksit" kısmını oluşturur.

> **Ders sonrası not:** Hoca D-type ve E-type MOSFET'lerde "gate p tipi" dedi. MOSFET'te gate bir metal elektrottur ve kanaldan SiO$_2$ katmanıyla yalıtılmıştır; n-kanal MOSFET'te p tipi olan alttaştır (substrate). Altyazıda "saturation source" diye geçen uç da büyük olasılıkla substrate (SS) ucudur.

### 10.2 Depletion modu ve enhancement modu

Hocaya göre D-type MOSFET'in JFET'ten farkı yalnız gate-source polarmasının işaretinin değiştiği durumda ortaya çıkar (ekrandan, 00:55:00):

- **Depletion modu ($V_{GS} \le 0$):** $V_{GS} = 0$ iken $I_D = I_{DSS}$; $V_{GS} < 0$ iken $I_D < I_{DSS}$. Bu kısım JFET'in tamamen aynısıdır ve aynı Shockley denklemi geçerlidir.
- **Enhancement modu ($V_{GS} > 0$, n-kanal):** JFET bu bölgede çalışmaz. D-type MOSFET ise çalışır ve $I_D$'yi $I_{DSS}$'nin üstüne çıkarabilir.

Yani D-type MOSFET depletion ve enhancement modlarında birlikte çalışabilir; depletion modu normal JFET'in modudur. Slayttaki örnekte $I_{DSS} = 8$ mA ve $V_P = -6$ V'tur. Denklemle (python ile doğrulandı):

- $V_{GS} = +1$ V: $I_D = 8\,(1 + 1/6)^2 \approx 10{,}9$ mA (eğrideki $10{,}9$ değeri)
- $V_{GS} = 0{,}3V_P = -1{,}8$ V: $I_D = 8\,(0{,}7)^2 \approx 3{,}9$ mA $\approx I_{DSS}/2$
- $V_{GS} = V_P/2 = -3$ V: $I_D = 8\,(0{,}5)^2 = 2$ mA $= I_{DSS}/4$
- $V_{GS} = V_P = -6$ V: $I_D = 0$

p-kanal D-type MOSFET'te kanal p, alttaş n tipidir. Bu durumda pozitif $V_{GS}$ akımı düşürür (depletion modu), negatif $V_{GS}$ ise akımı artırır (enhancement modu).

> **Ders sonrası not:** Hoca n-kanalda pozitif $V_{GS}$'yi "ters polarma" diye adlandırdı. JFET'te n-kanalda pozitif $V_{GS}$, gate-kanal p-n eklemini doğru polarmalar; bu yüzden JFET bu bölgede kullanılmaz. MOSFET'te gate yalıtılmış olduğu için bu bölgede de gate akımı akmaz ve eleman çalışabilir.

### 10.3 Sembol

MOSFET sembolünde fark, alttaş (substrate) için ayrı bir ucun bulunmasıdır. Ok yine n tipi bölgeyi gösterir: n-kanalda içeri, p-kanalda dışarı bakar; ama ok bu kez gate'te değil, alttaş ucundadır. Alttaşın source'a bağlandığı birleşik gösterim de vardır. Özellikler veri sayfasında yazar.

Hoca şunu da vurguladı: şimdiye kadar incelenen bütün FET'lerde hep gerilimden söz edildi. $I_D$ akımının gerilimdeki değişimlere göre değiştiği gözlendi; dersin başındaki ilk fark da buydu.

## 11. E-type MOSFET

### 11.1 Yapı ve eşik gerilimi

E-type MOSFET'te de metal oksit (silisyum oksit) katmanı vardır, ama hazır bir kanal yoktur. Fark budur. Kanal fiziksel olarak bulunmasa da drain ve source n tipi olduğu için yine "n-kanal E-type MOSFET" denir.

E-type'ta gate-source gerilimi belli bir eşiğe (threshold, $V_T$) ulaşana kadar $I_D$ akımı oluşmaz. Eşik aşıldıktan sonra akım oluşur ve $V_{GS}$ arttıkça artar. n-kanal E-type'ta $V_{GS}$ pozitif verilir; yani JFET'te kullanılmayan ve D-type'ta enhancement modu denen bölge, E-type'ta ayrıntılandırılır. Hoca bunu, kanalı daraltan tükenme etkisinin tersine, pozitif gerilimin akımı artırdığı biçiminde anlattı.

p-kanal E-type'ta polariteler terstir: $V_{GS}$ negatif yapıldıkça $I_D$ artar.

Grafikte JFET ve D-type MOSFET'in aksine, diyottaki gibi bir eşik vardır: eşiğe kadar akım geçmez, eşikten sonra gerilim arttıkça $I_D$ artar. Kontrol bu şekilde sağlanır.

### 11.2 Denklem ve k sabiti

Hoca burada formülün tamamen değiştiğini vurguladı; Shockley denklemi artık kullanılmaz (ekrandan, 01:00:00):

$$I_D = k\,(V_{GS} - V_T)^2$$

$$k = \frac{I_{D(\text{on})}}{(V_{GS(\text{on})} - V_T)^2}, \qquad V_{DS(\text{sat})} = V_{GS} - V_T$$

$k$, elemandan elemana değişen ve veri sayfasından öğrenilen bir sabittir. $I_D$, $V_{GS}$'nin eşik geriliminden ne kadar uzaklaştığının karesi ile $k$'nin çarpımıdır. $k$ bazen doğrudan verilir, bazen hesaplanması istenir; bunun için bir çalışma noktasındaki $I_{D(\text{on})}$ ve $V_{GS(\text{on})}$ değerlerinin verilmesi gerekir.

Slayttaki eğrilerde $V_T = 2$ V'tur ve $V_{GS} = 8$ V'ta $I_D = 10$ mA'dir (ekrandan, 01:00:00). Hoca bu değerlerle hesap yapmadı; slayttaki noktalar denklemle şöyle doğrulanır (python ile):

- $k = 10 / (8 - 2)^2 \approx 0{,}278$ mA/V$^2$
- $V_{GS} = 3, 4, 5, 6, 7$ V için $I_D \approx 0{,}28;\ 1{,}11;\ 2{,}5;\ 4{,}44;\ 6{,}94$ mA

Bu değerler slayttaki çıkış eğrilerinin ($V_{GS} = +3$ ... $+8$ V) doyum seviyeleriyle uyumludur.

### 11.3 Sembol ve sınır değerler

E-type'ta hazır kanal olmadığı için kanal çizgisi sembolde kesik (ayrı parçalar halinde) gösterilir. Tek fark budur. Yine n-kanalda ok içeri, p-kanalda dışarı bakar ve ok alttaş ucundadır.

Veri sayfasında bozulma sınırları da yazar. Hocanın okuduğu örnekte drain-source gerilimi 25 V'un, gate-source gerilimi 30 V'un üstüne çıkarılmamalıdır.

## 12. Statik elektrik, VMOS ve CMOS

### 12.1 Statik elektrik

Başta söylendiği gibi her FET'in temel niteliği gerilim kontrollü olmasıdır ve bu yüzden statik elektriğe duyarlıdırlar. Hocanın anlatımına göre MOSFET'te araya silisyum oksit konarak bu daha iyi hale getirilir, ama yine de etkilenebilirler. Korumak için statik önleyici bir kılıf kullanılır; MOSFET'ler bir kılıfın içinde saklanır.

### 12.2 VMOS

VMOS (Vertical MOSFET, dikey MOSFET) yapısında normalde tek olan yapının yerine iki source ve iki gate bulunan bir düzen vardır. Yapısı yüzeysel olduğu için ısıyı daha iyi yayar ve sıcaklıktan etkilenmeyi azaltır.

### 12.3 CMOS

CMOS (Complementary MOSFET, tümler MOSFET) bilgisayar organizasyonunda da çok geçen bir yapıdır. İçinde biri p-kanal, biri n-kanal iki MOSFET bulunur ve iki MOSFET'in drain'leri ortak bağlıdır. Hoca ayrıntısına girmeyeceğini, sayısal devrelerde ve FPGA gibi mimarilerde çok kullanıldığını söyledi. CMOS çok hızlı anahtarlar (kontrollü anahtarlama elemanı olarak) ve çok düşük güç tüketir; bu yüzden bugünkü bilgisayar sistemlerinde CMOS kullanılır.

> **Ek bilgi (derste anlatılmadı):** Temel CMOS evirici (inverter) devresinde p-kanal ve n-kanal MOSFET'lerin gate'leri birleştirilip giriş, drain'leri birleştirilip çıkış yapılır. Her iki kararlı durumda transistörlerden biri kesimde olduğundan besleme ile toprak arasında hemen hemen akım akmaz; düşük güç tüketimi buradan gelir.

## 13. Özet tablo ve ders sonu sorusu

### 13.1 Özet tablo

Hoca son slaytta üç FET türünü karşılaştırdı (ekrandan, 01:05:00). Üçünde de $I_G = 0$ A ve $I_D = I_S$'dir.

| Tür | Gerekli parametreler | Denklem | Transfer eğrisi |
|---|---|---|---|
| JFET | $I_{DSS}$, $V_P$ | $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ | $V_P$'den $V_{GS} = 0$'a kadar |
| D-type MOSFET | $I_{DSS}$, $V_P$ | $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ | $V_P$'den pozitif $V_{GS}$'ye uzanır |
| E-type MOSFET | $V_T$, $I_{D(\text{on})}$, $V_{GS(\text{on})}$ | $I_D = k(V_{GS} - V_{GS(\text{Th})})^2$ | $V_{GS(\text{Th})}$'den başlar |

Hoca JFET ile D-type arasındaki tek farkı yineledi: n-kanal JFET'e pozitif $V_{GS}$ verilirse (gate artı, source eksi) JFET çalışmaz; D-type MOSFET ise bu durumda enhancement moduna girdiği için çalışır.

> **Hocanın vurgusu:** Aynı denklemden çizilen JFET grafiğinde $V_{GS}$'ye pozitif değer koyunca eğri devam ediyormuş gibi görünebilir, ama mimari buna uygun değildir; JFET bu bölgede çalışmaz. Bunu bilmek ve analizi mimariye bakarak yapmak gerekir.

E-type MOSFET'te hiç depletion bölgesi yoktur. E-type, n-kanalda gate'e pozitif $V_{GS}$ verildiği durumun analizi için oluşturulmuş bir mimaridir; $V_{GS}$ eşik noktasını geçtikten sonra $I_D$ oluşur ve formülleri diğerlerinden farklıdır.

> **Ders sonrası not:** Hoca özetin başında "bizim için önemli olan üç tane MOSFET var: JFET, D-type ve E-type" dedi. JFET bir MOSFET değildir; doğrusu "üç tür FET"tir.

### 13.2 Ders sonu sorusu: gate-source kanalı nasıl keser

**Soru:** Görsel üzerinden, JFET'te gate ile source arasındaki gerilimin kanalı neden kestiği yeniden gösterilebilir mi? (ekrandan, 01:10:00)

**Cevap:** Hoca $V_{GS} = 0$ iken kanaldaki n tipi bölgeye dokunulmadığını, $I_D$'yi belirleyen tek şeyin $V_{DS}$ olduğunu söyledi. $V_{DS}$ doğru yönde artırıldıkça içerideki geçiş bölgesi dengeye ulaşmaya çalışırken tükenme bölgesi büyür. $V_{GS}$ ise kanaldaki taşıyıcıların dengesini değiştiren gerilimdir. Hocanın açıklamasına göre tükenme bölgesi dengenin kurulduğu tampon bölgedir; onun daha erken oluşması için öteki taraftaki dengeyi bozan malzemenin azaltılması gerekir. Gate-source gerilimi uygun yönde verildiğinde kanaldaki n taşıyıcıları azalır, p'lerin sayısı n'lere daha çabuk ulaşır ve tükenme bölgesi daha erken oluşur; n tarafı artırılırsa tükenme daha geç oluşur.

> **Ders sonrası not:** Hocanın bu cevaptaki yük dengesi açıklaması ve gerilimin yönü altyazıda karışık geçiyor. Standart açıklama şudur: n-kanal JFET'te gate source'a göre negatif yapılınca ($V_{GS} < 0$) gate-kanal p-n eklemi ters polarmalanır. Ters polarmalı eklemde tükenme bölgesi genişler, genişleme çoğunlukla daha hafif katkılı kanal tarafına doğru olur ve kanalın iletken kesiti daralır. $V_{GS} = V_P$ olduğunda iki yandaki tükenme bölgeleri birleşir ve kanal kapanır; $I_D = 0$ olur (slayttaki şekil de $V_{GS} = -1$ V için genişleyen tükenme bölgelerini gösterir, ekrandan 01:10:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:23:05): Bir n-kanal JFET'te elektronların source'tan drain'e akması için drain-source arasına nasıl bir polarma uygulanmalıdır? $I_D$ hangi yöndedir?

> **Çözüm (derste verildi):** Drain artı, source eksi bağlanır ($V_{DS} > 0$). Drain elektronları çeker, source iter. Akım elektron akışının tersi yönünde olduğu için $I_D$ drain'den source'a doğrudur.

**Soru 2** (ekrandan, 00:45:00): Slayttaki JFET için $I_{DSS} = 8$ mA ve $V_P = -4$ V'tur. $V_{GS} = 0, -1, -2, -3, -4$ V için $I_D$ değerlerini bularak transfer eğrisini çiziniz.

> **Çözüm (derste sayısal olarak hesaplanmadı):** Shockley denklemiyle: $V_{GS} = 0 \Rightarrow 8$ mA; $-1 \Rightarrow 8(0{,}75)^2 = 4{,}5$ mA; $-2 \Rightarrow 8(0{,}5)^2 = 2$ mA; $-3 \Rightarrow 8(0{,}25)^2 = 0{,}5$ mA; $-4 \Rightarrow 0$. Slayttaki noktalar bu değerlerle aynıdır (python ile doğrulandı).

**Soru 3** (ekrandan, 00:55:00): $I_{DSS} = 8$ mA ve $V_P = -6$ V olan n-kanal D-type MOSFET için $V_{GS} = +1$ V, $V_{GS} = V_P/2$ ve $V_{GS} = 0{,}3V_P$ değerlerinde $I_D$ nedir?

> **Çözüm (derste sayısal olarak hesaplanmadı):** $V_{GS} = +1$ V: $I_D = 8(1 + 1/6)^2 \approx 10{,}9$ mA (enhancement modu, $I_D > I_{DSS}$). $V_{GS} = -3$ V: $I_D = 8(0{,}5)^2 = 2$ mA $= I_{DSS}/4$. $V_{GS} = -1{,}8$ V: $I_D = 8(0{,}7)^2 \approx 3{,}92$ mA $\approx I_{DSS}/2$. Slayttaki eğri değerleriyle uyumludur (python ile doğrulandı).

**Soru 4** (ekrandan, 01:00:00): Slayttaki E-type MOSFET'te $V_T = 2$ V'tur ve $V_{GS} = 8$ V'ta $I_D = 10$ mA'dir. $k$ sabitini ve $V_{GS} = 5$ V için $I_D$'yi bulunuz.

> **Çözüm (derste verilmedi):** $k = I_{D(\text{on})}/(V_{GS(\text{on})} - V_T)^2 = 10/(8 - 2)^2 \approx 0{,}278$ mA/V$^2$. $V_{GS} = 5$ V için $I_D = 0{,}278 \cdot (5 - 2)^2 = 2{,}5$ mA. Slayttaki $V_{GS} = +5$ V eğrisi de yaklaşık 2,5 mA'de doyuma ulaşır (python ile doğrulandı).

## Dersin Toparlaması

Bu derste BJT'den sonra ikinci transistör ailesi olan FET'lere giriş yapıldı. FET'in BJT'den temel farkı gerilim kontrollü olmasıdır: gate'ten akım akmaz, $I_D$ gate-source ve drain-source gerilimleriyle kontrol edilir. JFET'te kanalın genişliği gate-kanal eklemlerindeki tükenme bölgeleriyle ayarlanır. $V_{GS} = 0$ iken pinch-off'taki akım $I_{DSS}$, akımı tamamen kesen gate-source gerilimi $V_P = V_{GS(\text{off})}$'tur ve bu iki parametre Shockley denklemiyle transfer eğrisini belirler. Çok büyük $V_{DS}$ değerleri ise elemanı breakdown'a götürür.

MOSFET'lerde gate oksit katmanıyla yalıtılmıştır. D-type MOSFET, JFET'in depletion modunu aynen taşır ve n-kanalda pozitif $V_{GS}$ ile $I_D > I_{DSS}$ olan enhancement modunda da çalışır. E-type MOSFET'te hazır kanal yoktur; akım $V_{GS}$ eşik gerilimi $V_T$'yi aşınca başlar ve $I_D = k(V_{GS} - V_T)^2$ denklemiyle hesaplanır. Ders statik elektriğe duyarlılık, VMOS ve sayısal sistemlerde yaygın olan CMOS ile kapandı. Hoca FET konusuyla ilgili soruların ilerleyen haftalarda çözülebileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
