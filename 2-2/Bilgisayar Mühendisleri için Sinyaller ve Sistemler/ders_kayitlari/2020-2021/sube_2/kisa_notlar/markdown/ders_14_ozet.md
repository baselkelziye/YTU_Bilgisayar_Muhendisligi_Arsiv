# Ders 14 Çalışma Özeti

## Genel Konular

- Ayrık zamanlı Fourier dönüşümünde $1/2\pi$ katsayısının yeri (derste sözlü, 00:08:14-00:13:18)
  - Ders notlarında ve kitapta DTFT analiz denklemi $X(\Omega)=\sum_{n}x[n]e^{-j\Omega n}$ biçimindedir; $\frac{1}{2\pi}$ katsayısı sentez (ters dönüşüm) denkleminde yer alır.
  - Bazı kaynaklar bu katsayıyı farklı yere koyar. Hoca bunun bir normalizasyon tercihi olduğunu, integral ya da toplam sınırları değişince katsayının yerinin de değişebileceğini söyledi. Katsayının yeri genlik değerlerini $1/2\pi$ oranında değiştirir.
- Laplace dönüşümünün tekrarı (ekrandan, 00:15:00-00:39:00)
  - Fourier dönüşümü, mutlak integrallenebilir olmayan (enerjisi ya da gücü sonsuza giden) işaretlerde çalışmaz. Çekirdekteki $e^{-j\omega t}$ yerine $e^{-(\sigma+j\omega)t}=e^{-st}$ konur; $e^{-\sigma t}$ çarpanı işareti bastırır ve integrali sonlu yapar.
  - İki taraflı ($-\infty..\infty$) ve tek taraflı ($0^-..\infty$) Laplace dönüşümü vardır. Tek taraflı dönüşüm başlangıç koşullarını (ör. anahtar kapanmadan önceki devre yükü) hesaba katar.
  - $e^{-bt}u(t)$ için integralin yakınsaması $\sigma+b>0$, yani $\sigma>-b$ koşulunu verir. Bu bölge yakınsama bölgesidir (ROC). ROC $j\omega$ eksenini içeriyorsa Fourier dönüşümü de vardır.
  - Paydayı sıfırlayan değerler kutup (×), payı sıfırlayan değerler sıfırdır (o). Bunlar sıfır-kutup diyagramında gösterilir.
  - Özellikler: doğrusallık, zamanda öteleme $x(t-c)\leftrightarrow e^{-cs}X(s)$, türev $\leftrightarrow sX(s)$, integral $\leftrightarrow X(s)/s$, zamanda ölçekleme $x(at)\leftrightarrow\frac{1}{a}X(s/a)$, $t^nx(t)\leftrightarrow(-1)^n\frac{d^nX(s)}{ds^n}$, üstel ile çarpma $\leftrightarrow$ $s$ düzleminde kayma, sinüzoitle çarpma (modülasyon), konvolüsyon $\leftrightarrow$ çarpım.
  - Tek taraflı dönüşümde türev: $y'(t)\leftrightarrow sY(s)-y(0^-)$, $y''(t)\leftrightarrow s^2Y(s)-sy(0^-)-y'(0^-)$.
  - Transfer fonksiyonu $H(s)=Y(s)/X(s)$ Laplace dönüşümünde, frekans cevabı Fourier dönüşümünde kullanılan terimdir.
  - RC devresi örneği: birinci mertebe diferansiyel denklem Laplace ile cebirsel denkleme dönüşür, basit kesirlere ayrılır ve ters dönüşümle $y(t)$ bulunur (ekrandan, 00:25:00-00:30:00).
  - Sıfır giriş ve sıfır durum cevabı: $Y(s)=\frac{IC(s)}{A(s)}+\frac{E(s)}{A(s)}+\frac{F(s)}{D_X(s)}$. İlk iki terim geçici (transient), son terim kalıcı durum (steady-state) cevabıdır (ekrandan, 00:30:00).
  - Basit kesirlere ayırma: tekrarlı kutup yoksa $G(s)=\frac{K_1}{s-p_1}+\dots+\frac{K_N}{s-p_N}$ (ekrandan, 00:35:00).
  - MATLAB'da transfer fonksiyonu pay ve payda katsayıları en yüksek dereceden başlayarak verilir; eksik dereceye 0 yazılır. Sıfırlar, kutuplar ve sıfır-kutup çizimi hazır komutlarla bulunur.
- z-dönüşümünün tanımı (ekrandan, 00:45:00)
  - $X(z)=\sum_{n=-\infty}^{\infty}x[n]z^{-n}$ (iki taraflı, bilateral). $n=0$'dan başlarsa tek taraflıdır (unilateral).
  - $z=re^{j\Omega}$ karmaşık bir sayıdır. Karmaşık sayı $a+bj$ için $r=\sqrt{a^2+b^2}$, $\theta=\arctan(b/a)$, $z=r(\cos\theta+j\sin\theta)=r\,e^{j\theta}$. Laplace'taki $s=\sigma+j\omega$'nın ayrık zamandaki karşılığıdır.
  - Geometrik seri: $\sum_{n=0}^{\infty}r^n=\frac{1}{1-r}$, ancak $|r|<1$ ise. $|r|>1$ ise seri ıraksar.
- z-dönüşümünün varlığı (ekrandan, 00:55:00)
  - $\sum_n|x[n]r^{-n}|<\infty$ olmalıdır. $r=1$ alınırsa DTFT elde edilir ve koşul mutlak toplanabilirlik (absolutely summable) olur.
- Temel örnekler ve ROC (ekrandan, 00:55:00-01:05:00, 01:35:00)
  - $a^nu[n]\leftrightarrow\frac{1}{1-az^{-1}}=\frac{z}{z-a}$, ROC $|z|>|a|$.
  - $-a^nu[-n-1]\leftrightarrow\frac{z}{z-a}$, ROC $|z|<|a|$. İfade aynı, ROC farklıdır.
  - $2^nu[n]$: ROC $|z|>2$.
  - Sonlu dizi $\{1,2,3,4\}$ ($n=0..3$): $X(z)=1+2z^{-1}+3z^{-2}+4z^{-3}$. Her katsayı doğrudan $z^{-n}$ ile yazılır.
  - $\delta[n]\leftrightarrow1$, $5\delta[n-3]\leftrightarrow5z^{-3}$, $3\delta[n+2]\leftrightarrow3z^{2}$.
- ROC kuralları, kararlılık ve nedensellik (ekrandan, 01:35:00)
  - Sağ yanlı dizide ROC en büyük kutbun tanımladığı çemberin dışındadır. Sol yanlı dizide ROC en küçük kutbun tanımladığı çemberin içindedir.
  - ROC birim çemberi içeriyorsa DTFT vardır ve sistem kararlıdır.
  - Sağ yanlı sistemler nedenseldir. Nedensel bir sistemin bütün kutupları birim çemberin içindeyse sistem BIBO kararlıdır.
  - Örnek: $x[n]=7(1/3)^nu[n]-6(1/2)^nu[n]$, $X(z)=\frac{z(z-3/2)}{(z-1/2)(z-1/3)}$, kutuplar $1/3$ ve $1/2$, ROC $|z|>1/2$; kutuplar birim çemberin içinde olduğundan kararlıdır (ekrandan, 01:45:00).
- z-dönüşümünün özellikleri (ekrandan, 01:55:00-02:05:00)
  - Doğrusallık: $ax_1[n]+bx_2[n]\leftrightarrow aX_1(z)+bX_2(z)$, ROC en az $R_1\cap R_2$'yi içerir.
  - Zamanda öteleme: $x[n-n_0]\leftrightarrow z^{-n_0}X(z)$, ROC aynı kalır (0 ya da $\infty$ noktası hariç olabilir). $z^{-1}$ birim geciktirme operatörüdür.
  - Zamanda ölçekleme (genişletme): $x[n/a]\leftrightarrow X(z^a)$, ROC $R^{1/a}$.
  - Zamanda ters çevirme: $x[-n]\leftrightarrow X(z^{-1})$, ROC $1/R$.
  - Konvolüsyon: $x[n]*y[n]\leftrightarrow X(z)Y(z)$.
  - $z$'de türev: $n\,x[n]\leftrightarrow-z\frac{dX(z)}{dz}$, ROC aynı.
  - İlk değer: $x[0]=\lim_{z\to\infty}X(z)$. Son değer: $x[\infty]=\lim_{z\to1}(1-z^{-1})X(z)$.
- Ayrık zamanda türev ve fark (derste sözlü, 01:16:07-01:18:44, 01:56:28-01:57:59)
  - Sürekli zamanda türev $\frac{f(t+h)-f(t)}{h}$, $h\to0$. Ayrık zamanda en küçük adım 1 olduğundan türev $x[n]-x[n-1]$ farkıdır. Sürekli zamanda "diferansiyel", ayrık zamanda "fark (difference)" denir.
  - $3,4,5,6$ dizisinin farkı $1,1,1$; $2,6,8,12$ dizisinin farkı $4,2,4$'tür. Fark, değişim hakkında bilgi verir ve sonraki değeri tahmin etmekte kullanılabilir.
- z-dönüşüm tablosu (ekrandan, 02:15:00-02:20:00)
  - $\delta[n]\leftrightarrow1$, tüm $z$. $u[n]\leftrightarrow\frac{1}{1-z^{-1}}=\frac{z}{z-1}$, $|z|>1$. $\delta[n-m]\leftrightarrow z^{-m}$, tüm $z$ ($m>0$ ise 0 hariç, $m<0$ ise $\infty$ hariç).
  - $a^nu[n]\leftrightarrow\frac{1}{1-az^{-1}}$, $|z|>|a|$. $na^nu[n]\leftrightarrow\frac{az^{-1}}{(1-az^{-1})^2}$, $|z|>|a|$.
  - $\cos(\Omega_0n)u[n]\leftrightarrow\frac{1-\cos\Omega_0\,z^{-1}}{1-2\cos\Omega_0\,z^{-1}+z^{-2}}$, $\sin(\Omega_0n)u[n]\leftrightarrow\frac{\sin\Omega_0\,z^{-1}}{1-2\cos\Omega_0\,z^{-1}+z^{-2}}$.
- Ters z-dönüşümü (ekrandan, 02:20:00-02:25:00, 02:50:00)
  - Tanımdaki kontur integrali pratikte kullanılmaz; tablo, özellikler ve basit kesirlere ayırma kullanılır.
  - $X(z)=\frac{3-\frac56z^{-1}}{(1-\frac14z^{-1})(1-\frac13z^{-1})}$, $|z|>1/3$: $A=1$, $B=2$, $x[n]=(1/4)^nu[n]+2(1/3)^nu[n]$.
  - Ötelemeli terimler: $\frac{z^{-4}}{z-1}=z^{-5}\frac{z}{z-1}\to u[n-5]$; $z^{-6}\to\delta[n-6]$; $\frac{z^{-3}}{z+0.5}=z^{-4}\frac{z}{z+0.5}\to(-0.5)^{n-4}u[n-4]$.
- Fark denklemi ve transfer fonksiyonu (ekrandan, 02:40:00)
  - $y[n]-\frac12y[n-1]=x[n]+\frac13x[n-1]$ $\Rightarrow$ $H(z)=\frac{1+\frac13z^{-1}}{1-\frac12z^{-1}}$, $h[n]=(1/2)^nu[n]+\frac13(1/2)^{n-1}u[n-1]$.
  - Ayrık zamandaki birim gecikme ($z^{-1}$), sürekli zamandaki türevin ($s$) karşılığı gibi kullanılır. Fark denklemleri ayrık matematikteki özyinelemeli bağıntılara (recurrence relation) benzer.
  - DTFT ile çözülen bir kitap örneğinde $e^{-j\Omega}$ yerine $z^{-1}$ yazılırsa aynı sonuç z-dönüşümüyle bulunur (ekrandan, 02:45:00).
- z-dönüşümüyle konvolüsyon (ekrandan, 03:00:00)
  - $X(z)=z^{-1}+2z^{-2}$, $Y(z)=1+z^{-3}$: çarpım $z^{-1}+2z^{-2}+z^{-4}+2z^{-5}$, yani $\delta[n-1]+2\delta[n-2]+\delta[n-4]+2\delta[n-5]$. Doğrudan konvolüsyon da aynı sonucu verir.
- Sistem modelleme ve uygulamalar (ekrandan, 02:25:00-02:35:00, 03:05:00-03:15:00)
  - Kontrol sistemleri geri beslemelidir; blok diyagramlar $s$ cinsinden yazılır ve transfer fonksiyonundan kararlılık, sıfır ve kutuplar incelenir. Çıkışın hedeften farkı (hata) geri beslenir; aynı fikir yapay sinir ağlarında hata hesabında görülür.
  - Ses üretimi (ses yolu) ayrık zamanlı bir sistemle modellenir; transfer fonksiyonu $z$ cinsindendir. Doğrusal öngörülü kodlama (LPC) katsayıları sesi ayırt eden özellikler olarak kullanılır.
  - Ardışık (kaskat) LTI sistemlerde $H(z)=H_1(z)H_2(z)$. Frekans cevabı $H(e^{j\Omega})=H(z)\big|_{z=e^{j\Omega}}$.
  - Filtreleme konvolüsyondur. Örnekler: çalışan toplam (running sum), istenmeyen frekansı sıfırlayan nulling filtre, gürültüyü azaltan çalışan ortalama; görüntüde tuz-biber gürültüsü ortalama ya da medyan filtreyle temizlenir.
- Laplace örnekleri (ekrandan, 03:25:00-03:55:00)
  - $X(s)=\frac{2s+4}{s^2+4s+3}=\frac{1}{s+1}+\frac{1}{s+3}$; üç farklı ROC için üç farklı işaret.
  - Birim basamak cevabı $y(t)=2e^{-3t}u(t)$ olan sistem: $H(s)=\frac{2s}{s+3}$, $h(t)=2\delta(t)-6e^{-3t}u(t)$.
  - $y''+5y'+6y=x(t)$, $y(0)=2$, $y'(0)=1$, $x(t)=e^{-t}u(t)$: $y(t)=\left(\tfrac12e^{-t}+6e^{-2t}-\tfrac92e^{-3t}\right)u(t)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- İşaret işleme bakışında sonuçlara $u(t)$ ya da $u[n]$ eklenir
  - Bulunan ifadeler sıradan matematiksel fonksiyon değil işarettir; sağ yanlı sonuçların yanına mutlaka birim basamak yazılır.
- Aynı cebirsel ifade, farklı ROC ile farklı işarete karşılık gelir
  - $\frac{z}{z-a}$ hem $a^nu[n]$ ($|z|>|a|$) hem $-a^nu[-n-1]$ ($|z|<|a|$) olabilir. ROC sağ yanlı ve sol yanlı işareti ayırt ettirir; ROC verilmeden ters dönüşüm tek değildir.
- Kararlılık z düzleminde kolay görülür
  - Zaman düzleminde BIBO kararlılığı görmek zor olabilir; z-dönüşümünde kutuplara (nedensel sistemde) ya da ROC'nin birim çemberi içerip içermediğine bakmak yeterlidir.
- Konvolüsyon yerine çarpım
  - z-dönüşümü ve Laplace dönüşümü, zaman düzlemindeki konvolüsyonu çarpıma çevirir. Çarparken polinom çarpımında hata yapmamak yeterlidir.
- Ters dönüşümde integral kullanılmaz
  - Tablo, özellikler ve basit kesirlere ayırma yeterlidir. Kökü yerine koyma yöntemi katsayıları hızlı verir.
- $t=10$ anındaki değer sorulursa $\delta(10)=0$'dır
  - $h(t)=2\delta(t)-6e^{-3t}u(t)$ için $t=10$'da $\delta$ terimi sıfırdır; öğrencilerin sık yaptığı hata $\delta(10)$'u 1 almaktır.
- Tek taraflı Laplace'ta başlangıç koşulları
  - Başlangıç koşulları verilmişse tek taraflı dönüşüm kullanılır. Türev kuralındaki $s$ ile denklemdeki sabit katsayı karıştırılmamalıdır.
- Asıl iş denklemi kurmak
  - İntegral ve dönüşüm hesaplarını MATLAB gibi araçlar yapabilir; mühendisin asıl işi sistemi doğru temsil eden denklemi kurmaktır.

## Kısa Tekrar Notları

- $X(z)=\sum x[n]z^{-n}$, $z=re^{j\Omega}$; $r=1$ (birim çember) DTFT'yi verir.
- $\sum_{n\ge0}r^n=\frac{1}{1-r}$, $|r|<1$.
- $a^nu[n]\leftrightarrow\frac{z}{z-a}$, $|z|>|a|$; $-a^nu[-n-1]\leftrightarrow\frac{z}{z-a}$, $|z|<|a|$.
- $\delta[n]\leftrightarrow1$; $\delta[n-m]\leftrightarrow z^{-m}$; $u[n]\leftrightarrow\frac{z}{z-1}$, $|z|>1$.
- $na^nu[n]\leftrightarrow\frac{az^{-1}}{(1-az^{-1})^2}$.
- Sağ yanlı: ROC en büyük kutbun dışında. Sol yanlı: ROC en küçük kutbun içinde.
- ROC birim çemberi içerirse DTFT var ve sistem kararlı. Nedensel sistemde tüm kutuplar birim çemberin içindeyse kararlı.
- $x[n-n_0]\leftrightarrow z^{-n_0}X(z)$; $x[-n]\leftrightarrow X(z^{-1})$; $nx[n]\leftrightarrow-z\,dX/dz$; konvolüsyon $\leftrightarrow$ çarpım.
- İlk değer $x[0]=\lim_{z\to\infty}X(z)$; son değer $\lim_{z\to1}(1-z^{-1})X(z)$.
- Fark denkleminde $y[n-1]\to z^{-1}Y(z)$; $H(z)=Y(z)/X(z)$; $h[n]$ ters dönüşümle bulunur.
- Laplace: $y'\to sY-y(0^-)$, $y''\to s^2Y-sy(0^-)-y'(0^-)$.

## Detaylı Açıklamalar

- Laplace'tan z-dönüşümüne geçiş
  - Laplace dönüşümü, Fourier dönüşümünün çekirdeğine $e^{-\sigma t}$ bastırma çarpanı ekleyerek yakınsamayan işaretleri analiz edilebilir hale getirir. Ayrık zamanda DTFT'nin aynı sorununu z-dönüşümü çözer: $e^{-j\Omega n}$ yerine $z^{-n}=r^{-n}e^{-j\Omega n}$ konur. $r^{-n}$ çarpanı Laplace'taki $e^{-\sigma t}$'nin rolünü oynar. $|e^{-j\Omega n}|=1$ olduğundan yakınsama yalnız $r$'ye bağlıdır; bu yüzden ROC z düzleminde merkezi orijin olan çemberlerle sınırlanır.
  - Laplace'ta ROC $j\omega$ eksenini içeriyorsa Fourier dönüşümü vardı; z-dönüşümünde bunun karşılığı ROC'nin birim çemberi ($|z|=1$) içermesidir.
- ROC'nin bulunması
  - $a^nu[n]$ için $X(z)=\sum_{n=0}^{\infty}(az^{-1})^n$ geometrik seridir ve yalnız $|az^{-1}|<1$, yani $|z|>|a|$ iken $\frac{1}{1-az^{-1}}$'e yakınsar. $2^nu[n]$'de $|2r^{-1}|<1\Rightarrow r>2$ olur; ROC yarıçapı 2 olan çemberin dışıdır.
  - $a^nu[-n-1]$'de toplam $n=-\infty..-1$ aralığındadır. Değişken değiştirilerek $\sum_{n=1}^{\infty}(a^{-1}z)^n=\frac{1}{1-a^{-1}z}-1=\frac{z}{a-z}$ bulunur; koşul $|z|<|a|$'dır. Başına eksi konursa $\frac{z}{z-a}$ elde edilir.
- İki kutuplu örnek
  - $x[n]=7(1/3)^nu[n]-6(1/2)^nu[n]$ doğrusallıkla iki ayrı dönüşümün farkıdır. Paydalar eşitlenince $X(z)=\frac{z(z-3/2)}{(z-1/2)(z-1/3)}$ çıkar: sıfırlar $0$ ve $3/2$, kutuplar $1/3$ ve $1/2$. İşaret sağ yanlı olduğundan ROC en büyük kutbun ($1/2$) dışıdır. Kutupların ikisi de birim çemberin içinde olduğundan sistem kararlıdır; ROC birim çemberi de içerir.
- Delta ve öteleme
  - $\delta[n]$ yalnız $n=0$'da 1 olduğundan toplamda tek terim kalır: $\delta[0]z^{0}=1$. $5\delta[n-3]$'te yalnız $n=3$ terimi kalır: $5z^{-3}$. $3\delta[n+2]$'de yalnız $n=-2$ terimi kalır: $3z^{2}$. Bir işareti $\delta[n-3]$ ile konvolüsyona sokmak onu 3 birim geciktirir; z düzleminde bu $z^{-3}$ ile çarpmaktır.
- Basit kesirlere ayırma
  - $X(z)=\frac{3-\frac56z^{-1}}{(1-\frac14z^{-1})(1-\frac13z^{-1})}=\frac{A}{1-\frac14z^{-1}}+\frac{B}{1-\frac13z^{-1}}$. Paydalar eşitlenir; $z^{-1}=4$ konunca $B$'li terim sıfırlanır: $A(1-\frac43)=3-\frac{20}{6}\Rightarrow A=1$. $z^{-1}=3$ konunca $A$'lı terim sıfırlanır: $B(1-\frac34)=3-\frac52\Rightarrow B=2$. ROC $|z|>1/3$ sağ yanlı işareti gösterir: $x[n]=(1/4)^nu[n]+2(1/3)^nu[n]$.
- Fark denkleminden dürtü cevabına
  - $y[n]-\frac12y[n-1]=x[n]+\frac13x[n-1]$'in iki tarafının z-dönüşümü alınır: $Y(z)(1-\frac12z^{-1})=X(z)(1+\frac13z^{-1})$. $H(z)=\frac{1}{1-\frac12z^{-1}}+\frac13z^{-1}\frac{1}{1-\frac12z^{-1}}$ biçiminde iki parçaya ayrılır. İlk parça $(1/2)^nu[n]$, ikinci parça aynı dizinin bir birim gecikmiş ve $1/3$ ile çarpılmış halidir.
- Laplace ile diferansiyel denklem
  - $y''+5y'+6y=e^{-t}u(t)$, $y(0)=2$, $y'(0)=1$: $s^2Y-2s-1+5(sY-2)+6Y=\frac{1}{s+1}$, yani $Y(s)(s^2+5s+6)=\frac{1}{s+1}+2s+11$. $Y(s)=\frac{1/2}{s+1}+\frac{6}{s+2}-\frac{9/2}{s+3}$ ve $y(t)=\left(\frac12e^{-t}+6e^{-2t}-\frac92e^{-3t}\right)u(t)$. Sonuç denklemi ve $y(0)=2$, $y'(0)=1$ koşullarını sağlar (ders sonrası python ile kontrol edildi).
- Ders sonrası düzeltmeler
  - Hoca $x[n+5]$ için önce $z^{-5}$ dedi (01:00:35); doğrusu $z^{+5}$'tir. Hoca aynı derste $3\delta[n+2]\leftrightarrow3z^{2}$ örneğini doğru çözdü.
  - Ekrandaki $\sin(\Omega_0n)u[n]$ çiftinde paydada $2\sin\Omega_0$ yazdı (02:20:00); doğrusu $1-2\cos\Omega_0\,z^{-1}+z^{-2}$'dir (python ile kontrol edildi).
  - Hoca $\delta[n]$'nin ROC'si için "bütün reel sayılar" dedi; doğrusu bütün z düzlemidir.
  - Laplace'ta sinüzoitle çarpma özelliğinde hoca iki durum için de "$j/2$ ile ölçekleme" dedi; doğrusu $\cos(\omega_0t)x(t)\leftrightarrow\frac12[X(s-j\omega_0)+X(s+j\omega_0)]$, $\sin(\omega_0t)x(t)\leftrightarrow\frac{1}{2j}[X(s-j\omega_0)-X(s+j\omega_0)]$'dir.
  - Ötelemeli ters dönüşüm örneğinde $\frac{z^{-3}}{z+0.5}$ teriminin karşılığı $(-0.5)^{n-4}u[n-4]$'tür; tabandaki eksi işareti önemlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
