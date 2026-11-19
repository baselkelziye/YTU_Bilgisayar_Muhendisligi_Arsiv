# Ders 5 Genişletilmiş Notu: PN Eklemi, Diyot Çeşitleri ve Doğrultucu Devreler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. P ve N Tipi Malzemeler, PN Eklemi
- 2. Tükenme Bölgesi ve Potansiyel Bariyeri
- 3. İleri ve Ters Kutuplama
- 4. Diyot Akım-Gerilim Bağıntısı ve Gerçek Karakteristik
- 5. Diyotun Üç Çalışma Koşulu
- 6. Zener Bölgesi
- 7. Sıcaklık Etkisi ve Direnç Seviyeleri
- 8. Eşdeğer Devre, Sembol, Paketler ve Diyot Testi
- 9. Diğer Diyot Türleri
- 10. Yük Doğrusu ve Q Noktası
- 11. Seri ve Paralel Diyot Devreleri
- 12. AC'den DC'ye: Doğrultma Fikri
- 13. Yarım Dalga Doğrultucu
- 14. Tam Dalga ve Köprü Doğrultucu
- 15. Diyot Kırpıcılar
- Örnek Sorular
- Dersin Toparlaması

## 1. P ve N Tipi Malzemeler, PN Eklemi

Ders, bir önceki haftada başlanan yarı iletken fiziği konusunun devamıyla açıldı. Hoca önce temeli hatırlattı: silisyum, germanyum ya da galyum arsenit gibi bir yarı iletkenin içine belli miktarlarda farklı atomlar katılarak iki tür malzeme elde edilir. Birinde dengedeki elektron sayısı artırılır, ötekinde elektron sayısı azaltılıp delik sayısı artırılır. Elektron fazlası olan malzemeye N tipi, delik fazlası olan malzemeye P tipi malzeme denir. Çok küçük miktarda katkı atomu eklemek bu iki malzemeyi elde etmeye yeter.

P tipi malzemede hareketli pozitif yükler, yani delikler çoğunluktadır. Delik, elektronun eksik olduğu yer olarak düşünülebilir. N tipi malzemede ise hareketli negatif yükler, yani akımı oluşturacak fazla elektronlar çoğunluktadır.

Slaytta bu iki malzemenin birleşimi şöyle tanımlanıyor: silisyum ya da germanyum kristalinin bir ucu p tipi, diğer ucu n tipi olarak katkılanabilir; sonuç bir p-n eklemidir (ekrandan, 00:10:00). Hoca slayttaki "p-n junction" başlığının yanına "Diyot" yazarak bu yapının diyotun kendisi olduğunu belirtti. Eklemleme (junction) iki malzemenin birbirine yapıştırılmasıdır.

## 2. Tükenme Bölgesi ve Potansiyel Bariyeri

P ve N tipi malzemeler birleştirildiğinde aralarında bir bölge oluşur. İngilizcede buna depletion region denir. Hoca derste Türkçe karşılığını aradı ve "tükenme bölgesi" olarak geçtiğini söyledi. Aynı bölge uzay yükü katmanı (space charge layer) olarak da adlandırılır.

Hoca "tükenme" sözcüğünün neyi anlattığını da tartıştı. Eklemin iki yanında yükler birbirini çeker ve iter: p tipi malzemede negatif yükler n tipine doğru yanaşır, n tipinde de pozitif yükler eklem bölgesinde toplanır. Eksilerle artıların birbirini çekmesiyle eklemde bir denge bölgesi oluşur. Hoca bunu sezgisel olarak bir "geçiş bölgesi" diye adlandırmayı önerdi; tükenme sözcüğü, taşıyıcıların göçü (migration) sonucu bu bölgenin serbest taşıyıcılardan arınması anlamında kullanılıyor.

Slayttaki açıklama şöyledir: bir yönde pozitif yükün, öbür yönde negatif yükün yayılması (difüzyon) bir yük dengesizliği üretir; bu da eklem boyunca bir potansiyel bariyerine yol açar (ekrandan, 00:15:00). Slayttaki yük grafiğinde eklemin p tarafında negatif, n tarafında pozitif bir yük bloğu görülür. Potansiyel grafiği bu yük dağılımının integralidir: p tarafında düşük başlar, eklem boyunca yükselir ve n tarafında $V_b$ kadar yüksek bir değerde sabitlenir. Yani potansiyel n tipinin olduğu yerde yüksek, p tipinin olduğu yerde düşüktür.

## 3. İleri ve Ters Kutuplama

Hoca bu kısmı slayttaki üç şekil üzerinden anlattı (ekrandan, 00:20:00):

- (a) Yalıtılmış eklem (isolated junction): Dışarıdan hiçbir gerilim bağlı değildir. Tükenme bölgesinden dolayı sabit bir potansiyel bariyeri vardır.
- (b) İleri kutuplama (forward bias): Dışarıdan bir DC kaynak, artı ucu p tarafına gelecek şekilde bağlanır. Bariyer $V$ kadar azalır.
- (c) Ters kutuplama (reverse bias): Kaynak ters bağlanır, p tarafına eksi gelir. Bariyer $V$ kadar artar.

İleri kutuplamada ne olduğunu hoca şöyle açıkladı: eklemin bir yanında artılar, öbür yanında eksiler yoğundu. Dışarıdan elektron gönderildiğinde bu yüklerin bölgesi küçülür, yük dengesi azalır ve potansiyel düşer. Tükenme bölgesi daralır, çoğunluk taşıyıcıları artık daha rahat geçer ve devreden akım akmaya başlar. İleri kutuplama, diyotun çalışmasını istediğimiz yöndeki beslemedir.

Ters kutuplamada diyotun artı ucuna eksi gerilim bağlanmıştır. Verilen eksi yük, eksileri iter; eklemin iki yanında yükler iyice yoğunlaşır ve tükenme bölgesi genişler. Bölge genişledikçe potansiyel farkı yükselir. Çoğunluk taşıyıcılarının akımı bu yüksek bariyeri aşamadığı için sıfır düzeyindedir; yalnız azınlık taşıyıcılarından kaynaklanan küçük bir ters akım akar. Slayttaki ifadeyle, ters kutuplama tükenme bölgesinin genişlemesine, ileri kutuplama ise daralmasına neden olur; ileri kutuplamada elektronlar ve delikler eklem yönüne itilir.

Hoca PN eklemi için Boltzmann sabiti, sıcaklık ve malzeme türüne bağlı ayrıntılı bir hesap olduğunu, ancak bu hesaba fazla girmeyeceğini söyledi.

### 3.1 Diyot tükenir mi?

**Soru:** Diyotun potansiyeli düşünce akım aktarıyor dediniz. Bu diyot ne zamana kadar çalışır, bir pil gibi bir süre sonra tükenir mi?

**Cevap:** Diyot bir pil, yani bir enerji kaynağı değildir. Potansiyel bariyeri düşünce iç direnci düşüp akımın geçmesine izin veren bir eleman olarak düşünülmelidir. İdeal diyot tanımında da $V_A > V_B$ olacak şekilde gerilim verilince diyot A ve B uçları arasında kısa devre gibi, $V_A < V_B$ olunca açık devre gibi davranır. Her malzeme gibi yarı iletkenlerin de bir ömrü vardır ama bu ömür uzundur. Bilgisayarların içindeki koruma diyotları ve transistörler çok dayanıklı elemanlardır. Genellikle çalışma sınırlarının dışındaki gerilimlerle karşılaşıp fiziksel yapıları bozulduğunda, yani "yandıklarında" bozulurlar.

## 4. Diyot Akım-Gerilim Bağıntısı ve Gerçek Karakteristik

Hoca önce ideal diyotu hatırlattı. Diyotun A ve B uçları arasındaki gerilim $V_D = V_{AB} = V_A - V_B$, diyottan akan akım $I_D$ olsun. $I_D$-$V_D$ grafiğinde $V_D$ negatifken akım akmaz. $V_D$ sıfırdan epsilon kadar büyük olunca akım akmaya başlar; hesaplarda bu epsilon ihmal edilir ve eğri dikey eksene yapışık çizilir.

Gerçekte ise önce potansiyel bariyerini aşacak kadar bir gerilim verilmesi gerekir. Bu eşik, kullanılan malzemeye göre değişir çünkü tükenme bölgesinin genişliği ve potansiyeli malzemeye bağlıdır:

- Silisyum: yaklaşık 0,7 V
- Germanyum: yaklaşık 0,3 V
- Galyum arsenit: yaklaşık 1,2 V

<!-- BELİRSİZ: Hoca GaAs için önce "1,3 yanlış hatırlamıyorsam" dedi ve ekrana elle 1,3 yazdı (00:24:49, ekrandan 00:25:00); daha sonra slayttan 1,2 V okudu (00:32:16). Notta slayttaki 1,2 V kullanıldı. -->

Slaytta diyot akımının üstel bağıntısı da verilmiştir (ekrandan, 00:25:00). Oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$ alınırsa:

$$V > +0{,}1\ \text{V} \text{ için } \quad I \approx I_s\left(\exp\frac{eV}{kT}\right) = I_s\,(\exp 40V)$$

$$V < -0{,}1\ \text{V} \text{ için } \quad I \approx I_s\,(0-1) = -I_s$$

Burada $I_s$ ters doyma akımıdır (reverse saturation current). Hoca karakteristik eğri üzerinde 0,7 V'u işaretledi ve ileri yönde akımın bu civarda hızla yükseldiğini gösterdi; ekrana $V_A - V_B = 0{,}7$ yazdı.

> **Ek bilgi (derste anlatılmadı):** $e/kT$ değeri, elektron yükü $e \approx 1{,}602\times10^{-19}$ C ve Boltzmann sabiti $k \approx 1{,}381\times10^{-23}$ J/K ile $T = 300$ K'de yaklaşık $38{,}7\ \text{V}^{-1}$ çıkar. Slayttaki 40, bunun yuvarlanmış halidir. Tersi olan $kT/e \approx 25{,}9$ mV ısıl gerilim olarak bilinir.

Hoca gerçek karakteristiği şöyle özetledi: ideal eğri sıfırdan dik çıkıyordu; gerçekte eğri 0,7 V'tan itibaren hızla yukarı çıkar. Ters beslemede ise $I_s$ denilen, mikroamperler seviyesinde çok küçük bir akım geriye doğru akar.

## 5. Diyotun Üç Çalışma Koşulu

Slaytta bir diyotun üç çalışma koşulu olduğu belirtilir (ekrandan, 00:25:00):

- Kutuplama yok (no bias): Diyota hiçbir gerilim uygulanmaz. Üzerinden akım akmaz, $I_D = 0$ mA. Boşta duran bir diyottan ne akım akar ne başka bir şey olur.
- Ters kutuplama (reverse bias): P tipi tarafa eksi gerilim bağlanmıştır. Tükenme bölgesi büyür, bariyer büyür, yalnız ters yönde azınlık taşıyıcısı akımı akar. Çoğunluk akımı sıfırdır.
- İleri kutuplama (forward bias): P tarafına artı verilir. Tükenme bölgesi daralır; elektronlar ve delikler eklem yönüne itilip dengelenir, çoğunluk taşıyıcıları potansiyel azaldığı için rahatça geçer.

Hoca, normal diyotun bir devrede yolu açıp kapayan bir anahtar gibi düşünülebileceğini söyledi.

## 6. Zener Bölgesi

Hoca diyotu ters bağladığında ne olacağını sordu. Normalde ters bağlı diyot akım geçirmemelidir. Ama ters gerilim artırıldıkça belli bir noktadan sonra diyot kırılır ve ters yöndeki akım $I_s$ düzeyinden birden, çığ gibi yükselir. Slayttaki karakteristikte bu, negatif $V_D$ ekseninde $V_Z$ noktasında akımın dikey olarak aşağı indiği kısımdır (ekrandan, 00:30:00).

Slayttaki tanımlar şöyledir (ekrandan, 00:30:00):

- Zener bölgesi diyotun ters kutuplama bölgesindedir.
- Bir noktada ters gerilim o kadar büyür ki diyot kırılır (breaks down) ve ters akım çarpıcı biçimde artar.
- Diyotu Zener bölgesine sokmayan en büyük ters gerilime tepe ters gerilim (peak inverse voltage ya da peak reverse voltage) denir.
- Diyotun Zener bölgesine girmesine neden olan gerilime Zener gerilimi ($V_Z$) denir.

> **Ders sonrası not:** Hoca anlatımda "tersteki belli bir gerilimden sonra Peak Reverse Voltage deniyor buna, Zener Voltage'ına ulaştığı zaman..." diyerek iki kavramı bir arada söyledi (00:31:11). Slayttaki tanıma göre tepe ters gerilim, diyotu Zener bölgesine sokmayan en büyük ters gerilimdir; kırılmanın başladığı gerilim ise Zener gerilimi $V_Z$'dir.

Hoca bu davranıştan ayrı bir diyot türünün, Zener diyotun üretildiğini söyledi. Normal diyotta eşik hep 0,7 V civarındadır; malzeme türü değiştirilerek $V_Z$ sağa sola kaydırılabilir ve örneğin $-5$ V, $-10$ V, $-12$ V'ta ters akım akıtan diyotlar elde edilebilir.

## 7. Sıcaklık Etkisi ve Direnç Seviyeleri

Slayta göre sıcaklık diyota enerji verir ve gereken ileri kutuplama gerilimini, yani 0,7 V'luk eşiği düşürür. Hoca bunun kararlı çalışması istenen devrelerde istenmeyen bir davranış olduğunu söyledi.

Diyot bir devre elemanı olduğu için kendine ait bir iç direnci vardır. Bu direnç DC ve AC için ayrı ayrı hesaplanır. Elimizde akım-gerilim grafiği olduğu için iletim anındaki direnç hesaplanabilir: eğri üzerinde A ve B gibi iki nokta seçilir, aradaki eğimin tersi alınır. Slayttaki ortalama AC direnç tanımı şöyledir (ekrandan, 00:35:00):

$$r_{av} = \frac{\Delta V_d}{\Delta I_d}\ \Big|\ \text{noktadan noktaya}$$

Ters kutuplama bölgesinde ise slayt $r'_d = \infty$ der: direnç fiilen sonsuzdur, diyot açık devre gibi davranır (ekrandan, 00:35:00). Hoca bunu bir tel üzerinden açıkladı: açık devre, telin arasında hava olması gibidir; havanın direnci sonsuz kabul edilir. Kısa devrede ise direnç sıfıra yakındır. Gerçekte direnç tam sonsuz olmayacağı için ters bölgede çok yüksek bir direnç olduğunu ve akım akmadığını düşünebiliriz. Slaytın üst kısmında, ileri yöndeki $r_B$ direncinin yüksek güçlü elemanlarda yaklaşık 0,1 Ω'dan düşük güçlü genel amaçlı diyotlarda birkaç ohma kadar değiştiği ve bazı durumlarda ihmal edilebildiği yazıyor (ekrandan, 00:35:00).

<!-- BELİRSİZ: Slaytta $r_B$ aralığının üst sınırı karede kesik görünüyor ("... to 2 Ω for low power" gibi okunuyor); kesin değer okunamadı. -->

## 8. Eşdeğer Devre, Sembol, Paketler ve Diyot Testi

### 8.1 Eşdeğer devre

Diyot sembolünde bir tarafa çubuk (halka) çizilir. Halkanın olduğu taraf eksi uç, yani katottur; diğer taraf artı uç, yani anottur. Üst taraf (anot) p tipi malzemeden, alt taraf (katot) n tipi malzemeden oluşur.

Yalnız sembolle çizilen diyot ideal diyottur. Gerçek diyotu modellemek için üç parça seri bağlanır: ideal diyot, 0,7 V'luk bariyer gerilimi ve diyotun iç direnci. Hoca gerçek diyotun eşdeğer devresinin bu şekilde çizilmesi gerektiğini söyledi.

### 8.2 Paketler

Hoca slayttaki diyot paketlerini gösterdi:

- Düşük akımlı devrelerde kullanılan, silindir gövdeli ve bir ucunda katodu gösteren halka bulunan diyotlar.
- Büyük akım ve güç uygulamaları için tasarlanmış iri gövdeli diyotlar.
- PCB denilen elektronik kartın yüzeyine monte edilen, düşük akımlı yüzey montaj diyotlar.

### 8.3 Multimetre ile diyot testi

Hoca bir soru sordu: elinizde bir direnç ölçer ya da multimetre varsa bir diyotun çalıştığını nasıl anlarsınız? Cihaz direnç konumuna getirilir. Kırmızı (pozitif) uç diyotun artı ucuna, siyah (ortak ya da eksi) uç eksi ucuna konunca düşük bir değer okunmalıdır. Yüksek değer okunuyorsa diyotun iç yapısı bozulmuş demektir. Uçlar ters konduğunda, yani kırmızı uç katoda, siyah uç anoda değdirildiğinde yüksek direnç okunmalıdır. Bu iki yönlü kontrol diyotun bozuk olup olmadığını gösterir.

> **Ders sonrası not:** Hoca ileri yöndeki ölçüm için "düşük gerilim vermesi lazım" dedi (00:38:11). Cihaz direnç konumunda olduğu için burada büyük olasılıkla düşük direnç kastedildi; ters yönde de yüksek direnç beklenir.

Akım-gerilim karakteristiğini çizen eğri çiziciler (curve tracer) de vardır. Bunlar elemana farklı gerilimler uygulayıp aldığı akımı nokta nokta çizerek karakteristiği gösterir.

## 9. Diğer Diyot Türleri

Hoca slayttaki listeyi kendi numaralandırmasıyla genişletti (ekrandan, 00:40:00):

- 1. Normal diyotlar
- 2. Zener diyotlar: ters kutuplamada kullanılan diyotlar
- 3. Işık yayan diyotlar (LED)
- 4. Diyot dizileri

### 9.1 LED

LED de bir diyottur ama üzerinden akım geçtiği anda belirli dalga boylarında ışık yayar. Telefonlarda, bilgisayarlarda, televizyonlarda kullanılan yapı budur. Yayılan dalga boyları kırmızı, yeşil ve mavi (RGB) olacak şekilde ayarlanırsa her hücreden bu üç renk elde edilir ve renkli bir görüntünün her pikseli oluşturulabilir. PN eklemleri ne kadar sık ve dar alana basılabilirse LED dizilerinin çözünürlüğü o kadar yükselir ve göz pikselleri o kadar az fark eder.

Slayta göre LED ileri kutuplandığında foton yayar; bu fotonlar kızılötesi ya da görünür spektrumda olabilir. İleri kutuplama gerilimi genellikle 2 V ile 3 V arasındadır (ekrandan, 00:45:00). Hoca görünür bölgede kullanılan LED'lerin yaklaşık 400 ile 700 nanometre arasında, göze görünen elektromanyetik dalga yaydığını söyledi. Kısacası LED'i iletime geçirdiğimizde malzemeden ışık elde ederiz.

### 9.2 Zener diyot

Normal diyot pozitif beslemeyle akım geçirir ve eşiği 0,7 V civarındadır. Diyotun belli bir, daha yüksek gerilimde akım akıtması istendiğinde (örneğin 1,8 V, 3,6 V, 5 V, 12 V) Zener diyot kullanılır. Zener diyot sembolünde uçlar kırık çizilir. Ters bölgede çalıştığı için normal diyota ters bağlıymış gibi kullanılır: artı ucu normal diyotun eksi ucunun olduğu tarafa gelir. Kullanılan akım $I_Z$ ters yöndeki akımdır; karakteristikteki ters akımın hızla artmasından yararlanılır.

Normal diyottan farkı, kırılma geriliminin malzemeyle istenen yere kaydırılabilmesidir. Hoca bir örnek devre çizdi: bir kaynak, bir direnç ve ters bağlı 1,8 V'luk bir Zener diyot. Zener'in üzerine 1,8 V düştüğünde diyot üzerinden hızla akım akıtmaya başlar.

> **Ders sonrası not:** Hoca bu sırada "açık devreye haline gidiyoruz" dedi (00:43:01), hemen sonra da "kısa devre gibi davranmaya, daha doğrusu üzerinden hızlıca akım akıtmaya başlıyor" diye düzeltti (00:43:29). Kırılma geriliminde Zener diyot açık devre değildir; iletime geçer ve uçlarındaki gerilim yaklaşık $V_Z$'de kalır.

Hocaya göre yaygın Zener diyotlar 1,8 V ile 200 V arasında ayarlanabilir. Normal diyotlar da ilkesel olarak Zener gibi kullanılabilir, ama bir diyotun ters yöndeki kırılma noktası ile başka bir diyotunki farklı yerlerde olabilir. Kırılma geriliminin sabit ve güvenilir olması için özel üretim gerekir; Zener diyotun ayrı bir sembolü olmasının nedeni budur.

### 9.3 Diyot dizileri

Bir devrede çok sayıda diyot kullanılacaksa, mantık dersinde görülen VE ve VEYA kapılarının entegre gövdeleri gibi, diyotlar da tek bir gövdenin içine dizi halinde konur. Bacakları gövdeden dışarı çıkarılır; 8'li ya da 16'lı yapılarda bulunurlar. Pozitif uçları ortak bir beslemeden sağlanıyorsa ortak anotlu dizi denir: hangi diyotun katoduna düşük potansiyel uygulanırsa o diyottan akım geçer, düşük potansiyel yoksa iletim olmaz. Negatif uçlar ortaksa ortak katotlu dizi denir; ortak uç toprağa ya da belli bir gerilim kaynağına bağlanabilir.

## 10. Yük Doğrusu ve Q Noktası

Aradan önce hoca, artık diyotun devre içindeki kullanımının analizine geçileceğini söyledi. Elimizde diyot gerilimi $V_D$ ve diyot akımı $I_D$ vardır. Devreler kurulduğunda diyotun standart eğrisinin neresinde çalıştığını bulmak gerekir; bu noktaya Q noktası (çalışma noktası) denir.

Sonraki slayt dosyasının ilk sayfasında bu konu özetlenir (ekrandan, 00:50:00). Grafikte diyotun karakteristik eğrisi (device) ile devrenin yük doğrusu (network) birlikte çizilmiştir. Yük doğrusu dikey eksende $E/R$, yatay eksende $E$ noktalarından geçer:

- Devredeki en büyük $I_D$ değeri $E/R$'dir.
- En büyük $V_D$ değeri $E$'dir.
- Yük doğrusu ile karakteristik eğrinin kesiştiği nokta Q noktasıdır ve verilen devredeki diyot için $I_{D_Q}$ ve $V_{D_Q}$ değerlerini belirler.

Hoca ekranda bir kaynak, seri direnç ve diyottan oluşan devreyi çizip diyot üzerindeki $V_D$ gerilimini ve $I_D$ akımını işaretledi; Q'nun yanına "çalışma noktası" yazdı.

## 11. Seri ve Paralel Diyot Devreleri

### 11.1 İleri kutuplanmış seri devre

Aradan sonra hoca seri diyot devresiyle başladı. Devrede $E$ ile gösterilen bir DC gerilim kaynağı vardır; bir pil gibi düşünülebilir, artı ucu yukarıda, eksi ucu genellikle toprağa bağlıdır. Akım kaynaktan çıkıp silisyum diyot ve direnç üzerinden toprağa döner. $E$ yerine 3 V, 5 V gibi değerler konabilir.

Diyot ideal verilmişse üzerine düşen gerilim sıfırdır. Silisyum diyot kullanılmışsa iletim durumunda üzerine 0,7 V, germanyumsa 0,3 V düşer; bu gerilim potansiyel bariyerini aşmak için harcanır. Kalan gerilim direncin üzerine düşer. Tek bir koldan geçtiği için diyot akımı direnç akımına eşittir:

$$I_D = I_R, \qquad V_R = R\,I_R = R\,I_D$$

### 11.2 Ters kutuplanmış seri devre

$E$ eksi bir gerilimse ya da silisyum diyot için 0,7 V'un altındaysa (örneğin 0,6 V ya da daha az) diyot iletmez. Diyotun uçları sanki açıkmış gibi düşünülür. Dirençten akım akmadığı için $I_R = 0$ ve dolayısıyla $V_R = 0$ olur; $I_D$ de sıfırdır. Uygulanan gerilim, $-3$ V, $-5$ V ya da 0,6 V ne ise, tamamen diyotun A ve B uçları arasına düşer. Diyot çalışmadığı için açık devre gibi davranır.

### 11.3 Paralel diyot örneği

Hoca slayttaki paralel diyot örneğini çözdü (ekrandan, 01:05:00). Devrede $E = 10$ V'luk bir kaynak, buna seri $R = 0{,}33$ kΩ'luk bir direnç ve direncin çıkışına paralel bağlı iki özdeş silisyum diyot ($D_1$, $D_2$) vardır. Çıkış gerilimi $V_o$ diyotların uçlarından alınır. İstenen $I_1$, $I_{D1}$ ve $I_{D2}$ akımlarıdır.

Verilen: $E = 10$ V, $R = 0{,}33$ kΩ, $D_1$ ve $D_2$ Si.

1. Kaynakta 10 V olduğu için iki diyot da iletir; gerilimin bir kısmı dirence, kalanı diyotlara düşer. Silisyum diyot için $V_D = 0{,}7$ V.
2. Paralel uçlar arasındaki gerilimler eşittir: $V_{AB} = V_{D1} = V_{D2} = V_o = 0{,}7$ V.
3. Hoca direnç gerilimini düğüm potansiyelleriyle kurdu. Direncin kaynak tarafındaki uca C, diyot tarafındaki uca A dersek $V_R = V_C - V_A$'dır. Diyotun öbür ucu toprakta olduğu için $V_A = V_D = 0{,}7$ V; direncin öbür ucu kaynağa bağlı olduğu için $V_C = E = 10$ V. Böylece $V_R = E - V_D = 10 - 0{,}7 = 9{,}3$ V.
4. Ohm yasasından ($V = IR$) ana kol akımı:

$$I_R = I_1 = \frac{E - V_D}{R} = \frac{10\ \text{V} - 0{,}7\ \text{V}}{0{,}33\ \text{k}\Omega} = 28\ \text{mA}$$

5. Diyotlar özdeş olduğu için bu akım iki kola eşit bölünür:

$$I_{D1} = I_{D2} = \frac{28\ \text{mA}}{2} = 14\ \text{mA}$$

Python ile kontrol: $9{,}3/330 = 28{,}18$ mA, yarısı 14,09 mA; slayttaki 28 mA ve 14 mA yuvarlanmış değerlerdir.

> **Hocanın vurgusu:** Akımın 14 mA ve 14 mA olarak eşit bölünmesinin nedeni diyotların özdeş olmasıdır; "özdeş olması önemli."

Hoca bir öğrencinin tereddüdü üzerine karakteristiği yeniden gösterdi: ideal olmayan diyotta 0,7 V'a varıldıktan sonra diyot üzerindeki gerilim artık artmaz, yalnız akım artar. Bu yüzden 0,7 V'a varınca diyot kısa devre gibi (sabit 0,7 V düşüren bir eleman gibi) düşünülür.

## 12. AC'den DC'ye: Doğrultma Fikri

Hoca doğrultuculara geçmeden önce AC ve DC işaretleri hatırlattı. DC işaret zamana göre sabit bir gerilimdir: 5 V, 3,3 V ya da $-5$ V gibi. Sinüzoidal (AC) işaret ise zamanla salınır.

Prizlerden AC işaret alınır, ama kullandığımız elektronik cihazlar DC ile çalışır. Örneğin dizüstü bilgisayar adaptörü 220 V AC alır ve 19,3 V DC'ye düşürür; telefon şarj cihazları da benzer şekilde çalışır. Bu dönüşümün adımları şöyledir:

- Yarım dalga doğrultma: pozitif bölgeler geçirilir, negatif bölgeler geçirilmez. Aradaki boşluklar kalır.
- Tam dalga doğrultma: negatif kısımlar da evrilerek pozitif tarafa çevrilir.
- Sonra kondansatörler kullanılarak tepe noktaları arasındaki boşalmalar olabildiğince düzeltilir; geriye dalgalı bir işaret kalır ve bu dalgalanma başka elektronik devrelerle giderilir.

Doğrultucu (rectifier), AC'den DC'ye çevrimi gerçekleştiren devredir.

## 13. Yarım Dalga Doğrultucu

### 13.1 Çalışma

Slayttaki devrede (ekrandan, 01:15:00) girişe $v_i$ sinüs işareti uygulanır; seri bir diyottan sonra çıkış $v_o$, toprağa bağlı direncin üzerinden alınır. Hoca diyotu şimdilik ideal kabul etti, yani 0,7 V'u hesaba katmadı.

- Pozitif yarı periyot ($0$ ile $T/2$ arası): Diyot gerilimi sıfırı epsilon kadar geçince diyot iletime girer ve kısa devre gibi olur. $v_i$, A noktası ile toprak arasına uygulanan gerilimdir: $v_i = V_A - V_{\text{toprak}} = V_A$. Çıkış da aynı noktadan alındığı için $v_o = v_i$ olur. Epsilon çok küçük olduğu için pozitif kısım olduğu gibi çıkışa geçer.
- Negatif yarı periyot ($T/2$ ile $T$ arası): Diyot ters kutuplanır, açık devre olur. Çıkışın girişle bağlantısı kalmaz ve $v_o = 0$ V olur.

Sonuçta çıkışta yalnız pozitif yarım dalgalar görülür. Slayttaki açıklamaya göre diyot yalnız ileri kutuplandığında iletir, bu yüzden AC çevriminin yalnız yarısı çıkışa geçer (ekrandan, 01:15:00).

### 13.2 DC çıkış

Slayta göre DC çıkış gerilimi $0{,}318\,V_m$'dir; $V_m$ AC işaretin tepe değeridir (ekrandan, 01:15:00). Hoca bunun anlamını ortalama üzerinden kurdu. Tepe değeri $V_m$, en küçük değeri $-V_m$ olan sinüsün ortalaması sıfırdır, çünkü ortalama, eğrinin altında kalan alanın periyoda bölümüdür ve pozitif ile negatif alanlar birbirini götürür. Negatif kısımlar yok edilince yalnız pozitif alan kalır ve ortalama pozitife çıkar. Bu ortalama $0{,}318\,V_m$'dir; örneğin $V_m = 10$ V ise ortalama 3,18 V olur. Hoca bu ortalamaya "DC seviye" dendiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** 0,318 sayısı $1/\pi$'dir. Yarım dalganın bir periyottaki ortalaması $\frac{1}{T}\int_0^{T/2} V_m \sin(\omega t)\,dt = V_m/\pi$ çıkar. Tam dalgada alan iki katına çıktığı için $2V_m/\pi \approx 0{,}636\,V_m$ olur.

### 13.3 Yarım dalgada Zener bölgesi sorusu

**Soru:** Negatif yarı periyotta diyot açık devre gibi davrandı. Ama $v_i$ çok büyük olursa diyot bir yerde Zener bölgesine girmez mi?

**Cevap:** Doğru bir tespit. Devre, Zener bölgesine girilmeyeceği garanti edilecek şekilde tasarlanır. Normal çalışan diyotlarda Zener geriliminin çok uzak bir negatif değerde olması beklenir, böylece o gerilime ulaşılmaz. Ulaşılırsa yanlış çalışma olur ve diyot ters yönde de akım akıtır.

> **Ek bilgi (derste anlatılmadı):** Bu yüzden doğrultucu diyot seçilirken diyotun tepe ters gerilim (PIV) değerinin, devrede diyota gelecek en büyük ters gerilimden büyük olması istenir. Yarım dalga doğrultucuda bu en büyük ters gerilim yaklaşık $V_m$'dir.

## 14. Tam Dalga ve Köprü Doğrultucu

### 14.1 DC seviye

Yarım dalgada $V_{dc} = 0{,}318\,V_m$ idi. Negatif kısım da yukarı evrilirse ortalamaya aynı katkı bir kez daha eklenir; alan iki katına çıkar. Bu yüzden tam dalga doğrultucuda DC seviye $0{,}318 \times 2 = 0{,}636\,V_m$'dir. Slaytta bu iki değer yan yana verilmiştir: yarım dalga $V_{dc} = 0{,}318\,V_m$, tam dalga $V_{dc} = 0{,}636\,V_m$; tam dalga doğrultma daha büyük bir DC çıkış üretir (ekrandan, 01:20:00).

### 14.2 Köprü doğrultucu

Tam dalga doğrultucunun bir türü köprü doğrultucudur (bridge rectifier). Slayta göre dört diyot köprü biçiminde bağlanır ve $V_{DC} = 0{,}636\,V_m$'dir (ekrandan, 01:35:00). Giriş $v_i$ köprünün üst (A) ve alt (B) düğümleri arasına uygulanır; çıkış $v_o$ köprünün sol ve sağ düğümleri arasına bağlı direncin üzerinden alınır (direncin sağ ucu artı, sol ucu eksi).

Pozitif yarı periyotta (A ucu B'den yüksek potansiyelde): D1 ters yönde bağlı olduğu için açık devredir. D2'nin eksi ucu toprağa daha yakın olduğu için D2 iletir ve kısa devre gibidir. D4 de ters yönde bağlıdır, iletmez. Akım D2'den geçip direnci sağdan sola dolaşır ve D3 üzerinden geri döner. Hoca ekranda D1 ve D4'ün üzerine çarpı koyarak bunları gösterdi (ekrandan, 01:35:00). Diyotların direnci olmadığı varsayıldığı için girişin pozitif yarısı aynen çıkışta oluşur.

Negatif yarı periyotta (B ucu A'dan yüksek potansiyelde): $v_i$'nin artı ucunda eksi gerilim vardır. Bu kez D1 ve D4 iletir, D2 ve D3 kesimdedir. Hoca akım yolunu ekranda kırmızıyla çizdi (ekrandan, 01:25:00). Akım direnci yine aynı yönde, sağdan sola geçer; yani direncin artı işaretli ucu yine yüksek potansiyeldedir. Böylece girişin negatif yarısı çıkışta pozitif olarak görünür.

Çıkışta her yarı periyotta bir pozitif tepe oluşur. Buna tam dalga doğrultucu denir ve DC ortalaması yarım dalga doğrultucunun tam iki katıdır.

### 14.3 Kesimdeki diyotun neden iletmediği

**Soru:** Pozitif yarı periyotta dört diyottan ikisi çalışıyor: akım ilk diyottan geçiyor, sonra dirençten, sonra ikinci diyottan aşağı iniyor. Ama dirençten geçtikten sonra akım üst kısımdaki, açık devre sayılan diyottan yukarı çıkmaz mı?

**Cevap:** Akım daima yüksek potansiyelden düşüğe gider. Akım direncin üzerinden geçerken belli bir gerilim kaybeder. Direncin çıkış ucundaki düğüme (C) geldiğinde bu düğümün gerilimi hâlâ $V_A$'dan küçüktür, çünkü akım bir direnç üzerinden geçmiştir. Bu yüzden C ile A arasındaki diyot iletmez. Akım, B ucu toprakta olduğu için alttaki diyottan geçer. Öbür düğümde (D) de gerilim B'ye göre öyle değildir ki oradaki diyot iletsin; o diyot da çalışmaz.

<!-- BELİRSİZ: Hocanın bu cevabında D düğümü ile B ucu arasındaki karşılaştırma altyazıda karışık ("hala B'den küçük olduğu için bu da çalışmıyor", 01:32:58); hangi diyot için söylendiği karesiz kesinleştirilemedi. -->

### 14.4 Transformatörlü tam dalga doğrultucu

Tam dalga doğrultmanın başka yolları da vardır; bunlarda transformatör devreleri kullanılır. Transformatörler farklı sarım sayılarıyla gerilimi dönüştüren yapılardır. Hoca bu kısma fazla girmeyeceğini, ilk kısmın (köprü doğrultucunun) bilinmesinin yeterli olduğunu söyledi.

### 14.5 Gerçek diyotla DC seviye

Şimdiye kadarki değerler ideal diyot içindir. Hoca daha gerçekçi bir hesap için şunu söyledi: yarım dalga doğrultucuda akım bir diyottan geçtiği için 0,7 V düşülmelidir. Köprü doğrultucuda akım her yarı periyotta iki diyottan geçtiği için $2 \times 0{,}7$ V çıkarılmalıdır.

> **Ders sonrası not:** Hoca bu düşüşü "DC seviyeden çıkarmak" diye ifade etti (01:26:45). Ders kitaplarındaki yaygın yaklaşım, diyot gerilimini tepe değerden çıkarmaktır: yarım dalgada büyük olasılıkla $V_{dc} \approx 0{,}318\,(V_m - 0{,}7)$, köprüde $V_{dc} \approx 0{,}636\,(V_m - 1{,}4)$. Çıkışın tepe değeri yarım dalgada $V_m - 0{,}7$, köprüde $V_m - 1{,}4$ V olur.

## 15. Diyot Kırpıcılar

Dersin son konusu diyot kırpıcılardı (clippers). Hoca önce girişin yalnız sinüs olmak zorunda olmadığını söyledi: ortalaması sıfır olan kare dalga ya da üçgen dalga da uygulanabilir. Bunların hepsi salındığı için AC işaret sayılır.

Clipper, resimlerdeki kesme işlemi gibi, işaretin bir kısmını kesmek anlamında kullanılır. Diyot devreye seri bağlandığında seri kırpıcı (series clipper) denir. Girişe bir kare dalga uygulanırsa diyot pozitif kısmı geçirir; negatif kısımda açık devre gibi davrandığı için o kısmı geçirmez. Bu aslında yarım dalga doğrultucudur. Girişe üçgen dalga uygulanırsa da üçgenin pozitif olduğu yerler geçer, negatif olduğu yerler ideal diyotla geçmez.

Hoca bundan sonra devreye çeşitli güç kaynakları eklenmiş farklı bağlantı şekillerinin, standart girişin nasıl değiştiğinin örnekler üzerinden çalışılacağını söyledi. Dersin sonunda ekranda bu türden, seri kırpıcıya 5 V'luk DC kaynak eklenmiş bir örnek slayt görünüyordu (ekrandan, 01:30:00), ancak bu derste anlatılmadı.

## Örnek Sorular

### Soru 1: Paralel iki silisyum diyot

(ekrandan, 01:05:00)

Şekildeki devrede $E = 10$ V'luk kaynağa seri $R = 0{,}33$ kΩ'luk direnç ve direncin çıkışına paralel bağlı iki özdeş silisyum diyot ($D_1$, $D_2$) vardır. $V_o$, $V_R$, $I_1$, $I_{D1}$ ve $I_{D2}$ değerlerini bulun.

**Çözüm (derste verildi):**

- Si diyot iletimde: $V_D = 0{,}7$ V. Paralel bağlı oldukları için $V_{D1} = V_{D2} = V_o = 0{,}7$ V.
- $V_R = E - V_D = 10 - 0{,}7 = 9{,}3$ V.
- $I_1 = I_R = \dfrac{E - V_D}{R} = \dfrac{9{,}3\ \text{V}}{0{,}33\ \text{k}\Omega} \approx 28$ mA.
- Diyotlar özdeş: $I_{D1} = I_{D2} = 28/2 = 14$ mA.

### Soru 2: Yarım dalga doğrultucunun DC değeri

(derste sözlü, 01:17:44)

Tepe değeri $V_m = 10$ V olan bir sinüs ideal yarım dalga doğrultucudan geçirilirse çıkışın ortalama (DC) değeri ne olur? Aynı işaret tam dalga doğrultulursa ne olur?

**Çözüm (derste verildi):** Yarım dalgada $V_{dc} = 0{,}318\,V_m = 0{,}318 \times 10 = 3{,}18$ V. Tam dalgada alan iki katına çıktığı için $V_{dc} = 0{,}636\,V_m$ olur.

> **Çözüm (derste verilmedi):** Tam dalga için sayısal değer $0{,}636 \times 10 = 6{,}36$ V'tur (python ile $20/\pi \approx 6{,}37$ V; 0,636 yuvarlanmış katsayıdır).

### Soru 3: Diyot bozuk mu?

(derste sözlü, 00:37:46)

Elinizde yalnız bir direnç ölçer (multimetre) varsa bir diyotun sağlam olup olmadığını nasıl anlarsınız?

**Çözüm (derste verildi):** Multimetre direnç konumuna alınır. Kırmızı uç anoda, siyah uç katoda konunca düşük direnç; uçlar ters çevrilince yüksek direnç okunmalıdır. İleri yönde yüksek değer okunuyorsa diyotun iç yapısı bozulmuştur.

### Soru 4: Ters kutuplamada Zener bölgesi

(derste sözlü, 01:18:31)

Yarım dalga doğrultucuda negatif yarı periyotta diyot açık devre kabul ediliyor. Giriş genliği çok büyükse ne olur?

**Çözüm (derste verildi):** Ters gerilim Zener gerilimine ulaşırsa diyot ters yönde de akım akıtır ve devre yanlış çalışır. Bu yüzden devre, diyotun Zener bölgesine girmeyeceği garanti edilerek kurulur; normal diyotlarda Zener gerilimi çok uzak bir negatif değerdedir.

### Soru 5: Köprüde kesimdeki diyot

(derste sözlü, 01:31:45)

Köprü doğrultucunun pozitif yarı periyodunda akım dirençten geçtikten sonra neden üstteki kesimdeki diyottan yukarı çıkmaz?

**Çözüm (derste verildi):** Akım yüksek potansiyelden düşüğe akar. Dirençten geçen akım gerilim kaybettiği için direncin çıkış ucundaki düğümün gerilimi hâlâ girişin yüksek ucundan ($V_A$) küçüktür; bu yüzden aradaki diyot ters kutuplu kalır ve iletmez. Akım, toprağa (B ucu) bağlı olan diyottan devresini tamamlar.

## Dersin Toparlaması

Bu derste PN ekleminin fiziğinden başlanıp diyotun devrelerdeki ilk uygulamalarına kadar gelindi. P ve N tipi malzemelerin birleşmesiyle oluşan tükenme bölgesi ve potansiyel bariyeri, ileri kutuplamada daralıp ters kutuplamada genişleyerek diyotun tek yönlü iletimini açıklar. Gerçek diyotun silisyumda 0,7 V, germanyumda 0,3 V, galyum arsenitte yaklaşık 1,2 V'luk bir eşiği, ters yönde mikroamper düzeyinde bir doyma akımı ve büyük ters gerilimlerde bir Zener bölgesi vardır. Bu davranışlardan Zener diyot, LED ve diyot dizileri gibi farklı türler üretilir. Gerçek diyot; ideal diyot, bariyer gerilimi ve iç direncin seri bağlantısıyla modellenir.

Devre analizinde diyotun çalışma noktası yük doğrusu ile karakteristiğin kesişimidir. Seri ve paralel devrelerde silisyum diyot 0,7 V'luk bir gerilim düşümü olarak alınır; paralel özdeş diyotlarda akım eşit bölünür. AC'yi DC'ye çevirmenin ilk adımı doğrultmadır: yarım dalga doğrultucu $0{,}318\,V_m$, köprü doğrultucu $0{,}636\,V_m$ DC seviye verir. Son olarak seri kırpıcılara giriş yapıldı; hoca bir sonraki aşamada devreye DC kaynaklar eklenmiş kırpıcıların örnekler üzerinden inceleneceğini, diyotlardan sonra da diyotun daha karmaşık bir hali olan transistörlere geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
