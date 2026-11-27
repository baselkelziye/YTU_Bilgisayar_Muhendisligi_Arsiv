# Ders 3 Çalışma Özeti

## Genel Konular

- Boole cebrindeki özdeşlikler ve bir sadeleştirme kuralının ikinci ispatı
  - $A + \overline{A}B = A + B$ özdeşliği bu kez doğrudan dağılma kuralıyla ispatlandı: $A + \overline{A}B = (A+\overline{A})(A+B) = 1\cdot(A+B) = A+B$ (ekrandan, 00:20:00).
  - Aynı yol $\overline{A} + AB = (\overline{A}+A)(\overline{A}+B) = \overline{A}+B$ için de kullanıldı.
  - Boole cebrinin soyut tanımı mantıktaki kuralların aynısıdır: doğru/yanlış yerine 1/0, VEYA yerine $+$, VE yerine çarpma, değil için üst çizgi ya da kesme işareti ($x'$) kullanılır.
- Doğruluk tablosundan Boole ifadesi yazma
  - Çıkışın 1 olduğu satırlar yazılır; 0 olan satırların yazılmasına gerek yoktur.
  - Her 1 satırı, değişkenin 1 ise kendisi, 0 ise değili alınarak çarpım olarak yazılır; bu çarpımlar toplanır.
  - Örnekte $F(x,y,z) = x\overline{y}z$ ve $G(x,y,z) = xy\overline{z} + \overline{x}y\overline{z} = y\overline{z}(x+\overline{x}) = y\overline{z}$ bulundu (ekrandan, 00:25:00).
- SOP ve POS gösterimleri
  - SOP (sum of products, çarpımların toplamı): parantez içinde çarpımlar, terimler arasında toplama. Mintermlerle ifade edilir, $\Sigma$ ile gösterilir.
  - POS (product of sums, toplamların çarpımı): parantez içinde toplamlar, parantezler arasında çarpma. Maxtermlerle ifade edilir, $\Pi$ ile gösterilir.
  - Öğe (literal): bir değişken ya da tümleyeni. Minterm: $n$ değişkenin her birinin kendisi ya da tümleyeni olarak bir kez geçtiği $n$ öğeli çarpım (ekrandan, 00:35:00).
  - Mintermler satırın ikili değerinin onluk karşılığıyla adlandırılır: $m_0$ (000) ... $m_7$ (111).
- Mantık kapıları
  - Temel kapılar: NOT (inverter), OR (toplama), AND (çarpma); çok girişli AND ve OR kapıları da vardır (ekrandan, 00:45:00).
  - NAND ve NOR, AND/OR ile NOT'un birleşimidir ve "evrensel kapı" olarak anılır. NAND çıkışı $(xy)'$, NOR çıkışı $(x+y)'$ olur.
  - Devre tasarımında amaç fonksiyonu en az maliyetle, yani en az kapı ve öğeyle gerçeklemektir.
- Problemden devreye: oylama örneği
  - İki jüri (30'ar puan) ve bir müdür (40 puan) oy veriyor; toplam 55'ten büyükse aday geçiyor. 3 giriş, 1 çıkış var (ekrandan, 00:30:00).
  - Adımlar: blok şema, doğruluk tablosu, SOP ifade, sadeleştirme, kapı şeması.
- Yarı toplayıcı (half adder)
  - İki biti toplar; çıkışlar toplam (sum) $S$ ve elde (carry) $C$ (ekrandan, 00:50:00).
  - $S = x\overline{y} + \overline{x}y = (x+y)\overline{(xy)}$, $C = xy$.
  - İki yarı toplayıcı ile önceki basamağın eldesini de hesaba katan tam toplayıcı elde edilir.
- Karnaugh haritaları
  - Doğruluk tablosundaki fonksiyonu ortak paranteze alma mantığıyla, sistematik biçimde sadeleştirme yöntemidir.
  - Satır ve sütun başlıkları Gray kodla yazılır: komşu hücreler arasında yalnız bir bit değişir (00, 01, 11, 10).
  - 2, 3 ve 4 değişkenli haritalar; 5 değişken için iki 4'lü harita ya da hücreye değişken yazma yöntemi.
  - Gruplar 2'nin kuvveti büyüklüğünde (1, 2, 4, 8, 16) ve mümkün olan en büyük seçilir; gruplar iç içe geçebilir.
  - Kenarlar ve köşeler komşudur (harita silindir gibi katlanır).

## Hocanın Özellikle Vurguladığı Kısımlar

- Grup ifadesi yazılırken değişmeyen değişkenin hangi değerde değişmediğine bakılır
  - Grup boyunca 1 olarak sabit kalan değişken kendisiyle, 0 olarak sabit kalan değişken değiliyle yazılır. Bu, en sık yapılan hatadır.
- Gray kodu doğru yazmak
  - Haritada başlıklar ikili sırayla (00, 01, 10, 11) yazılırsa komşuluk bozulur ve gruplama yanlış olur.
- En büyük grubu seçmek
  - Grup büyüdükçe terimdeki öğe sayısı azalır: 4 değişkenli haritada 8'li grup tek öğe, 4'lü grup iki öğe, 2'li grup üç öğe verir. 16'lı grup sonucu 1 yapar.
  - Üç elemanlı grup olmaz; çapraz hücreler doğrudan gruplanmaz.
- Karnaugh gruplaması değişken sayısına göre yapılır, elimizdeki kapıların giriş sayısına göre değil
  - Kapı türü ve giriş sayısı yalnız son adımda, devre çizilirken önemlidir.
- Değişken sayısını en büyük mintermden bulmak
  - $\Sigma(1,2,3,7,11)$ gibi bir verilişte 11'i göstermek için 4 bit gerekir, bu yüzden 4 değişkenli harita kurulur.

## Kısa Tekrar Notları

- $A + \overline{A}B = A + B$, $\overline{A} + AB = \overline{A} + B$ (dağılma + birim özelliği).
- Doğruluk tablosundan SOP: 1 olan satırlar, 1'ler kendisi, 0'lar değili.
- SOP = mintermlerin toplamı ($\Sigma$), POS = maxtermlerin çarpımı ($\Pi$).
- NAND $=(xy)'$, NOR $=(x+y)'$; ikisi evrensel kapıdır.
- Oylama örneği: $R = J_1M + J_1J_2 + J_2M$.
- Yarı toplayıcı: $S = x \oplus y = (x+y)\overline{(xy)}$, $C = xy$.
- 2 bit Gray kod: 00, 01, 11, 10. Karnaugh başlıkları bu sırayla yazılır.
- Karnaugh akışı: problem → doğruluk tablosu → harita → gruplama → sade SOP → kapı şeması.
- Grupta değişen değişken yazılmaz; 1'de sabit kalan kendisi, 0'da sabit kalan değili ile yazılır.
- Köşe ve kenar hücreleri komşudur (4 köşe birlikte 4'lü grup olabilir).
- $\Sigma(1,2,3,7,11,15) = \overline{a}\,\overline{b}d + \overline{a}\,\overline{b}c + cd$.

## Detaylı Açıklamalar

- **Özdeşliğin ikinci ispatı.** Önceki derste $A + \overline{A}B = A + B$, $A$'yı $A(B+1)$ diye açarak ispatlanmıştı. Bu derste dağılma kuralının toplama üzerine biçimi $x + yz = (x+y)(x+z)$ kullanıldı: $A + \overline{A}B = (A+\overline{A})(A+B)$. $A + \overline{A} = 1$ olduğundan sonuç $A+B$ olur. Aynı yolla $\overline{A} + AB = (\overline{A}+A)(\overline{A}+B) = \overline{A}+B$ bulunur (ekrandan, 00:20:00).

- **Tablodan ifade ve sadeleştirme.** Tabloda $F$ yalnız $x=1, y=0, z=1$ satırında 1 olduğu için $F = x\overline{y}z$ olur; bu iki AND ve bir NOT ile çizilir. $G$ ise $110$ ve $010$ satırlarında 1'dir: $G = xy\overline{z} + \overline{x}y\overline{z}$. $y\overline{z}$ ortak paranteze alınınca $y\overline{z}(x+\overline{x}) = y\overline{z}$ kalır. Hoca bunu tablodan da gösterdi: $y=1, z=0$ iken $x$ ne olursa olsun $G=1$'dir, yani $x$'in etkisi yoktur. Sadeleştirmeyle dört AND, üç NOT ve bir OR yerine bir AND ve bir NOT yeter (ekrandan, 00:25:00).

- **Oylama problemi.** Girişler $J_1$, $J_2$, $M$; çıkış $R$. Bir giriş 1 ise o kişinin puanı (30, 30, 40) eklenir, 0 ise eklenmez. Toplam 55'i geçerse $R=1$:

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

  SOP: $R = \overline{J_1}J_2M + J_1\overline{J_2}M + J_1J_2\overline{M} + J_1J_2M$. Son iki terim $J_1J_2(\overline{M}+M) = J_1J_2$ olur. Karnaugh haritasıyla en sade biçim $R = J_1M + J_1J_2 + J_2M$ bulundu (ekrandan, 01:25:00). Devre: üç adet iki girişli AND ve bir OR (tablo değerleri python ile doğrulandı).

- **$(x+y)\overline{z}$ örneği.** Slaytta tablo kurularak $F = xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z}$ bulundu. Ters yönde sadeleştirme: $y\overline{z}(x+\overline{x}) + x\overline{y}\,\overline{z} = \overline{z}(y + \overline{y}x) = \overline{z}(x+y)$. Çözüm 2'de $(x+y)\overline{z}$ dağıtılıp eksik değişkenler $(y+\overline{y})$ ve $(x+\overline{x})$ ile eklenir, tekrar eden $xy\overline{z}$ terimi bir kez yazılır (ekrandan, 00:40:00).

- **Yarı toplayıcı.** Tablo: $11 \to S=0, C=1$; $10$ ve $01 \to S=1, C=0$; $00 \to S=0, C=0$. $S = x\overline{y} + \overline{x}y$. Bu ifade dağıtılarak $(x+\overline{x})(x+y)(\overline{x}+\overline{y})(y+\overline{y}) = (x+y)(\overline{x}+\overline{y}) = (x+y)\overline{(xy)}$ biçimine getirilir; slayttaki devre bu ifadeyi bir OR, bir AND, bir NOT ve bir AND ile kurar. $C = xy$ olup aynı AND kapısının çıkışından alınır (ekrandan, 00:50:00 ve 01:00:00).

- **Gray kod.** İkili kodda değer her adımda 1 artar (00, 01, 10, 11). Gray kodda her adımda yalnız bir bit değişir: 00, 01, 11, 10. Tek bit değiştiği için komşu hücreler ortak paranteze alınabilir. Karnaugh haritalarında bir eksende en fazla 2 bit kullanıldığından 2 bitlik Gray kod yeterlidir.

- **Karnaugh gruplama örnekleri (3 değişken).** Satır $a$, sütun $bc$ (00, 01, 11, 10). $a=0$ satırının tamamı 1 ise grup $\overline{a}$; $bc=01$ ve $11$ sütunlarındaki dört 1 ise grup $c$ olur. Bir başka haritada 1'ler $000, 001, 010, 110, 111$ hücrelerindeydi: $\overline{a}\,\overline{b} + ab + b\overline{c}$; üçüncü grup yerine $\overline{a}\,\overline{c}$ de seçilebilir (ekrandan, 01:35:00).

- **Karnaugh gruplama örnekleri (4 değişken).** Satır $ab$, sütun $cd$. Dört köşe 4'lü grup olur: $\overline{b}\,\overline{d}$. Üst ve alt satırlar ($ab=00$ ve $10$) 8'li grup: $\overline{b}$; ilk iki sütun 8'li grup: $\overline{c}$. Bütün hücreler 1 ise sonuç 1'dir. Bir örnekte 1'ler $m_0, m_2, m_3, m_7, m_8, m_{10}, m_{11}$ hücrelerindeydi; sonuç $\overline{b}\,\overline{d} + \overline{b}c + \overline{a}cd$ bulundu (ekrandan, 01:50:00).

- **$\Sigma$ ile verilen fonksiyon.** $F = \Sigma(1,2,3,7,11,15)$: en büyük minterm 11 (ve 15) olduğundan 4 değişken gerekir. Harita: $\overline{a}\,\overline{b}$ satırında $m_1, m_3, m_2$; $cd=11$ sütununda $m_3, m_7, m_{15}, m_{11}$. Gruplar: $cd$ (4'lü sütun), $\overline{a}\,\overline{b}d$ ve $\overline{a}\,\overline{b}c$ (2'li). Sonuç $F = \overline{a}\,\overline{b}d + \overline{a}\,\overline{b}c + cd$ (ekrandan, 02:05:00 ve 02:10:00). Bu SOP biçiminde en sade haldir; $\overline{a}\,\overline{b}(c+d) + cd$ diye yazmak kapı sayısını daha da azaltabilir ama artık SOP değildir. Python ile doğrulandı.

- **Beş değişken.** İki yol anlatıldı: $E=0$ ve $E=1$ için üst üste iki 4 değişkenli harita, ya da 4 değişkenli haritanın hücrelerine 1, $e$ ya da $\overline{e}$ yazıp $1 = e + \overline{e}$ mantığıyla gruplamak (ekrandan, 02:20:00). Hoca bu konunun ders kapsamında olmadığını, ayrıntısının mantık devreleri dersinde görüleceğini belirtti. Algoritmik yöntem olarak Quine-McCluskey yönteminin adı geçti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
