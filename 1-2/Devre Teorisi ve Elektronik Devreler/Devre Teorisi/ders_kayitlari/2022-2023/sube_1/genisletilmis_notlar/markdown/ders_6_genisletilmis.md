# Ders 6 Genişletilmiş Notu: Thevenin ve Norton Eşdeğer Devreleri, Maksimum Güç Aktarımı, Kondansatör ve Bobin

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaynak Dönüşümü ile Thevenin ve Norton Teoremlerinin Farkı
- 2. Thevenin Eşdeğeri, Yöntem 1: Art Arda Kaynak Dönüşümü
- 3. Thevenin Eşdeğeri, Yöntem 2: Açık Devre Gerilimi ve Kısa Devre Akımı
- 4. Thevenin Eşdeğeri, Yöntem 3: Kaynakları Sıfırlayıp Eşdeğer Direnç
- 5. Thevenin Eşdeğeri, Yöntem 4: Test Kaynağı
- 6. Thevenin ve Norton Örnekleri
- 7. Bağımlı Kaynaklı Thevenin Örnekleri
- 8. Maksimum Güç Aktarımı
- 9. Ek Örnekler: Süperpozisyon, Kaynak Dönüşümü ve Thevenin
- 10. Devre Teoremlerinin Toparlanması
- 11. Kondansatör
- 12. Bobin
- Örnek Sorular
- Dersin Toparlaması

## 1. Kaynak Dönüşümü ile Thevenin ve Norton Teoremlerinin Farkı

Önceki derste kaynak dönüşümü ve kaynak türleri görülmüştü. Hoca, kaynak dönüşümünün Thevenin ve Norton teoremleriyle karıştırılabileceğini belirterek ikisini ayırdı.

**Kaynak dönüşümü** (source transformation) yalnız şunu söyler: ideal olmayan bir gerilim kaynağı (ideal gerilim kaynağı + seri iç direnç), ideal olmayan bir akım kaynağı (ideal akım kaynağı + paralel iç direnç) biçiminde yazılabilir; tersi de geçerlidir.

**Thevenin teoremi** daha geneldir. Doğrusal elemanlardan oluşan iki terminalli karmaşık bir devre, seçilen iki terminalden içeri bakıldığında tek bir ideal olmayan gerilim kaynağıyla temsil edilebilir. Bu eşdeğer devrenin kaynağı **Thevenin gerilimi** $V_{TH}$, seri direnci **Thevenin direnci** $R_{TH}$'dir (ekrandan, 00:10:00). "Eşdeğer" demek, bu terminallere hangi yük direnci ($R_L$, İngilizcede *load*) bağlanırsa bağlansın, yük üzerinden geçen akımın ($i_L$) ve yükün uçlarındaki gerilimin ($v_L$) karmaşık devrede ve eşdeğer devrede birebir aynı olması demektir.

**Norton teoremi**, kaynak dönüşümünü bunun üzerine uygular: aynı karmaşık devre, seçilen terminallerden bakıldığında ideal olmayan bir akım kaynağına eşdeğerdir. Bu kaynağın akımı **Norton akımı** $I_N$, paralel direnci **Norton direnci** $R_N$'dir.

Hoca, Thevenin eşdeğerini bulmak için devrenin karmaşıklığına göre dört yöntem verdi. Terminallerden "içeri bakmak" şöyle gösterilir: yük ile devre arasına kesikli bir çizgi çizilir; bu, devrenin oradan koparıldığını ve kalan kısmın o iki uçtan görülen eşdeğerinin arandığını anlatır.

## 2. Thevenin Eşdeğeri, Yöntem 1: Art Arda Kaynak Dönüşümü

Bağımsız kaynaklar ve dirençlerden oluşan basit bir devrede, art arda kaynak dönüşümleri yapılarak (gerekirse kaynakları toplayarak, akım kaynaklarının yönlerine dikkat ederek, dirençleri birleştirerek) devre tek bir gerilim kaynağı ve tek bir seri dirence indirgenir (ekrandan, 00:10:00).

### 2.1 Örnek: 12 V, 3 Ω, 6 Ω, 7 Ω

<!-- BELİRSİZ: Bu örneğin slaytı karelerde görünmüyor; değerler altyazıdan alındı ve aynı devrenin bir sonraki slayttaki (ekrandan, 00:25:00) hâliyle tutarlıdır. -->

Devre, "Network A" denen karmaşık kısım ile sağdaki yük direnci $R_L$'den ("Network B") oluşur. Network A: 12 V kaynağa seri 3 Ω, ardından toprağa paralel 6 Ω, ardından terminale giden seri 7 Ω.

1. 12 V kaynak ve seri 3 Ω, ideal olmayan bir akım kaynağına dönüştürülür: $12/3 = 4$ A, 3 Ω paralel.
2. Paralel 3 Ω ve 6 Ω birleştirilir: $3\parallel6 = \frac{3\cdot6}{3+6} = 2$ Ω.
3. 4 A ve paralel 2 Ω tekrar gerilim kaynağına çevrilir: $4\cdot2 = 8$ V, 2 Ω seri. Amaç, 7 Ω ile seri birleştirme yapabilmektir.
4. Seri 2 Ω ve 7 Ω birleştirilir: 9 Ω.

Sonuç: $V_{TH} = 8$ V, $R_{TH} = 9$ Ω. Bu eşdeğerle yük akımı ve gücü parametrik olarak yazılabilir:

$$i_L = \frac{8}{9 + R_L}, \qquad P_L = i_L^2 R_L = \left(\frac{8}{9+R_L}\right)^2 R_L$$

## 3. Thevenin Eşdeğeri, Yöntem 2: Açık Devre Gerilimi ve Kısa Devre Akımı

Bu yöntemde yük direncinin iki özel durumu ele alınır (ekrandan, 00:15:00):

- $R_L = 0$: direnci sıfır olan eleman **kısa devre**dir (*short circuit*).
- $R_L \to \infty$: direnci sonsuz olan eleman **açık devre**dir (*open circuit*).

Eşdeğer devrede iki bilinmeyen ($V_{TH}$, $R_{TH}$) olduğu için bu iki durumdan iki denklem elde edilir.

Hoca önce bunun eşdeğer devrede ne vereceğine baktı. Eşdeğer devrenin uçları açık bırakılırsa $R_{TH}$'den akım geçmez ve uçlardaki gerilim doğrudan $V_{TH}$ olur. Pratikte bu, uçlara bir voltmetre bağlayarak ölçülebilir; ancak önce $R_L$ çıkarılmalıdır, yoksa voltmetre $R_L$'ye paralel bağlanmış olur. Teoride de yük çıkarılıp iki terminal arasındaki gerilim hesaplanır:

$$V_{TH} = V_{OC}$$

Uçlar bir telle kısa devre edilirse eşdeğer devrede $I_{SC} = V_{TH}/R_{TH}$ akımı akar. Pratikte bu, uçlara seri bağlanan bir ampermetreyle ölçülür; teoride yük yerine tel konup o telden geçen akım hesaplanır. $V_{TH}$ zaten bilindiği için:

$$R_{TH} = \frac{V_{OC}}{I_{SC}}$$

**Soru:** Bu yöntemin ilk yöntemden farkı tam olarak nedir? **Cevap:** İlk yöntem devreyi yalnız kaynak dönüşümleriyle indirger. İkinci yöntemde ise devre açık devre ve kısa devre durumları için çözülür ve bu çözümde istenen yöntem (düğüm analizi, çevre analizi vb.) kullanılabilir. İlk yöntem esasen Norton ve Thevenin'in kaynak dönüşümünden geldiğini vurgulamak içindir.

**Soru:** Kaynak dönüşümü derken tam olarak ne kastediliyor? **Cevap:** İdeal olmayan bir gerilim kaynağı yerine ideal olmayan bir akım kaynağı konabilmesi (ya da tersi).

### 3.1 Örnek 15: Aynı devre, açık devre gerilimi ve kısa devre akımıyla

Aynı 12 V, 3 Ω, 6 Ω, 7 Ω devresi kullanıldı (ekrandan, 00:25:00).

**Açık devre:** Uç boşta olduğu için 7 Ω'dan akım geçmez; akım yalnız 12 V, 3 Ω ve 6 Ω'luk çevrede dolaşır. $V_{OC}$, 6 Ω üzerindeki gerilimdir:

$$V_{OC} = 12\left(\frac{6}{3+6}\right) = 8 \text{ V}$$

**Kısa devre:** Terminaller kısa devre edilir ve 3 Ω, 6 Ω, 7 Ω'nun birleştiği düğüme $V$ denir. Düğümden çıkan akımların toplamı sıfırdır:

$$\frac{V-12}{3} + \frac{V}{6} + \frac{V}{7} = 0$$

Ortak payda 42 ile: $14V - 168 + 7V + 6V = 0 \Rightarrow 27V = 168 \Rightarrow V \approx 6.22$ V. Kısa devre akımı 7 Ω'dan geçen akımdır: $I_{SC} = V/7 \approx 0.889$ A $= 8/9$ A. Slaytta aynı sonuç ana kol akımı üzerinden bulunur: $I_M = 12/(3 + 7\parallel6) = 1.9259$ A, $I_{SC} = (1.9259\cdot6)/13 = 0.8889$ A.

$$R_{TH} = \frac{V_{OC}}{I_{SC}} = \frac{8}{8/9} = 9\ \Omega, \qquad V_{TH} = 8 \text{ V}$$

Hoca, bağımsız kaynaklı devrelerde bu yöntemin daha pratik ve önemli olduğunu, iyi anlaşılması gerektiğini söyledi.

## 4. Thevenin Eşdeğeri, Yöntem 3: Kaynakları Sıfırlayıp Eşdeğer Direnç

Önce yük çıkarılıp açık devre gerilimi bulunur ($V_{TH} = V_{OC}$). Sonra bütün **bağımsız** kaynaklar sıfırlanır: gerilim kaynakları kısa devre, akım kaynakları açık devre yapılır. Terminallerden görülen eşdeğer direnç $R_{TH}$'dir (ekrandan, 00:30:00):

$$V_{TH} = V_{OC}, \qquad R_{TH} = R_{eq}$$

Hoca yöntemi en basit "karmaşık devre" olan eşdeğer devrenin kendisinde sınadı: uçlar açıkken $R_{TH}$'den akım geçmez ve $V_{OC} = V_{TH}$ çıkar. Kaynak sıfırlanınca (uçları arasındaki gerilim sıfır olan eleman, yani kısa devre konunca) terminallerden doğrudan $R_{TH}$ görülür. Bu yöntemin avantajı, kısa devre akımını hesaplama adımına gerek kalmadan $R_{TH}$'nin doğrudan bulunmasıdır.

### 4.1 Örnek 16: Aynı devre

<!-- BELİRSİZ: Bu örneğin slaytı karelerde görünmüyor; değerler altyazıdan. -->

3 Ω ve 6 Ω seri olduğu için gerilimin üçte biri 3 Ω'da, üçte ikisi 6 Ω'da düşer: $12/3 = 4$, 6 Ω üzerinde $2\cdot4 = 8$ V. Yani $V_{OC} = 8$ V. 12 V kaynak sıfırlanınca 3 Ω ile 6 Ω paralel olur ($2$ Ω), buna 7 Ω seri eklenir: $R_{TH} = 9$ Ω.

## 5. Thevenin Eşdeğeri, Yöntem 4: Test Kaynağı

Hoca bu yöntemin önemli olduğunu ve devrede **bağımlı kaynak** varsa mutlaka bu yöntemin kullanılması gerektiğini söyledi (ekrandan, 00:35:00). Nedeni: Yöntem 3'te kaynaklar sıfırlanıp dirençler birleştirilir; bağımlı kaynağı kontrol eden akım ya da gerilim de bu sırada sıfırlanacağı için bağımlı kaynağın devredeki etkisi görülemez.

Adımlar:

1. Yük çıkarılır, açık devre gerilimi bulunur: $V_{TH} = V_{OC}$.
2. Bağımsız kaynaklar sıfırlanır (bağımlı kaynaklar devrede kalır).
3. Yükün çıkarıldığı iki terminale bir **test kaynağı** bağlanır: 1 A'lık bir akım kaynağı ya da 1 V'luk bir gerilim kaynağı.
4. Test kaynağının gerilimi ile akımının oranı alınır:

$$R_{TH} = \frac{V_{test}}{I_{test}}$$

Test kaynağının türü devreye göre seçilir. Kaynaklar sıfırlandıktan sonra devre tek bir düğüm çiftine (elemanlar paralel) dönüşmüşse gerilim kaynağı, tek bir çevreye dönüşmüşse 1 A'lık akım kaynağı bağlamak daha pratiktir; seçim öğrencinin inisiyatifindedir. Slaytta da belirtildiği gibi, dört yöntem içinde bağımlı kaynak içeren devrelerde çalışması garanti olan tek yöntem test kaynağı yöntemidir.

En basit devrede sınama: eşdeğer devrede kaynak sıfırlanınca yalnız $R_{TH}$ kalır. Uçlara 1 A akım kaynağı bağlanırsa uçlardaki gerilimi devrenin geri kalanı belirler: $V_{test} = 1\cdot R_{TH}$. Böylece $V_{test}/I_{test} = R_{TH}$ çıkar.

### 5.1 Örnek 17: Aynı devre, 1 V test kaynağıyla

<!-- BELİRSİZ: Bu örneğin slaytı karelerde görünmüyor; değerler altyazıdan. -->

$V_{TH} = 8$ V önceden biliniyor. 12 V kısa devre edilir, terminallere 1 V test kaynağı bağlanır. Ortadaki düğüm $V$ için:

$$\frac{V}{3} + \frac{V}{6} + \frac{V-1}{7} = 0$$

42 ortak paydasıyla $14V + 7V + 6V = 6 \Rightarrow 27V = 6 \Rightarrow V = \frac{2}{9}$ V. 7 Ω'dan düğüme doğru akan akım hesaplanınca $\frac{2/9 - 1}{7} = -\frac{1}{9}$ A çıkar. Akım yönü düğümden kaynağa doğru tanımlandığı için, kaynaktan devreye giden akım $I_{test} = 1/9$ A'dir.

$$R_{TH} = \frac{V_{test}}{I_{test}} = \frac{1}{1/9} = 9\ \Omega$$

> **Ders sonrası not:** Hoca bu adımda test değerini "1 amper" ve sonucu "$V_{TH}$" diye söyledi; doğrusu test kaynağı 1 V'tur ve bulunan değer $R_{TH} = 9$ Ω'dur.

## 6. Thevenin ve Norton Örnekleri

Thevenin eşdeğerinden Norton eşdeğerine geçmek için direnç aynı kalır, Norton akımı Thevenin gerilimi bölü Thevenin direncidir:

$$R_N = R_{TH}, \qquad I_N = \frac{V_{TH}}{R_{TH}}$$

### 6.1 Örnek 18: 1 kΩ'luk yükün gördüğü devre

Devre (ekrandan, 00:40:00): solda 4 V kaynak (+ üstte), üst kolda 2 kΩ, orta düğüm ile alt hat arasında yukarı yönlü 2 mA akım kaynağı, orta düğümden terminale 3 kΩ, terminaller arasında 1 kΩ yük. İstenen: 1 kΩ'luk direncin gördüğü devrenin Thevenin ve Norton eşdeğerleri.

**$V_{OC}$:** Yük çıkarılınca 3 kΩ'dan akım geçmez; terminal gerilimi orta düğümün gerilimidir. 2 mA, 4 V kaynağı ve 2 kΩ'luk tek çevrede dolaşır; çevre akımı doğrudan 2 mA'dir. Gerilim: 2 kΩ üzerinde $0.002\cdot2000 = 4$ V, buna 4 V kaynak eklenir:

$$V_{OC} = 4 + 4 = 8 \text{ V}$$

Slayt aynı sonucu süperpozisyonla verir: $V_{oc|4V} = 4$ V, $V_{oc|2mA} = 0.002\times2000 = 4$ V, toplam 8 V.

**$R_{TH}$ (Yöntem 3):** Gerilim kaynağı kısa devre, akım kaynağı açık devre yapılınca 3 kΩ ile 2 kΩ seri kalır: $R_{TH} = 5$ kΩ.

**Norton:** $I_N = 8/5000 = 1.6$ mA, paralel 5 kΩ.

### 6.2 Örnek 19: Yük verilmemiş devre

Devre (ekrandan, 00:45:00): 3 V kaynak (+ üstte), üst kolda 2 kΩ; 2 kΩ'un sağındaki düğümden alt hatta (toprağa) doğru aşağı yönlü 7 mA akım kaynağı; aynı düğümden toprağa 5 kΩ; düğümden terminale seri 1 kΩ. Slayttaki cevap: $-7.857$ V, $-3.235$ mA, $2.429$ kΩ.

**$V_{OC}$:** 1 kΩ'dan akım geçmediği için $V_{OC}$, 5 kΩ üzerindeki gerilime eşittir. Düğüm $V$ için çıkan akımların toplamı:

$$\frac{V-3}{2000} + 0.007 + \frac{V}{5000} = 0$$

Hoca hesabın ilk denemesinde payı yanlışlıkla $V - 3000$ yazdı, fark edip baştan yaptı. Düzenlenince $V\left(\frac{1}{2000} + \frac{1}{5000}\right) = \frac{3}{2000} - 0.007$, yani $\frac{7V}{10000} = -0.0055$ ve

$$V_{OC} = V = -\frac{55}{7} \approx -7.857 \text{ V}$$

**$R_{TH}$:** 3 V kısa devre, 7 mA açık devre yapılır. 2 kΩ ve 5 kΩ paralel, 1 kΩ seri:

$$R_{TH} = \frac{1}{\frac{1}{2000} + \frac{1}{5000}} + 1000 = \frac{10000}{7} + 1000 \approx 2.429 \text{ kΩ}$$

**Norton:** $I_N = V_{TH}/R_{TH} = -7.857/2429 \approx -3.235$ mA (slayttaki cevap).

## 7. Bağımlı Kaynaklı Thevenin Örnekleri

### 7.1 Örnek 20: $v_x/4000$ bağımlı akım kaynağı

Devre (ekrandan, 00:50:00): solda 4 V kaynak (+ üstte), üst kolda 2 kΩ; 2 kΩ'un sağındaki düğümden alt hatta yukarı yönlü, değeri $v_x/4000$ olan bağımlı akım kaynağı; düğümden "+" terminaline 3 kΩ. $v_x$, açık terminaller arasındaki gerilimdir (+ üstte). İstenen: açık devre terminallerine göre Thevenin eşdeğeri.

**$V_{OC}$:** Açık devrede 3 kΩ'dan akım geçmez. Bu yüzden orta düğümün gerilimi de $v_x$'tir ve bağımlı kaynağın akımı 2 kΩ'dan geçmek zorundadır. Bağımlı kaynak yukarı doğru akım bastığı için çevre akımı 2 kΩ'da kaynağa doğru, yani seçilen çevre yönünün tersinedir. KVL:

$$-4 + 2\times10^3\left(-\frac{v_x}{4000}\right) + 3\times10^3(0) + v_x = 0$$

$-4 - \frac{v_x}{2} + v_x = 0 \Rightarrow \frac{v_x}{2} = 4 \Rightarrow v_x = 8$ V $= V_{OC}$.

**$R_{TH}$ (test kaynağı):** 4 V kısa devre edilir. Bağımlı kaynak devrede kalır. Terminallere 1 V test kaynağı bağlanır; $v_x$ terminal gerilimi olduğu için $v_x = 1$ V ve bağımlı kaynak $1/4000$ A olur. Orta düğüm $V$ için (ekrandan, 00:55:00):

$$\frac{V}{2000} - \frac{1}{4000} + \frac{V-1}{3000} = 0$$

$\frac{5V}{6000} = \frac{1}{4000} + \frac{1}{3000} = \frac{7}{12000}$, buradan $V = 0.7$ V. Test kaynağından devreye giden akım 3 kΩ üzerinden:

$$I_{test} = \frac{1 - 0.7}{3000} = 10^{-4} \text{ A}, \qquad R_{TH} = \frac{1}{10^{-4}} = 10 \text{ kΩ}$$

Slayt aynı sonucu kısa devre akımı yoluyla verir: terminaller kısa devre edilince $v_x = 0$ olur ve bağımlı kaynak devre dışı kalır; $I_{sc} = 4/(5\times10^3) = 0.8$ mA ve $R_{TH} = 8/(0.8\times10^{-3}) = 10$ kΩ.

Hoca, bu örnekte bağımlı kaynağı kontrol eden $v_x$ doğrudan terminal gerilimi olduğu için sıfır volt bağlamanın (kısa devre) da sonuç verdiğini, ama $v_x$ devrenin başka bir yerinde tanımlı olsaydı bunun anlamlı bir çözüm oluşturmayabileceğini söyledi. Genel kural: devrede bağımlı kaynak varsa sıfırdan farklı, anlamlı bir test kaynağı bağlanmalıdır.

**Soru:** Devreden geçen akımı hesaplarken yalnız akım kaynağını dikkate alıyoruz; gerilim kaynağı da devre için bir akım üretmiyor mu? **Cevap:** Gerilim kaynağının üzerinden geçen akımı diğer elemanlar belirler. Gerilim kaynağı yalnız iki ucu arasındaki gerilim farkını belirler; diğer elemanların etkisiyle üzerinde oluşan akımı kabul eder.

> **Hocanın vurgusu:** Gerilim kaynağı akımı belirlemez; bu önemli bir noktadır.

### 7.2 Örnek 21: Akım kontrollü gerilim kaynağı ($1.5i$)

<!-- BELİRSİZ: Bu örneğin slaytı karelerde görünmüyor. Devre yapısı altyazıdan kuruldu: bir ucu referansta olan $1.5i$ akım kontrollü gerilim kaynağı, ondan ara düğüme 3 Ω, ara düğümden referansa 2 Ω; terminal ara düğüm ile referans arasında, $i$ terminal akımı. -->

Devrede bağımsız kaynak yoktur. Uçlar açıkken $i = 0$ olur, bağımlı kaynağın gerilimi de sıfırdır ve $V_{OC} = 0$ çıkar. Kaynak sıfırlamaya gerek yoktur; terminallere 1 A test akım kaynağı bağlanır. Test kaynağının yönü $i$'nin tersine olduğu için $i = -1$ A kesindir.

Alt düğüm referans (0 V) seçilince bağımlı kaynağın üst ucu $1.5\cdot(-1) = -1.5$ V olur. Ara düğüm $x$ için çıkan akımların toplamı (ekrandan alınamadı, altyazıdan):

$$\frac{x - (-1.5)}{3} + \frac{x}{2} - 1 = 0$$

$\frac{1.5}{3} = 0.5$ olduğundan $\frac{x}{3} + \frac{x}{2} = 0.5 \Rightarrow \frac{5x}{6} = 0.5 \Rightarrow x = 0.6$ V. Test akım kaynağı 2 Ω'a paraleldir, uçlarındaki gerilim $V_{test} = 0.6$ V'tur:

$$R_{TH} = \frac{V_{test}}{I_{test}} = \frac{0.6}{1} = 0.6\ \Omega$$

$V_{OC} = 0$ olduğundan bu devrenin Thevenin eşdeğeri yalnız 0.6 Ω'luk bir dirençtir.

> **Ders sonrası not:** Hoca sonucu "0.6 volt" diye söyledi; $R_{TH}$ bir dirençtir, doğrusu 0.6 Ω.

**Soru:** $V_{test}$ nasıl bulundu? **Cevap:** Test kaynağı 1 A olarak seçildi. $i$ ile gösterilen akımı bu akım kaynağı belirler ve yönler ters olduğu için $i = -1$ A'dir. Bağımlı kaynak iki ucu arasında $1.5i = -1.5$ V fark oluşturur. Ara düğüme düğüm denklemi yazılınca $x = 0.6$ V bulunur; test kaynağı bu düğümle referans arasına bağlı olduğu için $V_{test} = 0.6$ V'tur.

Hoca bu noktada Norton ve Thevenin teoremlerini kapattı: bu teoremler karmaşık bir devreyi tamamen ya da devrenin yalnız belirli bir bölgesini indirgemek için kullanılır. Akılda kalması gereken: içeride bağımlı kaynak varsa önce açık devre gerilimi ($V_{TH}$) bulunur, sonra terminallere test kaynağı bağlanıp $V_{test}/I_{test}$ ile $R_{TH}$ hesaplanır.

## 8. Maksimum Güç Aktarımı

Aradan sonra hoca, ideal olmayan bir kaynaktan en fazla gücü çekebilmek için yük direncinin ne olması gerektiği sorusuna geçti. Bu kavram ileride elektronik ve mikrodalga gibi derslerde hat uyumlaştırma (örneğin anten bağlantısı) konusunda karşıya çıkar.

Soru iki parçalıdır. Birincisi: ideal olmayan bir gerilim kaynağına ($v_s$, $R_s$ sabit) bağlanan $R_L$ nasıl seçilmeli ki yüke en fazla güç aktarılsın? İkincisi: doğrusal herhangi bir devrenin Thevenin eşdeğeri yazılabildiği için, birinci sorunun cevabı herhangi bir devrenin iki terminaline bağlanan yük için de cevaptır.

### 8.1 Yük gücünün ifadesi

Yük akımı $i_L$, yük gerilimi $v_L$ olsun (ekrandan, 01:00:00):

$$p_L = i_L v_L = \frac{v_L^2}{R_L} = \frac{1}{R_L}\left[v_s\frac{R_L}{R_s+R_L}\right]^2 = \frac{v_s^2 R_L}{(R_s+R_L)^2}$$

$R_L$'nin değişen değerleri için $p_L$ incelenir:

- $R_L \to 0$: payda sabit bir terime ($R_s^2$) gider, pay sıfıra gider; $p_L \to 0$.
- $R_L \to \infty$: paydada $R_L^2$, payda $R_L$ vardır; payda daha hızlı büyür, $p_L \to 0$.
- Arada güç önce artar, bir tepe noktasından geçer ve sonra azalarak sıfıra yaklaşır. Aranan, bu tepeyi veren $R_L$ ve tepedeki güçtür.

### 8.2 Türev ile tepe noktası

Tepe noktası, eğrinin $R_L$'ye göre eğiminin sıfır olduğu yerdir: $\frac{dp_L}{dR_L} = 0$ (ekrandan, 01:25:00). Bölümün türevi kuralı kullanılır:

$$\left(\frac{f(x)}{g(x)}\right)' = \frac{f'(x)g(x) - g'(x)f(x)}{g^2(x)}$$

- $f = v_s^2 R_L$: $v_s$, $R_L$'ye bağlı olmadığından $f' = v_s^2$.
- $g = (R_s + R_L)^2$: zincir kuralıyla $g' = 2(R_s+R_L)\cdot1$.

Hoca ilk denemede iç türevi yanlış yazıp silerek düzeltti. Sonuç:

$$\frac{dp_L}{dR_L} = \frac{(R_s+R_L)^2 v_s^2 - 2v_s^2R_L(R_s+R_L)}{(R_s+R_L)^4}$$

Payı sıfıra eşitleyip $v_s^2(R_s + R_L)$ ile sadeleştirince $R_s + R_L = 2R_L$, yani:

$$R_L = R_s$$

Bu noktadaki güç: $p_{max} = \frac{v_s^2 R_s}{(2R_s)^2} = \frac{v_s^2}{4R_s}$. Yük direnci bu değerden büyük ya da küçük seçilirse aktarılan güç azalır.

Karmaşık bir devrenin Thevenin eşdeğeri bulunursa aynı sonuç geçerlidir:

$$R_L = R_{TH}, \qquad p_{max} = \frac{V_{TH}^2}{4R_{TH}}$$

Slayttaki kutu: yük direnci kaynağın Thevenin direncine eşit olduğunda yüke en büyük güç aktarılır.

### 8.3 Örnek 22: Ortak emetörlü BJT kuvvetlendirici modeli

Devre (ekrandan, 01:30:00) iki parçalıdır.

- Giriş kısmı: $2.5\sin 440t$ mV'luk AC kaynak, seri 300 Ω, ardından toprağa paralel 17 kΩ ve 5 kΩ; 5 kΩ üzerindeki gerilim $v_\pi$ (+ üstte).
- Çıkış kısmı: aşağı yönlü $0.03v_\pi$ bağımlı akım kaynağı, paralel 1 kΩ, terminallerde yük $R_L$.

İstenen: kuvvetlendiriciden en fazla gücü çekecek yük direnci ve bu durumda yükün çektiği güç. Hoca, AC kaynak henüz görülmemiş olsa da doğrusallık ve süperpozisyon mantığıyla çözülebileceğini, bu devrenin ileride elektronik derslerinde göreceğiniz bipolar jonksiyon transistörün (BJT) küçük işaret eşdeğer devresi olduğunu söyledi.

**$R_{TH}$ (Yöntem 4):** Bağımsız kaynak sıfırlanınca giriş kısmında akım akıtacak bir eleman kalmaz; giriş ile çıkış arasındaki bağlantı yalnız gerilimi ($v_\pi$) taşır. Bu yüzden $v_\pi = 0$ ve bağımlı kaynağın değeri sıfırdır. Terminallere 1 V test kaynağı bağlanınca 1 kΩ'dan 1 mA geçer:

$$R_{TH} = \frac{1 \text{ V}}{1 \text{ mA}} = 1 \text{ kΩ}$$

**Soru:** $v_\pi$ neden sıfır oldu? **Cevap:** Test kaynağı yönteminde bağımsız kaynaklar sıfırlanır. Giriş tarafında referans 0 V seçildiğinde akım akmasını sağlayacak bir kaynak kalmadığı için bütün düğümler 0 V olur; $v_\pi = 0$ ve bağımlı kaynak da sıfır olur. Bu yüzden test kaynağı bağlansa da yalnız 1 kΩ görülür.

**$V_{TH}$:** $5\parallel17 = 3864$ Ω (yaklaşık). Gerilim bölücüyle:

$$v_\pi = (2.5\times10^{-3}\sin 440t)\left(\frac{3864}{300+3864}\right)$$

Açık devrede bağımlı kaynağın akımı tamamen 1 kΩ'dan geçer; aşağı yönlü akım, "+" ucu üstte olan $v_{oc}$'yi negatif yapar:

$$v_{oc} = -0.03v_\pi(1000) = -30v_\pi$$

**Maksimum güç:** $R_L = R_{TH} = 1$ kΩ seçilir:

$$p_{max} = \frac{v_{TH}^2}{4R_{TH}} = 1.211\sin^2 440t \ \mu\text{W}$$

Python ile kontrol: $v_\pi$ genliği $\approx 2.320$ mV, $v_{oc}$ genliği $\approx 69.6$ mV, $69.6^2\times10^{-6}/4000 \approx 1.211$ μW (slayttaki sonuçla uyumlu).

## 9. Ek Örnekler: Süperpozisyon, Kaynak Dönüşümü ve Thevenin

Konu takviminde bir haftalık gecikme olduğu için hoca kalan örneklerde yalnız çözüm yolunu gösterdi, ayrıntılı çözümü zorunlu olmayan ev çalışması olarak öğrencilere bıraktı. Ayrıntılı çözümler aşağıda "Örnek Sorular" bölümündedir.

### 9.1 Örnek 23: Süperpozisyonla $i_o$

Devre ekrandan alındı (ekrandan, 01:35:00); ayrıntısı Örnek Sorular bölümündedir. Çözüm yolu: kaynaklar sırayla sıfırlanır (gerilim kaynağı yerine kısa devre, akım kaynağı yerine açık devre). Her alt devrede $i_o$'ya katkı ayrı hesaplanıp toplanır. $i_o$ aynı zamanda bağımlı kaynağı ($5i_o$) belirlediği için bağımlı kaynak her iki alt devrede kalır.

- Birinci alt devre (yalnız 4 A): üç çevre akımı ($i_1, i_2, i_3$) ve $i_o'$ için dört denklem gerekir; $i_1 = 4$ A doğrudan yazıldığı için hoca bunu "üç bilinmeyen" diye özetledi.
- İkinci alt devre (yalnız 20 V): iki çevre ($i_4, i_5$) ve $i_o''$; üç denklem, üç bilinmeyen.
- Sonuç $i_o = i_o' + i_o''$.

### 9.2 Örnek 24: Kaynak dönüşümüyle $v_x$

<!-- BELİRSİZ: Bu örneğin slaytı karelerde görünmüyor; devre yapısı altyazıdan kısmen kuruldu (6 V kaynak ve 2 Ω, iki paralel 2 Ω'luk direnç olarak birleşen 1 Ω, $0.25v_x$ bağımlı akım kaynağı ve 4 Ω, 18 V kaynak). -->

Süperpozisyon gibi kaynak dönüşümü de hem bağımsız hem bağımlı kaynaklara uygulanabilir.

1. 6 V ve seri 2 Ω, $6/2 = 3$ A'lik akım kaynağına ve paralel 2 Ω'a dönüştürülür.
2. $0.25v_x$ bağımlı akım kaynağı ve paralel 4 Ω, bağımlı gerilim kaynağına dönüştürülür: direnç aynı kalır, gerilim $4\times0.25v_x = v_x$ olur.
3. İki paralel direncin eşdeğeri 1 Ω'dur; 3 A ve paralel 1 Ω, 3 V ve seri 1 Ω'a dönüştürülür.
4. Devre tek çevreye iner. Hocanın yazdığı denklemler:

$$-3 + 5i + v_x + 18 = 0$$
$$-v_x + 4i + v_x + 18 = 0 \Rightarrow i = -4.5 \text{ A}$$

$i$ birinci denklemde yerine konunca $v_x$ bulunur; hoca bu son adımı öğrencilere bıraktı.

> **Çözüm (derste verilmedi):** $v_x = 3 - 5i - 18 = 3 + 22.5 - 18 = 7.5$ V (python ile kontrol edildi).

### 9.3 Örnek 25: Bağımlı kaynaklı ($2v_x$) Thevenin eşdeğeri

Devre ekrandan alındı (ekrandan, 01:40:00); ayrıntısı Örnek Sorular bölümündedir. Bağımlı kaynak olduğu için iki adımda çözülür:

- **$R_{TH}$:** 5 A akım kaynağı sıfırlanır (çıkarılır), terminallere $v_o = 1$ V test kaynağı bağlanır. Üç çevre ($i_1, i_2, i_3$) ve $v_x$ için bir denklem gerekir; $v_x$ 4 Ω üzerindeki gerilim olduğundan $-4i_2 = v_x$ yazılabilir. Dört denklem dört bilinmeyenle çözülür. Test kaynağından çıkan akım $i_o = -i_3$'tür ve $R_{TH} = 1/i_o$.
- **$V_{TH}$:** Terminaller açık bırakılır. Üç çevre vardır, ama $i_1 = 5$ A doğrudan yazılır. Bir denklem $i_2$ çevresinden, bir denklem $i_3$ çevresinden (bağımlı kaynağın gerilimi, paralel bağlı olduğu 2 Ω'un düğümleri arasındaki farka eşittir), bir denklem de $v_x$ için yazılır. Sağdaki 2 Ω'dan akım geçmediği için $V_{OC} = 6i_2$ olur.

### 9.4 Örnek 26: Maksimum güç ve Thevenin birlikte

<!-- BELİRSİZ: Bu örneğin slaytı karelerde görünmüyor; değerler altyazıdan (6 Ω, 12 Ω, 3 Ω, 2 Ω, bir akım kaynağı ve bir gerilim kaynağı). $V_{TH}$'nin sayısal değeri derste söylenmedi. -->

Verilen devrede $R_L$ yüküne en fazla güç aktarılmak isteniyor. İçeride bağımlı kaynak olmadığı için kaynaklar sıfırlanıp eşdeğer direnç bulunabilir: akım kaynağı kopar, gerilim kaynağı kısa devre olur. 6 Ω ile 12 Ω paralel (4 Ω), buna 3 Ω ve 2 Ω seri eklenir:

$$R_{TH} = 4 + 3 + 2 = 9\ \Omega \quad\Rightarrow\quad R_L = 9\ \Omega$$

$V_{TH}$ için uçlar açık bırakılır; sağdaki koldan akım geçmez. Çevre analiziyle akım kaynağının bulunduğu çevrenin akımı doğrudan $i_2 = -2$ A'dir; tek bilinmeyenli denklemden $i_1$ bulunur ve terminal gerilimi bu akımlarla yazılır. Sonra $p_{max} = V_{TH}^2/(4R_{TH})$.

## 10. Devre Teoremlerinin Toparlanması

Hoca, temel devre teoremlerinin tamamlandığını söyleyip şunların mutlaka bilinmesi gerektiğini vurguladı:

- **Düğüm analizi:** hangi devrelere, nasıl uygulandığı. **Süper düğüm:** bir ucu referansta olmayan bir gerilim kaynağı olduğunda ortaya çıkar; o koldaki akım diğer kollara bağlı olarak belirlenir.
- **Çevre analizi:** çevre denklemleriyle çözüm. **Süper çevre:** iki çevrenin paylaştığı bir akım kaynağı varsa, iki çevreden yazılan denklemler doğrusal bağımsız olmaz; daha büyük bir çevre alınarak çözülür.
- Kaynak dönüşümü, doğrusallık, süperpozisyon.
- Norton ve Thevenin eşdeğerleri ile maksimum güç aktarımı.

> **Hocanın vurgusu:** Bu kavramların terim olarak ne anlama geldiği mutlaka bilinmeli ve örneklerle pekiştirilmelidir.

Sonraki konular: kapasite ve endüktans elemanları, RL ve RC devrelerinin davranışı, ardından çözümü zor olan RLC devreleri ve sinüzoidal bir kaynağın uzun süre bulunduğu durumlar için yeni bir devre çözme yöntemi. Bunların temeli olan enerji depolayan elemanlarla başlanır (ekrandan, 01:45:00).

## 11. Kondansatör

### 11.1 Yapı ve kapasite

Kondansatör (kapasite elemanı) enerjiyi üzerinde tuttuğu yük miktarıyla depolar. İki iletken plaka arasına yalıtkan (dielektrik) bir malzeme konarak yapılır; şematik gösterimi de buna benzer (ekrandan, 01:50:00):

$$C = \frac{\varepsilon A}{d}, \qquad \varepsilon = \varepsilon_r\varepsilon_0$$

Burada $\varepsilon_0$ boşluğun (vakumun) geçirgenliği, $\varepsilon_r$ malzemenin bu referansa göre bağıl dielektrik sabitidir. $A$ plaka yüzey alanı, $d$ plakalar arası uzaklıktır. Yüzey alanı arttıkça daha fazla yük birikebilir; plakalar yaklaştıkça karşı plakadaki zıt yüklerin etkisi artar ve yük depolama kabiliyeti yükselir.

Laboratuvarda kullanılan silindirik elektrolitik kondansatörlerde iki paralel düz plaka yerine iç içe kıvrılmış metal plakalar vardır; aralarında yine dielektrik bulunur ve kıvrılma yüzey alanını büyütür.

### 11.2 Kondansatör türleri

- **Seramik kondansatör** ("mercimek kondansatör"): yönsüzdür.
- **Elektrolitik kondansatör:** yönlüdür. Gösterimde eksi ucu eğik bir çizgiyle ya da artı ucu "+" işaretiyle belirtilir. Eksi ucu kaynağın referans ucuna doğru bağlanmalıdır.

> **Hocanın vurgusu:** Elektrolitik kondansatör ters bağlanırsa şişme ve patlama riski vardır.

- **Değer okuma:** Dirençlerde olduğu gibi üzerindeki kod değeri verir. İlk iki rakam iki basamaklı bir sayı, üçüncü rakam 10'un kuvvetidir; sonuç pikofarad cinsindendir. Örneğin $10\times10^2 = 1000$ pF $= 1$ nF.
- **Değişken kondansatör:** Mekanik bir düzenekle (örneğin döndürülen bir çarkla) plakaların karşılıklı yüzey alanı değiştirilerek kapasite ayarlanır.
- **MEMS kondansatörler:** Mikro elektromekanik sistemlerin minyatür kondansatörleridir; değişken ya da sabit olarak, küçük devre ayak izi gereken RF devrelerinde kullanılır.

### 11.3 Elektriksel özellikler

Kondansatörün sembolü DC koşullardaki davranışını da gösterir: uçlar arasında bağlantı yoktur. Kondansatör DC kararlı durumda **açık devre** gibi davranır (ekrandan, 01:55:00).

Bu özellik elektronikte kullanılır: transistörlü bir kuvvetlendiricide transistör DC gerilimlerle belirli bir çalışma noktasına getirilir. Kuvvetlendirilecek küçük genlikli AC işaret bu noktayı bozmasın diye kuvvetlendiriciye seri bir kondansatör üzerinden verilir; böylece işaretin DC bileşeni çalışma noktasını bozmaz.

**Gerilimin sürekliliği:** Boş bir kondansatöre bir direnç üzerinden gerilim uygulanınca akım yükleri taşır ve plakalarda yük birikmeye başlar. Başta kondansatörün yük kabul etme isteği çok yüksektir; yük biriktikçe bu istek azalır. Kondansatör gerilimi kaynak gerilimine eşit olduğunda artık yük kabul etmez. Deşarjda da yüklü kondansatörün uçları bir dirençle birleştirilince yükler direnç üzerinden akıp birbirini nötrler. Yük bir anda aktarılamadığı ya da çekilemediği için:

> **Hocanın vurgusu:** Kondansatörün gerilimi süreklidir, ani sıçrama gösteremez; grafiği yumuşak bir eğridir. Bu, kondansatörün en önemli özelliğidir.

**Enerji:** İdeal kondansatör enerji harcamaz; depolarken güç çeker, deşarj olurken geri verir. Gerçek kondansatörde dielektrikten küçük kaçak akımlar geçer ve yük zamanla azalır. Bu, ideal kondansatöre **paralel bir direnç** eklenerek modellenir; kondansatör hiçbir yere bağlı olmasa bile bu direnç üzerinden yavaşça boşalır.

### 11.4 Akım-gerilim bağıntıları

Depolanan yük, kapasite ve uygulanan gerilimle doğru orantılıdır (ekrandan, 02:00:00):

$$Q = CV$$

Birimler: coulomb = farad·volt. $C = \varepsilon_r\varepsilon_0 A/d$ bağıntısında $\varepsilon_r$ birimsiz olduğundan $\varepsilon_0$'ın birimi F/m'dir.

Akım, birim zamandaki net yük geçişi olduğu için iki tarafın zamana göre türevi alınır; $C$ sabittir (ekrandan, 02:05:00):

$$i_C = \frac{dq}{dt}, \qquad q = Cv_C, \qquad i_C = C\frac{dv_C}{dt}$$

Tersinden, $q = \int i\,dt$ olduğu için:

$$v_C = \frac{1}{C}\int_{t_0}^{t_1} i_C\,dt$$

Başlangıçta üzerinde yük olan bir kondansatör, aynı yönlü bir gerilim kaynağına bağlanınca boş bir kondansatöre göre daha az yeni yük kabul eder. Uçlarına ne kadar yüksek gerilim uygulanırsa $Q = CV$ gereği o kadar çok yük birikir.

### 11.5 Güç ve enerji

Gücün tanımı $p = vi$'dir. Hoca burada potansiyelin tanımını hatırlattı: birim yüke 1 joule enerji yükleyecek gerilim farkı 1 volttur. Kondansatör için:

$$p = v_C i_C = Cv_C\frac{dv_C}{dt}$$

Enerji gücün zamana göre integralidir. $dt$'ler sadeleşince $\int Cv_C\,dv_C$ kalır; $x$'in integrali $x^2/2$ olduğundan:

$$w = \frac{1}{2}Cv_C^2$$

$Cv = Q$ ve $v = Q/C$ yazılırsa aynı enerji $w = \dfrac{Q^2}{2C}$ olarak da ifade edilir.

### 11.6 Şarj ve deşarj

Başlangıç yükü sıfır olan bir kondansatör bir direnç üzerinden DC kaynağa bağlanınca gerilimi üstel bir eğriyle artar (ekrandan, 02:10:00). Grafiklerde düşey eksen $V(t)/V_c$ (birimsiz), yatay eksen $t/\tau$'dur.

- **Şarj:** $t = 0$'da 0'dan başlar, önce hızlı, sonra giderek yavaşlayarak artar; $t \to \infty$'da asimptotik olarak $V_c$'ye ulaşır.
- **Deşarj:** $V_c$ başlangıç geriliminden başlar, önce hızlı, sonra yavaşlayarak azalır ve $t \to \infty$'da sıfıra yaklaşır. Plakalardaki zıt yükler birbirini çektiği için boşalma isteği zamanla azalır.

Hoca bu eğrileri şimdilik deneysel gözlem olarak verdi ve üstel bir fonksiyona benzediklerinden hareketle şu modeli kurdu:

$$\text{Şarj: } v(t) = V_c\left(1 - e^{-t/\tau}\right), \qquad \text{Deşarj: } v(t) = V_c\,e^{-t/\tau}, \qquad \tau = RC$$

Modelin sınır değerleri kontrol edildi: şarjda $t = 0$ için $1 - e^0 = 0$, $t \to \infty$ için $1 - 0 = 1$, yani $V_c$. Deşarjda $t = 0$ için $V_c$, $t \to \infty$ için sıfır. Bu denklemlerin matematiksel türetilmesi RC devreleri konusunda yapılacak.

Pratikte şarj ya da deşarj, $5\tau$ süre sonunda tamamlanmış kabul edilir (ekrandan, 02:15:00).

> **Ders sonrası not:** Hoca bir yerde süreyi "1 bölü RC'nin 5 katı" diye söyledi; doğrusu $5\tau = 5RC$'dir. Hoca birkaç dakika sonra $\tau$'yu $R$ ile $C$'nin çarpımı olarak düzeltti.

### 11.7 Paralel ve seri kondansatörler

**Paralel bağlantı:** Bir $i_{in}$ akım kaynağına paralel bağlı $C_1, \dots, C_N$ kondansatörleri aynı $v$ gerilimini görür. Düğümde $i_{in} = i_1 + i_2 + \dots + i_N$ ve her kolda $i_k = C_k\frac{dv}{dt}$:

$$i_{in} = (C_1 + C_2 + \dots + C_N)\frac{dv}{dt}$$

Bunların yerine tek bir $C_{eq}$ konunca $i_{in} = C_{eq}\frac{dv}{dt}$ olmalı; eşleştirince:

$$C_{eq} = C_1 + C_2 + \dots + C_N$$

**Seri bağlantı:** Bir $v_{in}$ kaynağına seri bağlı kondansatörlerden aynı $i$ akımı geçer. Çevre boyunca $v_{in} = v_1 + v_2 + \dots + v_N$ ve $v_k = \frac{1}{C_k}\int i\,dt$:

$$v_{in} = \left(\frac{1}{C_1} + \frac{1}{C_2} + \dots + \frac{1}{C_N}\right)\int i\,dt \quad\Rightarrow\quad \frac{1}{C_{eq}} = \frac{1}{C_1} + \frac{1}{C_2} + \dots + \frac{1}{C_N}$$

Dirençlerin tersine: paralel kondansatörler toplanır, seri kondansatörler dirençlerin paralel hesabı gibi birleştirilir.

## 12. Bobin

### 12.1 Yapı ve DC davranışı

Bobin (endüktans elemanı), bir çekirdek etrafına sarılmış iletkenden oluşur. Sargının içi boşsa çekirdek havadır, başka bir malzeme de olabilir. Bobin enerjiyi üzerinden geçen akımla depolar: sargıdan geçen akım bir manyetik alan oluşturur ve depolanan enerjiyi bu alan belirler. Enerjinin boşalması da akım değişimi olarak gerçekleşir.

Bobinin şematik gösterimi de bir sargıdır ve DC davranışını gösterir. DC koşullarda bobin sonuçta bir teldir:

- Bobin DC kararlı durumda **kısa devre** gibi davranır.
- Kondansatör DC kararlı durumda **açık devre** gibi davranır.

### 12.2 Tanım bağıntıları

Bobin üzerinde akım yönüyle aynı yönlü referansla bir gerilim tanımlanır; enerjisini boşaltırken bu gerilim ters yönlü (negatif) olur. Endüktansın birimi henry'dir (ekrandan, 02:25:00):

$$1\ \text{H} = 1\ \text{V·s/A}$$

Bobindeki manyetik akı, endüktans ve akımla orantılıdır: $\phi = Li$. Akıdaki değişim gerilimi oluşturur; iki tarafın türevi alınınca:

$$v_L = L\frac{di}{dt}, \qquad i_L = \frac{1}{L}\int_{t_0}^{t_1} v_L\,dt$$

Birim, $L = v_L\frac{dt}{di}$ yazılınca volt·saniye/amper olarak görülür.

**Güç ve enerji:** $p = v_L i_L$ ve depolanan enerji

$$w = \frac{1}{2}Li^2$$

### 12.3 Selenoidin endüktansı

Bir selenoidin endüktansı kesit alanına, malzemeye bağlı bir katsayıya, sargının uzunluğuna ve sarım sayısına bağlıdır. Malzemenin öz endüktans katsayısı, boşluğun referans değeri $\mu_0$'ın bağıl bir katsayıyla çarpılmasıyla bulunur. Birimlere bakılınca $\mu_0$'ın birimi H/m'dir.

<!-- BELİRSİZ: Selenoid formülünün slaytı karelerde görünmüyor; formül yazılmadı. -->

Anlamlı bir endüktans için sargı gerekir, ama pratikte düz tellerin de istenmeyen (parazitik) bir endüktansı vardır. Bunun etkisi daha çok elektronik ve haberleşme derslerinin konusudur.

### 12.4 Akımın sürekliliği

> **Hocanın vurgusu:** Kondansatörde gerilim nasıl sürekliyse bobinde de akım süreklidir. Bobin manyetik alanını bir anda çok büyük miktarda değiştiremez.

Bu özellik sonraki derslerde RL ve RC devrelerinde kullanılacak. Kaynak bir anahtarla devreye bağlandığında, anahtar kapanmadan hemen önceki ve hemen sonraki anlarda kondansatör gerilimi (bobinde akım) eşit olmalıdır. Bu sınır koşulu, çözümdeki belirsiz katsayıları bulmak için ek bir denklem sağlar.

### 12.5 Gerçek bobin modeli

Gerçek bir bobin tel olduğu için küçük de olsa bir direnç içerir; bu **seri** bir dirençle gösterilir. Sargının komşu sarımları arasında da kapasitif bir etki oluşur; bu çok küçük, parazitik bir **paralel** kapasiteyle gösterilir.

### 12.6 Seri ve paralel bobinler

**Seri bağlantı:** Hepsinden aynı akım geçer. $v_{in} = v_1 + \dots + v_N$ ve $v_k = L_k\frac{di}{dt}$:

$$v_{in} = (L_1 + L_2 + \dots + L_N)\frac{di}{dt} \quad\Rightarrow\quad L_{eq} = L_1 + L_2 + \dots + L_N$$

**Paralel bağlantı:** Bir $i_{in}$ akım kaynağına paralel bobinlerin hepsinde aynı $v$ gerilimi vardır (ekrandan, 02:35:00). $\phi = Li = \int v\,dt$ olduğundan $i_k = \frac{1}{L_k}\int v\,dt$:

$$i_{in} = \left(\frac{1}{L_1} + \frac{1}{L_2} + \dots + \frac{1}{L_N}\right)\int v\,dt \quad\Rightarrow\quad \frac{1}{L_{eq}} = \frac{1}{L_1} + \frac{1}{L_2} + \dots + \frac{1}{L_N}$$

Bobinlerde seri ve paralel birleştirme dirençlerdeki gibidir; kondansatörlerde dirençlerin tersidir.

## Örnek Sorular

### Soru 1: Network A'nın Thevenin eşdeğeri (ekrandan, 00:25:00)

12 V kaynak, seri 3 Ω, paralel 6 Ω ve seri 7 Ω'dan oluşan Network A'nın Thevenin eşdeğerini açık devre gerilimi ve kısa devre akımıyla bulun.

**Çözüm (derste verildi):** $V_{OC} = 12\cdot\frac{6}{9} = 8$ V. Kısa devrede düğüm denklemi $\frac{V-12}{3} + \frac{V}{6} + \frac{V}{7} = 0$, $V = 168/27 \approx 6.22$ V, $I_{SC} = V/7 = 8/9 \approx 0.889$ A. $R_{TH} = 8/(8/9) = 9$ Ω, $V_{TH} = 8$ V.

### Soru 2: 1 kΩ'luk direncin gördüğü devre (ekrandan, 00:40:00)

4 V, 2 kΩ, yukarı yönlü 2 mA ve 3 kΩ'dan oluşan devrenin 1 kΩ'luk yüke göre Thevenin ve Norton eşdeğerlerini bulun.

**Çözüm (derste verildi):** $V_{OC} = 4 + 0.002\cdot2000 = 8$ V, $R_{TH} = 2 + 3 = 5$ kΩ, $I_N = 8/5 = 1.6$ mA. Thevenin: 8 V ile seri 5 kΩ; Norton: 1.6 mA ile paralel 5 kΩ.

### Soru 3: Thevenin ve Norton eşdeğerleri (ekrandan, 00:45:00)

3 V kaynak, 2 kΩ, aşağı yönlü 7 mA, 5 kΩ ve terminale seri 1 kΩ'dan oluşan devrenin Thevenin ve Norton eşdeğerlerini bulun.

**Çözüm (derste verildi, Norton akımı slayttan):** $\frac{V-3}{2000} + 0.007 + \frac{V}{5000} = 0 \Rightarrow V_{TH} = -7.857$ V; $R_{TH} = 2\parallel5 + 1 = 2.429$ kΩ; $I_N = -3.235$ mA. Python ile kontrol edildi.

### Soru 4: Bağımlı kaynaklı Thevenin eşdeğeri (ekrandan, 00:50:00)

4 V, 2 kΩ, $v_x/4000$ bağımlı akım kaynağı ve 3 kΩ'dan oluşan devrenin açık terminallere göre Thevenin eşdeğerini bulun ($v_x$ terminal gerilimi).

**Çözüm (derste verildi):** $-4 + 2000(-v_x/4000) + v_x = 0 \Rightarrow V_{OC} = v_x = 8$ V. 1 V test kaynağıyla $\frac{V}{2000} - \frac{1}{4000} + \frac{V-1}{3000} = 0 \Rightarrow V = 0.7$ V, $I_{test} = 10^{-4}$ A, $R_{TH} = 10$ kΩ. Slayttaki yolla $I_{sc} = 0.8$ mA, $R_{TH} = 8/0.8\text{ mA} = 10$ kΩ.

### Soru 5: BJT kuvvetlendiricide maksimum güç (ekrandan, 01:30:00)

Ortak emetörlü BJT kuvvetlendirici modelinde ($2.5\sin440t$ mV, 300 Ω, 17 kΩ, 5 kΩ, $0.03v_\pi$, 1 kΩ) kuvvetlendiriciden en fazla gücü çekecek yük direncini seçin ve yükün çektiği gücü hesaplayın.

**Çözüm (derste verildi):** $R_{TH} = 1$ kΩ, dolayısıyla $R_L = 1$ kΩ. $v_{oc} = -30v_\pi$, $v_\pi = (2.5\times10^{-3}\sin440t)\frac{3864}{4164}$, $p_{max} = 1.211\sin^2440t$ μW.

### Soru 6: Süperpozisyonla $i_o$ (ekrandan, 01:35:00)

Devre:

- Sol dikey kol: yukarı yönlü 4 A akım kaynağı; alt ucu alt-orta düğüme (D), üst ucu üst-sol düğüme (A) bağlı.
- A ile sağ üst köşe arasında 2 Ω; sağ üst köşe sağ-orta düğüme (C) tel ile bağlı.
- A'dan orta-sol düğüme (B) 3 Ω.
- B'den sağa 1 Ω ve ardından $5i_o$ bağımlı gerilim kaynağı (+ ucu 1 Ω tarafında, − ucu C tarafında).
- B'den D'ye 5 Ω; $i_o$ bu dirençten aşağı doğru akan akım.
- C'den sağ alt köşeye (E) 4 Ω.
- Alt hatta D ile E arasında 20 V kaynak (+ ucu D tarafında, − ucu E tarafında).

İstenen: süperpozisyon kullanarak $i_o$.

Derste yalnız yol gösterildi (Bölüm 9.1).

> **Çözüm (derste verilmedi):** D referans alınıp düğüm analiziyle iki alt devre ayrı çözüldü (python ile). Yalnız 4 A etkinken (20 V kısa devre) $i_o' = 52/17 \approx 3.059$ A. Yalnız 20 V etkinken (4 A açık devre) $i_o'' = -60/17 \approx -3.529$ A. Süperpozisyon: $i_o = i_o' + i_o'' = -8/17 \approx -0.471$ A.

### Soru 7: Kaynak dönüşümüyle $v_x$ (derste sözlü, 01:36:37)

<!-- BELİRSİZ: Devre karelerde görünmüyor; yalnız hocanın anlattığı dönüşüm adımları ve denklemler biliniyor. -->

Kaynak dönüşümü kullanarak devredeki $v_x$ gerilimini bulun.

**Derste verilen yol:** Dönüşümlerden sonra tek çevre: $-3 + 5i + v_x + 18 = 0$ ve $-v_x + 4i + v_x + 18 = 0 \Rightarrow i = -4.5$ A.

> **Çözüm (derste verilmedi):** $v_x = 3 - 5(-4.5) - 18 = 7.5$ V.

### Soru 8: Bağımlı kaynaklı Thevenin eşdeğeri (ekrandan, 01:40:00)

Devre:

- Sol dikey kol: yukarı yönlü 5 A akım kaynağı (alt hat b ile üst-sol düğüm P arasında).
- P'den alt hatta 4 Ω; üzerindeki gerilim $v_x$ (+ üstte).
- P ile Q arasında 2 Ω; aynı iki düğüm arasında, 2 Ω'un üstünde $2v_x$ bağımlı gerilim kaynağı (− ucu P tarafında, + ucu Q tarafında).
- Q'dan alt hatta 6 Ω; Q'dan a terminaline seri 2 Ω; b terminali alt hat.

İstenen: a-b terminallerine göre Thevenin eşdeğeri.

Derste yalnız yol gösterildi (Bölüm 9.3).

> **Çözüm (derste verilmedi):** Bağımlı kaynak $V_Q - V_P = 2v_x = 2V_P$ verir, yani $V_Q = 3V_P$. Açık devrede P ve Q düğümlerine KCL yazılıp bağımlı kaynağın akımı yok edilince $5 = \frac{V_P}{4} + \frac{V_Q}{6}$, buradan $V_P = 20/3$ V ve $V_{OC} = V_Q = 20$ V. 5 A çıkarılıp a'ya 1 V test kaynağı bağlanınca $i_o = 1/6$ A, $R_{TH} = 6$ Ω. Sonuç: $V_{TH} = 20$ V, $R_{TH} = 6$ Ω (python ile kontrol edildi).

### Soru 9: Laboratuvar sözlü oturumundan: gerilim kaynağının ters bağlanması (derste sözlü, 03:37:35)

Dersten sonra kayda giren laboratuvar sözlü oturumunda, deney föyündeki "Şekil 6" devresi üzerinden sorular soruldu (ekrandan, 03:05:00). Devre:

- Sol dikey kol: $V_1$ kaynağı (+ ucu üstte).
- Üst kol: sol üst köşe ile sağ üst köşe arasında $R_5$.
- Orta yatay hat: sol düğüm → $R_1$ → orta düğüm → $R_2$ → sağ düğüm.
- Orta düğümden alt hatta $R_3$; sağ düğümden alt hatta $R_4$.
- Çevre akımları (hepsi saat yönünde): $I_a$ üstte ($R_5$, $R_2$, $R_1$), $I_b$ sol altta ($V_1$, $R_1$, $R_3$), $I_c$ sağ altta ($R_2$, $R_4$, $R_3$).
- Föydeki değerler: $R_1 = R_2 = 220$ Ω, $R_3 = R_4 = 100$ Ω, $R_5 = 470$ Ω, $V_1 = 5$ V.

Soru: Hiçbir değer değiştirilmeden yalnız $V_1$ ters bağlanırsa $I_a$, $I_b$, $I_c$ nasıl değişir?

> **Çözüm (derste tam verilmedi):** Devre doğrusaldır ve tek bağımsız kaynak vardır; bütün akımlar kaynakla orantılıdır. Kaynak ters çevrilince üç çevre akımının da yönü (işareti) değişir, büyüklükleri aynı kalır. Föy değerleriyle (python): $I_a \approx 8.45$ mA, $I_b \approx 24.65$ mA, $I_c \approx 10.29$ mA; ters bağlanınca $-8.45$, $-24.65$, $-10.29$ mA.

### Soru 10: Laboratuvar sözlü oturumundan: $R_5$'e paralel eş direnç (derste sözlü, 03:15:50)

Aynı Şekil 6 devresinde $R_5$'e paralel, değeri $R_5$'e eşit ikinci bir direnç eklenirse $I_a$ artar mı, azalır mı? Paralel iki dirençten geçen akımlar $I_a$ ile nasıl ilişkilidir?

> **Çözüm (derste tam verilmedi):** Paralel iki eş direncin eşdeğeri $R_5/2$'dir; üst çevrenin direnci azalır ve $I_a$ artar. Akım iki eş dirence eşit bölünür; her birinden $I_a/2$ geçer. Föy değerleriyle (python): $I_a$ yaklaşık $8.45$ mA'den $14.87$ mA'e çıkar; $I_b$ ($24.65 \to 30.56$ mA) ve $I_c$ ($10.29 \to 15.06$ mA) de artar.

## Dersin Toparlaması

Bu derste devre teoremlerinin son halkası olan Thevenin ve Norton eşdeğer devreleri tamamlandı. Doğrusal bir devrenin iki terminalden görülen davranışı tek bir gerilim kaynağı ve seri dirençle (Thevenin) ya da tek bir akım kaynağı ve paralel dirençle (Norton) temsil edilebilir; ikisi arasında kaynak dönüşümüyle geçilir. Eşdeğeri bulmak için dört yöntem görüldü: art arda kaynak dönüşümü, açık devre gerilimi ile kısa devre akımı, kaynakları sıfırlayıp eşdeğer direnç ve test kaynağı. Bağımlı kaynak içeren devrelerde güvenilir olan yöntem test kaynağıdır. Thevenin eşdeğeri üzerinden maksimum güç aktarımı türetildi: yük direnci Thevenin direncine eşit olduğunda yüke $V_{TH}^2/(4R_{TH})$ güç aktarılır.

Dersin ikinci yarısında enerji depolayan elemanlara geçildi. Kondansatör enerjiyi yük olarak depolar ($q = Cv$, $i = C\,dv/dt$, $w = \tfrac12 Cv^2$), DC'de açık devredir ve gerilimi süreklidir. Bobin enerjiyi manyetik alanda depolar ($\phi = Li$, $v = L\,di/dt$, $w = \tfrac12 Li^2$), DC'de kısa devredir ve akımı süreklidir. Kondansatörün şarj ve deşarjı $\tau = RC$ zaman sabitli üstel eğrilerle modellendi. Sonraki derste bu eğrilerin matematiksel türetmesi ve süreklilik koşullarının sınır koşulu olarak kullanıldığı RC ve RL devreleri işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
