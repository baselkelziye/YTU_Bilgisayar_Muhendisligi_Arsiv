# Ders 11 Çalışma Özeti

## Genel Konular

- Kaynak ve dersin akışı
  - Ders, Schaum serisinin Signals and Systems kitabı (Hwei P. Hsu) üzerinden işlendi: sürekli zaman için Bölüm 5, ayrık zaman için Bölüm 6 (ekrandan, 00:15:00 ve 01:25:00). Altyazıda "Xiaomi serisi" diye bozuk geçen kitap budur.
  - Kitap Laplace ve z dönüşümünü Fourier analizinden önce veriyor; derste bu kısımlar atlandı, önce işaretlerin frekans analizi bitirilecek.
  - Fourier analizinin dört biçimi (ekrandan, 01:25:00): periyodik işaretler için CTFS ve DTFS, periyodik olmayan işaretler için CTFT ve DTFT; DTFT'nin ayrıklaştırılmış hali DFT.
- Periyodik işaret ve temel frekans (ekrandan, 00:15:00)
  - $x(t+T)=x(t)$ koşulunu sağlayan en küçük pozitif $T$ temel periyot $T_0$'dır; $f_0=1/T_0$ temel frekans, $\omega_0=2\pi/T_0=2\pi f_0$ temel açısal frekanstır.
- Karmaşık üstel Fourier serisi (ekrandan, 00:15:00 ve 00:20:00)
  - $x(t)=\sum_{k=-\infty}^{\infty}c_k e^{jk\omega_0 t}$, $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0 t}\,dt$. İntegral herhangi bir periyot üzerinden alınır ($0$–$T_0$ ya da $-T_0/2$–$T_0/2$).
  - İşaret, frekansları $\omega_0$'ın tam katları olan sonsuz sayıda karmaşık sinüzoidin ağırlıklı toplamıdır; $c_k$ o frekansın işarette ne kadar bulunduğunu söyler ve karmaşık bir sayıdır.
  - $c_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$ işaretin bir periyottaki ortalamasıdır (DC bileşen).
  - Gerçel $x(t)$ için $c_{-k}=c_k^*$: genlikler eşit, fazlar ters işaretlidir.
- Trigonometrik ve harmonik biçim (ekrandan, 00:25:00)
  - $x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}(a_k\cos k\omega_0 t+b_k\sin k\omega_0 t)$, $a_k=\frac{2}{T_0}\int_{T_0}x(t)\cos k\omega_0 t\,dt$, $b_k=\frac{2}{T_0}\int_{T_0}x(t)\sin k\omega_0 t\,dt$.
  - İlişki: $\frac{a_0}{2}=c_0$, $a_k=c_k+c_{-k}$, $b_k=j(c_k-c_{-k})$; tersine $c_k=\frac12(a_k-jb_k)$, $c_{-k}=\frac12(a_k+jb_k)$.
  - Harmonik biçim yalnız kosinüs ve faz terimleriyle yazılır; ayrıntısına girilmedi.
- Sürekli zamanlı Fourier dönüşümü (CTFT) (ekrandan, 00:30:00)
  - Periyodik olmayan bir işaret, periyodu $T_0\to\infty$ giden periyodik bir işaret gibi düşünülerek elde edilir.
  - $X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}\,dt$, $x(t)=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(\omega)e^{j\omega t}\,d\omega$, gösterim $x(t)\leftrightarrow X(\omega)$.
  - $X(\omega)=|X(\omega)|e^{j\phi(\omega)}$: genlik ve faz spektrumu.
  - Küçük $\omega$ sürekli (analog) frekans, büyük $\Omega$ ayrık (sayısal) frekans için kullanılır.
- CTFT özellikleri ve bilinen çiftler (ekrandan, 00:35:00 ve 01:00:00)
  - Doğrusallık; zamanda $t_0$ öteleme frekansta $e^{-j\omega t_0}$ ile çarpım.
  - $\delta(t)\leftrightarrow 1$, $\delta(t-t_0)\leftrightarrow e^{-j\omega t_0}$, $1\leftrightarrow 2\pi\delta(\omega)$, $e^{j\omega_0 t}\leftrightarrow 2\pi\delta(\omega-\omega_0)$.
  - $\cos\omega_0 t\leftrightarrow\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$, $\sin\omega_0 t\leftrightarrow -j\pi[\delta(\omega-\omega_0)-\delta(\omega+\omega_0)]$.
- Çözümlü problemler (sürekli zaman)
  - Trigonometrik ve karmaşık seriler arasındaki ilişkinin türetilmesi (ekrandan, 00:40:00).
  - $\cos\omega_0 t$ için $c_1=c_{-1}=\frac12$; $\cos(2t+\pi/4)$ için $c_{\pm1}=\frac{\sqrt2}{4}(1\pm j)$ (ekrandan, 00:45:00).
  - Yarım periyot boyunca $A$ olan kare dalga: $c_0=A/2$, $c_{2m}=0$, $c_{2m+1}=\frac{A}{j(2m+1)\pi}$ (ekrandan, 00:55:00).
- Sayısal frekans ve örnekleme (ekrandan, 01:35:00 ve 01:40:00)
  - $t=nT_s$ konunca $\cos(2\pi f_0 t)\to\cos\left(2\pi\frac{f_0}{f_s}n\right)=\cos(\Omega_0 n)$; $\Omega_0=\omega_0/f_s=\omega_0 T_s$.
  - Nyquist: $f_s\ge 2f_{max}$. $f_s=2f_{max}$ iken en yüksek bileşen $\Omega=\pi$'ye düşer; $f_s/2$ her zaman $\Omega=\pi$'ye karşılık gelir.
  - $e^{j(\Omega_0+2\pi k)n}=e^{j\Omega_0 n}$: ayrık frekanslar $2\pi$ ile periyodiktir, sürekli frekans ise sonsuza kadar gidebilir.
  - Zamanda örnekleme, frekans içeriğini $2\pi$ aralıklarla tekrarlanan (periyodik) hale getirir.
- Ayrık zamanlı Fourier serisi (DTFS) (ekrandan, 01:25:00 ve 01:45:00)
  - $x[n+N]=x[n]$; en küçük pozitif tam sayı $N_0$ temel periyottur, $\Omega_0=2\pi/N_0$.
  - $x[n]=\sum_{k=0}^{N_0-1}c_k e^{jk\Omega_0 n}$, $c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]e^{-jk\Omega_0 n}$.
  - Katsayılar sonsuza gitmez: $c_{k+N_0}=c_k$, yalnız $N_0$ tane farklı katsayı vardır.
- Ayrık zamanlı Fourier dönüşümü (DTFT) (ekrandan, 01:50:00 ve 01:55:00)
  - Sonlu, periyodik olmayan $x[n]$ periyodik olarak genişletilir, $N_0\to\infty$ götürülür.
  - $X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]e^{-j\Omega n}$, $x[n]=\frac{1}{2\pi}\int_{2\pi}X(\Omega)e^{j\Omega n}\,d\Omega$.
  - $X(\Omega)$ sürekli, $2\pi$ ile periyodik ve karmaşıktır; gerçel $x[n]$ için $X(-\Omega)=X^*(\Omega)$, yani genlik simetrik, faz ters işaretlidir. $[-\pi,\pi]$ ya da $[0,2\pi]$ aralığında incelenir; $[0,\pi]$ pozitif frekanslardır, $\pi$ en yüksek frekanstır.
- DTFT özellikleri (ekrandan, 02:10:00)
  - Doğrusallık; $x[n-n_0]\leftrightarrow e^{-j\Omega n_0}X(\Omega)$; frekans öteleme $e^{j\Omega_0 n}x[n]\leftrightarrow X(\Omega-\Omega_0)$; eşlenik $x^*[n]\leftrightarrow X^*(-\Omega)$; zamanda ters çevirme $x[-n]\leftrightarrow X(-\Omega)$.
  - Zamanda konvolüsyon frekansta çarpımdır; zamanda çarpım frekansta (periyodik) konvolüsyondur.
  - $\delta[n]\leftrightarrow 1$, $\delta[n-n_0]\leftrightarrow e^{-j\Omega n_0}$; sabit işaretin DTFT'si $[-\pi,\pi]$ içinde $\Omega=0$'da alanı $2\pi$ olan bir dürtüdür.
- Ayrık Fourier dönüşümü (DFT) (ekrandan, 02:15:00 ve 02:20:00)
  - DTFT'nin çıktısı sürekli olduğu için bilgisayarda saklanamaz; frekansın da örneklenmesi gerekir.
  - $N$ uzunluklu $x[n]$ için $2\pi$ aralığı $N$ parçaya bölünür: $X[k]=X(\Omega)\big|_{\Omega=2\pi k/N}=\sum_{n=0}^{N-1}x[n]W_N^{kn}$, $W_N=e^{-j2\pi/N}$, $k=0,\dots,N-1$.
  - Ters DFT: $x[n]=\frac1N\sum_{k=0}^{N-1}X[k]W_N^{-kn}$. Örnek sayısı ile frekans örneği sayısı aynıdır; ayrıntısı Sayısal İşaret İşleme dersine bırakıldı.
- Çözümlü problemler (ayrık zaman)
  - $N_0=4$ periyotlu dizinin DTFS katsayıları (derste $c_0=3/2$ bulundu).
  - $x[n]=\cos(\pi n/4)$: $N_0=8$, $c_1=c_{-1}=c_7=\frac12$, diğerleri sıfır.
  - Dikdörtgen spektrumun ters DTFT'si: $x[n]=\frac{\sin Wn}{\pi n}$; $W=\pi/4$ için $x[0]=1/4$ (ekrandan, 02:30:00 ve 02:35:00).
  - MATLAB ile bu dizinin $n=-15..15$ için `stem` ile çizimi (ekrandan, 02:40:00).
  - Zaman ölçekleme: 5 örnekli dikdörtgen dizi araya sıfır konarak yayıldığında DTFT $X(2\Omega)$, $X(3\Omega)$ olur, yani frekansta sıkışır ve $[-\pi,\pi]$ içinde birden çok kopya görünür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dual çiftler
  - $x(t)$ ile $c_k$, $x(t)$ ile $X(\omega)$, $x[n]$ ile $X(\Omega)$ birbirinin dönüşüm çiftidir ve birlikte bilinmelidir.
- $c_0$ ve $a_0$ ayrıca hesaplanmalı
  - Kare dalga örneğinde $c_k=0$ ($k$ çift) sonucu $k=0$'ı kapsamaz; $c_0=A/2$'dir. $c_0$'ı ve trigonometrik seride $a_0$'ı daima ayrıca bulun.
- Sürekli ve ayrık frekans farkı
  - Sürekli frekans sınırsızdır; ayrık frekans $2\pi$ ile periyodiktir ve ulaşılabilecek en büyük değer $\pi$'dir. Hoca bunu "çok önemli fark" diye altını çizerek verdi.
- $e^{j\theta}$ değerlerinin hızlı bulunması
  - $e^{j0}=1$, $e^{\pm j\pi}=-1$, $e^{j\pi/2}=j$, $e^{-j\pi/2}=-j$; $e^{-jk\pi}=(-1)^k$.
- Temel işaretlerin çizimi
  - $\delta[n]$, $\delta[n-1]$, $u[n]$, $u[-n]$, $u[n-n_0]$ gibi işaretlerle tanımlanan $x[n]$ ve $x(t)$'yi çizebilmek gerekir.
- Konvolüsyon ve çarpma
  - Zamanda uzun sürecek konvolüsyon yerine frekansta çarpma yapılıp ters dönüşüm alınabilir.
- Çözümlü sorular
  - Kitabın çözümlü problemleri (farklı periyodik işaretlerin $c_k$, $a_k$, $b_k$ katsayıları, $x(t)\to X(\omega)$ integralleri) mutlaka çalışılmalı.

## Kısa Tekrar Notları

- $\omega_0=2\pi/T_0$, $\Omega_0=2\pi/N_0$, $\Omega=\omega/f_s$.
- CTFS: $c_k=\frac1{T_0}\int_{T_0}x(t)e^{-jk\omega_0t}dt$; DTFS: $c_k=\frac1{N_0}\sum_{n=0}^{N_0-1}x[n]e^{-jk\Omega_0n}$, $c_{k+N_0}=c_k$.
- $c_0=a_0/2$ = ortalama; $a_k=c_k+c_{-k}$, $b_k=j(c_k-c_{-k})$; gerçel işaret için $c_{-k}=c_k^*$.
- CTFT: $X(\omega)=\int x(t)e^{-j\omega t}dt$, ters: $\frac1{2\pi}\int X(\omega)e^{j\omega t}d\omega$.
- DTFT: $X(\Omega)=\sum x[n]e^{-j\Omega n}$, ters: $\frac1{2\pi}\int_{2\pi}X(\Omega)e^{j\Omega n}d\Omega$; $X(\Omega)$ sürekli ve $2\pi$ periyodik.
- DFT: $X[k]=\sum_{n=0}^{N-1}x[n]e^{-j2\pi kn/N}$, DTFT'nin $\Omega=2\pi k/N$ noktalarındaki örnekleri.
- $1\leftrightarrow2\pi\delta(\omega)$, $\delta(t)\leftrightarrow1$, $\cos\omega_0t\leftrightarrow\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$.
- $f_s\ge2f_{max}$; $f_s/2\leftrightarrow\Omega=\pi$.
- $\frac{\sin Wn}{\pi n}\leftrightarrow$ $|\Omega|\le W$'de 1 olan dikdörtgen spektrum; $n=0$'da değer $W/\pi$.

## Detaylı Açıklamalar

Fourier analizinin çıkış noktası periyodik işaretlerdir. Periyodu $T_0$ olan bir işaret, frekansları $k\omega_0$ olan karmaşık üstellerin toplamı olarak yazılır. $k$ arttıkça frekans yükselir; $c_k$ katsayısı her frekansın işaretteki payını verir. $k=0$ terimi frekansı sıfır olan, yani sabit (DC) bileşendir ve işaretin bir periyottaki ortalamasına eşittir. Trigonometrik seri aynı açılımın Euler formülü $e^{jx}=\cos x+j\sin x$ kullanılarak kosinüs ve sinüslerle yazılmış halidir. Karmaşık seride $k$ pozitif ve negatif diye ikiye ayrılıp $c_0$ dışarı alınınca $x(t)=c_0+\sum_{k=1}^{\infty}[(c_k+c_{-k})\cos k\omega_0t+j(c_k-c_{-k})\sin k\omega_0t]$ elde edilir; buradan $c_0=a_0/2$, $a_k=c_k+c_{-k}$, $b_k=j(c_k-c_{-k})$ çıkar (ekrandan, 00:40:00). Bir öğrencinin sorusu üzerine, trigonometrik serinin başındaki terimin $a_0/2$ olması gerektiği bu türetmeyle gösterildi.

Basit sinüzoidlerin katsayıları integral almadan, Euler açılımıyla bulunur. $\cos\omega_0t=\frac12e^{j\omega_0t}+\frac12e^{-j\omega_0t}$ olduğu için $c_1=c_{-1}=\frac12$, diğer bütün $c_k$ sıfırdır. $\cos(2t+\pi/4)$ için $\omega_0=2$ ve $\cos(2t+\pi/4)=\frac12e^{j\pi/4}e^{j2t}+\frac12e^{-j\pi/4}e^{-j2t}$ yazılır; $e^{j\pi/4}=\frac{1+j}{\sqrt2}$ olduğundan $c_1=\frac{\sqrt2}{4}(1+j)$, $c_{-1}=\frac{\sqrt2}{4}(1-j)$ olur (ekrandan, 00:45:00). $\cos4t+\sin6t$ gibi iki frekanslı bir işarette temel açısal frekans iki frekansın ortak böleni olan $\omega_0=2$, temel periyot $T_0=\pi$'dir (ekrandan, 00:45:00).

Genel bir periyodik işarette katsayılar integralle bulunur. Yarım periyot boyunca $A$, diğer yarıda sıfır olan kare dalgada $c_k=\frac{1}{T_0}\int_0^{T_0/2}Ae^{-jk\omega_0t}dt=\frac{A}{jk2\pi}(1-e^{-jk\pi})$ çıkar. $e^{-jk\pi}=(-1)^k$ olduğundan çift $k$ için $c_k=0$, tek $k$ için $c_k=\frac{A}{jk\pi}$ olur. $k=0$'da bu ifade belirsizdir; $c_0$ ayrıca hesaplanır ve $A/2$ bulunur (ekrandan, 00:55:00).

Periyodik olmayan bir işaretin frekans içeriği için periyot sonsuza götürülür; komşu kopyalar uzaklaşır ve yalnız merkezdeki işaret kalır. Bu limit Fourier dönüşümünü verir. Dürtünün dönüşümü 1'dir: bütün frekanslar eşit miktarda toplanırsa dürtü oluşur. Sabit işaretin dönüşümü $\omega=0$'da alanı $2\pi$ olan bir dürtüdür; yalnız DC bileşen vardır. Kosinüs ise $\pm\omega_0$'da alanı $\pi$ olan iki dürtüden oluşur. Negatif frekanslar fiziksel değil, matematiksel gösterimin sonucudur; gerçel işaretlerde pozitif taraf yorum için yeterlidir.

Ayrık zamana geçerken $t$ yerine $nT_s$ konur. Derste beş kosinüslü bir işaret ($5600$, $8400$, $11200$, $16800$, $25200$ Hz) $f_s=50400$ Hz ile örneklendi; sayısal frekanslar $2\pi/9$, $\pi/3$, $4\pi/9$, $2\pi/3$ ve $\pi$ çıktı (ekrandan, 01:35:00 ve 01:40:00). En yüksek bileşen tam $\pi$'ye düştü; $f_s=100800$ Hz seçilseydi $\pi/2$'ye düşecekti. Ayrık frekans $2\pi$ ile periyodik olduğu için ayrık zamanda katsayı sayısı da periyotla sınırlıdır: DTFS'de yalnız $N_0$ tane farklı katsayı vardır.

DTFT, sonlu bir dizinin periyodik genişletmesinden $N_0\to\infty$ limitiyle çıkar. Girişi ayrık, çıktısı sürekli ve $2\pi$ periyodiktir; ters dönüşüm bu yüzden integralle, ileri dönüşüm toplamla yazılır. Bilgisayarda sürekli $X(\Omega)$ saklanamayacağı için $N$ örnekli bir dizide $2\pi$ aralığı $N$ eşit parçaya bölünür ve DFT elde edilir.

Ayrık zamandaki son örnekte $|\Omega|\le W$ için 1 olan spektrumun ters DTFT'si alındı: $x[n]=\frac1{2\pi}\int_{-W}^{W}e^{j\Omega n}d\Omega=\frac{e^{jWn}-e^{-jWn}}{2\pi jn}=\frac{\sin Wn}{\pi n}$. $n=0$'daki $0/0$ belirsizliği L'Hospital kuralıyla giderilir ve $x[0]=W/\pi$ olur; $W=\pi/4$ için $1/4$ (ekrandan, 02:35:00). Bu dizinin farklı $W$ değerleri için MATLAB'de `stem` ile çizilmesi istendi (ekrandan, 02:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
