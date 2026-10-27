# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 23 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:04:00'te başlar. Kaydın başı bekleme ve sohbettir.
  - Dersin ikinci yarısında hoca önceden çektiği Karnaugh videolarını Zoom'dan oynatır. Video paylaşımı ilk denemelerde çalışmaz; anlatım yaklaşık 01:40:00'te oturur.
- Önceki haftaların tekrarı
  - Önerme, mantık kapıları (AND, OR, NOT, XOR), koşullu önerme, çift koşullu önerme, mantıksal denklik.
  - Karşıt (converse), ters-karşıt (contrapositive), totoloji (tautology), çelişki (contradiction).
  - İspat yöntemleri: doğrudan, dolaylı ve tümevarımla ispat.
- Bool cebri (Boolean algebra)
  - $B = \{0, 1\}$ üzerinde toplama (OR), çarpma (AND, Boolean product) ve tümleyen (complement).
  - Arama motorlarında `OR` ve `AND` ile sorgu örneği (bilgi getirimi, information retrieval).
- Bool ifadeleri ve Bool fonksiyonları
  - $n$. dereceden Bool fonksiyonu $F: B^n \to B$.
  - Doğruluk tablosuyla fonksiyon değeri hesaplama.
  - Günlük hayat modeli: dezenfektan, maske ve araba değişkenleriyle "risk" fonksiyonu.
  - $n$ değişkenli farklı Bool fonksiyonu sayısı.
- Bool cebri özdeşlikleri (Boolean identities)
- Mintermler, çarpımların toplamı açılımı (sum-of-products expansion)
- Mantık kapılarıyla devre çizimi ve yarım toplayıcı (half adder)
- Karnaugh haritaları (Karnaugh map)
  - İki, üç ve dört değişkenli haritalar.
  - Gray kodu ve mintermlerin haritaya yerleştirilmesi.
  - Gruplama kuralları ve grupların okunması.
  - Çözümlü örnekler ve üç alıştırma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karnaugh haritası, Bool fonksiyonunu sadeleştirmenin en hızlı ve en az hatalı yoludur.
  - Hoca, aynı sadeleştirmeyi Bool özdeşlikleriyle yaparken derste takıldığını söyledi. Tabloyla ya da haritayla yaparken hiç hata yapmadığını vurguladı.
- Gruplar her zaman 2'nin kuvveti büyüklüğünde olur: 1, 2, 4, 8, 16.
  - Önce en büyük grup aranır. Sonra bir küçüğüne inilir.
  - Grup kare ya da dikdörtgen olur. Çapraz (diagonal) ya da "L" biçimli grup alınmaz.
  - Daha büyük bir grup kurmaya yarıyorsa, önceden gruplanmış bir 1 tekrar kullanılabilir.
  - Açıkta 1 kalmayınca gruplama biter.
- Haritanın kenarları komşudur.
  - Sağ ve sol kenar birleşir. Üst ve alt kenar birleşir. Dört köşe de bir grup oluşturabilir ("bohça gibi katlama").
- Gereksiz grup almayın.
  - Hoca bunun "çok yapılan bir hata" olduğunu söyledi. Diğer grupların tamamen kapsadığı bir grup sonucu sadeleştirmez, fazladan terim ekler.
- Doğruluk tablosunu 0'dan başlatın: 000, 001, ... Sütunlar sağdan sola $2^0$, $2^1$, $2^2$ basamaklarıdır.
- Haritanın satır ve sütun etiketleri Gray koduna göre yazılır: 00, 01, 11, 10.
  - Bu yüzden 3. ve 4. sütundaki mintermler yer değiştirir.
- Fonksiyonu minterm listesiyle ($\Sigma$) vermek ve yazmak hata ihtimalini çok azaltır.
- Fonksiyonları sadeleştirmek devrede daha az kapı demektir. Elinizde sınırlı sayıda kapı olabilir, kart üzerinde yer kalmayabilir.
- Ayrık matematikte Karnaugh haritası 4 değişkene kadar işlenir. Daha fazlası lojik / sayısal tasarım derslerinde görülür.
- Akademik metinlerdeki matematiksel gösterimden korkmayın. Bu gösterim, sözle anlatılanın kısa yazılışıdır.

## Kısa Tekrar Notları

- Bool cebrinde $1 + 1 = 1$ (OR). İkilik aritmetikte ise $1 + 1 = 10_2$ (toplam 0, elde 1).
- $n$ değişkenli doğruluk tablosunda $2^n$ satır vardır.
- $n$ değişkenli farklı Bool fonksiyonu sayısı $2^{2^n}$'dir. $n=2$ için $2^4 = 16$.
- Minterm: bütün değişkenlerin (düz ya da tümleyen hâliyle) çarpımıdır. Numarası, değişken değerlerinin ondalık karşılığıdır. Örnek: $A=1, B=1$ ise minterm 3.
- Çarpımların toplamı: fonksiyonun 1 olduğu satırların mintermlerini `+` ile bağla.
- Önemli özdeşlikler:
  - $\overline{\overline{x}} = x$, $x + x = x$, $x \cdot x = x$
  - $x + 0 = x$, $x \cdot 1 = x$, $x + 1 = 1$, $x \cdot 0 = 0$
  - $x + \overline{x} = 1$, $x \cdot \overline{x} = 0$
  - $x(y+z) = xy + xz$, $x + yz = (x+y)(x+z)$
  - De Morgan: $\overline{xy} = \overline{x} + \overline{y}$, $\overline{x+y} = \overline{x}\,\overline{y}$
  - Yutma: $x + xy = x$, $x(x+y) = x$
- Karnaugh grubunu okuma: grubun sütunlarına ve satırlarına bak. Grubun her yerinde aynı kalan değişkenleri AND'le. Grupları OR'la.
- 2 değişken: $AB + \overline{A}B = B$.
- Bütün mintermler 1 ise sadeleşmiş fonksiyon $1$'dir.

## Detaylı Açıklamalar

### Bool cebri ve fonksiyonlar

Bool cebri yalnızca 0 ve 1 değerleri üzerinde çalışır. Toplama OR, çarpma AND, tümleyen NOT işlemine karşılık gelir. İşlem önceliği: önce parantez, sonra tümleyen, sonra çarpma, en son toplama.

$n$. dereceden Bool fonksiyonu $F: B^n \to B$ biçimindedir. Her $x_i \in \{0,1\}$ olur.

Derste hesaplanan fonksiyon: $F(x,y,z) = xy + \overline{z}$.

| $x$ | $y$ | $z$ | $xy$ | $\overline{z}$ | $F$ |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 | 1 |

İki Bool fonksiyonu, aynı değişken kümesi üzerinde bütün girişlerde aynı değeri veriyorsa eşittir. Örnek: $xy$, $xy + 0$ ve $xy \cdot 1$ birbirine eşittir.

Hoca, gerçek bir problemin de böyle modellendiğini anlattı. Değişkenler $x$ = dezenfektan, $y$ = maske, $z$ = özel araba olsun. Verilen kurallara göre her satırın riskli (1) ya da risksiz (0) olduğuna karar verilir. Sonra 1 olan satırlardan fonksiyon yazılır ve Karnaugh ile sadeleştirilir.

### $n$ değişkenli Bool fonksiyonu sayısı

İki değişkenin 4 giriş durumu vardır. Her durumda fonksiyon 0 ya da 1 olabilir. Bu yüzden $2^4 = 16$ farklı fonksiyon yazılabilir ($F_1$ ... $F_{16}$). Genel kural: $2^{2^n}$.

### İspat örneği: dağılma

Hoca derste bu ispatta takıldı ve ilk gönderenlere bonus verdi. Özdeşliklerle ispat:

$$(x+y)(x+z) = xx + xz + yx + yz = x + xz + xy + yz = x(1 + z + y) + yz = x + yz$$

Yutma özdeşlikleri de böyle ispatlanır:

- $x + xy = x(1 + y) = x \cdot 1 = x$
- $x(x+y) = xx + xy = x + xy = x$

Hoca, bu tür eşitlikleri doğruluk tablosuyla göstermenin çok daha kolay olduğunu söyledi. $x(y+z)$ ve $xy + xz$ sütunları sekiz satırda da aynı çıkar.

### Çarpımların toplamı örneği

Soru: $F(x,y,z) = (x+y)\overline{z}$ için çarpımların toplamı açılımını bulun.

- Tablodan: $F$, yalnız $z = 0$ ve $x+y = 1$ olan satırlarda 1'dir. Bunlar minterm 2, 4 ve 6'dır.
- Özdeşliklerle:
  - Dağılma: $x\overline{z} + y\overline{z}$
  - Eksik değişkenle çarp ($\cdot 1$ ve $a + \overline{a} = 1$): $x(y+\overline{y})\overline{z} + (x+\overline{x})y\overline{z}$
  - Aç: $xy\overline{z} + x\overline{y}\,\overline{z} + xy\overline{z} + \overline{x}y\overline{z}$
  - Tekrarı at ($a + a = a$): $F = xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$

### Mantık kapıları ve yarım toplayıcı

- $x\overline{y}$ gibi bir ifade için: bir NOT kapısı, bir AND kapısı.
- Aynı girişi birden fazla kapıya götürmek için yeni giriş açmaya gerek yok. Tel dallandırılır.
- Yarım toplayıcı iki biti toplar. İki çıkışı vardır:
  - Toplam (sum): $s = x \oplus y = (x + y)\overline{(xy)}$
  - Elde (carry): $c = xy$

| $x$ | $y$ | $c$ | $s$ |
| :-: | :-: | :-: | :-: |
| 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 |
| 0 | 0 | 0 | 0 |

- Tam toplayıcı (full adder) üç biti toplar. Lojik / sayısal tasarım dersinde ayrıntılı işlenir.

### Karnaugh haritası

Karnaugh haritasını 1953'te Maurice Karnaugh yayımladı. Benzer bir yöntemi bir yıl önce Edward Veitch önermişti.

**Gray kodu.** Ardışık iki kodda yalnız bir bit değişir:

| Ondalık | İkilik | Gray |
| :-: | :-: | :-: |
| 0 | 000 | 000 |
| 1 | 001 | 001 |
| 2 | 010 | 011 |
| 3 | 011 | 010 |
| 4 | 100 | 110 |
| 5 | 101 | 111 |

Haritada komşu iki göz yalnız bir değişkende farklı olmalıdır. Bu yüzden etiketler 00, 01, 11, 10 sırasıyla yazılır.

**Minterm yerleşimi.** Üç değişkende ($AB$ sütunda, $C$ satırda):

| $C$ / $AB$ | 00 | 01 | 11 | 10 |
| :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 2 | 6 | 4 |
| 1 | 1 | 3 | 7 | 5 |

Dört değişkende ($AB$ sütunda, $CD$ satırda):

| $CD$ / $AB$ | 00 | 01 | 11 | 10 |
| :-: | :-: | :-: | :-: | :-: |
| 00 | 0 | 4 | 12 | 8 |
| 01 | 1 | 5 | 13 | 9 |
| 11 | 3 | 7 | 15 | 11 |
| 10 | 2 | 6 | 14 | 10 |

**Bir terimde eksik değişken.** $AC$ terimi 3 değişkenli bir fonksiyonda hem $B$ hem $\overline{B}$ durumunu kapsar: $AC = ABC + A\overline{B}C$. Haritada iki göze 1 konur.

**Çözümlü örnekler** (hepsi Python ile kontrol edildi):

| Fonksiyon | Sadeleşmiş hâli |
| :-- | :-- |
| $AB + \overline{A}B$ | $B$ |
| $\Sigma(0,2,3)$, 2 değişken | $A + \overline{B}$ |
| $\Sigma(0,1,2,3)$, 2 değişken | $1$ |
| $AB + \overline{A}B + AC = \Sigma(2,3,5,6,7)$ | $B + AC$ |
| $\Sigma(0,1,4,5,6,7)$ | $A + \overline{B}$ (kenarlar komşu) |
| $\Sigma(1,2,3,4,5,6,7)$ | $A + B + C$ |
| $\Sigma(1,5,7,9,10,11,13,15)$ | $\overline{C}D + BD + A\overline{B}C$ |
| $\Sigma(0,2,4,5,7,8,10)$ | $\overline{B}\,\overline{D} + \overline{A}B\overline{C} + \overline{A}BD$ (köşe grubu) |

**Derste verilen alıştırmalar ve çözümleri:**

| Alıştırma | Çözüm |
| :-- | :-- |
| $\Sigma(1,3,4,5,6,7,9,11,13,15)$ | $D + \overline{A}B$ (8'li grup + 4'lü grup) |
| $\Sigma(1,3,9,11,12,13,14,15)$ | $AB + \overline{B}D$ |
| $\Sigma(2,7,8,10,12,13,14)$ | $A\overline{D} + AB\overline{C} + \overline{A}BCD + \overline{B}C\overline{D}$ |

İkinci alıştırmada hoca bilerek bir tuzak gösterdi. Önce ortadaki $BD$ dörtlüsünü alırsanız, sonra $AB$ ve $\overline{B}D$ dörtlülerini de almak zorunda kalırsınız. $BD$ grubu bu iki grubun içinde kaldığı için gereksizdir. Doğru sonuç iki terimlidir.

Üçüncü alıştırmada 2 ve 10 numaralı mintermler alt satırda yan yana değildir. Ama sağ ve sol kenar komşu olduğu için birlikte $\overline{B}C\overline{D}$ grubunu oluşturur. Bu sorudaki yanlışı bir öğrenci fark etti.

**Ödev:** $F(A,B,C) = \Sigma(0,3,4,6,7)$ fonksiyonunu sadeleştirin.

- Çözüm: $\overline{B}\,\overline{C} + BC + AB$. $AB$ yerine $A\overline{C}$ de alınabilir; ikisi de en kısa çözümdür.

### Ders sonrası notlar

- Hoca Bool cebrinin Claude Shannon tarafından ortaya atıldığını söyledi. Bool cebrini 19. yüzyılda George Boole kurdu (1847, 1854). Shannon 1937-1938'de bu cebri anahtarlama devrelerine uyguladı.
- Altyazıda "Edward Wage" geçiyor. Doğru ad Edward Veitch'tir (Veitch diyagramı, 1952).
- Hoca tekrar kısmında "contradiction" dedi, ama tanımladığı şey ters-karşıttır (contrapositive): $p \to q$ için $\neg q \to \neg p$. Çelişki, her girişte yanlış olan önermedir.
- Hoca XOR için "aklımıza çıkarma gelsin" dedi. Daha doğru ifade: XOR, 2'ye göre (modulo 2) toplamadır. Yarım toplayıcının toplam bitini verir. Girişler aynıysa 0, farklıysa 1'dir.
- Hoca tekrar sırasında "önermelerimiz hiçbir zaman negatif olmuyordu" dedi. Bir önermenin değili de bir önermedir. Kastedilen, temel önermeleri olumlu cümle olarak seçip olumsuzluğu $\neg$ ile göstermek olmalı.
- Altyazıda farklı Bool fonksiyonu sayısı "2 üzeri en" diye geçiyor. Doğrusu $2^{2^n}$'dir. Slayttaki $n=2$ için 16 sonucu doğrudur.
- $(x+y)\overline{z}$ örneğinde hoca bir satırı "X yok, Y yok, Z var" diye okudu. Bu satırda $F = 0$'dır. Doğru satırlar yalnız minterm 2, 4 ve 6'dır (yukarıdaki çözüm).
- Slayttaki çözümde dağılma adımında bir terimde $y$ eksik yazılmış. Hoca bunu derste fark etti ve $\overline{x}y\overline{z}$ olarak düzeltti.
- Hoca "değişmezlik kanunu" adını idempotent kanunu ($x + x = x$) için kullandı. Türkçe kaynaklarda bu kural "tek kuvvet" ya da "eşgüçlülük" diye de geçer. Değişme (commutative) kuralı başka bir kuraldır.
- Dört değişkenli ikinci örnekte ($\Sigma(0,2,4,5,7,8,10)$) videoda köşe grubu $\overline{B}D$ diye okundu. Hoca derste düzeltti: köşelerde $D = 0$ olduğu için doğrusu $\overline{B}\,\overline{D}$'dir. Düzeltmeyi USİS'ten de duyurdu.
- Üçüncü alıştırmanın video çözümünde 2 numaralı minterm tek başına alınmıştı. Doğrusu 2 ve 10'u kenar komşuluğuyla birleştirmektir: $\overline{B}C\overline{D}$. Hoca bu düzeltmeyi de mail ile göndereceğini söyledi.
- Bütün Karnaugh örnekleri ve alıştırmaları, olası bütün asal terim (prime implicant) kombinasyonları denenerek Python ile doğrulandı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
