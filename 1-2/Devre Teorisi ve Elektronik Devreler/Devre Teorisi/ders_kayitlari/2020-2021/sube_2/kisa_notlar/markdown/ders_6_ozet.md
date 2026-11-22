# Ders 6 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Devre analizinin genel çerçevesi ve eşdeğer devre fikri
  - Şimdiye kadar Ohm yasası, KCL ve KVL, bunlardan türetilen düğüm (node) ve çevre (mesh) analizi ile süperpozisyon işlendi. Bu yöntemler birbirinin üzerine kurulur: düğüm ve çevre analizi KCL ve KVL'den, KCL ve KVL de Ohm yasasından gelir.
  - Bu dersten itibaren amaç, karmaşık bir devreyi en sade biçimine, yani tek bir kaynak ve tek bir dirençten oluşan "çekirdek" devreye indirmektir.
  - İki devrenin eşdeğer sayılmasının ölçütü, ilgili uçlardaki akım-gerilim (v-i) karakteristiklerinin birebir aynı olmasıdır.
- Kaynak dönüşümü (source transformation)
  - Gerilim kaynağına seri bağlı bir direnç, değeri $V_s/R$ olan bir akım kaynağı ve ona paralel aynı dirençle gösterilebilir. Tersi de geçerlidir: akım kaynağına paralel direnç, $V = I_s R$ değerli gerilim kaynağı ve seri dirence dönüşür.
  - Dönüşümde kaynağın yönü korunur: akım kaynağının oku, gerilim kaynağının artı ucunu gösterir.
  - Kaynak dönüşümü, Thevenin ve Norton eşdeğerlerini bulmanın birinci yöntemi olarak da kullanılır. Bağımlı kaynak varken doğrudan uygulanamaz.
- Thevenin ve Norton eşdeğer devreleri
  - İki uçlu her doğrusal devre, bir gerilim kaynağı $V_{TH}$ ve seri direnç $R_{TH}$ (Thevenin) ya da bir akım kaynağı $I_N$ ve paralel direnç $R_N$ (Norton) ile gösterilebilir.
  - Eşdeğer devreye bağlanan yük direnci $R_L$ üzerindeki akım $i_L$ ve gerilim $v_L$, orijinal devredekiyle aynı olmalıdır.
  - $R_N = R_{TH}$ ve $I_N = V_{TH}/R_{TH}$ olduğundan Thevenin eşdeğeri bulununca Norton eşdeğeri kaynak dönüşümüyle elde edilir.
- $V_{TH}$ ve $R_{TH}$ bulmak için dört yöntem
  - Yöntem 1: Kaynak dönüşümleriyle devreyi adım adım sadeleştirmek.
  - Yöntem 2: Yük uçlarını açıp açık devre gerilimini ($V_{oc} = V_{TH}$), sonra uçları kısa devre edip kısa devre akımını ($I_{sc} = I_N$) bulmak; $R_{TH} = V_{oc}/I_{sc}$.
  - Yöntem 3: $V_{oc}$'yi bulmak; $R_{TH}$ için bağımsız gerilim kaynaklarını kısa devre, bağımsız akım kaynaklarını açık devre yapıp açık uçlardan bakmak.
  - Yöntem 4: Bağımlı kaynak varsa uçlara bir test kaynağı (1 V ya da 1 A) bağlayıp $R_{TH} = v_{test}/i_{test}$ hesaplamak.
  - Yöntem 1-3 bağımlı kaynak yokken kullanılır. Bağımlı kaynaklı devrede Yöntem 2 ya da Yöntem 4 kullanılır.
- Maksimum güç aktarımı
  - Yük direnci üzerindeki güç, yük direncinin Thevenin direncine eşit olduğu durumda ($R_L = R_{TH}$) en büyüktür.
- Kondansatör (kapasitör)
  - İki iletken levha arasında yalıtkan (dielektrik) bulunan, enerjiyi elektrik alanında depolayan elemandır. Birimi faraddır.
  - Kapasitans levha alanıyla doğru, levhalar arası uzaklıkla ters orantılıdır ve dielektrik malzemenin sabitine bağlıdır.
  - Türler: kutupsuz (kağıt, mika, seramik, polimer yalıtkanlı), elektrolitik (kutuplu; alüminyum, tantal), ayarlı kondansatörler, MEMS kondansatörler, süper (ultra) kapasitörler.
  - Akım-gerilim ilişkisi: $q = C v_C$, $i_C = C\,\dfrac{dv_C}{dt}$, $v_C = \dfrac{1}{C}\displaystyle\int_{t_0}^{t_1} i_C\,dt$.
  - RC devresinde şarj: $v(t) = V_C\left(1 - e^{-t/\tau}\right)$; deşarj: $v(t) = V_C\,e^{-t/\tau}$; zaman sabiti $\tau = RC$.
  - Paralel kondansatörler toplanır: $C_{eq} = C_1 + C_2 + \dots$; seri kondansatörlerde $\dfrac{1}{C_{eq}} = \dfrac{1}{C_1} + \dfrac{1}{C_2} + \dots$
  - DC altında en az $5\tau$ geçtikten sonra (kalıcı durum) ideal kondansatör açık devre gibi davranır.
- Bobin (indüktör)
  - Akımın oluşturduğu manyetik alanda enerji depolayan, iletken telin sarılmasıyla yapılan elemandır. Birimi henry'dir.
  - $v_L = L\,\dfrac{di_L}{dt}$, $i_L = \dfrac{1}{L}\displaystyle\int v_L\,dt$.
  - Seri bobinler dirençler gibi toplanır, paralel bobinlerde terslerin toplamı alınır.
  - Kondansatörde gerilim, bobinde akım sürekli olmak zorundadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kısa devre akımını bulurken kullanılan eşdeğer direnç Thevenin direnci değildir
  - Yöntem 2'de uçlar kısa devre edilip ana koldaki akımı bulmak için bir eşdeğer direnç hesaplanır (örnekte $3 + 6\parallel 7 \approx 6{,}23\ \Omega$). Bu değer $R_{TH}$ ya da $R_N$ değildir; yalnız $I_{sc}$'yi bulmaya yarar. Hoca bu hatanın sık yapıldığını söyledi.
- Bağımlı kaynak devreden atılamaz
  - Bağımsız kaynaklar söndürülebilir (gerilim kaynağı kısa, akım kaynağı açık devre), bağımlı kaynak söndürülemez. Bu yüzden bağımlı kaynaklı devrede ya $I_{sc}$ bulunur ya da test kaynağı bağlanır. Hangi yöntemin bağımlı kaynağı etkisiz kıldığına bakmak gerekir (örneğin $v_x = 0$ olunca kaynak kendiliğinden devre dışı kalır).
- Kaynak dönüşümünde akım kaynağına direnç her zaman paralel bağlanır
  - Gerilim kaynağı ve seri direnç akım kaynağına çevrilirken direnç akım kaynağına seri değil paralel konur.
- Maksimum güç kuralı
  - Yük üzerinde maksimum güç için önce devrenin Thevenin direnci bulunur, sonra $R_L = R_{TH}$ seçilir. Hoca bu kuralın unutulmamasını istedi.
- Şarj ve deşarj formülleri karıştırılmamalı
  - Hoca iki formülü bilmenin şart olduğunu söyledi. Ayırt etmenin yolu sınır değerleridir: şarjda $t \to \infty$ iken $v \to V_C$; deşarjda $t = 0$ iken $v = V_C$.
- Kondansatör gerilim, bobin akım depolar
  - Hoca bu ayrımın akılda tutulmasını istedi: kondansatörde akım gerilimin türeviyle, bobinde gerilim akımın türeviyle ilişkilidir.

## Kısa Tekrar Notları

- Kaynak dönüşümü: $V_s$ seri $R$ ⇔ $I_s = V_s/R$ paralel $R$; yön korunur.
- Thevenin: $V_{TH} = V_{oc}$, $R_{TH} = V_{oc}/I_{sc}$; Norton: $I_N = I_{sc} = V_{TH}/R_{TH}$, $R_N = R_{TH}$.
- Bağımlı kaynak yoksa $R_{TH}$: gerilim kaynakları kısa, akım kaynakları açık, açık uçlardan bakılır.
- Bağımlı kaynak varsa: $V_{oc}/I_{sc}$ ya da test kaynağı ($R_{TH} = v_{test}/i_{test}$).
- $V_{TH}$ ve $I_N$ negatif çıkabilir; işaret, $V_{oc}$ için seçilen yönün tersine olduğunu gösterir.
- Maksimum güç: $R_L = R_{TH}$.
- Kondansatör: $i_C = C\,dv_C/dt$; paralelde toplanır, seride terslerin toplamı.
- Bobin: $v_L = L\,di_L/dt$; seride toplanır, paralelde terslerin toplamı.
- $\tau = RC$; $5\tau$ sonra kondansatör DC'de açık devre.
- Şarj: $V_C(1 - e^{-t/\tau})$; deşarj: $V_C e^{-t/\tau}$.

## Detaylı Açıklamalar

- Kaynak dönüşümü örneği (ekrandan, 00:12:20)
  - Devrede $4\ \Omega$ paralel $3$ A (aşağı yönlü), $2\ \Omega$ ve $3\ \Omega$ seri kollar, $8\ \Omega$ üzerinde $v_0$ ve $12$ V'luk bir kaynak vardır. $3$ A ve $4\ \Omega$, $12$ V ve seri $4\ \Omega$'a; $12$ V ve seri $3\ \Omega$, $4$ A ve paralel $3\ \Omega$'a dönüştürülür. Seri $4 + 2 = 6\ \Omega$ ile $12$ V tekrar $2$ A ve paralel $6\ \Omega$ olur. $6\ \Omega \parallel 3\ \Omega = 2\ \Omega$; akım kaynakları birleşince yukarı yönlü $2$ A kalır.
  - Akım bölücüyle $i = 2 \cdot \dfrac{2}{8+2} = 0{,}4$ A, $v_0 = 8 \cdot 0{,}4 = 3{,}2$ V.
  - Hoca paralel dirençler için bir kestirme verdi: iki direnç arasında $k$ kat fark varsa eşdeğer, büyük direncin $k+1$'e bölümüdür ($6\parallel 3$: $6/3 = 2$).
- Thevenin eşdeğeri için dört yöntemin aynı örnekte karşılaştırılması (ekrandan, 00:32:20 ve 00:37:20)
  - Devre: $12$ V kaynak, seri $3\ \Omega$, paralel $6\ \Omega$, seri $7\ \Omega$, uçlarda $R_L$.
  - $V_{oc} = 12 \cdot \dfrac{6}{3+6} = 8$ V (açık uçta $7\ \Omega$'dan akım geçmez).
  - $I_{sc}$: ana kol akımı $12/(3 + 6\parallel 7) \approx 1{,}926$ A; $7\ \Omega$ koluna düşen pay $1{,}926 \cdot \dfrac{6}{13} \approx 0{,}889$ A. $R_{TH} = 8/0{,}889 = 9\ \Omega$.
  - Söndürme yöntemi: $R_{TH} = 7 + 6\parallel 3 = 9\ \Omega$. Kaynak dönüşümüyle de aynı $8$ V ve $9\ \Omega$ bulunur.
- Bağımlı kaynaklı iki örnek
  - $v_x/4000$ bağımlı akım kaynaklı devrede (ekrandan, 00:57:20) $V_{oc} = 8$ V, kısa devrede $v_x = 0$ olduğu için bağımlı kaynak çalışmaz, $I_{sc} = 4/5000 = 0{,}8$ mA ve $R_{TH} = 10\ \text{k}\Omega$. Bağımlı kaynağı yok sayıp söndürme yöntemi uygulanırsa yanlış olarak $5\ \text{k}\Omega$ bulunur.
  - $1{,}5i$ bağımlı gerilim kaynaklı devrede (ekrandan, 01:02:20) uçlar açık olduğundan $i = 0$, kaynak etkisizdir ve $V_{oc} = 0$. $R_{TH}$ için uçlara $1$ A test akımı bağlanır, $i = -1$ A olur; düğüm denklemiyle $v_{test} = 0{,}6$ V, $R_{TH} = 0{,}6\ \Omega$.
- Kondansatörün davranışı
  - Boş kondansatör ilk anda hızlı şarj olur. Levhalar doldukça kaynakla kondansatör arasındaki potansiyel farkı azalır ve şarj yavaşlar. Deşarj da önce hızlı, sonra yavaştır.
  - Gerçek kondansatör ve bobinde enerji kaybı vardır; bu bir direnç eklenerek modellenir, idealde göz ardı edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
