# Ders 1 Genişletilmiş Notu: 8086 Yazmaçlarının Tekrarı, Komut Yapısı, Veri Aktarım ve Aritmetik Komutlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8086 Yazmaçlarının Tekrarı
- 2. Yazmaç Kavramı ve Bellek Hiyerarşisi
- 3. Segment ve Offset ile 20 Bitlik Adres
- 4. Bayraklar
- 5. 32 ve 64 Bitlik x86 Yazmaçları, Gerçek Mod
- 6. Komut Yapısı ve MASM Sözdizimi
- 7. Komutlardaki Kısaltmalar ve Bellek Erişimi
- 8. MOV Komutu
- 9. LEA Komutu
- 10. LDS, LES, XCHG ve XLAT
- 11. Aritmetik Komutlar
- 12. Örnek: 32 Bitlik İki Sayının Toplanması
- 13. SUB, SBB, INC, DEC, NEG ve CMP
- Örnek Sorular
- Dersin Toparlaması

## 1. 8086 Yazmaçlarının Tekrarı

Ders, bir önceki haftanın kısa bir tekrarıyla başladı. Hoca 8086 açısından en önemli konulardan birinin yazmaçlar olduğunu söyledi ve slayttaki yazmaç tablosunu yeniden gözden geçirdi (ekrandan, 00:10:00). Tabloda yazmaçlar dört grupta gösterilir:

- Genel amaçlı yazmaçlar: AX (AL, AH), BX (BL, BH), CX (CL, CH), DX (DL, DH), SI, DI, SP, BP.
- Segment yazmaçları: SS, CS, DS, ES.
- Özel amaçlı yazmaç: IP.
- Bayrak yazmacı (FLAGS): CF, PF, AF, ZF, SF, TF, IF, DF, OF.

Genel amaçlı yazmaçlar, kod içinde erişilip üzerinde işlem yapılabilen yazmaçlardır. Hoca bunlar arasında özel dikkat isteyen tek yazmacın SP olduğunu belirtti.

### 1.1 AX: akümülatör

AX 16 bitlik, AL ise 8 bitlik akümülatördür. Akümülatör için özel donanım ve özel komutlar vardır: aynı işlem AX ya da AL üzerinden yapılırsa daha hızlı gerçekleşir ve komut daha az bitle ifade edilir. Adı akümülatör olsa da genel olarak veri işlemlerinde kullanılır. Ayrıca DIV ve MUL gibi komutlarda gizli (örtük) operand, giriş/çıkış işlemlerinde de varsayılan operanddır: bir G/Ç birimine veri yazmak ya da ondan okumak için AX/AL dışında bir yazmaç kullanılamaz. Hoca G/Ç komutlarının ayrıntısının Mikroişlemciler dersinde görüleceğini, bu derste yalnız bir giriş yapılacağını söyledi.

### 1.2 BX, SI ve DI

BX'in adı "base register"dır. Bellekte bir tablo (dizi ya da matris) oluşturulduğunu düşünelim; bu tablonun başlangıcını gösteren değer BX'te tutulur. Bu işlev yalnız BX'e aittir; BL ve BH'nin böyle bir işlevi yoktur.

Köşeli parantez içinde yazılan değer bir bellek gözünü gösterir. Köşeli parantez içine BX yazılabilir ama BH ya da BL yazılamaz. Köşeli parantez içinde SI ve DI de kullanılabilir. AX, CX ya da 8 bitlik yazmaçlar (AH, BL, DL, DH vb.) köşeli parantez içinde kullanılamaz.

SI (source index) ve DI (destination index) indis yazmaçlarıdır. BX bir dizinin başlangıç adresini tutarken, SI ve DI başlangıçtan ne kadar ötedeki göze erişileceğini belirtir. Bu yüzden tablonun belirli bir gözüne `[BX+SI]` (ya da `[BX+DI]`) ile erişilir: "BX'te başlayan tablonun SI indisindeki veri".

### 1.3 CX ve DX

CX "count register"dır. Genel veri işlemlerinde kullanılabilir, ama özel olarak döngü işlemlerinde kullanılır; CX ve CL belirli döngü komutlarında sayaç görevi görür. DX "data register"dır. Veri işlemlerinde kullanılır; AX gibi DIV ve MUL işlemlerinde gizli operand, G/Ç işlemlerinde varsayılan operanddır.

### 1.4 SP ve BP

SP (stack pointer) ve BP (base pointer) yığınla ilgili yazmaçlardır. SP mikroişlemci tarafından otomatik güncellenir: PUSH, POP, CALL, INT ya da RET gibi yığınla ilgili bir komut çalıştığında SP, yığındaki en üstteki anlamlı veriyi gösterecek değeri alır.

BP de yığınla ilgilidir ama mikroişlemci BP'yi değiştirmez. SP sürekli arttığı ve azaldığı için, yığında belirli bir offsetteki veriye erişmek isteyen programın sabit bir referansa, hocanın deyişiyle bir "çapa"ya ihtiyacı vardır. O anki SP değeri BP'ye kopyalanır. Artık yığına yeni değerler eklense bile aranan veriye her zaman BP'ye göre (örneğin "BP eksi bir değer" biçiminde) erişilebilir.

## 2. Yazmaç Kavramı ve Bellek Hiyerarşisi

Bir öğrencinin sorusu üzerine hoca yazmacın ne olduğunu bellek hiyerarşisi üzerinden yeniden anlattı ve tahtaya bir şekil çizdi (ekrandan, 00:15:00). Şekilde mikroişlemci, önbellek ve ana bellek yan yana gösterildi; önbelleğin bir kısmı mikroişlemcinin içine taşacak biçimde çizildi:

- Mikroişlemcinin içindeki bellek birimleri: yazmaçlar (register).
- Önbellek (cache).
- Ana bellek (main memory, RAM).
- İkincil depolama birimleri: sabit disk, CD vb.

Yazmaçlardan diske doğru gidildikçe bellek kapasitesi artar: diskler terabayt hatta petabayt, RAM'ler 16-64 GB, önbellekler kilobayt ya da megabayt mertebesindedir. Mikroişlemcide ise her biri örneğin 64 bitlik olan, sayısı yüzden az yazmaç bulunur. Ters yönde, yani diske doğru değil yazmaca doğru gidildikçe birim üretim maliyeti artar. Ticari bir ürün ortaya koymak gerektiği için pahalı birimlerden çok sayıda kullanılamaz.

Bu hiyerarşide yazmaç, mikroişlemcinin içinde yer alan, tek tek ve adıyla erişilebilen (adreslenebilen) yüksek hızlı bellek birimidir. Mikroişlemcinin içinde kabaca yazmaçlar, bir kontrol birimi, ALU ve bunlar arasındaki bağlantıyı sağlayan yollar vardır. Assembly dilinde yazmaçlara adlarıyla erişilir.

## 3. Segment ve Offset ile 20 Bitlik Adres

8086'nın yazmaçları 16 bitlik, adres yolu ise 20 bitliktir (ekrandan, 00:25:00). Buradan şu problem doğar: 16 bitlik yazmaçlarla 20 bitlik bir adres nasıl oluşturulur? Intel'in çözümü, veri erişiminde kullanılan yazmaçları segment yazmaçları ve offset yazmaçları diye iki gruba ayırmaktır. İkisi de 16 bitliktir. 20 bitlik fiziksel adres şöyle hesaplanır:

$$\text{fiziksel adres} = \text{segment} \times 10\text{H} + \text{offset}$$

Segment değeri onaltılık yazıldığında 10H ile çarpmak, sonuna bir 0 eklemek demektir.

Segment yazmaçları SS (stack segment), CS (code segment), DS (data segment) ve ES (extra segment) olarak adlandırılır. Önemli bir nokta, her segment yazmacının yalnız belirli offset yazmaçlarıyla çalışmasıdır. Tahtadaki eşleşmeler şöyledir:

| Segment | Offset | Gösterdiği |
|---|---|---|
| SS | BP, SP | yığının en üst adresi |
| CS | IP | bir sonraki adımda çalıştırılacak komutun adresi |
| DS, ES | BX, SI, DI | veri kesimindeki değişkenin adresi |

SS kesinlikle IP ile çalışmaz. DS ve ES ikisi de veri alanının farklı bölgelerini göstermek için kullanılır.

Buradan yazılacak her assembly programının üç parçadan oluşacağı sonucu çıkar (ekrandan, 00:30:00): verilerin tanımlandığı veri kesimi (data segment), yürütülecek kodların bulunduğu kod kesimi (code segment) ve dallanmalarda, fonksiyon çağırmalarda kullanılan yığın kesimi (stack segment).

IP (instruction pointer) bir offset yazmacıdır ve CS ile birlikte sıradaki yürütülecek komutun adresini gösterir. IP mikroişlemci tarafından otomatik güncellenir; örneğin sıradaki komut 3 baytlıksa, komut yürütüldükten sonra IP 3 artırılır.

## 4. Bayraklar

### 4.1 CF

Carry flag, işaretsiz sayılarla yapılan işlemlerde taşma olursa 1 değerini alır.

### 4.2 PF ve eşlik hesabı

Eşlik (parity) hesabının tek (odd) ve çift (even) olmak üzere iki türü vardır. Hoca 8 bitlik bir veri ve onun yanında bir eşlik biti çizdi (ekrandan, 00:30:00).

Veri `1 0 1 0 1 1 1 1` olsun. Verideki 1'lerin sayısı 6'dır.

- Tek eşlikte veri ve eşlik biti birlikte tek sayıda 1 içermelidir. 6 tane 1 olduğu için eşlik biti 1 olur; toplam 7 tane 1 elde edilir.
- Çift eşlikte toplam 1 sayısı çift olmalıdır. Zaten 6 tane 1 olduğu için eşlik biti 0 olur.

Eşlik genellikle seri haberleşmede kullanılır. Gönderen taraf verinin yanında kendi hesapladığı eşlik bitini de gönderir. Alan taraf gelen veriden eşliği yeniden hesaplar ve gelen eşlik bitiyle karşılaştırır. Aynıysa bozulma olmadığı varsayılır; farklıysa veride bozulma olduğu anlaşılır ve veri atılır.

> **Ek bilgi (derste anlatılmadı):** 8086'nın PF bayrağı, işlem sonucunun düşük anlamlı baytında çift sayıda 1 varsa 1, tek sayıda 1 varsa 0 değerini alır.

### 4.3 AF

8086 yerel olarak 8 bitlik ve 16 bitlik işlemleri destekler. Auxiliary flag daha küçük, 4 bitlik gruplar arasında elde oluşup oluşmadığını tutar: örneğin ilk 4 bitlik gruptan ikinci 4 bitlik gruba elde geçip geçmediği. Bu bayrak daha çok BCD işlemleriyle ilgilidir ve o konu geldiğinde yeniden ele alınacaktır.

> **Ders sonrası not:** Hoca AF'yi her 4 bitlik grup arası elde gibi anlattı. AF yalnız en düşük 4 bitten (bit 3'ten bit 4'e) oluşan eldeyi (ya da borcu) gösterir.

### 4.4 ZF ve SF

Zero flag işlem sonucu sıfırsa 1 olur. Sign flag, ikiye tümleyen gösterim kullanıldığı için 8 ya da 16 bitlik sonucun en yüksek anlamlı bitinin kendisidir.

### 4.5 TF, IF ve DF

Trap flag daha çok hata ayıklama amacıyla kullanılır. TF = 1 yapılırsa her komuttan sonra belirli tipte bir kesme oluşur; bu kesmenin içinde yazmaçlar ekranda gösterilebilir. Bu, kodu adım adım çalıştırmaya karşılık gelir.

Interrupt flag 1 ise donanım kesmeleri etkindir: dışarıdaki bir donanımdan gelen kesme istekleri değerlendirilebilir. Direction flag ise daha çok katar (string) işlemlerinde kullanılır ve işlemin düşük adresten yüksek adrese doğru mu (artırarak), yüksek adresten düşük adrese doğru mu (azaltarak) yapılacağını belirler.

### 4.6 OF

CF işaretsiz sayı işlemlerindeki taşmayı gösterirken, overflow flag işaretli sayı işlemlerindeki taşmayı gösterir.

> **Hocanın vurgusu:** CF ve OF bu ders için önemlidir. CF işaretsiz, OF işaretli sayılarda taşmayı tutar; bu çok önemli bir noktadır.

### 4.7 Bu bilgiler neden gerekli?

Hoca bu bilgi düzeyindeki konuların neden önemli olduğunu bir örnekle açıkladı. Komutlarda bellek adresleri köşeli parantez içinde gösterilir ve köşeli parantez içine yalnız belirli yazmaçlar yazılabilir. Bunu bilmeyen biri bellekten okuma yapmak için köşeli parantez içine DX yazmaya çalışabilir; bu hatalı bir komut olur. Assembly komutlarını doğru kullanabilmek için yazmaçların bu özelliklerini bilmek gerekir.

## 5. 32 ve 64 Bitlik x86 Yazmaçları, Gerçek Mod

Ders kapsamındaki 8086 16 bitlik bir mikroişlemcidir. 32 bitlik yazmaçlar 80386'dan itibaren vardır. Bunlar "extended" anlamında E ön ekiyle adlandırılır: EAX, EBX, ECX, EDX gibi. 32 bitlik EAX yazmacının düşük anlamlı 16 bitine AX adıyla erişilir; yüksek anlamlı 16 bitine adıyla erişilemez. AX'in de düşük ve yüksek anlamlı 8 bitlerine AL ve AH olarak erişilir.

32 bitlik mimaride SI ve DI de ESI ve EDI olarak kullanılır; IP yerine EIP (extended instruction pointer) vardır. Ek olarak FS ve GS adlı iki segment yazmacı daha bulunur. Bunlar korumalı (protected) ve sanal (virtual) modla ilgili kısımlarda işlev görür: programın çalıştığı bellek bölgesi yalnız ona ayrıldığı için adres değerleri bir tablodan alınır ve bu tablolara ilişkin satır değerleri FS ve GS'de tutulur.

> **Hocanın vurgusu:** İleride bir assembly kodu ile C kodu arasında veri paylaşımı istenecek. 32 bitlik bir program derlenirken bellek gözlerine köşeli parantez içinde SI ya da BX yazarak değil, ESI ya da EBX gibi 32 bitlik yazmaçlarla erişilmelidir.

64 bitlik Intel mimarisinde genel amaçlı yazmaçların başına R gelir: RAX, RBX, RCX gibi. RAX'in düşük 32 bitine EAX, onun düşük 16 bitine AX, AX'in 8 bitlerine AH ve AL olarak erişilir. 64 bitlik mimaride 8 ek genel amaçlı yazmaç ve çeşitli vektör yazmaçları da vardır.

8086 gerçek modda (real mode) çalışır. Gerçek modda bir program, 8086'nın 1 MB'lık bellek uzayının istediği herhangi bir noktasına erişebilir (ekrandan, 00:40:00).

## 6. Komut Yapısı ve MASM Sözdizimi

Bu haftanın asıl konusu 8086'nın komut yapısıdır. 8086 komut kümesinde her biri bir komut grubunu temsil eden özel kelimeler vardır: ADD (toplama), INC (increment, bir artırma), MOV (veri aktarma) gibi. Komutun ne yapacağını adından anlatan bu kısaltmalara mnemonic denir. Assembly ile yazılmış her program mnemonic'lerden ve operandlardan oluşur. Derste Microsoft Assembler (MASM) kullanılacaktır.

MASM sözdiziminin en genel hali tahtada şöyle yazıldı (ekrandan, 00:45:00):

```text
{ETIKET:} MNEMONIC {{operand1,} operand2} {; yorum}
```

Süslü parantezler isteğe bağlı kısımları gösterir:

- 8086 komutları 0, 1 ya da 2 operand alır. İkinci operand yoksa komut tek operandlıdır; iki operand varsa bunlar virgülle ayrılır. 8086'da 3 operandlı komut yoktur; 8086'nın üst serilerinde ise 3 operandlı komutlar vardır.
- Komutun başında bir etiket (label) olabilir. Etiketten sonra iki nokta üst üste konur. Her zaman gerekmez.
- Noktalı virgülden sonra satırın geri kalanı yorum sayılır.

Etiket kullanımına örnek olarak tahtaya şu kod yazıldı (ekrandan, 00:45:00):

```text
A1: ADD AX, [SI]
    INC SI
    JMP A1
```

Kod yukarıdan gelir, toplama yapar, SI'yi artırır ve tekrar A1'e döner; bu bir sonsuz döngüdür. Tüm parçaları içeren bir satır örneği de şudur: `A1: ADD AX, [SI] ; AX üzerinde toplama` (ekrandan, 00:50:00).

### 6.1 İşlem yönü: sağdan sola

İşlemler sağdan sola tanımlıdır. `ADD AX, BX` komutunda AX birinci, BX ikinci operanddır. AX ile BX toplanır ve sonuç birinci operanda, AX'e yazılır: $AX \leftarrow AX + BX$. BX'in değeri değişmez, çünkü ona bir atama yapılmaz.

### 6.2 Tip uyumu

Operandların tipleri aynı olmalıdır (ya da uygun dönüşümle düzeltilmelidir; bu sonraki bir konudur). `ADD BX, AX` geçerlidir, çünkü ikisi de 16 bitlik yazmaçtır. `ADD AL, BX` derlenmeye çalışılırsa assembler "type mismatch" hatası verir, çünkü AL 8, BX 16 bitliktir (ekrandan, 00:50:00).

Aynı durum değişkenler için de geçerlidir. Veri kesiminde `VAR1 DB 35H` tanımı yapılsın. Burada VAR1 değişkenin adı, DB (define byte) tipi, 35H değeridir. Bu, C'de `char var1 = 0x35;` tanımına benzer. Kodun ilerisinde `MOV AX, VAR1` yazılırsa yine "type mismatch" hatası alınır, çünkü VAR1 8 bitlik bir değişken, AX ise 16 bitlik bir yazmaçtır.

### 6.3 Soru-cevap: neden üçüncü operand gerekmiyor?

**Soru:** MOV ya da ADD yaparken üçüncü bir yazmaç gerekmiyor mu? **Cevap:** Bilgisayar Donanımı dersinde görülen MIPS tarzı sistemlerde komutlar 3 operand alır: `ADD R1, R2, R3` komutunda R1 sonucun yazıldığı, R2 ve R3 işleme giren operandlardır. Bu farklı bir mikroişlemci ailesidir. 8086'da ise işleme giren iki operand vardır ve sonuç birinci operanda yazılır; bu yüzden üçüncü bir operanda gerek yoktur. Bu fark mimariden kaynaklanır.

## 7. Komutlardaki Kısaltmalar ve Bellek Erişimi

Komutların şematik gösterimlerinde kullanılan kısaltmalar slaytta şöyle verildi; hoca yanlarına örnekleri yazdı (ekrandan, 00:55:00):

| Kısaltma | Anlamı | Örnekler |
|---|---|---|
| acc | akümülatör | AL, AX |
| reg | 8/16 bitlik yazmaç | AL, BL, BH, AH, ..., CS, DX, AX, ... |
| regb | 8 bitlik yazmaç | AL, AH, BL, BH, ... |
| regw | 16 bitlik yazmaç | AX, BX, CX, DX, CS, DS, ES, SS |
| sreg | segment (kesim) yazmacı | CS, SS, DS, ES |
| mem | bellek adresi | [100H], [BX], [DI], [SI], [BX+SI], [BX+DI] |
| idata | 8/16 bitlik sabit değer | |
| disp8/disp16 | [-128 ... 0 ... 127] / [-32768 ... 0 ... 32767] | |
| dest/src | hedef/kaynak | |

### 7.1 mem: köşeli parantez ile bellek erişimi

MASM'de köşeli parantez bir bellek erişimini ifade eder: belleğin o numaralı gözündeki içeriğe erişilir. Köşeli parantez içine yazılan şey bir offsettir ve bir segment yazmacıyla birlikte kullanılır. Veri işleminde varsayılan kesim yazmacı DS'dir: DS'nin gösterdiği yerden offset kadar ilerideki bellek gözüne erişilir. Yığın işleminde varsayılan kesim SS'dir.

Köşeli parantez içine bir sabit yazılabilir: `[100H]`, ilgili kesimin 100H offsetindeki veri demektir. BX yazılabilir: kesimin BX kadar ötesindeki veri. Hoca ayrıca DI, SI, BX+SI, BX+DI, SI+DI ve bunların yanına bir sabit eklenmiş hallerinin yazılabileceğini söyledi. Köşeli parantez içinde CX ya da AX yazmak hatadır.

> **Ders sonrası not:** Hoca köşeli parantez içinde `[SI+DI]` ve `[BX+SI+DI+sabit]` yazılabileceğini söyledi. 8086'da bu biçimler geçersizdir: bir adreste en fazla bir taban yazmacı (BX ya da BP) ve en fazla bir indis yazmacı (SI ya da DI) bulunabilir. Geçerli biçimler `[sabit]`, `[BX]`, `[BP]`, `[SI]`, `[DI]`, `[BX+SI]`, `[BX+DI]`, `[BP+SI]`, `[BP+DI]` ve bunların bir sabit eklenmiş halleridir. BP içeren adreslerde varsayılan kesim SS'dir.

### 7.2 idata: sabit değer

Immediate data sabit değerdir. Bellek erişimiyle karışmaması için iki komut karşılaştırıldı:

- `MOV AX, [100H]`: bir bellek işlemidir; AX'e 100H adresinin içeriği atanır.
- `MOV AX, 100H`: bir sabit (immediate) işlemidir; AX'e 100H değeri atanır.

Hoca bunu C ile de karşılaştırdı: dizi adı bir göstericidir; `y = a[10]` başlangıçtan 10 öteki değeri almak, `y = 10` ise doğrudan 10 değerini atamaktır. İlki köşeli parantezli erişime, ikincisi sabit atamaya karşılık gelir.

### 7.3 disp8/disp16: dallanmalarda uzaklık

Etiket örneğindeki `JMP A1` komutu derlenirken assembler A1 etiketini kod içinde arayıp mutlak olarak ona dallanmaz. A1'in adresi (adres 1) ve JMP'nin bulunduğu yerin adresi (adres 2) bellidir; derleme sırasında aralarındaki fark hesaplanıp komuta yazılır (ekrandan, 01:00:00). JMP geride bir yere gidiyorsa bu fark negatiftir, örneğin "JMP -10" yani 10 bayt gerideki komuta git; ileride bir yere gidiyorsa pozitiftir, örneğin "JMP 20". Geri ve ileri dallanma olabildiği için uzaklık (displacement) işaretli sayıdır.

Uzaklık 8 bitlik işaretli sayıya sığıyorsa ($-128 \ldots 127$) hoca bu dallanmayı "near" olarak adlandırdı; 16 bitlik işaretli sayıya sığan ($-32768 \ldots 32767$) dallanmaları ise "far" olarak adlandırdı.

> **Ders sonrası not:** Intel terminolojisinde 8 bitlik uzaklıklı dallanma "short", aynı kesim içinde 16 bitlik uzaklıklı dallanma "near" dallanmadır. "Far" dallanma ise başka bir kesime gider ve CS'yi de değiştirir.

### 7.4 dest/src

`MOV AX, BX` komutunda atama sağdan sola yapıldığı için BX kaynak (source), AX hedef (destination) olarak adlandırılır.

## 8. MOV Komutu

Ara sonrasında veri aktarım komutlarına geçildi. İlk komut MOV'dur (move data). Bir kaynak ve bir hedef olmak üzere iki parametre alır ve kaynaktaki içeriği hedefe kopyalar.

### 8.1 Geçersiz durumlar

**Bellekten belleğe aktarım olmaz.** `MOV [100H], [200H]` geçerli bir komut değildir (ekrandan, 01:25:00). Bellek erişimi köşeli parantezle yapılır ve köşeli parantez içindeki değer bellek adresidir. Bellekten belleğe, G/Ç'den belleğe, bellekten G/Ç'ye ya da G/Ç'den G/Ç'ye doğrudan aktarım yapılamamasının nedeni geçen haftaki veri aktarım tiplerinden gelir: polling, kesme (interrupt) ve DMA. DMA'da mikroişlemci devrede değildir. Diğer iki yöntemde ise veri önce mikroişlemciye okunur, sonra hedefe aktarılır. Yani iki bellek biriminin aynı anda doğrudan haberleştiği bir durum yoktur.

**İki segment yazmacı arasında aktarım olmaz.** `MOV SS, CS` geçersizdir. Ama CS'nin içeriği iki adımda SS'ye aktarılabilir; ara bir geçici (temp) yazmaç kullanılır:

```text
MOV AX, CS
MOV SS, AX
```

**Soru:** Ara yazmaç olarak AL kullanılabilir mi? **Cevap:** Hayır. CS ve SS 16 bitlik yazmaçlardır; tip uyumu için ara yazmacın da 16 bitlik olması gerekir.

**Segment yazmacına sabit atanamaz.** `MOV DS, 100H` geçersizdir. İşlem yine ikiye bölünür: önce sabit bir 16 bitlik genel amaçlı yazmaca (AX ya da BX) yüklenir, sonra segment yazmacına aktarılır:

```text
MOV AX, 100H
MOV DS, AX
```

**Hedef ve kaynak aynı tipte olmalıdır.** `MOV AL, DX` geçersizdir, çünkü DX 16 bitlik, AL 8 bitliktir; assembler "type mismatch" hatası verir. Aynı durum değişkenler için de geçerlidir: veri kesiminde `VAR1 DB 12` tanımlanıp kod kesiminde `MOV AX, VAR1` yazılırsa yine "type mismatch" alınır (ekrandan, 01:30:00).

**Soru:** 12 yazmışız, bu 12 bit değil mi? **Cevap:** 12 burada onluk (decimal) bir değerdir; yanında H yoktur. Onaltılık karşılığı 0CH'dir ve 8 bite sığar. 12H yazılsaydı da (ikilik 0001 0010) yine 8 bite sığardı.

### 8.2 MOV reg, idata

Tahtada dört örnek yazıldı ve geçerlilikleri incelendi (ekrandan, 01:35:00):

```text
MOV CH, 300
MOV AX, 1234H   ; AX <- 1234H
MOV BL, 'A'     ; BL <- 65
MOV DX, -1      ; DX <- FFFFH
MOV AX, 1       ; AX <- 0001H
```

- `MOV DX, -1`: DX'e -1'in ikiye tümleyen karşılığı, yani 16 tane 1 yüklenir: FFFFH.
- `MOV BL, 'A'`: BL'ye A karakterinin ASCII kodu yüklenir: onluk 65 (41H).
- `MOV AX, 1234H`: dört onaltılık basamak 16 bittir, geçerlidir.
- `MOV AX, 1`: değer 8 bite sığsa da geçerlidir; değer 16 bite tamamlanır, önü sıfırlarla doldurulur ve AX = 0001H olur.
- `MOV CH, 300`: geçersizdir. 8 bitlik değerler 0 ile 255 arasındadır; 300 bu aralığın dışındadır (300 = 12CH).

Aynı hata `MOV BL, 100H` için de oluşur. 100 sayısı ilk bakışta 0-255 arasında gibi görünür, ama değer onaltılık verilmiştir: 100H = 256, yani 8 bitten büyüktür. Bir öğrencinin yorumuyla, 8 bitlik bir yazmaca atanan onaltılık değer iki basamaktan fazla olmamalıdır.

### 8.3 MOV mem, idata ve PTR belirteci

`MOV [100H], 12H` komutu ilgili kesimin 100H offsetindeki göze 12H sabitini yazmak ister (ekrandan, 01:40:00). Burada bir belirsizlik vardır.

Önce bir öğrenci her bellek gözünün kapasitesini sordu. Aksi belirtilmedikçe her bellek gözü 8 bittir (1 bayt). Ama bir adrese bir word da yazılabilir. Örneğin 1234H 16 bitlik bir değerdir; 100H'ye yazılırsa, 8086 little endian olduğu için düşük anlamlı bayt 34H düşük adrese (100H), yüksek anlamlı bayt 12H bir sonraki adrese (101H) yazılır.

Asıl belirsizlik başka yerdedir. `MOV AX, 1` komutunda sabit 16 bite tamamlanmıştı, çünkü AX'in 16 bitlik olduğu biliniyordu; `MOV AL, 1` olsaydı AL'ye 01H atanırdı. `MOV [100H], 12H` komutunda ise işlemi belirleyen bir yazmaç yoktur. 12H, 0012H olarak mı (word) yoksa 12H olarak mı (byte) değerlendirilmelidir? Bunun açıkça yazılması gerekir:

```text
MOV WORD PTR [100H], 12H
MOV BYTE PTR [100H], 12H
```

Komut öncesinde 100H ve 101H gözlerinde FFH olsun (ekrandan, 01:45:00):

- `MOV WORD PTR [100H], 12H`: 12H, 16 bite tamamlanır (0012H). Düşük anlamlı bayt 12H, 100H'deki FFH'nin yerine; yüksek anlamlı bayt 00H, 101H'deki FFH'nin yerine yazılır. Sonuç: 100H = 12H, 101H = 00H.
- `MOV BYTE PTR [100H], 12H`: yalnız 100H'deki FFH silinip 12H yazılır. 101H değişmez. Sonuç: 100H = 12H, 101H = FFH.

**Soru:** Buradaki FF değerleri önceden yapılmış bir işlemden mi geliyor? **Cevap:** Evet, daha önceki bir işlemden ya da bellek açıldığında orada bulunan rastgele değerlerden; başlangıç (initial) değerleri olarak düşünülebilir.

**Soru:** Köşeli parantezle yaptığımız bellek erişimi gösterici ile aynı işlem mi? **Cevap:** Evet, aynı işlemdir.

> **Hocanın vurgusu:** WORD PTR ve BYTE PTR ile işlem tipi açıkça belirtilir ve bellekteki yerleşim buna göre değişir. Hoca bunun önemli bir nokta olduğunu söyledi.

### 8.4 MOV reg, reg

`MOV AX, BX` ve `MOV DL, CL` geçerlidir: 16 bitten 16 bite, 8 bitten 8 bite atama yapılır. `MOV AH, CS` geçersizdir, çünkü AH 8 bitlik, segment yazmaçları 16 bitliktir (ekrandan, 01:45:00).

**Soru:** `MOV SI, reg` komutunda reg 8 bitlik mi, 16 bitlik mi olmalı? **Cevap:** SI 16 bitlik olduğu için yalnız AX, BX, DX gibi 16 bitlik bir yazmaç kullanılabilir.

### 8.5 MOV reg, mem ve MOV mem, reg

`MOV BX, [250H]` komutunda tip belirtecine gerek yoktur, çünkü BX kullanıldığı için işlemin 16 bitlik olduğu bellidir.

Komut öncesinde bellek şöyle olsun (ekrandan, 01:50:00): 250H = ABH, 251H = 12H, 252H = 34H.

- `MOV BX, [250H]`: 250H'den başlayan 16 bitlik veri alınır, yani 250H ve 251H. Little endian olduğu için 250H'deki değer düşük, 251H'deki değer yüksek anlamlı bayttır. Sonuç: BX = 12ABH.
- `MOV AL, [250H]`: 250H'den başlayan 1 baytlık değer alınır. Sonuç: AL = ABH.

Ters yön de geçerlidir: `MOV [250H], BX` hem 250H'yi hem 251H'yi günceller; `MOV [250H], AL` yalnız 250H'yi günceller.

### 8.6 Segment yazmacı içeren MOV'lar

Segment yazmacı ile genel amaçlı bir yazmaç arasında iki yönde aktarım yapılabilir. Hoca örnek olarak `MOV CS, SI` yazdı.

> **Ders sonrası not:** CS, MOV komutunda hedef olarak kullanılamaz; CS yalnız uzak dallanma, uzak çağrı, dönüş ve kesmelerle değişir. Örneğin `MOV SI, CS` ya da `MOV DS, SI` geçerlidir, ama `MOV CS, SI` assembler tarafından reddedilir.

Bellekten segment yazmacına ve segment yazmacından belleğe de aktarım yapılabilir. `MOV DS, [20H]` ve `MOV [20H], DS` örnekleri verildi. Segment yazmaçları 16 bitlik olduğu için ikisi de 16 bitlik işlemdir; ikincisinde 20H ve 21H gözleri DS'nin düşük ve yüksek anlamlı baytlarıyla doldurulur.

**Soru:** Bellek gözleri 8 bit mi? **Cevap:** Ders kapsamında varsayılan olarak bir bellek gözünün kapasitesi 1 bayttır.

## 9. LEA Komutu

LEA (load effective address) iki operand alır: birinci operand 16 bitlik bir yazmaç, ikincisi bir bellek adresi ya da (çoğunlukla) bir değişkendir. Verilen değişkenin kendi kesimindeki offset değerini hesaplayıp birinci operanda atar.

### 9.1 Kavram

Bellekte programın üç kesimi (veri, kod, yığın) yerleşmiş olsun. Veri kesiminde tanımlanan değişkenler sırasıyla kesim içinde bir yere yerleşir. LEA, ilgilenilen değişkenin kendi kesiminin başlangıcından ne kadar uzakta (hangi offsette) olduğunu verir. Bu, değişkenin adresini (bir tür göstericisini) vermek gibidir. Büyük boyutlu veriler bayt bayt işlenmek istendiğinde çok kullanışlıdır.

Offset değeri kesimin sonunda bile olabileceği için en kötü durumda FFFFH olabilir, yani 16 bitliktir; bu yüzden atama 16 bitlik bir yazmaca yapılır. LEA ile alınan değer bir adres olduğu ve veriye sonra köşeli parantezle erişileceği için, değerin BX, SI ya da DI gibi köşeli parantez içinde yazılabilen bir yazmaca alınması faydalıdır.

### 9.2 Veri kesiminin belleğe yerleşmesi

Hoca slayttaki gerçek bir veri kesimi tanımını kullandı. Kesimin adı DATASG'dir; segment tanımının başladığı ve bittiği satırlar arasında dört değişken tanımlıdır. Tahtadaki değişkenler şunlardır (ekrandan, 02:10:00):

```text
ASAYISI DW 13
BSAYISI DW 15
GCD     DW ?
DENEME  DW -1
```

Program assembler'dan geçirilip çalıştırılabilir hale getirildiğinde (EXE), çalıştırma anında veri, kod ve yığın kesimleri işletim sistemi tarafından uygun boş alanlara yerleştirilir. Yani DS değeri kod çalışırken belirlenir.

Hoca örnekte DS = 0100H aldı. Kesimin 0000H offseti fiziksel olarak $0100\text{H} \times 10\text{H} + 0000\text{H} = 01000\text{H}$ adresine, 0001H offseti ise $01000\text{H} + 0001\text{H} = 01001\text{H}$ adresine karşılık gelir (ekrandan, 02:20:00). Program yüklenmeden DS belli olmadığı için, değişkenlerin yeri hep kesim başlangıcına göre offset olarak düşünülür.

Yerleşim, word değişkenlerin little endian yazılmasıyla şöyle olur:

| Offset | İçerik | Değişken |
|---|---|---|
| 0000H | 0DH | ASAYISI (düşük bayt) |
| 0001H | 00H | ASAYISI (yüksek bayt) |
| 0002H | 0FH | BSAYISI (düşük bayt) |
| 0003H | 00H | BSAYISI (yüksek bayt) |
| 0004H | ?? | GCD |
| 0005H | ?? | GCD |
| 0006H | FFH | DENEME |
| 0007H | FFH | DENEME |

- ASAYISI: 13 onluk = 0DH. DW 16 bitlik olduğu için 000DH olarak iki göze yazılır: önce 0DH, sonra 00H. 13 bir bayta sığsa da word olarak tanımlandığı için iki göz kaplar.
- BSAYISI: 15 = 000FH; 0FH ve 00H.
- GCD: word tipinde ama başlangıç değeri verilmemiş (`?`). Bu, buradaki gözlerde bellekte ne varsa öyle kalsın demektir; değişkene önce okuma değil yazma yapılacaktır.
- DENEME: -1 word olarak FFFFH; iki göz de FFH.

Veri kesimindeki bu tanımların makine kodu karşılığı yoktur; değerler komut çalıştırılarak yazılmaz.

### 9.3 LEA örneği

Tahtada şu soru soruldu (ekrandan, 02:10:00): aşağıdaki komutlardan sonra BX, SI ve DI ne olur?

```text
LEA BX, ASAYISI   ; BX = ?
LEA SI, BSAYISI   ; SI = ?
LEA DI, DENEME    ; DI = ?
```

- ASAYISI kesimin en başındadır; başlangıçtan uzaklığı 0'dır. BX = 0000H.
- BSAYISI, önce bir word yerleştirildiği için başlangıçtan 2 uzaktadır. SI = 0002H.
- DENEME başlangıçtan 6 uzaktadır. DI = 0006H.

LEA değişkenin değerini saklamaz, yalnız başlangıçtan ne kadar uzakta olduğunu verir. BX'te 13 değil 0, SI'de 15 değil 2 vardır. Bu bir MOV işlemi değildir. `MOV BX, ASAYISI` yazılsaydı (ASAYISI offset olarak 0'da olduğu için `MOV BX, [0]` gibi) BX'e 13 yüklenirdi.

**Soru:** SI bundan sonra bir gösterici gibi mi işlev görüyor? **Cevap:** Evet. C'de bir değişkenin adresini bir göstericiye atayıp gösterici tipini int'ten char'a çevirerek veriye 8 bit 8 bit erişmek gibidir. Sonraki örnekte tam olarak bu yapılır.

### 9.4 Adres üzerinden erişim

Ardından şu komutlar incelendi (ekrandan, 02:20:00):

```text
MOV AL, [BX]
MOV DX, [DI]
MOV AH, [BX+1]
```

- `MOV DX, [DI]`: köşeli parantez bellek erişimidir; varsayılan kesim DS olduğu için DS:DI, yani kesimin 6 offset ötesine gidilir. DX 16 bitlik olduğu için buradan başlayan iki bayt (FFH, FFH) little endian okunur: DX = FFFFH.
- `MOV AL, [BX]`: BX = 0 olduğu için kesimin 0 offsetine gidilir. AL 8 bitlik olduğu için yalnız bir bayt alınır: AL = 0DH. Böylece word olarak tanımlanmış bir değişkenin tek bir baytına erişilmiş olur.
- `MOV AH, [BX+1]`: 1 numaralı offsetteki bayt alınır: AH = 00H.

LEA ile kurulan sabit referansa göre sabit değerler ekleyerek büyük bir veri küçük parçalara bölünüp her birine ayrı ayrı erişilebilir.

**Soru:** SI yerine CX kullanılsa olur muydu? **Cevap:** LEA kısmı olurdu, ama köşeli parantez içinde CX kullanılamayacağı için ikinci kısım, yani adres üzerinden erişim yapılamazdı.

**Soru:** Offsetler belli; sabit sayı yazsak olmaz mı? **Cevap:** Yazılabilir, ama kod statikleşir. Değişkenlerin başına sonradan örneğin `XSAYISI DB 2` eklenirse elle yapılan bütün hesap kayar. Kodun bakımı ve iyileştirilmesi açısından LEA kullanmak anlamlıdır.

**Soru:** Veri kesimindeki değerler komut çalıştırmadan belleğe nasıl yazılıyor? **Cevap:** Kod assembler'dan geçerken veri kesimi için bu karşılıklar hazırlanır; işletim sistemi DS'yi nereye ayarladıysa değerler oraya doğrudan, birebir yazılır. Kod kesimindeki komutların da makine kodu karşılıkları hesaplanıp tek tek yazılır. Hoca bunu ROM programlamaya benzetti: özel bir cihaz çipi programlama moduna geçirir, adres uçlarına hangi göze yazılacaksa o adres, veri uçlarına ilgili değer verilir. Diskten RAM'e kopyalanıp çalıştırılan programlar için de benzer bir süreç geçerlidir.

> **Hocanın vurgusu:** LEA önemli bir konudur. LEA değişkenin değerini değil, kendi kesimi içindeki offsetini verir.

## 10. LDS, LES, XCHG ve XLAT

### 10.1 LDS

LEA'da ilgilenilen değişken zaten kullanılan veri kesimindeydi; DS değişmiyordu ve başlangıçtan uzaklığı almak yeterliydi. Bir kesimin offseti 0 ile FFFFH arasında değiştirilerek yalnız o kesimin içinde gezilebilir. Erişilmek istenen veri çok uzaktaki, başka bir kesimdeki bir veriyse DS de o kesimin başlangıcını gösterecek biçimde güncellenmeli ve verinin bu başlangıca göre offseti de verilmelidir. LDS ve LES'in çıkış mantığı budur.

LDS, verilen adresteki içeriği (word) bir yazmaca, ondan sonra gelen word'ü de DS'ye atar. Örnek (ekrandan, 02:30:00):

```text
UZAK_OFF DW 1234H
UZAK_SEG DW 0ABCDH
...
LDS BX, UZAK_OFF   ; BX <- 1234H, DS <- ABCDH
MOV AL, [BX]       ; ABCDH:BX
```

Amaç ABCDH kesiminin 1234H offsetindeki veriye erişmektir. Program normalde DS = 100H civarında çalışırken, LDS'den sonra DS = ABCDH olur; `MOV AL, [BX]` ABCDH kesiminin 1234H offsetindeki baytı AL'ye okur. Fiziksel adres $\text{ABCD0H} + 1234\text{H} = \text{ACF04H}$ olur (ara adım eklendi).

> **Hocanın vurgusu:** Tanımlanan sabitler harfle başlıyorsa, assembler hata vermesin diye başına 0 konmalıdır (`0ABCDH`).

### 10.2 LES

LES de aynı biçimde çalışır: verilen adresteki değeri bir offset yazmacına, sonraki word'ü ise ES'ye atar. Tek fark DS yerine ES kullanılmasıdır. İkisi birlikte, örneğin bir katar (dizi) işleminde uzak bir kaynaktan uzak bir hedefe veri aktarırken kullanılabilir: biri LDS ile, diğeri LES ile belirtilir.

### 10.3 XCHG

XCHG (exchange) takas (swap) işlemidir; iki operandın yerini değiştirir. İki yazmaç arasında çalışabilir: `XCHG AX, BX` geçerlidir, `XCHG AL, BX` ise tip uyumsuzluğu nedeniyle geçersizdir. Bellek ile yazmaç arasında da iki yönde takas yapılabilir.

### 10.4 XLAT

XLAT ve XLATB (translate byte) aynı anlama gelir. Bellekte bir arama tablosu (lookup table) olduğunu düşünelim. BX tablonun başlangıç adresini, AL ise tablodaki ilgili satırı (indisi) gösterir. XLAT operand almaz; çalıştırılmadan önce BX ve AL uygun değerlerle doldurulmalıdır. İşlevsel olarak DS kesiminin BX+AL offsetindeki değeri AL'ye almak gibidir. Ama `[BX+AL]` bir bellek adreslemesi olarak yazılamaz; BX+AL toplamını mikroişlemci kendisi hesaplar.

## 11. Aritmetik Komutlar

Aritmetik komutlar slaytta şöyle listelendi; hoca yanlarına açıklamalar yazdı (ekrandan, 02:35:00):

- ADD: toplama. `ADD AX, BX` → $AX \leftarrow AX + BX$.
- ADC (add with carry): eldeli toplama. `ADC AX, BX` → $AX \leftarrow AX + BX + CF$. CF 1 bitlik bir değerdir; önceki işlemde elde oluşmuşsa 1, oluşmamışsa 0 eklenir.
- SUB: çıkarma, ikiye tümleyen aritmetikle yapılır. `SUB AX, BX` → $AX + (-BX)$.
- SBB (subtract with borrow): borçlu çıkarma.
- INC ve DEC: 1 artırma ve 1 azaltma.
- NEG: verilen operandın ikiye tümleyen negatifini hesaplar.
- CMP: SUB ile aynı işlemi yapar ama sonucu saklamaz, yalnız bayrakları günceller.
- MUL, IMUL (işaretli çarpma), DIV (işaretsiz bölme), IDIV (işaretli bölme).

Borç kavramı onluk çıkarmayla açıklandı: en düşük basamakta 5'ten 9 çıkmıyorsa bir üst basamaktan değer alınır, 5 sanki 15 gibi değerlendirilir ve $15 - 9 = 6$ kalır; borç alındığı için üst basamak bir azalır, orada da çıkarma yapılamazsa yine bir üst basamaktan borç alınır. Bir üst basamaktan borç alınıp alınmadığını tutan şeye borrow denir. CF toplama işlemlerinde elde (carry), çıkarma işlemlerinde borç (borrow) görevi görür.

<!-- BELİRSİZ: Onluk çıkarma örneğindeki sayıların tamamı altyazıdan ve karelerden okunamadı; yalnız 15 - 9 = 6 ve 11 - 7 = 4 adımları duyuluyor. -->

### 11.1 ADD ve ADC'nin biçimleri

ADD'nin iki operandı vardır (hedef ve kaynak); toplama sonucu birinci operanda yazılır. Biçimleri:

- Yazmaç ve sabit: `ADD AX, 1` geçerlidir. `ADD BL, 300` 8 bitlik bir işlem olduğu ve 300 8 bite sığmadığı için hatalıdır.
- Bellek ve sabit: `ADD [100H], 12H` belirsizdir; word mu byte mı yapılacağı bilinmez. `ADD WORD PTR [100H], 12H` ya da `ADD BYTE PTR [100H], 12H` yazılmalıdır.
- İki yazmaç: `ADD DX, AX`.
- Yazmaç ve bellek, bellek ve yazmaç: örneğin `ADD [100H], AX`; AX kullanıldığı için bir word işlemi olduğu bellidir.

ADC'nin çalışma biçimleri de aynıdır; tek fark, toplamaya 1 bitlik CF değerinin de eklenmesidir. Bellek ile sabit kullanılan biçimde yine WORD PTR ya da BYTE PTR gerekir.

## 12. Örnek: 32 Bitlik İki Sayının Toplanması

8086 8 bitlik operand alırsa 8 bitlik, 16 bitlik operand alırsa 16 bitlik toplamayı donanımsal olarak yapar. 32 bitlik değişkenleri toplamak için donanım desteği yoktur; mevcut komutlarla bir "kütüphane" oluşturulmalıdır. Hoca bunu o ana kadar görülen veri aktarım ve aritmetik komutlarla yapılabilecek bir örnekle gösterdi.

### 12.1 Tanımlar ve bellek yerleşimi

Değişkenler şöyle tanımlandı (ekrandan, 02:50:00):

```text
VAR1 DD 6789ABCDH
VAR2 DD ABCD1234H
VAR3 DQ 0
```

DD (define double word) 32 bitlik, DQ (define quad word) 64 bitlik değişken tanımlar. VAR1 sekiz onaltılık basamaktan oluşur, yani 32 bitliktir.

Ara soru: iki 16 bitlik sayının toplamı kaç bite sığar? Bir öğrenci 17 dedi. 17 bitlik bir değişken olmadığı için 32 bit kullanılır. Benzer şekilde iki 32 bitlik sayının toplamı 33 bit olabilir; bu yüzden sonuç için 64 bitlik bir değişken (VAR3) tanımlandı ve 0 ile başlatıldı.

Adresler yukarıdan aşağı doğru artacak şekilde bellek yerleşimi:

| Değişken | Baytlar (düşük adresten yükseğe) |
|---|---|
| VAR1 | CDH, ABH, 89H, 67H |
| VAR2 | 34H, 12H, CDH, ABH |
| VAR3 | 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H |

Soru: 32 bitlik VAR1 ve VAR2 değişkenlerini toplayarak sonucu 64 bitlik VAR3 değişkenine atayan kodu yazınız.

### 12.2 Çözümün kurulması

Bir öğrenci sayıları bayt bayt toplamayı önerdi; bu doğru bir yoldur. Hoca daha kısa olduğu için word'ler üzerinden gitmeyi seçti: iki sayının düşük anlamlı 16 bitleri toplanır, buradan gelen elde yüksek anlamlı 16 bitlerin toplamına katılır, oradan da elde çıkarsa o da tutulur ve 33 bite kadar çıkabilen sonuç 64 bitlik değişkene yazılır.

1. Büyük bir verinin parçalarına erişmeyi sağlayan komut LEA'dır. Üç değişkenin başlangıç adresleri, veri kesiminde köşeli parantez içinde kullanılabilen üç yazmaca alınır: `LEA BX, VAR3`, `LEA SI, VAR1`, `LEA DI, VAR2`.
2. VAR1'in düşük word'ü: SI zaten başlangıcı gösterir; adres yukarı doğru arttığı için bu adresten bir word okunursa iki bayt birlikte alınır. `MOV AX, [SI]` → AX = ABCDH.
3. VAR1'in yüksek word'ü: `MOV DX, [SI+2]`. Bu her 32 bitlik sayı için geçerlidir.
4. Düşük word'lerin toplamı: iki bellek operandı aynı komutta kullanılamayacağı için biri AX'e alınmıştı; ikincisi için buna gerek yoktur. `ADD AX, [DI]` → $AX = \text{ABCDH} + 1234\text{H}$. Bu toplamdan elde oluşursa CF'de tutulur; mikroişlemci bunu otomatik ayarlar.
5. Yüksek word'lerin toplamı ve elde: `ADC DX, [DI+2]` → $DX = CF + \text{VAR1 yüksek} + \text{VAR2 yüksek}$.
6. Sonucun yazılması: `MOV [BX], AX` ve `MOV [BX+2], DX`.
7. Son elde: yüksek word'lerin toplamından da elde çıkabilir; bu 32 bitlik toplamanın eldesidir ve bir bayta sığar. VAR3'ün 4 numaralı baytına eklenir. İçerik 0 ile başlatıldığı için 0 ile eldeli toplama yapılır. Bellek ile sabit toplandığı için tip belirtilmelidir: `ADC BYTE PTR [BX+4], 0`.

Tahtadaki tam kod (ekrandan, 03:10:00):

```text
LEA BX, VAR3
LEA SI, VAR1
LEA DI, VAR2
MOV AX, [SI]           ; AX <- ABCDH
MOV DX, [SI+2]         ; DX <- VAR1 yüksek word
ADD AX, [DI]           ; AX <- ABCDH + 1234H
ADC DX, [DI+2]         ; DX <- CF + VAR1 yüksek + VAR2 yüksek
MOV [BX], AX
MOV [BX+2], DX
ADC BYTE PTR [BX+4], 0
```

### 12.3 Adım adım sonuç

Hesaplar python ile kontrol edildi (assembler ya da emülatör kurulu olmadığı için kod çalıştırılmadı):

- $\text{ABCDH} + 1234\text{H} = \text{BE01H}$; 16 bite sığar, CF = 0. AX = BE01H.
- $6789\text{H} + \text{ABCDH} + 0 = 11356\text{H}$; 16 bite sığmaz. DX = 1356H, CF = 1.
- `MOV [BX], AX` ve `MOV [BX+2], DX` CF'yi değiştirmez.
- `ADC BYTE PTR [BX+4], 0`: $00\text{H} + 0 + 1 = 01\text{H}$.
- VAR3 = 000000011356BE01H, yani $6789\text{ABCDH} + \text{ABCD1234H} = 1\,1356\,\text{BE01H}$. Bellekte VAR3'ün baytları: `01 BE 56 13 01 00 00 00`.

Derste de bu toplamada düşük word'lerden elde oluşmadığı söylendi.

### 12.4 Sorular

**Soru:** AX'teki toplamada neden ADC kullanılmadı? **Cevap:** En düşük anlamlı word'ler toplanıyor; onlara dışarıdan bir elde gelemez. En düşük anlamlı bayt ya da double word toplanırken de durum aynıdır, ADC'ye gerek yoktur.

**Soru:** ADC iki operand alıyor; son eldeyi aktarmak için sıfırla bir şey toplasak olur mu? **Cevap:** Evet, aranan cevap budur: `ADC BYTE PTR [BX+4], 0`.

**Soru:** ADC'den sonra MOV komutları çalışıyor; elde bozulmaz mı? **Cevap:** CF, AX ya da BX gibi ayrı bir yazmaç olan bayrak yazmacının bit olarak adreslenebilen bir gözüdür. Veri aktarım komutları bayrakları etkilemez. Bu yüzden ADC'de oluşan elde iki MOV'dan sonra korunur. Aritmetik işlemler ise bayrakları etkiler; araya MOV'lardan önce bir aritmetik işlem girseydi yüksek word'lerin toplamından gelen elde bozulabilirdi.

> **Hocanın vurgusu:** Yazılan kod beklenen sonucu vermiyorsa ve işlem CF ile ilgiliyse, arada CF'yi bozan bir aritmetik komut olabilir. O komutun yeri uygun biçimde değiştirilince kod çalışır hale gelebilir; bu tür durumlarda geriye doğru hata ayıklamak gerekir.

**Soru:** 64 bitlik sonuç nasıl okunur? **Cevap:** Sonuç bellekte peş peşe 64 bitlik bir veri olarak durur. İşleme sokmak için 8 ya da 16 bitlik parçaları tek tek okunup, bu örnekteki kütüphanede olduğu gibi işlenmelidir.

Daha pratik yol, verinin bayt sayısı kadar dönen bir döngüyle her seferinde bir sonraki adrese giderek toplamaktır. Döngüler henüz görülmediği için örnek word'ler üzerinden yapıldı.

Hoca son olarak okunabilirlik için bütün komutların, yazmaçların ve değişkenlerin büyük harfle yazılmasını istedi; assembler büyük/küçük harfe duyarlı değildir. Kodun MASM'de çalıştırılması için veri, kod ve yığın kesimlerinin tanımlanması gerektiği, ileride satır satır çalıştırma için DEBUG aracının kullanılacağı (ama DEBUG'da değişken tanımlanamadığı) belirtildi.

## 13. SUB, SBB, INC, DEC, NEG ve CMP

### 13.1 SUB ve SBB

SUB (subtraction) ve SBB (subtract with borrow), ADD ve ADC gibi çalışır (ekrandan, 03:15:00). `SUB dest, src` → $dest \leftarrow dest - src$; biçimleri `SUB reg, idata`, `SUB mem, idata` (PTR gerekli), `SUB reg, reg`, `SUB reg, mem`, `SUB mem, reg`. SUB borcu dikkate almadan, SBB ise borç değerini de dikkate alarak işlem yapar; ikisi de ikiye tümleyen aritmetikle çalışır. 32 bitlik toplama kütüphanesi gibi, 32 bitlik iki sayıyı çıkarmak için de düşük word'de SUB, yüksek word'de SBB kullanılır ve 32 biti aşan durum ayrıca kontrol edilir.

### 13.2 INC ve DEC

INC tek operand alır, operandı 1 artırıp aynı operanda yazar. 8 ya da 16 bitlik bir yazmaç üzerinde kullanılabilir. Bellek adresiyle kullanılıyorsa işlem tipi açıkça belirtilmelidir.

Başlangıçta 100H = FFH ve 101H = 00H olsun. `INC [100H]` tip belirtilmediği için hata verir. Bunun yerine:

- `INC WORD PTR [100H]`: 100H'den başlayan word (00FFH) 1 artırılır: 0100H. Düşük bayt 00H 100H'ye, yüksek bayt 01H 101H'ye yazılır.
- `INC BYTE PTR [100H]`: yalnız 100H'deki bayt artırılır: FFH + 1 = 100H, ama 8 bitlik kısım 00H'dir. 101H değişmez.

Hoca word durumunda CF'nin 0, byte durumunda ise 8 bitte taşma olduğu için CF'nin 1 olduğunu söyledi.

> **Ders sonrası not:** INC ve DEC komutları CF'yi etkilemez (diğer aritmetik bayrakları etkiler). `INC BYTE PTR [100H]` sonrasında 100H = 00H ve ZF = 1 olur, CF ise komuttan önceki değerini korur. Taşmanın CF ile izlenmesi gerekiyorsa `ADD BYTE PTR [100H], 1` kullanılır.

DEC benzer biçimde operandı 1 azaltır; yazmaç ya da bellek üzerinde çalışır, bellek kullanılıyorsa PTR gerekir.

### 13.3 NEG

NEG verilen operandın eksi değerini ikiye tümleyen aritmetikle hesaplar.

### 13.4 CMP

CMP (compare) temelde SUB ile aynı işlemi yapar: $dest - src$. SUB'da sonuç saklanır; CMP'de saklanmaz, yalnız bayraklar etkilenir (ekrandan, 03:20:00). CMP'nin kullanım amacı, sonraki adımdaki koşullu dallanma komutları için bayrak koşullarını oluşturmaktır: işaretli ve işaretsiz sayılar açısından $dest > src$, $dest \geq src$, $dest = src$, $dest \leq src$, $dest < src$ gibi sorulara doğru/yanlış cevap verecek koşullar.

Çarpma ve bölme komutları (MUL, IMUL, DIV, IDIV) bir sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): `1 0 1 0 1 1 1 1` verisi için tek (odd) ve çift (even) eşlik biti nedir?

> **Çözüm:** Veride 6 tane 1 vardır. Tek eşlikte toplam 1 sayısı tek olmalıdır: eşlik biti 1. Çift eşlikte toplam çift olmalıdır: eşlik biti 0.

**Soru 2** (ekrandan, 01:25:00): `MOV [100H], [200H]` neden geçerli bir komut değildir?

> **Çözüm:** İki bellek operandı arasında doğrudan aktarım yoktur. Veri her zaman önce mikroişlemciye okunur, sonra hedefe yazılır; iki bellek birimi doğrudan haberleşmez.

**Soru 3** (derste sözlü, 01:26:36): `MOV SS, CS` geçersizdir. CS'nin içeriği SS'ye nasıl aktarılır? Ara yazmaç olarak AL kullanılabilir mi?

> **Çözüm:** `MOV AX, CS` / `MOV SS, AX`. AL kullanılamaz, çünkü CS ve SS 16 bitliktir ve tip uyumu gerekir.

**Soru 4** (ekrandan, 01:35:00): Aşağıdaki komutların geçerliliğini ve sonuçlarını bulunuz: `MOV CH, 300`, `MOV AX, 1234H`, `MOV BL, 'A'`, `MOV DX, -1`, `MOV AX, 1`.

> **Çözüm:** `MOV CH, 300` geçersizdir (300 = 12CH, 8 bite sığmaz). AX = 1234H. BL = 65 (41H). DX = FFFFH. AX = 0001H.

**Soru 5** (ekrandan, 01:40:00): `MOV [100H], 12H` komutunda belirsizlik nedir? 100H ve 101H başlangıçta FFH ise WORD PTR ve BYTE PTR durumlarında bellek ne olur?

> **Çözüm:** İşlemin word mü byte mı olduğu belli değildir. `MOV WORD PTR [100H], 12H`: 100H = 12H, 101H = 00H. `MOV BYTE PTR [100H], 12H`: 100H = 12H, 101H = FFH.

**Soru 6** (ekrandan, 01:45:00): `MOV AX, BX`, `MOV DL, CL`, `MOV AH, CS` komutlarından hangileri geçerlidir?

> **Çözüm:** İlk ikisi geçerlidir. `MOV AH, CS` geçersizdir, çünkü AH 8, CS 16 bitliktir.

**Soru 7** (ekrandan, 01:50:00): 250H = ABH, 251H = 12H, 252H = 34H iken `MOV BX, [250H]` ve `MOV AL, [250H]` sonrasında BX ve AL ne olur? İlk komutta PTR gerekir mi?

> **Çözüm:** PTR gerekmez, çünkü BX işlemin 16 bitlik olduğunu belirtir. Little endian: BX = 12ABH. AL = ABH.

**Soru 8** (ekrandan, 02:10:00 ve 02:20:00): `ASAYISI DW 13`, `BSAYISI DW 15`, `GCD DW ?`, `DENEME DW -1` tanımları için `LEA BX, ASAYISI`, `LEA SI, BSAYISI`, `LEA DI, DENEME` komutlarından sonra BX, SI ve DI nedir? Ardından `MOV DX, [DI]`, `MOV AL, [BX]` ve `MOV AH, [BX+1]` ne yükler?

> **Çözüm:** BX = 0000H, SI = 0002H, DI = 0006H. DX = FFFFH, AL = 0DH, AH = 00H.

**Soru 9** (ekrandan, 02:30:00): `UZAK_OFF DW 1234H` ve `UZAK_SEG DW 0ABCDH` için `LDS BX, UZAK_OFF` ne yapar ve ardından `MOV AL, [BX]` hangi adresi okur?

> **Çözüm:** BX = 1234H, DS = ABCDH. AL, ABCDH:1234H adresindeki baytı alır (fiziksel adres ACF04H).

**Soru 10** (derste sözlü, 02:43:46): İki tane 16 bitlik sayının toplamı kaç bite sığar?

> **Çözüm:** 17 bite. Benzer şekilde iki 32 bitlik sayının toplamı 33 bite sığar.

**Soru 11** (ekrandan, 02:50:00): `VAR1 DD 6789ABCDH`, `VAR2 DD ABCD1234H`, `VAR3 DQ 0` tanımları için, 32 bitlik VAR1 ve VAR2 değişkenlerini toplayarak sonucu 64 bitlik VAR3 değişkenine atayan kodu yazınız.

> **Çözüm:** Bölüm 12'deki kod (ekrandan, 03:10:00). Sonuç VAR3 = 000000011356BE01H; bellekte `01 BE 56 13 01 00 00 00`.

**Soru 12** (derste sözlü, 03:08:40): 32 bitlik toplama kodunda ADC'den sonra MOV komutları çalıştırılıyor. CF neden bozulmuyor?

> **Çözüm:** Veri aktarım komutları bayrakları etkilemez. Araya aritmetik bir komut girseydi CF bozulabilirdi.

## Dersin Toparlaması

Bu derste önce 8086 yazmaçları, bellek hiyerarşisi, segment-offset ile 20 bitlik adres oluşturma ve bayraklar tekrar edildi; 32 ve 64 bitlik x86 yazmaçlarının adlandırılması ve gerçek mod kısaca anlatıldı. Ardından 8086 komut yapısı, MASM sözdizimi ve komut tanımlarında kullanılan kısaltmalar görüldü. Veri aktarım komutlarından MOV, LEA, LDS, LES, XCHG ve XLAT işlendi; aritmetik komutlardan ADD, ADC, SUB, SBB, INC, DEC, NEG ve CMP tanıtıldı. Bütün bu konuların ortak noktası tip uyumu, köşeli parantezle bellek erişimi, little endian yerleşim ve bazı operandların gizli (örtük) verilmesidir.

Uygulama olarak 32 bitlik iki sayının yalnız 16 bitlik komutlarla toplanması yapıldı; bu örnekte LEA ile adres alma, ADD ile ADC arasındaki fark ve veri aktarım komutlarının bayrakları etkilememesi bir arada kullanıldı. Bir sonraki derste aritmetik komutlardan çarpma ve bölme komutlarıyla (MUL, IMUL, DIV, IDIV) devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
