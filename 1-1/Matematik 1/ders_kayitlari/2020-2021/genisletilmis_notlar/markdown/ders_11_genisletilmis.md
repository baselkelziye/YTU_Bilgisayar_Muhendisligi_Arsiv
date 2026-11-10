# Ders 11 Genişletilmiş Notu: Mutlak ve Yerel Uç Değerler, Kritik Noktalar, Rolle ve Ortalama Değer Teoremleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Türevin Uygulamalarına Giriş
- 2. Mutlak Maksimum ve Minimum
- 3. Uç Değer Teoremi
- 4. Mutlak Uç Değer Örnekleri: $\sin x$
- 5. Yerel Maksimum ve Minimum
- 6. Kritik Noktalar
- 7. Yerel Uç Değer ve Kritik Nokta Teoremi
- 8. Kapalı Aralıkta Uç Değerler: $x^4 - 2x^3$
- 9. Birinci Türev Testi
- 10. Artan-Azalan Aralıklar ve Yerel Uç Değer Örneği
- 11. Rolle Teoremi
- 12. Ortalama Değer Teoremi
- 13. Parçalı Fonksiyonda Ortalama Değer Teoremi
- 14. Örnek Sorular

## 1. Türevin Uygulamalarına Giriş

Bu derste hoca, türevin uygulamaları (applications of derivatives) ana başlığına geçti. Hoca bu dersten itibaren Zoom'un beyaz tahtası yerine tablet üzerinde bir uygulamaya yazarak anlattı. Altyazıda yalnız sözlü anlatım var. Bu yüzden formüller ve çizimler hocanın söylediklerinden kuruldu.

Dersin konuları sırasıyla şunlardır:

- Mutlak maksimum ve minimum (absolute maximum/minimum): nokta ve değer kavramları.
- Uç değer teoremi (extreme value theorem).
- Yerel maksimum ve minimum (local maximum/minimum).
- Kritik nokta (critical point).
- Yerel uç değer ile kritik nokta arasındaki ilişki.
- Birinci türev testi (first derivative test).
- Rolle teoremi (Rolle's theorem) ve ortalama değer teoremi (mean value theorem).

Hoca, konuları hızlıca bitirip ilerideki derslerde bol soru çözmek istediğini söyledi. "Konuyu anlamaya çalışın, çok zor değil. Tanımların mantığı bizim için önemli" dedi.

## 2. Mutlak Maksimum ve Minimum

### 2.1 Tanım

**Tanım (Mutlak maksimum ve minimum):**

- $f: D \to \mathbb{R}$ bir fonksiyon ve $c \in D$ olsun.
- Her $x \in D$ için $f(c) \ge f(x)$ ise $c$'ye $f$'nin **bir** mutlak maksimum noktası (an absolute maximum point) denir. $f(c)$'ye $f$'nin mutlak maksimum değeri (the absolute maximum value) denir.
- Her $x \in D$ için $f(c) \le f(x)$ ise $c$'ye $f$'nin bir mutlak minimum noktası denir. $f(c)$'ye mutlak minimum değeri denir.
- Mutlak maksimum değeri kısaca $\max f$, mutlak minimum değeri kısaca $\min f$ ile gösterilir.

Hoca burada İngilizcedeki tanımlıklara dikkat çekti. Nokta için "**an** absolute maximum point", değer için "**the** absolute maximum value" denir. Bunun anlamı şudur: mutlak maksimum **değeri tektir**. Ama bu değeri aldıran **nokta birden fazla** olabilir. Aynı ayrım minimum için de geçerlidir.

### 2.2 Örnek: $f(x) = x^2$, $D = \mathbb{R}$

$f(x) = x^2$ fonksiyonunun tanım kümesi bütün reel sayılardır. Her $x \in \mathbb{R}$ için

$$f(0) = 0 \le x^2 = f(x)$$

olur. Bu yüzden $x = 0$ bir mutlak minimum noktasıdır. $f(0) = 0$ mutlak minimum değeridir. Fonksiyon yukarı doğru sınırsız büyüdüğü için mutlak maksimum yoktur (ara adım eklendi).

### 2.3 Örnek: $f(x) = x^2$, $D = [0, 2]$

Hoca aynı fonksiyonun $[0, 2]$ kapalı aralığına kısıtlanışını ele aldı. Değerler $0$'dan $4$'e kadar gider. Grafik elimizi kaldırmadan çizilebilir. Yani fonksiyon $[0, 2]$ üzerinde süreklidir.

- Her $x \in [0, 2]$ için $f(2) = 4 \ge f(x)$. Bu yüzden $x = 2$ bir mutlak maksimum noktası, $f(2) = 4$ mutlak maksimum değeridir.
- Her $x \in [0, 2]$ için $f(0) = 0 \le f(x)$. Bu yüzden $x = 0$ bir mutlak minimum noktası, $f(0) = 0$ mutlak minimum değeridir.

Hoca burada önce "the absolute point" demeye başladı, sonra düzeltti: nokta için "the" değil "an" kullanılır.

### 2.4 Örnek: $f(x) = x^2$, $D = (0, 2]$

Bu kez tanım kümesi $(0, 2]$'dir. $2$ dahildir, $0$ dahil değildir.

- Mutlak maksimum vardır: $x = 2$ mutlak maksimum noktası, $f(2) = 4$ mutlak maksimum değeridir. Bunun nedeni aralığın $2$ tarafında kapalı olmasıdır.
- Mutlak minimum noktası yoktur. Nokta olmadığı için mutlak minimum değeri de yoktur.

<!-- BELİRSİZ: 00:31:42'de hoca tanım kümesini "from 0 to closed interval from 0 to 4" diye okuyor. Öğrenci sorusundaki "sıfırdan ikiye, iki dahil, sıfır dahil değil" ifadesinden (00:37:28) tanım kümesinin $(0, 2]$ olduğu anlaşılıyor. -->

**Soru:** Sol uçtaki içi boş noktada "nokta var ama değer yok" mu deriz, yoksa ikisi de mi yok? **Cevap:** İkisi de yok. Değer olabilmesi için noktanın olması gerek koşuldur. Burada $0$ aralığa, yani tanım kümesine dahil değildir. Bu yüzden minimum noktası da yoktur.

**Soru:** $x$ sağdan $0$'a giderken limit alarak minimum diyemez miyiz? **Cevap:** Hayır. Limit, $x$ bir noktaya yaklaşırken $f(x)$'in yaklaştığı değerdir. Bu değerin fonksiyonun aldığı bir değer olması gerekmez. Fonksiyon sürekli olursa eşit olur. Burada $x \to 0^+$ iken $f(x)$ değerleri $0$'a yaklaşır, ama $f(0)$ tanımlı değildir. Hoca "Bunlar çok farklı kavramlar" dedi.

## 3. Uç Değer Teoremi

Hoca bu teoremi "çok önemli" diye tanıttı.

**Teorem (Uç değer teoremi):**

- $f$, kapalı $[a, b]$ aralığı üzerinde sürekli olsun.
- O zaman $f$'nin $[a, b]$ üzerinde mutlak maksimum değeri ($\max f$) ve mutlak minimum değeri ($\min f$) vardır.

> **Hocanın vurgusu:** Teoremin iki koşulu var: süreklilik ve aralığın **kapalı** olması. Bu koşullar olmadan bu teoremden söz edemeyiz.

Hoca ispatı biçimsel olarak yapmadı. Kapalı bir aralıkta sürekli bir fonksiyonun grafiğini çizdi. Grafik üzerinde en yüksek noktayı $\max f$, en alçak noktayı $\min f$ olarak gösterdi.

Bir önceki örnekte $(0, 2]$ kapalı olmadığı için teorem kullanılamaz. Gerçekten de orada mutlak minimum yoktu.

> **Ek bilgi (derste anlatılmadı):** Uç değer teoreminin ispatı reel sayıların tamlık özelliğine dayanır. Bu yüzden kalkülüs derslerinde büyük olasılıkla ispatsız verilir. Teorem yalnız varlığı garanti eder; uç değerin nerede olduğunu söylemez.

## 4. Mutlak Uç Değer Örnekleri: $\sin x$

### 4.1 $f(x) = \sin x$, $D = \mathbb{R}$

Hoca, aralık kapalı olmasa da bir fonksiyonun mutlak uç değeri olabileceğini gösterdi. $\sin x$, $\mathbb{R}$ üzerinde tanımlıdır. $\mathbb{R}$ kapalı ve sınırlı bir aralık değildir. Yine de:

- $\max f = 1$. Bu değer $x = \dfrac{\pi}{2}$ gibi noktalarda alınır. Sonsuz sayıda mutlak maksimum noktası vardır.
- $\min f = -1$. Bu değer $x = -\dfrac{\pi}{2}$, $x = \dfrac{3\pi}{2}$ gibi noktalarda alınır. Sonsuz sayıda mutlak minimum noktası vardır.

Hoca Türkçe olarak şöyle özetledi: sonsuz sayıda mutlak minimum nokta var, çünkü fonksiyon bire bir değil. Ama hepsinde alınan değer aynıdır: $-1$. Bu, fonksiyonun alabileceği en küçük değerdir. Benzer şekilde en büyük değer $1$'dir. "Değerler bir tanedir. Ona dikkat edin."

Mutlak maksimum noktaları $\dfrac{\pi}{2} + 2k\pi$, mutlak minimum noktaları $-\dfrac{\pi}{2} + 2k\pi$ biçiminde yazılabilir ($k \in \mathbb{Z}$) (ara adım eklendi).

### 4.2 $D = \left(0, \dfrac{\pi}{4}\right)$

Hoca sonra fonksiyonu $\left(0, \dfrac{\pi}{4}\right)$ açık aralığında ele aldı. Grafiği bu aralıkta çizdi. Bu aralıkta fonksiyon sürekli artar. İki uç da aralığa dahil olmadığı için ne mutlak maksimum ne de mutlak minimum vardır.

<!-- BELİRSİZ: 00:42:02-00:43:15 arasında fonksiyon sözlü okunmuyor; yalnız "from 0 to pi over 4" geçiyor. Önceki ve sonraki örnekle aynı fonksiyon ($\sin x$) olduğu varsayıldı. -->

### 4.3 $D = (0, \pi)$

Son örnekte aralık $(0, \pi)$'dir. Fonksiyon bu aralıkta süreklidir. Grafikten:

- $x = \dfrac{\pi}{2}$ mutlak maksimum noktası, $\max f = 1$.
- Mutlak minimum noktası yoktur. Bu yüzden mutlak minimum değeri de yoktur ($\min f$ yok).

Değerler $0$'a uçlarda yaklaşır, ama uçlar aralıkta değildir (ara adım eklendi).

## 5. Yerel Maksimum ve Minimum

### 5.1 Tanım

**Tanım (Yerel maksimum ve minimum):**

- $f: D \to \mathbb{R}$, $D \subset \mathbb{R}$ ve $c \in D$ olsun.
- $c$'yi içeren bir **açık** $I \subset D$ aralığı varsa ve her $x \in I$ için $f(c) \ge f(x)$ oluyorsa, $c$'ye $f$'nin bir yerel maksimum noktası (local maximum point), $f(c)$'ye bir yerel maksimum değeri denir.
- Benzer şekilde, her $x \in I$ için $f(c) \le f(x)$ ise $c$ bir yerel minimum noktası, $f(c)$ bir yerel minimum değeridir.

Hoca "Bu koşul çok önemli" dedi. Mutlak tanımda karşılaştırma bütün tanım kümesi üzerindedir. Yerel tanımda ise yalnız $c$'nin etrafındaki bir açık aralıkta karşılaştırma yapılır.

Hoca ders içinde bir örnekte $I$ aralığını kapalı yazdı. Sonra bir öğrencinin uyarısıyla düzeltti: "$I$ açık aralık olmalı, kapalı değil. Tanıma bakın." Ardından şunu ekledi:

> **Hocanın vurgusu:** Kavramlar ve tanımlar çok önemli. Önce tanımların ruhunu anlamaya çalışın. Tanımları kavramazsanız ezber yapmış olursunuz, karıştırırsınız ve hata yaparsınız.

### 5.2 Grafik üzerinde yerel maksimum

Hoca inişli çıkışlı bir grafik çizdi. Üzerinde iki tepe noktası işaretledi: $c_1$ ve $c_2$.

- $c_1$'i içeren bir açık $I_1$ aralığı seçilebilir. Her $x \in I_1$ için $f(c_1) \ge f(x)$. Bu yüzden $c_1$ bir yerel maksimum noktası, $f(c_1)$ bir yerel maksimum değeridir.
- $c_2$'yi içeren bir açık $I_2$ aralığı seçilebilir. Her $x \in I_2$ için $f(c_2) \ge f(x)$. Bu yüzden $c_2$ de bir yerel maksimum noktası, $f(c_2)$ bir yerel maksimum değeridir.

Buradan şu sonuç çıkar: **yerel maksimum değeri birden fazla olabilir.** Mutlak maksimum değeri ise tektir.

**Soru:** Bu grafikte $c_1$ aynı zamanda mutlak maksimum değerini mi veriyor? **Cevap:** Evet, bu özel grafiğe göre $f(c_1)$ yerel maksimum değeri aynı zamanda mutlak maksimum değeridir.

### 5.3 Mutlak ve yerel ilişkisi

Hoca şu ilişkiyi verdi:

- Her mutlak uç değer yereldir.
- Her yerel uç değer mutlak değildir.

Mantık diliyle: "mutlak maksimum $\Rightarrow$ yerel maksimum" doğrudur. Tersi her zaman doğru değildir.

Hoca ikinci bir grafikte yerel minimum noktalarını da gösterdi. Grafikte üç yerel minimum noktası vardı. Biri aynı zamanda mutlak minimumdu. Hoca uç noktaları da hesaba katarak şu yöntemi verdi:

- Bütün yerel minimum değerleri karşılaştırılır. En küçüğü mutlak minimum değeridir.
- Bütün yerel maksimum değerleri karşılaştırılır. En büyüğü mutlak maksimum değeridir.

Hoca "ekstremum" (extremum) sözcüğünü de açıkladı: ekstremum, yerel maksimum ya da yerel minimumun genel adıdır. Türkçede "uç değer" denir.

> **Ders sonrası not:** Hoca grafiklerde ve Bölüm 8'deki örnekte aralığın uç noktalarındaki değerleri de yerel uç değer saydı. Derste verilen tanım açık aralık istediği için bu tanımla bir kapalı aralığın uç noktası yerel uç nokta olamaz. Ders kitaplarında (ör. Thomas) uç noktadaki yerel uç değer büyük olasılıkla yarı açık aralıkla ayrıca tanımlanır. "Her mutlak uç değer yereldir" ifadesi, uç noktada oluşan mutlak uç değerler için ancak bu kitap tanımıyla doğrudur.

## 6. Kritik Noktalar

### 6.1 Tanım

**Tanım (Kritik nokta):**

- $c \in D(f)$ olsun.
- $f'(c) = 0$ ise ya da $f'(c)$ yoksa, $c$'ye $f$'nin bir kritik noktası (critical point) denir.

> **Hocanın vurgusu:** $c \in D(f)$ bir ön koşuldur. Bu koşul olmadan kritik noktadan söz edemeyiz. Nokta tanım kümesinde değilse kritik nokta değildir.

### 6.2 Örnek 1: Üst yarım çember

$f(x) = \sqrt{1 - x^2}$ fonksiyonu, birim çemberin üst yarısıdır.

- **Tanım kümesi:** $1 - x^2 \ge 0$ olmalı. $D(f) = [-1, 1]$, kapalı aralık.
- **Türev:**
  $$f'(x) = \frac{-2x}{2\sqrt{1 - x^2}} = \frac{-x}{\sqrt{1 - x^2}}.$$
- **$f'(c) = 0$ koşulu:** Pay sıfır olmalı: $x = 0$. $0 \in D(f)$. Bu yüzden $c_1 = 0$ kritik noktadır. Bu, çemberin tepe noktasıdır.
- **$f'(c)$ yok koşulu:** Payda $x = \pm 1$'de sıfır olur.
  - $c_2 = -1$: $f'(-1)$'i hesaplamak için $-1$'i türev fonksiyonuna koyamayız; $f'(-1)$ yoktur. $-1 \in D(f)$. Bu yüzden $-1$ kritik noktadır.
  - $c_3 = 1$: Benzer şekilde $f'(1)$ yoktur ve $1 \in D(f)$. Bu yüzden $1$ kritik noktadır.

**Sonuç:** Kritik noktalar $-1$, $0$, $1$. (sympy ile doğrulandı.)

> **Ders sonrası not:** Altyazıda $c_3 = 1$ için "F' 1, 0" geçiyor (01:18:26). Doğrusu $f'(1)$ yoktur, çünkü payda sıfırdır. $x = 1$ bu nedenle kritik noktadır.

### 6.3 Örnek 2: $f(x) = |x|$

$y = |x|$ fonksiyonunun grafiği $0$'da bir köşe yapar.

- $f'(0)$ yoktur.
- $0 \in D(f)$.

Bu iki bilgi birlikte $c = 0$'ın kritik nokta olduğunu verir.

### 6.4 Örnek 3: Bütün kritik noktalar

Hoca öğrencilere bir fonksiyonun bütün kritik noktalarını bulmayı ödev olarak verdi. Cevapları bekledi. Sonra "Herkes aynı hatayı yaptı" dedi.

<!-- BELİRSİZ: Fonksiyon altyazıda sözlü okunmuyor (01:21:22). Hocanın türevi "1 minus 1 over x squared" diye vermesi ve tanım kümesinin $\mathbb{R} \setminus \{0\}$ olması fonksiyonun $f(x) = x + \dfrac{1}{x}$ olduğunu gösteriyor. -->

**Çözüm:**

- **Önce tanım kümesi:** $D(f) = \mathbb{R} \setminus \{0\}$.
- **Türev:**
  $$f'(x) = 1 - \frac{1}{x^2} = \frac{x^2 - 1}{x^2}.$$
- $f'(1) = 0$ ve $1 \in D(f)$. Bu yüzden $x = 1$ kritik noktadır.
- $f'(-1) = 0$ ve $-1 \in D(f)$. Bu yüzden $x = -1$ kritik noktadır.
- $f'(0)$ yoktur, yani birinci koşul sağlanıyor. Ama $0 \notin D(f)$. Bu yüzden **$0$ kritik nokta değildir.**

**Sonuç:** Kritik noktalar $x = -1$ ve $x = 1$. (sympy ile doğrulandı.)

> **Hocanın vurgusu:** Önce tanım kümesini bulun. Tanım kümesini hesaplamadan kritik nokta ararsanız hata yaparsınız.

**Soru:** Kritik nokta ile kırılma noktası (köşe, broken point) aynı şey mi? **Cevap:** Hayır. Burada $0$ noktasında fonksiyon tanımlı değildir. Grafikte bir noktada kırılma olduğunu söyleyebilmek için o noktanın tanım kümesinde olması gerekir. $|x|$ örneğinde $0$ tanım kümesindeydi. Bu yüzden orada kırılma noktası vardır. İkisini karıştırmayın.

## 7. Yerel Uç Değer ve Kritik Nokta Teoremi

### 7.1 Teorem

**Teorem:**

- $f$'nin yerel maksimumu ya da yerel minimumu varsa, bu değer bir kritik noktada oluşur.

Hoca teoremi mantık diliyle yazdı. $p$: "$f$'nin yerel maksimum ya da minimumu var". $q$: "bu değer bir kritik noktada oluşur". Teorem $p \Rightarrow q$ der.

Bu durumda $q$, $p$ için **gerek koşuldur** (necessary condition), ama **yeter koşul değildir** (not sufficient). Hoca Türkçe olarak şöyle açıkladı: Fonksiyonunuz yerel maksimum ya da yerel minimuma sahipse, o değer kesinlikle bir kritik noktada olmak zorundadır. Ama her kritik noktada bir yerel maksimum ya da yerel minimum olmak zorunda değildir.

> **Ek bilgi (derste anlatılmadı):** Bu teorem ders kitaplarında büyük olasılıkla Fermat teoremi adıyla geçer. İç noktada türevlenebilir bir fonksiyonun yerel uç değeri varsa o noktada türev sıfırdır. Türevin olmadığı noktalar ayrıca kritik nokta tanımına eklendiği için teorem kritik nokta diliyle yukarıdaki gibi yazılır.

### 7.2 Teoremi doğrulayan örnek: $f(x) = x^2$

- $0$'ı içeren bir $I$ aralığında her $x \in I$ için $f(0) \le f(x)$. Bu yüzden $f$'nin $0$'da yerel minimum değeri vardır: $f(0) = 0$. Bu aynı zamanda mutlak minimum değeridir.
- $f'(x) = 2x$, $f'(0) = 0$ ve $0 \in D(f)$. Yani $x = 0$ kritik noktadır.

Teoremin söylediği gibi yerel uç değer bir kritik noktada oluşmuştur.

### 7.3 Karşı örnek: $f(x) = x^3$

Hoca "$q \Rightarrow p$ her zaman doğru değildir" dedi ve şu örneği verdi.

- $f'(x) = 3x^2$, $f'(0) = 0$ ve $0 \in D(f)$. Bu yüzden $x = 0$ kritik noktadır.
- Ama $0$'ı içeren hiçbir açık $I$ aralığında her $x$ için $f(x) \ge f(0)$ ya da her $x$ için $f(x) \le f(0)$ olmaz:
  - $I$'daki bazı $x$ değerleri için ($x > 0$) $f(x) > 0 = f(0)$.
  - $I$'daki bazı $x$ değerleri için ($x < 0$) $f(x) < 0 = f(0)$.
- Bu yüzden $x = 0$'da yerel maksimum da yerel minimum da yoktur.

Hoca Türkçe olarak sordu: "Sıfırı içeren öyle bir aralık bulabilir misiniz ki her $x$ için $f(x)$ değerleri $f(0)$'dan büyük olsun? Buraya yerel maksimum ya da yerel minimum diyebilir misiniz? Diyemezsiniz."

Sonuç: $x = 0$ kritik nokta olduğu halde orada yerel ekstremum değer (uç değer) yoktur.

### 7.4 Not

Hoca şu notu yazdı:

- Uç değerler (extreme values) kritik noktalarda aranır.
- Ama $f$'nin her kritik noktada mutlak maksimum, mutlak minimum, yerel maksimum ya da yerel minimumu olmak zorunda değildir. Böyle bir zorunluluk yoktur.

## 8. Kapalı Aralıkta Uç Değerler: $x^4 - 2x^3$

**Örnek 4:** $f(x) = x^4 - 2x^3$ ve $[-2, 2]$ kapalı aralığı veriliyor.

- (a) $f$'nin $[-2, 2]$ üzerindeki bütün yerel ekstremum değerlerini inceleyin.
- (b) $f$'nin aynı aralıktaki mutlak ekstremum değerlerini inceleyin.

Hoca "Basit örneklerle başlayalım. İleride zor örnekler çözeceğiz" dedi.

**Çözüm:**

- **Tanım kümesi:** Kapalı $[-2, 2]$ aralığı.
- **Türev:**
  $$f'(x) = 4x^3 - 6x^2 = 2x^2(2x - 3).$$
  Hoca ortak çarpan olarak $x^2$ aldı. Türevi tanımsız yapan bir $x$ yoktur. Bu yüzden kritik noktalar yalnız $f'(x) = 0$ denkleminden gelir.
- **Kritik noktalar:** $c_1 = 0$ ve $c_2 = \dfrac{3}{2}$. İkisi de aralıktadır.
- **Uç noktalar:** Aralık kapalı olduğu için fonksiyonun uç noktalardaki değerleri de hesaplanır:
  - $f(-2) = 16 + 16 = 32$.
  - $f(2) = 16 - 16 = 0$.
- **Kritik noktalardaki değerler:**
  - $f(0) = 0$.
  - $f\!\left(\dfrac{3}{2}\right) = \dfrac{81}{16} - 2 \cdot \dfrac{27}{8} = \dfrac{81}{16} - \dfrac{108}{16} = -\dfrac{27}{16}$ (ara adım eklendi).
- **Karşılaştırma:**
  - Mutlak maksimum değeri $32$, $x = -2$'de.
  - Mutlak minimum değeri $-\dfrac{27}{16}$, $x = \dfrac{3}{2}$'de.

(sympy ile doğrulandı.)

Hoca uç noktalar için şunu söyledi: $-2$ ve $2$ noktalarında iki taraflı türev yoktur. Hoca bu noktaları da yerel ekstremum noktaları olarak saydı (Bölüm 5.3'teki ders sonrası nota bakın).

**Soru:** $x = 0$'ın bir yerel ekstremum değeri olduğunu nereden anlıyoruz? Bunun için grafiği çizip örneğin $f(0)$ yerel maksimum değeridir dememiz gerekmez mi? **Cevap:** Hoca önce "çünkü kritik nokta" dedi, sonra öğrencinin haklı olduğunu kabul etti. Bir noktanın ekstremum noktası olup olmadığını kontrol etmek için şu ana kadar bir teorem vermemişlerdi. Hoca bunun üzerine birinci türev testine geçti. Test, $x = 0$'da uç değer **olmadığını** gösterir (Bölüm 9.4).

## 9. Birinci Türev Testi

Hoca teoremi bir işaret tablosu üzerinde anlattı. $c$ bir kritik nokta olsun. Yani $f'(c) = 0$ ya da $f'(c)$ yok.

**Teorem (Ekstremum değerler için birinci türev testi):**

- **Durum 1:** $c$'nin solunda $f' > 0$, sağında $f' < 0$ ise $f$'nin $c$'de yerel maksimumu vardır.
- **Durum 2:** $c$'nin solunda $f' < 0$, sağında $f' > 0$ ise $f$'nin $c$'de yerel minimumu vardır.
- **Durum 3:** $f'$, $c$'de işaret değiştirmiyorsa ($+\,+$ ya da $-\,-$), $c$ kritik nokta olsa bile orada ekstremum değer yoktur.

### 9.1 Durum 1: $+ \to -$

$c$'nin solunda türev pozitiftir. Yani $f$, $-\infty$'dan $c$'ye kadar artandır. $c$'nin sağında türev negatiftir. Yani $f$, $c$'den $+\infty$'a kadar azalandır. Grafik önce çıkar, sonra iner. $c$'de bir tepe vardır: $f$'nin $c$'de yerel maksimum değeri vardır.

```
x     :      c
f'(x) :  +   |   -
f(x)  : artan  yerel max  azalan
```

Hoca iki tür grafiğe dikkat çekti. İkisiyle de karşılaşabilirsiniz:

- $y = -x^2$: tepe yumuşaktır, $f'(0) = 0$.
- $y = -|x|$: tepe sivridir, $f'(0)$ yoktur.

### 9.2 Durum 2: $- \to +$

$c$'nin solunda türev negatiftir, fonksiyon azalandır. Sağında türev pozitiftir, fonksiyon artandır. $c$'de bir çukur vardır: $f$'nin $c$'de yerel minimum değeri vardır.

```
x     :      c
f'(x) :  -   |   +
f(x)  : azalan  yerel min  artan
```

Yine iki tür grafik olabilir:

- $y = x^2$: $f'(0) = 0$.
- $y = |x|$: $f'(0)$ yok.

### 9.3 Durum 3: işaret değişmiyor

Hoca bu durumun "çok önemli" olduğunu söyledi. $c$ kritik nokta olsun. $c$'nin iki yanında türev aynı işaretli olsun ($+\,+$ ya da $-\,-$). Yani türev $c$'de işaret değiştirmez. O zaman $c$ kritik nokta olsa bile orada ekstremum değer yoktur.

**Örnek:** $f(x) = x^3$.

- $f'(x) = 3x^2$, $f'(0) = 0$: $x = 0$ kritik nokta.
- $0$'ın solunda da sağında da $f' > 0$.
- Bu yüzden $x = 0$'da yerel ekstremum değer yoktur.

### 9.4 Örnek 4'e uygulama

Hoca Bölüm 8'deki $f(x) = x^4 - 2x^3$ fonksiyonuna döndü.

$$f'(x) = 4x^3 - 6x^2 = x^2(4x - 6).$$

Hoca önce üç kritik nokta olduğunu söyledi, sonra düzeltti: iki kritik nokta vardır, $0$ ve $\dfrac{3}{2}$. İlk işaret tablosunda bir hata yaptı ($0$, $+$, $-$, $+$ yazdı). Sonra tabloyu çarpan çarpan yeniden kurdu:

| Aralık | $x < 0$ | $0 < x < \frac{3}{2}$ | $x > \frac{3}{2}$ |
|---|---|---|---|
| $x^2$ | $+$ | $+$ | $+$ |
| $4x - 6$ | $-$ | $-$ | $+$ |
| $f'(x)$ | $-$ | $-$ | $+$ |
| $f(x)$ | azalan | azalan | artan |

- **$x = 0$:** $x^2$ çarpanı çift kuvvetli olduğu için türev $0$'da işaret değiştirmez ($-\,-$). Bu yüzden $x = 0$'da ekstremum değer yoktur.
- **$x = \dfrac{3}{2}$:** Türev $-$'den $+$'ya geçer. Fonksiyon azalandan artana döner. Bu bir yerel minimum noktasıdır. Yerel minimum değeri $f\!\left(\dfrac{3}{2}\right) = -\dfrac{27}{16}$.

Hoca ayrıca "en yüksek dereceli terimin katsayısına bakın, pozitif" dedi. Bu, en sağdaki aralıkta türevin pozitif olacağını gösterir.

> **Ders sonrası not:** Hoca 02:11:27'de "Bu çift kuvvet yüzünden kritik nokta yok" dedi, hemen ardından "Pardon, ekstremum değer yok" diye düzeltti. Doğrusu: $x = 0$ kritik noktadır, ama orada ekstremum değer yoktur.

> **Hocanın vurgusu:** $0$ çift katlı kök olduğu için, yani kuvveti $2$, $4$, $6$ gibi çift olduğu için türev işaret değiştirmez. Ama kuvvet $x^3$ gibi tek olursa iş değişir. Ona dikkat edin.

> **Ek bilgi (derste anlatılmadı):** Genel kural şudur: $f'$'nin bir kökü tek katlıysa türev o kökte işaret değiştirir ve birinci türev testine göre orada uç değer vardır. Kök çift katlıysa türev işaret değiştirmez ve orada uç değer yoktur.

## 10. Artan-Azalan Aralıklar ve Yerel Uç Değer Örneği

**Örnek 5:** $f(x) = 3x^4 - 4x^3 - 6x^2 + 12x + 1$ veriliyor.

- (a) $f$'nin artan ya da azalan olduğu bütün aralıkları bulun.
- (b) Bütün ekstremum değerlerini (yerel maksimum, yerel minimum) bulun.

<!-- BELİRSİZ: 02:14:27'de altyazıda "x kare artı 3x, local max, local min" geçiyor; bu kısım altyazıda anlaşılmıyor. Fonksiyon 02:13:31'deki okumadan ve türevden kuruldu. -->

> **Hocanın vurgusu:** Bunlar konuyu özümsemek için basit örnekler. Fonksiyonun yapısı değiştirilerek test sınavında benzer bir soru sorulabilir. Sorunun yapısına odaklanın.

**Çözüm:**

- **Türev:**
  $$f'(x) = 12x^3 - 12x^2 - 12x + 12 = 12(x^3 - x^2 - x + 1).$$
- **Çarpanlara ayırma:** $x = 1$ bir köktür: $1 - 1 - 1 + 1 = 0$. Polinomu $x - 1$'e (ya da $(x-1)^2$'ye) bölerek:
  $$f'(x) = 12(x + 1)(x - 1)^2.$$
- **İşaret:** $(x - 1)^2$ çarpanının işaretini incelemeye gerek yoktur; hiçbir zaman negatif olmaz. Yalnız $x + 1$ çarpanına, yani $-1$ köküne odaklanılır:
  - $-1$'in solunda $f' < 0$.
  - $-1$'in sağında $f' > 0$ ($x = 1$'de türev sıfır olur ama işaret değişmez).
- **(a) Artan ve azalan aralıklar:**
  - $f$, $(-\infty, -1)$ aralığında azalandır.
  - $f$, $(-1, +\infty)$ aralığında artandır.
- **(b) Ekstremum değerler:**
  - $x = -1$'de türev $-$'den $+$'ya geçer. Bu bir yerel minimum noktasıdır.
  - Yerel minimum değeri:
    $$f(-1) = 3 + 4 - 6 - 12 + 1 = -10.$$
  - $x = 1$'de türev işaret değiştirmez. Orada ekstremum yoktur.
  - Yerel maksimum değeri yoktur.

(sympy ile doğrulandı: $f'(x) = 12(x-1)^2(x+1)$, $f(-1) = -10$.)

Hoca önce $-1$'i yanlışlıkla türev fonksiyonuna koydu ve $0$ buldu. Bir öğrenci "Hocam türev fonksiyonunu yerine yazdınız galiba" diye uyardı. Hoca "Haklısın" dedi ve $-1$'i $f$'nin kendisine koyarak yeniden hesapladı.

> **Ders sonrası not:** Altyazıda sonuç "7, 1, x on" diye geçiyor (02:21:14). Hoca büyük olasılıkla "eksi on" dedi. Doğru değer $f(-1) = -10$'dur.

Hoca "Basit bir soru. Biraz dikkat gerekiyor. İşlem hatası yapmamak gerekiyor" dedi.

## 11. Rolle Teoremi

### 11.1 Teorem

**Teorem (Rolle teoremi):** $f$ şu üç koşulu sağlayan bir fonksiyon olsun:

- $f$, kapalı $[a, b]$ aralığında süreklidir.
- $f$, açık $(a, b)$ aralığında türevlenebilirdir.
- Aralığın uç noktalarında fonksiyon aynı değeri alır: $f(a) = f(b)$.

O zaman $f'(c) = 0$ olacak şekilde **en az bir** $c \in (a, b)$ vardır.

Hoca koşulları grafik diliyle açıkladı:

- Süreklilik: grafiği elinizi kaldırmadan çizebilirsiniz.
- Türevlenebilirlik: grafikte kırılma noktası yoktur.

Hoca "$c$ açık aralıktadır, bu çok önemli" dedi.

### 11.2 Geometrik anlam

Hoca uçları aynı yükseklikte olan bir grafik çizdi. Grafik üzerinde türevin sıfır olduğu noktaları $c_1$, $c_2$ diye işaretledi. Bu noktalarda fonksiyonun yatay teğet doğrusu vardır. Teorem, böyle en az bir iç nokta olduğunu söyler.

### 11.3 Fiziksel yorum

Hoca teoremi bir araç örneğiyle anlattı. Bir aracınız $t = -1$ anından $t = 1$ anına kadar sürekli hareket ediyor. Araç "ralli yapmıyor", düzgün kullanılıyor. Yani konum grafiğinde kırılma yok. Araç başladığı konuma geri dönüyor. O zaman hareket sırasında öyle bir ara an bulabilirsiniz ki o anda aracın anlık hızı sıfırdır.

Hoca bunu İngilizce olarak da söyledi: $[a, b]$'de sürekli, $(a, b)$'de türevlenebilir bir fonksiyon için $f$'nin anlık değişim oranının (instantaneous rate of change) sıfır olduğu bir iç an $c$ vardır.

### 11.4 Örnek 6

**Soru:** $a$'nın hangi değeri için Rolle teoremi $f(x) = x^2 - ax$ fonksiyonuna $[-1, 1]$ aralığında uygulanabilir?

> **Hocanın vurgusu:** Basit bir örnek, ama soru yapısı önemli. Fonksiyonun yapısı değiştirilerek soru daha karmaşık hale getirilebilir. Belki öyle bir $a$ değeri bulunmayacak; böyle bir $a$ olmak zorunda değil.

**Çözüm:**

- **Birinci koşul (süreklilik):** $f$ her $a$ için bir polinomdur. Polinomlar her yerde süreklidir. Bu yüzden $f$, $[-1, 1]$'de süreklidir.
- **İkinci koşul (türevlenebilirlik):** $f'(x) = 2x - a$. Türev her yerde vardır. Bu yüzden $f$, $(-1, 1)$'de türevlenebilirdir.
- **Üçüncü koşul (uç değerler eşit):**
  - $f(-1) = (-1)^2 - a(-1) = 1 + a$.
  - $f(1) = 1 - a$.
  - $1 + a = 1 - a \Rightarrow a = 0$.
- **Teoremin uygulanması:** $a = 0$ için $f(x) = x^2$ olur. $f'(x) = 2x$.
  $$f'(c) = 2c = 0 \Rightarrow c = 0.$$
  $c = 0$, verilen açık aralıktadır: $0 \in (-1, 1)$.

**Sonuç:** $a = 0$. Teoremin verdiği nokta $c = 0$. (sympy ile doğrulandı.)

> **Ders sonrası not:** Altyazıda $f(-1)$ için "1 minus 1 plus a, sorry" geçiyor (02:31:05). Doğrusu $f(-1) = 1 + a$'dır. Hoca da sonuçta bunu kullandı.

Hoca bir an "tanım kümesindedir" dedi, sonra düzeltti: $c$ tanım kümesinde değil, verilen açık aralıkta olmalıdır.

## 12. Ortalama Değer Teoremi

### 12.1 Teorem

**Teorem (Ortalama değer teoremi):** $f$ şu iki koşulu sağlasın:

- $f$, kapalı $[a, b]$ aralığında süreklidir.
- $f$, açık $(a, b)$ aralığında türevlenebilirdir.

O zaman

$$f'(c) = \frac{f(b) - f(a)}{b - a}$$

olacak şekilde **en az bir** $c \in (a, b)$ vardır.

Hoca burada da bir an "tanım kümesinde" ve "kapalı aralıkta" dedi, sonra ikisini de düzeltti: $c$ açık $(a, b)$ aralığındadır.

### 12.2 İki tarafın anlamı

- **Sol taraf** $f'(c)$: $f$'nin $c$ anındaki anlık değişim oranıdır (instantaneous rate of change).
- **Sağ taraf** $\dfrac{f(b) - f(a)}{b - a}$: $f$'nin $[a, b]$ kapalı aralığı üzerindeki ortalama değişim oranıdır (average rate of change).

### 12.3 Fiziksel yorum

Hoca yine bir araç örneği verdi. Bir aracınız $[a, b]$ zaman aralığında sürekli hareket ediyor. Konum grafiğinde kırılma noktası yok. Yani her iç anda anlık hızı hesaplayabiliyorsunuz. Başladığı ve bitirdiği anlar bu iç anlara dahil değildir. O zaman aracın anlık hızının, $[a, b]$ üzerindeki ortalama hızına eşit olduğu en az bir iç $c$ anı vardır.

Hoca "Ortalama değer teoremini uygulamak demek, anlık hızın ortalama hıza eşit olduğu $c$ ara zamanlarını bulmak demektir" dedi.

### 12.4 Örnek 7

**Soru:** Ortalama değer teoremini $f(x) = x^3 - x^2 + 1$ fonksiyonuna $[-1, 1]$ aralığında uygulayın. Hangi $x$ değerinde anlık hız ortalama hıza eşit olur?

<!-- BELİRSİZ: Fonksiyon altyazıda sözlü okunmuyor (02:37:48). Türevin $3c^2 - 2c$ olması, $f(1) = 1$ ve "eksi 1" ifadesi (02:41:14) fonksiyonu $x^3 - x^2 + 1$ olarak destekliyor. Sabit terim kesin okunamadı; sonuç ($c$ değeri) sabitten bağımsızdır. -->

**Çözüm:**

- **Koşullar:** $f$ bir polinomdur. $[-1, 1]$'de süreklidir, $(-1, 1)$'de türevlenebilirdir.
- **Uç değerler:**
  - $f(1) = 1 - 1 + 1 = 1$.
  - $f(-1) = -1 - 1 + 1 = -1$.
- **Ortalama değişim oranı:**
  $$\frac{f(1) - f(-1)}{1 - (-1)} = \frac{1 - (-1)}{2} = 1.$$
- **Türev:** $f'(x) = 3x^2 - 2x$.
- **Denklem:**
  $$f'(c) = 3c^2 - 2c = 1 \Rightarrow 3c^2 - 2c - 1 = 0.$$
- **Çarpanlara ayırma:** Hoca katsayıların işaretini bir iki kez denedi, sonra şu çarpanlamaya ulaştı:
  $$(3c + 1)(c - 1) = 0.$$
- **Kökler:** $c_1 = -\dfrac{1}{3}$, $c_2 = 1$.
- **Aralık kontrolü:** $c_2 = 1$ açık $(-1, 1)$ aralığında değildir. $c_1 = -\dfrac{1}{3}$ ise açık aralıktadır.

**Sonuç:** $c = -\dfrac{1}{3}$. Bu anda anlık hız ortalama hıza eşittir. (sympy ile doğrulandı.)

Bir öğrenci hocanın kullandığı dosyayı paylaşmasını istedi. Hoca, benzer örneklerin daha önce paylaştığı kitapta olduğunu ve ileride bol örnek çözeceklerini söyledi.

### 12.5 Geometrik yorum

Hoca teoremin temel fikrini bir grafik üzerinde gösterdi ve "Bunu ezberlemenize gerek yok. Grafik bize her şeyi anlatıyor" dedi.

- Yatay eksen zaman, dikey eksen bir aracın konumu olsun.
- Grafiğin $(a, f(a))$ ve $(b, f(b))$ uç noktalarını bir doğru parçasıyla birleştirelim. Bu doğru parçası, kenarları $b - a$ ve $f(b) - f(a)$ olan bir dik üçgenin hipotenüsüdür.
- Hipotenüsün eğimi:
  $$\tan\theta = \frac{f(b) - f(a)}{b - a}.$$
  Bu, ortalama hızdır.
- Grafik kapalı aralıkta süreklidir ve içeride kırılma yoktur. Bu yüzden en az bir iç noktada teğet doğrusu bu hipotenüse paraleldir.

Hoca grafikte bu tür iki iç nokta işaretledi ve oradaki teğetleri mavi renkle çizdi. Bu teğetlerin eğimi hipotenüsün eğimine eşittir. Yani o anlarda anlık hız ortalama hıza eşittir.

### 12.6 Rolle teoremi ile ilişkisi

Rolle teoremi, ortalama değer teoreminin özel bir durumudur. $f(a) = f(b)$ ise sağ taraf sıfır olur ve $f'(c) = 0$ elde edilir (ara adım eklendi). Geometrik olarak hipotenüs yatay olur, paralel teğet de yatay teğettir.

## 13. Parçalı Fonksiyonda Ortalama Değer Teoremi

**Örnek 8:** $a$'nın hangi değeri için ortalama değer teoremi

$$f(x) = \begin{cases} \dfrac{e^{ax} - 1}{x}, & x \neq 0 \\[2mm] 1, & x = 0 \end{cases}$$

fonksiyonuna $[-1, 1]$ aralığında uygulanabilir?

> **Hocanın vurgusu:** Soru yalnız $a$'nın değerini istiyor; teoremi uygulayın demiyor. Test sınavında böyle sorularla karşılaşabilirsiniz.

### 13.1 Birinci koşul: süreklilik

$x \neq 0$ için $f$ sürekli fonksiyonların bölümüdür. Sorun yalnız $x = 0$ noktasındadır (ara adım eklendi). $f$'nin $0$'da sürekli olması için uygun $a$ değerini bulmalıyız. Sürekliliğin tanımına göre:

$$\lim_{x \to 0} \frac{e^{ax} - 1}{x} = f(0) = 1$$

olmalıdır.

- Limit $\dfrac{0}{0}$ belirsiz formundadır.
- L'Hôpital kuralı ile pay ve paydanın türevi alınır:
  $$\lim_{x \to 0} \frac{a e^{ax}}{1} = a.$$
- Bu limit $1$'e eşit olmalıdır: $a = 1$.

Süreklilik için $a = 1$ olmalıdır. Ama hoca bunun **gerek koşul olduğunu, yeterli olmadığını** vurguladı. İkinci koşul da kontrol edilmelidir.

### 13.2 İkinci koşul: türevlenebilirlik

$a = 1$ alalım. $f$'nin $(-1, 1)$'de türevlenebilir olduğunu göstermeliyiz.

- $x \neq 0$ için türev doğrudan bölüm kuralıyla alınabilir.
- $x = 0$'da ise türev formülüne $0$ konamaz, çünkü $\dfrac{1}{x}$ terimi $0$'da tanımsızdır. Bu yüzden türevin limit tanımı kullanılır:
  $$f'(0) = \lim_{x \to 0} \frac{f(x) - f(0)}{x - 0}.$$

Hesap:

$$f'(0) = \lim_{x \to 0} \frac{\dfrac{e^x - 1}{x} - 1}{x} = \lim_{x \to 0} \frac{e^x - 1 - x}{x^2}.$$

- Bu yine $\dfrac{0}{0}$ belirsiz formudur.
- L'Hôpital kuralı: payın türevi $e^x - 1$ (çünkü $-1$'in türevi $0$, $-x$'in türevi $-1$), paydanın türevi $2x$:
  $$\lim_{x \to 0} \frac{e^x - 1}{2x}.$$
- Bu da $\dfrac{0}{0}$'dır. L'Hôpital kuralı bir kez daha:
  $$\lim_{x \to 0} \frac{e^x}{2} = \frac{1}{2}.$$

Limit vardır: $f'(0) = \dfrac{1}{2}$. Bu yüzden $f$, $(-1, 1)$'de türevlenebilirdir.

**Sonuç:** $a = 1$. (sympy ile doğrulandı: süreklilik limiti $a$, $f'(0) = \dfrac{1}{2}$.)

**Soru:** Türevlenebilirliği kanıtlamak için sağ türevi ve sol türevi ayrı ayrı mı hesaplamalıyız? **Cevap:** Türevi doğrudan alamazsınız, türevin limit tanımını kullanmalısınız. Ama burada sağ ve sol diye ayırmaya gerek yok, çünkü iki tarafta da aynı kural ($\frac{e^x - 1}{x}$) geçerli. Tek bir limit yazmak yeterli.

**Soru:** Neden doğrudan türev alıp $x = 0$'ı türev fonksiyonuna koyamıyoruz? **Cevap:** $\dfrac{1}{x}$ terimi yüzünden $x = 0$ konamaz; $\dfrac{1}{0}$ tanımlı değildir.

### 13.3 Teoremin uygulanması (ödev)

Ortalama değer teoremine göre öyle bir iç $c$ anı vardır ki $f'(c)$ ortalama değişim oranına eşittir. Bunun için önce türev fonksiyonu kurulur:

$$f'(x) = \begin{cases} \dfrac{e^x \cdot x - (e^x - 1)}{x^2}, & x \neq 0 \\[2mm] \dfrac{1}{2}, & x = 0 \end{cases}$$

Ortalama değişim oranı için uç değerler:

- $f(1) = e - 1$.
- $f(-1) = \dfrac{e^{-1} - 1}{-1} = 1 - e^{-1}$ (ara adım eklendi).

Bu yüzden iki durum incelenir:

- **Birinci durum ($c \neq 0$):**
  $$\frac{e^c c - e^c + 1}{c^2} = \frac{(e - 1) - (1 - e^{-1})}{2}.$$
- **İkinci durum ($c = 0$):** $f'(0) = \dfrac{1}{2}$ sağ tarafa eşit mi diye bakılır.

Hoca bu kısmı ödev olarak bıraktı. $c$ değerini bulmak hesap makinesi gerektirir. Bu yüzden test sınavında yalnız $a$ sorulur.

<!-- BELİRSİZ: 02:57:09'da $f(-1)$ için "explanation minus 1, minus 1" geçiyor; hocanın yazdığı tam ifade altyazıda anlaşılmıyor. Yukarıdaki $f(-1) = 1 - e^{-1}$ fonksiyonun tanımından hesaplandı. -->

> **Hocanın vurgusu:** Test sınavında yalnız süreklilikten $a = 1$ bulup işaretlemeyin. Bağlantı noktasında türevlenebilirliği de kontrol etmek zorundasınız. Fonksiyon orada türevlenemeyebilir. Şıklarda ya "$a = 1$" yazar ya da "öyle bir $a$ değeri yoktur" yazar. Cevap "öyle bir $a$ değeri olamaz" da olabilir. Böyle bir hataya düşmeyin.

Hoca dersi bir uygulama benzetmesiyle bağladı: İleride bir şirkette, şirketin o andaki başarı oranının ortalama başarı oranına eşit olduğu bir anı bulmanız istenebilir. Karşınıza böyle üstel bir fonksiyon çıkabilir. O zaman bunu hesaplamak zorunda kalırsınız; mühendis olan sizsiniz.

> **Ek bilgi (derste anlatılmadı):** Ortalama değişim oranı sadeleşince $\dfrac{e - 2 + e^{-1}}{2} = \cosh 1 - 1$ olur. Bu, hiperbolik kosinüs tanımından ($\cosh x = \frac{e^x + e^{-x}}{2}$) doğrudan görülür. Sayısal değeri yaklaşık $0{,}5431$'dir.

## 14. Örnek Sorular

Bu derste ekran görüntüsü kullanılmadı. Aşağıdaki sorular derste sözlü olarak sorulan ya da öğrencilere çözdürülen sorulardır.

**Soru 1** (derste sözlü, 01:21:22): Verilen fonksiyonun bütün kritik noktalarını bulun.

<!-- BELİRSİZ: Fonksiyon sözlü okunmuyor; türevden $f(x) = x + \dfrac{1}{x}$ olduğu anlaşılıyor. -->

> **Çözüm (derste verildi):** $D(f) = \mathbb{R} \setminus \{0\}$. $f'(x) = \dfrac{x^2 - 1}{x^2}$. Kritik noktalar $x = -1$ ve $x = 1$. $0$ tanım kümesinde olmadığı için kritik nokta değildir.

**Soru 2** (derste sözlü, 01:39:36): $f(x) = x^4 - 2x^3$ için (a) $[-2, 2]$ üzerindeki yerel ekstremum değerlerini, (b) aynı aralıktaki mutlak ekstremum değerlerini inceleyin.

> **Çözüm (derste verildi):** Kritik noktalar $0$ ve $\dfrac{3}{2}$. $f(-2) = 32$, $f(2) = 0$, $f(0) = 0$, $f\!\left(\frac{3}{2}\right) = -\frac{27}{16}$. Mutlak maksimum $32$ ($x = -2$), mutlak minimum $-\frac{27}{16}$ ($x = \frac{3}{2}$). Birinci türev testine göre $x = \frac{3}{2}$ yerel minimum; $x = 0$'da uç değer yok.

**Soru 3** (derste sözlü, 02:13:31): $f(x) = 3x^4 - 4x^3 - 6x^2 + 12x + 1$ için (a) $f$'nin artan ve azalan olduğu aralıkları, (b) yerel ekstremum değerlerini bulun.

> **Çözüm (derste verildi):** $f'(x) = 12(x + 1)(x - 1)^2$. $(-\infty, -1)$'de azalan, $(-1, \infty)$'da artan. $x = -1$'de yerel minimum, değer $-10$. Yerel maksimum yok.

**Soru 4** (derste sözlü, 02:28:54): $a$'nın hangi değeri için Rolle teoremi $f(x) = x^2 - ax$ fonksiyonuna $[-1, 1]$ aralığında uygulanabilir?

> **Çözüm (derste verildi):** $f(-1) = f(1) \Rightarrow 1 + a = 1 - a \Rightarrow a = 0$. $f'(c) = 2c = 0 \Rightarrow c = 0 \in (-1, 1)$.

**Soru 5** (derste sözlü, 02:37:32): Ortalama değer teoremini $f(x) = x^3 - x^2 + 1$ fonksiyonuna $[-1, 1]$ aralığında uygulayın. Hangi $x$ değerinde anlık hız ortalama hıza eşit olur?

<!-- BELİRSİZ: Fonksiyonun sabit terimi altyazıdan kesin okunamadı; $c$ değeri sabitten bağımsızdır. -->

> **Çözüm (derste verildi):** Ortalama değişim oranı $1$. $3c^2 - 2c - 1 = 0 \Rightarrow (3c + 1)(c - 1) = 0$. Açık aralıktaki kök $c = -\dfrac{1}{3}$.

**Soru 6** (derste sözlü, 02:48:14): $a$'nın hangi değeri için ortalama değer teoremi $f(x) = \dfrac{e^{ax} - 1}{x}$ ($x \neq 0$), $f(0) = 1$ fonksiyonuna $[-1, 1]$ aralığında uygulanabilir?

> **Çözüm (derste verildi):** Süreklilik: $\lim_{x \to 0} \frac{e^{ax} - 1}{x} = a = 1$. Türevlenebilirlik: $f'(0) = \lim_{x \to 0} \frac{e^x - 1 - x}{x^2} = \frac{1}{2}$, limit var. Cevap $a = 1$.

**Soru 7** (derste sözlü, 02:56:41, ödev): Soru 6'daki fonksiyon için ($a = 1$) ortalama değer teoreminin verdiği $c$ değerini bulun.

> **Çözüm (derste verilmedi):** Ortalama değişim oranı $\dfrac{(e - 1) - (1 - e^{-1})}{2} = \cosh 1 - 1 \approx 0{,}5431$. $f'(0) = \frac{1}{2} \neq 0{,}5431$ olduğu için $c \neq 0$. $\dfrac{c\,e^c - e^c + 1}{c^2} = \cosh 1 - 1$ denklemi sayısal olarak çözülünce $c \approx 0{,}1233$ bulunur. Bu değer $(-1, 1)$ aralığındadır. (sympy `nsolve` ile farklı başlangıç noktalarından aynı kök bulundu.)

## Dersin Toparlaması

Bu derste türevin uygulamalarına giriş yapıldı. Önce mutlak maksimum ve minimum tanımlandı. Mutlak uç değerin tek, onu veren noktanın ise birden fazla olabileceği vurgulandı. Uç değer teoremi, kapalı aralıkta sürekli bir fonksiyonun mutlak maksimum ve minimum değerlerinin var olduğunu garanti eder. Kapalılık ya da süreklilik bozulursa garanti kalkar; $(0, 2]$ üzerinde $x^2$ ve $(0, \pi)$ üzerinde $\sin x$ örnekleri bunu gösterdi. Ardından yerel uç değerler açık aralık üzerinden tanımlandı ve kritik nokta kavramı verildi. Kritik nokta için noktanın tanım kümesinde olması ön koşuldur; $x + \frac{1}{x}$ örneğinde $0$ bu yüzden kritik nokta değildir.

Yerel uç değerler kritik noktalarda aranır, ama her kritik noktada uç değer yoktur ($x^3$ örneği). Bir kritik noktada uç değer olup olmadığına birinci türev testiyle karar verilir: türev $+ \to -$ geçerse yerel maksimum, $- \to +$ geçerse yerel minimum vardır, işaret değişmezse uç değer yoktur. Son olarak Rolle teoremi ve onun genellemesi olan ortalama değer teoremi verildi. İkisinde de koşullar kapalı aralıkta süreklilik ve açık aralıkta türevlenebilirliktir; parçalı fonksiyonlarda bağlantı noktasındaki türevlenebilirliğin limit tanımıyla ayrıca kontrol edilmesi gerekir. Hoca, sonraki derslerde bu konularla ilgili bol örnek çözeceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
