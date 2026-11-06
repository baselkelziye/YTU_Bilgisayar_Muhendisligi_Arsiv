# Ders 12 Genişletilmiş Notu: Kısa Sınav Çözümü, Fazör Uzayında Thevenin-Norton, Gerilim-Akım Bölücü, Bağımlı Kaynaklı Örnekler ve Özel Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Kısa Sınav Çözümü: İkinci Dereceden Devre
- 3. Sürekli Sinüzoidal Hâl ve Fazör Uzayı Tekrarı
- 4. Fazör Uzayında Thevenin-Norton Eşdeğeri
- 5. Merdiven Devre: Ardışık Kaynak Dönüşümü
- 6. Rezonanstaki LC Devresinin Norton Eşdeğeri
- 7. Gerilim Bölücü ve Akım Bölücü
- 8. Örnek 53: Bağımlı Gerilim Kaynaklı Devre
- 9. Örnek 54: Süper Düğüm ve Akım Kontrollü Kaynak
- 10. Örnek 56: Bağımlı Kaynaklı Devrenin Norton Eşdeğeri
- 11. Özel Fonksiyonlar: Basamak, Dürtü ve Rampa

## 1. Dersin Planı

Bu dersin son haftasıydı. Hoca, geçen haftadan kalan fazör uzayındaki devre teoremlerinden devam edeceğini söyledi. Geçen hafta fazör uzayında eşdeğer empedans ve eşdeğer iletkenlik tanımlanmıştı. Bu hafta önce kısa sınavın çözümü yapıldı. Ardından fazör uzayında Thevenin-Norton örnekleri, gerilim ve akım bölücü, bağımlı kaynaklı örnek çözümleri geldi. Dersin sonunda, dönem içinde hızlı geçilen özel fonksiyonlar örneklerle tamamlandı.

## 2. Kısa Sınav Çözümü: İkinci Dereceden Devre

### 2.1 Soru ve Genel Yaklaşım

Bu soru zaman domeninde çözüm isteyen bir soruydu, fazör kullanılmıyordu. Devre şöyleydi: Solda bir $i_s$ akım kaynağı ve ona paralel bir $C$ kapasitesi var. Kapasitenin üst ucundan bir $L$ endüktansı çıkıyor, $i_L$ bu yönde tanımlı. Endüktansın diğer ucu ile toprak arasında $R$ direnci var. Aynı düğümden bir anahtar üzerinden $5$ V'luk bir gerilim kaynağına gidiliyor. Anahtar uzun süre kapalı kaldıktan sonra $t = 0$ anında açılıyor. Değerler $R = 40\ \Omega$, $C = 25$ mF, $L = 10$ H.

Sorular şunlardı:

- **Soru 1:** $i_s = 10u(t)$ A için a) $i_L(0^-)$, b) $i_L(t)$.
- **Soru 2:** $i_s = e^{-3t}u(t)$ A için a) $i_L(\infty)$, b) $i_L(t)$.

Hoca önce derste görülen yapıları hatırlattı. Seri RLC devresinde analiz endüktans akımı üzerinden yapılıyordu, çünkü ana kol akımı oydu. Paralel RLC devresinde ise kapasite gerilimi üzerinden yapılıyordu, diğer büyüklükler onun cinsinden yazılabiliyordu. İkisinde de ikinci dereceden bir diferansiyel denklem çıkar. Bu yüzden iki bilgi gerekir: büyüklüğün belirli bir andaki değeri ve türevinin belirli bir andaki değeri. Seri ve paralel RLC'de bunları bulmak kolaydı. Bu soruda $i_L(0)$ kolaydı, ama $\frac{di_L}{dt}(0)$ "küçük bir trik" istiyordu.

Hocanın ikinci gözlemi şuydu: $i_s$ kaynağı ne olursa olsun devrenin homojen çözümü iki soruda da aynıdır. Homojen çözüm, diferansiyel denklemin sağ tarafı sıfırken elde edilen çözümdür. Fark yalnız zorlanmış çözümdedir. Birinci soruda bir sabit, ikinci soruda $e^{-3t}$ çarpanlı bir terim önerilir.

### 2.2 $t < 0$ Devresi

Her iki soruda da $i_s$ bir $u(t)$ ile çarpılmış durumdadır. Bu yüzden $t = 0^-$ anına kadar akım kaynağı sıfırdır. Sıfır değerli bir akım kaynağı açık devre gibi davrandığı için çizilmese de olur. Devre $-\infty$'dan $0^-$'a kadar yalnız $5$ V kaynağıyla sürülmüştür.

DC şartlarda kapasite açık devre, endüktans kısa devre gibi çalışır. Kapasite açık devre olduğu için endüktansın bulunduğu koldan akım geçemez:

$$i_L(0^-) = 0\ \text{A}$$

Endüktans akımı süreklilik gösterdiği için $i_L(0^+) = 0$ A olur. Kaynak, direnç ve kapasite kolu birbirine paraleldir. Endüktansta gerilim düşümü olmadığından:

$$V_C(0^-) = 5\ \text{V}$$

Birinci sorunun a şıkkının cevabı $0$ A'dır. Burada cevabın net bir sayı olarak yazılması gerekir. Sonuçta $u(t)$ içeren bir ifade bırakılmamalıdır.

Hoca $5$ V kaynağını bilerek anahtarla çizdiğini anlattı. Kaynağı $5[1 - u(t)]$ biçiminde yazmış olsaydı, $t > 0$ için o kol kısa devre gibi ele alınmak zorunda kalacaktı. Anahtar açıldığında ise kaynak devreden tamamen çıkar.

### 2.3 $t > 0$ Devresi ve Diferansiyel Denklem

$t > 0$ için anahtar açıktır, geriye $i_s$, $C$ ve seri $L$-$R$ kolu kalır. Denklemler sırayla şöyle kurulur:

$i_s$ akım kaynağından gelen akım iki kola ayrılır:

$$i_s = i_L + i_C$$

$L$ ve $R$ aynı koldadır, akımları eşittir. Kapasitenin tanım bağıntısı:

$$i_C = C\frac{dV_C}{dt}$$

Hedef, bu terimi $i_L$ cinsinden yazmaktır. Kapasite kolu ile $L$-$R$ kolu paralel olduğu için:

$$V_C = V_L + V_R = L\frac{di_L}{dt} + Ri_L$$

Bu ifadenin türevi alınıp $C$ ile çarpılırsa $i_C$ bulunur:

$$i_C = C\left(L\frac{d^2 i_L}{dt^2} + R\frac{di_L}{dt}\right)$$

Bu, $i_s = i_L + i_C$ denkleminde yerine konup her taraf $LC$'ye bölünürse:

$$\frac{d^2 i_L}{dt^2} + \frac{R}{L}\frac{di_L}{dt} + \frac{1}{LC}i_L = \frac{i_s}{LC}$$

Sayısal olarak $\frac{R}{L} = 4$ ve $\frac{1}{LC} = 4$ olur (ara adım eklendi):

$$\frac{d^2 i_L}{dt^2} + 4\frac{di_L}{dt} + 4i_L = 4i_s$$

### 2.4 İkinci Başlangıç Koşulu

Sorunun "trik" kısmı buydu. $V_C = L\frac{di_L}{dt} + Ri_L$ denklemi $t = 0$ anında yazılırsa türev doğrudan çıkar:

$$\frac{di_L}{dt}(0) = \frac{V_C(0) - Ri_L(0)}{L} = \frac{5 - 0}{10} = 0.5\ \text{A/s}$$

$V_C$ de $i_L$ de sıfır anında bilindiği için tek bilinmeyen türevdir.

> **Hocanın vurgusu:** $i_L$'nin türevinin sıfırdaki değerini bulmaya ilişkin bu çözümleme çoğu çözümde yapılamamış. Bu değer bulunmadan ikinci katsayı bulunamaz.

### 2.5 Soru 1b: $i_s = 10$ A

Diferansiyel denklemin çözümü doğal ve zorlanmış çözümün toplamıdır. Doğal çözüm için, kendisiyle doğrusal ilişkisi olan fonksiyon önerilir: $Ae^{\alpha t}$. Sağ taraf sıfıra eşitlenip öneri yerine konduğunda $A = 0$ önemsiz (trivial) çözümdür, $i_L = 0$ demektir. Aranan çözüm bu olmadığı için parantezdeki polinom sıfır olmalıdır:

$$s^2 + 4s + 4 = 0 \quad \Rightarrow \quad s_{1,2} = -2$$

Katlı kök vardır. Katlı kökte önerilecek iki terim $A_1e^{-2t}$ ve $A_2te^{-2t}$'dir:

$$i_{L,h}(t) = A_1e^{-2t} + A_2te^{-2t}$$

<!-- BELİRSİZ: Hoca iki terimin ilişkisini anlatırken "lineer bağımsız, pardon lineer bağımlı olarak yazılabilen" diyor; cümle altyazıda karışık. Aşağıdaki Ders sonrası not bu yere ait. -->

> **Ders sonrası not:** Hoca $e^{\alpha t}$ ile $te^{\alpha t}$ için önce "lineer bağımsız" deyip "lineer bağımlı olarak yazılabilen" diye düzeltti. Katlı kökte iki terimin birlikte kullanılabilmesinin sebebi birbirlerinden doğrusal bağımsız olmalarıdır: Wronskian değerleri $e^{-4t}$ çıkar ve hiçbir $t$ için sıfır olmaz (python ile hesaplandı).

Zorlanmış çözüm için sağ taraf sabit olduğundan bir $B$ sabiti önerilir. Sabitin birinci ve ikinci türevi sıfırdır, geriye $\frac{B}{LC} = \frac{i_s}{LC}$ kalır ve $B = 10$ bulunur. Genel çözüm:

$$i_L(t) = 10 + A_1e^{-2t} + A_2te^{-2t}$$

İki katsayı, iki başlangıç koşulundan bulunur. $t = 0$ konunca:

$$A_1 + 10 = 0 \quad \Rightarrow \quad A_1 = -10$$

Çözümün türevi alınıp $t = 0$ konur ve $0.5$'e eşitlenir (ara adım eklendi):

$$-2A_1 + A_2 = 0.5 \quad \Rightarrow \quad A_2 = 0.5 - 20 = -19.5$$

Sonuç:

$$i_L(t) = 10 - 10e^{-2t} - 19.5te^{-2t}\ \text{A}, \quad t \geq 0$$

Bu çözümün diferansiyel denklemi ve iki başlangıç koşulunu sağladığı python ile hesaplandı.

### 2.6 Soru 2: $i_s = e^{-3t}$ A

**a şıkkı.** $t \to \infty$ için kapasite açık devre, endüktans kısa devre gibi düşünülür, anahtarlı kol devreden çıkmıştır. Tek kaynak $i_s$'dir ve $e^{-3t}$ sıfıra gittiği için:

$$i_L(\infty) = 0$$

**b şıkkı.** $t = 0^-$ için bulunanlar burada da geçerlidir: $i_L(0) = 0$, $V_C(0) = 5$ V, $\frac{di_L}{dt}(0) = 0.5$ A/s. Diferansiyel denklem de aynıdır, yalnız $i_s$ yerine $e^{-3t}$ yazılır. Homojen çözümde bir fark yoktur.

> **Ders sonrası not:** Hoca bu kısmı özetlerken "$V_C$ $0.5$" dedi. Doğrusu $V_C(0) = 5$ V'tur, $0.5$ ise $\frac{di_L}{dt}(0)$ değeridir.

Zorlanmış çözüm için $Be^{-3t}$ önerilir. Denkleme konunca (ara adım eklendi):

$$B(9 - 12 + 4)e^{-3t} = 4e^{-3t} \quad \Rightarrow \quad B = 4$$

Genel çözüm:

$$i_L(t) = 4e^{-3t} + A_1e^{-2t} + A_2te^{-2t}$$

$t = 0$ konunca $4 + A_1 = 0$, yani $A_1 = -4$. Türev alınıp $t = 0$ konur ve $0.5$'e eşitlenir (ara adım eklendi):

$$-12 - 2A_1 + A_2 = 0.5 \quad \Rightarrow \quad -12 + 8 + A_2 = 0.5 \quad \Rightarrow \quad A_2 = 4.5$$

Sonuç:

$$i_L(t) = -4e^{-2t} + 4.5te^{-2t} + 4e^{-3t}\ \text{A}, \quad t \geq 0$$

Bu çözümün de denklemi ve başlangıç koşullarını sağladığı python ile hesaplandı.

### 2.7 Sık Yapılan Hatalar

Hocanın kâğıtlarda gördüğü genel tablo şuydu: Homojen çözüm ve katlı kök tarafı çoğunlukla bulunmuş, DC kaynak için zorlanmış çözüm de bulunmuş. Hatalar iki noktada toplanmış:

- **Zorlanmış çözümü katsayısız yazmak:** Üstel kaynak için öneri $e^{-3t}$ olarak yapılıp geçilmiş. Sabit kaynak bağlıyken nasıl doğrudan "10" diye değil de "bir sabit" diye öneri yapılıyorsa, burada da önerinin $Be^{-3t}$ gibi belirli bir katsayıyla, doğrusal birleşim olarak yazılması gerekir. Bu hata $A_2$'yi de bozar.
- **$\frac{di_L}{dt}(0)$ değerini bulmamak:** İkinci uç koşulun neye eşit olduğu çıkarılamamış.

> **Hocanın vurgusu:** En fazla hata zorlanmış çözüm önerisinde yapıldı. Önerilen çözüm, üstel terimin belirli bir katsayıyla çarpılmış hâli olmalıdır.

**Soru:** Bunu derste incelediğimiz üç durumla ($\alpha$ ve $\omega$ karşılaştırması) çözemez miyiz?

**Cevap:** Evet, aynı hesaba gelir. $\alpha$ ve $\omega$ hesaplanıp büyük, küçük ve eşitlik durumlarına göre incelendiğinde kritik sönümlü (critically damped), aşırı sönümlü (overdamped) ve az sönümlü (underdamped) durumlar zaten ortaya çıkar. Çözüm önerisi ona göre yapılır. Bu yaklaşımla yapılan çözümler de geçerlidir. Bu soruda $\alpha = \frac{R}{2L} = 2$ ve $\omega_0 = \frac{1}{\sqrt{LC}} = 2$ olduğundan durum kritik sönümlüdür ve katlı kökle aynı sonuca gelinir (ara adım eklendi).

## 3. Sürekli Sinüzoidal Hâl ve Fazör Uzayı Tekrarı

Hoca konuya geçmeden sürekli sinüzoidal hâli (SSH) kısaca hatırlattı. Devrede sinüzoidal bir kaynak vardır. Kaynağın devreye bağlandığı andaki anlık titreşim ve değişimlerle ilgilenmeyiz. Yeterince uzun süre bekledikten, geçici rejimler tamamlandıktan sonraki devre karakteristiğine bakarız. Geçici rejim bittiği için homojen çözümden gelen katkı kaybolur ve devre yalnız sinüzoidal kaynakla sürülüyormuş gibi olur.

> **Hocanın vurgusu:** Devrede sinüzoidal bir kaynak varsa bütün R, L ve C elemanlarının akım ve gerilimleri kaynak frekansıyla, yani aynı frekansta salınım yapar. Bu önemli bir noktadır.

Bu yüzden frekans bilgisi fazladan bir bilgidir, kenara not edilir. Kosinüs biçiminde yazılan bir büyüklük fazör uzayına geçirilir. Zaman domenindeki doğrusal denklemler doğrusal kalır, diferansiyel denklemler ise fazör uzayında doğrusal denklemlere dönüşür. Bütün eleman tanım bağıntıları ve kaynak tanımları fazör uzayına geçirilirse devre sanki bir direnç devresi hâline gelir. Bu durumda direnç devresinde yapılan her şey burada da yapılabilir: eşdeğer direnç (burada empedans) hesabı, Norton ve Thevenin teoremleri, kaynak dönüşümü, maksimum güç hesabı.

Tek fark bütün değerlerin karmaşık sayı olmasıdır. Çözüm bitince zaman domenine dönülür. Fazör uzayından bir genlik ve bir faz açısı gelir, başta not edilen kaynak frekansı kullanılarak zaman domenindeki karşılık yazılır:

$$A\cos(\omega t + \phi)$$

## 4. Fazör Uzayında Thevenin-Norton Eşdeğeri

Tıpkı direnç devrelerinde olduğu gibi, fazör uzayında da karmaşık bir devrenin bir yük üzerindeki etkisi basitleştirilebilir. Karmaşık devrenin yerine ya bir gerilim kaynağı ve ona seri bir empedans (Thevenin) ya da bir akım kaynağı ve ona paralel bir empedans (Norton) konabilir.

Eşdeğerliğin tanımı şudur: İki devrenin çıkış terminallerine aynı yük empedansı bağlandığında, yük üzerinde oluşan gerilim ve akım **bütün yük empedansları için** aynıysa bu iki devre eşdeğerdir.

Thevenin ve Norton büyüklükleri arasındaki ilişki bu tanımdan çıkar:

- **Açık devre:** Yük empedansı sonsuz yapılırsa akım akmaz. Thevenin devresinde uçlarda $\mathbf{V}_{TH}$ görülür. Norton devresinde akımın tamamı paralel empedanstan geçer ve uçlarda $\mathbf{I}_N Z_N$ görülür. Demek ki $\mathbf{V}_{TH} = \mathbf{I}_N Z_N$.
- **Kaynağı sıfırlama:** Thevenin devresinde kaynak sıfırlanınca kısa devre olur ve içeri bakınca $Z_{TH}$ görülür. Norton devresinde kaynak sıfırlanınca açık devre olur ve içeri bakınca $Z_N$ görülür. Görülen empedansların eşit olması gerektiğinden $Z_N = Z_{TH}$.

Bu, direnç devrelerinde yapılan analizin fazör uzayındaki aynısıdır.

## 5. Merdiven Devre: Ardışık Kaynak Dönüşümü

### 5.1 Devre ve Çözüm Planı

Devre, kısa nottaki numarasıyla Örnek 05, şöyledir: $i_1 = 5\sin(400t + 50^\circ)$ mA akım kaynağı ve ona paralel $C_1 = 1\ \mu$F. Seri $R_1 = 3$ k$\Omega$. Şönt $L_1 = 0.3$ H. Seri $L_2 = 2$ H. Şönt $R_2 = 5$ k$\Omega$. Yük olarak şönt $C_2 = 0.7\ \mu$F. Çıkış terminallerinin solunda kalan devrenin eşdeğeri aranıyor, yük ise $C_2$'dir ve üzerinden geçen akım isteniyor.

> **Ders sonrası not:** Hoca yük kapasitesi için "en solda yer alan" dedi. Aynı cümlenin devamında eşdeğeri aranan devrenin "sol tarafta kalan devre" olduğunu söylediği için yük en sağdaki $C_2$'dir.

Hoca iki çözüm yolu olduğunu söyledi: kaynak dönüşümü ve doğrudan Norton-Thevenin yaklaşımı. İkisi aslında aynı şeye karşılık gelir. Kaynak dönüşümü planı, devreyi sanki direnç devresiymiş gibi düşünerek şu adımlardan oluşur:

1. Akım kaynağı ve paralel $C_1$, gerilim kaynağı ve seri empedansa çevrilir.
2. Bu empedans $R_1$ ile seri toplanır.
3. Tekrar Norton'a dönülür, paralel gelen $L_1$ ile eşdeğer alınır.
4. Tekrar Thevenin'e dönülür, seri gelen $L_2$ ile toplanır.
5. Tekrar Norton'a dönülür, paralel gelen $R_2$ ile eşdeğer alınır.
6. Yük $C_2$ ile birlikte tek bir akım kaynağı ve iki paralel eleman kalır, akım bölücü uygulanır.

### 5.2 Kaynağın Fazörü

Önce açısal frekans not edilir: $\omega = 400$ rad/s. Kaynak sinüs olarak verilmiştir, önce kosinüse çevrilmelidir. Dik üçgen bağıntısından $\sin\alpha = \cos(90^\circ - \alpha)$ yazılır. Kosinüs eksi açıda aynı değeri verdiği için bu aynı zamanda $\cos(\alpha - 90^\circ)$'ye eşittir. Yani sinüsü kosinüse çevirmek için fazdan $90^\circ$ çıkarmak yeterlidir:

$$5\sin(400t + 50^\circ) = 5\cos(400t - 40^\circ)\ \text{mA}$$

Euler formülünden bu ifade şu karmaşık terimin gerçel kısmıdır:

$$\text{Re}\left\{5\times 10^{-3}\, e^{j400t}\, e^{-j40^\circ}\right\}$$

$e^{j400t}$ terimi akılda tutulur, genlik ve faz açısı üzerinden ilerlenir:

$$\mathbf{I}_1 = 5\angle{-40^\circ}\ \text{mA}$$

Hoca kosinüs ile gerçel kısmı birlikte kullanma üzerinde anlaştıklarını hatırlattı. Sinüsün fazör karşılığı doğrudan hesaplanmak istenirse sinüs ile sanal kısım birlikte kullanılmalıdır.

### 5.3 Empedanslar

Eleman empedansları $Z_R = R$, $Z_L = j\omega L$, $Z_C = \frac{1}{j\omega C}$ bağıntılarıyla bulunur. Kapasite için $\frac{10^6}{j400} = \frac{2500}{j}$ yazılır, pay ve payda $j$ ile çarpılınca $-j2500$ çıkar.

| Eleman | Kartezyen | Polar |
|---|---|---|
| $C_1 = 1\ \mu$F | $-j2500\ \Omega$ | $2500\angle{-90^\circ}$ |
| $R_1 = 3$ k$\Omega$ | $3000\ \Omega$ | $3000\angle 0^\circ$ |
| $L_1 = 0.3$ H | $j120\ \Omega$ | $120\angle 90^\circ$ |
| $L_2 = 2$ H | $j800\ \Omega$ | $800\angle 90^\circ$ |
| $R_2 = 5$ k$\Omega$ | $5000\ \Omega$ | $5000\angle 0^\circ$ |
| $C_2 = 0.7\ \mu$F | $-j3571\ \Omega$ | $3571\angle{-90^\circ}$ |

Bazı işlemler toplama, bazıları çarpma olacağı için iki gösterim de not edilir. Polar gösterimi karmaşık düzlemden okumak kolaydır: $-j2500$ noktası düşey eksenin altındadır, uzaklığı $2500$, açısı $-90^\circ$'dir.

### 5.4 Adım Adım Çözüm

**Adım 1: Thevenin'e dönüş.** $\mathbf{I}_1$ ile $Z_{C_1}$ çarpılır. Çarpmada genlikler çarpılır, açılar toplanır. Bunun sebebi açıların üstel terimlerin kuvvetinde olmasıdır: $e^{-j40^\circ}\cdot e^{-j90^\circ} = e^{-j130^\circ}$. Mili ve kilo birbirini götürür:

$$\mathbf{V}_{TH1} = (5\times 10^{-3}\angle{-40^\circ})(2500\angle{-90^\circ}) = 12.5\angle{-130^\circ}\ \text{V}$$

Slaytta bu değer $7.5$ yazılıydı. Hoca derste bunu $12.5$ olarak düzeltti ve hatalı olduğunu bilerek ilerlediklerini söyledi. Seri empedans yine $Z_{C_1} = 2500\angle{-90^\circ}\ \Omega$'dur.

**Adım 2: Seri toplama.** Toplamada kartezyen biçim kullanılır, sonra polar biçime dönülür:

$$Z_{C_1} + Z_{R_1} = 3000 - j2500\ \Omega$$

Genlik için gerçel ve sanal kısmın kareleri toplanıp kökü alınır, açı için $\tan^{-1}\frac{-2500}{3000}$ hesaplanır. Sayı dördüncü bölgede olduğundan açı negatiftir:

$$3000 - j2500 = 3905\angle{-39.8^\circ}\ \Omega$$

**Soru:** Bu açıyı arktanjant bulmak yerine, fazör gösterimindeki açıların farkını alarak bulabilir miyiz?

**Cevap:** Hayır. $e^{-j90^\circ}$ ile $e^{j40^\circ}$ gibi iki üstel terim toplanamaz. Toplama işlemine girilecekse mutlaka kartezyen biçimde ilerlemek gerekir. Polara dönerken de $\frac{y}{x}$'in arktanjantı alınır. $Z_{R_1}$ ve $Z_{C_1}$'in kendi açılarından bu sonuç elde edilemez.

> **Hocanın vurgusu:** Toplama varsa mutlaka ve mutlaka kartezyen biçim kullanılır. Çarpma ve bölmede ise polar biçim pratiktir.

**Adım 3: Norton'a dönüş ve $L_1$ ile paralel birleştirme.** Thevenin gerilimi empedansa bölünür. Bölmede genlikler bölünür, açılar çıkarılır:

$$\mathbf{I}_{N1} = \frac{12.5\angle{-130^\circ}}{3905\angle{-39.8^\circ}} = 3.20\angle{-90.2^\circ}\ \text{mA}$$

Norton empedansı Thevenin empedansına eşittir. Bu empedans ile $Z_{L_1}$ paraleldir. Slayt burada iletkenlikleri topluyor: $\frac{1}{Z_{N1}} + \frac{1}{Z_{L_1}} = \frac{1}{Z_{eq}}$. Hoca, bunun hem iletkenliğin hem empedansın kullanımını göstermek için seçildiğini söyledi. Kendisi doğrudan $\frac{Z_1Z_2}{Z_1 + Z_2}$ ile ilerlemeyi tercih ediyor. İkisi aynı işlemdir, öğrenciler de böyle çözebilir. Python ile hesaplanan değerler:

$$Y_{eq2} = 8.172\times 10^{-3}\angle{-88.6^\circ}\ \text{S}, \quad Z_{eq2} = 122.4\angle 88.6^\circ\ \Omega$$

**Adım 4: Thevenin'e dönüş ve $L_2$ ile seri toplama.** İletkenlik empedansın tersi olduğu için $\mathbf{I}_N Z$ yerine $\mathbf{I}_N / Y$ yazılabilir:

$$\mathbf{V}_{TH2} = \frac{\mathbf{I}_{N1}}{Y_{eq2}} = 0.392\angle{-1.6^\circ}\ \text{V}$$

Empedans iletkenlikten geri bulunur, $Z_{L_2}$ ile kartezyen biçimde toplanır, polar biçimi yanda tutulur:

$$Z_{eq3} = (2.95 + j122.3) + j800 = 2.95 + j922.3 = 922.3\angle 89.8^\circ\ \Omega$$

**Adım 5: Norton'a dönüş ve $R_2$ ile paralel birleştirme.**

$$\mathbf{I}_{n2} = \frac{\mathbf{V}_{TH2}}{Z_{eq3}} = 0.425\angle{-91.4^\circ}\ \text{mA}$$

Norton empedansı $Z_{eq3}$ ile $R_2$ paraleldir. İletkenlikler toplanıp tersi alınır. Hoca, matematiksel olarak ters alınınca açının işaret değiştirdiğine dikkat çekti: $\frac{1}{Y}$ alındığında negatif açı pozitife döner, genlik de $\frac{1}{1.1\times 10^{-3}}$'ten gelir:

$$Y_{eq4} = 1.103\times 10^{-3}\angle{-79.4^\circ}\ \text{S}, \quad Z_{eq4} = 906.5\angle 79.4^\circ\ \Omega$$

Böylece $C_2$ yükü için Norton eşdeğeri elde edilmiş olur: $\mathbf{I}_{n2}$ ve paralel $Z_{eq4}$.

**Adım 6: Akım bölücü.** Geriye iki paralel eleman kaldı, bunlar akım bölücü gibi çalışır. Akım kaynağı, akımı ters koldaki empedansla orantılı olarak bir kola verir:

$$\mathbf{I}_{C_2} = \mathbf{I}_{n2}\frac{Z_{eq4}}{Z_{eq4} + Z_{C_2}}$$

Gerilim için akım ile empedans çarpılır, iki elemanın gerilimi zaten eşittir: $\mathbf{V}_{C_2} = \mathbf{I}_{C_2}Z_{C_2}$. Yani özgün devrede $C_2$ üzerinde bu akım ve bu gerilim oluşur.

### 5.5 Sonuç

Slaytta sonuç şu değerde kalmıştı:

$$i_{C_2}(t) = 86\times 10^{-6}\cos(400t + 74.3^\circ)\ \text{A}$$

> **Ders sonrası not:** Hoca, Thevenin yolundaki $Z_{TH}$ slayttaki değerle aynı çıkınca "arada bir yerde $7.5$'i $12.5$ olarak düzelttiğini düşünebiliriz" dedi. $Z_{TH}$ kaynak değerine bağlı değildir, bu yüzden bu karşılaştırma slaytın düzeltildiğini göstermez. Doğrusu: $12.5$ V ile python ile hesaplanan $\mathbf{I}_{n2} = 0.4247\angle{-91.4^\circ}$ mA ve $\mathbf{I}_{C_2} = 143.3\angle 74.4^\circ\ \mu$A'dır. Bu değerlerin $0.6$ katı, yani $7.5/12.5$ oranı, $0.255$ mA ve $86.0\ \mu$A eder. Bu sayılar slayttaki sayılarla aynıdır, slayt $7.5$ ile devam etmiştir. Doğru sonuç $i_{C_2}(t) = 143.3\cos(400t + 74.4^\circ)\ \mu$A, $\mathbf{V}_{C_2} = 0.512\angle{-15.6^\circ}$ V'tur. Aynı akım devrenin doğrudan düğüm denklemleriyle de python ile hesaplandı ve aynı çıktı.

### 5.6 Aynı Devrenin Thevenin Yoluyla Çözümü

Hoca aynı mantığın doğrudan Thevenin-Norton teoremleriyle de kurulabileceğini gösterdi. Karmaşık devre terminallerden içeri bakılarak ele alınır, direnç devresinde $R_{TH}$ ve $V_{TH}$ hesabı yapar gibi düşünülür.

**Eşdeğer empedans.** Kaynak sıfırlanır. Akım kaynağını sıfırlamak onu açık devre yapmak demektir. Terminallerden bakılınca $Z_{C_1}$ ile $Z_{R_1}$ seri, bunlara $Z_{L_1}$ paralel, çıkan sonuca $Z_{L_2}$ seri, onun sonucuna da $Z_{R_2}$ paraleldir:

$$Z_{TH} = \Big(\big[(Z_{C_1} + Z_{R_1}) \parallel Z_{L_1}\big] + Z_{L_2}\Big) \parallel Z_{R_2}$$

Hoca bu ifadeyi MATLAB'da (Octave da olabilir) hesapladı, sonucun radyandan dereceye çevrilince kaynak dönüşümündekiyle aynı olduğunu gösterdi. Python ile hesaplanan değer:

$$Z_{TH} = 167.2 + j891.0 = 906.5\angle 79.4^\circ\ \Omega$$

**Thevenin gerilimi.** Yük çıkarılır, açık devre yapılır, açık terminallerdeki gerilime bakılır. Bu gerilim $\mathbf{V}_{TH}$'dir. Hoca bu hesabı derste sayısal olarak yapmadı. Kaynak dönüşümünden gelen değerlerle $\mathbf{V}_{TH} = \mathbf{I}_{n2}Z_{eq4} = 0.385\angle{-12.0^\circ}$ V olur (ara adım eklendi, python ile hesaplandı).

### 5.7 Hangi Yöntem Pratik?

Hocaya göre pratiklik devrenin şekline bağlıdır. Bu devre, ardışık kaynak dönüşümünde pratik yapmak için özellikle merdiven şeklinde verilmiştir. Paralel veya seri bir devrede doğrudan Norton-Thevenin hızlı olabilir. Direnç devrelerindeki gibi sonuçlar karmaşık da çıkabilir, öğretici olan bu yöntemleri kullanabilmektir. "Verilen devre için Thevenin eşdeğer gerilimini bulun" gibi bir soruyla karşılaşılırsa konu gereği Thevenin kullanmak zorunlu olur.

## 6. Rezonanstaki LC Devresinin Norton Eşdeğeri

### 6.1 Soru

Aradan sonra yeni bir örneğe geçildi. Devre şöyledir: $v_1 = 1\sin(1000t)$ V kaynağı, seri $L_1 = 0.1$ H, uçlara paralel $C_1 = 10\ \mu$F ve yük direnci $R_1 = 1$ k$\Omega$. $R_1$'e paralel terminalden bakıldığında, solda kalan kaynak, endüktans ve kapasiteden oluşan devrenin Norton eşdeğeri isteniyor. Slayttaki iddia, bu eşdeğerin $R_1$'e bağlı tek bir $10\sin(1000t)$ mA akım kaynağı olduğudur. Ayrıca doğal frekans $\omega_0$ isteniyor. Hoca sınıfa cevabın belli olduğunu, önemli olanın oraya nasıl ulaşılacağını göstermek olduğunu söyledi.

### 6.2 Fazörler

Kaynak sinüs biçiminde verilmiştir. $\sin(1000t) = \cos(90^\circ - 1000t) = \cos(1000t - 90^\circ)$ yazılır. İkinci biçim açısal frekansı pozitif tutmak için seçilir. Buna göre:

$$\mathbf{V}_1 = 1\angle{-90^\circ}\ \text{V}, \quad \omega = 1000\ \text{rad/s}$$

Eleman empedansları:

$$Z_{L_1} = j(1000)(0.1) = j100\ \Omega = 100\angle 90^\circ\ \Omega$$

$$Z_{C_1} = \frac{1}{j(1000)(10\times 10^{-6})} = \frac{100}{j} = -j100\ \Omega = 100\angle{-90^\circ}\ \Omega$$

### 6.3 Norton Empedansı

Terminallerden bakılır ve kaynak sıfırlanır. Gerilim kaynağı sıfırlanınca kısa devre olur, $L_1$ ile $C_1$ birbirine paralel kalır:

$$\frac{1}{Z_N} = \frac{1}{j100} + \frac{1}{-j100} = 0 \quad \Rightarrow \quad Z_N = \infty$$

$Z_N$ sonsuz demek açık devre demektir. Hedeflenen eşdeğer bir akım kaynağı ve ona paralel $Z_N$ idi, demek ki $Z_N$ elemanı çıkarılabilir. Hoca bir yanılgıya da dikkat çekti: İlk bakışta bu iki eleman seri gibi görünüp toplamları sıfır çıkacak izlenimi verebilir. Oysa terminallerden bakıldığında paraleldirler, hesap paralellik üzerinden yapılır.

### 6.4 Açık Devre Gerilimi Denemesi

Hoca önce yük direncini çıkarıp açık uçlardaki $\mathbf{V}_{OC}$ gerilimine bakmayı denedi. $L_1$ ve $C_1$'i gerilim bölücü gibi düşününce $j100 + (-j100) = 0$ çıktı ve hesap burada tıkandı. Empedansların doğruluğu tekrar kontrol edildi, hata yoktu.

> **Ders sonrası not:** Bu tıkanma hesap hatasından gelmiyor. Açık uçlarda $L_1$ ve $C_1$ seridir ve toplam empedansları python ile hesaplandığında tam $0$ çıkar. Bu frekansta $\mathbf{V}_{OC}$ sonlu bir değer olarak tanımlanamaz. $\mathbf{V}_{TH} = \mathbf{I}_N Z_N$ bağıntısında da $Z_N$ sonsuzdur. Bu yüzden bu devrenin Thevenin biçimi yazılamaz, yalnız Norton biçimi yazılır.

### 6.5 Norton Akımı

Hoca bu kez kaynak dönüşümüne geçti. Gerilim kaynağı ve seri $Z_{L_1}$, akım kaynağı ve paralel $Z_{L_1}$ olur. Akım, gerilimin empedansa bölümüdür:

$$\mathbf{I}_N = \frac{1\angle{-90^\circ}}{100\angle 90^\circ} = 0.01\angle{-180^\circ}\ \text{A}$$

Şimdi $Z_{L_1}$ ile $Z_{C_1}$ paraleldir ve eşdeğerleri açık devredir, ikisi de elenir. Geriye tek bir akım kaynağı kalır. Zaman domenine dönülünce:

$$i_N(t) = 0.01\cos(1000t - 180^\circ)\ \text{A} = 10\cos(1000t - 180^\circ)\ \text{mA}$$

Doğal frekans ise (kısa nottan; altyazıda sayısal olarak söylenmiyor):

$$\omega_0 = \frac{1}{\sqrt{L_1C_1}} = 1000\ \text{rad/s}$$

Kaynak frekansı tam bu değerde olduğu için $Z_N$ sonsuz çıkmıştır.

### 6.6 Slaytla Eşleştirme Çabası

Hoca bu sonucu slayttaki sinüslü ifadeyle eşleştirmeye çalıştı. Önce trigonometrik düzenleme yaptı. $\cos(\alpha - 180^\circ)$ açılımı ile:

$$\cos(1000t - 180^\circ) = \cos(1000t)\cos 180^\circ + \sin(1000t)\sin 180^\circ = -\cos(1000t)$$

Yani sonuç $-10\cos(1000t)$ mA'dır. Kartezyen düzlemde de $0.01\angle{-180^\circ}$ noktası $-0.01$'e karşılık gelir, bu doğrudur. Sinüse çevirmeyi de denedi, $-10\sin(1000t + 90^\circ)$ gibi bir sonuca ulaştı. Hesabı defalarca kontrol etti, bulduğu sonuç slayttakiyle eşleşmedi, aradaki $180^\circ$'nin fazla göründüğünü söyledi. Sonunda doğru hâlini kontrol edip paylaşacağını belirtti.

**Soru:** $\cos\alpha = \sin(\alpha + 180^\circ)$ diyebilir miyiz? (Derste yorum olarak geldi.)

**Cevap:** Hoca açılımı yazdı: $\sin(\alpha + 180^\circ) = \sin\alpha\cos 180^\circ + \cos\alpha\sin 180^\circ = -\sin\alpha$. Doğrudan $180^\circ$ eklemek sinüse dönüştürmüyor.

> **Ders sonrası not:** Hocanın bulduğu $\mathbf{I}_N = 0.01\angle{-180^\circ}$ A doğrudur. $\cos\alpha = \sin(\alpha + 90^\circ)$ eşitliğinden $-\cos(1000t) = \sin(1000t - 90^\circ)$ olur, bunlar python ile hesaplandı. Yani $i_N(t) = 10\cos(1000t - 180^\circ) = -10\cos(1000t) = 10\sin(1000t - 90^\circ)$ mA'dır. Slayttaki $10\sin(1000t)$ mA ile fark $90^\circ$'dir, bu fark akım yönünü ters almakla da kapanmaz. Hoca "$180^\circ$ fazla" dedi, ama sinüsle kosinüs arasında gereken fark $90^\circ$'dir. Kaynak $1\cos(1000t)$ V olsaydı $\mathbf{I}_N = 0.01\angle{-90^\circ}$ A, yani tam $10\sin(1000t)$ mA çıkardı (python ile hesaplandı). Slayttaki ifade büyük olasılıkla bu kaynağa göre yazılmıştır.

### 6.7 Yük Bağlıyken Doğrudan Çözüm

Hoca, kaynak dönüşümü yapmadan da ilerlenebileceğini söyledi: $L_1$-$C_1$ birleşiminin kaynak üzerindeki etkisine bakmak, yük empedansı da devredeyken doğrudan onun üzerindeki akım ve gerilimi hesaplamak. Ayrıca pratikte bu elemanların dirençle seri veya paralel bağlı olmadığı bir devrenin mümkün olmadığını belirtti. Bu devre teorik bir örnektir.

Bu yolla $R_1$ akımı python ile hesaplandı: $10\angle{-180^\circ}$ mA çıkar. Yükü farklı bir değere değiştirmek bu akımı değiştirmez. Bu da tek akım kaynağından oluşan eşdeğerle uyumludur.

## 7. Gerilim Bölücü ve Akım Bölücü

### 7.1 Gerilim Bölücü

Direnç devrelerinde gerilim bölme, birbirine seri dirençlerle oluyordu. Fazör uzayında da seri elemanlardan empedansı yüksek olan, o oranda daha fazla gerilimi üzerine alır. Seri $Z_1$ ve $Z_2$ için eşdeğer empedans $Z_1 + Z_2$'dir:

$$\mathbf{V}_1 = \frac{\mathbf{V}_s}{Z_1 + Z_2}Z_1, \quad \mathbf{V}_2 = \frac{\mathbf{V}_s}{Z_1 + Z_2}Z_2, \quad \frac{\mathbf{V}_1}{\mathbf{V}_2} = \frac{Z_1}{Z_2}$$

Empedans ne kadar yüksekse elemanın gerilim düşümü de o kadar fazladır.

### 7.2 Akım Bölücü

Paralel elemanlarda aynı mantık akım için geçerlidir, burada iki farklı ifade kullanılabilir:

- **İki paralel eleman:** Bir elemandaki akım, karşı koldaki elemanın empedansıyla orantılıdır.

$$\mathbf{I}_1 = \mathbf{I}_s\frac{Z_2}{Z_1 + Z_2}$$

- **İkiden fazla paralel eleman:** İfade değişir. Bir elemandaki akım, kendi empedansıyla ters orantılıdır.

Üç eleman için Kirchhoff'un akımlar kanunu kullanılır. Kaynak akımı üç kola paylaştırılır, hepsi paralel olduğu için üzerlerinde aynı gerilim $\mathbf{V}_s$ vardır. Buradan (son biçim kısa nottan):

$$\mathbf{I}_s = \frac{\mathbf{V}_s}{Z_1} + \frac{\mathbf{V}_s}{Z_2} + \frac{\mathbf{V}_s}{Z_3} \quad \Rightarrow \quad \mathbf{I}_k = \mathbf{I}_s\frac{1/Z_k}{\sum_i 1/Z_i} = \mathbf{I}_s\frac{Y_k}{Y_{\text{eş}}}$$

Direnç devresindeki "karşı kol" biçimine dönmek istenirse iki elemana indirgenir. Örneğin $Z_2$ ile $Z_3$'ün paralel eşdeğeri $Z_{\text{eş}}$ bulunur, geriye $Z_1$ ve $Z_{\text{eş}}$ kalır:

$$\mathbf{I}_1 = \mathbf{I}_s\frac{Z_{\text{eş}}}{Z_1 + Z_{\text{eş}}}$$

Hoca, bunlar direnç devresindeki durumun aynısı olduğu için ayrıntıya girmedi.

## 8. Örnek 53: Bağımlı Gerilim Kaynaklı Devre

### 8.1 Devre

Devre şöyledir: $v_s = 20\cos(250t)$ V kaynağından seri $8\ \Omega$ ve $36$ mH ile $a$ düğümüne gidiliyor. $a$ düğümü ile toprak arasında $0.25$ mF kapasite ve düğüme giren $1.2\cos(250t + 45^\circ)$ A akım kaynağı var. $a$ düğümünden $80$ mH üzerinden, artı ucu üstte olan $4v_a$ bağımlı gerilim kaynağına gidiliyor. İstenen $v_a(t)$ gerilimidir. $v_a$ aynı zamanda bağımlı kaynağı da belirlemektedir.

### 8.2 Süperpozisyon mu, Toplu Çözüm mü?

Hoca önce hangi teoremden yararlanılacağını sordu. İki bağımsız sinüzoidal kaynak olduğu için akla süperpozisyon gelebilir. Fakat iki kaynağın da frekansı $250$ rad/s olduğu için devredeki bütün elemanlar aynı frekansta salınır ve hepsi için toplu çözüm yapma imkânı vardır. Frekanslar farklı olsaydı akla gelen ilk senaryo doğrudan süperpozisyonla çözmek olacaktı.

### 8.3 Fazörler

Bütün kaynaklar kosinüs olarak verilmiştir ve $\omega = 250$ rad/s:

$$\mathbf{V}_s = 20\angle 0^\circ\ \text{V}, \quad \mathbf{I}_s = 1.2\angle 45^\circ\ \text{A}$$

Empedanslar:

$$Z_{36\text{mH}} = j(250)(36\times 10^{-3}) = j9\ \Omega$$

$$Z_{80\text{mH}} = j(250)(80\times 10^{-3}) = j20\ \Omega$$

$$Z_C = \frac{1}{j(250)(250\times 10^{-6})} = \frac{16}{j} = -j16\ \Omega$$

### 8.4 Düğüm Denklemi

Devre bir direnç devresi gibi çözülür. Alt düğüm sıfır referans olduğu için $a$ düğümünün gerilimi $\mathbf{V}_a$'dır. Düğüme giren akımlar pozitif alınır:

$$\mathbf{I}_1 + 1.2\angle 45^\circ = \mathbf{I}_2 + \mathbf{I}_3$$

Kol akımları düğüm gerilimleri farkının empedansa bölümüdür:

$$\mathbf{I}_1 = \frac{20\angle 0^\circ - \mathbf{V}_a}{8 + j9}, \quad \mathbf{I}_2 = \frac{\mathbf{V}_a}{-j16}, \quad \mathbf{I}_3 = \frac{\mathbf{V}_a - 4\mathbf{V}_a}{j20}$$

Slaytta birinci paydada $8 - j9$ yazıyordu. Hoca bunu fark edip $8 + j9$ olması gerektiğini söyledi. Bu düzeltme doğrudur.

Tek bilinmeyen $\mathbf{V}_a$'dır. Terimler düzenlenince (ara adım eklendi):

$$\mathbf{V}_a\left[\frac{1}{8 + j9} + \frac{1}{-j16} + \frac{-3}{j20}\right] = \frac{20}{8 + j9} + 1.2\angle 45^\circ$$

Python ile hesaplanan ara değerler:

- Köşeli parantez: $0.0552 + j0.1504 = 0.1602\angle 69.9^\circ$
- $\frac{20}{8 + j9} = 1.1034 - j1.2414$
- $1.2\angle 45^\circ = 0.8485 + j0.8485$
- Sağ taraf toplamı: $1.9520 - j0.3929 = 1.991\angle{-11.4^\circ}$

Buradan:

$$\mathbf{V}_a = \frac{1.991\angle{-11.4^\circ}}{0.1602\angle 69.9^\circ} = 12.43\angle{-81.2^\circ}\ \text{V}$$

### 8.5 Sonucun Doğrusu

Slayttaki sonuç $12.43\angle{-81.2^\circ}$ V idi. Hoca $8 + j9$ düzeltmesinin sonucu değiştirip değiştirmediğini MATLAB ile kontrol etti, $17.71\angle{-60.62^\circ}$ V buldu ve slaytı buna göre düzeltmeyi söyledi.

> **Ders sonrası not:** Hoca "sonuç $v_a(t) = 17.71\cos(250t - 60.61^\circ)$ V olmalı, farkın sebebi slayttaki $8 - j9$" dedi. Doğrusu $v_a(t) = 12.43\cos(250t - 81.2^\circ)$ V'tur, slayttaki sonuç doğrudur. Hoca MATLAB'a akım kaynağını $1.2\sqrt{2}\,(1 + j) = 1.697 + j1.697$ olarak girdi. $1.2\angle 45^\circ$ ise $1.2\cos 45^\circ + j1.2\sin 45^\circ = \frac{1.2}{\sqrt{2}}(1 + j) = 0.8485 + j0.8485$'tir. Aynı hatalı girdiyle $8 + j9$ kullanılınca $17.71\angle{-60.62^\circ}$ V, doğru girdiyle $12.43\angle{-81.2^\circ}$ V çıkar. Doğru girdi ve $8 - j9$ ile sonuç $10.21\angle{-31.7^\circ}$ V olur, yani slayttaki $8 - j9$ yalnız yazım hatasıdır. Hepsi python ile hesaplandı, doğru sonuç düğüm denklemini sağlıyor.

## 9. Örnek 54: Süper Düğüm ve Akım Kontrollü Kaynak

### 9.1 Devre ve Önceki Örnekten Farkı

Topoloji bir önceki örneğe kabaca benziyor, ama önemli bir fark var: Önceki örnekte bağımlı kaynağın bir ucu referanstaydı, bu yüzden o noktanın gerilimi doğrudan $4\mathbf{V}_a$ alındı. Burada kaynağın bir ucu referansa bağlı değil, üzerindeki gerilim düşümü için ek işlem gerekiyor.

> **Ders sonrası not:** Hoca bu karşılaştırmada iki kez "bağımsız kaynağın ucu" dedi. Anlatılan eleman $4\mathbf{V}_a$ ve $10\mathbf{I}$ kaynaklarıdır, yani doğrusu "bağımlı kaynağın ucu"dur.

Devre şöyledir: $v_s = 10\cos(10t)$ V kaynağı, seri $R_1 = 10\ \Omega$ ($i$ bu dirençten geçen akım) ile $v_1$ düğümüne gidiliyor. $v_1$ ile toprak arasında $C = 10$ mF ve $R_2 = 10\ \Omega$ paralel. $v_1$'den $v_2$'ye, eksi ucu $v_1$ tarafında olan $10i$ bağımlı gerilim kaynağı. $v_2$ ile toprak arasında seri $L = 500$ mH ve $R_3 = 5\ \Omega$. İstenen $i(t)$ akımıdır. Slaytta kaynak $v_a$ diye yazılmıştı, hoca bunun büyük ihtimalle $v_s$'ye karşılık geldiğini söyledi. Devrede başka bağımsız kaynak yok.

### 9.2 Fazörler

$\mathbf{V}_s = 10\angle 0^\circ$ V ve $\omega = 10$ rad/s. Empedanslar:

$$Z_{R_1} = 10\ \Omega, \quad Z_{R_2} = 10\ \Omega, \quad Z_{R_3} = 5\ \Omega$$

$$Z_C = \frac{1}{j(10)(10\times 10^{-3})} = -j10\ \Omega, \quad Z_L = j(10)(500\times 10^{-3}) = j5\ \Omega$$

### 9.3 Empedansları Birleştirme

Kapasite ve $R_2$ paraleldir:

$$Z_1 = \frac{1}{\frac{1}{-j10} + \frac{1}{10}} = \frac{10}{1 + j} = \frac{10(1 - j)}{1^2 + 1^2} = 5 - j5\ \Omega$$

$L$ ve $R_3$ seridir:

$$Z_2 = 5 + j5\ \Omega$$

Hoca, empedansları şekilde kutucuk olarak gösterebileceğimizi söyledi.

> **Ders sonrası not:** Hoca birleştirmeleri doğru buldu, ama sonra özet geçerken ikisi için de "$5 - j5$" dedi. Doğrusu $Z_2 = 5 + j5\ \Omega$'dur.

Slaytta denklemlerde $Z_2$ ve $Z_3$, şekilde $Z_1$ ve $Z_2$ yazıyordu. Hoca şekle uyacak biçimde düzeltti: denklemdeki $Z_2$, $Z_1$ olur; $Z_3$, $Z_2$ olur.

### 9.4 Denklemler

Düğüm gerilimlerinden yararlanılır. Kol akımı:

$$\mathbf{I} = \frac{\mathbf{V}_s - \mathbf{V}_1}{10}$$

Bağımlı kaynağın bir ucu referansa bağlı olmadığı için bir süper düğüm (supernode) söz konusudur. $\mathbf{I}$ akımı hem aşağıya hem kaynak üzerinden diğer kola devam eder:

$$\mathbf{I} = \frac{\mathbf{V}_1}{Z_1} + \frac{\mathbf{V}_2}{Z_2}$$

İki düğüm arasındaki gerilim farkını bağımlı kaynak belirler:

$$\mathbf{V}_2 = \mathbf{V}_1 + 10\mathbf{I}$$

Üç bilinmeyen ($\mathbf{V}_1$, $\mathbf{V}_2$, $\mathbf{I}$) ve üç denklem vardır. Hoca sayısal çözümü derste yapmadı, sonucun bu denklemlerden çekilip zaman domenine dönüştürülebileceğini söyledi.

### 9.5 Sayısal Çözüm

Çözüm (ara adımlar eklendi): Birinci denklemden $10\mathbf{I} = 10 - \mathbf{V}_1$ olur. Üçüncü denklemde yerine konunca $\mathbf{V}_2 = 10$ V çıkar. İkinci denklemde yerine konunca:

$$\frac{10 - \mathbf{V}_1}{10} = \mathbf{V}_1(0.1 + j0.1) + (1 - j)$$

$$j = \mathbf{V}_1(0.2 + j0.1) \quad \Rightarrow \quad \mathbf{V}_1 = 2 + j4 = 4.472\angle 63.4^\circ\ \text{V}$$

$$\mathbf{I} = \frac{10 - 2 - j4}{10} = 0.8 - j0.4 = 0.894\angle{-26.6^\circ}\ \text{A}$$

$$i(t) = 0.894\cos(10t - 26.6^\circ)\ \text{A}$$

Sonuç python ile hesaplandı ve kısa nottaki slayt değeriyle aynıdır.

Hoca bundan sonra gelen örneği atladı. O örnek bir op-amp sorusuydu ve her elemanın fazör karşılığı bulunup hesap yapılması gerekiyordu. Öğrencilerin kendilerinin bakmasını söyledi.

<!-- BELİRSİZ: Atlanan op-amp örneğinin devresi ve değerleri altyazıda geçmiyor. -->

## 10. Örnek 56: Bağımlı Kaynaklı Devrenin Norton Eşdeğeri

### 10.1 Devre

Bu örnekte her eleman zaten fazör uzayına geçirilmiş olarak veriliyor: $10\angle 30^\circ$ V kaynağından seri $30\ \Omega$ ve $5\mathbf{I}_a$ bağımlı gerilim kaynağı (artı ucu sağda) ile bir düğüme gidiliyor. Bu düğüm ile toprak arasında $-j25\ \Omega$ kapasite var, $\mathbf{I}_a$ bu kapasiteden aşağı akan akım. Düğümden seri $50\ \Omega$ ile çıkış uçlarına gidiliyor. Norton eşdeğeri isteniyor. Önemli nokta bir bağımlı kaynak olmasıdır. Kaynağın frekansı verilmediği için çözüm fazör uzayında, bir akım kaynağına paralel empedans noktasında bırakılır.

### 10.2 Açık Devre Gerilimi

Yük direnci yerine sonsuz direnç konduğunda uçlardaki gerilim $\mathbf{V}_{TH}$'dir. $50\ \Omega$'dan geçen akım sıfır olur, sol koldan akan akım kapasiteden akan $\mathbf{I}_a$'ya eşittir. Çevre boyunca gerilimler toplanır. Kaynakların eksi ucundan girildiği için ikisi negatif yazılır:

$$-10\angle 30^\circ + 30\mathbf{I}_a - 5\mathbf{I}_a + (-j25)\mathbf{I}_a = 0$$

$$(25 - j25)\mathbf{I}_a = 10\angle 30^\circ$$

Bir denklem, bir bilinmeyen vardır. $25 - j25$ polara çevrilince $35.36\angle{-45^\circ}$ olur (ara adım eklendi) ve bölme yapılır:

$$\mathbf{I}_a = \frac{10\angle 30^\circ}{35.36\angle{-45^\circ}} = 0.283\angle 75^\circ\ \text{A}$$

Açık devre gerilimi kapasitenin gerilimidir. $-j25$ polar biçimde $25\angle{-90^\circ}$ yazılır:

$$\mathbf{V}_{OC} = (0.283\angle 75^\circ)(25\angle{-90^\circ}) = 7.071\angle{-15^\circ}\ \text{V} = \mathbf{V}_{TH}$$

### 10.3 Kısa Devre Akımı

İçeride bağımlı kaynak olduğu için izlenecek yol kısa devre üzerinden gitmektir. Yük yerine kısa devre konur ve o koldan geçen akım bulunur. Thevenin devresi kısa devre yapılınca $\mathbf{I}_{SC} = \mathbf{V}_{TH}/Z_{TH}$ olur. $\mathbf{V}_{TH}$ bilindiği için buradan $Z_{TH}$ çıkar.

İki çevre vardır: birinci çevrede $\mathbf{I}_1$, kısa devreli çevrede $\mathbf{I}_{SC}$. Kapasite kolundaki akım $\mathbf{I}_a = \mathbf{I}_1 - \mathbf{I}_{SC}$'dir.

Birinci çevre:

$$30\mathbf{I}_1 - 5(\mathbf{I}_1 - \mathbf{I}_{SC}) - j25(\mathbf{I}_1 - \mathbf{I}_{SC}) = 10\angle 30^\circ$$

İkinci çevre:

$$50\mathbf{I}_{SC} - j25(\mathbf{I}_{SC} - \mathbf{I}_1) = 0$$

Bunlar iki bilinmeyenli iki denklemdir, matris biçimine getirilir (ara adım eklendi):

$$\begin{bmatrix} 25 - j25 & 5 + j25 \\ j25 & 50 - j25 \end{bmatrix}\begin{bmatrix}\mathbf{I}_1 \\ \mathbf{I}_{SC}\end{bmatrix} = \begin{bmatrix}10\angle 30^\circ \\ 0\end{bmatrix}$$

Çözüm (python ile hesaplandı):

$$\mathbf{I}_1 = 0.237\angle 61.4^\circ\ \text{A}, \quad \mathbf{I}_{SC} = 0.106\angle{-2.0^\circ}\ \text{A}$$

### 10.4 Norton Eşdeğeri

$\mathbf{V}_{OC}$, $\mathbf{I}_{SC}$'ye bölünerek eşdeğer empedans bulunur:

$$Z_{TH} = Z_N = \frac{7.071\angle{-15^\circ}}{0.106\angle{-2^\circ}} = 65 - j15 = 66.71\angle{-13^\circ}\ \Omega$$

Norton akımı için devrenin kısa devre edildiği hâl düşünülür. Norton empedansından akım geçmez, bütün akım kısa devre kolundan akar. Demek ki $\mathbf{I}_{SC}$ aynı zamanda Norton akımıdır:

$$\mathbf{I}_N = 0.106\angle{-2^\circ}\ \text{A}, \quad Z_N = 66.71\angle{-13^\circ}\ \Omega$$

### 10.5 Kaynağı Sıfırlama Denemesi

Hoca, direnç devresindeki pratiklerin burada da geçerli olduğunu, bir test kaynağı bağlayarak da hesap yapılabileceğini söyledi. Ardından bir deneme yaptı: Kaynağı sıfırladı, $\mathbf{I}_a$'nın sıfır olacağını, bu yüzden bağımlı kaynağın da sıfır alınabileceğini söyledi. Geriye $30\ \Omega$, $-j25\ \Omega$ ve $50\ \Omega$ kaldı:

$$Z = 30 \parallel (-j25) + 50 = (12.30 - j14.75) + 50 = 64.02\angle{-13.3^\circ}\ \Omega$$

<!-- BELİRSİZ: Hocanın ekranda okuduğu sayı altyazıda bozuk ("N-70 farklı"). Yukarıdaki değer python ile hesaplandı, kısa notla aynıdır. -->

Hoca sonucun $66.71\angle{-13^\circ}\ \Omega$'den biraz farklı çıktığını, bunun yuvarlamadan kaynaklandığını düşündüğünü söyledi ve bu yolun da kullanılabileceğini belirtti.

> **Ders sonrası not:** Hoca farkı yuvarlamaya bağladı ve kaynak sıfırlama yönteminin burada da kullanılabileceğini söyledi. Doğrusu: fark yöntem hatasından gelir, bağımlı kaynak sıfırlanamaz. Uçlara test akımı verildiğinde $\mathbf{I}_a$ sıfır olmaz. Bağımsız kaynak sıfırken uçlardan $1$ A verilirse (test kaynağı yöntemi) denklem $30(\mathbf{I}_a - 1) - 5\mathbf{I}_a - j25\mathbf{I}_a = 0$ olur. Buradan $\mathbf{I}_a = 0.6 + j0.6 = 0.849\angle 45^\circ$ A, kapasite gerilimi $15 - j15$ V ve $Z_{TH} = 50 + 15 - j15 = 65 - j15 = 66.71\angle{-13^\circ}\ \Omega$ çıkar. Bu değer $\mathbf{V}_{OC}/\mathbf{I}_{SC}$ ile tam aynıdır, python ile hesaplandı. Kaynak sıfırlayıp içeri bakma yöntemi yalnız bağımsız kaynaklı devrelerde kullanılabilir.

Hocanın genel sonucu, direnç devreleri için kullanılan Norton, Thevenin ve süperpozisyon mantıklarının hepsinin fazör uzayına taşınabildiğidir.

## 11. Özel Fonksiyonlar: Basamak, Dürtü ve Rampa

### 11.1 Tanımlar

Dönem içinde özel fonksiyonların tanımlanmasıyla ilgili konu ders akışı nedeniyle hızlı geçilmişti. Hoca bunu örneklerle tamamladı.

**Birim basamak fonksiyonu** ya $1$ ya $0$ değerini alır:

$$u(t) = \begin{cases} 1, & t > 0 \\ 0, & t < 0 \end{cases}$$

Grafiği sıfırda gelir, $t = 0$'da $1$'e çıkar ve $1$'de devam eder.

**Delta (impuls, dürtü) fonksiyonu** birim basamağın türevidir:

$$\delta(t) = \frac{du(t)}{dt}$$

Altında kalan alan $1$ olan, sonsuz genlikli, anlık bir darbedir.

**Rampa fonksiyonu** $t > 0$ iken $t$ değerini, $t < 0$ iken $0$ değerini alır, grafiği eğimi $1$ olan bir doğrudur:

$$r(t) = \begin{cases} t, & t > 0 \\ 0, & t < 0 \end{cases}, \qquad r(t) = \int u(t)\,dt$$

Birim basamağın genliği $1$ olduğu için herhangi bir $t$'ye kadar altında kalan alan $t$'ye eşittir. Rampa bu yüzden basamağın integralidir.

> **Hocanın vurgusu:** Bu fonksiyonlar arasındaki ilişkiler önemlidir: daha karmaşık fonksiyonlar bunlar cinsinden yazılır.

### 11.2 Örnek 45: Kare Darbe

$t = 2$ ile $t = 5$ arasında $10$ olan, diğer yerlerde $0$ olan bir gerilim veriliyor. Bu, kare puls fonksiyonudur. Birim basamaklar cinsinden yazılması ve türevinin bulunması isteniyor.

Önce katsayı $10$'dur. Fonksiyon $-\infty$'dan gelip $t = 2$'de yükseliyor. Bu kısım $10u(t - 2)$'dir, çünkü $u$ içindeki parametre sıfırdan büyükse $1$ olur, yani $t > 2$ için $1$'dir. Bu terim sonsuza kadar sürer, ama $t = 5$'te sıfırlanması gerekir. O hâlde ikinci terim, $t = 5$'te konum değiştiren ve genliği ters işaretli bir basamaktır. Eksi katsayı, basamağı yatay eksene göre simetriğine alır: $-10u(t - 5)$. İki terim toplanınca $t = 5$'ten sonraki kısımlar birbirini götürür:

$$v(t) = 10u(t - 2) - 10u(t - 5) = 10\left[u(t - 2) - u(t - 5)\right]$$

Türevde $u$'nun türevi $\delta$ olur:

$$\frac{dv}{dt} = 10\left[\delta(t - 2) - \delta(t - 5)\right]$$

Birinci dürtünün şiddeti $+10$, ikincisinin $-10$'dur. Bu, kare fonksiyonun üzerinden de görülür: $t = 2$'de $0$'dan $10$'a çıkış, yani $\frac{10}{dt}$ kadar bir değişim var. $t = 5$'te $10$'dan $0$'a düşüş, yani $\frac{-10}{dt}$ kadar bir değişim var.

### 11.3 Örnek 46: Çift Darbe ve İntegrali

$0$-$2$ arasında $+10$, $2$-$4$ arasında $-10$ olan bir akım veriliyor. Alt bileşenlere ayrılır:

1. $t = 0$'da başlayan $10u(t)$. Tek başına sonsuza kadar $10$'da kalır.
2. $t = 2$'de $-10$'a düşmek gerekiyor. Bunun için $10$'dan toplam $20$ inmek, yani $-20u(t - 2)$ eklemek gerekir. Bu ikisinin toplamı $2$'den sonra $-10$'da kalır.
3. $t = 4$'te toplamın $0$ olması gerekiyor. O anda $10 - 20 = -10$ olduğu için $+10u(t - 4)$ eklenir.

$$i(t) = 10u(t) - 20u(t - 2) + 10u(t - 4) = 10\left[u(t) - 2u(t - 2) + u(t - 4)\right]$$

İntegral alınırken $\int u\,dt = r$ kullanılır:

$$\int i\,dt = 10\left[r(t) - 2r(t - 2) + r(t - 4)\right]$$

Sonucu önceden tahmin etmek de mümkündür: Biri yukarıda biri aşağıda iki darbe vardır ve alanları eşittir, o hâlde toplam alan $t = 4$'ten sonra sıfır olmalıdır. Grafik üzerinden:

- $r(t)$, eğimi $1$ ile yükselir.
- $-2r(t - 2)$, $t = 2$'den itibaren eğimi $-2$ olan bir rampadır. İkisinin toplamının eğimi $-1$ olur, yani yükseldiği eğimle azalır. Yalnız bu iki terim kalsaydı grafik sonsuza kadar aşağı doğru devam ederdi.
- $r(t - 4)$, $t = 4$'te eğimi $+1$ olan üçüncü rampayı başlatır, eğimi sıfırlar ve toplam $0$'da kalır.

Tepe değeri $t = 2$'dedir: $10 \times 2 = 20$. Sonuç, $t = 4$'te sıfıra inen üçgen biçimli bir fonksiyondur. Değerler python ile hesaplandı: $t = 1, 2, 3, 4, 5$ için sırasıyla $10, 20, 10, 0, 0$.

### 11.4 Örnek 47: Testere Dişi, Üç Çözüm

$0$-$2$ arasında $0$'dan $10$'a doğrusal yükselen, $t = 2$'de sıfıra düşen bir gerilim veriliyor. Hoca burada farklı çözümler olabileceğini, üç senaryo gösterdiğini söyledi.

**Birinci çözüm: Rampa ve basamak toplamı.** Fonksiyon $2$ saniyede $10$ genliğine eriştiği için eğim $\frac{10}{2} = 5$'tir ve ilk kısım $5r(t)$'dir. Yükselmeyi durdurmak için $t = 2$'den başlayan, aynı eğimli ama ters yönlü bir rampa eklenir: $-5r(t - 2)$. Bu ikisinin toplamı $t = 2$'den sonra $10$ değerinde sabit kalır, basamak gibi bir yapı oluşur. Bu basamağı kaybetmek için $t = 2$'de ters yönlü bir basamak eklenir:

$$v(t) = 5r(t) - 5r(t - 2) - 10u(t - 2)$$

**İkinci çözüm: Pencere ile çarpma.** Basamak fonksiyonlarının farkı bir aralığı sınırlandırır. $u(t)$ ile $-u(t - 2)$ toplanınca $0$-$2$ arasında genliği $1$ olan bir pencere elde edilir. Bu pencere rampa ile çarpılırsa aranan sonuç bulunur. $r(t)$, $t \geq 0$ için $t$'ye eşit olduğu için bu, $t$ ile çarpmak gibi de düşünülebilir:

$$v(t) = 5r(t)\left[u(t) - u(t - 2)\right]$$

**Üçüncü çözüm: Tek basamakla sınırlama.** Rampa $t < 0$ için zaten sıfır olduğundan penceredeki $u(t)$ gereksizdir. Yalnız üst sınırı koyan bir basamak yeterlidir. Dikkat edilecek nokta, $t = 2$'de $10$'a ulaşılması gerektiği için rampanın genliğinin $5$ olmasıdır:

$$v(t) = 5r(t)\,u(2 - t)$$

$u(2 - t)$'nin nereden geldiği şöyle görülür: $u(t)$, soldan $0$, sağdan $1$ olan bir basamaktır. Bunun tersi bir basamak isteniyorsa yatay eksendeki değişkenin işareti değiştirilir, $u(-t)$ alınır. Bu, basamağın düşey eksene göre aynasıdır. Durum değişikliği $t = 2$'de olacağı için içerideki parametre $t - 2$'den gelir, işareti alınınca $-(t - 2) = 2 - t$ olur.

<!-- BELİRSİZ: Altyazıda üçüncü çözüm "eksi 5 UT eksi 2 fonksiyonunu ... rampa ile çarpabiliriz" diye geçiyor; bozuk okunmuş olmalı. Formül kısa nottan ve anlatımın sonundaki 2 - t türetmesinden alındı. -->

> **Ders sonrası not:** Hoca burada "rampa fonksiyonunu dikey yönde ayna görüntüsünü almak" dedi, hemen ardından işlemi birim basamak üzerinde gösterdi. Aynası alınan fonksiyon $u$'dur.

Üç çözümün de aynı fonksiyonu verdiği python ile hesaplandı. $t = 0.5, 1, 1.9$ için değerler $2.5, 5, 9.5$, $t = 2.1$ ve sonrası için $0$'dır.

## Dersin Toparlaması

Bu derste önce ikinci dereceden bir devrenin zaman domeninde çözümü görüldü. Burada iki başlangıç koşulu gerekiyor, ikincisi $V_C = L\frac{di_L}{dt} + Ri_L$ bağıntısından çıkıyor, zorlanmış çözüm ise belirli bir katsayıyla öneriliyor. Ardından fazör uzayına geçildi. Elemanlar ve kaynaklar fazöre çevrilince devre bir direnç devresi gibi çözülüyor, bu yüzden $\mathbf{V}_{TH} = \mathbf{I}_N Z_N$, $Z_{TH} = Z_N$, $\mathbf{I}_N = \mathbf{I}_{SC}$ ilişkileri, kaynak dönüşümü, gerilim ve akım bölücü, düğüm ve çevre denklemleri olduğu gibi kullanılıyor. Toplamada kartezyen, çarpma ve bölmede polar biçim pratik. Bağımlı kaynaklı devrelerde süper düğüm ve kısa devre akımı yoluna dikkat edilmesi gerekiyor. Son olarak basamak, dürtü ve rampa fonksiyonlarıyla kare darbe, üçgen ve testere dişi biçimlerinin nasıl yazılacağı görüldü.

Hoca bütün örnek çözümlerin paylaşılacağını, içlerinde soru tanımı veya şekillerde yazım farkları olabileceğini söyledi, bu yüzden dikkatli bakılmasını ve örneklerin dersin başındaki referans kaynaklarla birlikte pratik olarak çözülmesini istedi. Bunca teoremin asıl amacının devreyi daha pratik çözmek olduğunu da ekledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
