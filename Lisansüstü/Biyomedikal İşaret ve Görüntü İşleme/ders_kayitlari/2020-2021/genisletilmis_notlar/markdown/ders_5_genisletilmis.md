# Ders 5 Genişletilmiş Notu: DTFT ile Frekans Cevabı, Örtüşme, DFT ve DTMF Uygulaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. DTFT Tekrarı ve Gösterim Kuralları
- 2. Fark Denklemiyle Verilen Bir Sistemin Frekans Cevabı
- 3. Toparlama: Örneklemenin Frekans Uzayındaki Etkisi
- 4. Sayısal Frekans ve $[-\pi,\pi]$ Aralığı
- 5. Ayrık Fourier Dönüşümü (DFT)
- 6. Örtüşme (Aliasing) ve Beş Bileşenli İşaret Örneği
- 7. DFT İndislerinin Analog Frekansa Çevrilmesi
- 8. MATLAB'de FFT: EKG Parçası
- 9. Gerçek Hayat Örneği: DTMF Tuşlu Telefon İşaretleri

## 1. DTFT Tekrarı ve Gösterim Kuralları

Önceki derste ayrık zamanlı Fourier dönüşümü (Discrete Time Fourier Transform, DTFT) görülmüştü. DTFT'nin en önemli özelliği, herhangi bir işaretin frekans içeriğini yalnızca ayrık örneklerinden elde etmeyi sağlamasıdır:

$$X(e^{j\Omega})=\sum_{n=-\infty}^{\infty} x[n]\,e^{-jn\Omega}$$

(ekrandan, 00:30:00)

Bu ifadede iki farklı uzay yan yana durur. Sağ taraf ayrık zaman uzayıdır: toplam, zamandaki $x[n]$ örnekleri üzerinden alınır. Sol taraf ise sürekli frekans uzayıdır. Hoca gösterim kuralına özellikle dikkat çekti:

- Ayrık zaman uzayındaki işaretler küçük harfle ve köşeli parantezle yazılır: $x[n]$.
- Frekans uzayına geçince harf büyür ve normal parantez kullanılır: $X(e^{j\Omega})$.

DTFT'de frekans süreklidir. Bu yüzden bilgisayarda işlenebilmesi için frekans tarafının da ayrıklaştırılması gerekir. Dersin ikinci yarısındaki DFT konusu bu ihtiyaçtan doğar.

## 2. Fark Denklemiyle Verilen Bir Sistemin Frekans Cevabı

### 2.1 Örnek sistem

Bir kutunun girişi $x[n]$, çıkışı $y[n]$ olsun. Kutunun içinde yapılan işlem şu fark denklemiyle verilmiş:

$$y[n]=1.34\,y[n-1]-0.9\,y[n-2]+x[n]-1.41\,x[n-1]+x[n-2]$$

(ekrandan, 00:35:00)

Bu sistem şu anki çıkışı üretmek için daha önce üretilmiş çıkışları ($y[n-1]$, $y[n-2]$), şu anki girişi ve önceki girişleri kullanır. Önceki çıkışların bir yerde tutulması gerektiği için sistemde bir hafıza bulunmalıdır; hoca tahtada bunu kutuya giren bir "Memory" okuyla gösterdi.

### 2.2 Neden frekans uzayına geçiyoruz?

Zaman uzayında çıkış $y[n]=h[n]*x[n]$ konvolüsyonuyla bulunurdu. Ancak burada $h[n]$ bilinmiyor; sistem yalnızca giriş ve çıkış örnekleri cinsinden tanımlanmış. İstenen, sistemin frekans karşılığı olan $H(e^{j\Omega})$'dır.

Bunun için DTFT'nin öteleme (shift) özelliği hatırlatıldı. Bir işaret zamanda $n_0$ örnek kaydırılırsa, DTFT'si bir karmaşık üstelle çarpılır:

$$x[n-n_0]\ \overset{\text{DTFT}}{\longleftrightarrow}\ X(e^{j\Omega})\,e^{-jn_0\Omega}$$

Yani gecikme, frekans uzayında yalnızca bir karmaşık üstelle çarpma demektir. Önündeki skaler katsayılar ise doğrusallık özelliği sayesinde aynen kalır.

### 2.3 Adım adım çözüm

Denklemin her iki tarafının DTFT'si alınır. $y[n-1]$ için $n_0=1$ olduğundan $e^{-j\Omega}$, $y[n-2]$ için $e^{-j2\Omega}$ gelir. Girişli terimler de aynı şekilde dönüşür:

$$Y(e^{j\Omega})=1.34\,Y(e^{j\Omega})e^{-j\Omega}-0.9\,Y(e^{j\Omega})e^{-j2\Omega}+X(e^{j\Omega})-1.41\,X(e^{j\Omega})e^{-j\Omega}+X(e^{j\Omega})e^{-j2\Omega}$$

(ekrandan, 00:40:00)

Konvolüsyon konusunda görüldüğü gibi zamandaki konvolüsyon frekansta çarpmaya dönüşür:

$$y[n]=h[n]*x[n]\ \xrightarrow{\text{DTFT}}\ Y(e^{j\Omega})=H(e^{j\Omega})\,X(e^{j\Omega})\quad\Rightarrow\quad H(e^{j\Omega})=\frac{Y(e^{j\Omega})}{X(e^{j\Omega})}$$

Yapılacak iş, $Y$'li terimleri bir tarafa, $X$'li terimleri diğer tarafa toplamak ve ortak parantez almaktır (ara adım eklendi):

$$Y(e^{j\Omega})\left[1-1.34e^{-j\Omega}+0.9e^{-j2\Omega}\right]=X(e^{j\Omega})\left[1-1.41e^{-j\Omega}+e^{-j2\Omega}\right]$$

Buradan sistemin frekans cevabı:

$$H(e^{j\Omega})=\frac{1-1.41\,e^{-j\Omega}+e^{-j2\Omega}}{1-1.34\,e^{-j\Omega}+0.9\,e^{-j2\Omega}}$$

Zamandaki karşılık istenirse önceki derste verilen ters DTFT formülü uygulanır:

$$h[n]=\frac{1}{2\pi}\int_{-\pi}^{\pi}H(e^{j\Omega})\,e^{jn\Omega}\,d\Omega$$

Hocanın bu örnekle anlatmak istediği temel fikir şudur: kutunun içindeki işlemler arttıkça zaman uzayındaki konvolüsyonun hesap yükü artar. Frekans uzayına geçildiğinde aynı iş basit bir çarpma ve bölmeyle yapılır; elde edilen frekans cevabı gerekirse tekrar zamana döndürülür.

## 3. Toparlama: Örneklemenin Frekans Uzayındaki Etkisi

Hoca, matematiksel olarak yoğun geçen önceki derslerin özetini tek bir şekil üzerinde yaptı (ekrandan, 00:45:00 ve 00:50:00).

1. Başlangıçta sürekli bir $x(t)$ işareti vardır. Frekans uzayındaki karşılığı $X(f)$, $0$'dan başlayıp belli bir $f_{max}$'a kadar uzanır. Çizilen örnekte alçak frekanslar fazla, yüksek frekanslar azdır.
2. İşaret zamanda örneklenir ve $x[n]$ elde edilir. Tahtadaki mavi çubuklar bu ayrık örneklerdir.
3. Örneklemeyle birlikte frekans uzayında artık $X(e^{j\Omega})$'dan söz edilir. Bu spektrumun iki özelliği vardır: simetriktir ve periyodiktir. Spektrum $0$ çevresinde simetrik hale gelir ve $f_s$'in katlarında kendini tekrar eder.

Kopyaların birbirine girmemesi için ardışık kopyaların merkezleri arasındaki $f_s$ mesafesi en az $2f_{max}$ olmalıdır:

$$f_s\ \ge\ 2f_{max}$$

Örneğin $f_{max}=4$ kHz ise $f_s$ en az 8 kHz olmalıdır (ara adım eklendi). $f_s=2f_{max}$ olduğunda kopyalar uç uca değer ve özgün bölge hâlâ kurtarılabilir. $f_s<2f_{max}$ olduğunda ise kopyalar $f_s/2$ çevresinde birbirinin içine girer. Bu bölgedeki yüksek frekanslar toplanır (tahtada yeşil ile gösterilen kısım), özgün spektrumun yüksek frekanslı kısmı ezilir ve farklı bir değere bürünür. Artık özgün işaret geri elde edilemez. Hoca bunun Nyquist teoreminin frekans uzayındaki karşılığı olduğunu söyledi.

> **Hocanın vurgusu:** Kopyalar uç uca değdiği sürece özgün bölge kurtarılabilir; birbirlerinin içine girdikleri an özgün işaret elde edilemez.

> **Ek bilgi (derste anlatılmadı):** Pratikte $f_s$'in $2f_{max}$'a tam eşit seçilmesi risklidir. Örneğin tam $f_s/2$ frekansındaki bir sinüs, örnekleme anlarına göre sıfırlarda örneklenebilir ve hiç görünmeyebilir. Bu yüzden genellikle $f_s$, $2f_{max}$'tan biraz büyük seçilir ve örneklemeden önce bir alçak geçiren (anti-aliasing) süzgeç kullanılır.

## 4. Sayısal Frekans ve $[-\pi,\pi]$ Aralığı

Örneklenen bir işaretin içinde $\cos(2\pi f_{max} t)$ gibi en yüksek frekanslı bir bileşen olsun. $t$ yerine $nT_s=n/f_s$ konunca:

$$\cos\!\left(2\pi f_{max}\,\frac{n}{f_s}\right)$$

$f_s=2f_{max}$ yerine konursa $f_{max}$'lar sadeleşir ve $\cos(\pi n)$ kalır (ekrandan, 00:55:00). Demek ki ayrıklaştırma yapıldığında en yüksek frekans $\Omega=\pi$'de oluşur. Genel olarak:

$$\Omega=\frac{2\pi f}{f_s},\qquad f=\frac{f_s}{2}\ \leftrightarrow\ \Omega=\pi,\qquad f=f_s\ \leftrightarrow\ \Omega=2\pi$$

$\Omega$'ya sayısal frekans denir. $f_s/2$ daima $\pi$'ye denk gelir. $f_s$, $2f_{max}$'tan ne kadar uzaklaştırılırsa $f_{max}$ o kadar içeride kalır ve periyodik kopyalar birbirinden o kadar ayrılır.

$X(e^{j\Omega})$ $2\pi$'lik bir alanda tanımlıdır ve sonra kendini tekrar eder. Bu periyot $[-\pi,\pi]$ olarak da $[0,2\pi]$ olarak da düşünülebilir. $[-\pi,0]$ aralığı $[0,\pi]$'nin simetriğidir; $[0,2\pi]$ düşünüldüğünde de $[\pi,2\pi]$ aralığı $[0,\pi]$'nin simetriğidir. İşaretin tanımlı olduğu ana alan $2\pi$ genişliğindedir. $[-\pi,\pi]$ aralığı, özgün işareti geri elde etmek için gereken bilgiyi tam olarak içerir.

## 5. Ayrık Fourier Dönüşümü (DFT)

### 5.1 Neden DFT?

$[-\pi,\pi]$ aralığındaki spektrum özgün işaretin bütün bilgisini taşır. Ama bu spektrum süreklidir; bilgisayarın hafızasına konup üzerinde işlem yapılabilmesi için zaman uzayında olduğu gibi frekans uzayında da örnek alınmalıdır. Hoca iki dönüşümü şöyle ayırdı:

- DTFT ayrıktan sürekliye geçiş yapar: $x[n]\ \overset{\text{DTFT}}{\longleftrightarrow}\ X(e^{j\Omega})$.
- DFT (Discrete Fourier Transform) ayrıktan ayrığa dönüşüm yapar: $x[n]\ \overset{\text{DFT}}{\longleftrightarrow}\ X[k]$.

Frekans tarafı da ayrıklaşınca köşeli parantez kullanılır; frekans uzayı olduğu için harf yine büyüktür (ekrandan, 01:05:00).

Tahtaya yazılan tanım (ekrandan, 01:00:00 ve 01:05:00): DFT, sonlu uzunluklu diziler için başka bir Fourier dönüşümüdür ve oldukça önemlidir. DTFT frekansın ($\Omega$) sürekli halini sunarken, DFT frekans örneklerinin ayrık biçimde dönüşümünü gerçekleştirir. Bu dönüşüm sayısal hesaplamalarda ve sayısal donanım uygulamalarında oldukça kullanışlıdır.

### 5.2 Formülün kurulması

$e^{j\Omega}=\cos\Omega+j\sin\Omega$ olduğundan $X(e^{j\Omega})$ aslında belli frekanslardaki sinüzoidal salınımların içeriğini gösterir. DTFT'deki $e^{-j\Omega n}$ teriminde $\Omega$, $2\pi$'lik bir alanda değişir. Bu alan $N$ eşit parçaya bölünür. Parçalar arasındaki mesafe $2\pi/N$'dir ve $k$. parça $\Omega_k=\frac{2\pi}{N}k$ frekansına karşılık gelir. $k=0$ ilk parçayı, $k=1$ bir sonraki $2\pi/N$ adımını verir; $N$ parçayla $2\pi$'lik alan tamamlanır. Böylece $e^{-j\Omega n}$ terimi $e^{-j\frac{2\pi}{N}kn}$ olur:

$$X[k]=\sum_{n=0}^{N-1}x[n]\,e^{-j\frac{2\pi}{N}kn}=X(e^{j\Omega})\Big|_{\Omega=\frac{2\pi}{N}k},\qquad k=0,1,\dots,N-1$$

(ekrandan, 01:10:00)

Tahtadaki not: $x[n]$'in DTFT'si ile karşılaştırılırsa DFT katsayıları DTFT'nin örnekleridir.

> **Ders sonrası not:** Tahtada örnekleme noktası $\Omega=\frac{2\pi}{N}nk$ diye yazıldı (ekrandan, 01:10:00). Doğrusu $\Omega=\frac{2\pi}{N}k$'dir; $n$ zaman indisidir ve üstel terimde zaten ayrıca çarpan olarak yer alır.

Burada iki indis vardır. $n$ ayrık örnek (zaman) indisidir ve $0$'dan $N-1$'e kadar gider. $k$ ayrık frekans indisidir ve o da $0$'dan $N-1$'e kadar gider. DFT sonlu uzunluklu diziler için tanımlandığından, kaç örnek alındıysa frekans da tanım gereği o kadar parçaya bölünür. Örneğin bir işaretten 128 örnek alınırsa frekans ekseni de 128 parçaya bölünür. Yani alınan örnek sayısı $N$, frekansın kaç parçaya bölüneceğini belirler.

**Soru:** DTFT ile eşitlik yazılan yerde $X(e^{j\Omega})$'nın sağındaki dikey çizgi ve alt yazı ne anlama geliyor? **Cevap:** O ifade, $X(e^{j\Omega})$'nın $\Omega=2\pi k/N$ noktalarında aldığı değerleri gösterir. DTFT'nin bu noktalardaki değerleri DFT katsayılarını verir.

### 5.3 DTFT'den DFT'ye özet

Hoca bütün anlatımı şöyle bağladı: Önce zaman uzayında, belli bir frekans içeriği olan bir işaret vardır. İşaret ayrıklaştırılınca frekans uzayı simetrik ve periyodik olur; buna DTFT denir ve bu matematiksel bir ara formdur. Asıl hedef hem işaretleri hem de frekans karşılıklarını ayrık elde etmektir. DTFT'den alınan örneklerle ayrıktan ayrığa geçilir ve iki tarafta da bilgisayarda çalışılabilir. Bunu hızlı yapan algoritma FFT'dir (Fast Fourier Transform); DFT'nin algoritmik olarak nasıl hızlandırıldığı sayısal işaret işleme dersinde ayrıntılı anlatılır.

> **Ek bilgi (derste anlatılmadı):** DFT tanımı doğrudan hesaplanırsa $N$ frekansın her biri için $N$ çarpma gerektiğinden işlem sayısı $N^2$ mertebesindedir. FFT algoritmaları bu sayıyı $N\log_2 N$ mertebesine indirir. Bu yüzden $N$ genellikle 256, 1024 gibi 2'nin kuvveti seçilir.

## 6. Örtüşme (Aliasing) ve Beş Bileşenli İşaret Örneği

### 6.1 Örtüşme nedir?

$f_s<2f_{max}$ olduğunda, $f_s$ çevresinde oluşan kopya özgün spektrumun içine girer. Bu bölgede frekanslar toplanır ve özgün frekansın görüntüsü kaybolur; özellikle yüksek frekanslardaki özgün içerik yok olur. Bu olaya örtüşme (aliasing) denir.

### 6.2 Örnek (S1)

Soru (ekrandan, 01:30:00):

$$x_a(t)=\cos(2\pi5600t)+\cos(2\pi8400t)+\cos(2\pi11200t)+\cos(2\pi16800t)+\cos(2\pi25200t)$$

Sürekli zaman işareti $F_s=33600$ Hz örnekleme frekansında örnekleniyor. a) $x[n]$ sayısal işareti nedir? b) Aliasing var mıdır? Varsa hangi frekanslar için vardır? c) Aliasing oluşmaması için gerekli minimum örnekleme frekansı nedir?

Hoca önce derste şu soruyu sordu: Bu işaretteki $f_{max}$ nedir? Cevap 25200 Hz'dir. Buna göre minimum örnekleme frekansı $2\times25200=50400$ Hz olmalıdır. Verilen 33600 Hz bundan küçük olduğu için örtüşme olacaktır.

**a) Sayısal işaret.** $x[n]=x_a(nT_s)$; yani $t$ gördüğümüz yere $nT_s=n/F_s$ konur (ekrandan, 01:35:00). Örneğin üçüncü bileşen için:

$$\cos\!\left(2\pi\,\frac{11200}{33600}\,n\right)=\cos\!\left(\frac{2\pi}{3}n\right)$$

Buradaki $2\pi/3$, $\Omega$ sayısal frekansıdır. Hepsi için aynı işlem yapılınca:

$$x[n]=\cos\!\left(\frac{\pi}{3}n\right)+\cos\!\left(\frac{\pi}{2}n\right)+\cos\!\left(\frac{2\pi}{3}n\right)+\cos(\pi n)+\cos\!\left(\frac{3\pi}{2}n\right)$$

33600'ün yarısı 16800'dür ve $\cos(\pi n)$ terimi 16800 Hz'lik bileşenden gelir. Yani bu örnekleme frekansında en yüksek frekansın $\pi$'de oluşması gerekir. 16800 Hz'i aşan 25200 Hz bileşeni ($3\pi/2$), $\pi$'yi $\pi/2$ kadar aşmıştır ve örtüşmeye yol açar.

**b) Spektrum çizimi ve örtüşen frekanslar.** $X(e^{j\Omega})$, bileşenlerin bulunduğu frekanslarda birer çizgi olarak çizildi (ekrandan, 01:40:00). Bileşenler $\pm\pi/3$, $\pm\pi/2$, $\pm2\pi/3$, $\pm\pi$ ve $\pm3\pi/2$'dedir. Hepsinin genliği aynı (1) olduğundan çizgiler aynı yükseklikte çizildi; normalde bir frekanstan daha çok varsa onun genliği yüksek olur. Spektrum $2\pi$ periyotlu olduğundan $2\pi$ merkezli kopyada bileşenler $2\pi\mp\pi/3$ ($5\pi/3$, $7\pi/3$), $2\pi-\pi/2=3\pi/2$, $2\pi-2\pi/3=4\pi/3$, $\pi$ ve $2\pi-3\pi/2=\pi/2$ gibi noktalara düşer.

Sonuç: 25200 Hz'lik bileşen $\pi$'nin dışına çıkıp $3\pi/2$'de oluşmuştur. Yan kopyadaki karşılığı $\pi/2$'ye düşer ve orada 8400 Hz'lik bileşenin üstüne biner. İkisi de $\pi$'den $\pi/2$ uzaklıktadır. Hertz cinsinden: $33600-25200=8400$ Hz. Aynı şekilde $-3\pi/2$ ile $-\pi/2$ de çakışır. Ekrandaki çözüm metni: "33600 Hz < 2 × 25200 Hz olduğundan aliasing oluşur, aliasing 25200 Hz frekansı için oluşmaktadır" (ekrandan, 01:35:00).

**c) Minimum örnekleme frekansı.** $f_s\ge2f_{max}=50400$ Hz (ekrandan, 01:45:00).

### 6.3 $f_s=50400$ Hz ile tekrar

Hoca, $f_s=50400$ Hz seçilseydi ne olacağını da çizdi (ekrandan, 01:50:00). Her bileşen için oran sadeleştirildi (değerler derste öğrencilerle birlikte bulundu):

- $5600/50400=1/9\Rightarrow\cos\left(\frac{2\pi}{9}n\right)$
- $8400/50400=1/6\Rightarrow\cos\left(\frac{\pi}{3}n\right)$
- $11200/50400=2/9\Rightarrow\cos\left(\frac{4\pi}{9}n\right)$
- $16800/50400=1/3\Rightarrow\cos\left(\frac{2\pi}{3}n\right)$
- $25200/50400=1/2\Rightarrow\cos(\pi n)$

$$x[n]=\cos\!\left(\frac{2\pi}{9}n\right)+\cos\!\left(\frac{\pi}{3}n\right)+\cos\!\left(\frac{4\pi}{9}n\right)+\cos\!\left(\frac{2\pi}{3}n\right)+\cos(\pi n)$$

Bu kez bütün bileşenler $[-\pi,\pi]$ içindedir. $2\pi$ merkezli kopyada bileşenler $2\pi\pm2\pi/9$ ($16\pi/9$ ve $20\pi/9$), $2\pi\pm\pi/3$ vb. noktalara düşer. En yüksek bileşen tam sınırdadır: $\pi$'deki bileşen ile kopyanın $\pi$'deki bileşeni aynı frekansa (25200 Hz) denk gelir. Hoca bunu örtüşme saymadı, çünkü farklı bir frekans farklı bir frekansı ezmemiştir; üst üste gelen, aynı frekanslardır.

> **Ders sonrası not:** Derste işaretin "3 tane sinüzoidalin toplamı" olduğu söylendi; ekrandaki soruda işaret 5 kosinüsün toplamıdır (5600, 8400, 11200, 16800 ve 25200 Hz). Python ile her bileşenin $2f/f_s$ oranı iki örnekleme frekansı için de doğrulandı.

## 7. DFT İndislerinin Analog Frekansa Çevrilmesi

### 7.1 Soru (S2)

Soru (ekrandan, 01:55:00): 15 kHz ile bant sınırlı $x_a(t)$ sürekli işareti $f_s=30$ kHz'de örnekleniyor ve elde edilen $x(n)$'in DFT'si $N=2000$ örnek için hesaplanıyor.

$$X(k)=\sum_{n=0}^{N-1}x(n)\,e^{-j\frac{2\pi}{N}nk}$$

olmak üzere: a) $k=200$ ve $k=1200$ indisleri hangi analog frekans değerlerine denk düşmektedir? b) Spektral örnekler arasındaki mesafe $\Delta f$ nedir?

İşaret tam sınırda ($f_s=2f_{max}$) örneklendiği için örtüşme yoktur.

### 7.2 Çözüm

Frekans içeriği $[-\pi,\pi]$ aralığında düşünülürse 2000 parçanın 1000'i pozitif, 1000'i negatif taraftadır. Spektrum $2\pi$ periyotlu olduğundan aynı şey $[0,2\pi]$ aralığında da incelenebilir. DFT formülünde $k$ eksi değer almaz, $0$'dan $1999$'a kadar gider; yani hesap $[0,2\pi]$ aralığında yapılır (ekrandan, 02:00:00). Bu durumda $[\pi,2\pi]$ aralığındaki örnekler aslında negatif frekanslardır.

$\pi$'deki frekans $f_s/2=15$ kHz'dir ve 1000. örneğe denk gelir. Basit bir orantıyla:

$$k=200:\qquad \frac{1000}{15\text{ kHz}}=\frac{200}{f}\ \Rightarrow\ f=3\text{ kHz}$$

$k=1200$ ise $\pi$'yi 200 birim aşmıştır, negatif frekans bölgesindedir. $[0,2\pi]$ ekseninde frekans $0$'dan $15$ kHz'e çıkar, $\pi$'den sonra $-15$ kHz'den $0$'a doğru geri iner. Hoca bunu iki yoldan gösterdi (ekrandan, 02:05:00):

- $-15$ kHz'den 200 birim ileri gidilir: $-15+3=-12$ kHz.
- $k=1200$, $k=800$'ün simetrik karşılığıdır. $800$. örnek $800\cdot15/1000=12$ kHz'dir; $\pi$'yi aşan taraf negatif frekans olduğu için $k=1200$, $-12$ kHz'e denk gelir.

Benzer şekilde $k=1800$, $k=200$'ün negatif karşılığıdır ve $-3$ kHz'i gösterir.

**Soru:** Grafikte dikey eksen hep pozitif; "eksi" demek için dikey koordinatın negatif olması gerekmez mi? **Cevap:** Hayır. Yatay eksen $\Omega$'yı, yani frekansı gösterir; dikey eksen katsayının genliğini ($|X(e^{j\Omega})|$) gösterir. Negatif frekans, yatay eksendeki konumla ilgilidir.

(b şıkkı derste çözülmedi; çözümü Örnek Sorular bölümündedir.)

## 8. MATLAB'de FFT: EKG Parçası

### 8.1 İşaretin yüklenmesi ve çizimi

Hoca MATLAB'de 256 örneklik bir EKG parçası yükledi (`ECGsegment256.mat`). Hastanede ekranda arka arkaya görülen kalp atımlarından bir segmenttir. Ekrandaki komutlar (ekrandan, 02:10:00):

```matlab
load('ECGsegment256.mat', 'segmentECG256sample')
plot(x)
hold on
stem(x)
plot(x)
X = fft(x);
```

Ayrık bir işaret aslında `stem` ile çizilmelidir, çünkü `stem` örnekleri tek tek çubuk olarak gösterir. Ancak çok sayıda örnek olduğunda `plot` daha okunaklı olduğu için gösterimde `plot` kullanıldı.

### 8.2 FFT ve karmaşık çıktı

MATLAB'de DFT'nin karşılığı `fft` fonksiyonudur. FFT (Fast Fourier Transform) aynı DFT'yi daha hızlı gerçekleştirir. `x` gerçel sayılardan (`1x256 double`) oluşurken `X=fft(x)` sonucu `1x256 complex double` oldu (ekrandan, 02:10:00). Bunun nedeni $X(e^{j\Omega})$'nın karmaşık değer almasıdır; DTFT'den alınan DFT örnekleri de karmaşıktır. Spektrum çizimlerinde aslında hep $|X(e^{j\Omega})|$, yani mutlak değer çizilir.

> **Ders sonrası not:** Derste ilk değerin (sıfır frekansı, DC bileşen) "daima sıfır" olduğu söylendi. Ekranda $X$'in ilk elemanı $5.9397\times10^{5}$'tir (ekrandan, 02:10:00). Doğrusu: gerçel bir işaretin DFT'sinde $X[0]=\sum_n x[n]$ olduğundan DC bileşen sıfır değil, gerçeldir (karmaşık kısmı yoktur). Hocanın kastettiği büyük olasılıkla DC bileşenin karmaşık olmadığıdır.

`plot(X)` komutu anlamsız bir şekil verdi. Hoca nedenini sordu: $z=a+jb$ biçimindeki bir sayının iki bileşeni vardır ve `plot` bunu doğrudan genlik olarak çizemez. Spektrumu görmek için mutlak değer alınmalıdır:

```matlab
figure
plot(abs(X))
```

Çizimde enerji yalnızca alçak frekanslarda toplandı; diğer frekanslarda genlik çok küçük kaldı. Spektrum simetriktir; $[0,2\pi]$ gösteriminde DC bileşenin simetrik karşılığı uçtadır (255. örnek civarı). Örnekleme frekansı bilinmeden hangi örneğin hangi analog frekansa denk geldiği söylenemez; bu örnekte yalnızca FFT alınmış oldu.

### 8.3 `fftshift`

```matlab
Xshifted = fftshift(X);
plot(abs(Xshifted))
```

(ekrandan, 02:30:00)

`fft` çıktısı $[0,2\pi]$ aralığına karşılık gelir. `fftshift` ise sıfır frekansı ortaya (128. örneğe) taşır: solda $-\pi$, ortada $0$ Hz, sağda $+\pi$ olur; sağa doğru pozitif, sola doğru negatif frekanslar yer alır (ekrandan, 02:15:00). Yani $[-\pi,\pi]$ gösterimini sağlar.

Hoca bir işaretin iki türlü gösterilebileceğini tekrarladı: $0$ ile $f_s$ arası ($[0,2\pi]$) ya da $-f_s/2$ ile $f_s/2$ arası ($[-\pi,\pi]$). İki gösterim aynıdır; ikisinde de $0$ Hz'den pozitife doğru gidilir, ilkinde negatif frekanslar $f_s$'ten geriye doğru yayılmıştır. FFT'de genlik (magnitude) çizilir; faz (açı) çizilmek istenirse açı kısmına ayrıca dikkat edilmelidir.

## 9. Gerçek Hayat Örneği: DTMF Tuşlu Telefon İşaretleri

### 9.1 DTMF mantığı

Tuşlu telefonlarda, cep telefonlarında ve telefon bankacılığında bir tuşa basıldığında duyulan sesler DTMF işaretleridir. Her tuş iki frekansın birleşimidir. Kullanılan frekanslar (ekrandan, 02:25:00):

- Düşük grup: 697, 770, 852, 941 Hz
- Yüksek grup: 1209, 1336, 1477, 1633 Hz

4×4'lük tuş takımında (rakamlar, yıldız, kare ve dört ek tuş) her tuş bir düşük ve bir yüksek frekansın kesişimidir. Örneğin tahtada işaretlenen tuş 770 Hz ve 1336 Hz'den oluşur:

$$x(t)=\cos(2\pi\,770\,t)+\cos(2\pi\,1336\,t)$$

İki sinüsün toplamı tel üzerinden karşı tarafa gönderilir. Karşı tarafta işaret örneklenir ve FFT yardımıyla hangi iki frekansın gönderildiği bulunur.

> **Ek bilgi (derste anlatılmadı):** Standart DTMF tuş takımında düşük grup frekansları satırları (697: 1-2-3-A, 770: 4-5-6-B, 852: 7-8-9-C, 941: *-0-#-D), yüksek grup frekansları sütunları (1209, 1336, 1477, 1633) belirler. Buna göre 770+1336 Hz "5" tuşuna, 697+1336 Hz "2" tuşuna karşılık gelir. Tahtadaki çizimde frekanslar satır/sütun olarak farklı yerleştirilmiştir.

### 9.2 Örnekleme frekansı seçimi

**Soru (derste sözlü):** Bu sistemde örnekleme frekansı en az kaç seçilmelidir? **Cevap:** Bir öğrenci en yüksek frekansın 1633 Hz olduğunu ve $f_s$'in bunun iki katı olması gerektiğini söyledi; hoca doğruladı. $2\times1633=3266$ Hz (ara adım eklendi). Hoca güvenlik payı bırakmak için dosyaları 4 kHz ile örnekledi.

Dosyalar iki sinüs toplanarak üretilmiştir (örneğin 697 Hz ile 1477 Hz), her biri 256 örnektir; karşı tarafta 256 noktalık FFT ile okunması beklenir. $f_s=4$ kHz için $[0,2\pi]$ aralığında 256 örnek vardır; $\pi$ ($f_s/2$) 2 kHz'e, yani 128. örneğe denk gelir. Bir tepenin konumu bilinirse orantıyla frekansı bulunur. Yalnızca $[0,\pi]$ aralığını değerlendirmek yeterlidir.

### 9.3 Bilinmeyen bir tuşun bulunması (`g.data`)

Hoca, içinde hangi frekansların olduğunu bilmediği `g.data` dosyasını açtı (ekrandan, 02:30:00):

```matlab
x = load('g.data');
plot(x)
sound(x)
sound([x x x])
X = fft(x);
plot(abs(X))
```

`plot(x)` iki sinüsün toplamının oluşturduğu dalga şeklini gösterdi. `sound` ile basılan tuşun sesi dinletildi; dizi kendisiyle art arda eklenerek uzatıldı. FFT genliğinde 0 ile 256 arasında dört tepe görüldü. $[0,2\pi]$ aralığında çalışıldığı ve iki kosinüs olduğu için dört tepe normaldir: 0-128 arası pozitif, 128-256 arası negatif frekanslardır.

Pozitif taraftaki tepeler 46. ve 87. örnekte bulundu. 128. örnek 2000 Hz olduğuna göre (ekrandan, 02:35:00):

$$f_1=\frac{46\times2000}{128}\approx718\text{ Hz},\qquad f_2=\frac{87\times2000}{128}\approx1359\text{ Hz}$$

718 Hz'e en yakın DTMF frekansı 697 Hz, 1359 Hz'e en yakını 1336 Hz'dir. Demek ki 697 Hz ve 1336 Hz'den oluşan tuşa basılmıştır.

> **Ders sonrası not:** MATLAB dizileri 1'den başladığı için grafikte okunan $i$. eleman $k=i-1$ frekans indisidir; doğru eşleme $f=(i-1)\,f_s/N$'dir: $45\times4000/256\approx703$ Hz ve $86\times4000/256\approx1344$ Hz. Python ile 697 Hz + 1336 Hz, $f_s=4$ kHz, $N=256$ işaretinin genlik tepeleri gerçekten 46. ve 87. elemanda çıktı. Yorum ve sonuç (697 Hz ve 1336 Hz) değişmez.

## Örnek Sorular

### Soru 1: Fark denkleminden frekans cevabı

(ekrandan, 00:35:00) $y[n]=1.34\,y[n-1]-0.9\,y[n-2]+x[n]-1.41\,x[n-1]+x[n-2]$ ile verilen sistemin $H(e^{j\Omega})$ frekans cevabını bulunuz.

> **Çözüm:** İki tarafın DTFT'si alınır; $x[n-n_0]\leftrightarrow e^{-jn_0\Omega}X(e^{j\Omega})$ kullanılır. $Y$'li terimler bir tarafa toplanır: $Y(e^{j\Omega})[1-1.34e^{-j\Omega}+0.9e^{-j2\Omega}]=X(e^{j\Omega})[1-1.41e^{-j\Omega}+e^{-j2\Omega}]$. Buradan $H(e^{j\Omega})=\dfrac{1-1.41e^{-j\Omega}+e^{-j2\Omega}}{1-1.34e^{-j\Omega}+0.9e^{-j2\Omega}}$ (ekrandan, 00:40:00). $h[n]$ istenirse ters DTFT uygulanır.

### Soru 2: Beş bileşenli işarette örtüşme

(ekrandan, 01:30:00) $x_a(t)=\cos(2\pi5600t)+\cos(2\pi8400t)+\cos(2\pi11200t)+\cos(2\pi16800t)+\cos(2\pi25200t)$ sürekli zaman işareti $F_s=33600$ Hz örnekleme frekansında örnekleniyor. a) $x(n)$ sayısal işareti nedir? b) Aliasing var mıdır? Varsa hangi frekanslar için vardır? c) Aliasing oluşmaması için gerekli minimum örnekleme frekansı nedir?

> **Çözüm:** a) $t\to nT_s$: $x[n]=\cos(\frac{\pi}{3}n)+\cos(\frac{\pi}{2}n)+\cos(\frac{2\pi}{3}n)+\cos(\pi n)+\cos(\frac{3\pi}{2}n)$ (ekrandan, 01:35:00). b) $33600<2\times25200$ olduğundan aliasing vardır; 25200 Hz bileşeni ($3\pi/2$) $\pi$'yi aşar, $2\pi-3\pi/2=\pi/2$'ye düşer ve 8400 Hz ile örtüşür ($33600-25200=8400$). c) $f_s\ge2\times25200=50400$ Hz (ekrandan, 01:45:00). Bu durumda $x[n]=\cos(\frac{2\pi}{9}n)+\cos(\frac{\pi}{3}n)+\cos(\frac{4\pi}{9}n)+\cos(\frac{2\pi}{3}n)+\cos(\pi n)$ olur (ekrandan, 01:50:00).

### Soru 3: DFT indislerinin analog frekansı

(ekrandan, 01:55:00) 15 kHz ile bant limitli $x_a(t)$ sürekli işareti $f_s=30$ kHz'de örnekleniyor ve elde edilen $x(n)$'in DFT'si $N=2000$ örnek için hesaplanıyor. $X(k)=\sum_{n=0}^{N-1}x(n)e^{-j\frac{2\pi}{N}nk}$ olmak üzere: a) $k=200$ ve $k=1200$ indisleri hangi analog frekans değerlerine denk düşmektedir? b) Spektral örnekler arasındaki mesafe $\Delta f$ nedir?

> **Çözüm (a şıkkı derste verildi):** 1000. örnek 15 kHz'dir. $k=200\Rightarrow200\cdot15/1000=3$ kHz. $k=1200>1000$ olduğundan negatif frekanstır: $k=800$'ün (12 kHz) simetriği, yani $-12$ kHz (ekrandan, 02:00:00 ve 02:05:00).

> **Çözüm (derste verilmedi):** b) Spektral örnekler $2\pi/N$ aralıklıdır; Hertz cinsinden $\Delta f=f_s/N=30000/2000=15$ Hz. Bu, a şıkkıyla da tutarlıdır: $200\times15=3000$ Hz, $1200\times15-30000=-12000$ Hz (Python ile doğrulandı).

### Soru 4: En yüksek frekans ve minimum örnekleme frekansı

(derste sözlü, 01:30:38) Soru 2'deki işaretin $f_{max}$ değeri nedir ve örtüşme olmaması için en düşük örnekleme frekansı ne olmalıdır?

> **Çözüm:** $f_{max}=25200$ Hz; $f_s\ge2f_{max}=50400$ Hz. Verilen 33600 Hz bundan küçük olduğu için örtüşme olur.

### Soru 5: DTMF sisteminde örnekleme frekansı

(derste sözlü, 02:22:44) Tuş sesleri 697, 770, 852, 941, 1209, 1336, 1477 ve 1633 Hz frekanslarının ikişerli toplamından oluşuyorsa, örnekleme frekansı en az kaç seçilmelidir?

> **Çözüm:** En yüksek frekans 1633 Hz olduğundan $f_s\ge2\times1633=3266$ Hz. Derste güvenlik payı için 4 kHz kullanıldı.

### Soru 6: Ödev 2, DTMF dosyalarının çözümlenmesi

(derste sözlü, 02:35:08 ve 02:38:54) $f_s=4$ kHz ile örneklenmiş, her biri 256 örnekten oluşan ve harflerle adlandırılmış DTMF dosyalarının her biri için FFT alınız, $|$FFT$|$ grafiğini çiziniz, tepe noktalarını belirleyiniz ve her dosyada hangi iki frekansa (697, 770, 852, 941, 1209, 1336, 1477, 1633 Hz) basıldığını bulunuz. Frekansları satır ve sütunları açıkça belirtilmiş bir matris yapısında gösteriniz.

> **Çözüm yolu (derste `g.data` için gösterildi):** `x=load('g.data'); X=fft(x); plot(abs(X))`. $[0,\pi]$ aralığındaki iki tepenin konumu bulunur ve orantıyla frekansa çevrilir (128. örnek $\approx$ 2 kHz). `g.data` için tepeler 46 ve 87, frekanslar yaklaşık 718 Hz ve 1359 Hz, yani 697 Hz ve 1336 Hz. Diğer dosyaların verisi derste gösterilmediği için çözümleri burada verilemez.

## Dersin Toparlaması

Bu derste DTFT'nin pratik kullanımı ve DTFT'den DFT'ye geçiş işlendi. Önce yalnızca giriş ve çıkış örnekleriyle verilen bir fark denkleminin frekans cevabı, öteleme özelliği ve "konvolüsyon frekansta çarpmadır" ilkesiyle bulundu. Ardından örneklemenin frekans uzayında spektrumu simetrik ve periyodik yaptığı, $f_s\ge2f_{max}$ koşulu sağlanmazsa kopyaların iç içe girerek örtüşmeye yol açtığı ve $f_s/2$'nin sayısal frekansta daima $\pi$'ye denk geldiği gösterildi. Beş bileşenli işaret örneğinde 25200 Hz bileşeninin 33600 Hz örneklemede 8400 Hz ile örtüştüğü, 50400 Hz'de ise örtüşmenin kalktığı görüldü.

Dersin ikinci yarısında DTFT'nin sürekli frekans ekseni $N$ parçaya bölünerek DFT tanımlandı: $X[k]=X(e^{j\Omega})|_{\Omega=2\pi k/N}$. DFT indislerinin analog frekansa çevrilmesinde $N/2$'den büyük indislerin negatif frekanslara karşılık geldiği vurgulandı. MATLAB'de EKG parçası üzerinde `fft`, `abs` ve `fftshift` kullanıldı. Son olarak DTMF tuş sesleri üzerinden FFT ile bir işaretin içindeki frekansların nasıl bulunacağı gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
