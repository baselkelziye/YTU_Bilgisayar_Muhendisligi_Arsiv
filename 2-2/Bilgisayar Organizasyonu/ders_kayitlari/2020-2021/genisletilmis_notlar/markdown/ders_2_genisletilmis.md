# Ders 2 Genişletilmiş Notu: Dekoder, DEMUX ve Enkoderler, Toplayıcılar, Karşılaştırıcı, Tri-State Buffer, Flip-Flop'lar ve T Flip-Flop ile Seri Toplayıcı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dekoderler
- 2. Demultiplexer (DEMUX)
- 3. Enkoderler ve öncelik enkoderi
- 4. Yarım ve tam toplayıcılar
- 5. Çok bitli kombinasyonel bloklar
- 6. Toplayıcı-çıkarıcı devresi
- 7. Karşılaştırıcı
- 8. Üç durumlu tampon (tri-state buffer)
- 9. Ardışıl devreler: latch, flip-flop, preset ve clear
- 10. Ardışıl devre tasarımı: T flip-flop ile seri toplayıcı
- 11. Verilog'a kısa giriş
- Örnek Sorular

Ders, kaydın yaklaşık 00:11:25'inde başlar. Bilgisayar organizasyonu konularına geçmeden önce lojik devreler dersinden gereken yapı taşlarının tekrarı bu derste de sürüyor. Önceki derste MUX'lar ve dekoderlere giriş yapılmıştı. Hoca 2'ye 1 ve 4'e 1 MUX'u kısaca hatırlattı: MUX'un $2^n$ girişi, $n$ seçim ucu ve 1 çıkışı vardır; seçim uçlarındaki değer hangi girişin çıkışa aktarılacağını belirler. Küçük MUX'lardan büyük MUX'lar hiyerarşik olarak kurulabiliyordu. Anlatım Microsoft Whiteboard üzerinde el çizimiyle ve "Digital Logic Review" slaytlarıyla yürüdü.

## 1. Dekoderler

### 1.1 Blok yapı ve çeşitleri

Dekoderin $n$ girişi, bir enable ucu ve $2^n$ çıkışı vardır. Üç girişli bir dekoderde girişler $A, B, C$ ($C$ en anlamlı), çıkışlar $Y_0 \dots Y_7$ olur; bu yapı 3x8 dekoder diye anılır. Enable ucu aktif 1 ($E$) ya da aktif 0 ($\bar E$, üzerinde çizgi) olabilir. Çıkışlar da aktif 1 ($Y_0 - Y_7$) ya da aktif 0 ($\bar Y_0 - \bar Y_7$) olabilir. Böylece $2 \times 2 = 4$ yapısal çeşit ortaya çıkar (ekrandan, 00:20:00).

Çalışma mantığı şudur: enable aktifken girişteki değer bir ikili sayı gibi okunur ve o numaralı çıkış aktif olur. Aktif 1 çıkışlı yapıda aktif çıkış 1, diğerleri 0'dır. Örneğin $CBA = 000$ iken yalnız $Y_0 = 1$, $CBA = 001$ iken yalnız $Y_1 = 1$ olur. Enable pasifken ($E = 0$) seçim uçları ne olursa olsun bütün çıkışlar 0'dır: her $A, B, C$ için $Y_0 = Y_1 = \dots = Y_7 = 0$.

### 1.2 Aktif 1 çıkışlı dekoder: çıkışlar mintermdir

Her çıkışı girişlerin bir fonksiyonu olarak yazalım: $Y_0 = f_0(A,B,C)$, ..., $Y_7 = f_7(A,B,C)$. $Y_0$ sütununda yalnız bir satır 1'dir, yani tek bir doğru minterm vardır. Çarpımlar toplamı biçiminde yazınca tek terim kalır. Bu terim $C, B, A$'nın üçünün de 0 olduğu satırdır, o yüzden değişkenlerin tümleyenleri alınır:

$$Y_0 = \bar C \bar B \bar A \quad (0.\ \text{minterm}), \qquad Y_1 = \bar C \bar B A \quad (1.\ \text{minterm})$$

$$Y_6 = C B \bar A \quad (6.\ \text{minterm}), \qquad Y_7 = CBA \quad (7.\ \text{minterm})$$

(ekrandan, 00:30:00). Hoca önce tahtaya $C \cdot B \cdot A$ yazıp "doğru mu?" diye sordu; bir öğrencinin uyarısıyla tümleyenlerin gerektiği vurgulandı.

**Soru:** $B$'ye 0, $A$'ya 0 verince $Y$ 1 oluyor mu? Toplamları şeklinde mi olacak? **Cevap:** Toplamlar biçiminde de yazılabilir, ama burada çarpımlar toplamı biçimi istendi. Bu biçimde terim, değişkenlerin değilleriyle yazılır.

Sonuç: aktif 1 çıkışlı dekoderde her çıkış, seçim uçlarına göre ilgili minterme karşılık gelir.

### 1.3 Aktif 0 çıkışlı dekoder: çıkışlar makstermdir

Şimdi aynı üç girişli dekoderin çıkışları aktif 0 olsun (çıkış isimlerinin üzerinde çizgi var). Enable'ın aktif 1 ya da aktif 0 olması burada önemli değildir. Seçilen çıkış 0, diğerleri 1 olur. $CBA = 000$ iken $\bar Y_0 = 0$, diğerleri 1; $CBA = 111$ iken yalnız $\bar Y_7 = 0$ (ekrandan, 00:30:00).

Bu kez her sütunda tek bir 0 olduğu için toplamlar çarpımı biçimi işe yarar. Hoca bunu Karnaugh haritasındaki seçime benzetti: pratik olan, sıfır olanı seçmek. Yanlış makstermler yazılır:

$$\bar Y_0 = C + B + A, \quad \bar Y_1 = C + B + \bar A, \quad \bar Y_2 = C + \bar B + A, \quad \bar Y_7 = \bar C + \bar B + \bar A$$

Yani aktif 0 çıkışlı dekoderde her çıkış ilgili makstermdir. Bir fonksiyon doğru mintermlerin OR'lanmasıyla ya da yanlış makstermlerin AND'lenmesiyle elde edilebildiğine göre, dekoder kullanarak herhangi bir lojik fonksiyon gerçeklenebilir.

### 1.4 Örnek: 3x8 dekoder ile tam toplayıcı

Tam toplayıcının girişleri $A, B, C_{in}$, çıkışları $S$ ve $C_{out}$'tur. Çalışma mantığı: $C_{out}$ ve $S$ iki basamaklı bir ikili sayı olarak okunduğunda, bu sayı üç bitin toplamına eşittir:

$$(C_{out}\, S)_2 = A + B + C_{in}$$

(ekrandan, 00:40:00). Doğruluk tablosu toplama yapılarak doldurulur: $0+0+0 = 0 \to 00$, $0+0+1 = 1 \to 01$, $0+1+1 = 2 \to 10$, $1+1+1 = 3 \to 11$.

| $A$ | $B$ | $C_{in}$ | $C_{out}$ | $S$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 1 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 | 0 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 |

Buradan $C_{out} = \sum m(3,5,6,7)$ ve $S = \sum m(1,2,4,7)$ okunur.

**Bağlantı sırası.** Tablo $A, B, C_{in}$ sırasında yazıldı ve en anlamlı bit $A$'dır. Dekoderde ise en anlamlı giriş $C$ ucudur. Tablonun mintermlerinin dekoder çıkışlarına birebir düşmesi için $A$ dekoderin $C$ ucuna, $B$ $B$ ucuna, $C_{in}$ $A$ ucuna bağlanır. Bunu derste bir öğrenci önerdi ("ters çevirip bağlayacağız"). Enable ucuna 1 verilir.

**Aktif 1 çıkışlı dekoderle.** Doğru mintermler OR'lanır: $C_{out}$ için $Y_3, Y_5, Y_6, Y_7$ büyük bir OR kapısına, $S$ için $Y_1, Y_2, Y_4, Y_7$ ikinci bir OR kapısına bağlanır. Aynı dekoder iki fonksiyon için ortak kullanılır.

**Aktif 0 çıkışlı dekoderle.** Çıkışlar maksterm olduğu için yanlış makstermler AND'lenir. $C_{out}$'un 0 olduğu satırlar 0, 1, 2, 4'tür; $\bar Y_0, \bar Y_1, \bar Y_2, \bar Y_4$ bir AND kapısına girer. $S$'nin 0 olduğu satırlar 0, 3, 5, 6'dır; $\bar Y_0, \bar Y_3, \bar Y_5, \bar Y_6$ ikinci bir AND kapısına girer. Giriş tarafındaki bağlantılar aynıdır.

**Soru:** Daha önce seçim ucunun aktif 1 ya da aktif 0 olmasına göre ters işlem yapmamış mıydık? **Cevap:** Burada söz konusu olan enable ucudur. Enable aktif 1 olduğu için 1'e bağlanır; aktif 0 olsaydı 0'a bağlanması gerekirdi. Seçim uçları her iki örnekte de aynı şekilde bağlanır, fark yalnız çıkış tarafındadır.

### 1.5 Dekoderin iç yapısı

Çıkışlar minterm olduğu için her çıkış, girişlerin düz ya da tümleyen hallerini alan bir AND kapısıyla üretilir. $Y_0$ için üç girişin tümleyenleri AND'lenir, $Y_1, Y_2, Y_3$ benzer şekilde 1., 2. ve 3. mintermlerdir. Enable ucunun 0 iken bütün çıkışları 0 yapması için enable her AND kapısına ayrı bir giriş olarak bağlanır.

### 1.6 Hiyerarşik yapı: 2x4 dekoderlerden 4x16 dekoder

Hiyerarşik mimari, daha az girişli ve çıkışlı küçük blokları kullanarak büyük bloklar kurmaktır. Slayttaki örnekte iki katlı bir dekoder ağacı vardır (ekrandan, 00:45:00). Ulaşılmak istenen 4x16 dekoderin dört seçim ucu ($D, C, B, A$; $D$ en anlamlı), bir enable ucu ve $Y_0 \dots Y_{15}$ çıkışları olmalıdır.

Hangi ucun hangi seçim ucuna karşılık geldiğini bulmak için uçların değişiminin çıkışı kaç basamak kaydırdığına bakılır. 0000 girişi $Y_0$'ı, 1000 girişi $Y_8$'i seçer; yani $D$'nin 0'dan 1'e geçmesi çıkışı $2^3 = 8$ basamak kaydırır.

- $w_0$ ikinci kattaki bütün dekoderlerin $w_0$ ucuna gider, değişimi çıkışı 1 basamak kaydırır: $A$'ya karşılık gelir.
- $w_1$ değişimi 2 basamak kaydırır: $B$.
- $w_2$ birinci kattaki dekoderin girişidir, değişimi ikinci kattaki bir sonraki dekoderi seçtirir; örneğin $Y_0$ yerine $Y_4$ seçilir. 4 basamak: $C$.
- $w_3$ değişimi iki dekoder atlatır; $Y_0$ seçiliyken $w_3 = 1$ olunca üçüncü dekoderin ilk çıkışı $Y_8$ seçilir. 8 basamak: $D$.

Mantık şöyledir: birinci kattaki seçim uçları ikinci kattaki dekoderlerden hangisinin etkin olacağını, ikinci kattaki seçim uçları da o dekoderin hangi çıkışının aktif olacağını belirler. Enable 0 olunca birinci kattaki dekoderin bütün çıkışları 0 olur; bunlar ikinci kattaki dekoderlerin enable uçları olduğu için 16 çıkışın tamamı 0'a düşer. İstenen davranış sağlanmış olur.

Hoca bunun bir soyutlama seviyesi olduğunu vurguladı: içerideki lojik kapı seviyesindeki tasarım, hatta transistörlerin üretim aşamasındaki bağlantıları hazır kabul edilir.

## 2. Demultiplexer (DEMUX)

DEMUX, MUX'un ters yönde çalışan bir benzeri gibi düşünülebilir. MUX'ta çok sayıda girişten biri seçilip çıkışa verilir (çok kaynaktan tek kaynağa). DEMUX'ta ise tek bir kaynak farklı hedeflere yönlendirilir. $n$ seçim ucu ve $2^n$ çıkış vardır; seçim uçlarındaki sayının onluk değeri hangi çıkışı gösteriyorsa giriş o çıkışa aktarılır.

1'e 4 DEMUX'ta veri girişi $A$ (slaytta $I$) ve seçim uçları $S_1 S_0$'dır (ekrandan, 00:50:00):

| $S_1$ | $S_0$ | $Q_3$ | $Q_2$ | $Q_1$ | $Q_0$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | $A$ |
| 0 | 1 | 0 | 0 | $A$ | 0 |
| 1 | 0 | 0 | $A$ | 0 | 0 |
| 1 | 1 | $A$ | 0 | 0 | 0 |

Burada iki girişli, tek çıkışlı dört fonksiyon eş zamanlı olarak gerçekleniyor. En genel yazım $f = \sum_i m_i \cdot f(i)$'dir. Fonksiyonun 0 olduğu satırlar çarpımda yutan eleman yüzünden düşer; 1 olduğu satırlarda 1 etkisiz eleman olduğundan yalnız doğru mintermlerin toplamı kalır. Burada $f(i)$ bir değişken ($A$) olduğu için çarpımda bırakılır. Her sütunda yalnız bir satır sıfırdan farklıdır:

$$Q_3 = S_1 S_0 A, \quad Q_2 = S_1 \bar S_0 A, \quad Q_1 = \bar S_1 S_0 A, \quad Q_0 = \bar S_1 \bar S_0 A$$

Devre, seçim uçları için iki NOT kapısı ve her çıkış için bir 3 girişli AND kapısıyla kurulur.

## 3. Enkoderler ve öncelik enkoderi

### 3.1 4'e 2 enkoder

Enkoder, dekoderin tersi gibi düşünülebilir: $2^n$ giriş, $n$ çıkış vardır. Ön koşul olarak girişlerden yalnız birinin 1 olmasına izin verilir; birden fazla 1 olursa davranış tanımlı değildir. Çıkış, 1 olan girişin numarasının ikili karşılığıdır (ekrandan, 00:55:00):

| $w_3$ | $w_2$ | $w_1$ | $w_0$ | $y_1$ | $y_0$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 0 | 0 | 1 | 1 |

Hoca önce yalnız bu dört satırı kullanarak $y_0$'ı yazdı:

$$y_0 = \bar w_3 \bar w_2 w_1 \bar w_0 + w_3 \bar w_2 \bar w_1 \bar w_0 = \bar w_2 \bar w_0 (\bar w_3 w_1 + w_3 \bar w_1)$$

Bu ifade slayttaki basit devreye ($y_0 = w_1 + w_3$) varmıyordu. Eksik olan, "don't care" durumlarıdır. Dört girişli bir fonksiyonun doğruluk tablosu 16 satırdır. Tanım gereği yalnız bir girişin 1 olduğu 4 satır bilinir; kalan 12 satır, tanımın kendisinden gelen don't care'dir.

Karnaugh haritasına ($w_3 w_2$ satırlar, $w_1 w_0$ sütunlar) bilinen değerler ve don't care'ler yerleştirilir (ekrandan, 01:00:00). $y_0$ için 0001 ve 0100 satırları 0, 0010 ve 1000 satırları 1'dir. $w_1 = 1$ sütunlarını kapsayan grup $w_1$ terimini, $w_3 = 1$ satırlarını kapsayan grup $w_3$ terimini verir:

$$y_0 = w_1 + w_3$$

$y_1$ için 0001 ve 0010 satırları 0, 0100 ve 1000 satırları 1'dir. Aynı şekilde:

$$y_1 = w_2 + w_3$$

$w_0$ devrede boşta kalır. Bu mantıklıdır: yalnız $w_0 = 1$ iken iki çıkış da 0 olmalıdır, yani $w_0$ çıkışları etkileyen bir değişken değildir.

### 3.2 Öncelik enkoderi

Öncelik enkoderi enkoderin özel bir durumudur ve birden fazla girişin 1 olmasına izin verir. $w_0$ en düşük, $w_{2^n-1}$ en yüksek anlamlı giriştir (3 çıkış varsa 8 giriş, $w_0 \dots w_7$). Devre en yüksek anlamlı girişten başlayarak düşüğe doğru tarar ve ilk karşılaştığı 1'e göre çıkış üretir. Özel bir $z$ (valid, geçerlilik) çıkışı vardır: hiçbir giriş 1 değilse $z = 0$ olur ve diğer çıkışların anlamı yoktur. Hoca bu yapının kesme önceliklendirmesi gibi mekanizmalarda kullanıldığını ve mikroişlemci derslerinde karşılaşılacağını söyledi.

4'e 2 öncelik enkoderinin davranışı:

- Hiçbir giriş 1 değilse $z = 0$, $y_1 y_0$ anlamsız.
- İlk 1 $w_0$'da görülürse (diğerleri 0) $y_1 y_0 = 00$, $z = 1$.
- İlk 1 $w_1$'de görülürse $w_0$ don't care olur; $y_1 y_0 = 01$, $z = 1$.
- İlk 1 $w_2$'de görülürse $w_1, w_0$ don't care; $y_1 y_0 = 10$, $z = 1$.
- $w_3 = 1$ ise diğer bütün girişler don't care; $y_1 y_0 = 11$, $z = 1$.

## 4. Yarım ve tam toplayıcılar

### 4.1 Onluk toplamadan ikili toplamaya

Onluk tabanda toplama yaparken en düşük anlamlı basamakta yalnız iki rakam toplanır; oluşan elde bir sonraki basamağa aktarılır. Sonraki basamaklarda ise iki değere bir de elde eklenir. İkili tabanda en düşük anlamlı bitteki toplamaya karşılık gelen blok yarım toplayıcıdır (half adder): $A$ ve $B$'yi toplayıp $C_{out}$ ve $S$'den oluşan iki basamaklı sayıyı üretir. Tam toplayıcı (full adder) önceki basamaktan gelen eldeyi de katar. Yarım toplayıcı iki girişli ($A, B$), tam toplayıcı üç girişlidir ($A, B, C_{in}$). Tam toplayıcılar, her birinin $C_{out}$'u bir sonrakinin $C_{in}$'ine bağlanacak şekilde kaskat bağlanırsa $n$ bitlik toplayıcı elde edilir.

### 4.2 Yarım toplayıcı

$(C_{out}\, S)_2 = A + B$ (ekrandan, 01:25:00). $0+0 = 00$, $0+1 = 01$, $1+0 = 01$, $1+1 = 10$. Buradan:

$$C_{out} = A \cdot B \ (3.\ \text{minterm}), \qquad S = \bar A B + A \bar B = A \oplus B$$

İç yapı: $A$ ile $B$ bir AND kapısına girerek $C_{out}$'u, bir XOR kapısına girerek $S$'yi üretir.

### 4.3 Tam toplayıcı

Doğruluk tablosu 1.4'tekiyle aynıdır (ekrandan, 01:30:00). $S$'nin Karnaugh haritası (satırlar $AB$, sütunlar $C_{in}$) 001, 010, 100 ve 111'de 1 olan satranç tahtası desenindedir. Bu, Karnaugh haritalarında özel bir durum olarak görülmüştü:

$$S = A \oplus B \oplus C_{in}$$

$C_{out}$ haritasında gruplama yapılınca:

$$C_{out} = AB + C_{in}A + C_{in}B = AB + C_{in}(A + B)$$

Hoca burada, $S$ için zaten üretilmiş olan $A \oplus B$ kapısını $C_{out}$ için de kullanmak istedi. Bunun için her minterm tek tek yazılıp düzenlendi:

$$C_{out} = \bar A B C_{in} + A \bar B C_{in} + A B \bar C_{in} + ABC_{in}$$

$$= (\bar A B + A \bar B) C_{in} + AB(\bar C_{in} + C_{in}) = (A \oplus B) C_{in} + AB$$

(ekrandan, 01:35:00). $\bar C_{in} + C_{in} = 1$ olduğu için o terim sadeleşir. Bu biçim, daha önce üretilmiş bir kapıyı yeniden kullandığı için kapı sayısı açısından daha uygundur. Devre: $A$, $B$, $C_{in}$'in XOR'u $S$'yi verir; $A \oplus B$ ile $C_{in}$'in AND'i ve $A$ ile $B$'nin AND'i bir OR kapısında birleşerek $C_{out}$'u verir.

### 4.4 Yarım toplayıcılar ve lojik kapılarla tam toplayıcı

Tam toplayıcı $A + B + C_{in}$ işlemini yapar. İçinde önce bir yarım toplayıcı vardır: $A$ ile $B$ toplanır, bir elde ($C_1$) ve bir toplam ($S_1$) çıkar. Sonra $S_1$ ile $C_{in}$ ikinci bir yarım toplayıcıda toplanır; bunun toplam çıkışı tam toplayıcının $S$'sidir. İkinci yarım toplayıcının da bir eldesi ($C_2$) olur. $C_{out}$, bu iki eldeden herhangi biri 1 olduğunda 1 olmalıdır; bu yüzden $C_1$ ve $C_2$ bir OR kapısında birleştirilir.

Doğrulama: $C_{out} = 1$ olan satırlarda iki giriş 1 ise ya ilk yarım toplayıcı ($A = B = 1$) ya da ikincisi ($S_1 = 1$, $C_{in} = 1$) elde üretir. Üç giriş de 1 iken ilk yarım toplayıcının çıkışı $10$'dur ($C_1 = 1$, $S_1 = 0$); ikinci yarım toplayıcıda $0 + 1$ toplanır, $S = 1$, $C_2 = 0$ olur. Eldelerden yalnız biri 1 olduğu için OR çıkışı 1'dir.

### 4.5 Yalnız yarım toplayıcılarla tam toplayıcı

İlk iki kat aynıdır: birinci yarım toplayıcı $A$ ve $B$'yi, ikincisi $S_1$ ve $C_{in}$'i toplar; $S$ hazırdır. Bir öğrenci OR kapısı yerine bir yarım toplayıcı daha konmasını önerdi. Üçüncü yarım toplayıcının girişlerine $C_1$ ve $C_2$ bağlanır; toplam çıkışı $C_{out}$ olur, eldesi dışarı çıkarılmaz. Üçüncü bir basamak çıkma ihtimali yoktur: üç ikili sayının toplamı en çok 3'tür ve iki bite sığar. Bu yüzden $C_1$ ve $C_2$ hiçbir zaman aynı anda 1 olmaz ve XOR (yarım toplayıcının toplamı) burada OR gibi davranır. Bu tasarım python ile sekiz giriş için doğrulandı.

## 5. Çok bitli kombinasyonel bloklar

### 5.1 Veri yolu (bus) gösterimi

Şimdiye kadar görülen bloklar hep 1 bitlikti; örneğin MUX'un her girişi tek bitti. Bir bilgisayar sisteminde veriyi bit bit aktarmak anlamlı değildir; işlemler byte'lar ya da word'ler üzerinde yapılır. Örneğin anlamlı bir bütün oluşturan 8 bitlik bir karakter tek seferde aktarılmalıdır. Bu yüzden $n$ bitlik bloklar gerekir.

Şemada bir hat üzerinde eğik bir çizgi ve yanında bir sayı varsa bu, o hattın bir veri yolu olduğunu gösterir: $A$ girişi aslında $A_0, A_1, \dots, A_{n-1}$ diye $n$ ayrı teldir. Bir biti taşımak için bir tel yeterlidir; veri yolu ise paralel döşenmiş bir tel bloğudur.

### 5.2 8 bitlik 4'e 1 MUX

Slayttaki örnekte 4 giriş ve 1 çıkış vardır, ama her biri 8 bitliktir (ekrandan, 01:45:00). Dört veri yolunu ayırt etmek için gereken seçim ucu sayısı giriş sayısından gelir: $\log_2 4 = 2$. Hoca özellikle "$2n$ değil, 2 seçim ucu" diye vurguladı. Doğruluk tablosu 1 bitlik MUX'unkiyle aynıdır: $s_1 s_0 = 00$ ise $w_0$, $11$ ise $w_3$ çıkışa verilir; fark girişlerin ve çıkışın 8 bitlik olmasıdır. Slayta göre çok bitli 2'ye 1, 16'ya 1 MUX'lar da olabilir.

Bu MUX, 1 bitlik 4'e 1 MUX'larla şöyle kurulur. Bir öğrencinin önerdiği gibi 8 tane 4'e 1 MUX kullanılır. $A$ sayısının 0. biti birinci MUX'un $w_0$'ına, 1. biti ikinci MUX'un $w_0$'ına, ..., 7. biti sekizinci MUX'un $w_0$'ına bağlanır. $B$'nin bitleri aynı şekilde $w_1$'lere, $C$ ve $D$'ninkiler $w_2$ ve $w_3$'lere gider. $A$ sayısı seçildiğinde her MUX'un $w_0$ girişi çıkışa geçmelidir; bu yüzden bütün MUX'ların $S_0$ uçları ortak, $S_1$ uçları ortaktır.

### 5.3 16 bitlik toplayıcılardan 32 bitlik toplayıcı

Bir kara kutu düşünelim: $n$ bitlik $X$ ve $Y$ sayılarını ve 1 bitlik $C_{in}$'i toplayıp $n$ bitlik $S$ ve 1 bitlik $C_{out}$ üretsin. $n = 16$ için çıktı 17 bitlik bir sayıdır. Soru: 16 bitlik tam toplayıcılarla 32 bitlik tam toplayıcı gerçekleyiniz (ekrandan, 01:55:00).

32 bitlik toplayıcının $X$ ve $Y$ girişleri 32'şer bit, $S$ çıkışı 32 bit, $C_{in}$ ve $C_{out}$ 1'er bittir. İki 16 bitlik toplayıcı kaskat bağlanır: $X$ ve $Y$ yüksek ve düşük anlamlı 16'şar bitlik parçalara bölünür. Düşük anlamlı parçalar birinci toplayıcıya, yüksek anlamlı parçalar ikinciye girer. Birincinin $C_{out}$'u ikincinin $C_{in}$'ine bağlanır. Böylece düşük yarının toplamından oluşan elde, yüksek yarının toplamına katılır. Sonuç 16 bit düşük, 16 bit yüksek toplam ve 1 bit eldeyle 33 bittir; bu da 32 bitlik kara kutunun çıktısıyla uyumludur.

### 5.4 Tam toplayıcılardan 16 bitlik toplayıcı ve ripple carry sorunu

Aynı mantık aşağı doğru da işler: 16 tam toplayıcı yan yana konur. $i$. tam toplayıcıya $X_i$ ve $Y_i$ bağlanır, her katın $C_{out}$'u bir üst katın $C_{in}$'ine gider. Sonuçta 16 $S$ çıkışı, 1 $C_{in}$ ve 1 $C_{out}$ elde edilir. Yapı herhangi bir $n$ için genelleştirilebilir.

**Soru (hocanın):** Kaskat bağlı tam toplayıcılarla kurulan 16 bitlik toplayıcının sorunu nedir? **Cevap (öğrenciden):** Zamanlama; son bite kadar gecikme birikir. Hoca bunu onayladı: her katta $C_{out}$ birkaç kapıdan geçerek oluşur ve bir sonraki kat bu eldeyi bekler. Hoca kat başına 3 kapı gecikmesiyle 16 katta $16 \times 3 = 48$ kapı gecikmesi biriktiğini söyledi.

> **Ders sonrası not:** Hoca 48 kapı gecikmesi hesabında her katı 3 kapı saydı. 4.3'teki devrede $A \oplus B$ bütün katlarda baştan, paralel hesaplanır. Bu durumda büyük olasılıkla yalnız ilk katta 3 kapı (XOR, AND, OR), sonraki katlarda $C_{in}$'den $C_{out}$'a 2 kapı (AND, OR) gecikme olur. En kötü durum yaklaşık $3 + 15 \times 2 = 33$ kapı gecikmesidir. Ana fikir değişmez: gecikme bit sayısıyla doğrusal artar.

Sorun iki düzeydedir. Birincisi, doğru sonuç için bütün gecikmenin beklenmesi gerekir. İkincisi, bu süre boyunca çıkışlar sürekli değişir: en düşük anlamlı katın eldesi oluşunca bir sonraki katın toplamı değişir, onun eldesi oluşunca bir sonrakininki değişir. Domino taşı etkisiyle sonuç ancak elde son kata ulaşınca anlamlı hale gelir. Bu duruma ripple carry denir.

## 6. Toplayıcı-çıkarıcı devresi

$A$ ve $B$ $n$ bitlik sayılar olsun. $A - B$ işlemi aslında $A + (-B)$ olarak, yani $A$ ile $B$'nin 2'ye tümleyeninin toplamı olarak yapılır. 2'ye tümleyen iki adımda alınır: önce $B$'nin 1'e tümleyeni alınır (her bit ters çevrilir), sonra 1 eklenir (ekrandan, 02:05:00):

$$A - B = A + \bar B + 1$$

Bir sayının 1'e tümleyenini XOR kapılarıyla almak mümkün müdür? XOR'da girişler aynıysa çıkış 0, farklıysa 1'dir. $Y = 1$ satırlarına bakılırsa çıkış $X$'in tersidir: $X \oplus 1 = \bar X$. Kapı simetrik olduğu için $1 \oplus Y = \bar Y$ de geçerlidir. $Y = 0$ satırlarında ise çıkış $X$'in kendisidir: $X \oplus 0 = X$. Yani XOR'un bir girişi 1'e sabitlenirse NOT kapısı gibi çalışır.

**Soru:** Alt satırda $1$ ile $Y$'nin XOR'u yazılmayacak mıydı? **Cevap:** Kapı simetrik olduğu için isim fark etmez; hangi giriş 1 ile XOR'lanırsa çıkış onun değili olur.

Devrede $X$ bitleri $n$ bitlik toplayıcının $X$ girişine doğrudan girer. $Y$'nin her biti, Add/Sub kontrol ucuyla bir XOR kapısına girer. Kontrol ucu aynı zamanda toplayıcının $C_0$ girişine bağlıdır. Toplama için kontrol 0, çıkarma için 1'dir.

- Kontrol 0 iken XOR'lar $Y$'yi değiştirmez, $C_0 = 0$'dır: devre $X + Y$ hesaplar.
- Kontrol 1 iken XOR'ların çıkışı $\bar Y$'dir, $C_0 = 1$'dir: devre $X + \bar Y + 1 = X + (-Y) = X - Y$ hesaplar.

## 7. Karşılaştırıcı

Karşılaştırıcı, iki $n$ bitlik girişi ve 1 bitlik çıkışı olan bir bloktur. $A > B$, $A \ge B$, $A < B$, $A \le B$ ya da $A = B$ gibi bir koşulu sınar; koşul sağlanıyorsa 1, sağlanmıyorsa 0 üretir.

Eşitlik karşılaştırıcısının çıkışı $A = B$ ise 1, $A \ne B$ ise 0 olmalıdır. Bütün anlam sıralarındaki bitler birbirine eşitse sonuç 1'dir. İki bitin eşitliği XOR ile yakından ilgilidir: $A_i \ne B_i$ ise XOR çıkışı 1, eşitse 0'dır (ekrandan, 02:10:00). Eşitlik varsa bütün XOR çıkışları 0'dır; eşitlik yoksa en az biri 1'dir.

Son katta "bütün girişleri 0 iken 1, en az bir girişi 1 iken 0 üreten" bir kapı gerekir. Hoca bunu sordu ve bir öğrenci NOR kapısı diye cevap verdi. Hoca gerekçesini açıkladı: bütün girişlerin 0 olduğunu anlayan kapı OR'dur, çünkü OR yalnız o durumda 0 verir. Bu durumda 1 istendiği için ucuna bir NOT konur ve NOR elde edilir. Diğer durumlar kendiliğinden sağlanır.

Büyüklük ya da küçüklük karşılaştırmasında önce en yüksek anlamlı bitlere bakılır. Farklıysa sonuç oradan belirlenir; eşitse bir sonraki bite geçilir. Bu yüzden kaskat bağlı bir yapı kurulur. Derste yalnız eşitlik durumu incelendi.

## 8. Üç durumlu tampon (tri-state buffer)

Bu yapı lojik devreler dersinde görülmemiş olabilir. Mikroişlemcilerde ve devre tasarımlarında veri yollarının ortak kullanılmasından doğan bir ihtiyaçla ortaya çıkmıştır. Aynı veri yoluna birden fazla çıkış bağlı olabilir, ama bir anda bunlardan yalnız biri aktif olmalıdır. İki kaynak aynı hatta biri 0, diğeri 1 sürmeye çalışırsa kısa devre olabilir. Tri-state buffer, hatta yalnız bir kaynağın veri çıkarmasını sağlar.

Bir girişi ($X$), bir çıkışı ($F$) ve bir enable ucu ($E$) vardır. $E = 1$ iken $F = X$'tir, eşdeğer devre kapalı bir anahtardır. $E = 0$ iken $X$ çıkışa aktarılmaz ve açık devre oluşur; $X$ hattan koparılmış gibi davranır. Bu duruma yüksek empedans denir ve $Z$ ile gösterilir.

Hoca empedansı hatırlattı: empedans AC devrelerde direncin karşılığıdır, frekansa bağlı olarak değişen ve akıma karşı gösterilen dirençtir. Çok yüksek direnç açık devrede olur (sonsuz direnç). Çok yüksek empedans da pratikte o hattı devreden koparır.

Dört tür tri-state buffer vardır (ekrandan, 02:15:00):

- (a) Aktif 1 enable, düz çıkış: $E = 1$ iken $F = X$.
- (b) Aktif 1 enable, terslenmiş çıkış: $E = 1$ iken $F = \bar X$.
- (c) Aktif 0 enable, düz çıkış: $E = 0$ iken $F = X$.
- (d) Aktif 0 enable, terslenmiş çıkış: $E = 0$ iken $F = \bar X$.

8 bitlik bir veri yolunu yüksek empedansa almak ya da aktarmak için her tele bir tane olmak üzere 8 tri-state buffer gerekir.

## 9. Ardışıl devreler: latch, flip-flop, preset ve clear

### 9.1 Kombinasyonel ve ardışıl devre

Kombinasyonel devrede çıkış yalnız girişlere bağlıdır; girişlerden biri değişince çıkış değişir. Ardışıl devrelerde kombinasyonel lojiğin yanında bellek elemanları da vardır. Sistemin çıkışı, o an bellekte tutulan değere ve girişlere bağlıdır. Bu yüzden aynı girişlere rağmen farklı çıkışlar elde edilebilir.

### 9.2 Latch ile flip-flop farkı

Hoca iki tür bellek elemanı olan latch (tutucu) ile flip-flop arasındaki farkı sordu.

**Soru (hocanın):** D latch ile D flip-flop arasındaki fark nedir? **Cevap (öğrenciden):** Latch saatin yüksek ya da alçak seviyesinde, flip-flop ise yükselen (ya da düşen) kenarda çalışır. Hoca cevabı onayladı.

İkisinin de bir enable ucu vardır. Latch'in enable ucu seviye tetiklemelidir: enable 1 olduğu sürece giriş değiştikçe çıkış da değişir. Flip-flop'un enable ucu kenar tetiklemelidir: yalnız yükselen kenarda (ya da düşen kenarda) girişteki değer çıkışa yansıtılır; kenar yoksa giriş ne kadar değişirse değişsin çıkış değişmez.

> **Ders sonrası not:** Hoca bir anda (02:28:10) flip-flop'taki enable ucu için de "seviye tetiklemeli" dedi; hemen ardından "flip-flop kenar tetiklemeli" diye düzeltti. Doğrusu: latch seviye, flip-flop kenar tetiklemelidir.

Slayttaki zamanlama diyagramı farkı gösterir (ekrandan, 02:30:00). Üstteki D latch'te CLK ucu enable gibi çalışır: CLK yüksekken latch saydamdır ("Latch transparent when clock is high"), D'deki her değişim Q'ya geçer. CLK düşünce o anki değer tutulur. Alttaki D flip-flop'ta CLK ucunda bir üçgen işareti vardır, bu yükselen kenarda tetikleme demektir. Flip-flop D'yi yalnız yükselen kenarda örnekler ("Samples D on rising edge of clock") ve küçük bir kapı gecikmesinden sonra Q'ya aktarır. Saat 1'de kalsa da 0'a düşse de bir sonraki yükselen kenara kadar Q değişmez.

Şemadaki tetikleme gösterimleri:

- Düz enable ucu: aktif 1, seviye tetiklemeli.
- Ucunda daire olan enable: aktif 0, seviye tetiklemeli (uç 0 olduğu sürece eleman aktif).
- Üçgen: yükselen kenarda tetikleme.
- Daire ve üçgen birlikte: düşen kenarda tetikleme.

**Soru:** Hem yükselen hem düşen kenarda tetikleme nasıl olur? **Cevap:** Örneğin eskiden RAM'lerde yalnız yükselen kenarda işlem yapılırken DDR (double data rate) belleklerde her iki kenarda yapılır. Mantık olarak içerideki devre tekrarlanır; biri yükselen, diğeri düşen kenarı yakalar. Bunun ayrı bir şematik gösterimi yoktur.

### 9.3 Flip-flop tanım tabloları

Tabloların hepsinde $q$ önceki durum, $Q$ sonraki durumdur (ekrandan, 02:40:00).

- **D flip-flop:** yükselen kenarda $Q = D$; diğer saat durumlarında $Q = q$ (önceki durumu korur).
- **T flip-flop:** yükselen kenarda $T = 0$ ise $Q = q$, $T = 1$ ise $Q = \bar q$; diğer durumlarda $T$ ne olursa olsun $Q = q$.
- **JK flip-flop:** yükselen kenarda $JK = 00$ ise $Q = q$ (korur), $01$ ise $Q = 0$ (sıfırlar), $10$ ise $Q = 1$ (birler), $11$ ise $Q = \bar q$ (tersler); diğer durumlarda $Q = q$.

SR gibi başka flip-floplar da vardır; bunlarda girişlere asla uygulanmaması gereken özel durumlar bulunur. Bu tanımlar ileri yönlü tanımlardır. Tasarımda ise çoğu zaman tersi gerekir: durum diyagramında 0 durumundan 1 durumuna geçmek için girişe ne verilmeli? Bu soruyu ters (geri yönlü) tanım bağıntısı cevaplar; 10. bölümde örnekle kurulur.

### 9.4 Preset ve clear uçları

Bütün tanımlar bir önceki duruma bağlı yazıldı. İlk durum ise flip-flopların set (preset) ve reset (clear) uçlarıyla oluşturulur. Lojik devreler laboratuvarında bu uçlar birer anahtara bağlanıp ilk değer kuruluyordu. Uçlar aktif 0'dır:

- İlk durum 1 için: $\bar S \bar R$ önce 00, sonra 01 yapılır (set hâlâ aktif), sonra 11'e çekilir.
- İlk durum 0 için: önce 00, sonra 10 yapılır (reset aktif), sonra 11'e çekilir.

Preset ve clear uçları asenkron kontrollerdir, yani saat işaretinden bağımsız çalışırlar. Uçlar 11'e çekildiği anda saat gelse de gelmese de içerik birlenir ya da sıfırlanır.

Senkron clear istenirse, yani içeriğin saatle birlikte sıfırlanması istenirse, D flip-flop'a en az müdahaleyle şu yapılır: D girişi, dışarıdan gelen veri ile clear sinyalinin AND'i olarak bağlanır. Clear'a 0 verilince AND çıkışı 0 olur ve D'ye 0 gelir. Ama yükselen kenar gelmeden içerik sıfırlanmaz; ancak bir sonraki yükselen kenarda sıfırlanır. Böylece sıfırlama saatle senkron olur.

## 10. Ardışıl devre tasarımı: T flip-flop ile seri toplayıcı

### 10.1 Problem

Problem: seri toplayıcı ardışıl devresini T flip-flop kullanarak tasarlayınız. Seri toplayıcı iki $n$ bitlik sayıyı seri olarak toplar; içinde iki $n$ bitlik sayıyı tutması beklenmez. Önce $X_0$ ve $Y_0$ girilir, karşılığında $S_0$ çıkar; bir saat adımı sonra $X_1$ ve $Y_1$ girilir, $S_1$ çıkar ve bu böyle sürer (ekrandan, 02:55:00). Yapının iki girişi ($X$, $Y$) ve bir çıkışı ($S$) vardır. Bunu düzgün yapabilmesi için önceki basamakta elde oluşup oluşmadığını tutması gerekir.

### 10.2 Durum diyagramı

İki durum vardır: "son işlemde elde yok" ve "son işlemde elde var". Elde yoksa yapılan işlem yarım toplayıcı gibi, elde varsa tam toplayıcı gibidir. Bunu tutmak için tek bir bellek elemanı yeter.

Hoca iki gösterimi hatırlattı. Çıkış hem girişe hem duruma bağlıysa geçiş okunun üzerine "giriş/çıkış" yazılır; bu Mealy makinesidir. Çıkış yalnız duruma bağlıysa çıkış durumun içine, altına yazılır; bu Moore makinesidir. Seri toplayıcının çıkışı hem girişlere hem duruma bağlı olduğu için Mealy makinesi kullanılır.

Başlangıç durumu "elde yok"tur (en düşük anlamlı bitlerde önceki işlemden elde gelmez). Geçişler $XY/S$ biçiminde:

- Elde yok (0) durumunda: $00/0$, $01/1$, $10/1$ ile aynı durumda kalınır ($0+0+0 = 0$, $0+1+0 = 1$). $11/0$ ile "elde var" durumuna geçilir: toplam 0, elde 1.
- Elde var (1) durumunda: $01/0$, $10/0$ ile kalınır ($1+0+1$: toplam 0, elde 1); $11/1$ ile kalınır ($1+1+1$: toplam 1, elde 1). $00/1$ ile "elde yok" durumuna dönülür ($0+0+1$: toplam 1, elde yok).

Durum kodlaması doğrudan yapılır: elde yok 0, elde var 1. İki durum için tek durum değişkeni, yani tek T flip-flop yeterlidir.

### 10.3 Durum tablosu ve ters tanım bağıntısı

Amaç, T flip-flop'un girişine $q$, $X$ ve $Y$'nin hangi fonksiyonunun bağlanacağını ($T = f(q, X, Y)$) ve çıkışı ($S = f(q, X, Y)$) bulmaktır. $X$, $Y$ dış girişler, $q$ bellek elemanından gelen girdidir. Bunların bütün değerleri yazılır, $Q$ ve $S$ sütunları durum diyagramından doldurulur (ekrandan, 03:00:00).

T sütunu için ters tanım bağıntısı ileri yönlü tanımdan çıkarılır. İleri tanımda $T = 0$ durumu korur, $T = 1$ tersler. Buna göre:

| $q$ | $Q$ | $T$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Özetle: durum korunuyorsa $T = 0$, değişiyorsa $T = 1$. Tamamlanmış tablo:

```text
X Y q | Q S T
0 0 0 | 0 0 0
0 0 1 | 0 1 1
0 1 0 | 0 1 0
0 1 1 | 1 0 0
1 0 0 | 0 1 0
1 0 1 | 1 0 0
1 1 0 | 1 0 1
1 1 1 | 1 1 0
```

Tablo, $Q$ eldenin, $S$ toplamın biti olacak şekilde python ile doğrulandı.

### 10.4 Karnaugh haritaları ve devre

Hoca önce $S$ için haritayı doldurduğunu düşünürken aslında $T$ sütununu yerleştirdi ve $XY\bar q + \bar X \bar Y q$ ifadesini buldu; bunun $T$'nin ifadesi olduğunu fark edip $S$ haritasını yeniden doldurdu. Doğru sonuçlar:

$$T = XY\bar q + \bar X \bar Y q$$

$$S = q \oplus X \oplus Y$$

$S$ haritasındaki 0, 1, 1, 0 / 1, 0, 0, 1 deseni XOR yapısıdır. Devre: bir T flip-flop ($Q$ ve $\bar Q$ çıkışlı); $S$ üç girişli XOR'dan çıkar ($q$, $X$, $Y$). $T$ için $X$, $Y$ ve $\bar Q$ üç girişli bir AND'e, $\bar X$, $\bar Y$ ve $Q$ ikinci bir üç girişli AND'e girer; iki AND bir OR'da birleşip $T$ ucuna bağlanır. Burada $X$ ve $Y$, sayıların sıradaki anlam basamağındaki bitleridir; $S$ o basamağın toplam biti, T flip-flop ise son işlemden elde olup olmadığını tutan durumdur.

## 11. Verilog'a kısa giriş

İki donanım tanımlama dili (HDL) yaygındır: Verilog ve VHDL. Derste Verilog örnekleri incelenecek. Hoca, Windows ve Linux için hazır sürümleri olan Icarus Verilog'u tanıttı; Windows kurulumu GTKWave dalga biçimi görüntüleyicisini de getirir. Verilog'la yazılan tasarımlar, FPGA kartlarına anahtar ve çıkış bağlantıları yapılarak aktarılabilir ve fiziksel bir sisteme dönüştürülebilir.

Temel kurallar:

- Her kod bloğu bir modüldür: `module` ile başlar, `endmodule` ile biter.
- `module` kelimesinden sonra modülün adı gelir; bu modül başka yerlerden çağrılabilir. Parametreler parantez içinde virgülle ayrılır.
- `endmodule` dışında her satır noktalı virgülle biter.
- Sonraki satırlar parametrelerin `input` mu `output` mu olduğunu bildirir.
- `xor` ve `and` gibi kapılar hazır modüllerdir; ilk parametre çıkış, diğerleri giriştir.

Yarım toplayıcı yapısal (structural) olarak şöyle tanımlanır (ekrandan, 03:05:00):

```verilog
module half_adder(x,y,s,c);
    input x,y;
    output s,c;
    xor(s,x,y);
    and(c,x,y);
endmodule
```

Bir adım ötesi hiyerarşik tanımdır: daha önce tanımlanmış `half_adder` modülünden iki örnek (instance) oluşturulur ve bir `or` kapısıyla, derste anlatıldığı gibi tam toplayıcı kurulur. `wire` anahtar kelimesi, giriş ya da çıkış olmayan ama bir kapının çıkışını başka bir kapıya bağlayan ara telleri tanımlar. Birinci yarım toplayıcı iki girişi toplar, ikincisi onun toplamını eldeyle toplar, eldeler OR'lanarak $C_{out}$ üretilir. Modülleri sınamak için bir testbench yazılır ve modülle birlikte derlenir.

Derleme komutu (ekrandan, 03:10:00):

```text
iverilog -ohalf_adder half_adder.vl
```

Derleme sonunda bir çıktı dosyası oluşur. Testbench'in ürettiği dalga biçimi GTKWave'de incelenerek girişlere karşılık istenen çıkışların üretilip üretilmediği kontrol edilir. Hoca Verilog'a ayrı bir ders ayrılmayacağını, örnekler yapılırken Verilog karşılıklarının gösterileceğini söyledi.

**Soru:** Bu programda tasarlanan devreyi görsel olarak gösterme seçeneği var mı? **Cevap:** Icarus Verilog'da bu açıdan zengin bir seçenek yoktur. Altera'nın Quartus programında farklı seviyelerde tasarım yapılabiliyordu; lojik kapı seviyesinde yapılan bir tasarımı Verilog koduna dönüştürmek de mümkündü. Intel, Altera'yı satın aldı ve Quartus'u artık kendi lisansıyla veriyor.

Hoca Verilog'u neden gösterdiğini de açıkladı: tanımlanan donanımın bir yazılım karşılığıyla da gerçeklenebildiğini görmek ve bilmek gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Tam toplayıcıyı ($(C_{out} S)_2 = A + B + C_{in}$) 3x8 dekoder ile gerçekleyiniz.

> **Çözüm (derste verildi):** Tablo $A, B, C_{in}$ sırasında yazılır: $C_{out} = \sum m(3,5,6,7)$, $S = \sum m(1,2,4,7)$. $A$ dekoderin en anlamlı ($C$) ucuna, $B$ $B$ ucuna, $C_{in}$ $A$ ucuna bağlanır, enable = 1. Aktif 1 çıkışlı dekoderde $C_{out} = Y_3 + Y_5 + Y_6 + Y_7$, $S = Y_1 + Y_2 + Y_4 + Y_7$ (iki OR kapısı). Aktif 0 çıkışlı dekoderde $C_{out} = \bar Y_0 \cdot \bar Y_1 \cdot \bar Y_2 \cdot \bar Y_4$, $S = \bar Y_0 \cdot \bar Y_3 \cdot \bar Y_5 \cdot \bar Y_6$ (iki AND kapısı).

**Soru 2** (derste sözlü, 00:42:27): 2x4 dekoderlerle kurulan 4x16 dekoder ağacında, 4x16 dekoderin en anlamlı seçim ucu $D$'ye hangi uç ($w_0 \dots w_3$) karşılık gelir?

> **Çözüm (derste verildi):** $D$'nin 0'dan 1'e geçmesi çıkışı 8 basamak kaydırmalıdır (0000 $\to y_0$, 1000 $\to y_8$). $w_0$ 1, $w_1$ 2, $w_2$ 4, $w_3$ 8 basamak kaydırır. Bu yüzden $w_3 = D$, $w_2 = C$, $w_1 = B$, $w_0 = A$.

**Soru 3** (ekrandan, 01:35:00): Yarım toplayıcılar ve gerekli lojik kapıları kullanarak tam toplayıcı gerçekleyiniz.

> **Çözüm (derste verildi):** HA1($A$, $B$) $\to C_1, S_1$; HA2($S_1$, $C_{in}$) $\to C_2, S$. $C_{out} = C_1 + C_2$ (bir OR kapısı).

**Soru 4** (ekrandan, 01:40:00): Sadece yarım toplayıcılar kullanarak tam toplayıcı gerçekleyiniz.

> **Çözüm (derste verildi):** Soru 3'teki ilk iki yarım toplayıcı aynen kullanılır. OR yerine üçüncü bir yarım toplayıcı konur: HA3($C_1$, $C_2$); toplam çıkışı $C_{out}$'tur, eldesi kullanılmaz. Üç bitin toplamı iki bite sığdığı için $C_1$ ve $C_2$ aynı anda 1 olamaz.

**Soru 5** (derste sözlü, 01:48:07): 8 bitlik 4'e 1 MUX'u 1 bitlik 4'e 1 MUX'lar kullanarak nasıl gerçeklersiniz?

> **Çözüm (derste verildi):** 8 tane 1 bitlik 4'e 1 MUX kullanılır. $i$. MUX'un $w_0 \dots w_3$ girişlerine dört sayının $i$. bitleri bağlanır. Bütün MUX'ların $S_0$ uçları ortak, $S_1$ uçları ortaktır. Seçim ucu sayısı $\log_2 4 = 2$'dir.

**Soru 6** (ekrandan, 01:55:00): 16 bitlik tam toplayıcı kullanarak 32 bitlik tam toplayıcı gerçekleyiniz.

> **Çözüm (derste verildi):** İki 16 bitlik toplayıcı kaskat bağlanır. $X$ ve $Y$'nin düşük anlamlı 16 biti birinciye, yüksek anlamlı 16 biti ikinciye girer. Birincinin $C_{out}$'u ikincinin $C_{in}$'ine bağlanır; sistemin $C_{in}$'i birinciye, $C_{out}$'u ikinciden alınır. Sonuç 33 bittir.

**Soru 7** (derste sözlü, 01:57:40): Kaskat bağlı tam toplayıcılarla oluşturulan 16 bitlik toplayıcının sorunu nedir?

> **Çözüm (derste verildi):** Gecikme. Elde katlar boyunca sırayla yayılır (ripple carry); doğru sonuç için toplam gecikme beklenmelidir ve bu süre boyunca çıkışlar sürekli değişir.

**Soru 8** (derste sözlü, 02:01:24): XOR kapısından NOT kapısı nasıl yapılır?

> **Çözüm (derste verildi):** Girişlerden biri 1'e sabitlenir: $X \oplus 1 = \bar X$. Bir girişi 0 olan XOR ise diğer girişi aynen geçirir: $X \oplus 0 = X$.

**Soru 9** (derste sözlü, 02:09:47): Eşitlik karşılaştırıcısının son katında, bütün girişleri 0 iken 1, en az bir girişi 1 iken 0 üreten kapı hangisidir?

> **Çözüm (derste verildi):** NOR kapısı (OR'un çıkışına NOT konmuş hali).

**Soru 10** (derste sözlü, 02:26:05): Latch ile flip-flop arasındaki temel fark nedir?

> **Çözüm (derste verildi):** Latch'in enable ucu seviye tetiklemelidir (enable aktif olduğu sürece giriş çıkışa geçer); flip-flop'un enable ucu kenar tetiklemelidir (giriş yalnız yükselen ya da düşen kenarda örneklenir).

**Soru 11** (ekrandan, 02:55:00): Seri toplayıcı ardışıl devresini T flip-flop kullanarak tasarlayınız.

> **Çözüm (derste verildi):** İki durumlu Mealy makinesi (elde yok = 0, elde var = 1), tek T flip-flop. Durum tablosu 10.3'tedir. $S = X \oplus Y \oplus q$, $T = XY\bar q + \bar X \bar Y q$.

## Dersin Toparlaması

Bu derste lojik devreler tekrarı tamamlanmaya yaklaştı. Kombinasyonel tarafta dekoderlerin minterm ve maksterm ürettiği, bu yüzden her fonksiyonu gerçekleyebildiği gösterildi; DEMUX, enkoder ve öncelik enkoderi incelendi. Yarım ve tam toplayıcılar kapı seviyesinde kuruldu, küçük bloklardan büyük blok kurma (hiyerarşi) fikri MUX, dekoder ve toplayıcı örnekleriyle hem yukarı hem aşağı yönde işlendi. Toplayıcı-çıkarıcı, eşitlik karşılaştırıcısı ve ortak veri yolları için tri-state buffer görüldü. Ardışıl tarafta latch ile flip-flop farkı, D, T ve JK tanımları, preset/clear uçları anlatıldı ve T flip-flop ile seri toplayıcı adım adım tasarlandı.

Dersin sonunda Verilog'a kısa bir giriş yapıldı: yarım toplayıcının yapısal tanımı, hiyerarşik tam toplayıcı ve Icarus Verilog ile derleme. Hoca sonraki derslerde registerlar ve daha karmaşık ardışıl devrelere geçileceğini, örneklerin Verilog karşılıklarının da gösterileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
