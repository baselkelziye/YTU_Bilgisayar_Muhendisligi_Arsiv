# Ders 2 Çalışma Özeti

## Genel Konular

- Analog işaretten sayısal işarete geçiş problemi
  - Sürekli (analog) bir $x(t)$ işareti zamanın her anında tanımlıdır, yani sonsuz sayıda değerden oluşur. Bilgisayar (mikrodenetleyici, mikroişlemci gibi hesaplama yapan bir birim) bu işareti doğrudan saklayamaz, çünkü hafıza sınırlı bir kaynaktır.
  - İşaretler bir boyutlu (ses, kalp işareti), iki boyutlu (gri seviye görüntü) ya da daha çok boyutlu (renkli görüntü, MR kesitleri) olabilir. Derste genellikle bir boyutlu işaretler üzerinden gidilir; sonuçlar $n$ boyuta genelleştirilebilir.
- Sinüzoidal işaretler
  - Genel biçim: $x(t) = A\sin(\omega t + \varphi)$ (ekrandan, 00:15:00). $A$ genlik (işaret $A$ ile $-A$ arasında salınır), $\varphi$ faz (işaretin başlangıç durumu), $\omega = 2\pi f$ açısal frekanstır.
  - Periyot ile frekans ters orantılıdır: $T = 1/f$. Frekansın birimi Hz'dir ve işaretin bir saniyede kaç çevrim tamamladığını gösterir (100 Hz, saniyede 100 çevrim).
  - Sinüs ile kosinüs aynı fonksiyondur, aralarında yalnız 90 derecelik faz farkı vardır.
- DC ve AC işaretler
  - $f = 0$ olan, zamanla değişmeyen işaret DC (Direct Current) işarettir. Pil ve adaptörler sabit gerilim verir.
  - Salınım yapan, artı ve eksi arasında değişen işaret AC (Alternating Current) işarettir. Şehir şebekesi 220 V, 50 Hz'lik sinüzoidal bir işarettir (110 V kullanan ülkelerde 60 Hz).
  - Ders sonrası not: Hoca işaretin +220 V ile −220 V arasında salındığını söyledi; 220 V şebekenin etkin (RMS) değeridir, tepe genliği yaklaşık $220\sqrt{2} \approx 311$ V'tur.
- Fourier analizi
  - Bir işaret, farklı frekans ve genliklerdeki (sonsuz sayıda) sinüzoidalin toplamı olarak yazılabilir. Bazı frekansların genliği sıfır olabilir; o frekans işarete katkı yapmaz.
  - Pratikte bir işaretin sonsuz sayıda frekans bileşeni olmaz; kaynak belli bir bant genişliğinde üretir. İnsan sesi yaklaşık 4 kHz'e kadar frekans içerir.
- Örnekleme (sampling) ve Nyquist teoremi
  - İşaretten $T_s$ (örnekleme periyodu) aralıklarla örnek alınır; $f_s = 1/T_s$ örnekleme frekansıdır.
  - Amaç: $T_s$'yi olabildiğince geniş seçip hafızayı korumak, ama işaretin bilgi taşıyan değişimlerini kaçırmamak.
  - En kötü durum, en yüksek frekanslı bileşende ($f_{max}$) yalnız tepe noktalarının alınmasıdır: $T_{max} = 2T_s$, yani $f_s = 2f_{max}$. Daha sık örneklenirse ($T_{max} = 4T_s$) $f_s = 4f_{max}$ olur.
  - Nyquist teoremi: $f_s \geq 2 f_{max}$ (ekrandan, 00:35:00).
  - Bant geçiren işaretlerde de (alt frekanslar yoksa da) Nyquist oranı en yüksek frekansın iki katıdır.
- Nicemleme (quantization) ve kodlama (encoding)
  - Örnekleme zaman (x) eksenini ayrıklaştırır; genlik (y) ekseni hâlâ sonsuz değer alabilir. Hafıza ise bitlerden oluşur.
  - Genlik ekseni $\Delta$ genişliğinde aralıklara (kuanta seviyelerine) bölünür; bir aralığa düşen her değer o aralığın ortalama değeriyle saklanır. $b$ bit ile $2^b$ seviye elde edilir.
  - Her seviyeye bir ikili (binary) kod atanır ve hafızaya yazılır. Analog işaret → örnekleme → nicemleme → kodlama → sayısal veri.
  - Hem örnekleme hem nicemleme hata getirir; saklanan işaret orijinal işaretin yaklaşığıdır ($\tilde{x}[n]$).
- Sürekli ve ayrık işaret gösterimi
  - Sürekli işaret normal parantezle, $x(t)$; ayrık işaret köşeli parantezle, $x[n]$ gösterilir. $n$ örnek indisidir.
- Bilgi, veri ve sistem kavramları (slaytlar: "Information Systems: Fundamentals")
  - Yapılandırılmamış veriden amaç doğrultusunda bilgi (enformasyon) çıkarılır. Örnek: kalp işaretinden QRS kompleksi ve tepe noktaları arasındaki oranlarla hastalık tespiti.
  - Sistem: ortak bir amaca ulaşmak için birlikte çalışan bileşenler; giriş, işlem, çıkış ve geri besleme.
  - Tipik ölçüm sistemi: fiziksel işaret → algılayıcı → analog yükseltme/filtreleme → ADC (örnekleme + nicemleme) → hafıza → işaret işleme algoritması → sonuç.
- Sayısal veri temsili
  - Bit, nibble (4 bit), byte (8 bit), word (sisteme göre 16 ya da 32 bit).
  - Bilgisayarda kilo $2^{10}$, mega $2^{20}$ ile çarpılır (1 KB = 1024 byte, 1 MB = 1.048.576 byte) (ekrandan, 01:40:00).
  - Hertz: saniyedeki saat çevrimi. Saat işareti kare dalgadır; işlemler yükselen (ya da düşen) kenarda tetiklenir.
  - 8 bit ile $2^8 = 256$ durum: işaretsiz 0–255, işaretli −128…+127.
  - İşaret biti (sign-magnitude) gösteriminde +0 ve −0 iki ayrı koddur; ikinin tümleyeni (two's complement) bu israfı ortadan kaldırır.
  - Sabit noktalı (fixed point) ve kayan noktalı (IEEE-754, 32 bit) gösterim.
  - $k$ farklı durum için gereken bit sayısı $\lceil \log_2 k \rceil$.
  - BCD (8421), onaltılık (hex) sayılar, ASCII; dönüştürme (conversion) ile kodlama (coding) farkı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Nyquist teoremi: $f_s \geq 2 f_{max}$
  - $f_{max}$'ı biz seçmeyiz, işaret kaynağının doğası belirler. $f_s = 2f_{max}$ en geniş $T_s$'yi (en az örneği) verir; $f_s$ arttıkça orijinal işarete daha çok yaklaşılır ama hafıza ihtiyacı artar.
  - Örnek: 4 kHz'lik ses en az 8 kHz ile örneklenmelidir ($T_s = 125\ \mu s$). 360 Hz'e kadar bileşen içeren bir kalp işareti en az 720 Hz ile örneklenmelidir; 2000 Hz seçmek de mümkündür.
- Örnekleme frekansı ile kalite ve dosya boyutu dengesi
  - MP3 gibi dosyalarda örnekleme frekansı yükseldikçe kalite artar, dosya boyutu da büyür. 64 kHz, 8 kHz'in 8 katı örnek demektir.
- Bit sayısı ile nicemleme hatası dengesi
  - Bit sayısı arttıkça kuanta aralığı daralır ve hata azalır; karşılığında hafıza kapasitesi artırılmalıdır.
- Sürekli ve ayrık gösterim farkı
  - $x(t)$ ile $x[n]$ arasındaki parantez farkına dikkat edilmesi istendi.
- İkinin tümleyeni
  - Pozitif ve negatif sıfırın karışmaması, 8 bitte +127'den sonra −128'e geçilmesi gösterildi.
- Dönüştürme ile kodlamayı karıştırmamak
  - $13_{10} = 1101_2$ bir dönüştürmedir; $(0001\ 0011)_{BCD}$ ise kodlamadır. BCD kodunu düz ikili sayı gibi okumak 19 verir.

## Kısa Tekrar Notları

- Analog işaret sonsuz değerlidir; hafıza sınırlı olduğu için örnekleme ve nicemleme gerekir.
- $x(t) = A\sin(\omega t + \varphi)$, $\omega = 2\pi f$, $T = 1/f$.
- DC: $f = 0$, sabit. AC: salınımlı. Şebeke: 220 V, 50 Hz.
- Fourier: her işaret sinüzoidallerin toplamıdır.
- $f_s = 1/T_s$; Nyquist: $f_s \geq 2f_{max}$. Bant geçiren işaret için de en yüksek frekans esas alınır.
- 4 kHz ses → en az 8 kHz, $T_s = 125\ \mu s$; 16 kHz → $T_s = 62{,}5\ \mu s$.
- Örnekleme: zaman ekseni; nicemleme: genlik ekseni; kodlama: seviyeyi ikili koda çevirme.
- $b$ bit → $2^b$ seviye; bit arttıkça $\Delta$ ve hata küçülür, hafıza büyür.
- Örnekleme türleri (slayttan): $f_s = 2f_{max}$ yalnız tepeler, $f_s > 2f_{max}$ aşırı örnekleme (oversampling), $f_s < 2f_{max}$ (örneğin $f_s = f_{max}$) eksik örnekleme (undersampling).
- Bit, nibble = 4 bit, byte = 8 bit; 1 KB = $2^{10}$ byte, 1 MB = $2^{20}$ byte.
- 8 bit işaretli aralık: −128…+127. İkinin tümleyeni: bitleri ters çevir, 1 ekle.
- IEEE-754 tek duyarlık: 1 işaret + 8 üs (bias 127) + 23 kesir biti; $N = (-1)^s \times 1.\text{kesir} \times 2^{(\text{üs} - 127)}$.
- $\lceil \log_2 k \rceil$: 7 durum → 3 bit, 9 ya da 10 durum → 4 bit.
- BCD: her ondalık rakam ayrı 4 bitle kodlanır: $(57)_{10} = (0101\ 0111)_{BCD}$.

## Detaylı Açıklamalar

- **Örnekleme aralığının seçimi.** Sürekli bir işaretten örnek alırken $T_s$ ne kadar küçük seçilirse örnekler orijinal işarete o kadar yakın olur; ama her örnek bir hafıza gözü ister. $T_s$ çok büyük seçilirse işaretteki hızlı değişimler kaçırılır. Hoca, Fourier analizinden yola çıkarak en kötü durumu en yüksek frekanslı bileşen üzerinden kurdu: $f_{max}$ frekanslı sinüsün bir periyodunda yalnız tepe ve çukur noktaları alınırsa, iki örnek arası $T_s$ olur ve $T_{max} = 1/f_{max} = 2T_s$ elde edilir (ekrandan, 00:40:00). Bu eşitlik $f_s = 2f_{max}$'a karşılık gelir. Daha düşük frekanslı bileşenler aynı $T_s$ ile bir periyotta çok daha fazla örnekle temsil edilir, bu yüzden sorun yalnız en yüksek frekanstadır. Tepe noktalarının arasındaki sıfır geçişleri de alınırsa $T_{max} = 4T_s$, $f_s = 4f_{max}$ olur. Böylece eşitlik bir alt sınıra dönüşür: $f_s \geq 2f_{max}$ (Nyquist teoremi).
- **Sayısal örnek (ekrandan, 00:40:00).** $f_{max} = 4$ kHz olan insan sesi için $f_s \geq 8$ kHz gerekir. $T_s = 1/8000 = 125\ \mu s$ ($\mu = 10^{-6}$). Aralık 62,5 µs'ye daraltılırsa $f_s = 1/62{,}5\ \mu s = 16$ kHz olur; bu $4 f_{max}$'a karşılık gelir ve daha iyi bir örneklemedir.
  - Ders sonrası not: Altyazıda bir yerde "125 ms" geçiyor; tahtada yazan ve doğru olan 125 µs'dir.
- **Nicemleme.** Örnekleme yalnız zaman eksenini ayrıklaştırır. Örneğin genliği 3,5 ya da 3,758923… gibi sonsuz hassasiyette bir değer olabilir. Hafıza gözleri ise belli sayıda bitten oluşur (8, 16, 32, 64 bit; int, long int, float gibi tipler). 1 bit ile yalnız iki seviye (0 ve 1), 2 bit ile dört seviye (00, 01, 10, 11), 3 bit ile sekiz seviye ayırt edilir. Genlik ekseni bu seviyelere bölünür ve bir aralığa düşen her değer o aralığın ortası ile temsil edilir. Hocanın örneğinde 3,7–3,8 aralığına düşen değerler 3,75, bir üst aralıktakiler 3,85 olarak saklanır; 3,84 de bir üst aralığa düştüğü için 3,85'e yuvarlanır. Saklanan değer ile gerçek değer arasındaki farkların mutlak değerlerinin toplamı bir hata fonksiyonu verir: $\sum |x_i - A|$. Hoca "kuanta" kavramını atomdaki elektronların belli enerji seviyelerinde bulunmasına benzetti.
- **Ayrık işaret ve yaklaşıklık.** Örneklenmiş ve nicemlenmiş işaret, sürekli işaretin bir yaklaşığıdır. Örnekler arası değerler bilinmez; geri çatma sırasında örnekler düz çizgilerle birleştirilir ya da her değer bir sonraki örneğe kadar tutulur (düz tepeli, flat-top örnekleme). Önemli olan $T_s$ ve kuanta aralığının işareti incelemeye yetecek kadar küçük olmasıdır.
- **Slaytlardaki ADC zinciri (ekrandan, 01:30:00).** Sürekli işaret önce bir saat işaretine göre ölçülür ve her saat darbesinde tutulur (sample-and-hold); tutulmadan ölçülürse işaret ölçüm sırasında değişirdi. Tutulan değer ölçülüp sayısal değere dönüştürülür. Slaytlarda ayrıca ölçümün yalnız belli bir süre boyunca yapıldığı (yavaş değişimler kaçabilir) ve belli bir hassasiyette yapıldığı (küçük değişimler kaçabilir) vurgulanır (ekrandan, 01:35:00).
- **İkinin tümleyeni (ekrandan, 01:55:00).** İşaret biti gösteriminde $0\,0000000$ (+0) ve $1\,0000000$ (−0) iki ayrı koddur; bir durum boşa harcanır. İkinin tümleyeninde sayılar bir çember gibi dizilir: $0000\,0000$ = 0, $0111\,1111$ = +127, $1000\,0000$ = −128, $1111\,1111$ = −1. Negatif bir sayının büyüklüğünü bulmak için bitler ters çevrilir ve 1 eklenir. Tahtadaki örnek: $10001011$ → tümleme $01110100$ → +1 → $01110101 = 117$, yani sayı −117'dir (değer ajan tarafından python ile hesaplandı). Kısa yol: sağdan ilk 1'e kadar bitler aynen yazılır, sonrakiler ters çevrilir.
- **Sabit noktalı gösterim.** Virgülün yeri sabittir. Virgülün solundaki basamaklar $2^0, 2^1, 2^2, \dots$, sağındakiler $2^{-1}, 2^{-2}, \dots$ ağırlığındadır. Derste $11001{,}11_2 = 2^4 + 2^3 + 2^0 + 2^{-1} + 2^{-2} = 25{,}75$ hesaplandı. Kesir için yalnız 3 bit varsa en büyük kesir $0{,}5 + 0{,}25 + 0{,}125 = 0{,}875$'tir; bu gösterimin aralığını sınırlar.
- **IEEE-754 kayan noktalı gösterim (ekrandan, 02:00:00).** 32 bit: 1 işaret biti, 8 bit kaydırılmış (biased) üs, 23 bit kesir (mantis). $N = (-1)^s \times 1.\text{kesir} \times 2^{(\text{üs} - 127)}$. Üsse 127 eklenerek hem pozitif hem negatif üsler temsil edilir: $2^{-127}$ → 0, $2^0$ → 127, $2^{+127}$ → 254. Derste 25,75 örneği: $11001{,}11_2$'de virgül baştaki 1'in hemen sağına gelecek şekilde 4 basamak kaydırılır ($1{,}100111 \times 2^4$), üs alanına $4 + 127 = 131$ yazılır, işaret biti 0'dır.
  - Ders sonrası not: Derste tam 32 bit yazılmadı. Ajanın python ile kontrolüne göre 25,75'in IEEE-754 karşılığı `0 10000011 10011100000000000000000` (onaltılık `41CE0000`).
- **Bit sayısı, BCD ve hex.** $k$ durum için $\lceil \log_2 k \rceil$ bit gerekir: 7 renk → 3 bit, 9 durum → 4 bit, 10 rakam → 4 bit. BCD'de her rakam ayrı 4 bitle kodlanır, 1010–1111 kodları kullanılmaz: $(57)_{10} = (0101\ 0111)_{BCD}$ (ekrandan, 02:05:00). Onaltılık sistemde 0–9 ve A–F (F = 15) kullanılır; her hex rakam 4 bite karşılık gelir: $41_{16} = 0100\ 0001$, $5A_{16} = 0101\ 1010$. ASCII'de $41_{16}$ "A" harfidir; küçük harfler $61_{16}$–$7A_{16}$ aralığındadır.
- **Dönüştürme ve kodlama (ekrandan, 02:10:00).** $13_{10} = 1101_2 = 2^3 + 2^2 + 2^0$ bir dönüştürmedir. $13 \Leftrightarrow (0001\ 0011)_{BCD}$ ise kodlamadır; bu bit dizisini düz ikili sayı gibi okumak $2^4 + 2^1 + 2^0 = 19$ verir. Bu yüzden BCD kullanıldığı bilinmelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
