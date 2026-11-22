# Ders 7 Genişletilmiş Notu: İşlemsel Yükselteç (Op-Amp): İdeal ve Gerçek Model, Karşılaştırıcı, Eviren/Evirmeyen, Gerilim İzleyici, Toplayıcı, Fark Alıcı, Kaskat; Kaynak Dönüşümü ve Thevenin Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kondansatörün Çalışma Mantığı: Animasyonla Tekrar
- 2. İşlemsel Yükselteç (Op-Amp) Nedir?
- 3. Op-Amp Sembolü, Uçları ve Eşdeğer Devresi
- 4. İdeal Op-Amp Kabulleri ve Tipik Parametreler
- 5. Besleme Gerilimleri ve Doyum
- 6. Açık Çevrim: Gerilim Karşılaştırıcı
- 7. Kapalı Çevrim Kazancı: Eviren Yükselteç
- 8. Gerçek Op-Amp ile Kapalı Çevrim ve Kazanç Türleri
- 9. Eviren Yükselteç: Sayısal Örnek ve Doyum
- 10. Evirmeyen Yükselteç
- 11. Gerilim İzleyici
- 12. Toplayıcı Yükselteç
- 13. Fark Alıcı Yükselteç
- 14. Kaskat (Ardışık) Yükselteçler ve Karma Devreler
- 15. Op-Amp Konusunun Özeti
- 16. Ödev Soruları: Kaynak Dönüşümü ve Thevenin Eşdeğeri
- Örnek Sorular
- Dersin Toparlaması

## 1. Kondansatörün Çalışma Mantığı: Animasyonla Tekrar

Önceki derste kondansatör ve bobine giriş yapılmıştı. Hoca yeni konuya geçmeden önce bir kondansatörün nasıl şarj ve deşarj olduğunu gösteren kısa bir animasyon açtı (ekrandan, 00:05:00).

Animasyonda bir batarya, ona bir anahtarla bağlanan bir kondansatör ve bir de motor vardı. Artı yükler kırmızı, elektronlar (eksi yükler) sarı gösteriliyordu. Bataryanın içi hareketliydi, kondansatörün içi ise başlangıçta durgundu: dielektrik malzeme bir yalıtkan gibi davranıyor, içinden elektron akımı geçmiyordu. Önce motor doğrudan bataryaya bağlanarak çalıştırıldı ve bir ağırlığı kaldırdı. Sonra motor devreden ayrıldı ve kondansatör bataryaya bağlandı, çünkü amaç önce kondansatörü şarj etmekti.

Anahtar kapanınca elektronlar hareket etmeye başladı. Kondansatördeki iki plaka ve aradaki dielektrik kutuplanır: negatif yüklerin geldiği tarafta dielektrik, dengeyi sağlamak için pozitif yükleri o tarafa toplar, öbür tarafa negatif yükleri iter. Böylece kondansatörün bir yanı artı, öbür yanı eksi kutuplanır. Hoca önceki derste söylenenleri tekrarladı: kondansatör, bataryanın tersine doğru bir kutuplanma gösterir; şarj önce çok hızlı başlar, sonra yavaşlayarak sürer.

Bu dolum sonsuza kadar sürmez. Kondansatörün farad değeri, yani taşıyabileceği yük miktarı ne kadarsa, şarj o noktaya kadar hızlı başlayıp yavaşlayarak ilerler ve durur. Durduğu anda kondansatör artık yük almaz ve akım geçmez. Akım akmadığından devre bu noktada açık devre gibi davranır.

> **Hocanın vurgusu:** Kondansatör kararlı duruma (doyum noktasına) geldiğinde devre açık devre özelliği gösterir; akım oluşmaz.

Ardından kondansatör bataryadan ayrılıp motora bağlandı. Deşarj ters yönde, yine önce çok hızlı başlayıp sonra yavaşlayarak, kondansatördeki potansiyel farkı sıfıra yaklaşana kadar sürdü ve bu sırada motor çalıştı. Kondansatör tekrar şarj edilmek istendiğinde yine bataryaya bağlanır.

## 2. İşlemsel Yükselteç (Op-Amp) Nedir?

### 2.1 Tanım ve dersin planı

Bu dersin konusu op-amp'tır. Ad, İngilizce "operational amplifier" teriminin kısaltmasıdır. Türkçede "işlemsel yükselteç" ya da "işlemsel kuvvetlendirici" denir. Dersin hedefleri slaytta şöyle sıralanmıştı (ekrandan, 00:10:00):

- İdeal bir op-amp'ın nasıl davrandığını anlatmak.
- Gerilim kazancı, akım kazancı, geçiş direnci (transresistance) kazancı ve geçiş iletkenliği (transconductance) kazancını tanımlamak.
- İdeal op-amp'ın gerilim karşılaştırıcı ve eviren yükselteç devresinde nasıl çalıştığını açıklamak ve gerçek op-amp kullanmanın etkisini göstermek.
- "Neredeyse ideal" op-amp modelini şu devrelerde uygulamak: eviren yükselteç (inverting amplifier), evirmeyen yükselteç (noninverting amplifier), gerilim izleyici (voltage follower), toplayıcı yükselteç (summing amplifier), fark alıcı yükselteç (difference amplifier) ve kaskat (ardışık) yükselteçler (cascaded amplifiers).

Hoca önce ideal op-amp'ın çalışma ilkesini, sonra gerçek bir op-amp'ın nasıl modellendiğini göstereceğini söyledi. Ancak bütün sorularda ve devre tasarımlarında op-amp ideal kabul edilecek, yani ideal olmasından gelen bazı kurallar konulacak. Gerçek hayatta bu kurallar birebir tutmaz, ama hesaplar ideal modele göre yapılır. Her bağlantı şemasının kendi adı ve etkisi vardır; hepsinde ortak olan, yükseltme özelliğini anlatan bir kazanç denkleminin çıkarılmasıdır.

### 2.2 Op-amp ne yapar?

Op-amp, girişteki gerilimi (iki girişi arasındaki farkı) yüksek bir kazanç katsayısıyla çarparak çıkışa yansıtan bir devre elemanıdır. Hoca bunu yalnız "sayıyı büyütmek" diye düşünmemek gerektiğini vurguladı. Bir devre girişi ters işaretle yükseltebilir: +5 V verip −7 V almak, sayı doğrusunda küçültme gibi görünür, ama genlik açısından 5'ten 7'ye büyüme vardır. Bazen kazanç 1'den küçük seçilip çıkış girişten küçük de yapılabilir; yine de bir katsayıyla işlem yapıldığından her zaman bir "kazanç"tan (gain) söz edilir.

### 2.3 Kullanım alanları

- **Ses uygulamaları:** Mikrofona gelen ses sinyalinin genliği çok küçüktür. Sinyal yükseltilerek bilgisayara aktarılır; hoparlör tarafında da yükseltilerek sese çevrilir.
- **Biyomedikal sistemler:** EKG gibi cihazlarda kalp ritminin çok küçük sinyali algılanabilir düzeye yükseltilir. Burada yükselteç devresinin gürültüden etkilenmemesi gerekir.
- **Güç elektroniği:** Girişteki düşük gerilimi, dolayısıyla düşük gücü artırma çalışmalarında kullanılır.

## 3. Op-Amp Sembolü, Uçları ve Eşdeğer Devresi

### 3.1 Sembol ve uçlar

Sorularda ve şematik diyagramlarda op-amp üç uçlu bir üçgenle gösterilir: iki giriş ve bir çıkış. Girişlerin kutbu önemlidir. Artı (+) ile işaretli uca **evirmeyen giriş** (non-inverting), eksi (−) ile işaretli uca **eviren giriş** (inverting) denir; üçüncü uç çıkıştır.

En çok kullanılan örneklerden biri LM324 entegresidir. Onun şematik diyagramında artı ve eksi besleme gerilimleri de gösterilir. Diyagramdaki 1, 2, 3, 4 gibi numaralar, entegrenin datasheet'inde hangi bacağın hangi işleve karşılık geldiğini gösterir; örneğin 1 numaralı bacak çıkış, 2 ve 3 numaralı bacaklar giriştir. Op-amp pozitif ve negatif olmak üzere iki beslemeyle çalışır.

Datasheet'te ayrıca kılıfın (paketin) diyagramı bulunur. Entegrenin bir ucunda bir çentik vardır ve bacak numaraları bu çentiğe göre sayılır. Çentiğin hangi tarafta olduğuna bakarak, örneğin 7 numaralı bacağa pozitif beslemenin, 4 numaralı bacağa negatif beslemenin verilmesi gerektiği okunur ve bağlantı buna göre yapılır. Hoca, derste fiziksel devre kurulmayabileceğini ama bu bilgiyi bilmenin yararlı olduğunu belirtti.

### 3.2 Eşdeğer devre (ekrandan, 00:15:00)

Op-amp'ın içine bakıldığında şu model görülür:

- Evirmeyen giriş $v_2$ (+) ile eviren giriş $v_1$ (−) arasında bir **giriş direnci** $R_i$ vardır. $R_i$ çok çok büyük bir dirençtir.
- İki giriş arasındaki fark gerilimi $v_d = v_2 - v_1$'dir.
- İçeride değeri $A v_d$ olan bir **gerilim kontrollü gerilim kaynağı** vardır. $A$, açık çevrim (open-loop) gerilim kazancıdır.
- Bu kaynağa seri bir **çıkış direnci** $R_o$ bağlıdır ve çıkış gerilimi $v_o$ bunun ucunda alınır.

Hedef, $v_d$'yi $A$ katsayısıyla çarparak $v_o$'yu üretmektir. Bunun için $R_o$'nun olabildiğince küçük, $R_i$'nin olabildiğince büyük olması istenir. Hoca $R_o$ için şöyle açıkladı: içeride üretilen gerilimin bu direnç üzerinde en az kayba uğraması, yani direncin üretilen gerilimi "sömürmemesi" istenir.

> **Ders sonrası not:** Hoca $R_i$'nin büyük olmasını "iki giriş arasındaki potansiyel farkın yüksek çıkması" ile açıkladı. Asıl gerekçe, büyük $R_i$'nin girişlerden akım çekilmesini engellemesidir; böylece op-amp girişine bağlanan devreyi yüklemez. İdeal modelde bu, giriş akımlarının sıfır olması demektir (Bölüm 4).

## 4. İdeal Op-Amp Kabulleri ve Tipik Parametreler

### 4.1 İki temel kural

İdeal op-amp'ta kabul edilen iki kriter, bütün soruların temelidir:

1. **Girişlere akım girmez:** $i_1 = i_2 = 0$. Op-amp'ın içine bir sızıntı akımı gelmediği kabul edilir. Gerekçe, $R_i$'nin ideal op-amp'ta sonsuz alınmasıdır. $R_i$ sonsuz olunca iki giriş arası açık devre gibidir ve akım geçmez.
2. **İki giriş gerilimi eşittir:** $v_n = v_p$, yani $v_1 = v_2$.

Bu kabullere göre bir kazanç katsayısı hesaplanır. Kazanç, çıkışın girişe oranıdır. Op-amp'ın iki girişi olduğundan "giriş" burada iki girişin farkı olan $v_d$'dir:

$$A = \frac{v_o}{v_d} \quad\Longrightarrow\quad v_o = A\, v_d$$

Sorularda genellikle amaç, op-amp devresinin ne kadar kazanç sağladığını bulmaktır.

### 4.2 Tipik değerler (ekrandan, 00:20:00)

| Parametre | Değişken | Tipik aralık | İdeal değer |
|---|---|---|---|
| Açık çevrim gerilim kazancı | $A$ | $10^5$ – $10^8$ | $\infty$ |
| Giriş direnci | $R_i$ | $10^5$ – $10^{13}\ \Omega$ | $\infty\ \Omega$ |
| Çıkış direnci | $R_o$ | $10$ – $100\ \Omega$ | $0\ \Omega$ |
| Besleme gerilimi | $V_{cc}/V^+$ ; $-V_{cc}/V^-$ | 5 – 30 V ; −30 V – 0 V | yok |

> **Ders sonrası not:** Hoca gerçek op-amp'larda $A$'nın "100 bin ile 1 milyon arasında" olduğunu söyledi; slayttaki tabloda aralık $10^5$ – $10^8$ olarak verilmiştir.

Gerçek hayatta giriş direnci çok yüksektir; ideal modelde sonsuz kabul edilerek girişlerin açık devre olduğu ve giriş akımlarının sıfır olduğu söylenir. Besleme gerilimleri gerçek op-amp'larda pozitif tarafta 5–30 V, negatif tarafta −30–0 V arasındadır. Sorularda ise besleme hangi değerle verilirse (40 V, 50 V gibi) o kullanılır.

### 4.3 Frekansın kazanca etkisi

Derste analizler DC gerilimle yapılacak. Ancak hoca op-amp'ın bir özelliğini de belirtti: giriş alternatif akımsa, yani bir frekans bilgisi varsa, frekans arttıkça op-amp'ın sağladığı kazanç ($A$ parametresi) azalır. Kazanç frekansla ters yönde değişir. Slaytta PSpice benzetim programında bir op-amp modeli gösterildi; orada kazanç doğrudan parametre olarak girilebiliyor. Sorularda ise kazanç devreden hesaplanacaktır.

## 5. Besleme Gerilimleri ve Doyum

### 5.1 Besleme neden önemli?

Op-amp, artı ve eksi beslemelerle beslenmedikçe çalışmaz. Bu beslemeler aynı zamanda **sınırlayıcıdır**. Hocanın örneği: girişe 5 V verilip çıkışta 100 V istendiğini, yani 20 katlık bir kazanç tasarlandığını düşünelim. Bu yapılamaz; enerji "yoktan var edilemez". Beslemeler $\pm 18$ V ise 5 V girişle alınabilecek en yüksek çıkış 18 V'tur.

Hesaplanan çıkış +18 V'u geçerse çıkış **pozitif doyuma** (positive saturation), −18 V'un altına inerse **negatif doyuma** (negative saturation) gider.

### 5.2 Sayısal örnek (ekrandan, 00:25:00)

Tahtadaki örnekte $\pm 18$ V ile beslenen bir op-amp için $A = 10$ ve $v_d = 5$ V alındı:

- Hesap $v_o = 10 \cdot 5 = 50$ V verir. Besleme $+18$ V olduğundan çıkış 50 V olamaz, $v_o = +18$ V olur.
- Tersine $v_d = -5$ V olsaydı hesap $-50$ V verirdi; çıkış $-18$ V'ta kalır.
- $A v_d$ besleme aralığının içinde kalıyorsa (beslemenin 18 V olması gerekmez, $+V$ ile $-V$ arası herhangi bir değer), çıkış doğrudan $v_o = A v_d$ formülüyle bulunur.

> **Ders sonrası not:** Tahtada $v_d = v_1 - v_2$ yazıldı, slayttaki eşdeğer devrede ise $v_d = v_2 - v_1$ tanımlıdır ($v_2$: evirmeyen, $v_1$: eviren giriş). Doğru olan slayttaki tanımdır. Örnekteki sayısal fikir (çıkışın beslemeyle sınırlanması) bundan etkilenmez.

Slayttaki tablo bunu özetler:

| Bölge | Gerilim aralığı | Çıkış gerilimi |
|---|---|---|
| Pozitif doyum | $A v_d > V^+$ | $v_o \approx V^+$ |
| Doğrusal bölge | $V^- < A v_d < V^+$ | $v_o = A v_d$ |
| Negatif doyum | $A v_d < V^-$ | $v_o \approx V^-$ |

Slaytın altındaki not: op-amp'ın içindeki bağımlı gerilim kaynağının ürettiği gerilim, pozitif ve negatif beslemelere (rails) uygulanan gerilimlerle sınırlıdır.

İki giriş eşitse ($v_1 = v_2$), $v_d = 0$ olur ve çıkış da sıfırdır. Çıkışta bir gerilim görmek için iki giriş arasında bir potansiyel farkı oluşturmak gerekir.

## 6. Açık Çevrim: Gerilim Karşılaştırıcı

### 6.1 Devre ve davranış (ekrandan, 00:30:00)

İlk incelenen yapı **gerilim karşılaştırıcı** (voltage comparator) devresidir. Bu devrede çıkıştan girişe bir bağlantı (çevrim, loop) yoktur; doğrudan bir $v_d$ oluşturulur ve $A v_d$ ile çıkış elde edilir. Slayttaki devrede $V_s$ kaynağı eviren girişe ($v_1$) bağlıdır, evirmeyen giriş ($v_2$) toprağa bağlıdır; $i_s = i_1 = i_2 = 0$'dır.

- $V_s = 0$ V ise iki giriş de 0 V'tur, fark oluşmaz ve $v_o = 0$ V olur.
- $V_s > 0$ ise (örneğin +5 V, hatta +1 V) eviren taraf ağır basar ve çıkış negatif beslemeye gider: $v_o = V^-$.
- $V_s < 0$ ise (örneğin −5 V) evirmeyen taraf ağır basar ve çıkış pozitif beslemeye gider: $v_o = V^+$.

**Soru:** Çıkışın $-V$ olduğu durumu tekrar özetler misiniz?

**Cevap:** Çıkışın $-V$ olması için eviren (−) girişteki gerilimin evirmeyen (+) girişteki gerilimden büyük olması gerekir. Bu devrede evirmeyen giriş toprakta, yani 0 V'tadır. $V_s$'ye sıfırdan büyük herhangi bir değer verilirse, 1 V bile olsa, aradaki fark eviren taraftan geldiği için çıkışa negatif besleme ($-V$) yansır. $V_s$ sıfırdan küçükse (−1 V, −2 V gibi) bu kez evirmeyen taraf baskın olur ve çıkış $+V$ olur.

### 6.2 İkinci örnek: $v_2 = 5$ V (ekrandan, 00:35:00)

Slayttaki soru: Op-amp'ın nasıl çalıştığını düşünerek, evirmeyen girişe $v_2 = 5$ V bağlıyken, eviren girişteki $V_s$'nin şu değerleri için $v_o$ ne olur? Çözüm Örnek Sorular bölümünde adım adım verilmiştir. Kısaca: $V_s = 0$ V için $+V$, $V_s = 5$ V için $0$, $V_s = 6$ V için $-V$.

$+V$ ve $-V$ her zaman dışarıdan verilen besleme gerilimleridir; sorularda verilir. Örneğin "$\pm 15$ V ile beslenen bir op-amp" denirse pozitif doyumda çıkış $+15$ V olur.

### 6.3 Açık çevrimde $A$ neden hesaplanmaz?

Hoca bunu ayrıca açıkladı. İdeal kabulde op-amp'ın içinde, $v_d$'ye bağlı bir gerilim kaynağı ve bir direnç vardır ve $A$ ideal op-amp'ta sonsuz alınır. Bu yüzden iki giriş arasındaki fark 0,1 mV gibi çok küçük bir değer olsa bile, örneğin $A = 10^6$ için $v_o = A v_d$ formülü 100 V gibi bir değer verir. Bu mümkün olmadığından çıkış doğrudan sınırlayıcı beslemeye gider: artı ağırlıklıysa $+V$, eksi ağırlıklıysa $-V$.

> **Hocanın vurgusu:** Açık çevrimde (open loop) $A$ her zaman maksimum alınır ve hesaplanmaz. Çıkıştan girişe bir bağlantı olan kapalı çevrimde (closed loop) ise $A$'nın, yani devrenin kazancının hesaplanması gerekir.

> **Ders sonrası not:** $v_1 = v_2$ kuralı yalnız geri beslemeli (kapalı çevrim) devrelerde geçerlidir. Karşılaştırıcıda geri besleme olmadığından girişler farklı gerilimlerde kalır ve çıkış doyuma gider.

## 7. Kapalı Çevrim Kazancı: Eviren Yükselteç

### 7.1 Devre (ekrandan, 00:40:00)

Kapalı çevrimde op-amp'ın çıkışı ile girişi arasında bir bağlantı vardır. Slayttaki devrede $V_s$, $R_1$ üzerinden eviren girişe bağlıdır; çıkıştan eviren girişe bir geri besleme direnci $R_f$ bağlanmıştır; evirmeyen giriş topraktadır. Akımlar: $R_1$'den geçen $i_s$, $R_f$'den geçen $i_f$, op-amp girişlerine giren $i_1$ ve $i_2$.

Kurallar aynıdır: $i_1 = i_2 = 0$ ve $v_1 = v_2$.

### 7.2 Türetme

Akım yönleri değiştirilmeden yazılırsa:

$$i_s = \frac{V_s - v_1}{R_1}, \qquad i_f = \frac{v_1 - v_o}{R_f}$$

$i_1 = 0$ olduğundan eviren giriş düğümünde KCL $i_s = i_f$ verir. Hoca, $i_1$ sıfır kabul edilmeseydi $i_s = i_f + i_1$ yazmak gerekeceğini ve bunun bir düğüm analizi olduğunu hatırlattı. İdeal kabul bu iki akımı eşitler:

$$\frac{V_s - v_1}{R_1} = \frac{v_1 - v_o}{R_f}$$

Evirmeyen giriş toprakta olduğundan $v_2 = 0$, ikinci kuraldan $v_1 = 0$. Yerine konunca:

$$\frac{V_s}{R_1} = -\frac{v_o}{R_f} \quad\Longrightarrow\quad A = \frac{v_o}{V_s} = -\frac{R_f}{R_1}$$

Bu denklem neden yazılıyor? Çünkü kazanç çıkışın girişe oranıdır. Hocanın örneğiyle: girişe 10 V verilip çıkışta 100 V alınıyorsa kazanç $100/10 = 10$'dur. $v_o/V_s$'yi bulmak için $V_s$ ve $v_o$ denklemde ayrı taraflara toplanır.

Sonuçta ideal op-amp'ın kazancını belirleyen parametre iki direncin oranı olur.

> **Hocanın vurgusu:** Formüller ve diyagramlar değişir; önemli olan mantığı anlamak, yani bu denklemi yazabilmektir. Formülü ezberlemeyin. Devreye bir gerilim kaynağı daha eklenebilir. $R_f/R_1$'in ve önündeki eksinin nereden geldiğini anlayın.

**Soru:** $v_1$ ve $v_2$ neden sıfır oldu?

**Cevap:** $v_2$'nin bağlı olduğu nokta toprağa bağlıdır, bu yüzden $v_2 = 0$'dır. İdeal op-amp'ta girişler arası açık devre kabul edildiğinden $i_1 = i_2 = 0$ olur ve iki giriş gerilimi eşit kabul edilir. Dolayısıyla $v_1$ de 0'dır.

## 8. Gerçek Op-Amp ile Kapalı Çevrim ve Kazanç Türleri

### 8.1 Kazanç türleri

Kazancın birkaç farklı biçimi vardır:

- **Gerilim kazancı:** $A_v = v_o / v_s$ (çıkış geriliminin giriş gerilimine oranı).
- **Akım kazancı:** $A_i = i_o / i_s$ (çıkış akımının giriş akımına oranı).
- **Geçiş direnci kazancı** (transresistance): çıkış geriliminin giriş akımına oranı, $v_o / i_s$.
- **Geçiş iletkenliği kazancı** (transconductance): çıkış akımının giriş gerilimine oranı, $i_o / v_s$.

Hoca bunların "nedir, nereye gelir" diye sorulabileceğini söyledi.

### 8.2 İdeal olmayan model (ekrandan, 00:45:00)

Aynı eviren devre, op-amp'ın içindeki $R_i$, $R_o$ ve $A v_d$ kaynağı gösterilerek yeniden çizildi. Bu kez $i_1$ sıfır alınmazsa:

- $v_d$'nin oluşması için $R_i$ üzerinden bir akım geçmesi gerekir. $i_1$ ile $i_2$ aynı direnç üzerinden geçtiğinden birbirinin tersidir: $i_1 = -i_2$.
- Eviren giriş düğümünde $i_s$ artık $i_f$'ye eşit değildir: $i_s = i_1 + i_f$.
- Çıkış düğümünde çıkıştan op-amp'a doğru bir $i$ akımı vardır ve bu akım $i_f$'ye eşittir.
- Fark gerilimi: $v_d = v_2 - v_1 = -R_i i_1 = R_i i_2$.
- Çıkış gerilimi yalnız $A v_d$ değildir; $R_o$ üzerindeki düşüm de hesaba katılır.
- Giriş tarafında $V_s = R_1 i_s - v_d$ (evirmeyen giriş toprakta olduğundan), çevrenin tamamında $V_s = R_1 i_s + R_f i_f + v_o$.

> **Ders sonrası not:** Hoca çıkış için $v_o = A v_d - R_o i$ dedi. Slayttaki $i$ okuna göre (çıkış düğümünden op-amp'ın içine doğru) $R_o$ üzerinden akım $v_o$ ucundan bağımlı kaynağa aktığından $v_o = A v_d + R_o i$ yazılır. İşaret, $i$'nin seçilen yönüne bağlıdır.

Bu ifadeler birbirinin içine yazılınca iç direnç ve çıkış direncini içeren çok karmaşık bir formül çıkar. Bu yüzden sorularda op-amp ideal kabul edilir: $R_i \to \infty$ alınıp girişler açık devre sayılır ($i_1 = i_2 = 0$), $R_o = 0$ alınıp $R_o i$ düşümü ihmal edilir ve $v_o = A v_d$ kullanılır. İdeal olmasaydı $v_1$ doğrudan $v_2$'ye eşitlenemezdi; $v_1 = v_d + v_2$ olurdu ve $v_2 = 0$ iken $v_1$, $R_i$ üzerindeki gerilime eşit çıkardı.

> **Ders sonrası not:** Hoca 00:47:12 civarında "ideal diyot" dedi; kastettiği ideal op-amp'tır.

## 9. Eviren Yükselteç: Sayısal Örnek ve Doyum

### 9.1 Adı ve analizi (ekrandan, 01:05:00)

Önceki bölümdeki kapalı çevrim devre aslında **eviren yükselteç** (inverting amplifier) devresidir. "Eviren" denmesinin nedeni, $V_s$'nin op-amp'ın eksi (eviren) girişine uygulanmasıdır. Kaynak artı (evirmeyen) girişe uygulanırsa devre evirmeyen yükselteç olur.

Analiz aynı kurallarla yapılır: $i_1 = 0$ olduğundan $i_s = i_f$; $v_2 = 0$ olduğundan $v_1 = 0$. 

$$\frac{V_s - 0}{R_1} = \frac{0 - v_o}{R_f} \quad\Longrightarrow\quad A_v = \frac{v_o}{V_s} = -\frac{R_f}{R_1}$$

Bu denklemde başka bir akım ya da bilinmeyen yoktur; $R_1$ ve $R_f$ soruda verilir. Soru tersten de sorulabilir: örneğin devrenin girişi 10 katına çıkarması için $R_f$ ne olmalıdır? O zaman direnç bilinmeyen olur.

### 9.2 Sayısal örnek

Slayttaki değerler: $R_1 = 1$ kΩ, $R_f = 10$ kΩ, $V^+ = 15$ V, $V^- = -10$ V.

$$A_v = -\frac{10\ \text{k}\Omega}{1\ \text{k}\Omega} = -10$$

Devre girişi eviriyor (işaretini değiştiriyor) ve $A$ katsayısı kadar büyütüyor. Besleme gerilimleri yine sınırlayıcıdır:

| $V_s$ | Hesap $-10 V_s$ | Çıkış $v_o$ |
|---|---|---|
| 0 V | 0 V | 0 V |
| 0,1 V | −1 V | −1 V |
| 0,5 V | −5 V | −5 V |
| 1 V | −10 V | −10 V |
| 1,1 V | −11 V | −10 V (negatif doyum) |
| 2 V | −20 V | −10 V (negatif doyum) |
| −1,2 V | +12 V | +12 V |
| −10 V | +100 V | +15 V (pozitif doyum) |

<!-- BELİRSİZ: Altyazıda pozitif doyum örneği "1.71 iken 15.1 okuyamam" diye bozulmuş; slayttaki giriş değeri büyük olasılıkla −1,51 V (hesap +15,1 V, çıkış +15 V). Bu satıra ait kare yok. -->

Giriş-çıkış grafiği çizilirse, çıkış $-10$ V ile $+15$ V arasında $-10$ eğimli bir doğrudur; bunun dışında doyumdadır. Doğrusal bölge $-1{,}5\ \text{V} \le V_s \le 1\ \text{V}$ aralığıdır (ara adım eklendi: $-10 V_s = 15 \Rightarrow V_s = -1{,}5$ V, $-10 V_s = -10 \Rightarrow V_s = 1$ V).

> **Hocanın vurgusu:** Formülün nasıl çıktığını bilmek, formülü ezberlemekten çok daha yararlıdır.

## 10. Evirmeyen Yükselteç

### 10.1 Türetme (ekrandan, 01:10:00)

Bu devrede yine geri besleme vardır, bu yüzden $A$ hesaplanır. Bu kez $V_s$ evirmeyen (+) girişe bağlıdır; eviren giriş $R_1$ üzerinden toprağa, $R_f$ üzerinden çıkışa bağlıdır. Fark gerilimini oluşturan artı taraftır.

$v_2 = V_s$ ve kural gereği $v_1 = v_2 = V_s$. $i_1 = 0$ olduğundan $R_1$ ve $R_f$ akımları eşittir:

$$\frac{0 - V_s}{R_1} = \frac{V_s - v_o}{R_f}$$

Düzenlenirse (ara adım eklendi): $\dfrac{v_o}{R_f} = V_s\left(\dfrac{1}{R_1} + \dfrac{1}{R_f}\right)$, buradan

$$A_v = \frac{v_o}{V_s} = 1 + \frac{R_f}{R_1}$$

Hoca bu sonucu derste yerinde çıkarırken bir an duraksadı ve tam bu yüzden son formülü ezberlemeye gerek olmadığını, nereden geldiğini bilmenin önemli olduğunu söyledi. Kazanç, $R_f/R_1$'in bir fazlasıdır ve pozitiftir; çıkış girişle aynı işaretlidir.

### 10.2 Sayısal örnek

Aynı dirençler ($R_1 = 1$ kΩ, $R_f = 10$ kΩ) ve beslemeler ($V^+ = 15$ V, $V^- = -10$ V) ile $A_v = 1 + 10 = 11$:

- $V_s = 0$ V: $v_o = 11 \cdot 0 = 0$ V.
- $V_s = 0{,}5$ V: $v_o = 11 \cdot 0{,}5 = 5{,}5$ V.
- $V_s = 1{,}6$ V: hesap $17{,}6$ V $> V^+$, çıkış $+15$ V'ta doyar.
- $V_s = -0{,}9$ V: $v_o = -9{,}9$ V.
- $V_s = -1{,}01$ V: hesap $-11{,}11$ V.

> **Ders sonrası not:** Slaytta son satır "$11(-1{,}01\ \text{V}) > V^+$, $V_o = +15$ V" diye yazılmıştı. Hoca bunun yanlış olduğunu, $-10$ olması gerektiğini söyledi. Doğrusu: $-11{,}11$ V $< V^- = -10$ V olduğundan çıkış negatif doyumda, $v_o = -10$ V'tur.

## 11. Gerilim İzleyici

Gerilim izleyici (voltage follower) devresinde çıkış doğrudan eviren girişe bağlıdır, $V_s$ evirmeyen girişe verilir. Bir çevrim olduğundan kazanç hesabı yapılabilir. Kurallar yerine oturtulursa: evirmeyen giriş $V_s$'dir, kural gereği eviren giriş de $V_s$'dir ve eviren giriş doğrudan çıkışa bağlı olduğundan $v_o = V_s$'dir.

$$A_v = \frac{v_o}{V_s} = 1$$

Yani bu devre, ideal durumda girişteki gerilimi olduğu gibi çıkışa taşır.

## 12. Toplayıcı Yükselteç

### 12.1 Sık yapılan hata

Hoca bu devrede öğrencilerin çok karışıklık yaptığını söyledi: giriş gerilimlerinin doğrudan toplanıp çıkışa geldiği sanılır, ama öyle değildir. Her giriş ayrı ayrı analiz edilmelidir. Bunun için süperpozisyon kullanılabilir.

Süperpozisyonun hatırlatması: bir devrede birden fazla gerilim ya da akım kaynağı varsa, her kaynak tek başına bırakılıp diğer gerilim kaynakları kısa devre, diğer akım kaynakları açık devre yapılır; her durumun sonucu bulunup toplanır.

### 12.2 Örnek (ekrandan, 01:15:00)

Devrede üç kaynak üç direnç üzerinden op-amp'ın eviren girişine bağlıdır, evirmeyen giriş topraktadır: $V_A = 1$ V ile $R_A = 5$ kΩ, $V_B = 3$ V ile $R_B = 2$ kΩ, $V_C = -2$ V ile $R_C = 4$ kΩ; geri besleme direnci $R_f = 10$ kΩ. Kaynak değerleri altyazıdan, dirençler ve $V_C$ kareden alınmıştır.

**1. adım ($V_A$ tek başına):** $V_B$ ve $V_C$ kısa devre edilir. Eviren giriş 0 V'ta olduğundan $R_B$ ve $R_C$'nin iki ucu da 0 V'tadır ve $i_B = i_C = 0$ olur. Geriye $i_A = i_f$ kalır; bu, eviren yükseltecin aynısıdır:

$$\frac{V_A - 0}{R_A} = \frac{0 - v_{oA}}{R_f} \quad\Longrightarrow\quad v_{oA} = -\frac{R_f}{R_A}V_A$$

**2. adım ($V_B$ tek başına):** Aynı mantıkla $\dfrac{V_B - 0}{R_B} = \dfrac{0 - v_{oB}}{R_f}$ ve $v_{oB} = -\dfrac{R_f}{R_B}V_B$.

**3. adım ($V_C$ tek başına):** Slaytta gösterildiği gibi $i_A = i_B = 0$, $i_C = i_f$, $i_C = (V_C - 0)/R_C$, $i_f = (0 - v_o)/R_f$ ve $v_{oC} = -\dfrac{R_f}{R_C}V_C$.

**Toplam:** Üç ayrı eviren devrenin çıkışları toplanır, ortak eksi dışarı alınır:

$$v_o = -\left(\frac{R_f}{R_A}V_A + \frac{R_f}{R_B}V_B + \frac{R_f}{R_C}V_C\right)$$

$$v_o = -\left(\frac{10}{5}\cdot 1 + \frac{10}{2}\cdot 3 + \frac{10}{4}\cdot(-2)\right) = -(2 + 15 - 5) = -12\ \text{V}$$

Yani çıkış, 1 V + 3 V − 2 V = 2 V değildir; her gerilim kendi $R_f/R_k$ katsayısıyla büyütülüp toplanır. Sonuç python ile doğrulandı.

## 13. Fark Alıcı Yükselteç

### 13.1 Devre (ekrandan, 01:20:00)

Bu devrede gerilimler aynı bacağa değil, biri evirmeyen, biri eviren girişe bağlıdır. $v_d$ zaten bir fark gerilimi olduğundan iki tarafın etkisinin farkı alınır. Değerler: $V_A = 2$ V, $R_A = 6$ kΩ üzerinden eviren girişe; $V_B = 3$ V, $R_B = 8$ kΩ üzerinden evirmeyen girişe ve evirmeyen giriş ile toprak arasında $R_C = 4$ kΩ; geri besleme $R_f = 30$ kΩ.

Hoca burada da sık yapılan hatayı vurguladı: $3 - 2 = 1$ V bulup $R_f/R_A$ ile çarpmak yanlıştır. Böyle hesaplanmaz.

### 13.2 Adım adım çözüm (ekrandan, 01:25:00)

**1. adım, evirmeyen giriş gerilimi:** Evirmeyen girişe akım girmediğinden $R_B$ ve $R_C$ seri bağlıdır ve aynı akımı taşır; bu bir gerilim bölücüdür. $v_2$, $R_C$ üzerindeki gerilimdir:

$$v_2 = \frac{R_C}{R_B + R_C}V_B = \frac{4}{8 + 4}\cdot 3 = 1\ \text{V}$$

Hoca bunu sezgiyle de anlattı: 3 V'un 2 V'u $R_B$ (8 kΩ) üzerinde, 1 V'u $R_C$ (4 kΩ) üzerinde düşer.

**2. adım, eviren giriş:** Kural gereği $v_1 = v_2 = 1$ V.

**3. adım, eviren girişte düğüm denklemi:** $i_A = i_f$:

$$\frac{V_A - v_1}{R_A} = \frac{v_1 - v_o}{R_f} \quad\Longrightarrow\quad \frac{2 - 1}{6} = \frac{1 - v_o}{30}$$

Buradan $1 - v_o = 5$ ve $v_o = -4$ V.

Parametrik yazımda $v_1 = V_B \dfrac{R_C}{R_B + R_C}$ ifadesi denklemde yerine konur:

$$\frac{V_A - V_B\dfrac{R_C}{R_B + R_C}}{R_A} = \frac{V_B\dfrac{R_C}{R_B + R_C} - v_o}{R_f}$$

Karmaşık görünse de düzenlenince basit bir devre çözümüdür. Slayttaki genel sonuç (ekrandan, 01:20:00):

$$v_o = \frac{R_f}{R_A}\,\frac{1 + R_A/R_f}{1 + R_B/R_C}\,V_B - \frac{R_f}{R_A}V_A$$

$$v_o = \frac{30}{6}\cdot\frac{1 + 6/30}{1 + 8/4}\cdot 3 - \frac{30}{6}\cdot 2 = 6 - 10 = -4\ \text{V}$$

Sonuç python ile doğrulandı.

### 13.3 Direnç oranları eşit seçilirse

Hoca, direnç oranları uygun seçilirse devrenin doğrudan bir fark alıcı gibi çalışacağını anlattı. $R_A$-$R_f$ ve $R_B$-$R_C$ çiftleri, gerilimi belli bir oranda bölen yapılardır. Bu oranlar eşit olursa (hocanın örneğinde iki tarafta da 2 katlık oran: $R_B = 8$, $R_C = 16$ gibi), çıkış doğrudan iki girişin farkının o kazançla çarpımı olur. Bütün dirençler eşit seçilirse (örneğin 4'e 4 ve 16'ya 16) kazançla da uğraşmadan tam bir çıkarıcı elde edilir.

> **Ders sonrası not:** Hoca bu kısmı anlatırken oranları ve farkın sırasını ($V_A - V_B$ ile $V_B - V_A$) karışık söyledi. Doğrusu: $\dfrac{R_C}{R_B} = \dfrac{R_f}{R_A}$ ise $v_o = \dfrac{R_f}{R_A}(V_B - V_A)$; bütün dirençler eşitse $v_o = V_B - V_A$. Burada $V_B$ evirmeyen, $V_A$ eviren taraftaki kaynaktır.

**Soru:** (Slayttaki kırmızı kesikli çerçeveyle işaretli kısım soruldu.) Evirmeyen girişteki gerilim nasıl bulunuyor?

**Cevap:** Soruda ideal op-amp deniyorsa her zaman iki kural uygulanır: girişe akım geçmediği için $i_A = i_f$ yazılır ve iki giriş gerilimi eşittir. $v_2$'yi hesaplarken çerçevedeki kısma bakılır: op-amp girişine akım gitmediğinden $R_B$ ve $R_C$ seri bağlıdır ve $i_B = i_C$'dir. Seri devrede akım her yerde aynı, dirençler üzerindeki gerilimler farklıdır: 4 kΩ'luk $R_C$ üzerinde 1 V, 8 kΩ'luk $R_B$ üzerinde 2 V düşer. $v_2$, $R_C$ üzerindeki gerilimdir: $v_2 = V_B R_C / (R_B + R_C)$. Gerisi eviren yükselteç gibi yazılır: $i_A = (V_A - v_1)/R_A$, $i_f = (v_1 - v_o)/R_f$ ve ikisi eşitlenip $v_o$ çekilir. İstenirse $v_o/V_A$ oranından devrenin kazancı da bulunabilir.

## 14. Kaskat (Ardışık) Yükselteçler ve Karma Devreler

### 14.1 Kaskat yükselteç örneği (ekrandan, 01:30:00)

Kaskat yapıda op-amp'lar art arda bağlanır. Önce her katın türüne bakılır. Birinci katta kaynak artı girişe geldiği için bu bir evirmeyen yükselteçtir. İkinci katta artı giriş topraktadır, eksi girişe bir gerilim (birinci katın çıkışı) gelir; bu bir eviren yükselteçtir.

> **Ders sonrası not:** Hoca ilk katı önce "eviren" diye adlandırdı, sonra "evirmeyen" diye düzeltti; birinci kat evirmeyen, ikinci kat eviren yükselteçtir.

Analiz parçalı yapılır: önce soldaki kutu çözülür, çıkışı $v_{o1}$ diye adlandırılır, sonra bu gerilim sağdaki kutunun girişi olarak kullanılır.

**Birinci kat:** $R_1 = 5$ kΩ, $R_{f1} = 15$ kΩ, $V_s = 2$ V. Eviren giriş de 2 V'tur:

$$\frac{0 - 2}{5} = \frac{2 - v_{o1}}{15} \quad\Longrightarrow\quad v_{o1} = 8\ \text{V}$$

Parametrik olarak $A_{v1} = 1 + 15/5 = 4$; 2 V girişi 8 V yapar.

**İkinci kat:** $R_2 = 2$ kΩ, $R_{f2} = 8$ kΩ. Denklem $\dfrac{v_{o1} - 0}{R_2} = \dfrac{0 - v_o}{R_{f2}}$ yazılarak $v_o$ çekilir. Parametrik olarak $A_{v2} = -8/2 = -4$.

**Toplam kazanç:** Slayttaki kural: kaskat yükselteçlerin kazancı, tek tek kazançların çarpımıdır.

$$A_{v,toplam} = A_{v1}A_{v2} = 4\cdot(-4) = -16$$

Hoca bu değeri derste hesaplamadıklarını ama $-16$ olması gerektiğini söyledi.

> **Ders sonrası not:** Slayttaki formül $v_o = -\dfrac{R_{f2}}{R_2}\left(1 + \dfrac{R_{f2}}{R_1}\right)V_s$ diye yazılmış. Parantezin içinde $R_{f1}/R_1$ olmalıdır: $v_o = -\dfrac{R_{f2}}{R_2}\left(1 + \dfrac{R_{f1}}{R_1}\right)V_s$. Bu değerlerle ve besleme sınırı yoksa $v_o = -16 \cdot 2 = -32$ V çıkar (ara adım eklendi; derste besleme verilmedi ve çıkış hesaplanmadı).

### 14.2 Karma devre: gerilim izleyiciler ve fark alıcı

Hoca son olarak farklı devre yapılarının birleştirilebileceğini gösterdi. Ekrandaki devrede iki gerilim izleyici vardı; bunların çıkışları dirençlerle bir op-amp'ın iki girişine bağlanınca bir fark alıcı devre oluşur. Gerilim izleyici girişi olduğu gibi aktardığından, evirmeyen taraftaki gerilim bir bölücüyle bulunur: izleyicinin çıkışı $R_3$ ve $R_4$ bölücüsünden geçer ve $v_x = v^+ \dfrac{R_4}{R_3 + R_4}$ olur. Sonra eviren girişin de $v_x$ olduğu yazılıp düğüm denklemi kurulur: $\dfrac{v_{-} - v_x}{R_1} = \dfrac{v_x - v_{out}}{R_2}$ biçiminde eşitlenerek $v_{out}$ bulunur.

<!-- BELİRSİZ: Bu karma devrenin karesi yok; direnç adları ve eviren taraftaki kaynak altyazıdan kısmen çıkarılabildi. -->

Hoca bu tür karışık devrelerin de sorulabileceğini, ama matematiksel olarak neyin nasıl yapıldığı anlaşıldıysa hepsinin çözülebileceğini söyledi.

## 15. Op-Amp Konusunun Özeti

Hoca konuyu şöyle bağladı:

- İdeal op-amp'ta iki kural vardır: $i_1 = i_2 = 0$ ve bu yüzden $v_1 = v_2$. Gerekçe, giriş direnci $R_i$'nin sonsuz alınmasıdır; girişler açık devre gibidir.
- İdeal op-amp'ta çıkış direnci $R_o = 0$ kabul edilir.
- Kazanç çok yüksekse çıkış, besleme gerilimlerine bağlı olarak doyuma gider.
- Kaskat yapılar ve süperpozisyonla çözüm gösterildi.
- Slaytların sonunda formül özeti vardır:
  - Eviren: $v_o = -\dfrac{R_f}{R_1}V_s$
  - Evirmeyen: $v_o = \left(1 + \dfrac{R_f}{R_1}\right)V_s$
  - Gerilim izleyici: $v_o = V_s$
  - Toplayıcı: dirençler ortaksa $v_o = -\dfrac{R_f}{R}\sum V_k$
  - Fark alıcı: bütün dirençler eşitse çıkış iki girişin farkıdır; değilse önce bölücüden evirmeyen girişin gerilimi bulunur, eviren girişe eşitlenir ve devre eviren yükselteç gibi çözülür.

> **Hocanın vurgusu:** Formülleri ezberlemeyin, ama nasıl elde edildiklerini unutmayın. Nasıl geldiğini anladıysanız hiçbir problem yoktur.

## 16. Ödev Soruları: Kaynak Dönüşümü ve Thevenin Eşdeğeri

Op-amp konusundan sonra hoca, önceki derste verilen iki ödev sorusunu öğrencilere çözdürdü. Her iki soru da önceki derslerin konularıdır (kaynak dönüşümü, çevre analizi, Thevenin eşdeğeri). Çözümler Örnek Sorular bölümünde ayrıntılıdır.

### 16.1 Example 24: Kaynak dönüşümüyle $v_x$ (ekrandan, 01:55:00)

Bir öğrenci çözümü anlattı: önce iki kaynak dönüşümü ve paralel dirençlerin birleştirilmesiyle devre tek çevreli hale getirilir, sonra çevre denklemi ve $v_x$ için ek bir denklem yazılır. Hoca bir ara bağımlı kaynağın kutbu ile 3 V'luk kaynağın kutbunun ters gibi durduğunu sordu; öğrenci kutupların öyle olması gerektiğini söyledi. Sonuç $v_x = 7{,}5$ V.

Başka bir öğrenci aynı soruyu düğüm analiziyle çözdüğünü anlattı: alt düğümü referans alıp $v_x$'in bulunduğu düğüm ile 18 V'luk kaynağın düğümü arasında akımları yazmış ve doğrudan $v_x$'i çekmiş. Hoca bunun da doğru ve güzel bir başka çözüm olduğunu söyledi. Hoca ayrıca soru çevre (mesh) analiziyle de çözülebilir dedi.

### 16.2 Example 25: Bağımlı kaynaklı devrenin Thevenin eşdeğeri (ekrandan, 02:00:00)

Bir öğrenci $R_{Th}$'yi 1 V'luk test kaynağıyla, $V_{Th}$'yi açık devre gerilimiyle buldu: $R_{Th} = 6\ \Omega$, $V_{Th} = V_{oc} = 20$ V.

Hoca çözümün ardından yöntemi yeniden anlattı (ekrandan, 02:15:00):

- Thevenin eşdeğeri için iki şey gerekir: eşdeğer direnç $R_{Th}$ ve eşdeğer gerilim $V_{Th}$.
- Bağımlı kaynak olmasaydı akım kaynağı açık devre yapılır, a-b uçlarından bakılır: 4 Ω ile 2 Ω seri (6 Ω), bu 6 Ω'luk dirence paralel (3 Ω), sonra 2 Ω seri; $R_{Th} = 5\ \Omega$ bulunurdu. Bağımlı kaynak olduğu için bu yol kullanılamaz, çünkü bağımlı kaynak ne kısa ne açık devre yapılabilir. Bu yüzden a-b'ye 1 V'luk bir kaynak bağlanır, akımı bulunur ve gerilim akıma bölünür. Sonuç 5 Ω değil, 6 Ω'dur.
- $V_{Th}$ için devre olduğu gibi tutulur. a-b açık olduğundan uçtaki 2 Ω'dan akım geçmez; a noktasının gerilimi 6 Ω üzerindeki gerilime eşittir ve çevre analiziyle bulunur.
- Eşdeğer devre: 20 V'luk kaynak ve seri 6 Ω. Asıl devreye ve eşdeğer devreye aynı yük direnci $R_L$ bağlanırsa yükten geçen akım ve yük üzerindeki gerilim iki devrede aynı olur; devre sadeleştirilmiş olur.

> **Ders sonrası not:** Hoca, akım istenseydi test devresindeki $i_o$'nun Norton akımı olacağını söyledi. Norton akımı a-b uçlarının kısa devre akımıdır: $I_N = V_{Th}/R_{Th} = 20/6 = 10/3$ A. Test devresindeki $i_o = 1/6$ A ise yalnız $R_{Th}$'yi bulmaya yarar.

> **Hocanın vurgusu:** Thevenin ve Norton'a çok ciddi çalışın; bunlara benzer sorular gelecektir. Bunlar zor sorular değildir, yalnız KCL ve KVL'yi dikkatle uygulama sorularıdır. Özellikle Thevenin çok önemlidir, çünkü içinde KCL, KVL, hatta süperpozisyon uygulanabilir.

### 16.3 Thevenin eşdeğerini bulmada en yaygın yollar

Hoca, önceki derste anlatılan dört yöntem içinden en yaygın olanları şöyle özetledi:

- **Bağımlı kaynak varsa $R_{Th}$:** Bağımsız gerilim kaynakları kısa, bağımsız akım kaynakları açık devre yapılır, uçlara test kaynağı bağlanır. Bu çok standart ve en çok kullanılan yöntemdir.
- **Bağımlı kaynak yoksa $R_{Th}$:** Bağımsız kaynaklar aynı şekilde söndürülür ve eşdeğer direnç doğrudan hesaplanır.
- **Nereden bakılır?** Her zaman soruda istenen uçlardan (a-b). Bu örnekte a ucundaki 2 Ω, iç noktadan bakılsaydı hesaba girmezdi; a-b'den bakınca içerideki yapıya seri olduğu görülür.
- **$V_{oc}$ için:** Bağımlı kaynak yoksa en çok kaynak dönüşümü, bağımlı kaynak varsa normal çevre analizi kullanılır; çünkü $v_x$ gibi kontrol değişkenleri devrenin bir yerinden gelir ve denklemlerde tutulmalıdır.

Hoca ek alıştırma isteyenler için dersin başında önerdiği devre analizi kitabını yeniden andı, ama slaytlardaki soruların yeterli olduğunu, önemli olanın bütün soruları kendi başına sıfırdan çözebilmek olduğunu söyledi. <!-- BELİRSİZ: Kitap adı altyazıda "Xiaomi" diye bozulmuş; büyük olasılıkla Alexander ve Sadiku'nun devre analizi kitabı. -->

## Örnek Sorular

### Soru 1: Gerilim karşılaştırıcı (ekrandan, 00:30:00)

$V_s$ eviren girişe, evirmeyen giriş toprağa bağlı, $i_s = i_1 = i_2 = 0$. $V_s$'nin işaretine göre $v_o$ ne olur?

> **Çözüm (derste verildi):** $V_s = 0$ V ise iki giriş eşittir, $v_o = 0$ V. $V_s < 0$ ise evirmeyen giriş daha büyüktür, $v_o = V^+$. $V_s > 0$ ise eviren giriş daha büyüktür, $v_o = V^-$. Geri besleme olmadığından $A$ sonsuz kabul edilir ve en küçük fark bile çıkışı beslemeye götürür.

### Soru 2: Karşılaştırıcıda $v_2 = 5$ V (ekrandan, 00:35:00)

Op-amp'ın nasıl çalıştığını düşünerek, evirmeyen girişe $v_2 = 5$ V bağlıyken, eviren girişteki $V_s$ için $v_o$ ne olur? (1) $V_s = 0$ V, (2) $V_s = 5$ V, (3) $V_s = 6$ V.

> **Çözüm (derste verildi):**
>
> 1. $V_s = 0$ V: $v_d = v_2 - v_1 = 5 - 0 = 5$ V $> 0$, $A$ çok büyük; $v_o = +V$.
> 2. $V_s = 5$ V: iki giriş eşit, $v_d = 0$; $v_o = 0$ V.
> 3. $V_s = 6$ V: $v_d = 5 - 6 = -1$ V $< 0$; $v_o = -V$.
>
> $+V$ ve $-V$ besleme gerilimleridir; örneğin $\pm 15$ V beslemede (1) için $v_o = +15$ V olur.

### Soru 3: Eviren yükselteç (ekrandan, 01:05:00)

$R_1 = 1$ kΩ, $R_f = 10$ kΩ, $V^+ = 15$ V, $V^- = -10$ V. Kazancı bulun ve çeşitli $V_s$ değerleri için çıkışı belirleyin.

> **Çözüm (derste verildi):** $i_s = i_f$ ve $v_1 = v_2 = 0$ ile $\dfrac{V_s}{R_1} = -\dfrac{v_o}{R_f}$, $A_v = -R_f/R_1 = -10$. $V_s = 0$: 0 V; $V_s = 0{,}5$ V: $-5$ V; $V_s = 1$ V: $-10$ V; $V_s = 1{,}1$ V: $-11$ V hesaplanır ama $V^-$ sınırı nedeniyle $-10$ V; $V_s = -1{,}2$ V: $+12$ V; hesap $+15$ V'u aşarsa çıkış $+15$ V'ta kalır.

### Soru 4: Evirmeyen yükselteç (ekrandan, 01:10:00)

Aynı dirençler ve beslemelerle $V_s$ evirmeyen girişe bağlı. $A_v$ ve $V_s = 0;\ 0{,}5;\ 1{,}6;\ -0{,}9;\ -1{,}01$ V için $v_o$?

> **Çözüm (derste verildi, son satır düzeltildi):** $\dfrac{0 - V_s}{R_1} = \dfrac{V_s - v_o}{R_f}$ ile $A_v = 1 + R_f/R_1 = 11$. Çıkışlar: 0 V; 5,5 V; $17{,}6 > 15$ olduğundan $+15$ V; $-9{,}9$ V; $-11{,}11 < -10$ olduğundan $-10$ V (slayttaki "+15 V" yanlıştır, hoca derste düzeltti).

### Soru 5: Toplayıcı yükselteç (ekrandan, 01:15:00)

$V_A = 1$ V, $R_A = 5$ kΩ; $V_B = 3$ V, $R_B = 2$ kΩ; $V_C = -2$ V, $R_C = 4$ kΩ; $R_f = 10$ kΩ. $v_o$?

> **Çözüm (derste verildi):** Süperpozisyonla her kaynak için ayrı bir eviren yükselteç: $v_o = -\left(\frac{10}{5}\cdot 1 + \frac{10}{2}\cdot 3 + \frac{10}{4}\cdot(-2)\right) = -12$ V.

### Soru 6: Fark alıcı yükselteç (ekrandan, 01:20:00)

$V_A = 2$ V, $R_A = 6$ kΩ (eviren taraf); $V_B = 3$ V, $R_B = 8$ kΩ, $R_C = 4$ kΩ (evirmeyen taraftaki bölücü); $R_f = 30$ kΩ. $v_o$?

> **Çözüm (derste verildi):** $v_2 = 3\cdot\frac{4}{12} = 1$ V $= v_1$. $\dfrac{2 - 1}{6} = \dfrac{1 - v_o}{30}$, $v_o = -4$ V. Genel formülle de $5\cdot\frac{1{,}2}{3}\cdot 3 - 5\cdot 2 = -4$ V.

### Soru 7: Kaskat yükselteç (ekrandan, 01:30:00)

Birinci kat evirmeyen ($R_1 = 5$ kΩ, $R_{f1} = 15$ kΩ, $V_s = 2$ V), ikinci kat eviren ($R_2 = 2$ kΩ, $R_{f2} = 8$ kΩ). Toplam kazanç?

> **Çözüm (derste verildi):** $A_{v1} = 1 + 15/5 = 4$, $v_{o1} = 8$ V; $A_{v2} = -8/2 = -4$; $A_{v,toplam} = -16$.

> **Çözüm (derste verilmedi):** Besleme sınırı olmadığı varsayılırsa $v_o = A_{v2}\, v_{o1} = -4 \cdot 8 = -32$ V (python ile doğrulandı).

### Soru 8: Example 24, kaynak dönüşümüyle $v_x$ (ekrandan, 01:55:00)

Devre: 6 V'luk kaynak ve seri 2 Ω, sol üst düğüme bağlı. Bu düğüm ile toprak arasında 2 Ω vardır ve üzerindeki gerilim $v_x$'tir (+ üstte). Bu düğüm ile sağ üst düğüm arasında 4 Ω ve ona paralel, oku sol düğüme doğru olan $0{,}25 v_x$ bağımlı akım kaynağı vardır. Sağ üst düğüm 18 V'luk kaynağın artı ucudur. Kaynak dönüşümü kullanarak $v_x$'i bulun.

> **Çözüm (derste bir öğrenci verdi):**
>
> 1. 6 V ve seri 2 Ω, $6/2 = 3$ A akım kaynağı ve paralel 2 Ω olur.
> 2. $0{,}25 v_x$ akım kaynağı ve paralel 4 Ω, $4 \cdot 0{,}25 v_x = v_x$ değerli bağımlı gerilim kaynağı ve seri 4 Ω olur.
> 3. Paralel iki 2 Ω birleşir: 1 Ω. 3 A ve paralel 1 Ω, 3 V ve seri 1 Ω olur. $v_x$, bu 1 Ω'dan sonraki düğüm ile toprak arasındaki gerilimdir.
> 4. Tek çevre (saat yönünde $i$): $-3 + 1\cdot i + 4i + v_x + 18 = 0$.
> 5. Sol kolda: $-3 + i + v_x = 0 \Rightarrow v_x = 3 - i$.
> 6. Yerine konunca: $-3 + 5i + 3 - i + 18 = 0 \Rightarrow 4i = -18 \Rightarrow i = -4{,}5$ A.
> 7. $v_x = 3 - (-4{,}5) = 7{,}5$ V.
>
> İkinci öğrencinin düğüm yaklaşımı: alt düğüm referans alınınca sol düğümde KCL $\dfrac{6 - v_x}{2} + 0{,}25 v_x + \dfrac{18 - v_x}{4} = \dfrac{v_x}{2}$, buradan $7{,}5 = v_x$. İki yöntem aynı sonucu verir (python ile doğrulandı).

### Soru 9: Example 25, Thevenin eşdeğeri (ekrandan, 02:00:00)

Devre: 5 A akım kaynağı (yukarı doğru) ile paralel 4 Ω (üzerindeki gerilim $v_x$, + üstte). 4 Ω'un üst düğümü ile orta düğüm arasında 2 Ω ve ona paralel $2v_x$ bağımlı gerilim kaynağı (artı ucu orta düğüm tarafında). Orta düğüm ile toprak arasında 6 Ω, orta düğüm ile a ucu arasında 2 Ω; b ucu topraktır. a-b uçlarına göre Thevenin eşdeğerini bulun.

> **Çözüm (derste bir öğrenci verdi):**
>
> **$R_{Th}$, test kaynağıyla:** 5 A'lik kaynak açık devre yapılır, a-b'ye $v_o = 1$ V bağlanır. Çevreler: $i_1$ (üst, bağımlı kaynak ve 2 Ω), $i_2$ (4 Ω, 2 Ω, 6 Ω), $i_3$ (6 Ω, uçtaki 2 Ω ve test kaynağı). Test kaynağının akımı $i_o = -i_3$.
>
> - Çevre 1: $-2v_x + 2i_1 - 2i_2 = 0$
> - Çevre 2: $12 i_2 - 2 i_1 - 6 i_3 = 0$
> - Çevre 3: $1 + 8 i_3 - 6 i_2 = 0$
> - Kontrol değişkeni: $v_x = -4 i_2$
>
> Çevre 1'de $v_x$ yerine konunca $8 i_2 + 2 i_1 - 2 i_2 = 0 \Rightarrow i_1 = -3 i_2$. Çevre 2'de yerine konunca $18 i_2 - 6 i_3 = 0$. Çevre 3 ile birlikte: $8 i_3 - 6 i_2 = -1$ ve $6 i_2 = 2 i_3$ olduğundan $6 i_3 = -1$, $i_3 = -1/6$ A. Dolayısıyla $i_o = 1/6$ A ve
>
> $$R_{Th} = \frac{1\ \text{V}}{1/6\ \text{A}} = 6\ \Omega$$
>
> **$V_{Th}$, açık devre gerilimi:** Çevreler: $i_1$ (5 A ve 4 Ω), $i_2$ (4 Ω, 2 Ω, 6 Ω), $i_3$ (üst, bağımlı kaynak ve 2 Ω). Akım kaynağından $i_1 = 5$ A.
>
> - $v_x = 4(i_1 - i_2) = 20 - 4 i_2$
> - Çevre 2: $12 i_2 - 4 i_1 - 2 i_3 = 0 \Rightarrow 12 i_2 - 2 i_3 = 20$
> - Çevre 3: $-2 v_x + 2 i_3 - 2 i_2 = 0 \Rightarrow -40 + 8 i_2 + 2 i_3 - 2 i_2 = 0 \Rightarrow 6 i_2 + 2 i_3 = 40$
>
> İki denklem toplanınca $18 i_2 = 60$, $i_2 = 10/3$ A. a-b açık olduğundan uçtaki 2 Ω'dan akım geçmez; $V_{oc}$ 6 Ω üzerindeki gerilimdir: $V_{oc} = 6 \cdot \frac{10}{3} = 20$ V.
>
> **Sonuç:** Thevenin eşdeğeri 20 V'luk kaynak ve seri 6 Ω. Bağımlı kaynak hesaba katılmasaydı $R_{Th}$ yanlışlıkla 5 Ω bulunurdu. Bütün değerler python ile doğrulandı.

> **Çözüm (derste verilmedi):** Norton eşdeğeri istenirse $I_N = V_{Th}/R_{Th} = 20/6 = 10/3 \approx 3{,}33$ A ve paralel 6 Ω olur.

## Dersin Toparlaması

Bu derste işlemsel yükselteç (op-amp) ele alındı. Op-amp'ın içinde büyük bir giriş direnci, $A v_d$ değerli bir bağımlı gerilim kaynağı ve küçük bir çıkış direnci vardır. İdeal modelde $A$ ve $R_i$ sonsuz, $R_o$ sıfır alınır; bundan iki temel kural çıkar: girişlere akım girmez ve iki giriş gerilimi eşittir. Çıkış hiçbir zaman besleme gerilimlerinin dışına çıkamaz; hesap dışarı taşarsa çıkış doyuma gider. Geri beslemesiz karşılaştırıcıda çıkış doğrudan $+V$, $0$ ya da $-V$ olurken, geri beslemeli devrelerde kazanç dirençlerden hesaplanır: eviren yükselteçte $-R_f/R_1$, evirmeyende $1 + R_f/R_1$, gerilim izleyicide 1. Toplayıcı süperpozisyonla, fark alıcı gerilim bölücü ve düğüm denklemiyle, kaskat yapılar katlara bölünerek çözülür ve kat kazançları çarpılır. Hocanın en çok vurguladığı nokta, formülleri ezberlemek yerine iki ideal kuralla düğüm denklemini kurabilmekti.

Dersin son bölümünde önceki konulara dönülerek kaynak dönüşümü ve bağımlı kaynaklı Thevenin eşdeğeri soruları çözüldü. Bağımlı kaynak varsa $R_{Th}$ test kaynağıyla, $V_{Th}$ açık devre gerilimiyle bulunur ve direnç her zaman istenen a-b uçlarından bakılarak hesaplanır. Hoca ilerleyen konularda alternatif akım, fazör diyagramları ve kondansatörün şarj-deşarj davranışının ayrıntılı olarak işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
