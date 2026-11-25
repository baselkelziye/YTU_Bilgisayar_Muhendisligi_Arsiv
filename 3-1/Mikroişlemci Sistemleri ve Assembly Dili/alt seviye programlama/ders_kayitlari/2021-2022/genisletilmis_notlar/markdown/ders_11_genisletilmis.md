# Ders 11 Genişletilmiş Notu: COM Tipi Programlar, İki Sözdizimi ve Örnekler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Akışı
- 2. EXE Tipi ve COM Tipi Program
- 3. COM Tipi Programın Bellekteki Yerleşimi
- 4. Sözdizimi 1: Önce Veri, Sonra Kod
- 5. Örnek 1: Sıcaklık Dizisinde −20'nin Altında Değer Var mı?
- 6. Derleme, Bağlama ve COM Dosyası Üretme
- 7. Örnek 1'in DEBUG ile İzlenmesi
- 8. Sözdizimi 2: Önce Kod, Sonra Veri
- 9. Örnek 2: Sıraya Karışan Kişiyi Bulma
- 10. Örnek 2'nin DEBUG ile İzlenmesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Akışı

Önceki derslerde EXE tipi program örnekleri yapılmıştı. Bu derste COM tipi programlar ele alındı. Hoca önce EXE ile COM arasındaki farkı ve COM programının tek bir kesim içindeki yerleşimini tablet üzerinde çizdi, ardından COM tipi programın iki sözdizimini (syntax) anlattı ve her sözdizimi için bir örnek çözdü. Her örnekte önce soru okunup akış diyagramı çizildi, sonra kod Sublime Text'te yazıldı, DOSBox içinde MASM, LINK ve EXE2COM ile derlendi ve DEBUG ile adım adım izlendi. Ders Zoom üzerinden yürütüldü.

## 2. EXE Tipi ve COM Tipi Program

EXE tipi programda temel olarak üç kesim vardır: yığın kesimi (SS), kod kesimi (CS) ve veri kesimi (DS); gerekirse ek kesim (ES) de kullanılır. Bunların her biri en çok 64 KB'lık bir blok olarak oluşturulabilir. Program yazıldıktan, veriler ve yığın kullanımı belli olduktan sonra bir boyut ortaya çıkar; buna 512 baytlık bir başlık (header) eklenir. Yani `.exe` dosyasının boyu, programın boyu ile başlık boyunun toplamıdır (ekrandan, 00:15:00).

COM tipi programda ("compact", yani küçük) yığın, kod ve veri kesimlerinin hepsi tek bir 64 KB'lık alanın içinde tanımlanır. Başlık bilgisi yoktur; bu yüzden COM dosyalarının EXE'ye göre çok daha küçük olduğu görülür. Yapılacak iş 64 KB'a sığmıyorsa EXE tipi program yazmak gerekir. Hoca derste yazılacak programların 40-50 bayttan en çok 200 bayta kadar olduğunu, bu ölçekte 64 KB'ın "hayli hayli büyük" bir alan olduğunu belirtti.

## 3. COM Tipi Programın Bellekteki Yerleşimi

Tahtadaki çizim (ekrandan, 00:15:00) 1 MB'lık belleği ve onun içinde program için ayrılmış tek bir 64 KB'lık kesimi gösteriyordu. Bu kesimin ofsetleri 0000h'den FFFFh'ye kadar gider. CS, SS ve DS yazmaçlarının hepsi bu kesimin başını gösterir; tek bir program tek bir kesimin içindedir.

Kesimin içi, word düzeninde aşağıdan yukarıya şöyle düzenlenir:

- 0000h-00FFh: PSP (Program Segment Prefix). Programın parametreleri ve işleyişiyle ilgili çeşitli bilgileri tutan, 100h baytlık alandır.
- 0100h'den itibaren: program. Programın 100h'den sonra başlayacağını söylemek için `ORG` (origin) sözde komutu kullanılır: `ORG 100h`.
- FFFEh-FFFFh: kesimin son iki baytı. Buraya program sonlandıktan sonra kullanılacak, değeri 0 olan bir word dönüş ofseti yerleştirilir.

Hoca bunu EXE tipi programla karşılaştırdı. EXE'de program başında yığına önce DS'nin değeri `PUSH` edilir, ardından AX sıfırlanıp o da `PUSH` edilir. COM tipi programda bu yapılmaz; FFFEh adresinde varsayılan olarak bir word'lük sıfır değeri zaten bulunur.

Geri kalan alana diğer kesimler yerleşir. Yığın FFFEh'den başlayıp aşağıya doğru büyür; yani yığın kullanıldıkça SP azalır. 0100h'den yukarıya doğru ise kod ve veri yerleşir; kod yürüdükçe IP artar. Kod ve verinin bu alana yerleşmesi iki şekilde olabilir: altta veri, üstte kod ya da altta kod, üstte veri. COM tipi programın iki sözdizimi bu iki yerleşime karşılık gelir.

Hoca şu durumu düşündürdü: binlerce elemanlı diziler, çok hacimli bir kod ve yoğun yığın kullanımı varsa veri ve kod yukarıya, yığın aşağıya doğru büyür ve bir süre sonra alan yetersiz kalır. Program COM'a sığmıyorsa artık "compact" değildir ve EXE tipi yazılması beklenir.

## 4. Sözdizimi 1: Önce Veri, Sonra Kod

Sözdizimi 1'in iskeleti tahtada şöyle yazıldı (ekrandan, 00:25:00):

```text
codeseg   SEGMENT PARA 'kod'
          ORG 100h
          ASSUME DS:codeseg, SS:codeseg, CS:codeseg
Bilgi:    JMP BASLA
sayi1     DB ?
wsayiB    DW 17h
          ...
BASLA     PROC NEAR
          ...
          XOR BX, AX      ; ofseti 010D olsun
          ...
          RET
BASLA     ENDP
codeseg   ENDS
          END Bilgi
```

Kesimin içinde ilk yazılan satır `ORG 100h`'dir. PSP 100h baytlık yer kapladığı için programın kökeni 100h'den sonra başlamalıdır; COM tipi programda bu muhakkak yazılır. Ardından `ASSUME` ile hangi kesim yazmacı için hangi kesim adının kullanıldığı yazılır. Tek bir kesim adı vardır ve CS, DS ve SS'nin hepsi için bu ortak ad kullanılır.

Sözdizimi 1'de önce veri yerleştirilir. Ancak program kod olarak kesimin başından çalışmaya başlayacağı için verilerden önce koşulsuz bir dallanma (`JMP`) ile ana yordama atlanır; bu satıra da bir etiket (`Bilgi`) verilir. `JMP`'tan sonra değişkenler (veri kesimi) yazılır, ardından `JMP` ile atlanan `BASLA` yordamı başlar.

COM tipi programda bütün yordamlar aynı kesimin içindedir; ana yordam dahil kullanılan bütün yordamlar `NEAR` tanımlanır. Hoca ileride yordamlar arası geçişlerde dallanılan yordamın NEAR ya da FAR olmasına göre yığına farklı değerler atıldığını göreceklerini söyledi. EXE tipi programdan farklı olarak `PUSH DS` ile başlayan, dönüş değerlerini yığına atan ve veri kesimi numarasını DS'ye yükleyen beş satırlık kod yazılmaz: zaten tek bir kesim vardır ve dönüş ofseti yığında varsayılan olarak durur. Yordam `RET` ile (FAR olmadığı için RETF değil) sonlandırılır, `ENDP` ile kapatılır; kesim `ENDS` ile kapatılır.

En sondaki `END`'den sonra EXE tipi programda başlangıç yordamının adı yazılıyordu. Burada ise programın başladığı nokta, yani `JMP`'ın bulunduğu satırın etiketi (`Bilgi`) yazılır. Program önce o satırdan başlar, oradan ana yordama atlar ve akış oradan devam eder. Kod içinde `PUSH` ve `POP` ile yığın kullanılabilir (ekrandan, 00:25:00).

### 4.1 Sözdizimi 1'de ofset kayması

Hoca bu sözdiziminde dikkat edilmesi gereken bir noktayı vurguladı. Örneğin kodda `XOR BX, AX` komutunun ofseti 010Dh olsun ve bu ofsete göre işlem yapılıyor (örneğin oraya dallanılıyor) olsun. Yukarıdaki değişken tanımlarına `DD ?` gibi 4 baytlık yeni bir değişken eklenirse bütün kod 4 bayt aşağıya kayar ve 010Dh artık o komutun adresi olmaz.

> **Hocanın vurgusu:** Sözdizimi 1'de veri kesiminde yapılan her değişiklik altındaki kodun ofsetlerini kaydırır; ofsete bağlı işler yapılıyorsa bu kontrol edilmelidir.

## 5. Örnek 1: Sıcaklık Dizisinde −20'nin Altında Değer Var mı?

Soru (ekrandan, 00:30:00): "1 yıl süresince günlük en düşük ve en yüksek hava sıcaklığı bulunan bir dizide −20'nin altında sıcaklık değeri olup olmadığını bulan COM tipi assembly programını yazınız." Sözdizimi 1 kullanılacaktır. Ek bilgi olarak en düşük sıcaklıkların en küçüğünün −92, en yüksek sıcaklıkların en büyüğünün 56 olduğu verildi.

### 5.1 Sorudan çıkarılanlar

Hoca soruyu okurken şu çıkarımları yaptı (ekrandan, 00:30:00; tahtada "G/L" ve "Byte" notları):

- Değerler −92 ile 56 arasındadır; byte'a sığar. En düşük değer −128'den küçük ya da en yüksek değer 127'den büyük olsaydı dizi byte'a sığmaz, word kullanmak gerekirdi. Bu bilgi önemlidir, çünkü özellikle çarpma ve bölmede byte ve word tanımlı verilerle kullanılan yazmaçlar ve işlevleri değişir.
- Sıfırın altında değerler vardır ve −20 ile karşılaştırma yapılacaktır. Sayılar hep pozitif olsaydı above/below'lu karşılaştırma yapılırdı; negatif olabildikleri için greater/less'li (`JG`, `JL` ailesi) karşılaştırma yapılır.

### 5.2 for mu, while mı?

Bir yılı 365 gün kabul eden 365 elemanlı bir dizi için akla ilk gelen `for` olabilir. Ama soru −20'nin altında değer olup olmadığını soruyor. Diyelim ki 10. elemanda −20'nin altında bir değer bulundu; geri kalanları kontrol etmeye gerek yoktur. Soru "−20'nin altında kaç tane değer vardır?" olsaydı bütün dizi `for` ile gezilmeliydi. Var/yok sorusu için `while` kullanılmalıdır.

> **Hocanın vurgusu:** Bu soru `for` ile çözülmemelidir; değer bulunduğu anda döngüden çıkılmalıdır.

### 5.3 Akış diyagramı

Tahtadaki akış diyagramı metin olarak şöyledir (ekrandan, 00:30:00 ve 00:50:00):

```text
START
  n <- 365, i <- 0, dizi[n] <- {...}, esik <- -20
  while (i < n && dizi[i] > esik):
      i++
  if (i == n):  T -> s = 1   ("yoktur")
                F -> s = 7   ("vardır")
STOP
```

While içine yazılan ifade çıkma koşulu değil dönme koşuludur: sıcaklık eşikten büyük olduğu ve dizinin sonuna gelinmediği sürece dönülür ve döngü içinde bir sonraki elemana geçmek için `i` bir artırılır. Döngüden iki şekilde çıkılabilir: ya dizinin sonuna gelinmiş ve −20'nin altında değer bulunamamıştır ya da −20'nin altında bir değer bulunmuştur. Hoca programlaması ve anlaşılması daha kolay olduğu için çıkışta yalnız ilk koşulu kontrol etti: `i == n` ise (i 0'dan 364'e kadar gidip 365 olmuşsa) dizi bitmiş ve değer bulunamamıştır, sonuç 1 ("yoktur"); değilse sonuç 7 ("vardır"). Hoca 1 ve 7 değerlerini yalnız birbirinden farklı olsunlar diye seçtiğini söyledi.

> **Ders sonrası not:** Soruda istenen "−20'nin altında" yani dizi[i] < −20 durumudur. Bunun tersi olan dönme koşulu tam olarak dizi[i] ≥ esik olmalıdır. Akış diyagramında dizi[i] > esik yazıldı; kodda ise `CMP AL, dizi[SI]` / `JG vardir` ile yalnız esik > dizi[i] olduğunda çıkıldığı için kod soruya uygundur. Fark yalnız değerin tam −20 olduğu durumda ortaya çıkar.

Hoca kodlamaya geçmeden önce şu kararları verdi:

- `i` için SI kullanılacak.
- Döngü `for` olmasa bile dizinin elemanlarıyla ilgili işlem yapılıyorsa, uygunsa `n` değeri CX'e alınmalıdır.
- `dizi[i]` ile `esik`'in ikisi de bellek alanıdır; `CMP` iki bellek operandını karşılaştıramaz. Değişmeyen taraf olan eşik sürekli AL'de tutulur. Veri byte olduğu için AX değil AL kullanılır; AH, BH gibi başka byte yazmaçları da olabilir.

### 5.4 Kod

Hoca kodu `021221a.asm` adıyla Sublime Text'te yazdı (ekrandan, 00:40:00 ve 00:45:00). Önce iskeleti yazdı: kesim tanımı, `ORG 100h`, `ASSUME`, `basla:` etiketli `JMP SICAKLIK`, `SICAKLIK PROC NEAR` ... `RET` / `ENDP`, `ENDS` ve `END basla`. Son hali:

```text
codeseg   SEGMENT PARA 'kod'
          ORG 100h
          ASSUME CS:codeseg, DS:codeseg, SS:codeseg
basla:    JMP SICAKLIK
n         DW 5                    ; 365
dizi      DB 15, -19, 20, 50, -25 ; DB 365 DUP(?)
esik      DB -20
sonuc     DB ?
SICAKLIK  PROC NEAR
          XOR SI, SI
          MOV CX, n
          MOV AL, esik
don:      CMP SI, CX
          JAE yoktur
          CMP AL, dizi[SI]        ; CMP dizi[SI], AL
          JG vardir
          INC SI
          JMP don
vardir:   MOV sonuc, 7
          JMP son
yoktur:   MOV sonuc, 1
son:      RET
SICAKLIK  ENDP
codeseg   ENDS
          END basla
```

<!-- BELİRSİZ: vardir satırından sonraki satırların ekran görüntüsü yok; altyazıdaki anlatım ve 00:55:00'daki bellek dökümündeki makine kodu (C6 06 0B 01 07, EB 06, 90, C6 06 0B 01 01, C3) ile kuruldu. -->

Değişkenlerle ilgili açıklamalar:

- `n` word tanımlandı. 365 byte'a sığmaz, word gerekir. Hoca n byte'a sığacak kadar küçük olsa bile word tanımlamanın daha yararlı olacağını söyledi, çünkü n bir süre sonra CX'e atanacaktır (özellikle `for` kullanılıyorsa).
- Dizinin gerçek tanımı `DB 365 DUP(?)` biçimindedir: 365 elemanlık yer ayrılır, değerleri o an bellekte ne varsa odur. Bu değerler −92...56 aralığını sağlamayabilir, ama 365 değeri tek tek yazmak mümkün olmadığından bu tanım kullanılır. Derste test için bu satır ve 365 yorum satırı yapıldı, `n` 5'e düşürüldü ve dizi 15, −19, 20, 50, −25 olarak yazıldı.
- `esik` = −20 (`DB -20`), sonuç için `sonuc DB ?` tanımlandı. Hoca `sonuc`'u başta 7 tanımlayıp yalnız bir kolda 1 yazmanın da mümkün olduğunu, ama iki kolda da atama yapılsın diye başlangıç değerini serbest bıraktığını söyledi.

Kodun adımları:

- `XOR SI, SI`: i ← 0. `i`'yi ayrıca bellekte tanımlamaya gerek yoktur.
- `MOV CX, n`: dizi boyu CX'e alınır. `MOV AL, esik`: eşik AL'ye alınır.
- `don: CMP SI, CX` / `JAE yoktur`: dönme koşulunun ilk parçası `i < n`'dir. Bunun tersi `i ≥ n` olduğunda döngüden çıkılır ve o durumda değer bulunamamıştır; bu yüzden doğrudan `yoktur` etiketine atlanabilir. İndis ve dizi boyu negatif olamayacağı için above/below ailesinden `JAE` kullanıldı.
- `CMP AL, dizi[SI]` / `JG vardir`: AL = −20 ve dizi[i] = −22 ise AL daha büyüktür (negatif sayılar küçüldükçe mutlak değerce büyür). Yani AL > dizi[i] ise −20'nin altında bir sıcaklık bulunmuştur ve `vardir` etiketine atlanır.
- İki dallanma da olmadıysa döngü gövdesi çalışır: `INC SI` ve `JMP don`.
- `vardir: MOV sonuc, 7` / `JMP son`; `yoktur: MOV sonuc, 1`; `son: RET`.

Hoca ikinci karşılaştırmanın `CMP dizi[SI], AL` biçiminde de yazılabileceğini, ama karşılaştırılan taraflardan biri AL ise onu ilk operand yapmanın daha performanslı ve "daha şık" olduğunu söyledi.

> **Ders sonrası not:** 8086 zamanlama tablolarında `CMP reg, mem` ile `CMP mem, reg` büyük olasılıkla aynı süreyle (9 + EA saat çevrimi) verilir; akümülatöre özel kısa kodlama yalnız anlık (immediate) operandlı `CMP AL, imm8` / `CMP AX, imm16` biçimleri içindir. İki yazımın da çalıştığı derste ikinci örnekte gösterildi.

**Soru:** İndis ile dizi boyunun karşılaştırmasında neden greater/less değil de above/below kullanıldı?
**Cevap:** n dizinin boyutu, i de 0'dan yukarı giden indis değişkenidir; ikisi de negatif olamaz. Bu yüzden above/below komutları kullanılır. `i < n`'nin tersi `i ≥ n` olduğu için `JAE` yazıldı.

**Soru:** (sohbetten) n'i CX'e almadan, `CMP SI, n` yazarak karşılaştırma yapamaz mıydık?
**Cevap:** Yapılabilirdi; bir taraf yazmaç, diğer taraf bellek olabilir. Ama örneğin yazmaç-yazmaç karşılaştırması 2 saat çevrimi, yazmaç-bellek karşılaştırması 3 saat çevrimi sürüyorsa döngü her turda bir çevrim fazla harcar; en kötü durumda 365 çevrim fazla işlem yapılır. Karşılaştırma döngü içinde tekrarlanıyorsa ve yazmaçlar müsaitse iki tarafın da yazmaç olması yararlıdır. (Hocanın verdiği çevrim sayıları örnek amaçlıdır.)

## 6. Derleme, Bağlama ve COM Dosyası Üretme

Çalıştırma DOSBox içinde yapıldı (ekrandan, 00:50:00). Klasör DOSBox'a `mount` ile bağlandıktan sonra adımlar şunlardır:

- `dir 021221a.*` ile dosya listelenir; başta yalnız `.asm` dosyası vardır.
- `masm 021221a.asm;`: Microsoft Assembler (MASM) kaynak kodu assemble eder. Sondaki noktalı virgül, MASM'ın ek dosya adı sorularını sormaması içindir. Sözdizimi hatası varsa MASM bildirir; hata yoksa `.obj` dosyası oluşur.
- `link 021221a.obj;`: linker'dan geçirilir ve `.exe` oluşur. Bu adımda `LINK : warning L4021: no stack segment` uyarısı çıktı.
- `exe2com 021221a.exe`: EXE dosyası COM dosyasına çevrilir.

Hoca assembly dilinde uyarıların da hatalar kadar kritik olduğunu söyledi. Java gibi dillerde sarı uyarılar umursanmadan geçilebiliyor olabilir, ama burada program hiç uyarı ve hata olmadan yazılmalıdır. Tek istisna COM tipi programda çıkan "no stack segment" uyarısıdır: ayrı bir yığın kesimi olmadığı zaten bilinmektedir.

> **Hocanın vurgusu:** Assembly'de hem uyarılara hem hatalara çok dikkat edilmelidir; COM programındaki "no stack segment" uyarısı dışında hiçbiri kabul edilmez.

Dosya boyları karşılaştırıldığında EXE 816 bayt, COM yalnız 48 bayt çıktı (ekrandan, 00:50:00). Hoca bunun "compact" olmanın avantajı olduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** 816 baytlık EXE boyu büyük olasılıkla şöyle oluşur: program `ORG 100h` ile 0100h'den başladığı için EXE görüntüsünde önce 100h = 256 baytlık boşluk, ardından 48 baytlık kod ve veri bulunur; buna 512 baytlık başlık eklenince 256 + 48 + 512 = 816 bayt eder.

Hoca çalıştırma önceliğini de anlattı: programın yalnız adı yazılıp Enter'a basıldığında, aynı adda hem COM hem EXE dosyası varsa önce COM tipi program çalışır. Buradaki EXE zaten standart bir EXE gibi üç kesimden oluşmadığı, tek kesimden oluştuğu için düzgün çalışabilir bir program değildir. Program kullanıcıdan değer almadığı ve ekrana bir şey yazdırmadığı için çalışıp sonlanır; sonucu görmek için program DEBUG ile açılıp veri alanına bakılır.

## 7. Örnek 1'in DEBUG ile İzlenmesi

### 7.1 Bellek yerleşimi

DEBUG'da `u` ile koda bakıldığında ilk komutun `JMP` olduğu ve 010Ch'ye (SICAKLIK yordamının başı) atladığı görüldü. `JMP` de bir komut olduğu için onun da makine kodu vardır ve ondan sonra veriler başlar. Bellek dökümünde (ekrandan, 00:55:00) şunlar görüldü:

| Adres | Değişken | Bayt(lar) | Ondalık değer |
|---|---|---|---|
| 0100h | `JMP SICAKLIK` | 3 bayt | — |
| 0103h | `n` | 05 00 | 5 |
| 0105h | `dizi` | 0F ED 14 32 E7 | 15, −19, 20, 50, −25 |
| 010Ah | `esik` | EC | −20 |
| 010Bh | `sonuc` | (program sonunda 07) | 7 |

Hoca onaltılık değerleri ondalığa çevirdi: 0Fh = 15; 14h = 1 × 16 + 4 = 20; 32h = 3 × 16 + 2 = 50. E7h ve ECh işaretli byte olarak sırasıyla −25 ve −20'dir (python ile kontrol edildi). `n` word olduğu için iki bayt (05 00) yer kaplar.

Önceki örneklerde veri kesimine `d ds:0` ile bakılıyordu. COM programında veri `JMP`'tan sonra 0103h'den başladığı için `d ds:103` ile bakılmalıdır. Hoca önce yanlışlıkla `d ds:0` yazdı ve bunu düzeltti. `g` (go) ile program sonlandırıldıktan sonra `d ds:103` ile bakıldığında 010Bh'deki `sonuc` baytının 07 olduğu, yani "vardır" sonucunun üretildiği görüldü (ekrandan, 00:55:00).

Ardından dizinin son elemanı −25 yerine −17 yapılıp program yeniden derlendi (MASM, LINK, EXE2COM); bu kez sonuç 1 ("yoktur") oldu. Sonra yeniden −25 yapılıp adım adım izlendi.

### 7.2 Adım adım izleme

`t` (trace) ile adım adım ilerlendi (ekrandan, 01:00:00):

- `JMP` çalıştı ve `XOR SI, SI` komutuna, yani kodun başladığı yere atlandı. SI zaten 0'dı, XOR sonrasında da 0 kaldı.
- `MOV CX, [0103]`: bellekteki 0103h'deki 5 değeri CX'e yüklendi (CX önceden 0030 idi, 0005 oldu).
- `MOV AL, [010A]`: AL'ye EC, yani −20 yüklendi.
- `CMP SI, CX`: SI = 0, CX = 5 karşılaştırıldı. DEBUG, kodda yazılan `JAE`'yi `JNB` (küçük değilse atla) olarak gösterdi. "Büyük eşitse" ile "küçük değilse" aynı anlama gelir. 0, 5'ten küçük olduğu için atlanmadı.
- `CMP AL, [SI+0105]`: −20 ile 15 karşılaştırıldı. −20, 15'ten büyük olmadığı için `JG` atlamadı; SI bir artırıldı ve `JMP` ile ilk karşılaştırmaya (0115h) dönüldü.
- SI = 1: dizideki ED (−19) ile karşılaştırıldı. Sayısal olarak ED, EC'den büyük görünse de işaretli sayılar olarak −20 < −19'dur; `JG` atlamadı.
- SI = 2 ve SI = 3: 14h (20) ve 32h (50) için de −20 büyük olmadığı için döngü devam etti.
- SI = 4 (hâlâ CX = 5'ten küçük): E7h (−25) ile karşılaştırıldı. −20 > −25 olduğu için `JG` 0122h'ye atladı; IP 0122 oldu.
- 0122h'deki `MOV BYTE PTR [010B], 07` ile `sonuc`'a 7 yazıldı; ardından `son` etiketindeki `RET`'e atlandı. `d ds:10B` ile 7 değeri görüldü.

DEBUG'daki makine kodları ve dallanma hedefleri python ile kontrol edildi: `JNB 012A` (`yoktur`), `JG 0122` (`vardir`), `JMP 0115` (`don`), `JMP 012F` (`son`). Kod 010Ch'den 012Fh'ye kadar 36 bayttır; `JMP` ve verilerle birlikte program 0100h-012Fh arasında 30h = 48 bayt tutar, bu da COM dosyasının boyuyla aynıdır.

## 8. Sözdizimi 2: Önce Kod, Sonra Veri

İkinci sözdiziminde (hocanın deyişiyle sözdizimi 2, model 2 ya da tip 2) önce kod kesimi, sonra veri kesimi yerleştirilir. Tahtadaki iskelet (ekrandan, 01:20:00):

```text
mys       SEGMENT PARA 'my'
          ORG 100h
          ASSUME CS:mys, DS:mys, SS:mys
ANA       PROC NEAR
          ...
          RET
ANA       ENDP
sayib1    DB 17
sayi      DW ?
mys       ENDS
          END ANA
```

İki sözdiziminde de program 100h'den başlatılır. Sözdizimi 1'de önce `JMP` ile ana yordama atlanıyordu; burada doğrudan kod yazılır. Yordam yine `NEAR` tanımlanır ve `RET` ile biter. COM tipinde yalnız bir yordam olmak zorunda değildir; birden fazla yordam tanımlanabilir (hoca bunları sonraki haftalarda göreceklerini söyledi). En son tanımlanan yordamın `ENDP` satırından sonra değişkenler yerleştirilir, ardından kesim kapatılır. En sondaki `END`'den sonra bu kez ana yordamın adı yazılır.

Sözdizimi 1'deki sorun, veri üstte olduğu için yeni bir değişken eklenince bütün kodun kaymasıydı. Sözdizimi 2'de kod yukarıda, veri aşağıdadır; bu kez yeni bir kod satırı eklendiğinde veriler aşağıya kayar.

> **Hocanın vurgusu:** Sözdizimi 2'de kod eklendikçe verinin adresi değişir; aranan veri beklenen adreste bulunmayabilir.

## 9. Örnek 2: Sıraya Karışan Kişiyi Bulma

Soru (ekrandan, 01:25:00): "15 yaşından küçük ve 50 yaşından büyük 10 tane kişinin olduğu sıraya yaş koşulunu bozan 11. kişi karışmıştır. Sıradaki tüm kişilerin yaşları bilindiğine göre, sıraya sonradan karışan kişinin baştan kaçıncı sırada olduğunu bulan COM tipi assembly programını yazınız." Yani 11 kişilik sırada yaşı 15 ile 50 arasında olan tek bir kişi vardır.

### 9.1 Sorudan çıkarılanlar

Yaş söz konusu olduğu için dizideki bütün değerler pozitiftir ve hiçbir insanın yaşı 255'i geçmez; dizi byte tanımlıdır. Karşılaştırmalar yaş üzerinden yapıldığı için above/below'lu (`JA`, `JB` ailesi) komutlar kullanılır.

Yine `while` kullanılmalıdır: örneğin karışan kişi üçüncü sıradaysa dördüncü ve beşinci sıradakilere bakmaya gerek yoktur. Önceki problemde değerin dizide olup olmadığı bilinmiyordu, bu yüzden dizinin sonuna gelinip gelinmediği de kontrol edilmeliydi. Burada soruda kesin olarak birinin karıştığı söylendiği için dizinin sonu ayrıca kontrol edilmez.

### 9.2 OR koşullu while ve akış diyagramı

Akış diyagramı (ekrandan, 01:25:00 ve 01:30:00):

```text
START
  i <- 0, k_esik <- 15, b_esik <- 50
  while (dizi[i] < k_esik  or  dizi[i] > b_esik):
      i++
  indeks <- i
STOP
```

Dizinin i. elemanı küçük eşikten küçükse ya da büyük eşikten büyükse o kişi aranan kişi değildir; `i` artırılıp yeni değere geçilir. Hoca bu örneği özellikle OR yapısı kurmak için seçtiğini, daha önce while yapılmış olsa da OR'lu bir koşul yapılmamış olabileceğini söyledi. OR'un doğruluk tablosu tahtada şöyle yazıldı (ekrandan, 01:30:00): (1, 1) → dön, (1, 0) → dön, (0, 1) → dön, (0, 0) → çık. Yani iki koşul da bozulduğunda döngüden çıkılır.

Hoca üç değerle denedi:

- 14: 15'ten küçük müdür? Evet. Birinci koşul sağlandığı için dönülür, i artırılır.
- 34: 15'ten küçük değildir; 50'den büyük de değildir. İki koşul da bozulduğu için döngüden çıkılır; aranan kişi budur.
- 54: 15'ten küçük değildir, ama 50'den büyüktür. İkinci koşul sağlandığı için yine dönülür.

Döngüden çıkıldığında `i`, `indeks` adlı değişkene yazılır ve program sonlandırılır.

### 9.3 Kod

Kod `021221b.asm` adıyla yazıldı (ekrandan, 01:35:00):

```text
mys        SEGMENT PARA 'my'
           ORG 100h
           ASSUME CS:mys, DS:mys, SS:mys
KAYNAK_BUL PROC NEAR
           MOV AL, k_esik
           MOV AH, b_esik
don:       CMP dizi[BX], AL
           JB sonraki
           CMP dizi[BX], AH
           JBE bulundu
sonraki:   INC BX
           JMP don

bulundu:   MOV indeks, BL
RET
KAYNAK_BUL ENDP
dizi       DB 14, 11, 54, 62, 11, 3, 8, 63, 81, 13, 16
k_esik     DB 15
b_esik     DB 50
indeks     DB ?
mys        ENDS
           END KAYNAK_BUL
```

Hoca önce bütün sözdizimsel iskeleti (kesim, `ORG`, `ASSUME`, `PROC`/`ENDP`, değişkenler, `ENDS`, `END`) yazmayı sevdiğini, sonraya bırakınca unutulduğunu söyledi. Kesim adı serbestçe verilebilir. Dizide 11 eleman vardır ve yalnız 16, 15 ile 50 arasındadır. Hoca hem bulunan hem bulunmayan durum için örnek yapılabileceğini söyledi.

Kodla ilgili açıklamalar:

- Bu kez `i` için BX kullanıldı. `i` köşeli parantez içinde kullanılacaktır. Hoca köşeli parantez içinde kullanılabilecek yazmaçların SI, DI ve BX olduğunu söyledi; ilk örnekte SI kullanmıştı, bu kez BX'i seçti.
- `dizi[i]` sürekli değişir; eşikler sabittir. `CMP`'de iki tarafın da bellek olduğu bir komut yoktur. Bu yüzden `k_esik` AL'ye, `b_esik` AH'a alındı. Bir taraf bellek, diğeri yazmaç olabilir.
- `CMP dizi[BX], AL` / `JB sonraki`: dizinin elemanı 15'ten küçükse sonraki elemana geçilir. Hoca bu kez AL'yi bilerek ilk operand yapmadı ve bu yazımın da çalıştığını gösterdi; performans istenen bir soruda AL'nin ilk operand olmasını önerdi. Küçük değilse (15'e eşit ya da büyükse) değer aralıkta olabilir ve ayrıca 50 ile karşılaştırılmalıdır.
- `CMP dizi[BX], AH` / `JBE bulundu`: eleman 50'den küçük ya da eşitse aranan kişi bulunmuştur ve döngüden çıkmak için `bulundu` etiketine atlanır. İki dallanma da olmazsa `sonraki: INC BX` / `JMP don` ile döngü devam eder.
- `bulundu: MOV indeks, BL`: `indeks` byte tanımlıdır, BX ise word yazmaçtır; `MOV indeks, BX` yazılamaz. İki seçenek vardır: `indeks`'i word yapmak (boşuna yer kaplar) ya da sıranın 11 elemanlı olduğunu bilerek BH'ın hep 0 kalacağını kullanmak ve yalnız BL'yi atamak. Hoca ikincisini seçti.

> **Hocanın vurgusu:** Byte tanımlı bir değişkene word yazmaç atanamaz; değer 8 bite sığıyorsa yazmacın alt yarısı (BL) atanır.

> **Ders sonrası not:** Hoca köşeli parantez içinde yalnız SI, DI ve BX'in kullanılabileceğini söyledi; BP de kullanılabilir (BP'li adreslemede varsayılan kesim SS'dir).

> **Ders sonrası not:** Kodda BX'e başlangıç değeri verilmiyor (akış diyagramındaki `i ← 0` adımının karşılığı yok). DEBUG'da BX'in başta 0000 olduğu görüldü (ekrandan, 01:40:00); DOS büyük olasılıkla COM programını yüklerken BX'i sıfırlar. Yine de döngüden önce `XOR BX, BX` yazmak daha güvenlidir.

## 10. Örnek 2'nin DEBUG ile İzlenmesi

Program yine MASM ve LINK'ten geçirildi; `.asm` dosyası 391 bayttı. DEBUG'da veriye bakıldığında dizinin değerleri sırayla yerleşmişti: 0Eh = 14, 0Bh = 11, 36h = 3 × 16 + 6 = 54, 3Eh = 48 + 14 = 62 ve devamı. Bu sözdiziminde veri koddan sonra geldiği için dizinin başladığı adres koda bakılarak bulunur: dizi 011Bh'den başlar (`d ds:11b`). Dizinin ardından 0Fh (15), 32h (3 × 16 + 2 = 50) gelir ve 32h'den sonraki bayt `indeks`'tir. `g` ile çalıştırılınca `indeks` 0Ah oldu: aranan 16 değeri 10. indistedir. Dizi 0'dan başladığı için 11. eleman 10. indistedir.

Ardından dizide 16 yerine 12, beşinci elemandaki 11 yerine 31 yazılarak (14, 11, 54, 62, 31, 3, 8, 63, 81, 13, 12) program yeniden derlendi; 31 değeri 4. indiste olduğu için sonuç 4 çıktı. `l` (load) ile program yeniden yüklenip `t` ile adım adım izlendi (ekrandan, 01:40:00):

| Ofset | Makine kodu | Komut |
|---|---|---|
| 0100 | A0 26 01 | `MOV AL, [0126]` |
| 0103 | 8A 26 27 01 | `MOV AH, [0127]` |
| 0107 | 38 87 1B 01 | `CMP [BX+011B], AL` |
| 010B | 72 06 | `JB 0113` |
| 010D | 38 A7 1B 01 | `CMP [BX+011B], AH` |
| 0111 | 76 03 | `JBE 0116` |
| 0113 | 43 | `INC BX` |
| 0114 | EB F1 | `JMP 0107` |
| 0116 | 88 1E 28 01 | `MOV [0128], BL` |
| 011A | C3 | `RET` |

`k_esik` 0126h, `b_esik` 0127h, `indeks` 0128h adresindedir; program toplam 41 bayttır (python ile kontrol edildi). İzleme şöyle ilerledi:

- AL'ye 15, AH'a 50 yüklendi.
- BX = 0: dizinin ilk elemanı 0Eh = 14. 14, 15'ten küçük mü? Evet; `JB` 0113h'ye atladı, IP 0113 oldu. `INC BX` ile BX 1 oldu ve döngü başına dönüldü.
- BX = 1: 11 < 15; yine atlandı, BX artırıldı.
- BX = 2: 36h = 54. 54 < 15 değil; `JB` atlamadı ve alt satırdan devam edildi. 54 ≤ 50 değil; `JBE` de atlamadı. BX artırıldı.
- BX = 3: 3Eh = 62. 62 < 15 değil, 62 ≤ 50 değil; BX artırıldı.
- BX = 4: 1Fh = 16 + 15 = 31. 31 < 15 değil; 31 ≤ 50 evet. Hoca bu soruya ilk kez "evet" cevabı verildiğini belirtti. `JBE` 0116h'ye atladı, IP 0116 oldu.
- `MOV [0128], BL` ile BL'deki 04 `indeks`'e yazıldı, `RET` ile program sonlandı. `d ds:11b` ile bakıldığında `indeks` alanında 4 görüldü.

Hoca bu sırada kesim yazmaçlarının hepsinin aynı değerde olduğunu ve yığın göstericisinin başlangıç değerinde kaldığını gösterdi: bu örneklerde yığına `PUSH`/`POP` yapılmadığı için SP değişmedi; yapılsaydı değiştiği görülecekti. Karelerde SP = FFFE görülüyor (ekrandan, 01:00:00).

## Örnek Sorular

**1.** (ekrandan, 00:30:00) 1 yıl süresince günlük en düşük ve en yüksek hava sıcaklığı bulunan bir dizide −20'nin altında sıcaklık değeri olup olmadığını bulan COM tipi assembly programını yazınız (sözdizimi 1; en düşük sıcaklıkların en küçüğü −92, en yüksek sıcaklıkların en büyüğü 56).

> **Çözüm (derste verildi):** Byte dizisi, işaretli karşılaştırma ve `while` döngüsü. `XOR SI, SI` / `MOV CX, n` / `MOV AL, esik` / `don: CMP SI, CX` / `JAE yoktur` / `CMP AL, dizi[SI]` / `JG vardir` / `INC SI` / `JMP don` / `vardir: MOV sonuc, 7` / `JMP son` / `yoktur: MOV sonuc, 1` / `son: RET`. 15, −19, 20, 50, −25 dizisi için sonuç 7, son eleman −17 olunca sonuç 1 (python ile kontrol edildi).

**2.** (derste sözlü, 00:46:08) Dizi boyunu CX'e almadan `CMP SI, n` ile karşılaştırma yapılamaz mıydı?

> **Çözüm (derste verildi):** Yapılabilirdi; ama döngü içinde tekrarlanan karşılaştırmada yazmaç-bellek karşılaştırması yazmaç-yazmaç karşılaştırmasından yavaştır ve fark her turda birikir. Yazmaç müsaitse iki tarafı da yazmaç yapmak yararlıdır.

**3.** (ekrandan, 01:25:00) 15 yaşından küçük ve 50 yaşından büyük 10 tane kişinin olduğu sıraya yaş koşulunu bozan 11. kişi karışmıştır. Sıradaki tüm kişilerin yaşları bilindiğine göre, sıraya sonradan karışan kişinin baştan kaçıncı sırada olduğunu bulan COM tipi assembly programını yazınız.

> **Çözüm (derste verildi):** Byte dizisi, işaretsiz karşılaştırma, OR koşullu `while`. `MOV AL, k_esik` / `MOV AH, b_esik` / `don: CMP dizi[BX], AL` / `JB sonraki` / `CMP dizi[BX], AH` / `JBE bulundu` / `sonraki: INC BX` / `JMP don` / `bulundu: MOV indeks, BL` / `RET`. 14, 11, 54, 62, 11, 3, 8, 63, 81, 13, 16 dizisi için indeks 10; 14, 11, 54, 62, 31, 3, 8, 63, 81, 13, 12 dizisi için indeks 4 (python ile kontrol edildi). BX'in başlangıçta 0 olması için `XOR BX, BX` eklemek daha güvenlidir.

## Dersin Toparlaması

Bu derste COM tipi programlar işlendi. COM programında yığın, kod ve veri tek bir 64 KB'lık kesimde bulunur; dosyada başlık yoktur, ilk 100h bayt PSP'ye ayrıldığı için program `ORG 100h` ile başlar, CS, DS ve SS aynı kesimi gösterir, yordamlar NEAR tanımlanır ve `RET` ile kesimin sonundaki sıfır dönüş ofsetine dönülür. İki sözdizimi görüldü: sözdizimi 1'de `JMP` ile verinin üzerinden atlanır ve veri kodun üstündedir; sözdizimi 2'de kod üstte, veri en alttadır. Her birinde bir yerdeki ekleme diğerinin adreslerini kaydırır. MASM, LINK ve EXE2COM adımlarıyla 48 baytlık bir COM dosyası üretildi ve DEBUG'da verinin 103h ya da koddan sonraki adreste olduğu görüldü.

İki örnekte sorudan veri tipine (byte/word), karşılaştırma ailesine (greater/less ya da above/below) ve döngü türüne (`for` ya da `while`) nasıl karar verildiği, AND ve OR koşullu `while` döngülerinin assembly'ye nasıl çevrildiği adım adım gösterildi. Bir sonraki derste yordamlar arasında parametre aktarma konusuna geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
