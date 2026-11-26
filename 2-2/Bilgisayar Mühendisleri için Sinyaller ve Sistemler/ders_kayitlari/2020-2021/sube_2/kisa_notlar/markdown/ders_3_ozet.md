# Ders 3 Çalışma Özeti

## Genel Konular

- Frekans domeni neden kullanılır?
  - Bir sistemi incelemenin ilk yolu girişe karşı çıkışa bakmaktır. Örneğin 1, 2, 3, 4 girişlerine 2, 4, 6, 8 çıkışları veren sistem "iki katını alan" bir sistemdir. Her sistemin davranışı bu kadar kolay çözülemez; bu yüzden sinyale ve sisteme farklı bir açıdan, frekans açısından bakılır.
  - Bir kağıt paranın ön ve arka yüzü gibi, aynı sinyalin zaman domeni ve frekans domeni gösterimleri farklı bilgileri öne çıkarır.
  - Bir sinyal sinüzoidallerin toplamı olarak yazılabilir: $f(t) = 0{,}1\sin(\omega_1 t) + 0{,}7\sin(\omega_2 t) + 0{,}2\sin(\omega_3 t)$, burada $\omega_1 = 2\pi f_1$ (ekrandan, 00:30:00). Her bileşenin üç bilgisi vardır: genlik, frekans ve faz. Üç bileşenli sinyalde toplam dokuz bilgi frekans domeninde ayrıştırılarak elde edilir.
  - Frekans analizi ayırt edici özellik çıkarmanın (feature extraction) temelidir: konuşmacı tanıma, enstrüman ve nota tahmini, müzik türü ayırma, stetoskop kayıtlarından solunum analizi, rulman arızası tahmini.
  - Piyano akoru örneği: zaman serisi grafiği akorun başladığı anı ve sönümünü (ADSR zarfı; atak ve sönüm aşamaları) gösterir ama hangi notaların çalındığı dalga biçiminden anlaşılmaz. Genlikler frekansa göre çizilince birkaç belirgin tepe görülür ve grafik çok daha kolay okunur (ekrandan, 00:40:00).
  - Diferansiyel denklemlerin çözümü: giriş ve diferansiyel denklem frekans domenine dönüştürülür, transfer fonksiyonu ile çarpım yapılır, sonuç ters dönüşümle zaman domenine geri getirilir (ekrandan, 00:45:00).
  - Kontrol örneği: arabanın hızını sabit tutmak için gaz-hız döngüsü kapatılır ("close the loop"). Bunu otomatik yapan yapı PID kontrolördür (ekrandan, 00:50:00).
- Sinyallerin sınıflandırılması
  - Sürekli zaman ve ayrık zaman: sınıflandırma zaman ekseninin sürekli mi ayrık (sayılabilir) mı olduğuna göre yapılır. Sürekli zaman sinyali zaman eksenindeki her gerçek sayı için değer alır. Ayrık zaman sinyali genellikle sürekli sinyalin örneklenmesiyle elde edilir ve yalnız eşit aralıklı noktalarda değer alır (ekrandan, 00:55:00).
  - Analog ve dijital: analog sinyal genlikte de süreklidir; dijital sinyal hem zamanda hem genlikte ayrıktır ve 0-1 dizileriyle ifade edilir.
  - Periyodik ve aperiyodik: $f(t) = f(t+T)$ bütün $t$ için sağlanıyorsa sinyal periyodiktir. Bunu sağlayan en küçük $T$ temel periyottur (ekrandan, 01:00:00).
  - Nedensel (causal), antinedensel (anticausal), nedensel olmayan (noncausal): nedensel sinyal negatif zamanda sıfırdır, antinedensel sinyal pozitif zamanda sıfırdır, nedensel olmayan sinyal iki tarafta da sıfırdan farklı değer alır (ekrandan, 01:05:00).
  - Çift ve tek: çift sinyalde $f(t) = f(-t)$, tek sinyalde $f(t) = -f(-t)$.
  - Deterministik ve rastgele: deterministik sinyalin her değeri bir formül, kural ya da tabloyla bellidir; rastgele sinyal her denemede farklı değer verir.
- Çift-tek ayrıştırması
  - Her sinyal bir çift ve bir tek sinyalin toplamıdır: $f(t) = \tfrac{1}{2}\big(f(t) + f(-t)\big) + \tfrac{1}{2}\big(f(t) - f(-t)\big)$. İlk parça çift, ikinci parça tek fonksiyondur (ekrandan, 01:10:00).
- MATLAB ile sinyal çizimi
  - MATLAB matris tabanlı, yorumlanan bir dildir. Diziler döngü yazmadan vektörel olarak toplanır; eleman eleman çarpma ve bölme için `.*` ve `./` kullanılır.
  - `plot`, `hold on`, `figure`, `subplot`, `fft`, `abs` komutları ile sinyal çizme ve frekans bileşenlerine bakma gösterildi (ekrandan, 02:10:00).
- Sinyal ve sistem özellikleri
  - Sinyaller tek boyutlu (ses, kalp atışı, döviz kuru), iki boyutlu (görüntü) ya da uzay ve zamana bağlı (video) olabilir; hiperspektral görüntüler yüzlerce kanallıdır.
  - Sistemler sürekli zamanlı, ayrık zamanlı ve hibrit (A/D, D/A dönüştürücüler) olarak sınıflanır (ekrandan, 02:15:00).
  - Ayrık zamanda $x(t)$ yerine $t = nT$ yazılarak $x[n]$ dizisi elde edilir; $T$ örnekleme periyodudur.
- Sinyaller üzerinde temel işlemler
  - Genlikte ölçekleme: $a\,x(t)$ ve $a\,x[n]$ (ekrandan, 02:20:00).
  - Zamanda ölçekleme: $x(at)$, $a>1$ ise sinyal daralır, $a<1$ ise genişler. Ayrık zamanda $x[nk]$ her $k$'ıncı örneği alır; ara örnekler kaybolur (downsampling, decimation) (ekrandan, 02:30:00). Tersine örnek sayısını artırmak upsampling ya da interpolasyondur.
  - Zamanda ters çevirme: $x(-t)$, $x[-n]$.
  - Zamanda öteleme: $x(t - t_1)$ ve $x[n - n_1]$ gecikmiş (delay), $x[n + n_1]$ öne alınmış (advance) sinyaldir (ekrandan, 02:35:00).
- Periyodik sinyaller, karmaşık sayılar, enerji ve güç
  - $x(t+T_0) = x(t)$ ve $x[n+N_0] = x[n]$; en küçük $T_0$ ya da $N_0$ temel periyottur (ekrandan, 02:40:00).
  - Karmaşık sayı: $z = x + jy$, $x = \Re z$, $y = \Im z$; mühendislikte $j$, matematikte $i$ kullanılır (ekrandan, 02:45:00).
  - Sinyal enerjisi: $E_x = \lim_{T\to\infty}\int_{-T}^{T}|x(t)|^2\,dt$; güç, enerjinin zamana göre ortalamasıdır (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Frekans domeninin amacı
  - Zaman domeninde çözülmesi zor olan sistem davranışı, frekans domeninde daha basit cebirsel işlemlerle (çarpma) çözülür. Hoca bunu "sistemin temel karakteristiğini ortaya çıkarır" diye özetledi.
  - Sinüzoidallerin toplamı olarak ifade edilebilen sinyallerde, az bir bilgi kaybıyla bile, güçlü çıkarımlar yapılabilir.
- "Suggest" kelimesinin anlamı
  - Bilimsel metinlerde ve sınav sorularında "suggest" çoğunlukla "öner" değil, "ortaya koymak, belirtmek, göstermek" (reveal, disclose) anlamındadır.
- Causal kelimesinin yazılışı
  - Doğru terim "causal" (nedensel) olup "casual" (gündelik) ile karıştırılmamalıdır. Nedensellik, mevcut değerin yalnız şimdiki ve geçmiş değerlere bağlı olmasıdır.
- İşlem sırası
  - Ölçekleme ve öteleme birlikte yapılırken sıra önemlidir. Karışıklığı önlemek için parantez kullanılmalı ve hangi işlemin önce yapıldığına dikkat edilmelidir.
- Periyodik sinyaller
  - Periyodik sinyalde tek bir periyodu incelemek bütün sinyali incelemek için yeterlidir. Bu yüzden derste "çok önemli" sayılır.
- Alıştırma
  - $x(t)$ verildiğinde $x(-t/2)$, $x(2t+2)$ gibi dönüşümlerin taslak çizimini (sketch) yapmak, kitaptaki örneklerle çalışılmalıdır.

## Kısa Tekrar Notları

- Sinyal sinüzoidallerin toplamıdır; her bileşen genlik, frekans ve fazla tanımlanır.
- Frekans domeni: diferansiyel denklem yerine transfer fonksiyonu ile çarpma, sonra ters dönüşüm.
- $x(t) = 3\cos(2\pi\cdot 2\cdot t - 3\pi/4)$: $A = 3$, $f_0 = 2$ Hz, $T_0 = 1/f_0 = 0{,}5$ s, ilk tepe $t = 3/16$ s (ekrandan, 00:55:00).
- Periyodiklik: $f(t) = f(t+T)$ her $t$ için; en küçük $T$ temel periyot.
- Nedensel: $t<0$ için sıfır; antinedensel: $t>0$ için sıfır; nedensel olmayan: iki tarafta değerli.
- Çift: $f(t) = f(-t)$; tek: $f(t) = -f(-t)$; her sinyal çift ve tek parçaya ayrılır.
- $f(t) = \sin(2\pi t)/t$ ($t \ge 1$), $0$ ($t<1$): sürekli zaman, analog, aperiyodik, sonsuz uzunluklu, nedensel, ne çift ne tek, deterministik.
- Genlik ölçekleme: $a\,x(t)$; zaman ölçekleme: $x(at)$; ters çevirme: $x(-t)$; öteleme: $x(t-t_1)$.
- $x[nk]$: downsampling (decimation), ara örnekler kaybolur.
- $x[n-n_1]$ gecikme, $x[n+n_1]$ öne alma.
- Sinyal enerjisi $\int |x(t)|^2 dt$, güç enerjinin zaman ortalaması.
- Euler: $e^{x+jy} = e^{x}(\cos y + j\sin y)$; karmaşık sayı $z = r e^{j\phi}$.

## Detaylı Açıklamalar

- **Neden frekans domeni?** Hoca önce basit bir giriş-çıkış tablosuyla başladı: 1 girince 2, 2 girince 4, 3 girince 6, 4 girince 8 çıkan sistem iki katını alan bir sistemdir. Gerçek sistemlerde böyle doğrudan çıkarım her zaman mümkün değildir. Bu durumda sinyale başka bir açıdan bakmak gerekir. Hoca bunu kağıt paranın iki yüzüne benzetti: aynı nesnenin iki yüzü farklı ayırt edici bilgiler taşır. Karmaşık görünen bir dalga biçimi frekans domeninde, örneğin 11 tane bilinen sinüzoidalin toplamı olarak ifade edilebilir. Bu, sinyalin hangi frekansları içerdiğini, düşük frekansların mı yüksek frekansların mı baskın olduğunu gösterir.
- **Müzik türü sezgisi.** Hoca, biri metal biri klasik müzikten alınmış iki sinyalin frekans bileşenlerinin ortalamasını karşılaştırmayı sordu. Öğrencilerin cevabı ve hocanın onayı: metal müzik daha hızlı ve daha çok değişim içerdiği için frekans ortalaması daha yüksektir. Hoca verdiği sayıların (klasik 50 Hz, caz 60 Hz, metal 300 Hz gibi) uydurma olduğunu, yalnız fikri göstermek için verildiğini belirtti. Bir öğrenci bazı klasik eserlerin de çok hızlı olabileceğini hatırlattı; hoca bunun genel bir eğilim olduğunu kabul etti.
- **Sinüzoidallerin toplamı.** Slayttaki örnekte üç sinüzoidal toplanır: $0{,}1\sin(\omega_1 t)$, $0{,}7\sin(\omega_2 t)$ ve $0{,}2\sin(\omega_3 t)$ (ekrandan, 00:30:00). $\omega = 2\pi f$ ilişkisiyle açısal ve çizgisel frekans birbirine çevrilir. Her bileşenin genlik, frekans ve faz bilgisi vardır; üç bileşen için dokuz bilgi bulunur. Denklemi bilinen bir sinyalde bunlar gözle okunabilir, ama gerçek dünyadan kaydedilen bir sinyalde (örneğin mikrofon hoparlöre yaklaşınca çıkan yüksek frekanslı ses) bu bilgiler ancak frekans analiziyle elde edilir.
- **Uygulamalar.** Konuşmacı tanıma (bankaların sesli imza sistemleri), görüntüdeki yüz özelliklerine benzer biçimde sesten ayırt edici özellik çıkarma, piyano/obua/klarnet gibi enstrümanların aynı notayı farklı frekans bileşenleriyle üretmesi, stetoskop kayıtlarından yorgunluk ya da zatürre tahmini, araç rulman arızasının çok boyutlu zaman serisi olarak frekans domeninde incelenmesi örnek verildi. Saf bir ton (pure tone) frekans domeninde tek bir bileşen (yaklaşık 1 kHz) olarak görünür; enstrümanlarda birden çok bileşen ortaya çıkar.
- **Piyano akoru.** Zaman serisi grafiği akorun başlangıcını (atak) ve sönümünü (decay) gösterir; hoca buna ADSR zarfı dedi. CD kalitesinde saniyede 44.100 örnek olduğu için zaman domeninde analiz zordur. Frekans domeninde ise grafikte birkaç belirgin tepe görülür ve hangi notaların çalındığı anlaşılır (ekrandan, 00:40:00).
- **Diferansiyel denklemler ve transfer fonksiyonu.** Arabanın kaldırıma (curb) çıkması örneğinde giriş bir basamak fonksiyonudur, araba dinamiği diferansiyel denklemlerle modellenir (ekrandan, 00:45:00). Doğrudan çözüm yerine giriş frekans domenine alınır, diferansiyel denklemin karşılığı olan transfer fonksiyonu ile çarpılır, frekans domenindeki çıkış ters dönüşümle zaman domenine getirilir. Hoca bu yapıya genel olarak "model" dedi; sürekli sistemlerde bu model transfer fonksiyonu adını alır. Türevlerin frekans domenindeki karşılıkları tablolarla verilir; bu konu ileride Laplace ve Fourier ile işlenecek.
- **Kontrol ve PID.** Araba hızı örneğinde gaz arttıkça hız artar. Sürücü göstergeye bakıp gazı ayarlayarak döngüyü kapatır (ekrandan, 00:50:00). Bunu otomatik yapan yapı PID kontrolördür: geçmiş hataların toplamı (integral) ve hatanın değişimi (türev) kullanılarak çıkış hedef değere oturtulur. Hoca benzer bir mantığı göz bebeği (iris/pupil) tespitine bağladı: bir maske görüntüde gezinip renk değerlerini toplar, bir önceki konumla karşılaştırır ve en karanlık noktayı bulunca durur.
- **Sürekli ve ayrık sinyaller.** Slayttaki örnek $x(t) = 3\cos(2\pi\cdot 2\cdot t - 3\pi/4)$ için $A = 3$, $f_0 = 2$, $T_0 = 1/f_0 = 0{,}5$ s ve ilk tepe $t = 3/16$ s'dedir (ekrandan, 00:55:00). Hoca ekrandaki çizimin aslında gerçek anlamda sürekli olmadığını, sürekli sinyali ifade eden şeyin formül olduğunu belirtti. Ayrık sinyal yalnız belirli aralıklarda değer alır; aradaki bilgi kaybedilebilir, ama bilgisayar ve sayısal işaret işlemcilerle hızlı işleme imkânı sağlar.
- **Periyodik sinyaller ve temel frekans.** $f(t) = f(t+T)$ eşitliği bütün $t$ değerleri için sağlanıyorsa sinyal periyodiktir. Bu eşitliği sağlayan en küçük $T$ temel periyottur (ekrandan, 01:00:00). Temel frekans, kişilerin seslerini ayırt etmede kullanılan bir özelliktir.
- **Nedensellik.** Nedensel sinyal negatif zamanda sıfırdır. Hoca nedenselliği "şu anki durumun önceki durumlara bağlı olması" ile ilişkilendirdi ve $y[n] = x[n-1] + x[n]$ gibi geçmiş değerlere bağlı ifadeler verdi. Nedensel sistemlerin çözüm yöntemleri diğerlerinden farklıdır. Hoca slayttaki grafiksel tanımın nedenselliği tek başına iyi anlatmadığını, denklem biçiminin daha açıklayıcı olduğunu söyledi.
- **Çift-tek ayrıştırması.** $f(t)+f(-t)$ çift, $f(t)-f(-t)$ tek fonksiyondur; ikisinin yarılarının toplamı $f(t)$'yi verir (ekrandan, 01:10:00). Hoca bir sinyal ile zamanda ters çevrilmiş halinin toplanmasıyla çift parçanın, farkıyla tek parçanın elde edildiğini grafik üzerinde gösterdi.
- **Örnek sinyal.** $f(t) = \sin(2\pi t)/t$ ($t \ge 1$), $f(t) = 0$ ($t < 1$) sinyali sürekli zamanlı, analog, aperiyodik, sonsuz uzunluklu, nedensel, ne çift ne tek ve tanımı gereği deterministiktir (ekrandan, 01:20:00). Aperiyodikliğin nedeni paydaki $t$'dir: $\sin(2\pi t)$ kendi başına periyodiktir, ama $1/t$ çarpanı sinyali sönümlendirir ve aynı değer hiçbir zaman tekrar etmez.
- **MATLAB.** MATLAB matris tabanlı, yorumlanan bir dildir; değişkenler vektör ya da matris olarak tutulur. `a = [1 2 3]` için `a*2` sonucu `[2 4 6]`, `a.*b` eleman eleman çarpma sonucu `[2 8 18]`'dir (ekrandan, 02:05:00). Derste önceki slayttaki örnek sinyal çizildi, sonra iki kosinüs oluşturulup `subplot(3,1,k)` ile alt alta çizildi ve `abs(fft(...))` ile frekans bileşenlerine bakıldı (ekrandan, 02:10:00). Araç kutuları (toolbox) ile sinyal işleme, görüntü işleme, kontrol (PID Tuner) ve yapay sinir ağı uygulamaları da yapılabilir.
- **Zaman ölçekleme ve örnekleme.** $x(2t)$ müziği iki kat hızda dinlemeye benzer: sinyal zamanda daralır. Ayrık zamanda $x[2n]$ her ikinci örneği alır; ara örnekler kaybolur ve dizi kısalır. Bu, veri iletiminde örnek sayısını azaltmak için kullanılabilir; karşı taraf interpolasyonla (doğrusal ya da kuadratik) örnek sayısını yeniden artırabilir, ama üretilen yeni değerler orijinal sinyalle birebir aynı olmayabilir.
- **Genlik ölçekleme ve doygunluk.** Ses açmak genliği bir sabitle çarpmaktır. Ses kartının çözünürlüğü (nicemleme seviyesi sayısı) sınırlıdır; aşırı yükseltmede doygunluk (satürasyon) oluşur ve gürültü duyulur. Görüntüde aşırı ışık da benzer biçimde bölgeyi bembeyaz yapar.
- **Karmaşık sayılar ve enerji.** Fourier dönüşümünde $e^{-j\omega_0 t}$ çarpanı kullanılır. Sinüsü üstel biçimde yazmak, kısmi integrasyon yerine üstlerin toplanmasıyla daha kolay integral almayı sağlar. Sinyal enerjisi direnç üzerinde harcanan enerjiden genelleştirilir: $E_x = \lim_{T\to\infty}\int_{-T}^{T}|x(t)|^2\,dt$. Çoğu uygulamada bu gerçek bir fiziksel enerji değildir; güç, enerjinin zaman ortalamasıdır. Hoca, güç ve enerjinin müzik türü ayırma gibi veri madenciliği uygulamalarında özellik olarak kullanılabileceğini belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
