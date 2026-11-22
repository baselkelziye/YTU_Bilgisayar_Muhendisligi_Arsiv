# Ders 2 Çalışma Özeti

## Genel Konular

- Ders kaydın yaklaşık 00:11:25'inde başlar. Lojik devreler konularının tekrarı sürüyor.
- Dekoderler (kod çözücüler)
  - $n$ girişli, $2^n$ çıkışlı, bir enable ucu olan yapı. Girişteki ikili sayının değeri hangi çıkışı gösteriyorsa o çıkış aktif olur.
  - Enable ve çıkışların aktif 1 ya da aktif 0 olmasına göre 4 farklı yapı vardır.
  - Aktif 1 çıkışlı dekoderde her çıkış bir minterme, aktif 0 çıkışlı dekoderde her çıkış bir maksterme karşılık gelir.
  - Bu yüzden dekoder ve bir OR (ya da AND) kapısıyla her lojik fonksiyon gerçeklenebilir. Örnek: 3x8 dekoder ile tam toplayıcı.
  - Hiyerarşik yapı: 2x4 dekoderlerden 4x16 dekoder (dekoder ağacı).
- Demultiplexer (DEMUX)
  - MUX'un tersi gibi çalışır: tek bir girişi, seçim uçlarındaki değere göre $2^n$ çıkıştan birine yönlendirir.
  - 1'e 4 DEMUX'un çıkış fonksiyonları minterm ile veri girişinin çarpımıdır.
- Enkoderler (kodlayıcılar)
  - $2^n$ girişli, $n$ çıkışlı yapı. Girişlerden yalnız biri 1 olabilir; çıkış, 1 olan girişin numarasının ikili karşılığıdır.
  - 4'e 2 enkoder: "don't care" durumları Karnaugh haritasında kullanılarak $y_0 = w_1 + w_3$, $y_1 = w_2 + w_3$ bulunur.
  - Öncelik enkoderi: birden fazla 1'e izin verir, en yüksek anlamlı 1'i kodlar. Hiç 1 yoksa geçerlilik çıkışı $z = 0$ olur.
- Toplayıcılar
  - Yarım toplayıcı: $C_{out} = AB$, $S = A \oplus B$.
  - Tam toplayıcı: $S = A \oplus B \oplus C_{in}$, $C_{out} = (A \oplus B)C_{in} + AB$.
  - Tam toplayıcı iki yarım toplayıcı ve bir OR kapısıyla ya da yalnız üç yarım toplayıcıyla kurulabilir.
- Çok bitli yapı blokları
  - Veri yolu (bus) gösterimi: hat üzerindeki eğik çizgi ve sayı, o kadar paralel tel olduğunu gösterir.
  - 8 bitlik 4'e 1 MUX: seçim uçları ortak olan 8 tane 1 bitlik 4'e 1 MUX.
  - İki 16 bitlik tam toplayıcıdan 32 bitlik toplayıcı; 16 tam toplayıcıdan 16 bitlik toplayıcı (ripple carry).
  - Toplayıcı-çıkarıcı devresi: XOR kapıları ve $C_0$ girişine bağlanan kontrol ucu.
- Karşılaştırıcı (comparator)
  - 4 bitlik eşitlik karşılaştırıcısı: bit çiftleri XOR'lanır, sonuçlar NOR kapısında birleştirilir.
- Üç durumlu tampon (tri-state buffer)
  - Enable aktif değilken çıkış yüksek empedans (Z) olur, hat devreden kopmuş gibi davranır. Ortak veri yolu için gereklidir.
- Ardışıl devreler
  - Çıkış hem girişlere hem bellek elemanlarının durumuna bağlıdır.
  - Latch seviye tetiklemeli, flip-flop kenar tetiklemelidir.
  - D, T ve JK flip-flop tanım tabloları; asenkron preset/clear ve senkron clear.
- Ardışıl devre tasarımı örneği: T flip-flop ile seri toplayıcı (Mealy makinesi).
- Verilog'a kısa giriş: yarım toplayıcı modülü, hiyerarşik tam toplayıcı, Icarus Verilog ile derleme ve GTKWave.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dekoder çıkışları minterm ya da maksterm verir
  - Aktif 1 çıkışlıda doğru mintermler OR'lanır, aktif 0 çıkışlıda yanlış makstermler AND'lenir. Böylece dekoderle her fonksiyon gerçeklenebilir.
  - Seçim uçlarına bağlantı sırası tablodaki anlam sırasına uymalıdır. Tabloda en anlamlı bit $A$ ise $A$ dekoderin en anlamlı girişine ($C$ ucu) bağlanır.
- Küçük bloklardan büyük blok kurmak (hiyerarşi) bir soyutlama seviyesidir
  - İçerideki kapı ve transistör seviyesi hazır kabul edilir.
- Enkoder tasarımında "don't care" durumları unutulmamalıdır
  - 4 girişli tabloda 16 satır vardır; tanımdan ötürü 12'si don't care'dir.
- Ripple carry toplayıcının sorunu gecikmedir
  - Her katın eldesi bir öncekini bekler; çıkış, son kat bitene kadar defalarca değişir (domino etkisi).
- Latch ile flip-flop arasındaki temel fark
  - Latch'in enable ucu seviye tetiklemeli, flip-flop'unki kenar tetiklemelidir.
- Ters (geri yönlü) flip-flop tanım bağıntısı
  - Tasarımda "bu geçiş için girişe ne verilmeli" sorusunu cevaplar.

## Kısa Tekrar Notları

- $n \times 2^n$ dekoder: enable = 1 iken girişteki sayıya karşılık gelen çıkış aktif olur, enable = 0 iken bütün çıkışlar pasiftir.
- Aktif 1 çıkışlı 3x8 dekoderde $Y_0 = \bar C \bar B \bar A$ (0. minterm), $Y_7 = CBA$. Aktif 0 çıkışlıda $\bar Y_0 = C + B + A$ (0. maksterm).
- Tam toplayıcı mintermleri: $C_{out} = \sum m(3,5,6,7)$, $S = \sum m(1,2,4,7)$.
- 4x16 dekoder ağacında ilk kat ($w_2, w_3$) ikinci kattaki dört dekoderden birini seçer, ikinci kat ($w_0, w_1$) o dekoderin çıkışını seçer.
- DEMUX: $Q_3 = S_1 S_0 A$, $Q_2 = S_1 \bar S_0 A$, $Q_1 = \bar S_1 S_0 A$, $Q_0 = \bar S_1 \bar S_0 A$.
- 4'e 2 enkoder: $y_0 = w_1 + w_3$, $y_1 = w_2 + w_3$; $w_0$ çıkışı etkilemez.
- Öncelik enkoderi: en yüksek anlamlı 1 kodlanır, daha düşük girişler don't care olur; hiç 1 yoksa $z = 0$.
- Üç yarım toplayıcıyla tam toplayıcı: üçüncü yarım toplayıcının toplam çıkışı $C_{out}$ olur, eldesi kullanılmaz (üç bitin toplamı iki bite sığar).
- 8 bitlik 4'e 1 MUX'ta seçim ucu sayısı $\log_2 4 = 2$'dir, $2n$ değil.
- $A - B = A + \bar B + 1$. XOR'un bir girişi 1 ise çıkış diğer girişin tersidir, 0 ise aynısıdır.
- Toplayıcı-çıkarıcıda kontrol ucu 0 ise $X + Y$, 1 ise $X - Y$ hesaplanır.
- Eşitlik karşılaştırıcısı: XOR'lar, ardından NOR.
- Tri-state: $E = 1$ iken $F = X$, $E = 0$ iken $F = Z$ (yüksek empedans). 4 türü vardır.
- T flip-flop: $T = 0$ durumu korur, $T = 1$ tersler. Ters tanım: durum değişiyorsa $T = 1$, değişmiyorsa $T = 0$.
- JK: 00 korur, 01 sıfırlar, 10 birler, 11 tersler.
- Seri toplayıcı: $S = X \oplus Y \oplus q$, $T = XY\bar q + \bar X \bar Y q$.

## Detaylı Açıklamalar

- **Dekoder ve fonksiyon gerçekleme.** 3x8 dekoderde girişler $C, B, A$ ($C$ en anlamlı), çıkışlar $Y_0 \dots Y_7$'dir. Enable 1 iken girişteki ikili sayı hangi değeri gösteriyorsa yalnız o çıkış aktif olur. Her çıkışın doğruluk tablosunda tek bir satır aktif olduğu için, aktif 1 çıkışlı dekoderde $Y_i$ tam olarak $i$. mintermdir ($Y_0 = \bar C \bar B \bar A$, $Y_1 = \bar C \bar B A$, $Y_6 = CB\bar A$, $Y_7 = CBA$) (ekrandan, 00:30:00). Aktif 0 çıkışlı dekoderde her çıkış tek bir satırda 0 olduğu için toplamlar çarpımı biçiminde tek terimle yazılır: $\bar Y_0 = C + B + A$, $\bar Y_1 = C + B + \bar A$, $\bar Y_2 = C + \bar B + A$, $\bar Y_7 = \bar C + \bar B + \bar A$. Yani çıkışlar makstermlerdir. Bir fonksiyon doğru mintermlerin OR'u ya da yanlış makstermlerin AND'i olarak yazılabildiği için dekoderle her fonksiyon gerçeklenir.
- **3x8 dekoderle tam toplayıcı** (ekrandan, 00:40:00). Doğruluk tablosu $A, B, C_{in}$ sırasındadır ve en anlamlı bit $A$'dır. Bu yüzden $A$ dekoderin $C$ ucuna, $B$ $B$ ucuna, $C_{in}$ $A$ ucuna bağlanır, enable'a 1 verilir. Aktif 1 çıkışlı dekoderde $C_{out}$ için $Y_3, Y_5, Y_6, Y_7$, $S$ için $Y_1, Y_2, Y_4, Y_7$ birer OR kapısında birleştirilir. Aktif 0 çıkışlı dekoderde yanlış makstermler alınır: $C_{out}$ için $\bar Y_0, \bar Y_1, \bar Y_2, \bar Y_4$, $S$ için $\bar Y_0, \bar Y_3, \bar Y_5, \bar Y_6$ birer AND kapısına girer. Dekoderin iç yapısı da her çıkış için girişlerin düz ya da tümleyenlerini ve enable'ı alan bir AND kapısıdır.
- **4x16 dekoder ağacı** (ekrandan, 00:45:00). Birinci kattaki 2x4 dekoderin girişleri $w_2$ ($C$) ve $w_3$ ($D$), çıkışları ikinci kattaki dört 2x4 dekoderin enable uçlarıdır. İkinci kattaki dekoderlerin $w_0$ ($A$) ve $w_1$ ($B$) uçları ortaktır. $D$'nin 0'dan 1'e geçmesi çıkışı 8 basamak, $C$'ninki 4, $B$'ninki 2, $A$'nınki 1 basamak kaydırır; örneğin 0000 $y_0$'ı, 1000 $y_8$'i seçer. Ana enable 0 olunca ikinci kattaki bütün enable'lar 0 olur, 16 çıkışın hepsi 0'a düşer.
- **DEMUX** (ekrandan, 00:50:00). 1'e 4 DEMUX'ta veri girişi $A$ (slaytta $I$), seçim uçları $S_1 S_0$'dır. Genel yazım $f = \sum_i m_i \cdot f(i)$'dir. Her çıkış sütununda yalnız bir satırda $A$ vardır, bu yüzden her çıkış o mintermin $A$ ile çarpımıdır. Devre iki NOT ve dört 3 girişli AND kapısıyla kurulur.
- **4'e 2 enkoder** (ekrandan, 00:55:00 ve 01:00:00). Yalnız dört satır kullanılarak yazılan $y_0 = \bar w_3 \bar w_2 w_1 \bar w_0 + w_3 \bar w_2 \bar w_1 \bar w_0$ ifadesi sadeleşmiyor gibi görünür. Doğrusu 16 satırlık tabloyu kurmaktır: tanım gereği yalnız bir girişin 1 olduğu 4 satır bilinir, kalan 12 satır don't care'dir. Karnaugh haritasında don't care'ler kullanılınca $y_0 = w_1 + w_3$, $y_1 = w_2 + w_3$ bulunur. $w_0$'ın devrede yer almaması mantıklıdır: yalnız $w_0 = 1$ iken iki çıkış da 0'dır.
- **Öncelik enkoderi.** 4'e 2 öncelik enkoderinde girişler $w_3$'ten (en anlamlı) $w_0$'a doğru taranır. İlk görülen 1'in numarası çıkışa yazılır, ondan düşük girişler don't care olur. Ek $z$ (valid) çıkışı en az bir giriş 1 ise 1'dir; hepsi 0 ise $z = 0$ olur ve $y_1 y_0$ anlamsızdır. Hoca bu yapının kesme önceliklendirmesinde kullanıldığını söyledi.
- **Yarım ve tam toplayıcı** (ekrandan, 01:25:00 ve 01:30:00). Yarım toplayıcı iki biti toplayıp $(C_{out} S)_2 = A + B$ iki basamaklı sonucunu üretir: $C_{out} = AB$, $S = \bar A B + A \bar B = A \oplus B$. Tam toplayıcı önceki basamağın eldesini de katar: $(C_{out} S)_2 = A + B + C_{in}$. $S$ haritası satranç tahtası desenindedir, $S = A \oplus B \oplus C_{in}$. $C_{out}$ Karnaugh ile $AB + C_{in}A + C_{in}B = AB + C_{in}(A + B)$ çıkar. Mintermler tek tek yazılıp gruplanırsa $(\bar A B + A \bar B)C_{in} + AB(\bar C_{in} + C_{in}) = (A \oplus B)C_{in} + AB$ elde edilir. Bu biçim $S$ için zaten üretilen $A \oplus B$ kapısını yeniden kullandığı için daha az kapı gerektirir.
- **Yarım toplayıcılarla tam toplayıcı.** Birinci yarım toplayıcı $A$ ile $B$'yi, ikincisi birincinin toplamı ile $C_{in}$'i toplar; ikincinin toplam çıkışı tam toplayıcının $S$'idir. İki elde (carry) bir OR kapısında birleşince $C_{out}$ elde edilir. Yalnız yarım toplayıcı kullanılacaksa OR yerine üçüncü bir yarım toplayıcı konur: iki elde bu yarım toplayıcıya girer, toplam çıkışı $C_{out}$ olur, eldesi dışarı çıkarılmaz. İki elde aynı anda 1 olamaz; üç bitin toplamı en çok 3'tür ve iki bite sığar.
- **Çok bitli MUX** (ekrandan, 01:45:00). 8 bitlik 4'e 1 MUX'un 4 girişi ve çıkışı 8 bitlik veri yollarıdır, seçim ucu 2 tanedir. Sekiz tane 1 bitlik 4'e 1 MUX kullanılır: $i$. MUX'un $w_0$ girişine $A_i$, $w_1$ girişine $B_i$ vb. bağlanır, bütün $S_0$'lar ve bütün $S_1$'ler ortaktır.
- **Çok bitli toplayıcılar** (ekrandan, 01:55:00). 32 bitlik toplayıcı iki 16 bitlik toplayıcıdan kurulur: $X$ ve $Y$'nin düşük anlamlı 16 biti ilk toplayıcıya, yüksek anlamlı 16 biti ikinciye girer; ilkinin $C_{out}$'u ikincinin $C_{in}$'ine bağlanır. Sonuç 32 bit toplam ve 1 bit eldeyle 33 bittir. Aynı şekilde 16 tam toplayıcı zincirlenerek 16 bitlik toplayıcı yapılır. Bu yapıda elde katlar boyunca sırayla yayıldığı için (ripple carry) sonuç ancak son kat bitince doğrudur, ara süreçte çıkışlar değişip durur.
- **Toplayıcı-çıkarıcı** (ekrandan, 02:05:00). $A - B = A + (B$'nin 2'ye tümleyeni$)$; 2'ye tümleyen, bire tümleyen artı 1'dir. $X \oplus 0 = X$ ve $X \oplus 1 = \bar X$ olduğundan $Y$'nin her biti, Add/Sub kontrol ucuyla XOR'lanır ve kontrol ucu aynı zamanda $C_0$'a bağlanır. Kontrol 0 iken $X + Y + 0$, kontrol 1 iken $X + \bar Y + 1 = X - Y$ hesaplanır.
- **Eşitlik karşılaştırıcısı** (ekrandan, 02:10:00). $A_i \ne B_i$ ise XOR çıkışı 1, eşitse 0'dır. Eşitlik varsa bütün XOR çıkışları 0, yoksa en az biri 1'dir. "Bütün girişler 0 iken 1 veren" kapı NOR'dur (OR'un tersi). Büyüklük karşılaştırmasında ise en anlamlı bitten başlanır, bitler eşitse bir sonraki bite geçilir (kaskat yapı).
- **Tri-state buffer** (ekrandan, 02:15:00). Aynı veri yoluna birden çok çıkış bağlanabilir ama bir anda yalnız biri sürmelidir; yoksa biri 0, diğeri 1 sürerken kısa devre olabilir. $E = 1$ iken $F = X$, $E = 0$ iken çıkış açık devre gibidir (yüksek empedans, $Z$). Empedans AC devrelerde frekansa bağlı dirençtir; sonsuz empedans açık devre demektir. Enable ve çıkışın aktif 1/aktif 0 olmasına göre dört tür vardır. 8 bitlik bir yol için her tele bir tane, yani 8 tri-state buffer gerekir.
- **Latch ve flip-flop** (ekrandan, 02:30:00). D latch'te CLK ucu enable gibi çalışır: CLK 1 iken latch saydamdır, D'deki her değişim Q'ya geçer; CLK düşünce son değer tutulur. D flip-flop D'yi yalnız yükselen kenarda örnekler, sonraki kenara kadar Q değişmez. Şemada CLK ucundaki üçgen kenar tetiklemeyi, daire aktif 0'ı ya da düşen kenarı gösterir. DDR bellekler gibi hem yükselen hem düşen kenarda çalışan yapılar, iki kenarı yakalayan devre tekrarlanarak kurulur.
- **Flip-flop tanımları ve preset/clear** (ekrandan, 02:40:00). D: yükselen kenarda $Q = D$, diğer durumlarda $Q = q$. T: $T = 0$ ise $Q = q$, $T = 1$ ise $Q = \bar q$. JK: 00 korur, 01 sıfırlar, 10 birler, 11 tersler. Aktif 0 preset ve clear uçları ilk durumu kurmak içindir ve saatten bağımsızdır (asenkron). $\bar S \bar R$ önce 00, sonra 01, sonra 11 yapılınca ilk durum 1, önce 00, sonra 10, sonra 11 yapılınca 0 olur. Senkron clear için D girişi clear sinyaliyle AND'lenir; clear 0 iken içerik ancak yükselen kenarda sıfırlanır.
- **Seri toplayıcı tasarımı (T flip-flop)** (ekrandan, 02:55:00 ve 03:00:00). $X$ ve $Y$'nin bitleri en düşük anlamlıdan başlayarak her saat adımında birer birer girer, her adımda toplamın bir biti çıkar. Durum, son işlemde elde olup olmadığıdır: "elde yok (0)" ve "elde var (1)". Çıkış hem duruma hem girişlere bağlı olduğu için Mealy makinesidir. Durum diyagramında 0 durumunda 00/0, 01/1, 10/1 ile kalınır, 11/0 ile 1'e geçilir; 1 durumunda 01/0, 10/0, 11/1 ile kalınır, 00/1 ile 0'a dönülür. Tek durum değişkeni yeter, yani tek T flip-flop. Tablo:

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

  T'nin ters tanımı: durum değişiyorsa $T = 1$, değişmiyorsa $T = 0$. Karnaugh haritalarından $S = X \oplus Y \oplus q$ ve $T = XY\bar q + \bar X \bar Y q$ bulunur. Devre: üç girişli XOR ile $S$; iki üç girişli AND ve bir OR ile $T$. Tablo python ile doğrulandı.
- **Verilog'a giriş** (ekrandan, 03:05:00). Her kod bloğu `module` ile başlar, `endmodule` ile biter; modül adından sonra parantez içinde parametreler gelir, sonra `input` ve `output` bildirimleri yapılır. Kapı seviyesindeki hazır `xor` ve `and` modüllerinde ilk parametre çıkıştır:

  ```verilog
  module half_adder(x,y,s,c);
      input x,y;
      output s,c;
      xor(s,x,y);
      and(c,x,y);
  endmodule
  ```

  Bu yapısal (structural) tanımdır. Hiyerarşik tanımda iki `half_adder` örneği ve bir `or` kapısıyla tam toplayıcı kurulur; kapılar arası bağlantılar `wire` ile tanımlanır. Derleme `iverilog -o half_adder half_adder.vl` ile yapılır (ekrandan, 03:10:00); dalga biçimleri GTKWave ile incelenir. Hoca Verilog'un ilerleyen derslerde örneklerle kullanılacağını söyledi. Icarus Verilog'da görsel şema çizme yoktur; Quartus'ta kapı seviyesinde tasarımdan Verilog'a dönüşüm mümkündü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
