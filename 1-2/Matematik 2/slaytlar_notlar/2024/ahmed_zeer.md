<details > <summary>Diziler</summary>

* ***<h4>Donem Hak. Bilg.</h4>***
    * diziler olmadan seriler olmaz.
    * kuvvet serileri cok onemli.
    * kisa baslik: parametrik denklemler.
    * Kutupsal koord zormus.
    * vektorler cartcurt carpimlar filan. Uzayda dogrular uzerinde duracagiz.
    * vektor degerli mat1e dayali.
    * cok degiskenli fonklar uzun soluklu. farkli ve zormus.
        * limit turev cartcurt mat1 iste.
    * katli integreler. araliklari kartezyen carpimlari zartzurt. dikdortgen veren integraller vs. hacim ve alan hesaplari
    * Kaynak ayni.

----------

* ***<h4>Sonsuz Dizi</h4>***

    * ***Tanim:** pozitif dogal sayilar uzerinde tanimlanmis fonk.*
    \[b_{n}=\frac{1}{n-1} \Longrightarrow \left\{b_{n}\right\}_{n=2}^{\infty} = \left\{1, \frac{1}{2}, \frac{1}{3}, \ldots, \frac{1}{n-1}, \ldots \right\}\]
    $$b_{n}=\frac{1}{n-1}\ \ \Longrightarrow\ \ \left\{b_{n}\right\}_{n=2}^{\infty}=\left\{1,\frac{1}{2},\frac{1}{3},\cdot\cdot\cdot,\frac{1}{n-1},\ \cdot\cdot\cdot\right\}$$

    * Dizinin butun elemanlari bir sayidan kucukse **ustten sinirli**.
        tam tersi ise **alttan sinirli**. ikisi de soz konusu ise **sinirli** denir.

    * **dizilerin yakinsakligi:** sonsuza limiti alinir ve ona gore yakinsakligi hespalanir. 0'e yaklasir cartcurt.
    * *latex*

    * **dizinin tekligi:** limiti varsa tektir.
    * **yakinsakligi:** limit varsa yakinsaktir. ( limit yok demek +-sonsuz ya da sureksiz demek )

    * ### Onemli limitler: 
        $$r>0\;\mathrm{ise,}\;\;\;\;\operatorname*{lim}_{n\to\infty}r^{1/n}\stackrel{}{=}\;1\;$$
        $$r > 1 \text{ise,}\;\;\;\;\lim_{n \to \infty} r^n = \infty$$
        $$|r| < 1 \text{ise,}\;\;\;\;\lim_{n \to \infty} r^n = 0$$
        $$\lim_{n \to \infty}\;\left(\sqrt[n]{n}\right) = 1 $$

    * **Limit teoremleri**:
        * dizinin limitini alinirken diziyi fonksiyon gibi dusunup onun limiti alinir. ( istisna var )
        * usttekinin tersi dogru degil. Diziden fonka gecemeyiz.
    * **Yakinsak iki dizinin toplami ve farki yakinsak.** ( bi zahmet ). iraksakta dogru degildir.
        *Asagidaki ornek iki iraksak fonkun topalmi yakinsak oldugnu gosterir*
       $$\lim_{n \to \infty} (a_n - b_n) = \lim_{n \to \infty} \left(\sqrt{n^2 + 2n} - n\right) = \lim_{n \to \infty} \frac{2n}{\sqrt{n^2 + 2n} + n} = 1$$


    * **Diziler sikistirma kurali.**
        $$\operatorname*{lim}_{n\rightarrow\infty}\frac{n!}{n^{n}}\ =\ 0 \;\;\;\text{gosterelim,}$$
        $$n\geq1\;\;\;\;\mathrm{icin}\;\;n=\;1\cdot2\cdot3\cdot\cdot n\;<\;1\cdot\,\ldots n\cdot\cdot n\;=\;n^{n-1}$$
        $$0\,<\,{\frac{n!}{n^{n}}}\,<\,{\frac{n^{n-1}}{n^{n}}}\,=\,{\frac{1}{n}}$$
        $${n\rightarrow\infty} \text{ durumunda,}$$
        $$\lim_{n \to \infty} \frac{n!}{n^n} = 0$$
    * **icine alma kurali:** fonk surekliyse icine limit alinabilir. ( triglar loglar vs. )
----------

* Monoton Diziler: daima artan veya azalan dizilere denir. an - an+1 ya da turevi alinir.

</details>




<details > <summary>Seriler</summary>

* ***<h4>Sonsuz Seriler.</h4>***

* Bir dizinin terimlerinin toplamidir. 
    $$\Large \sum_{k=1}^{\infty} a_k = a_1 + a_2 + \cdots + a_n + \cdots$$
    * Bu toplami bir terimda sonlandirirsak artik elimizde yepyeni bir dizi olmus olur. ( kismi toplamlar dizisi. ) 
    * Bu dizinin karakteri de serinin karakterini de verecek.
    * Kismi toplamlar dizisinin limiti varsa yakinsak oldugu soylenir. Ve toplami bulunabilir.

* Seri, bir dizinin toplami.

* Karakteri irksagi ve yakinsakligi.
* Sonsuz toplam yerine sonlu toplam yapip yorum yapacagiz.
* Kismi toplamlar dizisi bir limite sahipse yakinsak.
* Yakinsak bir serinin toplami farki yakinsaktir.
* Yakinsak bir serinin bir sayiyla carpimi yakinsaktir.

* Teleskopik seri: Bu yontem ozellikle ardisik gelenler icin kullanilir.
$$\Large \sum_{k=1}^{\infty} (a_{k-1} - a_k) = a_0 - \lim_{n \to \infty} a_n$$

----------

$$\Large \sum (a_{k})$$
$$\Large \text{serisi yakinsak ise}$$
$$\Large \lim_{k \to \infty} a_k = 0$$

Bu teoremin tersi dogru degildir. Yani, bir dizinin limiti 0 ise ondan olusan bir seri yakinsak olabildigi
gibi iraksak da olabilir.

***NOT:*** *Bir serinin genel teriminin limiti mevcut ise ve 0 degilse o dizi `iraksaktir`. 
0 cikarsa bir test uygulayip durumu degerlendirecegiz.*

----------
### Harmonik ve Geometrik  Seri
* HARMONIK SERI IRAKSAKTIR !!
* Harmonik serileri iraksaktir. Payin derecesi paydanin derecesinden 1 kucuk olan serilere harmonik seri denir.

$$\Large \sum_{k=1}^{\infty} \frac{1}{k} = 1 + \frac{1}{2} + \frac{1}{3} + \ldots$$

* Geometrik seri sinavda her zaman cikar.
* Geometrik serinin ilk teriminin r'nin kuvveti 0 olacak. Olmazsa ona gore ayarlariz.

$$\Large \sum_{k=1}^{\infty} ar^{k-1} = a + ar + ar^2 + \ldots$$

* `|r| < 1` iken `a/(1-r)` sayisina *yakinsar*, `|r| >= 1` ise *iraksar.*


----------
### Integral testi
* Surekli azalan ve pozitif bir fonk icin kullanilir.
* Importoper integralin bir sayi ise o sayi serinin toplamini ifade etmez. Sadece serinin karakterini belirler.
* Bir serinin impropern integralinin karakteri ve kendisnin karakteri aynidir.
----------
### p-serisi
* p pozitif bir reel sayi olmakla beraber,
$$\Large \sum_{k=1}^{\infty} \frac{1}{k^p} = 1 + \frac{1}{2^p} + \frac{1}{3^p} + \ldots$$
* p 1den buyuk oldugu zaman sadece yakinsaktir.

----------
### Mukayese Testi
* Eger bir serinin genel terimini baska bir serinin genel terimiyle mukayese edebiliyorsaniz ve o serinin 
karakterini biliyorsaniz mukayese testi elverislidir.
* Orjinial serimiz `a_k` olsun obur serimiz ise `b_k` olsun. 
    * Eger `a_k` nin butun terimleri `b_k` ninkinden **kucuk** kaliyorsa ve `b_k` serisinin karakteri yakinsaksa `a_k` da yakinsaktir.
    * Eger `a_k` nin butun terimleri `b_k` ninkinden **buyuk** kaliyorsa ve `b_k` serisinin karakteri iraksaksa `a_k` da iraksaktir.

***Limit Mukayese Testi:*** 

   * $$\lim_{{k \to \infty}} \frac{a_k}{b_k} = L$$ 
   * Eger `L > 0` ise her iki seri de yakinsar ya da iraksar.
   * Eger `L = 0` ise ve `b_k` yakinsak ise, `a_k` serisi de yakinsaktir.
   * Eger `L = sonsuz` ise ve `b_k` iraksak ise, `a_k` serisi de iraksaktir.

----------
### Alterne Serilerde Yakinsaklik:

* Bir alterne serinin multak degerini alinca `(-1)^n` terimi kalkar. Bu durumda, `a_n` kalir ve bu seri de yakinsak ise `mutlak yakinsak` denir.
* Ustteki teset basarisiz ise ve alttak sartlari sagliyorsa:
    * Seri azalandir.
    * Serinin her bir eleman pozitiftir.
    * Genel terim limiti 0dir.  
`sartli yakinsaktir.`

</details>


<details > <summary>Kuvvet Serileri</summary>

* $$\Large \sum a_k  x^k$$
dizisi icin sifirdan farkli `c` sayisi icin yakinsak ise
$$\Large |x| < |c|$$
saglayan butun x'ler icin yakinsaktir.

----------

### Yakinsaklik yaricapi ve araligi:

$$\Large \rho = \lim_{k \to \infty} \left| \frac{a_k}{a_{k+1}} \right|$$
$$\Large \rho = 0 \;\;\;, \;\;\; \Large{x = x_0} \;\;\;\small\text{  icin yakinsar }$$
$$\Large \rho = c \;\;\;, \;\;\; \Large{|x| < |c|} \;\;\;\small\text{  icin yakinsar }$$
$$\Large \rho = \infty \;\;\;, \;\;\; \Large{x = R} \;\;\;\small\text{  icin yakinsar }$$

* bulunan araliklarin uc noktalari ayrica kontrol edilmelidir.

----------

###  Kuvvet serileri ve fonksiyonlar.
$$\Large \frac{1}{1-x} = \sum_{x=1}^{\infty} x^k \;\;\;\; \small{|x|<1} $$
* verilen denklemi bu formata gore ayarlayip geometrik serinin ozelliklerinden faydalanacagiz.
`NOT: Bir serinin p gibi bir yakinsaklik yaricapina sahipse, bu fonksiyonun turevi de integrali de ayni p'ye sahiptir. ( aralik degisebilir )

----------

###  Serinin Turevi ve integrali.
* Her ne kadar bir serinin yakinsadigi aralik turev veya integral alininca degismese de uc noktalar kontrol edilmelidir.

</details>


<details > <summary>Kutupsal Koordinatlar</summary>

* `cos` iceren kardoitler `kutup eksenine`, yani x-ekseni, gore simetriktirler.
* `sin` iceren kardoitler `normal eksene`, yani y-ekseni, gore simetriktirler.
* Bazi kesisim noktalari denklemden gorulemedigi icin gradige bakarak daha iyi yorum yapabiliriz.
$$ x = r \cos(\theta) \;\;\;\;\; y = r \sin(\theta)$$
* Ustteki formulu kullanrak bir egrinin kutupsal koordinattaki egimini bulabilecegiz. bu da kesisen noktalari
ogrenmekte epeyce faydali olacaktir.

----------

$$ A = \int_{\alpha}^{\beta} \frac{1}{2} [f(\theta)]^2 d\theta$$
* Ustteki formulu kullanip kutbu bakis acisina alarak alan hesabi yapacagiz. 

----------

$$ L = \int_{\alpha}^{\beta} \sqrt{ [f(\theta)]^2 + [f^\prime(\theta)]^2 } \;d\theta$$
* Ustteki formulu kullanip kutupsal koordinatlarda olan bir yayin uzunulugunu bulacagiz.

</details>


<details > <summary>Vektorler</summary>

`Konum Vektoru:' Orjinden baslayip belli bir yere kadar giden vekotre konum vektoru denir.

`Paralel Vektorler:` 
$$ a = \lambda b $$

<p><a href="https://yildiz-edu-tr.zoom.us/rec/play/UMUkdaUcGyTB98MaezSidkn4llk_gAt5ltZDwTSUZAwS5aMR_REp8rXKqRye0htqP2haMM0OB9iYiyTh.Fm4ccCO7xlspp1Sw"/> click me</p>
`02:32:42 / 02:54:55`

</details>


<details > <summary>Vektorler</summary>

### Uzayda Dogrular

$$ \bold{r} = x \bold{i} + y \bold{j} + z \bold{k} $$
$$ x = x_0 + at \;\;\;\; y = y_0 + bt \;\;\;\; z = z_0 + ct $$
$$ \bold{v} = a \bold{i} + b \bold{j} + c \bold{k} $$

* `v` ile gosterilen vektor bizim icin cok onemlidir.
* Eger iki dogru birbirinin paraleli ise bu `yon vektorlerinin` paralel oldugunu gosterir.
* ustte verilen `a, b ve c` nin herhangi birisinin 0 olmasi durumunda denklem `simetrik olamaz`.
* Bunlardan herhangi birisinin 0 gelmesi durumunda tabana 0 yazmayacagiz. Tavani 0'a esitleyeceigiz. Bu durum
bizi `0/0` tanimsizligina goturur.

### Duzlemler

* Sunu hayal edelim, elimizde iki nokta var: `p` ve `p_0`. Bu iki noktayi birlestirerek bir vektor cizelim.
* Cizilen bu vektor oyle bir `n` vektoruyle noktasal carpilsin ki sonuc `0` versin.
* Bu `n` vektorune `normal vektor` adini verecegiz.
$$ \bold{n} = a\bold{i} + b\bold{j} + c\bold{k} $$
$$ a(x-x_0) + b(y-y_0) + c(z-z_0) = 0 $$ 
$$ ax + by + cz + d = 0 $$ 
* Nasil dogrularda **`v`** degeri cok onemli ise duzlemlerde normal dogru da **`n`** o kadar da onemli.
* Eger iki duzlemin normal dogrulari birbirine dikse, `n_1 . n_2 = 0` ise bo iki duzelem birbirine diktir.
* Eger iki duzlemin normal dogrulari paralelse , `n_1 X n_2 = 0` ise bo iki duzelem birbirine paraleldir.

$$ cos \theta = \frac{ \bold{n_1} . \bold{n_2} }{ ||n_1|| \; ||n_2||} $$
* ustteki formulun yardimiyla aradaki aciyi bulabiliriz.

* Eger bir dogrunun yonlu vektoru **`v`** ve bir duzlemin **`n`** normal dogrusu birbirine dikse o `dogru` ve `duzlem`
biribirine `paraleldir`.

* Eger bir dogrunun yonlu vektoru **`v`** ve bir duzlemin **`n`** normal dogrusu birbirine paralelse o `dogru` ve `duzlem`
biribirine `diktir`.

* Bir dogru boyunca kesisen duzlemler ailesine `duzlemler demeti` denir. Duzlemlerin genel terimleri 0 esitlenir.
ve birisi bir katsayi ile carpilip digeri ile toplanir.

* `Birlikte` turevleri sifir olmayan egriye duzgun egri denir.

$$ L = \int_{a}^{b} \{ [x'(t)]^2 + [y'(t)]^2 + [z'(t)]^2 \}^\frac{1}{2}dt $$
* Ustteki formul yardimiyla `yay uzunlugunu` bulabilecegiz.

</details>
