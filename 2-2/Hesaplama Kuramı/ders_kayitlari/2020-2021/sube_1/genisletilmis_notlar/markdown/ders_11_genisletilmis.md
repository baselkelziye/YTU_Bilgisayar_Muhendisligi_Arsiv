# Ders 11 Genişletilmiş Notu: Turing Makineleri ve Turing Makineleriyle Fonksiyon Hesaplama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dil Hiyerarşisi ve Turing Makinesine Geçiş
- 2. Turing Makinesinin Yapısı
- 3. Geçişler ve Örnek Adımlar
- 4. Belirlenimcilik ve Epsilon Geçişleri
- 5. Kısmi Geçiş Fonksiyonu, Durma ve Son Durumlar
- 6. Kabul ve Ret
- 7. Düzenli Diller için Turing Makinesi Örnekleri
- 8. Sonsuz Döngü Örneği
- 9. Tablette Çözülen Örnek: $b(a+b)^*b$
- 10. $\{a^nb^n\}$ için Turing Makinesi
- 11. Biçimsel Tanımlar
- 12. Turing Makineleriyle Fonksiyon Hesaplama
- 13. Turing Makinelerinin Birleştirilmesi
- Örnek Sorular

## 1. Dil Hiyerarşisi ve Turing Makinesine Geçiş

Önceki haftalarda NFA ve DFA ile düzenli diller, PDA (yığıtlı otomat) ile bağlamdan bağımsız diller incelendi. Bu derste bağlamdan bağımsız dillerden daha güçlü dilleri tanıyan makineye, Turing makinesine geçiliyor.

Slayttaki dil hiyerarşisi şöyledir (ekrandan, 00:05:00):

- Düzenli diller: $a^*$, $a^*b^*$. Düzenli dil, onu tanıyan en az bir NFA ya da DFA bulunan dildir; bu diller düzenli ifadelerle tanımlanır.
- Bağlamdan bağımsız diller: $a^nb^n$, $ww^R$. Bunlar için NFA/DFA tasarlanamaz; CFG ve PDA gerekir.
- Bu iki kümenin dışında: $a^nb^nc^n$ ve $ww$.

$a^nb^nc^n$ dilinde $a$ sayısı $b$ sayısına, $b$ sayısı da $c$ sayısına eşit olmalıdır; yani birden fazla ilişki vardır. Hoca bu yüzden dilin bağlamdan bağımsız olmadığını, CFG'si olmadığı için onu tanıyan bir PDA da olmadığını söyledi. $ww$ dili de (bir dizginin kendisiyle birleştirilmesi) bu gruptadır. Bu diller daha güçlü bir makineyle, Turing makinesiyle tanınır.

İkinci slaytta hoca her kümenin yanına makinesini çizdi (ekrandan, 00:10:00): düzenli diller için yalnız durumlardan oluşan bir otomat, bağlamdan bağımsız diller için durumlar ve bir yığıt (stack), Turing makinesinin tanıdığı diller için durumlar ve bir şerit (tape). Hocaya göre bugünkü bilgisayarlar, cep telefonları da birer Turing makinesi olarak görülebilir.

> **Ek bilgi (derste anlatılmadı):** $a^nb^nc^n$'nin bağlamdan bağımsız olmadığı, bağlamdan bağımsız diller için pompalama önsavıyla ispatlanır. "Birden fazla ilişki var" sezgisi tek başına ispat sayılmaz.

## 2. Turing Makinesinin Yapısı

Turing makinesinin üç parçası vardır:

- **Şerit (tape):** Uzunluğu sonsuzdur. Her hücre bir simge tutar. Makinenin belleği budur.
- **Kafa (head):** Şeritten okur ve şeride yazar. Her adımda bir hücre sola ya da sağa gider.
- **Kontrol birimi:** Durumları ve geçişleri tutar. Kafanın okuduğu değere göre durum değişir, sonunda son durumlara ulaşılır.

Hoca bunu PDA ile karşılaştırdı: PDA'da da kontrol birimi vardır ama bellek bir yığıttır ve yalnız tepesine erişilir. Turing makinesinin kontrolü daha karmaşık, belleği daha esnektir; bu yüzden PDA'dan çok daha güçlüdür ve birçok bilimsel problem Turing makinesiyle çözülebilir. Hoca, Turing makinesiyle çözülemeyen problemlerin de bulunduğunu belirtti.

> **Ders sonrası not:** Hoca, Turing makinesiyle çözülemeyen bazı problemler için kuantum makineleri gibi daha güçlü makinelerin kullanıldığını söyledi. Kuantum bilgisayarlar bazı problemleri daha hızlı çözebilir, ama büyük olasılıkla Turing makinesinin hesaplayamadığı bir fonksiyonu hesaplayamaz; hesaplanabilirlik açısından Turing makinesinden güçlü değildir.

Her adımda kafa üç iş yapar:

1. Kafanın altındaki simgeyi okur.
2. O hücreye bir simge yazar (aynı simge de olabilir).
3. Sola (L) ya da sağa (R) bir hücre gider.

### 2.1 Giriş dizgisi ve boş simge

Slayttaki şeritte giriş dizgisi $abac$'dir; iki yanındaki hücrelerde $\Diamond$ vardır (ekrandan, 00:15:00). $\Diamond$ boş simgedir (blank): şeridin o kısımlarının kullanılmadığını gösterir. Böylece giriş dizgisinin nerede başladığı ve nerede bittiği anlaşılır. Hoca bunu C'deki dizgi sonu karakterine (null) benzetti: null dizginin sonunu ya da kullanılmayan belleği gösterir, $\Diamond$ de kullanılmayan hücreleri gösterir. $\Diamond$ yerine \$, $\Delta$ ya da 0 gibi başka bir simge de seçilebilir; önemli olan tutarlı kullanmaktır.

> **Hocanın vurgusu:** Kafa her zaman giriş dizgisinin en soldaki simgesinden başlar. Bu bir kuraldır ve çok önemlidir.

## 3. Geçişler ve Örnek Adımlar

Bir geçiş $q_1 \xrightarrow{a\to b,\,R} q_2$ biçiminde yazılır. Anlamı: makine $q_1$'de ve kafanın altında $a$ varsa, $a$ okunur, yerine $b$ yazılır, kafa sağa gider ve durum $q_2$ olur. Kafanın altında $a$ yoksa bu geçiş geçerli değildir. Hoca bunu PDA'da yığıta simge itmeye benzetti; farkı, Turing makinesinde ayrıca sola ya da sağa hareket edilmesidir.

**Örnek 1 (ekrandan, 00:20:00).** Zaman 1: şerit $\Diamond\Diamond\,a\,b\,a\,c\,\Diamond\Diamond$, kafa üçüncü giriş simgesi $a$'nın üstünde, durum $q_1$. Geçiş $a\to b,R$:

- Kafanın altında $a$ var, geçiş geçerli.
- $a$ yerine $b$ yazılır: şerit $a\,b\,b\,c$ olur.
- Kafa bir sağa, $c$'nin üstüne gider. Zaman 2'de durum $q_2$'dir.

**Örnek 2.** Aynı başlangıçta geçiş $a\to b,L$ olsaydı şerit yine $abbc$ olur, ama kafa sola gider ve $b$'nin (ikinci simge) üstünde durur; durum $q_2$ olur.

**Örnek 3.** Kafa giriş dizgisinin sağındaki ilk $\Diamond$'ın üstünde ve durum $q_1$ iken $\Diamond\to g,R$ geçişi uygulanır: $\Diamond$ okunur, yerine $g$ yazılır, kafa sağa gider, durum $q_2$ olur. Yani $\Diamond$ da bir simgedir ve üzerine yazılabilir.

## 4. Belirlenimcilik ve Epsilon Geçişleri

Turing makineleri belirlenimcidir (ekrandan, 00:25:00):

- **İzinli:** $q_1 \xrightarrow{a\to b,R} q_2$ ve $q_1 \xrightarrow{b\to d,L} q_3$. Okunan simgeler farklı olduğu için hangi geçişin uygulanacağı bellidir.
- **İzinli değil:** $q_1 \xrightarrow{a\to b,R} q_2$ ve $q_1 \xrightarrow{a\to d,L} q_3$. Kafanın altında $a$ varken iki geçiş de uygulanabilir olurdu. Tek bir kafa olduğu için aynı anda hem $b$ yazıp sağa hem $d$ yazıp sola gidilemez.

Epsilon geçişleri de yoktur. Hocanın gerekçesi: her hücreye bir simge yazılır ve her simgenin uzunluğu 1'dir; boş dizginin uzunluğu ise 0'dır. Bu yüzden her adımda mutlaka bir simge okunur ve yazılır.

> **Hocanın vurgusu:** Turing makineleri belirlenimcidir ve epsilon geçişi yoktur. Bu çok önemlidir.

> **Ek bilgi (derste anlatılmadı):** Belirlenimci olmayan Turing makineleri de tanımlanır, ama tanıdıkları dil sınıfı belirlenimci Turing makinelerininkiyle aynıdır. Bu derste kullanılan standart model belirlenimcidir.

## 5. Kısmi Geçiş Fonksiyonu, Durma ve Son Durumlar

### 5.1 Kısmi geçiş fonksiyonu

Her durumda her simge için geçiş tanımlanmak zorunda değildir. Örnekte şerit $abac$, kafa ilk $a$'nın üstünde, durum $q_1$; $q_1$'den $a\to b,R$ ile $q_2$'ye ve $b\to d,L$ ile $q_3$'e giden geçişler var. Kafanın altında $a$ olduğu için yalnız birinci geçiş geçerlidir: $a$ yerine $b$ yazılır, kafa sağa gider, durum $q_2$ olur.

### 5.2 Durma (halt)

Makine, izleyeceği bir geçiş kalmadığında durur. Örnekler:

- Durum $q_1$, kafanın altında $c$ var ve $q_1$'den hiç çıkan geçiş yok: makine durur.
- Durum $q_1$, kafanın altında $c$ var; $q_1$'den $a\to b,R$ ile $q_2$'ye ve $b\to d,L$ ile $q_3$'e geçişler var. İkisi de $c$ için geçerli olmadığından makine durur.

$q_1$ son durum olmadığı için iki durumda da giriş reddedilir.

### 5.3 Son durumlar

Turing makinesinde başlangıç durumundan son durumlara doğru bir geçiş akışı vardır. Son (kabul) durumlarından çıkan geçiş yoktur; son duruma ulaşıldığında makine durur.

> **Hocanın vurgusu:** Son durumdan çıkan geçiş olamaz. Sınavda son durumdan çıkan geçiş çizip "çözümüm doğru" diyen çözümler, Turing makinesinin tanımına aykırı olduğu için doğru sayılmaz.

## 6. Kabul ve Ret

Slayta göre (ekrandan, 00:35:00):

- **Kabul:** Makine bir kabul (son) durumunda durursa giriş dizgisi kabul edilir.
- **Ret:** Makine kabul olmayan (son olmayan) bir durumda durursa ya da sonsuz döngüye girerse giriş dizgisi reddedilir.

Yani üç olası sonuç vardır: son durumda durmak (kabul), son olmayan durumda durmak (ret), hiç durmamak (ret).

**Gözlem:** Bir dizgiyi kabul etmek ya da reddetmek için dizgideki bütün simgeleri taramak gerekmez. Makine geçişlere göre karar verir; bazen dizginin başını okuması yeter. Hoca bunu dersin en önemli gözlemi olarak sundu.

> **Ders sonrası not:** Hoca bu gözlemden Turing makinesinin PDA ya da NFA/DFA'dan "çok daha hızlı" olduğu sonucunu çıkardı. Bu, büyük olasılıkla yalnız bazı özel örnekler için geçerlidir; genelde Turing makinesinin üstünlüğü hız değil, tanıyabildiği dillerin daha geniş olmasıdır.

## 7. Düzenli Diller için Turing Makinesi Örnekleri

### 7.1 $\Sigma=\{a,b\}$, $L = a^*$

Slayttaki makine (ekrandan, 00:40:00):

- $q_0$ başlangıç durumu; $q_0$'da $a\to a,R$ döngüsü.
- $q_0 \xrightarrow{\Diamond\to\Diamond,L} q_1$; $q_1$ son durum.

Hoca dili tablette $L=\{\varepsilon, a, aa, aaa, \ldots\}$ diye yazdı. Makine $a$'ları değiştirmeden sağa doğru okur; $\Diamond$'ı görünce bir sola gidip son duruma geçer. Boş girişte kafa doğrudan $\Diamond$'ın üstündedir; makine hemen $q_1$'e geçer ve $\varepsilon$'u kabul eder.

Hoca ardından $\varepsilon$'u içermeyen $\{a, aa, aaa, \ldots\}$ dili için de tablette bir makine çizdi. Bu makinede ilk $a$ okunup başka bir duruma geçilir; $a$ yerine aynı $a$ ya da örneğin $x$ yazılabilir. Hoca, okunan ve yazılan simgelerin seçilen algoritmaya bağlı olduğunu vurguladı. <!-- BELİRSİZ: Bu el yazısı makinenin tam geçişleri altyazıdan ve okunan karelerden çıkarılamadı. -->

**$aaa$ girişi.** Zaman 0'da kafa ilk $a$'da, durum $q_0$. Üç kez $a\to a,R$ uygulanır; kafa $\Diamond$'a gelir. $\Diamond\to\Diamond,L$ ile kafa son $a$'ya döner ve durum $q_1$ olur. $q_1$ son durum olduğundan $aaa$ kabul edilir.

**$aba$ girişi.** Zaman 0'da $a\to a,R$ uygulanır. Zaman 1'de kafa $b$'nin üstünde, durum $q_0$ (ekrandan, 00:45:00). $q_0$'dan $b$ için geçiş yoktur: makine durur ve $q_0$ son durum olmadığından dizgi reddedilir. Üçüncü simge $a$ hiç taranmamıştır.

### 7.2 $\Sigma=\{a\}$, $L=a^*$

Alfabede yalnız $a$ varsa $a^*$ dışında bir dizgi gelemez. Hoca bu durumda başlangıç durumunun aynı zamanda son durum olduğu, hiç geçişi olmayan tek durumlu bir makinenin yeterli olduğunu anlattı: makine $q_0$'da başlar, izleyeceği geçiş olmadığı için hemen durur ve son durumda olduğu için girişi kabul eder. Hoca, alfabe $\{a,b\}$ olsaydı bu makinenin yanlış olacağını vurguladı.

## 8. Sonsuz Döngü Örneği

Dil $L = a^* + b(a+b)^*$. Makine (ekrandan, 00:50:00):

- $q_0$'da iki döngü: $a\to a,R$ ve $b\to b,L$.
- $q_0 \xrightarrow{\Diamond\to\Diamond,L} q_1$; $q_1$ son durum.

### 8.1 $aba$ girişi: sonsuz döngü

- Zaman 0: kafa $a$'da, $q_0$. $a\to a,R$; kafa $b$'ye geçer.
- Zaman 1: kafa $b$'de, $q_0$ (ekrandan, 01:05:00). $b\to b,L$; kafa yeniden $a$'ya döner.
- Zaman 2: yine $a\to a,R$, sonra yine $b\to b,L$...

Kafa birinci ve ikinci hücre arasında sonsuza dek gidip gelir. Son duruma hiç ulaşılmaz; giriş reddedilir. $ab$ ile başlayan her dizgi aynı döngüye girer.

### 8.2 $aaa$ girişi

Kafa üç $a$'yı sağa doğru geçer, $\Diamond$'a gelir, $\Diamond\to\Diamond,L$ ile $q_1$'e geçer: kabul.

### 8.3 $b$ ile başlayan giriş

Kafa ilk simgede $b$ okur, $b\to b,L$ ile sola, $\Diamond$'ın üstüne gider. Ardından $\Diamond\to\Diamond,L$ ile $q_1$'e geçer: kabul. Kalan simgelere hiç bakılmaz.

### 8.4 Hocanın Türkçe özeti

Dil iki parçanın birleşimidir. Birinci parça $a^*$: boş dizgi de dahil yalnız $a$'lardan oluşan dizgiler. İkinci parça $b(a+b)^*$: $b$ ile başlayan dizgiler. Alfabe $\{a,b\}$ olduğu için $b$'den sonra ne gelirse gelsin dizgi dildedir; bu yüzden ilk simge $b$ ise hemen kabul edilebilir. Makine başta $b$ görürse bir sola gidip $\Diamond$'a ulaşır ve son duruma geçer. Yalnız $a$'lar varsa $\Diamond$'a kadar sağa gider ve son duruma geçer. İkisinin birleşimiyle $a^*+b(a+b)^*$ tanınır.

Python ile yapılan benzetimde bu makine, uzunluğu 7'ye kadar olan bütün $\{a,b\}$ dizgilerinde $a^*+b(a+b)^*$ ile aynı kararı verdi; $aba$ için döngüden çıkmadı.

## 9. Tablette Çözülen Örnek: $b(a+b)^*b$

Düzenli ifade $r = b(a+b)^*b$ (ekrandan, 01:15:00). Dil, $b$ ile başlayıp $b$ ile biten dizgilerdir; en kısa eleman $bb$'dir (uzunluk 2). Hoca örnekleri yazdı (ekrandan, 01:20:00):

- $b \notin L(r)$
- $bb \in L(r)$
- $baab \in L(r)$
- $bab \in L(r)$

Tablette çizilen makine (ekrandan, 01:20:00; durum adları hocanın 01:20'deki anlatımından):

| Geçiş | Etiket |
|---|---|
| $q_0 \to q_1$ | $b\to b,R$ |
| $q_1 \to q_2$ | $a\to a,R$ |
| $q_1 \to q_3$ | $b\to b,R$ |
| $q_2 \to q_3$ | $b\to b,R$ |
| $q_3 \to q_1$ | $a\to a,R$ |
| $q_3 \to q_4$ (son) | $\Diamond\to\Diamond,L$ |

Fikir: ilk simge $b$ olmalıdır ($q_0\to q_1$). Sonra okunan son simgenin $a$ mı $b$ mi olduğu durumlarla izlenir. Son okunan $b$ iken ($q_3$) $\Diamond$ görülürse dizgi $b$ ile bitmiştir ve kabul edilir.

İkinci aradan sonra hoca bu çizimde bir döngüyü unuttuğunu söyledi. Örneğin $bbb$ dilin elemanıdır, ama döngü olmadan makine bunu tanıyamaz. Hoca eksik döngüyü kırmızıyla ekledi ve öğrencilerden notlarını düzeltmelerini istedi. <!-- BELİRSİZ: Eklenen döngünün çizimi kayıttaki karelerde görünmüyor; aşağıdaki düzeltme benzetimden çıkarıldı. -->

> **Ders sonrası not:** Çizildiği hâliyle makinede $q_3$'te $b$ için ve $q_2$'de $a$ için geçiş yoktur. $bbb$ için $q_3$'te $b\to b,R$ döngüsü gerekir. $baab$ için ise $q_2$'de $a\to a,R$ döngüsü de gerekir; yoksa $q_2$'de ikinci $a$ okunurken makine durur ve dizgiyi reddeder. Python benzetimine göre iki döngü eklenince makine, uzunluğu 7'ye kadar olan bütün $\{a,b\}$ dizgilerinde $b(a+b)^*b$'yi doğru tanır; yalnız $q_3$'teki döngüyle 20 dizgide (örneğin $baab$) hâlâ hata vardır.

> **Hocanın vurgusu:** Bir düzenli ifade verilip Turing makinesinin tasarlanması istenebilir. Hoca bunu basit bir soru türü olarak gösterdi.

## 10. $\{a^nb^n\}$ için Turing Makinesi

Turing makinesi PDA'dan da, NFA/DFA'dan da güçlü olduğu için bağlamdan bağımsız dilleri de tanıyabilir. Örnek: $\{a^nb^n : n\ge 1\}$. $a$ sayısı $b$ sayısına eşittir; en kısa eleman $ab$'dir, $\varepsilon$ dilde değildir.

### 10.1 Makine

Slayttaki makine (ekrandan, 01:25:00):

| Durum | Okunan | Yazılan, hareket | Sonraki durum |
|---|---|---|---|
| $q_0$ | $a$ | $x, R$ | $q_1$ |
| $q_0$ | $y$ | $y, R$ | $q_3$ |
| $q_1$ | $a$ | $a, R$ | $q_1$ |
| $q_1$ | $y$ | $y, R$ | $q_1$ |
| $q_1$ | $b$ | $y, L$ | $q_2$ |
| $q_2$ | $a$ | $a, L$ | $q_2$ |
| $q_2$ | $y$ | $y, L$ | $q_2$ |
| $q_2$ | $x$ | $x, R$ | $q_0$ |
| $q_3$ | $y$ | $y, R$ | $q_3$ |
| $q_3$ | $\Diamond$ | $\Diamond, L$ | $q_4$ (son) |

### 10.2 Algoritma

1. En soldaki $a$'yı $x$ ile değiştir ($q_0\to q_1$).
2. Sağa doğru $a$ ve $y$'lerin üzerinden geç; en soldaki $b$'yi bul ve $y$ ile değiştir ($q_1\to q_2$).
3. Sola doğru $a$ ve $y$'lerin üzerinden geç; $x$'i bulunca bir sağa geç ve $q_0$'a dön.
4. $a$ ve $b$ kalmayana dek tekrarla.
5. $q_0$'da $a$ yerine $y$ görülürse bütün $a$'lar $x$ olmuştur. Sağa doğru yalnız $y$'ler okunup $\Diamond$'a varılırsa ($q_3$) bütün $b$'ler de $y$ olmuştur: $x$ sayısı $y$ sayısına, yani $a$ sayısı $b$ sayısına eşittir. Makine $q_4$'te kabul eder.

Bir $a$ ya da $b$ artarsa makine bir yerde geçiş bulamaz ve son olmayan bir durumda durarak dizgiyi reddeder. Hoca bunu durumların ve şerit içeriğinin $a$ ve $b$ sayısını saymak için kullanılması diye açıkladı.

### 10.3 $aaabbb$ üzerinde fikir

Hoca tablette şeridin her turdaki hâlini yazdı (ekrandan, 01:30:00):

```text
a a a b b b
x a a y b b
x x a y y b
x x x y y y
```

### 10.4 $aabb$ izlemesi

- Zaman 0: $\underline{a}abb$, $q_0$. $a\to x,R$: $x\underline{a}bb$, $q_1$.
- $q_1$'de $a\to a,R$: $xa\underline{b}b$.
- $q_1$'de $b\to y,L$: $x\underline{a}yb$, $q_2$.
- $q_2$'de $a\to a,L$: $\underline{x}ayb$.
- $q_2$'de $x\to x,R$: $x\underline{a}yb$, $q_0$. Böylece bir $a$ $x$'e, bir $b$ $y$'ye çevrilmiştir.
- İkinci tur: $a\to x,R$ ile $xx\underline{y}b$, $q_1$; $y\to y,R$ ile $xxy\underline{b}$; $b\to y,L$ ile $xx\underline{y}y$, $q_2$; $y\to y,L$ ile $x\underline{x}yy$; $x\to x,R$ ile $xx\underline{y}y$, $q_0$.
- $q_0$'da $y$ okunur: $y\to y,R$ ile $q_3$. $q_3$'te $y\to y,R$ ile kafa $\Diamond$'a gelir.
- $\Diamond\to\Diamond,L$ ile kafa son simgeye döner ve durum $q_4$ olur: kabul.

Döngü iki kez dönmüştür; yani $a$ sayısı da $b$ sayısı da 2'dir. Python benzetimi $aabb$ için şeridin sonunda $xxyy$, $aaabbb$ için $xxxyyy$ verdi; ikisinde de makine $q_4$'te kabul etti. Uzunluğu 8'e kadar olan bütün $\{a,b\}$ dizgilerinde makine yalnız $a^nb^n$ ($n\ge1$) dizgilerini kabul etti.

### 10.5 $a^nb^nc^n$'e genişletme

Hoca, makine biraz değiştirilerek $\{a^nb^nc^n\}$ için de bir Turing makinesi kurulabileceğini söyledi ve bunu öğrencilere bıraktı.

## 11. Biçimsel Tanımlar

### 11.1 Geçiş fonksiyonu

$q_1 \xrightarrow{a\to b,R} q_2$ geçişi şöyle yazılır (ekrandan, 01:40:00):

$$\delta(q_1,a) = (q_2, b, R)$$

Okunuşu: $q_1$ durumunda $a$ okunursa durum $q_2$ olur, $a$ yerine $b$ yazılır, kafa sağa gider. Benzer biçimde $q_1 \xrightarrow{c\to d,L} q_2$ için $\delta(q_1,c)=(q_2,d,L)$ yazılır.

### 11.2 Turing makinesinin yedilisi

$$M = (Q, \Sigma, \Gamma, \delta, q_0, \Diamond, F)$$

- $Q$: durumlar kümesi.
- $\Sigma$: giriş alfabesi.
- $\Gamma$: şerit alfabesi.
- $\delta$: geçiş fonksiyonu.
- $q_0$: başlangıç durumu. Her zaman tek bir başlangıç durumu vardır.
- $\Diamond$: boş simge.
- $F$: son durumlar kümesi.

$a^nb^n$ makinesinde $\Sigma=\{a,b\}$, $\Gamma=\{a,b,x,y,\Diamond\}$'dir. Genel olarak giriş alfabesi şerit alfabesinin alt kümesidir: $\Sigma\subseteq\Gamma$.

### 11.3 Yapılandırma ve anlık betim

Şerit $\Diamond\Diamond\,c\,a\,b\,a\,\Diamond\Diamond$, kafa $b$'nin üstünde ve durum $q_1$ ise yapılandırma şöyle yazılır (ekrandan, 01:45:00):

$$ca\,q_1\,ba$$

Kafanın solundaki dizgi ($ca$), durum ($q_1$) ve kafanın altındaki simgeden başlayarak sağdaki dizgi ($ba$) yan yana yazılır. Buna anlık betim (instantaneous description) denir. Hoca, anlık betimlerin makinenin içeriğinin adım adım nasıl değiştiğini izlemek için çok önemli olduğunu söyledi.

**Bir hamle.** $a^nb^n$ makinesinin $aabb$ izlemesinde Zaman 4: durum $q_2$, kafanın solunda yalnız boş hücreler var (bu yüzden solda bir şey yazılmaz), kafa $x$'in üstünde, şerit $xayb$. Dizi şöyledir:

$$q_2\,xayb \;\succ\; x\,q_0\,ayb$$

$x\to x,R$ ile kafa sağa geçmiş ve durum $q_0$ olmuştur. Bu bir hamledir ($\succ$). Sonraki hamlelerle:

$$q_2\,xayb \succ x\,q_0\,ayb \succ xx\,q_1\,yb \succ xxy\,q_1\,b$$

Dört zaman adımında durum $q_2\to q_0\to q_1\to q_1$ olmuş, şerit $xayb$'den $xxyb$'ye dönmüştür.

**Birçok hamle.** Bu dizinin kısaltması:

$$q_2\,xayb \overset{*}{\succ} xxy\,q_1\,b$$

$\overset{*}{\succ}$, sıfır ya da daha çok hamleden sonra soldaki yapılandırmadan sağdakine ulaşıldığını gösterir.

### 11.4 Başlangıç yapılandırması ve dil

Başlangıç yapılandırması $q_0\,w$'dir: durum $q_0$, kafanın solunda hiçbir şey yok, sağda bütün giriş $w$ var.

Turing makinesinin dili:

$$L(M) = \{\, w : q_0\,w \overset{*}{\succ} x_1\,q_f\,x_2,\ q_f\in F \,\}$$

Son durumlardan çıkan geçiş olmadığı için son duruma ulaşıldığında makine durur ve giriş kabul edilmiş olur.

### 11.5 Turing-tanınabilir diller

$L$ dili bir $M$ Turing makinesi tarafından kabul ediliyorsa $L$'ye Turing-tanınabilir (Turing-recognizable), Turing-kabul edilebilir (Turing-acceptable) ya da özyinelemeli sayılabilir (recursively enumerable) denir. Üç ad aynı anlamdadır.

## 12. Turing Makineleriyle Fonksiyon Hesaplama

### 12.1 "Computer" ve "hesaplayıcı"

Bu bölüme geçerken hoca Türkçe bir açıklama yaptı (ekrandan, 02:10:00 ve 02:15:00). "Computer" sözcüğünün kökü "compute", yani hesaplamaktır; karşılığı "hesaplayıcı"dır. Hoca, önceki derslerde gösterdiği, İngiltere'de bir bilim insanının domino taşlarıyla hesap yaptığı videoyu hatırlattı: o düzenek de bir bilgisayardır. Hoca, İngilizce konuşan küçük bir çocuğa "computer" denince abaküsün akla gelebileceğini, "bilgisayar" sözcüğünün ise hesaplama anlamını tam vermediğini söyledi.

Hocanın görüşüne göre bilgi sayılamaz, yalnız ölçülebilir; ölçüsü entropidir. Hoca entropiyi olasılığın eksi logaritması olarak yazdı: $-\log p$.

> **Ders sonrası not:** $-\log_2 p$, olasılığı $p$ olan bir olayın öz bilgisidir (self-information). Entropi bunun beklenen değeridir: $H = -\sum_i p_i \log_2 p_i$ (büyük olasılıkla hocanın kastettiği ilişki budur).

Hoca ayrıca "information" ile "knowledge" ayrımını kendi tanımıyla verdi: information bilinmeyen bilgi, knowledge bilinen bilgidir; bilinmeyeni bilinene dönüştüren bilimdir. Hocanın vardığı sonuç şudur:

> **Hocanın vurgusu:** Turing makinesi bir hesaplayıcıdır. Nasıl hesaplar? Sayarak (counting). Örneğin $a^nb^n$ makinesi $a$'ların ve $b$'lerin sayısını karşılaştırır.

### 12.2 Fonksiyon

Bir $f$ fonksiyonu, $D$ tanım kümesindeki bir $w$'yi $S$ sonuç kümesindeki $f(w)$'ye eşler. Yani fonksiyon iki uzay arasında bir eşlemedir. Fonksiyonun birden fazla parametresi olabilir; örneğin toplama fonksiyonu $f(x,y)=x+y$.

### 12.3 Birli (unary) gösterim

Turing makinelerinde sayılar birli gösterimle yazılır: 5 sayısı $11111$ ile, yani beş tane $1$ ile gösterilir. Turing makineleri birli gösterimi kolayca işler; birli gösterim saymaya dayanır.

### 12.4 Hesaplanabilir fonksiyon

$f$ fonksiyonu, tanım kümesindeki her $w$ için şu koşulu sağlayan bir $M$ Turing makinesi varsa hesaplanabilirdir (computable) (ekrandan, 02:20:00):

$$q_0\,w \overset{*}{\succ} q_f\,f(w)$$

Soldaki başlangıç yapılandırmasıdır: durum $q_0$, şeritte $w$. Sağdaki son yapılandırmadır: durum son durum $q_f$, şeritte $f(w)$. Birçok hamlenin sonunda şerit içeriği $w$'den $f(w)$'ye dönüşür.

### 12.5 Toplama: $f(x,y) = x+y$

$x$ ve $y$ tam sayılardır. Giriş dizgisi $x0y$, çıkış dizgisi $xy0$'dır; ikisi de birli gösterimdedir. $0$, iki sayıyı ayıran simgedir (ekrandan, 02:25:00).

**$3+5$ örneği.** Hoca tablette şunu yazdı:

```text
Giriş:  ◊ ◊ 1 1 1 0 1 1 1 1 1 ◊ ◊
Çıkış:  ◊ ◊ 1 1 1 1 1 1 1 1 0 ◊ ◊
```

Girişte $0$'ın solunda üç, sağında beş $1$ vardır. Çıkışta sekiz $1$ ve en sonda $0$ vardır: $3+5=8$. Yapılan iş, $0$ ile en sondaki $1$'in yer değiştirmesidir.

Hoca Türkçe olarak devam etti: toplama yapılabiliyorsa çıkarma da yapılabilir; sondaki $0$ birli dizide bir sola alınırsa bir çıkarılmış olur, iki sola alınırsa iki çıkarılmış olur. Toplama ve çıkarmayla çarpma, onların üzerine bölme kurulabilir; tam sayılardan gerçel sayılara genişletilebilir. Böylece bütün işlemler saymaya dayanan bir hesaplama ortamı ortaya çıkar.

**Makine** (ekrandan, 02:40:00):

| Durum | Okunan | Yazılan, hareket | Sonraki durum |
|---|---|---|---|
| $q_0$ | $1$ | $1, R$ | $q_0$ |
| $q_0$ | $0$ | $1, R$ | $q_1$ |
| $q_1$ | $1$ | $1, R$ | $q_1$ |
| $q_1$ | $\Diamond$ | $\Diamond, L$ | $q_2$ |
| $q_2$ | $1$ | $0, L$ | $q_3$ |
| $q_3$ | $1$ | $1, L$ | $q_3$ |
| $q_3$ | $\Diamond$ | $\Diamond, R$ | $q_4$ (son) |

Başlangıçta kafa $x$'in ilk $1$'inin üstündedir, durum $q_0$'dır (ekrandan, 02:35:00). Makine $0$'ı $1$ yapar, sağa giderek sondaki $\Diamond$'ı bulur, bir sola dönüp en sağdaki $1$'i $0$ yapar ve sola giderek başa döner.

**$2+2$ izlemesi.** Giriş $11011$:

- $q_0$'da iki kez $1\to1,R$; kafa $0$'a gelir.
- $0\to1,R$ ile $q_1$; şerit $11111$.
- $q_1$'de iki kez $1\to1,R$; kafa $\Diamond$'a gelir.
- $\Diamond\to\Diamond,L$ ile $q_2$; kafa son $1$'de (Zaman 6, ekrandan, 02:40:00).
- $1\to0,L$ ile $q_3$; şerit $11110$.
- $q_3$'te $1\to1,L$ ile başa kadar sola gidilir; $\Diamond$'da $\Diamond\to\Diamond,R$ ile $q_4$.

Şeritte dört $1$ vardır: $2+2=4$. Sondaki $0$, sonucun başka işlemlerde kullanılmasına yardım eder. Python benzetimi, $x,y\in\{0,\ldots,4\}$ için makinenin her zaman $1^{x+y}0$ ürettiğini doğruladı; $3+5$ için çıkış $111111110$'dır.

> **Hocanın vurgusu:** Hoca $2x+y$ ya da $x^2$ gibi fonksiyonlar için Turing makinesi istenebileceğini söyledi; çarpma, toplama ve çıkarma da Turing makinesiyle yapılabilir.

### 12.6 İkiye katlama: $f(x) = 2x$

Giriş birli gösterimde $x$, çıkış $2x$'tir. Sözde kod:

1. Her $1$'i \$ ile değiştir.
2. Tekrarla: en sağdaki \$'ı $1$ yap, sağa giderek sona bir $1$ ekle.
3. \$ kalmayana dek sürdür.

Yani her \$ iki $1$'e dönüşür. Makine (ekrandan, 02:45:00):

| Durum | Okunan | Yazılan, hareket | Sonraki durum |
|---|---|---|---|
| $q_0$ | $1$ | \$, $R$ | $q_0$ |
| $q_0$ | $\Diamond$ | $\Diamond, L$ | $q_1$ |
| $q_1$ | $1$ | $1, L$ | $q_1$ |
| $q_1$ | \$ | $1, R$ | $q_2$ |
| $q_2$ | $1$ | $1, R$ | $q_2$ |
| $q_2$ | $\Diamond$ | $1, L$ | $q_1$ |
| $q_1$ | $\Diamond$ | $\Diamond, R$ | $q_3$ (son) |

**$11$ örneği.** Başlangıç $11$, Bitiş $1111$, kafa en soldaki $1$'de, durum $q_3$ (ekrandan, 02:45:00). İzleme: $11\to\$\$$; sola dönülür; ikinci \$ $1$ yapılır, sona $1$ eklenir ($\$11$); sola dönülür; birinci \$ $1$ yapılır, sona $1$ eklenir ($1111$); sola dönülür, $\Diamond$'da $q_3$'e geçilir. Python benzetimi $x=1,\ldots,5$ için çıkışın $1^{2x}$ olduğunu doğruladı.

### 12.7 Karşılaştırma fonksiyonu

$$f(x,y)=\begin{cases}1 & x>y\\ 0 & x\le y\end{cases}$$

Hoca bunu birim basamak fonksiyonuyla ilişkilendirdi: $f(x,y)=u(x-y)$; burada $u(t)=1$ ($t>0$), $u(t)=0$ ($t\le 0$) olarak alınır. Sözde kod: $x$'teki $1$'leri $y$'deki $1$'lerle tek tek eşleştir; $x$'in $1$'leri artarsa sonuç $1$, değilse $0$'dır. Hoca, her eşlemenin Turing makinesiyle gerçeklenebileceğini söyledi ve sözde kodun bir programlama diline benzediğine dikkat çekti: program yazmak, makineye saymaya dayanan hesaplama adımlarını söylemektir.

## 13. Turing Makinelerinin Birleştirilmesi

Turing makineleri, girişi ve çıkışı olan bloklar gibi birleştirilebilir. Örnek fonksiyon:

$$f(x,y)=\begin{cases}x+y & x>y\\ 0 & x\le y\end{cases}$$

Blok çizimde bir karşılaştırıcı (comparator) Turing makinesi, bir toplayıcı (adder) ve bir silici (eraser) vardır. Karşılaştırıcının sonucuna göre ya toplayıcı ya da silici çalışır. Böylece basit Turing makineleri art arda bağlanarak daha karmaşık fonksiyonlar hesaplanır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00 ve 00:45:00). $\Sigma=\{a,b\}$ için $a^*$'ı tanıyan Turing makinesi verilmiştir: $q_0$'da $a\to a,R$; $q_0\xrightarrow{\Diamond\to\Diamond,L}q_1$ (son). $aaa$ ve $aba$ girişlerinde makine ne yapar?

> **Çözüm:** $aaa$: kafa üç $a$'yı geçer, $\Diamond$'da sola dönüp $q_1$'e geçer, kabul. $aba$: ikinci simgede $q_0$'da $b$ için geçiş yoktur, makine son olmayan $q_0$'da durur, ret.

**Soru 2** (ekrandan, 00:50:00 ve 01:05:00). $a^*+b(a+b)^*$ için verilen makinede ($q_0$'da $a\to a,R$, $b\to b,L$; $q_0\xrightarrow{\Diamond\to\Diamond,L}q_1$) $aba$, $aaa$ ve $bab$ girişlerinde ne olur?

> **Çözüm:** $aba$: kafa birinci ve ikinci hücre arasında gidip gelir; sonsuz döngü, ret. $aaa$: sona gidip $q_1$'de kabul. $bab$: ilk $b$'de sola, $\Diamond$'a gidilir, $q_1$'de kabul; kalan simgeler okunmaz.

**Soru 3** (ekrandan, 01:15:00 ve 01:20:00). $r=b(a+b)^*b$ düzenli ifadesi için bir Turing makinesi tasarlayın.

> **Çözüm:** Derste çizilen makine ve ona eklenmesi gereken döngüler 9. bölümdedir. Doğru bir makine: $q_0\xrightarrow{b\to b,R}q_1$; $q_1\xrightarrow{a\to a,R}q_2$; $q_1\xrightarrow{b\to b,R}q_3$; $q_2$'de $a\to a,R$; $q_2\xrightarrow{b\to b,R}q_3$; $q_3$'te $b\to b,R$; $q_3\xrightarrow{a\to a,R}q_1$; $q_3\xrightarrow{\Diamond\to\Diamond,L}q_4$ (son). Bu biçim python ile denetlendi.

**Soru 4** (ekrandan, 01:25:00 ve 01:30:00). $\{a^nb^n : n\ge1\}$ için verilen Turing makinesinde $aaabbb$ girişinin her turdan sonraki şerit içeriğini yazın.

> **Çözüm:** $xaaybb$, $xxayyb$, $xxxyyy$; ardından makine $q_3$ ile $y$'leri geçip $\Diamond$'da $q_4$'e geçer ve kabul eder.

**Soru 5** (derste sözlü, 01:38:52). $\{a^nb^nc^n\}$ dili için bir Turing makinesi geliştirin.

> **Çözüm (derste verilmedi):** $a^nb^n$ makinesinin fikri genişletilir: en soldaki $a$'yı $x$, en soldaki $b$'yi $y$, en soldaki $c$'yi $z$ yap, $x$'e geri dön; $a$ kalmayınca yalnız $y$ ve $z$'lerin kaldığını denetle. Geçişler:
>
> - $q_0$: $a\to x,R \Rightarrow q_1$; $y\to y,R \Rightarrow q_4$.
> - $q_1$: $a\to a,R$, $y\to y,R$ (döngü); $b\to y,R \Rightarrow q_2$.
> - $q_2$: $b\to b,R$, $z\to z,R$ (döngü); $c\to z,L \Rightarrow q_3$.
> - $q_3$: $a,b,y,z$ için aynı simgeyi yazıp $L$ (döngü); $x\to x,R \Rightarrow q_0$.
> - $q_4$: $y\to y,R$, $z\to z,R$ (döngü); $\Diamond\to\Diamond,L \Rightarrow q_5$ (son).
>
> Bu makine python ile uzunluğu 9'a kadar olan bütün $\{a,b,c\}$ dizgilerinde denendi ve yalnız $a^nb^nc^n$ ($n\ge1$) dizgilerini kabul etti.

**Soru 6** (ekrandan, 02:25:00). $f(x,y)=x+y$ için birli gösterimde $3+5$'in giriş ve çıkış şeritlerini yazın.

> **Çözüm:** Giriş $111\,0\,11111$, çıkış $11111111\,0$ (sekiz $1$).

**Soru 7** (ekrandan, 02:45:00). $f(x)=2x$ makinesi $11$ girişinde hangi çıkışı üretir?

> **Çözüm:** $1111$; makine $q_3$'te, kafa en soldaki $1$'de durur.

## Dersin Toparlaması

Bu derste Turing makinesi tanıtıldı: sonsuz şerit, okuyup yazan bir kafa ve kontrol biriminden oluşan, belirlenimci ve epsilon geçişi olmayan bir makine. Kafa en soldaki giriş simgesinden başlar; geçiş kalmayınca makine durur. Son durumda durursa giriş kabul edilir; son olmayan durumda durursa ya da sonsuz döngüye girerse reddedilir. Son durumlardan çıkan geçiş yoktur. $a^*$, $a^*+b(a+b)^*$, $b(a+b)^*b$ ve $a^nb^n$ için makineler kuruldu; yedili tanım, anlık betim, $\overset{*}{\succ}$ gösterimi ve Turing-tanınabilir dil kavramı verildi.

Dersin ikinci kısmında Turing makinesinin bir hesaplayıcı olduğu ve sayarak hesap yaptığı vurgulandı. Birli gösterimle toplama ve ikiye katlama makineleri incelendi, karşılaştırma fonksiyonu ve makinelerin bloklar hâlinde birleştirilmesi gösterildi. Hoca, $a^nb^n$ makinesinden yola çıkarak $a^nb^nc^n$ için makine kurmayı alıştırma olarak bıraktı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
