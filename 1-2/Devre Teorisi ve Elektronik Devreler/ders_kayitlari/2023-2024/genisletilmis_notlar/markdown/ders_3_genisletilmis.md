# Ders 3 Genişletilmiş Notu: İkinci Dereceden Devreler: Sınır Koşulları, Kaynaksız ve Basamak Cevaplı Seri/Paralel RLC, Aşırı/Kritik/Az Sönüm

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birinci Dereceden İkinci Dereceye
- 2. Sınır Koşulları
- 3. Sınır Koşulu Örnekleri
- 4. Geçişin Üç Biçimi
- 5. Kaynaksız Seri RLC Devresi
- 6. Aşırı, Kritik ve Az Sönüm
- 7. Kaynaksız Paralel RLC Devresi
- 8. Basamak Cevabı

## 1. Birinci Dereceden İkinci Dereceye

### 1.1 Derece Ne Demek?

Hoca derse "derece" sözüyle neyi kastettiğimizi hatırlatarak başladı: Derece, devredeki türev alıcı elemanlarla ilgilidir. Şimdiye kadar gördüğümüz RC ve RL devrelerinde bir direnç ve bir kondansatör ya da bir direnç ve bir bobin vardı. Çözümde türevi oluşturan kısım kondansatörde

$$i_C = C\frac{dv_C}{dt},$$

bobinde ise

$$v_L = L\frac{di_L}{dt}$$

ilişkisinden geliyordu. Bobinli devrede KVL denkleminden, kondansatörlü devrede KCL denkleminden birer diferansiyel denklem çıkarıyorduk. Devrede tek bir türev alıcı eleman olduğu için bunlara birinci dereceden devre dedik.

### 1.2 İkinci Dereceden Devre

Bu hafta RLC devreleri ele alınıyor. Konunun adı ikinci dereceden devre çözümleridir (second order). İkinci dereceden denklemden kastımız, devrede iki kondansatör, iki bobin ya da bir kondansatör ve bir bobin bulunmasıdır.

Bir bobin ve bir kondansatör varsa, biri akım üzerinden, öteki gerilim üzerinden türev alır. Denklemi tek bir değişkene düşürmek istediğimizde türevin türevini almak zorunda kalırız. İkinci dereceden denklem buradan doğar. Hocanın deyişiyle "işin özü bu".

Birinci dereceden devrelerde geçişi üstel bir ifadeyle yazıyorduk. Hoca, RLC devrelerinde geçişin birebir bu şekilde çıkmayacağını, nedenini de formülleri kurarken göstereceğini söyledi.

Ders iki adımda ilerledi: Önce başlangıç ve son durumlar bulundu, sonra aradaki geçişin şekli incelendi.

## 2. Sınır Koşulları

### 2.1 Başlangıç ve Son Durum

Geçen hafta RL ve RC devrelerinde başlangıçtaki durum (initial state) ve sonsuzdaki durum (final state) için analiz yapmıştık. Aynı analizi burada da yapacağız. Bu kararlı hallere (steady state) sınır koşulları (boundary conditions) diyoruz, yani sınırdaki durumlar.

Şekillerde $t_0$ anı, devreye bir kaynağın eklendiği ya da devreden bir kaynağın çıkarıldığı anı gösterir. Sınır koşulları $t_0$ anının kendisini değil, ondan çok çok önceki ve çok çok sonraki durumu anlatır.

### 2.2 İki Kural

Başlangıç ve son durum analizinde iki kuralı aklımızda tutmamız gerekir:

- **Kondansatör açık devre** kabul edilir.
- **Bobin kısa devre** kabul edilir.

Hocanın tarif ettiği yöntem şöyledir:

1. $t_0$'dan çok önceki durum için devre yeniden çizilir: kondansatörler açık, bobinler kısa devre yapılır.
2. Bu devrede $v_C$, $i_C$, $v_L$, $i_L$ tek tek hesaplanarak başlangıç durumları bulunur.
3. $t_0$'dan çok sonraki durum için devre aynı kurallarla tekrar çizilir ve son değerler bulunur.

Böylece grafiğin nereden başlayıp nereye gittiğini biliriz. Aradaki geçişin şekli bu adımda cevaplanmaz.

### 2.3 Varsayımlar

Geçiş bölgesinin (transition) formülle bulunabilmesi için hoca iki kabul yaptı:

- Devreyi besleyen gerilim ya da akım kaynağı sabittir. Gerilim zamanla değişseydi hesap kolay bir hesap olmazdı.
- $t_0$ anının tam üzerinde akımda ve gerilimde bir değişim olmadığı kabul edilir.

### 2.4 Son Değer Neden Her Zaman Sıfır Değildir?

Sınır koşullarını hesaplamamızın nedeni şudur: Bir kondansatörü gerilimle besleyip kaynağı çıkardığımızda, kondansatör gerilimi sıfıra varacak demek değildir. Devrede başka bir gerilim kaynağı olabilir ve sıfıra varmasını engelleyebilir. Son değeri bu yüzden her devre için ayrıca bulmak gerekir.

> **Hocanın vurgusu:** Başlangıç ve son durumu bulmadaki en önemli iki kural şudur: kondansatör açık devre, bobin kısa devre. Devre bu iki kuralla çözülür.

## 3. Sınır Koşulu Örnekleri

### 3.1 Örnek 1: Gerilim Bölücü ve Boşalma

**Verilen:** $V_1$ kaynağı $R_1$ üzerinden bir düğüme bağlıdır. Düğümden toprağa $R_2$ gider. Düğümden $L_1$ ve $R_3$ üzerinden $C_1$'e gidilir. $V_1$, $t_0$ anında devreden çıkarılıyor. Bu örnekte sayısal değer kullanılmadı.

<!-- BELİRSİZ: Devrenin bağlantısı altyazıda sözlü ve eksik; bağlantı kısa nottan alındı. -->

**$t_0$'dan çok önce:** Bobin kısa devre, kondansatör açık devre yapılır. Kondansatörün olduğu kol açık olduğu için bu koldan akım geçmez, dolayısıyla bobin akımı sıfırdır. Kondansatörün şarj olacağı yer $R_2$ direnci üzerindeki gerilimdir, çünkü kol üzerindeki dirençte akım olmadığı için gerilim düşümü de yoktur (ara adım eklendi). $R_1$ ve $R_2$ burada bir gerilim bölücü oluşturur:

$$v_{C1}(-\infty) = v_{R2} = V_1\frac{R_2}{R_1 + R_2}, \qquad i_{L1}(-\infty) = 0.$$

Yani $v_C(t)$ grafiği çizilecekse başlangıç noktası bu değerdir. Akım grafiği ise sıfırdan başlar.

**$t_0$'dan çok sonra:** Gerilim kaynağı çıktığı için elimizde yalnızca $C_1$ üzerindeki gerilimin boşalacağı bir yapı kalır, başka kaynak yoktur. Kondansatör tamamen boşalır ve bobin akımı da sıfırda kalır:

$$v_{C1}(\infty) = 0, \qquad i_{L1}(\infty) = 0.$$

Hoca burada sınır değerlerini bulduğumuzu, ama aradaki geçişin nasıl olacağına henüz yorum yapmadığımızı belirtti.

### 3.2 Örnek 2: İki Gerilim Kaynağı

**Verilen:** $V_1 = 2$ V, $R_1 = 5$ kΩ, $C_1 = 1$ µF, $L_1 = 10$ µH, $R_2 = 5$ kΩ, $V_2 = 5$ V. $V_1$, $t_0$ anından sonra devreden çıkarılıyor. Devre $t_0$'dan önce uzun süre iki kaynakla beslenmiştir.

<!-- BELİRSİZ: Eleman değerleri (C1, L1) ve dizilim kısa nottan alındı; altyazıda yalnız 2 V, 5 V ve 5 kΩ değerleri okunuyor. -->

**$t_0$'dan çok önce:** Kondansatör açık devre, bobin kısa devre yapılınca geriye tek bir seri çevre kalır.

1. İki kaynak birbirine ters yönlüdür: net gerilim $5 - 2 = 3$ V.
2. Toplam direnç: $5\text{ k}\Omega + 5\text{ k}\Omega = 10$ kΩ.
3. Çevre akımı: $I = \dfrac{3\text{ V}}{10\text{ k}\Omega} = 0{,}3$ mA.
4. Her bir 5 kΩ'luk direnç üzerindeki gerilim: $0{,}3\text{ mA} \cdot 5\text{ k}\Omega = 1{,}5$ V.
5. Kondansatör gerilimi iki yoldan bulunur. 5 V tarafından: $5 - 1{,}5 = 3{,}5$ V. 2 V tarafından: $2 + 1{,}5 = 3{,}5$ V.

Sonuç: $v_C(-\infty) = 3{,}5$ V.

Akım yönü konusunda hoca, bulduğumuz akımın bobin akımı için seçilen yönün tersi olduğunu söyledi: $i_L(-\infty) = -0{,}3$ mA.

> **Ders sonrası not:** Slayttaki çözümde $i_L$ için $0{,}3$ mA yazıyordu. Hoca da bunu derste fark etti: Slayttaki ok yönüne göre doğrusu $-0{,}3$ mA'dır. Hocanın dediği gibi bu fark yalnız yönü belirler.

**$t_0$'dan çok sonra:** $V_1$'in olduğu kol açılınca yalnız 5 V kalır, devre de kondansatör nedeniyle açıktır. Akım geçmez, dirençte gerilim düşmez. Kararlı halde kalabilmesi için kondansatör gerilimi 5 V'a eşitlenmelidir:

$$v_C(\infty) = 5\text{ V}, \qquad i_L(\infty) = 0.$$

Grafiğimiz 3,5 V'tan başlayıp sonsuzda 5 V'ta sabitlenir. Akım grafiği $-0{,}3$ mA'den başlayıp sıfıra gider. Aradaki şekil geçiş analizinde ele alınacaktır.

Bu örneğin ara ve son değerleri python ile hesaplandı: 0,3 mA, 1,5 V, 3,5 V.

### 3.3 Örnek 3: İki Bobinli Devre

**Verilen:** $V_1 = 2$ V kaynağı $R_1 = 5$ kΩ üzerinden bir düğüme bağlanıyor. Düğümden toprağa $L_2 = 40$ µH gider. Düğümden $L_1 = 10$ µH ve $R_2 = 5$ kΩ üzerinden $V_2 = 5$ V'a gidilir. $V_1$, $t_0$ anında devreye ekleniyor, öncesinde yoktur.

<!-- BELİRSİZ: Bobin değerleri ve dizilim kısa nottan alındı; akım oklarının yönü altyazıda görülmüyor. -->

**$t_0$'dan çok önce:** İki bobin de kısa devre yapılır ve devrede yalnız 5 V vardır. 5 V, 5 kΩ üzerinden

$$\frac{5\text{ V}}{5\text{ k}\Omega} = 1\text{ mA}$$

akıtır. Ok yönlerine göre:

$$i_{L1}(-\infty) = -1\text{ mA}, \qquad i_{L2}(-\infty) = 1\text{ mA}.$$

> **Ders sonrası not:** Altyazıda bu akım bir yerde "bir amper" diye geçiyor; doğrusu python ile hesaplandı: 1 mA. Hoca hemen sonrasında 1 mA dedi.

**$t_0$'dan çok sonra:** Hocanın vurguladığı nokta burada akımın yoludur. Bobinler kısa devre olduğu için düğüm toprağa kısa devredir. Akım, dirençli yola değil kısa devre yoluna gider. Bu yüzden iki kaynağın akımları birbirini etkilemez (ara adım eklendi):

1. Sağ taraf: $V_2$ yine $R_2$ üzerinden $1$ mA verir, $i_{L1}(\infty) = -1$ mA.
2. Sol taraf: $V_1$, $R_1$ üzerinden $\dfrac{2\text{ V}}{5\text{ k}\Omega} = 0{,}4$ mA verir.
3. $L_2$'den ikisinin toplamı geçer: $i_{L2}(\infty) = 1 + 0{,}4 = 1{,}4$ mA.

Sonuç olarak $i_{L1}$'in sınır değerleri aynı kalır, $-1$ mA'den $-1$ mA'ye. $i_{L2}$ ise $1$ mA'den $1{,}4$ mA'ye geçer. Hoca burada da eğrinin düz mü gideceğini, salınım yaparak mı gideceğini sonra ele alacağını söyledi.

> **Ders sonrası not:** Hoca $i_{L1}$ için "değişim olmadan" dedi. Bu, sınır değerleri için doğrudur, geçiş sırasında akım sabit kalmaz. Bu devrenin denklemleri hocanın değerleriyle python ile çözüldü: $i_{L1}$, $-1$ mA'den yaklaşık $-0{,}84$ mA'ye çıkıp yeniden $-1$ mA'ye döner.

> **Ders sonrası not:** Hoca bu iki bobinli devre için salınım ihtimalini de andı, 4. bölümde de "iki kondansatör veya iki bobin" için aynı enerji alışverişinden söz etti. Bu devrenin kökleri python ile hesaplandı: $t_0$ sonrasında $s_1 \approx -5{,}86\times10^{7}$ 1/s ve $s_2 \approx -1{,}07\times10^{9}$ 1/s. İkisi de gerçek ve negatif olduğu için bu devre salınmaz. Salınımın yalnız L ve C birlikte varken görülmesi büyük olasılıkla genel bir durumdur.

### 3.4 Örnek 4: İki Kondansatörlü Devre

**Verilen:** $V_1 = 1$ V, $L_1 = 10$ µH, paralel $C_1 = C_2 = 1$ µF, 1 kΩ ve 3 kΩ'luk iki direnç, $V_2 = 5$ V. $V_2$, $t_0$ anında devreden çıkarılıyor. Yani $t_0$ öncesinde 5 V devrededir.

**$t_0$'dan çok önce:** Bobin kısa devre, kondansatörler açık devre yapılır.

1. 1 V ve 5 V ters yönlüdür: net gerilim $5 - 1 = 4$ V.
2. Toplam direnç: $3\text{ k}\Omega + 1\text{ k}\Omega = 4$ kΩ.
3. Akım: $\dfrac{4\text{ V}}{4\text{ k}\Omega} = 1$ mA.
4. Ok yönüne göre $i_{L1}(-\infty) = -1$ mA.
5. Hoca kondansatör gerilimini $v_C(-\infty) = 4$ V olarak verdi.

Hoca önce toplam direnci yalnız 1 kΩ alıp 4 mA dedi, sonra "pardon" diyerek kendi düzeltti: Direnç 4 kΩ, akım 1 mA'dir.

<!-- BELİRSİZ: Örnek 4'ün dizilimi altyazıdan ve kısa nottan kesin okunmuyor. Python ile hesaplandı: 1 mA akımda kondansatör düğümü 5 V'a 1 kΩ üzerinden bağlıysa v_C = 4 V, 3 kΩ üzerinden bağlıysa v_C = 2 V olur. Hocanın 4 V değeri ilk dizilime uyar; slayttan kontrol edilmeli. -->

**$t_0$'dan çok sonra:** 5 V çıkınca devrede hâlâ 1 V vardır. Bu yüzden son değer sıfıra gelmez. Kondansatör 1 V'a oturur, akım geçmez:

$$v_C(\infty) = 1\text{ V}, \qquad i_L(\infty) = 0.$$

Bu örnek, 2.4'teki uyarının somut hâlidir: Kaynak çıkınca her şey sıfıra gitmeyebilir.

## 4. Geçişin Üç Biçimi

Sınır koşullarından sonra hoca geçişlerin hesabına geçti. Dört analiz yapılacaktır:

- Kaynak uzun süre devredeyken çıkarılan **seri** RLC.
- Kaynak uzun süre devredeyken çıkarılan **paralel** RLC.
- Kaynak yokken $t_0$ anında kaynak eklenen **seri** RLC.
- Kaynak yokken $t_0$ anında kaynak eklenen **paralel** RLC.

Matematiği ne olursa olsun, sonuçta aradaki geçiş üç şekilde olabilir. Hoca bunu şöyle bir örnekle çizdi: Bir kondansatör gerilimi 1 V'tan başlasın, sonsuzda 10 V'ta sabit kalsın.

- **Kritik sönümlü (critically damped):** Doğrudan oturan karakteristik.
- **Aşırı sönümlü (overdamped):** Son değere daha çok sonra oturur.
- **Az sönümlü (underdamped):** Salınım yapar ama sonunda 10 V'a oturur.

<!-- BELİRSİZ: Hocanın çizdiği üç eğri altyazıda yalnız sözlü olarak geçiyor. -->

### 4.1 Neden Böyle Bir Davranış Var?

Devrede iki enerji depolayan birim vardır. Hoca bunu boşalma üzerinden anlattı, çünkü onu kafada canlandırmak daha kolaydır: Bir C ve bir L olsun, devreyi bir gerilim beslesin. Kararlı halde kondansatör bir değere şarj olur. Kaynak söküldüğünde kondansatör boşalmaya başlar, ama boşalırken bobini şarj eder. Bobin de sonra boşalırken kondansatörü besler.

Birbirini besleyen bir mekanizma olduğu için sistem salınım yapabilir ya da kararlı hale geç erişebilir. Üç duruma bu yüzden üç ayrı ad veriyoruz. Hangisinin oluşacağını, formülleri çıkardıktan sonra iki parametrenin birbirine göre büyüklüğünden anlayacağız.

## 5. Kaynaksız Seri RLC Devresi

### 5.1 Sınır Koşulları

$V_s$ kaynağı devrede uzun süredir vardır ve $t_0$ anında bir anahtarla devreden çıkarılıyor. Tek kaynak bu olduğu için sıfıra inme eğilimi bekliyoruz.

- **Başlangıç:** Kondansatör $V_s$'ye şarj olmuştur, $v_C = V_s$. Akım sıfırdır, bobin ve direnç gerilimi de sıfırdır.
- **Son:** Kaynak yoktur, bütün büyüklükler sıfıra gider.

> **Ders sonrası not:** Hoca akımın sıfır olmasını "kısa devre ettiğimiz için" diye söyledi. 2.2'deki kurala göre seri kolda akımı kesen, açık devre kabul edilen kondansatördür. Bobinin kısa devre olması akımı sıfır yapmaz.

Değişimini izleyeceğimiz büyüklük kondansatör gerilimidir. $V_s$'den sıfıra nasıl indiğini bulmak istiyoruz.

### 5.2 Denklemin Kurulması

Kaynak söküldükten sonra KVL yazılır. Hoca, polarizasyonu şarjdaki hâliyle bozmadan yazmak gerektiğini söyledi: Kondansatör, direnç ve bobin gerilimlerinin toplamı sıfırdır.

$$v_C(t) + R\,i(t) + L\frac{di(t)}{dt} = 0$$

Elemanlar seri olduğu için üçünden de aynı akım geçer: $i_L = i_R = i_C$. Hedefimiz akımı denklemden atıp yalnız $v_C$ bırakmaktır, çünkü değişen büyüklük odur. Kondansatör akımının formülü bilinir:

$$i = C\frac{dv_C}{dt}$$

Bunu yerine koyunca, $C$ sabit olduğu için türevin önüne çıkar ve türevin türevi oluşur:

$$LC\frac{d^2v_C}{dt^2} + RC\frac{dv_C}{dt} + v_C = 0$$

İkinci dereceden denklem işte budur. İkinci türevi yalnız bırakmak için $\frac{1}{LC}$ ile çarpılır. İkinci terimde $C$'ler sadeleşir:

$$\frac{d^2v_C}{dt^2} + \frac{R}{L}\frac{dv_C}{dt} + \frac{1}{LC}v_C = 0$$

Hocanın yorumu: $v_C$'leri bir kenara alırsak, davranışı belirleyen şey direncin, bobinin ve kondansatörün değerleridir.

### 5.3 Üstel Çözüm Kabulü ve Karakteristik Denklem

Denklemi çözmek için şu kabul yapılır:

$$v_C(t) = Ae^{st}$$

Burada $A$ bir katsayıdır, $s$ ise bulunacak parametredir. Türevleri kolaydır: İkinci türevde $s^2$, birinci türevde $s$ başa gelir.

$$As^2e^{st} + \frac{R}{L}Ase^{st} + \frac{1}{LC}Ae^{st} = 0$$

$Ae^{st}$ ortak paranteze alınır:

$$Ae^{st}\left(s^2 + \frac{R}{L}s + \frac{1}{LC}\right) = 0$$

Parantezin içi bilinen $ax^2 + bx + c$ yapısına benzer. Bu benzetmeyi yapmamızın nedeni, kökleri diskriminantla bulabilmektir:

$$x_{1,2} = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

### 5.4 $\alpha$, $\omega_0$ ve Kökler

Daha basit bir gösterim için iki parametre tanımlanır. Bunların adları önemlidir:

$$\alpha = \frac{R}{2L}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}$$

Hoca bu seçimlerin bir hile olduğunu açıkladı: $\alpha$'daki 2, kök formülündeki paydadaki 2'yi; $\omega_0$'ın karesi de kökün içindeki 4 ile 2'yi götürsün diye böyle seçilmiştir. Bu parametrelerle denklem şöyle yazılır:

$$s^2 + 2\alpha s + \omega_0^2 = 0$$

$\alpha$ ve $\omega_0$ yerine konursa önceki denklemin aynısı çıkar. Kökler:

$$s_1 = -\alpha + \sqrt{\alpha^2 - \omega_0^2}, \qquad s_2 = -\alpha - \sqrt{\alpha^2 - \omega_0^2}$$

$s_1$ ve $s_2$ doğal frekansları belirler. Her şeyi belirleyen iki parametre vardır:

- **$\omega_0$:** Yalnız enerji depolayan elemanların, yani L ve C'nin değerlerini kullanır. Buna rezonans frekansı ya da sönümsüz doğal frekans denir. Hocanın açıklaması, L ve C'nin birbirini besleme eğilimini gösterdiğidir.
- **$\alpha$:** Sönüm katsayısı (damping factor), yani sönümlendiren faktör. İçinde direnç vardır ve seri devrede direnç büyüdükçe $\alpha$ büyür.

$\alpha$ büyük olup $\omega_0$'ı geçerse kökün içi pozitif çıkar ve salınım olmaz. $\omega_0$ büyükse kökün içi negatif çıkar. Kökün içi negatif olunca $j$'li, yani karmaşık sayılı bir yapıya geçeriz. $s$'ler $e^{st}$ içinde kullanıldığı için $e^{j\ldots}$ terimi sinüs ve kosinüs doğurur, bu da salınım demektir. Hocanın özeti: $\omega_0$, $\alpha$'dan ne kadar büyükse sistem o kadar sallanarak oturur, ikisi eşitse kritik oturur.

> **Ders sonrası not:** Hoca burada "alfa çok büyükse underdamped oturur" dedi. Doğrusu: $\alpha > \omega_0$ ise aşırı sönümlüdür (overdamped). Az sönüm $\alpha < \omega_0$ durumudur. Hoca ilerleyen bölümde doğrusunu anlattı.

> **Ders sonrası not:** Hoca "$\omega_0$ ne kadar yüksekse sistem o kadar salınım yapar" dedi. Salınımın olup olmayacağını tek başına $\omega_0$ değil, $\alpha$ ile $\omega_0$'ın karşılaştırması belirler. Salınım varsa frekansı 6.3'te tanımlanan $\omega_d$'dir.

### 5.5 Genel Çözüm ve Katsayılar

İki farklı kök bulunduğunda her biri bir çözüm verir, gerçek çözüm ikisinin toplamıdır:

$$v_C(t) = A_1e^{s_1t} + A_2e^{s_2t}$$

> **Ders sonrası not:** Hoca bu iki terimi $v_{C1}(t)$ ve $v_{C2}(t)$ diye adlandırırken bir yerde "kondansatörün bir tanesinin üzerindeki gerilim" dedi. Hemen ardından söylediği gibi bunlar iki kökten gelen iki terimdir ve toplamları $v_C(t)$'yi verir. Seri devrede tek kondansatör vardır.

Bilinmeyen olarak $A_1$ ve $A_2$ kalır. Bunları bulmak basittir, başlangıç koşulları elimizdedir.

**Birinci denklem:** $t = 0$ anında kondansatör gerilimini biliyoruz, $V_s$'dir. $t = 0$ koymak demek $e^0 = 1$ demektir:

$$A_1 + A_2 = V_s$$

**İkinci denklem:** Akım için $i_C = C\frac{dv_C}{dt}$ kullanılır. $t = 0$ anında akım sıfırdır. Türev alınıp $t = 0$ konursa:

$$s_1A_1 + s_2A_2 = 0$$

$s_1$ ve $s_2$ önceki adımda bulunmuştu. İki bilinmeyen, iki denklem vardır, $A_1$ ve $A_2$ bulunur. Çözüm (ara adım eklendi):

$$A_1 = \frac{s_2V_s}{s_2 - s_1}, \qquad A_2 = \frac{-s_1V_s}{s_2 - s_1}$$

> **Ders sonrası not:** Hoca katsayıları "initial ve final" koşullardan bulacağımızı, ikinci denklem için "sonsuzdakine bakalım" dedi, sonra $t = 0$ anının türevini kullandı. Doğrusu, iki koşul da $t = 0$ anındadır. Sonsuzda iki üstel terim de sıfıra gittiği için son değer $A_1$ ve $A_2$ hakkında bilgi vermez.

Hoca, şarj ve deşarj için yapılan işlemlerin aynı olduğunu belirtti. Burada gösterilen deşarjdır: Gerilimden başlanır, sıfıra inilir, ama nasıl inileceği bu hesapla bulunur.

> **Hocanın vurgusu:** Bu formüllerin nasıl çıktığını evde kağıt kalemle kendiniz çözün. Ama gün sonunda bilmemiz gereken üç durumdur ve şarj için de deşarj için de bu üç durum uygulanır.

## 6. Aşırı, Kritik ve Az Sönüm

Geçişin hangi biçimde olacağını $\alpha$ ile $\omega_0$'ın karşılaştırması söyler.

### 6.1 Aşırı Sönüm: $\alpha > \omega_0$

$\alpha = \frac{R}{2L}$ olduğundan, hocanın anlattığı senaryoda devredeki direnç çok yüksektir. Direnç yüksek olunca bobin ve kondansatör birbirini yeteri kadar besleyemez, enerjilerini birbirine aktarabilecekleri yapı ortadan kalkar.

> **Ders sonrası not:** Hoca bu durumda "deşarjın çok hızlı olacağını" söyledi. Oysa aşırı sönüm son değere geç oturur. Python ile hesaplandı: $L$ ve $C$ sabitken $\alpha$ büyüdükçe yavaş kök $s_1$ sıfıra yaklaşır, yani kondansatör daha yavaş boşalır. Bunun nedeni büyük olasılıkla büyük direncin akımı da sınırlamasıdır.

Koşul kondansatör değeri üzerinden de yazılır. $\frac{R}{2L} > \frac{1}{\sqrt{LC}}$ eşitsizliğinde içler dışlar çarpımı yapılıp $C$ çekilirse:

$$C > \frac{4L}{R^2}$$

Bu durumda iki farklı kök çıkar. Kökün içi pozitiftir, ama $\alpha$'nın önündeki eksi nedeniyle iki kök de negatif ve gerçektir, karmaşık sayı yoktur. Çözüm doğrudan yazılır:

$$v_C(t) = A_1e^{s_1t} + A_2e^{s_2t}$$

$s_1, s_2$ ve $A_1, A_2$ bulunduktan sonra farklı $t$ değerleri denenerek eğri çizilir.

### 6.2 Kritik Sönüm: $\alpha = \omega_0$

Bu durumda kondansatör değeri tam olarak bobinin dört katının direncin karesine bölümüne eşittir:

$$C = \frac{4L}{R^2}$$

Kökün içi sıfır olur, ikinci bir kök oluşmaz:

$$s_1 = s_2 = -\alpha = -\frac{R}{2L}$$

Üstel terimin üssü negatif olduğu için $t$ büyüdükçe azalır ve eğri salınım yapmadan sönümlenir. Hoca özet slaytında kritik sönüm için "$A_1$ ile $A_2$'lerde $t$'yi çarpacağız" dedi. Çözüm:

$$v_C(t) = (A_1 + A_2t)e^{-\alpha t}$$

> **Ek bilgi (derste anlatılmadı):** Kökler eşit olunca $A_1e^{s_1t} + A_2e^{s_2t}$ tek bir terime, $(A_1 + A_2)e^{-\alpha t}$'ye iner ve iki başlangıç koşulunu birlikte sağlayamaz. Bu yüzden ikinci bağımsız çözüm olarak $te^{-\alpha t}$ gerekir. Kaynaksız seri devrede koşullar $A_1 = V_s$, $A_2 = \alpha V_s$ verir; bu çözüm diferansiyel denklemin sayısal çözümüyle karşılaştırıldı, python ile hesaplandı.

### 6.3 Az Sönüm: $\alpha < \omega_0$

Bu durumda koşul

$$C < \frac{4L}{R^2}$$

olur. Hoca senaryoyu şöyle anlattı: Direnç çok düşük. Kondansatör ve bobin kararlı halde tamamen şarj olmuş. Kaynak çıkınca devre boşalmak ister, ama R değeri çok düşüktür. Bu durumda L ve C birbirini besler ve salınım oluşur. Tam bir deşarj hemen gerçekleşmez, salınım zaman içinde sönümlenir.

> **Ders sonrası not:** Hoca bu senaryoda "kondansatör ve bobin değerleri çok yüksek" olduğu için $\omega_0$'ın büyük olduğunu söyledi. $\omega_0 = \frac{1}{\sqrt{LC}}$ olduğundan L ve C büyüdükçe $\omega_0$ küçülür. Koşul $C < \frac{4L}{R^2}$ olduğu için az sönüme götüren şey küçük R, büyük L ve küçük C'dir. Büyük C, aksine aşırı sönüme doğru iter. Koşulun $\alpha < \omega_0$ ile denkliği python ile hesaplandı.

Kökün içi negatif olduğu için işareti ters çevirip yeni bir parametre tanımlanır:

$$\omega_d = \sqrt{\omega_0^2 - \alpha^2}$$

Buna sönümlü doğal frekans denir. Kökün içindeki negatiflik $j$ ile gösterilir:

$$s_1 = -\alpha + j\omega_d, \qquad s_2 = -\alpha - j\omega_d$$

Bunları genel çözüme yazalım ve ortak $e^{-\alpha t}$'yi paranteze alalım:

$$v_C(t) = A_1e^{(-\alpha + j\omega_d)t} + A_2e^{(-\alpha - j\omega_d)t} = e^{-\alpha t}\left(A_1e^{j\omega_dt} + A_2e^{-j\omega_dt}\right)$$

$e^{j}$'li terim kosinüs ve sinüse açılır:

$$e^{j\omega_dt} = \cos\omega_dt + j\sin\omega_dt, \qquad e^{-j\omega_dt} = \cos\omega_dt - j\sin\omega_dt$$

Yerine konunca kosinüs ve sinüs katsayıları toplanır ve bunlara yeni parametreler atanır (ara adım eklendi): $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$. Sonuç:

$$v_C(t) = e^{-\alpha t}\left(B_1\cos\omega_dt + B_2\sin\omega_dt\right)$$

Kosinüs ve sinüs işin içine girdiği an açısal bir dalgalanma olacağı anlaşılır. $e^{-\alpha t}$ çarpanı ise bu dalgalanmayı zamanla söndürür. $\alpha$ sönümlendiren faktör olduğu için, sönümsüz frekans $\omega_0$ yerine salınım $\omega_d$ ile olur.

> **Ek bilgi (derste anlatılmadı):** $A_1$ ve $A_2$ karmaşık olsa da $B_1$ ve $B_2$ gerçek sayıdır. Kaynaksız seri devrede $v_C(0) = V_s$ ve akımın sıfır başlaması $B_1 = V_s$ ve $B_2 = \frac{\alpha V_s}{\omega_d}$ verir. Bu çözüm diferansiyel denklemin sayısal çözümüyle karşılaştırıldı, python ile hesaplandı.

### 6.4 Üç Eğrinin Karşılaştırılması

Hoca slaytta 1'den 0'a inen üç eğriyi gösterdi: Mavi aşırı sönümlü, yeşil kritik sönümlü, kırmızı az sönümlü. Hocanın yorumu şöyleydi:

- Aşırı sönümlü olmak, kararlı hale daha yakın olmak demek değildir. Eğri çok hızlı düşer, ama kararlı hale geç ulaşır. Yeşilin daha önce ulaştığı değere mavi daha ileride ulaşır.
- Kırmızı daha da ileride ulaşabilir, çünkü salınımın bitmesi gerekir.
- Kritik sönüm, düşüşün en yavaş olduğu çözüm olarak gösterildi, ama hedefe en çabuk varan odur.

<!-- BELİRSİZ: Slayttaki grafik altyazıda yalnız sözlü ve renklerle anlatılıyor. -->

> **Ders sonrası not:** Hocanın ana sonucu doğrudur: Son değere salınmadan en çabuk kritik sönüm oturur. "Aşırı sönüm başta çok hızlı düşer" kısmı ise bu dersteki devreye uymaz. Python ile hesaplandı: Aynı $\omega_0$ ve aynı başlangıçla ($v(0) = 1$, akım sıfır), aşırı sönümlü eğri her $t > 0$ anında kritik eğrinin üstünde kalır, yani daha yavaş düşer. En hızlı ilk düşüş az sönümlü eğrinindir. Denklem de bunu söyler: Akım sıfır başladığı için $t = 0$'da üç durumda da eğim sıfır, ikinci türev $-\omega_0^2 v(0)$'dır. Slayttaki grafik büyük olasılıkla başka başlangıç koşullarıyla ya da farklı $\omega_0$ ile çizilmiştir.

> **Ders sonrası not:** Örnek 2'deki "böyle mi gider, şöyle mi gider" sorusu derste bu devre için yanıtlanmadı. $t_0$ sonrası kalan seri çevrenin değerleri ($R = 5$ kΩ, $L = 10$ µH, $C = 1$ µF) ile python ile hesaplandı: $\alpha = 2{,}5\times10^{8}$ 1/s, $\omega_0 \approx 3{,}16\times10^{5}$ rad/s. $\alpha > \omega_0$ olduğu için devre aşırı sönümlüdür, kökler $s_1 \approx -200$ 1/s ve $s_2 \approx -5\times10^{8}$ 1/s'dir. Eğri 3,5 V'tan 5 V'a salınmadan gider.

### 6.5 Bilinmesi Gereken Üç Formül

> **Hocanın vurgusu:** RLC devresi, bu derste anlattığımız konular arasında en zor konudur, ama anlaşılması çok önemlidir. Anlatılanları evde tekrar tekrar kendiniz çıkarmaya çalışın.

Hocanın özeti şöyledir: Kondansatör gerilimini üç formülden biriyle yazacağız. Önce devredeki R, L, C değerleriyle $\alpha$ ve $\omega_0$ bulunur. Sonra durum belirlenir.

| Durum | Koşul | Kökler | $v_C(t)$ |
|---|---|---|---|
| Aşırı sönüm | $\alpha > \omega_0$ | gerçek, farklı, negatif | $A_1e^{s_1t} + A_2e^{s_2t}$ |
| Kritik sönüm | $\alpha = \omega_0$ | $s_1 = s_2 = -\alpha$ | $(A_1 + A_2t)e^{-\alpha t}$ |
| Az sönüm | $\alpha < \omega_0$ | $-\alpha \pm j\omega_d$ | $e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$ |

Grafik için formülde $t$ değiştirilerek başlangıçtan sona kadar birkaç nokta hesaplanır. $v_C(t)$ bulunduktan sonra öteki büyüklükler de bulunur: $i = C\frac{dv_C}{dt}$ ile akım, akımdan da $v_L = L\frac{di}{dt}$ ile bobin gerilimi.

Hoca, $\alpha = \frac{R}{2L}$ değerinin kaynaksız seri devreye ait olduğunu, KVL'den böyle çıktığını ve paralel devrede değişeceğini söyledi.

## 7. Kaynaksız Paralel RLC Devresi

### 7.1 Sınır Koşulları

Bu kez $t_0$ anında bir akım kaynağı $I_s$ devreden sökülüyor. Söküm öncesinde bobin kısa devre, kondansatör açık devre sayılır. Bu yüzden akımın tamamı bobinden geçer: $i_L = I_s$. Kaynak söküldükten sonra başka kaynak olmadığı için son durumda $i_L = 0$ olur. Yani bobin üzerinde $I_s$'ten başlayıp sıfıra inen bir akım grafiği bekleriz.

Serideki değişken $v_C$ idi, burada değişken $i_L$'dir.

### 7.2 Denklemin Kurulması

Düğüm analizi yapılır, üç kolun akımları toplamı sıfırdır:

$$i_R + i_L + i_C = 0$$

Üç eleman paralel olduğu için gerilimleri aynıdır: $v_R = v_L = v_C = v$. Bunu kullanarak yazarsak:

$$\frac{v}{R} + i_L + C\frac{dv}{dt} = 0$$

Bobinde $v = L\frac{di_L}{dt}$ olduğu biliniyor. Bu ifade $v$'nin yerine konulunca tek değişken $i_L$ kalır. Son terimde türevin türevi alındığı için ikinci türev, ilk terimde birinci türev gelir:

$$\frac{L}{R}\frac{di_L}{dt} + i_L + LC\frac{d^2i_L}{dt^2} = 0$$

Düzenlenince (ara adım eklendi):

$$\frac{d^2i_L}{dt^2} + \frac{1}{RC}\frac{di_L}{dt} + \frac{1}{LC}i_L = 0$$

### 7.3 Değişen Tek Şey $\alpha$

Seri devreyle karşılaştıralım. Birinci türevin katsayısı serideki $\frac{R}{L}$ yerine $\frac{1}{RC}$ olmuştur, son terim $\frac{1}{LC}$ aynıdır. Bu yüzden:

$$\alpha = \frac{1}{2RC}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}$$

Hocanın vurgusuyla, paralel olma durumu yalnız sönüm katsayısını değiştirir, bunun dışında her şey aynıdır.

> **Ek bilgi (derste anlatılmadı):** Paralel devrede $R$, $\alpha$'nın paydasındadır. Seride büyük direnç sönümü artırırken, paralelde küçük direnç sönümü artırır. Serideki $C > \frac{4L}{R^2}$ koşulunun paralel karşılığı $L > 4R^2C$'dir; $\alpha > \omega_0$ ile denkliği python ile hesaplandı.

Durumlar da serideki gibidir:

- **$\alpha > \omega_0$, aşırı sönüm:** İki negatif gerçek kök. $i_L(t) = A_1e^{s_1t} + A_2e^{s_2t}$.
- **$\alpha = \omega_0$, kritik sönüm:** Tek kök, $s_1 = s_2 = -\alpha$. $i_L(t) = (A_1 + A_2t)e^{-\alpha t}$.
- **$\alpha < \omega_0$, az sönüm:** $s_{1,2} = -\alpha \pm j\omega_d$ ve $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$. $i_L(t) = e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$.

Akım bulunduktan sonra devredeki gerilimler aynı şekilde bulunur.

> **Hocanın vurgusu:** Bu karşılaştırma seri ya da paralel fark etmeden aynıdır: Sönüm katsayısı $\alpha$ büyükse aşırı sönüm, eşitse kritik sönüm, salınımı sağlayan $\omega_0$ büyükse az sönüm olur. Fark yalnız $\alpha$ formülündedir: paralelde $\frac{1}{2RC}$, seride $\frac{R}{2L}$.

## 8. Basamak Cevabı

Basamak cevabı (step response), devrede hiçbir kaynak yokken devreye bir gerilim ya da akım kaynağı bağlandığında oluşan geçiştir. Hoca, çözümlerde değişen bir şey olmadığı için bu bölümü hızlı geçtiğini söyledi. Üç durum aynıdır: $\alpha = \omega_0$ kritik, $\omega_0 > \alpha$ az, $\alpha > \omega_0$ aşırı sönüm.

### 8.1 Seri RLC Basamak Cevabı

$t_0$ anında $V_s$ devreye dahil oluyor. Son durumda bobin kısa, kondansatör açık devre sayılır.

$$v_C(0) = 0, \qquad v_C(\infty) = V_s$$

Değişen büyüklük yine gerilimdir, bu yüzden kondansatör analizi yapılır. Formülde tek bir şey değişir: KVL'ye $-V_s$ girer.

$$v_R + v_L + v_C - V_s = 0$$

Aynı işlemler yapılınca denklemin sol tarafı birebir aynı çıkar, sağ tarafta bir sabit kalır:

$$\frac{d^2v_C}{dt^2} + \frac{R}{L}\frac{dv_C}{dt} + \frac{1}{LC}v_C = \frac{V_s}{LC}$$

> **Ders sonrası not:** Altyazıda bu sabit "$V_s$ bölü RC" diye geçiyor. Doğrusu $\frac{V_s}{LC}$'dir, kısa not da böyle yazar. Bu denklemin çözümü üç durumda aşağıdaki formüllerle karşılaştırıldı, python ile hesaplandı.

Parametreler aynı kalır: $\alpha = \frac{R}{2L}$, $\omega_0 = \frac{1}{\sqrt{LC}}$. Çözüme yalnız son değer eklenir:

- **Aşırı sönüm:** $v_C(t) = V_s + A_1e^{s_1t} + A_2e^{s_2t}$
- **Kritik sönüm:** $v_C(t) = V_s + (A_1 + A_2t)e^{-\alpha t}$
- **Az sönüm:** $v_C(t) = V_s + e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$

Hocanın gerekçesi basittir: Varmamız gereken nokta $V_s$'dir. Formülde $t$ yerine sonsuz koyduğumuzda üstel terimler sıfıra gider ve sonuç $V_s$ olmalıdır. Hoca, matematik olarak da böyle olduğunu ekledi, çünkü sonsuzda üreteç devrede kalır.

Katsayılar yine başlangıç koşullarından bulunur. Burada $v_C(0) = 0$ ve akım sıfır olduğu için aşırı sönümde koşullar şöyle olur (ara adım eklendi):

$$V_s + A_1 + A_2 = 0, \qquad s_1A_1 + s_2A_2 = 0$$

### 8.2 Paralel RLC Basamak Cevabı

$t_0$ anında akım kaynağı $I_s$ devreye alınıyor. Şekildeki kısa devre ortadan kalkar ve kaynak devreyi beslemeye başlar. Bobin akımı sıfırdan başlar, sonsuzda bobin kısa devre sayıldığı için kaynak akımının tamamını taşır:

$$i_L(0) = 0, \qquad i_L(\infty) = I_s$$

Bu kez değişen büyüklük akım olduğu için akım analizi yapılır. KCL'de tek değişiklik, önceden sıfıra eşitlenen toplamın artık kaynak akımına eşitlenmesidir:

$$i_R + i_L + i_C = I_s$$

Denklem (ara adım eklendi):

$$\frac{d^2i_L}{dt^2} + \frac{1}{RC}\frac{di_L}{dt} + \frac{1}{LC}i_L = \frac{I_s}{LC}$$

$\alpha = \frac{1}{2RC}$ ve $\omega_0 = \frac{1}{\sqrt{LC}}$ değişmez. Tek fark, çözüme $I_s$ eklenmesidir:

- **Aşırı sönüm:** $i_L(t) = I_s + A_1e^{s_1t} + A_2e^{s_2t}$
- **Kritik sönüm:** $i_L(t) = I_s + (A_1 + A_2t)e^{-\alpha t}$
- **Az sönüm:** $i_L(t) = I_s + e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$

## Dersin Toparlaması

Bu derste iki enerji depolayan elemanın bir arada olduğu devreleri inceledik. Önce kondansatörü açık, bobini kısa devre sayarak geçişten çok önceki ve çok sonraki değerleri bulduk. Kaynak çıksa da başka bir kaynak varsa son değerin sıfır olmadığını gördük. Sonra seri devrede KVL, paralel devrede KCL ile ikinci dereceden denklemi kurduk. $e^{st}$ kabulüyle karakteristik denkleme, oradan $\alpha$ ve $\omega_0$ parametrelerine ulaştık. İkisinin karşılaştırılması aşırı, kritik ya da az sönümden hangisinin oluşacağını belirler. Seriyle paralel arasındaki tek fark $\alpha$'nın formülüdür. Basamak cevabında ise çözüme son değer eklenir.

Hoca dualite konusunu işlemedi ve bu konudan sorumlu olunmadığını söyledi. Sonraki hafta Yunus Hoca, RLC, RL, RC ile Thevenin ve Norton konularında soru çözecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
