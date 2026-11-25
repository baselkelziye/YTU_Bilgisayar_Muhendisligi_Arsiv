# Ders 9 Genişletilmiş Notu: Türev ve İntegral Alıcı Op-Amp Devreleri, İkinci Dereceden RLC Devrelerinde Sınır Koşulları ve Vize Soru Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Yol Haritası
- 2. İdeal Op-Amp ve Kondansatör Bağıntılarının Hatırlanması
- 3. Türev Alıcı Devre
- 4. Türev Alıcı Örnekleri
- 5. Sinüs ve Kosinüs Arasında Dönüşüm
- 6. İntegral Alıcı Devre
- 7. Başlangıç Gerilimli Kondansatör
- 8. İkinci Dereceden Devrelere Giriş
- 9. Sınır Koşulları
- 10. Sınır Koşulu Örnekleri
- 11. Seri RLC Devresinin Basamak Tepkisi
- 12. Vize Sorularının Çözümü
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yeri ve Yol Haritası

Önceki haftalarda ideal op-amp dirençlerle birlikte incelendi: eviren kuvvetlendirici, evirmeyen kuvvetlendirici, tampon (buffer) ve toplayıcı. Ardından birinci dereceden RC ve RL devreleri görüldü. Bu derste önce op-amp konusunun eksik kalan kısmı, yani içinde kondansatör bulunan türev alıcı ve integral alıcı devreler ele alınır. Sonra ikinci dereceden devrelere, yani RLC devrelerine geçilir.

RLC devreleri zaman domeninde ikinci dereceden diferansiyel denklem verir. Hoca, müfredatta diferansiyel denklemler dersi olmadığı için konuya "yumuşak bir geçişle" gireceklerini söyledi. Bu haftaki çözümler DC kaynakların devreye bağlandığı ya da devreden çıkarıldığı durumların geçici hallerini kapsar.

Hoca, bu konunun sonraki haftalardaki fazör konusuna temel olduğunu anlattı. Fazör yaklaşımında kaynak sinüs ya da kosinüs biçimindedir ve geçici haller (yaklaşık beş zaman sabiti) geçtikten sonraki sürekli sinüzoidal hal incelenir. Fazör uzayına geçildiğinde direnç, kondansatör ve bobin doğrusal elemanlar gibi davranır; devre sanki bir direnç devresiymiş gibi, ama karmaşık sayılarla çözülür. Sonuç sonra zaman domenine geri çevrilir.

## 2. İdeal Op-Amp ve Kondansatör Bağıntılarının Hatırlanması

İdeal op-amp'ın bir eksi (eviren) ve bir artı (evirmeyen) girişi vardır. Kendi başına enerji üretmez; ihtiyaç duyduğu enerjiyi besleme uçlarından alır. Çizimlerde besleme gerilimleri genelde gösterilmez. Çözümde iki tanım bağıntısı kullanılır:

- Giriş gerilimleri eşittir: $v_N = v_P$.
- Girişlerden akım akmaz: $i_N = i_P = 0$.

Hoca eski devreleri kısaca hatırlattı. Eviren kuvvetlendiricinin kazancı dirençlerin oranının eksisidir; giriş sinüsse çıkış aynı frekansta, ters işaretli ve farklı genlikte bir sinüstür. Evirmeyen kuvvetlendiricide çıkış aynı işaretli ve genliği büyütülmüş bir işarettir. Toplayıcı birden fazla kaynağı toplar. Tampon devre gerilimi tekrarlar.

Tampon için hoca pratik bir örnek verdi: bir lojik çıkışın sürebileceği giriş sayısı (fan-out) sınırlıdır. Daha fazla giriş sürülürse akım yüzünden gerilim seviyeleri lojik 1 ya da 0 eşiklerinin dışına kayabilir ve yanlış değer aktarılabilir. Araya tampon konunca gerilim yeniden özgün değerine çıkarılır ve sürülebilen giriş sayısı artar.

Hoca, "çarpma devresinin" de aslında kazançlı kuvvetlendirici olduğunu ekledi: dirençlerin oranı girişi bir sabitle çarpar.

Kondansatörün tanım bağıntısı:

$$q = C\,v_C, \qquad i_C = C\,\frac{dv_C}{dt}, \qquad v_C = \frac{1}{C}\int i_C\,dt.$$

Akım, yükün zamana göre türevidir. Bu bilgiyle kondansatör bağıntısı türev ya da integral biçiminde yazılabilir.

### 2.1 Neden türev ve integral alıcı?

Bugünkü sayısal bilgisayarlardan önce analog bilgisayarlar vardı. Örneğin bir hız denetimi ya da bir uzay aracının yörüngeye oturtulması gibi denetim işleri için türev ve integral hesapları gerekir. Bu matematik işlemlerin elektriksel elemanlarla yapıldığı sistemlere analog bilgisayar denir. Türev ve integral alan op-amp devreleri bu bilgisayarlarda yaygın biçimde kullanılmıştır.

## 3. Türev Alıcı Devre

Devre (ekrandan, 00:15:00):

- $v_S$ kaynağı toprak ile giriş düğümü arasındadır.
- Giriş düğümü ile op-amp'ın eksi girişi arasında seri bir kondansatör $C$ vardır ($+\,v_C\,-$ kaynak tarafı artı).
- Eksi girişten çıkışa geri besleme direnci $R$ bağlıdır ($i_R$ çıkışa doğru).
- Artı giriş toprağa bağlıdır.

Çözüm adımları (ekrandan, 00:20:00):

1. Artı giriş toprakta olduğu için $v_P = 0$; tanım bağıntısından $v_N = 0$.
2. Kondansatörün bir ucu $v_S$'de, diğer ucu 0 V'tadır: $v_C = v_S$.
3. Kondansatör akımı: $i_C = C\,v_C' = C\,v_S'$.
4. Op-amp girişlerine akım girmez, bu yüzden kondansatörden gelen akım tamamen dirençten geçer: $i_C = i_R = \dfrac{0 - v_o}{R}$.
5. Eşitlenirse $C\,v_S' = -\dfrac{v_o}{R}$, yani

$$v_o = -RC\,\frac{dv_S}{dt}.$$

Amaç çıkışı girişin fonksiyonu olarak yazmaktı ($v_o = f(v_S)$). Devre girişin türevini alır, $RC$ ile çarpar ve işaretini çevirir.

> **Hocanın vurgusu:** Türev alıcının çalışma mantığı "çok önemli bir nokta". Hoca anlaşılıp anlaşılmadığını özellikle sordu ve kısa sınavlarda karşılaşılabileceğini söyledi.

### 3.1 Dalga biçimleri

Hoca tahtada giriş olarak bir üçgen dalga çizdi (ekrandan, 00:20:00). Üçgen dalganın eğimi parça parça sabittir:

- Gerilimin arttığı parçalarda eğim pozitiftir. $-RC$ ile çarpılınca çıkış negatif sabit bir değer olur.
- Gerilimin azaldığı parçalarda eğim negatiftir; çıkış pozitif sabit bir değer olur.

Sonuç olarak üçgen dalga girince kare dalga çıkar. Benzer biçimde $a t^2$ türünden parabol parçalarından oluşan bir giriş verilirse türevi doğrusal parçalardan oluşur ve çıkış üçgen dalgaya benzer; eğimin sıfır olduğu tepe noktalarında çıkış sıfırdan geçer. Bu çizimde hoca önce yanlış yönde çizdi, sonra eksi işaretini hesaba katarak düzeltti.

## 4. Türev Alıcı Örnekleri

### 4.1 Basamak girişi (Örnek 01)

Verilenler (ekrandan, 00:25:00): $v_S(t) = 3\,\text{V}\,u(t - 5\,\text{s})$, $C = 40\ \mu\text{F}$, $R = 20\ \text{k}\Omega$. Kaynak $t = 5$ s'de 0 V'tan 3 V'a çıkar. Slayttaki koşullar:

- $t < 5$ s için kondansatörün başlangıç gerilimi $v_C = 0$ V.
- $t > 5RC$ sonrasında kondansatörün son gerilimi $v_C = 3$ V.

Hoca kondansatörün başlangıçta yük depolamış olabileceğini, bu örnekte başlangıç değerinin sıfır verildiğini belirtti. Zaman sabiti:

$$\tau = RC = (20\times10^{3}\ \Omega)(40\times10^{-6}\ \text{F}) = 0{,}8\ \text{s}.$$

Yaklaşık $5\tau$ beklendikten sonra kondansatör dolmuş sayılır. Bu yüzden (ekrandan, 00:30:00):

- $t < 5$ s için $v_o(t) = 0$ V.
- $t > t_0 + 5\tau = 5\,\text{s} + 5(20\ \text{k}\Omega)(40\ \mu\text{F}) = 9$ s için $v_o(t) = 0$ V.
- Arada geçici hal vardır ve çıkış $e^{-(t-5\,\text{s})/0{,}8\,\text{s}}$ ile söner.

Slaytta iki satır vardır:

$$v_o(t) = \frac{-1}{0{,}8\,\text{s}}\,(-20\times10^{3}\,\Omega)(40\times10^{-6}\,\text{F})(3\,\text{V})\,e^{-(t-5\,\text{s})/0{,}8\,\text{s}}$$

$$v_o(t) = 3\,\text{V}\,e^{-(t-5\,\text{s})/0{,}8\,\text{s}}$$

Hoca ikinci satırı çarpı ile işaretledi ve katsayının kaybolduğunu söyledi; türevi ayrıca yazdı (ekrandan, 00:30:00):

$$\frac{d}{dt}\left(3\,e^{-\frac{t-5}{0{,}8}}\right) = 3\cdot\left(-\frac{1}{0{,}8}\right)e^{-\frac{t-5}{0{,}8}}.$$

Üstel fonksiyonun türevi kendisidir, üstteki fonksiyonun türevi ($-1/0{,}8$) de çarpan olarak gelir. Hoca, buradaki davranışın op-amp'tan çok kondansatör ve kaynaktan kaynaklandığını, op-amp'ın etkisinin eksi girişi 0 V'ta tutmak olduğunu söyledi.

> **Ders sonrası not:** $RC = 0{,}8$ s olduğundan slayttaki iki satır sayısal olarak aynı sonucu verir; ilk satırdaki çarpım $(-1/0{,}8)(-0{,}8)(3) = 3$'tür. Ancak kondansatör gerilimi $v_C = 3\left(1 - e^{-(t-5)/0{,}8}\right)$ V biçiminde yükseliyorsa türevi pozitiftir ve $v_o = -RC\,v_C' = -3\,e^{-(t-5)/0{,}8}$ V olur; yani çıkış büyük olasılıkla negatif bir darbedir. İdeal op-amp ve ideal kaynakla kondansatör gerilimi anında 3 V'a atlardı; slayttaki üstel model büyük olasılıkla küçük bir seri direnç varsayar.

### 4.2 Sinüs girişi (Örnek 02)

Verilenler (altyazıdan, 00:30:50): $R = 2\ \text{k}\Omega$, $C = 0{,}1\ \mu\text{F}$, $v_S = 2\sin(500t)$ V.

$$RC = (2\times10^{3})(1\times10^{-7}) = 0{,}2\times10^{-3}\ \text{s} = 0{,}2\ \text{ms}.$$

Türev: $\dfrac{d}{dt}\,2\sin(500t) = 2\cdot500\cos(500t) = 1000\cos(500t)$. $RC$ ile çarpınca $0{,}2\times10^{-3}\cdot1000 = 0{,}2$; eksi işaretle birlikte

$$v_o(t) = -0{,}2\cos(500t)\ \text{V}.$$

Hoca giriş ve çıkışı birlikte çizdi: kosinüs, sinüsün tepe yaptığı yerde sıfırdan geçer; eksi işaret yüzünden çıkış ters döner. Çıkışın genliği girişten küçüktür. Türev $90^\circ$ faz farkı getirir, eksi işaret de işareti çevirir.

## 5. Sinüs ve Kosinüs Arasında Dönüşüm

Hoca, ileride fazörlerde kullanılacak dönüşümleri dik üçgen ve birim çember üzerinde gösterdi (ekrandan, 00:35:00).

Dik üçgende bir açı $\alpha$ ise diğeri $90^\circ - \alpha$'dır ve $\cos\alpha = \sin(90^\circ - \alpha)$ olur. Birim çemberde $\sin\alpha = \sin(180^\circ - \alpha)$ olduğu da görülür. $\alpha$ yerine $90^\circ - x$ konursa:

$$\cos x = \sin(90^\circ - x) = \sin\big(180^\circ - (90^\circ - x)\big) = \sin(90^\circ + x).$$

Aynı sonuç toplam formülünden de çıkar: $\sin(A + B) = \sin A\cos B + \sin B\cos A$. $A = 90^\circ$, $B = x$ alınırsa $\sin 90^\circ = 1$, $\cos 90^\circ = 0$ olduğundan $\sin(90^\circ + x) = \cos x$.

Baştaki eksi işaretini açının içine almak için birim çemberde $180^\circ$ ötedeki açıya bakılır:

$$-\sin\alpha = \sin(\alpha + 180^\circ) = \sin(\alpha - 180^\circ).$$

Amaç baştaki eksi işaretinden kurtulmak ve faz açısını $-180^\circ$ ile $+180^\circ$ arasında tutmaktır. Örnek 02'nin sonucu böylece düzenlenir (ekrandan, 00:35:00):

$$v_o(t) = -0{,}2\cos(500t) = -0{,}2\sin(500t + 90^\circ) = 0{,}2\sin(500t + 90^\circ - 180^\circ) = 0{,}2\sin(500t - 90^\circ)\ \text{V}.$$

Slayttaki yorum: $v_S(t) = 2\sin(500t)$ V iken çıkış gerilimi girişten $90^\circ$ geridedir.

## 6. İntegral Alıcı Devre

Bu devrede geri beslemede direnç yerine kondansatör vardır; direnç girişte, eksi uca bağlıdır. Artı giriş yine toprakta. Çözüm:

1. $v_P = 0$ olduğu için $v_N = 0$.
2. Direnç akımı: $i_R = \dfrac{v_S - 0}{R}$.
3. Girişlere akım girmediği için $i_C = i_R$.
4. Kondansatör gerilimi (eksi giriş tarafı artı): $v_C = 0 - v_o = -v_o$.
5. $v_C = \dfrac{1}{C}\int i_C\,dt = \dfrac{1}{C}\int \dfrac{v_S}{R}\,dt$.

Buradan

$$v_o = -\frac{1}{RC}\int v_S\,dt.$$

Çıkış, girişin integralinin $-1/RC$ katıdır. Hoca, eksi işaret ve katsayının uygun seçimle ayarlanabileceğini, böylece analog bilgisayarlarda istenen integral ve türev hesaplarının yapılabileceğini söyledi.

### 6.1 Sinüs girişli örnek (Örnek 03)

Verilenler (ekrandan, 00:45:00): $R = 25\ \text{k}\Omega$, $C = 5$ nF, $v_S(t) = 3\,\text{V}\sin\!\left(6{,}24\text{k}\,\tfrac{\text{rad}}{\text{s}}\,t\right)$, başlangıç $t = 0$ s.

Hoca birim öneklerini hatırlattı: mili $10^{-3}$, mikro $10^{-6}$, nano $10^{-9}$, piko $10^{-12}$. Böylece $RC = 25\times10^{3}\cdot5\times10^{-9}$ s.

İntegral bir aralıkta alındığı için başlangıç değeri eklenir:

$$V_o(t_2) = \frac{-1}{RC}\int_{t_1}^{t_2} V_{in}(t)\,dt + V_o(t_1).$$

$$V_o(t_2) = \frac{-1}{25\,\text{k}\Omega\,(5\,\text{nF})}\int_{t_1}^{t_2} 3\,\text{V}\sin\!\left(6{,}24\text{k}\,t\right)dt + V_o(t_1).$$

Sinüsün integrali eksi kosinüstür; bu eksi, $-1/RC$'deki eksiyle sadeleşir. İçerideki $6240$ çarpanı da paydaya gelir:

$$\frac{3}{RC\cdot6240} = \frac{3\cdot8000}{6240} \approx 3{,}85\ \text{V}.$$

$$V_o(t_2) = 3{,}85\,\text{V}\cos\!\left(6{,}24\text{k}\,t\right)\Big|_{t_1}^{t_2} + V_o(t_1).$$

$t_1 = 0$ alınırsa alt sınırdan $\cos 0 = 1$ gelir. $v_o(t) = -v_C(t)$ ve kondansatör gerilimi süreksiz olamayacağı için çıkış $t = 0$'da sıfırdan başlar. Kosinüs sinüse çevrilince (ekrandan, 00:45:00):

$$V_o(t_2) = 3{,}85\,\text{V}\sin\!\left(6{,}24\text{k}\,t_2 + 90^\circ\right) - 3{,}85\,\text{V}, \qquad t_1 = 0\ \text{s}.$$

Giriş ve çıkış birlikte çizildiğinde aralarında $90^\circ$'lik faz farkı görülür: birinin sıfırdan geçtiği yerde diğeri tepe yapar.

## 7. Başlangıç Gerilimli Kondansatör

Önceki örneklerde kondansatörün başlangıç gerilimi yoktu. Örnek 04'te (ekrandan, 00:50:00) devrede kaynak yoktur:

- Kondansatörün bir ucu op-amp'ın eksi girişine ($v_1$), diğer ucu toprağa bağlı $R_1$ direncine bağlıdır.
- Eksi girişten çıkışa $R_2$ geri besleme direnci vardır; artı giriş ($v_2$) topraktadır.

Kondansatördeki başlangıç gerilimi $R_1$ üzerinde bir gerilim düşümü oluşturur; bu gerilim akımı, akım da kondansatördeki değişimi belirler. Başlangıç gerilimi sanki orada ek bir kaynak varmış gibi modellenebilir. Slayttaki denklemler:

$$i_C(t) - i_{R1}(t) = 0, \qquad C\frac{dv_C(t)}{dt} + \frac{v_C(t)}{R_1} = 0, \qquad \frac{dv_C(t)}{dt} + \frac{v_C(t)}{R_1C} = 0,$$

$$v_C(t) = v_C(t_0)\,e^{-\frac{t-t_0}{R_1C}}, \qquad i_C = C\frac{dv_C(t)}{dt} = -\frac{1}{R_1}v_C(t_0)\,e^{-\frac{t-t_0}{R_1C}}.$$

$R_1C$ zaman sabitidir. $t \to \infty$'da $v_C \to 0$ olur. Hoca bu kısmı zaman darlığından hızlı geçti.

### 7.1 İsteğe bağlı ödev

Hoca iki soruyu zorunlu olmayan ev ödevi olarak bıraktı: türev alıcı ve integral alıcı devreler kondansatör yerine bobin (endüktans) kullanılarak gerçekleştirilebilir mi, gerçekleştirilirse nasıl? (Çözümler "Örnek Sorular" bölümündedir.)

## 8. İkinci Dereceden Devrelere Giriş

İkinci dereceden devre, iki enerji depolayan eleman içeren devredir. İki elemanın integral-diferansiyel denklemleri birlikte çözülür.

### 8.1 Birinci derecede ne oluyordu?

Birinci dereceden devrelerde kabaca $A\,f(x) + B\,f'(x) = 0$ biçiminde bir denklem çıkar (ekrandan, 01:15:00): fonksiyon türeviyle doğrusal bağımlıdır. Türevi kendisine benzeyen fonksiyon aranır. $x^2$ olamaz, çünkü türevi $2x$'tir ve ikisi doğrusal bağımlı değildir. Bir öğrenci $e^x$ diye cevap verdi; hoca onayladı. $e^{5x}$'in türevi $5e^{5x}$'tir; $A = -5$, $B = 1$ alınırsa toplam sıfır olur.

Devrede çözüm $e^{-(t-t_0)/\tau}$ biçimindedir. Bunun bir sabitle çarpımı da çözümdür, bu yüzden genel çözüm

$$A\,e^{-\frac{t-t_0}{\tau}}$$

olur. $\tau$ devredeki $RC$ ya da $L/R$ değerlerinden bulunur. $A$ katsayısı ise **sınır değerlerinden** bulunur. Örneğin $t = 0$'da kapanan bir anahtar düşünülürse kondansatör gerilimi süreklidir: $v_C(0^-) = v_C(0^+)$. Bu eşitlik $A$'yı verir.

### 8.2 İkinci derecede çözüm önerisi

İkinci derecede denklem fonksiyon, birinci türevi ve ikinci türevi arasında doğrusal bir bağıntıdır. Yine üstel bir çözüm önerilir: $f = e^{ax}$. Yerine konunca

$$e^{ax}\,(a^2 + b\,a + c) = 0$$

biçiminde $a$'ya bağlı ikinci dereceden bir denklem çıkar. İki kök $a_1$, $a_2$ bulunur; $e^{a_1x}$ ve $e^{a_2x}$ ayrı ayrı çözümdür. Her biri bir sabitle çarpılabilir ve doğrusal birleşimleri de çözümdür:

$$f = D\,e^{a_1x} + E\,e^{a_2x}.$$

Kökler $R$, $L$, $C$ değerlerinden; $D$ ve $E$ ise iki sınır değerinden bulunur. İki bilinmeyen için iki denklem gerekir.

İkinci dereceden devre örnekleri: bir kondansatör ve bir bobin içeren seri RLC, paralel RLC, iki bobinli ya da iki kondansatörlü devreler. Bu derste incelenen durumlar basamak fonksiyonuna karşılık gelir: kaynağın devreye bağlanması ya da devreden çıkarılması.

## 9. Sınır Koşulları

Dersin amacı (ekrandan, 01:15:00): ikinci dereceden bir devrede gerilim ve akımların sınır koşullarını belirlemek. Bu sınır koşulları devrenin geçici tepkisini hesaplarken kullanılır.

Slayttaki kurallar (ekrandan, 01:20:00):

- **Kararlı hal:** $u(t - t_0)$ basamak tepkisinde, $t = t_0$'dan sonraki kısa bir süre dışında ($t = \pm\infty$ arasında):
  - Kondansatörler açık devredir. Hoca şekliyle açıkladı: iki paralel plaka, DC'de akım geçirmez.
  - Bobinler kısa devredir: dönerek giden bir teldir.
- **Basamak anında ($t = t_0$) geçiş:**
  - Kondansatör gerilimi süreklidir: $v_C(t_0^+) = v_C(t_0^-)$.
  - Bobin akımı süreklidir: $i_L(t_0^+) = i_L(t_0^-)$.

Yöntem şöyledir: başlangıç durumu için devre uzun süre DC şartlarda çalışmış kabul edilir, kondansatörler açık devre, bobinler kısa devre yapılarak başlangıç değerleri bulunur. Sonra $t \to \infty$ için aynı şey yapılır ve devrenin varacağı son değerler bulunur. Elde edilen üstel çözümde $t \to \infty$ konunca çıkan değer, DC çözümüyle tutmalıdır.

> **Hocanın vurgusu:** $t \to \infty$ değerleri, yapılan işlemin doğruluğunu kontrol etmek için mutlaka hesaplanmalıdır.

## 10. Sınır Koşulu Örnekleri

### 10.1 Örnek 01: anahtar açılıyor

Devre (ekrandan, 01:25:00):

- Sol kolda $V_1$ DC kaynağı ve alt telde bir anahtar vardır; anahtar $t = t_0$'a kadar kapalıdır, $t_0$'da açılır.
- $V_1$'in üst ucundan $R_1$ bir orta düğüme gider.
- Orta düğümden alt tele $R_2$ bağlıdır.
- Orta düğümden sağa seri $L_1$ ve $R_3$, ardından sağ kolda $C_1$ alt tele iner.

İstenen: $i_L, v_L, i_C, v_C$ sınır değerleri.

**$t < t_0$ eşdeğer devresi:** bobin kısa devre, kondansatör açık devre çizilir. $R_3$ ve kondansatörün bulunduğu kol açık uçlu kalır, bu yüzden o koldan akım geçmez:

$$i_L = i_C = 0, \qquad v_L = 0.$$

Kondansatör gerilimi, $R_2$ üzerindeki gerilime eşittir. $R_1$ ve $R_2$ gerilim bölücü olarak çalışır; akım $V_1/(R_1 + R_2)$'dir:

$$v_C = \frac{V_1}{R_1 + R_2}\,R_2.$$

**$t > t_0$ (geçiş sonrası):** anahtar açılınca $V_1$ ve $R_1$ devreden çıkar (ekrandan, 01:30:00). Geriye $R_2$, $L_1$, $R_3$, $C_1$'den oluşan tek gözlü bir devre kalır. Kondansatör $V_1R_2/(R_1+R_2)$ gerilimiyle başlar; göz akımını bu gerilim belirler. Göz akımı $i$ için $i = i_C = i_L$ ve

$$i_C = C\frac{dv_C}{dt}, \qquad v_L = L\frac{di}{dt}, \qquad v_C + v_L + i\,(R_2 + R_3) = 0.$$

Hoca yazarken önce bobin bağıntısını yanlış yazdı, sonra düzeltti: manyetik akı $\Phi = L\,i$'dir ve $v_C$ akım cinsinden $\dfrac{1}{C}\int i\,dt$ olarak yazılır. Sonuçta akımın kendisi, türevi ve integrali bulunan bir denklem çıkar; türev alınınca akıma bağlı ikinci dereceden bir diferansiyel denklem olur.

Slayttaki açıklama: bobin ve kondansatörde depolanan enerji $t = t_0$'dan sonra $R_2$ ve $R_3$ üzerinde harcanır.

**$t \to \infty$:** enerji dirençlerde harcandığı için $i_L = 0$, $v_L = 0$, $i_C = 0$, $v_C = 0$.

### 10.2 Örnek 02: iki kaynaklı devre

Bu örneğin devre şekli okunan karelerde yoktur; değerler altyazıdan alındı. <!-- BELİRSİZ: devre şekli ve eleman yerleşimi karelerde görünmüyor; 2 V ve 5 V kaynaklar ile iki 5 kΩ direnç olduğu altyazıdan çıkarıldı -->

Anahtar başta kapalıdır, $t_0$'da açılır. $t < t_0$ için iki kaynak da devrededir. Bir göz için KVL (bobin kısa devre):

$$-2 + i\cdot5\,\text{k}\Omega + i\cdot5\,\text{k}\Omega + 5 = 0 \;\Rightarrow\; i = -0{,}3\ \text{mA}.$$

Bu akım aynı zamanda bobin akımıdır. Bobin kısa devre olduğu için $v_L = 0$, kondansatör açık devre olduğu için $i_C = 0$. Kondansatör gerilimi için başka bir çevre:

$$-2 + i\cdot5\,\text{k}\Omega + v_C = 0 \;\Rightarrow\; v_C = 2 - (-1{,}5) = 3{,}5\ \text{V}.$$

$t \to \infty$ için anahtar açık olduğundan bir kaynak devre dışıdır; kalan göz açık devreyle (kondansatör) tamamlanır. Akım akmaz, kondansatör gerilimi kalan kaynağın gerilimine eşit olur: $v_C = 5$ V. Akımlar sıfırdır, bobin gerilimi sıfırdır.

$t_0$ civarındaki davranış ikinci dereceden diferansiyel denklemle bulunur.

### 10.3 Örnek 03: iki bobinli devre

Devre (ekrandan, 01:35:00):

- Sol kolda $V_1 = 2$ V kaynağı ve alt telde bir anahtar vardır.
- $V_1$'in üst ucundan $R_1 = 5$ kΩ orta düğüme gider.
- Orta düğümden alt tele $L_2 = 40\ \mu$H bobini iner ($i_{L2}$ aşağı doğru, $v_{L2}$ üst uç artı).
- Orta düğümden sağa $L_1 = 10\ \mu$H ($i_{L1}$ sağa doğru, $v_{L1}$ sol uç artı) ve $R_2 = 5$ kΩ seri bağlıdır.
- Sağ kolda $V_2 = 5$ V kaynağı alt tele iner (artı ucu üstte).

İstenen: $i_{L1}, v_{L1}, i_{L2}, v_{L2}$. Anahtar uzun süre açıktır, $t_0$'da kapanır. (Slaytta "It is open at $t = t_0$" yazıyor; hocanın anlatımına ve sonraki slaytlara göre anahtar $t_0$'da kapanır.)

**$t < t_0$:** anahtar açık olduğu için $V_1$ ve $R_1$ devrede değildir. İki bobin kısa devredir. $V_2$, $R_2$ ve bobinler üzerinden bir göz kurulur; akım $5\ \text{V}/5\ \text{k}\Omega = 1$ mA'dir ve $i_{L1}$ okunun tersine, $i_{L2}$ okunun yönündedir:

$$i_{L1} = -1\ \text{mA}, \qquad i_{L2} = 1\ \text{mA}, \qquad v_{L1} = v_{L2} = 0.$$

**$t \gg t_0$** (ekrandan, 01:40:00): iki kaynak da devrededir, iki bobin kısa devredir. Orta düğüm $L_2$ ile alt tele (toprağa) kısa devre olduğu için 0 V'tur.

$$i_{L1} = \frac{0 - 5}{5\ \text{k}\Omega} = -1\ \text{mA}.$$

$V_1$ tarafından orta düğüme gelen akım $\dfrac{2 - 0}{5\ \text{k}\Omega} = 0{,}4$ mA'dir. Orta düğümde KCL:

$$i_{L2} = 0{,}4 - (-1) = 1{,}4\ \text{mA}, \qquad v_{L1} = v_{L2} = 0\ \text{V}.$$

**$t = t_0^+$:** bobin akımları sürekli olduğu için $i_{L1}(t_0^+) = -1$ mA, $i_{L2}(t_0^+) = 1$ mA. Hoca bu değerleri önce ters söyledi, sonra düzeltti. Bu başlangıç koşullarıyla ikinci dereceden diferansiyel denklem kurulup çözülür.

## 11. Seri RLC Devresinin Basamak Tepkisi

Hoca bu kısmı beyaz tahta uygulamasında anlattı (ekrandan, 01:45:00). Slayttaki sayısal değerlere takılmadan önce genel çözüm kuruldu.

### 11.1 Kaynak ve devre

Kaynak $v_s = V_s\,[1 - u(t - t_0)]$ biçimindedir. $u(t - t_0)$, $t_0$'da 0'dan 1'e çıkar; $-u(t - t_0)$, $t_0$'da $-1$'e iner; $1 - u(t - t_0)$ ise uzun süre 1'de kalıp $t_0$'da 0'a düşer. $V_s$ ile çarpılınca: kaynak uzun süre $V_s$ değerindedir, $t_0$'da devreden çıkarılır. Yani önce başlangıç koşulları oluşur, sonra kaynaksız bir RLC devresi çözülür.

Devre: kaynak, seri $L$, seri $R$ ve $C$; kondansatörün alt ucu referans (toprak).

### 11.2 Uç durumlar

**$-\infty < t < t_0$:** bobin kısa devre, kondansatör açık devre. Akım akmaz:

$$i_L(t_0^-) = 0, \qquad v_L(t_0^-) = 0, \qquad i_C(t_0^-) = 0, \qquad v_C(t_0^-) = V_s.$$

**$t \to \infty$:** kaynak sıfırdır. Kondansatördeki enerji direnç üzerinden yavaş yavaş harcanır:

$$i_L(\infty) = 0, \qquad v_L(\infty) = 0, \qquad i_C(\infty) = 0, \qquad v_C(\infty) = 0.$$

### 11.3 Diferansiyel denklem

$t_0$ civarında kaynak çıkarılmıştır; devrede $L$, $R$ ve $v_C(t_0) = V_s$ ile başlayan $C$ vardır. Göz akımı $i$ için $i = i_L = i_C = i_R$ ve KVL:

$$v_L + v_R + v_C = 0.$$

Tanım bağıntıları: $v_L = L\dfrac{di}{dt}$, $v_R = iR$, $v_C = \dfrac{1}{C}\int i\,dt$. Yerine konunca (ekrandan, 01:55:00):

$$iR + L\,i' + \frac{1}{C}\int i\,dt = 0.$$

Her terimin türevi alınırsa integralin türevi kendisi olur:

$$\frac{1}{C}\,i + R\,i' + L\,i'' = 0.$$

Hoca, slayttaki çözümün aynı denklemi $v_C$ cinsinden yazdığını, bunun da aynı sonuca götürdüğünü söyledi.

### 11.4 Karakteristik denklem ve kökler

Kendisi, birinci ve ikinci türevi doğrusal bağımlı bir fonksiyon aranır: $i(t) = e^{\alpha t}$. Yerine konunca

$$\frac{1}{C}e^{\alpha t} + R\,\alpha\,e^{\alpha t} + L\,\alpha^2 e^{\alpha t} = 0 \;\Rightarrow\; e^{\alpha t}\left(\alpha^2L + \alpha R + \frac{1}{C}\right) = 0.$$

$e^{\alpha t}$ sıfır olsaydı $i = 0$ olurdu; aranan çözüm bu değildir. Bu yüzden parantez sıfırdır. $L$'ye bölünürse:

$$\alpha^2 + \alpha\frac{R}{L} + \frac{1}{LC} = 0.$$

İkinci dereceden denklemin kök formülü $\dfrac{-b \pm \sqrt{b^2 - 4ac}}{2a}$ ile:

$$\alpha_1 = \frac{-\dfrac{R}{L} + \sqrt{\dfrac{R^2}{L^2} - \dfrac{4}{LC}}}{2}, \qquad \alpha_2 = \frac{-\dfrac{R}{L} - \sqrt{\dfrac{R^2}{L^2} - \dfrac{4}{LC}}}{2}.$$

### 11.5 Genel çözüm ve katsayılar

İki çözümün doğrusal birleşimi de çözümdür; durum değişimi $t_0$'da olduğu için zaman $t - t_0$ olarak yazılır:

$$i(t) = A\,e^{\alpha_1(t - t_0)} + B\,e^{\alpha_2(t - t_0)}.$$

Birinci koşul: $i_L(t_0) = 0$. $t = t_0$'da iki üstel de 1 olur:

$$A + B = 0.$$

İkinci koşul kondansatörün başlangıç geriliminden ($v_C(t_0) = V_s$) gelir. Hoca bunu akımın integralinin $C\,v_C$'ye eşit olmasıyla ilişkilendirmeye çalıştı. Slayttaki çözüm ise denklemi $v_C$ cinsinden yazar: $i_L$ ve $i_R$, $v_C$'nin türeviyle ilişkilidir; kökler (slaytta $s_1, s_2$) bulunur, $A_1$ ve $A_2$ katsayıları $v_C(t_0)$ ve $i(t_0)$ koşullarıyla iki bilinmeyenli iki denklemden çözülür.

> **Ders sonrası not:** Akım cinsinden çözümde ikinci koşul en kolay KVL'den yazılır. $t_0^+$ anında $i = 0$ olduğundan $v_R = 0$ ve $L\,\dfrac{di}{dt}(t_0^+) = -v_C(t_0^+) = -V_s$ olur. Buradan $A\alpha_1 + B\alpha_2 = -V_s/L$ elde edilir; $A + B = 0$ ile birlikte $A = -B = \dfrac{-V_s}{L(\alpha_1 - \alpha_2)}$ bulunur. Hocanın tahtada integral üzerinden yazdığı ikinci denklem büyük olasılıkla bu koşula karşılık gelir.

### 11.6 Köklerin durumu

Hoca bir sonraki derste köklerin durumuna göre üç senaryonun ayrıntılı inceleneceğini söyledi: kökler iki ayrı gerçel sayı, eşit ya da karmaşık eşlenik olabilir. Bunlar sırasıyla aşırı sönümlü (overdamped), kritik sönümlü (critically damped) ve az sönümlü (underdamped) durumlardır.

## 12. Vize Sorularının Çözümü

Dersin son saatinde iki şubenin öğrencileri tek oturumda birleşti ve vize soruları bir asistan tarafından çözüldü. Zaman yetmediği için bazı sorular yalnız cevabıyla geçildi. Asistanın genel tavsiyesi: soruları karmaşık yollara sapmadan, basit düşünerek çözmek. Soruların metinleri ve çözümleri "Örnek Sorular" bölümündedir.

## Örnek Sorular

### Soru 1: Türev alıcıya üçgen dalga (derste sözlü, 00:18:15)

Türev alıcıya üçgen dalga uygulanırsa çıkış nasıl olur?

**Cevap (derste verildi):** Eğim pozitifken çıkış negatif sabit, eğim negatifken pozitif sabittir; çıkış kare dalgadır. Parabol parçalarından oluşan bir girişte ise çıkış üçgen dalgaya benzer.

### Soru 2: Bobinli türev alıcı (derste sözlü, 00:50:09)

Türev alıcı devre kondansatör yerine bobin kullanılarak gerçekleştirilebilir mi?

> **Çözüm (derste verilmedi):** Evet. Girişe seri $R$, geri beslemeye $L$ konur. Eksi giriş 0 V olduğu için giriş akımı $i = v_S/R$'dir ve tamamen bobinden geçer. Bobin gerilimi $v_L = L\,di/dt$, çıkış $v_o = 0 - v_L$ olduğundan $v_o = -\dfrac{L}{R}\dfrac{dv_S}{dt}$ bulunur.

### Soru 3: Bobinli integral alıcı (derste sözlü, 00:50:35)

İntegral alıcı devre bobin kullanılarak gerçekleştirilebilir mi?

> **Çözüm (derste verilmedi):** Evet. Girişe seri $L$, geri beslemeye $R$ konur. Bobin uçları arasındaki gerilim $v_S$'dir, akımı $i = \dfrac{1}{L}\int v_S\,dt$ olur. Bu akım dirençten geçer ve $v_o = -R\,i = -\dfrac{R}{L}\int v_S\,dt$ elde edilir.

### Soru 4: Vize 1 (ekrandan, 02:15:00)

Soru metni karede görünmüyor; seçenekler: a) 2 V, b) 4 V, c) 0 V, d) −2 V, e) −4 V. <!-- BELİRSİZ: soru metni ve devre karede yok; asistan aynı devrenin bir sonraki soruda da kullanıldığını söyledi -->

**Çözüm (derste verildi):** Devrede üç göz vardır; asistan KVL ile göz denklemlerini sırayla yazdı (24 V, 4 V, 2 V, −3 V, 6 V gerilimleri işaretleriyle toplandı) ve cevabı −4 V (e) buldu.

### Soru 5: Vize 2 (ekrandan, 02:15:00)

"B elemanından sola doğru 10 A, $R_3$ direncinden aşağı doğru 3 A ve $R_4$ direncinden aşağı doğru 5 A akım akarsa, $R_5$ direncinden geçen akımın değeri ve $v_x$ polarizasyonu referansında yönü nedir?"

Devre:

- Üst kolda soldan sağa: 24 V kaynağı, $R_2$ (üzerinde 4 V), A elemanı (2 V), 3 V kaynağı.
- Dikey kollar soldan sağa: $R_1$ (üzerinde 6 V), $R_3$, $R_4$, $R_5$ (üzerinde $v_x$).
- Alt kolda: B elemanı (3 V, $R_1$ ile $R_3$ arasında), C elemanı (8 V, $R_4$ ile $R_5$ arasında).

Seçenekler: a) 2 A, b) 4 A, c) 0 A, d) −2 A, e) −4 A.

**Çözüm (derste verildi, ekrandan, 02:25:00):** Üç gözün saat yönündeki akımları $I_A$, $I_B$, $I_C$ olsun.

- $R_3$'ten aşağı 3 A: $I_A - I_B = 3$ A. Birinci gözden $(I_B - I_A)R_3 = -11$ V.
- İkinci göz: $(I_B - I_A)R_3 - 2\,\text{V} + R_4(I_B - I_C) = 0$. $R_4$'ten aşağı 5 A: $I_B - I_C = 5$ A, buradan $R_4(I_B - I_C) = 13$ V.
- Üçüncü göz: $13 - 3 - 8 - v_x = 0 \Rightarrow v_x = 2$ V.
- $I_A = I_B + 3 = I_C + 5 + 3$; B elemanındaki 10 A, $I_A$'ya karşılık gelir: $10 = I_C + 8 \Rightarrow I_C = 2$ A.

$v_x$ pozitif çıktığı için akım referans yönündedir: cevap 2 A (a).

### Soru 6: Vize 3 (ekrandan, 02:25:00)

"Aşağıda verilen devre için, anahtar uzun süre kapalı kaldığında her kondansatörde depolanan gerilim değerlerini bulunuz."

Devre:

- Sol kolda seri 20 kΩ ve 20 V kaynağı.
- Üst düğüm A'dan sağdaki düğüme 30 kΩ; aynı iki düğüm arasında $C_1 = 4\ \mu$F.
- A düğümünden alt tele $C_2 = 2\ \mu$F.
- Sağdaki düğümden alt tele seri $C_3 = 3\ \mu$F ve 40 kΩ.
- En sağda 50 kΩ alt tele iner. Alt telde bir anahtar vardır.

**Çözüm (derste verildi):** DC'de kondansatörler açık devredir; 40 kΩ'dan akım geçmez. Akım 20 kΩ, 30 kΩ ve 50 kΩ üzerinden akar. $V_{C2}$, A noktası ile alt tel arasındaki gerilimdir:

$$\frac{V_{C2}}{V_{top}} = \frac{30 + 50}{30 + 50 + 20} = \frac{4}{5} \;\Rightarrow\; V_{C2} = 16\ \text{V}.$$

$V_{C1}$ 30 kΩ üzerindeki, $V_{C3}$ ise 50 kΩ üzerindeki gerilimdir:

$$\frac{V_{C1}}{V_{C3}} = \frac{30}{50} = \frac{3}{5}, \quad V_{C1} + V_{C3} = 16\ \text{V} \;\Rightarrow\; V_{C1} = 6\ \text{V},\; V_{C3} = 10\ \text{V}.$$

Cevap c) $V_{C1} = 6$ V, $V_{C2} = 16$ V, $V_{C3} = 10$ V.

### Soru 7: Vize 4 (ekrandan, 02:30:00)

"Aşağıdaki devre için eşdeğer kapasitansı ($C_{eq}$) hesaplayınız."

Devre ($C_{eq}$, a ve b uçları arasında):

- Sol parça: 12 F ve 10 F birbirine paralel, sol üst düğüm ile a tarafındaki düğüm arasında. Sol üst düğümden alt tele 7 F. a tarafındaki düğümden alt tele 4 F.
- Sağ parça: b düğümünden yukarı açık uçlu 2 F (devreye katılmaz). b düğümünden alt tele 5 F. b düğümünden sağa 12 F, onun sağ ucundan alt tele 1 F.

Seçenekler: a) 2 F, b) 3 F, c) 3,6 F, d) 6,8 F, e) 17,2 F.

**Çözüm (derste verildi):** Kapasitörlerde kural dirençlerin tersidir: paralel olanlar toplanır, seri olanlar ters toplanır.

- Sol: $(12 + 10) = 22$ F, 7 F ile seri: $\left(\tfrac{1}{22} + \tfrac{1}{7}\right)^{-1} = \tfrac{154}{29}$ F; 4 F ile paralel: $\tfrac{154}{29} + 4 = \tfrac{270}{29}$ F.
- Sağ: 12 F ile 1 F seri: $\tfrac{12}{13}$ F; 5 F ile paralel: $\tfrac{12}{13} + 5 = \tfrac{77}{13}$ F.
- İki parça alt tel üzerinden seri: $C_{eq} = \left(\tfrac{29}{270} + \tfrac{13}{77}\right)^{-1}$.

Cevap c) 3,6 F.

> **Ders sonrası not:** Çözüm belgesinde son değer 3,6189 F olarak yazılmış. Python ile hesap $20790/5743 \approx 3{,}620$ F veriyor; fark küçük bir aritmetik kaymadır, seçenek değişmez.

### Soru 8: Vize 5 (ekrandan, 02:35:00)

"Aşağıdaki devreyi analiz edin ve $V_o$ değerini hesaplayın."

Devre:

- 9 V kaynağı, 100 Ω üzerinden op-amp'ın eksi girişine bağlı.
- Eksi girişten çıkışa geri besleme yolunda iki adet 850 Ω seri (toplam 1700 Ω).
- Artı giriş düğümü: alttan yukarı 1 mA akım kaynağı ile beslenir; aynı düğümden alt tele 10 kΩ.
- Çıkıştan alt tele 250 Ω; $V_o$ bu direnç üzerindeki gerilimdir.

Seçenekler: a) 18 V, b) −12 V, c) 12 V, d) 27 V, e) −9 V.

**Çözüm (derste verildi):** Artı girişe akım girmez; 1 mA tamamen 10 kΩ'dan geçer: $V_1 = 1\ \text{mA}\cdot10\ \text{k}\Omega = 10$ V. Eksi giriş de 10 V'tur. 100 Ω'dan geçen akım değişmeden 1700 Ω'dan geçer:

$$\frac{10 - V_2}{1700} = \frac{9 - 10}{100} = -\frac{1}{100} \;\Rightarrow\; 10 - V_2 = -17 \;\Rightarrow\; V_2 = 27\ \text{V}.$$

$V_o = V_2 = 27$ V. Asistan devrenin evirmeyen kuvvetlendirici olduğunu söyledi ve önemli noktanın $10 - V_2$ ifadesini doğru işaretle yazmak olduğunu vurguladı.

**Soru:** $10 - V_2$ ifadesi neden böyle yazıldı?
**Cevap:** Eksi girişteki gerilim 10 V'tur; geri besleme direncindeki akım $(10 - V_2)/1700$'dür ve 100 Ω'daki akıma eşittir. $V_2 - 10$ diye yazılsa sağ taraf da işaret değiştirir, sonuç aynıdır.

**Soru:** Akım kaynağı ile 10 kΩ'u Thevenin eşdeğerine çevirerek çözülebilir mi?
**Cevap:** Gerek yoktur; op-amp sorularında Thevenin-Norton dönüşümüne başvurmak yerine ideal op-amp bağıntılarıyla basit düşünmek daha kolaydır.

> **Ders sonrası not:** Vize belgesinde c) 12 V şıkkı işaretli görünüyor (ekrandan, 02:35:00). Hem çözüm belgesi hem asistan hem de python hesabı 27 V buluyor; doğru seçenek büyük olasılıkla d) 27 V'tur.

### Soru 9: Vize 6 (ekrandan, 02:35:00)

"Düğüm analizi yöntemini kullanarak düğüm gerilimlerini bulunuz." <!-- BELİRSİZ: devre şekli okunan karelerde görünmüyor -->

**Çözüm (derste verildi):** Çözüm belgesindeki denklemler: $V_1 = V_3 - 8I_2$, $V_2 = V_1 - 20I_1$, $V_3 = V_4 - 12I_4$, $V_4 = 15$ V. Sonuç: $V_1 = 22{,}4$ V, $V_2 = 27{,}4$ V, $V_3 = 17{,}4$ V. Devre karede olmadığı için bu değerler doğrulanamadı.

**Soru:** $V_2$ denklemi neden $V_1 - 20I_1$?
**Cevap:** $I_1$, 20 Ω üzerinden geçen göz akımıdır ve bu devrede $V_1$ daha yüksek potansiyeldedir.

### Soru 10: Vize 7 (ekrandan, 02:50:00)

Göz akımları $i_1$ ve $i_3$'ün bulunması istenir; bağımlı kaynak ($5V_a$) içerir. Doğru seçenek d) $i_1 = -0{,}8$, $i_3 = -1{,}7$. <!-- BELİRSİZ: soru metni ve devre okunan karelerde görünmüyor -->

**Çözüm (derste verildi, ekrandan, 02:50:00):** Çözüm belgesinde: $30I_3 + 5V_a + 20(I_3 - I_2) = 0$, buradan $-10I_b + 15 = V_a$. Yukarı doğru 2 A'lık kaynaktan $I_2 = -2$ A. $I_3 = I_b - 2$, $I_1 = 4I_b - 2$; $V_a = 10(I_1 - I_2) = 40I_b$. Eşitlenince $-10I_b + 15 = 40I_b \Rightarrow I_b = 0{,}3$ A, $I_1 = -0{,}8$ A, $I_3 = -1{,}7$ A. Bu ara sonuçlar kendi içinde tutarlıdır (python ile kontrol edildi).

### Soru 11: Vize 8 (ekrandan, 02:50:00)

"Mikrodalga elektroniğinde, yükün empedansı, kaybı ortadan kaldırmak için reaktif elemanların eklenmesiyle iletim hattının empedansına uyarlanır. Devre teorisinden hangi teorem yukarıda belirtilen uygulama ile yakından ilişkilidir?"

Seçenekler: a) Norton teoremi, b) Thevenin teoremi, c) Maksimum güç teoremi, d) KCL, e) KVL.

**Çözüm (derste verildi):** Empedans uyumlaması maksimum güç aktarımıyla ilgilidir: c).

### Soru 12: Vize 9 (ekrandan, 02:50:00)

"Verilen $i(t)$ akımını sadece adım fonksiyonlarının toplamı olarak yazabilmek için gereken birim adım fonksiyonlarının sayısı nedir?" Grafik: 4 mA genlikli darbeler. <!-- BELİRSİZ: grafiğin tamamı karede görünmüyor -->

Seçenekler: a) 3, b) 4, c) 5, d) 6, e) 7.

**Çözüm (derste verildi, ekrandan, 02:55:00):** İşaretteki her değişim (her yükselen ve düşen kenar) bir adım fonksiyonu gerektirir; asistan grafiğe göre 5 adım fonksiyonu gerektiğini söyledi: c).

### Soru 13: Vize 10 (ekrandan, 02:55:00)

"R = 100 ohm olan bir sonsuz merdiven devresinin AB terminalleri arasındaki eşdeğer direnci nedir?" Devre: A ucundan seri R, ardından düğümden B hattına paralel R; bu yapı sağa doğru sonsuz kez tekrar eder.

Seçenekler: a) 100 Ω, b) 133,33 Ω, c) 161,8 Ω, d) 333,33 Ω, e) 200 Ω.

**Soru (bir öğrencinin yaklaşımı):** İlk seri R dışındaki kısım sonsuz paralel olduğu için ihmal edilebilir mi?
**Cevap:** Hayır. Devre kendini tekrar eder.

**Çözüm (derste verildi):** İlk basamaktan sonraki kısım yine $R_x$'tir. Bu yüzden

$$R_x = R + \frac{R\,R_x}{R + R_x} \;\Rightarrow\; R_x^2 - R\,R_x - R^2 = 0 \;\Rightarrow\; R_x = \frac{1 + \sqrt5}{2}\,R.$$

$R = 100\ \Omega$ için $R_x = 50 + 50\sqrt5 \approx 161{,}8\ \Omega$: c).

### Soru 14: Vize 11 (ekrandan, 03:10:00)

"Verilen devredeki anahtar uzun süredir açıktır. $t = 0$'da anahtar kapatıldığında, $t \ge 0$ için $v(t)$'yi bulunuz."

Devre (soldan sağa, hepsi üst ve alt raylar arasında): 20 mA akım kaynağı (yukarı), $t = 0$'da kapanan anahtar, 20 kΩ, 60 kΩ; ardından üst rayda seri 10 kΩ ve sağ kolda 40 nF kondansatör ($v$ üst uç artı).

Seçenekler: a) $120e^{-277{,}78t}$ V, b) $300e^{-1000t}$ V, c) $300e^{-277{,}78t}$ V, d) $120e^{-1000t}$ V, e) Hiçbiri.

**Çözüm (derste verildi):** Anahtar açıkken kondansatör açık devredir; 20 mA, $20\ \text{k}\Omega \parallel 60\ \text{k}\Omega = 15$ kΩ üzerinden akar: $v(0) = 20\ \text{mA}\cdot15\ \text{k}\Omega = 300$ V. Asistan zaman sabitini $(15 + 10)\ \text{k}\Omega\cdot40\ \text{nF} = 1$ ms aldı ve $v(t) = 300\,e^{-1000t}$ V (b) buldu.

> **Ders sonrası not:** Asistan "1000 milisaniye" dedi ve bunu "frekans" diye andı; $25\ \text{k}\Omega\cdot40\ \text{nF}$ aslında 1 ms'lik bir zaman sabitidir, üsteki 1000 değeri $1/\tau$'dur. Ayrıca karedeki şekilde anahtar raylar arasında paralel çizilmiştir; kapandığında 20 kΩ ve 60 kΩ kısa devre olur ve kondansatör yalnız 10 kΩ üzerinden boşalır. Bu durumda $\tau = 10\ \text{k}\Omega\cdot40\ \text{nF} = 0{,}4$ ms ve $v(t) = 300\,e^{-2500t}$ V olur (python ile kontrol edildi). Belgedeki b) şıkkı büyük olasılıkla anahtarın kaynağı devreden ayırdığı bir çizime göredir.

### Soru 15: Vize 12 (ekrandan, 03:15:00)

"Verilen devre için $R_2$ ve $R_3$'ten geçen akım $I_{R2}$ ve $I_{R3}$'ü süperpozisyon uygulayarak bulunuz."

Devre: a düğümünden $R_1 = 10$ kΩ ile $V_1$ düğümüne, oradan $R_4 = 12$ kΩ ile $V_2$ düğümüne. $V_1$ düğümünden b'ye seri $R_2 = 5$ kΩ ve $E_1 = 10$ V. $V_2$ düğümünden b'ye seri $R_5$ ve $E_2 = 8$ V. a ile b arasında 2 mA akım kaynağı; a'dan sağa giden üst hattan b'ye $R_3$ (çözüm kâğıdında 6 kΩ). <!-- BELİRSİZ: R5 değeri ve devrenin sağ kısmı karede görünmüyor -->

Seçenekler: a) $I_{R2} = 1{,}27$ mA, $I_{R3} = 1{,}58$ mA; b) $I_{R2} = 1{,}12$ mA, $I_{R3} = 1{,}32$ mA; d) $I_{R2} = 1{,}55$ mA, $I_{R3} = 1{,}84$ mA; e) Hiçbiri (c şıkkı karede kapalı).

**Çözüm (derste verildi, ayrıntılı işlem yapılmadı):** Süperpozisyonda her seferinde bir bağımsız kaynak bırakılır: akım kaynağı açık devre, gerilim kaynağı kısa devre yapılır; her alt devredeki akımlar toplanır.

1. Akım kaynağı açık devre: düğüm denklemleri

$$\frac{V_1 - V_{ab}}{R_1} + \frac{V_1 - 10}{R_2} + \frac{V_1 - V_2}{R_4} = 0, \qquad \frac{V_2 - V_1}{R_4} + \frac{V_2 + 8}{R_5} = 0,$$

$$I_{R2}' = \frac{V_1 - 10}{R_2}, \qquad I_{R3}' = \frac{V_{ab} - 0}{R_3}.$$

2. Gerilim kaynakları kısa devre: aynı düğümler için denklemler yeniden yazılır, $I_{R2}''$ ve $I_{R3}''$ bulunur.
3. Toplam: $I_{R2} = I_{R2}' + I_{R2}''$, $I_{R3} = I_{R3}' + I_{R3}''$. Sonuç d) $I_{R2} = 1{,}55$ mA, $I_{R3} = 1{,}84$ mA. $R_5$ değeri görünmediği için sonuç doğrulanamadı.

### Soru 16: Kalan vize soruları (derste sözlü, 03:18:32)

Asistan zaman kalmadığı için kalan soruların yalnız cevaplarını verdi: 16. soruda düğüm yöntemi ya da başka bir yöntemle sonuç ohm cinsinden bulunur; 18. soruda DC şartlarda bobinin kısa devre, kondansatörün açık devre gibi davrandığı kullanılır; 20. soruda doğru fonksiyon a) şıkkıdır. <!-- BELİRSİZ: 13-20. soruların metinleri ve sayısal cevapları altyazıda net değil, karelerde görünmüyor -->

## Dersin Toparlaması

Bu derste önce kondansatörlü op-amp devreleri tamamlandı. Türev alıcıda girişte kondansatör, geri beslemede direnç vardır ve çıkış $-RC\,dv_S/dt$'dir. İntegral alıcıda yerleri değişir ve çıkış $-\frac{1}{RC}\int v_S\,dt$ artı başlangıç değeridir. Basamak ve sinüs girişli örneklerde zaman sabiti, beş zaman sabiti kuralı ve sinüs-kosinüs dönüşümleriyle faz düzenlemesi kullanıldı. Bu dönüşümler, sonraki haftalarda işlenecek fazör yönteminin hazırlığıdır.

İkinci kısımda ikinci dereceden devrelere geçildi. Çözüm üstel fonksiyonların doğrusal birleşimidir; üsler devre elemanlarından gelen karakteristik denklemin kökleridir, katsayılar iki sınır koşulundan bulunur. Sınır koşulları için DC kararlı halde kondansatör açık, bobin kısa devre alınır; geçiş anında kondansatör gerilimi ve bobin akımı süreklidir. Seri RLC devresi için $L\,i'' + R\,i' + i/C = 0$ denklemi kuruldu. Sonraki derste köklerin gerçel, eşit ya da karmaşık olmasına göre aşırı sönümlü, kritik sönümlü ve az sönümlü yanıtlar incelenecektir. Son saatte vize soruları çözülerek KVL, düğüm analizi, kondansatörlü DC devreler, op-amp, RC geçici hal ve süperpozisyon konuları tekrar edildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
