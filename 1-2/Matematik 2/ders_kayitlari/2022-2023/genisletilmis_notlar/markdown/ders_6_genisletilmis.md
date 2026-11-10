# Ders 6 Genişletilmiş Notu: Seriler Üzerine Çıkmış Sınav Soruları ve Kutupsal Koordinatlara Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Dizi Limiti Sorusu
- 3. Teleskopik Seri ve Kuvvet Serileri
- 4. Genel Terim ve Oran Testiyle Karakter Soruları
- 5. Örüntüden Genel Terim ve Seri Toplamı
- 6. Mutlak ve Şartlı Yakınsaklık Sorusu
- 7. İki Geometrik Serinin Toplamı
- 8. Maclaurin Serisiyle İntegral ve Limit Soruları
- 9. Kutupsal Koordinatlardan Kartezyen Koordinatlara Geçiş
- 10. Örnek Sorular

## 1. Dersin Planı

Ders Zoom üzerinden online yapıldı. Hoca, bu haftanın seriler konusunun son haftası olduğunu söyledi. Bu derste yeni konu anlatılmadı. Geçmiş yılların ara sınav, final ve bütünleme sınavlarından seri soruları çözüldü. Hocanın ifadesiyle amaç, "eksik ve gedik varsa" kapatmaktı.

Hoca sonraki konuların sırasını da verdi: parametrik denklemler, ardından çok değişkenli fonksiyonlar, tanım kümeleri, limit, süreklilik, türev ve çok katlı integral.

> **Hocanın vurgusu:** Birinci ara sınav sorularının yarıdan fazlası serilerden gelecek. Ne kadar çok soru görülür ve çözülürse yapma olasılığı o kadar artar.

Sorular test (çoktan seçmeli) biçimine göre ele alındı. Hoca birkaç kez şunu hatırlattı: Test sorusunda çözümün her aşaması ayrı bir şık olabilir. Bu yüzden yalnız sonuca değil, sürecin her adımına hâkim olmak gerekir.

## 2. Dizi Limiti Sorusu

İlk soru 2019 yılına ait bir sınavdan alındı. Bir dizinin limiti soruluyordu. Hoca önce dizi limitinin $n\to\infty$ için alındığını hatırlattı. Sonra öğrencilere üç temel limiti sordu.

**Soru:** $\lim_{x\to0}\dfrac{\sin x}{x}$ neye eşittir? **Cevap:** $1$.

**Soru:** $\lim_{x\to\infty}\dfrac{\sin x}{x}$ neye eşittir? **Cevap:** $0$. Hoca bu cevabı onayladı.

**Soru:** $\lim_{x\to\infty}\dfrac{\sin(1/x)}{1/x}$ neye eşittir? **Cevap:** $1$. Çünkü $x\to\infty$ iken $\dfrac1x\to0$ olur ve ilk limite dönülür.

Bu son limit sorunun anahtarıdır. Sinüsün içindeki ifade neyse, sinüsün altında da aynı ifade bulunmalıdır. O zaman limit $1$ olur.

**Örnek 1.** $\left\{\dfrac{n^{5/2}}{2n^2+1}\sin\dfrac{1}{\sqrt n}\right\}_{n\ge1}$ dizisinin limitini bulunuz.

<!-- BELİRSİZ: Dizinin tam ifadesi altyazıda okunmuyor. İfade kısa nottan (kareden okunmuş) alındı. Altyazı yalnız "sinüs 1 bölü kök n bölü 1 bölü kök n", "bir tane kök n, bir tane n kare" ve "derecesi 2, 2" parçalarını veriyor; bunlar bu ifadeyle uyumlu. -->

1. $n\to\infty$ için $\sin\dfrac1{\sqrt n}\to0$, kesir ise sonsuza gidiyor. Doğrudan koyunca belirsizlik çıkar.
2. Manipülasyon: $n^{5/2}=n^2\cdot\sqrt n$ diye parçalanır. $\sqrt n$, $\dfrac{1}{1/\sqrt n}$ olarak sinüsün altına taşınır.
3. Dizi şu hale gelir:
$$\frac{n^2}{2n^2+1}\cdot\frac{\sin(1/\sqrt n)}{1/\sqrt n}.$$
4. Birinci çarpanda pay ve paydanın derecesi $2$'dir. Limit, baş katsayıların oranıdır: $\dfrac12$.
5. İkinci çarpan, yukarıdaki üçüncü temel limit gereği $1$'e gider.
6. Limit $\dfrac12\cdot1=\dfrac12$.

Hoca, şıklarda $\dfrac12$'nin aranacağını söyledi.

## 3. Teleskopik Seri ve Kuvvet Serileri

### 3.1 Teleskopik seri

**Örnek 2.** Teleskopik bir serinin toplamını bulunuz.

İkinci soru bir seri toplamıydı. Terimleri doğrudan koyarak toplam alınamıyordu. Hoca önce seri tipinin belirlenmesi gerektiğini söyledi: bu bir teleskopik seridir (telescoping series). Genel terim iki terimin farkı şeklinde yazılır.

<!-- BELİRSİZ: Teleskopik serinin ifadesi altyazıda hiç okunmuyor; yalnız çözüm adımları ve sonuç geçiyor. -->

Fark şeklinde yazılınca kısmi toplamda (partial sum) ara terimler birbirini götürür. Geriye ilk ve son terim kalır. Hoca $S_n$'nin $n\to\infty$ limitini aldı. Son terim "sayı bölü sonsuz" biçiminde olduğundan sıfıra gidiyordu. Böylece kısmi toplamlar dizisi $1$'e gitti ve serinin toplamı $1$ bulundu.

> **Hocanın vurgusu:** Bu tip sorular daha önce de çözüldü. Çıkma ihtimali yüksektir.

### 3.2 Yalnız bir noktada yakınsayan kuvvet serisi

**Örnek 3.** $\displaystyle\sum_{n=0}^{\infty}n!\,(x-1)^n$ serisini yakınsak yapan $x$ değerlerini bulunuz.

Hoca, sınav çözümündeki yazımı beğenmediğini söyledi ve soruyu tahtada yeniden çözdü. Kuvvet serilerinde oran testi (ratio test) kullanılır. Genel terime $u_n=n!\,(x-1)^n$ denir.

1. Oran:
$$\left|\frac{u_{n+1}}{u_n}\right|=\frac{(n+1)!\,|x-1|^{n+1}}{n!\,|x-1|^n}=(n+1)\,|x-1|.$$
2. Yakınsaklık için bu oranın limiti $1$'den küçük olmalıdır.
3. $x\neq1$ ise $\lim_{n\to\infty}(n+1)|x-1|=\infty$ olur. Seri ıraksaktır.
4. Yalnız $x=1$'de bütün terimler (ilki hariç) sıfırdır ve seri yakınsaktır.

Sonuç: Seri yalnız $x=1$ noktasında yakınsaktır, başka her yerde ıraksaktır.

> **Ders sonrası not:** Hoca 00:11:31'de "orijinde yani" diyor. Seri $x=1$ merkezlidir; yakınsadığı tek nokta orijin değil, serinin merkezi olan $x=1$'dir.

Hoca aynı soruyu başka bir soruya dönüştürdü. $n!$ pay kısmında değil de paydada olsaydı, yani seri $\sum\dfrac{(x-1)^n}{n!}$ olsaydı, oran $\dfrac{|x-1|}{n+1}$ olurdu. Bu oran her $x$ için sıfıra gider. O zaman seri bütün reel sayılar için, yani $(-\infty,\infty)$'da yakınsak olurdu.

> **Hocanın vurgusu:** Bu iki tipe dikkat edin. Faktöriyel pay kısmındaysa seri yalnız merkezde, paydadaysa bütün reel sayılarda yakınsar.

### 3.3 Geometrik kuvvet serisi

**Örnek 4.** $\displaystyle\sum_{n=0}^{\infty}\frac{(x+3)^n}{4^{n+1}}$ kuvvet serisinin yakınsaklık aralığını ve temsil ettiği fonksiyonu bulunuz.

Hoca bunun bir kuvvet serisi olduğunu, ama aynı zamanda geometrik seri olduğunu belirtti. Çünkü $x$'in kuvvetleri ortak bir çarpanla ilerliyor.

1. Paydadaki $4^{n+1}=4\cdot4^n$ olduğundan $\dfrac14$ dışarı alınır:
$$\frac14\sum_{n=0}^{\infty}\left(\frac{x+3}{4}\right)^n.$$
2. Seri açık yazılınca $1+\dfrac{x+3}{4}+\dfrac{(x+3)^2}{4^2}+\cdots$ olur. İlk terim $1$, ortak çarpan $r=\dfrac{x+3}{4}$'tür.
3. Geometrik serinin toplamı "ilk terim bölü bir eksi ortak çarpan" ile bulunur:
$$\frac14\cdot\frac{1}{1-\frac{x+3}{4}}=\frac14\cdot\frac{4}{1-x}=\frac{1}{1-x}.$$
Son eşitlik için ara adım eklendi.
4. Bu toplam yalnız $|r|<1$ iken geçerlidir:
$$\left|\frac{x+3}{4}\right|<1\iff -4<x+3<4\iff -7<x<1.$$

Yani seri $(-7,1)$ aralığında yakınsaktır ve bu aralıkta $\dfrac{1}{1-x}$ fonksiyonunu temsil eder.

> **Ders sonrası not:** Altyazıda hoca 00:14:47'de "bu birden büyük ise" diyor; toplam formülü için doğrusu $|r|<1$ olmasıdır. 00:15:38'de aralık "x yeri ile artı 1" diye bozuk geçiyor; doğrusu $-7<x<1$. 00:16:12'de koşul "x artı 7 bölü 4" diye geçiyor; doğrusu $\left|\dfrac{x+3}{4}\right|<1$'dir.

Hoca bu sorunun test sınavında nasıl sorulabileceğini anlattı. "Aşağıdakilerden hangisi doğrudur" diye sorulabilir. Şıklarda serinin temsil ettiği fonksiyon $\dfrac{1}{1-x}$, yakınsaklık aralığı $(-7,1)$ ya da yakınsaklık koşulu $\left|\dfrac{x+3}{4}\right|<1$ verilebilir. Yani sorunun her aşaması bir şık olabilir. Öğrencinin konuyu ne kadar kavradığı böyle ölçülür.

> **Ek bilgi (derste anlatılmadı):** Uç noktalarda $|r|=1$ olur. $x=1$'de seri $\frac14\sum1$, $x=-7$'de $\frac14\sum(-1)^n$ biçimine gelir. İkisinde de genel terim sıfıra gitmez, seri ıraksaktır. Bu yüzden geometrik serinin yakınsaklık aralığı her zaman açık aralıktır.

## 4. Genel Terim ve Oran Testiyle Karakter Soruları

### 4.1 Genel terim testiyle ıraksaklık

**Örnek 5.** $\displaystyle\sum_{n=2}^{\infty}n\ln\left(1-\frac1n\right)$ serisinin karakterini (yakınsaklığını ya da ıraksaklığını) tespit ediniz.

Hoca önce genel terimin limitine bakılması gerektiğini söyledi. Bu, genel terim testidir (n-th term test).

**Genel terim testi**

- $\lim_{n\to\infty}a_n\neq0$ ise $\sum a_n$ ıraksaktır.
- $\lim_{n\to\infty}a_n=0$ ise test sonuç vermez. Başka teste bakmak gerekir.

Hoca ayrıca $n\ge2$ için $1-\dfrac1n>0$ olduğunu, yani logaritmanın tanımlı olduğunu hatırlattı.

1. Logaritmanın özelliğiyle $n$ üsse taşınır:
$$a_n=n\ln\left(1-\frac1n\right)=\ln\left(1-\frac1n\right)^n.$$
2. $\ln$ sürekli olduğundan limit ile $\ln$ yer değiştirir:
$$\lim_{n\to\infty}a_n=\ln\left(\lim_{n\to\infty}\left(1-\frac1n\right)^n\right).$$
3. İçteki limit $e^{-1}$'dir. Öğrenciler bu değeri doğru söyledi.
4. $\lim a_n=\ln e^{-1}=-1\neq0$.
5. Genel terim testiyle seri ıraksaktır.

Bir öğrenci soruyu tekrar sordu. Hoca soruyu baştan çözdü ve aynı sonuca ulaştı.

> **Ders sonrası not:** Hoca 00:18:10'da ilk çözümde bir an "yakınsaktır" diyor. Doğrusu ıraksaktır; hoca ikinci çözümde (00:21:19) bunu doğru söylüyor. Ayrıca ikinci çözümde $e^{-1}$ değerini sonuç gibi okuyor. Genel terimin limiti $\ln e^{-1}=-1$'dir. İki değer de sıfırdan farklı olduğu için sonuç değişmez.

### 4.2 İndirgeme bağıntısıyla verilen seri

Dördüncü soru yine bir seri sorusuydu. İlk terim $a_1$ ve $a_{n+1}$'i $a_n$ cinsinden veren bir bağıntı verilmişti. $\sum a_n$ serisinin karakteri soruluyordu.

<!-- BELİRSİZ: Bağıntı altyazıda "A1 1 1 2 ... 1 1 2 çarpı 1 1 1 2 n çarpı A1" diye geçiyor ve okunmuyor. -->

Hoca, soru karışık görünse de çözümün basit bir oran testi olduğunu söyledi. Bağıntıdan $\dfrac{a_{n+1}}{a_n}$ doğrudan yazılır ve limiti alınır. Hoca serinin yakınsak çıktığını söyledi.

> **Hocanın vurgusu:** Soru karışık görünse de yöntem bellidir. Önemli olan doğru sonuca ulaşmaktır.

## 5. Örüntüden Genel Terim ve Seri Toplamı

### 5.1 Final sorusu: örüntüden seri toplamı

Moladan sonra hoca bir final sorusuna geçti. Hocaya göre soru "hakikaten ilginç, çok güzel bir soru"ydu.

**Örnek 6.** $\{a_n\}_{n=1}^{\infty}=\left\{\dfrac34,\dfrac58,\dfrac7{16},\dfrac9{32},\dots\right\}$ dizisi veriliyor. $\sum a_n$ serisinin toplamını hesaplayınız.

1. Önce örüntü okunur ve genel terim bulunur. Paylar $3,5,7,9,\dots$ tek sayılardır: $2n+1$. Paydalar $4,8,16,32,\dots$ ikinin kuvvetleridir: $2^{n+1}$. Böylece
$$a_n=\frac{2n+1}{2^{n+1}}.$$
2. Seri iki parçaya ayrılır (ara adım eklendi):
$$\sum_{n=1}^{\infty}\frac{2n+1}{2^{n+1}}=\sum_{n=1}^{\infty}\frac{n}{2^{n}}+\sum_{n=1}^{\infty}\frac{1}{2^{n+1}}.$$
3. İkinci parça geometrik seridir. İlk terim $\dfrac14$, ortak çarpan $\dfrac12$:
$$\sum_{n=1}^{\infty}\frac{1}{2^{n+1}}=\frac{1/4}{1-1/2}=\frac12.$$
4. Birinci parça $\sum n\left(\dfrac12\right)^n$ biçimindedir. Hoca bunun geçen hafta yapılan yöntemle bulunduğunu söyledi: $\sum x^n=\dfrac{1}{1-x}$ serisinin terim terim türevi alınıp $x$ ile çarpılır (ara adım eklendi):
$$\sum_{n=1}^{\infty}nx^{n-1}=\frac{1}{(1-x)^2}\quad\Rightarrow\quad\sum_{n=1}^{\infty}nx^{n}=\frac{x}{(1-x)^2},\qquad |x|<1.$$
$x=\dfrac12$ konursa $\dfrac{1/2}{1/4}=2$ bulunur.
5. Toplam: $2+\dfrac12=\dfrac52$.

> **Hocanın vurgusu:** Genel terimi bulmak, problemi yüzde elli çözmek demektir. Sorular zor değildir; önemli olan örüntüyü doğru okuyup doğru sonuca ulaşmaktır.

> **Ders sonrası not:** Altyazıda dördüncü terim "9 bölü 22" diye geçiyor; örüntüye göre doğrusu $\dfrac9{32}$'dir. Paydalar da bir yerde "6, 4, 8, 16, 32" diye geçiyor; doğrusu $4,8,16,32$'dir. Hoca 00:40:33'te seriyi bütünüyle "geometrik seri" diye anıyor; aslında yalnız ikinci parça geometriktir, birinci parça türevle bulunur.

### 5.2 $n$'inci kök içeren seri

Moladan sonra hoca, "hiç çözmediğimiz bir soru değil" diyerek klasik (yazılı) sınavdan bir soru gösterdi (**Örnek 7**). Seri $n=1$'den sonsuza kadardı ve $2020$ sayısının $n$'inci kökünü içeriyordu.

<!-- BELİRSİZ: Serinin ifadesi altyazıda "köken 2020-1" ve "40L üzeri 2020" diye geçiyor. Genel terimin tam biçimi okunmuyor. -->

Komisyonun çözümü uzun ara işlemlerle seriyi ıraksak buluyordu. Hoca daha kısa bir yol önerdi: Genel terimin limiti sıfırdan farklıysa, genel terim testiyle seri doğrudan ıraksaktır.

> **Ders sonrası not:** Genel terim $\sqrt[n]{2020}$ biçimindeyse $\lim\sqrt[n]{2020}=1\neq0$ olur ve hocanın yolu doğrudur. Genel terim büyük olasılıkla $\sqrt[n]{2020}-1$ biçimindeyse limit $0$'dır ve genel terim testi sonuç vermez. Bu durumda $\lim\dfrac{\sqrt[n]{2020}-1}{1/n}=\ln2020$ olduğundan, limit karşılaştırma testiyle $\sum\frac1n$ gibi ıraksaktır. Sonuç (ıraksak) her iki durumda da aynıdır.

Hoca, test sınavında bu tür uzun soruların daha az çıktığını, klasik sınavlarda daha sık görüldüğünü söyledi.

## 6. Mutlak ve Şartlı Yakınsaklık Sorusu

Hoca ekranda 2019 Bahar dönemi ara sınavını açtı. Bu sorunun, gelebilecek soru tiplerinden biri olduğunu söyledi.

> **Hocanın vurgusu:** Kuvvet serisinin hangi $x$ değerleri için mutlak yakınsak, şartlı yakınsak ve ıraksak olduğunu soran en az bir soru kesin gelecek.

Test biçiminde bu soru şöyle sorulabilir: Seri verilir ve "aşağıdakilerden hangisi doğrudur" ya da "hangisi yanlıştır" denir. Şıklar "şu aralıkta mutlak yakınsaktır", "şu noktada şartlı yakınsaktır" gibi ifadelerdir.

**Örnek 8.** $\displaystyle\sum_{n=1}^{\infty}\frac{(x-4)^n}{2^n\sqrt[5]{n^3+7}}$ serisinin hangi $x\in\mathbb{R}$ değerleri için mutlak yakınsak, şartlı yakınsak ve ıraksak olduğunu araştırınız.

<!-- BELİRSİZ: Serinin tam ifadesi altyazıda okunmuyor. İfade kısa nottan (kareden okunmuş) alındı. Altyazıdaki "6'dan 4 çıkarsa 2 kalır", "2 üzeri n birbirini götürür" ve "n üzeri 3 bölü 5" parçaları bu ifadeyle uyumlu. -->

Hoca adımları şöyle sıraladı: oran testi alınır, düzenlenir, $1$'den küçük olduğu bölgeye bakılır, sonra uç noktalar ayrı ayrı incelenir.

1. Oran testi:
$$\lim_{n\to\infty}\left|\frac{u_{n+1}}{u_n}\right|=\lim_{n\to\infty}\sqrt[5]{\frac{n^3+7}{(n+1)^3+7}}\cdot\frac{|x-4|}{2}=\frac{|x-4|}{2}.$$
Kök içindeki oran $1$'e gider (ara adım eklendi).
2. $\dfrac{|x-4|}{2}<1\iff|x-4|<2\iff2<x<6$. Bu aralıkta seri mutlak yakınsaktır.
3. Uç nokta $x=6$: $(x-4)^n=2^n$ olur ve paydadaki $2^n$ ile sadeleşir. Seri $\displaystyle\sum\frac{1}{\sqrt[5]{n^3+7}}$ olur. Büyük $n$ için bu terim $\dfrac{1}{n^{3/5}}$ gibi davranır. $p=\dfrac35<1$ olduğundan $p$-serisi ıraksaktır. Limit testiyle seri de ıraksaktır. $x=6$ dahil değildir.
4. Uç nokta $x=2$: $(x-4)^n=(-2)^n$ olur. Seri $\displaystyle\sum\frac{(-1)^n}{\sqrt[5]{n^3+7}}$ alterne serisidir. Terimlerin mutlak değeri azalarak sıfıra gider, Leibniz testiyle seri yakınsaktır (ara adım eklendi). Mutlak değer serisi ise 3. adımdaki ıraksak seridir. Bu yüzden $x=2$'de seri şartlı yakınsaktır.
5. Sonuç:
  - $2<x<6$: mutlak yakınsak.
  - $x=2$: şartlı yakınsak.
  - $x<2$ ve $x\ge6$: ıraksak.
  - Yakınsaklık aralığı $[2,6)$: $2$'de kapalı, $6$'da açık.

> **Ders sonrası not:** Hoca 00:45:42'de önce $\dfrac35$'i $1$'den büyük sanıp $x=6$'da serinin yakınsak, $6$'nın dahil olduğunu söylüyor. 00:46:12'de $\dfrac35<1$ olduğunu görüp düzeltiyor. Doğrusu: $p=\dfrac35\le1$ olduğu için $x=6$'da seri ıraksaktır ve $6$ dahil değildir.

> **Hocanın vurgusu:** Şıklarda fark çoğu zaman yalnız bir uç noktanın dahil olup olmamasıdır. Örneğin $2$'nin dahil ya da hariç olması bile sizi yanıltabilir.

Hoca anlaşılıp anlaşılmadığını sordu. Birkaç öğrenci "anlaşıldı" dedi ve derse devam edildi.

> **Ek bilgi (derste anlatılmadı):** $p$-serisi $\sum\frac{1}{n^p}$, $p>1$ ise yakınsak, $p\le1$ ise ıraksaktır. Limit testinde $\lim\frac{a_n}{b_n}=L$, $0<L<\infty$ ise iki seri aynı karakterdedir. Burada $a_n=\frac{1}{\sqrt[5]{n^3+7}}$, $b_n=\frac{1}{n^{3/5}}$ için $L=1$'dir.

## 7. İki Geometrik Serinin Toplamı

**Örnek 9.** $\displaystyle\sum_{n=1}^{\infty}\left(\frac{2}{3^n}+\frac{(-1)^n}{5^n}\right)$ toplamı neye eşittir?

<!-- BELİRSİZ: İfade altyazıda "iki bölü üç üzere en artı eksi bir üzere en bölü beş üzere en" diye geçiyor; bu biçimde kuruldu. Hoca sonucu söylemedi. -->

Hoca, serinin iki geometrik seriye ayrılabileceğini, ortak çarpanların belli olduğunu söyledi. Her birinde $|r|<1$ olmalıdır. Sonra $\dfrac{a}{1-r}$ uygulanır. Hesap derste yapılmadı; aşağıdaki adımlar eklendi.

1. Birinci seri: $2\displaystyle\sum_{n=1}^{\infty}\left(\frac13\right)^n=2\cdot\frac{1/3}{1-1/3}=2\cdot\frac12=1$.
2. İkinci seri: $\displaystyle\sum_{n=1}^{\infty}\left(-\frac15\right)^n=\frac{-1/5}{1+1/5}=-\frac16$.
3. Toplam: $1-\dfrac16=\dfrac56$.

> **Hocanın vurgusu:** Bu sorularda dikkat edilecek tek şey işlem hatası yapmamaktır. Test sınavında "işlem hatası yaptım" deme lüksü yoktur; bir soru ya doğrudur ya yanlıştır.

## 8. Maclaurin Serisiyle İntegral ve Limit Soruları

Hoca, Taylor ve Maclaurin serileriyle ilgili sınavlarda mutlaka soru geldiğini söyledi. Bir önceki derste gösterdiği bir soruyu tekrar açtı.

### 8.1 İntegralin Maclaurin serisi

**Örnek 10.** $\displaystyle\int_0^x e^{-t^2}\,dt$ ifadesinin Maclaurin serisinin genel terimi aşağıdakilerden hangisidir?

Çözüm $e^x$ açılımından başlar. Hoca öğrencilere $e^x$'in açılımını sordu.

**Soru:** $e^x$'in açılımı nedir, içinde $(-1)^n$ var mıdır? **Cevap:** Öğrenciler açılımı $1+x+\dfrac{x^2}{2}+\cdots$ diye verdi. $(-1)^n$ sorusuna "var" diye cevap verdiler. Hoca bunu düzeltti: $e^x$ açılımında $(-1)^n$ yoktur.

Hoca, açılım unutulursa Taylor formülünden yeniden çıkarılabileceğini gösterdi:
$$f(x)=f(0)+\frac{f'(0)}{1!}x+\frac{f''(0)}{2!}x^2+\cdots$$
$f(x)=e^x$ için bütün türevler $e^x$'tir ve $0$'da değerleri $1$'dir. Böylece
$$e^x=1+\frac{x}{1!}+\frac{x^2}{2!}+\cdots=\sum_{n=0}^{\infty}\frac{x^n}{n!}.$$
İşaretlerin değişmesi ancak $x$ yerine eksi işaretli bir ifade konunca ortaya çıkar.

1. $x$ yerine $-t^2$ yazılır:
$$e^{-t^2}=\sum_{n=0}^{\infty}\frac{(-t^2)^n}{n!}=\sum_{n=0}^{\infty}\frac{(-1)^nt^{2n}}{n!}.$$
2. $0$'dan $x$'e kadar terim terim, $t$'ye göre integral alınır:
$$\int_0^xe^{-t^2}\,dt=\sum_{n=0}^{\infty}\frac{(-1)^n}{n!}\int_0^xt^{2n}\,dt=\sum_{n=0}^{\infty}\frac{(-1)^nx^{2n+1}}{(2n+1)\,n!}.$$
3. İlk terimler: $x-\dfrac{x^3}{3}+\dfrac{x^5}{10}-\dfrac{x^7}{42}+\cdots$ (ara adım eklendi).

<!-- BELİRSİZ: 00:54:13'ten sonra hocanın mikrofonu kapalı kaldı; 00:54-00:58 arasındaki integral adımları kayıtta yok. Yukarıdaki 2. ve 3. adımlar hocanın "terim terim integral" yönteminden kuruldu. Altyazıdaki "Trabzon'a göre" ifadesi büyük olasılıkla "t'ye göre"dir. -->

> **Ek bilgi (derste anlatılmadı):** Kuvvet serisi yakınsaklık aralığının içinde terim terim integrallenebilir. $e^{-t^2}$ serisi her $t$ için yakınsak olduğundan bu integral serisi de her $x$ için yakınsaktır. $e^{-t^2}$'nin temel fonksiyonlarla ifade edilen bir ters türevi yoktur; bu yüzden bu integral serilerle hesaplanır.

### 8.2 Seri açılımıyla limit

**Örnek 11.** $\displaystyle\lim_{x\to0}\frac{x-\sin x}{x^3}$ limitini seri açılımıyla hesaplayınız.

<!-- BELİRSİZ: Limitin ifadesi altyazıda "limit x8'i seri 8" diye geçiyor. İfade kısa nottan alındı; altyazıdaki sonuç (1/6) ve üç kez L'Hôpital uygulanması bu ifadeyle uyumlu. -->

$x=0$ konunca $\dfrac00$ belirsizliği çıkar. Hoca, test sınavında sonuç soruluyorsa yöntemin serbest olduğunu söyledi.

- **Seri açılımıyla:** $\sin x=x-\dfrac{x^3}{3!}+\dfrac{x^5}{5!}-\cdots$ olduğundan $x-\sin x=\dfrac{x^3}{6}-\dfrac{x^5}{120}+\cdots$. $x^3$'e bölününce limit $\dfrac16$ olur (ara adım eklendi).
- **L'Hôpital kuralıyla:** Payın ve paydanın türevi ayrı ayrı alınır. Üç kez uygulandıktan sonra $\dfrac{\cos x}{6}$ elde edilir ve değer doğrudan $\dfrac16$ çıkar.

Hoca, sorunun başka biçimde de gelebileceğini söyledi: "Seri açılımı aşağıdakilerden hangisidir" ya da "bu limiti çözmek için hangi adım doğrudur" gibi. Şıklarda seri açılımının parçaları verilebilir.

Ardından hoca bir limit sorusu daha gösterdi. Değerler yerine konunca yine belirsizlik çıkıyordu. Hoca bunun da L'Hôpital ya da seri açılımı gibi yöntemlerle çözülebileceğini söyledi.

<!-- BELİRSİZ: 00:59:47'deki ikinci limit sorusunun ifadesi altyazıda geçmiyor. -->

> **Hocanın vurgusu:** Sonuç odaklı değil, süreç odaklı çalışın. Soru, sürecin tek bir adımını da sorabilir. Ayrıca zaman çok önemlidir: Kendinizi soru başına üç dakikaya göre ayarlayın. Bu sürede soruyu anlamak, çözmek ve doğru işaretlemek gerekir.

## 9. Kutupsal Koordinatlardan Kartezyen Koordinatlara Geçiş

Hoca seriler konusunu kapattı. Gelecek hafta parametrik denklemlere ve kartezyen-kutupsal koordinat geçişlerine girileceğini söyledi. Bu geçişlerin birinci dönemde de kısmen görüldüğünü hatırlattı. Konuya bir örnekle kısa bir giriş yaptı.

**Kutupsal ve kartezyen koordinatlar arası geçiş**

- $x=r\cos\theta$
- $y=r\sin\theta$
- $x^2+y^2=r^2$

**Örnek 12.** Kutupsal koordinatlarda $r=2\sin\theta$ eğrisini çiziniz.

Eğrinin kutupsal biçimde nasıl çizileceği ilk bakışta belli değildir. Hoca kartezyen koordinatlara geçmeyi önerdi.

1. Her iki taraf $r$ ile çarpılır: $r^2=2r\sin\theta$.
2. $r^2$ yerine $x^2+y^2$, $r\sin\theta$ yerine $y$ yazılır: $x^2+y^2=2y$.
3. Düzenlenir ve tam kareye tamamlanır: $x^2+y^2-2y+1=1$, yani
$$x^2+(y-1)^2=1.$$
4. Bu, merkezi $(0,1)$ ve yarıçapı $1$ olan çemberdir.

Hoca şöyle özetledi: Başlangıçta eğrinin ne olduğu bilinmiyordu. Kutupsal koordinatlardan kartezyen koordinatlara dönüştürülünce eğri tanıdık bir çembere dönüştü.

> **Ek bilgi (derste anlatılmadı):** $r$ ile çarpma, $r=0$ noktasını (orijini) ekleyebilir. Burada orijin zaten eğri üzerindedir ($\theta=0$ için $r=0$), bu yüzden yeni nokta eklenmez. $\theta$, $0$'dan $\pi$'ye giderken çember bir kez tam çizilir.

## 10. Örnek Sorular

Bu derste çözülen soruların hepsi geçmiş yılların sınav sorularıdır. Çözümlerin ayrıntısı yukarıdaki bölümlerdedir.

**Soru 1** (derste sözlü, 00:03:33): $\lim_{x\to0}\dfrac{\sin x}{x}$, $\lim_{x\to\infty}\dfrac{\sin x}{x}$ ve $\lim_{x\to\infty}\dfrac{\sin(1/x)}{1/x}$ limitleri neye eşittir?

> **Çözüm:** Sırasıyla $1$, $0$ ve $1$.

**Soru 2** (derste sözlü, 00:02:48): $\left\{\dfrac{n^{5/2}}{2n^2+1}\sin\dfrac{1}{\sqrt n}\right\}_{n\ge1}$ dizisinin limiti aşağıdakilerden hangisidir? <!-- BELİRSİZ: İfade kısa nottan alındı. -->

> **Çözüm:** Dizi $\dfrac{n^2}{2n^2+1}\cdot\dfrac{\sin(1/\sqrt n)}{1/\sqrt n}$ biçiminde yazılır. Limit $\dfrac12\cdot1=\dfrac12$ (Örnek 1).

**Soru 3** (derste sözlü, 00:07:45): $\displaystyle\sum_{n=0}^{\infty}n!\,(x-1)^n$ serisini yakınsak yapan $x$ değerleri aşağıdakilerden hangisidir?

> **Çözüm:** Oran testinde limit $(n+1)|x-1|\to\infty$ ($x\neq1$). Seri yalnız $x=1$'de yakınsaktır (Örnek 3).

**Soru 4** (derste sözlü, 00:13:26): $\displaystyle\sum_{n=0}^{\infty}\frac{(x+3)^n}{4^{n+1}}$ kuvvet serisinin yakınsaklık aralığını ve temsil ettiği fonksiyonu bulunuz.

> **Çözüm:** Geometrik seri, $r=\dfrac{x+3}{4}$. Yakınsaklık aralığı $(-7,1)$, temsil ettiği fonksiyon $\dfrac{1}{1-x}$ (Örnek 4).

**Soru 5** (derste sözlü, 00:16:57): $\displaystyle\sum_{n=2}^{\infty}n\ln\left(1-\frac1n\right)$ serisinin karakterini tespit ediniz.

> **Çözüm:** $\lim a_n=\ln\left(\lim\left(1-\frac1n\right)^n\right)=\ln e^{-1}=-1\neq0$. Genel terim testiyle ıraksak (Örnek 5).

**Soru 6** (derste sözlü, 00:39:33): $\{a_n\}=\left\{\dfrac34,\dfrac58,\dfrac7{16},\dfrac9{32},\dots\right\}$ ise $\sum a_n$ toplamını hesaplayınız.

> **Çözüm:** $a_n=\dfrac{2n+1}{2^{n+1}}$. $\sum\dfrac{n}{2^n}=2$ ve $\sum\dfrac1{2^{n+1}}=\dfrac12$. Toplam $\dfrac52$ (Örnek 6).

**Soru 7** (derste sözlü, 00:44:17): $\displaystyle\sum_{n=1}^{\infty}\frac{(x-4)^n}{2^n\sqrt[5]{n^3+7}}$ serisinin hangi $x$ değerleri için mutlak yakınsak, şartlı yakınsak ve ıraksak olduğunu araştırınız. <!-- BELİRSİZ: İfade kısa nottan alındı. -->

> **Çözüm:** $(2,6)$'da mutlak yakınsak, $x=2$'de şartlı yakınsak, $x<2$ ve $x\ge6$ için ıraksak (Örnek 8).

**Soru 8** (derste sözlü, 00:48:21): $\displaystyle\sum_{n=1}^{\infty}\left(\frac{2}{3^n}+\frac{(-1)^n}{5^n}\right)$ toplamı neye eşittir?

> **Çözüm (derste verilmedi):** $1-\dfrac16=\dfrac56$ (Örnek 9; sympy ile doğrulandı).

**Soru 9** (derste sözlü, 00:52:01): $\displaystyle\int_0^xe^{-t^2}\,dt$'nin Maclaurin serisinin genel terimi aşağıdakilerden hangisidir?

> **Çözüm:** $\dfrac{(-1)^nx^{2n+1}}{(2n+1)\,n!}$, $n=0,1,2,\dots$ (Örnek 10).

**Soru 10** (derste sözlü, 00:58:42): $\displaystyle\lim_{x\to0}\frac{x-\sin x}{x^3}$ limitini hesaplayınız. <!-- BELİRSİZ: İfade kısa nottan alındı. -->

> **Çözüm:** $\dfrac16$ (Örnek 11).

**Soru 11** (derste sözlü, 01:02:35): $r=2\sin\theta$ eğrisini çiziniz.

> **Çözüm:** $x^2+(y-1)^2=1$; merkezi $(0,1)$, yarıçapı $1$ olan çember (Örnek 12).

## Dersin Toparlaması

Bu derste seriler konusu geçmiş sınav sorularıyla kapatıldı. Dizi limitinde $\dfrac{\sin(1/x)}{1/x}\to1$ kalıbı kuruldu. Seri toplamlarında teleskopik seri, geometrik seri ve $\sum nx^n=\dfrac{x}{(1-x)^2}$ formülü kullanıldı. Karakter sorularında önce genel terim testine, sonra oran testine bakıldı. Kuvvet serilerinde oran testiyle aralık bulundu, uç noktalar $p$-serisi, limit testi ve Leibniz testiyle ayrı ayrı incelendi. Mutlak ve şartlı yakınsaklık farkı bu uç noktalarda ortaya çıktı. Maclaurin serisiyle bir integralin seri açılımı ve bir limit hesaplandı.

Dersin sonunda bir sonraki konuya giriş yapıldı. Kutupsal koordinatlardaki $r=2\sin\theta$ eğrisi, $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$ dönüşümleriyle bir çembere dönüştürüldü. Gelecek hafta parametrik denklemler ve kutupsal koordinatlarla devam edilecek. Hoca, yeni konuların önceki konuların üzerine kurulacağını ve sürecin hızlı ilerleyeceğini söyleyerek eski konuların şimdiden tekrar edilmesini istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
