# Ders 11 Çalışma Özeti

## Genel Konular

- EXE tipi ve COM tipi programın karşılaştırılması (ekrandan, 00:15:00)
  - EXE tipi programda yığın (SS), kod (CS) ve veri (DS) kesimleri ayrı ayrı tanımlanır; her biri en çok 64 KB olabilir. Gerekirse ek kesim (ES) de kullanılır.
  - EXE dosyasının başına 512 baytlık bir başlık (header) eklenir; `.exe` dosyasının boyu program boyu ile başlık boyunun toplamıdır.
  - COM (compact) tipi programda SS, CS ve DS'nin hepsi tek bir 64 KB'lık kesimin içindedir. Başlık yoktur, bu yüzden dosya EXE'ye göre çok daha küçüktür.
  - Program 64 KB'a sığmıyorsa artık "compact" değildir; EXE tipi program yazılmalıdır. Derste yazılan 40-200 baytlık programlar için 64 KB oldukça büyük bir alandır.
- COM tipi programın bellekteki yerleşimi (ekrandan, 00:15:00)
  - 1 MB'lık bellekte program tek bir 64 KB'lık kesime yerleşir; ofsetler 0000h'den FFFFh'ye kadar gider. CS, DS ve SS aynı kesim numarasını gösterir.
  - 0000h-00FFh arası (100h bayt) PSP'dir (Program Segment Prefix). Programın parametreleri ve işleyişiyle ilgili bilgileri tutar.
  - Program 100h ofsetinden başlar; bunu söylemek için `ORG 100h` sözde komutu kullanılır.
  - Kesimin son iki baytına (FFFEh-FFFFh) program bitince kullanılacak, değeri 0 olan bir word dönüş ofseti yerleşir. EXE'deki `PUSH DS` / `XOR AX, AX` / `PUSH AX` hazırlığı COM'da yazılmaz.
  - Yığın FFFEh'den aşağıya doğru büyür (SP azalır); kod ve veri 100h'den yukarıya doğru yerleşir (IP artar).
- COM tipi programın iki sözdizimi
  - Sözdizimi 1: önce veri, sonra kod. Kesimin başında `JMP` ile ana yordama atlanır, araya değişkenler yazılır (ekrandan, 00:25:00).
  - Sözdizimi 2: önce kod, sonra veri. Yordam(lar)dan sonra değişkenler yazılır; `JMP` gerekmez (ekrandan, 01:20:00).
- Sözdizimi 1'in iskeleti (ekrandan, 00:25:00)
  - `codeseg SEGMENT PARA 'kod'` / `ORG 100h` / `ASSUME DS:codeseg, SS:codeseg, CS:codeseg` / `Bilgi: JMP BASLA` / değişkenler (`sayi1 DB ?`, `wsayiB DW 17h`) / `BASLA PROC NEAR` ... `RET` / `BASLA ENDP` / `codeseg ENDS` / `END Bilgi`.
  - `END`'den sonra programın başladığı etiket (burada `JMP`'ın bulunduğu satırın etiketi) yazılır.
- Sözdizimi 2'nin iskeleti (ekrandan, 01:20:00)
  - `mys SEGMENT PARA 'my'` / `ORG 100h` / `ASSUME CS:mys, DS:mys, SS:mys` / `ANA PROC NEAR` ... `RET` / `ANA ENDP` / değişkenler (`sayib1 DB 17`) / `mys ENDS` / `END ANA`.
  - `END`'den sonra ana yordamın adı yazılır.
- COM programında yordamlar
  - Ana yordam dahil bütün yordamlar aynı kesimdedir ve `NEAR` tanımlanır; yordam `RET` ile (RETF değil) biter.
  - EXE'deki veri kesimi adresini DS'ye yükleyen ve dönüş değerlerini yığına atan beş satırlık başlangıç kodu yazılmaz.
- Derleme, bağlama ve COM dosyasına çevirme (ekrandan, 00:50:00)
  - DOSBox'ta `masm dosya.asm;` ile assemble edilir, `.obj` oluşur; `link dosya.obj;` ile `.exe` oluşur; `exe2com dosya.exe` ile `.com` dosyası üretilir.
  - Linker'ın `warning L4021: no stack segment` uyarısı COM programında beklenen tek uyarıdır; diğer bütün uyarı ve hatalar giderilmelidir.
  - Derste ilk örnekte EXE 816 bayt, COM yalnız 48 bayt çıktı.
  - Aynı adda hem COM hem EXE dosyası varsa ad yazılıp Enter'a basıldığında önce COM çalışır.
- Örnek 1: Sıcaklık dizisinde −20'nin altında değer var mı? (Sözdizimi 1, ekrandan, 00:30:00-01:00:00)
  - Byte dizisi, işaretli karşılaştırma (`JG`/`JL` ailesi), `while` yapısı; bulunursa `sonuc = 7` ("vardır"), bulunamazsa `sonuc = 1` ("yoktur").
- Örnek 2: Yaşı 15 ile 50 arasında olan kişinin sıradaki yeri (Sözdizimi 2, ekrandan, 01:25:00-01:40:00)
  - Byte dizisi, işaretsiz karşılaştırma (`JB`/`JBE`), `OR` koşullu `while` döngüsü; bulunan indis `indeks` değişkenine yazılır.
- DEBUG ile COM programını izleme (ekrandan, 00:55:00, 01:00:00, 01:40:00)
  - Sözdizimi 1'de veri `JMP` komutundan (3 bayt) sonra, 103h'den başlar; `d ds:0` yerine `d ds:103` ile bakılır.
  - `u` (unassemble), `t` (trace), `g` (go), `d` (display), `l` (load) komutları kullanıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- `ORG 100h` COM tipi programda muhakkak yazılmalıdır
  - İlk 100h bayt PSP'ye ayrılmıştır; programın kökeni bundan sonra başlamalıdır.
- Tek bir kesim adı bütün kesim yazmaçları için kullanılır
  - `ASSUME`'da CS, DS ve SS'nin hepsi aynı kesim adına bağlanır.
- Yordamlar `NEAR` olmalıdır
  - NEAR ve FAR yordama dallanırken yığına atılan değerler farklıdır; COM programında NEAR beklenir.
- Ofset kayması
  - Sözdizimi 1'de veri üstte olduğu için yeni bir değişken eklemek (örneğin `DD ?` ile 4 bayt) altındaki bütün kodun ofsetini kaydırır. Belirli bir ofsete (örneğin 010Dh) göre iş yapılıyorsa bu kontrol edilmelidir.
  - Sözdizimi 2'de kod üstte olduğu için yeni bir kod satırı eklemek verinin adresini kaydırır; aranan veri beklenen adreste bulunmayabilir.
- `for` ile `while` seçimi soruyu okuyarak yapılır
  - "Var mı yok mu?" ya da "kaçıncı sırada?" soruları bulunduğu anda durmayı gerektirir, `while` ile çözülür. "Kaç tane var?" sorusu bütün diziyi gezmeyi gerektirir, `for` ile çözülür.
- Soruda verilen sınır değerler veri tipini ve karşılaştırma türünü belirler
  - En düşük −92, en yüksek 56 verilmesi değerlerin byte'a sığdığını (−128...127) gösterir. Negatif değer olabileceği için `JG`/`JL` (greater/less) ailesi kullanılır.
  - Yaş her zaman pozitiftir ve 255'i geçmez; byte dizisi ve `JA`/`JB` (above/below) ailesi kullanılır.
  - İndis ile dizi boyunun karşılaştırmasında iki taraf da negatif olamayacağı için above/below komutları kullanılır.
- `CMP` iki bellek operandı alamaz
  - Değişmeyen taraf (eşik) bir yazmaca alınır. Döngü içinde tekrarlanan karşılaştırmalarda iki tarafın da yazmaç olması daha hızlıdır (dizi boyu CX'e alınır).
- Byte değişkene word yazmaç yazılamaz
  - `indeks` DB tanımlıyken `MOV indeks, BX` tip uyumsuzluğudur. Dizi 11 elemanlı olduğu için BH hep 0 kalır; `MOV indeks, BL` yeterlidir.
- Assembly'de uyarılar da hatalar kadar önemlidir
  - Program hiç uyarı ve hata olmadan derlenmelidir; COM'daki "no stack segment" uyarısı tek istisnadır.

## Kısa Tekrar Notları

- COM: tek 64 KB kesim, başlık yok, `ORG 100h`, CS = DS = SS, yordamlar NEAR, `RET` ile biter.
- EXE: ayrı kesimler (her biri en çok 64 KB), 512 baytlık başlık, dönüş için `PUSH DS` / `XOR AX, AX` / `PUSH AX`.
- PSP: 0000h-00FFh. Program 0100h'den başlar. FFFEh'de 0 değerli dönüş ofseti vardır; yığın oradan aşağı büyür.
- Sözdizimi 1: `JMP` + veri + kod; `END <JMP satırının etiketi>`. Sözdizimi 2: kod + veri; `END <ana yordam>`.
- Derleme sırası: `masm` → `link` (no stack segment uyarısı normal) → `exe2com`.
- Aynı adlı COM ve EXE varsa önce COM çalışır.
- Köşeli parantez içinde SI, DI, BX (ve BP) kullanılabilir.
- İşaretli veri: `JG`, `JL`, `JGE`, `JLE`; işaretsiz veri/indis: `JA`, `JB`, `JAE`, `JBE`. DEBUG `JAE`'yi `JNB` olarak gösterir (aynı komut).
- Diziyi gerçek boyutta tanımlamak için `DB 365 DUP(?)` kullanılır; derste test için 5 elemanlı dizi yazıldı.

## Detaylı Açıklamalar

### COM tipi programın yerleşimi

EXE tipi programda kod, veri ve yığın ayrı kesimlerde tutulur ve dosyaya 512 baytlık bir başlık eklenir. COM tipi programda ise bütün kesimler tek bir 64 KB'lık bloğun içindedir ve başlık yoktur. Bu blokta ilk 100h bayt PSP'ye ayrılmıştır; program `ORG 100h` ile 0100h ofsetinden başlar. Bloğun en sonundaki iki bayta (FFFEh ve FFFFh) değeri sıfır olan bir word dönüş ofseti yerleşir. Bu yüzden COM programında EXE'deki gibi DS'yi ve sıfırı yığına atan hazırlık kodu yazılmaz; yordamın sonundaki `RET` bu sıfır ofsete döner. Yığın FFFEh'den aşağıya doğru büyür, kod ve veri 0100h'den yukarıya doğru yerleşir. İkisi birbirine yetişecek kadar büyürse program COM'a sığmıyor demektir ve EXE yazılmalıdır. Derste izlenen DEBUG çıktılarında CS, DS, ES ve SS'nin aynı değerde (075A) olduğu ve SP'nin FFFE gösterdiği görüldü (ekrandan, 01:00:00).

> **Ek bilgi (derste anlatılmadı):** İlk örnekte EXE'nin 816, COM'un 48 bayt çıkması büyük olasılıkla şöyle açıklanır: COM programı 0100h'den başladığı için EXE görüntüsünde önce 100h = 256 baytlık boşluk, ardından 48 baytlık program vardır; buna 512 baytlık başlık eklenince 256 + 48 + 512 = 816 bayt eder.

### Sözdizimi 1 ve Örnek 1

Sözdizimi 1'de kesimin başına `JMP` konur, çünkü program çalışmaya kesimin başından (0100h) başlar ve hemen ardından gelen veri komut olarak çalıştırılmamalıdır. Derste yazılan program (ekrandan, 00:40:00 ve 00:45:00; son satırlar 00:55:00'daki bellek dökümünden doğrulandı):

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

<!-- BELİRSİZ: vardir satırından sonraki satırların (JMP son, yoktur, son etiketi) ekran görüntüsü yok; altyazıdaki anlatım ve 00:55:00'daki bellek dökümündeki makine kodu (EB 06, 90, C6 06 0B 01 01, C3) ile kuruldu. -->

Bellekte yerleşim (ekrandan, 00:55:00; python ile kontrol edildi): 0100h'de 3 baytlık `JMP`, 0103h'de `n` (05 00), 0105h-0109h'de dizi (0F ED 14 32 E7), 010Ah'da `esik` (EC = −20), 010Bh'de `sonuc`. Kod 010Ch'den başlar ve 012Fh'deki `RET` ile biter; toplam 30h = 48 bayt. Dizinin son elemanı −25 iken program `sonuc`'a 7 yazdı ("vardır"); −25 yerine −17 yazılınca 1 ("yoktur") yazdı.

### Sözdizimi 2 ve Örnek 2

Sözdizimi 2'de kod üstte, veri en sondadır; `JMP` gerekmez ve `END`'den sonra ana yordamın adı yazılır. Derste yazılan program (ekrandan, 01:35:00):

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

Dizi 011Bh'den başlar; `k_esik` 0126h, `b_esik` 0127h, `indeks` 0128h adresindedir (ekrandan, 01:40:00; python ile kontrol edildi). İlk dizide 16 değeri 10. indiste bulundu (`indeks` = 0Ah). Dizi 14, 11, 54, 62, 31, 3, 8, 63, 81, 13, 12 yapılınca sonuç 4 oldu.

- Ders sonrası not: Kodda BX'e başlangıç değeri verilmiyor; çalıştırmada BX = 0000 görüldü. DOS büyük olasılıkla COM programını yüklerken BX'i sıfırlar, ama akış diyagramındaki `i ← 0` adımı için `XOR BX, BX` yazmak daha güvenlidir.
- Ders sonrası not: Hoca köşeli parantez içinde yalnız SI, DI ve BX'in kullanılabileceğini söyledi; BP de kullanılabilir (varsayılan kesimi SS'dir).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
