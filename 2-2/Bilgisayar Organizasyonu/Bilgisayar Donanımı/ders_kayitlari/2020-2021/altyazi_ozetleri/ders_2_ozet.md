# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 19 Mart 2021 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:06:20'de başlar.
  - Lojik konularının tekrarı sürüyor.
- Toplayıcılar
  - Yarım toplayıcı (half adder) ve tam toplayıcı (full adder).
  - Tam toplayıcılarla $n$ bitlik ripple carry adder.
- Çok bitli yapı taşları
  - 8 bitlik 4'ten 1'e MUX: 8 tane 1 bitlik 4'ten 1'e MUX.
  - 16 bitlik işaretsiz toplayıcı.
  - Toplayıcı-çıkarıcı (adder-subtractor) devresi.
- Karşılaştırıcı (comparator)
  - XOR ve NOR ile eşitlik kontrolü.
  - Çıkarma işlemiyle büyüklük karşılaştırması.
- İkiye tümleyen aritmetiği
  - İşaretsiz çıkarma ve elde/borç biti.
  - İşaretli toplama, çıkarma ve taşma (overflow).
  - Durum bitleri: C, V, Z, N.
- Üç durumlu tampon (three-state buffer)
  - Yüksek empedans (Hi-Z) çıkışı ve veri yolunda (bus) kullanımı.
- Ardışıl devreler
  - Latch ve flip-flop farkı, D latch, D flip-flop.
  - Asenkron preset ve clear girişleri.
  - D, SR, JK ve T flip-flop karakteristik tabloları. JK geçiş tablosuna giriş.
- Ardışıl devre analizi
  - Tersine mühendislik örneği: devreden state table ve state diagram çıkarmak (Mealy modeli).
  - Moore modeli örneği.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yarım toplayıcı elde girişi almadığı için çok bitli toplayıcı kurmaya yetmez. Tam toplayıcı kullanılır.
- Bundan sonraki tasarımlarda hazır bir tam toplayıcı olduğu varsayılacak.
- İkiye tümleyeni alırken "tersini çevirip başına 1 eklemek" yanlıştır.
  - Doğrusu: bitleri ters çevir, sonra en düşük anlamlı bite 1 ekle.
  - Kısa yol: sağdan ilk 1'e kadar bitleri aynen yaz, sonrakilerin tersini al.
- Çıkarmada elde biti C = 1 ise borç biti B = 0'dır. Bu, X'in Y'den büyük olduğunu gösterir.
  - Böylece aritmetik devre bir karşılaştırıcı gibi de kullanılabilir.
- İşaretli sayılarda V (overflow), Z (zero) ve N (negative) bitlerine bakılır.
  - İşaretsiz sayılarda overflow biti kullanılmaz, yalnızca C bitine bakılır.
- $-1$'in ikiye tümleyen gösteriminde bütün bitler 1'dir. ALU tasarımında sık karşımıza çıkacak.
- İki normal kapının çıkışı birbirine bağlanamaz. Üç durumlu tamponlarda bağlanabilir, ama aynı anda yalnızca biri etkin olmalıdır.
- Devre tasarımında latch değil flip-flop kullanılacak.
- Flip-flop karakteristik tablolarını ezbere bilmelisiniz. JK geçiş tablosunu karakteristik tablodan kendiniz üretebilmelisiniz.
- Mealy ve Moore modellerini hem çıkış denkleminden hem de state diagram'dan ayırt edebilmelisiniz.
- Lojik eksiği olanlar (özellikle bilimsel hazırlık öğrencileri) ilk 2-3 hafta içinde kitabın ilk 5-6 bölümünü tekrar etmeli.

## Kısa Tekrar Notları

- Yarım toplayıcı: $S = A \oplus B$, $C = AB$.
- Tam toplayıcı: $S = A \oplus B \oplus C_{in}$, $C_{out} = AB + C_{in}(A \oplus B)$.
- Ripple carry adder: her bitin $C_{out}$'u bir üst bitin $C_{in}$'ine bağlanır.
- Adder-subtractor: kontrol ucu $S = 0$ ise $X + Y$, $S = 1$ ise $X + \bar{Y} + 1 = X - Y$.
- XOR'un bir girişi 0 ise çıkış diğer girişe eşittir. Bir girişi 1 ise çıkış diğer girişin tersidir.
- $n$ bit ikiye tümleyen aralığı: $-2^{n-1} \ldots 2^{n-1} - 1$. 8 bit: $-128 \ldots +127$.
- Overflow: $V = C_n \oplus C_{n-1}$ (işaret bitinden çıkan elde XOR işaret bitine giren elde).
- Three-state buffer: E = 1 ise $F = X$, E = 0 ise $F$ = Hi-Z.
- Latch: clock 1 olduğu sürece girişi izler. Flip-flop: yalnızca clock kenarında değişir.
- Asenkron preset/clear clock'u beklemez. Senkron clear clock kenarında etki eder.
- D: $Q(t+1) = D$. T: $T = 0$ ise $Q$, $T = 1$ ise $\bar{Q}$.
- JK: 00 değişmez, 01 reset, 10 set, 11 tümleyen. SR: 11 tanımsız.
- Mealy: çıkış girişe de bağlı. Moore: çıkış yalnızca duruma bağlı.

## Detaylı Açıklamalar

### Yarım toplayıcı ve tam toplayıcı

Yarım toplayıcı iki bitlik girişi toplar ve toplam (sum) ile elde (carry out) üretir. Toplam çıkışı XOR ile gerçekleştirilir. Çünkü toplam, girişlerdeki 1'lerin sayısı tek olduğunda 1'dir.

Tam toplayıcı üç bit toplar: $A$, $B$ ve $C_{in}$. Toplam çıkışı yine 1'lerin sayısı tek olduğunda 1'dir. Bu yüzden Karnaugh haritasında sadeleşmez ve iki tane 2 girişli XOR (ya da bir tane 3 girişli XOR) ile kurulur. İki yarım toplayıcı ile bir tam toplayıcı yapılabilir.

$n$ tane tam toplayıcı yan yana bağlanırsa ripple carry adder elde edilir. En düşük anlamlı bitin $C_{in}$'i 0'a bağlanır. Doğru sonuç için elde, en düşük anlamlı bitten en yüksek anlamlı bite kadar ilerlemelidir.

### Çok bitli yapı taşları

İşlemcide 8, 16, 32 bitlik sayılarla çalışılır. Bu yüzden yapı taşları çok bitli hâle getirilir.

8 bitlik 4'ten 1'e MUX'un içinde 8 tane 1 bitlik 4'ten 1'e MUX vardır. Her MUX dört sayının aynı ağırlıktaki bitlerini alır. Bütün MUX'ların seçme uçları ortaktır. Şemada bu yapı tek bir blokla gösterilir.

16 bitlik işaretsiz toplayıcının iki 16 bitlik girişi, bir $C_{in}$ girişi, 16 bitlik toplam çıkışı ve bir $C_{out}$ çıkışı vardır. $C_{in}$ sayesinde iki blok kaskat bağlanıp 32 bitlik toplayıcı yapılabilir.

### Toplayıcı-çıkarıcı

$Y$ girişinin her biti bir XOR kapısından geçer. XOR'un diğer girişine bir kontrol ucu ($S$) bağlanır. Aynı kontrol ucu toplayıcının $C_{in}$ girişine de bağlanır.

- $S = 0$: $Y$ değişmeden geçer, $C_{in} = 0$. Sonuç $X + Y$.
- $S = 1$: $Y$'nin bitleri ters çevrilir, $C_{in} = 1$. Sonuç $X + \bar{Y} + 1 = X - Y$.

### Karşılaştırıcı

Eşitlik kontrolü: iki sayının aynı ağırlıktaki bitleri XOR'lanır. Bitler eşitse XOR çıkışı 0'dır. Bütün XOR çıkışları bir NOR kapısına girer. NOR çıkışı 1 ise $A = B$'dir.

Büyüklük kontrolü için bir öğrenci en anlamlı bitten başlayarak bitleri karşılaştırmayı önerdi. Hoca bunun da doğru olduğunu söyledi. Ancak tercih edilen yol, hazır aritmetik devreyle çıkarma yapıp elde bitine bakmaktır.

### İşaretsiz çıkarma örneği

$X = 1010100_2 = 84$, $Y = 1000011_2 = 67$.

- $Y$'nin ikiye tümleyeni: $0111101$.
- $X + 0111101 = 1\,0010001$. Elde biti C = 1, sonuç $0010001_2 = 17$.

$84 - 67 = 17$ doğrudur. Borç biti $B = \bar{C} = 0$ çıktı. Borç alınmadığı için $X > Y$'dir. Bu yöntemle bir karşılaştırıcı elde edilir.

### İşaretli sayı örnekleri

$X = +6 = 00000110$, $Y = +13 = 00001101$ (8 bit).

- $Y$'nin ikiye tümleyeni: $11110011$.
- $X - Y = 00000110 + 11110011 = 11111001 = -7$.
- $X + Y = 00010011 = 19$. İşaret bitine giren elde 0, çıkan elde 0. Taşma yok.

Taşmalı örnek: $+70 + 80$.

- $70 = 01000110$, $80 = 01010000$.
- Toplam: $10010110$. İki pozitif sayının toplamı negatif görünüyor ($-106$).
- İşaret bitine giren elde 1, çıkan elde 0. $V = 1 \oplus 0 = 1$. Taşma oluştu.
- $150$, 8 bitlik işaretli aralığın ($-128 \ldots +127$) dışındadır.

4 bitlik ikiye tümleyen tablosu: pozitif sayılarda işaret biti 0, negatiflerde 1'dir. $-1 = 1111$, $-8 = 1000$. İkiye tümleyende $+0$ ve $-0$ ayrımı yoktur.

### Durum bitleri

İşlemci C, V, Z ve N bitlerinin hepsini her işlemde üretir. Hangisinin dikkate alınacağına programcı karar verir.

- İşaretsiz sayılar: C (carry) bitine bakılır.
- İşaretli sayılar: V (overflow), Z (zero) ve N (negative) bitlerine bakılır.
- $V$, işaret bitinden çıkan elde ($C_n$) ile işaret bitine giren eldenin ($C_{n-1}$) XOR'udur.

### Üç durumlu tampon (three-state buffer)

Girişteki işareti çıkışa aktaran ve bir enable ucuyla kontrol edilen bir kanaldır.

- E = 1: çıkış girişe eşittir.
- E = 0: çıkış Hi-Z'dir (yüksek empedans). Hat kopukmuş gibi davranır.

İki normal kapının çıkışları birbirine bağlanırsa, biri 1 (5 V) diğeri 0 (0 V) olduğunda kısa devre olur. Üç durumlu tamponların çıkışları ise birbirine bağlanabilir. Şart: aynı anda yalnızca bir tampon etkin olmalıdır. Örneğin iki tamponun enable uçları birbirinin tersiyle sürülür.

Kullanım alanı: işlemcide veri yolu ve adres yolu (bus) oluşturmak. 8 bitlik bir veri yolu için 8 tane üç durumlu tampon kullanılır.

Dört türü vardır: girişi aynen ya da tersleyerek aktaran ve enable'ı 1'de ya da 0'da aktif olan türler. Sembolün üzerindeki işaretlerden (daire, ters çevirme) hangisi olduğunu anlayabilmelisiniz.

### Latch ve flip-flop

Ardışıl devre = kombinasyonel lojik + durum tutan elemanlar (flip-flop) + clock.

- SR latch: clock = 0 iken değişmez. Clock = 1 iken SR'ye göre çalışır. S = R = 1 tanımsızdır.
- D latch: clock = 1 olduğu sürece çıkış D'yi izler. Clock = 0 iken son değeri tutar.
- D flip-flop: yalnızca clock'un yükselen kenarında (positive edge) D'yi çıkışa aktarır. Sembolde clock girişindeki küçük üçgen kenar tetiklemeyi gösterir. Önünde daire varsa düşen kenarda (negative edge) tetiklenir.

### Asenkron preset ve clear

Slayttaki flip-flopta preset ve clear uçları 0'da aktiftir.

- Preset = 0: Q = 1 olur. Clear = 0: Q = 0 olur.
- İkisi de 1 ise normal çalışma.

Asenkron olmaları clock'tan bağımsız çalıştıkları anlamına gelir. Aktif oldukları anda çıkış değişir. Senkron clear ise D girişinin önüne bir AND kapısı konarak yapılır ve yalnızca clock kenarında etki eder. Preset ve clear aynı anda 0 yapılmamalıdır.

### Flip-flop karakteristik tabloları

| Tür | Girişler | $Q(t+1)$ |
| :---: | :---: | :---: |
| D | $D = 0 / 1$ | $0 / 1$ |
| T | $T = 0 / 1$ | $Q(t) / \overline{Q(t)}$ |
| SR | 00 / 01 / 10 / 11 | $Q(t)$ / 0 / 1 / tanımsız |
| JK | 00 / 01 / 10 / 11 | $Q(t)$ / 0 / 1 / $\overline{Q(t)}$ |

Tasarımda bir de geçiş tablosu (excitation table) gerekir: $Q(t)$ ve $Q(t+1)$ biliniyorsa girişler ne olmalıdır? Bu tablo karakteristik tablodan üretilir (ayrıntısı 3. derste).

### Tersine mühendislik: Mealy modeli devre

Elimizde iki D flip-flop (A ve B), bir X girişi ve bir Y çıkışı olan bir devre var. Devrenin ne yaptığını bulacağız.

1. Flip-flop giriş denklemlerini ve çıkış denklemini yaz:
   - $D_A = AX + BX$
   - $D_B = \bar{A}X$
   - $Y = (A + B)\bar{X}$
2. State table oluştur.
3. State table'dan state diagram çiz.

| $AB$ | $X$ | $A(t+1)B(t+1)$ | $Y$ |
| :---: | :---: | :---: | :---: |
| 00 | 0 | 00 | 0 |
| 00 | 1 | 01 | 0 |
| 01 | 0 | 00 | 1 |
| 01 | 1 | 11 | 0 |
| 10 | 0 | 00 | 1 |
| 10 | 1 | 10 | 0 |
| 11 | 0 | 00 | 1 |
| 11 | 1 | 10 | 0 |

State diagram'da her ok "X/Y" ile etiketlenir. Çıkış denkleminde X girişi bulunduğu için bu bir Mealy modeli devredir. Çıkış denkleminde girişlerden yalnızca birinin bulunması da yeterlidir.

Tasarımda sıra bunun tersidir: problem, state diagram, state table, denklemler, devre.

### Moore modeli devre

Bir D flip-flop, iki giriş (x, y) ve bir z çıkışı:

$$D_A = A \oplus x \oplus y, \qquad z = A$$

Çıkış yalnızca durum değişkenine bağlı olduğu için devre Moore modelidir. State diagram'da çıkış dairenin içine "durum/çıkış" şeklinde yazılır. Okların üzerinde yalnızca girişler bulunur.

Hoca bu konu için evde çözülecek iki ardışıl devre tasarım sorusu paylaşacağını söyledi.

### Ders sonrası notlar

- Hoca "çıkarma işleminde overflow oluşmaz" dedi. Bu genel olarak yanlış. Aynı işaretli iki sayının farkında taşma olmaz. Farklı işaretli sayılarda olabilir. Örneğin 8 bitte $100 - (-100) = 200$ taşar. İkiye tümleyen ile çıkarma da bir toplama olduğu için V biti aynı şekilde hesaplanır.
- $70 + 80$ örneğinde "işaret biti dışarı taştı" dendi. Daha doğrusu: işaret bitine 1 elde girdi, işaret bitinden dışarı elde çıkmadı. Sonuç bitleri 8 bite sığdı ama işaret biti yanlış (1) çıktı. $V = C_8 \oplus C_7 = 0 \oplus 1 = 1$.
- T flip-flop anlatılırken "T = 0 ise no change yani QT'nin komplementi" dendi. Doğrusu: $T = 0$ ise $Q(t+1) = Q(t)$, $T = 1$ ise $Q(t+1) = \overline{Q(t)}$.
- Derste bir yerde "SR flip-flop" denip sonra "SR latch" diye düzeltildi. Ayrım sembolden yapılır: clock girişinde kenar tetikleme üçgeni yoksa eleman latch'tir, varsa flip-flop'tur.
- Sayısal örnekler (84 - 67, 6 - 13, 6 + 13, 70 + 80) ve Mealy state table'ı Python ile kontrol edildi; sonuçlar derstekiyle aynı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
