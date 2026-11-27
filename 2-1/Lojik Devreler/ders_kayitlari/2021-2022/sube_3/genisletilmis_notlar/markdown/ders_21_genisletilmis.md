# Ders 21 Genişletilmiş Notu: Seçiciler, Dağıtıcılar, Kod Çözücüler, Kodlayıcılar ve ALU

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Seçiciler (multiplexer, MUX)
- 2. MUX ile Boole fonksiyonu gerçekleme
- 3. Seçim uçlarının seçimi ve maliyet
- 4. MUX çıkış ifadesi
- 5. Dağıtıcılar (demultiplexer, DEMUX) ve santral örneği
- 6. Kod çözücü (decoder)
- 7. Kod çözücüyle tam toplayıcı
- 8. Kodlayıcı (encoder)
- 9. Aritmetik Lojik Birim (ALU)
- 10. Yedi parçalı gösterge sürücüsü
- 11. Tampon (buffer) ve yüksek empedans
- Örnek Sorular
- Dersin Toparlaması

## 1. Seçiciler (multiplexer, MUX)

Bir önceki derste toplayıcı, çıkarıcı ve toplayıcı-çıkarıcı devreleri görülmüştü. Bu derste sayısal haberleşmede ve sayısal devrelerde çok kullanılan özel kombinezonsal devre elemanlarına geçilir. İlki seçicidir; İngilizcesi multiplexer, kısaca MUX'tur.

Genel olarak $2^n \times 1$ MUX, $2^n$ girişli ve tek çıkışlı bir devre elemanıdır. Girişler $I_0$'dan $I_{2^n-1}$'e kadar numaralanır, çıkışa $Z$ denir. Devrenin amacı girişlerden birini seçip çıkışa iletmektir. Hangi girişin seçileceğini seçim uçları belirler. $2^n$ giriş varsa $n$ seçim ucu gerekir ($S_{n-1} \ldots S_0$); $n$ bit ile $2^n$ farklı değer tanımlanabilir ve her değer bir girişi seçer (ekrandan, 00:10:00).

### 1.1 4×1 MUX

Basit bir uygulama olarak $4 \times 1$ MUX çizilir: dört giriş ($I_0, I_1, I_2, I_3$), bir çıkış ($Z$) ve iki seçim ucu ($S_1$, $S_0$). Seçim uçlarının alabileceği dört değer ve karşılık gelen sayısal değer şöyledir (ekrandan, 00:10:00):

| $S_1$ | $S_0$ | Sayısal değer | Çıkışa aktarılan |
|---|---|---|---|
| 0 | 0 | 0 | $I_0$ |
| 0 | 1 | 1 | $I_1$ |
| 1 | 0 | 2 | $I_2$ |
| 1 | 1 | 3 | $I_3$ |

Hoca bunu içeride bir anahtar varmış gibi düşünmeyi önerdi: seçim uçlarıyla anahtar istenen girişe çevrilir ve o giriş çıkışa aktarılır.

## 2. MUX ile Boole fonksiyonu gerçekleme

### 2.1 Soru

Dört değişkenli bir fonksiyonun doğruluk tablosu verilmiştir (ekrandan, 00:15:00). $X_1$ en ağırlıklı, $X_4$ en az ağırlıklı bittir.

| $X_1X_2X_3X_4$ | $f$ | $X_1X_2X_3X_4$ | $f$ |
|---|---|---|---|
| 0000 | 0 | 1000 | 1 |
| 0001 | 0 | 1001 | 1 |
| 0010 | 1 | 1010 | 1 |
| 0011 | 1 | 1011 | 1 |
| 0100 | 0 | 1100 | 0 |
| 0101 | 1 | 1101 | 0 |
| 0110 | 0 | 1110 | 0 |
| 0111 | 1 | 1111 | 0 |

Yani $f = \sum m(2,3,5,7,8,9,10,11)$. İstenen: bu devrede $4 \times 1$ MUX kullanarak $f$ fonksiyonunu gerçekleyiniz; $X_3$ ve $X_4$ seçim uçları olsun.

Normalde böyle bir fonksiyon için önce Karnaugh haritası çizilir, indirgenir ve bilinen kapılarla devre kurulur. Burada farklı bir tasarım yöntemi kullanılır: temel eleman MUX'tur, MUX girişlerine gerekli kapılar bağlanır.

### 2.2 Bit sırası ve seçim uçları

Hoca kitaptaki örnekte indislerin alışılmış sırada olmadığına dikkat çekti: normalde en ağırlıklı bit sola yazılır; burada en ağırlıklı bit $X_1$, en az ağırlıklı bit $X_4$'tür. $X_3$ ve $X_4$ seçim ucu olacaksa daha ağırlıklı olan $X_3$ $S_1$'e, daha az ağırlıklı olan $X_4$ $S_0$'a bağlanır. MUX'ta en az ağırlıklı giriş $I_0$, en yüksek ağırlıklı giriş $I_3$'tür.

> **Hocanın vurgusu:** İndislerin sırasına muhakkak dikkat edin; düşük ağırlıklı seçim biti $S_0$'a gelmelidir.

### 2.3 Mintermleri yazma ve paranteze alma

Önce fonksiyon mintermlerin toplamı olarak yazılır (ekrandan, 00:20:00):

$$f = \overline{X_1}\,\overline{X_2}X_3\overline{X_4} + \overline{X_1}\,\overline{X_2}X_3X_4 + \overline{X_1}X_2\overline{X_3}X_4 + \overline{X_1}X_2X_3X_4 + X_1\overline{X_2}\,\overline{X_3}\,\overline{X_4} + X_1\overline{X_2}\,\overline{X_3}X_4 + X_1\overline{X_2}X_3\overline{X_4} + X_1\overline{X_2}X_3X_4$$

Seçim uçları $X_3$, $X_4$ olduğuna göre bu iki değişkenin dört kombinasyonu ($\overline{X_3}\,\overline{X_4}$, $\overline{X_3}X_4$, $X_3\overline{X_4}$, $X_3X_4$) ortak paranteze alınır. Parantez içinde kalan ifadeler MUX'un girişlerine bağlanacak ifadelerdir (ekrandan, 00:25:00):

$$f = \overline{X_3}\,\overline{X_4}\,(X_1\overline{X_2}) + \overline{X_3}X_4\,(\overline{X_1}X_2 + X_1\overline{X_2}) + X_3\overline{X_4}\,(\overline{X_1}\,\overline{X_2} + X_1\overline{X_2}) + X_3X_4\,(\overline{X_1}\,\overline{X_2} + \overline{X_1}X_2 + X_1\overline{X_2})$$

### 2.4 Sadeleştirme

- $\overline{X_3}\,\overline{X_4}$ parantezi: $X_1\overline{X_2}$ zaten en sade haldedir.
- $\overline{X_3}X_4$ parantezi: $\overline{X_1}X_2 + X_1\overline{X_2} = X_1 \oplus X_2$ (XOR).
- $X_3\overline{X_4}$ parantezi: $\overline{X_2}$ ortak paranteze alınır, $\overline{X_2}(\overline{X_1} + X_1) = \overline{X_2}$.
- $X_3X_4$ parantezi: önce $\overline{X_1}$ paranteze alınır, $\overline{X_1}(\overline{X_2} + X_2) + X_1\overline{X_2} = \overline{X_1} + X_1\overline{X_2}$. Dağıtma kuralıyla $(\overline{X_1} + X_1)(\overline{X_1} + \overline{X_2}) = \overline{X_1} + \overline{X_2}$ (ekrandan, 00:30:00).

Sonuç:

$$f = \overline{X_3}\,\overline{X_4}\,(X_1\overline{X_2}) + \overline{X_3}X_4\,(X_1 \oplus X_2) + X_3\overline{X_4}\,(\overline{X_2}) + X_3X_4\,(\overline{X_1} + \overline{X_2})$$

### 2.5 Giriş tablosu ve devre

Seçim değerine göre hangi terimin "çalıştığına" bakılır. Örneğin $X_3X_4 = 00$ geldiğinde yalnız ilk terim kalır, diğer bütün terimler 0 olur; dolayısıyla $I_0 = X_1\overline{X_2}$ olur (ekrandan, 00:30:00):

| $a$ | $X_3$ ($S_1$) | $X_4$ ($S_0$) | $I_a$ |
|---|---|---|---|
| 0 | 0 | 0 | $X_1\overline{X_2}$ |
| 1 | 0 | 1 | $X_1 \oplus X_2$ |
| 2 | 1 | 0 | $\overline{X_2}$ |
| 3 | 1 | 1 | $\overline{X_1} + \overline{X_2}$ |

Devre (ekrandan, 00:30:00):

```text
I0 <- VE(X1, X2')
I1 <- XOR(X1, X2)
I2 <- X2'
I3 <- VEYA(X1', X2')      (X1 ve X2 DEĞİL kapılarından geçer)
S1 <- X3,  S0 <- X4,  Z = f
```

Bu sonuç python ile 16 satırlık doğruluk tablosu üzerinden kontrol edildi.

**Soru:** Bu MUX ile tam olarak ne yaptık? **Cevap:** MUX ile verilen fonksiyonu gerçekledik. Normalde Karnaugh haritasından indirgenmiş ifadeyi bulup kapılarla devre kurardık. Burada mintermleri yazdık, seçim ucu olarak verilen $X_3X_4$'ün parantezlerini aldık ve girişlere ne bağlanacağını bulduk. Karnaugh ile indirgenmiş devre de $Z$ ucunda aynı çıkışı verir; MUX devresi çok verimli olmayabilir ama aynı sonucu üretir.

## 3. Seçim uçlarının seçimi ve maliyet

Aynı fonksiyon bu kez $X_1$ ($S_1$, daha ağırlıklı) ve $X_2$ ($S_0$) seçim uçlarıyla gerçeklensin. Bu durumda $\overline{X_1}\,\overline{X_2}$, $\overline{X_1}X_2$, $X_1\overline{X_2}$ ve $X_1X_2$ parantezleri alınır (ekrandan, 00:35:00):

$$f = \overline{X_1}\,\overline{X_2}\,(X_3\overline{X_4} + X_3X_4) + \overline{X_1}X_2\,(\overline{X_3}X_4 + X_3X_4) + X_1\overline{X_2}\,(\overline{X_3}\,\overline{X_4} + \overline{X_3}X_4 + X_3\overline{X_4} + X_3X_4) + X_1X_2\,(0)$$

$X_1 = X_2 = 1$ olan hiçbir minterm bulunmadığı için son parantez 0'dır. Sadeleştirme:

- $X_3(\overline{X_4} + X_4) = X_3$
- $X_4(\overline{X_3} + X_3) = X_4$
- Dört terimin toplamı: $\overline{X_3}(\overline{X_4} + X_4) + X_3(\overline{X_4} + X_4) = \overline{X_3} + X_3 = 1$
- Son grup: 0

$$f = \overline{X_1}\,\overline{X_2}\,X_3 + \overline{X_1}X_2\,X_4 + X_1\overline{X_2}\cdot 1 + X_1X_2\cdot 0$$

| $a$ | $X_1$ ($S_1$) | $X_2$ ($S_0$) | $I_a$ |
|---|---|---|---|
| 0 | 0 | 0 | $X_3$ |
| 1 | 0 | 1 | $X_4$ |
| 2 | 1 | 0 | 1 |
| 3 | 1 | 1 | 0 |

Böylece MUX'un girişlerine yalnız $X_3$, $X_4$, 1 ve 0 bağlanır; ek bir kapı gerekmez, devre tek bir MUX ile gerçeklenir (ekrandan, 00:40:00). Önceki çözümde VE, XOR, DEĞİL ve VEYA kapıları gerekiyordu. Bu sonuç da python ile kontrol edildi.

> **Hocanın vurgusu:** Seçim uçlarını belirlemek çok önemlidir; aynı fonksiyon yalnız seçim uçları değiştirilerek çok daha az maliyetle gerçeklenebilir. Bir de ifadeyi doğru yazmak önemlidir; sınavlarda MUX sorusu her zaman bu biçimde gelmeyebilir.

## 4. MUX çıkış ifadesi

Bir öğrenci son anlatılan kısmın tekrarını istedi. Hoca MUX'un çıkışını genel bir ifadeyle yazdı. Seçim uçları $x$ ($S_1$) ve $y$ ($S_0$) olan bir $4 \times 1$ MUX için:

$$Z = I_0\,\overline{x}\,\overline{y} + I_1\,\overline{x}\,y + I_2\,x\,\overline{y} + I_3\,x\,y$$

$I_0$'ın çıkışta görünmesi için $x = y = 0$ olmalıdır; $I_1$ için 01, $I_2$ için 10, $I_3$ için 11 gelmelidir. Hangi girişe ne bağlıysa (bir sabit 0 ya da 1, bir değişken ya da bir ifade) o terim seçim değeri uyduğunda çıkışa yansır. Örneğin bir girişe 1 bağlıysa o seçim değerinde çıkış doğrudan 1 olur; bir girişe $\overline{x}$ bağlıysa o seçim değerinde çıkışa $\overline{x}$ aktarılır (ekrandan, 00:40:00). <!-- BELİRSİZ: tahtadaki küçük örnek MUX'un (girişlerde 1 ve x̄) bütün bağlantıları ve hocanın bu örnek için yazdığı ifade tam okunamıyor -->

## 5. Dağıtıcılar (demultiplexer, DEMUX) ve santral örneği

### 5.1 Tanım

Dağıtıcı (DEMUX) seçicinin tersi mantıkla çalışır. MUX $2^n \times 1$ iken DEMUX $1 \times 2^n$'dir: tek bir girişi ($I$) vardır ve bu girişi çıkışlardan birine gönderir. Çıkışlar $Z_0$'dan $Z_{2^n-1}$'e kadar gider. Girişin hangi çıkışa gideceğini seçim uçları belirler. Seçim uçlarında $S_0$ en az ağırlıklı bit (LSB), en üstteki seçim ucu en ağırlıklı bittir (MSB); çıkışlarda $Z_0$ en az ağırlıklı, $Z_{2^n-1}$ en ağırlıklı çıkıştır (ekrandan, 00:45:00).

> **Ders sonrası not:** $2^n$ çıkış için $n$ seçim ucu gerekir; bunlar $S_0 \ldots S_{n-1}$ diye numaralanır. Tahtada en üstteki uç $S_n$ diye yazıldı; MUX tanımıyla tutarlı olan $S_{n-1}$'dir.

### 5.2 Basit bir santral

Hoca MUX ve DEMUX'un birlikte kullanımını basit bir telefon santrali örneğiyle anlattı (ekrandan, 00:50:00). Solda $2^n \times 1$ MUX vardır; girişleri $I_0 \ldots I_{2^n-1}$ konuşan abonelerin hatlarıdır. Ortada tek bir hat (medium: kablo, fiber vb.) vardır. Sağda $1 \times 2^n$ DEMUX bulunur; çıkışları $Z_0 \ldots Z_{2^n-1}$ karşı taraftaki abonelerdir. İki tarafın seçim uçlarını ayarlayan ortak bir seçici (santral arabirimi) vardır.

3 bitlik bir örnekte:

- Solda 000 seçilir: MUX $I_0$ abonesini hatta verir.
- Sağda 011 seçilir: DEMUX hattı $Z_3$ abonesine (sıfırdan sayınca 3 numaralı abone) aktarır. Böylece $I_0$ ile $Z_3$ konuşur.
- Sonra solda 010 seçilir: hattı $I_2$ abonesi alır. Sağda 101 seçilirse bu abone $Z_5$ ile görüşür.

Böylece tek bir hat, seçim uçları sırayla değiştirilerek çok sayıda abone arasında paylaşılır.

> **Ders sonrası not:** Hoca bir yerde sağ taraf için "0, 0, 1" ve "1, 1, 0" dedi; tahtada yazılan değer 011'dir ($Z_3$). Ayrıca hoca her tarafta "$2^n - 1$ abone" dedi; girişler $I_0 \ldots I_{2^n-1}$ olduğu için her tarafta $2^n$ abone vardır ($2^n - 1$ son abonenin numarasıdır).

Hoca bu elemanlarla yavaş yavaş ALU tasarımına doğru gidileceğini belirtti.

## 6. Kod çözücü (decoder)

### 6.1 Tanım

Kod çözücü, $n$ bitlik bir sözcüğün kodunu çözüp en çok $2^n$ çıkış yolundan yalnız birini aktif yapan kombinezonsal devredir. $n \times 2^n$ yapıdadır: $n$ giriş, $2^n$ çıkış. Hangi çıkışın aktif olacağını $n$ giriş bitinin değeri belirler.

### 6.2 3×8 kod çözücü

Girişler $X$ ($I_2$, en ağırlıklı), $Y$ ($I_1$), $Z$ ($I_0$); çıkışlar $D_0 \ldots D_7$ (ekrandan, 00:55:00):

| Sayısal değer | $XYZ$ | $D_7$ | $D_6$ | $D_5$ | $D_4$ | $D_3$ | $D_2$ | $D_1$ | $D_0$ |
|---|---|---|---|---|---|---|---|---|---|
| 0 | 000 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| 5 | 101 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 7 | 111 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

Kod çözücünün mantığı, verilen giriş değerine karşılık gelen çıkışı 1 yapmak, diğerlerini 0'da tutmaktır.

### 6.3 Tümleyen çıkışlı kod çözücü

Tümleyen çıkışlı kod çözücüde çıkışların ucunda değil işareti (yuvarlak) vardır. Normalde çıkışların hepsi 1'dir; seçilen çıkış 0 olur, yani 0 aktiftir. Tahtadaki örnekte giriş 111 iken $D_7 = 0$, diğer bütün çıkışlar 1'dir (ekrandan, 00:55:00). Normal kod çözücüde seçilen çıkış 1 aktiftir.

> **Ders sonrası not:** Hoca 7 girişi için anlatırken bir yerde "sadece $D_0$ 0 oldu" dedi; tahtadaki tabloda 0 olan çıkış $D_7$'dir. Doğrusu: 111 girişinde $D_7 = 0$, diğerleri 1.

## 7. Kod çözücüyle tam toplayıcı

Tam toplayıcının üç girişi ($a$, $b$, elde girişi $E_g$) ve iki çıkışı (toplam $T$, elde çıkışı $E$) vardır. Bir önceki derste bulunduğu gibi (ekrandan, 01:00:00):

$$T(a,b,E_g) = \sum m(1,2,4,7), \qquad E(a,b,E_g) = \sum m(3,5,6,7)$$

Tahtadaki doğruluk tablosu $E_g$ en ağırlıklı olacak sırayla yazıldı:

| Satır | $E_g\,a\,b$ | $T$ | $E$ |
|---|---|---|---|
| 0 | 000 | 0 | 0 |
| 1 | 001 | 1 | 0 |
| 2 | 010 | 1 | 0 |
| 3 | 011 | 0 | 1 |
| 4 | 100 | 1 | 0 |
| 5 | 101 | 0 | 1 |
| 6 | 110 | 0 | 1 |
| 7 | 111 | 1 | 1 |

Kod çözücünün her çıkışı bir minterm ürettiği için bu fonksiyonlar çok kolay kurulur: $3 \times 8$ kod çözücünün girişlerine $E_g$ (MSB), $a$, $b$ (LSB) bağlanır. $D_1, D_2, D_4, D_7$ çıkışları dört girişli bir VEYA kapısına bağlanınca toplam, $D_3, D_5, D_6, D_7$ çıkışları ikinci bir dört girişli VEYA kapısına bağlanınca elde çıkışı elde edilir. İçlerinden biri 1 olunca VEYA'nın çıkışı 1 olur (ekrandan, 01:05:00).

$$T = D_1 + D_2 + D_4 + D_7, \qquad E = D_3 + D_5 + D_6 + D_7$$

Dört girişli VEYA kapıları iki girişli VEYA kapılarından da kurulabilir; teorik olarak fonksiyon bir kod çözücü ve iki adet dört girişli VEYA ile gerçeklenmiş olur.

> **Ders sonrası not:** Hoca elde girişi sona ya da $a$ başa alınırsa farklı değerler çıkacağını, buna dikkat etmek gerektiğini söyledi. Genel fonksiyonlarda değişken sırası minterm numaralarını değiştirir. Ancak tam toplayıcının toplam ve elde fonksiyonları üç girişe göre simetrik olduğundan burada minterm listeleri sıradan etkilenmez; python ile her iki sıra için kontrol edildi.

## 8. Kodlayıcı (encoder)

Kodlayıcı kod çözücünün tersi mantıkla çalışır ve $2^n \times n$ dönüşüm yapar: girişler $I_0 \ldots I_{2^n-1}$, çıkışlar $Z_0 \ldots Z_{n-1}$'dir. Bir işareti başka bir lojik devrenin işleyebileceği biçime getiren devre olarak tanımlanır. 16, 10 ve 8 tabanlı sayılardan ikili sisteme dönüşüm yapan kodlayıcılar bu mantıkla çalışır (ekrandan, 01:15:00).

### 8.1 4×2 kodlayıcı

Girişler $I_3$ (MSB), $I_2$, $I_1$, $I_0$ (LSB); çıkışlar $X$, $Y$ ve bir de "Hazır" (Ready) ucudur. Ready, çıkışın oluştuğunu sonraki devreye bildirir; karşıdaki devre çıkışın geçerli olduğunu Ready'nin 1 olmasından anlar.

| $I_3I_2I_1I_0$ | $X$ | $Y$ | Ready |
|---|---|---|---|
| 0000 | $\phi$ | $\phi$ | 0 |
| 0001 | 0 | 0 | 1 |
| $001\phi$ | 0 | 1 | 1 |
| $01\phi\phi$ | 1 | 0 | 1 |
| $1\phi\phi\phi$ | 1 | 1 | 1 |

<!-- BELİRSİZ: tablonun yalnız ilk satırı karelerde görünüyor; diğer satırlar altyazıdan kuruldu -->

$\phi$ o girişin 0 ya da 1 olabileceği anlamına gelir. Örneğin ikinci basamak ($I_1$) 1 ise, sıfırıncı basamağın değeri ne olursa olsun çıkış 01'dir. Yani çıkış, 1 olan en yüksek basamağın numarasını verir; özellikle sayı dönüşümlerinde hangi basamakta değer olduğunu anlamak için kullanılır. Bütün girişler 0 iken devre hazır değildir (Ready = 0) ve $X$, $Y$ belirsizdir.

> **Ek bilgi (derste anlatılmadı):** Girişlerden birden fazlası 1 olduğunda en yüksek numaralı girişi esas alan bu tür kodlayıcıya genellikle öncelikli kodlayıcı (priority encoder) denir. Ready çıkışı literatürde çoğunlukla "geçerli" (valid, V) çıkışı diye de adlandırılır.

## 9. Aritmetik Lojik Birim (ALU)

### 9.1 Genel yapı

Öğrenilen sistemlerin hepsinin bir arada kullanıldığı, hem aritmetik hem lojik işlemlerin yapıldığı birim aritmetik lojik birimdir (Arithmetic Logic Unit, ALU). Genel gösterimi V biçiminde bir bloktur. En basit haliyle iki girişinden işlenecek iki sayı (A ve B, $n$ bit) gelir, çıkışı F ($n$ bit) olur. Hangi işlemin yapılacağını $m$ bitlik işlem kodu belirler; $m$ bit ile $2^m$ işlem tanımlanabilir (toplama, çıkarma, sola/sağa öteleme gibi). İşlemler arasında toplama varsa bir elde girişi ve bir elde çıkışı da tanımlanmalıdır.

Lojik şemalarda bir okun üzerine eğik çizgi çekilip yanına $n$ (örneğin 8) yazılırsa o yoldan $n$ bitin paralel taşındığı anlaşılır (ekrandan, 01:20:00).

### 9.2 Örnek: 4 işlemli ALU

Kitaptaki örnekte iki adet 4 bitlik veri alan, bir elde girişi olan ve bu veriler üzerinde 4 işlemden birini yapan bir ALU tasarlanmak istenir (ekrandan, 01:20:00):

- Veri girişleri: $A = a_3a_2a_1a_0$, $B = b_3b_2b_1b_0$
- Elde girişi $E_g$ ve elde çıkışı
- Sonuç: $F = F_3F_2F_1F_0$
- İşlem kodu: $M_1M_0$ (2 bit, dolayısıyla 4 işlem)

| $M_1M_0$ | İşlem |
|---|---|
| 00 | $F = A + B$ (toplama) |
| 01 | altyazıda söylenmedi (büyük olasılıkla $A - B$) <!-- BELİRSİZ: 01 işlem kodu altyazıda yok; blok sırasına göre büyük olasılıkla çıkarma --> |
| 10 | $F = \overline{A}$ (1'e tümleyen) |
| 11 | A'yı 1 bit sağa ötele (shift right) |

Sağa öteleme şöyle tanımlanır: $A_0$ elde çıkışından çıkar, $A_1 \to F_0$, $A_2 \to F_1$, $A_3 \to F_2$ ve elde girişindeki değer $F_3$'e geçer.

### 9.3 Kavramsal tasarım

Tasarımda dört blok kullanılır: tam toplayıcı (TT), tam çıkarıcı (TÇ), tümleyici ve öteleyici (ekrandan, 01:25:00).

- A girişi (4 bit) dört bloğun hepsine gider.
- B girişi (4 bit) yalnız tam toplayıcıya ve tam çıkarıcıya gider.
- Elde girişi (1 bit) tam toplayıcıya, tam çıkarıcıya (borç girişi olarak) ve öteleyiciye gider; tümleyiciye gitmez.

Her blok 4 bitlik bir sonuç üretir. Hangi sonucun kullanılacağını seçmek için MUX kullanılır. Her çıkış biti için bir $4 \times 1$ MUX gerekir, yani toplam dört adet $4 \times 1$ MUX; hepsinin seçim uçlarına $M_1$, $M_0$ bağlanır. Örneğin dört bloğun $F_3$ bitleri bir MUX'un $I_0 \ldots I_3$ girişlerine gider ve bu MUX asıl $F_3$'ü üretir; $F_2$, $F_1$, $F_0$ için de aynısı yapılır (ekrandan, 01:30:00). $M_1M_0 = 00$ seçildiğinde dört MUX da $I_0$'a bağlı tam toplayıcı çıkışlarını F'ye aktarır.

Elde çıkışı tam toplayıcıdan, tam çıkarıcıdan (borç) ve öteleyiciden gelebilir; tümleyiciden gelmez. Tahtada bunlar bir VEYA ile toplanarak elde çıkışı oluşturuldu. Bu, verilenlere göre hangi kombinezonsal devrelerin kurulacağını gösteren tamamen kavramsal bir tasarımdır.

**Soru:** Öteleyici işlemini kullanmak istediğimizde toplayıcı da elde çıkışı üretirse, ALU'nun elde çıkışında yine 1 görmez miyiz? **Cevap:** Doğru. Bütün blokların girişine aynı veri verildiği için seçilmeyen bir blok da elde çıkışı üretebilir ve VEYA ile toplanınca hatalı sonuç çıkar. Bunun yerine elde çıkışı için de bir $4 \times 1$ MUX kullanılabilir; seçim uçlarına yine $M_1$, $M_0$ bağlanır, toplayıcının elde çıkışı $I_0$'a, çıkarıcınınki $I_1$'e, öteleyicininki $I_3$'e verilir (tümleyici kullanılmaz). Kitapta toplama (VEYA) kullanılmış; ama o yapının doğru çalışması için seçilmeyen blokların elde çıkışı üretmeyecek biçimde kurulması gerekir.

## 10. Yedi parçalı gösterge sürücüsü

### 10.1 Gösterge

Elde edilen sonuçları göstermek için yedi parçalı gösterge (seven segment display) çok kullanılır. Hoca filmlerde bombaların üzerinde görülen göstergeleri örnek verdi. Parçalar a, b, c, d, e, f, g diye adlandırılan yedi LED'dir; bazılarında ondalık nokta için bir LED daha bulunur, ona girilmedi (ekrandan, 01:35:00).

```text
  aaa
 f   b
 f   b
  ggg
 e   c
 e   c
  ddd
```

Her parça bir LED'dir. LED'in diğer ucu ortak toprağa bağlıdır; bir parçaya 1 vermek o uca (örneğin 5 V) gerilim uygulamak demektir ve LED yanar. 0 verilince diyot gerilimi oluşmaz, o parça yanmaz.

### 10.2 Sürücü devresinin doğruluk tablosu

Tasarlanan şey göstergenin kendisi değil, onu süren kombinezonsal devredir. Bu devre 4 bitlik bir girişi ($X_1X_2X_3X_4$, $X_1$ en ağırlıklı) a–g çıkışlarına çevirir. 10 rakam yazılacaktır; 3 bit ile yalnız $2^3 = 8$ değer yazılabildiği için 4 bit gerekir. 4 bit $2^4 = 16$ değer verir, 6'sı boşta kalır (ekrandan, 01:35:00).

Tahtada yazılan satırlar (ekrandan, 01:40:00):

| $X_1X_2X_3X_4$ | a | b | c | d | e | f | g |
|---|---|---|---|---|---|---|---|
| 0000 (0) | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
| 0001 (1) | 0 | 1 | 1 | 0 | 0 | 0 | 0 |
| … | | | | | | | |
| 1001 (9) | 1 | 1 | 1 | 1 | 0 | 1 | 1 |
| 1010 … 1111 | $\phi$ | $\phi$ | $\phi$ | $\phi$ | $\phi$ | $\phi$ | $\phi$ |

- 0 için a, b, c, d, e, f yanar; g yanmaz.
- 1 için yalnız b ve c yanar.
- 9 için e dışındaki bütün parçalar yanar.
- 2 için a, b, g, e, d yanar; diğerleri 0'dır.
- 10–15 girişleri hiç verilmeyeceği için önemsiz durumdur (don't care): "ne yanarsa yansın". Devreye yalnız 0–9 girişlerinin verileceği garanti edilmelidir.

### 10.3 Karnaugh haritası

Her çıkış için ayrı bir Karnaugh haritası çıkarılır. Derste yalnız a çıkışı için harita çizildi; önemsiz durumlar 1 sayılarak büyük komşuluklar kuruldu. Tahtada bulunan sonuç (ekrandan, 01:45:00):

$$a = X_1 + \overline{X_2}\,\overline{X_4} + X_2X_4 = X_1 + (X_2 \odot X_4)$$

**Soru:** a sütununda yalnız iki tane 1 yok mu? **Cevap:** Aradaki satırlar (2–8) atlandı, tablo yalnız 0, 1, 9 ve önemsiz durumlarla yazıldı; aradaki değerleri öğrenciler kendisi tamamlamalı. Örneğin 0010 (2) için a, b, g, e, d parçalarına 1 verilir.

> **Ders sonrası not:** Tahtadaki ifade yalnız doldurulan satırlara göredir. 0–9 satırlarının tamamı yazıldığında 3 (0011) ve 6 (0110) rakamlarında da a parçası yanar; bunları kapsamak için $X_3$ terimi gerekir: $a = X_1 + X_3 + (X_2 \odot X_4)$. Bu ifade python ile 0–9 için kontrol edildi; tahtadaki ifade 3 ve 6 için yanlış sonuç verir.

## 11. Tampon (buffer) ve yüksek empedans

### 11.1 Çıkışlar neden doğrudan birleştirilmez

Bir kombinezonsal devrenin çıkışı başka bir devreye giriş olarak bağlanabilir. Ancak iki ayrı devrenin çıkışları aynı girişe doğrudan bağlanmaz. Örneğin birinci çıkış 1, ikinci çıkış 0 verirse birinde yüksek, ötekinde düşük gerilim vardır ve devre doğrudan bunların arasından tamamlanır (ekrandan, 01:45:00). İki çıkışla aynı yere ulaşmak gerekiyorsa tampon (buffer) kullanılır.

### 11.2 Tampon

Tampon, DEĞİL kapısına benzer bir üçgenle gösterilir (ucunda yuvarlak yoktur). Bir girişi, bir çıkışı ve bir çıkış izni (enable) ucu vardır. İki türü vardır (ekrandan, 01:50:00):

1 aktif tampon (çıkış izni 1 iken çıkışı verir):

| Çıkış izni | Giriş | Çıkış |
|---|---|---|
| 0 | 0 | yüksek empedans |
| 0 | 1 | yüksek empedans |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

0 aktif tampon (çıkış izni ucunda yuvarlak vardır, 0 iken çıkışı verir):

| Çıkış izni | Giriş | Çıkış |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | yüksek empedans |
| 1 | 1 | yüksek empedans |

### 11.3 Yüksek empedans

Çıkışın yüksek empedans olması, çıkışta çok büyük bir direnç varmış gibi davranması demektir; bu çıkıştan akım akmaz. En büyük yüksek empedans hattın kesilmesi, yani araya havanın girmesidir. İki çıkış aynı hatta bağlıysa ve biri yüksek empedanstaysa akım yalnız öteki çıkıştan akar. Tamponlarla aynı yolu kullanan iki çıkıştan biri iptal edilmiş olur; yüksek empedans devreyi oradan koparmak, çıkışı aktarmamak demektir.

> **Hocanın vurgusu:** Aynı hatta (ortak yola) bağlanacak devre elemanlarında 1) tamponlar ya da 2) pull-up dirençleri kullanılır. Pull-up direnci, çıkışın açık kolektörlü yapıldığı elektronikle ilgili bir yapıdır; şimdilik yalnız bilgi olarak bilinmesi yeterli.

> **Ek bilgi (derste anlatılmadı):** Çıkışı 0, 1 ya da yüksek empedans (Z) olabilen bu tür tamponlara üç durumlu (tri-state) tampon denir. Bilgisayarlardaki ortak veri yolları (bus) çoğunlukla üç durumlu tamponlarla kurulur; her an yalnız bir kaynağın çıkış izni aktif tutulur.

## Örnek Sorular

### Soru 1 (ekrandan, 00:15:00)

$f(X_1,X_2,X_3,X_4) = \sum m(2,3,5,7,8,9,10,11)$ doğruluk tablosuyla verilmiştir ($X_1$ en ağırlıklı bit). Bu devrede $4 \times 1$ MUX kullanarak $f$ fonksiyonunu gerçekleyiniz. $X_3$ ve $X_4$ seçim uçları olsun.

> **Çözüm (derste verildi):** $S_1 = X_3$, $S_0 = X_4$; $I_0 = X_1\overline{X_2}$, $I_1 = X_1 \oplus X_2$, $I_2 = \overline{X_2}$, $I_3 = \overline{X_1} + \overline{X_2}$. Ayrıntılar Bölüm 2'de.

### Soru 2 (derste sözlü, 00:30:21)

Aynı fonksiyonu seçim uçları $X_1$ ($S_1$) ve $X_2$ ($S_0$) olacak şekilde gerçekleyiniz.

> **Çözüm (derste verildi):** $I_0 = X_3$, $I_1 = X_4$, $I_2 = 1$, $I_3 = 0$; ek kapı gerekmez. Ayrıntılar Bölüm 3'te.

### Soru 3 (ekrandan, 01:00:00)

Tam toplayıcıyı ($T = \sum m(1,2,4,7)$, $E = \sum m(3,5,6,7)$) bir kod çözücü kullanarak gerçekleyiniz.

> **Çözüm (derste verildi):** $3 \times 8$ kod çözücü, girişler $E_g$ (MSB), $a$, $b$ (LSB); $T = D_1 + D_2 + D_4 + D_7$, $E = D_3 + D_5 + D_6 + D_7$ (iki adet dört girişli VEYA). Ayrıntılar Bölüm 7'de.

### Soru 4 (ekrandan, 01:20:00)

İki adet 4 bitlik veri ($A$, $B$) alan, bir elde girişi olan ve 2 bitlik işlem koduna ($M_1M_0$) göre 4 işlemden birini (00: $A + B$, 10: $\overline{A}$, 11: A'yı 1 bit sağa ötele) yapan bir ALU'nun kavramsal tasarımını çiziniz. <!-- BELİRSİZ: 01 işleminin metni altyazıda yok; büyük olasılıkla A − B -->

> **Çözüm (derste verildi):** Tam toplayıcı, tam çıkarıcı, tümleyici ve öteleyici blokları paralel kurulur; her çıkış biti için bir $4 \times 1$ MUX (toplam dört), seçim uçları $M_1M_0$. Elde çıkışı için de bir $4 \times 1$ MUX kullanılabilir. Ayrıntılar Bölüm 9'da.

### Soru 5 (ekrandan, 01:35:00)

4 bitlik BCD girişini ($X_1X_2X_3X_4$) yedi parçalı göstergenin a–g parçalarını süren çıkışlara çeviren kombinezonsal devrenin doğruluk tablosunu kurunuz ve a çıkışını Karnaugh haritasıyla indirgeyiniz.

> **Çözüm (derste kısmen verildi, tamamlandı):** Derste 0, 1, 9 satırları ve önemsiz durumlar yazıldı, tahtada $a = X_1 + (X_2 \odot X_4)$ bulundu. 0–9 satırlarının tamamıyla ($a = 1$: 0, 2, 3, 5, 6, 7, 8, 9; önemsiz: 10–15) sonuç $a = X_1 + X_3 + X_2X_4 + \overline{X_2}\,\overline{X_4}$ olur (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste toplayıcı ve çıkarıcıdan sonra sayısal sistemlerin temel kombinezonsal yapı taşları işlendi. Seçici (MUX) seçim uçlarıyla girişlerden birini çıkışa aktarır; mintermler seçim değişkenlerine göre ortak paranteze alınarak herhangi bir fonksiyon MUX ile gerçeklenebilir ve seçim uçlarının iyi seçilmesi maliyeti çok düşürür. Dağıtıcı (DEMUX) bunun tersini yapar; MUX ve DEMUX birlikte tek bir hattı birçok kullanıcı arasında paylaştırır. Kod çözücü her girişe karşılık tek bir çıkışı aktif yaparak mintermleri üretir; VEYA kapılarıyla birlikte tam toplayıcı gibi fonksiyonları kurmaya yeter. Kodlayıcı tersine, aktif olan en yüksek girişin numarasını ve bir Ready bilgisini verir.

Bu elemanlar ALU tasarımında birleşir: toplayıcı, çıkarıcı, tümleyici ve öteleyici blokları paralel çalışır, işlem kodu MUX'lar aracılığıyla istenen sonucu seçer. Sonuçları göstermek için yedi parçalı gösterge sürücüsünün doğruluk tablosu ve Karnaugh haritası yöntemi görüldü. Son olarak çıkışların ortak bir hatta doğrudan bağlanamayacağı, bunun için tampon (yüksek empedans) ya da pull-up direnci kullanıldığı anlatıldı; pull-up direncine sonra dönülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
