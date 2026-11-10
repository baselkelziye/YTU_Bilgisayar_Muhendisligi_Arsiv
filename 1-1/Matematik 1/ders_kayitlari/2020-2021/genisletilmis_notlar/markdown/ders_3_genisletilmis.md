# Ders 3 Genişletilmiş Notu: Temel Trigonometrik Limit, Ara Değer Teoremi ve Süreksizlik Türleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İki Formülü Karıştırmayın: $\frac{\sin x}{x}$ Sonsuzda ve Sıfırda
- 2. $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$ Formülünün Kanıtı
- 3. Eşlenik Yöntemi: $\frac{1-\cos x}{x}$
- 4. Değişken Değiştirme ile Benzerlik Kurmak
- 5. Genel Kural: $\frac{\sin u(x)}{u(x)}$ ve $\frac{\tan u(x)}{u(x)}$
- 6. Parçalı Fonksiyonda Süreklilik
- 7. Ara Değer Teoremi
- 8. Süreksizlik Türleri
- 9. Ara Değer Teoremi Alıştırmaları ve İpuçları
- 10. Test Tipi Ara Değer Teoremi Soruları
- 11. L'Hôpital'siz Limit Alıştırmaları
- 12. Geçmiş Yıl Sınav Soruları
- 13. Örnek Sorular

Hoca derse Zoom üzerinden, ekranını paylaşıp bir beyaz sayfaya (tablet) yazarak başladı. Ders İngilizce anlatıldı, önemli yerler Türkçe tekrar edildi. Amaç, geçen hafta görülen limit ve süreklilik konularını soru çözerek pekiştirmekti. Altyazıda yalnız sözlü kısım var. Tahtadaki formüller sözlü anlatımdan kuruldu ve sympy ile doğrulandı.

## 1. İki Formülü Karıştırmayın: $\frac{\sin x}{x}$ Sonsuzda ve Sıfırda

Hoca ilk olarak sıkıştırma teoreminden (sandwich / squeeze theorem) bilinen bir limiti hatırlattı:

$$\lim_{x\to\infty}\frac{\sin x}{x}=0$$

Gerekçe şudur: Her $x$ için $-1\le\sin x\le1$ olduğundan, $x>0$ için

$$-\frac1x\le\frac{\sin x}{x}\le\frac1x$$

yazılır. $x\to\infty$ iken iki uç da 0'a gider. Sıkıştırma teoremine göre ortadaki ifade de 0'a gider.

Ardından ikinci, "popüler" formülü sordu:

$$\lim_{x\to0}\frac{\sin x}{x}=1$$

Bu limit L'Hôpital kuralıyla kolayca 1 bulunur. Hocanın sorusu ise şuydu: L'Hôpital kullanmadan bunu nasıl kanıtlarız?

> **Hocanın vurgusu:** Bu iki formülü sakın birbiriyle karıştırmayın. $x\to0$ iken $\frac{\sin x}{x}$ ifadesinde $\frac00$ belirsizliği vardır. $x\to\infty$ iken ise belirsizlik yoktur: pay $\sin x$, $-1$ ile $+1$ arasında salınan sınırlı (bounded) bir ifadedir, payda $x$ ise sınırsızdır (unbounded). Bu yüzden ikincisinde sıkıştırma teoremi doğrudan uygulanır. Limitin yönüne dikkat edin.

## 2. $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$ Formülünün Kanıtı

Hoca kanıt için değişken olarak $\theta$ kullandı ve şunu vurguladı: $\theta$ bir gerçel sayıdır, yani radyan cinsindendir, derece değildir.

### 2.1 Birim Çember Çizimi

Birim çember (unit circle) çizildi. Yatay eksen kosinüs ekseni (sağı pozitif, solu negatif), dikey eksen sinüs ekseni (üst yarısı pozitif, alt yarısı negatif). Çembere $A=(1,0)$ noktasında teğet olan dikey doğru da tanjant ekseni (tangent axis) olarak işaretlendi: üst yarısı pozitif tanjant, alt yarısı negatif tanjant.

Orijin $O$ etrafında dönen bir ışın (bar) çizildi. Işının çemberi kestiği nokta $P$, tanjant eksenini kestiği nokta $T$ olarak adlandırıldı. Işın ile pozitif yatay eksen arasındaki açı $\theta$'dır.

### 2.2 Birinci Durum: $\theta\to0^+$

Bu durumda $0<\theta<\frac\pi2$ alınır. Şekilde üç bölge vardır ve alanları karşılaştırılır:

- **$OAP$ üçgeni:** Taban $|OA|=1$, yükseklik $P$'nin ordinatı olan $\sin\theta$. Alan $\frac{\sin\theta}{2}$.
- **$OAP$ dairesel dilimi (circular sector):** Radyan cinsinden dairesel dilimin alanı $\frac12r^2\theta$'dır. $r=1$ olduğundan alan $\frac\theta2$.
- **$OAT$ üçgeni:** Taban $|OA|=1$, yükseklik $|AT|=\tan\theta$. Alan $\frac{\tan\theta}{2}$.

Hoca dairesel dilim alanı için şuna dikkat çekti: Lisede derece cinsinden $\frac{\alpha}{360^\circ}\pi r^2$ formülü öğretilir. Burada derece değil, radyan cinsinden gerçel değerle çalışılıyor. Bu yüzden alan $\frac12r^2\theta$ olur.

Şekilde üçgen $OAP$ dilimin içinde, dilim de üçgen $OAT$'nin içinde kaldığı için alanlar sıralanır:

$$\frac{\sin\theta}{2}<\frac{\theta}{2}<\frac{\tan\theta}{2}\qquad(\ast\ast\ast)$$

Hoca bu adımdan sonrasını ödev bıraktı: Bu eşitsizlik üzerinde düzenleme yapılıp sıkıştırma teoremi uygulanırsa

$$\lim_{\theta\to0^+}\frac{\sin\theta}{\theta}=1$$

bulunur. Bir öğrencinin isteği üzerine bu kısmı tekrar ederken hoca, $(\ast\ast\ast)$ eşitsizliğinde her tarafı $\theta$'ya bölüp yeni bir sıralama elde etmeyi ve $\theta\to0^+$ iken sıkıştırma teoremini uygulamayı önerdi.

> **Ek bilgi (derste anlatılmadı):** Eşitsizliğin her tarafı $2$ ile çarpılıp $\sin\theta>0$ ile bölünürse $1<\frac{\theta}{\sin\theta}<\frac{1}{\cos\theta}$ elde edilir. Terslerine geçilince $\cos\theta<\frac{\sin\theta}{\theta}<1$ olur. $\theta\to0^+$ iken $\cos\theta\to1$ olduğu için sıkıştırma teoremine göre $\frac{\sin\theta}{\theta}\to1$ bulunur. Hocanın önerdiği gibi $\theta$'ya bölünürse de $\frac{\sin\theta}{\theta}<1<\frac{\sin\theta}{\theta\cos\theta}$ çıkar, bu da aynı sıralamayı verir.

### 2.3 İkinci Durum: $\theta\to0^-$

Bu kez ışın $-\frac\pi2<\theta<0$ aralığında, yani dördüncü bölgede alınır. Benzer bir alan karşılaştırması ve sıkıştırma teoremiyle

$$\lim_{\theta\to0^-}\frac{\sin\theta}{\theta}=1$$

gösterilir. İki tek taraflı limit eşit olduğu için

$$\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$$

sonucuna varılır.

### 2.4 Öğrenci Sorusu

**Soru:** Neden $\lim_{x\to0}\sin x$ ve $\lim_{x\to0}x$ ayrı ayrı alınıp sıkıştırma teoremi doğrudan uygulanamıyor?

**Cevap:** $x\to0$ iken $\sin x\to0$ ve $x\to0$ olur. İkisini oranlarsanız $\frac00$ belirsizliği (indeterminate form) çıkar ve bu durumda hiçbir şey söyleyemezsiniz. $x\to\infty$ durumunda ise $\sin x$, $-1$ ile $+1$ arasında salınır; $x$ ekseninde soldan sağa yürüdükçe payda sınırsız büyür. İki durumda limitin yönü farklıdır. Hoca bunun çok önemli olduğunu Türkçe olarak da tekrarladı.

<!-- BELİRSİZ: 00:19:20-00:19:47 arasında altyazı kelime kelime bölünmüş; cevabın bu kısmı yalnızca "limit as x goes to 0 sin x goes to 0, x goes to 0, indeterminate form" biçiminde okunabiliyor. -->

## 3. Eşlenik Yöntemi: $\frac{1-\cos x}{x}$

### 3.1 Örnek 1

Hoca, L'Hôpital kullanmadan şu limiti istedi:

$$\lim_{x\to0}\frac{1-\cos x}{x}$$

**Belirsizlik:** $x\to0$ iken pay $1-1=0$, payda $0$. $\frac00$ belirsizliği var.

**Fikir:** Bu ifade ile bilinen formül $\frac{\sin x}{x}$ arasında bir benzerlik kurmak. $1-\cos x$ ifadesinin eşleniği (conjugate) $1+\cos x$'tir. Pay ve payda $1+\cos x$ ile çarpılıp bölünür.

**İşlem:** $(a-b)(a+b)=a^2-b^2$ özdeşliği kullanılır:

$$\lim_{x\to0}\frac{1-\cos x}{x}=\lim_{x\to0}\frac{1-\cos^2x}{x}\cdot\frac{1}{1+\cos x}$$

$1-\cos^2x=\sin^2x=\sin x\cdot\sin x$ yazılır:

$$=\lim_{x\to0}\frac{\sin x}{x}\cdot\sin x\cdot\frac{1}{1+\cos x}$$

**Çarpım kuralı:** Hoca burada limitin çarpım kuralını (product rule) kullanmadan önce her çarpanın limitinin var olduğundan emin olunması gerektiğini söyledi:

- $\frac{\sin x}{x}\to1$,
- $\sin x\to0$,
- $\frac{1}{1+\cos x}\to\frac12$.

Her çarpanın limiti var. **Sonuç:** $1\cdot0\cdot\frac12=0$.

## 4. Değişken Değiştirme ile Benzerlik Kurmak

### 4.1 Örnek 2

$$\lim_{x\to1}\frac{\cos\frac{\pi x}{2}}{x-1}$$

**Belirsizlik:** $x=1$'de pay $\cos\frac\pi2=0$, payda $0$. $\frac00$ belirsizliği. Hoca L'Hôpital kullanılmamasını istedi.

**Fikir:** Ana formül $\lim_{t\to0}\frac{\sin t}{t}=1$ de $\frac00$ belirsizliğindedir. Hoca şöyle bir genel ilke koydu: Aynı tür belirsizliğe sahip iki farklı limit varsa, değişken değiştirme (change of variable) ya da bazı düzenlemelerle aralarında benzerlik kurulabilir.

**Dönüşüm:** $t=x-1$ alınır. $x\to1$ iken $t\to0$ olur ve $x=t+1$'dir. Limit yeni değişkenle yazılır:

$$\lim_{t\to0}\frac{\cos\left(\frac{\pi}{2}(t+1)\right)}{t}=\lim_{t\to0}\frac{\cos\left(\frac{\pi t}{2}+\frac\pi2\right)}{t}$$

**Toplam formülü:** $\cos(a+b)=\cos a\cos b-\sin a\sin b$ kullanılır, $a=\frac{\pi t}{2}$, $b=\frac\pi2$:

$$\cos\left(\frac{\pi t}{2}+\frac\pi2\right)=\cos\frac{\pi t}{2}\underbrace{\cos\frac\pi2}_{0}-\sin\frac{\pi t}{2}\underbrace{\sin\frac\pi2}_{1}=-\sin\frac{\pi t}{2}$$

Böylece limit $\lim_{t\to0}\frac{-\sin\frac{\pi t}{2}}{t}$ olur.

**$u$ oluşturma:** $u=\frac{\pi t}{2}$ denirse payda $\sin u$ vardır, ama paydada $u$ yoktur. Bu yüzden pay ve payda $\frac\pi2$ ile çarpılıp bölünür:

$$\lim_{t\to0}\frac{-\sin\frac{\pi t}{2}}{t}=-\frac\pi2\lim_{t\to0}\frac{\sin\frac{\pi t}{2}}{\frac{\pi t}{2}}$$

$t\to0$ iken $u=\frac{\pi t}{2}\to0$ olduğundan kutudaki limit $\lim_{u\to0}\frac{\sin u}{u}=1$'dir.

**Sonuç:** $-\frac\pi2$. (sympy ile doğrulandı.)

> **Ders sonrası not:** Hoca toplam formülünü uyguladıktan sonra iki yerde "as x goes to 0" dedi. Dönüşümden sonra değişken $t$'dir ve doğrusu "$t\to0$" (yani $x\to1$) olmalıdır.

> **Hocanın vurgusu:** "Niye bu kadar uzun anlatıyorsunuz, L'Hôpital ile direkt çıkıyor" diyenler olacaktır. Ama öyle sorular var ki L'Hôpital uyguladıkça yine belirsizlik çıkar, bir daha uygularsınız, yine çıkar. L'Hôpital her zaman işe yaramaz. Bu yüzden size öğrettiğim mantığı anlamaya çalışın.

**Soru:** $\cos\left(\frac\pi2(t+1)\right)$ ifadesinde neden bu dönüşümü ve toplam formülünü kullandık?

**Cevap:** Ana formül $\lim_{u\to0}\frac{\sin u}{u}=1$ ile bu limit arasında benzerlik kurmak için. Verilen limitte $x\to1$, ana formülde ise $u\to0$. Aslında bu iyi bilinen formül, verilen limit probleminin içinde saklıdır; onu ortaya çıkarmak için dönüşüm yapılır.

## 5. Genel Kural: $\frac{\sin u(x)}{u(x)}$ ve $\frac{\tan u(x)}{u(x)}$

### 5.1 Genel Durum

**Kural (sinüs):**

- $\lim_{x\to a}u(x)=0$ ise
- $\lim_{x\to a}\frac{\sin u(x)}{u(x)}=\lim_{u\to0}\frac{\sin u}{u}=1$.

Hoca bunu Türkçe olarak da tekrar etti: $x$, $a$'ya giderken $u(x)$ sıfıra gidiyorsa, $\frac{\sin u(x)}{u(x)}$ ifadesinin limiti $\frac{\sin u}{u}$'nun $u\to0$ limitine, yani 1'e eşittir. Az önceki Örnek 2 bunun bir uygulamasıdır.

### 5.2 Örnek 3

$$\lim_{x\to1}\frac{\sin(x^2-1)}{x-1}$$

**Paketleme:** $u=x^2-1$ alınır. Hoca bunun çok önemli bir koşul olduğunu söyledi: genel kuralı kullanmak için $x\to a$ iken $u\to0$ olmalıdır. Burada $a=1$ ve $x\to1$ iken $x^2-1\to0$. Koşul sağlanıyor.

**$u$'yu paydada oluşturma:** Paydada $x-1$ var, $u=x^2-1=(x-1)(x+1)$ yok. Bu yüzden pay ve payda $x+1$ ile çarpılıp bölünür. Özdeşlik açısından hiçbir şey değişmez:

$$\lim_{x\to1}\frac{\sin(x^2-1)}{x-1}\cdot\frac{x+1}{x+1}=\lim_{x\to1}\frac{\sin(x^2-1)}{x^2-1}\cdot(x+1)$$

**Limitler:** İlk çarpan genel kurala göre $1$'e, ikinci çarpan $x+1\to2$'ye gider.

**Sonuç:** $1\cdot2=2$. L'Hôpital olmadan bulundu.

### 5.3 Örnek 4

$$\lim_{x\to0}\frac{\sin(\sin x)}{x}$$

Hoca bu soruyu öğrencilere çözmeleri için bıraktı ve L'Hôpital kullanmamalarını hatırlattı.

> **Hocanın vurgusu:** Amacımız cevaba ulaşmak değil. Benim amacım size sonuca ulaşmayı öğretmek değil, bir yöntem öğretmek. Bunu unutmayın.

**Çözüm:** $u=\sin x$ alınır. $x\to0$ iken $\sin x\to0$, yani $u\to0$. Pay ve payda $\sin x$ ile çarpılıp bölünür:

$$\lim_{x\to0}\frac{\sin(\sin x)}{\sin x}\cdot\frac{\sin x}{x}$$

Hoca çarpanları iki sınıfa ayırdı:

- **Birinci sınıf:** $\frac{\sin(\sin x)}{\sin x}$, yani $\lim_{u\to0}\frac{\sin u}{u}=1$.
- **İkinci sınıf:** $\frac{\sin x}{x}\to1$.

**Sonuç:** $1\cdot1=1$.

### 5.4 Örnek 5: $\frac{\tan x}{x}$

$$\lim_{x\to0}\frac{\tan x}{x}=\lim_{x\to0}\frac{\sin x}{\cos x}\cdot\frac1x=\lim_{x\to0}\frac{\sin x}{x}\cdot\frac{1}{\cos x}=1\cdot1=1$$

### 5.5 Genel Durum (Tanjant ile)

**Kural:** $\lim_{x\to a}u(x)=0$ ise

$$\lim_{x\to a}\frac{\sin u(x)}{u(x)}=\lim_{u\to0}\frac{\sin u}{u}=1,\qquad\lim_{x\to a}\frac{\tan u(x)}{u(x)}=\lim_{u\to0}\frac{\tan u}{u}=1$$

### 5.6 Örnek 6

$$\lim_{x\to\infty}\frac{x\tan\frac{\sin x}{x}}{\sin x}$$

Hoca bunu bir "test" olarak öğrencilere bıraktı, L'Hôpital kullanılmamasını istedi.

**Düzenleme:** Önce fonksiyonun kuralı üzerinde düzenleme yapılmalıdır, aksi hâlde iyi bilinen formülle benzerlik görülmez. $\frac{x}{\sin x}=\frac{1}{\frac{\sin x}{x}}$ olduğundan:

$$\lim_{x\to\infty}\frac{\tan\frac{\sin x}{x}}{\frac{\sin x}{x}}$$

**Paketleme:** $u=\frac{\sin x}{x}$. Bölüm 1'deki sıkıştırma teoremine göre $x\to\infty$ iken $u\to0$. Hoca önce "as x goes to zero" dedi, hemen "sorry, as x goes to infinite" diye düzeltti.

**Sonuç:** Limit, $\lim_{u\to0}\frac{\tan u}{u}=1$ biçimine dönüşür. Cevap $1$.

Hoca bu yolun L'Hôpital uygulamaktan daha iyi olduğunu, L'Hôpital ile denenirse çok daha fazla zaman harcanacağını söyledi. (Büyük $x$ için sayısal kontrol yapıldı: değer 1'e çok yakın.)

> **Ders sonrası not:** $\sin x=0$ olan noktalarda ($x=k\pi$) ifade tanımsızdır. Limit, $\sin x\ne0$ olan $x$ değerleri üzerinden düşünülmelidir.

## 6. Parçalı Fonksiyonda Süreklilik

### 6.1 Örnek 7

Hoca bir önceki hafta sürekliliğin tanımının verildiğini hatırlatıp şu fonksiyonun $x=2$'de sürekli olup olmadığını incelemeyi istedi:

$$f(x)=\begin{cases}\dfrac{\sin\left(\sqrt{x^3+1}-3\right)}{x-2}, & x<2\\[2mm] x+1, & x\ge2\end{cases}$$

<!-- BELİRSİZ: Fonksiyonun tahtadaki tam tanımı altyazıda kısmen okunuyor ("sin of square root of x cubed plus 1 minus 3 over x minus 2"); sağ parçanın $x+1$ olduğu ve $f(2)=3$ olduğu kısa nottan ve hocanın "this is different from the value of function at the point two" ifadesinden çıkarıldı. -->

**Süreklilik tanımı:** $f$'nin $x=2$'de sürekli olması için $\lim_{x\to2}f(x)=f(2)$ olmalıdır. Önce limitin varlığı incelenir.

**Sol limit:** $x\to2^-$ iken birinci kural kullanılır:

$$\lim_{x\to2^-}\frac{\sin\left(\sqrt{x^3+1}-3\right)}{x-2}$$

Hoca burada L'Hôpital uygulamanın aslında daha iyi olacağını, ama henüz L'Hôpital öğretilmediğini söyledi.

**Paketleme:** $u=\sqrt{x^3+1}-3$. $x\to2$ iken $\sqrt{9}-3=0$, yani $u\to0$. Paydada $u$ oluşturmak için pay ve payda $\sqrt{x^3+1}-3$ ile çarpılıp bölünür:

$$\lim_{x\to2^-}\frac{\sin u}{u}\cdot\frac{\sqrt{x^3+1}-3}{x-2}$$

İlk çarpan $1$'e gider. Geriye daha basit bir limit kalır.

**Eşlenik yöntemi:** İkinci çarpanda yine $\frac00$ var. Eşlenik $\sqrt{x^3+1}+3$ ile çarpılıp bölünür:

$$\frac{x^3+1-9}{(x-2)\left(\sqrt{x^3+1}+3\right)}=\frac{x^3-8}{(x-2)\left(\sqrt{x^3+1}+3\right)}$$

Hoca payda $x-2$ çarpanının bulunduğunu söyledi ve "bundan sonrası $x^2+2x+4$, bla bla bla" diyerek kalan kısmı ödev bıraktı. Ara adım eklendi: $x^3-8=(x-2)(x^2+2x+4)$ olduğundan

$$\lim_{x\to2^-}\frac{x^2+2x+4}{\sqrt{x^3+1}+3}=\frac{4+4+4}{3+3}=\frac{12}{6}=2$$

**Sonuç:** Hoca cevabın 2 olduğunu söyledi. Sol limit $2$, $f(2)=2+1=3$. Bu değerler farklı olduğu için fonksiyon $x=2$'de sürekli değildir. (Sol limit sympy ile 2 olarak doğrulandı.)

> **Ders sonrası not:** Hoca yalnız sol limiti hesapladı. Sağ limit $\lim_{x\to2^+}(x+1)=3$'tür. Sol limit 2, sağ limit 3 olduğu için $x=2$'de limit yoktur. Bu, Bölüm 8'de anlatılan sıçrama süreksizliğidir.

## 7. Ara Değer Teoremi

Hoca 15 dakikalık aradan sonra derse ara değer teoremiyle (Intermediate Value Theorem) devam etti.

### 7.1 Teoremin Koşulları ve Sonucu

**Ara Değer Teoremi**

- **Koşul 1:** $f$, $[a,b]$ kapalı aralığında (closed interval) süreklidir. Uç noktalarda tek taraflı süreklilik yeterlidir: $a$'da sağdan, $b$'de soldan süreklilik.
- **Koşul 2:** $L$, $f(a)$ ile $f(b)$ arasında seçilen bir değerdir.
- **Sonuç:** $f(c)=L$ olacak biçimde en az bir $c\in[a,b]$ vardır.

Geometrik anlamı: $y=L$ yatay doğrusu çizilirse, fonksiyon sürekli olduğu için bu doğru grafiği en az bir yerde keser.

> **Hocanın vurgusu:** Fonksiyon kapalı aralıkta sürekli değilse ara değer teoreminden söz edemezsiniz.

### 7.2 Uygulama: Kök Varlığı

Teoremin en önemli uygulaması bir denklemin verilen aralıkta çözümü olduğunu göstermektir. Hoca bunu Türkçe olarak şöyle özetledi: Fonksiyon sürekliyse ve uç noktalarda aldığı değerler zıt işaretliyse, ara değer teoremine göre grafiği $x$ eksenini en az bir yerde kesmek zorundadır. Yani verilen aralıkta en az bir kökü vardır.

### 7.3 Örnek 8

$x^3+x+1=0$ denkleminin $[-2,1]$ aralığında çözümü olduğunu gösterin.

<!-- BELİRSİZ: Denklemin kendisi altyazıda okunmuyor; $f(-2)=-9$, $f(1)=3$ ve $f(-1)=-1$ değerleri altyazıda geçiyor ve $x^3+x+1$ ile tutarlı. Denklem kısa nottan alındı. -->

**Çözüm:**

- $f(x)=x^3+x+1$ alınır.
- $f(-2)=-8-2+1=-9<0$.
- $f(1)=1+1+1=3>0$.
- $f$ bir polinom fonksiyonudur, her yerde süreklidir. Dolayısıyla $[-2,1]$ kapalı aralığında süreklidir.
- $f(-2)=-9<0<3=f(1)$. Yani $L=0$, $f(-2)$ ile $f(1)$ arasındadır.
- Ara değer teoremine göre $f(c)=0$ olan en az bir $c\in(-2,1)$ vardır. Bu $c$, fonksiyonun bir köküdür.

Hoca grafiği de çizdi: $x=-2$'de grafik $-9$ yüksekliğinde, $x=1$'de $3$ yüksekliğinde; sürekli olduğu için aradaki bir noktada $x$ eksenini kesmek zorunda.

**Soru:** Neden $-2$ yerine $-1$ kullanmadık?

**Cevap:** Hoca önce aralığı yazarken "$-1$ yazsak olmaz, $-2$ yazın" demişti. Öğrencinin sorusu üzerine $-1$'i yerine koydu, sonucun $-1$ olduğunu gördü ve "hata yaptım, $-1$ de kullanabilirsiniz, sorun yok" dedi. $f(-1)=-1<0$ olduğundan $[-1,1]$ aralığı da teorem için uygundur.

> **Ders sonrası not:** Hoca "the answer is minus 1, directly that is this root" dedi. Doğrusu: $-1$, $f$'nin bir kökü değil, $f$'nin $-1$'deki değeridir ($f(-1)=-1$). Bu değer negatif olduğu için $[-1,1]$ aralığı da kullanılabilir.

## 8. Süreksizlik Türleri

Hoca ardından süreksizlik türlerini grafikler üzerinden tanıttı ve her birinin adının nereden geldiğini açıkladı. Kabaca üç tür süreksizlik vardır.

### 8.1 Kaldırılabilir Süreksizlik (Removable Discontinuity)

**Tanım**

- $\lim_{x\to a}f(x)=L$ vardır (soldan ve sağdan aynı $L$),
- ama $L\ne f(a)$ (ya da $f$, $a$'da tanımlı değildir).

Bu durumda yeni bir fonksiyon tanımlanır:

$$g(x)=\begin{cases}f(x), & x\ne a\\ L, & x=a\end{cases}$$

$f$, $a$'da sürekli olmasa bile yeni tanımlanan $g$ süreklidir. Yani $f$'nin süreksizliği, yeni bir fonksiyon tanımlanarak "kaldırılmış" olur. Elbette $g$, $f$'den farklı bir fonksiyondur. Bu mümkündür çünkü $f$'nin $a$'da limiti vardır, sadece bu limit değeri fonksiyonun $a$'daki değerine eşit değildir. Adı buradan gelir.

### 8.2 Sıçrama Süreksizliği (Jump Discontinuity)

**Tanım**

- Soldan limit $L_1$ ve sağdan limit $L_2$ sonlu (finite) değerler olarak vardır,
- ama $L_1\ne L_2$.

İki limit arasındaki mesafe sonlu bir sayıdır. Hocanın deyişiyle bu mesafeyi "sıçrayabilirsiniz". Sıçrama süreksizliği adı buradan gelir.

> **Hocanın vurgusu:** Kavramların arkasında yatan mantığı kavrayın. Soldan ve sağdan limit var ama farklı değerler; aradaki sıçrama miktarı sonlu. Bu yüzden sıçrama süreksizliği deniyor.

### 8.3 Sonsuz Süreksizlik (Infinite Discontinuity)

**Tanım**

- Soldan ya da sağdan (hangisi olduğu fark etmez) limitlerden en az biri sonsuzdur. Örneğin $\lim_{x\to a^+}f(x)=\infty$.
- Bu durumda $a$ noktası $f$ için bir sonsuz süreksizlik noktasıdır.

## 9. Ara Değer Teoremi Alıştırmaları ve İpuçları

Hoca ders notlarındaki alıştırmalara geçti. Bunların "sınavda çıkacak soru" diye değil, basit örnekler olarak anlatıldığını belirtti. Ders notlarındaki bir örnekte bir fonksiyonun $x=1$'de sürekli olup olmadığının incelenmesi istendi; hoca bunu temel bir soru olarak araştırmaya bıraktı.

### 9.1 Örnek 9

$2x^3+x-2=0$ denkleminin $(-1,1)$ aralığında çözümü vardır.

<!-- BELİRSİZ: Denklem altyazıda okunmuyor; yalnız "$-1$'de negatif ($-5$), $1$'de pozitif ($+1$)" değerleri geçiyor. Denklem kısa nottan alındı ve bu değerlerle tutarlı. -->

**Çözüm:** $f(x)=2x^3+x-2$ her yerde süreklidir. $f(-1)=-2-1-2=-5<0$, $f(1)=2+1-2=1>0$. $0$, $-5$ ile $1$ arasında olduğu için ara değer teoremine göre denklemin bu aralıkta en az bir çözümü vardır.

### 9.2 Örnek 10

$\sqrt{x^4+25x^3+10}=5$ eşitliğinin $(0,1)$ aralığındaki bir $x$ için sağlandığını gösterin.

<!-- BELİRSİZ: Eşitlik altyazıda okunmuyor; hoca yalnız "0'da negatif, 1'de pozitif" diyor. Eşitlik kısa nottan alındı. -->

**Çözüm:** Hoca, eşitliğin bir aralıkta sağlandığını göstermek için önce uygun bir fonksiyon kurulması ve uygun aralık seçilmesi gerektiğini söyledi. $f(x)=\sqrt{x^4+25x^3+10}-5$ alınır.

- $f(0)=\sqrt{10}-5\approx-1{,}84<0$.
- $f(1)=\sqrt{36}-5=1>0$.

$f$, $[0,1]$'de süreklidir. Ara değer teoremine göre bu aralıkta en az bir çözüm vardır.

Hoca ders notlarındaki bir başka örneğin üstel fonksiyon (exponential function) içerdiğini, üstel fonksiyon henüz öğrenilmediği için bu örneğin sonra yapılacağını söyledi.

### 9.3 Trigonometrik Limit İpuçları

Hoca ders notlarındaki bir dizi limit alıştırmasını tek tek çözmek yerine ipuçları verip evde çözülmesini istedi.

**Örnek 11:**

$$\lim_{x\to\pi}\frac{\cos^2x+3\cos x+2}{\cos x+1}$$

<!-- BELİRSİZ: Kesrin tam biçimi altyazıda okunmuyor; hoca payın $(\cos x+1)(\cos x+2)$ olarak çarpanlara ayrıldığını ve paydada $\cos x+1$ bulunduğunu söylüyor. Yukarıdaki ifade bu anlatımla tutarlı olarak kuruldu. -->

$x\to\pi$ iken $\cos x\to-1$ olduğundan $\frac00$ var. Pay çarpanlara ayrılır: $(\cos x+1)(\cos x+2)$. Belirsizliğe yol açan $\cos x+1$ çarpanı sadeleşir. Kalan $\cos x+2\to-1+2=1$. **Sonuç:** 1.

**Diğer ipuçları:**

- Bu tür sorularda büyük olasılıkla az önce kanıtlanan $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$ kullanılacaktır.
- Kök içeren bir soruda ($\sqrt{\sin x+1}$ gibi bir ifade) eşlenikle çarpıp bölmek gerekir.
- Bir soruda $\frac{\sin^2x}{\sin x}$ biçimi elde edilir; $\sin x$ sadeleşir, kalan $\sin x\to0$ ve cevap 0'dır.
- Bir soruda (ders notlarındaki numarasıyla 71) $\cos x-1$ ifadesinin eşleniğiyle çarpıp bölmek gerekir.
- Genel yol: önce ifadeyi basitleştirin, sadeleştirin, payda eşitleyin, düzenleme yapın; ondan sonra $\frac{\sin\theta}{\theta}$ formülünü kullanın.

<!-- BELİRSİZ: 01:24:52-01:26:10 arasındaki ipuçlarına ait soruların tam ifadeleri altyazıda okunmuyor. -->

### 9.4 Örnek 12: Süreklilik İçin Parametre

Bir parçalı fonksiyonun $x=-1$'de sürekli olması için $a$ değeri soruldu. Fonksiyonun $x=-1$'deki değeri $a$'dır. Süreklilik için $\lim_{x\to-1}f(x)=a$ olmalıdır. Limit hesaplanırken $x^2+3x+2$ çarpanlara ayrılır: $x^2+3x+2=(x+1)(x+2)$. Hoca sonucun $a=1$ olduğunu söyledi.

<!-- BELİRSİZ: Fonksiyonun tam tanımı altyazıda yok. Kural $\frac{x^2+3x+2}{x+1}$ biçimindeyse limit $x+2\to1$ olur ve $a=1$ ile tutarlıdır. Hemen ardından gelen "soldan süreklilik için $a$" sorusunun ifadesi ve cevabı altyazıda anlaşılmıyor. -->

Hoca bu soruların çok basit olduğunu, daha zor sorulara geçmek istediğini söyleyip hızlıca geçti.

## 10. Test Tipi Ara Değer Teoremi Soruları

Hoca test sınavında "Aşağıdaki ifadelerden hangileri doğrudur?" tipinde ara değer teoremi soruları gelebileceğini tahmin ettiğini söyledi. Bir hocanın "test sınavının ruhuna uygun" böyle bir senaryo kurgulayabileceğini düşünerek bu tipte sorular çözdü.

### 10.1 Örnek 13

"$x^2-10=x\sin x$ denkleminin gerçel bir çözümü vardır." İfadesi doğru mu?

Hoca amacın denklemi çözmek değil, gerçel çözümün varlığını göstermek olduğunu vurguladı: "Bunu çözmeye çalışmayın."

**Çözüm:**

- Sağ taraf sola atılır: $f(x)=x^2-10-x\sin x$. Bu yüzden karşılaştırılacak değer $0$'dır.
- $f$ her yerde süreklidir.
- $f(0)=0-10-0=-10<0$.
- $f(10)=100-10-10\sin10=90-10\sin10$. $|10\sin10|\le10$ olduğu için bu değer kesinlikle pozitiftir ($\approx95{,}44$).
- $f(0)<0<f(10)$. Ara değer teoremine göre $(0,10)$'da en az bir çözüm vardır.

**Sonuç:** İfade doğrudur.

### 10.2 Örnek 14

Denklemden $f(x)=1-\frac{x^2}{4}-\cos x$ fonksiyonu kurulur. Hoca her maddenin doğru olduğunu göstermeyi öğrencilere görev olarak verdi.

<!-- BELİRSİZ: Maddelerin tam metni altyazıda okunmuyor. Anlatımdan maddelerin "en az bir kökü vardır", "$(\frac\pi2,\pi)$'de bir kökü vardır" ve "en az üç kökü vardır" türünde olduğu anlaşılıyor. -->

**Çift fonksiyon:** $f(-x)=1-\frac{(-x)^2}{4}-\cos(-x)=f(x)$. $f$ çift fonksiyondur (even function). Hoca maddelerin doğruluğunun bu tanım kullanılarak anlaşılabileceğini söyledi.

**Madde A:** $f(0)=1-0-1=0$. Yani en az bir çözüm vardır: $r_1=0$. Doğru.

**Madde B:**

- $f\left(\frac\pi2\right)=1-\frac{\pi^2}{16}-0\approx0{,}38>0$.
- $f(\pi)=1-\frac{\pi^2}{4}+1=2-\frac{\pi^2}{4}\approx-0{,}47<0$.
- Uç noktalarda zıt işaret var ve $f$ sürekli. Ara değer teoremine göre $\left(\frac\pi2,\pi\right)$'de en az bir kök $r_2$ vardır. Doğru.

**Madde C:** $f$ çift olduğundan grafik $y$ eksenine göre simetriktir. $r_2$ kök ise $r_3=-r_2$ de köktür. $r_1=0$, $r_2>0$, $r_3<0$ birbirinden farklıdır. En az 3 çözüm vardır. Doğru.

Hoca bunu Türkçe olarak şöyle toparladı: $r_1=0$ dedik, $r_2$ ara değer teoreminden geldi, $r_3$ fonksiyonun çift olmasından geldi. En az 3 tane çözümü var.

> **Ders sonrası not:** Altyazıda hoca "R3 is equal to minus R3" diyor. Doğrusu $r_3=-r_2$'dir.

## 11. L'Hôpital'siz Limit Alıştırmaları

Hoca bu kısımda L'Hôpital kullanmadan, cebirsel düzenlemeler ya da uygun dönüşümlerle çözülecek daha zor limitlere geçti.

Bir öğrencinin sorusu üzerine hoca, Thomas' Calculus kitabıyla bağlantıyı doğruladı: İlk iki haftada fonksiyonlarla ilgili temel tanımlar (dikey doğru testi gibi), limit ve süreklilik öğrenilmelidir. Kitabın ilk bölümü fonksiyonlar ve temel tanımlarla ilgilidir.

### 11.1 Örnek 15

$$\lim_{x\to0}\frac{\sqrt{1+\sin^2x^2}-\cos^3x^2}{x^3\tan x}$$

Burada $\sin^2x^2=\left(\sin(x^2)\right)^2$ ve $\cos^3x^2=\left(\cos(x^2)\right)^3$ anlamındadır.

**Adım 1: $-1+1$ ekleme.** Hoca önce eşlenik yöntemini düşündüğünü, ama pay içine $-1$ ve $+1$ eklemenin daha uygun olduğunu söyledi. Hiçbir şey değişmez:

$$\frac{\left(\sqrt{1+\sin^2x^2}-1\right)+\left(1-\cos^3x^2\right)}{x^3\tan x}$$

**Adım 2: Ortak çarpan.** Paydada $x^3\tan x$ var. $x^4$ elde etmek için $\frac{x}{\tan x}$ ortak çarpan olarak ayrılır:

$$\frac{x}{\tan x}\left[\frac{\sqrt{1+\sin^2x^2}-1}{x^4}+\frac{1-\cos^3x^2}{x^4}\right]$$

$\frac{x}{\tan x}=\frac{1}{\frac{\tan x}{x}}\to1$.

**Adım 3: Birinci parça (eşlenik).** $\sqrt{1+\sin^2x^2}-1$, eşleniği $\sqrt{1+\sin^2x^2}+1$ ile çarpılıp bölünür:

$$\frac{\sin^2x^2}{x^4}\cdot\frac{1}{\sqrt{1+\sin^2x^2}+1}=\left(\frac{\sin x^2}{x^2}\right)^2\cdot\frac{1}{\sqrt{1+\sin^2x^2}+1}$$

$u=x^2\to0$ olduğundan $\frac{\sin x^2}{x^2}\to1$. İkinci çarpanda belirsizlik yok, $x=0$ doğrudan yazılır: $\frac{1}{1+1}=\frac12$. Birinci parça $\frac12$'ye gider.

Hoca bir yerde çözüm dosyasında bir adımın atlandığını belirtti: $\sqrt{1+\sin^2x^2}-1$ ifadesinin eşleniğiyle çarpılıp bölündüğü adım yazılmamıştı. Ayrıca anlatım "çok çorba oldu" diyerek bu kısmı yeniden anlattı.

**Adım 4: İkinci parça ($a^3-b^3$).** $a^3-b^3=(a-b)(a^2+ab+b^2)$ özdeşliği $a=1$, $b=\cos x^2$ ile kullanılır:

$$1-\cos^3x^2=\left(1-\cos x^2\right)\left(1+\cos x^2+\cos^2x^2\right)$$

$1-\cos\theta=2\sin^2\frac\theta2$ özdeşliği ile $1-\cos x^2=2\sin^2\frac{x^2}{2}$ yazılır (ara adım eklendi):

$$\frac{1-\cos^3x^2}{x^4}=\frac{2\sin^2\frac{x^2}{2}}{x^4}\left(1+\cos x^2+\cos^2x^2\right)=\frac12\left(\frac{\sin\frac{x^2}{2}}{\frac{x^2}{2}}\right)^2\left(1+\cos x^2+\cos^2x^2\right)$$

$u=\frac{x^2}{2}\to0$ olduğundan kare içindeki ifade $1$'e, $1^2=1$'e gider. Son çarpan $1+1+1=3$'e gider. İkinci parça $\frac12\cdot1\cdot3=\frac32$.

**Sonuç:** $1\cdot\left(\frac12+\frac32\right)=2$. Hoca "orada $\frac32$ geldi, en son yerine yerleştirirsek cevap 2 geliyor" dedi. (sympy ile doğrulandı: birinci parça $\frac12$, ikinci parça $\frac32$, toplam $2$.)

> **Ek bilgi (derste anlatılmadı):** $1-\cos\theta=2\sin^2\frac\theta2$ özdeşliği, yarım açı formülü $\cos\theta=1-2\sin^2\frac\theta2$'den gelir. $1-\cos$ içeren limitlerde eşlenik yöntemine bir alternatiftir: $\frac{\theta}{2}$ yeni değişken alınarak doğrudan $\frac{\sin u}{u}$ biçimi elde edilir.

### 11.2 Örnek 16

$$\lim_{x\to\infty}\left(\sqrt{x^2+1}-\sqrt{x^2-1}\right)$$

Hoca bu tür sorularda doğrudan eşlenik yöntemini uygulamanın daha iyi olduğunu, L'Hôpital ile çözmeye çalışılırsa büyük olasılıkla zor olacağını söyledi.

**Belirsizlik:** $\infty-\infty$.

**Eşlenik:** $\sqrt{x^2+1}+\sqrt{x^2-1}$ ile çarpılıp bölünür:

$$\lim_{x\to\infty}\frac{(x^2+1)-(x^2-1)}{\sqrt{x^2+1}+\sqrt{x^2-1}}=\lim_{x\to\infty}\frac{2}{\sqrt{x^2+1}+\sqrt{x^2-1}}$$

Pay sabit, payda sonsuza gider. **Sonuç:** $0$.

### 11.3 Eşlenik Yöntemiyle İki Alıştırma

Hoca ardından iki alıştırma daha çözdü. İkisinde de eşlenik yöntemi kullanıldı.

- Birinci alıştırmada da $\infty-\infty$ belirsizliği vardı. Hoca eşlenikte "eksi bir yerine artı bir" yazıldığını söyledi ve sonuçta $x$ ortak çarpanının çıktığını belirtti.
- İkinci alıştırmada $\frac00$ belirsizliği ve kök vardı. Eşlenikle çarpılıp bölündükten sonra $2x$ ortak çarpan olarak alındı, $x$ sadeleşti. Kalan terimlerde $x\to0$ yazılınca belirsizlik kalmadı ve sonuç $\frac44=1$ çıktı.

<!-- BELİRSİZ: Bu iki alıştırmanın ifadeleri altyazıda okunmuyor. Birincisinin çözüm adımları 01:53:09'daki uzun tekrar döngüsü ("yukarı ile yukarı ile ...") nedeniyle anlaşılmıyor ve cevabı duyulmuyor. -->

### 11.4 Örnek 17: $\frac{\sin ax}{bx}$

$$\lim_{x\to0}\frac{\sin ax}{bx},\qquad a,b\ne0$$

**Çözüm:** $\frac{\sin u}{u}$ oluşturmak için pay ve payda $a$ ile çarpılıp bölünür:

$$\lim_{x\to0}\frac{\sin ax}{ax}\cdot\frac{a}{b}$$

$u=ax$ denirse $x\to0$ iken $u\to0$. Kutudaki limit $1$'dir. **Sonuç:** $\frac ab$.

Hoca $a=0$ ise cevabın $0$ olacağını, $b$'nin ise sıfırdan farklı olması gerektiğini ekledi.

> **Hocanın vurgusu:** Genel kural bu. Bakın hiç ezber yapmadım. Lisede öğretmenler genelde "bu böyledir" diye öğretir ya da L'Hôpital ile bulursunuz. Burada mantığıyla yapıyoruz.

### 11.5 Örnek 18

Hoca bir soruyu daha ekrana yazıp öğrencilere bıraktı. Çözümde pay ve payda $x^2$'ye bölündü ve $\frac{\sin x^2}{x^2}$ ifadesi elde edildi. Aradan sonra hoca aynı soruya dönerek eşlenik yöntemi uygulandığını, işlemlerin uzun olduğunu söyledi. Paydanın eşleniğiyle çarpılıp $a^2-b^2$ özdeşliği kullanıldı, sadeleştirildi ve iyi bilinen $\frac{\sin x}{x}\to1$ formülünü elde etmek için payda $x$'e bölündü. Bazı terimler $0$'a, bazıları $1$'e gitti. **Hocanın verdiği sonuç:** $2$.

<!-- BELİRSİZ: Bu sorunun ifadesi altyazıda okunmuyor. 02:00:00 ile 02:08:38-02:11:02 arasındaki iki anlatımın aynı soruya mı yoksa iki ayrı soruya mı ait olduğu da kesin değil. -->

Hoca bu sırada öğrencilere bunu L'Hôpital ile yapmak isteyen olup olmadığını sordu ve L'Hôpital ile çözmenin zaman alacağını söyledi.

### 11.6 Örnek 19

$$\lim_{x\to0}\frac{\sin(1-\cos x)}{\sin x}$$

Hoca bu sorunun L'Hôpital ile de çözülebileceğini, ama yine ana formülü kullanarak çözdüğünü söyledi.

**Adım 1:** Pay ve payda $1-\cos x$ ile çarpılıp bölünür ve terimler toplanır:

$$\lim_{x\to0}\frac{\sin(1-\cos x)}{1-\cos x}\cdot\frac{1-\cos x}{\sin x}$$

**Adım 2:** $u=1-\cos x$. $x\to0$ iken $u\to0$. İlk çarpan $\lim_{u\to0}\frac{\sin u}{u}=1$.

**Adım 3:** İkinci çarpanda iyi bilinen formülü elde etmek için $x$ ile çarpılıp bölünür:

$$\frac{1-\cos x}{\sin x}=\frac{1-\cos x}{x}\cdot\frac{x}{\sin x}$$

Örnek 1'den $\frac{1-\cos x}{x}\to0$; $\frac{x}{\sin x}\to1$ (hocanın deyişiyle "$\frac{x}{\sin x}$ ya da $\frac{\sin x}{x}$ fark etmez"). İkinci çarpan $0$'a gider.

**Sonuç:** $1\cdot0=0$.

> **Hocanın vurgusu:** $1-\cos(\ldots)$ görürseniz ve belirsizlik $\frac00$ ise eşleniği olan $1+\cos(\ldots)$ ile çarpıp bölün ki $u\to0$ iken $\frac{\sin u}{u}$ biçiminde bir şey yakalayabilesiniz. Yaptığınız düzenlemenin hangi amaçla yapıldığı çok önemlidir.

### 11.7 Örnek 20

$$\lim_{x\to0^+}\frac{1-\cos\sqrt x}{x}$$

**Belirsizlik:** $\cos0=1$, pay $1-1=0$, payda $0$. $\frac00$.

**Eşlenik:** $1+\cos\sqrt x$ ile çarpılıp bölünür. $1-\cos^2\sqrt x=\sin^2\sqrt x$ olur. Paydadaki $x$, $\sqrt x\cdot\sqrt x$ olarak yazılır:

$$\lim_{x\to0^+}\frac{\sin\sqrt x}{\sqrt x}\cdot\frac{\sin\sqrt x}{\sqrt x}\cdot\frac{1}{1+\cos\sqrt x}$$

Hoca $\frac{1}{1+\cos\sqrt x}$ çarpanının unutulmamasını özellikle söyledi. $x\to0^+$ iken $\sqrt x\to0$, iki kesir $1$'e, son çarpan $\frac12$'ye gider. **Sonuç:** $\frac12$.

**Soru:** Paydadaki ikinci $\sqrt x$ nereden geldi?

**Cevap:** Orijinal sorunun paydasında $x$ çarpanı var. $x=\sqrt x\cdot\sqrt x$ yazıldı. Böylece iki tane $\frac{\sin u}{u}$ biçimi elde edildi.

> **Ek bilgi (derste anlatılmadı):** $\sqrt x$ yalnız $x\ge0$ için tanımlı olduğundan bu limit aslında sağdan limit olarak anlaşılmalıdır. $x<0$ tarafında ifade gerçel sayılarda tanımlı değildir.

### 11.8 Örnek 21: Sıkıştırma Teoremi

$$\lim_{x\to0}x^2\cos\frac1x$$

<!-- BELİRSİZ: İfadenin tam biçimi altyazıda okunmuyor. Anlatımda $\cos\frac1x$ ve "$-x^2$" geçiyor; $x^2\cos\frac1x$ biçimi bununla tutarlı. -->

Hoca önce bir belirsizlik olup olmadığına bakılmasını istedi. Bu örnekte belirsizlik yoktur: $x\to0$ iken $\frac1x\to\infty$ ve $\cos\frac1x$, $-1$ ile $+1$ arasında salınır. Bu, sıkıştırma teoreminin kullanılması gerektiğini gösterir; başka türlü çözülemez.

$$-1\le\cos\frac1x\le1\quad\Rightarrow\quad-x^2\le x^2\cos\frac1x\le x^2$$

$x\to0$ iken iki uç da $0$'a gider. Sıkıştırma teoremine göre **sonuç** $0$'dır.

### 11.9 Örnek 22

$$\lim_{x\to-1}\frac{1+x}{1+x\sqrt{2+x}}$$

**Belirsizlik:** $x=-1$ yazılınca pay $0$; payda $1+(-1)\cdot1=0$. $\frac00$.

**Eşlenik:** Paydanın eşleniği $1-x\sqrt{2+x}$ ile çarpılıp bölünür:

$$\lim_{x\to-1}\frac{(1+x)\left(1-x\sqrt{2+x}\right)}{1-x^2(2+x)}=\lim_{x\to-1}\frac{(1+x)\left(1-x\sqrt{2+x}\right)}{1-2x^2-x^3}$$

**Polinom bölmesi:** $x=-1$, $1-2x^2-x^3$ polinomunun köküdür ($1-2+1=0$). Bu yüzden $x+1$ çarpanı vardır. Hoca bölmeyi adım adım yaptı:

- En yüksek dereceli terim $-x^3$'ü yok etmek için $x+1$, $-x^2$ ile çarpılır: $-x^3-x^2$. Çıkarınca kalan $-x^2+1$ olur.
- $-x^2$'yi yok etmek için $x+1$, $-x$ ile çarpılır: $-x^2-x$. Çıkarınca kalan $x+1$ olur.
- $x+1$ için $+1$ ile çarpılır, kalan $0$.
- Kalanın derecesi bölenin derecesinden küçük olana kadar devam edilir.

Sonuç: $1-2x^2-x^3=(x+1)(-x^2-x+1)$. (sympy ile doğrulandı.)

**Sadeleştirme:** $1+x$ sadeleşir:

$$\lim_{x\to-1}\frac{1-x\sqrt{2+x}}{-x^2-x+1}=\frac{1-(-1)\cdot1}{-1+1+1}=\frac{2}{1}=2$$

**Sonuç:** Hoca "işlem hatası yapmazsak 2 gibi bir şey gelecek" dedi. Cevap $2$'dir.

> **Ders sonrası not:** Hoca paydayı açarken bir yerde "$1-2x^2-x^2$" dedi. Doğrusu $1-x^2(2+x)=1-2x^2-x^3$'tür.

Hoca polinom bölmesinin daha önce (lise ya da ortaokulda) öğrenildiğini hatırlattı.

## 12. Geçmiş Yıl Sınav Soruları

Hoca son olarak başka bir hocanın (Pınar Hoca) derleyip herkese açık paylaştığı "Uygulama 1" dosyasını açtı. Bu dosyada geçmiş yıl sınav soruları vardır. Dosyalar hocanın Avesis sayfasında da bulunuyor. Hoca çözümleri kapatamadığı için öğrencilerden çözüme bakmadan denemelerini istedi.

### 12.1 Örnek 23

$x\to\infty$ iken $1-\cos\frac2x$ içeren bir limit.

<!-- BELİRSİZ: Limitin tam ifadesi ve sonucu altyazıda okunmuyor. Anlatımdan bir çarpanın sonsuza, $1-\cos\frac2x$'in sıfıra gittiği bir $\infty\cdot0$ belirsizliği olduğu anlaşılıyor. -->

**Çözüm yolu:**

- $x\to\infty$ iken $\frac2x\to0$, $\cos0=1$, yani $1-\cos\frac2x\to0$. Diğer çarpan sonsuza gidiyor. $\infty\cdot0$ belirsizliği var.
- $1-\cos$ olduğu için eşlenik yöntemi: $1+\cos\frac2x$ ile çarpılıp bölünür. Pisagor özdeşliğinden $1-\cos^2\frac2x=\sin^2\frac2x$.
- $u=\frac2x$ alınır. $x\to\infty$ iken $u\to0$. Hoca bunun çok önemli olduğunu söyledi.
- $\frac{\sin u}{u}$ biçimini elde etmek için 4 ile çarpılıp bölünür ($u^2=\frac{4}{x^2}$ olduğundan).

### 12.2 Örnek 24

$x\to\frac\pi2$ iken $\frac00$ belirsizliği olan bir limit.

<!-- BELİRSİZ: Limitin tam ifadesi altyazıda okunmuyor. -->

**Çözüm yolu:** Hoca daha önce çözülen bir soruya (Örnek 2) çok benzediğini söyledi ve ipucu verdi:

- $u=x-\frac\pi2$ dönüşümü yapılır. $x\to\frac\pi2$ iken $u\to0$.
- $x$, $u$ cinsinden yazılır ve toplam formülü $\cos(a+b)=\cos a\cos b-\sin a\sin b$ kullanılır.
- $v=\frac u2$ denir. $u\to0$ iken $v\to0$ ve $\frac{\sin v}{v}\to1$.
- Paydada $v$ yok; $v$ oluşturmak için 2 ile çarpılıp bölünür.

**Sonuç:** $-\frac12$. Öğrencilerin çoğu $-\frac12$ buldu, bazıları $\frac12$ buldu; hoca cevapların yeniden kontrol edilmesini istedi.

**Soru (sohbetten):** Önceki soruda sıkıştırma teoremi kullanılmıyor mu?

**Cevap:** Önceki soruda sıkıştırma teoremi yok. Sıkıştırma teoremi için $\cos(\pm\infty)$ ya da $\sin(\pm\infty)$ gibi salınan bir ifade elde edilmelidir.

> **Hocanın vurgusu:** $u\to0$ iken $\frac{\sin u}{u}\to1$. Ama diğer formülü unutmayın: $u\to\infty$ iken $\frac{\sin u}{u}\to0$. Bu iki formülü karıştırmayın.

### 12.3 Örnek 25

$$\lim_{x\to0}\frac{\tan x-\sin x}{x^3}$$

<!-- BELİRSİZ: İfade altyazıda sözlü okunmuyor; hocanın anlatımı ("tanjant yerine sinüs bölü kosinüs, payda eşitleyin, sinüs x bölü x'i içeren sinüs x bölü x küp var, 1-kosinüs x'in eşleniği, sonuç 1/2") ve kısa notla tutarlı olarak yazıldı. -->

**Adım 1:** $\tan x=\frac{\sin x}{\cos x}$ yazılır ve payda eşitlenir:

$$\frac{\frac{\sin x}{\cos x}-\sin x}{x^3}=\frac{\sin x(1-\cos x)}{x^3\cos x}$$

**Adım 2:** Çarpanlara dağıtılır:

$$\frac{\sin x}{x}\cdot\frac{1-\cos x}{x^2}\cdot\frac{1}{\cos x}$$

**Adım 3:** $1-\cos x$ eşleniği $1+\cos x$ ile çarpılıp bölünür, belirsizlik veren çarpanlar giderilir:

$$\frac{1-\cos x}{x^2}=\left(\frac{\sin x}{x}\right)^2\cdot\frac{1}{1+\cos x}\to1\cdot\frac12$$

**Sonuç:** $1\cdot\frac12\cdot1=\frac12$. (sympy ile doğrulandı.)

### 12.4 Örnek 26

$$\lim_{x\to0}\frac{\sqrt{2+\sin x}-\sqrt{1+\cos x}}{\tan x}$$

Bu sırada hocanın bağlantısı koptu; geri geldiğinde son soruyu yeniden anlattı.

**Adım 1: Eşlenik.** Kök sembolleri görüldüğünde eşlenik yöntemi uygulanır. Pay ve payda $\sqrt{2+\sin x}+\sqrt{1+\cos x}$ ile çarpılıp bölünür. $(A-B)(A+B)=A^2-B^2$:

$$\frac{(2+\sin x)-(1+\cos x)}{\tan x\left(\sqrt{2+\sin x}+\sqrt{1+\cos x}\right)}=\frac{1+\sin x-\cos x}{\tan x\left(\sqrt{2+\sin x}+\sqrt{1+\cos x}\right)}$$

**Adım 2: $\tan x$ yerine $\frac{\sin x}{\cos x}$.** Böylece $\cos x$ paya geçer:

$$\frac{\cos x\left[(1-\cos x)+\sin x\right]}{\sin x\left(\sqrt{2+\sin x}+\sqrt{1+\cos x}\right)}$$

**Adım 3: Gruplama ve dağıtma.** $1-\cos x$ bir arada tutulur (bir grup), $\sin x$ ayrı alınır (diğer grup). Pay dağıtılınca:

$$\frac{1-\cos x}{\sin x}\cdot\frac{\cos x}{\sqrt{2+\sin x}+\sqrt{1+\cos x}}+\frac{\cos x}{\sqrt{2+\sin x}+\sqrt{1+\cos x}}$$

İkinci terimde $\frac{\sin x}{\sin x}$ sadeleşti; geriye yalnız $\cos x$ kaldı.

**Adım 4: Limitler.**

- $\frac{1-\cos x}{\sin x}=\frac{1-\cos x}{x}\cdot\frac{x}{\sin x}\to0\cdot1=0$. Birinci terim $0$'a gider.
- İkinci terim: $\frac{\cos0}{\sqrt2+\sqrt2}=\frac{1}{2\sqrt2}$.

**Sonuç:** $\frac{1}{2\sqrt2}=\frac{\sqrt2}{4}$. (sympy ile doğrulandı.)

**Soru:** Paydaki "$+\cos x$ bölü kök içindeki $\sin x$ ve kök içindeki $1+\cos x$" kısmı nasıl elde edildi?

**Cevap:** Payda bir toplam var. Hoca gruplama yaptı: $1-\cos x$'i bir arada düşündü ($a$), $\sin x$'i ayrı aldı ($b$). Dağıttıktan sonra sadeleştirdi: $\frac{\sin x}{\cos x}$'teki $\sin x$ gitti, yalnız $\cos x$ kaldı.

## 13. Örnek Sorular

Bu derste video karesi yok. Aşağıdaki sorular derste hocanın sözlü okuduğu ya da öğrencilere "çözün" diye bıraktığı sorulardır.

**Soru 1** (derste sözlü, 00:13:04, ödev): Birim çemberden elde edilen $\frac{\sin\theta}{2}<\frac\theta2<\frac{\tan\theta}{2}$ eşitsizliği ve sıkıştırma teoremiyle $\lim_{\theta\to0^+}\frac{\sin\theta}{\theta}=1$ olduğunu gösterin.

> **Çözüm (derste verilmedi):** Her taraf $\frac{\sin\theta}{2}>0$'a bölünür: $1<\frac{\theta}{\sin\theta}<\frac{1}{\cos\theta}$. Terslerine geçilir: $\cos\theta<\frac{\sin\theta}{\theta}<1$. $\theta\to0^+$ iken $\cos\theta\to1$; sıkıştırma teoremine göre limit $1$'dir.

**Soru 2** (derste sözlü, 00:20:50): $\lim_{x\to0}\frac{1-\cos x}{x}$ limitini L'Hôpital kullanmadan bulun. Çözüm Örnek 1'de verildi: $0$.

**Soru 3** (derste sözlü, 00:32:48): $\lim_{x\to1}\frac{\sin(x^2-1)}{x-1}$ limitini L'Hôpital kullanmadan bulun. Çözüm Örnek 3'te verildi: $2$.

**Soru 4** (derste sözlü, 00:35:25): $\lim_{x\to0}\frac{\sin(\sin x)}{x}$ limitini L'Hôpital kullanmadan bulun. Çözüm Örnek 4'te verildi: $1$.

**Soru 5** (derste sözlü, 00:42:19): $\lim_{x\to\infty}\frac{x\tan\frac{\sin x}{x}}{\sin x}$ limitini L'Hôpital kullanmadan bulun. Çözüm Örnek 6'da verildi: $1$.

**Soru 6** (derste sözlü, 00:52:41, ödev): Örnek 7'deki sol limitin son adımını tamamlayın.

> **Çözüm (derste verilmedi):** $\frac{x^3-8}{(x-2)\left(\sqrt{x^3+1}+3\right)}=\frac{x^2+2x+4}{\sqrt{x^3+1}+3}\to\frac{12}{6}=2$. Hoca yalnız sonucu (2) söyledi.

**Soru 7** (derste sözlü, 01:29:09-01:30:42): "$x^2-10=x\sin x$ denkleminin gerçel bir çözümü vardır" ifadesi doğru mu? Çözüm Örnek 13'te verildi: doğru.

**Soru 8** (derste sözlü, 01:35:24): $f(x)=1-\frac{x^2}{4}-\cos x$ fonksiyonu için verilen maddelerin doğru olduğunu gösterin. Çözüm Örnek 14'te verildi. <!-- BELİRSİZ: Maddelerin tam metni altyazıda yok. -->

**Soru 9** (derste sözlü, 02:13:17): $\lim_{x\to0}\frac{\sin(1-\cos x)}{\sin x}$ limitini bulun. Çözüm Örnek 19'da verildi: $0$.

**Soru 10** (derste sözlü, 02:23:30): $\lim_{x\to-1}\frac{1+x}{1+x\sqrt{2+x}}$ limitini bulun. Çözüm Örnek 22'de verildi: $2$.

**Soru 11** (derste sözlü, 01:49:28): Örnek 16'daki $\lim_{x\to\infty}\left(\sqrt{x^2+1}-\sqrt{x^2-1}\right)$ limitini L'Hôpital ile çözmeyi deneyin. Hoca bunun büyük olasılıkla zor olacağını söyledi; eşlenik yöntemiyle sonuç $0$'dır.

## Dersin Toparlaması

Bu derste L'Hôpital kuralı kullanılmadan trigonometrik limitlerin nasıl hesaplanacağı öğrenildi. Temel taş, birim çemberde alan karşılaştırması ve sıkıştırma teoremiyle kanıtlanan $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$ formülüdür. Bu formülün genel hâli, $x\to a$ iken $u(x)\to0$ olmak koşuluyla $\frac{\sin u(x)}{u(x)}\to1$ ve $\frac{\tan u(x)}{u(x)}\to1$ kuralıdır. Soruları bu kurala benzetmek için dört temel araç kullanıldı: çarpıp bölerek $u$'yu paydada oluşturmak, değişken değiştirme ve toplam formülleri, $1-\cos$ ve kök içeren ifadelerde eşlenik yöntemi, salınan ifadelerde sıkıştırma teoremi. Hocanın sürekli vurguladığı nokta, $\lim_{x\to0}\frac{\sin x}{x}=1$ ile $\lim_{x\to\infty}\frac{\sin x}{x}=0$ formüllerinin karıştırılmaması ve her düzenlemenin hangi amaçla yapıldığının bilinmesiydi.

Ardından süreklilik konusu iki yönden genişletildi. Ara değer teoremi, kapalı aralıkta sürekli bir fonksiyonun uç değerleri arasındaki her değeri aldığını söyler. Uç değerler zıt işaretliyse aralıkta en az bir kök vardır. Test tipi sorularda çift fonksiyon simetrisiyle birlikte kök sayısı hakkında sonuç çıkarıldı. Süreksizlik türleri de kaldırılabilir, sıçrama ve sonsuz süreksizlik olarak sınıflandırıldı. Hoca, üstel fonksiyon içeren ara değer teoremi örneklerinin üstel fonksiyon işlendikten sonra yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
