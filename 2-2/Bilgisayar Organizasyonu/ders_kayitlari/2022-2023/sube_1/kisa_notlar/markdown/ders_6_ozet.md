# Ders 6 Çalışma Özeti

## Genel Konular

- Kısa tekrar: senkron sayıcıda kendi kendini düzeltme (auto-correction)
  - Tüm durumları kullanmayan keyfi bir sayıcıda kullanılmayan durumların nereye gideceği, Karnaugh diyagramında don't care ($x$) hücrelerine verilen değerlerle belirlenir.
  - Kullanılmayan durumlar kendi aralarında bir döngüye girip asıl sayma döngüsüne dönemiyorsa devre kendini düzeltemez. Bu durumda seçilen $x$ değerlerinden biri değiştirilip (örneğin 1 yerine 0 alınıp) devre yeniden tasarlanır.
- Yazmaç transferi için üç veri yolu (datapath) yapısı (ekrandan, 00:15:00 ve 00:35:00)
  - (a) Adanmış (dedicated) MUX: her yazmacın önünde kendine ait 2'ye 1 MUX vardır. R0'ın MUX'unun 0 girişi R2'den, 1 girişi R1'den; R1'in 0 girişi R0'dan, 1 girişi R2'den; R2'nin 0 girişi R0'dan, 1 girişi R1'den gelir. Denetim işaretleri: $L_0, L_1, L_2$ (yükleme) ve $S_0, S_1, S_2$ (seçim), toplam 6 işaret.
  - (b) Tek ortak yol (single bus): üç yazmacın çıkışı tek bir 3'e 1 MUX'a girer, MUX çıkışı bütün yazmaçların girişine dağıtılır. Denetim: $L_0, L_1, L_2$ ve $S_1S_0$.
  - (c) Üç durumlu (three-state) yol: her yazmacın çift yönlü veri ucu bir üç durumlu tampon ve enable ($E_i$) üzerinden ortak yola bağlanır; MUX yoktur. Denetim: $E_0, E_1, E_2$ ve $L_0, L_1, L_2$.
  - Yükleme işaretleri saatin yükselen kenarında etkilidir. Kombinasyonel kısımlar (MUX, yol) saati beklemeden çıkış üretir; kenar anında kopyalanan değer, kenar geçtiği için başka yazmaca aynı çevrimde yayılamaz. Bu yüzden eşanlı (paralel) transferler güvenlidir.
  - Adanmış MUX: farklı bir kaynaktan tek hedefe, aynı kaynaktan birden çok hedefe ve farklı kaynaklardan farklı hedeflere eşanlı transferi destekler. 2'ye 1 MUX kullanıldığı için bir yazmaç kendi değerini (ya da kendi değerinin bir fonksiyonunu, örneğin tümleyenini) kendine yükleyemez.
  - Ortak MUX yolu: tek kaynaktan bir ya da birden çok hedefe (kendisi dahil) transferi destekler; yola bir çevrimde tek değer çıkabildiği için farklı kaynaklardan eşanlı transfer (örneğin takas) yapılamaz. Seçim işareti bir azalır, devre karmaşıklığı düşer.
  - Üç durumlu yol: işlev olarak ortak MUX yolu ile aynıdır, MUX ortadan kalkar. Aynı anda yalnız bir $E_i$ 1 olabilir; iki yazmaç birlikte yola çıkarsa farklı değerlerde kısa devre olur.
  - MUX girişlerine yazmaç yerine kombinasyonel fonksiyonlar (toplam, bitwise AND, tümleyen, öteleme) konarak aynı yapılarla aritmetik ve lojik mikro işlemler de yapılabilir.
- Ötelemeli yazmaçlarla 4 bitlik seri toplayıcı (ekrandan, 00:45:00 - 01:00:00)
  - Problem: iki 4 bitlik ötelemeli yazmaçta tutulan iki sayı en düşük anlamlı bitten başlanarak bit bit toplanacak, sonuç yine yazmaçta saklanacak.
  - Hafızada tutulması gereken tek bilgi önceki basamaktan elde olup olmadığıdır: durum 0 = elde yok, durum 1 = elde var. Girişler $A_i$, $B_i$; çıkış $S_i$; tek flip-flop yeter.
  - Durum diyagramı (giriş $A_iB_i$/çıkış $S_i$): 0 durumunda $00/0$, $01/1$, $10/1$ ile kalır, $11/0$ ile 1'e geçer; 1 durumunda $01/0$, $10/0$, $11/1$ ile kalır, $00/1$ ile 0'a döner.
  - D flip-flop ile: $D = Q = AB + Aq + Bq$ (tam toplayıcının elde çıkışı), $S = A \oplus B \oplus q$ (tam toplayıcının toplam çıkışı).
  - Devre: bir tam toplayıcı; $C_{in}$'e flip-flop'un $q$ çıkışı, D girişine $C_{out}$ bağlanır. Yazmaçların seri çıkışları toplayıcının A ve B girişlerine gider, toplam bir yazmacın seri girişine geri verilir. Bütün saatler ortaktır, başlangıçta $q = 0$ yapılır; 4 saat darbesinden sonra toplam yazmaçta, son elde flip-flop'ta bulunur.
- Komut kümesi mimarisi (ISA) ve komut biçimi (ekrandan, 01:30:00)
  - Assembly kodu makine koduna çevrilir, program hafızasına yerleştirilir; sıradaki komutun adresini program sayıcı (PC) tutar (8086'da Instruction Pointer).
  - RISC'te komutlar eşit uzunlukta ve tek çevrimde yürütülür; PC sabit miktarda artar. CISC'te (8086 gibi) komut uzunlukları ve süreleri farklıdır; sonraki komutun adresi opcode ve moda bakılarak bulunur.
  - Komut alanları: Opcode (komut grubunu ve işlevi belirler), Mode (adresleme modunu belirler), Address or operand. Örneğin 5 bitlik opcode en fazla 32 komut demektir.
  - İki operandlı mimaride ilk operand aynı zamanda hedeftir; üç operandlı mimaride (MIPS, `add R1, R2, R3`) ilk operand hedef, diğer ikisi kaynaktır.
  - Akümülatör (8086'da AX) özel komutları ve donanımı olan, ALU sonuçlarının varsayılan olarak yazıldığı yazmaçtır.
- Adresleme modları (ekrandan, 01:35:00 ve 01:40:00)
  - Başlangıç durumu: PC = 250; 250'de opcode ve mod, 251'de 500, 252'de sonraki komut; M[400] = 700, M[500] = 800, M[752] = 600, M[800] = 300, M[900] = 200; R1 = 400.
  - Tablo (etkin adres / ACC içeriği):

    ```text
    Mod               Sembol         Yazmaç transferi        EA    ACC
    Direct            LDA ADRS       ACC <- M[ADRS]          500   800
    Immediate         LDA #NBR       ACC <- NBR              251   500
    Indirect          LDA [ADRS]     ACC <- M[M[ADRS]]       800   300
    Relative          LDA $ADRS      ACC <- M[ADRS + PC]     752   600
    Index             LDA ADRS (R1)  ACC <- M[ADRS + R1]     900   200
    Register          LDA R1         ACC <- R1               --    400
    Register-indirect LDA (R1)       ACC <- M[R1]            400   700
    ```
  - Göreli adreslemede PC, komut yürütülürken zaten sonraki komutu (252) gösterir; $252 + 500 = 752$.
  - Doğrudan adresli dallanma örneği: PC = 300'deki "ACC = 0 ise dallan" komutu ACC sıfırsa PC'yi 500 yapar, değilse 302'ye geçer.
  - 8086 karşılıkları (ekrandan, 01:50:00): direct `MOV AL,[100]`, immediate `MOV AL,100`, relative `JLE L1`; index için dizi[SI] biçimi, register için `MOV AL,BL`. Bellek dolaylı adreslemenin 8086'da karşılığı yoktur.
- Tipik komut grupları
  - Veri transferi (ekrandan, 01:55:00): LD, ST, MOVE, XCH, PUSH, POP, IN, OUT.
  - Aritmetik (ekrandan, 02:05:00): INC, DEC, ADD, SUB, MUL, DIV, ADDC, SUBB, SUBR, NEG.
  - Lojik ve bit işlem: CLR, SET, NOT (bire tümleyen), AND, OR, XOR; carry bayrağını sıfırlayan, birleyen ve tersleyen komutlar.
  - Öteleme ve döndürme (ekrandan, 02:10:00): SHR, SHL, SHRA, SHLA, ROR, ROL, RORC, ROLC.
  - Program denetimi (ekrandan, 02:15:00): BR, JMP, CALL, RET, CMP (çıkarma ile), TEST (AND ile).
- Yığın (stack) (ekrandan, 02:00:00)
  - LIFO çalışan bellek bölgesidir; alt yordama parametre aktarımı, geçici saklama ve dönüş adresi saklama için kullanılır.
  - Slayttaki örnekte SP = 101, yığında 101'de C, 102'de B, 103'te A vardır. Push'ta SP önce bir azalır (100), sonra R1 o adrese yazılır. Pop'ta SP'nin gösterdiği dolu gözden okunur, sonra SP bir artar. Yığın yüksek adresten aşağı doğru büyür (8086'daki gibi).
- Koşullu dallanma ve bayraklar (ekrandan, 02:30:00 ve 02:45:00)
  - Basit dallanmalar tek bayrağa bakar: BZ/BNZ ($Z$), BC/BNC ($C$), BN/BP ($N$), BV/BNV ($V$).
  - İşaretsiz karşılaştırmada "above/below", işaretlide "greater/less" kullanılır. CMP A,B ($A - B$) sonrası:

    ```text
    İşaretsiz (C burada borrow):      İşaretli:
    BA   A >  B   C + Z = 0           BG   A >  B   (N xor V) + Z = 0
    BAE  A >= B   C = 0               BGE  A >= B   N xor V = 0
    BB   A <  B   C = 1               BL   A <  B   N xor V = 1
    BBE  A <= B   C + Z = 1           BLE  A <= B   (N xor V) + Z = 1
    BE   A =  B   Z = 1               BE   A =  B   Z = 1
    BNE  A != B   Z = 0               BNE  A != B   Z = 0
    ```
- Program sayıcıyı değiştiren durumlar
  - Koşullu dallanma: PC'ye göreli bir değer eklenir ya da çıkarılır.
  - CALL: dönüş adresi saklanır, PC'ye doğrudan yeni değer yüklenir; RET saklanan adresi geri yükler.
  - Kesme: kesme isteği onaylanır (acknowledge), cihaz bir kesme vektör adresi gönderir, PC bu adrese göre kesme alt programını gösterir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yükleme işaretinin anlamı
  - Bir yazmaca yükleme yapılması istenmiyorsa $L_i = 0$ yazılır, don't care bırakılmaz; "yükle" emri yoksa "yükleme" emri vardır. Yüklenmeyen yazmacın MUX seçim ucu ise don't care olabilir.
- Üç durumlu yolda tek sürücü kuralı
  - Enable'lardan yalnız biri 1 olmalıdır; aksi halde yolda çakışma ve kısa devre oluşur.
- Exchange (takas) komutunun değeri (ekrandan, 01:55:00)
  - C'de takas `t = a; a = b; b = t;` ile üç adımda yapılır. İşlemci XCH komutunu destekliyorsa iyi optimize edilmiş kod bunu tek komutla yapar. Derleyicinin ürettiği assembly kodunu incelemek ve gerekirse optimizasyon seviyesini değiştirmek bu yüzden önemlidir.
- CMP ile SUB, TEST ile AND farkı
  - CMP ve SUB bayrakları aynı biçimde etkiler, ama SUB sonucu ilk operanda yazar; CMP hiçbir operandı bozmaz. TEST de bayrakları AND gibi etkiler ama sonucu saklamaz.
- Koşul adını akışa uygun seçmek
  - "Branch if greater" ile "branch if not less or equal" aynı bayraklara bakar. Kodda yazılan koşulun birebir karşılığı olan komutu seçmek okunabilirliği artırır.
- JMP ile gidilen yere JMP ile dönülebilir; CALL ile çağrılan alt yordamdan mutlaka RET ile dönülür, çünkü dönüş adresinin saklanıp geri yüklenmesi CALL/RET çiftinin içindedir.
- Bitwise ve lojik işlem farkı
  - C'de `a & b` bitwise, `a && b` lojik AND'dir. Donanım bitwise işlemleri doğrudan destekler.

## Kısa Tekrar Notları

- Adanmış MUX: 6 denetim ucu ($L_0..L_2$, $S_0..S_2$); kendine yükleme yok, farklı kaynaklardan eşanlı transfer var.
- Ortak MUX yolu: 5 denetim ucu ($L_0..L_2$, $S_1S_0$); tek kaynaktan çok hedefe var, takas yok.
- Üç durumlu yol: $E_0..E_2$, $L_0..L_2$; aynı anda tek $E_i = 1$.
- Örnek denetim değerleri: R0 ← R1 (adanmış MUX) $L_0L_1L_2 = 100$, $S_0 = 1$, $S_1 = S_2 = x$; R0 ← R1, R2 ← R1 için $L = 101$, $S_0 = 1$, $S_1 = x$, $S_2 = 1$; R0 ← R1, R2 ← R0 için $S_2 = 0$.
- Seri toplayıcı: durum = elde; $D = AB + Aq + Bq$, $S = A \oplus B \oplus q$.
- Komut alanları: Opcode | Mode | Address/operand.
- Adresleme modları ve sonuçlar: direct 800, immediate 500, indirect 300, relative 600, index 200, register 400, register-indirect 700.
- Push: SP azalır, sonra yazılır. Pop: okunur, sonra SP artar.
- SHRA işaret bitini korur, taşma olmaz; SHLA = SHL, taşma olabilir.
- RORC/ROLC carry dahil 9 bit üzerinde (8 bitlik yazmaçta) döndürür; ROR/ROL 8 bit üzerinde döndürür, çıkan bit carry'ye de kopyalanır.
- İşaretsiz: C toplamada elde, çıkarmada borrow; taşmayı C gösterir. İşaretli taşmayı V gösterir.
- BA: $C + Z = 0$; BAE: $C = 0$; BB: $C = 1$; BBE: $C + Z = 1$.
- BG: $(N \oplus V) + Z = 0$; BGE: $N \oplus V = 0$; BL: $N \oplus V = 1$; BLE: $(N \oplus V) + Z = 1$.
- PC'yi değiştirenler: koşullu dallanma (göreli), CALL (doğrudan), kesme (vektör adresi).

## Detaylı Açıklamalar

- **Adanmış MUX yapısında denetim işaretleri.** R0 ← R1 transferinde yalnız R0 yüklenecektir: $L_0 = 1$, $L_1 = L_2 = 0$. R0'ın MUX'unda R1, 1 numaralı girişte olduğundan $S_0 = 1$; yüklenmeyen yazmaçların MUX'ları önemsizdir, $S_1 = S_2 = x$ (ekrandan, 00:20:00). Eşanlı R0 ← R1, R2 ← R1 için $L_0 = 1$, $L_1 = 0$, $L_2 = 1$, $S_0 = 1$, $S_1 = x$; R2'nin MUX'unda R1, 1 numaralı girişte olduğundan $S_2 = 1$. R0 ← R1, R2 ← R0 için yalnız $S_2 = 0$ olur. Bu yapı R0 ← R0 ya da R0 ← $\overline{R0}$ gibi bir yazmacın kendi değerini kullanan transferleri yapamaz, çünkü her 2'ye 1 MUX yalnız diğer iki yazmacı görür. MUX genişletilip her yazmaca bütün kaynaklar (ve onların aritmetik/lojik fonksiyonları) verilirse bu kısıt kalkar.
- **Ortak MUX yolu ve üç durumlu yol.** Ortak yolda R0 ← R1 için $L_0L_1L_2 = 100$ ve $S_1S_0 = 01$ verilir (ekrandan, 00:30:00). R1 değeri kendi girişine de geldiği için R1 ← R1 de yapılabilir. R0 ← R1, R2 ← R1 için yalnız $L_2 = 1$ eklenir. Ama R0 ← R1, R1 ← R0 (takas) yapılamaz, çünkü yola bir çevrimde iki farklı değer çıkamaz. Üç durumlu yolda R0 ← R1 için $E_0 = 0$, $E_1 = 1$, $E_2 = 0$ ve $L_0 = 1$, $L_1 = L_2 = 0$ verilir (ekrandan, 00:35:00). R0 ← R0 için $E_0 = 1$, $L_0 = 1$, diğerleri 0'dır.
- **Seri toplayıcının türetilmesi.** Hoca önce onluk tabanda $1287 + 1122$ toplamasını tahtada yaptı (ekrandan, 00:45:00): $7 + 2 = 9$ elde yok, $8 + 2 = 10$ yaz 0 elde 1, $2 + 1 + 1 = 4$, $1 + 1 = 2$; sonuç 2409. Elle toplamada da her basamakta yalnız önceki basamaktan gelen elde hatırlanır; bu da durum değişkenidir. İkilik tabanda durum tablosu (ekrandan, 00:55:00):

  ```text
  A B q | Q = D | S
  0 0 0 |   0   | 0
  0 0 1 |   0   | 1
  0 1 0 |   0   | 1
  0 1 1 |   1   | 0
  1 0 0 |   0   | 1
  1 0 1 |   1   | 0
  1 1 0 |   1   | 0
  1 1 1 |   1   | 1
  ```

  D flip-flop'ta $D = Q$ olduğundan $D$ sütunu sonraki durum sütunuyla aynıdır. Karnaugh diyagramından $D = AB + Aq + Bq$ çıkar, bu tam toplayıcının elde çıkışıdır; $S$ de tam toplayıcının toplam çıkışıdır. Tahtadaki devrede A yazmacının seri girişine 0 verildi, toplam B yazmacının seri girişine bağlandı (ekrandan, 01:00:00). Tablo ve fonksiyonlar Python ile 8 satır için doğrulandı.
- **Aritmetik öteleme örneği.** 4 bitlik ikiye tümleyen gösteriminde $1110 = -2$'dir. SHRA ile bitler bir sağa kayar, en sağdaki bit carry'ye gider, boşalan en soldaki göze eski işaret biti (1) yazılır: $1111 = -1$. Sağa aritmetik öteleme işareti koruyarak 2'ye bölmedir. <!-- BELİRSİZ: Tahtadaki 4 bitlik dizinin karesi yok; 1110 değeri hocanın söylediği -2'den kuruldu. -->
- **TEST ile bit denetimi.** "A'nın 3 numaralı biti 1 ise F'yi çalıştır" koşulu için ilgilenilen bit 1, diğerleri 0 olan maske kullanılır: `TEST A, 08H`. Sonuç 0 değilse bit 1'dir: `BNZ L1` ile F'nin bulunduğu L1'e dallanılır.
- **İşaretli karşılaştırmada $N \oplus V$.** $A > B$ iken $A - B$ ya taşmasız ve pozitif çıkar ($N = 0$, $V = 0$; örneğin $127 - 10 = 117$) ya da taşar ve sonuç negatif görünür ($N = 1$, $V = 1$; $127 - (-100) = 227$, 8 bitte $-29$). Her iki durumda $N = V$, yani $N \oplus V = 0$; eşitliği dışlamak için $Z = 0$ da gerekir: BG için $(N \oplus V) + Z = 0$. $A < B$ iken $N \ne V$ olur: örneğin $-127 - 10 = -137$ 8 bite sığmaz, sonuç $+119$ görünür ($N = 0$, $V = 1$). Değerler Python ile 8 bit için doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
