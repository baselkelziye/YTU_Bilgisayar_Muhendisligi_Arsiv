# Ders 3 Genişletilmiş Notu: Sonlu Otomatlar, Genişletilmiş Geçiş Fonksiyonu, NFA ve Küme/Dizgi Alıştırmaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dil ve Sonlu Otomat
- 2. Sonlu Otomatın 5'li Tanımı
- 3. Geçiş Grafiği ve Geçiş Tablosu: `abba` Örneği
- 4. Tasarım Örneği: Tek Sayıda 1 İçeren Dizgiler
- 5. Dizgilerin Adım Adım İşlenmesi, Kabul ve Ret
- 6. Verilen Makinelerin Dilini Bulmak
- 7. Genişletilmiş Geçiş Fonksiyonu
- 8. Bir DFA'nın Kabul Ettiği ve Reddettiği Dil
- 9. Deterministik Olmayan Sonlu Otomat (NFA)
- 10. Boş Geçişler ve NFA Örnekleri
- 11. Boş Dil Tuzağı ve Basit Makineler
- 12. DFA ile NFA Arasındaki Fark
- 13. Alıştırmalar: Küme ve Dizgi İşlemleri
- 14. Alıştırma: Verilen Bir Dil İçin DFA ve NFA Tasarımı
- Örnek Sorular

Ders çoğunlukla İngilizce anlatıldı; bazı açıklamalar Türkçe tekrarlandı. Kayıt iki arayla üç bölümden oluşuyor. İlk bölümde (yaklaşık 00:04-00:52) DFA anlatıldı. İkinci bölümde (yaklaşık 01:04-01:52) NFA'ya geçildi. Üçüncü bölümde (yaklaşık 02:07-03:00) tablette el yazısıyla alıştırmalar çözüldü. İlk iki bölümde PowerPoint slaytları kullanıldı.

## 1. Dil ve Sonlu Otomat

Ders, geçen haftanın sorusuyla açılıyor: dil nedir? **Dil (language), bir dizgiler (strings) kümesidir.** Bir dizgi kümeniz varsa bir diliniz vardır. Türkçe de İngilizce de birer dildir; makinelerin de bir dili vardır. Bir algoritmayı bir makinede çalıştırmak istiyorsanız onu makinenin anlayacağı dilde yazmanız gerekir.

Bir dil bir sonlu otomat (finite automaton) tarafından tanınıyorsa (recognized / accepted) o dile **düzenli dil (regular language)** denir. Kayıt başında görünen slayt da bunu söylüyor: düzenli dilleri doğrudan tanımlamanın yolu yoktur, ama bir kümenin düzenli olup olmadığını söylemek mümkündür; en iyi yol sonlu otomattır. Bir sonlu otomat dili tanıyorsa dil düzenlidir (ekrandan, 00:05:00). Aynı slaytta düzenli işlemler de yazılı:

$$A \cup B = \{x \mid x \in A \text{ ya da } x \in B\}, \quad A \circ B = \{xy \mid x \in A \text{ ve } y \in B\}, \quad A^* = \{x_1 x_2 \cdots x_k \mid k \ge 0,\ x_i \in A\}.$$

> **Ders sonrası not:** Slaytta yıldız işlemi için "$k > 0$" yazıyor. $k = 0$ durumu boş dizgiyi verdiği için doğrusu büyük olasılıkla $k \ge 0$'dır; hoca derste $A^*$'ın her zaman $\varepsilon$ içerdiğini kullandı.

Sonlu otomat bir makinedir. Bir dizgi alır ve bu dizginin kendi dilinin elemanı olup olmadığına karar verir. Dizgi dilin elemanıysa "kabul" (accept), değilse "ret" (reject) sonucu verir. Bir otomat yalnız bir dili tanır.

Hoca bunu bir benzetmeyle anlattı: Japonca bilmeyen birine Japonca bir ifade söylerseniz onu tanıyamaz ve "Türkçe değil" diye reddeder. Japonca bilen biri ise onu tanır. "Merhaba" dediğinizde ise siz hemen tanırsınız. Sonlu otomat da kendi dilinin dizgilerini böyle tanır. Bir otomat bir dildeki bütün dizgileri tanıyorsa (ve başka dizgi tanımıyorsa) o otomat o dili tanır.

## 2. Sonlu Otomatın 5'li Tanımı

Slayttaki tanım şöyledir (ekrandan, 00:10:00). Bir sonlu otomat bir 5'lidir: $(Q, \Sigma, \delta, q_0, F)$.

- $Q$: **durumlar (states)** adı verilen sonlu bir küme,
- $\Sigma$: **alfabe** adı verilen sonlu bir küme,
- $\delta: Q \times \Sigma \to Q$: **geçiş fonksiyonu (transition function)**,
- $q_0 \in Q$: **başlangıç durumu (start state)**,
- $F \subseteq Q$: **kabul durumları kümesi (set of accept states)**.

> **Hocanın vurgusu:** Sınavlarda 5'li tanım sorulur ve bazı öğrenciler bunu yazamaz. 5'li bir küme değildir; beş bileşenli bir elemandır. $Q$, $\Sigma$ ve $F$ birer kümedir; $\delta$ bir geçiş fonksiyonudur (tablo olarak da yazılabilir); $q_0$ ise yalnızca başlangıç durumunun adıdır. Tanımı yazarken bu ayrıma dikkat edin.

Geçişler, bütün durumlarla alfabenin Kartezyen çarpımı üzerinde tanımlanır: alfabedeki her sembol ve her durum için bir sonraki durum belirlenir. $q_0$, $Q$'nun elemanlarından biridir. Kabul durumları kümesi $F$ ise $Q$'nun bir alt kümesidir.

Hoca geçiş fonksiyonunu "otomatın programı" gibi düşünmeyi önerdi. $\delta(r, a) = r'$ yazımı şu anlama gelir: $M$ makinesi $r$ durumundayken $a$ sembolünü okursa $r'$ durumuna geçer. $r'$, $r$'nin kendisi de olabilir.

## 3. Geçiş Grafiği ve Geçiş Tablosu: `abba` Örneği

Slayttaki geçiş grafiğinde (transition graph) altı durum vardır: $q_0, \dots, q_5$ (ekrandan, 00:15:00). Kaynağı olmayan ok başlangıç durumu $q_0$'ı, çift çember ise kabul durumu $q_4$'ü gösterir.

> **Hocanın vurgusu:** Sonlu otomatta başlangıç durumu birden fazla olamaz.

Oklar geçişleri, okların üstündeki harfler o geçişi tetikleyen sembolü gösterir. Örneğin makine $q_1$'deyken `a` okursa $q_5$'e, `b` okursa $q_2$'ye geçer. $q_5$'e bir kez girildi mi her sembolde $q_5$'te kalınır. Bir ok üzerinde iki harf (`a,b`) varsa bu, iki ayrı geçişin tek okla gösterilmesidir. Geçiş tablosu:

| $\delta$ | a | b |
|---|---|---|
| $q_0$ | $q_1$ | $q_5$ |
| $q_1$ | $q_5$ | $q_2$ |
| $q_2$ | $q_5$ | $q_3$ |
| $q_3$ | $q_4$ | $q_5$ |
| $q_4$ | $q_5$ | $q_5$ |
| $q_5$ | $q_5$ | $q_5$ |

Makine $q_3$'teyken `a` okur ve bu `a` dizginin son sembolüyse makine $q_4$'e geçer, girdi biter, $q_4$ kabul durumu olduğu için dizgi kabul edilir. Bu makine yalnız bir dizgiyi tanır: `abba`. Dolayısıyla dili yalnız `abba` dizgisini içeren kümedir: $L = \{abba\}$.

Hoca burada bir soru sordu: bu tablo verilirse makineyi çizebilir misiniz? Eksik olan bilgi, **başlangıç durumudur**. Geçiş tablosunda hangi durumun başlangıç durumu olduğu yazmaz; grafikte bunu ok gösterir. Bu yüzden başlangıç durumu ayrı bir bilgidir.

## 4. Tasarım Örneği: Tek Sayıda 1 İçeren Dizgiler

Dil şöyledir: $A = \{ w \mid w \text{ tek sayıda } 1 \text{ içeren bir ikili dizgidir} \}$. Otomat girdiyi soldan sağa okur ve 1'leri sayar. Okunan 1 sayısı tek ise kabul durumunda olmalıdır.

Slayt, her sayı için ayrı bir durum tutmanın uygulanabilir olmadığını, çünkü sonlu otomatın sonlu sayıda durumu olduğunu söylüyor. Doğru yaklaşım, şimdiye kadar okunan 1'lerin sayısının çift mi tek mi olduğunu tutmaktır (ekrandan, 00:25:00). Hoca, tasarımın birçok farklı yolu olduğunu ama bazı tasarımların daha verimli olduğunu ekledi.

- $q_0$: şimdiye kadar çift sayıda 1 okundu (başlangıç durumu; sıfır da çifttir).
- $q_1$: şimdiye kadar tek sayıda 1 okundu (kabul durumu).

`0` okumak 1 sayısını değiştirmez, durum aynı kalır. `1` okumak sayının tekliğini değiştirir, durum değişir. Örneğin `1010` dizgisinde iki tane 1 vardır: $q_0 \to q_1 \to q_1 \to q_0 \to q_0$; makine $q_0$'da biter ve dizgi reddedilir.

Biçimsel tanım (ekrandan, 00:30:00):

$$M = (Q, \Sigma, \delta, q_0, F), \quad Q = \{q_0, q_1\}, \quad \Sigma = \{0, 1\}, \quad F = \{q_1\}$$

Geçişler $(q_0, 0) \to q_0$, $(q_0, 1) \to q_1$, $(q_1, 0) \to q_1$, $(q_1, 1) \to q_0$ biçiminde de yazılabilir, tablo olarak da:

| $\delta$ | 0 | 1 |
|---|---|---|
| $q_0$ | $q_0$ | $q_1$ |
| $q_1$ | $q_1$ | $q_0$ |

> **Hocanın vurgusu:** Geçişleri tek tek yazmak yerine geçiş tablosunu kullanmanızı şiddetle öneririm. Tek tek yazılan geçişlerde makinenin nasıl davrandığını görmek kolay değildir.

Alfabe, geçişlerin üzerinde görünen sembollerden okunur: burada geçişler 0 ve 1 için olduğundan $\Sigma = \{0, 1\}$'dir. Başlangıç durumu okla gösterilen $q_0$'dır. Bir DFA'da her durumda alfabedeki her sembol için bir geçiş vardır; `abba` makinesinde de her durumdan `a` ve `b` için birer geçiş çıkar ve alfabe $\{a, b\}$'dir.

## 5. Dizgilerin Adım Adım İşlenmesi, Kabul ve Ret

Otomat girdi dizgisini **soldan sağa** okur. Okuma kafası (head) başta şeridin (tape) başındadır ve dizgi şeridin içindedir; şerit bir bellek gibi düşünülebilir. Makine başta başlangıç durumundadır.

**`abba`:** $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2 \xrightarrow{b} q_3 \xrightarrow{a} q_4$. Girdi bitti ve şu anki durum kabul durumu, dizgi kabul edilir.

**`aba`:** $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2 \xrightarrow{a} q_5$. Girdi bitti ve $q_5$ kabul durumu değil, dizgi reddedilir (ekrandan, 00:35:00). Yani `aba`, bu otomatın tanıdığı dilin elemanı değildir.

**Boş dizgi $\varepsilon$:** Girdi boştur. Makine $q_0$'dadır ve girdi hemen biter. $q_0$ kabul durumu olmadığından boş dizgi reddedilir.

Makinenin dili $L = \{abba\}$'dır. Bu bir dil midir? Evet: dil bir dizgiler kümesidir ve kümenin hiç elemanı olmayabilir, bir elemanı olabilir ya da birçok elemanı olabilir.

Kabul ve ret koşulları şöyle özetlendi:

- Bir dizgiyi **kabul** etmek için bütün girdi okunmalı ve son durum kabul durumu olmalıdır.
- Bir dizgiyi **reddetmek** için bütün girdi okunmalı ve son durum kabul durumu olmamalıdır.

## 6. Verilen Makinelerin Dilini Bulmak

### 6.1 Üç Kabul Durumlu Makine

Aynı grafikte kabul durumu sayısı birden üçe çıkarıldı: $q_0$, $q_2$ ve $q_4$ çift çemberlidir. Bu otomat boş dizgiyi, `ab` dizgisini ve `abba` dizgisini tanır. Boş dizgide makine $q_0$'da kalır ve $q_0$ kabul durumu olduğu için boş dizgi kabul edilir. Dil $\{\varepsilon, ab, abba\}$'dır (python ile kontrol edildi).

### 6.2 $a^n b$ Dili

Slayttaki makinede (ekrandan, 00:40:00):

- $q_0$ (başlangıç): `a` ile kendine döner, `b` ile $q_1$'e gider.
- $q_1$ (kabul durumu): `a` ve `b` ile $q_2$'ye gider.
- $q_2$ (tuzak durumu, trap state): `a` ve `b` ile kendine döner.

Alfabe $\{a, b\}$, üç durum olduğu için geçiş tablosunda üç satır vardır, kabul durumları kümesi $F = \{q_1\}$'dir.

`aab`: $q_0 \xrightarrow{a} q_0 \xrightarrow{a} q_0 \xrightarrow{b} q_1$; kabul edilir.

`bab`: $q_0 \xrightarrow{b} q_1 \xrightarrow{a} q_2 \xrightarrow{b} q_2$; girdi biter, $q_2$ kabul durumu değildir, reddedilir.

Dil $\{a^n b : n \ge 0\} = \{b, ab, aab, aaab, \dots\}$'dır. Bu dilin boyutu sonsuzdur. Yalnız üç durumu olan bir makinenin sonsuz bir dil tanımasını sağlayan şey **döngülerdir** (loops).

> **Ders sonrası not:** Hoca bu dili bir yerde "a ile başlayıp b ile biten dizgiler" diye özetledi. Makine `b` dizgisini de kabul eder, `abab` gibi a ile başlayıp b ile biten bazı dizgileri ise reddeder. Doğru tanım $\{a^n b : n \ge 0\}$'dır (python ile kontrol edildi).

### 6.3 Tek Sembollü Alfabe

Bir başka makinede geçişlerin üzerinde yalnız `1` sembolü görünüyor; dolayısıyla alfabe $\Sigma = \{1\}$'dir. Hoca bu makinenin boş dizgiyi, `11` dizgisini, kısacası 1 sayısı ikiye bölünebilen dizgileri kabul ettiğini söyledi: $\{1^{2n} : n \ge 0\}$.

<!-- BELİRSİZ: Bu makinenin diyagramı incelenen karelerde yok; durum sayısı ve geçişleri doğrulanamadı. -->

## 7. Genişletilmiş Geçiş Fonksiyonu

Geçiş fonksiyonu $\delta$ bir durum ve bir **sembol** alır. Örneğin $\delta(q_0, 0) = q_0$: $q_0$ durumunda 0 okununca çıktı durumu $q_0$'dır. İkinci argüman bir dizgi değil, tek bir semboldür.

**Genişletilmiş geçiş fonksiyonu (extended transition function)** $\delta^*$ ise bir durum ve bir **dizgi** alır ve bir durum verir (ekrandan, 00:45:00):

$$\delta^*: Q \times \Sigma^* \to Q, \qquad \delta^*(q, w) = q'$$

$\delta^*(q, w)$, $q$ durumundan başlayıp $w$ dizgisini taradıktan sonra varılan durumu verir.

**Örnek 1:** $\delta^*(q_0, ab)$. $q_0$'dan `a` ile $q_1$'e, `b` ile $q_2$'ye gidilir. Sonuç: $\delta^*(q_0, ab) = q_2$ (ekrandan, 00:45:00).

**Örnek 2:** Hoca $q_0$'dan başlayıp `a`, `b` ve üçüncü sembol olarak yine `b` okunan bir örneği izledi. Bu yol $q_0 \to q_1 \to q_2 \to q_3$ olur, yani $\delta^*(q_0, abb) = q_3$ (python ile kontrol edildi).

<!-- BELİRSİZ: Bu örneğin sonu altyazıda bozuk; dizginin tam olarak abb mi yoksa daha uzun mu olduğu ekrandan doğrulanamadı. -->

**Örnek 3:** $\delta^*(q_1, bba)$. Başlangıç durumunun $q_0$ olması gerekmez; genişletilmiş geçiş fonksiyonu her durum için tanımlanabilir. $q_1 \xrightarrow{b} q_2 \xrightarrow{b} q_3 \xrightarrow{a} q_4$; sonuç $\delta^*(q_1, bba) = q_4$ (ekrandan, 00:50:00).

Genel olarak $\delta^*(q, w) = q'$, $q$ ile $q'$ arasında bir **yürüyüş (walk)** olduğunu gösterir. $w = \sigma_1 \sigma_2 \cdots \sigma_k$ dizgisi $k$ sembol içerir; her sembolde makinenin durumu değişir ve $k$'inci sembolle $q'$'ye varılır. Bütün ara durumları çizmek zor olduğu için bu yürüyüş bazen $q$'dan $q'$'ye giden ve üzerinde $w$ yazan tek bir okla gösterilir. Bu, genişletilmiş geçiş fonksiyonunun tanımladığı genişletilmiş bir geçiştir.

## 8. Bir DFA'nın Kabul Ettiği ve Reddettiği Dil

Bir $M$ otomatının kabul ettiği dil $L(M)$ ile gösterilir ve $M$'nin kabul ettiği bütün dizgileri içerir. Bir $L'$ dili için $L(M) = L'$ ise $L'$ dilinin $M$ tarafından kabul edildiği söylenir.

> **Hocanın vurgusu:** Bir otomat bir ve yalnız bir dil kabul eder. Bir dil ise birçok otomat tarafından kabul edilebilir.

Bir DFA $M = (Q, \Sigma, \delta, q_0, F)$ için kabul edilen dil (ekrandan, 01:10:00):

$$L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \in F \}$$

Hoca bunu Türkçe de açıkladı: alfabeye Kleene yıldızı uygulanınca elde edilen $\Sigma^*$ de bir dildir ve alfabeden üretilebilecek bütün olası dizgiler bunun içindedir ("evrensel dil"). Bu dizgilerden genişletilmiş geçiş fonksiyonuyla $q_0$'dan bir kabul durumuna ulaştıranların kümesine $M$ makinesinin dili denir.

Reddedilen dil, kabul edilen dilin tümleyenidir (ekrandan, 01:15:00):

$$\overline{L(M)} = \{ w \in \Sigma^* : \delta^*(q_0, w) \notin F \}$$

Yani son durumu kabul durumu olmayan bütün girdi dizgileri, makinenin dilinin tümleyenini oluşturur.

**Soru:** DFA ne demek? **Cevap:** DFA, deterministik sonlu otomattır (deterministic finite automaton). Her durumda alfabedeki her sembol için bir geçiş vardır. NFA ile farkı bir sonraki konuda görülecek.

## 9. Deterministik Olmayan Sonlu Otomat (NFA)

NFA da 5'li ile tanımlanır: $Q$ durumlar, $\Sigma$ alfabe, $\delta$ geçiş fonksiyonu, $q_0$ başlangıç durumu, $F$ kabul durumları. Fark geçiş fonksiyonundadır: NFA'da bir geçiş **bir durum değil, bir durum kümesi** verir (ekrandan, 01:20:00):

$$\delta(q, x) = \{q_1, q_2, \dots, q_k\}$$

Bu küme, $x$ sembolüyle bir geçiş izlenerek varılabilecek durumlardır. Makine $x$'i okuyunca aynı anda birden çok durumda bulunur.

> **Ek bilgi (derste anlatılmadı):** Boş geçişler de hesaba katıldığında NFA'nın geçiş fonksiyonu genellikle $\delta: Q \times (\Sigma \cup \{\varepsilon\}) \to 2^Q$ biçiminde yazılır. Buradaki $2^Q$, $Q$'nun kuvvet kümesidir; boş küme de bir değer olabilir.

### 9.1 Birden Çok Durum, Boş Geçiş, Ölü Geçiş

Hocanın gösterdiği üç durumlu NFA'da geçişler şöyledir:

| $\delta$ | 0 | 1 | $\varepsilon$ |
|---|---|---|---|
| $q_0$ | $\emptyset$ | $\{q_1\}$ | $\{q_2\}$ |
| $q_1$ | $\{q_0, q_2\}$ | $\{q_2\}$ | $\emptyset$ |
| $q_2$ | $\emptyset$ | $\emptyset$ | $\emptyset$ |

- $q_0$'da `1` okununca yalnız $q_1$'e gidilir.
- $q_1$'de `0` okununca aynı anda hem $q_0$'da hem $q_2$'de bulunulur.
- $q_0$'dan boş dizgiyle $q_2$'ye de geçilir.
- $q_2$'de `1` için geçiş yoktur: hiçbir durumda bulunulmaz. Hoca buna **ölü geçiş (dead transition)** dedi.

<!-- BELİRSİZ: Tablodaki q1 -1-> q2 geçişi ve kabul durumu (q0) slayt küçük resminden okundu; altyazıda bu NFA'nın yalnız bir kısmı anlatılıyor. -->

### 9.2 İki Seçenekli NFA: $\{aa\}$

Alfabe $\{a\}$'dır (ekrandan, 01:25:00). $q_0$'dan `a` ile iki seçenek vardır: $q_1$ ve $q_3$. $q_1$'den `a` ile kabul durumu $q_2$'ye gidilir; $q_2$ ve $q_3$'ten çıkan geçiş yoktur.

**`aa`:** İlk `a` ile aynı anda $q_1$ ve $q_3$'te bulunulur. İkinci `a` ile $q_1$'den $q_2$'ye gidilir; $q_3$'te `a` için geçiş olmadığından o dal ölür. Artık yalnız $q_2$'de bulunulur. $q_2$ kabul durumu olduğundan `aa` kabul edilir.

**NFA'da kabul:** NFA'nın dizgiyi kabul eden bir hesaplaması (computation) varsa dizgi kabul edilir: bütün girdi okunur ve otomat bir kabul durumundadır. Hoca bunu şöyle yazdı:

> **Hocanın vurgusu:** NFA'nın o anda üzerinde bulunduğu durumlardan en az biri kabul durumuysa girdi dizgisi kabul edilir (tanınır). Başka bir deyişle girdi dizgisi makinenin dili $L(M)$'nin elemanıdır.

**`a`:** Tek `a` ile $q_1$ ve $q_3$'te bulunulur. İkisi de kabul durumu değildir; dizgi reddedilir.

**`aaa`:** İlk iki `a` ile $q_2$'ye varılır (öteki dal $q_3$'te ölür). Üçüncü `a` için $q_2$'den çıkan geçiş yoktur, girdi okunamaz. Dizgi reddedilir.

**NFA'da ret:** NFA, dizgiyi kabul eden hiçbir hesaplama yoksa dizgiyi reddeder. Her hesaplama için ya bütün girdi okunur ve otomat kabul olmayan bir durumdadır, ya da girdi okunamaz (ekrandan, 01:30:00).

Bu NFA'nın dili $\{aa\}$'dır (python ile kontrol edildi).

## 10. Boş Geçişler ve NFA Örnekleri

### 10.1 $\varepsilon$-Geçişi

İki durum bir $\varepsilon$ (boş dizgi) geçişiyle bağlıysa, birine varıldığında öbüründe de bulunulur. Örneğin $q_1$ ile $q_2$ arasında $\varepsilon$-geçişi varsa $q_1$'e varınca aynı zamanda $q_2$'de de bulunulur.

### 10.2 $\{ab\}^+$ Dili

Slayttaki NFA (ekrandan, 01:35:00 ve 01:40:00):

- $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$, kabul durumu $q_2$,
- $q_2 \xrightarrow{\varepsilon} q_3$, $q_3 \xrightarrow{\varepsilon} q_0$.

**`ab`:** `a` ile $q_1$'e, `b` ile $q_2$'ye gidilir. $\varepsilon$-geçişleri nedeniyle aynı anda $q_3$ ve $q_0$'da da bulunulur. Son durumlardan biri ($q_2$) kabul durumu olduğundan `ab` kabul edilir.

**`abab`:** `ab` sonrasında $\{q_2, q_3, q_0\}$'da bulunulur. Üçüncü sembol `a` ile $q_0$'dan $q_1$'e, dördüncü sembol `b` ile $q_2$'ye gidilir; yine $q_3$ ve $q_0$'da da bulunulur. Son durumlardan biri kabul durumu olduğundan `abab` kabul edilir.

Dil:

$$L = \{ab, abab, ababab, \dots\} = \{ab\}^+$$

Bu, $\{ab\}$ kümesine artı (Kleene plus) işleminin uygulanmasıdır (python ile kontrol edildi).

**Soru:** Bu örnekte $q_2$ değil de $q_3$ kabul durumu olsaydı, aradaki $\varepsilon$-geçişi yüzünden yine aynı sonucu elde eder miydik? **Cevap:** Kesinlikle evet. Önemli olan, o anda üzerinde bulunulan durumlardan birinin kabul durumu olmasıdır; $q_2$'ye varınca $q_3$'te de bulunulduğundan dil aynı kalır.

**Soru:** $q_0$ kabul durumu olsaydı, sonuca yalnız boş dizgiyi eklemek mi gerekirdi? **Cevap:** Evet.

> **Ders sonrası not:** $q_0$ kabul durumu yapılırsa dil $\{ab\}^* = \{\varepsilon\} \cup \{ab\}^+$ olur; çünkü $\{ab\}^+$'daki her dizgiden sonra zaten $q_0$'da da bulunulmaktadır. Yani cevap doğrudur (python ile kontrol edildi).

### 10.3 $\{10\}^*$ Dili

Bölüm 9.1'deki üç durumlu makine "Another NFA Example" başlığıyla yeniden ele alındı. Başlangıç durumu $q_0$ aynı zamanda kabul durumudur. Dilde `10`, `1010` ve genel olarak `10`'un tekrarları vardır: $L = \{\varepsilon, 10, 1010, 101010, \dots\} = \{10\}^*$ (python ile kontrol edildi). Hoca, $q_2$'ye giden geçişin gereksiz (useless) olduğunu söyledi: $q_2$'den hiçbir yere gidilemez ve $q_2$ kabul durumu değildir.

> **Hocanın vurgusu:** Başlangıç durumu $q_0$ aynı zamanda kabul durumuysa boş dizgi, otomatın tanıdığı dilin elemanıdır.

## 11. Boş Dil Tuzağı ve Basit Makineler

Hoca tek durumlu basit makineleri gösterdi:

- $M_1$: tek bir başlangıç durumu var, kabul durumu yok, geçiş yok. $L(M_1) = \{\} = \emptyset$.
- $M_2$: tek durum hem başlangıç hem kabul durumu. $L(M_2) = \{\varepsilon\}$.

Ardından sordu: "$M_1$ hiçbir şey tanımaz" demek doğru mu? Bir öğrenci "doğru" dedi. Doğru değil:

> **Hocanın vurgusu:** Bu makine boş kümeyi, yani boş dili tanır. Her makine bir dil tanır. Dilin tanımı neydi? Dizgiler kümesi. Boş küme de bir kümedir; elemanı olmayan bir dizgiler kümesidir. Sınavlarda böyle ters köşe sorular sorulabilir.

$M_2$'nin dili ise boş küme değildir: içinde boş dizgi bulunan, tek elemanlı bir kümedir. $\emptyset$ ile $\{\varepsilon\}$ arasındaki farkı görmek gerekir.

Hoca bu örnekten genel bir ders çıkardı: sınava hazırlanırken insanlar basit görünen slaytları "buradan bir şey çıkmaz" diye geçer, karmaşık olanlara odaklanır. Oysa sorular genellikle basit slaytlarda saklıdır; insanlar hatayı en çok basit konularda yapar. Basit, temel kavramları iyi anlarsanız karmaşık olanları anlamak da kolaylaşır.

## 12. DFA ile NFA Arasındaki Fark

Slaytta, aynı dili tanıyan iki makine karşılaştırılıyor; ikisinde de alfabe $\Sigma = \{a\}$'dır (ekrandan, 01:45:00):

- **NFA $M_1$:** $q_0 \xrightarrow{a} q_1$, kabul durumu $q_1$; $q_1$'den çıkan geçiş yok. $L(M_1) = \{a\}$.
- **DFA $M_2$:** $q_0 \xrightarrow{a} q_1$, kabul durumu $q_1$; $q_1 \xrightarrow{a} q_2$, $q_2 \xrightarrow{a} q_2$ (tuzak durumu). $L(M_2) = \{a\}$.

Slayttaki ifade: NFA'lar ilginçtir, çünkü dilleri DFA'lardan daha kolay ifade edebiliriz. Bu örnek, daha önce söylenen ilkenin de bir örneğidir: bir dili birden çok makine tanıyabilir, ama her makine tek bir dil tanır.

**Fark:** $M_2$'de her durumun alfabedeki sembol (`a`) için çıkan bir geçişi vardır: $q_0$, $q_1$ ve $q_2$'nin her birinden `a` ile bir geçiş çıkar. $M_1$'de ise $q_1$'den hiç geçiş çıkmaz. Bu yüzden $M_1$ bir NFA'dır.

> **Hocanın vurgusu:** Her DFA'da her durumdan çıkan geçişlerin sayısı, DFA'nın tanıdığı dilin alfabesindeki sembollerin sayısı kadardır. NFA'da bu sayı alfabedeki sembol sayısı kadar olmak zorunda değildir.

**Soru:** NFA'da bir durumdan aynı sembol için birden fazla geçiş de çıkabilir, doğru mu? **Cevap:** Evet; NFA'da çıkan geçiş sayısı alfabedeki eleman sayısına eşit olmak zorunda değildir (bir sembol için birden çok geçiş olabilir, hiç olmayabilir).

Hoca bölümü bir soruyla kapattı: bütün olası DFA makinelerinin kümesi, bütün olası NFA makinelerinin kümesinin nesidir? **Bir alt kümesidir.** Her DFA aynı zamanda bir NFA'dır.

## 13. Alıştırmalar: Küme ve Dizgi İşlemleri

Üçüncü bölümde hoca tablette sorular yazıp sınıfla birlikte çözdü.

### 13.1 Eleman ve Alt Küme

$A = \{\{1,2,3\}, \{4,5\}, \{6,7,8\}\}$ kümesi veriliyor. Her ifadenin doğru mu yanlış mı olduğu soruluyor (ekrandan, 02:10:00). $A$'nın üç elemanı vardır ve her biri bir kümedir.

- **(a) $1 \in A$:** Yanlış. $1$, $A$'nın bir elemanının elemanıdır; $A$'nın elemanı değildir.
- **(b) $\{1,2,3\} \subseteq A$:** Yanlış. $\{1,2,3\}$, $A$'nın bir elemanıdır; alt küme olması için onun elemanlarının (1, 2, 3) $A$'da bulunması gerekirdi. Bir süslü parantez daha eklenirse, yani $\{\{1,2,3\}\} \subseteq A$ yazılırsa ifade doğru olur.
- **(c) $\{6,7,8\} \in A$:** Doğru.
- **(d) $\{\{4,5\}\} \subseteq A$:** Doğru.
- **(e) Boş kümeyle ilgili ifade:** Sınıfın cevabı "yanlış" oldu; bu, ifadenin $\emptyset \in A$ olmasıyla tutarlıdır ($\emptyset \subseteq A$ her zaman doğrudur).

<!-- BELİRSİZ: (b), (d) ve (e) şıklarının tam yazımı karelerde görünmüyor; altyazıdaki açıklamalardan kuruldu. (f) şıkkı altyazıda okunamadı. -->

> **Hocanın vurgusu:** Sınavda böyle kafa karıştırıcı sorular olur. Eleman ($\in$) ile alt küme ($\subseteq$) ayrımına dikkat edin.

### 13.2 Dizgi Kümeleri Üzerinde İşlemler

Kümeler (ekrandan, 02:25:00):

$$C = \{\varepsilon, aab, baa\}, \quad D = \{bb, aab\}, \quad E = \{\varepsilon\}, \quad F = \emptyset = \{\}$$

**(a) Birleşim:** $D \cup C = \{\varepsilon, bb, aab, baa\}$ (ekrandan, 02:20:00).

**(b)** $C \cup F = \{\varepsilon, aab, baa\} = C$, çünkü $F$ boş kümedir (ekrandan, 02:20:00).

**(c) Kartezyen çarpım:** $C \times D$ sıralı ikililerden oluşur (ekrandan, 02:20:00):

$$C \times D = \{(\varepsilon, bb), (\varepsilon, aab), (aab, bb), (aab, aab), (baa, bb), (baa, aab)\}$$

Ardından hoca şunu sordu: $C$ ve $D$ aynı değilse $C \times D \neq D \times C$ doğru mu? Sınıf "doğru" dedi. Hoca sınavda bunun "$C \not\subseteq D$ ve $D \not\subseteq C$ ise" biçiminde de sorulabileceğini ekledi.

> **Ders sonrası not:** $C \times D = D \times C$ eşitliği $C = D$ olduğunda ya da kümelerden biri boş olduğunda sağlanır. Örneğin $C = \emptyset$, $D = \{a\}$ için iki çarpım da boştur ama $C \neq D$'dir. Bu yüzden ifade, iki kümenin de boş olmadığı varsayımıyla doğrudur.

**(d) Kesişim:** $C \cap D = \{aab\}$. Ortak tek eleman $aab$'dir.

**Birleştirme (concatenation):** $C$'nin her elemanı $D$'nin her elemanıyla birleştirilir. $\varepsilon$ ile birleştirme dizgiyi değiştirmez (ekrandan, 02:25:00):

$$CD = \{bb, aab, aabbb, aabaab, baabb, baaaab\}$$

Ara adımlar: $\varepsilon \cdot bb = bb$, $\varepsilon \cdot aab = aab$, $aab \cdot bb = aabbb$, $aab \cdot aab = aabaab$, $baa \cdot bb = baabb$, $baa \cdot aab = baaaab$ (python ile kontrol edildi).

**$D \cdot F$:** Bir öğrenci "$D$ kümesinin aynısı olur" dedi; hoca ekrana $D \cdot F = \{bb, aab\}$ yazıp üstünü çizdi ve "WRONG" diye işaretledi. Doğrusu:

$$D \cdot F = \{\}$$

çünkü $F$ boş kümedir ve birleştirilecek eleman yoktur (ekrandan, 02:25:00).

**$D \cdot E$:** $D \cdot E = D$. $bb \cdot \varepsilon = bb$, $aab \cdot \varepsilon = aab$; boş dizgi birleştirmede düşer. Sonuç $\{bb, aab\}$.

> **Hocanın vurgusu:** $X \cdot \emptyset = \emptyset$ ama $X \cdot \{\varepsilon\} = X$. Bu iki birleştirme "ilginç" birleştirmelerdir; sınavda karıştırılmaya elverişlidir.

**Kuvvet kümesi:** $\mathcal{P}(C)$, $C$'nin bütün alt kümeleridir:

$$\mathcal{P}(C) = \{\emptyset, \{\varepsilon\}, \{aab\}, \{baa\}, \{\varepsilon, aab\}, \{\varepsilon, baa\}, \{aab, baa\}, \{\varepsilon, aab, baa\}\}$$

Hoca önce boş kümeyi, sonra tek elemanlı, iki elemanlı ve üç elemanlı alt kümeleri yazdı. Kuvvet kümesinin boyutu, içindeki eleman sayısıdır (ekrandan, 02:30:00):

$$|\mathcal{P}(C)| = 8 = 2^{|C|}, \quad |C| = 3$$

**Kleene yıldızı:** $F^* = \{\varepsilon\}$; boş kümenin yıldızı yalnız boş dizgiyi içerir (ekrandan, 02:35:00). $C^*$ ise boş dizgiden ve $C$'nin elemanlarının bütün birleştirmelerinden oluşur (ekrandan, 02:35:00):

$$C^* = \{\varepsilon, aab, baa, aabaab, aabbaa, baaaab, baabaa, aabaabaab, aabaabbaa, \dots\}$$

**Kleene artısı:** Hoca $C^+ = C^* - \{\varepsilon\}$ tanımını yazdı, ama listeye $\varepsilon$'u da koydu (ekrandan, 02:40:00). Nedenini Türkçe açıkladı: $C$'nin içinde $\varepsilon$ elemanı vardır. $C^+$'daki birleştirmeler arasında $\varepsilon$'un kendisi de bulunur. Kümenin elemanı bir $\varepsilon$ içeriyorsa, yıldızdan $\varepsilon$ çıkarılsa bile $\varepsilon$ yine $C^+$'da olmak zorundadır.

> **Ders sonrası not:** Genel tanım $S^+ = S S^*$'dır ($S$'nin elemanlarından en az birinin birleştirilmesi). $S^+ = S^* - \{\varepsilon\}$ eşitliği yalnız $\varepsilon \notin S$ iken geçerlidir. $\varepsilon \in S$ ise $S^+ = S^*$ olur; dolayısıyla burada $C^+ = C^*$'dır. Ekrandaki "$C^* - \{\varepsilon\}$" yazımı bu durumda yanıltıcıdır, ama hocanın sözlü açıklaması doğru sonucu verir.

**Alt küme ve ters çevirme:** Hoca $D \not\subseteq C$ olduğunu kısaca belirtti. Ardından ters çevirme (reverse) örnekleri verdi (ekrandan, 02:40:00): $(aa)^R = aa$, $(ab)^R = ba$, $(aabab)^R = babaa$, $\varepsilon^R = \varepsilon$.

### 13.3 Yıldız ve Artı Üzerine Örnekler

Soru: her şık için bir örnek verin ve kısaca açıklayın.

**(a) $S^* = S^+$:** Bu eşitlik, boş dizginin $S$'nin elemanı olduğunu gösterir: $\varepsilon \in S$. Örnek: $S = \{\varepsilon, a\}$. Bu durumda $S^*$ ile $S^+$ aynı kümedir.

**(b) $S^* \neq S^+$:** Bu, $\varepsilon \notin S$ olduğunu gösterir (ekrandan, 02:45:00). Örnek $S = \{a\}$:

$$S^* = \{\varepsilon, a, aa, aaa, aaaa, \dots\}, \quad S^+ = S^* - \{\varepsilon\} = \{a, aa, aaa, aaaa, \dots\} \quad (\varepsilon \notin S)$$

**(c) $S = S^*$:** Hoca bunun $\varepsilon \in S$ olduğunu ve $S$'nin boyutunun sonsuz olduğunu gösterdiğini söyledi. Örnek: $S = \{\varepsilon, a, aa, aaa, \dots\}$; bu durumda $S^* = S$.

> **Ders sonrası not:** $S = S^*$ ise $\varepsilon \in S$ olması gerekir, ama $S$'nin sonsuz olması gerekmez: $S = \{\varepsilon\}$ için $S^* = \{\varepsilon\} = S$'dir (hoca da (e) şıkkında bu örneği kullandı). Doğru ifade, "$S = \{\varepsilon\}$ ya da $S$ sonsuzdur" olmalıdır.

**(d) $S \neq S^*$:** Hoca bunun $S$'nin boyutunun sonlu olduğunu gösterdiğini söyledi. Örnek: $S = \{a\}$; $S^* = \{\varepsilon, a, aa, \dots\}$ ve $S \neq S^*$.

> **Ders sonrası not:** $S \neq S^*$, $S$'nin sonlu olduğunu göstermez. Örneğin $S = \{a, aa, aaa, \dots\}$ sonsuzdur ama $\varepsilon \notin S$ olduğu için $S \neq S^*$'dır. Hocanın verdiği örnek ise doğrudur.

**(e) Kleene yıldızı sonlu olan bir $S$ dizgi kümesi örneği verin ($|S^*| < \infty$).** Kleene yıldızı uygulanınca kümenin boyutu genellikle sonsuza gider. Öğrenciler "boş küme olabilir mi?" ve "boş dizgi olabilir mi?" diye önerdi; ikisi de doğrudur (ekrandan, 02:50:00):

$$S = \{\} \Rightarrow S^* = \{\varepsilon\} \Rightarrow |S^*| = 1 < \infty$$

$$S = \{\varepsilon\} \Rightarrow S^* = \{\varepsilon\} \Rightarrow |S^*| = 1 < \infty$$

**(f) Yıldızları eşit iki küme.** Hoca soruyu sınav biçiminde şöyle yazdı: $A$ ve $B$, $A^* = B^*$ olacak biçimde iki kümedir. $A$ ve $B$ nedir? Cevap: $A$ boş küme, $B$ ise yalnız boş dizgiyi içeren küme. $A^* = B^* = \{\varepsilon\}$.

> **Ek bilgi (derste anlatılmadı):** Farklı iki kümenin yıldızlarının eşit olması için başka örnekler de vardır; örneğin $\{a\}^* = \{\varepsilon, a\}^* = \{a, aa\}^*$. Hocanın verdiği örnek, (e) şıkkıyla bağlantılı en basit örnektir.

## 14. Alıştırma: Verilen Bir Dil İçin DFA ve NFA Tasarımı

Soru: $A = \{\varepsilon, b, ab\}$ dilini kabul eden bir DFA tasarlayın (ekrandan, 02:55:00).

**Adım 1, başlangıç durumu:** Dil boş dizgiyi içerdiği için başlangıç durumu $q_0$ aynı zamanda kabul durumudur.

**Adım 2, alfabe:** $\Sigma = \{a, b\}$, $|\Sigma| = 2$. DFA'da her durumdan çıkan geçiş sayısı alfabenin boyutu kadar, yani 2 olmalıdır.

**Adım 3, ağaç gibi genişletme:** $q_0$'dan `a` ile $q_1$'e, `b` ile $q_2$'ye gidilir. `b` dilin elemanı olduğu için $q_2$ kabul durumudur. $q_1$ ve $q_2$'nin de ikişer çıkan geçişi olmalıdır: $q_1 \xrightarrow{a} q_3$, $q_1 \xrightarrow{b} q_4$, $q_2 \xrightarrow{a} q_5$, $q_2 \xrightarrow{b} q_6$ (ekrandan, 02:55:00). `ab` dilin elemanı olduğu için `ab` ile varılan durum kabul durumudur, ötekiler değildir.

**Adım 4, tuzak durumu:** Yeni durumların da ikişer çıkan geçişi olmalıdır. Hoca bunun için bir tuzak durumu ($q_7$) tanımladı; tuzak durumu `a,b` ile kendine döner.

**Adım 5, sadeleştirme:** Aynı işi yapan durumlar birleştirildi: kabul olmayan ve her sembolle tuzağa giden durumlar tek bir tuzak durumunda toplandı. Hoca bir öğrencinin uyarısıyla etiketlerde bir düzeltme yaptı; dilde `ba` değil `ab` vardır.

<!-- BELİRSİZ: Sadeleştirmeden sonraki son çizim incelenen karelerde görünmüyor; aşağıdaki tablo dilden kurulan ve python ile doğrulanan DFA'dır. -->

Sonuçta elde edilen DFA (python ile kontrol edildi; kabul ettiği dizgiler tam olarak $\varepsilon$, `b`, `ab`):

| $\delta$ | a | b |
|---|---|---|
| $\to q_0$ (kabul) | $q_1$ | $q_2$ |
| $q_1$ | $T$ | $q_2$ |
| $q_2$ (kabul) | $T$ | $T$ |
| $T$ (tuzak) | $T$ | $T$ |

Burada `b` ile ve `ab` ile varılan durumlar aynı işi yaptığı için tek bir kabul durumunda ($q_2$) birleştirildi (ara adım eklendi).

**Soru:** $q_1$'den $q_4$'e geçerken okun üzerinde `a, b` yazıyor; bu, ikisinden birini seçebiliyoruz anlamına mı geliyor? **Cevap:** Hayır; bu iki ayrı geçiş demektir. İki ok çizmek yerine tek bir ok çizilir ve üzerine iki sembol yazılır.

**NFA:** Hoca NFA'nın çok daha basit olduğunu söyledi. Boş dizgi yüzünden başlangıç durumu yine kabul durumudur; $q_0$'dan `a` ile $q_1$'e, oradan ve $q_0$'dan `b` ile bir kabul durumuna gidilir. NFA'da tuzak durumuna gerek yoktur.

<!-- BELİRSİZ: NFA çiziminin tamamı ders sonunda zaman kalmadığı için altyazıda eksik kaldı. -->

## Örnek Sorular

**Soru 1** (ekrandan, 02:10:00): $A = \{\{1,2,3\}, \{4,5\}, \{6,7,8\}\}$ olsun. Aşağıdakilerin doğru mu yanlış mı olduğunu belirleyin: (a) $1 \in A$, (b) $\{1,2,3\} \subseteq A$, (c) $\{6,7,8\} \in A$, (d) $\{\{4,5\}\} \subseteq A$.

> **Çözüm (derste verildi):** (a) Yanlış, (b) Yanlış, (c) Doğru, (d) Doğru. Ayrıntı Bölüm 13.1'de.

**Soru 2** (ekrandan, 02:20:00 ve 02:25:00): $C = \{\varepsilon, aab, baa\}$, $D = \{bb, aab\}$, $E = \{\varepsilon\}$, $F = \emptyset$ için $D \cup C$, $C \cup F$, $C \times D$, $C \cap D$, $CD$, $DF$, $DE$, $\mathcal{P}(C)$, $|\mathcal{P}(C)|$, $F^*$, $C^*$, $C^+$ nedir?

> **Çözüm (derste verildi):** $D \cup C = \{\varepsilon, bb, aab, baa\}$; $C \cup F = C$; $C \times D$ altı ikiliden oluşur; $C \cap D = \{aab\}$; $CD = \{bb, aab, aabbb, aabaab, baabb, baaaab\}$; $DF = \emptyset$; $DE = D$; $|\mathcal{P}(C)| = 8$; $F^* = \{\varepsilon\}$; $\varepsilon \in C$ olduğundan $C^+ = C^*$. Ayrıntı Bölüm 13.2'de.

**Soru 3** (ekrandan, 02:45:00): Aşağıdakilerin her biri için bir $S$ örneği verin ve kısaca açıklayın: (a) $S^* = S^+$, (b) $S^* \neq S^+$, (c) $S = S^*$, (d) $S \neq S^*$.

> **Çözüm (derste verildi):** (a) $\varepsilon \in S$, örn. $\{\varepsilon, a\}$; (b) $\varepsilon \notin S$, örn. $\{a\}$; (c) örn. $\{a\}^* = \{\varepsilon, a, aa, \dots\}$; (d) örn. $\{a\}$. Hocanın (c) ve (d) için söylediği sonlu/sonsuz koşullarına ilişkin düzeltmeler Bölüm 13.3'te.

**Soru 4** (ekrandan, 02:50:00): Kleene yıldızı sonlu olan bir $S$ dizgi kümesi örneği verin.

> **Çözüm (derste verildi):** $S = \emptyset$ ya da $S = \{\varepsilon\}$; ikisinde de $S^* = \{\varepsilon\}$ ve $|S^*| = 1$.

**Soru 5** (derste sözlü, 02:50:36): $A$ ve $B$ farklı kümeler ve $A^* = B^*$ ise $A$ ve $B$ ne olabilir?

> **Çözüm (derste verildi):** $A = \emptyset$, $B = \{\varepsilon\}$; $A^* = B^* = \{\varepsilon\}$.

**Soru 6** (ekrandan, 02:55:00): $A = \{\varepsilon, b, ab\}$ dilini kabul eden bir DFA tasarlayın.

> **Çözüm:** Bölüm 14'teki dört durumlu DFA; python ile kontrol edildi.

**Soru 7** (derste sözlü, 01:40:44): Kabul durumu olmayan tek durumlu bir makine için "bu makine hiçbir şey tanımaz" demek doğru mu?

> **Çözüm (derste verildi):** Yanlış. Makine boş dili $\emptyset$ tanır; her makine bir dil tanır.

**Soru 8** (derste sözlü, 01:52:17): Bütün DFA'ların kümesi, bütün NFA'ların kümesinin nesidir?

> **Çözüm (derste verildi):** Bir alt kümesidir.

## Dersin Toparlaması

Bu derste dilin bir dizgiler kümesi olduğu hatırlatıldı ve bir sonlu otomatın tanıdığı dile düzenli dil dendiği söylendi. Sonlu otomatın 5'li tanımı, geçiş grafiği ve geçiş tablosu `abba` örneğiyle, DFA tasarımı da tek sayıda 1 içeren dizgiler örneğiyle anlatıldı. Dizgilerin adım adım işlenmesi, kabul ve ret koşulları, verilen makinelerin dilini bulma, genişletilmiş geçiş fonksiyonu $\delta^*$ ve $L(M) = \{w \in \Sigma^* : \delta^*(q_0, w) \in F\}$ tanımı işlendi. İkinci bölümde NFA'ya geçildi: geçişin bir durum kümesi vermesi, $\varepsilon$-geçişleri, ölü dallar, NFA'da kabul ve ret, $\{aa\}$, $\{ab\}^+$ ve $\{10\}^*$ örnekleri. Kabul durumu olmayan makinenin boş dili tanıdığı ve DFA'ların NFA'ların bir alt kümesi olduğu vurgulandı.

Son bölümde küme ve dizgi işlemleri (eleman/alt küme, birleşim, kesişim, Kartezyen çarpım, birleştirme, kuvvet kümesi, Kleene yıldızı ve artısı, ters çevirme) alıştırmalarla pekiştirildi ve verilen sonlu bir dil için DFA tasarımı yapıldı. Hoca DFA ile NFA'yı daha çok örnekle çalışacaklarını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
