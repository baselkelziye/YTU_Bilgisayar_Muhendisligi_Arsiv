# Ders 5 Genişletilmiş Notu: Taylor ve Maclaurin Serileri, Taylor Polinomu ve Seri Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Taylor Serisinin Fikri: Fonksiyonu Kuvvet Serisiyle Yazmak
- 2. Taylor Serisinin Tanımı
- 3. İlk Örnek: $e^x$'in Sıfır Noktasındaki Açılımı
- 4. Maclaurin Serisi
- 5. Taylor Polinomu
- 6. $\cos x$ ve $\sin x$'in Maclaurin Serileri
- 7. $\dfrac1x$'in $a=2$'deki Taylor Serisi ve Yakınsaklık Aralığı
- 8. Taylor Polinomuyla Yaklaşık Değer: $\sqrt[3]{1{,}2}$
- 9. Sık Kullanılan Maclaurin Açılımları
- 10. Açılımlardan Yeni Açılım Üretmek
- 11. Uygulamalar: Kapalı Biçimde Alınamayan İntegraller ve Belirsiz Limitler
- 12. $\ln x$'in $x-3$'ün Kuvvetlerine Göre Açılımı
- 13. Soru Çözümü: Seriler ve Kuvvet Serileri
- Örnek Sorular
- Dersin Toparlaması

## 1. Taylor Serisinin Fikri: Fonksiyonu Kuvvet Serisiyle Yazmak

Hoca derse, öğrencilerin önceki derslerle ilgili sorusu olup olmadığını sorarak başladı. Konu üzerine çalışan birinin "hocam şu konuyla ilgili bir soru çözebilir miyiz" diyebilmesi gerektiğini, soru gelmiyorsa çalışmaya henüz başlanmadığını düşündüğünü söyledi. Ardından yeni konuya geçti: Taylor ve Maclaurin serileri (Taylor series, Maclaurin series).

Çıkış noktası, önceki derste görülen kuvvet serileriyle ilgili bir sonuçtur. Bir kuvvet serisinin toplamı, yakınsaklık aralığının içinde, her mertebeden türevi olan sürekli bir fonksiyondur. Hoca bunun tersini sordu:

- Bir $f(x)$ fonksiyonunun bir $I$ aralığında her mertebeden türevi varsa, $f$'yi o aralıkta bir kuvvet serisiyle ifade edebilir miyiz?
- İfade edebilirsek, bu kuvvet serisinin katsayıları için ne söylenebilir?

$f$'nin pozitif yakınsaklık yarıçaplı bir kuvvet serisiyle yazılabildiğini varsayalım:

$$f(x)=\sum_{n=0}^{\infty}a_n(x-a)^n=a_0+a_1(x-a)+a_2(x-a)^2+a_3(x-a)^3+\cdots$$

Yakınsaklık aralığının içinde seri terim terim türevlenebilir. Her türevden sonra $x=a$ konursa, $(x-a)$ çarpanı içeren bütün terimler sıfır olur ve yalnız bir terim kalır:

- $f(a)=a_0$
- $f'(a)=a_1$
- $f''(a)=2\,a_2$, yani $a_2=\dfrac{f''(a)}{2!}$
- $f'''(a)=3!\,a_3$, yani $a_3=\dfrac{f'''(a)}{3!}$
- Genel olarak $a_n=\dfrac{f^{(n)}(a)}{n!}$

Hoca burada bir gösterim uyarısı yaptı: $f^{(n)}$ bir kuvvet değildir, $f$'nin $n$'inci türevidir.

## 2. Taylor Serisinin Tanımı

Katsayılar yerine yazılınca seri Taylor serisi adını alır.

**Tanım (Taylor serisi)**

- $f$, $a$ noktasını içeren bir aralıkta her mertebeden türevlenebilir bir fonksiyon olsun.
- $f$ tarafından $x=a$'da üretilen Taylor serisi şudur:

$$\sum_{n=0}^{\infty}\frac{f^{(n)}(a)}{n!}(x-a)^n=f(a)+\frac{f'(a)}{1!}(x-a)+\frac{f''(a)}{2!}(x-a)^2+\cdots+\frac{f^{(n)}(a)}{n!}(x-a)^n+\cdots$$

Hoca seriyi tahtaya bir kez daha, açılım noktasını $x_0$ ile göstererek yazdı: $f(x_0)+\dfrac{f'(x_0)}{1!}(x-x_0)+\dfrac{f''(x_0)}{2!}(x-x_0)^2+\cdots$. Böylece "kalıcı olarak hafızaya geçmesini" istedi.

Taylor serisinin açılabilmesi için fonksiyonun $x_0$ noktasının bir komşuluğunda her mertebeden türevlenebilir olması gerekir. Hoca bunu şöyle açıkladı: Toplam $n=0$'dan sonsuza kadar gider. Bu yüzden birinci türev, ikinci türev ve sonraki bütün türevler var olmalıdır. Fonksiyon sonsuz kez türevlenebiliyorsa Taylor serisi bu şekilde açılır.

Hoca fikri şöyle özetledi: Bazen fonksiyonun kendisi yerine, ona yaklaşan bir seri kullanılır. Taylor serisi bir fonksiyona türevleri yardımıyla yaklaşmaktır. Bu, işi kolaylaştırır ve uygulamada, özellikle mühendislik problemlerinde çok değerlidir.

> **Ek bilgi (derste anlatılmadı):** Her mertebeden türevlenebilir olmak, Taylor serisinin fonksiyona eşit olmasını tek başına garanti etmez. Eşitlik için $f(x)$ ile $n$'inci Taylor polinomu arasındaki farkın (kalan terimin) $n\to\infty$ iken sıfıra gitmesi gerekir. Derste görülen $e^x$, $\sin x$, $\cos x$ gibi fonksiyonlarda bu koşul sağlanır. Bu yüzden seri, yakınsaklık aralığında fonksiyonun kendisine eşittir.

## 3. İlk Örnek: $e^x$'in Sıfır Noktasındaki Açılımı

**Örnek 1.** $f(x)=e^x$ fonksiyonunun $x=0$ noktasındaki Taylor serisini açınız.

Formülde $a=0$ alınır:

$$f(x)=f(0)+\frac{f'(0)}{1!}x+\frac{f''(0)}{2!}x^2+\frac{f'''(0)}{3!}x^3+\cdots$$

Hoca öğrencilere $e^x$'in türevini sordu. Cevap: $e^x$'in türevi yine $e^x$'tir. Bu yüzden bütün türevler aynıdır:

- $f(x)=e^x$, $f(0)=e^0=1$
- $f'(x)=e^x$, $f'(0)=1$
- $f^{(n)}(x)=e^x$, $f^{(n)}(0)=1$ (her $n$ için)

Değerler yerine yazılır:

$$e^x=1+x+\frac{x^2}{2!}+\frac{x^3}{3!}+\cdots$$

Hoca toplam sembolüyle yazarken önce $\sum_{n=1}^{\infty}\dfrac{x^n}{n!}$ yazdı, sonra öğrencilere bunun doğru olup olmadığını sordu. $n=1$ konursa ilk terim $x$ olur. Oysa açılım $1$ ile başlıyor. $n=0$ konursa $x^0=1$ elde edilir. Bu yüzden toplam sıfırdan başlamalıdır:

$$e^x=\sum_{n=0}^{\infty}\frac{x^n}{n!}$$

## 4. Maclaurin Serisi

Hoca Taylor ile Maclaurin serisi arasındaki farkı sordu ve cevapladı: Taylor serisinde açılım noktası özel olarak $0$ alınırsa seriye Maclaurin serisi denir. Maclaurin serisi, Taylor serisinin özel bir durumudur.

**Tanım (Maclaurin serisi)**

- $f$ tarafından üretilen Maclaurin serisi, $f$'nin $x=0$'daki Taylor serisidir:

$$\sum_{n=0}^{\infty}\frac{f^{(n)}(0)}{n!}x^n=f(0)+f'(0)\,x+\frac{f''(0)}{2!}x^2+\cdots$$

- Taylor serisindeki $(x-a)$ yerine artık yalnız $x$ vardır.

> **Hocanın vurgusu:** Soruda "Maclaurin serisini açınız" denirse, açılım noktasının $x_0=0$ olduğunu kendiniz bileceksiniz.

Buna göre Örnek 1'deki $e^x$ açılımı aynı zamanda $e^x$'in Maclaurin serisidir.

## 5. Taylor Polinomu

Taylor polinomu (Taylor polynomial), Taylor serisinin sonlu bir yerde kesilmiş hâlidir. Seri sonsuza kadar devam eder. Polinomda ise toplam $n$'e kadar alınır, yani serinin kısmi toplamı alınır.

**Tanım ($n$'inci mertebe Taylor polinomu)**

- $f$'nin $x=a$'daki $n$'inci mertebe Taylor polinomu:

$$P_n(x)=\sum_{k=0}^{n}\frac{f^{(k)}(a)}{k!}(x-a)^k=f(a)+f'(a)(x-a)+\cdots+\frac{f^{(n)}(a)}{n!}(x-a)^n$$

- Seri olsaydı, sonraki terim $\dfrac{f^{(n+1)}(a)}{(n+1)!}(x-a)^{n+1}$ olurdu ve toplam sonsuza kadar sürerdi. Polinomda bu terim ve sonrası alınmaz.
- Yüksek mertebeden Taylor polinomları, $f$'ye $x=a$ civarında en iyi polinom yaklaşımlarını verir.

Hoca örnek olarak yine $e^x$'i aldı. $e^x$'in $x=0$'daki Taylor polinomu, Örnek 1'deki değerlerle elde edilir: $f(0)=1$, bütün türevlerin sıfırdaki değeri $1$'dir. Buna göre

$$e^x\approx P_n(x)=1+x+\frac{x^2}{2!}+\cdots+\frac{x^n}{n!}=\sum_{k=0}^{n}\frac{x^k}{k!}$$

Bu yaklaşım her $x$ için geçerlidir.

## 6. $\cos x$ ve $\sin x$'in Maclaurin Serileri

**Örnek 2.** $f(x)=\cos x$ fonksiyonunun $x=0$'daki Taylor serisini (ve polinomunu) bulunuz.

Formül yine $f(0)+\dfrac{f'(0)}{1!}x+\dfrac{f''(0)}{2!}x^2+\dfrac{f'''(0)}{3!}x^3+\cdots$ şeklindedir. Türevler hesaplanır:

- $f(x)=\cos x$, $f(0)=\cos 0=1$
- $f'(x)=-\sin x$, $f'(0)=0$
- $f''(x)=-\cos x$, $f''(0)=-1$
- $f'''(x)=\sin x$, $f'''(0)=0$
- Türevler dört adımda bir tekrar eder.

Hoca türevleri çift ve tek mertebeler olarak topladı:

- Çift mertebeli türevler: $f^{(2n)}(x)=(-1)^n\cos x$. $x=0$ konunca $f^{(2n)}(0)=(-1)^n$.
- Tek mertebeli türevler: $f^{(2n+1)}(x)=(-1)^{n+1}\sin x$. $x=0$ konunca $\sin 0=0$ olduğundan hepsi sıfırdır.

Hoca bu genellemeleri türevleri tek tek alarak kendi kendinize görebileceğinizi söyledi. Tek mertebeli terimler düştüğü için seride yalnız çift kuvvetler kalır:

$$\cos x=1-\frac{x^2}{2!}+\frac{x^4}{4!}-\cdots=\sum_{n=0}^{\infty}\frac{(-1)^n x^{2n}}{(2n)!}$$

Bu, $\cos x$'in $x=0$'daki Taylor açılımı, yani doğrudan Maclaurin açılımıdır. Aynı yolla $\sin x$ için

$$\sin x=x-\frac{x^3}{3!}+\frac{x^5}{5!}-\cdots=\sum_{n=0}^{\infty}\frac{(-1)^n x^{2n+1}}{(2n+1)!}$$

bulunur.

> **Ders sonrası not:** Hoca açılımları sözlü okurken "$1-\dfrac{x^2}{2}+\dfrac{x^4}{4}$" ve "$x-\dfrac{x^3}{3}+\dfrac{x^5}{5}$" diyor. Paydalar faktöriyeldir: $\cos x$ için $2!,\,4!$, $\sin x$ için $3!,\,5!$. Genel terimlerde hoca faktöriyeli doğru söylüyor.

Hemen ardından hoca, genel terimi $\dfrac{(-1)^n\,2^{2n}}{(2n)!}$ biçiminde olan bir açılımdan bahsetti. <!-- BELİRSİZ: 00:26:15'te "eksi bir üzeri en, çarpı iki üzeri iki en, bölü iki en faktöriyel" deniyor; hangi açılım olduğu altyazıdan anlaşılmıyor. Büyük olasılıkla $\cos 2x=\sum\frac{(-1)^n 2^{2n}x^{2n}}{(2n)!}$. --> Bu açılımları ileride çok kullanacağımızı, hem çıkarılışlarını hem de kendilerini bilmekte fayda olduğunu söyledi.

**Seri ile polinom arasındaki fark.** Hoca $\cos x$ açılımına dönerek şunu vurguladı: Toplam sonsuza kadar alınırsa seri $\cos x$'e eşittir. Toplam $k=0$'dan $n$'e kadar alınırsa artık "eşittir" değil "yaklaşık eşittir" ($\approx$) yazılır. $n\to\infty$ iken bu polinomların limiti $\cos x$'tir. Yani fonksiyonun değerine doğrudan ulaşamadığımızda ona seriyle yaklaşırız.

## 7. $\dfrac1x$'in $a=2$'deki Taylor Serisi ve Yakınsaklık Aralığı

**Örnek 3.** $f(x)=\dfrac1x$ tarafından $a=2$ noktasında üretilen Taylor serisi aşağıdakilerden hangisidir? Seri hangi $x$ değerlerinde $\dfrac1x$'e yakınsar?

Açılım noktası $2$ olduğundan formül şudur:

$$f(x)=f(2)+\frac{f'(2)}{1!}(x-2)+\frac{f''(2)}{2!}(x-2)^2+\cdots$$

Türevler alınıp $x=2$ konur:

- $f(x)=\dfrac1x$, $f(2)=\dfrac12$
- $f'(x)=-\dfrac{1}{x^2}$, $f'(2)=-\dfrac14$
- $f''(x)=\dfrac{2}{x^3}$, $f''(2)=\dfrac{2}{8}$, yani $\dfrac{f''(2)}{2!}=\dfrac18$ (ara adım eklendi)
- Böyle $n$'inci türeve kadar devam edilir.

Değerler yerine yazılınca

$$\frac1x=\frac12-\frac{x-2}{4}+\frac{(x-2)^2}{8}-\cdots=\sum_{n=0}^{\infty}\frac{(-1)^n(x-2)^n}{2^{n+1}}$$

elde edilir. Hoca bunun bir geometrik seri olduğunu belirtti: İlk terim $\dfrac12$, ortak çarpan $-\dfrac{x-2}{2}$'dir. Geometrik seri, ortak çarpanın mutlak değeri $1$'den küçükken yakınsar:

$$\left|\frac{x-2}{2}\right|<1\iff|x-2|<2\iff -2<x-2<2\iff 0<x<4$$

Bu aralıkta seri $\dfrac{1}{1-\left(-\frac{x-2}{2}\right)}\cdot\dfrac12=\dfrac1x$ toplamına yakınsar. Hoca anlaşılmadıysa yeniden çözebileceğini söyledi. Öğrenciler anlaşıldığını söyleyince devam etti.

## 8. Taylor Polinomuyla Yaklaşık Değer: $\sqrt[3]{1{,}2}$

**Örnek 4.** İkinci mertebe Taylor polinomunu kullanarak $\sqrt[3]{1{,}2}$ için yaklaşık değer bulunuz.

Soruda fonksiyon verilmemiştir. Önce fonksiyonu kendimiz seçeriz: $f(x)=\sqrt[3]{x}$. Sonra açılım noktası seçilir. $1{,}2$'ye en yakın ve küp kökü tam çıkan sayı $1$'dir. Bu yüzden $x_0=1$ alınır ve $f$'nin $1$ noktasındaki ikinci mertebe Taylor polinomu yazılır:

$$\sqrt[3]{x}\approx f(1)+\frac{f'(1)}{1!}(x-1)+\frac{f''(1)}{2!}(x-1)^2$$

Burada "eşittir" değil "yaklaşık" yazılır. Çünkü toplam sonsuza kadar değil, yalnız ikinci mertebeye kadar alınmıştır.

1. $f(1)=\sqrt[3]{1}=1$.
2. $f'(x)=\dfrac13x^{-2/3}=\dfrac{1}{3\sqrt[3]{x^2}}$. Hoca türevi bu şekilde, $x^{1/3}$ yazıp türev alarak buldu. $f'(1)=\dfrac13$.
3. $f''(x)=-\dfrac29x^{-5/3}$, $f''(1)=-\dfrac29$. Hoca bu adımda "tekrar türev alınır, değer konur" demekle yetindi. Değer altyazıda geçmiyor (ara adım eklendi).
4. Polinom: $P_2(x)=1+\dfrac{x-1}{3}-\dfrac{1}{9}(x-1)^2$.
5. $x=1{,}2$ konur, $x-1=0{,}2$:

$$\sqrt[3]{1{,}2}\approx1+\frac{0{,}2}{3}-\frac{0{,}04}{9}\approx1+0{,}06667-0{,}00444\approx1{,}0622$$

Hoca sonucu "$1+\dfrac{0{,}2}{3}+\cdots$" diye bıraktı ve yaklaşık değerin bu şekilde bulunduğunu söyledi.

> **Ders sonrası not:** Son terim ve sayısal sonuç altyazıda yok, yukarıda tamamlandı. Hesap makinesi değeri $\sqrt[3]{1{,}2}\approx1{,}06266$'dır. Yalnız ilk iki terim ($1{,}0667$) ile yapılan yaklaşım daha kabadır. İkinci mertebe terim hatayı belirgin biçimde küçültür.

**Soru (hoca sordu):** Sayı $1{,}2$ değil de başka bir sayı olsaydı açılım noktasını ne seçerdik? **Cevap:** Hoca önce $3{,}9$ için $4$ dedi. Sonra küp kökü tam çıkan bir sayının gerektiğini hatırlatıp örneği $7{,}9$ olarak değiştirdi. $7{,}9$ için açılım noktası $8$ seçilir, çünkü $\sqrt[3]{8}=2$ tam çıkar. Taylor serisi $8$ civarında açılır.

> **Ders sonrası not:** $4$ bir küp sayı değildir. $\sqrt[3]{3{,}9}$ için büyük olasılıkla $a=8$ ya da $a=1$ gibi küp kökü bilinen bir nokta seçilmelidir. Hoca bunu kendisi fark edip örneği $7{,}9$'a çevirdi.

Bu kısımdan sonra derse ara verildi.

## 9. Sık Kullanılan Maclaurin Açılımları

Aradan sonra hoca, iletişim ve etkileşimin önemli olduğunu, anlaşılmayan her şeyin rahatça sorulmasını istedi. Hocaya göre sorularla hafızaya yerleşmeyen bilgi kullanılabilir bir bilgi değildir. Ardından sık kullanılan Maclaurin ve Taylor açılımlarına geçti.

> **Hocanın vurgusu:** Bu açılımları evde kendiniz mutlaka tek tek açın. Açılımın neden o seriye eşit olduğunu kendiniz elde edin.

### 9.1 $\dfrac{1}{1-x}$ ve $\dfrac{1}{1+x}$

$f(x)=\dfrac{1}{1-x}$'in $x=0$'daki Taylor serisi örnek olarak alındı. Türevi $f'(x)=\dfrac{1}{(1-x)^2}$'dir, sonraki türevler de benzer biçimdedir. Değerler Taylor formülüne konunca bilinen geometrik seri elde edilir:

$$\frac{1}{1-x}=\sum_{n=0}^{\infty}x^n,\qquad |x|<1$$

> **Hocanın vurgusu:** $\dfrac{1}{1-x}$ açılımını sınavlarda çok kullanacaksınız. Ama yakınsaklık aralığı ondan da önemlidir.

$x$ yerine $-x$ yazılırsa $\dfrac{1}{1+x}=\sum_{n=0}^{\infty}(-1)^nx^n$, $|x|<1$ bulunur.

### 9.2 $e^x$, $\sin x$, $\cos x$

Bu üç açılım derste daha önce çıkarıldı:

- $e^x=\sum_{n=0}^{\infty}\dfrac{x^n}{n!}$
- $\sin x=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+1}}{(2n+1)!}$
- $\cos x=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n}}{(2n)!}=1-\dfrac{x^2}{2!}+\cdots$

Hoca bu açılımların önemli bir özelliğini vurguladı: Üçü de her $x$ için geçerlidir. Yakınsaklık aralığı bütün reel sayılardır.

### 9.3 $\ln(1+x)$

$f(x)=\ln(1+x)$'in sıfır noktasındaki açılımı:

- $f(0)=\ln1=0$
- $f'(x)=\dfrac{1}{1+x}$, $f'(0)=1$
- $f''(x)=-\dfrac{1}{(1+x)^2}$, $f''(0)=-1$, böyle devam eder.

Değerler yerine yazılınca

$$\ln(1+x)=x-\frac{x^2}{2}+\frac{x^3}{3}-\cdots=\sum_{n=1}^{\infty}\frac{(-1)^{n+1}x^n}{n}$$

bulunur. Hoca yakınsaklık aralığının oran testiyle de bulunabileceğini söyledi. Ayrıca aynı açılımın başka bir yolla da elde edilebileceğini gösterdi: $\dfrac{1}{1+x}=\sum(-1)^nx^n$ açılımı terim terim integre edilirse $\ln(1+x)$ açılımı çıkar.

> **Ders sonrası not:** Hoca aralığı "eksi 1, artı 1" diye okuyor. $\ln(1+x)$ serisinin yakınsaklık aralığı $-1<x\le1$'dir. $x=1$'de seri alterne harmonik seri olur ve yakınsar ($\ln2$). $x=-1$'de harmonik serinin negatifi olur ve ıraksar.

### 9.4 $\arctan x$

$\dfrac{1}{1+x}$ açılımında $x$ yerine $x^2$ yazılır:

$$\frac{1}{1+x^2}=\sum_{n=0}^{\infty}(-1)^nx^{2n}=1-x^2+x^4-\cdots,\qquad |x|<1$$

$\arctan x$'in türevi $\dfrac{1}{1+x^2}$ olduğundan, iki taraf $x$'e göre integre edilir:

$$\arctan x=\sum_{n=0}^{\infty}\frac{(-1)^nx^{2n+1}}{2n+1}=x-\frac{x^3}{3}+\frac{x^5}{5}-\cdots$$

Hoca paydayı yazarken önce "$(2n+1)!$" dedi, sonra durup faktöriyel olmadığını, integral alındığı için paydaya yalnız $2n+1$ geldiğini söyleyerek düzeltti.

> **Ders sonrası not:** Hoca aralığı "eksi 1, artı 1 aralığında" diye veriyor. $\arctan x$ serisi iki uçta da alterne seri olarak yakınsar, aralık $-1\le x\le1$'dir.

> **Hocanın vurgusu:** Bu açılımları ezberlemeyin, anlayın. Anlarsanız kalıcı olur.

## 10. Açılımlardan Yeni Açılım Üretmek

### 10.1 $e^{-x^2/3}$

**Örnek 5.** $e^{-x^2/3}$ fonksiyonunun Maclaurin serisi aşağıdakilerden hangisidir?

Hoca önce $e^x$ açılımını hatırlattı: $e^x=\sum_{n=0}^{\infty}\dfrac{x^n}{n!}$. Soruda Maclaurin polinomu istenseydi $e^x\approx\sum_{k=0}^{n}\dfrac{x^k}{k!}$ yazılırdı, bu da her $x$ için geçerlidir.

> **Ders sonrası not:** Hoca polinom toplamının sınırını "birden" diye okuyor. Toplam $k=0$'dan başlamalıdır, çünkü ilk terim $1$'dir (Örnek 1'deki düzeltmeyle aynı).

İstenen fonksiyon için $e^x$ açılımında $x$ gördüğümüz yere $-\dfrac{x^2}{3}$ yazılır ve düzenlenir:

$$e^{-x^2/3}=\sum_{n=0}^{\infty}\frac{1}{n!}\left(-\frac{x^2}{3}\right)^n=\sum_{n=0}^{\infty}\frac{(-1)^nx^{2n}}{3^n\,n!}=1-\frac{x^2}{3}+\frac{x^4}{18}-\cdots$$

Aralık değişmez: seri her $x\in\mathbb{R}$ için geçerlidir. <!-- BELİRSİZ: 01:09:46'da soru "e üzeri eksi x kare bir iki" diye okunuyor; 01:10:51'de "eksi x kare bölü 3" deniyor. Not 01:10:51'e göre yazıldı. -->

### 10.2 $\sin^2x$

**Örnek 6.** $\sin^2x$'in Maclaurin serisi.

Hoca, integral hesaplarında olduğu gibi yarım açı özdeşliğini kullanmayı önerdi:

$$\sin^2x=\frac{1-\cos2x}{2}$$

$\cos2x$'in açılımı, $\cos x$ açılımında $x$ yerine $2x$ yazılarak bilinir. Hoca bundan sonrasını "düzenli bir şekilde yazıyoruz" diyerek geçti. Düzenleme yapılırsa (ara adım eklendi):

$$\cos2x=\sum_{n=0}^{\infty}\frac{(-1)^n2^{2n}x^{2n}}{(2n)!}\ \Rightarrow\ \sin^2x=\sum_{n=1}^{\infty}\frac{(-1)^{n+1}2^{2n-1}x^{2n}}{(2n)!}=x^2-\frac{x^4}{3}+\frac{2x^6}{45}-\cdots$$

### 10.3 $\tan x$

**Örnek 7.** $\sin x$ ve $\cos x$'in seri açılımlarından yararlanarak $\tan x$'in Maclaurin serisinin ilk üç terimini bulunuz.

Hoca, soruda "yararlanarak" denmese de bu yolla yapılabileceğini söyledi. $\tan x=\dfrac{\sin x}{\cos x}$ yazılır. Her iki açılımdan üç terim alınır:

$$\tan x=\frac{x-\dfrac{x^3}{3!}+\dfrac{x^5}{5!}-\cdots}{1-\dfrac{x^2}{2!}+\dfrac{x^4}{4!}-\cdots}$$

Sonra pay paydaya, polinom bölmesi gibi bölünür:

1. Paydadaki $1$'i payın ilk terimi $x$ yapmak için $x$ ile çarparız. Bölüme $x$ yazılır, çarpım paydan çıkarılır.
2. Kalan ifadenin ilk terimi $\dfrac{x^3}{3}$'tür (ara adım eklendi). Bölüme $\dfrac{x^3}{3}$ yazılır.
3. Aynı işlem bir kez daha yapılınca $\dfrac{2x^5}{15}$ bulunur.

$$\tan x=x+\frac{x^3}{3}+\frac{2x^5}{15}+\cdots$$

## 11. Uygulamalar: Kapalı Biçimde Alınamayan İntegraller ve Belirsiz Limitler

Hoca serilerin neden bu kadar işe yaradığını iki uygulamayla gösterdi: integral ve limit.

### 11.1 $\int_0^x e^{-t^2}\,dt$

**Örnek 8.** $\displaystyle\int_0^x e^{-t^2}\,dt$ integralini seri olarak ifade ediniz.

Hoca bu integralin bilinen yöntemlerle alınamadığını, reel sayılarda kapalı bir karşılığı olmadığını söyledi. Böyle integraller gama ve beta fonksiyonlarıyla ya da seri açılımı yöntemiyle hesaplanır. Seri yönteminde $e^x$ açılımında $x$ yerine $-t^2$ yazılır:

$$e^{-t^2}=\sum_{n=0}^{\infty}\frac{(-1)^nt^{2n}}{n!}=1-t^2+\frac{t^4}{2!}-\cdots$$

Sonra $0$'dan $x$'e kadar terim terim integre edilir, üst sınır ve alt sınır konur:

$$\int_0^x e^{-t^2}\,dt=\sum_{n=0}^{\infty}\frac{(-1)^nx^{2n+1}}{(2n+1)\,n!}=x-\frac{x^3}{3}+\frac{x^5}{10}-\cdots$$

Çıkan seri integralin sonucunu verir. Yani reel sayılarda kapalı biçimde sonucunu alamadığımız bir integrali seriler yardımıyla hesaplayabiliyoruz.

> **Ek bilgi (derste anlatılmadı):** Bu integral istatistikte ve mühendislikte sık geçer. Normalleştirilmiş hâline hata fonksiyonu denir: $\operatorname{erf}(x)=\dfrac{2}{\sqrt\pi}\int_0^x e^{-t^2}dt$. Hesap makineleri ve yazılımlar bu değeri büyük olasılıkla seri açılımına benzer yaklaşımlarla hesaplar.

### 11.2 $\lim_{x\to0}\dfrac{x-\sin x}{x^3}$

Limitlerdeki belirsizlikler türev yoluyla (L'Hospital) giderilebilir. Hoca bunun bir de seri açılımıyla yapılabileceğini gösterdi.

**Örnek 9.** $\displaystyle\lim_{x\to0}\frac{x-\sin x}{x^3}$ limitini bulunuz.

$x=0$ konunca $\dfrac00$ belirsizliği çıkar. $x$'in açılımı yapılmaz, ama $\sin x$ Maclaurin serisine açılır:

$$x-\sin x=x-\left(x-\frac{x^3}{3!}+\frac{x^5}{5!}-\cdots\right)=\frac{x^3}{3!}-\frac{x^5}{5!}+\cdots$$

Paydaki $x$'ler birbirini götürür. Kalan ifade $x^3$'e bölünür:

$$\frac{x-\sin x}{x^3}=\frac{1}{3!}-\frac{x^2}{5!}+\cdots\ \xrightarrow{x\to0}\ \frac{1}{3!}=\frac16$$

### 11.3 Çarpım ve kuvvet içeren bir limit

**Örnek 10.** $\displaystyle\lim_{x\to0}\frac{(e^{2x}-1)\,\ln(1+x^3)}{(1-\cos3x)^2}$ limitini bulunuz.

<!-- BELİRSİZ: Soru ekranda gösterildi, altyazıda ifadenin tamamı okunmuyor. İfade aynı dersin kısa notundan (kareden doğrulanmış) alındı; altyazıdaki adımlarla ($e^{2x}$, $\ln(1+x^3)$, $\cos$ terimi, sonuç "8/81") uyumlu. -->

$x\to0$ iken $e^0=1$ olduğundan pay ve payda sıfıra gider, $\dfrac00$ belirsizliği vardır. Her çarpan seriye açılır:

- $e^{2x}$: $e^x$ açılımında $x$ yerine $2x$ yazılır. $e^{2x}-1=2x+\dfrac{(2x)^2}{2!}+\cdots$. Baştaki $1$ ile $-1$ birbirini götürür.
- $\ln(1+x^3)$: $\ln(1+x)$ açılımında $x$ yerine $x^3$ yazılır. $\ln(1+x^3)=x^3-\dfrac{x^6}{2}+\cdots$.
- $1-\cos3x$: $\cos x$ açılımında $x$ yerine $3x$ yazılır. $1-\cos3x=\dfrac{9x^2}{2}-\dfrac{3^4x^4}{4!}+\cdots$.

En küçük dereceli terimler alınır:

$$\frac{(2x+\cdots)(x^3+\cdots)}{\left(\frac{9x^2}{2}+\cdots\right)^2}=\frac{2x^4+\cdots}{\frac{81x^4}{4}+\cdots}\ \xrightarrow{x\to0}\ \frac{2}{81/4}=\frac{8}{81}$$

Hoca sonucu "8 bölü 81" olarak verdi. Bu iki örnekle Maclaurin ve Taylor serilerinin integrallerde ve limitlerde ne kadar işe yaradığını göstermiş oldu.

### 11.4 Binom serisi

Hoca bir de binom serisini (binomial series) gösterdi:

$$(1+x)^r=1+rx+\frac{r(r-1)}{2!}x^2+\frac{r(r-1)(r-2)}{3!}x^3+\cdots,\qquad |x|<1$$

Bu seri toplam sembolüyle de yazılabilir. Binom serisi de bir Taylor açılımıdır. Örneğin $\dfrac{1}{1+x}$'in kuvvet serisi binom serisiyle de bulunabilir ($r=-1$).

> **Ek bilgi (derste anlatılmadı):** Toplam sembolüyle yazımda genelleştirilmiş binom katsayısı kullanılır: $(1+x)^r=\sum_{k=0}^{\infty}\binom{r}{k}x^k$, burada $\binom{r}{k}=\dfrac{r(r-1)\cdots(r-k+1)}{k!}$. $r$ pozitif bir tam sayıysa katsayılar bir yerden sonra sıfır olur ve seri bilinen sonlu binom açılımına dönüşür.

### 11.5 $\int_0^1\cos(x^2)\,dx$

**Örnek 11.** $\displaystyle\int_0^1\cos(x^2)\,dx$ integralinin değeri aşağıdaki serilerden hangisidir?

Hoca bu integralin de normal yollarla alınamadığını söyledi. Bazı açılımları pratik olarak bilmek gerekir. $\cos x$ açılımı hatırlanır:

$$\cos x=\sum_{n=0}^{\infty}\frac{(-1)^nx^{2n}}{(2n)!},\qquad x\in\mathbb{R}$$

Hoca bu serinin her $x$ için yakınsak olduğunu, yakınsaklık aralığının da sorulabileceğini hatırlattı. İntegralde $\cos(x^2)$ olduğu için $x$ yerine $x^2$ konur. Üs $2n$'den $4n$'e çıkar:

$$\cos(x^2)=\sum_{n=0}^{\infty}\frac{(-1)^nx^{4n}}{(2n)!}$$

Sonra $0$'dan $1$'e kadar terim terim integre edilir. Hoca öğrencilere sonucu sordu, birlikte şu bulundu:

$$\int\cos(x^2)\,dx=\sum_{n=0}^{\infty}\frac{(-1)^nx^{4n+1}}{(4n+1)(2n)!}$$

Sınırlar konur. $x=1$ için her terimde $1$, $x=0$ için $0$ gelir:

$$\int_0^1\cos(x^2)\,dx=\sum_{n=0}^{\infty}\frac{(-1)^n}{(4n+1)(2n)!}=1-\frac{1}{5\cdot2!}+\frac{1}{9\cdot4!}-\cdots\approx0{,}9045$$

> **Ders sonrası not:** Hoca açılımın ilk terimlerini "$1+\dfrac{1}{5\cdot2!}$, $\dfrac{1}{9\cdot3!}$" diye okuyor. Doğrusu, işaretler $(-1)^n$ nedeniyle değişir ve faktöriyeller $(2n)!$ olduğu için çift sayılardır: $1-\dfrac{1}{5\cdot2!}+\dfrac{1}{9\cdot4!}-\dfrac{1}{13\cdot6!}+\cdots$. Bu toplam sayısal integral değeri $0{,}904524$ ile uyumludur.

## 12. $\ln x$'in $x-3$'ün Kuvvetlerine Göre Açılımı

**Örnek 12.** $f(x)=\ln x$ fonksiyonunu $x-3$'ün kuvvetleri cinsinden seriye açınız. Soruda $\dfrac1x$'in açılımından yararlanılması da isteniyor.

"$x-3$'ün kuvvetleri" denmesi, açılımın $3$ noktasında yapılacağı anlamına gelir. Hoca önce doğrudan Taylor formülüyle çözdü:

$$\ln x=f(3)+\frac{f'(3)}{1!}(x-3)+\frac{f''(3)}{2!}(x-3)^2+\cdots$$

- $f(3)=\ln3$
- $f'(x)=\dfrac1x$, $f'(3)=\dfrac13$
- $f''(x)=-\dfrac{1}{x^2}$, $f''(3)=-\dfrac19$

$$\ln x=\ln3+\frac13(x-3)-\frac{1}{9\cdot2!}(x-3)^2+\cdots$$

Hoca "ister dolaylı yoldan ister doğrudan yapın, bu sonucu elde edersiniz" dedi. Dolaylı yol $\dfrac1x$'in açılımıdır. Bu yol derste ayrıntılı yazılmadı, kısaca şöyledir (ara adım eklendi): $\dfrac1x=\dfrac{1}{3+(x-3)}=\dfrac13\cdot\dfrac{1}{1+\frac{x-3}{3}}=\sum_{n=0}^{\infty}\dfrac{(-1)^n(x-3)^n}{3^{n+1}}$. Bu seri $3$'ten $x$'e integre edilip $\ln3$ eklenirse

$$\ln x=\ln3+\sum_{n=1}^{\infty}\frac{(-1)^{n+1}(x-3)^n}{n\,3^n},\qquad 0<x\le6$$

bulunur. İlk terimleri doğrudan yolla bulunanla aynıdır.

Hoca konuyu şöyle bağladı: Taylor ya da Maclaurin serileri, fonksiyonun doğrudan değerini değil, seriyle yaklaşık değerini bulmada işimizi kolaylaştırır. Mühendislik uygulamalarında bunun birçok örneği vardır. Ardından ikinci araya geçildi.

## 13. Soru Çözümü: Seriler ve Kuvvet Serileri

Aradan sonra hoca, bu dersin ve önceki derslerin konularıyla ilgili soru çözümüne geçti. Soruların bir kısmının daha önceki sınavlarda çıktığını belirtti.

### 13.1 Limit testiyle karakter belirleme

**Örnek 13.** $\displaystyle\sum_{n=1}^{\infty}\sqrt{\frac{4n^2-1}{n^3+1}}$ serisinin karakterini belirleyiniz.

Önce genel terime bakılır. Kök içinde payın derecesi $2$'dir, kökten dışarı $1$ olarak çıkar. Paydanın derecesi $3$'tür, kökten $1{,}5$ olarak çıkar. Paydanın derecesi daha büyük olduğu için $\lim a_n=0$'dır. Genel terim sıfıra gittiğinde test karar vermez. Seri yakınsak da olabilir, ıraksak da.

Paydanın derecesi payınkinden yarım fazla olduğundan hoca limit testini (limit comparison test) önerdi. Genel terim $\dfrac{1}{\sqrt n}$ ile karşılaştırılır:

$$\lim_{n\to\infty}\frac{a_n}{1/\sqrt n}=\lim_{n\to\infty}\sqrt{\frac{(4n^2-1)\,n}{n^3+1}}=\sqrt4=2$$

Limit $2$'dir, sıfırdan ve sonsuzdan farklıdır. Bu durumda iki serinin karakteri aynıdır. $\sum\dfrac{1}{n^{1/2}}$ bir $p$-serisidir, $p=\dfrac12\le1$ olduğundan ıraksaktır. Limit testine göre verilen seri de ıraksaktır.

### 13.2 Teleskopik seri

**Örnek 14.** $\displaystyle\sum_{n=1}^{\infty}\frac{4}{(4n-2)(4n+2)}$ serisinin toplamı aşağıdakilerden hangisidir?

Hoca, toplamın teleskopik seri gibi iki terimin farkına ayrılarak bulunacağını söyledi. Kısmi kesirlere ayrılır:

$$\frac{4}{(4n-2)(4n+2)}=\frac{A}{4n-2}+\frac{B}{4n+2}$$

$A$ ve $B$ bulununca $A=1$, $B=-1$ çıkar (ara adım eklendi: $4=A(4n+2)+B(4n-2)$, $n$'li terimler $A+B=0$, sabitler $2A-2B=4$):

$$\sum_{n=1}^{\infty}\left(\frac{1}{4n-2}-\frac{1}{4n+2}\right)$$

Hoca bu satırı yazarken bir an "$4n+2$, pardon $4n-2$" diye kendini düzeltti. Kısmi toplam terim terim yazılır:

$$S_n=\left(\frac12-\frac16\right)+\left(\frac16-\frac1{10}\right)+\cdots+\left(\frac{1}{4n-2}-\frac{1}{4n+2}\right)=\frac12-\frac{1}{4n+2}$$

$n\to\infty$ iken $\dfrac{1}{4n+2}\to0$'dır. Serinin toplamı kısmi toplamlar dizisinin limitidir:

$$\sum_{n=1}^{\infty}\frac{4}{(4n-2)(4n+2)}=\lim_{n\to\infty}S_n=\frac12$$

### 13.3 Faktöriyelli seri ve oran testi

**Örnek 15.** $\displaystyle\sum\frac{n!}{n^{n+1}}$ serisinin yakınsak mı ıraksak mı olduğunu söyleyiniz.

> **Hocanın vurgusu:** Faktöriyel gördüğünüz zaman hemen oran testi aklınıza gelsin.

Oran testi: $\lim\dfrac{a_{n+1}}{a_n}<1$ ise seri yakınsaktır.

$$\frac{a_{n+1}}{a_n}=\frac{(n+1)!}{(n+1)^{n+2}}\cdot\frac{n^{n+1}}{n!}=\frac{(n+1)\,n^{n+1}}{(n+1)^{n+2}}=\left(\frac{n}{n+1}\right)^{n+1}$$

Ara sadeleştirme altyazıda geçmiyor, burada eklendi. Limit:

$$\lim_{n\to\infty}\left(\frac{n}{n+1}\right)^{n+1}=\frac1e$$

$e\approx2{,}7$ olduğundan $\dfrac1e<1$'dir. Seri yakınsaktır.

### 13.4 $\ln(1+x^2)$'nin açılımı ve $\ln2$

**Örnek 16.** $\ln(1+x^2)$'nin seri açılımını bulunuz ve bundan yararlanarak $\ln2$'yi bir seri olarak yazınız.

Hoca yolu öğrencilere sordu ve önceki adımları hatırlattı. $\dfrac{1}{1+x}$ açılımında $x$ yerine $x^2$ yazılır:

$$\frac{1}{1+x^2}=\sum_{n=0}^{\infty}(-1)^nx^{2n},\qquad |x|<1$$

**Soru (hoca sordu):** Bu seriyi doğrudan integre edersek $\ln(1+x^2)$ elde edilir mi? **Cevap:** Hayır. $\dfrac{1}{1+x^2}$'nin integrali $\arctan x$'tir. $\ln(1+x^2)$'nin türevi ise $\dfrac{2x}{1+x^2}$'dir. İntegral ile $\ln$ elde etmek için payda paydanın türevi, yani $2x$ bulunmalıdır. Payda $x$ olsaydı integral doğrudan alınırdı. Burada $x^2$ olduğu için pay $2x$ olmalıdır.

Bu yüzden iki taraf $2x$ ile çarpılır:

$$\frac{2x}{1+x^2}=\sum_{n=0}^{\infty}(-1)^n\,2\,x^{2n+1}$$

Sonra iki taraf $x$'e göre integre edilir:

$$\ln(1+x^2)=\sum_{n=0}^{\infty}\frac{(-1)^n\,2\,x^{2n+2}}{2n+2}=\sum_{n=0}^{\infty}\frac{(-1)^nx^{2n+2}}{n+1}=x^2-\frac{x^4}{2}+\frac{x^6}{3}-\cdots$$

Hoca bu satırı yazarken paydada $2n+1$, $2n+2$ ve "$(2n+2)!$" arasında bir süre gidip geldi.

> **Ders sonrası not:** İntegralde faktöriyel oluşmaz. $x^{2n+1}$'in integrali $\dfrac{x^{2n+2}}{2n+2}$'dir. Paydaki $2$ ile sadeleşince payda $n+1$ kalır. Doğru sonuç yukarıdaki gibidir.

Hoca açılımın $-1$ ile $1$ aralığında geçerli olduğunu söyledi. $\ln2$ için $1+x^2=2$, yani $x=1$ konur:

$$\ln2=\sum_{n=0}^{\infty}\frac{(-1)^n}{n+1}=1-\frac12+\frac13-\cdots$$

Hoca soruların şu biçimlerde gelebileceğini söyledi: "$\ln(1+x^2)$'nin seri açılımı aşağıdakilerden hangisidir?" ya da "$\ln2$ aşağıdaki serilerden hangisine eşittir?"

> **Ek bilgi (derste anlatılmadı):** $x=1$ uç noktasıdır. Seri burada alterne seri olarak yakınsar. Uç noktada toplamın fonksiyon değerine eşit olduğu Abel teoremiyle güvenceye alınır. Yani $x=1$ konması yalnız $|x|<1$ için yazılan açılımın kendiliğinden bir sonucu değildir, ama bu durumda sonuç doğrudur.

Hoca daha basit bir durumu da karşılaştırma için gösterdi: $\ln(1-x)$. $\dfrac{1}{1-x}=\sum_{n=0}^{\infty}x^n$, $|x|<1$ açılımı integre edilir. $\ln(1-x)$'in türevi $-\dfrac{1}{1-x}$ olduğu için başa bir eksi gelir:

$$-\ln(1-x)=\sum_{n=0}^{\infty}\frac{x^{n+1}}{n+1}$$

$\ln(1+x^2)$'de ise kare geldiği için türevin, yani $2x$'in ortaya çıkması gerekir. Bu yüzden iki taraf $2x$ ile çarpılır.

### 13.5 $\dfrac{1}{3+2x}$'in açılımı

**Örnek 17.** $\dfrac{1}{3+2x}$'in seri açılımı ve yakınsaklık aralığı aşağıdakilerden hangisidir?

Bildiğimiz açılım $\dfrac{1}{1+x}=\sum_{n=0}^{\infty}(-1)^nx^n$'dir. Burada paydada $1$ değil $3$ var. Hoca öğrencilerden yol göstermelerini istedi: $\dfrac13$ parantezine alınır.

$$\frac{1}{3+2x}=\frac13\cdot\frac{1}{1+\frac{2x}{3}}=\frac13\sum_{n=0}^{\infty}(-1)^n\left(\frac{2x}{3}\right)^n$$

$x$'in yerine $\dfrac{2x}{3}$ geldi. Yakınsaklık koşulu:

$$\left|\frac{2x}{3}\right|<1\iff -\frac32<x<\frac32$$

Hoca, şıklarda hem serinin hem aralığın doğru olanını ayırt etmek gerektiğini söyledi.

### 13.6 $\dfrac{1}{(2+x)^2}$'nin açılımı

**Örnek 18.** $\dfrac{1}{(2+x)^2}$'nin seri açılımı aşağıdakilerden hangisidir?

Hoca öğrencilere bir süre düşünme fırsatı verdi ve "ne kadar soru çözerseniz karşılaştığınızda yapma olasılığınız o kadar artar" dedi. Önce $\dfrac{1}{2+x}$ açılımı yazılır (ara adım eklendi: $\dfrac{1}{2+x}=\dfrac12\cdot\dfrac{1}{1+\frac x2}$):

$$\frac{1}{2+x}=\sum_{n=0}^{\infty}\frac{(-1)^nx^n}{2^{n+1}},\qquad |x|<2$$

<!-- BELİRSİZ: 02:13:41'de paydadaki kuvvet "A artı bir üzeri N" diye okunuyor; büyük olasılıkla $2^{n+1}$. -->

Sonra iki tarafın türevi alınır. Sol tarafta bölümün türevi kuralı uygulanır, sağ tarafta terim terim türev alınır:

$$-\frac{1}{(2+x)^2}=\sum_{n=1}^{\infty}\frac{(-1)^n\,n\,x^{n-1}}{2^{n+1}}$$

Eksi diğer tarafa geçirilir. Hoca, indisi kaydırarak toplamı yeniden $n=0$'dan başlattı (kaydırmada $n$ yerine $n+1$ gelir):

$$\frac{1}{(2+x)^2}=\sum_{n=0}^{\infty}\frac{(-1)^n(n+1)\,x^n}{2^{n+2}}=\frac14-\frac x4+\frac{3x^2}{16}-\cdots$$

Hoca, küçük manipülasyonlarla sonuca rahatça ulaşılan bu tür soruların sınavlarda olacağını söyledi.

### 13.7 Kök testi

**Örnek 19.** Genel terimi $n$'inci kuvvet olan ve içinde $\sin(e^{-n})$ bulunan serinin karakteri.

<!-- BELİRSİZ: Soru 02:16:20'de "1-l, 1-l çarpı sinüs, l üzeri eksi m, üzeri m" diye okunuyor. Çözüm adımlarına göre seri büyük olasılıkla $\sum_{n=0}^{\infty}\left(n\sin(e^{-n})\right)^n$; serinin tam ifadesi altyazıdan kesinleşmiyor. -->

Genel terim $n$'inci kuvvet olduğu için kök testi (root test) uygulanır. $n$'inci kök, kuvveti götürür:

$$\lim_{n\to\infty}\sqrt[n]{a_n}=\lim_{n\to\infty}n\sin(e^{-n})$$

Hoca ifadeyi $e^{-n}$ ile bölüp çarparak düzenledi:

$$n\sin(e^{-n})=n\,e^{-n}\cdot\frac{\sin(e^{-n})}{e^{-n}}$$

$n\to\infty$ iken $e^{-n}\to0$ olduğundan $\dfrac{\sin(e^{-n})}{e^{-n}}\to1$'dir. Geriye kalan kısım:

$$\lim_{n\to\infty}\frac{n}{e^n}=0$$

Hoca bunu "$e^n$ daha kuvvetli olduğu için" sıfıra gider diye açıkladı. Limit $0<1$ olduğundan kök testine göre seri yakınsaktır.

### 13.8 Kuvvet serisinin yakınsaklık aralığı

**Örnek 20.** $\displaystyle\sum_{n=0}^{\infty}\frac{(2x+5)^n}{(n^2+1)\,3^n}$ serisinin yakınsaklık aralığını, merkezini ve yarıçapını bulunuz.

Hoca bunun "çok orijinal" bir soru olduğunu söyledi. Genel terim bir bütün olarak $u_n$ diye düşünülür ve oran testi uygulanır:

$$\lim_{n\to\infty}\left|\frac{u_{n+1}}{u_n}\right|=\lim_{n\to\infty}\left|\frac{2x+5}{3}\right|\cdot\frac{n^2+1}{(n+1)^2+1}=\left|\frac{2x+5}{3}\right|$$

Bu bir kuvvet serisidir. Hangi $x$'ler için yakınsak olduğunu bulmak için limit $1$'den küçük olmalıdır:

$$\left|\frac{2x+5}{3}\right|<1\iff -3<2x+5<3\iff -8<2x<-2\iff -4<x<-1$$

Ardından uç noktalar ayrı ayrı denenir:

- **$x=-4$:** $2x+5=-3$ olur. $3^n$'ler sadeleşir: $\sum\dfrac{(-1)^n}{n^2+1}$. Hoca bunu alterne seri olarak yakınsak buldu. $x=-4$ aralığa dahildir.
- **$x=-1$:** $2x+5=3$ olur, yine $3^n$'ler sadeleşir: $\sum\dfrac{1}{n^2+1}$. Hoca öğrencilere bu serinin yakınsak olup olmadığını sordu. $\dfrac{1}{n^2}$ ile limit testi uygulanır, limit $1$'dir, sıfırdan ve sonsuzdan farklıdır. $\sum\dfrac{1}{n^2}$ bir $p$-serisidir, $p=2>1$ olduğundan yakınsaktır. Dolayısıyla $\sum\dfrac{1}{n^2+1}$ de yakınsaktır. $x=-1$ de aralığa dahildir.

Sonuç: yakınsaklık aralığı $[-4,-1]$'dir. Merkez ve yarıçap altyazıda açıkça söylenmiyor. Aralıktan doğrudan okunur: merkez $-\dfrac52$, yarıçap $\dfrac32$.

> **Ders sonrası not:** $x=-4$'teki seri yalnız alterne seri testiyle yakınsak değildir, mutlak yakınsaktır. Çünkü mutlak değerlerin serisi $\sum\dfrac{1}{n^2+1}$, $x=-1$'de gösterildiği gibi yakınsar.

Hoca bu soruların bir örgü gibi aşama aşama ilerlediğini söyledi: önce kitaplardaki basit seriler, sonra bu tür sorular.

## Örnek Sorular

Bu derste kare ya da video kullanılmadı. Aşağıdaki sorular hocanın derste tahtaya yazdığı ya da sözlü sorduğu sorulardır. Ayrıntılı çözümler ilgili bölümlerdedir.

**Soru 1** (derste sözlü, 00:40:03). $\sqrt[3]{1{,}2}$ yerine $\sqrt[3]{7{,}9}$ istenseydi Taylor açılımı hangi noktada yapılırdı?

> **Çözüm:** Küp kökü tam çıkan en yakın nokta $a=8$ seçilir ($\sqrt[3]{8}=2$). Hoca önce $3{,}9$ ve $4$ dedi, sonra örneği $7{,}9$ ve $8$ olarak düzeltti (Bölüm 8).

**Soru 2** (derste sözlü, 01:50:34; hoca sınavda çıktığını söyledi). $\displaystyle\sum_{n=1}^{\infty}\sqrt{\frac{4n^2-1}{n^3+1}}$ serisinin karakterini belirleyiniz.

> **Çözüm:** $\dfrac1{\sqrt n}$ ile limit testi, limit $2$. $\sum\dfrac1{\sqrt n}$ ıraksak olduğundan seri ıraksaktır (Bölüm 13.1).

**Soru 3** (derste sözlü, 01:53:57; sınav sorusu). $\displaystyle\sum_{n=1}^{\infty}\frac{4}{(4n-2)(4n+2)}$ serisinin toplamı nedir?

> **Çözüm:** $\dfrac{1}{4n-2}-\dfrac{1}{4n+2}$ teleskopik farkı, $S_n=\dfrac12-\dfrac{1}{4n+2}\to\dfrac12$ (Bölüm 13.2).

**Soru 4** (derste sözlü, 01:56:53; sınav sorusu). $\displaystyle\sum\frac{n!}{n^{n+1}}$ yakınsak mı ıraksak mı?

> **Çözüm:** Oran testi, $\left(\dfrac{n}{n+1}\right)^{n+1}\to\dfrac1e<1$. Yakınsak (Bölüm 13.3).

**Soru 5** (derste sözlü, 02:00:01). $\ln(1+x^2)$'nin seri açılımını bulunuz ve $\ln2$'yi seri olarak yazınız. Ara soru (02:01:28): $\dfrac{1}{1+x^2}$ açılımını doğrudan integre etmek $\ln(1+x^2)$'yi verir mi?

> **Çözüm:** Vermez, $\arctan x$'i verir. İki taraf $2x$ ile çarpılıp integre edilir: $\ln(1+x^2)=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+2}}{n+1}$. $x=1$ için $\ln2=\sum_{n=0}^{\infty}\dfrac{(-1)^n}{n+1}$ (Bölüm 13.4).

**Soru 6** (derste sözlü, 02:09:04). $\dfrac{1}{3+2x}$'in seri açılımı ve yakınsaklık aralığı nedir?

> **Çözüm:** $\dfrac13\sum_{n=0}^{\infty}(-1)^n\left(\dfrac{2x}{3}\right)^n$, $-\dfrac32<x<\dfrac32$ (Bölüm 13.5).

**Soru 7** (derste sözlü, 02:11:52). $\dfrac{1}{(2+x)^2}$'nin seri açılımı nedir?

> **Çözüm:** $\dfrac{1}{2+x}$ açılımının türevi alınır: $\dfrac{1}{(2+x)^2}=\sum_{n=0}^{\infty}\dfrac{(-1)^n(n+1)x^n}{2^{n+2}}$, $|x|<2$ (Bölüm 13.6).

**Soru 8** (derste sözlü, 02:16:14). İçinde $\sin(e^{-n})$ bulunan, genel terimi $n$'inci kuvvet olan serinin karakteri. <!-- BELİRSİZ: serinin tam ifadesi altyazıdan çıkmıyor; büyük olasılıkla $\sum(n\sin(e^{-n}))^n$. -->

> **Çözüm:** Kök testi: $\lim n\sin(e^{-n})=\lim\dfrac{n}{e^n}=0<1$. Yakınsak (Bölüm 13.7).

**Soru 9** (derste sözlü, 02:19:35). $\displaystyle\sum_{n=0}^{\infty}\frac{(2x+5)^n}{(n^2+1)\,3^n}$ serisinin yakınsaklık aralığı, merkezi ve yarıçapı nedir?

> **Çözüm:** Oran testiyle $-4<x<-1$. İki uçta da seri yakınsak, aralık $[-4,-1]$. Merkez ve yarıçap derste açıkça söylenmedi: merkez $-\dfrac52$, yarıçap $\dfrac32$ (Bölüm 13.8).

## Dersin Toparlaması

Bu derste, her mertebeden türevlenebilen bir fonksiyonun bir kuvvet serisiyle nasıl yazılabileceği görüldü. Katsayıların $a_n=\dfrac{f^{(n)}(a)}{n!}$ olduğu terim terim türev alınarak çıkarıldı ve Taylor serisi tanımlandı. Açılım noktası $0$ olan özel durum Maclaurin serisi, serinin sonlu bir yerde kesilmiş hâli ise Taylor polinomu adını aldı. $e^x$, $\cos x$, $\sin x$, $\dfrac1x$ ($a=2$) ve $\sqrt[3]{x}$ ($a=1$) üzerinde açılımlar ve yaklaşık değer hesabı yapıldı. Sonra sık kullanılan açılımlar ($\dfrac{1}{1\pm x}$, $\ln(1+x)$, $\arctan x$, binom serisi) ve bunlardan değişken değiştirme, türev, integral ve bölme ile yeni açılım üretme gösterildi. Serilerin iki önemli uygulaması işlendi: kapalı biçimde alınamayan integraller ($\int e^{-t^2}dt$, $\int_0^1\cos x^2\,dx$) ve $\dfrac00$ belirsizliğindeki limitler.

Dersin son bölümünde limit testi, teleskopik seri, oran testi, kök testi ve kuvvet serisinin yakınsaklık aralığı üzerine sınav tipi sorular çözüldü. Hoca her açılımda yakınsaklık aralığının da en az açılım kadar önemli olduğunu vurguladı. Bir sonraki derste (ertesi gün) Taylor ve Maclaurin serileriyle ilgili soru çözümüne devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
