# Ders 12 Genişletilmiş Notu: Proje Gösterimleri (1. Hafta)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu kayıtta yeni konu işlenmedi. Ders saati proje gösterimlerine ayrıldı. Hoca gösterimlerde programlara kendi seçtiği girdileri verdi ve sonuçları kendi çözümleriyle karşılaştırdı. Bu not yalnız o girdilerin çözümünü ve hocanın gösterim sırasında yaptığı akademik düzeltme ve açıklamaları içerir.

## İçindekiler

- 1. Newton-Raphson: Başlangıç Değeri ve Durma Koşulu
- 2. Sayısal Türev
- 3. Matrisin Tersi
- 4. Simpson ve Polinomun Programa Girilmesi
- 5. Gauss Eliminasyon
- 6. Gregory-Newton Enterpolasyonu
- 7. $x$ Sıfırdan Başlamadığında ve Aralıklar Eşit Olmadığında
- 8. Regula Falsi ve Üç Ayrı Durma Koşulu
- 9. Üçüncü Dereceden Polinomda Newton-Raphson

## 1. Newton-Raphson: Başlangıç Değeri ve Durma Koşulu

### 1.1 Alt ve Üst Sınır Gerekir mi?

Bir programda polinom girildikten sonra alt ve üst sınır soruluyordu. Hoca, Newton-Raphson'da bir başlangıç değeri olduğunu hatırlatıp neden aralık istendiğini sordu.

**Soru:** Newton-Raphson niye alt ve üst sınır istiyor? **Cevap:** Bir öğrenci, ders notunda aralık alındığını ve iterasyonun alt sınırdan başlatıldığını gördüğü için üst sınırı da aldığını, ama fonksiyonda kullanmadığını söyledi. Hoca kendi notlarında öyle bir şey olmadığını söyledi ve notlarına bakacağını belirtti. Konu kayıtta kapanmadı.

> **Ders sonrası not:** Ders 3 notunda Newton-Raphson için bir $[a, b]$ aralığının verilebildiği ve bir örnekte başlangıç değeri verilmediği için aralığın en küçük değerinin $x_0$ alındığı yazılıdır. Yani aralık yalnız başlangıç değerini seçmeye yarar. Formülde yalnız bir $x_k$ değeri kullanılır, üst sınır hiç girmez:
> $$x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}$$

Hoca koda bakarken türevin dışarıdan mı verileceğini de sordu. Bu programda polinomun değerini hesaplayan ve türevini alan ayrı fonksiyonlar yazılmış, Newton-Raphson fonksiyonu bunları çağırıyordu.

### 1.2 Durma Koşulu

Aynı programda ayrıca maksimum iterasyon sayısı soruluyordu. Hoca bunu sorguladı.

> **Hocanın vurgusu:** Durma koşulu, arka arkaya bulunan kökler arasındaki mutlak farkın $\varepsilon$'dan küçük eşit olmasıdır: $|x_{k+1} - x_k| \le \varepsilon$. "Her zaman şunu söylüyordum."

**Soru:** Ben 10 bin iterasyon desem, belki 100 iterasyonda koşul sağlanacak. Boşuna 10 bine kadar mı dönüyor? **Cevap:** Bir öğrenci, programın hangi koşul önce sağlanırsa orada çıktığını, hatanın ilk sağlandığı yerde döngüden çıktığını söyledi.

> **Ders sonrası not:** Hocanın itirazı, $\varepsilon$ kontrolü yapmadan iterasyon sayısı kadar dönen kod için geçerlidir. Hem $\varepsilon$ kontrolü hem üst sınır olan döngüde boşuna dönüş olmaz. Ders 3'te yöntemin ıraksayabileceği söylenmişti. Üst sınır büyük olasılıkla bu durumda döngünün sonsuza gitmesini engeller. Ölçüt yine ardışık kök farkıdır.

### 1.3 Örnek: $x^2 - 4x - 5$

**Verilen:** $f(x) = x^2 - 4x - 5$, $\varepsilon = 0.001$. Türev $f'(x) = 2x - 4$. Köklerden birini bulmak için $x_0 = 0$, öbürünü bulmak için $x_0 = 6$ verildi. Hoca sonuçlar için "köklerden biri eksi bir", "beşi buldu, doğru" dedi. Gerçekten $x^2 - 4x - 5 = (x - 5)(x + 1)$'dir.

**$x_0 = 0$ için (ara adımlar eklendi, Python ile hesaplandı):**

| $k$ | $x_k$ | $f(x_k)$ | $f'(x_k)$ | $x_{k+1}$ | $\lvert x_{k+1} - x_k \rvert$ |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | $-5$ | $-4$ | $-1.25$ | 1.25 |
| 1 | $-1.25$ | 1.5625 | $-6.5$ | $-1.009615$ | 0.240385 |
| 2 | $-1.009615$ | 0.057785 | $-6.019231$ | $-1.000015$ | 0.009600 |
| 3 | $-1.000015$ | 0.000092 | $-6.000031$ | $-1.000000$ | 0.000015 |

**$x_0 = 6$ için (ara adımlar eklendi, Python ile hesaplandı):**

| $k$ | $x_k$ | $f(x_k)$ | $f'(x_k)$ | $x_{k+1}$ | $\lvert x_{k+1} - x_k \rvert$ |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 6 | 7 | 8 | 5.125 | 0.875 |
| 1 | 5.125 | 0.765625 | 6.25 | 5.0025 | 0.1225 |
| 2 | 5.0025 | 0.015006 | 6.005 | 5.000001 | 0.002499 |
| 3 | 5.000001 | 0.000006 | 6.000002 | 5.000000 | 0.000001 |

İkinci çalıştırma derste de dördüncü iterasyonda 5 sonucunu verdi. Bu, tabloyla uyumludur.

> **Ders sonrası not:** İlk çalıştırmada altyazıda "ikinci iterasyonda" çıkıldığı geçiyor, hoca da bunu kökü başlangıç değeri olarak vermesine bağladı. Oysa hocanın verdiği $x_0 = 0$ kök değildir, $f(0) = -5$'tir. Python ile hesaplandı: $\varepsilon = 0.001$ ve $|x_{k+1} - x_k| \le \varepsilon$ ile $x_0 = 0$'dan başlayınca dördüncü iterasyonda durulur. İkinci iterasyonda çıkılmaz.

<!-- BELİRSİZ: İlk çalıştırmanın ekran çıktısı ve "ikinci iterasyon" ifadesinin neyi gösterdiği altyazıda net değil. -->

> **Ek bilgi (derste anlatılmadı):** Hangi kökün bulunacağını burada türevin sıfır olduğu $x = 2$ noktası ayırır. $x_0 < 2$ için $-1$, $x_0 > 2$ için 5 bulunur. Bu, Python ile $-10$ ile 14 arasında 0.01 adımla denendi. $x_0 = 2$'de türev sıfır olduğu için formül uygulanamaz.

## 2. Sayısal Türev

Hoca aynı programda sayısal türevi denedi. Altyazıda polinomun derecesi 3 olarak söyleniyor, katsayılar "bir, bir, eksi iki, eksi bir, eksi bir" diye geçiyor. Verilen nokta $x = 1$, $h = 0.25$, sonuç $-1.6875$ idi.

Python ile hesaplandı: Bu sonuç $f(x) = x^3 - 2x^2 - x - 1$ polinomunun ileri farkına eşittir. Sabit terim sonucu etkilemez.

$$f(1) = -3, \quad f(1.25) = -3.421875$$

$$f'(1) \approx \frac{f(1.25) - f(1)}{0.25} = \frac{-0.421875}{0.25} = -1.6875$$

Analitik türev $f'(x) = 3x^2 - 4x - 1$ olduğundan $f'(1) = -2$'dir. Aynı veriyle geri fark $-2.1875$, merkezi fark $-1.9375$ verir (Python ile hesaplandı). Hoca sonucu kendi örnek çözümüyle karşılaştırdı. Altyazıda bu değer için "birazcık fazla" gibi bir ifade geçiyor, sonra hoca başka bir programda da aynısını soracağını söyledi.

<!-- BELİRSİZ: Polinomun katsayıları ve hangi farkın seçildiği altyazıdan okunmuyor. Polinom ve ileri fark, sonucun tutmasından çıkarıldı. "Birazcık fazla" ifadesi de bozuk. -->

## 3. Matrisin Tersi

Hoca tersin nasıl alındığını sordu.

**Soru:** Tersini alırken nasıl bir yol izliyorduk? **Cevap:** Birim matris kullanılır. Orijinal matris birim matris hâline getirilirken birim matris de ters matrise dönüşür.

Bu, Ders 4'te görülen Gauss-Jordan yoludur: $[A \mid I] \to [I \mid A^{-1}]$.

**Verilen:**

$$A = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}$$

**Birinci sütun.** $R_2 \leftarrow R_2 - 4R_1$, $R_3 \leftarrow R_3 - 7R_1$ (ara adımlar eklendi):

$$\left[\begin{array}{ccc|ccc} 1 & 2 & 3 & 1 & 0 & 0 \\ 0 & -3 & -6 & -4 & 1 & 0 \\ 0 & -12 & -12 & -7 & 0 & 1 \end{array}\right]$$

**İkinci sütun.** $R_2 \leftarrow R_2 / (-3)$, sonra $R_1 \leftarrow R_1 - 2R_2$, $R_3 \leftarrow R_3 + 12R_2$:

$$\left[\begin{array}{ccc|ccc} 1 & 0 & -1 & -5/3 & 2/3 & 0 \\ 0 & 1 & 2 & 4/3 & -1/3 & 0 \\ 0 & 0 & 12 & 9 & -4 & 1 \end{array}\right]$$

**Üçüncü sütun.** $R_3 \leftarrow R_3 / 12$, sonra $R_1 \leftarrow R_1 + R_3$, $R_2 \leftarrow R_2 - 2R_3$:

$$\left[\begin{array}{ccc|ccc} 1 & 0 & 0 & -11/12 & 1/3 & 1/12 \\ 0 & 1 & 0 & -1/6 & 1/3 & -1/6 \\ 0 & 0 & 1 & 3/4 & -1/3 & 1/12 \end{array}\right]$$

**Sonuç (Python ile hesaplandı):**

$$A^{-1} = \begin{bmatrix} -11/12 & 1/3 & 1/12 \\ -1/6 & 1/3 & -1/6 \\ 3/4 & -1/3 & 1/12 \end{bmatrix} \approx \begin{bmatrix} -0.9167 & 0.3333 & 0.0833 \\ -0.1667 & 0.3333 & -0.1667 \\ 0.75 & -0.3333 & 0.0833 \end{bmatrix}$$

Hocanın kontrol ederken okuduğu $1/12$, $0.75$, $1/6$ ve $0.08$ değerleri bu sonuçla uyumludur.

<!-- BELİRSİZ: Hocanın okuduğu değerlerin işaretleri ve sırası altyazıda net değil ("03, 1 bölü 12, 0,75, 16, 1 bölü 6, 0,08"). -->

## 4. Simpson ve Polinomun Programa Girilmesi

### 4.1 Girdi Ne Soruluyor?

Simpson gösteriminde program polinomun terim sayısını soruyordu. Hoca soruyu önce derece sandı, sonra katsayıların nasıl girileceğini anlamakta zorlandı. Benzer karışıklık sonraki gösterimlerde de oldu. Aynı $x^2 - 4x - 5$ polinomu iki farklı biçimde girilebiliyordu:

- **Derece ve katsayılar:** Derece 2, katsayılar büyük dereceden küçüğe $1, -4, -5$.
- **Terim sayısı ve (üs, katsayı) çiftleri:** 3 terim, $(2, 1)$, $(1, -4)$, $(0, -5)$. Her çift üssüyle girildiği için terimlerin sırası önemli değildir.

Hoca ikinci biçimde sıranın önemli olup olmadığını sordu: "Nasıl fark etmiyor? Nasıl ondan sonra yerleştiriyorsun?" Cevap, her katsayının üssüyle birlikte alınmasıydı. Bu yüzden program neyi sorduğunu açık yazmazsa kullanan kişi derece mi, terim sayısı mı, katsayı mı girdiğini anlayamaz. Hoca bunu kural olarak söylemedi, ama gösterimlerde birkaç kez "benden ne istiyorsun?" diye sordu.

### 4.2 Örnek: $\int_1^3 (x^2 + 2x)\,dx$, $n = 6$

Programda Simpson'ın 1/3 seçeneği seçildi. Hoca sonucu "16.66" olarak doğruladı. Ara adımlar eklendi:

$$h = \frac{3 - 1}{6} = \frac{1}{3}$$

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| $x_i$ | 1 | 4/3 | 5/3 | 2 | 7/3 | 8/3 | 3 |
| $f(x_i)$ | 3 | 4.4444 | 6.1111 | 8 | 10.1111 | 12.4444 | 15 |

$$I \approx \frac{h}{3}\Big[f_0 + 4(f_1 + f_3 + f_5) + 2(f_2 + f_4) + f_6\Big]$$

$$I \approx \frac{1}{9}\Big[3 + 4(24.8889) + 2(16.2222) + 15\Big] = \frac{150}{9} = 16.6667$$

> **Ek bilgi (derste anlatılmadı):** Analitik sonuç $\left[\frac{x^3}{3} + x^2\right]_1^3 = \frac{50}{3}$'tür, Simpson sonucuyla aynıdır (Python ile hesaplandı). Ders 6'da Simpson 1/3'ün ikinci dereceden polinom geçirdiği görülmüştü. İntegrand zaten ikinci dereceden olduğu için burada yöntem hatası oluşmaz. Altyazıdaki 16.66 değeri kesilmiş, 16.67 yuvarlanmış yazımdır.

## 5. Gauss Eliminasyon

**Verilen:**

$$2x_1 + 5x_2 = 16, \qquad 3x_1 + x_2 = 11$$

Hoca sonuç sorarken önce başlangıç değerlerini sordu.

**Soru:** Başlangıç değerlerini sormadın, ne aldın? **Cevap:** Eliminasyonda başlangıç değeri alınmaz. Hoca, Gauss-Seidel'in sonucuna baktığını söyleyip düzeltti. Başlangıç değeri, Ders 5'teki Gauss-Seidel gibi iteratif yöntemlerde gerekir.

**Çözüm (ara adımlar eklendi).** $R_2 \leftarrow R_2 - \frac{3}{2}R_1$:

$$\left(1 - \frac{15}{2}\right)x_2 = 11 - 24 \quad\Rightarrow\quad -\frac{13}{2}x_2 = -13 \quad\Rightarrow\quad x_2 = 2$$

Geri yerine koyma:

$$2x_1 + 5(2) = 16 \quad\Rightarrow\quad x_1 = 3$$

Hoca $x_1 = 3$, $x_2 = 2$ sonucunu doğruladı.

## 6. Gregory-Newton Enterpolasyonu

**Verilen:** 7 nokta. Aranan değer $x = 4.5$. Program 233.375 buldu.

| $x$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| $f(x)$ | $-4$ | $-2$ | 14 | 62 | 160 | 326 | 578 |

**Fark tablosu (ara adımlar eklendi, Python ile hesaplandı).** Üçüncü farklar sabittir, dördüncü farklar sıfırdır:

| $\Delta f$ | 2 | 16 | 48 | 98 | 166 | 252 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| $\Delta^2 f$ | 14 | 32 | 50 | 68 | 86 | |
| $\Delta^3 f$ | 18 | 18 | 18 | 18 | | |

$x_0 = 0$ ve $h = 1$ olduğu için en basit formül kullanılır:

$$F(x) = f_0 + x\,\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0$$

$$F(4.5) = -4 + 4.5(2) + 7.875(14) + 6.5625(18) = -4 + 9 + 110.25 + 118.125 = 233.375$$

Hoca denklemin de görülüp görülemeyeceğini sordu. Program yalnız sonucu yazıyordu. Formül açılırsa (ara adım eklendi):

$$F(x) = -4 + 2x + 7x(x-1) + 3x(x-1)(x-2) = 3x^3 - 2x^2 + x - 4$$

## 7. $x$ Sıfırdan Başlamadığında ve Aralıklar Eşit Olmadığında

Hoca bir sonraki gösterimde özellikle şunu sordu: "$x$ sıfırdan başlamasa çözebiliyor musun?" 1891'den başlayan 5 $x$ değeri verdi. $y$ değerleri 46, 66, 81, 93, 101, aranan nokta 1895 idi.

Program bir $h$ değeri ve $x$ sayısı alıyordu, yani $x$'lerin hepsini sormuyordu. Hoca buna itiraz etti: "Ama ben $h$ değerimi sabit bırakmadım ki." Bir öğrenci değişken dönüşümünü andı, hoca aralıkların hepsinin aynı olmadığını söyledi. Bunun üzerine aralığın 11 olduğu varsayılarak devam edildi ve program 54 civarında bir değer verdi. Hoca değerin 46 ile 66 arasında olmasına bakarak "bunun arasında olabilir" dedi.

Python ile hesaplandı: Eşit aralık ve $h = 11$ kabulüyle $k = \frac{1895 - 1891}{11} = \frac{4}{11}$ olur. Farklar $\Delta f_0 = 20$, $\Delta^2 f_0 = -5$, $\Delta^3 f_0 = 2$, $\Delta^4 f_0 = -3$ olduğundan

$$F(1895) = 46 + 7.2727 + 0.5785 + 0.1262 + 0.1248 = 54.1022$$

> **Ders sonrası not:** Hocanın itirazı doğrudur. Gregory-Newton formülündeki sabit $h$, aralıkların eşit olmasını gerektirir. $x$'lerin yalnız sıfırdan başlamaması ve artımın 1 olmaması formülün genel hâliyle çözülür. Aralıklar eşit değilse sabit $h$ kabulü yanlış sonuç verir. Ders 10'da bu durum için $z = 0, 1, 2, \ldots$ yardımcı değişkeniyle değişken dönüşümü gösterilmişti. Bu yüzden veri eşit aralıklı değilse yukarıdaki 54.1022 yalnız kabulün sonucudur, aranan değer olmayabilir.

<!-- BELİRSİZ: Hocanın verdiği 1891 dışındaki x değerleri altyazıda söylenmiyor. "11" değeri ve sonucun ondalıkları da net değil. Altyazıda yalnız "54" geçiyor. -->

## 8. Regula Falsi ve Üç Ayrı Durma Koşulu

### 8.1 Örnek

Bir programda yine $x^2 - 4x - 5$ girildi. Başlangıç sınırları $-1$ ve 5, hata 0.001 idi. Durma koşulu olarak birincisi ($\varepsilon$'dan küçük olma) seçildi. Sonuç $-1$ çıktı, hoca "köklerden biri eksi bir" dedi.

> **Ders sonrası not:** Bu girdi Regula Falsi için özel bir durumdur. Python ile hesaplandı: $f(-1) = 0$ ve $f(5) = 0$. Yani aralığın iki ucu da köktür ve $f(a)f(b) < 0$ koşulu sağlanmaz. Ders 3'teki formülde payda sıfır olur:
> $$c = \frac{a\,f(b) - b\,f(a)}{f(b) - f(a)} = \frac{0}{0}$$
> Programın $-1$ yazması büyük olasılıkla formüle girmeden uçtaki değerin kök olduğunu görmesindendir. Yöntemin kendisini sınamak için iki ucunda işaret değişen bir aralık gerekir.

<!-- BELİRSİZ: "Başlangıç değeri eksi bir ... Beş" ifadesinin alt ve üst sınır olduğu bağlamdan çıkarıldı. Üç durma koşulunun neler olduğu altyazıda söylenmiyor. -->

### 8.2 Durma Koşulları ve Kodu Yeniden Yazmak

Bu programda üç ayrı durma koşulu tanımlanmış ve seçilen koşula göre kod ayrı ayrı yazılmıştı.

> **Hocanın vurgusu:** "Ben hep ardışık iki kök arasındaki mutlak değerce farka bakarım." Üç koşulu da ayrı ayrı kodlamak için "hayatı kendinize zorlaştırmışsınız" dedi, ama bunun önemli olmadığını ekledi.

Bir öğrenci kodu şimdi yazsa daha kolay okunur ve aynı şeyleri tekrar etmeden yazabileceğini söyleyince hoca bunu projenin asıl amacına bağladı:

> **Hocanın vurgusu:** "İşte bu senin kendindeki gelişmeyi sana gösteriyor. Bizim istediğimiz aslında bu." Amaç, bir ya da bir buçuk ay içinde algoritmadaki gelişmeyi görebilmektir.

Hocanın önerisi şudur: Vakit olursa kodu daha optimize biçimde yeniden yazın, başına ve sonuna sistem zamanını alan çağrılar koyun ve ne kadar hızlı çalıştığını karşılaştırın.

## 9. Üçüncü Dereceden Polinomda Newton-Raphson

Hoca son bir Newton-Raphson denemesi için $f(x) = x^3 + x^2 - 9x - 9$ verdi. $\varepsilon = 0.001$, iterasyon üst sınırı 100, başlangıç değeri 0 idi. Program $-1$ buldu. Hoca "köklerden biri" diye doğruladı. Polinom $(x + 1)(x - 3)(x + 3)$ olarak çarpanlarına ayrılır.

Türev $f'(x) = 3x^2 + 2x - 9$'dur. Çözüm (ara adım eklendi, Python ile hesaplandı):

$$x_1 = 0 - \frac{f(0)}{f'(0)} = 0 - \frac{-9}{-9} = -1$$

$$x_2 = -1 - \frac{f(-1)}{f'(-1)} = -1 - \frac{0}{-8} = -1$$

$|x_2 - x_1| = 0 \le 0.001$ olduğu için ikinci iterasyonda durulur. Aynı gösterimde ardından $\int_1^3 (x^2 + 2x)\,dx$, $n = 6$ örneği de çalıştırıldı ve yine 16.66 çıktı.

<!-- BELİRSİZ: Başlangıç değerinin geçtiği altyazı satırı bozuk ("iletişim şeyler sıfır"). 0 değeri bu satırdan ve sonucun tutmasından alındı. -->

## Dersin Toparlaması

Bu kayıtta yeni konu yoktu, ama gösterimler dönemin yöntemlerini kodlarken nelere dikkat edileceğini ortaya koydu. Newton-Raphson bir başlangıç değeriyle çalışır ve farklı başlangıç değerleri farklı köklere götürebilir. Durma ölçütü ardışık iki kök arasındaki mutlak farktır. Gauss eliminasyonu başlangıç değeri istemez, Gauss-Seidel ister. Gregory-Newton'da sabit $h$ eşit aralık gerektirir, aksi hâlde değişken dönüşümü kullanılır. Polinom girdisini soran bir program neyi sorduğunu açık yazmalıdır.

Kökleri ya da sonucu bilinen örneklerle sınamak, hocanın gösterimlerde yaptığı kontrolün aynısıdır. Hocanın proje için vurguladığı nokta ise bir kodu yazdıktan sonra daha iyi nasıl yazılacağını görebilmektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
