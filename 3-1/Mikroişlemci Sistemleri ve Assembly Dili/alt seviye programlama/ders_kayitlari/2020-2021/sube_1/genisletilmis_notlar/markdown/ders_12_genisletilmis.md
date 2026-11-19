# Ders 12 Genişletilmiş Notu: Kesmeler, Kesme Vektör Tablosu ve DIV0 Kesme Alt Programı Örneği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş ve Segment Birleştirme Üzerine Bir Soru
- 2. Üç Veri Aktarım Yaklaşımı: Polling, Kesme ve DMA
- 3. 8086'da Kesme Kaynakları
- 4. Donanım Kesmeleri: NMI, INTR ve INTA
- 5. Kesme Bayrakları ve IRET
- 6. Kesme Vektör Tablosu
- 7. Kesme İşleminin Adımları
- 8. Örnek: DIV0 Kesme Alt Programını Değiştirme
- 9. Kesme Alt Programı ve Yığın
- 10. DOSBox'ta Debug ile İzleme
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş ve Segment Birleştirme Üzerine Bir Soru

Bu ders, bir önceki hafta başlanan kesme (interrupt) konusunun devamıdır. Geçen hafta kesme vektör tablosunun tanıtımına kadar gelinmişti. Hoca bu hafta o noktaya kadar hızlı bir tekrar yapıp konuyu bir kesme örneğiyle tamamlayacağını söyledi. Slaytların başlığı "ALT SEVİYE PROGRAMLAMA"dır (ekrandan, 00:05:00).

Dersin başında bir önceki dersle ilgili bir soru geldi.

**Soru:** Segmentleri birleştirmenin avantajları anlatıldı. Her durumda daha avantajlıysa yordamları hep segment birleştirerek yazmak daha mantıklı değil mi?

**Cevap:** Evet, segment birleştirme daha mantıklıdır. Ders kapsamında kavramlar adım adım kurulduğu için birleştirme ancak belli bir noktadan sonra tanımlanabildi. Gündelik programlamada segmentler sürekli birleştirilerek kullanılabilir; bu daha uygun olur.

## 2. Üç Veri Aktarım Yaklaşımı: Polling, Kesme ve DMA

Hoca kesme konusuna girmeden önce üç farklı veri aktarım yaklaşımını hatırlattı: polling, kesme ve doğrudan bellek erişimi (DMA). Anlatım bir donanım örneği üzerinden yürüdü: İşlemci bir çevre birimiyle iletişimdedir ve o birimde hazır olan bir veriyi okumak ister. Örneğin bir tuşa basılmıştır ve işlemci bu tuşun ASCII değerini okumak istemektedir.

### 2.1 Polling

Senaryoda klavye tarafındaki arayüzde (interface) iki yazmaç vardır. Birincisi klavye kontrolcüsünün durum (status) baytıdır; bunun bir biti, içeride hazır bir verinin olup olmadığını gösterir. İkincisi veri yazmacıdır; basılan tuşun ASCII karakteri burada durur.

İşlemci karakteri okuyabilmek için önce kontrolcünün hazır olduğunu garanti etmelidir. Bunun için durum baytını okur. Okuduğu değerin içindeki tek bir kontrol bitiyle ilgilenir; o biti maskeler ve istenen değerde olup olmadığına bakar. Değilse bir döngü içinde durum baytını yeniden okur, yine maskeler ve yine kontrol eder. Bu, istenen bit değerine ulaşılana kadar sürer. Bit istenen değere ulaştığında döngüden çıkılır ve hemen ardından kontrolcünün veri baytı okunarak karakter alınır.

Bu yaklaşıma polling denir. İşlemci sürekli ve aktif biçimde durumu kontrol eder, veri hazır olunca gidip okur. Dezavantajı, işlemcinin bu kontrolle sürekli meşgul olmasıdır. Başka işlere zaman ayırabilmesi için çok görevlilik (multitasking) gibi ek düzenekler gerekebilir.

### 2.2 Kesme

Kesme yaklaşımında aynı senaryo düşünülür. Tuşa basıldığında değer veri yazmacına yazılır ve durum biti uygun biçimde kurulur. Buna ek olarak çevre birimi bir fiziki uç üzerinden işlemciyi tetikler. Bu uç kesme istek ucudur.

Hoca, 8086 dahil bütün işlemcilerin çeşitli kesme giriş uçları olduğunu söyledi. Bazı işlemcilerde istek tek bir uçtan alınıp içeride çeşitlendirilir. Bazı mikrodenetleyicilerde ise her işleve ayrı bir kesme ucu ayrılmıştır. Örneğin yükselen kenarla tetiklenen genel kesme istek uçları vardır; buraya bir buton bağlanırsa butona basıldığı anda kesme oluşur. Seri veri alma ve gönderme için ayrı kesme kaynakları, içerideki zamanlayıcı dolduğunda oluşan ayrı bir kesme kaynağı bulunabilir.

Senaryoya dönülürse: tuşa basılınca durum biti kurulur ve işlemciye kesme isteği gönderilir. Bunun için çevre biriminin kesmeyle ilgili ayarlarının önceden yapılmış olduğu varsayılır. İşlemci o sırada başka bir işle, örneğin ekranı sürmekle uğraşıyor olabilir. İstek geldiğinde bir komutun ortasındaysa önce o komutu tamamlar. 8086'da bir istek ve buna karşılık bir onay (acknowledge) gönderilmesi biçiminde çalışan bir el sıkışma (handshaking) yapısı vardır. Bu basit senaryoda onay, verinin hazır olduğu anlamına da gelir. İşlemci yaptığı işi keser, çevre biriminden veriyi okur, sonra geri dönüp ekranı sürmeye kaldığı yerden devam eder. Veri okumaya ilişkin komutlar, otomatik olarak tetiklenen kesme alt programının içinde yürütülür.

Slaytta bu fark bir benzetmeyle gösterildi (ekrandan, 00:10:00). Bir öğrenci ders çalışmaktadır. Giriş birimi bir kovayı doldurur; kova dolunca bir hoparlör müzik çalmaya başlar ("kesme isteği"). Öğrenci, "Ben sadece çalışacağım; hoparlör çalmaya başlarsa kova dolmuş demektir, o zaman kovadaki suyu varile (belleğe) aktarırım" diye düşünür. Öğrenci işlemciyi, kova giriş birimini, varil belleği temsil eder.

### 2.3 Polling ve Kesmede Verinin Yolu

Hoca, polling ve kesmede verinin önce işlemciye okunduğunu, sonra belleğe aktarıldığını vurguladı. İki bellek adresini birlikte işlenen olarak alan bir komut yoktur. Bu yüzden veri önce bir yazmaca okunur, sonra o yazmaçtan ikinci adres bölgesine yazılır. Polling'de bu işlem programın akışı içinde, kesmede ise kesme alt programının içinde yapılır. "Okumak" burada işlemcinin içindeki bir yazmaca kopyalamak demektir.

### 2.4 Doğrudan Bellek Erişimi (DMA)

Üçüncü yaklaşım Direct Memory Access'tir. Burada verinin önce işlemciye, sonra ikinci birime aktarılması söz konusu değildir. Sistemde bir DMA kontrolcüsü vardır. İşlemci bu kontrolcüyü programlar: G/Ç ya da bellek uzayındaki kaynak başlangıç adresini, hedef başlangıç adresini ve kaç bayt aktarılacağını verir. Ardından veri yolu ve adres yolunun kontrolünü DMA kontrolcüsüne bırakır; yollar üzerinde artık denetim kurmaz. DMA kontrolcüsü kaynak ve hedef adreslerini art arda üreterek aktarımı kendisi yürütür. Böylece veri iki birim arasında doğrudan aktarılır, işlemciden geçmez.

Hoca takvim sıkışık olduğu için DMA kontrolcüsüne ne bu derste ne de mikroişlemciler dersinde ayrıntılı değinilebildiğini söyledi.

## 3. 8086'da Kesme Kaynakları

Slayttaki özet şöyledir (ekrandan, 00:20:00):

- Yazılımsal olarak: `INT`, `INTO`, `INT 3`
- Donanımsal olarak: `INTR`, `NMI`
  - Donanım kesmesiyle ilgili onay (acknowledge): $\overline{INTA}$
- Kesmeyle ilgili bayraklar: `IF`, `TF`
- Kesmeyle ilgili dönüş komutu: `IRET`

8086'da temelde iki kaynak vardır: harici (donanımsal) kesmeler ve yazılımsal kesmeler. Yazılımsal kesmelerin de iki alt başlığı vardır.

### 3.1 Doğrudan Kesme Tetikleyen Komutlar

Birincisi, tıpkı bir fonksiyon çağrısı gibi kesme alt programı çağıran komutlardır. `CALL` komutunun kesme alt programı çağıran karşılığı `INT` komutudur (interrupt'tan gelir). `INT`, yanında 0 ile 255 arasında 8 bitlik bir anlık (immediate) değer alır. Bu değer kesme tipini belirtir. Buradan 8086'da en çok 256 farklı kesme tipi tanımlanabileceği sonucu çıkar.

Bunun yanında parametre almayan özel komutlar da vardır. Bunlardan biri `INTO`'dur (interrupt on overflow). Çağrıldığında özel bir tipte, tip 4'te kesme kendiliğinden tetiklenir.

### 3.2 Komut Yürütülürken Oluşan Kesmeler

İkinci yazılımsal kaynak, yürütülen komutların sonucunda doğan kesme istekleridir:

- Sıfıra bölme (divide by zero): Bir sayı sıfıra bölünmeye çalışıldığında sıfıra bölme kesmesi kendiliğinden tetiklenir.
- Tek adım (trap): TF bayrağı kurulmuşsa her komut yürütüldükten sonra tip 1 kesmesi tetiklenir.
- Bölmede taşma: Hoca geçen haftaki örneği hatırlattı: AX'te FFFFH olsun ve bu değer BX'teki 1'e bölünsün. Sonuç AL'ye, yani 8 bite sığmayacaktır ve bölmeye ilişkin bir taşma durumu oluşur.

> **Ders sonrası not:** Hoca örneği `DIV BX` komutuyla söyledi. `DIV BX` 16 bitlik bölmedir: DX:AX, BX'e bölünür ve bölüm AX'e yazılır. DX=0 iken FFFFH/1 = FFFFH AX'e sığar, taşma olmaz. Bölümün AL'ye sığmaması 8 bitlik bölmede (`DIV BL`: AX, BL'ye bölünür, bölüm AL'ye) geçerlidir. Ayrıca 8086'da bölmedeki taşma, tip 4 (`INTO`) kesmesini değil, sıfıra bölmeyle aynı tip 0 kesmesini tetikler. Tip 4 kesmesi, OF=1 iken `INTO` komutu çalıştırıldığında oluşur.

## 4. Donanım Kesmeleri: NMI, INTR ve INTA

Donanımsal kesmeler iki fiziki uçtan gelir: NMI (non-maskable interrupt) ve INTR (interrupt request).

### 4.1 NMI

NMI ucu, adının söylediği gibi maskelenemeyen, yani yazılımla kapatılamayan bir kesme ucudur. Daha çok sistemin sağlık durumuyla ilgili kritik durumları bildirmek için kullanılır. Örneğin sinyal ya da besleme seviyesi kabul edilebilir bir değerde değilse, bileşenler kontrol edildiğinde eksik bir bileşen varsa ya da kritik bir sorun oluşacaksa bu kesme tetiklenebilir. NMI ucundan gelen istek her zaman tip 2 kesmesini tetikler.

### 4.2 INTR ve IF

INTR ucu, IF bayrağıyla maskelenebilen uçtur. IF=1 ise INTR'den gelen istekler değerlendirmeye alınır; IF=0 ise dikkate alınmaz. INTR daha çok operasyonel işlemler içindir: bir G/Ç biriminden veri hazır, seri veri hazır, seri veri göndermeye hazırım, zamanlayıcı saymayı bitirdi, ADC dönüşümü bitti gibi.

INTR'den gelen isteklerde kesme tipi kendiliğinden belli değildir. Hangi tipin çalıştırılacağı işlemciye ikinci bir veri aktarımıyla ayrıca bildirilmelidir. Hoca bu konuya "biraz sonra bakacağız" dedi, ancak derste ayrıntısına girilmedi.

> **Ek bilgi (derste anlatılmadı):** 8086'da INTR isteği kabul edildiğinde işlemci INTA çıkışından onay döngüleri üretir ve ikinci döngüde kesme tipini veri yolundan 8 bitlik bir sayı olarak okur. Bu sayıyı genellikle 8259 gibi bir programlanabilir kesme denetleyicisi (PIC) veri yoluna koyar.

### 4.3 INTA

İşlemcinin üzerinde INTR ve INTA (interrupt acknowledge) adlı iki fiziki uç vardır. INTR işlemci açısından bir giriş ucudur; INTA ise bir çıkış ucudur. Çevre birimi INTR'den kesme isteği gönderdiğinde işlemci INTA üzerinden "kesmeyi değerlendiriyorum" anlamında bir onay sinyali gönderir. Bu iki uç birlikte çalışır.

### 4.4 Tetikleme Biçimleri

Hoca, önceki anlatımda atladığı bir noktayı tamamladı. NMI ucundaki istek kenar tetiklemelidir: Normalde uçtaki sinyal 0'dadır; çevre birimi lojik 1 oluşturduğunda, 0'dan 1'e yükselme anında kesme tetiklenir. INTR ise seviye tetiklemelidir: Çevre birimi INTR ucunda lojik 1'i belli bir süre boyunca korumak zorundadır. Lojik 1 seviyesi bu süre boyunca sağlanmışsa kesme isteği var diye anlaşılır.

## 5. Kesme Bayrakları ve IRET

### 5.1 IF ve TF

Kesmeyle ilgili iki önemli bayrak vardır. IF (interrupt flag), INTR ucundan gelen isteklerin değerlendirilip değerlendirilmeyeceğini belirler. TF (trap flag) ise tek adım (single step) hata ayıklama amacıyla kullanılır; kuruluyken her komut yürütüldükten sonra tip 1 kesmesi tetiklenir.

Bu bayraklarla ilgili özel bir durum vardır: Ana program akışında uygun biçimde kurulmuş olsalar bile kesme alt programına gidildiğinde işlemci tarafından otomatik olarak sıfırlanırlar. Amaç, varsayılan olarak kesme alt programının içindeyken yeniden kesme gelmesini, yani iç içe kesmeleri önlemektir. Programcı kontrolü net biçimde sağlayabiliyorsa, başka bir kaynaktan gelecek kesmeyi de ele alabilmek için kesme alt programına girdikten sonra IF'yi yeniden kurabilir. Burada kesmelerin tetiklenme sırasını kabaca öngörebilmek gerekir: aynı kaynaktan iç içe iki kesme yine istenmez, ama başka bir kaynaktan gelen kesme bu yolla kabul edilebilir.

IF için özel komutlar vardır:

- `STI` (set interrupt flag): IF'yi 1 yapar.
- `CLI` (clear interrupt flag): IF'yi 0 yapar.

TF için özel bir komut yoktur. TF kurulmak istenirse bayrak yazmacı yığına atılır, yığında bit işlemleriyle 8 numaralı bit kurulur ve değer yeniden bayrak yazmacına yüklenir.

### 5.2 IRET ile Dönüş

Her kesme tipine karşılık bir kesme alt programı tanımlanır. Kesme alt programı, NEAR ya da FAR tipinde tanımlanan alt yordamlara çok benzer, ama temel bir farkı vardır. Kesmeye girerken IF ve TF sıfırlandığı için bayraklar bozulmuş gibi düşünülebilir ve geri alınmaları gerekir. Bu yüzden işlemci kesme alt programına giderken FAR çağrıdan farklı olarak bir işlem daha yapar: önce bayraklar, sonra segment değeri, sonra ofset değeri yığına atılır. Dönüşte bunlar ters sırada geri çekilir.

`RETF` yığından yalnız ofset ve segment çeker. Fazladan atılan bayrak yazmacını da çekebilmek için ayrı bir komut gerekir: `IRET` (interrupt return). Özetle:

- NEAR yordamdan dönüş: `RET`
- FAR yordamdan dönüş: `RETF`
- Kesme alt programından dönüş: `IRET`

## 6. Kesme Vektör Tablosu

### 6.1 Kesme Tipi ile Kesme Alt Programının İlişkisi

Her donanımsal ya da yazılımsal kesme isteğine karşılık bir kesme tipi vardır. `INT` komutunda tip, yanına verilen 0-255 arası anlık değerdir. NMI kendiliğinden tip 2'yi tetikler. INTR'de tip ayrıca bildirilir. Peki kesme tipleri ile kesme alt programları birbirine nasıl bağlanır? Bu bağlantı kesme vektör tablosuyla kurulur.

Slayttaki tanım şöyledir (ekrandan, 00:30:00):

- Kesme vektör tablosu hafıza uzayında 00000H-003FFH adres aralığındaki 1024 baytlık alandır.
- Kesme vektör tablosu toplamda 256 farklı kesme için ilgili fonksiyonların ofset ve kesim (segment) değerlerini saklar.

Tablo 20 bitlik 0H adresinden başlar ve 1023 numaralı adrese kadar gider; 0 ve 1023 dahil 1024 adres gözüdür. 3FFH ondalık 1023'e karşılık gelir. 256 gözün her birinde 4 bayt vardır: $256 \times 4 = 1024$ bayt. Bu adreslerde mutlaka bellek bulunmalıdır.

### 6.2 Gözlerde Ne Saklanır?

Dört baytlık bir göze kesme alt programının kendisi sığmaz; bir kesme alt programının giriş ve çıkışı bile 4 baytı geçer. Bu yüzden tabloya kesme alt programlarının adresi yazılır. Tablo bellek uzayının başında durur, ama kesme alt programı çok farklı bir segmentte olabilir. Bu nedenle saklanan adres hem segment hem ofset değerini içermek zorundadır.

> **Hocanın vurgusu:** Kesme vektör tablosunda fonksiyonun kendisi yoktur. Sadece ve sadece kesme alt programlarının adresleri vardır.

Bir kesme tipi tetiklendiğinde işlemci tablonun o tipe ait gözüne gider, oradaki iki kelimeyi IP ve CS yazmaçlarına yükler. Bu değerler yüklenince program kendiliğinden kesme alt programına dallanmış olur.

### 6.3 Gözdeki Yerleşim

Bir gözün içinde düşük adreslerde ofset, yüksek adreslerde segment vardır (ekrandan, 01:20:00). Slayttaki çizimde göz aşağıdan yukarı "Offset (low), Offset (high), Segment (low), Segment (high)" diye sıralanır. Hoca bunu yığınla karşılaştırdı: FAR çağrıda yığına önce segment atıldığı için segment yığının dibinde, yani daha yüksek adreste kalır. Tabloda da segment yüksek adreste, ofset düşük adrestedir.

### 6.4 Sabit Tipler ve Ayrılmış Alanlar

Slayttaki tablo şöyledir (ekrandan, 01:20:00):

| Adres | İçerik |
|---|---|
| 000H | Divide By 0 (Tip 0) |
| 004H | Single Step (Tip 1) |
| 008H | NMI (Tip 2) |
| 00CH | 1 byte Breakpoint (Tip 3) |
| 010H | Overflow (Tip 4) |
| 014H-07FH | Reserved Interrupt Pointers |
| 080H-3FFH | Available Interrupt Pointers |

Sıfıra bölmede işlemci kendiliğinden tip 0'ı, TF kuruluyken her komuttan sonra tip 1'i, NMI ucundan istek gelince her zaman tip 2'yi, bir kez konan breakpoint'te tip 3'ü, taşma durumunda tip 4'ü tetikler. Hoca bunları "sabit tetiklemeler" diye niteledi.

Ayrılmış alanlar şöyle düşünülebilir. Sistemin açılışını önce BIOS ele alır ve çeşitli kontroller yapar. BIOS'un sistemi denetleyebilmek için kendi kesme alt programları vardır ve açılışta bunların adreslerini tabloya ilk o yerleştirir. Açılış işletim sistemine (DOS) devredildikten sonra DOS da kendi kesme alt programlarının adreslerini kendisine ayrılmış gözlere yazar. Uygulama programcısı da programı yürütülürken kesme alt programına ihtiyaç duyabilir; kullanıcının da kendi kesme alt programlarını tabloya yerleştirme imkânı vardır. Böylece tabloda standart tanımlı gözler, BIOS'a ayrılmış bir kısım, işletim sisteminin kullandığı bir kısım ve kullanıcıya ait bir bölge bulunur.

## 7. Kesme İşleminin Adımları

### 7.1 Kontrol Sırası

Slayttaki "Kesme İşlemi" özeti şöyledir (ekrandan, 00:35:00): Sıradaki işlem bittiğinde işlemci, komut işleme ile oluşan, single-step, NMI, INTR, INT sırasıyla bir kesme olup olmadığını kontrol eder. Hoca bunu sözlü olarak "önce TF kaynaklı tek adım kesmesi, sonra NMI, sonra donanımsal, sonra yazılımsal kesmeler" diye anlattı. İşlemci bu sırada ilk hangisinde istek bulursa onu değerlendirir.

Hoca, işlemcinin senkron çalıştığını hatırlattı. İki saat darbesi arasında farklı anlarda gelen istekler aynı kontrol çevriminde gelmiş sayılır ve öncelik bu kontrol sırasına göre belirlenir. Analog bir yapıda iki isteğin tam aynı anda gelme olasılığı sıfıra yakın olurdu; arada mutlaka bir zaman farkı bulunurdu.

> **Ek bilgi (derste anlatılmadı):** Intel'in 8086 belgelerinde öncelik büyük olasılıkla şöyle verilir: en yüksek öncelikte sıfıra bölme, `INT n` ve `INTO` gibi komutun kendisinden doğan kesmeler; ardından NMI, ardından INTR; en düşük öncelikte tek adım kesmesi. Slayttaki sıralamayla bu sıralamayı karşılaştırırken kaynağın hangi bakış açısıyla yazıldığına dikkat etmek gerekir.

### 7.2 Kesme Varsa İşlemcinin Yaptıkları

Kesme varsa işlemci aşağıdaki işlemleri kendiliğinden yapar; bunlar için programda `PUSHF` gibi bir komut yazmaya gerek yoktur (ekrandan, 00:35:00):

```text
PUSHF
IF <- 0, TF <- 0        (INTR, single-step kesmeleri engellenir)
PUSH CS
PUSH IP
IP <- Kesme_vektör_tablosu, CS <- Kesme_vektör_tablosu
```

Önce bayrak yazmacı yığına atılır. Bunun nedeni, kesme alt programına gidilirken bayrakların sıfırlanacak olması ve bayrakların özgün değerlerinin kaybedilmemesi gerektiğidir. Ardından IF ve TF iç içe kesmeyi engellemek için sıfırlanır. Sonra normal bir FAR çağrıdaki gibi segment ve ofset yığına atılır; bunlar ana programda kalınan noktaya geri dönebilmek içindir.

Sonra kesme tipi belirlenir. Tek adım ve NMI kesmelerinin tipi bellidir. INTR'den sonra tip çevre biriminden ikinci kez istenir. Yazılımla çağrılmışsa tip, `INT`'in yanındaki anlık değerdir. Taşma ya da sıfıra bölme gibi operasyonel durumların tipi de kendiliğinden bellidir. Tip bilinince tablonun o tip numaralı gözüne gidilir, oradaki adres değerleri CS ve IP'ye yüklenir. Bu, kesme alt programına gitmek demektir.

### 7.3 IRET'in Yaptıkları

Kesme alt programı yürütüldükten sonra `IRET` ile dönülür. `IRET` arka planda şunları yapar: yığının en üstünden çektiği değeri IP'ye, ikinci değeri CS'ye, üçüncü değeri bayrak yazmacına yükler. Böylece hem kalınan noktaya hem de özgün bayrak değerlerine geri dönülmüş olur.

## 8. Örnek: DIV0 Kesme Alt Programını Değiştirme

Aradan sonra slayttaki örneğe geçildi: "Örnek: DIV0 kesme alt programının adresini değiştirme" (ekrandan, 01:00:00). Matematikte bir sayının sıfıra bölümü sonsuz kabul edilebilir. 16 bitlik bölmede bölüm AX'te döner. Örnekte sıfıra bölme oluştuğunda AX'e yazılabilecek en büyük değer olan FFFFH'yi döndüren bir kesme alt programı yazılır.

### 8.1 Sıfıra Bölmenin Özel Dönüş Davranışı

Hoca önce bir hatırlatma yaptı. FAR ya da NEAR bir çağrıdan dönüldüğünde `CALL` satırına değil, bir sonraki komuta dönülür; çünkü yığına atılan ofset ve segment, `CALL`'dan hemen sonraki komutun adresidir. Aynı durum kesme alt programlarının çoğu için de geçerlidir. Tek istisna sıfıra bölme kesmesidir: Bu kesmeden dönerken, sıfıra bölmeyi oluşturan satırın kendisine dönülür.

Bu yüzden kesme alt programında özel bir şey yapılmazsa program o satırda takılır: sıfıra bölme oluşur, kesme alt programına gidilir, dönülür, yine aynı satırdadır, yine sıfıra bölme oluşur ve bu sonsuz bir döngüye dönüşür. Kesme alt programı, dönüş adresini bir sonraki komuta ilerletmelidir.

### 8.2 Programın Üç Hedefi

Hoca örnekte dikkat edilecek üç temel noktayı şöyle sıraladı:

- Kesme alt programını yalnız bu program çalıştığı sürece tabloya yerleştirmek ve program bitince kaldırmak. BIOS ya da DOS kesmesi tabloya bir kez yüklendiğinde bilgisayar kapatılana kadar orada kalır; bu örnekte ise kendi alt programımızın yalnız program süresince geçerli olması istenir.
- Kesmeyi ele alıp AX'te FFFFH döndürmek.
- Sıfıra bölmenin dönüş adresini bir sonraki komuta taşımak.

### 8.3 Veri Segmenti

Örnek, standart EXE program şablonu üzerine kurulmuştur. Hoca bütün slaytları ve örnekleri öğrencilerle paylaştığını söyledi. Veri segmentinde iki kelime dizisi vardır. Yapılacak iş, birinci dizinin sıradaki elemanını ikinci dizinin aynı sıradaki elemanına bölerek ilerlemektir: 1/1, 2/0, 3/3, 4/4, 5/5, ... Her iki dizide 7 eleman olduğu için eleman sayısı (ELEMAN) 7'dir. Debug çıktısında veri segmentinin içeriği şöyle görünür (ekrandan, 01:35:00):

```text
076C:0000  01 00 02 00 03 00 04 00-05 00 06 00 07 00 01 00
076C:0010  00 00 03 00 04 00 05 00-06 00 07 00 07 00 00 00
076C:0020  00 00 00 00 00 00 00 00-00 00 00 00 00 00 00 00
```

Buna göre DIZI1 = 1, 2, 3, 4, 5, 6, 7 ve DIZI2 = 1, 0, 3, 4, 5, 6, 7'dir; 1CH ofsetinde ELEMAN = 7 bulunur. Ardından iki kelimelik yedek değişkenler gelir: OLDOF ve OLDSG. Program çalıştığı sürece tablonun sıfıra bölme gözünde bizim alt programımızın adresi olacak, program bitince özgün değerler geri yüklenecektir. Bu yüzden değiştirmeden önce özgün ofset ve segment bu iki değişkene yedeklenir.

Hoca debug sırasında veri segmentinin sonunda kullanılmayan baytları da gösterdi. Segmentler PARA (paragraf) hizalı tanımlandığı için veri segmentinden sonra gelen kod segmenti 16'nın tam katında başlamalıdır. Veri 22H ofsetinde bittiği için 22H-2FH arasında 14 bayt kullanılmadan kalır (ara adım eklendi: $30H - 22H = 14$). Kod segmenti 076C:0030'da, yani 076F:0000'da başlar.

### 8.4 Kod Segmenti ve NEWINT

Kod segmentinin başında bir yordam tanımı vardır ve bu yordamın `IRET` ile bittiği görülür (ekrandan, 01:15:00). `IRET` ile biten yordam bir kesme alt programıdır. Adı NEWINT'tir.

```asm
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
```

Ana yordam BASLA'dır. EXE programı olduğu için `RETF` ile işletim sistemine döner. Başındaki blok işletim sistemine dönüş için yığına değer atar; sonraki blok veri segmentini kullanılabilir hale getirir (ekrandan, 01:10:00):

```asm
BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DATASG
        MOV DS, AX
```

Hoca kesme alt programlarında da yordamlardaki temel kuralın geçerli olduğunu hatırlattı: Alt programda geçici olarak kullanılan yazmaçlar, ana programla alt program arasında en son yüklendikleri değerlerle taşındıkları için, özgün değerleri bozulmasın diye girişte yığına atılır ve çıkışta yığından geri yüklenir.

### 8.5 Tip 0 Gözünün Yedeklenmesi ve NEWINT'in Yerleştirilmesi

Sıfıra bölme tip 0'dır ve tip 0'ın gözü 20 bitlik 0H adresinden başlar. Bu adresteki kelime, işletim sisteminin ya da BIOS'un yerleştirdiği özgün sıfıra bölme alt programının ofsetidir. 20 bitlik 00000H adresi, 0 segmentinin 0 ofsetine karşılık gelir.

Kodun ilgili bölümü şöyledir (ekrandan, 01:10:00):

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

        STI
        XOR SI, SI
```

Bu satırlar adım adım şöyle çalışır:

- `ES:` ön eki yazılmasaydı okuma DS'nin 0. ofsetinden yapılırdı, çünkü bir bellek işleneninde varsayılan segment DS'dir. DS ise şu anda programın kendi veri segmentini göstermektedir. Bize 0 segmentinin 0 ofseti lazım olduğu için ES kullanılır.
- Segment yazmacına doğrudan anlık değer atanamaz; ancak başka bir yazmaç üzerinden değer aktarılabilir. Bu yüzden önce AX sıfırlanır (`XOR AX, AX`), sonra `MOV ES, AX` ile ES=0 yapılır.
- `MOV AX, WORD PTR ES:[0]` 0 segmentinin 0 ofsetindeki kelimeyi, yani özgün ofseti okur; `MOV OLDOF, AX` bunu yedekler.
- Segment, gözün 2H ofsetinden başlar. `MOV AX, WORD PTR ES:[2]` ile okunur ve `MOV OLDSG, AX` ile yedeklenir.
- `LEA AX, NEWINT` (load effective address), NEWINT etiketinin tanımlı olduğu segmentin başından itibaren hangi ofsette olduğunu AX'e verir. Segment değerine hiç karışmaz. Bu örnekte NEWINT kod segmentinin ilk satırında olduğu için AX=0 olur. Araya örneğin bir DELAY yordamı konsaydı NEWINT o yordamın boyu kadar ileride başlardı; bu hesabı elle yapmak gerekmez, assembler kendisi yapar.
- `MOV WORD PTR ES:[0], AX` NEWINT'in ofsetini tip 0 gözünün düşük adresine yazar.
- NEWINT, CS'nin gösterdiği segmenttedir. Program belleğe yüklenip bu satıra gelindiğinde CS belli bir değere sabitlenmiştir. `MOV AX, CS` ve `MOV WORD PTR ES:[2], AX` bu değeri gözün segment kısmına (2H ofsetinden başlayan, little endian kelime) yazar.

Hoca `STI` satırının bu örnekte gerekmediğini, çünkü sıfıra bölme kesmesinin kendiliğinden tetikleneceğini söyledi. Bir öğrencinin uyarısı üzerine `WORD PTR` yazmaya da gerek olmadığını kabul etti: Hedef ya da kaynak AX olduğu için işlenen boyutu zaten bellidir; `WORD PTR` önceki bir notundan kalmıştı.

### 8.6 Döngü ve Özgün Değerlerin Geri Yüklenmesi

Döngüde DIZI1 ve DIZI2'nin SI indisli elemanları alınıp birbirine bölünür, sonra bir sonraki elemana geçilir ve bu, eleman sayısı kadar tekrarlanır (ekrandan, 01:40:00):

```asm
        MOV CX, ELEMAN

TEKRAR:
        XOR DX, DX
        MOV AX, DIZI1[SI]
        MOV BX, DIZI2[SI]
        DIV BX
        ADD SI, 2
```

<!-- BELİRSİZ: Döngünün devamı ve geri yükleme bloğu karelerde görünmüyor. Altyazıya göre döngü 7 eleman boyunca sürer (büyük olasılıkla LOOP TEKRAR); sonra ES yeniden sıfırlanır, OLDOF 20 bitlik 0H adresine, OLDSG 2H adresine yazılır ve işletim sistemine dönülür. Satırların birebir yazımı doğrulanamadı. -->

Döngüden sonra ES "her ihtimale karşı" yeniden sıfırlanır. Veri segmentindeki OLDOF değeri 20 bitlik 0H adresine, OLDSG değeri 2H adresine yazılır. Böylece tablonun özgün değerleri geri yüklenir ve işletim sistemine dönülür.

1/1 adımında sorun yoktur. 2/0 adımına gelindiğinde `DIV BX` satırı sıfıra bölme kesmesini tetikler. İşlemci tablonun 0 numaralı gözüne gider, oradaki adresleri IP ve CS'ye yükler ve program NEWINT'e dallanır. NEWINT iki iş yapar: AX'e sonsuz yerine FFFFH yazar ve dönüş adresini bölme satırından bir sonraki komuta ilerletir.

### 8.7 Başka Bir Tipe Yerleştirmek: 40H Örneği

Hoca derste şu soruyu sordu: NEWINT tip 0 yerine 40H tipindeki göze yerleştirilmek istenseydi neler değişirdi?

Öğrencilerin verdiği iki cevap da bir noktayı eksik bırakmıştı. Hoca iki noktayı açıkladı. Birincisi, ofset 16 bitlik bir değerdir ve 65535'e kadar gidebilir; tablo ise 0'dan 3FFH'ye kadar uzanır. Boyut açısından bir sorun yoktur, bu yüzden ES'yi değiştirmeye gerek yoktur; ES=0 kalır. İkincisi, tip 0'ın gözü 0'dan, tip 1'inki 4'ten, tip 2'ninki 8'den, tip 3'ünkü 0CH'den başlar. Her göz 4 bayt olduğu için 40H tipinin gözü $40H \times 4$ adresindedir:

$$40H \times 4 = 100H$$

Buna göre kodda yalnız ofsetler değişir:

```asm
        MOV AX, ES:[100H]     ; 40H tipinin özgün ofseti
        ...
        MOV AX, ES:[102H]     ; 40H tipinin özgün segmenti
```

Aynı ofsetler, NEWINT'in adresinin yazıldığı satırlarda da kullanılır.

> **Hocanın vurgusu:** Bir kesme tipine karşılık erişilmek istenen göz, tip numarası çarpı 4 ofsetindedir. Buna dikkat edilmelidir.

## 9. Kesme Alt Programı ve Yığın

### 9.1 BP ile Sabit Referans

Kesme alt programında da, yığın üzerinden parametre aktarılan FAR ve NEAR yordamlardaki gibi BP ile sabit bir referans kurulur. Bunun nedeni dönüş ofsetini değiştirmek zorunda olmamızdır. BP güncellendiği için içeride bozulur; bu yüzden geçici bir değişken gibi önce yığına atılır, dönüşte geri çekilir. Bu iki işlem kesinlikle yapılmalıdır. BP yığına atıldıktan sonra SP'nin değeri BP'ye kopyalanır (`MOV BP, SP`) ve sabit referans oluşur.

Hoca yığını tahtada çizdi (ekrandan, 01:30:00). Yığının en dibinde ana programın başında atılan iki değer vardır: `PUSH DS` ile atılan işletim sistemine dönüş segmenti (girişteki DS değeri) ve `PUSH AX` ile atılan işletim sistemine dönüş ofseti (0). Program içinde başka bir şey yığına atılmaz. Sıradaki değerler, sıfıra bölme kesmesi tetiklendiğinde işlemcinin kendiliğinden attığı değerlerdir: bayrak yazmacı, ana programa dönüş CS'si ve ana programa dönüş IP'si. Kesme alt programına girilince BP de yığına atılır. Yığının görünümü, en üstten (düşük adres) dibe (yüksek adres) doğru şöyledir:

```text
BP  ->  BP (eski değer)      <- SP ve BP burayı gösterir
        ANA IP               [BP+2]
        ANA CS               [BP+4]
        FLAG                 [BP+6]
        OS IP (=0)
        OS CS (=DS)
```

Kesme alt programında yığına başka değerler atılsaydı SP yukarı doğru ilerlerdi, ama BP aynı yerde kalırdı. SP kendiliğinden güncellendiği için ona göre sabit bir konum belirlemek mümkün değildir; dönüş IP'sine güvenle erişmek için alt programa girer girmez sabit referans kurmak gerekir.

**Soru:** Dönüş adresinin yerini SP'ye göre dinamik olarak hesaplasak olmaz mı?

**Cevap:** Dinamik hesap çok zordur. Arada yığına bir şeyler atılmış olabilir; bunlar görülse bile hesap zordur, bir de görülmeyenler olabilir. Kesme alt programındayken başka bir zaman diliminde başka bir şey çalışmış ve SP değişmiş olabilir; bundan haberimiz bile olmaz. Yalnız bu program çalışıyorsa kabaca hesaplanabilir, ama bu riske girmeye gerek yoktur. Girer girmez sabit referans oluşturmak kesin çalışan yöntemdir.

### 9.2 Yığının Dibi ve Tepesi

Hoca öğrencilere yığının dibinin mi tepesinin mi daha yüksek adreste olduğunu sordu. Yığına bir şey atıldıkça SP azalır; yukarı doğru gidildikçe adres küçülür. Yığından bir şey çekildikçe SP artar. Yani yığının dibi daha yüksek adreste, tepesi daha düşük adrestedir.

> **Hocanın vurgusu:** Yığına bir şey atıldıkça SP yazmacı azalır, yığından bir şey çekildikçe artar. Yığının dibi yüksek adrestedir. Bu çok önemlidir.

### 9.3 Dönüş Ofsetinin İlerletilmesi

BP'nin gösterdiği satırın hemen altında ana IP vardır; dolayısıyla ana IP, BP'ye göre $+2$ ötededir. Bu değer değiştirilmezse işlemci programı yine `DIV BX` satırına döndürür. Bir sonraki satıra gelebilmek için IP'nin `DIV BX` komutunun boyu kadar artması gerekir. Hoca komutun boyuna emu8086'da baktı (ekrandan, 01:30:00): `DIV BX` 2 bayt yer kaplar. O halde `[BP+2]`'deki kelime 2 artırılmalıdır:

```asm
        MOV AX, [BP+2]
        ADD AX, 2
        MOV [BP+2], AX
```

Hoca bu üç satırın yerine tek bir satır da yazılabileceğini gösterdi: `ADD [BP+2], 2`. Ardından AX'e sonsuzun karşılığı olarak FFFFH yazılır (`MOV AX, 0FFFFH`), BP yığından çekilir ve `IRET` ile dönülür.

> **Ders sonrası not:** MASM'de bellek işleneni ile anlık değer birlikte kullanıldığında işlem boyutu belirsizdir (bayt mı kelime mi). Tek satırlık sürüm `ADD WORD PTR [BP+2], 2` biçiminde yazılmalıdır. Hocanın "WORD PTR'ye gerek yok" sözü, bir işleneni AX olan `MOV` satırları içindi.

Böylece program 2/0 adımında NEWINT'e gider, AX=FFFFH ile `ADD SI, 2` satırına döner, sonraki elemanları bölerek döngüyü bitirir.

## 10. DOSBox'ta Debug ile İzleme

Hoca programı DOSBox'ta derleyip DEBUG ile adım adım izledi.

### 10.1 Başlangıç

Birkaç adım ilerleyip veri segmenti kullanılabilir hale getirildikten sonra veri segmentinin içi incelendi (ekrandan, 01:35:00). DIZI1'in 1-7 değerli kelimeleri, DIZI2'nin elemanları, ELEMAN = 7, iki yedek kelime ve PARA hizalamasından kalan 14 kullanılmayan bayt görüldü. Kayıt satırında başlangıçta SP=0014, SS=076A, CS=076F görülür.

Ardından yığına SS:14H'den itibaren bakıldı. Yığının tepesinde işletim sistemine dönüş ofseti (0) ve işletim sistemine dönüş segmenti bulunur.

### 10.2 Tablonun Değişmesi

Yedekleme satırları yürütüldükten sonra 0 segmentinin 0 ofsetinden itibaren dump alındı. İlk dört baytta işletim sisteminin ya da BIOS'un yerleştirdiği sıfıra bölme alt programının ofseti ve segmenti, sonraki dört baytta tek adım kesmesinin, ardından NMI'nın adresleri görüldü. `LEA AX, NEWINT` satırında NEWINT'in 0 ofsetinde olduğu görüldü; AX'e 0 yüklendi. Segment de yazıldıktan sonra yeniden dump alındığında tip 0 gözünde little endian biçimde ofset 0000 ve segment 076F (programın kendi CS'si) okundu.

### 10.3 Kesme Anında Yığın

Döngüde 1/1 sorunsuz yapıldı. İkinci adımda AX=2, BX=0 iken `DIV BX` çalıştırıldı. Bu komut 076F:004B adresindedir ve makine kodu F7 F3'tür (ekrandan, 01:40:00). Komut yürütülünce kayıtlarda IP=0000 ve SP=000E görüldü; sıradaki komut NEWINT'in ilk satırı `PUSH BP` idi. Bayrak gösteriminde IF'nin kapandığı (EI yerine DI) da görülür.

Yığına SS:0EH'den itibaren bakıldığında şu değerler okunur (ekrandan, 01:40:00):

```text
076A:000E  4B 00        ana programa dönüş ofseti = 004B
076A:0010  6F 07        ana programa dönüş segmenti = 076F
076A:0012  46 73        bayrak yazmacı
076A:0014  00 00        işletim sistemine dönüş ofseti = 0000
076A:0016  5A 07        işletim sistemine dönüş segmenti = 075A
```

Yığına atılan dönüş ofseti 4BH, yani `DIV BX` satırının kendisidir. Değiştirilmeseydi hep aynı satıra dönülecekti. Hoca bu tasarımın nedenini şöyle açıkladı: Sıfıra bölme 8 bitlik bir bölmede de, 16 bitlik bir bölmede de oluşabilir; kaynak sabit değildir. Bu yüzden durumu kullanıcının kendisinin ele alıp düzenlemesi için böyle tasarlanmıştır.

> **Ders sonrası not:** Dönüş adresinin bölme komutunun kendisini göstermesi, büyük olasılıkla DOSBox'un taklit ettiği 80286 ve sonrası işlemcilerin davranışıdır. Özgün 8086/8088'de sıfıra bölme kesmesinin dönüş adresi büyük olasılıkla bir sonraki komutu gösterir; o işlemcide dönüş ofsetine 2 eklemek bir komutu atlatır.

### 10.4 NEWINT İçinde ve IRET Sonrası

`PUSH BP` ile yığın en derin haline ulaştı; SS:0CH'de BP'nin eski değeri (0) görüldü. Hoca BP'nin özgün değerinin farklı olabileceğini, önemli olanın yedeğinin alınması olduğunu söyledi. Sonra `[BP+2]`'deki 4BH AX'e alındı, 2 eklenerek 4DH yapıldı ve geri yazıldı. SS:0CH'den bakıldığında dönüş ofsetinin 4D olduğu görüldü; 4DH bir sonraki komutun adresidir. AX'e FFFFH atandı, BP yığından çekildi.

`IRET` çalıştırılınca yığından dönüş ofseti, dönüş segmenti ve bayraklar çıktı; SS:14H'den bakıldığında yığında yine yalnız işletim sistemine dönüş değerleri kaldı. Program `ADD SI, 2` satırına, yani `DIV BX`'ten sonraki komuta geldi. Sonraki elemanlarda bölme sorunsuz yapıldı. Program bitmeden önce 0 segmentinin 0 ofsetine yeniden bakıldığında özgün değerlerin geri yazıldığı görüldü.

Hoca geçen hafta konuyu önceden anlattığı için bu haftanın tekrar ve örnekle tamamlandığını, kesme konusunun kapsamının böylece bittiğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:10:20): `MOV AX, WORD PTR ES:[0]` satırında `ES:` ön eki yazılmasaydı hangi adres okunurdu?

> **Çözüm:** Anlık ofsetli bir bellek işleneninde varsayılan segment DS'dir; DS:0 okunurdu. DS programın kendi veri segmentini gösterdiği için okunan değer tablonun tip 0 gözü değil, DIZI1'in ilk elemanı olurdu. Tabloya ulaşmak için ES=0 yapılıp `ES:` ön eki açıkça yazılır.

**Soru 2** (derste sözlü, 01:13:51): Bu örnekte `LEA AX, NEWINT` satırı AX'e hangi değeri yükler?

> **Çözüm:** 0. `LEA` etiketin kendi segmentinin başından itibaren ofsetini verir, segment değerine karışmaz. NEWINT, CODESG segmentinin ilk satırında tanımlandığı için ofseti 0'dır (debug'da da 0 görüldü).

**Soru 3** (derste sözlü, 01:15:49): NEWINT fonksiyonu hangi segmenttedir; gözün segment kısmına ne yazılmalıdır?

> **Çözüm:** NEWINT kod segmentindedir; program yüklendikten sonra CS'nin aldığı değer yazılır (`MOV AX, CS`, `MOV ES:[2], AX`). Debug'da bu değer 076F idi.

**Soru 4** (derste sözlü, 01:17:19): NEWINT tip 0 yerine 40H tipindeki göze yerleştirilmek istenseydi kodda ne değişirdi?

> **Çözüm:** ES=0 kalır; tablo 3FFH'ye kadar uzandığı için 16 bitlik ofset yeterlidir. Her göz 4 bayt olduğundan gözün başlangıcı $40H \times 4 = 100H$ olur. Ofset için `ES:[100H]`, segment için `ES:[102H]` kullanılır.

**Soru 5** (derste sözlü, 01:27:44): Yığının dibi mi, tepesi mi daha yüksek adrestedir?

> **Çözüm:** Dibi. Yığına değer atıldıkça SP azalır, çekildikçe artar; tepe düşük adreste kalır.

**Soru 6** (derste sözlü, 01:28:42): NEWINT'te `PUSH BP` ve `MOV BP, SP` sonrasında ana programa dönüş IP'si BP'ye göre ne kadar ötededir?

> **Çözüm:** $+2$. BP'nin gösterdiği kelime BP'nin eski değeridir; hemen altındaki (2 bayt yüksek adresteki) kelime ana IP'dir. Ana CS $[BP+4]$'te, bayraklar $[BP+6]$'dadır.

**Soru 7** (derste sözlü, 01:29:50): Bölmeden sonraki satıra dönebilmek için dönüş ofseti özgün değerinden ne kadar fazla olmalıdır?

> **Çözüm:** `DIV BX` komutunun boyu kadar, yani 2 bayt (makine kodu F7 F3). Debug'da 4BH olan dönüş ofseti 4DH yapıldı.

## Dersin Toparlaması

Bu derste veri aktarımında üç yaklaşım karşılaştırıldı: işlemcinin durum bitini döngüde sorguladığı polling, çevre biriminin işlemciyi bir uçtan uyardığı kesme ve işlemcinin yolları DMA kontrolcüsüne bıraktığı doğrudan bellek erişimi. 8086'nın yazılımsal (`INT n`, `INTO`, `INT 3`, sıfıra bölme, tek adım) ve donanımsal (NMI, INTR/INTA) kesme kaynakları, IF ve TF bayraklarının rolü ve `IRET`'in `RET`/`RETF`'ten farkı ele alındı. Kesme tipleri ile kesme alt programları arasındaki bağın, 00000H-003FFH arasındaki 256 gözlük kesme vektör tablosuyla kurulduğu; gözlerde alt programın değil adresinin (düşükte ofset, yüksekte segment) saklandığı vurgulandı. Kesme geldiğinde işlemcinin bayrakları, CS'yi ve IP'yi kendiliğinden yığına attığı ve tablodan yeni CS:IP'yi yüklediği gösterildi.

Örnekte tip 0 gözü yedeklenip yerine kendi NEWINT alt programımız yazıldı, program sonunda özgün değerler geri yüklendi. NEWINT, BP ile sabit referans kurarak yığındaki dönüş ofsetini bölme komutunun boyu kadar ilerletti ve AX'te FFFFH döndürdü. DOSBox'taki debug izlemesi, yığının kesme anındaki içeriğini ve dönüş adresinin nasıl değiştirildiğini adım adım gösterdi. Hoca kesme konusunun kapsamının bu dersle tamamlandığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
