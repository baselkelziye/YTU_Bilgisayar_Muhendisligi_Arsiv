# Ders 11 Genişletilmiş Notu: Sürekli ve Ayrık Zamanlı Fourier Analizi: Seriler, DTFT ve DFT

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kaynağı ve Fourier analizinin yol haritası
- 2. Sürekli zamanda Fourier serileri (tekrar)
- 3. Sürekli zamanlı Fourier dönüşümü (CTFT)
- 4. Sürekli zaman çözümlü problemleri
- 5. Sayısal frekans ve örneklemenin frekansa etkisi
- 6. Ayrık zamanlı Fourier serisi (DTFS)
- 7. Ayrık zamanlı Fourier dönüşümü (DTFT)
- 8. Ayrık Fourier dönüşümü (DFT)
- 9. Ayrık zaman çözümlü problemleri ve MATLAB ile çizim
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kaynağı ve Fourier analizinin yol haritası

Bu ders bir önceki haftanın Fourier konusunun tekrarıyla başladı, ardından ayrık zamana geçildi. Kaynak olarak Schaum serisinin Signals and Systems kitabı (Hwei P. Hsu) ekranda açıktı: sürekli zaman kısmı kitabın 5. bölümü "Fourier Analysis of Time Signals and Systems", ayrık zaman kısmı 6. bölümü "Fourier Analysis of Discrete-Time Signals and Systems" (ekrandan, 00:15:00 ve 01:45:00). Altyazıda kitap "Xiaomi serisi" diye bozuk yazılmış; doğrusu Schaum'dur. Hoca bu kitabın Fourier anlatımını incelediği kitaplar arasında en iyisi olarak niteledi; özellikle çözümlü problem kısımlarının çok yararlı olduğunu söyledi.

Kitap Laplace ve z dönüşümlerini Fourier analizinden önce anlatıyor; bu yüzden bazı bölümlerde $s$ ve $z$ düzlemi analizine benzer ufak kısımlar var. Derste farklı bir yol seçildi: önce işaretlerin frekans analizi iyice anlaşılacak, Laplace ve z dönüşümleri sonra gelecek. Bu nedenle kitaptaki Laplace kısımları geçildi.

Fourier analizinin dört biçimi tahtada şöyle bağlandı (ekrandan, 01:25:00):

```text
            periyodik            periyodik olmayan
sürekli     CTFS  ----------->   CTFT
ayrık       DTFS  ----------->   DTFT  ----> DFT
```

Fourier analizi önce periyodik işaretler için kurulur (seriler). Ardından periyot sonsuza götürülerek periyodik olmayan, tek bir işaretin frekans içeriğini veren dönüşümler elde edilir. Ayrık zamanda bunun bir adım ötesi DFT'dir; neden gerektiği bölüm 8'de anlatıldı.

## 2. Sürekli zamanda Fourier serileri (tekrar)

### 2.1 Periyodik işaret ve temel frekans

Sürekli zamanlı bir $x(t)$ işareti, her $t$ için $x(t+T)=x(t)$ sağlayan sıfırdan farklı pozitif bir $T$ varsa periyodiktir. Bu koşulu sağlayan en küçük pozitif değer temel periyot $T_0$'dır; $f_0=1/T_0$ temel frekans adını alır (ekrandan, 00:15:00). İki temel periyodik işaret gerçel sinüzoid $x(t)=\cos(\omega_0t+\phi)$ ve karmaşık üstel $x(t)=e^{j\omega_0t}$'dir; burada

$$\omega_0=\frac{2\pi}{T_0}=2\pi f_0$$

temel açısal frekanstır.

### 2.2 Karmaşık üstel Fourier serisi

Hocanın "birinci yaklaşım" dediği açılım şudur (ekrandan, 00:15:00 ve 00:20:00):

$$x(t)=\sum_{k=-\infty}^{\infty}c_k\,e^{jk\omega_0t},\qquad c_k=\frac{1}{T_0}\int_{T_0}x(t)\,e^{-jk\omega_0t}\,dt$$

$k$ eksi sonsuzdan artı sonsuza gider. $k\omega_0$ çarpımı $k$ arttıkça büyüdüğü için her terim farklı frekansta bir sinüzoiddir. Bu sinüzoidler $c_k$ katsayılarıyla ağırlıklandırılıp toplanınca $x(t)$ oluşur; yani bir periyodik işaret sonsuz sayıda sinüzoidal bileşenin toplamı olarak yazılabilir. $c_k$ o frekansın işarette ne kadar bulunduğunu söyler; bu yüzden Fourier katsayısı adını alır. Karmaşık bir sayıdır, hem gerçel hem sanal kısmı vardır.

$\int_{T_0}$ herhangi bir periyot üzerinden integral demektir; genellikle $0$'dan $T_0$'a ya da $-T_0/2$'den $T_0/2$'ye alınır.

> **Hocanın vurgusu:** $x(t)$ ile $c_k$ birbirinin dualidir; biri öbüründen elde edilir ve ikisi birlikte bir bütün oluşturur. İşaret ve sistemler ile sayısal işaret işlemede bu tür çiftler daima birbirinin tersi olarak yazılır ve birlikte bilinmelidir.

$k=0$ konunca $e^{0}=1$ olur ve

$$c_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$$

elde edilir. Bu, sıfır frekansına karşılık gelen terimdir: işaretin bir periyot boyunca ortalaması, yani DC bileşeni.

$x(t)$ gerçel ise $c_{-k}=c_k^*$ olur (ekrandan, 00:20:00). Örneğin $c_1=a-jb$ ise $c_{-1}=a+jb$'dir. İkisinin genliği $\sqrt{a^2+b^2}$ ile aynıdır, fazları ise ters işaretlidir: biri $\arctan(-b/a)$, öbürü $\arctan(b/a)$.

### 2.3 Trigonometrik Fourier serisi

Euler formülü $e^{jx}=\cos x+j\sin x$ kullanılınca $e^{-jk\omega_0t}=\cos k\omega_0t-j\sin k\omega_0t$ olur (sinüs tek fonksiyon olduğu için eksi işareti öne çıkar). Bu dönüşümle ikinci temsil biçimi olan trigonometrik seri elde edilir (ekrandan, 00:25:00):

$$x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}\left(a_k\cos k\omega_0t+b_k\sin k\omega_0t\right)$$

$$a_k=\frac{2}{T_0}\int_{T_0}x(t)\cos k\omega_0t\,dt,\qquad b_k=\frac{2}{T_0}\int_{T_0}x(t)\sin k\omega_0t\,dt$$

Burada $k$ 1'den başlar; $a_0/2$ ayrı yazılmış DC bileşendir. Kosinüs ve sinüslerin frekansları $\omega_0$'ın katları olarak yükselir.

İki seri arasındaki ilişki (ekrandan, 00:25:00):

$$\frac{a_0}{2}=c_0,\qquad a_k=c_k+c_{-k},\qquad b_k=j(c_k-c_{-k})$$

$$c_k=\tfrac12(a_k-jb_k),\qquad c_{-k}=\tfrac12(a_k+jb_k)$$

$x(t)$ gerçel ise $a_k=2\,\mathrm{Re}[c_k]$, $b_k=-2\,\mathrm{Im}[c_k]$ olur. Ekranda ayrıca çift periyodik işaretlerde $b_k=0$ olduğu ve serinin yalnız kosinüs terimleri içerdiği görünüyordu.

Üçüncü biçim olan harmonik biçim, sinüsleri kaldırıp yalnız kosinüs ve bir faz terimiyle yazılır; kosinüs ile sinüs arasında yalnız bir faz farkı olduğu için faz terimi sinüs bileşenlerini de temsil eder. Hoca bu biçimin ayrıntısına girmedi.

**Soru:** Paylaşılan bir video kaynağında trigonometrik serinin ilk terimi $a_0$ ikiye bölünmeden veriliyor. Bir fark var mı?
**Cevap:** Hoca kitapta ve diğer kaynaklarda formülün $a_0/2$ olduğunu söyledi ve bunu çözümlü problemler kısmında türetmeyle gösterdi (bölüm 4.1). $c_0$ yerine yazılan terim $a_0/2$ olmalıdır; videodaki anlatımda farklı bir tanım kullanılmış olabileceğini ekledi.

> **Ek bilgi (derste anlatılmadı):** Bazı kaynaklar sabit terimi doğrudan ortalama olarak, $a_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$ diye tanımlar; o zaman seri $a_0+\sum(\dots)$ biçiminde yazılır ve ikiye bölmeye gerek kalmaz. Bu notta kullanılan tanımda ise $a_0$ da $a_k$ formülüyle ($2/T_0$ çarpanıyla) hesaplandığı için ortalamanın iki katıdır ve $a_0/2$ yazılır. İki gösterim aynı işareti verir; yalnız $a_0$'ın tanımı farklıdır.

## 3. Sürekli zamanlı Fourier dönüşümü (CTFT)

### 3.1 Seriden dönüşüme

Gerçek hayatta incelenen işaretlerin çoğu periyodik değildir; çoğu zaman yalnız tek bir işaret parçasının frekans içeriği merak edilir. Elimizdeki araç ise periyodik işaretin frekans bileşenlerini çıkarıyor. Çözüm şudur: bu tek işaret, periyodu $T_0$ olan periyodik bir işaretin bir periyodu gibi düşünülür ve $T_0$ sonsuza götürülür. Kopyalar sonsuz uzağa gidince yalnız merkezdeki işaret kalır; bu limitten Fourier dönüşüm çifti çıkar (ekrandan, 00:30:00):

$$X(\omega)=\mathcal{F}\{x(t)\}=\int_{-\infty}^{\infty}x(t)\,e^{-j\omega t}\,dt$$

$$x(t)=\mathcal{F}^{-1}\{X(\omega)\}=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(\omega)\,e^{j\omega t}\,d\omega$$

Gösterim $x(t)\leftrightarrow X(\omega)$ ya da $x(t)\xrightarrow{\text{CTFT}}X(\omega)$ biçimindedir. Hoca "Continuous Fourier Transform" yerine "Continuous Time Fourier Transform" (CTFT) demenin, ayrık zamandaki DTFT ile benzetmeyi korumak için daha iyi olduğunu söyledi.

> **Ders sonrası not:** Hoca ters dönüşümü sözlü okurken üsteli "e üzeri eksi omega t" diye ve integrali "iki pilik periyot içerisinde" diye söyledi. Ekrandaki doğru formülde üstel $e^{+j\omega t}$'dir ve sürekli zamanda integral $-\infty$'dan $\infty$'a alınır; $2\pi$ uzunluklu aralık üzerinden integral ayrık zamandaki ters DTFT'ye aittir.

$X(\omega)$ genelde karmaşıktır ve $X(\omega)=|X(\omega)|\,e^{j\phi(\omega)}$ biçiminde yazılır. $|X(\omega)|$ genlik spektrumu, $\phi(\omega)$ faz spektrumudur (ekrandan, 00:30:00).

### 3.2 Küçük omega ve büyük omega

Tahtada iki gösterim ayrıldı (ekrandan, 00:30:00). Küçük $\omega$ sürekli (analog) frekansı gösterir ve $\omega=2\pi/T_0$ ile ilişkilidir; CTFT bunu kullanır: $x(t)\to X(\omega)$. Büyük $\Omega$ ayrık (sayısal) frekansı gösterir ve $\Omega=2\pi/N_0$ ile ilişkilidir; DTFT bunu kullanır: $x[n]\to X(\Omega)$. İkisi de Yunanca omega harfidir; küçük harf sürekli, büyük harf ayrık frekans için ayrılmıştır.

### 3.3 Özellikler

Hoca kitaptaki özellik tablosuna (Table 5.1) dikkat çekti ve iki özelliği örnekledi:

- **Doğrusallık:** Zamanda işaretler katsayılarla çarpılıp toplanırsa frekansta da dönüşümleri aynı katsayılarla çarpılıp toplanır.
- **Zamanda öteleme:** İşaret $t_0$ kadar kaydırılırsa dönüşümü $e^{-j\omega t_0}$ ile çarpılır: $x(t-t_0)\leftrightarrow e^{-j\omega t_0}X(\omega)$.

İspatların hepsi kitapta bulunuyor.

### 3.4 Bilinen dönüşüm çiftleri ve yorumları

Kitaptaki Table 5-2'den şu çiftler üzerinde duruldu (ekrandan, 00:35:00):

| $x(t)$ | $X(\omega)$ |
|---|---|
| $\delta(t)$ | $1$ |
| $\delta(t-t_0)$ | $e^{-j\omega t_0}$ |
| $1$ | $2\pi\delta(\omega)$ |
| $e^{j\omega_0t}$ | $2\pi\delta(\omega-\omega_0)$ |
| $\cos\omega_0t$ | $\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$ |
| $\sin\omega_0t$ | $-j\pi[\delta(\omega-\omega_0)-\delta(\omega+\omega_0)]$ |

Yorumları şöyle verildi:

- **Dürtü:** $X(\omega)=1$, yani bütün frekanslar eşit miktarda bulunur. Bütün frekanslar eşit ağırlıkla toplanırsa dürtü elde edilir. Dürtü kaydırılınca genlik değişmez, yalnız $e^{-j\omega t_0}$ faz terimi gelir.
- **Sabit işaret:** Sabit bir işaretin sinüzoidal bileşeni yoktur. Dönüşümü yalnız $\omega=0$'da, alanı $2\pi$ olan bir dürtüdür; işaret yalnız DC bileşenden oluşur.
- **Karmaşık üstel:** $e^{j\omega_0t}$ yalnız $\omega_0$'da alanı $2\pi$ olan bir dürtü üretir.
- **Kosinüs:** $\pm\omega_0$'da genliği (alanı) $\pi$ olan iki dürtü; toplam alan yine $2\pi$'dir. $\omega_0=2\pi f_0$ olduğuna göre $f_0$ frekansında tek bir sinüzoid vardır ve $\omega$ ekseninde de gerçekten tek bir frekans bileşeni görünür.
- **Sinüs:** Yine $\pm\omega_0$'da iki dürtü, ama birbirinin ters işaretlisi ve $j$ çarpanlı; değerleri sanal eksendedir.

Negatif frekanslar fiziksel olarak yoktur; matematiksel gösterimin sonucudur. Gerçel bir işareti yorumlarken pozitif taraf yeterlidir. Örneğin genlik spektrumu sıfır civarında büyük, yükseldikçe sönüyorsa "işarette alçak frekanslar baskın, yüksek frekanslar yok gibi" denir.

Hoca $e^{j\omega_0t}\leftrightarrow2\pi\delta(\omega-\omega_0)$ çiftini doğrudan ters dönüşüm integraliyle göstermeye çalıştı; sonsuz sınırlar ve $0/0$ belirsizliği çıktığı için bu hesabı Laplace dönüşümü konusuna bıraktı. Kitapta ise bu çift başka yoldan bulunuyor: önce $\delta(t)\leftrightarrow1$ ve dualite özelliğinden $1\leftrightarrow2\pi\delta(\omega)$, sonra frekans öteleme özelliğinden $e^{j\omega_0t}\leftrightarrow2\pi\delta(\omega-\omega_0)$ (ekrandan, 01:00:00).

## 4. Sürekli zaman çözümlü problemleri

### 4.1 İki seri arasındaki ilişkinin türetilmesi

Bu problem trigonometrik seri ile karmaşık seri arasındaki ilişkiyi ister (ekrandan, 00:40:00). Karmaşık seride $c_0$ dışarı alınır ve toplam pozitif ve negatif $k$'lar diye ikiye ayrılır; ikisinde de $k$ artık 1'den sonsuza gider. $e^{\pm jk\omega_0t}$ Euler formülüyle açılınca

$$x(t)=c_0+\sum_{k=1}^{\infty}\left[(c_k+c_{-k})\cos k\omega_0t+j(c_k-c_{-k})\sin k\omega_0t\right]$$

bulunur. $c_0=a_0/2$, $c_k+c_{-k}=a_k$, $j(c_k-c_{-k})=b_k$ konunca trigonometrik seri elde edilir:

$$x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}\left(a_k\cos k\omega_0t+b_k\sin k\omega_0t\right)$$

Hoca öğrencinin sorusuna buradan cevap verdi: $c_0$ yerine yazılacaksa ilk terim $a_0/2$ olmalıdır. İki açılım birbirinden türetilir; biri karmaşık üstel tabanlı, öbürü sinüs ve kosinüs tabanlıdır.

### 4.2 Sinüzoidlerin karmaşık Fourier katsayıları

Kitaptaki problem 5.4 şu işaretlerin karmaşık Fourier serisini ister (ekrandan, 00:40:00): (a) $\cos\omega_0t$, (b) $\sin\omega_0t$, (c) $\cos(2t+\pi/4)$, (d) $\cos4t+\sin6t$, (e) $\sin^2t$. Derste (a), (c) ve (d) üzerinde duruldu.

**(a) $x(t)=\cos\omega_0t$.** İntegrale gerek yoktur. Euler'den

$$\cos\omega_0t=\tfrac12e^{j\omega_0t}+\tfrac12e^{-j\omega_0t}$$

yazılır ve $\sum c_ke^{jk\omega_0t}$ ile terim terim karşılaştırılır. $e^{j\omega_0t}$ teriminde $k=1$, $e^{-j\omega_0t}$ teriminde $k=-1$'dir. Sonuç: $c_1=c_{-1}=\frac12$, diğer bütün $k$ için $c_k=0$ (bu arada $c_0=0$). Tek frekanslı bir işaret olduğu için yalnız bir pozitif frekans ve onun negatif eşi vardır. Gerçel işaret için $c_{-k}=c_k^*$ olduğundan genlik spektrumu çift (simetrik) bir fonksiyon olarak çizilir.

**(c) $x(t)=\cos(2t+\pi/4)$.** İşaret $\cos(\omega t+\theta)$ biçimindedir: $\omega_0=2$, faz $\theta=\pi/4$. Kitaptaki çözüm (ekrandan, 00:45:00):

$$\cos\left(2t+\frac{\pi}{4}\right)=\frac12\left(e^{j(2t+\pi/4)}+e^{-j(2t+\pi/4)}\right)=\frac12e^{-j\pi/4}e^{-j2t}+\frac12e^{j\pi/4}e^{j2t}=\sum_{k=-\infty}^{\infty}c_ke^{j2kt}$$

Faz kısmı ile $t$'li kısım ayrılıp katsayılar eşleştirilir. $e^{j\pi/4}=\cos\frac\pi4+j\sin\frac\pi4=\frac{\sqrt2}{2}+j\frac{\sqrt2}{2}=\frac{1+j}{\sqrt2}$ olduğundan:

$$c_1=\frac12e^{j\pi/4}=\frac12\cdot\frac{1+j}{\sqrt2}=\frac{\sqrt2}{4}(1+j),\qquad c_{-1}=\frac12e^{-j\pi/4}=\frac{\sqrt2}{4}(1-j),\qquad c_k=0\ \ (|k|\ne1)$$

Bu katsayılar sayısal integralle de doğrulandı ($c_{\pm1}=0{,}3536\pm j0{,}3536$).

**(d) $x(t)=\cos4t+\sin6t$.** Kitap, problem 1.14'ün sonucuna dayanarak temel periyodun $T_0=\pi$, temel açısal frekansın $\omega_0=2\pi/T_0=2$ olduğunu yazıyor (ekrandan, 00:45:00). Hoca önce temel frekansın neden 4 değil de 2 olduğunu sorguladı; sonra 4 ve 6'nın ortak çarpanı olarak $4=2\cdot2$, $6=2\cdot3$ yazıldığını ve periyodun ortak katlardan bulunduğunu söyledi. Ardından işaretin Euler açılımıyla doğrudan çözülebileceğini belirtip geçti.

> **Ders sonrası not:** Kitaptaki değer doğrudur. $\cos4t$'nin periyodu $\pi/2$, $\sin6t$'nin periyodu $\pi/3$'tür; toplamın temel periyodu bunların en küçük ortak katı olan $\pi$'dir. Temel açısal frekans da 4 ve 6'nın en büyük ortak böleni olan $2$'dir. Euler açılımı $\cos4t+\sin6t=\frac12e^{j4t}+\frac12e^{-j4t}+\frac{1}{2j}e^{j6t}-\frac{1}{2j}e^{-j6t}$ olduğundan $\omega_0=2$ ile $c_{\pm2}=\frac12$, $c_3=-\frac j2$, $c_{-3}=\frac j2$, diğerleri sıfırdır (ara adım eklendi; sayısal integralle doğrulandı).

### 4.3 Kare dalganın Fourier katsayıları

Geçen haftanın sorularında da çözülen bu örnekte (problem 5.5'e ait çözüm ekranda), periyodu $T_0$ olan ve $0\le t<T_0/2$ aralığında $A$, $T_0/2\le t<T_0$ aralığında $0$ olan kare dalga ele alındı (ekrandan, 00:55:00). Böyle bir işaretin hem karmaşık hem trigonometrik serisi istenebilir.

**Verilen:** $x(t)=A$ ($0\le t<T_0/2$), $x(t)=0$ ($T_0/2\le t<T_0$), $\omega_0=2\pi/T_0$.

**İşlem:** Önce genel formül yazılır, sonra $x(t)$ yerleştirilir. İşaretin sıfır olduğu yer integrale katkı vermez:

$$c_k=\frac{1}{T_0}\int_0^{T_0}x(t)e^{-jk\omega_0t}dt=\frac{1}{T_0}\int_0^{T_0/2}Ae^{-jk\omega_0t}dt$$

$$=\frac{A}{-jk\omega_0T_0}e^{-jk\omega_0t}\Big|_0^{T_0/2}=\frac{A}{-jk\omega_0T_0}\left(e^{-jk\omega_0T_0/2}-1\right)$$

$\omega_0T_0=2\pi$ olduğundan:

$$c_k=\frac{A}{jk2\pi}\left(1-e^{-jk\pi}\right)=\frac{A}{jk2\pi}\left[1-(-1)^k\right]$$

**$e^{-jk\pi}=(-1)^k$ neden?** Hoca bunu $k$'ya değer vererek gösterdi. $e^{-j\pi}=\cos\pi-j\sin\pi=-1$; $e^{-j2\pi}=1$; $e^{-j3\pi}=-1$. Yani tek $k$ için $-1$, çift $k$ için $+1$ çıkar.

> **Ders sonrası not:** Hoca hesap sırasında bir an "$e^{-j\pi}$'nin değeri 1" ve "$\cos\pi$ 1" dedi, ardından bir öğrencinin sohbetten yazmasıyla düzeltti. Doğrusu $\cos\pi=-1$ ve $e^{\pm j\pi}=-1$'dir.

Hoca birim çember üzerinde hızlı bir kural verdi: $e^{j0}$ (ve $2\pi$'nin katları) 1, $e^{\pm j\pi}$ (ve $\pi$'nin tek katları) $-1$, $e^{j\pi/2}$ ise $j$, $e^{j3\pi/2}=e^{-j\pi/2}$ ise $-j$ verir.

**Sonuç:**

$$c_k=0\quad(k=2m\ne0),\qquad c_k=\frac{A}{jk\pi}\quad(k=2m+1)$$

$$c_0=\frac{1}{T_0}\int_0^{T_0/2}A\,dt=\frac{A}{2}$$

Yani $c_0=\frac A2$, $c_{2m}=0$, $c_{2m+1}=\frac{A}{j(2m+1)\pi}$. Sayısal kontrol: $A=1$ için $c_1=-j0{,}3183$, $c_3=-j0{,}1061$, $c_5=-j0{,}0637$.

> **Hocanın vurgusu:** "Çift $k$ için $c_k=0$" sonucu $k=0$'ı kapsamaz. $k=0$ konunca ifade $0/0$ olur; $c_0$ ayrıca hesaplanınca $A/2$ çıkar, sıfır değildir. $c_0$'ı daima ayrıca bulun; trigonometrik seride de $a_0$'ı daima ayrıca bulun.

Kitapta aynı problemin bir sonraki şıkkında darbe aralığı daha dar ($T_0/4$ civarı) ve çift fonksiyon olacak şekilde yerleştirilmiş bir kare dalga var; karşılaştırma için ona da bakılması önerildi. Hoca farklı periyodik fonksiyonların $c_k$, $a_k$ ve $b_k$ katsayılarını bulmaya çalışmayı özellikle tavsiye etti. Ekranda bu kısımda testere dişi biçimli bir periyodik işaret ve türevi (dürtü dizisi), ayrıca periyodik kare darbe dizisinin genlik spektrumunu isteyen problem 5.11 de görünüyordu (ekrandan, 01:05:00); bunlar üzerinde durulmadı.

## 5. Sayısal frekans ve örneklemenin frekansa etkisi

### 5.1 Sürekli ve ayrık frekans arasındaki önemli fark

Kitapta "very important distinction" diye vurgulanan nokta şudur (ekrandan, 01:25:00): sürekli zamanda $e^{j\omega_0t}$ işaretleri farklı her $\omega_0$ için farklıdır, ama ayrık zamanda frekansları $2\pi$'nin katı kadar farklı olan $e^{j\Omega_0n}$ dizileri aynıdır. Sürekli zamanda frekans 0'dan başlayıp 2 Hz, 100 Hz, 1 MHz diye sonsuza kadar gidebilir; ayrık zamanda ise $\Omega$ yalnız belli bir aralıkta değer alır.

### 5.2 Sayısal frekansın tanımı

Sürekli bir işaret $T_s$ aralıklarla örneklenir: $0$, $T_s$, $2T_s$, $3T_s$, ... anlarında örnek alınır. $T_s$ örnekleme periyodu, $f_s=1/T_s$ örnekleme frekansıdır. Örnekleme $t$ yerine $nT_s$ koymak demektir; $n=0$ ilk örneği, $n=1$ ikinci örneği ($T_s$ kadar sonra), $n=2$ üçüncü örneği verir.

$\cos(2\pi f_0t)$'de $t=nT_s$ konunca

$$\cos(2\pi f_0nT_s)=\cos\left(2\pi\frac{f_0}{f_s}n\right)=\cos(\Omega_0n),\qquad \Omega_0=\frac{\omega_0}{f_s}=\omega_0T_s$$

olur. Sürekli halde $\cos\omega t$ kullanılırken ayrık halde $\cos\Omega n$ kullanılır.

Daha önce görülen Nyquist koşuluna göre örnekleme frekansı işaretteki en yüksek frekansın en az iki katı olmalıdır: $f_s\ge2f_{max}$. İşaretteki en yüksek bileşen $\cos(2\pi f_{max}t)$ ise ve en küçük izin verilen $f_s=2f_{max}$ seçilirse

$$\cos\left(2\pi\frac{f_{max}}{2f_{max}}n\right)=\cos(\pi n)$$

olur. Yani sayısal frekansın alabileceği en büyük değer $\pi$'dir.

### 5.3 Beş kosinüslü işaret örneği

Tahtadaki örnek (ekrandan, 01:35:00 ve 01:40:00):

$$x_a(t)=\cos(2\pi\,5600t)+\cos(2\pi\,8400t)+\cos(2\pi\,11200t)+\cos(2\pi\,16800t)+\cos(2\pi\,25200t)$$

İşarette beş farklı frekans var: 5600, 8400, 11200, 16800 ve 25200 Hz.

**Minimum örnekleme frekansı:** En yüksek frekans $f_{max}=25200$ Hz olduğundan $f_{s,min}=2\times25200=50400$ Hz. Daha yüksek bir frekansla (örneğin 100800 Hz) örneklemek de doğrudur; alt sınır $2f_{max}$'tır.

> **Hocanın vurgusu:** "$x[n]$'i üretin" denirse önce örnekleme frekansı sorulmalıdır; analog işaretten $x[n]$'i elde etmek için $f_s$ gerekir.

**$f_s=50400$ Hz ile $x[n]$:** Her terimde $t$ yerine $n/50400$ konur ve oranlar sadeleştirilir:

| $f$ (Hz) | $f/f_s$ | $\Omega=2\pi f/f_s$ |
|---|---|---|
| 5600 | $1/9$ | $2\pi/9$ |
| 8400 | $1/6$ | $2\pi/6=\pi/3$ |
| 11200 | $2/9$ | $4\pi/9$ |
| 16800 | $1/3$ | $2\pi/3$ |
| 25200 | $1/2$ | $\pi$ |

$$x[n]=\cos\left(\frac{2\pi}{9}n\right)+\cos\left(\frac{2\pi}{6}n\right)+\cos\left(\frac{4\pi}{9}n\right)+\cos\left(\frac{2\pi}{3}n\right)+\cos(\pi n)$$

En yüksek bileşen tam $\pi$'ye düştü. $f_s=100800$ Hz seçilseydi $25200$ Hz'lik bileşen $\Omega=2\pi\cdot25200/100800=\pi/2$'ye düşecekti. Genel kural: örnekleme frekansının yarısı her zaman $\Omega=\pi$'ye karşılık gelir; sürekli bir işaretin örneklenmesiyle ulaşılabilecek en büyük sayısal frekans $\pi$'dir.

### 5.4 Ayrık frekansın $2\pi$ periyodikliği

Neden $2\pi$ ile tekrar ettiği şöyle gösterildi (ekrandan, 01:25:00):

$$e^{j(\Omega_0+2\pi k)n}=e^{j\Omega_0n}\,e^{j2\pi kn}=e^{j\Omega_0n}$$

$k$ ve $n$ tam sayı olduğu için $e^{j2\pi kn}=\cos(2\pi kn)+j\sin(2\pi kn)=1+j\cdot0=1$'dir. Örneğin $\Omega_0=2\pi/9$ noktasından $2\pi$, $4\pi$, $6\pi$ kadar ilerlense yine aynı diziye varılır.

Buradan iki sonuç çıkar. Birincisi, örnekleme yaparken işaretteki en yüksek frekansı bilmek gerekir. İkincisi, zamanda örnekleme frekans içeriğini çoğaltır: spektrum $2\pi$ aralıklarla kendini tekrar eden, periyodik bir hale gelir. Tahtada $[-\pi,\pi]$ aralığındaki üçgen biçimli bir spektrumun her $2\pi$'de tekrarlandığı çizildi (ekrandan, 01:40:00). Bu, dersin başlarındaki örnekleme konusuyla aynı olgudur.

Kitapta $\Psi_k[n]=e^{jk\Omega_0n}$, $\Omega_0=2\pi/N_0$ tanımıyla bunun bir sonucu da veriliyor: $\Psi_{k+N_0}[n]=\Psi_k[n]$; periyot kadar ilerleyince aynı temel fonksiyona dönülür (ekrandan, 01:25:00).

## 6. Ayrık zamanlı Fourier serisi (DTFS)

### 6.1 Periyodik dizi

Ayrık bir $x[n]$ dizisi, her $n$ için $x[n+N]=x[n]$ sağlayan pozitif bir tam sayı $N$ varsa periyodiktir. Bu koşulu sağlayan en küçük pozitif tam sayı temel periyot $N_0$'dır (ekrandan, 01:25:00). Tahtadaki örnekte dizi her 3 örnekte bir kendini tekrar ediyordu, yani $N_0=3$'tü.

Sürekli zamandaki $e^{j2\pi t/T_0}$ üstelinde $T_0$ yerine $N_0$, $t$ yerine $n$ konunca ayrık karmaşık üstel çıkar:

$$x[n]=e^{j(2\pi/N_0)n}=e^{j\Omega_0n},\qquad \Omega_0=\frac{2\pi}{N_0}$$

Bu dizi $N_0$ temel periyotla periyodiktir.

### 6.2 Seri ve katsayılar

Periyodik bir dizinin Fourier serisi (ekrandan, 01:45:00):

$$x[n]=\sum_{k=0}^{N_0-1}c_k\,e^{jk\Omega_0n},\qquad c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]\,e^{-jk\Omega_0n}$$

Sürekli halle karşılaştırma tahtada şöyle yapıldı: $\frac{1}{T_0}$ yerine $\frac{1}{N_0}$, $\int_{T_0}$ yerine $\sum_{n=0}^{N_0-1}$ geldi. Toplamlar herhangi $N_0$ ardışık tam sayı üzerinden alınabilir; kitap bunu $\sum_{k=\langle N_0\rangle}$ ve $\sum_{n=\langle N_0\rangle}$ diye gösteriyor. $k=0$ için $c_0=\frac1{N_0}\sum_{n=\langle N_0\rangle}x[n]$, yani yine bir periyottaki ortalamadır.

### 6.3 Katsayıların periyodikliği

Sürekli zamandan farklı olarak katsayılar sonsuza gitmez: $k$ yalnız $0$ ile $N_0-1$ arasında anlamlıdır ve

$$c_{k+N_0}=c_k$$

olur. Örneğin $k=0$ için $c_{N_0}=c_0$. Sürekli halde $c_0,c_1,c_2,\dots$ sonsuza kadar gidiyordu; ayrık halde örnekleme yüzünden katsayılar periyot $N_0$ ile sınırlandı.

## 7. Ayrık zamanlı Fourier dönüşümü (DTFT)

### 7.1 Neden gerekli?

Seriler kendini periyodik olarak tekrar eden bir diziden frekansları çıkarır. Oysa çoğu zaman karşılaşılan şey sonsuza kadar gitmeyen, kendini tekrar etmeyen belli bir $x[n]$'dir. Hocanın örneğiyle: bir kalp işaretinin yalnız bir parçasını alıp frekans içeriğine bakmak istenebilir; bunun periyodik olması gerekmez (ekrandan, 01:50:00).

### 7.2 Türetme

$|n|>N_1$ için sıfır olan sonlu bir $x[n]$ alınır. Bu dizi $N_0$ periyotla periyodik olarak genişletilir ve $x_{N_0}[n]$ elde edilir (kitapta Fig. 6-1; ekrandan, 01:50:00). $N_0\to\infty$ götürülünce kopyalar uzaklaşır ve $x_{N_0}[n]\to x[n]$ olur, yalnız ortadaki işaret kalır. Periyodik dizinin katsayıları bilindiğine göre onlardan yola çıkılır:

$$c_k=\frac{1}{N_0}\sum_{n=\langle N_0\rangle}x_{N_0}[n]e^{-jk\Omega_0n}$$

$X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]e^{-j\Omega n}$ diye bir fonksiyon tanımlanınca $c_k=\frac{1}{N_0}X(k\Omega_0)$ olur. $\frac{1}{N_0}=\frac{\Omega_0}{2\pi}$ yazılıp seriye konunca toplam, küçük $\Omega_0$ adımlarıyla dikdörtgenlerin toplamına dönüşür; $N_0\to\infty$ limitinde integral tanımındaki gibi $\Omega_0\to d\Omega$ olur. Hoca bu kısmın bir ispat olduğunu, tekrar üzerinden geçilmesini söyledi.

### 7.3 Dönüşüm çifti

Sonuç (ekrandan, 01:55:00):

$$X(\Omega)=\mathcal{F}\{x[n]\}=\sum_{n=-\infty}^{\infty}x[n]\,e^{-j\Omega n}$$

$$x[n]=\mathcal{F}^{-1}\{X(\Omega)\}=\frac{1}{2\pi}\int_{2\pi}X(\Omega)\,e^{j\Omega n}\,d\Omega$$

Gösterim $x[n]\leftrightarrow X(\Omega)$. Bu iki denklem, CTFT'deki iki denklemin ayrık zamandaki karşılığıdır.

İleri dönüşümde dizi, farklı frekanslardaki karmaşık üstellerle çarpılıp toplanır ve o $\Omega$ değerindeki frekans bileşeni ölçülür. $X(\Omega)$ sürekli bir fonksiyon olduğu için ters dönüşüm integralle yazılır; $x[n]$ ayrık olduğu için ileri dönüşüm toplamla (integralin ayrık hali) yazılır. Özetle ayrık değerler girer, sürekli bir frekans içeriği çıkar; ters dönüşümde de bu sürekli fonksiyondan ayrık değerler geri elde edilir.

### 7.4 DTFT'nin iki temel özelliği

$X(\Omega)$ karmaşık olduğu için $X(\Omega)=|X(\Omega)|e^{j\phi(\Omega)}$ biçiminde genlik ve faz olarak yazılır (ekrandan, 01:55:00).

- **Simetri:** Gerçel $x[n]$ için $X(-\Omega)=X^*(\Omega)$. $X(\Omega)=a+jb$ ise $X(-\Omega)=a-jb$; mutlak değerleri eşit, fazları ters işaretlidir. Genlik spektrumu pozitif ve negatif frekanslarda simetriktir.
- **Periyodiklik:** $X(\Omega+2\pi)=X(\Omega)$. Herhangi bir frekanstan $2\pi$ ilerleyince aynı değere gelinir.

Bu yüzden $X(\Omega)$ ya $[-\pi,\pi]$ ya da $[0,2\pi]$ aralığında incelenir. $[0,\pi]$ pozitif frekanslara karşılık gelir ve $\pi$, örnekleme frekansına göre ulaşılabilen en yüksek frekanstır. $[-\pi,0]$ negatif frekanslardır; $[0,2\pi]$ gösteriminde bunlar $[\pi,2\pi]$ aralığına düşer.

### 7.5 DTFT özellikleri

Kitaptaki özellikler (ekrandan, 02:10:00) şöyle anlatıldı:

- **Doğrusallık:** Zamanda doğrusal toplama frekansta da doğrusal toplamadır.
- **Zamanda öteleme:** $x[n-n_0]\leftrightarrow e^{-j\Omega n_0}X(\Omega)$.
- **Frekans öteleme:** İşaret zamanda karmaşık bir üstelle çarpılırsa DTFT $\Omega_0$ kadar kayar: $e^{j\Omega_0n}x[n]\leftrightarrow X(\Omega-\Omega_0)$.
- **Eşlenik:** $x^*[n]\leftrightarrow X^*(-\Omega)$; frekans ters çevrilir ve eşleniği alınır.
- **Zamanda ters çevirme:** $x[-n]\leftrightarrow X(-\Omega)$.
- **Zaman ölçekleme:** Örnek sayısı değiştirilince (alt örnekleme ya da araya örnek koyma) frekans ekseni de ölçeklenir. Bunun bir örneği bölüm 9.4'te.
- **Konvolüsyon:** Zamanda konvolüsyon frekansta çarpımdır. Uzun iki dizinin zamanda uzun sürecek konvolüsyonu yerine frekansa geçilip basit çarpma yapılır, sonra ters DTFT ile $y[n]$ bulunur.
- **Çarpma:** Zamanda iki işaretin çarpımı frekansta konvolüsyona karşılık gelir; burada frekans sürekli olduğu için bu sürekli (periyodik) bir konvolüsyondur.

Dualite, türev ve birikim (accumulation) özellikleri kafa karıştırmamak için geçildi. Hoca kitaptaki özellik tablosunun (Table 6-1) hepsini toplu verdiğini söyledi.

> **Ders sonrası not:** Hoca zaman ölçekleme satırında bir an "burada küçük omega değil büyük omega olmalı" dedi, sonra o satırın sürekli zamana ait olduğunu fark etti. Ayrık zamanda frekans değişkeni $\Omega$'dır; küçük $\omega$ yalnız sürekli zamandaki satırlarda geçer.

### 7.6 Bilinen DTFT çiftleri

- $\delta[n]\leftrightarrow1$: bütün frekanslar eşit miktarda bulunur. Spektrum $2\pi$ periyodik olduğu için $[-\pi,\pi]$'ye bakmak yeterlidir.
- $\delta[n-n_0]\leftrightarrow e^{-j\Omega n_0}$.
- Sabit dizi: $[-\pi,\pi]$ aralığında yalnız $\Omega=0$'da alanı $2\pi$ olan bir dürtü vardır; dürtü periyodik olarak her $2\pi$'de tekrar eder. Yalnız 0 frekansında bir DC bileşen bulunur; sonuç sürekli zamandakine çok benzer.

## 8. Ayrık Fourier dönüşümü (DFT)

### 8.1 DTFT'nin bilgisayardaki sorunu

$0\le n\le N-1$ dışında sıfır olan, toplam $N$ örnekli bir $x[n]$ için DTFT

$$X(\Omega)=\sum_{n=0}^{N-1}x[n]e^{-j\Omega n}$$

olur (ekrandan, 02:15:00). Dizi bilgisayara verilir, karmaşık üstellerle çarpılır ve sürekli bir sonuç elde edilir. Bu kâğıt üzerinde yapılabilir, ama sonuçların hafızada saklanması gerekir. Dizinin değerleri (örneğin 1, 2, 3, 4, 1) hafıza gözlerine yazılabilir; oysa $X(\Omega)$ süreklidir ve sürekli bir değer hafızada tutulamaz. Hangi frekansın ne kadar değerli olduğunu analiz edip üzerinde işlem yapabilmek için frekansın da örneklenmesi, ayrıklaştırılması gerekir.

### 8.2 Tanım

$[-\pi,\pi]$ (ya da $[0,2\pi]$) aralığındaki $2\pi$ uzunluk, dizideki örnek sayısı olan $N$ parçaya bölünür; her parça $2\pi/N$ genişliğindedir. $k=0$ sıfırıncı frekans, $k=1$ için $2\pi/N$, $k=2$ için $4\pi/N$ ilerlenir. DTFT bu noktalarda örneklenir (ekrandan, 02:20:00):

$$X[k]=X(\Omega)\Big|_{\Omega=\frac{2\pi}{N}k}=\sum_{n=0}^{N-1}x[n]\,e^{-j\frac{2\pi}{N}kn}=\sum_{n=0}^{N-1}x[n]\,W_N^{kn},\qquad k=0,1,\dots,N-1$$

$$W_N=e^{-j(2\pi/N)}$$

$W_N$ bir kısaltmadır ($N$'inci birim kök); altındaki $N$ örnek sayısını gösterir. $2\pi/N$ sabit olduğu için frekans yalnız $k$ indisiyle yazılır.

Ters DFT:

$$x[n]=\frac{1}{N}\sum_{k=0}^{N-1}X[k]\,W_N^{-kn},\qquad n=0,1,\dots,N-1$$

Gösterim $x[n]\leftrightarrow X[k]$. Örnek sayısı ile frekans örneği sayısı aynıdır: $n$ de $k$ de $0$'dan $N-1$'e gider. Bunun neden böyle olduğu Sayısal İşaret İşleme (DSP) dersine bırakıldı. Kitap DFT'nin Fourier dönüşümüyle karıştırılmaması gerektiğini de vurguluyor (ekrandan, 02:15:00).

## 9. Ayrık zaman çözümlü problemleri ve MATLAB ile çizim

### 9.1 Dört periyotlu dizinin DTFS katsayıları

Kitaptaki Fig. 6-7'de periyodik olarak devam eden bir dizi veriliyor ve Fourier katsayıları isteniyor. Hoca önce periyodu sordu; bir öğrenci 4 örnek dedi.

**Verilen:** $N_0=4$, bir periyottaki değerler $x[0]=0$, $x[1]=1$, $x[2]=2$, $x[3]=3$. <!-- BELİRSİZ: Şeklin karesi yok; dizinin bir periyottaki değerleri altyazıdaki "0, 1, 2, 3" sayımından ve hocanın bulduğu ortalama 3/2'den kuruldu. -->

**İşlem:** $\Omega_0=2\pi/N_0=\pi/2$. Kitap yardımcı olarak $e^{-j\Omega_0}=e^{-j\pi/2}=-j$ veriyor. Hoca bunu açtı: $e^{-j\pi/2}=\cos\frac\pi2-j\sin\frac\pi2=0-j\cdot1=-j$ (kosinüs çift fonksiyon olduğu için içindeki eksi kaybolur, sinüs tek olduğu için eksi dışarı çıkar).

$$c_k=\frac14\sum_{n=0}^{3}x[n](-j)^{kn}$$

- $c_0=\frac14(0+1+2+3)=\frac32$ (işaretin ortalaması; derste bu bulundu).
- $c_1=\frac14\left(0+1\cdot(-j)+2\cdot(-1)+3\cdot(j)\right)=\frac14(-2+2j)=-\frac12+\frac j2$ (ara adım eklendi).
- $c_2=\frac14\left(0+1\cdot(-1)+2\cdot1+3\cdot(-1)\right)=-\frac12$ (ara adım eklendi).
- $c_3=\frac14\left(0+1\cdot j+2\cdot(-1)+3\cdot(-j)\right)=-\frac12-\frac j2$ (ara adım eklendi).

Derste $c_1$, $c_2$, $c_3$'ün tek tek hesaplandığı söylendi ama sonuçları sözlü okunmadı; yukarıdaki değerler python ile doğrulandı. Hoca $c_4=c_0$, $c_5=c_1$, $c_6=c_2$ olduğunu, bu yüzden yalnız $c_0$–$c_3$'ün hesaplanmasının yeterli olduğunu vurguladı.

> **Hocanın vurgusu:** Sürekli zamanda katsayılar sonsuza giderken ayrık zamanda yalnız periyot kadar katsayı hesaplamak yeterlidir. Burada $c$ değerlerini doğru yerine koyup doğru hesap yapmak önemlidir; hoca bunu önemli bir soru tipi olarak niteledi.

### 9.2 Dürtülerin toplamı olarak verilen dizi

Kitapta $x[n]$'in $k$ üzerinden eksi sonsuzdan artı sonsuza giden bir dürtü toplamıyla verildiği ve çizilmesinin istendiği sorular var: $k=0$ için $\delta[n]$, $k=1$ için $n=4$'te bir dürtü çizilir ve bu şekilde devam edilir. <!-- BELİRSİZ: Ekrandaki dürtü toplamının tam ifadesi karede yok; altyazıda yalnız "k=0 için impuls n, k=1 için 4'te" geçiyor. -->

> **Hocanın vurgusu:** Bu tür sorular için $\delta[n]$, $\delta[n-1]$, $u[n]$, $u[-n]$, $u[n-n_0]$ gibi temel işaretlerin nasıl çizildiğini ve bunlarla tanımlanan $x[n]$, $x(t)$ fonksiyonlarının çizimini iyi çalışın.

### 9.3 $\cos(\pi n/4)$'ün Fourier serisi

**Verilen:** $x[n]=\cos\frac{\pi n}{4}$, yani $\Omega_0=\frac{\pi}{4}$.

**Temel periyot:** $\frac{2\pi}{N_0}=\frac{\pi}{4}\Rightarrow N_0=8$.

**Katsayılar:** Euler'den $\cos\frac{\pi n}{4}=\frac12e^{j\Omega_0n}+\frac12e^{-j\Omega_0n}$. Bu da $c_1=\frac12$ ve $c_{-1}=\frac12$ verir. Katsayılar 8 ile periyodik olduğu için $c_{-1}=c_{-1+8}=c_7=\frac12$. $0\le k\le7$ aralığında diğer bütün $c_k=0$'dır. Sonuç python'da 8 noktalı DFT'nin $1/8$ katıyla doğrulandı ($c_1=c_7=0{,}5$).

> **Hocanın vurgusu:** $N_0$ kaç ise o kadar katsayı bulmak gerekir; bu örnekte 8 katsayıdan yalnız $c_1$ ve $c_7$ sıfırdan farklıdır.

### 9.4 Zaman ölçeklemenin DTFT'ye etkisi

Kitapta 5 örnekli dikdörtgen bir $x[n]$ girişi ve onun DTFT'si veriliyor. Dizi zamanda yayıldığında (her örnek arasına sıfır konarak genişletildiğinde) DTFT $X(2\Omega)$, daha da yayıldığında $X(3\Omega)$ olur. Hoca önce "downsampling" dedi, sonra dizinin yayıldığını düzeltti. $X(3\Omega)$ frekansta sıkışmış bir fonksiyondur: $[-\pi,\pi]$ aralığında asıl spektrumun 3 kopyası görünür. Yani zamanda yayılma frekansta sıkışma demektir.

### 9.5 Dikdörtgen spektrumun ters DTFT'si (problem 6.15)

**Soru (ekrandan, 02:30:00):** (a) $X(\Omega)=1$ ($|\Omega|\le W$), $X(\Omega)=0$ ($W<|\Omega|\le\pi$) ile tanımlanan dikdörtgen darbe spektrumunun ters Fourier dönüşümü $x[n]$'i bulun. (b) $W=\pi/4$ için $x[n]$'i çizin.

Spektrum alçak frekanslarda değer alan, $W$'nin dışında sıfır olan ve $2\pi$ ile kendini tekrar eden bir fonksiyondur. Soru, böyle bir frekans içeriğine sahip dizinin ne olduğudur.

**Çözüm (derste ve ekranda):** Ters DTFT formülü kullanılır. İntegral $[-\pi,\pi]$ üzerinden alınır, ama $|\Omega|>W$ için $X(\Omega)=0$ olduğundan yalnız $[-W,W]$ kalır:

$$x[n]=\frac{1}{2\pi}\int_{-\pi}^{\pi}X(\Omega)e^{j\Omega n}d\Omega=\frac{1}{2\pi}\int_{-W}^{W}e^{j\Omega n}d\Omega=\frac{1}{2\pi}\cdot\frac{e^{j\Omega n}}{jn}\Big|_{-W}^{W}$$

$$=\frac{1}{2\pi jn}\left(e^{jWn}-e^{-jWn}\right)=\frac{1}{\pi n}\cdot\frac{e^{jWn}-e^{-jWn}}{2j}=\frac{\sin Wn}{\pi n}$$

Son adımda Euler'den $\sin x=\frac{e^{jx}-e^{-jx}}{2j}$ kullanıldı (ekrandan, 02:35:00). Böylece

$$\frac{\sin Wn}{\pi n}\ \leftrightarrow\ X(\Omega)=\begin{cases}1,&|\Omega|\le W\\0,&W<|\Omega|\le\pi\end{cases}$$

**$n=0$ değeri:** $\sin0=0$ ve paydada $0$ olduğu için $0/0$ belirsizliği oluşur. Hoca bunun L'Hospital kuralıyla giderildiğini söyledi: $\lim_{n\to0}\frac{\sin Wn}{\pi n}=\frac{W}{\pi}$ (ara adım eklendi). $W=\pi/4$ için $x[0]=1/4$; bu ekrandaki şekilde de görünüyor (ekrandan, 02:35:00). Diğer değerler doğrudan bulunur: $x[\pm1]=\frac{\sin(\pi/4)}{\pi}\approx0{,}2251$, $x[\pm2]=\frac{1}{2\pi}\approx0{,}1592$, $x[\pm3]\approx0{,}0750$, $x[\pm4]=0$. Bu değerler ters DTFT integralinin sayısal hesabıyla da doğrulandı.

Kitaptaki şekilde (Fig. 6-13b) dizinin $n=0$'da en büyük değeri aldığı, $n=\pm4$'te sıfırdan geçtiği ve iki yana doğru sönerek salındığı görülüyor.

### 9.6 MATLAB ile çizim

Hoca aynı diziyi MATLAB Online'da çizmeye başladı (ekrandan, 02:40:00). Önce $n$'e $-15$ ile $15$ arası değerler verildi, sonra $x[n]$ hesaplanıp `stem` ile çizildi. Ekranda yazılan komutlar şunlardı:

```matlab
n=-15:15
xn=sin(W.*n)/(pi*n)=
stem(xn,n)
```

İkinci satırın sonundaki fazladan `=` işareti MATLAB'de "Incorrect use of '=' operator" hatası verdi. Hoca $W$'nin yukarıda ayrıca tanımlanacağını, `W.*n` ile çarpımın her eleman için ayrı yapılması gerektiğini (nokta çarpım) söyledi. `stem` fonksiyonu bulunan $x[n]$ değerlerini $n$ değerlerine karşı ayrık olarak çizer.

> **Ders sonrası not:** Ekrandaki kodda üç düzeltme gerekir. (1) Satır sonundaki `=` silinmelidir. (2) Bölme de eleman eleman olmalıdır: `./(pi*n)`. Yalnız `/` kullanılırsa MATLAB iki satır vektör arasında matris bölmesi (en küçük kareler çözümü) yapar ve tek bir sayı döndürür; ekrandaki hâliyle dizi elde edilmez. (3) `stem` fonksiyonunun ilk argümanı yatay eksen olmalıdır: `stem(n,xn)`. Ayrıca $n=0$'da `sin(0)/0` ifadesi `NaN` verir; bu noktaya L'Hospital sonucu $W/\pi$ elle konmalıdır. Düzeltilmiş kod aşağıda (MATLAB'de çalıştırılmadı; aynı mantık python ile denendi):

```matlab
W  = pi/4;
n  = -15:15;
xn = sin(W.*n)./(pi*n);
xn(n==0) = W/pi;      % 0/0 belirsizliği, L'Hospital
stem(n, xn)
xlabel('n'), ylabel('x[n]')
```

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Problem 5.4 (c). $x(t)=\cos(2t+\pi/4)$ işaretinin karmaşık üstel Fourier serisini bulun.

> **Çözüm (derste ve ekranda):** $\omega_0=2$. $x(t)=\frac12e^{-j\pi/4}e^{-j2t}+\frac12e^{j\pi/4}e^{j2t}$. Katsayılar: $c_1=\frac{\sqrt2}{4}(1+j)$, $c_{-1}=\frac{\sqrt2}{4}(1-j)$, $|k|\ne1$ için $c_k=0$. Ayrıntı bölüm 4.2'de.

**Soru 2** (ekrandan, 00:40:00): Problem 5.4 (d). $x(t)=\cos4t+\sin6t$ işaretinin karmaşık üstel Fourier serisini bulun.

> **Çözüm (derste verilmedi):** Temel periyot $T_0=\pi$, $\omega_0=2$. $x(t)=\frac12e^{j2(2)t}+\frac12e^{-j2(2)t}+\frac{1}{2j}e^{j2(3)t}-\frac{1}{2j}e^{-j2(3)t}$. Buradan $c_2=c_{-2}=\frac12$, $c_3=-\frac j2$, $c_{-3}=\frac j2$, diğer bütün $c_k=0$. Sonuç sayısal integralle doğrulandı.

**Soru 3** (ekrandan, 00:55:00): Periyodu $T_0$ olan, $0\le t<T_0/2$ aralığında $A$, diğer yarıda $0$ olan kare dalganın karmaşık Fourier katsayılarını bulun.

> **Çözüm (derste ve ekranda):** $c_k=\frac{A}{jk2\pi}[1-(-1)^k]$. Buradan $c_0=\frac A2$ (ayrıca hesaplanır), $c_{2m}=0$, $c_{2m+1}=\frac{A}{j(2m+1)\pi}$. Ayrıntı bölüm 4.3'te.

**Soru 4** (ekrandan, 01:35:00): $x_a(t)=\cos(2\pi\,5600t)+\cos(2\pi\,8400t)+\cos(2\pi\,11200t)+\cos(2\pi\,16800t)+\cos(2\pi\,25200t)$ işareti için minimum örnekleme frekansını bulun ve bu frekansla $x[n]$'i yazın.

> **Çözüm (derste ve ekranda):** $f_{s,min}=2\times25200=50400$ Hz. $x[n]=\cos\frac{2\pi}{9}n+\cos\frac{\pi}{3}n+\cos\frac{4\pi}{9}n+\cos\frac{2\pi}{3}n+\cos\pi n$. En yüksek bileşen $\Omega=\pi$'dedir; $f_s=100800$ Hz seçilseydi $\pi/2$'de olurdu.

**Soru 5** (derste sözlü, 02:21:15): Kitaptaki Fig. 6-7'de verilen periyodik dizinin periyodu nedir ve Fourier katsayıları nelerdir?

> **Çözüm (kısmen derste verildi):** Periyot $N_0=4$ (bir öğrenci cevapladı), $\Omega_0=\pi/2$. Derste $c_0=3/2$ bulundu. Bir periyottaki değerler $0,1,2,3$ alınırsa $c_1=-\frac12+\frac j2$, $c_2=-\frac12$, $c_3=-\frac12-\frac j2$ çıkar (derste okunmadı, python ile doğrulandı). <!-- BELİRSİZ: Şeklin karesi yok; dizi değerleri altyazıdan kuruldu. -->

**Soru 6** (derste sözlü, 02:27:36): $x[n]=\cos(\pi n/4)$ dizisinin Fourier serisi katsayılarını bulun.

> **Çözüm (derste verildi):** $N_0=8$. $c_1=c_{-1}=c_7=\frac12$, $0\le k\le7$ aralığında diğer katsayılar sıfır.

**Soru 7** (ekrandan, 02:30:00): Problem 6.15. (a) $|\Omega|\le W$ için 1, $W<|\Omega|\le\pi$ için 0 olan $X(\Omega)$'nın ters Fourier dönüşümü $x[n]$'i bulun. (b) $W=\pi/4$ için $x[n]$'i çizin.

> **Çözüm (derste ve ekranda):** $x[n]=\frac{\sin Wn}{\pi n}$, $x[0]=W/\pi$. $W=\pi/4$ için $x[0]=0{,}25$, $x[\pm1]\approx0{,}2251$, $x[\pm2]\approx0{,}1592$, $x[\pm3]\approx0{,}0750$, $x[\pm4]=0$. Ayrıntı bölüm 9.5'te.

**Soru 8** (derste sözlü, 02:36:19; ödev olarak verildi): Problem 6.15'teki $x[n]=\frac{\sin Wn}{\pi n}$ dizisini $W=\pi/2$, $\pi/3$, $\pi/4$ ve $\pi/6$ için $-15\le n\le15$ aralığında bir program (örneğin MATLAB) ile ayrık olarak çizin. $W$ genişleyip daraldıkça $x[n]$ nasıl değişiyor?

> **Çözüm (derste verilmedi):** Bölüm 9.6'daki düzeltilmiş kod $W$ değerleri üzerinde döngüye alınır:
>
> ```matlab
> n  = -15:15;
> Ws = [pi/2 pi/3 pi/4 pi/6];
> for i = 1:4
>     W  = Ws(i);
>     xn = sin(W.*n)./(pi*n);
>     xn(n==0) = W/pi;
>     subplot(4,1,i), stem(n, xn), title(sprintf('W = pi/%g', pi/W))
> end
> ```
>
> Aynı hesap python ile yapıldı (MATLAB'de çalıştırılmadı). Sonuçlar: tepe değeri $x[0]=W/\pi$ sırasıyla $0{,}5$, $0{,}333$, $0{,}25$, $0{,}167$; ilk sıfır geçişi $n=\pi/W$ noktasında, yani sırasıyla $n=2$, $3$, $4$, $6$'da. $W$ büyüdükçe (spektrum genişledikçe) dizinin tepesi yükselir ve ana lobu daralır; $W$ küçüldükçe tepe alçalır ve dizi zamanda yayılır. Bu, zamanda daralmanın frekansta genişlemeye karşılık geldiğini gösterir.

## Dersin Toparlaması

Ders, sürekli zamanda Fourier serilerinin ve dönüşümünün tekrarıyla başladı. Periyodik bir işaret, frekansları temel frekansın katları olan karmaşık üstellerin toplamı olarak yazıldı; karmaşık katsayılarla trigonometrik katsayılar arasındaki ilişki türetildi ve $c_0=a_0/2$'nin işaretin ortalaması olduğu gösterildi. Periyot sonsuza götürülerek CTFT elde edildi ve dürtü, sabit, karmaşık üstel, kosinüs ve sinüsün dönüşümleri yorumlandı. Çözümlü örneklerde sinüzoidlerin katsayıları Euler açılımıyla, kare dalganınki integralle bulundu; $c_0$'ın daima ayrıca hesaplanması gerektiği vurgulandı.

İkinci bölümde ayrık zamana geçildi. Örneklemeyle $\Omega=\omega/f_s$ sayısal frekansı tanımlandı; ayrık frekansın $2\pi$ ile periyodik olduğu ve en büyük değerinin $\pi$ olduğu beş kosinüslü bir örnekle gösterildi. Ardından DTFS (yalnız $N_0$ katsayılı), sonlu diziler için DTFT ve onun simetri, periyodiklik ve konvolüsyon gibi özellikleri işlendi. Bilgisayarda sürekli $X(\Omega)$ saklanamayacağı için frekansın da örneklenmesiyle DFT tanımlandı. Ders, dikdörtgen spektrumun ters DTFT'si olan $\frac{\sin Wn}{\pi n}$ dizisi ve bunun MATLAB'de farklı $W$ değerleri için çizilmesiyle bitti. Hoca sonraki bölümde Laplace ve z dönüşümlerine geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
