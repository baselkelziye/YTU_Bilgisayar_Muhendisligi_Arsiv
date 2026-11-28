# Ders 24 Genişletilmiş Notu: Kesmeler, Kesme Vektör Tablosu ve 8259A

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Polling ve kesme mantığının tekrarı
- 2. Kesme kaynakları
- 3. Kesme bayrakları ve bayrak komutları
- 4. IRET komutu
- 5. Kesme vektör tablosu
- 6. Kesme işlemi sırasında işlemcinin yaptıkları
- 7. Örnek: sıfıra bölme kesme alt programını değiştirme
- 8. Donanımsal kesmeler: NMI ve INTR
- 9. Elle kesme vektörü üretme ve önceliklendirme
- 10. 8259A programlanabilir kesme denetleyicisi
- 11. Örnek: 8259 ile düğmeye basma sayısını sayma
- Örnek Sorular
- Dersin Toparlaması

## 1. Polling ve kesme mantığının tekrarı

Ders, önceki haftada başlanan kesme konusunun devamıdır. Önce iki veri alışverişi yaklaşımı hatırlatılır. Yoklama (polling) mantığında işlemci yürüttüğü işi sürekli keserek çevre biriminin durumunu kontrol etmek zorundadır. Kesme tabanlı yaklaşımda ise işlemci kendi işine devam eder; çevre biriminden bir uyarı (tetikleme) gelince kesme alt programına gider, onu yürütür ve kaldığı yere döner.

## 2. Kesme kaynakları

Slaytta kesme kaynakları şöyle özetlenir (ekrandan, 00:05:00):

- Yazılımsal olarak: `INT`, `INTO`, `INT 3`
- Donanımsal olarak: INTR, NMI
  - Donanım kesmesi ile ilgili acknowledge: $\overline{INTA}$
- Kesme ile ilgili bayraklar: IF, TF
- Kesme ile ilgili dönüş komutu: `IRET`

### 2.1 Yazılımsal kesmeler

Yazılımsal kesmeler iki başlıkta incelenir.

Birincisi, kesmenin doğrudan bir komutla tetiklenmesidir. `INT` komutundan sonra 8 bitlik bir immediate değer verilir. Bu değer 00H ile FFH arasında olabileceği için toplam 256 kesme tipi vardır. 8086 sisteminde zaten 256 farklı kesme tipi tanımlanabilir. Aynı kesme tipi farklı yollarla da çağrılabilir: hem `INT` komutuyla hem bir donanım kesmesi olarak hem de otomatik tetiklenen bir kesme olarak.

İkincisi, doğrudan bir `INT` komutu kullanılmadan, yürütülen işlemin sonucu olarak oluşan kesmelerdir:

- **Sıfıra bölme (divide by zero):** bir sayı sıfıra bölündüğünde tip 0 kesmesi oluşur. Burada kesme komutu çalıştırılmamıştır, ama bazı komutların yürütülmesi sırasında böyle bir durumla karşılaşılabilir.
- **Bölmede sonucun sığmaması:** hoca örnek olarak DX:AX = FFFF0000H ve BX = 1 iken `DIV BX` komutunu verdi. Bölüm AX'e, yani 16 bitlik bir yazmaca yazılacaktır, ama FFFF0000H 16 bite sığmaz.
- **Tek adım:** TF (trap flag) 1 yapılırsa her komut yürütüldüğünde tip 1 kesmesi oluşur.
- **Breakpoint:** tek bir kesme noktası (single breakpoint) konduysa tip 3 kesmesi oluşur.
- **Taşma:** taşma (overflow) durumunda tip 4 kesmesi oluşur.

> **Ders sonrası not:** Hoca `DIV BX` örneğinde bölümün sığmamasıyla bir "overflow kesmesi" oluşabileceğini söyledi. 8086'da bölümün hedef yazmaca sığmaması tip 4 kesmesini değil, sıfıra bölmeyle aynı tip 0 (divide error) kesmesini oluşturur. Tip 4, OF=1 iken `INTO` komutu çalıştırılınca oluşur.

### 2.2 Donanımsal kesmeler

Donanımsal kesmeler, işlemcinin fiziki uçlarına karşılık gelen kesme kaynaklarıdır. İşlemcide kesme isteği için iki giriş ucu vardır: INTR (interrupt request) ve NMI (non-maskable interrupt).

- **NMI** adı üzerinde maskelenemez. Ne olursa olsun değerlendirilir. Bu yüzden kritik durumlarla ilişkilendirilir: sistem açıldı ama elektriksel seviye istenen kararlı değere ulaşmadıysa, ya da açılışta BIOS birimleri kontrol ederken bellek yoksa, eksikse veya çalışmıyorsa NMI ile sistem güvenli biçimde kapatılabilir. NMI'dan gelen kesme otomatik olarak tip 2'dir.
- **INTR** maskelenebilir: IF bayrağı 0 ise INTR ucuna gelen istekler değerlendirilmez.

Üçüncü bir kesme ucu daha vardır: $\overline{INTA}$ (interrupt acknowledge). Yazılımsal kesmede tipi `INT`'ten sonraki 8 bitlik değer belirler, bazı kesmelerin de tipi sabittir. INTR'den gelen bir isteğin tipi ise şöyle belirlenir: Bir çevre birimi INTR ucundan istekte bulunur. İşlemci o sırada bir komutun ortasında olabilir (örneğin dört saat darbesinde biten bir komutun ikinci darbesinde). Komutu bitirir ve kesmeyi değerlendirmeye uygunsa $\overline{INTA}$ ucundan çevre birimine 0 gönderir. Bunu alan çevre birimi istediği kesmenin tipini D0-D7 veri uçlarından 8 bitlik bir değer olarak gönderir. Bu değer, `INT` komutundan sonra verilen immediate değer gibi kesme tipini belirler.

## 3. Kesme bayrakları ve bayrak komutları

Slayttaki bilgiler şunlardır (ekrandan, 00:25:00):

- INTR ucu sadece IF=1 ise kesme oluşturabilir.
- TF=1 ise her komut işlendikten sonra single-step kesmesi oluşur (debug amaçlı).
- `STI`: set interrupt flag, `CLI`: clear interrupt flag; TF için özel komut yok.

Bayrak yazmacının düzeni slayttaki şekle göre şöyledir:

| Bit | 15-12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Bayrak | - | O | D | I | T | S | Z | - | A | - | P | - | C |

TF'nin kullanım amacı adım adım hata ayıklamadır. Ana programda bir komut yürütülür, tip 1 kesme alt programına gidilir. Bu alt programda örneğin bütün yazmaç değerleri ekranda gösterilip bir sonraki komuta dönülebilir. Böylece komutlar bir tuşa basılarak adım adım yürütülür ve her komuttan sonra sonuç görülür.

> **Ders sonrası not:** Hoca IF'yi değiştiren komutları söylerken "STI ve CLC" dedi; slaytta da yazdığı gibi doğrusu `STI` ve `CLI`'dır. `CLC` carry bayrağını sıfırlar.

### 3.1 Özel komutu olan bayraklar

Hoca hangi bayraklar için özel komut olduğunu sordu. Bir öğrenci carry bayrağını söyledi. Hoca bunları slayta yazarak tamamladı (ekrandan, 00:25:00):

- CF: `CLC` (clear carry flag), `STC` (set carry flag), `CMC` (complement carry flag; carry'yi tersler)
- DF: `CLD` (clear direction flag), `STD` (set direction flag). DF dizi işlemlerinin artan ya da azalan adreslere doğru gideceğini belirler.
- IF: `CLI`, `STI`

### 3.2 LAHF ve SAHF

Bayraklarla ilgili iki komut daha vardır (ekrandan, 00:30:00):

- `LAHF`: AH ← FLAG(s, z, ?, a, ?, p, ?, c)
- `SAHF`: FLAG(s, z, ?, a, ?, p, ?, c) ← AH

16 bitlik bayrak yazmacından 5 anlamlı bit alınır, diğerleri önemsiz (don't care) kabul edilir. AH'nin bit 0'ı CF'ye, bit 2'si PF'ye, bit 4'ü AF'ye, bit 6'sı ZF'ye, bit 7'si SF'ye karşılık gelir. Böylece özel komutu olan CF, IF ve DF dışında, `LAHF`/`SAHF` ile CF, PF, AF, ZF ve SF de değiştirilebilir. Derste bunun üzerine sorular soruldu (bkz. Örnek Sorular 1 ve 2).

### 3.3 TF'yi 1 yapmak

Geriye TF ve OF kalır. OF'yi elle 1 yapmak pek istenmez, ama TF'yi 1 yapmak gereken durumlar vardır. TF'nin özel komutu yoktur ve `LAHF`/`SAHF` da TF'yi kapsamaz. Bu yüzden yığın ve bayrak komutları birlikte kullanılır: `PUSHF` ile bayrak yazmacı yığına atılır, yığının üstündeki 16 bitlik değerin 8 numaralı biti 1 yapılır ve `POPF` ile geri yüklenir. Çözüm Örnek Sorular 3'te verilmiştir.

## 4. IRET komutu

Near tipinde bir alt yordam çağrıldığında yığına yalnız IP (offset) atılır, dönüş `RET` ile yapılır. `CALL FAR PTR` ile far tipinde bir alt yordam çağrıldığında yığına hem segment hem offset atılır. Dönüş `RETF` ile yapılır; bu komut yığından offset ve segmenti çekip sırasıyla IP ve CS'ye yükler.

Kesmede durum farklıdır. Kesme alt programına dallanırken yığına önce bayrak yazmacı, sonra segment (CS), sonra offset (IP) atılır. Kesme alt programından dönüş mutlaka `IRET` (interrupt return) ile yapılır. `IRET` yığının en üstündeki değeri IP'ye, sıradakini CS'ye, sıradakini de bayrak yazmacına yazar. `RET`, `RETF` ve `IRET` arasındaki temel fark budur.

## 5. Kesme vektör tablosu

Slayttaki tanım şudur (ekrandan, 00:15:00): Kesme oluştuğunda mevcut CS:IP ile gösterilen kodun yürütülmesi bırakılarak, kesmeye ilişkin fonksiyonun yer aldığı kesim ve offset değerindeki kod işlenmelidir. Her kesmeye ilişkin fonksiyonların hangi hafıza adresinde yer aldığı Kesme Vektör Tablosu ile tutulur.

Kesme tipi, bu tablonun bir gözüne karşılık gelir. Tablonun 256 gözü vardır. Örneğin sıfıra bölme tip 0 olduğu için tablonun 0. gözüyle, taşma tip 4 olduğu için 4. gözüyle ilişkilidir. Her göz 4 bayttır ve içinde ilgili kesme alt programının segment ve offset değerleri bulunur.

Tablo bellek uzayının en düşük adresinden, yani 0 adresinden başlar. 256 göz × 4 bayt = 1024 bayt yer kaplar: onluk 0-1023, onaltılık 000H-3FFH. Kesme alt programları bellekte bambaşka bir segmentin herhangi bir offsetinde durabilir. Bu yüzden kesme alt programları far tipinde olmalıdır.

> **Hocanın vurgusu:** Kesme vektör tablosunda ilgili kesme tipine ait fonksiyonun kendisi değil, fonksiyonun adresi bulunur. Hoca bunu birkaç kez "çok önemli" diye tekrarladı.

Tablonun 00H-1FH arası BIOS'a, 20H'den sonraki belirli bir bölümü işletim sistemine (DOS) ayrılmıştır. Kalan kısım kullanıcıya aittir; kullanıcının kendi programında `INT` ile çağıracağı kesmeler bu üst bölgede tanımlanabilir.

Bir gözün içinde adresler aşağıdan yukarıya artar. Little endian düzenine göre 16 bitlik offsetin düşük baytı düşük adreste, yüksek baytı yüksek adrestedir; segment için de aynısı geçerlidir. Gözün alt iki baytında offset, üst iki baytında segment bulunur. Bu düzen far `CALL`'da yığındaki dönüş adresiyle uyumludur: yığında da yüksek adreste segment, düşük adreste offset durur. Buna göre tip $n$'nin offseti $4n$, segmenti $4n+2$ adresindedir.

## 6. Kesme işlemi sırasında işlemcinin yaptıkları

Kesme donanımsal (INTR ya da NMI üzerinden), doğrudan `INT` komutuyla ya da bir komutun yürütülmesi sırasında oluşmuş olabilir. Hepsinde süreç aynıdır. Slayttaki adımlar şunlardır (ekrandan, 00:20:00):

- Sıradaki işlem bittiğinde işlemci:
  - Komut işleme ile oluşan, single-step, NMI, INTR, INT sırasıyla bir kesme olup olmadığını kontrol eder.
  - Kesme varsa:
  - PUSHF
  - IF←0, TF←0 (INTR, single-step kesmeleri engellenir)
  - PUSH CS
  - PUSH IP
  - IP←Kesme_vektör_tablosu, CS←Kesme_vektör_tablosu

Bayrakların yığına atılması için programcının `PUSHF` yazması gerekmez; işlemci bunu kendisi yapar. Ardından IF ve TF sıfırlanır. Bunun anlamı, kesme alt programındayken donanım kesmelerinin yeniden alınmaması ve alt programdaki komutlar yürütülürken single-step kesmesi oluşmamasıdır; yani iç içe kesme oluşmaz. Sonra geri dönüş için segment ve offset yığına yazılır.

Kesme tipi bazı kesmelerde sabittir: single-step tip 1, NMI tip 2, sıfıra bölme tip 0. `INT` komutunda tip immediate değer olarak verilir. INTR'de ise işlemci $\overline{INTA}$ gönderdikten sonra tipi çevre biriminden alır. Tablonun bu tipe ait gözündeki offset ve segment IP ve CS'ye yüklenir. CS ve IP artık kesme alt programının ilk komutunu gösterdiği için alt programa dallanılmış olur. Alt program bitince `IRET` çalıştırılır: işlemci yığından sırasıyla IP, CS ve bayrak yazmacını geri yükler.

## 7. Örnek: sıfıra bölme kesme alt programını değiştirme

Slayt başlığı: "Kesme Vektör Tablosunu Değiştirme. Örnek: DIV0 kesme alt programının adresini değiştirme" (ekrandan, 00:35:00). Örnek, sıfıra bölmede tetiklenen tip 0 kesmesi için kendi yazdığımız bir kesme alt programının tabloya nasıl ekleneceğini ve bir kesme alt programının nasıl yazılacağını gösterir.

### 7.1 Amaç ve özel durum

Bir sayının sıfıra bölümü matematikte limitle sonsuz olarak ifade edilebilir (artı ya da eksi sonsuz olabilir, burada artı sonsuz kabul edilir). Bu yüzden sıfıra bölme kesmesinde AX'e FFFFH yazıp dönmek, durumu ele almanın bir yolu olarak seçilir. Sıfıra bölme 8 bitlik ya da 16 bitlik bölmede oluşabilir; AX'e FFFFH yazmak iki durumu da karşılar (8 bitlikte AL de FFH olur).

Özel bir durum vardır: `CALL` yapıldığında yığına atılan offset, `CALL`'dan sonraki komutu gösterir. Sıfıra bölme kesmesinde ise yığındaki dönüş offseti kesmeyi oluşturan `DIV` komutunun kendisini gösterir. `IRET` ile dönülürse `DIV` satırına geri dönülür. Bu yüzden kesme alt programı dönüş offsetini bir sonraki komutu gösterecek biçimde güncellemelidir.

### 7.2 Gerekli adımlar

- 1. Kesme alt programı yazılır. Far tipinde olması gerektiği için program EXE tipinde olur.
- 2. Tablonun 0. gözündeki mevcut fonksiyon adresleri yedeklenir. DOSBox ya da 8086 benzetiminde bu gözde zaten bir kesme alt programı adresi vardır.
- 3. Yazılan kesme alt programının adresi tablonun 0. gözüne yazılır.
- 4. Ana program bitip işletim sistemine dönülürken yedeklenen değerler tabloya geri yazılır.

Kesme alt programının özellikleri de şunlardır: far tipindedir, `IRET` ile biter, AX'e FFFFH yazar ve dönüş offsetini `DIV` komutunun boyu kadar artırır.

### 7.3 Veri segmenti

Programda bir yığın segmenti ve bir veri segmenti vardır. Veri segmentinde 7'şer elemanlı iki dizi bulunur; dizilerin sıradaki elemanları birbirine bölünür. İkinci dizinin 2. elemanı 0 olduğu için ikinci bölmede sıfıra bölme oluşur (ekrandan, 00:40:00):

```asm
DIZI1   DW 1,2,3,4,5,6,7
DIZI2   DW 1,0,3,4,5,6,7
ELEMAN  DW 7
OLDOF   DW 0
OLDSG   DW 0
DATASG  ENDS
```

### 7.4 Kesme alt programı

Kod segmentinin başında kesme alt programı tanımlanır (ekrandan, 00:40:00 ve 00:45:00):

```asm
CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

NEWINT  PROC FAR
        PUSH BP
        MOV  BP, SP
        MOV  AX, [BP+2]
        ADD  AX, 2
        MOV  [BP+2], AX

        MOV  AX, 0FFFFH
        POP  BP

        IRET
NEWINT  ENDP
```

Bu alt program far tipindeki bir alt yordamdan farklı değildir; tek fark dönüş komutunun `RETF` yerine `IRET` olmasıdır.

Hoca yığının durumunu ekranda çizdi (ekrandan, 00:45:00). Ana yordam çağrıldığında yığına işletim sistemine dönüş için DS ve 0 atılmıştı. Kesme tetiklenince önce bayrak yazmacı, sonra ana yordama dönüş segmenti, sonra ana yordama dönüş offseti atılır. Yığındaki bir değere erişmek için sabit bir referans gerekir; bu, yığın üzerinden parametre aktarımında olduğu gibi BP ile sağlanır. BP alt programda kullanılacağı için önce `PUSH BP` ile korunur, sonra `MOV BP, SP` yapılır. Yığının dibi en yüksek adrestir ve yığına bir şey atıldıkça adres azalır. Yığın, adres yukarıdan aşağıya doğru artacak biçimde şöyle çizilir:

```text
düşük adres  [BP]    BP (yedek)         <- SP, BP
             [BP+2]  dönüş offseti (DIV satırı)
             [BP+4]  dönüş segmenti
             [BP+6]  FLAGS
             [BP+8]  OS dönüş offseti (0)
yüksek adres [BP+10] OS dönüş segmenti (DS)
```

**Soru:** BP bu satırı gösterirken dönüş offseti BP'ye göre kaç adres uzaktadır? **Cevap:** Arada 16 bitlik bir değer olduğu için 2 bayt öte, yani `[BP+2]`'dedir.

`[BP+2]`'deki değer AX'e alınınca, ana yordamda `DIV` satırına döndürecek offset elde edilir. Bir sonraki komuta geçmek için offsetin ne kadar artırılacağı emu8086'da görüldü: `DIV BX` komutu 2 bayttır. Bu yüzden `ADD AX, 2` yapılır ve değer yığındaki yerine geri yazılır. Sonra asıl iş yapılır: AX'e FFFFH yazılır, BP yığından çekilir ve `IRET` çalıştırılır. `POP BP` sonrasında SP dönüş offsetini gösterir. `IRET` bu değeri IP'ye (artık `DIV BX`'ten sonraki komut), sıradakini CS'ye, sıradakini de bayrak yazmacına yükler. Yığında işletim sistemine dönüş değerleri kalır; ana yordam işi bitince `RETF` ile işletim sistemine döner.

### 7.5 Ana yordam: tabloya yazma

Ana yordamın ilk kısmı şöyledir (ekrandan, 00:50:00):

```asm
BASLA   PROC FAR
        PUSH DS
        XOR  AX,AX
        PUSH AX

        MOV  AX, DATASG
        MOV  DS, AX

        XOR  AX, AX
        MOV  ES, AX
        MOV  AX, WORD PTR ES:[0]
        MOV  OLDOF, AX
        MOV  AX, WORD PTR ES:[2]
        MOV  OLDSG, AX
        LEA  AX, NEWINT
        MOV  WORD PTR ES:[0], AX
        MOV  AX, CS
        MOV  WORD PTR ES:[2], AX

        STI
        XOR  SI, SI

        MOV  CX, ELEMAN
```

İlk üç satır işletim sistemine dönüş değerlerini yığına koyar, sonraki iki satır DS'yi veri segmentine ayarlar.

**Soru:** İşaretlenen kısım (ES ile ilgili satırlar) ne yapıyor? **Cevap:** Bir öğrenci vektör tablosunu değiştirmeye çalıştığını söyledi; hoca daha teknik olarak açıkladı. Sıfıra bölmenin tablodaki gözü 0. gözdür. 20 bitlik adres olarak tip 0'ın offseti 00000H'de, segmenti 00002H'dedir. Yani 0 segmentinin 0 offsetinde BIOS'un koyduğu sıfıra bölme alt programının offseti, 0 segmentinin 2 offsetinde de segmenti vardır.

0 segmentine erişmek için bir segment yazmacı gerekir. O anda DS veri segmentini, CS kod segmentini, SS yığın segmentini gösterir. Geriye ek segment (ES) kalır. ES'ye sabit değer doğrudan atanamadığı için AX sıfırlanıp ES'ye kopyalanır. Program belleğe yüklendiğinde 700'lü adresler civarında bir segmente yerleşir; 0 segmenti bizim için uzaktır ve açıkça belirtilmelidir. `ES:[0]`'daki offset `OLDOF`'a, `ES:[2]`'deki segment `OLDSG`'ye yedeklenir.

**Soru:** `LEA AX, NEWINT` ve sonraki satırlar ne işe yarar? **Cevap:** Bir öğrenci fonksiyonun offsetini ve kod segmentini vektör tablosuna yazmak için kullanıldığını söyledi; hoca onayladı. `LEA` bir etiketin kendi segmentindeki offsetini verir. Fonksiyonun segmenti de, ana yordamla aynı kod segmentinde olduğu için o anki CS'dir. Offset `ES:[0]`'a, segment `ES:[2]`'ye yazılır.

Hoca `STI` satırına gerek olmayabileceğini, silerek de denenebileceğini söyledi.

### 7.6 Döngü ve geri yükleme

Döngünün kodu karede görünmüyor; altyazıya göre şöyle işler. SI sıfırlanıp indis olarak kullanılır, CX'e eleman sayısı (7) yüklenir. Her turda DX sıfırlanır, AX'e birinci dizinin, BX'e ikinci dizinin sıradaki elemanı alınır ve `DIV BX` yapılır. Diziler word olduğu için SI ikişer artırılır ve `LOOP` ile döngü sürer. Döngüden sonra yedeklenen değerler (`OLDOF`, `OLDSG`) tablonun 0. gözüne geri yazılır. <!-- BELİRSİZ: döngü ve geri yükleme satırlarının tam kodu karelerde görünmüyor; anlatım altyazıdan alındı. -->

**Soru:** DX'i neden her seferinde sıfırlıyoruz? Sonuç AX'te oluşmuyor mu, bir kez sıfırlamak yetmez mi? **Cevap:** Bölme 16 bitliktir: `DIV BX` 32 bitlik sanal DX:AX yazmacını BX'e böler. Bölüm AX'e yazılır, ama kalan (DX:AX mod BX) da DX'e yazılır. Yani DX her bölmede bozulur ve bir sonraki bölmeden önce yeniden sıfırlanmalıdır.

> **Ders sonrası not:** Hoca cevabın sonunda "her seferinde BX de bozuluyor" dedi; kastedilen DX'tir. `DIV BX` BX'i değiştirmez, kalanı DX'e yazar.

### 7.7 DOSBox ile adım adım çalıştırma

Kod MASM ile derlenip bağlanır (link) ve debug ile adım adım (`t`, trace) yürütülür. İlk satırlar işletim sistemine dönüş değerlerini ve DS'yi ayarlar (ekrandan, 00:55:00).

**Soru:** Vektör tablosunun tip 0 gözüne debug ile nasıl bakılır? **Cevap:** Dump komutuyla 0 segmentinin 0 offsetine bakılır (`d 0000:0000`). Altyazıya göre burada F000 segmentinin 1060 offsetinde bir fonksiyon adresi görüldü; bunu BIOS yerleştirmiştir. Bu fonksiyonun sıfıra bölmeyi nasıl ele aldığı örnek için önemli değildir. Değerler yedeklenip yerine kendi adresimiz konur.

`LEA AX, NEWINT` komutunun 0 offseti ürettiği debug ekranında da görülür. Offset ve segment yazıldıktan sonra yeniden dump edilince tabloda kendi CS'mizin 0 offseti, yani NEWINT'in adresi görünür.

Döngüde ilk bölme 1/1'dir, sorun yoktur. İkinci turda AX = 2, BX = 0 olur. `DIV BX` komutu IP = 004BH'dedir. Yürütülünce `PUSH BP` satırına, yani kesme alt programının ilk komutuna gelinir. Bu anda yığına (SS:SP) bakılınca en üstte dönüş offseti olarak 004BH görülür; değiştirilmezse yine `DIV BX` satırına dönülecektir. Ardından ana yordama dönüş segmenti, bayrak yazmacı ve işletim sistemine dönüş offseti (0) ile segmenti gelir.

**Soru:** Yığındaki şu farklı değer nedir? **Cevap:** Bir öğrenci bayraklar olduğunu söyledi; hoca onayladı: bu, kesmede yığına atılan bayrak yazmacıdır.

Dönüş offseti okunup 2 artırılınca ve geri yazılınca yığında 004BH değeri 004DH olur. Listeleme (.LST) dosyasında 004BH `DIV BX` satırı, 004DH ise sonraki komuttur. Kesmeden AX = FFFFH ile dönülür; sonraki elemanlarda kesme oluşmadan döngü biter.

## 8. Donanımsal kesmeler: NMI ve INTR

### 8.1 NMI

NMI ucu yükselen kenarla tetiklenir. Bu uçtan kenar geçişiyle istek gelince otomatik olarak tip 2 kesmesi oluşur; işlemci tipi kendi belirler. Tablonun 2. gözünde, yani 08H adresindeki adresler IP ve CS'ye yüklenir ($2 \times 4 = 8$).

### 8.2 INTR

INTR ucundan gelen istekler seviye tetiklemelidir. INTR ucu sürekli 1'de tutulursa istek alınıp değerlendirilir, alt yordama gidilir, kesme işlemi yapılıp dönülür; uç hâlâ 1 ise aynı kesme yeniden gelebilir. Bu ucun istekleri buna göre değerlendirilmelidir.

> **Ders sonrası not:** Hoca bu açıklamanın sonunda "kenar tetiklemeli olan INTR ucu" dedi. Kendi anlatımında da belirttiği gibi INTR seviye tetiklemelidir; kenarla tetiklenen NMI'dır.

İstek tipinin belirlenmesi yine aynıdır. Çevre birimi INTR ucunu 1 yapar. İşlemci yürüttüğü komutu bitirince aktif 0 olan $\overline{INTA}$ ucunu 0 yapar; bu, "isteğini değerlendireceğim" mesajıdır. Ardından çevre birimi istediği kesme tipini D0-D7 üzerinden 8 bitlik değer olarak gönderir. BIOS kesmeleri 00H-1FH arasındadır. İşletim sistemi yoksa 20H-FFH arası INTR için kullanılabilir. İşletim sistemi varsa DOS kesmeleri de 20H'den itibaren olan bölgeyi kullanır.

### 8.3 Zamanlama diyagramı

Slayttaki zamanlama diyagramı şöyledir (ekrandan, 01:15:00):

```text
INTR     ____/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
INTA'    ‾‾‾‾‾‾‾‾\____/‾‾‾‾‾‾‾‾\____/‾‾‾‾‾
D7-D0    - - - - -<  * >- - - - -< VN >- - -
                                 Vector number
```

INTR işlemci için bir giriş ucudur. Uç 1'e çıktıktan sonra işlemci devam eden işlemini bitirir ve kendisi için bir çıkış ucu olan $\overline{INTA}$'yı 0 yapar. $\overline{INTA}$ iki kez 0'a iner. İlk iniş çevre birimine işlemcinin tip değerini almaya hazır olduğunu bildirir. İkinci inişte çevre birimi vektör tipini D0-D7 üzerinden işlemciye gönderir. İki acknowledge darbesi 8086'ya özgü bir durumdur. Slayttaki uyarı: "Dikkat! Adres uçlarından gönderilen kesme TİP'idir, kesme vektör tablosunun ilgili adresi değil."

## 9. Elle kesme vektörü üretme ve önceliklendirme

### 9.1 Tek kaynak için sabit vektör

Sistemde tek bir kesme kaynağı varsa ve INTR'ye bağlıysa, bu kaynak için sabit bir vektör numarası şöyle üretilir: bir 74244 tamponu kullanılır. Bu entegre, enable uçlarına 0 gelince A girişlerini Y çıkışlarına aktarır. Girişlere pull-up dirençler ve anahtarlar bağlıdır. Anahtarı açık olan uçta direnç üzerinden VCC (5 V, lojik 1) görülür, anahtarı kapalı olan uç ise toprağa bağlıdır ve 0'dır. Örnekte yalnız en yüksek bit 1, diğerleri 0'dır, yani 80H. <!-- BELİRSİZ: tek kaynaklı devrenin slaytı karelerde yok; hangi anahtarın açık/kapalı olduğu altyazıda karışık anlatılıyor, sonuç değeri (80H) altyazıdan alındı. --> $\overline{INTA}$'nın iki 0 geçişi sırasında 80H veri uçlarına çıkar ve ikinci geçişte işlemci tarafından vektör tipi olarak okunur.

### 9.2 Yedi kaynak için vektör üretme

Slayttaki devre "Donanımsal Kesmeler INTR Genişletme" başlığını taşır (ekrandan, 01:20:00):

- U1 (74ALS244) tamponunun Y çıkışları düşük veri yoluna (D0-D7) bağlıdır. Tamponun 1G ve 2G enable uçları $\overline{INTA}$'ya bağlıdır.
- Kesme istek uçları $\overline{IR0}$-$\overline{IR6}$ aktif 0'dır. Her biri tamponun bir A girişine ve U2 (74ALS30, 8 girişli NAND) kapısının bir girişine gider. NAND çıkışı (pin 8) INTR'ye bağlıdır.
- D7'ye karşılık gelen tampon girişi 10K'lık bir dirençle VCC'ye bağlıdır.

Yedi kaynak arasında öncelik yoktur. İstekler tek tek ya da aynı anda gelebilir. Kurulan sistem her isteği tek başına, ikili kombinasyonları ayrı, n'li kombinasyonları da ayrı değerlendirir. Kaynaklardan herhangi birinde 0 (istek) varsa NAND çıkışı 1 olur ve INTR'ye 1 gelir. İşlemci $\overline{INTA}$ gönderdiğinde D7'ye her zaman 1, diğer uçlara isteklere göre 00H-7FH arasında bir değer gelir. Böylece hangi isteğin geldiğine göre 80H-FFH arasında 128 farklı vektör tipi gönderilebilir.

Hoca örnek olarak yalnız IR0'dan istek gelirse 81H, yalnız IR1'den gelirse 82H vektörünün oluşacağını, iki bitin 1 olduğu bir durumda C0H'nin, hepsine basılınca FFH'nin oluşacağını söyledi. <!-- BELİRSİZ: C0H örneğinde hocanın hangi istek ucunu gösterdiği altyazıdan anlaşılmıyor. -->

> **Ders sonrası not:** Hocanın verdiği değerler, istek gelen ucun ilgili veri bitini 1 yaptığı varsayımına dayanıyor. Karedeki şemada istek uçları aktif 0'dır ve tampona doğrudan bağlıdır; bu durumda büyük olasılıkla istek olmayan uçlar 1, istek gelen uç 0 okunur. Buna göre yalnız IR0 isteğinde büyük olasılıkla FEH, bütün istekler birden geldiğinde 80H oluşur. 80H-FFH aralığı ve D7'nin hep 1 olması iki yorumda da aynıdır.

Tekli, çiftli ve n'li kombinasyonların her biri böylece farklı bir kesme vektör tipi olur. Bu, vektörü elle oluşturmak istendiğinde karşılaşılan senaryodur.

### 9.3 Daisy chain ve yazılımla önceliklendirme

Örneğin iki 8255 entegresi mod 1'de veri aktarımı için kullanılıyor olsun. Her ikisinde de INTRA ve INTRB uçları vardır. Bunlar OR kapıları üzerinden birleştirilip işlemcinin INTR ucuna bağlanabilir. Kaynakların bu şekilde birbirine bağlanmasına daisy chain denir.

Tek bir INTR ucu olduğu için isteğin kimden geldiği ve öncelik yazılımla bulunur: önce birinci 8255'in INTRB biti kontrol edilir, değilse INTRA biti, değilse ikinci 8255'in INTRB'si, değilse INTRA'sı. Hangi sırayla kontrol edilirse kesme önceliği de o olur. Bundan farklı olarak önceliklendirme için öncelik kodlayıcı (priority encoder) da kullanılabilir; bu sonuç donanımsal olarak elde edilir.

Buraya kadarki kısımlar, üçüncü haftadaki özel G/Ç cihazı örneğine benzer biçimde, kesme isteğinin, kesme tipinin ve önceliğin elle nasıl sağlanacağını gösterir.

## 10. 8259A programlanabilir kesme denetleyicisi

### 10.1 Genel özellikler

Slayttaki özellikler şunlardır (ekrandan, 01:25:00):

- 8259A programlanabilir kesme kontrol devresidir.
- Kesme isteklerine öncelik atayabilir (priority encoding).
- Tek başına 8 farklı kesme vektörü sağlar.
- Master (1)/Slave (8) formunda 64 farklı kesme vektörü sağlar.

Önceki örnekteki gibi önceliği yazılımla kontrol etmek gerekmez; aynı anda iki istek gelirse öncelik sırası kimdeyse onun isteği işlemciye gönderilir. Tekil bağlantıda 8 kaynak değerlendirilir. Bir entegre master modda kullanılıp 8 ucunun her birine slave olarak birer 8259 bağlanırsa, her slave'in 8 girişiyle $8 \times 8 = 64$ kaynak elde edilir.

### 10.2 Uçlar

- 8 veri ucu (D0-D7)
- Kontrol uçları: $\overline{RD}$, $\overline{WR}$, $\overline{CS}$
- INT: işlemcinin INTR ucuna bağlanır.
- $\overline{INTA}$: işlemcinin $\overline{INTA}$ ucu buraya bağlanır.
- Bir adres ucu (A0): cihaz G/Ç uzayında 2 bayt yer kaplar.
- CAS0-CAS2: kaskat bağlantı için 3 uç; 8 slave'e kadar destekler. Bir kod çözücü girişi gibi düşünülebilir: 000-111 değerleri 8 slave'den birini seçer.
- $\overline{SP}/\overline{EN}$: entegrenin master/slave ya da enable buffer olarak çalışacağını belirler. Derste tek 8259 master olarak kullanılacağı için bu uç 1'e bağlanır.

İçeride ICW (Initialization Control Word) ve OCW (Operation Control Word) yazmaçları vardır. 2 baytlık adres alanına rağmen bunlara 8251'de olduğu gibi belli bir sırayla erişilir. İç yapıda öncelik, maskeleme ve bunları yöneten kontrol mantığı bulunur.

### 10.3 8259 ile kesme süreci

8259'un IR uçlarından biri ya da birkaçı 1'e çıkınca 8259 işlemciye INT ucundan istek gönderir ve $\overline{INTA}$ ucundan cevap bekler. İlk $\overline{INTA}$ darbesi alınınca öncelik ve kesme bitleri ayarlanır; bu, hangi isteğin vektörünün gönderileceğini belirler. İkinci $\overline{INTA}$ darbesinde 8259 öncelik sırasına göre seçilen isteğin kesme vektör numarasını veri uçlarından gönderir.

Kesme işleminin tamamlanması için otomatik kesme sonu (automatic end of interrupt, AEOI) modu kullanılacaktır. Elle (manuel) modda ilgili biti yazılımla sıfırlamak gerekir. Başlangıçta AEOI açılırsa süreç otomatik tamamlanır.

### 10.4 ICW'lere erişim sırası

Slayttaki tablo (ekrandan, 01:30:00):

| CS | A0 | Initialization |
|---|---|---|
| 0 | 0 | ICW1 |
| 0 | 1 | ICW2, ICW3, ICW4 |
| 1 | X | Not Address |

A0=0 ile erişilen yazmaç ICW1'dir. A0=1 ile sırasıyla ICW2, ICW3 ve ICW4'e erişilir. ICW1'deki ayarlara göre akış belirlenir. Kaskat bağlantı kullanılmayacaksa ICW3 atlanır. ICW4 kullanılacaksa (derste hep kullanılacak) ICW4'e değer yazılır. Böylece erişim sırası ICW1 → ICW2 → ICW4 olur.

### 10.5 ICW1 ve ICW2

Slayttaki ICW1 ve ICW2 tabloları şöyledir (ekrandan, 01:35:00 ve 01:45:00):

| AD0 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 1 | LTIM | 0 | SGNL | IC4 |

- D7-D5: x86 için 0
- D3 (LTIM): 1 for Level Trigger, 0 for Edge Trigger
- D1 (SGNL): 1 = single, 0 = Cascade
- D0 (IC4): 1 = IC4 needed, 0 = no IC4 needed

| AD0 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|---|
| 1 | T7 | T6 | T5 | T4 | T3 | T2 | T1 | T0 |

- T7-T0 is the assign to IR0, Vector address for ISR

8086 kullanılıyorsa ICW1'in en yüksek 3 biti 0 olmalıdır, D4 sabit 1'dir. NMI kenar tetiklemeli, INTR seviye tetiklemelidir. 8259 ise IR uçlarına gelen istekleri seviye ya da kenar tetiklemeli olarak ele alabilir; bu, D3 (LTIM) bitiyle seçilir. İşlemcinin INTR ucu tarafı yine seviye tetiklemeli çalışır. Daha duyarlı olduğu için derste kenar tetikleme tercih edilecektir. Bağlantı derste hep tekli olacaktır.

Hoca ICW1'i slayta "0001 (?) 011" diye yazdı: değişen tek bit D3'tür. Kenar tetiklemede $0001\,0011_2 = 13H$, seviye tetiklemede $0001\,1011_2 = 1BH$ olur. Bu değerler neredeyse sabit gibi düşünülebilir.

ICW2'ye yazılan değerin en düşük 3 biti 8086 ile kullanıldığında dikkate alınmaz (0 kabul edilir). Bu değer IR0'dan gelen isteğin vektör numarasıdır. IR1'in vektör numarasında son bit 1 olur. Yani son 3 bit istek numarasına göre 000'dan 111'e değişir, T7-T3 ise yazılan değere göre sabittir. Kısaca ICW2'ye IR0'ın vektör numarası yazılır; IR0-IR7'nin numaralarını 8259 kendisi hesaplar.

### 10.6 ICW3, ICW4 ve OCW'ler

ICW3 ve ICW4 master-slave modu içindir; tek 8259 kullanıldığı için ICW3 geçilir. ICW4'te otomatik kesme sonu (AEOI) biti 1 yapılır ve 8086 için mikroişlemci modu biti (µPM) 1 kullanılır. Bu yüzden ICW4 her zaman 03H olarak kullanılacaktır. Hocanın açıklamasına göre µPM'nin 1 olması, $\overline{INTA}$'dan iki kez 0 geçişi geleceğini belirtir. <!-- BELİRSİZ: ICW4 slaytı karelerde yok; bit adları altyazıdan alındı. -->

> **Ders sonrası not:** Hoca bir yerde "OCW4'ü hep 03H olarak kullanacağız" dedi; kastedilen ICW4'tür.

OCW'lere de 0 ve 1 adresleriyle, verilen sırayla erişilir. Bunlar daha çok maskeleme ve kesmeyi elle bitirme için kullanılır; derste OCW kullanılmayacaktır.

Özetle 8259 ayarlanırken: ICW1'e (büyük olasılıkla kenar tetikleme seçileceği için) 13H, ICW2'ye IR0'ın karşılık geleceği vektör numarası, ICW4'e 03H yazılır.

## 11. Örnek: 8259 ile düğmeye basma sayısını sayma

### 11.1 Soru ve devre

Hoca soruyu ekrana yazdı: 60H-62H adreslerine yerleştirilmiş 8259'un IR0 ucuna bir düğme bağlıdır. Düğmeye kaç kez basıldığı kesme tabanlı olarak sayılacaktır. Düğmeye basıldığında tetiklenecek kesme tipi 40H olmalıdır.

Proteus şemasında (ekrandan, 01:40:00) 8259'un (U5) bağlantıları şöyledir:

- D[0..7]: AD[0..7] veri yoluna
- $\overline{CS}$ (pin 1): adres çözme devresindeki 74LS138'in Y0 çıkışına
- $\overline{WR}$ (pin 2), $\overline{RD}$ (pin 3): işlemcinin $\overline{WR}$ ve $\overline{RD}$ işaretlerine
- A0 (pin 27): işlemcinin A1 ucuna
- $\overline{SP}/\overline{EN}$ (pin 16): lojik 1'e
- INT (pin 17): işlemcinin INTR ucuna; $\overline{INTA}$ (pin 26): işlemcinin $\overline{INTA}$ ucuna
- IR0 (pin 18): bir düğme üzerinden VCC'ye, R1 pull-down direnciyle toprağa

Adres çözme devresi yalnız 60H ve 62H'de chip select üretir. Bu iki adreste A0 hep 0 olduğu için iki adresi ayıran bit A1'dir; bu yüzden A1, 8259'un adres ucuna bağlanır. Düğme basılı değilken IR0 lojik 0, basılınca lojik 1'dir; yani IR girişleriyle uyumludur, tetikleme için 1 gelmesi gerekir.

Gerekenler şunlardır: düğmeye basılınca çalışacak kesme alt programı, bu alt programın tabloya yerleştirilmesi, bunun için tablodaki eski değerlerin yedeklenmesi ve program bitince geri yüklenmesi.

### 11.2 Kod

Proteus kaynak kodu (ekrandan, 01:50:00):

```asm
STACKSG SEGMENT PARA STACK 'STACK'
        DW 12 DUP(?)
STACKSG ENDS

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, SS:STACKSG

NEWINT  PROC FAR
        PUSH BP
        MOV  BP, SP
        INC  AX

        POP  BP
        IRET
NEWINT  ENDP

START PROC FAR

        XOR  AX, AX
        MOV  ES, AX
        MOV  AL, 40H
        MOV  AH, 4
        MUL  AH
        MOV  BX, AX
        LEA  AX, NEWINT
        MOV  WORD PTR ES:[BX], AX
        MOV  AX, CS
        MOV  WORD PTR ES:[BX+2], AX

        MOV  AL, 13H
        OUT  60H, AL
        MOV  AL, 40H
        OUT  62H, AL
```

Karede görünmeyen devamı altyazıya göre şöyledir: ICW4 için 03H değeri 62H adresine yazılır, `STI` ile kesmeler açılır, AX sıfırlanır ve program sonsuz döngüde bekler. <!-- BELİRSİZ: ICW4, STI ve sonsuz döngü satırlarının tam yazımı karelerde görünmüyor. -->

### 11.3 Açıklama

- **ICW1:** 60H'ye ilk kez yazılan değer, A1 = 0 olduğu için ICW1'e gider. $13H = 0001\,0011_2$: 8086 için üst bitler 0, D4 = 1, D3 = 0 (kenar tetikleme), D1 = 1 (tek 8259), D0 = 1 (ICW4 kullanılacak).
- **ICW2:** IR0'a bağlı kesmenin tipi 40H olmalıdır; $\overline{INTA}$ ile işlemciye 40H gönderilmelidir. Bu değer ICW2'ye yazılır. ICW2'nin son 3 biti 0 olmalıdır; 40H'nin son 3 biti zaten 0 olduğu için doğrudan 40H yazılır. A1 = 1 olan adres 62H'dir.
- **ICW3:** ICW1'de tekli mod seçildiği için atlanır.
- **ICW4:** ICW1'de IC4 = 1 dendiği için 62H'ye yapılan ikinci yazma ICW4'e gider: 03H, yani AEOI açık ve 8086 modu.
- `STI` ile IF = 1 yapılır, AX sıfırlanır ve sonsuz döngüde beklenir. Kodda hiçbir şey olmuyor gibi görünür, ama düğmeye her basıldığında kesme alt programı tetiklenir.

> **Ders sonrası not:** Hoca açıklama sırasında bir yerde "IR0'a bağlı kesmenin 60H olmasını istiyoruz" dedi; soruda ve kodda istenen tip 40H'dir. 60H 8259'un adresidir.

- **Vektör tablosu:** AL = 40H ve AH = 4 ile `MUL AH` yapılınca AX = $40H \times 4 = 100H$ olur. Bu, tip 40H'nin tablodaki gözünün adresidir. Bu göze NEWINT'in offseti ve NEWINT'in bulunduğu kod segmentinin değeri yazılır; yani tablo üzerine yazılmış olur. Proteus simülasyonundaki 8086'da işletim sistemi ya da BIOS olmadığı için yedekleme yapılmaz. Program sonsuz döngüde kaldığı için hiç sonlanmaz.
- **Kesme alt programı:** her girişte AX'i 1 artırır. Kesme 0'dan 1'e geçişte tetiklenir. Kenar tetiklemede her basış bir kez sayılır. Seviye tetiklemede ise seviye her kontrol edildiğinde değer yanlışlıkla birden çok kez artabilir. Bu yüzden kenar tetikleme bu ölçümü daha hassas yapar.

### 11.4 Simülasyon

Simülasyon çalıştırılıp düğmeye basılmadan duraklatılınca, Debug menüsündeki 8086 registers penceresinde AX = 0 görülür. Düğmeye üç kez basılıp yeniden duraklatılınca AX = 3 olur. Ana programda yoklama mantığında hiçbir kontrol yoktur; sayma tamamen düğmeye her basışta tetiklenen kesme alt programıyla yapılır.

Kesme kaynağı olarak yalnız düğmeler değil, 8255'in mod 1/mod 2 INTR uçları, 8251'in TxRDY ve RxRDY uçları, 8254'ün OUT0, OUT1, OUT2 uçları ve ADC'nin INTR ucu da INTR ya da NMI üzerinden kullanılabilir. Hoca örnekleri çeşitlendirip denemeyi önerdi.

> **Hocanın vurgusu:** Kesme konusu önceki bütün çevre birimlerini içeren kapsayıcı bir konudur; hoca sınavda bununla ilgili soru olacağını açıkça söyledi.

## Örnek Sorular

### Soru 1: SF'yi 1 yapmak

(ekrandan, 00:30:00) Sign Flag = 1 yapmak için izlenecek yol nedir?

**Çözüm (derste verildi):**

```asm
LAHF
OR   AH, 80H
SAHF
```

`LAHF` bayrakları AH'ye alır (parametre almaz), bit 7 (SF) `OR AH, 80H` ile 1 yapılır, `SAHF` ile bayraklara geri yazılır.

### Soru 2: SF'yi 0 yapmak

(ekrandan, 00:30:00) Sign Flag = 0 yapmak için izlenecek yol nedir?

**Çözüm (derste verildi):**

```asm
LAHF
AND  AH, 7FH
SAHF
```

Bit 7'yi 0, diğerlerini 1 bırakan maske $0111\,1111_2 = 7FH$'tir.

### Soru 3: TF'yi 1 yapmak

(ekrandan, 00:30:00; çözüm derste sözlü, 00:30:32-00:32:52) TF = 1 yapmak için izlenecek yol nedir?

**Çözüm (derste verildi, düzeltilerek):** Bayrak yazmacı yığına atılır, BP ile yığının üstü sabit referans yapılır, bit 8 1 yapılır ve geri yüklenir:

```asm
PUSHF
MOV  BP, SP
OR   WORD PTR [BP], 0100H
POPF
```

Derste önerilen öteki yol da şudur: `PUSHF`, `POP AX`, `OR AX, 0100H`, `PUSH AX`, `POPF`.

> **Ders sonrası not:** Derste maske "0010H" olarak söylendi. 0010H bayrak yazmacının 4 numaralı bitini (AF) etkiler; 8 numaralı bit (TF) için doğru maske 0100H'dir. Ayrıca ikinci yolda `POPF`'den önce değerin `PUSH AX` ile yığına geri konması gerekir (ara adım eklendi).

### Soru 4: Özel komutu olan bayraklar

(derste sözlü, 00:22:43) Hangi bayraklar için özel komutlar vardır?

**Cevap (derste verildi):** CF için `CLC`, `STC`, `CMC`; DF için `CLD`, `STD`; IF için `CLI`, `STI`.

### Soru 5: Dönüş offsetinin BP'ye göre yeri

(derste sözlü, 00:41:16) NEWINT alt programında `PUSH BP` ve `MOV BP, SP` sonrasında, yığındaki dönüş offseti BP'ye göre nerededir?

**Cevap (derste verildi):** Arada 16 bitlik BP yedeği olduğu için 2 bayt ötede, `[BP+2]`'dedir.

### Soru 6: LEA AX, NEWINT sonucu

(derste sözlü, 00:49:59) Sıfıra bölme örneğinde `LEA AX, NEWINT` yürütüldüğünde AX'te hangi değer oluşur?

**Cevap (derste verildi):** `LEA` etiketin kendi segmentinin başından itibaren offsetini verir. NEWINT kod segmentinin en başında tanımlı olduğu ve öncesinde başka kod olmadığı için AX = 0 olur. Debug ekranında da 0 offseti görüldü.

### Soru 7: Tip 0 gözüne debug ile bakmak

(derste sözlü, 00:54:54) Kesme vektör tablosunun tip 0 gözüne debug ile nasıl bakılır?

**Cevap (derste verildi):** Dump komutuyla 0 segmentinin 0 offseti görüntülenir (`d 0000:0000`). İlk iki bayt offseti, sonraki iki bayt segmenti verir.

### Soru 8: 8259 ile düğme sayacı

(derste ekrana yazıldı, 01:40:16) 60H-62H adreslerine yerleştirilmiş 8259'un IR0 ucuna bir düğme bağlıdır. Düğmeye kaç kez basıldığı kesme tabanlı olarak sayılacaktır. Düğmeye basıldığında tetiklenecek kesme tipi 40H olmalıdır.

**Çözüm (derste verildi):** Bölüm 11'deki gibi: tip 40H'nin tablo gözü $40H \times 4 = 100H$'ye NEWINT'in offseti ve CS yazılır; 60H'ye ICW1 = 13H, 62H'ye ICW2 = 40H ve ICW4 = 03H yazılır; `STI` ile kesmeler açılır ve ana program sonsuz döngüde bekler. Kesme alt programı her çağrıldığında AX'i 1 artırır.

## Dersin Toparlaması

Bu derste kesme konusu tamamlandı. Önce yazılımsal (`INT`, `INTO`, `INT 3`, komut yürütülürken oluşan) ve donanımsal (INTR, NMI) kesme kaynakları, sabit kesme tipleri, IF ve TF bayrakları ve bayrak komutları ele alındı. `LAHF`/`SAHF` ile SF'nin, `PUSHF`/`POPF` ile TF'nin nasıl değiştirileceği soru olarak çözüldü. Kesmede yığına FLAGS, CS ve IP'nin atıldığı ve dönüşün `IRET` ile yapıldığı gösterildi. Kesme vektör tablosunun 0 adresinden başlayan 1024 baytlık yapısı ve gözlerde alt programın kendisinin değil adresinin tutulduğu vurgulandı. Sıfıra bölme örneğinde kendi kesme alt programımız tabloya yazıldı, eski adres yedeklendi ve dönüş offsetinin `DIV` komutunun boyu kadar artırılması gerektiği DOSBox debug ile gösterildi.

İkinci bölümde donanımsal kesmelere geçildi: NMI'nın kenar, INTR'nin seviye tetiklemeli olduğu ve $\overline{INTA}$'nın iki darbesiyle tipin veri yolundan okunduğu anlatıldı. Vektörün 74244 ve NAND kapısıyla elle üretilmesi, daisy chain ile yazılımsal önceliklendirme ve öncelik kodlayıcı ele alındı. Son olarak 8259A'nın uçları, ICW1/ICW2/ICW4 ayarları (13H, IR0 vektörü, 03H) anlatıldı ve Proteus'ta IR0'a bağlı bir düğmenin basılma sayısı kesmeyle sayıldı. Bir sonraki derste bellek arabirimi (belleğin 8086'ya bağlanması ve adreslere yerleştirilmesi) işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
