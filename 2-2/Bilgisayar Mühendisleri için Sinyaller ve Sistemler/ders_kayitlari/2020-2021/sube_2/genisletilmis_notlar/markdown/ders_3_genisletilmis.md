# Ders 3 Genişletilmiş Notu: Frekans Domeni, Sinyallerin Sınıflandırılması ve Sinyaller Üzerinde Temel İşlemler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sistemi Giriş ve Çıkıştan Tanımak
- 2. Neden Frekans Domeni?
- 3. Frekans Domeninin Uygulamaları
- 4. Diferansiyel Denklemler, Transfer Fonksiyonu ve Kontrol
- 5. Sinyallerin Sınıflandırılması
- 6. Çift-Tek Ayrıştırması
- 7. Deterministik ve Rastgele Sinyaller, Bir Örnek
- 8. MATLAB ile Sinyal Çizimi
- 9. Sinyal ve Sistem Türleri
- 10. Sinyaller Üzerinde Temel İşlemler
- 11. Periyodik Sinyaller
- 12. Karmaşık Sinyaller ve Karmaşık Sayılar
- 13. Sinyal Enerjisi ve Gücü
- Örnek Sorular

## 1. Sistemi Giriş ve Çıkıştan Tanımak

Ders, bir önceki derste kalınan "Neden frekans domeni?" sorusuyla başladı. Bir sistemin davranışını incelemenin ilk yolu, sisteme bir giriş uygulayıp elde edilen çıkışa bakmaktır. Farklı girişlerle bu işlem tekrarlanınca giriş ile çıkış arasındaki ilişkiden bir model ortaya çıkar.

Hocanın verdiği basit örnekte tek girişli, tek çıkışlı bir sistem vardır:

| Giriş | Çıkış |
|---|---|
| 1 | 2 |
| 2 | 4 |
| 3 | 6 |
| 4 | 8 |

Bu tablodan sistemin girişin iki katını alan bir sistem olduğu hemen anlaşılır. Derste bağımsız değişken çoğunlukla zaman ($t$) olacaktır; bağımlı değişken ise gerilim, akım ya da ses bilgisi gibi büyüklüklerdir. Ancak her sistemin davranışı girişlere bakarak bu kadar kolay çözülemez. Bu durumda sinyale ve sisteme farklı bir açıdan bakmak gerekir.

Hoca bunu bir kağıt paraya benzetti: paranın ön yüzünden kaç TL olduğu, arka yüzünden başka ayırt edici özellikleri görülür. Aynı sinyale zaman açısından ve frekans açısından bakmak da aynı nesnenin iki farklı yüzüne bakmak gibidir.

## 2. Neden Frekans Domeni?

### 2.1 Sinyali Sinüzoidallerin Toplamı Olarak Görmek

Hoca internette "Fourier decomposition" görsellerinden birini açarak, günlük hayatta karşılaşılan karmaşık görünümlü bir sinyalin frekans düzleminde bilinen sinüzoidallerin (örnekte 11 tane) toplamı olarak ifade edilebildiğini gösterdi (ekrandan, 00:25:00). Bu sinyali analiz etmek, bu bilinen sinüzoidalleri analiz etmekle aynı anlama gelir. Böylece sinyalin temel frekansı, hangi frekansları içerdiği, düşük ya da yüksek frekansların baskın olup olmadığı anlaşılır.

Slayttaki örnek üç sinüzoidalin toplamıdır (ekrandan, 00:30:00):

$$f(t) = 0{,}1\sin(\omega_1 t) + 0{,}7\sin(\omega_2 t) + 0{,}2\sin(\omega_3 t)$$

Hoca slayta $\omega_1 = 2\pi f_1$ ilişkisini yazdı: biri açısal, diğeri çizgisel frekanstır. Her sinüzoidal bileşenin üç özelliği vardır: **genlik**, **frekans** ve **faz**. Üç bileşenli bu sinyalde $3 \times 3 = 9$ bilgi bulunur ve bunlar sinyal frekans düzleminde ayrıştırılarak elde edilir. Denklemi bilinen bir sinyalde bu bilgiler gözle okunabilir; gerçek dünyada kaydedilen bir sinyalde ise bu mümkün değildir. Hoca örnek olarak mikrofonu hoparlöre yaklaştırınca çıkan cızırtıyı verdi: bu çok yüksek frekanslı bir sinüzoidal dalgadır ve analiz edilince genlik, frekans ve faz bilgisi elde edilir.

### 2.2 Müzik Türü Sezgisi

Hoca öğrencilere şu soruyu sordu: biri metal, biri klasik müzikten elde edilmiş iki sinyalin frekans bileşenlerinin aritmetik ortalaması alınırsa hangisininki daha yüksek olur? Öğrencilerin cevabı metaldi; gerekçe olarak "daha çok değişim" ve "hızlı olması" söylendi. Hoca bunu onayladı: hız ve değişim, frekansın daha yüksek olduğunu gösterir.

Hoca verdiği sayıların tamamen uydurma olduğunu belirterek klasik müzik için yaklaşık 50 Hz, caz için 60 Hz, metal için belki 300 Hz gibi ortalamalar olabileceğini söyledi. Böylece dalga formundan çok frekans bileşenlerinden fikir çıkarılır: iki ses dosyası verilip etiketlenmesi istenirse, frekans ortalaması yüksek olana "hızlı olan, büyük olasılıkla metal", düşük olana "klasik" demek makul bir tahmindir.

**Soru:** Bazı klasik eserler (örneğin bazı Vivaldi eserleri) birçok metal parçadan daha hızlı olamaz mı? **Cevap:** Hoca bunun doğru olduğunu, söylenenin genel bir eğilim olduğunu kabul etti.

Hoca, insan sesinin ve notaların da bazı temel seslerin, yani harmoniklerin birleşiminden oluştuğunu, örneğin bir Do notasının belirli sayıda sinüzoidalin birleşimi olduğunu ekledi. Frekans domeninde işi tersinden yürüterek sistemlerin ve verilerin özellikleri üzerinde analiz yapılabilir.

## 3. Frekans Domeninin Uygulamaları

### 3.1 Ayırt Edici Özellik Çıkarma

Konuşmacı tanıma (speaker recognition) örneğinde, telefonla bankaya bağlanınca ses bir kez kaydedilir ve daha sonra ses bir imza gibi tanınır. Görüntü işlemede yüzden ayırt edici özellikler çıkarıldığı gibi, seste de ayırt edici özellik çıkarma (feature extraction, distinctive feature extraction) yapılır; bunun temeli frekans analizidir.

Hoca ileride sinyallerin her zaman periyodik olmayacağını, hangi zaman aralığında hangi frekans bileşenlerinin baskın olduğunun da inceleneceğini söyledi. Radyo sinyalleri de sinüzoidaller cinsinden üretilir ve belirli bir frekansı vardır (FM, AM). Özellikle doğrusal (lineer) sistemler bu açıdan rahatça analiz edilir ve frekans analizi sistemin temel karakteristiğini ortaya çıkarır.

Bir başka örnek araç rulman arızalarıdır. Basınç, sıcaklık gibi çok sayıda parametre girişi ve "arıza var/yok" çıkışı olan bir sistem düşünülür. Veri bir tablo gibi toplanır; sistem çok boyutlu bir zaman serisi gibi frekans düzleminde incelenince arızaya neden olan etkenleri tespit etmeye yönelik özellikler ortaya çıkar.

### 3.2 Enstrümanlar ve Saf Ton

Hoca bir web sayfasında farklı enstrümanların ses örneklerini açtı (ses öğrencilere ulaşmadı). Elektronik olarak üretilmiş saf bir ton (pure tone) frekans düzlemine geçirilince tek bir frekans bileşeni görülür; hoca buna yaklaşık 1000 Hz, yani 1 kHz dedi. Obua, klarnet gibi enstrümanlarda ise birden fazla bileşen vardır ve bileşenler enstrümana göre farklıdır. Bu sayede aynı nota çalınsa bile sesin hangi enstrümandan geldiği bilgisayarla tahmin edilebilir.

Piyanoda bir tuşa basılınca sesin bir atak (attack) anı, ardından hafif bir sönüm, bir plato ve sonunda tamamen sönme aşaması vardır. Hoca buna ADSR zarfı dendiğini hatırlattı.

> **Ek bilgi (derste anlatılmadı):** ADSR kısaltması büyük olasılıkla attack (atak), decay (sönüm), sustain (sürdürme) ve release (bırakma) aşamalarını ifade eder. Derste attack ve decay adları açıkça geçti.

Bu zarfın belirli bir zaman dilimi (örneğin 0,7-0,8 saniye arası) frekans analizine sokulunca enstrüman tahmini, nota tahmini, müzik türlerinin ayırt edici özellikleri ve insan sesine dair bilgiler çıkarılabilir. Hoca stetoskop kayıtlarının incelenerek yorgunluk seviyesinin ya da zatürre olup olmadığının tahmin edilmesini de örnek verdi.

### 3.3 Piyano Akoru

Slayttaki örnekte bir piyano akorunun zaman serisi grafiği akorun başladığı anı ve sönümünü gösterir, ama dalga biçiminden hangi notaların çalındığı anlaşılmaz (ekrandan, 00:40:00). Dalga biçimi farklı frekanslardaki sinüzoidallerin toplamı olarak gösterilip her frekanstaki genlik çizilince grafik çok daha kolay okunur. Slayttaki ilk grafik $-5000$ ile $5000$ Hz arasında simetrik tepeler, ikinci grafik $0$-$1500$ Hz arasında birkaç belirgin tepe (yaklaşık 300-800 Hz arasında güçlü tepeler) gösterir.

Hoca CD kalitesinin saniyede 44.100 örnek olduğunu hatırlattı. Bir saniyelik müzik için bile çok uzun bir dizi elde edildiğinden zaman üzerinden analiz güçtür; hangi frekansların ortaya çıktığını bulmak frekans düzleminde daha kolaydır. Sinyaller doğal sinyallerden oluşuyorsa bu iş daha da avantajlıdır. Hoca doğal sinyalin temel halinin kosinüs olduğunu, sinüsün ondan 90 derece faz farkıyla türetildiğini söyledi. Bir sinyal sinüzoidaller cinsinden az bir bilgi kaybıyla bile ifade edilebiliyorsa, onun üzerinden çok ciddi çıkarımlar yapılabilir.

## 4. Diferansiyel Denklemler, Transfer Fonksiyonu ve Kontrol

### 4.1 Arabanın Kaldırıma Çıkması

Slayttaki örnekte bir arabanın kaldırıma (curb) çıkınca nasıl bir cevap vereceği tahmin edilmek istenir (ekrandan, 00:45:00). Giriş bir basamak (step) biçimindedir, araba dinamiği diferansiyel denklemlerle modellenir ve çıkış bir salınım yapıp oturan bir eğridir. Basamak fonksiyonları ileride görülecektir.

Sistemin davranışı $y'' + y' = \dots$ gibi bir diferansiyel denklemle veriliyorsa, aslında istenen $y = f(x)$ biçiminde bir çözümdür. Diferansiyel denklemleri çözmek, özellikle yüksek mertebelerde ve çok değişkende zordur. Frekans domeninde ise yol şöyledir:

```text
Giriş (zaman domeni) --> Frekans domeni girişi
Diferansiyel denklem  --> Transfer fonksiyonu (model)
Frekans domeni girişi x Transfer fonksiyonu --> Frekans domeni çıkışı
Frekans domeni çıkışı --(ters dönüşüm)--> Zaman domeni çıkışı
```

Slaytta transfer fonksiyonu kutusunun altında "Easy to Solve, Multiplication" yazar; frekans domenindeki çıkışı bulmak kolaydır, zaman domenindeki çıkış ters dönüşümle bulunur. Hoca slayttaki diferansiyel denklem kutusuna "Model" yazdı: genel olarak sistemin davranışına model denir ve bu model sürekli sistemlerde transfer fonksiyonu adını alır. Türevlerin frekans domeninde belirli karşılıkları vardır ve bunlar ileride tablolarla görülecektir. Böylece diferansiyel denklem çözmek yerine "bilinenler bir tarafa, bilinmeyenler bir tarafa" türünden cebirsel işlemlerle sonuca ulaşılır.

Hoca ileride Laplace ve Fourier dönüşümlerinin anlatılacağını, frekans domenine geçişin hem çıkışı tahmin etmeyi hem de sistemlerin kararlılığı gibi konuları kolaylaştırdığını söyledi.

### 4.2 Hız Kontrolü ve PID

Frekans domeni doğrusal sistemlerin kontrolünü de kolaylaştırır: uçağın uçuş yüksekliğini, arabanın sabit hızını ya da sıcaklığın belli bir değerde kalmasını sağlamak gibi. Slayttaki örnekte arabaya gaz verilince hız artar; normalde sürücü göstergeye bakıp gazı ayarlayarak döngüyü kapatır ("close the loop") (ekrandan, 00:50:00). Slaytın sorusu şudur: bu otomatik nasıl yapılır?

Hoca, örneğin hızı 68'de sabit tutmayı elle yapmanın zor olduğunu, bunu yakıtı en az harcayarak otomatik yapan yapının bir kontrolör olduğunu söyledi ve slayta "PID Cont." yazdı. Çıkış önce hedefin üstüne çıkar, sonra salınarak hedefe oturur. Hocanın benzetmesiyle, bir hedefe ulaşmaya çalışırken önce hatalar yapılır, bu hatalar toplanır (integral) ve hataların değişimine bakılarak (türev) gelecekteki hatalar azaltılır; sonunda çıkış belirli bir düzeye oturur. Bu konuyu en çok kontrol ve otomasyon mühendisleri kullanır.

Hoca aynı mantığı göz bebeği tespitine bağladı. Bir fotoğrafta gözün içindeki iris ve pupil bulunmak istenir. Kare biçiminde bir maske görüntüde dolaşır, bulunduğu yerdeki renk değerlerini toplar ve bir önceki konumdaki toplamla karşılaştırır. Daha karanlık bir noktaya gelindiğinde ve bir sonraki adım daha kötü sonuç verdiğinde durulur; göz bebeği bulunmuştur. Burada da toplama (integral) ve karşılaştırma (türev) benzeri bir geri besleme vardır. Hoca, bilgisayar mühendisleri için frekans analizinin asıl kullanım alanının veri setlerinden ayırt edici özellik çıkarmak olduğunu vurguladı.

## 5. Sinyallerin Sınıflandırılması

### 5.1 Sürekli Zaman ve Ayrık Zaman

Slayta göre bu sınıflandırma, zaman ekseninin ayrık (sayılabilir) mı sürekli mi olduğuna göre yapılır (ekrandan, 00:55:00). Sürekli zaman sinyali zaman ekseni boyunca bütün gerçek sayılar için bir değer alır. Ayrık zaman sinyali çoğunlukla sürekli bir sinyalin örneklenmesiyle elde edilir ve yalnız zaman ekseninde eşit aralıklı noktalarda değer alır.

> **Hocanın vurgusu:** Slayttaki "As the names suggest" ifadesindeki "suggest" burada "önermek" anlamında değildir. Bilimsel metinlerde "ortaya koymak, belirtmek, açıklamak" (reveal, disclose) anlamında kullanılır. Hoca sınav sorularında da bu kelimeyi kullandıklarını belirtti.

Hoca ekrandaki çizimin gerçek anlamda sürekli olmadığını, çünkü bir çizim olduğunu; sürekli sinyali ifade edenin formül olduğunu söyledi. Slayttaki örnek şudur:

$$x(t) = 3\cos\!\left(2\pi\cdot 2\cdot t - \frac{3\pi}{4}\right)$$

Hoca bu sinyalin frekansını sordu. Bir öğrenci önce "$2t$" dedi; hoca frekansın $2t$ olamayacağını söyledi. Ardından bir öğrenci doğru cevabı verdi: frekans 2, faz $3\pi/4$. Slayttaki değerler (ekrandan, 00:55:00):

- Genlik $A = 3$
- Frekans $f_0 = 2$ Hz
- Faz $\phi = 3\pi/4$ (slayttaki yazım)
- Periyot $T_0 = 1/f_0 = 0{,}5$ s

Grafikte ilk tepe $t = 3/16$ s'de, bir sonraki tepe $3/16 + 1/2$ s'dedir ve aradaki uzaklık bir periyottur. Kontrol: tepe noktasında kosinüsün argümanı sıfır olmalıdır, $4\pi t - 3\pi/4 = 0 \Rightarrow t = 3/16$ (ara adım eklendi). Hoca, frekans bilinmese de grafikte bir periyodun başlangıç ve bitiş zamanları biliniyorsa periyodun oradan da bulunabileceğini söyledi.

> **Ders sonrası not:** Slaytta faz $\phi = 3\pi/4$ olarak yazılmış ve derste de böyle söylendi. $A\cos(2\pi f_0 t + \phi)$ biçimine göre formüldeki faz $\phi = -3\pi/4$'tür; $3\pi/4$ fazın büyüklüğüdür. Tepenin $t = 3/16$'da olması da $-3\pi/4$ fazıyla tutarlıdır.

Ayrık sinyal bağımsız değişken ekseninde sürekli olmayan, belirli aralıklardaki değerlerden oluşur. Örnekler arasındaki değerler kaçırılabilir ve bir miktar bilgi kaybı olabilir; buna karşılık veri bilgisayarla ya da sayısal işaret işlemciyle daha hızlı işlenir. Sürekli sinyali doğrudan işlemek çoğu zaman mümkün değildir.

### 5.2 Analog ve Dijital

Analog ve dijital kavramları sürekli ve ayrık kavramlarına benzer, ama küçük bir fark vardır. Analog sinyal sürekli sinyalin fonksiyon değerlerine doğrudan karşılık gelir. Dijital sinyal ise hem zamanda hem genlikte ayrıktır; değerleri 0 ve 1'ler cinsinden, ikili (binary) olarak ifade edilir. Ayrık bir sinyal 0 ve 1'ler cinsinden kodlanınca dijital sinyal haline gelir.

### 5.3 Periyodik ve Aperiyodik

Periyodik sinyal kendini belirli aralıklarla tekrar eden sinyaldir; aperiyodik (non-periodic) sinyal tekrar etmez (ekrandan, 01:00:00). Hoca tanımı slayta şöyle yazdı:

$$f(x) = f(x + T_0) \quad \forall t$$

Slaytta tanım $f(t) = f(t+T)$ biçimindedir; burada $t$ herhangi bir sayı, $T$ pozitif bir sabittir. Eşitlik sinyalin başından sonuna bütün değerler için sağlanmalıdır. Eşitliği sağlayan en küçük $T$ temel periyottur (fundamental period); bundan temel frekans bulunur. Hoca temel frekansın ayırt edici bir özellik olarak kullanıldığını, örneğin kişilerin seslerini ayırt eden çalışmalarda temel frekanstan yola çıkıldığını söyledi.

### 5.4 Nedensel, Antinedensel ve Nedensel Olmayan

Slayttaki tanımlar şöyledir (ekrandan, 01:05:00):

- **Nedensel (causal) sinyal:** bütün negatif zamanlarda sıfırdır.
- **Antinedensel (anticausal) sinyal:** bütün pozitif zamanlarda sıfırdır.
- **Nedensel olmayan (noncausal) sinyal:** hem pozitif hem negatif zamanda sıfırdan farklı değerler alır.

Bu bölümde terimin yazılışı ve okunuşu tartışıldı. Doğru terim "causal" (nedensel) olup "casual" (gündelik, sıradan) ile karıştırılmamalıdır; iki kelimede "u" ile "s" harflerinin yeri farklıdır. Bir öğrenci terimin daha önce "casual" diye yazılıp okunduğunu ve "olağan" diye açıklandığını söyledi; hoca ve öğrenciler doğrusunun "causal" ve anlamının nedensellik olduğunda birleştiler.

Hoca nedenselliği şöyle açıkladı: şu anki durum bir önceki ya da daha önceki durumlara bağlıysa sistem nedenseldir. Örnek olarak $y[n] = x[n-1] + x[n]$ gibi, çıkışın şimdiki ve bir önceki girişe bağlı olduğu ifadeler verdi. Sinyal açısından nedensellik, $t = 0$ anından önce herhangi bir değer olmaması demektir. Bu ayrım önemlidir çünkü nedensel sistemlerin denklem çözüm yöntemleri diğerlerinden farklıdır; ileride nedensel doğrusal sistemler incelenecektir. Hoca slayttaki grafiksel örneğin nedenselliği tek başına iyi anlatmadığını, denklem biçiminde verilince daha iyi anlaşılacağını söyledi.

### 5.5 Çift ve Tek

Bir sinyal için $f(t) = f(-t)$ sağlanıyorsa sinyal çifttir; düşey eksene göre simetriktir. $f(t) = -f(-t)$ sağlanıyorsa sinyal tektir. Hoca Laplace ve Fourier görülünce çift sinyallerin analizinin daha kolay olduğunun görüleceğini söyledi.

## 6. Çift-Tek Ayrıştırması

Çift ve tek sinyal tanımları kullanılarak her sinyalin bir çift ve bir tek sinyalin toplamı olarak yazılabileceği gösterilir. Yani her sinyalin bir tek-çift ayrıştırması vardır. Bunu göstermek için tek bir denklem yeterlidir (ekrandan, 01:10:00):

$$f(t) = \frac{1}{2}\big(f(t) + f(-t)\big) + \frac{1}{2}\big(f(t) - f(-t)\big)$$

Sağ taraf açılınca $\tfrac{1}{2}f(t) + \tfrac{1}{2}f(t) = f(t)$ kalır ve $f(-t)$ terimleri birbirini götürür. $f(t)+f(-t)$ çift fonksiyon koşulunu, $f(t)-f(-t)$ tek fonksiyon koşulunu sağlar:

$$f_e(t) = \frac{1}{2}\big(f(t) + f(-t)\big), \qquad f_o(t) = \frac{1}{2}\big(f(t) - f(-t)\big)$$

Hoca grafik bir örnekle açıkladı: bir sinyal kendi zamanda ters çevrilmiş haliyle toplanınca iki yana doğru simetrik rampalardan oluşan çift bir sinyal elde edilir; sinyalden ters çevrilmiş hali çıkarılınca tek sinyal elde edilir. Çift ve tek parçalar toplanınca orijinal sinyal geri gelir. Hoca derste bu ayrıştırmayla çok uğraşılmayacağını, asıl fikrin bir sinyalin daha basit sinyaller cinsinden ifade edilebilmesi olduğunu söyledi.

## 7. Deterministik ve Rastgele Sinyaller, Bir Örnek

### 7.1 Tanımlar

Deterministik sinyalin her değeri sabittir; bir matematiksel ifade, kural ya da tabloyla tanımlanır. Örneğin $\sin(2\pi\cdot 2t)$ sinyalinde $t$'ye aynı değer verildikçe hep aynı sonuç elde edilir. Rastgele (random, stokastik) sinyalde ise aynı $t$ için her denemede farklı sonuçlar çıkar; bu sinyaller bir formülle kesin olarak ifade edilemez ve belirli bir değişkenlik gösterir. Hoca günlük hayatta rastgele sinyallerin daha yaygın olduğunu söyledi.

### 7.2 Örnek: $\sin(2\pi t)/t$

Slayttaki örnek (ekrandan, 01:15:00):

$$f(t) = \begin{cases} \sin(2\pi t)/t, & t \ge 1 \\ 0, & t < 1 \end{cases}$$

Soru bu sinyalin özelliklerini yazmaktır. Slayttaki cevap ve hocanın açıklaması (ekrandan, 01:20:00):

- **Sürekli zaman:** sinyal zamanın sürekli bir fonksiyonudur.
- **Analog:** genlik değerleri süreklidir.
- **Aperiyodik:** $\sin(2\pi(t+T))/(t+T)$ hiçbir $T$ için $\sin(2\pi t)/t$'ye eşit olmaz. Sinyal $t$ büyüdükçe sönümlenir.
- **Sonsuz uzunluklu:** zamanda sonsuza kadar sürer.
- **Nedensel:** $t<1$ için sıfırdır, yani negatif zamanda değeri yoktur.
- **Ne çift ne tek:** bir sinyal çift ya da tek olmak zorunda değildir.
- **Deterministik:** bir denklemle tanımlanmıştır; aynı $t$ için hep aynı değeri verir.

**Soru:** Bu sinyalin aperiyodik olduğu yalnız gözlemle mi anlaşıldı? **Cevap:** Hoca en basit testin tanımı uygulamak olduğunu söyledi: $t$ yerine $t + T$ yazılır ve eşitliğin her $t$ için sağlanıp sağlanmadığına bakılır. Tecrübeye dayalı bir yorum da vardır: $\sin(2\pi t)$ kendi başına periyodiktir, ama paydaki $t$ işi bozar. Sinüsün değeri $1/t$ ile çarpılıp sürekli küçüldüğü için sinyal hiçbir zaman aynı değere dönmez.

## 8. MATLAB ile Sinyal Çizimi

### 8.1 Kaynaklar Üzerine Kısa Not

Ders arasından sonra hoca dersin ana kaynağının DSP First (Signal Processing First) kitabı ve MIT ders notları olduğunu, ayrıca Luis Chaparro'nun "Signals and Systems Using MATLAB" kitabını önerdiğini söyledi (ekrandan, 01:45:00). Türkçe kaynak olarak sayısal işaret işleme kitaplarından söz etti, ama dersi takip etmenin ve kitaplardaki çalışma sorularını çözmenin yeterli olacağını belirtti.

### 8.2 MATLAB'ın Özellikleri

Hoca MATLAB Online'ı açarak dili tanıttı (ekrandan, 02:00:00). MATLAB yorumlanan bir dildir; hem paket program hem programlama dili gibi kullanılır. `.m` dosyalarında betikler (script) yazılıp çağrılabilir. Matris tabanlıdır: değişkenler, tek eleman olsa bile, vektör ya da matris olarak tutulur. İki dizi `for` döngüsüne gerek kalmadan vektörel olarak toplanabilir ya da çarpılabilir; bu paralel işleme yeteneğini artırır. Genel sözdizimi C'ye benzer. Satır sonuna noktalı virgül konmazsa sonuç ekrana basılır; `clc` ekranı, `clear all` çalışma alanını (workspace) temizler. Workspace panelinde değişkenlerin boyutu ve tipi görülür, değerleri değiştirilebilir.

MATLAB'a finans, yapay sinir ağları, sinyal işleme, kontrol, görüntü ve ses işleme gibi alanlarda araç kutuları (toolbox) eklenir. Hoca ayrıca Neural Network uygulamaları ve PID Tuner gibi hazır uygulamaların kod yazmadan kullanılabildiğini gösterdi. Benzer işlemler Python'da da yapılabilir, ama bu ders MATLAB üzerine yoğunlaşmıştır.

### 8.3 Önceki Örneğin Kodu

Slayttaki kod, Bölüm 7.2'deki sinyali çizer (ekrandan, 01:35:00 ve 02:00:00):

```matlab
% Code written for Last Example in Lecture1
clc
clear all
close all
t1 = 1:0.01:10;
t2 = -10:0.01:1-0.01;
timeAxis = [t2 t1];
MySignal = [zeros(1,length(t2)) sin(2*pi*t1)./t1];
plot(timeAxis,MySignal)
ylabel('Amplitude','fontsize',20)
xlabel('time','fontsize',20)
title('My First Signal','fontsize',20)
```

`t1` 1'den 10'a 0,01 adımla 901 eleman, `t2` $-10$'dan $0{,}99$'a 1100 eleman içerir; `timeAxis` bu ikisini birleştirir ve 2001 elemanlıdır (ekrandan, 02:00:00, workspace değerleri). Hoca bunun bir tür örnekleme olduğunu, ama derste kastedilen örneklemeyle tam aynı olmadığını söyledi. `MySignal`'in ilk kısmı `t2` uzunluğunda sıfırlardan, ikinci kısmı `sin(2*pi*t1)./t1` değerlerinden oluşur. Komut satırında yazılırken köşeli parantez satır ortasında kapandığı için hata alındı; bir öğrencinin uyarısıyla parantezin iki parçayı birlikte kapsaması gerektiği düzeltildi.

`./` işleci eleman eleman bölmedir. Çizim sönümlenen bir sinüs verir; `./t1` kaldırılınca hiç sönümlenmeyen bir sinüs elde edilir ve sinyal periyodik olur. Hoca bunu bir öğrencinin aperiyodiklik sorusuna cevap olarak gösterdi.

### 8.4 Eleman Eleman İşlemler

Hoca `a = [1 2 3]` dizisi üzerinde işlemler gösterdi (ekrandan, 02:05:00, workspace değerleri):

- `b = a*2` sonucu `[2 4 6]`
- `c = a.*b` sonucu `[2 8 18]` (karşılıklı elemanların çarpımı)

Değişken tipini önceden tanımlamaya gerek yoktur; hoca bunu Python tarzına benzetti.

### 8.5 İki Kosinüs, Toplam ve Frekans Bileşeni

Hoca iki kosinüs sinyali oluşturdu (ekrandan, 02:05:00):

```matlab
t = 1:0.01:100;
A = 10 * cos(2*pi*20*t);
B = 20*cos(2*pi*t ...
```

<!-- BELİRSİZ: B satırının devamı karede yazılırken kesilmiş. Altyazıda "20 olan çarpı kosinüs ... pardon 20 t" geçiyor; öğrencinin toplamın 30 olduğunu söylemesi ve FFT'de tek frekans görülmesi B'nin de 20 Hz frekanslı olduğunu düşündürüyor, ama karede tam okunmuyor. Altyazıda A için "frekansı 10" dense de karede 20 yazıyor. -->

Örnek sayısı çok fazla olduğundan çizim yoğun göründü ve zaman ekseni 0'dan 5'e indirildi; son durumda workspace'te `t`, `A`, `B` ve `C` 501 elemanlıdır (ekrandan, 02:10:00). `hold on` ile iki sinyal aynı grafikte farklı renklerde çizildi. `C = A + B` iki dizinin karşılıklı elemanlarını toplar; `figure` yeni bir çizim penceresi açar. Üç sinyal `subplot` ile alt alta çizildi:

```matlab
figure
subplot(3,1,1)
plot(t,A)
subplot(3,1,2)
plot(t,B)
subplot(3,1,3)
plot(t,C)
```

`subplot(3,1,k)` üç satır ve bir sütunluk bir düzende $k$'ıncı grafiği seçer; dört grafik ikişer ikişer de yerleştirilebilir. Karede genlik eksenleri A için $\pm 10$, B için $\pm 20$, C için $-20$ ile $40$ arasıdır. Bir öğrenci toplamın tepe değerinin 30 olduğunu söyledi ve hoca onayladı.

Ardından hoca `abs(fft(A))` ile A'nın frekans düzlemine geçti. Grafikte simetrik iki tepe görüldü; hoca bunun tek bir frekans bileşenini gösterdiğini, çünkü A oluşturulurken tek bir frekans yazıldığını söyledi. Mutlak değerin neden alındığını karmaşık sayılarla ilgili olduğu için ileride anlatacağını belirtti. C için de iki frekans bekleyip tek bileşen görünce, iki sinyal birleşip "otuz" genlikli tek bir sinyal olduğu için böyle çıktığını söyledi ve konuyu Fourier'de yeniden açacağını belirtti.

> **Ders sonrası not:** Python ile kontrol edildi: $t = 0, 0{,}01, \dots, 5$ (501 örnek) için $10\cos(2\pi\cdot 20t) + 20\cos(2\pi\cdot 20t) = 30\cos(2\pi\cdot 20t)$ olur ve `abs(fft(...))` tepeleri yalnız $\pm 20$ Hz civarında çıkar. Yani iki kosinüsün frekansı aynıysa toplam tek frekanslı bir kosinüstür. B'nin frekansı karede tam okunmadığı için bu açıklama büyük olasılıkla doğrudur.

Hoca ileride bir telefon tuşu sesinin frekanslarını çözme (dekod etme) gibi bir uygulama yapmayı düşündüğünü söyledi.

## 9. Sinyal ve Sistem Türleri

Üçüncü slayt dosyasına geçildi (ekrandan, 02:15:00). Derste ele alınan sinyallerin çoğu zamanın fonksiyonudur. Sürekli zaman sinyali bir aralıktaki her noktada değer alır; ayrık zaman sinyali yalnız ayrık zaman noktalarında değer alır.

Hoca sinyalin yalnız tek boyutlu olarak düşünülmemesi gerektiğini vurguladı:

- **Tek boyutlu:** kalp sesi, kalp atış hızı, nefes alma, ses, doların günlük seyri.
- **İki boyutlu:** görüntü, piksellere göre.
- **Uzay ve zaman:** video.
- **Çok kanallı:** klasik görüntüler RGB yani üç kanallıdır; uzaktan algılamadaki hiperspektral görüntüler ise yüz küsur kanallıdır ve farklı dalga boylarında görüntü elde eder.

Hiperspektral görüntülemenin uygulaması olarak hoca bir çek örneği verdi: mürekkeple yazılmış 10 TL'nin sonradan eklenen sıfırlarla 1000'e çevrildiği bir çekte bu değişikliği gözle ayırt etmek zordur, ama hiperspektral kamerada eski ve yeni mürekkebin özellikleri farklı kanallarda açıkça görülür. Üstü karalanmış bir yazı da benzer biçimde kanallardan birinde ortaya çıkabilir.

Sürekli zaman sinyali $t$, $\tau$ ya da $t_1$ gibi bir değişkenle ifade edilir. Sinyalin tamamı $v(\cdot)$ ya da $v(t)$ ile, belirli bir andaki değeri $v(2)$ ya da $v(t)|_{t=2}$ ile gösterilir. Hoca ultrason palsini örnek verdi.

Sistemler de sinyaller gibi sınıflanır (ekrandan, 02:15:00):

- **Sürekli zaman sistemi:** girişleri ve çıkışları süreklidir (AM/FM radyo, geleneksel mekanik araba).
- **Ayrık zaman sistemi:** girişleri ve çıkışları ayrıktır (bilgisayar oyunu, MATLAB).
- **Hibrit sistem:** girişi sürekli çıkışı ayrık ya da tersi olan sistemler; analog-dijital ve dijital-analog dönüştürücüler. Hoca sıcaklık örneğini verdi: giriş sürekli bir sıcaklık değeridir, çıkış "ısıtıcıyı çalıştır" ya da "soğutucuyu çalıştır" gibi ayrık bir karardır. Bilgisayarda oyun oynamak, elektronik kontrol üniteli modern araçlar ve uçaklar da birden çok alt sistemden oluşan örneklerdir.

Ayrık zamanda notasyon köşeli parantezle ve küçük $n$ ile yapılır: $x[n]$. Analog sinyalden dijitale geçerken $x(t)$'de $t$ yerine $nT$ yazılır; $T$ örnekleme periyodudur, yani sinyalin hangi aralıklarla örnekleneceğini gösterir. $x(t)$ bir fonksiyon, $x[n] = x(nT)$ ise bir dizidir.

## 10. Sinyaller Üzerinde Temel İşlemler

### 10.1 Genlikte Ölçekleme

Ölçeklenmiş sinyal $a\,x(t)$, $x(t)$'nin $a$ sabitiyle çarpımıdır; ayrık zamanda $a\,x[n]$ aynı biçimde tanımlanır (ekrandan, 02:20:00). Slayttaki örnekte tepe değeri 1 olan $x(t)$, $2x(t)$ yapılınca tepe değeri 2 olur; ayrık örnekte de $x[n]$'in her örneği 2 ile çarpılır.

Günlük hayattaki karşılığı ses açmaktır: ses açılınca genlik yükseltilir. Ayrık sinyalde bu, dizinin bütün elemanlarını 2 ile çarpmaktan farksızdır. Hoca sürekli bir fonksiyonun bilgisayarda doğrudan ölçeklenemeyeceğini, bunun ancak sembolik matematik kütüphaneleriyle (değişken tanımlayıp türev, integral alma, katsayıları çarpma) yapılabildiğini, gerçek kayıtlarda ise elimizdeki dizinin elemanlarının çarpıldığını söyledi.

Sesin ne kadar yükseltilebileceği ses kartının çözünürlüğüne bağlıdır. Hoca nicemleme (quantization) seviyelerini hatırlattı: ses kartı örneğin $n$ bit sunuyorsa genlik $2^n$ farklı seviyeye bölünür. Ses kartının ya da kulaklığın çözünürlüğü yetmeyecek kadar yükseltilirse doygunluk (satürasyon) oluşur ve gürültü duyulur. Görüntüde de bir nesneye olması gerekenden fazla ışık düşerse ilgili bölge bembeyaz görünür ve ayrıntılar kaybolur.

### 10.2 Zamanda Ölçekleme

Zaman ekseninde ölçekleme yapılınca sinyal zamanda daralır ya da genişler (büzme ya da germe). $x(at)$'de $a > 1$ ise sinyal daralır; bu, müziği iki kat hızda dinlemek gibidir: ikinci saniyede duyulacak şey birinci saniyede duyulur. Ayrık bir kayıtta bu, örneklerin bir kısmını atlamak gibidir; bin örnekten beş yüzü duyulur. Yavaşlatmak için $a = 1/2$ gibi bir katsayı kullanılır.

$x(2t)$'de $t = 1$ iken $x(2)$, $t = 2$ iken $x(4)$, $t = 3$ iken $x(6)$ değeri elde edilir. Bu sayede bir sinyal diğeri cinsinden ifade edilebilir.

Ayrık zamanda $x[n]$ dizisinin indisi bir $k$ tamsayısıyla çarpılarak $x[nk]$ elde edilir (ekrandan, 02:30:00):

- Bu işlem $x[n]$'in her $k$'ıncı örneğini alır.
- Aradaki örnekler kaybolur.
- Dizi kısalır.

Buna aşağı örnekleme (downsampling) ya da seyreltme (decimation) denir. Slayttaki örnekte $y[n] = x[2n]$ için $y[0] = x[0]$, $y[1] = x[2]$, $y[2] = x[4]$, $y[-1] = x[-2]$, $y[-2] = x[-4]$ olur.

Hoca veri iletiminden örnek verdi: bin örnekli bir verinin aktarımında sorun varsa beş yüzü gönderilir; karşı taraf interpolasyonla tekrar bine açabilir. Doğrusal interpolasyon araya düz çizgiler koyar, kuadratik interpolasyon daha yakın sonuç verebilir; ama bilgi kaybı olabilir. Tersine, indisi bir sayıya bölmek örnek sayısını artırır; buna yukarı örnekleme (upsampling) ya da interpolasyon denir.

> **Hocanın vurgusu:** İnterpolasyonla üretilen değerler bir sentezdir ve orijinal sinyalle doğrudan ilişkili olmayabilir. Gerçek değerin elde edildiği varsayılmamalıdır.

### 10.3 Zamanda Ters Çevirme

$x(t)$ yerine $x(-t)$ yazılınca sinyal düşey eksene göre simetriği alınmış olur. Ayrık zamanda $n$ yerine $-n$ yazılınca $n$'deki değer $-n$'ye gider; değerler yer değiştirir. Bu işlem, katsayısı $-1$ olan bir zaman ölçeklemesine benzer. Ölçekleme ve ters çevirme birlikte de yapılabilir: örneğin $x(-2t)$ hem daraltma hem ters çevirme içerir.

### 10.4 Zamanda Öteleme

Sürekli zaman sinyalinin değerlerini $t_1 > 0$ kadar zamanda kaydırmaya öteleme (shift) denir ve iki türlüdür: geciktirme (delay) ve öne alma (advance). $x(t-1)$ sinyali 1 saniye sağa kaydırır (gecikme), $x(t+1)$ 1 saniye sola kaydırır (öne alma). Hoca "advance" kelimesini "zaman ekseninde öne alma" olarak açıkladı: bir kişi bir şeyden öndeyse ileridedir.

Ayrık zamanda, $n_1 > 0$ bir tamsayı olmak üzere (ekrandan, 02:35:00):

- $x[n - n_1]$ gecikmiş (delayed) sinyaldir.
- $x[n + n_1]$ öne alınmış (advanced) sinyaldir.
- Gecikme ya da öne alma tamsayı sayıda örnek kadar olur.

Slayttaki grafikte $x[n+1]$, $x[n]$ ve $x[n-1]$ yan yana çizilmiştir: $x[n]$'in $n = 0$'daki en büyük örneği $x[n+1]$'de $n = -1$'e, $x[n-1]$'de $n = 1$'e kayar. Hoca bunu bir dizi (array list) üzerinden açıkladı: gecikmede dizinin başına boş bir eleman eklenir ve değerler bir sağa kayar; öne almada değerler bir sola kayar.

### 10.5 İşlemlerin Birleştirilmesi

Zamanda ölçekleme, öteleme ve ters çevirme birlikte kullanılabilir. Önemli olan işlemlerin hangi sırayla yapıldığıdır; karışıklığı önlemek için parantez kullanılmalıdır. Örneğin $x(2t)$ önce sinyali daraltır, ardından bir öteleme uygulanırsa daraltılmış sinyal kaydırılır. Slaytta "önce öteleme sonra ölçekleme" yapılan bir yol için "incorrect" yazılı bir örnek vardır; hoca öteleme ve ölçekleme sırasının sonucu değiştirdiğini gösterdi.

<!-- BELİRSİZ: Hocanın "13. slide" diye anlattığı doğru ve yanlış sıra örneklerinin formülleri karelerde görünmüyor; slayttaki sinyal ve dönüşümler aktarılamadı. -->

> **Ek bilgi (derste anlatılmadı):** $x(at + b)$ biçimindeki bir dönüşümde güvenli yol, önce $b$ kadar ötelemek ($x(t+b)$), sonra elde edilen sinyali $a$ ile ölçeklemektir ($t \to at$). Alternatif olarak ifade $x\big(a(t + b/a)\big)$ biçiminde yazılırsa önce ölçekleme, sonra $b/a$ kadar öteleme yapılır. Sıra karıştırılırsa öteleme miktarı yanlış bulunur.

> **Hocanın vurgusu:** $x(t)$ verildiğinde $x(-t/2)$, $x(2t+2)$ gibi sinyallerin taslak çizimleri (sketch) alıştırma olarak yapılmalıdır. Kitabın ve Chaparro'nun kitabının ilgili bölümlerinde benzer örnekler vardır. Hoca bu tür soruların geçmiş yıllarda sorulduğunu belirtti.

Hoca bu işlemlerin günlük bilgisayar uygulamalarında ve yapay zekada çok kullanılmadığını, ama özellikle analog elektronikte öteleme ve ölçekleme devreleri olarak çok karşılığı olduğunu söyledi.

## 11. Periyodik Sinyaller

Slayta göre periyodik sinyaller bu derste çok önemlidir (ekrandan, 02:40:00). Önemlerinin nedeni şudur: sinyal belirli aralıklarla kendini tekrar ettiği için tamamını analiz etmek yerine bir periyodunu incelemek yeterlidir.

- Sürekli zaman sinyali, ancak ve ancak $T_0 > 0$ olan bir sayı için $x(t + T_0) = x(t)$ bütün $t$ değerlerinde sağlanıyorsa periyodiktir. $T_0$, $x(t)$'nin zamandaki periyodudur.
- Ayrık zaman sinyali, ancak ve ancak $N_0 > 0$ olan bir tamsayı için $x[n + N_0] = x[n]$ bütün $n$ değerlerinde sağlanıyorsa periyodiktir. $N_0$, örnek aralığı cinsinden periyottur.
- En küçük $T_0$ ya da $N_0$ temel periyottur (fundamental period).

Hoca örnek olarak $x(1) = x(501)$, $x(2) = x(502)$, $x(3) = x(503)$ eşitliklerini verdi; bu değerler periyodu 500 olan bir sinyale karşılık gelir. <!-- BELİRSİZ: Altyazıda aynı cümlede "periyot 5 olsun" da geçiyor; verilen eşitlikler periyot 500 ile tutarlı. --> "En küçük" şartının nedeni şudur: bir sinyal $T$ periyotluysa $2T$ aralığında da kendini tekrar eder, yani $2T$ de bir periyottur. Ama temel periyot sinyalin kendini tekrar ettiği en kısa aralık olan $T$'dir. Bütün frekanslar temel frekansın tamsayı katları cinsinden yazılır: $1\cdot f_0$, $2\cdot f_0$, $3\cdot f_0$ gibi; analizler buna göre yapılacaktır.

Kosinüs ve sinüs yaygın kullanılan periyodik sinyallerdir. Bir periyodu verilen sinyalin tamamı periyodik genişletme (periodic extension) ile yeniden oluşturulabilir: bir periyot kopyalanarak bütün zaman eksenine yayılır. Hoca siren sesini örnek verdi: tek bir periyotta üretilen ses kopyalanarak sürekli çalınır.

## 12. Karmaşık Sinyaller ve Karmaşık Sayılar

Şimdiye kadar incelenen sinyallerin değerleri gerçek sayılardı. Gerçek dünyada bazı sinyaller karmaşık değerler içerir: dizinin her elemanı bir tamsayı ya da ondalık sayı değil, karmaşık bir sayıdır. Slayta göre karmaşık sinyal $z(t) = x(t) + jy(t)$ biçimindedir; haberleşme, sonar ve ultrasonda ve sinüzoidallerin rahat gösteriminde ortaya çıkar (ekrandan, 02:45:00, slayt önizlemesi).

Karmaşık sayıların hızlı tekrarı (ekrandan, 02:45:00):

- Kartezyen biçim: $z = x + jy$
- $x = \Re z$ gerçel kısım, $y = \Im z$ sanal kısım
- $x$ ve $y$ sırasıyla eş fazlı (in-phase) ve dik (quadrature) bileşenler olarak da adlandırılır.
- $j = \sqrt{-1}$ mühendislik gösterimidir; fizik, kimya ve matematikte $i = \sqrt{-1}$ kullanılır.

Karmaşık bir sayının büyüklüğü (modulus, magnitude) $r$, açısı ya da fazı $\phi$ ise sayı $z = r e^{j\phi}$ biçiminde yazılır. Hoca karmaşık sayıyı kosinüs ve sinüsler cinsinden ya da üstel biçimde yazabilmenin ileride çok gerekeceğini söyledi. Genel olarak:

$$e^{z} = e^{x + jy} = e^{x}\, e^{jy}, \qquad e^{jy} = \cos y + j\sin y$$

Bunun nedeni Fourier dönüşümüdür. Fourier dönüşümünde $\int f(t)\, e^{-j\omega_0 t}\, dt$ biçiminde bir integral alınır. $f(t)$ bir sinüs ise $\sin(t)\, e^{-j\omega_0 t}$ integralini kısmi integrasyonla almak uzundur. Sinüs üstel biçimde yazılırsa, tabanlar aynı olduğu için üsler toplanır ve tek bir üstel terim kalır; üstel terimin integralini almak kolaydır. Hoca bu noktada $e^{-ax}$'in integralini hatırlamaya çalıştı.

> **Ders sonrası not:** Hoca integrali tam hatırlayamadı. Doğrusu $\displaystyle\int e^{-ax}\,dx = -\frac{1}{a}e^{-ax} + C$'dir ($a \ne 0$).

## 13. Sinyal Enerjisi ve Gücü

Sinyalin gücü ve enerjisi çok kullanılan iki özelliktir. Hoca bunların yapay zeka ve veri madenciliği uygulamalarında da özellik olarak kullanılabileceğini, örneğin iki müzik parçasından birinin rock, birinin klasik olduğunu ayırt ederken enerjisi ya da gücü fazla olan sinyale göre karar verilebileceğini söyledi.

Slayttaki tanımlar (ekrandan, 02:50:00):

- $i(t)$ bir dirençten geçen akımsa dirençte harcanan enerji (Joule):

$$E_R = \lim_{T\to\infty}\int_{-T}^{T} i^2(t)\, R\, dt$$

- $i(t)$'nin sinyal enerjisi, $1\,\Omega$'luk dirençte harcanan enerji olarak tanımlanır:

$$E_i = \lim_{T\to\infty}\int_{-T}^{T} i^2(t)\, dt$$

- Karmaşık olabilecek bir $x(t)$ sinyalinin enerjisi:

$$E_x = \lim_{T\to\infty}\int_{-T}^{T} |x(t)|^2\, dt$$

Çoğu uygulamada bu gerçek bir enerji değildir, çünkü sinyallerin çoğu gerçekten $1\,\Omega$'luk bir dirence uygulanmaz. Hocanın özetiyle sinyal enerjisi, sinyalin karelerinin $-\infty$'dan $+\infty$'a integralidir. Güç ise ortalama enerji gibi düşünülür: enerji, hesaplandığı aralığın uzunluğuna bölünür ve sınır alınır:

$$P_x = \lim_{T\to\infty}\frac{1}{2T}\int_{-T}^{T} |x(t)|^2\, dt$$

Bu güç formülü slaytın bir sonraki sayfasının önizlemesinde görülür (ekrandan, 02:50:00, slayt önizlemesi). Hoca bu konunun örneklerine ayrık zamanlı sistemlerde bakılacağını söyleyerek dersi burada bitirdi.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:26:09)

Biri metal müzikten, biri klasik müzikten alınmış iki ses sinyalinin frekans bileşenlerinin ortalaması alınırsa hangisinin ortalaması daha yüksek olur?

> **Çözüm (derste verildi):** Metal müzik daha hızlı ve daha çok değişim içerdiği için frekans ortalaması daha yüksektir. Bu genel bir eğilimdir; çok hızlı klasik eserler istisna olabilir.

### Soru 2 (ekrandan, 00:55:00)

$x(t) = 3\cos(2\pi\cdot 2\cdot t - 3\pi/4)$ sinyalinin genliğini, frekansını, fazını ve periyodunu bulun.

> **Çözüm (derste verildi):** $A = 3$, $f_0 = 2$ Hz, faz büyüklüğü $3\pi/4$ (formüldeki işaretiyle $-3\pi/4$), $T_0 = 1/f_0 = 0{,}5$ s. İlk tepe $4\pi t - 3\pi/4 = 0$ koşulundan $t = 3/16$ s'dedir.

### Soru 3 (ekrandan, 01:15:00)

Bütün gerçek $t$ değerleri için tanımlı şu sinyalin özelliklerini yazın:

$$f(t) = \begin{cases} \sin(2\pi t)/t, & t \ge 1 \\ 0, & t < 1 \end{cases}$$

> **Çözüm (derste verildi, ekrandan, 01:20:00):** Sinyal sürekli zamanlı, analog, aperiyodik, sonsuz uzunluklu, nedensel, ne çift ne tek ve tanımı gereği deterministiktir. Aperiyodiklik: $\sin(2\pi(t+T))/(t+T) = \sin(2\pi t)/t$ eşitliği hiçbir $T > 0$ için her $t$'de sağlanmaz; $1/t$ çarpanı sinyali sürekli sönümlendirir.

### Soru 4 (derste sözlü, 02:23:28)

Bir uygulamada sesi açmak ve bir müziği iki kat hızda dinlemek sinyal üzerinde hangi işlemlere karşılık gelir?

> **Çözüm (derste verildi):** Sesi açmak genlikte ölçeklemedir: $a\,x(t)$, $a > 1$. İki kat hızda dinlemek zamanda ölçeklemedir: $x(2t)$; sinyal zamanda daralır ve dolaylı olarak örnekleme frekansı değişir.

### Soru 5 (ekrandan, 02:05:00)

MATLAB'da `a = [1 2 3]` için `b = a*2` ve `c = a.*b` sonuçları nedir?

> **Çözüm (derste verildi, workspace değerleri):** `b = [2 4 6]`, `c = [2 8 18]`. `.*` karşılıklı elemanları çarpar: $1\cdot 2 = 2$, $2\cdot 4 = 8$, $3\cdot 6 = 18$.

### Soru 6 (derste sözlü, 02:38:08)

$x(t)$ verildiğinde $x(-t/2)$ ve $x(2t+2)$ sinyallerinin taslağını çizin.

<!-- BELİRSİZ: Hoca bu soruyu alıştırma olarak söyledi; hangi $x(t)$ için sorulduğu altyazıda ve karelerde yok. -->

> **Çözüm (derste verilmedi):** Genel yol şöyledir. $x(-t/2)$ için önce $x(t)$ zamanda 2 kat genişletilir ($x(t/2)$), sonra düşey eksene göre ters çevrilir; $x(t)$'nin $t = t_0$'daki değeri $x(-t/2)$'de $t = -2t_0$'a gider. $x(2t+2)$ için önce 2 birim sola ötelenir ($x(t+2)$), sonra zamanda 2 kat daraltılır ($t \to 2t$); $x(t)$'nin $t = t_0$'daki değeri $x(2t+2)$'de $t = (t_0 - 2)/2$'ye gider.

## Dersin Toparlaması

Bu derste önce frekans domeninin neden kullanıldığı ayrıntılı ele alındı: bir sinyal sinüzoidallerin toplamı olarak yazılınca her bileşenin genlik, frekans ve faz bilgisi ortaya çıkar; bu bilgiler konuşmacı tanıma, enstrüman ve nota tahmini, arıza tespiti gibi uygulamalarda ayırt edici özellik olarak kullanılır. Diferansiyel denklemle verilen sistemler frekans domeninde transfer fonksiyonu ile çarpma işlemine indirgenir ve sonuç ters dönüşümle zaman domenine geri getirilir; kontrol sistemleri de bu sayede kolay tasarlanır. Ardından sinyaller sürekli/ayrık, analog/dijital, periyodik/aperiyodik, nedensel/antinedensel/nedensel olmayan, çift/tek ve deterministik/rastgele olarak sınıflandı ve her sinyalin çift ve tek parçalara ayrılabildiği gösterildi.

Dersin ikinci yarısında MATLAB ile sinyal oluşturma, çizme ve `fft` ile frekans bileşenlerine bakma uygulandı. Sonra sinyal ve sistem türleri, genlikte ve zamanda ölçekleme, aşağı ve yukarı örnekleme, ters çevirme ve öteleme işlemleri, bu işlemlerin birleştirilmesinde sıranın önemi, periyodik sinyaller ve temel periyot, karmaşık sayıların üstel gösterimi ve sinyal enerjisi ile gücü işlendi. Hoca karmaşık sayıların üstel gösteriminin ileride Fourier dönüşümünde integralleri kolaylaştıracağını, enerji ve güç örneklerine ise ayrık zamanlı sistemlerde bakılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
