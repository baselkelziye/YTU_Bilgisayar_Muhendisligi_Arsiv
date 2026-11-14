# Ders 2 Genişletilmiş Notu: Sonsuz Limitler, Asimptotlar, Limitin Kesin Tanımı ve Süreklilik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi
- 2. Sıkıştırma Teoremi Alıştırması
- 3. Parçalı Fonksiyonda Limit İçin Sabit Bulma
- 4. Eşlenik Yöntemiyle Limit
- 5. Sonsuz Limitler ve Düşey Asimptot
- 6. Sonsuzda Limit ve Yatay Asimptot
- 7. Polinomların Sonsuzdaki Davranışı
- 8. Köklü Rasyonel İfadelerde Yatay Asimptot
- 9. Yatay ve Düşey Asimptot Birlikte
- 10. Limitin Kesin Tanımı ($\varepsilon$-$\delta$)
- 11. Bir Noktada Süreklilik
- 12. Süreklilik Kuralları ve Bileşke
- 13. Bir Aralıkta Süreklilik
- 14. Doğru/Yanlış Alıştırmaları

## 1. Dersin Çerçevesi

Ders, hocanın beyaz tahtayı paylaşmasıyla başladı. Hoca önce kendini tanıttı ve dersin çerçevesini çizdi. Dersin kodu MAT 1071'dir. Konu tek değişkenli fonksiyonlar (single variable functions) teorisidir: $x$ bağımsız değişken, $y$ bağımlı değişkendir. Ana başlıklar fonksiyonun tanımı ve temel kuralları, limit, süreklilik, türev ve integraldir. Ders kitabı olarak büyük ölçüde Thomas takip ediliyor.

Öğrenciler bir önceki derste tanıştıklarını hatırlatınca hoca, iki grubu olduğunu ve bu dersi diğer grupla karıştırdığını söyledi. Ardından soru çözmeye geçti. Hocaya göre henüz çok soru çözülecek kadar konu işlenmedi; temel özellikler görüldü. Bu yüzden önce işlenen konulara dair alıştırmalar yapılacak, sonra konuda ilerlenecek.

## 2. Sıkıştırma Teoremi Alıştırması

İlk alıştırma sıkıştırma teoremi (Sandwich Theorem) üzerineydi.

**Örnek 1.** $c$ bir sabit olsun. $\lim_{x\to c}f(x)=0$ olsun. Bir $K$ sabiti için $|g(x)|\le K$ koşulu sağlansın. $\lim_{x\to c}f(x)g(x)=0$ olduğunu gösterin.

Hoca önce hipotezin anlamını açıkladı. $|g(x)|\le K$, $g$'nin sınırlı (bounded) olduğunu söyler. Yani $g$'nin grafiği $y=K$ ve $y=-K$ yatay doğruları arasında salınır (oscillates).

Hocanın verdiği ipucu şudur: Böyle bir mutlak değer eşitsizliği görürseniz sıkıştırma teoremini kullanabilirsiniz. Bunun için çarpım $f(x)g(x)$ etrafında bir sıralama kurmak gerekir.

- Mutlak değerin çarpım özelliğiyle ve hipotezle:

$$0\le|f(x)g(x)|=|f(x)|\,|g(x)|\le K|f(x)|$$

- Mutlak değer eşitsizliği açılır (ara adım eklendi):

$$-K|f(x)|\le f(x)g(x)\le K|f(x)|$$

- $x\to c$ iken $f(x)\to0$, dolayısıyla $|f(x)|\to0$. Bu yüzden hem üst sınır $K|f(x)|$ hem alt sınır $-K|f(x)|$ sıfıra gider.
- Sıkıştırma teoremine göre ortadaki terim de sıfıra gider: $\lim_{x\to c}f(x)g(x)=0$.

Bir öğrenci soruyu yeniden göstermesini istedi. Hoca soruyu tekrar okurken slaytta "$x\to0$" yazdığını fark etti ve bunun "$x\to c$" olması gerektiğini söyledi.

> **Ders sonrası not:** Hoca anlatım sırasında bir yerde "$x\to c$ iken $f(x)\to c$" dedi; hipotez gereği doğrusu $f(x)\to0$'dır.

## 3. Parçalı Fonksiyonda Limit İçin Sabit Bulma

Hoca bunun aslında ödev olduğunu ama basit olduğu için çözeceğini söyledi.

**Örnek 2.**

$$g(x)=\begin{cases}x^2-5x, & x\le-1\\ ax^3-7, & x>-1\end{cases}$$

$g$'nin $x=-1$ noktasında limiti olması için $a$ sabiti ne olmalıdır?

Bir noktada limitin varlığından söz etmek için soldan ve sağdan limitlere bakmak gerekir.

- $x\to-1^-$ iken $x\le-1$ olduğundan birinci kural kullanılır. Belirsizlik (indeterminate form) yok, doğrudan yerine konur:

$$\lim_{x\to-1^-}(x^2-5x)=1+5=6$$

- $x\to-1^+$ iken ikinci kural kullanılır:

$$\lim_{x\to-1^+}(ax^3-7)=-a-7$$

- Limitin var olması için iki tek taraflı limit eşit olmalı:

$$6=-a-7\quad\Rightarrow\quad a=-13$$

### 3.1 Ödev: Çarpanlara Ayırma Formülü

Hoca ardından ödev olarak bırakılan limitlerden söz etti. Bu limitler şu çarpanlara ayırma formülüyle hesaplanabilir:

$$x^n-a^n=(x-a)\left(x^{n-1}+x^{n-2}a+\dots+xa^{n-2}+a^{n-1}\right)$$

Örnek olarak $\lim_{x\to2}\frac{x^5-32}{x-2}$ verildi. $x=2$ yazınca $\frac00$ belirsizliği çıkar. $x^5-2^5$ formülle çarpanlara ayrılırsa belirsizliğe yol açan $x-2$ sadeleşir.

<!-- BELİRSİZ: Ödev listesindeki diğer limitlerin ifadeleri altyazıda geçmiyor. -->

**Soru:** L'Hôpital kuralını kullanabilir miyiz? **Cevap:** Hayır. Henüz türev öğretilmedi. Önce türevsiz, L'Hôpital'siz yöntemler öğrenilmeli.

> **Hocanın vurgusu:** Öyle sorular var ki L'Hôpital işe yaramaz. Bu yüzden bu yöntemleri öğrenmek zorunludur. Ödevlerde L'Hôpital uygulamayın.

## 4. Eşlenik Yöntemiyle Limit

Sıradaki konu eşlenik içeren limitlerdi (limits involving conjugates). Yöntem: kesir, köklü ifadenin eşleniğiyle çarpılıp bölünür.

**Örnek 3.** $\lim_{x\to1}\dfrac{x-1}{\sqrt{4x+5}-3}$

- $x=1$ yazınca pay $0$, payda $\sqrt9-3=0$. $\frac00$ belirsizliği var (ara adım eklendi).
- Pay ve payda $\sqrt{4x+5}+3$ ile çarpılır. $(a-b)(a+b)=a^2-b^2$ özdeşliğiyle payda:

$$\left(\sqrt{4x+5}-3\right)\left(\sqrt{4x+5}+3\right)=4x+5-9=4x-4=4(x-1)$$

- Böylece:

$$\lim_{x\to1}\frac{(x-1)\left(\sqrt{4x+5}+3\right)}{4(x-1)}=\lim_{x\to1}\frac{\sqrt{4x+5}+3}{4}=\frac{3+3}{4}=\frac32$$

Hoca sonucu öğrencilere kontrol ettirdi; hata bulunmadı. Diğer soruların da bu yöntemle yapılabileceğini, yine L'Hôpital uygulanmaması gerektiğini söyledi.

> **Ders sonrası not:** Hoca özdeşliği söylerken "$(a-b)(a+b)=a^2+b^2$" dedi; doğrusu $a^2-b^2$'dir. Hesapta doğru özdeşlik kullanıldı.

## 5. Sonsuz Limitler ve Düşey Asimptot

### 5.1 Sonsuz Limit Kavramı

Hoca grafikler üzerinden sonsuz limitleri (infinite limits) anlattı. Sonsuz limitler genellikle fonksiyonun kuralını tanımsız yapan noktalarda ortaya çıkar.

- Birinci grafikte $x$, $a$'ya sağdan yaklaşırken $f(x)$ sınırsız yukarı çıkar: $\lim_{x\to a^+}f(x)=+\infty$.
- Aynı grafik soldan da yukarı çıkıyorsa: $\lim_{x\to a^-}f(x)=+\infty$.
- Başka bir grafikte $x\to a^+$ iken $f(x)$ sınırsız aşağı iner: $\lim_{x\to a^+}f(x)=-\infty$.

Tek taraflı sonsuz limitlerde (one-sided infinite limits) yalnız bir yönden sonsuza gidiş vardır. Dört durum, $x\to a^+$ ya da $x\to a^-$ ile $f(x)\to+\infty$ ya da $-\infty$ birleşimleridir. Bu durumlarda $x=a$ doğrusu düşey asimptottur (vertical asymptote).

<!-- BELİRSİZ: 00:18:24-00:18:52 ve 00:23:28-00:24:56 arasında tahtadaki tanım ve grafik anlatımı altyazıda anlaşılmıyor. -->

### 5.2 Sonsuz Limitin İşaretini Bulmak

Hoca öğrencilere birkaç sonsuz limit verip "eksi sonsuz mu, artı sonsuz mu?" diye sordu. Grafik çizmeye gerek olmadığını, işaretin cebirsel olarak çarpanların işaretinden bulunabileceğini söyledi. Bir öğrenci "ilki eksi sonsuz, ikincisi artı sonsuz" diye cevap verdi; hoca "öyle bir şey olacak" dedi.

<!-- BELİRSİZ: Bu sorudaki fonksiyonlar altyazıda okunmuyor. -->

**Örnek 4.** Paydasında çift kuvvetli bir çarpan bulunan, $x\to1$ limiti sorulan bir fonksiyon. Payda, $x$ hem soldan hem sağdan $1$'e yaklaşırken $0^+$'ya gider; çünkü çift kuvvet her zaman pozitiftir. Bu yüzden sonuç her iki taraftan $+\infty$'dur. Hoca grafiğin $x=1$'in iki yanında yukarı çıkacağını önceden tahmin edebileceğimizi söyledi.

<!-- BELİRSİZ: Örnek 4'ün tam fonksiyonu altyazıda geçmiyor; 00:22:06 civarında altyazı döngüye giriyor. -->

**Örnek 5.** Paydasında $x-2$ ve $x-3$ çarpanları olan bir rasyonel fonksiyonun $x=3$'teki tek taraflı limitleri incelendi.

- $x\to3^+$: $x-3>0$ ve sıfıra yaklaşır ($0^+$). $x-2>0$. Diğer çarpan her zaman pozitif. Sonuç $+\infty$, grafik sınırsız yukarı çıkar.
- $x\to3^-$: $x-3<0$ ama sıfıra yaklaşır ($0^-$). Diğer çarpanlar pozitif. İşaretler "pozitif, pozitif, negatif" olduğundan sonuç $-\infty$, grafik sınırsız aşağı iner.

<!-- BELİRSİZ: Örnek 5'in payı ve "her zaman pozitif" denen çarpanı altyazıda okunmuyor; 00:25:15 civarında altyazı döngüye giriyor. -->

**Örnek 6.** $x=-4$ pay ve paydaya yazıldığında $\frac00$ belirsizliği veren bir rasyonel fonksiyon.

- Önce rasyonel fonksiyon çarpanlarına ayrılır ve ortak çarpan sadeleştirilir.
- Sadeleşmeden sonra paydada kalan $x+4$ çarpanı sonsuz limite yol açar.
- $x\to-4^+$ iken $x+4\to0^+$. Diğer kısım negatif bir sayıya yaklaşır. Sonuç $-\infty$.

<!-- BELİRSİZ: Örnek 6'nın fonksiyonu altyazıda okunmuyor. Yöntem: sadeleştir, sonra her çarpanın işaretine bak. -->

## 6. Sonsuzda Limit ve Yatay Asimptot

### 6.1 Tanım

Yatay asimptotta (horizontal asymptote) grafiğin sonsuzdaki davranışı incelenir. Düşey asimptottan farkı şudur: Burada limit noktası $+\infty$ ya da $-\infty$'dur, ama limitin sonucu sonlu olmalıdır.

**Tanım (yatay asimptot):**

- $\lim_{x\to\infty}f(x)=L$ ya da $\lim_{x\to-\infty}f(x)=L$ ve $L$ sonlu ise,
- $y=L$ doğrusu $f$'nin yatay asimptotudur.
- Yani $x$ yeterince büyüdükçe (ya da yeterince küçüldükçe) grafik $y=L$ doğrusuna benzer.

**Soru:** Üst taraftaki, $x$'in sonsuza gittiği yeri anlamadım. **Cevap:** Tanım bu. $x$ ekseni üzerinde sağa ya da sola yeterince ilerlediğinizde, hemen üstteki fonksiyon değerleri düz bir doğruya yaklaşıyorsa, yani grafik $y=L$ doğrusu gibi davranıyorsa, $y=L$'ye yatay asimptot denir.

**Soru:** Yatay asimptotları nasıl bulacağız? **Cevap:** Doğrudan $+\infty$ ve $-\infty$'daki limitlere bakılır. Limit sonlu bir değere gidiyorsa, fonksiyonun yaklaştığı o sonlu değer yatay asimptotu verir.

Temel araç şu gözlemdir: Sabit (ya da sınırlı) bir ifade, sınırsız bir ifadeye bölündüğünde sıfıra gider.

### 6.2 Örnek: $2+\frac{10}{x^2}$

**Örnek 7.** $f(x)=2+\dfrac{10}{x^2}$ fonksiyonunun asimptotlarını inceleyin.

- $x\to\infty$: $2$ sabittir. $\frac{10}{x^2}$'de sabit bir sayı sınırsız bir ifadeye bölünüyor, bu yüzden sıfıra gider. Sonuç $2$. $y=2$, $+\infty$'da yatay asimptottur.
- $x\to-\infty$: Aynı şekilde sonuç $2$. $y=2$, $-\infty$'da da yatay asimptottur.
- $x\to0^\pm$: $x^2\to0^+$, dolayısıyla $\frac{10}{x^2}\to+\infty$ ve $f(x)\to+\infty$. Grafik sınırsız yukarı çıkar. $x=0$ doğrusu, yani $y$ ekseni, düşey asimptottur.

> **Ders sonrası not:** Hoca bir yerde "sınırsız ifade bölü sınırlı ifade sıfıra gider" deyip hemen "pardon, sınırlı ifade bölü sınırsız ifade" diye düzeltti. Doğrusu düzeltilmiş hâlidir.

### 6.3 Örnek: $5+\frac{\sin x}{\sqrt x}$

**Örnek 8.** $f(x)=5+\dfrac{\sin x}{\sqrt x}$ fonksiyonunun $x\to\infty$'daki yatay asimptotunu bulun.

Hoca burada sınırlı bir ifade görüldüğünü vurguladı. Sinüs fonksiyonunun grafiği hatırlanırsa $x\to\infty$ iken $\sin x$, $-1$ ile $+1$ arasında salınır.

- $-1\le\sin x\le1$. $x>0$ için $\sqrt x>0$ olduğundan eşitsizlik $\sqrt x$'e bölünebilir:

$$-\frac{1}{\sqrt x}\le\frac{\sin x}{\sqrt x}\le\frac{1}{\sqrt x}$$

- Alt sınır ve üst sınır sıfıra gider: sabit bölü sınırsız ifade.
- Sıkıştırma teoremine göre $\frac{\sin x}{\sqrt x}\to0$.
- Hoca önce $y=0$ doğrusunu ($x$ ekseni) söyledi, sonra baştaki $5$'i hatırladı: Sabit terimi unutmayın. Sonuç $5+0=5$. Yatay asimptot $y=5$'tir.

> **Hocanın vurgusu:** $x\to\infty$ iken sınırlı (salınan) bir ifade görürseniz bu çok önemlidir; sıkıştırma teoremini düşünün.

### 6.4 Ne Yatay Ne Düşey Asimptot

Bazı fonksiyonlarda $x\to\infty$ iken $f(x)\to\infty$, $x\to-\infty$ iken $f(x)\to-\infty$ olur. Örneğin $y=x^3$. Böyle durumlarda ne düşey ne de yatay asimptot vardır.

## 7. Polinomların Sonsuzdaki Davranışı

### 7.1 Kuvvet Fonksiyonları

Hoca genel durumları tanıttı. $n$ pozitif bir tam sayı olsun.

- $n$ pozitif çift tam sayı ise $x\to+\infty$ ve $x\to-\infty$ iken $x^n\to+\infty$.
- $n$ pozitif tek tam sayı ise $x\to+\infty$ iken $x^n\to+\infty$, $x\to-\infty$ iken $x^n\to-\infty$.
- Sabit bir terim (1 olmak zorunda değil) bölü sınırsız bir ifade her zaman sıfıra yaklaşır. Örneğin $n>0$ için $\frac{c}{x^n}\to0$.

<!-- BELİRSİZ: 00:38:22 civarında altyazı döngüye giriyor; bu kısımdaki tahta yazısı okunmuyor. -->

### 7.2 Polinomlar

$p(x)=a_nx^n+a_{n-1}x^{n-1}+\dots+a_0$ için $x\to\pm\infty$ iken $p(x)\to\pm\infty$ olur. İşaret, polinomun derecesine (tek/çift) ve baş katsayı $a_n$'nin işaretine bağlıdır. Yani yalnız baş terime ve onun işaretine bakılır.

**Örnek 9.** Baş terimi $3x^4$ olan bir polinom.

- Baş katsayı pozitif.
- $x\to\infty$ iken $+\infty$.
- $x\to-\infty$ iken de $+\infty$, çünkü kuvvet çifttir.

**Örnek 10.** Baş terimi $-2x^3$ olan bir polinom.

- $x\to-\infty$ iken $x^3\to-\infty$. Önündeki eksiyle birlikte $-2\cdot(-\infty)=+\infty$.
- $x\to+\infty$ iken $-\infty$.

<!-- BELİRSİZ: Örnek 9 ve 10'daki polinomların baş terim dışındaki terimleri altyazıda geçmiyor. -->

## 8. Köklü Rasyonel İfadelerde Yatay Asimptot

### 8.1 İşaretin Önemi: $\sqrt{x^6}$

Hoca rasyonel ifadelerle ilgili bir örnekte, pay ve paydada ortak çarpan alınca sabit bölü sınırsız terimlerin sıfıra gittiğini gösterdi. $x\to\infty$ iken sonuç $2$ çıktı; $y=2$ yatay asimptottur. Sonra aynı ifadeyi $x\to-\infty$ için inceledi ve özellikle uyardı.

> **Hocanın vurgusu:** $x$'i $-\infty$'a götürürken çok dikkatli olun. Kökün içinden $x^3$ değil, $-x^3$ çıkar.

Bu yüzden $x\to-\infty$'da sonuç $-2$ çıktı. Grafik $x\to\infty$ iken $y=2$ doğrusuna, $x\to-\infty$ iken $y=-2$ doğrusuna benzer.

<!-- BELİRSİZ: 00:40:23-00:42:45 arasındaki örneğin fonksiyonu altyazıda okunmuyor; yalnız sonuçlar ($+\infty$'da $y=2$, $-\infty$'da $y=-2$) ve kökten $-x^3$ çıktığı söyleniyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu uyarının nedeni $\sqrt{u^2}=|u|$ eşitliğidir. $x<0$ iken $x^3<0$ olduğundan $\sqrt{x^6}=|x^3|=-x^3$ olur. Kökün içinden $x$'in kuvveti çıkarılırken bu yüzden $x$'in işaretine bakılmalıdır.

### 8.2 Kısa Alıştırmalar

Hoca ardından öğrencilere kısa alıştırmalar verdi. Birinde $x\to\infty$ iken sıfıra giden terimler atılınca sonuç $3$, diğerinde $5$ çıktı. Üçüncüsü için "ne yapabiliriz?" diye sordu; cevap sıkıştırma teoremiydi.

<!-- BELİRSİZ: Sonucu 3 ve 5 çıkan alıştırmaların fonksiyonları altyazıda okunmuyor. -->

**Örnek 11.** $\displaystyle\lim_{\theta\to\infty}\frac{\cos\theta}{\theta^2}$

Bir öğrenci açının en fazla 360 olabileceğini düşünüp düşünemeyeceğini sordu. Hoca üniversitede artık derecelerle değil, radyanla çalışıldığını söyledi. 360 derece $2\pi$'ye, yaklaşık $2\cdot3{,}14$'e karşılık gelir. Burada $\theta$ bir derece değil, gerçel bir sayı olarak düşünülmelidir.

**Soru:** Kosinüsün çift fonksiyon olmasını kullanacak mıyız? **Cevap:** Gerek yok. Sınırlı bir fonksiyon görürseniz ve $\theta$ sonsuza gidiyorsa, kosinüs ve sinüs $-1$ ile $+1$ arasında salınır. Bu durumda limit büyük ölçüde sıkıştırma teoremiyle ilgilidir.

> **Hocanın vurgusu:** $\theta\to\infty$ iken salınan bir fonksiyon varsa limit "%99" sıkıştırma teoremiyle ilgilidir. Çoğu öğrenci burada L'Hôpital kullanmaya kalkar; sakın kullanmayın.

Çözüm:

- Sınırlılık ön koşuldur. Yoksa sıkıştırma teoreminden söz edilemez.
- Her gerçel $\theta$ için (radyan) $-1\le\cos\theta\le1$.
- İstenen ifadeyi elde etmek için eşitsizliğin iki tarafı $\theta^2>0$'ye bölünür:

$$-\frac{1}{\theta^2}\le\frac{\cos\theta}{\theta^2}\le\frac{1}{\theta^2}$$

- $\theta\to\infty$ iken iki sınır da sıfıra gider: sabit bölü sınırsız terim.
- Sıkıştırma teoremine göre $\lim_{\theta\to\infty}\frac{\cos\theta}{\theta^2}=0$.

Diğer örnekler ödev olarak bırakıldı.

### 8.3 Örnek: Kök İçeren Rasyonel Fonksiyon

**Örnek 12.** Aşağıdaki fonksiyonun yatay asimptotlarını inceleyin:

$$f(x)=\frac{4x^3+1}{2x^3+\sqrt{16x^6+1}}$$

<!-- BELİRSİZ: Fonksiyon altyazıda tam okunmuyor; çözümdeki "4 artı 1 bölü x küp", "x üzeri 6" ve "4 bölü 6" ifadelerinden ve kısa nottan kuruldu. -->

Hoca, kâğıt kalemle herkesin çözmeye çalışmasını istedi; "artık topu size atacağım" dedi. Bir öğrenci $\frac23$ buldu.

- Payın baş terimi $x^3$'tür. Pay ve paydada $x^3$ ortak çarpanı alınır.
- Kökün içinden $x^6$ ortak çarpanı alınır. $x\to\infty$ iken $x$ pozitif olduğundan $\sqrt{x^6}=x^3$ yazılabilir:

$$\sqrt{16x^6+1}=x^3\sqrt{16+\frac{1}{x^6}}$$

- Böylece:

$$\lim_{x\to\infty}\frac{x^3\left(4+\frac{1}{x^3}\right)}{x^3\left(2+\sqrt{16+\frac{1}{x^6}}\right)}=\frac{4+0}{2+\sqrt{16}}=\frac{4}{2+4}=\frac23$$

- $+\infty$'da yatay asimptot $y=\frac23$'tür.

Hoca $x\to-\infty$ durumunu ödev bıraktı. Uyarısı: Bu durumda kökten çıkan ifadenin önüne eksi gelir, çünkü $\sqrt{x^6}$ aslında $|x^3|$'tür.

> **Ders sonrası not:** $x\to-\infty$ durumu derste çözülmedi. $\sqrt{16x^6+1}=-x^3\sqrt{16+\frac{1}{x^6}}$ alınırsa limit $\frac{4}{2-4}=-2$ çıkar; $-\infty$'da yatay asimptot $y=-2$'dir (sympy ile doğrulandı).

> **Hocanın vurgusu:** L'Hôpital uygulamaya çalışmayın. Bu yöntemi kendinizde geliştirin, yoksa ileride sıkıntı yaşayabilirsiniz.

## 9. Yatay ve Düşey Asimptot Birlikte

**Örnek 13.** Aşağıdaki fonksiyonun yatay ve düşey asimptotlarını inceleyin:

$$f(x)=\frac{\sqrt{x^2+2x+6}-3}{x-1}$$

Hoca soruyu öğrencilere bıraktı. Bir öğrenci düşey asimptot için "$x=-3$ mü?" diye sordu. Hoca biçimleri hatırlattı: yatay asimptotlar $y=L$, düşey asimptotlar $x=a$ biçimindedir. Yatay asimptotta grafik giderken yatay bir doğruya benzemeye çalışır. Bir öğrenci yatay asimptot için $y=0$ dedi.

> **Ders sonrası not:** Derste söylenen "$x=-3$" ve "$y=0$" tahminleri hesapla doğrulanmıyor. Fonksiyonun tek tanımsız noktası $x=1$'dir ($x^2+2x+6$ hiçbir gerçel sayıda sıfır olmaz). Aşağıdaki hesapta düşey asimptot çıkmıyor, $+\infty$'da yatay asimptot $y=1$ bulunuyor.

### 9.1 Düşey Asimptot Adayı: $x=1$

- $x\to1$ iken doğrudan yerine koyunca pay $\sqrt9-3=0$, payda $0$. Hoca dikkat çekti: $\frac00$ belirsizliği var, doğrudan yerine koymak işe yaramaz.
- Paydaki kökün eşleniği $\sqrt{x^2+2x+6}+3$ ile çarpılıp bölünür.

**Soru:** Yukarıdaki kökün eşleniğini alabilir miyiz? **Cevap:** Tabii. Eşleniksiz olmaz.

$$\lim_{x\to1}\frac{x^2+2x+6-9}{(x-1)\left(\sqrt{x^2+2x+6}+3\right)}$$

- Pay çarpanlara ayrılır: $x^2+2x-3=(x+3)(x-1)$.

$$\lim_{x\to1}\frac{(x+3)(x-1)}{(x-1)\left(\sqrt{x^2+2x+6}+3\right)}=\frac{1+3}{\sqrt9+3}=\frac46=\frac23$$

Hoca test sınavında bu kadar uzun yazılmayacağını, anlaşılsın diye uzun yaptığını söyledi.

> **Ders sonrası not:** Hoca eşlenikle çarpma adımında "$x^2+2x+6$ eksi 19" dedi; doğrusu eksi $9$'dur ($3^2=9$). Sonraki adımlar doğru değerle yapıldı.

Sonuç sonlu bir sayıdır. Bu yüzden $x=1$ düşey asimptot değildir. Sonlu bir noktaya yaklaşırken sonsuz bir sonuç çıkmadığı için bu fonksiyonun düşey asimptotu yoktur.

> **Hocanın vurgusu:** Düşey asimptot olması için sonlu bir değere yaklaşırken elde edilen sonuç sonsuz olmalıdır. Sonlu bir değer çıkarsa düşey asimptot yoktur.

**Soru:** Dikey ve yatayı neye göre belirlediğimizi tekrarlar mısınız? **Cevap:** Dikey asimptot için sonlu bir değere yaklaşırken grafik sonsuza doğru sıçramalıdır. Burada sonuç sonlu bir değere yaklaşıyor, bu yüzden dikey asimptot olmaz.

### 9.2 Yatay Asimptot: $x\to\infty$

- Pay ve paydada $x$ ortak çarpanı alınır. Kökün içinden $x^2$ çıkar; $x>0$ olduğundan $\sqrt{x^2}=x$:

$$\lim_{x\to\infty}\frac{x\left(\sqrt{1+\frac2x+\frac6{x^2}}-\frac3x\right)}{x\left(1-\frac1x\right)}=\frac{\sqrt{1+0+0}-0}{1-0}=1$$

- $x$'ler sadeleşir, kalan $\frac2x$, $\frac6{x^2}$, $\frac3x$, $\frac1x$ terimleri sıfıra gider.
- $+\infty$'da yatay asimptot $y=1$'dir. Grafik ya alttan ya üstten bu doğruya yaklaşır; $f(x)$ değerleri $1$'e gider.

> **Ders sonrası not:** Hoca yalnız $x\to+\infty$'u hesapladı. $x\to-\infty$ iken $\sqrt{x^2}=|x|=-x$ olduğundan limit $-1$ çıkar; $-\infty$'da yatay asimptot $y=-1$'dir (sympy ile doğrulandı).

### 9.3 Test Sınavı Tipi Sorular

Hoca test sınavlarında asimptotlarla ilgili sorularla karşılaşılabileceğini söyledi. Tipik soru: "Verilen fonksiyon için aşağıdakilerden hangisi söylenebilir?"

- A şıkkı: "Bu fonksiyonun $+\infty$ ya da $-\infty$'da yatay asimptotu vardır." Bunun doğru olup olmadığını kontrol etmek gerekir.
- Başka bir şık: "Fonksiyonun düşey asimptotu $x=1$ doğrusudur." Örnek 13 için bu yanlıştır, çünkü fonksiyonun düşey asimptotu yok.

Dersin bu noktasında 10 dakikalık ara verildi.

## 10. Limitin Kesin Tanımı ($\varepsilon$-$\delta$)

Aradan sonra hoca limitin kesin tanımına (precise definition of limit) geçti. Bunun test sınavında çıkma ihtimalinin çok düşük olduğunu, ama müfredatta olduğu için mantığını basitçe anlatıp geçeceğini söyledi.

### 10.1 Eşitsizliklerin Anlamı

- $|x-a|<\delta$ eşitsizliği çözülünce $a-\delta<x<a+\delta$ elde edilir. Bu, merkezi $a$ olan bir açık aralıktır. $x$, $a$'nın sağında ya da solunda bir yerdedir.
- $|f(x)-L|<\varepsilon$ ise bağımlı değişken $f(x)$'in $L-\varepsilon$ ile $L+\varepsilon$ arasında olduğunu söyler.

Kesin tanımın içerdiği ifade şudur: Bağımsız değişken $x$, $a-\delta$ ile $a+\delta$ arasında kaldığında, $f(x)$ de $L-\varepsilon$ ile $L+\varepsilon$ arasında kalır.

<!-- BELİRSİZ: 01:16:13-01:16:43 arasında altyazı döngüye giriyor; tahtadaki tanım metni okunmuyor. -->

**Tanım (limitin kesin tanımı):**

- Her $\varepsilon>0$ için öyle bir $\delta>0$ vardır ki,
- $0<|x-a|<\delta$ olduğunda $|f(x)-L|<\varepsilon$ olur.
- Bu durumda $\lim_{x\to a}f(x)=L$ yazılır.

Hoca şu cümlenin çok önemli olduğunu vurguladı: $\varepsilon$ keyfi (arbitrary) ama pozitif bir sayıdır. $\varepsilon$ istenildiği kadar küçük seçilebilir, örneğin $0{,}00000001$. Amaç, verilen her küçük $\varepsilon$ için $f(x)$'in $L$'ye yeterince yakın olmasını sağlayan, yani $x$ $a$'ya yeterince yakınken bunu garanti eden bir $\delta$ bulmaktır. Limitin fikri budur: $x\to a$, $x$'in $a$'ya yeterince yakın olması; bu durumda $f(x)$ de $L$'ye yeterince yakın olur.

> **Ders sonrası not:** Hoca iki yerde "$f(x)$, $a$'ya yeterince yakın olur" dedi; doğrusu "$f(x)$, $L$'ye yeterince yakın olur"dur.

### 10.2 Örnek: $\lim_{x\to4}(4x-15)=1$

**Örnek 14.** $\lim_{x\to4}(4x-15)=1$ olduğunu kesin tanımla kanıtlayın.

Burada $f(x)=4x-15$, $a=4$, $L=1$'dir. Amaç, keyfi ama pozitif bir $\varepsilon$'a bağlı bir $\delta$ bulmaktır. Hoca slayttaki anlatımı karışık bulduğunu söyleyip kendi yolundan anlattı.

- $|f(x)-L|$ ifadesiyle başlanır:

$$|f(x)-L|=|4x-15-1|=|4x-16|=4|x-4|$$

- $\varepsilon$ keyfi ama pozitif olduğundan bu ifadenin $\varepsilon$'dan küçük olmasını isteriz:

$$4|x-4|<\varepsilon\iff|x-4|<\frac{\varepsilon}{4}$$

- Böylece $\delta=\frac{\varepsilon}{4}$ seçilebilir. $0<|x-4|<\delta$ olduğunda $|f(x)-1|<\varepsilon$ olur.
- Örneğin $\varepsilon=0{,}00001$ verilirse $\delta=0{,}0000025$ alınır (ara adım eklendi).

<!-- BELİRSİZ: 01:20:36 civarında altyazı döngüye giriyor ("x-4'e epsilonu 4'e..."); $\delta=\varepsilon/4$ sonucu hocanın sonraki Türkçe açıklamasından alındı. -->

Hoca bunu bir şekille açıkladı. $x$ ekseninde $(a-\delta,a+\delta)$ açık aralığı, $y$ ekseninde $L-\varepsilon$ ve $L+\varepsilon$ işaretlenir. $x$'ler bu aralıkta, yani $a$'ya yeterince yakınken, $f(x)$'ler de $(L-\varepsilon,L+\varepsilon)$ bandında, yani $L$'ye yeterince yakın kalır. Bu tam olarak limittir.

Hocanın Türkçe özeti şöyledir: Keyfi bir $\varepsilon$ verildiğinde, $\varepsilon$'a bağlı olarak bu mantıksal ifadeyi doğru yapan bir $\delta$ bulunabiliyorsa limit matematiksel olarak ispatlanmış olur. Burada amaç $\delta$ bulmaktır. Bu örnekte eşitsizlik çözülünce $\delta=\frac{\varepsilon}{4}$ geldi. Yani $x\to4$ iken $4x-15$ gerçekten $1$'e yaklaşır.

> **Hocanın vurgusu:** Böyle bir ispat test sınavına gelmez. Yalnız mantığını bilmek yeterli; müfredatta olduğu için anlatılıyor.

## 11. Bir Noktada Süreklilik

Hoca, gelecek hafta soru çözebilecek kadar konu öğrenmek için sürekliliği de bu derste bitirmek istediğini söyledi.

### 11.1 Grafikte Delik ve Tanım

Parçalı tanımlı bir fonksiyon MATLAB gibi bir çizim aracıyla çizilirse grafikte bir kopma, bir delik (hole) görülür. Bu, grafiğin orada sürekli olmadığı anlamına gelir. Bunu matematiksel olarak göstermek için süreklilik tanımı kullanılır.

**Tanım (bir noktada süreklilik):** $f$, $a$ noktasında süreklidir ancak ve ancak

- $f$'nin $a$'da limiti vardır: $\lim_{x\to a}f(x)=L$,
- ve bu limit fonksiyonun $a$'daki değerine eşittir: $L=f(a)$.

Bu tanım, kısa notta olduğu gibi üç koşul olarak da yazılabilir: $f(a)$ tanımlı, $\lim_{x\to a}f(x)$ var ve $\lim_{x\to a}f(x)=f(a)$.

### 11.2 Grafikten Süreklilik

**Örnek 15.** Bir grafik üzerinde üç nokta incelendi.

- $x=2$: $x$ soldan ve sağdan 2'ye yaklaşırken $f(x)\to1$. Limit var. Ama $f(2)=3$, limite eşit değil. Fonksiyon $x=2$'de sürekli değildir.
- $x=3$: Limit yok. Fonksiyon $x=3$'te süreksizdir.
- $x=6$: Grafikte kopma ya da delik yok. $f$, $x=6$'da süreklidir.

Hoca farklı süreksizlik türleri olduğunu söyledi.

<!-- BELİRSİZ: 01:27:21-01:27:51 arasında tahtadaki anlatım altyazıda okunmuyor; grafiğin kendisi altyazıda yok. -->

### 11.3 Tanımsız Nokta ve Tanımlı Nokta

**Örnek 16.** Bir $g$ fonksiyonunun $x=1$ ve $x=2$'deki sürekliliği incelendi.

- $x=1$: Fonksiyonun tanımlı olması ön koşuldur. $g$, $x=1$'de tanımlı olmadığından orada sürekli değildir.
- $x=2$: $g$ burada tanımlı, limiti var ve $x=2$'deki değeri limite eşit. Bu yüzden $g$, $x=2$'de süreklidir.

<!-- BELİRSİZ: Örnek 16'daki fonksiyonun kuralı altyazıda geçmiyor. -->

### 11.4 Örnek: $x\sin\frac1x$

**Örnek 17.**

$$h(x)=\begin{cases}x\sin\dfrac1x, & x\ne0\\[4pt] 0, & x=0\end{cases}$$

$h$'nin $x=0$'da sürekli olduğunu gösterin.

- $x\to0$ iken $x$ soldan ya da sağdan sıfıra yaklaşır ama $0$'dan farklıdır. Bu yüzden $x\sin\frac1x$ parçası kullanılır.
- Gösterilmesi gereken: $\lim_{x\to0}x\sin\frac1x=h(0)=0$.
- Burada L'Hôpital uygulanamaz, çünkü $\frac00$ ya da $\frac\infty\infty$ biçiminde bir belirsizlik yok.
- Değişken değiştirme yapılır: $t=\frac1x$.
  - $x\to0^+$ iken $t\to+\infty$.
  - $x\to0^-$ iken $t\to-\infty$.
- $x=\frac1t$ olduğundan $x\sin\frac1x=\frac{\sin t}{t}$ olur (ara adım eklendi). Limit problemi şuna dönüşür:

$$\lim_{x\to0}x\sin\frac1x=\lim_{t\to\pm\infty}\frac{\sin t}{t}$$

- $t\to\infty$ iken $\sin t$, $-1$ ile $+1$ arasında salınır; $t$ ise sınırsızdır. Sıkıştırma teoremiyle limit $0$'dır.
- Bu, fonksiyonun $0$'daki değerine eşittir. Bu yüzden $h$, $x=0$'da süreklidir.

Hoca şunu ekledi: $h(0)$ değeri $0$ yerine $1$ olarak tanımlansaydı, $h$ sürekli olmazdı.

## 12. Süreklilik Kuralları ve Bileşke

### 12.1 Cebirsel Kurallar

**Teorem (süreklilik kuralları):** $f$ ve $g$, $a$ noktasında sürekli olsun. O zaman $a$'da şunlar da süreklidir:

- Toplam: $f+g$
- Fark: $f-g$
- Sabitle çarpım: $cf$
- Çarpım: $fg$
- Bölüm: $f/g$, $g(a)\ne0$ koşuluyla
- Kuvvet: $f(x)^n$

Polinom fonksiyonlarının her yerde sürekli olduğunu biliyoruz. Rasyonel fonksiyonlar iki polinomun bölümü olarak elde edildiğinden, paydası $q(x)$'i sıfır yapan noktalar dışında her yerde süreklidir.

> **Ders sonrası not:** Hoca önce "paydanın sıfır olmadığı noktalar hariç" gibi söyleyip hemen "payda sıfır, pardon" diye düzeltti. Doğrusu: paydayı sıfır yapan noktalar hariç.

### 12.2 Bileşkenin Sürekliliği

<!-- BELİRSİZ: 01:33:40-01:34:08 arasında teoremin ifadesi altyazıda okunmuyor; aşağıdaki ifade kısa nottan ve hocanın sonraki açıklamasından kuruldu. -->

**Teorem (bileşke):**

- $g$, $a$'da sürekli ve $f$, $g(a)$'da sürekli ise $f\circ g$, $a$'da süreklidir.
- Bu koşullar sağlanmazsa $f\circ g$'nin $a$'daki sürekliliğinden söz edilemez.
- Teoremin verdiği işlem:

$$\lim_{x\to a}f(g(x))=f\left(\lim_{x\to a}g(x)\right)$$

Hoca bunu Türkçe olarak açıkladı: Süreklilik sayesinde, limit probleminden elde edilen ifadeyi $f$'nin argümanı olarak yazabiliyorsunuz. Aksi durumda bunu yapamazsınız.

> **Hocanın vurgusu:** Limiti sürekli bir fonksiyonun içine alabilmek süreklilik sayesindedir. Burası çok önemli.

Hocanın verdiği basit örnekte bir kök ifadesinin limiti, kökün içindeki ifadenin limiti hesaplanarak bulundu. Bu, karekök fonksiyonunun sürekliliği sayesinde yapılabilir.

<!-- BELİRSİZ: Kök örneğindeki ifade altyazıda geçmiyor. -->

## 13. Bir Aralıkta Süreklilik

Bir aralıkta süreklilik, grafiğin o aralıkta çizilebilmesi, yani grafikte hiç delik olmaması demektir.

Hoca bir grafik üzerinden anlattı. Fonksiyonun grafiği yarı açık yarı kapalı $[a,b)$ aralığında süreklidir. Ama $b$ noktası da dahil edilirse, yani aralık $[a,b]$ alınırsa, sürekli olmaz. Bunu açıklamak için soldan ve sağdan süreklilik kavramlarından söz etmek gerekir.

**Tanım (tek taraflı süreklilik):**

- $\lim_{x\to a^-}f(x)=f(a)$ ise $f$, $a$'da soldan süreklidir (continuous from the left).
- $\lim_{x\to a^+}f(x)=f(a)$ ise $f$, $a$'da sağdan süreklidir (continuous from the right).

**Örnek 18 (grafikten).**

- Birinci grafik: $[a,b)$'de sürekli. $b$ dahil edilirse $b$'de soldan süreklilik olmadığından $[a,b]$'de sürekli değil.
- İkinci grafik: $a$'da sağdan limit var, bir $L$ değeri bulunuyor, ama $f(a)$ tanımlı değil. Fonksiyon $(a,b]$'de sürekli, ama $[a,b]$'de sürekli değil. Çünkü $a$'da sağdan süreklilik tanımı sağlanmıyor.

**Soru:** $a$ noktasında limit de yok, değil mi? **Cevap:** Var. $a$'da sağdan limit var. Sorun limitte değil, $f(a)$'nın tanımsız olmasında.

Hoca buradan şu kuralı çıkardı: Bir aralıkta sürekliliği incelerken uç noktalarda tek taraflı limite ve tek taraflı sürekliliğe bakılır.

**Tanım ($[a,b]$'de süreklilik, kısa nottaki biçimiyle):**

- $f$, $(a,b)$'nin her iç noktasında süreklidir,
- $a$'da sağdan süreklidir,
- $b$'de soldan süreklidir.

## 14. Doğru/Yanlış Alıştırmaları

Hoca konuyu oturtmak için boş bir beyaz tahta paylaşıp grafikler üzerinden doğru/yanlış ifadeler sordu.

**Örnek 19.** Aşağıdaki ifadelerin doğru mu yanlış mı olduğunu belirleyin.

- Deliksiz bir grafik için "$f$, $[a,b]$ kapalı aralığında süreklidir." **Doğru.** Grafikte delik yok. $a$'da sağdan limit ve sağdan süreklilik var. $b$'de soldan limit ve soldan süreklilik var. Fonksiyon her iç noktada da sürekli.
- Aynı grafik için uç noktaları dahil edilmeyen aralıkta süreklilik ifadesi de doğru kabul edildi.
- $a$'da delik olan bir grafik için "$f$, $[a,b]$'de süreklidir." **Yanlış.** Çalışılan tanım kümesinde grafikte delik var. $a$'da sağdan limit var ama $f(a)$ tanımlı değil, bu yüzden $a$'da sağdan süreklilik yok.
- Hoca "zihniniz otursun" diye bir grafik daha gösterdi ve açık aralıkta çalışıldığını varsaydı. "$f$, $[a,b]$'de süreklidir." **Yanlış.** "$f$, $(a,b)$ açık aralığında süreklidir." **Doğru.**
- "Polinom fonksiyonları her yerde, yani $\mathbb{R}=(-\infty,\infty)$ üzerinde süreklidir." **Doğru.**
- "$f(x)=\dfrac{1}{x^2-1}$, $\mathbb{R}\setminus\{-1,1\}$ üzerinde süreklidir." **Doğru.** Bu küme $(-\infty,-1)\cup(-1,1)\cup(1,\infty)$'dur. Rasyonel fonksiyonda paydayı sıfır yapan noktalar çıkarılır.
- "$\sin x$ her yerde süreklidir." **Doğru.** Aynı şekilde $\cos x$ de her yerde süreklidir.
- "$\tan x$ her yerde süreklidir." **Yanlış.** $\tan x=\dfrac{\sin x}{\cos x}$ olduğundan $\cos x=0$ yapan noktalarda süreksizdir. $\tan x$, bu noktalar dışında her yerde süreklidir.

<!-- BELİRSİZ: 01:42:03 civarındaki ikinci ifadenin aralığı (açık mı, yarı açık mı) altyazıda tam okunmuyor. -->

$\frac1{x^2-1}$ ifadesinde bir öğrenci önce bunun doğru olmadığını söyledi. Hoca, yazılanın bir aralık değil bir küme olduğunu açıkladı: Tanım kümesinden yalnız $-1$ ve $+1$'den oluşan küme çıkarılıyor. Aradaki $(-1,1)$ aralığında $0$ da vardır ve fonksiyon orada süreklidir.

> **Ders sonrası not:** Hoca kümeyi sözlü yazarken aralıkların uçlarını karıştırdı ("eksi 1'den eksi sonsuza", "eksi 1'den artı sonsuza"). Doğrusu $(-\infty,-1)\cup(-1,1)\cup(1,\infty)$'dur.

$\cos x$ periyodik bir fonksiyon olduğundan onu sıfır yapan sonsuz tane $x$ değeri vardır. Bu yüzden $\tan x$'in sonsuz tane süreksizlik noktası vardır; bunlardan biri $\frac\pi2$'dir.

> **Ek bilgi (derste anlatılmadı):** $\cos x=0$ denkleminin çözümleri $x=\frac\pi2+k\pi$ ($k$ tam sayı) biçimindedir. $\tan x$'in süreksiz olduğu noktalar bunlardır ve grafiği bu noktalarda düşey asimptotlara sahiptir.

### 14.1 Dersin Kapanışı

Ders saati dolduğunda hoca yatay ve düşey asimptotun işlendiğini, ama eğik asimptotun (oblique asymptote) anlatılmadığını söyledi. Eğik asimptot müfredatta yok ama önemli bir konu olduğu için ileride anlatacağını belirtti.

**Soru:** Ödev sorularının cevaplarını notların sonunda bulabilir miyiz? **Cevap:** Onlar çok basit pratik sorular olduğu için cevap yazma ihtiyacı duyulmadı. Sınava yönelik sorular derste çözülecek ve onların cevapları verilecek.

Hoca son olarak, temel tanımları ve tanımların arkasındaki felsefeyi anlamaya çalışmayı öğütledi.

## Örnek Sorular

Bu bölüm yalnız derste öğrencilere sorulan ya da ödev bırakılan sorulardan kuruldu. Derste çözülenlerin çözümü ilgili bölümdedir.

**Soru 1** (derste sözlü, 00:18:52). Verilen sonsuz limitler $+\infty$ mu, $-\infty$ mu? Grafik çizmeden, çarpanların işaretiyle belirleyin.

<!-- BELİRSİZ: Sorudaki fonksiyonlar altyazıda okunmuyor. Bir öğrencinin cevabı "ilki eksi sonsuz, ikincisi artı sonsuz" oldu ve hoca onayladı. -->

**Soru 2** (derste sözlü, 00:13:44). Ödev: $\displaystyle\lim_{x\to2}\frac{x^5-32}{x-2}$ limitini L'Hôpital kullanmadan, $x^n-a^n$ çarpanlara ayırma formülüyle hesaplayın.

> **Çözüm (derste verilmedi):** $x^5-2^5=(x-2)(x^4+2x^3+4x^2+8x+16)$. Sadeleştirince $\lim_{x\to2}(x^4+2x^3+4x^2+8x+16)=16+16+16+16+16=80$ (sympy ile doğrulandı).

**Soru 3** (derste sözlü, 00:43:23). $\displaystyle\lim_{\theta\to\infty}\frac{\cos\theta}{\theta^2}$ limitini bulun; yatay asimptotu belirleyin. Çözüm Bölüm 8.2'de (Örnek 11): sonuç $0$, yatay asimptot $y=0$.

**Soru 4** (derste sözlü, 00:47:03). $f(x)=\dfrac{4x^3+1}{2x^3+\sqrt{16x^6+1}}$ fonksiyonunun yatay asimptotlarını inceleyin. $+\infty$ tarafı Bölüm 8.3'te çözüldü (Örnek 12): $y=\frac23$. $-\infty$ tarafı ödev bırakıldı.

<!-- BELİRSİZ: Fonksiyonun sabitleri altyazıdan tam okunmuyor; çözüm adımlarından kuruldu. -->

> **Çözüm (derste verilmedi):** $x\to-\infty$ iken $x^3<0$, dolayısıyla $\sqrt{16x^6+1}=|x^3|\sqrt{16+\frac1{x^6}}=-x^3\sqrt{16+\frac1{x^6}}$. Limit $\dfrac{4+0}{2-4}=-2$. $-\infty$'da yatay asimptot $y=-2$ (sympy ile doğrulandı).

**Soru 5** (derste sözlü, 00:50:56). $f(x)=\dfrac{\sqrt{x^2+2x+6}-3}{x-1}$ fonksiyonunun yatay ve düşey asimptotlarını inceleyin. Bölüm 9'da çözüldü (Örnek 13): $x\to1$ limiti $\frac23$ olduğundan düşey asimptot yok; $+\infty$'da yatay asimptot $y=1$. $-\infty$ tarafı derste hesaplanmadı.

> **Çözüm (derste verilmedi):** $x\to-\infty$ iken $\sqrt{x^2}=-x$ olduğundan $f(x)=\dfrac{-x\sqrt{1+\frac2x+\frac6{x^2}}-3}{x-1}\to\dfrac{-1}{1}=-1$. $-\infty$'da yatay asimptot $y=-1$ (sympy ile doğrulandı).

**Soru 6** (derste sözlü, 01:42:03-01:49:05). Doğru/yanlış: Grafikteki $f$'nin $[a,b]$'de, $(a,b)$'de sürekliliği; polinomların $\mathbb{R}$'de sürekliliği; $\frac1{x^2-1}$'in $\mathbb{R}\setminus\{-1,1\}$'de sürekliliği; $\sin x$, $\cos x$, $\tan x$'in her yerde sürekliliği. Cevaplar Bölüm 14'te (Örnek 19).

## Dersin Toparlaması

Ders, önceki derste görülen limit kurallarının alıştırmalarıyla başladı: sınırlı bir fonksiyonla sıfıra giden bir fonksiyonun çarpımında sıkıştırma teoremi, parçalı fonksiyonda tek taraflı limitleri eşitleyerek sabit bulma ve eşlenik yöntemi. Hoca her fırsatta L'Hôpital kuralının henüz kullanılmaması gerektiğini, bazı sorularda zaten işe yaramadığını vurguladı. Ardından sonsuz limitler ve düşey asimptot, sonsuzda limit ve yatay asimptot işlendi. Düşey asimptotta sonlu bir noktaya yaklaşırken sonucun $\pm\infty$ olması, yatay asimptotta $\pm\infty$'a giderken sonucun sonlu olması gerektiği ayrımı ve $x\to-\infty$ iken kökten çıkan ifadenin işaretine dikkat edilmesi dersin ana mesajlarıydı. Salınan sınırlı fonksiyonlarda ($\sin$, $\cos$) sıkıştırma teoremi temel araç oldu.

İkinci yarıda limitin $\varepsilon$-$\delta$ tanımı mantığıyla anlatıldı ve $\lim_{x\to4}(4x-15)=1$ için $\delta=\frac\varepsilon4$ bulundu. Sonra bir noktada süreklilik, süreklilik kuralları, bileşkenin sürekliliği (limiti sürekli fonksiyonun içine alma) ve bir aralıkta süreklilik için tek taraflı süreklilik işlendi. Hoca gelecek hafta soru çözüleceğini, ardından logaritmik ve üstel fonksiyonlara geçileceğini söyledi. Eğik asimptotun da müfredatta olmasa bile ileride anlatılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
