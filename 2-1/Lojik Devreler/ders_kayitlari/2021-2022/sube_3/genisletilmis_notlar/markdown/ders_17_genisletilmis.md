# Ders 17 Genişletilmiş Notu: Türetilmiş Kapılarla Tasarım ve Kombinezonsal Devrelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden türetilmiş kapılar?
- 2. Temel kapıların NAND ve NOR ile yapılması
- 3. İndirgenmiş ifadelerin aynı tür kapılarla gerçeklenmesi
- 4. A1: Çarpımlar toplamının NAND tasarımı
- 5. A2: Çarpımlar toplamının NOR tasarımı
- 6. B1: Toplamlar çarpımının NAND tasarımı
- 7. B2: Toplamlar çarpımının NOR tasarımı
- 8. Kombinezonsal devreler
- 9. Kombinezonsal devre tasarım adımları ve basit örnekler
- 10. 2 bitlik genlik karşılaştırıcı
- Örnek Sorular
- Dersin Toparlaması

## 1. Neden türetilmiş kapılar?

Ders, bir önceki haftada işlenen fonksiyon indirgemenin devamı olarak başlar. <!-- BELİRSİZ: altyazıda geçen haftanın konusu "eksik bul işlevleri" diye yazılmış; büyük olasılıkla eksik tanımlı (don't care) fonksiyonlar kastediliyor --> Bu haftanın amacı, maliyet kavramıyla bağlantılı olarak bir devreyi olabildiğince aynı tür kapılarla kurmaktır. Tahtanın başlığı "Türetilmiş Kapılarla Temel Lojik Kapıların Yapılması"dır (ekrandan, 00:05:00).

Hoca gerekçeyi çip yapısı üzerinden anlatır. Bir tümleşik devre (çip) içinde aynı türden çok sayıda kapı bulunur; örneğin bir AND çipinde birden fazla AND kapısı vardır. Bir devre farklı türde kapılarla kurulursa her tür için ayrı bir çip gerekir ve bu çiplerin içindeki kapıların çoğu kullanılmadan kalır. Devre tek tür kapıyla kurulursa bir çipin içindeki bütün kapılar değerlendirilebilir (ekrandan, 00:10:00).

Türetilmiş kapılar burada NAND ve NOR'dur. Bunların yapımı maliyet bakımından normal AND ve OR'a göre daha uygun olduğu için NAND ve NOR yapıları tercih edilebilir.

## 2. Temel kapıların NAND ve NOR ile yapılması

### 2.1 Tümleme (NOT) kapısı

NAND kapısı $f = (ab)'$ işlemini yapar. İki girişin ikisine de aynı $a$ sinyali verilirse, yani girişler kısa devre edilirse, çıkış

$$f = (a\cdot a)' = a'$$

olur. Burada Boole cebrindeki $a\cdot a = a$ özdeşliği kullanılır: $0\cdot 0 = 0$ ve $1\cdot 1 = 1$ (ekrandan, 00:15:00).

NOR kapısında da aynı yol izlenir. NOR $f = (a+b)'$ verir; girişler kısa devre edilip $a$ verilirse $a + a = a$ olduğundan

$$f = (a + a)' = a'$$

elde edilir (ekrandan, 00:15:00). Hoca tahtaya ilk çizdiğinde NAND ile NOR'un yerini karıştırdığını fark edip düzeltti; doğru eşleşme yukarıdaki gibidir.

Hocanın verdiği pratik örnek: elimizde bir NOR çipi olsun ve kapılarının bir kısmını kullanmış olalım. Devrenin bir yerinde bir NOT kapısına ihtiyaç duyulursa ayrı bir NOT çipi almak gerekmez; boşta kalan bir NOR kapısının iki girişi birleştirilip $a$ verilirse çıkışta $a'$ elde edilir.

### 2.2 VE (AND) kapısı

AND iki şekilde gerçeklenebilir.

Birinci yol çift tümlemedir: $f = ab = \left((ab)'\right)'$. İçteki $(ab)'$ bir NAND'dir. Dıştaki tümleme ise bir önceki adımda öğrenilen NOT'tur; NOT da girişleri kısa devre edilmiş bir NAND ile yapılır. Sonuç olarak iki NAND kapısı yeterlidir: birincisi $a$ ve $b$'yi alır, ikincisi birincinin çıkışını tümler.

İkinci yol De Morgan kuralıdır: $ab = \left((ab)'\right)' = (a' + b')'$. $a'$'ye $X$, $b'$'ye $Y$ denirse ifade $(X+Y)'$, yani bir NOR olur. $a'$ ve $b'$ de girişleri kısa devre edilmiş birer NOR ile üretilir. Böylece AND üç NOR kapısıyla kurulur (ekrandan, 00:20:00):

```text
a --[NOR, girişler kısa devre]-- a' --+
                                      +--[NOR]-- a.b
b --[NOR, girişler kısa devre]-- b' --+
```

İki devre birbirine eşdeğerdir; biri NAND, öteki NOR ile kurulmuştur. Tasarımda hangisinin kullanılacağı tasarımcının elindeki kapıya bağlıdır.

### 2.3 VEYA (OR) kapısı

Hoca burada da yapılan işin hep aynı olduğunu söyler: temel ifade Boole işlemleriyle manipüle edilip NOR ya da NAND biçimine getirilir.

NOR ile: $f = a + b = \left((a+b)'\right)'$. İçteki $(a+b)'$ bir NOR'dur, dıştaki tümleme de girişleri kısa devre edilmiş bir NOR ile yapılır. İki NOR yeterlidir.

NAND ile: $a + b = \left((a+b)'\right)' = (a'b')'$. $a'$'ye $X$, $b'$'ye $Y$ denirse ifade $(XY)'$, yani bir NAND olur. $a'$ ve $b'$ girişleri kısa devre edilmiş iki NAND ile üretilir; toplam üç NAND gerekir.

Yine iki devre aynı çıkışı verir; fark birinde NOR, ötekinde NAND kullanılmasıdır.

## 3. İndirgenmiş ifadelerin aynı tür kapılarla gerçeklenmesi

Tahtanın yeni başlığı "İndirgenmiş İfadelerin Aynı Tür Kapılarla Gerçeklenmesi"dir (ekrandan, 00:25:00). Geçen hafta kanonik biçimlerin lojik kapılarla gerçeklenmesi anlatılmıştı. İki temel ifade biçimi vardır:

- Çarpımlar toplamı: çarpım şeklindeki terimler toplanır (örneğin $abc + \bar b c + cd$ gibi).
- Toplamlar çarpımı: toplam şeklindeki terimler çarpılır (örneğin $(a + c)(c + \bar d)$ gibi).

Hoca burada bu terimlerin minterm değil, indirgenmiş ifadedeki çarpım ya da toplam terimleri olduğunu ayrıca belirtir.

Genel gösterimde değişkenler $x_i$ ile gösterilir ($x_1$, $x_2$, ... bizim $a$, $b$, $c$'mize karşılık gelir). Çarpımlar toplamı ve toplamlar çarpımı (ekrandan, 00:30:00):

$$f = \sum\prod x_i \qquad\qquad f = \prod\sum x_i$$

Dört tasarım sırayla ele alınacaktır:

| Kod | İfade biçimi | Kullanılan kapı |
|---|---|---|
| A1 | Çarpımlar toplamı | NAND (TVE) |
| A2 | Çarpımlar toplamı | NOR (TVEYA) |
| B1 | Toplamlar çarpımı | NAND (TVE) |
| B2 | Toplamlar çarpımı | NOR (TVEYA) |

## 4. A1: Çarpımlar toplamının NAND tasarımı

### 4.1 Genel dönüşüm

Çarpımlar toplamı biçimindeki ifadenin tümleyeni alınır:

$$\bar f = \overline{\sum\prod x_i}$$

De Morgan'a göre toplamın tümleyeni, tümleyenlerin çarpımıdır. Hoca bunu iki terimli bir örnekle açıklar: $(ab + cd)' = (ab)'\,(cd)'$ (ekrandan, 00:30:00). Yani içerideki her çarpım teriminin tümleyeni alınır ve dıştaki toplam ($\Sigma$) çarpıma ($\Pi$) döner:

$$\bar f = \prod\overline{\prod x_i}$$

Bu ifadenin bir kez daha tümleyeni alınırsa $f$'e dönülür:

$$f = \overline{\prod\overline{\prod x_i}}$$

(ekrandan, 00:35:00). İçerideki $\overline{\prod x_i}$ terimleri $(XY)'$ biçimindedir, yani NAND'dir. Bunlara $X$, $Y$ denirse dıştaki ifade de $(XY)'$, yani yine NAND olur. Böylece ifade yalnız NAND'lerle gerçeklenebilir.

### 4.2 Örnek

Verilen fonksiyon (ekrandan, 00:35:00):

$$f = \bar a\bar b c + \bar a b c + a b\bar c + abc \qquad \text{(NAND ile gerçekleyiniz)}$$

Önce indirgeme yapılır. Hoca doğruluk tablosunu tam yazmak yerine doğrudan Karnaugh haritasına geçer. 3 değişken olduğu için $2\times 4$ bir harita yeterlidir; satırlar $a$, sütunlar $bc$ (00, 01, 11, 10 sırasıyla):

| $a \backslash bc$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 |

- $\bar a\bar b c$: $a=0$, $b=0$, $c=1$ hücresi.
- $\bar a b c$: $a=0$, $b=c=1$ hücresi.
- $a b\bar c$: $a=b=1$, $c=0$ hücresi.
- $abc$: hepsinin 1 olduğu hücre.

En büyük komşuluklar alınır: üst satırdaki ikili grup $\bar a c$, alt satırdaki ikili grup $ab$ verir. Bütün 1'ler kapsandığı için başka gruba gerek yoktur. Hoca $ab$ grubunun terimini öğrencilere sordu, öğrenciler $ab$ cevabını verdi. Sonuç:

$$f = ab + \bar a c$$

(ekrandan, 00:35:00). Şimdi NAND biçimine dönüştürülür. Çift tümleme alınır ve içteki tümleme De Morgan ile dağıtılır:

$$f = \overline{\overline{ab + \bar a c}} = \overline{(ab)'\,(\bar a c)'}$$

İçteki $(ab)'$ ve $(\bar a c)'$ birer NAND'dir; bunlar $X$ ve $Y$ kabul edilirse dış ifade $(XY)'$ olur, o da bir NAND'dir. Devre (ekrandan, 00:40:00):

```text
a, b ------------------------------> [NAND] --(ab)'----+
a ---> [NAND, girişler kısa devre] --> a'              +--> [NAND] --> f = ab + a'c
a', c -----------------------------> [NAND] --(a'c)'--+
```

Toplam 4 NAND kullanılır. (Python ile bütün girişlerde $f$ ile aynı çıkışı verdiği doğrulandı.)

## 5. A2: Çarpımlar toplamının NOR tasarımı

### 5.1 Genel dönüşüm

NOR tasarımında amaç ifadeyi $(x + y)'$ biçimlerine getirmektir (ekrandan, 00:40:00). Genel ifade $f = \sum\prod x_i$'dir; içteki çarpım terimi için bir dönüşüm gerekir.

Hoca bunu önce bir örnekle gösterir: $ab$ çarpımının iki kez tümleyeni alınıp içteki tümlemeye De Morgan uygulanırsa

$$ab = \overline{\overline{ab}} = \overline{a' + b'}$$

olur (ekrandan, 00:40:00). Yani bir çarpım terimi, içindeki değişkenlerin tümleyenleri alınıp toplanması ve bu toplamın tümleyeninin alınmasıyla ifade edilebilir:

$$\prod x_i = \overline{\sum \bar x_i}$$

Bu terimler $(X + Y)'$ biçimindedir, yani zaten NOR'dur. Bunları yerine koyunca

$$f = \sum\overline{\sum\bar x_i}$$

elde edilir. Ancak dıştaki işlem hâlâ düz bir toplamdır. Onu da NOR yapmak için önce $f$'in tümleyeni gerçeklenir:

$$\bar f = \overline{\sum\overline{\sum\bar x_i}}$$

Bu artık tamamen NOR'dur. Son adımda $\bar f$'in bir kez daha tümleyeni alınarak $f$'e dönülür; bir fonksiyonun çıkışını tümlemek kolaydır, girişleri kısa devre edilmiş bir NOR yeterlidir. Hoca $\bar f$'ten başlamanın nedeninin, dıştaki $x + y$ ifadesinin NOR biçiminde olmasını sağlamak olduğunu vurgular.

### 5.2 Örnek

Bir önceki örneğin indirgenmiş hali kullanılır (ekrandan, 00:45:00):

$$f(a,b,c) = ab + \bar a c$$

Her çarpım terimi NOR biçimine çevrilir:

$$ab = \overline{\bar a + \bar b}, \qquad \bar a c = \overline{\bar{\bar a} + \bar c} = \overline{a + \bar c}$$

$$f = \overline{(\bar a + \bar b)} + \overline{(a + \bar c)}$$

Bu terimlere $X$ ve $Y$ denirse $f = X + Y$ olur. $(X+Y)'$ biçimini elde etmek için tümleyen alınır:

$$\bar f = \overline{\overline{(\bar a + \bar b)} + \overline{(a + \bar c)}}$$

(ekrandan, 00:45:00). Devre şöyle kurulur:

```text
a --> [NOR, kısa devre] --> a'  --+
b --> [NOR, kısa devre] --> b'  --+--> [NOR] --> (a'+b')' --+
                                                           +--> [NOR] --> f' --> [NOR, kısa devre] --> f
a --------------------------------+                         |
c --> [NOR, kısa devre] --> c'  --+--> [NOR] --> (a+c')' --+
```

Kullanılan NOR sayısı (sayım derste yapılmadı, ara adım eklendi): $a'$, $b'$, $c'$ için 3, iki terim için 2, $\bar f$ için 1 ve çıkış tümlemesi için 1; toplam 7. (Python ile doğrulandı.)

## 6. B1: Toplamlar çarpımının NAND tasarımı

### 6.1 Genel dönüşüm

Tahtanın başlığı "B1 Toplamlar Çarpımı (NAND) Tasarımı, TVE"dir (ekrandan, 00:50:00). Genel ifade $f = \prod\sum x_i$'dir. NAND tasarımı için ifadenin $(a\cdot b)'$, yani $(x\cdot y)'$ biçimlerine getirilmesi gerekir. Bu, A2'deki işlemin tam tersidir.

Önce bir toplam terimi çarpımın tümleyeni biçimine getirilir. Örnek:

$$a + b = \overline{\overline{a + b}} = \overline{\bar a\,\bar b}$$

Yani içerideki değişkenlerin tümleyeni alınır, çarpılır ve çarpımın tümleyeni alınır:

$$\sum x_i = \overline{\prod\bar x_i}$$

Bunlar $(XY)'$ biçimindedir, yani NAND'dir. Yerine koyunca $f = \prod\overline{\prod\bar x_i}$ olur. Dıştaki çarpımın da NAND olması için $\bar f$ gerçeklenir:

$$\bar f = \overline{\prod\overline{\prod\bar x_i}}$$

(ekrandan, 00:55:00). Çıkışa girişleri kısa devre edilmiş bir NAND eklenerek $\bar f$'ten $f$'e dönülür.

### 6.2 Örnek

Verilen fonksiyon (ekrandan, 00:55:00):

$$f(a,b,c) = (a+b)(\bar a + c) \qquad \text{(NAND ile)}$$

Her toplam terimi NAND biçimine çevrilir:

$$a + b = \overline{\bar a\,\bar b}, \qquad \bar a + c = \overline{a\,\bar c}$$

$$f = \overline{\bar a\,\bar b}\cdot\overline{a\,\bar c}$$

Bu terimlere $X$ ve $Y$ denirse $f = XY$, yani düz bir AND'dir. Onu NAND biçimine getirmek için tümleyen alınır:

$$\bar f = \overline{\overline{\bar a\,\bar b}\cdot\overline{a\,\bar c}}$$

<!-- BELİRSİZ: bu örneğin tahtadaki ara satırları karelerde görünmüyor; altyazıda ikinci terim bozuk yazılmış ("A üstü A artı C üstü"); ifade anlatımdan kuruldu ve python ile denetlendi -->

Devre şöyle kurulur:

```text
a --> [NAND, kısa devre] --> a' --+
b --> [NAND, kısa devre] --> b' --+--> [NAND] --> (a'b')' --+
                                                           +--> [NAND] --> f' --> [NAND, kısa devre] --> f
a --------------------------------+                         |
c --> [NAND, kısa devre] --> c' --+--> [NAND] --> (ac')' ---+
```

Hoca kapıları tek tek saydı: toplam 7 NAND.

### 6.3 Tek tür kapının getirdiği kazanç

Aynı ifade doğrudan kurulsaydı bir NOT ($\bar a$ için), iki OR ve bir AND gerekirdi. Kapı sayısı daha az olurdu ama 3 farklı kapı türü, yani 3 ayrı çip gerekirdi. NAND tasarımında 7 kapı kullanılır, ama bir çipte 8 NAND bulunuyorsa devrenin tamamı tek çiple kurulur.

> **Hocanın vurgusu:** Biraz daha fazla sayıda NAND kullanılsa da hepsi tek bir çipin içinde kalıyorsa devre tek çiple biter; farklı kapı türleriyle kurulursa 3 çip gerekir.

## 7. B2: Toplamlar çarpımının NOR tasarımı

### 7.1 Genel dönüşüm

Son tasarım "B2 Toplamlar Çarpımı (NOR) Tasarımı, TVEYA"dır (ekrandan, 01:00:00). Genel ifade $f = \prod\sum x_i$; NOR için $(a+b)'$ biçimi gerekir. İçeride zaten toplam vardır.

Önce $\bar f$ alınır. Çarpımın tümleyeni De Morgan ile toplama döner ve içteki her toplam teriminin tümleyeni alınır:

$$\bar f = \sum\overline{\sum x_i}$$

İçteki terimler toplamların tümleyenidir, yani NOR'dur. Bir kez daha tümleyen alınırsa

$$f = \overline{\sum\overline{\sum x_i}}$$

olur (ekrandan, 01:05:00). Dıştaki işlem de bir toplamın tümleyenidir, yani NOR. Bu tasarımda çıkışta ayrıca bir tümleme kapısı gerekmez.

### 7.2 Örnek

Aynı standart örnek kullanılır: $f(a,b,c) = (a+b)(\bar a + c)$ (ekrandan, 01:05:00).

$$\bar f = \overline{(a+b)} + \overline{(\bar a + c)}$$

Bu terimlere $X$ ve $Y$ denirse $\bar f = X + Y$ olur. Bir kez daha tümleyen alınınca

$$f = \overline{\bar f} = \overline{\overline{(a+b)} + \overline{(\bar a + c)}}$$

elde edilir; dıştaki tümleme son NOR'a yerleşir. Devre (ekrandan, 01:05:00):

```text
a, b -----------------------------> [NOR] --(a+b)'----+
a ---> [NOR, girişler kısa devre] --> a'               +--> [NOR] --> f
a', c ----------------------------> [NOR] --(a'+c)'---+
```

Toplam 4 NOR kullanılır. (Python ile doğrulandı.)

> **Hocanın vurgusu:** Bu dört tasarımda yapılan iş yalnız De Morgan kuralını ve çift tümlemeyi uygulamaktır; başka bir şey yoktur.

## 8. Kombinezonsal devreler

Aradan sonra hoca, elde edilen kapı bilgileriyle kombinezonsal devrelerin tasarımına geçer (ekrandan, 01:20:00).

Kombinezonsal devre, çıkışı yalnız o andaki giriş değerlerine bağlı olan ve bilinen kapıların bir araya getirilmesiyle oluşan lojik devredir. Devrenin $x_1, x_2, \dots, x_n$ girişleri (bildiğimiz $a$, $b$, $c$ değişkenleri) ve bir çıkış fonksiyonu vardır. $t$ anındaki çıkış, $t$ anındaki girişlerden üretilir; hafıza yapısına gerek yoktur. Tahtada kutunun altına "hafıza" yazılıp üstü çizilmiştir (ekrandan, 01:20:00).

Bu bölümde sırayla şunlar görülecektir:

- Aritmetik toplama/çıkarma devreleri: yarı toplayıcı ve yarı çıkarıcı, tam toplayıcı ve tam çıkarıcı.
- Özelleşmiş kombinezonsal devreler: çoğullayıcı (multiplexer, seçici) ve onun tersi gibi çalışan dağıtıcı (demultiplexer).
- Kod çözücü (decoder) ve kodlayıcı (encoder).
- Bunların birleşimiyle ALU (aritmetik lojik birim) tasarımı.
- 7 bölmeli gösterge (seven segment display).
- Son olarak çıkış bağlantı şekilleri.

Bu devrelerin gerçeklenmesinde AND, OR, NAND, NOR, XOR ve XNOR, yani temel ve türetilmiş kapılar kullanılacaktır.

## 9. Kombinezonsal devre tasarım adımları ve basit örnekler

### 9.1 Adımlar

Tahtada "Kombinezonsal Devre Tasarımı" başlığıyla adımlar yazılır (ekrandan, 01:25:00):

1. Problem tanımı: problem sözle tanıtılır; kutunun ne yapacağı, kaç giriş ve kaç çıkış alacağı söylenir.
2. Giriş/çıkış değişkenlerinin sayısı ve varsa isimlendirilmesi: girişler $x_1 \dots x_n$, çıkışlar $z_1 \dots z_m$. Hoca çıkış sayısının giriş sayısıyla aynı olmak zorunda olmadığını, bu yüzden $z_n$ değil $z_m$ yazdığını belirtir.
3. Probleme ilişkin doğruluk tablosu oluşturulur.
4. Her çıkışa ait lojik fonksiyon bulunur ve en az maliyet için indirgenir. Her çıkış farklı olduğundan ayrı bir fonksiyon olarak ele alınır. Yöntem: görüşe dayalı Karnaugh haritası ya da Quine-McCluskey.
5. Kullanılacak lojik devre elemanları belirlenir. Tek tip kapı kullanılacaksa indirgenmiş çıkış fonksiyonları bu derste görülen NAND/NOR dönüşümleriyle yeniden düzenlenir; tek tip kapı istenmiyorsa indirgenmiş haller doğrudan kullanılır.
6. Devre şeması çizilir.

### 9.2 Örnek: "ikisi de 0 ise 0" devresi

İki girişli ($x_1$, $x_2$), bir çıkışlı bir devre isteniyor. Girişlerin ikisi de 0 ise çıkış 0, aksi durumda 1 olacak (ekrandan, 01:30:00).

| $x_1$ | $x_2$ | $z$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

İki değişkenli Karnaugh haritasında iki grup alınır: biri $x_2$, öteki $x_1$ verir. Sonuç

$$z = x_1 + x_2$$

yani en basit haliyle tek bir OR kapısı. Hoca, öğrencilerin bunun hangi eleman olduğunu zaten bildiğini, ama burada amacın sözel bir problem tanımından yola çıkmak olduğunu söyler.

### 9.3 Örnek: eşitlik devresi

İki girişli, bir çıkışlı bir devre: girişler birbirine eşitse çıkış 1, farklıysa 0. Hoca doğruluk tablosunu ilk yazışında çıkışları ters yazdı (eşitse 0), öğrencilerin uyarısıyla düzeltti. Doğru tablo:

| $x_1$ | $x_2$ | $z$ |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Karnaugh haritasında 1'ler komşu değildir, indirgeme olmaz:

$$z = \bar x_1\bar x_2 + x_1x_2$$

Bu ifade iki şekilde kurulabilir: $x_1$ ve $x_2$'nin tümleyenini alan NOT'lar, iki AND ve bir OR ile; ya da tek bir XNOR kapısıyla (ekrandan, 01:35:00). İki devre birbirinin muadilidir. Hangisinin seçileceği elde hangi çipin olduğuna bağlıdır; ilk yolda NOT, AND ve OR olmak üzere daha fazla kapı türü gerekir.

## 10. 2 bitlik genlik karşılaştırıcı

### 10.1 Problem tanımı

İki bitlik iki sayı olsun: $A = a_1a_0$ ve $B = b_1b_0$. $a_0$ en anlamsız bit (LSB), $a_1$ en anlamlı bit (MSB) (ekrandan, 01:35:00). Bu iki sayıyı karşılaştıran devreye genlik karşılaştırıcı (amplitude comparator) denir.

Girişler $a_1, a_0, b_1, b_0$; üç çıkış vardır:

- $Z_{A>B}$: $A$, $B$'den büyükse 1.
- $Z_{A=B}$: $A$ ile $B$ eşitse 1.
- $Z_{A<B}$: $A$, $B$'den küçükse 1.

Her giriş kombinasyonunda bu üç çıkıştan yalnız biri 1, diğerleri 0'dır.

### 10.2 Doğruluk tablosu

16 satırlık tablo, $A$'nın değerine göre dört bloğa ayrılarak doldurulur: önce $A = 0$ ($a_1a_0 = 00$), sonra $A = 1$, $A = 2$ ve $A = 3$. Her blokta $B$, $00$'dan $11$'e kadar yazılır (ekrandan, 01:40:00).

| $a_1$ | $a_0$ | $b_1$ | $b_0$ | $A>B$ | $A=B$ | $A<B$ |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 1 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 | 1 |
| 0 | 0 | 1 | 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 1 | 0 | 0 | 1 |
| 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 1 | 0 |

Hoca tabloyu doldururken satır satır gerekçe verir: ilk satırda iki sayı da 0 olduğu için eşitlik çıkışı 1'dir; $A = 0$ bloğunun geri kalanında $B$ daha büyüktür; $A = 1$ bloğunda yalnız $B = 0$'da $A$ büyüktür; $A = 2$ bloğunda 2, 0 ve 1'den büyüktür; $A = 3$ bloğunda son satır dışında hep $A$ büyüktür. (Tablo python ile doğrulandı.)

### 10.3 Çıkış fonksiyonları

Üç çıkış olduğu için üç ayrı fonksiyon vardır ($F_1$, $F_2$, $F_3$). Her biri için satırlar $a_1a_0$, sütunlar $b_1b_0$ olan 4 değişkenli bir Karnaugh haritası çizilir (satır ve sütun sırası 00, 01, 11, 10).

**$F_1 = Z_{A>B}$.** Haritada 6 adet 1 vardır. En büyük komşulukla başlanır, kenarda tek 1 bırakmamak için iki grup daha alınır:

$$Z_{A>B} = a_1\bar b_1 + a_0\bar b_1\bar b_0 + a_1a_0\bar b_0$$

> **Soru:** Hoca ikinci grubun terimini öğrencilere sorarken "$\bar b_1\bar b_0$, başa ne gelecek, $\bar a_0$" dedi; bir öğrenci "$a_0$ gelmeyecek mi?" diye sordu. **Cevap:** Hoca öğrencinin haklı olduğunu söyledi; terim $a_0\bar b_1\bar b_0$'dır.

**$F_2 = Z_{A=B}$.** Haritada 4 adet 1 vardır ve hepsi köşegen üzerindedir (ekrandan, 01:45:00). Hiçbiri birbirine komşu değildir, köşegenler de komşuluk oluşturmaz; her biri tek başına alınır:

$$Z_{A=B} = \bar a_1\bar a_0\bar b_1\bar b_0 + \bar a_1a_0\bar b_1b_0 + a_1a_0b_1b_0 + a_1\bar a_0b_1\bar b_0$$

Oldukça uzun bir fonksiyondur ve dört girişli AND kapılarıyla gerçeklenir.

**$F_3 = Z_{A<B}$.** Haritada yine 6 adet 1 vardır ve $Z_{A>B}$'ye benzer şekilde üç grup alınır. Hoca bir terimi önce $\bar b_0$ ile söyleyip hemen $b_0$ olarak düzeltti:

$$Z_{A<B} = \bar a_1 b_1 + \bar a_1\bar a_0 b_0 + \bar a_0 b_1 b_0$$

(Üç fonksiyon da python ile 16 girişin hepsinde doğrulandı.)

### 10.4 Devre

Devrenin girişleri $A$ sayısı için $a_1, a_0$, $B$ sayısı için $b_1, b_0$; çıkışları $Z_{A>B}$, $Z_{A=B}$ ve $Z_{A<B}$'dir. Girişlerin gerekli tümleyenleri alınır; $Z_{A>B}$ ve $Z_{A<B}$ için iki ve üç girişli AND'ler birer OR'a, $Z_{A=B}$ için dört girişli dört AND bir OR'a bağlanır. İç yapı karmaşıktır, ama yaptığı iş girişlerdeki iki sayıyı karşılaştırıp ilgili çıkışta 1 üretmektir.

Hoca bu devrenin bir lojik simülatörde kurulmasını önerdi: girişlere farklı değerler verilip her çıkışa bir LED gibi yanan bir eleman (diğer ayağı toprağa bağlı) bağlanırsa, büyük, eşit ve küçük durumlarında ayrı çıkışların yandığı gözlenebilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00)

$f = \bar a\bar b c + \bar a b c + a b\bar c + abc$ fonksiyonunu NAND kapılarıyla gerçekleyiniz.

> **Çözüm (derste verildi):** Karnaugh haritasından $f = ab + \bar a c$. Çift tümleme ve De Morgan ile $f = \overline{(ab)'\,(\bar a c)'}$. $(ab)'$ bir NAND, $\bar a$ girişleri kısa devre edilmiş bir NAND, $(\bar a c)'$ bir NAND ve çıkış bir NAND ile; toplam 4 NAND (ekrandan, 00:40:00).

**Soru 2** (ekrandan, 00:45:00)

$f(a,b,c) = ab + \bar a c$ fonksiyonunu yalnız NOR kapılarıyla gerçekleyiniz.

> **Çözüm (derste verildi):** $f = \overline{(\bar a + \bar b)} + \overline{(a + \bar c)}$, $\bar f = \overline{\overline{(\bar a + \bar b)} + \overline{(a + \bar c)}}$. $\bar a$, $\bar b$, $\bar c$ kısa devre NOR'larla; iki terim birer NOR'la; $\bar f$ bir NOR'la; son olarak kısa devre bir NOR ile $f$ elde edilir.

**Soru 3** (ekrandan, 00:55:00)

$f(a,b,c) = (a+b)(\bar a + c)$ fonksiyonunu NAND kapılarıyla gerçekleyiniz.

> **Çözüm (derste verildi):** $f = \overline{\bar a\bar b}\cdot\overline{a\bar c}$, $\bar f = \overline{\overline{\bar a\bar b}\cdot\overline{a\bar c}}$; çıkışa kısa devre bir NAND eklenir. Toplam 7 NAND.

**Soru 4** (ekrandan, 01:05:00)

$f(a,b,c) = (a+b)(\bar a + c)$ fonksiyonunu NOR kapılarıyla gerçekleyiniz.

> **Çözüm (derste verildi):** $f = \overline{\overline{(a+b)} + \overline{(\bar a + c)}}$; $(a+b)'$ için bir NOR, $\bar a$ için kısa devre bir NOR, $(\bar a + c)'$ için bir NOR ve çıkış NOR'u; toplam 4 NOR.

**Soru 5** (ekrandan, 01:30:00)

İki girişli, bir çıkışlı bir kombinezonsal devrede girişlerin ikisi de 0 ise çıkış 0, aksi halde 1 olsun. Devreyi tasarlayınız.

> **Çözüm (derste verildi):** Doğruluk tablosu $z = 0, 1, 1, 1$; Karnaugh haritasından $z = x_1 + x_2$, tek bir OR kapısı.

**Soru 6** (derste sözlü ve ekrandan, 01:28:57 ve 01:35:00)

İki girişli, bir çıkışlı bir kombinezonsal devrede girişler birbirine eşitse çıkış 1, farklıysa 0 olsun. Devreyi tasarlayınız.

> **Çözüm (derste verildi):** $z = \bar x_1\bar x_2 + x_1x_2$; NOT, AND, OR ile ya da tek bir XNOR kapısıyla.

**Soru 7** (ekrandan, 01:35:00 ve 01:50:00)

2 bitlik iki sayıyı ($A = a_1a_0$, $B = b_1b_0$) karşılaştıran genlik karşılaştırıcıyı tasarlayınız; $Z_{A>B}$, $Z_{A=B}$ ve $Z_{A<B}$ çıkışlarını bulunuz. Devreyi bir simülatör yardımıyla gerçekleyiniz ve büyük, eşit, küçük durumları için birer örnekle ilgili çıkışın 1 olduğunu gösteriniz.

> **Çözüm (derste verildi, simülasyon kısmı hariç):** $Z_{A>B} = a_1\bar b_1 + a_0\bar b_1\bar b_0 + a_1a_0\bar b_0$; $Z_{A=B} = \bar a_1\bar a_0\bar b_1\bar b_0 + \bar a_1a_0\bar b_1b_0 + a_1a_0b_1b_0 + a_1\bar a_0b_1\bar b_0$; $Z_{A<B} = \bar a_1 b_1 + \bar a_1\bar a_0 b_0 + \bar a_0 b_1 b_0$. Örneğin $A = 2$, $B = 1$ ($a_1a_0b_1b_0 = 1001$) için yalnız $Z_{A>B} = 1$; $A = B = 3$ ($1111$) için yalnız $Z_{A=B} = 1$; $A = 1$, $B = 2$ ($0110$) için yalnız $Z_{A<B} = 1$ (python ile doğrulandı; örnek girişler derste verilmedi).

## Dersin Toparlaması

Dersin ilk yarısında NOT, AND ve OR kapılarının yalnız NAND ya da yalnız NOR ile nasıl kurulacağı, ardından indirgenmiş bir fonksiyonun tamamının tek tür kapıyla nasıl gerçekleneceği görüldü. Dört durumun hepsi (çarpımlar toplamı ve toplamlar çarpımı, NAND ve NOR) çift tümleme ile De Morgan kuralının uygun yerlere uygulanmasından ibarettir. Çarpımlar toplamı doğal olarak iki seviyeli NAND'e, toplamlar çarpımı da iki seviyeli NOR'a dönüşür; çapraz durumlarda (A2 ve B1) önce $\bar f$ gerçeklenip çıkışta bir tümleme kapısı eklenir. Tek tür kapı, kapı sayısı artsa bile çip sayısını azaltır.

İkinci yarıda kombinezonsal devreler tanımlandı ve altı adımlı tasarım yöntemi verildi. OR, XNOR ve 2 bitlik genlik karşılaştırıcı örnekleri bu adımlarla çözüldü. Sonraki derslerde aynı yöntemle yarı ve tam toplayıcı/çıkarıcı, çoğullayıcı, dağıtıcı, kod çözücü, kodlayıcı, ALU ve 7 bölmeli gösterge gibi devreler ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
