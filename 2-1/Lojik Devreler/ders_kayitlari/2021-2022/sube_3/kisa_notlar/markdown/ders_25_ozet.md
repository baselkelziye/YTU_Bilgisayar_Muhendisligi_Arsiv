# Ders 25 Çalışma Özeti

## Genel Konular

- Birleşik (kombinezonsal) devre tasarımının adımları
  - Problemdeki girişler ve çıkışlar belirlenir, bu değişkenlerle doğruluk tablosu kurulur, tablodaki 1'lerden Karnaugh diyagramı çıkarılır ve sadeleşmiş ifadeyle devre kurulur. Soru belirli bir kapı türü (örneğin yalnız TVE) istiyorsa ifade son adımda o biçime dönüştürülür.
  - Hocaya göre bu tür sorularda "zor soru" yoktur; önemli olan koşulları ve ayrıntıları adım adım çözümlemektir.
- Tam toplayıcı / tam çıkarıcı devresi (kontrol girişli)
  - Girişler $a, b, e, k$; çıkışlar $s, c$. $k = 0$ iken devre tam toplayıcı, $k = 1$ iken tam çıkarıcıdır (ekrandan, 00:15:00).
  - $s$ her iki modda da aynıdır: $s = \bar a b \bar e + \bar a \bar b e + a \bar b \bar e + abe = a \oplus b \oplus e$ (ekrandan, 00:35:00).
  - $c = be + \bar k a e + \bar k a b + k \bar a b + k \bar a e$ (ekrandan, 00:40:00).
  - Yalnız TVE (NAND) kapılarıyla gerçekleme: ifadenin iki kez değili alınır, içteki değil De Morgan ile dağıtılır; her çarpım terimi bir NAND, terimleri birleştiren de bir NAND olur. Değil kapıları da girişleri birleştirilmiş bir NAND ile yapılır (ekrandan, 00:40:00).
- Helikopter kalkış sinyali (Karnaugh ve 4x1 MUX ile)
  - Girişler: zaman sinyali $T$ ve 3 bitlik yolcu sayısı $A_2A_1A_0$. Kalkış zamanı gelmediyse helikopter dolu (7 kişi), geldiyse en az 2 yolcu olmalıdır (ekrandan, 00:45:00).
  - Sadeleşmiş ifade: $F = T A_2 + T A_1 + A_2 A_1 A_0$ (ekrandan, 00:50:00).
  - $T, A_2$ seçme girişli 4x1 MUX ile: $I_0 = 0$ (GND), $I_1 = A_1 A_0$, $I_2 = A_1$, $I_3 = 1$ (+5 V) (ekrandan, 00:55:00).
- Ağırlıklı oylama sistemi
  - Başkan 3, başkan yardımcısı 2, iki üye 1'er oy ağırlığındadır; toplam 7 olduğu için eşitlik oluşmaz. Çıkış, EVET ağırlığı 4 ya da daha fazlaysa 1'dir (ekrandan, 01:00:00 ve 01:05:00).
  - $B, Y$ seçme girişli 4x1 MUX ile: $I_0 = 0$, $I_1 = a_1 a_0$, $I_2 = a_1 + a_0$, $I_3 = 1$.
- İki çıkışlı yer değiştirme devresi
  - $w = 0$ ise $z_0 = x_0$, $z_1 = x_1$; $w = 1$ ise $z_0 = x_1$, $z_1 = x_0$ (ekrandan, 01:10:00).
  - İki çıkış olduğu için iki tane 2x1 MUX gerekir; ikisinin de seçme girişi $w$'dir, girişleri birinde $(x_0, x_1)$, diğerinde $(x_1, x_0)$ sırasıyla bağlanır.
- İki MUX ve bir VEYA kapısından oluşan devrenin çözümlemesi
  - Devrenin fonksiyonu tüm giriş kombinasyonları denenerek doğruluk tablosuyla bulunur; çıkışın sıfır olduğu satırlar az olduğu için maxterm (toplamların çarpımı) biçimi kullanılır (ekrandan, 01:25:00).
  - $Z = (a + b + \bar c + \bar d)(\bar a + b + c + \bar d)(\bar a + b + \bar c + \bar d)$.
  - $a, b, c$ seçme girişli 8x1 MUX ile girişler sırasıyla $1, \bar d, 1, 1, \bar d, \bar d, 1, 1$ olur.
- Merdiven aydınlatması (üç anahtar)
  - Lamba, kapalı anahtar sayısı tek iken yanar: $L = x_1 \oplus x_2 \oplus x_3$ (ekrandan, 01:30:00).
  - $x_1, x_2$ seçme girişli MUX ile girişler: $x_3, \bar x_3, \bar x_3, x_3$.
- BCD için tek eşlik (odd parity) biti üreteci
  - Eşlik biti, gönderilen 4 bit ile birlikte 1'lerin sayısını tek yapar (ekrandan, 01:35:00).
  - BCD dışı kombinasyonlar (1010-1111) için soru çıkışı tanımlamadığından bunlar farketmez (don't care) alınabilir.
  - $x_1, x_2$ seçme girişli 4x1 MUX ile: $I_0 = \overline{x_3 \oplus x_4}$, $I_1 = I_2 = x_3 \oplus x_4$, $I_3 = \overline{x_3 \oplus x_4}$.
- Basit bir ALU tasarımı
  - İki 4 bitlik veri ($A$, $B$), elde girişi $E_g$, elde çıkışı $E_{\text{ç}}$, 4 bitlik sonuç $F$ ve iki bitlik işlem kodu (opcode) vardır. İşlemler: $A + B$, $A - B$, $\bar B$ ve $A$'nın bir bit sağa ötelenmesi (ekrandan, 01:45:00 ve 01:50:00).
  - Tasarım: tüm işlemleri yapan bloklar (tam toplayıcı, tam çıkarıcı, değil kapıları, öteleme bağlantısı) paralel çalışır; işlem kodu seçme girişi olan 4x1 MUX'lar (her sonuç biti için bir tane) istenen sonucu çıkışa aktarır.
- Ardışıl (sequential) devrelere giriş
  - Ardışıl devre, birleşik devreye ek olarak bellek (storage) elemanları içerir: tutucular (latch) ve flip-floplar (ekrandan, 01:55:00).
  - Dış girişler ve çıkışların yanında, bellek elemanlarından gelen o anki durum (present state) ek bir giriş, bir sonraki durum (next state) ek bir çıkıştır.
  - Mealy ve Moore makineleri: ikisinde de $d(t+1) = f(d(t), x(t))$; Mealy'de $Z(t) = f(d(t), x(t))$, Moore'da $Z(t) = f(d(t))$ (ekrandan, 02:00:00).
  - Senkron ve asenkron ardışıl devreler: senkron devrede durum değişimi ortak bir saat (clock) darbesiyle olur; asenkron devrede ortak saat yoktur, değişim girişlerdeki değişime bağlı olarak ve değişken gecikmelerle olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- MUX'un tanımı
  - Seçme girişleriyle seçilen veri girişini çıkışa aktaran elemandır. Hoca, bir hafta sonra MUX ile kod çözücünün karıştırıldığını gözlemlediğini, bu yüzden örnekleri tekrar için çözdürdüğünü söyledi.
- MUX ile gerçeklemede satır gruplama
  - Seçme girişlerinin her değeri doğruluk tablosunda bir satır grubuna karşılık gelir. Grup içinde çıkış hep 0 ise girişe GND, hep 1 ise +5 V (lojik 1), kalan değişkenlerin kendisine eşitse o değişken, değilse küçük bir kapı devresi bağlanır. Bu yöntem Karnaugh'a gerek bırakmadan doğruluk tablosundan doğrudan tasarım sağlar.
- Toplayıcı/çıkarıcıda elde ve borcun aynı sütunda olması
  - Tam toplayıcıdaki elde biti ile tam çıkarıcıdaki borç biti aynı çıkışa ($c$) atanmalıdır; bit sırası (MSB/LSB) iki modda farklı seçilmemelidir.
- Birden çok çıkış = birden çok MUX
  - Her MUX tek çıkış verdiği için iki çıkışlı bir devrede iki MUX kullanılır.
- Mealy ile Moore arasındaki tek fark
  - Durum geçişleri iki makinede aynıdır; fark yalnız çıkışın nasıl belirlendiğindedir (Mealy: durum ve giriş, Moore: yalnız durum).

## Kısa Tekrar Notları

- Tasarım adımları: giriş/çıkış belirleme, doğruluk tablosu, Karnaugh, devre (gerekirse NAND/NOR biçimine dönüştürme).
- $\bar{\bar F} = F$; çarpımlar toplamı iki kez değillenip De Morgan uygulanınca NAND-NAND yapısı çıkar.
- Tam çıkarıcıda $0 - 1$: fark 1, borç 1; $0 - 1 - 1$: fark 0, borç 1 (sonuç $-2 + 0 = -2$).
- Helikopter: $F = TA_2 + TA_1 + A_2A_1A_0$.
- Oylama: $f = BY + Ba_1 + Ba_0 + Ya_1a_0$.
- Çıkışta 0'lar azsa maxterm (toplamların çarpımı) yazmak daha kısadır.
- Merdiven lambası: üç girişli XOR.
- Tek eşlik biti, 4 bitteki 1 sayısı çiftken 1'dir: $P = \overline{x_1 \oplus x_2 \oplus x_3 \oplus x_4}$.
- ALU: işlemler paralel hesaplanır, MUX işlem koduna göre sonucu seçer.
- Ardışıl devre = birleşik devre + bellek elemanları (latch, flip-flop).
- Senkron: ortak saat darbesi; asenkron: saat yok, değişken gecikmeler.

## Detaylı Açıklamalar

- Kontrol girişli toplayıcı/çıkarıcı
  - Ders, daha önce blok diyagramla (XOR'lu kontrol ucuyla) çözülmüş toplama/çıkarma devresinin bu kez doğruluk tablosu ve Karnaugh ile çözülmesiyle başladı. Tablo 16 satırdır: ilk 8 satır ($k = 0$) tam toplayıcının, son 8 satır ($k = 1$) tam çıkarıcının tablosudur. Çıkarıcıda $a - b - e$ hesaplanır; örneğin $a = 0, b = 1, e = 1$ için sıfırdan bir çıkmadığından borç alınır ve borç biti 1 olur, ikinci 1 de çıkarılınca fark 0 kalır. Bir öğrenci bunu "$-2$" olarak yorumladı; hoca bu bakışın da doğru olduğunu söyledi. $s$'nin Karnaugh diyagramında 1'ler komşu olmadığından ifade dört mintermden oluşur ve üç girişli XOR'a eşittir. $c$ için Karnaugh'da $be$ dörtlüsü ile $\bar k a e$, $\bar k a b$, $k \bar a b$, $k \bar a e$ ikilileri seçilir (ekrandan, 00:40:00).
  - Yalnız NAND kapılarıyla kurmak için ifadenin değilinin değili alınır. İçteki değil De Morgan ile dağıtıldığında toplamlar çarpıma, her çarpım terimi de bir NAND kapısına döner; dıştaki değil ile birlikte son kapı da NAND olur. Giriş değilleri, iki girişi birleştirilmiş bir NAND ile elde edilir ($x$ girerse çıkış $\bar x$ olur). Böylece tüm devre tek tür kapıyla kurulmuş olur.
- MUX ile tasarım örnekleri
  - Helikopter sorusunda hoca, aynı doğruluk tablosunu $T$ ve $A_2$ seçme girişli bir 4x1 MUX ile gerçekledi. $TA_2 = 00$ grubunda çıkış hep 0 olduğu için $I_0$ toprağa bağlanır. $11$ grubunda çıkış hep 1 olduğu için $I_3$'e +5 V verilir. $10$ grubunda çıkış $A_1$'in aynısıdır, $I_2 = A_1$. $01$ grubunda çıkış yalnız $A_1A_0 = 11$ iken 1 olduğundan $I_1$'e bir VE kapısının çıkışı ($A_1A_0$) bağlanır. MUX iç yapısındaki kapıları hazır getirdiği için çözüm Karnaugh'a gerek kalmadan doğrudan tablodan çıkar.
  - Oylama sorusunda aynı yöntem $B, Y$ seçme girişleriyle uygulanır: hiçbiri evet demezse sonuç 0, yalnız yardımcı evet derse iki üyenin de evet demesi ($a_1a_0$), yalnız başkan evet derse üyelerden birinin evet demesi ($a_1 + a_0$) gerekir; ikisi birden evet derse sonuç 1'dir.
  - İki MUX ve VEYA kapısından oluşan devrede doğruluk tablosu her kombinasyon için iki MUX çıkışının ayrı ayrı hesaplanıp VEYA'lanmasıyla bulunur. Bir öğrenci MUX çıkışlarını ayrı sütunlar olarak yazdığını söyledi; hoca bunun karmaşık, birbirine bağlı MUX'lardan oluşan devrelerde hata olasılığını azaltan iyi bir yöntem olduğunu belirtti.
- ALU
  - ALU, işlemcinin aritmetik (toplama, çıkarma, bazı tasarımlarda çarpma, bölme) ve lojik (kaydırma, döndürme, bit işlemleri) işlemlerini yapan birimidir. Örnekteki ALU'da toplama için bir tam toplayıcı bloğu, çıkarma için bir tam çıkarıcı bloğu, tümleme için her $B$ bitine bir değil kapısı (NAND ya da NOR girişleri birleştirilerek), sağa öteleme için ise kablolama kullanılır: $A$'nın her biti bir alt sıradaki bitin MUX'una bağlanır, en anlamlı bite elde girişi, dışarı çıkan en düşük bit de elde çıkışına gider. İşlem kodu, her sonuç biti için bir tane olmak üzere dört adet 4x1 MUX'un seçme girişlerine bağlanır.
- Ardışıl devreler
  - Birleşik devrelerde $t$ anındaki çıkış yalnız $t$ anındaki girişlere bağlıdır. Ardışıl devrelerde ise bir sonraki durum, o anki durum ile o anki girişe bağlıdır; bu yüzden önceki durumun saklanması gerekir. Hoca, geçen kişiyi sayıp her geçişte sayıyı bir artıran sensörlü sayıcıyı ve bir sayıya ulaşınca LED yakan sayıcıyı örnek verdi. Buradaki "bellek" RAM ya da disk gibi bir birim değil, tutucu ve flip-flop gibi değeri tutan elemanlardır.
  - Senkron devreye örnek olarak, saat darbeleriyle tazelenmesi gereken RAM verildi. Asenkron örnek olarak, bilgisayara USB takıldığında çalan uyarı sesi verildi: bu ses periyodik bir saatle değil, bir kesmeyle (interrupt) tetiklenir. Zamanlama diyagramında senkron devrede çıkış saat darbesinin yükselen kenarında girişi izler; asenkron devrede çıkış girişi saat olmadan, değişken gecikmelerle izler.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
