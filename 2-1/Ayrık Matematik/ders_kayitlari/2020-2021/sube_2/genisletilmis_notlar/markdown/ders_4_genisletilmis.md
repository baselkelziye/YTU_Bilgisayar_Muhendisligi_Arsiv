# Ders 4 Genişletilmiş Notu: Bool Cebri Uygulamaları, NAND/NOR Devreleri ve Kümeler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bool Cebriyle Sadeleştirme: Hatırlatma
- 2. Karnaugh Haritasında Bir Gruplama Hatası
- 3. SOP ve POS Biçimleri
- 4. Dual Alarak SOP'tan POS'a
- 5. Bool Kurallarıyla İki Sadeleştirme Örneği
- 6. Evrensel Kapılar: Yalnız NAND ile Devre
- 7. Yalnız NOR ile Devre: 0'ları Gruplamak
- 8. Önemsiz (Don't Care) Durumlar
- 9. Beş Değişkenli Problem: Haritaya Değişken Yazmak
- 10. Quine-McCluskey Yöntemi
- 11. Matematik Dili: Kümeler
- 12. Küme İşlemleri ve Özellikleri
- 13. Kartezyen Çarpım, Genelleştirilmiş İşlemler ve Bit İşlemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Bool Cebriyle Sadeleştirme: Hatırlatma

Ders, önceki haftanın mantık devreleri konusundaki eksikleri tamamlamakla başladı. Hoca bu bölümdeki örneklerin slaytlarda olmadığını, hem bilgi hem pratik için tahtada çözdüğünü söyledi.

İlk hatırlatma önceki derste geçen kuraldır (ekrandan, 00:20:00):

$$x+\overline{x}y = x+y$$

Bu kural ifadelerin içinde gizli olarak karşımıza çıkar. Ekrandaki örnek:

$$\overline{z}\,(xy+x\overline{y}+\overline{x}y)$$

Parantezin dışında ne olduğu önemli değildir; önce parantezin içi ayrı düşünülür. İlk iki terimde $x$ ortaktır:

$$xy+x\overline{y} = x(y+\overline{y}) = x\cdot 1 = x$$

Geriye $x+\overline{x}y$ kalır, bu da kurala göre $x+y$ olur. Böylece ifade $\overline{z}(x+y)$ olur (ekrandan, 00:30:00). Bu biçimde bırakılabilir ya da parantez dağıtılabilir:

$$\overline{z}(x+y) = x\overline{z}+y\overline{z}$$

Soru SOP biçiminde sonuç isterse ikinci yazım kullanılır.

**Soru:** $x$ parantezi alınırken üç terimin $y$'leri birden alınamaz mıydı? **Cevap:** $x$ parantezini almak için terimde $x$ bulunmalıdır. Üçüncü terimde $x$ değil $\overline{x}$ vardır; bu yüzden $x$ yalnız ilk iki terimde ortaktır.

> **Ders sonrası not:** Hoca 00:21:19'da SOP (sum of products) için "toplamların çarpımı" dedi. Doğrusu SOP çarpımların toplamı, POS (product of sums) toplamların çarpımıdır. Hoca 00:32'den sonra iki biçimi doğru tanımladı.

## 2. Karnaugh Haritasında Bir Gruplama Hatası

Öğrenciler, slaytları hazırlayan hocanın ders videosundaki bir Karnaugh haritası çözümünde gruplama hatası olduğunu söyledi ve soruyu minterm olarak verdi (ekrandan, 00:30:00):

$$F = \sum m(2,7,8,10,12,13,14)$$

En büyük sayı 14 olduğu için dört bit gerekir. Bu tür bir soruda önce 16 satırlık doğruluk tablosu çıkarılabilir; hoca uzun olmasın diye sayıların ikilik karşılıklarını doğrudan haritaya yerleştirdi ($ABCD$ sırasıyla):

| Sayı | $ABCD$ |
|---|---|
| 2 | 0010 |
| 7 | 0111 |
| 8 | 1000 |
| 10 | 1010 |
| 12 | 1100 |
| 13 | 1101 |
| 14 | 1110 |

Haritada satırlar $AB$, sütunlar $CD$ ile etiketlendi; ikisi de $00, 01, 11, 10$ sırasındadır. Bir öğrenci öbür videoda $AB$'nin üstte, $CD$'nin yanda olduğunu söyledi. Hoca bunun hiçbir şeyi değiştirmediğini, hatta $A, C, B$ gibi farklı sıralarla da harita kurulabileceğini, önemli olanın sayıları seçilen sıraya göre doğru hücreye yazmak olduğunu belirtti.

Gruplama adımları:

- 16'lı ve 8'li grup yoktur; dörtlü gruplara bakılır.
- Dörtlü grup: 8, 10, 12, 14 (haritanın iki kenarındaki sütunlar, alt iki satır). $A$ değişmez (1), $B$ değişir, $C$ değişir, $D$ hep 0'dır: $A\overline{D}$.
- 2 ve 10 ikilisi: $A$ değişir, $B=0$, $C=1$, $D=0$: $\overline{B}C\overline{D}$.
- 12 ve 13 ikilisi: $A=1$, $B=1$, $C=0$, $D$ değişir: $AB\overline{C}$.
- 7 hiçbir komşusuyla gruplanamaz, tek başına kalır: $\overline{A}BCD$.

$$F = A\overline{D}+\overline{B}C\overline{D}+AB\overline{C}+\overline{A}BCD$$

Bu sonuç python ile doğruluk tablosu üzerinden denetlendi ve en sade SOP biçimiyle aynıdır. Öğrencinin aktardığına göre videodaki hata, 2 ve 10'un ikili gruplanmayıp ayrı ayrı alınmasıydı. Hoca bunun küçük, gözden kaçabilecek bir hata olduğunu söyledi.

## 3. SOP ve POS Biçimleri

Hoca iki standart biçimi hatırlattı (ekrandan, 00:35:00):

- **SOP (sum of products):** çarpım terimlerinin toplamı. Örnek: $abc+\overline{a}\,\overline{b}c$.
- **POS (product of sums):** toplam terimlerinin çarpımı. Örnek: $(\overline{a}+b+c)(\overline{a}+\overline{c})$.

Mintermler sayısal olarak da yazılır: $\sum m(1,2,4)$ ya da $m_1+m_2+m_4$. Büyük $\Sigma$ toplam, büyük $\Pi$ çarpım sembolüdür. Sayısal POS gösterimine ekrandaki örnek:

$$\prod(5,4,3,6)$$

Burada en büyük sayı 6 olduğu için değişken sayısı 3'tür (3 bit). Bu gösterimden yazılacak ifade, parantez içlerinde toplama, parantezler arasında çarpma olan bir denklem olur.

> **Ek bilgi (derste anlatılmadı):** $\prod M(\dots)$ gösteriminde sayılar fonksiyonun 0 olduğu satırlardır (maxterm). Her maxterm, o satırda 0 veren bir toplam terimidir; örneğin 3 bitte 5 = 101 için maxterm $\overline{a}+b+\overline{c}$'dir.

## 4. Dual Alarak SOP'tan POS'a

Ekrandaki örnek (ekrandan, 00:40:00):

$$f(A,B,C) = A\overline{C}+\overline{A}B+\overline{B}C$$

Hoca soruyu şöyle kurdu: ifadeyi önce SOP'tan POS'a dönüştürün, Bool kurallarıyla sadeleştirin, sonra tekrar diğer biçime çevirin. Bu dönüşüme dual alma dedi. Dual alırken $+$ ile $\cdot$ yer değiştirir; tümleyen işaretleri olduğu gibi kalır. Hoca "tersini değil, dualini aldık" diye vurguladı:

$$(A+\overline{C})(\overline{A}+B)(\overline{B}+C)$$

Önce ilk iki parantez açılır, sonra üçüncüyle çarpılır:

$$(A\overline{A}+AB+\overline{A}\,\overline{C}+B\overline{C})(\overline{B}+C)$$

Bir değişkenle tümleyeninin çarpımı 0'dır ($A\overline{A}=0$, $B\overline{B}=0$, $C\overline{C}=0$). Bunlar atılınca geriye

$$ABC+\overline{A}\,\overline{B}\,\overline{C}$$

kalır. Parantezler açıldığı için ifade doğal olarak SOP biçimine dönmüştür. Bunun tekrar duali alınınca:

$$(A+B+C)(\overline{A}+\overline{B}+\overline{C})$$

Hoca son ifadenin devresini çizdi (ekrandan, 00:45:00): $A$, $B$, $C$ bir üç girişli kapıya, tümleyenleri NOT kapılarından geçip ikinci bir üç girişli kapıya girer, iki çıkış son bir kapıda birleşir. SOP biçimine göre çizimde AND'ler ve bir OR, POS biçimine göre çizimde OR'lar ve bir AND kullanılır. Hoca kabloların kesiştiği yerlerde kısa devre kaygısıyla özel çizime gerek olmadığını, dokunmadıklarının kabul edildiğini söyledi. İki girişli kapı şartı konursa üç girişli bir kapı iki tane iki girişli kapıyla kurulur.

**Soru:** SOP'tan POS'a geçerken değil (tümleyen) alınmıyor mu? **Cevap:** De Morgan ile ifadenin değili alınırsa, SOP biçimindeki bir ifadenin değili POS biçimine geçer, ama bu artık başka bir fonksiyondur. Hoca dersteki geçişin dual ile yapıldığını söyledi ve iki şeyin farklı olduğunu doğruluk tablosuyla göstermeyi önerdi.

> **Ders sonrası not:** Bir ifadenin duali genelde kendisine eşit değildir. Örnekte $f$ yalnız 000 ve 111 satırlarında 0'dır; ara sonuç $ABC+\overline{A}\,\overline{B}\,\overline{C}$ ise yalnız bu iki satırda 1'dir. Yani ara sonuç $f$ değil, $f$'nin dualidir (bu örnekte $\overline{f}$ ile aynıdır). Dualin duali yeniden $f$'yi verdiği için son sonuç $(A+B+C)(\overline{A}+\overline{B}+\overline{C}) = f$ doğrudur. Bu, python ile sekiz satırın hepsinde denetlendi.

### 4.1 Doğruluk tablosuyla dual karşılaştırması

Hoca aynı noktayı ikinci bir ifadeyle gösterdi (ekrandan, 00:50:00):

$$(A+B)(A+C) \xrightarrow{\text{dual}} AB+AC$$

| $A$ | $B$ | $C$ | $(A+B)(A+C)$ | $AB+AC$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 |

İlk sütun $A$ 1 iken hep 1'dir; $A=0$ iken $B$ ile $C$'nin ikisi de 1 olmalıdır. İkinci sütun ancak $A=1$ ve $B$, $C$'den en az biri 1 ise 1'dir. Hoca tabloyu doldururken bir an karıştırdı, sonra "dualde doğrudan mantıksal denklik yapamayız" dedi ve iki sütun arasındaki simetriye dikkat çekti. Bir öğrencinin uyarısıyla ilk ifadenin POS, ikincisinin SOP olduğunu düzeltti.

Bu dönüşümlerin kullanıldığı yer devre optimizasyonudur: bir problemi çözen mantık devresi en az elemanla kurulmak istenir. AND ile NOT'u tek kapıda birleştiren NAND, OR ile NOT'u birleştiren NOR gibi kapılar kullanılabilirse devre küçülür, maliyet düşer.

## 5. Bool Kurallarıyla İki Sadeleştirme Örneği

### 5.1 $(A+B)(A+C) = A+BC$ ispatı

Ekrandaki ifade (ekrandan, 00:45:00) açılınca:

$$AA+AC+AB+BC$$

$A$ parantezi almadan önce $AA=A$ yazılmalıdır, yoksa işin içinden çıkılmaz. Sonra:

$$A(1+C+B)+BC = A\cdot 1+BC = A+BC$$

1 ile toplanan her şey 1'dir. Hoca aynı terimin iki kez geçtiği durumlara dikkat çekti: örneğin parantezlerden $AB$ ve $AB$ gelirse $AB+AB=AB$ olur ve ona göre parantez alınır.

### 5.2 Tümleyenli karmaşık ifade

Ekrandaki ifade (ekrandan, 00:55:00):

$$\overline{\overline{A}(B+\overline{C})}\cdot(A+\overline{B}+\overline{C})\cdot\overline{\overline{A}\,\overline{B}\,\overline{C}}$$

Hoca bunun sınavda "SOP'a dönüştürün" gibi bir yönlendirme olmadan, yalnız Bool cebri kurallarıyla çözülecek türden bir soru olduğunu söyledi.

**Adım 1, tümleyenleri kaldırma (De Morgan):**

- $\overline{\overline{A}(B+\overline{C})} = A+\overline{(B+\overline{C})} = A+\overline{B}C$
- $\overline{\overline{A}\,\overline{B}\,\overline{C}} = A+B+C$

İfade: $(A+\overline{B}C)(A+\overline{B}+\overline{C})(A+B+C)$.

**Adım 2, ilk iki parantez (ekrandan, 01:00:00):**

$$AA+A\overline{B}+A\overline{C}+\overline{B}CA+\overline{B}C\overline{B}+\overline{B}C\overline{C}$$

$\overline{B}C\overline{C}=0$ ve $\overline{B}C\overline{B}=\overline{B}C$'dir. $A$ ortak paranteze alınınca:

$$A(1+\overline{B}+\overline{C}+\overline{B}C)+\overline{B}C = A+\overline{B}C$$

**Adım 3, üçüncü parantezle:**

$$(A+\overline{B}C)(A+B+C) = AA+AB+AC+A\overline{B}C+B\overline{B}C+\overline{B}CC$$

$B\overline{B}C=0$, $\overline{B}CC=\overline{B}C$; $A$ yine ortak paranteze alınır:

$$A(1+B+C+\overline{B}C)+\overline{B}C = A+\overline{B}C$$

**Sonuç:** $A+\overline{B}C$ (python ile doğrulandı).

**Soru:** $\overline{B}\,\overline{B}C$ terimi nasıl gitti? **Cevap:** Hoca o terimi yanlışlıkla sildiğini, gitmemesi gerektiğini söyledi; $\overline{B}\,\overline{B}C=\overline{B}C$ olarak kalır. Silinmesi gereken $\overline{B}C\overline{C}$ terimidir. Hoca De Morgan kuralını önceki derste anlattığı için tekrar etmedi ve bu tür örnekleri bol çözmeyi önerdi.

## 6. Evrensel Kapılar: Yalnız NAND ile Devre

NAND, AND ile NOT'un; NOR, OR ile NOT'un; XNOR, XOR ile NOT'un birleşik halidir. NAND ve NOR evrensel kapılardır ve maliyeti azaltırlar. Karnaugh haritasından çıkan bir ifade için "devreyi yalnız NAND ile" ya da "yalnız NOR ile" çizin denebilir. Hoca bunun önemli bir kural olduğunu söyledi.

### 6.1 Örnek: 3'ten küçük ya da 12'den büyük

Dört bitlik bir sayı giriliyor; sayı 3'ten küçük ya da 12'den büyükse çıkış 1, değilse 0 (ekrandan, 01:10:00). Eşitlik olmadığı için 3 ve 12 dahil değildir. Çıkışın 1 olduğu sayılar:

$$0,1,2,13,14,15 \quad (0000, 0001, 0010, 1101, 1110, 1111)$$

> **Hocanın vurgusu:** Bu derste en sık yapılan hata haritaya yanlış hücreye 0 ya da 1 yazmaktır; satır ve sütun kodlarına çok dikkat edin.

Haritada dörtlü grup çıkmaz. Dört ikili grup alınır:

- 13 ve 15: $A$, $B$ değişmez, $C$ değişir, $D=1$: $ABD$
- 14 ve 15: $A$, $B$, $C$ değişmez, $D$ değişir: $ABC$
- 0 ve 1: $\overline{A}\,\overline{B}\,\overline{C}$
- 0 ve 2 (karşılıklı kenarlar): $\overline{A}\,\overline{B}\,\overline{D}$

$$f = ABD+ABC+\overline{A}\,\overline{B}\,\overline{C}+\overline{A}\,\overline{B}\,\overline{D}$$

Bu haliyle devre dört tane üç girişli AND ve bir dört girişli OR ister. Hoca önce üç girişli OR dedi, sonra dört terim olduğu için OR'un dört girişli olması gerektiğini düzeltti.

### 6.2 NAND dönüşümü

Bir ifadenin iki kez tümleyeni kendisine eşittir. $f=\overline{\overline{f}}$ yazılıp içteki tümleyen De Morgan ile dağıtılınca (ekrandan, 01:15:00):

$$f = \overline{\overline{ABD}\cdot\overline{ABC}\cdot\overline{\overline{A}\,\overline{B}\,\overline{C}}\cdot\overline{\overline{A}\,\overline{B}\,\overline{D}}}$$

Her $\overline{ABD}$ biçimli terim bir üç girişli NAND kapısının çıkışıdır. Bu dört çıkış son bir dört girişli NAND kapısına girer. Toplam beş NAND kapısı kullanılır. Hoca işin elektronik tarafını bilmediğini, ama donanımcı hocaların bu yapının daha optimize olduğunu söylediğini aktardı.

**Soru:** Bu örnekte NOT kapıları da gerekiyor; o zaman yalnız NAND kullanmış olmuyor muyuz? **Cevap:** Terimleri oluşturan ve toplayan kapılar NAND'dir. Terimlerin girişlerinde $\overline{A}$, $\overline{B}$ gibi tümleyenler için elbette NOT kullanılır; gerekiyorsa kullanılır.

> **Ek bilgi (derste anlatılmadı):** Girişlerdeki NOT kapıları da NAND ile kurulabilir: bir NAND'in iki girişine aynı sinyal verilirse $\overline{AA}=\overline{A}$ elde edilir. Bu yüzden NAND tek başına her mantık devresini kurabilir.

## 7. Yalnız NOR ile Devre: 0'ları Gruplamak

Aradan sonra aynı fonksiyon yalnız NOR ile çizildi (ekrandan, 01:45:00). Hoca 1'leri gruplayıp dual ya da tümleyen almanın NOR'lu bir biçim vermediğini söyledi; NOR için ifadenin parantez içleri toplam, parantezler arası da (tümleyenden sonra) toplam olmalıdır. Bunun yolu 0'ları gruplamaktır.

Haritada 0'lar 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 hücreleridir. Gruplar ve verdikleri toplam terimleri (0 grubunda değişmeyen değişken 0 ise kendisi, 1 ise tümleyeni yazılır):

- 3 ve 7 ($\overline{A}CD$ hücreleri): $A+\overline{C}+\overline{D}$
- 8 ve 12 ($A\overline{C}\,\overline{D}$ hücreleri): $\overline{A}+C+D$
- 8, 9, 10, 11 ($A\overline{B}$ satırı): $\overline{A}+B$
- 4, 5, 6, 7 ($\overline{A}B$ satırı): $A+\overline{B}$

$$f = (A+\overline{C}+\overline{D})(\overline{A}+C+D)(\overline{A}+B)(A+\overline{B})$$

Hoca bunun bir dönüşüm değil, 0'ları gruplayınca doğrudan elde edilen POS benzeri bir yazım olduğunu vurguladı. İki kez tümleyen alınıp De Morgan uygulanınca:

$$f = \overline{\overline{(A+\overline{C}+\overline{D})}+\overline{(\overline{A}+C+D)}+\overline{(\overline{A}+B)}+\overline{(A+\overline{B})}}$$

Bütün operatörler artık toplamdır. Her parantez bir NOR kapısı, dıştaki işlem de dört girişli bir NOR kapısıdır. Ekrandaki çizimde iki NOR çıkışının bir NOR'a girdiği yapı gösterildi; terim sayısı dört olduğu için son kapı dört girişlidir. İfade python ile 16 satırda denetlendi.

> **Hocanın vurgusu:** Yalnız NAND için 1'ler, yalnız NOR için 0'lar gruplanır; bu ileride lazım olur.

## 8. Önemsiz (Don't Care) Durumlar

Bazı problemlerde bir giriş durumu için çıkışın 1 ya da 0 olması önemli değildir. Bu durum doğruluk tablosunda ve haritada $X$ ile işaretlenir. Gruplama yapılırken bir $X$ grubu büyütmeye, yani terim sayısını azaltmaya yarıyorsa 1 sayılıp gruba katılır; yaramıyorsa gruba alınmaz, 0 sayılabilir.

Örnek olarak önceki fonksiyon kullanıldı (ekrandan, 01:50:00):

- Yalnız 3 (0011) önemsiz olsun. $\overline{A}\,\overline{B}$ satırında 0, 1, 2 hücrelerindeki 1'ler, 3'teki $X$ ile birlikte dörtlü grup olur: $\overline{A}\,\overline{B}$. $AB$ satırında 13-15 ve 14-15 ikilileri kalır:

$$f = \overline{A}\,\overline{B}+ABD+ABC$$

- 3 ve 12 önemsiz olsaydı (sınır değerlerin önemsiz olduğu söylenseydi), $AB$ satırı da dörtlü grup olurdu:

$$f = \overline{A}\,\overline{B}+AB$$

Her iki sonuç python ile denetlendi.

**Soru:** Önemsiz durumlar soruda veriliyor mu, yoksa biz mi çıkarıyoruz? **Cevap:** Problem metninden çıkar; örneğin "3 ve 12 önemsiz" gibi "olsa da olur, olmasa da olur" denen durumlar $X$ olarak işaretlenir.

## 9. Beş Değişkenli Problem: Haritaya Değişken Yazmak

### 9.1 İki, üç ve dört değişken

İki değişkenli haritada en çok dörtlü, üç değişkenlide en çok sekizli, dört değişkenlide on altılı grup çıkar. Üç değişkenli kısa örnekte bir dörtlü grup $B$, bir ikili grup $\overline{A}C$ benzeri bir terim verdi; mantık hep aynıdır. Hoca kendi notasyonunun slayttakinden farklı olabileceğini, önemli olanın mantığı öğrenmek olduğunu söyledi. Beş değişkende iki dört değişkenli harita yan yana çizilebilir, ama hoca başka bir teknik gösterdi. Yedi değişkenli harita çizmek pratik değildir.

### 9.2 Oylama örneği

Beş kişinin oy ağırlıkları (ekrandan, 01:55:00):

| Kişi | Ağırlık |
|---|---|
| $A$ | 30 |
| $B$ | 25 |
| $C$ | 25 |
| $D$ | 10 |
| $E$ | 10 |

Evet oylarının ağırlık toplamı $\geq 65$ ise çıkış 1 olacaktır. 32 satırlık tabloda örneğin $A=0$ iken $B+C+D=60$ olduğu için $01110$ satırı 0, $01111$ satırı ($70$) 1'dir.

### 9.3 $E$'yi hücre değeri yapmak

Tablo, $A$, $B$, $C$, $D$ aynı ve yalnız $E$'si farklı satır çiftlerine ayrılır. Her çift için:

- $E=0$'da 0, $E=1$'de 1 ise sonucu $E$ belirler, hücreye $E$ yazılır.
- İkisinde de 1 ise hücreye 1 yazılır.
- İkisinde de 0 ise 0 yazılır.
- $E=0$'da 1, $E=1$'de 0 olsaydı hücreye $\overline{E}$ yazılırdı.

**Soru:** Yalnız bir bitin değiştiği ikililere mi bakıyoruz? **Cevap:** Sonucun 1 olduğu satırın, diğer bütün bitleri aynı olan eşine (genelde bir üst ya da bir alt satır) bakılır; ikisini ayıran tek şey $E$'dir.

Sonuçta dört değişkenli haritaya şunlar yazıldı (ekrandan, 02:05:00):

| $AB \backslash CD$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 0 | 0 | 0 | 0 |
| 01 | 0 | 0 | $E$ | 0 |
| 11 | $E$ | 1 | 1 | 1 |
| 10 | 0 | 0 | 1 | $E$ |

Hocanın yorumu: hücredeki 1, $E+\overline{E}$ demektir; yani 1'li hücre $E$'li gruplara da katılabilir. Hoca önce 1'leri $E$ hücreleriyle birlikte dörtlü gruplayarak $1\cdot AB$ ve $1\cdot AC$ (bir ara $1\cdot ACD$) terimlerini, sonra $E$'leri tek tek gruplayarak $E\cdot AB\overline{C}\,\overline{D}$, $E\cdot\overline{A}BCD$, $E\cdot A\overline{B}C\overline{D}$ terimlerini yazdı. Ardından "önce $E$'leri kendi başına gruplamak gerekir" dedi, iki dörtlünün aynı anda alınıp alınamayacağından emin olmadığını ve kuralı sonraki derste kontrol edeceğini söyledi.

> **Ders sonrası not:** Hocanın bulduğu $AB+AC+\dots$ ifadesi yanlıştır: $AB$ dörtlüsü $E$ yazılı $1100$ hücresini, $AC$ dörtlüsü $E$ yazılı $1010$ hücresini kapsadığı için ifade $11000$ ve $10100$ satırlarında (ağırlık toplamı 55) yanlışlıkla 1 verir. Haritaya değişken yazma yönteminde 1'ler gruplanırken $E$ hücreleri 0 sayılır; $E$'ler gruplanırken ise 1 hücreleri önemsiz ($X$) gibi kullanılabilir ve bu gruplar $E$ ile çarpılır. Buna göre:
>
> - 1'lerin grupları: $ABD$ (1101, 1111), $ABC$ (1111, 1110), $ACD$ (1011, 1111)
> - $E$'lerin grupları (1'ler önemsiz): $AB\cdot E$, $AC\cdot E$, $BCD\cdot E$
>
> $$f = ABC+ABD+ACD+ABE+ACE+BCDE$$
>
> Bu ifade 32 satırın hepsinde $\geq 65$ koşuluyla aynı sonucu verir ve en sade SOP biçimidir (python ile denetlendi).

## 10. Quine-McCluskey Yöntemi

Gerçek mantık devrelerinde değişken sayısı 10 gibi büyük olabilir. Karnaugh haritaları 5-6 değişkene kadar sorunsuz kullanılır, daha fazlasında işin içinden çıkılamaz. Ya Bool kurallarıyla elle çözülür ya da algoritmik bir yöntem kullanılır. Quine-McCluskey yöntemi bu ikinci yoldur. Hoca bir üniversitenin ders sayfasındaki slaytlar üzerinden yöntemi anlattı.

Örnek (ekrandan, 02:10:00): mintermler 0, 3, 5, 6, 7, 10, 12, 13; önemsizler 2, 9, 15; değişkenler $W, X, Y, Z$.

**Adım 1, 1 sayısına göre gruplama.** Terimler içerdikleri 1 sayısına göre (0'dan 4'e) gruplanır: 0 tane 1 içeren 0; 1 tane içeren 2; 2 tane içeren 3, 5, 6, 9, 10, 12; 3 tane içeren 7, 13; 4 tane içeren 15.

**Adım 2, tek bit farkla birleştirme.** Yalnız komşu gruplar (0 ile 1, 1 ile 2, ...) karşılaştırılır; tek bit farklı olan çiftler birleştirilir, değişen bit "d" ile gösterilir (ekrandan, 02:15:00):

| Grup | Çift | $WXYZ$ |
|---|---|---|
| G0' | 0, 2 | 0 0 d 0 |
| G1' | 2, 3 | 0 0 1 d |
| G1' | 2, 6 | 0 d 1 0 |
| G1' | 2, 10 | d 0 1 0 |
| G2' | 3, 7 | 0 d 1 1 |
| G2' | 5, 7 | 0 1 d 1 |
| G2' | 6, 7 | 0 1 1 d |
| G2' | 5, 13 | d 1 0 1 |
| G2' | 9, 13 | 1 d 0 1 |
| G2' | 12, 13 | 1 1 0 d |
| G3' | 7, 15 | d 1 1 1 |
| G3' | 13, 15 | 1 1 d 1 |

**Adım 3, tekrar.** Aynı işlem yeni gruplara uygulanır. 2, 3, 6, 7 ($0\,d\,1\,d$) ve 5, 7, 13, 15 ($d\,1\,d\,1$) dörtlüleri çıkar; her biri iki farklı yoldan geldiği için iki kez yazılır, tekrarlar teke indirilir. Birleşmeye katılmayan çiftler (0-2, 2-10, 9-13, 12-13) olduğu gibi alınır. Artık birleşme mümkün değildir.

**Adım 4, asal çarpanlar.** Kalan terimler değişkenlerle yazılır: $\overline{W}\,\overline{X}\,\overline{Z}$ (0, 2), $\overline{X}Y\overline{Z}$ (2, 10), $W\overline{Y}Z$ (9, 13), $WX\overline{Y}$ (12, 13), $\overline{W}Y$ (2, 3, 6, 7), $XZ$ (5, 7, 13, 15).

**Adım 5, seçim.** Önemsizler kapsanmak zorunda değildir. Bütün mintermleri kapsayan en az sayıda terim seçilir. $XZ$ tek seferde 5, 7, 13'ü kapsar; $WX\overline{Y}$ 12'yi, $\overline{X}Y\overline{Z}$ 10'u, $\overline{W}Y$ 3 ve 6'yı, $\overline{W}\,\overline{X}\,\overline{Z}$ 0'ı ekler. $W\overline{Y}Z$'ye gerek kalmaz:

$$f = XZ+WX\overline{Y}+\overline{X}Y\overline{Z}+\overline{W}Y+\overline{W}\,\overline{X}\,\overline{Z}$$

Sonuç python ile denetlendi; beş terimlik bu seçim en az terimli çözümdür. Hoca yöntemin 7-8 değişkene uyarlanabildiğini söyledi. Bir ders sayfasının içeriğini gösterip donanım çalışacaklar için bu konuların ve donanım tanımlama dillerinin (HDL) önemli olduğunu ekledi.

> **Hocanın vurgusu:** Karnaugh haritası 3-4 değişkenli problemler için uygundur; daha çok değişkenli bir ifadenin en sade hali Karnaugh kullanmadan, yalnız Bool kurallarıyla da bulunabilir. Ağırlıklı ortalaması belirli bir eşiği geçenleri bulan devre gibi sözel problemler de aynı yöntemle çözülür.

## 11. Matematik Dili: Kümeler

Dersin ikinci yarısında "Bölüm 4 Matematik Dili" slaytlarına geçildi (ekrandan, 02:25:00). Algoritmaya giden yolda kümeler, kartezyen çarpım, bağıntılar, bağıntıların özel hali olan fonksiyonlar ve işlemler vardır; algoritma ileride "sınırlı, belirli komutlar kümesi" diye tanımlanacaktır.

Hoca, eskiden bu derste anlatılan cebirsel yapıların (halka, grup, abelyen grup) bilgisayar bilimiyle ilgisi azaldığı için çıkarıldığını söyledi ve kısaca hatırlattı:

- Kapalılık ve birleşme varsa yarı grup.
- Ayrıca birim eleman ve ters eleman varsa grup.
- Ayrıca değişme varsa abelyen grup.

Toplama genelde abelyen gruptur. Çarpmada her sayının her modda tersi yoktur; örneğin mod 26'da 2'nin çarpmaya göre tersi yoktur. Hoca bunu kriptoloji örneklerinde göreceklerini söyledi.

> **Ek bilgi (derste anlatılmadı):** Mod $n$'de $a$'nın çarpmaya göre tersi ancak $\gcd(a,n)=1$ ise vardır. $\gcd(2,26)=2$ olduğu için 2'nin tersi yoktur; mod 26'da tersi olan sayılar 26 ile aralarında asal olan 12 sayıdır.

### 11.1 Küme, gösterimler ve özel kümeler

Küme, ayrık nesnelerden (elemanlardan) oluşan topluluktur. Üç gösterim vardır: Venn şeması, liste ve tanım (kural) gösterimi. Algoritmik yaklaşım için en önemlisi tanım gösterimidir: "$x$ öyle ki" diye okunur; bir kural ve bu kuralın kapsamı yazılır (örneğin elemanlar $2k+1$ biçiminde, $k$ belirli bir aralıkta).

- **Sonlu (finite) küme:** eleman sayısı sonludur, belli bir bellekte saklanabilir. **Sonsuz (infinite) küme:** eleman sayısı sonsuzdur.
- **Boş küme:** $\emptyset$ ya da $\{\}$ ile gösterilir; null set, void set de denir. $\{\emptyset\}$ boş küme değildir, içinde bir eleman olan kümedir.
- **Evrensel küme:** ilgilenilen problemin tanım alanındaki bütün elemanları içeren kümedir; örneğin bir sınıftaki öğrenci numaraları. Evrensel küme sonsuz olmak zorunda değildir; probleme göre sonlu da olabilir.

### 11.2 Kardinalite

Kümenin eleman sayısı $|S|$ ile gösterilir. Sonsuz kümelerde sayılabilir (doğal sayılar, tam sayılar) ve sayılamaz (reel sayılar) durumlar ayrı incelenir. Derste slayttaki kümelerin kardinalitesi soruldu: tekrar eden elemanlar bir kez sayıldığı için bir kümenin kardinalitesi 1, boş kümeninki 0, iç içe kümeler içeren bir kümede her farklı eleman bir sayıldığı için 3 bulundu. <!-- BELİRSİZ: Kardinalitesi sorulan kümeler karede görünmüyor; altyazıdan yalnız cevaplar (1, 0, 3) çıkıyor. -->

### 11.3 Alt küme

Hoca alt kümeyi yalnız matematik kavramı olarak düşünmemeyi önerdi: bir problem alanının belli bir parçasıyla ilgilenmek alt küme almaktır. Örneğin 1000 verinin %80'iyle (800 veri) eğitim kümesi kurmak bir alt küme seçmektir.

Slayttaki tanımlar (ekrandan, 02:30:00):

- $X$'in bütün elemanları $Y$'de ise $X\subseteq Y$.
- Eşitlik: $X=Y$ ancak $X\subseteq Y$ ve $Y\subseteq X$ ise.
- $X\subseteq Y$ ama $Y\not\subseteq X$ ise $X$, $Y$'nin öz alt kümesidir (proper subset).
- Gözlem: $\emptyset$ her kümenin alt kümesidir.

Niceleyicilerle: $A\subseteq B \iff \forall x\,(x\in A \rightarrow x\in B)$. Hoca başka bir sözel yorum istedi ve "B'nin elemanlarının bazıları A'nın da elemanıdır" yorumunu varoluş niceleyiciyle yazdı: $\exists x\,(x\in B \wedge x\in A)$. Bir Venn şemasında evrensel küme içinde $B$, $B$ içinde $A$ gösterildi.

> **Ders sonrası not:** "$\exists x\,(x\in B \wedge x\in A)$" yalnız $A$ ile $B$'nin ortak elemanı olduğunu söyler, $A\subseteq B$ ile denk değildir. Alt küme tanımı evrensel niceleyicili biçimdir. Hoca bu ifadeyi alt kümenin denk bir yorumu olarak sundu; büyük olasılıkla ek bir gözlem olarak kastetmiştir.

### 11.4 Kuvvet kümesi

$S$'nin bütün alt kümelerinin kümesine kuvvet kümesi denir; $P(S)$ ya da $2^S$ ile gösterilir (ekrandan, 02:35:00):

$$2^S=\{x : x\subseteq S\}$$

- $S=\{a\}$ ise $2^S=\{\emptyset,\{a\}\}$
- $S=\{a,b\}$ ise $2^S=\{\emptyset,\{a\},\{b\},\{a,b\}\}$
- $S=\emptyset$ ise $2^S=\{\emptyset\}$
- $S=\{\emptyset,\{\emptyset\}\}$ ise $2^S=\{\emptyset,\{\emptyset\},\{\{\emptyset\}\},\{\emptyset,\{\emptyset\}\}\}$

$S$ sonlu ve $|S|=n$ ise $|2^S|=2^n$. Üç elemanlı bir kümenin 8 alt kümesi vardır. Venn şeması, birleşim, kesişim, fark, simetrik fark ve tümleyen gibi kavramları liste yöntemine göre daha kolay görmeyi sağlar.

## 12. Küme İşlemleri ve Özellikleri

### 12.1 Temel işlemler

- **Birleşim:** $X$'te ya da $Y$'de (ya da ikisinde) olan elemanlardan oluşan yeni küme. Mantıktaki OR'a, Bool cebrindeki toplamaya karşılık gelir. Slayttaki örnekte iki kişi adı kümesi birleştirildi; ortak ad bir kez yazıldı.
- **Kesişim (intersection):** iki kümede de olan elemanlar. AND'e, Bool çarpımına karşılık gelir.
- **Ayrık kümeler (disjoint):** kesişimi boş küme olan kümeler. Slayttaki örnekte bir kümede bulunmayan bir elemanın başka kümeyle kesişimi yoktur.
- **Tümleyen:** evrensel küme içinde $X$'in dışındaki bütün elemanlar. Örneğin $X$ uzun boylular ise tümleyeni uzun boylu olmayanlardır. $\overline{\emptyset}=U$, $\overline{U}=\emptyset$.
- **Fark:** $X-Y=\{z : z\in X \wedge z\notin Y\}$. "X ama Y değil" (but) diye okunur; "but" mantıkta AND'e dönüşür. Göreli tümleyen (relative complement) de denir. $\overline{A}=U-A$ biçiminde de yazılır.
- **Simetrik fark** (ekrandan, 02:40:00):

$$X\oplus Y=(X-Y)\cup(Y-X)=\{z : (z\in X \wedge z\notin Y)\vee(z\in Y \wedge z\notin X)\}$$

Simetrik fark XOR'un kendisidir: girişler farklıysa 1, aynıysa 0. Hoca XOR'un Türkçedeki karşılığının "ya da", OR'un "veya" olduğunu hatırlattı. İngilizcedeki "either ... or" kalıbı "ya o ya o" anlamını taşır; "exclusive or" adı da buradan gelir.

### 12.2 Özellikler

Küme işlemleri programlamadaki operatörler gibidir; operatör önceliği ve birleşme özelliği gibi kavramlar burada da geçerlidir.

- **Birleşme (associativity):** ifadedeki operatörler aynıysa sıranın önemi yoktur.
- **Değişme:** $A\cup B=B\cup A$, $A\cap B=B\cap A$.
- **Dağılma:** farklı operatörler ortak paranteze alınabilir ya da dağıtılabilir; çift yönlüdür, hangisi problemi kolaylaştırıyorsa o kullanılır.
- **Birim (identity):** $A\cap U=A$, $A\cup\emptyset=A$. Mantıkta $A\cdot 1=A$, $A+0=A$.
- **Tümleyen:** $A\cup\overline{A}=U$, $A\cap\overline{A}=\emptyset$. Mantıkta $A+\overline{A}=1$, $A\overline{A}=0$.
- **Eş kuvvetlilik (idempotent)** (ekrandan, 02:45:00): $A\cup A=A$, $A\cap A=A$.
- **Sınır (bound) kanunları:** $A\cup U=U$, $A\cap\emptyset=\emptyset$. Mantıkta $A+1=1$, $A\cdot 0=0$; yutan eleman gibi.
- **İçine alma (absorption):** $A\cup(A\cap B)=A$, $A\cap(A\cup B)=A$. Mantıktaki karşılığı $A+AB=A(1+B)=A$ ve $A(A+B)=AA+AB=A+AB=A$.
- **Gerektirme (involution):** $\overline{\overline{A}}=A$.
- **0/1 kanunu:** $\overline{\emptyset}=U$, $\overline{U}=\emptyset$.
- **De Morgan:** $\overline{A\cup B}=\overline{A}\cap\overline{B}$, $\overline{A\cap B}=\overline{A}\cup\overline{B}$. Aradaki operatör değişir, terimlerin tümleyeni alınır.

> **Ders sonrası not:** Hoca 0/1 kanununu anlatırken "sıfırın tümleyeni sonsuzdur" diyerek limitteki $1/0$ ve $1/\infty$ ilişkisine benzetti. Kümelerde bu kanunun doğru ifadesi $\overline{\emptyset}=U$ ve $\overline{U}=\emptyset$'dir; evrensel küme sonlu da olabileceği için "sonsuz" denmesi yanlış anlaşılmaya açıktır.

## 13. Kartezyen Çarpım, Genelleştirilmiş İşlemler ve Bit İşlemleri

### 13.1 Kartezyen çarpım

$$A\times B=\{(a,b) : a\in A \wedge b\in B\}$$

Elemanlar sıralı ikililerdir ve parantez içinde yazılır; sıralı üçlüler, dörtlüler de tanımlanabilir. Kartezyen çarpımın her elemanı yeni bir nesne gibi düşünülmelidir. Örneğin $\{2,3,4\}\times\{1,2\}$ çarpımında $(3,1)$ bir elemandır ve $(1,3)$ ile aynı değildir; bu yüzden genelde $A\times B\neq B\times A$'dır.

$$|A\times B|=|A|\cdot|B|$$

Slayttaki örnekte üç elemanlı bir ad kümesi ile iki elemanlı bir ad kümesinin çarpımında $3\cdot 2=6$ farklı sıralı ikili vardır.

### 13.2 Genelleştirilmiş birleşim ve kesişim

$n$ kümenin birleşimi ve kesişimi büyük işlem sembolleriyle kısaltılır (ekrandan, 02:50:00):

$$A_1\cup A_2\cup\dots\cup A_n=\Sigma_{i=1}^{n}A_i,\qquad A_1\cap A_2\cap\dots\cap A_n=\Pi_{i=1}^{n}A_i$$

Hoca bu kullanımın sonlu toplamlar ya da serilerle karıştırılmaması gerektiğini söyledi.

### 13.3 İçerme-dışlama

$$s(A\cup B)=s(A)+s(B)-s(A\cap B)$$

Slayttaki örnekte 217 öğrencilik bir bölümde iki dersi alanların ve ikisini birden alanların sayısı verilip hiçbirini almayanlar soruldu; $217-|A\cup B|$ hesaplandı. <!-- BELİRSİZ: Örneğin ara sayıları karede görünmüyor; altyazıda sonuç "onç" diye geçiyor, büyük olasılıkla 13. -->

Üç küme için $|A|+|B|+|C|$ toplanır; iki kez sayılan ikili kesişimler çıkarılır; bu sırada üç kez eklenip üç kez çıkarılan üçlü kesişim geri eklenir:

$$|A\cup B\cup C|=|A|+|B|+|C|-|A\cap B|-|A\cap C|-|B\cap C|+|A\cap B\cap C|$$

Hoca aynı mantığın daha çok kümeye uygulanabileceğini, ama kuralların uzadığını söyledi.

### 13.4 Bit düzeyi işlemler ve XOR ile şifreleme

Kesişim ve birleşim bit düzeyinde AND ve OR olarak kullanılır; dizgilerde (string) de uygulanır. Bit düzeyi OR'da iki bitten en az biri 1 ise sonuç 1'dir; AND'de ikisi de 1 ise 1'dir. İki sayının karşılıklı bitleri işleme sokulur.

Kriptografide bir anahtar (key) ve bir mesaj vardır. Günümüzde şifrelemede çoğunlukla XOR kullanılır: anahtar ve mesajın karşılıklı bitleri aynıysa 0, farklıysa 1 yazılır. Sonuç şifreli metindir (encoded ya da ciphered text). <!-- BELİRSİZ: Derste kullanılan anahtar ve mesaj bitleri karede görünmüyor, altyazıdan kesin çıkmıyor. -->

> **Ek bilgi (derste anlatılmadı):** XOR'un $(m\oplus k)\oplus k=m$ özelliği sayesinde şifreli metin aynı anahtarla tekrar XOR'lanınca mesaj geri elde edilir.

Ders, dizi ve seriler konusunun sonraki derste anlatılacağı söylenerek bitirildi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): $\overline{z}\,(xy+x\overline{y}+\overline{x}y)$ ifadesini sadeleştirin, SOP biçiminde yazın.

> **Çözüm:** $xy+x\overline{y}=x$, $x+\overline{x}y=x+y$; sonuç $\overline{z}(x+y)=x\overline{z}+y\overline{z}$.

**Soru 2** (ekrandan, 00:30:00): $F=\sum m(2,7,8,10,12,13,14)$ fonksiyonunu Karnaugh haritasıyla sadeleştirin.

> **Çözüm:** $F=A\overline{D}+\overline{B}C\overline{D}+AB\overline{C}+\overline{A}BCD$ (Bölüm 2).

**Soru 3** (ekrandan, 00:40:00): $f(A,B,C)=A\overline{C}+\overline{A}B+\overline{B}C$ ifadesinin dualini alın, Bool kurallarıyla sadeleştirin ve tekrar dualini alarak diğer biçime dönüştürün.

> **Çözüm:** Dual $(A+\overline{C})(\overline{A}+B)(\overline{B}+C)=ABC+\overline{A}\,\overline{B}\,\overline{C}$; bunun duali $(A+B+C)(\overline{A}+\overline{B}+\overline{C})$, bu da $f$'ye eşittir (Bölüm 4).

**Soru 4** (ekrandan, 00:45:00): $(A+B)(A+C)=A+BC$ olduğunu gösterin.

> **Çözüm:** $AA+AC+AB+BC=A(1+C+B)+BC=A+BC$.

**Soru 5** (ekrandan, 00:55:00): $\overline{\overline{A}(B+\overline{C})}\cdot(A+\overline{B}+\overline{C})\cdot\overline{\overline{A}\,\overline{B}\,\overline{C}}$ ifadesini sadeleştirin.

> **Çözüm:** $A+\overline{B}C$ (Bölüm 5.2).

**Soru 6** (ekrandan, 01:05:00 ve 01:15:00): Dört bitlik bir sayı 3'ten küçük ya da 12'den büyükse çıkışı 1 olan devreyi bulun ve yalnız NAND kapılarıyla çizin. Aynı devreyi yalnız NOR kapılarıyla çizin (ekrandan, 01:45:00).

> **Çözüm:** $f=ABD+ABC+\overline{A}\,\overline{B}\,\overline{C}+\overline{A}\,\overline{B}\,\overline{D}$; NAND biçimi $\overline{\overline{ABD}\cdot\overline{ABC}\cdot\overline{\overline{A}\,\overline{B}\,\overline{C}}\cdot\overline{\overline{A}\,\overline{B}\,\overline{D}}}$ (beş NAND). NOR için 0'lar gruplanır: $f=(A+\overline{C}+\overline{D})(\overline{A}+C+D)(\overline{A}+B)(A+\overline{B})$, iki kez tümleyen alınarak her parantez ve dış işlem NOR olur.

**Soru 7** (ekrandan, 01:50:00): Aynı fonksiyonda 3 önemsiz olsa sonuç ne olur? 3 ve 12 önemsiz olsa?

> **Çözüm:** $f=\overline{A}\,\overline{B}+ABD+ABC$; 3 ve 12 önemsizse $f=\overline{A}\,\overline{B}+AB$.

**Soru 8** (ekrandan, 01:55:00): Oy ağırlıkları $A=30$, $B=25$, $C=25$, $D=10$, $E=10$ olan beş kişinin evet oylarının toplamı 65 ya da daha fazlaysa 1 veren mantık devresinin ifadesini bulun.

> **Çözüm (derste verilen sonuç hatalıydı, düzeltilmiş):** Haritaya $E$ yazılarak $f=ABC+ABD+ACD+ABE+ACE+BCDE$ bulunur (Bölüm 9.3, python ile denetlendi).

**Soru 9** (ekrandan, 02:10:00): Mintermleri 0, 3, 5, 6, 7, 10, 12, 13 ve önemsizleri 2, 9, 15 olan fonksiyonu Quine-McCluskey yöntemiyle sadeleştirin.

> **Çözüm:** $f=XZ+WX\overline{Y}+\overline{X}Y\overline{Z}+\overline{W}Y+\overline{W}\,\overline{X}\,\overline{Z}$ (Bölüm 10).

**Soru 10** (derste sözlü, 02:31:48): $A\subseteq B$ ifadesinin başka bir sözel yorumu nedir?

> **Çözüm:** Derste "B'nin elemanlarının bazıları A'nın da elemanıdır" yorumu verildi ve $\exists x\,(x\in B\wedge x\in A)$ diye yazıldı; bu ifadenin alt kümeye denk olmadığı Bölüm 11.3'teki notta açıklandı. Asıl tanım $\forall x\,(x\in A\rightarrow x\in B)$'dir.

**Soru 11** (derste sözlü, 02:40:12): Simetrik farkın (XOR) Türkçe ve İngilizce karşılığı nedir?

> **Çözüm:** Türkçede "ya da", İngilizcede "exclusive or" (either ... or).

## Dersin Toparlaması

Dersin ilk yarısında Bool cebri ve Karnaugh haritaları üzerine slayt dışı örnekler çözüldü: $x+\overline{x}y=x+y$ ve $(A+B)(A+C)=A+BC$ gibi kurallarla sadeleştirme, SOP ve POS biçimleri, dual alma, yalnız NAND (1'leri gruplayıp çift tümleyen) ve yalnız NOR (0'ları gruplayıp çift tümleyen) ile devre kurma, önemsiz durumlar, beş değişkenli bir problemde bir değişkeni haritaya hücre değeri olarak yazma ve çok değişkenli ifadeler için algoritmik Quine-McCluskey yöntemi. Oylama örneğinde derste bulunan sonuç hatalıydı; doğru ifade bu notta verildi.

İkinci yarıda algoritmaya giden matematik diline geçildi: kümeler, gösterimleri, kardinalite, alt küme ve kuvvet kümesi, küme işlemleri ve bunların mantık kapılarıyla (OR, AND, XOR) bağlantısı, küme özdeşlikleri, kartezyen çarpım, içerme-dışlama ve bit düzeyi işlemlerle XOR şifrelemesi. Sonraki derste diziler ve seriler konusuna geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
