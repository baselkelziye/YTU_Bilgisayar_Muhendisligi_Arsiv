# Ders 9 Genişletilmiş Notu: DOSBox ile Derleme ve DEBUG, Sözde Komutlar, EXE Tipi Program İskeleti

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. DOSBox Ortamının Hazırlanması
- 2. MASM ve LINK ile Derleme
- 3. Örnek Program: deneme.asm
- 4. DEBUG ile Yazmaçların ve Belleğin İncelenmesi
- 5. EXE Programının İşletim Sistemine Dönüşü
- 6. Veri Kesiminin İncelenmesi ve Hizalama Boşluğu
- 7. Diğer DEBUG Komutları ve Sonucun Kontrolü
- 8. Sözde Komutlara Giriş
- 9. Kesim Tanımı: SEGMENT ve ENDS
- 10. Segment Yazmaçlarının Hangi Kesimi Gösterdiği
- 11. EXE ve COM Programlarının Bellek Yerleşimi
- 12. Veri Tanımlama Sözde Komutları
- 13. LABEL
- 14. Yordam ve Makro Sözde Komutları
- 15. LENGTH, TYPE, SIZE, OFFSET, SEG ve END
- 16. Sözde Komutlar Derleme Anında Ne Yapar: LST ve MAP Dosyaları
- 17. EXE Tipi Program İskeleti
- 18. Örnek: İki 16 Bitlik Sayının Toplamını 32 Bitlik Değişkende Saklamak
- Örnek Sorular

## 1. DOSBox Ortamının Hazırlanması

Ders, önceki haftada konuşulan geliştirme ortamının kurulumuyla açıldı. DOSBox bir DOS emülatörüdür ve Windows, Linux, macOS sürümleri vardır. Hoca Windows üzerinde gösterdi, diğer sistemlerde de kabaca aynı olduğunu söyledi. Ayrıca DOSBox ayar dosyasında (`dosbox-0.74-3.conf`) yazı boyutunu büyütmek için iki satırı değiştirdiğini belirtti (ekrandan, 00:10:00). <!-- BELİRSİZ: Değiştirilen iki satırın hangileri olduğu altyazıda söylenmedi. -->

DOSBox açıldığında kendi sanal Z sürücüsünde başlar. Yereldeki bir klasörü DOSBox'a göstermek için `MOUNT` komutu kullanılır:

```text
MOUNT C <yereldeki klasör>
C:
DIR
```

`MOUNT C ...` yereldeki klasörü DOSBox içinde C sürücüsü olarak tanıtır; C yerine başka bir harf de verilebilir. `C:` ile o sürücüye geçilir, `DIR` ile içerik listelenir. Hoca kendi düzeninde çalıştırılabilir programları bir `BIN` klasöründe, `.asm` dosyalarını bir `MASM` klasöründe tutuyordu. Öğrencilere daha pratik bir yol önerdi: bütün çalıştırılabilir dosyalar ve bütün `.asm` dosyaları bağlanan tek klasöre konabilir.

`MOUNT` işlemi DOSBox kapatılınca kaybolur ve yeniden Z sürücüsünde başlanır. Bunu her seferinde elle yapmamak için DOSBox Options (ayar dosyası) açılır; en alttaki `[autoexec]` bölümüne bu komutlar birer satır olarak yazılır. Böylece DOSBox her açıldığında bu komutlar kendiliğinden çalışır ve doğrudan C sürücüsünde başlanır.

Bizi doğrudan ilgilendiren programlar şunlardır:

- `MASM`: Microsoft Macro Assembler; `.asm` dosyasından nesne dosyası üretir.
- `LINK`: nesne dosyalarını bağlayıp `.EXE` üretir.
- `EXE2BIN`: COM tipi programlarla çalışılırken `.EXE`'yi `.COM`'a çevirir; bu daha sonraki derslerin konusudur.
- `DEBUG`: programı adım adım çalıştırıp yazmaçları ve belleği incelemeye yarar.

## 2. MASM ve LINK ile Derleme

Ekranda `MASM` sürüm 5.10 ve `LINK` sürüm 3.64 kullanıldı (ekrandan, 00:15:00). Derleme şu adımlarla yapılır:

```text
C:\MASM>c:\bin\MASM.EXE deneme.asm
Object filename [deneme.OBJ]:
Source listing  [NUL.LST]: deneme.lst
Cross-reference [NUL.CRF]:
     0 Warning Errors
     0 Severe  Errors

C:\MASM>c:\bin\LINK.EXE deneme.obj
Run File [DENEME.EXE]:
List File [NUL.MAP]: deneme.map
Libraries [.LIB]:

C:\MASM>DENEME.EXE
```

Assembler önce nesne dosyasının adını sorar; ad verilmezse `deneme.OBJ` kullanılır. Sonra liste dosyasını (`.LST`) sorar; varsayılan `NUL` olduğu için ad verilmezse üretilmez. Hoca LST'nin üretilmesini istediği için `deneme.lst` adını verdi. Çapraz referans dosyası (`.CRF`) üretilmedi. Hata ve uyarı olmadan derleme bitince bizim için anlamlı çıktı `.OBJ` dosyasıdır.

Daha büyük projelerde birden fazla kaynak dosya ayrı ayrı derlenip ortaya çıkan nesne dosyaları birlikte bağlanarak tek bir çalıştırılabilir dosya üretilebilir. İleride ana yordamla alt yordamlar ayrı dosyalarda yazılacak; şimdilik tek nesne dosyası vardır.

Bağlayıcı `.OBJ` dosyasını girdi olarak alır, çalıştırılabilir dosyanın adını (varsayılan `DENEME.EXE`), harita dosyasını (`.MAP`) ve kütüphaneleri sorar. Hoca harita dosyasını da istedi. Sonunda `.EXE` oluşur ve çalıştırılabilir. Program ekrana bir şey yazmadığı için çalışıp hemen bitti.

Daha hızlı bir yol da vardır: komutun sonuna noktalı virgül konursa bütün varsayılanlar kabul edilir.

```text
MASM deneme.asm;
LINK deneme.obj;
```

Bu durumda LST ve MAP üretilmez, yalnız `.OBJ` ve `.EXE` oluşur.

## 3. Örnek Program: deneme.asm

DEBUG'ı göstermek için kullanılan programın tamamı ekrandan şöyledir (ekrandan, 00:20:00, 00:25:00, 00:45:00):

```asm
PAGE 80, 60

STKSG SEGMENT PARA STACK 'STK'
        DW 20 DUP (?)
STKSG ENDS

DATASG SEGMENT PARA 'DAT'
        A DB 2
        B DB 10
        SONUC DW 0
DATASG ENDS

CODESG SEGMENT PARA 'CD'
        ASSUME CS: CODESG, DS: DATASG, SS: STKSG
        SON PROC FAR
                PUSH DS
                XOR AX, AX
                PUSH AX

                MOV AX, DATASG
                MOV DS, AX
                XOR DX, DX
                XOR CX, CX
                MOV AX, 1
                MOV CL, B
                XOR BX, BX
                MOV BL, A
        L1:
                MUL BX
                LOOP L1
                MOV SONUC, AX
                RETF
        SON ENDP
CODESG ENDS
        END SON
```

<!-- BELİRSİZ: Son iki satır (CODESG ENDS, END SON) karelerde görünmedi; altyazıdaki "end kelimesi ve yanında bir etiket" ve "son isimli yordam" anlatımından kuruldu. -->

Program A sayısı (2), B sayısı (10) ve SONUC adlı bir word tanımlar. AX'e 1 konur, CX'e B kadar döngü sayısı, BX'e A yüklenir. Döngüde her adımda `MUL BX` ile `DX:AX ← AX · BX` yapılır; `LOOP L1` bunu B (10) kez tekrarlar. Yani program $2^{10}$'u hesaplayıp SONUC'a yazar. Python ile kontrol: 1 değeri 10 kez 2 ile çarpılınca AX = 0400h = 1024, DX = 0 olur.

## 4. DEBUG ile Yazmaçların ve Belleğin İncelenmesi

DEBUG, kodun adım adım çalıştırılabildiği, adının söylediği gibi hata ayıklama yapılan bir programdır. `DEBUG deneme.exe` yazılınca `-` işaretli bir komut satırına düşülür. `?` ile komut listesi alınır (ekrandan, 00:50:00):

| Komut | Söz dizimi | İşlev |
|---|---|---|
| assemble | `A [address]` | Belleğe komut yazdırır |
| dump | `D [range]` | Bellek içeriğini gösterir |
| enter | `E address [list]` | Belleğe byte girer |
| go | `G [=address] [addresses]` | Verilen adrese kadar çalıştırır |
| proceed | `P [=address] [number]` | Döngü/çağrıyı tek adımda geçer |
| quit | `Q` | DEBUG'dan çıkar |
| register | `R [register]` | Yazmaçları gösterir ya da değiştirir |
| trace | `T [=address] [value]` | Bir komut yürütür |
| unassemble | `U [range]` | Makine kodunu mnemoniğe çevirir |

Listede başka komutlar da (compare, fill, hex, input, load, move, name, output, search, write) vardır; hoca derste yukarıdakileri inceleyeceklerini söyledi.

### 4.1 R: yazmaçlar ve bayraklar

Program yüklenip henüz hiçbir komut çalışmadan `R` çıktısı şöyleydi (ekrandan, 00:20:00):

```text
AX=FFFF  BX=0000  CX=0062  DX=0000  SP=0028  BP=0000  SI=0000  DI=0000
DS=075A  ES=075A  SS=076A  CS=076E  IP=0000   NV UP EI PL NZ NA PO NC
076E:0000 1E            PUSH    DS
```

DS, SS ve CS'de değerler vardır; EXE programının kesimleri belleğe yerleştirilmiştir. CS:IP ikilisi sıradaki komutu gösterir: 076E:0000 adresinde `1E` makine kodlu `PUSH DS` komutu. Son satırda bu adres, makine kodu ve mnemonik birlikte yazılır.

Bayraklar şöyle okunur: `NV` taşma yok (no overflow), `UP` yön bayrağı ileri, `EI` kesmeler açık (enable interrupt), `PL` sonuç pozitif (işaret bayrağı 0), `NZ` sıfır değil, `NA` yardımcı elde yok, `PO` tek eşlik (parity odd), `NC` elde yok.

Bir yazmacı değiştirmek için `R` ve yazmaç adı yazılır. `R AX` önce AX'in güncel değerini (FFFF) gösterir, sonra yeni değeri sorar; `1111` girilince AX = 1111h olur. Aynı şekilde `R DX` ile DX = 0001 yapıldı. DEBUG'da sayılar onaltılık girilir.

SP burada önemlidir. Hoca SP'nin yığın için ayrılan alanın en uzak (en yüksek) adresini gösterdiğini, yığına bir şey atıldıkça SP'nin küçüleceğini hatırlattı. Bu programda yığına `DW 20 DUP (?)` ile 20 word = 40 byte = 28h ayrıldığı için başlangıçta SP = 0028h'dir.

R'nin temel amacı, her komut çalıştırıldıktan sonra yazmaçlarda oluşan değerleri kontrol etmektir.

### 4.2 T: bir adım yürütme

`T` (trace) bir komut yürütür ve ardından yazmaçları gösterir. `PUSH DS` yürütülünce sıradaki komut `XOR AX, AX` olur ve IP 0'dan 1'e çıkar. Bunun nedeni `PUSH DS`'nin 1 byte'lık bir komut olmasıdır; IP komutun uzunluğu kadar artar. Ekrandaki ilk adımlar (ekrandan, 00:25:00):

| Adım | Komut | Makine kodu | Sonra IP | Sonra SP |
|---|---|---|---|---|
| 1 | `PUSH DS` | `1E` | 0001 | 0026 |
| 2 | `XOR AX, AX` | `33C0` | 0003 | 0026 |
| 3 | `PUSH AX` | `50` | 0004 | 0024 |
| 4 | `MOV AX, 076D` | `B86D07` | 0007 | 0024 |

`XOR AX, AX` sonrası bayraklar `ZR` (sıfır) ve `PE` (çift eşlik) oldu. Yardımda T'ye bir adres de verilebildiği görüldü (`T [=address]`), yani belirli bir adresten de yürütülebilir.

### 4.3 D: bellek dökümü

`D` (dump) bir bellek bölgesini listeler. `D CS:0` yazılınca kod kesiminin başından itibaren makine kodları görülür: `1E` (`PUSH DS`), `33 C0` (`XOR AX, AX`), `50` (`PUSH AX`), `B8 6D 07` (`MOV AX, 076D`). Yani kod kesiminin makine kodu karşılıkları doğrudan görülebilir. Segment değeri sayı olarak da yazılabilir (`D 076E:0000`), ama `CS` yazmak daha pratiktir.

### 4.4 Yığının dump edilmesi

İlk üç komut yığına iki değer attı: `PUSH DS` ile DS'nin o anki değeri 075Ah, `XOR AX, AX` ile sıfırlanan AX'in değeri 0000h. Hoca bunların yığında nasıl görüleceğini sordu.

Yığın kesiminin başlangıç adresini SS gösterir. Yığın kesimi içinde yüksek adres yığının "dibi"dir. İlk atılan değer en yüksek adrese, sonra atılanlar daha düşük adreslere yazılır. Bu yüzden yığına atılanları görmek için kesimin 0 ofsetine değil, SP'nin gösterdiği yere bakılmalıdır; dump o adresten itibaren yükselen adreslere doğru gösterir. Ofset sabit değer olarak yazılır: SP = 0024 olduğu için `D SS:24` (ekrandan, 00:40:00):

```text
-d ss:24
076A:0020              00 00 5A 07-00 00 00 00 00 00 00 00
```

İlk iki byte `00 00`, son atılan AX değeridir. Sonraki iki byte'ta DS değerinin, yani 075Ah'nin görülmesi beklenir, ama `5A 07` görünür.

**Soru:** 07 5A yerine neden 5A 07 görüldü, neyi yanlış yaptık? **Cevap:** Bir öğrenci "uzağa doğru gittiği için 07'yi daha uzakta görmüş" diye önerdi. Doğru açıklama: 8086 veriyi little endian biçiminde saklar; word'ün düşük anlamlı byte'ı düşük adreste, yüksek anlamlı byte'ı yüksek adrestedir. Bu iki byte word olarak okunduğunda değer tam olarak 075Ah'dir, yani bir sorun yoktur.

Yığını dump etmek ileride çok önemli olacak: alt yordamlara yığın üzerinden parametre aktarılan ve yığından değer döndürülen örnekler ile özyinelemeli (recursive) programlar incelenecek. Program doğru çalışmadığında yığının içeriğine bakmak gerekecek.

> **Ders sonrası not:** Hoca yığın çiziminde (ekrandan, 00:30:00) ve iskelet anlatımında PUSH yapılınca SP'nin "2 arttığını" ve SP'nin "sıradaki boş gözü" gösterdiğini söyledi; 00:28:43'te de 24 adresinin "sıradaki boş gözü" gösterdiğini belirtti. 8086'da `PUSH` önce SP'yi 2 azaltır, sonra değeri [SS:SP]'ye yazar; SP her zaman en son yazılan word'ü gösterir. Ekrandaki değerler de bunu doğrular: SP 0028 → 0026 → 0024 diye azaldı ve `D SS:24` ilk iki byte'ta son atılan 0000'ı gösterdi. Hocanın çiziminde yüksek adres aşağıda olduğu için "artı" sözü çizimdeki yönü anlatıyordu; doğru ifade "SP 2 azalır"dır.

## 5. EXE Programının İşletim Sistemine Dönüşü

### 5.1 FAR yordam

Hoca, data segmentteki değişkenlere neden henüz bakılamadığını açıklamak için programın nasıl çalıştığına döndü. Komut satırında `deneme.exe` yazıldığında devrede işletim sistemi vardır. İşletim sistemi denetimi geçici olarak programa devreder; program bitince işletim sisteminde kalınan yere dönülür. Bunun için EXE programlarında iki kural vardır (ekrandan, 00:35:00):

- Ana yordam mutlaka olmalıdır.
- Ana yordam FAR tipinde olmalıdır.

Bir yordamın FAR olması şu demektir: işletim sistemi bir CS1:IP1 adresinde çalışırken program başka bir CS2:IP2 adresinde bulunur. İşletim sistemi programı çağırırken hem CS'ye CS2'yi hem IP'ye IP2'yi yükler. Hem CS'nin hem IP'nin değiştiği çağırmaya FAR yordam çağırma denir. Program fiziksel olarak yakın olsa bile FAR tipinde olduğu için iki yazmaç da değişir. Geri dönerken de CS1 ve IP1 geri yüklenmelidir.

### 5.2 Dönüş adresinin yığına konması

EXE tipi bir program çalıştırıldığında işletim sistemi DS'ye kendi dönüş segment değerini yükler ve programdan o segmentin 0 ofsetine dönmesini bekler. Bu iki tarafça kabul edilmiş bir anlaşmadır. Program bu yüzden şöyle başlar:

```asm
PUSH DS        ; dönüş segment değeri yığına
XOR AX, AX     ; AX = 0
PUSH AX        ; dönüş ofseti 0 yığına
```

### 5.3 RETF

EXE programının dönüşü `RETF` (return far) ile yapılır. `RETF` yığının en üstündeki değeri alıp IP'ye, bir sonrakini alıp CS'ye yükler. Programın başında yığına önce DS, sonra 0000 konmuştu. Program çalışırken yığına bir şey atıldıysa o kadar şey geri çekilmişse, `RETF` satırına gelindiğinde yığının en üstünde 0000 bulunur. `RETF` bunu IP'ye, altındaki dönüş segment değerini CS'ye koyar ve denetim işletim sistemine geçer.

DEBUG'da başlangıçta DS = 075A görülmüştü; bu değer işletim sistemine dönüş segment değeridir. Programın kendi veri kesimi henüz DS'ye yüklenmemiştir. Bu `MOV AX, DATASG` ve `MOV DS, AX` satırlarıyla olur. Segment yazmaçlarına sabit değer atayan bir komut olmadığı için değer önce AX'e alınır, sonra DS'ye kopyalanır; iş iki adımda yapılır. Bu iki satır trace edilince DS = 076D oldu; artık bizim tanımladığımız kesim veri kesimi olarak kullanılıyordu (ekrandan, 00:45:00).

> **Ek bilgi (derste anlatılmadı):** DOS bir EXE'yi yüklerken DS ve ES'ye programın önüne koyduğu Program Segment Prefix (PSP) adlı alanın segmentini verir. PSP'nin 0 ofsetinde `INT 20h` (programı sonlandır) komutu bulunur. Derste de son örnekte `RETF`'ten sonra CS:IP = 075A:0000 olduğu ve orada `CD20 INT 20` komutunun durduğu görüldü (ekrandan, 03:00:00). Hocanın "işletim sistemine dönüş segment değeri" dediği değer büyük olasılıkla bu PSP segmentidir.

## 6. Veri Kesiminin İncelenmesi ve Hizalama Boşluğu

### 6.1 Değişkenleri görmek

**Soru:** Veri kesimindeki değişkenlerimizi nasıl görürüz? **Cevap:** Program başlar başlamaz DS bizim veri kesimimizi göstermez. `MOV AX, DATASG` / `MOV DS, AX` çalıştıktan sonra `D DS:0` ile veri kesiminin 0 ofsetinden itibaren dump edilir.

Dump'ta önce A sayısı `02`, sonra B sayısı `0A` (10) görüldü; ikisi de birer byte. Ardından SONUC word'ü `00 00` olarak 2 byte yer kaplar. Toplam 4 byte. Sonra bir süre ne olduğu bilinmeyen sıfırlar ve ardından tanıdık bir bölge geldi (ekrandan, 00:40:00):

```text
076A:0030  02 0A 00 00 00 00 00 00-00 00 00 00 00 00 00 00
076A:0040  1E 33 C0 50 B8 6D 07 8E-D8 33 D2 33 C9 B8 01 00
```

**Soru:** Bu tanıdık bölge neresidir? **Cevap:** Kod kesiminin kendisidir; `1E 33 C0 50 B8 6D 07` daha önce `D CS:0` ile görülen baytlardır. Bunu adreslerden de doğrulayabiliriz: 076E:0000 adresi, 076D:0010 adresiyle aynı fiziksel adrestir.

Python ile kontrol: 076Dh · 16 + 10h = 076E0h = 076Eh · 16 + 0. Ayrıca 076A:0030 = 076D0h, yani veri kesiminin başı; 076A:0040 = 076E0h, kod kesiminin başı.

### 6.2 Hizalama boşluğu

Değişkenlerden sonraki baytlar anlamsız (çöp) değerlerdir. Bunun nedeni kesim tanımında kullanılan `PARA` kelimesidir. PARA bir hizalama tipidir; kesimin 16'nın tam katı olan bir adresten başlamasını sağlar. Veri kesimi yalnız 4 byte kaplar, ama sonraki kod kesimi PARA hizalı olduğu için bir sonraki 16'nın katına kadar olan alan boş kalır. Byte, word ve page hizalamaları da vardır; bunlar ilerideki bölümde anlatıldı.

### 6.3 Başlangıçta DS:0'da ne var?

Program ilk başlatıldığında `D DS:0` yapılırsa A, B, SONUC görülmez; çünkü DS o anda işletim sisteminin verdiği bölgeyi gösterir. Hoca işletim sistemine dönüş adresinde ne olduğunu `U` ile inceledi ve orada bir `INT 20` kesme çağrısı olduğunu, ondan sonrasının anlamlı olmadığını gösterdi.

## 7. Diğer DEBUG Komutları ve Sonucun Kontrolü

### 7.1 E: belleğe değer girme

`E DS:0` yazılınca adres ve mevcut içerik (A'nın değeri 02) gösterilir, yeni değer istenir. Hoca 12 girdi; `D DS:0` ile tekrar bakılınca değişiklik görüldü. E ile baytlar tek tek değiştirilebilir.

### 7.2 U: makine kodunu mnemoniğe çevirme

Elimizde kaynak kodu olmayan bir nesne dosyası ya da EXE varsa ne yaptığını anlamak için `U` (unassemble) kullanılır. `U CS:0` verilen adresten başlayarak makine kodlarının mnemonik karşılıklarını gösterir.

### 7.3 G ve P

`G` verilen adrese kadar programı baştan çalıştırır. Kod kesiminde LOOP satırının ofseti 1Ch'dir; `G CS:1C` ile program döngünün ilk adımına kadar çalıştı. Döngüyü bitirmek için `P` (proceed) kullanıldı: döngü bitene kadar (B'den dolayı 10 kez) çalıştı ve LOOP'tan sonraki komutta durdu. Hoca bunu görsel hata ayıklayıcılarda bir fonksiyonu içine girmeden çalıştırıp sonucunu görme adımına benzetti.

Python ile ofset kontrolü (ekrandaki makine kodlarından): `1E`(0) `33C0`(1) `50`(3) `B86D07`(4) `8ED8`(7) `33D2`(9) `33C9`(B) `B80100`(D) `8A0E0100`(10) `33DB`(14) `8A1E0000`(16) `F7E3`(1A) `E2FC`(1C) `A30200`(1E) `CB`(21). LOOP 1Ch'de, RETF 21h'dedir; kodun toplam boyu 22h = 34 byte'tır.

### 7.4 A: belleğe komut yazma

`A` ile belleğe doğrudan assembly komutu yazılabilir. Hoca DEBUG'ı dosya vermeden açtı; boş bir bellek bölgesinde, 100h ofsetinden itibaren şu komutları yazdı:

```text
MOV AX, 12
CMP AX, 13
JE 109
NOP
NOP
```

İlk denemede `JE 108` yazılınca atlamanın hemen sonraki satıra düştüğü görüldü. `JE` 106h'de olduğu için hoca araya bir komut daha koydu: eşitlik varsa 109h'ye atlanacak, yoksa 108h'deki `NOP` çalışacak, 109h'de de başka bir `NOP` var. `U CS:100` ile bakılınca yazılan komutlar görüldü; sonraki satırlar bellekte rastgele duran baytların çözülmüş hâliydi ve anlamlı değildi. Hoca bunu emu8086'da satır satır yazmaya benzetti.

Komut uzunlukları adreslerle uyumludur: `MOV AX, 12` 3 byte (100h-102h), `CMP AX, 13` 3 byte (103h-105h), `JE` 2 byte (106h-107h), `NOP` 108h, `NOP` 109h. <!-- BELİRSİZ: Bu bölümün ekranı karelerde yok; adresler ve komutlar altyazıdan alındı. -->

### 7.5 Sonucun kontrolü

Hoca `G CS:21` ile programı RETF satırına kadar çalıştırdı. İşletim sistemine dönmeden durmak önemlidir; döndükten sonra programın veri kesimine erişilemez. Ekrandaki yazmaçlar (ekrandan, 00:55:00):

```text
AX=0400  BX=0002  CX=0000  DX=0000  SP=0024 ...
DS=076D  ES=075A  SS=076A  CS=076E  IP=0021
076E:0021 CB            RETF
```

Beklenen sonuç $2^{10} = 1024$'tür ve 1024 = 400h'dir. SONUC word'ü little endian olarak `00 04` görünür ve word olarak 0400h okunur.

> **Ders sonrası not:** Altyazıda bu yer "1024 değerinin 488 decimale karşılık gelmesi lazım" diye geçiyor; bu, ses tanımanın bozduğu bir cümledir. Doğrusu 1024'ün onaltılık karşılığının 400h olmasıdır; ekranda da AX = 0400 görüldü.

### 7.6 Dump'ın sağındaki karakterler

**Soru:** Dump çıktısının sağındaki yazılar nedir? **Cevap:** Dump edilen baytların ASCII karşılıklarıdır. Bellekte bir karakter dizisi ya da dosya adı varsa hemen görülebilsin diye yardımcı olarak gösterilir. Hoca bunu göstermek için veri kesiminin başına `STR DB 'MERHABA'` ekledi (ekrandan, 01:20:00). Dump'ta `4D 45 52 48 41 42 41` baytları ve sağda `MERHABA` yazısı göründü; ardından A (`02`), B (`0A`) ve SONUC (`00 04`) geldi (ekrandan, 00:55:00).

## 8. Sözde Komutlara Giriş

Sözde komutlar (pseudo-instructions) kendi başlarına makine kodu karşılığı olmayan kelimelerdir. 8086 komut kümesinin değil, assembler'ın özel kelimeleridir. Örneğin önceki haftalarda sık kullanılan `DB` ve `DW`: Intel 8086 komut kümesinde DB ya da DW diye bir komut yoktur, ama bunlar veri tanımlamamızı sağlar. Sözde komutların etkisi derleme anında (compile time) ortaya çıkar; çalışma anında (run time) etki edenler yalnız komutlardır (instructions). Sözde komutlar kodun düzenlenmesi, daha etkili ve pratik yazılması için vardır.

Slayttaki gruplar şunlardır (ekrandan, 01:15:00):

| Grup | Sözde komutlar |
|---|---|
| LST uzantılı dosyanın düzenlenmesi | `PAGE`, `TITLE` |
| Program kesim düzenlemesi | `SEGMENT/ENDS`, `ORG`, `ASSUME` |
| Veri tanımlamaları | `DB`, `DW`, `DD`, `DQ`, `EQU`, `DUP`, `TYPEDEF`, `PTR`, `LABEL` |
| Yordam düzenleme | `PROC/ENDP`, `EXTRN`, `PUBLIC` |
| MACRO düzenleme | `MACRO/ENDM`, `INCLUDE`, `LOCAL` |
| Diğer | `LENGTH`, `TYPE`, `SIZE`, `OFFSET`, `SEG`, `END` |

### 8.1 PAGE ve TITLE

`PAGE` yanına iki parametre alır ve oluşacak LST dosyasının sayfa düzenini belirler. `deneme.asm`'nin başında `PAGE 80, 60` vardı. Hoca bunu her sayfada 80 satırdan sonra sayfa sonu, her satırda 60 karakterden sonra satır sonu gelecek diye açıkladı. LST'yi yazdırma önizlemesinde göstermeyi denedi; Notepad'in yazı tipi büyütüldüğü için çıktı beklenen biçimde olmadı. Bu ayarın gerçek etkisi yazıcıdan çıkan çıktıda görülür; yani şekil ve gösterimle ilgili bir düzenlemedir.

`TITLE` LST dosyasına programın başlığını ya da açıklamasını yazdırır.

## 9. Kesim Tanımı: SEGMENT ve ENDS

`deneme.asm` içinde üç kesim tanımı vardır. Bir kesim tanımının yapısı:

```text
isim SEGMENT hizalama [birleştirme] 'sınıf'
        ...
isim ENDS
```

- İsim keyfidir (yıldız, A, B, ne olursa).
- `SEGMENT` kelimesi bunun bir kesim olduğunu belirtir.
- Sonra hizalama kelimesi gelir.
- Yığın kesimi isteniyorsa `STACK` kelimesi yazılır; bu durumda program belleğe yüklenince SS bu kesimi gösterecek biçimde yüklenir.
- Tırnak içindeki son kelime sınıf (class) adıdır. Sınıf adı da keyfidir; kesimlerin birleştirilmesinde rol oynar.
- Kesim, aynı isim ve `ENDS` ile kapatılır.

Yığın kesiminin içinde bir değer tanımı yoktur, yalnız yer ayrılır. Hoca güncel assembler'larda `.tiny`, `.flat` gibi farklı tanımlarla yığın boyutunun ayrıca belirlenebildiğini, ama derste bu notasyonun kullanılacağını söyledi. Veri kesimi genellikle değişkenlerin tanımlandığı yerdir; içinde `DB`, `DW` gibi sözde komutlar bulunur.

### 9.1 Hizalama

Daha önceki derslerde 8086'nın bir okuma/yazma çevriminde çift adresten 16 bitlik işlemi, çift ya da tek adresten 8 bitlik işlemi tek seferde yapabildiği; tek adresten 16 bitlik işlemin ise iki çevrim sürdüğü anlatılmıştı. Bu yüzden verinin ve programın çift adreslere hizalı olması programı hızlandırır. Hizalama tipleri bu nedenle vardır (ekrandan, 01:25:00):

| Hizalama | Kesimin başladığı adres |
|---|---|
| `BYTE` | Sıradaki ilk boş adres |
| `WORD` | Sıradaki çift adres |
| `PARA` | Sıradaki 16'nın tam katı |
| `PAGE` | Sıradaki 256'nın tam katı |

İşletim sistemi kesimi yerleştirirken sıradaki yeterli büyüklükteki boş alanı arar; WORD'de o adres çift değilse sonraki çift adrese, PARA'da 16'nın katına, PAGE'de 256'nın katına geçer.

### 9.2 Birleştirme

Bir EXE programında her kesim ayrı bir bellek bölgesi tutar. Hocanın örneğinde yazılan kod 20-50 byte mertebesindeydi, başlıklarla bile kilobayta yaklaşır; buna karşılık ayrı kesimler kullanmak verimsizdir. Bu yüzden farklı nesne dosyalarındaki kesimlerin birleştirilmesi gündeme gelir. Birleştirme kelimeleri (ekrandan, 01:25:00):

- `PUBLIC`: farklı dosyalardaki aynı isimli kesimleri bellekte aynı kesim içinde peş peşe yerleştirir. Hoca bunu C'deki struct'a benzetti.
- `COMMON`: aynı isimli kesimlerin aynı adresten başlamasını sağlar. C'deki union'a benzer.
- `STACK`: kesimi yığın mantığında (LIFO) tanımlar.
- `AT #####`: kesimin belirli bir adrese yerleşmesini sağlar.

> **Ders sonrası not:** Hoca bir yerde her kesimin "normalde 64 KB'lık bir alana tekabül ettiğini" ve EXE'nin "üç tane 64 KB'lık alanı işgal ettiğini" söyledi. Biraz sonra kendisinin de anlattığı gibi kesimlerin boyutu tanımlara göre belirlenir; 64 KB bir kesimin ulaşabileceği en büyük boyuttur. Bu programda MAP dosyası yığını 28h, veriyi 4h, kodu 22h byte olarak gösterdi.

## 10. Segment Yazmaçlarının Hangi Kesimi Gösterdiği

Hoca kodda üç kesim tanımı ve bir de `END` kelimesiyle yanındaki etiket bulunduğunu hatırlattı ve her kesimin nasıl rol kazandığını sordu:

- **Yığın kesimi:** `STACK` kelimesi bulunan kesimdir. Program belleğe yüklenince SS onu gösterir. Bu baştan bellidir.
- **Veri kesimi:** Program yüklendiğinde DS bu kesimi göstermez. `MOV AX, DATASG` / `MOV DS, AX` yürütüldükten sonra bu kesim veri kesimi olur.
- **Kod kesimi:** `END` kelimesinden sonra yazılan etiket hangi kesimin içindeyse CS o kesimin başlangıcını gösterecek biçimde yüklenir.

`deneme.asm`'de `END SON` yazıldığı için SON yordamının içinde bulunduğu CODESG kod kesimidir. `SON PROC FAR`, `ASSUME` ve kesim tanımı sözde komut olduğundan makine kodu yoktur; etiketten sonra gelen ilk komut `PUSH DS`'dir. Yani `END`'den sonraki etiket hem ana yordamı hem de ilk çalıştırılacak komutu (programın giriş noktasını) belirtir.

## 11. EXE ve COM Programlarının Bellek Yerleşimi

### 11.1 EXE

EXE tipi program bellekte üç kesim kullanır: yığın, veri ve kod. Her birinin boyutu bellidir.

**Soru:** `DW 20 DUP (?)` yığın için kaç byte ayırır? **Cevap:** 40 byte; her biri word olan 20 değer. Bir öğrenci de 40 cevabını verdi.

Veri kesiminin boyutu tanımlanan veriye, kod kesiminin boyutu yazılan koda bağlıdır.

### 11.2 COM

COM tipi program tek bir kesim kullanır (en fazla 64 KB). Kesimin başında başlık (header) bilgileri için 100h byte yer ayrılır, bu yüzden kod 100h adresinden başlamalıdır. Bunun için komutlardan önce `ORG` (origin) sözde komutu kullanılır: `ORG 100H` bundan sonraki kodun 100h adresinden itibaren yerleşeceğini belirtir. Yığın kesimin sonundan geriye (yukarıya) doğru büyür; kodla yığın arasındaki alan veri için kullanılır.

Bu düzende kod değiştikçe verinin ofseti yer değiştirir; bu hata ayıklama için iyi değildir. Bu yüzden derste farklı bir yaklaşım kullanılacak: başlıktan sonra önce veri yerleştirilecek, sonra kod gelecek ve bunun için özel işlemler yapılacak. Bu COM programları anlatılırken ele alınacak.

> **Ders sonrası not:** Altyazıda "100H decimal kadarlık" diye geçiyor; 100h onaltılıktır ve onluk 256 byte'a karşılık gelir.

### 11.3 ASSUME

`ASSUME CS: CODESG, DS: DATASG, SS: STKSG` kesim tanım isimlerinin kodda geçtiğinde hangi segment yazmacına karşılık geldiğini assembler'a bildirir (slayt: "Kesim tanımlarının ne amaçla yapıldığı ve başlangıç adreslerini belirler", ekrandan, 01:30:00).

Hoca sonraki bir soruya cevap verirken bunu açtı: `ASSUME` kullanılmasaydı `MOV AX, DATASG` içindeki DATASG bir etiket gibi anlam kazanırdı ve yerine bir ofset değeri konmaya çalışılırdı. Oysa burada 20 bitlik adresin segment kısmı (yüksek anlamlı kısım) AX'e konmak istenir. ASSUME sayesinde DATASG bir segment adresi olarak değerlendirilir. Benzer şekilde `MOV CL, B` satırında B bir etikettir; doğru tanımlama olmasaydı etiketin değeri atanmış gibi olurdu.

Hoca bütün sözde komutların derleme anında, komutların ise çalışma anında etki ettiğini burada bir kez daha hatırlattı.

## 12. Veri Tanımlama Sözde Komutları

### 12.1 DB

`DB` (define byte) 0-255 arası değerleri tek tek tanımlar. Sayı herhangi bir ek olmadan yazılırsa onluk kabul edilir. Onaltılık tanım yapmak için sayının sonuna `H` yazılmalı; sayının en yüksek anlamlı basamağı bir harfse başına mutlaka 0 konmalıdır. 0 konmazsa assembler bunu bir etiket olarak değerlendirir.

**Soru:** Başa 0 koyunca sayı 12 bite mi çıktı? **Cevap:** Hayır, sayı yine 8 bittir; 0 yalnız bunun onaltılık bir sabit olduğunu belirtmek içindir.

`DB`'den sonra virgülle ayrılmış değerler yazılırsa dizi tanımlanır. Tırnak içinde yazılan metin karakter dizisi tanımlar. <!-- BELİRSİZ: DB slaytındaki örnek satırlar karelerde görünmedi; kurallar altyazıdan alındı. -->

### 12.2 DW

`DW` (define word) 0000h-0FFFFh arası değerleri tanımlar. Slayttaki örnek (ekrandan, 01:35:00):

```asm
Diziw DW 5, 10, 20
```

Diziw 0510h adresinden başlıyorsa bellek şöyledir:

| Adres | İçerik |
|---|---|
| 0510h | 05h |
| 0511h | 00h |
| 0512h | 0Ah |
| 0513h | 00h |
| 0514h | 14h |
| 0515h | 00h |

Düşük adreste düşük anlamlı byte vardır. İlk word 0005h, ikincisi 000Ah (10), üçüncüsü 0014h (20)'dir. Python ile kontrol: 5, 10, 20 değerlerinin little endian word dizilimi `05 00 0A 00 14 00`'dır.

> **Hocanın vurgusu:** Bir veri kesimi tanımı assembly kodu olarak verildiğinde, bu kod çalıştırılıp DEBUG'da veri kesimi dump edilse hangi baytların görüleceğini (yani veri kesiminin makine kodu karşılığını) yazabilmek gerekir. Hoca bu tür soruyla karşılaşılabileceğini önceden söyledi.

### 12.3 DD ve DQ

`DD` (define double word) 32 bitlik, 00000000h-0FFFFFFFFh arası değerleri tanımlar. `DQ` (define quad word) 64 bitlik, yani 8 byte'lık bellek alanı ayırır.

### 12.4 EQU

`EQU` değişken tanımlamaz. Derlemeden önce bütün `EQU` adları uygun sabit değerle değiştirilir (ekrandan, 01:40:00). Hoca bunu C'deki `#define` makrosuna benzetti: derleme öncesinde tanımlı ad her geçtiği yerde verilen sayıyla değiştirilir. Örneğin bir adres bölgesiyle çalışırken o adresi her yerde hatırlamak yerine ona bir ad verilir ve kodda o ad kullanılır.

### 12.5 DUP

`DUP` (duplicate) tekrarlı veri tanımı için kullanılır. Slayttaki örnekler (ekrandan, 01:40:00):

```asm
Dizi1  DB 15 DUP (0)         ; 15 adet değeri 0 olan byte ayırır
Matris DB 3 DUP (4 DUP (8))  ; 3x4 adet değeri 8 olan byte ayırır
Dizi2  DW 10 DUP (?)         ; 10 adet word ayırır, ilk değer olarak
                             ; o anki bellek içeriğini kullanır
```

`Matris` satırında iki `DUP` iç içedir. İçteki `4 DUP (8)` dört byte yer ayırır ve her birine 8 değerini verir: 8, 8, 8, 8. Dıştaki `3 DUP (...)` bu dört değeri üç kez tekrarlar. Bu, 3×4 boyutunda bir matris tanımlayıp her elemanı 8 ile başlatmaya eşdeğerdir: 12 eleman, her biri byte, toplam 12 byte. Bellekte yerleşim C'deki dizilerde olduğu gibi satır öncelikli (row first) olur: ilk satır, ardından ikinci satır, adresler ardışık.

`Dizi2` satırında `?` kullanıldığı için yalnız yer ayrılır, ilk değer verilmez. 10 word, yani 20 byte'lık alan ayrılır.

### 12.6 TYPEDEF ve PTR

`TYPEDEF` var olan veri tiplerinden biriyle kendi adlandırdığımız yeni bir tip tanımlamamızı sağlar. Tip tanımından sonra değişken, `DB`/`DW`'deki gibi değişken adı, tip adı ve değerle tanımlanabilir.

`PTR` bir komutta işlem boyutu belli değilse onu açıkça belirtmek için kullanılır: `WORD PTR`, `BYTE PTR`.

> **Hocanın vurgusu:** emu8086, `INC [100H]` gibi bir komutu varsayılan olarak byte işlemi kabul eder. DOSBox'taki MASM ise "tip belirtilmesi gerekir" diye hata verir. Derste referans DOSBox, yani Microsoft Assembler'dır. emu8086 yalnız denemeleri hızlı yapmak için bir arayüzdür; kod DOSBox'ta çalışıyorsa doğru, çalışmıyorsa hatalıdır.

`PTR`'nin ikinci kullanımı `FAR PTR` ve `NEAR PTR`'dir. Bunlar yordamların nasıl çağrılacağını ya da dallanmanın nasıl yapılacağını belirtir; örneğin FAR tipinde bir `JMP` yapılacaksa bu açıkça yazılmalıdır.

## 13. LABEL

`LABEL` bir veri tanımına farklı bir tiple erişmek için kullanılır. Önceden aynı iş LEA ile yapılmıştı: bir double word'ün başlangıç adresi LEA ile BX'e alınıp BX artırılarak ona byte byte ya da word word erişilebiliyordu. Ama LEA çalışma anında etki eden bir komuttur. Derleme anındaki birebir karşılığı `LABEL` sözde komutudur. Slayttaki örnek (ekrandan, 01:45:00):

```asm
Yenib LABEL BYTE
Sayiw DW 2535H
Yeniw LABEL WORD
Sayib DB 45H
Sayic DB 55H

MOV AX, Yeniw
MOV BL, Yenib
```

| Adres | İçerik | Etiketler |
|---|---|---|
| 0000h | 35h | Sayiw, Yenib |
| 0001h | 25h | |
| 0002h | 45h | Sayib, Yeniw |
| 0003h | 55h | Sayic |
| 0004h | .. | |

İşleyiş adım adım:

- `Yenib LABEL BYTE`: sıradaki boş adres 0 olduğu için Yenib 0 adresini gösterir. Byte tipindedir. Kendisi yer kaplamaz, makine kodu yoktur.
- `Sayiw DW 2535H`: 0 ve 1 adreslerine yerleşir (little endian: 35h, 25h).
- Normalde Sayiw bir word değişkenidir ve 8 bitlik bir yazmaca atanamaz. Ama Yenib byte tipinde bir değişken adı gibi kullanılabilir ve Sayiw'nin düşük anlamlı byte'ını gösterir. `MOV BL, Yenib` → BL = 35h.
- `Yeniw LABEL WORD`: sıradaki boş adres 2'dir; Yeniw 2 ve 3 adreslerini kapsayan bir word etiketidir.
- `Sayib DB 45H`, `Sayic DB 55H`: 2 ve 3 adreslerine yerleşir. Sayib AL'ye atanabilir, ama AX'e atanamaz; kip (tip) hatası verir.
- Bu iki byte word olarak okunursa little endian biçiminde 5545h'dir. Bu word'ü kullanmak için Yeniw kullanılır: `MOV AX, Yeniw` → AX = 5545h.

Python ile kontrol: `45 55` baytları little endian word olarak 5545h'dir; Sayiw'nin düşük byte'ı 35h'dir.

## 14. Yordam ve Makro Sözde Komutları

### 14.1 PROC ve ENDP

Bir yordamın başlangıcı `PROC`, bitişi `ENDP` ile belirtilir. `deneme.asm`'de `SON PROC FAR` ile FAR tipinde SON adlı bir yordam vardır; `SON ENDP` ile kapanır.

> **Hocanın vurgusu:** EXE tipi programlarda mutlaka bir ana yordam olacak ve bu ana yordam FAR tipinde olacak. Bu kesin kuraldır.

### 14.2 EXTRN ve PUBLIC

Hoca iki dosyalı bir örnek çizdi. 1.asm EXE şablonunda bir dosyadır ve içindeki F1 fonksiyonu F2 adlı bir fonksiyonu çağırır. F2 bu dosyada tanımlı değildir; başka bir dosyadan kullanılacağını belirtmek için 1.asm'de `EXTRN F2` yazılır. F2, 2.asm'de tanımlıdır; bu dosyadan dışarıya kullandırılabilmesi için orada `PUBLIC F2` yazılır. İki dosya ayrı ayrı derlenince iki nesne dosyası oluşur. Bunlar bağlanınca oluşan EXE, F2'yi diğer nesne dosyasından çağıracağını `EXTRN` ve `PUBLIC` sayesinde bilir. Bu kural hem değişkenler hem fonksiyonlar için geçerlidir; ileride tekrar görülecek.

### 14.3 MACRO, ENDM, INCLUDE ve LOCAL

Makro tanımı `MACRO` ile başlar, `ENDM` ile biter. `INCLUDE` başka bir dosyadaki makroyu koda yüklemek için kullanılır.

Makrolar hatırlanırsa: her çağrıldığında makro kodu çağrıldığı yere kopyalanır ve kod büyür. Makro içinde bir etiket varsa, makro her çağrıldığında bu etiket de kopyalanır ve aynı etiket defalarca geçer. Bu normalde "etiket daha önce tanımlı" hatasıyla sonuçlanır. Etiket makro içinde `LOCAL` kelimesiyle tanımlanırsa assembler makronun her kopyasında o etiketi benzersiz bir adla değiştirir ve tekrarlı etiket sorunu oluşmaz.

## 15. LENGTH, TYPE, SIZE, OFFSET, SEG ve END

Dizi tanımlarıyla ilgili üç sözde komut, şu tanım üzerinden anlatıldı:

```asm
TABLO DW 15 DUP (0)
MOV AX, LENGTH TABLO   ; AX = 15
MOV BX, TYPE TABLO     ; BX = 2
MOV DX, SIZE TABLO     ; DX = 30
```

TABLO bir adrestir; gösterdiği şey word tipinde bir değerdir ve bu adresten itibaren 15 word yer ayrılıp hepsi 0 ile başlatılmıştır.

- `LENGTH`: dizinin tipine bakmadan kaç elemandan oluştuğunu verir: 15.
- `TYPE`: her elemanın boyutunu verir; word olduğu için 2.
- `SIZE`: diziye toplam kaç byte ayrıldığını verir: 15 · 2 = 30.

> **Ders sonrası not:** Hoca bu üç komut için bir yerde "runtime sırasında etki gösteriyor, compile time sırasında herhangi bir karşılıkları yok" dedi. Bu ters söylenmiştir. Sözde komut oldukları için derleme anında hesaplanırlar ve makine kodu karşılıkları yoktur; hoca da hemen sonra `MOV AX, LENGTH TABLO` satırının assembler'a `MOV AX, 15` olarak gönderildiğini anlattı.

Diğer sözde komutlar (ekrandan, 01:55:00):

- `OFFSET`: derleme öncesi değişken için ofset değerini döndürür. LEA de bir değişkenin tanımlı olduğu kesimin başından ne kadar uzakta olduğunu, yani adresini verir; ama program çalışırken. OFFSET bunun derleme anındaki birebir karşılığıdır.
- `SEG`: etiketin içinde yer aldığı kesimin segment değerini verir.
- `END`: ilk çalıştırılacak yordamı belirler. Programın giriş etiketiyle birlikte kullanılır. END'den sonraki etiket ya da yordam hangi kesimdeyse o kesim kod kesimi olur (CS onun segment değeriyle yüklenir) ve bu etiket ana yordamı belirtir.

## 16. Sözde Komutlar Derleme Anında Ne Yapar: LST ve MAP Dosyaları

### 16.1 Önişlemciye benzetme

**Soru:** Sözde komutların makine kodu karşılığı yoksa nasıl çalışırlar? **Cevap:** Hoca bunu C'deki makrolara ve önişlemeye (preprocessing) benzetti. C'de kod derleyiciye verilmeden önce bazı işlemler yapılır; örneğin `#include` ile verilen başlık dosyası kaynak kodun başına eklenir ve öyle derleyiciye verilir. Burada da assembler'a gitmeden önce benzer işlemler olur. `OFFSET` kullanılan yerde değişkenin tanımlı olduğu veri kesiminin başından itibaren kaçıncı ofsette olduğu hesaplanır ve OFFSET kelimesinin yerine bu sayı konur. Örneğin değişkenden önce iki tane `DB` varsa ofsetinin 2 olduğu hesaplanır ve yerine 2 konur. LEA gibi bir makine komutu konmaz. Aynı şekilde `MOV AX, LENGTH TABLO` yerine 15 hesaplanıp `MOV AX, 15` olarak assembler'a gönderilir.

### 16.2 Kesim boyutunu görmek

**Soru:** Kod kesiminin boyutunu DOSBox'ta görebilir miyiz? **Cevap:** İki yoldan görülebilir.

Birincisi LST dosyasıdır. LST her satırın ofsetini ve makine kodunu gösterir (ekrandan, 01:10:00):

```text
0000            STKSG SEGMENT PARA STACK 'STK'
0000  0014[             DW 20 DUP (?)
        ????
               ]
0028            STKSG ENDS
0000            DATASG SEGMENT PARA 'DAT'
0000  02                A DB 2
0001  0A                B DB 10
```

Yığın kesimi 0 ofsetinden başlar, 20 (14h) word, yani 40 byte'tır; 40'ın onaltılık karşılığı 28h olduğu için kesim 28h'de biter. Veri kesimi 0'dan 4'e gider: A bir byte, B bir byte, SONUC iki byte, toplam 4 byte. Kod kesimi 34 byte yer kaplar.

İkincisi bağlama sırasında üretilen MAP dosyasıdır. Orada da kod kesimi 22h, veri kesimi 4h, yığın kesimi 28h boyutunda görünür.

Python ile kontrol: 28h = 40, 22h = 34.

## 17. EXE Tipi Program İskeleti

İkinci aradan sonra EXE tipi programların iskelet şablonu incelendi. Hoca önce EXE ve COM farkını hatırlattı: uzantıya göre 8086'da EXE ve COM olmak üzere iki tip program vardır. EXE üç kesim kaplar ve her kesimin boyutu tanımlara göre belirlenir. COM tek kesim kullanır; başta 100h'lık başlık, ardından kod, kesimin sonundan yukarıya doğru yığın, kod ile yığın arasında veri bulunur.

Slayttaki iskelet (ekrandan, 02:15:00):

```asm
STACKSG SEGMENT PARA STACK 'STACK'
        DW 32 DUP(?)
STACKSG ENDS

DATASG SEGMENT PARA 'DATA'
SAYI    DB ?
ELEMAN  DW ?
DATASG ENDS

CODESG SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DATASG
        MOV DS, AX

        RETF
BASLA   ENDP
CODESG  ENDS
        END BASLA
```

İskelet dört bölümden oluşur: yığın kesimi, veri kesimi, kod kesimi ve `END` ile ardından gelen etiket.

### 17.1 Yığın kesimi

Bu kesimi yığın kesimi yapan şey `STACK` kelimesidir. Kesim adı keyfidir. Yığın için ayrılan yer EXE programında baştan bellidir ve çok küçük olmamalıdır. Boyuta karar vermek için yığının ne için kullanıldığını hatırlamak gerekir:

- Bir alt yordam çağrıldığında ya da ana yordama veya işletim sistemine dönülürken dönüş değerlerinin saklanması.
- PUSH/POP ile geçici bellek alanı olarak kullanım; örneğin iç içe iki döngüde CX'i yığına atıp iç döngü bitince geri çekmek.
- Parametre aktarımı: alt yordamı çağırmadan önce gönderilecek değerler yığına atılır, alt yordam parametrelerin yığından geldiğini bilerek onları okur, hatta yığından değer döndürebilir.

Özyinelemeli (recursive) bir yapı varsa yığın en az en derin iç içe çağrıyı karşılayacak boyutta olmalıdır. Böyle bir yapı yoksa çok büyük olmayan ama kıtı kıtına da olmayan bir alan ayrılır.

Slayttaki tanımda `DW 32 DUP(?)` ile 32 word, yani 64 byte ayrılmıştır. Yığın için ayrılan alan mutlaka çift sayıda byte olmalıdır, çünkü PUSH ve POP word ile çalışır. `DW` kullanılıyorsa sorun yoktur, sonuç zaten 2'nin katıdır; `DB` ile yer ayrılıyorsa verilen sayı çift seçilmelidir.

### 17.2 Veri ve kod kesimi

Kesimlerin bitişi `ENDS` ile işaretlenir. Veri kesiminde değişkenler tanımlanır. Kod kesiminde en az bir FAR tipinde yordam olmalıdır ve bu, EXE programının ana yordamıdır. FAR yordamın dönüşü mutlaka `RETF` ile olmalıdır.

İskeletin `RETF`'ten yukarısı kendi kodumuzu yazacağımız bloktur. Program içinde yığına ne atılıyorsa uygun sırada geri çekilmelidir ki `RETF` satırına gelindiğinde yığının en üstünde 0, altında dönüş segment değeri bulunsun. `MOV AX, DATASG` / `MOV DS, AX` satırları veri kesimini kullanılabilir yapar; bu da segment yazmacına doğrudan sabit atanamadığı için iki adımda yapılır.

**Soru:** AX'i de push etmemiz gerekiyor mu? **Cevap:** Hayır, AX'in eski değerini saklamaya gerek yoktur. Gereken şudur: program başlar başlamaz DS'deki değeri yığına atmak, bir de yığına 0 değeri atmak. `XOR AX, AX` AX'te 0 oluşturur, `PUSH AX` de bu sıfırı yığına atar. İşletim sistemine dönüş için yığına başka bir şey atılması gerekmez.

### 17.3 RETF'in yığından değer çekmesi

Hoca yığını yeniden çizerek anlattı: yığın kesiminin bir ucu en yüksek, diğer ucu en düşük adrestir. PUSH yapıldıkça SP'nin değeri küçülür, POP yapıldıkça büyür. Boş bir yığında SP yığının dışındaki bir değerle başlar. `PUSH DS` ile DS değeri yığının dibine, `PUSH AX` ile 0000 onun üstüne yazılır. Program akışında yığına atılanlar sırası gelince çekilir. `RETF` satırına gelindiğinde önce üstteki 0000 alınıp IP'ye, sonra alttaki değer alınıp CS'ye konur. Yani ilk çekilen 0 değeri, ikinci çekilen işletim sistemine dönüş segment değeridir. Hoca bir ara "DX" diye söylediği yeri "DX değil, programa girerken DS'de olan değer" diye düzeltti.

> **Ders sonrası not:** Hoca burada da PUSH'ta "stack pointer 2 artıyor", RETF'te "önce stack pointer 2 azaltılıyor, sonra çekiliyor" dedi. 8086'da sıra tersidir: PUSH'ta SP önce 2 azalır sonra yazılır; POP ve RETF'te önce [SS:SP] okunur sonra SP 2 artar. Ekranda RETF öncesi SP = 0024, RETF sonrası SP = 0028 görüldü (ekrandan, 03:00:00).

### 17.4 END

`RETF`'ten sonra yordamın bitişi (`ENDP`), sonra kod kesiminin bitişi (`ENDS`) gelir. En son `END` kelimesi ana yordamı gösterir. BASLA etiketi hangi kesimdeyse o kesim kod kesimi olur; bu etiket hem ana yordamı hem kodun giriş adresini belirtir. Kod kesiminde birden fazla yordam olabilir, hepsi FAR tipinde de olabilir; ilk çalıştırılacak olan `END`'den sonra yazılan etiketteki yordamdır.

COM programlarının iskeleti sonraki haftalarda ele alınacak.

## 18. Örnek: İki 16 Bitlik Sayının Toplamını 32 Bitlik Değişkende Saklamak

### 18.1 Problem ve plan

Hoca problemi metin dosyasına yazdı:

> İki adet 16 bitlik sayının toplamını hesaplayıp sonucu 32 bitlik bir değişkende saklayan EXE tipi assembly programını yazınız.

Bu daha önce yapılmış bir problemdi, ama bu kez iskelete uygun, düzgün biçimde yazılacaktı. Plan beyaz tahtaya çizildi (ekrandan, 02:35:00):

- Yığın kesimi: yalnız yer ayrılacak. Boyut, problemdeki fonksiyon çağrıları ve parametre aktarımına göre hesaplanır; burada alt yordam ya da özyineleme olmadığı için küçük ama yeterli bir değer yeter.
- Veri kesimi: iki 16 bitlik sayı `DW` ile (ASAY, BSAY), sonuç `DD` ile (SONUC) tanımlanacak.
- Kod kesimi: ana yordam; içinde işletim sistemine dönüş kısmı, DS tanımı ve kod bloğu. Ardından yordamın ve kesimin kapanması.
- `END ana`: giriş noktası.

Programda kullanıcıdan girdi almaya gerek yoktur. Komut satırından girdi almak için DOS kesmelerinden birini çağırmak gerekir; bu ileride görülecek. Şimdilik veri kesimindeki değişkenler kullanılıp sonuç yine bir değişkene yazılacak.

### 18.2 Kesim tanımları

Yığın kesimine STSG adı verildi, BYTE hizalama, `STACK` kelimesi ve STSGM sınıf adı ile tanımlandı; içine `DW 20 DUP(?)` ile 20 word (40 byte) yer ayrıldı. `?` yalnız yer ayırmak için yeterlidir. Veri kesimine DTSG adı, WORD hizalama ve DTSGM sınıf adı verildi. Kod kesimine CDSG adı, PARA hizalama ve CDSGM sınıf adı verildi. `ASSUME CS: CDSG, DS: DTSG, SS: STSG` yazıldı. Ana yordamın adı ANA oldu: `ANA PROC FAR` ... `RETF` ... `ANA ENDP`.

### 18.3 Kod bloğu

İşletim sistemine dönüş için `PUSH DS`, `XOR AX, AX`, `PUSH AX`; veri kesimi için `MOV AX, DTSG`, `MOV DS, AX` yazıldı.

**Soru:** İki bellek bölgesindeki değerleri nasıl toplarız? **Cevap:** İki bellek işlenenini toplayan bir assembly komutu yoktur. Bir öğrenci yazmaç üzerinden yapmayı önerdi: `MOV AX, ASAY` ile A sayısı AX'e alınır, `ADD AX, BSAY` ile B sayısı bellekten eklenir. 8086 16 bitlik işlemi destekler, ama sonucu 32 bit olarak saklamak programcının işidir.

AX'teki toplam 32 bitlik sonucun düşük anlamlı word'üdür. Toplama sonucunda elde oluşabilir de oluşmayabilir de; iki durum aynı kodla çözülmelidir. Önce düşük word SONUC'a yazılır. Bunun için `LEA BX, SONUC` ile SONUC'un başlangıç adresi BX'e alınır, sonra `MOV [BX], AX` ile BX'in gösterdiği adrese AX yazılır.

**Soru:** Elde varsa bunu sonucun yüksek anlamlı word'üne nasıl yazarız? **Cevap:** Elde yoksa yüksek word 0 kalmalıdır; ilk değer zaten 0 olduğu için hiçbir şey yapmamak yeter. Elde varsa yüksek word 1 olmalıdır. Yüksek word BX'ten 2 adres ötededir. İki yol konuşuldu:

- `ADC` ile: `ADC WORD PTR [BX+2], 0`. Elde ile toplama yapıldığı için elde varsa 1 eklenir, yoksa değişmez.
- Koşullu dallanma ile: elde varsa artırmak (`INC`), yoksa hiçbir şey yapmamak.

Bir öğrenci `JC` (jump carry) önerdi. Hoca koşullu dallanmalardan şunu hatırlattı: koşul yanlış (false) kol üzerinden yazılırsa tek dallanma komutu yeter, doğru (true) kol üzerinden yazılırsa iki dallanma gerekir. Beyaz tahtadaki akış (ekrandan, 02:40:00): "carry = 1" koşulu; doğru kolda `INC`, yanlış kolda hiçbir şey; iki kol birleşip devam ediyor. Bu yüzden `JNC L1` yazıldı: elde yoksa doğrudan L1'e, yani `RETF`'e gidilir; varsa bir sonraki satırdaki artırma yapılır. L1'den sonra `RETF` gelmesinde sakınca yoktur.

Hoca iki yolu da denemek istedi; `ADC` satırını yorum satırı yaptı ve `INC` yolunu kullandı.

### 18.4 Derleme hatası

İlk derlemede MASM 29. satırda (`INC [BX+2]`) hata verdi.

**Soru:** Hata nedir? **Cevap:** Bir öğrenci "WORD PTR mi yazmamız lazım?" diye sordu ve doğru cevap buydu. Bellek adresi artırılıyor, ama işlemin byte mı word mü olduğu belli değil. Bir öğrencinin önerdiği `ADD [BX+2], 1` de aynı hatayı verirdi, çünkü orada da bir adresle sabit toplanıyor ve işlem tipi belli değil. `ADC [BX+2], 0` için de aynısı geçerlidir. Satır `INC WORD PTR [BX+2]` olarak düzeltilince program derlendi.

Kodun son hali (ekrandan, 02:35:00, 02:40:00, 03:00:00):

```asm
STSG SEGMENT BYTE STACK 'STSGM'
        DW 20 DUP(?)
STSG ENDS

DTSG SEGMENT WORD 'DTSGM'
        ASAY DW 0F000H
        BSAY DW 0E000H
        SONUC DD 0
DTSG ENDS

CDSG SEGMENT PARA 'CDSGM'
        ASSUME CS: CDSG, DS: DTSG, SS: STSG

        ANA PROC FAR

                PUSH DS
                XOR AX, AX
                PUSH AX

                MOV AX, DTSG
                MOV DS, AX

                LEA BX, SONUC
                MOV AX, ASAY
                ADD AX, BSAY
                MOV [BX], AX
                ;ADC [BX+2], 0
                JNC L1
                INC WORD PTR [BX+2]
L1:
                RETF
        ANA ENDP

CDSG ENDS

        END ANA
```

<!-- BELİRSİZ: İlk altı satır karelerde tam görünmedi. Yığın kesiminin ilk satırı pencere başlığından, DTSG satırı ve ASAY değeri altyazıdan ve dump'taki `00 F0` baytlarından kuruldu. Hoca hata ayıklama sırasında STSG ve DTSG'nin hizalamasını PARA'ya çevirdi (bkz. 18.6). -->

### 18.5 LST ve MAP dosyaları

İlk bağlamada LST yerine yanlışlıkla nesne dosyası adı verildiği için LST oluşmadı; hoca yeniden derleyip LST ve MAP'i üretti. LST'de:

- Yığın kesimi 0 ofsetinden başlayıp 28h'ye kadar gider; 28h onluk 40'tır, yani 20 word'lük alan.
- Kesim tanımları (`SEGMENT`) makine kodu üretmez ve adresi artırmaz. `DB`/`DW`/`DD` tanımlarının makine kodu yoktur, ama yer kapladıkları için adresi artırırlar.
- `PUSH DS` 1 byte (`1E`), `XOR AX, AX` 2 byte, `PUSH AX` 1 byte'tır.
- `MOV AX, DTSG` satırında MOV'un kodu `B8`'dir, ama DTSG'nin değeri program belleğe yüklenmeden belli olmadığı için yeniden konumlandırılabilir (relative) bir bilinmeyen olarak işaretlenir.
- `LEA BX, SONUC` satırı da göreli bir işlem olarak işaretlenir; SONUC kendi veri kesiminin 4. ofsetindedir. Yani ofseti baştan bellidir, ama mutlak yeri kesimin yükleneceği adrese göre değişir.
- Yorum satırlarının makine kodu yoktur.

MAP dosyasında her kesim için kesim adı, sınıf adı, onaltılık boyutu ve göreli başlangıç-bitiş adresleri ile programın giriş noktası görünür. Bu bilgi birden fazla kod ve veri kesimi içeren, kesim birleştirmesi yapılan programlarda daha anlamlı olacak.

Hoca kesimlerin boyutlarını da saydı: 2 byte, 2 byte ve 4 byte, toplam 8 byte'lık veri.

### 18.6 DEBUG ile izleme ve hizalama sorunu

DEBUG'da önce işletim sistemine dönüş ve DS ayarı satırları trace edildi. Ardından `D DS:0` ile veri kesimine bakıldı, ama beklenen değişkenler yerine farklı değerler göründü. `D CS:0` doğru görünüyordu (`1E 33 C0 50 B8 ...`). Hoca segment değerini sayı olarak yazıp `D 076C:0` da denedi; aynı farklı değerler göründü.

Bir öğrenci kesim adlarının yanlış yazılmış olabileceğini sordu; hoca adların doğru olduğunu gösterdi. Hoca görülen değerlerin işletim sistemine dönüş değerleriyle ilgili olduğunu, yani yığın tarafında kalan baytların göründüğünü fark etti. `D SS:24` ile yığına bakıldığında yığının dibinde dönüş segment değeri ve 0000 doğru biçimde duruyordu. Sorunun hizalamadan kaynaklandığını düşünen hoca, yığın kesimini ve veri kesimini PARA hizalamaya çevirip yeniden derledi. Bu kez veri kesiminin başlangıcı 16'nın katına denk geldi ve değişkenler `D DS:0` ile doğru göründü. Hoca BYTE/WORD durumunda ofsetin tam olarak nasıl belirlendiğini o anda çözemediğini, daha sonra inceleyeceklerini söyledi.

> **Ek bilgi (derste anlatılmadı):** Segment yazmacı yalnız 16'nın katı olan adresleri gösterebilir. Bir kesim 16'nın katında başlamazsa bağlayıcı segment değerini bir alt paragrafa yuvarlar ve o kesimdeki değişkenlerin ofsetlerini aradaki fark kadar kaydırır. Bu örnekte yığın 076A:0000'dan başlayıp 28h byte sürdüğü için WORD hizalı veri kesimi büyük olasılıkla 076A0h + 28h = 076C8h fiziksel adresinde, yani 076C:0008'de başlamıştır. Bu yüzden `D 076C:0` ilk sekiz byte'ta yığının son baytlarını (dönüş değerlerini) göstermiştir.

### 18.7 Adım adım çalıştırma

PARA hizalamalı sürümde veri kesimi `00 F0 00 E0 00 00 00 00` olarak göründü: ASAY = F000h, BSAY = E000h (little endian olarak `00 E0`), SONUC = 0 (dört byte). Sonrası bir sonraki kesimin PARA hizalamasından dolayı çöp değerdir.

Adımlar:

1. `LEA BX, SONUC`: komut `LEA BX, [0004]` olarak çözülmüştü; BX = 0004 olur. SONUC'un ofseti 4'tür.
2. `MOV AX, ASAY`: AX = F000h.
3. `ADD AX, BSAY`: F000h + E000h. Hoca en yüksek basamakları topladı: F + E = 15 + 14 = 29; 16 çıkarılınca 13 = D kalır ve 1 elde oluşur. AX = D000h. Bayraklar: taşma yok (NV), yön ileri (UP), kesmeler açık (EI), sonuç negatif, sıfır değil, yardımcı elde yok, çift eşlik (PE) ve elde var (CY). Önce NC olan elde bayrağı CY olmuştu.
4. `MOV [BX], AX`: düşük word SONUC'a yazılır. `D DS:0`: SONUC'un düşük word'ü `00 D0`, yüksek word'ü hâlâ `00 00`.
5. `JNC L1`: elde olduğu için dallanmadı, `INC` satırına geçildi.
6. `INC WORD PTR [BX+2]`: sonucun yüksek word'ü 1 artırıldı.

Son durumda dump (ekrandan, 03:00:00):

```text
076A:0030  00 F0 00 E0 00 D0 01 00-00 00 00 00 00 00 00 00
```

SONUC'un dört byte'ı `00 D0 01 00`'dır ve little endian olarak 0001D000h okunur. F000h ile E000h'nin toplamı 1D000h'dir: D000h düşük word, 1 de eldedir.

Python ile kontrol: 0xF000 + 0xE000 = 0x1D000; düşük word D000h, CF = 1. İşaretli olarak −4096 + (−8192) = −12288 aralık içinde olduğu için OF = 0; D000h'nin en yüksek biti 1 olduğu için SF = 1; düşük byte 00h'de 1 bitlerinin sayısı çift olduğu için PF = 1; ZF = 0. Sonuç baytları `00 d0 01 00`. Bunlar hocanın okuduğu bayraklarla uyumludur.

Ekrandaki makine kodu da python ile ofsetlere ayrıldı: `1E`(0) `33C0`(1) `50`(3) `B86D07`(4) `8ED8`(7) `8D1E0400`(9, LEA BX,[0004]) `A10000`(D) `03060200`(10) `8907`(14) `7303`(16, JNC) `FF4702`(18, INC WORD PTR [BX+2]) `CB`(1B, RETF). `JNC`'nin hedefi 16h + 2 + 3 = 1Bh, yani RETF'tir; ekranda RETF IP = 001B'de görüldü.

### 18.8 İşletim sistemine dönüş

RETF'ten önce `D SS:24` ile yığına bakıldı: en üstte dönüş ofseti ve segment değeri (`00 00 5A 07`) duruyordu. Bir adım daha yürütülünce program işletim sistemine döndü; ekranda CS = 075A, IP = 0000, SP = 0028 ve sıradaki komut `INT 20` göründü (ekrandan, 03:00:00).

Hoca ilerideki örneklerde de hem veri kesimine hem yığın kesimine bu şekilde bakılacağını; EXE programı oluşturmak, derlemek, çalıştırmak ve DEBUG ile incelemek için izlenecek adımların bunlar olduğunu söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:24:41-00:28:35): Program `PUSH DS`, `XOR AX, AX`, `PUSH AX` satırlarını yürüttükten sonra yığına atılan değerler DEBUG ile nasıl görülür?

> **Çözüm:** SP'nin gösterdiği adresten itibaren dump edilir: SP = 0024 olduğu için `D SS:24`. Ofset sabit sayı olarak yazılır. Görülen `00 00 5A 07`'dir: üstte AX'ten gelen 0000, altında DS'den gelen 075Ah. Kesimin 0 ofsetine bakmak yanlıştır, çünkü yığın yüksek adresten aşağı doğru dolar.

**Soru 2** (derste sözlü, 00:29:09; ekrandan, 00:40:00): DS'nin değeri 075Ah olduğu halde dump'ta neden `07 5A` değil `5A 07` görülür?

> **Çözüm:** 8086 little endian'dır: word'ün düşük anlamlı byte'ı (5Ah) düşük adreste, yüksek anlamlı byte'ı (07h) yüksek adreste saklanır. Word olarak okunduğunda değer 075Ah'dir.

**Soru 3** (derste sözlü, 00:40:20-00:41:43): Programın veri kesimindeki A, B ve SONUC değişkenleri DEBUG'da nasıl görülür? Program başlar başlamaz `D DS:0` yazılırsa ne olur?

> **Çözüm:** Başlangıçta DS işletim sisteminin verdiği değeri (075A) gösterir, bu yüzden değişkenler görülmez. `MOV AX, DATASG` ve `MOV DS, AX` trace edildikten sonra (DS = 076D) `D DS:0` ile `02 0A 00 00` görülür.

**Soru 4** (derste sözlü, 00:42:24; ekrandan, 00:40:00): Veri kesiminin dökümünde değişkenlerden sonra gelen sıfırların ardından görülen tanıdık baytlar (`1E 33 C0 50 B8 6D 07 ...`) nereye aittir? Aradaki sıfırlar nedir?

> **Çözüm:** Kod kesimine aittir; 076E:0000 ile 076D:0010 aynı fiziksel adrestir (076E0h). Aradaki baytlar kullanılmayan alandır: veri kesimi 4 byte kaplar, ama kod kesimi PARA hizalı olduğu için bir sonraki 16'nın katında başlar.

**Soru 5** (derste sözlü, 00:51:16; ekrandan, 00:55:00): `deneme.asm` RETF satırına kadar çalıştırılırsa SONUC'ta ne görülmelidir?

> **Çözüm:** $2^{10} = 1024 = 0400h$. Dump'ta SONUC `00 04` olarak görülür; AX = 0400, CX = 0000.

**Soru 6** (derste sözlü, 00:52:46): DEBUG dump çıktısının sağ tarafındaki karakterler nedir?

> **Çözüm:** Dökülen baytların ASCII karşılıklarıdır. `STR DB 'MERHABA'` eklenince `4D 45 52 48 41 42 41` baytları sağda `MERHABA` olarak görüldü.

**Soru 7** (derste sözlü, 01:28:42): `DW 20 DUP (?)` ile yığın için kaç byte ayrılır?

> **Çözüm:** 20 word = 40 byte = 28h. Bu yüzden başlangıçta SP = 0028h'dir ve LST'de yığın kesimi 28h'de biter.

**Soru 8** (derste sözlü, 01:20:18): Bir kesimin veri kesimi, kod kesimi ya da yığın kesimi olduğu ne zaman ve neyle belli olur?

> **Çözüm:** Yığın: `STACK` kelimesiyle, program yüklenirken. Veri: `MOV AX, DATASG` / `MOV DS, AX` yürütüldükten sonra. Kod: `END` kelimesinden sonraki etiketin bulunduğu kesim; CS o kesimle yüklenir.

**Soru 9** (ekrandan, 01:40:00): `Matris DB 3 DUP (4 DUP (8))` kaç byte ayırır ve bellekte nasıl yerleşir?

> **Çözüm:** 3 · 4 = 12 byte; hepsinin değeri 8'dir. Satır öncelikli, ardışık adreslere yerleşir.

**Soru 10** (ekrandan, 01:45:00): `Yenib LABEL BYTE`, `Sayiw DW 2535H`, `Yeniw LABEL WORD`, `Sayib DB 45H`, `Sayic DB 55H` tanımlarından sonra `MOV AX, Yeniw` ve `MOV BL, Yenib` çalışınca AX ve BL ne olur?

> **Çözüm (derste sözlü verildi, python ile kontrol edildi):** Bellek: 35h, 25h, 45h, 55h. AX = 5545h, BL = 35h. `MOV AX, Sayib` ise tip uyuşmazlığı hatası verir.

**Soru 11** (derste sözlü, 01:47:16-01:48:28): `TABLO DW 15 DUP (0)` için `LENGTH TABLO`, `TYPE TABLO` ve `SIZE TABLO` değerleri nedir?

> **Çözüm:** 15, 2 ve 30.

**Soru 12** (derste sözlü, 01:51:56; ekrandan, 01:10:00): Kod kesiminin boyutu DOSBox'ta görülebilir mi?

> **Çözüm:** Evet; LST dosyasındaki ofsetlerden ya da LINK'in ürettiği MAP dosyasından. `deneme` için kod 22h (34 byte), veri 4h, yığın 28h.

**Soru 13** (derste sözlü ve ekrandan, 02:25:57): İki adet 16 bitlik sayının toplamını hesaplayıp sonucu 32 bitlik bir değişkende saklayan EXE tipi assembly programını yazınız.

> **Çözüm:** Bölüm 18'deki program. `ASAY = 0F000H`, `BSAY = 0E000H` için SONUC bellekte `00 D0 01 00`, yani 0001D000h olur.

**Soru 14** (derste sözlü, 02:34:41 ve 02:36:26): İki bellek değişkenini nasıl toplarız? Elde oluşursa 32 bitlik sonucun yüksek word'üne nasıl yansıtırız?

> **Çözüm:** `MOV AX, ASAY` / `ADD AX, BSAY` / `LEA BX, SONUC` / `MOV [BX], AX`. Yüksek word için ya `ADC WORD PTR [BX+2], 0` ya da `JNC L1` / `INC WORD PTR [BX+2]` / `L1:`. Koşul yanlış kol üzerinden yazıldığı için tek dallanma yeter.

**Soru 15** (derste sözlü, 02:41:41): MASM `INC [BX+2]` satırında neden hata verir? `ADD [BX+2], 1` yazılsa ne olur?

> **Çözüm:** İşlenen bir bellek adresi ve işlem boyutu belli değil. `WORD PTR` yazılmalıdır: `INC WORD PTR [BX+2]`. `ADD [BX+2], 1` ve `ADC [BX+2], 0` da aynı nedenle `WORD PTR` ister.

**Soru 16** (derste sözlü, 02:18:30-02:19:20): EXE programının başında AX'in de push edilmesi gerekir mi?

> **Çözüm:** Hayır. Gereken yalnız DS'yi (dönüş segment değeri) ve 0 değerini (dönüş ofseti) yığına atmaktır; `XOR AX, AX` ve `PUSH AX` bu sıfırı atmak içindir.

## Dersin Toparlaması

Bu derste alt seviye programlamanın çalışma ortamı kuruldu: DOSBox'ta yerel klasör bağlandı, MASM ile derleme ve LINK ile bağlama yapıldı, LST ve MAP dosyaları incelendi. DEBUG'ın R, T, P, G, D, E, U ve A komutlarıyla bir EXE programı adım adım izlendi. Yığın little endian baytlarıyla dump edildi; veri kesiminin DS ancak `MOV DS, AX`'ten sonra gösterdiği, PARA hizalamanın kesimler arasında boş alan bıraktığı görüldü. EXE programının işletim sistemine dönüşü FAR ana yordam, yığına atılan DS ve 0 ile `RETF` üzerinden açıklandı.

Dersin ikinci kısmında sözde komutlar işlendi: makine kodları yoktur ve derleme anında etki ederler. Kesim tanımı, hizalama ve birleştirme kelimeleri, ASSUME, ORG, veri tanımlama komutları (DB, DW, DD, DQ, EQU, DUP, TYPEDEF, PTR), LABEL, PROC/ENDP, EXTRN/PUBLIC, makro komutları ve LENGTH/TYPE/SIZE/OFFSET/SEG/END anlatıldı. Son kısımda EXE tipi program iskeleti incelendi ve iki 16 bitlik sayının 32 bitlik toplamını hesaplayan program sıfırdan yazıldı, derlendi ve DEBUG ile doğrulandı. Hoca ilerideki örneklerde alt yordamlara yığınla parametre aktarımı ve özyinelemeli programlarda yığının bu yöntemle inceleneceğini, COM tipi programların iskeletine de sonraki haftalarda geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
