# Ders 20 Genişletilmiş Notu: Kısmi İntegrasyon Uygulamaları, Tablo Yöntemi ve Trigonometrik İntegraller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kısmi İntegrasyon ve LAPTE Sıralaması
- 2. Polinom ile Trigonometrik Çarpımı: $\int x^2\cos x\,dx$
- 3. Tablo Yöntemi: Kısmi İntegrasyonun Kısaltılmış Hâli
- 4. Önce Değişken Dönüşümü, Sonra Tablo
- 5. Döngüsel Durum: $\int e^x\sin x\,dx$ ve $\int e^{3t}\cos 2t\,dt$
- 6. Ters Trigonometrik Fonksiyonların İntegralleri
- 7. Trigonometrik Fonksiyonların İntegralleri: Temel Özdeşlikler
- 8. Sinüs ve Kosinüsün Kuvvetleri
- 9. Çarpımı Toplama Çevirme
- 10. Tanjantın Kuvvetleri ve Gelecek Haftanın Konusu
- Örnek Sorular
- Dersin Toparlaması

## 1. Kısmi İntegrasyon ve LAPTE Sıralaması

Hoca, bir gün önce kısmi integrasyona (partial integration, integration by parts) giriş yaptıklarını hatırlattı. Bu derste bu yöntemle ilgili sorular çözüldü. Dersin ikinci yarısında yeni bir konuya, trigonometrik fonksiyonların integrallerine geçildi.

Kısmi integrasyon formülü, türevin çarpım kuralından gelir. Hoca bunu "5 saniyede bulabiliyorduk" diye hatırlattı:

$$\int u\,dv = uv - \int v\,du.$$

Formülü uygulamak için integrandı (integrand function) $u$ ve $dv$ diye iki parçaya ayırmak gerekir. Hangi parçanın $u$ seçileceğine karar vermek için hoca bir harf sıralaması kullanıyor:

- **L:** logaritmik fonksiyonlar (logarithmic functions)
- **A:** ters trigonometrik fonksiyonlar (inverse trigonometric functions)
- **P:** polinom fonksiyonlar (polynomial functions)
- **T:** trigonometrik fonksiyonlar (trigonometric functions)
- **E:** üstel fonksiyonlar (exponential functions)

Kural şudur: İntegrand iki farklı sınıftan fonksiyonun çarpımıysa, bu sıralamada önce gelen fonksiyon $u$ seçilir. Kalan kısım (diferansiyel dahil) $dv$ olur. Sonra $u$'nun diferansiyeli alınarak $du$, $dv$'nin integrali alınarak $v$ bulunur ve formülde yerine konur.

> **Ek bilgi (derste anlatılmadı):** Bu sıralama ders kitaplarında büyük olasılıkla "LIATE" kuralı adıyla geçer: Logarithmic, Inverse trigonometric, Algebraic, Trigonometric, Exponential. Hocanın LAPTE'si ile aynı sıradır; yalnız harfler farklıdır. Bu bir kesin kural değil, pratik bir yol göstericidir. Sıralamada sonra gelen fonksiyonların integrali genelde daha kolay alındığı için onlar $dv$ tarafına bırakılır.

## 2. Polinom ile Trigonometrik Çarpımı: $\int x^2\cos x\,dx$

### Örnek 1: $\displaystyle\int x^2\cos x\,dx$

İntegrand bir polinom ($x^2$) ile bir trigonometrik fonksiyonun ($\cos x$) çarpımıdır. LAPTE sıralamasında $P$, $T$'den önce gelir. Bu yüzden:

$$u = x^2,\qquad dv = \cos x\,dx.$$

Her iki tarafın diferansiyeli alınırsa $du = 2x\,dx$ olur. $dv$'nin integrali alınırsa $v = \sin x$ olur. Formülde yerine konunca:

$$\int x^2\cos x\,dx = x^2\sin x - \int \sin x\cdot 2x\,dx = x^2\sin x - 2\int x\sin x\,dx.$$

Hoca $2$'yi ortak çarpan olarak dışarı aldı. Sağdaki integral yine bir polinom ile bir trigonometrik fonksiyonun çarpımıdır. Bu yüzden kısmi integrasyon bir kez daha uygulanır:

$$u = x,\quad dv = \sin x\,dx \;\Rightarrow\; du = dx,\quad v = -\cos x.$$

$$\int x\sin x\,dx = -x\cos x - \int(-\cos x)\,dx = -x\cos x + \int\cos x\,dx = -x\cos x + \sin x.$$

Hoca buradaki işaretleri ayrıca vurguladı: Bir eksi formülden ($-\int v\,du$), bir eksi de $v = -\cos x$'ten gelir. İkisinin çarpımı artıdır. Bulunan sonuç parantez içinde yerine konur:

$$\int x^2\cos x\,dx = x^2\sin x - 2\left(-x\cos x + \sin x\right) = x^2\sin x + 2x\cos x - 2\sin x + C.$$

Belirsiz integral olduğu için sona keyfi sabit $C$ eklenir.

**Soru:** İkinci satırdan sonra ne yaptık, nereye geçtik? **Cevap:** Hoca önce dikdörtgen içine aldığı kısmın birinci integral için kısmi integrasyon uygulaması olduğunu, bunu herkesin anladığını teyit etti. Uygun diferansiyeller ve integraller alınıp $uv - \int v\,du$'ya yerleştirildi. Ortaya çıkan yeni integral yine $\int u\,dv$ biçimindeydi. Ona da kısmi integrasyon bir kez daha uygulandı; parantez içindeki kısım bu ikinci uygulamadır. Yani kısmi integrasyon iki defa uygulandı.

Ders başında hoca, bir öğrencinin isteği üzerine, yerel ekstremum (local extreme value) için ikinci türev testiyle ilgili soruyu gelecek hafta çözeceğini söyledi ve kendisine hatırlatılmasını istedi.

## 3. Tablo Yöntemi: Kısmi İntegrasyonun Kısaltılmış Hâli

Hoca, iki kez kısmi integrasyon uygulama işleminin kısaltılabileceğini söyledi. Birçok kitap ve kaynak bunu ayrı bir yöntem olarak, "tablo yöntemi" (tabular method) adıyla anlatıyor.

> **Hocanın vurgusu:** Bu farklı bir yöntem değildir. Kısmi integrasyonun basitleştirilmiş hâlidir. "Madem öyle, klişeye uyalım, teamüle" diyerek hoca da buna tablo yöntemi diyor. Ayrıca bu basitleştirme her zaman uygulanamaz.

### 3.1 Tablonun Kurulması

İki sütun oluşturulur:

- **Türev sütunu (derivation column):** $u$ yazılır ve aşağı doğru art arda türevi alınır.
- **İntegral sütunu (integration column):** $dv$'deki fonksiyon yazılır ve aşağı doğru art arda integrali alınır.

$\int x^2\cos x\,dx$ için:

| Türev sütunu | İntegral sütunu | İşaret |
|---|---|---|
| $x^2$ | $\cos x$ | $+$ |
| $2x$ | $\sin x$ | $-$ |
| $2$ | $-\cos x$ | $+$ |
| $0$ | $-\sin x$ | |

Hoca polinomun türevi alına alına sonunda $0$'a ulaşıldığını, bunun "şanslı" olduğumuz anlamına geldiğini söyledi. Hoca integral sütununu yazarken önce "$\cos x$'in integrali $-\sin x$" dedi, hemen "$-\sin x$ değil, $\sin x$" diye düzeltti.

İntegral sütununu kontrol etmek için ters yönde türev alınır: $-\sin x$'in türevi $-\cos x$, $-\cos x$'in türevi $\sin x$, $\sin x$'in türevi $\cos x$'tir. Yani bir yönde integral, ters yönde türev vardır.

### 3.2 Tablonun Okunması

Türev sütunundaki her terim, integral sütununda bir alt satırdaki terimle çapraz çarpılır ve işaretler sırayla $+, -, +, \dots$ diye değişir. Hoca bunu kısmi integrasyonun formülüyle açıkladı: Birinci uygulamada $uv$ teriminin katsayısı $+$, $\int v\,du$'nun katsayısı $-$'dir. İkinci uygulamada aynı yapı tekrar eder. Türev sütununda $0$ çıktığı için ondan sonrasını hesaplamaya gerek yoktur; $0$ çarpı herhangi bir şey $0$'dır.

$$I = (+)\,x^2\sin x \;(-)\;2x(-\cos x) \;(+)\;2(-\sin x) = x^2\sin x + 2x\cos x - 2\sin x + C.$$

Sonuç, uzun yoldan bulunanla aynıdır.

## 4. Önce Değişken Dönüşümü, Sonra Tablo

### Örnek 2: $\displaystyle\int \cos\sqrt{x}\,dx$

> **Hocanın vurgusu:** Bu tarz bir soruyu sınavda görebilirsiniz.

İntegrandda $\sqrt{x}$ "pek iyi olmayan" bir ifadedir. Önce onu yok etmek için değişken dönüşümü (change of variable, substitution method) yapılır:

$$t = \sqrt{x} \;\Rightarrow\; dt = \frac{1}{2\sqrt{x}}\,dx \;\Rightarrow\; dx = 2\sqrt{x}\,dt = 2t\,dt.$$

Yerine konunca:

$$\int\cos\sqrt{x}\,dx = \int 2t\cos t\,dt.$$

Bu yine bir polinom ile bir trigonometrik fonksiyonun çarpımıdır. Tablo:

| Türev sütunu | İntegral sütunu | İşaret |
|---|---|---|
| $2t$ | $\cos t$ | $+$ |
| $2$ | $\sin t$ | $-$ |
| $0$ | $-\cos t$ | |

Hoca tabloda bir yerde $t$ yerine $x$ yazdığını fark edip düzeltti. Çapraz çarpımlar:

$$I = 2t\sin t - 2(-\cos t) + C = 2t\sin t + 2\cos t + C.$$

Son olarak asıl değişkene ($x$) geri dönülür:

$$\int\cos\sqrt{x}\,dx = 2\sqrt{x}\sin\sqrt{x} + 2\cos\sqrt{x} + C.$$

### Örnek 3: $\displaystyle\int \ln^3 x\,dx$

Hoca iki yol gösterdi.

**Birinci yol (ödev):** $u = \ln^3 x$, $dv = dx$ alınarak doğrudan kısmi integrasyon uygulanır. Hoca bu yolda büyük olasılıkla en az üç kez kısmi integrasyon uygulamak gerekeceğini söyledi. Bu yüzden bu genel uygulamayı tercih etmiyor ve ödev olarak bıraktı.

**İkinci yol:** Önce değişken dönüşümü:

$$x = e^t \;\Rightarrow\; dx = e^t\,dt,\qquad \ln x = t.$$

$$\int \ln^3 x\,dx = \int t^3 e^t\,dt.$$

<!-- BELİRSİZ: 00:21:11-00:21:25 arası altyazı bozuk ("n'ın yöntemlerden birleştirilmesi için", "t' t' t'"). Bu kısımda hocanın $\ln^3(e^t) = t^3$ yazdığı, sonraki cümlelerden anlaşılıyor. -->

Bu bir polinom ile bir üstel fonksiyonun çarpımıdır. Tablo:

| Türev sütunu | İntegral sütunu | İşaret |
|---|---|---|
| $t^3$ | $e^t$ | $+$ |
| $3t^2$ | $e^t$ | $-$ |
| $6t$ | $e^t$ | $+$ |
| $6$ | $e^t$ | $-$ |
| $0$ | $e^t$ | |

Hoca burada iki kez "şanslı" olduğumuzu söyledi: Polinomun türevi $0$'a ulaşıyor ve $e^t$'nin integrali her adımda kolayca alınıyor. Tablo, kısmi integrasyonun art arda birçok kez uygulanmasının kısaltmasıdır.

$$I = t^3e^t - 3t^2e^t + 6te^t - 6e^t + C.$$

$e^t$ ortak çarpan olarak alınır, sonra $e^t = x$ ve $t = \ln x$ yazılır:

$$\int\ln^3 x\,dx = x\left(\ln^3 x - 3\ln^2 x + 6\ln x - 6\right) + C.$$

Hoca isteyenin uzun yoldan, kısmi integrasyonun genel uygulanışıyla da yapabileceğini, ama bunun çok zaman alacağını söyledi. Pratik yol: önce değişken dönüşümü, sonra kısmi integrasyonun basitleştirilmiş hâli olan tablo yöntemi.

## 5. Döngüsel Durum: $\int e^x\sin x\,dx$ ve $\int e^{3t}\cos 2t\,dt$

### Örnek 4: $\displaystyle\int e^x\sin x\,dx$ (uzun yol)

İntegrand bir üstel fonksiyon ile bir trigonometrik fonksiyonun çarpımıdır. LAPTE'de $T$, $E$'den önce gelir:

$$u = \sin x,\quad dv = e^x\,dx \;\Rightarrow\; du = \cos x\,dx,\quad v = e^x.$$

$$I = \int e^x\sin x\,dx = e^x\sin x - \int e^x\cos x\,dx.$$

Hoca burada önemli bir gözlem yaptı: $\sin x$'in türevleri periyodik bir süreç oluşturur. $\sin x$'in türevi $\cos x$, $\cos x$'in türevi $\sin x$'in bir katıdır ($-\sin x$). Bu yüzden ikinci integrale kısmi integrasyon bir kez daha uygulanır:

$$u = \cos x,\quad dv = e^x\,dx \;\Rightarrow\; du = -\sin x\,dx,\quad v = e^x.$$

$$I = e^x\sin x - \left(e^x\cos x - \int e^x(-\sin x)\,dx\right) = e^x\sin x - e^x\cos x - \int e^x\sin x\,dx.$$

Sağ taraftaki son integral, başladığımız integralin ta kendisidir. Yani:

$$I = e^x\sin x - e^x\cos x - I.$$

$-I$ sol tarafa atılırsa:

$$2I = e^x(\sin x - \cos x) \;\Rightarrow\; I = \frac{e^x(\sin x - \cos x)}{2} + C.$$

<!-- BELİRSİZ: 00:29:25-00:29:53 arası altyazı bozuk ("koncentralı"). Bu kısımda sabitle ilgili bir açıklama ("C over 2") geçiyor; büyük olasılıkla $C/2$'nin yine keyfi bir sabit olduğu söyleniyor. -->

### Örnek 4 (tablo ile)

Hoca, burada da tablo yönteminin uygulanıp uygulanamayacağını sordu.

**Soru (hocadan):** Burada iki kez kısmi integrasyon uyguladım. Sizce tablo yöntemiyle basitleştirebilir miyiz? **Bir öğrencinin cevabı:** Sürekli dönecek galiba. **Hocanın cevabı:** Hayır, basitleştirebiliriz.

Türev sütununa $\sin x$ ya da $e^x$ yazılabilir; hoca bunun fark etmediğini söyledi ve $\sin x$ yazdı:

| Türev sütunu | İntegral sütunu | İşaret |
|---|---|---|
| $\sin x$ | $e^x$ | $+$ |
| $\cos x$ | $e^x$ | $-$ |
| $-\sin x$ | $e^x$ | $+$ |

Üçüncü satırda $-\sin x$ elde edildi. Bu, başladığımız $\sin x$ ile aynı ifadedir; tek fark eksi işaretidir. Hoca "burada duruyoruz" dedi. Artık devam etmeye gerek yoktur.

Tablonun okunması şöyledir:

- Çapraz çarpımlar ($\sin x\cdot e^x$ ile $+$, $\cos x\cdot e^x$ ile $-$) kısmi integrasyonun $uv$ terimlerini verir: $e^x\sin x - e^x\cos x$.
- Son satırdaki **yatay** çarpım, işaretiyle birlikte bir integral olarak kalır: $+\int(-\sin x)e^x\,dx = -I$. Bu terim, kısmi integrasyon uygulandıktan sonra sağ tarafta kalan integraldir.

$$I = e^x\sin x - e^x\cos x - I \;\Rightarrow\; 2I = e^x(\sin x - \cos x) \;\Rightarrow\; I = \frac{e^x(\sin x - \cos x)}{2} + C.$$

Hoca hangisinin daha kolay olduğunu sordu ve cevabı verdi: Tablolu yol daha kolaydır, çünkü yöntem basitleştirilmiştir.

**Soru:** Diğer tablolarda en altta sıfır olduğu için, sola atınca bir şey değişmiyordu, o yüzden öyle gördük, değil mi? **Cevap:** Hoca "Aynen öyle, olayı kaptınız" dedi. Polinomlu örneklerde son satırdaki yatay çarpım $0$ olduğu için görünmüyordu.

> **Ek bilgi (derste anlatılmadı):** Tablo yönteminin genel kuralı şöyle özetlenebilir: Her satırda türev sütunundaki terim bir alt satırdaki integral terimiyle çapraz çarpılır, işaretler $+, -, +, \dots$ diye değişir. Durulan satırda ise türev ile integral teriminin çarpımı, o satırın işaretiyle birlikte integral içinde bırakılır. Polinomlu durumlarda bu kalan integral $0$'dır; döngüsel durumlarda ise başlangıç integralinin bir katıdır.

### Örnek 5 (derste alıştırma): $\displaystyle\int e^{3t}\cos 2t\,dt$

Hoca bu soruyu "your test" diyerek öğrencilere çözdürdü. Genel yoldan yapılırsa işin uzayacağını, gösterdiği yöntemle en fazla 1 dakika içinde bulunması gerektiğini söyledi.

Öğrenciler çözerken hoca bir öğrencinin sorusunu yanıtladı ve durma kuralını açıkladı:

> **Hocanın vurgusu:** Başladığınız fonksiyonu (ör. sinüs) tabloda tekrar yakaladığınızda durursunuz. Katsayının ne olduğu önemli değildir: $\tfrac{1}{2}$ olabilir, $-\tfrac{1}{2}$ olabilir. "Ters işaretlisi" gelmesi gerekmez; illa eksi işaret olacak diye bir şey yok. Aynı fonksiyonu yakalarsanız durursunuz.

Çözüm:

| Türev sütunu | İntegral sütunu | İşaret |
|---|---|---|
| $\cos 2t$ | $e^{3t}$ | $+$ |
| $-2\sin 2t$ | $\tfrac{1}{3}e^{3t}$ | $-$ |
| $-4\cos 2t$ | $\tfrac{1}{9}e^{3t}$ | $+$ |

Üçüncü satırda $\cos 2t$ tekrar yakalandı; burada durulur.

Hoca önce integral sütununa her satırda $e^{3t}$ yazdı ve son satırdan "$-4I$" elde etti. Sonra hatayı fark etti: $e^{3t}$'nin integrali $\tfrac{1}{3}e^{3t}$'dir. "Niye uyarmıyorsunuz? Ben uyuyorsam siz uyumayın arkadaşlar" diyerek düzeltti.

Doğru tabloyla:

- Çapraz çarpımlar: $+\cos 2t\cdot\tfrac{1}{3}e^{3t}$ ve $-(-2\sin 2t)\cdot\tfrac{1}{9}e^{3t} = +\tfrac{2}{9}e^{3t}\sin 2t$.
- Son satırın yatay çarpımı: $+\int(-4\cos 2t)\tfrac{1}{9}e^{3t}\,dt = -\tfrac{4}{9}I$.

$$I = \frac{1}{3}e^{3t}\cos 2t + \frac{2}{9}e^{3t}\sin 2t - \frac{4}{9}I.$$

$-\tfrac{4}{9}I$ sol tarafa atılır:

$$\frac{13}{9}I = e^{3t}\left(\frac{1}{3}\cos 2t + \frac{2}{9}\sin 2t\right).$$

Her iki taraf $\tfrac{9}{13}$ ile çarpılırsa (ara adım eklendi):

$$I = \frac{e^{3t}(3\cos 2t + 2\sin 2t)}{13} + C.$$

> **Ders sonrası not:** Hoca "$-\tfrac{4}{9}I$'yı sola atınca $\tfrac{4}{9}I$ elde ederiz" dedi. Sol tarafta zaten $I$ olduğu için doğrusu $I + \tfrac{4}{9}I = \tfrac{13}{9}I$'dır. Hoca hemen ardından $\tfrac{13}{9}I$ yazdı; sonuç doğrudur. Hocanın son satırı altyazıda sözlü geçmiyor ("i integration is equal to ..."); yukarıdaki son hâl sympy ile türev alınarak doğrulandı.

## 6. Ters Trigonometrik Fonksiyonların İntegralleri

### Örnek 6: $\displaystyle\int \arcsin x\,dx$

Hoca önce sorunun ne istediğine dikkat çekti: Amaç $\arcsin x$'in türevini bulmak değil, türevi $\arcsin x$ olan bir fonksiyon bulmaktır. Sonra $C$ sabiti eklenerek belirsiz integral bulunur.

Bilinen değişken dönüşümü burada işe yaramaz. Hocanın fikri, integrandı $1\cdot\arcsin x$ olarak görmektir. $1$ bir polinomdur. LAPTE'de $A$, $P$'den önce gelir:

$$u = \arcsin x,\quad dv = dx \;\Rightarrow\; du = \frac{dx}{\sqrt{1-x^2}},\quad v = x.$$

$$I = x\arcsin x - \int\frac{x\,dx}{\sqrt{1-x^2}}.$$

Kalan integral için değişken dönüşümü yapılır:

$$a = 1 - x^2 \;\Rightarrow\; da = -2x\,dx \;\Rightarrow\; x\,dx = -\frac{1}{2}\,da.$$

$$-\int\frac{x\,dx}{\sqrt{1-x^2}} = -\int\frac{-\tfrac{1}{2}\,da}{\sqrt{a}} = \frac{1}{2}\int a^{-1/2}\,da = \sqrt{a}.$$

$a = 1 - x^2$ yazılınca:

$$\int\arcsin x\,dx = x\arcsin x + \sqrt{1-x^2} + C.$$

### Örnek 7: $\displaystyle\int \arctan x\,dx$

Hoca bu soruyu önce öğrencilerin çözmesi için bıraktı. İntegrandda yine bir ters trigonometrik fonksiyon vardır:

$$u = \arctan x,\quad dv = dx \;\Rightarrow\; du = \frac{dx}{1+x^2},\quad v = x.$$

$$I = x\arctan x - \int\frac{x\,dx}{1+x^2}.$$

Kalan integral için $a = 1 + x^2$, $da = 2x\,dx$ dönüşümüyle:

$$\int\frac{x\,dx}{1+x^2} = \frac{1}{2}\int\frac{da}{a} = \frac{1}{2}\ln(1+x^2).$$

$$\int\arctan x\,dx = x\arctan x - \frac{1}{2}\ln(1+x^2) + C.$$

> **Ders sonrası not:** Hoca kontrol için "$\ln(1+x^2)$'nin türevini alırsanız $\tfrac{x}{1+x^2}$ elde edersiniz" dedi. Doğrusu: $\ln(1+x^2)$'nin türevi $\tfrac{2x}{1+x^2}$'dir; $\tfrac{x}{1+x^2}$ ise $\tfrac{1}{2}\ln(1+x^2)$'nin türevidir. Sonuç doğrudur.

**Soru:** $\int\arctan x\,dx$ gibi bir sorunun kısmi integrasyonla çözülmesi gerektiği sınavda söylenecek mi? **Cevap:** Hayır, bunu sizin görmeniz lazım. İntegrand fonksiyona bakacaksınız: Türevi $\arctan x$ olan fonksiyonu bulacağım. Burada normal bir değişken dönüşümü yapılacak bir durum yok; "gözümü tırmalayan" bir ifade yok. Eğer orada $\arctan\sqrt{x}$ gibi bir şey olsaydı, $\sqrt{x}$'i yok etmek için değişken dönüşümü yapmak, sonra kısmi integrasyon uygulamak gerekirdi.

Hoca ayrıca ileride daha karmaşık örneklerin çözüleceğini söyledi. Şimdiye kadar en önemli iki yöntem, değişken dönüşümü ve kısmi integrasyon öğretildi. Diğer yöntemler (ör. rasyonel fonksiyonların integrasyonu) öğrenildikten sonra, birden fazla yöntemin bir arada kullanıldığı sorular çözülecek.

### Örnek 8: $\displaystyle\int \arctan\sqrt{x}\,dx$

Hoca önce bu sorunun üç yöntem gerektirebileceğini, bu yüzden şimdi çözemeyeceğini söyledi: önce değişken dönüşümü, sonra kısmi integrasyon, sonra büyük olasılıkla henüz anlatılmamış başka bir yöntem. Ardından $\arctan\sqrt{x}$'i doğrudan $u$ seçmeyi önerdi ve bu "ikinci yol"u tahtada denedi:

$$u = \arctan\sqrt{x},\quad dv = dx \;\Rightarrow\; du = \frac{1}{1+x}\cdot\frac{1}{2\sqrt{x}}\,dx,\quad v = x.$$

Burada zincir kuralı kullanılır: $\arctan$'ın türevi $\tfrac{1}{1+(\sqrt{x})^2} = \tfrac{1}{1+x}$, iç fonksiyonun türevi $\tfrac{1}{2\sqrt{x}}$'tir.

$$I = x\arctan\sqrt{x} - \int x\cdot\frac{1}{2\sqrt{x}(1+x)}\,dx = x\arctan\sqrt{x} - \frac{1}{2}\int\frac{\sqrt{x}}{1+x}\,dx.$$

**Soru:** Paydada $2 + 2x$ olmayacak mı? **Cevap:** Evet, ikisi de var. Hoca $\tfrac{1}{2}$'yi integralin önüne aldı.

Kalan integral için $\sqrt{x}$'i yok etmek amacıyla $x = t^2$ ($t > 0$ kabul edilerek) dönüşümü yapılır; $dx = 2t\,dt$:

$$\frac{1}{2}\int\frac{t}{1+t^2}\,2t\,dt = \int\frac{t^2}{1+t^2}\,dt.$$

Hoca burada farklı bir yöntem gerekeceğini düşünmüştü, ama "çok farklı bir yöntem gerekmiyormuş" dedi. Paydaki $t^2$, $(t^2 + 1) - 1$ diye yazılır:

$$\int\frac{t^2}{1+t^2}\,dt = \int\left(1 - \frac{1}{1+t^2}\right)dt = t - \arctan t.$$

Bu, $I$'dan çıkarılır. $t$ yerine $\sqrt{x}$ yazılır (pozitif bölgede çalışıldığı kabul edilir):

$$\int\arctan\sqrt{x}\,dx = x\arctan\sqrt{x} - \sqrt{x} + \arctan\sqrt{x} + C.$$

<!-- BELİRSİZ: 00:56:58-00:57:14 arası son satır altyazıda net okunmuyor ("eksi t gördüğümüz yere köküsü yazıyorduk"). Sonuç sympy ile türev alınarak doğrulandı. -->

Hoca bu sorunun "test sınavının ruhuna biraz aykırı" olduğunu, böyle bir sorunun büyük olasılıkla gelmediğini söyledi. Ardından 10 dakikalık ara verildi (00:57:14 – 01:12:02).

## 7. Trigonometrik Fonksiyonların İntegralleri: Temel Özdeşlikler

Aradan sonra hoca, haftaya yine soru çözeceklerini ve konuları bitirmeye uğraşacaklarını söyleyip yeni konuya geçti: trigonometrik fonksiyonların integralleri (integration of trigonometric functions). Bu konu da bir sonraki vize sınavının konularındandır.

### 7.1 Toplam Formülleri

**Toplam formülleri (addition formulas):**

- $\sin(a + b) = \sin a\cos b + \cos a\sin b$
- $\cos(a + b) = \cos a\cos b - \sin a\sin b$

$b$ yerine $-b$ yazılırsa fark formülleri elde edilir. Bunun için iki gerçek kullanılır: Kosinüs çift fonksiyondur ($\cos(-b) = \cos b$), sinüs tek fonksiyondur ($\sin(-b) = -\sin b$).

- $\sin(a - b) = \sin a\cos b - \cos a\sin b$
- $\cos(a - b) = \cos a\cos b + \sin a\sin b$

### 7.2 Kuvvet İndirgeme Formülleri

<!-- BELİRSİZ: 01:14:22-01:14:52 arası altyazıda yalnız "Bu, bu," var. Akış sonraki cümlelerden kuruldu: hoca kosinüs toplam formülünde $b = a$ alıyor. -->

$\cos(a + b)$ formülünde $b = a$ alınırsa:

$$\cos 2a = \cos^2 a - \sin^2 a.$$

Buraya $\sin^2 a = 1 - \cos^2 a$ (Pisagor özdeşliği) yazılırsa $\cos 2a = 2\cos^2 a - 1$ olur ve:

$$\cos^2 a = \frac{1 + \cos 2a}{2}.$$

Benzer şekilde $\cos^2 a = 1 - \sin^2 a$ yazılırsa:

$$\sin^2 a = \frac{1 - \cos 2a}{2}.$$

Hoca bu formüllerin anlamını kuvvet (degree) üzerinden açıkladı: Sol tarafta $\cos a$'nın kuvveti $2$'dir. Sağ tarafta $\cos 2a$'yı bir polinomun değişkeni gibi düşünürsek kuvveti $1$'dir. Yani kuvvet indirgenmiştir (power reduction).

> **Hocanın vurgusu:** Bu formüller çok önemlidir.

## 8. Sinüs ve Kosinüsün Kuvvetleri

### Örnek 9: $\displaystyle\int\cos^2 x\,dx$ ve $\displaystyle\int\sin^2 x\,dx$

Önce kuvvet indirgenir:

$$\int\cos^2 x\,dx = \int\frac{1 + \cos 2x}{2}\,dx = \frac{1}{2}\left(\int dx + \int\cos 2x\,dx\right) = \frac{1}{2}\left(x + \frac{1}{2}\sin 2x\right) + C.$$

Benzer şekilde:

$$\int\sin^2 x\,dx = \int\frac{1 - \cos 2x}{2}\,dx = \frac{1}{2}\left(x - \frac{1}{2}\sin 2x\right) + C.$$

### Örnek 10: $\displaystyle\int\sin^3 x\,dx$ (tek kuvvet)

Hoca çift kuvvet (even power) ile tek kuvvet (odd power) arasındaki farka dikkat çekti. $\sin^3 x$'in kuvveti tektir. Bu durumda integrand şöyle parçalanır:

$$\sin^3 x = \sin^2 x\cdot\sin x = (1 - \cos^2 x)\sin x.$$

Artık değişken dönüşümüne hazırız:

$$u = \cos x \;\Rightarrow\; du = -\sin x\,dx \;\Rightarrow\; \sin x\,dx = -du.$$

$$\int\sin^3 x\,dx = \int(1 - u^2)(-du) = -\int du + \int u^2\,du = -u + \frac{u^3}{3} + C.$$

$$\int\sin^3 x\,dx = -\cos x + \frac{\cos^3 x}{3} + C.$$

<!-- BELİRSİZ: 01:19:41-01:20:41 arası altyazı döngüye giriyor ("u'ye kadar ..."). Son satır ve $\sin^4 x$ sorusunun yazılışı bu kısımda; akış önceki ve sonraki cümlelerden kuruldu. -->

### Örnek 11: $\displaystyle\int\sin^4 x\,dx$ (çift kuvvet)

Altyazıda bu kısımda "Bunu kullanmak zorunda mıyız? Yok" diye bir soru-cevap geçiyor; büyük olasılıkla Pisagor teoreminin gerekip gerekmediği soruluyor. Hoca trigonometrik özdeşliği kullandı. Kuvvet çift olduğu için kuvvet indirgenir:

$$\sin^4 x = \left(\sin^2 x\right)^2 = \left(\frac{1 - \cos 2x}{2}\right)^2 = \frac{1}{4}\left(1 - 2\cos 2x + \cos^2 2x\right).$$

<!-- BELİRSİZ: 01:21:08-01:21:38 arası altyazıda yalnız "1 over 4", "1 minus 2", "x x" geçiyor. Açılım ara adım olarak kuruldu. -->

$\cos^2 2x$'in kuvveti yine çifttir, bu yüzden tekrar indirgenir. Hoca açının $2x$ olduğuna dikkat çekti:

$$\cos^2 2x = \frac{1 + \cos 4x}{2}.$$

İntegraller alınınca hocanın yazdığı hâl:

$$\int\sin^4 x\,dx = \frac{1}{4}\left[x - \sin 2x + \frac{1}{2}\left(x + \frac{1}{4}\sin 4x\right)\right] + C.$$

Sadeleştirilirse (ara adım eklendi):

$$\int\sin^4 x\,dx = \frac{3x}{8} - \frac{\sin 2x}{4} + \frac{\sin 4x}{32} + C.$$

> **Hocanın vurgusu:** Sınavda bu kadar uzun bir soru gelmez. Bir tane örnek çözdüm; gerisini siz çözersiniz.

### Örnek 12 (ödev): $\displaystyle\int\sin^5 x\,dx$

Kuvvet tek olduğu için ifade parçalanır ve Pisagor özdeşliği kullanılır:

$$\sin^5 x = \sin^4 x\cdot\sin x = \left(1 - \cos^2 x\right)^2\sin x.$$

Sonra $u = \cos x$, $\sin x\,dx = -du$ dönüşümü yapılır. Hoca gerisini öğrencilere bıraktı (çözümü aşağıda Örnek Sorular bölümündedir).

<!-- BELİRSİZ: 01:23:32 civarında altyazıda "sin 5x dx" geçiyor; bağlamdan (tek kuvvet, parçalama) $\sin^5 x$ olduğu anlaşılıyor. 01:24:14-01:24:33 arası altyazı bozuk. -->

### Örnek 13 (ödev): $\displaystyle\int\sin^5 x\cos x\,dx$

Hoca bunun daha kolay olacağını söyledi. Burada $\cos x\,dx$ zaten integrandda vardır:

$$u = \sin x \;\Rightarrow\; du = \cos x\,dx.$$

$$\int\sin^5 x\cos x\,dx = \int u^5\,du.$$

Hoca bunu ödev bıraktı. Sonuç: $\dfrac{u^6}{6} + C = \dfrac{\sin^6 x}{6} + C$.

<!-- BELİRSİZ: 01:24:39-01:24:53 arası soru metni altyazıda yalnız "kosinüs x, d x" diye geçiyor; $u = \sin x$ ve $u^5$ ifadesinden integrandın $\sin^5 x\cos x$ olduğu anlaşılıyor. -->

### Örnek 14 (derste alıştırma): $\displaystyle\int\sin^5 x\cos^2 x\,dx$

Hoca önce integrand üzerinde trigonometrik özdeşlikler ve Pisagor teoremiyle nasıl bir düzenleme yapılması gerektiğini düşünmelerini istedi ("it is your test").

Bu sırada öğrenciler ikinci vizenin konularını sordu. Hoca, şu ana kadar anlattığı her şeyin ikinci vizeye dahil olduğunu, yeni konu işlemek zorunda kalırlarsa final konularını o zaman belirteceğini söyledi. Konuların bir önceki derste açıklandığını, dersleri baştan sona düzenli dinlemeleri gerektiğini hatırlattı.

Çözüm: Tek kuvvetli terime ($\sin^5 x$) odaklanılır ve parçalanır:

$$\sin^5 x\cos^2 x = \sin^4 x\cos^2 x\sin x = \left(1 - \cos^2 x\right)^2\cos^2 x\sin x.$$

$$u = \cos x \;\Rightarrow\; du = -\sin x\,dx \;\Rightarrow\; \sin x\,dx = -du.$$

$$\int\sin^5 x\cos^2 x\,dx = -\int\left(1 - u^2\right)^2u^2\,du.$$

Hoca açılımı ödev bıraktı: Kare açılıp $u^2$ ile çarpılınca bir polinom integrali elde edilir. Tamamlanmış çözüm Örnek Sorular bölümündedir.

> **Hocanın vurgusu:** Bu tip sorularda tek kuvvetli terim parçalanır. Pisagor özdeşliği ($\sin^2 x + \cos^2 x = 1$) kullanılır. Sonra uygun değişken dönüşümü görülür.

## 9. Çarpımı Toplama Çevirme

### Örnek 15: $\displaystyle\int\sin 2x\cos 3x\,dx$

Hoca bu integralin nasıl alınacağını sordu. Bir öğrenci toplam formülünün kullanılacağını söyledi; hoca onayladı.

$A = 2x$, $B = 3x$ alınırsa aranan $\sin A\cos B$'dir. İki formül yazılır:

$$\sin(A + B) = \sin A\cos B + \cos A\sin B,$$

$$\sin(A - B) = \sin A\cos B - \cos A\sin B.$$

İkisi taraf tarafa toplanınca $\cos A\sin B$ terimleri sadeleşir:

$$\sin(A + B) + \sin(A - B) = 2\sin A\cos B \;\Rightarrow\; \sin A\cos B = \frac{\sin(A + B) + \sin(A - B)}{2}.$$

Böylece integral şuna dönüşür:

$$\int\sin 2x\cos 3x\,dx = \frac{1}{2}\int\left(\sin 5x + \sin(-x)\right)dx.$$

Sinüs tek fonksiyon olduğundan her $x$ için $\sin(-x) = -\sin x$'tir:

$$= \frac{1}{2}\left(\int\sin 5x\,dx - \int\sin x\,dx\right) = \frac{1}{2}\left(-\frac{\cos 5x}{5} + \cos x\right) + C.$$

Hoca bu örnekte temel fikri vurguladı: Elimizde fonksiyonların çarpımı var. Formülle fonksiyonların toplamına çevirdik.

**Soru (hocadan):** Fonksiyonların toplamının integralini almak mı daha kolay, çarpımının mı? **Cevap:** Toplamının integralini almak daha kolaydır.

> **Hocanın vurgusu:** Trigonometrik fonksiyonların çarpımını toplam formülleriyle toplama çevirmeyi sizin görmeniz gerekir; bu "sizin yeteneğinize kalmış." Trigonometriyle ilgili bir sürü formül var. Tek tek hepsini ezberlemek mantıklı değil. Yalnız toplam formülünü ve Pisagor formülünü bilmeniz yeterli; diğerleri bunlardan kolayca çıkarılır.

### Örnek 16 (derste alıştırma): $\displaystyle\int\sin 2x\sin 4x\,dx$

Hoca önce herkesin kendisinin yapmasını istedi. $A = 2x$, $B = 4x$ alınırsa aranan $\sin A\sin B$'dir. Kosinüsün iki formülü kullanılır:

$$\cos(A + B) = \cos A\cos B - \sin A\sin B,$$

$$\cos(A - B) = \cos A\cos B + \sin A\sin B.$$

Hoca birinci formülü eksiyle çarpıp ikinciyle toplamayı önerdi. Bu sırada işaretleri öğrencilerle birlikte kontrol etti. Toplanınca $\cos A\cos B$ terimleri sadeleşir:

$$\cos(A - B) - \cos(A + B) = 2\sin A\sin B \;\Rightarrow\; \sin A\sin B = \frac{\cos(A - B) - \cos(A + B)}{2}.$$

$$\int\sin 2x\sin 4x\,dx = \frac{1}{2}\int\left(\cos(-2x) - \cos 6x\right)dx.$$

Hoca önce "kosinüs tek fonksiyondur" dedi, hemen "çift fonksiyondur" diye düzeltti. $\cos(-2x) = \cos 2x$:

$$= \frac{1}{2}\left(\int\cos 2x\,dx - \int\cos 6x\,dx\right) = \frac{1}{2}\left(\frac{1}{2}\sin 2x - \frac{1}{6}\sin 6x\right) + C = \frac{\sin 2x}{4} - \frac{\sin 6x}{12} + C.$$

> **Ders sonrası not:** Altyazıda son adım "$\tfrac{1}{2}\sin 2x - \tfrac{1}{6}\sin 6x$" diye geçiyor; dışarıdaki $\tfrac{1}{2}$ çarpanı sözlü söylenmiyor. Tahtada büyük olasılıkla bu çarpan önde duruyordu. Çarpan unutulursa sonuç yanlış olur (sympy ile kontrol edildi); doğrusu $\dfrac{\sin 2x}{4} - \dfrac{\sin 6x}{12} + C$'dir.

Hoca farklı kombinasyonların da gelebileceğini, uygun toplam formülü seçilerek uygun özdeşliğin elde edilebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Derste çıkarılan iki formüle ek olarak üçüncü çarpım formülü de aynı yolla, iki kosinüs formülü bu kez toplanarak elde edilir: $\cos A\cos B = \dfrac{\cos(A - B) + \cos(A + B)}{2}$. Üç formül birlikte "çarpımı toplama çevirme" (product-to-sum) formülleri diye bilinir.

## 10. Tanjantın Kuvvetleri ve Gelecek Haftanın Konusu

### Örnek 17: $\displaystyle\int\tan^2 x\,dx$

Türevi $\tan^2 x$ olan bir fonksiyon aranıyor. Hoca şu bilinen gerçeği hatırlattı:

$$(\tan x)' = 1 + \tan^2 x.$$

İntegrandda $1$ terimi görünmüyor. Ama $1$ eklenip çıkarılarak elde edilebilir:

$$\int\tan^2 x\,dx = \int\left(1 + \tan^2 x - 1\right)dx = \int\left(1 + \tan^2 x\right)dx - \int dx = \tan x - x + C.$$

<!-- BELİRSİZ: 01:42:32-01:42:42 arası altyazı kesik ("Ve bu"); hoca önce bir işaret hatası yapıp "oh sorry, minus" diye düzeltiyor. -->

### Örnek 18: $\displaystyle\int\tan^3 x\,dx$

Hoca öğrencilere ne yapılabileceğini sordu, sonra tahtada bir düzenleme yaptı. Altyazıda düzenlemenin kendisi sözlü geçmiyor; sonraki adımlardan şu yazıldığı anlaşılıyor:

$$\tan^3 x = \tan x\left(1 + \tan^2 x\right) - \tan x.$$

<!-- BELİRSİZ: 01:43:37-01:44:18 arası tahtadaki düzenleme altyazıda okunmuyor ("can we write this?", "proper distribisyon"). Yukarıdaki biçim sonraki değişken dönüşümlerinden kuruldu. -->

İlk kısım için $a = \tan x$, $da = (1 + \tan^2 x)\,dx$:

$$\int\tan x\left(1 + \tan^2 x\right)dx = \int a\,da = \frac{a^2}{2}.$$

İkinci kısım için $\tan x = \dfrac{\sin x}{\cos x}$ yazılır ve $b = \cos x$, $db = -\sin x\,dx$ alınır:

$$-\int\tan x\,dx = -\int\frac{\sin x}{\cos x}\,dx = \int\frac{db}{b} = \ln|b|.$$

$a$ ve $b$ yerine konunca:

$$\int\tan^3 x\,dx = \frac{\tan^2 x}{2} + \ln|\cos x| + C.$$

Hoca bu kısımda doğal logaritmayı söylerken altyazıya "L'Hospital" diye geçen bir okuma var; kastedilen $\ln|b|$'dir.

### Gelecek Hafta: İndirgeme Formülleri

Hoca, $\tan^4 x$, $\tan^5 x$ gibi kuvvetler için genel bir formül elde etmek istediğini söyledi: $\tan^n x$'in integrali daha küçük bir kuvvetin integraline bağlanabilir. Gelecek hafta indirgeme formülleri (reduction formulas) anlatılacak. Hoca öğrencilerden bunu haftaya kadar araştırmalarını istedi.

> **Hocanın vurgusu:** İndirgeme formülleri ikinci vizeye dahil olan son konudur. Bu konu anlatıldıktan sonra genel alıştırmalar çözülecek.

> **Ek bilgi (derste anlatılmadı):** Tanjant için indirgeme formülü büyük olasılıkla şu biçimde verilecektir: $\displaystyle\int\tan^n x\,dx = \frac{\tan^{n-1}x}{n-1} - \int\tan^{n-2}x\,dx$ ($n \geq 2$). Bu formül, derste $\tan^3 x$ için yapılan düzenlemenin ($\tan^n x = \tan^{n-2}x(1 + \tan^2 x) - \tan^{n-2}x$) genelleştirilmesidir. $n = 3$ için derste bulunan sonucu verir.

## Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular derste sözlü olarak öğrencilere sorulan ya da ödev bırakılan sorulardır.

### Soru 1 (derste sözlü, 00:35:11)

$\displaystyle\int e^{3t}\cos 2t\,dt$ integralini tablo yöntemiyle hesaplayınız. (Hoca: "Size gösterdiğim yöntemle en fazla 1 dakika içinde buluyor olmanız lazım.")

**Çözüm (derste verildi):** Türev sütunu $\cos 2t \to -2\sin 2t \to -4\cos 2t$, integral sütunu $e^{3t} \to \tfrac{1}{3}e^{3t} \to \tfrac{1}{9}e^{3t}$. $\cos 2t$ yakalanınca durulur:

$$I = \frac{1}{3}e^{3t}\cos 2t + \frac{2}{9}e^{3t}\sin 2t - \frac{4}{9}I \;\Rightarrow\; I = \frac{e^{3t}(3\cos 2t + 2\sin 2t)}{13} + C.$$

### Soru 2 (derste sözlü, 00:46:34)

$\displaystyle\int\arctan x\,dx$ integralini hesaplayınız.

**Çözüm (derste verildi):** $u = \arctan x$, $dv = dx$. $\displaystyle I = x\arctan x - \int\frac{x\,dx}{1+x^2} = x\arctan x - \frac{1}{2}\ln(1+x^2) + C$.

### Soru 3 (derste sözlü, ödev, 00:19:31)

$\displaystyle\int\ln^3 x\,dx$ integralini $u = \ln^3 x$, $dv = dx$ seçerek doğrudan kısmi integrasyonla hesaplayınız.

> **Çözüm (derste verilmedi):** $du = \dfrac{3\ln^2 x}{x}\,dx$, $v = x$ olur ve $\displaystyle\int\ln^3 x\,dx = x\ln^3 x - 3\int\ln^2 x\,dx$ elde edilir. Aynı yolla $\displaystyle\int\ln^2 x\,dx = x\ln^2 x - 2\int\ln x\,dx$ ve $\displaystyle\int\ln x\,dx = x\ln x - x$ bulunur. Yerine konunca $x\left(\ln^3 x - 3\ln^2 x + 6\ln x - 6\right) + C$ çıkar. Kısmi integrasyon üç kez uygulanmıştır. Sonuç, derste ikinci yolla bulunanla aynıdır (sympy ile doğrulandı).

### Soru 4 (derste sözlü, 00:52:48)

$\displaystyle\int\arctan\sqrt{x}\,dx$ integralini $u = \arctan\sqrt{x}$, $dv = dx$ seçerek deneyiniz.

**Çözüm (derste verildi):** Bkz. Örnek 8. Sonuç: $x\arctan\sqrt{x} - \sqrt{x} + \arctan\sqrt{x} + C$.

### Soru 5 (derste sözlü, ödev, 01:23:32)

$\displaystyle\int\sin^5 x\,dx$ integralini hesaplayınız.

> **Çözüm (derste verilmedi):** $\sin^5 x = (1 - \cos^2 x)^2\sin x$. $u = \cos x$, $\sin x\,dx = -du$ ile $\displaystyle -\int(1 - u^2)^2\,du = -\int(1 - 2u^2 + u^4)\,du = -u + \frac{2u^3}{3} - \frac{u^5}{5}$ olur. Sonuç: $-\cos x + \dfrac{2}{3}\cos^3 x - \dfrac{1}{5}\cos^5 x + C$ (sympy ile doğrulandı).

### Soru 6 (derste sözlü, ödev, 01:24:39)

$\displaystyle\int\sin^5 x\cos x\,dx$ integralini hesaplayınız.

> **Çözüm (derste verilmedi):** $u = \sin x$, $du = \cos x\,dx$ ile $\displaystyle\int u^5\,du = \frac{u^6}{6} + C = \frac{\sin^6 x}{6} + C$ (sympy ile doğrulandı).

### Soru 7 (derste sözlü, 01:25:37)

$\displaystyle\int\sin^5 x\cos^2 x\,dx$ integrali için integrand üzerinde hangi düzenleme yapılmalıdır? İntegrali hesaplayınız.

**Kısmi çözüm (derste verildi):** $\sin^5 x\cos^2 x = (1 - \cos^2 x)^2\cos^2 x\sin x$, $u = \cos x$ ile $\displaystyle -\int(1 - u^2)^2u^2\,du$. Açılım ödev bırakıldı.

> **Çözüm (derste verilmedi):** $-(1 - u^2)^2u^2 = -u^2 + 2u^4 - u^6$. İntegrali $-\dfrac{u^3}{3} + \dfrac{2u^5}{5} - \dfrac{u^7}{7}$'dir. Sonuç: $-\dfrac{\cos^3 x}{3} + \dfrac{2\cos^5 x}{5} - \dfrac{\cos^7 x}{7} + C$ (sympy ile doğrulandı).

### Soru 8 (derste sözlü, 01:36:37)

$\displaystyle\int\sin 2x\sin 4x\,dx$ integralini uygun toplam formülüyle hesaplayınız.

**Çözüm (derste verildi):** $\sin A\sin B = \dfrac{\cos(A - B) - \cos(A + B)}{2}$ ile $\dfrac{\sin 2x}{4} - \dfrac{\sin 6x}{12} + C$ (dışarıdaki $\tfrac{1}{2}$ çarpanına dikkat; bkz. Örnek 16).

### Soru 9 (derste sözlü, 01:43:05)

$\displaystyle\int\tan^3 x\,dx$ integralinde ne yapabiliriz?

**Çözüm (derste verildi):** $\tan^3 x = \tan x(1 + \tan^2 x) - \tan x$ yazılır. Sonuç: $\dfrac{\tan^2 x}{2} + \ln|\cos x| + C$.

## Dersin Toparlaması

Dersin ilk yarısında kısmi integrasyon pekiştirildi. $u$ seçimi için LAPTE sıralaması (logaritmik, ters trigonometrik, polinom, trigonometrik, üstel) kullanıldı. Ardından iki kez ya da daha fazla kısmi integrasyon gerektiren durumlar için tablo yöntemi gösterildi. Hoca bunun ayrı bir yöntem değil, kısmi integrasyonun basitleştirilmiş hâli olduğunu vurguladı. Polinomlu durumlarda türev sütunu $0$'a ulaşır. Döngüsel durumlarda ($e^x\sin x$, $e^{3t}\cos 2t$) başlangıç fonksiyonu tekrar yakalanınca durulur ve sonuç cebirsel bir denklemden bulunur. İntegrandda $\sqrt{x}$ gibi "gözü tırmalayan" bir ifade varsa önce değişken dönüşümü, sonra kısmi integrasyon uygulanır. $\arcsin x$, $\arctan x$ ve $\arctan\sqrt{x}$ gibi ters trigonometrik fonksiyonların integralleri, integrand $1\cdot f(x)$ olarak düşünülerek bulundu.

İkinci yarıda trigonometrik integrallere geçildi. Toplam formülleri ve Pisagor özdeşliğinden kuvvet indirgeme ve çarpımı toplama çevirme formülleri türetildi. Çift kuvvetlerde kuvvet indirgenir; tek kuvvetlerde tek kuvvetli terim parçalanır, Pisagor özdeşliği kullanılır ve uygun değişken dönüşümü yapılır. Çarpımlar toplama çevrilir, çünkü toplamın integrali çarpımınkinden kolaydır. $\tan^2 x$ ve $\tan^3 x$ için $(\tan x)' = 1 + \tan^2 x$ gerçeği kullanıldı. Gelecek hafta, $\tan^n x$ gibi yüksek kuvvetler için indirgeme formülleri anlatılacak; bu, ikinci vizeye dahil olan son konudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
