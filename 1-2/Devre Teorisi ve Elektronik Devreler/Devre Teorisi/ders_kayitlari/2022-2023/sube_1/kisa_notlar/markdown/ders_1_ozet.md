# Ders 1 Çalışma Özeti

## Genel Konular

- Devre teorisi nedir: soyutlama mantığı
  - Elektriksel ve manyetik olayların tamamını açıklayan teori elektromanyetik dalga teorisidir. Bu teori hem zamana hem konuma ($x, y, z$) bağlı bir dalga denkleminin çözümünü ister; büyük sistemlerde bu çözüm çok zahmetlidir.
  - Bunun yerine katman katman soyutlama kullanılır: her seviye bir "kara kutu" (black box) olarak, yalnız uçlarındaki davranışla tanımlanır.
  - İlk seviye soyutlama tek tek devre elemanlarıdır. Örneğin direnç, uçlarındaki gerilim ile üzerinden geçen akımın direnç değeriyle orantılı olduğu bir eleman olarak tanımlanır.
  - Üst seviyeler: lojik kapılar (içinde transistör ve kapasite gibi pek çok eleman), entegre devreler (örneğin iki ikili sayıyı toplayan bir ALU), mikroişlemci, mikrodenetleyici, alt sistem ve sistem seviyeleri.
- Dersin kapsamı ve kazanımları
  - Temel devre elemanları ve DC kaynaklı devrelerin davranışı; ardından enerji depolayan elemanlar (kapasite, endüktans); en sonda AC (sinüzoidal) kaynaklı devreler.
  - Zaman domeninde çözüm diferansiyel denklemlere götürür; sabit frekanslı sinüzoidal kaynaklarda fazör uzayına geçilerek elemanlar basit cebirsel bağıntılarla tanımlanır.
  - Devre teoremleri (çözümü basitleştiren yöntemler) hem zaman domeninde hem fazör uzayında işlenir.
  - Yalnız analiz değil tasarım da hedeflenir. Örnek: 12 V'luk bir kaynaktan 5 V elde etmek; en basit yol gerilim bölücüdür, ama gerilim bölücü güç kaybı yüksek bir çözümdür.
  - İşlemsel kuvvetlendirici (op-amp) çok terminalli bir eleman olarak işlenecek; RL ve RC devreleri birinci derece, RLC devreleri ikinci derece diferansiyel denklem üretir.
- SI birim sistemi ve önekler
  - Temel birimler: uzunluk metre, kütle kilogram, zaman saniye, akım amper, sıcaklık kelvin; yük birimi coulomb.
  - Önekler 10'un kuvvetleridir (ekrandan, 00:55:00): exa $10^{18}$, peta $10^{15}$, tera $10^{12}$, giga $10^{9}$, mega $10^{6}$, kilo $10^{3}$, hecto $10^{2}$, deka $10$, deci $10^{-1}$, centi $10^{-2}$, milli $10^{-3}$, micro $10^{-6}$, nano $10^{-9}$, pico $10^{-12}$, femto $10^{-15}$, atto $10^{-18}$.
  - Aynı uzaklık: 600 000 000 mm = 600 000 m = 600 km (ekrandan, 00:55:00).
  - Hesapta bütün büyüklükler temel birimlere çevrilir; çıktı birimi istenmişse ona dönüştürülür.
- Anlamlı basamak, doğruluk ve yuvarlama (ekrandan, 01:00:00)
  - Sayılar tam (exact, örneğin 12 elma) ya da yaklaşıktır (approximate; laboratuvarda okunan her değer yaklaşıktır).
  - Hassasiyet (precision) anlamlı basamak sayısıyla, doğruluk (accuracy) ölçülen değerin bilinen değere yakınlığıyla ilgilidir.
  - Yuvarlama: atılan basamak 5 ve üzerindeyse önceki basamak bir artırılır, 0-4 ise olduğu gibi kalır. Örnek: $3.186 \cong 3.19 \cong 3.2$.
  - Bilimsel gösterimde birler basamağında bir rakam, ondalıktan sonra en az iki anlamlı basamak ve $\times 10^{n}$ çarpanı kullanılır.
- Elektrik akımı ve elektron akımı
  - Elektronlar negatif yüklüdür ve yoğun oldukları bölgeden az oldukları bölgeye hareket eder. Elektron kaybeden atomlar net pozitif kalır.
  - Bu soyutlama seviyesinde elektrik akımının yönü, elektron akışının tersidir: dış devrede akım pozitif terminalden negatif terminale, elektronlar negatiften pozitife akar.
  - Su analojisi: yükseklik farkı gerilime, akan su akıma karşılık gelir. Akımı iki şey belirler: elektronların ne kadar serbest olduğu (malzemenin öz direnci) ve uygulanan potansiyel farkın büyüklüğü.
- Referans (toprak, ground) ve düğüm gerilimi
  - Gerilim, birim yükü belli bir mesafe hareket ettirmek için gereken enerjidir; her zaman bir referansa göre tanımlanır (yüksekliğin deniz seviyesine göre ölçülmesi gibi).
  - Bütün devre için tek bir sabit referans seçilir ve 0 V kabul edilir. Başka bir değer (örneğin 10 V) seçmek sonucu değiştirmez, ama her düğümden o değeri çıkarmak gerekir.
  - Düğüm gerilimi: bir noktanın referansa göre gerilimi. Eleman gerilimi: elemanın iki ucunun düğüm gerilimleri farkı ($V_1 - V_2$).
  - Farklı referanslarla çalışan iki devre bloğu birbirine bağlanacaksa toprakları (GND) bir kabloyla birleştirilir; böylece ikisi aynı referansa gelir.
- Devre bileşenleri (ekrandan, 01:20:00)
  - Aktif elemanlar devreye güç verir: bağımsız kaynaklar (gerilim, akım) ve bağımlı kaynaklar (gerilim, akım).
  - Pasif elemanlar güç tüketir: direnç, kapasite, endüktans. Kapasite ve endüktans ilk enerjiye sahip olabilir (yüklü kapasite, ilk akımı olan endüktans), ama net olarak enerji tüketirler.
  - Ölçü aletleri (ampermetre, voltmetre), toprak, kablo, anahtar, koruma elemanı (sigorta).
- Bağımsız kaynaklar (ekrandan, 01:35:00)
  - İdeal gerilim kaynağı, çekilen akım ne olursa olsun devreye ayarlı gerilimini verir; akımını bağlı olduğu devre belirler.
  - İdeal akım kaynağı, devreye sabit akım verir; uçlarındaki gerilimi bağlı olduğu devre belirler.
  - Sembol: pil sembolünde uzun çizgi pozitif, kısa çizgi negatif terminaldir; daire içindeki gerilim kaynağı sembolünde $+$ ve $-$ yazılmalıdır. Akım kaynağı daire içinde okla gösterilir; ok verdiği akımın yönüdür.
- Bağımlı kaynaklar
  - Eşkenar dörtgen (baklava) sembolüyle çizilir; değeri devrenin başka bir yerindeki bir akım ya da gerilimle orantılıdır.
  - Dört tür: gerilim kontrollü gerilim kaynağı (VCVS), akım kontrollü gerilim kaynağı (CCVS), gerilim kontrollü akım kaynağı (VCCS), akım kontrollü akım kaynağı (CCCS). Örneğin değeri $k\,I_1$ olan bir gerilim kaynağı CCVS'dir.
- Güç işareti ve enerjinin korunumu
  - Pasif işaret kuralı: akım elemanın $+$ ucundan giriyorsa $p = vi$ pozitiftir ve eleman güç tüketir; akım $+$ ucundan çıkıyorsa güç negatiftir ve eleman güç verir.
  - Kapalı bir devrede bütün elemanların güçleri toplamı sıfırdır.
- Ampermetre ve voltmetre
  - Ampermetre ölçülen kola seri bağlanır; ideal iç direnci sıfırdır, yani kısa devre gibi davranır.
  - Voltmetre ölçülen elemana paralel bağlanır; ideal iç direnci sonsuzdur, yani açık devre gibi davranır.
  - Voltmetre kırmızı probun bağlandığı düğümün geriliminden siyah probun bağlandığı düğümün gerilimini çıkarır. Sonuç negatif çıkabilir; bir düğümün kaynağa yakın olması onun daha yüksek gerilimde olduğu anlamına gelmez.
- Diğer temel elemanlar
  - Kablo: ideal durumda iç direnci sıfırdır; kesintisiz bir kablonun iki noktası arasındaki gerilim her zaman sıfırdır.
  - Anahtar: yanında $t = 0$ yazan anahtar, $-\infty$'dan $t = 0^-$'a kadar açık, $t = 0$ anında kapalıdır. "Açık" yolun kesildiği, "kapalı" yolun tamamlandığı durumdur.
  - Sigorta: normalde kısa devre gibi davranır; taşıyabileceğinden fazla akımda yanar ve açık devre olur. Koruduğu elemana seri bağlanır.
  - Kablo kesiti çekilecek akıma göre seçilir; yaygın standart AWG'dir. Yetersiz kesitli kablo ısınır.
  - Toprak sembolleri (ekrandan, 02:20:00): earth, chassis, ground, analog ground, digital ground. Derste tek bir sabit referans (earth sembolü) kullanılacak.
- Pasif elemanların sembolleri ve birimleri (ekrandan, 02:15:00)
  - Direnç (resistor): zikzak sembol, birimi ohm ($\Omega$).
  - Endüktans (inductor): yarım çember sargılar, birimi henry (H).
  - Kapasite (capacitor): iki paralel plaka, birimi farad (F).
  - DC'de uzun süre sonra endüktans kısa devre, kapasite açık devre gibi davranır.
- Tanım bağıntısı
  - Bir elemanın uç akım ve gerilimleri arasındaki ilişkiyi veren denklemdir. Direnç için $V/I = R$, kapasite için $q = C\,v$, yani $\int i\,dt = C\,v$.
  - $N$ terminalli bir eleman için $N-1$ tanım bağıntısı yeterlidir; eksik kalan bağıntı, terminallerden birinin referans (0 V) seçilmesiyle karşılanır.
- Akım akışı kuralları ve Ohm yasasına giriş (ekrandan, 02:35:00)
  - Akım, bir yol varsa yüksek gerilimden düşük gerilime akar ve düşük dirençli yolu tercih eder; paralel dirençlerde küçük dirençten daha büyük akım geçer.
  - Bir dirençte akım, uygulanan gerilimle doğru orantılıdır; $V/I$ oranı sabittir ve direnç değeridir. Direnç uzunlukla artar, kesit alanıyla azalır ve malzemenin öz direncine bağlıdır.
  - Gerilim kaynağından geçen akımı devrenin geri kalanı belirler; akım kaynağının uçlarındaki gerilimi de devrenin geri kalanı belirler.
- Yük, akım, gerilim, güç, enerji
  - Bir elektronun yükü $1.6 \times 10^{-19}$ C'dir.
  - Büyük harf ($V, I, Q$) zamanla değişmeyen DC büyüklükleri, küçük harf ($v(t), i(t), q(t)$) zamanla değişen büyüklükleri gösterir.
  - Akım, birim zamandaki net yük değişimidir (ekrandan, 02:40:00): $i = \dfrac{dq}{dt}$ (ayrık zamanda $\Delta q / \Delta t$), birimi C/s = A; $Q = \int_{t_1}^{t_2} i\,dt$.
  - Gerilim, enerji değişiminin yük değişimine oranıdır: $v = \dfrac{dw}{dq}$.
  - Güç, birim zamandaki enerjidir: $p = \dfrac{dw}{dt} = \dfrac{dw}{dq}\cdot\dfrac{dq}{dt} = v\,i$.
  - Enerji (ekrandan, 02:55:00): $w = \int_{t_1}^{t_2} p\,dt = \int_{t_1}^{t_2} v\,i\,dt$. Elektrik sayaçlarının birimi kWh'dir: $1\ \text{kWh} = 3.6\ \text{MJ}$.
- DC ve AC işaretler
  - DC (direct current): değeri zamanla değişmez, örneğin $V_1 = 1$ V.
  - AC (alternating current): zamana bağlıdır, örneğin $v_1(t) = 10\sin(2\pi\cdot 1000\,t + \pi/2)$.
  - Sinüzoidal bir işaretin dört parametresi: DC bileşen, genlik, frekans, faz açısı.

## Hocanın Özellikle Vurguladığı Kısımlar

- İdeal kaynakların neyi sabit tuttuğu
  - Gerilim kaynağının gerilimi sabittir, akımı devreye göre değişir; akım kaynağının akımı sabittir, gerilimi devreye göre değişir. Bir kaynağın hem akımının hem geriliminin her devrede sabit olduğu varsayılmamalıdır. Hoca bunu ders boyunca birkaç kez tekrarladı.
- Güç işareti
  - Negatif güç güç veren (aktif), pozitif güç güç tüketen (pasif) eleman demektir. Kapalı devrede toplam güç sıfırdır.
  - Birden fazla kaynağı olan bir devrede bir bağımsız kaynağın gücü pozitif çıkabilir; bu kaynak güç tüketiyordur. Pratik örnek: şarj olan şarj edilebilir pil ya da powerbank.
- Ölçü aletlerinin eşdeğeri
  - Ampermetre seri ve kısa devre (iç direnç 0), voltmetre paralel ve açık devre (iç direnç $\infty$).
- Kapasite ve endüktansın DC davranışı
  - DC kaynağa uzun süre bağlı endüktansın uçlarında 0 V ölçülür (kısa devre); kapasitenin uçlarında kaynak gerilimi ölçülür (açık devre). Semboller de bu davranışı çağrıştırır: endüktans sarılmış bir tel, kapasite iki ayrık plakadır.
- Tek referans
  - Bütün gerilimler tek bir referansa göre tanımlanır ve referans 0 V seçilir. Ayrı referanslı iki devre birleştirilecekse toprakları birleştirilir.
- Birimlere dikkat
  - Hesap öncesi değerler SI temel birimlerine çevrilir (örneğin öz direnç hesabında metre ve metrekare). Yuvarlamada en az iki anlamlı basamak korunur.

## Kısa Tekrar Notları

- Devre teorisi, elektromanyetik dalga teorisinin bir üst soyutlama seviyesidir; elemanlar kara kutu olarak uç davranışlarıyla tanımlanır.
- SI önekleri binerli adımlarla ilerler (kilo, mega, giga, ... ; milli, mikro, nano, piko, ...). Ara adımlar: deka, hekto, desi, santi.
- 4000 m'yi 1 dakikada giden cismin hızı $4\ \text{km} / (1/60)\ \text{h} = 240$ km/h.
- Elektrik akımı elektron akışının tersi yönündedir.
- Referans (toprak) her zaman 0 V; eleman gerilimi iki düğüm geriliminin farkıdır.
- Aktif: bağımsız ve bağımlı kaynaklar. Pasif: R, L, C.
- Bağımlı kaynak türleri: VCVS, CCVS, VCCS, CCCS; sembol eşkenar dörtgen.
- Pasif işaret kuralı: akım $+$ uçtan giriyorsa $p = vi > 0$ (tüketir).
- Ampermetre: seri, $R_{\text{iç}} = 0$. Voltmetre: paralel, $R_{\text{iç}} = \infty$.
- DC kararlı halde: L kısa devre, C açık devre.
- Sigorta seri bağlanır; aşırı akımda açık devre olur.
- $N$ terminalli eleman: $N-1$ tanım bağıntısı.
- $i = dq/dt$, $v = dw/dq$, $p = vi$, $w = \int p\,dt$, $1$ kWh $= 3.6$ MJ, $e = 1.6 \times 10^{-19}$ C.
- Sinüzoidal işaret: DC bileşen, genlik, frekans, faz. Saf sinüsün bir periyottaki ortalaması sıfırdır.

## Detaylı Açıklamalar

- **Soyutlama ve devre teorisinin yeri.** Gerçek fiziksel davranış Maxwell denklemlerinden gelen elektromanyetik dalga teorisiyle açıklanır. Ancak bir direnci bile bu düzeyde çözmek, zamana ve konuma bağlı bir kısmi diferansiyel denklem demektir. Devre teorisi bunun yerine elemanı deneylerle karakterize eder: belirli bir aralıkta direncin doğrusal olduğu ve uç geriliminin akıma oranının sabit kaldığı görülür; bu oran direnç değeri olarak tanımlanır. Aynı fikir daha üst seviyelerde tekrarlanır: lojik kapılar transistörleri, ALU kapıları, mikroişlemci de ALU gibi blokları soyutlar.

- **Referans ve gerilim.** Bir topun düştüğü yükseklik farkı ile düşme hızının ilişkisi gibi, bir elemandan geçen akımı belirleyen şey o elemanın iki ucu arasındaki potansiyel farktır. Her noktanın ortak bir referansa (toprak) göre değeri düğüm gerilimidir; elemanın gerilimi iki düğüm geriliminin farkıdır. Referans 0 V seçildiğinde düğüm gerilimleri doğrudan okunur. Derste sorulan soruda iki ayrı referansla çalışan devrenin birbirine bağlanması tartışıldı: doğru yaklaşım, iki devrenin GND'lerini bir kabloyla birleştirip ortak bir referans oluşturmaktır.

- **Örnek 1: akım kaynağı ve eleman (ekrandan, 01:40:00 ve 01:45:00).** Devre: 3 A'lik bağımsız akım kaynağı ile kırmızıyla gösterilen bir eleman paraleldir. Elemanın uçlarındaki gerilim 1 V'tur ($+$ üstte). Paralel bağlı oldukları için akım kaynağının uçlarında da 1 V vardır; yani kaynağın gerilimini bağlı olduğu eleman belirlemiştir.
  - Akım kaynağı: 3 A kaynağın $+$ ucundan çıkar (akım gerilimin $-$ ucundan girip $+$ ucundan çıkar). Pasif işaret kuralına göre $p = -3\ \text{A} \cdot 1\ \text{V} = -3$ W; kaynak 3 W güç üretir.
  - Kırmızı eleman: 3 A elemanın $+$ ucundan girer. $p = 3\ \text{A} \cdot 1\ \text{V} = 3$ W; eleman 3 W güç tüketir.
  - Enerjinin korunumu: $\sum p = -3 + 3 = 0$ W.

- **Bağımlı kaynak örneği.** Hoca, bağımsız bir gerilim kaynağı, birkaç direnç, bir bağımlı akım kaynağı ve bir bağımlı gerilim kaynağından oluşan bir devre çizdi. Bir dirençteki gerilime $V_1$, bir koldaki akıma $I_1$ dendi. Değeri $k\,V_1$ olan akım kaynağı gerilim kontrollü akım kaynağıdır; değeri $m\,I_1$ olan gerilim kaynağı akım kontrollü gerilim kaynağıdır. Değişkenler yer değiştirseydi ($n\,I_2$ değerli akım kaynağı, $t\,V_2$ değerli gerilim kaynağı) sırasıyla akım kontrollü akım kaynağı ve gerilim kontrollü gerilim kaynağı elde edilirdi. <!-- BELİRSİZ: çizilen devrenin tam bağlantısı kareden doğrulanamadı; bu anın karesi yok. -->

- **Pil ve akım kaynağı.** Pil ideal olmayan bir bağımsız gerilim kaynağıdır: iç direnci vardır, fazla akım çekildikçe enerjinin bir kısmı içeride ısıya dönüşür ve uç gerilimi düşer. Bu, onu akım kaynağı yapmaz. Pratikte akım kaynağı akım aynası gibi elektronik devrelerle ya da sabit akım modunda çalışan ayarlı güç kaynaklarıyla elde edilir.

- **Endüktansın AC davranışı (soru üzerine).** Endüktansta akım ile gerilim arasında türev/integral ilişkisi vardır; AC işarette gerilim değiştikçe akım onu geriden izler ve eleman dirence benzer bir davranış gösterir. AC'de buna empedans denir. Aynı durum kapasite için de geçerlidir. Ayrıntı ileriki haftalarda işlenecek.

- **AC işaret parametreleri (ekrandan, 02:45:00 ve 02:50:00).** Hoca beyaz tahtada $5\sin(10t)$ işaretini temel alıp üç karşılaştırma yaptı:
  - Yukarı kaydırılmış işaret: minimumu 0'a taşımak için $+5$ eklenir, $5 + 5\sin(10t)$. $5$ DC bileşen, $5\sin(10t)$ AC bileşendir. DC bileşen işaretin bir periyottaki ortalamasıdır; saf sinüsün ortalaması 0, bu işaretinki 5'tir.
  - Genliği büyük ve frekansı düşük işaret: genlik katsayısı büyür, açısal frekans küçülür (örneğin $10t$ yerine $5t$); bir periyodu tamamlaması daha uzun sürer.
  - Zamanda kaymış işaret: $5\sin(10t + \phi)$; genlik ve frekans aynı, yalnız faz açısı $\phi$ kadar fark var.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
