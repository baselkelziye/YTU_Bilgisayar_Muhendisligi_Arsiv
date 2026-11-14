# Ders 10 Genişletilmiş Notu: Vize Çözümleri, Fourier Sentezi, DFT ve FFT, Ayrık Zamanlı Fourier Serisi ve Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fourier Analizinden Fourier Sentezine: Tablodan Dalga Üretmek
- 2. Soru 1: Ayrık ve Sürekli İşaretlerin Çarpımı
- 3. Soru 2: Ayrık Konvolüsyon ve Sıfır Noktası
- 4. Soru 3: Birim Darbe Gösterimi, Çarpım, Tek-Çift Bileşenler, Enerji
- 5. Soru 4: Kare Dalganın Fourier Serisi ve Spektrumu
- 6. Analizden Senteze: Kare Dalgayı MATLAB'de Yeniden Kurmak
- 7. İşareti Sese Dönüştürmek ve İşitme Testi
- 8. DFT ve FFT
- 9. Ayrık Zamanlı Fourier Dönüşümüne Giriş
- 10. Ayrık Fourier Serisi ve Örnek: $x[n]=[0,1,2,3]$
- 11. Ayrık Zamanlı Fourier Dönüşümü Örnekleri
- 12. Ayrık Zamanlı Fourier Dönüşümünün Özellikleri
- 13. Sonsuza Giden İşaretler: Laplace ve Z Dönüşümüne Geçiş
- 14. Bu Ders Neden Önemli?

## 1. Fourier Analizinden Fourier Sentezine: Tablodan Dalga Üretmek

Hoca derse Fourier sentezini anlatarak başladı. Fourier analizinde bir işaretin kosinüs ve sinüs bileşenlerini tespit etmiştik. Bunun için bir integralle katsayıları buluyorduk. Hoca bu derste bu katsayılara zaman zaman $a_k$ dedi. Sentez bunun tersidir: Bileşenler elimizdedir ve onları toplayarak işareti yeniden oluştururuz.

Örnek olarak bir tablo gösterildi. Tabloda bir işaretin her frekans bileşeni için faz bilgisi, $a_k$ katsayısı, bu katsayılardan üretilen genlik (magnitude) değeri ve frekans yer alıyor. Toplam 17 bileşen var. Bazı frekanslarda $a_k$ katsayısı sıfırdır. Bu, o frekans bileşeninin işarette bulunmadığı anlamına gelir. Sıfır olanlar yazılmaz; geriye birkaç tane gerçek bileşen kalır.

Slaytta bu bileşenlerin toplamı adım adım çizilmişti. Önce yalnız ilk bileşen tek başına çizilir. İkincisi eklenince dalganın biçimi değişir. Üçüncü, dördüncü ve beşinci bileşenler eklendikçe dalga son biçimine yaklaşır. Elde edilen dalga, tablodaki değerlerin ait olduğu sese, yani "A" sesine karşılık gelir. Örnekleme frekansı olarak 20 000 Hz seçilirse, bu dalga formunun nasıl bir sese karşılık geldiği duyulabilir.

<!-- BELİRSİZ: Tablonun sayısal değerleri ve slayttaki grafikler altyazıda okunmuyor; yalnız 17 bileşen olduğu ve bazılarının sıfır olduğu söyleniyor. -->

**Soru:** Gerçel kısmın iki katını alarak MATLAB'de yazdırıyorum, ama grafikler pek benzemiyor. Neden olabilir? **Cevap:** İki olası sebep var. Birincisi, sinüzoidlerin denklemi yanlış kurulmuş olabilir. Dalga formu farklıysa önce bu denklem gözden geçirilmelidir. İkincisi, çizimde sık yapılan bir hata vardır. `plot(y)` yazılırsa ve `y` örneğin 1000 uzunlukta bir vektörse, MATLAB yatay ekseni otomatik olarak 1'den 1000'e kadar örnek numarası olarak atar. Zamana bağlı bir işareti görmek için `plot(t, y)` yazmak gerekir. Tablodaki değerlerle slayttaki grafikler birbirine uyumludur.

## 2. Soru 1: Ayrık ve Sürekli İşaretlerin Çarpımı

Hoca sonra vize sorularını çözdü. İlk soru iki maddeden oluşuyor. Her iki maddede de işaretlerin çarpımı var, konvolüsyon değil. Bu yüzden integral ya da konvolüsyon işlemi gerekmez; işaretler çizilip karşılıklı değerler çarpılır.

### 2.1 a Maddesi: $x[n]=(3-n)\,(u[n]-u[n-3])$

Bu bir ayrık işarettir ve grafiği de ayrık çizilmelidir.

> **Hocanın vurgusu:** Ayrık bir işaretin sonucu sürekli bir çizgi olarak çizilirse, değerler mantıken yakın olsa bile cevap yanlıştır. Bunun ayrık bir işaret olduğu baştan görülmelidir.

Önce birinci çarpanın birkaç değerine bakalım. $3-n$ ifadesi $n$'e bağlıdır:

| $n$ | $-1$ | $0$ | $1$ | $2$ | $3$ | $4$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $3-n$ | $4$ | $3$ | $2$ | $1$ | $0$ | $-1$ |

Bu değerler iki yönde de sonsuza kadar sürer. Şimdi parantez içindeki işarete bakalım. $u[n]$, $n=0$'dan başlayıp sıfırdan büyük bütün değerlerde 1 olan işarettir. $u[n-3]$ ise üç birim ötelenmiştir, yani $n=3$'ten itibaren 1'dir. Bunları çıkarınca $n=3$ ve sonrasındaki değerler birbirini götürür. Geriye yalnız $n=0,1,2$ noktalarında 1 olan bir işaret kalır.

İki işareti vektörel olarak çarpmak, karşılıklı değerleri çarpmak demektir. $n<0$ için ikinci işaret 0 olduğundan çarpım da 0'dır. Geri kalanlar:

$$x[0]=3\cdot 1=3,\qquad x[1]=2\cdot 1=2,\qquad x[2]=1\cdot 1=1$$

$n\geq 3$ için yine 0'dır. Sonuç $3,2,1$ değerlerinden oluşan bir ayrık işarettir. İstenirse vektör biçiminde de yazılabilir: $x[n]=[\underline{3},2,1]$. Altı çizili değer $n=0$ noktasıdır.

### 2.2 b Maddesi: $y(t)=v(t)\,[u(t)-u(t-1)]+v(t)\,\delta(t+1)$

Soruda $v(t)$ grafik olarak verilmiş. Bu işaret önce bir işaretle, sonra başka bir işaretle çarpılıyor ve iki sonuç toplanıyor. Hoca, köşeli parantez içindeki kısma geçici olarak $\alpha(t)$ dedi:

$$\alpha(t)=u(t)-u(t-1)$$

$u(t)$ sıfırdan başlayan bir basamaktır, $u(t-1)$ ise bir noktasından başlar. Birinciden ikinci çıkarılınca $t=1$ noktası dahil bütün sağ taraf gider, ama bir noktasının öncesi kalır. Sonuç, $[0,1)$ aralığında 1 olan bir işarettir. $t=1$ noktası açık noktadır, yani dahil değildir. İşaret sürekli olduğu için $0.99999$ gibi değerler işaretin içindedir; bu aralıktaki değerleri "$1$ ile birlikte" atmak yanlıştır.

$v(t)$ ile $\alpha(t)$ çarpılınca $v(t)$'nin sıfırdan önceki ve birden sonraki değerleri önemini yitirir. Çarpım, $v(t)$'nin $[0,1)$ aralığındaki değerlerini korur. Grafikte bu aralıkta genlik 3'tür. Sağ uçtaki açık noktayı işaretlememek ya da bu parçayı düz çizgi olarak çizmek kabul edilebilir bir çizimdir. Asıl önemli olan, $t=1$'e kadar olan bütün değerlerin saklı kalmasıdır.

Toplamın sağ tarafında birim darbe (impuls) fonksiyonuyla çarpım var. $\delta(t+1)$, $t=-1$ noktasında bulunur. Bir işareti birim darbeyle çarpmak, işaretin o noktadaki değerinden örnek almaktır:

$$v(t)\,\delta(t+1)=v(-1)\,\delta(t+1)$$

Grafikte $v(-1)=0$ olduğu için bu terim sıfırdır ve yazılması gerekmez. Sonuç olarak $y(t)$, $[0,1)$ aralığında 3, $-\infty$'dan $0$'a kadar ve $1$'den itibaren $0$ olan bir işarettir.

<!-- BELİRSİZ: v(t) grafiği altyazıda okunmuyor. Hoca "şurası 3 olacak, burası 1 olacak" ve t=-1'deki değerin sıfır olduğunu söylüyor; v(t)'nin başka aralıklardaki biçimi bilinmiyor. -->

## 3. Soru 2: Ayrık Konvolüsyon ve Sıfır Noktası

Verilen işaretler şunlardır (altı çizili değer $n=0$ noktasıdır):

$$x[n]=[2,\underline{3},2,1],\quad n=-1,\dots,2 \qquad\qquad h[n]=[2,-1,\underline{1},-2],\quad n=-2,\dots,1$$

Sonucun indis aralığı, işaretlerin sınır indislerinin toplanmasıyla bulunur. Başlangıç $-1+(-2)=-3$, bitiş $2+1=3$ olur. Yani $y[n]$, $n=-3$'ten $n=3$'e kadar 7 değer alır.

İşlem ters çevir, kaydır, çarp, topla yöntemiyle yapılır. Bir işaret ters çevrilip diğerinin üzerinde kaydırılır. Her kaydırmada üst üste gelen değerler karşılıklı çarpılıp toplanır:

| $n$ | Üst üste gelen çarpımlar | $y[n]$ |
| :---: | :---------- | :---: |
| $-3$ | $2\cdot 2$ | $4$ |
| $-2$ | $2\cdot(-1)+3\cdot 2$ | $4$ |
| $-1$ | $2\cdot 1+3\cdot(-1)+2\cdot 2$ | $3$ |
| $0$ | $2\cdot(-2)+3\cdot 1+2\cdot(-1)+1\cdot 2$ | $-1$ |
| $1$ | $3\cdot(-2)+2\cdot 1+1\cdot(-1)$ | $-5$ |
| $2$ | $2\cdot(-2)+1\cdot 1$ | $-3$ |
| $3$ | $1\cdot(-2)$ | $-2$ |

(Altyazıda her satırın terimleri okunmadığından çarpım dökümü ara adım olarak eklendi; sonuçlar hocanınkiyle aynıdır.) Hoca tahtada $n=1$ değerini önce $-4$ buldu, sonra toplamı yeniden yaparak ($-1+2=1$, $1-6=-5$) $-5$ olarak düzeltti. Sonuç:

$$y[n]=[4,\ 4,\ 3,\ \underline{-1},\ -5,\ -3,\ -2]$$

Sonuç `numpy.convolve` ile aynı çıktı.

Sıfır noktasını bulmanın iki yolu vardır. En kolayı başlangıç indisinden saymaktır: $-3,-2,-1,0$. Dördüncü değer olan $-1$, $n=0$ noktasıdır. İkinci yol, iki işaretin sıfır noktalarının karşılıklı çarpıldığı adımı bulmaktır. Burada $x[0]=3$ ile $h[0]=1$ dördüncü adımda çarpılıyor, yani yine dördüncü değer. Konvolüsyonu birim darbe fonksiyonları cinsinden yazarak yapmak ise işin asıl esasıdır; o zaman da $n$'lerin karşılıklı çarpıldığı nokta sıfır noktasını doğrudan verir.

Grafik çizilirken ayrık çizgiler $n=-3$'te 4, $n=-2$'de 4, $n=-1$'de biraz daha küçük olan 3, $n=0$'da $-1$, sonra $-5$, $-3$ ve $-2$ değerlerindedir.

> **Hocanın vurgusu:** Bu soruda zorlanılan yer çarpımlar değil, sınırların ve sıfır noktasının tayin edilmesidir. Bunlar doğru tespit edilmelidir.

## 4. Soru 3: Birim Darbe Gösterimi, Çarpım, Tek-Çift Bileşenler, Enerji

Ayrık zamanlı işaret şöyle veriliyor:

$$x[n]=[-1,\ 2,\ 0,\ \underline{3},\ -7,\ 6],\qquad n=-3,\dots,2$$

### 4.1 a Maddesi: Birim Darbe Cinsinden Yazmak

Soruda birim darbe (unit impulse) cinsinden yazılması isteniyor. Birim darbe $\delta[n]$, yalnız $n=0$ noktasında 1 olan işarettir. Birim basamak (unit step) $u[n]$ ise başka bir işarettir. Bu işareti birim basamak cinsinden yazmak zordur, çünkü çok sayıda $u[n]$ terimi gerekir. Birim darbeyle yazmak doğaldır.

> **Hocanın vurgusu:** Birim darbe ile birim basamak birbirine karıştırılmamalıdır. Soruda birim darbe isteniyorsa $u[n]$ ile yazmak cevap değildir.

Sıfır noktasından başlayalım. $n=0$'daki değer 3 olduğu için $3\delta[n]$ terimi gelir: $\delta[n]$, $n=0$'da 1 verir, 3 ile çarpılınca 3 olur. Geriye doğru gidince $n=-1$'de genlik 0'dır, yani $0\cdot\delta[n+1]$ terimini yazmak gerekmez. $n=-2$'de genlik 2, $n=-3$'te genlik $-1$'dir. İleri doğru $n=1$'de $-7$, $n=2$'de $6$ vardır. Sonuç:

$$x[n]=-\delta[n+3]+2\delta[n+2]+3\delta[n]-7\delta[n-1]+6\delta[n-2]$$

> **Ders sonrası not:** Hoca sıfır noktasının solundaki terimleri söylerken "$n-3$", "$n-2$" dedi ve bunu düzeltmeye çalıştı. Doğrusu yukarıdaki yazımdır: $n=-3$ noktasındaki örnek $\delta[n+3]$, $n=-2$ noktasındaki örnek $\delta[n+2]$ ile yazılır.

### 4.2 b Maddesi: $y[n]=x[n]\,(u[n]-u[n+2])$

$x[n]$'in grafiğini çizmek çözümü zaten ortaya çıkarır. $n=-3$'te $-1$, $n=-2$'de $2$, $n=-1$'de $0$, $n=0$'da $3$, $n=1$'de $-7$, $n=2$'de $6$ değerleri vardır.

Parantez içindeki işarete hoca $v[n]$ dedi. $u[n]$ sıfır noktasından başlar. $u[n+2]$ ise $n=-2$ noktasından başlar. İkisi şöyle dizilir:

| $n$ | $-3$ | $-2$ | $-1$ | $0$ | $1$ | $2$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $u[n]$ | $0$ | $0$ | $0$ | $1$ | $1$ | $1$ |
| $u[n+2]$ | $0$ | $1$ | $1$ | $1$ | $1$ | $1$ |
| $v[n]=u[n]-u[n+2]$ | $0$ | $-1$ | $-1$ | $0$ | $0$ | $0$ |

$v[n]$ yalnız $n=-2$ ve $n=-1$'de sıfırdan farklıdır ve orada $-1$'dir. Çarpım karşılıklı değerler arasında yapılır:

$$y[-1]=x[-1]\cdot v[-1]=0\cdot(-1)=0,\qquad y[-2]=x[-2]\cdot v[-2]=2\cdot(-1)=-2$$

Diğer bütün noktalarda çarpım 0'dır. Sonuç $y[n]=-2\,\delta[n+2]$, yani $n=-2$ noktasında genliği $-2$ olan tek bir darbedir. İstenirse vektör biçiminde de yazılabilir.

Sık yapılan hata, genliği $+2$ yazmaktır. Bir başka hata, işlemi toplama gibi düşünüp ortaya başka genlikler çıkarmaktır. Burada vektörel çarpma vardır: Yalnız 2 değeri kalır ve $v[-2]$'nin negatifliğinden dolayı $-2$ olur.

> **Ders sonrası not:** Altyazıda hoca soruyu okurken bir yerde "$u[n]-u[n-2]$" geçiyor. Çözümde kullandığı işaret, "eksi iki noktasından başlayan" $u[n+2]$'dir; doğrusu $u[n]-u[n+2]$'dir. Yukarıdaki değerler Python ile bu ifadeden hesaplandı.

### 4.3 c Maddesi: Tek ve Çift Bileşenler

Tek-çift ayrıştırması için $x[n]$ ile birlikte $x[-n]$ gerekir:

$$x_e[n]=\frac{x[n]+x[-n]}{2},\qquad x_o[n]=\frac{x[n]-x[-n]}{2}$$

$x[-n]$, işaretin dikey eksen etrafında döndürülmesiyle elde edilir. $n=2$'deki 6 değeri $n=-2$'ye, $n=1$'deki $-7$ değeri $n=-1$'e gelir, $n=0$'daki 3 yerinde kalır. Dikkat edilecek nokta limitlerin değişmesidir: $x[-n]$, $n=-2$'den $n=3$'e kadar uzanır. Bu yüzden iki işaret birlikte $n=-3$'ten $n=3$'e kadar yazılır, boş kalan yerlere 0 konur:

| $n$ | $-3$ | $-2$ | $-1$ | $0$ | $1$ | $2$ | $3$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $x[n]$ | $-1$ | $2$ | $0$ | $3$ | $-7$ | $6$ | $0$ |
| $x[-n]$ | $0$ | $6$ | $-7$ | $3$ | $0$ | $2$ | $-1$ |
| $x_e[n]$ | $-\frac12$ | $4$ | $-\frac72$ | $3$ | $-\frac72$ | $4$ | $-\frac12$ |
| $x_o[n]$ | $-\frac12$ | $-2$ | $\frac72$ | $0$ | $-\frac72$ | $2$ | $\frac12$ |

Hesaplardan birkaçı: $n=-3$'te çift bileşen $(-1+0)/2=-\frac12$, $n=-2$'de $(2+6)/2=4$, $n=-1$'de $(0-7)/2=-\frac72$, $n=0$'da $(3+3)/2=3$. Tek bileşen için $n=-2$'de $(2-6)/2=-2$, $n=-1$'de $(0+7)/2=\frac72$, $n=0$'da $(3-3)/2=0$, $n=1$'de $(-7-0)/2=-\frac72$, $n=2$'de $(6-2)/2=2$, $n=3$'te $(0+1)/2=\frac12$. Değerleri $-0.5$ gibi ondalık yazmak da uygundur. Tablodaki değerler Python ile aynı çıktı ve $x_e[n]+x_o[n]=x[n]$ eşitliğini sağlıyor.

> **Hocanın vurgusu:** Toplama ve çıkarma aynı indisler üzerinden yapılır. $x[n]$'in başındaki $-1$ ile $x[-n]$'in başındaki 6 birbiriyle toplanmaz, çünkü farklı indislerdedir. $n=-3$'te $x[-n]$'in değeri 0'dır.

### 4.4 d Maddesi: $y[n]$'in Enerjisi

Ayrık zamanlı bir işaretin enerjisi, bütün değerlerin karelerinin toplamıdır:

$$E=\sum_{n=-\infty}^{\infty}|y[n]|^2$$

$y[n]$, $n=-2$ dışında her yerde sıfırdır:

$$E_y=\dots+0+(-2)^2+0+\dots=4\ \text{J}$$

Soruda enerjisi istenen işaret $y[n]$'dir. $x[n]$'in enerjisini hesaplamak, yöntem bilinse de sorulan şeyin cevabı değildir.

> **Ders sonrası not:** Hoca enerji formülünü önce "$n=0$'dan sonsuza" diye söyledi. Doğrusu toplamın $-\infty$'dan $+\infty$'a alınmasıdır; hesapta da bunu kullandı. Burada fark önemlidir, çünkü tek sıfırdan farklı değer $n=-2$'dedir ve $n=0$'dan başlayan toplam yanlışlıkla 0 verirdi.

## 5. Soru 4: Kare Dalganın Fourier Serisi ve Spektrumu

Son soruda periyodik bir kare dalga var. İşaret $0<t<2$ aralığında $-1$, $2<t<4$ aralığında $4$ değerini alıyor ve kendini tekrar ediyor. Derste yapılan örneklere benziyor, tek farkı genliklerin $-1$ ve $4$ olmasıdır. Soruda sırayla temel frekans, DC bileşen, $c_k$ katsayıları, buradan $a_k$ ve $b_k$ katsayıları, sonra frekans spektrumu isteniyor.

### 5.1 Periyot ve Temel Frekans

Periyot bulunurken herhangi bir başlangıç noktası seçilir ve işaretin aynı değere yeniden ulaştığı nokta aranır. Sıfırdan başlanınca işaret kendini 4'te tekrar eder:

$$T_0=4\ \text{s},\qquad f_0=\frac{1}{T_0}=\frac14=0.25\ \text{Hz},\qquad \omega_0=\frac{2\pi}{T_0}=\frac{2\pi}{4}=\frac{\pi}{2}\ \text{rad/s}$$

> **Ders sonrası not:** Hoca hem burada hem ayrık örnekte "$\omega_0=2\pi/f_0$" dedi. Doğrusu $\omega_0=2\pi f_0=2\pi/T_0$'dır. Hesapta kullandığı $\pi/2$ değeri doğrudur.

### 5.2 DC Bileşen

DC bileşeni bulmak $a_0$'ı bulmak demektir. Bu, işaretin bir periyot boyunca altındaki alanın periyoda bölünmesidir:

$$a_0=\frac{1}{T_0}\int_0^{T_0}x(t)\,dt=\frac14\int_0^2(-1)\,dt+\frac14\int_2^4 4\,dt$$

$$a_0=\frac14\Big[-t\Big]_0^2+\frac14\Big[4t\Big]_2^4=\frac14(-2-0)+\frac14(16-8)=\frac{-2+8}{4}=\frac{6}{4}=\frac32$$

Sayısal integral de $1.5$ veriyor.

### 5.3 $c_k$ Katsayıları

Karmaşık gösterimdeki katsayı formülü şudur:

$$c_k=\frac{1}{T_0}\int_0^{T_0}x(t)\,e^{-jk\omega_0 t}\,dt$$

Değerler yerine konunca:

$$c_k=\frac14\int_0^2(-1)\,e^{-jk\frac{\pi}{2}t}\,dt+\frac14\int_2^4 4\,e^{-jk\frac{\pi}{2}t}\,dt$$

Hoca "Allah'tan kolay integraller" diyerek bunları çözdü. Üstel fonksiyonun integralinde üstel aynen yazılır, $t$'nin önündekiler paydaya iner:

$$c_k=\frac14\left(\left[\frac{-e^{-jk\frac{\pi}{2}t}}{-jk\frac{\pi}{2}}\right]_0^2+\left[\frac{4\,e^{-jk\frac{\pi}{2}t}}{-jk\frac{\pi}{2}}\right]_2^4\right)$$

Birinci terimdeki eksiler birbirini götürür. Sınırlar yazılırken $t=2$ için üs $-jk\pi$, $t=4$ için $-jk2\pi$, $t=0$ için $0$ olur:

$$c_k=\frac14\cdot\frac{1}{jk\frac{\pi}{2}}\left[\left(e^{-jk\pi}-1\right)-4\left(e^{-jk2\pi}-e^{-jk\pi}\right)\right]$$

$\frac14$'ü en başta ortak parantezde tutmak işi kolaylaştırır. $\frac14\cdot\frac{1}{jk\pi/2}=\frac{1}{jk2\pi}$ olur. Burada $\pi/2$'nin 2'si yukarı atılmış, 4 ile sadeleşmiştir.

Şimdi Euler açılımı kullanılır:

$$e^{-jk2\pi}=\cos(k2\pi)-j\sin(k2\pi)=1$$

Çünkü $k$ ne olursa olsun sinüs 0, kosinüs 1'dir. Köşeli parantez şuna dönüşür: $e^{-jk\pi}-1-4+4e^{-jk\pi}=5e^{-jk\pi}-5$.

$$c_k=\frac{1}{jk2\pi}\left(5e^{-jk\pi}-5\right)$$

> **Hocanın vurgusu:** Euler açılımı her zaman lazım olan bir formüldür. $e^{-jk2\pi}$ gibi ifadeler onunla hemen 1'e iner.

Paydadaki $j$'den kurtulmak için pay ve payda $j$ ile çarpılır. $j\cdot j=-1$ olduğundan payda eksiye döner, bu eksi de parantezin içine dağıtılır:

$$c_k=\frac{j}{-2k\pi}\left(5e^{-jk\pi}-5\right)=\frac{j}{2k\pi}\left(5-5e^{-jk\pi}\right)=\frac{5j}{2k\pi}\left(1-e^{-jk\pi}\right)$$

Son olarak $e^{jk\pi}$'nin iki türlü davrandığı hatırlanır. $k$'nın çift değerlerinde $2\pi$'nin katları, tek değerlerinde $\pi,3\pi,\dots$ gelir. Bu yüzden $e^{-jk\pi}=(-1)^k$ yazılabilir:

$$c_k=\frac{5j}{2k\pi}\left(1-(-1)^k\right)$$

**Soru:** Sol altta $j$'yi yukarı atıyoruz. Oradan sonrasını anlamadım. **Cevap:** Paydadan karmaşık sayıyı kaldırmak için pay ve payda aynı sayıyla çarpılır. $\frac{a}{j}$ ifadesinde pay ve payda $j$ ile çarpılırsa payda $j\cdot j=-1$ olur, yukarıda $aj$ kalır. Sonuç $-aj$'dir. Bu eksi işareti de parantezin içine dağıtılır.

Katsayılar böylece üç durumda yazılır:

$$c_k=\begin{cases}\dfrac32, & k=0\\[6pt] 0, & k\ \text{çift},\ k\neq0\\[6pt] \dfrac{5j}{k\pi}, & k\ \text{tek}\end{cases}$$

Tek $k$ için $1-(-1)^k=2$ olur ve ikiler sadeleşir. Sayısal integral bunu doğruluyor: $c_0=1.5$, $c_{\pm1}=\pm1.5915j$, $c_{\pm2}=0$, $c_{\pm3}=\pm0.5305j$, $c_{5}=0.3183j$.

Hoca çift $k$'lar için sıfır çıkmasını "işaret tek fonksiyon olduğu için kosinüs bileşeni olmaz" diye bağladı.

> **Ders sonrası not:** Bu iki gözlem ayrı şeylerdir. Kosinüs bileşeninin hiç olmaması ($k$ tek olsa da $a_k=0$) DC'si çıkarılmış işaretin, yani $x(t)-\frac32$'nin tek olmasındandır; işaretin kendisi tek değildir. Çift indisli harmoniklerin sıfır olması ise ayrı bir sonuçtur: Çift $k$ için hem $a_k$ hem $b_k$ sıfırdır, yani o sıralardaki sinüsler de yoktur. Hesapta $c_{\pm2}=0$ ve bütün tek $k$'larda gerçel kısım $0$ çıktı.

### 5.4 $a_k$ ve $b_k$

Kosinüslü terimlerin katsayısı gerçel kısımdan, sinüslü terimlerin katsayısı sanal kısımdan gelir:

$$a_k=2\,\mathrm{Re}(c_k)=0,\qquad b_k=-2\,\mathrm{Im}(c_k)=-2\cdot\frac{5}{k\pi}=-\frac{10}{k\pi}\quad(k\ \text{tek})$$

> **Ders sonrası not:** Hoca $b_k$ için "$-\frac{5}{k\pi}$" dedi. Bu değer $b_k$ değil, karşılıklı bileşenin ($\pm k$) yarı genliğidir. $b_k=-2\,\mathrm{Im}(c_k)$ formülüne göre doğrusu $-\frac{10}{k\pi}$'dir. Hoca birazdan sentezde, Euler formülüyle bu iki katı doğru kullanacak. Sayısal hesap: $b_1=-3.1831$, $b_3=-1.0610$.

### 5.5 Frekans Spektrumu

Soruda ilk üç frekans için artı ve eksi taraf birlikte isteniyor, çünkü bileşenler karmaşık eşlenik olarak karşılıklı çıkar. Frekanslar temel frekansın katlarıdır: $\pm0.25$, $\pm0.5$, $\pm0.75$ Hz. Hoca bu noktalara $-\frac{5}{k\pi}$ değerlerini çizdi:

| $k$ | $-3$ | $-2$ | $-1$ | $0$ | $1$ | $2$ | $3$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $f$ (Hz) | $-0.75$ | $-0.5$ | $-0.25$ | $0$ | $0.25$ | $0.5$ | $0.75$ |
| Hocanın çizdiği değer | $+\frac{5}{3\pi}$ | $0$ | $+\frac{5}{\pi}$ | $\frac32$ | $-\frac{5}{\pi}$ | $0$ | $-\frac{5}{3\pi}$ |
| $c_k$ | $-\frac{5j}{3\pi}$ | $0$ | $-\frac{5j}{\pi}$ | $\frac32$ | $\frac{5j}{\pi}$ | $0$ | $\frac{5j}{3\pi}$ |
| $\lvert c_k\rvert$ | $\frac{5}{3\pi}$ | $0$ | $\frac{5}{\pi}$ | $\frac32$ | $\frac{5}{\pi}$ | $0$ | $\frac{5}{3\pi}$ |

$k=\pm2$ için katsayı sıfırdır, grafikte o noktada çizgi yoktur. Hoca çizerken $k=\pm3$ değerlerini önce yanlış yere koydu, sonra 0.75'e taşıdı. Frekans arttıkça genlik sönümlenir ve sonsuzda 0'a gider.

> **Ders sonrası not:** $c_k$ saf sanal olduğu için tablodaki gerçel işaretli değerler aslında $j c_k=-\frac{5}{k\pi}$'dir, $c_k$'nın kendisi değildir. Genlik spektrumu çizilecekse $|c_k|=\frac{5}{k\pi}$ çizilir, $\pm k$ tarafları eşittir.

## 6. Analizden Senteze: Kare Dalgayı MATLAB'de Yeniden Kurmak

Hoca bu analizden sonra sentezi gösterdi. Amaç, bulunan katsayılardan işaretin kendisini yeniden elde etmek ve böylece analizin doğru olduğunu görmektir.

### 6.1 Katsayılardan Kosinüslere

Bir sinüzoid $A\cos(2\pi f t+\phi)$ biçimindedir. Hedef, işareti bu terimlerin toplamı olarak yazmaktır: $\sum_i A_i\cos(2\pi f_i t+\phi_i)$. Bunun için genlik, frekans ve faz gerekir.

Spektrumdaki değerler neden doğrudan genlik değil? Euler formüllerini hatırlayalım:

$$e^{j\omega}=\cos\omega+j\sin\omega,\qquad e^{-j\omega}=\cos\omega-j\sin\omega$$

Taraf tarafa toplanırsa sinüsler gider:

$$\cos\omega=\frac{e^{j\omega}+e^{-j\omega}}{2}$$

Yani genliği $A$ olan bir kosinüs, $+f$ ve $-f$ taraflarına $A/2$'şer olarak dağılır. Spektrumda her iki tarafta $\frac{5}{k\pi}$ görüyorsak, kosinüsün genliği bunun iki katıdır: $\frac{10}{k\pi}$. Sinüsü kosinüs olarak yazmak için de faza $\frac{\pi}{2}$ eklenir, çünkü $\cos(\theta+\frac{\pi}{2})=-\sin\theta$'dır:

$$x(t)=\frac32+\sum_{k\ \text{tek}}\frac{10}{k\pi}\cos\left(2\pi k f_0 t+\frac{\pi}{2}\right)=\frac32+\sum_{k\ \text{tek}}\left(-\frac{10}{k\pi}\right)\sin\left(k\omega_0 t\right)$$

Bu ifade 5.4'teki $b_k$ ile aynıdır.

### 6.2 Kod

Hoca MATLAB Online'da bir betik yazdı. `clear` ve `clc` ile başladı. Temel frekansı `f = 0.25`, örnekleme frekansını `fs = 100` aldı. `y` değişkenini DC bileşenle (1.5) başlattı. Zaman vektörünü $0$'dan $5-1/f_s$'ye kadar $1/f_s$ adımlarla kurdu. Çift bileşenler sıfır olduğu için döngü değişkeni ikişer ikişer artar.

```matlab
clear; clc;
f  = 0.25;              % temel frekans
fs = 100;               % örnekleme frekansı
t  = 0:1/fs:5-1/fs;     % zaman vektörü
y  = 3/2;               % DC bileşen
for v = 1:2:5           % yalnız tek harmonikler
    x = 10/(v*pi) * cos(2*pi*f*v*t + pi/2);
    y = y + x;
end
plot(y)                 % yatay eksen örnek numarası olur
```

İlk çalıştırmada `plot(y)` kullanıldı. `y` bir vektör olduğu için yatay eksen 1'den uzunluğuna kadar örnek numarasıdır ve 500'e kadar gider. Oysa sınavdaki grafikte zaman ekseni 0, 2, 4 diye gidiyordu. Bu yüzden `plot(t, y)` yazılmalıdır. Görüntüde işaret $-1$ ile $+4$ arasında dolaşır.

Hoca "şu anda kaç sinüzoidal bileşen var?" diye sordu; cevap üçtü ($k=1,3,5$). Döngü üst sınırı önce 15'e, sonra 155'e çıkarıldı. 15'te 0'dan 2'ye kadar $-1$ civarında, 2'den 4'e kadar $+4$ civarında bir işaret görüldü. 155'te işaret kare dalgaya çok yaklaştı. Köşelerdeki salınımlar daha önce gördüğümüz Gibbs olayıdır. Bileşen ekledikçe kare dalgaya yaklaşmak, 5. bölümdeki analizin doğru olduğunu kanıtlar.

> **Ders sonrası not:** Kod numpy ile aynı adımlarla çalıştırıldı. Vektör uzunluğu 500 çıktı. Köşelerdeki taşmayı gösteren değerler: `1:2:5` için $-1.471$ ile $4.471$, `1:2:15` için $-1.447$ ile $4.447$, `1:2:155` için $-1.311$ ile $4.311$. Son değerin küçük çıkması $f_s=100$ ızgarasının tepeyi kaçırmasındandır: Çok sık örnekleyip 1555'e kadar toplayınca tepe yine $-1.447$ ile $4.447$ çıktı. Ortalama hata azalsa da köşe taşması kaybolmuyor.

Döngü ödev tablosu için de aynı mantıkla çalışır: Genliği sıfır olan satır yazılmaz, her satırdaki genlik, frekans ve fazla bir kosinüs oluşturulup nihai değişkene eklenir.

**Soru:** Bunu `for` ile mi yapacağız? **Cevap:** İstenirse `for` ile yapılır, ama bileşen sayısı 5-6 olduğu için normal değişkenlerle de yazılabilir. Bu yalnız kodu biraz uzatır.

### 6.3 Bilgisayar Mühendisi İçin Neden Önemli?

Hoca buradan bir uygulamaya geçti. Bir ses tanıma uygulaması yapacağımızı düşünelim. Örüntü tanıma ya da makine öğrenmesi derslerinde bu konuyla karşılaşılabilir. Sesin frekans bileşenleri notaya, harfe, kelimeye, kişinin yorgunluğuna ve duygusuna göre değişir. Bu, aslında bir parmak izi, yani biyometri uygulamasıdır. Örneğin yorgun durumdaki genlik-frekans tablosu bir biçimdedir, dinç durumdaki başka biçimdedir. Do notasında bir biçimde, fa notasında başka biçimdedir.

Yapılan analizle ham veriden ayırt edici özellik (feature) çıkarılır ve bu özellikler uygulamalarda kullanılır. Aynı şey görüntü işlemede de vardır, orada iki boyutlu olarak.

## 7. İşareti Sese Dönüştürmek ve İşitme Testi

### 7.1 `sound` Komutu

MATLAB'de `sound` fonksiyonu herhangi bir vektörü sese dönüştürür. Yalnız veri verilirse varsayılan bir örnekleme frekansı kullanılır. İstenirse 22 050 veya 44 100 gibi bir değer de verilebilir:

```matlab
t = 0:0.01:10;              % derste yazılan zaman vektörü
x = 10 * cos(2*pi*1000*t);  % 1 kHz işaret
plot(t, x)
sound(y)                    % varsayılan örnekleme frekansı
sound(y, 22050)             % örnekleme frekansı verilerek
```

Hoca insan kulağının 10 kHz, 20 kHz'e kadar duyduğunu hatırlatarak 1 kHz bir işaret tanımladı. Grafik beklenen biçimde çıkmadı. Bir öğrencinin önerisiyle değişken adı `x1` yapıldı, `.*` denendi, ama çizim yine sıfırdan ona dalgalanma göstermeden on değerinde kaldı.

> **Ders sonrası not:** Altyazıda okunan değerlerle bu sonuç bekleneni verir. $t$ adımı 0.01 s iken $2\pi\cdot1000\cdot0.01\,m=20\pi m$ olur, yani her örnek kosinüsün tam katına denk gelir. Numpy ile hesapta 1001 örneğin hepsi tam olarak 10 çıktı. Yani sorun değişken adı veya `.*` değil, 1 kHz işaret için örnekleme adımının çok büyük olmasıdır. 1 kHz işareti görmek için çok daha küçük bir adım gerekir.

Sonra `sound` çalıştırıldı, ama MATLAB Online tarayıcının izin vermediğini bildirdi. Hoca bunu kullanılan tarayıcıya bağladı ve kendi bilgisayarınızda denemenizi söyledi.

Derste bir öğrenci kendi kodunda tablodaki bileşenlerden "A" sesini gerçekten duyduğunu söyledi ve ekranını paylaştı. Ses paylaşımı derse ulaşmadı. Bu sırada dalganın 40 milisaniyelik olduğu ve bu yüzden sesin kısa çıktığı, süre uzatılınca daha rahat duyulacağı konuşuldu. Hoca "analiz ve sentez bu işe yarıyor" diyerek bağladı.

<!-- BELİRSİZ: Hocanın ses için son denemesinde kullandığı kod (01:24:15-01:25:46) altyazıda okunmuyor. Süre uzatma işleminin nasıl yapıldığı da (01:33:47) net değil. -->

### 7.2 İşitme Testi

Hoca farklı frekanslarda sinüzoidal dalga çalan bir işitme testi videosu açtı. Video düşük bir frekanstan başlayıp yükseldikçe kulağın neyi duyabildiğini soruyor. Burada yapılan işlem, farklı frekanslarda sinüzoidal dalga göndermektir. Duyulan o "çirkin" ses, az önce yapılan şekilde ses biçimine dönüştürülmüş bir sinüs işaretidir.

Hastanelerdeki odyometri testleri de aynı mantıkla yapılır: Belli bir frekanstan başlanıp kişiye sinüzoidal dalgalar dinletilir. En düşükten en yükseğe rahat duyabilmek işitmenin iyi olduğunu gösterir. Videoda frekans arttıkça dalga formu belirsizleşir, çünkü periyot küçülür. Hepsi yine sinüzoidal işaretlerdir.

### 7.3 Nota ve Ses Sentezi

İki kosinüs toplanarak nota elde edilebilir. Hoca daha önce sözü edilen C6 notasını örnek verdi. Temel frekansı 1047 Hz'dir. Yalnız 1047 Hz çalınırsa basit bir sinüzoidal ses duyulur. Bu notayı örneğin obuada duymak isteseniz, 2000 küsürlerde ve başka yerlerde birkaç frekans bileşeni eklemeniz gerekir. Çıkan ses bu şekilde yapay olarak taklit edilir. Kaynak olarak "Music Information Retrieval" sayfasını gösterdi.

İnsan sesi de bir yere kadar böyle taklit edilebilir. Bununla ilgili bilimsel çalışmalar var. Örneğin kişi normal konuşur, ama matematiksel bir dönüşümle çıkan ses başkasının sesi olur.

<!-- BELİRSİZ: 01:31:34'teki enstrüman adı altyazıda "o boy" diye geçiyor, obua olarak okundu. 01:32:00'daki "su bu fikir ama de zehirlenme" kısmı anlaşılmıyor; ses dönüştürme çalışmasının adı olabilir. -->

## 8. DFT ve FFT

Hoca bundan sonra slaytların biraz dışına çıktı. Şimdiye kadar Fourier serilerini ve Fourier dönüşümünü sürekli işaretlerde çalıştık. Oysa bilgisayarcı olarak elimizdeki veriler ayrıktır. Bu yüzden birkaç terimi ayırmak gerekir.

### 8.1 DFT

Fourier dönüşümü Fourier serilerini kapsar, çünkü periyodik olmayan işaretleri de analiz edebilir. Bu dönüşümün algoritmik olarak gerçeklenmesine ayrık Fourier dönüşümü (Discrete Fourier Transform, DFT) denir.

Yapılan iş şudur: $\int_{-\infty}^{\infty}f(t)\,e^{-j\omega t}\,dt$ integralinin yerine iki toplam sembolü gelir. $f(t)$'nin değerleri ile $e^{j\omega t}$'nin değerleri çarpılıp toplanır. Algoritmik karmaşıklığı işaretin uzunluğu $N$'ye göre $O(N^2)$'dir.

Bu maliyetlidir. Hoca CD kalitesinde 4 dakikalık bir müziği örnek verdi: $4\times 60\times 44\,100$ örnek. Bu uzunlukta bir dizi için uzunluğun karesi kadar işlem yapmak gerekir.

> **Ders sonrası not:** Hoca örnek sayısını konuşurken "240 milyon" dedi. Verdiği çarpımın sonucu $4\times60\times44\,100=10\,584\,000$'dir, yani yaklaşık 10.6 milyon örnektir (tek kanal). İşlem sayısı $N^2\approx1.12\times10^{14}$ olur. Ana fikir değişmez: $N^2$ işlem çok büyüktür. Ayrıca hoca MATLAB'de DFT adlı bir fonksiyon olduğunu söyledi; temel MATLAB'de karşılığı büyük olasılıkla `fft` komutudur, bu kayıtta denenmedi.

> **Ek bilgi (derste anlatılmadı):** Derste formülü yazılmayan DFT, kaynaklarda büyük olasılıkla $N$ örnekli bir dizi için $X[k]=\sum_{n=0}^{N-1}x[n]e^{-j2\pi kn/N}$ biçiminde verilir. Her $k$ için $N$ terimlik bir toplam yapıldığından $N^2$ işlem çıkar; dersteki "iki toplam" budur. Bu toplam, 9. bölümdeki $X(\Omega)$'nın $\Omega=2\pi k/N$ noktalarındaki değerleridir; numpy ile bu eşitlik doğrulandı. Yani DFT sonlu sayıda frekans noktası verir, ayrık zamanlı Fourier dönüşümü ise sürekli bir fonksiyon verir. Hoca derste "ayrık Fourier dönüşümü" derken çoğunlukla ikincisini kastediyor.

### 8.2 FFT

Bunun daha hızlısı hızlı Fourier dönüşümüdür (Fast Fourier Transform, FFT). Yine algoritmik bir gerçeklemedir, ama karmaşıklığı $O(N\log N)$'ye indirir. Ayrıntıları sayısal işaret işleme dersinde anlatılır.

### 8.3 MATLAB'de `fft` Denemesi

Hoca az önce sentezlediği işaretle devam etti. Döngüyü `1:2:5` yaptı. İşaretin içinde 3 kosinüs ve bir DC bileşen, yani toplam 4 bileşen var. Bunları ayırmak için önce şunu yazdı:

```matlab
Y = real(fft(y));
plot(Y)
```

Fourier dönüşümü gerçel ve sanal kısımlardan oluşan sonuç döndürür. Beklenti, frekans düzlemindeki görüntüde 4 bileşen varsa 4 noktada tepe görmektir. Grafikte sayıldığında yaklaşık 4 tepe görüldü, ama eksen hâlâ örnek numarasıdır. Frekans düzlemine geçmek için eksenin sinyal uzunluğuna ve temel frekansa göre ayarlanması gerekir.

Hoca sonra daha düzenli hazırladığı kodu açtı. Mutlak değer (`abs`) aldı, FFT'den sonra `fftshift` yaptı. Bu kaydırma sıfırı ortaya alır, yani pozitif ve negatif frekansları birlikte gösterir. Bir de frekans ekseni `F` kurdu ve `subplot` ile üstte zaman, altta frekans düzlemini çizdi:

```matlab
Y = abs(fftshift(fft(y)));
F = (-length(y)/2 : length(y)/2-1) * fs/length(y);
subplot(2,1,1); plot(t, y);
subplot(2,1,2); plot(F, Y);
```

<!-- BELİRSİZ: Hocanın hazır kodu altyazıda okunmuyor. abs, fftshift, F değişkeni ve subplot kullanımı anlatımdan alındı; F satırının açık yazımı eklendi. Python karşılığı 500 örnekle çalıştırıldı. -->

Yakınlaşınca 1, 3 ve 5. harmonikler ile DC bileşen görülür. Frekans ekseni artı ve eksi taraflıdır. Döngü 75'e çıkarılınca küçük frekanslarda genlik yüksek, yüksek frekanslarda azalarak giden çok sayıda tepe görülür. Bu, 5. bölümde bulduğumuz sonucun frekans düzlemindeki karşılığıdır.

Son tepe nerede olmalı? Temel frekans $0.25$ Hz olduğu için $75\times0.25=\frac{75}{4}=18.75$ Hz. Grafikte son tepe $18.8$ olarak okundu. Ondan önceki tepe 73. harmoniktir.

> **Ders sonrası not:** Hoca 18.8 değerini "FFT olduğu için bir kayıp var, DFT olsa daha doğru olurdu" diye açıkladı. Doğrusu FFT ile DFT aynı sonucu verir, FFT yalnız daha hızlıdır. Numpy ile doğrudan DFT toplamı ile `fft` arasındaki en büyük fark $5\times10^{-11}$ çıktı. Sapmanın sebebi frekans çözünürlüğüdür: $f_s=100$ ve 500 örnekle aralık $100/500=0.2$ Hz'dir, bu yüzden 18.75 Hz'ye en yakın nokta 18.8'dir. Hesapta tepe gerçekten 18.8'de çıktı. Aynı sebeple 5 terimli denemede tepeler $0.2$, $0.8$ ve $1.2$ Hz noktalarında çıktı; 0.25, 0.75 ve 1.25 Hz bu ızgarada yoktur.

> **Ders sonrası not:** Hoca 73. harmonik için "73 bölü 4, 17 küsur" dedi. Doğrusu $73/4=18.25$ Hz'dir. Yine hoca "`abs` yerine `real` de diyebilirdim" dedi. Bu ikisi aynı şey değildir: Hesapta $0.4$ Hz noktasında `abs` 239.6, `real` 90.8 verdi. Genlik için `abs` kullanılır.

### 8.4 `plot` mu `stem` mi?

Frekans düzlemindeki görüntü ayrıktır, sürekli çizgi işe yaramaz. Bu yüzden `plot` ile değil `stem` ile çizmek gerekir. Ama `stem`'in de bir sakıncası var: Tepe olmayan, sıfıra çok yakın küçük noktaları da çizdiği için çizimi okumak zorlaşır. Çok yakınlaşınca bu değerlerin sıfıra yakın olduğu görülür. Genlik spektrumu çift fonksiyon gibi davranır.

FFT'nin ayrıntılı kullanımı bu dersin konusu değildir. Görüntü işleme veya sayısal işaret işleme derslerinde anlatılır.

> **Hocanın vurgusu:** Ayrık işaretler ve frekans düzlemindeki ayrık görüntüler `plot` ile değil, `stem` ile çizilmelidir.

## 9. Ayrık Zamanlı Fourier Dönüşümüne Giriş

Ayrık zamanda Fourier dönüşümü yapılacaksa karşımıza çıkan yöntemin adı ayrık zamanlı Fourier dönüşümüdür (Discrete Time Fourier Transform, DTFT). Bu dönüşüm $n$'ye bağlı bir işaretin içindeki frekans bileşenlerini bulur; artık $t$'ye bağlı işaret yoktur. Sürekli zamanda integral kullanıyorduk, burada toplam sembolü kullanılır. Küçük $\omega$ yerine büyük $\Omega$ yazılır. Kaynaklarda kısaca DTFT olarak görülür, Türkçe kaynaklarda da kısaltması vardır.

<!-- BELİRSİZ: Türkçe kısaltma altyazıda "AZFT" diye geçiyor, kısa notta "AZFD". Hocanın hangisini söylediği net değil. -->

Hoca konuyu bir kitaptan anlattığını, kitabın güzel örnekler içerdiğini söyledi. Çok ayrıntısı var, ama sürekli zamanın mantığı öğrenildikten sonra ayrık zaman aynıdır. Bu yüzden formülleri ve birkaç örneği vermek yeterlidir.

<!-- BELİRSİZ: Kitap altyazıda "Şans'ın kitabı" diye geçiyor; büyük olasılıkla Schaum serisidir. -->

İki durum ayrılır. İşaret periyodikse ayrık Fourier serisi, periyodik değilse ayrık zamanlı Fourier dönüşümü konuşulur. Periyodik durumda katsayılar sürekli zamana benzer biçimde bulunur:

$$c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]\,e^{-jk\Omega_0 n}$$

Periyodik olmayan durumda $k\Omega_0$ yerine $\Omega$ gelir ve toplam $-\infty$'dan $+\infty$'a alınır:

$$X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]\,e^{-j\Omega n}$$

Burada $x[n]$ ile bir korelasyon yapılır. Örneğin elimizde $1,2,3$ gibi bir ayrık işaret varsa, her değer kendi $n$'ine ait $e^{-j\Omega n}$ ile çarpılır: $1\cdot e^{-j\Omega n}+2\cdot e^{-j\Omega n}+3\cdot e^{-j\Omega n}$. Burada her terimde $n$ o örneğin indisidir. Sonuçta $\Omega$'ya bağlı bir denklem elde edilir.

Ters dönüşümde toplam değil, integral kullanılır. Hoca önce toplamla başlamak üzereyken bunu düzeltti:

$$x[n]=\frac{1}{2\pi}\int_{2\pi}X(\Omega)\,e^{j\Omega n}\,d\Omega$$

Sebebi şudur: Ayrık bir işaretin dönüşümü sürekli bir fonksiyon olur. Burası ayrık, orası süreklidir. Sürekli halden geri dönmek için integral almak gerekir. Bu bir integral dönüşümdür: Ana fonksiyonun yanında bir değişken bulunur ve bu değişken işin sonunda bize yeni boyutu verir. Ters integralle birlikte $\Omega$'dan yeniden $n$'ye geçilir. Laplace dönüşümünde aynı mantıkla buna kontur integrali denecek.

Sürekli zamandaki Fourier dönüşümünde olduğu gibi burada da yakınsama şartı vardır: Çarpımların toplamı sonsuza gitmemelidir.

> **Ek bilgi (derste anlatılmadı):** Ters dönüşümdeki integralin neden $2\pi$ uzunlukta bir aralıkta alındığı şöyle görülür: $n$ tam sayı olduğundan $e^{-j(\Omega+2\pi)n}=e^{-j\Omega n}$'dir. Dolayısıyla $X(\Omega+2\pi)=X(\Omega)$ olur, yani fonksiyon $2\pi$ ile periyodiktir. Numpy ile bu integral 11.2'deki sonuca uygulandı ve $x[n]$ değerleri geri elde edildi.

## 10. Ayrık Fourier Serisi ve Örnek: $x[n]=[0,1,2,3]$

Ayrık Fourier serisinden söz ediyorsak işaret periyodiktir ve önce temel periyot $N_0$ bulunur. Sürekli zamanda da periyodu bulduktan sonra integral alıyorduk. En genel haliyle seri şöyledir:

$$x[n]=\sum_{k=0}^{N_0-1}c_k\,e^{jk\Omega_0 n}$$

Bunu açarsak $\cos(k\Omega_0 n)$ ve $\sin(k\Omega_0 n)$ terimleri görülür. Yani işaret, temel frekansın katlarındaki sinüzoidlerden oluşur. $c_k$ de bir periyot üzerinden hesaplanır:

$$c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]\,e^{-jk\Omega_0 n}$$

Dönüşüm çifti ve önceki formüllerin sürekli zamandan farkı, integral yerine toplam gelmesi ve küçük $\omega_0 t$ yerine büyük $\Omega_0 n$ yazılmasıdır.

### 10.1 Örnek

Verilen: $x[n]=[0,1,2,3]$, $N_0=4$. Fourier katsayıları isteniyor. Önce temel frekansa geçilir:

$$\Omega_0=\frac{2\pi}{N_0}=\frac{2\pi}{4}=\frac{\pi}{2}$$

$k=0$ DC bileşendir. Üstel terim 1 olduğu için toplam, işaretin değerlerinin toplamı olur. Sürekli zamandaki "bir periyottaki alan"ın karşılığı budur. Aslında bu, aritmetik ortalamadır:

$$c_0=\frac14(0+1+2+3)=\frac64=\frac32$$

Dört örnek olduğu için dört katsayı vardır: $c_0,c_1,c_2,c_3$. Diğerleri için daha genel bir yazım kullanılır. $\Omega_0=\pi/2$ olduğundan:

$$e^{-j\frac{\pi}{2}kn}=(-j)^{kn}$$

Böylece hesap kısalır. $(-j)$'nin kuvvetleri $(-j)^1=-j$, $(-j)^2=-1$, $(-j)^3=j$, $(-j)^4=1$ diye döner.

**$c_1$:**

$$c_1=\frac14\sum_{n=0}^{3}x[n](-j)^{n}=\frac14\left(0+1\cdot(-j)+2\cdot(-1)+3\cdot j\right)=\frac14(-2+2j)=-\frac12+\frac{j}{2}$$

Bu ifade, $\cos x+j\sin x$ açılımına benzer. Zaten buradan ona geçilir.

**$c_2$:** Bu kez üs $2n$ olur:

$$c_2=\frac14\sum_{n=0}^{3}x[n](-j)^{2n}=\frac14\left(0+1\cdot(-1)+2\cdot 1+3\cdot(-1)\right)=\frac{-2}{4}=-\frac12$$

Burada sanal kısım yoktur, yalnız kosinüs bileşeni vardır.

**$c_3$:** Bu kez üs $3n$ olur:

$$c_3=\frac14\sum_{n=0}^{3}x[n](-j)^{3n}=\frac14\left(0+1\cdot j+2\cdot(-1)+3\cdot(-j)\right)=\frac14(-2-2j)=-\frac12-\frac{j}{2}$$

Dönüşümü bu biçimde yapabilmemizin sebebi yine Euler denklemidir. Dört katsayı da Python'daki doğrudan toplamla ve `fft(x)/4` ile aynı çıktı; bu katsayılarla seri toplanınca $[0,1,2,3]$ geri geldi.

**Soru:** $(-j)^3$'ü nasıl bulduk, tekrar anlatabilir misiniz? **Cevap:** Çarpım yapacağımız terim $e^{-jk\Omega_0 n}$'dir. $\Omega_0=\pi/2$ yazınca Euler ile $\cos(k\frac{\pi}{2}n)-j\sin(k\frac{\pi}{2}n)$ olur. Açı $\frac{\pi}{2},\frac{2\pi}{2},\frac{3\pi}{2}$ diye ilerler. Birim çemberde bu noktalara bakılırsa sonuçlar $j$'nin kuvvetleri biçiminde gelir. Daha önce $e^{jk\pi}$ için $(-1)^k$ bulmuştuk; burada aynı mantıkla $(-j)^{kn}$ çıkar. Bu dönüşümü başta bir kez yapmak hesabı kısaltır, istenirse sonda da yapılabilir.

$\Omega_0$, $\pi/2$ yerine $5\pi/7$ gibi bir değer çıksaydı bu kısayol olmazdı, üstelin karşılığını bulup yazmak gerekirdi.

### 10.2 Çalışma Önerisi

Hoca çalışmak için bir alıştırma önerdi: $x[n]=[1,1,1,1,1,0,0,0,0,0]$ işaretinin Fourier serisi katsayılarını bulun.

> **Ders sonrası not:** Derste çözülmedi. Kontrol için, $N_0=10$ alınarak Python ile bulunan sonuç: $c_0=\frac12$; $k\neq0$ çift için $c_k=0$; $k$ tek için $c_1=0.1-0.3078j$, $c_3=0.1-0.0727j$, $c_5=0.1$, $c_7=0.1+0.0727j$, $c_9=0.1+0.3078j$.

## 11. Ayrık Zamanlı Fourier Dönüşümü Örnekleri

### 11.1 Örnek: $x[n]=\delta[n]$

İşaretin periyodik olmadığı kabul edilir; tek bir değeri vardır. Formülde yerine yazalım:

$$X(\Omega)=\sum_{n=-\infty}^{\infty}\delta[n]\,e^{-j\Omega n}$$

$n$, $-\infty$'dan sıfıra gelene kadar $\delta[n]$ sıfırdır, dolayısıyla terimler $0+0+0+\dots$ diye gelir. $n=0$'da $\delta[0]=1$ ve üstel terim de $e^{0}=1$ olur. Bu noktadan $+1$ gelir. Sıfır geçilince terimler yine sıfırdır. Toplam:

$$X(\Omega)=1$$

Yani $n$ düzleminde tek bir darbe olan işaretin $\Omega$ düzlemindeki karşılığı, her yerde 1 olan bir fonksiyondur.

### 11.2 Örnek: $x[n]=a^n u[n]$

Önce işareti tanıyalım. **Soru:** Bu işaret sağ taraflı mı, sol taraflı mı? **Cevap:** Sağ taraflıdır, çünkü $u[n]$ yüzünden yalnız sıfırdan sonraki değerler kalır.

Hoca çizmek için $a$'yı birden büyük bir tam sayı, örneğin 2 aldı: $2^1,2^2,2^3,2^4$ diye üstel artan bir işaret.

Dönüşümün formülü yazılır:

$$X(\Omega)=\sum_{n=-\infty}^{\infty}a^n u[n]\,e^{-j\Omega n}$$

$u[n]$ yüzünden sınır sıfırdan başlar ve $u[n]$ terimi kalkar:

$$X(\Omega)=\sum_{n=0}^{\infty}a^n\,e^{-j\Omega n}$$

Burada üslü sayılarla işlem yapılır ve geometrik seri hatırlanır. $n$ ortak üs olarak alınır:

$$X(\Omega)=\sum_{n=0}^{\infty}\left(a\,e^{-j\Omega}\right)^n$$

Serilerden $\sum_{n=0}^{\infty}r^n=\frac{1}{1-r}$ formülünü biliyoruz. Burada $r=a\,e^{-j\Omega}$'dır:

$$X(\Omega)=\frac{1}{1-a\,e^{-j\Omega}}$$

Formülün şartı $|r|<1$'dir. Hoca bunu sınıfa sordu. **Soru:** Mutlak değerce birden büyük olursa ne olur? **Cevap:** Sonsuza ıraksar. Bu durumda dönüşüm alınamaz. $|e^{-j\Omega}|=1$ olduğundan şart şuna iner:

$$|a|<1$$

Eşitlik de olmaz, ifade sonsuza gitmemeli ve yakınsamalıdır. Bu şartlar altında yukarıdaki sonuç işaretin frekans düzlemindeki karşılığıdır. Sayısal olarak $a=0.5$, $a=-0.5$ ve $a=0.9$ için kısmi toplamla kapalı formül arasındaki en büyük fark $3\times10^{-15}$'ten küçük çıktı. Ters dönüşüm integraliyle $a=0.5$ için $x[n]$ değerleri de ($n=0,1,2,3$ için $1,\ 0.5,\ 0.25,\ 0.125$; negatif $n$ için $0$) geri geldi.

> **Ders sonrası not:** Hoca grafik için $a=2$ seçti. Bu işaretin DTFT'si yoktur, çünkü şart $|a|<1$'dir. Çizim üstel azalan bir işaret için ($0<a<1$) düşünülmelidir.

Hoca sonucun grafiğini de konuştu ve $\Omega=0$ noktasında değerin 1 çıktığını, $\Omega$ arttıkça terimin sıfıra gittiğini, grafiğin azalarak devam ettiğini söyledi.

> **Ders sonrası not:** Bu anlatım doğru değildir. $\Omega=0$'da $X(0)=\frac{1}{1-a}$ olur, 1 değil. Ayrıca $\Omega$ arttıkça $e^{-j\Omega}$ sıfıra gitmez, çünkü üs sanaldır ve $|e^{-j\Omega}|=1$'dir. $X(\Omega)$, $2\pi$ periyotludur. $0<a<1$ için genlik $\Omega=0$'da en büyük ($\frac{1}{1-a}$), $\Omega=\pi$'de en küçüktür ($\frac{1}{1+a}$). Numpy ile bu uç değerler doğrulandı, $2\pi$ noktasında genlik başlangıç değerine geri döndü.

Hoca, başka işaretlerde de uygulamaları olduğunu, ama bu dersin sayısal işaret işleme olmadığı için uzun uzun girmeyeceğini söyledi.

## 12. Ayrık Zamanlı Fourier Dönüşümünün Özellikleri

Sürekli zamandaki Fourier dönüşümünde gördüğümüz özellikler burada da vardır. Bunların faydası, her seferinde yeniden dönüşüm almak zorunda kalmamaktır.

**Zamanda öteleme.** Sürekli zamanda $x(t)\leftrightarrow X(j\omega)$ biliniyorsa, $x(t-t_0)$ için yeniden dönüşüm almıyorduk; $e^{-j\omega t_0}$ ile çarpıyorduk. Aynısı burada da geçerlidir:

$$x[n-n_0]\ \leftrightarrow\ e^{-j\Omega n_0}X(\Omega)$$

**Frekansta öteleme.** Öteleme frekansta yapılırsa karşılığı zamanda ($n$ düzleminde) bir çarpandır:

$$e^{j\Omega_0 n}x[n]\ \leftrightarrow\ X(\Omega-\Omega_0)$$

**Doğrusallık.** Toplamın dönüşümü, ayrı ayrı dönüşümlerin toplamıdır.

**Konvolüsyon.** $x_1[n]$ ve $x_2[n]$ işaretlerinin frekans düzlemindeki karşılıkları biliniyorsa, konvolüsyon almak yerine bunları vektörel çarpmak yeter:

$$x_1[n]*x_2[n]\ \leftrightarrow\ X_1(\Omega)\,X_2(\Omega)$$

Zamanda çarpma yapılırsa, frekans düzleminde konvolüsyon alınır.

Bu dört özellik küçük bir deneme işaretiyle numpy üzerinde sınandı; her birinde fark $10^{-14}$ mertebesinin altındaydı. Zamanda çarpma için frekanstaki konvolüsyonun $2\pi$ periyot üzerinden alınıp $\frac{1}{2\pi}$ ile çarpılması gerektiği de bu denemede görüldü.

> **Ders sonrası not:** Hoca ölçeklemenin de sürekli zamandakiyle aynı olduğunu söyledi. Ayrık zamanda bu aynen geçerli değildir. Deneme işaretinde $x[2n]$ için $\frac12 X(\Omega/2)$ formülü tutmadı (en büyük fark yaklaşık 1.72). Çünkü $x[2n]$ bazı örnekleri atar ve $x[an]$, tam sayı olmayan $a$ için tanımlı değildir.

Hoca ayrık zamanlı sistemlerde bu özelliklerin bazı kolaylıklar sağladığını söyledi. Geçenlerde bir diferansiyel denklem çözülmüştü; burada da fark denklemleri çözülebilir. Bunu ve birkaç örneği ileride konuşacağını belirtti.

## 13. Sonsuza Giden İşaretler: Laplace ve Z Dönüşümüne Geçiş

Hoca dersi sonraki konuya bağladı. Sürekli (continuous) ve ayrık (discrete) Fourier dönüşümlerini gördük. İkisinde de sonsuza gitme durumu olabilir. Fourier dönüşümü belli şartlar kabul edilerek yapılan bir dönüşümdür. Peki işaret sonsuza gidiyorsa bunun bir çözümü yok mu?

Sonsuza gitmenin İngilizcesi ıraksama (divergence) demektir. Bu durum için iki yeni dönüşüm önerilmiştir:

- **Sürekli işaretler için:** Laplace dönüşümü.
- **Ayrık işaretler için:** Z dönüşümü.

İkisinin yaptığı şey aynıdır: İşareti sonsuza gitmekten alıkoyan bir parametreyle çarpmak. Laplace'ta bu şöyle görünür:

$$\int_{-\infty}^{\infty}f(t)\,e^{-st}\,dt$$

$e^{-st}$ çarpanındaki eksi $s$ parametresi sayesinde işaretin "tepesine basılır", sonsuza gitmesi engellenir. Z dönüşümü de aynısının ayrık halidir. Bu yüzden ikisi de Fourier dönüşümünün daha genel halidir. Sürekli zamanda ve ayrık zamanda Fourier'yi daha genel yazan bu dönüşümlerle devam edilecek. Konvolüsyon veya diferansiyel denklem gibi işlemler orada daha kolay görülecek, ters dönüşümlere de yeri gelince bakılacak.

> **Ek bilgi (derste anlatılmadı):** Derste $s$ açılmadı. Büyük olasılıkla kaynaklarda $s=\sigma+j\omega$ biçiminde yazılır. O zaman $e^{-st}=e^{-\sigma t}e^{-j\omega t}$ olur. "Tepesine basan" kısım gerçel $e^{-\sigma t}$ çarpanıdır, $\sigma=0$ alınınca da Fourier dönüşümü geri gelir.

<!-- BELİRSİZ: 02:31:04'teki "Tabi büyükler bozuyor" ifadesi altyazıda anlaşılmıyor. -->

## 14. Bu Ders Neden Önemli?

Ders sonunda hoca dersin önemi üzerine konuştu. Bu dersin konuları makine öğrenmesi, akıllı sistemler ve yapay zeka gibi konular için temeldir, özellikle akademik çalışılacaksa. Körü körüne görüntü işleme ya da video işleme yapmak ileride çok anlam ifade etmez, çünkü yöntemler sürekli değişir ve yalnız var olan yöntemleri kullanmayı bilen kişi tıkanır.

Konvolüsyon bunun iyi bir örneğidir. Hoca makale ve konferans değerlendirmelerinde, konvolüsyonun ne olduğunu bilmeden "aldım, kullandım" denerek hazır kodla yapılmış çalışmalar gördüğünü anlattı. Oysa konvolüsyonun birkaç farklı biçimi ve parametresi vardır. Örneğin sıfır noktasının tespiti görüntü işlemede ve MATLAB'de önemlidir. Yanlış tespit edilirse görüntü yanlış işlenir, bilgi çıkarılamaz. Konvolüsyondan sonra gerekli kaydırma (shift) işlemi yapılmalıdır. Derin öğrenmeyle ilgili kısımda bunlar da gösterilecek.

> **Hocanın vurgusu:** Bu iş yalnız MATLAB'de veya başka bir dilde kod yazmaktan ibaret değildir. Teoriyi bilmek sizi bir üst noktaya taşır.

Hoca bu derste konuyu oturtmak için soru çözmenin çok önemli olduğunu da söyledi. Bunu antrenmana benzetti: Önceden antrenman yapmış olmak işi rahatlatır. Örnekleme (sampling) ve filtreler bu derste anlatılmıyor; filtreler sayısal işaret işleme dersine ayrılmıştır.

Sıradaki konular için de şunu söyledi: Şimdiye kadar bir problemi çözmek için gördüğümüz yollar işin zor tarafıydı. Konvolüsyon için konvolüsyon integrali, Fourier dönüşümü için integral hesabı gerekiyordu. Laplace, Z dönüşümü ve Fourier dönüşümü özellikleri ise çözüme daha kolay götürür. Bir problemi Laplace ile çözmek, Fourier ile çözmekten daha kolaydır. Burada gerekli olan karmaşık sayılar ve integral, lise matematiği düzeyindedir.

## Dersin Toparlaması

Bu derste önce Fourier sentezi tanıtıldı, sonra vize soruları üzerinden ayrık işaretlerin çarpımı, ayrık konvolüsyon ve sıfır noktası, birim darbe gösterimi, tek-çift ayrıştırma, enerji ve kare dalganın Fourier serisi çözüldü. Kare dalganın katsayıları MATLAB'de toplanarak dalga yeniden kuruldu. Böylece analiz ile sentezin birbirini nasıl doğruladığı, harmonik sayısı arttıkça işaretin kare dalgaya nasıl yaklaştığı ve köşelerde Gibbs olayının nasıl görüldüğü izlendi. `sound` komutu ve işitme testiyle sinüzoidlerin duyulan karşılığı konuşuldu.

İkinci bölümde ayrık veriye geçildi. DFT ve onun hızlı hali FFT tanıtıldı, `fft` ve `fftshift` ile spektrum çizildi. Periyodik ayrık işaretler için ayrık Fourier serisi, periyodik olmayanlar için ayrık zamanlı Fourier dönüşümü ve ters dönüşümü verildi. $x[n]=[0,1,2,3]$, $\delta[n]$ ve $a^n u[n]$ örnekleri çözüldü, özellikler sürekli zamanla karşılaştırıldı. Sonraki derslerde örneklerle birlikte, sonsuza giden işaretleri de ele alabilen Laplace ve Z dönüşümlerine geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
