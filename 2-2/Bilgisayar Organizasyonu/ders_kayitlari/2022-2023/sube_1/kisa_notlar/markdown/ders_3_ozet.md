# Ders 3 Çalışma Özeti

## Genel Konular

- Latch ve flip-flop tekrarı
  - Latch seviye tetiklemelidir: enable (ya da saat) 1 olduğu sürece girişteki her değişiklik çıkışa geçer (transparent latch). Enable 0'a düşünce son değer çıkışta kalır.
  - Flip-flop kenar tetiklemelidir: yalnız saat işaretinin yükselen (ya da düşen) kenarında girişi örnekler ve bir sonraki tetikleyen kenara kadar bu değeri tutar. Sembolde üçgen yükselen kenarı, önündeki yuvarlak ile birlikte düşen kenarı gösterir.
  - Hafıza elemanlarının içinde geri besleme vardır. Kombinasyonel devrede bir kapının çıkışı kendi girişine geri dönmez; geri beslemeli yapıda kararsız (sürekli 0-1 değişen) ve kararlı durumlar oluşabilir.
  - Slayttaki saatli SR latch: iki AND kapısı ($R' = R \cdot Clk$, $S' = S \cdot Clk$) çapraz bağlı iki NOR kapısını sürer (ekrandan, 00:10:00). Saat 0 iken $R'=S'=0$ olur ve durum değişmez; yani soldaki AND katmanı seviye tetiklemeyi sağlar.
  - Saatli SR latch karakteristik tablosu (ekrandan, 00:10:00): $Clk=0$ iken $Q(t+1)=Q(t)$; $Clk=1$ iken $SR=00$ değişim yok, $01 \to 0$, $10 \to 1$, $11 \to$ izin verilmez ($x$). $S=R=1$ iken iki NOR çıkışı da 0 olur, $Q$ ve $\bar{Q}$ birbirinin tümleyeni olmaz.
  - D latch: $S = D$, $R = \bar{D}$ bağlanmış SR latch'tir; yalnız $SR = 01$ ve $10$ satırları kalır, $Clk=1$ iken $Q = D$ olur (ekrandan, 00:10:00).
  - Preset ve clear uçları asenkron çalışır, saat kenarını beklemeden çıkışı 1 ya da 0 yapar. Clear denetimi D ucuna bağlanırsa senkron clear elde edilir.
- Flip-flop tanım tabloları (ekrandan, 00:30:00)
  - SR: $00 \to q$, $01 \to 0$, $10 \to 1$, $11 \to$ izin verilmez; yükselen kenar dışında $q$ korunur.
  - JK: $00 \to q$, $01 \to 0$, $10 \to 1$, $11 \to \bar{q}$.
  - D: $Q = D$.
  - T: $T=0 \to q$, $T=1 \to \bar{q}$.
  - Küçük $q$ mevcut (önceki) durumu, büyük $Q$ saat kenarından sonraki durumu gösterir.
- Senkron ardışıl devre tasarım adımları
  - Sözel problemden durum sayısı, gereken hafıza elemanı sayısı ve durum diyagramı çıkarılır. $n$ durum için $\lceil \log_2 n \rceil$ flip-flop yeter.
  - Durum diyagramı doğruluk tablosuna geçirilir: girdiler $x$ ve $q$'lar, çıktılar sonraki durum $Q$, flip-flop giriş uçları ve devre çıkışı $Z$.
  - Flip-flop girişleri $q \to Q$ geçişine göre ters dönüşüm (uyarma) tablosundan doldurulur; $Z$ durum diyagramından doldurulur.
  - Bütün flip-flop'ların saatleri ortak kaynaktan beslenir (senkron tasarımın temel şartı).
- Mealy ve Moore makineleri
  - Mealy: çıkış hem duruma hem girişe bağlıdır ($Z = f(q, x)$). Çıkış geçiş okunun üstüne "giriş/çıkış" diye yazılır. Durum değişmeden giriş değişince çıkış da değişebilir, bu yüzden bir sonraki saat kenarına kadar arada istenmeyen çıkışlar görülebilir.
  - Moore: çıkış yalnız duruma bağlıdır ($Z = f(q)$). Çıkış durumun içine yazılır.
  - Mealy ile tanımlanan bir akış Moore ile de kurulabilir ama genelde daha fazla durum gerekir.
- Ters dönüşüm tabloları (ekrandan, 00:50:00 ve 00:55:00)
  - D: $q \to Q$ için $D = Q$ (00:0, 01:1, 10:0, 11:1).
  - T: durum değişiyorsa $T=1$, değişmiyorsa $T=0$ (00:0, 01:1, 10:1, 11:0).
  - JK: $00 \to 0x$, $01 \to 1x$, $10 \to x1$, $11 \to x0$.
- Örnek: iki durumlu Mealy makinesinin T, D ve JK ile gerçeklenmesi (ekrandan, 00:40:00 - 01:00:00)
  - Durumlar A (kod 0) ve B (kod 1). Geçişler: A'da $0/0$ kendine döner, $1/1$ ile B'ye geçer; B'de $0/1$ kendine döner, $1/0$ ile A'ya geçer.
  - Sonuç: $Z = x \oplus q$, $T = x$, $D = x \oplus q$, $J = x$, $K = x$.
  - Moore versiyonunda geçişler aynı kalır, yalnız çıkış $Z = q$ olur.
- 3 bitlik senkron yukarı sayıcı (T flip-flop ile) (ekrandan, 01:20:00 ve 01:25:00)
  - Dışarıdan giriş yoktur; geçişleri saat tetikler, sonraki durumu mevcut durum belirler. Çıkış durumların kendisidir ($Z = q_2q_1q_0$, Moore).
  - $T_0 = 1$, $T_1 = q_0$, $T_2 = q_1 q_0$ ($T_2 = q_2q_1q_0 + \bar{q}_2q_1q_0$ sadeleşmesi).
  - Aşağı sayıcı için yalnız sonraki durumlar ($Q$'lar) ve buna bağlı $T$ fonksiyonları değişir.
- Asenkron (ripple) sayıcı (ekrandan, 01:35:00 ve 01:40:00)
  - $q_0$ her saat darbesinde, $q_1$ $q_0$'ın iki katı periyotta, $q_2$ $q_1$'in iki katı periyotta değişir. $T = 1$ bağlanan T flip-flop her tetikleyen kenarda toggle eder.
  - Yükselen kenar tetiklemeli katlarda bir katın $Q$ çıkışı sonrakinin saatine bağlanırsa sayıcı geri sayar (111, 110, ..., 000).
  - Aynı bağlantı düşen kenar tetiklemeli flip-flop'larla yapılırsa ileri sayar (000, 001, ..., 111).
  - Üçüncü yol: yükselen kenarlı katlarda saat girişine önceki katın $\bar{Q}$ çıkışı bağlanırsa yine ileri sayar.
  - Saatler farklı kaynaklardan geldiği için bu bir asenkron ardışıl devredir.
- Yazmaçlar (register)
  - Paralel yüklemeli yazmaç: $n$ adet D flip-flop, ortak saat; yükselen kenarda $Q = D$, diğer zamanlarda $q$ korunur.
  - Ötelemeli yazmaç (shift register): seri bağlı D flip-flop'lar, ortak saat; her kenarda bitler bir sıra kayar, $S_{in}$ ilk konuma girer (ekrandan, 01:45:00).
  - Kullanım örneği: seri toplayıcıda iki yazmaç her adımda bir bit sağa ötelenir.
  - Paralel erişimli ötelemeli yazmaç: $\overline{\text{Shift}}/\text{Load}=0$ iken öteleme, 1 iken paralel yükleme. En yüksek anlamlı bit için $D_3 = \bar{X}\,S_{in} + X\,P_i$ ($X$ = Shift/Load ucu); diğer bitlerde $S_{in}$ yerine bir üst katın çıkışı gelir (ekrandan, 01:50:00).
- Yükleme uçlu 4 bitlik senkron yukarı sayıcı (ekrandan, 01:55:00)
  - Enable (senkron) 1 iken sayar, 0 iken değerini tutar. Load (senkron) 1 iken $D$ girişlerindeki değer yüklenir. Carry, sayıcının başa döndüğünü gösterir. $D_3$/$Q_3$ en yüksek anlamlı bittir.
  - 8-12 arası sayıcı: Enable = 1, Load = $q_2$, $D_3D_2D_1D_0 = 1000$. Sıfırdan başlarsa ilk turda 0-4 sayar, 4'te 8 yüklenir; sonra 8, 9, 10, 11, 12, 8, ... diye döner.
  - Program sayıcı (PC) bu tür bir sayıcıdır; dallanmada toplama devresiyle birlikte kullanılır.
- Programlanabilir lojik: ROM, PAL, PLA (ekrandan, 02:15:00)
  - Hepsi bir AND katı ve bir OR katından oluşur (doğru mintermlerin toplamı yapısı).
  - ROM (PROM): AND katı sabittir (dekoder), OR katı programlanır.
  - PAL: AND katı programlanır, OR katı sabittir.
  - PLA: hem AND hem OR katı programlanır.
  - FPGA ve CPLD daha büyük yapılar içindir (örneğin işlemci prototipleme); bu ders kapsamında değildir.
- ROM
  - $n$ adres ucu ve $m$ veri ucu olan ROM'da $2^n$ hafıza gözü, toplam $2^n \times m$ bit vardır (slaytta $2^k \times n$ ROM, ekrandan, 02:20:00).
  - İçeride $n$-girişli dekoder bütün mintermleri üretir; her çıkış bitinin OR kapısına bütün dekoder çıkışlarından sigorta benzeri bağlantı vardır. Programlamak, bu bağlantıları korumak ya da yakmaktır.
  - ROM bir lookup table gibidir; veri genişliği kadar lojik fonksiyonu ek kapı kullanmadan aynı anda gerçekler.
  - Örnek $8 \times 4$ ROM (ekrandan, 02:25:00): $F_3 = \bar{A}B\bar{C} + A\bar{B}C + ABC$, $F_2 = \bar{A}\bar{B}\bar{C} + ABC$, $F_1 = \bar{A}\bar{B}C + A\bar{B}\bar{C}$, $F_0 = \bar{A}\bar{B}C + A\bar{B}C + ABC$. Adres 001 için çıkış $F_3F_2F_1F_0 = 0011$.
- PLA
  - Girişlerin kendisi ve tümleyeni içeride hazırdır. Sınırlı sayıda AND kapısı vardır (örnekte 3 giriş için 4 çarpım terimi). Her çıkışta, programlanabilir 0 ya da 1 ile beslenen bir XOR kapısı vardır: 0 ise fonksiyon aynen, 1 ise tümleyeni çıkar.
  - Örnek PLA (ekrandan, 02:35:00): $F_1 = A\bar{B} + AC + \bar{A}B\bar{C}$, $F_2 = \overline{AC + BC}$.
  - Çarpım terimi sınırı aşılıyorsa iki fonksiyonun kendisi ve tümleyeni Karnaugh haritasında karşılaştırılır, ortak çarpım terimleri aranır.
  - Mano Örnek 6-3 (ekrandan, 02:40:00): $F_1 = \Sigma m(3,5,6,7)$, $F_2 = \Sigma m(1,2,3,7)$. Çözüm: $F_1 = \overline{\bar{A}\bar{B}C + \bar{A}B\bar{C} + \bar{B}\bar{C}}$, $F_2 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + BC$; toplam 4 farklı çarpım terimi, ikisi ortak.
- PAL
  - OR katı sabit olduğu için her çıkışta toplanabilecek çarpım terimi sayısı sınırlıdır (örnekte 3).
  - Bir OR çıkışı AND katına geri giriş olarak verilir. Böylece bir fonksiyon başka bir fonksiyonun çıkışını bir terim gibi kullanarak sınırdan fazla terim toplayabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ardışıl devre tasarımında latch yerine flip-flop kullanılır
  - Seviye tetiklemede alt modüllerin gecikmeleri farklı olduğu için yanlış ara çıkışlar geri beslemeyle başka girişleri bozabilir.
  - Kenar tetiklemede bütün girişler saat kenarından önce hazırdır; değişen çıkışlar geri döndüğünde kenar geçmiş olduğu için bozucu etki oluşmaz.
- Doğruluk tablosunda $Z$ sütunu durum diyagramından doldurulur
  - Flip-flop sütunları ters dönüşüm tablosundan, $Z$ ise diyagramdaki çıkışlardan gelir; hoca bunun karıştırılmamasını özellikle söyledi.
- Senkron tasarımda bütün saatler ortak olmalıdır
  - Durum tablosundaki geçişler aynı anda olacak biçimde tanımlandığı için ikinci bir flip-flop eklense de saati ortak verilmelidir.
- Programlanabilir yapılarda darboğaz
  - PLA'da asıl sınır çarpım terimi sayısıdır, bu yüzden ortak çarpım terimi aramak daha pratiktir. PAL'da ise toplam terimlerinin başka fonksiyonlarda bulunması aranır.

## Kısa Tekrar Notları

- Latch: seviye tetiklemeli, transparent. Flip-flop: kenar tetiklemeli.
- Saatli SR latch'te $S=R=1$ izin verilmez; D latch $S=D$, $R=\bar{D}$ ile bu durumu engeller.
- Ters dönüşüm: D'de $D=Q$; T'de değişim varsa 1; JK'da $00:0x$, $01:1x$, $10:x1$, $11:x0$.
- Mealy: $Z=f(q,x)$; Moore: $Z=f(q)$.
- Örnek Mealy: $Z = x\oplus q$, $T=x$, $D=x\oplus q$, $J=K=x$.
- 3 bit senkron yukarı sayıcı: $T_0=1$, $T_1=q_0$, $T_2=q_1q_0$.
- Asenkron sayıcı: yükselen kenar + $Q$ → geri sayar; düşen kenar + $Q$ ya da yükselen kenar + $\bar{Q}$ → ileri sayar.
- Paralel erişimli ötelemeli yazmaç: $D_3 = \bar{X}S_{in} + XP_i$.
- 8-12 sayıcı: Load $= q_2$, $D = 1000$, Enable $=1$.
- ROM: AND sabit / OR programlanır; PAL: AND programlanır / OR sabit; PLA: ikisi de programlanır.
- $n$ adres, $m$ veri bitli ROM: $2^n \times m$ bit.
- PLA çıkışındaki XOR ile fonksiyon ya da tümleyeni seçilir; ortak çarpım terimleri aranır.
- PAL'da OR çıkışının AND katına geri verilmesi terim sınırını aşmayı sağlar.

## Detaylı Açıklamalar

- **Saatli SR latch'in çalışması.** Slayttaki devrede çapraz bağlı iki NOR kapısı geri besleme kısmını, önlerindeki iki AND kapısı da denetim kısmını oluşturur (ekrandan, 00:10:00). Bir NOR kapısının girişlerinden biri 1 ise çıkış diğer girişe bakmadan 0 olur. Hoca $R'S' = 01$ ve $10$ durumlarından $00$'a geçişi adım adım izledi: her iki durumda da geri beslenen değer çıkışı korur, yani $00$ "değişim yok" demektir. $R'S' = 11$ iken iki NOR çıkışı da 0 olur; $Q$ ile $\bar{Q}$'nun birbirinin tümleyeni olma şartı bozulduğu için bu giriş izin verilmez. Saat 0 olunca AND kapıları $R'=S'=0$ verir, latch'in enable'ı kapanmış olur. Bu yüzden AND katmanı geri besleme yapısına seviye tetikleme denetimi ekler. D latch, $S$ ucuna $D$ ve $R$ ucuna $\bar{D}$ bağlanarak elde edilir; böylece yalnız $SR=01$ ve $10$ satırları kalır ve $Clk=1$ iken $Q=D$ olur.
- **Mealy örneğinin tasarımı.** İki durum olduğu için tek flip-flop yeter. A'ya 0, B'ye 1 kodu verildi (ekrandan, 00:40:00). Tablo (ekrandan, 00:55:00):

  ```text
  x q | Q | T | D | J K | Z
  0 0 | 0 | 0 | 0 | 0 x | 0
  0 1 | 1 | 0 | 1 | x 0 | 1
  1 0 | 1 | 1 | 1 | 1 x | 1
  1 1 | 0 | 1 | 0 | x 1 | 0
  ```

  $Z$ ve $D$, girişler farklıyken 1 olduğu için $x \oplus q$'dur. $T$ sütunu $x$ ile aynıdır. JK'da don't care'ler uygun seçilince $J = x$, $K = x$ çıkar. T ile gerçeklemede $T$ ucuna $x$, çıkışa $x \oplus q$ veren bir XOR bağlanır. D ile gerçeklemede aynı XOR'un çıkışı hem $Z$ hem $D$ olur; $\bar{Q}$ kullanılırsa XNOR gerekir, karmaşıklık değişmez. Moore versiyonunda çıkış doğrudan $Q$'dan alınır.
- **Asenkron sayıcıda yön.** Üç T flip-flop'un hepsinin $T$ ucuna 1 verilir; ilkinin saatine dış saat, sonrakilere önceki katın çıkışı bağlanır. Yükselen kenarla ve $Q$ bağlantısıyla dalga şeması çizildiğinde, ilk kenarda üç çıkış da 1'e çıkar ve sayıcı 111, 110, 101, 100, 011, 010, 001 diye geri sayar (ekrandan, 01:35:00). Düşen kenar tetiklemeyle aynı şema 000'dan 111'e ileri sayar (ekrandan, 01:40:00). Python ile yapılan benzetim üç bağlantı biçimini de doğruladı.
- **8-12 sayıcı.** $q_2$ yalnız 4-7 ve 12-15 aralığında 1'dir. Load'a $q_2$ bağlanınca 8-11 arasında sayıcı normal artar, 12'de bir sonraki kenarda 1000 yüklenir. Sıfırdan başlanırsa 4'e gelindiğinde de 8 yüklenir; bu ilk turdaki tek hatalı saymadır. Python benzetimi: 0, 1, 2, 3, 4, 8, 9, 10, 11, 12, 8, ...
- **ROM ile fonksiyon gerçekleme.** 3'e 8 dekoderin her çıkışı bir mintermdir ($A$ en yüksek anlamlı). Bir sütundaki çarpı işaretleri o çıkışın OR kapısına hangi mintermlerin bağlı olduğunu gösterir. Adres 001 verilince yalnız $m_1$ aktif olur; $m_1$'in bağlı olduğu $F_1$ ve $F_0$ 1, diğerleri 0 verir (0011). AND katının sabit olmasının nedeni, AND kapılarının dekoderin içinde gömülü olmasıdır.
- **PLA'da çarpım terimi paylaşımı.** Mano 6-3 örneğinde $F_1$'in kendisi $AB + AC + BC$, $F_2$'nin kendisi $\bar{A}B + \bar{A}C + BC$ olarak yazılırsa ortak terim tektir ve toplam 5 çarpım terimi gerekir. $\bar{F}_1 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + \bar{B}\bar{C}$ ile $F_2 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + BC$ eşleştirildiğinde $\bar{A}\bar{B}C$ ve $\bar{A}B\bar{C}$ ortak olur; toplam 4 çarpım terimi yeter. $F_1$ çıkışındaki XOR'a 1 verilerek tümleyen alınır (ekrandan, 02:45:00). Python ile iki ifade de doğrulandı.
- **PAL'da terim sınırı.** Örnekte dört fonksiyon (W, X, Y, Z) sadeleştirildiğinde Z dört çarpım teriminin toplamı çıktı; PAL'ın her OR'u ise 3 terim alıyordu. Z'nin ilk iki teriminin W'ye eşit olduğu görülünce W çıkışı AND katına geri verildi ve Z, W artı iki terim olarak 3 terime indi. <!-- BELİRSİZ: W, X, Y, Z fonksiyonlarının minterm listeleri ve sadeleşmiş ifadeleri ekranda gösterildi ama bu ana ait kare yok; altyazıdan okunamıyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
