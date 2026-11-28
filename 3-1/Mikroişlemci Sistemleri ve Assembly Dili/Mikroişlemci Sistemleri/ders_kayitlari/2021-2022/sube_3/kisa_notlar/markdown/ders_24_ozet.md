# Ders 24 Çalışma Özeti

## Genel Konular

- Kesme kaynakları (tekrar ve tamamlama) (ekrandan, 00:05:00)
  - Yazılımsal kesmeler iki türlüdür: `INT n`, `INTO`, `INT 3` gibi komutlarla doğrudan tetiklenenler ve bir komutun yürütülmesi sırasında kendiliğinden oluşanlar (sıfıra bölme, taşma, TF=1 iken tek adım kesmesi, breakpoint).
  - `INT` komutu 8 bitlik bir immediate değer alır: 00H-FFH arası toplam 256 kesme tipi vardır.
  - Donanımsal kesmeler işlemcinin INTR (maskelenebilir) ve NMI (maskelenemez) uçlarından gelir. Donanım kesmesinin onay (acknowledge) ucu $\overline{INTA}$'dır.
  - Sabit tipler: sıfıra bölme tip 0, tek adım tip 1, NMI tip 2, breakpoint tip 3, taşma tip 4. INTR'den gelen kesmenin tipini çevre birimi $\overline{INTA}$ sonrasında D0-D7 uçlarından gönderir.
  - NMI kritik durumlar içindir: açılışta gerilim kararlı değilse ya da bellek eksik/bozuksa sistemi güvenli kapatmak gibi.
- Kesme bayrakları ve bayrak komutları (ekrandan, 00:25:00 ve 00:30:00)
  - IF=1 ise INTR ucundan gelen istekler değerlendirilir, IF=0 ise değerlendirilmez. `STI` IF'yi 1, `CLI` 0 yapar.
  - TF=1 ise her komuttan sonra tip 1 (single-step) kesmesi oluşur; adım adım hata ayıklama (debug) için kullanılır. TF için özel komut yoktur.
  - Özel komutu olan bayraklar: CF (`CLC`, `STC`, `CMC`), DF (`CLD`, `STD`), IF (`CLI`, `STI`).
  - `LAHF`: AH ← FLAG(S, Z, ?, A, ?, P, ?, C); `SAHF`: FLAG(S, Z, ?, A, ?, P, ?, C) ← AH. AH'de bit 7 = SF, bit 6 = ZF, bit 4 = AF, bit 2 = PF, bit 0 = CF.
  - Bu iki komutla SF, ZF, AF, PF ve CF de değiştirilebilir. TF için yığın kullanılır: `PUSHF` ile bayraklar yığına atılır, bit 8 değiştirilir, `POPF` ile geri yüklenir.
- `IRET` komutu
  - Near `CALL` yığına yalnız IP, far `CALL` CS ve IP atar; dönüş sırasıyla `RET` ve `RETF` ile yapılır.
  - Kesmede yığına sırayla FLAGS, CS ve IP atılır. `IRET` yığından sırayla IP, CS ve FLAGS'i çeker.
- Kesme vektör tablosu (ekrandan, 00:15:00)
  - Belleğin 0 adresinden başlar, 256 göz × 4 bayt = 1024 bayt (00000H-003FFH) yer kaplar.
  - Her gözde kesme alt programının kendisi değil, adresi vardır: düşük adreste offset, yüksek adreste segment (little endian). Tip $n$'nin adresi $4n$'dir.
  - Kesme alt programları başka bir segmentte durabildiği için far tipindedir.
  - 00H-1FH BIOS'a, 20H'den sonraki bir bölge işletim sistemine (DOS) ayrılmıştır; kalan tipler kullanıcı içindir.
- Kesme işlemi sırası (ekrandan, 00:20:00)
  - Sıradaki komut bitince işlemci sırasıyla komut işleme ile oluşan, single-step, NMI, INTR ve INT kesmelerine bakar.
  - Kesme varsa: PUSHF; IF←0, TF←0 (INTR ve single-step engellenir, iç içe kesme olmaz); PUSH CS; PUSH IP; IP ve CS kesme vektör tablosundan yüklenir.
- Örnek: sıfıra bölme (tip 0) kesme alt programını değiştirme (ekrandan, 00:40:00-00:55:00)
  - Amaç: bölme sıfıra olunca AX'e FFFFH ("sonsuz") yazıp devam etmek.
  - Dört adım: kesme alt programını yaz; tablonun 0. gözündeki eski adresi yedekle; kendi alt programının adresini tabloya yaz; program biterken eski adresi geri yükle.
  - Sıfıra bölmede yığına atılan dönüş offseti `DIV` komutunun kendisini gösterir. Bu yüzden alt program dönüş offsetini `DIV BX` komutunun boyu (2 bayt) kadar artırır.
  - Tabloya erişmek için ES = 0 yapılır (ES'ye sabit doğrudan atanamaz, AX üzerinden atanır). `LEA AX, NEWINT` offseti, CS de segmenti verir.
- Donanımsal kesmeler: NMI ve INTR
  - NMI yükselen kenarla tetiklenir ve otomatik olarak tip 2 kesmesi oluşturur (tablodaki adres 08H).
  - INTR seviye tetiklemelidir: uç 1'de kalırsa aynı istek yeniden değerlendirilebilir.
  - Zamanlama (ekrandan, 01:15:00): INTR 1'e çıkar, işlemci $\overline{INTA}$ ucundan iki kez 0 darbesi verir. İlk darbe hazır olduğunu bildirir, ikinci darbede çevre birimi D7-D0 üzerinden vektör numarasını (tipi) gönderir. Gönderilen değer tablonun adresi değil, kesme tipidir.
- Elle (manuel) kesme vektörü üretme ve önceliklendirme (ekrandan, 01:20:00)
  - Tek kaynak: 74ALS244 tamponu ve anahtar/pull-up dirençlerle sabit bir tip (örnekte 80H) $\overline{INTA}$ sırasında veri yoluna verilir.
  - Yedi kaynak (IR0-IR6): istek uçları 74ALS30 NAND kapısıyla birleştirilip INTR'ye bağlanır; D7 her zaman 1 olduğu için 80H-FFH arasında, isteklerin kombinasyonuna göre farklı tip üretilir.
  - Birden çok 8255 (mod 1) gibi kaynakların INTR çıkışları OR ile birleştirilirse (daisy chain) hangi kaynağın istediği ve öncelik, yazılımla durum bitleri sırayla test edilerek bulunur. Donanımsal çözüm öncelik kodlayıcıdır (priority encoder).
- 8259A programlanabilir kesme denetleyicisi (ekrandan, 01:25:00-01:45:00)
  - Kesme isteklerine öncelik atar; tek başına 8, bir master ve 8 slave ile 64 kesme vektörü sağlar.
  - Uçlar: D0-D7, $\overline{CS}$, $\overline{RD}$, $\overline{WR}$, INT (işlemcinin INTR ucuna), $\overline{INTA}$, tek adres ucu A0 (G/Ç uzayında 2 bayt), CAS0-CAS2 (kaskat), $\overline{SP}/\overline{EN}$ (tek kullanımda 1'e bağlanır), IR0-IR7.
  - Erişim: A0=0 ile ICW1, A0=1 ile sırayla ICW2, ICW3, ICW4. Tek 8259 ile ICW3 atlanır: sıra ICW1 → ICW2 → ICW4.
  - ICW1 = 0 0 0 1 LTIM 0 SNGL IC4. Kenar tetikleme, tek 8259 ve ICW4 kullanımıyla 13H; seviye tetiklemeyle 1BH.
  - ICW2: IR0'ın vektör numarası yazılır (son 3 bit 0). IR1-IR7'nin numaraları son 3 bit 001-111 olacak biçimde otomatik üretilir.
  - ICW4 = 03H: otomatik kesme sonu (AEOI) ve 8086 modu.
  - OCW'ler (maskeleme, elle kesme sonu) derste kullanılmayacak.
- Örnek: 8259 ile düğmeye basma sayısını kesmeyle sayma (ekrandan, 01:40:00-01:50:00)
  - 8259 60H/62H adreslerinde, düğme IR0'da (basılınca 1, pull-down dirençli), kesme tipi 40H.
  - ICW1 = 13H → 60H, ICW2 = 40H → 62H, ICW4 = 03H → 62H; `STI` ile kesmeler açılır, ana program sonsuz döngüde bekler.
  - Kesme alt programı her girişte AX'i 1 artırır. Tablo adresi $40H \times 4 = 100H$'dir. Üç basışta AX = 3 olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kesme vektör tablosunda kesme alt programının kendisi değil, adresi (segment ve offset) durur.
  - Hoca bunu birkaç kez "çok önemli" diye tekrarladı. Kesme alt programları far tipindedir ve dönüşleri `IRET` ile yapılır.
- `IRET`, `RET` ve `RETF` farkı
  - Kesmede FLAGS da yığına atıldığı için dönüş mutlaka `IRET` ile olmalıdır.
- Sıfıra bölme kesmesinin özel durumu
  - Dönüş adresi `DIV` satırını gösterir. Düzeltilmezse program aynı satıra döner, bu yüzden dönüş offseti komut boyu kadar artırılmalıdır.
- $\overline{INTA}$ sonrası gönderilen değer tablonun adresi değil, kesme tipidir.
- 8259 ayarı neredeyse sabittir: ICW1 = 13H (ya da 1BH), ICW2 = IR0'ın vektör numarası, ICW4 = 03H.
- Kenar tetikleme düğme sayma gibi işlerde daha hassastır; seviye tetiklemede aynı basış birden çok kez sayılabilir.
- Kesme konusu kapsayıcıdır: 8255 mod 1/mod 2 INTR uçları, 8251 TxRDY/RxRDY, 8254 OUT uçları, ADC'nin INTR'si ya da düğmeler kesme kaynağı olabilir. Hoca sınavda bununla ilgili soru olacağını söyledi.

## Kısa Tekrar Notları

- 256 kesme tipi; tablo 00000H-003FFH, tip $n$ → adres $4n$ (offset düşük, segment yüksek adreste).
- Tip 0 sıfıra bölme, tip 1 tek adım, tip 2 NMI, tip 3 breakpoint, tip 4 taşma (`INTO`).
- Kesmede: PUSHF, IF=TF=0, PUSH CS, PUSH IP, CS:IP ← tablo. `IRET`: POP IP, POP CS, POPF.
- IF: `STI`/`CLI`. CF: `CLC`/`STC`/`CMC`. DF: `CLD`/`STD`. TF için komut yok, `PUSHF`/`POPF` ile bit 8 değiştirilir.
- SF=1: `LAHF`, `OR AH, 80H`, `SAHF`. SF=0: `LAHF`, `AND AH, 7FH`, `SAHF`.
- NMI yükselen kenar, INTR seviye tetiklemeli. $\overline{INTA}$ iki darbe; ikinci darbede tip D0-D7'den okunur.
- Tabloyu değiştirirken eski adres yedeklenir, program sonunda geri yazılır.
- 8259: A0=0 → ICW1; A0=1 → ICW2/ICW3/ICW4. ICW1 13H (kenar) / 1BH (seviye), ICW2 = IR0 tipi (son 3 bit 0), ICW4 03H.
- Tek 8259 = 8 kaynak; 1 master + 8 slave = 64 kaynak.

## Detaylı Açıklamalar

- **Sıfıra bölme örneği.** Veri segmentinde `DIZI1 DW 1,2,3,4,5,6,7`, `DIZI2 DW 1,0,3,4,5,6,7`, `ELEMAN DW 7`, `OLDOF DW 0` ve `OLDSG DW 0` tanımlıdır (ekrandan, 00:40:00). Kesme alt programı şöyledir (ekrandan, 00:45:00):

```asm
NEWINT  PROC FAR
        PUSH BP
        MOV  BP, SP
        MOV  AX, [BP+2]     ; yığındaki dönüş offseti (DIV satırı)
        ADD  AX, 2          ; DIV BX 2 bayt: sonraki komuta atla
        MOV  [BP+2], AX
        MOV  AX, 0FFFFH     ; "sonsuz" sonuç
        POP  BP
        IRET
NEWINT  ENDP
```

  - `PUSH BP` sonrası yığının üstünde BP, onun 2 bayt üstünde dönüş offseti, sonra dönüş segmenti, sonra FLAGS ve en altta işletim sistemine dönüş değerleri vardır. Dönüş offseti bu yüzden `[BP+2]`'dedir.
  - Ana yordam ES'yi 0 yapar, `ES:[0]` ve `ES:[2]`'deki eski offset ve segmenti `OLDOF` ve `OLDSG`'ye yedekler, sonra `LEA AX, NEWINT` ile offseti `ES:[0]`'a, CS'yi `ES:[2]`'ye yazar (ekrandan, 00:50:00). NEWINT kod segmentinin başında olduğu için `LEA AX, NEWINT` 0 verir.
  - Döngüde her bölmeden önce DX sıfırlanır, çünkü `DIV BX` DX:AX'i BX'e böler ve kalanı DX'e yazar.
  - DOSBox debug çıktısında `DIV BX` IP = 004BH'dedir. Kesme alt programında yığındaki dönüş offseti 004BH'den 004DH'ye çıkar; listeleme (.LST) dosyasında 004DH bir sonraki komuttur. Kesmeden AX = FFFFH ile dönülür.
- **8259 düğme sayacı.** Adres çözme devresi yalnız 60H ve 62H için $\overline{CS}$ üretir. A0 bu iki adreste hep 0 olduğu için işlemcinin A1 ucu 8259'un A0 ucuna bağlanır. Kesme vektörü şöyle yazılır (ekrandan, 01:50:00):

```asm
        XOR  AX, AX
        MOV  ES, AX
        MOV  AL, 40H
        MOV  AH, 4
        MUL  AH             ; AX = 40H * 4 = 100H
        MOV  BX, AX
        LEA  AX, NEWINT
        MOV  WORD PTR ES:[BX], AX
        MOV  AX, CS
        MOV  WORD PTR ES:[BX+2], AX
        MOV  AL, 13H        ; ICW1
        OUT  60H, AL
        MOV  AL, 40H        ; ICW2: IR0 -> tip 40H
        OUT  62H, AL
```

  - Ardından ICW4 olarak 03H 62H adresine yazılır, `STI` ile kesmeler açılır, AX sıfırlanır ve program sonsuz döngüde bekler. Bu son satırlar karede görünmüyor, altyazıdan alındı.
  - Proteus simülasyonunda BIOS ya da işletim sistemi olmadığı için eski vektör yedeklenmez, program da hiç sonlanmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
