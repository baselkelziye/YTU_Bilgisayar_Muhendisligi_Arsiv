# Ders 12 Çalışma Özeti

## Genel Konular

- Üç veri aktarım yaklaşımı: polling, kesme (interrupt), DMA
  - Polling: İşlemci çevre biriminin (örneğin klavye kontrolcüsünün) durum (status) baytını okur, ilgili biti maskeleyip kontrol eder. Veri hazır değilse aynı okumayı bir döngüde tekrarlar; hazır olunca veri baytını okur. Dezavantajı, işlemcinin sürekli bu kontrolle meşgul olmasıdır.
  - Kesme: Veri hazır olduğunda çevre birimi bir fiziki uç üzerinden işlemciye kesme isteği gönderir. İşlemci o anki komutu bitirir, yaptığı işi bırakır, kesme alt programında veriyi okur ve kaldığı yere döner. Slaytta öğrenci-hoparlör-kova benzetmesi kullanıldı (ekrandan, 00:10:00).
  - Polling ve kesmede veri önce işlemciye (bir yazmaca) okunur, sonra belleğe yazılır; iki bellek adresi alan tek bir komut yoktur.
  - DMA (Direct Memory Access): İşlemci DMA kontrolcüsüne kaynak başlangıç adresini, hedef başlangıç adresini ve aktarılacak bayt sayısını programlar, sonra veri ve adres yollarının kontrolünü ona bırakır. Veri işlemciden geçmeden iki birim arasında aktarılır. Bu dönem ayrıntısına girilmedi.
- 8086'da kesme kaynakları (ekrandan, 00:20:00)
  - Yazılımsal: `INT n` (n, 0-255 arası 8 bitlik anlık değer; kesme tipini verir, bu yüzden en çok 256 kesme tipi vardır), `INTO` (tip 4), `INT 3`.
  - Komut yürütülürken oluşanlar: sıfıra bölme (tip 0), TF=1 iken her komuttan sonra oluşan tek adım kesmesi (tip 1), bölmede taşma.
  - Donanımsal: NMI (maskelenemez, her zaman tip 2) ve INTR (IF bayrağıyla maskelenebilir). Donanım kesmesinin onayı $\overline{INTA}$ ucuyla verilir.
  - Kesmeyle ilgili bayraklar IF ve TF; dönüş komutu IRET.
- NMI ve INTR farkı
  - NMI sistemin sağlığıyla ilgili kritik durumlar (besleme seviyesi, eksik bileşen) için kullanılır; yükselen kenarla tetiklenir.
  - INTR operasyonel istekler (veri hazır, seri veri gönderilebilir, zamanlayıcı doldu, ADC dönüşümü bitti) içindir; seviye tetiklemelidir (lojik 1 belirli bir süre korunmalıdır).
  - INTR işlemci için giriş, INTA çıkış ucudur. INTR isteğinden sonra kesme tipi işlemciye ayrıca bildirilmelidir.
- Kesme vektör tablosu (ekrandan, 00:30:00 ve 01:20:00)
  - Bellekte 00000H-003FFH arasındaki 1024 baytlık alandır. 256 gözün her biri 4 bayttır ($256 \times 4 = 1024$).
  - Gözlerde kesme alt programının kendisi değil, adresi (ofset ve segment) bulunur. Düşük adreste ofset, yüksek adreste segment vardır.
  - Sabit tipler: tip 0 sıfıra bölme (000H), tip 1 tek adım (004H), tip 2 NMI (008H), tip 3 bir baytlık breakpoint (00CH), tip 4 taşma (010H). 014H-07FH arası ayrılmış (reserved), 080H-3FFH arası kullanılabilir gözlerdir.
  - Önce BIOS kendi kesme alt programlarının adreslerini tabloya yazar, sonra DOS kendi gözlerini doldurur, kullanıcı programı da kendi kesme alt programlarını yerleştirebilir.
- Kesme işlemi (ekrandan, 00:35:00)
  - İşlemci o anki komutu bitirince kesmeleri belirli bir sırayla kontrol eder. Senkron çalıştığı için iki saat darbesi arasında gelen istekler aynı kontrol çevriminde gelmiş sayılır.
  - Kesme varsa işlemci kendiliğinden: PUSHF; IF←0, TF←0; PUSH CS; PUSH IP; IP ve CS'yi tablonun ilgili gözünden yükler.
  - IRET yığından sırasıyla IP, CS ve bayrak yazmacını çeker. RET yalnız IP'yi, RETF IP ve CS'yi çeker.
  - IF için STI (IF=1) ve CLI (IF=0) vardır; TF için özel komut yoktur.
- Örnek: sıfıra bölme (DIV0) kesme alt programını değiştirme (ekrandan, 01:05:00-01:40:00)
  - DIZI1 = 1,2,...,7 ve DIZI2 = 1,0,3,4,5,6,7 dizilerinin karşılıklı elemanları bölünür. 2/0 adımında tip 0 kesmesi oluşur.
  - Program başında tablonun tip 0 gözündeki eski ofset ve segment OLDOF ve OLDSG'ye yedeklenir, gözlere NEWINT'in adresi yazılır; program sonunda eski değerler geri yüklenir.
  - NEWINT dönüş ofsetini 2 artırır (DIV BX iki bayttır) ve AX'e "sonsuz" yerine 0FFFFH yazar, IRET ile döner.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kesme vektör tablosunda fonksiyonun kendisi yoktur, yalnız kesme alt programlarının adresleri vardır.
  - Hoca bunu "çok önemli bir nokta" diye tekrar etti. 4 baytlık göze bir alt program sığmaz.
- Tip $n$ gözünün ofseti $n \times 4$'tür.
  - 40H tipine yerleştirmek için ES yine 0 kalır, ofset gözü $40H \times 4 = 100H$, segment gözü 102H olur.
- Kesme alt programına girerken bayraklar yığına atılır ve IF ile TF sıfırlanır.
  - Amaç iç içe kesmeyi varsayılan olarak engellemektir. Programcı kontrolü sağlayabiliyorsa başka kaynaktan kesme almak için alt programda IF'yi yeniden açabilir.
- Sıfıra bölme kesmesi, dönüşte bölmeyi yapan satırın kendisine döner.
  - Dönüş adresi düzeltilmezse program aynı satırda sonsuz döngüye girer. Bölmenin 8 ya da 16 bitlik komutta olabileceği için ayarlamanın kullanıcıya bırakıldığını söyledi.
- Dönüş adresine erişmek için kesme alt programına girer girmez BP ile sabit referans kurulmalıdır.
  - SP alt programda ve başka zaman dilimlerinde değişebilir; SP'ye göre hesap riskli, BP'ye göre işlem kesin çalışan yöntemdir.
- Yığının dibi daha yüksek adrestedir.
  - Yığına bir şey atıldıkça SP azalır, çekildikçe artar.
- Kesme alt programında da geçici kullanılan yazmaçlar girişte yığına atılır, çıkışta geri yüklenir.

## Kısa Tekrar Notları

- Polling: işlemci durum bitini döngüde sorgular. Kesme: çevre birimi işlemciyi uyarır. DMA: işlemci yolları DMA kontrolcüsüne bırakır.
- `INT n`: n 0-255, 256 kesme tipi. `INTO` tip 4.
- Tip 0 sıfıra bölme, tip 1 tek adım, tip 2 NMI, tip 3 breakpoint, tip 4 taşma.
- NMI maskelenemez ve kenar tetiklemeli; INTR IF ile maskelenir ve seviye tetiklemeli; onay INTA ile.
- Kesme vektör tablosu: 00000H-003FFH, 1024 bayt, 256 göz × 4 bayt; düşükte ofset, yüksekte segment.
- Kesmede: PUSHF, IF=TF=0, PUSH CS, PUSH IP, CS:IP ← tablo. IRET: IP, CS, bayraklar geri.
- STI/CLI IF'yi kurar/temizler. TF, bayraklar yığına atılıp 8. bit değiştirilerek kurulabilir.
- Tip 0 gözüne `ES=0` ile `ES:[0]` (ofset) ve `ES:[2]` (segment) üzerinden erişilir; segment yazmacına anlık değer doğrudan atanamaz.
- `LEA AX, NEWINT` etiketin kendi segmentindeki ofsetini verir; segment değeri `MOV AX, CS` ile alınır.
- Kesme alt programında `[BP+2]` dönüş ofsetidir (BP'nin yığına atılmasından sonra).

## Detaylı Açıklamalar

- Polling ile kesme arasındaki fark, işlemcinin zamanını nasıl kullandığıdır. Klavye örneğinde kontrolcüde bir durum yazmacı (verinin hazır olup olmadığını gösteren bir bit) ve bir veri yazmacı (basılan tuşun ASCII kodu) bulunur. Polling'de işlemci durum baytını okur, biti maskeler, istenen değer gelene kadar döngüde tekrar eder, sonra veri baytını okur. Kesmede ise işlemci o sırada başka bir işle, örneğin ekranı sürmekle, uğraşabilir. Tuşa basılınca çevre birimi kesme isteği gönderir; işlemci komutun ortasındaysa komutu bitirir, onay sinyali verir, kesme alt programında veriyi okur ve ekranı sürmeye kaldığı yerden devam eder. Hoca mikrodenetleyicilerde her işlev için ayrı kesme uçları (buton için yükselen kenarla tetiklenen genel kesme ucu, seri haberleşme, zamanlayıcı) bulunabileceğini, bazı işlemcilerde ise tek uçtan alınıp içeride çeşitlendirildiğini söyledi.

- 8086'da bölmede taşma örneği olarak hoca AX=FFFFH değerinin 1'e bölünmesini ve sonucun AL'ye sığmamasını verdi.

> **Ders sonrası not:** Hoca örneği `DIV BX` diye söyledi; ancak `DIV BX` 16 bitlik bölmedir (DX:AX / BX, bölüm AX'te) ve DX=0 iken FFFFH/1 = FFFFH AX'e sığar, taşma olmaz. Sonucun AL'ye sığmaması 8 bitlik bölmede (`DIV BL`, AX / BL, bölüm AL'de) geçerlidir. Ayrıca 8086'da bölmedeki taşma tip 4 (INTO) kesmesini değil, sıfıra bölmeyle aynı tip 0 kesmesini tetikler; tip 4, OF=1 iken `INTO` komutu çalışınca oluşur.

- Kesme vektör tablosu bellek uzayının başındaki 1024 bayttır. Her kesme tipine bir göz düşer ve gözde ilgili kesme alt programının ofseti (düşük adreste) ve segmenti (yüksek adreste) saklanır. Hoca bu yerleşimi yığına benzetti: FAR çağrıda da segment yığında daha yüksek adreste kalır. Bir kesme geldiğinde işlemci tip numarasına göre göze gider, bu iki kelimeyi IP ve CS'ye yükler; bu da kesme alt programına dallanmak demektir.

- Örnek programda (DIV0.ASM) veri segmentinde DIZI1, DIZI2, ELEMAN (7), OLDOF ve OLDSG tanımlıdır. Kod segmentinin başında NEWINT kesme alt programı vardır (ekrandan, 01:15:00):

```asm
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
```

  Ana yordamda tip 0 gözünün yedeği alınıp NEWINT yerleştirilir (ekrandan, 01:10:00):

```asm
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
```

  `ES:` ön eki yazılmasaydı varsayılan segment DS olurdu ve programın kendi veri segmentinin 0. ofseti okunurdu. Hoca `WORD PTR`'nin bu satırlarda gerekmediğini (boyut AX'ten belli) söyledi.

- Debug izlemesinde (DOSBox) DIV BX komutu 076F:004B adresindedir ve makine kodu F7 F3, yani 2 bayttır (ekrandan, 01:40:00). Kesmeden sonra yığında (SS:000E'den itibaren) dönüş ofseti 004B, dönüş segmenti 076F, bayraklar, işletim sistemine dönüş ofseti 0000 ve segmenti bulunur. NEWINT ofseti 4B'yi 4D'ye çevirir; IRET sonrası program `ADD SI, 2` satırından devam eder.

> **Ders sonrası not:** Hoca `MOV AX,[BP+2]` / `ADD AX,2` / `MOV [BP+2],AX` üçlüsü yerine tek satırda `ADD [BP+2], 2` yazılabileceğini söyledi. MASM'de bellek işleneni ile anlık değer birlikte kullanıldığında boyut belirsizdir; satır `ADD WORD PTR [BP+2], 2` biçiminde yazılmalıdır.

> **Ders sonrası not:** Dönüş adresinin bölme komutunun kendisini göstermesi, büyük olasılıkla DOSBox'un taklit ettiği 80286 ve sonrası işlemcilerin davranışıdır. Özgün 8086/8088'de sıfıra bölme kesmesinin dönüş adresi büyük olasılıkla bir sonraki komutu gösterir; o işlemcide dönüş ofsetine 2 eklemek bir komutu atlatır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
