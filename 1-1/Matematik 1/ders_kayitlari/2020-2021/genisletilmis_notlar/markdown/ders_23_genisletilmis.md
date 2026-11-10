# Ders 23 Genişletilmiş Notu: 2. Vize Hazırlık Soruları ve Rasyonel Fonksiyonların İntegraline Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Haftadan Kalan Mazeret Sınavı Soruları
- 2. Yaz Okulu Final Mazeret Sınavı: Ekstremum ve Yorum Sorusu
- 3. Belirli İntegral Soruları: Kısmi İntegrasyon ve Değişken Değiştirme
- 4. Fonksiyonel Denklem, Tek Fonksiyon ve Doğrusallaştırma
- 5. Riemann Toplamı, Kapalı Türev ve Bükülme Noktası
- 6. Rasyonel Fonksiyonların İntegrali: Temel Kesirler
- 7. Basit Kesirlere Ayırma
- 8. 2. Vize Konularının Özeti
- Örnek Sorular
- Dersin Toparlaması

## 1. Geçen Haftadan Kalan Mazeret Sınavı Soruları

Ders Zoom üzerinden, hocanın ekran paylaşımı ve tablet kalemiyle yürüdü. Hoca geçen hafta kalemi bozuk olduğu için bazı soruları çözemediklerini hatırlattı. Bu derste önce o mazeret sınavının kalan sorularına, sonra başka bir mazeret sınavının (2020 yaz okulu final mazeret sınavı) sorularına baktı. Hoca her soruda konunun 1. vize mi, 2. vize mi, final mi konusu olduğunu belirtti. Daha önce çözülmüş ya da 1. vize konusu olan soruların (teğet doğrusu, $\ln$ uygulayarak limit, L'Hôpital kuralı) üzerinden hızlıca geçti. Bu soruların metni altyazıda okunmuyor.

<!-- BELİRSİZ: Sınav kâğıdı ekranda paylaşıldı; altyazıda soru numaraları ve şıkların tam metni çoğu yerde okunmuyor. Soru metinleri hocanın sözlü anlatımından kuruldu. -->

### Örnek 1: $f(x) = \ln|x^2-1|$ için hangi ifade doğrudur?

Bu soru 2. vize konusudur (türev ile artan/azalan aralıklar ve içbükeylik). Hocanın okuduğu şıklar şunlardır:

- A) $f$'nin $x = 0$'da yerel minimumu vardır.
- B) $f$'nin grafiği tanım kümesinde yukarı içbükeydir (concave up).
- C) $f$ tanım kümesinde artandır.
- D) $f$'nin görüntü kümesi bütün reel sayılardır.
- E) $f$ tanım kümesinde azalandır.

**Birinci türev.** Logaritmanın içinin türevi, içine bölünür:

$$f'(x) = \frac{2x}{x^2-1} = \frac{2x}{(x-1)(x+1)}.$$

Türevin işaretini belirleyen üç çarpan vardır. Kökler ve türevi tanımsız yapan noktalar $-1$, $0$ ve $1$'dir. Hoca $0$'ın aslında türevin kökü, $\pm1$'in ise türevi tanımsız yapan noktalar olduğunu belirtti. İşaret tablosundan $(-1, 0)$ aralığında $f$ artan, $(0,1)$ aralığında azalandır. Bu yüzden $x = 0$'da yerel minimum değil, yerel maksimum vardır. A yanlıştır.

**İkinci türev.** Bölüm kuralıyla:

$$f''(x) = \frac{2(x^2-1) - 2x\cdot 2x}{(x^2-1)^2} = \frac{2x^2 - 2 - 4x^2}{(x^2-1)^2} = \frac{-2(x^2+1)}{(x^2-1)^2}.$$

Payda her zaman pozitiftir. $x^2+1$ çarpanının reel kökü yoktur, o da her zaman pozitiftir. Başta $-2$ olduğu için $f''$ her yerde negatiftir. Yani grafik tanım kümesinde **aşağı içbükeydir** (concave down). Hoca burada şıklarda bir sorun olduğunu söyledi: "İşlem hatası yapmadıysak bu concave down olması lazım. Bu sınavın son hâli değil." Hoca C ve E'yi birinci türevin işaret tablosuna bakarak eledi: fonksiyon bazı aralıklarda artan, bazılarında azalandır. D'yi de "$-1$ noktası yüzünden" yanlış saydı.

> **Ders sonrası not:** Hoca D'yi yanlış saydı; doğrusu D doğrudur. $x \to \pm1$ iken $|x^2-1| \to 0$ olduğundan $f \to -\infty$, $x \to \pm\infty$ iken $f \to +\infty$ olur. $|x^2-1|$ tanım kümesinde bütün pozitif değerleri aldığı için $f$'nin görüntü kümesi bütün reel sayılardır. $f''$ hesabı doğrudur (sympy ile doğrulandı): B yanlıştır. Sorunun anahtarı büyük olasılıkla D'dir.

**Soru:** Bir öğrenci mutlak değerli logaritmanın türevini sordu. **Cevap:** Hoca bunu derste gösterdiklerini hatırlattı:

$$\frac{d}{dx}\ln|f(x)| = \frac{f'(x)}{f(x)}.$$

Yani mutlak değer olsa da türev, mutlak değer yokmuş gibi alınır.

### Örnek 2: Ekstremum değerleri

Soru, verilen fonksiyonun yerel ekstremum değerlerini soruyor. Fonksiyon

$$f(x) = \frac{x^2-x-1}{x-2}$$

biçimindedir (hocanın türev hesabından kuruldu). Bölüm kuralıyla:

$$f'(x) = \frac{(2x-1)(x-2) - (x^2-x-1)\cdot 1}{(x-2)^2} = \frac{2x^2 - 4x - x + 2 - x^2 + x + 1}{(x-2)^2} = \frac{x^2-4x+3}{(x-2)^2} = \frac{(x-1)(x-3)}{(x-2)^2}.$$

Paydadaki $(x-2)^2$ çift kuvvetli olduğu için her zaman pozitiftir. İşareti etkilemez, yok sayılabilir. $x = 2$ türevi tanımsız yapar, ama tanım kümesinde değildir. Kritik noktalar $x = 1$ ve $x = 3$'tür. Hoca işaret tablosunu "$+$" ile başlattı ve kontrol etti: $3$'ten büyük $x$ değerleri türevi pozitif yapar, $1$ ile $3$ arasında türev negatiftir. Fonksiyon artan, azalan, artandır. $x = 1$'de yerel maksimum, $x = 3$'te yerel minimum vardır.

Soru ekstremum **değerlerini** istediği için fonksiyonda yerine yazılır:

$$f(1) = \frac{1-1-1}{1-2} = 1, \qquad f(3) = \frac{9-3-1}{3-2} = 5.$$

Cevap A'dır. Hoca bu tip soruyu bir sonraki vizede görebileceklerini söyledi.

> **Ders sonrası not:** Hoca türev hesabında bir an paydayı "$(x-1)^2$" diye söyledi; doğrusu $(x-2)^2$'dir. Sonraki adımlarda doğru payda kullanıldı.

### Örnek 3: Ortalama değer teoremi (kiriş ve teğet)

Hoca bunun 1. vize konusu olduğunu ve daha önce çözdüklerini, ama önemli olduğu için hatırlatmak istediğini söyledi. Grafikte apsisleri $x = 1$ ve $x = 10$ olan iki noktayı birleştiren kirişe (secant line, chord) paralel teğetlerin $x$ değerleri soruluyor. Fonksiyon $y = x^2 - 8x$'tir (hocanın sayısal hesabından kuruldu).

Bu, türev için ortalama değer teoreminin (mean value theorem) geometrik yorumudur. Kirişin eğimi, $f$'nin $[1,10]$ aralığındaki ortalama değişim hızıdır:

$$\frac{f(10) - f(1)}{10 - 1} = \frac{(100 - 80) - (1 - 8)}{9} = \frac{20 + 7}{9} = 3.$$

Aranan iç nokta $c$'de teğet kirişe paraleldir, yani $f'(c) = 3$:

$$2c - 8 = 3 \;\Rightarrow\; 2c = 11 \;\Rightarrow\; c = \frac{11}{2}.$$

Bir öğrenci sonucun şıklarda çıkmadığını söyledi. Hoca hesabı yaptı ve şıklardan birinin $\tfrac{11}{2}$ olarak düzeltilmesi gerektiğini söyledi.

## 2. Yaz Okulu Final Mazeret Sınavı: Ekstremum ve Yorum Sorusu

Hoca ardından 2020 yaz okulunun final mazeret sınavını paylaştı. Final sınavı olduğu için bazı sorular final konusudur, ama 2. vize konularıyla ilgili soruları birlikte çözdüler. Hoca öğrencilerin önlerinde kâğıt kalem olmasını ve soruları önce kendilerinin denemesini istedi.

### Örnek 4: $g$'nin $x = 4$'te yerel maksimumu varsa $f$ hakkında ne söylenebilir?

$g$ fonksiyonunun birinci ve ikinci türevi vardır ve $g$'nin $x = 4$'te yerel maksimumu vardır. Hocanın türev hesabına göre fonksiyon $f(x) = e^{-g(x^2)}$'dir. Şıklardan biri "$f$'nin $x = 4$'te yerel minimumu vardır", biri de $x = 2$ ile ilgilidir.

<!-- BELİRSİZ: Şıkların tam metni altyazıda okunmuyor. Hoca bir şıkkı "f has a local maximum at the point x = 2" diye okuyor, sonra "x = 2'de yerel minimum" sonucuna varıp "burada doğru bir cevap" diyor. Hangi şıkkın doğru sayıldığı net değil; matematiksel sonuç x = 2'de yerel minimumdur. -->

Bir öğrenci ikinci türev testini uyguladığını söyledi. Hoca soruyu birinci türev üzerinden çözdü.

**Verilenin yorumu.** $g$'nin $x = 4$'te yerel maksimumu olduğu için $4$'ün hemen solunda $g' > 0$, hemen sağında $g' < 0$'dır. Yani $g$, $4$'ün solunda artan, sağında azalandır.

**$f$'nin türevi.** Zincir kuralıyla:

$$f'(x) = e^{-g(x^2)}\cdot\big(-g'(x^2)\big)\cdot 2x.$$

**$x = 4$ civarı.** $x$ yerine $4$'e yakın değerler yazılırsa $x^2$, $16$'ya yakın olur. Bu durumda $g'(16)$ civarının işaretine bakmak gerekir. Bu işaret bilinmez. Hocanın ifadesiyle: "Hemen dördün sağında ve solunda eksi ve artı diyebiliyorsunuz verilen bilgiden. Ama 16'ya doğru gidince belki başka şeyler var, değişiklikler olabilir." Bu yüzden $x = 4$ için kesin bir şey söylenemez. $x = 4$ ile ilgili şıklar yanlıştır.

**$x = 2$ civarı.** $x$ yerine $2$'ye yakın değerler yazılırsa $x^2$, $4$'e yakın olur. Hoca örnek olarak $x = 2{,}01$ değerini verdi: $x^2$, $4$'ten biraz büyüktür.

- $x$, $2$'nin hemen sağında: $x^2 > 4$, bu yüzden $g'(x^2) < 0$ ve $-g'(x^2) > 0$. $e^{(\dots)}$ her zaman pozitif, $2x$ de pozitiftir. Sonuç: $f'(x) > 0$.
- $x$, $2$'nin hemen solunda: $x^2 < 4$, bu yüzden $g'(x^2) > 0$ ve $-g'(x^2) < 0$. Sonuç: $f'(x) < 0$.

Birinci türev testine göre $f$, $2$'nin solunda azalan, sağında artandır. $f$'nin $x = 2$'de **yerel minimumu** vardır.

**Soru:** Bir öğrenci açıklamanın tekrarını istedi. **Cevap:** Hoca aynı adımları Türkçe yeniden anlattı ve özellikle $g$'nin argümanının $x^2$ olduğuna dikkat çekti: "Dört neresi, on altı neresi? Burada $x$ kare var."

> **Hocanın vurgusu:** Bu, yorum gerektiren güzel bir soru. Yorum gerektiren sorularla sınavlarda karşılaşırsınız.

## 3. Belirli İntegral Soruları: Kısmi İntegrasyon ve Değişken Değiştirme

### Örnek 5: Üç integralden yeni bir integral bulma

Verilenler ve istenen:

$$\int_1^3 f'(x)\,dx = 1,\qquad \int_1^3 f(x)f'(x)\,dx = 1,\qquad \int_1^3 x^2 f'(x)\,dx = 1 \quad\Longrightarrow\quad \int_1^3 x f(x)\,dx = ?$$

Hoca çözüme üçüncü integralden başladı. Kısmi integrasyon (integration by parts) uygulanır:

$$u = x^2,\quad dv = f'(x)\,dx \;\Rightarrow\; du = 2x\,dx,\quad v = f(x).$$

Belirli integralde sınırlar $uv$ terimine de yazılır:

$$1 = \int_1^3 x^2 f'(x)\,dx = \Big[x^2 f(x)\Big]_1^3 - \int_1^3 f(x)\cdot 2x\,dx = 9f(3) - f(1) - 2\int_1^3 x f(x)\,dx.$$

İstenen integral bu eşitlikte görünür:

$$\int_1^3 x f(x)\,dx = \frac{9f(3) - f(1) - 1}{2}.$$

Hoca önce sonucu bölü 2'siz yazdı; bir öğrenci "bölü ikisi var" diye uyardı, hoca düzeltti. Hoca, tahtada olsalar bunu çok hızlı yapacaklarını, ekranın dar olmasının kafasını karıştırdığını söyledi. Geriye $9f(3) - f(1)$ değerini bulmak kalır. Bunun için ilk iki integral kullanılır.

Bir öğrenci $f(3) = \tfrac32$ ve $f(1) = \tfrac12$ bulduğunu söyledi. Hoca bu yolu birlikte tamamladı:

1. Birinci integral doğrudan temel teoremden gelir: $\displaystyle\int_1^3 f'(x)\,dx = f(3) - f(1) = 1$.
2. İkinci integralde $u = f(x)$, $du = f'(x)\,dx$ dönüşümü yapılır. Sınırlar $f(1)$ ve $f(3)$ olur:
   $$\int_1^3 f(x)f'(x)\,dx = \int_{f(1)}^{f(3)} u\,du = \frac{f(3)^2 - f(1)^2}{2} = 1.$$
3. İki kare farkı açılır: $\dfrac{(f(3) - f(1))(f(3) + f(1))}{2} = 1$. $f(3) - f(1) = 1$ olduğundan $f(3) + f(1) = 2$.
4. İki denklemden $f(3) = \dfrac32$, $f(1) = \dfrac12$ (ara adım eklendi).
5. Yerine konur: $9\cdot\dfrac32 - \dfrac12 = 13$ (ara adım eklendi), ve
   $$\int_1^3 x f(x)\,dx = \frac{13 - 1}{2} = 6.$$

Cevap $6$'dır (sympy ile doğrulandı). Bir öğrenci kısmi integrasyon kısmını anlamadığını söyleyince hoca beyaz tahta açıp üçüncü integrale kısmi integrasyon uygulamasını yeniden yazdı.

> **Hocanın vurgusu:** Biraz zor bir soru, işlem gerektiriyor. Sınavda böyle sorudan en fazla bir tane olur diye düşünüyorum.

### Örnek 6: Değişken değiştirme ile sınırları değişen integral

Verilenler ve istenen:

$$\int_0^3 g(x)\,dx = 7,\qquad \int_0^6 g(2x)\,dx = 5 \quad\Longrightarrow\quad \int_1^2 x\,g(3x^2)\,dx = ?$$

Hoca önce hangi yöntemin kullanılması gerektiğini sordu: değişken değiştirme (substitution) mi, kısmi integrasyon mu? İntegrandda $x$ ile $g(3x^2)$ çarpılmıştır. $3x^2$'nin türevi $x$ içerdiği için değişken değiştirme uygundur.

**1. adım.** $u = 3x^2$, $du = 6x\,dx$, yani $x\,dx = \tfrac16\,du$. Sınırlar da değişir: $x = 1 \Rightarrow u = 3$, $x = 2 \Rightarrow u = 12$.

$$\int_1^2 x\,g(3x^2)\,dx = \frac16\int_3^{12} g(u)\,du.$$

**2. adım.** Bir öğrenci diğer integralleri de aynı şekilde $u$ dönüşümüyle mi çevireceklerini sordu; hoca "aynen öyle" dedi. $t = 2x$, $dt = 2\,dx$, $dx = \tfrac12\,dt$. Sınırlar: $x = 0 \Rightarrow t = 0$, $x = 6 \Rightarrow t = 12$.

$$5 = \int_0^6 g(2x)\,dx = \frac12\int_0^{12} g(t)\,dt \;\Rightarrow\; \int_0^{12} g(t)\,dt = 10.$$

**3. adım.** Belirli integralin aralık toplama özelliği:

$$\int_0^{12} g(t)\,dt = \int_0^{3} g(t)\,dt + \int_3^{12} g(t)\,dt \;\Rightarrow\; 10 = 7 + \int_3^{12} g \;\Rightarrow\; \int_3^{12} g = 3.$$

**4. adım.** $\displaystyle\int_1^2 x\,g(3x^2)\,dx = \frac16\cdot 3 = \frac12$ (ara adım eklendi). Cevap B'dir.

> **Ders sonrası not:** Hoca sınırları dönüştürürken bir an "$x = 0$ ve $x = 1$" dedi; sorudaki sınırlar $1$ ve $2$'dir. Hemen ardından "iki yazarsak on iki" diyerek doğru $u$ sınırlarını ($3$ ve $12$) kullandı. Sonuç $\tfrac12$ doğrudur.

> **Hocanın vurgusu:** Bu tarz sorular bekliyorum, 5-6 yıldız atıyorum. Yerine koyma yöntemi ve kısmi integrasyonla ilgili sorular aşağı yukarı böyle olur.

## 4. Fonksiyonel Denklem, Tek Fonksiyon ve Doğrusallaştırma

### Örnek 7: $f(cd) = f(c) + f(d)$ ve L'Hôpital

Her $c, d > 0$ için $f(cd) = f(c) + f(d)$ ve $\displaystyle\lim_{x\to2}\frac{f(x)}{x-2} = 4$ veriliyor. $f'(8)$ soruluyor. Hoca bunun aslında 1. vize konusu (L'Hôpital kuralı) olduğunu ama çözebileceklerini söyledi. Bir öğrenci ilk vizenin konularının biraz unutulduğunu söyledi. Bir başka öğrenci $f(cd)$'nin $c$'ye göre türevini almayı ve $f'(2)$'yi kullanmayı önerdi.

**1. adım: $f(2) = 0$.** $x \to 2$ iken payda sıfıra gider. Limitin sonlu olması için payın da sıfıra gitmesi gerekir, yani $f(2) = 0$ olmalıdır. Aksi hâlde çelişki çıkar. Bu durumda limit $\dfrac{f(x) - f(2)}{x-2}$ biçimindedir ve L'Hôpital ile $f'(2) = 4$ bulunur.

**2. adım: $f(x^3) = 3f(x)$.** Özellik iki kez uygulanır:

$$f(x^3) = f(x^2\cdot x) = f(x^2) + f(x) = f(x) + f(x) + f(x) = 3f(x).$$

Bir öğrenci bu adımı kaçırdığını söyleyince hoca bu açılımı ayrıca gösterdi.

**3. adım: türev.** Her iki tarafın türevi alınır. Sol tarafta zincir kuralı kullanılır:

$$3x^2 f'(x^3) = 3f'(x) \;\Rightarrow\; x^2 f'(x^3) = f'(x).$$

**4. adım.** $x = 2$ yazılır: $4\,f'(8) = f'(2) = 4$, buradan $f'(8) = 1$. Cevap B'dir.

> **Ders sonrası not:** Hoca 2. adımı bir an "$f(x^3) = 3x\,f(x)$" diye söyledi; doğrusu $f(x^3) = 3f(x)$'tir. Hesaba doğru biçim girdi ve sonuç $f'(8) = 1$ doğrudur.

> **Hocanın vurgusu:** Bu sınavda hem düşünmeyi hem işlem gerektiren sorular olacak. Mazeret sınavı bu zorlukta; en zor bunun kadar olur, bundan daha zor soracaklarını zannetmiyorum. Ders videolarını izlemeniz ve işin mantığını kavramanız gerekir.

### Örnek 8: Simetrik aralıkta uzun integrand

Hoca çok uzun bir integrand gördüklerinde bunun içinde bir hile, bir kestirme yol olduğunu, belirli integralin özelliklerini hatırlamaları gerektiğini söyledi. Soru $[-2, 2]$ aralığında, tek fonksiyonlardan oluşan uzun bir integranda $+3$ eklenmiş bir integraldir. Kısa nottaki biçimi:

$$\int_{-2}^{2}\left(x^3\cos^3 x - x - x^5\sin^2 x + x^2\sin x + 3\right)dx.$$

<!-- BELİRSİZ: İntegrandın tam metni altyazıda okunmuyor. Hocanın anlatımından yalnız şu çıkıyor: x³ gibi tek kuvvetler, tek × tek ve tek × çift çarpımları içeren terimler ve sonda +3. -->

**Kullanılan özellik.** $a > 0$ ve $f$ tek fonksiyon ($f(-x) = -f(x)$) ise

$$\int_{-a}^{a} f(x)\,dx = 0.$$

**Çarpım kuralları.** Hoca bir an "iki tek fonksiyonun çarpımı tek" dedi, hemen "sorry" diyerek düzeltti. Doğrusu:

- tek × tek = çift,
- çift × çift = çift,
- tek × çift = tek.

Hoca terimleri tek tek inceledi: $x^3$ tektir; $\cos x$ çifttir, bu yüzden $\cos^3 x$ çifttir ve $x^3\cos^3 x$ tektir. $\sin x$ tektir, $\sin^2 x$ çifttir ve $x^5\sin^2 x$ tektir. $x^2\sin x$, çift × tek olduğu için tektir. Bu terimlerin $[-2,2]$ integrali sıfırdır. Geriye yalnız sabit terim kalır:

$$\int_{-2}^{2} 3\,dx = \Big[3x\Big]_{-2}^{2} = 6 - (-6) = 12.$$

Hoca önce bir öğrenciye "cevap neden sıfır?" diye sordu. Sonra sondaki $3$'ü fark etti: "Oradaki 3'ü görmeden 0 demişim." Cevap $12$'dir, şık A (sympy ile sayısal olarak doğrulandı).

### Örnek 9: Temel teorem ile birleştirilmiş doğrusallaştırma

Hoca bu soruda doğrusallaştırmanın (linearization) belirli integral ve temel teoremin 1. kısmıyla birleştirildiğini söyledi. 1. vize konularıyla 2. vize konularının bu şekilde harmanlanabileceğini belirtti. Fonksiyon ve nokta:

$$h(x) = 1 + x + (x-2)\int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020} - 1\right]dt,\qquad a = 2.$$

Doğrusallaştırma formülü türevin tanımından gelir:

$$h(x) \approx L(x) = h(a) + h'(a)(x - a).$$

**$h(2)$.** $x = 2$ yazılınca $(x-2)$ çarpanı sıfır olur: $h(2) = 1 + 2 + 0 = 3$.

**$h'(x)$.** İlk iki terimin türevi $1$'dir. Üçüncü terime çarpım kuralı uygulanır. $(x-2)$'nin türevi $1$'dir; integralin türevi temel teoremin 1. kısmından integrandın $x$'teki değeridir:

$$h'(x) = 1 + \int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020} - 1\right]dt + (x-2)\left[(\sin x)^{2019}(\cos x)^{2020} - 1\right].$$

Hoca ikinci çarpımı açıkça yazmadı: "Yazmıyorum, çünkü $x$ yerine $2$ yerleştireceğim." $x = 2$'de bu terim sıfırdır.

**$h'(2)$.** $(\sin t)^{2019}$ tek, $(\cos t)^{2020}$ çifttir; çarpımları tektir. $[-2, 2]$ aralığında integrali sıfırdır. Geriye yalnız $-1$'in integrali kalır:

$$h'(2) = 1 + 0 + \int_{-2}^{2}(-1)\,dt = 1 - 4 = -3.$$

**$L(x)$.** $L(x) = 3 - 3(x - 2) = -3x + 9$. Cevap A'dır (sympy ile doğrulandı).

> **Ders sonrası not:** Altyazıda hoca $h'(2)$ hesabını "8-3" gibi karışık söylüyor; bu kısım altyazıda anlaşılmıyor. Doğru değer $h'(2) = 1 - 4 = -3$'tür ve hocanın vardığı $L(x) = -3x + 9$ sonucu bununla tutarlıdır.

Bu sırada bir öğrencinin sorusu üzerine hoca, 1. vizenin genelde biraz kolay olduğunu, ikinci vize ve finalin her zaman daha zor olduğunu söyledi; konuyu öğrenirlerse bunun çok fark etmeyeceğini ekledi. Doğrusallaştırmayı hatırlamanın bu tip sorularda gerekli olduğunu belirtti.

## 5. Riemann Toplamı, Kapalı Türev ve Bükülme Noktası

### Örnek 10: Riemann toplamını belirli integrale çevirme

$$\lim_{n\to\infty}\sum_{k=1}^{n}\frac{n}{n^2 + k^2} = ?$$

Hoca öğrencilere sorunun hangi konuyla ilişkili olduğunu sordu: Riemann toplamları (Riemann sums). Cevabın sıfır olmadığını, burada bir hile olduğunu söyledi.

**Hatırlatma.** Belirli integral, Riemann toplamının limitidir:

$$\int_a^b f(x)\,dx = \lim_{n\to\infty}\sum_{k=1}^{n} f(x_k)\,\Delta x,\qquad \Delta x = \frac{b-a}{n},\qquad x_k = a + k\,\Delta x.$$

Amaç, verilen ifadeyi $f(x_k)\,\Delta x$ yapısına sokmak ve uygun $f$'yi bulmaktır.

**1. adım.** Toplam değişkeni $k$'dır. Paydada $n^2$ ortak çarpan parantezine alınır:

$$\frac{n}{n^2 + k^2} = \frac{n}{n^2\left(1 + \left(\frac{k}{n}\right)^2\right)} = \frac{1}{1 + \left(\frac{k}{n}\right)^2}\cdot\frac{1}{n}.$$

**2. adım.** $\Delta x = \dfrac1n$ seçilir. Bunun için $b - a = 1$ olmalıdır. En basit seçim $a = 0$, $b = 1$'dir; o zaman $x_k = \dfrac{k}{n}$ olur. Hoca $a = 1$, $b = 2$ seçmenin de mümkün olduğunu, ama problemi daha karmaşık hâle getireceğini söyledi.

**3. adım.** Toplam $\displaystyle\lim_{n\to\infty}\sum_{k=1}^{n}\frac{1}{1 + x_k^2}\,\Delta x$ biçimine gelir. Buradan $f(x) = \dfrac{1}{1+x^2}$'dir ve $\Delta x$, $dx$'e dönüşür.

**4. adım.** Temel teoremin 2. kısmıyla:

$$\int_0^1 \frac{dx}{1+x^2} = \arctan x\,\Big|_0^1 = \arctan 1 - \arctan 0 = \frac{\pi}{4}.$$

Cevap $\dfrac{\pi}{4}$'tür (sympy ile doğrulandı; $n = 1000$ için toplam yaklaşık $0{,}7851$).

> **Hocanın vurgusu:** Böyle bir soru bekliyorum. Ya finalde ya da önümüzdeki sınavda böyle bir soruyla karşılaşma ihtimaliniz çok yüksek.

### Örnek 11: Temel teorem ile kapalı türev

$y$, $x$'e bağlı olarak şu kapalı biçimde veriliyor:

$$x = \int_0^{y}\frac{dt}{\sqrt{1 + 4t^2}}.$$

$\dfrac{d^2y}{dx^2}$'nin $4y$ olduğunu doğrulamak isteniyor. Hoca bu sorunun kapalı türev (implicit differentiation) ile temel teoremin 1. kısmının birleşimi olduğunu söyledi.

**1. adım.** Her iki tarafın $x$'e göre türevi alınır. Sol taraf $1$'dir. Sağ tarafta temel teorem ve zincir kuralı kullanılır ($y$, $x$'e bağlıdır):

$$1 = \frac{1}{\sqrt{1 + 4y^2}}\cdot y' \;\Rightarrow\; \frac{dy}{dx} = \sqrt{1 + 4y^2}.$$

**2. adım.** Türev bir kez daha alınır:

$$\frac{d^2y}{dx^2} = \frac{8y\,y'}{2\sqrt{1 + 4y^2}}.$$

**3. adım.** $y' = \sqrt{1+4y^2}$ yerine yazılınca kökler sadeleşir: $\dfrac{d^2y}{dx^2} = \dfrac{8y}{2} = 4y$ (ara adım eklendi; sympy ile doğrulandı).

**Soru:** Bir öğrenci integrali arccos'un türevi olarak alıp alamayacaklarını sordu. **Cevap:** Hoca orada arccos olmadığını söyledi: "Sen formül ezberi yapıyorsun, formülleri birbirine karıştırıyorsun. Kosinüsün türevini biliyorsun, arccos'un nasıl çıkarılacağını biliyorsun. 5-10 saniyede arccos olmadığını görebilirsin." Ayrıca bu soruda integrali hesaplamaya hiç gerek yoktur; doğrudan temel teorem uygulanır.

### Örnek 12: $y = \dfrac{\ln x}{x}$ fonksiyonunun bükülme noktası

Bükülme noktası (inflection point) için ikinci türevin işaret tablosu gerekir.

**Birinci türev** (bölüm kuralı):

$$y' = \frac{\frac1x\cdot x - \ln x\cdot 1}{x^2} = \frac{1 - \ln x}{x^2}.$$

**İkinci türev:**

$$y'' = \frac{-\frac1x\cdot x^2 - (1 - \ln x)\cdot 2x}{x^4} = \frac{-x - 2x + 2x\ln x}{x^4} = \frac{2\ln x - 3}{x^3}.$$

**İşaret tablosu.** Tanım kümesi yalnız pozitif reel sayılardır ($x > 0$). Bu yüzden $x^3 > 0$'dır ve işaret yalnız payla belirlenir. $2\ln x - 3 = 0 \Rightarrow x = e^{3/2}$. $e^{3/2}$'den büyük değerlerde $y'' > 0$, küçük pozitif değerlerde $y'' < 0$'dır. İkinci türev eksiden artıya geçtiği için $x = e^{3/2}$ bükülme noktasıdır (sympy ile doğrulandı).

Hoca tanım kümesinin önemini vurguladı: negatif değerler ve sıfır tabloya girmez.

Sınavın kalan soruları (eğri yay uzunluğu, trigonometrik dönüşüm, bir parçacığın hızı) final konusu olduğu için çözülmedi.

## 6. Rasyonel Fonksiyonların İntegrali: Temel Kesirler

Kısa bir aradan sonra hoca final konusu olan rasyonel fonksiyonların integraline (integration of rational functions) giriş yaptı.

> **Hocanın vurgusu:** Bu final konusu. Önümüzdeki sınavda bu konudan sorumlu değilsiniz.

**Tanım (rasyonel fonksiyon):**

- $P(x)$ ve $Q(x)$ iki polinom fonksiyon olsun.
- İki polinomun oranı $\dfrac{P(x)}{Q(x)}$ rasyonel fonksiyon (rational function) olarak adlandırılır.
- Örnekler: $\dfrac1x$, $\dfrac{1}{x^2+1}$, $\dfrac{x+1}{x^2+1}$, $\dfrac{x}{(x-1)^2}$.

Hoca önce kolayca integrali alınan **temel kesirleri** (basic fractions) gösterdi. Bunlarda payın derecesi paydanın derecesinden küçüktür.

### 6.1 $\dfrac{1}{x+a}$

Pay $0$, payda $1$. derecedendir. $u = x + a$, $du = dx$ dönüşümüyle:

$$\int\frac{dx}{x+a} = \int\frac{du}{u} = \ln|u| + C = \ln|x+a| + C.$$

### 6.2 $\dfrac{1}{x^2+a^2}$

Hoca önce $\dfrac{1}{x^2+1}$'den söz etti, sonra genel olarak $x^2 + a$ (pozitif sabit) paydasını $x^2 + (\sqrt a)^2$ biçiminde yazdı. Daha basit görünsün diye sabiti $a^2$ olarak aldı. Hoca öğrencilere bu formülü ezberlemediklerini, dönüşümle bulduklarını hatırlattı. Yöntem: paydada $a^2$ parantezine alınır, sonra $u = \dfrac{x}{a}$ dönüşümü yapılır.

$$\int\frac{dx}{x^2 + a^2} = \int\frac{dx}{a^2\left(\frac{x^2}{a^2} + 1\right)},\qquad u = \frac{x}{a},\quad dx = a\,du.$$

$$= \frac{1}{a^2}\int\frac{a\,du}{u^2 + 1} = \frac1a\arctan u + C = \frac1a\arctan\frac{x}{a} + C.$$

<!-- BELİRSİZ: Hocanın bu integralin son satırını söylediği yer (02:17:06 civarı) altyazıda anlaşılmıyor. Son iki adım dönüşümden kuruldu (ara adım eklendi) ve sympy ile doğrulandı. -->

### 6.3 $\dfrac{x}{x^2+b}$

Pay $1$., payda $2$. derecedendir. $u = x^2 + b$, $du = 2x\,dx$, $x\,dx = \tfrac12\,du$:

$$\int\frac{x\,dx}{x^2+b} = \frac12\int\frac{du}{u} = \frac12\ln|x^2+b| + C.$$

## 7. Basit Kesirlere Ayırma

Temel kesir olmayan bir rasyonel fonksiyonun integrali, onu temel kesirlerin toplamı olarak yazarak alınır. Bu yönteme basit kesirlere ayırma (partial fractions, hocanın deyişiyle "basic fraction method") denir. Hoca ayırmanın paydanın çarpanlarına göre yapıldığını gösterdi.

> **Ek bilgi (derste anlatılmadı):** Basit kesirlere ayırma doğrudan yalnız payın derecesi paydanın derecesinden küçük olduğunda (basit/proper rasyonel fonksiyon) uygulanır. Payın derecesi büyük ya da eşitse önce polinom bölmesi yapılır. Derste gösterilen bütün örneklerde payın derecesi paydanın derecesinden küçüktür.

### Örnek 13: $\displaystyle\int\frac{dx}{x^2-1}$ (katsız reel kökler)

$\dfrac{1}{x^2-1}$ bir rasyonel fonksiyondur ama temel kesir değildir. $x^2 - 1$'in reel kökleri vardır, bu yüzden çarpanlarına ayrılır: $x^2 - 1 = (x-1)(x+1)$.

Hoca çarpanları yorumladı: $(x-1)$'in reel kökü vardır, ama katlı (multiple) değildir, çünkü kuvveti $1$'dir. Bu durumda tek bir temel kesir yazmak yeterlidir. Aynısı $(x+1)$ için de geçerlidir:

$$\frac{1}{(x-1)(x+1)} = \frac{A}{x-1} + \frac{B}{x+1}.$$

**Genel yöntem (katsayı eşitleme).** Paydalar eşitlenir:

$$1 = A(x+1) + B(x-1) = (A+B)x + (A-B).$$

Sol tarafta $x$'in katsayısı $0$, sabit terim $1$'dir. Özdeşlik bağıntısından:

$$A + B = 0,\qquad A - B = 1 \;\Rightarrow\; 2A = 1 \;\Rightarrow\; A = \frac12,\quad B = -\frac12.$$

**Kısa yol (özel yöntem).** Çarpanın reel kökü varsa ve katlı değilse kullanılabilir. $A$'yı bulmak için sol taraftaki $(x-1)$ çarpanı kapatılır (yok sayılır) ve kalan ifadeye bu çarpanın kökü $x = 1$ yazılır:

$$A = \frac{1}{1+1} = \frac12.$$

$B$ için $(x+1)$ kapatılır ve $x = -1$ yazılır: $B = \dfrac{1}{-1-1} = -\dfrac12$.

<!-- BELİRSİZ: Hocanın kısa yolu anlattığı yerin bir kısmı (02:21:03-02:21:53 ve 02:24:19-02:25:17) altyazıda döngüye girmiş ya da boş; yöntemin adımları hocanın vardığı sonuçlardan ve sonraki örneklerdeki kullanımından kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Bu kısa yol ders kitaplarında büyük olasılıkla "Heaviside örtme yöntemi" (cover-up method) adıyla geçer. Katlı bir çarpanda yalnız en yüksek kuvvetli terimin katsayısını verir; diğer katsayılar için yine denklem sistemi gerekir.

**İntegral.** Her iki tarafın integrali alınır:

$$\int\frac{dx}{x^2-1} = \frac12\int\frac{dx}{x-1} - \frac12\int\frac{dx}{x+1} = \frac12\ln|x-1| - \frac12\ln|x+1| + C = \frac12\ln\left|\frac{x-1}{x+1}\right| + C.$$

Hoca son sadeleştirmenin zorunlu olmadığını, ama yapılabileceğini söyledi (sympy ile doğrulandı).

Ardından hoca çok basit bir rasyonel fonksiyonun integralini sordu ve $u = x - 1$ dönüşümüyle ya da doğrudan bulunabileceğini söyledi.

<!-- BELİRSİZ: 02:27:48-02:28:26 arasında sorulan "çok basit" integralin integrandı altyazıda okunmuyor (büyük olasılıkla 1/(x-1) ya da 1/(x-1)² türünden bir ifade). -->

### Örnek 14: $\displaystyle\int\frac{x\,dx}{(x-1)^2}$ (katlı reel kök)

Paydanın reel kökü $x = 1$'dir ve katlıdır (kuvveti $2$). Katlı reel kökte her kat (katman) için ayrı bir temel kesir yazılır:

$$\frac{x}{(x-1)^2} = \frac{A}{x-1} + \frac{B}{(x-1)^2}.$$

Birinci kesir $(x-1)$ ile genişletilir ve paydalar eşitlenir:

$$x = A(x-1) + B = Ax + (B - A).$$

Sol tarafta $x$'in katsayısı $1$, sabit terim $0$'dır: $A = 1$, $B - A = 0 \Rightarrow B = 1$.

Hoca burada kısa yolun **uygulanamayacağını** vurguladı, çünkü $(x-1)^2$ katlı köke sahiptir. Bu durumda katsayılar denklem sistemiyle bulunur.

$$\int\frac{x\,dx}{(x-1)^2} = \int\frac{dx}{x-1} + \int\frac{dx}{(x-1)^2} = \ln|x-1| - \frac{1}{x-1} + C.$$

(sympy ile doğrulandı.)

**İkinci yöntem.** Bir öğrencinin önerisi üzerine hoca bunun değişken değiştirmeyle de yapılabileceğini gösterdi: $u = x - 1$, $x = u + 1$, $dx = du$:

$$\int\frac{u+1}{u^2}\,du = \int\frac{du}{u} + \int\frac{du}{u^2}.$$

Hoca bunun da doğru olduğunu, ama burada genel yöntemi anlattığını söyledi.

> **Hocanın vurgusu:** Sonuca odaklanmayın, anlattığım yönteme odaklanın. Sonuca odaklanırsanız kaybedersiniz.

### 7.1 Basit kesir gerekmeyen durumlar

Hoca her rasyonel fonksiyonda basit kesirlere ayırmanın gerekmediğini gösterdi. Pay, paydanın türevine benziyorsa doğrudan değişken değiştirme yeterlidir:

$$\int\frac{x\,dx}{x^2-1} = \frac12\ln|x^2-1| + C\qquad(u = x^2 - 1),$$

$$\int\frac{x\,dx}{x^2+1} = \frac12\ln(x^2+1) + C\qquad(u = x^2 + 1).$$

### Örnek 15: $\displaystyle\int\frac{dx}{x(x^2+1)}$ (reel kökü olmayan ikinci derece çarpan)

Payda çarpanlarına ayrılmış hâldedir. Hoca her çarpanı yorumladı:

- $x$: reel kökü var ($x = 0$), kuvveti $1$, katlı değil. Bir katman: $\dfrac{A}{x}$.
- $x^2 + 1$: reel kökü yok, karmaşık (complex) kökleri var. Kuvveti $1$, katlı karmaşık kök yok. $x^2 + 1$ ikinci dereceden olduğu için payına derecesi $2 - 1 = 1$ olan bir polinom yazılır: $\dfrac{Bx + C}{x^2+1}$.

$$\frac{1}{x(x^2+1)} = \frac{A}{x} + \frac{Bx + C}{x^2+1}.$$

**$A$ kısa yolla.** $x$'in reel kökü var ve katlı değil. $x$ kapatılır, $x = 0$ yazılır: $A = \dfrac{1}{0 + 1} = 1$. $B$ ve $C$ kısa yolla bulunamaz, çünkü $x^2+1$'in kökleri karmaşıktır.

**$B$ ve $C$ katsayı eşitlemeyle.** Kesirler genişletilir:

$$1 = A(x^2+1) + (Bx + C)x = (A + B)x^2 + Cx + A.$$

Sol tarafta $x^2$'nin katsayısı $0$, $x$'in katsayısı $0$, sabit terim $1$'dir: $A + B = 0$, $C = 0$, $A = 1$. Buradan $B = -1$.

$$\int\frac{dx}{x(x^2+1)} = \int\frac{dx}{x} - \int\frac{x\,dx}{x^2+1} = \ln|x| - \frac12\ln(x^2+1) + C.$$

Hoca önce integralde $B$'yi $+1$ alıp "$+\tfrac12\ln$" yazdı, sonra "sorry" diyerek $B = -1$ olduğunu ve terimin eksi olması gerektiğini düzeltti (sympy ile doğrulandı).

### 7.2 Katlı reel ve katlı karmaşık kökler: $\dfrac{\dots}{x^3(x^2+1)^2}$

Hoca konuyu öğretmek için katsayıları bulunmayan, yalnız ayrışımın biçimi yazılan bir örnek verdi. Payda $x^3(x^2+1)^2$'dir.

- $x^3$: reel kök, katlı (kuvvet $3$). Üç katman yazılır. $x$ birinci dereceden olduğu için her paya derecesi $1 - 1 = 0$ olan polinom, yani sabit gelir:
  $$\frac{A}{x} + \frac{B}{x^2} + \frac{C}{x^3}.$$
- $(x^2+1)^2$: karmaşık kökler, katlı (kuvvet $2$). İki katman yazılır. $x^2+1$ ikinci dereceden olduğu için her paya birinci dereceden polinom gelir:
  $$\frac{Dx + E}{x^2+1} + \frac{Fx + G}{(x^2+1)^2}.$$

<!-- BELİRSİZ: Hocanın harf seçimi altyazıda karışık (ör. "Dx + F", "Gx + H"); burada harfler sırayla verildi. Altyazıda hoca bir an "x² − 1'in karmaşık kökleri" diyor; bağlamdan çarpan x² + 1'dir. -->

> **Hocanın vurgusu:** Sınavda böyle bir örnekte $A, B, C, \dots$ katsayılarını bulmanız istenmez; bunları bulmak kolay değil. Soru "bu integral aşağıdakilerden hangisine özdeştir?" tarzında gelir.

### Örnek 16: Final sorusu (ayrışımın biçimi)

Hoca bir final sınavı sorusu gösterdi ve cevabın A olduğunu doğrulamalarını istedi. Önce rasyonel fonksiyon sadeleştirildi: payda $x$ parantezine alınınca $x(x^2-1) = x(x-1)(x+1)$ çıkar. Paydada $(x^2+1)(x-1)^2$ vardır. Bir $(x-1)$ çarpanı sadeleşir:

$$\frac{x(x-1)(x+1)}{(x^2+1)(x-1)^2} = \frac{x(x+1)}{(x^2+1)(x-1)}.$$

<!-- BELİRSİZ: Sorudaki integrandın ilk (sadeleşmemiş) yazılışı altyazıda tam okunmuyor; yukarıdaki biçim hocanın sözlü sadeleştirmesinden kuruldu. -->

Paydayı yorumlarsak: $x^2 + 1$ karmaşık köklü ve katsızdır, $x - 1$ reel köklü ve katsızdır. Bu yüzden yazılacak biçim:

$$\frac{A}{x-1} + \frac{Bx + C}{x^2+1}.$$

Cevap A'dır. (sympy kontrolü: $\dfrac{x(x+1)}{(x^2+1)(x-1)} = \dfrac{1}{x-1} + \dfrac{1}{x^2+1}$, yani bu ayrışımda $A = 1$, $B = 0$, $C = 1$.)

### Örnek 17: $\dfrac{x}{(x+1)^2(x^4+1)}$ ve $\dfrac{x}{(x+1)^2(x^4+1)^2}$

Hoca konuyu tam anlatmak için son bir örnek verdi.

- $(x+1)^2$: reel kök, katlı. İki katman: $\dfrac{A}{x+1} + \dfrac{B}{(x+1)^2}$.
- $x^4 + 1$: reel kökü yok, karmaşık kökleri var, kuvveti $1$ (katsız). Dördüncü dereceden olduğu için paya derecesi $4 - 1 = 3$ olan polinom yazılır: $\dfrac{Cx^3 + Dx^2 + Ex + F}{x^4+1}$.

Hoca ardından $x^4+1$'in kuvvetini $2$ yaptı. O zaman ikinci bir katman da yazılır:

$$\frac{x}{(x+1)^2(x^4+1)^2} = \frac{A}{x+1} + \frac{B}{(x+1)^2} + \frac{Cx^3 + Dx^2 + Ex + F}{x^4+1} + \frac{Gx^3 + Hx^2 + Ix + J}{(x^4+1)^2}.$$

Hocanın genel kuralı: bir çarpanın derecesi $d$ ise payına derecesi $d - 1$ olan bir polinom yazılır; çarpan $m$ katlıysa $m$ katman yazılır.

> **Ek bilgi (derste anlatılmadı):** Reel sayılarda her polinom birinci ve (reel kökü olmayan) ikinci derece çarpanlara ayrılır. Örneğin $x^4 + 1 = (x^2 + \sqrt2\,x + 1)(x^2 - \sqrt2\,x + 1)$'dir. Hocanın yazdığı $\dfrac{Cx^3 + Dx^2 + Ex + F}{x^4+1}$ biçimi yine doğru bir ayrışımdır; ama integrali almak için bu kesrin büyük olasılıkla iki ikinci derece çarpana göre ayrıca ayrılması gerekir.

## 8. 2. Vize Konularının Özeti

Ders sonunda hoca, 2. vizeye yönelik aşağı yukarı bütün soru tiplerini çözdüklerini düşündüğünü söyledi ve konuları kısaca özetledi:

- **Asimptotlar:** bir iki soru gelebilir.
- **Ekstremumlar:** bir iki soru gelebilir.
- **Temel teorem:** çok önemli; birçok soruyla birleştirilebilir.
- **Riemann toplamları:** bugün çözülen soru tiplerine bakılmalı.
- **Kısmi integrasyon ve değişken değiştirme:** doğrudan integral sorusu gelmez; biraz düşündüren, değişken dönüşümü gerektiren sorular gelir.

> **Hocanın vurgusu:** İşin özünü anladıysanız, soru hangi zorlukta gelirse gelsin kaçırmazsınız.

Hoca bir sonraki derste bir miktar final konusu işleyeceğini, vakit kalırsa birkaç soru daha çözeceğini söyledi.

## Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular derste ekranda paylaşılan sınavlardan hocanın okuduğu ve çözdüğü, ya da sözlü sorduğu sorulardır. Soru metinleri hocanın sözlü anlatımından kuruldu.

### Soru 1 (derste sözlü, 00:04:39)

$f(x) = \ln|x^2-1|$ için şu ifadelerden hangisi doğrudur? A) $x = 0$'da yerel minimum var. B) Grafik tanım kümesinde yukarı içbükey. C) $f$ tanım kümesinde artan. D) $f$'nin görüntü kümesi bütün reel sayılar. E) $f$ tanım kümesinde azalan.

**Çözüm (derste verildi):** Bkz. Örnek 1. Hoca A, B, C, E'nin yanlış olduğunu gösterdi, grafiğin aşağı içbükey olduğunu buldu. D derste yanlış sayıldı; doğrusu D doğrudur (bkz. Örnek 1'deki ders sonrası not).

### Soru 2 (derste sözlü, 00:10:53)

$f(x) = \dfrac{x^2-x-1}{x-2}$ fonksiyonunun yerel ekstremum değerleri nelerdir?

**Çözüm (derste verildi):** Bkz. Örnek 2. $f(1) = 1$ (yerel maksimum), $f(3) = 5$ (yerel minimum).

### Soru 3 (derste sözlü, 00:15:46)

$y = x^2 - 8x$ grafiğinde apsisleri $1$ ve $10$ olan noktaları birleştiren kirişe paralel teğetin değme noktasının apsisi nedir?

**Çözüm (derste verildi):** Bkz. Örnek 3. $c = \dfrac{11}{2}$.

### Soru 4 (derste sözlü, 00:23:02)

$g$'nin birinci ve ikinci türevi vardır ve $g$'nin $x = 4$'te yerel maksimumu vardır. $f(x) = e^{-g(x^2)}$ için $x = 4$ ve $x = 2$ noktalarında ne söylenebilir?

<!-- BELİRSİZ: Şıkların tam metni altyazıda okunmuyor. -->

**Çözüm (derste verildi):** Bkz. Örnek 4. $x = 4$ için kesin bir şey söylenemez; $f$'nin $x = 2$'de yerel minimumu vardır.

### Soru 5 (derste sözlü, 00:40:57)

$\displaystyle\int_1^3 f'(x)\,dx = 1$, $\displaystyle\int_1^3 f(x)f'(x)\,dx = 1$ ve $\displaystyle\int_1^3 x^2 f'(x)\,dx = 1$ ise $\displaystyle\int_1^3 x f(x)\,dx$ kaçtır?

**Çözüm (derste verildi):** Bkz. Örnek 5. Cevap $6$.

### Soru 6 (derste sözlü, 00:56:02)

$\displaystyle\int_0^3 g(x)\,dx = 7$ ve $\displaystyle\int_0^6 g(2x)\,dx = 5$ ise $\displaystyle\int_1^2 x\,g(3x^2)\,dx$ kaçtır?

**Çözüm (derste verildi):** Bkz. Örnek 6. Cevap $\dfrac12$.

### Soru 7 (derste sözlü, 01:21:13)

Her $c, d > 0$ için $f(cd) = f(c) + f(d)$ ve $\displaystyle\lim_{x\to2}\frac{f(x)}{x-2} = 4$ ise $f'(8)$ kaçtır?

**Çözüm (derste verildi):** Bkz. Örnek 7. Cevap $1$.

### Soru 8 (derste sözlü, 01:29:06)

$[-2, 2]$ aralığında tek fonksiyonlardan oluşan uzun bir integranda $+3$ eklenmiş integralin değeri nedir?

<!-- BELİRSİZ: İntegrandın tam metni altyazıda okunmuyor; bkz. Örnek 8. -->

**Çözüm (derste verildi):** Bkz. Örnek 8. Tek fonksiyonların integrali sıfırdır; cevap $\displaystyle\int_{-2}^{2} 3\,dx = 12$.

### Soru 9 (derste sözlü, 01:32:44)

$h(x) = 1 + x + (x-2)\displaystyle\int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020} - 1\right]dt$ fonksiyonunun $a = 2$'deki doğrusallaştırması nedir?

**Çözüm (derste verildi):** Bkz. Örnek 9. $L(x) = -3x + 9$.

### Soru 10 (derste sözlü, 01:40:22)

$\displaystyle\lim_{n\to\infty}\sum_{k=1}^{n}\frac{n}{n^2+k^2}$ kaçtır? Bu soru hangi konuyla ilişkilidir?

**Çözüm (derste verildi):** Bkz. Örnek 10. Riemann toplamı; cevap $\dfrac{\pi}{4}$.

### Soru 11 (derste sözlü, 01:51:21)

$x = \displaystyle\int_0^{y}\frac{dt}{\sqrt{1+4t^2}}$ ise $\dfrac{d^2y}{dx^2} = 4y$ olduğunu doğrulayınız.

**Çözüm (derste verildi):** Bkz. Örnek 11.

### Soru 12 (derste sözlü, 01:58:51)

$y = \dfrac{\ln x}{x}$ fonksiyonunun bükülme noktasını bulunuz.

**Çözüm (derste verildi):** Bkz. Örnek 12. $x = e^{3/2}$.

### Soru 13 (derste sözlü, 02:44:17)

Final sınavı sorusu: verilen rasyonel fonksiyon sadeleştirilince $\dfrac{x(x+1)}{(x^2+1)(x-1)}$ olur. Bu fonksiyonun basit kesirlere ayrışımının biçimi hangisidir?

<!-- BELİRSİZ: Sorunun ilk yazılışı ve şıkları altyazıda okunmuyor. -->

**Çözüm (derste verildi):** Bkz. Örnek 16. $\dfrac{A}{x-1} + \dfrac{Bx+C}{x^2+1}$ (şık A).

## Dersin Toparlaması

Dersin büyük kısmı 2. vizeye hazırlık için iki mazeret sınavının sorularına ayrıldı. Bu sorular türevle ekstremum ve içbükeylik incelemesini, birinci türev testiyle yorum gerektiren bir soruyu, kısmi integrasyon ve değişken değiştirmeyle sınırları değişen belirli integralleri, tek fonksiyonun simetrik aralıktaki integralini, temel teoremle birleştirilmiş doğrusallaştırmayı ve kapalı türevi, Riemann toplamını integrale çevirmeyi ve bükülme noktasını kapsadı. Hoca her soruda sonuca değil yönteme odaklanmayı, formül ezberlemek yerine formüllerin nereden geldiğini bilmeyi ve uzun integrandlarda belirli integral özelliklerini aramayı öğütledi.

Son bölümde final konusu olan rasyonel fonksiyonların integraline giriş yapıldı. Temel kesirlerin integralleri ($\ln$ ve $\arctan$ veren tipler) gösterildi. Basit kesirlere ayırmada paydanın çarpanlarına göre yazılacak biçim kuruldu: katsız reel kök için tek sabit paylı kesir, katlı reel kök için her kat için bir kesir, reel kökü olmayan çarpan için derecesi bir düşük polinom paylı kesir, katlı karmaşık kök için her kat için ayrı bir kesir. Katsız reel köklerde katsayılar kısa yolla, diğer durumlarda katsayı eşitlemeyle bulunur. Hoca bir sonraki derste bu konuya devam edeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
