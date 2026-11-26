# Ders 10 Genişletilmiş Notu: Fourier Serileri, Fourier Dönüşümü ve Frekans Cevabı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Frekans Düzlemi Analizinin Sınıflandırılması
- 2. Sinüzoitlerin Toplamı ve Spektrum Gösterimi
- 3. Temel Frekans
- 4. Zaman-Frekans Analizi: Spektrogram ve Tını
- 5. Sürekli Zamanlı Fourier Serisi Formülleri
- 6. Kare Dalga Örneği: Trigonometrik Biçim
- 7. Kare Dalga Örneği: Üstel Biçim
- 8. Ayrık Zamanlı Fourier Serisi
- 9. Fourier Sentezi ve Gibbs Olayı
- 10. Fourier Dönüşümü
- 11. Fourier Dönüşümünün Özellikleri
- 12. Ayrık Zamanlı Fourier Dönüşümü
- 13. Frekans Cevabıyla Fark ve Diferansiyel Denklem Çözümü
- 14. Fourier'in Bilgisayar Mühendisliğindeki Yeri
- Örnek Sorular

## 1. Frekans Düzlemi Analizinin Sınıflandırılması

Ders, önceki haftada başlanan frekans düzlemi konusunun toparlanmasıyla açıldı. Frekans düzlemine geçmenin temel nedeni, davranışı diferansiyel denklemlerle modellenen sistemlerin zamanda çözümünün zor olmasıdır. Frekans düzlemine geçmek hem çözümü kolaylaştırır hem de işaret hakkında ek bilgi (hangi frekansları hangi genlik ve fazla içerdiği) verir.

Bir işaret frekans düzleminde incelenmeden önce iki soru sorulur: işaret sürekli mi ayrık mı, ve periyodik mi değil mi? Bu iki sorunun cevabına göre dört farklı araç kullanılır (ekrandan, 00:15:00):

- Sürekli ve periyodik işaret: Fourier serisi. Genelde yalnız "Fourier series" denir, "Continuous Time Fourier Series" (CTFS) adı da kullanılır.
- Ayrık ve periyodik işaret: ayrık Fourier serisi (DFS) ya da ayrık Fourier dönüşümü (DFT).
- Sürekli ve periyodik olmayan işaret: Fourier dönüşümü (FT). Fourier serisinin periyodu sonsuz alınmış genelleştirilmiş hâlidir. "Fourier dönüşümü" denince genelde sürekli zaman anlaşılır.
- Ayrık ve periyodik olmayan işaret: ayrık zamanlı Fourier dönüşümü (DTFT).

Bir işaretin periyodik olup olmadığı, her $t$ (ya da $n$) için $x(t+T)=x(t)$ sağlayan bir $T$ bulunup bulunmadığıyla anlaşılır.

Bütün yöntemlerde yapılan iş aynıdır. Hoca tahtada bunu şöyle çizdi (ekrandan, 00:15:00):

```text
zaman düzlemindeki işaret --T--> frekans bileşenleri --işlem/algoritma--> yeni frekans bileşenleri --T^-1--> zaman düzleminde yeni işaret
```

En basit uygulama konvolüsyondur. Konvolüsyon zaman düzleminde zor bir işlemdir; frekans düzleminde ise iki dönüşümün noktasal çarpımıdır:

$$x(t)*y(t)\;\longleftrightarrow\;X(\omega)\,Y(\omega)$$

Benzer şekilde, $y''(t)+\dots$ biçiminde bir diferansiyel denklemle tanımlanan bir sistemin frekans düzlemindeki karşılığı alınır, cebirsel işlemlerle çözülür ve ters dönüşümle zamana dönülür.

## 2. Sinüzoitlerin Toplamı ve Spektrum Gösterimi

### 2.1 Sentez ve spektrum

Dersin bu bölümünde kullanılan slaytlar sinüzoitler ve spektrum üzerineydi. Amaç, herhangi bir işareti en temel doğal fonksiyon olan kosinüs (sinüzoit) bileşenlerine ayırmaktır. Periyodik bir işaret belirli genlik, frekans ve fazlara sahip kosinüslerin toplamı olarak yazılır (ekrandan, 00:20:00):

$$x(t)=A_0+\sum_{k=1}^{N}A_k\cos(2\pi f_k t+\varphi_k)$$

Bu toplamı oluşturmaya **sentez**, verilen işaretten $A_k$, $f_k$, $\varphi_k$ değerlerini bulmaya **analiz** denir. Sentez kolaydır: genlik, frekans ve faz bilgisi verildiğinde bileşenler toplanır (bir döngüyle beş sinüzoidi üst üste eklemek gibi). Analiz zordur: işaretin periyodik olup olmadığına ve süreksizlik noktalarına bakmak, ardından katsayıları hesaplamak gerekir.

Hoca bu yaklaşımın çoğu zaman işe yaradığını, fakat keskin köşeli (süreksiz) işaretlerde köşelerin sonlu sayıda sinüzoitle tam üretilemediğini belirtti.

Spektrum grafiğinde frekans eksenindeki her çizgi bir bileşeni gösterir. Örneğin sıfır frekanslı (DC) bileşen 10 genlikli, 100 Hz'deki bileşen $7e^{\pm j\pi/3}$ karmaşık genlikli olabilir. Böyle bir grafikle işaretin içeriği bir bakışta görülür. Müzikteki nota kâğıdı da bir tür frekans diyagramıdır: dikey eksen frekansı (nota), yatay eksen zamanı (sırayı) gösterir.

### 2.2 Euler bağıntıları

Euler formülü bu konunun temel aracıdır:

$$\cos\theta=\frac{e^{j\theta}+e^{-j\theta}}{2},\qquad \sin\theta=\frac{e^{j\theta}-e^{-j\theta}}{2j}$$

Örneğin $\frac{A}{2}\left(e^{j7t}+e^{-j7t}\right)$ ifadesi görüldüğünde bunun $A\cos7t$ olduğu, yani fazı sıfır, frekansı 7 rad/s olan bir bileşen olduğu anlaşılır. Sıfır frekanslı terimde $e^{j0}=1$ olduğundan DC katsayısı doğrudan okunur.

Faz eklenince bu ifade şöyle genelleşir:

$$A\cos(\omega t+\varphi)=\frac{A}{2}e^{j\varphi}e^{j\omega t}+\frac{A}{2}e^{-j\varphi}e^{-j\omega t}$$

Slayttaki sinüs örneği (ekrandan, 00:30:00):

$$A\sin(7t)=\tfrac12Ae^{-j0.5\pi}e^{j7t}+\tfrac12Ae^{j0.5\pi}e^{-j7t}$$

Spektrumda $\omega=7$'de $\left(\tfrac12A\right)e^{-j0.5\pi}$, $\omega=-7$'de $\left(\tfrac12A\right)e^{j0.5\pi}$ çizgisi vardır; grafik genlik, faz ve frekansı birlikte gösterir.

Slayttaki bir diğer örnekte 100 Hz ve 250 Hz'lik bileşenler vardı: 100 Hz'lik bileşenin fazı $-\pi/3$ ve $+\pi/3$ (pozitif ve negatif frekans için) olarak yazılmıştı. Bu karmaşık üstel çiftleri Euler bağıntısıyla birleştirilince işaret $A_0+A_1\cos(2\pi\,100\,t+\varphi_1)+A_2\cos(2\pi\,250\,t+\varphi_2)$ biçimine döner.

> **Hocanın vurgusu:** Üstellerle verilmiş bir ifadeyi kosinüslü forma (ya da tersine) çevirmek ve spektrumunu çizmek sınavda büyük olasılıkla gelir. İki değil üç bileşen verilebilir; o zaman toplamda bir kosinüs ya da sinüs terimi daha olur.

Asıl önemli olan, işaret açıkça kosinüslerin toplamı olarak verilmediğinde bileşenleri bulmaktır. Kare dalga, testere dişi ya da üçgen dalgada sonsuz sayıda kosinüs vardır; bunların ilk birkaçını bulmak Fourier serisinin işidir.

### 2.3 Negatif frekans

Matematikte her kosinüs pozitif ve negatif frekanslı iki üstele ayrılır. Hoca negatif frekansın fiziksel bir örneği olarak polis radarını verdi: araçtan yansıyan sinyalin frekans kayması pozitifse araç yaklaşıyor, negatifse uzaklaşıyordur. Yaklaşan ve uzaklaşan bir trenin düdük sesinin değişmesi de aynı etkiye (Doppler) örnektir.

### 2.4 Sesli harf örneği

Bir sesli harfin spektrumu slaytta genlik ve faz olarak iki ayrı grafikte verildi (ekrandan, 00:35:00). Bileşenler yaklaşık $\pm200$, $\pm400$, $\pm500$, $\pm1600$, $\pm1700$ Hz'deydi. Genlik grafiğinde çizgi yükseklikleri $0.5A_k$, faz grafiğinde değerler $\varphi_k$ idi. Bu beş terim $A_k\cos(2\pi f_k t+\varphi_k)$ biçiminde toplanınca, periyodu yaklaşık 10 ms olan, $T_0=1/f_0$ bağıntısını sağlayan bir dalga elde edilir.

## 3. Temel Frekans

Temel frekans, işaretteki bütün bileşen frekanslarının en büyük ortak bölenidir (OBEB, GCD).

- $100$ ve $250$ Hz bileşenleri olan bir işaretin temel frekansı $50$ Hz'dir.
- $10$, $30$, $50$ Hz bileşenlerinde temel frekans $10$ Hz'dir. Bu üç bileşen toplanınca kare dalgaya benzeyen bir dalga oluşur.
- Sesli harf örneğindeki $200, 400, 500, 1600, 1700$ Hz'nin temel frekansı $100$ Hz'dir.
- Telefon sinyali örneğindeki $648$ ve $672$ Hz'nin temel frekansı $24$ Hz'dir (en küçük frekans olan 648 değil).
- Frekanslar $1.5$ ve $4.5$ Hz ise temel frekans $1.5$ Hz'dir.

Temel frekansın kendisi ya da bazı katları (sesli harf örneğinde 100, 300, 600 Hz gibi) spektrumda görünmeyebilir. Bu, o frekansların işarette olmadığı değil, genliklerinin sıfır olduğu anlamına gelir.

> **Hocanın vurgusu:** Birçok kaynakta ya da derste en küçük frekansın temel frekans olduğu söylenir; bu yanlıştır. Temel frekans bütün frekansların OBEB'idir.

Temel frekans bir işaretin periyodikliğiyle de bağlantılıdır. $e^{j\omega(t+T)}=e^{j\omega t}e^{j\omega T}$ olduğundan, $e^{j\omega T}=1$ ise işaret $T$ ile periyodiktir. Birim çemberde $\cos2\pi=1$, $\sin2\pi=0$ olduğu için $\omega T=2\pi k$ ($k$ tam sayı) olduğunda bu sağlanır.

Python ile kontrol: $\gcd(100,250)=50$, $\gcd(200,400,500,1600,1700)=100$, $\gcd(648,672)=24$, $\gcd(10,30,50)=10$.

## 4. Zaman-Frekans Analizi: Spektrogram ve Tını

### 4.1 Spektrogram

Fourier dönüşümüyle frekansa geçildiğinde zaman bilgisi kaybolur. Frekans düzlemindeki sonuçta $t$ bulunmaz; bulunuyorsa dönüşüm yanlış yapılmıştır. Ancak çoğu uygulamada hangi frekansın hangi zaman aralığında baskın olduğunu bilmek gerekir (örneğin 10 saniyelik bir seste).

Spektrogram bunun için kullanılan bir zaman-frekans görselleştirme aracıdır (MATLAB'de de bu adla bulunur). İşaret çok kısa zaman aralıklarına bölünür, her aralıkta ayrı ayrı Fourier analizi yapılır. Böylece her aralıkta hangi frekansların bulunduğu görülür.

Slaytlarda şu örnekler gösterildi:

- Gamın notaları: ilk nota yaklaşık 250-260 Hz, bir sonraki yaklaşık 300 Hz civarındadır.
- Yalnız sinüzoitlerle sentezlenmiş bir müzik parçasının spektrogramı (ekrandan, 00:45:00): dikey eksen 0-1200 Hz, yatay eksen 0-9 s; her nota yatay bir çizgi olarak görünür.
- Telefon sinyali: zaman boyunca iki bileşen (yaklaşık 648 ve 672 Hz) görülür. Bu, $\cos(2\pi\,660\,t)$ ile $12$ Hz'lik bir sinüzoidin çarpımıdır; çarpım Euler bağıntılarıyla açılınca $660\pm12$ Hz'lik iki bileşen çıkar.
- Doğrusal frekans modülasyonu (chirp): frekansı zamanla artan, kuş sesine benzeyen işaret. Hoca bunun ayrıntısına girmeyeceklerini, yalnız frekansın zamanla değiştiği bir örnek olarak gösterdiğini söyledi.

### 4.2 Tını

İdeal sentezlenmiş bir sinüzoit bir çalgıyla ya da insan sesiyle çalındığında tek başına çıkmaz; araya başka bileşenler girer. Bu ek bileşenlerden doğan ayırt edici özelliğe **tını** (İngilizce *timbre*) denir. Aynı nota farklı çalgılarda ya da farklı müzik türlerinde farklı tınıyla duyulur.

## 5. Sürekli Zamanlı Fourier Serisi Formülleri

Fourier serisi katsayılarını bulmak, işareti bir periyot boyunca farklı sinüzoitlerle çarpıp integral almaktır. Hoca bunu bir tür konvolüsyon (benzerlik ölçümü) olarak yorumladı: çarpım sonucu büyük çıkan sinüzoitler işaretin içindeki frekans bileşenleridir.

> **Hocanın vurgusu:** Formüllerin ispatı sorulmayacak; sınavda formüller verilir. Önemli olan verilen bir işaret için hangi formülün nasıl kullanılacağını bilmektir.

### 5.1 Üstel (karmaşık) biçim

Tahtada yazılan formüller (ekrandan, 00:55:00):

$$x(t)=\sum_{k=-\infty}^{\infty}c_k\,e^{jk\omega_0t}$$

$$c_k=\frac{1}{T_0}\int_{T_0}x(t)\,e^{-jk\omega_0t}\,dt\qquad(k\neq0)$$

$$c_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$$

$c_0$ ayrı hesaplanır, çünkü ileride genel formülde $k=0$ alınınca belirsizlik oluşur. $c_0$ işaretin DC bileşenidir; bir periyotluk alanın periyoda oranıdır. İntegral kolay alınabiliyorsa soru kolaydır; integral zorsa sorunun içinden çıkmak zorlaşır.

İşaret gerçel değerliyse katsayılar eşlenik simetriklidir:

$$c_{-k}=c_k^{*}$$

### 5.2 Trigonometrik biçim

$$x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}\left(a_k\cos k\omega_0t+b_k\sin k\omega_0t\right)$$

$$a_0=\frac{2}{T_0}\int_{T_0}x(t)\,dt,\qquad a_k=\frac{2}{T_0}\int_{T_0}x(t)\cos k\omega_0t\,dt,\qquad b_k=\frac{2}{T_0}\int_{T_0}x(t)\sin k\omega_0t\,dt$$

Hoca tahtaya önce toplam yerine integral yazdı, sonra bunun bir toplam olduğunu düzeltti. Üstel biçimdeki toplam açılınca kosinüs ve sinüsler ortaya çıkar; iki gösterim matematiksel olarak aynıdır. $a_k$ işaretin içindeki kosinüsleri, $b_k$ sinüsleri arar.

Trigonometrik biçimde üç ayrı integral ($a_0$, $a_k$, $b_k$) gerekir. Üstel biçimde tek integral yeterli olduğundan genelde o kullanılır.

### 5.3 İki biçim arasındaki ilişki

$$c_k=\tfrac12(a_k-jb_k),\qquad c_{-k}=\tfrac12(a_k+jb_k)$$

$$a_k=2\,\mathrm{Re}\{c_k\},\qquad b_k=-2\,\mathrm{Im}\{c_k\},\qquad a_0=2c_0$$

Hoca bu ilişkilerin ispatının uzun olduğunu, sınavda verileceğini söyledi.

## 6. Kare Dalga Örneği: Trigonometrik Biçim

### 6.1 İşaret ve periyot

Ekrana alınan işaret (ekrandan, 01:00:00): $f(t)$, $0<t<1$ aralığında 1, $1<t<2$ aralığında 0 olan ve bu şekilde tekrar eden bir kare dalgadır (grafikte $-2$'den $3$'e kadar gösterilmiş).

- Önce periyodik olup olmadığına bakılır. İşaret $0$'dan $2$'ye kadar bir tam desen çizip tekrar eder: $T=2$.
- Frekans $f=\frac{1}{T}=0.5$ Hz, açısal frekans $\omega_0=2\pi f=\pi$ rad/s.
- Doğrulama: her $t$ için $f(t+2)=f(t)$ sağlanır (tahtada bir noktadan iki birim ilerideki noktaya ok çizildi).

### 6.2 $a_0$

$$a_0=\frac{2}{T}\int_0^Tf(t)\,dt=\frac22\int_0^11\,dt+\frac22\int_1^20\,dt=t\Big|_0^1=1$$

Aynı sonuç bir periyottaki alandan da okunur: $0$–$1$ arasındaki dikdörtgenin alanı 1'dir ve $\frac{2}{T}=1$ olduğundan $a_0=1$'dir.

> **Ders sonrası not:** Hoca $a_0=1$ değerini "işaretin DC bileşeni, genliği 1" diye yorumladı. Seri $\frac{a_0}{2}+\dots$ biçiminde yazıldığı için DC bileşen $\frac{a_0}{2}=\frac12$'dir; bu, kare dalganın bir periyottaki ortalamasıdır. Üstel biçimde bulunan $c_0=\frac12$ de bunu doğrular.

### 6.3 $a_n$

$$a_n=\frac{2}{T}\int_0^2f(t)\cos(n\pi t)\,dt=\int_0^1\cos(n\pi t)\,dt=\frac{\sin(n\pi t)}{n\pi}\Big|_0^1=\frac{\sin n\pi}{n\pi}$$

Hoca önce bu ifadeyi sıfırdan farklı gibi taşıdı, sonra hatayı fark etti: $n$ tam sayı olduğundan $\sin\pi=\sin2\pi=\dots=0$'dır, dolayısıyla

$$a_n=0$$

Yani işaretin kosinüslü bileşeni yoktur (ekrandan, 01:10:00).

### 6.4 $b_n$

$$b_n=\frac{2}{T}\int_0^2f(t)\sin(n\pi t)\,dt=\int_0^1\sin(n\pi t)\,dt=-\frac{\cos(n\pi t)}{n\pi}\Big|_0^1=\frac{-\cos n\pi+1}{n\pi}=\frac{1-\cos n\pi}{n\pi}$$

Hoca bu adımda işaretleri derste birkaç kez kontrol etti ve öğrencilere sordu; $t=1$ için $-\frac{\cos n\pi}{n\pi}$, $t=0$ için $-\frac{1}{n\pi}$ gelir, fark alınınca yukarıdaki sonuç çıkar.

$\cos n\pi$ tek $n$ için $-1$, çift $n$ için $+1$'dir; yani $\cos n\pi=(-1)^n$. Buna göre

$$b_n=\frac{1-(-1)^n}{n\pi}=\begin{cases}\dfrac{2}{n\pi}, & n\ \text{tek}\\[2mm] 0, & n\ \text{çift}\end{cases}$$

Tahtada ara satırda $\cos2\pi$ için "= 2" yazılmıştır (ekrandan, 01:10:00); doğrusu $\cos2\pi=1$'dir ve sonuçtaki $b_n$ formülü doğrudur.

İntegralin sınırları her zaman $0$'dan $T$'ye alınmak zorunda değildir. Bir öğrenci bunu sordu.

**Soru:** İntegralin sınırları her zaman sıfırdan $T$'ye mi alınır? **Cevap:** Hayır, herhangi bir tam periyot alınabilir: $1$'den $3$'e ya da $0.5$'ten $2.5$'e alınsa da aynı sonuç çıkar; yalnız işaretin hangi aralıkta hangi değeri aldığına göre integral parçalanır.

### 6.5 Seri

$a_n=0$ olduğundan yalnız sinüslü terimler ve DC terimi kalır (ekrandan, 01:25:00):

$$f(t)=\frac12+\sum_{n=1}^{\infty}\frac{1-(-1)^n}{n\pi}\sin(n\pi t)=\frac12+\frac{2}{\pi}\sin\pi t+\frac{2}{3\pi}\sin3\pi t+\frac{2}{5\pi}\sin5\pi t+\dots$$

Bu terimler sonsuza kadar toplanırsa kare dalga elde edilir.

Python ile sayısal integral kontrolü: $a_0\approx1$, $a_n\approx0$, $b_1\approx0.63662=\frac{2}{\pi}$, $b_2\approx0$, $b_3\approx0.21221=\frac{2}{3\pi}$, $b_5\approx0.12732=\frac{2}{5\pi}$.

### 6.6 MATLAB ile kısmi toplamlar

Aradan sonra hoca MATLAB'de bir $t$ vektörü tanımlayıp ($0.1$ adımlarla) önce $\frac12+\frac{2}{\pi}\sin\pi t$ terimini, sonra buna $\frac{2}{3\pi}\sin3\pi t$, $\frac{2}{5\pi}\sin5\pi t$ terimlerini ekleyerek $x_1, x_2, \dots, x_5$ kısmi toplamlarını farklı renklerde çizdirdi. Terim eklendikçe eğri kare dalgaya yaklaşır: $0$–$1$ aralığında 1'e, $1$–$2$ aralığında 0'a yaklaşır. Kodda bir yazım hatası (katsayı yanlışlığı) fark edilip düzeltildi.

<!-- BELİRSİZ: MATLAB kodunun kendisi karelerde görünmüyor (yaklaşık 01:22-01:24 arası); kod metni nota alınmadı, yalnız altyazıdaki anlatım aktarıldı. -->

Hoca ayrıca şu birim çember eşitliklerinin sık unutulduğunu hatırlattı (ekrandan, 01:25:00):

$$\sin(-a)=-\sin a,\qquad \cos(-a)=\cos a$$

## 7. Kare Dalga Örneği: Üstel Biçim

Aynı işaret üstel biçimle çözüldü. $T=2$, $f=0.5$ Hz, $\omega_0=\pi$.

### 7.1 $c_0$

$$c_0=\frac{1}{T}\int_0^Tf(t)\,dt=\frac12\int_0^11\,dt=\frac12$$

$a_0=2c_0=1$ ilişkisi trigonometrik çözümle tutarlıdır.

### 7.2 $c_n$

$$c_n=\frac{1}{T}\int_0^Tf(t)e^{-jn\omega_0t}\,dt=\frac12\int_0^1e^{-jn\pi t}\,dt=\frac12\cdot\frac{e^{-jn\pi t}}{-jn\pi}\Big|_0^1=\frac{e^{-jn\pi}-1}{-2jn\pi}$$

Paydadaki $j$'den kurtulmak için pay ve payda $j$ ile çarpılır ($j\cdot j=-1$):

$$c_n=\frac{j\left(e^{-jn\pi}-1\right)}{2n\pi}$$

Euler bağıntısından $e^{-jn\pi}=\cos n\pi-j\sin n\pi$'dir. $\sin n\pi=0$, $\cos n\pi=(-1)^n$ olduğu için $e^{-jn\pi}=(-1)^n$ olur:

$$c_n=\frac{j\left[(-1)^n-1\right]}{2n\pi}$$

- Tek $n$: $(-1)^n-1=-2$, dolayısıyla $c_n=\dfrac{-j}{n\pi}$.
- Çift $n$ ($n\neq0$): $(-1)^n-1=0$, dolayısıyla $c_n=0$.

Seri şöyle yazılır:

$$f(t)=\frac12-\sum_{n\ \text{tek}}\frac{j}{n\pi}e^{jn\pi t}\qquad(n=\pm1,\pm3,\dots)$$

### 7.3 Trigonometrik katsayılara dönüş

Tek $n$ için $c_n=-\frac{j}{n\pi}$'nin gerçel kısmı yoktur:

$$a_n=2\,\mathrm{Re}\{c_n\}=0$$

Sanal kısmı $-\frac{1}{n\pi}$'dir:

$$b_n=-2\,\mathrm{Im}\{c_n\}=-2\left(-\frac{1}{n\pi}\right)=\frac{2}{n\pi}$$

İki yöntem aynı sonucu verir. Python ile $c_1\approx-0.31831j=-\frac{j}{\pi}$, $c_3\approx-0.1061j$ doğrulandı.

Hoca, sınavda bundan daha zor integraller (sinüslü bir "kubbe" işaretle sinüsün çarpımı, ya da farklı sınırlarla tanımlanmış kare dalgalar) sorulabileceğini ama o kadar zorlaştırmayacağını söyledi. Çalışma için birkaç örnek çözmeyi, özellikle testere dişi gibi $x(t)=t$ biçimindeki periyodik işaretlerle denemeyi önerdi.

## 8. Ayrık Zamanlı Fourier Serisi

### 8.1 Periyodun bulunması

Ayrık işaretlerde analiz daha kolaydır, çünkü integral yerine toplam vardır; çoğu zaman yalnız sayıların çarpımı ve toplamı gerekir.

Tahtadaki örnek (ekrandan, 01:40:00 ve 01:45:00): $x[n]$, $n=0,1,2,3,4$ için 1, $n=5,\dots,9$ için 0 olan ve böyle tekrar eden bir dizidir.

**Soru:** Bu dizinin periyodu kaçtır? **Cevap:** 10. Beş değil; desen 1'lerin başladığı yerden bir sonraki 1'lerin başladığı yere kadar on örnek sürer: $N_0=10$.

### 8.2 Formüller

$$x[n]=\sum_{k=0}^{N_0-1}c_k\,e^{jk\Omega_0n},\qquad \Omega_0=\frac{2\pi}{N_0}$$

$$c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]\,e^{-jk\Omega_0n}$$

Sürekli durumdaki $\int_{T_0}\dots dt$ yerine bir periyot boyunca $\sum_{n=0}^{N_0-1}$ gelir.

### 8.3 Örneğin çözümü

$N_0=10$ olduğundan $\Omega_0=\frac{2\pi}{10}=\frac{\pi}{5}$. $n=5,\dots,9$ için $x[n]=0$ olduğu için toplam $n=0,\dots,4$ ile sınırlanır:

$$c_k=\frac{1}{10}\sum_{n=0}^{4}1\cdot e^{-jk\pi n/5}$$

$n=0$ için terim 1, $n=1$ için $e^{-jk\pi/5}$, $n=2$ için $e^{-j2k\pi/5}$ ve böyle devam eder. Bu bir geometrik seridir; toplam formülüyle

$$\sum_{n=0}^{4}e^{-jk\pi n/5}=\frac{1-e^{-jk\pi}}{1-e^{-jk\pi/5}}$$

bulunur. Pay ve paydada $e^{-jk\pi/2}$ ve $e^{-jk\pi/10}$ ortak paranteze alınıp Euler bağıntısı kullanılınca

$$c_k=\frac{1}{10}\,e^{-j2\pi k/5}\,\frac{\sin(k\pi/2)}{\sin(k\pi/10)}$$

elde edilir. $k=0$ için limit alınınca $c_0=\frac{1}{10}\cdot5=\frac12$ olur. $k$ yalnız $0$'dan $9$'a kadar anlamlıdır, çünkü sonra katsayılar kendini tekrar eder.

> **Ders sonrası not:** Altyazıda sonucun başındaki çarpan "$2\pi$ bölü 5" diye geçiyor; bu büyük olasılıkla $e^{-j2\pi k/5}$ faz teriminin okunuşudur ve $\frac{1}{10}$ çarpanı da sonuçta bulunur. Yukarıdaki formül Python ile doğrudan toplamla karşılaştırıldı: örneğin $c_1\approx0.1-0.3078j$, $c_3\approx0.1-0.0727j$, $c_5=0.1$, çift $k\neq0$ için $c_k=0$.

Hoca geometrik seri toplam formüllerini o an hatırlamadığını, bir formül listesini ders sayfasına yükleyeceğini söyledi. Sınavda sorulacak bir ayrık seri sorusunda deseni bulmanın kolay olacağını, ama genelde bu konuda ayrık seri sorulmayacağını, çünkü işlemin uzadığını belirtti.

### 8.4 Önerilen alıştırma

$$x[n]=\sum_{k=-\infty}^{\infty}\delta[n-4k]$$

$\delta[n]$ yalnız $n=0$'da 1 olduğundan bu dizi her 4 örnekte bir 1 değerini alır (…, $-4$, $0$, $4$, $8$, …). Periyot $N_0=4$'tür. Formül uygulanınca bütün $k$ değerleri için $c_k=\frac14$ çıkar (Python ile doğrulandı).

## 9. Fourier Sentezi ve Gibbs Olayı

Bu bölüm periyodik analizdir: işaretin $-\infty$'dan $+\infty$'a tamamı değil, yalnız bir periyodu incelenir.

Slayttaki örnekte (ekrandan, 01:50:00) periyodu $0.04$ s olan bir kare dalga kullanıldı:

$$\omega_0=\frac{2\pi}{0.04}=2\pi(25)$$

$$a_k=\begin{cases}\dfrac{-j}{\pi k}, & k=\pm1,\pm3,\dots\\[2mm] 0, & k=\pm2,\pm4,\dots\\[2mm] \dfrac12, & k=0\end{cases}$$

Temel frekans 25 Hz'dir (25, 75, 125, … frekanslarının OBEB'i). Spektrumda $0$'da $\frac12$, $\pm25$ Hz'de $\pm\frac{j}{\pi}$ büyüklüğünde, $\pm75$ Hz'de $\frac{1}{3\pi}$, $\pm125$ Hz'de $\frac{1}{5\pi}$ büyüklüğünde çizgiler vardır. Katsayılar önceki örnekle aynı yapıdadır; yalnız periyot farklı olduğu için frekans ekseni değişir.

Sentez, bulunan katsayılarla harmonikleri sırayla toplamaktır. Örneğin ilk terimler:

$$x(t)\approx\frac12+\frac{2}{\pi}\cos\!\left(2\pi\,25\,t-\frac{\pi}{2}\right)+\frac{2}{3\pi}\cos\!\left(2\pi\,75\,t-\frac{\pi}{2}\right)+\dots$$

Genlik $2|a_k|$, faz $\angle a_k=-\frac{\pi}{2}$'dir. Terim eklendikçe toplam kare dalgaya yaklaşır.

Terim sayısı sonsuza götürülse de süreksizlik noktalarının yanında "kulak" biçiminde taşmalar kalır. Buna **Gibbs olayı** denir. Hoca bunu bir doyum noktası gibi yorumladı: belli bir terim sayısından sonra yeni terim eklemek kenarlardaki taşmayı azaltmaz. Uygulamada taşma belli bir oranı geçmeyecek kadar terim eklenir. Hoca bu konunun ders kapsamında ayrıntılı olarak gerekmediğini söyledi.

Slaytlarda ayrıca $\sin^3(3\pi t)$ işaretinin serisi gösterildi. Bu işaret açılınca $\frac34\sin3\pi t-\frac14\sin9\pi t$ olur; frekanslar $1.5$ ve $4.5$ Hz'dir, temel frekans OBEB olarak $1.5$ Hz bulunur (özdeşlik Python ile doğrulandı).

## 10. Fourier Dönüşümü

### 10.1 Tanım

Fourier dönüşümünün iki amacı vardır: periyodik olmayan bir işaretin temel bileşenlerini bulmak ve frekans bileşenlerinden özellik çıkarmak (makine öğrenmesi gibi uygulamalar için) (ekrandan, 01:55:00).

Fourier serisi periyodik işaretlerde çalışır. Periyodik olmayan bir işaret, periyodu sonsuz olan, yani $-\infty$'dan $+\infty$'a kendini bir kez tekrar eden bir işaret gibi düşünülür. Serinin bu limiti Fourier dönüşümünü verir; ters dönüşümün de var olduğu kanıtlanmıştır:

$$X(j\omega)=\int_{-\infty}^{\infty}x(t)\,e^{-j\omega t}\,dt\qquad(\text{analiz})$$

$$x(t)=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(j\omega)\,e^{j\omega t}\,d\omega\qquad(\text{sentez, ters dönüşüm})$$

$\frac{1}{2\pi}$ bir ölçekleme katsayısıdır; ters dönüşümde üsteki işaret $+j$ olur.

### 10.2 Örnek 1: $e^{-at}u(t)$

$u(t)$, $t\ge0$ için 1, $t<0$ için 0 olan birim basamak işaretidir (tahtaya yazıldı). Slayttaki örnek (ekrandan, 02:00:00):

$$x(t)=e^{-at}u(t),\qquad a>0$$

$t<0$ bölgesinde $u(t)=0$ olduğu için integral $0$'dan başlar:

$$X(j\omega)=\int_0^{\infty}e^{-at}e^{-j\omega t}\,dt=\int_0^{\infty}e^{-(a+j\omega)t}\,dt=\frac{-e^{-(a+j\omega)t}}{a+j\omega}\Big|_0^{\infty}=\frac{1}{a+j\omega}$$

Python ile $a=2$, $\omega=1.5$ için sayısal integral $0.32-0.24j$ verdi; $\frac{1}{2+1.5j}=0.32-0.24j$.

### 10.3 Frekans cevabı

Hoca burada öğrencilere birim dürtü cevabının ne işe yaradığını sordu ve önceki derslerde kullandığı benzetmeyi hatırlattı: birim dürtü cevabı sistemin "röntgenini çekmek" gibidir. İçini bilmediğimiz bir sisteme birim dürtü uygulanınca çıkan $h[n]$ (ya da $h(t)$) sistemin modelidir; herhangi bir girişin çıkışı bu cevapla konvolüsyondan bulunur.

Frekans düzleminde bunun karşılığı **frekans cevabıdır**: $h(t)$'nin Fourier dönüşümü $H(j\omega)$. Örneğin $h(t)=e^{-at}u(t)$ ise $H(j\omega)=\frac{1}{a+j\omega}$'dır. Genliği ve fazı:

$$|H(j\omega)|=\frac{1}{\sqrt{a^2+\omega^2}},\qquad \angle H(j\omega)=-\arctan\frac{\omega}{a}$$

Bunlar $\omega$'ya ve $a$'ya bağlıdır. Gerçel $h(t)$ için $H(-j\omega)=H^{*}(j\omega)$'dır.

### 10.4 Örnek 2: dikdörtgen darbe

$|t|<T/2$ için 1, diğer yerlerde 0 olan dikdörtgen darbenin dönüşümü alınırken integral yalnız darbe aralığında alınır; $e^{-j\omega t}=\cos\omega t-j\sin\omega t$ ile işaretin içindeki kosinüs ve sinüsler aranmış olur. Hoca integral çözülünce sonucun sinüslü bir ifade ($\sin$ bölü $\omega$ biçiminde) çıktığını söyledi. Slaytta işaret ve dönüşümü çizildi; dönüşüm sürekli bir frekans fonksiyonudur.

<!-- BELİRSİZ: Bu örneğin slaydı karelerde yok; altyazıda sonucun tam biçimi okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Genişliği $T$ olan birim dikdörtgen darbenin standart dönüşümü $X(j\omega)=\int_{-T/2}^{T/2}e^{-j\omega t}dt=\frac{2\sin(\omega T/2)}{\omega}$'dır. Bu, bir sonraki örnekteki ideal alçak geçiren filtrenin zaman-frekans ikilisidir.

### 10.5 Örnek 3: ideal alçak geçiren filtre

Slayttaki örnek (ekrandan, 02:05:00):

$$X(j\omega)=\begin{cases}1, & |\omega|<\omega_b\\ 0, & |\omega|>\omega_b\end{cases}$$

Ters dönüşüm yalnız $-\omega_b$ ile $\omega_b$ arasında alınır:

$$x(t)=\frac{1}{2\pi}\int_{-\omega_b}^{\omega_b}e^{j\omega t}\,d\omega=\frac{1}{2\pi}\cdot\frac{e^{j\omega_bt}-e^{-j\omega_bt}}{jt}$$

$e^{j\omega_bt}=\cos\omega_bt+j\sin\omega_bt$ ve $e^{-j\omega_bt}=\cos\omega_bt-j\sin\omega_bt$ yazılınca kosinüsler gider, $2j\sin\omega_bt$ kalır:

$$x(t)=\frac{\sin\omega_bt}{\pi t}$$

Bu güzel bir örnektir: frekans düzleminde $-\omega_b$ ile $\omega_b$ arasındaki frekansları geçiren, diğerlerini sıfırlayan bir filtre, zaman düzleminde $\frac{\sin\omega_bt}{\pi t}$ ile konvolüsyona karşılık gelir. Hoca bir önceki derste bahsettiği periyodik gürültüyü yok etmek için böyle bir filtrenin frekans düzleminde çarpılarak kullanıldığını hatırlattı.

### 10.6 Dürtü, karmaşık üstel ve kosinüs

- $x(t)=A\delta(t)$ ise $X(j\omega)=A$: bütün frekanslarda sabit genlik. Dürtünün integrali tek bir değer verir, $t$'ye bağlı bir şey kalmaz.
- Frekansta $\omega_0$'da bir dürtünün ters dönüşümü (ölçek çarpanıyla) $e^{j\omega_0t}$'dir. Bu da Euler bağıntısıyla $\cos\omega_0t+j\sin\omega_0t$ olarak yazılabilir.
- $x(t)=\cos\omega_0t$ ise dönüşüm integrali $\int\cos(\omega_0t)e^{-j\omega t}dt$ olur. Kosinüsün dönüşümü kendi frekansında ($\pm\omega_0$) tepe verir.

Hoca bu tepe verme fikrinin bir uygulamasını gösterdi: bir resimden bir bölge (göz bölgesi) kesilip Fourier tabanlı olarak resmin tamamında arandığında, sonuç görüntüsünde aranan bölgeye en çok benzeyen yerde parlak (beyaz) tepe noktaları oluşuyor; bu noktalar aranan bölgenin yerini gösteriyor. Kosinüslerle konvolüsyon yapıldığı için aynı frekansa ulaşıldığında en yüksek değer çıkar.

> **Hocanın vurgusu:** Bilgisayar mühendisleri olarak Fourier'i en çok bu tür benzerlik arama ve özellik çıkarma işlerinde kullanırız.

### 10.7 Dönüşüm tabloları ve periyodik işaretler

Fourier dönüşüm tablolarında $e^{-at}u(t)$, sinüs, kosinüs, Dirac delta, basamak fonksiyonu gibi temel işaretlerin dönüşümleri bulunur. Diğer işaretlerin dönüşümleri bunlardan türetilir. Slaytlarda periyodik bir işaretin Fourier dönüşümünün Fourier serisi katsayıları cinsinden yazıldığı (ekrandan, 02:10:00) ve kare dalganın Fourier dönüşümüyle bulunduğu örnekler de vardı; hoca bunların ayrıntısına girmedi.

## 11. Fourier Dönüşümünün Özellikleri

### 11.1 Doğrusallık, öteleme, ölçekleme

- **Doğrusallık:** Bir fonksiyon parçalara ayrılırsa dönüşümleri de toplamsal olarak birleşir.
- **Zamanda öteleme:** Zamanda $t_d$ kadar gecikme frekansta $e^{-j\omega t_d}$ çarpanı getirir; bu bir faz farkıdır:

$$x(t-t_d)\;\longleftrightarrow\;e^{-j\omega t_d}X(j\omega)$$

- **Ölçekleme:** $x(at)$'nin dönüşümünde $at=\lambda$ değişken dönüşümü yapılır; $t=\lambda/a$, $dt=d\lambda/a$ gelir:

$$x(at)\;\longleftrightarrow\;\frac{1}{|a|}X\!\left(\frac{j\omega}{a}\right)$$

Zamanda sıkıştırma (daraltma) frekansta genişlemeye yol açar; slaytta bir işaret ve sıkıştırılmış hâlinin spektrumları karşılaştırıldı.

### 11.2 Konvolüsyon ve çarpma

$$x(t)*h(t)\;\longleftrightarrow\;X(j\omega)H(j\omega)$$

$$x(t)\,p(t)\;\longleftrightarrow\;\frac{1}{2\pi}X(j\omega)*P(j\omega)$$

> **Hocanın vurgusu:** Zamandaki konvolüsyonun frekansta çarpma olması çok önemlidir ve en çok kullanılan özelliktir.

Örnek: $\frac{\sin100\pi t}{\pi t}$ ile $\frac{\sin200\pi t}{\pi t}$'nin konvolüsyonu. Zamanda yapılırsa işaretlerden biri ters çevrilir, kaydırılır, örtüşme bölgelerine göre integral sınırları belirlenir; uzun bir iştir. Frekansta ise ilk işaretin dönüşümü $|\omega|<100\pi$ aralığında 1, ikincisininki $|\omega|<200\pi$ aralığında 1 olan dikdörtgenlerdir. Çarpımları dar olan dikdörtgeni verir, ters dönüşüm de

$$\frac{\sin100\pi t}{\pi t}*\frac{\sin200\pi t}{\pi t}=\frac{\sin100\pi t}{\pi t}$$

sonucunu verir. Hoca bunu sezgisel olarak da açıkladı: 100'lük işaret 200'lük işaretin içinde arandığında en çok kendisine benzeyen kısım bulunur.

Doğrusal ve zamanla değişmez (LTI) bir sisteme kosinüs giriş verildiğinde çıkış yine aynı frekansta bir kosinüstür; yalnız genliği frekans cevabının genliğiyle çarpılır ve faz farkı eklenir.

Alçak geçiren filtre örneğinde (ekrandan, 02:25:00) bir kare dalganın spektrumu, belli bir kesim frekansının altındaki bileşenleri geçiren ideal filtreyle çarpıldı. Yüksek frekanslı bileşenler atılınca zaman düzleminde kare dalganın yalnız ilk birkaç harmoniğinden oluşan yumuşatılmış bir hâli kalır; bu, önceki bölümdeki sentezin tersten okunmasıdır.

Ters yön de geçerlidir: zamanda çarpma frekansta konvolüsyondur. Örneğin $50\pi t$'lik ve $150\pi t$'lik iki sinüzoit çarpılacaksa frekansta konvolüsyon yapılabilir.

### 11.3 Modülasyon (frekansta öteleme)

Bir işaret $e^{j\omega_0t}$ ile çarpılırsa dönüşümü yeniden hesaplamaya gerek yoktur; spektrum $\omega_0$ kadar kaydırılır:

$$e^{j\omega_0t}x(t)\;\longleftrightarrow\;X\big(j(\omega-\omega_0)\big)$$

Sinüs ya da kosinüsle çarpmada spektrum $\pm\omega_0$'a kayar.

### 11.4 Türev

$$\frac{dx(t)}{dt}\;\longleftrightarrow\;j\omega X(j\omega)$$

Bir işaretin dönüşümü biliniyorsa türevinin dönüşümü için yeniden integral almaya gerek yoktur; dönüşüm $j\omega$ ile çarpılır. Hoca bunu $x(t)=t$ örneğiyle anlattı: $t$'nin dönüşümünü bulmak kısmi integrasyon ($u$, $dv$ seçimi) gerektiren uzun bir işlemdir; bunun türevinin dönüşümü istenirse ikinci kez integral almak yerine bu özellik kullanılır.

### 11.5 Laplace dönüşümüyle bağlantı

Aynı tanım $j\omega$ yerine $s$ yazılarak Laplace dönüşümüne dönüşür:

$$X(s)=\int x(t)\,e^{-st}\,dt$$

Özellikler aynen geçerlidir. Laplace dönüşümünde de diferansiyel denklem önce dönüştürülür, cebirsel olarak çözülür, sonra ters dönüşümle sistem davranışı bulunur. Hoca bu nedenle buradaki temelin şimdiden iyi öğrenilmesi gerektiğini söyledi.

Hoca ayrıca, dönüşüm tablosundaki bir çiftten ve bir özellikten yola çıkarak (örneğin $e^{-t}u(t)$ ile $\cos t$'nin çarpımının dönüşümünü uzun integrali almadan modülasyon özelliğiyle bulmak) çözüm yapılabileceğini gösterdi.

## 12. Ayrık Zamanlı Fourier Dönüşümü

Ayrık işaretlerde integral yerine toplam gelir:

$$X(e^{j\omega})=\sum_{n=-\infty}^{\infty}x[n]\,e^{-j\omega n}$$

Laplace'taki ilişkiye benzer biçimde $e^{j\omega}$ yerine $z$ yazılınca z dönüşümü elde edilir (ekrandan, 02:40:00):

$$X(z)=\sum_{n=-\infty}^{\infty}x[n]\,z^{-n}$$

Bu dönüşüm özellikle sayısal işaret işleme dersinde çok kullanılır. Konvolüsyon, zamanda öteleme, frekansta türev gibi özelliklerin hepsi ayrık zamanda da aynen geçerlidir; hepsinin mantığı konvolüsyondan türer.

### 12.1 Örnek: $u[n]-u[n-N]$

Tahtadaki örnek (ekrandan, 02:40:00):

$$x[n]=u[n]-u[n-N]$$

$u[n]$ $n\ge0$ için 1'lerden oluşur; $u[n-N]$ $n\ge N$ için 1'dir. Farkları $n=0,\dots,N-1$ için 1, diğer yerlerde 0 olan sonlu bir dizidir.

$$X(e^{j\omega})=\sum_{n=0}^{N-1}e^{-j\omega n}=1+e^{-j\omega}+e^{-j2\omega}+\dots+e^{-j(N-1)\omega}$$

Hoca bu toplamı z dönüşümü üzerinden geometrik seri formülüyle buldu ($\sum_{n=0}^{N-1}z^{-n}$), sonra $z=e^{j\omega}$ yazdı:

$$X(e^{j\omega})=\frac{1-e^{-j\omega N}}{1-e^{-j\omega}}=e^{-j\omega(N-1)/2}\,\frac{\sin(\omega N/2)}{\sin(\omega/2)}$$

Son adım pay ve paydada yarım açılı üstellerin ortak paranteze alınmasıyla gelir. Python ile $N=5$, $\omega=0.7$ için iki ifade aynı değeri verdi.

Hoca tahtada üstün işaretini ($z^{-n}$ ile $z^{n}$) bir an karıştırdı ve düzeltti; doğru tanım $z^{-n}$'dir.

## 13. Frekans Cevabıyla Fark ve Diferansiyel Denklem Çözümü

### 13.1 Ayrık zamanlı LTI sistem

Soru (ekrandan, 02:50:00): nedensel bir ayrık zamanlı LTI sistem

$$y[n]-\frac34y[n-1]+\frac18y[n-2]=x[n]$$

ile tanımlanıyor. Sistemin frekans cevabı $H(e^{j\omega})$ ve dürtü cevabı $h[n]$ bulunacak.

Fark denklemi (özyinelemeli bağıntı) zamanda da çözülebilir, ama Fourier dönüşümünün özellikleri işi kolaylaştırır. Zamanda bir birim öteleme $e^{-j\omega}$ çarpanı getirir:

$$Y(e^{j\omega})-\frac34e^{-j\omega}Y(e^{j\omega})+\frac18e^{-j2\omega}Y(e^{j\omega})=X(e^{j\omega})$$

$Y$ ortak paranteze alınır:

$$Y(e^{j\omega})\left(1-\frac34e^{-j\omega}+\frac18e^{-j2\omega}\right)=X(e^{j\omega})$$

Çıkışın girişe oranı sistemin davranışını, yani frekans cevabını verir:

$$H(e^{j\omega})=\frac{Y(e^{j\omega})}{X(e^{j\omega})}=\frac{1}{1-\frac34e^{-j\omega}+\frac18e^{-j2\omega}}$$

Ters Fourier dönüşümü alınırsa $h[n]$ bulunur. Bunun için ifade basit kesirlere ayrılır. Payda $\left(1-\frac12e^{-j\omega}\right)\left(1-\frac14e^{-j\omega}\right)$ olarak çarpanlarına ayrılır (ara adım eklendi):

$$H(e^{j\omega})=\frac{2}{1-\frac12e^{-j\omega}}-\frac{1}{1-\frac14e^{-j\omega}}$$

Hoca ikinci terimin paydasını önce $e^{-j2\omega}$ ile yazdı, sonra bunun $e^{-j\omega}$ olması gerektiğini düzeltti (ekrandan, 02:55:00).

Dönüşüm tablosunda

$$a^nu[n]\;\longleftrightarrow\;\frac{1}{1-ae^{-j\omega}}\qquad(|a|<1)$$

çifti bulunur. Buna göre ilk terim $2\left(\frac12\right)^nu[n]$, ikinci terim $\left(\frac14\right)^nu[n]$'dir:

$$h[n]=\left[2\left(\frac12\right)^n-\left(\frac14\right)^n\right]u[n]$$

$u[n]$ çarpanı dizinin $n\ge0$ için tanımlı olduğunu gösterir. Fark denklemi zamanda çözülmeden, yalnız dönüşüm özellikleri ve tablo kullanılarak dürtü cevabı bulunmuş olur.

Python ile kontrol: $H$ iki biçimde aynı değeri verdi; ayrıca fark denklemi $x[n]=\delta[n]$ ile özyinelemeli çalıştırıldığında ilk 8 örnek $h[n]$ formülüyle aynı çıktı.

### 13.2 Sürekli zamanlı LTI sistem

Soru (ekrandan, 03:00:00 ve 03:05:00): doğrusal zamanla değişmez sistem

$$\frac{dy(t)}{dt}+2y(t)=x(t)$$

ile tanımlanıyor. Girişe $x(t)=e^{-t}u(t)$ uygulanırsa çıkış nedir? Hoca bunu bir RLC devresine belli bir gerilim kaynağı bağlandığında akım ya da gerilimin zamanla nasıl değişeceği sorusuna benzetti. Bu denklem diferansiyel denklem yöntemleriyle, Laplace dönüşümüyle ya da Fourier dönüşümüyle çözülebilir.

Türev özelliğiyle her iki tarafın dönüşümü alınır:

$$j\omega Y(\omega)+2Y(\omega)=X(\omega)\;\Rightarrow\;Y(\omega)(2+j\omega)=X(\omega)$$

$$H(\omega)=\frac{Y(\omega)}{X(\omega)}=\frac{1}{2+j\omega}$$

Normalde çıkış $y(t)=h(t)*x(t)$ konvolüsyonuyla bulunur; bunun için önce $h(t)$ ters dönüşümle bulunmalı, sonra konvolüsyon integrali alınmalıdır. Bunun yerine girişin dönüşümü tablodan alınır:

$$x(t)=e^{-t}u(t)\;\longleftrightarrow\;X(\omega)=\frac{1}{1+j\omega}$$

ve frekansta çarpılır:

$$Y(\omega)=X(\omega)H(\omega)=\frac{1}{(1+j\omega)(2+j\omega)}=\frac{1}{1+j\omega}-\frac{1}{2+j\omega}$$

Her terimin ters dönüşümü alınır:

$$y(t)=\left(e^{-t}-e^{-2t}\right)u(t)$$

Python ile kontrol: basit kesir ayrımı sayısal olarak doğrulandı; $y(t)=e^{-t}-e^{-2t}$ için $y'+2y=e^{-t}$ sağlanıyor.

Hoca, aynı sisteme $x_2(t)=e^{t}u(t)$ uygulandığında çıkışın aynı yolla (girişin Fourier dönüşümünü $H(\omega)$ ile çarparak) bulunmasını alıştırma olarak bıraktı.

> **Ek bilgi (derste anlatılmadı):** $e^{t}u(t)$ zamanla büyüyen bir işarettir ve mutlak integrallenebilir değildir; bu yüzden olağan anlamda Fourier dönüşümü yoktur. Bu tür girişler için genellikle Laplace dönüşümü kullanılır. Alıştırma büyük olasılıkla $e^{-2t}u(t)$ gibi sönümlü bir girişle düşünülmelidir.

Bu yöntemin gücü, ikinci ya da üçüncü dereceden diferansiyel denklemlerde daha açık görülür: zamanda çok uğraştıracak bir çözüm frekans düzleminde cebirsel işlemlere iner.

## 14. Fourier'in Bilgisayar Mühendisliğindeki Yeri

Dersin sonunda hoca, frekans düzlemine geçmenin bilgisayar mühendisi açısından en büyük faydasının özellik çıkarma (feature extraction), yani bir işaretin ayırt edici özelliklerini bulmak olduğunu söyledi. Ses, görüntü ve diğer verilerde spektrogramla zaman-frekans analizi yapılır.

Kod yazarken Python ya da MATLAB'de FFT ve ters FFT hazır fonksiyonlarla kullanılır; çoğu zaman yalnız bir kaydırma (shift) işlemi eklenir ve iş birkaç satırla biter. Önemli olan bu kodun arkasındaki matematiği anlamaktır. Hoca, konunun matematiğini daha derin öğrenmek isteyenler için Fourier serisi ve dönüşümünü ispatlarıyla anlatan Türkçe bir video serisi paylaştığını söyledi. Ayrıca ders kitaplarının konuları farklı sırayla anlattığını (bazılarının önce Laplace ve z dönüşümünü verip Fourier'i onlara bağladığını) ve bu yüzden dersin kendi sırasının izlenmesinin daha verimli olduğunu belirtti.

## Örnek Sorular

**1. Spektrumdan işaret yazma** (derste sözlü, 00:31:31)

İki ya da üç bileşeni karmaşık üstellerle verilmiş bir işaret, örneğin $\frac{A}{2}e^{j\varphi}e^{j\omega_1t}+\frac{A}{2}e^{-j\varphi}e^{-j\omega_1t}+\dots$, kosinüslü biçimde yazılıp spektrumu çizilecek. Hoca bu tür bir sorunun sınavda büyük olasılıkla geleceğini söyledi.

> **Çözüm (derste verilmedi):** Her eşlenik çift Euler bağıntısıyla birleştirilir: $\frac{A}{2}e^{j\varphi}e^{j\omega t}+\frac{A}{2}e^{-j\varphi}e^{-j\omega t}=A\cos(\omega t+\varphi)$. Spektrumda $\pm\omega$'da yüksekliği $\frac{A}{2}$, açısı $\pm\varphi$ olan çizgiler çizilir. Örneğin $A\sin7t$ için $+7$'de $\frac{A}{2}e^{-j\pi/2}$, $-7$'de $\frac{A}{2}e^{j\pi/2}$ vardır.

**2. Temel frekans** (derste sözlü, 00:33:37)

Frekansları $200, 400, 500, 1600, 1700$ Hz olan bileşenlerden oluşan işaretin temel frekansı nedir?

Çözüm: Temel frekans bütün frekansların OBEB'idir: $f_0=100$ Hz. 100 Hz ve 300 Hz gibi katlar spektrumda görünmez, çünkü genlikleri sıfırdır. Aynı yolla $100$ ve $250$ Hz için $f_0=50$ Hz, $648$ ve $672$ Hz için $f_0=24$ Hz bulunur.

**3. Kare dalganın Fourier serisi** (ekrandan, 01:00:00)

$0<t<1$ için $f(t)=1$, $1<t<2$ için $f(t)=0$ olan, periyodu 2 olan kare dalganın trigonometrik ve üstel Fourier serisini bulun.

Çözüm (derste verildi): $T=2$, $\omega_0=\pi$. $a_0=1$, $a_n=\frac{\sin n\pi}{n\pi}=0$, $b_n=\frac{1-(-1)^n}{n\pi}$ (tek $n$ için $\frac{2}{n\pi}$, çift $n$ için 0).

$$f(t)=\frac12+\frac{2}{\pi}\sin\pi t+\frac{2}{3\pi}\sin3\pi t+\frac{2}{5\pi}\sin5\pi t+\dots$$

Üstel biçimde $c_0=\frac12$, tek $n$ için $c_n=\frac{-j}{n\pi}$, çift $n$ için 0; $a_n=2\,\mathrm{Re}\{c_n\}=0$, $b_n=-2\,\mathrm{Im}\{c_n\}=\frac{2}{n\pi}$.

**4. Ayrık periyodik dizinin periyodu ve katsayıları** (ekrandan, 01:45:00)

Bir periyotta $n=0,\dots,4$ için 1, $n=5,\dots,9$ için 0 olan periyodik $x[n]$ dizisinin periyodu nedir? Ayrık Fourier serisi katsayılarını bulun.

Çözüm (derste verildi): $N_0=10$, $\Omega_0=\frac{\pi}{5}$.

$$c_k=\frac{1}{10}\sum_{n=0}^{4}e^{-jk\pi n/5}=\frac{1}{10}e^{-j2\pi k/5}\frac{\sin(k\pi/2)}{\sin(k\pi/10)},\qquad c_0=\frac12$$

**5. Dürtü dizisinin ayrık Fourier serisi** (derste sözlü, 01:47:34)

$x[n]=\sum_{k=-\infty}^{\infty}\delta[n-4k]$ dizisinin periyodunu ve ayrık Fourier serisi katsayılarını bulun. Hoca çözmeyi önerdi ve sonucu söyledi.

> **Çözüm (derste verilmedi):** Dizi her 4 örnekte bir 1'dir, $N_0=4$. Bir periyotta yalnız $x[0]=1$ olduğundan $c_k=\frac14\sum_{n=0}^{3}x[n]e^{-jk\pi n/2}=\frac14$, bütün $k$ için. (Python ile doğrulandı.)

**6. Ayrık LTI sistemin frekans ve dürtü cevabı** (ekrandan, 02:50:00)

$y[n]-\frac34y[n-1]+\frac18y[n-2]=x[n]$ ile tanımlı nedensel sistemin frekans cevabını ve dürtü cevabını bulun.

Çözüm (derste verildi):

$$H(e^{j\omega})=\frac{1}{1-\frac34e^{-j\omega}+\frac18e^{-j2\omega}}=\frac{2}{1-\frac12e^{-j\omega}}-\frac{1}{1-\frac14e^{-j\omega}}$$

$$h[n]=\left[2\left(\frac12\right)^n-\left(\frac14\right)^n\right]u[n]$$

**7. Sürekli LTI sistemin cevabı** (ekrandan, 03:00:00)

$\frac{dy}{dt}+2y(t)=x(t)$ sistemine $x(t)=e^{-t}u(t)$ uygulanıyor. Çıkışı bulun.

Çözüm (derste verildi): $H(\omega)=\frac{1}{2+j\omega}$, $X(\omega)=\frac{1}{1+j\omega}$,

$$Y(\omega)=\frac{1}{(1+j\omega)(2+j\omega)}=\frac{1}{1+j\omega}-\frac{1}{2+j\omega}\;\Rightarrow\;y(t)=\left(e^{-t}-e^{-2t}\right)u(t)$$

## Dersin Toparlaması

Bu derste frekans düzlemi analizinin dört aracı (CTFS, DFS/DFT, FT, DTFT) bir arada ele alındı. Periyodik işaretler için Fourier serisi katsayılarının üstel ve trigonometrik biçimleri, aralarındaki ilişki ve temel frekansın OBEB olarak bulunması anlatıldı; bir kare dalganın serisi iki yolla çözülüp MATLAB'de kısmi toplamlarla kare dalgaya yaklaşma gösterildi. Ayrık periyodik dizilerde integral yerine toplam kullanılarak katsayılar bulundu. Periyodik olmayan işaretler için Fourier dönüşümü tanımlandı; $e^{-at}u(t)$, ideal alçak geçiren filtre ve dürtü gibi temel çiftler ile doğrusallık, öteleme, ölçekleme, konvolüsyon, modülasyon ve türev özellikleri işlendi. Spektrogram ve tını gibi zaman-frekans kavramları örneklerle tanıtıldı.

Dersin son bölümünde bu özelliklerin asıl gücü gösterildi: bir fark denklemi ve bir diferansiyel denklem, Fourier dönüşümüyle cebirsel denkleme çevrildi, frekans cevabı bulundu, basit kesirlere ayrılıp tablodan ters dönüşüm alınarak dürtü cevabı ve çıkış elde edildi. Hoca, aynı tekniklerin $j\omega$ yerine $s$ yazılarak Laplace dönüşümünde, $e^{j\omega}$ yerine $z$ yazılarak z dönüşümünde kullanılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
