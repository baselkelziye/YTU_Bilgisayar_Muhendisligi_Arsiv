# Ders 8 Genişletilmiş Notu: Ayrık Konvolüsyonda Sıfır Noktası, Fourier Serisi Örnekleri, Gibbs Olayı ve Fourier Dönüşümüne Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ayrık Konvolüsyonda Sıfır Noktası
- 2. Temel Frekans ve Periyodiklik: Önceki Dersin Düzeltmesi
- 3. Fourier Analizinin Uygulamaları: Ses, Nota ve Spektrogram
- 4. Fourier Serisi Katsayılarının Hatırlatması
- 5. Kare Dalga Örneği: Analiz
- 6. Kare Dalga Örneği: Sentez ve MATLAB Denemesi
- 7. Trigonometrik Katsayılar ve Fourier Spektrumu
- 8. $\sin^3(3\pi t)$ Örneği
- 9. Yarım Dalga Doğrultulmuş Sinüs
- 10. Fourier Sentezi ve Gibbs Olayı
- 11. Fourier Dönüşümüne Giriş
- 12. Dikdörtgen Darbenin Fourier Dönüşümü
- 13. Genlik ve Faz, FFT Denemeleri
- 14. $e^{-bt}u(t)$ İşaretinin Fourier Dönüşümü
- 15. Temel Fourier Dönüşüm Çiftleri

## 1. Ayrık Konvolüsyonda Sıfır Noktası

Hoca derse, önceki konulardan kalan bir noktayla başladı: ayrık konvolüsyon sonucunda sıfır noktasının, yani $n=0$ indisinin nerede olduğu. Konu sürekli zamanda da geçerlidir, ama ayrık zamanda daha önemlidir.

### 1.1 Sayısal Sonuç Aynı, İndisler Farklı

Hoca uzun sayılarla uğraşmamak için iki kısa işaret seçti:

$$x[n] = [1,\ 1,\ 1], \qquad y[n] = [1,\ 1]$$

Bu değerlerin sıfır noktası farklı yerlerde seçilebilir. Hoca tahtada kırmızıyla bir seçim işaretledi. İşaretin hangi örneğinin $n=0$ olduğu değişse de konvolüsyonun **sayısal değerleri değişmez**. Sonuç her durumda şu dizidir:

$$[1,\ 2,\ 2,\ 1]$$

Değişen, bu değerlerin hangi indislere oturduğudur. Soru şudur: Sonucun sıfır noktası neresi olacak?

Gerçek dünya uygulamalarında bu soru pek ortaya çıkmaz. Ayrık işaretlerde uygulamada negatif indis yoktur. "Eksi birinci örnek", "eksi ikinci örnek" diye bir şey bulunmaz. Örnekler sıfırdan başlar ve devam eder. Dolayısıyla uygulamada konvolüsyon sonucunun sıfır noktası da ilk örnektir. Teoride ise iş değişir ve indisi ayrıca bulmak gerekir. Hoca bunun için üç yol gösterdi.

Bundan sonra kırmızıyla işaretlenen seçim kullanılacaktır:

$$x[n] = [1,\ \underline{1},\ 1] \quad (n=-1,0,1), \qquad y[n] = [\underline{1},\ 1] \quad (n=0,1)$$

Altı çizili değer $n=0$ örneğidir.

### 1.2 Birinci Yol: Darbe Gösterimi ve Dağılma Özelliği

Hocanın "işin en temel, en olması gereken yolu" dediği çözüm budur. Önce işaretler birim darbe (unit impulse) fonksiyonları cinsinden yazılır. Hoca önce "birim basamak" dedi, hemen düzeltti: Burada kullanılan birim darbedir.

**Soru:** $x[n]$ işareti birim darbeler cinsinden nasıl yazılır? **Cevap:** $\delta[n+1] + \delta[n] + \delta[n-1]$.

Ortadaki terim $\delta[n]$'nin kendisidir. Diğer ikisi onun bir birim ileri ve bir birim geri kaydırılmış halleridir. $y[n]$ de aynı şekilde yazılır:

$$x[n] = \delta[n+1] + \delta[n] + \delta[n-1], \qquad y[n] = \delta[n] + \delta[n-1]$$

Konvolüsyon değişme özelliğine sahiptir, yani $x[n]*y[n] = y[n]*x[n]$. Hoca $y[n]$'yi sabit bıraktı ve $x[n]$'yi dağılma özelliğiyle açtı:

$$y[n]*x[n] = y[n]*\delta[n+1] + y[n]*\delta[n] + y[n]*\delta[n-1]$$

Bir işareti tek bir darbeyle konvolve etmek ne demektir? Darbe tek bir noktada değer alır, başka her yerde sıfırdır. İşareti baştan sona onunla çarparsak yalnız o noktadaki değerler sonuç verir. Yani işaret, darbenin bulunduğu yere kaymış olur:

$$y[n]*\delta[n-k] = y[n-k]$$

Buna göre sonuç şudur:

$$y[n]*x[n] = y[n+1] + y[n] + y[n-1]$$

$y[n+1]$, işareti zamanda bir birim geri almak demektir. Üç terim ayrı ayrı yazılır:

$$y[n+1] = \delta[n+1] + \delta[n]$$
$$y[n] = \delta[n] + \delta[n-1]$$
$$y[n-1] = \delta[n-1] + \delta[n-2]$$

Aynı terimler toplanır. $\delta[n+1]$'den bir tane, $\delta[n]$'den iki tane, $\delta[n-1]$'den iki tane, $\delta[n-2]$'den bir tane vardır:

$$x[n]*y[n] = \delta[n+1] + 2\delta[n] + 2\delta[n-1] + \delta[n-2]$$

Bu, $n=-1$'de 1, $n=0$'da 2, $n=1$'de 2, $n=2$'de 1 değerini alan işarettir:

$$x[n]*y[n] = [1,\ \underline{2},\ 2,\ 1]$$

İlk 2 değeri sıfır noktasıdır. Yöntemin avantajı, hem sonucu hem de sıfır noktasını doğrudan vermesidir.

### 1.3 İkinci Yol: Polinom Çarpımı Benzetmesi

Hoca "Bu yaptığımız işlem matematikte neye benziyor?" diye sordu ve cevabı verdi: Bu aslında bir polinom çarpmasıdır. Bazı kaynaklarda kural olarak geçen bir kısa yol vardır. Hoca bu kuralın genel olarak doğru olduğunu, ama bilinmesinin şart olmadığını söyledi.

Her örneği, üssü indisine eşit bir terim gibi düşünün. $x[n]$ için $x^{-1} + x^{0} + x^{1}$, $y[n]$ için $x^{0} + x^{1}$ yazılır. Burada $x$ polinom değişkenidir, işaret değildir. İki polinom çarpılır:

$$(x^{-1} + x^{0} + x^{1})(x^{0} + x^{1})$$

Terim terim açılınca şu elde edilir:

$$x^{-1} + x^{0} + x^{0} + x^{1} + x^{1} + x^{2} = x^{-1} + 2x^{0} + 2x^{1} + x^{2}$$

Katsayılar konvolüsyon sonucunu, üsler indisleri verir. Katsayı dizisi yine $[1, 2, 2, 1]$'dir. Sıfır noktası $x^0$'ın bulunduğu terimdir, yani katsayısı 2 olan ilk terim.

Hoca sonra bu benzetmenin kaynağını söyledi: Bu z-dönüşümünden (z-transform) gelen bir özelliktir. Ayrık zamanlı sistemlerde $n$ düzleminden $z$ düzlemine geçilecek ve bazı işlemler orada kolaylaşacaktır. Örneğin bir sistemin kararlı olup olmadığını doğrudan $n$ düzleminde tespit etmek zordur, ama z-dönüşümünü alıp incelemek bunu kolaylaştırır. En basitinden konvolüsyon bile orada kolaydır.

> **Ek bilgi (derste anlatılmadı):** Hocanın kastettiği bağlantı büyük olasılıkla şudur: Bir $x[n]$ işaretinin z-dönüşümü $\sum_n x[n]z^{-n}$ biçiminde bir polinoma benzer ve konvolüsyon z düzleminde çarpmaya dönüşür. Dersteki $x^{n}$ yazımında üs artı işaretlidir, z-dönüşümünde eksi işaretlidir. İndislerin toplanması ikisinde de aynı şekilde olur.

### 1.4 Üçüncü Yol: Sınırları Toplama

Kitaplarda gösterilen kısa yol şudur. Her işaretin sınırları kapalı aralık olarak verilir (köşeli parantez, sınırın dahil olduğunu gösterir):

$$x[n]:\ [-1,\ 1], \qquad y[n]:\ [0,\ 1]$$

Sonucun sınırları, alt sınırların ve üst sınırların ayrı ayrı toplanmasıyla bulunur:

$$x[n]*y[n]:\ [-1+0,\ 1+1] = [-1,\ 2]$$

Genel olarak $x[n]$ $[a_1, b_1]$ aralığında, $y[n]$ $[a_2, b_2]$ aralığında tanımlıysa sonuç $[a_1+a_2,\ b_1+b_2]$ aralığında tanımlıdır.

Pratikte şöyle kullanılır: İşareti ters çevirip kaydırarak $[1, 2, 2, 1]$ değerlerini buldunuz. Sonra sınırlardan yola çıkarak indisleri yerleştirirsiniz: İlk değer $n=-1$, sonraki $n=0$, sonra $n=1$ ve $n=2$. Sıfır noktası böylece işlem yapmadan bulunur.

> **Hocanın vurgusu:** Sınavdaki konvolüsyon sorusunda adımlar gösterilmelidir. Kabul edilen iki yol vardır: işlemin tanımından yola çıkıp ters çevirip adım adım kaydırmak ve çarpmak, ya da işareti birim darbeler cinsinden yazıp dağılma özelliğiyle ilerlemek. Polinom yolu çözüm olarak kabul edilmez. Sıfır noktasının doğru bulunması önemlidir.

### 1.5 MATLAB ve Python'daki Hazır Fonksiyonlar

MATLAB'de veya Python'da kullanılan hazır konvolüsyon fonksiyonu işareti doğrudan sıfır noktasından ele alır. İndis bilgisini siz vermezseniz ve grafikte kaydırma yapmazsanız sonuç sıfırıncı örnekten başlıyormuş gibi yazılır. Bu normaldir. İndisi ayrıca kendiniz ayarlamanız gerekir.

## 2. Temel Frekans ve Periyodiklik: Önceki Dersin Düzeltmesi

Hoca Fourier serilerine dönerken, bu konu ile Fourier dönüşümünü iyi öğrenmenin z-dönüşümü ve Laplace dönüşümünü de çok kolaylaştıracağını söyledi. Bugün hem örnek çözülecek, hem MATLAB'de simülasyon yapılacak, hem de konu tamamlanacaktı.

### 2.1 Temel Frekansın Hatırlatılması

Temel frekans, işaretin bütün frekans bileşenlerinin en büyük ortak böleni (GCD, EBOB) alınarak bulunur. Slayttaki ilk örnekte temel frekans 10 Hz idi.

**Soru:** Temel periyot nedir? **Cevap:** Frekans ile periyodun çarpımı 1'dir, $f \cdot T = 1$. O halde $T_0 = 1/10 = 0.1$ saniyedir.

İkinci örnekte temel frekansın 100 Hz değil 50 Hz olduğu, çünkü bileşenlerin GCD'sinin 50 olduğu hatırlatıldı. Buradan $T_0 = 1/50$ saniye gelir (ara adım eklendi; hoca cümleyi bitirmedi).

<!-- BELİRSİZ: 10 Hz ve 50 Hz temel frekanslı slayt örneklerinin bileşenleri altyazıda söylenmiyor. -->

### 2.2 Sürekli Zaman: $\cos(t + \pi/4)$

Önce sürekli zamanlı işaret hatırlatıldı. $\cos(t + \pi/4)$ işaretinde $\pi/4$ fazdır. Frekans, $\omega_0 t = t$ eşitliğinden gelir:

$$\omega_0 = 1 \quad\Rightarrow\quad 1 = 2\pi f_0 \quad\Rightarrow\quad f_0 = \frac{1}{2\pi} \quad\Rightarrow\quad T_0 = \frac{1}{f_0} = 2\pi$$

Hoca, $t$ düzleminde periyodun bir sürü değer alabileceğini ve bu işaretin periyodik olduğunu söyledi.

> **Ders sonrası not:** Hoca gerekçe olarak $2\pi$'nin "rasyonel bir şey" olduğunu söyledi ve $\pi$ için $22/7$'yi andı; doğrusu $\pi$ irrasyoneldir, $22/7$ yalnız yaklaşık değeridir. Sürekli zamanda tek sinüzoidin periyodik olması için periyodun rasyonel olması gerekmez. $T_0 = 2\pi$ gerçel bir sayıdır ve $\cos(t+2\pi+\pi/4) = \cos(t+\pi/4)$ olduğu için işaret periyodiktir.

### 2.3 Ayrık Zaman: $\cos(n/4)$

Hoca önceki derste burada hata yaptığını söyledi ve düzeltti. Ayrık zamanda $\cos\!\left(\frac{1}{4}n\right)$ işaretinde rasyonellik aranmaz, **tam sayı** aranır:

$$\Omega_0 n = \frac{1}{4}n \quad\Rightarrow\quad \Omega_0 = \frac{1}{4} \quad\Rightarrow\quad \frac14 = 2\pi F_0 \quad\Rightarrow\quad F_0 = \frac{1}{8\pi} \quad\Rightarrow\quad N_0 = 8\pi$$

$N_0 = 8\pi$ tam sayı olmadığı için işaret periyodik değildir. Önceki derste bu işarete yanlışlıkla periyodik denmişti. Ayrık zamanlı işaretlerde periyodikliğe bakarken elde edilen sonucun tam sayı olmasına dikkat edilmelidir.

Hoca iki bileşen olduğunda $N_0/N_1$ oranının da tam sayı olup olmadığına bakılacağını söyledi.

> **Ders sonrası not:** Hoca gerekçeyi "$22/7$ tam sayı değil" diye verdi; doğrusu $\pi$'nin irrasyonel olmasıdır. Ayrık zamanda periyot koşulu, bir $k$ tam sayısı için $N = 2\pi k/\Omega_0$ değerinin tam sayı olmasıdır. Burada $N = 8\pi k$ hiçbir sıfırdan farklı tam sayı $k$ için tam sayı olmaz, işaret bu yüzden periyodik değildir. İki bileşende de hocanın dediği "oran tam sayı olmalı" koşulu fazla dardır: Her bileşenin kendi tam sayı periyodu varsa toplam da periyodiktir ve periyodu bu iki sayının EKOK'udur. Oranın tam sayı çıkması gerekmez.

Hoca bir de frekans bileşenleri irrasyonel sayılardan oluşsa bile temel frekansın yine GCD hesabıyla bulunacağını ekledi.

### 2.4 Harmonik ve Harmonik Olmayan İşaretler

Slaytta iki durum vardı. Harmonik işarette bileşenlerin toplamı periyodik bir işaret verir. Slayttaki üç sinüzoid toplamına bileşen eklendikçe sonuç kare dalgaya doğru ilerler. Harmonik olmayan (non-harmonic) işaretin içinde periyodik olmayan bir durum vardır. Periyodik olmadığı için bunu Fourier serisiyle sinüs ve kosinüsler cinsinden yazmak doğru sonuç vermez.

## 3. Fourier Analizinin Uygulamaları: Ses, Nota ve Spektrogram

Hoca bu bölümde konunun işe yaradığı yeri, ses ve müzik örnekleri üzerinden, kendi tezinden de örnek vererek anlattı. Burada anahtar konu müzik bilgisi çıkarımıdır (music information retrieval).

### 3.1 Saf Nota ve Tını

Bir notanın zaman düzlemindeki karşılığı dalga biçimidir. Örneğin C6 notası yaklaşık 1047 Hz'liktir ve saf hali sinüzoidal bir dalgadır. Bunu frekans düzlemine geçirince tek bir temiz bileşen görülür.

Bilgisayarda bu notayı sentezlemek çok kolaydır. Slayttaki kodun yaptığı şey, $\sin(2\pi f_0 t)$ ifadesinde $f_0 = 1047$ alıp CD kalitesinde (en yüksek frekans 22 050 Hz) örnekleri üretmek, sonra bu veriyi örnekleme hızıyla birlikte seslendirmektir.

Aynı C6 notası obuayla çalınırsa tablo değişir. 1047 Hz bileşeni yine vardır, ama ek bileşenler ortaya çıkar: 2000 Hz civarında bir bileşen, ardından azalıp giden başkaları. Klarnette de baskın bir bileşen ve onun ardından azalan bileşenler vardır, ama dağılım farklıdır. Bu farklılık **tını** (timbre) dediğimiz, müziğin karakterine ait bilgidir.

Bu yüzden flüt, gitar veya ut gibi bir enstrümanın sesini bilgisayarda doğrudan sentezlemek çok zordur. Saf notayı üretmek kolaydır, enstrümanı üretmek zordur.

### 3.2 Sentez Zor, Analiz Mümkün

Makine olarak şu yapılabilir: Bir ses kaydı alınır ve sentezin tersi olan analiz uygulanır, yani frekans bileşenleri ayrılır. Baskın frekanslara bakılarak hangi nota olduğu, makam, müzik türü ya da sanatçının sesi gibi analizler yapılabilir. Örneğin belirli bir zaman aralığındaki notanın C majör olduğu sesten tespit edilebilir. Hoca kendi tezinde de bu yaklaşımı kullandığını söyledi.

### 3.3 Spektrogram

Ses dosyasını zaman düzleminde çizdiğinizde yalnız bir dalga biçimi görürsünüz. Fikir şudur: İşaretin bir parçası alınır, ona Fourier analizi uygulanır. Sonra bir sonraki parça alınır, aynısı yapılır. Bütün parçalar açıldığında, telefon tuşu örneğinde olduğu gibi, ilk parçanın C notasına karşılık geldiği anlaşılır. Çünkü elimizde bir **kod kitabı** (codebook) vardır: C notası şu frekansları içerir, başka nota şu frekansları içerir.

Bu işi yapan araca **spektrogram** denir. Hoca şu ayrıma dikkat çekti: Burada "zamandan frekansa geçiş" değil, **zamana göre frekansın değişimi** söz konusudur. Örneğin 0-200 milisaniye aralığının frekans düzlemi karşılığı bulunur. Bu bulununca kod kitabıyla hangi notaya karşılık geldiği anlaşılır. Grafikte bir eksen zaman, diğer eksen frekanstır ve her zaman aralığında hangi frekans bileşenlerinin bulunduğu görülür.

Hoca telefon tuşlama problemini örnek gösterdi. Elimizde 7 haneli bir numaranın tuşlanma sesi olsun, başka hiçbir şey olmasın. Dosyada önce bir işaret gelir, sonra belli bir aralık sıfıra yakın düz kalır, sonra başka bir işaret gelir. Her aralık alınıp frekans düzleminde incelenir. Kaç tuşa basıldıysa aynı işlem o kadar tekrarlanır. Aynı yol nota bulmak için de geçerlidir.

Spektrogram aracı bir ilk parçayı alır, analiz eder, Fourier katsayılarını veya frekans katsayılarını döndürür. Böylece zaman-frekans analizi yapılmış olur. Hoca bu aracın sinyal işleme dersinde daha çok kullanılacağını söyledi. Arka planda her zaman seri çalışmaz. Çoğu zaman ileride görülecek Fourier dönüşümünün algoritmik hali çalışır. Çünkü işaretler her zaman periyodik değildir ve bu hal daha hızlıdır.

### 3.4 İki Frekansın Çarpımı

Hoca slaytta zamana göre çizilmiş bir ses gösterdi. Zaman düzleminde doğrudan görünmese de Fourier açılımı yapılınca iki frekans bileşeni ortaya çıkar: 672 Hz ve 648 Hz.

İşaretin denklemi elimizde olsaydı frekanslar kolayca bulunurdu. İşaret 660 Hz ile 12 Hz'lik iki frekansın çarpımıdır:

$$x(t) = \cos(2\pi\,660\,t)\,\sin(2\pi\,12\,t)$$

Hoca her iki çarpanı Euler formülüyle açıp dağıttı. Sonuçta frekansların toplamı ve farkı gelir: $660+12 = 672$ ve $660-12 = 648$. Sonuç şudur (ara adım eklendi):

$$x(t) = \frac12\sin(2\pi\,672\,t) - \frac12\sin(2\pi\,648\,t)$$

Hoca bunların sinüs olduğunu, 90 derece faz farkıyla kosinüs olarak da yazılabileceğini belirtti. Analiz yönteminin önemi burada görülür: Denklem elimizde olsa bulmak kolaydır, ama elimizde yalnız ses dosyası varsa Fourier analizine başvurmak zorundayız.

**Soru:** Temel frekans nedir? **Cevap:** $\mathrm{GCD}(648, 672) = 24$ Hz.

Hoca sonucu slayttan da kontrol etti. Dikkat edilecek nokta şudur: Temel frekans **en küçük frekans değildir**, ortak bölendir. Hocaya göre GCD hesaplayan analog devreler de vardır. Dijitalde ise algoritma yazılır: Yapısal programlamaya giriş dersinde görülen Öklid algoritması gibi.

### 3.5 Notaların Spektrogramı

Bir şarkının nota dosyasını zaman düzleminde gösterince dalga biçimi görülür. Spektrogram yapılınca belirli bir aralıkta notanın frekansı örneğin 250 Hz civarında kalır, başka bir nota yaklaşık 300 Hz'e karşılık gelir. Do, re, mi, fa, sol gibi notaları tespit etmek artık zor değildir. Baskın frekansa bakmak yeter.

Bazı zaman aralıklarında iki bileşen görülür, bazı yerlerde daha fazla. Hoca bunun, o andaki notanın daha fazla bileşenin birleşimi olmasından kaynaklanabileceğini söyledi. Slaytta analiz çerçevesi (analysis frame) 40 milisaniye idi. Yani ses yaklaşık 40 milisaniyelik parçalara bölünüyordu.

### 3.6 Doğrusal Frekans Modülasyonu (Chirp)

Hoca frekans modülasyonuna da kısaca değindi. Bu, haberleşme ve elektronikçilerin işidir. Örneğin insan sesini telefon hattında taşımak için modülasyon gerekir. Burada yapılan da bir dönüşümdür.

Doğrusal frekans modülasyonu, "kuş sesi" diye anılan **chirp** işaretidir. Fazı $t$'nin karesiyle ve $t$ ile değişir (slaytta $a t^2 + 2\pi f t$ biçiminde, kuadratik). Spektrogramında frekansın zamanla doğrusal olarak arttığı görülür.

Hoca anlık frekans gibi kavramların sinyal işlemede anlatıldığını, bu dersten sorumlu olunmadığını söyledi.

<!-- BELİRSİZ: Chirp işaretinin slayttaki tam formülü altyazıda yalnız "a çarpı t kare artı 2 p f t" olarak geçiyor. -->

## 4. Fourier Serisi Katsayılarının Hatırlatması

Bu işin amacı sentez ve analizdir. Frekans, genlik ve faz bilgisi elimizdeyse işaretin zaman düzlemindeki halini oluşturmak kolaydır. Bunlar yoksa analiz etmek daha zordur ve iyi bir algoritma gerekir.

Temel fikir, işareti sinüs ve kosinüsler cinsinden yazmaktır. Katsayı çoğunlukla $c_k$ diye verilir, bazı kaynaklarda $a_k$ diye görülür, ikisi aynıdır:

$$c_k = \frac{1}{T_0}\int_0^{T_0} x(t)\,e^{-j\omega_0 k t}\,dt$$

Burada $\omega_0$ temel frekanstır. Temel frekansın katları kadar sinüzoidal bileşenlerle işaret bir periyot boyunca işleme sokulur. Hangi frekans bileşenlerinin bulunduğu böylece tespit edilir.

> **Ders sonrası not:** Hoca bu işleme "konvolüsyon" dedi; doğrusu bu bir konvolüsyon değil, $x(t)$ ile $e^{j\omega_0 kt}$ arasındaki iç çarpımdır (korelasyon benzeri bir işlemdir). Konvolüsyonda işaretlerden biri ters çevrilip kaydırılır, burada öyle bir kaydırma yoktur. Aynı düzeltme, ileride Fourier dönüşümü için geçen "kosinüs ve sinüslerle konvolüsyon" ifadesi için de geçerlidir.

DC bileşen, yani frekansı sıfır olan bileşen için $k=0$ yazılır. O zaman $e^0 = 1$ olur ve üstel terimin hükmü kalmaz:

$$c_0 = \frac{1}{T_0}\int_0^{T_0} x(t)\,dt$$

Elimizde $\omega_0$ yerine $T_0$ varsa $\omega_0 = 2\pi f_0 = \dfrac{2\pi}{T_0}$ yazılır.

Slaytta ayrıca üstel terimin bir periyot üzerindeki integrali vardı. Üs integralde aynen aşağı iner, sınırlar yerine yazılınca $e^{-j2\pi m} - 1$ çıkar:

$$\int_0^{T_0} e^{-j\frac{2\pi}{T_0} m t}\,dt = \frac{T_0}{-j2\pi m}\left(e^{-j2\pi m} - 1\right) = 0, \qquad m \ne 0$$

$m=0$ için integral $T_0$ olur (ara adım eklendi). Bu sonucun altında **diklik** (ortogonallik) vardır. $e^{+jk\omega_0 t}$ ile $e^{-jl\omega_0 t}$ çarpılıp $\frac{1}{T_0}$ ile bir periyot boyunca integre edilirse $k=l$ iken sonuç 1, $k \ne l$ iken 0 çıkar. Hoca çift ve tek fonksiyon ayrıntılarına girmeye gerek olmadığını, slaytın formüllerin nasıl türetildiğini anlattığını söyledi. Sonuçta bulunacak olan $a_k$ katsayıları ve faz bilgileridir.

## 5. Kare Dalga Örneği: Analiz

Hoca örneği slayttan alıp elle yazarak çözdü. Amaç önce $a_0$ ve $a_k$ (yani $c_k$) katsayılarını bulmak, sonra sinüs ve kosinüs bileşenlerini ayırmak ve frekans spektrumunu çizmektir.

### 5.1 Verilen İşaret ve Kurulum

Verilen kare dalga 0.04 saniyede bir kendini tekrar eder:

$$x(t) = \begin{cases} 1, & 0 \le t < 0.02 \\ 0, & 0.02 \le t < 0.04 \end{cases} \qquad T_0 = 0.04\ \text{s}$$

Şekilde $\omega_0$ doğrudan görülmeyebilir, ama periyot görülür. Bu yüzden $\omega_0$ yerine $2\pi/T_0$ yazılır. İşaret 0-0.02 aralığında ve 0.02-0.04 aralığında farklı davranır. İkinci aralıkta işaret sıfır olduğu için o kısmı yazmaya gerek yoktur:

$$c_k = \frac{1}{0.04}\int_0^{0.02} 1\cdot e^{-j\frac{2\pi}{0.04}kt}\,dt$$

### 5.2 İntegral

Üstel fonksiyonun integralinde üssün katsayısı paydaya iner:

$$c_k = \frac{1}{0.04}\cdot\frac{1}{-j\frac{2\pi k}{0.04}}\left[e^{-j\frac{2\pi}{0.04}kt}\right]_0^{0.02}$$

Üst sınırda $0.02/0.04 = 1/2$ olur, üs $e^{-j\pi k}$ değerine iner. Alt sınırda $e^0 = 1$ gelir. Baştaki $1/0.04$ ile paydadaki $0.04$ de sadeleşir, geriye $-j2\pi k$ kalır:

$$c_k = \frac{1}{-j2\pi k}\left(e^{-j\pi k} - 1\right)$$

Şimdi $e^{-j\pi k}$ terimine bakılır. Euler açılımıyla bu $\cos(k\pi) - j\sin(k\pi)$ demektir. $\sin(k\pi)$ her tam sayı $k$ için sıfırdır. $\cos(k\pi)$ ise $\pi$'de $-1$, $2\pi$'de $+1$, $3\pi$'de $-1$, $4\pi$'de $+1$ diye gider. Yani $e^{-j\pi k} = (-1)^k$. Paydadaki eksi de yukarı yansıtılınca şu elde edilir:

$$c_k = \frac{1 - (-1)^k}{j2\pi k}$$

### 5.3 Tek ve Çift $k$

- **$k$ tek ise:** $(-1)^k = -1$, pay $1-(-1) = 2$ olur. İkiler sadeleşir:

$$c_k = \frac{2}{j2\pi k} = \frac{1}{j\pi k}$$

- **$k$ çift ise ($k \ne 0$):** $(-1)^k = +1$, pay $1-1 = 0$ olur. Yani $c_k = 0$.

Bu yüzden sinüzoidal toplamda $1/\pi$, $1/3\pi$, $1/5\pi$ gibi katsayılar görülür. $1/2\pi$, $1/4\pi$ gibi katsayılar yoktur, çünkü onlar sıfırdır.

### 5.4 DC Bileşen

Formülde $k=0$ yazmak paydayı sıfırlar, bu yüzden $c_0$ ayrıca hesaplanır. $c_0$, işaretin bir periyot boyunca ortalamasıdır:

$$c_0 = \frac{1}{T_0}\int_0^{T_0} x(t)\,dt = \frac{1}{0.04}\int_0^{0.02} 1\,dt = \frac{0.02}{0.04} = \frac12$$

Bu sonuç integralsiz de görülür: Eğrinin altındaki alan hesaplanıp $1/T_0$ ile çarpılır. Kare dalganın altında kalan alanın ortalaması $1/2$'dir.

Toparlanırsa:

$$c_k = \begin{cases} \dfrac{1}{2}, & k = 0 \\[2mm] \dfrac{1}{j\pi k}, & k = \pm1, \pm3, \pm5, \dots \\[2mm] 0, & k = \pm2, \pm4, \dots \end{cases}$$

### 5.5 Frekans Spektrumu

Spektrumu çizmek için temel frekans gerekir. Temel periyot elimizde olduğu için:

$$f_0 = \frac{1}{0.04} = 25\ \text{Hz}, \qquad \omega_0 = 2\pi\cdot 25 = 50\pi\ \text{rad/s}$$

Spektrum çizgileri $k \cdot 25$ Hz'de bulunur: 25, 50, 75, 100, 125 Hz diye gider. Çift $k$ değerlerinde genlik sıfır olduğu için yazılmaz.

> **Hocanın vurgusu:** "İlk 3 frekans bileşenini çizin" denirse var olan genlikler çizilir. 25 Hz çizilir, 50 Hz çizilmez, çünkü o ilk üçe dahil değildir. Sonra 75 Hz ve 125 Hz çizilir.

Katsayılarda $j$'nin paydada durması makul bir gösterim değildir. Pay ve payda $-j$ ile çarpılırsa değer değişmez, $j$ paya geçer:

$$\frac{1}{j\pi k} = \frac{-j}{\pi k}$$

Sonuçta spektrum çizgileri şöyledir:

| Frekans (Hz) | $k$ | $c_k$ |
|---|---|---|
| 0 | 0 | $1/2$ |
| 25 | 1 | $-j/\pi$ |
| 75 | 3 | $-j/3\pi$ |
| 125 | 5 | $-j/5\pi$ |
| $-25$ | $-1$ | $j/\pi$ |
| $-75$ | $-3$ | $j/3\pi$ |
| $-125$ | $-5$ | $j/5\pi$ |

Python ile sayısal integral bu tablonun bütün değerlerini verdi: $c_1 \approx -0.3183j$, $c_3 \approx -0.1061j$, $c_5 \approx -0.0637j$, çift $k$ için 0, $c_0 = 0.5$.

## 6. Kare Dalga Örneği: Sentez ve MATLAB Denemesi

Aranan, işareti sinüzoidal işaretler cinsinden yazmaktı. Katsayılar ve spektrum bulunduktan sonraki adım, işaretin hangi bileşenlerden oluştuğunu yazmaktır.

### 6.1 Eşlenik Çiftleri Birleştirme

İşarette önce frekansı sıfır olan $1/2$ DC bileşeni vardır. Sonra pozitif ve negatif frekans çiftleri gelir. Kullanılan kalıp, kosinüsün Euler açılımıdır:

$$A\cos(\omega t + \phi) = \frac12 A e^{j\phi}e^{j\omega t} + \frac12 A e^{-j\phi}e^{-j\omega t}$$

25 Hz çifti için $c_1 e^{j2\pi 25 t} + c_{-1}e^{-j2\pi 25 t}$ yazılır, bu da kalıba uyar. Hoca aynı işlemi 75 Hz çifti için tekrarladı ve bunun sonsuza kadar 1, 3, 5, 7 katlarıyla gittiğini söyledi. Bunların hepsi toplanırsa kare dalga yeniden elde edilir.

Doğru sonuç şudur:

$$c_1 = \frac{-j}{\pi} = \frac{1}{\pi}e^{-j\pi/2}$$

Buradan $\frac12 A = \frac1\pi$, yani $A = \frac{2}{\pi}$ ve $\phi = -\frac{\pi}{2}$ gelir:

$$c_1e^{j2\pi 25 t} + c_{-1}e^{-j2\pi 25 t} = \frac{2}{\pi}\cos\!\left(2\pi\,25\,t - \frac{\pi}{2}\right)$$

> **Ders sonrası not:** Hoca tahtada $-j/\pi$ değerini doğrudan üsse yazdı. Bu yüzden genliği 1, katsayıyı 2, fazı "$1/\pi$", ikinci bileşende de "$1/3\pi$" olarak okudu. Doğrusu $c_1 = -j/\pi$ değerinin genliği $1/\pi$, fazı $-\pi/2$'dir. Terimler $\frac{2}{\pi}\cos(2\pi\,25\,t - \pi/2)$ ve $\frac{2}{3\pi}\cos(2\pi\,75\,t - \pi/2)$ olur. Hoca dersin devamında slayttan doğru halini okudu (Bölüm 10).

### 6.2 MATLAB Denemesi: Tek Harmoniklerin Toplanması

Bu analizden sonra işareti çizdirmek zor değildir. Frekansı 25 olan terimi fazıyla yazıp, sonra 75 olanı ekleyerek, yani bir döngüyle ilerleyerek oluşturulabilir. Hoca bunun basit bir halini MATLAB'de gösterdi. Burada frekanslar 1, 3, 5, 7 rad/s alındı.

Hoca önce $\sin(3t)/3$ yazmayı düşündü, çünkü genlik düşürülmezse istenen sonuç görülmeyebilirdi. Sonra "direkt $3t$ yazalım" dedi ve bütün bileşenleri birim genlikli bıraktı. Komutlar sırayla şöyleydi:

```matlab
t = 0:0.1:10;
y  = sin(t);
y1 = sin(3*t);
y2 = sin(5*t);
y3 = sin(7*t);
subplot(4,1,1); plot(t, y)
subplot(4,1,2); plot(t, y + y1)
subplot(4,1,3); plot(t, y + y1 + y2)
subplot(4,1,4); plot(t, y + y1 + y2 + y3)
```

Hoca sonucu "kare dalgaya yaklaşan bir şey" diye yorumladı ve bir döngüyle 20 tane toplansa kare dalgaya çok yaklaşılacağını söyledi. Genlikleri daha net yazarsak bu işlemin kare dalgaya yakınsayacağını da ekledi.

> **Ders sonrası not:** Yukarıdaki kodda bütün genlikler 1'dir ve bu toplam kare dalgaya yakınsamaz. Kod numpy ile aynı adımlarla çalıştırıldı: Dört satırın tepe değeri 1.00, 1.54, 2.23, 2.94 çıktı, yani tepe her terimde büyüyor. 20 terimde tepe 14.5'e çıkıyor, düz bölge oluşmuyor. Kare dalga için genliklerin $1/k$ ile azalması şarttır. Bu derste bulunan $\frac{2}{\pi k}$ katsayılarıyla toplam, kısmi toplamlar kontrol edilince gerçekten yakınsıyor (süreksizlik yanındaki taşma hariç, Bölüm 10).

### 6.3 Testere Dişi Dalga

Hoca aynı işi başka bir periyodik işaret için kendi başımıza denememizi önerdi: devre teorisinden bilinebilecek, belirli bir değere kadar yükselip sonra başa dönen testere dişi dalga. Örneğin 0-1 aralığında yükselip 1-2 aralığında kendini tekrar ederse periyodu 1'dir. Bunu analiz edip sinüzoidal bileşenleri toplayınca yine aynı işaret elde edilir.

<!-- BELİRSİZ: Testere dişi dalganın tam biçimi yalnız sözle ve tahtada çizilerek anlatılıyor. -->

## 7. Trigonometrik Katsayılar ve Fourier Spektrumu

### 7.1 $c_k$'dan $a_k$ ve $b_k$'ya

Önce analiz, sonra sentez yapıldı. Şimdi hangi bileşenlerin sinüs, hangilerinin kosinüs olduğuna bakılır. Burada $a_k$ kosinüs bileşenlerini, $b_k$ sinüs bileşenlerini gösterir ve $c_k$'dan şöyle bulunur:

$$a_k = 2\,\mathrm{Re}\{c_k\}, \qquad b_k = -2\,\mathrm{Im}\{c_k\}$$

$a_0$ burada önemli değildir, çünkü ayrı bulundu. Tek $k$ için $c_k = \dfrac{-j}{k\pi}$ idi.

**Soru:** Bu değerin reel kısmı var mı? **Cevap:** Yok. Değer $A + Bj$ biçiminde düşünülürse $A$ yoktur.

O halde $a_k = 2\cdot 0 = 0$. Kosinüs bileşeni çıkmaz. Hoca bunun şekle de uyduğunu söyledi: Bu tek fonksiyondur, içinde kosinüs bileşeni beklenmez. Çift fonksiyon olsaydı, yani kosinüse benzeyen bir kare dalga olsaydı, kosinüs bileşeni olurdu.

> **Ders sonrası not:** Hoca işarete doğrudan "tek fonksiyon" dedi. $1/2$ ortalaması olan bu işaretin kendisi tek değildir, $x(t) - \frac12$ tektir. Sonucu ($a_k = 0$) değiştirmez, çünkü DC bileşen ayrı tutuluyor.

Sinüs katsayıları için $c_k$'nın sanal kısmı $-\dfrac{1}{k\pi}$'dir ($j$ alınmaz):

$$b_k = -2\cdot\left(-\frac{1}{k\pi}\right) = \frac{2}{k\pi}$$

Yani sinüs katsayıları $\frac{2}{\pi}$, $\frac{2}{3\pi}$ diye gider. Bu, Bölüm 6'daki $\frac{2}{\pi}$ katsayısıyla uyumludur. Hocanın analiz sırasında söylediği "$1/\pi$ çarpı sinüs" ifadesindeki $1/\pi$ ise $|c_k|$ değeridir, sinüsün önündeki katsayı $2/(k\pi)$'dir. Bileşenler kosinüs olarak yazılmıştı, ama $-\pi/2$ fazıyla sinüse dönüşür:

$$x(t) = \frac12 + \frac{2}{\pi}\sin(50\pi t) + \frac{2}{3\pi}\sin(150\pi t) + \frac{2}{5\pi}\sin(250\pi t) + \dots$$

Bileşen sayısı artırıldıkça katsayılar çok küçük değerlere iner ve sönümlenir. Kare dalgaya o zaman yaklaşılır.

### 7.2 Fourier Spektrumu

Bu çizime **Fourier spektrumu** denir. Elimizde böyle bir spektrum varsa işareti inşa etmek için şu formül kullanılır:

$$x(t) = \sum_{k} a_k\, e^{j2\pi f_k t}$$

Her frekansta $a_k$ yerine o frekanstaki katsayı gelir, $f_k$ yerine de frekans (slayt örneğinde 100 Hz, 250 Hz gibi). Pozitif ve negatif frekanstaki katsayılar birbirinin kompleks eşleniğidir. Bunlar toplanınca asıl işaret bulunur. Bu işleme işaretin harmoniklerinin tespit edilmesi, harmoniklerin ayrıştırılması veya Fourier serisinin bulunması denir, hepsi aynı kavramdır.

<!-- BELİRSİZ: Slayttaki 100 Hz ve 250 Hz'li spektrum örneğinin katsayıları altyazıda okunamıyor ("7 çarpı E üzeri ..." dışında). -->

Hoca bir görselleştirmeyle sonucu özetledi: Zaman düzlemindeki bir işarete bakıp hangi frekansların olduğu doğrudan bulunamaz. Fourier serisi açıldığında sinüzoidal bileşenler ortaya çıkar. Her biri belirli frekanslı tek bir işarettir. Bu bileşenlere frekans düzleminden bakıldığında spektrum görülür.

> **Hocanın vurgusu:** Bu analiz biyomedikalde, ekonomide, müzikte, görüntüde, her yerde karşımıza gelir. En temel analiz yöntemidir.

## 8. $\sin^3(3\pi t)$ Örneği

Biraz daha karmaşık bir işaret:

$$x(t) = \sin^3(3\pi t)$$

Frekans, $2\pi f t = 3\pi t$ eşitliğinden gelir: $f = 3/2 = 1.5$ Hz. Çizimden de sıfır noktasından itibaren yaklaşık bu frekansta olduğu görülür.

Slayttaki analiz sonucu şudur:

$$x(t) = \frac{j}{8}e^{j9\pi t} - \frac{3j}{8}e^{j3\pi t} + \frac{3j}{8}e^{-j3\pi t} - \frac{j}{8}e^{-j9\pi t}$$

İşaret periyodik olduğu için bunu Fourier serisinden elde etmek ilkesel olarak zor değildir. Ama integral alırken zorlanılır. $\sin^3(3\pi t)$ ile $e^{-j\omega_0 kt}$ çarpımının integrali için değişken dönüşümü, kısmi integrasyon gibi birçok işlem gerekir. Hoca burada kalkülüs dersinde olmadığımızı ve bu kadar zor integrali sormayacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu sonuca integralsiz de ulaşılabilir. $\sin\theta = \frac{e^{j\theta}-e^{-j\theta}}{2j}$ yazılıp küp açılınca $\sin^3\theta = \frac{j}{8}e^{j3\theta} - \frac{3j}{8}e^{j\theta} + \frac{3j}{8}e^{-j\theta} - \frac{j}{8}e^{-j3\theta}$ gelir. $\theta = 3\pi t$ konunca slayttaki ifade çıkar. Python karşılaştırmasında fark sayısal gürültü düzeyinde ($10^{-15}$) kaldı.

Bileşenlerin frekansları $3\pi t$ için 1.5 Hz, $9\pi t$ için 4.5 Hz'dir. Temel frekans bunların GCD'sidir:

$$\mathrm{GCD}(1.5,\ 4.5) = 1.5\ \text{Hz}$$

Burada en küçük frekans ile GCD aynı çıkmıştır. Spektrumda şunlar görülür:

- $k = \pm1$: $\pm1.5$ Hz bileşeni vardır.
- $k = \pm2$: $\pm3$ Hz bileşeni yoktur. O bileşende genlik sıfırdır.
- $k = \pm3$: $\pm4.5$ Hz bileşeni vardır.

DC bileşen her zaman olmak zorunda değildir, sıfır da olabilir. Burada sıfırdır.

Genlik ve fazlar katsayılardan okunur:

| Frekans (Hz) | $k$ | $c_k$ | Genlik ve faz |
|---|---|---|---|
| $1.5$ | $1$ | $-3j/8$ | $0.375\,e^{-j0.5\pi}$ |
| $-1.5$ | $-1$ | $3j/8$ | $0.375\,e^{+j0.5\pi}$ |
| $4.5$ | $3$ | $j/8$ | $0.125\,e^{+j0.5\pi}$ |
| $-4.5$ | $-3$ | $-j/8$ | $0.125\,e^{-j0.5\pi}$ |

Bu değerler sayısal integralle doğrulandı. Buradan sonra sinüs ve kosinüs karşılıklarını Euler denklemiyle yazmak zor değildir.

> **Ders sonrası not:** Altyazıda 4.5 Hz bileşeni için "$0.125\,e^{-j0.5\pi}$" geçiyor; doğrusu $c_3 = j/8 = 0.125\,e^{+j0.5\pi}$'dir, verilen değer $-4.5$ Hz'e aittir. Altyazıdaki "$0.375$" önündeki "eksi" de genliğe ait değildir, genlik pozitiftir ve eksi işaret $e^{-j0.5\pi}$ fazındadır.

## 9. Yarım Dalga Doğrultulmuş Sinüs

Slayttaki sıradaki örnek **yarım dalga doğrultulmuş sinüs** (half-rectified sine) dalgasıdır. Periyodun ilk yarısında sinüs, ikinci yarısında sıfırdır:

$$x(t) = \begin{cases} \sin\!\left(\dfrac{2\pi}{T_0}t\right), & 0 \le t < T_0/2 \\[2mm] 0, & T_0/2 \le t < T_0 \end{cases}$$

Katsayı formülüne yerleştirilince integralde iki sinüzoidal terim çarpılır:

$$a_k = \frac{1}{T_0}\int_0^{T_0/2} \sin\!\left(\frac{2\pi}{T_0}t\right)e^{-j\frac{2\pi}{T_0}kt}\,dt$$

Bu çarpımın integrali kısmi integrasyon ister. Hocanın gösterdiği kolay yol, sinüsü üstel biçimde yazmaktır:

$$\sin\theta = \frac{e^{j\theta} - e^{-j\theta}}{2j}$$

Böylece üstel terimler ortak parantezde birleşir. Kullanılan şey temel lise matematiğindeki üslü sayı kurallarıdır:

$$a_k = \frac{1}{2jT_0}\int_0^{T_0/2}\left[e^{-j\frac{2\pi}{T_0}(k-1)t} - e^{-j\frac{2\pi}{T_0}(k+1)t}\right]dt$$

Sınırlar yerine yazılınca (ara adım eklendi) şu ifadeye gelinir:

$$a_k = \frac{1}{2j}\left[\frac{1-(-1)^{k-1}}{j2\pi(k-1)} - \frac{1-(-1)^{k+1}}{j2\pi(k+1)}\right]$$

Hocanın okuduğu sonuç şudur:

- $k$ tek ise ($k \ne \pm1$): $a_k = 0$.
- $k$ çift ise (2, 4, 6, 8, ...): katsayı $k^2 - 1$ paydalı bir değerdir.
- $k = \pm1$: paydada sıfır olduğu için ayrıca incelenmelidir.

<!-- BELİRSİZ: Slayttaki sınır yerine yazma ara adımı altyazıda "k artı bir eksi k eksi bir bölü 4k kare eksi bir" gibi bozuk geçiyor; yukarıdaki ara adım buradan değil, integralden kuruldu. -->

> **Ders sonrası not:** Hoca "$k = \pm1$'de belirsizlik var, bileşen yok" dedi; doğrusu bu bileşenler vardır ve en güçlü bileşenlerdendir. $k=\pm1$'de köşeli parantezin bir terimi $0/0$ olur, integrali doğrudan almak gerekir: $k=1$ için üstel terim 1 olur ve $a_{1} = \frac{1}{2jT_0}\cdot\frac{T_0}{2} = -\frac{j}{4}$, benzer şekilde $a_{-1} = +\frac{j}{4}$. Hoca çift $k$ için "$1/(k^2-1)$" dedi; doğrusu $a_k = \dfrac{-1}{\pi(k^2-1)}$'dir. $k=0$ da bu formüle uyar: $a_0 = 1/\pi$. Sayısal integral ($T_0 = 1$ ve $T_0 = 0.04$ ile aynı sonuç): $a_0 \approx 0.3183$, $a_{\pm1} = \mp 0.25j$, $a_{\pm2} \approx -0.1061$, $a_{\pm3} = 0$, $a_{\pm4} \approx -0.0212$, $a_{\pm5} = 0$, $a_{\pm6} \approx -0.0091$.

## 10. Fourier Sentezi ve Gibbs Olayı

### 10.1 Sentez Adımları

Hoca kare dalga örneğine slayttan bir kez daha baktı. Akış şudur: Şekil verilince önce $a_k$'lar bulunur, onlardan spektrum çizilir, sonra Fourier sentezi yapılır. Sonuç, örnekte kodlananla aynı biçimde orijinale yakındır.

Birinci ve üçüncü harmoniklerle işaret şöyle yazılır. DC bileşen $\frac12$'dir. Birinci harmonik $-j/\pi$ katsayılı 25 Hz bileşenidir ve $\pi/2$ kadar faz bilgisi vardır. Euler denklemiyle:

$$x_3(t) = \frac12 + \frac{2}{\pi}\cos\!\left(2\pi\,25\,t - \frac{\pi}{2}\right) + \frac{2}{3\pi}\cos\!\left(2\pi\,75\,t - \frac{\pi}{2}\right)$$

Neden $-\pi/2$ var? Çünkü bunların hepsi faz farkıyla aslında sinüse dönüşür. Hoca bunun çok mühim olmadığını söyledi: Faz farkı olsa da sonuçta kare dalga bulunur. 7. harmoniğe kadar çıkılırsa bileşen sayısı artar ve şekil kare dalgaya biraz daha yaklaşır.

### 10.2 Gibbs Olayı

Bileşen sayısı çok artırılırsa süreksizlik noktalarının yanında **kulak** gibi taşmalar oluşur. Buna **Gibbs olayı** (Gibbs phenomenon) denir. Hoca bu kulakların şu noktadaki süreksizlikten kaynaklandığını söyledi. Süreksizlik yüzünden kare dalgaya tam ulaşan sonsuz toplamı zaten elde edemeyiz, ama toplamı bir yerde kesip kare dalgaya yakın bir sonuç bulmak mümkündür. Hoca ayrıntıların sinyal işleme veya ileri sinyal işleme derslerinde anlatıldığını belirtti.

> **Ders sonrası not:** Hoca Gibbs olayını "%90'ını, %95'ini geçerse dursun, daha fazla bileşen ekleme" diye kullanılan bir araç gibi anlattı; doğrusu bu bir durdurma ölçütü değil, kısmi toplamın süreksizlik yanında yaptığı taşmadır. Bu örnekteki 0-1 kare dalga için tepe değeri sayısal olarak hesaplandı: 10 terimde 1.0899, 100 terimde 1.0895, 1000 terimde 1.0895. Yani taşma, sıçrama yüksekliğinin yaklaşık %8.95'idir ve terim sayısı artınca küçülmez. Yalnız taşmanın yeri süreksizliğe daha çok yaklaşır.

Bu işlemin tamamı Fourier sentezidir: Az önce analizi yapılan işaretin orijinal dalgasını yeniden bulmak.

## 11. Fourier Dönüşümüne Giriş

### 11.1 Neden Dönüşüm?

Şu ana kadar yapılan, periyodik işaretlerde Fourier serisi analiziydi. Ama bu her zaman mümkün değildir. Hoca bilimin genellikle böyle ilerlediğini söyledi: Bir sorun çıkar, mevcut yöntem yetmez, daha iyi bir yöntem aranır. Fourier serisinin yetmediği en basit durum, işaretin periyodik olmamasıdır.

Bunu genelleştiren yöntem, periyodik olmayan (non-periodic) işaretlere de uygulanan **Fourier dönüşümüdür** (Fourier transform). Burada sürekli zamanlı dönüşüm görülecek, ayrık zamanda da kullanılacaktır. Yine işaret sinüzoidaller cinsinden ele alınır. Fark şudur: $a_0$, $a_k$, $b_k$ yoktur. Herhangi bir sinüzoidal bileşen işaretin içinde varsa sonucu oluşturur. Bunun için mümkün olan bütün frekansları test etmek gerekir. Bu da hesaplama açısından bir problemdir.

### 11.2 Formül

Bir işaretin Fourier dönüşümü şöyle tanımlanır:

$$X(\omega) = \int_{-\infty}^{\infty} x(t)\,e^{-j\omega t}\,dt$$

Burada üstel terim bildiğimiz açılıma sahiptir:

$$e^{-j\omega t} = \cos\omega t - j\sin\omega t$$

Yani işaret, belirli bir periyot boyunca değil, $-\infty$'dan $+\infty$'a kosinüs ve sinüs işaretleriyle karşılaştırılır. Hangi frekanslar varsa o kosinüs ve sinüs bileşenlerinde tepe (pik) oluşur. Böylece hangi frekansların bulunduğu test edilir. Sonuç büyük $X$ ile yazılır ve frekansa bağlıdır.

İntegral dönüşümlerinin genel kalıbı şöyledir:

$$F(y) = \int f(x)\,\varphi(x, y)\,dx$$

Sonunda $x$'ler kaybolur, sonuç $y$'ye bağlı kalır. Burada da $x(t)$ işareti, içinde hem $t$ hem $\omega$ bulunan üstel fonksiyonla integre edilir. Sonuçta $t$'ler kaybolur, $\omega$'lar kalır.

> **Hocanın vurgusu:** Fourier dönüşümünün sonucunda hiçbir şekilde $t$ bulunmamalıdır. Bulunuyorsa bilin ki yanlış bir şey yaptınız.

### 11.3 Ters Dönüşüm

Fourier sentezinin dönüşümdeki karşılığı **ters Fourier dönüşümüdür** (inverse Fourier transform). Elimizde $X(\omega)$ varken $x(t)$'ye şöyle dönülür:

$$x(t) = \frac{1}{2\pi}\int_{-\infty}^{\infty} X(\omega)\,e^{j\omega t}\,d\omega$$

Bu da bir integral dönüşümüdür. $\omega$'ya göre integral alınınca sonuç $t$'ye bağlı olur. Hoca $\frac{1}{2\pi}$ çarpanının bir normalizasyon olduğunu söyledi.

### 11.4 Her Dönüşümün İki Özelliği

Bundan sonra görülecek dönüşümlerin ortak özellikleri vardır:

- **Bir düzlemden öbür düzleme geçiş:** $t$, $n$, $f$, $\omega$ düzlemlerinden birindeyken dönüşüm yapılır ve başka bir düzleme, örneğin $z$ veya $s$ düzlemine geçilir.
- **Geri dönülebilirlik:** Bir şeyin dönüşüm sayılması için tekrar geri dönebilmek gerekir. Geri döndürülemeyen işlem dönüşüm olarak kabul edilmez ve kullanılmaz.

Bu yüzden Laplace ve ters Laplace, z ve ters z, Fourier ve ters Fourier gibi çiftler vardır. Matematikte bunların karşılığı integral dönüşümleridir ve matematik mühendisliğinde daha ayrıntılı çalışılır.

<!-- BELİRSİZ: 01:50:12'de sayılan dönüşümlerden biri altyazıda "Hard-D dönüşümü" olarak geçiyor, hangi dönüşüm olduğu anlaşılmıyor. -->

### 11.5 Algoritmik Bakış: $O(N^2)$ ve FFT

Dönüşümün özü, $x(t)$ işaretini teorik olarak sonsuz sayıda kosinüs ve sinüsle karşılaştırmaktır. İşaretin içinde belirli bir kosinüs varsa, frekansla örtüştüğünde tepe oluşur.

Bunu kodlamak istersek iki iç içe `for` döngüsü gerekir. $x(t)$ zamana göre değişir, üstel terim de zamana ve frekansa göre değişir. Bütün olası durumlar çarpılır. Örnek sayısı $N$ ise iki döngü de $N$ kez döner, karmaşıklık $O(N^2)$ olur. Bunun hızlandırılmış hali **hızlı Fourier dönüşümü** (Fast Fourier Transform, FFT) $O(N\log N)$'e düşer. Hoca ayrıntısına sonra geleceğini söyledi.

Python'da iki iç içe döngüye karşılık gelen doğrudan hesap ile `numpy.fft.fft` karşılaştırıldı, sonuçlar arasındaki fark yuvarlama düzeyinde kaldı.

### 11.6 Sonuç Karmaşıktır

İşaret gerçel olsa bile sonuç karmaşık sayıdır, çünkü içeride sinüslerin önünde $-j$ vardır. Hoca reel ve sanal kısımda ayrı bilgi bulunduğunu söyledi.

> **Ders sonrası not:** Hoca "reel kısmı almak için $X(\omega)$'nın mutlak değeri alınır", "sanal kısım faz için kullanılır" dedi. Dersin ilerleyen kısmında da genlik yerine "real part" dedi. Doğrusu bunlar ayrı büyüklüklerdir. $|X(\omega)| = \sqrt{\mathrm{Re}^2 + \mathrm{Im}^2}$ **genlik spektrumudur**, reel kısım değildir. $\angle X(\omega) = \arctan(\mathrm{Im}/\mathrm{Re})$ **faz spektrumudur** ve hesabı için iki kısım da gerekir. Bu not boyunca hocanın "real part" dediği yerlerde kastedilen genlik olarak yazıldı.

### 11.7 Seri ile Dönüşümün Karşılaştırması

Slaytta iki yöntem yan yana özetlenmişti:

| | Fourier serisi | Fourier dönüşümü |
|---|---|---|
| Analiz | $c_k$ katsayıları, bir periyot boyunca | $X(\omega)$, $-\infty$'dan $+\infty$'a |
| Sonuç | Karmaşık değerli, tam sayı $k$'ya bağlı | Karmaşık değerli, $\omega$'ya bağlı |
| Sentez | $c_k$'ların toplamı | Ters dönüşüm integrali |

Fourier serisinde "ters Fourier serisi" diye ayrı bir şey yoktur. $c_k$'lar bulunduktan sonra toplanınca işaretin kendisi bulunur. Dönüşümde ise önce frekans bileşenleri bulunur, işarete dönmek istenirse ters dönüşüm yapılır.

### 11.8 Gösterim

Zaman düzlemindeki işaret küçük harfle, $x(t)$, dönüşümü büyük harfle, $X(\omega)$, yazılır. Büyük harf, bir dönüşüm yapıldığını gösterir. Dönüşüm işlemcisi süslü bir $\mathcal{F}$ ile gösterilir:

$$\mathcal{F}\{x(t)\} = X(\omega), \qquad \mathcal{F}^{-1}\{X(\omega)\} = x(t)$$

### 11.9 Benzetmeler: Röntgen, Ultrason, Teknik Resim

$X(\omega)$'ya bakmak neye benzer? Hoca önce röntgeni örnek verdi: X ışını bir yerden geçer ve orada hangi maddelerin olduğunu tespit eder. Ultrason da bu mantıkla çalışır. Bir dokuya veya organa farklı frekanslarda ses işaretleri gönderilir, işaretler dokulara çarpar ve ekranda bir görüntü oluşur. Osiloskopta bir işaret incelemek gibi, burada da yansımalar izlenir. Normal dokunun dışında bir şey varsa, örneğin tümör gibi hastalıklı bir yapı, bu fark edilir. Dönüşümde de amaç, işaretin içinde neler olduğuna bakmaktır.

$x(t)$ ile $X(\omega)$ birbirinin karakteristiğini tamamen yansıtır. Bu, aynı işareti başka bir açıdan incelemek gibidir.

Hocanın ikinci benzetmesi teknik resim oldu. Tahtaya ortasından kanal geçen üç boyutlu bir kutu çizdi. Bu cisme önden, yandan ve üstten bakıldığında her seferinde farklı bir şekil görülür: Birinde kanal görünür, birinde düz bir dörtgen, üstten bakınca ise kanalın çizgisi. Üç görünüş bir araya getirilince cisim ortaya çıkar. Fourier dönüşümü de işaretin kendisinde doğrudan görünmeyen bilgiyi verir, özellikle frekansı. Bir işarete zaman düzleminde bakıp hangi frekans bileşenlerinin olduğunu görmek mümkün değildir.

## 12. Dikdörtgen Darbenin Fourier Dönüşümü

### 12.1 Türetme

Genişliği $\tau$ olan dikdörtgen darbe (rectangular pulse) şöyle tanımlanır:

$$p_\tau(t) = \begin{cases} 1, & -\tau/2 \le t \le \tau/2 \\ 0, & \text{diğer yerlerde} \end{cases}$$

Burada küçük harf zaman işaretini, büyük harf ($P_\tau(\omega)$) Fourier dönüşümünü gösterir. İntegral $-\infty$'dan $+\infty$'a yazılır, ama işaret yalnız $-\tau/2$ ile $+\tau/2$ arasında 1'dir:

$$P_\tau(\omega) = \int_{-\tau/2}^{\tau/2} e^{-j\omega t}\,dt = \left[\frac{-1}{j\omega}e^{-j\omega t}\right]_{-\tau/2}^{\tau/2}$$

Sınırlar yerine yazılır ve ifade $2/\omega$ ile $2j$ etrafında düzenlenir:

$$P_\tau(\omega) = \frac{2}{\omega}\cdot\frac{e^{j\omega\tau/2} - e^{-j\omega\tau/2}}{2j}$$

İkinci çarpanın sinüs olduğu Euler formülünden görülür:

$$P_\tau(\omega) = \frac{2\sin(\omega\tau/2)}{\omega}$$

Bu ifade $\tau$ etrafında $\tau\,\dfrac{\sin(\omega\tau/2)}{\omega\tau/2}$ biçiminde de yazılır (ara adım eklendi). $\omega=0$'da değeri $\tau$'dur. Sayısal integral farklı $\tau$ ve $\omega$ değerlerinde formülle aynı sonucu verdi.

Hoca şekli anlatırken $\tau = 1/2$ için eğrinin $0.5$'ten başladığı ve salınımın $\pm 2/\omega$ zarfı içinde kaldığı söylendi. $\sin$ değeri $-1$ ile $+1$ arasında olduğu için bu doğrudan formülden gelir.

### 12.2 MATLAB'de $\sin t / t$

**Soru:** $\sin t / t$ çizilirse nasıl bir sonuç görülür? **Cevap:** Sönümlenen bir sonuç.

Hoca bunu MATLAB'de gösterdi. Burada $\sin t / t$, dönüşüm eğrisinin biçimini görmek için kullanılıyor. Önce `/` ile yazdı, sonuç beklenen olmadı. Vektörlerde eleman eleman bölme için `./` gerekir:

```matlab
clear all
t = 1:0.1:100;
x = sin(t);
y = x ./ t;
subplot(2,1,1); plot(x)
subplot(2,1,2); plot(y)
figure; stem(y)
```

Üstteki grafikte normal bir sinüs, alttakinde $t$ arttıkça sönümlenen sinüs görülür. `stem` ile çizildiğinde, buna frekans ekseni gibi bakılırsa, düşük frekanslarda genlik büyüktür, frekans arttıkça sönümlenir. Hoca bunun kare dalganın frekans düzlemi görüntüsüyle aynı karakterde olduğunu söyledi: Başlangıçta bir değer vardır, frekans arttıkça küçülür ve salınarak sıfıra iner.

Numpy ile aynı kod 991 örnek üretti. $t$ 1'den başladığı için ilk değer $\sin(1)/1 \approx 0.841$'dir, $t=0$ tepesi bu çizimde görünmez.

Slayttaki sinc fonksiyonu da aynı biçimdedir. Bilgisayarda çizilince ayrık noktalar çıkar, çünkü işlem ayrıktır: DC bileşen, 1 Hz bileşeni, 2 Hz bileşeni gibi. Çözünürlük ne belirlendiyse noktalar o aralıklarda olur.

> **Ders sonrası not:** Hoca dönüşümün çift taraflı görünmesini "karmaşık işaret olduğu için" diye açıkladı; bu darbe için doğru değildir. $t=0$ etrafında simetrik darbenin dönüşümü $2\sin(\omega\tau/2)/\omega$ tamamen gerçeldir, sayısal integralde de sanal kısım sıfır çıktı. İki tarafın görünmesinin sebebi $\omega$'nın negatif değerler de almasıdır ve eğri $\omega$'da çift fonksiyondur.

### 12.3 Seri ile Dönüşümün Mantığı

Hoca dönüşümün, işaret ne olursa olsun, başladığı noktaya $-\infty$, bittiği noktaya $+\infty$ dediğini ve işareti bu aralıkta tek bir periyotluk bir işaret gibi gördüğünü söyledi. Mantık bu yüzden seriyle aynıdır, yalnız incelenen işaretler farklıdır.

> **Ders sonrası not:** Hoca bu darbenin Fourier serileriyle bile ele alınabileceğini söyledi; tek bir darbe periyodik olmadığı için seri ancak darbenin periyodik tekrarına uygulanır. Dönüşüm tek darbeye doğrudan uygulanır.

## 13. Genlik ve Faz, FFT Denemeleri

### 13.1 Genlik ve Faz Grafikleri

Dönüşümün sonucu karmaşık olduğu için grafik çıkarmak için bazı ek işlemler gerekir. Hoca bu ders kapsamında daha çok genlikle (kendi ifadesiyle "real part") ilgileneceğimizi, ileri işaret işleme gibi derslerde ikisi üzerinde işlem yapıldığını söyledi.

Slayttaki $X(\omega)$ grafiğinde negatif değerler de görülüyordu. Faz grafiğinde değerler 0 ve $\pi$ idi. Negatif tarafı görmek istemiyorsak mutlak değer alınır. O zaman yalnız hangi frekans bileşenlerinin olduğu görülür: Örneğin 10 ve 20'de bileşen vardır, arada da başka bileşenler olabilir. Açı bilgisi ise frekans ile faz arasındaki değişimi radyan cinsinden gösterir.

> **Ders sonrası not:** Hoca "sanal kısmın negatifini alınca reel kısmın eşleniği elde edilir" dedi; doğrusu bu ifade geçerli değildir. Faz için hem reel hem sanal kısım kullanılır. Dikdörtgen darbede $P_\tau(\omega)$ gerçel olduğu için faz yalnız işarete bağlıdır: Pozitif yerde 0, negatif yerde $\pi$. Slayttaki 0 ve $\pi$ değerleri buradan gelir.

<!-- BELİRSİZ: 02:24:10 civarındaki slayt grafiklerinin eksenleri ve kullanılan örnek ayrıntısı altyazıda net değil. -->

### 13.2 MATLAB'de `abs(fft(x))`

MATLAB'de doğrudan "Fourier" diye yazınca bir şey çıkmaz. Bunun için FFT algoritması kullanılır. Hoca $x = \sin t$ işaretinin dönüşümünü çizdi. Sonuç karmaşık olduğu için mutlak değer aldı:

```matlab
subplot(2,1,1); plot(x)
subplot(2,1,2); plot(abs(fft(x)))
```

Grafikte iki tepe çıktı, biri pozitif taraf, biri negatif taraf. Sıfıra göre aynıdır. Sebep, işaretin tek bir frekanslı $\sin t$ olmasıdır, açısal frekansı 1'dir.

Numpy ile ($t = 1:0.1:100$, 991 örnek) tepeler 16. ve 975. indislerde çıktı.

> **Ek bilgi (derste anlatılmadı):** FFT çıktısında sıra $k = 0, 1, \dots, N-1$ biçimindedir ve dizinin ikinci yarısı negatif frekanslara karşılık gelir. Bu örnekte 975 indisi $975 - 991 = -16$ demektir. $k$. indisin frekansı $f_k = k/(N T_s)$'dir: $16/(991\cdot 0.1) \approx 0.161$ Hz, yani $\sin t$'nin frekansı olan $1/2\pi \approx 0.159$ Hz'e en yakın indis.

### 13.3 Düzensiz Görünen Kosinüs

Hoca daha sonra başka bir işaretle deneme yaptı. Amaç 100 frekanslı, genliği 10 olan bir kosinüs çizip dönüşümünü görmekti:

```matlab
t = 1:0.01:10;
x = 10*cos(2*pi*100*t);
plot(x)
```

Çizim beklendiği gibi çıkmadı. Hoca ifadeyi açısal frekans biçiminde değiştirdi, $t$ için adımı 0.1'e çıkardı (`t = 1:0.1:10`, 91 değer). Yine düzensiz bir eğri geldi. Sebep ders sırasında bulunamadı ve vakit kaybetmemek için geçildi.

<!-- BELİRSİZ: 02:27:13-02:30:29 arasında yazılan kosinüs ifadesi altyazıda bozuk; "2*pi*100*t" ile başlayıp "açısal frekans şeklinde" değiştirildiği anlaşılıyor, son biçimi kesin değil. -->

> **Ders sonrası not:** Sebep örnekleme aralığıdır. Numpy ile denendi: `10*cos(2*pi*100*t)` adım 0.1 ve 0.01 ile bütün örneklerde tam 10 verir, çünkü örnekler periyodun tam katlarına denk gelir. Bu durumda eğri düzensiz değil, düz çizgi olur. `10*cos(100*t)` ise adım 0.1 ile 8.62, $-9.99$, 8.14, $-3.67$, $-1.98$, 6.99 diye düzensiz değerler verir. Çünkü iki örnek arasında 10 radyan ilerlenir, bu da bir periyotta yaklaşık 2.45 örnek demektir. Hocanın ekranda gördüğü, açısal frekans diye yazdığı son ifade büyük olasılıkla budur. Her iki durumda da kök sebep aynıdır: Bu frekans için adım çok büyüktür ve örnekler dalgayı izleyemez.

## 14. $e^{-bt}u(t)$ İşaretinin Fourier Dönüşümü

### 14.1 Dönüşüm Tabloları

Hoca sinüs ve kosinüsün de periyodik olduğunu, ama örneklerde hep kare dalga kullanıldığını hatırlattı. $\sin t$ gibi bir işaretin dönüşümünü almanın daha kolay olduğunu söyledi. **Fourier dönüşüm tabloları** yaygın bilinen fonksiyonların frekans düzlemi karşılıklarını verir ve integrale gerek bırakmaz. Hoca kitapta da bulunan bir tabloyu ileride paylaşacağını söyledi.

> **Ders sonrası not:** Hoca $\sin t$'nin Fourier serisi açılımının "biraz daha uzun sürdüğünü" söyledi; doğrusu bu açılım en kısa olanlardandır. Euler formülünden $\sin t = \frac{1}{2j}e^{jt} - \frac{1}{2j}e^{-jt}$ doğrudan yazılır, integrale gerek kalmaz.

### 14.2 Türetme

Örnek işaret şudur:

$$x(t) = e^{-bt}u(t)$$

Dönüşümde sonuç $\omega$'ya bağlı olacaktır, $b$ sabit bir sayıdır. Tanımdan:

$$X(\omega) = \int_{-\infty}^{\infty} e^{-bt}u(t)\,e^{-j\omega t}\,dt$$

$u(t)$ alt sınırı $-\infty$'dan 0'a getirir ve integralden çıkar. Üsler birleştirilirken $-t$ ortak parantezine alınır, böylece iş kolaylaşır:

$$X(\omega) = \int_0^\infty e^{-(b+j\omega)t}\,dt = \left[\frac{e^{-(b+j\omega)t}}{-(b+j\omega)}\right]_0^\infty$$

Üst sınırda sonsuz yazılınca üstel terim sıfır olur. Alt sınırda $e^0 = 1$ gelir. Eksi eksiyle çarpılır:

$$X(\omega) = 0 - \frac{1}{-(b+j\omega)} = \frac{1}{b+j\omega}$$

Önde $A$ katsayısı olsaydı integralin dışına çıkar ve sonuç $\dfrac{A}{b+j\omega}$ olurdu.

Sayısal integral $b=1$ ve $b=5$ için çeşitli $\omega$ değerlerinde formülle aynı sonucu verdi.

**Soru:** Üs neden $-bt$ alınıyor, $+bt$ olursa integral neden alınamıyor? **Cevap:** Alan sonsuza gider. Alanı hesaplayamayız, yani dönüşüm yapamayız. Bu yüzden $b > 0$ olmalıdır.

### 14.3 Genlik ve Faz

Sonuç karmaşıktır, reel ve sanal kısmı vardır. Genlik, yani magnitüd (magnitude), pay ve paydanın mutlak değerlerinden gelir:

$$|X(\omega)| = \frac{1}{\sqrt{b^2 + \omega^2}}$$

Faz açısı da $\omega/b$ üzerinden gelir, negatif işaretlidir:

$$\angle X(\omega) = -\arctan\!\left(\frac{\omega}{b}\right)$$

Hoca paydayı açarken $j^2$'yi de andı; doğru yazım $|b+j\omega|^2 = b^2 + \omega^2$'dir, $j$ karenin içine girmez. Her iki formül de sayısal olarak doğrulandı.

Genlik eğrisinin davranışı formülden okunur. $\omega = 0$'da genlik $1/b$'dir, yani DC bileşen $1/b$ kadardır. $\omega$ arttıkça payda büyür ve genlik azalır.

### 14.4 MATLAB Denemesi

Hoca çizimi MATLAB'de denedi. $b$ yerine 5 verdi:

```matlab
t = 1:0.1:10;
x = exp(-5*t);
plot(t, x)
y = abs(fft(x));
hold on
plot(y, 'r')
```

İlk çizimde belirli bir noktadan başlayıp sönümlenen işaret görülür. FFT sonucunu aynı eksene kırmızı çizdirince iki tepe çıktı. Hoca bunlardan birinin frekans, diğerinin negatif karşılığı olduğunu söyledi. Sonra `fftshift` denedi. Bir tarafta sönüm, öbür tarafta aynı sönümü bekliyordu, ama yine tek taraf çizildi. Hoca sonra şu yorumu yaptı: İşaretin bir kısmı pozitif tarafı, öbür kısmı negatif tarafı gösterir. Bu taraf negatife alınırsa frekans düzlemindeki eğrinin aynısı elde edilir.

> **Ders sonrası not:** Hoca buradan "bir tane frekansı olduğunu görmüş olduk" sonucunu çıkardı; doğrusu $e^{-bt}u(t)$ tek frekanslı değildir, spektrumu sürekli yayılıdır. Numpy ile aynı kodda en büyük değer 0. indiste çıktı ve dizinin iki ucunda küçük frekanslar birikti, iki "tepe" bundan görülür. Altyazıya göre `fftshift` işareti doğrudan $x$'e uygulanmış; bu durumda kaydırılan zaman işaretidir ve tek taraf görünür. Doğru kullanım `abs(fftshift(fft(x)))` biçimindedir. Numpy'de bu biçim tepeyi ortaya (91 örnekte 45. indis) getirdi ve eğri iki yana simetrik çıktı.

### 14.5 $b$ Parametresinin Etkisi

Slaytta işaretin zaman düzlemi, genlik ve faz grafikleri vardı. Grafik yan yana analitik olarak negatif frekanstan pozitif frekansa çizilmişti. Faz için hazır `angle` fonksiyonu kullanılmıştı. Hoca adımların her tür işarete genelleştirilebileceğini söyledi.

$b=1$ iken frekans düzleminde görülen şey DC bileşene çok yakın, yapışık, genliği yüksek bir bileşendir. $b$ artırılınca sönüm hızı (decay rate) artar, işaret zamanda daha hızlı söner. Frekans düzleminde ise daha fazla bileşen işe karışır, yüksek frekanslar daha etkin olur. Yani spektrumda bir yayılma (spread) görülür.

### 14.6 Konvolüsyona Bağlantı

Hoca $y(t)$ olarak $\delta(t)$ örneğini anarak dönüşümün asıl kullanım alanını gösterdi. $x(t)$ ile $y(t)$'nin konvolüsyonu normalde konvolüsyon integraliyle bulunur. Fourier dönüşümü sayesinde bu integrale gerek kalmaz. İki işaretin dönüşümü alınır, doğrudan çarpılır, sonucun ters dönüşümü alınır. Bu yol çok daha kısadır:

$$x(t)*y(t) \quad\longleftrightarrow\quad X(\omega)\,Y(\omega)$$

Bölüm 1'deki ayrık örnek için dönüşüm çarpımının tersi numpy ile hesaplandı (4 noktalı FFT) ve yine $[1, 2, 2, 1]$ çıktı.

## 15. Temel Fourier Dönüşüm Çiftleri

> **Hocanın vurgusu:** Bu tablolar bizim için çok önemlidir. Yaygın bilinen fonksiyonların karşılıkları buradan okunur. Bu tabloyu çok kullanacağız.

### 15.1 Sabit İşaret: $1$

$-\infty$'dan $+\infty$'a sabit 1 olan işaretin dönüşümü, $\omega=0$'da $2\pi$ kadarlık bir darbedir:

$$1 \longleftrightarrow 2\pi\,\delta(\omega)$$

### 15.2 Birim Basamak: $u(t)$

Birim basamak işareti için integral 0'dan $\infty$'a yazılır:

$$\int_0^\infty e^{-j\omega t}\,dt = \left[\frac{e^{-j\omega t}}{-j\omega}\right]_0^\infty$$

Hoca üst sınırı sıfır aldı. Geriye $\dfrac{1}{j\omega}$ kaldı. Pay ve payda $j$ ile çarpılırsa $-\dfrac{j}{\omega}$ biçiminde de görülür. Hoca $\omega=0$'da $u(t)$'nin başındaki katsayıya bağlı bir bileşen olduğunu da söyledi ve bizim için lazım olan kısmın $\dfrac{1}{j\omega}$ olduğunu belirtti. $u(t)$'ye bir sabit eklenirse değişen, $\omega=0$'daki bileşendir.

Tablodaki tam çift şudur:

$$u(t) \longleftrightarrow \pi\,\delta(\omega) + \frac{1}{j\omega}$$

> **Ders sonrası not:** $e^{-j\omega t}$'nin $t \to \infty$ limiti olağan anlamda sıfır değildir, salınır. Bu yüzden integral doğrudan alınmaz. Hocanın bıraktığı yol $e^{-bt}u(t)$ çiftinde $b \to 0$ alınmasıyla tamamlanır: $\frac{1}{b+j\omega}$ ifadesinin sanal kısmı $1/(j\omega)$ terimini, reel kısmı $\frac{b}{b^2+\omega^2}$ ise $\omega=0$'daki darbeyi verir. Bu reel kısmın alanı $b = 1$, $0.1$, $0.01$ için sayısal olarak $\pi$ çıktı, yani darbenin ağırlığı $\pi$'dir.

### 15.3 Birim Darbe: $\delta(t)$

$\delta(t)$ yalnız $t=0$'da çalışır, $-\infty$ ve $+\infty$ kısmı yoktur. Bu yüzden integralde $t=0$ yazılır, $e^{0} = 1$ kalır:

$$\mathcal{F}\{\delta(t)\} = \int_{-\infty}^{\infty} \delta(t)\,e^{-j\omega t}\,dt = 1$$

$$\delta(t) \longleftrightarrow 1$$

### 15.4 Kosinüs

Önce formül çıkarılır. Euler açılımları yazılır:

$$e^{j\omega_0 t} = \cos\omega_0 t + j\sin\omega_0 t, \qquad e^{-j\omega_0 t} = \cos\omega_0 t - j\sin\omega_0 t$$

İkisi toplanınca sinüsler gider:

$$\cos\omega_0 t = \frac{e^{j\omega_0 t} + e^{-j\omega_0 t}}{2}$$

İntegrale yerleştirilir:

$$\mathcal{F}\{\cos\omega_0 t\} = \frac12\int_{-\infty}^{\infty} e^{j\omega_0 t}e^{-j\omega t}\,dt + \frac12\int_{-\infty}^{\infty} e^{-j\omega_0 t}e^{-j\omega t}\,dt$$

Üsler ortak parantezde birleşince $e^{-j(\omega-\omega_0)t}$ ve $e^{-j(\omega+\omega_0)t}$ gelir. Her biri, $\omega_0$ kadar kaymış bir darbe verir:

$$\cos\omega_0 t \longleftrightarrow \pi\left[\delta(\omega-\omega_0) + \delta(\omega+\omega_0)\right]$$

Yani frekans düzleminde biri $+\omega_0$'a, diğeri $-\omega_0$'a kaymış iki darbe görülür. Bu, kosinüsün tek bir frekans bileşeni olduğunu söyler. Örneğin 300 Hz veya 500 Hz'lik işarette tam o frekansta tepe görülür. Fourier serisi de zaten bu tepeleri bulmayı sağlıyordu.

> **Ders sonrası not:** Altyazıda bu integralin sonucu için "bir bölü omega kare" gibi bir ifade geçiyor; doğrusu kosinüs dönüşümünde böyle bir terim yoktur, yukarıdaki iki darbe gelir.

> **Ek bilgi (derste anlatılmadı):** Bu integraller olağan anlamda yakınsamaz. Sonucun kaynağı $\int_{-\infty}^{\infty} e^{-j\omega t}\,dt = 2\pi\,\delta(\omega)$ eşitliğidir. Sayısal kontrol için işaretler geniş bir Gauss pencereyle çarpıldı ve frekansta darbenin çevresindeki alan ölçüldü: $1$ için $\omega=0$'da $2\pi$, $\cos\omega_0 t$ için $\pm\omega_0$'da $\pi$, $\sin\omega_0 t$ için $+\omega_0$'da $-j\pi$ ve $-\omega_0$'da $+j\pi$, $e^{j\omega_0 t}$ için $+\omega_0$'da $2\pi$ çıktı.

### 15.5 Sinüs

Sinüsün farkı, sanal katsayıya sahip olmasıdır. Önüne $j$ gelir, darbelerin biri artı, biri eksi işaretlidir:

$$\sin\omega_0 t \longleftrightarrow j\pi\left[\delta(\omega+\omega_0) - \delta(\omega-\omega_0)\right]$$

### 15.6 Karmaşık Üstel

Daha önce konuşulan üstel çift de şudur:

$$e^{j\omega_0 t} \longleftrightarrow 2\pi\,\delta(\omega-\omega_0)$$

Yani frekansı $\omega_0$ olan yerde $2\pi$ büyüklüğünde bir tepe görülür.

### 15.7 Özet Tablo

| $x(t)$ | $X(\omega)$ |
|---|---|
| $1$ | $2\pi\,\delta(\omega)$ |
| $\delta(t)$ | $1$ |
| $u(t)$ | $\pi\,\delta(\omega) + \dfrac{1}{j\omega}$ |
| $e^{-bt}u(t)$, $b>0$ | $\dfrac{1}{b+j\omega}$ |
| $p_\tau(t)$ | $\dfrac{2\sin(\omega\tau/2)}{\omega}$ |
| $e^{j\omega_0 t}$ | $2\pi\,\delta(\omega-\omega_0)$ |
| $\cos\omega_0 t$ | $\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$ |
| $\sin\omega_0 t$ | $j\pi[\delta(\omega+\omega_0)-\delta(\omega-\omega_0)]$ |

> **Hocanın vurgusu:** Bizim için önemli olan bu integralleri almak değildir. Önemli olan, Fourier dönüşümünden elde edilen sonucu yorumlamak ve başka işlemlerde kullanmaktır. En basiti konvolüsyon işleminde kullanmak olacaktır.

## Dersin Toparlaması

Ders, ayrık konvolüsyonda sıfır noktasının bulunmasıyla başladı: Sayısal değerler sıfır noktasının seçiminden etkilenmez, ama indisler etkilenir. İndis, darbe gösterimi ve dağılma özelliğiyle ya da sınırları toplayarak bulunur. Ardından ayrık zamanda periyodikliğin tam sayı periyot gerektirdiği hatırlatıldı. Fourier serisinin kullanım alanı ses, tını ve spektrogram üzerinden görüldü. Kare dalga, $\sin^3(3\pi t)$ ve yarım dalga doğrultulmuş sinüs örnekleriyle analiz ve sentez işlendi, süreksizlik yanındaki Gibbs taşması gösterildi.

Sonra periyodik olmayan işaretler için Fourier dönüşümüne geçildi. Dönüşümün sonucunda $t$ kalmadığı, tersinin bulunduğu ve FFT'nin hesabı $O(N\log N)$'e indirdiği görüldü. Dikdörtgen darbeden sinc biçimi, $e^{-bt}u(t)$'den $1/(b+j\omega)$ çifti, genlik ve faz grafikleri ile temel dönüşüm çiftleri elde edildi. Hoca konunun ayrıntılarına öğleden sonraki oturumda devam edileceğini söyledi. Bundan sonra kullanılacak ana araç dönüşüm tablolarıdır, özellikle konvolüsyonu dönüşüm düzleminde çarpmayla yapmak için.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
