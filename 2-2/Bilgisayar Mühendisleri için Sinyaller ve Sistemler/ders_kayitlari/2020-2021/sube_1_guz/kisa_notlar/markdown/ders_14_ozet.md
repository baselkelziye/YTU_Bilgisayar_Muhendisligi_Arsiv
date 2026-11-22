# Ders 14 Çalışma Özeti

## Genel Konular

- Dönüşümlerin yeri ve z-dönüşümüne geçiş
  - İşaretler sürekli zamanda $x(t)$, ayrık zamanda $x[n]$ olarak incelenir. Sürekli zamanda CTFT $X(\omega)$, ayrık zamanda DTFT $X(\Omega)=X(e^{j\Omega})$ görülmüştü. Sürekli frekans $0$'dan $\infty$'a gider; sayısal frekans ise $[0,2\pi)$ ya da $[-\pi,\pi)$ aralığında incelenir (ekrandan, 00:20:00).
  - DTFT'nin $[0,2\pi)$ aralığı $N$ parçaya bölünürse hem zaman hem frekans ayrık olur: DFT, $X[k]$. Bu kısım sayısal işaret işleme dersinin konusudur.
  - Laplace dönüşümü CTFT'nin, z-dönüşümü DTFT'nin genelleştirilmiş hâlidir. Laplace integral-diferansiyel denklemleri, z-dönüşümü fark denklemlerini cebirsel ifadelere çevirir.
  - $\Omega=\pi$, örnekleme frekansının yarısına ($f_s/2$) karşılık gelir. Örnek: 4 kHz bant genişlikli konuşma işareti en az 8 kHz ile örneklenmelidir.
- LTI sistemin karmaşık üstel girişe cevabı
  - Zaman domeninde çıkış konvolüsyonla bulunur: $y[n]=x[n]*h[n]$, $y(t)=x(t)*h(t)$. Frekans domeninde sisteme $e^{j\Omega n}$ verilirse çıkış $H(e^{j\Omega})e^{j\Omega n}$ olur (ekrandan, 00:20:00).
  - z-dönüşümünde giriş $z^n$ alınır: $y[n]=T\{z^n\}=H(z)z^n$, $H(z)=\sum_{n=-\infty}^{\infty}h[n]z^{-n}$ (ekrandan, 00:25:00).
- z-dönüşümünün tanımı
  - $X(z)=\sum_{n=-\infty}^{\infty}x[n]z^{-n}$ (ekrandan, 00:25:00). $z$ karmaşık değişkendir; kutupsal biçimi $z=re^{j\Omega}$'dır, $r$ genlik, $\Omega$ açıdır.
  - $r=1$ alınırsa $z=e^{j\Omega}$ olur ve z-dönüşümü DTFT'ye indirgenir. $r$, farklı genlikli üstel işaretleri de analize katar.
  - $-\infty$'dan $\infty$'a toplanan biçim iki taraflı (bilateral), $n=0$'dan başlayan biçim tek taraflı (unilateral) z-dönüşümüdür. Gösterim: $x[n]\overset{z}{\longleftrightarrow}X(z)$ ya da $X(z)=\mathcal{Z}\{x[n]\}$.
- Yakınsaklık bölgesi (ROC)
  - $X(z)$'nin sonlu olduğu $z$ değerleri kümesidir. Şart: $\sum|x[n]||z^{-n}|<\infty$ (ekrandan, 01:15:00). Laplace'ta olduğu gibi sonuç her zaman ifade ve ROC çifti olarak verilir.
  - Kullanılan seri toplamları: $\sum_{n=0}^{\infty}\alpha^n=\frac{1}{1-\alpha}$ ($|\alpha|<1$); $\sum_{n=0}^{N-1}\alpha^n=\frac{1-\alpha^N}{1-\alpha}$ ($\alpha\neq1$, $\alpha=1$ ise toplam $N$); $\sum_{n=0}^{\infty}n\alpha^n=\frac{\alpha}{(1-\alpha)^2}$ ($|\alpha|<1$).
- Temel örnekler (Schaum Örnek 4.1, 4.2 ve Problem 4.1)
  - Sağ taraflı: $a^nu[n]\leftrightarrow\frac{1}{1-az^{-1}}=\frac{z}{z-a}$, $|z|>|a|$ (ekrandan, 00:35:00 ve 00:40:00). Sıfır $z=0$'da, kutup $z=a$'da.
  - Sol taraflı: $-a^nu[-n-1]\leftrightarrow\frac{z}{z-a}$, $|z|<|a|$ (ekrandan, 00:50:00 ve 01:05:00). İfade aynı, ROC farklıdır.
  - $a^{-n}u[-n-1]\leftrightarrow-\frac{z}{z-1/a}$, $|z|<\frac{1}{|a|}$ (ekrandan, 00:55:00).
  - $\delta[n]\leftrightarrow1$, ROC tüm z düzlemi. $u[n]\leftrightarrow\frac{z}{z-1}$, $|z|>1$.
  - İki taraflı dizi: $x[n]=a^n$ ($n\ge0$), $x[n]=-b^n$ ($n<0$) için $X(z)=\frac{z}{z-a}+\frac{z}{z-b}=\frac{z\,(2z-(a+b))}{(z-a)(z-b)}$, ROC $|a|<|z|<|b|$ halkası. Sıfırlar $0$ ve $(a+b)/2$'de, kutuplar $a$ ve $b$'de.
- Kutup-sıfır grafiği ve z düzlemi
  - Rasyonel $X(z)$'de pay polinomu sıfır polinomu, payda polinomu karakteristik polinomdur. Sıfırlar payın, kutuplar paydanın kökleridir. Grafikte kutup "x", sıfır "o" ile gösterilir (ekrandan, 01:35:00).
  - $|z|=1$ çemberi birim çemberdir. $z=e^{j\Omega}$, $\Omega$ $0$'dan $2\pi$'ye giderken birim çemberi çizer (ekrandan, 01:10:00). Karmaşık düzleme z düzlemi denir (Laplace'taki s düzleminin karşılığı).
- ROC'nin özellikleri (ekrandan, 01:20:00)
  - ROC z düzleminde halka ya da disktir.
  - DTFT yalnız ROC birim çemberi kapsıyorsa vardır.
  - ROC kutup içeremez.
  - Sonlu uzunluklu dizide ROC tüm z düzlemidir.
  - Sağ taraflı dizide ROC en dıştaki kutbun dışıdır; $z=\infty$ dahil olabilir.
  - Sol taraflı dizide ROC en içteki kutbun içidir; $z=0$ dahil olabilir.
  - İki taraflı dizide ROC iç ve dış kutuplarla sınırlı bir halkadır. ROC bağlantılı (tek parça) olmalıdır.
- z-dönüşümünün özellikleri
  - Doğrusallık: $ax_1[n]+bx_2[n]\leftrightarrow aX_1(z)+bX_2(z)$, ROC en az $R_1\cap R_2$ (ekrandan, 01:25:00).
  - Öteleme: $x[n-m]\leftrightarrow z^{-m}X(z)$. DTFT'deki $x[n-n_0]\leftrightarrow e^{-j\Omega n_0}X(\Omega)$ özelliğinin karşılığıdır.
  - $\delta[n-m]\leftrightarrow z^{-m}$, ROC $0<|z|\le\infty$; $\delta[n+m]\leftrightarrow z^{m}$, ROC $0\le|z|<\infty$ (ekrandan, 01:30:00).
  - Zaman domeninde $n$ ile çarpma z domeninde türeve karşılık gelir (ispata girilmedi).
- Transfer fonksiyonu
  - $x[n]=z^n$ girişinde $y[n]=\sum_k h[k]z^{n-k}=z^n\sum_k h[k]z^{-k}=H(z)z^n$ (ekrandan, 01:50:00). $H(z)$ transfer fonksiyonudur.
  - Zaman domenindeki konvolüsyon z domeninde çarpmaya dönüşür: $Y(z)=X(z)H(z)$.
- Ters z-dönüşümü
  - Tek bir formülle değil, $X(z)$'yi bilinen dönüşüm çiftlerine benzeterek bulunur.
  - Kısmi kesirlere açılım: $X(z)=A(z)/B(z)$ rasyonelse, pay derecesi payda derecesinden küçükse ve kutuplar birinci dereceden ise $X(z)=\sum X_k(z)$, $x[n]=\sum x_k[n]$ (ekrandan, 01:55:00). Tek katlı kutuplarda $x[n]=\sum_k r_kp_k^nu[n]$.
  - Seri açılımı: $X(z)=\dots+x[-1]z+x[0]+x[1]z^{-1}+\dots$; $z^{-k}$'nın katsayısı $x[k]$'dır, dizi impulsların toplamı olarak okunur.
- MATLAB ile kutup-sıfır çizimi
  - `tf2zp` pay ve payda katsayılarından sıfırları, kutupları ve kazancı bulur; `zplane` bunları z düzleminde çizer.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aynı cebirsel ifade, farklı ROC
  - $a^nu[n]$ ve $-a^nu[-n-1]$'in ikisi de $\frac{z}{z-a}$ verir; yalnız ROC farklıdır ($|z|>|a|$ ve $|z|<|a|$). Bu yüzden z-dönüşümü sonucu ROC'siz yazılmaz.
- $|z|>|a|$ şartının kaynağı
  - Geometrik serinin yakınsaması için $|az^{-1}|<1$ olmalıdır. Hoca bu şartı "hiç unutmuyoruz" diye vurguladı.
- Öteleme özelliği ve ters dönüşüm
  - $z^{-m}$ çarpanı zamanda $m$ birim gecikmedir. Hoca bunun önemli bir soru tipi olduğunu söyleyip Örnek 12.9'u ayrıntılı açıkladı.
- Çalışılacak konular
  - $X(z)$'nin bulunması, kutup-sıfır çizimi ve ROC, derste çözülenlere benzer basit ters dönüşümler. Schaum kitabının z-dönüşümü bölümünün sonundaki sorular önerildi.

## Kısa Tekrar Notları

- $X(z)=\sum x[n]z^{-n}$, $z=re^{j\Omega}$; $r=1$ ise DTFT.
- $a^nu[n]\leftrightarrow\frac{z}{z-a}$, $|z|>|a|$; $-a^nu[-n-1]\leftrightarrow\frac{z}{z-a}$, $|z|<|a|$.
- $\delta[n]\leftrightarrow1$ (tüm düzlem); $u[n]\leftrightarrow\frac{z}{z-1}$, $|z|>1$; $\delta[n-m]\leftrightarrow z^{-m}$.
- ROC: kutup içermez; sağ taraflı dizide dışa, sol taraflıda içe, iki taraflıda halka; DTFT için birim çemberi kapsamalı.
- Doğrusallıkta ROC kesişim; $x[n-m]\leftrightarrow z^{-m}X(z)$.
- $H(z)=\sum h[n]z^{-n}$, $Y(z)=H(z)X(z)$.
- Ters dönüşüm: $X(z)/z$ ya da $X(z)$ kısmi kesirlere açılır, $\frac{z}{z-a}$ biçimlerine getirilir, ROC'ye göre sağ ya da sol taraflı dizi seçilir.

## Detaylı Açıklamalar

- z-dönüşümünün tanımı ve ROC
  - Ders, DTFT'den z-dönüşümüne geçişle başladı. DTFT'de işaret $e^{-j\Omega n}$ ile çarpılıp toplanır; işaret hangi frekansa benziyorsa o frekansta büyük değer çıkar. z-dönüşümünde $e^{j\Omega}$ yerine $z=re^{j\Omega}$ konur. Böylece genliği değişen (artan ya da azalan) üstel bileşenler de analize girer ve DTFT'si olmayan bazı işaretlerin de dönüşümü bulunabilir.
  - $x[n]=a^nu[n]$ için $X(z)=\sum_{n=0}^{\infty}(az^{-1})^n$. $a=1/2$ gibi bir değerde dizi azalır ve toplam yakınsar; $a=2$ gibi bir değerde dizi büyür. Toplamın yakınsaması için $|az^{-1}|<1$, yani $|z|>|a|$ olmalıdır. Sonuç $\frac{1}{1-az^{-1}}$ ya da pay ve payda $z$ ile çarpılarak $\frac{z}{z-a}$'dır (ekrandan, 00:40:00).
  - Schaum Problem 4.1(a)'da $-a^nu[-n-1]$ dizisi $n=-1$'den $-\infty$'a uzanır. Toplamın indisi $n\to-n$ ile çevrilir, $n=0$ terimi ($=1$) eklenip çıkarılır: $X(z)=1-\sum_{n=0}^{\infty}(a^{-1}z)^n=1-\frac{1}{1-a^{-1}z}=\frac{z}{z-a}$, $|z|<|a|$ (ekrandan, 00:50:00).
  - Problem 4.1(b)'de $a^{-n}u[-n-1]$ için $X(z)=\sum_{n=1}^{\infty}(az)^n=\frac{1}{1-az}-1=\frac{az}{1-az}=-\frac{z}{z-1/a}$, $|z|<1/|a|$ (ekrandan, 00:55:00).
- ROC'nin özellikleri ve iki taraflı dizi
  - İki taraflı dizide sağ taraflı parça $|z|>|a|$, sol taraflı parça $|z|<|b|$ verir; ortak ROC kesişimdir, $|a|<|z|<|b|$ halkası. Kesişim boşsa dizinin z-dönüşümü yoktur.
- Doğrusallık örneği (Örnek 12.5)
  - $x[n]=(0{,}5^n+2)u[n]=0{,}5^nu[n]+2u[n]$. Dönüşümler $\frac{1}{1-0{,}5z^{-1}}$ ($|z|>0{,}5$) ve $\frac{2}{1-z^{-1}}$ ($|z|>1$). Ortak ROC büyük olanı, $|z|>1$'dir. <!-- BELİRSİZ: Örnek 12.5 slaydı karelerde görünmüyor; dizinin yazımı altyazıdan kuruldu. -->
- Kutup-sıfır örneği
  - Slayttaki örnekte pay $(1-0{,}8z^{-1})(1+0{,}8z^{-1})$ biçiminde çarpanlarına ayrıldı; sıfırlar $z=\pm0{,}8$'dir. Her çarpan sıfıra eşitlenerek kök bulunur. <!-- BELİRSİZ: Paydanın ifadesi ve kutupların yeri (altyazıda 0,4 ve 0,2 geçiyor) karelerden doğrulanamadı. -->
- Ters dönüşüm örnekleri
  - Örnek 12.9: $X(z)=\frac{z^{-4}}{z-1}+z^{-6}+\frac{z^{-3}}{z+0{,}5}=z^{-5}\frac{z}{z-1}+z^{-6}+z^{-4}\frac{z}{z+0{,}5}$, buradan $x[n]=u[n-5]+\delta[n-6]+(-0{,}5)^{n-4}u[n-4]$ (ekrandan, 02:00:00).
  - Örnek 12.10: $F(z)=\frac{10z(z+5)}{(z-1)(z-2)(z+3)}=z\left[\frac{-15}{z-1}+\frac{14}{z-2}+\frac{1}{z+3}\right]$, buradan $f[n]=(-3)^nu[n]+14\cdot2^nu[n]-15u[n]$ (ekrandan, 02:05:00).
  - Örnek 12.11: $x[n]=7(-\tfrac13)^nu[n]-(\tfrac12)^nu[-n-1]$ için $X(z)=\frac{7z}{z+1/3}+\frac{z}{z-1/2}=\frac{z(8z-19/6)}{(z+1/3)(z-1/2)}$, ROC $\tfrac13<|z|<\tfrac12$ (ekrandan, 02:10:00). Sıfırlar $0$ ve $19/48$'de, kutuplar $-1/3$ ve $1/2$'dedir.
- Ders sonrası not
  - Hoca bir yerde "Laplace'ın sürekli haldeki karşılığı z-dönüşümü" dedi; doğrusu, z-dönüşümü Laplace dönüşümünün ayrık zamandaki karşılığıdır (aynı derste kendisi de böyle tanımladı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
