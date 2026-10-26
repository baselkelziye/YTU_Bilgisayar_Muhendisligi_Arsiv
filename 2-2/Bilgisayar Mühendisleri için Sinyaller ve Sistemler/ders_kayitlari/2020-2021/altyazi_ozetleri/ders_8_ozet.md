# Ders 8 Çalışma Özeti

## Genel Konular

- Dersin tarihi 21 Ağustos 2021 Cumartesi, sabah oturumu (yaz okulu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:03:45'te başlar.
  - İki ara verildi: yaklaşık 01:01:20 - 01:14:00 ve 01:59:35 - 02:13:20.
  - Aynı gün öğleden sonra 14:30'da sınav vardı. Hoca dersin sonunda "saat 1'de görüşmek üzere" dedi.
- Ayrık konvolüsyonda sıfır noktasının (indeksin) bulunması
  - Darbe ($\delta$) gösterimi ve dağılma özelliği ile çözüm.
  - Polinom çarpımı benzetmesi.
  - Sınırları toplama kısa yolu.
- Ödev teslimi ve sınav yüklemesi hakkında duyurular.
- Önceki dersteki bir hatanın düzeltilmesi: ayrık zamanda periyodiklik.
- Fourier serileri: uygulamalar ve örnekler
  - Ses, nota ve tını (timbre); spektrogram; telefon tuşu (DTMF) benzeri analiz.
  - İki frekansın çarpımından oluşan işaret (672 Hz ve 648 Hz bileşenleri).
  - Kare dalga ($T_0 = 0.04$ s) için $c_k$ katsayıları, spektrum ve sentez.
  - MATLAB'de tek harmoniklerin toplanmasıyla kare dalgaya yaklaşma.
  - $\sin^3(3\pi t)$ örneği ve yarım dalga doğrultulmuş sinüs örneği.
  - Gibbs olayı.
- Fourier dönüşümü (Fourier transform) konusuna giriş
  - Periyodik olmayan işaretler için Fourier dönüşümü ve ters dönüşüm.
  - Dikdörtgen darbenin dönüşümü ve sinc fonksiyonu.
  - $e^{-bt}u(t)$ işaretinin dönüşümü, genlik ve faz.
  - Temel dönüşüm çiftleri: $1$, $u(t)$, $\delta(t)$, $\cos\omega_0 t$, $\sin\omega_0 t$, $e^{j\omega_0 t}$.
  - FFT ve MATLAB denemeleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınavda konvolüsyon sorusunda adımlar gösterilmeli.
  - Kabul edilen yollar iki tane: ters çevir-kaydır-çarp-topla ya da $\delta$ gösterimi ve dağılma özelliği.
  - Polinom çarpımı ile çözüm sınavda kabul edilmez.
  - Sınavda sıfır noktasının doğru bulunması önemli. Ödevde bundan puan kırılmadı.
- MATLAB ve Python'daki hazır konvolüsyon fonksiyonları sonucu doğrudan sıfırıncı örnekten başlatır. İndeks bilgisini ayrıca sizin vermeniz gerekir.
- Gerçek uygulamalarda negatif indis yoktur. Örnekler sıfırdan başlar. Teoride ise indis önemlidir.
- Ayrık zamanda periyodiklik için periyodun **tam sayı** olması gerekir. Sürekli zamandaki "rasyonel" ölçütü burada yetmez.
- Temel frekans bileşenlerin EBOB'u ile bulunur. En küçük frekans her zaman temel frekans değildir.
- Fourier dönüşümünün sonucunda $t$ kalmamalıdır. Kalıyorsa bir yerde hata yapılmıştır.
- Bir dönüşümün dönüşüm sayılması için tersinin de olması gerekir.
- Bu derste önemli olan integral almak değil, dönüşüm sonucunu yorumlamak ve kullanmaktır. Bu yüzden dönüşüm tabloları çok önemlidir.
  - En temel kullanım: konvolüsyonu dönüşüm düzleminde çarpma ile yapmak.
- Ödev ve sınav yükleme:
  - Ödevin gelip gelmediğini paylaşılan Excel'den kontrol edin. Dosya adı alanı boşsa ödev gelmemiştir.
  - Başarılı yükleme ekran görüntüsü saklayın. Kanıt yoksa "unuttum, geç kaldım" kabul edilmez.
  - Sınav için ayrıca bir yedek yükleme linki paylaşılacak.
  - Sınavda sistem ilk 10-15 dakika açık kalacak.
- Derslere canlı katılım önemli. Videoları sonradan izlemek birikme yüzünden genelde gerçekçi olmuyor.
- Fourier serileri sınava dahildir. Fourier dönüşümü yeni konudur.
- Fourier serileriyle ilgili bir ödev verilecek. Hoca ödev sayısını 3'te tutmayı planlıyor.

## Kısa Tekrar Notları

- Ayrık konvolüsyonda sonuç sınırları: $x[n]$ $[a_1, b_1]$'de, $y[n]$ $[a_2, b_2]$'de tanımlıysa sonuç $[a_1+a_2,\ b_1+b_2]$'de tanımlıdır.
- $x[n] = \delta[n+1]+\delta[n]+\delta[n-1]$, $y[n] = \delta[n]+\delta[n-1]$ $\Rightarrow$ $x*y = [1,\ \underline{2},\ 2,\ 1]$, $n=-1$'den başlar.
- Ayrık sinüzoid $\cos(\Omega_0 n)$ yalnız $\Omega_0/2\pi$ rasyonel ise periyodiktir. $\cos(n/4)$ periyodik değildir.
- Kare dalga ($T_0=0.04$ s, ilk yarı periyotta 1, ikinci yarıda 0): $c_0 = \tfrac12$, $c_k = \frac{1-(-1)^k}{j2\pi k}$.
  - $k$ tek: $c_k = \frac{1}{j\pi k} = \frac{-j}{\pi k}$. $k$ çift: $c_k = 0$. $f_0 = 25$ Hz.
  - $x(t) = \tfrac12 + \sum_{k\ \text{tek}} \frac{2}{\pi k}\sin(2\pi\,25k\,t)$.
- $\sin^3(3\pi t) = \frac{j}{8}e^{j9\pi t} - \frac{3j}{8}e^{j3\pi t} + \frac{3j}{8}e^{-j3\pi t} - \frac{j}{8}e^{-j9\pi t}$. Temel frekans 1.5 Hz.
- Fourier dönüşümü: $X(\omega) = \int_{-\infty}^{\infty} x(t)e^{-j\omega t}\,dt$. Ters dönüşüm: $x(t) = \frac{1}{2\pi}\int_{-\infty}^{\infty} X(\omega)e^{j\omega t}\,d\omega$.
- Dikdörtgen darbe (genişlik $\tau$): $P_\tau(\omega) = \frac{2\sin(\omega\tau/2)}{\omega} = \tau\,\frac{\sin(\omega\tau/2)}{\omega\tau/2}$.
- $e^{-bt}u(t) \leftrightarrow \frac{1}{b+j\omega}$, $b>0$. $|X| = \frac{1}{\sqrt{b^2+\omega^2}}$, $\angle X = -\arctan(\omega/b)$.
- $\delta(t) \leftrightarrow 1$; $1 \leftrightarrow 2\pi\delta(\omega)$; $e^{j\omega_0 t} \leftrightarrow 2\pi\delta(\omega-\omega_0)$.
- $\cos\omega_0 t \leftrightarrow \pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$; $\sin\omega_0 t \leftrightarrow j\pi[\delta(\omega+\omega_0)-\delta(\omega-\omega_0)]$.
- Doğrudan DFT hesabı $O(N^2)$, FFT $O(N\log N)$.

## Detaylı Açıklamalar

### Ayrık konvolüsyonda sıfır noktası

- Örnek: $x[n] = [1, \underline{1}, 1]$ ($n=-1,0,1$), $y[n] = [\underline{1}, 1]$ ($n=0,1$).
  - Sıfır noktaları farklı seçilse de sayısal sonuç aynıdır: $[1,2,2,1]$. Değişen yalnız indislerdir.
- Yol 1: darbe gösterimi ve dağılma özelliği.
  - $x[n] = \delta[n+1] + \delta[n] + \delta[n-1]$.
  - $y[n]*x[n] = y[n+1] + y[n] + y[n-1]$, çünkü $y[n]*\delta[n-k] = y[n-k]$.
  - $y[n+1] = \delta[n+1]+\delta[n]$, $y[n] = \delta[n]+\delta[n-1]$, $y[n-1] = \delta[n-1]+\delta[n-2]$.
  - Toplam: $\delta[n+1] + 2\delta[n] + 2\delta[n-1] + \delta[n-2]$. Yani $[1, \underline{2}, 2, 1]$.
- Yol 2: polinom çarpımı benzetmesi.
  - Her örneği $x^{n}$ terimi gibi düşünün: $(x^{-1}+x^0+x^1)(x^0+x^1)$.
  - Çarpım $x^{-1} + 2x^0 + 2x^1 + x^2$. Katsayılar sonucu, üsler indisleri verir.
  - Hoca bunun z-dönüşümünden gelen bir özellik olduğunu söyledi. Z-dönüşümünde konvolüsyon çarpmaya dönüşür.
- Yol 3: sınırları toplama.
  - $x$: $[-1, 1]$, $y$: $[0, 1]$. Sonuç: $[-1, 2]$.
  - Kaydırarak bulunan sonuç bu indislere yerleştirilir.

### Ayrık zamanda periyodiklik (önceki dersin düzeltmesi)

- Sürekli zaman: $\cos(t+\pi/4)$ için $\omega_0 = 1$, $T_0 = 2\pi$. İşaret periyodiktir.
- Ayrık zaman: $\cos(n/4)$ için $\Omega_0 = 1/4$.
  - $N_0 = 2\pi/\Omega_0 = 8\pi$ çıkar. Bu bir tam sayı değildir.
  - Hiçbir tam sayı $k$ için $8\pi k$ tam sayı olmaz. İşaret periyodik değildir.
  - Hoca önceki derste bu işarete yanlışlıkla periyodik dediğini söyledi ve düzeltti.
- Ayrık zamanda birden fazla bileşen varsa periyotların oranına bakılır. Oran yine tam sayılarla ifade edilebilmelidir.

### Fourier serilerinin uygulamaları

- Harmonik işaret: frekansları temel frekansın tam katları olan bileşenlerden oluşur. Bileşen ekledikçe kare dalgaya yaklaşılabilir.
- Harmonik olmayan işarette bileşenler ortak bir temel frekansın katı değildir. Bu durumda Fourier serisi doğru sonuç vermez.
- Nota ve tını:
  - Saf bir nota (örneğin 1047 Hz'lik C6) tek bir sinüzoiddir ve kolayca sentezlenir.
  - Obua veya klarnetle çalınan aynı notada ek harmonikler vardır. Bu harmonikler tınıyı oluşturur.
  - Gerçek enstrüman sesini sentezlemek zordur. Analiz ise baskın frekanslara bakarak nota, makam veya tür tespitine izin verir. Hoca kendi tezinden örnek verdi.
- Spektrogram: frekansın zamanla değişimini gösterir.
  - Ses kısa çerçevelere bölünür (örnekte yaklaşık 40 ms). Her çerçevenin frekans içeriği bulunur.
  - Telefon tuşlarındaki gibi bir "kod kitabı" ile hangi tuşa ya da notaya basıldığı bulunabilir.
  - Hoca, 7 haneli bir telefon tuşlama sesinden tuşları bulma gibi bir ödev verebileceğini söyledi.
- İki frekansın çarpımı:
  - $x(t) = \cos(2\pi\,660\,t)\sin(2\pi\,12\,t)$ gibi bir işaret, çarpım-toplam dönüşümüyle 672 Hz ve 648 Hz bileşenlerine ayrılır.
  - Temel frekans $\mathrm{EBOB}(648, 672) = 24$ Hz.
- Chirp (doğrusal frekans modülasyonu, "kuş sesi"): frekansı zamanla doğrusal artan işaret. Hoca bunun sinyal işleme dersinin konusu olduğunu ve bu dersten sorumlu olunmadığını söyledi.

### Kare dalga örneği ($T_0 = 0.04$ s)

- İşaret: $0\le t<0.02$ için 1, $0.02\le t<0.04$ için 0.
- $c_k = \frac{1}{0.04}\int_0^{0.02} e^{-j\frac{2\pi}{0.04}kt}\,dt = \frac{1 - e^{-j\pi k}}{j2\pi k} = \frac{1-(-1)^k}{j2\pi k}$.
  - $k$ tek: $c_k = \frac{2}{j2\pi k} = \frac{1}{j\pi k} = \frac{-j}{\pi k}$.
  - $k$ çift ($\ne0$): $c_k = 0$.
- $c_0 = \frac{1}{0.04}\int_0^{0.02} 1\,dt = \frac12$ (DC bileşen).
- Temel frekans $f_0 = 1/0.04 = 25$ Hz, $\omega_0 = 50\pi$ rad/s.
- Spektrum çizgileri: 0 Hz'de $1/2$; $\pm25$, $\pm75$, $\pm125$ Hz'de $\mp j/\pi$, $\mp j/3\pi$, $\mp j/5\pi$.
  - "İlk 3 bileşeni çizin" denirse genliği sıfır olan 50 Hz çizilmez. 25, 75 ve 125 Hz çizilir.
- Trigonometrik katsayılar: $a_k = 2\,\mathrm{Re}\{c_k\} = 0$, $b_k = -2\,\mathrm{Im}\{c_k\} = \frac{2}{\pi k}$ ($k$ tek).
  - İşaret (DC çıkarılınca) tek simetrilidir. Kosinüs bileşeni beklenmez.
- Sentez: eşlenik çiftler toplanır.
  - $c_1e^{j\omega_0 t} + c_{-1}e^{-j\omega_0 t} = \frac{2}{\pi}\cos(2\pi\,25\,t - \pi/2) = \frac{2}{\pi}\sin(2\pi\,25\,t)$.
  - $x(t) = \frac12 + \frac{2}{\pi}\sin(50\pi t) + \frac{2}{3\pi}\sin(150\pi t) + \dots$
- MATLAB denemesi:
  - Hoca $\sin t$, $\sin 3t$, $\sin 5t$, $\sin 7t$ işaretlerini adım adım topladı (`subplot` ile 4 satır).
  - Toplam her adımda kare dalgaya biraz daha yaklaştı.
  - Genlikler doğru alınırsa ($1/k$ ile ölçeklenmiş) yakınsama daha iyi olur.

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

### $\sin^3(3\pi t)$ ve yarım dalga doğrultulmuş sinüs

- $x(t) = \sin^3(3\pi t)$:
  - $\sin(3\pi t)$'nin frekansı 1.5 Hz'dir. Küp alınınca 1.5 Hz ve 4.5 Hz bileşenleri çıkar.
  - Temel frekans $\mathrm{EBOB}(1.5, 4.5) = 1.5$ Hz.
  - $x(t) = \frac{j}{8}e^{j9\pi t} - \frac{3j}{8}e^{j3\pi t} + \frac{3j}{8}e^{-j3\pi t} - \frac{j}{8}e^{-j9\pi t}$.
  - $k=\pm2$ bileşeni (3 Hz) yoktur. DC bileşen de yoktur.
  - Genlik-faz: 1.5 Hz'de $|c_1| = 0.375$, $\angle c_1 = -\pi/2$; 4.5 Hz'de $|c_3| = 0.125$, $\angle c_3 = +\pi/2$.
  - Hoca, bu katsayıları integralle bulmanın uzun olduğunu ve sınavda böyle zor integral sormayacağını söyledi.
- Yarım dalga doğrultulmuş sinüs: bir periyodun ilk yarısında $\sin(2\pi t/T_0)$, ikinci yarısında 0.
  - Çözümde $\sin$, $\frac{e^{j\theta}-e^{-j\theta}}{2j}$ şeklinde yazılır. Böylece kısmi integrasyona gerek kalmaz; üsler ortak parantezde birleşir.
  - $k \ne \pm1$ için: $k$ tek ise $a_k = 0$; $k$ çift ise $a_k = \frac{-1}{\pi(k^2-1)}$.
  - $k = \pm1$ durumu formülde $0/0$ verir. Bu değerler ayrıca hesaplanmalıdır (bkz. ders sonrası notlar).

### Gibbs olayı

- Kare dalgaya bileşen eklendikçe süreksizlik noktalarının yanında "kulak" gibi taşmalar oluşur. Buna Gibbs olayı denir.
- Taşmanın sebebi süreksizlik noktasıdır. Sonlu sayıda bileşenle süreksizlik tam elde edilemez.
- Hoca ayrıntıların sinyal işleme derslerinde anlatıldığını söyledi.

### Fourier dönüşümüne giriş

- Fourier serisi yalnız periyodik işaretlerde kullanılabilir. Periyodik olmayan işaretler için Fourier dönüşümü kullanılır.
- $X(\omega) = \int_{-\infty}^{\infty} x(t)e^{-j\omega t}\,dt$, $e^{-j\omega t} = \cos\omega t - j\sin\omega t$.
  - İşaret, bütün frekanslardaki sinüs ve kosinüslerle karşılaştırılır. İşarette bulunan frekanslarda sonuç tepe yapar.
  - Sonuçta $t$ kaybolur, yalnız $\omega$ kalır.
- Ters dönüşüm: $x(t) = \frac{1}{2\pi}\int_{-\infty}^{\infty} X(\omega)e^{j\omega t}\,d\omega$. $\frac{1}{2\pi}$ bir normalizasyon katsayısıdır.
- Gösterim: zaman işareti küçük harf ($x(t)$), dönüşümü büyük harf ($X(\omega)$). $\mathcal{F}\{x(t)\} = X(\omega)$, $\mathcal{F}^{-1}\{X(\omega)\} = x(t)$.
- Her dönüşüm bir düzlemden diğerine geçiştir ($t \to \omega$, $n \to z$, $t \to s$). Geri dönülemiyorsa dönüşüm sayılmaz. Laplace, z ve Fourier dönüşümlerinin hepsinin tersi vardır.
- Doğrudan hesap iki iç içe döngüyle yapılır ve $O(N^2)$ karmaşıklığındadır. FFT bunu $O(N\log N)$'e indirir.
- Gerçek bir işaretin dönüşümü genelde karmaşık sayıdır.
  - Genlik spektrumu $|X(\omega)|$ hangi frekansların var olduğunu gösterir.
  - Faz spektrumu $\angle X(\omega)$ faz bilgisini gösterir.
- Hoca dönüşümü teknik resimdeki farklı görünüşlere ve ultrason/röntgene benzetti. İşarete başka bir açıdan bakmak, zaman düzleminde görünmeyen frekans bilgisini ortaya çıkarır.

### Dikdörtgen darbenin Fourier dönüşümü

- $p_\tau(t) = 1$, $-\tau/2 \le t \le \tau/2$; diğer yerlerde 0.
- $P_\tau(\omega) = \int_{-\tau/2}^{\tau/2} e^{-j\omega t}\,dt = \frac{2}{\omega}\cdot\frac{e^{j\omega\tau/2} - e^{-j\omega\tau/2}}{2j} = \frac{2\sin(\omega\tau/2)}{\omega}$.
- Bu bir sinc biçimidir. $\omega = 0$'da değer $\tau$'dur; frekans arttıkça salınarak sönümlenir.
- Hoca MATLAB'de $\sin t / t$ çizdirerek sönümlenen biçimi gösterdi.

### $e^{-bt}u(t)$ işaretinin dönüşümü

- $X(\omega) = \int_0^\infty e^{-bt}e^{-j\omega t}\,dt = \int_0^\infty e^{-(b+j\omega)t}\,dt = \frac{1}{b+j\omega}$.
  - $b>0$ gerekir. $b<0$ olsa integral (alan) sonsuza gider ve dönüşüm alınamaz.
  - Önünde $A$ katsayısı varsa sonuç $\frac{A}{b+j\omega}$ olur.
- Genlik: $|X(\omega)| = \frac{1}{\sqrt{b^2+\omega^2}}$. $\omega=0$'da $1/b$'dir; frekans arttıkça azalır.
- Faz: $\angle X(\omega) = -\arctan(\omega/b)$.
- $b$ büyüdükçe işaret zamanda daha hızlı söner. Frekans düzleminde yüksek frekans bileşenleri artar, spektrum yayılır.
- MATLAB denemesinde `abs(fft(x))` ile genlik spektrumu çizildi. Negatif frekans tarafı da görüldü; `fftshift` ile spektrum ortalanabilir.

### Temel dönüşüm çiftleri

- $1 \leftrightarrow 2\pi\delta(\omega)$.
- $\delta(t) \leftrightarrow 1$. $\delta(t)$ yalnız $t=0$'da değer verdiği için $e^{0} = 1$ kalır.
- $u(t) \leftrightarrow \pi\delta(\omega) + \frac{1}{j\omega}$.
- $e^{j\omega_0 t} \leftrightarrow 2\pi\delta(\omega - \omega_0)$.
- $\cos\omega_0 t \leftrightarrow \pi[\delta(\omega-\omega_0) + \delta(\omega+\omega_0)]$. Tek bir frekansı olduğu için $\pm\omega_0$'da iki darbe görülür.
- $\sin\omega_0 t \leftrightarrow j\pi[\delta(\omega+\omega_0) - \delta(\omega-\omega_0)]$. Katsayılar sanaldır, biri artı biri eksidir.
- Konvolüsyon, Fourier düzleminde çarpmaya dönüşür. İki işaretin dönüşümleri çarpılır, ters dönüşüm alınır. Bu yol konvolüsyon integralinden kısadır.

### Ders sonrası notlar

- **$\pi$ ve periyodiklik:** Hoca $\cos(n/4)$'ün periyodik olmadığını doğru söyledi, ama gerekçeyi "$22/7$ tam sayı değil" diye verdi. Doğru gerekçe: $\pi$ irrasyoneldir. Bu yüzden $N = 8\pi k$ hiçbir $k$ tam sayısı için tam sayı olmaz.
- **Kare dalga sentezinde faz:** Derste bir yerde faz için "$1/\pi$'lik faz" dendi. Doğrusu: $c_1 = -j/\pi$ olduğu için genlik $|c_1| = 1/\pi$, faz $-\pi/2$'dir. Sentezde terim $\frac{2}{\pi}\cos(2\pi\,25\,t - \pi/2)$ olur.
- **Yarım dalga doğrultulmuş sinüsün $k=\pm1$ bileşenleri:** Derste "$k=\pm1$'de belirsizlik var, bileşen yok" dendi. Bu yanlıştır. Bu bileşenler en güçlü bileşenlerden biridir ve ayrıca hesaplanır.
  - $T_0 = 1$ için Python ile hesaplandı: $a_0 = 1/\pi \approx 0.318$, $a_{\pm1} = \mp j/4$, $a_2 = -1/(3\pi) \approx -0.106$, $a_4 \approx -0.021$. $a_3 = a_5 = 0$.
  - Çift $k$ için formül $a_k = \frac{-1}{\pi(k^2-1)}$'dir. Derste söylenen "$1/(k^2-1)$" ifadesinde $-1/\pi$ çarpanı eksik.
- **Gibbs olayı bir durdurma ölçütü değildir.** Derste "%90-95'i geçince bileşen eklemeyi durduran araç" gibi anlatıldı. Doğrusu: Gibbs olayı süreksizlik yanında oluşan, yaklaşık %9'luk taşmadır. Bileşen sayısı artırılsa da bu taşma kaybolmaz, yalnız süreksizliğe daha çok yaklaşır.
- **Genlik ile reel kısım farklıdır.** Derste "reel kısmı almak için mutlak değer alınır" ve "imajiner kısımdan faz bulunur" gibi ifadeler geçti. Doğrusu:
  - $|X(\omega)|$ genlik spektrumudur, reel kısım değildir.
  - $\angle X(\omega) = \arctan(\mathrm{Im}/\mathrm{Re})$ faz spektrumudur; reel ve sanal kısmın ikisi de gerekir.
- **$u(t)$'nin dönüşümü:** Derste yalnız $\frac{1}{j\omega}$ verildi. Tam dönüşüm $\pi\delta(\omega) + \frac{1}{j\omega}$'dır. $u(t)$'nin ortalama değeri $1/2$ olduğu için $\omega=0$'da darbe vardır.
- **$\cos\omega_0 t$'nin dönüşümü:** Altyazıda "$1/\omega^2$" gibi bir ifade geçiyor. Doğru sonuç $\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$'dır.
- **$\sin^3(3\pi t)$ fazları:** Altyazıda "0.125 $e^{-j0.5\pi}$" geçiyor. Slayttaki katsayılara göre 4.5 Hz bileşeni $c_3 = j/8 = 0.125e^{+j\pi/2}$'dir; $-4.5$ Hz bileşeni $0.125e^{-j\pi/2}$'dir. 1.5 Hz bileşeni $c_1 = -3j/8 = 0.375e^{-j\pi/2}$'dir.
- **MATLAB'de kosinüs çizimi:** Derste $10\cos(2\pi\,100\,t)$ adım 0.1 ile çizilince düzensiz göründü ve hoca sebebi bulamadı. Muhtemel sebep örnekleme aralığıdır. 100 Hz için $T_s = 0.1$ s çok büyüktür (Nyquist için $T_s < 0.005$ s gerekir). Bu durumda örtüşme (aliasing) olur ve sinüzoid doğru görünmez.
- Sayısal sonuçlar Python ile doğrulandı. Bunlar: $[1,1,1]*[1,1] = [1,2,2,1]$, kare dalga $c_k$ değerleri ($c_1 = -j/\pi \approx -0.318j$, $c_2 = 0$, $c_3 \approx -0.106j$), $\sin^3$ katsayıları, yarım dalga katsayıları ve EBOB(648, 672) = 24.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
