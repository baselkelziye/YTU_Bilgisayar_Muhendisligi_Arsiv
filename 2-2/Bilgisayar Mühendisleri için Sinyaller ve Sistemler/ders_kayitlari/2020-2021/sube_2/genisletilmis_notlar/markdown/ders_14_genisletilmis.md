# Ders 14 Genişletilmiş Notu: Laplace Dönüşümü Tekrarı ve z-Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. DTFT'de $1/2\pi$ Katsayısının Yeri
- 2. Laplace Dönüşümünün Tekrarı
- 3. z-Dönüşümünün Tanımı ve Karmaşık Sayılar
- 4. z-Dönüşümünün Varlığı
- 5. İlk Örnekler: $a^nu[n]$, Sonlu Dizi ve $2^nu[n]$
- 6. Ayrık Zamanda Türev: Fark İşlemi
- 7. Sol Yanlı Dizi ve ROC Kuralları
- 8. Kararlılık ve Nedensellik
- 9. İki Kutuplu Örnek ve Delta Örnekleri
- 10. z-Dönüşümünün Özellikleri
- 11. z-Dönüşüm Tablosu
- 12. Ters z-Dönüşümü
- 13. Sistem Modelleme Üzerine
- 14. Fark Denklemleri ve Transfer Fonksiyonu
- 15. Alıştırmalar ve z-Dönüşümüyle Konvolüsyon
- 16. Slaytlardan: Gecikme, Kaskat Sistemler, Frekans Cevabı ve Filtreler
- 17. Laplace Dönüşümü Örnekleri
- Örnek Sorular

## 1. DTFT'de $1/2\pi$ Katsayısının Yeri

Ders, bir öğrencinin sorusuyla başladı.

**Soru:** Önerilen bir video serisinde ayrık zamanlı Fourier dönüşümünün $\frac{1}{2\pi}$ katsayısı analiz denklemine yazılmış; internetteki diğer kaynaklar ise bu katsayıyı sentez denkleminde kullanıyor. Katsayının yerinin bir önemi var mı?

**Cevap:** Ders notlarında ve kitapta analiz denklemi $X(\Omega)=\sum_{n}x[n]e^{-j\Omega n}$ biçimindedir; $\frac{1}{2\pi}$ sentez (ters dönüşüm) denklemindedir. Katsayı bir normalizasyon için konur. O kaynak toplamı $-\infty..\infty$ aralığında ya da integrali $-\pi..\pi$ aralığında aldığı için katsayıyı başka yere koymuş olabilir; sınırlar değişince elde edilen değerler de değişir. Ayrık zamanda işaret çoğu zaman belli bir noktada başlayıp biter (ör. $n=0..5$). Hoca o kaynaktaki türetmeyi ayrıca inceleyeceğini söyledi.

**Soru:** $2\pi$ sabit olduğu için integralden dışarı çıkar; ama genlik hesabında $1/2\pi$ kadar fark oluşmaz mı?

**Cevap:** Evet, fark oluşur. Katsayının hangi denklemde olduğu genlik değerlerini değiştirir.

## 2. Laplace Dönüşümünün Tekrarı

Hoca bir önceki derste tahta üzerinde anlatılan Laplace dönüşümünü ders slaytları üzerinden kısaca tekrar etti.

### 2.1 Dönemin konu haritası

Slayttaki haritada (ekrandan, 00:15:00) dönemin konuları şöyle sıralanır: giriş (sürekli ve ayrık işaret modelleri, LTI ve nedensellik gibi sistem özellikleri), diferansiyel ve fark denklemleri (sıfır durum ve sıfır giriş cevabı, karakteristik denklem), konvolüsyon (sürekli zamanda konvolüsyon integrali, ayrık zamanda konvolüsyon toplamı), sürekli ve ayrık zamanlı Fourier işaret ve sistem modelleri (Fourier serisi, CTFT, DTFT, DFT ve FFT, frekans cevabı) ve son olarak sürekli zaman için Laplace, ayrık zaman için z-dönüşümü (transfer fonksiyonu).

### 2.2 Laplace dönüşümüne neden gerek duyuldu?

Fourier dönüşümü, analiz edilen işaret mutlak integrallenebilir olmadığında, yani enerjisi ya da gücü sonsuza gittiğinde çalışmaz. Bunu aşmak için çekirdekteki $e^{-j\omega t}$'nin önüne bir çarpan konur: $e^{-\sigma t}$. İkisi birlikte $e^{-(\sigma+j\omega)t}=e^{-st}$ olur, $s=\sigma+j\omega$. Laplace dönüşümü de bir integral dönüşümüdür: $x(t)$ bir çekirdekle çarpılıp $t$'ye göre integrali alınınca $t$ kaybolur, yerine ikinci parametre ($s$) gelir. $\sigma$ işareti bastırır ve sonsuz durumdan sonlu duruma geçişi sağlar.

İki taraflı Laplace dönüşümünde işaret $-\infty..\infty$ aralığında, tek taraflıda $0..\infty$ aralığında incelenir. Tek taraflı dönüşümde negatif zaman yoktur: bir anahtar kapandığında devredeki o anki yük, sıfırıncı andan başlayarak analize dahil edilir.

### 2.3 ROC ve sıfır-kutup diyagramı

Elde edilen sonuç $s$ düzleminde ($\sigma$ ve $j\omega$ eksenleri) incelenir. İntegral ancak belli bir bölgede yakınsar; bu bölge yakınsama bölgesidir (ROC). Örneğin $e^{-bt}u(t)$ için integrand $e^{-(s+b)t}$'dir. $t\to\infty$'da sıfıra gitmesi için $s+b$'nin reel kısmı pozitif olmalıdır. $j\omega$ sanal olduğundan koşul $\sigma+b>0$, yani $\sigma>-b$ olur. Bunun tersinde integral büyüyüp gider.

Laplace dönüşümü aynı olup ROC'si farklı olan işaretler vardır (ör. ikisinin de dönüşümü $\frac{1}{s-a}$ olan sağ ve sol yanlı işaretler). ROC $j\omega$ eksenini içeriyorsa işaretin Fourier dönüşümü de vardır; içermiyorsa yalnız Laplace dönüşümü vardır.

Payı sıfırlayan değerler sıfırlar (zeros), paydayı sıfırlayan değerler kutuplardır (poles). Kutuplar diyagramda × ile gösterilir; bu değerlerde ifade sonsuza gider. Sıfırlarda ifade sıfır olur. Bu gösterime sıfır-kutup diyagramı denir.

### 2.4 Özellikler

- **Doğrusallık:** Sabitle çarpılmış toplamların dönüşümü ayrı ayrı alınabilir.
- **Zamanda öteleme:** $x(t-c)\leftrightarrow e^{-cs}X(s)$; tekrar integral almaya gerek yoktur.
- **Türev:** Fourier'de $j\omega$ ile çarpma neyse Laplace'ta $s$ ile çarpmadır (çift taraflı). Tek taraflı dönüşümde $y'(t)\leftrightarrow sY(s)-y(0)$, $y''(t)\leftrightarrow s^2Y(s)-sy(0)-y'(0)$. Başlangıç değerleri sayısal olarak verilir.
- **İntegral:** $1/s$ ile çarpmaktır; türevin tersidir.
- **Zamanda ölçekleme:** $x(at)\leftrightarrow\frac1aX\!\left(\frac sa\right)$.
- **$t^n$ ile çarpma:** $t^nx(t)\leftrightarrow(-1)^n\frac{d^nX(s)}{ds^n}$.
- **Üstel ile çarpma:** $s$ düzleminde kaydırma yapar.
- **Sinüzoitle çarpma:** Sinüs ve kosinüs $e^{\pm j\omega t}$ cinsinden açıldığında $s-j\omega_0$ ve $s+j\omega_0$ kadar kaymış iki terim gelir. Bu modülasyondur ve haberleşmede çok kullanılır: bir ses işaretinin bilgisi radyo frekans aralığına (yaklaşık 88-108 MHz) taşınır, radyo alıcısı ters işlemle sesi duyulabilir aralığa geri getirir.
- **Konvolüsyon:** Zamandaki konvolüsyonun karşılığı çarpımdır. $Y(s)$ ve $X(s)$ bulunarak $H(s)$ elde edilir.

> **Ders sonrası not:** Hoca sinüs ve kosinüsle çarpma için ikisinde de "$j/2$ kadar ölçekleme" dedi. Doğrusu $\cos(\omega_0t)x(t)\leftrightarrow\frac12[X(s-j\omega_0)+X(s+j\omega_0)]$ ve $\sin(\omega_0t)x(t)\leftrightarrow\frac{1}{2j}[X(s-j\omega_0)-X(s+j\omega_0)]$'dir.

> **Hocanın vurgusu:** Transfer fonksiyonu kavramı genelde Laplace dönüşümünde, frekans cevabı kavramı Fourier dönüşümünde kullanılır. Geri kalan her şey Fourier dönüşümüyle aynıdır.

### 2.5 Diferansiyel denklem çözümü

Sabit katsayılı diferansiyel denklemleri çözmek her zaman kolay değildir, özellikle ikinci ve üçüncü mertebede. Laplace dönüşümüyle $y(t)\to Y(s)$, $y'(t)\to sY(s)$ yazılır ve denklem toplama, çıkarma, çarpma, bölmeyle çözülür.

Slayttaki RC devresi örneğinde (ekrandan, 00:25:00) Kirchhoff ve Ohm yasalarından birinci mertebe bir diferansiyel denklem elde edilir. Devrenin başlangıç koşulu olduğu için tek taraflı dönüşüm alınır: $y'(t)\to sY(s)-y(0)$, $ay(t)\to aY(s)$, $bx(t)\to bX(s)$. Giriş birim basamaksa $X(s)=1/s$'dir. İfade $\frac1s-\frac{1}{s+1/RC}$ gibi basit kesirlere ayrılır; $\frac1s\to u(t)$, $\frac{1}{s+1/RC}\to e^{-t/RC}u(t)$. Sonuçta $y(t)$ elde edilir ve örneğin $t=10$ saniyedeki değer doğrudan hesaplanabilir. İkinci mertebe bir denklemde aynı işlem iki kez türev kuralıyla yapılır.

Slayttaki genel ifade (ekrandan, 00:30:00): $H(s)=\frac{B(s)}{A(s)}$ olan bir sistem, $X(s)=\frac{N_X(s)}{D_X(s)}$ girişi ve başlangıç koşullarıyla

$$Y(s)=\underbrace{\frac{IC(s)}{A(s)}}_{\text{sıfır giriş}}+\underbrace{\frac{E(s)}{A(s)}+\frac{F(s)}{D_X(s)}}_{\text{sıfır durum}}$$

verir. $A(s)$ ve $IC(s)/A(s)$ terimleri geçici (transient) cevabı, $F(s)/D_X(s)$ kalıcı durum (steady-state) cevabını oluşturur. Sistem karakteristik polinomu $A(s)$'nin kökleri negatif reel kısımlıysa geçici kısım zamanla söner.

### 2.6 Basit kesirlere ayırma ve sonuçlara $u(t)$ eklenmesi

Ters Laplace dönüşümü integralle değil, bilinen dönüşümlere çevirerek yapılır. Payda çarpanlarına ayrılabiliyorsa (ör. $(s+1)(s+2)$) her çarpana bir sabit katsayı yazılır; ikinci dereceden bir çarpan varsa payına $As+B$ biçiminde bir ifade gelir. Slayttaki genel biçim, tekrarlı kutup yoksa ve $N>M$ ise (ekrandan, 00:35:00):

$$G(s)=\frac{b_Ms^M+\dots+b_1s+b_0}{(s-p_1)(s-p_2)\cdots(s-p_N)}=\frac{K_1}{s-p_1}+\frac{K_2}{s-p_2}+\dots+\frac{K_N}{s-p_N}.$$

> **Hocanın vurgusu:** Bulunan sonuçların yanına $u(t)$ eklemek gerekir; çünkü bunlar işarettir, sıradan matematiksel denklem gibi düşünülmemelidir. İşaret işlemeci gözüyle sıfırdan önceki aralıkla pek ilgilenilmez.

### 2.7 MATLAB ve kaynaklar

MATLAB'da transfer fonksiyonu pay (numerator) ve payda (denominator) katsayılarıyla tanımlanır. Katsayılar en yüksek dereceden en düşüğe yazılır; ilgili derece yoksa araya 0 konur (ör. $s^2+4$ için $[1\ 0\ 4]$). Elde edilen transfer fonksiyonunun sıfırları, kutupları ve sıfır-kutup çizimi hazır komutlarla bulunur. Kontrolcüler bu araçlarla sistem kararlılığına, haberleşmeciler başka açılardan bakar; bilgisayar mühendisliğinde Fourier tabanlı özellikler özellik çıkarımı ve makine öğrenmesinde kullanılır. Hoca slaytlardaki ters Laplace dönüşümü ve basit kesir örneklerinin çalışmak için yeterli olduğunu söyledi. $s$ yerine $j\omega$ konunca bazı şartlarda Fourier dönüşümü elde edilir.

## 3. z-Dönüşümünün Tanımı ve Karmaşık Sayılar

Sürekli zamanda Fourier dönüşümündeki sorun Laplace dönüşümüyle çözülmüştü. Ayrık zamanda da aynı durum vardır. DTFT $X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]e^{-j\Omega n}$ biçimindedir (sürekli zamandaki küçük $\omega$ burada büyük $\Omega$ olur). İşaretin enerjisinin sonsuza gitme olasılığı yüzünden DTFT her zaman çözüm olmaz; daha genel hali olan z-dönüşümü kullanılır (ekrandan, 00:45:00):

$$X(z)=\sum_{n=-\infty}^{\infty}x[n]\,z^{-n}.$$

Bu bir toplam dönüşümüdür; $n$ tamsayı değerler alır. Toplam $-\infty..\infty$ ise iki taraflı (bilateral, bidirectional), $n=0..\infty$ ise tek taraflıdır (unilateral).

### 3.1 $z$ nedir?

Bir karmaşık sayı $a+bj$, reel ekseni $a$, sanal ekseni $b$ olan bir nokta olarak gösterilebilir. Aynı nokta, orijine uzaklığı $r=\sqrt{a^2+b^2}$ ve açısı $\theta$ ile de ifade edilir. Açının tanjantı karşı bölü komşu, yani $b/a$'dır; açı $\theta=\arctan(b/a)$ ile bulunur. Böylece

$$z=r(\cos\theta+j\sin\theta)=r\,\mathrm{cis}\,\theta=r\,e^{j\theta}$$

yazılır; son eşitlik Euler formülünden ($e^{j\theta}=\cos\theta+j\sin\theta$) gelir. z-dönüşümündeki $z$ de budur: $z=re^{j\Omega}$. Laplace'taki $s=\sigma+j\omega$ nasıl karmaşık bir sayıysa $z$ de öyledir. $e^{j\Omega}$ sinüs ve kosinüs bileşenlerini, $r$ ise işaretteki reel ölçek bileşenini taşır.

### 3.2 Geometrik seri

Toplam sembolüyle çalışırken en çok kullanılan eşitlik şudur:

$$\sum_{n=0}^{\infty}r^n=\frac{1}{1-r},\qquad |r|<1.$$

$r=1/2$ gibi bir değerin kuvvetleri sonsuza kadar toplanınca belli bir sayıya (burada 2'ye) yaklaşılır. $|r|>1$ ise (ör. 2'nin kuvvetleri) toplam sonsuza gider, seri ıraksar. Hoca bu eşitliğin dönüşümlerde sürekli kullanılacağını söyledi.

## 4. z-Dönüşümünün Varlığı

z-dönüşümünün var olması için toplamın sonlu olması gerekir:

$$\left|\sum_{n}x[n]z^{-n}\right|<\infty.$$

Mutlak değer toplamın içine alınır ve $z=re^{j\Omega}$ yazılır: $\sum_n|x[n]\,r^{-n}e^{-j\Omega n}|$. $e^{-j\Omega n}=\cos\Omega n-j\sin\Omega n$ olduğundan büyüklüğü 1'dir; yakınsama yalnız $r$'ye bağlı kalır:

$$\sum_{n}|x[n]\,r^{-n}|<\infty.$$

$r=1$ alınırsa (yani $z=e^{j\Omega}$) DTFT elde edilir ve koşul $\sum_n|x[n]|<\infty$ olur (ekrandan, 00:55:00). Sürekli zamandaki "mutlak integrallenebilir" koşulunun ayrık zamandaki karşılığı "mutlak toplanabilir"dir (absolutely summable).

**Soru:** İlk tanımda toplam $n=0$'dan başlıyordu, sonra $-\infty$'dan yazdık; hangisi doğru?

**Cevap:** İki taraflı tanımda toplam $-\infty..\infty$ olmalıdır; $0..\infty$ tek taraflı durumdur. Hoca tanımı düzeltti.

## 5. İlk Örnekler: $a^nu[n]$, Sonlu Dizi ve $2^nu[n]$

### 5.1 $x[n]=a^nu[n]$

Bu işaret $a$'nın değerine göre ya sonsuza giden ya da azalan bir üsteldir. Tanımdan (ekrandan, 00:55:00):

$$X(z)=\sum_{n=-\infty}^{\infty}a^nu[n]z^{-n}=\sum_{n=0}^{\infty}(az^{-1})^n=1+az^{-1}+(az^{-1})^2+\dots$$

$u[n]$ yüzünden negatif $n$ terimleri sıfırdır. Geometrik seri formülüyle

$$X(z)=\frac{1}{1-az^{-1}},\qquad |az^{-1}|<1\;\Rightarrow\;\frac{|a|}{|z|}<1\;\Rightarrow\;|z|>|a|.$$

ROC, merkezi orijin ve yarıçapı $|a|$ olan çemberin dışıdır (ekrandan, 01:05:00). $a$ aynı zamanda paydayı sıfırlayan değer, yani kutuptur. İki taraf $z$ ile çarpılırsa aynı sonuç $\frac{z}{z-a}$ biçiminde de yazılır.

### 5.2 Sonlu dizi

$x[n]=\{1,2,3,4\}$, $n=0$ noktası ilk elemanda olsun. Toplam sonlu olduğundan ROC'ye ayrıca bakmaya gerek yoktur (ekrandan, 01:05:00):

$$X(z)=x[0]z^{0}+x[1]z^{-1}+x[2]z^{-2}+x[3]z^{-3}=1+2z^{-1}+3z^{-2}+4z^{-3}.$$

Hoca bunu konvolüsyonla ilişkilendirdi: aynı dizi $h[n]=\delta[n]+2\delta[n-1]+3\delta[n-2]+4\delta[n-3]$ biçiminde yazılabilir. $n$'deki katsayı doğrudan $z^{0}$'ın, $n-1$'deki katsayı $z^{-1}$'in, $n-2$'deki $z^{-2}$'nin katsayısı olur. Zaman düzlemindeki konvolüsyon, z düzleminde çarpıma dönüşür.

> **Ders sonrası not:** Hoca "$n+5$ olursa" sorusuna "$z^{-5}$ olacak" diye cevap verdi (01:00:35). Doğrusu $x[n+5]\leftrightarrow z^{+5}X(z)$'dir. Hoca dersin ilerleyen kısmında $3\delta[n+2]\leftrightarrow3z^{2}$ örneğini doğru çözdü (Bölüm 9.2).

### 5.3 $x[n]=2^nu[n]$, ROC nedir?

$X(z)=\sum_{n=0}^{\infty}2^nz^{-n}$. ROC aranırken $z=re^{j\Omega}$ yazılır; $e^{j\Omega}$ terimi büyüklüğü etkilemez (ekrandan, 01:05:00):

$$\sum_{n=0}^{\infty}|2^nr^{-n}|=\sum_{n=0}^{\infty}(2r^{-1})^n=1+2r^{-1}+(2r^{-1})^2+\dots$$

Toplamın sonlu olması için $|2r^{-1}|<1$, yani $2/r<1$, $r>2$ olmalıdır. ROC $|z|>2$'dir: z düzleminde birim çemberin de dışında kalan, yarıçapı 2 olan çemberin dışı. Bu koşul dışında işaret sonsuza gider ve z-dönüşümü alınamaz.

## 6. Ayrık Zamanda Türev: Fark İşlemi

Arada bir öğrencinin "diferansiyel nedir?" sorusu üzerine hoca türevi fark olarak açıkladı. Sürekli zamanda $t$ noktasındayken $t$'ye küçük bir $h$ artışı verilir ve

$$\frac{f(t+h)-f(t)}{(t+h)-t}$$

ile çok küçük bir artıştaki değişim miktarına bakılır. Ayrık zamanda elimizde bir dizi vardır (C'deki dizi gibi: sıfırıncı, birinci eleman...). En küçük adım $h=1$'dir; birden küçük bir dilime gidilemez. Bu yüzden türev, dizinin $n$. elemanından $n-1$. elemanını çıkarmaktır: $x[n]-x[n-1]$. Sürekli zamanda buna diferansiyel, ayrık zamanda fark (difference) denir; ikisi de çıkarma işlemidir.

Hocanın benzetmesi: yoğurda su ekleyince ayran olur; ayrandan suyu çıkarınca yoğurda dönülür. Burada türev, bir şeyin bir şeyden farkı, aradaki değişimdir.

Örnekler (derste sözlü, 01:56:54-01:57:59):

- $3,4,5,6$ dizisi $y=x$ gibi doğrusal artar; farkı $1,1,1$'dir. Doğrunun türevi sabittir.
- $2,6,8,12$ tam bir doğru değildir; farkı $4,2,4$'tür. Fark yine değişim hakkında bilgi verir ve sonraki değeri tahmin etmede kullanılabilir (ör. 2 birimlik değişimle sonraki değer 14 tahmin edilebilir).

Sinyallerde taban çizgisi düzeltme (baseline adjustment) bu fikri kullanır. Konuşma sinyaline dışarıdan yavaşça artan bir bileşen eklenmişse, belli pencerelerde en küçük değerler bulunur, bu noktalardan geçen doğrular (interpolasyon) üretilir ve sinyalden çıkarılır; sonuç orijinale yakın olur. Türev kullanan algoritmalar bu işi daha hassas yapar.

## 7. Sol Yanlı Dizi ve ROC Kuralları

### 7.1 $x[n]=a^nu[-n-1]$

Önce $a^nu[n]\leftrightarrow\frac{1}{1-az^{-1}}=\frac{z}{z-a}$, $|z|>|a|$ hatırlatıldı. Şimdi $u[-n-1]$ yüzünden toplam $-\infty..-1$ aralığındadır (ekrandan, 01:35:00):

$$X(z)=\sum_{n=-\infty}^{-1}a^nz^{-n}=\sum_{n=-\infty}^{-1}(az^{-1})^n=\sum_{n=1}^{\infty}(a^{-1}z)^n.$$

Sınırların yer değiştirmesi sayısal değeri değiştirmez, yalnız üssün işareti değişir. $n=0$ terimi eklenip çıkarılırsa ($(a^{-1}z)^0=1$):

$$X(z)=\sum_{n=0}^{\infty}(a^{-1}z)^n-1=\frac{1}{1-a^{-1}z}-1=\frac{a}{a-z}-1=\frac{z}{a-z},\qquad |a^{-1}z|<1\Rightarrow|z|<|a|.$$

Başa bir eksi konsaydı ($x[n]=-a^nu[-n-1]$) sonuç $\frac{z}{z-a}$ olurdu. İki ifade aynıdır; farklı olan yalnız ROC'dir: biri $|a|$ çemberinin dışı, diğeri içidir. ROC, işaretin sağ yanlı mı sol yanlı mı olduğunu ayırt ettirir.

### 7.2 Kurallar

Laplace'taki kuralların z düzlemindeki karşılıkları (ekrandan, 01:35:00):

- **Sağ yanlı dizilerde** (sıfırdan küçük $n$'leri yok eden $u[n]$ gibi bir çarpan varsa) ROC, en büyük kutbun tanımladığı çemberin dışındadır. Laplace'ta "en büyük kutbun sağı" denmişti; z düzleminde "çemberin dışı" olur.
- **Sol yanlı dizilerde** ROC, en küçük kutbun tanımladığı çemberin içindedir.

## 8. Kararlılık ve Nedensellik

$X(z)$'de $z=e^{j\Omega}$ yazmak doğrudan DTFT'yi bulmaktır. Ama DTFT her zaman yoktur. DTFT ancak ROC birim çemberi içeriyorsa vardır. Laplace'ta bunun karşılığı ROC'nin $j\omega$ eksenini içermesiydi.

- ROC birim çemberi içeriyorsa sistem kararlıdır: enerjisi ya da gücü sonsuza gitmez.
- Sağ yanlı sistemler nedenseldir (causal): yalnız şimdiki ve geçmiş değerler vardır, geleceğe ilişkin bir şey yoktur.
- Sağ yanlı (nedensel) bir sistemde bütün kutuplar birim çemberin içindeyse sistem kararlıdır. Burada kararlılık, sınırlı girişe sınırlı çıkış (BIBO) anlamındadır.

> **Hocanın vurgusu:** Bir sistemin denklemine bakıp çıkışın sınırlı kalıp kalmadığını zaman ($n$) düzleminde görmek zor olabilir. z-dönüşümü alınıp kutuplara ya da ROC'ye bakılınca kararlılık kolayca söylenir.

## 9. İki Kutuplu Örnek ve Delta Örnekleri

### 9.1 $x[n]=7(1/3)^nu[n]-6(1/2)^nu[n]$

$a^nu[n]$ dönüşümü ve doğrusallıkla (ekrandan, 01:45:00):

$$X(z)=7\cdot\frac{1}{1-\frac13z^{-1}}-6\cdot\frac{1}{1-\frac12z^{-1}}=\frac{z\,(z-\frac32)}{(z-\frac12)(z-\frac13)}.$$

Paydalar eşitlenince kapalı form elde edilir ve kutuplar doğrudan görünür: $z=1/3$ ve $z=1/2$. Sıfırlar $z=0$ ve $z=3/2$'dir (ara adım eklendi: $7(z-\frac12)-6(z-\frac13)=z-\frac32$). Her terim kendi kutbunun dışında yakınsar ($|z|>1/3$ ve $|z|>1/2$). İşaret sağ yanlı olduğundan ROC en büyük kutbun ($1/2$) tanımladığı çemberin dışıdır: $|z|>1/2$.

**Soru (hocanın sorusu):** Bu sistem kararlı mıdır?

**Cevap:** Önce ROC'ye bakılır. Kutupların ikisi de birim çemberin içindedir; bu yüzden sistem kararlıdır. Burada ROC dışarıyı gösteriyor; bazı durumlarda ROC iki çember arasında simit gibi bir halka da olabilir.

### 9.2 Delta örnekleri

Hoca üç işaret verdi (ekrandan, 01:45:00): $\delta[n]$, $5\delta[n-3]$ ve $3\delta[n+2]$.

- $\delta[n]$ yalnız $n=0$'da 1, diğer her yerde 0'dır. Toplamda yalnız $\delta[0]z^{-0}=1$ kalır: $X(z)=1$.
- $5\delta[n-3]$: 5 dışarı çıkar; $\delta[n-3]$ yalnız $n=3$'te 1'dir. $5\delta[0]z^{-3}=5z^{-3}$.
- $3\delta[n+2]$: yalnız $n=-2$'de 1'dir. $3\delta[0]z^{-(-2)}=3z^{2}$.

**Soru:** $5\delta[n-3]$ için doğrudan $5z^{-3}$ diyebilir miyiz?

**Cevap:** Evet; ama ispat istenirse tanımdan gösterilmelidir.

Toplamları $x[n]=\delta[n]+5\delta[n-3]+3\delta[n+2]$ için doğrusallıkla $X(z)=1+5z^{-3}+3z^{2}$ olur.

Bir $x[n]$ işareti $\delta[n-3]$ ile konvolüsyona sokulursa yalnız $n-3$ noktasında sonuç alınır; işaret 3 birim gecikir. Konvolüsyon yerine z-dönüşümünü $z^{-3}$ ile çarpmak aynı sonucu verir. Örneğin $5\delta[n]\leftrightarrow5$; bunu $z^{-3}$ ile çarpmak $5z^{-3}$, yani $5\delta[n-3]$'tür. $z^{-1}$ birim geciktirme operatörü olarak kullanılır.

## 10. z-Dönüşümünün Özellikleri

Özellikler ekranda şöyle yazıldı (ekrandan, 01:55:00 ve 02:05:00).

### 10.1 Doğrusallık

$$a\,x_1[n]+b\,x_2[n]\;\leftrightarrow\;a\,X_1(z)+b\,X_2(z).$$

Toplamın dönüşümü ayrı ayrı alınabilir, katsayılar dışarı çıkar. ROC en az $R_1$ ile $R_2$'nin kesişimi kadardır (ekranda "ROC $\supset R_1\cap R_2$").

### 10.2 Zamanda öteleme

$x[n]\leftrightarrow X(z)$, ROC $R$ ise

$$x[n-n_0]\;\leftrightarrow\;z^{-n_0}X(z),\qquad \text{ROC}=R.$$

Kanıt: $\sum_nx[n-n_0]z^{-n}$'de $m=n-n_0$ konur, $n=m+n_0$ olur ve toplam $\sum_mx[m]z^{-m-n_0}=z^{-n_0}X(z)$'ye döner.

### 10.3 Zamanda ölçekleme ve ters çevirme

$$x[n/a]\;\leftrightarrow\;X(z^a),\qquad \text{ROC}=R^{1/a}.$$

$$x[-n]\;\leftrightarrow\;X(z^{-1}),\qquad \text{ROC}=1/R.$$

> **Ek bilgi (derste anlatılmadı):** Ayrık zamanda $x[n/a]$ ancak $n/a$ tamsayı olduğunda tanımlıdır; diğer noktalarda 0 alınır. Bu nedenle bu özellik çoğu kaynakta "zamanda genişletme" adıyla geçer.

### 10.4 Konvolüsyon

$$x[n]*y[n]\;\leftrightarrow\;X(z)\,Y(z).$$

Sınavda konvolüsyonu bir diziyi ters çevirip kaydırarak, örtüşen elemanları çarpıp toplayarak yapıyordunuz. Diziler z-dönüşümüne kolay çevriliyorsa dönüşümler çarpılır ve ters z-dönüşümü alınır.

### 10.5 $z$'de türev

$$n\,x[n]\;\leftrightarrow\;-z\frac{dX(z)}{dz},\qquad \text{ROC}=R.$$

Hoca bunu Laplace'taki $t^nx(t)\leftrightarrow(-1)^n\frac{d^nX(s)}{ds^n}$ kuralına benzetti. Pratikte bu kural tersten kullanılır: dönüşümde $z$'ye göre birinci türev görülüyorsa işaret $n$ ile çarpılmıştır. İkinci türev için doğrudan bir kural verilmedi. Hoca bütün dönüşümlerde (Fourier, Laplace, z) kuralların sınırlı sayıda ve birbirine benzer olduğunu, yalnız gösterimin (köşeli ya da yuvarlak parantez) değiştiğini söyledi.

### 10.6 İlk ve son değer teoremleri

$$x[0]=\lim_{z\to\infty}X(z),\qquad x[\infty]=\lim_{z\to1}(1-z^{-1})X(z).$$

$x[0]$ normalde $n$'li ifadede $n=0$ konarak bulunur; ama elde yalnız $X(z)$ varsa $z\to\infty$ limiti kullanılır. Son değer teoremi ayrık zamanda biraz teorik kalır.

## 11. z-Dönüşüm Tablosu

Hoca sık kullanılan çiftleri yazdı ve soruların bunlar üzerinden geleceğini söyledi (ekrandan, 02:15:00 ve 02:20:00):

| İşaret | $X(z)$ | ROC |
|---|---|---|
| $\delta[n]$ | $1$ | tüm $z$ |
| $u[n]$ | $\dfrac{1}{1-z^{-1}}=\dfrac{z}{z-1}$ | $\lvert z\rvert>1$ |
| $\delta[n-m]$ | $z^{-m}$ | tüm $z$ ($m>0$ ise 0, $m<0$ ise $\infty$ hariç) |
| $a^nu[n]$ | $\dfrac{1}{1-az^{-1}}=\dfrac{z}{z-a}$ | $\lvert z\rvert>\lvert a\rvert$ |
| $n\,a^nu[n]$ | $\dfrac{az^{-1}}{(1-az^{-1})^2}$ | $\lvert z\rvert>\lvert a\rvert$ |
| $\cos(\Omega_0n)u[n]$ | $\dfrac{1-\cos\Omega_0\,z^{-1}}{1-2\cos\Omega_0\,z^{-1}+z^{-2}}$ | $\lvert z\rvert>1$ |
| $\sin(\Omega_0n)u[n]$ | $\dfrac{\sin\Omega_0\,z^{-1}}{1-2\cos\Omega_0\,z^{-1}+z^{-2}}$ | $\lvert z\rvert>1$ |

$n\,a^nu[n]$ çifti, $a^nu[n]$'nin dönüşümüne $z$'de türev kuralı uygulanarak bulunur. Kosinüs için ipucu: kosinüs $e$'li biçimde yazılıp toplam açılır ve seri toplamları kullanılır. Hoca kosinüs ve sinüs çiftlerini kendi başınıza türetmenin iyi bir pratik olacağını söyledi.

> **Ders sonrası not:** Ekrandaki sinüs çiftinde paydada $2\sin\Omega_0$ yazıldı. Doğrusu, kosinüs çiftindekiyle aynı payda olan $1-2\cos\Omega_0\,z^{-1}+z^{-2}$'dir (python ile sayısal olarak kontrol edildi). Hoca ayrıca $\delta[n]$'nin ROC'si için "bütün reel sayılar" dedi; doğrusu bütün z düzlemidir. Tablodaki kosinüs ve sinüs satırlarının ROC'si ekranda yazılmadı; $|z|>1$ büyük olasılıkla doğrudur.

## 12. Ters z-Dönüşümü

Ters z-dönüşümünün tanımı bir kontur integralidir (integral işaretinin ortasında bir halka bulunur). Ayrık ve karmaşık bir durumdan geri dönmek gerektiği için bu integral karşımıza çıkar; ama pratikte kullanılmaz. Laplace'ta olduğu gibi tablo ve kurallar kullanılır.

### 12.1 Basit kesirlere ayırma örneği

$$X(z)=\frac{3-\frac56z^{-1}}{(1-\frac14z^{-1})(1-\frac13z^{-1})},\qquad |z|>\frac13$$

verilsin, $x[n]$ bulunsun (ekrandan, 02:20:00). Böyle bir dönüşüm tabloda yoktur; basit kesirlere ayrılır. Paydalar birinci dereceden olduğu için paylar sabittir:

$$X(z)=\frac{A}{1-\frac14z^{-1}}+\frac{B}{1-\frac13z^{-1}}.$$

Paydalar eşitlenir: $A(1-\frac13z^{-1})+B(1-\frac14z^{-1})=3-\frac56z^{-1}$ (ekrandan, 02:25:00). Açmaya gerek yoktur:

- $z^{-1}=4$ konunca $B$'li terim sıfırlanır: $A(1-\frac43)=3-\frac{20}{6}$, yani $A\cdot(-\frac13)=-\frac26$ ve $A=1$.
- $z^{-1}=3$ konunca $A$'lı terim sıfırlanır: $B(1-\frac34)=3-\frac52$, yani $B\cdot\frac14=\frac12$ ve $B=2$.

Hoca $B$'yi hesaplarken önce aritmetik bir hata yaptı ($\frac15$ buldu); bir öğrencinin uyarısıyla $\frac52$'nin $3-\frac52=\frac12$ vereceği düzeltildi.

$$X(z)=\frac{1}{1-\frac14z^{-1}}+\frac{2}{1-\frac13z^{-1}}.$$

Tablodaki $a^nu[n]$ kalıbına benzer. ROC $|z|>1/3$ (sıfırdan büyük değerler) olduğundan işaret sağ yanlıdır ve terimlerin yanına $u[n]$ gelir:

$$x[n]=\left(\tfrac14\right)^nu[n]+2\left(\tfrac13\right)^nu[n].$$

Sonuç python ile tanım toplamı hesaplanarak kontrol edildi.

### 12.2 Ötelemeli terimlerin ters dönüşümü

$$X(z)=\frac{z^{-4}}{z-1}+z^{-6}+\frac{z^{-3}}{z+0.5}$$

verildi (ekrandan, 02:50:00).

- $\frac{z^{-4}}{z-1}=z^{-5}\cdot\frac{z}{z-1}$. Tablodan $\frac{z}{z-1}\to u[n]$; $z^{-5}$ ile çarpmak 5 birim ötelemedir: $u[n-5]$.
- $z^{-6}$: 6 birim ötelenmiş delta, $\delta[n-6]$. Hoca bunu sınıfa sordu; kimse cevap vermeyince kendisi söyledi.
- $\frac{z^{-3}}{z+0.5}=z^{-4}\cdot\frac{z}{z+0.5}$. $\frac{z}{z-a}$ kalıbında $a=-0.5$'tir; $z^{-4}$ ile çarpma 4 birim ötelemedir: $(-0.5)^{n-4}u[n-4]$.

Sonuç: $x[n]=u[n-5]+\delta[n-6]+(-0.5)^{n-4}u[n-4]$.

> **Ders sonrası not:** Hoca son terimi söylerken "$0.5^{n-4}$" dedi; kalıpta $a=-0.5$ olduğundan doğrusu $(-0.5)^{n-4}u[n-4]$'tür (python ile kontrol edildi).

## 13. Sistem Modelleme Üzerine

Ayrık ya da sürekli zamanlı her sistem (sıcaklık sistemi, hız sistemi vb.) önce kâğıt üzerinde blok diyagramlarla modellenir. Slayttaki kontrol sistemi örneğinde (benzer bir diyagram ekrandan, 03:05:00) bir giriş, bir çıkış ve geri besleme vardır. Kontrol sistemleri geri beslemeli olmak zorundadır; haberleşme sistemlerinde geri besleme bulunmayabilir. Geri besleme sayesinde sistem hedeflenen bir değere (sıcaklık, çamaşır makinesinde dönüş hızı) ulaşana kadar çalışır. Kararlılığı, sıfır ve kutupları, kritik noktaları bulmak için giriş-çıkış ilişkisi, yani transfer fonksiyonu elde edilir. Diyagramdaki bloklar $s$ cinsinden yazılır; iş Laplace dönüşümü üzerinden yürür.

Çıkış geri yansıtılıp hedeften çıkarılır. Hoca bunu yapay sinir ağlarındaki hata hesabına benzetti (ekrandan, 02:30:00): $E=(T-O)^2$, yani hedef ($T$) ile çıkış ($O$) farkının karesi. Bu hataya bağlı olarak ağın ya da makine öğrenmesi algoritmasının parametreleri güncellenir.

Hoca ayrıca bir açma-kapama (on-off) kontrolörünü örnek verdi: evdeki kombilerdeki gibi sıcaklık belli bir değerin üstüne çıkınca soğutucu, altına inince ısıtıcı açılır. Sistemin zamana bağlı modeli yazılır, Laplace dönüşümüyle nerede sonsuza nerede sıfıra gittiği incelenir. Mikrodenetleyici ve FPGA ile çalışanlar sistemi MATLAB'da çözer, MATLAB çözümü otomatik olarak koda dönüştürüp çipe gömer. Asıl iş, sistemi doğru temsil eden denklemi kurmaktır. Bilgisayar mühendisliğinde daha çok ayrık zamanla uğraşılır; Laplace'taki sıfır ve kutuplar ya da Fourier'deki frekans değerleri müzik, ses ve görüntü işlemede ayırt edici özellikler olarak karşımıza çıkar.

### 13.1 Ses üretim modeli ve LPC

İnsan ses üretim mekanizması (ciğerlerden gelen hava, ses yolu, vocal tract) sayısal olarak modellenebilir. Bu ayrık zamanlı model, insandaki sürekli zamanlı ses üretiminin bir kopyası gibidir ve transfer fonksiyonu z-dönüşümü cinsinden hesaplanır; slaytta $z$'li ifadeler bu yüzden görülür. Ses sentezi (ör. toplu taşımadaki anonslar) bu fikirden geliştirilmiştir. Doğrusal öngörülü kodlama (Linear Predictive Coding, LPC) yönteminde ters z-dönüşümü kullanılarak katsayılar bulunur. Hoca kaydedilmiş bir "a" sesinin dalga biçimini ve LPC katsayılarını gösterdi: sesi çıkarırken gırtlağa yüklenme bir yükselme, sonra bir düşme olarak görünür; ses iki kez vurgulanırsa dalga biçiminde ikinci küçük bir artış görülür. Bu katsayılar sesleri ayırt etmek ve konuşmayı yazıya dönüştürmek için özellik olarak kullanılabilir. Hoca bütün bu örneklerde bir fark işlemi bulunduğunu vurguladı.

## 14. Fark Denklemleri ve Transfer Fonksiyonu

Haberleşmede AM, FM ve faz modülasyonunda da fark işlemleri vardır. Fark denklemi aslında türevden başka bir şey değildir: $Y(z)$'nin bir birim gecikmiş hali $y[n-1]\leftrightarrow z^{-1}Y(z)$'dir. Bir sistemin fark denklemi verilirse, sistemin $n$'e bağlı denklemi z-dönüşümü ve ters dönüşümüyle bulunur. Bu konunun bir benzeri ayrık matematikte özyinelemeli fonksiyonların analizinde, özyinelemeli bağıntılar (recurrence relation) olarak görülür.

### 14.1 Örnek

$x[n]$ girişi $h[n]$ sistemine uygulanıp $y[n]$ çıkıyor. Daha önce bu konvolüsyonla yapılmıştı. Fark denklemi (ekrandan, 02:40:00):

$$y[n]-\tfrac12y[n-1]=x[n]+\tfrac13x[n-1].$$

İki tarafın z-dönüşümü alınır. Katsayılar dışarı çıkar; bir birim öteleme $z^{-1}$ ile yazılır:

$$Y(z)-\tfrac12z^{-1}Y(z)=X(z)+\tfrac13z^{-1}X(z).$$

Laplace'ta türev nasıl $s\,Y(s)$ oluyorsa, burada bir birim fark $z^{-1}Y(z)$ olur. Sistemin giriş-çıkış ilişkisini gösteren transfer fonksiyonu $Y(z)/X(z)$'dir; zaman düzleminde $h[n]$ denmişti, burada $H(z)$ denir:

$$H(z)=\frac{Y(z)}{X(z)}=\frac{1+\frac13z^{-1}}{1-\frac12z^{-1}}=\frac{1}{1-\frac12z^{-1}}+\frac13z^{-1}\cdot\frac{1}{1-\frac12z^{-1}}.$$

İlk parça bilinen bir kalıptır: $(1/2)^nu[n]$. Bu parçayı $\frac{z}{z-1/2}$ biçiminde de görmek mümkündür; işaret sağ yanlıdır. Fark denklemlerinde geçmişe yönelik terimler bulunduğu için $u[n]$ kalır. İkinci parçada $\frac13$ katsayıdır; $z^{-1}$ ile çarpma ise zamanda bir birim ötelemedir. Hoca önce bunu türev kuralıyla karıştırdı, sonra öteleme kuralı olduğunu düzeltti.

$$h[n]=\left(\tfrac12\right)^nu[n]+\tfrac13\left(\tfrac12\right)^{n-1}u[n-1].$$

Bu $h[n]$ sayesinde yeni bir giriş geldiğinde çıkış doğrudan bulunabilir. Çizilirse: ilk terim 1'den başlayıp her adımda yarıya düşer; ikinci terim $n=1$'den başlayan ek bir bileşendir. İkisinin toplamı sonsuzda sıfıra yaklaşır. Sonuç, fark denkleminin özyinelemeli çözümüyle karşılaştırılarak python ile kontrol edildi ($h[0..3]=1,\ 0.8333,\ 0.4167,\ 0.2083$).

### 14.2 DTFT ile çözülen kitap örneği

Hoca daha önce sınav öncesi için hazırladığı bir kitap örneğini gösterdi (ekrandan, 02:45:00). Örnekte nedensel bir LTI sistem $y[n]-\frac34y[n-1]+\frac18y[n-2]=2x[n]$ fark denklemiyle verilir ve DTFT ile çözülür. $e^{-j\Omega}$ ile çarpma, $z^{-1}$ ile çarpmanın karşılığıdır. Örnekte "frekans cevabı" denir; transfer fonksiyonu denmez ama yapılan iş aynıdır. Ayrıntılar ve z-dönüşümüyle çözümü "Örnek Sorular" bölümündedir.

## 15. Alıştırmalar ve z-Dönüşümüyle Konvolüsyon

Hoca ders notlarında unuttuğu bir şey olup olmadığını kontrol ederken birkaç alıştırma verdi. Alıştırmaların metni ve çözümleri "Örnek Sorular" bölümündedir: $x[n]=(0.5^n+2)u[n]$'nin z-dönüşümü, Bölüm 12.2'deki ötelemeli ters dönüşüm ve üç kutuplu bir ters dönüşüm.

### 15.1 z-dönüşümüyle konvolüsyon

Bir dizi verilip z-dönüşümü sorulursa tanımda yerine konur. İki dizi verilip konvolüsyonları sorulursa z-dönüşümleri çarpılır (ekrandan, 03:00:00):

$$X(z)=z^{-1}+2z^{-2},\qquad Y(z)=1+z^{-3}.$$

$$X(z)Y(z)=z^{-1}+2z^{-2}+z^{-4}+2z^{-5}\;\Rightarrow\;\delta[n-1]+2\delta[n-2]+\delta[n-4]+2\delta[n-5].$$

Doğrudan konvolüsyonla kontrol: $X(z)$'nin ters dönüşümü $\delta[n-1]+2\delta[n-2]$, katsayıları $n=0,1,2$ için $0,1,2$; $Y(z)$'ninki $\delta[n]+\delta[n-3]$, katsayıları $n=0..3$ için $1,0,0,1$. Hoca bu sırada $\delta[n-3]$'ün katsayısını yanlışlıkla 3 yazdı ve sonuçlar tutmadı; bir öğrenci katsayının 1 olduğunu gösterdi. Düzeltilince kaydırmalı yöntem de $0,1,2,0,1,2$ ($n=0..5$) verir; iki yöntemin sonucu aynıdır (python ile kontrol edildi).

**Soru:** İkinci dizide $n-3$ teriminin katsayısı yok, ama konvolüsyonda 3 yazılıyor; sorun orada olabilir mi?

**Cevap:** Evet; $\delta[n-3]$'ün katsayısı 1'dir. Düzeltilince iki yöntem aynı sonucu verdi.

## 16. Slaytlardan: Gecikme, Kaskat Sistemler, Frekans Cevabı ve Filtreler

Hoca ardından z-dönüşümü slaytlarından hızlıca geçti.

- $0.8^nu[n]$ işareti 1'den başlayıp azalır; dönüşümü $\frac{z}{z-0.8}$'dir. Bu, başta verilen seri toplamından bulunur; $z$ ile çarpılınca daha kompakt görünür.
- Slayttaki bir örnekte iş tersten yapılır: dönüşüm verilir, $x[n]$ çizilir. Hoca böyle iki aşamalı bir sorunun sorulabileceğini söyledi: ters dönüşümü bulup ilk 5 terimi çizmek (ör. $0,\ 1,\ -1.2,\ 1.44,\dots$ gibi değerler, hesap makinesiyle). <!-- BELİRSİZ: Slayttaki örneğin dönüşüm ifadesi karede görülmedi; değerler altyazıdan alındı. -->
- **Birim gecikme:** Bir işareti $\delta[n-1]$ ile konvolüsyona sokmak bir birim gecikmedir. Bunun yerine dönüşüm $z^{-1}$ ile çarpılıp ters dönüşüm alınır; sonuç bir birim kayar.
- **Kaskat sistemler:** İki LTI sistem ardışık bağlanınca zamanda konvolüsyon gerekir; z düzleminde $H(z)=H_1(z)H_2(z)$ ile birleştirilir (ekrandan, 03:05:00). Geri beslemeli kontrol diyagramında da bloklar çarpılıp toplanarak tek bir denkleme indirilir.
- **Frekans cevabı:** $H(z)$'de $z$ yerine $e^{j\Omega}$ konursa frekans cevabı bulunur; tersine, frekans cevabında $e^{-j\Omega}$ yerine $z^{-1}$ konursa ayrık zamanlı sistemin transfer fonksiyonu elde edilir. Kutuplar ve sıfırlar paydayı ve payı sıfıra eşitleyerek bulunur.
- **Üç düzlem:** Slayttaki üçgende (ekrandan, 03:10:00) aynı $\{b_k\}$ katsayıları üç düzlemde görülür: zaman düzleminde $y[n]=\sum_{k=0}^{M}b_kx[n-k]$, frekans düzleminde $H(e^{j\hat\omega})=\sum_{k=0}^{M}b_ke^{-j\hat\omega k}$, z düzleminde $H(z)$ polinomu.
- **Filtreler:** Filtrelemek konvolüsyon yapmaktır. Alçak ya da yüksek frekansları geçiren bir filtrenin dönüşümü işaretin dönüşümüyle çarpılır, ters dönüşüm alınır. Çalışan toplam (running sum) işaretin başından itibaren değerleri toplar. Nulling filtre istenmeyen bir frekansı sıfırlar: z düzleminde o frekansa karşılık gelen nokta sıfır yapılıp ters dönüşüm alınınca o frekans kaybolur. Örneğin bir ses kaydına 100 Hz'lik bir sinüs eklenip Fourier dönüşümünde 100 Hz'teki genlik sıfırlanırsa ve ters dönüşüm alınırsa eski sese dönülür.
- **Çalışan ortalama (running average):** Bir sinyalde gürültü varsa, ayrık örnekler üçerli, beşerli pencerelerle ortalanarak ilerlenir; gürültü yok olur, işaret düzleşir. Görüntü işlemede ortalama (mean) ve medyan filtre iki boyutlu bir matris gezdirerek tuz-biber (salt and pepper) gürültüsünü temizler. Görüntü düzenleme programlarındaki medyan filtre de aynı algoritmayı kullanır.

Hoca filtrelerle ilgili kısımların dersin kapsamını aştığını, z-dönüşümü ve ters z-dönüşümü örneklerinin çalışmak için yeterli olduğunu söyledi: bunların hepsi ya üstel, ya $u$'lu ya da deltalı ifadelere dönüşür.

## 17. Laplace Dönüşümü Örnekleri

Dersin son kısmında hoca bir önceki derste yetişmeyen Laplace örneklerini kitaptan çözdü. Örneklerin metni ve çözümleri "Örnek Sorular" bölümündedir (Soru 10, 11 ve 12). Anlatımda öne çıkan noktalar şunlardır:

- Pay ve paydada $s+4$ gibi ifadeler sadeleşmez; doğrudan basit kesirlere ayrılır.
- Katsayı bulmanın kısa yolu: $C_1$ için onun paydasını sıfırlayan kök ($s=-1$) yerine konur ve o çarpan "kapatılır".
- Bir kutbun sağında kalan ROC o terim için sağ yanlı ($u(t)$), solunda kalan ROC sol yanlı ($-u(-t)$) işaret verir.
- $H(s)$ bulunurken birim basamak girişi sisteme "röntgen çekmek" gibidir: sistemin davranışını ortaya çıkarır.
- Tek taraflı Laplace'ta türev kuralı ardışık uygulanır: $y'$ yeni bir fonksiyon gibi düşünülür. Kuraldan gelen $s$, denklemdeki sabit katsayıyla karıştırılmamalıdır.

> **Hocanın vurgusu:** $h(t)=2\delta(t)-6e^{-3t}u(t)$ için $t=10$ anındaki değer sorulduğunda $\delta(10)=0$'dır; öğrenciler sık sık $\delta(10)$'u 1 alıp yanlış sonuç bulur. Sonuç $-6e^{-30}$'dur.

## Örnek Sorular

**Soru 1** (ekrandan, 01:05:00): $x[n]=2^nu[n]$ işaretinin yakınsama bölgesi (ROC) nedir?

> **Çözüm:** $\sum_{n\ge0}|2^nr^{-n}|=\sum_{n\ge0}(2r^{-1})^n$ ancak $2/r<1$ iken sonludur. ROC: $|z|>2$; $X(z)=\frac{1}{1-2z^{-1}}$.

**Soru 2** (ekrandan, 01:45:00): $x[n]=7(1/3)^nu[n]-6(1/2)^nu[n]$ işaretinin z-dönüşümünü bulun; sistem kararlı mıdır?

> **Çözüm:** $X(z)=\frac{z(z-3/2)}{(z-1/2)(z-1/3)}$, kutuplar $1/3$ ve $1/2$, sıfırlar $0$ ve $3/2$, ROC $|z|>1/2$. Bütün kutuplar birim çemberin içinde olduğundan kararlıdır.

**Soru 3** (ekrandan, 01:45:00): $\delta[n]$, $5\delta[n-3]$ ve $3\delta[n+2]$ işaretlerinin z-dönüşümleri nedir?

> **Çözüm:** Sırasıyla $1$, $5z^{-3}$ ve $3z^{2}$. Toplamları için doğrusallıkla $1+5z^{-3}+3z^{2}$.

**Soru 4** (ekrandan, 02:20:00): $X(z)=\dfrac{3-\frac56z^{-1}}{(1-\frac14z^{-1})(1-\frac13z^{-1})}$, $|z|>1/3$ ise $x[n]$ nedir?

> **Çözüm:** $A=1$, $B=2$; $x[n]=(1/4)^nu[n]+2(1/3)^nu[n]$ (ayrıntı Bölüm 12.1).

**Soru 5** (ekrandan, 02:45:00): Nedensel bir LTI sistem $y[n]-\frac34y[n-1]+\frac18y[n-2]=2x[n]$ ile veriliyor. (a) Dürtü cevabını, (b) $x[n]=(1/4)^nu[n]$ girişine cevabı bulun. Kitapta DTFT ile çözülmüş; hoca z-dönüşümüyle çözmeyi alıştırma olarak verdi.

> **Çözüm (kitapta DTFT ile; z-dönüşümü karşılığı derste verilmedi):** $H(z)=\dfrac{2}{1-\frac34z^{-1}+\frac18z^{-2}}=\dfrac{2}{(1-\frac12z^{-1})(1-\frac14z^{-1})}=\dfrac{4}{1-\frac12z^{-1}}-\dfrac{2}{1-\frac14z^{-1}}$, ROC $|z|>1/2$ (nedensel). $h[n]=4(1/2)^nu[n]-2(1/4)^nu[n]$.
>
> $X(z)=\dfrac{1}{1-\frac14z^{-1}}$ olduğundan $Y(z)=\dfrac{2}{(1-\frac12z^{-1})(1-\frac14z^{-1})^2}=-\dfrac{4}{1-\frac14z^{-1}}-\dfrac{2}{(1-\frac14z^{-1})^2}+\dfrac{8}{1-\frac12z^{-1}}$.
>
> $y[n]=\left[-4\left(\tfrac14\right)^n-2(n+1)\left(\tfrac14\right)^n+8\left(\tfrac12\right)^n\right]u[n]$. Kitaptaki sonuçla aynıdır; fark denkleminin özyinelemeli çözümüyle python ile kontrol edildi ($y[0..3]=2,\ 2,\ 1.375,\ 0.8125$).

**Soru 6** (ekrandan, 02:50:00): $x[n]=(0.5^n+2)u[n]$ işaretinin z-dönüşümünü ve ROC'sini bulun.

> **Çözüm (derste verilmedi):** İçeri dağıtılır: $0.5^nu[n]+2u[n]$. $X(z)=\dfrac{1}{1-0.5z^{-1}}+\dfrac{2}{1-z^{-1}}$. ROC'ler $|z|>0.5$ ve $|z|>1$'in kesişimi: $|z|>1$.

**Soru 7** (ekrandan, 02:50:00): $X(z)=\dfrac{z^{-4}}{z-1}+z^{-6}+\dfrac{z^{-3}}{z+0.5}$ ise $x[n]$ nedir?

> **Çözüm:** $x[n]=u[n-5]+\delta[n-6]+(-0.5)^{n-4}u[n-4]$ (ayrıntı Bölüm 12.2; tanım toplamıyla python ile kontrol edildi).

**Soru 8** (derste sözlü, 02:52:48): Hoca çalışmak için üç kutuplu bir ters z-dönüşümü verdi: basit kesirlere ayırıp katsayıları bulun, bilinen dönüşümler cinsinden yazın. Söylenen sonucun bir kısmı: $\dots+14\cdot2^nu[n]-15\,u[n]$. <!-- BELİRSİZ: İfade altyazıda "10 çarpı n çarpı z artı 5 bölü z eksi 1, z eksi 2, z artı 3" diye geçiyor ve karede görülmedi; söylenen 14 ve -15 katsayılarını veren biçim $X(z)=\frac{10z(z+5)}{(z-1)(z-2)(z+3)}$'tür. -->

> **Çözüm (derste verilmedi):** $X(z)=\dfrac{10z(z+5)}{(z-1)(z-2)(z+3)}$ alınırsa (sağ yanlı varsayımıyla) $\dfrac{X(z)}{z}=\dfrac{-15}{z-1}+\dfrac{14}{z-2}+\dfrac{1}{z+3}$, dolayısıyla $x[n]=(-3)^nu[n]+14\cdot2^nu[n]-15\,u[n]$. Katsayılar hocanın söylediği 14 ve $-15$ ile uyuşur; sonuç python ile kontrol edildi.

**Soru 9** (ekrandan, 03:00:00): $X(z)=z^{-1}+2z^{-2}$ ve $Y(z)=1+z^{-3}$ ise karşılık gelen dizilerin konvolüsyonu nedir?

> **Çözüm:** $X(z)Y(z)=z^{-1}+2z^{-2}+z^{-4}+2z^{-5}$; konvolüsyon $\delta[n-1]+2\delta[n-2]+\delta[n-4]+2\delta[n-5]$, yani $n=0..5$ için $0,1,2,0,1,2$.

**Soru 10** (ekrandan, 03:30:00): $X(s)=\dfrac{2s+4}{s^2+4s+3}$ için ters Laplace dönüşümünü (a) $\mathrm{Re}\{s\}>-1$, (b) $\mathrm{Re}\{s\}<-3$, (c) $-3<\mathrm{Re}\{s\}<-1$ durumlarında bulun.

> **Çözüm:** $X(s)=\dfrac{2(s+2)}{(s+1)(s+3)}=\dfrac{C_1}{s+1}+\dfrac{C_2}{s+3}$. $s=-1$: $C_1=\frac{2(1)}{2}=1$; $s=-3$: $C_2=\frac{2(-1)}{-2}=1$. Sıfır $s=-2$, kutuplar $-1$ ve $-3$.
>
> (a) Sağ yanlı: $x(t)=e^{-t}u(t)+e^{-3t}u(t)$.
>
> (b) Sol yanlı: $x(t)=-e^{-t}u(-t)-e^{-3t}u(-t)$.
>
> (c) $-1$'e göre sol yanlı, $-3$'e göre sağ yanlı: $x(t)=-e^{-t}u(-t)+e^{-3t}u(t)$.

**Soru 11** (ekrandan, 03:35:00): Sürekli zamanlı bir LTI sisteme $x(t)=u(t)$ uygulanınca çıkış $y(t)=2e^{-3t}u(t)$ oluyor. (a) $h(t)$'yi bulun. (b) Giriş $x(t)=e^{-t}u(t)$ olursa çıkış nedir?

> **Çözüm:** (a) $Y(s)=\dfrac{2}{s+3}$, $X(s)=\dfrac1s$, $H(s)=\dfrac{Y(s)}{X(s)}=\dfrac{2s}{s+3}$. ROC $\mathrm{Re}\{s\}>-3$ (sağ yanlı). Polinom bölmesiyle $H(s)=2-\dfrac{6}{s+3}$, dolayısıyla $h(t)=2\delta(t)-6e^{-3t}u(t)$. $t=10$'da $h(10)=-6e^{-30}$.
>
> (b) $X(s)=\dfrac{1}{s+1}$, $\mathrm{Re}\{s\}>-1$. $Y(s)=\dfrac{2s}{(s+3)(s+1)}=-\dfrac{1}{s+1}+\dfrac{3}{s+3}$, ROC $\mathrm{Re}\{s\}>-1$. $y(t)=\left(-e^{-t}+3e^{-3t}\right)u(t)$.

**Soru 12** (ekrandan, 03:50:00): $y''(t)+5y'(t)+6y(t)=x(t)$, $y(0)=2$, $y'(0)=1$, $x(t)=e^{-t}u(t)$ ise $y(t)$ nedir?

> **Çözüm:** Başlangıç koşulları verildiği için tek taraflı Laplace: $y''\to s^2Y(s)-2s-1$, $5y'\to5(sY(s)-2)=5sY(s)-10$, $6y\to6Y(s)$, $X(s)=\frac{1}{s+1}$ ($\mathrm{Re}\{s\}>-1$).
>
> $Y(s)(s^2+5s+6)-2s-11=\dfrac{1}{s+1}\;\Rightarrow\;Y(s)=\dfrac{1}{(s+1)(s+2)(s+3)}+\dfrac{2s+11}{(s+2)(s+3)}=\dfrac{1/2}{s+1}+\dfrac{6}{s+2}-\dfrac{9/2}{s+3}$.
>
> $y(t)=\left(\tfrac12e^{-t}+6e^{-2t}-\tfrac92e^{-3t}\right)u(t)$. Derste önce $5y'$ teriminin dönüşümü yanlış yazıldı; öğrencilerin uyarısıyla $-2s-11$ terimi düzeltildi. Sonuç denklemi ve başlangıç koşullarını sağlar (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste önce Laplace dönüşümünün neden gerektiği, ROC, sıfır-kutup diyagramı, özellikleri ve diferansiyel denklem çözümündeki kullanımı tekrar edildi. Ardından ayrık zamanda DTFT'nin aynı sorununu çözen z-dönüşümü tanımlandı: $X(z)=\sum x[n]z^{-n}$, $z=re^{j\Omega}$. Geometrik seri yardımıyla temel çiftler ve ROC'ler bulundu; sağ yanlı dizilerde ROC'nin en büyük kutbun dışında, sol yanlı dizilerde en küçük kutbun içinde olduğu, ROC birim çemberi içerirse DTFT'nin var olduğu ve sistemin kararlı olduğu gösterildi. Doğrusallık, öteleme, ölçekleme, ters çevirme, konvolüsyon, $z$'de türev, ilk ve son değer teoremleri ile z-dönüşüm tablosu verildi.

Ters z-dönüşümü basit kesirlere ayırma ve öteleme kuralıyla çözüldü; fark denklemlerinden transfer fonksiyonu ve dürtü cevabı elde edildi; konvolüsyonun z düzleminde polinom çarpımına dönüştüğü gösterildi. Kontrol sistemleri, ses üretim modeli ve filtreler gibi uygulamalarla dönüşümlerin sistem modellemedeki yeri anlatıldı. Ders, kitaptan çözülen Laplace örnekleriyle (farklı ROC'ler için ters dönüşüm, basamak cevabından dürtü cevabı, başlangıç koşullu ikinci mertebe diferansiyel denklem) bitti. Bu ders dönemin son konusuydu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
