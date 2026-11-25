# Ders 2 Genişletilmiş Notu: Kombinasyonel Devre Blokları (MUX, Dekoder, DEMUX, Enkoder, Toplayıcılar, Karşılaştırıcı, Tri-State Buffer) ve Latch/Flip-Flop'lar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Küçük MUX'lardan büyük MUX kurmak
- 2. Dekoderler
- 3. Dekoderle lojik fonksiyon gerçekleme
- 4. Dekoder ağacı: 2x4 dekoderlerden 4x16 dekoder
- 5. Demultiplexer (DEMUX)
- 6. Enkoderler ve öncelik enkoderi
- 7. Yarım ve tam toplayıcılar
- 8. Yalnız yarım toplayıcıyla tam toplayıcı
- 9. Çok bitli bloklar: çok bitli MUX ve toplayıcılar
- 10. Toplayıcı-çıkarıcı devresi
- 11. Karşılaştırıcı
- 12. Üç durumlu tampon (tri-state buffer)
- 13. Ardışıl devreler: latch ve flip-flop
- 14. Preset ve clear: asenkron ve senkron başlangıç değeri
- Örnek Sorular

Bu ders, bilgisayar organizasyonu konularına geçmeden önce lojik devreler dersinden gereken yapı taşlarının tekrarıdır. Önceki derste kombinasyonel blokların ilki olan multiplexer'ın (MUX) iç yapısı çarpımlar toplamı biçimindeki fonksiyonundan kurulmuştu. Bu derste önce küçük bloklardan büyük blokların nasıl kurulacağı, sonra dekoder, DEMUX, enkoder, toplayıcı ve karşılaştırıcı gibi bloklar, en sonda da ardışıl devrelerin hafıza elemanları ele alınır. Anlatım İngilizce slaytlar üzerinde el çizimiyle yürür.

## 1. Küçük MUX'lardan büyük MUX kurmak

### 1.1 MUX'u hatırlama

MUX, $n$ tane girişten birini seçip çıkışa aktaran devredir. Bunun için $\log_2 n$ tane seçim ucu gerekir. Önceki derste görülenler 1 bitlik MUX'lardı, yani her giriş tek bir bitti. İlerleyen tasarımlarda girişleri $n$ bitlik olan MUX'lar da kullanılacak.

### 1.2 2'ye 1 MUX'lardan 4'e 1 MUX

Soru şudur: elimizde yalnız 2'ye 1 MUX'lar (2 giriş, 1 seçim ucu, 1 çıkış) varsa, 4 girişli ($w_0..w_3$), 2 seçim uçlu ($s_1, s_0$) ve 1 çıkışlı ($f$) bir 4'e 1 MUX kurabilir miyiz?

- 4'e 1 MUX'un 4 girişi var, 2'ye 1 MUX'un 2 girişi var. Demek ki ilk katmanda iki tane 2'ye 1 MUX gerekir.
- Bu iki MUX aynı seviyededir. Seçim uçlarını ortaklarsak ikisi de aynı anda 0 numaralı ya da 1 numaralı girişini aktarır.
- İlk katmanın çıkışında iki aday kalır ($w_0$ ya da $w_1$ ile $w_2$ ya da $w_3$). Bunlardan tek bir $f$ elde etmek için ikinci katmanda bir 2'ye 1 MUX daha gerekir.

Slaytta ilk katmandaki iki MUX'un girişleri $w_0, w_1$ ve $w_2, w_3$'tür, ortak seçim ucu $s_0$'dır; ikinci katmandaki MUX'un seçim ucu $s_1$'dir (ekrandan, 00:05:00).

### 1.3 Hangi seçim ucu daha anlamlı?

Hoca, uçların adını bilmiyormuş gibi davranıp ilk katmana bağlı uca $Y$, ikinci katmana bağlı uca $X$ dedi ve hangisinin $s_0$ olduğunu deneyerek bulmayı gösterdi.

- 4'e 1 MUX'ta $s_1$ sabitken $s_0$'ı değiştirmek seçilen girişi bir basamak kaydırır ($w_0 \leftrightarrow w_1$ ya da $w_2 \leftrightarrow w_3$). $s_0$ sabitken $s_1$'i değiştirmek iki basamak kaydırır ($w_0 \leftrightarrow w_2$ ya da $w_1 \leftrightarrow w_3$).
- Kurduğumuz devrede $X = 0$ iken $Y$'yi değiştirince çıkış $w_0$'dan $w_1$'e geçer; $X = 1$ iken $w_2$'den $w_3$'e geçer. Bir basamak kaydırdığı için $Y$ düşük anlamlı uçtur, yani $s_0$'dır.
- $Y = 0$ iken $X$'i değiştirince çıkış $w_0$'dan $w_2$'ye geçer. İki basamak kaydırdığı için $X$ yüksek anlamlı uçtur, yani $s_1$'dir.

Sonuç: ikinci katmana bağlanan seçim ucunun anlam değeri daha yüksek, birinci katmana bağlananınki daha düşüktür.

### 1.4 Genelleme

Hoca, $2^n$'e 1 MUX'u bir düşük seçim uçlu MUX'lardan kurmayı şöyle genelledi: iki tane $2^{n-1}$'e 1 MUX ve bir tane 2'ye 1 MUX, toplam 3 MUX. Örneğin 8'e 1 MUX, iki tane 4'e 1 MUX (her biri dört girişi kapsar) ve çıkışlarını birleştiren bir 2'ye 1 MUX ile kurulur; seçim uçları ilk katmanda 2, son katmanda 1 olmak üzere toplam 3'tür.

16'ya 1 MUX için iki örnek verildi:

- 2'ye 1 MUX'larla: 16 giriş olduğu için ilk katmanda 8 tane 2'ye 1 MUX gerekir. Hoca ikinci katmanda bir 8'e 1 MUX kullanılırsa toplam 9 MUX olacağını söyledi.
- 4'e 1 MUX'larla: ilk katmanda 4 tane 4'e 1 MUX, seçilen 4 adayı birleştirmek için bir 4'e 1 MUX daha; toplam 5 tane 4'e 1 MUX (ekrandan, 00:05:00).

> **Ders sonrası not:** Hocanın "9 adet" sonucu, ikinci katmanda hazır bir 8'e 1 MUX kullanıldığı varsayımıyla geçerlidir. Yalnız 2'ye 1 MUX kullanılırsa katmanlar $8 + 4 + 2 + 1 = 15$ MUX gerektirir.

Temel analiz giriş sayısına bakılarak yapılır.

## 2. Dekoderler

### 2.1 Blok yapı

Dekoderin $n$ girişi, bir enable ucu ve $2^n$ çıkışı vardır (ekrandan, 00:15:00). Adlandırma giriş-çıkış sayısına göredir: 1 girişli 2 çıkışlı olana 1x2, 2 girişli olana 2x4 dekoder denir. Girişler bir anlam sırasına sahiptir (en üstteki en yüksek anlamlı, en alttaki en düşük anlamlı olsun).

Çalışma mantığı şöyledir: enable aktifken girişlere verilen $n$ bitlik ikili sayının ondalık karşılığı kaçsa o numaralı çıkış aktif olur, diğer bütün çıkışlar aktif olmaz. Enable pasifse hiçbir çıkış aktif olmaz.

Enable ucu aktif 1 ya da aktif 0 olabilir. Aktif 0 enable, $E$'nin üzerinde çizgiyle gösterilir; entegreyi çalıştırmak için bu uca 0 verilir, 1 verilirse entegre seçilmez. Aynısı çıkışlar için de geçerlidir: aktif 1 çıkışta seçilen çıkış 1, diğerleri 0 olur; aktif 0 çıkışta seçilen çıkış 0, diğerleri 1 olur. Aktif 0 çıkışlar hem isimlerinin üzerindeki çizgiyle hem şemada uçtaki küçük yuvarlakla gösterilir.

Slayttaki özet: "If enable=1, one output is asserted high, the other outputs are asserted low; if enable=0, all outputs asserted low", "Often, enable pin is not needed", "Called n-to-$2^n$ decoder", "Decoders are often used for RAM/ROM addressing" (ekrandan, 00:15:00).

### 2.2 Ne için kullanılır?

Dekoder, $n$ bitlik paketlenmiş bir girişi genişletir: çıkış tarafı, girişin bit bazında ya da ondalık anlam sırasında çözülmüş halidir. Başlıca kullanım alanları:

- RAM ve ROM'lar için adres çözümleme devresi,
- G/Ç cihazlarının hangi adres aralıklarına yerleşeceğini belirleyen yardımcı devre.

### 2.3 2x4 dekoderin iç yapısı

Doğruluk tablosu (ekrandan, 00:20:00):

| En | $w_1$ | $w_0$ | $y_3$ | $y_2$ | $y_1$ | $y_0$ |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| 1 | 0 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| 0 | - | - | 0 | 0 | 0 | 0 |

Her çıkışı $En, w_1, w_0$ cinsinden yazalım. Enable 0 iken $w_1, w_0$ ne olursa olsun bütün çıkışlar 0 olmalıdır. Tablonun son satırı aslında dört satırın kısaltmasıdır ve bu satırların hiçbirinde doğru minterm yoktur. Her çıkış sütununda yalnız bir doğru minterm kalır:

$$y_3 = En\, w_1 w_0, \quad y_2 = En\, w_1 \bar w_0, \quad y_1 = En\, \bar w_1 w_0, \quad y_0 = En\, \bar w_1 \bar w_0$$

Slayttaki devre de bunu gösterir: iki NOT kapısı ve her biri $En$ ile girişlerin uygun biçimlerini çarpan dört tane 3 girişli AND kapısı. Böylece bir "kara kutu"nun istenen davranışından, çarpımlar toplamı yaklaşımıyla iç yapısı tasarlanmış olur.

### 2.4 Aktif 1 çıkışlı dekoderin çıkışları mintermdir

Enable'ı görmezden gelelim (ya da 1 olduğunu düşünelim). Bu durumda $y_3 = w_1 w_0$, $y_2 = w_1 \bar w_0$, $y_1 = \bar w_1 w_0$, $y_0 = \bar w_1 \bar w_0$ olur.

**Soru (hoca):** Enable'ı görmezsek $y$ çıkışları neye benziyor? **Cevap:** Bir öğrenci önce $w_1$'in $2^1$'i, $w_0$'ın $2^0$'ı temsil ettiğini söyledi; hoca bunun zaten tanımda olduğunu belirtti. Başka bir öğrenci doğru cevabı verdi: mintermler. $y_3$ 3. minterme, $y_2$ 2. minterme, $y_1$ 1. minterme, $y_0$ 0. minterme karşılık gelir.

> **Hocanın vurgusu:** Dekoderin çıkışları seçim uçlarının mintermlerine karşılık gelir. Bu yüzden elimizde seçim uçlarının bütün mintermleri vardır ve dekoder fonksiyon gerçeklemek için kullanılabilir.

## 3. Dekoderle lojik fonksiyon gerçekleme

### 3.1 Aktif 1 çıkışlı dekoder ve OR kapısı

İki girişli bir fonksiyon (ekrandan, 00:30:00):

| $a$ | $b$ | $f$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Bu fonksiyon bir 2x4 dekoder ve bir OR kapısıyla gerçeklenmek isteniyor. Doğru mintermlerin toplamı:

$$f = \bar a b + a \bar b + ab$$

Tabloda $b$ her satırda bir basamak, $a$ ise iki satırda bir değişiyor; yani $a$ yüksek anlamlı değişken gibi yazılmış. Aynı anlam sırasını korumak için $a$, $w_1$'e; $b$, $w_0$'a bağlanır; enable'a 1 verilir. İhtiyaç duyulan terimler $y_1$, $y_2$ ve $y_3$ çıkışlarında zaten vardır. Bunlar bir OR kapısında birleştirilince $f$ elde edilir.

Genel sonuç: $n$ girişli herhangi bir lojik fonksiyon, aynı sayıda seçim ucu olan bir dekoder ve bir OR kapısıyla gerçeklenebilir.

### 3.2 Aktif 0 çıkışlı dekoder: çıkışlar makstermdir

Şimdi çıkışları ve enable'ı aktif 0 olan bir 2x4 dekodere bakalım. Hoca doğruluk tablosunu tahtaya çizdi (ekrandan, 00:30:00):

| $\bar E$ | $w_1$ | $w_0$ | $\bar y_3$ | $\bar y_2$ | $\bar y_1$ | $\bar y_0$ |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 1 | 1 | 0 |
| 0 | 0 | 1 | 1 | 1 | 0 | 1 |
| 0 | 1 | 0 | 1 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | - | - | 1 | 1 | 1 | 1 |

Enable ucuna 1 gelirse entegre seçilmez ve aktif 0 çıkışların hepsi 1 olur. Enable 0 iken girişin ondalık değerindeki çıkış 0 olur, diğerleri 1 kalır.

Her sütunda tek bir 0 olduğu için fonksiyonları yanlış makstermlere göre (toplamlar çarpımı biçiminde) yazmak pratiktir. Bir öğrenci önce çarpım biçimini denedi; başka bir öğrenci "bir olan yerlerde değil yapılır" diyerek doğru biçimi hatırlattı. Burada $\bar E$ enable ucunun kendi değeridir:

$$\bar y_3 = \bar E + \bar w_1 + \bar w_0, \quad \bar y_2 = \bar E + \bar w_1 + w_0, \quad \bar y_1 = \bar E + w_1 + \bar w_0, \quad \bar y_0 = \bar E + w_1 + w_0$$

Bunun anlamı şudur: enable ucuna 1 gelince her terimde "+1" olduğu için bütün çıkışlar 1 olur, yani entegre seçilmemiş olur. Enable'ı görmezsek (0 verdiğimizi düşünürsek), aktif 0 çıkışlı dekoderin her çıkışı $w_1, w_0$'ın bir makstermidir: $\bar y_3$ 3. maksterm, $\bar y_2$ 2. maksterm, $\bar y_1$ 1. maksterm, $\bar y_0$ 0. maksterm.

### 3.3 Aynı fonksiyon aktif 0 dekoderle

Aynı $f$ fonksiyonunu bu kez toplamlar çarpımı olarak yazalım. Fonksiyonun tek yanlış satırı $a = b = 0$'dır, yani yalnız 0. makstermi vardır:

$$f = a + b$$

Bu, dekoderin $\bar y_0$ çıkışıdır. Enable ucuna 0, $w_1$'e $a$, $w_0$'a $b$ verilirse $\bar y_0$ çıkışı doğrudan $f$ olur. Hoca, bunun lojik devreler dersinde deney olarak da yapıldığını hatırlattı.

## 4. Dekoder ağacı: 2x4 dekoderlerden 4x16 dekoder

### 4.1 Yapı

Amaç, 2x4 dekoderlerden bir 4x16 dekoder kurmaktır (ekrandan, 00:35:00).

- 2x4 dekoderin 4 çıkışı var, bize 16 çıkış lazım. Demek ki son katmanda 4 tane 2x4 dekoder gerekir.
- Bu dört dekoderin seçim uçları ortaklanır ($w_0$, $w_1$). Hoca, bunların eş anlı seçilmesinin mantıklı olduğunu, aksi halde yanlış çalışma olabileceğini söyledi.
- Dört dekoderin her birinin bir enable ucu vardır. Bu dört enable ucunu da bir dekoderle kontrol etmek için dört çıkışlı, yani bir 2x4 dekoder daha gerekir. Bu dekoderin girişleri $w_2, w_3$'tür, enable ucu dışarıya açılan $En$'dir; çıkışları ikinci katmandaki dekoderlerin enable uçlarına gider.

Dışarıdan bakınca 4 seçim ucu, 1 enable ucu ve 16 çıkış ucu vardır; uç uyumluluğu sağlanmıştır. Slayttaki başlık: "A 4-to-16 decoder built using a decoder tree".

### 4.2 Hangi uç en düşük anlamlı?

4x16 dekoderde $w_3$ en yüksek, $w_0$ en düşük anlamlı seçim ucudur. Diğerleri sabitken bir ucu değiştirip aktif çıkışın ne kadar kaydığına bakılır. Örneğin $1110$ 14'e karşılık gelir; $w_0$'ı 1 yapınca $1111 = 15$ olur. Yani en düşük anlamlı uç, diğerleri sabitken aktif çıkışı bir basamak kaydırır.

Kurduğumuz devrede mantık olarak en yüksek ya da en düşük anlamlı uç, ya ilk katmandaki dekoderin uçlarından ya da ikinci katmandakilerin uçlarından biridir. Hoca, ilk katmana 1,1 verilince en alttaki dekoderin seçildiğini; ikinci katmanda $w_0$ ucu 0 iken o dekoderin $y_2$ çıkışının, 1 yapılınca $y_3$ çıkışının aktif olduğunu gösterdi. Aktif çıkış bir basamak kaydığı için ikinci katmana bağlanan bu uç en düşük anlamlı uçtur. Diğer uçlar da aynı yöntemle sınanarak anlam sıraları bulunur.

## 5. Demultiplexer (DEMUX)

### 5.1 Tanım

MUX, $n$ girişten birini çıkışa yönlendiriyordu. DEMUX bunun karşılığıdır: tek bir girişi çok sayıdaki çıkış kanalından birine yönlendirir. $n$ seçim ucu varsa $2^n$ çıkış vardır: 1 seçim ucu ile 1'e 2, 2 seçim ucu ile 1'e 4 DEMUX.

### 5.2 1'e 4 DEMUX

Veri girişi $I$ (tabloda $A$ ile gösterilmiş), seçim uçları $s_1 s_0$, çıkışlar $O_0..O_3$ (ekrandan, 01:00:00):

| $s_1$ | $s_0$ | $O_3$ | $O_2$ | $O_1$ | $O_0$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | A |
| 0 | 1 | 0 | 0 | A | 0 |
| 1 | 0 | 0 | A | 0 | 0 |
| 1 | 1 | A | 0 | 0 | 0 |

Giriş değeri, seçim uçlarındaki ikili sayının ondalık karşılığındaki çıkışta görülür. Her çıkış sütununda sıfırdan farklı olabilen tek bir satır vardır; diğer satırlar 0 ile çarpıldığı için elenir:

$$O_3 = s_1 s_0 I, \quad O_2 = s_1 \bar s_0 I, \quad O_1 = \bar s_1 s_0 I, \quad O_0 = \bar s_1 \bar s_0 I$$

Slayttaki devre iki NOT ve dört tane 3 girişli AND kapısından oluşur.

**Soru:** Tablodaki $A$ ile $I$ aynı mı? **Cevap:** Evet. $A$ da 0 ya da 1 değerini alan ikili bir değişkendir; $I$ ile aynı şeydir.

## 6. Enkoderler ve öncelik enkoderi

### 6.1 Enkoder

Enkoder, dekoderin tersi gibi düşünülebilir: $2^n$ girişi ve $n$ çıkışı vardır (2 çıkışlı olan 4'e 2 enkoderdir). Girişlerde hangi numaralı uçta 1 görülüyorsa çıkışta o numaranın ikili karşılığı üretilir.

> **Hocanın vurgusu:** Enkoder mantığında giriş tarafında yalnız bir tane 1'e izin verilir.

### 6.2 Öncelik enkoderi (priority encoder)

Öncelik enkoderi birden fazla 1'e izin verir. Girişler anlam sırasına göre $0$'dan $2^n - 1$'e numaralanır; en yüksek anlamlı girişten taramaya başlanır ve ilk 1 görülen girişin ikili karşılığı çıkışta üretilir.

**Soru (hoca):** Enkoderde olmayan, öncelik enkoderinde ortaya çıkan ikinci özel durum nedir? **Cevap (bir öğrenci):** Hiçbir girişin 1 olmaması. Bu durumda çıkış 0 olamaz, çünkü ondalık 0, $w_0$'ın 1 olduğu durumdur. Bunun için ayrı bir $z$ çıkışı vardır.

Slayttaki tanım (ekrandan, 01:05:00): $2^n$ ikili giriş, $n$ ikili çıkış ve bir "valid" çıkışı ($z$). "Priority encoder allows for multiple inputs to have a value of '1', as it encodes the input with the highest priority (MSB = highest priority, LSB = lowest priority)"; "valid output indicates when priority encoder output is valid".

Doğruluk tablosunun mantığı hocanın anlatımıyla şöyledir: $w_3 = 1$ görülürse diğer girişlere bakılmadan çıkışta $11$ (3) üretilir. $w_3 = 0$, $w_2 = 1$ ise alt girişler 0 ya da 1 olabilir, çıkış $10$ (2) olur. Böyle devam edilir. Hiçbir girişte 1 yoksa $z = 0$ üretilir ve bu, $y$ çıkışlarındaki değerin anlamsız olduğunu gösterir.

<!-- BELİRSİZ: Öncelik enkoderinin doğruluk tablosu slaytı okunan karelerde yok; tablo altyazıdaki anlatımdan kuruldu. -->

**Kullanım alanı:** Birden fazla cihaz için bir kesme denetleyicisi yapılacaksa, en önemli kesme kaynağı en yüksek anlamlı girişe bağlanır. Aynı denetim çevriminde birden fazla kesme isteği gelse bile, donanımsal önceliği en yüksek olan girişteki kesme çözümlenir.

### 6.3 4'e 2 enkoderin iç yapısı ve don't care

Doğruluk tablosu (ekrandan, 01:10:00):

| $w_3$ | $w_2$ | $w_1$ | $w_0$ | $y_1$ | $y_0$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 0 | 0 | 1 | 1 |

Önceki yaklaşımla $y_1$'i doğru mintermlerinden yazalım:

$$y_1 = \bar w_3 w_2 \bar w_1 \bar w_0 + w_3 \bar w_2 \bar w_1 \bar w_0$$

**Soru (hoca):** Sonuç aslında $w_2 + w_3$; neden bu kadar karmaşık bir devre çıktı? **Cevap (bir öğrenci):** Yazmadığımız terimlerden dolayı. Dört değişkenli bir fonksiyonun doğruluk tablosu 16 satırdır; burada yalnız 4'ü görünüyor, geri kalan 12 satır "don't care"dir. Bunu Karnaugh haritasında kullanmak gerekir.

$y_1$ için Karnaugh haritası (satırlar $w_1 w_0$, sütunlar $w_3 w_2$, Gray sırasıyla 00, 01, 11, 10; X = don't care) (ekrandan, 01:15:00):

| $w_1 w_0$ \ $w_3 w_2$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | X | 1 | X | 1 |
| 01 | 0 | X | X | X |
| 11 | X | X | X | X |
| 10 | 0 | X | X | X |

Bir öğrenci 01 ve 11 sütunlarını birlikte almayı, ayrıca 10 sütununu yukarıdan aşağı almayı önerdi. Hoca 8'li iki grup aldı:

- 01 ve 11 sütunları ($w_2 = 1$): $w_3$, $w_1$ ve $w_0$ elenir, $w_2$ kalır.
- 11 ve 10 sütunları ($w_3 = 1$): $w_3$ kalır.

$$y_1 = w_2 + w_3$$

Aynı işlem $y_0$ için yapılınca 8'li iki grup (biri $w_3 = 1$ sütunları, diğeri $w_1 = 1$ satırları) alınır:

$$y_0 = w_1 + w_3$$

Slayttaki devre de bunu doğrular: $y_0$ için $w_1$ ve $w_3$'ü, $y_1$ için $w_2$ ve $w_3$'ü toplayan iki OR kapısı; $w_0$ hiçbir yere bağlı değildir. Yaklaşım aynıdır, ama don't care satırları sayesinde fonksiyon sadeleştirilmiştir.

## 7. Yarım ve tam toplayıcılar

### 7.1 Kavramın çıkış noktası

Hoca ondalık bir örnekle başladı: $9999 + 8888$. Birler basamağında yalnız iki basamağın değerleri toplanır; bu, ikili aritmetikteki yarım toplayıcıya karşılık gelir. Bu toplamdan bir sonuç ve bir sonraki basamağa giden bir elde oluşur. Sonraki basamaklarda iki basamak ve gelen elde toplanır; bu da tam toplayıcıya karşılık gelir.

### 7.2 Çıkış kaç bit olmalı?

- Yarım toplayıcı iki tane 1 bitlik girdi alır. En büyük toplam $1 + 1 = 2$'dir ve 2'yi göstermek için iki bit gerekir. Çıkış, anlam sırasına dikkat edilerek iki bittir.
- Tam toplayıcı $A$, $B$ ve carry-in olmak üzere üç tane 1 bitlik girdi alır. En büyük toplam $1 + 1 + 1 = 3 = 11_2$'dir. Çıkış yine iki bittir.

Slayttaki özet (ekrandan, 01:20:00): "Half-adder: Adds two binary (i.e. 1-bit) inputs A and B, produces a sum and carryout. Problem: Cannot use it alone to build larger adders"; "Full-adder: Adds three binary inputs A, B, and carryin ... Allows building M-bit adders (M > 1). Simple technique: connect $C_{out}$ of one adder to $C_{in}$ of the next. These are called ripple-carry adders".

### 7.3 4 bitlik iki sayıyı toplamak

$A = A_3 A_2 A_1 A_0$ ve $B = B_3 B_2 B_1 B_0$ toplanacak.

- En düşük basamakta bir yarım toplayıcıya $A_0$ ve $B_0$ bağlanır. Toplam çıkışı $S_0$ nihai sonucun son basamağıdır; eldesi $C_1$ bir sonraki basamağa gider.
- Bir sonraki basamakta üç girişli bir toplayıcı, yani tam toplayıcı gerekir: $A_1$, $B_1$ ve carry-in'e $C_1$. Çıkışlar $S_1$ ve $C_2$'dir.
- Aynı şekilde $A_2, B_2, C_2 \to S_2, C_3$ ve $A_3, B_3, C_3 \to S_3, C_4$.

4 bitlik iki sayının toplamı en fazla $15 + 15 = 30$ eder; 30'u göstermek için 5 bit gerekir. Beşinci bit son toplayıcının eldesi $C_4$'tür.

**Soru (hoca):** Bu toplayıcıyı yalnız tam toplayıcılarla kurmak istesek ne değişir? **Cevap:** En düşük basamağa da bir tam toplayıcı konur ve carry-in girişine lojik 0 bağlanır; sonuç aynı olur.

### 7.4 Yarım toplayıcının iç yapısı

Yarım toplayıcı $(C S)_2 = A + B$ ikili sayısını üretir: toplamın yüksek anlamlı biti $C$, düşük anlamlı biti $S$'dir (ekrandan, 01:25:00).

| $A$ | $B$ | Sum | $C_{out}$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |

$C_{out}$ sütununda tek doğru minterm son satırdadır: $C_{out} = AB$. Toplam sütununda iki doğru minterm vardır:

$$S = \bar A B + A \bar B = A \oplus B$$

Bu ifade AND, OR ve NOT kapılarıyla kurulabilir, ama transistör düzeyinde XOR kapısı tek bir blok olarak gerçeklenebildiği için toplam bir XOR kapısıyla verilir.

### 7.5 Tam toplayıcının iç yapısı

Tam toplayıcı $(C_{out}\, S)_2 = A + B + C_{in}$ ikili sayısını üretir (ekrandan, 01:25:00):

| $A$ | $B$ | $C_{in}$ | Sum | $C_{out}$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

Artık indirgenmiş fonksiyonlar gerektiği için Karnaugh haritasına bakılır (cebirsel indirgeme de mümkün ama daha uzun).

**Toplam fonksiyonu.** Karnaugh haritası (sütunlar $AB$ = 00, 01, 11, 10; satırlar $C_{in}$):

| $C_{in}$ \ $AB$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 0 |

Bu harita sadeleşmez. Ama $A = 0$ yarısında ($AB$ = 00, 01) bir XOR deseni, $A = 1$ yarısında ($AB$ = 11, 10) başka bir desen vardır (ekrandan, 01:35:00).

- $A = 0$ yarısının terimleri: $\bar A \bar B C + \bar A B \bar C = \bar A (B \oplus C)$.
- $A = 1$ yarısının terimleri: $ABC + A \bar B \bar C = A(BC + \bar B \bar C)$. Parantez içi $B$ ile $C$'nin XNOR'udur.

XNOR ile XOR arasındaki ilişkiyi görmek için XOR'un değili De Morgan ile açılır:

$$\overline{a \oplus b} = \overline{\bar a b + a \bar b} = \overline{\bar a b} \cdot \overline{a \bar b} = (a + \bar b)(\bar a + b) = ab + \bar a \bar b$$

Çarpım açılırken $a \bar a = 0$ ve $\bar b b = 0$ terimleri düşer. Demek ki $a \odot b = \overline{a \oplus b}$; XNOR, XOR'un tümleyenidir.

Şimdi $X = B \oplus C$ dersek $A = 1$ yarısının parantezi $\bar X$ olur:

$$S = \bar A X + A \bar X = A \oplus X = A \oplus (B \oplus C)$$

XOR'un değişme ve birleşme özelliği olduğu için:

$$S = A \oplus B \oplus C_{in}$$

**Elde fonksiyonu.** Karnaugh haritası (ekrandan, 01:35:00):

| $C_{in}$ \ $AB$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 1 | 1 |

En küçük indirgeme üç tane 2'li grupla yapılır: $C_{out} = BC + AC + AB$. Bunda ortak kapı yoktur. Amaç, toplam için zaten gereken XOR kapısını eldede de kullanmaktır. Bunun için gruplar değiştirilir: $AB = 11$ sütunu birlikte alınır ($AB$ terimi), geri kalan iki 1 tek tek alınır:

$$C_{out} = AB + \bar A B C + A \bar B C = AB + C(\bar A B + A \bar B) = AB + C_{in}(A \oplus B)$$

(ekrandan, 01:40:00). Devrede $A$ ile $B$ bir XOR kapısına girer; bu kapının çıkışı hem $C_{in}$ ile ikinci XOR'a girip toplamı verir, hem de $C_{in}$ ile AND'lenir. Bu AND'in çıkışı ile $AB$ bir OR kapısında birleşip $C_{out}$'u verir.

> **Hocanın vurgusu:** Çok çıkışlı fonksiyonları gerçeklerken ortak kapıların olup olmadığına bakılmalıdır. Ortak kapıları kullanmak, toplamda daha az kapılı ve daha düşük karmaşıklıklı devreler verir. Karnaugh haritasındaki en sade sonuç, çok çıkışlı bir devrede en iyi sonuç olmayabilir.

## 8. Yalnız yarım toplayıcıyla tam toplayıcı

Lojik devreler dersinde tam toplayıcının iki yarım toplayıcı ve bir OR kapısıyla kurulduğu görülmüştü (ekrandan, 01:45:00): ilk yarım toplayıcı $x_i, y_i$'yi toplar; toplamı $c_i$ ile ikinci yarım toplayıcıda toplanır ve bu toplam $s_i$'dir. İki yarım toplayıcının eldeleri bir OR kapısında birleşip $c_{i+1}$ olur. Üç girişi toplamak için en az iki yarım toplayıcı gerektiği açıktır: önce ikisi toplanır, sonra üçüncüsü eklenir. İlk ya da ikinci toplamdan bir elde geliyorsa çıkış eldesi 1 olmalıdır.

Slayta hocanın el yazısıyla eklenen soru: "Sadece HA ile FA?" Yani OR kapısı da kullanmadan, yalnız yarım toplayıcılarla tam toplayıcı kurulabilir mi?

**Cevap (bir öğrenci):** OR kapısının yerine bir yarım toplayıcı konur. İki elde bu yarım toplayıcının girişlerine bağlanır; onun toplam çıkışı tam toplayıcının $C_{out}$'u olarak kullanılır, elde çıkışı kullanılmaz. Hoca cevabı doğruladı; aynı cevap sohbetten de gelmişti.

**Soru (bir öğrenci):** İki elde de 1 olursa toplam 0 olmaz mı? **Cevap:** Girişlere verilebilecek değerlerle iki eldenin aynı anda 1 olduğu bir durum oluşmaz. Bu yüzden XOR, OR ile aynı sonucu verir.

> **Ders sonrası not:** Bu iddia sekiz giriş kombinasyonunun hepsinde python ile denendi: ilk yarım toplayıcının eldesi $AB$, ikincininki $(A \oplus B)C$'dir; $AB = 1$ iken $A \oplus B = 0$ olduğu için ikisi aynı anda 1 olamaz ve $c_1 \oplus c_2 = c_1 + c_2 = C_{out}$ her durumda doğrudur.

## 9. Çok bitli bloklar: çok bitli MUX ve toplayıcılar

### 9.1 Veri yolu ve çok bitli MUX

Bu ana kadarki bütün bloklar 1 bitlikti. Bundan sonra her kanalı $n$ bitlik olan bloklara bakılır. Veri yolu (bus), $n$ bitlik bir sayıyı taşıyan tel grubudur. Örneğin $w_0..w_3$'ün her biri 8 telden oluşan bir grup olsun ve bu gruplardan biri dışarı aktarılmak istensin; çıkış da 8 bitlik olmalıdır. Dört grup olduğu için 8 bitlik bir 4'e 1 MUX gerekir ve iki seçim ucu vardır (ekrandan, 01:50:00).

Şemada bir tel üzerindeki eğik çizgi ve yanındaki sayı, o telin kaç alt telden oluştuğunu gösterir. Seçim uçları tek bitlik tellerdir; girişler ve $f$ çıkışı 8 bitliktir. Slayttaki doğruluk tablosu: $s_1 s_0 = 00 \to w_0$, $01 \to w_1$, $10 \to w_2$, $11 \to w_3$.

Bunu 1 bitlik MUX'lardan kurmak için 8 ayrı 1 bitlik 4'e 1 MUX gerekir. Her MUX, girişlerin ilgili anlam sırasındaki bitleri arasında seçim yapar: en yüksek anlamlı MUX $w_0..w_3$'ün 7 numaralı bitleri arasında, bir sonraki 6 numaralı bitleri arasında seçer. Seçim değeri bütün alt MUX'lara eş anlı gider. Seçim uçlarına 1,1 verilirse her MUX $w_3$'ün kendi bitini aktarır ve çıkışta $w_3$'ün 8 bitinin tamamı görülür.

### 9.2 16 bitlik işaretsiz toplayıcı

Kara kutu olarak bir toplayıcı: $X$ ve $Y$ 16 bitlik girişler, $C_{in}$ 1 bitlik giriş, $S$ 16 bitlik çıkış, $C_{out}$ 1 bitlik çıkış (ekrandan, 01:55:00).

Çıkış kaç bit olmalı? Basit örnek: 4 bitlik en büyük işaretsiz sayı 15'tir; $15 + 15 = 30$ ve 30 için 5 bit gerekir. Genel olarak:

> **Hocanın vurgusu:** $n$ bitlik iki sayının toplamını kesin olarak göstermek için $n + 1$ bit gerekir.

Girişler 16 bitlikse çıkış 17 bitlik olmalıdır: düşük anlamlı 16 bit $S$'te, en yüksek anlamlı bit $C_{out}$'tadır. Slaytta $C_{out}$ ile $S$ birlikte çevrelenip "17" yazılmıştır. Bu bloğun işlevi:

$$(C_{out}\, S)_2 = X + Y + C_{in}$$

Burada $X$ ve $Y$ $n$ bitlik, $C_{in}$ ve $C_{out}$ 1 bitlik, $S$ $n$ bitliktir.

### 9.3 İki 16 bitlik toplayıcıdan 32 bitlik toplayıcı

$A$ ve $B$ 32 bitlik sayılar olsun (bitleri 0-31).

- Düşük anlamlı toplayıcıya $A_{0..15}$ ve $B_{0..15}$ girer. Çıkan 16 bit, 32 bitlik toplamın düşük anlamlı 16 bitidir.
- Bu toplamdan bir elde gelebilir. Bu elde, toplayıcının $C_{out}$ çıkışından yüksek anlamlı toplayıcının $C_{in}$ girişine aktarılır.
- Yüksek anlamlı toplayıcıya $A_{16..31}$ ve $B_{16..31}$ girer; çıkışı toplamın yüksek anlamlı 16 bitidir.
- 32 bitlik iki sayının toplamı 33 bitle kesin olarak gösterilebilir. 33. bit, yüksek anlamlı toplayıcının $C_{out}$'udur.

### 9.4 Ripple carry toplayıcı ve gecikme

16 bitlik toplayıcının içinde 16 tane 1 bitlik tam toplayıcı vardır; en düşük anlamlı toplayıcının $C_{in}$'ine dışarıdan 0 verilir. Slayt (ekrandan, 02:00:00): "A 16-bit ripple-carry adder is composed of 16 (1-bit) full adders. Inputs: 16-bit A, 16-bit B, 1-bit carryin (set to zero in the figure below). Outputs: 16-bit sum R, 1-bit overflow". Son eldeye $C_{15}$ "overflow signal" denmiştir. "Called a ripple-carry adder because carry ripples from one full-adder to the next. Critical path is 16 full-adders."

$A$ ve $B$ aynı anda verilse de kapıların ve tellerin bir yayılma (propagation) süresi vardır. En düşük basamakta oluşan eldenin etkisinin en yüksek anlamlı tam toplayıcıya ulaşması zaman alır. Bu sürede çıkışlarda küçük değişiklikler görülür; ancak belirli bir süre sonra anlamlı ve doğru bir değer elde edilir.

> **Hocanın vurgusu:** Peş peşe bağlı çok sayıda blok kullanılan senkron tasarımlarda (örneğin bir mikroişlemci tasarımında) bloğun doğru sonuç üretmesinin belirli bir $T$ süresi aldığı bilinmelidir. Bu süre geçmeden çıktı bir sonraki çevrimde kullanılamaz. Bu yüzden bu gecikme, işlemcinin saat frekansını etkileyen en önemli unsurlardan biridir.

Ripple carry mantığının yerine look-ahead toplayıcılar kullanılabilir. Look-ahead toplayıcıda eldeyi basamak basamak aktarmak yerine bütün girdi değerleri aynı anda tek bir kombinasyonel lojik fonksiyonda değerlendirilir.

## 10. Toplayıcı-çıkarıcı devresi

### 10.1 Ön bilgi: ikiye tümleyen

Önceki derslerde işaretli sayılar için ikiye tümleyen gösterimi kullanılmıştı. $A - B$ işlemi aslında $A + (-B)$ işlemidir. İkiye tümleyende $-B$, önce bit bit değil (bire tümleyen), sonra $+1$ ile bulunur (ekrandan, 02:15:00):

$$A - B = A + (-B), \qquad -B = \bar B + 1$$

### 10.2 Tasarım

Tek bir kontrol ucuyla toplama ve çıkarma arasında geçiş yapan bir devre aranıyor: kontrol 0 ise toplama, 1 ise çıkarma. Bu devre hem girdilerden birinin bit bit değilini alabilmeli hem de $+1$ ekleyebilmelidir.

- **$+1$:** $n$ bitlik toplayıcının carry-in girişine 1 verilirse toplama $+1$ eklenmiş olur. $+1$ yalnız çıkarmada gerekir. Çıkarma 1, toplama 0 ile kodlanır ve kontrol ucu doğrudan $c_0$'a bağlanırsa bu iş kendiliğinden yapılır.
- **$\bar B$:** Bir bitlik $x$'i bilinmeyen bir işleme sokalım. Kontrol 1 iken sonuç $\bar x$, kontrol 0 iken $x$ olmalıdır.

**Soru (hoca):** Böyle bir lojik kapı hatırlıyor muyuz? **Cevap:** XOR kapısı. XOR'un doğruluk tablosunda $y = 1$ olan iki satırda çıkış $x$'in tersidir; $y = 0$ olan iki satırda çıkış $x$'in kendisidir.

$$x \oplus 1 = \bar x, \qquad x \oplus 0 = x$$

Devrede $y_{n-1}..y_0$ bitlerinin her biri, Add/Sub kontrol ucuyla bir XOR kapısına girer; XOR çıkışları $n$ bitlik toplayıcının bir girişine, $x_{n-1}..x_0$ diğer girişine gider; kontrol ucu ayrıca $c_0$'a bağlanır (ekrandan, 02:15:00). Kontrol 1 iken $(c_n\, S) = X - Y$, kontrol 0 iken $X + Y$ üretilir.

## 11. Karşılaştırıcı

### 11.1 Genel

Karşılaştırıcı (comparator), iki $n$ bitlik girişi büyüklük, küçüklük, eşitlik, büyük eşit, küçük eşit gibi durumlara göre karşılaştırır. Örneğin "$A > B$?" karşılaştırıcısı $A$ büyükse 1, eşit ya da küçükse 0 üretir.

### 11.2 4 bitlik eşitlik karşılaştırıcısı

$A = A_3 A_2 A_1 A_0$ ve $B = B_3 B_2 B_1 B_0$. Çıkış ancak $A_3 = B_3$, $A_2 = B_2$, $A_1 = B_1$ ve $A_0 = B_0$ ise 1, aksi halde 0 olmalıdır (ekrandan, 02:20:00).

Önce bir bitlik eşitlik: $x$ ve $y$ eşitken 1, farklıyken 0 veren kapı aranıyor.

**Soru (hoca):** Bu devre nedir? **Cevap (öğrenciler):** XNOR. $x \odot y$ eşitliği verir.

Sonra dört bit çiftinin XNOR çıkışlarının hepsi 1 iken 1, diğer durumlarda 0 veren bir kapı aranıyor: AND kapısı. Örneğin $A_2 \neq B_2$ ise o XNOR 0 verir ve AND'in çıkışı 0 olur.

İkinci çözüm: XNOR'lar yerine XOR kullanılır ve NOT'lar AND'in girişlerine kaydırılır. AND'in bütün girişleri tümlenmişse ($\bar a \bar b \bar c \bar d$), De Morgan ile:

$$\bar a \bar b \bar c \bar d = \overline{a + b + c + d}$$

Bu bir NOR kapısıdır. Slayttaki devre de dört XOR ve bir NOR kapısından oluşur: "1 if A = B, 0 if A != B" (ekrandan, 02:20:00). İki çözüm (XNOR + AND ve XOR + NOR) birbirinin eşdeğeridir.

## 12. Üç durumlu tampon (tri-state buffer)

### 12.1 Neden gerekli?

Bir mikroişlemcinin bir veri yolu ve bir adres yolu vardır. Adres yolu işlemci açısından çıkış, diğer bütün elemanlar açısından giriştir; çift yön yoktur. Veri yoluna ise RAM, ROM, seri ve paralel haberleşme cihazları, zamanlayıcı gibi birçok cihaz bağlıdır ve veri iki yönde (okuma ya da yazma) akabilir. Aynı anda birden fazla cihaz işlemciyle konuşmaya çalışırsa çakışma olur.

Çözüm: işlemci bağlı her cihazı önceden belirli bir adres aralığına yerleştirir. Bir cihaza erişmek için o adres aralığıyla ilgili bir komut yürütüldüğünde harici bir adres çözümleme devresi yalnız o cihazı etkinleştirir, diğerlerini devre dışı bırakır. Böylece bir anda işlemciyle tek bir cihaz konuşur; geçişler hızlı olduğu için ortalamada aynı anda birçok cihazla konuşuyormuş gibi görünür. Tri-state buffer, fiziksel olarak hatta bağlı olan cihazların hatta bir şey gönderememesini ya da hattan bir şey alamamasını sağlamak için kullanılır.

### 12.2 Çalışma

Buffer'ın $x$ girişi (örneğin işlemcinin bir veri ucu), $f$ çıkışı (örneğin bir G/Ç cihazının veri ucu) ve $e$ kontrol ucu vardır (ekrandan, 02:25:00):

| $e$ | $x$ | $f$ |
|---|---|---|
| 0 | 0 | Z |
| 0 | 1 | Z |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

$e = 0$ iken $f$ ucunda $Z$ ile gösterilen yüksek empedans oluşur. Hoca, devre teorisi dersinden empedansı hatırlattı: empedans, AC sinyallerde devre elemanının akıma gösterdiği direnç benzeri büyüklüktür. En yüksek empedans, ucun hattan fiziksel olarak koparılmasına (sonsuz direnç) karşılık gelir. Yüksek empedansta uç fiziksel olarak bağlı olsa da yeterince büyük bir direnç gösterir, yani pratikte $x$ ile $f$ arasındaki bağlantı kopmuş olur (açık devre). $e = 1$ iken $x$'teki değer $f$'ye aktarılır; bağlantı kısa devre bir elemanla sağlanmış gibidir. Ters yönde bir buffer daha konursa okuma ve yazma yönleri ayrı ayrı kontrol edilebilir.

### 12.3 Dört çeşit tri-state buffer

Girişi, çıkışı ya da enable'ı aktif 0 olan çeşitler vardır (ekrandan, 02:30:00):

- (a) Aktif 1 enable, düz çıkış: $e = 1$ iken $f = x$.
- (b) Aktif 1 enable, aktif 0 (tümleyen) çıkış: $e = 1$ ve $x = 0$ iken $f = 1$.
- (c) Aktif 0 enable, düz çıkış: devreyi etkinleştirmek için $e = 0$ verilir; $x = 0$ iken $f = 0$.
- (d) Aktif 0 enable, aktif 0 çıkış: $e = 0$ ve $x = 1$ iken $f = 0$.

## 13. Ardışıl devreler: latch ve flip-flop

### 13.1 Ardışıl devre nedir?

Ardışıl devreler hafızalı devrelerdir: önceki durumları hafızada tutar ve yeni durumu hem yeni girişlere hem hafızadaki önceki duruma göre üretir. Yapı olarak bir kombinasyonel lojik blok ile önceki durumları tutan hafıza elemanlarından oluşur. Yalnız kombinasyonel devreden oluşan bir tasarımda aynı giriş her zaman aynı çıkışı verir. Ardışıl devrede ise iki farklı anda aynı giriş verilse bile hafızadaki değerler farklılaştığı için farklı çıkış elde edilebilir.

Hafıza elemanları temelde flip-flop'lardır; çok benzer bir yapı da latch'tir (tutucu).

> **Hocanın vurgusu:** Latch'te enable ucu seviye tetiklemeli çalışır. Flip-flop'ta enable ucu bir saat (clock) işaretine dönüşür ve devre saatin yükselen ya da düşen kenarında tetiklenir.

### 13.2 SR latch ve geri besleme

Hafıza elemanlarının kombinasyonel devrelerde olmayan özelliği geri beslemedir: bir kapının çıkışı kendisine ya da başka bir elemana geri verilir (ekrandan, 02:35:00).

Hoca, çapraz bağlı kapı çiftini NOR kapısı olarak çözümledi:

- Bir NOR kapısının girişlerinden biri 1 ise diğerine bakmadan çıkış 0 olur.
- Girişlere 0,1 verilsin. 1 alan kapının çıkışı 0 olur; bu 0 geri beslenir, diğer kapı 0 ile 0'ın NOR'unu alıp 1 üretir; bu 1 de ilk kapıya döner ve 1 ile 1'in NOR'u yine 0'dır. Döngü kararlı bir duruma oturur ve $Q$'da 1 saklanır.
- Girişlere 1,0 verilirse aynı akıl yürütmeyle kararlı bir durumda $Q = 0$ olur.
- Bu durumlardan sonra girişler 0,0'a çekilirse çıkış değişmez: 0 saklanıyorsa 0, 1 saklanıyorsa 1 kalır.
- Hoca 1,1 durumunun izin verilmeyen durum olduğunu belirtti.

Böylece istenen zaman çıkışta 0, istenen zaman 1 üretilebilir ve istenen zaman üretilen değer sabit tutulabilir.

> **Ders sonrası not:** Hocanın çözümlemesi (girişler 0,0 iken durum korunur, 1,1 yasak) NOR tabanlı SR latch için doğrudur. Slayttaki devrede çapraz bağlı kapılar ise NAND kapılarıdır ve girişleri $R'$, $S'$ diye aktif 0 gösterilmiştir. NAND tabanlı latch'te aktif 0 girişler 1,1 iken durum korunur, 0,0 izin verilmeyen durumdur. Hocanın anlattığı davranış büyük olasılıkla NOR sürümüne aittir; saatli devrenin karakteristik tablosu iki yapıda da aynıdır.

Bu yapı bir enable ya da saat işaretiyle birleştirilmek istenirse önüne saatle kontrol edilen bir katman eklenir ve saatli SR latch elde edilir. Slayttaki karakteristik tablo (ekrandan, 02:35:00):

| Clk | S | R | $Q(t+1)$ |
|---|---|---|---|
| 0 | x | x | $Q(t)$ (değişmez) |
| 1 | 0 | 0 | $Q(t)$ (değişmez) |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | x |

Saatli SR latch tek bir kontrol girişiyle sürülürse (S'ye $D$, R'ye $\bar D$) D latch elde edilir. D latch'in karakteristik tablosu: $Clk = 0$ iken $Q(t+1) = Q(t)$; $Clk = 1$ iken $Q(t+1) = D$. Bu yapılar latch'tir, çünkü saat (enable) işaretini seviye olarak alırlar.

### 13.3 D latch ile D flip-flop farkı: zaman diyagramı

D latch ya da D flip-flop'ta saat işareti uygun seviyede ya da kenarda geldiğinde $D$'deki değer çıkışa aktarılır; saat kalkınca içeride kopyalanan değer saklanır.

- **Latch (transparent latch):** Saat 1 iken $D$'de ne olursa olsun aynısı çıkışa yansır. Giriş ile çıkış arasında kapılar ve geri beslemeden kaynaklanan küçük bir yayılma gecikmesi (propagation delay) vardır.
- **Flip-flop:** Durum değişimi yalnız saatin yükselen kenarında olur. Başta $Q = 0$ olsun ve $D$ saat gelmeden 1'e çıksın: $Q$ değişmez. Saatte bir yükselen kenar yakalanınca $D$ örneklenir ve çıkışa aktarılır. Bir sonraki yükselen kenara kadar $D$'de ne kadar değişiklik olursa olsun $Q$ değişmez.

Şemada saat girişindeki üçgen yükselen kenarda tetiklemeyi, önünde bir yuvarlak bulunan üçgen düşen kenarda tetiklemeyi gösterir.

## 14. Preset ve clear: asenkron ve senkron başlangıç değeri

### 14.1 Asenkron preset ve clear

Lojik devreler deneylerinde kullanılan flip-flop entegrelerinde preset ve clear uçları vardı; bunlar flip-flop'a başlangıç değeri vermek için kullanılır. Bu uçlar aktif 0'dır (ekrandan, 02:45:00):

- Preset ve clear ikisi de 1 iken flip-flop normal çalışır.
- Preset 0'a çekilirse $Q$ 1'e kurulur; preset tekrar 1'e alınınca normal çalışmaya dönülür.
- Clear 0'a çekilirse $Q$ 0'a kurulur; clear tekrar 1'e alınınca başlangıç değeri 0 olarak çalışmaya başlanır.

Slayt: "Bubble on the symbol means active-low"; "Preset and Clear also known as Set and Reset respectively"; "In this circuit, preset and clear are asynchronous: Q changes immediately when preset or clear are active, regardless of clock".

Normalde $D$'deki değere göre çıkışın değişmesi için bir yükselen kenar gerekir. Preset ve clear ise saat işareti gelmeden $Q$'da bir başlangıç değeri oluşturabilir. Bu yüzden asenkron preset ve clear diye adlandırılır.

### 14.2 Senkron clear

Bir başka seçenek: clear komutu hazırlanır, ama değişiklik ancak saat vurduğunda olur. Buna senkron clear (senkron reset) denir. Bunu yapmak için $D$ girişi clear kontrol işaretiyle AND'lenir: flip-flop'un girişi $Clear \cdot D$ olur.

Örnekte $D$ verilen biçimde değişiyor, saat belirli periyotlarla geliyor ve yükselen kenarda tetikleme var. Clear ucu 0'a inince $Clear \cdot D$ de 0'a iner, ama bunun etkisi hemen görülmez. Etki bir sonraki yükselen kenarda gösterilir ve o kenardan küçük bir yayılma gecikmesi sonra $Q$ 0'a çekilir. Asenkron clear kullanılsaydı $Q$ clear 0'a iner inmez sıfırlanırdı.

Senkron, saat darbesiyle eş anlı, yani saatin yükselen ya da düşen kenarında gerçekleşen demektir.

**Soru:** Saat 0'a inerken (düşen kenarda) çalışan flip-flop'lar da senkron mu olur? **Cevap:** Saatin aktif olduğu anda durum geçişi yapan her şey senkrondur. Senkron clear örneğinde düşen kenarda tetiklenen bir flip-flop kullanılsaydı bu da senkron clear olurdu, yalnız saatin düşen kenarında gerçekleşirdi. Daha geniş anlamda, senkron ardışıl devre tasarımında kullanılan bütün flip-flop'lara aynı saat işareti bağlıdır ve hepsi aynı yönlü kenarda tetiklenir.

**Soru:** Ripple toplayıcıda gecikme yüzünden sonuç çevrime yetişmeyebiliyor; alternatif yöntem nasıl çalışır? **Cevap:** Ripple toplayıcıda her blok yalnız kendi anlam sırasındaki bitlerle ilgilenir ve eldeyi bir sonrakine aktarır. Look-ahead yaklaşımında ise örneğin iki 4 bitlik sayının toplam 8 bitinin durumu aynı anda tek bir kombinasyonel devrede değerlendirilir; girişler verildiği anda doğru çıkış bir seferde oluşur.

> **Ek bilgi (derste anlatılmadı):** Carry look-ahead toplayıcıda her basamak için üretme $g_i = a_i b_i$ ve yayma $p_i = a_i \oplus b_i$ terimleri tanımlanır ve eldeler $c_{i+1} = g_i + p_i c_i$ bağıntısı açılarak doğrudan girişler cinsinden yazılır (örneğin $c_2 = g_1 + p_1 g_0 + p_1 p_0 c_0$). Böylece eldeler basamak basamak beklemeden, iki düzeyli lojikle aynı anda hesaplanır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): 2'ye 1 MUX'lardan gerekli sayıda kullanarak 4'e 1 MUX kurunuz. Hangi seçim ucunun $s_0$, hangisinin $s_1$ olduğunu nasıl anlarsınız?

> **Çözüm (derste verildi):** İlk katmanda iki 2'ye 1 MUX ($w_0, w_1$ ve $w_2, w_3$), seçim uçları ortak; ikinci katmanda bir 2'ye 1 MUX. Toplam 3 MUX. İlk katmana bağlı uç değişince seçilen giriş bir basamak kaydığı için o uç $s_0$, ikinci katmana bağlı uç değişince iki basamak kaydığı için o uç $s_1$'dir.

**Soru 2** (derste sözlü, 00:13:19): 4'e 1 MUX'lar kullanarak 16'ya 1 MUX kaç MUX ile kurulur?

> **Çözüm (derste verildi):** İlk katmanda 4, son katmanda 1; toplam 5 tane 4'e 1 MUX.

**Soru 3** (ekrandan, 00:25:00 ve 00:30:00): $f(a,b)$ fonksiyonu 00 için 0, 01, 10, 11 için 1 olsun. Bu fonksiyonu (a) aktif 1 çıkışlı bir 2x4 dekoder ve bir OR kapısıyla, (b) aktif 0 çıkışlı ve aktif 0 enable'lı bir 2x4 dekoderle gerçekleyiniz.

> **Çözüm (derste verildi):** (a) $f = \bar a b + a \bar b + ab$. $a \to w_1$, $b \to w_0$, $En = 1$; $y_1$, $y_2$, $y_3$ bir OR kapısına bağlanır. (b) $f = a + b$, yani 0. maksterm. $\bar E = 0$, $a \to w_1$, $b \to w_0$; $\bar y_0$ çıkışı $f$'dir.

**Soru 4** (ekrandan, 00:30:00): Aktif 0 enable'lı ve aktif 0 çıkışlı 2x4 dekoderin doğruluk tablosunu yazıp her çıkışı $\bar E, w_1, w_0$ cinsinden ifade ediniz. Enable'ı görmezsek çıkışlar neye karşılık gelir?

> **Çözüm (derste verildi):** $\bar y_3 = \bar E + \bar w_1 + \bar w_0$, $\bar y_2 = \bar E + \bar w_1 + w_0$, $\bar y_1 = \bar E + w_1 + \bar w_0$, $\bar y_0 = \bar E + w_1 + w_0$. Enable görülmezse çıkışlar sırasıyla 3., 2., 1. ve 0. makstermlerdir.

**Soru 5** (ekrandan, 01:10:00 ve 01:15:00): 4'e 2 enkoderin doğruluk tablosundan $y_1$ ve $y_0$'ı en sade biçimde bulunuz. Mintermlerden doğrudan yazınca neden karmaşık bir devre çıkar?

> **Çözüm (derste verildi):** Dört değişkenli fonksiyonun 16 satırından 12'si don't care'dir. Karnaugh haritasında 8'li gruplarla $y_1 = w_2 + w_3$, $y_0 = w_1 + w_3$ bulunur. Mintermlerden doğrudan yazmak don't care satırlarını kullanmadığı için uzun terimler verir.

**Soru 6** (ekrandan, 01:45:00): Tam toplayıcıyı yalnız yarım toplayıcılarla (OR kapısı kullanmadan) kurabilir misiniz?

> **Çözüm (derste verildi):** İki yarım toplayıcılı yapıdaki OR kapısının yerine üçüncü bir yarım toplayıcı konur; iki elde bu yarım toplayıcıya girer, onun toplam çıkışı $C_{out}$ olarak kullanılır, elde çıkışı boşta kalır. İki elde aynı anda 1 olamadığı için XOR, OR ile aynı sonucu verir.

**Soru 7** (derste sözlü, 02:16:26): Toplayıcı-çıkarıcı devresinde, kontrol 1 iken $x$'in değilini, kontrol 0 iken $x$'in kendisini veren kapı hangisidir?

> **Çözüm (derste verildi):** XOR kapısı: $x \oplus 1 = \bar x$, $x \oplus 0 = x$. $+1$ ise kontrol ucunun toplayıcının $c_0$ girişine bağlanmasıyla sağlanır.

**Soru 8** (ekrandan, 02:20:00): 4 bitlik $A$ ve $B$ sayılarının eşitliğini veren karşılaştırıcıyı tasarlayınız.

> **Çözüm (derste verildi):** Her bit çifti XNOR'lanır ve dört sonuç AND'lenir. Eşdeğer olarak bit çiftleri XOR'lanıp bir NOR kapısında birleştirilir (slayttaki devre).

## Dersin Toparlaması

Bu derste kombinasyonel devre blokları tekrar edildi ve her bloğun iç yapısı, istenen davranışı veren doğruluk tablosundan çarpımlar toplamı (ya da toplamlar çarpımı) yaklaşımıyla kuruldu. Küçük MUX ve dekoderlerden büyük bloklar kurulurken seçim uçlarının anlam sırasının, ucu değiştirince çıkışın kaç basamak kaydığına bakılarak bulunduğu görüldü. Dekoder çıkışlarının minterm ya da maksterm olması, dekoderle her lojik fonksiyonun gerçeklenebileceğini gösterdi. Enkoderde don't care satırlarının, tam toplayıcıda ise ortak XOR kapısının kullanılması sade ve az kapılı devreler verdi. Çok bitli bloklarda veri yolu gösterimi, $n + 1$ bitlik toplam, ripple carry gecikmesinin saat frekansına etkisi, toplayıcı-çıkarıcı ve karşılaştırıcı ele alındı. Tri-state buffer'ın ortak veri yolunda aynı anda tek cihazın konuşmasını nasıl sağladığı anlatıldı.

Son bölümde ardışıl devrelere geçildi: latch ile flip-flop arasındaki seviye ve kenar tetikleme farkı, SR ve D latch, D flip-flop, asenkron preset/clear ve senkron clear işlendi. Sonraki derste senkron ardışıl devre tasarımı hatırlanacak, ardından çok bitli senkron ardışıl devre blokları ve işlevleri incelenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
