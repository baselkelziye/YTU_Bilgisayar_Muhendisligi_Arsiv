# Ders 25 Genişletilmiş Notu: İşlemsel Yükselteçler (Op-Amp) ve Temel Op-Amp Devreleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Op-amp nedir, nerede kullanılır
- 2. Op-amp sembolü, bacakları ve besleme sınırı
- 3. İdeal op-amp'ın iki kabulü
- 4. Gerilim kıyaslayıcı
- 5. Kapalı çevrim ve eviren yükselteç
- 6. Kazanç türleri ve gerçek op-amp
- 7. Doyum: eviren yükselteç sayısal örneği
- 8. Evirmeyen yükselteç
- 9. Gerilim izleyici
- 10. Toplayıcı yükselteç ve süperpozisyon
- 11. Fark alıcı devre
- 12. Kaskat yükselteçler
- 13. Genel tekrar ve yöntem üzerine
- Örnek Sorular

## 1. Op-amp nedir, nerede kullanılır

Op-amp, İngilizce "operational amplifier" teriminin kısaltmasıdır; Türkçede işlemsel yükselteç denir ve pratikte hep kısaltmasıyla anılır. Hocanın tanımıyla op-amp, girişteki gerilimi çıkışta yükselten bir devre elemanıdır. Burada "yükseltme" sözcüğü yalnız pozitif yönde büyütme anlamına gelmez: çıkış negatif yönde de büyüyebilir, yani giriş geriliminin işareti de değişebilir. Ortak nokta, girişteki gerilimin çıkışta belirli bir kurala göre değişmesidir.

Dersin hedef slaytında birinci dereceden op-amp devreleri, türev alıcı (differentiator) ve integral alıcı (integrator) devrelerin denklemleri ve giriş ile çıkış arasındaki faz kaymasının kaynağı listelenmişti (ekrandan, 00:20:00). Hoca bu devrelerden kısaca söz etti, ama dersin sonunda onları konu dışında bıraktı; ders temel op-amp devreleriyle sınırlı kaldı.

Hocanın saydığı tipik kullanım biçimleri şunlardır:

- Çoğaltıcı (multiplier) diye andığı, girişi belirli bir katsayıyla büyüten devreler. Bunun iki alt türü vardır: eviren ve evirmeyen yükselteç.
- Toplayıcı (summing) devreler. Burada "toplama", giriş gerilimlerinin doğrudan toplanması anlamına gelmez; giriş gerilimlerinin bir kombinasyonuna göre çıkışta bir gerilim üretilir.
- Fark alıcı (difference, subtractor) devreler. Bunlar da girişlerin bir kombinasyonuna göre çıkış üretir.
- Kaskat, yani ardı ardına bağlanmış yükselteç devreleri.

> **Ders sonrası not:** Hoca dersin başında türev ve integral alıcı devreleri bir yerde "ikinci dereceden" devreler diye andı, birkaç cümle sonra da onları birinci dereceden devrelerle birlikte saydı. Tek kapasitörlü türev ve integral alıcılar birinci dereceden devrelerdir; dersin hedef slaytı da onları "1st order" başlığı altında verir (ekrandan, 00:20:00). İkinci dereceden devreler iki enerji depolayıcı (örneğin RLC) içerir; hoca da RLC devrelerine geçilmeyeceğini söyledi.

## 2. Op-amp sembolü, bacakları ve besleme sınırı

### 2.1 Sembol ve bacaklar

Op-amp devre şemasında bir üçgenle gösterilir. Ayrıntılı çizilmeyen şemalarda üç bacak görünür. "+" işaretli giriş evirmeyen giriştir (non-inverting input), "−" işaretli giriş eviren giriştir (inverting input), üçgenin ucu da çıkıştır ($v_o$, "Vout"). Bunlara ek olarak $V^+$ ve $V^-$ besleme gerilimlerini alan iki bacak vardır.

Ekranda ideal op-amp sembolünün yanında gerçek entegrelerin sembolleri gösterildi: uA741 (3 "+", 2 "−", 7 $V^+$, 4 $V^-$, 6 çıkış, 1 ve 5 offset), LM111 kıyaslayıcı ve dört op-amp'lı LM324 (3 "+", 2 "−", 4 $V^+$, 11 $V^-$, 1 çıkış) (ekrandan, 00:25:00). Ardından LM741 entegresinin 8 bacaklı kılıfı gösterildi: 1 offset null, 2 eviren giriş, 3 evirmeyen giriş, 4 $V^-$, 5 offset null, 6 çıkış, 7 $V^+$, 8 bağlantısız (NC) (ekrandan, 00:30:00). Hoca bacakların dörderli iki sıra hâlinde dizildiğini, ikisinin besleme, birinin çıkış olduğunu, offset gibi diğer bacakların bu ders için önemli olmadığını söyledi.

### 2.2 Besleme gerilimi kazancı sınırlar

Teoride ideal op-amp'ın kazancı sonsuz kabul edilir. Pratikte bu mümkün değildir; hocanın deyişiyle op-amp "yoktan var edemez". Çıkışın ulaşabileceği en yüksek ve en düşük değerleri $V^+$ ve $V^-$ besleme gerilimleri belirler.

Ekrandaki örnekte devre girişi 10 katına çıkaracak biçimde kurulmuştur ve girişe 10 V verilmiştir (ekrandan, 00:25:00). Hesapla 100 V beklenir. Ama besleme +15 V ve −15 V ise çıkış 100 V olamaz, 15 V'ta kalır. Benzer biçimde beslemeler −18 V ve +18 V ise devrenin çıkışı −18 V ile +18 V arasında kalır.

> **Ders sonrası not:** Hoca bu örnekte "maksimum kazanç 100 değil 15 volt olacak" dedi. Kastedilen kazanç değil çıkış gerilimidir: kazanç 10'dur, çıkış gerilimi 100 V yerine 15 V'ta sınırlanır.

Soru çözerken teoride op-amp'ın hesaplanan kazancı sağladığı kabul edilir; ancak hesaplanan çıkış beslemenin dışına düşüyorsa çıkış o beslemede kalır. Bu konu 7. bölümde sayısal olarak işlenir.

## 3. İdeal op-amp'ın iki kabulü

Hoca op-amp sorularını çözerken iki kabul yapılacağını söyledi ve bunları ders boyunca her devrede kullandı. Kabullerin gösterildiği şemada op-amp'ın içi, girişler arasındaki iç direnç $R_i$ ve çıkıştaki bağımlı gerilim kaynağı $A v_d$ ile modellenmiştir (ekrandan, 00:40:00).

### 3.1 Birinci kabul: girişlerden akım akmaz

Eviren ve evirmeyen giriş bacaklarından op-amp'ın içine akım girmez: $i_1 = i_2 = 0$. Hocanın gerekçesi şudur: idealde iç direnç $R_i$ sonsuz kabul edilir, sonsuz direnç açık devre demektir; açık devreden akım geçmez.

Bu kabulün işe yararlığını hoca şöyle anlattı. Eviren girişin bağlı olduğu düğüme $R_1$'den $i_s$ akımı gelir, bu düğümden $R_f$'ye $i_f$ akımı ve op-amp'ın içine bir sızıntı akımı gider. Sızıntı akımı sıfır alınmazsa $i_s = i_f + i_{\text{sızıntı}}$ gibi birden fazla bilinmeyenli bir denklem çıkar; sızıntı akımını bulmak için $v_d$'yi bilmek ve $v_d / R_i$ hesaplamak gerekir. Akım sıfır kabul edilince doğrudan $i_s = i_f$ yazılabilir.

Soruda op-amp'ın ideal olmadığı ve iç direncinin değeri verilmedikçe bu kabul yapılır.

### 3.2 İkinci kabul: girişlerin gerilimleri eşittir

İki giriş noktasındaki gerilimler birbirine eşittir: $v_1 = v_2$, yani $v_d = v_1 - v_2 = 0$. Şemanın altında da "op-amp, çıkışı $V_1 = V_2$ olacak biçimde üretir" cümlesi yazılıdır (ekrandan, 00:40:00).

Bu kabulün önemli bir sonucu vardır: girişlerden biri topraklıysa diğer giriş de 0 V'tadır. Bu noktaya "sanal toprak" (virtual ground) denir; slaytta da eviren girişin bağlı olduğu düğüm bu adla işaretlidir.

> **Hocanın vurgusu:** Bu iki kabul, ideal op-amp sorularını çözmek için zorunludur. Soruların hepsi bu kabullerle çözülecektir.

### 3.3 Gerilim kazancı

Op-amp devrelerinde hesaplanan temel parametre gerilim kazancıdır (voltage gain): çıkış geriliminin giriş gerilimine oranı, $A_v = v_o / v_s$. Hocanın örneğiyle, "gerilim kazancı 5 olan bir devre tasarlayın" denirse, çıkışta girişin 5 katı gerilim veren bir devre istenmektedir.

Hoca bu kısımların Devre Teorisi dersinde daha ayrıntılı işlendiğini, burada hatırlatma amacıyla geçildiğini belirtti.

## 4. Gerilim kıyaslayıcı

### 4.1 Çalışma ilkesi

İlk devre gerilim kıyaslayıcıdır (comparator). Bu devrede geri besleme yoktur. Girişlerden birine ölçülecek gerilim, diğerine bir referans gerilimi verilir ve op-amp iki giriş gerilimini karşılaştırır. Şemada beslemeler çizilmemiştir, ama op-amp'ın $+V$ ve $-V$ beslemeleri vardır.

Kural şudur: hangi girişin gerilimi daha büyükse çıkış, o girişin işaretine karşılık gelen beslemeye gider.

- $v_2 > v_1$ (evirmeyen giriş daha büyük) ise $v_o = +V$.
- $v_1 > v_2$ (eviren giriş daha büyük) ise $v_o = -V$.

Hoca ilk örneği eviren girişe bir $v_s$ gerilimi, evirmeyen girişe 0 V referans verilmiş bir devre üzerinde anlattı. Besleme ±15 V olsun. Eviren girişe 5 V verilirse, 5 V sıfırdan büyüktür ve eviren uçta olduğu için çıkışta −15 V görülür. Eviren girişe −5 V verilirse giriş referanstan küçüktür ve çıkışta +15 V görülür.

Kullanım alanı olarak hoca anahtarlamayı gösterdi. Girişe örneğin sıcaklıkla değişen bir sensör ya da ayarlı direnç (reosta) üzerinden bir gerilim bağlanır, diğer girişe bir referans verilir. Ölçülen gerilim referansı geçtiğinde çıkış bir beslemeden diğerine geçer ve bu çıkış başka bir devreyi tetiklemek için kullanılabilir. Hoca bu davranışı transistörün anahtar olarak çalışmasına benzetti.

### 4.2 Ekrandaki kıyaslayıcı örneği

Slaytta $v_s$ eviren girişe ($v_1$), 5 V'luk bir kaynak evirmeyen girişe ($v_2$) bağlıdır ve $v_s = 0$, 5 ve 6 V için $v_o$ sorulmaktadır (ekrandan, 00:35:00). Çözüm 4. sorunun cevabı olarak Örnek Sorular bölümünde verilmiştir.

Hoca op-amp'ların genelde kıyaslama için değil, kazanç sağlamak, yani girişteki bir seviyeyi çıkışta yükseltmek ya da işaretini değiştirmek için kullanıldığını ekledi.

## 5. Kapalı çevrim ve eviren yükselteç

### 5.1 Kapalı çevrim

Kazançtan söz edebilmek için op-amp kapalı çevrim bağlanmalıdır. Kapalı çevrim, çıkışın bir dirençle ($R_f$) girişlerden birine geri bağlanmasıdır. Hoca bu bağlantının artı ya da eksi girişe yapılabileceğini, çözümün buna göre değişeceğini, ama çözüm mantığının aynı kalacağını söyledi.

> **Ders sonrası not:** Hoca $R_f$ için "feed forward", "geri besleme" ve "ileri besleme direnci" ifadelerini art arda kullandı. $R_f$ geri besleme (feedback) direncidir; çıkışı girişe geri bağlar.

Hoca formülleri vereceğini ama asıl önemli olanın formülün nasıl çıktığını anlamak olduğunu, böylece farklı bir soru biçimiyle karşılaşıldığında da çözüm yapılabileceğini söyledi.

### 5.2 Eviren yükselteçte kazancın çıkarılışı

Devrede $v_s$ kaynağı $R_1$ üzerinden eviren girişe bağlıdır, $R_f$ çıkıştan eviren girişe geri besleme yapar, evirmeyen giriş topraklıdır (ekrandan, 00:40:00).

1. Op-amp ideal olduğu için $i_1 = i_2 = 0$ ve $v_1 = v_2$.
2. Evirmeyen giriş toprakta olduğu için $v_2 = 0$; ikinci kabulden $v_1 = 0$.
3. $R_1$'den geçen akım: $i_s = \dfrac{v_s - v_1}{R_1}$.
4. $R_f$'den geçen akım (akım yönü düğümden çıkışa doğru alınmıştır): $i_f = \dfrac{v_1 - v_o}{R_f}$.
5. Op-amp'a akım girmediği için $i_s = i_f$:
   $$\frac{v_s - v_1}{R_1} = \frac{v_1 - v_o}{R_f}$$
6. $v_1 = 0$ yazılırsa: $\dfrac{v_s}{R_1} = -\dfrac{v_o}{R_f}$.
7. Aranan oran $v_o / v_s$ olduğuna göre:
   $$A_v = \frac{v_o}{v_s} = -\frac{R_f}{R_1}$$

Kazancı belirleyen, geri besleme direncinin girişteki dirence oranının negatifidir. Eksi işaret formülden gelir, ama hoca bunun fiziksel olarak da beklendiğini söyledi: giriş eviren uca bağlandığı için çıkışın işareti ters döner.

## 6. Kazanç türleri ve gerçek op-amp

### 6.1 Diğer kazançlar

Sorularda her zaman gerilim kazancı istenmeyebilir. Hocanın saydığı diğer oranlar şunlardır:

- Akım kazancı: $i_o / i_s$. $i_s$, $\frac{v_s - v_1}{R_1}$ formülünden bulunur. $i_o$ ise çıkışta bir yük direnci varsa onun üzerinden, ya da başka bir dallanma yoksa $i_f$ ile eşitlikten bulunabilir; çünkü op-amp'ın girişine akım girmez.
- Geçiş direnci (transresistance): çıkış geriliminin giriş akımına oranı, $v_o / i_s$.
- Geçiş iletkenliği (transconductance): çıkış akımının giriş gerilimine oranı, $i_o / v_s$.

Hoca bu terimlerin Türkçe karşılıklarından emin olmadığını belirtti; tanımları ise yukarıdaki gibidir.

### 6.2 Gerçek op-amp analizi

$i_1$ sıfır alınmazsa analiz zorlaşır. Eviren giriş düğümüne giren akım $i_s$, çıkan akımlar $i_1$ ve $i_f$'dir; düğüm kuralından $i_s = i_1 + i_f$ yazılır. $i_1$'i bulmak için iç direnç üzerinden akan akımın evirmeyen girişten çıkan akımla ($i_2$) eşit büyüklükte ve ters yönlü olduğu da işleme katılmalıdır. Bu denklemler daha karmaşık olduğu için dersteki sorular op-amp ideal kabul edilerek çözülür.

## 7. Doyum: eviren yükselteç sayısal örneği

Bu örnekte $R_1 = 1\,k\Omega$, $R_f = 10\,k\Omega$, beslemeler $V^+ = 15$ V ve $V^- = -10$ V'tur (ekrandan, 00:45:00).

Önce kazanç çıkarılır. Evirmeyen giriş topraklı olduğu için $v_1 = 0$; $i_s = \dfrac{v_s}{R_1}$ ve $i_f = -\dfrac{v_o}{R_f}$. Eşitlikten:

$$A_v = \frac{v_o}{v_s} = -\frac{R_f}{R_1} = -\frac{10 \times 10^3}{1 \times 10^3} = -10$$

Devre girişi $-10$ katına çıkarır. Çıkış ise $-10$ V ile $+15$ V arasında kalmak zorundadır. Hocanın denediği değerler (python ile doğrulandı):

| $v_s$ (V) | Hesaplanan $-10 v_s$ (V) | Gerçek $v_o$ (V) |
|---|---|---|
| 0 | 0 | 0 |
| 0,5 | −5 | −5 |
| 1 | −10 | −10 |
| 1,1 | −11 | −10 (sınırlandı) |
| 2 | −20 | −10 (sınırlandı) |
| −1,2 | 12 | 12 |
| −5 | 50 | 15 (sınırlandı) |

<!-- BELİRSİZ: Altyazıda "1-1.2 verdik, normalde 12 volt" geçiyor; bağlama göre girişin −1,2 V olduğu ve çıkışın +12 V ile sınır içinde kaldığı anlaşılıyor. -->

Giriş-çıkış grafiği çizilirse yatay eksen $v_s$, dikey eksen $v_o$ olur. Grafiğin orta kısmı eğimi $A_v = -10$ olan bir doğrudur; eğim gerilim kazancını verir. Çıkış beslemelere ulaştığı noktalardan sonra grafik düzleşir, yani çıkış sınırlanır.

> **Hocanın vurgusu:** Hesaplanan çıkış pozitif beslemeden büyükse çıkış pozitif besleme, negatif beslemeden küçükse çıkış negatif besleme kadar olur.

## 8. Evirmeyen yükselteç

### 8.1 Kazancın çıkarılışı

Bu kez $v_s$ evirmeyen girişe bağlıdır, $R_1$'in bir ucu eviren girişte, diğer ucu topraktadır; $R_f$ yine çıkıştan eviren girişe bağlıdır (ekrandan, 00:50:00). Hoca, mantık oturduktan sonra hiçbir şeyin değişmediğini, yalnız formülün değiştiğini söyledi.

1. $v_2 = v_s$; ikinci kabulden $v_1 = v_s$.
2. $R_1$'den geçen akım (toprak tarafından düğüme doğru): $i_s = \dfrac{0 - v_s}{R_1}$.
3. $R_f$'den geçen akım: $i_f = \dfrac{v_s - v_o}{R_f}$.
4. $i_1 = 0$ olduğundan $i_s = i_f$:
   $$-\frac{v_s}{R_1} = \frac{v_s - v_o}{R_f}$$
5. Her iki taraf $R_f$ ile çarpılıp $v_s$'ye bölünürse: $-\dfrac{R_f}{R_1} = \dfrac{v_s - v_o}{v_s} = 1 - \dfrac{v_o}{v_s}$.
6. Terimler yer değiştirilirse:
   $$A_v = \frac{v_o}{v_s} = 1 + \frac{R_f}{R_1}$$

Kazanç yine $R_f$ ile $R_1$'e bağlıdır, ama bu kez oranın bir fazlasıdır ve pozitiftir. Pozitif olmasının nedeni girişin evirmeyen uca bağlı olmasıdır.

> **Hocanın vurgusu:** Formülü ezberlemeyin; bu mantığı formüle dökmeyi bilmek daha önemlidir.

### 8.2 Sayısal değerler

Aynı $R_1 = 1\,k\Omega$ ve $R_f = 10\,k\Omega$ ile:

$$A_v = 1 + \frac{10 \times 10^3}{1 \times 10^3} = 11$$

Girişe 0 V verilince çıkış 0 V, 0,5 V verilince 5,5 V olur. Burada da çıkış beslemeleri aştığı noktalarda sınırlanır; grafik yine ortada eğimli, uçlarda düz bir eğridir, ama eğim pozitiftir.

## 9. Gerilim izleyici

Gerilim izleyici (voltage follower) devresinde giriş evirmeyen uca verilir, çıkış doğrudan eviren uca bağlanır. Evirmeyen giriş $v_s$'dedir, ikinci kabulden eviren giriş de $v_s$'dedir; eviren giriş çıkışa doğrudan bağlı olduğu için çıkış da $v_s$ olur. Kazanç 1'dir: devre girişteki gerilimi değiştirmeden çıkışa aktarır.

Dersin sonuna doğru hoca bu devreye geri döndü ve izleyicilerin ölçüm cihazlarında (enstrümantasyonda) çok kullanıldığını söyledi. Giriş artı uca verilip çıkış eksi uca geri bağlanırsa girişin aynısı alınır. Hoca bağlantı tersine çevrilip girişin eksi uca verildiği durumda çıkışın girişin ters işaretlisi olacağını, toplayıcı örneğinde de böyle eksi bir sonuç bulunduğunu hatırlattı.

<!-- BELİRSİZ: 01:10-01:11 arasında hocanın "eksiye artı verseydim ... evirecekti" diye anlattığı ters bağlantının şeması altyazıdan tam çıkmıyor; ekranda o anın karesi yok. -->

## 10. Toplayıcı yükselteç ve süperpozisyon

### 10.1 "Toplayıcı" ne yapar

Hoca bu devre için yaygın bir yanlışa dikkat çekti: toplayıcı yükselteç, girişlere 1, 3 ve 2 V verilince çıkışta bunların toplamını veren bir devre değildir. Böyle bir devre kurulabilir, ama direnç değerleri buna göre ayarlanmalıdır.

### 10.2 Süperpozisyon hatırlatması

Hoca devrede birden fazla kaynak olduğunda kullanılan yöntemi sordu. Bir öğrenci süper düğüm (supernode) yöntemini önerdi. Hoca süper düğümün düğüm analizinde iki düğüm arasındaki bir kaynağı ortadan kaldırmak için kullanıldığını, burada uygulanacak yöntemin süperpozisyon olduğunu söyledi.

Süperpozisyonda kaynaklar teker teker devrede bırakılır. Diğer kaynaklar "atılmaz", sıfırlanır: gerilim kaynakları kısa devre, akım kaynakları açık devre edilir. Her kaynak için ayrı analiz yapılır ve en sonunda bulunan sonuçlar toplanır.

### 10.3 Ekrandaki toplayıcı örneği

Devrede üç kaynak ayrı dirençlerle eviren girişe bağlıdır, evirmeyen giriş topraklıdır, $R_f = 10\,k\Omega$'dur (ekrandan, 00:55:00):

- $V_A = 1$ V, $R_A = 5\,k\Omega$
- $V_B = 3$ V, $R_B = 2\,k\Omega$
- $V_C = -2$ V, $R_C = 4\,k\Omega$

Analiz şöyle ilerler:

1. Eviren giriş sanal topraktadır ($v_1 = 0$).
2. Yalnız $V_A$ devredeyken $V_B$ ve $V_C$ kısa devre edilir. Bu durumda $R_B$ ve $R_C$'nin iki ucu da 0 V'tadır; örneğin $i_B = \frac{0 - 0}{R_B} = 0$. Böylece $i_A = i_f$: $\dfrac{V_A - 0}{R_A} = \dfrac{0 - v_o}{R_f}$, yani $v_{o,A} = -\dfrac{R_f}{R_A}V_A$. Bu, eviren yükseltecin formülüdür.
3. Aynı işlem $V_B$ ve $V_C$ için tekrarlanır: $v_{o,B} = -\dfrac{R_f}{R_B}V_B$, $v_{o,C} = -\dfrac{R_f}{R_C}V_C$.
4. Süperpozisyon gereği sonuçlar toplanır:
   $$v_o = -\left[\frac{R_f}{R_A}V_A + \frac{R_f}{R_B}V_B + \frac{R_f}{R_C}V_C\right]$$
5. Değerler yerine konursa:
   $$v_o = -\left[\frac{10}{5}V_A + \frac{10}{2}V_B + \frac{10}{4}V_C\right] = -[2V_A + 5V_B + 2{,}5V_C]$$
   $$v_o = -[2(1) + 5(3) + 2{,}5(-2)] = -[2 + 15 - 5] = -12\text{ V}$$

Sonuç python ile doğrulandı. Hocanın dikkat çektiği nokta, girişlerin 1 V, 3 V ve −2 V olmasına karşın çıkışın −12 V çıkmasıdır: devre, direnç oranlarıyla ağırlıklandırılmış bir toplama yapar.

### 10.4 Doğrudan toplama nasıl yapılır

Hoca öğrencilere girişleri doğrudan toplayan, yani bu örnekte $1 + 3 - 2 = 2$ V veren bir devrenin nasıl kurulacağını sordu.

**Soru:** Dirençler çıkarılıp kaynaklar doğrudan bağlansa olur mu?
**Cevap:** Olmaz. Direnç olmazsa o kollardan tanımlı bir akım geçmez; akım için direnç gerekir.

**Soru:** Bütün dirençler 10 kΩ yapılırsa olur mu?
**Cevap:** Hoca bunu tahtada çözdü (ekrandan, 01:00:00). Yalnız $V_A$ devredeyken $\frac{1 - 0}{10} = \frac{0 - v_o}{10}$, yani bu kaynağın katkısı $-1$ V'tur. Diğerleri de aynı biçimde $-3$ V ve $+2$ V katkı verir: $v_o = -1 - 3 + 2 = -2$ V. Bütün katsayılar 1 olur, toplam doğru alınır, ama eviren uç kullanıldığı için işaret ters döner. İstenen +2 V'tur.

**Soru:** Yalnız $R_C$'yi 30 kΩ, $R_A$ ve $R_B$'yi 10 kΩ yapmak olur mu?
**Cevap:** Hoca bunun bu giriş değerlerine göre ayar yapmak olduğunu, girişler değiştiğinde (örneğin girişlerden birine farklı bir gerilim verildiğinde) çalışmayacağını söyledi. İstenen, girişe ne verilirse verilsin doğrudan toplayan bir devredir.

<!-- BELİRSİZ: Öğrencinin bu öneriyle hangi çıkışı hedeflediği altyazıdan anlaşılmıyor; ideal hesapla $R_f = 10\,k\Omega$ iken bu değerler +2 V değil yaklaşık −3,33 V verir. -->

**Soru:** Girişler eviren uç yerine artı uca bağlansa olur mu?
**Cevap:** Hoca, geri besleme direnci eksi uçta kalırken yalnız girişlerin yeri değiştirilirse bunun tek başına yeterli olmadığını söyledi; birkaç yöntem olduğunu, kendisinin aklına iki yol geldiğini belirterek soruyu öğrencilere çalışma sorusu olarak bıraktı.

## 11. Fark alıcı devre

### 11.1 Çözüm mantığı

Fark alıcı devre de girişleri doğrudan çıkarmaz; yine devre çözümlenmelidir. Devrede $V_A$, $R_A$ üzerinden eviren girişe; $V_B$ ise $R_B$ ve $R_C$'den oluşan bir gerilim bölücü üzerinden evirmeyen girişe bağlıdır; $R_f$ çıkıştan eviren girişe geri besleme yapar (ekrandan, 01:05:00).

İlk iş evirmeyen girişteki gerilimi bulmaktır. Evirmeyen girişe akım girmediği için $R_B$'den geçen akımın gidebileceği tek yol $R_C$'dir; bu yüzden o düğümün gerilimi gerilim bölücü formülüyle bulunur:

$$V^+ = V_B \frac{R_C}{R_B + R_C}$$

İkinci kabulden eviren giriş de bu gerilimdedir. Sonra eviren girişte yine akım eşitliği yazılır:

$$\frac{V_A - V^+}{R_A} = \frac{V^+ - v_o}{R_f}$$

### 11.2 Sayısal örnek

Değerler: $V_A = 2$ V, $R_A = 6\,k\Omega$, $R_f = 30\,k\Omega$, $V_B = 3$ V, $R_B = 8\,k\Omega$, $R_C = 4\,k\Omega$ (ekrandan, 01:05:00).

1. $V^+ = 3 \cdot \dfrac{4}{8 + 4} = 1$ V. Hoca bunu akım üzerinden de gösterdi: $R_B$ ve $R_C$'den geçen akım $\frac{3}{12}\,\text{mA} = \frac{1}{4}$ mA, bu akım 4 kΩ ile çarpılınca 1 V çıkar.
2. Eviren giriş de 1 V'tadır.
3. Akım eşitliği (kΩ'lar sadeleşir): $\dfrac{2 - 1}{6} = \dfrac{1 - v_o}{30}$.
4. $1 - v_o = 5$, buradan $v_o = -4$ V.

Slayttaki genel formül de aynı sonucu verir:

$$v_o = \frac{R_f}{R_A}\frac{(1 + R_A/R_f)}{(1 + R_B/R_C)}V_B - \frac{R_f}{R_A}V_A = \frac{30}{6}\cdot\frac{1{,}2}{3}\cdot 3 - \frac{30}{6}\cdot 2 = 6 - 10 = -4\text{ V}$$

İki yol python ile doğrulandı. Hoca, iç içe yazılmış formül yerine bulunan 1 V'u doğrudan denkleme yazmanın daha basit olduğunu söyledi. Bu örnekte de girişler 2 V ve 3 V iken çıkış −4 V'tur; doğrudan bir çıkarma yoktur.

### 11.3 Doğrudan çıkarma koşulu

Hoca, girişlerin doğrudan farkını veren ($v_o = V_B - V_A$) bir devrenin nasıl kurulacağını da araştırma sorusu olarak bıraktı ve slayttaki koşulları gösterdi:

- $\dfrac{R_A}{R_f} = \dfrac{R_B}{R_C}$ ise $v_o = \dfrac{R_f}{R_A}(V_B - V_A)$ olur.
- Buna ek olarak $R_A = R_f$ ise $v_o = V_B - V_A$ olur.

Dersin sonundaki tekrarda bunu en basit hâliyle verdi: bütün dirençler $R$ ise evirmeyen giriş $V^+ = \dfrac{R}{2R}V_2$'dir; bu değer eviren giriş denkleminde yerine yazılınca çıkış iki girişin farkı olur.

> **Ek bilgi (derste anlatılmadı):** Koşulun nereden geldiği şöyle görülebilir. Eviren giriş denkleminden $v_o = V^+\left(1 + \frac{R_f}{R_A}\right) - \frac{R_f}{R_A}V_A$ çıkar. $\frac{R_A}{R_f} = \frac{R_B}{R_C}$ ise $V^+ = V_B\frac{R_C}{R_B + R_C} = V_B\frac{R_f}{R_A + R_f}$ olur ve ilk terim $\frac{R_f}{R_A}V_B$'ye sadeleşir.

## 12. Kaskat yükselteçler

Kaskat devreler, ardı ardına bağlanmış op-amp yükselteçlerdir. Ekrandaki örnekte birinci kat evirmeyen yükselteçtir ($R_1 = 5\,k\Omega$, $R_{f1} = 15\,k\Omega$, giriş $v_s = 2$ V); birinci katın çıkışı $R_2 = 2\,k\Omega$ üzerinden eviren bir yükseltece ($R_{f2} = 8\,k\Omega$) girer (ekrandan, 01:10:00).

Hoca iki yaklaşım gösterdi:

- Katlar standart devrelerse, her katın kazancı ayrı bulunur ve çarpılır: $A_{v,toplam} = A_{v1} A_{v2}$. Burada birinci kat evirmeyen ($1 + R_{f1}/R_1$), ikinci kat eviren ($-R_{f2}/R_2$) yükselteçtir.
- Kademeli çözüm: önce birinci kat çözülüp çıkışı ($v_{o1}$) bulunur, sonra bu değer ikinci katın girişi gibi kullanılarak ikinci kat çözülür. Hoca bu yolu daha net bulduğunu söyledi; çünkü örneğin ikinci kata fazladan bir direnç eklenmişse hazır formül tutmaz, ama formülü kendiniz çıkararak yaptığınız kademeli çözüm yine doğru sonuç verir.

> **Ders sonrası not:** Slayttaki formülde birinci katın kazancı $\left(1 + \frac{R_{f2}}{R_1}\right)$ diye yazılmıştır; doğrusu $\left(1 + \frac{R_{f1}}{R_1}\right)$'dir. Slayttaki değerlerle $A_{v1} = 1 + \frac{15}{5} = 4$, $v_{o1} = 8$ V, $A_{v2} = -\frac{8}{2} = -4$ ve ideal hesapla $v_o = -32$ V çıkar (toplam kazanç $-16$). Bu sayısal sonuç derste hesaplanmadı, python ile kontrol edildi. Slaytta besleme gerilimi verilmediği için doyum durumu belirtilmemiştir; gerçek bir op-amp'ta çıkış beslemeyle sınırlanır.

## 13. Genel tekrar ve yöntem üzerine

### 13.1 İki kabul ve temel devreler

Dersin sonunda hoca iki kabulü yeniden özetledi: $v_1 = v_2$ ve op-amp'ın girişlerine giren akımların ($i_1$, $i_2$) sıfır olması. İdeal op-amp soruları bu iki kabulle çözülür.

En çok kullanılan iki devre eviren ($A_v = -R_f/R_1$) ve evirmeyen ($A_v = 1 + R_f/R_1$) yükselteçtir. İzleyicide giriş artı uca verilip çıkış eksi uca bağlanırsa çıkış girişin kendisidir. Toplayıcı devrenin formülü $v_o = -R_f\left(\frac{V_1}{R_1} + \frac{V_2}{R_2} + \frac{V_3}{R_3}\right)$ biçimindedir; hoca buradaki eksi işaretin unutulmaması gerektiğini söyledi. Fark alıcıda bütün dirençler $R$ ise çıkış iki girişin farkıdır.

### 13.2 Neden ezber değil

Hoca ezberlenmiş formüllerin karıştırıldığını, devre bilinen yapıya tam benzemeyince öğrencilerin tahmine yöneldiğini söyledi. İki örnek verdi:

- Eviren yükselteçte evirmeyen giriş ile toprak arasına bir direnç konursa sonuç değişmez. O girişten akım akmadığı için direnç üzerinde gerilim düşmez, giriş yine 0 V'tadır ve aynı formül çıkar.
- Ama direnç, bir gerilim bölücü oluşturacak biçimde konursa hazır formül işlemez. Önce o düğümün gerilimi bulunmalı, ancak ondan sonra diğer taraf hesaplanabilir.

> **Hocanın vurgusu:** Formüllerin nasıl elde edildiğini bilmek, ezberden çok daha önemlidir. Op-amp devrelerinin analizine iyi çalışılmalıdır.

### 13.3 Aynı yaklaşım FET konusunda

Hoca aynı ilkenin yalnız op-amp için değil, önceki konular için de geçerli olduğunu söyledi. Örneğin FET'te $V_{GS}$'nin negatif olmasının drain akımını ($I_D$) düşürdüğü bir zihinsel model üzerine kurulmalıdır. Derste çoğunlukla N-kanal işlendiyse ve P-kanal sorulursa $V_{GS}$'nin negatif mi pozitif mi olacağı bu mantıkla anlaşılmalı; gate geriliminin tükenme bölgesini (depletion region) nasıl değiştirdiği bilinmelidir.

<!-- BELİRSİZ: Hocanın tükenme bölgesi için kullandığı ifade altyazıda bozuk ("daralttığını"); N-kanal JFET'te $V_{GS}$ daha negatif oldukça tükenme bölgesi genişler ve kanal daralır. -->

## Örnek Sorular

**1. Doyum sınırı (ekrandan, 00:25:00)**

Kazancı 10 olan bir op-amp devresine 10 V giriş veriliyor, besleme ±15 V. Çıkış nedir?

> **Çözüm:** İdeal hesap $10 \times 10 = 100$ V verir. Çıkış beslemeyi aşamayacağı için $v_o = 15$ V olur.

**2. Eviren yükselteç (ekrandan, 00:45:00)**

$R_1 = 1\,k\Omega$, $R_f = 10\,k\Omega$, $V^+ = 15$ V, $V^- = -10$ V. Kazancı bulun; farklı $v_s$ değerleri için çıkışı inceleyin.

> **Çözüm:** $A_v = -10$. $v_s = 1$ V için $-10$ V; $v_s = 2$ V için hesap $-20$ V verir ama çıkış $-10$ V'ta sınırlanır; $v_s = -5$ V için hesap $+50$ V verir ama çıkış $+15$ V'ta sınırlanır. Ayrıntılı tablo 7. bölümdedir.

**3. Evirmeyen yükselteç (ekrandan, 00:50:00)**

Aynı dirençler ve beslemelerle giriş evirmeyen uca verilirse kazanç nedir?

> **Çözüm:** $A_v = 1 + \frac{10}{1} = 11$. $v_s = 0{,}5$ V için $v_o = 5{,}5$ V.

**4. Gerilim kıyaslayıcı (ekrandan, 00:35:00)**

Op-amp'ın nasıl çalıştığına göre, $v_2 = 5$ V iken $v_o$ ne olur: (1) $v_s = 0$ V, (2) $v_s = 5$ V, (3) $v_s = 6$ V? ($v_s$ eviren girişe, $v_2$ evirmeyen girişe bağlıdır.)

> **Çözüm:** (1) $v_1 = 0 < v_2 = 5$ V, evirmeyen giriş büyük: $v_o = +V$. (2) Girişler eşit: hocanın anlatımıyla $v_o = 0$. (3) $v_1 = 6 > v_2 = 5$ V, eviren giriş büyük: $v_o = -V$.

**5. Eviren toplayıcı (ekrandan, 00:55:00)**

$R_A = 5\,k\Omega$, $R_B = 2\,k\Omega$, $R_C = 4\,k\Omega$, $R_f = 10\,k\Omega$; $V_A = 1$ V, $V_B = 3$ V, $V_C = -2$ V. $v_o$ nedir?

> **Çözüm:** $v_o = -[2(1) + 5(3) + 2{,}5(-2)] = -12$ V. Bütün dirençler 10 kΩ olsaydı $v_o = -2$ V olurdu.

**6. İşaret değiştirmeden doğrudan toplama (derste sözlü ve ekrandan, 01:01:13)**

Girişte verilen üç gerilimi doğrudan toplayan ve işaretini ters çevirmeyen bir devre tasarlayın (örnekteki girişlerle çıkış +2 V olmalı).

> **Çözüm (derste verilmedi):** Hoca birden fazla yöntem olduğunu söyleyip soruyu çalışma sorusu olarak bıraktı. Bir yol: üç giriş eşit dirençlerle ($R$) evirmeyen girişe bağlanır. Evirmeyen girişe akım girmediği için o düğümde $\sum \frac{V_k - V^+}{R} = 0$, yani $V^+ = \frac{V_A + V_B + V_C}{3}$ olur. Op-amp $R_f = 2R_1$ seçilmiş bir evirmeyen yükselteç olarak bağlanırsa kazanç $1 + 2 = 3$ olur ve $v_o = V_A + V_B + V_C$ çıkar. Örnek değerlerle $v_o = \frac{1 + 3 - 2}{3} \cdot 3 = 2$ V (python ile doğrulandı). İkinci bir yol: bütün dirençleri eşit bir eviren toplayıcının ($-(V_A + V_B + V_C)$) çıkışına kazancı $-1$ olan bir eviren yükselteç bağlamak.

**7. Fark alıcı (ekrandan, 01:05:00)**

$V_A = 2$ V, $R_A = 6\,k\Omega$, $R_f = 30\,k\Omega$; $V_B = 3$ V, $R_B = 8\,k\Omega$, $R_C = 4\,k\Omega$. $v_o$ nedir?

> **Çözüm:** $V^+ = 3 \cdot \frac{4}{12} = 1$ V. $\frac{2 - 1}{6} = \frac{1 - v_o}{30}$ ⇒ $v_o = -4$ V.

**8. Doğrudan çıkarma (derste sözlü ve ekrandan, 01:06:06)**

Girişlere ne verilirse verilsin doğrudan farklarını veren (örneğin girişler 2 V ve 3 V iken 1 V veren) bir çıkarma devresi nasıl kurulur?

> **Çözüm:** Hoca slayttaki koşulu gösterdi: fark alıcıda $\frac{R_A}{R_f} = \frac{R_B}{R_C}$ ve $R_A = R_f$ seçilirse, yani bütün dirençler eşitse, $v_o = V_B - V_A$ olur. Örneğin $V_B = 3$ V ve $V_A = 2$ V için $v_o = 1$ V.

**9. Kaskat yükselteç (ekrandan, 01:10:00)**

Birinci kat evirmeyen ($R_1 = 5\,k\Omega$, $R_{f1} = 15\,k\Omega$, $v_s = 2$ V), ikinci kat eviren ($R_2 = 2\,k\Omega$, $R_{f2} = 8\,k\Omega$). Toplam kazanç ve çıkış nedir?

> **Çözüm (derste verilmedi):** Derste yalnız $A_{v,toplam} = A_{v1}A_{v2}$ ilişkisi gösterildi. $A_{v1} = 1 + \frac{15}{5} = 4$, $A_{v2} = -\frac{8}{2} = -4$, $A_{v,toplam} = -16$. İdeal hesapla $v_{o1} = 8$ V, $v_o = -32$ V (python ile doğrulandı). Besleme verilmediği için doyum dikkate alınmamıştır.

## Dersin Toparlaması

Bu derste op-amp'ın ne olduğu, sembolü, bacakları ve çıkışın besleme gerilimleriyle nasıl sınırlandığı anlatıldı. İdeal op-amp'ın iki kabulü, yani girişlere akım girmemesi ve iki girişin aynı gerilimde olması, bütün devrelerin çözümünde kullanıldı. Bu kabullerle önce geri beslemesiz kıyaslayıcı, sonra eviren ($-R_f/R_1$) ve evirmeyen ($1 + R_f/R_1$) yükselteçlerin kazançları adım adım çıkarıldı; gerilim izleyici, süperpozisyonla çözülen toplayıcı, gerilim bölücüyle başlayan fark alıcı ve kazançları çarpılan kaskat yükselteçler örneklerle işlendi.

Dersin ana mesajı, formüllerin ezberlenmemesi ve her devrede iki kabul ile akım eşitliğinden yola çıkılarak yeniden kurulmasıdır. Hoca aynı yaklaşımın FET gibi önceki konular için de geçerli olduğunu vurguladı. Türev ve integral alıcı birinci dereceden op-amp devreleri bu derste işlenmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
