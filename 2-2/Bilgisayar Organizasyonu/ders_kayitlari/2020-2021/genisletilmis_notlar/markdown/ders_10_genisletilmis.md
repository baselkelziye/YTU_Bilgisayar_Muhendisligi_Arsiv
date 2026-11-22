# Ders 10 Genişletilmiş Notu: ALU, Kaydırıcı, Kontrol Kelimesi ve Tek Çevrimli Bilgisayar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Register File ve Aritmetik Birim
- 2. Lojik Birim Tasarımı
- 3. Aritmetik ve Lojik Birimin Birleştirilmesi
- 4. Örnek: Giriş Lojiğinden Fonksiyon Tablosuna
- 5. Örnek: Kısıtlı 8 Bitlik ALU Tasarımı
- 6. Kaydırıcı ve Barrel Shifter
- 7. Function Unit'in Tamamı
- 8. Kontrol Kelimesi
- 9. Kontrol Kelimesi Örnekleri
- 10. ALU Durum Bitleri
- 11. Bellekler, Program Sayacı ve Komut Biçimleri
- 12. Basit Bilgisayarın Komut Kümesi
- 13. Bellekteki Komutların Çözülmesi
- 14. Tek Çevrimli Bilgisayarın Tamamı ve Komut Çözücü
- 15. Kritik Yol
- 16. Soru-Cevap: Bekleme Süresi, İş Hattı ve Tek Komutlu Makineler
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Register File ve Aritmetik Birim

Bir önceki derste tek çevrimli bilgisayarın (single cycle computer) fonksiyonel bloklarına başlanmıştı. Şu ana kadar iki ana blok görüldü: register file ve function unit. Bunlara daha sonra komut çözücü (instruction decoder), bellek ve program sayacı (program counter) lojiği eklenecek.

Register file'ın iki çıkış kanalı vardır: A ve B. A kanalına hangi yazmacın çıkacağını bir adres seçim ucu, B kanalına hangisinin çıkacağını başka bir adres seçim ucu belirler. A ve B kanallarından çıkan değerler function unit'te işlenir ve sonuç tekrar register file'ın D (data in) girişine gelir. Bu sonucun hangi yazmaca yazılacağını D adres uçları, yazma yapılıp yapılmayacağını write kontrolü belirler. Böylece herhangi iki yazmaç A ve B kanallarına çıkar (ikisi aynı yazmaç da olabilir) ve sonuç herhangi bir yazmaca yazılabilir. İç yapıda, örneğin 4 yazmaçlı bir register file'da, A ve B kanalları için birer MUX bulunur. Yazma işlemi ise yazmaçların load uçlarının kontrolüyle yapılır: D kanalındaki veri ortak yol üzerinden bütün yazmaçlara gider, yalnız seçilenin load ucu etkinleşir.

Function unit iki birimden oluşur: aritmetik lojik birim (ALU) ve kaydırıcı (shifter). Önceki derste ALU, aritmetik birim ve lojik birim olarak ikiye ayrılmış ve aritmetik birim tasarlanmıştı (ekrandan, 00:05:00). Bu tasarımda $n$ bitlik paralel tam toplayıcı kullanılır. Fonksiyon tablosu şöyledir:

| $S_1$ | $S_0$ | Y girişi | $C_{in} = 0$ | $C_{in} = 1$ |
|---|---|---|---|---|
| 0 | 0 | hepsi 0 | $G = A$ (transfer) | $G = A + 1$ (artırma) |
| 0 | 1 | $B$ | $G = A + B$ (toplama) | $G = A + B + 1$ |
| 1 | 0 | $\overline{B}$ | $G = A + \overline{B}$ | $G = A + \overline{B} + 1$ (çıkarma) |
| 1 | 1 | hepsi 1 | $G = A - 1$ (azaltma) | $G = A$ (transfer) |

Bu yapıda A kanalı doğrudan tam toplayıcının X girişine bağlıdır. B kanalı bir giriş lojiğinden (input logic) geçerek Y girişine bağlanır. $C_{in}$ ise doğrudan dışarıdan verilen bir kontroldür.

Hoca bit dilimi (bit slice) çizimi için bir kural koydu. Bit dilimi denince 0. ya da $n$. bit değil, ortadaki herhangi bir bit anlaşılır. Sizden bit dilimi çizmeniz istenirse ortadaki bir katı çizersiniz. 0. bit ve en yüksek anlamlı bit için özel durumlar varsa ayrıca belirtirsiniz. Örneğin en yüksek anlamlı katın elde çıkışı bütün toplayıcının $C_{out}$'udur, diğer elde çıkışları bir sonraki katın girişidir. 0. katın elde girişi ise dışarıdan verilen $C_{in}$ kontrolüne bağlıdır.

> **Hocanın vurgusu:** Dış $C_{in}$ girişi her bir 1 bitlik tam toplayıcının elde girişine bağlı değildir. Yalnız en düşük anlamlı tam toplayıcının elde girişine bağlıdır. Önceki haftanın çözümlemesini bu gözle tekrar edin.

En genel aritmetik birimde üç lojik bulunur: A giriş lojiği, B giriş lojiği ve elde girişi lojiği. Kanallar X, Y ve $C_{in}$'e doğrudan bağlı olmayabilir. Elde girişi de girdilerin bir fonksiyonu olarak belirlenebilir. Bir öğrencinin önceki dersteki sorusuna da cevap verildi: bu giriş lojikleri basit kapılar yerine MUX'larla da kurulabilir ve devre daha basit olur.

Aritmetik birimde bir kanala bütün bitleri 1 olan değer (1111...) bağlanırsa, ikiye tümleyen gösterimde bu $-1$ demektir. $C_{in} = 1$ ise $+1$ gelir. Bir kanala 0 bağlanırsa öbür kanal olduğu gibi aktarılır. Bu üç durumu birleştirerek birbirinden farklı aritmetik fonksiyonlar elde edilebilir.

## 2. Lojik Birim Tasarımı

Lojik birimin blok yapısında iki kontrol ucu ($S_1$, $S_0$), iki adet $n$ bitlik giriş kanalı (A ve B) ve bir adet $n$ bitlik G çıkışı vardır. Tasarım yine fonksiyon tablosundan başlar (ekrandan, 00:15:00):

| $S_1$ | $S_0$ | Çıkış | İşlem |
|---|---|---|---|
| 0 | 0 | $G = A \wedge B$ | AND |
| 0 | 1 | $G = A \vee B$ | OR |
| 1 | 0 | $G = A \oplus B$ | XOR |
| 1 | 1 | $G = \overline{A}$ | NOT |

Bu işlemler bit düzeyindedir (bitwise). Aritmetik toplamadaki gibi düşük anlamlı bitten yüksek anlamlı bite elde taşınmaz. Her bit diğerlerinden bağımsız işleme girer. Bu yüzden tek bir bit için bir blok tasarlanır ve bu bloktan $n$ tane kullanılır.

Dört işlemden birini seçmek için bir 4'e 1 MUX kullanılır. Seçim uçlarına 00 verildiğinde MUX 0 numaralı girişini dışarı aktarır. O hâlde 0 numaralı girişe $A_i$ ile $B_i$'nin AND'i bağlanır. Aynı şekilde 1 numaralı girişe OR, 2 numaralı girişe XOR, 3 numaralı girişe $\overline{A_i}$ bağlanır.

Bütün yapı için bu MUX'lardan $n$ tane dizilir: 0. bitin çıkışı $G_0$, 1. bitin çıkışı $G_1$, sonuncunun çıkışı $G_{n-1}$ olur. Bütün MUX'lar aynı anda aynı fonksiyonu yerine getirmelidir. Bu yüzden seçim uçları ortaklanır ve $S_1$, $S_0$ olarak dışarı çıkarılır. Hoca bunu, bütün MUX'lardaki seçim uçlarını birleştiren tek bir hat olarak çizdi. 0. katın kapılarına $A_0$ ve $B_0$, 1. katın kapılarına $A_1$ ve $B_1$, son katın kapılarına $A_{n-1}$ ve $B_{n-1}$ girer. Böylece lojik birimin tasarımı baştan sona tamamlanır.

## 3. Aritmetik ve Lojik Birimin Birleştirilmesi

Lojik birim MUX'larla kurulabildiğine göre aritmetik birimdeki giriş lojikleri de MUX'larla kurulabilir. Şimdi soru şudur: aritmetik birimle lojik birimi nasıl birleştiririz?

İki birim de kombinasyonel devredir. Verilen kontrol ve giriş işaretlerine göre ikisi de her an sonuç üretir. Örneğin aritmetik birimde $A + B$, lojik birimde aynı anda $A \wedge B$ oluşur. Function unit'in çıkışına hangisinin aktarılacağını belirlemek için fazladan bir seçim (kontrol) ucu tanımlanır. Bu uç, aritmetik birimin mi lojik birimin mi çıkışının dışarı aktarılacağını seçen bir MUX katını kontrol eder. İki birimin fonksiyon tabloları da birleştirilir ve ALU'nun fonksiyon tablosu elde edilir.

Sonraki adım ALU'dan ayrı duran kaydırıcıdır. Ama önce iki örnek soru çözüldü.

## 4. Örnek: Giriş Lojiğinden Fonksiyon Tablosuna

Bu soruda olaya tersten yaklaşılır (ekrandan, 00:20:00). Önceki örneklerde fonksiyon tablosu verilir, tasarım istenirdi. Burada ise giriş lojikleri verilir ve fonksiyon tablosu istenir. Soru metni Örnek Sorular bölümündedir: 4 bitlik aritmetik devrede her tam toplayıcının girişleri

$$X_i = A_i, \qquad Y_i = \overline{B_i}\,S + B_i\,\overline{C_{in}}$$

ile verilir. Elde girişi lojiği doğrudan aktarmadır, yani $C_{in}$ doğrudan toplayıcının elde girişine gider. A giriş lojiği de doğrudan aktarmadır. Yalnız B giriş lojiği bir fonksiyondur. Birimde bir kontrol ucu (S) vardır, ama $C_{in}$ ile birlikte iki kontrol değişkeni olduğu için 4 farklı fonksiyon oluşabilir. X'e her durumda $A_i$ gelir, yani X kanalında hep A sayısı vardır.

**$S = 0$, $C_{in} = 0$:** S sıfır olduğu için ilk terim düşer. $\overline{C_{in}} = 1$ olduğu için $Y_i = B_i$. X'te A, Y'de B, elde 0: $F = A + B$.

**$S = 0$, $C_{in} = 1$:** İlk terim yine düşer, $\overline{C_{in}} = 0$ olduğu için ikinci terim de düşer: $Y_i = 0$. A ile 0 toplanır ama elde 1'dir: $F = A + 1$.

**$S = 1$, $C_{in} = 0$:** $Y_i = \overline{B_i} + B_i = 1$. Hoca burada öğrencilere bir değerin kendisiyle değilinin toplamının ne olduğunu sordu; cevap 1'dir. Y'nin bütün bitleri 1 olduğu için Y ikiye tümleyende $-1$'dir. Elde 0: $F = A - 1$.

**$S = 1$, $C_{in} = 1$:** İkinci terim düşer, $Y_i = \overline{B_i}$. Y'de B'nin bire tümleyeni var, elde 1: $F = A + \overline{B} + 1 = A - B$. Bire tümleyen alıp 1 eklemek ikiye tümleyende $-B$ demektir.

| $S$ | $C_{in} = 0$ | $C_{in} = 1$ |
|---|---|---|
| 0 | $F = A + B$ | $F = A + 1$ |
| 1 | $F = A - 1$ | $F = A - B$ |

Bu tablo python ile 4 bitlik bütün $A$, $B$ değerleri için kaba kuvvetle doğrulandı.

Sorunun ikinci kısmında aynı birim, daha az elemanla, yalnız MUX'larla kurulur. 4 bitlik toplayıcının X girişlerine $A_0 \ldots A_3$ doğrudan bağlanır. Seçim Y tarafında yapılır. Her bit için bir 4'e 1 MUX kullanılır, yüksek anlamlı seçim ucuna S, düşük anlamlı seçim ucuna $C_{in}$ bağlanır. $C_{in}$ ayrıca toplayıcının elde girişine de doğrudan gider.

- 0 numaralı giriş ($S = 0$, $C_{in} = 0$, $A + B$): $B_i$
- 1 numaralı giriş ($S = 0$, $C_{in} = 1$, $A + 1$): 0 ($+1$ zaten elde girişinden gelir)
- 2 numaralı giriş ($S = 1$, $C_{in} = 0$, $A - 1$): 1 (bütün bitleri 1 olan Y, $-1$ demektir)
- 3 numaralı giriş ($S = 1$, $C_{in} = 1$, $A - B$): $\overline{B_i}$ ($+1$ elde girişinden gelir)

Hoca bu sorunun, konuyu ters yönden görmek açısından anlamlı olduğunu söyledi.

## 5. Örnek: Kısıtlı 8 Bitlik ALU Tasarımı

İkinci soru, 8 bitlik A ve B girişlerinden 8 bitlik F çıkışı üreten bir ALU tasarımıdır (ekrandan, 00:30:00). Soru metni ve fonksiyon tablosu Örnek Sorular bölümündedir. Tabloya bakınca ilk 8 satırın aritmetik, son 4 satırın lojik işlem olduğu görülür. Hoca 3. bölümdeki fikri hatırlattı: aritmetik ve lojik birim arasındaki seçimi bir MUX yapar. Bu seçimin hangi uçla yapıldığı tablodan doğrudan okunur.

### 5.1 Birimlerin kontrol uçları

ALU'nun genel blok yapısında 4 kontrol işareti ($S_3 \ldots S_0$), iki adet 8 bitlik giriş ve bir adet 8 bitlik çıkış vardır. Bir adım içeri girilince:

- Lojik birim satırlarında $S_3$ ve $S_2$ hep aynı değerdedir ($S_3 = 1$, $S_2 = 0$). 4 farklı işlem $S_1$ ve $S_0$ ile seçilir. Lojik birimin kontrol uçları $S_1$, $S_0$'dır.
- 8 farklı aritmetik işlemi $S_2$, $S_1$ ve $S_0$ belirler. Aritmetik birimin kontrol uçları bunlardır.
- Seçim: $S_3 = 1$ iken lojik birim, $S_3 = 0$ iken aritmetik birim seçilir.

Hazır çözümde lojik birim seçimi için $S_3\overline{S_2}$ yazılmıştı. Hoca burada küçük bir hata gördü ve yalnız $S_3$'e bakmanın yeterli olduğunu söyledi. Çıkış MUX'unun seçim ucu $S_3$'tür.

### 5.2 Lojik birim

İki kontrol ucu olduğu için her bit dilimi için bir 4'e 1 MUX gerekir; toplam 8 MUX. Seçim uçları $S_1$, $S_0$'a bağlanır. Tabloya göre girişler sırasıyla AND, OR, $\overline{A}$ ve XOR'dur (bu tabloda NOT 10, XOR 11 satırındadır). Bu dilimden 8 tane kullanarak lojik birimin 8 bitlik çıkışı elde edilir.

### 5.3 Aritmetik birim

Aritmetik birimin 3 kontrol ucu olduğu için her bit dilimi için A lojiğinde bir 8'e 1 MUX, B lojiğinde bir 8'e 1 MUX gerekir. Seçim uçları ortaklanıp $S_2$, $S_1$, $S_0$ olarak dışarı çıkarılır. Kısıt gereği $S_0$ ayrıca tam toplayıcının $C_{in}$ girişine bağlanır. Bu kısıt, X ve Y'ye ne bağlanacağını serbestçe seçmemizi engeller. Her satırda elde girişinin değeri $S_0$ ile belirlenmiştir. Hoca tabloya X, Y ve $C_{in}$ sütunları ekleyerek çözdü (ekrandan, 00:40:00):

| $S_2S_1S_0$ | F | $C_{in}$ | X | Y | Açıklama |
|---|---|---|---|---|---|
| 000 | $A + B$ | 0 | $A_i$ | $B_i$ | $A + B + 0$ |
| 001 | $A$ | 1 | $A_i$ | 1'ler | $A + (-1) + 1$ |
| 010 | $B$ | 0 | 0'lar | $B_i$ | $0 + B + 0$ |
| 011 | $A + 1$ | 1 | $A_i$ | 0'lar | $+1$ elde girişinden |
| 100 | $A - 1$ | 0 | $A_i$ | 1'ler | $-1$ ikiye tümleyende |
| 101 | $B + 1$ | 1 | 0'lar | $B_i$ | $+1$ elde girişinden |
| 110 | $B - 1$ | 0 | 1'ler | $B_i$ | $-1$ X tarafından |
| 111 | $A - B$ | 1 | $A_i$ | $\overline{B_i}$ | $A + \overline{B} + 1$ |

Buna göre örneğin 0. bit diliminde X MUX'unun girişleri sırasıyla $A_0, A_0, 0, A_0, A_0, 0, 1, A_0$, Y MUX'unun girişleri $B_0, 1, B_0, 0, 1, B_0, B_0, \overline{B_0}$ olur. Burada "1" ve "0", o bitin sabit değeridir. Bütün bitlere 1 verilince kanal $-1$ olur.

Bu bağlantılar 8 satırın hepsi için python ile 8 bitlik değerler üzerinde kontrol edildi ve tabloyla uyumlu çıktı.

> **Ders sonrası not:** Altyazıda X girişleri "A0, A0, 0, A0, A0, A0, 1, A0" diye geçiyor. Hocanın ekrandaki tablosuna göre 5 numaralı giriş ($B + 1$ satırı) 0 olmalıdır. Altyazıdaki fark büyük olasılıkla bir okuma ya da Whisper hatasıdır.

Hoca çözüm yöntemini şöyle özetledi: fonksiyon tablosuna göre $C_{in}$'in her satırı nasıl kısıtladığı belirlenir, sonra X ve Y'ye bağlanacak değerler buna göre seçilir.

## 6. Kaydırıcı ve Barrel Shifter

### 6.1 Kaydırıcının girişi

ALU'nun iki girişi ve bir çıkışı vardır. Kaydırıcının ise tek girişi vardır ve bu yapıda bu giriş B kanalıdır. Örneğin R1'i bir kez sola kaydırmak istiyorsak R1'in B kanalına aktarılması ve kaydırıcıya ilgili kontrol işaretlerinin verilmesi gerekir.

> **Hocanın vurgusu:** Kaydırılacak değer mutlaka B kanalından kaydırıcıya aktarılmalıdır. Bu tasarım için buna dikkat edin.

### 6.2 4 bitlik kaydırıcı

Kaydırıcının fonksiyon seçimi 2 bittir (S), yani 4 farklı işlem tanımlanabilir (ekrandan, 00:45:00). Her çıkış biti ($H_3 \ldots H_0$) için bir MUX vardır. MUX'ların yalnız 3 girişi kullanıldığı için $S = 11$ durumu tanımsızdır. Fonksiyon tablosu çizimden çıkarılır:

- **$S_1S_0 = 00$:** 0 numaralı girişler aktarılır. $B_3 \to H_3$, $B_2 \to H_2$, $B_1 \to H_1$, $B_0 \to H_0$. Fonksiyon $H = B$ (transfer).
- **$S_1S_0 = 01$:** Sağdan seri giriş $I_R$, $H_3$'e yüklenir. $B_3 \to H_2$, $B_2 \to H_1$, $B_1 \to H_0$. Bu sağa ötelemedir: $H = sr\,B$.
- **$S_1S_0 = 10$:** Sol seri giriş $I_L$, $H_0$'a yüklenir. $B_0 \to H_1$, $B_1 \to H_2$, $B_2 \to H_3$. Çıkış $B_2 B_1 B_0 I_L$ olur. Bu sola ötelemedir: $H = sl\,B$.

| $S_1S_0$ | Fonksiyon |
|---|---|
| 00 | $H = B$ |
| 01 | $H = sr\,B$ |
| 10 | $H = sl\,B$ |
| 11 | tanımsız |

Bu iç yapı, MUX'ların girişlerine uygun kaydırma sırasıyla bağlantı yapılarak elde edilir.

### 6.3 Barrel shifter

Kaydırıcı olarak döndürme (rotate) fonksiyonları da kullanılabilir. Bu yapıya barrel shifter denir (ekrandan, 00:50:00):

| $S_1$ | $S_0$ | $Y_3$ | $Y_2$ | $Y_1$ | $Y_0$ | İşlem |
|---|---|---|---|---|---|---|
| 0 | 0 | $D_3$ | $D_2$ | $D_1$ | $D_0$ | Döndürme yok |
| 0 | 1 | $D_2$ | $D_1$ | $D_0$ | $D_3$ | Bir konum döndürme |
| 1 | 0 | $D_1$ | $D_0$ | $D_3$ | $D_2$ | İki konum döndürme |
| 1 | 1 | $D_0$ | $D_3$ | $D_2$ | $D_1$ | Üç konum döndürme |

Her çıkışta bir 4'e 1 MUX vardır (giriş burada D olarak adlandırılmış, B kanalının değerleridir). 00 kontrolünde transfer yapıldığı için her MUX'un 0 numaralı girişine aynı sıradaki D biti bağlanır. 01 kontrolünde bir konum sola döndürme vardır: $D_2$, $Y_3$'ün; $D_1$, $Y_2$'nin; $D_0$, $Y_1$'in; $D_3$, $Y_0$'ın 1 numaralı girişine bağlanır. 10 için iki adım kaydırılır: $D_1 \to Y_3$, $D_0 \to Y_2$, $D_3 \to Y_1$, $D_2 \to Y_0$ (2 numaralı girişler). 11 için üç adım: $D_3 \to Y_2$, $D_1 \to Y_0$, $D_0 \to Y_3$, $D_2 \to Y_1$ (3 numaralı girişler). Kontrol uçlarına hangi değer verilirse ilgili döndürmenin karşılığı o girişte hazırdır.

## 7. Function Unit'in Tamamı

Function unit içinde ALU ve kaydırıcı vardır. ALU'nun içinde aritmetik birimden mi lojik birimden mi değer çıkacağını bir MUX seçer. ALU ile kaydırıcı da kombinasyonel devredir ve ikisi de sonuç üretir. Hangisinin function unit'in dışına çıkacağını MUX F seçer, seçim ucu MF'dir.

FS (function select) 4 bitlik uçtur. FS'nin son iki biti kaydırıcının kontrol uçlarına da bağlıdır. FS'nin bütün bitleri belirli bir serbestlikle ALU'nun kontrol uçlarına bağlıdır. ALU'nun 16 değil 12 fonksiyonu olduğu için bir giriş don't care kullanılabilir (lojik satırlarında $S_2$ = X, ekrandan, 01:20:00). Her FS koduna karşılık gelen mikro işlemler önce aritmetik birim, sonra lojik birim, sonra kaydırıcı için sıralanır ve function unit'in fonksiyon tablosu oluşur. Ders boyunca kullanılan FS kodları şunlardır (ekrandan, 01:20:00 ve 01:25:00; tablonun ilk satırları altyazıdan ve FS örneklerinden):

| FS | İşlem | FS | İşlem |
|---|---|---|---|
| 0000 | $F = A$ | 1000 | $F = A \wedge B$ |
| 0001 | $F = A + 1$ | 1001 | $F = A \vee B$ |
| 0010 | $F = A + B$ | 1010 | $F = A \oplus B$ |
| 0011 | $F = A + B + 1$ | 1011 | $F = \overline{A}$ |
| 0100 | $F = A + \overline{B}$ | 1100 | $F = B$ |
| 0101 | $F = A + \overline{B} + 1$ | 1101 | $F = sr\,B$ |
| 0110 | $F = A - 1$ | 1110 | $F = sl\,B$ |
| 0111 | $F = A$ | | |

<!-- BELİRSİZ: 0000, 0001 ve 1100 satırları karelerde tam görünmüyor; 0000 (transfer A), 0001 (increment) ve 1110 (shift left) altyazıda geçiyor, 1100 ve 1101 komut tablosundaki MOVB ve SHR'den çıkarıldı. -->

Bu noktadan sonra, şimdiye kadar elle verilen kontrol değerlerinin daha düzenli verilmesi ele alınır: kontrol kelimesine verilen değerler hangi fonksiyonlara karşılık gelir, bir fonksiyonu gerçekleştirmek için kontrol kelimesi ne olmalıdır?

Hoca aradan önce bir ayrımı vurguladı. Kontrol kelimesi (control word), yapılacak işlemin seyrek (sparse) gösterimidir ve doğrudan bir komuta (instruction) karşılık gelmez. Komutlar daha paketlenmiş, kodlanmış bir yapıdır. Komuttan kontrol kelimesini elde etmek için bir dönüştürücü, yani komut çözücü gerekir. Bellek, program belleği gibi birimler eklendikçe kontrol kelimesi büyüyecek, komut ise daha az bitle ifade edilecektir.

## 8. Kontrol Kelimesi

### 8.1 MUX B ve MUX D

Datapath'te iki MUX seçimi daha vardır (ekrandan, 01:15:00). Komut kümesi mimarisinde görülen anlık (immediate) adreslemede komut içinde sabit bir değer gelir. 8086'daki `MOV AL, 0H` atamaya, `ADD AL, 3` ise function unit'te sabit kullanmaya örnektir. AL'nin R1'e karşılık geldiğini düşünürsek R1 ile 3 toplanacaktır. Komuttan gelen sabitin function unit'e aktarılabilmesi gerekir. Bunun için MUX B vardır. Sabit yalnız function unit'in B girişine aktarılabilir. MUX B'nin 1 bitlik seçim ucu MB, B girişine register file'ın B kanalının mı sabitin mi gideceğini belirler: MB = 0 ise B kanalı, MB = 1 ise sabit (constant in).

Bir de bellek birimi düşünelim. Register file'daki bir değeri belleğin belirli bir adresine yazmak isteyebiliriz. Bu durumda A kanalı adres (address out), B kanalı veri (data out) işlevi görür. Tersine bellekten okunan değeri bir yazmaca aktarmak da isteyebiliriz. Bunun için MUX D vardır: register file'a geri yazılacak değer function unit'ten mi bellekten (data in) mi gelecek? MD = 0 ise function unit, MD = 1 ise data in seçilir.

Şemada gri bloklar kombinasyonel, mavi bloklar sıralı (sequential) devrelerdir. Sıralı bloklarda durum yalnız saatin örneğin yükselen kenarında değişir. Kombinasyonel bloklar ise herhangi bir girişteki değişime hemen çıkış üretir.

### 8.2 Kontrol kelimesinin alanları

Register file içinde 8 adet $n$ bitlik yazmaç vardır ($8 \times n$). 8 yazmaçtan birini A kanalında seçmek için 3 bit, B kanalında seçmek için 3 bit, sonucun yazılacağı yazmacı seçmek için 3 bit gerekir. Yazma için 1 bit (RW), MUX B için 1 bit, FS için 4 bit, MUX D için 1 bit gerekir. Toplam 16 bitlik bir kontrol kelimesi elde edilir:

| Bitler | 15-13 | 12-10 | 9-7 | 6 | 5-2 | 1 | 0 |
|---|---|---|---|---|---|---|---|
| Alan | DA | AA | BA | MB | FS | MD | RW |

DA, AA ve BA için yazmaçlar 0'dan 7'ye numaralıdır ve 3 bitle kodlanır; örneğin 100, R4 demektir. RW aslında yazmaçların load uçlarına giden değerdir. RW = 0 ise AND kapılarından sonraki çıkış 0 olur ve yükleme yapılmaz. RW = 1 ise D kanalındaki değer adres olarak seçilen yazmaca yazılır.

## 9. Kontrol Kelimesi Örnekleri

Kontrol kelimeleri önce sözel olarak (DA, AA, BA, MB, FS, MD, RW), sonra ikili olarak yazıldı (ekrandan, 01:25:00 ve 02:10:00).

### 9.1 $R1 \leftarrow R2 - R3$

A kanalına R2, B kanalına R3 verilir, sonuç R1'e yazılır: DA = R1 (001), AA = R2 (010), BA = R3 (011). R3'ün function unit'in B girişine gidebilmesi için yazmaç seçilmelidir: MB = 0. Çıkarma $A - B$ işlemidir: FS = 0101. Sonuç D kanalına function unit'ten gelmelidir: MD = 0. Yazma yapılır: RW = 1.

Kontrol kelimesi: `001 010 011 0 0101 0 1`.

### 9.2 $R4 \leftarrow sl\,R6$

Kaydırıcı yalnız B kanalını kullanır. R6 B kanalına verilmelidir, A kanalı kullanılmaz (don't care). DA = R4 (100), AA = XXX, BA = R6 (110), MB = 0, FS = 1110 (sola kaydırma), MD = 0, RW = 1.

Kontrol kelimesi: `100 XXX 110 0 1110 0 1`.

### 9.3 $R7 \leftarrow R7 + 1$

Fonksiyon tablosunda $B + 1$ diye bir işlem yoktur. Artırma yalnız A kanalından yapılabilir. R7 A kanalına verilmelidir. Register file'ın B kanalından ne çıktığı ve MUX B'den sabit mi B kanalı mı geldiği önemsizdir. DA = 111, AA = 111, BA = XXX, MB = X, FS = 0001, MD = 0, RW = 1.

Kontrol kelimesi: `111 111 XXX X 0001 0 1`.

> **Hocanın vurgusu:** Artırma işleminin yalnız A kanalından yapılabildiğini fonksiyon tablosuna bakarak görmek gerekir. "Burası anlaşıldı değil mi? Bu önemli."

### 9.4 $R1 \leftarrow R0 + 2$

Fonksiyon tablosunda $+2$ yoktur. 2 sabit bir değerdir ve komuttan sağlanabilir: sabit, MUX B'nin 1 girişinden function unit'in B girişine verilir. Sabit B tarafından geldiği için R0 A kanalından verilmelidir. Register file'ın B çıkışı önemsizdir. DA = 001, AA = 000, BA = XXX, MB = 1, FS = 0010 ($A + B$), MD = 0, RW = 1. Constant in = 2.

Kontrol kelimesi: `001 000 XXX 1 0010 0 1`.

### 9.5 $Data\ out \leftarrow R3$

Data out bir giriş-çıkış birimi ya da bellek olabilir; veri yolu üzerinden dış dünyaya veri aktarılır. R3 B kanalından çıkmalıdır: BA = 011, MB = 0. A kanalı, DA, FS ve MD önemsizdir. Ancak function unit kombinasyonel olduğu için yine de bir değer üretir ve bu rastgele değer D kanalına gelir. Bu değerin rastgele bir yazmaca yazılmasını engellemek için RW mutlaka 0 olmalıdır.

Kontrol kelimesi: `XXX XXX 011 0 XXXX X 0`.

### 9.6 $R4 \leftarrow Data\ in$

Data in bir bellek ya da giriş-çıkış cihazı olabilir. A kanalı, B kanalı, MUX B ve FS önemsizdir. Data in'i D kanalına aktarmak için MD = 1 gerekir. Hedef R4'tür ve yazma yapılır.

Kontrol kelimesi: `100 XXX XXX X XXXX 1 1`.

### 9.7 $R5 \leftarrow 0$

Fonksiyon tablosunda sıfırlama ya da sıfır atama yoktur. Hoca bunun nasıl yapılabileceğini sordu. Birkaç yol vardır. Biri, $A - B$ işleminde iki kanala da aynı yazmacı vermektir; sonuç 0 olur. Öbürü XOR'dur: aynı değerli bitlerin XOR'u ($0 \oplus 0$ ve $1 \oplus 1$) 0'dır. Kitaptaki çözümde XOR ve R0 seçilmiştir; herhangi bir yazmaç seçilebilirdi. A ve B kanallarına R0 verilir, MB = 0 ile B kanalı function unit'e gider, FS = 1010 (XOR) ile çıkış 0 olur, MD = 0 ile bu değer D kanalına gelir, DA = R5 ve RW = 1 ile R5'e yazılır.

Kontrol kelimesi: `101 000 000 0 1010 0 1`.

Böylece kontrol kelimesi kavramı görülmüş oldu. Komut, kontrol kelimesinin ve sonradan eklenecek kontrol işaretlerinin sıkıştırılmış, paketlenmiş hâlidir; amaç daha az yer kaplaması ve daha kompakt olmasıdır. Komutlar komut çözücüden geçirilerek kontrol kelimeleri üretilir.

## 10. ALU Durum Bitleri

Bellek ve komut çözücüye geçmeden önce hoca atlanan bir adıma döndü: function unit'in durum (status) çıktıları nasıl üretilir? Bu bitler, komut kümesi mimarisinde işaretli ve işaretsiz sayılar için görülen bayrak kontrollerine benzer. 8 bitlik bir ALU için çıktı $G_7 \ldots G_0$ olsun. Hoca bayrakların G'ler, A'lar ve B'ler cinsinden nasıl ifade edileceğini öğrencilere sordu (ekrandan, 01:50:00).

**İşaret (N):** Bir öğrenci en anlamlı bite, yani en soldaki bite bakılacağını söyledi. $N = G_7$.

**Sıfır (Z):** Sonucun bütün bitleri 0 ise 1, değilse 0 olmalıdır. Bir öğrenci bütün bitlerin bir OR kapısına bağlanmasını önerdi. $G_0 + G_1 + \cdots + G_7$ yalnız hepsi 0 iken 0'dır, herhangi biri 1 olduğunda 1'dir. Çıkış ters olduğu için değili alınır, yani bir NOR kapısı gerekir:

$$Z = \overline{G_0 + G_1 + \cdots + G_7}$$

AND kapısı ise herhangi bir bit 0 olduğunda 0 verir; bu belirleyici değildir. Hepsi 0 olduğunda 0 veren tek kapı OR'dur.

**Elde (C):** Tam toplayıcı, elde uçları zincirleme bağlı 1 bitlik tam toplayıcılardan oluşur. 8 bitlik ALU'da en yüksek anlamlı tam toplayıcının elde çıkışı elde bayrağını verir: $C = C_7$.

**Taşma (V):** İki negatif sayının toplamı pozitif ya da iki pozitif sayının toplamı negatif çıkıyorsa taşma vardır. Bu durum en yüksek anlamlı ve bir altındaki elde bitlerinin farklı olmasına denk gelir:

$$V = C_7 \oplus C_6$$

> **Ders sonrası not:** Hoca sözlü olarak "eğer bunlar aynıysa overflow var anlamına geliyor" dedi. Doğrusu ekrana yazdığı XOR ifadesidir: $C_7$ ile $C_6$ **farklıysa** taşma vardır, aynıysa yoktur.

Kitap şemasında Z bayrağı ALU çıkışındaki bir sıfır algılayıcı (zero detect) bloğuyla üretilir (ekrandan, 01:50:00).

## 11. Bellekler, Program Sayacı ve Komut Biçimleri

### 11.1 Bellek genişlikleri ve PC

Blok şemada eksik kalan yapılar data memory (veri belleği), program memory (komut belleği), program memory'de hangi satırın işleneceğini belirleyen program sayacı ve komut çözücüdür. PC komut belleğini adresler, bellekten çıkan değer komut çözücüye gider ve komut çözücü bütün kontrol kelimesi bitlerini üretir.

Register file $8 \times 16$ ise 8 yazmaç vardır ve her biri 16 bit genişliğindedir. Bu durumda veri genişliğinin de 16 bit olması uygundur. Komut belleği $2^{15} \times 16$ olsun. Hoca PC'nin genişliğini sordu. PC, komut belleğinde hangi gözle işlem yapıldığını belirleyen bir adres seçimidir. Komut belleğinin adres uçları 15 tane olduğu için PC'nin de adres yolu genişliğinde, yani 15 bit olması gerekir.

Koşullu ya da koşulsuz dallanma yoksa kod sırayla yürütülür. Her komut bir bellek gözü (16 bit) olduğu için PC her seferinde bir artırılır. Dallanma varsa PC dallanma ofseti kadar değiştirilip tekrar adres ucuna verilir.

### 11.2 Üç komut biçimi

Komut belleğinde saklanan veriler komutlardır. Komutlar üç gruba ayrılır: yazmaçlar üzerinde işlem yapanlar, anlık (immediate) sabit değerlerle işlem yapanlar ve koşullu/koşulsuz dallanmalar (ekrandan, 01:55:00).

| Biçim | 15-9 | 8-6 | 5-3 | 2-0 |
|---|---|---|---|---|
| (a) Yazmaç | Opcode | DR | SA | SB |
| (b) Anlık | Opcode | DR | SA | OP |
| (c) Atlama ve dallanma | Opcode | AD (sol) | SA | AD (sağ) |

Opcode, arka tarafta hangi işlemin yürütüleceğini belirler. Komut çözüldüğünde opcode'un bir kısmı FS'ye dönüşür.

> **Ders sonrası not:** Hoca 9 bitin yazmaç alanlarına, "6 bitlik kısmın" opcode'a ayrıldığını söyledi. Ekrandaki biçimde opcode 15-9 bitlerindedir, yani 7 bittir. 16 bitlik komutta $16 - 9 = 7$ bit kalır ve komut tablosundaki opcode'lar da 7 basamaklıdır.

**Yazmaç biçimi:** Bu tek çevrimli bilgisayarda komutların temel yapısı "hedef ← kaynak 1 işlem kaynak 2"dir. Örneğin `ADD R1, R2, R3` iki kaynak (R2, R3) ve bir hedef (R1) içerir. ADD opcode'u $A + B$'yi yürüten FS'ye çözülür. Komutlar en fazla üç işlenenlidir (iki ya da bir işlenenli olanlar da vardır); bu yönüyle 8086'dan farklıdır. 8 yazmaç için her alana 3 bit gerekir.

**Anlık biçim:** Örneğin `AND R1, R2, 3`: R2 ve 3 kaynak, R1 hedeftir. AND opcode'u $A \wedge B$'yi yürüten FS'ye çözülür. Son alan sabit işlenendir (operand) ve 3 bit genişliğindedir. Bu yüzden verilebilecek anlık değerler yalnız 0 ile 7 arasındadır.

**Dallanma biçimi:** Örneğin bir yazmaç sıfır değilse belirli bir ofset kadar ileri git. Ofset 6 bittir ve iki parçaya bölünür: 3 biti 8-6 bitlerinde, 3 biti 2-0 bitlerinde. Hoca örnek olarak 16 seçti. 6 bitte $16 = 010000$'dır. Sol parçaya 010, sağ parçaya 000 yazılır. Ofset ikiye tümleyen çalışır. 16 adres geri gitmek için $-16$ yazılır: $-16 = 110000$. Bu sayılar python ile kontrol edildi.

> **Ek bilgi (derste anlatılmadı):** 6 bitlik ikiye tümleyen bir ofset $-32$ ile $+31$ arasında değer alabilir.

### 11.3 Komutların komut belleğine yüklenmesi

İşlemciye ait bir assembly dili ve assembler vardır. Kod assembly ile yazılır ve derlenir, oluşan ikili dosya bir ROM programlayıcıyla komut belleğine aktarılır. Artık bellekte sırayla yürütülecek, algoritmik anlamı olan bir komut dizisi vardır ve PC ilgili adresleri seçer.

### 11.4 Komut, kontrol kelimesi ve fonksiyon ayrımı

Komut ile kontrol kelimesi farklı şeylerdir. Komut yürütülecek işlemin başka bir alandaki adı ve sıkıştırılmış hâlidir. Kontrol kelimesi seyrek gösterimdir ve doğrudan fiziksel uçlara bağlanır. Aynı şekilde komut ile function unit'teki fonksiyon da farklıdır. Function unit'te bir yazmacı sıfırlama fonksiyonu yoktur, ama komut kümesinde "sıfırla" komutu olabilir. Bu komutun karşılığı iki aynı yazmacı XOR'layan bir kontrol kelimesidir. Komut daha üst seviyede bir tanımdır ve function unit fonksiyonları uygun kontrol kelimeleriyle birleştirilerek farklı işlemler yapılabilir.

## 12. Basit Bilgisayarın Komut Kümesi

8086'da olduğu gibi her komut için bir ad, opcode, kısaltma (mnemonic), işlenenler, yaptığı işlem ve etkilenen bayraklar verilir. Hoca temel yaklaşımın aslında ters yönde olduğunu belirtti: önce ihtiyaç duyulan komutlar belirlenir, sonra arkadaki mikro işlemler oluşturulur. Komut tablosu şöyledir (ekrandan, 02:15:00):

| Komut | Opcode | Kısaltma | Biçim | Açıklama | Bayrak |
|---|---|---|---|---|---|
| Move A | 0000000 | MOVA | RD, RA | $R[DR] \leftarrow R[SA]$ | N, Z |
| Increment | 0000001 | INC | RD, RA | $R[DR] \leftarrow R[SA] + 1$ | N, Z |
| Add | 0000010 | ADD | RD, RA, RB | $R[DR] \leftarrow R[SA] + R[SB]$ | N, Z |
| Subtract | 0000101 | SUB | RD, RA, RB | $R[DR] \leftarrow R[SA] - R[SB]$ | N, Z |
| Decrement | 0000110 | DEC | RD, RA | $R[DR] \leftarrow R[SA] - 1$ | N, Z |
| AND | 0001000 | AND | RD, RA, RB | $R[DR] \leftarrow R[SA] \wedge R[SB]$ | N, Z |
| OR | 0001001 | OR | RD, RA, RB | $R[DR] \leftarrow R[SA] \vee R[SB]$ | N, Z |
| Exclusive OR | 0001010 | XOR | RD, RA, RB | $R[DR] \leftarrow R[SA] \oplus R[SB]$ | N, Z |
| NOT | 0001011 | NOT | RD, RA | $R[DR] \leftarrow \overline{R[SA]}$ | N, Z |
| Move B | 0001100 | MOVB | RD, RB | $R[DR] \leftarrow R[SB]$ | |
| Shift Right | 0001101 | SHR | RD, RB | $R[DR] \leftarrow sr\,R[SB]$ | |
| Shift Left | 0001110 | SHL | RD, RB | $R[DR] \leftarrow sl\,R[SB]$ | |
| Load Immediate | 1001100 | LDI | RD, OP | $R[DR] \leftarrow zf\,OP$ | |
| Add Immediate | 1000010 | ADI | RD, RA, OP | $R[DR] \leftarrow R[SA] + zf\,OP$ | N, Z |
| Load | 0010000 | LD | RD, RA | $R[DR] \leftarrow M[SA]$ | |
| Store | 0100000 | ST | RA, RB | $M[SA] \leftarrow R[SB]$ | |
| Branch on Zero | 1100000 | BRZ | RA, AD | $R[SA] = 0$ ise $PC \leftarrow PC + se\,AD$, değilse $PC \leftarrow PC + 1$ | N, Z |
| Branch on Negative | 1100001 | BRN | RA, AD | $R[SA] < 0$ ise $PC \leftarrow PC + se\,AD$, değilse $PC \leftarrow PC + 1$ | N, Z |
| Jump | 1110000 | JMP | RA | $PC \leftarrow R[SA]$ | |

Tablodaki yıldızlı açıklamalar (dallanma olmayan bütün komutlar) için PC ayrıca bir artırılır, çünkü bu komutlar sıralıdır.

Komutların function unit'le ilişkisi şöyle kuruldu:

- **MOVA:** A'nın aktarımı fonksiyon tablosunda iki yerde vardır: FS = 0000 ya da 0111. İkisinden biri kullanılır.
- **INC ve DEC:** Fonksiyon tablosunda artırma ve azaltma yalnız A kanalında vardır. RA parametresi register file'ın A kanalıyla ilişkilidir.
- **ADD, SUB:** $A + B$ ve $A + \overline{B} + 1$ fonksiyonları kullanılır; iki kaynak, bir hedef.
- **OR, XOR:** A ve B kaynakları bit düzeyinde işlenip D'ye yazılır. **NOT** yalnız A kanalından olur.
- **MOVB:** B'nin çıkışa aktarıldığı, A kanalının don't care olduğu özel bir işlemdir.
- **SHR, SHL:** Kaydırma B kanalından yapılır; işlenenler RB (kaynak) ve RD (hedef).

**LDI:** Örneğin `LDI R1, 3`. Sabit yalnız B kanalından aktarılabildiği için A kanalı kullanılmaz. 3 bitlik sabiti yazmaçtaki değerle aynı genişliğe getirmek için sıfırla doldurma (zero fill) yapılır: 3 = 011, üst bitleri 0 ile tamamlanır.

> **Ders sonrası not:** Hoca burada yazmaç değerinin "8 bitlik" olduğunu söyledi. Bu derste kullanılan register file $8 \times 16$'dır. Sabit büyük olasılıkla 16 bite tamamlanır. Ayrıca altyazıda 3'ün ikili karşılığı "1, 1, 0" diye geçiyor; doğrusu 011'dir.

**ADI:** Örneğin `ADI R7, R2, 5`: R2 ile 5 toplanıp R7'ye yazılır. Sabit yine 3 bittir ve sıfırla genişletilir. ADI anlık değerli komut grubuna girer.

**LD:** Bellekten yazmaca okumadır. Belleğin adres, data in ve data out uçları vardır. Okuma için bir adres çıkılmalıdır. Adres register file'ın A kanalından gelir. Örneğin `LD R5, R2`: R2'nin içeriği A kanalından belleğin adres uçlarına gider, okunan veri MUX D üzerinden (MD = 1) R5'e yazılır. Yani belleğin R2 numaralı gözü okunur ve R5'e aktarılır.

**ST:** Belleğe yazmadır. Hem adres hem veri gönderilmelidir. Adres A kanalından, veri B kanalından (MUX B'nin 0 girişi üzerinden data out) gelir. `ST R5, R2` ile belleğin R5 numaralı gözüne R2'nin içeriği yazılır. Bu sıralama donanımdaki kısıttan kaynaklanır: adresi A kanalı, veriyi B kanalı üretir.

**BRZ ve BRN:** BRZ sıfır bayrağına, BRN negatif bayrağına bakar. RA kaynak yazmacının durumuna göre AD kadar ofsete gidilir. Ofset 6 bitlik işaretli sayıdır. PC 15 bit olduğu için ofset, PC'ye eklenmeden önce işaretli olarak 15 bite genişletilmelidir (sign extend). İşaretle genişletme, 15 bit tamamlanana kadar işaret bitini tekrarlamak demektir:

- $+16$: 010000 → `000000000010000`
- $-16$: 110000 → `111111111110000`

Bu genişletmeler python ile kontrol edildi.

Komutun çalışması: RA = 0 ise PC, AD kadar artar (AD negatifse azalır). RA sıfır değilse sonraki komuta geçilir. Assembly karşılığı için hoca şu örneği verdi (ekrandan, 02:25:00):

```text
      SUB R2, R0, R1
      BRZ R2, Etiket
      ADD R1, R2, R3
      ...
Etiket:
      ADD R1, R1, 5
```

SUB, N ve Z bayraklarını etkiler. SUB sonucu R2'de bir değer oluşur. R2 sıfırsa "Etiket" adresine gidilir. Assembler, 8086'nın debug ekranında görüldüğü gibi, etiketin ne kadar ötede olduğunu otomatik hesaplar: etiket ileride ise ofset pozitif, gerideyse negatif çıkar. R2 sıfır değilse PC 1 artar. Koşullu dallanma böylece iki kollu bir yapı oluşturur. BRN için de aynısı geçerlidir; bu kez koşul RA'nın 0'dan küçük olmasıdır.

**JMP:** Tek parametre alır (RA) ve A yazmacındaki değeri doğrudan PC'ye yükler. RA'daki adrese gidilir.

## 13. Bellekteki Komutların Çözülmesi

Program belleğindeki ikili kodların çözülmesine örnek (ekrandan, 02:30:00):

| Adres | İçerik | Opcode | Diğer alanlar | İşlem |
|---|---|---|---|---|
| 25 | `0000101 001 010 011` | 5 (SUB) | DR:1, SA:2, SB:3 | $R1 \leftarrow R2 - R3$ |
| 35 | `0100000 000 100 101` | 32 (ST) | SA:4, SB:5 | $M[R4] \leftarrow R5$ |
| 45 | `1000010 010 111 011` | 66 (ADI) | DR:2, SA:7, OP:3 | $R2 \leftarrow R7 + 3$ |
| 55 | `1100000 101 110 100` | 96 (BRZ) | AD:44, SA:6 | R6 = 0 ise $PC \leftarrow PC - 20$ |
| 70 | `0000000011000000` | | | Veri = 192 |

**Adres 25:** Opcode 5, yani SUB. Üç parametre alır. DR = 1, SA = 2, SB = 3: R1'e $R2 - R3$ yazılır.

**Adres 35:** Opcode 0100000, yani ST. ST, A ve B parametrelerini kullanır: A'daki adres, B'deki içeriktir. Hedef alanı kullanılmaz (don't care). Belleğin R4 ile gösterilen adresine R5'in içeriği yazılır.

**Adres 45:** Opcode 1000010, yani ADI. Hedef, A kaynağı ve sabit işlenen kullanılır: R2'ye $R7 + 3$ atanır.

**Adres 55:** Opcode 1100000, yani BRZ. Koşul yazmacı SA alanındadır: 110 = R6. Ofsetin 3 biti hedef alanında (101), 3 biti SB alanında (100) durur. Birleşince `101100` olur. En yüksek anlamlı bit 1 olduğu için sayı negatiftir. Büyüklüğü hoca "8, 16, 20" diye hesapladı: $-20$. R6 = 0 ise PC 20 adres geri gider. İşaretsiz okunduğunda aynı bit dizisi 44'tür (tablodaki AD:44). Python ile kontrol edildi.

**Adres 70:** Bunun bir opcode olup olmadığı doğrudan anlaşılamaz, çünkü 000 ile başlayan opcode'lar da vardır. PC bu adresi komut adresi olarak göstermediği sürece bu satır veri olarak değerlendirilir. PC'nin bu adresi gösterme ihtimali varsa MOVA'ya karşılık gelebilir; kesin söylenemez.

## 14. Tek Çevrimli Bilgisayarın Tamamı ve Komut Çözücü

### 14.1 Genel mimari

Eksik parçalar tamamlanınca tek çevrimli bilgisayarın genel mimarisi elde edilir (ekrandan, 02:35:00). Register file, MUX B, function unit ve MUX D'ye ek olarak veri belleği eklenir ve bununla bir kontrol işareti daha gelir: MW (memory write). Ayrıca dallanma mı atlama mı yapılacağını ya da PC'ye yükleme yapılıp yapılmayacağını belirten üç kontrol daha vardır: PL, JB ve BC. Dallanma koşulları durum bayraklarına göre gerçekleştiği için bayraklar da dallanma kontrolüne (branch control) girdidir.

PC komut belleğinde bir adresi gösterir. Bu adresteki komutu komut çözücü çözer ve bir kontrol kelimesi oluşturur. Bu kontrol kelimesi dallanma yapılıp yapılmayacağını, function unit'in kullanılıp kullanılmayacağını, veri belleğine yazılıp yazılmayacağını ya da okunup okunmayacağını, hangi yazmaçların kaynak, hangisinin hedef olacağını belirler. Son hâlinde kontrol kelimesi 20 bit, komutlar 16 bittir:

| Bitler | 19-17 | 16-14 | 13-11 | 10 | 9-6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Alan | DA | AA | BA | MB | FS | MD | RW | MW | PL | JB | BC |

Komut, kontrol kelimesinin paketlenmiş, sıkıştırılmış hâlidir ve kontrol kelimeleri üzerinde daha üst seviyede farklı komutlara karşılık gelebilir. Örneğin bir "move zero" komutu, R0 XOR R0 kontrol kelimesiyle karşılanabilir. Her komutun hangi function unit fonksiyonunu kullandığı bir geçiş tablosunda toplanırsa komut çözücü lojik kapılarla kurulabilir.

DR doğrudan DA'ya, SA doğrudan AA'ya, SB doğrudan BA'ya karşılık gelir (ekrandan, 02:45:00 öncesi şema). Bu alanlar zaten kodlanmıştır, daha fazla sıkıştırılamaz. Komutun en düşük anlamlı 3 biti (IR(2:0)) sıfırla genişletilerek sabit girişini (constant in) besler. Komut çözücü MB = 1 verirse bu sabit function unit'in B girişine gider. Koşullu dallanmada ofset yine komutun içindedir: 8-6 bitleri ile 2-0 bitleri birleştirilerek 6 bitlik değer oluşturulur, 15 bite işaretle genişletilip PC'nin önüne getirilir. PC'nin içinde bir toplayıcı olduğu varsayılır. Dallanma koşulu oluşursa PC bu ofset kadar değişir, oluşmazsa bir artırılır.

PC'ye iki yol gelir. Biri işaretle genişletilmiş ofsetin eklendiği koşullu dallanma yolu, öbürü register file'ın A kanalındaki değerin doğrudan PC'ye yüklendiği koşulsuz atlama (jump) yoludur.

### 14.2 Komut çözücünün doğruluk tablosu

Komut çözücünün DA, AA ve BA dışındaki çıktıları MB, FS, MD, RW, MW, PL, JB ve BC'dir. Bunlar opcode'un 15, 14, 13 ve 9 numaralı bitlerinden üretilir (ekrandan, 02:45:00):

| Komut türü | 15 | 14 | 13 | 9 | MB | MD | RW | MW | PL | JB | BC |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Yazmaçlarla function unit işlemleri | 0 | 0 | 0 | X | 0 | 0 | 1 | 0 | 0 | X | X |
| Bellekten okuma | 0 | 0 | 1 | X | 0 | 1 | 1 | 0 | 0 | X | X |
| Belleğe yazma | 0 | 1 | 0 | X | 0 | X | 0 | 1 | 0 | X | X |
| Yazmaç ve sabitle function unit işlemleri | 1 | 0 | 0 | X | 1 | 0 | 1 | 0 | 0 | X | X |
| Sıfıra göre koşullu dallanma (Z) | 1 | 1 | 0 | 0 | X | X | 0 | 0 | 1 | 0 | 0 |
| Negatife göre koşullu dallanma (N) | 1 | 1 | 0 | 1 | X | X | 0 | 0 | 1 | 0 | 1 |
| Koşulsuz atlama | 1 | 1 | 1 | X | X | X | 0 | 0 | 1 | 1 | X |

Satırların gerekçeleri:

- **000 (yazmaçlarla function unit):** Ne anlık değer ne dallanma vardır. Yazmaç seçileceği için MB = 0, sonuç function unit'ten geleceği için MD = 0, sonuç yazılacağı için RW = 1, bellek işlemi olmadığı için MW = 0. PL (program counter load), PC'de ani bir değişiklik olup olmayacağını, yani dallanma olup olmadığını belirtir. Sıradaki komuta geçildiğinde PL = 0'dır ve PC yalnız bir artar. Bu durumda JB ve BC don't care'dir.
- **001 (bellekten okuma):** Yalnız LD bu gruptadır ve DR ile SA kullanılır. Okunan veri D kanalına gelmeli: MD = 1. Okunan değer yazmaca yazılır: RW = 1. Belleğe yazılmaz: MW = 0. PC'ye yükleme yoktur: PL = 0.
- **010 (belleğe yazma):** Veri yazmaçtan gelecek, adres A kanalından gelecek: MB = 0, MW = 1. Sonuç yazmaca yazılmaz: MD don't care, RW = 0. PL = 0.
- **100 (yazmaç ve sabit):** ADI ve LDI bu gruptadır. Sabitle işlem için MB mutlaka 1, sonuç function unit'ten: MD = 0, RW = 1, MW = 0, PL = 0. Hoca ADI için MB, MD, RW, MW, PL değerlerinin 1, 0, 1, 0, 0 olduğunu gösterdi.
- **Koşullu dallanma:** PL = 1 (komut çözücü dallanma opcode'larında PL'yi 1 üretecek şekilde kurulmuştur). JB yalnız atlamayla ilgilidir, burada 0'dır. Sıfır bayrağına bakılırken BC = 0, negatif bayrağına bakılırken BC = 1. Sonuç ne belleğe ne yazmaca yazılır, MB ve MD don't care'dir.
- **Koşulsuz atlama:** PL = 1 ve JB = 1. Atlamada BC don't care'dir.

**Soru:** Bellekten okumada MB neden don't care değil de 0 verilmiş? (Hoca öğrencilere sordu.) **Cevap:** Okuma için adres A kanalından çıkılır. Data out'un bir önemi yoktur, MUX B'nin hangi girişi seçtiği de önemsizdir. Hoca burada MB'yi don't care almanın daha anlamlı olduğunu ve X olarak kabul edilebileceğini söyledi. MD ise kesinlikle 1 olmalıdır.

Bütün komut grupları için böyle bir tablo çıkarıldıktan sonra Karnaugh haritasıyla sadeleştirilerek komut çözücü elde edilir. Sadeleştirmede don't care'ler, haritada alınıp alınmamalarına göre 1 ya da 0 olur. Bu yüzden komut bazındaki tabloda don't care beklenen yerlerde de değerler görülür. Örneğin SHL için JB'de 1 üretilmiştir. Bunun bir anlamı yoktur, çünkü PL = 0 olduğu için JB değerlendirilmez. Hoca bu kısmın ayrıntılı incelenmesini öğrencilere bıraktı.

## 15. Kritik Yol

Tek çevrimli bilgisayarda olası bütün komutlar düşünüldüğünde yürütülmesi en uzun süren komut, register file'dan A ve B kanallarına değer çıkaran, bunları function unit'ten ve MUX D'den geçirip tekrar register file'a yazan komuttur. Bu yolun toplam süresi kritik yolu (critical path) oluşturur.

Tek çevrimli bilgisayarda sıralı ve kombinasyonel bloklar bir arada kullanılır. En uzun yolun süresi, sıralı lojikteki saat frekansını belirler. Derste toplam süre adım adım toplanarak yaklaşık 9,8 ns bulundu. <!-- BELİRSİZ: Bileşen gecikmeleri karelerde okunamadı; altyazıda yalnız birikimli toplamlar 4,2; 4,8; 5; 9; 9,2; 9,8 ns olarak geçiyor. --> Saat periyodu 9,8 ns'den kısa olamaz. Daha kısa olursa sonuçlar oluşmadan yazılmaya çalışılır. Böylece kritik yol, tek çevrimli bilgisayarın hangi frekansta çalışacağını belirleyen ölçüt olur.

Ders kapsamında yalnız tek çevrimli bilgisayar ele alınır; kitabın bundan sonraki kısmı çok çevrimli bilgisayarla (multi-cycle computer) ilgilidir. Sonraki konu iş hattıdır (pipeline): her komut alt adımlara bölünür ve bütün alt adımlar eş zamanlı çalıştırılarak aynı anda birden fazla komut yürütülür. Ardından seri ve iş hatlı yapıların performans karşılaştırması ve giriş-çıkış birimleri gelecektir.

## 16. Soru-Cevap: Bekleme Süresi, İş Hattı ve Tek Komutlu Makineler

**Soru:** Bellekten veri okunurken ya da yazılırken geçen sürede işlemci boş mu durur? Bu süreden yararlanıp bellek gerektirmeyen işlemler yapılabilir mi? Bunun için işlemcinin kaç komutu önceden görebildiğini anlatan "pencere" terimi mi kullanılır?

**Cevap:** Mavi bloklar ortak saatle çalışan sıralı bloklar, gri bloklar kombinasyonel bloklardır. Kombinasyonel blokların uçlarında değer varken çıktı üretilir. Örneğin saat darbesi gelmeden function unit'te bir önceki komutun A ve B değerleri ve çıktısı bulunur. Anlamlı çıktı ancak saatin yükselen kenarından sonra A ve B kanallarına sonraki komutun değerleri çıktığında oluşur. Tek çevrimli bilgisayarda bir komut tamamen bitmeden sonrakine geçilemez. Bu yüzden komut yürütülürken, işlenen getirilirken ya da işlem yapılırken bekleme süresinden yararlanılamaz. Bundan yararlanmak için içeride bir önceden getirme kuyruğu (prefetch queue) olmalıdır; sorudaki pencere mantığı buna karşılık gelir. Çok çevrimli bilgisayarda ve iş hattında komut çözme, işlenen getirme, yürütme ve geri yazma (writeback) ayrı bloklar hâlinde tanımlanır. Birinci blok yeni komutu çözerken ikinci blok bir önceki komutun işlenenlerini getirir, üçüncü blok iki önceki komutu yürütür, dördüncü blok daha önceki komutun sonucunu geri yazar. Böylece aradaki boşluklar etkin kullanılır. Günümüz işlemcileri sıradaki $n$ komutu almak yerine koşullu dallanmalarda kodun hangi dala gideceğini tahmin eder. Tahmin istatistiksel olabilir ya da yazmaç değerlerine bakılarak yapılabilir. Tahmin edilen koldaki komutlar önceden çekilir. Tahmin yanlışsa bunlar atılır ve doğru koldaki komutlar bellekten yeniden çekilir. Dallanma koşulunu önceden hesaplayıp dallanma içermeyen kod yazmak da mümkündür; hoca bunun için "branchless programming" konusuna bakılmasını önerdi.

**Soru:** Tek komutlu işlemciler gerçek hayatta kullanılıyor mu, yoksa yalnız derste gördüğümüz yapı mı kullanılıyor?

**Cevap:** Derste görülen yapı RISC mimarisine yakındır. RISC mimarisi bugün daha da genişlemiştir; dersteki yapı daha teorik ve eğiticidir. Tek komutlu yapıların pratikte karşılığı yoktur. Her şey yapılabilir, ama bir if karşılaştırması için satırlarca kod yazmak gerekiyorsa bunun pratik anlamı yoktur. Bu yapılar bir alıştırma ya da teorik bir şeyi gösterme aracıdır. Hoca bu konuda ezoterik programlama dillerine bakılabileceğini söyledi.

## Örnek Sorular

### Soru 1: Giriş lojiğinden fonksiyon tablosu (ekrandan, 00:20:00)

4 bitlik bir aritmetik devrede her tam toplayıcının $X_i$ ve $Y_i$ girişleri şu Boole fonksiyonlarıyla verilmiştir:

$$X_i = A_i, \qquad Y_i = \overline{B_i}\,S + B_i\,\overline{C_{in}}$$

Burada S bir seçim değişkeni, $C_{in}$ elde girişi, $A_i$ ve $B_i$ $i$. katın veri girişleridir.

a) S ve $C_{in}$'in 00, 01, 10 ve 11 kombinasyonlarının her biri için yapılan aritmetik işlemi belirleyin.

b) 4 bitlik devrenin lojik diyagramını tam toplayıcılar ve MUX'lar kullanarak çizin.

> **Çözüm (derste verildi):** a) $SC_{in} = 00$: $Y_i = B_i$, $F = A + B$. $01$: $Y_i = 0$, $F = A + 1$. $10$: $Y_i = \overline{B_i} + B_i = 1$ (hepsi 1, yani $-1$), $F = A - 1$. $11$: $Y_i = \overline{B_i}$, $F = A + \overline{B} + 1 = A - B$. b) X girişlerine $A_0 \ldots A_3$ doğrudan bağlanır. Her bit için bir 4'e 1 MUX'un seçim uçlarına S (yüksek) ve $C_{in}$ (düşük) bağlanır. Girişler sırasıyla $B_i$, 0, 1, $\overline{B_i}$'dir. MUX çıkışı $Y_i$'ye gider, $C_{in}$ ayrıca 0. tam toplayıcının elde girişine bağlanır. Fonksiyon tablosu python ile doğrulandı.

### Soru 2: Kısıtlı 8 bitlik ALU (ekrandan, 00:30:00)

8 bitlik A ve B girişlerine karşılık 8 bitlik F çıkışlarını aşağıdaki fonksiyon tablosuna göre üreten ALU birimini verilen kısıtlar çerçevesinde tasarlayınız.

- $S_3, S_2, S_1, S_0$ ALU fonksiyon seçim uçlarıdır.
- ALU birimini AU (aritmetik birim) ve LU (lojik birim) şeklinde 2 alt birim olarak tasarlayınız.
- AU birimini 8 bitlik tam toplayıcı kullanarak tasarlayınız.
- AU birimindeki tam toplayıcının $C_{in}$ girişine $S_0$ ALU fonksiyon seçim ucu doğrudan bağlıdır.
- AU biriminde A giriş lojiği ile B giriş lojiği için ve LU birimi tasarımında gerekli büyüklükte MUX kullanınız.

| $S_3$ | $S_2$ | $S_1$ | $S_0$ | F | Açıklama |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | $A + B$ | Toplama |
| 0 | 0 | 0 | 1 | $A$ | A transferi |
| 0 | 0 | 1 | 0 | $B$ | B transferi |
| 0 | 0 | 1 | 1 | $A + 1$ | A'yı artırma |
| 0 | 1 | 0 | 0 | $A - 1$ | A'yı azaltma |
| 0 | 1 | 0 | 1 | $B + 1$ | B'yi artırma |
| 0 | 1 | 1 | 0 | $B - 1$ | B'yi azaltma |
| 0 | 1 | 1 | 1 | $A - B$ | Çıkarma |
| 1 | 0 | 0 | 0 | $A \wedge B$ | Bit düzeyinde AND |
| 1 | 0 | 0 | 1 | $A \vee B$ | Bit düzeyinde OR |
| 1 | 0 | 1 | 0 | $\overline{A}$ | A'nın tümleyeni |
| 1 | 0 | 1 | 1 | $A \oplus B$ | Bit düzeyinde XOR |

> **Çözüm (derste verildi):** Çıkış MUX'u $S_3$ ile AU ($S_3 = 0$) ve LU ($S_3 = 1$) arasında seçer. LU: her bit için 4'e 1 MUX, seçim $S_1S_0$, girişler AND, OR, $\overline{A}$, XOR. AU: her bit için iki adet 8'e 1 MUX, seçim $S_2S_1S_0$, $C_{in} = S_0$. X MUX'unun girişleri sırasıyla $A_i, A_i, 0, A_i, A_i, 0, 1, A_i$, Y MUX'unun girişleri $B_i, 1, B_i, 0, 1, B_i, B_i, \overline{B_i}$ (ayrıntılı tablo 5.3'te). Bağlantılar python ile 8 bitlik değerlerde kontrol edildi.

### Soru 3: 8 bitlik ALU'nun durum bitleri (derste sözlü, 01:46:24)

Çıkışı $G_7 \ldots G_0$ olan 8 bitlik bir ALU'da işaret, sıfır, elde ve taşma bayrakları nasıl üretilir?

> **Çözüm (derste verildi):** $N = G_7$. $Z = \overline{G_0 + G_1 + \cdots + G_7}$ (bütün bitlerin NOR'u). $C = C_7$ (en yüksek anlamlı tam toplayıcının elde çıkışı). $V = C_7 \oplus C_6$ (son iki elde biti farklıysa taşma vardır).

### Soru 4: Program sayacının genişliği (derste sözlü, 01:52:17)

Register file $8 \times 16$ ve komut belleği $2^{15} \times 16$ ise program sayacının genişliği nedir?

> **Çözüm (derste verildi):** PC komut belleğinin adresini verir. Komut belleğinin $2^{15}$ satırı, yani 15 adres ucu olduğu için PC 15 bit olmalıdır.

### Soru 5: Fonksiyon tablosunda olmayan sıfırlama (derste sözlü, 01:38:49)

Function unit'in fonksiyon tablosunda sıfırlama ya da sıfır atama yoktur. $R5 \leftarrow 0$ işlemi nasıl yapılır ve kontrol kelimesi nedir?

> **Çözüm (derste verildi):** Aynı yazmaç hem A hem B kanalına verilip XOR'lanır (ya da çıkarılır); sonuç 0 olur. R0 kullanılırsa: DA = 101, AA = 000, BA = 000, MB = 0, FS = 1010, MD = 0, RW = 1, yani `101 000 000 0 1010 0 1` (ekrandan, 02:10:00).

### Soru 6: Bellekteki komutu çözme (ekrandan, 02:30:00)

Program sayacı 25, 35, 45 ve 55 numaralı adresleri gösterdiğinde, bu adreslerdeki `0000101 001 010 011`, `0100000 000 100 101`, `1000010 010 111 011` ve `1100000 101 110 100` içerikleri hangi komutları yürütür?

> **Çözüm (derste verildi):** 25: SUB, $R1 \leftarrow R2 - R3$. 35: ST, $M[R4] \leftarrow R5$. 45: ADI, $R2 \leftarrow R7 + 3$. 55: BRZ, ofset `101100` = $-20$; R6 = 0 ise $PC \leftarrow PC - 20$. Ofset değeri python ile doğrulandı.

### Soru 7: Bellekten okumada MB (derste sözlü, 02:41:44)

Komut çözücü tablosunda bellekten okuma satırında MB neden 0 verilmiştir; don't care olarak alınabilir mi?

> **Çözüm (derste verildi):** Okumada adres A kanalından çıkılır, data out ve MUX B'nin seçimi önemsizdir. MB don't care (X) olarak alınabilir. MD ise okunan veriyi D kanalına aktarmak için kesinlikle 1 olmalıdır.

## Dersin Toparlaması

Bu derste function unit tamamlandı. Lojik birim bit başına bir 4'e 1 MUX ile kuruldu, aritmetik birimle bir seçici MUX üzerinden birleştirilerek ALU elde edildi. İki örnek soruyla hem giriş lojiğinden fonksiyon tablosuna gitmek hem de $C_{in}$ kısıtı altında MUX'larla ALU tasarlamak çalışıldı. Ardından yalnız B kanalını kullanan kaydırıcı ve barrel shifter görüldü, MUX F ile function unit tamamlandı. Datapath'in kontrol değerleri 16 bitlik kontrol kelimesinde toplandı ve yedi mikro işlemin kontrol kelimesi çıkarıldı. Durum bitlerinin üretimi gösterildi.

Dersin ikinci yarısında komut belleği, PC, komut biçimleri, basit bilgisayarın komut kümesi ve komut çözücü eklenerek tek çevrimli bilgisayar tamamlandı. Kontrol kelimesi 20 bite çıktı, komutlar 16 bitte kaldı. Komutun kontrol kelimesinin sıkıştırılmış hâli olduğu, komut çözücünün bir doğruluk tablosundan Karnaugh haritasıyla kurulabileceği ve en uzun yolun saat periyodunu belirlediği görüldü. Sonraki derste iş hattı mantığı, seri ve iş hatlı yapıların performans karşılaştırması ve giriş-çıkış birimleri ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
