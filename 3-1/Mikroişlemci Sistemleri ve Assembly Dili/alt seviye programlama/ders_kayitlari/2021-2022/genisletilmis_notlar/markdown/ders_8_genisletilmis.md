# Ders 8 Genişletilmiş Notu: Dizi Komutları, Giriş/Çıkış, BCD Komutları ve Adresleme Modları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Akışı
- 2. Tekrarlama Önekleri ve LOOP ile Karşılaştırma
- 3. Dizi (String) Komutlarına Genel Bakış
- 4. DF Bayrağı ve Dizi Komutlarının Hazırlığı
- 5. MOVS ve Kopyalama Örneği
- 6. CMPS ve İlk Farklı Elemanı Bulma
- 7. SCAS ve Dizide Değer Arama
- 8. LODS, STOS ve Dizi Doldurma
- 9. CBW ve CWD
- 10. Giriş/Çıkış Komutları: IN ve OUT
- 11. Durdurma ve Bekletme Komutları
- 12. BCD Düzenleme Komutları
- 13. Veri Adresleme Modları
- 14. Program Hafızası Adresleme
- 15. Yığın Adresleme
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Akışı

Hoca dersin planını şöyle verdi: önce dizi (string) komutları, ardından giriş/çıkış komutları, durdurma ve bekletme komutları, BCD düzenleme komutları ve son olarak yeni bir slayt setindeki adresleme modları. Ders Zoom üzerinden, hocanın Microsoft Whiteboard'a yazdığı örnekler ve PDF slaytlarla yürütüldü.

## 2. Tekrarlama Önekleri ve LOOP ile Karşılaştırma

Dizi komutlarının çoğu (CBW ve CWD hariç) dizideki yalnız bir eleman için işlem yapar. Bütün elemanlar için tekrarlanmaları için `REP`, `REPE`/`REPZ`, `REPNE`/`REPNZ` önekleri kullanılır. Hoca bunları önceki derste görülen döngü komutlarıyla karşılaştırarak anlattı (ekrandan, 00:05:00):

- `LOOP`: CX ≠ 0 olduğu sürece döngüye devam eder.
- `LOOPZ`: CX ≠ 0 ve ZF = 1 olduğu sürece devam eder.
- `LOOPNZ`: CX ≠ 0 ve ZF = 0 olduğu sürece devam eder.
- `REP`: CX ≠ 0 olduğu sürece peşindeki dizi komutunu tekrarlar.
- `REPZ` (`REPE`): CX ≠ 0 ve ZF = 1 olduğu sürece tekrarlar.
- `REPNZ` (`REPNE`): CX ≠ 0 ve ZF = 0 olduğu sürece tekrarlar.

İki grup arasındaki temel fark sözdizimindedir: `LOOP`'tan sonra bir etiket gelir ve koşul sağlanırsa o etikete dallanılır; `REP` öneklerinden sonra ise bir dizi komutu gelir. Tekrar sayısı her iki durumda da işlemden önce CX'e yüklenir ve her geçişte CX otomatik olarak 1 azaltılır.

**Soru:** REP de CX'i azalttığına göre LOOP ile aynı anlama gelmiyor mu?
**Cevap:** İşlevsel olarak benzerdir ama yapı farklıdır. LOOP etikete dallanır; REP etiket almaz, yalnız hemen peşindeki dizi komutunu CX sıfır olmadığı sürece tekrar tekrar çalıştırır.

**Soru:** REP kullanınca SI ve DI'yı artırma/azaltma işini bizim yapmamıza gerek kalmıyor mu?
**Cevap:** SI ve DI'yı değiştiren REP değil, dizi komutunun kendisidir (örneğin MOVSB). REP yalnız "CX sıfır olmadığı sürece peşindeki komutu çalıştır" der. Artırma mı azaltma mı yapılacağı DF bayrağına bağlıdır.

**Soru:** REP yalnız dizi komutlarıyla mı kullanılır?
**Cevap:** Hoca bildiği kadarıyla yalnız dizi komutlarıyla kullanıldığını, başka bir yerde kullanma ihtiyacı duymadığını söyledi.

## 3. Dizi (String) Komutlarına Genel Bakış

Komutlar ve açılımları tahtada şöyle listelendi (ekrandan, 00:10:00):

- `MOVS`: move string
- `CMPS`: compare string
- `SCAS`: scan string
- `LODS`: load string
- `STOS`: store string

Her birinin `B` ile biten byte sürümü ve `W` ile biten word sürümü vardır (`MOVSB`/`MOVSW` gibi). Byte sürümü byte dizisi, word sürümü word dizisi üzerinde çalışır.

Slayttaki tanımlar şöyledir (ekrandan, 00:20:00):

- MOVS: bir bellek bölgesinin bir başka bellek bölgesine kopyalanması.
- CMPS: farklı iki bellek bölgesinin içeriklerinin karşılaştırılması.
- SCAS: bellek bölgesinin içeriğinin AX/AL ile karşılaştırılması.
- LODS: bellek bölgesindeki değerin AX/AL'ye yüklenmesi.
- STOS: bellek bölgesinin AX/AL değeri ile doldurulması.
- CBW: işaret bitini koruyarak byte'ı word'e genişletme.
- CWD: işaret bitini koruyarak word'ü double word'e genişletme.

Kaynak her zaman DS:[SI], hedef her zaman ES:[DI] ile gösterilir (ekrandan, 00:10:00 ve 00:15:00):

- MOVS: DS:[SI]'dan ES:[DI]'ya kopyalar (kaynak → hedef).
- CMPS: kaynak − hedef, yani DS:[SI] − ES:[DI] işlemini yapar. Sonuç saklanmaz, yalnız bayraklar etkilenir.
- SCAS: akümülatördeki (8 bitte AL, 16 bitte AX) referans değerini dizinin elemanlarıyla karşılaştırır.
- LODS: AL/AX ← DS:[SI]. Dizinin elemanlarını sırayla akümülatöre alır.
- STOS: ES:[DI] ← AL/AX. Akümülatördeki değeri dizinin sıradaki elemanına yazar.

Hoca hep "iki dizi" diye anlatmanın kolay olduğunu, ama SCAS, LODS ve STOS'ta tek dizi ve akümülatör bulunduğunu hatırlattı. Komutlar üç gruba ayrıldı: dizi işlemini yapan komutlar, dönüştürme komutları (CBW, CWD) ve tekrarı sağlayan önekler.

## 4. DF Bayrağı ve Dizi Komutlarının Hazırlığı

İşlemin yönünü DF (direction flag) belirler (ekrandan, 00:15:00):

- DF = 0 ise DS:[SI] ve ES:[DI] dizilerin ilk elemanını gösterir. Byte komutlarında (MOVSB, CMPSB ...) her adımda $SI \leftarrow SI + 1$, $DI \leftarrow DI + 1$; word komutlarında (MOVSW, CMPSW ...) her adımda 2 artış olur, çünkü bir sonraki word 2 bayt ötededir.
- DF = 1 ise SI ve DI dizilerin son elemanını gösterir; her adımda byte'ta 1, word'de 2 azalırlar. Bu, diziyi sondan başa doğru işlemek demektir.

Bu yüzden bir dizi komutundan önce sırasıyla şu hazırlık yapılır:

- Dizinin başından mı sonundan mı işlem yapılacağına karar verilir ve SI/DI buna göre ayarlanır.
- DF buna göre ayarlanır: SI/DI baş tarafı gösteriyorsa DF = 0, son tarafı gösteriyorsa DF = 1. Hoca "set edilmeli" demenin 1 yapmak gibi anlaşılabileceğini, doğrusunun "ayarlanmalı" olduğunu belirtti.
- CX'e döngü sayısı yüklenir. Bu sayı bayt sayısı değil, eleman sayısıdır (word dizisinde de eleman adedi).
- Uygun önekle dizi komutu çalıştırılır.

**Soru (hocadan):** DF bayrağını ayarlayan komutlar nelerdi?
**Cevap:** `STD` (set direction flag) DF'yi 1 yapar; `CLD` (clear direction flag) DF'yi 0 yapar. İkisi de parametre almaz.

## 5. MOVS ve Kopyalama Örneği

MOVSB kaynaktaki diziyi hedefe kopyalar. DF = 0 iken kaynağın birinci elemanı hedefin birinci elemanına kopyalanır, SI ve DI 1 artar, sonra ikinci elemanlar kopyalanır; bu CX sıfır olana kadar sürer. DF = 1 olsaydı her kopyalamadan sonra SI ve DI 1 azalacaktı. MOVSW aynı işi word elemanlarla yapar ve SI/DI 2 artar ya da azalır.

Örnek (ekrandan, 00:30:00 ve 00:35:00): veri kesimi şöyledir.

```asm
dizi1 DB 'abcdefgh....'   ; 20 karakter
dizi2 DB 20 DUP(?)
n     DW 20
```

`20 DUP(?)` dizi2 için içeriği önemsiz 20 baytlık yer ayırır, ilk değer vermez. Amaç dizi1'i dizi2'ye kopyalamaktır. Kaynak SI ile, hedef DI ile ilişkilidir. Bir öğrenci önce DF'yi sıfırlamayı önerdi; hoca DF'ye SI/DI'nın nereyi gösterdiğine göre karar verileceğini, önce onların ayarlanması gerektiğini söyledi. Bir başka öğrencinin önerisiyle SI ve DI `LEA` (load effective address) ile ayarlandı:

```asm
LEA SI, dizi1   ; [SI]: 'a'
LEA DI, dizi2   ; [DI]: dizi2'nin başı
CLD             ; DF <- 0
MOV CX, n
REP MOVSB       ; dizi2 <- dizi1
```

SI ve DI dizilerin başını gösterdiği için ileri gidilecektir, bu yüzden `CLD` kullanılır. MOVSB tek başına çalıştırılsa yalnız 'a' karakterini kopyalar ve başka bir şey yapmaz; başına REP konunca CX sıfır olana kadar tekrar eder ve her adımda $DI \leftarrow DI + 1$, $SI \leftarrow SI + 1$ olur.

**Soru:** Bu tanımdaki gibi diziye karakter (harf) verebilir miyiz?
**Cevap:** Evet. Örneğin `dizi DB 'Merhaba', '$'` bir karakter dizisi tanımıdır; sonundaki `$` sonlandırma karakteri olarak seçildiyse kontrol buna göre yapılabilir. Tek bir karakter değişkeni `var DB 'e'` biçiminde tanımlanır; bu durumda `var`'a küçük e'nin ASCII karşılığı atanır (ekrandan, 00:35:00).

## 6. CMPS ve İlk Farklı Elemanı Bulma

CMPS kaynak ile hedefi tüm elemanlar boyunca karşılaştırır: DS:[SI] − ES:[DI] çıkarmasını yapar, sonucu saklamaz, yalnız bayrakları etkiler. CMPSB'de DF = 0 ise her karşılaştırmadan sonra SI ve DI 1 artar, DF = 1 ise 1 azalır. CMPSW'de bu değişim 2'dir.

> **Ders sonrası not:** Hoca 00:20:20 civarında CMPS için "bayraklar etkilenmeyecek" dedi, hemen ardından ve dersin geri kalanında bayrakların etkilendiğini söyledi. Doğrusu: sonuç saklanmaz, bayraklar etkilenir.

Örnek (ekrandan, 00:40:00 ve 00:45:00):

```asm
dizi1 DB 'abcdefgh....'
dizi2 DB 'abcdefGh....'
n     DW 20
```

İstenen: iki dizi için karşılıklı elemanlarda ilk farklı değeri ve indisini bulmak. Gözle bakıldığında ilk fark g ile G arasındadır.

Başlangıç bir öncekiyle aynıdır: `LEA SI, dizi1`, `LEA DI, dizi2`, `CLD`, `MOV CX, n`. Bir öğrenci REP'in sonuna kadar gideceğini, bu yüzden LOOP ile elle döngü kurmanın gerekebileceğini söyledi. Hoca bunun da bir çözüm olduğunu (döngüde farkı yakalayınca döngüyü kırmak), ama işin önekle yapılabileceğini gösterdi.

Döngü ne zamana kadar sürmelidir? Elemanlar eşit oldukça CMPSB ZF'yi 1 yapar; döngü CX ≠ 0 ve ZF = 1 olduğu sürece sürmelidir. Bir öğrenci `REPNZ` önerdi; hoca önekin "hangi şartta tekrarlanacağını" söylediğini, bu yüzden doğru önekin `REPZ` olduğunu açıkladı. a − a = 0 (ZF = 1, devam), b − b = 0 (devam), ... g − G ≠ 0 (ZF = 0) olunca döngü kırılır.

```asm
REPZ CMPSB      ; CX != 0 ve Z = 1 iken devam (ekrandan, 00:45:00)
```

### 6.1 REP ve LOOP bayrakları etkilemez

Hoca burada komut kümesi (instruction set) tablosunu açtı. Tabloda her komutun aldığı operandlar, süresi ve etkilediği bayraklar yer alır. LOOP komutlarının ve REP'in hiçbir bayrağı etkilemediği gösterildi. REP, CX'i azaltırken CX sıfır olunca bile ZF'yi değiştirmez. Yani bu döngüde ZF'yi değiştiren yalnız CMPSB'dir.

> **Hocanın vurgusu:** REP ve LOOP komutları bayrakları etkilemez. Bu önemli bir noktadır.

### 6.2 Döngüden hangi koşulla çıkıldı?

Döngünün altındaki satıra iki yoldan gelinebilir: CX = 0 (diziler eşit, fark yok) ya da ZF = 0 (fark bulundu). Bunu ayırt etmek gerekir. `JZ` ZF = 1 iken dallanır; burada ZF = 0 iken dallanmak istendiği için `JNZ` kullanılır:

```asm
        REPZ CMPSB
        JNZ farkli      ; ZF = 0: farklı eleman bulundu
        ...             ; buraya CX = 0 ile gelindi: diziler aynı
farkli: ...
```

Bir öğrenci, `JNZ` dallanmazsa akışın `farkli` etiketine düşmemesi için araya bir atlama konması gerektiğini söyledi; hoca bir çıkış atlaması ekledi ve CX = 0 ile gelinen durum için `ayni` adlı bir etiketten söz etti. <!-- BELİRSİZ: JNZ sonrası atlama satırlarının ve etiketlerin tahtadaki tam yazımı karelerde görünmüyor (altyazı 00:46:19–00:48:10) -->

**Soru:** CX zaten indisi vermiyor mu?
**Cevap:** CX azalarak ilerlediği için doğrudan indis değildir; 20'den başlayıp 4 adım gidilince 16 olur, aranan değer 20'den çıkarılmalıdır. Hoca indisin SI ve DI üzerinden de doğrudan bulunabileceğini, çünkü dizi komutlarının onları da güncellediğini söyledi.

> **Ders sonrası not:** Hoca farklı elemanların `[SI]` ve `[DI]` ile okunabileceğini söyledi. CMPSB karşılaştırmadan sonra SI ve DI'yı yine artırır; bu yüzden döngü bittiğinde SI ve DI farklı elemanın bir sonrasını gösterir. Farklı elemanlar `[SI-1]` ve `[DI-1]`'dedir. Python ile kontrol: bu örnekte döngü SI = DI = 7 (dizi başına göre) ve CX = 13 ile biter; farklı elemanın indisi $SI - 1 = 6$ ya da $n - CX - 1 = 20 - 13 - 1 = 6$'dır (a=0, ..., g=6).

## 7. SCAS ve Dizide Değer Arama

SCASB ve SCASW akümülatördeki referans değeri hedef dizinin sıradaki elemanıyla karşılaştırır (ekrandan, 00:50:00):

- SCASB: AL − ES:[DI]; $DI \leftarrow DI + 1$ (DF = 1 olsaydı $DI \leftarrow DI - 1$).
- SCASW: AX − ES:[DI]; $DI \leftarrow DI + 2$ (DF = 1 olsaydı $DI \leftarrow DI - 2$).

Bir dizide belirli bir karakteri (AL'ye koyarak) ya da bir word dizisinde belirli bir word'ü (AX'e koyarak) aramak için kullanılır.

Örnek: bir word dizisi (`dizi DW ...`) ve `n DW 10` tanımlanır; amaç 8 değerinin dizide olup olmadığını ve varsa indisini bulmaktır. <!-- BELİRSİZ: dizinin elemanları altyazıda "1, 2, 3, 4, 4, ... 6, 8, 1, 7" diye okunuyor, tahtada görünmüyor; on eleman tam çıkarılamadı -->

Hoca önce DI'yı ve CX'i ayarladı, sonra referans değerin atanmadığını fark edip `MOV AX, 8` ekledi (word dizisi olduğu için AX), en son DF'yi ayarlamayı unuttuğunu görüp `CLD` ekledi (ekrandan, 00:55:00):

```asm
LEA DI, dizi
MOV CX, n
MOV AX, 8
CLD               ; DF = 0, DI <- DI + 2
REPNZ SCASW
JZ buldum         ; Z = 1 veya CX = 0
...
buldum:
```

Döngü ne zamana kadar sürmeli? CX ≠ 0 olduğu ve eşitlik bulunmadığı sürece. Bir öğrenci eşitlik yokken ZF'nin 1 olduğunu söyledi; hoca eşitlik yoksa ZF'nin 0 olduğunu düzeltti. Bu yüzden önek `REPNZ`'dir. Döngü bittikten sonra ya ZF = 1 (değer bulundu) ya da CX = 0 (değer yok) ile alt satıra gelinir. Aranan durum ZF = 1 olduğu için `JZ buldum` yazılır. `buldum` etiketinde bulununca yapılacaklar, `JZ`'nin hemen altında ise CX = 0 durumu (bulunamadı) ele alınır; hoca bunu ayrı bir `yok` etiketiyle belirtti ve `buldum` kısmının sonuna bir çıkış atlaması koydu.

**Soru:** `yok` etiketine atlamak yerine bulunamadı durumunun komutlarını doğrudan `JZ`'nin altına yazsak olmaz mı?
**Cevap:** Olur. Hoca yalnız bu satıra CX = 0 ile gelindiğini daha açık göstermek için ayrı etiket kullandığını söyledi.

> **Ders sonrası not:** Hoca bulunan elemanın DI indisinde olduğunu söyledi. SCASW de karşılaştırmadan sonra DI'yı 2 artırdığı için bulunan word büyük olasılıkla `[DI-2]` adresindedir (python ile örnek bir dizide kontrol edildi: 8 indis 6'daysa döngü DI = 14 ile biter, word adresi 12'dir).

## 8. LODS, STOS ve Dizi Doldurma

LODS ve STOS benzer çalışır, ama LODS SI'yı, STOS DI'yı kullanır. LODSB dizinin elemanını AL'ye, LODSW AX'e alır; STOS akümülatördeki değeri dizinin sıradaki elemanına yazar. DF = 0 ise SI/DI artar, DF = 1 ise azalır (byte'ta 1, word'de 2).

LODS ile REP kullanmak anlamlı değildir, çünkü her adımda AL'nin üzerine yazılır. STOS için ise anlamlıdır.

### 8.1 Diziyi sıfırlama

Veri kesimi: `dizi1 DB 25 DUP(?)` (25 baytlık yer, ilk değersiz), `n DW 25`. Bir öğrenci STOS kullanılacağını söyledi; STOS DI üzerinden çalıştığı için hazırlık DI ile yapılır (ekrandan, 01:00:00):

```asm
LEA DI, dizi1
MOV CX, n
CLD
XOR AL, AL      ; AL = 0 (dizi byte tipinde)
REP STOSB
```

Burada başka bir koşula gerek yoktur; REP yeterlidir, çünkü her adımda aynı değer (0) yazılır.

### 8.2 Diziyi 1'den 25'e kadar doldurma

Aynı tanımlarla dizi1 1'den 25'e kadar değerlerle ilklendirilmek istenir (ekrandan, 01:00:00). `n` word olarak tanımlandı, çünkü CX'e atanacak. Bir öğrenci REP mi LOOP mu kullanılacağını sordu. REP ve STOS birlikte kullanıldığında AL'yi döngünün içinde değiştirecek bir yer yoktur; döngü bitince değiştirmek de işe yaramaz. Bu yüzden LOOP gerekir. Hoca önce şunu yazdı:

```asm
LEA DI, dizi1
MOV CX, n
MOV AL, 1
L1: STOSB
    INC AL
    LOOP L1
```

STOSB AL'yi DI'nın gösterdiği elemana yazar ve DI'yı bir sonraki elemana geçirir; INC AL değeri artırır; LOOP CX'i azaltıp L1'e döner. Böylece dizi 1, 2, 3, ..., 25 olur. Bir öğrenci `XOR AL, AL` ile başlayıp `INC AL`'yi STOSB'nin önüne almayı önerdi; hoca bunun daha iyi olduğunu söyleyip kodu buna göre değiştirdi:

```asm
    XOR AL, AL
L1: INC AL
    STOSB
    LOOP L1
```

Python ile kontrol: her iki biçim de 1'den 25'e kadar değerleri yazar. <!-- BELİRSİZ: bu iki kodun tahtadaki yazımı karelerde görünmüyor; altyazıdan kuruldu (01:01:19–01:03:38) -->

Bu örnek, dizi komutlarının önek olmadan da tek başına kullanılabildiğini gösterir: STOSB o anki DI için işlemi bir kez yapar.

## 9. CBW ve CWD

Bu komutlar akümülatör üzerinden çalışır ve operand almaz.

`CBW` (convert byte to word) AL'deki byte'ı işaret bitini koruyarak (sign extend) AX'e genişletir (ekrandan, 01:05:00). Genişletme, işaret bitinin AH'ın bütün bitlerine kopyalanmasıdır.

- `MOV AL, 00111010B` / `CBW`: işaret biti 0 olduğu için AH sıfırlarla dolar; AX = 0000 0000 0011 1010B = 003AH. Genlik değişmez.
- AL = 1111 1111B (8 bitlik −1) / `CBW`: işaret biti 1 olduğu için AH birlerle dolar; AX = FFFFH, bu da 16 bitlik −1'dir.

`CWD` (convert word to double word) AX'teki word'ü işaretini koruyarak sanal 32 bitlik DX:AX ikilisine genişletir. Hoca bu ikilinin DIV ve MUL'da karşılaşılan sanal yazmaç olduğunu hatırlattı. AX değişmez; DX, AX'in işaret bitiyle doldurulur.

- `MOV AX, 0777H` / `CWD`: DX = 0000H, AX = 0777H (pozitif sayı).
- `MOV AX, 8000H` / `CWD`: DX = FFFFH, AX = 8000H. Bir öğrenci DX için "EFFF" dedi; hoca hepsinin 1 olacağını, yani FFFFH olduğunu söyledi.

Bu komutlarla bir byte ya da word değeri, örneğin bölme işleminden önce AX ya da DX:AX biçimine hazırlanır. Bütün sonuçlar python ile doğrulandı.

> **Ders sonrası not:** Hoca 8000H için "yazabileceğimiz en büyük negatif sayı" dedi. 8000H işaretli 16 bitte −32768'dir; mutlak değeri en büyük, yani en küçük negatif sayıdır.

## 10. Giriş/Çıkış Komutları: IN ve OUT

Hoca bu komutların bu derste çok kullanılmayacağını, Mikroişlemciler dersinin ana konusu olacağını söyledi.

### 10.1 MOV ile IN/OUT arasındaki fark

MOV da IN/OUT da mikroişlemcinin adres, veri ve kontrol uçlarında değer oluşturur. Fiziksel fark M/IO ucundadır: MOV yürütülürken bu uçta bellek işlemine karşılık gelen değer, IN/OUT yürütülürken 0 değeri oluşur. Dışarıdaki sistem bu uca bakarak işlemin bellek mi G/Ç mı olduğunu ayırt eder. IN dışarıdan okuma olduğu için RD (read) ucunu 0 yapar, OUT dışarıya yazma olduğu için WR (write) ucunu 0 yapar. MOV'da da bellekten okuma (örneğin bir adresten AL'ye) RD ucunu, belleğe yazma (AL'yi 100 numaralı adrese) WR ucunu 0 yapar. Kısacası IN/OUT G/Ç birimleriyle, MOV bellekle ilgilidir.

Neden ayrılmışlar? Bellek birimleri, elektriksel seviye ve haberleşme protokolü açısından mikroişlemciyle uyumludur. G/Ç birimleri ise insanla arayüz oluşturan klavye, monitör, seri haberleşme gibi birimlere bağlanır; bunlar elektriksel seviye ya da protokol bakımından mikroişlemciyle uyumlu olmayabilir. G/Ç birimleri bu dönüşümü ve seviye uyumunu sağlar. Bellekte bir göze "adres" denirken G/Ç biriminin adreslenebilir her gözüne "port" (iskele) denir.

### 10.2 Komut biçimleri

Komut biçimleri port adresinin 8 bite sığıp sığmamasına ve işlemin 8 ya da 16 bitlik olmasına göre tabloda verildi (ekrandan, 01:30:00 ve 01:35:00):

| | Port adresi 8 bite sığar (p8) | Port adresi 8 bite sığmıyor (DX) |
|---|---|---|
| IN, 8 bit | `IN AL, p8` | `IN AL, DX` |
| IN, 16 bit | `IN AX, p8` | `IN AX, DX` |
| OUT, 8 bit | `OUT p8, AL` | `OUT DX, AL` |
| OUT, 16 bit | `OUT p8, AX` | `OUT DX, AX` |

p8, 8 bitlik anlık (immediate) port adresidir; örneğin `IN AL, 10H` 10H adresli porttan değer okur. Port adresi 8 bite sığmıyorsa komuttan önce adres DX'e yüklenir. Hoca port adresi küçük olsa da DX'in kullanılabileceğini, yalnız bu durumda komutun biraz daha uzun sürdüğünü ekledi.

**Soru:** DX'teki porttan gelen değer AL'ye sığmazsa (16 bitlik bir port ise) ne olur?
**Cevap:** Bu durumda verinin yalnız düşük anlamlı kısmı AL'ye kopyalanır; yüksek anlamlı kısım AH'a geçmeyi bekler ama AH'a kopyalama olmadığı için atılır.

**Soru:** `OUT DX, AL`'de AL 8, DX 16 bit; sorun olmaz mı?
**Cevap:** Bu bir MOV değildir. AL'deki 8 bitlik değer, DX ile ifade edilen adrese gönderilir. Adres 16 bitle ifade edilir ama o adresteki göz 8 bitliktir. Tip uyumsuzluğu yoktur.

> **Hocanın vurgusu:** IN ve OUT komutu verilip "burada tip uyumsuzluğu var mı?" diye sormak tam sınavlık bir sorudur. `IN AL, DX` ya da `OUT DX, AL`'de tip uyumsuzluğu yoktur.

### 10.3 Bellek ve G/Ç uzayının kapasitesi

Hoca tahtaya iki soru yazdı (ekrandan, 01:35:00): 8086'nın bellek uzayının kapasitesi nedir, G/Ç uzayının kapasitesi nedir?

Bir öğrenci her bellek gözünün 8 bit olduğunu söyledi; hoca bunun kabul edilebileceğini, toplam kapasitenin $2^n \times 8$ bit olduğunu ($n$ adres ucu sayısı) söyledi. Bir öğrenci 32 bit dedi; hoca 32 bitlik adresin 80386'da olduğunu hatırlattı. Fiziksel adres segment × 10H + offset ile oluşturulur; 16 bitlik segment değeri 10H ile çarpılınca sonuna 4 bit eklenmiş olur ve 20 bitlik adres elde edilir. 8086'nın 20 adres ucu vardır:

$$2^{20} \times 8 \text{ bit} = 1\text{M} \times 1 \text{ bayt} = 1 \text{ MB}$$

G/Ç işlemlerinde port adresi en çok DX ile verilebilir; DX 16 bit olduğu için en büyük adres FFFFH'tir. Yani G/Ç işlemlerinde 16 adres ucu kullanılır:

$$2^{16} \times 8 \text{ bit} = 64\text{K} \times 1 \text{ bayt} = 64 \text{ KB}$$

## 11. Durdurma ve Bekletme Komutları

Slayttaki tanımlar (ekrandan, 01:40:00):

- `HLT`: halt; işlemci durur, bir kesme gelince kaldığı komuttan devam eder.
- `NOP`: no operation; 1 baytlık, işlem yapmayan komut. Makine kodu 90H'dir.
- `WAIT`: wait until not busy; yardımcı işlemcinin sonucunu beklemek için kullanılır.

NOP'un bir kullanımı: kaynak kod yoksa ve yalnız derlenmiş (nesne) kod varsa, genel yapıyı bozmadan bazı baytlar 90H ile değiştirilerek o kısımlar etkisiz hale getirilebilir. Örneğin bir döngüde yaptırılmak istenen yeni işlem orijinal koddan kısa yer tutuyorsa kalan kısım NOP'larla doldurulur.

WAIT yardımcı işlemci (coprocessor) kullanıldığında anlamlıdır. 8086 ile uyumlu matematik yardımcı işlemcisi 8087'dir. Mikroişlemci bir matematik işlemini 8087'ye gönderir ve WAIT çalıştırır; yardımcı işlemci işini bitirince 8086'yı uygun şekilde tetikler, WAIT kırılır ve program devam eder.

## 12. BCD Düzenleme Komutları

Hoca bu komutların da çok kullanılmayacağını, ama birer örnekle akılda kalmasının yararlı olacağını söyledi. Altı komut vardır. Bütün örnekler python ile doğrulandı.

### 12.1 AAA: ASCII adjust after addition

AL'ye `'6'` karakteri atanır; ASCII karşılığı 36H'tir (hoca çift tırnağın da kabul edildiğini kontrol etti). 36H ile `'7'` (37H) ADD ile toplanınca sonuç 6DH olur (ekrandan, 01:50:00). Amaç girilen karakterleri 6 ve 7 sayıları gibi yorumlayıp toplamı unpacked BCD olarak elde etmektir: 6 + 7 = 13. AAA sonrası AH = 01, AL = 03 olur; AX'te unpacked BCD 13 oluşur (her basamak ayrı bir 8 bitlik yazmaçta). AH'ın başlangıçta 0 olduğu varsayıldı (ara adım eklendi).

### 12.2 AAD: ASCII adjust before division

AH = 4, AL = 5 olsun; yani AX = 0405H. Amaç bunun BCD 45 olarak yorumlanmasıdır, ama yan yana konunca büyük bir onaltılık sayı gibi görünür. AAD çalışınca AX'te 45'in onaltılık karşılığı oluşur: 45 = 2DH, yani AX = 002DH (ekrandan, 01:50:00).

### 12.3 AAM: ASCII adjust after multiplication

Slayttaki örnek (ekrandan, 01:45:00):

```asm
MOV AL, 4
MOV AH, 8
MUL AH        ; AX'te 0020H var
AAM           ; AX <- 0302H, BCD olarak 32 sayısı
```

MUL AH, AL ile AH'ı çarpıp sonucu AX'e yazar: 8 × 4 = 32 = 20H. AAM bunu yüksek baytta 3, düşük baytta 2 olacak şekilde BCD biçimine çevirir.

> **Ders sonrası not:** AAM slaytında "ASCII değer olarak tutulan iki sayının toplamını BCD olarak düzenler" yazıyor. Bu cümle büyük olasılıkla AAA slaytından kalmıştır; AAM çarpma sonucunu düzenler.

### 12.4 AAS: ASCII adjust after subtraction

AL'de `'5'` (35H) vardır; `'7'` (37H) çıkarılınca AL = FEH olur. FEH işaretli olarak −2'dir (hoca önce −8 deyip −2 diye düzeltti). Ama sonuç onaltılık değil ASCII/BCD olarak istenir. Elle çıkarma gibi düşünülür: 5'ten 7 çıkmaz, bir elde (borç) alınır, 15 − 7 = 8. Borç olduğu için CF = AF = 1 olur ve AL = 08H elde edilir (ekrandan, 01:50:00).

### 12.5 DAA: decimal adjust after addition

75 ile 19 BCD biçiminde toplanmak istenir. Mikroişlemci 75H + 19H toplamında AL = 8EH üretir. DAA ilk basamağa bakar: 9'dan büyükse 6 ekler. 8EH + 6H: E (14) + 6 = 20, bu 16'yı 4 geçer, bir elde üst basamağa gider; sonuç 94H olur. Onluk toplam da 75 + 19 = 94'tür (ekrandan, 01:50:00).

### 12.6 DAS: decimal adjust after subtraction

42'den 13 çıkarılmak istenir. Mikroişlemciye 42H ve 13H verilince doğrudan çıkarma 2FH verir. Düşük basamak 9'dan büyük olduğu için 6 çıkarılır: 2FH − 6H = 29H, yani BCD 29. Onluk olarak da 42 − 13 = 29'dur (ekrandan, 01:50:00).

**Soru:** 2F değeri nasıl oluştu?
**Cevap:** AL'de 42H var, 13H çıkarılıyor. 2'den 3 çıkmaz; üst basamaktan bir 16 alınır, 18 − 3 = 15 = F. Üst basamakta 4'ten alınan bir düşülür, 3 − 1 = 2. Sonuç 2FH, standart bir ikili çıkarmadır. Sonra 42H ve 13H'ın 42 ve 13'ün BCD gösterimi olduğu düşünülerek sonuç 29'un BCD gösterimi olan 29H'a düzenlenir.

## 13. Veri Adresleme Modları

### 13.1 Çalışma ortamı

Adresleme modlarına geçmeden hoca, programların EXE tipinde olacağını ve bir EXE programının veri kesimi, kod kesimi ve yığın kesiminden oluştuğunu hatırlattı; adresleme modları bu kesimlerden birine erişimi tarif eder. Sonraki derslerde DOSBox emülatörünün kullanılacağını, assembler, linker ve debugger dosyalarının DOSBox'ta bir klasöre bağlanarak (mount) kullanılacağını anlattı. Derleme adımları (ekrandan, 02:10:00):

```text
C:\> masm deneme.asm     -> deneme.obj
C:\> link deneme.obj     -> deneme.exe
C:\> debug deneme.exe
```

DEBUG içinde `T` (trace) her seferinde bir komut yürütür, `R` (registers) yazmaçların durumunu gösterir.

### 13.2 Yazmaç adresleme

Her iki operand da yazmaçtır. Genişlik uyumu gerekir: 16 bitlik yazmaca 16 bitlik yazmaçtan, 8 bitlik yazmaca 8 bitlik yazmaçtan atama yapılır, örneğin `MOV AL, BL`.

### 13.3 Anlık (immediate) adresleme

Sabit bir değer atanır, 8 ya da 16 bitlik olabilir:

- `MOV AL, 0F2H`: F2H 8 bitlik bir sabittir. En yüksek anlamlı onaltılık basamak 9'dan büyükse etiketle karışmaması için başa 0 konur; assembler bunu bekler.
- `MOV CX, 100`: 100 onluk değeri 8 bite sığar; 16 bitlik yazmaçta yüksek baytı 00 olur, boyut sorunu yoktur.
- Sonda `H` onaltılık, `B` ikilik (yalnız 0 ve 1), sonek yoksa onluk sayı demektir; tek tırnakla ASCII karakter atanır.

### 13.4 Doğrudan adresleme

Erişilecek hafıza gözünün doğrudan gösterildiği durumdur (ekrandan, 02:15:00):

```asm
MOV AL, DATA      ; DATA bir etiket olup assembler bunu karşılık gelen adres değeri ile değiştirir
MOV BX, [1234H]   ; BX <- DS:1234H
```

`MOV BX, [1234H]`, veri kesiminin başından 1234H ötedeki word'ü BX'e alır. Etiket ya da değişken kullanmak da doğrudan adreslemedir: `var DW 3` tanımlanıp `MOV AX, var` yazılırsa assembler bunu `MOV AX, [0000H]` gibi bir sabit adrese çevirir (değişken veri kesiminin başındaysa).

### 13.5 Yazmaç dolaylı adresleme

Köşeli parantez içinde bir yazmaç bulunur. Veri için yalnız BX, DI ve SI kullanılabilir. AX, DX, herhangi bir segment yazmacı ve BL, BH gibi 8 bitlik yazmaçlar köşeli parantez içinde kullanılamaz. Yığın için BP kullanılır: köşeli parantez içinde BP varsa varsayılan kesim SS'dir (SS'nin BP offseti), BX/SI/DI varsa DS'dir.

> **Hocanın vurgusu:** Köşeli parantez içinde yalnız BP, BX, DI ve SI kullanılabilir.

Bazı dolaylı adreslemelerde işlem tipi belirtilmelidir (ekrandan, 02:20:00). `INC [BX]` gibi bir komutta BX bir işaretçi gibidir; artırılacak gözün word mü byte mı olduğu bilinmez. Hoca, bazı araçların varsayılan olarak BYTE PTR kabul etse bile bu derste hiçbir varsayılanın kabul edilmeyeceğini, belirsizliğin `BYTE PTR` ya da `WORD PTR` ile mutlaka giderileceğini söyledi: `INC WORD PTR [BX]`. Operandlardan biri yazmaçsa gerek yoktur, çünkü yazmaç işlemin tipini belirler.

BX'in adı base register'dır; köşeli parantezde BX, bir tablonun ya da dizinin başlangıç adresi gibi değerlendirilebilir.

### 13.6 Taban + indis (base plus index) adresleme

Taban yazmacına (BX ya da BP) bir indis yazmacı (DI ya da SI) eklenir: `[BX+SI]`, `[BX+DI]`, `[BP+SI]`, `[BP+DI]`. Hoca emin olmak için `[BP+SI]`'yi derleyicide denedi; derlendi ve beklendiği gibi çevrildi. Aynı denemede `var DB 1` tanımlanıp `MOV AL, var` yazıldı; derleyici değişkeni doğrudan adreslemeye çevirdi.

### 13.7 Yazmaç göreli adresleme

Köşeli parantez içine yazılabilen yazmaçlardan birine (BP, BX, DI, SI) sabit bir değer eklenir. Örneğin BX'te bir tablonun başı var ama anlamlı veri, 100H büyüklüğündeki başlık (header) kısımlarından sonra geliyorsa erişim doğrudan `[BX+100H]` gibi yazılabilir.

### 13.8 Taban göreli + indis adresleme

Bir taban yazmacı, bir indis yazmacı ve bir sabit birlikte kullanılır. Slayttaki örnek (ekrandan, 02:25:00):

```asm
MOV AX, [BX + SI + 100H]   ; iki boyutlu veri adresleme için uygundur
```

Terimlerin yeri değişirse sorun olur mu? Hoca `[BX+100+SI]` yazıp denedi; derleyici bunu `[BX+SI+64h]` biçimine çevirdi. 100 onluk değeri 64H'tir (python ile doğrulandı). Yani sıra önemli değildir. Bu, veri adreslemede karşılaşılabilecek en karmaşık durumdur; taban, indis ve sabitin her alt kümesi de geçerli bir adreslemedir.

> **Hocanın vurgusu:** Sınavda adresleme modunun adı verilip ne olduğu sorulmaz; bir adresleme biçimi verilip geçerli olup olmadığı sorulabilir.

## 14. Program Hafızası Adresleme

Bir sonraki komutun yeri CS ve IP ikilisinde saklıdır (CS segment, IP offset). Normal akışta bir komut yürütülünce IP komutun boyu kadar artar ve bir sonraki komutu gösterir. <!-- BELİRSİZ: hocanın tahtadaki örnekte komut boylarını (4 ve 2 bayt) ve IP artışını (IP+5) söylediği yer altyazıda tutarsız (02:26:13–02:26:33) -->

Program hafızası adresleme, bu ardışık akışı bozup programın başka bir yere dallanmasını sağlayan durumlardır: CS ve IP'yi birlikte ya da yalnız IP'yi değiştiren CALL, RET, JMP ve koşullu dallanma komutları. Üç türü vardır.

### 14.1 Doğrudan program hafızası adresleme

Gidilecek adres komutla birlikte doğrudan sayısal değer olarak verilir; bu bir mutlak dallanmadır. Hocanın örneğinde 100H segmentinin 100H offsetindeki `JMP 200H:300H` komutu çalıştırılınca CS'ye 200H, IP'ye 300H atanır; komutun nerede bulunduğunun önemi yoktur. CALL için de çağrılacak yordam bu şekilde açıkça verilebilir.

### 14.2 Göreli program hafızası adresleme

Slayttaki tanım (ekrandan, 02:30:00): mevcut IP yazmacı değerine göre hangi program hafızasının adresleneceğini ifade eder. JMP komutu 1 bayt ya da 2 bayt işaretli sabit değerli operand kabul eder (disp8, disp16). Örneğin `JMP 100`, bulunulan yerden 100 ilerideki adrese gitmek demektir.

Slayttaki soru: `JMP 0FFH ; IP değeri 1 azalır (NEDEN?)`. Hocanın açıklaması: FFH işaretli sayı olarak −1'dir, bu yüzden bir bayt geriye gidilir. Hoca bunu derleyicide ve DOSBox'taki DEBUG'da denedi. Derleyici sayıyı doğrudan (mutlak) adres gibi yorumladı; etiketle (`JMP L1`) yazınca göreli dallanmaya çevrildi. DEBUG'da birkaç NOP'tan sonra `JMP FF` yazıp adım adım yürüttüğünde IP FF'ye gitti. Hoca burada kendi tarafında bir hata olduğunu, düzeltip sonra bildireceğini; ama etiket kullanıldığında ileri ya da geri dallanmanın göreli adreslemeye çevrildiğini söyledi.

> **Ders sonrası not:** Assembly kaynağında `JMP` operandı hedef adres ya da etikettir; assembler göreli uzaklığı kendisi hesaplar. Bu yüzden `JMP 0FFH` yazınca FFH hedef adres olarak alınır. "IP 1 azalır" yorumu büyük olasılıkla makine kodundaki 8 bitlik uzaklık baytının FFH (−1) olduğu durum içindir (`EB FF`): hedef, bir sonraki komutun adresinin 1 eksiğidir.

### 14.3 Dolaylı program hafızası adresleme

Gidilecek yer doğrudan bir yazmaçla ya da bir yazmacın dolaylı olarak işaret ettiği hafıza bölgesinin içeriğiyle verilir.

## 15. Yığın Adresleme

Slayttaki maddeler (ekrandan, 02:35:00):

- 8086'da yığın geçici veri saklamak için ve fonksiyonlardan dönüşlerde dönüş adreslerini saklamak için kullanılır.
- Yığın LIFO mantığında çalışır (Last In First Out).
- Yığın ile ilgili PUSH ve POP komutları kullanılır.
- PUSH yığına WORD basar, POP yığından WORD çeker. `PUSH BL ; (DOĞRU MU?)` sorusunun cevabı: hayır, 8 bitlik değer yığına basılamaz.
- Yığın adresleme için SS:SP ikilisi kullanılır.

Yığın parametre aktarımında ve CALL ile kesme (INT) işlemlerinde geri dönüş adresini saklamakta kullanılır. Bir CALL ya da INT çalışınca o anki segment ve offset değerleri (gerekiyorsa bayraklar) yığına atılır; alt programın sonunda dönüş komutuyla yığının en üstündeki değerler CS, IP ve gerekiyorsa bayrak yazmacına geri yüklenip kalınan yere dönülür. Ayrıntısı sonraki derslerde, parametre aktarımı ve alt yordamlarla görülecektir.

PUSH ve POP SP'yi otomatik değiştirir. Yığın başta boştur ve SP yığının en uzak adresini gösterir; yığın doldukça adres küçülür. PUSH'ta SP 2 azalır ve word yazılır; POP'ta en üstteki word okunur ve SP 2 artar, okunan göz artık çöp sayılır.

> **Ders sonrası not:** Hoca SP'nin "yığında her zaman sıradaki boş gözü gösterdiğini" söyledi. 8086'da PUSH önce SP'yi 2 azaltıp sonra yazar, POP önce okuyup sonra SP'yi 2 artırır; bu yüzden SP büyük olasılıkla yığının en üstündeki dolu word'ü gösterir. Hoca da anlatımın bir yerinde SP'nin "yığının en üstündeki gözü" gösterdiğini söyledi.

Hoca, sözde komutları (pseudo-op) sonraki derse bıraktı. Derste önemli olanın veri erişimindeki adresleme modlarını doğru kullanabilmek olduğunu söyledi: hangi komutların geçerli olduğu, köşeli parantez içine hangi yazmaçların yazılabileceği ve verilen bir adreslemenin geçerli olup olmadığı.

## Örnek Sorular

**1.** (ekrandan, 00:30:00) `dizi1 DB 'abcdefgh....'` (20 karakter), `dizi2 DB 20 DUP(?)`, `n DW 20` veriliyor. dizi1'i dizi2'ye MOVSB ile kopyalayın.

> **Çözüm (derste verildi):** `LEA SI, dizi1` / `LEA DI, dizi2` / `CLD` / `MOV CX, n` / `REP MOVSB`.

**2.** (ekrandan, 00:40:00) `dizi1 DB 'abcdefgh....'`, `dizi2 DB 'abcdefGh....'`, `n DW 20`. İki dizi için karşılıklı elemanlarda ilk farklı değeri ve indisini bulun.

> **Çözüm (derste verildi, ders sonrası notla):** `LEA SI, dizi1` / `LEA DI, dizi2` / `CLD` / `MOV CX, n` / `REPZ CMPSB` / `JNZ farkli`. Farklı elemanlar `[SI-1]` ve `[DI-1]`'dedir; indis $n - CX - 1 = 6$ (python ile kontrol edildi).

**3.** (derste sözlü, 00:50:50) Bir word dizisinde 8 değerinin yer alıp almadığını ve varsa indisini bulun.

> **Çözüm (derste verildi):** `LEA DI, dizi` / `MOV CX, n` / `MOV AX, 8` / `CLD` / `REPNZ SCASW` / `JZ buldum`. Bulunan word büyük olasılıkla `[DI-2]`'dedir.

**4.** (ekrandan, 01:00:00) `dizi1 DB 25 DUP(?)` dizisinin elemanlarını sıfırlayın; sonra dizi1'i 1'den 25'e kadar değerlerle ilklendirin.

> **Çözüm (derste verildi):** Sıfırlama: `LEA DI, dizi1` / `MOV CX, n` / `CLD` / `XOR AL, AL` / `REP STOSB`. İlklendirme: REP kullanılamaz; `XOR AL, AL` / `L1: INC AL` / `STOSB` / `LOOP L1`.

**5.** (derste sözlü, 01:08:35) `MOV AX, 8000H` / `CWD` sonrasında DX'te hangi değer oluşur?

> **Çözüm (derste verildi):** DX = FFFFH, AX = 8000H.

**6.** (ekrandan, 01:35:00) 8086'nın bellek uzayının ve G/Ç uzayının kapasitesi nedir?

> **Çözüm (derste verildi):** Bellek: 20 adres ucu, $2^{20} \times 8$ bit = 1 MB. G/Ç: port adresi en çok 16 bitlik DX ile verilir, $2^{16} \times 8$ bit = 64 KB.

**7.** (derste sözlü, 01:37:11) `OUT DX, AL` komutunda tip uyumsuzluğu var mıdır?

> **Çözüm (derste verildi):** Yoktur. Bu bir MOV değildir; DX port adresini verir, AL'deki 8 bitlik değer o adresteki 8 bitlik göze gönderilir.

**8.** (ekrandan, 02:20:00) Dolaylı adreslemede operandlardan biri yazmaç ise BYTE PTR, WORD PTR'ye neden gerek yoktur?

> **Çözüm (derste verildi):** Yazmacın boyu (8 ya da 16 bit) işlemin tipini belirler.

**9.** (ekrandan, 02:30:00) `JMP 0FFH ; IP değeri 1 azalır (NEDEN?)`

> **Çözüm (derste verildi, ders sonrası notla):** FFH işaretli 8 bitlik sayı olarak −1'dir, bu yüzden bir bayt geri gidilir. Bu yorum makine kodundaki uzaklık baytı için geçerlidir; assembly kaynağında `JMP 0FFH` mutlak hedef adres olarak yorumlanır.

**10.** (ekrandan, 02:35:00) `PUSH BL` doğru mu?

> **Çözüm (derste verildi):** Hayır. PUSH yığına word basar; 8 bitlik yazmaç yığına basılamaz.

## Dersin Toparlaması

Bu derste 8086'nın dizi komutları (MOVS, CMPS, SCAS, LODS, STOS) ve tekrarlama önekleri (REP, REPZ, REPNZ) ayrıntılı örneklerle işlendi. Kaynağın DS:[SI], hedefin ES:[DI] olduğu, yönün DF ile belirlendiği, tekrar sayısının CX'e eleman adedi olarak yüklendiği ve REP/LOOP'un bayrakları etkilemediği vurgulandı. Kopyalama, ilk farklı elemanı bulma, dizide arama, sıfırlama ve sıralı değerlerle doldurma örnekleri, hangi durumda REP'in, hangi durumda LOOP'un uygun olduğunu gösterdi. Ardından CBW/CWD ile işaret genişletme, IN/OUT ile port erişimi ve bellek/G/Ç uzayı kapasitesi, HLT/NOP/WAIT ve altı BCD düzenleme komutu birer örnekle görüldü.

Son bölümde veri adresleme modları (yazmaç, anlık, doğrudan, dolaylı, taban + indis, göreli, taban göreli + indis), program hafızası adresleme (doğrudan, göreli, dolaylı) ve yığın adresleme anlatıldı. Hoca köşeli parantez içinde hangi yazmaçların kullanılabileceğinin ve bir adreslemenin geçerli olup olmadığını söyleyebilmenin önemli olduğunu belirtti. Sonraki derste sözde komutlarla ve DOSBox ortamında EXE tipi programlarla devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
