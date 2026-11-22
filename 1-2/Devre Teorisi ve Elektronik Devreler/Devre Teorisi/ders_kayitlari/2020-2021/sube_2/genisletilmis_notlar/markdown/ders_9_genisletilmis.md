# Ders 9 Genişletilmiş Notu: Birinci Dereceden RC ve RL Devreleri, Tekillik Fonksiyonları, Türev ve İntegral Alıcı Op-Amp Devreleri

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Enerji Depolayan Elemanlardan RC ve RL Devrelerine
- 2. Doğal Cevap: RC Devresinin Deşarjı
- 3. Doğal Cevap: RL Devresinin Deşarjı
- 4. Tekillik Fonksiyonları
- 5. Basamak Cevabı: RC ve RL Devrelerinin Şarjı
- 6. Birden Çok Kaynakta Süperpozisyon
- 7. Sayısal Örnekler
- 8. Birinci Dereceden Op-Amp Devreleri: Türev Alıcı
- 9. İntegral Alıcı
- Örnek Sorular
- Dersin Toparlaması

## 1. Enerji Depolayan Elemanlardan RC ve RL Devrelerine

Hoca derse önceki konuları hatırlatarak başladı. Op-amp konusundan önce enerji depolayan iki devre elemanı işlenmişti: kondansatör ve bobin. Kondansatör enerjiyi uçları arasındaki **gerilim** üzerinden depolar. Bobin ise üzerinden geçen **akımın** oluşturduğu manyetik alan üzerinden enerji biriktirir. Her iki durumda da birikim sonuçta $V\cdot I$ çarpımından gelir; fark, birinde belirleyici büyüklüğün gerilim, ötekinde akım olmasıdır.

RC ve RL devreleri, bu elemanların şarj olurken (enerji biriktirirken) ve deşarj olurken (enerjiyi boşaltırken) verdiği cevabı incelemek için kurulur. Hoca neden yalnız C ya da yalnız L kullanılmadığını şöyle açıkladı: şarj eğrisinde gerilimin oluşabilmesi için bir R gerekir. Deşarjda da depolanan enerjinin bir R üzerinden "sömürülmesi", yani harcanması gerekir. Bu devrelerin denklemleri birinci dereceden diferansiyel denklemlerdir; bu yüzden matematikte **birinci dereceden devreler** diye anılırlar.

Ders iki adımda ilerledi. Önce deşarj, yani **doğal cevap** incelendi. Ardından şarj, yani basamak girişe verilen cevap ele alındı.

## 2. Doğal Cevap: RC Devresinin Deşarjı

### 2.1 Doğal cevabın tanımı

Slayttaki tanım şöyledir (ekrandan, 00:12:53): doğal cevap, devrenin **dış uyarı kaynağı olmadan** gösterdiği davranıştır. $t = 0$ anında kondansatörde ya da bobinde depolanmış enerji vardır. $t>0$ için bu enerji serbest kalır; enerji boşalırken devrede akım akar ve elemanlar üzerinde gerilim oluşur. Zaman sonsuza giderken depolanan enerji sıfıra iner ve devredeki akım ve gerilimler de sıfır olur.

Hoca senaryoyu şöyle kurdu: devrede bir gerilim kaynağı anahtarla bağlıdır ve kondansatör bu kaynakla $V_0$ gerilimine tam şarj olmuştur. $t_0$ anında anahtar açılır, kaynak devreden çıkar. Geriye yalnız şarjlı kondansatör ve onun üzerinden boşaldığı direnç kalır.

Hoca deşarj eğrisinin biçimini, kondansatör konusunda anlattığı fiziksel tabloyla ilişkilendirdi. Başta iki bacak arasındaki gerilim farkı büyüktür ve bu fark çok hızlı kapanır; eğri dik iner. Sonra içerideki polarizasyon yavaş yavaş dengeye geldiği için düşüş yavaşlar ve eğri yatıklaşır.

### 2.2 Denklemlerin kurulması

Devre tek bir kondansatör ve bir dirençten oluşur. Slayttaki yönlerle (ekrandan, 00:17:53):

- KVL: $-v_C + v_R = 0$, yani $v_R = v_C$. Kondansatör "üreten", direnç "harcayan" taraftır ve gerilimleri eşittir.
- Kondansatörün iç akımı, dış devrede dolaşan $i_R$ akımının tersi yönündedir: $i_C = -i_R$.
- Kondansatör akımı: $i_C = C\,\dfrac{dv_C}{dt}$ (kondansatör konusunda verilmişti).
- Direnç akımı: $i_R = \dfrac{v_R}{R}$.

Bu eşitlikler birleştirilince şu denklem çıkar:

$$C\frac{dV_C}{dt} + \frac{V_R}{R} = 0 \;\Rightarrow\; \frac{dV_C}{dt} + \frac{V_C}{RC} = 0 \;\Rightarrow\; \frac{1}{V_C}\frac{dV_C}{dt} + \frac{1}{RC} = 0$$

Değişkenler ayrılır: $\dfrac{dV_C}{V_C} = -\dfrac{1}{RC}\,dt$. Türevden kurtulmak için iki tarafın integrali alınır; sol taraf doğal logaritma verir:

$$\ln(V_C) = -\frac{t}{RC} + \ln\left(V_C\big|_{t=t_0}\right)$$

$V_C\big|_{t=t_0}$, kaynağın çekildiği andaki kondansatör gerilimidir; bu da kondansatörün şarj olduğu $V_0$ değeridir. İki tarafın üssü alınarak logaritmadan kurtulunca formül çıkar (ekrandan, 00:22:53):

$$V_C(t) = V_0\,e^{-t/\tau}, \qquad \tau = RC, \qquad t \ge 0$$

Hoca $e^{-t/\tau}$ çarpanını şöyle yorumladı: bir sayının eksi üssü, o sayının tersidir. Yani bu çarpan $1/e^{t/\tau}$'dur ve $V_0$'ı zamanla bölen, küçülten bir katsayıdır. Herhangi bir andaki kondansatör gerilimini bulmak için o anın $t$ değeri formüle konur. Formül yalnız $t_0$ sonrası için geçerlidir. Daha önce kaynak bağlıdır ve kondansatör zaten şarjlıdır.

### 2.3 Akım ve güç

Gerilim bulunduktan sonra akım ve güç kolayca yazılır (ekrandan, 00:22:53):

$$I_R(t) = -I_C(t) = \frac{V_0}{R}e^{-t/\tau}, \qquad p_R(t) = V_RI_R = \frac{V_0^2}{R}e^{-2t/\tau}$$

> **Hocanın vurgusu:** Güç $V^2/R$ diye yazılınca gerilimin karesi alınır, bu yüzden üsteki $t$ de 2 ile çarpılır ($e^{-2t/\tau}$). Hoca bunun sınavlarda sık unutulduğunu söyledi.

Slaytta enerji formülü de vardı: $w(t) = \int_0^t p_R\,dt = \dfrac{CV_0^2}{2}\left[1-e^{-2t/\tau}\right]$. Slayttaki açıklamaya göre gerilimler eşit, akımlar zıt işaretli olduğu için direncin harcadığı güç, kondansatörün bıraktığı güçtür. Hoca enerji hesabına bu derste girmeyeceklerini belirtti.

### 2.4 Zaman sabiti ve 5τ kuralı

$RC$ çarpımı zaman sabitidir ve $\tau$ (tau) diye okunur. Hocaya göre $\tau$ kondansatör ve bobin için çok kritik bir bilgi verir.

> **Hocanın vurgusu:** Bir kondansatörün tam şarj ya da tam deşarj olabilmesi için (bobinde de tam yüklenip boşalabilmesi için) en az $5\tau$ süre geçmesi gerekir. Hoca "bu kaydı unutmuyoruz" dedi.

Hoca bir $\tau$ süresi sonunda kondansatörün başlangıç enerjisinin yaklaşık %36'sını içinde tuttuğunu, %64'ünü bıraktığını söyledi. Kalan kısım da $5\tau$'ya kadar boşalır.

> **Ders sonrası not:** Bir $\tau$ sonunda gerilim $V_0e^{-1} \approx 0{,}368\,V_0$ olur; yani başlangıç geriliminin yaklaşık %36,8'i kalır, %63,2'si boşalır. Hocanın %36 ve %64 değerleri bunların yuvarlanmış hâlidir. Bu oranlar gerilim içindir; enerji gerilimin karesiyle orantılı olduğu için enerjide kalan oran $e^{-2} \approx \%13{,}5$'tir.

### 2.5 τ içindeki R hangi dirençtir?

> **Hocanın vurgusu:** $\tau = RC$ içindeki R, **kondansatörün uçlarından devreye bakıldığında** görülen eşdeğer dirençtir. Thevenin eşdeğerinde yük direncinin bağlandığı uçlardan bakarak eşdeğer direnç nasıl bulunuyorsa, burada da öyle bulunur. Gerilim kaynağı tarafından bakılmaz.

Basit devrede tek bir R vardır. Daha karmaşık devrelerde önce bu eşdeğer direnç hesaplanır (bkz. Örnek 03).

## 3. Doğal Cevap: RL Devresinin Deşarjı

Bobin için de aynı senaryo kurulur. $t_0$ anına kadar bobin bir akım kaynağıyla $I_0$ akımına yüklüdür. Kaynak çekilince bobin, üzerindeki akımı aynı yönde sürdürür. Bu sırada direnç gibi değil, bir üreteç gibi davranır.

Slayttaki denklemler (ekrandan, 00:27:53):

- KVL: $V_L + V_R = 0$. Hoca bunu "$V_L = -V_R$" diye de ifade etti: iki gerilim birbirinin tam zıttıdır.
- Seri devre olduğu için $I_L = I_R$.
- Bobin gerilimi: $V_L = L\,\dfrac{dI_L}{dt}$; direnç akımı: $I_R = V_R/R$.

Yerine konunca:

$$L\frac{dI_L}{dt} + RI_R = 0 \;\Rightarrow\; \frac{dI_L}{dt} + \frac{R}{L}I_L = 0 \;\Rightarrow\; \frac{dI_L}{I_L} = -\frac{R}{L}\,dt$$

İntegral alınınca $\ln(I_L) = -\dfrac{R}{L}t + \ln\left(I_L\big|_{t=0}\right)$ çıkar. Üs alınınca sonuç bulunur:

$$I_L(t) = I_0\,e^{-t/\tau}, \qquad \tau = \frac{L}{R}$$

Hoca neden burada $\tau$'yu "ters" yazdığını açıkladı. Üsteki ifade $\frac{R}{L}t$'dir ve bunu $t/\tau$ biçimine getirmek için $\tau = L/R$ alınır. Kondansatörde ise üs $t/RC$ olduğu için $\tau = RC$'dir.

İki deşarj arasındaki tek fark şudur: kondansatörde hesap gerilim üzerinden ($V_0$'ın sönümlenmesi), bobinde akım üzerinden ($I_0$'ın sönümlenmesi) yapılır. Akım bulunduktan sonra direnç gerilimi $V_R = I_LR = I_0R\,e^{-t/\tau}$ olur. Bobin gerilimi bunun tam tersidir: $V_L = -V_R$.

$\tau = L/R$ içindeki R de bobinin uçlarından devreye bakılarak bulunan eşdeğer dirençtir. 5τ kuralı burada da geçerlidir. Eğri yine başta hızlı, sonra yavaş düşer.

## 4. Tekillik Fonksiyonları

### 4.1 Neden fonksiyonla yazılır?

Hoca, örneklerde "$t_0$ anında kaynak çekiliyor" ya da "$t = 2$ saniyede 5 V veriliyor" gibi sözlü anlatımların gerçekte kullanılmadığını söyledi. Anahtarlama, kaynağın devreye girip çıkması ve sinyalin biçimi bir fonksiyonla belirtilir. Bu fonksiyonlara **tekillik fonksiyonları** (singularity functions) denir. RC ve RL devrelerinde sürekli anahtarlama yapılacağı için şarj ve deşarjın ne zaman başladığı bu fonksiyonlarla gösterilir.

### 4.2 Birim basamak fonksiyonu

Slayttaki tanım (ekrandan, 00:32:53):

$$u(t) = \begin{cases} 0, & t<0 \\ 1, & t>0 \end{cases} \qquad u(t-t_0) = \begin{cases} 0, & t<t_0 \\ 1, & t>t_0 \end{cases} \qquad u(t+t_0) = \begin{cases} 0, & t<-t_0 \\ 1, & t>-t_0 \end{cases}$$

Sağa kaydırma fonksiyonda negatif ($t-t_0$), sola kaydırma pozitif ($t+t_0$) yazılır. Bir $V_0$ gerilimini $t_0$ anında uygulamak $v(t) = V_0\,u(t-t_0)$ yazmak demektir. Böylece şemaya anahtar çizmeye gerek kalmaz. Aynı gösterim akım için de geçerlidir.

Hocanın tahtadaki örnekleri:

- 3. saniyede başlayan 1 V'luk basamak $u(t-3)$ diye yazılır. Katsayı 1 olduğu için yükseklik 1 birimdir.
- Aynı basamak 5 V olsaydı $5u(t-3)$ yazılırdı.
- $t_0$'dan 2 ms önce başlayan 5 V'luk basamak $5u(t+2)$ biçimindedir.

Kaynağın devreden çıkarılması ise $1-u(t-t_0)$ ile gösterilir: kaynak $t_0$ anına kadar devrededir, $t_0$ anında çıkarılır.

### 4.3 Birim darbe fonksiyonu

Birim basamağın türevi **birim darbe** fonksiyonudur (ekrandan, 00:42:53):

$$\delta(t) = \frac{d}{dt}u(t) = \begin{cases} 0, & t<0 \\ \text{tanımsız}, & t=0 \\ 0, & t>0 \end{cases}, \qquad \int_{0^-}^{0^+}\delta(t)\,dt = 1$$

Darbe yalnız tek bir anda oluşup biter; sürekli bir sinyal değildir. Slayttaki örnekte $t=-2$'de 5, $t=0$'da 10 ve $t=3$'te $-4$ büyüklüğünde üç darbe vardır:

$$x(t) = 5\delta(t+2) + 10\delta(t) - 4\delta(t-3)$$

Hoca birim darbenin sinyal işleme ve konvolüsyon gibi ileri sınıflardaki seçmeli derslerde karşılarına çıkacağını, bu derste yalnız gösterimini bilmenin yeteceğini söyledi.

### 4.4 Rampa fonksiyonu

Rampa fonksiyonu $t_0$ anından önce sıfırdır, sonra zamanla doğrusal artar. Kaydırma kuralı basamaktaki gibidir: $r(t-t_0)$ sağa kaydırılmış rampadır. <!-- BELİRSİZ: Rampa fonksiyonu slaytının karesi yok; altyazıda formülün geri kalanı net değil. -->

## 5. Basamak Cevabı: RC ve RL Devrelerinin Şarjı

15 dakikalık aradan sonra şarj eğrisine geçildi.

### 5.1 RC devresinin şarjı

Slayttaki devrede bir $I_1u(t-t_0)$ akım kaynağına R ve C paralel bağlıdır (ekrandan, 00:57:53). Basamak fonksiyonunun anlamı şudur: $t_0$'dan önce devreye akım verilmez, $t_0$'dan sonra $I_1$ akımı verilir. $t<t_0$ için devrede ne akım ne gerilim vardır.

Önce kondansatörün **neye şarj olacağı** bulunur. Slayttaki kural şöyledir: C açık devre yapılır ve uçlarındaki gerilim belirlenir. Zaman sonsuza giderken $I_C = 0$ olur, bu yüzden $V_C = V_R = I_1R$'dir. Hoca aynı devrenin kaynak dönüşümüyle seri bir $V = I_1R$ gerilim kaynağı ve R'ye çevrilebileceğini de hatırlattı. Kondansatör en geç $5\tau$ sonra bu değere şarj olur.

Formül, üst düğümde KCL ile kurulur. Giren akım $I_1$, çıkanlar $I_R$ ve $I_C$'dir:

$$I_R + I_C - I_1 = 0 \;\Rightarrow\; \frac{V_C}{R} + C\frac{dV_C}{dt} - I_1 = 0$$

Burada $V_R = V_C$ olduğu için $I_R = V_C/R$ yazılır. Denklem çözülünce şu sonuç çıkar:

$$V_C(t) = RI_1\left[1 - e^{-(t-t_0)/RC}\right], \qquad t>t_0$$

$RI_1$ çarpımı şarjın varacağı $V_0$ değeridir. Hoca formülü sınır değerleriyle kontrol etti. $t = t_0$ konunca üs sıfır olur ve $e^0 = 1$ çıkar; $1-1 = 0$ olduğu için kondansatör geriliminin sıfır olduğu, yani şarjın yeni başladığı görülür. $t$ büyüdükçe parantez 1'e yaklaşır ve $V_C$, $V_0$'a yakınsar. $5\tau$'da kondansatör tam şarj kabul edilir.

> **Ders sonrası not:** Hoca $5\tau$'daki değeri "yaklaşık $0{,}999\,V_0$" diye söyledi. Doğrusu $1-e^{-5} \approx 0{,}993$'tür, yani $V_C(5\tau) \approx 0{,}993\,V_0$ olur (python ile hesaplandı).

Hoca formülün nereden geldiğini bilmenin önemli olduğunu, ama formülün kendisini bilmenin de yeteceğini söyledi. $\tau = RC$ olduğu unutulmamalıdır.

### 5.2 RL devresinin şarjı

Slayttaki devrede $V_1u(t-t_0)$ gerilim kaynağı, R ve L seri bağlıdır (ekrandan, 01:02:53). $t_0$ öncesinde devre boştadır. $t_0$'dan sonra akım ve gerilim oluşur. Sonsuzda bobin tam yüklenir ve kısa devre gibi davranır.

Denklemler:

$$-V_1 + V_L + V_R = 0, \qquad I_L = I_R = V_R/R, \qquad V_L = L\frac{dI_L}{dt}$$

$$L\frac{dI_L}{dt} + RI_R - V_1 = 0 \;\Rightarrow\; \frac{dI_L}{dt} + \frac{R}{L}I_L - \frac{V_1}{L} = 0$$

$$I_L(t) = \frac{V_1}{R}\left[1 - e^{-(t-t_0)/\tau}\right], \qquad \tau = \frac{L}{R}$$

Kondansatörde son değer $I_1R$ (bir çarpım), bobinde $V_1/R$ (bir bölüm) biçimindedir. Bobin akım üzerinden çalıştığı için $V_1/R$ aslında bobinin varacağı akımdır. Bobinin hangi akıma şarj olacağını bulmak için bobin **kısa devre** yapılır. Kondansatörün hangi gerilime şarj olacağını bulmak için ise kondansatör **açık devre** yapılır.

Hoca formüldeki $t-t_0$ farkının önemini vurguladı. Önceki formüllerde yalnız $t$ yazıyordu, çünkü kaynak $t = 0$'da devreye giriyordu. Kaynak örneğin 1 saniyede devreye giriyorsa $t_0 = 1$ olur. 2. saniyedeki değer için üsse $2-1$ konur.

## 6. Birden Çok Kaynakta Süperpozisyon

Bir problem önce şarj, sonra deşarj içerebilir ya da iki ayrı kaynakla beslenebilir. Hoca böyle durumlarda daha önce olduğu gibi süperpozisyon kullanılacağını söyledi: her kaynak ayrı ayrı analiz edilir, sonuçlar toplanır.

Slayttaki örnekte (Example 01) paralel R ve C'yi iki akım kaynağı besler (ekrandan, 01:07:53). Kaynaklardan biri yukarı yönlü $I_1u(t-t_1)$'dir ve $t_1$ anında devreye girer. Öteki ters yönlü $I_2[1-u(t-t_2)]$'dir. Hoca bu yazımın anlamını şöyle açıkladı: "1 eksi" ifadesi kaynağın baştan beri devrede olduğunu ve $t_2$ anında çıkarıldığını söyler.

**Yalnız $I_1$ varken:** $t<t_1$ için kaynak devrede değildir; kondansatör gerilimi sıfırdır ve akım akmaz. $t_1$'den sonra bir şarj eğrisi başlar. Kondansatör açık devre yapılınca son değer $RI_1$ çıkar:

$$V_C(t) = 0\ \text{V}\ (t<t_1), \qquad V_C(t) = RI_1\left[1 - e^{-(t-t_1)/RC}\right]\ (t>t_1)$$

Hoca bir sayısal yorum da ekledi. $t_1 = 0{,}1$ ms ise, $t = 0{,}2$ ms'de üsse $0{,}2-0{,}1 = 0{,}1$ ms konur. Bu, kaynağın devreye girmesinden 0,1 ms sonraki gerilimdir.

**Yalnız $I_2$ varken:** Kaynak $t_2$'ye kadar devrededir ve kondansatör uzun süredir ona şarjlıdır. Akım ilk kaynağın tersi yönünde aktığı için şarj değeri $-RI_2$'dir. $t_2$'de kaynak çıkarılınca deşarj başlar: $-RI_2\,e^{-(t-t_2)/RC}$.

**Toplam ($t_1<t_2$ için)** slayttaki gibidir (ekrandan, 01:12:53):

$$V_C(t) = \begin{cases} 0\ \text{V} - RI_2, & t<t_1 \\[4pt] RI_1\left[1-e^{-(t-t_1)/RC}\right] - RI_2, & t_1<t<t_2 \\[4pt] RI_1\left[1-e^{-(t-t_1)/RC}\right] - RI_2\,e^{-(t-t_2)/RC}, & t>t_2 \end{cases}$$

Hoca aralıkları tek tek yorumladı:

- $t<t_1$: Yalnız $I_2$ etkilidir. $I_2$ sürekli beslediği için kondansatör sabit $-RI_2$'de durur.
- $t_1<t<t_2$: İki kaynak da devrededir. $I_2$ hâlâ beslediği için onun terimi değişmez. $I_1$ yeni takıldığı için onun şarj eğrisi başlar.
- $t>t_2$: Yalnız $I_1$ devrededir. $I_1$ şarj etmeyi sürdürür, $I_2$'nin bıraktığı yük ise sönümlenir.

> **Hocanın vurgusu:** Bu tür sorularda önce süperpozisyon yapılır. En önemli nokta tekillik fonksiyonlarını doğru okumaktır: hangi kaynak hangi anda devreye giriyor, hangisi çıkıyor.

## 7. Sayısal Örnekler

### 7.1 Örnek 02: RL devresinin deşarjı

Devrede 5 V'luk bir kaynak, 1 kΩ'luk direnç ve 10 mH'lik bir bobin vardır. Anahtar $t_0$ anında açılır. <!-- BELİRSİZ: Bu slaytın karesi yok; değerler altyazıdan alındı. -->

Hoca önce şunu gösterdi: bu durum $5u(t)$ diye değil, $5[1-u(t)]$ diye yazılır. Çünkü $u(t)$ kaynağın devreye girdiğini, $1-u(t)$ ise devreden çıktığını söyler.

- $t<t_0$: 5 V devreyi besler. Bobinde gerilim oluşmaz, yalnız akım geçer. Akımı bulmak için bobin kısa devre yapılır: $I_0 = 5\ \text{V}/1\ \text{k}\Omega = 5$ mA. Bobin $t_0$'a kadar bu akıma şarj olmuştur.
- $t>t_0$: $\tau = L/R$ ile hesaplanır ve akım $I_L(t) = 5\ \text{mA}\cdot e^{-t/\tau}$ olur. Direnç gerilimi $V_R = I_LR = 5\ \text{V}\cdot e^{-t/\tau}$ olur.

Hoca $\tau$'yu 10 ns buldu ve 2 ns'deki akımı örnek verdi: $I = 5\ \text{mA}\cdot e^{-2/10} = 5\ \text{mA}\cdot e^{-1/5}$.

> **Ders sonrası not:** Değerler 10 mH ve 1 kΩ ise $\tau = 10\cdot10^{-3}/10^{3} = 10^{-5}$ s $= 10$ µs olur, 10 ns değil. Hocanın bulduğu 10 ns ancak bobin 10 µH olsaydı doğru olurdu. Slayt karesi olmadığı için hangisinin doğru olduğu büyük olasılıkla slayttaki değere bağlıdır. Oran aynı kaldığı için ($t/\tau = 0{,}2$) sonuç değişmez: $5e^{-0{,}2} \approx 4{,}09$ mA (python ile hesaplandı).

> **Hocanın vurgusu:** En büyük problem nano, mikro ve mili saniye dönüşümlerinde yaşanıyor. Kilonun $10^3$, milinin $10^{-3}$ olduğunu dikkatle hesaba katmak gerekir.

### 7.2 Örnek 03: Üç dirençli RC devresinin deşarjı

Slayttaki devre (ekrandan, 01:17:53): 5 V'luk kaynak bir anahtarla bağlıdır ve anahtar $t = 2$ ms'de açılır. Kaynak ucunda R1 = 1 kΩ toprağa bağlıdır. R2 = 3 kΩ seri koldadır. R3 = 12 kΩ ile C1 = 2 µF birbirine paraleldir. Kaynak $V(t) = 5\ \text{V}\,[1-u(t-2\ \text{ms})]$ diye verilmiştir. Hoca bunun $5 - 5u(t-2\ \text{ms})$ biçiminde de yazılabileceğini gösterdi: 5 V sonsuza kadar veriliyor, 2 ms'de $-5$ V eklenip sıfırlanıyor.

**Adım 1: Kondansatörün şarj değeri ($t<2$ ms).** Kondansatör R3'e paralel olduğu için onun gerilimine şarj olur. C açık devre yapılır. R1 doğrudan kaynağın uçlarında durduğu için R3'ün gerilimini etkilemez. R2 ve R3 bir gerilim bölücü oluşturur:

$$V_C = 5\ \text{V}\cdot\frac{12}{3+12} = 4\ \text{V}$$

**Adım 2: τ hesabı ($t>2$ ms).** Anahtar açıldıktan sonra kondansatör tarafından devreye bakılır. R2 ile R1 seridir ($3+1 = 4$ kΩ). Bu kol R3'e paraleldir:

$$R_{eq} = 12\,\|\,4 = \frac{12\cdot 4}{12+4} = 3\ \text{k}\Omega, \qquad \tau = 3\ \text{k}\Omega\cdot 2\ \mu\text{F} = 6\ \text{ms}$$

(Kilonun $10^3$'ü ile mikronun $10^{-6}$'sı birleşince $10^{-3}$ kalır.)

**Adım 3: Deşarj formülü.**

$$V_C(t) = 4\ \text{V}\cdot e^{-(t-2\ \text{ms})/6\ \text{ms}}, \qquad t>2\ \text{ms}$$

Hoca bir de 3 ms'deki gerilimi örnek verdi. Kaynağın kesilmesinden $3-2 = 1$ ms sonrası için $V_C = 4e^{-1/6} \approx 3{,}39$ V olur (python ile doğrulandı).

Direnç gerilimi kondansatör gerilimine eşittir. Akım istenirse $V_R/R$'den ya da $C\,dV_C/dt$'den bulunur.

### 7.3 Örnek 04: 6 V'luk RL devresinin deşarjı

Slayttaki devre (ekrandan, 01:22:53): 6 V'luk kaynak, $t = 0$ s'de konum değiştiren bir anahtar, 10 mH'lik bobin ve 3 kΩ'luk direnç. Anahtar konum değiştirince kaynak devreden çıkar ve bobin direnç üzerinden boşalır.

- $t<0$: Bobin kısa devre yapılır: $I_0 = 6\ \text{V}/3\ \text{k}\Omega = 2$ mA.
- $t>0$: Devrede tek bir direnç vardır. $\tau = L/R$ ve $I_L(t) = 2\ \text{mA}\cdot e^{-t/\tau}$ olur.
- $V_R = 3\ \text{k}\Omega\cdot I_L$; bobin gerilimi bunun tersidir ya da $L\,dI_L/dt$ ile bulunur.

> **Ders sonrası not:** Hoca $\tau$'yu 3,33 ms diye söyledi. Slayttaki değerlerle $\tau = 10\cdot10^{-3}/(3\cdot10^{3}) \approx 3{,}33\cdot10^{-6}$ s, yani **3,33 µs**'dir. Doğru ifade $I_L(t) = 2\ \text{mA}\cdot e^{-t/3{,}33\,\mu\text{s}}$'dir (python ile hesaplandı).

Hoca bu konuların ileride RLC devreleri ve faz farkı konularında kullanılacağını, bu yüzden iyi anlaşılması gerektiğini söyledi.

## 8. Birinci Dereceden Op-Amp Devreleri: Türev Alıcı

### 8.1 Bağlam

Geçen hafta op-amp devreleri işlenmişti: eviren ve evirmeyen yükselteç, fark alıcı, toplayıcı ve kaskat yapılar. Op-amp'ın analog işlemler için bir kullanımı daha vardır: **birinci dereceden op-amp devreleri**, yani türev alıcı ve integral alıcı devreler. Bu devrelerde kondansatör bulunduğu için hoca önce kondansatörün şarj ve deşarj matematiğini işlemeyi seçtiğini söyledi.

### 8.2 Türev alıcı devrenin çıkarılışı

Eviren yükselteçte giriş direnci yerine bir kondansatör konur. Eviren yükselteçte formül $V_{out} = -\dfrac{R_F}{R_1}V_{in}$ idi. Aynı iki kural burada da geçerlidir:

- Eviren uç sanal topraktadır (virtual ground), yani gerilimi 0'dır (ekrandan, 01:27:53).
- Op-amp girişine akım girmez, bu yüzden kondansatör akımı geri besleme direncinden geçen akıma eşittir: $i_C = i_R$.

Eviren uç 0 V'ta olduğu için KVL'den $v_C = v_S$ olur. Kondansatör girişteki sinyale eşit olarak değişir ve ona şarj olur. Akımlar şöyle yazılır:

$$i_C = C\frac{dv_C}{dt} = C\frac{dv_S}{dt}, \qquad i_R = \frac{0 - v_o}{R} = -\frac{v_o}{R}$$

İkisi eşitlenip $v_o$ yalnız bırakılınca:

$$v_o(t) = -RC\,\frac{dv_S(t)}{dt}$$

Hoca buradaki $RC$'nin deşarjdaki gibi bir zaman sabiti olarak değil, yalnız bir katsayı olarak kullanıldığını belirtti; burada zaman analizi değil değer analizi yapılır.

### 8.3 Türev alıcı Örnek 01: basamak giriş

Girişe $3u(t-5\ \text{s})$ V uygulanır, yani 5. saniyede 3 V verilir. $R = 20$ kΩ, $C = 40$ µF'tır (ekrandan, 01:32:53).

- $t<5$ s: Giriş yoktur; kondansatör 0 V, çıkış 0 V'tur.
- $\tau = RC = 20\cdot10^{3}\cdot40\cdot10^{-6} = 0{,}8$ s.
- $5$ s $< t <$ 9 s: Slaytta hesap şöyledir:

$$v_o(t) = \frac{-1}{0{,}8\ \text{s}}\left(-20\cdot10^{3}\ \Omega\right)\left(40\cdot10^{-6}\ \text{F}\right)(3\ \text{V})\,e^{-(t-5\,\text{s})/0{,}8\,\text{s}} = 3\ \text{V}\,e^{-(t-5\,\text{s})/0{,}8\,\text{s}}$$

- $t > t_0 + 5\tau = 5\ \text{s} + 5(20\ \text{k}\Omega)(40\ \mu\text{F}) = 9$ s: $v_o = 0$ V.

> **Hocanın vurgusu:** $t > t_0 + 5\tau$ için çıkış 0 V'tur. Kondansatör $5\tau$'da tam dolar ve gerilimi girişteki 3 V'a eşit olur. Artık değişmediği için türev, dolayısıyla çıkış sıfırdır. Bu op-amp devresi yalnız 5 s ile $5+5\tau = 9$ s arasında anlamlı bir çıkış verir.

> **Ders sonrası not:** Slayttaki işaret, kondansatör gerilimi $3e^{-(t-5)/0{,}8}$ biçiminde alınarak bulunmuş görünüyor; hoca da altyazıda bu ifadeyi söyledi. Oysa hoca kondansatörün 0'dan 3 V'a şarj olduğunu da söyledi. $v_C = 3\left[1-e^{-(t-5)/0{,}8}\right]$ alınırsa türev pozitif olur ve $v_o = -3e^{-(t-5)/0{,}8}$ V çıkar. Büyüklük ve zaman sabiti iki durumda da aynıdır; işaret büyük olasılıkla slayttaki kabule bağlıdır. <!-- BELİRSİZ: Kondansatör geriliminin yazıldığı slaytın karesi yok. -->

### 8.4 Türev alıcı Örnek 02: sinüs giriş

$R = 2$ kΩ, $C = 0{,}1$ µF ve giriş $v_S = 2\sin(500t)$ V'tur. Hoca bunun genliği 2 V olan ve $-2$ ile $+2$ V arasında salınan bir sinüs olduğunu, frekansın $2\pi f$ ilişkisiyle bu ifadeden çıkarılabileceğini söyledi. Alternatif akım ileride ayrıca işlenecektir. <!-- BELİRSİZ: Bu slaytın karesi yok; değerler altyazıdan alındı. -->

Girişin kendisi zamana bağlı olduğu için üstel ifade yazmaya gerek yoktur; doğrudan türev alınır:

$$v_o(t) = -RC\frac{d}{dt}\left[2\sin(500t)\right] = -(2\cdot10^{3})(0{,}1\cdot10^{-6})(2)(500)\cos(500t) = -0{,}2\cos(500t)\ \text{V}$$

> **Hocanın vurgusu:** Türev alırken öğrenciler sık karıştırıyor. Sinüsün türevi kosinüs, kosinüsün türevi eksi sinüstür. Sinüsün içindeki 500 katsayısı türevde dışarı çıkar, 2 V'luk genlik de dışarıda kalır.

Hoca sonucu sinüs biçimine çevirdi. Kosinüs ile sinüs arasında 90° faz farkı vardır; kosinüsü sinüs olarak yazmak için açıya 90° eklenir: $\cos x = \sin(x+90^\circ)$. Başındaki eksiden kurtulmak için 180° daha kaydırılır. Sonuç:

$$v_o(t) = 0{,}2\sin(500t - 90^\circ)\ \text{V}$$

Giriş $2\sin(500t)$ V olduğu için **çıkış girişin 90° gerisindedir**. Hoca ileri ve geri faz (leading, lagging) kavramlarına ilerideki derslerde ayrıntılı döneceklerini söyledi. Python kontrolü: $RC\cdot 2\cdot 500 = 0{,}2$.

## 9. İntegral Alıcı

### 9.1 Çıkarılış

İntegral alıcıda, türev alıcıdan farklı olarak **geri besleme direncinin** yerine kondansatör konur; giriş direnci R kalır (ekrandan, 01:37:53). Kondansatör bu kez çıkışa bağlıdır. Akım üzerinden işlem yapıldığı ve kondansatör gerilimi akımın integraliyle bulunduğu için devre integral alır.

- Eviren uç sanal topraktadır, bu yüzden $i_R = \dfrac{v_S - 0}{R}$.
- Kondansatörün bir ucu 0 V'ta, öbürü çıkıştadır; polarizasyona göre $v_C = 0 - v_o = -v_o$.
- $i_R = i_C = C\dfrac{dv_C}{dt} = -C\dfrac{dv_o}{dt}$.

Eşitlik düzenlenip integral alınınca:

$$v_o(t) = -\frac{1}{RC}\int_{t_1}^{t} v_S(t)\,dt + v_o(t_1)$$

Devre, girişteki $v_S$ geriliminin zaman içindeki integralini $-1/RC$ katsayısıyla alır. $v_o(t_1)$, başlangıçta çıkışta bulunabilecek gerilimdir. Belirtilmemişse sıfır alınır.

### 9.2 Sinüs giriş örneği ve PSpice sonucu

Örnekte yaklaşık 25 kΩ'luk bir direnç, 5 nF'lık bir kondansatör ve girişte $t_0$ anında uygulanan 3 V genlikli, açısı radyan cinsinden verilmiş bir sinüs vardır. <!-- BELİRSİZ: Bu slaytın karesi yok; direnç değeri altyazıda "25.10" diye geçiyor, açısal frekans okunamadı. -->

Sinüsün integrali $-\cos$'tur. Formüldeki eksiyle birleşince çıkış pozitif kosinüs biçimini alır. Giriş sinüs olduğu için çıkış da sinüs cinsinden yazılır: $\cos x = \sin(x+90^\circ)$. Yani **integral alıcıda çıkış girişin 90° önündedir**.

PSpice grafiğinde (ekrandan, 01:42:53) giriş (yeşil) yaklaşık $\pm 3$ V arasında, periyodu yaklaşık 1 ms olan bir sinüstür. Çıkış (kırmızı) yaklaşık 0 ile $-7{,}4$ V arasında salınır. Slayttaki açıklamaya göre çıkış girişin $+90^\circ$ önündedir ve görülen gerilim kayması $V_o(t_1)$ teriminden gelir.

> **Ek bilgi (derste anlatılmadı):** $v_o(0) = 0$ ile başlayan bir integral alıcıda $v_S = A\sin(\omega t)$ için $v_o = \dfrac{A}{\omega RC}\left[\cos(\omega t) - 1\right]$ olur. Çıkış bu yüzden 0 ile $-2A/(\omega RC)$ arasında salınır. Grafikteki sıfırın altındaki kayma büyük olasılıkla bu sabit terimdir.

### 9.3 Kaynaksız türev alıcı

Son slaytta besleme olmadan kondansatörde gerilim bulunan bir türev alıcı devre incelendi. Burada $V_1 = V_C + V_R$ yazılır, çünkü deşarj sırasında iki gerilim aynı yönde polarizedir. Eviren uç sıfır olduğu için $V_C = -V_R$ biçimine gelinir. R1 akımı kondansatör akımına eşittir. Kondansatör şarj olurken şarjın tersi yönünde akım akıttığı için R2 akımı bunların tersi yönünde alınır. <!-- BELİRSİZ: Bu slaytın karesi yok; devre şekli ve işaretler altyazıdan tam çıkarılamadı. -->

### 9.4 Genel kural

> **Hocanın vurgusu:** Türev ve integral alıcı devrelerde belirleyici olan kondansatörün yeridir. Kondansatör geri besleme direncinin yerindeyse devre **integral alıcı**, giriş direncinin yerindeyse **türev alıcıdır**. Sinüs girişte türev alıcı çıkışı 90° geri, integral alıcı çıkışı 90° ileri kaydırır.

## Örnek Sorular

**Soru 1 (ekrandan, 00:37:53).** Aşağıdaki sinyali birim basamak fonksiyonlarıyla yazınız: $t<5$ s için 0 V; $5<t<8$ s için 3 V; $8<t<12$ s için $-5$ V; $t>12$ s için 0 V.

> **Çözüm (derste verildi, 00:37:33-00:40:21):** 5. saniyede 3 V'luk sıçrama $3u(t-5)$ ile yazılır. 8. saniyede sinyal 3 V'tan $-5$ V'a, yani 8 V iner: $-8u(t-8)$. 12. saniyede $-5$ V'tan 0'a, yani 5 V çıkar: $+5u(t-12)$.
> $$v(t) = 3u(t-5) - 8u(t-8) + 5u(t-12)\ \text{V}$$
> Bir öğrenci 8. saniyedeki terimin $-3u(t-8)$ olması gerektiğini önerdi. Hoca bunun yalnız sıfırlamaya yeteceğini, sinyalin $-5$ V'a inmesi için ayrıca $-5u(t-8)$ gerektiğini gösterdi. İki terimin toplamı yine $-8u(t-8)$'dir. Hoca bu tür bir sorunun finalde daha karmaşık biçimde mutlaka geleceğini söyledi.

**Soru 2 (ekrandan, 01:17:53).** 5 V'luk kaynak, R1 = 1 kΩ, R2 = 3 kΩ, R3 = 12 kΩ ve C1 = 2 µF'tan oluşan devrede anahtar $t = 2$ ms'de açılıyor: $V(t) = 5\ \text{V}[1-u(t-2\ \text{ms})]$. $t>2$ ms için kondansatör gerilimini bulunuz.

> **Çözüm (derste verildi):** $V_C(2\ \text{ms}) = 5\cdot 12/15 = 4$ V. $R_{eq} = 12\,\|\,(3+1) = 3$ kΩ, $\tau = 6$ ms. $V_C(t) = 4e^{-(t-2\ \text{ms})/6\ \text{ms}}$ V. Örneğin $V_C(3\ \text{ms}) = 4e^{-1/6} \approx 3{,}39$ V.

**Soru 3 (ekrandan, 01:22:53).** 6 V'luk kaynak, 10 mH'lik bobin ve 3 kΩ'luk dirençten oluşan devrede anahtar $t = 0$'da kaynağı devreden çıkarıyor. $I_L(t)$'yi bulunuz.

> **Çözüm (derste verildi; zaman sabiti düzeltildi):** $I_0 = 6/3\text{k} = 2$ mA, $\tau = L/R = 3{,}33$ µs. $I_L(t) = 2\ \text{mA}\cdot e^{-t/3{,}33\,\mu\text{s}}$, $V_R(t) = 6\ \text{V}\cdot e^{-t/3{,}33\,\mu\text{s}}$. Derste $\tau$ 3,33 ms diye söylendi; doğru birim mikrosaniyedir.

**Soru 4 (ekrandan, 01:32:53).** $R = 20$ kΩ, $C = 40$ µF'lık türev alıcının girişine $3u(t-5\ \text{s})$ V uygulanıyor. Çıkış gerilimini zaman aralıklarına göre yazınız.

> **Çözüm (derste verildi):** $t<5$ s için $v_o = 0$. $\tau = 0{,}8$ s. $5<t<9$ s için slayttaki sonuç $v_o = 3\ \text{V}\,e^{-(t-5)/0{,}8}$'dir (işaret için 8.3'teki ders sonrası nota bakınız). $t>9$ s için $v_o = 0$.

**Soru 5 (derste sözlü, 01:33:49).** $R = 2$ kΩ, $C = 0{,}1$ µF'lık türev alıcının girişi $v_S = 2\sin(500t)$ V ise çıkış nedir ve giriş ile çıkış arasındaki faz ilişkisi nasıldır?

> **Çözüm (derste verildi):** $v_o = -RC\,\dfrac{dv_S}{dt} = -0{,}2\cos(500t)\ \text{V} = 0{,}2\sin(500t-90^\circ)$ V. Çıkış girişin 90° gerisindedir.

## Dersin Toparlaması

Bu derste kondansatör ve bobinin şarj ve deşarj davranışı matematiksel olarak çıkarıldı. Deşarjda (doğal cevap) kondansatör gerilimi $V_0e^{-t/RC}$, bobin akımı $I_0e^{-tR/L}$ biçiminde sönümlenir. Şarjda (basamak cevabı) son değere $1-e^{-(t-t_0)/\tau}$ biçiminde yaklaşılır. Son değeri bulmak için kondansatör açık devre, bobin kısa devre yapılır. $\tau$ içindeki R, elemanın uçlarından görülen eşdeğer dirençtir ve 5τ sonunda eleman tam dolmuş ya da boşalmış kabul edilir. Anahtarlamanın birim basamak, birim darbe ve rampa gibi tekillik fonksiyonlarıyla nasıl yazılacağı gösterildi. Birden çok kaynaklı devrelerin süperpozisyonla aralık aralık çözüldüğü görüldü. Son olarak kondansatörün op-amp devresinde giriş ya da geri besleme elemanı olarak kullanılmasıyla türev ve integral alıcı devreler elde edildi.

Hoca bu haftayı ilerideki konular için kritik saydı. Bundan sonra empedans hesaplarına, ardından faz farklarına geçilecek. Bir sinyalin öne mi geçtiği, geride mi kaldığı (leading, lagging) ve faz kaymasının olup olmadığı ancak kondansatör ve bobindeki şarj ve deşarj iyi anlaşılırsa bulunabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
