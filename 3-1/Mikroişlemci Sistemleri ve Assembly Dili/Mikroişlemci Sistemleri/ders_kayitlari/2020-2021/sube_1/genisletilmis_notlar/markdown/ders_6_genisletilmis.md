# Ders 6 Genişletilmiş Notu: Basit G/Ç Birimleri için Adres Çözümleme, 8255 PPI ve 3×8 Kod Çözücü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Adres çözümleme devresinin görevi
- 2. Basit çıkış birimi: 0F000H adresinde 8 LED
- 3. Basit giriş birimi: 0F000H adresinde 8 düğme
- 4. Basit G/Ç birimleri üzerine üç soru
- 5. Programlanabilir G/Ç cihazları ve 8255 PPI
- 6. 8255'in G/Ç uzayında kapladığı yer ve bağlantıları
- 7. 8255'in yazmaçları, iç yapısı ve modları
- 8. 16 bitlik veri yolunda 8 bitlik çevre birimi
- 9. Örnek: F8H'den itibaren ardışık çift adreslerde 8255
- 10. 3×8 kod çözücü
- 11. Laboratuvarla bağlantı ve örnek uygulama
- Örnek Sorular

## 1. Adres çözümleme devresinin görevi

Önceki derste düğme ve LED'lerle basit giriş-çıkış birimlerinin nasıl kurulabileceği konuşulmuştu. Bu ders, bu birimlerin işlemciye nasıl "adreslendiği" sorusuyla, yani adres çözümleme kavramıyla başlar. Plan şudur: önce kendi tasarladığımız basit bir çıkış ve bir giriş birimi, sonra bunların kontrolüne dair birkaç soru, ardından 8255 programlanabilir paralel arayüz cihazı.

Bir mikroişlemci sisteminin çalışması için işlemcinin yanında yardımcı devreler, çevre birimleri ve hafıza birimleri bulunur. Bunların hepsi aynı veri, adres ve kontrol yollarını kullanır. Adres ve kontrol yolu açısından bu bir sorun değildir; ama iki çevre birimi aynı anda veri yoluna değer çıkarmaya çalışırsa çakışma olur.

Çözüm şudur: sistemdeki bütün hafıza ve çevre birimleri belirli adres aralıklarına yerleştirilir. Bu aralıklar cihazların kapasitesiyle doğru orantılıdır ve kapasiteye göre hizalıdır. Hoca hizalı yerleştirmeyi şöyle açıkladı:

- 1 MB'lık tek bir hafıza birimi 20 bitlik 0 adresinden başlar ve bütün uzayı kaplar.
- 512 KB'lık bir cihaz ya 0 adresinden ya da 512K (80000H) adresinden başlar.
- 256 KB'lık bir cihaz dört farklı noktadan birine (0, 40000H, 80000H, C0000H) yerleştirilebilir (ara adım eklendi).

> **Ders sonrası not:** Hoca 00:03:44'te "356 kilobaytlık bir cihaz" dedi; dört hizalı nokta 256 KB için geçerlidir ($2^{20} / 2^{18} = 4$). Büyük olasılıkla bir söyleme ya da Whisper hatasıdır.

Cihazların adres aralıkları bilindiğine göre, yürütülen komut hangi adresle ilgiliyse ve bu adres hangi cihazın aralığına düşüyorsa yalnız o cihaz için chip select (chip enable) işareti üreten, diğer bütün cihazları devre dışı bırakan bir ara birime ihtiyaç vardır. Bu, **adres çözümleme devresidir**. Bir cihazı seçmemek, onun veri uçlarını yüksek empedansta bırakmak demektir; bu da cihazı hattan koparmak gibi bir etki yapar. Böylece her an işlemciyle yalnız bir cihaz veri yolu üzerinden konuşur.

Adres çözümleme devresini bir kara kutu olarak düşünürsek:

- Girişleri: belirli adres uçları ve kontrol işaretleri ($\overline{BHE}$, $\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$ gibi).
- Çıkışları: sistemdeki hafıza ve çevre birimi sayısı kadar. Verilen adrese göre ya hiçbiri seçilmez (işlem hafıza ya da G/Ç işlemi değilse) ya da yalnız biri seçilir.

Hoca tahtada işlemciyi, kontrol, veri ve adres yollarını, bunlara bağlı hafıza cihazlarını ve adres yolundan ile kontrol yolundan beslenen çözümleme devresini çizdi. Çözümleme devresinin çıkışları cihazların chip select uçlarına gider. Adres yolu 20 bittir (A0–A19). Kapasitesi $2^{i+1}$ göz olan bir cihazda A0–Ai uçları cihazın içindeki gözleri seçmek için cihaza gider; geri kalan uçlar çözümleme devresine gider. Slaytta bu kural şöyle özetlenir (ekrandan, 00:05:00):

- Hafıza: A19–A(i+1)
- Değişken adresli G/Ç (Variable I/O): A15–A(i+1)
- Sabit adresli G/Ç (Fixed I/O): A7–A(i+1)

Bu uçlar adres çözümleme devresine gitmelidir. G/Ç cihazında adres 16 bitle ifade ediliyorsa (DX ile) A15'e kadar, 8 bitlik sabit adres kullanılıyorsa A7'ye kadar olan uçlar çözümlemeye girer.

## 2. Basit çıkış birimi: 0F000H adresinde 8 LED

### 2.1 Soru

Slayttaki soru şudur (ekrandan, 00:10:00): "8 LED kullanarak 0F000H adresine yerleştirilmiş basit bir çıkış biriminin tasarlanması → donanım + adres çözümleme. LED'lerde (on, off, on, off…) şeklinde patern oluşturma → I/O programlama."

Sistemde yalnız 8086 ve bizim tasarlayacağımız çıkış birimi vardır. Hoca önce "20 bitlik adres uzayı" dedi, sonra bunun bir G/Ç birimi olduğu için adresin 16 bit olduğunu düzeltti. Birim yalnız bu adrese yapılan **çıkış** işlemlerinde seçilmeli, bu adresten giriş yapıldığında bile seçilmemelidir.

### 2.2 Donanım: 74245 ile çıkış birimi

Tasarımda 74245 entegresi kullanılır. Hatırlatma olarak 74245, 8086'da veri yolunu ayırıp tutmak için kullanılan çift yönlü alıcı-vericidir (bidirectional transceiver):

- $\overline{E}$ ucuna 1 gelirse A yolu ile B yolu birbirinden ayrılır.
- $\overline{E}$ ucuna 0 gelirse DIR ucu anlam kazanır: DIR = 0 ise B tarafı A tarafına, DIR = 1 ise A tarafı B tarafına aktarılır.

Çıkış cihazı olduğu için DIR ucu sabit 5 V'a (lojik 1) bağlanır. Böylece işlemcinin veri uçlarına çıkardığı değer dış dünyada LED'leri yakar. Slayttaki devrede (ekrandan, 00:15:00) 8086'nın D7 ucu 74245'in A0 ucuna, D6 ucu A1'e, …, D0 ucu A7'ye bağlıdır; B0–B7 uçlarına birer LED ve direnç üzerinden toprak bağlıdır. $\overline{E}$ ucu adres çözümleme devresinin (büyük bir NAND kapısı) çıkışına bağlıdır.

> **Hocanın vurgusu:** 74245'in A ve B uçları yalnız entegrenin içinden tanımlı adlardır; işlemcinin adres ve veri uçlarıyla karıştırılmamalıdır. $\overline{E}$ ucuna AX yazmacı bağlanmamıştır, adres çözümleme devresinin çıkışı bağlanmıştır.

Bu derste, işlemcinin adres ve veri uçlarının uygun biçimde ayrıştırılmış ve tutulmuş olduğu varsayılır.

### 2.3 LED deseni için veri değeri

Bir LED'i yakmak için ilgili B ucunda 5 V, yani lojik 1 üretmek gerekir. İstenen "sönük, yanık, sönük, yanık…" desenidir. Slayttaki atamada B0 = 0, B1 = 1, B2 = 0, B3 = 1, B4 = 0, B5 = 1, B6 = 0, B7 = 1'dir (ekrandan, 00:15:00). B uçlarında bu değerlerin oluşması için A uçlarında da aynı değerler bulunmalıdır. A0'a D7, A7'ye D0 bağlı olduğu için:

$$D7\,D6\,D5\,D4\,D3\,D2\,D1\,D0 = 0101\;0101_2 = 55\text{H}$$

İşlemci veri uçlarına 55H çıkarır ve 74245 seçilirse (DIR = 5 V olduğundan A → B), istenen desen oluşur.

### 2.4 Adres çözümleme koşulu

Birimin seçilmesi için gereken koşullar (ekrandan, 00:20:00):

- Adres uçları: F000H = 1111 0000 0000 0000B, yani A15 = A14 = A13 = A12 = 1, A11 … A0 = 0. Hoca önce A19 yazdı, sonra G/Ç cihazlarında en fazla A15'e kadar gidildiğini söyleyerek A15 olarak düzeltti.
- M/$\overline{IO}$ = 0 (G/Ç işlemi).
- $\overline{WR}$ = 0 (çıkış işlemi).

Bu koşulların hepsi sağlandığında çözümleme devresi lojik 0 üretmeli, herhangi biri bozulduğunda lojik 1 üretmelidir. Örneğin aynı adresle `IN AL, DX` yapılırsa $\overline{RD}$ = 0 ve $\overline{WR}$ = 1 olur ve cihaz seçilmemelidir; ayrım $\overline{WR}$ üzerinden yapılır.

Slayttaki devre büyük bir NAND kapısıdır (ekrandan, 00:15:00). A15–A12 girişleri doğrudan, A11–A0 girişleri birer tersleyici (yuvarlak) üzerinden, $\overline{WR}$+M/$\overline{IO}$ işareti de bir tersleyici üzerinden girer. Hoca iki yuvarlağın farkını belirtti: $\overline{E}$ ucundaki yuvarlak $\overline{E}$'ye dahildir ve aktif 0 olduğunu gösterir; kapının çıkışındaki yuvarlak ise NAND'ı oluşturan DEĞİL işlemidir.

Hoca devreyi deneme değerleriyle inceledi (ekrandan, 00:25:00):

- Adres 7000H olursa: F000H ile 7000H arasındaki tek fark A15'tir; A15 = 0 gelir. Kapı A15 açısından bir VE kapısı gibi çalışır; bir girişi 0 olan VE kapısının çıkışı 0'dır, DEĞİL'den geçince 1 olur. $\overline{E}$ = 1 olduğundan cihaz seçilmez.
- Adres F001H olursa: A0 = 1 gelir, girişteki tersleyiciden geçince 0 olur, VE çıkışı 0, NAND çıkışı 1 olur; cihaz yine seçilmez.

Sonra M/$\overline{IO}$ ve $\overline{WR}$ için aranan işlev soruldu: iki giriş de 0 olduğunda 0, herhangi biri 1 olduğunda 1 üreten kapı. Bu **OR kapısıdır**; slayttaki "+" işareti bu yüzden kullanılmıştır. OR çıkışı 0 ise tersleyiciden geçip 1 olarak NAND'a girer ve sorun yoktur. OR çıkışı 1 olursa tersleyiciden geçip 0 olur, VE çıkışı 0, NAND çıkışı 1 olur ve cihaz seçilmez.

Sonuç: Bu cihaz yalnız F000H adresine `OUT` yapıldığında çalışır. Aynı adresten `IN` yapılırsa, 7000H'ye `OUT` yapılırsa ya da F001H'ye `OUT` yapılırsa çalışmaz.

### 2.5 Program

Bir öğrencinin hatırlattığı gibi adres 8 bite sığmadığı için değişken adresleme, yani DX yazmacı kullanılır: adres DX'te, veri AL'de olur. Kod (ekrandan, 00:15:00):

```asm
    mov al, 55h
    mov dx, 0F000h
    out dx, al
```

`OUT DX, AL` çalıştığında işlemci M/$\overline{IO}$ ucunda 0, $\overline{WR}$ ucunda 0 üretir; adres uçlarında A15–A12 = 1, diğerleri 0 olur. Aranan koşul sağlandığı için NAND çıkışı 0 olur ve 74245 seçilir. Veri uçlarındaki 01010101 değeri, DIR ucunda 5 V olduğu için B tarafına kopyalanır; LED uçlarında 0 V, 5 V, 0 V, 5 V, … oluşur ve sönük-yanık deseni elde edilir.

## 3. Basit giriş birimi: 0F000H adresinde 8 düğme

### 3.1 Soru ve çözümleme koşulu

Öncekinden bağımsız ikinci soru: 8 düğme kullanarak (yani 8 bitlik) bir giriş birimi tasarlanacak ve 0F000H adresine yerleştirilecek. Cihazın donanımı ve adres çözümlemesi yapılacak, basılan tuş değerini okuyan bir G/Ç programı yazılacak.

Cihaz yalnız F000H adresinden yapılan okumalarda seçilmelidir. Koşullar (ekrandan, 00:35:00):

- A15 = A14 = A13 = A12 = 1, A11 … A0 = 0.
- $\overline{RD}$ = 0 (`IN` komutu; bu sırada $\overline{WR}$ = 1 olduğu için yalnız $\overline{RD}$'yi denetlemek yeterlidir).
- M/$\overline{IO}$ = 0.

Hoca tahtaya önce "A11 = 1" yazdı; bir öğrencinin uyarısıyla bunun 0 olması gerektiğini söyleyip düzeltti ve öğrenciye teşekkür etti (derste düzeltme, 00:37:53). F000H = 1111 0000 0000 0000B olduğundan yalnız A15–A12 birdir.

Çözümleme devresi çıkış birimindekiyle aynıdır; tek fark $\overline{WR}$ yerine $\overline{RD}$ işaretinin kullanılmasıdır (slaytta $\overline{RD}$+M/$\overline{IO}$, ekrandan 00:30:00).

### 3.2 Donanım: pull-up dirençli düğmeler

Yine 74245 kullanılır; ama bu sefer dış dünyadan veri okunacağı için B tarafı A tarafına aktarılmalıdır. Bu yüzden DIR ucu toprağa (0) bağlanır. Cihaz seçildiğinde düğme değerleri işlemcinin veri uçlarında oluşur ve `IN` komutu bunları okur.

Düğmeler pull-up dirençlerle sürülür (ekrandan, 00:30:00). Birinci düğmeye bakalım:

- Tuşa basılmadığında devre açıktır. B0 ucu direnç üzerinden 5 V'a bağlıdır; uçtan içeri akım akmadığı (kaçak akım olmadığı) varsayılırsa B0'da lojik 1 görülür.
- Tuşa basıldığında yol tamamlanır, B0 doğrudan toprağa bağlanır ve lojik 0 görülür. 5 V ile 0 V arasındaki gerilim farkı direnç üzerinde harcanır, kısa devre olmaz.

Hiçbir tuşa basılmazsa bütün uçlar lojik 1 olur, `IN` komutu FFH okur (ekrandan, 00:35:00).

### 3.3 Program

Herhangi bir tuşa basılıp basılmadığını anlamak için okunan değerin FFH'den farklı olup olmadığına bakılır. Kod (ekrandan, 00:30:00):

```asm
        mov dx, 0F000h
    L1: in  al, dx
        cmp al, 0FFh
        je  L1
```

`MOV DX, 0F000H` ile adres DX'e yazılır. `IN AL, DX` bu adresi adres yoluna çıkarır, çözümleme devresi cihazı seçer, düğme değerleri veri uçlarından AL'ye okunur. `CMP` iki işleneni birbirinden çıkarıp yalnız bayrakları değiştirir, hiçbir yazmacı etkilemez. AL = FFH ise hiçbir tuşa basılmamıştır; `JE L1` ile tekrar okunur. Böylece tuşa basılmadığı sürece sonsuz döngüde beklenir. Bir tuşa basıldıktan sonra AL'nin bitleri ayrı ayrı denetlenerek hangi tuşa (ya da tuşlara) basıldığı bulunabilir.

> **Ders sonrası not:** Hoca 00:34:45'te adresin "16 bite sığdığından dolayı" DX ile aktarıldığını söyledi; doğrusu, adres 8 bite sığmadığı için DX kullanılır (hoca 00:35:32'de de böyle söyledi).

> **Ders sonrası not:** Hoca 00:36:29'da AL'nin 1, 2, 4, 8, 16, 32 ve 64 gibi değerlerle karşılaştırılabileceğini söyledi. 8 bitte bu diziye 128 (D7) de eklenmelidir. Ayrıca bu devrede basılı tuş 0 okunduğu için tek tuşa basıldığında AL, FFH'nin yalnız ilgili biti 0 olan değeridir (örneğin D0 tuşu için FEH, D1 tuşu için FDH). Bu yüzden doğrudan 1, 2, 4, … ile eşitlik karşılaştırması değil, bit bit maskeleme (örneğin `TEST`) gerekir.

## 4. Basit G/Ç birimleri üzerine üç soru

Hoca önce çift adres durumunu hatırlattı: devrede birimler veri yolunun düşük anlamlı baytına bağlanmıştır ve adres çifttir. Bu durumda A0 (düşük bayt etkinleştirme gibi davranır) 0, $\overline{BHE}$ ise 1 olur. Ardından slayttaki üç soru tartışıldı (ekrandan, 00:40:00).

### 4.1 Aynı adreste giriş ve çıkış birimi

**Soru:** F000H adresine bir giriş birimi ve bir çıkış birimi aynı anda yerleştirilirse sorun çıkar mı?

**Cevap:** Çıkmaz. Çıkış birimi yalnız F000H'ye yapılan `OUT` komutlarında, giriş birimi yalnız F000H'den yapılan `IN` komutlarında seçilir; çözümleme devreleri $\overline{WR}$ ve $\overline{RD}$ ile ayrışır. İki birimin veri uçları aynı D7–D0 hatlarına bağlanabilir. Çıkış birimine `OUT`, giriş birimine `IN` ile erişilir ve birbirleriyle karışmazlar.

### 4.2 Birimi 0F001H adresine taşımak

**Soru:** Basit giriş (ya da çıkış) birimini 0F001H adresine yerleştirmek için ne yapılmalıdır?

**Cevap:** Bir öğrencinin söylediği gibi, tek adresten 8 bitlik işlemde işlemci veriyi D8–D15 arasında bekler (ya da oraya koyar). Bu yüzden:

- Cihazın veri uçları D8–D15'e bağlanır (D15 en üst, D8 en alt uca).
- Çözümleme A0 = 1 iken seçim yapacak şekilde değiştirilir: ya A0 girişindeki tersleyici kaldırılır, ya da A0 çözümlemeden çıkarılıp yerine $\overline{BHE}$ (0 iken etkin) bağlanır. İki seçenek de aynı işi görür.

Hoca bu ikinci adımı önce atladığını fark edip sonra ekledi.

### 4.3 16 bitlik basit çıkış birimi

**Soru:** 0F000H adresinden itibaren 16 bitlik bir basit çıkış birimi nasıl tasarlanır?

**Cevap:** Böyle bir birim F000H ve F001H adreslerini aynı anda seçebilmelidir. Bir öğrencinin de söylediği gibi iki adet 74245 gerekir:

- Birinci 74245 D0–D7'ye bağlanır.
- İkinci 74245 D8–D15'e bağlanır.
- 16 bitlik işlemde çift adresten erişimde işlemci A0 = 0 ve $\overline{BHE}$ = 0 üretir. İki cihazın aynı anda seçilmesi için çözümleme devresinden A0 çıkarılır ve aynı çıkış iki cihaza da verilir. Diğer seçenek: çift adresteki cihaz için A0 bırakılır, tek adresteki cihaz için A0 yerine $\overline{BHE}$ kullanılır.
- Aktarım AL yerine AX ile yapılır.

> **Ders sonrası not:** Hoca "okumayı AL'den değil AX'den yapacağız" dedi; bu bir çıkış birimi olduğu için kastedilen, yazmanın `OUT DX, AX` ile yapılmasıdır.

Slaytlardaki sonraki konu (polling) ileride sık sık tekrar edileceği için bu derste atlandı.

## 5. Programlanabilir G/Ç cihazları ve 8255 PPI

Bir G/Ç cihazının **programlanabilir** olması şu demektir: cihazın içinde ayar yazmaçları vardır; yazılımla bu yazmaçlara değer gönderildiğinde cihazın işlevi değişir. Cihaz standarttır, ama davranışı yazılımla ayarlanır.

İlk görülecek programlanabilir cihaz **8255**'tir. Açılımı Programmable Peripheral Interface'tir (programlanabilir çevre birimi arayüzü); işlevsel olarak bir paralel arayüzdür. TTL uyumlu herhangi bir mikroişlemciyle çalışabilir. Üç adet genel amaçlı portu vardır ve 8 bitlik bir cihazdır. Derste 8255'in uç yapısı, iç yapısı, 8086 ile arayüzü, adres çözümlemesi ve yetiştiği ölçüde Mod 0 uygulamaları ele alınacaktır.

Mod 0 temel G/Ç'dir (Basic I/O): paralel olarak 8 bit veri çıkarılır ya da okunur. Mod 1 ve Mod 2 ise el sıkışma (handshaking) temelli veri alışverişine dayanır ve ileride görülecektir.

### 5.1 8255'in uçları

Slaytta 8255'in uç şeması gösterilir (ekrandan, 00:55:00):

- Veri uçları D0–D7 (fiziksel uçlar 34'ten 27'ye). İşlemciyle, derste tasarlanan basit cihazlar gibi 8 veri ucu üzerinden konuşur.
- İki adres ucu: A0 (uç 9) ve A1 (uç 8).
- Kontrol uçları: $\overline{CS}$ (6), $\overline{WR}$ (36), $\overline{RD}$ (5), RESET (35). $\overline{CS}$, $\overline{WR}$ ve $\overline{RD}$ aktif 0'dır. RESET aktif bir uçtur; cihazın hep çalışması istendiği için toprağa bağlanır.
- Besleme: VCC (26), GND (7).
- Portlar: PA0–PA7, PB0–PB7, PC0–PC7.

### 5.2 Port neden gerekir?

Port, dış dünyayla bağlantı sağlayan uçlardır. İşlemcinin veri uçları dış dünyadaki elektriksel seviyelere doğrudan bağlanmaz, çünkü:

- **Zamanlama:** İşlemci uçlardaki değerlere belirli bir zamanlamayla ihtiyaç duyar; dış cihazın ya da dışarıdan bağlanan bir seviyenin buna uyması mümkün olmayabilir.
- **Elektriksel seviye:** İşlemci TTL uyumludur (0–5 V); 1 ve 0 sayılması için belirli aralıklar vardır. Bu aralıkları tutturamayan seviyeleri doğrudan bağlamak uçların yanmasına yol açabilir.
- **Meşguliyet:** Çok yavaş değişen bir uç doğrudan veri ucundan okunur ya da yazılırsa işlemciyi çok meşgul eder. Araya bir yardımcı devre konursa, veri hazır olduğunda bu devre örneğin el sıkışma ile haber verebilir.

Sekiz ucuna aynı anda değer çıkarılabilen ya da sekizinden aynı anda okunabilen portlara paralel port denir. İleride dış dünyayla seri veri alışverişi yapan seri portlar da görülecektir. 8255'in üç adet 8 bitlik paralel portu vardır.

## 6. 8255'in G/Ç uzayında kapladığı yer ve bağlantıları

### 6.1 8255 kaç bayt yer kaplar?

**Soru:** İki adres ucu olan 8255, 8086'nın G/Ç uzayında ne kadar yer kaplar?

**Cevap:** Bir öğrencinin cevabındaki "4" doğrudur ama birim bit değil bayttır. İki adres ucuyla $2^2 = 4$ farklı değer (00, 01, 10, 11) üretilir; bunlar işlemcinin 8255 içinde erişebileceği 4 yazmacın adresleridir. 8255'in 8 veri ucu olduğu için bu yazmaçların her biri büyük olasılıkla 8 bittir. Dört yazmaç × 1 bayt = G/Ç uzayında **4 bayt**.

### 6.2 Basit çıkış birimi kaç bayt yer kaplar?

**Soru:** Derste tasarlanan basit çıkış birimi (74245 + 8 LED) 8086'nın G/Ç uzayında kaç bayt yer kaplar?

**Cevap:** Öğrencilerden gelen "1 bayt" cevabı doğrudur; ama türetme önemlidir. Bu cihazın kaç adres ucu olduğuna bakılır. İşlemcinin 16 adres ucu cihazın adres ucu sayılmaz; $\overline{E}$ ucu da adres ucu değil, chip select ucudur (8255'teki $\overline{CS}$'nin karşılığı). 8255'in A0 ve A1 uçlarının karşılığı bu cihazda yoktur, yani adres ucu sayısı 0'dır. $2^0 = 1$ göz, 8 veri ucu olduğu için 1 bayt eder. Cihaz G/Ç uzayında 1 bayt kaplar. Hoca ileride görülecek sayısal-analog ve analog-sayısal çeviricilerin de adres ucu olmadığını, onların da 1 bayt kaplayacağını söyledi.

### 6.3 $\overline{CS}$ ucu nereye bağlanır?

**Soru:** 8255'in $\overline{CS}$ ucuna işlemci tarafından nereden tel çekilmelidir?

Hoca önce ilk haftanın tam tamponlanmış sistem slaytını hatırlattı: adres ve veri uçları tutucu ve tamponlarla hazırlanmış kabul edildiği için $\overline{DEN}$, DT/$\overline{R}$, ALE ve AD uçları dış dünyaya çıkmaz. Öğrencilerden gelen tahminler (M/$\overline{IO}$, doğrudan 0, bir veri ucu vb.) tek tek ele alındı:

- M/$\overline{IO}$ değildir; o, aynı adresle yapılan işlemin hafıza mı G/Ç mı olduğunu ayırmak için adres çözümleme devresine giren bir uçtur.
- Doğrudan 0 verilirse 8255 her zaman etkin olur; örneğin `MOV AX, BX` çalışırken de veri uçlarında rastgele değerler görülür. Bu istenmez.
- Kesme, DMA (HOLD) gibi konulara henüz gelinmemiştir.

**Cevap:** Bir öğrencinin bulduğu gibi, $\overline{CS}$ ucuna **adres çözümleme devresinin bir çıkışı** bağlanır. 8086'ya bağlı birden fazla cihaz olabilir, ama adres çözümleme devresi tektir; o an yürütülen komut hangi adresle ilgiliyse hangi cihazın seçileceğine o karar verir. Basit çıkış biriminde $\overline{E}$ ucuna ne bağlandıysa 8255'in $\overline{CS}$ ucuna da aynı tür işaret bağlanır.

### 6.4 $\overline{RD}$ ve $\overline{WR}$ uçları

**Soru:** 8255'in $\overline{RD}$ ucuna işlemcinin hangi ucu bağlanmalıdır? Çapraz mı olmalıdır?

**Cevap:** Bu bir tuzak soruydu. Bütün uçlar işlemci açısından tanımlıdır. İşlemci bu cihazdan okuma yapmak istediğinde kendi $\overline{RD}$ ucunu etkin yapar; 8255'in bunu anlaması için işlemcinin $\overline{RD}$ ucu 8255'in $\overline{RD}$ ucuna bağlanır. Benzer şekilde işlemcinin $\overline{WR}$ ucu 8255'in $\overline{WR}$ ucuna bağlanır.

A0 ve A1 uçlarına ne bağlanacağı, adres çözümleme örneğinde (Bölüm 9) cevaplanır.

## 7. 8255'in yazmaçları, iç yapısı ve modları

### 7.1 Yazmaç seçimi

8255'in yaptığı işlem, adres uçlarına ve okuma/yazma işaretlerine göre değişir:

| A1 A0 | Okuma ($\overline{RD}$ = 0) | Yazma ($\overline{WR}$ = 0) |
|---|---|---|
| 00 | Port A uçları → veri yolu | Veri yolu → Port A uçları |
| 01 | Port B uçları → veri yolu | Veri yolu → Port B uçları |
| 10 | Port C uçları → veri yolu | Veri yolu → Port C uçları |
| 11 | Durum okuma (ayrıntısı sonraya bırakıldı) | Kontrol kelimesine (ayar yazmacına) yazma |

Okuma işleminde ($\overline{CS}$ = 0, $\overline{RD}$ = 0) A1A0 = 00 ise 8255, Port A'nın fiziksel uçlarındaki değeri veri uçlarına çıkarır; bu değer işlemcinin veri uçlarına aktarılır, yani işlemci Port A'yı okumuş olur. 01 ve 10 için aynı işlem Port B ve Port C ile yapılır. Yazma işleminde (örneğin `OUT`) A1A0 = 00 ise işlemcinin veri yolundaki değer Port A'nın fiziksel uçlarında üretilir; 01 ve 10 Port B ve Port C içindir. 11 adresine yazılan değer kontrol kelimesine gider; 8255'in programlanabilir olmasının tanımı budur.

> **Hocanın vurgusu:** Bir işlemde $\overline{RD}$ ile $\overline{WR}$'nin ikisinin birden 0 olması mümkün değildir; belirli bir aralıkta ikisi birden 1 olabilir.

### 7.2 İç yapı ve modlar

İç yapıya göre:

- Port A kontrol kelimesiyle tamamen 8 bit çıkış ya da tamamen 8 bit giriş yapılabilir.
- Port B de 8 bit çıkış ya da 8 bit giriş olabilir.
- Port C özeldir: düşük anlamlı 4 biti (PC alt) ve yüksek anlamlı 4 biti (PC üst) birbirinden bağımsız olarak giriş ya da çıkış yapılabilir. Yani Mod 0'da 8255 iki adet 8 bitlik ve iki adet 4 bitlik port gibi davranır.

El sıkışmalı Mod 1 ve Mod 2'de:

- Port A ile Port C'nin yüksek anlamlı 4 biti birlikte çalışır ve Grup A'yı oluşturur: veri Port A'da, el sıkışma işaretleri PC üst 4 bitte.
- Port B ile Port C'nin düşük anlamlı 4 biti birlikte çalışır ve Grup B'yi oluşturur: veri Port B'de, el sıkışma işaretleri PC alt 4 bitte.

Mod 1 ve Mod 2'de Port C el sıkışma ve kontrol uçları olarak kullanılır.

## 8. 16 bitlik veri yolunda 8 bitlik çevre birimi

8255 8 bitlik bir cihazdır; 16 bitlik veri yoluna sahip 8086'ya bağlanırken basit G/Ç birimlerindeki gibi düşünülür. Slayttaki tablo (ekrandan, 01:15:00):

| $\overline{BHE}$ | A0 | Aktarım |
|---|---|---|
| 0 | 0 | Anlamlı değil |
| 0 | 1 | Tek adresteki bayt D8–D15 |
| 1 | 0 | Çift adresteki bayt D0–D7 |
| 1 | 1 | Anlamlı değil |

$\overline{BHE}$ = 0 ve A0 = 0 durumu 16 bitlik çift adresli işlemlerde geçerlidir; ama tek bir 8 bitlik cihaz için anlamlı değildir. İkisinin de seçilmediği durum zaten anlamsızdır.

8255 G/Ç uzayında 4 bayt kapladığı için üç yerleştirme yaklaşımı vardır:

- Ardışık çift adreslere yerleştirmek (cihaz D0–D7'ye bağlanır).
- Ardışık tek adreslere yerleştirmek (cihaz D8–D15'e bağlanır).
- Ardışık adreslere yerleştirmek. Bu durumda 8255'in 8 bitlik veri yolunu adres değerine göre D0–D7 ya da D8–D15'e aktaran özel bir donanım gerekir. Bu daha karmaşık olduğu için derste ilk iki yaklaşım kullanılacaktır.

## 9. Örnek: F8H'den itibaren ardışık çift adreslerde 8255

### 9.1 Soru ve adresler

Slayttaki örnek (ekrandan, 01:20:00): "We want to use a 8255 PPI with the starting I/O address of F8h. Use even addresses only."

F8H ilk adrestir. Sonraki adres F9H tektir; bir sonraki çift adres FAH'dir. Ardından FCH ve FEH gelir. 8255'in 2 adres ucu olduğu için ($2^2 = 4$), soruda söylenmese bile F8H dahil 4 adrese yerleşmesi gerektiği anlaşılır: F8H, FAH, FCH, FEH.

> **Hocanın vurgusu:** Onaltılık adreslerde artı 2 hesabında çok hata yapılıyor. A8H + 2 = AAH'dır, B0H değildir (ekrandan, 01:20:00). Cihazlar hizalı yerleştirildiği için adres dizisinde böyle bir sıçrama görürseniz hatayı fark etmelisiniz.

### 9.2 Sabit ve değişken bitler

Adres 8 bite sığdığı için sabit adresleme kullanılır ve çözümlemede A0–A7 uçları yeterlidir. Hoca, devre karmaşıklığını azaltmak için A8–A15'in zaten 0 olduğunu (0'a bağlandığını) kabul edebileceğini söyledi.

Slayttaki tablo (ekrandan, 01:20:00):

| Adres | A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 |
|---|---|---|---|---|---|---|---|---|
| F8H | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| FAH | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 0 |
| FCH | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
| FEH | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |

Dört adreste de sabit kalan bitler A7 = A6 = A5 = A4 = A3 = 1 ve A0 = 0'dır. Bunlara M/$\overline{IO}$ = 0 eklenir. Bu koşullar cihazı F8H'den itibaren ardışık 4 çift adrese yerleştirir.

> **Ders sonrası not:** Hoca 01:19:48'de önce "A7'nin 0 olması gerekiyor" dedi, hemen ardından (01:20:13) A7 = 1 olarak saydı. F8H = 1111 1000B olduğundan ve slayttaki tablo da öyle gösterdiğinden doğrusu A7 = 1'dir.

### 9.3 A2 ve A1'in bağlanması

A2 ve A1 dört adreste değişir; bu yüzden çözümlemeye girmezler. Bir öğrencinin cevabı doğrudur: bunlar 8255'in adres uçlarına (yazmaç seçimi, "A2-A1 Register Select") bağlanır. Peki bağlantı sırası önemli mi?

**Mavi bağlantı:** işlemcinin A2'si 8255'in A1'ine, işlemcinin A1'i 8255'in A0'ına. Bu durumda (ekrandan, 01:25:00):

- F8H → Port A
- FAH → Port B
- FCH → Port C
- FEH → Kontrol

**Kırmızı bağlantı:** işlemcinin A2'si 8255'in A0'ına, A1'i 8255'in A1'ine. Hangi yazmaçlar değişir?

**Cevap:** Yalnız Port B ve Port C yer değiştirir. 00 ve 11 değerlerinde uçların sırası değişse de değer aynı kalır; bu yüzden Port A yine F8H'de, kontrol yazmacı yine FEH'dedir. FAH'de Port C, FCH'de Port B bulunur (ara adım eklendi: FAH'de A2A1 = 01, çapraz bağlantıda 8255'e A1A0 = 10 gider).

Ardından bu yapıya ait çözümleme devresinde bir kod çözücü kullanıldığı görüldü; bu yüzden önce kod çözücünün çalışması anlatıldı.

## 10. 3×8 kod çözücü

Hoca entegrenin adını "7438" diye andı ve 3×8 kod çözücü (decoder) olduğunu söyledi. <!-- BELİRSİZ: Altyazıda "7438" geçiyor; tarif edilen G1, G2A, G2B etkinleştirmeli, aktif 0 çıkışlı 3×8 entegre büyük olasılıkla 74LS138. -->

> **Ek bilgi (derste anlatılmadı):** G1 (aktif 1), $\overline{G2A}$ ve $\overline{G2B}$ (aktif 0) etkinleştirme uçlu, sekiz aktif 0 çıkışlı standart 3×8 kod çözücü 74LS138'dir. Laboratuvar tanıtımında anılan 74LS137 ise büyük olasılıkla girişleri tutuculu (latch) benzeri bir sürümdür.

Tahtadaki çizim (ekrandan, 01:30:00):

- Üç seçim girişi: C, B, A. Harf büyüdükçe anlam sırası büyür: C'nin ağırlığı $2^2$, B'nin $2^1$, A'nın $2^0$'dır.
- Üç etkinleştirme ucu: G1 (aktif 1), G2A ve G2B (aktif 0).
- Sekiz çıkış: Y0, Y1, …, Y7; hepsi aktif 0.

Cihazın etkin olması için G1 = 1, G2A = 0 ve G2B = 0 olmalıdır. Bu koşulda CBA üç basamaklı ikilik sayısının ondalık değeri hangi çıkışı gösteriyorsa o çıkış 0, diğerleri 1 olur:

| C | B | A | Y0 | Y1 | Y2 | … | Y7 |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 1 | 1 | … | 1 |
| 0 | 0 | 1 | 1 | 0 | 1 | … | 1 |
| … | | | | | | | |
| 1 | 1 | 1 | 1 | 1 | 1 | … | 0 |

Örneğin CBA = 000 → 0 → Y0 = 0; CBA = 001 → 1 → Y1 = 0; CBA = 111 → 7 → Y7 = 0. Etkinleştirme koşulu sağlanmazsa (G1 ≠ 1 ya da G2A ≠ 0 ya da G2B ≠ 0) hiçbir çıkış seçilmez: Y0 = Y1 = … = Y7 = 1. Hoca tahtada önce "G1 eşit değil 0" yazdı, sonra bunu "G1 eşit değil 1" olarak düzeltti.

Çıkışların aktif 0 olması bizim için avantajlıdır, çünkü kullanılacak çevre birimlerinin chip select uçları da aktif 0'dır. Bu yüzden cihaz "aktif 0 çıkışlı 3×8 kod çözücü" diye tam tanımlanır ve kendi başına bir adres çözümleme devresi olarak kullanılabilir.

Ders süresi dolduğu için F8H örneğinin kod çözücülü çözümleme devresi bir sonraki derse kaldı. Hoca slaytlarda sırada ardışık tek adres yerleşimi ve ardından ardışık adres yerleşimi için çoğullayıcıya benzeyen, farklı yolları tek bir veri yoluna aktaran karmaşık devrenin bulunduğunu gösterdi.

## 11. Laboratuvarla bağlantı ve örnek uygulama

Ders sonundaki sorular üzerine hoca laboratuvar çalışmasının mantığını açıkladı.

**Soru:** Adres seçimi buradaki gibi elle mi yapılıyor?

**Cevap:** Bağlantılar elle yapılır: benzetim başlamadan önce, breadboard üzerinde devre kurar gibi bir uçtan diğerine tel çekilir. Örneğin adres çözümleme için 3×8 kod çözücü kullanılacak ve giriş uçlarına neyin bağlanacağına öğrenci karar verecek. Çözümleme devresinin adresi çözmesi, verinin yola çıkması gibi işlemler ise devre çalıştırıldığında yazılan koda ve işlemcinin çalışma mantığına göre benzetim tarafından otomatik üretilir.

Laboratuvarlar hem donanım hem yazılım içerir. Bir devre şablonu verilir; bazı bağlantılar eksik bırakılır ve tamamlanması ya da bazı devrelerin kurulması istenir (pull-up dirençli düğme, uygun dirençli LED, ileride görülecek yedi parçalı gösterge ve 4×4 tuş tarama gibi). Kod hazır verilmez: bir problem verilir, öğrenci hem donanım bağlantısını yapar hem assembly kodunu yazar; benzetim çalıştırıldığında istenen çıktının görülmesi beklenir.

Hoca örnek olarak bir laboratuvar sorusunu Proteus'ta gösterdi: 8255'in Port C'si Mod 0'da kullanılır; yüksek anlamlı yarısı çıkış (LED'ler), düşük anlamlı yarısı giriş (düğmeler) olarak çalışır. Adres çözümleme devresi 3×8 kod çözücüdür. İki tür soru olabilir: cihazın yerleşeceği adres aralığı verilip çözümleme devresinin kurulması istenir, ya da çözümleme devresi verilip cihazın adresleri bulunarak kod buna göre yazılır. İstenen davranış: sistem başladığında bütün LED'ler yanar; bir tuşa basıldığında ilgili sıradaki LED söner. Ekranda bu örneğin kodu görünür (ekrandan, 01:40:00); kodun satır satır açıklaması derste yapılmadı, aşağıda Örnek Sorular bölümünde çözümlenmiştir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): 8 LED kullanarak 0F000H adresine yerleştirilmiş basit bir çıkış birimi tasarlayın (donanım + adres çözümleme) ve LED'lerde (on, off, on, off…) deseni oluşturan programı yazın.

Çözüm (derste verildi): 74245'in DIR ucu 5 V'a, $\overline{E}$ ucu çözümleme devresine bağlanır. Çözümleme koşulu A15–A12 = 1, A11–A0 = 0, M/$\overline{IO}$ = 0, $\overline{WR}$ = 0; devre, A11–A0 ve $\overline{WR}$+M/$\overline{IO}$ girişleri terslenmiş bir NAND kapısıdır. Slayttaki bağlantıda istenen desen D7…D0 = 0101 0101B = 55H ile oluşur. Program: `mov al, 55h` / `mov dx, 0F000h` / `out dx, al`.

**Soru 2** (ekrandan, 00:25:00; derste sözlü, 00:22:18): Çıkış birimine 7000H ya da F001H adresiyle `OUT` yapılırsa ne olur?

Çözüm (derste verildi): 7000H'de A15 = 0, F001H'de A0 = 1 olur. İki durumda da NAND kapısının içindeki VE işleminin bir girişi 0 olur, çıkış 1 olur ve $\overline{E}$ = 1 olduğundan cihaz seçilmez.

**Soru 3** (derste sözlü, 00:24:53): $\overline{WR}$ ve M/$\overline{IO}$ ikisi de 0 olduğunda 0, diğer durumlarda 1 üreten kapı hangisidir?

Çözüm (derste verildi): OR kapısı. Girişlerden biri 1 olursa çıkış 1 olur; yalnız ikisi de 0 iken çıkış 0'dır.

**Soru 4** (ekrandan, 00:30:00): 8 düğme kullanarak 0F000H adresinde basit bir giriş birimi tasarlayın ve bir tuşa basılana kadar bekleyen programı yazın. Hiçbir tuşa basılmadığında hangi değer okunur?

Çözüm (derste verildi): 74245'in DIR ucu toprağa bağlanır; çözümleme koşulu A15–A12 = 1, A11–A0 = 0, M/$\overline{IO}$ = 0, $\overline{RD}$ = 0. Pull-up dirençler yüzünden basılmayan tuş 1 okunur; hiçbir tuşa basılmazsa FFH okunur. Program: `mov dx, 0F000h` / `L1: in al, dx` / `cmp al, 0FFh` / `je L1`.

**Soru 5** (ekrandan, 00:40:00): (a) Aynı adreste giriş ve çıkış birimi bulunması sorun yaratır mı? (b) Basit giriş/çıkış birimini 0F001H adresine yerleştirmek için ne yapılmalıdır? (c) 0F000H adresinden itibaren 16 bitlik bir basit çıkış birimi nasıl tasarlanmalıdır?

Çözüm (derste verildi): (a) Sorun yaratmaz; biri yalnız $\overline{WR}$ = 0 (`OUT`), diğeri yalnız $\overline{RD}$ = 0 (`IN`) ile seçilir. (b) Veri uçları D8–D15'e bağlanır ve çözümleme A0 = 1 ile (tersleyici kaldırılarak) ya da A0 yerine $\overline{BHE}$ = 0 ile yapılır. (c) İki 74245 kullanılır (D0–D7 ve D8–D15); A0 çözümlemeden çıkarılır ve aynı seçim iki cihaza verilir (ya da çift adresteki için A0, tek adresteki için $\overline{BHE}$); aktarım AX ile yapılır.

**Soru 6** (derste sözlü, 00:56:04 ve 00:57:37): 8255 ve derste tasarlanan basit çıkış birimi 8086'nın G/Ç uzayında ne kadar yer kaplar?

Çözüm (derste verildi): 8255'in 2 adres ucu vardır, $2^2 = 4$ yazmaç × 8 bit = 4 bayt. Basit çıkış biriminin adres ucu yoktur ($\overline{E}$ chip select'tir), $2^0 = 1$ göz × 8 bit = 1 bayt.

**Soru 7** (derste sözlü, 01:01:24 ve 01:06:56): 8255'in $\overline{CS}$ ve $\overline{RD}$ uçlarına işlemci tarafında ne bağlanmalıdır?

Çözüm (derste verildi): $\overline{CS}$ ucuna adres çözümleme devresinin bir çıkışı bağlanır (doğrudan 0 verilirse 8255 ilgisiz komutlarda da etkin olur). $\overline{RD}$ ucuna işlemcinin $\overline{RD}$ ucu, $\overline{WR}$ ucuna işlemcinin $\overline{WR}$ ucu bağlanır; çapraz bağlantı yoktur.

**Soru 8** (ekrandan, 01:20:00): Başlangıç G/Ç adresi F8H olan bir 8255 yalnız çift adresler kullanılarak yerleştirilecek. Adresler ve çözümlemeye giren bitler nelerdir? A2 ve A1 nereye bağlanır?

Çözüm (derste verildi): Adresler F8H, FAH, FCH, FEH. Çözümleme koşulu A7 = A6 = A5 = A4 = A3 = 1, A0 = 0, M/$\overline{IO}$ = 0 (A8–A15 = 0 kabul edilir). A2 ve A1 8255'in yazmaç seçme uçlarına gider. İşlemci A2 → 8255 A1, A1 → 8255 A0 ise F8H Port A, FAH Port B, FCH Port C, FEH kontrol olur (ekrandan, 01:25:00). Bağlantı çaprazlanırsa yalnız Port B ile Port C yer değiştirir.

**Soru 9** (ekrandan, 01:20:00): A8H'den sonraki çift adres nedir?

Çözüm (derste verildi): A8H + 2 = AAH. B0H yazmak sık yapılan bir hatadır.

**Soru 10** (ekrandan, 01:30:00): 3×8 kod çözücüde G1 = 1, G2A = 0, G2B = 0 iken CBA = 000, 001 ve 111 için çıkışlar nedir? Etkinleştirme koşulu sağlanmazsa ne olur?

Çözüm (derste verildi): CBA = 000 → Y0 = 0, diğerleri 1; 001 → Y1 = 0, diğerleri 1; 111 → Y7 = 0, diğerleri 1. Etkinleştirme koşulu sağlanmazsa bütün çıkışlar 1'dir.

**Soru 11** (ekrandan, 01:40:00): Laboratuvar örneğinde 8255'in Port C'si Mod 0'da kullanılıyor; PC üst 4 bit çıkış (LED), PC alt 4 bit giriş (pull-up dirençli düğmeler). Başlangıçta bütün LED'ler yanmalı, bir tuşa basılınca ilgili LED sönmelidir. Ekrandaki kod aşağıdadır. Kod bu işi nasıl yapar?

```asm
START:
    MOV AL, 81H
    OUT 66H, AL
    MOV AL, 0FFH
    OUT 64H, AL
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

> **Çözüm (derste verilmedi):** 81H = 1000 0001B kontrol kelimesidir; büyük olasılıkla 8255'in mod seçme biçimine göre en üst bit 1 (mod ayarı), Grup A ve Grup B Mod 0, Port A ve Port B çıkış, PC üst çıkış (bit 3 = 0), PC alt giriş (bit 0 = 1) anlamına gelir. Bu kelime 66H'ye, yani kontrol yazmacına yazılır. Kodda Port C 64H, kontrol 66H olduğundan cihaz büyük olasılıkla ardışık çift adreslere (60H Port A, 62H Port B, 64H Port C, 66H kontrol) yerleştirilmiştir. `OUT 64H, FFH` PC üst bitlerini 1 yapar ve bütün LED'ler yanar. Döngüde Port C okunur, `OR AL, 0F0H` ile üst 4 bit 1'e zorlanır; alt 4 bit 1111 ise (hiçbir tuş basılı değil) AL = FFH olur ve döngü başa döner. Bir tuşa basılırsa ilgili alt bit 0 olur; `SHL AL, 4` bu 4 biti üst yarıya taşır ve `OUT 64H, AL` ile ilgili LED söner. Örneğin PC0 tuşu basılıyken AL = FEH → kaydırma sonrası E0H → PC4 = 0 (python ile denetlendi).

## Dersin Toparlaması

Bu derste adres çözümleme devresinin neden gerektiği (ortak veri yolunda çakışmayı önlemek) ve nasıl kurulduğu, kendi tasarladığımız iki basit birimle somutlaştırıldı. 74245 ve LED'lerle 0F000H'de bir çıkış birimi, 74245 ve pull-up dirençli düğmelerle aynı adreste bir giriş birimi kuruldu; çözümleme koşuluna adres bitlerinin yanında M/$\overline{IO}$ ve $\overline{RD}$/$\overline{WR}$'nin de girdiği, bu sayede iki birimin aynı adreste birlikte durabileceği görüldü. Tek adrese taşımanın D8–D15 ve A0/$\overline{BHE}$ ile, 16 bitlik birimin iki 74245 ve A0'ın çözümlemeden çıkarılmasıyla yapıldığı tartışıldı.

İkinci yarıda programlanabilir paralel arayüz 8255 tanıtıldı: uçları, A1A0 ile seçilen dört yazmacı (Port A, Port B, Port C, kontrol), G/Ç uzayında 4 bayt kaplaması, Mod 0 ile el sıkışmalı Mod 1/Mod 2 grupları. 16 bitlik veri yolunda 8 bitlik cihaz için $\overline{BHE}$/A0 tablosu ve F8H'den başlayan ardışık çift adres örneği işlendi; son olarak aktif 0 çıkışlı 3×8 kod çözücünün doğruluk tablosu verildi. Bir sonraki derste bu kod çözücüyle F8H örneğinin adres çözümleme devresi kurulacak, ardından ardışık tek ve ardışık adres yerleşimlerine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
