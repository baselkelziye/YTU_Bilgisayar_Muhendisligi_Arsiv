# Ders 14 Çalışma Özeti

## Genel Konular

- Dersin tarihi 4 Eylül 2021 Cumartesi (sabah oturumu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:04'te başlar. Kaydın başı bekleme kısmıdır.
  - 00:53 ile 01:04 arası ders arasıdır.
- Laplace dönüşümünde başlangıç ve son değer teoremleri (tekrar örneği)
  - $F(s)=\dfrac{2}{s(s+2)(s+4)}$ için $f(0)$ ve $f(\infty)$.
- z-dönüşümüne (z-transform) giriş
  - Neden gerekli: Laplace, Fourier dönüşümünün genelleştirilmiş hâliydi. z-dönüşümü de ayrık zamanlı Fourier dönüşümünün (DTFT) genelleştirilmiş hâlidir.
  - Tanım, $z=re^{j\omega}$ karmaşık değişkeni, z düzlemi ve birim çember.
  - Var olma şartı ve yakınsaklık bölgesi (ROC, region of convergence).
  - $a^n u[n]$ ve $a^n u[-n-1]$ işaretlerinin dönüşümleri.
- Slayt örnekleri
  - Sonlu uzunluklu işaretin z-dönüşümü: polinom gösterimi.
  - $\delta[n]$ ve $\delta[n-n_0]$ dönüşümleri, birim gecikme.
  - $0.8^n u[n]$ ve $X(z)=\dfrac{1}{z+1.2}$ örnekleri.
  - Sistem fonksiyonu $H(z)$, fark denklemi (difference equation), FIR filtre.
  - z-dönüşümüyle konvolüsyon: polinom çarpımı.
  - Seri bağlı (cascade) sistemler.
  - Sıfırlar (zeros), kutuplar (poles) ve frekans cevabına geçiş ($z=e^{j\omega}$).
  - IIR filtreye kısa bakış (sınav dışı).
- z-dönüşümünün özellikleri
  - Doğrusallık, zamanda öteleme, zamanda tersleme, konvolüsyon.
  - Zamanda fark alma, z düzleminde türev ($n$ ile çarpma).
  - Başlangıç ve son değer teoremleri.
- Fark denklemi örneği: $y[n]-\frac{1}{2}y[n-1]=x[n]$ sisteminin $H(z)$'si.
- Duyurular: öğleden sonra Quiz 4, pazartesi final.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bugünkü quizde z-dönüşümünün kullanımı doğrudan yok.
  - Sadece bir özelliği sorulacak.
- Başlangıç ve son değer teoremleri ters dönüşüm almadan sonuç verir.
  - Bunları kontrol amaçlı kullanabilirsiniz.
- z-dönüşümü, Laplace dönüşümünden daha kolaydır.
  - Ayrık zamanlı konvolüsyonun sürekliden kolay olması gibi. İşlemler çoğunlukla polinom işlemleridir.
- İndis ile genliği karıştırmayın.
  - $z^{-k}$'nın üssü zamandaki konumu ($n=k$), katsayısı ise o andaki genliği gösterir.
- Birim gecikme uygularken $n=0$ noktasını unutmayın.
  - Gecikmeden sonra $z^0$ teriminin katsayısı sıfır olabilir. Çizimde $n=0$'da sıfır gösterilmelidir.
- ROC kuralı (Laplace'taki "sağında / solunda" kuralının z karşılığı):
  - Sağ taraflı işarette ROC, en büyük kutbun tanımladığı çemberin dışıdır.
  - Sol taraflı işarette ROC, en küçük kutbun tanımladığı çemberin içidir.
- Konvolüsyon z düzleminde çarpmadır.
  - Uzun konvolüsyon hesabı yerine dönüşümleri çarpıp ters dönüşüm alın.
- IIR filtre kısmından sınavda soru gelmeyecek.
- Fark denklemi, ayrık zamandaki diferansiyel denklemdir.
  - Laplace diferansiyel denklemleri nasıl çözüyorsa, z-dönüşümü de fark denklemlerini öyle çözer.

## Kısa Tekrar Notları

- Son değer teoremi (Laplace): $\lim_{t\to\infty} f(t)=\lim_{s\to 0} sF(s)$.
- Başlangıç değer teoremi (Laplace): $\lim_{t\to 0} f(t)=\lim_{s\to\infty} sF(s)$.
- z-dönüşümü (iki taraflı): $X(z)=\sum_{n=-\infty}^{\infty} x[n]z^{-n}$, $z=re^{j\omega}$.
- $r=1$ alınırsa ($z=e^{j\omega}$) z-dönüşümü DTFT'ye indirgenir.
- Temel çiftler:
  - $\delta[n] \leftrightarrow 1$, her $z$ için.
  - $\delta[n-n_0] \leftrightarrow z^{-n_0}$.
  - $a^n u[n] \leftrightarrow \dfrac{1}{1-az^{-1}}=\dfrac{z}{z-a}$, ROC: $|z|>|a|$.
  - $a^n u[-n-1] \leftrightarrow \dfrac{z}{a-z}=-\dfrac{z}{z-a}$, ROC: $|z|<|a|$.
- Özellikler:
  - Doğrusallık: $ax_1[n]+bx_2[n] \leftrightarrow aX_1(z)+bX_2(z)$, ROC en az $R_1\cap R_2$.
  - Öteleme: $x[n-k] \leftrightarrow z^{-k}X(z)$.
  - Tersleme: $x[-n] \leftrightarrow X(z^{-1})$, ROC $1/R$.
  - Konvolüsyon: $x[n]*h[n] \leftrightarrow X(z)H(z)$.
  - Fark: $x[n]-x[n-1] \leftrightarrow (1-z^{-1})X(z)$.
  - $n$ ile çarpma: $n\,x[n] \leftrightarrow -z\dfrac{dX(z)}{dz}$.
  - Başlangıç değeri (nedensel $x[n]$): $x[0]=\lim_{z\to\infty} X(z)$.
  - Son değer: $x[\infty]=\lim_{z\to 1}(1-z^{-1})X(z)$.
- Sistem fonksiyonu: $H(z)=\dfrac{Y(z)}{X(z)}$. Frekans cevabı için $z=e^{j\omega}$ yazılır.
- Sıfırlar: $H(z)$'nin payını sıfır yapan $z$ değerleri. Kutuplar: paydayı sıfır yapan $z$ değerleri.
- Terim eşleşmesi: impuls cevabı (konvolüsyon), frekans cevabı (Fourier), transfer fonksiyonu (Laplace), sistem fonksiyonu (z).

## Detaylı Açıklamalar

### Laplace: başlangıç ve son değer teoremi örneği

- Verilen: $F(s)=\dfrac{2}{s(s+2)(s+4)}$.
- Kısmi kesirlere ayırmak için 3 katsayı gerekir. Çünkü 3 kutup vardır: $0$, $-2$, $-4$.
- Ters dönüşüm almadan $f(t)$'nin başta ve sonda nereye gittiğini bulabiliriz.
- Son değer:
  - $\lim_{s\to 0} s\cdot\dfrac{2}{s(s+2)(s+4)}=\dfrac{2}{2\cdot 4}=\dfrac{1}{4}$.
  - $s$'ler sadeleşir. $0/0$ belirsizliğiyle uğraşmaya gerek yoktur.
- Başlangıç değeri:
  - $\lim_{s\to\infty} \dfrac{2}{(s+2)(s+4)}=0$.
- Yorum: Sistem $0$'dan başlar ve zamanla $1/4$ değerine oturur. Bu, DC bileşeni olan bir sistem olabilir.
- Hocanın çalışma sorusu: $\dfrac{A}{s}+\dfrac{B}{s+2}+\dfrac{C}{s+4}$ açılımını yapın. Ters dönüşüm alıp $t=0$ ve $t\to\infty$ koyun. Aynı değerleri bulmalısınız.
  - Çözüm: $A=\frac{1}{4}$, $B=-\frac{1}{2}$, $C=\frac{1}{4}$.
  - $f(t)=\left(\frac{1}{4}-\frac{1}{2}e^{-2t}+\frac{1}{4}e^{-4t}\right)u(t)$.
  - $f(0)=\frac14-\frac12+\frac14=0$, $f(\infty)=\frac14$. Teoremlerle uyumlu.

### z-dönüşümü neden gerekli

- Periyodik işaretler için Fourier serisi, periyodik olmayanlar için Fourier dönüşümü kullanılır.
- İntegral (veya toplam) sonsuza gidiyorsa Fourier dönüşümü yapılamaz.
  - Sürekli zamanda bu sorunu Laplace dönüşümü çözdü. $\sigma$ terimi ıraksamayı bastırır.
- Ayrık zamanda DTFT vardı: $X(\omega)=\sum_n x[n]e^{-j\omega n}$.
  - Aynı ıraksama sorunu burada da vardır.
  - Çözüm z-dönüşümüdür. z-dönüşümü DTFT'nin genel hâlidir.
- Hoca, ses üretim mekanizmasının modelini ayrık zamanlı sistem örneği olarak gösterdi.
  - Ses yolu, $E(z)$, $G(z)$, $V(z)$, $R(z)$ gibi z düzleminde tanımlı alt sistemlerin çarpımıyla modellenir.
  - Konu konuşma işleme (speech processing) derslerinde detaylı işlenir.

### Tanım ve yakınsaklık şartı

- $X(z)=\sum_{n=-\infty}^{\infty} x[n]z^{-n}$.
- $z=re^{j\omega}$ yazılırsa:
  - $X(z)=\sum_n \left(x[n]r^{-n}\right)e^{-j\omega n}$.
- Dönüşümün var olması için $|X(z)|<\infty$ gerekir.
  - $|e^{-j\omega n}|=1$ olduğu için şart $\sum_n |x[n]r^{-n}|<\infty$ hâline gelir.
  - Yani ıraksamayı bastıran şey $r^{-n}$ çarpanıdır. Laplace'taki $e^{-\sigma t}$ ile aynı rolü oynar.
- $r=1$ olursa şart $\sum_n |x[n]|<\infty$ olur: işaret mutlak toplanabilir (absolutely summable) olmalıdır.

### Örnek: $x[n]=a^n u[n]$

- $X(z)=\sum_{n=0}^{\infty} a^n z^{-n}=\sum_{n=0}^{\infty}(az^{-1})^n$.
- Açılım: $1+az^{-1}+(az^{-1})^2+\dots$
- Geometrik seri formülü: $\sum_{n=0}^{\infty} q^n=\dfrac{1}{1-q}$, $|q|<1$ ise.
  - Hoca seri toplamları için bir formül kâğıdı paylaşacağını söyledi.
- Sonuç: $X(z)=\dfrac{1}{1-az^{-1}}=\dfrac{z}{z-a}$.
- Şart: $|az^{-1}|<1$, yani $|z|>|a|$.
  - ROC, z düzleminde yarıçapı $|a|$ olan çemberin dışıdır.

### Örnek: $x[n]=a^n u[-n-1]$

- $u[-n-1]$ yalnızca $n\le -1$ için 1'dir.
- $X(z)=\sum_{n=-\infty}^{-1} a^n z^{-n}$.
- Değişken değiştirme $m=-n$: $X(z)=\sum_{m=1}^{\infty}(a^{-1}z)^m$.
- $m=0$ terimi eklenip çıkarılır: $\sum_{m=0}^{\infty}(a^{-1}z)^m-1=\dfrac{1}{1-a^{-1}z}-1$.
- Sadeleştirme: $X(z)=\dfrac{z}{a-z}$.
- Şart: $|a^{-1}z|<1$, yani $|z|<|a|$.
  - ROC, yarıçapı $|a|$ olan çemberin içidir.
- Öğrenci sorusu: "Sıfırdan sonsuza mı, birden sonsuza mı bulduk?"
  - Cevap: Sıfırdan sonsuza toplamı bilinen formülle yazıp $m=0$ terimini çıkardık. Böylece birden sonsuza olan kısmı bulduk.

### Sonlu uzunluklu işaret ve gecikme

- Sonlu işaretin z-dönüşümü bir polinomdur.
  - Örnek: $x[n]=\{2,4,6,4,2\}$ ($n=0$'dan başlar) için $X(z)=2+4z^{-1}+6z^{-2}+4z^{-3}+2z^{-4}$.
- $z^{-k}$'nın üssü zamandaki konumu verir.
  - $\delta[n] \leftrightarrow 1$.
  - $\delta[n-5] \leftrightarrow z^{-5}$.
  - $\delta[n+1] \leftrightarrow z^{+1}$.
- Ters yönde de doğrudan okunur: $X(z)=1-2z^{-1}+3z^{-3}-z^{-5}$ ise $x[n]=\delta[n]-2\delta[n-1]+3\delta[n-3]-\delta[n-5]$.
- Birim gecikme: $y[n]=x[n-1]$ ise $Y(z)=z^{-1}X(z)$, yani $H(z)=z^{-1}$.
  - Örnek: $x[n]=\{3,1,4,1,5,9\}$ bir birim geciktirilirse $Y(z)=0\cdot z^0+3z^{-1}+z^{-2}+4z^{-3}+z^{-4}+5z^{-5}+9z^{-6}$ olur.
  - Gecikmeden önce $z^{+1}$ terimi varsa, gecikmeden sonra o terim $z^0$'a (yani $n=0$'a) kayar.

### Örnek: $0.8^n u[n]$

- $X(z)=1+0.8z^{-1}+0.64z^{-2}+0.512z^{-3}+\dots=\dfrac{1}{1-0.8z^{-1}}=\dfrac{z}{z-0.8}$.
- Pay ve payda $z$ ile çarpılarak ikinci biçim elde edilir.

### Örnek: $X(z)=\dfrac{1}{z+1.2}$ (slayt 14)

- Pay ve payda $z^{-1}$ ile çarpılır: $X(z)=\dfrac{z^{-1}}{1+1.2z^{-1}}$.
- $\dfrac{1}{1+1.2z^{-1}}$ terimi $(-1.2)^n u[n]$'in dönüşümüdür. $z^{-1}$ ise bir birim gecikmedir.
- Sonuç: $x[n]=(-1.2)^{n-1}u[n-1]$.
  - Değerler: $x[0]=0$, $x[1]=1$, $x[2]=-1.2$, $x[3]=1.44$, $x[4]=-1.728$, …
  - İşaret bir pozitif bir negatif değer alır.

### Sistem fonksiyonu ve FIR filtre

- $x$ giriş, $y$ çıkış, $h$ sistem için kullanılır: $h(t)$, $h[n]$, $H(\omega)$, $H(s)$, $H(z)$.
- FIR filtre: $y[n]=\sum_k b_k x[n-k]$.
  - $H(z)=\sum_k b_k z^{-k}$.
  - Örnek: $b_k=\{6,-5,1\}$ ise $H(z)=6-5z^{-1}+z^{-2}$.

### Konvolüsyon örneği (slayt 26)

- $x[n]=\{1,2,3,4\}$, FIR filtre $h[n]=\{0,1,-1,1,-1\}$ ($L=4$).
- $Y(z)=H(z)X(z)=(1+2z^{-1}+3z^{-2}+4z^{-3})(z^{-1}-z^{-2}+z^{-3}-z^{-4})$.
- Sonuç: $Y(z)=z^{-1}+z^{-2}+2z^{-3}+2z^{-4}-3z^{-5}+z^{-6}-4z^{-7}$.
- Buradan doğrudan: $y[n]=\{0,1,1,2,2,-3,1,-4\}$ ($n=0$'dan başlar).
- Bu sonuç Python ile `numpy.convolve` kullanılarak doğrulandı.

### Seri bağlı sistemler

- LTI sistemler seri bağlanınca sıra önemli değildir.
- Eşdeğer sistem: $H(z)=H_1(z)H_2(z)$.
- Örnek:
  - $v[n]=x[n]-x[n-1]$, yani $H_1(z)=1-z^{-1}$.
  - $y[n]=v[n]+v[n-1]$, yani $H_2(z)=1+z^{-1}$.
  - $H(z)=(1-z^{-1})(1+z^{-1})=1-z^{-2}$.
  - Fark denklemi: $y[n]=x[n]-x[n-2]$.

### Sıfırlar, kutuplar ve frekans cevabı

- $H(z)=\dfrac{B(z)}{A(z)}$ biçimindeyse:
  - $B(z)=0$ yapan noktalar sıfırlardır. Kutup-sıfır diyagramında "o" ile gösterilir.
  - $A(z)=0$ yapan noktalar kutuplardır. "x" ile gösterilir.
- Örnek: $H(z)=1-\frac{1}{2}z^{-1}=\dfrac{z-\frac12}{z}$.
  - Sıfır $z=\frac12$'de, kutup $z=0$'dadır.
- $z^{-1}$ kuvvetli ifadeyi $z$ ile çarpıp pozitif kuvvetlere geçmek, sıfır ve kutupları görmeyi kolaylaştırır.
- Frekans cevabı: $H(e^{j\omega})=H(z)\big|_{z=e^{j\omega}}$.
  - $\omega$ değiştikçe $e^{j\omega}$ birim çemberi dolaşır.
  - Birim çember üzerindeki bir sıfır, o frekansta genliği sıfır yapar.
- Slayt 45: $h[n]=\{1,-2,2,-1\}$ FIR filtresi.
  - $H(z)=1-2z^{-1}+2z^{-2}-z^{-3}$.
  - Sıfırlar: $z=1$ ve $z=e^{\pm j\pi/3}$. Üçü de birim çember üzerindedir.
  - Bu yüzden genlik cevabı $\omega=0$ ve $\omega=\pm\pi/3\approx\pm1.05$ rad'da sıfıra iner.

### IIR filtre (sınav dışı)

- IIR filtrede çıkış, kendi önceki değerlerine de bağlıdır (geri besleme, feedback).
- Örnek: $y[n]=0.8y[n-1]+3x[n]-2x[n-1]$.
  - MATLAB'de `filter(b, a, x)` ile hesaplanır.

```matlab
b = [3 -2];      % giriş katsayıları
a = [1 -0.8];    % çıkış (geri besleme) katsayıları
y = filter(b, a, xx);
```

- Hoca bu kısmın sinyal işleme dersinin konusu olduğunu, sınavda sorulmayacağını söyledi.

### İki terimli işaret ve ROC

- $x[n]=7\left(\frac13\right)^n u[n]-6\left(\frac12\right)^n u[n]$.
- $X(z)=\dfrac{7}{1-\frac13 z^{-1}}-\dfrac{6}{1-\frac12 z^{-1}}=\dfrac{z\left(z-\frac32\right)}{\left(z-\frac12\right)\left(z-\frac13\right)}$.
- Kutuplar: $\frac12$ ve $\frac13$.
- İki terim de sağ taraflıdır. ROC en büyük kutbun dışıdır: $|z|>\frac12$.
  - Bu ROC birim çemberi içerir.

### Özellikler: fark, türev, başlangıç ve son değer

- Zamanda fark: $x[n]-x[n-1] \leftrightarrow (1-z^{-1})X(z)$.
  - Ayrık zamanda türevin karşılığı budur.
- z düzleminde türev: $n\,x[n] \leftrightarrow -z\dfrac{dX(z)}{dz}$. ROC değişmez.
- Başlangıç değeri: nedensel $x[n]$ için ($n<0$'da $x[n]=0$) $x[0]=\lim_{z\to\infty}X(z)$.
- Son değer: $\lim_{n\to\infty}x[n]=\lim_{z\to 1}(1-z^{-1})X(z)$.

### Fark denklemi örneği

- $y[n]-\frac12 y[n-1]=x[n]$.
- z-dönüşümü: $Y(z)-\frac12 z^{-1}Y(z)=X(z)$.
- $H(z)=\dfrac{Y(z)}{X(z)}=\dfrac{1}{1-\frac12 z^{-1}}$.
  - Ters dönüşümle $h[n]=\left(\frac12\right)^n u[n]$ bulunur.
- Giriş $x[n]=\left(\frac13\right)^n u[n]$ verilirse $Y(z)=H(z)X(z)$ hesaplanır ve ters dönüşüm alınır.
  - Hoca bunu çalışma sorusu olarak bıraktı.
- Ters z-dönüşümünün tanımı kontür integralidir. Derste onun yerine tablolar, özellikler ve kısmi kesirler kullanılacak.

### Ders sonrası notlar

- Hoca $|e^{-j\omega n}|$ için "$\omega$ tam alınırsa kosinüs 1, sinüs 0 olur, ifade 1'e yaklaşır" dedi. Doğrusu: $|e^{-j\omega n}|=1$'dir, her $\omega$ ve $n$ için. Yaklaşma ya da $\omega$'nın tam sayı olması gerekmez. Bu yüzden yakınsaklık yalnızca $r$'ye bağlıdır.
- Hoca $|z|>|a|$ bölgesini anlatırken "A kadar çapta birim çember" dedi. Birim çemberin yarıçapı 1'dir. Burada kastedilen, yarıçapı $|a|$ olan çemberdir.
- Hoca $a^n u[-n-1]$ için "dönüşüm aslında aynı" dedi. Tam olarak aynı değildir:
  - $a^n u[n] \leftrightarrow \dfrac{z}{z-a}$, $|z|>|a|$.
  - $a^n u[-n-1] \leftrightarrow -\dfrac{z}{z-a}$, $|z|<|a|$.
  - Aynı ifadeyi veren çift $-a^n u[-n-1]$'dir. Ders 15'te hoca bu çifti eksi işaretiyle doğru yazdı.
- Bir öğrenci DTFT için "discrete Fourier transform" dedi. DTFT (ayrık zamanlı Fourier dönüşümü) ile DFT (ayrık Fourier dönüşümü) farklıdır. DTFT'nin çıktısı süreklidir, DFT ise sonlu sayıda frekans örneği verir.
- Slayt 45'teki sıfırları hoca "eksi 1'de, 0'da ve 1'de" diye okudu. Bunlar grafiğin yatay eksenindeki frekans değerleridir ($\omega\approx-1.05,\ 0,\ 1.05$ rad). $H(z)$'nin sıfırları ise $z=1$ ve $z=e^{\pm j\pi/3}$'tür. Python ile `numpy.roots` kullanılarak doğrulandı.
- Son değer teoremi her zaman uygulanamaz. $(1-z^{-1})X(z)$'nin bütün kutupları birim çemberin içinde olmalıdır. Laplace için de $sF(s)$'nin kutupları sol yarı düzlemde olmalıdır. Derste bu şart söylenmedi. $F(s)=\frac{2}{s(s+2)(s+4)}$ örneğinde şart sağlanır.
- Hoca $2^n u[n]$ örneğine başladı, sonra "soruyu yanlış yazmışım" deyip bıraktı. Bu işaretin dönüşümü $\dfrac{z}{z-2}$, ROC $|z|>2$'dir.
- $X(z)=\frac{1}{z+1.2}$ örneğinde işaretin genliği büyür ($|-1.2|>1$). Bu, kutbun birim çemberin dışında olmasından kaynaklanır. Nedensel bir sistemde böyle bir kutup kararsızlık demektir.
- Kontrol edilen sayısal sonuçlar (Python ile): $F(s)$ örneğinin kısmi kesirleri ve $f(0)=0$, $f(\infty)=\frac14$; slayt 26 konvolüsyonu; $\frac{1}{z+1.2}$'nin ilk değerleri; iki terimli örneğin birleşik ifadesi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
