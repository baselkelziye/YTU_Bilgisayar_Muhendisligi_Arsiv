# Ders 3 Genişletilmiş Notu: Boole Cebri, SOP Gösterimi, Mantık Kapıları ve Karnaugh Haritaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Boole Cebrindeki Özdeşlikler ve Bir İspatın İkinci Yolu
- 2. Doğruluk Tablosundan Boole İfadesi
- 3. SOP ve POS Gösterimleri
- 4. Problemden Devreye: Oylama Örneği
- 5. Mintermler ve Toplamların Çarpımı Örneği
- 6. Mantık Kapıları ve Evrensel Kapılar
- 7. Yarı Toplayıcı Devresi
- 8. Gray Kod
- 9. Karnaugh Haritaları
- 10. Mintermlerle Verilen Fonksiyonun Sadeleştirilmesi
- 11. Beş Değişkenli Fonksiyonlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Boole Cebrindeki Özdeşlikler ve Bir İspatın İkinci Yolu

Ders, Boole cebrinin temel özdeşliklerinin listelendiği slayttan devam etti (ekrandan, 00:20:00). Tablodaki özdeşlikler:

| Özdeşlik | Adı |
|---|---|
| $\overline{\overline{x}} = x$ | Çift tümleme |
| $x + x = x$, $x \cdot x = x$ | Eş güçlülük (idempotent) |
| $x + 0 = x$, $x \cdot 1 = x$ | Özdeşlik |
| $x + 1 = 1$, $x \cdot 0 = 0$ | Baskınlık (domination) |
| $x + y = y + x$, $xy = yx$ | Değişme |
| $x + (y+z) = (x+y)+z$, $x(yz) = (xy)z$ | Birleşme |
| $x + yz = (x+y)(x+z)$, $x(y+z) = xy + xz$ | Dağılma |
| $\overline{(xy)} = \overline{x} + \overline{y}$, $\overline{(x+y)} = \overline{x}\,\overline{y}$ | De Morgan |
| $x + xy = x$, $x(x+y) = x$ | Yutma (absorption) |
| $x + \overline{x} = 1$ | Birim özelliği |
| $x\overline{x} = 0$ | Sıfır özelliği |

Önceki derste ek kural olarak $A + \overline{A}B = A + B$ gösterilmişti. O zaman $A$, $A(B+1)$ diye yazılıp açılmış, $AB + A + \overline{A}B$ elde edilmiş, $B$ paranteze alınarak $B(A+\overline{A}) + A = A + B$ bulunmuştu. Bu derste hoca daha kısa bir yol gösterdi: dağılma kuralının toplama üzerindeki biçimi $x + yz = (x+y)(x+z)$ kullanılır.

$$A + \overline{A}B = (A + \overline{A})(A + B) = 1 \cdot (A+B) = A + B$$

Burada $+$ işaretinin VEYA anlamına geldiği hatırlatıldı. $A + \overline{A}$ her zaman 1'dir ve 1 ile VE yapılan şey kendisi olarak kalır. Aynı yol ikinci kural için de kullanıldı:

$$\overline{A} + AB = (\overline{A} + A)(\overline{A} + B) = \overline{A} + B$$

Boole cebrinin soyut tanımı, mantık dersinde görülen kuralların aynısıdır. Doğru ve yanlış yerine 1 ve 0 kullanılır. VEYA $+$ ile, VE çarpma ile, değil ise üst çizgi ya da kesme işaretiyle ($x'$) gösterilir.

## 2. Doğruluk Tablosundan Boole İfadesi

Slayttaki örnekte $F(x,y,z)$ ve $G(x,y,z)$ fonksiyonlarını tanımlayan Boole ifadeleri istendi (ekrandan, 00:25:00). Hoca önce blok şemayı çizdi: üç giriş ($x, y, z$), iki çıkış ($F$ ve $G$). Her çıkışın sonucu kendine aittir.

| $x$ | $y$ | $z$ | $F$ | $G$ |
|---|---|---|---|---|
| 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

Kural şudur: yalnız çıkışın 1 olduğu satırlar yazılır. 0 olan bir satırı yazmak, ifadeye "0 VEYA" eklemek demektir ve bir anlamı yoktur. Bir satır yazılırken 1 olan değişken kendisiyle, 0 olan değişken değiliyle alınır ve hepsi çarpılır.

$F$ yalnız $x = z = 1$, $y = 0$ iken 1'dir:

$$F = x\overline{y}z$$

Bunu çizmek için iki AND kapısı ve bir NOT kapısı gerekir. Başka bir satırı yerine koyunca sonucun 0 çıktığı da kontrol edildi: örneğin $x=0, y=1, z=0$ için $0 \cdot 0 \cdot 0 = 0$.

$G$ iki satırda 1'dir ($110$ ve $010$):

$$G = xy\overline{z} + \overline{x}y\overline{z}$$

Hoca $100$ satırını yerine koyarak iki terimin de 0 verdiğini gösterdi. Sonra sadeleştirdi: $y\overline{z}$ ortak paranteze alınır.

$$G = y\overline{z}(x + \overline{x}) = y\overline{z}$$

Sadeleştirmeden önce devre için dört AND, üç NOT ve bir OR kapısı gerekirken, sadeleştirmeden sonra bir AND ve bir NOT yeter. Tablodan da aynı sonuç okunur: $y = 1, z = 0$ iken $x$ 1 de olsa 0 da olsa $G = 1$'dir; yani $x$'in sonuca etkisi yoktur. Hoca, uzun ve karmaşık ifadelerde bu sadeleştirmeyi daha sistematik yapmak için Karnaugh haritalarının kullanılacağını söyledi.

## 3. SOP ve POS Gösterimleri

Mantık fonksiyonları yazılırken iki genel gösterim vardır.

- **SOP (sum of products, çarpımların toplamı):** Parantez içinde çarpımlar, terimler arasında toplama vardır. Örnek biçim: $AB\overline{C} + \overline{C}\,\overline{B}A$. Mintermlerle ifade edilir ve toplam olduğu için $\Sigma$ ile gösterilir.
- **POS (product of sums, toplamların çarpımı):** Parantez içinde toplamlar, parantezler arasında çarpma vardır. Örnek biçim: $(A+B)(\overline{A} + \overline{B} + C)$. Maxtermlerle ifade edilir ve çarpım olduğu için $\Pi$ ile gösterilir.

Hoca, yeri gelince birinin, yeri gelince ötekinin kullanıldığını, ayrıntısının mantık devreleri dersinde anlatılacağını, bu ders için bu kadar bilginin yeterli olduğunu söyledi.

## 4. Problemden Devreye: Oylama Örneği

Hoca bir problemi çözerken hangi adımların izlendiğini bir örnekle gösterdi (ekrandan, 00:30:00).

**Problem:** Bir yarışmada iki jüri üyesi ($J_1$, $J_2$) ve bir müdür ($M$) bir aday için oylama yapacak. Jürilerin oyu 30, müdürün oyu 40 puandır; her kişi ya tam puan ya da 0 puan verir. Toplam puan 55'ten büyükse aday başarılı sayılır.

**Adım 1, giriş ve çıkış sayısı:** Üç kişinin farklı kombinasyonları incelenir, başka bilgi yoktur; dolayısıyla 3 giriş vardır. Çıkış tektir: aday geçti mi kaldı mı ($R$).

**Adım 2, blok şema:** Üç girişli, bir çıkışlı bir kutu çizilir. Hoca, sınavda önce blok şemanın çizilmesinin istenebileceğini belirtti.

**Adım 3, doğruluk tablosu:** Bütün olası durumlar yazılır ve her satır için puan toplanır.

| $J_1$ | $J_2$ | $M$ | Puan | $R$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 40 | 0 |
| 0 | 1 | 0 | 30 | 0 |
| 0 | 1 | 1 | 70 | 1 |
| 1 | 0 | 0 | 30 | 0 |
| 1 | 0 | 1 | 70 | 1 |
| 1 | 1 | 0 | 60 | 1 |
| 1 | 1 | 1 | 100 | 1 |

(Puan sütunu ve $R$ değerleri python ile doğrulandı.)

**Adım 4, SOP ifade:** 1 olan satırlar yazılır.

$$R = \overline{J_1}J_2M + J_1\overline{J_2}M + J_1J_2\overline{M} + J_1J_2M$$

Bir öğrenci üçüncü terimin yanlış yazıldığını fark etti; hoca terimi $J_1J_2\overline{M}$ olarak düzeltti.

**Adım 5, devre:** Her terim üç girişli bir AND kapısıyla, dört AND'in çıkışı da bir OR kapısıyla toplanır. Hoca blok şemanın ve devrenin kendi çiziminin farklı şeyler olduğunu vurguladı.

**Adım 6, sadeleştirme:** Son iki terimde $J_1 = J_2 = 1$ iken $M$ 0 da olsa 1 de olsa sonuç 1'dir:

$$J_1J_2\overline{M} + J_1J_2M = J_1J_2(\overline{M} + M) = J_1J_2$$

Böylece iki terim teke indi. İlk iki terimde ise ortak paranteze alınacak bir şey yoktu. Hoca $M$'yi ortak paranteze alınca içeride XOR'a benzer bir ifadenin kaldığını söyledi. Bu örnek, dersin ilerisinde Karnaugh haritasıyla yeniden çözüldü (Bölüm 9.4).

## 5. Mintermler ve Toplamların Çarpımı Örneği

### 5.1 Öğe ve Minterm

Slayttaki tanım (ekrandan, 00:35:00):

> Bir değişken veya tümleyenine **öğe** (literal) denir. Boole değişkenleri $x_1, x_2, \dots, x_n$'in $y_i = x_i$ veya $y_i = \overline{x_i}$ durumunu sağlayan $y_1, y_2, \dots, y_n$ çarpımına **minterm** denir. Her değişken bir öğe olarak gösterildiğinde bir minterm $n$ tane öğenin çarpımıdır.

Hoca, slaytta yer almasa da maxtermin bunun karşılığı olduğunu söyledi: maxtermde öğeler toplanır, örneğin $\overline{A} + \overline{B} + C$. Mintermler toplanınca $\Sigma$, maxtermler çarpılınca $\Pi$ gösterimi kullanılır.

### 5.2 $(x+y)\overline{z}$ Örneği

Slayttaki soru: $F(x,y,z) = (x+y)\overline{z}$ fonksiyonu için toplamların çarpımı açılımını bulunuz (ekrandan, 00:40:00). Slaytta çözülen ifade ise mintermlerin toplamıdır.

**Çözüm 1 (tablo ile):** İfade alt parçalara ayrılır. Önce $x + y$ sütunu hesaplanır: yalnız $x = y = 0$ olan iki satırda 0'dır. Sonra $\overline{z}$ sütunu yazılır. Son olarak ikisi VE yapılır: $\overline{z} = 0$ ise sonuç 0'dır, $\overline{z} = 1$ ise sonuç $x+y$'ye eşittir.

| $x$ | $y$ | $z$ | $x+y$ | $\overline{z}$ | $(x+y)\overline{z}$ |
|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 |

1 olan satırlar:

$$F(x,y,z) = xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$$

Üç minterm çıktı. Hoca mintermlerin numarayla da adlandırıldığını anlattı: satırın ikili değerinin onluk karşılığı minterm numarasıdır. $m_0$ $000$'a, $m_7$ $111$'e karşılık gelir.

Hoca bu ifadeyi ters yönde sadeleştirip başlangıç ifadesine döndü:

$$xy\overline{z} + \overline{x}y\overline{z} + x\overline{y}\,\overline{z} = y\overline{z}(x + \overline{x}) + x\overline{y}\,\overline{z} = y\overline{z} + x\overline{y}\,\overline{z}$$

$$= \overline{z}(y + \overline{y}x) = \overline{z}(x+y)$$

Son adımda Bölüm 1'deki kural ($y + \overline{y}x = y + x$) kullanıldı.

**Çözüm 2 (Boole kurallarıyla):** Slayttaki adımlar:

$$\begin{aligned}
F &= (x+y)\overline{z} \\
&= x\overline{z} + y\overline{z} && \text{dağılma kuralı}\\
&= x1\overline{z} + 1y\overline{z} && \text{özdeşlik kuralı}\\
&= x(y+\overline{y})\overline{z} + (x+\overline{x})y\overline{z} && \text{birim özelliği}\\
&= xy\overline{z} + x\overline{y}\,\overline{z} + xy\overline{z} + \overline{x}y\overline{z} && \text{dağılma kuralı}\\
&= xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z} && \text{eş güçlülük}
\end{aligned}$$

Fikir, bir terimde olmayan değişkeni $1 = (y + \overline{y})$ biçiminde çarpan olarak eklemektir. Hoca öğrencilere hangi iki terimin aynı olduğunu sordu; bir öğrenci birinci ve üçüncü terimin aynı olduğunu söyledi. Aynı terim iki kez yazılmaz.

> **Ders sonrası not:** Slayttaki son adımın adı "değişmezlik kuralı" olarak yazılmış. Tekrar eden terimin bir kez yazılması $x + x = x$, yani eş güçlülük (idempotent) kuralıdır.

## 6. Mantık Kapıları ve Evrensel Kapılar

Kapılar, oluşturulan mantık fonksiyonlarının fiziksel olarak gerçeklenmesini sağlayan devre elemanlarıdır (ekrandan, 00:45:00). Temel üç işlem NOT, OR ve AND'dir:

- **NOT (inverter):** $x \to \overline{x}$
- **OR:** $x, y \to x + y$; çok girişli biçimi $x_1 + x_2 + \dots + x_n$
- **AND:** $x, y \to xy$; çok girişli biçimi $x_1x_2\cdots x_n$

### 6.1 $xy + \overline{x}y$ ifadesinin çizimi

$x$ ve $y$ bir AND kapısına girer ($xy$). $x$ bir NOT kapısından geçirilir ve $y$ ile ikinci bir AND kapısına girer ($\overline{x}y$). İki çıkış bir OR kapısında toplanır. Slayttaki ikinci çizimde $x$ ve $y$ için ayrı giriş üretmek yerine aynı hattan dallanma alınır. Hoca devre tasarlarken bu yolun kullanılabileceğini söyledi: aynı değişken için ikinci bir giriş üretmeye gerek yoktur. Devre tasarımında amaç, fonksiyonu kaç değişkenli olursa olsun en düşük maliyetle, yani en sade haliyle gerçeklemektir.

### 6.2 NAND ve NOR

AND, OR ve NOT'tan türeyen NAND ve NOR kapılarına evrensel (universal) kapı denir. Hoca bir AND kapısının çıkışını NOT kapısına bağladı ve sordu: AND'in çıkışı $xy$, NOT'tan sonra $z = (xy)'$ olur. NAND bu iki kapıyı tek kapıda birleştirir: önce AND, sonra çıkışın değili. Kapı simgesinin ucundaki küçük yuvarlak değillemeyi gösterir. NOR da önce OR, sonra değil demektir: çıkış $(x+y)'$ olur.

### 6.3 Düzensiz bir ifadenin çizimi

Hoca bir ifadeyi kapılarla çizerken sırayı anlattı: değil işlemi en son uygulanır, önce parantez içi yapılır. Örnekte $x$'in değili alınır; $y$ ile $z$'nin değili OR yapılır; bu sonucun değili alınır; sonra iki kol AND ile birleştirilir. Bu tür ifadelerin ne SOP ne POS olduğunu, düzensiz ama geçerli birer mantık fonksiyonu olduğunu belirtti.

<!-- BELİRSİZ: 00:45:27-00:47:42 arasında çizilen ifadeler (x+y ile x'in değilinin birleşimi ve x, y, z'li ifade) slaytın aşağı kısmında; 00:45:00 karesinde görünmüyor, ifadenin tam biçimi altyazıdan çıkarılamadı. -->

## 7. Yarı Toplayıcı Devresi

Devre örneği olarak iki bitlik yarı toplayıcı (half adder) incelendi (ekrandan, 00:50:00). Yarı toplayıcı iki biti toplar. İki çıkışı vardır: toplam (sum, $S$) ve elde (carry, $C$).

| $x$ | $y$ | $S$ | $C$ |
|---|---|---|---|
| 1 | 1 | 0 | 1 |
| 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 0 |

$1 + 1 = 2$'dir, ama ikilik tabanda 2 yazılamaz: sonuç 0, elde 1 olur. Bu yüzden $S = 0$, $C = 1$. Tablodan:

$$S = x\overline{y} + \overline{x}y, \qquad C = xy$$

Slayttaki devre $S$'yi farklı bir biçimde kurar: $x$ ve $y$ bir OR kapısına girer ($x+y$); aynı girişler bir AND kapısına girer ($xy$), bu çıkış bir NOT'tan geçer ($\overline{xy}$); son olarak iki kol AND yapılır. Yani $S = (x+y)\overline{(xy)}$. Elde $C = xy$, aynı AND kapısının çıkışından doğrudan alınır.

### 7.1 $S$ ifadesinin dönüştürülmesi

Hoca $x\overline{y} + \overline{x}y$ ifadesinin $(x+y)\overline{(xy)}$'ye eşit olduğunu göstermek istedi. Önce iki kez değil alma yolunu denedi, sonra içeriyi dağıtmayı denedi; dağıtırken bir adım karıştı ve öğrencilerle birlikte hata bulundu. Sonuçta öğrencilerden birinin önerdiği yol, yani dağılma kuralının toplama üzerine biçimi, sonuca götürdü (ekrandan, 01:00:00):

$$x\overline{y} + \overline{x}y = (x + \overline{x})(x + y)(\overline{y} + \overline{x})(\overline{y} + y)$$

Birinci ve dördüncü çarpan 1'dir:

$$= (x+y)(\overline{x} + \overline{y})$$

De Morgan kuralıyla $\overline{x} + \overline{y} = \overline{(xy)}$ olduğundan:

$$S = (x+y)\overline{(xy)}$$

(Eşitlik python ile doğrulandı.) Hoca $S$'nin aslında $x$ XOR $y$ olduğunu, devreyi doğrudan $x\overline{y} + \overline{x}y$ ile de çizebileceğini söyledi.

> **Ders sonrası not:** Hoca dönüşümü yaparken bir yerde $x\overline{y} + \overline{x}y$ ifadesini çarpım gibi dağıttı ve sonuç tutmadı. Bir toplamın kendisini dağıtmak için $a + bc = (a+b)(a+c)$ kuralı uygulanmalıdır; bu durumda $(x\overline{y} + \overline{x})(x\overline{y} + y)$ yazılır ve yukarıdaki dört çarpan elde edilir.

### 7.2 Yarı toplayıcıdan tam toplayıcıya

Bir öğrenci "yarı" toplayıcının neden yarı olduğunu sordu.

**Soru:** Yarı toplayıcıdaki "yarı" ne anlama geliyor?

**Cevap:** Yarı toplayıcı, toplamadan önce gelen elde bilgisini hesaba katmaz. Onluk tabanda $486 + 382$ toplanırken $6 + 2 = 8$ (elde 0), $8 + 8 = 16$ (6 yaz, elde 1), sonra elde bir sonraki basamağa eklenir (ekrandan, 01:00:00). Yani bir basamağı toplarken önceki basamaktan gelen elde de işin içine girer. Tam toplayıcı (full adder) bu elde girişini de alır. İki yarı toplayıcı birleştirilerek tam toplayıcı elde edilir; dört bitlik toplayıcılar da böyle kurulur. Ayrıntısı mantık devreleri dersinde anlatılacaktır. Ayrık matematiğin buradaki işi, verilen $x, y$ girişlerinden istenen sonucu veren denklemi bulmak ve bu denklemden devreyi çizmektir.

## 8. Gray Kod

Aradan sonra Karnaugh haritalarına geçildi. Karnaugh haritasının temel mantığı ortak paranteze almaktır ve haritada Gray kod kullanılır (ekrandan, 01:15:00 ve 01:20:00).

**İkili kod (binary):** Sıfırdan başlar, değer her adımda 1 artar.

| İkili | Değer |
|---|---|
| 00 | 0 |
| 01 | 1 |
| 10 | 2 |
| 11 | 3 |

**Gray kod:** Yine sıfırdan başlar ama her adımda yalnız bir bit değişir; değişiklik mümkünse en az önemli bitten yapılır.

| Gray | Değer |
|---|---|
| 00 | 0 |
| 01 | 1 |
| 11 | 3 |
| 10 | 2 |

Hoca kuruluşu adım adım anlattı: $00$'dan sonra son bit değişir, $01$ olur. Sonraki adımda son biti değiştirmek eski bir koda ($00$) götürür, bu yüzden öbür bit değişir ve $11$ olur. Ardından son bit değişir, $10$ olur. Sıra $0, 1, 3, 2$'dir.

Üç bitlik Gray kodu yazmayı da denedi; ilk dört adımı ($000, 001, 011, 010$) yazdıktan sonra devamın sistematiğini tam hatırlamadığını söyledi.

> **Ders sonrası not:** Üç bitlik Gray kod dizisi $000, 001, 011, 010, 110, 111, 101, 100$'dür (değerleri $0, 1, 3, 2, 6, 7, 5, 4$; python ile $i \oplus (i \gg 1)$ formülüyle doğrulandı). Hoca derste $010$'dan sonra $100$ gelebileceğini söyledi; doğrusu $110$'dur.

Karnaugh haritalarında bir eksene en fazla iki bit yazıldığı için iki bitlik Gray kod yeterlidir. Tek bit değiştiğinden, komşu hücrelerde değişkenlerin biri dışında hepsi ortaktır; bu da ortak paranteze almayı kolaylaştırır.

## 9. Karnaugh Haritaları

### 9.1 Harita boyutları

- **2 değişken ($a, b$):** 4 hücre. Satırlar $a = 0, 1$; sütunlar $b = 0, 1$.
- **3 değişken ($a, b, c$):** 8 hücre. Bir eksende tek değişken ($a$), öbür eksende iki değişken ($bc$) Gray sırasıyla: $00, 01, 11, 10$.
- **4 değişken ($a, b, c, d$):** $2^4 = 16$ hücre. Satırlar $ab$, sütunlar $cd$, ikisi de $00, 01, 11, 10$ sırasında.

Hoca ekseni ikili sırayla ($00, 01, 10, 11$) yazmanın hatalı olacağını vurguladı. İkili kod doğruluk tablosunda kullanılır; haritada Gray kod kullanılır ve tablodaki değerler haritaya doğru aktarılmalıdır.

### 9.2 Yöntemin adımları

Slaytta özetlenen akış (ekrandan, 01:20:00):

```text
Doğruluk tablosu
      |
      v
Karnaugh haritası (1 olan satırlar ilgili hücrelere 1 olarak yazılır)
      |
      v
Gruplama (2'nin katlarına göre mümkün olan en büyük gruplar seçilir)
```

### 9.3 Gruplama kuralları

- Gruplar 2'nin kuvveti büyüklüğündedir: 1, 2, 4, 8, 16. Üç elemanlı grup olmaz.
- Önce mümkün olan en büyük grup aranır: 4 değişkenli haritada 16'lı, olmazsa 8'li, olmazsa 4'lü, olmazsa 2'li, en kötü durumda 1'li grup.
- Yan yana ya da üst üste komşu olan 1'ler gruplanır. Çapraz hücreler doğrudan gruplanamaz.
- Bir 1 birden çok gruba girebilir; gruplar iç içe geçebilir, kesişebilir. Önemli olan, her 1'in bir gruba dahil edilmesi ve tek başına yazılmamasıdır.
- Haritanın kenarları ve köşeleri komşudur. Hoca bunu kâğıtla gösterdi: harita silindir gibi katlanınca sol ve sağ kenar, üst ve alt kenar birleşir. 4 değişkenli haritada dört köşe birlikte bir grup oluşturabilir.

Bir grubun ifadesi şöyle yazılır:

- Grup boyunca değeri değişen değişken yazılmaz (bu, ortak paranteze almanın sonucudur).
- Grup boyunca 1 olarak sabit kalan değişken kendisiyle yazılır.
- Grup boyunca 0 olarak sabit kalan değişken değiliyle yazılır.

> **Hocanın vurgusu:** Çok yapılan hatalardan biri, değişmeyen değişkeni bulup sıfırda mı birde mi değişmediğine bakmamaktır. Terimin 1 vermesi için 0'da sabit kalan değişkenin değili alınmalıdır.

1'li gruplama, doğruluk tablosundaki satırı aynen yazmak demektir ve hiçbir sadeleştirme sağlamaz. 2'li gruplama bir değişkeni, 4'lü gruplama iki değişkeni, 8'li gruplama üç değişkeni yok eder. Grup ne kadar büyükse öğe (literal) sayısı o kadar azalır.

### 9.4 Oylama örneğinin Karnaugh ile çözümü

Bölüm 4'teki doğruluk tablosu 3 değişkenli haritaya aktarıldı (ekrandan, 01:25:00). Satır $J_1$, sütun $J_2M$:

| $J_1 \backslash J_2M$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 1 | 1 |

8'li ya da 4'lü grup kurulamaz, üç tane 2'li grup kurulur. Ortadaki $111$ hücresi üç gruba da girer; bu sorun değildir.

- **Pembe grup** ($J_1 = 1$; $J_2M = 01, 11$): $J_1$ hep 1, $J_2$ değişiyor, $M$ hep 1 → $J_1M$
- **Kırmızı grup** ($J_1 = 1$; $J_2M = 11, 10$): $J_1$ hep 1, $J_2$ hep 1, $M$ değişiyor → $J_1J_2$
- **Beyaz grup** ($J_2M = 11$; $J_1 = 0, 1$): $J_1$ değişiyor, $J_2$ ve $M$ hep 1 → $J_2M$

$$R = J_1M + J_1J_2 + J_2M$$

Devre: üç adet iki girişli AND ve bir OR kapısı. Sonuç SOP biçimindedir. Hoca bir öğrencinin grupları göremediğini söylemesi üzerine grupları renkleriyle tek tek yeniden anlattı.

Ardından anlamayı ölçmek için bir soru sordu: $J_1 = 0, 1$ iken $J_2M = 00$ sütunundaki iki hücre 1 olsaydı grup ne olurdu? Bir öğrenci $J_2M$ dedi; hoca düzeltti: $J_1$ değiştiği için yazılmaz, $J_2$ ve $M$ 0'da sabit olduğu için ikisinin değili alınır, sonuç $\overline{J_2}\,\overline{M}$ olur.

### 9.5 Üç değişkenli harita örnekleri

Satır $a$, sütun $bc$ (ekrandan, 01:30:00).

- $a = 0$ satırının dört hücresi 1 ise (4'lü grup): $a$ 0'da sabit, $b$ ve $c$ değişiyor → $\overline{a}$.
- $bc = 01$ ve $11$ sütunlarındaki dört hücre 1 ise (4'lü grup): $a$ değişiyor, $b$ değişiyor, $c$ 1'de sabit → $c$.
- $bc = 00$ ve $10$ sütunlarındaki dört hücre 1 ise (sol ve sağ kenar komşu, 4'lü grup): $a$ ve $b$ değişiyor, $c$ 0'da sabit → $\overline{c}$. Hoca bu durumda iki ayrı 2'li grup yapmanın yeterince sadeleştirmemek olduğunu belirtti.

Hoca 3 değişkenli haritada 4'lü grubun tek öğe verdiğini, 2'li grubun iki öğe verdiğini gösterdi.

İkinci örnekte 1'ler şu hücrelerdeydi (ekrandan, 01:35:00):

| $a \backslash bc$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 |

4'lü grup kurulamaz; 2'li gruplar seçilir:

- Yeşil ($000, 001$): $\overline{a}\,\overline{b}$
- Alt satırdaki grup ($111, 110$): $ab$
- Pembe ($010, 110$, dikey): $a$ değişiyor, $b = 1$, $c = 0$ → $b\overline{c}$

$$F = \overline{a}\,\overline{b} + ab + b\overline{c}$$

Pembe grup yerine $010$ hücresi, kenar komşuluğuyla $000$ hücresiyle de gruplanabilir: $a = 0$, $b$ değişiyor, $c = 0$ → $\overline{a}\,\overline{c}$. İki seçim de doğrudur (iki ifade python ile doğrulandı).

**Soru:** Üçlü bir grup ve bir ikili grup yapılabilir mi?

**Cevap:** Bir grupta üç tane 1 olamaz; grup 2'li, 4'lü ya da 8'li olmalıdır.

### 9.6 Dört değişkenli harita örnekleri

Satır $ab$, sütun $cd$.

**Dört köşe (ekrandan, 01:35:00):** $0000, 0010, 1000, 1010$ hücreleri 1. Harita katlanınca köşeler komşudur ve tek bir 4'lü grup oluşur. $a$ değişiyor; $b$ dördünde de 0 → $\overline{b}$; $c$ değişiyor; $d$ dördünde de 0 → $\overline{d}$. Sonuç: $\overline{b}\,\overline{d}$. Hoca, 4 değişkenli haritada 4'lü grubun iki öğe verdiğini, tek öğe için 8'li grup gerektiğini belirtti.

Bir başka örnekte iki 2'li grubun $b\overline{c}$ ve $b\overline{d}$ olarak yazıldığı gösterildi. Öğrencilerden biri ikinci grubu $\overline{b}\,\overline{d}$ dedi; hoca $b$'nin 1'de sabit olduğunu, doğrusunun $b\overline{d}$ olduğunu söyledi.

<!-- BELİRSİZ: 01:36:13-01:37:44 arasındaki ($b\overline{c}$ ve $b\overline{d}$ gruplu) haritanın hücreleri karede görünmüyor; yalnız altyazıdan aktarıldı. -->

**Soru:** Bu haritalamada amaç karmaşık fonksiyonları temele indirgemek mi?

**Cevap:** Evet. Hoca, slayttaki $(x+y)\overline{z}$ örneğini gösterdi: genişletilmiş haliyle çizilince çok sayıda kapı gerekir (saydığı kadarıyla on üç civarı), sade haliyle üç kapı yeter. Karnaugh bunu sistematik olarak sağlar.

**Soru:** Hep SOP çözüm çıktı; POS nasıl çıkar?

**Cevap:** SOP ve POS ifadeyi standart biçimde yazmak için kullanılan gösterimlerdir. Önemli olan daha az öğe ve kapı kullanmaktır.

**8'li gruplar (ekrandan, 01:45:00 ve 01:50:00):**

- $ab = 00$ ve $ab = 10$ satırları tamamen 1 ise: üst ve alt satır komşudur, 8'li grup. $a$ değişiyor, $b$ 0'da sabit, $c$ ve $d$ değişiyor → $\overline{b}$.
- $cd = 00$ ve $01$ sütunları tamamen 1 ise: 8'li grup. $a$, $b$, $d$ değişiyor, $c$ 0'da sabit → $\overline{c}$.
- $cd = 00$ ve $10$ sütunları tamamen 1 ise (sol ve sağ kenar): $\overline{d}$.

Bir örnekte iki 8'li grup birlikte seçildi: hem $cd = 00, 01$ sütunları ($\overline{c}$) hem de dört 1'li satırlar ($\overline{b}$). Hoca önce ikinci grubu yanlışlıkla $\overline{c}$ diye yazdı, bir öğrencinin uyarısıyla $\overline{b}$ olarak düzeltti. Grupların birbiriyle kesişmesi sorun değildir; bir grup büyütülebiliyorsa büyütülmelidir, çünkü daha az terime ulaşılır.

**16 hücrenin hepsi 1 ise:** Hoca öğrencilere sonucu tahmin etmelerini istedi. Bütün değişkenler değiştiği için hiçbiri yazılmaz; doğruluk tablosunun $2^4 = 16$ satırının hepsi 1'dir ve $F = 1$'dir. Hepsi 0 olursa $F = 0$'dır.

**Karışık örnek (ekrandan, 01:50:00):**

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 1 | 0 | 1 | 1 |
| 01 | 0 | 0 | 1 | 0 |
| 11 | 0 | 0 | 0 | 0 |
| 10 | 1 | 0 | 1 | 1 |

Bir öğrenci dört ikili grup önerdi; başka bir öğrenci köşelerin 4'lü gruplanabileceğini fark etti. Hoca önce 4'lü grupların aranması gerektiğini hatırlattı.

- Mavi 4'lü grup (dört köşe): $a$ değişiyor, $b = 0$, $c$ değişiyor, $d = 0$ → $\overline{b}\,\overline{d}$
- Sarı 4'lü grup ($ab = 00, 10$; $cd = 11, 10$): $a$ değişiyor, $b = 0$, $c = 1$, $d$ değişiyor → $\overline{b}c$
- Ortada kalan $0111$ hücresi, $0011$ ile 2'li grup: $a = 0$, $b$ değişiyor, $c = 1$, $d = 1$ → $\overline{a}cd$

$$F = \overline{b}\,\overline{d} + \overline{b}c + \overline{a}cd$$

(Python ile doğrulandı.) Bir öğrenci 2'li grubu önce $\overline{b}c$ diye söyledi; hoca, 4'lü grup iki öğe veriyorsa 2'li grubun daha çok öğe vermesi gerektiğini hatırlattı.

Hoca son olarak, bütün adımları özetledi: problem anlaşılır, doğruluk tablosuna aktarılır, tablodan haritaya geçilir, haritada gruplanır, en sade SOP fonksiyon yazılır ve kapı şeması çizilir.

**Bir başka örnek (01:51:08-01:53:45):** Bir 4'lü grup ve iki 2'li grupla bitirilen bir harita yapıldı. Söylenen gruplar: $\overline{b}d$ (4'lü) ve $\overline{a}\,\overline{c}d$ (2'li); üçüncü 2'li grubun ifadesi altyazıda net değil. Hoca ardından komşusu olmayan tek bir 1 ekledi: hiçbir yönden gruplanamayan bu hücre doğruluk tablosu satırı olarak, dört öğeli bir terim olarak yazılır (örnekte $c$ ve $d$ değiliyle girdi).

<!-- BELİRSİZ: 01:51:08-01:53:45 arasındaki haritanın hücreleri karede görünmüyor; grup ifadeleri altyazıda bozuk (örneğin üçüncü grubun ifadesi söylenmiyor), yalnız genel akış aktarıldı. -->

## 10. Mintermlerle Verilen Fonksiyonun Sadeleştirilmesi

### 10.1 Mintermleri gösteren başka bir yazım

Hoca, önceki yıl uzaktan eğitim için hazırlanmış bir ders videosunu kısaca açtı. Videoda 2 değişkenli haritanın eksenlerine $0/1$ yerine $\overline{A}/A$ ve $\overline{B}/B$ yazılıyor, hücrelere minterm numaraları ekleniyordu (ekrandan, 01:55:00). Videodaki örnekte $F(A,B) = AB + \overline{A}B = B$ bulundu: $A$ değiştiği için yazılmaz, yalnız $B$ kalır.

Minterm numarası, hücrenin ikili değerinin onluk karşılığıdır. 3 değişkenli haritada ($a$ satır, $bc$ sütun) hücre numaraları (ekrandan, 02:00:00):

| $a \backslash bc$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 0 | 1 | 3 | 2 |
| 1 | 4 | 5 | 7 | 6 |

Hoca, değişkenlerin hangi eksene yazıldığının önemli olmadığını, önemli olanın tablodaki değerleri Gray sıralı haritaya doğru aktarmak olduğunu söyledi. Eksenlere $0/1$ yazmayı, $\overline{A}/A$ yazmaya tercih ettiğini, bunun ezberlenecek şeyi azalttığını belirtti.

**Soru:** Mintermlerin onluk karşılıkları nasıl bulunur?

**Cevap:** Hücrenin ikili değeri onluğa çevrilir: $000 \to 0$, $001 \to 1$, $011 \to 3$, $010 \to 2$, $100 \to 4$, $101 \to 5$, $111 \to 7$, $110 \to 6$. Eksenlerdeki başlıklar Gray koddur; hücre numaraları ise ikili kodun onluk karşılığıdır.

### 10.2 $\Sigma(1, 2, 3, 7, 11, 15)$ örneği

Hoca soruyu $\Sigma(1, 2, 7, 3, 11)$ olarak verdi (ekrandan, 02:05:00): $m_1, m_2, m_7, m_3, m_{11}$ 1, diğer durumlar 0.

**Değişken sayısı:** En büyük minterm 11'dir. 3 bitle en fazla 7 gösterilebilir; 11 için en az 4 bit gerekir. Bu yüzden $a, b, c, d$ diye 4 değişken vardır.

Doğruluk tablosu 0'dan 15'e kadar yazılır, ilgili satırlara 1 konur. Sonra 4 değişkenli haritaya aktarılır. İlk aktarmada $m_3$ atlanmıştı ve 1'ler hiçbir şekilde gruplanamıyordu; hoca haritayı biraz kolaylaştırmak için $m_{15}$'i de ekledi, sonra bir öğrencinin uyarısıyla $m_3$'ün eksik yazıldığı fark edildi. Son harita:

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 0 | 1 ($m_1$) | 1 ($m_3$) | 1 ($m_2$) |
| 01 | 0 | 0 | 1 ($m_7$) | 0 |
| 11 | 0 | 0 | 1 ($m_{15}$) | 0 |
| 10 | 0 | 0 | 1 ($m_{11}$) | 0 |

Gruplar:

- 1. grup ($m_1, m_3$): $a = 0$, $b = 0$, $c$ değişiyor, $d = 1$ → $\overline{a}\,\overline{b}d$
- 2. grup ($m_3, m_2$): $a = 0$, $b = 0$, $c = 1$, $d$ değişiyor → $\overline{a}\,\overline{b}c$
- 3. grup ($cd = 11$ sütunu, 4'lü): $a$ ve $b$ değişiyor, $c = 1$, $d = 1$ → $cd$

$$F = \overline{a}\,\overline{b}d + \overline{a}\,\overline{b}c + cd$$

(Ekrandan, 02:10:00; python ile doğrulandı.)

**Devre:** $a$ ve $b$ birer NOT kapısından geçer. Üç girişli bir AND $\overline{a}, \overline{b}, d$'yi; ikinci üç girişli AND $\overline{a}, \overline{b}, c$'yi; iki girişli bir AND $c, d$'yi alır. Üç AND çıkışı bir OR kapısında toplanır.

**Soru:** Kümeyi belirlerken 15 yoktu, neden 4 değişken kullandık?

**Cevap:** 11'i gösterebilmek için 4 bit gerekir. 15 sonradan haritayı kolaylaştırmak için eklendi.

**Soru:** Bu kadar az kapı çıkmasının nedeni üç girişli kapı kullanmamız mı?

**Cevap:** Evet. Yalnız iki girişli kapılar olsaydı $\overline{a}\,\overline{b}$ için bir AND, sonucu $d$ ile ikinci bir AND'e sokulurdu. Hoca iki girişli kapılarla toplam yaklaşık beş AND, iki OR ve dört NOT gerektiğini saydı. Üç ya da dört girişli kapılar da vardır.

**Soru:** Elimizde yalnız iki girişli kapılar varsa Karnaugh'da en fazla 4'lü mü gruplarız?

**Cevap:** Hayır. Karnaugh gruplaması kapılara göre değil, giriş (değişken) sayısına göre yapılır. Hücre sayısı $2^n$'dir: 4 değişken için 16, 3 değişken için 8. Elimizdeki kapı türü yalnız son adımda, devre çizilirken önemlidir. Mantık devreleri laboratuvarında elde ikili ya da çok girişli kapılar olması fark etmez; sade denklem bulunduktan sonra eldeki malzemeye göre devre kurulur.

**Soru:** $\overline{a}\,\overline{b}$'yi ortak paranteze alırsak daha az kapı gerekmez mi?

**Cevap:** Doğru: $\overline{a}\,\overline{b}(c + d) + cd$ yazılabilir ve bu daha kısadır. Ama artık SOP biçiminde değildir; $\overline{a}\,\overline{b}d + \overline{a}\,\overline{b}c + cd$ SOP biçiminde yazılabilecek en sade haldir.

Hoca, mantık devreleri dersinde "bu devreyi yalnız NAND ya da yalnız NOR kapılarıyla gerçekleyin" gibi soruların geleceğini, bunun için SOP ya da POS biçimine ihtiyaç olduğunu söyledi. Yalnız NAND için 1'ler gruplanıp elde edilen SOP ifadenin iki kez değili alınır; yalnız NOR için 0'lar gruplanır ve POS biçimi elde edilir. Ayrıntısı mantık devreleri ve bilgisayar organizasyonu derslerindedir.

> **Ek bilgi (derste anlatılmadı):** İki kez değil alma ve De Morgan ile $\overline{a}\,\overline{b}d + \overline{a}\,\overline{b}c + cd = \overline{\overline{(\overline{a}\,\overline{b}d)}\cdot\overline{(\overline{a}\,\overline{b}c)}\cdot\overline{(cd)}}$ yazılır. Böylece her çarpım bir NAND, en dıştaki işlem de bir NAND olur; iki katmanlı AND-OR devresi iki katmanlı NAND-NAND devresine dönüşür.

## 11. Beş Değişkenli Fonksiyonlar

Hoca son olarak beş değişkenli ($a, b, c, d, e$) durumdan söz etti (ekrandan, 02:20:00).

**Birinci yol:** $ab$ ile $cde$ eksenleri kullanılabilir, ama $cde$ üç bitlik Gray kod olduğu için 8 sütun olur ve gruplamada başka sorunlar çıkar. Bunun yerine $e = 0$ ve $e = 1$ için iki ayrı 4 değişkenli ($abcd$) harita çizilir ve üst üste düşünülür; harita iki boyuttan üç boyuta çıkar. İki haritada aynı yerdeki gruplar birleşirse $e$ değişiyor demektir ve yazılmaz; grup yalnız bir haritadaysa $e$ ya da $\overline{e}$ terime eklenir. Hoca bu yöntemi tavsiye etmediğini söyledi.

**İkinci yol:** 4 değişkenli haritanın hücrelerine 1, 0, $e$ ya da $\overline{e}$ yazılır. Gruplamada $e$'li hücreler kendi içlerinde ve 1'lerle, $\overline{e}$'li hücreler kendi içlerinde ve 1'lerle, 1'ler kendi içlerinde gruplanır; çünkü $1 = e + \overline{e}$'dir. $e$ ya da $\overline{e}$ içeren grubun terimine bu öğe çarpan olarak eklenir. Böylece beş değişkenli haritaya gerek kalmadan gruplama yapılır.

<!-- BELİRSİZ: 02:19:43-02:20:48 arasındaki örneğin grup ifadeleri altyazıda tutarsız ("B, D", "A, B'nin değili, C'nin değili", "A'nın değili, B, C"); 02:20:00 karesindeki haritada yalnız birkaç 1, e ve e' hücresi görünüyor, son ifade doğrulanamadı. -->

**Soru:** Bu gösterimde $e$ nasıl değişebilir?

**Cevap:** Bir grup iki haritada da varsa $e$ değişmiştir. Grup yalnız $e = 0$ haritasında varsa $e$ sabittir ve $\overline{e}$ olarak terime girer.

Hoca, bunun bu dersin konusu olmadığını, ilgilenen olursa ayrıca anlatabileceğini söyledi. Çok değişkenli durumlar için algoritmik bir yöntem (Quine-McCluskey yöntemi) olduğunu, 8-10 değişkende bile işe yaradığını ve devre simülatörlerinin genellikle bu yöntemle sonuç ürettiğini belirtti.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): $x(y+z) = xy + xz$ doğru mudur?

> **Çözüm (derste verilmedi):** Slayttaki doğrulama tablosunda $x(y+z)$ ve $xy + xz$ sütunları bütün satırlarda aynıdır (yalnız $110$, $101$, $111$ satırlarında 1). Dolayısıyla eşitlik doğrudur; bu, dağılma kuralıdır.

**Soru 2** (ekrandan, 00:20:00): $A + \overline{A}B$ ifadesini sadeleştiriniz.

Çözüm: $(A + \overline{A})(A + B) = A + B$. Benzer biçimde $\overline{A} + AB = \overline{A} + B$.

**Soru 3** (ekrandan, 00:25:00): Tabloda verilmiş olan $F(x,y,z)$ ve $G(x,y,z)$ fonksiyonlarını tanımlayan Boole ifadelerini bulunuz.

Çözüm: $F = x\overline{y}z$; $G = xy\overline{z} + \overline{x}y\overline{z} = y\overline{z}$ (Bölüm 2).

**Soru 4** (ekrandan, 00:30:00): İki jüri (30'ar puan) ve bir müdür (40 puan) 0 ya da tam puan veriyor; toplam 55'ten büyükse aday geçiyor. Bu işi yapan mantık devresinin blok şemasını, doğruluk tablosunu, ifadesini ve devresini bulunuz.

Çözüm: 3 giriş, 1 çıkış; $R = J_1M + J_1J_2 + J_2M$ (Bölüm 4 ve 9.4).

**Soru 5** (ekrandan, 00:40:00): $F(x,y,z) = (x+y)\overline{z}$ fonksiyonu için açılımı bulunuz.

Çözüm: $F = xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$ (Bölüm 5.2).

**Soru 6** (ekrandan, 00:50:00): İki bitlik yarı toplayıcının toplam ve elde çıkışlarını bulunuz.

Çözüm: $S = x\overline{y} + \overline{x}y = (x+y)\overline{(xy)}$, $C = xy$ (Bölüm 7).

**Soru 7** (ekrandan, 01:50:00): Bir karışık 4 değişkenli haritayı ($m_0, m_2, m_3, m_7, m_8, m_{10}, m_{11}$) sadeleştiriniz.

Çözüm: $F = \overline{b}\,\overline{d} + \overline{b}c + \overline{a}cd$ (Bölüm 9.6).

**Soru 8** (ekrandan, 02:05:00): $F = \Sigma(1, 2, 3, 7, 11, 15)$ fonksiyonunu Karnaugh haritasıyla sadeleştirip devresini çiziniz.

Çözüm: $F = \overline{a}\,\overline{b}d + \overline{a}\,\overline{b}c + cd$ (Bölüm 10.2).

## Dersin Toparlaması

Bu derste Boole cebri özdeşliklerinin sadeleştirmede nasıl kullanıldığı ve doğruluk tablosundan Boole ifadesi yazma yöntemi görüldü. Çarpımların toplamı (SOP, mintermler, $\Sigma$) ve toplamların çarpımı (POS, maxtermler, $\Pi$) gösterimleri tanıtıldı. Temel mantık kapıları (NOT, OR, AND) ve evrensel kapılar (NAND, NOR) anlatıldı; oylama problemi ve yarı toplayıcı örnekleriyle bir problemin blok şemadan devre çizimine kadar nasıl çözüldüğü gösterildi.

Dersin ikinci yarısında Gray kod ve Karnaugh haritaları işlendi. Haritalarda Gray sıralı eksenler, komşu hücrelerin 2'nin kuvveti büyüklüğündeki en büyük gruplarla toplanması, kenar ve köşe komşuluğu ve grup ifadesinin yazılması üzerinde duruldu. Mintermlerle verilen bir fonksiyon sadeleştirilip devresi çizildi; beş değişkenli durumlar ve Quine-McCluskey yöntemi yalnız adıyla anıldı. Yalnız NAND ya da NOR ile devre kurma ve tam toplayıcı gibi konuların ayrıntısı mantık devreleri dersine bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
