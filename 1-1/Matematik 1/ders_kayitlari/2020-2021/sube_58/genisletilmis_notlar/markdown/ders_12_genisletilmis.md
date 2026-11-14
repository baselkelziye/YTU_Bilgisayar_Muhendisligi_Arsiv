# Ders 12 Genişletilmiş Notu: 1. Vize Öncesi Genel Alıştırmalar: Limit, Tanım Kümesi, Ters Fonksiyon ve Doğrusallaştırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş: Nasıl Çalışmalı?
- 2. Örnek 1: $1^\infty$ Belirsizliği
- 3. Örnek 2: arccos, ln ve Küp Kök İçeren Fonksiyonun Tanım Kümesi
- 4. Örnek 3: İç İçe Logaritmanın Tanım Kümesi
- 5. Örnek 4: Artan ve Azalan Olduğu Aralıklar
- 6. Örnek 5: Ters Fonksiyonun Bir Noktadaki Türevi
- 7. Örnek 6: $\infty - \infty$ Belirsizliği
- 8. Örnek 7: $0 \cdot \infty$ Belirsizliği ve Değişken Dönüşümü
- 9. Örnek 8: $0^0$ Belirsizliği
- 10. Örnek 9: Kapalı Eğrinin Teğet ve Normal Doğrusu
- 11. Örnek 10: Doğrusallaştırma ile Yaklaşık Değer
- 12. Örnek 11: $\dfrac{\infty}{\infty}$ Belirsizliği ve L'Hôpital Kuralının Mantığı
- Örnek Sorular

## 1. Derse Giriş: Nasıl Çalışmalı?

Bu ders, birinci vizeden önceki genel alıştırma (general exercises) dersidir. Ders İngilizce anlatıldı, arada Türkçe açıklamalar yapıldı. Yeni konu anlatılmadı. Hoca soruyu tahtaya (tablete) yazdı, öğrencilere birkaç dakika çözme süresi verdi, sonra çözümü birlikte yaptı. Bu notta her soru, önce sorunun kendisi, sonra adım adım çözüm olarak verilmiştir.

Derse başlamadan önce bir öğrenci, yalnızca ders notlarındaki soruları çözmenin yeterli olup olmadığını sordu. Hoca "evet" dedi, ama asıl önemli olanın her sorunun arkasındaki "felsefeyi" (philosophy behind each question) anlamak olduğunu söyledi. Bunu anlayan biri için çok sayıda soru çözmeye gerek yoktur.

Bir başka öğrenci, hocanın tablete yazdığı notların yüklenip yüklenmeyeceğini sordu. Hoca bunların AVS'deki ders notlarının bir özeti olduğunu, asıl notlardan çalışmanın daha iyi olduğunu söyledi. Video izlerken öğrencilerin önlerine kâğıt kalem almalarını, soru yazıldığında çözüme bakmadan önce kendilerinin çözmeye çalışmalarını önerdi.

Hoca çalışma sırasını şöyle özetledi:

- Önce tanımları ve kavramları öğrenin. Tanımlarda ince nüanslar vardır. Bunları kaçırırsanız ne kadar soru çözerseniz çözün bir anlamı olmaz. Tanımları öğrenmek temel ve gerekli koşuldur.
- Sonra derste çözülen soruları, çözümlere hiç bakmadan yeniden çözmeyi deneyin.
- Bunları yapabiliyorsanız sınavı gözünüzde büyütmenize gerek yoktur. Amaç zorlamak değil, öğretmektir.

> **Hocanın vurgusu:** Tanımları ve kavramları öğrenmeden soru çözmek işe yaramaz. Her sorunun arkasındaki mantığı anlamaya odaklanın.

## 2. Örnek 1: $1^\infty$ Belirsizliği

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to 1}\big(1 + \sin(x-1)\big)^{\frac{1}{x-1}}$$

Hoca, bu tür limit sorularının test sınavında görülebileceğini, logaritmik yöntemle (logaritmanın limitini hesaplayarak) çözülebileceğini söyledi. İlk iş, belirsizliğin türünü belirlemektir.

### 2.1 Belirsizliğin türü

$x \to 1$ iken $\sin(x-1) \to \sin 0 = 0$ olduğundan taban $1$'e gider. Üs $\dfrac{1}{x-1}$ ise $+\infty$ ya da $-\infty$'a gider (sağdan ve soldan yaklaşmaya göre). Belirsizlik $1^\infty$ biçimindedir.

### 2.2 Birinci yol: Benzetme yöntemi

Hoca daha önce logaritmik yöntemle gösterilen genel sonucu hatırlattı:

**Hatırlatma (genel $1^\infty$ limiti):**

- $u \to 0$ iken
$$\lim_{u\to 0}(1 + a u)^{\frac{1}{u}} = e^{a}.$$

Sorudaki ifade bu kalıba benzetilir. $u = \sin(x-1)$ denirse $x \to 1$ iken $u \to 0$ olur. Hocanın deyişiyle "şanslıyız": taban tam olarak $1 + u$ biçimindedir. Kalıbı kullanmak için üste $\dfrac{1}{u} = \dfrac{1}{\sin(x-1)}$ gerekir. Orijinal üs ise $\dfrac{1}{x-1}$'dir. Üs, değeri değiştirmeden şöyle yazılır:

$$\big(1 + \sin(x-1)\big)^{\frac{1}{x-1}} = \left[\big(1 + \sin(x-1)\big)^{\frac{1}{\sin(x-1)}}\right]^{\frac{\sin(x-1)}{x-1}}.$$

Hoca bunun "hiçbir şeyi değiştirmediğini" vurguladı: dışarıdaki üs ile içerideki üs çarpılınca yine $\dfrac{1}{x-1}$ elde edilir.

- Köşeli parantezin içi, $u \to 0$ kalıbıyla $e^1 = e$'ye gider.
- Dıştaki üs $\dfrac{\sin(x-1)}{x-1}$, $\dfrac{0}{0}$ belirsizliğidir. L'Hôpital kuralı ile $\dfrac{\cos(x-1)}{1} \to 1$ olur.

Sonuç: $e^1 = e$.

<!-- BELİRSİZ: 00:14:08 civarında altyazıda uzun bir döngü var; bu adımın sözlü anlatımı tam okunmuyor. Adımlar hocanın önceki ve sonraki cümlelerinden kuruldu. -->

### 2.3 İkinci yol: Genel (logaritmik) yöntem

Hoca, benzetme yöntemi akla gelmezse genel yöntemin her zaman kullanılabileceğini söyledi.

- $A = \big(1 + \sin(x-1)\big)^{\frac{1}{x-1}}$ denir.
- Eşitliğin iki tarafına doğal logaritma (natural logarithm) uygulanır:
$$\ln A = \frac{\ln\big(1 + \sin(x-1)\big)}{x - 1}.$$
- $A$'nın limiti yerine $\ln A$'nın limiti hesaplanır. $x \to 1$ iken pay $\ln 1 = 0$'a, payda $0$'a gider. Belirsizlik $\dfrac{0}{0}$'dır. L'Hôpital kuralı uygulanır:
$$\lim_{x\to 1}\ln A = \lim_{x\to 1}\frac{\dfrac{\cos(x-1)}{1 + \sin(x-1)}}{1} = \frac{1}{1} = 1 \quad \text{(ara adım eklendi)}.$$
- Geri dönmek için $\ln$'in tersi olan üstel fonksiyon (exponential function) uygulanır: $\displaystyle\lim_{x\to 1} A = e^{1} = e$.

**Cevap:** $e$. (sympy ile doğrulandı.)

## 3. Örnek 2: arccos, ln ve Küp Kök İçeren Fonksiyonun Tanım Kümesi

**Soru:** Aşağıdaki fonksiyonun tanım kümesini (domain) bulun.

$$f(x) = \arccos\left(\frac{x-5}{2}\right) + \ln(6 - x) + \sin\sqrt[3]{x-2}$$

Hoca bunun basit bir soru olduğunu, herkesin çözebileceğini söyledi ve öğrencilere süre verdi.

### 3.1 Çözüm

Fonksiyon üç terimin toplamıdır. Her terimin anlamlı olduğu küme bulunur, sonra bunların kesişimi alınır.

- **arccos terimi:** Kosinüsün tersinden (arccos) söz edebilmek için argümanın $[-1, 1]$ aralığında olması gerekir. Aksi hâlde kosinüsün tersinden söz edilemez.
$$-1 \le \frac{x-5}{2} \le 1 \;\Rightarrow\; -2 \le x - 5 \le 2 \;\Rightarrow\; 3 \le x \le 7.$$
- **ln terimi:** $\ln$'in argümanı pozitif olmalıdır: $6 - x > 0 \Rightarrow x < 6$.
- **Küp kök terimi:** Kök derecesi 3'tür (tek). Tek dereceli kök her reel sayı için tanımlıdır. $\sin$ de her reel sayıda tanımlıdır. Bu terim ek şart getirmez.

Kesişim alınır:

$$D(f) = [3, 7] \cap (-\infty, 6) = [3, 6).$$

3 dahildir, 6 dahil değildir.

**Cevap:** $D(f) = [3, 6)$. (sympy ile doğrulandı.)

### 3.2 Öğrenci sorusu: $6 - x$, 1'e eşit olabilir mi?

**Soru:** $6 - x$'in 1 olmaması gerekmez mi?

**Cevap:** Hoca, genel kuralın $\ln$'in argümanının yalnızca pozitif olması olduğunu söyledi. Argüman 1 olabilir. Ardından, iki aralığın kesişimini düşünürken "bu özel durumda $6 - x$ 1 olamaz" gibi bir cümle kurdu, ama sonunda yine "genel olarak $\ln$'in argümanı ayrı ayrı pozitif olmalıdır" diyerek bitirdi.

<!-- BELİRSİZ: 00:22:40-00:22:57 arasında hocanın "özel durumda 6 - x 1 olamaz" sözüyle neyi kastettiği altyazıdan anlaşılmıyor. -->

> **Ders sonrası not:** Bu fonksiyonda $6 - x = 1$, yani $x = 5$ olabilir. $x = 5$ tanım kümesinin içindedir: $f(5) = \arccos 0 + \ln 1 + \sin\sqrt[3]{3} = \dfrac{\pi}{2} + \sin\sqrt[3]{3}$ tanımlıdır. $\ln$ için tek şart argümanın pozitif olmasıdır. Argümanın 1'den farklı olması şartı yalnızca logaritmanın **tabanı** için konur.

## 4. Örnek 3: İç İçe Logaritmanın Tanım Kümesi

**Soru:** Aşağıdaki fonksiyonun tanım kümesini bulun.

$$f(x) = \ln\big(\ln(\ln x)\big) + \sqrt{9 - x^2}$$

Hoca soruyu yazarken iki parantezin yeterli olduğunu, araya artı konmaması gerektiğini düzeltti. Öğrencilere dikkat etmelerini söyledi: Fonksiyonun kuralı iki fonksiyonun toplamıdır. Toplamdaki birinci terim, **üç doğal logaritma fonksiyonunun bileşkesidir** (composition).

### 4.1 Birinci terim: dıştan içe

$\ln$'in argümanı pozitif olmalıdır. Hoca, dıştan içe doğru gidilmesini söyledi.

- En dıştaki $\ln$'in argümanı $\ln(\ln x)$'tir. Bu pozitif olmalıdır:
$$\ln(\ln x) > 0.$$
- Eşitsizliğin her yerine üstel fonksiyon uygulanır. Üstel fonksiyon artan olduğu için eşitsizliğin yönü değişmez:
$$e^{\ln(\ln x)} > e^{0} \;\Rightarrow\; \ln x > 1.$$
- Yeniden üstel fonksiyon uygulanır:
$$e^{\ln x} > e^{1} \;\Rightarrow\; x > e.$$

Birinci terimin anlamlı olması için $x > e$ olmalıdır. Bu şart içteki $\ln x > 0$ ve $x > 0$ şartlarını da kapsar.

### 4.2 İkinci terim: karekök

Kök derecesi 2 (çift) olduğu için kökün içi sıfır ya da pozitif olmalıdır:

$$9 - x^2 \ge 0 \;\Rightarrow\; x^2 \le 9 \;\Rightarrow\; -3 \le x \le 3.$$

### 4.3 Kesişim

Toplam olduğu için iki aralığın kesişimi alınır:

$$D(f) = (e, \infty) \cap [-3, 3] = (e, 3].$$

$e$ dahil değildir, çünkü o şartta eşitlik yoktur. 3 dahildir, çünkü kök şartında eşitlik vardır. Hoca, öğrencilerin hepsinin $e$ ile 3 arasını doğru bulduğunu söyledi.

**Cevap:** $D(f) = (e, 3]$. (sympy ile doğrulandı.)

## 5. Örnek 4: Artan ve Azalan Olduğu Aralıklar

**Soru:** Aşağıdaki fonksiyonun artan (increasing) ve azalan (decreasing) olduğu aralıkları bulun.

$$f(x) = \arcsin\sqrt{1 - x^2}$$

Hoca kolay ve temel bir alıştırma olduğunu söyledi. Ancak öğrencilerin bir kısmı yanlış buldu.

> **Hocanın vurgusu:** Artan/azalan aralıkları bulmadan önce fonksiyonun tanım kümesi bulunmalıdır. Fonksiyonun anlam ifade etmediği bölgede "artıyor" ya da "azalıyor" demek saçmadır. Bu çok düşürücü bir sorudur: test sınavında şıklarda $(-\infty, -1)$ ya da $(1, \infty)$ gibi aralıklar olursa, tanım kümesine bakmayan öğrenci yanlış şıkkı işaretler.

### 5.1 Önce tanım kümesi

İki şart vardır:

- **Karekök:** Kökün içi negatif olmamalıdır: $1 - x^2 \ge 0 \Rightarrow -1 \le x \le 1$.
- **arcsin:** Argüman $[-1, 1]$ aralığında olmalıdır: $-1 \le \sqrt{1 - x^2} \le 1$. Karekök zaten negatif olmadığından sol taraf $0$ olarak alınır. Kare alınırsa
$$0 \le 1 - x^2 \le 1 \;\Rightarrow\; x^2 \ge 0,$$
bu da her zaman doğrudur.

Hoca kare alırken önce sol tarafa yanlışlıkla bir şey yazdı. Bir öğrenci, kare alınca eksi tarafın sıfır olarak yazılması gerektiğini hatırlattı. Hoca "doğru söylüyorsun" diyerek düzeltti.

Kesişim: $D(f) = [-1, 1]$.

### 5.2 Türev

Hoca önce arcsin'in türev formülünü hatırlattı:

**Hatırlatma (arcsin'in türevi):**

- $u = u(x)$ için
$$\big(\arcsin u\big)' = \frac{u'}{\sqrt{1 - u^2}}.$$

Burada $u = \sqrt{1 - x^2}$'dir.

- $u' = \dfrac{-2x}{2\sqrt{1 - x^2}} = \dfrac{-x}{\sqrt{1 - x^2}}$.
- $1 - u^2 = 1 - (1 - x^2) = x^2$.
- Yerine konur:
$$f'(x) = \frac{\dfrac{-x}{\sqrt{1-x^2}}}{\sqrt{x^2}} = \frac{-x}{|x|\sqrt{1 - x^2}}.$$

Hoca burada $x$'lere dikkat edilmesini, işin $x$'in negatif ya da pozitif oluşuna göre değişeceğini söyledi.

### 5.3 İşaret tablosu

Tanım kümesi $[-1, 1]$ kapalı aralığıdır. $f'$'nin işareti, $0$'ın sağı ve solu için incelenir. $|x|$ ve $\sqrt{1 - x^2}$ her zaman pozitiftir. İşareti belirleyen pay $-x$'tir.

| Aralık | $-x$ | $\lvert x\rvert\sqrt{1-x^2}$ | $f'(x)$ | $f$ |
|---|---|---|---|---|
| $(-1, 0)$ | $+$ | $+$ | $+$ | artan |
| $(0, 1)$ | $-$ | $+$ | $-$ | azalan |

$[-1, 1]$ dışında fonksiyon tanımlı değildir. Hoca, aralıkların uçlarının açık ya da kapalı yazılmasının bu soru için önemli olmadığını söyledi.

**Cevap:** $f$, $(-1, 0)$ aralığında artan, $(0, 1)$ aralığında azalandır. (sympy ile türev ve işaret doğrulandı.)

> **Ek bilgi (derste anlatılmadı):** $x \in [-1, 1]$ için $\arcsin\sqrt{1 - x^2} = \arccos|x|$ eşitliği vardır. arccos azalan bir fonksiyon olduğundan, $|x|$ büyüdükçe $f$ küçülür. Bu da $f$'nin $0$'ın solunda artan, sağında azalan olduğunu doğrular. $f$, $x = 0$'da türevlenemez; en büyük değeri $f(0) = \dfrac{\pi}{2}$'dir.

### 5.4 Öğrenci soruları

**Soru:** Ters çevirip çarparken mutlak değer $|x|$ nereden geldi? Çift katlı kök işaret değiştirmez gibi hatırlıyorum.

**Cevap:** Kök içinde $x^2$ kaldı. Onu kök dışına çıkarırken $\sqrt{x^2} = |x|$ yazılır. Daima pozitif olduğu için mutlak değerle çıkar. İstenirse $\sqrt{x^2}$ olarak da bırakılabilirdi.

**Soru:** Fonksiyonun türevini almak neden faydalı oldu?

**Cevap:** Hoca önce arcsin'in türev formülünü yeniden hatırlattı. Sonra bu sorunun bir maksimum-minimum (max-min) sorusu olmadığını, yalnızca $f$'nin arttığı ve azaldığı aralıkları bulma sorusu olduğunu söyledi. Bu aralıkları türevin işareti verir.

## 6. Örnek 5: Ters Fonksiyonun Bir Noktadaki Türevi

**Soru:** $f: \mathbb{R} \to \mathbb{R}$, $f(x) = x\sqrt{8 + x^2}$ olsun. $(f^{-1})'(3)$ değerini hesaplayın.

Hoca bu tip sorunun test sınavında görülebileceğini söyledi.

> **Hocanın vurgusu:** Bu tür sorularda $f^{-1}$'i hesaplamanıza gerek yoktur. Formülü ezberlemenize de gerek yoktur: $f^{-1} \circ f$ özdeşlik fonksiyonudur. Buna zincir kuralı uygulanırsa ne yapılması gerektiği beş saniyede görülür.

### 6.1 Formülün elde edilişi

$$f^{-1}\big(f(x)\big) = x.$$

İki tarafın $x$'e göre türevi alınır. Sol tarafta zincir kuralı (chain rule) kullanılır:

$$(f^{-1})'\big(f(x)\big)\cdot f'(x) = 1.$$

$x = x_0$ yazılırsa

$$(f^{-1})'\big(f(x_0)\big) = \frac{1}{f'(x_0)}.$$

Soruda $f(x_0) = 3$ olmalıdır.

### 6.2 Çözüm

**Adım 1: $x_0$'ı bulmak.**

$$f(x_0) = x_0\sqrt{8 + x_0^2} = 3.$$

Hoca buradan $x_0$'ın tek türlü $1$ olarak bulunduğunu söyledi. Kontrol: $1\cdot\sqrt{8 + 1} = 3$.

Ara adım eklendi: İki tarafın karesi alınırsa $x_0^2(8 + x_0^2) = 9$, yani $x_0^4 + 8x_0^2 - 9 = 0$ olur. Bu $(x_0^2 + 9)(x_0^2 - 1) = 0$ diye çarpanlarına ayrılır. $x_0 = \pm 1$ çıkar. $x_0 = -1$ için $f(-1) = -3$ olduğundan kare alırken eklenmiş bir köktür. Geriye $x_0 = 1$ kalır.

**Adım 2: $f'(x)$'i bulmak.** Çarpım kuralı (product rule) ve $(\sqrt{u})' = \dfrac{u'}{2\sqrt{u}}$ kullanılır:

$$f'(x) = 1\cdot\sqrt{8 + x^2} + x\cdot\frac{2x}{2\sqrt{8 + x^2}} = \sqrt{8 + x^2} + \frac{x^2}{\sqrt{8 + x^2}}.$$

**Adım 3: $x_0 = 1$'de değer.**

$$f'(1) = \sqrt{9} + \frac{1}{\sqrt{9}} = 3 + \frac{1}{3} = \frac{10}{3}.$$

**Adım 4: Formül.**

$$(f^{-1})'(3) = \frac{1}{f'(1)} = \frac{1}{10/3} = \frac{3}{10}.$$

**Cevap:** $\dfrac{3}{10}$. (sympy ile doğrulandı.)

> **Hocanın vurgusu:** Cevap $\dfrac{3}{10}$'dur, $\dfrac{10}{3}$ değil. Ezbere giden öğrencinin çok basit bir yerde yanlış şıkkı işaretleme ihtimali çok yüksektir. İşin mantığını anlamayanlar burada hata yapıyor.

Hoca ayrıca derse düzenli katılıp derste anlatılanları iyi öğrenen öğrenciler için stres yapılacak bir durum olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** $f'(x) = \sqrt{8 + x^2} + \dfrac{x^2}{\sqrt{8 + x^2}}$ her $x$ için pozitiftir. Bu yüzden $f$, $\mathbb{R}$ üzerinde kesin artandır ve bire birdir. $f(x_0) = 3$ denkleminin tek çözümü olması ve $f^{-1}$'in var olması bundan gelir.

## 7. Örnek 6: $\infty - \infty$ Belirsizliği

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to 0^+}\left(\frac{1}{x} - \frac{1}{\sqrt{x}}\right)$$

Hoca bunun L'Hôpital kuralının uygulanmasıyla ilgili bir soru olduğunu söyledi. Öğrencilere çözme süresi verildi. Bir öğrenci cevabın $+\infty$ olduğunu söyledi.

### 7.1 Belirsizliğin türü

$x \to 0^+$ iken iki terim de $+\infty$'a gider. Belirsizlik $\infty - \infty$'dur. Bu biçimde L'Hôpital kuralı doğrudan uygulanamaz. Önce ifade düzenlenmelidir.

### 7.2 Birinci yol: Payda eşitleme ve L'Hôpital

Payda eşitlenir:

$$\frac{1}{x} - \frac{1}{\sqrt{x}} = \frac{\sqrt{x} - x}{x\sqrt{x}}.$$

Şimdi belirsizlik $\dfrac{0}{0}$'dır. L'Hôpital kuralı uygulanır.

- Payın türevi: $(\sqrt{x} - x)' = \dfrac{1}{2\sqrt{x}} - 1$.
- Paydanın türevi (çarpım kuralı ile): $(x\sqrt{x})' = \sqrt{x} + x\cdot\dfrac{1}{2\sqrt{x}}$.

Hoca paydanın türevinin doğrudan da yazılabileceğini, ama çarpım kuralının da uygulanabileceğini söyledi. Düzenlenirse:

$$\lim_{x\to 0^+}\frac{\dfrac{1 - 2\sqrt{x}}{2\sqrt{x}}}{\dfrac{3\sqrt{x}}{2}} = \lim_{x\to 0^+}\frac{1 - 2\sqrt{x}}{3x} \quad \text{(ara adım eklendi)}.$$

Pay $1$'e, payda $0^+$'a gider. Sonuç $\dfrac{1}{0^+} = +\infty$'dur. Hoca işlemleri tek tek yapmadı, sonucun sonsuz geleceğini söyledi.

### 7.3 İkinci yol: Eşlenik yöntemi

**Soru:** Bu soru L'Hôpital'siz yapılabilir miydi?

**Cevap:** Hoca, eşlenikle (conjugate) çarparak da yapılabileceğini, hatta belki bu yolla daha kolay geleceğini söyledi ve ikinci yolu da gösterdi.

$\dfrac{\sqrt{x} - x}{x\sqrt{x}}$ ifadesinin payı ve paydası $\sqrt{x} + x$ ile çarpılır. Payda $(\sqrt{x})^2 - x^2 = x - x^2$ olur. Sağdan yaklaşıldığı için $x > 0$'dır. Ortak $x$ parantezine alınıp sadeleştirilir:

$$\frac{x - x^2}{x\sqrt{x}\,(\sqrt{x} + x)} = \frac{x(1 - x)}{x\sqrt{x}\,(\sqrt{x} + x)} = \frac{1 - x}{x + x\sqrt{x}}.$$

$x \to 0^+$ iken pay $1$'e, payda $0^+$'a gider. Sonuç yine $+\infty$'dur.

<!-- BELİRSİZ: 01:00:01-01:00:28 arasında eşlenik yönteminin sözlü anlatımı kopuk ("mutlak değer x, o da x diye çıkar", "x'i x kare bölü x kök x"). Ara ifadeler bu sözlerden ve sonuçtan kuruldu. -->

**Cevap:** $+\infty$. (sympy ile limit ve iki ara ifade doğrulandı.)

## 8. Örnek 7: $0 \cdot \infty$ Belirsizliği ve Değişken Dönüşümü

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to\infty} x^2\left(1 - \cos\frac{1}{x}\right)$$

Hoca soruyu yazarken önce "$x \to 0$" dedi, hemen "pardon" diyerek $x \to \infty$ olarak düzeltti.

### 8.1 Belirsizliğin türü

$x \to \infty$ iken $x^2 \to \infty$, $\dfrac{1}{x} \to 0$ ve $\cos\dfrac{1}{x} \to \cos 0 = 1$ olur. Parantez $1 - 1 = 0$'a gider. Belirsizlik $\infty \cdot 0$'dır. L'Hôpital kuralı doğrudan uygulanamaz.

> **Ders sonrası not:** Hoca belirsizliği açıklarken (01:03:48) yine "$x \to 0$" dedi. Soru $x \to \infty$ içindir; açıklamadaki $x^2 \to \infty$ ve $\cos\frac{1}{x} \to 1$ de bunu gösterir.

### 8.2 Düzenleme ve dönüşüm

İfade bölüm biçimine getirilir:

$$\lim_{x\to\infty}\frac{1 - \cos\frac{1}{x}}{\dfrac{1}{x^2}}.$$

Hoca, sorunun sadeleşmesi için şu dönüşümün daha iyi olacağını söyledi:

$$t = \frac{1}{x}, \qquad x \to \infty \text{ iken } t \to 0^+.$$

Limit şuna dönüşür:

$$\lim_{t\to 0^+}\frac{1 - \cos t}{t^2}.$$

### 8.3 L'Hôpital

Belirsizlik $\dfrac{0}{0}$'dır. Pay ve paydanın $t$'ye göre türevleri alınır:

$$\lim_{t\to 0^+}\frac{\sin t}{2t} = \frac{1}{2}\lim_{t\to 0^+}\frac{\sin t}{t} = \frac{1}{2}.$$

Hoca bu son adımın doğrudan görülebileceğini söyledi.

**Cevap:** $\dfrac{1}{2}$. (sympy ile doğrulandı.)

> **Hocanın vurgusu:** Bazen bir değişken dönüşümü yapmak L'Hôpital işlemini kolaylaştırır. Hemen doğrudan $x$ üzerinden gitmeyin.

Bu sorudan sonra hoca, sınav öncesi bu genel alıştırmaların çok katkı sağlayacağını söyledi. Derslere katılıp konuları anlamış ve bu son haftalarda soruları çözmeye uğraşmış bir öğrencinin, sınavdan önce tanımlara ve kavramlara yarım saat göz gezdirmesinin yeterli olacağını iddia etti.

## 9. Örnek 8: $0^0$ Belirsizliği

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to 0^+} x^{\frac{1}{\ln(e^x - 1)}}$$

Soru yazıldıktan sonra 10 dakika ara verildi. Aradan dönünce hoca cevabın $e$ olacağını söyledi ve çözüme geçti.

### 9.1 Belirsizliğin türü

- Taban $x \to 0^+$.
- $x \to 0^+$ iken $e^x - 1 \to 0^+$, dolayısıyla $\ln(e^x - 1) \to -\infty$ ve üs $\dfrac{1}{\ln(e^x-1)} \to 0$.

Belirsizlik $0^0$'dır.

### 9.2 Genel yöntem

- $A = x^{\frac{1}{\ln(e^x - 1)}}$ denir.
- İki tarafa $\ln$ uygulanır:
$$\ln A = \frac{\ln x}{\ln(e^x - 1)}.$$
- $x \to 0^+$ iken pay $-\infty$'a, payda $-\infty$'a gider. Belirsizlik $\dfrac{\infty}{\infty}$'dur. L'Hôpital uygulanır.
- Payın türevi $\dfrac{1}{x}$, paydanın türevi $\dfrac{(e^x - 1)'}{e^x - 1} = \dfrac{e^x}{e^x - 1}$'dir.
$$\lim_{x\to 0^+}\ln A = \lim_{x\to 0^+}\frac{1/x}{e^x/(e^x - 1)} = \lim_{x\to 0^+}\frac{e^x - 1}{x}\cdot\frac{1}{e^x}.$$
- Hoca limiti iki parçaya ayırdı:
  - $\dfrac{1}{e^x} \to 1$.
  - $\dfrac{e^x - 1}{x}$ yine $\dfrac{0}{0}$ belirsizliğidir. L'Hôpital ile $\dfrac{e^x}{1} \to 1$.
- Sonuç: $\displaystyle\lim_{x\to 0^+}\ln A = 1\cdot 1 = 1$.
- Bu $\ln A$'nın limitidir. $A$'nın limitini bulmak için geri dönülür: $\ln$'in tersi olan üstel fonksiyon uygulanır.
$$\lim_{x\to 0^+} A = e^{1} = e.$$

**Cevap:** $e$. (sympy ile doğrulandı.)

### 9.3 Öğrenci sorusu

**Soru:** Son satırı (açık mavi ile yazılanı) tekrar eder misiniz?

**Cevap:** Hoca, bölü bölünün ters çevrilip çarpıldığını, L'Hôpital'i daha rahat uygulayabilmek için limitin parçalara ayrıldığını anlattı. Parçalardan biri $\dfrac{1}{e^x}$'tir ve $1$'e gider. Diğeri $\dfrac{e^x - 1}{x}$'tir. Bunda $\dfrac{0}{0}$ belirsizliği vardır. $e^x - 1$'in türevi $e^x$, $x$'in türevi $1$'dir. L'Hôpital ile $1$'e gider. Başta $A$'ya $\ln$ uygulandığı için bulunan sonucu geri döndürmek gerekir. $\ln$ ile üstel fonksiyon birbirinin tersidir.

> **Hocanın vurgusu:** Cevap $e$'dir, $1$ değil. $1$, $\ln A$'nın limitidir. Geri dönmek için üstel fonksiyon uygulanmalıdır.

## 10. Örnek 9: Kapalı Eğrinin Teğet ve Normal Doğrusu

**Soru:** Kapalı (implicit) biçimde verilen

$$x^{y} = 2y$$

eğrisinin $P(2, 1)$ noktasındaki teğet (tangent) ve normal doğrularının denklemlerini (varsa) bulun.

Hoca "varsa" (if any) ifadesini ekledi: teğet ya da normal doğrunun olmak zorunda olmadığını belirtti. Önce $P$ noktasının eğri üzerinde olduğu görülür: $2^1 = 2 = 2\cdot 1$.

### 10.1 Logaritma ile düzenleme

Bu olağan bir fonksiyon değildir. Problemi olağan biçime çevirmek için iki tarafa doğal logaritma uygulanır:

$$\ln\big(x^{y}\big) = \ln(2y) \;\Rightarrow\; y\ln x = \ln(2y).$$

### 10.2 Kapalı türev

$y$'nin $x$'e göre türevi, teğet doğrunun eğimini verir. İki tarafın $x$'e göre türevi alınır:

$$y'\ln x + y\cdot\frac{1}{x} = \frac{2y'}{2y} = \frac{y'}{y}.$$

### 10.3 Noktada eğim

$P(2, 1)$ yerine konur ($x = 2$, $y = 1$, $y' = m$):

$$m\ln 2 + \frac{1}{2} = m.$$

Hoca önce $x$ ile $y$'nin yerini karıştırıp $\dfrac{y}{x}$ terimine $2$ yazdı. Bir öğrenci sol taraftaki terimin $\dfrac{1}{2}$ olması gerektiğini söyledi. Hoca "doğru söylüyorsun" diyerek düzeltti.

$$m(\ln 2 - 1) = -\frac{1}{2} \;\Rightarrow\; m_t = -\frac{1}{2(\ln 2 - 1)} = \frac{1}{2(1 - \ln 2)} \approx 1{,}629.$$

### 10.4 Teğet ve normal doğru

**Teğet doğru:**

$$y - 1 = \frac{1}{2(1 - \ln 2)}\,(x - 2).$$

Hoca sayıların biraz çirkin çıktığını, testte daha düzgün sayılar geleceğini söyledi.

> **Ders sonrası not:** Altyazıda teğet denklemi okunurken eğim "minus one times two times ln two" gibi bozuk geçiyor. Doğru eğim, hocanın bir önceki adımda söylediği $m_t = -\dfrac{1}{2(\ln 2 - 1)}$'dir.

**Normal doğru:** Teğet ile normal doğru diktir, eğimlerinin çarpımı $-1$'dir:

$$m_n = -\frac{1}{m_t} = 2(\ln 2 - 1).$$

$$y - 1 = 2(\ln 2 - 1)\,(x - 2).$$

(sympy ile $m_t$ ve $m_n$ doğrulandı.)

### 10.5 Öğrenci sorusu: Doğru denklemi nasıl yazılır?

**Soru:** Denklemi yazmayı tekrar eder misiniz?

**Cevap:** Hoca, bir noktası ve eğimi bilinen doğrunun denkleminin nasıl yazıldığını hatırlattı.

- Doğru $P(x_0, y_0)$ noktasından geçer. $(x, y)$ doğru üzerinde herhangi bir noktadır. Bu iki nokta ile bir dik üçgen oluşur. Üçgenin eğimi
$$\frac{y - y_0}{x - x_0} = m.$$
- $y = f(x)$ grafiğine $(x_0, y_0)$ noktasında çizilen teğet doğrunun eğimi, fonksiyonun türevinin o noktadaki değeridir: $m_t = f'(x_0)$.
- Teğet doğru denklemi:
$$y - y_0 = f'(x_0)\,(x - x_0).$$
- Normal doğru da aynı noktadan geçer ve teğete diktir. Eğimlerinin çarpımı $-1$'dir:
$$m_n = -\frac{1}{m_t}, \qquad m_t \ne 0.$$

## 11. Örnek 10: Doğrusallaştırma ile Yaklaşık Değer

Hoca bu soruyu belki daha önce çözmüş olabileceklerini, ama yeniden çözmek istediğini söyledi.

**Soru:** $g$ türevlenebilir (differentiable) bir fonksiyon olsun. $g(1) = 4$ ve $g'(1) = 4$ şartları sağlansın.

$$f(x) = \frac{g(x^2)}{1 + x^2}$$

olarak veriliyor. $f(1{,}25)$ değerini yaklaşık olarak hesaplayın.

<!-- BELİRSİZ: 01:37:22 civarında altyazıda "g of 1, g prime of 1, is equal to 4" geçiyor; çözümde hem g(1) = 4 hem g'(1) = 4 kullanıldığı için şart böyle yazıldı. -->

Hoca "yaklaşık" için bazılarının farklı bir sembol kullandığını, bunun tercihe bağlı olduğunu söyledi. Bu, doğrusallaştırma (linearization), doğrusal yaklaşım (linear approximation) ya da diferansiyel (differential) yöntemiyle çözülür. Hoca böyle bir sorunun test sınavında ya da finalde görülebileceğini söyledi.

> **Hocanın vurgusu:** Teğet ve normal doğru soruları da bu şekilde sorulabilir. Fonksiyon açıkça verilmez; bir $g$ ve sağladığı bazı koşullar verilir, $f$ bunun üzerinden tanımlanır. Hocalar bu tür soruları sormayı seviyor.

### 11.1 Türev

Bölüm kuralı ve zincir kuralı kullanılır ($g(x^2)$'nin türevi $g'(x^2)\cdot 2x$'tir):

$$f'(x) = \frac{g'(x^2)\cdot 2x\cdot(1 + x^2) - g(x^2)\cdot 2x}{(1 + x^2)^2}.$$

### 11.2 Yaklaşım noktası

$a = 1$ seçilir. Çünkü $1$, $1{,}25$'e yakındır ve $g$'nin $1$'deki değerleri bilinir.

$$f'(1) = \frac{g'(1)\cdot 2\cdot 2 - g(1)\cdot 2}{2^2} = \frac{4\cdot 4 - 4\cdot 2}{4} = \frac{16 - 8}{4} = 2.$$

$$f(1) = \frac{g(1)}{1 + 1} = \frac{4}{2} = 2.$$

### 11.3 Doğrusallaştırma

Diferansiyel ilişki şudur:

$$\Delta f \approx f'(1)\,\Delta x, \qquad \Delta f = f(x) - f(1), \qquad \Delta x = x - 1.$$

$\Delta f$ açılırsa

$$f(x) \approx f(1) + f'(1)(x - 1) = 2 + 2(x - 1).$$

Hocanın ifadesiyle, doğrusal olmayan $f$ grafiği, $a = 1$'deki bu doğruyla yaklaşık olarak temsil edilir. $x = 1{,}25$ konur ($\Delta x = 0{,}25$):

$$f(1{,}25) \approx 2 + 2\cdot 0{,}25 = 2{,}5 = \frac{5}{2}.$$

**Cevap:** $f(1{,}25) \approx \dfrac{5}{2} = 2{,}5$. (sympy ile $f'(1) = g'(1) - \dfrac{g(1)}{2} = 2$ doğrulandı.)

Hoca bunun anlaşılır bir soru olduğunu söyledi; soru soran olmadı.

## 12. Örnek 11: $\dfrac{\infty}{\infty}$ Belirsizliği ve L'Hôpital Kuralının Mantığı

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to\infty}\frac{e^{\arctan x} - x}{\ln(1 + x^2) + x}$$

Hoca bunun basit bir limit sorusu olduğunu, herkesin en fazla iki dakikada çözmesi gerektiğini söyledi. Öğrencilerden gelen cevaplar arasında $-1$'i doğru kabul etti.

<!-- BELİRSİZ: 01:46:34-01:47:00 arasında paydanın ifadesi altyazıda "ln 1 plus ekstrem" diye bozuk geçiyor. L'Hôpital adımında paydanın türevi "2x over 1 plus x square" ve "derivation of x, 1" olarak okunduğu için payda ln(1 + x^2) + x olarak yazıldı. -->

### 12.1 Belirsizliğin türü

$x \to \infty$ iken $\arctan x \to \dfrac{\pi}{2}$'dir. Yani $e^{\arctan x}$ bir sabite ($e^{\pi/2}$) gider. Pay $-\infty$'a, payda $+\infty$'a gider. Belirsizlik $\dfrac{\infty}{\infty}$'dur. L'Hôpital kuralı uygulanabilir.

### 12.2 Gerekli türev formülleri

Hoca şu temel formülleri hatırlattı:

- $(e^{u})' = e^{u}\,u'$.
- $(\arctan u)' = \dfrac{u'}{1 + u^2}$.
- $(\ln u)' = \dfrac{u'}{u}$.

### 12.3 L'Hôpital

$$\lim_{x\to\infty}\frac{e^{\arctan x}\cdot\dfrac{1}{1 + x^2} - 1}{\dfrac{2x}{1 + x^2} + 1}.$$

Hoca önce bu ifadeyi sadeleştirmeye başladı (payda eşitleyip ters çevirip çarptı), sonra buna gerek olmadığını fark edip sildi: "Zaten daha doğrudan geliyor, ben niye uzatıyorum ki?" $x \to \infty$ iken:

- $e^{\arctan x}$ bir sabite gider, $\dfrac{1}{1 + x^2} \to 0$. Paydaki ilk terim $0$'a gider.
- $\dfrac{2x}{1 + x^2} \to 0$.

$$\frac{0 - 1}{0 + 1} = -1.$$

**Cevap:** $-1$. (sympy ile doğrulandı.)

### 12.4 Öğrenci sorusu: $\dfrac{2x}{1 + x^2}$ neden $0$'a gidiyor?

**Soru:** $\dfrac{2x}{1 + x^2}$ yine $\dfrac{\infty}{\infty}$ olmuyor mu? Neden $0$'a gidiyor dediniz?

**Cevap:** Hoca polinomların derecelerini karşılaştırdı. $2x$'in derecesi 1'dir. $1 + x^2$'nin derecesi 2'dir. $x \to \infty$ iken $1 + x^2$ daha hızlı artar. Payın derecesi paydanınkinden küçük olduğu için sonuç doğrudan $0$'dır.

**Soru:** Payın derecesi büyük olduğunda ne olur?

**Cevap:** O zaman sonuç sonsuz olur. Hoca aynı ifadeyi ters çevirerek gösterdi:

$$\lim_{x\to\infty}\frac{1 + x^2}{2x}.$$

$1 + x^2$, $2x$'e göre daha hızlı arttığı için sonuç $\infty$'dur. L'Hôpital ile de aynı şey görülür: Yine $\dfrac{\infty}{\infty}$ vardır. $1 + x^2$'nin anlık değişim oranı $2x$, $2x$'in anlık değişim oranı $2$'dir. $\dfrac{2x}{2} = x \to \infty$.

Hoca burada L'Hôpital kuralının mantığını anlattı. Türev, anlık değişim oranıdır (instantaneous rate of change). İki fonksiyonun oranının limiti, bu fonksiyonların anlık değişim oranlarının oranının limitine eşittir. L'Hôpital kuralı budur. Bu yüzden polinomlarda L'Hôpital'i uzun uzun uygulamaya gerek yoktur; sonuç dereceler karşılaştırılarak zihinden görülebilir.

> **Ek bilgi (derste anlatılmadı):** Genel olarak $p$ ve $q$ polinomları için $x \to \infty$ iken $\dfrac{p(x)}{q(x)}$'in limiti, payın derecesi küçükse $0$, dereceler eşitse baş katsayıların oranı, payın derecesi büyükse $\pm\infty$'dur. L'Hôpital kuralı, derece eşitlenene ya da biri sabite inene kadar tekrar uygulanarak aynı sonucu verir.

## Örnek Sorular

Bu derste video ve kare yoktur. Aşağıdaki sorular derste hocanın öğrencilere çözmeleri için sorduğu sorulardır. Çözümler yukarıdaki ilgili bölümlerdedir.

1. (derste sözlü, 00:10:07) $\displaystyle\lim_{x\to 1}\big(1 + \sin(x-1)\big)^{\frac{1}{x-1}}$ limitini hesaplayın. Cevap: $e$ (Bölüm 2).
2. (derste sözlü, 00:17:16) $f(x) = \arccos\left(\dfrac{x-5}{2}\right) + \ln(6 - x) + \sin\sqrt[3]{x-2}$ fonksiyonunun tanım kümesini bulun. Cevap: $[3, 6)$ (Bölüm 3).
3. (derste sözlü, 00:23:20) $f(x) = \ln\big(\ln(\ln x)\big) + \sqrt{9 - x^2}$ fonksiyonunun tanım kümesini bulun. Cevap: $(e, 3]$ (Bölüm 4).
4. (derste sözlü, 00:29:43) $f(x) = \arcsin\sqrt{1 - x^2}$ fonksiyonunun artan ve azalan olduğu aralıkları bulun. Cevap: $(-1, 0)$'da artan, $(0, 1)$'de azalan (Bölüm 5).
5. (derste sözlü, 00:44:16) $f: \mathbb{R} \to \mathbb{R}$, $f(x) = x\sqrt{8 + x^2}$ ise $(f^{-1})'(3)$ nedir? Cevap: $\dfrac{3}{10}$ (Bölüm 6).
6. (derste sözlü, 00:52:37) $\displaystyle\lim_{x\to 0^+}\left(\frac{1}{x} - \frac{1}{\sqrt{x}}\right)$ limitini hesaplayın. Cevap: $+\infty$ (Bölüm 7).
7. (derste sözlü, 01:01:08) $\displaystyle\lim_{x\to\infty} x^2\left(1 - \cos\frac{1}{x}\right)$ limitini hesaplayın. Cevap: $\dfrac{1}{2}$ (Bölüm 8).
8. (derste sözlü, 01:06:12) $\displaystyle\lim_{x\to 0^+} x^{\frac{1}{\ln(e^x - 1)}}$ limitini hesaplayın. Cevap: $e$ (Bölüm 9).
9. (derste sözlü, 01:26:09) $x^{y} = 2y$ eğrisinin $P(2, 1)$ noktasındaki teğet ve normal doğrularının denklemlerini (varsa) bulun. Cevap: Teğet $y - 1 = \dfrac{1}{2(1 - \ln 2)}(x - 2)$, normal $y - 1 = 2(\ln 2 - 1)(x - 2)$ (Bölüm 10).
10. (derste sözlü, 01:37:02) $g$ türevlenebilir, $g(1) = 4$, $g'(1) = 4$ ve $f(x) = \dfrac{g(x^2)}{1 + x^2}$ ise $f(1{,}25)$'in yaklaşık değeri nedir? Cevap: $\dfrac{5}{2}$ (Bölüm 11).
11. (derste sözlü, 01:46:34) $\displaystyle\lim_{x\to\infty}\frac{e^{\arctan x} - x}{\ln(1 + x^2) + x}$ limitini hesaplayın. Cevap: $-1$ (Bölüm 12). <!-- BELİRSİZ: paydanın ifadesi altyazıda bozuk; Bölüm 12'deki nota bakın. -->

## Dersin Toparlaması

Bu ders, birinci vizeden önce yapılan genel alıştırma dersiydi. Önce çalışma yöntemi konuşuldu: tanımlar ve kavramlar öğrenilmeden soru çözmenin işe yaramadığı, her sorunun arkasındaki mantığın anlaşılması gerektiği vurgulandı. Ardından on bir soru çözüldü. Limit sorularında her seferinde önce belirsizliğin türü ($1^\infty$, $\infty - \infty$, $0\cdot\infty$, $0^0$, $\dfrac{\infty}{\infty}$) belirlendi. $1^\infty$ ve $0^0$ biçimlerinde logaritmik yöntem kullanıldı ve sonucun $\ln A$'nın limiti olduğu, geri dönmek için üstel fonksiyonun uygulanması gerektiği hatırlatıldı. $\infty - \infty$ ve $0\cdot\infty$ biçimlerinde ifade önce bölüme çevrildi; $t = \dfrac{1}{x}$ gibi bir dönüşümün işi kolaylaştırdığı gösterildi.

Tanım kümesi sorularında arccos/arcsin için argümanın $[-1, 1]$'de, $\ln$ için argümanın pozitif, çift dereceli kök için kök içinin negatif olmaması gerektiği kullanıldı; iç içe logaritmada dıştan içe gidildi. Artan/azalan sorusunda önce tanım kümesinin bulunması gerektiği özellikle vurgulandı. Ters fonksiyonun türevi $f^{-1}$ bulunmadan zincir kuralıyla hesaplandı. Kapalı eğride teğet ve normal doğru, logaritma ve kapalı türev ile bulundu. Doğrusallaştırma ile $f(1{,}25)$ yaklaşık olarak hesaplandı. Ders, L'Hôpital kuralının anlık değişim oranlarının oranı olarak yorumlanmasıyla bitti. Hoca gelecek hafta da genel soru çözümü yapılacağını söyledi ve limit, türev, L'Hôpital, ters fonksiyon, artanlık-azalanlık gibi genel kuralların bir kâğıda özetlenip soru çözerken yanda tutulmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
