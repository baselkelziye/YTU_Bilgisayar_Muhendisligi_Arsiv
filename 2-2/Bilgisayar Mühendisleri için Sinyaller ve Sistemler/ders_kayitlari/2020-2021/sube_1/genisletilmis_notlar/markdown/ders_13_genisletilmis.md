# Ders 13 Genişletilmiş Notu: Laplace Dönüşümünün Özellikleri, Yakınsama Bölgesi Kuralları, Diferansiyel Denklem Çözümü ve Kısmi Kesirler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Aynı Laplace Dönüşümü, İki Farklı Sinyal
- 2. Sol Taraflı, Sağ Taraflı ve İki Taraflı Sinyaller
- 3. İki Kutuplu Bir Örnek
- 4. Laplace Dönüşümünün Özellikleri
- 5. Ters Laplace Dönüşümü ve Slayttaki Özellik Listesi
- 6. Sistem Çıkışının Bulunması
- 7. Birinci Dereceden Sistem: RC Devresi
- 8. Tek Taraflı Dönüşümde Yüksek Dereceli Türevler
- 9. İkinci Dereceden Sistemlerin Genel Hâli
- 10. Kısmi Kesirlere Ayırma
- 11. Genel Akış: Sıfır Giriş, Sıfır Durum, Geçici ve Kalıcı Cevap
- 12. Slayttaki Kısmi Kesir Örnekleri ve Rezidüler
- 13. Kutuplar, Sıfırlar ve Frekans Cevabı
- 14. Kararlılık ve Nedensellik
- 15. İkinci Dereceden Diferansiyel Denklem Örneği
- 16. Yakınsama Bölgesi Örnekleri
- 17. Yakınsama Bölgesiyle Ters Dönüşüm Örneği
- 18. İkinci Dereceden Çarpanlı Kısmi Kesir Örneği
- 19. Soru: İşareti ve Basamak Fonksiyonunu Neye Göre Seçtik?

## 1. Aynı Laplace Dönüşümü, İki Farklı Sinyal

Hoca, bir önceki derste Laplace dönüşümüne ve özelliklerine giriş yapıldığını hatırlatarak başladı. Bu derste hem özelliklere hem de dönüşümün uygulama alanlarına bakılacaktı. Hatırlatma olarak iki sinyalin dönüşümünü tanımdan hesapladı. Amacı, iki farklı sinyalin aynı cebirsel sonucu verebileceğini göstermekti.

### 1.1 Birinci Sinyal: $x(t) = -e^{-at}u(-t)$

Dönüşümün tanımında integral $-\infty$'dan $+\infty$'a alınır. Eksi işareti integralin dışına atılır:

$$X(s) = -\int_{-\infty}^{\infty} e^{-at}\,u(-t)\,e^{-st}\,dt$$

$u(-t)$ çarpanı yalnız $t < 0$ için 1 olduğundan sinyal $-\infty$'dan $0$'a doğru gelir. Yapılacak ilk iş budur: alt sınır $-\infty$, üst sınır $0$ olur. Sonra üsler $-t$ ortak parantezine alınır:

$$X(s) = -\int_{-\infty}^{0} e^{-(s+a)t}\,dt = -\left[\frac{e^{-(s+a)t}}{-(s+a)}\right]_{-\infty}^{0} = \frac{1}{s+a}\left[e^{-(s+a)t}\right]_{-\infty}^{0}$$

İki eksi birbirini götürür. Sınırlar yerine yazılır: $t = 0$ için köşeli parantezdeki ifade $1$, $t = -\infty$ için $0$ olur. Sonuç:

$$X(s) = \frac{1}{s+a}$$

### 1.2 İkinci Sinyal: $x(t) = e^{-at}u(t)$

Bu kez $u(t)$ yüzünden integral $0$'dan $\infty$'a alınır:

$$X(s) = \int_{0}^{\infty} e^{-at}e^{-st}\,dt = \int_{0}^{\infty} e^{-(s+a)t}\,dt = \frac{1}{-(s+a)}\left[e^{-(s+a)t}\right]_{0}^{\infty}$$

$t = \infty$ için üstel terim $0$, $t = 0$ için $1$ olur. Yani parantez $0 - 1 = -1$ çıkar ve eksiler sadeleşir:

$$X(s) = \frac{1}{s+a}$$

Hoca bu noktada şuna dikkat çekti: iki sinyal farklı, ama Laplace dönüşümleri aynı.

> **Hocanın vurgusu:** Ters dönüşüm yaparken yalnız $X(s)$ ifadesiyle hangi sinyali elde edeceğimizi bilemeyiz. Tabloda iki değer olmalıdır: $X(s)$ ve yakınsama bölgesi (Region of Convergence, ROC).

### 1.3 Yakınsama Bölgesinin Çıkarılması

Şart, integralin sonsuza gitmemesidir. İkisini sırayla inceleyelim.

**İkinci sinyal (sınır $+\infty$).** $t = +\infty$ yazıldığında üssün $-\infty$ olması gerekir ki $e^{-\infty} = 0$ bulunsun. Üs $-(s+a)t$ olduğuna göre $s+a$'nın gerçel kısmı pozitif olmalıdır. Aksi hâlde integral artı sonsuza gider. $s = \sigma + j\omega$ olduğundan $\mathrm{Re}(s) = \sigma$'dır:

$$\mathrm{Re}(s+a) > 0 \quad\Rightarrow\quad \sigma > -a$$

**Birinci sinyal (sınır $-\infty$).** Burada $t = -\infty$ yazıldığında yine üssün $-\infty$ olması gerekir. $t$ negatif olduğundan bu kez $s+a$'nın gerçel kısmı negatif olmalıdır:

$$\mathrm{Re}(s+a) < 0 \quad\Rightarrow\quad \sigma < -a$$

Birinde neden pozitif, ötekinde neden negatif şartı çıktı sorusunun cevabı sınırların farklı olmasıdır: Birinde $-\infty$, ötekinde $+\infty$ vardır. Ayırt edici olan da $\sigma$ değeridir. Bir ters dönüşümde $\sigma < -a$ verilmişse sinyal $-e^{-at}u(-t)$, $\sigma > -a$ verilmişse $e^{-at}u(t)$'dir.

### 1.4 s-Düzleminde Gösterim ve Fourier Dönüşümü

Hoca iki durumu s-düzleminde (S-plane) çizdi. Yatay eksen $\sigma$, dikey eksen $j\omega$ eksenidir. $-a$ noktası her iki çizimde de aynı yerdedir. Birinci durumda ROC bu noktanın solu, ikinci durumda sağıdır.

<!-- BELİRSİZ: 00:12:27'de altyazıda "eksi a bizim pozitif sayımız" geçiyor. Devamındaki Fourier yorumu ancak a pozitifken, yani -a noktası dikey eksenin solundayken tutuyor. Not bu kabulle yazıldı. -->

Hoca sınıfa, iki durumdan hangisinde Fourier dönüşümünün Laplace dönüşümüne eşit olduğunu sordu. Şart, ROC'un dikey ekseni ($j\omega$ eksenini) kapsamasıdır. İkinci durumda ROC dikey ekseni kapsar. Bu nedenle ikinci sinyal için hem Fourier hem Laplace dönüşümü alınabilir ve ikisi eşittir.

### 1.5 $\sigma = -a$ Durumu: Kutup

Hoca üçüncü bir durum olarak $\sigma = -a$ noktasını ele aldı. Bu değer sistemin paydasını sıfır yapar. Paydayı sıfır yapan değerlere kutup (pole) denir. Hoca bunun önemli bir kavram olduğunu, sistemin sıfırlarının da birazdan görüleceğini ve kutupları ile sıfırları inceleyerek kararlılık gibi özelliklerin kontrol edilebildiğini söyledi.

<!-- BELİRSİZ: 00:14:12 ile 00:15:07 arasında altyazı boşluğu var. Hocanın sigma = -a durumundaki hesabı okunamıyor. -->

> **Ders sonrası not:** Hoca kutbu bir yerde "Laplace dönüşümünün sonucunu sıfır yapan değer" diye andı. Doğrusu: kutup paydayı sıfır yapar, bu noktada $X(s)$ sonsuza gider.

> **Ek bilgi (derste anlatılmadı):** ROC hiçbir kutbu içermez. Kutupta $X(s)$ sonlu bir değer almadığından integral orada yakınsamaz. ROC'un sınırlarının kutuplardan geçmesi bundandır.

## 2. Sol Taraflı, Sağ Taraflı ve İki Taraflı Sinyaller

Hoca önce tanımları verdi:

- **Sol taraflı (left-sided) sinyal:** $e^{-at}u(-t)$ gibi, $t$'nin sıfırdan küçük değerleri için var olan sinyal.
- **Sağ taraflı (right-sided) sinyal:** $e^{-at}u(t)$ gibi, $t$'nin sıfırdan büyük değerleri için var olan sinyal.
- **İki taraflı (bilateral) sinyal:** $e^{at}$ gibi, $t$'nin bütün değerleri için tanımlı olan sinyal. Bu sinyal ne sağ ne sol taraflıdır.

Bu sinyaller, dönüşüm ve ROC bilgisi birleştirilince şu kural elde edilir.

> **Hocanın vurgusu:** $x(t)$ sol taraflıysa ROC en küçük kutbun solundadır. $x(t)$ sağ taraflıysa ROC en büyük kutbun sağındadır.

Bölüm 1'deki örnekler tek kutupludur. Tek kutup hem en büyük hem en küçük kutup olduğundan sağ taraflı sinyalde ROC onun sağı, sol taraflı sinyalde onun soludur.

Birden fazla kutup varsa kural daha anlamlı hâle gelir. Hoca örnek olarak şu dönüşümü yazdı:

$$X(s) = \frac{1}{(s-a)(s-b)(s-c)}$$

Burada üç kutup vardır: $a$, $b$ ve $c$. Önce sinyalin sağ taraflı mı sol taraflı mı olduğuna bakılır. Sağ taraflıysa ROC sayısal olarak en büyük kutbun sağında, sol taraflıysa en küçük kutbun solundadır. Bu iki durumda kutupların arasında bir ROC olmaz.

Hoca matematik tarafında sinyallerin daha çok en genel hâliyle, yani iki taraflı olarak incelendiğini, elektronik ve bilgisayar tarafında ise tek taraflı sinyallerle çalışıldığını söyledi. Bazı kurallar iki taraflı sinyallere, bazıları tek taraflı sinyallere uygundur. Önce iki taraflı gibi düşünülecek, devamı sonra getirilecektir.

> **Ek bilgi (derste anlatılmadı):** $e^{at}$ sinyali $e^{at}u(t) + e^{at}u(-t)$ biçiminde yazılabilir. Birinci terim $\sigma > a$, ikinci terim $\sigma < a$ şartını ister ($a$ gerçel). Bu iki bölge kesişmediği için $e^{at}$'nin Laplace dönüşümü yoktur. Aynı durum Bölüm 16'daki üçüncü örnekte de görülür.

## 3. İki Kutuplu Bir Örnek

Tek kutuplu sinyalden sonra iki kutuplu bir sinyal incelendi:

$$x(t) = 3e^{-2t}u(t) - 2e^{-t}u(t)$$

**Adım 1: Doğrusallık.** Toplama ve çıkarma üzerinde dağıtılır, her terimin dönüşümü ayrı alınır. Baştaki katsayılar dışarıda kalır.

$$3e^{-2t}u(t) \leftrightarrow \frac{3}{s+2},\quad \sigma > -2 \qquad\qquad -2e^{-t}u(t) \leftrightarrow \frac{-2}{s+1},\quad \sigma > -1$$

Hoca ROC'un integrali açarak da bulunabileceğini, ama paydayı sıfır yapan değerden de okunabileceğini söyledi.

**Adım 2: Payda eşitleme.** Sıfırları ve kutupları görmek için paydalar eşitlenir:

$$X(s) = \frac{3(s+1) - 2(s+2)}{(s+2)(s+1)} = \frac{3s + 3 - 2s - 4}{(s+1)(s+2)} = \frac{s-1}{(s+1)(s+2)}$$

**Adım 3: Sıfır-kutup diyagramı.** Paydayı sıfırlayan değerler kutuptur: $s = -1$ ve $s = -2$. Diyagramda çarpı ($\times$) ile gösterilir. Payı sıfırlayan değer sıfırdır: $s = 1$. Diyagramda küçük bir daire ile gösterilir.

**Adım 4: ROC.** İki terim de $t$'nin pozitif değerlerinde tanımlı olduğundan sinyal sağ taraflıdır. ROC en büyük kutbun sağındadır. En büyük kutup $-1$ olduğundan ROC $\sigma > -1$'dir.

**Adım 5: Fourier dönüşümü.** Bu ROC $j\omega$ eksenini içerir. Dolayısıyla sinyalin Fourier dönüşümü vardır.

Hoca bir sinyalin hem sağ hem sol taraflı parçalar da içerebileceğini söyledi: Örneğin birinci terimde $u(t)$, ikinci terimde $u(-t)$ olabilir. Bunun üzerinde burada fazla durmadı. Ders sonunda bu tür örnekler yine ele alındı (Bölüm 16).

## 4. Laplace Dönüşümünün Özellikleri

Hoca, geçen derste $e^{-at}$ ile çarpım ve $t$ ile çarpım kurallarının görüldüğünü, üstelle çarpımın s-düzleminde öteleme yaptığını hatırlattı ve özellikleri sınıfa sorarak geçti. Bu özellikler iki taraflı dönüşüm için yazılmıştır.

### 4.1 Zamanda Kayma (Time Shift)

$x(t)$ sinyalini $t_0$ kadar kaydırıp dönüşümünü almak için baştan integral hesaplamaya gerek yoktur. Bir öğrencinin de söylediği gibi:

$$x(t - t_0) \leftrightarrow e^{-st_0}X(s)$$

Yani s-düzleminde yalnızca bir çarpan eklenir.

### 4.2 s-Düzleminde Kayma

Bu kez tersten düşünülür. $s$ düzleminde $s_0$ kadar kayma, zaman düzleminde üstel bir çarpana karşılık gelir:

$$X(s - s_0) \leftrightarrow e^{s_0 t}x(t)$$

### 4.3 Konvolüsyon

Hoca, sürekli zamanda konvolüsyon integralinin daha önce uzun uzun anlatıldığını hatırlattı. Laplace dönüşümüyle aynı işlem çarpmaya dönüşür:

$$x_1(t) * x_2(t) \leftrightarrow X_1(s)\,X_2(s)$$

> **Ders sonrası not:** Hoca buradaki çarpmayı "vektörel çarpım" diye andı. İşlem sıradan çarpmadır: her $s$ değerinde iki karmaşık sayı çarpılır.

### 4.4 Türev

Hoca Fourier dönüşümünde türevin ne yaptığını sordu. Bir öğrenci $j\omega$ ile çarpıldığını söyledi. Laplace düzleminde $j\omega$'nın yerini $s$ aldığından:

$$\frac{dx(t)}{dt} \leftrightarrow s\,X(s)$$

### 4.5 İntegral

Bir fonksiyonun integrali başka bir fonksiyondur. $x(t)$'nin dönüşümü biliniyorsa integralini alıp yeniden dönüşüm hesaplamak gerekmez. $1/s$ ile çarpmak yeterlidir:

$$\int_{-\infty}^{t} x(\tau)\,d\tau \leftrightarrow \frac{1}{s}\,X(s)$$

> **Ders sonrası not:** Hoca integrali sözlü olarak "eksi sonsuzdan artı sonsuza" diye okudu. Bu özelliğin üst sınırı $t$'dir, integral $t$'nin bir fonksiyonudur.

### 4.6 Başlangıç Değer Teoremi (Initial Value Theorem)

Bir sistemi açtığınız anda, hatta açtıktan kısa bir süre sonra göreceğiniz değeri verir. $X(s)$ biliniyorsa $s$ ile çarpılır ve $s \to \infty$ limiti alınır:

$$x(0^+) = \lim_{s\to\infty} s\,X(s)$$

Zaman düzlemindeki sıfır anı, Laplace düzleminde sonsuzdaki değere karşılık gelir.

### 4.7 Son Değer Teoremi (Final Value Theorem)

Sistemin $t \to \infty$'da nasıl davranacağını görmek isteyebiliriz. $x(t)$'nin limitini hesaplamak yerine, elimizde $X(s)$ varsa yine $s$ ile çarpılır, ama bu kez $s \to 0$ limiti alınır:

$$x(\infty) = \lim_{s\to 0} s\,X(s)$$

Bir düzlemde sonsuz, öteki düzlemde sıfır değer bilgisi elde edilmiş olur.

> **Ders sonrası not:** Son değer teoremi yalnız $sX(s)$'nin bütün kutupları sol yarı düzlemdeyse geçerlidir, yani sinyal gerçekten bir değere oturuyorsa. Örneğin $e^{t}u(t)$ için $\lim_{s\to 0} s\cdot\frac{1}{s-1} = 0$ çıkar, ama sinyal sonsuza gider.

> **Hocanın vurgusu:** Bundan sonra integral özelliği belki o kadar kullanılmayacak. Ama türev, başlangıç değer ve son değer özellikleri çok kullanılacak.

## 5. Ters Laplace Dönüşümü ve Slayttaki Özellik Listesi

Bir problemi s-düzleminde çözdükten sonra zaman düzlemine dönmek gerekir. Bunun için ters Laplace dönüşümü alınır. Tanımdaki integral $2\pi j$ çarpanı içerir ve hesaplaması zordur:

$$x(t) = \frac{1}{2\pi j}\int_{\sigma - j\infty}^{\sigma + j\infty} X(s)\,e^{st}\,ds$$

Bunun yerine $s$ cinsinden ifade polinomların oranı olarak, basit kesirler biçiminde yazılır ve tablolardan doğrudan ters dönüşüm alınır. Hoca Bölüm 3'teki örneğe dönerek amacı gösterdi: Elimizde $\frac{s-1}{(s+1)(s+2)}$ varsa, onu $\frac{3}{s+2} - \frac{2}{s+1}$ biçimine getirecek işlemler yapılır. Bu, calculus derslerinde anlatılan basit kesirlere ayırma yöntemidir. $\frac{3}{s+2}$'nin $3e^{-2t}$'den geldiğini tablodan görürüz. $e$'li, sinüslü ve kosinüslü fonksiyonların dönüşümleri bilindiği için terslerini de söyleyebiliriz.

> **Ders sonrası not:** Hoca integrali "bir periyot boyunca eksi sonsuzdan" diye anlattı ve yöntemi "ters Fourier dönüşümü tablosu" diye andı. Ters Laplace integrali, ROC içindeki dikey bir doğru boyunca alınır, periyotla ilgisi yoktur. Kullanılan tablo da Laplace dönüşümü tablosudur.

Hoca slaytta özelliklerin listesini de geçti:

- **Doğrusallık:** İki sinyalin doğrusal birleşiminin dönüşümü ayrı ayrı hesaplanır.
- **Zamanda kayma:** $x(t-c) \leftrightarrow e^{-cs}X(s)$. Fourier dönüşümünde bunun karşılığı $e^{-j\omega c}$ idi.
- **Türev:** İki taraflı olduğu için türev yerine yalnızca $s$ çarpanı eklenir.
- **İntegral:** $1/s$ ile çarpılır.
- **Zaman ölçekleme (time scale):** $a > 0$ için $x(at) \leftrightarrow \frac{1}{a}X\!\left(\frac{s}{a}\right)$.
- **$t^n$ ile çarpma:** $t^n x(t) \leftrightarrow (-1)^n \frac{d^n X(s)}{ds^n}$.
- **Üstelle çarpma:** s-düzleminde kayma olur, Bölüm 4.2'deki kural.
- **Sinüzoidalle çarpma:** s-düzleminde $j\omega$ kadar öteleme demektir.

Türev ile integral birbirini karşılar: Biri $s$ ile çarpar, öteki $s$'e böler. Hoca, diferansiyel denklem çözerken bu özelliklerin işi çok kolaylaştırdığını belirtti.

$t^n$ ile çarpma biraz zordur, çünkü örneğin $t^5$ ile çarpılacaksa beş kez türev almak gerekir. Bu ek maliyet getirir. Sinüzoidalle çarpma ise çok kullanılan bir özellik değildir. Genellikle sinüzoidal işaret bulunup diğer özellikler üzerinden işlem yapılır.

> **Ders sonrası not:** Hoca sinüzoidalle çarpmayı kısaca "$j\omega$ kadar öteleme" diye anlattı. Tam ifadede iki yöne yarım genlikli iki öteleme vardır:
> $$x(t)\cos(\omega_0 t) \leftrightarrow \tfrac{1}{2}\left[X(s-j\omega_0) + X(s+j\omega_0)\right]$$
> $$x(t)\sin(\omega_0 t) \leftrightarrow \tfrac{1}{2j}\left[X(s-j\omega_0) - X(s+j\omega_0)\right]$$

## 6. Sistem Çıkışının Bulunması

$h(t)$ ya da $H(s)$ sistemin nasıl davrandığını söyler. $H(s)$ transfer fonksiyonudur. Girişin dönüşümü $X(s)$ ise çıkışın dönüşümü, s-düzleminde doğrudan çarpma ile bulunur:

$$Y(s) = X(s)\,H(s)$$

Bu çarpma, iki sinyalin konvolüsyonunu almaktır. Elimizde bir işaretin dönüşümü ve sistemin transfer fonksiyonu varsa, ikisini çarpıp ters Laplace dönüşümü aldığımızda sistemin çıkışı $y(t)$ elde edilir. Buradan diferansiyel denklemlerin Laplace dönüşümüyle çözümüne geçilir.

Hoca bir diferansiyel denklemin çözümünün iki parçası olduğunu, bu iki parça birleştirilince toplam çözümün bulunduğunu söyledi. Bu parçalar RC örneğinde görülecektir.

## 7. Birinci Dereceden Sistem: RC Devresi

### 7.1 Devre Denklemi ve Tek Taraflılık

RC devresi birinci dereceden bir devredir: Birinci mertebe türev içeren bir diferansiyel denklemle karakterize edilir.

$$\frac{dy(t)}{dt} + \frac{1}{RC}\,y(t) = \frac{1}{RC}\,x(t)$$

Bu sistem sağ taraflıdır, iki taraflı değildir. Bu yüzden türev kuralı değişir. Normalde birinci türevin dönüşümü $sY(s)$ idi, ama türevde sistemin $-\infty$'dan $0$'a kadarki değerleri de hesaba katılıyor. Sağ taraflı bir sistemde bunu çıkarmamız gerekir:

$$\frac{dy}{dt} \leftrightarrow sY(s) - y(0^-)$$

Hocanın anlatımıyla: Bir devreye enerji verdiğimizde, devrenin o andaki içindeki değerleri, yani başlangıç koşullarını çıkararak tek taraflı bir diferansiyel denklemi çözebiliriz. $y(0^-)$ üzerindeki eksi işareti, $t$'nin sıfırdan küçük olduğu tarafı anlatır.

> **Ek bilgi (derste anlatılmadı):** Bu kural kısmi integrasyondan gelir. $\int_{0^-}^{\infty} y'(t)e^{-st}dt = \left[y(t)e^{-st}\right]_{0^-}^{\infty} + s\int_{0^-}^{\infty} y(t)e^{-st}dt$ yazılır. ROC içinde üst sınır sıfır verir, alt sınır $-y(0^-)$ bırakır. Yani çıkarılan şey tüm geçmiş değil, geçmişi özetleyen tek değerdir: $y(0^-)$.

### 7.2 Diferansiyel Denklemden Cebirsel Denkleme

Genel model şudur: Bir diferansiyel denklemin Laplace dönüşümü alınır, $Y(s)/X(s)$ oranı bulunur ve sistemin nasıl davranacağı elde edilir.

> **Hocanın vurgusu:** Diferansiyel denklem çözmek zordur. Birinci dereceden tek bilinmeyenli cebirsel denklem çözmek çok kolaydır. Laplace dönüşümüyle diferansiyel denklemi $Y(s)$ cinsinden klasik bir cebirsel denkleme çeviriyoruz.

Denklem genel olarak $y' + a\,y = b\,x$ biçimindedir. Burada $a = b = \frac{1}{RC}$'dir. Toplama üzerinde dağıtılarak her terimin dönüşümü ayrı alınır:

$$sY(s) - y(0^-) + aY(s) = bX(s)$$

$Y(s)$ parantezine alınır, $y(0^-)$ karşıya atılır:

$$Y(s)(s+a) = bX(s) + y(0^-)$$

İki taraf $s+a$'ya bölünür:

$$Y(s) = \frac{y(0^-)}{s+a} + \frac{b\,X(s)}{s+a}$$

Birinci terim devredeki başlangıç koşuluna (initial condition), ikinci terim girişe bağlıdır.

$X(s)$'e devreye ne verildiyse onun Laplace dönüşümü yazılır. Sinüzoidal bir kaynak verilirse sinüzoidalin dönüşümü, 5 volt verilirse $5/s$ gelir. Hoca $x(t) = u(t)$ alınmasını önerdi: Bu, $t$'nin sıfırdan büyük olduğu yerde 1 olan, yani 1 voltluk sabit bir işarettir. Dönüşümü $X(s) = 1/s$'dir. Yerine yazılınca:

$$Y(s) = \frac{y(0^-)}{s + \frac{1}{RC}} + \frac{\frac{1}{RC}}{s\left(s + \frac{1}{RC}\right)}$$

$R$ direnç, $C$ kapasite değeridir. $y(0^-)$ de sistem daha açılmadan orada bulunan gerilim gibi verilen bir sabittir. Bunların hepsi sabit olduğundan geriye yalnız $s$'e bağlı ifadelerin ters dönüşümü kalır.

### 7.3 Sıfır Giriş Cevabı (Zero-Input Response)

Hoca birinci terimi anlamak için sabite $\mu$ dedi ve $\frac{\mu}{s + 1/RC}$'nin neyin dönüşümü olduğunu sordu. Bir öğrenci $\mu e^{-\frac{1}{RC}}$ dedi. Hoca bunun $t$'ye bağlı olacağını ekledi. $t > 0$ aralığı gösterildiği için $u(t)$ de yazılır:

$$\frac{y(0^-)}{s + \frac{1}{RC}} \quad\leftrightarrow\quad y(0^-)\,e^{-t/RC}\,u(t), \qquad \sigma > -\frac{1}{RC}$$

> **Ders sonrası not:** Hoca ROC'u "sigma değeri bir bölü RC'den büyük" diye söyledi. Kutup $-\frac{1}{RC}$'dedir ve doğrusu $\sigma > -\frac{1}{RC}$'dir.

Bu parça, sistem hangi başlangıç değerine sahipse oradan başlar ve sonsuzda azalıp gider. Kolay parça budur.

### 7.4 Sıfır Durum Cevabı (Zero-State Response)

İkinci terim daha zordur, çünkü tablolarda görülen bir biçimde değildir. $s$ içeri dağıtılırsa payda $s^2 + \frac{s}{RC}$ olur. Basit kesirlere ayrılır:

$$\frac{\frac{1}{RC}}{s\left(s + \frac{1}{RC}\right)} = \frac{1}{s} - \frac{1}{s + \frac{1}{RC}}$$

Doğrusallıktan iki kesrin tersi ayrı ayrı alınır. $1/s$, $u(t)$'nin dönüşümüdür. İkincisi de $e^{-t/RC}u(t)$'nin. Burada başlangıç değeri yoktur, çünkü bu parça yalnız sistemin girişine bağlıdır:

$$\left(1 - e^{-t/RC}\right)u(t)$$

Davranışı şöyle okunur: $t = 0$ için $1 - 1 = 0$, yani sıfırdan başlar. $t = \infty$ için $e^{-\infty} = 0$ olduğundan $1$'e gider. Sıfırdan başlayıp 1'e kadar artan bir grafik görülür.

### 7.5 Toplam Cevap

Birinci parçaya IC parçası (başlangıç koşulu), ikinci parçaya giriş parçası (input part) denir. Toplamları sistemin davranışını verir. Başlangıç değeri 5 ise:

$$y(t) = 5e^{-t/RC}u(t) + \left(1 - e^{-t/RC}\right)u(t) = \left(1 + 4e^{-t/RC}\right)u(t)$$

Slaytta parametreler yerine konmuştu. Sıfır giriş cevabı 5'ten başlayıp azalıyor, sıfır durum cevabı 0'dan başlayıp 1'e çıkıyordu. Toplam cevap yine 5'ten başlar. Fakat 0'a inmez. Belli bir noktaya gelir ve sistem orada oturur. Yukarıdaki ifadede bu değer 1'dir. Hoca önce azalmanın hızlandığını söyledi, sonra düzeltip yavaşladığını belirtti.

<!-- BELİRSİZ: Slayttaki değerler altyazıda bozuk ("VCE'ye 0.5 ... 5 voltluk"). Büyük olasılıkla RC = 0,5 ve başlangıç gerilimi 5 V. Bu değerlerle y(t) = 1 + 4e^(-2t) olur; Python ile sayısal çözümle doğrulandı. -->

Hoca, en karmaşık işlemin yalnızca bir basit kesirlere ayırma olduğunu, gerisinin Laplace özellikleriyle yapılan cebirsel işlem olduğunu söyleyerek birinci dereceden örneği kapattı.

## 8. Tek Taraflı Dönüşümde Yüksek Dereceli Türevler

Hoca aradan sonra konuyu genelleştirdi. Laplace dönüşümü genellikle diferansiyel denklem çözümünde ve sistemlerin nedensellik, kararlılık gibi özelliklerini incelemede kullanılır. Bu yüzden diferansiyel denklemlerin dönüşümünü iyi kurmak çok önemlidir.

İki taraflı dönüşümde iş kolaydır. Fourier dönüşümünde $j\omega$'nın kuvvetleri yazılıyordu, burada da $s$'in kuvvetleri yazılır: $y'' \leftrightarrow s^2Y(s)$, $y''' \leftrightarrow s^3Y(s)$. Gerçek hayattaki sistemlerde ise $t$'nin sıfırdan küçük değerleriyle uğraşmadığımız için tek taraflı (unilateral) kural kullanılır.

> **Hocanın vurgusu:** Bu formülleri uzun uzun ezberlemeye gerek yok. Mantık kolaydır: Her türevde $s$ ile çarp, o anda türevi alınan fonksiyonun $t = 0$ anındaki değerini çıkar.

**Birinci türev:**

$$y' \leftrightarrow sY(s) - y(0)$$

**İkinci türev.** $y'$ de bir fonksiyondur. Birinci türevin dönüşümü başına $s$ alır, sonra $y'$'nün sıfırdaki değeri çıkarılır:

$$y'' \leftrightarrow s\left[sY(s) - y(0)\right] - y'(0) = s^2Y(s) - s\,y(0) - y'(0)$$

**Üçüncü türev.** İkinci türevin dönüşümü başına $s$ alır, sonra $y''$'nün sıfırdaki değeri çıkarılır:

$$y''' \leftrightarrow s\left[s^2Y(s) - s\,y(0) - y'(0)\right] - y''(0) = s^3Y(s) - s^2y(0) - s\,y'(0) - y''(0)$$

Soruda $y(0)$, $y'(0)$, $y''(0)$ değerleri sabit sayı olarak verilir. Örneğin hoca "$y'(0) = 5$, $y''(0) = 0$, $y(0) = -3$ gibi" dedi. Bunlar doğrudan yerine yazılır. Değişken olan yalnız $Y(s)$'dir. Tek taraflı dönüşümü iki taraflıdan farklı kılan da sistemin önceki davranışının hariç tutulmasıdır.

## 9. İkinci Dereceden Sistemlerin Genel Hâli

Elektrik devrelerinde enerji depolayan iki eleman varsa, ya da bir sistemde böyle iki durum varsa, sistem genellikle ikinci dereceden bir diferansiyel denklemle ifade edilir:

$$y''(t) + a_1 y'(t) + a_0 y(t) = b_1 x'(t) + b_0 x(t)$$

Bunun için sistemin $t = 0$ anındaki değeri ve birinci türevinin $t = 0$ anındaki değeri gerekir. Gerçek bir devre olduğu için tek taraflı kural kullanılır:

$$s^2Y(s) - s\,y(0) - y'(0) + a_1\left[sY(s) - y(0)\right] + a_0Y(s) = b_1\left[sX(s) - x(0^-)\right] + b_0X(s)$$

Sağ taraftaki $x(0^-)$ için hoca şunu söyledi: $x$ nedensel (causal) bir sinyalse, yani $t < 0$ için $x(t) = 0$ ise $x(0^-) = 0$'dır. Slaytta bu nedenle yazılmamıştır. Giriş nedensel değilse bu değer yine yazılır, kural aynıdır.

Geriye cebirsel işlem kalır. $a_1$, $a_0$, $b_1$, $b_0$ ve başlangıç değerleri sabittir. $X(s)$ ve $Y(s)$ ise $s$'e bağlıdır. $Y(s)$ yalnız bırakılınca bir kısmı başlangıç koşullarından, bir kısmı $X(s)$'ten gelen iki parça çıkar (ara adım eklendi):

$$Y(s) = \frac{(s + a_1)\,y(0) + y'(0)}{s^2 + a_1 s + a_0} + \frac{b_1 s + b_0}{s^2 + a_1 s + a_0}\,X(s)$$

Hoca bunun ilk bakışta zor geldiğini, ama örnekle çözülünce gayet basit olduğunu söyledi. Ters dönüşümü alabilmek için ifadenin olabildiğince basit kesirlere ayrılması gerekir. Önce bu yönteme bakıldı.

## 10. Kısmi Kesirlere Ayırma

Hoca bunun calculus'te anlatıldığını belirterek hızlıca geçti. Mantık payda eşitlemeyi tersten düşünmektir.

### 10.1 Birinci Durum: Farklı Kökler

$$\frac{F(s)}{(s-a)(s-b)(s-c)} = \frac{A}{s-a} + \frac{B}{s-b} + \frac{C}{s-c}$$

Büyük $A$, $B$, $C$ sabit sayılardır, çünkü her paydanın kendisi birinci derecedendir. Paydalar eşitlenip sadeleştirilince:

$$F(s) = A(s-b)(s-c) + B(s-a)(s-c) + C(s-a)(s-b)$$

Burada $s = a$ yazılırsa ikinci ve üçüncü terimler sıfır olur, yalnız büyük $A$ kalır. $s = b$ yazılırsa büyük $B$, $s = c$ yazılırsa büyük $C$ bulunur.

Bulunan her kesrin tersi üstel bir fonksiyondur. Hoca sordu: $\frac{A}{s-5}$ neyin dönüşümüdür? Öğrenciler üstel olduğunu söyledi. Payda $s-5$ olduğu için üs $+5t$'dir: $A\,e^{5t}$. $t$'yi sıfırdan büyük alırsak $u(t)$ de eklenir: $A\,e^{5t}u(t)$. Payda $s+5$ olsaydı üs $-5t$ olurdu.

> **Ders sonrası not:** Hoca genel biçimi sözlü olarak "$A\,e^{-at}$" diye söyledi. Yukarıdaki paydalar $s-a$ biçiminde olduğundan doğru karşılık $A\,e^{at}u(t)$'dir.

### 10.2 İkinci Durum: Katlı (Çakışık) Kök

Payda $(s-a)^2$ olabilir. Örneğin $s^2 - 2s + 1 = (s-1)^2$. Bu durumda açılım şöyle yazılır:

$$\frac{F(s)}{(s-a)^2} = \frac{A}{s-a} + \frac{B}{(s-a)^2}$$

Payda eşitlenince:

$$F(s) = A(s-a) + B$$

Önce $s = a$ yazılır: Birinci terim sıfır olur ve $B$ bulunur. Sonra $s$ yerine herhangi başka bir değer verilerek $A$ bulunur. Dikkat edilecek nokta, paydaların birinci dereceden olup katlı kök durumuna ait olmasıdır: Pay yine sabit sayıdır.

> **Ders sonrası not:** Hoca $F(s)$ için "$s^2 + 5s$ gibi" dedi. $A(s-a) + B$ biçimi yalnız $F(s)$'in derecesi paydanınkinden küçükse (burada en fazla 1) geçerlidir. $F(s)$ ikinci dereceden olursa kesre bir de sabit terim eklenir, $s^2 + 5s$ bu açılıma tek başına uymaz.

<!-- BELİRSİZ: 01:17:32'de hoca üçüncü dereceden katlı kök için açılımı sözlü verdi, altyazıda "S eksi A, S eksi A'nın karesi, S eksi B'nin karesi" yazıyor. Bir sonraki notta matematiksel doğru hâli verildi. -->

> **Ders sonrası not:** Üçüncü dereceden katlı kökte açılım $\frac{A}{s-a} + \frac{B}{(s-a)^2} + \frac{C}{(s-a)^3}$ olur.

### 10.3 Üçüncü Durum: Karmaşık Kökler

Payda $as^2 + bs + c$ gibi, reel köke ayrılmayan ikinci dereceden bir ifade olabilir. Yapılacak ilk iş paydayı tam kareli hâle getirmektir. Hocanın örneği:

$$\frac{2s-3}{s^2-2s+5} = \frac{2s-3}{(s-1)^2+4}$$

Hoca, payda ikinci dereceden olduğu için payın da birinci dereceden terim ile sabit içermesi gerektiğini söyledi. Slaytta $\frac{As+B}{(s-1)^2+4} + \frac{C}{(s-1)^2+4}$ biçiminde yazıp bunu $\frac{As}{\cdots}$, $\frac{B}{\cdots}$, $\frac{C}{\cdots}$ olarak ayırdı. $s$'li pay kosinüse, sabit pay sinüse karşılık gelir. $s$'teki öteleme de üstel bir çarpanla ifade edilir. Hoca burada yalnız genel terminolojiyi anlattığını, karmaşık bir hâlden daha basit bir hâle indirildiğini söyledi ve örneği bitirmedi.

> **Ders sonrası not:** Üç bilinmeyenli yazım gereksizdir, çünkü $B$ ve $C$ terimleri aynı biçimdedir. Pay doğrudan $(s-1)$ cinsinden yazılır: $2s-3 = 2(s-1) - 1$. Buradan
> $$\frac{2s-3}{(s-1)^2+4} = 2\cdot\frac{s-1}{(s-1)^2+4} - \frac{1}{2}\cdot\frac{2}{(s-1)^2+4}$$
> bulunur. Sinyal sağ taraflı alınırsa sonuç $e^{t}\left[2\cos(2t) - \tfrac{1}{2}\sin(2t)\right]u(t)$'dir. Bu sonuç sayısal Laplace integraliyle doğrulandı. Öteleme $s-1$ olduğu için üstel çarpan eksi değil, $e^{+t}$'dir.

> **Ek bilgi (derste anlatılmadı):** Sağ taraflı sinyaller için kullanılan tablo çiftleri şunlardır: $\cos(\omega t)u(t) \leftrightarrow \frac{s}{s^2+\omega^2}$ ve $\sin(\omega t)u(t) \leftrightarrow \frac{\omega}{s^2+\omega^2}$. s-düzleminde kayma özelliğiyle $e^{at}\cos(\omega t)u(t) \leftrightarrow \frac{s-a}{(s-a)^2+\omega^2}$ ve $e^{at}\sin(\omega t)u(t) \leftrightarrow \frac{\omega}{(s-a)^2+\omega^2}$ elde edilir.

> **Hocanın vurgusu:** Hoca sayısal çalışmalarda genellikle en fazla ikinci dereceden paydayla karşılaşılacağını söyledi: "Matematik bilginizi burada test etmiyoruz. Sinyal bilgisini ve bu özelliği kullanmak bizim için yeterli."

## 11. Genel Akış: Sıfır Giriş, Sıfır Durum, Geçici ve Kalıcı Cevap

Slaytta $n$. mertebeden bir sistemin genel hâli vardı. Hoca bunun, ikinci ve üçüncü mertebe için gösterilen mantığın aynısı olduğunu, sıfır anındaki değerlerin hepsinin sabit sayı olacağını ve sonucun basit kesirlerle elde edileceğini söyledi.

$Y(s)$ açıldığında iki ayrı adlandırma görülür:

- **Sıfır giriş cevabı (zero-input response) ve sıfır durum cevabı (zero-state response):** Birincisi başlangıç koşullarından, ikincisi girişten gelen parçadır.
- **Geçici cevap (transient response) ve kalıcı cevap (steady-state response):** Birincisi belli bir zamanla yok olur. İkincisi sistemin bir yerden sonra oturacağı davranışı gösterir.

<!-- BELİRSİZ: 01:22:39'daki slayt formülü altyazıda bozuk ("I çarpı GS bölü AS"). Y(s)'in slayttaki tam gösterimi okunamıyor. -->

RC örneğinde bu ayrım şöyledir: Sıfır giriş parçası $5e^{-t/RC}$, sıfır durum parçası $1 - e^{-t/RC}$'dir. Toplamda geçici kısım $4e^{-t/RC}$, kalıcı kısım $1$'dir (ara adım eklendi).

Başlangıç koşulu parçası sıfırsa, geriye yalnızca girişe bağlı parça kalır ve bu durumda $Y(s)/X(s)$ oranına transfer fonksiyonu denir. Bu oran giriş-çıkış ilişkisidir.

Özetle yapılan şudur:

- Sistemin davranışı diferansiyel denklemle modellenir. Sürekli zamanda ($t$ düzleminde) çalışıldığı için model diferansiyel denklemdir.
- Laplace dönüşümüyle s-düzlemindeki karşılığı bulunur.
- Bu karşılık en basit biçimde, basit kesirler olarak yazılır.
- Ters dönüşümle zaman düzlemine dönülür.

## 12. Slayttaki Kısmi Kesir Örnekleri ve Rezidüler

### 12.1 RC Örneğindeki Ayrım

Hoca RC'deki ayrımı tekrar gösterdi. Kolaylık için $\frac{1}{RC} = \alpha$ denirse:

$$\frac{\alpha}{s(s+\alpha)} = \frac{\alpha}{s^2+\alpha s} = \frac{1}{s} - \frac{1}{s+\alpha}$$

Birincisi $u(t)$'nin, ikincisi $e^{-\alpha t}u(t)$'nin dönüşümüdür.

### 12.2 Hedeflenen Biçim

Slaytta $Y(s)$ basit kesirlere ayrılmış olarak verilen bir örnek vardı. Bir sabit terim ile $s+5$ ve $s+3$ paydalı iki kesir içeriyordu. Hoca, hedefin tam bu biçimi elde etmek olduğunu, çünkü ters dönüşümünün çok kolay olduğunu söyledi. Sabit 2 terimi $2\delta(t)$'yi (hoca önce $u(t)$ dedi, sonra delta olarak düzeltti), $s+5$ paydalı terim $4e^{-5t}$'yi, $s+3$ paydalı terim $2e^{-3t}$'yi verir.

<!-- BELİRSİZ: 01:24:57'deki slayt formülünün tamamı altyazıda yok. Terimlerin işaretleri ve Y(s)'in açılmadan önceki biçimi okunamıyor. -->

### 12.3 Örnek: $\frac{3s-1}{s^2+3s+2}$

Sabit terim (direct term), katlı kök ve karmaşık kök olmayan durum incelendi. Payda çarpanlarına ayrılır:

$$s^2+3s+2 = (s+2)(s+1) \quad\Rightarrow\quad \frac{3s-1}{(s+2)(s+1)} = \frac{A}{s+2} + \frac{B}{s+1}$$

$A$ ve $B$'ye (slayttaki adlarıyla $R_1$ ve $R_2$) rezidü (residue) denir. Hoca kavramla çok işimiz olmadığını söyledi. Payda eşitlenince:

$$A(s+1) + B(s+2) = 3s - 1$$

**Uzun yol.** İfade açılır: $(A+B)s + (A+2B) = 3s - 1$. Katsayılar eşitlenir: $A + B = 3$, $A + 2B = -1$. Bu denklem takımı çözülür. Hoca buna gerek olmadığını söyledi.

**Kısa yol.** Paydayı sıfırlayan değerler yerine yazılır.

- $s = -1$: Birinci terim sıfır olur. $B(-1+2) = 3(-1) - 1$, yani $B = -4$.
- $s = -2$: İkinci terim sıfır olur. $A(-2+1) = 3(-2) - 1$, yani $-A = -7$ ve $A = 7$.

> **Hocanın vurgusu:** Katsayıları bulmak için uzun denklem sistemi kurmaya gerek yoktur. Paydayı sıfırlayan değeri $s$ yerine koymak yeterlidir.

Sonuç:

$$Y(s) = \frac{7}{s+2} - \frac{4}{s+1} \quad\leftrightarrow\quad y(t) = 7e^{-2t}u(t) - 4e^{-t}u(t)$$

Hoca önce sözlü olarak $7e^{-t}$ dedi, sonra slaytta $7e^{-2t}$ olarak düzeltti. $u(t)$ çarpanı, $t$'yi sıfırdan büyük almaktan, yani negatif zamanın olmadığı gerçek fiziksel bir sistemde çalışmaktan gelir.

Slaytta rezidüler için kısa bir yazım da vardır: $Y(s)$ ile $(s+2)$ çarpılır ve $s = -2$ yazılır, yani paydayı sıfırlayan değer kullanılır. Kontrol: $\frac{3s-1}{s+1}\Big|_{s=-2} = \frac{-7}{-1} = 7$ (ara adım eklendi). Hoca işin mantığının bu eşitliği yazıp $A$ ile $B$'yi bulmak olduğunu söyledi.

## 13. Kutuplar, Sıfırlar ve Frekans Cevabı

### 13.1 Tanımlar

Sıfır ve kutup kavramları, sürekli zamanlı sistemleri analiz ederken yararlanılan araçlardır. Bunlardan ROC, kararlılık ve nedensellik gibi özellikler bulunabilir.

- **Sıfır (zero):** Payı sıfır yapan değerler. Diyagramda küçük daire ile gösterilir.
- **Kutup (pole):** Paydayı sıfır yapan değerler. Diyagramda çarpı ile gösterilir. Hoca "kutup, sonsuza gitmek demektir" dedi.

Genel olarak $z_1, z_2, \ldots, z_m$ sıfırları, $p_1, p_2, \ldots, p_n$ kutuplarıdır. Önemli olan denklemi bulabilmektir. Sonrası sıfır ve kutupları işaretlemektir.

> **Ders sonrası not:** "Sonsuza gitmek" burada $|H(s)|$'nin kutup noktasında sonsuza gitmesidir. Sistemin zaman cevabının sonsuza gittiği anlamına gelmez. Zaman cevabının davranışını kutbun s-düzlemindeki yeri belirler.

### 13.2 Slayttaki Sıfır-Kutup Örneği

Sıfırlar ve kutuplar karmaşık da çıkabilir. Slayttaki örnek şudur:

<!-- BELİRSİZ: Formülün tamamı altyazıda yok, kısa nottan alındı. Altyazı yalnız kutupları ve pay katsayılarını (2, 12, 20) doğruluyor. -->

$$H(s) = \frac{2s^2+12s+20}{s^3+6s^2+10s+8} = \frac{2(s+3-j)(s+3+j)}{(s+4)(s+1-j)(s+1+j)}$$

Kutuplar $-4$, $-1+j$ ve $-1-j$'dir. Sıfırlar $-3+j$ ve $-3-j$'dir. S-düzlemi iki boyutlu olduğundan karmaşık bir kök, gerçel kısmı $\sigma$ ekseninde, sanal kısmı $j\omega$ ekseninde okunarak işaretlenir. Örneğin $-1+j$ kutbu $\sigma = -1$ ile $j\omega = 1$'in kesişimindedir. Hepsinin işaretlendiği çizime sıfır-kutup diyagramı denir. Python ile kökler bu değerlerde bulundu.

Hoca, MATLAB'e pay ve payda katsayıları verildiğinde s-düzlemini sizin yerinize çizdiğini söyledi. Pay katsayıları $2, 12, 20$; payda katsayıları $1, 6, 10, 8$'dir.

<!-- BELİRSİZ: 01:31:49'da komut adı altyazıda "zero call" geçiyor, gerçek MATLAB komutu okunamıyor. Payda katsayıları altyazıda "1, 6, 18" yazılı; büyük olasılıkla bu "1, 6, 10, 8"in ("on, sekiz") yanlış yazımıdır. -->

Slaytta aynı sıfır-kutup diyagramının üç boyutlu bir görseli de vardı: Kutup olan noktalarda değer sonsuza gider, sıfır olan noktalarda sıfır olur.

### 13.3 Laplace'tan Frekans Cevabına

Sistemin Fourier dönüşümü varsa Laplace'tan Fourier'e geçmek kolaydır: $s$ yerine $j\omega$ yazılır ve $H(\omega)$ bulunur.

$$H(\omega) = H(s)\Big|_{s=j\omega}$$

$H(s)$'e transfer fonksiyonu, $H(\omega)$'ya frekans cevabı (frequency response) denir. Slaytta frekans cevabının farklı grafikleri vardı. Kutup $j\omega$ eksenine yaklaştıkça frekans cevabında etkisi güçlenir, daha keskin ve daha yüksek sıçramalar görülür. Uzaklaştıkça bu etki azalır.

<!-- BELİRSİZ: Frekans cevabı grafiklerinin kutup konumları ve sayısal değerleri altyazıda yok. -->

Hoca, Laplace dönüşümü için ders notlarında genel tablolar olduğunu ve kullanılabileceğini belirtti.

## 14. Kararlılık ve Nedensellik

Hoca iki kuralı yazarak anlattı.

**Kural 1.** Sistem nedenselse ve sağ yarı düzlemde kutbu varsa, sistem kararsızdır.

Nedensellik, $t < 0$ için $h(t) = 0$ olması demektir. $h(t)$'nin sağ taraflı olması da aynı şeyi anlatır, $h(t)$ içinde $u(t)$ gibi bir çarpan olur. Sonlu giriş-sonlu çıkış (BIBO) kararlılığına bakarken, sıfır-kutup diyagramında sağ yarı düzlemde bir kutup görülürse bu nedensel sistem kararsızdır.

**Kural 2.** ROC, $j\omega$ eksenini içeriyorsa sistem BIBO kararlıdır.

İki kural birbiriyle uyumludur: Nedensel bir sistemde ROC en büyük kutbun sağındadır (Bölüm 2). Sağ yarı düzlemde kutup varsa ROC $j\omega$ eksenini içeremez (ara adım eklendi).

Hoca ROC'un sonsuza kadar uzanmak zorunda olmadığını da gösterdi. İki kutup varsa ROC ikisinin arasında bir şerit olabilir. Bu durumda sinyal için sağ taraflı ya da sol taraflı denemez. Hoca çizdiği örnekte, sağ yarı düzlemdeki bir kutup nedeniyle sistemin kararsız olduğunu söyledi.

<!-- BELİRSİZ: 01:37:57 ile 01:38:30 arasında çizimdeki iki kutbun ve şeridin yeri altyazıda yok. -->

> **Ders sonrası not:** "Sağ yarı düzlemde kutup varsa kararsızdır" kuralı yalnız nedensel sistemler içindir. Şerit biçimli ROC'ta sistem nedensel değildir ve belirleyici olan Kural 2'dir. Şerit $j\omega$ eksenini içeriyorsa sistem, sağ yarı düzlemde kutbu olsa da BIBO kararlıdır. Örneğin Bölüm 16.2'deki $e^{-3t}u(t) + e^{2t}u(-t)$ bir dürtü cevabı olsaydı kutupları $-3$ ve $2$ olurdu, ROC $j\omega$ eksenini içerirdi ve $\int|h(t)|dt = \frac{1}{3}+\frac{1}{2} = \frac{5}{6}$ sonlu çıkardı.

## 15. İkinci Dereceden Diferansiyel Denklem Örneği

Hoca bundan sonra daha önce hazırlığı yapılan ikinci dereceden örneği çözdü.

**Verilen:**

$$y''(t) + 3y'(t) + 2y(t) = x(t),\qquad x(t) = u(t),\qquad y(0) = 1,\qquad y'(0) = 2$$

**Adım 1: Dönüşüm.** Her terimin tek taraflı karşılığı yazılır: $y'' \leftrightarrow s^2Y(s) - s\,y(0) - y'(0)$, $y' \leftrightarrow sY(s) - y(0)$, $y \leftrightarrow Y(s)$, $x \leftrightarrow X(s) = 1/s$. Başlangıç değerleri yerine konur:

$$s^2Y(s) - s - 2 + 3\left[sY(s) - 1\right] + 2Y(s) = \frac{1}{s}$$

**Adım 2: Cebir.** Hoca "iş artık bunu cebirsel olarak çözmeye kaldı" dedi. Sabitler $-2$ ve $-3$ birleşerek $-5$ olur:

$$Y(s)\left(s^2+3s+2\right) - s - 5 = \frac{1}{s}$$

**Soru:** Bir öğrenci hocanın parantez dışında $2Y(s)$ yazdığını fark ettirdi ve orada $-5$ mi $-s$ mi olduğunu sordu. **Cevap:** Hoca $2Y(s)$'in zaten parantezde olduğunu kabul etti. $-2$ ve $-3$'ten $-5$, ayrıca $-s$ teriminin bulunduğunu, $s$ ile $5$'in yazıda karıştığını açıkladı.

$-s-5$ karşıya atılır ve iki taraf $s^2+3s+2$'ye bölünür:

$$Y(s)\left(s^2+3s+2\right) = \frac{1}{s} + s + 5 = \frac{s^2+5s+1}{s}$$

$$Y(s) = \frac{s^2+5s+1}{s\,(s^2+3s+2)} = \frac{s^2+5s+1}{s(s+1)(s+2)}$$

**Adım 3: Parçalama.** Hoca ifadeyi iki kesre böldü:

$$Y(s) = \frac{1}{s(s^2+3s+2)} + \frac{s+5}{s^2+3s+2}$$

Paydalarda $s^2+3s+2 = (s+1)(s+2)$ vardır. İkinci kesri de $\frac{s}{(s+1)(s+2)} + \frac{5}{(s+1)(s+2)}$ diye ayırdı. Sonra derste vakit kalmadığını söyleyerek sonucu parça parça sözlü verdi. Ara adımlar paydayı sıfırlayan değer yöntemiyle şöyledir (ara adım eklendi):

- $\frac{1}{s(s+1)(s+2)} = \frac{1/2}{s} - \frac{1}{s+1} + \frac{1/2}{s+2}$. Bu, hocanın saydığı $\frac{1}{2}u(t)$, $e^{-t}$ ve $\frac{1}{2}e^{-2t}$ terimleridir.
- $\frac{s+5}{(s+1)(s+2)} = \frac{4}{s+1} - \frac{3}{s+2}$. Bu, hocanın saydığı $4e^{-t}$ ve $3e^{-2t}$ terimleridir.

**Adım 4: Sonuç.** Terimler toplanır:

$$Y(s) = \frac{1/2}{s} + \frac{3}{s+1} - \frac{5/2}{s+2}$$

$$y(t) = \left(\frac{1}{2} + 3e^{-t} - \frac{5}{2}e^{-2t}\right)u(t)$$

> **Ders sonrası not:** Hoca toplamı yazmadı, "uzun bir denklem bulunur" dedi. Sonuç başlangıç koşullarını sağlar: $y(0) = \frac{1}{2} + 3 - \frac{5}{2} = 1$ ve $y'(0) = -3 + 5 = 2$. Denklemin sayısal çözümü (Runge-Kutta) bu ifadeyle aynı değerleri verdi. Sınırda $s\,Y(s)$'ten de aynı değerler çıkar: $s \to \infty$ için $1$, yani $y(0)$; $s \to 0$ için $\frac{1}{2}$, yani oturma değeri.

Hoca sorunun bu kadar karmaşık sorulmasının beklenmediğini, önemli olanın adımlar olduğunu söyledi: Denklemin dönüşümü alınır, başlangıç koşulları yerine yazılır, $Y(s)$ cebirsel olarak yalnız bırakılır, basit kesirlere ayrılır ve ters dönüşüm alınır.

**Sıfır-kutup diyagramı.** $Y(s)$'in paydasını sıfır yapan değerler kutuplardır: $0$, $-1$ ve $-2$. Payı sıfır yapan değerler sıfırlardır ve daireyle gösterilir.

> **Ders sonrası not:** Hoca sıfırların "galiba kompleks" çıkacağını söyledi. $s^2+5s+1 = 0$ denkleminin diskriminantı $25 - 4 = 21 > 0$'dır, yani kökler reeldir: $\frac{-5\pm\sqrt{21}}{2}$, yaklaşık $-0{,}209$ ve $-4{,}791$. İki sıfır da $\sigma$ ekseni üzerindedir.

## 16. Yakınsama Bölgesi Örnekleri

Son bölümde yakınsama bölgesiyle ilgili birkaç örnek yapıldı.

### 16.1 Örnek 1: Sağ Taraflı Sinyal

$$x(t) = e^{-2t}u(t) + e^{-3t}u(t)$$

Terimlerin dönüşümleri:

$$e^{-2t}u(t) \leftrightarrow \frac{1}{s+2},\ \ \sigma > -2 \qquad\qquad e^{-3t}u(t) \leftrightarrow \frac{1}{s+3},\ \ \sigma > -3$$

$u(t)$ olduğundan her terim $0$'dan sonsuza kadarki değerleri içerir. $\sigma$, $s$'in gerçel kısmıdır. Sıfır-kutup diyagramı için payda eşitlenir:

$$X(s) = \frac{1}{s+2} + \frac{1}{s+3} = \frac{(s+3)+(s+2)}{(s+2)(s+3)} = \frac{2s+5}{(s+2)(s+3)}$$

Kutuplar $-2$ ve $-3$'tür. Sıfır $-\frac{5}{2}$'dir ve iki kutbun arasındadır. Sinyal sağ taraflıdır, bu yüzden ROC en büyük kutbun sağındadır: $\sigma > -2$. Hoca kararlılık gibi özelliklerin de buradan söylenebileceğini belirtti.

### 16.2 Örnek 2: İki Taraflı Sinyal

$$x(t) = e^{-3t}u(t) + e^{2t}u(-t)$$

Birinci terim sağ taraflıdır:

$$e^{-3t}u(t) \leftrightarrow \frac{1}{s+3},\quad \sigma > -3$$

İkinci terim sol taraflıdır. $t$'nin negatif değerlerinde tanımlı olduğu için başa eksi gelir ve ROC'un yönü de değişir:

$$e^{2t}u(-t) \leftrightarrow -\frac{1}{s-2},\quad \sigma < 2$$

Toplanınca:

$$X(s) = \frac{1}{s+3} - \frac{1}{s-2} = \frac{(s-2)-(s+3)}{(s+3)(s-2)} = \frac{-5}{(s+3)(s-2)}$$

Kutuplar $-3$ ve $2$'dir. Pay sabit olduğundan sıfır yoktur, boş küme yazılır. Sinyal ne sağ taraflı ne sol taraflıdır. ROC, iki şartın kesişimi olan şerittir:

$$-3 < \sigma < 2$$

Hoca bir an sınırı $-2$ diye okudu, sonra $+2$ diye düzeltti. Şeridin dışında integral ıraksar.

### 16.3 Örnek 3: Laplace Dönüşümü Olmayan Sinyal

$$x(t) = e^{2t}u(t) + e^{-3t}u(-t)$$

Bu sinyalde basamak fonksiyonlarının yeri değiştirilmiştir:

$$e^{2t}u(t) \leftrightarrow \frac{1}{s-2},\quad \sigma > 2 \qquad\qquad e^{-3t}u(-t) \leftrightarrow -\frac{1}{s+3},\quad \sigma < -3$$

Cebirsel olarak hesaplanabilir:

$$\frac{1}{s-2} - \frac{1}{s+3} = \frac{5}{(s-2)(s+3)}$$

Fakat iki şartın da sağlanması gerekir. Hem $2$'den büyük hem $-3$'ten küçük hiçbir $\sigma$ yoktur. Yakınsama bölgeleri kesişmez.

> **Hocanın vurgusu:** İntegralde yakınsama bölgelerinin kesişmesi gerekir. Kesişim yoksa bu sinyalin Laplace dönüşümü yoktur.

> **Ders sonrası not:** Altyazıda paydanın "S eksi 2 çarpı S eksi 3" diye geçtiği görülüyor. Kutbu hoca $-3$ diye verdiğinden doğru payda $(s-2)(s+3)$'tür. Python ile kontrol edildi: $\sigma = 3$'te sağ taraflı terim yakınsarken sol taraflı terim, integrasyon aralığı büyüdükçe sınırsız büyür. $\sigma = -4$'te durum tersine döner.

## 17. Yakınsama Bölgesiyle Ters Dönüşüm Örneği

Hoca önce $\frac{5s+13}{s(s^2+4s+13)}$ ifadesini yazdı. Kökleri karmaşık çıktığı için "buna gerek yok" diyerek bıraktı ve daha basit bir örneğe geçti:

$$X(s) = \frac{2s+4}{s^2+4s+3}$$

**Adım 1: Payda.** $s^2+4s+3 = (s+1)(s+3)$.

**Adım 2: Basit kesirler.**

$$\frac{2s+4}{(s+1)(s+3)} = \frac{A}{s+1} + \frac{B}{s+3} \quad\Rightarrow\quad A(s+3) + B(s+1) = 2s+4$$

- $s = -1$: $2A = 2$, yani $A = 1$.
- $s = -3$: $-2B = -2$, yani $B = 1$.

Sonuç:

$$X(s) = \frac{1}{s+1} + \frac{1}{s+3}$$

**Adım 3: ROC.** Hoca bu kesirlerin hangi kurallara benzediğini sordu. Üstel olduğu söylendi. Ama hangisi olduğunu bilmek için $\sigma$ şartını görmek gerekir.

- $\sigma > -1$ verilmişse sinyal sağ taraflıdır. Hem $\sigma > -1$ hem $\sigma > -3$ sağlanır. Sonuç $x(t) = \left(e^{-t} + e^{-3t}\right)u(t)$'dir.
- Slayttaki ikinci durumda $-3 < \sigma < -1$ verilir. Bu ROC ile sinyal iki taraflıdır.

> **Hocanın vurgusu:** Soruda bu aralık verilmelidir, yani "$\mathrm{Re}(s)$ şu aralıktadır" denmelidir. Yoksa ters dönüşüm tek değildir.

<!-- BELİRSİZ: 02:14:30 ile 02:15:39 arasında hoca slaytın maddesini okurken duraksadı ("madde eksik var herhalde"), aralığı kendisi yazdı. Slayttaki maddelerin tam metni okunamıyor. -->

**Adım 4: Ters dönüşüm ($-3 < \sigma < -1$).** Her kesir kendi şartıyla okunur:

- $\frac{1}{s+1}$ için ROC $\sigma < -1$'dir. Normalde $-1$'den büyük beklenirdi, küçük verilmiştir. O hâlde terim sol taraflıdır: $-e^{-t}u(-t)$.
- $\frac{1}{s+3}$ için ROC $\sigma > -3$'tür. Terim sağ taraflıdır: $e^{-3t}u(t)$.

$$x(t) = -e^{-t}u(-t) + e^{-3t}u(t)$$

Sonuç sayısal integralle doğrulandı ($s = -2+j$ noktasında).

## 18. İkinci Dereceden Çarpanlı Kısmi Kesir Örneği

Hoca bitirmeden önce basit kesirlere ayırmada unuttuğu bir durumu gösterdi:

$$X(s) = \frac{2s+1}{(s-2)(s^2+9)}$$

Bir çarpan birinci, öteki ikinci derecedendir ve katlı değildir. İkinci dereceden çarpanın payı birinci dereceden yazılır. Üçüncü dereceden olsaydı $Bs^2+Cs+D$ yazılırdı:

$$\frac{2s+1}{(s-2)(s^2+9)} = \frac{A}{s-2} + \frac{Bs+C}{s^2+9}$$

Payda eşitlenince:

$$2s+1 = A(s^2+9) + (Bs+C)(s-2)$$

Hocaya göre burada $s$ yerine değer vermek pek işe yaramaz, çünkü en fazla $s = 2$ verilir ve geri kalanlar açıkta kalır. Bu yüzden ifade açılır:

$$2s+1 = As^2 + 9A + Bs^2 - 2Bs + Cs - 2C = (A+B)s^2 + (C-2B)s + (9A-2C)$$

Katsayılar eşitlenir ve doğrusal denklem takımı elde edilir:

$$A + B = 0,\qquad C - 2B = 2,\qquad 9A - 2C = 1$$

Çözüm (hocanın yazdığı değerlerin düzeltilmiş hâliyle):

$$A = \frac{5}{13},\qquad B = -\frac{5}{13},\qquad C = \frac{16}{13}$$

> **Ders sonrası not:** Hoca $A = \frac{6}{13}$, $B = -\frac{6}{13}$, $C = \frac{14}{13}$ değerlerini verdi. Bu değerler ilk iki denklemi sağlar, ama $9A - 2C = \frac{54-28}{13} = 2$ çıkar, $1$ değil. Denklemlerin çözümü yukarıdaki gibidir. Kısa kontrol: $s = 2$ yazılınca $2\cdot 2 + 1 = A(4+9)$, yani $A = \frac{5}{13}$. Hocanın değerleri tam olarak $\frac{2s+2}{(s-2)(s^2+9)}$ ifadesine aittir; büyük olasılıkla değerler payı farklı bir hazır çözümden okunmuştur.

Şimdi ters dönüşüm alınır. Hoca ikinci kesri iki parçaya böldü:

$$\frac{Bs+C}{s^2+9} = B\,\frac{s}{s^2+9} + C\,\frac{1}{s^2+9}$$

Bir öğrenci birincinin kosinüslü olduğunu söyledi. $s^2 + 9$'da $\omega = 3$ olduğundan bu $\cos(3t)$'dir. İkincisi $\sin(3t)$'dir, ama payda 3 olmalıdır. Bunun için 3 ile çarpılıp 3'e bölünür:

$$\frac{C}{s^2+9} = \frac{C}{3}\cdot\frac{3}{s^2+9} \quad\leftrightarrow\quad \frac{C}{3}\sin(3t)$$

Değerler yerine yazılır. Sinyal sağ taraflı kabul edilirse:

$$x(t) = \left[\frac{5}{13}e^{2t} - \frac{5}{13}\cos(3t) + \frac{16}{39}\sin(3t)\right]u(t)$$

Sonucun Laplace dönüşümü sayısal integralle alındı ve $X(s)$ ile aynı çıktı (hocanın sözlü sonucu $\frac{6}{13}e^{2t} - \frac{6}{13}\cos(3t) + \frac{14}{39}\sin(3t)$ idi).

## 19. Soru: İşareti ve Basamak Fonksiyonunu Neye Göre Seçtik?

**Soru:** Bölüm 17'deki örnekte terimlerin başındaki eksi ve artı işaretleri neye göre belirlendi?

**Cevap:** Hoca kutupları çizdi: $-1$ ve $-3$. Soruda $\sigma$ bu ikisinin arasında verilmiştir. Paydalara bakılınca $\frac{1}{s+1}$ normal hâlde $\sigma > -1$, $\frac{1}{s+3}$ normal hâlde $\sigma > -3$ ister.

- $\frac{1}{s+3}$ için verilen şart ($\sigma > -3$) uyumludur. Bu, normal $e^{-3t}u(t)$ terimidir.
- $\frac{1}{s+1}$ için verilen şart ($\sigma < -1$) terstir. Bu da $t$'si tersine çevrilmiş ve negatif hâlidir: $-e^{-t}u(-t)$.

Bu farkın kaynağı Bölüm 1'dedir: $\frac{1}{s+1}$ hem $e^{-t}u(t)$'nin hem $-e^{-t}u(-t)$'nin dönüşümüdür. İkisini ayıran yakınsama bölgesidir.

## Dersin Toparlaması

Bu derste, $X(s)$ tek başına yeterli olmadığı için ters dönüşümde yakınsama bölgesinin neden gerektiği görüldü. Sağ taraflı sinyalde ROC en büyük kutbun sağında, sol taraflı sinyalde en küçük kutbun solunda, iki taraflı sinyalde iki kutup arasındaki şerittir, kesişim yoksa dönüşüm yoktur. Dönüşümün özellikleri arasında türev, başlangıç değer ve son değer özellikleri öne çıktı. Gerçek sistemlerde tek taraflı dönüşüm kullanıldığı için her türevde başlangıç değeri çıkarılır. Böylece diferansiyel denklem cebirsel bir denkleme döner, basit kesirlere ayrılır ve tablolardan zaman düzlemine geri gelinir. RC devresi ve ikinci dereceden örnek bu akışı baştan sona gösterdi. Sıfır-kutup diyagramı ise ROC, nedensellik, kararlılık ve frekans cevabı hakkında bilgi veren ortak araç oldu.

Hoca analog elektronik tarafında başka konular da olduğunu, ama bu ders için Laplace'ın bu kadarının yeterli olduğunu söyledi. Sonraki derste z-dönüşümü (Z-Transform) anlatılacak. Bu dönüşüm, Laplace dönüşümünün ayrık zamandaki karşılığıdır ve biraz farklı bir yöntem içerir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
