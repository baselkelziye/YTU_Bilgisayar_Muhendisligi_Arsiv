# Ders 8 Çalışma Özeti

## Genel Konular

- 8255 mod 0 örneği: 4 düğme ve 4 LED aynı portta (port C)
  - 8255, 60H'den başlayan ardışık çift adreslere yerleştirilmiştir (önceki dersin adres çözümleme devresi): 60H port A, 62H port B, 64H port C, 66H kontrol yazmacı. İşlemcinin A1'i 8255'in A0'ına, A2'si 8255'in A1'ine bağlıdır; veri uçları D0-D7 (benzetimde AD0-AD7) üzerindedir, RESET toprağa çekilmiştir (ekrandan, 00:05:00).
  - Düğmeler PC0-PC3'e bağlıdır ve pull-up dirençle 5 V'a çekilmiştir: basılmayan düğme lojik 1, basılan düğme lojik 0 okunur. LED'lerin anotu PC4-PC7'ye, katotu toprağa bağlıdır: LED'i yakmak için ilgili uca lojik 1 yazılır (ekrandan, 00:05:00 ve 00:25:00).
  - İstenen davranış: başta bütün LED'ler yanar; hangi sıradaki düğmeye basılırsa o sıradaki LED söner, diğerleri yanık kalır.
  - El sıkışma gerektirmeyen basit paralel veri aktarımı olduğu için mod 0 seçilir. Port C'nin alt yarısı giriş, üst yarısı çıkış olmalıdır; port A ve port B önemsizdir (X).
  - Kontrol sözcüğü: D7 = 1, grup A mod 0 (00), PA = X, PCH çıkış (0), grup B mod 0 (0), PB = X, PCL giriş (1). X'ler 0 alınırsa $1000\,0001_2 = 81H$ olur ve 66H adresine yazılır (ekrandan, 00:10:00).
- Kontrol sözcüğünü yazan kod
  - Isolated I/O kullanıldığı için (M/$\overline{IO}$ adres çözümlemeye girer) G/Ç cihazı yalnız `IN`/`OUT` ile seçilir; `MOV` bellek işlemi yapar ve cihazı seçmez.
  - 8255 yalnız 8 bitlik veri yoluna bağlı olduğu için `AL` kullanılır. 66H 8 bite sığdığı için sabit adres (p8) biçimi kullanılır; 8 bite sığmayan adreslerde `DX` gerekirdi.
  - `MOV AL, 81H` ve `OUT 66H, AL` (ekrandan, 00:15:00). Hoca her satıra noktalı virgülle açıklama yazılmasını ister (ör. "PCL giriş, PCH çıkış, grup A ve B mod 0").
- Programın tamamı ve maskeleme (ekrandan, 00:20:00 ve 00:30:00)
  - `MOV AL, 0FFH / OUT 64H, AL` port C'ye FFH yazar: üst yarıdaki dört LED yanar; giriş olarak ayarlanan alt yarıya yazılan 1'lerin etkisi yoktur.
  - Döngü: `IN AL, 64H` port C'nin 8 bitini birden okur. Üst 4 bit çıkış olduğu için anlamsızdır ve maskelenir.
  - İki maskeleme seçeneği: `AND AL, 0FH` (üst 4 bit 0 olur, tuş yokken sonuç 0FH) veya `OR AL, 0F0H` (üst 4 bit 1 olur, tuş yokken sonuç FFH). Sonuç daha sonra kaydırılıp doğrudan kullanılacağı için `OR` tercih edilir.
  - `CMP AL, 0FFH / JZ ENDLESS`: tuşa basılmadıkça döngü sürer. Basıldığında AL değeri B3 için F7H, B2 için FBH, B1 için FDH, B0 için FEH olur.
  - `MOV CL, 4 / SHL AL, CL / OUT 64H, AL`: düğme bitleri dört bit sola kaydırılıp LED bitlerine taşınır ve port C'ye yazılır; örneğin FEH kaydırılınca E0H olur ve PC4'teki LED söner. Birden fazla kaydırmada sayı `CL` ile verilir, tek kaydırmada 1 doğrudan yazılabilir.
- Proteus'ta COM tipi programın hata ayıklaması
  - Duraklatma ile başlatılıp adım adım yürütülür; 8086 yazmaç penceresi ve 8255 iç durum penceresi açılabilir. 81H yazılınca 8255 penceresi grup A ve B'yi mod 0, PCH'yi çıkış, PCL'yi giriş gösterir; X yerine yazılan 0'lar yüzünden PA ve PB çıkış görünür.
  - Kesme noktası satıra çift tıklanarak konur. Hoca, Proteus'un eski sürümlerinde EXE tipi programlarda hata ayıklamanın çalışmadığını, COM tipinin bu yüzden daha rahat olduğunu söyler.
- 7 parçalı gösterge (7-segment display)
  - İçinde 8 LED vardır: a-g yedi parça ve nokta (h). 0-F onaltılık rakamlarını ve ondalık noktayı gösterebilir. 9 ucu vardır: bir ortak uç ve a-h veri uçları (ekrandan, 00:45:00).
  - Ortak uç LED'lerin katotlarıysa ortak katotlu (OK), anotlarıysa ortak anotlu (OA) göstergedir.
  - Ortak anotluda: ortak uç 0 ise hiçbir LED yanmaz (hepsini söndürmenin kısa yolu); yakmak için ortak uç 1, yanacak parçanın ucu 0 olmalıdır.
  - Ortak katotluda: ortak uç 0, yanacak parçanın ucu 1 olmalıdır.
  - Aynı rakamı öteki tip göstergede göstermek için ortak uç dahil bütün değerlerin bire tümleyeni alınır. Ortak anotluya ortak katotlu verisi gönderilirse rakam "sönük" (tersi) görünür.
- Tek ortak anotlu göstergede 0 yakma (ekrandan, 00:50:00 ve 00:55:00)
  - Gösterge port B'ye bağlıdır: a = PB0, ..., h = PB7. Port B mod 0 çıkış olmalıdır.
  - 0 için a-f yanar (0), g ve h söner (1): $hgfedcba = 1100\,0000_2 = C0H$. Tersi 3FH gönderilirse yalnız g ve h yanar.
  - Kontrol sözcüğü: D7 = 1, D2 = 0 (grup B mod 0), D1 = 0 (PB çıkış), geri kalanı X: X'ler 0 alınırsa 80H.
  - Kod EXE tipidir: STAK, DATA, CODE segmentleri; `DIGITS DB 0C0H`; `MOV AX, DATA / MOV DS, AX` ile veri segmenti ayarlanır (segment yazmacına doğrudan sabit atanamaz); `MOV AL, 80H / OUT 66H, AL`; `OUT 62H` ile önce FFH (söndür), sonra `MOV AL, DIGITS / OUT 62H, AL` ile C0H gönderilir. Program `END START` ile başlangıç etiketini belirtir.
- Dört göstergenin çoğullanarak (tarama ile) sürülmesi (ekrandan, 01:05:00 ve 01:10:00)
  - Dört ortak anotlu göstergenin a-h uçları ortak olarak port B'ye, ortak anot uçları PC0-PC3'e bağlıdır.
  - Algoritma: yalnız bir göstergeyi etkinleştir (ortak anot 1, diğerleri 0), o basamağın verisini port B'den gönder, bekle, hepsini kapat, sıradaki basamağa geç. Tarama 25 Hz'in üstünde olursa göz bütün basamakları aynı anda yanıyor görür.
  - Uç tasarrufu: çoğullama ile 4 basamak için 8 + 4 = 12 uç yeter; 100 basamak için 108 uç, ayrı ayrı sürülseydi 800 uç gerekirdi.
  - Tüm portları mod 0 çıkış yapan kontrol sözcüğü 80H'dir. Örnek kodda PB'ye FFH ve PC'ye FFH yazılır (bütün göstergeler etkin, bütün parçalar sönük), sonra `DIGITS` dizisinden bir eleman port B'ye gönderilir; hepsi etkin olduğu için dört göstergede aynı rakam görünür.
- Matris tuş takımı (keypad) tarama mantığı (ekrandan, 01:15:00)
  - 4 satır × 3 sütun = 12 tuş 7 uçla okunur; 10 × 10'luk takımda 20 uç yeterken ayrı ayrı bağlantıda 100 uç gerekir.
  - Basılan tuş, satır ve sütun hattını kısa devre eder. Aynı anda tek tuşa basıldığı varsayılır (aksi durumda diyot gibi koruma gerekir).
  - Satırlar pull-up ile okunuyorsa: tuş yokken satırlar 1'dir; sütunlar 1 ile sürülürse değişim görülmez; hepsi 0 ile sürülürse yalnız satır anlaşılır. Bu yüzden her seferinde tek sütun 0 yapılır (etkin sütun) ve sırayla döndürülür.
  - Satırlar pull-down ile okunuyorsa: tuş yokken satırlar 0'dır; etkin sütun 1 ile sürülür.
  - Sürülen sütunlar 8255 açısından çıkış, okunan satırlar giriş olmalıdır. Hangisinin "satır" sayılacağını direncin bağlı olduğu taraf belirler: pull-up/pull-down tarafı giriştir.
- Tuş takımı örneği (ekrandan, 01:25:00 ve 01:30:00)
  - Sütunlar PA0-PA2'den sürülür, pull-up'lı satırlar PC0-PC3'ten okunur. Port A mod 0 çıkış, port C alt yarısı mod 0 giriş: kontrol sözcüğü yine 81H.
  - Örnek kod port A'ya FDH ($1111\,1101_2$) yazarak yalnız 2. sütunu etkinleştirir, `IN AL, 64H` ile satırları okur ve 2. satır bitini (02H) denetler. Yani yalnız 5 tuşuna basılıp basılmadığını anlayan, tamamlanmamış bir örnektir. <!-- BELİRSİZ: Karşılaştırma komutu karede görünmüyor; altyazıda hem "2H ile karşılaştırıyoruz" hem "0.2 ile test" geçiyor (büyük olasılıkla TEST AL, 02H). -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Mod seçiminin gerekçesi
  - Doğrudan "mod 0" demek yetmez: veri aktarımında denetim ya da el sıkışma gerekmiyorsa mod 0 anlamlıdır.
- Port C'nin yarıları ayrı yönlere ayarlanabilir ama okuma ve yazma 8 bittir
  - Bu yüzden okunan değerin anlamsız yarısı maskelenmelidir; çıkış ucuna yazılan değer anlam taşır, giriş ucuna yazılan değerin karşılığı yoktur.
- Maskeleme
  - İlgilenilen bitler korunur, ilgilenilmeyen bitler önceden seçilen bir değere zorlanır: `AND` ile 0'a, `OR` ile 1'e.
- Kodda açıklama
  - Her satıra noktalı virgülle ne yaptığı yazılmalıdır; okunabilirlik ve değerlendirme açısından önemlidir.
- Isolated I/O varsayımı
  - Aksi belirtilmedikçe isolated I/O kullanılır, bu yüzden 8255'e `IN`/`OUT` ile erişilir; `MOV` ile erişilmez.
- 7 parçalı göstergeyi anlamak için
  - LED'in nasıl yandığı, anot ve katodun hangi taraf olduğu bilinmelidir. Rakam sönük (ters) görünüyorsa yanlış ortak uç tipine göre veri gönderilmiştir.
- Örnekleri indirip çalıştırmak, değiştirmek ve sıfırdan yazmaya çalışmak önerilir.

## Kısa Tekrar Notları

- 60H'den ardışık çift adres: PA 60H, PB 62H, PC 64H, kontrol 66H.
- Kontrol sözcüğü (mod ayarı): D7 = 1; D6-D5 grup A modu; D4 PA; D3 PCH; D2 grup B modu; D1 PB; D0 PCL. Yön biti 1 = giriş, 0 = çıkış.
- PCL giriş + PCH çıkış, ikisi mod 0: 81H. PB çıkış mod 0 (gerisi X): 80H. Bütün portlar mod 0 çıkış: 80H. PA çıkış + PCL giriş: 81H.
- Pull-up'lı düğme: basılmamış 1, basılmış 0. Anotu porta bağlı LED: 1 yazınca yanar.
- `OR AL, 0F0H` sonrası tuş yoksa FFH; basılı tuş F7H/FBH/FDH/FEH verir.
- `SHL AL, CL` ile birden fazla bit kaydırılır; sayı önce `CL`'ye konur.
- Ortak anot: ortak uç 1, yanan parça 0. Ortak katot: ortak uç 0, yanan parça 1.
- Ortak anotlu göstergede 0: C0H (a = bit 0, h = bit 7).
- Çoğullama: tek gösterge etkin, veri gönder, bekle, sıradakine geç; 25 Hz üstü tarama.
- Tuş takımı: sütun çıkış, satır giriş; pull-up'ta etkin sütun 0, pull-down'da 1; tek sütun sırayla etkinleştirilir.
- EXE tipinde `MOV AX, DATA / MOV DS, AX` gerekir; başlangıç etiketi `END` sonrasında verilir.

## Detaylı Açıklamalar

- LED-düğme örneğinde kontrol sözcüğü bit bit kurulur. D7 mod ayarı yapıldığı için 1'dir. Port C'nin üst yarısı grup A'ya, alt yarısı grup B'ye ait olduğu için iki grup da mod 0'a alınır (D6-D5 = 00, D2 = 0). LED'ler PCH'de olduğu için D3 = 0 (çıkış), düğmeler PCL'de olduğu için D0 = 1 (giriş). Port A ve B kullanılmadığı için D4 ve D1 önemsizdir; 0 alınınca değer 81H olur. Bu değer 8255'in A1 = A0 = 1 olduğu adrese, yani 66H'ye `OUT` ile yazılır. `OUT`'un veri parametresi `AL` ya da `AX` olabilir; 8255 yalnız D0-D7'ye bağlı olduğu için `AL` kullanılır ve değer önce `MOV AL, 81H` ile hazırlanır (ekrandan, 00:10:00 ve 00:15:00).
- Benzetimdeki tam kod (ekrandan, 00:30:00):

  ```text
  START:
          MOV AL, 81H
          OUT 66H, AL
          MOV AL, 0FFH
          out 64H, AL
  ENDLESS:
          IN  AL, 64H
          OR  AL, 0F0H
          CMP AL, 0FFH
          JZ  ENDLESS
          MOV CL, 4
          SHL AL, CL
          OUT 64H, AL
          JMP ENDLESS
  ```

  Başta port C'ye FFH yazılarak dört LED yakılır. Döngüde port C okunur, üst yarı `OR` ile 1'e zorlanır. Hiç tuşa basılmamışsa alt yarı da 1'dir ve AL = FFH olduğu için `JZ` başa döner. Bir tuşa basılınca ilgili bit 0 olur; değer dört bit sola kaydırılınca o 0 LED bitine taşınır. Örneğin B0'a basılınca AL = FEH, kaydırınca E0H olur ve PC4'teki LED söner; B3'e basılınca F7H, kaydırınca 70H olur ve PC7'deki LED söner. Kaydırma sonucu alt yarıya gelen 0'lar giriş uçlarına yazıldığı için etkisizdir. Tuş bırakılınca AL yeniden FFH olur ve port C'ye yazma yapılmadığı için son durum korunur.
- Ders sonrası not: hoca `MOV AL, 81H` komutunu anlatırken AL'yi "source", 81H'yi "destination" diye adlandırdı. Doğrusu tersidir: Intel sözdiziminde ilk işlenen (AL) hedef (destination), ikinci işlenen (81H) kaynaktır (source). Benzer biçimde iki işlenenin ikisi birden bellek (köşeli parantez) olamaz.
- 7 parçalı göstergede hoca, LED sembollerini çizerek a (üst), b, c, d, e, f, g (orta) ve h (nokta) parçalarını adlandırdı. Bütün anotlar birleştirilip dışarı tek uç olarak çıkarılırsa ortak anotlu, bütün katotlar birleştirilirse ortak katotlu gösterge elde edilir; kalan uçlar veri ucu olarak dışarı çıkar (ekrandan, 00:45:00).
- Tek göstergede 0 yakmak için port B'ye C0H gönderilir: h ve g 1 (sönük), f-a 0 (yanık). Ortak katotlu göstergede aynı rakam bunun bire tümleyeni 3FH ile ve ortak uç 0 yapılarak gösterilir (python ile doğrulandı).
- EXE tipi örnek kod (ekrandan, 00:55:00):

  ```text
  STAK    SEGMENT PARA STACK 'STACK'
          DW 20 DUP(?)
  STAK    ENDS
  DATA    SEGMENT PARA 'DATA'
  DIGITS  DB 0C0H
  DATA    ENDS
  CODE    SEGMENT PARA 'CODE'
          ASSUME CS:CODE, DS:DATA, SS:STAK
  START:
          MOV AX, DATA
          MOV DS, AX
          MOV AL, 80H
          OUT 66H, AL
          MOV AL, 0FFH
          OUT 62H, AL
          MOV AL, 0FFH
          OUT 64H, AL
          MOV AL, DIGITS
          OUT 62H, AL
  ENDLESS:
          JMP ENDLESS
  CODE    ENDS
          END START
  ```

  Yığın segmenti fonksiyon çağrıları ve dönüşler için ayrılır ve çift sayıda baytlık olmalıdır. Port C'ye FFH yazılması bu örnekte bir işe yaramaz; port C'ye bir şey bağlı değildir. Hoca aynı kodun COM tipi de yazılabileceğini, iki örnek olsun diye birini COM birini EXE verdiğini söyler.
- Ders sonrası not: hoca dört basamağı ayrı portlardan sürme seçeneğinde "port A, B, C, D" dedi ve gereken veri ucu sayısını "4 × 4 = 16" olarak verdi. Her basamak 8 veri ucu istediği için doğrusu $4 \times 8 = 32$ uçtur (hocanın 100 basamak için verdiği $100 \times 8 = 800$ hesabıyla da tutarlı). Ayrıca tek bir 8255'te yalnız üç port (A, B, C) vardır; dört port için büyük olasılıkla ikinci bir çevre birimi gerekir.
- Tuş takımında tarama çok hızlı yapıldığı için (bin mertebesinde frekans) tuş basılı kaldığı sürede etkin sütun mutlaka o tuşun sütununa denk gelir. Örneğin pull-up'lı takımda 2. sütun 0 iken 2. satır 0 okunursa basılan tuş 5'tir; 1. sütun etkinken 4. satır 0 okunursa yıldız (*) tuşudur. Pull-down'lı takımda 2. sütun 1 iken 3. satır 1 okunursa tuş 8'dir.
- Tuş takımı örneğinde port A'ya yazılan FDH yalnız PA1'i, yani 2. sütunu 0 yapar (ekrandan, 01:30:00). Hoca örneğin yalnız 5 tuşunu algıladığını, tam çözüm için her sütunun sırayla etkinleştirilip satırların 1, 2, 4, 8 değerleriyle karşılaştırılması ve satır-sütun bilgisinden tuşun bulunması gerektiğini söyler.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
