# Ders 9 Çalışma Özeti

## Genel Konular

- DOSBox ile derleme ortamı
  - DOSBox bir DOS emülatörüdür; Windows, Linux ve macOS sürümleri vardır. Yereldeki bir klasör `MOUNT C <yerel klasör>` ile DOSBox içinde C sürücüsü olarak bağlanır, `C:` ile o sürücüye geçilir, `DIR` ile içerik listelenir.
  - Bağlama işlemi DOSBox her açıldığında kaybolur. Bu komutlar DOSBox ayar dosyasının (Options) en altındaki `[autoexec]` bölümüne satır satır yazılırsa her açılışta kendiliğinden çalışır.
  - Kullanılacak programlar: `MASM` (assembler), `LINK` (bağlayıcı), COM tipi program için `EXE2BIN` (exe'yi com'a çevirme) ve `DEBUG`. Pratik olması için bütün çalıştırılabilir dosyalar ve `.asm` dosyaları bağlanan klasöre konabilir.
- Derleme ve bağlama adımları (ekrandan, 00:15:00)
  - `MASM deneme.asm`: nesne dosyası adı (varsayılan `deneme.OBJ`), liste dosyası (`.LST`, varsayılan üretilmez) ve çapraz referans dosyası (`.CRF`) sorulur. Hata ve uyarı yoksa `.OBJ` oluşur.
  - `LINK deneme.obj`: çalıştırılabilir dosya adı (varsayılan `DENEME.EXE`), harita dosyası (`.MAP`) ve kütüphane sorulur. Büyük projelerde birden fazla `.OBJ` birlikte bağlanır.
  - Komutun sonuna `;` konursa bütün varsayılanlar kabul edilir (`link deneme.obj;`).
- Örnek program `deneme.asm` (ekrandan, 00:20:00, 00:45:00)
  - Veri: `A DB 2`, `B DB 10`, `SONUC DW 0`. Yığın: `DW 20 DUP (?)`.
  - Kod: `MOV AX, 1`, `MOV CL, B`, `XOR BX, BX`, `MOV BL, A`, `L1: MUL BX` / `LOOP L1`, `MOV SONUC, AX`, `RETF`. AX, BX'teki 2 ile 10 kez çarpılır; sonuç $2^{10} = 1024 = 0400h$ olur.
- DEBUG komutları (ekrandan, 00:50:00)
  - `?`: yardım. `R`: yazmaçları ve bayrakları gösterir; `R AX` ile AX'e yeni değer girilir.
  - `T` (trace): bir komut yürütür. `P` (proceed): döngüyü ya da çağrıyı tek adımda bitirip sonraki komutta durur. `G adres`: programı baştan o adrese kadar çalıştırır (örn. `G CS:1C` LOOP satırı, `G CS:21` RETF satırı).
  - `D segment:offset` (dump): belleği onaltılık ve sağda ASCII olarak gösterir. `E adres` (enter): belleği byte byte değiştirir. `U adres` (unassemble): makine kodunu mnemoniğe çevirir. `A adres` (assemble): belleğe doğrudan komut yazdırır.
- Yazmaç ve bayrak gösterimi (ekrandan, 00:20:00)
  - Program yüklenince ilk durum: `DS=075A ES=075A SS=076A CS=076E IP=0000 SP=0028`; bayraklar `NV UP EI PL NZ NA PO NC` (taşma yok, yön ileri, kesme açık, pozitif, sıfır değil, yardımcı elde yok, tek eşlik, elde yok).
  - `PUSH DS` 1 byte'lık (`1E`) olduğu için yürütülünce IP 0'dan 1'e çıkar. `XOR AX, AX` 2 byte (`33C0`), `PUSH AX` 1 byte (`50`), `MOV AX, 076D` 3 byte (`B8 6D 07`).
- Yığının ve verinin dump ile incelenmesi (ekrandan, 00:40:00)
  - `PUSH DS` ve `PUSH AX` sonrasında SP 0028 → 0026 → 0024 olur. `D SS:24` çıktısı `00 00 5A 07` gösterir: üstte AX'ten gelen 0000, altında DS'den gelen 075A.
  - `5A 07` ters görünür, çünkü 8086 little endian saklar: düşük anlamlı byte düşük adrestedir.
  - `MOV AX, DATASG` / `MOV DS, AX` çalışmadan DS hâlâ işletim sisteminin verdiği değeri gösterir; değişkenler ancak bu iki satırdan sonra `D DS:0` ile görülür. Kendi data segmentimiz 076D'dedir.
  - Değişkenlerden sonra gelen baytlar PARA hizalamanın bıraktığı kullanılmayan alandır; 076E:0000 ile 076D:0010 aynı fiziksel adrestir, yani kod segmenti oradan başlar.
- EXE programı ve işletim sistemine dönüş (ekrandan, 00:35:00)
  - EXE programında bir ana yordam olmalı ve bu yordam FAR tipinde olmalıdır. FAR çağrıda hem CS hem IP değişir.
  - İşletim sistemi programı başlatırken DS'ye kendi dönüş segment değerini koyar ve programdan o segmentin 0 ofsetine dönmesini bekler. Bu yüzden program `PUSH DS`, `XOR AX, AX`, `PUSH AX` ile başlar.
  - `RETF` yığının üstündeki word'ü IP'ye, sonrakini CS'ye yükler. Programın yığına attığı her şey `RETF`'ten önce ters sırada geri çekilmelidir.
- Sözde komutlar (pseudo-instructions) (ekrandan, 01:15:00)
  - Makine kodu karşılığı yoktur; 8086 komut kümesinin değil, assembler'ın kelimeleridir. Etkileri derleme anında (compile time) ortaya çıkar; komutlar (instructions) ise çalışma anında (run time) etki eder.
  - Gruplar: LST düzenleme (`PAGE`, `TITLE`), kesim düzenleme (`SEGMENT/ENDS`, `ORG`, `ASSUME`), veri tanımlama (`DB`, `DW`, `DD`, `DQ`, `EQU`, `DUP`, `TYPEDEF`, `PTR`, `LABEL`), yordam düzenleme (`PROC/ENDP`, `EXTRN`, `PUBLIC`), makro düzenleme (`MACRO/ENDM`, `INCLUDE`, `LOCAL`), diğer (`LENGTH`, `TYPE`, `SIZE`, `OFFSET`, `SEG`, `END`).
  - `PAGE 80, 60`: LST dosyasının sayfa düzenini belirler. `TITLE`: LST dosyasına başlık yazar.
- Kesim tanımı: `isim SEGMENT hizalama birleştirme 'sınıf'` ... `isim ENDS` (ekrandan, 01:25:00)
  - Hizalama: `BYTE` sıradaki adresten, `WORD` sıradaki çift adresten, `PARA` sıradaki 16'nın katından, `PAGE` sıradaki 256'nın katından başlatır.
  - Birleştirme: `PUBLIC` aynı isimli kesimleri peş peşe yerleştirir (C'deki struct gibi), `COMMON` aynı adresten başlatır (union gibi), `STACK` kesimi yığın kesimi yapar, `AT` kesimi belirli bir adrese yerleştirir.
  - Kesim adı ve sınıf adı keyfidir.
- Hangi kesimin hangi segment yazmacına bağlandığı
  - SS: `STACK` kelimesinin geçtiği kesim; program yüklenince belirlenir.
  - DS: `MOV AX, DATASG` / `MOV DS, AX` satırları çalıştıktan sonra.
  - CS: `END` kelimesinden sonraki etiketin içinde bulunduğu kesim. Bu etiket aynı zamanda ana yordamı ve programın giriş noktasını belirler.
- EXE ve COM tipi programlar
  - EXE programı üç kesim kullanır (yığın, veri, kod); her kesimin boyutu tanımlara göre belirlenir.
  - COM programı tek bir kesim (en fazla 64 KB) kullanır. Başta 100h byte'lık başlık alanı bulunur; kod `ORG 100H` ile 100h adresinden başlatılır, yığın kesimin sonundan geriye doğru büyür, veri arada kalır.
  - `ASSUME`, kesim adlarının hangi segment yazmacına karşılık geldiğini assembler'a bildirir. Bu sayede `MOV AX, DATASG` bir etiket ofseti değil, segment değeri olarak çevrilir.
- Veri tanımlama sözde komutları (ekrandan, 01:35:00, 01:40:00)
  - `DB` 0-255 arası byte tanımlar. Sayı ekisiz yazılırsa onluk sayılır; onaltılık sayı `H` ile biter ve harfle başlıyorsa başına 0 konur (aksi halde etiket sanılır). Virgülle dizi, tırnak içinde karakter dizisi tanımlanır.
  - `DW`, `DD` (32 bit), `DQ` (8 byte). `Dizi DW 5, 10, 20` 510h adresinden itibaren `05 00 0A 00 14 00` olarak yerleşir.
  - `EQU` değişken tanımlamaz; derlemeden önce her geçtiği yer sabit değerle değiştirilir (C'deki `#define` gibi).
  - `DUP`: `Dizi1 DB 15 DUP (0)` 15 sıfır; `Matris DB 3 DUP (4 DUP (8))` 3×4 = 12 byte, hepsi 8, satır satır ardışık; `Dizi2 DW 10 DUP (?)` 10 word (20 byte) yer ayırır, ilk değer vermez.
  - `TYPEDEF` yeni tip adı tanımlar. `BYTE PTR`/`WORD PTR` işlem boyutunu, `FAR PTR`/`NEAR PTR` dallanma ya da çağrı tipini belirtir.
- `LABEL` (ekrandan, 01:45:00)
  - `Yenib LABEL BYTE`, `Sayiw DW 2535H`, `Yeniw LABEL WORD`, `Sayib DB 45H`, `Sayic DB 55H`. Bellek: 0000h: 35h, 0001h: 25h, 0002h: 45h, 0003h: 55h.
  - `MOV AX, Yeniw` → AX = 5545h. `MOV BL, Yenib` → BL = 35h (Sayiw'nin düşük byte'ı).
  - LEA ile çalışma anında yapılan farklı tipte erişimin derleme anındaki karşılığıdır.
- Diğer sözde komutlar (ekrandan, 01:55:00)
  - `TABLO DW 15 DUP (0)` için `LENGTH TABLO` = 15 (eleman sayısı), `TYPE TABLO` = 2 (eleman boyutu), `SIZE TABLO` = 30 (toplam byte).
  - `OFFSET`: değişkenin ofsetini derleme öncesinde verir (LEA ise çalışma anında). `SEG`: etiketin bulunduğu kesimin değerini verir.
  - `EXTRN`/`PUBLIC`: başka bir nesne dosyasındaki yordamı ya da değişkeni kullanmak için `EXTRN`, dışarıya açmak için `PUBLIC` yazılır.
  - `MACRO/ENDM`, `INCLUDE`, `LOCAL`: makro içindeki etiket `LOCAL` ile tanımlanırsa her çağrıda benzersiz bir etiket üretilir; böylece tekrarlı etiket hatası oluşmaz.
- LST ve MAP dosyaları
  - LST dosyası her satırın ofsetini ve makine kodunu gösterir. Kesim tanımları adres artırmaz; `DB`/`DW` tanımları makine kodu olmadan yer kaplar.
  - `deneme` için MAP: kod 22h (34 byte), veri 4h, yığın 28h (40 byte).
  - Yükleme anında belli olmayan değerler (`MOV AX, DTSG`'deki segment, `LEA BX, SONUC`'taki göreli ofset) LST'de yeniden konumlandırılabilir (relocatable) olarak işaretlenir.
- EXE tipi program iskeleti (ekrandan, 02:15:00)
  - Dört bölüm: yığın kesimi, veri kesimi, kod kesimi ve `END ana_yordam`.
  - Yığın için ayrılan alan çift sayıda byte olmalıdır, çünkü PUSH/POP word ile çalışır. `DW` ile ayrılırsa zaten çifttir; `DB` ile ayrılırsa sayı çift seçilmelidir.
  - Yığın; alt yordam çağrılarında dönüş adreslerini saklamak, geçici saklama (iç içe döngüde CX) ve parametre aktarımı için kullanılır. Özyinelemeli (recursive) çağrı varsa en derin çağrıya yetecek boyutta olmalıdır.
- Örnek: iki 16 bitlik sayının toplamını 32 bitlik değişkende saklayan EXE programı (ekrandan, 02:40:00, 03:00:00)
  - Veri: `ASAY DW 0F000H`, `BSAY DW 0E000H`, `SONUC DD 0`.
  - Kod: `LEA BX, SONUC`, `MOV AX, ASAY`, `ADD AX, BSAY`, `MOV [BX], AX`, `JNC L1`, `INC WORD PTR [BX+2]`, `L1: RETF`. Diğer yol: `ADC WORD PTR [BX+2], 0`.
  - F000h + E000h = 1D000h: AX = D000h, CF = 1. Bellekte SONUC: `00 D0 01 00`, yani 0001D000h.

## Hocanın Özellikle Vurguladığı Kısımlar

- EXE programında ana yordam mutlaka olmalı ve FAR tipinde olmalıdır; dönüşü `RETF` ile yapılır. Hoca bunu kesin kural olarak tekrarladı.
- Ders boyunca kodun doğruluğu için referans DOSBox ve MASM'dır. emu8086, `INC [100H]` gibi boyutu belirsiz komutları varsayılan olarak byte kabul eder; MASM ise hata verir. emu8086 yalnız hızlı deneme aracıdır.
- Bellek işleneniyle sabit kullanılan `ADC [BX+2], 0`, `INC [BX+2]`, `ADD [BX+2], 1` gibi satırlarda `WORD PTR` yazılmalıdır; yoksa MASM hata verir.
- Segment yazmacına doğrudan sabit atanamaz; DS'ye değer önce AX üzerinden verilir (`MOV AX, DTSG` / `MOV DS, AX`).
- Bir veri kesimi tanımı verildiğinde DEBUG'da `D DS:0` ile hangi baytların görüleceğini (little endian, hizalama boşlukları dahil) yazabilmek önemlidir.
- Yığını dump etmek, ileride alt yordamlara yığınla parametre aktarılan ve özyinelemeli programlarda hata ayıklamanın temel yoludur.
- Koşullu dallanmada koşul yanlış kol (false kol) üzerinden yazılırsa tek dallanma komutu yeter (`JNC L1`); doğru kol üzerinden yazılırsa iki dallanma gerekir.
- Sözde komutların hepsi derleme anında, komutlar çalışma anında etki eder.

## Kısa Tekrar Notları

- Akış: `MASM x.asm` → `x.OBJ` (+ `.LST`) → `LINK x.obj` → `x.EXE` (+ `.MAP`) → `DEBUG x.exe`.
- DEBUG: R, T, P, G, D, E, U, A. `D SS:SP` yığını, `D DS:0` veriyi, `U CS:0` kodu gösterir.
- Little endian: 075Ah bellekte `5A 07` görünür.
- EXE başlangıcı: `PUSH DS`, `XOR AX, AX`, `PUSH AX`, `MOV AX, veri_kesimi`, `MOV DS, AX`; sonu `RETF`.
- SS ← STACK kelimeli kesim; DS ← `MOV DS, AX` ile; CS ← `END etiket`'in bulunduğu kesim.
- Hizalama: BYTE, WORD (çift), PARA (16), PAGE (256). Birleştirme: PUBLIC, COMMON, STACK, AT.
- COM: tek kesim, `ORG 100H`; EXE: üç kesim.
- `DUP`: `3 DUP (4 DUP (8))` = 12 byte. `DW 10 DUP (?)` = 20 byte, ilk değersiz.
- `LENGTH` = eleman sayısı, `TYPE` = eleman boyutu, `SIZE` = toplam byte.
- `OFFSET` ↔ `LEA`, `LABEL` ↔ LEA ile farklı tipte erişim; ilkler derleme anında, LEA çalışma anında.
- 32 bitlik toplam: düşük word `ADD`, yüksek word `ADC ..., 0` ya da `JNC` + `INC WORD PTR`.

## Detaylı Açıklamalar

- DEBUG ile `deneme.exe` adım adım izlendiğinde ilk `R` çıktısında CS:IP = 076E:0000 sıradaki komutu (`1E PUSH DS`) gösterir. Her `T` ile IP komut uzunluğu kadar ilerler. `D CS:0` kodun makine kodunu verir: `1E 33 C0 50 B8 6D 07 8E D8 ...`. `G CS:1C` ile LOOP satırına gelinir, `P` ile döngü bitirilir, `G CS:21` ile RETF satırında durulup `D DS:0` ile sonuç incelenir. Programa sonradan eklenen `STR DB 'MERHABA'` tanımıyla dump'ın sağındaki ASCII sütununda `MERHABA` görüldü ve SONUC word'ü `00 04` (0400h = 1024) olarak okundu (ekrandan, 00:55:00).
- `E DS:0` ile A değişkeninin değeri 2'den 12'ye değiştirildi ve tekrar dump edilince değişiklik görüldü. `A` komutu ile boş bir bellek bölgesine `MOV AX, 12`, `CMP AX, 13`, `JE 109`, `NOP`, `NOP` yazılıp `U` ile geri okundu. `A` ile yazılan komutlardan sonraki satırlar, bellekte rastgele duran baytların çözülmüş halidir ve anlamsızdır.
- EXE'nin işletim sistemine dönüşü şöyle işler: program başlarken DS'de dönüş segment değeri vardır. `PUSH DS` bunu, `PUSH AX` (AX = 0) da 0 ofsetini yığına atar. `RETF` önce 0'ı IP'ye, sonra segment değerini CS'ye yükler. Derste son örnekte RETF sonrasında CS:IP = 075A:0000 olduğu ve orada `INT 20` komutunun bulunduğu görüldü (ekrandan, 03:00:00).
  - Ders sonrası not: Hoca yığın çiziminde PUSH'ta SP'nin "2 arttığını" ve SP'nin "sıradaki boş gözü" gösterdiğini söyledi. 8086'da PUSH önce SP'yi 2 azaltır, sonra değeri [SS:SP]'ye yazar; SP son yazılan word'ü gösterir. POP ve RETF önce [SS:SP]'yi okur, sonra SP'yi 2 artırır. Ekranda da SP 0028 → 0026 → 0024 diye azaldı ve `D SS:24` ilk baytlarda son atılan 0000'ı gösterdi. Hocanın çiziminde yüksek adres aşağıda olduğu için "artı" çizimdeki yönü anlatıyordu.
  - Ders sonrası not: Hoca `LENGTH`, `TYPE`, `SIZE` için bir yerde "runtime sırasında etki gösteriyor" dedi; ama hemen ardından ve slaytta da belirtildiği gibi bunlar derleme anında sayıya çevrilir (`MOV AX, LENGTH TABLO` assembler'a `MOV AX, 15` olarak gider).
  - Ders sonrası not: Altyazıda "1024 değeri 488 decimal" gibi geçen yer bozuk; 1024 = 400h'dir ve ekranda SONUC `00 04` olarak görüldü.
  - Ders sonrası not: COM programındaki başlık alanı 100h byte'tır, yani onluk 256 byte (altyazıda "100H decimal" geçiyor).
- İkinci örnekte veri kesimi önce WORD, yığın kesimi BYTE hizalamayla yazıldı. Bu durumda `D DS:0` beklenen değişkenleri değil, yığından kalan dönüş değerlerini gösterdi. Hoca iki kesimi de PARA yapıp yeniden derleyince değişkenler `D DS:0` ile doğru göründü: `00 F0 00 E0 00 D0 01 00` (ASAY, BSAY, SONUC).
  - Ek bilgi (derste anlatılmadı): Kesim 16'nın katında başlamazsa segment değeri bir alt paragrafa yuvarlanır ve değişkenlerin ofsetleri kaydırılır. Burada yığın 076A:0000'dan 28h byte sürdüğü için veri büyük olasılıkla 076C8h fiziksel adresinde, yani 076C:0008'de başlamıştır; bu yüzden 076C:0000'da yığının son baytları görülmüştür.
- Toplama örneğinde `ADD AX, BSAY` sonrası bayraklar: CF = 1 (elde var), sonuç D000h'nin en yüksek biti 1 olduğu için SF = 1, OF = 0, ZF = 0, düşük byte 00h olduğu için PF = 1. `JNC L1` elde olduğu için dallanmadı, `INC WORD PTR [BX+2]` yüksek word'ü 1 yaptı. Bu değerler python ile de doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
