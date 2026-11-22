# Ders 10 Genişletilmiş Notu: İkinci Dereceden Devreler: Sınır Koşulları ve RLC Geçiş Cevabı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birinci Dereceden Devrelerden İkinci Dereceden Devrelere
- 2. Sınır Koşulları (Boundary Conditions)
- 3. Sınır Koşulu Örnekleri
- 4. RLC Devrelerinde Geçiş: Neden Farklı?
- 5. Kaynaksız Seri RLC Devresi
- 6. Üç Cevap Türü: Aşırı, Kritik ve Az Sönümlü
- 7. Diğer Akım ve Gerilimlerin Bulunması
- 8. Kaynaksız Paralel RLC Devresi
- 9. Kaynak Eklendiğinde: Seri ve Paralel RLC Basamak Cevabı
- 10. Dualite ve RC Devresiyle Karşılaştırma
- Örnek Sorular
- Dersin Toparlaması

## 1. Birinci Dereceden Devrelerden İkinci Dereceden Devrelere

Önceki derslerde birinci dereceden (first order) devreler işlenmişti. "Birinci derece" adı, devre denklemindeki birinci türevden gelir. Bu devreler enerji depolayan devrelerdir: bobinli ya da kondansatörlü devreler. Bobinde akım üzerinden çalışıldığında $v_L = L\,di_L/dt$, kondansatörde gerilim üzerinden çalışıldığında $i_C = C\,dv_C/dt$ bağıntısı kullanılır. İkisi de denkleme birinci türevi getirir.

Birinci dereceden devrelerde yapılan iş, tek bir kondansatörün ya da tek bir bobinin şarj ve deşarjını incelemekti. Şarjda $1 - e^{-t/\tau}$ biçimli, deşarjda başlangıç değerinden azalan $e^{-t/\tau}$ biçimli ifadeler elde edilmişti.

Bu derste ikinci dereceden (second order) devrelere geçilir. Burada türevin de türevi, yani ikinci türev ortaya çıkar. İkinci dereceden bir devrede enerji depolayan iki eleman vardır:

- bir bobin ve bir kondansatör (seri ya da paralel bağlı),
- iki bobin,
- iki kondansatör.

Birinci dereceden devrelere RC ve RL devreleri denmişti. İkinci dereceden devrelere genelde RLC devreleri denir: kondansatör, bobin ve direnç üzerinden geçiş (transition) analizi yapılır.

> **Hocanın vurgusu:** İkinci dereceden devreler birinci dereceden devrelerin üzerine kurulur. Önceki dersteki tek kondansatörlü ve tek bobinli devreler iyi anlaşılmadıysa o kayıt yeniden izlenmelidir.

Geçişten kastedilen şudur: devreyi besleyen bir gerilim ya da akım kaynağı devreden çıkarılır ya da devreye eklenir. Bu değişiklik devredeki gerilim ve akımları değiştirir; bobin ve kondansatördeki enerjinin bu değişimle nasıl geçiş yaptığı incelenir.

## 2. Sınır Koşulları (Boundary Conditions)

### 2.1 Başlangıç ve son durum

Geçişi incelemeden önce iki durumun bilinmesi gerekir. Bunlara sınır koşulları (boundary conditions) denir:

- Başlangıç (initial) durumu: anahtar $t_0$ anında değişiyorsa, bundan çok çok önceki durum ($t < t_0$).
- Son (final) durumu: geçiş bittikten çok sonraki, sonsuzdaki durum ($t = \infty$).

Bu iki durum da devrenin kararlı hale (steady state) ulaştığı durumlardır. Derste kullanılan slayt bunu şöyle özetler (ekrandan, 00:25:00):

- Kararlı halde, yani $t = \pm\infty$ arasındaki bütün zamanlarda ($t_0$'dan sonraki kısa geçiş süresi dışında):
  - kondansatörler açık devredir,
  - bobinler kısa devredir.
- $t = t_0$ anındaki geçişte:
  - kondansatör gerilimi süreklidir: $v_C(t_0^+) = v_C(t_0^-)$,
  - bobin akımı süreklidir: $i_L(t_0^+) = i_L(t_0^-)$.

### 2.2 Açık devre ve kısa devre kuralı

Kondansatörü açık devre yapmak, üzerinden akım geçmediğini ($i_C = 0$) kabul etmek demektir. Bu durumda kondansatörde biriken gerilim hesaplanır. Bobini kısa devre yapmak, üzerinde gerilim oluşmadığını ($v_L = 0$) kabul etmek demektir. Bu durumda bobinden geçen akım hesaplanır. Örneğin devreye $t_0$ anında 5 V'luk bir kaynak bağlandıysa son durumu hesaplarken kondansatörler açık devre, bobinler kısa devre yapılır.

> **Hocanın vurgusu:** Bu iki kural hem başlangıç hem son durum için uygulanır ve karıştırılmamalıdır. Hoca sınavlarda bobini açık devre, kondansatörü kısa devre yapan çok öğrenci gördüğünü söyledi; doğrusu bunun tersidir.

### 2.3 Geçiş anı için kabul

$t_0$ anındaki hesap geçiş (transition) hesabıdır. Burada kondansatörün giriş beslemesi tarafından gerilimle, bobinin de akımla beslendiği kabul edilir. Geçiş anında bağlantının kopması gibi bir durumda bobin ani bir gerilim darbesine, kondansatör ani bir akıma yol açabilir. Bu tür durumlar konu dışıdır. Geçiş, dışarıdan başka bir etki olmayan saf bir geçiş olarak incelenir.

Geçiş iki biçimde olabilir: devrede bir kaynak vardır ve çıkarılır, ya da kaynak yoktur ve bağlanır. Kaynak bağlanırsa son durumda kondansatör bir gerilime, bobin de bir akıma ulaşır. Kaynak sökülürse bunun tersi olur.

## 3. Sınır Koşulu Örnekleri

Her örnekte istenen, geçişin kendisi değil, başlangıç ve son durumlardır ("Find the boundary conditions").

### 3.1 Örnek 1: Kondansatör gerilim bölücüye şarj olur

Devre (ekrandan, 00:30:00): $V_1$ kaynağı, ona seri $R_1$; $R_1$'den sonra toprağa $R_2$; aynı düğümden sağa doğru seri $L_1$ ve $R_3$, en sağda toprağa $C_1$. $t_0$ anında anahtar açılır ve $V_1$ devreden çıkar.

Başlangıç durumu ($t < t_0$): kondansatör açık devre (slaytta "$\infty\,\Omega$" olarak gösterilmiş), bobin kısa devre yapılır.

- $C_1$ açık devre olduğu için $L_1$ ve $R_3$ kolundan akım geçmez: $i_L(-\infty) = i_L(t_0^-) = 0$ A.
- Bobin kısa devre: $v_L(-\infty) = v_L(t_0^-) = 0$ V.
- Kondansatör açık devre: $i_C = 0$.
- Kondansatör gerilimi: kondansatörün uçları, akım geçmeyen $L_1$-$R_3$ kolu üzerinden $R_2$'ye paraleldir. Devre bir gerilim bölücüye döner:

$$v_C(t_0^-) = V_1\,\frac{R_2}{R_1 + R_2}$$

Son durum ($t = \infty$): $V_1$ çıktıktan sonra yalnız sağ taraf kalır ve orada besleme yoktur. Kondansatör $R_2$ ve $R_3$ üzerinden sönümlenerek boşalır: $v_C \to 0$, $i_C = 0$, $i_L = 0$, $v_L = 0$. Hoca, sağ tarafta örneğin 2 V'luk bir kaynak daha olsaydı $v_C$'nin sıfıra değil 2 V'a gideceğini belirtti.

> **Hocanın vurgusu:** Kondansatör başlangıçta ya da sonda doğrudan giriş gerilimine şarj olmaz. Bu örnekte $V_1$'e değil $V_1R_2/(R_1+R_2)$'ye şarj olur. Kondansatörün uçlarının neye paralel olduğuna bakmak gerekir.

### 3.2 Örnek 2: İki zıt kaynak

Devre (ekrandan, 00:35:00): $V_1 = 2$ V, seri $R_1 = 5$ kΩ; ortada toprağa $C_1$; sağa doğru $L_1 = 10\,\mu$H ve $R_2 = 5$ kΩ; en sağda $V_2 = 5$ V. $I_L$ oku soldan sağa çizilmiştir. $t_0$ anında sol kol (2 V'luk kaynak) açılır.

Başlangıç ($t < t_0$):

- Kondansatör açık devre, bobin kısa devre. Kaynaklar birbirine zıt olduğu için net gerilim $5 - 2 = 3$ V'tur.
- Toplam direnç $5 + 5 = 10$ kΩ, akım $3\text{ V}/10\text{ kΩ} = 0{,}3$ mA.
- Akım 5 V'luk kaynaktan 2 V'luk kaynağa, yani sağdan sola akar. Şekildeki $I_L$ okuna göre $i_L(t_0^-) = -0{,}3$ mA olur. Hoca slaytta 0,3 yazıldığını ama okun yönüne göre bunun $-0{,}3$ olması gerektiğini söyledi.
- $v_L = 0$ (kısa devre), $i_C = 0$ (açık devre).
- Kondansatör gerilimi, orta düğümün gerilimidir ve iki yoldan bulunur:
  - soldan: $2\text{ V} + 0{,}3\text{ mA}\cdot 5\text{ kΩ} = 3{,}5$ V,
  - sağdan: $5\text{ V} - 0{,}3\text{ mA}\cdot 5\text{ kΩ} = 3{,}5$ V.

Son durum ($t = \infty$): sol kol devreden çıkar ama sağda hâlâ 5 V'luk kaynak vardır. Kondansatör açık devre olduğu için akım geçmez: $i_L = 0$, $i_C = 0$, $v_C = 5$ V.

Sonuç olarak anahtar açılınca kondansatör gerilimi 3,5 V'tan 5 V'a çıkar, bobin akımı $-0{,}3$ mA'den 0'a iner. Nasıl değiştiği geçiş hesabının konusudur.

Hoca sonucu sezgiyle de açıkladı: sonda kondansatör 5 V'a şarj olur, iki uç arasında potansiyel fark kalmadığı için akım geçmez. Başlangıçta ise iki kaynak ters bağlı olduğu ve kondansatör 3,5 V'ta olduğu için küçük bir akım akar.

> **Ders sonrası not:** Hoca bu akımı bir yerde "0,3 amper" diye söyledi. Dirençler kΩ olduğu için doğrusu 0,3 mA'dir (python ile doğrulandı).

### 3.3 Örnek 3: İki bobin

Devre (ekrandan, 00:40:00): $V_2 = 5$ V, seri $R_2 = 5$ kΩ ve $L_1 = 10\,\mu$H; sol tarafta toprağa $L_2 = 40\,\mu$H. $I_{L1}$ oku sağa (dirence doğru), $I_{L2}$ oku aşağı çizilmiştir. $t_0$ anında 2 V'luk bir kaynak devreye eklenir; $t < t_0$'da bu kaynak yoktur.

<!-- BELİRSİZ: 2 V'luk kaynağın bağlandığı kolun şekli karede görünmüyor; hocanın hesabından bu kolda 5 kΩ'luk bir direnç olduğu ve L2'ye paralel bağlandığı anlaşılıyor. -->

Başlangıç ($t < t_0$): bobinler kısa devredir. Akım $5\text{ V}/5\text{ kΩ} = 1$ mA olur. Akım $L_1$'den $I_{L1}$ okunun tersine, $L_2$'den okun yönünde geçer:

- $i_{L1}(t_0^-) = -1$ mA,
- $i_{L2}(t_0^-) = +1$ mA.

Son durum ($t = \infty$): iki kaynak vardır, süperpozisyon kullanılır.

- 2 V'luk kaynağın katkısı: $2\text{ V}/5\text{ kΩ} = 0{,}4$ mA.
- 5 V'luk kaynağın katkısı: $5\text{ V}/5\text{ kΩ} = 1$ mA.
- $i_{L2}(\infty) = 0{,}4 + 1 = 1{,}4$ mA.
- $i_{L1}$ yalnız 5 V'luk kolu taşır: $i_{L1}(\infty) = -1$ mA.

Sonuç: $i_{L1}$ $-1$ mA'de kalır, $i_{L2}$ 1 mA'den 1,4 mA'e çıkar.

### 3.4 Örnek 4: İki kondansatör ve bir bobin

Bu örnekte iki kondansatör ve bir bobin vardır. Kondansatörler arasında başka bir eleman olmadığı için ikisi aynı gerilime şarj olur. 1 V ve 5 V'luk iki kaynak birbirine zıt bağlıdır, dirençler 3 kΩ ve 1 kΩ'dur. Anahtar $t_0$ anında açılır, öncesinde kapalıdır.

<!-- BELİRSİZ: Örnek 4'ün devre şekli karelerde yok; eleman yerleşimi altyazıdan kuruldu (1 V'luk kaynak 3 kΩ ile, 5 V'luk kaynak 1 kΩ ile kondansatör düğümüne bağlı; anahtar 5 V'luk tarafı ayırıyor). -->

Başlangıç ($t < t_0$):

- Net gerilim $5 - 1 = 4$ V, toplam direnç $3 + 1 = 4$ kΩ, akım 1 mA. Şekildeki yöne göre $i_L = -1$ mA.
- Kondansatör gerilimi: $1\text{ V} + 1\text{ mA}\cdot 3\text{ kΩ} = 4$ V ya da $5\text{ V} - 1\text{ mA}\cdot 1\text{ kΩ} = 4$ V. Yani $v_C = 4$ V.

Hoca burada 5 - 1 = 4 sonucunun akımın 1 mA çıkması ve değerlerin uygun olmasından kaynaklandığını, her zaman böyle çıkmayacağını, hesabın mutlaka yapılması gerektiğini söyledi.

Son durum: anahtar açılınca sağ taraf (5 V'luk kaynak) devreden çıkar. Kondansatörler 1 V'a şarj olur, açık devre nedeniyle akım sıfır olur: $v_C = 1$ V, $i_L = 0$.

### 3.5 Özet

Sınır koşulları hesaplanırken (ekrandan, 00:45:00):

- devredeki gerilim ve akım kaynaklarının basamak geçişinden önceki ve sonraki değerleri bilinmelidir,
- kararlı halde ($t < t_0$ ve $t = \infty$) kondansatör açık devre ($i_C = 0$), bobin kısa devre ($v_L = 0$) yapılır,
- kondansatör gerilimi ve bobin akımı hesaplanır,
- geçiş anında kondansatör gerilimi ve bobin akımı süreklidir.

## 4. RLC Devrelerinde Geçiş: Neden Farklı?

Yalnız direnç ve kondansatörden oluşan bir RC devresinde kaynak çekilince kondansatör direnç üzerinden azalarak boşalır. Bu devrede yaklaşık $5\tau$ sonra bütün yükün boşaldığı söylenir; deşarj $V_0 e^{-t/\tau}$, şarj $V_0(1 - e^{-t/\tau})$ ile verilir. Direnç enerji depolamaz, yalnız tüketir. Bu yüzden RC ve RL devrelerinde tek soru, hangi zaman ölçeğinde tam şarj ya da tam deşarj olunacağıdır.

RLC devresinde durum farklıdır. Kaynak çekilince kondansatör başlangıç gerilimini boşaltır, ama bu deşarj akımıyla bobin enerji depolar. Bobin depoladığı akımla kondansatörü yeniden şarj edebilir. Bu karşılıklı besleme bir salınıma (hoca "rezonans, salınım" dedi) yol açar. RLC geçişinde incelenen şey, bobin ile kondansatör arasındaki bu etkileşimdir.

Geçiş, $R$, $L$ ve $C$ değerlerine bağlı olarak üç farklı karakteristik gösterir:

- Aşırı sönümlü (overdamped),
- Kritik sönümlü (critically damped),
- Az sönümlü, sönüm altı (underdamped).

Derste önce kaynağın devreden çıkarıldığı durum (kaynaksız, source-free), sonra kaynağın devreye eklendiği durum incelenir.

## 5. Kaynaksız Seri RLC Devresi

### 5.1 Devre ve sınır koşulları

Devre (ekrandan, 00:50:00): kaynak $V_s[1 - u(t - t_0)]$, seri $R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF. $1 - u(t - t_0)$ ifadesi, $t_0$ anında açılan bir anahtar anlamına gelir: kaynak $t_0$'da devreden çıkar.

Başlangıçta kondansatör açık devre, bobin kısa devredir. Kondansatör giriş gerilimine şarj olur: $v_C = V_s$. Açık devre nedeniyle $i_L = 0$, ayrıca $v_L = 0$, $i_C = 0$. Kaynak çıktıktan sonra devrede besleme kalmadığı için sonsuzda her şey sıfıra gider. Bobin akımı başta da sonda da sıfırdır; arada bobin ile kondansatör arasında bir etkileşim olur. Başlangıçla son durum arasında değişen tek şey kondansatör gerilimi olduğu için geçiş denklemi $v_C$ üzerinden yazılır.

### 5.2 Diferansiyel denklemin çıkarılması

Anahtar açıldıktan hemen sonraki durum için KVL yazılır (ekrandan, 00:55:00):

$$\sum v(t) = 0 \quad\Rightarrow\quad v_C(t) + L\frac{di_L(t)}{dt} + R\,i_L = 0$$

Seri devrede bütün elemanlardan aynı akım geçer: $i_L(t) = i_C(t)$. Kondansatör akımı $i_C(t) = C\,dv_C(t)/dt$ olduğundan her terim $v_C$ cinsinden yazılabilir. Bobin teriminde türevin içine bir türev daha girer:

$$LC\frac{d^2v_C(t)}{dt^2} + RC\frac{dv_C(t)}{dt} + v_C(t) = 0$$

Her iki taraf $LC$'ye bölünür:

$$\frac{d^2v_C(t)}{dt^2} + \frac{R}{L}\frac{dv_C(t)}{dt} + \frac{1}{LC}v_C(t) = 0$$

"İkinci derece"nin anlamı budur: bobinin akımı kondansatör akımına eşit, o da $C\,dv_C/dt$ olduğu için türevler iç içe girer. $RC\,dv_C/dt$ terimi RC devresinden tanıdık kısımdır; ikinci türevi getiren bobindir.

### 5.3 Karakteristik denklem

Çözüm için $v_C(t) = Ae^{st}$ konur. $t$'ye göre türev almak üstteki $s$'yi katsayı olarak öne getirir: birinci türevde $sAe^{st}$, ikinci türevde $s^2Ae^{st}$. Ortak çarpan $Ae^{st}$ paranteze alınınca

$$Ae^{st}\left(s^2 + \frac{R}{L}s + \frac{1}{LC}\right) = 0$$

kalır. Bir çarpım sıfırsa çarpanlardan biri sıfırdır; $Ae^{st}$ sıfır olamayacağına göre parantez sıfıra eşitlenir. Hoca bu ifadeyi $a^2 + 2ab + b^2$ kalıbına benzeterek iki parametre tanımladı. Kökler için ikinci dereceden denklemin diskriminant formülü kullanılır.

**Soru (hoca sınıfa):** Diskriminant neydi? **Cevap:** $b^2 - 4ac$; kökler $\dfrac{-b \pm \sqrt{b^2 - 4ac}}{2a}$ ile bulunur. İki kökün kaynağı formüldeki $\pm$ işaretidir.

Derste kullanılan kompakt gösterim (ekrandan, 01:00:00):

$$s^2 + 2\alpha s + \omega_0^2 = 0, \qquad \alpha = \frac{R}{2L}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}$$

$$s_1 = -\alpha + \sqrt{\alpha^2 - \omega_0^2}, \qquad s_2 = -\alpha - \sqrt{\alpha^2 - \omega_0^2}$$

Slayttaki tanımlar:

- $s_1$ ve $s_2$ doğal frekanslardır (natural frequencies), saniyede neper (Np/s) ile ölçülür, çünkü devrenin doğal cevabıyla ilişkilidir.
- $\omega_0$ rezonans frekansı ya da sönümsüz doğal frekanstır (undamped natural frequency), rad/s ile ölçülür.
- $\alpha$ neper frekansı ya da sönüm katsayısıdır (damping factor), Np/s ile ölçülür.

Hoca $\alpha$ ve $\omega_0$'ı ayrı ayrı yazmanın, karakteristik denkleme göre çalışmanın daha mantıklı olduğunu söyledi; $\alpha$ ve $\omega_0$ yerine konunca diskriminanttan çıkan köklerle aynı sonuç elde edilir.

> **Hocanın vurgusu:** $\alpha$ ve $\omega_0$ kondansatör geriliminin boşalması için en kritik iki parametredir. $\alpha$ sönümlendirici faktördür; devrede bir şeyi sönümlendiren dirençtir ve $\alpha$ büyüdükçe gerilim daha çok sönümlenir. $\omega_0$ bobinin etkisiyle oluşan salınımı temsil eder.

### 5.4 Genel çözüm ve katsayılar

İki kök bulununca (ekrandan, 01:10:00):

$$v_{C1}(t) = A_1 e^{s_1\Delta t}, \qquad v_{C2}(t) = A_2 e^{s_2\Delta t}$$

$$v_C(t) = v_{C1}(t) + v_{C2}(t) = A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t}$$

Burada $\Delta t$, $t_0$'dan itibaren geçen süredir; doğrudan $t$ diye de yazılabilir.

$A_1$ ve $A_2$ katsayıları başlangıç koşullarından bulunur:

1. $t_0$ anında kondansatör gerilimi $V_s$'dir. $\Delta t = 0$ konunca üstel terimler 1 olur: $A_1 + A_2 = V_s$.
2. $t_0$ anında kondansatör akımı sıfırdır. $i_C = C\,dv_C/dt$ olduğu için ifadenin türevi alınır; türevde $s_1$ ve $s_2$ öne gelir, $\Delta t = 0$'da üsteller 1 olur: $s_1A_1 + s_2A_2 = 0$.

$s_1$ ve $s_2$ önceki adımda bulunduğundan, iki bilinmeyenli iki denklemden $A_1$ ve $A_2$ çekilir.

## 6. Üç Cevap Türü: Aşırı, Kritik ve Az Sönümlü

Cevabın türü $\alpha$ ile $\omega_0$'ın karşılaştırılmasıyla belirlenir:

- $\alpha > \omega_0$: aşırı sönümlü,
- $\alpha = \omega_0$: kritik sönümlü (sınırda sönümlü),
- $\alpha < \omega_0$: az sönümlü (sönüm altı).

### 6.1 Aşırı sönümlü durum

$\alpha > \omega_0$ koşulu seri devre için $C$ cinsinden yazılabilir (hocanın tahtadaki adımları):

$$\frac{R}{2L} > \frac{1}{\sqrt{LC}} \;\Rightarrow\; \frac{R^2}{4L^2} > \frac{1}{LC} \;\Rightarrow\; C > \frac{4L}{R^2}$$

Yani kondansatör değeri $4L/R^2$'den büyük seçilirse devre aşırı sönümlüdür. Bu durumda karekök içi pozitiftir, iki farklı reel kök vardır. $s_1$ ve $s_2$ formülden hesaplanır, sonra $A_1$ ve $A_2$ bulunur. Sınavda "Bu devre nasıl bir karakteristikle sönümlenir, sönüm eğrisini çizin" gibi bir soru gelirse önce türü bulunur, sonra formül elde edilip birkaç farklı $t$ değeri için eğri çizilir.

### 6.2 Kritik sönümlü durum

$\alpha = \omega_0$ olduğunda karekök içi sıfırdır ve iki kök birbirine eşittir: $s_1 = s_2 = -\alpha$. Hoca bu durumda çözümü $A_1e^{-\alpha t} + A_2e^{-\alpha t}$ diye yazıp "biraz yanlış olmuş" dedi.

> **Ders sonrası not:** Kritik sönümlü durumun doğru çözümü slayttaki özet tablosunda (ekrandan, 01:55:00) verildiği gibi $v(t) = e^{-\alpha t}(A_1 t + A_2)$'dir. Çift kökte iki terimi aynı üstelle yazmak tek bir bağımsız çözüm verir; ikinci bağımsız çözüm $te^{-\alpha t}$'dir.

### 6.3 Az sönümlü durum

Az sönümlü durum en sorunlu durumdur: devre salınım yapar ve kararlı bir değere hemen oturamaz. $C < 4L/R^2$ ise bu durum oluşur (ekrandan, 01:15:00). Hoca kuramsal olarak $R = 0$ olsaydı devrenin sonsuza kadar sönümlenmeden salınacağını söyledi; gerçekte kablonun bile direnci olduğu için bu olmaz.

> **Ders sonrası not:** Hoca $R = 0$ durumunda sonsuz salınımı "bobinin değeri kondansatörden fazlaysa" ya da "C, L'nin dört katından azsa" gibi bir koşula bağladı. $R = 0$ ise $\alpha = 0$ olur ve $\alpha < \omega_0$ her zaman sağlanır; $L$ ile $C$ arasında ek bir koşul gerekmez.

$\alpha < \omega_0$ iken karekök içi negatiftir. Negatif sayının karekökü $j$ ile dışarı çıkarılır ($j = \sqrt{-1}$; slayta göre matematikçiler sanal sayılar için $i$ kullanır). Yeni bir parametre tanımlanır (ekrandan, 01:15:00):

$$\omega_d = \sqrt{\omega_0^2 - \alpha^2}$$

$$s_1 = -\alpha + j\omega_d, \qquad s_2 = -\alpha - j\omega_d$$

Bu kökler genel çözüme konur ve $e^{-\alpha\Delta t}$ ortak paranteze alınır (ekrandan, 01:20:00):

$$v_C(t) = e^{-\alpha\Delta t}\left(A_1e^{j\omega_d\Delta t} + A_2e^{-j\omega_d\Delta t}\right)$$

Euler bağıntıları kullanılır:

$$e^{j\theta} = \cos\theta + j\sin\theta, \qquad e^{-j\theta} = \cos\theta - j\sin\theta$$

Yerine yazılınca

$$v_C(t) = e^{-\alpha\Delta t}\left[A_1(\cos\omega_d\Delta t + j\sin\omega_d\Delta t) + A_2(\cos\omega_d\Delta t - j\sin\omega_d\Delta t)\right]$$

Kosinüsler ve sinüsler ayrı ayrı paranteze alınır:

$$v_C(t) = e^{-\alpha\Delta t}\left[(A_1 + A_2)\cos\omega_d\Delta t + j(A_1 - A_2)\sin\omega_d\Delta t\right]$$

$B_1 = A_1 + A_2$ ve $B_2 = j(A_1 - A_2)$ tanımlanınca az sönümlü durum için sonuç:

$$v_C(t) = e^{-\alpha\Delta t}\left[B_1\cos\omega_d\Delta t + B_2\sin\omega_d\Delta t\right]$$

$B_1$ ve $B_2$ (yani $A_1$, $A_2$) yine başlangıçtaki kondansatör gerilimi ve akımından bulunur. Slayttaki grafik, $e^{-t}$ zarfı içinde salınan ve periyodu $2\pi/\omega_d$ olan bir eğri gösterir.

Hoca $\omega_0$'ın salınıma neden olan parametre olduğunu tekrarladı; $\omega_d$'ye de İngilizce adıyla sönümlü doğal frekans dendiğini belirtti.

> **Ders sonrası not:** Hoca $\omega_d$'yi bir yerde "salınımı sönümlendiren parametre" diye tarif etti. $\omega_d$ sönümlü doğal frekanstır (damped natural frequency), yani sönüm altında kalan salınımın açısal frekansıdır. Genliğin azalmasını $e^{-\alpha t}$ zarfı, yani $\alpha$ belirler.

### 6.4 Üç cevabın grafikte karşılaştırılması

Slayttaki grafikte (ekrandan, 01:25:00) üç eğri de 1'den başlayıp sıfıra iner (kaynak çekilmiş, kondansatör boşalıyor):

- Mavi eğri, aşırı sönümlü cevap: başta hızlı düşer, ama sıfıra daha geç oturur.
- Yeşil eğri, kritik sönümlü cevap: başta daha yavaş düşer, ama kararlı hale (sıfıra) en erken ulaşır.
- Kırmızı eğri, az sönümlü cevap: sıfırın altına iner (yaklaşık $-0{,}38$'e kadar), sonra yeniden yükselir ve salınarak oturur.

Hoca bunu şöyle özetledi: kritik sönümlü cevap daha geç düşer ama dengeye daha erken gelir; aşırı ve az sönümlü cevaplar daha erken düşer ama dengeye daha geç gelir. Aşırı sönümlüde gevşek bir yaklaşma, az sönümlüde salına salına oturma vardır.

**Soru:** Grafiğin üzerinden biraz daha geçilebilir mi? **Cevap:** Hoca "optimum seviye"nin kararlı hal, yani artık değişim göstermeyen denge durumu olduğunu açıkladı. RC ya da RL devresinde denge basittir: kaynak yoksa direnç enerjiyi tüketir ve gerilim sıfıra iner. RLC devresinde bobin ile kondansatör birbirini beslediği için denge, değişimin durduğu an olarak anlaşılır. Kırmızı eğride $\omega_0 > \alpha$, yani $1/\sqrt{LC} > R/(2L)$'dir: bobin-kondansatör ikilisi dirençten baskındır ve direnç salınımı hemen bastıramaz, ama sonunda direnç etkisiyle salınım söner. Mavi eğride $\alpha > \omega_0$'dır: direncin etkisi büyüktür ve şarj-deşarj etkileşimini erkenden bastırır. Yeşil eğride devre tam dengededir ($R/(2L) = 1/\sqrt{LC}$).

Hoca, $R = 0$ olduğunda enerjinin bobin ile kondansatör arasında ileri geri aktarılacağını ("shifted back and forth") ve sonsuza kadar salınım olacağını söyledi; az sönümlü cevaplara osilasyon (salınım) etkisi gösteren cevaplar dendiğini ekledi.

## 7. Diğer Akım ve Gerilimlerin Bulunması

Kondansatör gerilimi $v_C(t)$ bulunduktan sonra $t > t_0$ için diğer büyüklükler şu bağıntılarla hesaplanır (ekrandan, 01:30:00):

$$i_C(t) = C\frac{dv_C(t)}{dt}, \qquad i(t) = i_C(t) = i_L(t) = i_R(t)$$

$$v_L(t) = L\frac{di_L(t)}{dt}, \qquad v_R(t) = R\,i_R(t)$$

Hoca örnek bir soru biçimi verdi: $s_1$, $s_2$, $A_1$, $A_2$ bilindiğinde "$t = 0{,}2$ s anında bobin akımını bulun" denirse, önce $v_C(t)$ ifadesinden $i_C = C\,dv_C/dt$ hesaplanır ve $t = 0{,}2$ s konur. Seri devrede $i_C = i_L = i_R$ olduğundan bobin akımı bulunmuş olur. Direnç gerilimi istenirse $v_R = R\,i_R$, bobin gerilimi istenirse $v_L = L\,di_L/dt$ kullanılır. Hocanın önerisi, önce kondansatör akımını bulup akım üzerinden ilerlemektir.

## 8. Kaynaksız Paralel RLC Devresi

### 8.1 Bir soru: kondansatör neye şarj olur?

Aradan sonra bir soru üzerine hoca kuralı yeniden açıkladı.

**Soru:** Kondansatör tam olarak hangi elemanla şarj oluyor? **Cevap:** Kondansatör uçlarına uygulanan gerilime şarj olur. Kondansatör açık devre yapıldığında, açık devrenin uçlarının hangi kapalı devreye, hangi dirence bağlı olduğuna bakılır; bir dirence paralelse o direncin gerilimine şarj olur.

### 8.2 Devre ve sınır koşulları

Paralel RLC devresinde (ekrandan, 01:45:00 ve 01:50:00) bir akım kaynağı $I_s$, paralel bağlı $R = 2$ kΩ, $L = 10$ µH ve $C = 3$ µF'ı besler. Hoca paralel devrelerde akım kaynağı kullanıldığını, kaynak dönüşümüyle seri biçime geçilebileceğini belirtti. $t_0$ anında kaynak devreden çıkarılır.

Başlangıç ($t < t_0$): kondansatör açık devre, bobin kısa devre yapılır. Akım her zaman direnci olmayan yolu tercih ettiği için kaynağın bütün akımı bobinden geçer:

- $i_L(t_0^-) = I_s$,
- $i_C = 0$,
- bobin kısa devre olduğu için paralel elemanların gerilimi sıfırdır: $v_C = 0$, dirençten akım geçmez.

Hoca bunu ara sınavda sorulan kısa devre sorularına benzetti: bir direncin üzerinden kısa devre bağlantısı varsa akım dirence değil kısa devreye gider.

Son durum: kaynak çıkınca devrede besleme kalmaz; bobindeki $I_s$ akımı deşarj olur ve $i_L(+\infty) = 0$ olur. Bu durumda değişen büyüklük bobin akımı olduğu için denklem $i_L$ üzerinden, KCL ile yazılır.

### 8.3 Diferansiyel denklem

Kaynak çıktıktan sonra düğümdeki akımların toplamı sıfırdır (ekrandan, 01:50:00):

$$i_R(t) + i_L(t) + i_C(t) = 0$$

Paralel devrede bütün elemanların gerilimi aynıdır: $v(t) = v_R(t) = v_L(t) = v_C(t)$. Buna göre

$$\frac{v_R(t)}{R} + i_L(t) + C\frac{dv_C(t)}{dt} = 0$$

Bütün gerilimler bobin gerilimine eşit olduğundan $v_L(t) = v(t) = L\,di_L(t)/dt$ her yere yazılır. Kondansatör teriminde yine türevin türevi oluşur:

$$LC\frac{d^2i_L(t)}{dt^2} + \frac{L}{R}\frac{di_L(t)}{dt} + i_L(t) = 0$$

$$\frac{d^2i_L(t)}{dt^2} + \frac{1}{RC}\frac{di_L(t)}{dt} + \frac{i_L(t)}{LC} = 0$$

Hoca genel kuralı şöyle verdi: başlangıç ile son durum arasında hangi büyüklük değişiyorsa denklem onun üzerinden kurulur. Seri devrede kondansatör gerilimi, paralel devrede bobin akımı değişir.

### 8.4 Parametreler ve çözüm

Paralel devrede tek fark $\alpha$'dadır:

$$\alpha = \frac{1}{2RC}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}$$

$\omega_0$ yine aynı LC yapısından geldiği için değişmez. Üç durumun ölçütleri, $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ kökleri, az sönümlü durumda $\omega_d$ tanımı ve $\cos$-$\sin$ biçimli çözüm aynen geçerlidir. Katsayılar yine $t_0$ anındaki değerlerden bulunur. Akım bulununca bobin gerilimi $v_L = L\,di_L/dt$ ile, paralel olduğu için bu gerilimden direnç ve kondansatör büyüklükleri de bulunur.

> **Ders sonrası not:** Hoca paralel devreye geçerken seri devredeki $\alpha$'yı bir yerde "L bölü 2R" diye söyledi. Seri devrede doğrusu $\alpha = R/(2L)$'dir; slayttaki tabloda da böyledir.

### 8.5 Özet tablosu

Kaynaksız RLC devreleri için özet tablo (ekrandan, 01:55:00):

| Durum | Ölçüt | $\alpha$ (paralel / seri) | $\omega_0$ | Cevap |
|---|---|---|---|---|
| Aşırı sönümlü | $\alpha > \omega_0$ | $\frac{1}{2RC}$ / $\frac{R}{2L}$ | $\frac{1}{\sqrt{LC}}$ | $A_1e^{s_1t} + A_2e^{s_2t}$, $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ |
| Kritik sönümlü | $\alpha = \omega_0$ | $\frac{1}{2RC}$ / $\frac{R}{2L}$ | $\frac{1}{\sqrt{LC}}$ | $e^{-\alpha t}(A_1t + A_2)$ |
| Az sönümlü | $\alpha < \omega_0$ | $\frac{1}{2RC}$ / $\frac{R}{2L}$ | $\frac{1}{\sqrt{LC}}$ | $e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ |

Az sönümlü satırda $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$'dir. Hoca tabloyu şöyle yorumladı: aşırı sönümlüde iki kök bulunup denkleme yazılır; kritik sönümlüde $\alpha = \omega_0$ olduğu için karekök sıfırdır ve tek kök $-\alpha$'dır; az sönümlüde $j\omega_d$ üzerinden $\cos$ ve $\sin$ içeren bir ifade bulunur.

## 9. Kaynak Eklendiğinde: Seri ve Paralel RLC Basamak Cevabı

### 9.1 Ne değişir?

**Soru (hoca sınıfa):** Kaynağı çıkarmak yerine eklediğimizde ne değişir? **Cevap:** Başlangıç ve son durumlar değişir. Kaynak çıkarılan durumda kondansatör başta şarjlı ya da bobin başta akım taşıyordu ve sonda sönümleniyordu. Kaynak eklenen durumda başta sıfırdır, sonda bir değere yüklenir.

> **Hocanın vurgusu:** Hoca bu kısımdan sınavda soru gelebileceğini söyledi ve konunun iyi çalışılmasını istedi.

### 9.2 Seri RLC: gerilim kaynağı bağlanıyor

Devre (ekrandan, 02:00:00): kaynak $V_s u(t - t_0)$, seri $R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF. Başlangıçta devrede hiçbir şey olmadığı için $v_C = 0$; sonda kondansatör $V_s$'ye şarj olur. Kondansatör açık devre olduğu için başta da sonda da akım geçmez, bobinde değişiklik yoktur; incelenen, $v_C$'nin 0'dan $V_s$'ye geçişidir.

KVL'de bu kez kaynak da yer alır. Elemanlar tüketen, kaynak üreten olarak yazıldığı için kaynak $-V_s$ ile girer:

$$v_C(t) + L\frac{di_L(t)}{dt} + R\,i_L - V_s = 0$$

$i_L = i_C = C\,dv_C/dt$ konunca

$$LC\frac{d^2v_C(t)}{dt^2} + RC\frac{dv_C(t)}{dt} + v_C(t) = V_s$$

$$\frac{d^2v_C(t)}{dt^2} + \frac{R}{L}\frac{dv_C(t)}{dt} + \frac{1}{LC}v_C(t) = \frac{V_s}{LC}$$

Slaytta çözüm $v_C(t - t_0) = v_t(t - t_0) + v_{ss}(t - t_0)$ diye, yani geçici kısım ile kararlı hal kısmının toplamı olarak yazılmıştır. $\omega_0 = 1/\sqrt{LC}$ ve $\alpha = R/(2L)$ aynıdır. Aşırı sönümlüde iki üstel, kritik sönümlüde $e^{-\alpha t}$'li ifade, az sönümlüde $\cos$-$\sin$'li ifade kullanılır.

Fark yaratan son koşuldur: kaynak çıkarıldığında ulaşılan değer sıfırken burada $V_s$'dir. Yani $t \to \infty$ limitinde $v_C(t) \to V_s$ olmalıdır; $t_0$ anında ise $v_C = 0$'dır. Katsayılar bu koşullardan bulunur. $v_C$ bulunduktan sonra diğer akım ve gerilimler yine kondansatör akımı üzerinden hesaplanır.

### 9.3 Paralel RLC: akım kaynağı bağlanıyor

Paralel devrede $t_0$ anında akım kaynağı devreye girer. Başta bobinden akım geçmezken sonsuzda bobin akımı $I_s$'ye ulaşır: $i_L$ 0'dan $I_s$'ye bir geçiş gösterir.

KCL'de düğüme giren akım çıkanlara eşit olmalıdır. Bu yüzden toplam artık sıfıra değil $I_s$'ye eşitlenir:

$$I_s = i_R + i_L + i_C$$

Düzenlenince denklemin sağ tarafında $I_s/(LC)$ oluşur. $\omega_0 = 1/\sqrt{LC}$, $\alpha = 1/(2RC)$ aynıdır; üç durumdan hangisinin geçerli olduğu yine bunlara göre bulunur. Tek fark, $t \to \infty$'da $i_L$'nin $I_s$'ye eşit olmasını sağlayacak biçimde çözüme $I_s$'nin eklenmesidir.

Özet slaytına göre (ekrandan, 02:05:00): paralel RLC'de bobin akımı için $t > t_0$ çözümleri elde edilir; bobin akımının son koşulu kararlı hal çözümüdür; denklem seçimi $\omega_0$ ile $\alpha$ karşılaştırılarak yapılır; katsayılar denklemin ve birinci türevinin $t = t_0^-$ ve $t = \infty$'daki değerlerinden bulunur; $t < t_0$'da bobin akımı başlangıç koşuluna eşittir. Akım-gerilim ilişkileriyle bobin gerilimi ve kondansatör ile direncin büyüklükleri de hesaplanır.

## 10. Dualite ve RC Devresiyle Karşılaştırma

Hoca dualite (eşdeğerlik) kavramından kısaca söz etti ama ayrıntıya girmedi: direncin iletkenlikle (conductance), bobinin kondansatörle karşılıklı bir eşdeğerliği vardır.

Son olarak RC devresiyle karşılaştırma yaptı. RC devresinde şarj eğrisi $V_0(1 - e^{-t/\tau})$, $\tau = RC$ ile verilir. Hocanın gösterdiği grafikteki örnekte (değerler altyazıdan) $R = 1$ kΩ ve $C = 2$ mF için $\tau = 2$ s'dir ve yaklaşık $5\tau = 10$ s sonra kondansatörün dolması beklenir; grafikte de eğri buraya yakın oturur. RC ve RL devreleri direnç üzerinden sönümlendiği için böyle davranır. RLC devrelerinde şarj eğrisi biraz salınıp oturabilir (az sönümlü), hızla yükselip geç oturabilir (aşırı sönümlü) ya da en kısa sürede oturabilir (kritik sönümlü). Birbirini besleyen iki enerji depolayan eleman olduğu için bu üç durum ayrı ayrı incelenir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Şekildeki devrede $V_1$ kaynağı $R_1$ üzerinden düğüme bağlıdır; düğümden toprağa $R_2$, düğümden sağa seri $L_1$ ve $R_3$, sonra toprağa $C_1$ bağlıdır. Anahtar $t_0$ anında açılıp $V_1$'i devreden çıkarıyor. Sınır koşullarını bulun.

> **Çözüm (derste verildi):** $t < t_0$'da $C_1$ açık, $L_1$ kısa devre: $i_L(t_0^-) = 0$, $v_L(t_0^-) = 0$, $i_C = 0$, $v_C(t_0^-) = V_1R_2/(R_1 + R_2)$. $t = \infty$'da kaynak olmadığı için $v_C = 0$, $i_L = 0$, $i_C = 0$, $v_L = 0$.

**Soru 2** (ekrandan, 00:35:00): $V_1 = 2$ V, $R_1 = 5$ kΩ, $C_1$, $L_1 = 10$ µH, $R_2 = 5$ kΩ, $V_2 = 5$ V devresinde 2 V'luk kol $t_0$'da açılıyor. $i_L$ (oku soldan sağa) ve $v_C$ için başlangıç ve son değerleri bulun.

> **Çözüm (derste verildi):** Başlangıç: $|i| = (5 - 2)/(10\text{ kΩ}) = 0{,}3$ mA, okun tersine olduğu için $i_L = -0{,}3$ mA; $v_C = 2 + 0{,}3\cdot 5 = 3{,}5$ V. Son: $i_L = 0$, $v_C = 5$ V.

**Soru 3** (ekrandan, 00:40:00): $V_2 = 5$ V, $R_2 = 5$ kΩ, $L_1 = 10$ µH ve $L_2 = 40$ µH'lik devreye $t_0$'da 2 V'luk bir kaynak ekleniyor. $i_{L1}$ ve $i_{L2}$'nin başlangıç ve son değerlerini bulun.

<!-- BELİRSİZ: 2 V'luk kaynağın kolu karede görünmüyor; hocanın hesabına göre 5 kΩ üzerinden L2'ye paralel bağlı. -->

> **Çözüm (derste verildi):** Başlangıç: $i_{L1} = -1$ mA, $i_{L2} = 1$ mA. Son (süperpozisyon): $i_{L2} = 2/5\text{k} + 5/5\text{k} = 1{,}4$ mA, $i_{L1} = -1$ mA.

**Soru 4** (derste sözlü, 00:42:06): İki kondansatör ve bir bobinden oluşan, 1 V ve 5 V'luk zıt kaynakların 3 kΩ ve 1 kΩ üzerinden beslediği devrede anahtar $t_0$'da açılıp 5 V'luk tarafı ayırıyor. Sınır koşullarını bulun.

<!-- BELİRSİZ: Devre şekli karelerde yok; yerleşim altyazıdan kuruldu. -->

> **Çözüm (derste verildi):** Başlangıç: $i = 4\text{ V}/4\text{ kΩ} = 1$ mA, şekildeki yöne göre $i_L = -1$ mA; iki kondansatör de $v_C = 1 + 1\cdot 3 = 4$ V'a şarj olur. Son: $v_C = 1$ V, $i_L = 0$.

**Soru 5** (derste sözlü, 00:50:41): Kaynaksız seri RLC devresinde (kaynak $V_s[1 - u(t - t_0)]$) kondansatör başlangıçta neye şarj olur?

> **Çözüm (derste verildi):** Kondansatör açık devre, bobin kısa devre olduğu için akım geçmez ve kondansatör giriş gerilimine şarj olur: $v_C(t_0^-) = V_s$, $i_L = 0$.

**Soru 6** (derste sözlü, 01:00:25): İkinci dereceden bir denklemin diskriminantı nedir ve kökler nasıl bulunur?

> **Çözüm (derste verildi):** $\Delta = b^2 - 4ac$, kökler $(-b \pm \sqrt{\Delta})/(2a)$. Karakteristik denklem $s^2 + 2\alpha s + \omega_0^2 = 0$ için bu, $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ verir.

**Soru 7** (derste sözlü, 01:56:43): Kaynaksız RLC analizinden kaynak eklenen RLC analizine geçerken ne değişir?

> **Çözüm (derste verildi):** Başlangıç ve son durumlar değişir: seri devrede $v_C$ 0'dan $V_s$'ye, paralel devrede $i_L$ 0'dan $I_s$'ye gider. $\alpha$, $\omega_0$ ve üç cevap türünün ölçütleri aynı kalır.

## Dersin Toparlaması

Bu derste ikinci dereceden devrelere giriş yapıldı. Önce sınır koşullarının nasıl bulunacağı gösterildi: kararlı halde kondansatör açık devre, bobin kısa devre yapılır; kondansatör gerilimi ve bobin akımı geçiş anında süreklidir. Dört örnekte kondansatörün giriş gerilimine değil uçlarının bağlı olduğu kısmın gerilimine şarj olduğu, bobin akımlarının da süperpozisyonla bulunabileceği görüldü. Ardından kaynaksız seri RLC devresi için KVL'den ikinci dereceden diferansiyel denklem çıkarıldı, karakteristik denklem $s^2 + 2\alpha s + \omega_0^2 = 0$ ile kökler bulundu ve $\alpha$ ile $\omega_0$'ın karşılaştırılmasına göre aşırı, kritik ve az sönümlü cevaplar tanımlandı. Az sönümlü durumda Euler bağıntısıyla $\cos$-$\sin$ biçimli çözüme ulaşıldı.

Paralel RLC devresinde aynı yöntem KCL ve bobin akımı üzerinden uygulandı; tek fark $\alpha = 1/(2RC)$ oldu. Son olarak kaynağın devreye eklendiği basamak cevabında denklemin sağ tarafının sıfır olmadığı, son değerin $V_s$ ya da $I_s$ olduğu gösterildi. Hoca ilk anlatılan seri devrenin ayrıntılı işlendiğini, diğer üç durumun onun benzeri olduğunu söyledi ve konunun farklı örneklerle çalışılmasını önerdi; bu konuyla ilgili örneklere sonraki derste devam edilebileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
