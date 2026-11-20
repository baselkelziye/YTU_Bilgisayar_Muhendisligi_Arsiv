# Ders 23 Çalışma Özeti

## Genel Konular

- Veri aktarım yöntemlerinin tekrarı: polling, kesme (interrupt) ve doğrudan bellek erişimi (DMA)
  - Polling'de işlemci, çevre biriminin durum (status) yazmacını sürekli okuyup bit maskeleyerek verinin hazır olup olmadığını denetler. 8251'de RxRDY/TxRDY, 8255'te INTRA/INTRB, 8254'te OUT ucu, ADC'de kesme isteği ucu bu amaçla kullanılmıştı.
  - Kesme temelli aktarımda işlemci başka işle uğraşırken, veri hazır olduğunda çevre birimi kesme ucu üzerinden işlemciyi uyarır; işlemci yürüttüğü komutu bitirip kesme alt programına dallanır.
  - DMA'da DMA denetleyicisine kaynak adres, hedef adres ve aktarılacak bayt sayısı yazılır; işlemci yolların denetimini denetleyiciye bırakır ve veri işlemciden geçmeden aktarılır. DMA bu ders kapsamında ayrıntılı işlenmedi.
- Kesme kaynakları ve kesme bayrakları (tekrar)
  - Yazılımsal: `INT n` (0-255 arası 256 tip), `INTO` (tip 4), `INT 3` (breakpoint) ve işlem sonucu oluşan kesmeler (sıfıra bölme, bölme taşması).
  - Donanımsal: NMI (yükselen kenar tetiklemeli, her zaman tip 2) ve INTR (seviye tetiklemeli, IF ile maskelenebilir). INTR'ye karşılık işlemci $\overline{INTA}$ ucundan iki kez onay darbesi verir; ikinci darbede çevre birimi kesme tipini D0-D7 uçlarına koyar.
  - TF (trap flag) 1 iken her komuttan sonra tip 1 (single-step) kesmesi oluşur; adım adım hata ayıklama için kullanılır.
  - Kesme alt programına girildiğinde IF ve TF otomatik olarak 0 yapılır; IRET ile dönüşte bayraklar yığından eski değerleriyle geri yüklenir.
- Kesme vektör tablosu
  - Fiziksel adres uzayının 00000H adresinden başlar, 256 göz × 4 bayt = 1024 bayttır. Her gözde kesme alt programının yalnız adresi bulunur: düşük adreste offset, yüksek adreste segment.
  - Tip $n$ için offset adresi $4n$, segment adresi $4n+2$'dir.
  - Reset sonrası CS=FFFFH, IP=0000H ile FFFF0H adresinden BIOS çalışır; tabloya önce BIOS, sonra işletim sistemi (DOS), en son kullanıcı programları kendi kesme alt programlarının adreslerini yazar.
- Kesme işleminin adımları (ekrandan, 00:30:00)
  - İşlemci sıradaki komutu bitirince sırasıyla komut işleme ile oluşan kesme, single-step, NMI, INTR ve INT kesmelerine bakar.
  - Kesme varsa: PUSHF, IF←0 ve TF←0, PUSH CS, PUSH IP, sonra IP ve CS kesme vektör tablosundan yüklenir.
  - IRET sırasıyla IP, CS ve bayrak yazmacını yığından çeker.
- Kesme vektör tablosunu değiştirme örneği: DIV0 (ekrandan, 00:45:00-01:05:00)
  - İki word dizisinin karşılıklı elemanları bölünür; ikinci elemanda $2/0$ işlemi sıfıra bölme kesmesini tetikler. Kendi kesme alt programımız (`NEWINT`) bu durumda AX'e `0FFFFH` döndürür.
  - Program önce tablonun 0. gözündeki eski offset ve segmenti `OLDOF` ve `OLDSG` değişkenlerine yedekler, sonra `NEWINT`'in offsetini (LEA ile) ve CS'yi ES:[0] ve ES:[2]'ye yazar. Program biterken eski değerler geri yazılır.
  - Sıfıra bölmede dönüş adresi bölmeyi yapan `DIV BX` komutunu gösterir. Bu yüzden kesme alt programı BP ile yığında sabit referans kurar, [BP+2]'deki dönüş IP'sini `DIV BX` komutunun boyu olan 2 bayt artırır.
- Basit donanımla INTR kullanımı (ekrandan, 01:30:00)
  - Sabit tipli devre: pull-up dirençli DIP anahtarlar ve $\overline{INTA}$ ile etkinleşen bir tampon (latch) her kesmede aynı tipi veri yoluna koyar.
  - 74ALS244 tampon ve 8 girişli 74ALS30 NAND ile genişletme: aktif-0 IR0-IR6 istekleri D0-D6'ya, D7 pull-up ile 1'e bağlıdır; herhangi bir istek 0 olursa NAND çıkışı 1 olur ve INTR tetiklenir. Kesme tipi, etkin isteklerin birleşimine göre değişir.
  - Daisy chain: iki 8255'in INTRA ve INTRB çıkışları OR'lanarak tek INTR ucuna bağlanır; kaynak, kesme alt programında çevre birimlerinin durum yazmaçları sırayla okunarak bulunur. Okuma sırası önceliği belirler.
- 8259A programlanabilir kesme denetleyicisi
  - Tek başına 8 kesme kaynağını (IR0-IR7), bir master ve 8 slave ile kaskat bağlantıda 64 kaynağı yönetir. Öncelik atar, maskeleme yapar, her kaynağa programlanan kesme tipini işlemciye verir.
  - Uçlar: D0-D7, $\overline{RD}$, $\overline{WR}$, $\overline{CS}$, tek adres ucu A0, INT (işlemcinin INTR ucuna), $\overline{INTA}$, CAS0-CAS2 (kaskat), $\overline{SP}/\overline{EN}$ (tek kullanımda lojik 1, master).
  - İç yapı: Interrupt Request Register (IRR), Priority Resolver, Interrupt Service Register (ISR), Interrupt Mask Register, kontrol mantığı ve iç veri yolu.
  - Ayar yazmaçları: ICW1 (A0=0), ICW2, ICW3, ICW4 (A0=1, akış şemasına göre sırayla). İşletim yazmaçları: OCW1-OCW3.
- 8259 ile buton sayacı örneği (ekrandan, 02:00:00)
  - 8259 60H ve 62H adreslerinde; IR0'a pull-down butonu bağlı. Her basışta 40H tipi kesme oluşur ve kesme alt programı AX'i 1 artırır.
  - Ayar: ICW1=13H (60H'ya), ICW2=40H ve ICW4=03H (62H'ye), sonra STI ve sonsuz döngü.

## Hocanın Özellikle Vurguladığı Kısımlar

- Polling, kesme ve DMA kavramları
  - Hoca bu üç yöntemi kavramsal olarak bilmeyi istedi ve sözel soru olarak sorulabileceğini söyledi.
- Sıfıra bölme kesmesinin özel dönüşü
  - Hocaya göre neredeyse bütün near/far çağrılar ve kesmeler bir sonraki komuta döner; sıfıra bölmede ise dönüş, hatayı oluşturan komuta yapılır. Bunun için kesme alt programında dönüş IP'si komut boyu kadar (DIV BX için 2) artırılır.
- Yığının yönü
  - Yığına her PUSH'ta SP 2 azalır; yığının dibi yüksek adreste, üstü düşük adrestedir. Hoca bunu "çok önemli" diye vurguladı.
- Dolaylı adreslemede varsayılan segment
  - Köşeli parantezde BX, SI, DI ya da sabit değer varsa DS; BP varsa SS kullanılır. Bu yüzden [BP+2] yığından okur. Kesme vektör tablosuna erişmek için ES=0 yapılıp `ES:` öneki kullanıldı.
- ICW2'nin anlamı
  - Hoca "ICW2'yi anlarsak 8259'u çözüyoruz" dedi: T7-T3 bitlerini programcı yazar, T2-T0 bitleri isteği gelen IR ucunun numarasıyla otomatik dolar.
- STI
  - 8259 ayarlarından sonra STI ile IF'nin 1 yapılması "çok önemli"dir; yoksa INTR değerlendirilmez.
- 8259'da kenar tetikleme
  - 8259'un IR girişleri kenar tetiklemeli programlanabilir, ama bu ayar 8086'nın INTR ucunu kenar tetiklemeli yapmaz; INTR seviye tetiklemeli kalır.

## Kısa Tekrar Notları

- NMI: yükselen kenar, tip 2, vektör adresi 008H. INTR: seviye tetiklemeli, IF=1 olmalı, tipi ikinci $\overline{INTA}$ darbesinde veri yolundan okunur.
- Ekranda: "Adres uçlarından gönderilen kesme TİP'idir, kesme vektör tablosunun ilgili adresi değil." (ekrandan, 00:15:00)
- Tip $n$ → offset $4n$, segment $4n+2$. Örnek: tip 10H → 40H ve 42H; tip 40H → 100H ve 102H.
- Kesmeye girişte: PUSHF, IF=TF=0, PUSH CS, PUSH IP. IRET: POP IP, POP CS, POP FLAGS.
- STI/CLI yalnız IF içindir; TF için özel komut yoktur. LAHF/SAHF TF'yi kapsamaz. TF, bayraklar yığına atılıp 8. bit OR ile 1, AND ile 0 yapılarak değiştirilir.
- Kendi kesme alt programını yerleştirirken eski vektörü yedekle, programdan çıkarken geri yaz.
- 74ALS244/74ALS30 devresinde: yalnız IR0 → FEH, yalnız IR6 → BFH, IR0 ve IR6 birlikte → BEH.
- 8259: tek başına 8, kaskat 64 kaynak. A0=0 → ICW1; A0=1 → ICW2, (kaskatta ICW3), (IC4=1 ise) ICW4.
- ICW1 = 0001 LTIM 0 SNGL IC4. Tek 8259, kenar tetikleme, ICW4 gerekli → 13H.
- ICW2 = T7-T3 + IR numarası. ICW2=80H ise IR0→80H, IR4→84H, IR7→87H.
- ICW4 = 03H: otomatik EOI ve 8086 modu.
- Derste tek 8259 ve otomatik EOI kullanıldığı için ICW3 ve OCW'ler kullanılmadı.

## Detaylı Açıklamalar

- **Kesme vektör tablosu ve doldurulması.** Tablo, 20 bitlik adres uzayının 00000H adresinden başlayan 1024 baytlık alandır. 256 kesme tipinin her biri için 4 bayt ayrılır. 4 bayta bir fonksiyon sığmayacağı için gözlerde kesme alt programlarının kendisi değil, uzak (far) adresleri tutulur: düşük adresli word offset, yüksek adresli word segmenttir. Sistem açıldığında tablo boştur; CS=FFFFH, IP=0000H ile hesaplanan FFFF0H adresinde bulunan BIOS ROM'u kendi kesme alt programlarının adreslerini tabloya yazar, sonra denetimi işletim sistemine (DOS) devreder. DOS kendi kesmelerini ekler. Kullanıcı programları da kendileri için ayrılan alanı kullanır. Tablodaki ilk tipler: tip 0 sıfıra bölme, tip 1 single-step, tip 2 NMI, tip 3 breakpoint, tip 4 taşma (overflow). Hocaya göre 1FH'ye kadar olan tipler özel olarak ayrılmıştır, 20H'den itibaren olanlar işletim sistemi ve kullanıcı için kullanılabilir.
  - Ders sonrası not: Hoca bu sınırı "1FH adresine kadar" diye söyledi. Burada kastedilen büyük olasılıkla kesme tipi numarasıdır; tip 00H-1FH tabloda 00000H-0007FH adreslerine karşılık gelir.
- **DIV0 örneği (ekrandan, 00:45:00-01:05:00).** Kod şöyledir:

```text
STACKSG SEGMENT PARA STACK 'STACK'
        DW 12 DUP(?)
STACKSG ENDS
DATASG  SEGMENT PARA 'DATA'
DIZI1   DW 1,2,3,4,5,6,7
DIZI2   DW 1,0,3,4,5,6,7
ELEMAN  DW 7
OLDOF   DW 0
OLDSG   DW 0
DATASG ENDS
CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG
NEWINT  PROC FAR
        PUSH BP
        MOV BP, SP
        MOV AX, [BP+2]
        ADD AX, 2
        MOV [BP+2], AX
        MOV AX, 0FFFFH
        POP BP
        IRET
NEWINT  ENDP
BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DATASG
        MOV DS, AX
        XOR AX, AX
        MOV ES, AX
        MOV AX, WORD PTR ES:[0]
        MOV OLDOF, AX
        MOV AX, WORD PTR ES:[2]
        MOV OLDSG, AX
        LEA AX, NEWINT
        MOV WORD PTR ES:[0], AX
        MOV AX, CS
        MOV WORD PTR ES:[2], AX
        STI
        XOR SI, SI
        MOV CX, ELEMAN
TEKRAR: XOR DX, DX
        MOV AX, DIZI1[SI]
        MOV BX, DIZI2[SI]
        DIV BX
        ADD SI, 2
        LOOP TEKRAR
        XOR AX, AX
        MOV ES, AX
        MOV AX, OLDOF
        MOV WORD PTR ES:[0], AX
        MOV AX, OLDSG
        MOV WORD PTR ES:[2], AX
        RETF
BASLA   ENDP
CODESG  ENDS
        END BASLA
```

  - ES'ye doğrudan sabit atanamadığı için 0 değeri AX üzerinden verilir. `ES:` öneki varsayılan DS'yi geçersiz kılar; ES:[0] fiziksel 00000H, ES:[2] fiziksel 00002H adresidir.
  - `NEWINT` kod segmentinin başında olduğu için LEA ile alınan offset 0'dır. Segment değeri, program o anda bu kod segmentinde çalıştığı için CS'den alınır.
  - Kesme alt programına girildiğinde yığında yukarıdan aşağı BP, ana IP, ana CS, FLAG, OS IP (=0) ve OS CS vardır (ekrandan, 01:00:00). BP'nin kullanılma nedeni, alt programda PUSH/POP yapılsa bile değişmeyen sabit bir referans sağlamasıdır. Ana IP, BP'ye göre +2 uzaklıktadır.
  - DOSBox debug çıktısında (ekrandan, 01:10:00) CS=076FH, kesmede yığındaki dönüş IP'si 004BH idi ve 2 eklenince 004DH oldu; dönüş `DIV BX`'ten sonraki `ADD SI,2` komutuna yapıldı. Altyazıya göre tablonun 0. gözünde önceden offset 1060H ve segment F000H vardı.
  - Hoca, bu örnekte dönüş değerinin 2 artırılmasını sıfıra bölmeye özgü bir durum olarak anlattı.
- **8259A'nın çalışma akışı.** IR0-IR7'den birine istek gelince 8259, maskeleme ve öncelik çözümlemesinden sonra en öncelikli isteği INT ucu ile işlemcinin INTR ucuna iletir. İşlemci yürüttüğü komutu bitirir ve IF=1 ise ilk $\overline{INTA}$ darbesini gönderir; 8259 IRR ve ISR'deki ilgili bitleri günceller. İkinci $\overline{INTA}$ darbesinde programlanmış kesme tipini veri yoluna koyar. Otomatik EOI modunda ISR biti kendiliğinden 0 yapılır; normal EOI modunda bunu programcının yapması gerekir. Derste otomatik EOI kullanıldı.
- **8259 buton sayacı örneği (ekrandan, 02:00:00 ve 02:05:00).** Adres çözümlemede A0=0, A1 8259'un A0 ucuna bağlı, A2-A4=0 (Y0 çıkışı), A5=A6=1 ve A7=0 olduğundan 8259 60H ve 62H adreslerindedir. Ana program 40H tipinin tablo adresini `MOV AL,40H / MOV AH,4 / MUL AH` ile hesaplar (BX=0100H), `NEWINT`'in offsetini ES:[BX]'e, CS'yi ES:[BX+2]'ye yazar. Sonra `MOV AL,13H / OUT 60H,AL` (ICW1), `MOV AL,40H / OUT 62H,AL` (ICW2: IR0→40H … IR7→47H), `MOV AL,03H / OUT 62H,AL` (ICW4), `STI`, `XOR AX,AX` ve sonsuz döngü gelir. Kesme alt programı `PUSH BP / MOV BP,SP / INC AX / POP BP / IRET`'tir. Hoca bu örnekte eski vektörün yedeklenip geri yazılmadığını, bunun yapılması gerektiğini belirtti. Benzetimde ilk denemede dönüş bozuldu; neden, gösterim için yığın segmentinin kapatılmış olmasıydı. Yığın segmenti geri konunca üç basışta AX=3 görüldü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
