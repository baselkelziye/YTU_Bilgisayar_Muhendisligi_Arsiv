# Ders 6 Genişletilmiş Notu: Kaynak Dönüşümü, Thevenin ve Norton Eşdeğerleri, Kondansatör ve Bobin

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Şimdiye Kadarki Yöntemlerin Tekrarı ve Eşdeğer Devre Fikri
- 2. Kaynak Dönüşümü (Source Transformation)
- 3. Thevenin ve Norton Eşdeğer Devreleri
- 4. Thevenin Eşdeğerini Bulmanın Dört Yöntemi
- 5. Bağımlı Kaynaklı Devrelerde Thevenin Eşdeğeri
- 6. Maksimum Güç Aktarımı
- 7. Kondansatör (Kapasitör)
- 8. Bobin (İndüktör)
- Örnek Sorular
- Dersin Toparlaması

## 1. Şimdiye Kadarki Yöntemlerin Tekrarı ve Eşdeğer Devre Fikri

Hoca derse, şimdiye kadar işlenen konuların nasıl birbirinin üzerine kurulduğunu özetleyerek başladı. Ders Ohm yasasıyla başlamış, temel terimler bu yasa üzerinden tanıtılmıştı. Sonra KCL (Kirchhoff Akım Yasası) ve KVL (Kirchhoff Gerilim Yasası) işlendi; bunlardan da düğüm (node) ve çevre (mesh) analizi türetildi. Hocanın anlatımıyla zincir şöyledir: düğüm ve çevre analizi KCL ve KVL'den, KCL ve KVL de Ohm yasasından gelir. Süperpozisyon da bu araçlara eklenir: örneğin iki gerilim ve bir akım kaynağı olan bir devrede önce süperpozisyonla hangi kaynağın kısa, hangisinin açık devre yapılacağına karar verilir, sonra her alt devre çevre ya da düğüm analiziyle çözülür.

Bundan sonraki konuların ortak amacı farklıdır: karmaşık bir devreyi, aynı davranışı gösteren en sade biçime, yani **tek bir kaynak ve tek bir direnç** içeren "çekirdek" devreye indirmek. Seri-paralel direnç birleştirme (eşdeğer direnç $R_{eq}$) devreyi sadeleştirir ama kaynaklara dokunmaz. İleride işlenecek yıldız-üçgen (Y-Δ) dönüşümü de yalnız dirençleri bir formülle birbirine çevirir. Kaynak dönüşümü ise kaynakları da sadeleştiren bir yöntemdir.

Hoca "eşdeğer devre" kavramının ölçütünü özellikle vurguladı: karmaşık devrenin incelenen iki ucundaki akım-gerilim (v-i) karakteristiği, sadeleştirilmiş devrede de **birebir aynı** olmalıdır. Bir devreyi eşdeğer yapan şey budur.

## 2. Kaynak Dönüşümü (Source Transformation)

### 2.1 Kural

Bir gerilim kaynağına seri bağlı bir direnç varsa, bu ikili bir akım kaynağı ve ona paralel bağlı aynı dirençle gösterilebilir. Akım kaynağının değeri Ohm yasasından gelir:

$$I_s = \frac{V_s}{R}$$

Tersi de geçerlidir: bir akım kaynağına paralel bağlı direnç, $V_s = I_s R$ değerli bir gerilim kaynağı ve ona seri aynı dirence dönüştürülür. Dönüşümde yön korunur: akım kaynağının oku, gerilim kaynağının artı ucunun bulunduğu tarafı gösterir. Hoca, öğrencilerin sık yaptığı bir hatayı da düzeltti: gerilim kaynağı ve seri direnç akım kaynağına çevrildiğinde direnç akım kaynağına **seri değil, paralel** bağlanır (00:50:40).

Hoca, önceki derste yapılan güç tartışmasını da kısaca hatırlattı. Güç $P = IV = I^2R = V^2/R$ formüllerinden, kaynak direncinin değerine göre yük direncine ne kadar güç aktarılacağı değişir. Örneğin bir akım kaynağına paralel iç direnç küçültülürse akımın daha büyük kısmı o dirençten geçer ve yüke daha az güç kalır. Bu konu Bölüm 6'daki maksimum güç kuralına bağlanır.

### 2.2 Örnek: Kaynak dönüşümüyle $v_0$ (ekrandan, 00:12:20)

Devrede soldan sağa $4\ \Omega$ direnç ve ona paralel aşağı yönlü $3$ A akım kaynağı, üst kolda $2\ \Omega$, ortada $8\ \Omega$ (üzerinde $v_0$), üst kolda $3\ \Omega$ ve en sağda $12$ V gerilim kaynağı vardır. Soru, $v_0$'ın kaynak dönüşümüyle bulunmasını ister.

- $3$ A ve paralel $4\ \Omega$ → $3 \cdot 4 = 12$ V'luk gerilim kaynağı ve seri $4\ \Omega$. Yön, akım kaynağının aşağı bakmasından dolayı ters işaretlidir.
- $12$ V ve seri $3\ \Omega$ → $12/3 = 4$ A'lik (yukarı yönlü) akım kaynağı ve paralel $3\ \Omega$.
- Soldaki seri $4\ \Omega + 2\ \Omega = 6\ \Omega$ olur. $12$ V ve seri $6\ \Omega$ tekrar $12/6 = 2$ A'lik (aşağı yönlü) akım kaynağı ve paralel $6\ \Omega$'a çevrilir.
- $v_0$ istendiği için $8\ \Omega$ olduğu gibi bırakılır. $6\ \Omega \parallel 3\ \Omega = 2\ \Omega$. Akım kaynakları yönlerine göre toplanır: $4 - 2 = 2$ A yukarı yönlü.
- Sonuç devrede $8\ \Omega$, $2\ \Omega$ ve $2$ A paraleldir.

Hoca paralel dirençler için bir kestirme hatırlattı: iki direnç arasında $k$ kat fark varsa eşdeğer direnç, büyük direncin $k+1$'e bölümüdür. $6$ ile $3$ arasında $2$ kat fark olduğundan $6/3 = 2\ \Omega$.

Son adım iki yolla yapılabilir. Akım bölücüyle:

$$i = 2 \cdot \frac{2}{8 + 2} = 0{,}4\ \text{A}, \qquad v_0 = 8 \cdot 0{,}4 = 3{,}2\ \text{V}$$

Ya da paralel eşdeğer direnç bulunup ana kol akımıyla çarpılır: $8 \parallel 2 = 1{,}6\ \Omega$, $v_0 = 2 \cdot 1{,}6 = 3{,}2$ V. Paralel elemanların gerilimi aynı olduğundan iki yol aynı sonucu verir.

Ardından bir alıştırma (Örnek 13) öğrencilere bırakıldı ve bir öğrenci tahtada çözdü; çözüm Örnek Sorular bölümündedir.

## 3. Thevenin ve Norton Eşdeğer Devreleri

### 3.1 Tanım (ekrandan, 00:27:20)

Kaynak dönüşümünün sınırları vardır; örneğin bağımlı kaynak bulunan devrede doğrudan uygulanamaz. Thevenin ve Norton teoremleri buna çözüm sunar. Slaytta L. C. Thévenin'in 1883'te teoremini yayımlayan bir Fransız mühendis, E. L. Norton'un da Bell Telefon Laboratuvarları'nda çalışan bir bilim insanı olduğu yazar.

Fikir şudur: elimizde karmaşık bir devre (complex network) ve uçlarına bağlı bir yük direnci $R_L$ vardır. Yükten bir $i_L$ akımı geçer, yük üzerinde bir $v_L$ gerilimi oluşur. Bu karmaşık devre:

- bir gerilim kaynağı $V_{TH}$ ve ona seri bir direnç $R_{TH}$ ile gösterilirse **Thevenin eşdeğeri**,
- bir akım kaynağı $I_N$ ve ona paralel bir direnç $R_N$ ile gösterilirse **Norton eşdeğeri**

elde edilir. Bağlayıcı koşul, üç devrede de (orijinal, Thevenin, Norton) aynı $R_L$ üzerindeki $i_L$ ve $v_L$ değerlerinin aynı olmasıdır; yoksa eşdeğer devre denemez. Bölüm 1'deki "v-i karakteristiği birebir aynı" ölçütü bunu anlatır.

Hocanın ifadesiyle Thevenin ve Norton aslında yalnız kaynağın gerilim mi akım mı olduğunu belirten iki biçimdir. Birinden diğerine kaynak dönüşümüyle geçilir:

$$R_N = R_{TH}, \qquad I_N = \frac{V_{TH}}{R_{TH}}$$

### 3.2 Kaynak dönüşümü ile bağlantı

Hoca, önceki alıştırmayı (Örnek 13) Norton biçiminde göstermeye çalıştı: bulunan $1{,}78$ A'lik akımla bir akım kaynağı ve uygun bir paralel direnç, orijinal devrenin o kola göre eşdeğeri olur. <!-- BELİRSİZ: 00:28:04-00:29:03 arasında hoca bu Norton biçimindeki direnç değerini hesaplamadan "2 paralel 7 paralel 5" gibi bir ifade kullandı; değer derste bulunmadı. --> Bu, kaynak dönüşümünün Thevenin-Norton eşdeğerini bulmanın birinci yöntemi olduğunu gösterir.

## 4. Thevenin Eşdeğerini Bulmanın Dört Yöntemi

Hedef her yöntemde $V_{TH}$ ile $R_{TH}$'yi (Norton için $I_N$ ile $R_N$'yi) bulmaktır. Hoca dört yöntemi aynı devre üzerinde gösterdi: $12$ V kaynak, seri $3\ \Omega$, paralel $6\ \Omega$, seri $7\ \Omega$ ve uçlarda $R_L$ (ekrandan, 00:32:20 ve 00:37:20). Slaytta kaynak tarafı "Network A", yük tarafı "Network B" olarak adlandırılır.

### 4.1 Yöntem 1: Kaynak dönüşümü

$12$ V ve seri $3\ \Omega$, $12/3 = 4$ A ve paralel $3\ \Omega$ olur. $3 \parallel 6 = 2\ \Omega$. $4$ A ve paralel $2\ \Omega$ tekrar $4 \cdot 2 = 8$ V ve seri $2\ \Omega$'a çevrilir. $2\ \Omega$ ile $7\ \Omega$ seridir: $9\ \Omega$. Sonuç: $V_{TH} = 8$ V, $R_{TH} = 9\ \Omega$. Yükteki güç bundan sonra bilinen güç formülüyle hesaplanır.

### 4.2 Yöntem 2: Açık devre gerilimi ve kısa devre akımı

Yük uçları açılır ve uçlar arasındaki gerilime **açık devre gerilimi** $V_{oc}$ denir. Bu gerilim Thevenin gerilimine eşittir. Uç açık olduğundan $7\ \Omega$'dan akım geçmez; ölçülen gerilim $6\ \Omega$ üzerindeki gerilimdir. Gerilim bölücüyle:

$$V_{oc} = 12 \cdot \frac{6}{3 + 6} = 8\ \text{V} = V_{TH}$$

Sonra uçlar kısa devre edilir ve kısa devreden geçen akım $I_{sc}$ bulunur; bu akım Norton akımıdır. Kısa devre durumunda $7\ \Omega$ ile $6\ \Omega$ paraleldir ve bu paralellik $3\ \Omega$ ile seridir. Ana kol akımı:

$$I = \frac{12}{3 + \dfrac{6 \cdot 7}{6 + 7}} = \frac{12}{6{,}23} \approx 1{,}926\ \text{A}$$

Bu akımın $7\ \Omega$ koluna düşen payı akım bölücüyle:

$$I_{sc} = 1{,}926 \cdot \frac{6}{7 + 6} \approx 0{,}889\ \text{A}$$

$$R_{TH} = \frac{V_{oc}}{I_{sc}} = \frac{8}{0{,}889} = 9\ \Omega$$

> **Ders sonrası not:** Hoca akım bölücüyü önce "7 çarpı 1,92 bölü 7 artı 6" diye söyledi, ardından "6 bölü 13" diye düzeltti. Doğrusu, $7\ \Omega$ kolundaki akım için karşı koldaki direncin ($6\ \Omega$) kullanılmasıdır: $1{,}926 \cdot 6/13 \approx 0{,}889$ A. Hocanın "0,88" değeri yuvarlanmış haldir.

> **Hocanın vurgusu:** Kısa devre akımını bulurken kullanılan eşdeğer direnç (burada $3 + 6\parallel 7 \approx 6{,}23\ \Omega$) Thevenin ya da Norton direnci **değildir**. Bu yalnız $I_{sc}$'yi bulmaya yarayan bir ara değerdir. Hoca bu hatanın çok yapıldığını söyledi.

Kontrol olarak: Thevenin devresinde uçlar kısa devre edilirse $8/9 \approx 0{,}889$ A akar; bu, orijinal devredeki $I_{sc}$ ile aynıdır.

### 4.3 Yöntem 3: Bağımsız kaynakları söndürme

$V_{TH}$ yine açık devre gerilimidir ($8$ V). $R_{TH}$ için bağımsız **gerilim kaynakları kısa devre**, bağımsız **akım kaynakları açık devre** yapılır ve devreye her zaman açık uç (yük) tarafından bakılır. Burada $12$ V kısa devre edilince $3\ \Omega$ ile $6\ \Omega$ paralel olur, $7\ \Omega$ bunlara seridir:

$$R_{TH} = 7 + (6 \parallel 3) = 7 + 2 = 9\ \Omega$$

Hoca, yöntem 1, 2 ve 3'ün devrede **bağımlı kaynak yokken** uygulanabileceğini söyledi.

### 4.4 Yöntem 4: Test kaynağı

Bağımlı kaynak varsa dördüncü yöntem kullanılır. $V_{oc}$ yine açık uçtan bulunur. $R_{TH}$ için bağımsız gerilim kaynakları kısa devre edilir ve yük uçlarına bir test kaynağı bağlanır: Thevenin için $1$ V'luk test gerilimi, Norton için $1$ A'lik test akımı. Test kaynağının ürettiği akım (ya da test akımının oluşturduğu gerilim) bulunur ve

$$R_{TH} = \frac{v_{test}}{i_{test}}$$

hesaplanır. Mantığı şudur: kutunun içindeki devre bir gerilim kaynağına bağlanınca bir akım çeker; gerilim akıma bölünürse kutunun eşdeğer direnci elde edilir. Aynı devrede $1$ V test gerilimiyle de $9\ \Omega$ bulunur.

## 5. Bağımlı Kaynaklı Devrelerde Thevenin Eşdeğeri

### 5.1 Süperpozisyonla $V_{oc}$ (ekrandan, 00:42:20)

Bu örnekte bağımlı kaynak yoktur ama iki bağımsız kaynak vardır: $4$ V gerilim kaynağı, $2\ \text{k}\Omega$, $2$ mA akım kaynağı, $3\ \text{k}\Omega$ ve uçlarda $1\ \text{k}\Omega$'luk yük. Soru, $1\ \text{k}\Omega$'luk direncin gördüğü Thevenin ve Norton eşdeğerlerini ister.

$R_{TH}$ için yöntem 3 en pratiğidir: $4$ V kısa devre, $2$ mA açık devre edilir; geriye seri $2\ \text{k}\Omega$ ve $3\ \text{k}\Omega$ kalır: $R_{TH} = 5\ \text{k}\Omega$.

$V_{oc}$ için yük açılır ve iki kaynak olduğundan süperpozisyon uygulanır (gerilim kaynağı kısa, akım kaynağı açık devre edilerek her kaynak ayrı ayrı):

- Yalnız $4$ V: $2$ mA açık devre olunca dirençlerden akım geçmez, $V_{oc|4V} = 4$ V.
- Yalnız $2$ mA: $4$ V kısa devre edilince akım $2\ \text{k}\Omega$ üzerinden döner, $V_{oc|2mA} = 0{,}002 \cdot 2000 = 4$ V.
- Toplam: $V_{oc} = 4 + 4 = 8$ V.

Thevenin eşdeğeri $8$ V ve seri $5\ \text{k}\Omega$'dur; $1\ \text{k}\Omega$'luk yükten geçen akım iki devrede aynıdır. Norton eşdeğeri için kaynak dönüşümü yeterlidir: $I_N = 8/5000 = 1{,}6$ mA, $R_N = 5\ \text{k}\Omega$ (ara adım eklendi).

Ardından bir alıştırma (Örnek 19) öğrencilere bırakıldı; çözüm Örnek Sorular bölümündedir.

### 5.2 Bağımlı akım kaynaklı devre: $V_{oc}/I_{sc}$ (ekrandan, 00:57:20)

Devrede $4$ V kaynak, $2\ \text{k}\Omega$, değeri $v_x/4000$ olan bağımlı akım kaynağı (yukarı yönlü) ve $3\ \text{k}\Omega$ vardır; açık uçlardaki gerilim $v_x$'tir. Uçlar açık olduğundan $v_x = V_{oc}$'dir ve $3\ \text{k}\Omega$'dan akım geçmez. Bu yüzden bağımlı kaynağın akımı $2\ \text{k}\Omega$ üzerinden akmak zorundadır. KVL (ekrandan):

$$-4 + 2 \times 10^3\left(-\frac{v_x}{4000}\right) + 3 \times 10^3 (0) + v_x = 0 \;\Rightarrow\; v_x = 8\ \text{V} = V_{oc}$$

$R_{TH}$ söndürme yöntemiyle bulunamaz, çünkü bağımlı kaynak devreden atılamaz: bağımsız gerilim kaynağı kısa, akım kaynağı açık devre edilebilir ama bağımlı kaynağa böyle bir şey yapılamaz. Bu yüzden $I_{sc}$ aranır. Uçlar kısa devre edilince $v_x = 0$ olur ve bağımlı kaynak etkisizleşir; devre $4$ V ve seri $5\ \text{k}\Omega$'a döner:

$$I_{sc} = \frac{4}{5 \times 10^3} = 0{,}8\ \text{mA}, \qquad R_{TH} = \frac{V_{oc}}{I_{sc}} = \frac{8}{0{,}8 \times 10^{-3}} = 10\ \text{k}\Omega$$

Hoca, bağımlı kaynak yok sayılıp söndürme yöntemi uygulansaydı yanlış olarak $5\ \text{k}\Omega$ bulunacağını gösterdi. Test kaynağı da kullanılabilirdi, ama $v_x/4000$ ifadesi yüzünden işlem daha karışık olurdu. Kısa devre burada işe yarar, çünkü bir değişkeni ($v_x$) ortadan kaldırır.

> **Hocanın vurgusu:** Bağımlı kaynaklı devrede önce "bağımlı kaynağı nasıl etkisiz kılabilirim?" diye düşünülmelidir. Kısa devre bağımlı kaynağı etkisiz kılıyorsa $V_{oc}/I_{sc}$, kılmıyorsa test kaynağı kullanılır.

### 5.3 Bağımlı gerilim kaynaklı devre: test kaynağı (ekrandan, 01:02:20)

Devrede değeri $1{,}5i$ olan bağımlı gerilim kaynağı, seri $3\ \Omega$ ve uçlara paralel $2\ \Omega$ vardır; $i$, sağdaki uçlara doğru akan akımdır. Uçlar açık olduğundan $i = 0$, bağımlı kaynak etkisizdir ve $2\ \Omega$ üzerinde gerilim oluşmaz: $V_{oc} = 0$.

Kısa devre burada işe yaramaz: uçları kısa devre etmek $2\ \Omega$'u devreden çıkarır ama $i$ bilinmeyeni yine kalır. Bu yüzden uçlara $1$ A'lik bir test akım kaynağı bağlanır (bağımlılık akıma göre olduğu için akım kaynağı seçilir). Test kaynağının akımı uçlara doğru tanımlanan $i$'nin tersi yönünde olduğundan $i = -1$ A olur ve bağımlı kaynak $1{,}5 \cdot (-1) = -1{,}5$ V'a dönüşür. Üst düğümde ($v_{test}$) KCL:

$$\frac{v_{test} - (-1{,}5)}{3} + \frac{v_{test}}{2} = 1 \;\Rightarrow\; \frac{5}{6}\,v_{test} = 0{,}5 \;\Rightarrow\; v_{test} = 0{,}6\ \text{V}$$

$$R_{TH} = \frac{v_{test}}{1\ \text{A}} = 0{,}6\ \Omega$$

Bu devrenin Thevenin eşdeğeri yalnız bir dirençtir; içinde gerilim oluşturacak bağımsız kaynak yoktur.

> **Ders sonrası not:** Hoca bir yerde "1 amperi $i$'ye böldüğünde $R_{TH}$ gelecek" dedi. Doğrusu, test geriliminin test akımına bölünmesidir: $R_{TH} = v_{test}/1\ \text{A}$. Hoca hesapta da bunu yaptı ve $0{,}6$ buldu. Sonra eşdeğeri "altı ohmluk bir direnç" diye andı; altyazıdaki bu ifade büyük olasılıkla $0{,}6\ \Omega$'un yanlış duyulmuş halidir.

## 6. Maksimum Güç Aktarımı

Yük direnci üzerindeki güç, kaynak tarafının iç direnci $R_S$ ile yük direnci $R_L$'ye bağlı olarak değişir. Hocanın verdiği kural şudur: yük üzerindeki gücün en büyük olması için $R_L$, karmaşık devrenin Thevenin direncine eşit seçilmelidir:

$$R_L = R_{TH}$$

Soru tipik olarak şöyle gelir: karmaşık bir devrenin ucuna $R_L$ bağlanmıştır; $R_L$ üzerinde maksimum güç nasıl elde edilir? Önce karmaşık devre analiz edilip Thevenin direnci çıkarılır, yani devre tek bir dirençle gösterilir. Bu değer $R_L$'ye eşitlenirse yükte maksimum güç toplanır. Hoca dersin başında bu durumu "üreteç gücünün yüzde ellisinin yükte toplanması" diye de andı.

> **Hocanın vurgusu:** Bu kaide unutulmamalıdır: maksimum güç için $R_L = R_{TH}$.

> **Ek bilgi (derste anlatılmadı):** $R_L = R_{TH}$ iken yükün gerilimi $V_{TH}/2$ olur. Bu yüzden yükteki maksimum güç $P_{max} = \dfrac{(V_{TH}/2)^2}{R_L} = \dfrac{V_{TH}^2}{4R_{TH}}$'dir. Bu durumda Thevenin kaynağının verdiği gücün yarısı yükte, yarısı $R_{TH}$ üzerinde harcanır.

Dersin son Thevenin sorusu (Örnek 25) bu konudadır ve Örnek Sorular bölümünde çözülmüştür.

## 7. Kondansatör (Kapasitör)

### 7.1 Enerji depolayan elemanlar

Bu hafta yeni bir konuya, enerji depolayan devre elemanlarına geçildi. Direnç de üzerinde enerji harcar (ısınma gibi), ama bunu depolayıp sonra devreyi tekrar besleyecek bir işlevi yoktur. Kondansatör (kapasitör) ve bobin (indüktör) ise enerjiyi depolar ve sonra devrede kullanılmasını sağlar. Hoca enerjinin iki bileşeni olan gerilim ve akımı hatırlattı: kondansatör gerilim tabanlı, bobin akım tabanlı depolama yapar.

> **Hocanın vurgusu:** Gerilim kondansatörde, akım bobinde depolanır. Bu ayrım unutulmamalıdır.

Bu derste çok matematiğe girmeden iç yapılar, kondansatörde gerilim ve bobinde akım ilişkisi ile seri ve paralel bağlantılar incelendi.

### 7.2 Yapı ve kapasitans

Kondansatör, içinde elektriği iletmeyen bir yalıtkan (dielektrik, insulator) malzeme bulunan bir devre elemanıdır. Dielektriğin iki yanında levhalar (plate) vardır ve yükler bu levhalarda birikir. Kondansatörün yük depolama parametresi $C$ ile gösterilir; birimi faraddır, depoladığı yük coulomb cinsindendir. Kapasitans:

- levha alanıyla doğru orantılıdır (alan büyüdükçe depolanan enerji artar),
- levhalar arası uzaklıkla ters orantılıdır,
- dielektrik malzemenin sabitiyle doğru orantılıdır (her malzemenin kendine özgü bir sabiti vardır).

> **Ek bilgi (derste anlatılmadı):** Paralel levhalı kondansatör için bu orantılar $C = \varepsilon A / d$ formülüyle yazılır; $\varepsilon$ dielektriğin geçirgenliği, $A$ levha alanı, $d$ levhalar arası uzaklıktır.

### 7.3 Kondansatör türleri (ekrandan, 01:32:20)

- **Kutupsuz (nonpolarized):** Herhangi bir ucu devrenin yüksek gerilimli tarafına bağlanabilir. Yalıtkanı kağıt, mika, seramik ya da polimerdir. Genelde çok küçük değerlidir (pikofarad mertebesi). Hoca bu kondansatörlerin üzerindeki kodun okunuşunu da anlattı: ilk iki rakam değeri, üçüncü rakam 10'un üssünü verir ve değer pikofarad cinsindendir; harf (örneğin K) toleransı gösterir (K için $\pm\%10$). Örneğin üçüncü rakam 2 ise $10 \cdot 10^2 = 1000$ pF olur. <!-- BELİRSİZ: Hocanın okuduğu kodun tamamı karede görülmedi; "10 çarpı 100 = 1000" anlatımından kodun büyük olasılıkla 102K olduğu çıkarıldı. -->
- **Elektrolitik (kutuplu):** Negatif uç her zaman pozitif uçtan daha düşük gerilimde olmalıdır. Levhalar alüminyum ya da tantaldandır. Bacaklardan biri uzun, biri kısadır. Daha büyük boyutludur, çünkü içinde sarılmış katmanlı bir yapı vardır; genelde tüp biçimindedir, kutupsuzlar ise mercimek biçimindedir.
- **Ayarlı kondansatörler:** Levhaları hareketli olduğundan kapasitansı değiştirilebilir.
- **MEMS (Micro Electromechanical System) kondansatörler:** RF elektroniğinde kullanılan, güncel bir çalışma alanıdır; malzeme, alttaş ve katkılar değiştirilerek kapasitans ayarlanır.
- **Çift katmanlı (süper ya da ultra) kapasitörler:** Güneş enerjisi gibi alternatif enerji sistemlerinde enerji depolamak ve elektrikli araçların batarya modülleri gibi uygulamalarda kullanılan, yeni gelişen bir teknolojidir.

> **Ders sonrası not:** Hoca elektrolitik kondansatörde "uzun bacak eksiyi, kısa bacak artıyı gösterir" dedi. Doğrusu büyük olasılıkla tersidir: elektrolitik kondansatörlerde yaygın gösterimde uzun bacak artı (anot), kısa bacak eksi (katot) uçtur. Artı uç beslemenin yüksek potansiyelli tarafına, eksi uç düşük potansiyelli tarafına bağlanır; slayttaki "negatif uç her zaman daha düşük gerilimde olmalı" kuralı da bunu söyler.

Hoca, fiziksel laboratuvarda malzeme alınsaydı bu kodları okumanın faydalı olacağını, şu an simülasyon kullanıldığını belirtti. PSpice'ta kutupsuz kondansatörün sembolü de gösterildi.

### 7.4 Elektriksel özellikler

- **Kalıcı durum (steady state):** Kondansatör şarj olup doyduktan sonra (şarj anı değil, sonrası) DC altında **açık devre** gibi davranır; artık şarj almaz.
- **Süreklilik:** Slayta göre kondansatör üzerindeki gerilim sürekli bir fonksiyon olmak zorundadır; akım ise süreksiz olabilir (ekrandan, 01:52:20).
- **İdeal ve gerçek kondansatör:** İdeal kondansatör enerji harcamaz. Gerçekte bir kayıp vardır; bu, kondansatörün yanına bir direnç eklenerek modellenir. Teoride göz ardı edilir.

> **Ders sonrası not:** Hoca süreklilik kuralını "kondansatörü şarj etmek için girişteki gerilim sabit ve kesintisiz olmalı, gerilim kesilirse şarj durur" diye yorumladı. Slayttaki kuralın anlamı büyük olasılıkla şudur: kondansatörün gerilimi bir anda sıçrayamaz ($i_C = C\,dv_C/dt$ olduğundan anlık gerilim sıçraması sonsuz akım gerektirir), akım ise bir anda değişebilir.

Gerilim kaynağı bağlanınca levhalara pozitif ve negatif yükler dolar ve aralarında bir elektrik alanı oluşur; depolanan enerji bu alanla ilgilidir.

### 7.5 Şarj ve deşarj davranışı

Boş bir kondansatöre gerilim uygulanınca şarj ilk anda hızlı ve kolay başlar. Levhalardaki yük arttıkça kondansatörün gerilimi besleme gerilimine yaklaşır, aradaki potansiyel farkı azalır ve şarj yavaşlar; sonunda doyuma ulaşır. Deşarj da benzerdir: önce hızlı bir düşüş olur, içerideki yük azaldıkça deşarj yavaşlar. Slaytta bir DC kaynak, bir direnç ve kondansatörden oluşan devrede şarj ve deşarj eğrileri gösterildi.

### 7.6 Akım-gerilim ilişkisi (ekrandan, 01:42:20)

Akım, yükün zamana göre değişimidir; bu tel için de kondansatör için de geçerlidir. Kondansatördeki yük, kapasitansla uygulanan gerilimin çarpımıdır:

$$i_C = \frac{dq}{dt}, \qquad q = C\,v_C \;\Rightarrow\; i_C = C\,\frac{dv_C}{dt}$$

Gerilim, bu ifadenin integrali alınarak bulunur (akımın altındaki alan):

$$v_C = \frac{1}{C}\int_{t_0}^{t_1} i_C\,dt$$

Güç $p = v\,i$ formülüne $i_C$ yazılarak bulunur. Slaytta enerji formülü de gösterildi.

> **Ek bilgi (derste anlatılmadı):** $p = v_C\,i_C = C\,v_C\,\dfrac{dv_C}{dt}$ ifadesinin integrali kondansatörde depolanan enerjiyi verir: $w = \tfrac{1}{2}C v_C^2$. Bobinde karşılığı $w = \tfrac{1}{2}L i_L^2$'dir.

### 7.7 Zaman sabiti ve şarj-deşarj formülleri (ekrandan, 01:47:20)

Slayta göre yükün levhalara eklenme ya da levhalardan çekilme hızı zamanın üstel bir fonksiyonuyla ifade edilir:

$$\text{Şarj: } v(t) = V_C\left(1 - e^{-t/\tau}\right), \qquad \text{Deşarj: } v(t) = V_C\,e^{-t/\tau}, \qquad \tau = RC$$

$\tau$ (tau) zaman sabitidir ve devredeki eşdeğer direnç ile eşdeğer kapasitansın çarpımıdır. Zaman ölçeğini belirleyen parametredir.

> **Hocanın vurgusu:** Bu iki formül kesinlikle bilinmelidir. Hoca ezber yerine sınır değerleriyle ayırt etmeyi önerdi.

- Şarjda $t \to \infty$ iken $e^{-t/\tau} \to 0$ ve $v \to V_C$: kondansatör en fazla besleme gerilimine şarj olur. Pratikte $t$ sonsuza gitmediğinden gerilim $V_C$'nin çok az altında kalır.
- Deşarjda $t = 0$ anında $e^{0} = 1$ ve $v = V_C$: deşarj tam dolu kondansatörle başlar.

### 7.8 Seri ve paralel kondansatörler

$\tau = RC$ formülünde birden fazla kondansatör varsa eşdeğer kapasitans, birden fazla direnç varsa eşdeğer direnç kullanılır.

**Paralel bağlantı:** Kondansatörler dirençlerin tersine **doğrudan toplanır**:

$$C_{eq} = C_1 + C_2 + C_3 + C_4$$

Gerekçesi düğüm analizidir: ana kol akımı kollardaki akımların toplamıdır, $i = i_1 + i_2 + i_3 + i_4$. Her kolun gerilimi aynı ($v$) olduğundan $i = C_1\dfrac{dv}{dt} + C_2\dfrac{dv}{dt} + \dots = (C_1 + C_2 + \dots)\dfrac{dv}{dt}$ olur.

**Seri bağlantı:** KVL'ye göre kondansatörlerdeki gerilimlerin toplamı giriş gerilimine eşittir. Hepsinden aynı akım geçtiğinden ortak terim dışarı alınır ve

$$\frac{1}{C_{eq}} = \frac{1}{C_1} + \frac{1}{C_2} + \frac{1}{C_3} + \frac{1}{C_4}$$

bulunur. Bu da seri dirençlerin tersidir. Hoca paralel bağlantının ispatına bir sonraki sunumda tekrar değinileceğini söyledi.

### 7.9 Özet slaytı (ekrandan, 01:52:20)

- Kondansatörler enerji depolayan elemanlardır.
- İdeal kondansatör, en az $5\tau$ süre DC gerilim ya da akım uygulandıktan sonra açık devre gibi davranır ($\tau = RC$).
- Kondansatör gerilimi sürekli olmalıdır; akımı süreksiz olabilir.
- Paralelde $C_{eq} = \sum C_p$, seride $C_{eq} = \left[\sum 1/C_s\right]^{-1}$.

## 8. Bobin (İndüktör)

### 8.1 Yapı ve çalışma

Bobin de enerji depolar, ama farkı enerjiyi akımın oluşturduğu **manyetik alanda** depolamasıdır. Fiziksel olarak kalın bir iletken telin sarılmasıyla yapılır; ortasında bir çekirdek malzeme bulunur. Amaç bir manyetik alan oluşturmak ve böylece giriş kesilse bile akımın bir süre devam etmesini sağlamaktır. Devre şemalarında farklı sembollerle gösterilir.

Akım bobini beslediğinde, dirençte olduğu gibi bir kutuplanma (polarizasyon) oluşur. İletim kesildiğinde bobin depoladığı enerjiyi ters işaretli bir şekilde boşaltır. Bobinin kondansatör gibi sabit bir kutbu yoktur.

> **Hocanın vurgusu:** Bobin için akımın sürekli olması şarttır; bu, kondansatördeki gerilim sürekliliğinin karşılığıdır. Bobinde gerilim kesintiye uğrayabilir.

### 8.2 Akım-gerilim ilişkisi

Bobinin değerinin birimi henry'dir (kondansatördeki faradın karşılığı). Bobin gerilimi, akımın zamana göre değişimiyle orantılıdır; akım da gerilimin integralinden bulunur:

$$v_L = L\,\frac{di_L}{dt}, \qquad i_L = \frac{1}{L}\int v_L\,dt$$

Hoca bu formüllerin kondansatördekilerle ikili (dual) olduğunu vurguladı: kondansatörde $i_C = C\,dv_C/dt$ ve $v_C = \frac{1}{C}\int i_C\,dt$, bobinde rolleri gerilim ve akım değiştirir. Güç yine $p = v\,i$ formülünden bulunur.

> **Ders sonrası not:** Hoca özetlerken "bobinde akım integral ile, kondansatörde akım türev ile, kondansatörde gerilim integral ile, bobinde gerilim akım integral ile" dedi. Son kısım hatalıdır: bobinde gerilim, akımın **türevi** ile ilişkilidir ($v_L = L\,di_L/dt$).

### 8.3 Sağ el kuralı ve telin endüktansı (ekrandan, 01:57:20)

Slayta göre sağ el kuralında başparmak akımın yönünü, kıvrılan parmaklar manyetik alanın yönünü gösterir. Hoca bu kuralın çok bilinmesi gerekmediğini söyledi. Slayt, çıplak bir telin bile endüktansı olduğunu belirtir:

$$L = \ell\left[\ln\left(4\frac{\ell}{d}\right) - 1\right]\left(2 \times 10^{-7}\right)\ \text{H}$$

Burada $d$, telin metre cinsinden çapıdır. Hoca bu formülün ayrıntısına girmedi.

> **Ders sonrası not:** Hoca "parmağımızın yönü akımın yönünü gösterir" dedi; slayta göre akımın yönünü **başparmak**, manyetik alanın yönünü kıvrılan parmaklar gösterir.

### 8.4 Gerçek bobin ve bağlantılar

Gerçek bobinde de enerji kaybı vardır; teoride göz ardı edilir. Gerçek durumu modellemek için bobine seri bir direnç bağlanır. Seri bağlı direnç akımı değiştirmez ama gerilimi bölerek gücü değiştirir.

Bobinler dirençler gibi işlem görür:

$$\text{Seri: } L_{eq} = L_1 + L_2 + L_3 + L_4, \qquad \text{Paralel: } \frac{1}{L_{eq}} = \frac{1}{L_1} + \frac{1}{L_2} + \dots$$

Gerekçe: seri bobinlerde gerilimler toplanır ve her bobinin gerilimi $L_k\,di/dt$ olduğundan ortak $di/dt$ dışarı alınır. Kondansatörde ise gerilim ifadesinde $1/C$ bulunduğu için kurallar tersine döner. Bobinin şarj ve deşarjına ilerleyen derslerde değinilecektir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:12:20)

Kaynak dönüşümüyle devredeki $v_0$'ı bulun. Devre: $4\ \Omega$ ve paralel aşağı yönlü $3$ A, üst kolda $2\ \Omega$, ortada $8\ \Omega$ ($v_0$), üst kolda $3\ \Omega$, sağda $12$ V.

**Çözüm (derste verildi):** Bölüm 2.2'deki adımlarla devre $8\ \Omega$, $2\ \Omega$ ve yukarı yönlü $2$ A'lik paralel devreye indirilir. $i = 2 \cdot 2/(8+2) = 0{,}4$ A, $v_0 = 8 \cdot 0{,}4 = 3{,}2$ V.

### Soru 2 (ekrandan, 00:17:20)

Kaynak dönüşümüyle devredeki $i_0$'ı bulun. Devre soldan sağa: $6\ \Omega$, yukarı yönlü $5$ A, $3\ \Omega$ (hepsi paralel); üst kolda soldan sağa $-$/$+$ yönlü $5$ V; ortada $7\ \Omega$ (aşağı yönlü $i_0$); yukarı yönlü $3$ A; üst kolda $1\ \Omega$ ve en sağda $4\ \Omega$. Slayttaki cevap: $1{,}78$ A.

**Çözüm (derste bir öğrenci çözdü, 00:20:52-00:24:02):**

- $6\ \Omega \parallel 3\ \Omega = 2\ \Omega$. $5$ A ve paralel $2\ \Omega$ → $10$ V ve seri $2\ \Omega$.
- $1\ \Omega$ ve $4\ \Omega$ seri ($5\ \Omega$); $3$ A ve paralel $5\ \Omega$ → $15$ V ve seri $5\ \Omega$ (ekrandan, 00:22:20).
- İki çevreli devre kalır: sol çevrede $10$ V, $2\ \Omega$, $5$ V ve ortak $7\ \Omega$; sağ çevrede ortak $7\ \Omega$, $5\ \Omega$ ve $15$ V.
- Sol çevre: $-10 + 2i_1 - 5 + 7(i_1 - i_2) = 0 \Rightarrow 9i_1 - 7i_2 = 15$
- Sağ çevre: $7(i_2 - i_1) + 5i_2 + 15 = 0 \Rightarrow -7i_1 + 12i_2 = -15$
- Çözüm: $i_1 \approx 1{,}271$ A, $i_2 \approx -0{,}508$ A.
- $i_0 = i_1 - i_2 \approx 1{,}271 + 0{,}508 \approx 1{,}78$ A. Sonuç slayttaki cevapla ve python denetimiyle uyuşur.

### Soru 3 (ekrandan, 00:32:20 ve 00:37:20)

Network A'nın Thevenin eşdeğerini (a) açık devre gerilimi ve kısa devre akımıyla, (b) bağımsız kaynakları söndürerek bulun. Devre: $12$ V, seri $3\ \Omega$, paralel $6\ \Omega$, seri $7\ \Omega$.

**Çözüm (derste verildi):** $V_{oc} = 12 \cdot 6/9 = 8$ V. (a) $I_{sc} \approx 0{,}889$ A, $R_{TH} = 8/0{,}889 = 9\ \Omega$. (b) $R_{TH} = 7 + 6\parallel 3 = 9\ \Omega$. Ayrıntılar Bölüm 4'tedir.

### Soru 4 (ekrandan, 00:42:20)

$1\ \text{k}\Omega$'luk direncin gördüğü devrenin Thevenin ve Norton eşdeğerlerini bulun. Devre: $4$ V, $2\ \text{k}\Omega$, yukarı yönlü $2$ mA, $3\ \text{k}\Omega$, uçlarda $1\ \text{k}\Omega$.

**Çözüm (derste verildi):** $R_{TH} = 2 + 3 = 5\ \text{k}\Omega$. Süperpozisyonla $V_{oc} = 4 + 0{,}002 \cdot 2000 = 8$ V. Norton: $I_N = 8/5000 = 1{,}6$ mA, $R_N = 5\ \text{k}\Omega$ (Norton değerleri derste yalnız sözlü olarak "kaynak dönüşümüyle bulunur" diye geçti; ara adım eklendi).

### Soru 5 (ekrandan, 00:47:20)

Devrenin Thevenin ve Norton eşdeğerlerini bulun. Devre: $3$ V kaynak, seri $2\ \text{k}\Omega$, aşağı yönlü $7$ mA akım kaynağı, paralel $5\ \text{k}\Omega$, uçlara seri $1\ \text{k}\Omega$; alt hat topraklı. Slayttaki cevap: $-7{,}857$ V, $-3{,}235$ mA, $2{,}429\ \text{k}\Omega$.

**Çözüm (derste bir öğrenci hocanın yardımıyla çözdü, 00:50:09-00:55:04):**

- $3$ V ve seri $2\ \text{k}\Omega$ → $3/2 = 1{,}5$ mA (yukarı yönlü) ve paralel $2\ \text{k}\Omega$ (ekrandan, 00:52:20). Hoca burada direncin akım kaynağına paralel bağlanması gerektiğini vurguladı.
- Akım kaynakları birleşir: $7 - 1{,}5 = 5{,}5$ mA aşağı yönlü.
- $2\ \text{k}\Omega \parallel 5\ \text{k}\Omega = 10/7 \approx 1{,}43\ \text{k}\Omega$.
- Açık uçta $1\ \text{k}\Omega$'dan akım geçmez; $V_{oc}$, $1{,}43\ \text{k}\Omega$ üzerindeki gerilimdir. Akım aşağı yönlü olduğundan, üst ucu artı kabul edilen $V_{oc}$ negatif çıkar: $V_{oc} = -5{,}5 \cdot 1{,}4286 \approx -7{,}857$ V $= V_{TH}$.
- $R_{TH}$: gerilim kaynağı kısa, akım kaynağı açık devre; $2 \parallel 5 = 1{,}4286$, buna seri $1$: $R_{TH} \approx 2{,}429\ \text{k}\Omega$.
- Norton: $I_N = V_{TH}/R_{TH} = -7{,}857/2{,}429 \approx -3{,}235$ mA, $R_N = 2{,}429\ \text{k}\Omega$.

> **Ders sonrası not:** Çözüm sırasında $2\ \text{k}\Omega$ ile $5\ \text{k}\Omega$'un birleşimi önce "seri", hocanın özetinde de "5 ile 7'nin paralelliği" diye söylendi. Doğrusu $2\ \text{k}\Omega \parallel 5\ \text{k}\Omega = 10/7\ \text{k}\Omega$'dur; hesapta da bu değer kullanıldı.

### Soru 6 (ekrandan, 00:57:20)

Açık uçlardaki Thevenin eşdeğerini bulun. Devre: $4$ V, $2\ \text{k}\Omega$, yukarı yönlü $v_x/4000$ bağımlı akım kaynağı, $3\ \text{k}\Omega$; uçlarda $v_x$.

**Çözüm (derste verildi):** $-4 + 2000(-v_x/4000) + v_x = 0 \Rightarrow V_{oc} = v_x = 8$ V. Kısa devrede $v_x = 0$, bağımlı kaynak etkisiz, $I_{sc} = 4/5000 = 0{,}8$ mA. $R_{TH} = 8/0{,}8\ \text{mA} = 10\ \text{k}\Omega$.

### Soru 7 (ekrandan, 01:02:20)

Devrenin Thevenin eşdeğerini bulun. Devre: $1{,}5i$ bağımlı gerilim kaynağı, seri $3\ \Omega$, paralel $2\ \Omega$; $i$ sağdaki açık uçlara doğru akan akım.

**Çözüm (derste verildi):** $i = 0$ olduğundan $V_{oc} = 0$. $1$ A test akımıyla $i = -1$ A, düğüm denklemi $(v_{test} + 1{,}5)/3 + v_{test}/2 = 1$, $v_{test} = 0{,}6$ V, $R_{TH} = 0{,}6\ \Omega$.

### Soru 8 (ekrandan, 01:07:20)

Süperpozisyonla devredeki $i_0$'ı bulun. Devre: solda yukarı yönlü $4$ A; üst hatta $2\ \Omega$; orta kolda üstte $3\ \Omega$, altta $5\ \Omega$ ($i_0$ aşağı yönlü, $3\ \Omega$ ile $5\ \Omega$ arasındaki düğümden aşağı); bu düğümden sağa $1\ \Omega$ ve $+$/$-$ yönlü $5i_0$ bağımlı gerilim kaynağı; sağ kolda $4\ \Omega$; alt hatta $+$/$-$ yönlü $20$ V. Hoca bu soruyu Örnek 24 ve 25 ile birlikte öğrencilerin çözmesi için verdi.

> **Çözüm (derste verilmedi):** Ajan tarafından düğüm analiziyle çözüldü ve python ile denetlendi (süperpozisyon yerine doğrudan çözüm; süperpozisyonla bulunacak $i_0'$ ve $i_0''$ toplamı aynı sonucu vermelidir). Sol alt düğüm referans alınırsa $20$ V kaynağından sağ alt düğüm $-20$ V'tur. Sol üst düğüm $V_A$, orta düğüm $V_M$, sağ düğüm $V_B$ olsun; bağımlı kaynağın sol ucu $V_B + 5i_0$, $i_0 = V_M/5$'tir. Denklemler: $(V_A - V_M)/3 + (V_A - V_B)/2 = 4$; $(V_M - V_A)/3 + V_M/5 + (V_M - V_B - 5i_0)/1 = 0$; $1\ \Omega$'dan gelen akım $= (V_B - V_A)/2 + (V_B + 20)/4$. Çözüm: $V_A \approx 2{,}588$ V, $V_M \approx -2{,}353$ V, $V_B \approx -2{,}118$ V; $i_0 = V_M/5 \approx -0{,}4706$ A.

### Soru 9 (ekrandan, 01:22:20)

Devrede maksimum güç aktarımı için $R_L$ değerini ve maksimum gücü bulun. Devre: $12$ V, seri $6\ \Omega$, paralel $12\ \Omega$, seri $3\ \Omega$, yukarı yönlü $2$ A akım kaynağı, seri $2\ \Omega$, $a$-$b$ uçlarında $R_L$.

**Çözüm (derste kısmen verildi):** Bağımlı kaynak olmadığından $12$ V kısa, $2$ A açık devre edilir. $6 \parallel 12 = 4\ \Omega$, seri $3$ ve $2$ ile $R_{TH} = 4 + 3 + 2 = 9\ \Omega$. Maksimum güç için $R_L = 9\ \Omega$. Hoca $V_{TH}$ için çevre analizi kurmaya başladı; $2$ A'lik akım kaynağının bulunduğu çevrede çevre akımının akım kaynağıyla belirlendiğini ($i_2 = -2$ A) söyledi, ama hesabı tamamlamadı.

> **Çözüm (derste verilmedi):** $V_{TH}$ ajan tarafından düğüm analiziyle bulundu ve python ile denetlendi. Uçlar açıkken $2\ \Omega$'dan akım geçmez, $V_{TH}$ akım kaynağının üst düğüm gerilimidir ($V_2$). $6\ \Omega$ ile $12\ \Omega$ arasındaki düğüm $V_1$ olsun: $(V_1 - 12)/6 + V_1/12 + (V_1 - V_2)/3 = 0$ ve $(V_2 - V_1)/3 = 2$. Çözüm: $V_1 = 16$ V, $V_2 = 22$ V, yani $V_{TH} = 22$ V. Maksimum güç: $P_{max} = V_{TH}^2/(4R_{TH}) = 22^2/36 \approx 13{,}44$ W.

> **Ders sonrası not:** Hoca maksimum gücün "$V^2/R$'den" bulunacağını söyledi. $V_{TH}^2/R_L$ yazılırsa sonuç dört kat büyük çıkar; $R_L = R_{TH}$ iken yükün gerilimi $V_{TH}/2$ olduğundan doğru formül $P_{max} = (V_{TH}/2)^2/R_L = V_{TH}^2/(4R_{TH})$'dir.

## Dersin Toparlaması

Bu derste devreleri sadeleştirme araçları tamamlandı. Kaynak dönüşümü, gerilim kaynağı ve seri direnç ile akım kaynağı ve paralel direnç arasında geçiş yapmayı sağlar ve Thevenin-Norton eşdeğerini bulmanın ilk yoludur. Thevenin ve Norton teoremleri, iki uçlu her doğrusal devrenin tek bir kaynak ve tek bir dirençle gösterilebileceğini söyler. $V_{TH}$ açık devre gerilimidir; $R_{TH}$ ise bağımlı kaynak yoksa kaynaklar söndürülerek, bağımlı kaynak varsa $V_{oc}/I_{sc}$ oranıyla ya da bir test kaynağıyla bulunur. Kısa devre akımını bulurken kullanılan ara eşdeğer direnç Thevenin direnci değildir. Maksimum güç aktarımı için yük direnci Thevenin direncine eşit seçilir.

Dersin ikinci yarısında enerji depolayan elemanlara giriş yapıldı. Kondansatör enerjiyi elektrik alanında depolar ($i_C = C\,dv_C/dt$); şarj ve deşarjı $\tau = RC$ zaman sabitli üstel fonksiyonlarla verilir ve $5\tau$ sonra DC altında açık devre gibi davranır. Bobin enerjiyi manyetik alanda depolar ($v_L = L\,di_L/dt$). Paralel kondansatörler toplanırken seri bobinler toplanır. Hoca kondansatör ve bobinle ilgili matematiksel soruların ve bobinin şarj-deşarjının ilerleyen derslerde işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
