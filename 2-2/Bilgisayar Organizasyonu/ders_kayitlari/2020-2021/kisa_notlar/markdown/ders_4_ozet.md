# Ders 4 Çalışma Özeti

## Genel Konular

- Ders kaydın yaklaşık 00:04:25'inde başlar. Lojik devre tekrarı, programlanabilir lojik cihazlarla sürüyor.
- Bellek yapıları (ROM ve RAM)
  - ROM (Read Only Memory): çalışırken yalnız okunan, enerji kesilince içeriği kaybolmayan bellek. Adres, veri, okuma (read) ve yonga seçme (chip select) uçları vardır.
  - $m$ adres ucu $2^m$ hafıza gözünü seçer; her gözde $n$ bit saklanır. Kapasite $2^m \times n$ bittir.
  - İç yapı: adres uçları $m \times 2^m$ bir dekodere girer; dekoder bir satırı seçer, sütunlar okunur, çıkışlar üç durumlu tamponlarla (tri-state) veri yoluna verilir ya da yoldan koparılır.
  - RAM (Random Access Memory): okunabilir ve yazılabilir, geçici (enerji kesilince içerik kaybolur) bellek. Herhangi bir göze doğrudan (rastgele) erişilir; sıralı erişimin örneği veri kasetleri ve bantlardır.
  - RAM'de de adres seçimini bir $m$'den $2^m$'e dekoder yapar. Yazma ve okuma yönü için giriş ve çıkış tamponları vardır. Şekilde ayrı veri giriş ve çıkış yolları görünse de pratikte tek bir çift yönlü veri yolu kullanılır.
- Programlanabilir lojik cihazlar (PLD)
  - Her biri bir AND katı (çarpım terimleri) ve bir OR katı (toplam) içerir. Fark, hangi katın programlanabildiğindedir (ekrandan, 00:20:00):
    - ROM: AND katı sabit (dekoder, bütün mintermleri üretir), OR katı programlanabilir.
    - PAL (Programmable Array Logic): AND katı programlanabilir, OR katı sabit.
    - PLA (Programmable Logic Array): iki kat da programlanabilir.
    - CPLD/FPGA: "mimari" denecek kadar karmaşık; bloklar programa göre hafıza elemanı, kapı ya da look-up table gibi davranabilir.
- ROM ile lojik fonksiyon gerçekleme
  - Aktif 1 çıkışlı dekoderin $i$ numaralı çıkışı $i$ numaralı mintermdir ($Y_i = m_i$). Bu yüzden ROM'un içindeki dekoder, AND katının kendisidir.
  - OR kapısının girişlerine bütün dekoder çıkışları sigortalarla bağlıdır. Şemadaki "X" sigortanın korunduğunu (mintermin OR'a dahil olduğunu), işaret olmaması sigortanın yakıldığını gösterir.
  - $m$ adres ve $n$ veri ucu olan ROM, $m$ girişli en fazla $n$ fonksiyon gerçekler. Her OR kapısının girdileri diğerlerinden bağımsızdır.
- ROM türleri (ekrandan, 00:35:00)
  - Maskeli ROM: üretimde programlanır, değiştirilemez.
  - PROM: kullanıcı bir kez programlar (sigorta ya da antisigorta).
  - EPROM: penceresinden morötesi (UV) ışıkla silinir.
  - EEPROM ($E^2PROM$): elektriksel olarak silinir ve yazılır.
  - Flash: EEPROM benzeri, silme ve yazma blok blok yapılır.
- PLA
  - Bütün mintermler üretilmez; örnekteki 3 girişli PLA'da yalnız 4 AND kapısı vardır.
  - Çıkışta programlanabilir XOR katı bulunur: XOR'un diğer girişi 0'a bağlanırsa OR çıkışı olduğu gibi, 1'e bağlanırsa tümlenmiş geçer.
  - Aynı yonga alanında ROM'dan çok daha fazla girişi destekler.
- PAL
  - AND katı programlanabilir, OR katı sabittir. Her OR kapısına bağlı AND sayısı (örnekte 3) sınırlıdır.
  - Bir çıkış AND katına geri beslenerek 3'ten fazla çarpım teriminin toplamı kurulabilir.
- PLD cihazı örneği (bilgi amaçlı)
  - 22V10 tipi PLD: her blokta bir D flip-flop ve lojik kapılar bulunur. WinCUPL ile program yazılıp derlenir, çıkan JED dosyası cihaza ya da Proteus simülasyonuna yüklenir.
  - Örnekler: 8 bitlik barrel shifter (döndürmeli kaydırıcı) ve 16V8 tipi cihazda 4 bitlik toplayıcı.
- FPGA ve Verilog (bilgi amaçlı, kısa)
  - Verilog'da yarım toplayıcı modülü (yerleşik `and` ve `xor` yapılarıyla) ve `always` bloğunda `case` ile 3'e 8 dekoder gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- RAM ve ROM'da adres uçlarına karşılık seçimi bir dekoder yapar
  - Hoca bunu bu bölümden akılda kalması gereken asıl nokta olarak söyledi.
- ROM'da AND katı nerede?
  - Şemada AND kapısı görünmez; AND katı dekoderin içindedir. Dekoder AND ve NOT kapılarından oluşur, çıkışları çarpım terimleridir (mintermler).
- ROM tasarımı pratik bir yoldur
  - Doğruluk tablosu kurulur, çıkışın 1 olduğu satırların mintermleri ilgili OR kapısına bağlanır (sigortası korunur).
- PLA'da ortak kapı aramanın sebebi
  - AND kapısı sayısı bütün çarpım terimlerine yetmez. Bu yüzden her fonksiyon hem kendisi hem tümleyeni için sadeleştirilir ve en çok ortak çarpım terimi veren seçim kullanılır; tümleyen gerekiyorsa çıkıştaki XOR'a 1 verilir.
- XOR katı olmadan PLA her fonksiyonu gerçekleyemez
  - Bazı fonksiyonlar XOR'suz da yapılabilir ama genel olarak tümleme imkânı gereklidir.
- PAL'da kısıt OR kapısı giriş sayısıdır
  - Bir OR kapısı yalnız belirli sayıda AND çıkışını toplar. Fazlası için başka bir çıkışın geri beslenmesi kullanılır.
- Verilog ve PLD programlama kısmı derste bilgi amaçlıdır.

## Kısa Tekrar Notları

- ROM kapasitesi: $2^m \times n$ bit ($m$ adres ucu, $n$ veri ucu).
- ROM = sabit AND (dekoder) + programlanabilir OR. PAL = programlanabilir AND + sabit OR. PLA = ikisi de programlanabilir.
- Aktif 1 çıkışlı dekoderde $Y_i = m_i$.
- Şemada X: bağlantı (sigorta) korunur. İşaret yok: sigorta yakılmış.
- 1 bitlik tam toplayıcı için en küçük ROM: $2^3 \times 2$. $C_{out} = \sum m(3,5,6,7)$, $S = \sum m(1,2,4,7)$.
- ROM'u okumak: adres hangi dekoder çıkışını 1 yapıyorsa, o satırda X olan çıkışlar 1 olur.
- PLA çıkışındaki XOR: kontrol girişi 0 ise $F$ aynen, 1 ise $\overline{F}$ çıkar ($0 \oplus x = x$, $1 \oplus x = \overline{x}$).
- PLA tasarımında fonksiyon ve tümleyeni Karnaugh haritasından ayrı ayrı çıkarılır. Tümleyen için 0 olan gözler 1 gibi gruplanır.
- PAL'da bir OR kapısına en fazla 3 çarpım terimi bağlanabiliyorsa, 4 terimli fonksiyon başka bir çıkışın (örnekte $W$) geri beslenmesiyle kurulur.
- ROM türleri: maskeli ROM, PROM, EPROM (UV), EEPROM, Flash.

## Detaylı Açıklamalar

- ROM ile fonksiyon gerçeklemenin temeli
  - Bir lojik fonksiyon doğruluk tablosundan çarpımlar toplamı olarak yazılır: $F = \sum_i F_i\, m_i$. Burada $m_i$ $i$ numaralı minterm, $F_i$ o satırdaki çıkış değeridir.
  - Aktif 1 çıkışlı bir dekoderde girişteki sayının ondalık karşılığı hangi çıkışı gösteriyorsa yalnız o çıkış 1 olur. Bir çıkışın doğruluk tablosunda tek bir satır 1 olduğu için $Y_i = m_i$ olur.
  - Şemada OR kapısına tek çizgi bağlı gibi çizilir; gerçekte bütün dekoder çıkışları bu OR'a birer sigortayla bağlıdır.
  - Tahta örneği (ekrandan, 00:30:00): girişleri $x$ (en anlamlı), $y$, $z$ olan 3x8 dekoderde 0, 4 ve 7 numaralı çıkışların sigortaları korunursa $f = x'y'z' + xy'z' + xyz$ olur.
- Sigorta yakma (öğrenci sorusu)
  - Dekoder çıkışı ile OR girişi arasındaki bağlantıyı bir transistör ve ona bağlı bir sigorta sağlar. Sigortadan, transistörü bozmayacak ama sigortanın en büyük akım değerini aşan bir akım geçirilirse sigorta yanar ve bağlantı kalıcı olarak kopar.
  - Tekrar programlanabilir yapılarda (MOSFET tabanlı) kapıdaki gerilim seviyesi tutulup bırakılarak bağlantı açılıp kapanabilir, yani bağlantı kalıcı olarak yakılmaz.
- Örnek: 1 bitlik tam toplayıcıyı uygun büyüklükte bir ROM ile gerçekleme (ekrandan, 00:40:00)
  - Girdiler $A$, $B$, $C_{in}$ (3 tane, $m = 3$); çıktılar $C_{out}$ ve $S$ (2 tane, $n = 2$). En küçük ROM $2^3 \times 2$ olur ve içinde bir 3x8 dekoder ile 2 OR kapısı vardır.
  - Doğruluk tablosundan: $C_{out} = \sum m(3,5,6,7) = A'BC_{in} + AB'C_{in} + ABC_{in}' + ABC_{in}$; $S = \sum m(1,2,4,7) = A'B'C_{in} + A'BC_{in}' + AB'C_{in}' + ABC_{in}$.
  - Programlama: $C_{out}$ kapısında 3, 5, 6, 7; $S$ kapısında 1, 2, 4, 7 numaralı çıkışların sigortaları korunur, diğerleri yakılır.
- Örnek: 8 x 4 ROM'un okunması (ekrandan, 00:45:00)
  - Şemadaki X'ler: $F_3$: $D_2, D_5, D_7$; $F_2$: $D_0, D_7$; $F_1$: $D_1, D_4$; $F_0$: $D_1, D_5, D_7$.
  - Okuma: adres 000 için yalnız $D_0$ = 1, buna bağlı tek çıkış $F_2$ olduğu için içerik 0100 (ondalık 4). Adres 001: 0011. Adres 010: 1000. Adres 111: 1101.
  - Fonksiyonlar ($A = A_2$, $B = A_1$, $C = A_0$): $F_0 = A'B'C + AB'C + ABC$, $F_1 = A'B'C + AB'C'$, $F_2 = A'B'C' + ABC$, $F_3 = A'BC' + AB'C + ABC$.
  - Aynı şemadan hem tasarım (hangi değer yazılacak) hem analiz (yazılı değer nedir) yapılabilir.
- PLA analizi (ekrandan, 01:10:00)
  - AND kapıları: 1: $AB'$, 2: $AC$, 3: $BC$, 4: $A'BC'$. Birinci OR kapısı $BC + AC$, ikinci OR kapısı $AB' + AC + A'BC'$ toplar.
  - $F_1$ XOR'unun kontrol girişi 0'a bağlı: $F_1 = AB' + AC + A'BC'$.
  - $F_2$ XOR'unun kontrol girişi 1'e bağlı: $F_2 = \overline{BC + AC} = (B' + C')(A' + C') = C' + A'B'$.
- PLA tasarımı: Mano Örnek 6-3 (ekrandan, 01:20:00)
  - $F_1(A,B,C) = \sum m(3,5,6,7)$, $F_2(A,B,C) = \sum m(1,2,3,7)$.
  - Karnaugh haritalarından: $F_1 = AB + AC + BC$, $\overline{F_1} = A'B'C + A'BC' + B'C'$; $F_2 = A'B + A'C + BC$ ya da ortak terim için $F_2 = A'B'C + A'BC' + BC$.
  - $\overline{F_1}$ ile ikinci $F_2$ yazımı $A'B'C$ ve $A'BC'$ terimlerini paylaşır. Toplam 4 çarpım terimi ($A'B'C$, $A'BC'$, $B'C'$, $BC$) 4 AND kapısına sığar.
  - Çözüm: $F_1 = \overline{A'B'C + A'BC' + B'C'}$ (XOR'a 1), $F_2 = A'B'C + A'BC' + BC$ (XOR'a 0).
- PAL örneği (ekrandan, 01:40:00)
  - 4 girişli, her OR kapısı 3 girişli PAL. Fonksiyonlar: $W = \sum m(2,12,13)$, $X = \sum m(7,8,9,10,11,12,13,14,15)$, $Y = \sum m(0,2,3,4,5,6,7,8,10,11,15)$, $Z = \sum m(1,2,8,12,13)$.
  - Sadeleştirilmiş: $W = ABC' + A'B'CD'$, $X = A + BCD$, $Y = A'B + CD + B'D'$, $Z = ABC' + A'B'CD' + AC'D' + A'B'C'D$.
  - $Z$ dört terimlidir ve 3 girişli OR'a sığmaz. İlk iki terim $W$'ye eşit olduğu için $Z = W + AC'D' + A'B'C'D$ yazılır ve $W$ çıkışı AND katına geri beslenir.
  - $W$ bölümünde kullanılmayan üçüncü AND kapısının hiç bağlantısı yoktur; OR katında etkisiz eleman 0 olduğu için çıkışı 0 kabul edilir.
- PLD örnekleri
  - Barrel shifter (ekrandan, 01:50:00): WinCUPL kodunda pin 1 saat, pin 2-9 veri girişleri `[D7..0]`, pin 10, 11, 14 kaydırma seçimi `[S2..0]`, pin 13 çıkış yetkilendirme, pin 23 preset, pin 15-22 çıkışlar `[Q7..0]` olarak tanımlanır. `shift` alanının 0-7 değerine göre girişler döndürülerek çıkış registerına (`output.d`) yazılır; bu bir `case` yapısı gibi çalışır.
  - 4 bitlik toplayıcı: 1 bitlik toplayıcı fonksiyonu tanımlanır ($S$ girdilerin XOR'u, $C_{out}$ çoğunluk fonksiyonu) ve elde zincirleme bağlanarak dört kez çağrılır.
  - Bu cihazın temel sürümü tek başına ardışıl devre için yetmez; gelişmiş sürümlerinde programlanabilir flip-flop'lar vardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
