# Ders 9 Genişletilmiş Notu: 8255 BSR Modu Örneği ve Mod 1 (El Sıkışmalı G/Ç)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8255'i 16 bitlik veri yoluna bağlamanın tekrarı
- 2. $\overline{BHE}$ ucunun anlamı
- 3. Zorunlu olmayan ödevlerin değerlendirilmesi
- 4. 8255'in üç modu
- 5. Kontrol yazmacının tekrarı
- 6. BSR modu örneği
- 7. Mod 1: gruplar, uçlar ve kontrol sözcükleri
- 8. Mod 1 giriş akışı ve zamanlaması
- 9. Mod 1 çıkış akışı ve zamanlaması
- 10. Durum sözcüğü ile yoklama
- 11. Tek 8255'te iki grubu birbirine bağlama
- 12. Proteus örneği: mod 1 ile tuş takımından 7 segment göstergeye
- Örnek Sorular

## 1. 8255'i 16 bitlik veri yoluna bağlamanın tekrarı

Ders, önceki haftada 8255 için işlenenlerin kısa bir tekrarıyla başlar: uç diyagramı, iç yapı, iç portlara erişim ve 8255'in 16 bitlik veri yoluna sahip 8086'ya nasıl bağlanacağı. Hoca bu tekrarın aynı haftanın laboratuvarı için de yararlı olduğunu belirtir.

### 1.1 Neden çift ya da tek adresler?

8086'nın veri yolu 16 bittir, ama kullanılan G/Ç cihazlarının 8 veri ucu vardır. 8086 tek bir okuma/yazma çevriminde üç tür aktarımı destekler:

- çift adresten 8 bitlik aktarım,
- tek adresten 8 bitlik aktarım,
- çift adresten 16 bitlik aktarım.

20 adres ucuyla 1M × 8 bellek adreslenebilir, fakat işlemci karşısında 512K × 16'lık bir bellek arayüzü görmek ister. Aynı şey G/Ç için de geçerlidir: en fazla 64K × 8'lik G/Ç kapasitesi, işlemciye 32K × 16 olarak görünmelidir. 8 bitlik bir cihazın ardışık çift ya da ardışık tek adreslere yerleştirilmesi, işlemci açısından daha verimli bir veri akışı sağlar.

### 1.2 Ardışık çift adresler

Cihaz ardışık çift adreslere yerleştirilmişse A0 her zaman 0'dır. Dört kombinasyonu (port A, port B, port C, kontrol yazmacı) işlemcinin A2 ve A1 uçları oluşturur; bu uçlar 8255'in A1 ve A0 uçlarına bağlanır. Çift adresten 8 bitlik işlemde işlemci veriyi veri yolunun düşük anlamlı baytında beklediği için 8255'in veri uçları D0-D7'ye bağlanır.

Bu yerleşimde A0'ın 0 aranması, $\overline{BHE}$ (bus high enable) ucunun 1 aranmasıyla eşdeğerdir; adres çözümlemede biri diğerinin yerine kullanılabilir.

Port adresi `IN AL, port8` ya da `OUT port8, AL` komutlarındaki gibi sabit 8 bitlik bir sayı olarak veriliyorsa adres çözümleme yalnız A7-A0 uçlarıyla yapılır; A15-A8 için çözümleme gerekmez (bu derste böyle kabul edilir). Örnekteki çözümleme 3'e 8 kod çözücüyle yapılmıştı (ekrandan, 00:05:00). Kod çözücünün üç izin ucu vardır: ikisi aktif 0, biri aktif 1. İzin uçlarına 0, 0, 1 verilirse seçim girişlerindeki ikilik sayının onluk karşılığı olan çıkış 0, diğerleri 1 olur; izinler uygun değilse hiçbir çıkış 0 olmaz. 8255'in $\overline{CS}$ ucu aktif 0 olduğu için bu çıkış doğrudan seçim için kullanılabilir.

Sayım şöyledir: kod çözücünün 3 seçim ve 3 izin olmak üzere 6 kontrol girişi vardır. Adres çözümlemeye 8 adres ucu ve M/$\overline{IO}$ katılır, toplam 9 uç. Bunlardan ikisi (A2, A1) 8255'e doğrudan bağlandığı için geriye 7 uç kalır; 7 uç 6 girişe bağlanacağı için iki uç uygun bir kapıyla birleştirilir. Ekrandaki devrede A7 ve A6 bir VE kapısında birleşip aktif 1 olan E3'e, M/$\overline{IO}$ ve A0 aktif 0 olan E1 ve E2'ye, A5-A3 seçim girişlerine bağlıdır; 7 numaralı çıkış $\overline{CS}$'yi sürer (ekrandan, 00:05:00).

### 1.3 Ardışık tek adresler

Ardışık tek adreslerde işlemci veriyi D8-D15 arasında bekler; bu yüzden veri uçlarının bağlantısı değişir. Burada A0 = 1 aranır ve bu, $\overline{BHE}$ = 0 aranmasıyla eşdeğerdir. Devrede A0'ı DEĞİL kapısından geçirip izin girişine vermek yerine $\overline{BHE}$ doğrudan aynı girişe bağlanabilir. Diğer konular aynıdır: dört kombinasyonu A2 ve A1 oluşturur, 3'e 8 kod çözücüyle 8 bitlik adres yeterlidir, G/Ç işlemi olduğu için M/$\overline{IO}$ = 0 aranır.

### 1.4 Ardışık adresler

Son alternatif ardışık adreslere yerleştirmedir ve daha karmaşık bir donanım gerektirir. Adres tekse 8255 verisi veri yolunun yüksek anlamlı baytına, çiftse düşük anlamlı baytına aktarılmalıdır; bunun için gelen adrese göre yalnız biri etkin olan bir tampon/mandal mantığı kullanılmıştı. Bu durumda dört kombinasyonu A1 ve A0 oluşturur. Hoca bu yerleşimin ders kapsamında olmadığını, yalnız örnek olarak hatırlatıldığını söyler.

Önceki hafta ayrıca mod 0 kontrol yazmacı, BSR modunun ayar bitleri ve mod 0 örnekleri işlenmişti: 8255'i seçme, düğme ve LED sürme, 7 segment gösterge sürme, dört 7 segment göstergeyi birlikte sürme ve 4x4 ya da 3x4 matris tuş takımını tarama.

## 2. $\overline{BHE}$ ucunun anlamı

Bir öğrencinin sorusu üzerine hoca $\overline{BHE}$'yi yeniden açıklar. Bellek ve G/Ç cihazları x16 düzende iki sütun gibi düşünülür. Düşük anlamlı (çift adresli) blok A0 = 0 ile, yüksek anlamlı (tek adresli) blok $\overline{BHE}$ = 0 ile seçilir. Bu yüzden A0, adres ucu olmasına karşın "bus low enable" gibi de çalışır; verinin yüksek anlamlı veri yolunda olduğunu belirtmek için de $\overline{BHE}$ kullanılır.

Hoca bir karşılaştırma verir: 80386 ve 80486'da veri yolu 32 bittir. Her bellek gözü 8 bit olduğu için işlemci belleği x32 görmek ister, yani dört bellek bloğu yan yana gelir. A1 ve A0'ın ikisinin de 0 olduğu blok (adresin 4'e bölümünden kalan 0) byte enable 0 ile, kalan 1 olan blok byte enable 1 ile, kalan 2 ve 3 olanlar da kendi byte enable uçlarıyla seçilir; her biri ayrı bir fiziksel uçtur. 8086'da ise ayrı fiziksel uç olarak yalnız $\overline{BHE}$ vardır; "bus low enable" A0 ile eşdeğer düşünülür.

Buradan çıkan eşdeğerlikler:

- Çift adreslere yerleştirme: A0 = 0 aranır ya da $\overline{BHE}$ = 1 aranır; adres çözümleme devresinde biri diğerinin yerine konabilir.
- Tek adreslere yerleştirme: A0 = 1 aranır ya da $\overline{BHE}$ = 0 aranır.

$\overline{BHE}$'nin asıl önemi çift adresten 16 bitlik işlemdedir. Adres çift olduğu için A0 = 0'dır; işlem 16 bitlik olduğu için işlemci $\overline{BHE}$ = 0 da üretir. Böylece hem çift hem tek adresli bloktaki aynı satır etkinleşir ve işlemci 16 bitlik veriyi tek seferde okur. Hoca, bellek arayüzü konusunda 16 bitlik arayüzün nasıl kurulduğunun ayrıca görüleceğini, orada $\overline{BHE}$ ile blok seçmenin yanında farklı bir yaklaşımın da işleneceğini söyler.

## 3. Zorunlu olmayan ödevlerin değerlendirilmesi

### 3.1 Dört 7 segment göstergede farklı değerler

Derste dört 7 segment göstergenin hepsinde aynı değer yakılmıştı; ödevde 1, 2, 3, 4 gibi farklı değerlerin gösterilmesi istenmişti. Bir öğrencinin çalışması ekranda çalıştırıldı ve sorunsuz göründü. Hoca bu uygulamada çıkabilecek iki tipik sorunu anlatır:

- Tarama (güncelleme) frekansı yeterli değilse bütün değerler bütün hanelerde yanıyormuş gibi görünür; sonuçta her hanede 8 varmış gibi bir görüntü oluşur.
- Hane geçişi düzgün yapılmazsa, yani iki hane kısa süre aynı anda etkin kalırsa, örneğin 2 yanması gereken yerde 1 ve 2 aynı anda yanabilir; bu da gösterge kalitesini bozar.

### 3.2 Tuş takımında her tuşu tanıma

Derste tuş takımı örneği yalnız bir sütunun bir satırını tarıyor, yalnız o tuşa basıldığını anlıyordu; ödevde herhangi bir tuşun hangisi olduğunu anlayacak biçimde kodun genişletilmesi istenmişti. Bir öğrencinin uygulaması gösterildi. Uygulamada parmak tuştan çekilince değer sönüyordu. Hoca beklenen davranışı şöyle açıklar: bir tuşa basıldıktan sonra değer yazılımsal ya da mantıksal olarak mandallanmalı, başka bir tuşa basılana kadar korunmalıdır.

Hoca ayrıca 4x4 tarama mantığındaki varsayımı vurgular: aynı anda iki tuşa basılmadığı varsayılır. İki tuşa birden basılırsa yazılım bunu anlayıp değeri atabilir, ama donanımda mutlaka diyot koruması gerekir. Örneğin bir sütun 0, başka bir sütun 1 sürülürken iki sütundaki tuşlara aynı anda basılırsa sürülme sırasına göre bu hatlar birbirine kısa devre olabilir. Diyotlarla tuş takımını korumak aynı zamanda 8255'i korumak demektir.

**Soru:** Laboratuvar ödevinde ilk basılan düğmeden sonra basılan ikinci ya da üçüncü düğmenin dikkate alınmaması isteniyor. Bir düğmeye basınca değer doğru yazılıyor, ama birinci düğme basılıyken ikinciye basılınca 2 yerine ikisinin toplamı olan 3 yazılıyor. Neden?

**Cevap:** Maskeleme uygun yapılmamış olabilir. Örneğin birinci satırdaki bir değişim algılandıktan sonra yalnız o satırın maskesini korumak gerekebilir. Düğmelerin değerleri 1, 2, 4, 8 olarak ikilik basamak sırasına göre ağırlıklandırılmıştır; maskenin nasıl uygulanacağına dair ipucu bu ağırlıklandırmadadır.

## 4. 8255'in üç modu

Hoca ardından haftanın konusuna geçer ve 8255'in üç haberleşme modunu özetler (ekrandan, 00:30:00).

### 4.1 Mod 0: basit G/Ç

Mod 0 "basic I/O" ya da "simple I/O" olarak geçer. Port A ve port B tek başına 8 bitlik giriş ya da 8 bitlik çıkış olarak ayarlanabilir. Port C'nin düşük (PCL) ve yüksek (PCH) yarıları ise ayrı ayrı 4 bitlik giriş ya da çıkış olabilir.

Mod 0'ın temel özelliği, dış dünyaya veri gönderirken ya da dış dünyadan veri alırken bir denetim olmamasıdır. İşlemci veriyi gönderir ve ulaştığını varsayar, alındı (acknowledge) gelip gelmediğini denetlemez. Okurken de hatta geçerli veri olup olmadığını denetlemez, verinin her zaman hazır olduğunu varsayar. Bu yüzden veri denetimi gerektirmeyen işler için uygundur: LED, düğme gibi tekil değer yazma ya da okuma, o anki değerin doğruluğunu denetleme ihtiyacı olmayan durumlar. Önceki örneklerde LED, düğme, 7 segment gösterge ve 4x4 tuş takımı mod 0'da kullanılmıştı.

### 4.2 Mod 1: tek yönlü el sıkışma

Mod 1, 8255 içindeki grup A ve grup B üzerinden çalışır. Grup A, port A ile port C'nin yüksek anlamlı yarısından; grup B, port B ile port C'nin düşük anlamlı yarısından oluşur.

Mod 1 el sıkışma (handshaking) temelli bir veri alışverişidir. Veri gönderen taraf karşıya bir strobe işareti gönderir; bu, verinin hazır olduğunu gösterir. Karşı taraf veriyi kendi içine aldığında acknowledge gönderir; bu da verinin alındığını gösterir. Mod 1'in mod 2'den farkı veri yönünün tek olması ve baştan belirlenmesidir: bir grup baştan giriş olarak ayarlandıysa giriş, çıkış olarak ayarlandıysa çıkış yönünde çalışır. Grup A mod 1'de çalışırsa port A veriyi taşır, port C'nin yüksek yarısı kontrol ve el sıkışma işaretlerini içerir. Grup B mod 1'de çalışırsa port B veriyi taşır, port C'nin düşük yarısı kontrol ve el sıkışma işaretlerini içerir (ekrandan, 00:55:00).

Mod 0 port A, port B, PCL ve PCH için ayrı ayrı tanımlanırken mod 1 grup A ve grup B için tanımlanır. Ayrıca grup A mod 1'de kullanılırken grup B'deki portlar mod 0'da kullanılabilir; böyle bir çeşitlilik vardır.

### 4.3 Mod 2: çift yönlü el sıkışma

Mod 2 çift yönlü (bidirectional) bir el sıkışma yöntemidir. Yürütülen komuta göre port yönü ayarlanır: `OUT` kullanılırsa port çıkış, `IN` kullanılırsa giriş yönünde olur. Mod 2'yi yalnız grup A kullanabilir; port A ve port C birlikte mod 2 için kullanılır, port C'nin bütün bitleri el sıkışma ve kontrol işaretlerine ayrılmış olur. Port B boşta kalır ve istenirse mod 0 ya da mod 1'de kullanılabilir.

## 5. Kontrol yazmacının tekrarı

Kontrol yazmacı 8 bittir (ekrandan, 00:35:00). Erişim koşulları şunlardır: 8255'in $\overline{CS}$ ucu 0, A1 ve A0 uçları 1 ve 1 iken bir yazma işlemi yapılırsa veri yolundaki değer kontrol yazmacına aktarılır.

En yüksek anlamlı bit (D7) iki durumu ayırır:

- D7 = 0: sözcük BSR (bit set/reset) işlevi görür.
- D7 = 1: mod ayarı yapılır (mod 0, mod 1 ya da mod 2).

Mod ayar sözcüğünde:

- D6-D5: grup A modu. 00 mod 0, 01 mod 1, 1X (10 ya da 11) mod 2.
- D4: port A yönü (mod 0 ve mod 1'de).
- D3: port C yüksek yarısının yönü (mod 0'da).
- D2: grup B modu. Yalnız 0 (mod 0) ya da 1 (mod 1) olabilir; grup B'de mod 2 yoktur.
- D1: port B yönü.
- D0: port C düşük yarısının yönü (mod 0'da).

Yön bitlerinde 1 giriş, 0 çıkıştır.

**Soru:** Çıkış olarak ayarlanmış uçlardan `IN` ile okunan değerler ne anlama gelir?

**Cevap:** Anlamsız değerlerdir, yazmaçtaki geçici değerler okunmuş olabilir; dikkate alınmamalıdır. Dört düğmeli ve dört LED'li örnekte port C'nin düşük yarısında LED'ler, yüksek yarısında düğmeler vardı; port C okunduğunda LED'leri süren bitler maskelenerek atılıyordu. Bu değerleri dikkate almamak programcının sorumluluğudur.

BSR modu port C'nin herhangi bir $i$ numaralı ucunda 0 ya da 1 oluşturmak için kullanılır. Bu, o ucun çıkış olarak ayarlanmasına karşılık gelir. BSR modu tek bitte çıkış değeri üretmenin yanında bazı ayarları açıp kapatmak için de kullanılır. BSR sözcüğünde:

- D7 = 0,
- D6, D5, D4 önemsiz (don't care),
- D3 D2 D1: port C'nin hangi ucunun seçildiğini belirten 3 bitlik ikilik sayı,
- D0: seçilen uca yazılacak değer (1 set, 0 reset).

## 6. BSR modu örneği

### 6.1 Soru ve adresler

Slayttaki soru şöyledir (ekrandan, 00:40:00): 80H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8255'te a) PC2'yi lojik 1 olacak biçimde, b) PC6'da görev çevrimi %66 olan bir kare dalga üretecek biçimde programlayın.

Ardışık çift adresler 2'şer artar: port A 80H, port B 82H, port C 84H, kontrol sözcüğü 86H'dir (88H değil). Her iki şık da port C'nin tek bir ucunda değer oluşturmak istediği için bir BSR modu örneğidir ve bütün yazmalar kontrol sözcüğüne yapılır. Alttaki bağlantı ve adres çözümlemenin yapılmış olduğu varsayılır.

### 6.2 a şıkkı: PC2 = 1

BSR sözcüğü bit bit kurulur:

- D7 = 0 (BSR),
- D6 D5 D4 = X X X, 0 alınır,
- D3 D2 D1 = 010 (uç numarası 2),
- D0 = 1 (set).

Sonuç 0000 0101B = 05H'dir. Yani a şıkkı 86H portuna 05H yazmaya dönüşür.

**Soru:** Bu işlem tek satırda yapılabilir mi?

**Cevap:** Hayır. `OUT` komutunun kalıbında port 8 bitlik sabit olabilir, ama gönderilen veri ya AL ya da AX olmalıdır. Veri önce AL'ye alınır (ekrandan, 00:45:00):

```asm
MOV AL, 05H    ; BSR mod ile C2 set icin CW degeri
OUT 86H, AL    ; CW degeri yazildi
```

> **Hocanın vurgusu:** Kodun yanına bu tür açıklamaların mutlaka yazılması beklenir.

### 6.3 b şıkkı: %66 görev çevrimli kare dalga

Görev çevrimi (duty cycle) şöyle tanımlanır: periyodik bir kare dalgada bir periyot $T$, dalganın aynı hareketin yeniden başladığı noktaya kadar geçen süredir. Dalganın 1'de kalma süresi $d$ ise görev çevrimi

$$\text{görev çevrimi} = \frac{d}{T}$$

olur. Hoca kullanım alanı olarak PWM ile motor sürmeyi ve modülasyonları anar.

%66 görev çevrimi için 1'de kalma süresi $2x$, 0'da kalma süresi $x$ alınır. O zaman $T = 3x$ ve $d/T = 2x/3x \approx \%66$ olur (ekrandan, 00:50:00). Yapılacak iş, PC6'da BSR moduyla 2 birim zaman 1'de, 1 birim zaman 0'da kalan bir kare dalga üretmektir.

Bu iş sonsuz döngüde yapılır: PC6'ya 1 yazılıp yeniden 0'a çekilmezse uç 1'de, 0 yazılıp yeniden 1'e çekilmezse 0'da kalır.

Gereken iki BSR sözcüğü (ekrandan, 00:50:00):

- PC6 = 1: D7 = 0, D6-D4 = 000, D3 D2 D1 = 110 (6), D0 = 1 → 0000 1101B = 0DH.
- PC6 = 0: D7 = 0, D6-D4 = 000, D3 D2 D1 = 110, D0 = 0 → 0000 1100B = 0CH.

Yani 86H'ye 0DH gönderilince uç 1'e çıkar, 0CH gönderilince 0'a düşer. Bekleme için bir birim zaman bekleyen, önceden tanımlanmış `DELAY` alt programı varsayılır; içinde NOP'lar ya da hiçbir iş yapmayan boş bir döngü olabilir. İki kez çağrılırsa iki birim, bir kez çağrılırsa bir birim bekler. Program (kare dalga kısmı ekrandan, gecikme çağrıları altyazıdan):

```asm
L1: MOV AL, 0DH    ; PC6 = 1
    OUT 86H, AL
    CALL DELAY     ; 1 birim
    CALL DELAY     ; 1 birim -> 1'de toplam 2 birim
    MOV AL, 0CH    ; PC6 = 0
    OUT 86H, AL
    CALL DELAY     ; 0'da 1 birim
    JMP L1
```

İşleyiş: uç 1'e çıkar, iki birim beklenir, uç 0'a düşer, bir birim beklenir ve başa dönülür.

> **Ders sonrası not:** Altyazıda döngü sonundaki komut "CMP L1" olarak geçer (00:46:13, 00:51:17). Ekranda yazılan komut `JMP L1`'dir; ses tanıma hatası olması büyük olasılıktır.

### 6.4 İşletim sistemsiz sistemlerde sonsuz döngü

Hoca laboratuvar örneklerinde de sonsuz döngüler olacağını söyler. Mikroişlemci üzerinde işletim sistemi yüklü değildir. İlk reset alındığında CS'ye FFFFH, IP'ye 0000H yüklenir (ekrandan, 00:50:00); bu bir fiziksel adrese karşılık gelir ve orada kullanıcının programının yerleştirildiği belleğe bir atlama komutu bulunur. Sistem resetlenir resetlenmez yazılan kod çalışmaya başlar.

Bu yüzden program sürekli tekrar eden bir döngüdür: 7 segment göstergede sürekli değer yakmak, tuş takımını tarayıp bir tuşa basılıp basılmadığını denetlemek, ya da ikisini birleştirip basılan tuşun değerini göstermek ve yeniden taramak. Genel amaçlı bir bilgisayarda böyle sonsuz döngülü programlar genelde yazılmaz, ama mikroişlemci tarafındaki G/Ç işlerinde olağandır.

> **Ek bilgi (derste anlatılmadı):** CS = FFFFH ve IP = 0000H, fiziksel adres olarak $FFFF0H + 0000H = FFFF0H$ verir. Bu adres 1 MB'lık uzayın sonundan 16 bayt öncedir; bu yüzden orada genellikle yalnız uzak bir atlama komutu bulunur.

Hoca laboratuvar Proteus örneklerinde BSR'nin bir çıkış örneği olmadığını, ancak BSR'nin mod 1'deki kesme izin (interrupt enable) ayarlarını kurmak için kullanılacağını belirtir.

## 7. Mod 1: gruplar, uçlar ve kontrol sözcükleri

### 7.1 Mod 1'in kullanım alanı

Mod 1, iki terminal ya da iki 8255 arasında ya da 8255 ile el sıkışmayı destekleyen bir dış birim arasında kullanılır: yazıcı, klavye, tuş tarama entegreleri ya da 7 segment gösterge tarama entegreleri. 8255 bu tür bir dış birimle haberleşmeyi el sıkışma işaretleri üzerinden denetimli biçimde yapar.

Mod 1'de veri yönü tektir. Grup A ya da B giriş veya çıkış olarak ayarlanır ve değiştirilmediği sürece öyle çalışır. Giriş yönü ayarlanmışsa `OUT` komutları yok sayılır ya da anlamsız değerler üretebilir. Mod 2'de ise yön baştan belirlenmez, verilen komut otomatik olarak belirler.

Grup A için veri port A'da, kontrol işaretleri port C'nin yüksek yarısında; grup B için veri port B'de, kontrol işaretleri port C'nin düşük yarısında bulunur.

> **Ders sonrası not:** Hoca bir yerde "mod 1'de veriler grup A için port B'de taşınır" dedi (00:54:18). Doğrusu grup A verisinin port A'da taşınmasıdır; hemen ardından hoca da grup A için port A + PCH tanımını verir.

Grup A ve grup B ayrı ayrı programlanabilir: ikisi de birbirinden bağımsız olarak mod 1'de ayarlanabilir. Grup A mod 1'de iken port B ve boşta kalan port C uçları mod 0'da kullanılabilir; tersine, grup B mod 1'de iken port A ve port C'nin yüksek yarısı mod 0'da kullanılabilir. Hoca grup A için 8 veri biti ve 4 kontrol biti olduğunu söyler: veri bitleri port A'da, kontrol bitleri port C'nin yüksek yarısındadır.

### 7.2 Dört yapılandırma ve kontrol sözcükleri

Slaytta mod 1'in dört yapılandırması bir arada gösterilir (ekrandan, 01:00:00): sol üstte grup A mod 1 giriş, sol altta grup B mod 1 giriş, sağ üstte grup A mod 1 çıkış, sağ altta grup B mod 1 çıkış. Her birinin yanında kontrol sözcüğüne yazılacak değer vardır.

| Yapılandırma | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|---|
| Grup A mod 1 giriş | 1 | 0 | 1 | 1 | 1/0 | X | X | X |
| Grup A mod 1 çıkış | 1 | 0 | 1 | 0 | 1/0 | X | X | X |
| Grup B mod 1 giriş | 1 | X | X | X | X | 1 | 1 | X |
| Grup B mod 1 çıkış | 1 | X | X | X | X | 1 | 0 | X |

Grup A mod 1 giriş sözcüğünde D7 = 1 mod ayarı, D6 D5 = 01 grup A mod 1, D4 = 1 port A giriş demektir. D3'ün anlamı burada farklıdır: grup A mod 1 girişte port C'nin 6 ve 7 numaralı uçları boşta kalır. Bu uçlar mod 0'daki gibi birer G/Ç ucu olarak giriş ya da çıkış yapılabilir; yönlerini D3 belirler (1 giriş, 0 çıkış). Alt dört bit grup B ile ilgili olduğu için grup A'yı ayarlamak isteyen için önemsizdir; D7-D3 yeterlidir.

Grup B mod 1 giriş sözcüğünde D7 = 1 mod ayarı, D2 = 1 grup B mod 1, D1 = 1 port B giriş demektir.

Grup A mod 1 çıkış için girişten farklı olarak D4 = 0 yapılır. Çıkışta port C'nin 4 ve 5 numaralı uçları boşta kalır; bunların basit G/Ç yönü yine D3 ile ayarlanır. Grup B mod 1 çıkış için de girişten farklı olarak D1 = 0 yapılır.

### 7.3 Uçların görevleri ve INTE bitleri

Şekildeki her satır bir port C ucunu ve onun görevini gösterir (ekrandan, 01:00:00):

| Yapılandırma | Strobe / ACK | IBF / OBF | INTR | INTE'yi kuran uç | Boştaki uçlar |
|---|---|---|---|---|---|
| Grup A giriş | $\overline{STB_A}$ = PC4 | IBF$_A$ = PC5 | PC3 | PC4 | PC6, PC7 |
| Grup A çıkış | $\overline{ACK_A}$ = PC6 | $\overline{OBF_A}$ = PC7 | PC3 | PC6 | PC4, PC5 |
| Grup B giriş | $\overline{STB_B}$ = PC2 | IBF$_B$ = PC1 | PC0 | PC2 | — |
| Grup B çıkış | $\overline{ACK_B}$ = PC2 | $\overline{OBF_B}$ = PC1 | PC0 | PC2 | — |

INTE A (interrupt enable A) bir iç kontrol bitidir; dışarıdan doğrudan erişilemez, fiziksel bir uç olarak yoktur. Şekilde aynı satırda bulunduğu port C ucuyla eşleşir: grup A girişte PC4'e BSR modunda 1 yazılırsa INTE A'ya da 1 yazılmış olur, 0 yazılırsa INTE A 0 olur. Hoca, uç numarasının veri sayfasında yazılı olduğunu, şekildeki aynı satır eşleşmesinin yalnız görsel bir hatırlatma olduğunu belirtir. INTE A, daha üst seviyeden bir kontrol işareti olan INTR A'nın (interrupt request A) üretilmesini sağlar.

## 8. Mod 1 giriş akışı ve zamanlaması

### 8.1 Klavye örneği

Hoca önce kesmeyi işin içine katmadan anlatır (ekrandan, 01:05:00). 8255 dış dünyadan veri almak istiyorsa, dış cihazın (örneğin bir klavye) veri hattını ve strobe bağlantısını yapmış olması gerekir. 8255 bu modda uçları yoklamayla (polling) denetlemez; bir tetikleme işareti bekler.

1. Klavye verisini veri hattına koyar.
2. Klavye $\overline{STB}$ ucunda 0 oluşturur. Bu, karşı taraf için "veri uçlarında veri hazır, okuyabilirsin" demektir; adres mandallamadaki ALE tetiklemesi gibi düşünülebilir.
3. 8255 veri uçlarını okuyup iç yazmacına kopyalar. Nanosaniyeler mertebesinde de olsa bu kopyalama zaman alır.
4. Kopyalama bitince port A'nın tampon yazmacı dolduğu için 8255 IBF (input buffer full) çıkışını etkinleştirir. Klavye açısından IBF bir acknowledge, bir "ready" ucudur.

Grup A girişte $\overline{STB}$ işareti PC4'ten verilir, IBF PC5'ten çıkar. Klavye, alındı işareti gelmeden sonraki karakteri gönderirse öncekini ezebilir.

> **Hocanın vurgusu:** El sıkışmada sıra ve denetim çok önemlidir; sıra ve denetim yoksa veri kaybolabilir.

Olaya üç birim katılır: 8086, 8255 ve klavye. Amaç basılan klavye tuşunu 8086'ya aktarmaktır. Bunun için 8086 8255'in grup A'sını mod 1 giriş olarak ayarlar, klavyenin veri uçları port A'ya, klavyenin ready ucu PC4'e (8255 için strobe) bağlanır. Okuma bitince IBF ile bu karşı tarafa bildirilir.

8086 IBF'yi yakaladığında veriyi okuyabilir. Ancak bunun için PC5'i sürekli örnekleyip IBF'nin 1 olup olmadığını yoklama mantığıyla denetlemesi gerekir. Yani el sıkışma bir aşamada vardır, ama 8086 tarafında yine yoklama vardır.

Bunu aşmak için PC3'ten kesme isteğiyle uyumlu bir çıkış (INTR A) üretilir. Bu çıkışın üretilip üretilmemesini INTE A biti belirler; INTE A'yı açmak için PC4'e BSR modunda 1 yazılır. INTE A açıksa kopyalama bitip IBF etkinleşince INTR ucunda anlamlı bir değer oluşur. Bu uç 8086'nın kesme istek ucuna bağlıysa 8086 8255'i sürekli yoklamak zorunda kalmaz; kesme isteği gelince o sırada yaptığı işi bırakıp port A'daki veriyi okur.

Aynı şey grup B için de geçerlidir (ekrandan, 01:10:00). Dış birimin verisi port B'ye bağlanır, ready ucu PC2'ye ($\overline{STB_B}$), alındı ucu PC1'e (IBF$_B$) bağlanır. Klavye tuşa basılınca veriyi port B uçlarına koyar, strobe gönderir; 8255 uçlardaki değeri port B yazmacına kopyalar ve dış birim sonraki veriyi gönderebilsin diye alındı işareti verir. Verinin hazır olduğunu anlamak için IBF B'ye (PC1) bakmak yeterlidir, ama bu sürekli yoklama ister. INTE B açılırsa (PC2'ye BSR modunda 1 yazılırsa) PC0'da bir kesme istek ucu oluşur; mikroişlemcinin kesme girişine bağlanırsa veri akışı kesme temelli olur ve işlemci INTR'de lojik 1 görünce o anki işini bitirip port B'yi okur.

### 8.2 Uçların formal tanımları

- $\overline{STB}$ (strobe, giriş): lojik 0 olduğunda port uçlarındaki verinin içerideki mandala, ilgili port yazmacına alınmasını sağlayan kontrol işaretidir.
- IBF (input buffer full): uçlardan içeriye kopyalama bitince lojik 1 olur (aktif 1); verinin içeri okunduğunu doğrular. $\overline{STB}$'nin düşük olduğu anda tetiklenerek 1'e çıkar. İşlemci tamponu okuyunca ($\overline{RD}$) tampondaki veri artık eskimiştir ve IBF 0'a düşer.
- INTR (interrupt request): kesme istekleriyle uyumlu, seviye tetiklemeli bir kesme istek ucudur. İşlev görmesi için INTE bitinin 1 yapılmış olması gerekir. $\overline{STB}$ = 1, IBF = 1 ve INTE = 1 iken 1 olur; yani strobe bitmiş ve veri içeri alınmıştır. İşlemci kesme isteği üzerine yaptığı işi bitirip tamponu okur; okuma ($\overline{RD}$) ile INTR yeniden 0'a düşer.
- INTE A ve INTE B: girişte sırasıyla PC4 ve PC2 ile BSR modunda kurulan bitlerdir.

### 8.3 Zamanlama diyagramı

Slayttaki "8255 Mod 1 – Input Timing" diyagramında $\overline{STB}$, IBF, INTR, $\overline{RD}$ ve çevre biriminden gelen veri işaretleri vardır (ekrandan, 01:20:00).

**Soru:** $\overline{STB}$ ucunu kim sürüyor: 8086 mı, 8255 mi, klavye mi?

**Cevap:** Çevre birimi, yani klavye sürer.

> **Hocanın vurgusu:** Konunun anlaşılması için bu soruya doğru cevap vermek çok önemlidir. Bir ucu "sürmek", o uçtaki değeri oluşturmak demektir.

**Soru:** IBF'yi kim sürüyor?

**Cevap:** 8255 sürer; IBF 8255'ten çıkan bir uçtur. Aynı şekilde INTR'yi 8255 sürer, $\overline{RD}$'yi ise 8086 denetler.

Akış:

1. Klavye veriyi koyar, sonra $\overline{STB}$'yi gönderir. $\overline{STB}$'nin düşen kenarı verinin 8255'e okunmasını başlatır; belirli bir sürede okuma tamamlanır ve IBF 1 olur.
2. Klavye önce $\overline{STB}$'yi hattan kaldırır, belirli bir süre sonra veriyi de kaldırır.
3. $\overline{STB}$ 1'e döndüğünde IBF de 1'dir. INTE de 1 yapılmışsa bu üç koşul sağlanır ve INTR 1'e çıkar; mikroişlemcide kesme isteği oluşur.
4. Mikroişlemci bir süre sonra yaptığı işlemi bitirip kesme alt programına geçer ve 8255'in ilgili portunu okur. $\overline{RD}$ (aktif 0) düştüğünde INTR etkinliğini kaybeder.
5. Okuma bitince ($\overline{RD}$ yükselince) IBF 0'a düşer ve sonraki verinin alınmasına hazır olunur.

Diyagramda kimin kimi tetiklediği ve hangi koşulda hangi ucun değer aldığı oklarla gösterilir.

## 9. Mod 1 çıkış akışı ve zamanlaması

### 9.1 Yazıcı örneği

Çıkışa bağlanabilecek cihaza örnek bir yazıcıdır (ekrandan, 01:15:00). Yazıcıya karakterler gönderilir; karakterler üst üste gönderilirse yazıcıdaki önceki karakterler ezilebilir. Bu yüzden her karakteri yazıcı işledikten sonra göndermek anlamlıdır.

1. 8086 dış dünyaya göndermek istediği veriyi port A yazmacına yazar.
2. Yazma işlemi bitince veri port uçlarında oluşur ve PC7'deki $\overline{OBF}$ (output buffer full) ucunda lojik 0 oluşur. $\overline{OBF}$'yi 8255 sürer.
3. $\overline{OBF}$ yazıcının strobe ucuna bağlıdır; bu uç 0 olunca yazıcı veri uçlarını okuyup içeri alır.
4. Yazıcı veriyi aldığında, yani belleğine alıp yazdırdığında, 8255'e $\overline{ACK}$ gönderir (PC6). $\overline{ACK}$ aktif 0'dır; etkin olduğunda o uçta 0 görülür.

$\overline{ACK}$ denetlenerek verinin gönderildiğinden emin olunabilir, ama bunun için ilgili bit sürekli yoklanmalıdır. Alternatif yine kesmedir: PC6'ya BSR modunda yazılarak INTE A açılırsa PC3'ten kesme isteğiyle uyumlu bir değer çıkar. Bu uç mikroişlemcinin kesme girişine bağlanırsa işlemci o anki işlerini yaparken kesme geldiğinde kesme alt programında sonraki karakteri gönderebilir.

> **Ders sonrası not:** Hoca grup B'de INTE B'yi açmak için PC2'nin BSR modunda "reset" edilmesi gerektiğini söyledi (01:14:14). Doğrusu PC2'ye 1 yazılmasıdır (set). Hocanın kendi örnek kodunda da INTE B, PC2 = 1 yapan 05H sözcüğüyle açılır (bkz. Bölüm 12).

### 9.2 Uçların formal tanımları

- $\overline{OBF}$: işlemci 8255'in yazmacına veri yazınca lojik 0'a düşer. Örneğin yazıcı için bir strobe işaretidir.
- $\overline{ACK}$: çevre birimi port uçlarındaki değeri okuyup işledikten sonra 8255'e gönderir; uçta lojik 0 görülmesiyle etkinleşir ve karşı tarafın veriyi değerlendirdiğini bildirir. Ardından $\overline{OBF}$ yeniden 1 olur.
- INTR: slayttaki tanım şudur (ekrandan, 01:25:00): "INTR: A '0' on this output can be used to interrupt the CPU when an output device has accepted data transmitted by the CPU. INTR is set when $\overline{ACK}$ is a '1', $\overline{OBF}$ is a '1' and INTE is a '1'. It is reset by the falling edge of $\overline{WR}$." Yani alındı işareti bitmiş, $\overline{OBF}$ 1'e dönmüş ve INTE 1 ise INTR 1'e çıkar; yeni bir yazma işlemi onu sıfırlar.
- Çıkışta INTE A PC6 ile, INTE B PC2 ile denetlenir.

> **Ders sonrası not:** Slayttaki INTR tanımının ilk cümlesinde "A '0' on this output" yazar; aynı tanımın devamında INTR'nin 1 olduğunda kurulduğu (set) söylenir. Kesme isteği INTR'nin 1 olmasıdır; ilk cümledeki "0" büyük olasılıkla slayt yazım hatasıdır (veri sayfasında "A 'high' on this output" ifadesi geçer).

Yeni veri göndermek isteyen işlemci bunu ya $\overline{ACK}$'i denetleyerek ya da kesme üzerinden, INTR ucuyla yapabilir.

### 9.3 Zamanlama akışı

1. 8086 $\overline{WR}$ ile 8255'e veri yazar; amaç bu veriyi 8255 üzerinden yazıcıya aktarmaktır.
2. Yazma bittikten belirli bir süre sonra, değerler 8255'in yazmacında oluştuğu anda $\overline{OBF}$ 0'a düşer.
3. Dış birim veriyi alır, işler ve bunu $\overline{ACK}$ ile gösterir. Bu noktadan sonra $\overline{OBF}$ yeniden 1'e çıkar.
4. Yazıcı belirli bir süre sonra $\overline{ACK}$'i kaldırır. $\overline{ACK}$ ve $\overline{OBF}$ ikisi de 1 iken INTE de 1 ise INTR 1'e çıkar.
5. Mikroişlemci verinin gönderildiğini anlar ve yeni bir yazma yapar; bu yazma ile INTR yeniden 0'a düşer ve döngü baştan başlar.

### 9.4 İki akışın özeti

Okuma: dış birim veriyi hatta koyar, $\overline{STB}$ gönderir, veri okunur, IBF 1 olur, dış birim $\overline{STB}$'yi kaldırır; $\overline{STB}$ = 1, IBF = 1, INTE = 1 ise INTR 1 olur, işlemci veriyi okur ve INTR 0'a düşer.

Yazma: işlemci port yazmacına yazar, $\overline{OBF}$ 0 olur ve karşı tarafta strobe olarak algılanır, veri içeri alınıp işlenir, $\overline{ACK}$ = 0 ile bildirilir; çevre birimi $\overline{ACK}$'i kaldırır, $\overline{OBF}$ de 1'dir, INTE = 1 ise INTR oluşur; bu, sonraki yazmaya hazır olunduğu anlamına gelir.

## 10. Durum sözcüğü ile yoklama

Verinin okunduğunu ya da gönderildiğini anlamak için iki yöntem konuşuldu. Birincisi girişte IBF'ye, çıkışta $\overline{OBF}$'ye ya da $\overline{ACK}$'e bakmaktır. İkincisi INTR uçlarına bakmaktır. Bu bilgiler fiziksel uç olarak vardır, ama port C'nin ilgili bitleri olarak da okunabilir.

8255 mod 1'de ayarlanmışsa port C adresinden yapılan okuma durum (status) sözcüğünü verir:

- Mod 1 girişte: IBF A, INTR A ve grup B için IBF B, INTR B bitleri buradan denetlenebilir.
- Mod 1 çıkışta: OBF A, OBF B, INTR A ve INTR B bitleri yoklama mantığıyla denetlenebilir.

INTR A ve INTR B'ye bakmak ancak INTE A ya da INTE B açıksa anlamlıdır; kesme kullanılmayacaksa IBF'lere bakmak yeterli olabilir. Kesmeler henüz işlenmediği için INTR ucunda değer oluşsa bile şimdilik durum sözcüğünden yoklamayla kullanılır.

<!-- BELİRSİZ: Durum sözcüğü bit düzeni slaytta gösterildi (yaklaşık 01:31:00-01:33:00), ancak bu aralıkta kare yok. Aşağıdaki ek bilgi veri sayfasından alınmıştır, derste gösterilen slaytla karşılaştırılamadı. -->

> **Ek bilgi (derste anlatılmadı):** 8255 veri sayfasına göre mod 1 giriş durum sözcüğü D7-D0 sırasıyla I/O, I/O, IBF$_A$, INTE$_A$, INTR$_A$, INTE$_B$, IBF$_B$, INTR$_B$; mod 1 çıkış durum sözcüğü ise $\overline{OBF_A}$, INTE$_A$, I/O, I/O, INTR$_A$, INTE$_B$, $\overline{OBF_B}$, INTR$_B$ biçimindedir. Bu düzende INTR$_A$ her iki yönde D3, INTR$_B$ D0'dır; Bölüm 12'deki koddaki `AND AL, 08H` ve `AND AL, 01H` maskeleri de bu bitlere karşılık gelir.

<!-- BELİRSİZ: 01:33:27'de bir öğrencinin yazılı sorusuna hoca "her birisinden birer tane bit boşta geliyor, grup A'dan ve grup B'den birer port C biti boşta kalmış oluyor, 3 bit demek mantıklı olabilir" diye cevap verdi. Soru altyazıda yok; neyin 3 bit olduğu net değil. -->

## 11. Tek 8255'te iki grubu birbirine bağlama

Slayttaki soru (ekrandan, 01:35:00): 8255 grup A mod 1 çıkış, grup B mod 1 giriş yönlü ayarlanarak bunlar arasında el sıkışma tabanlı G/Ç işlemleri nasıl yapılabilir?

Grup A çıkış olduğu için port A, $\overline{OBF_A}$ çıkışı ve $\overline{ACK_A}$ girişi vardır. Grup B giriş olduğu için port B, $\overline{STB_B}$ girişi ve IBF$_B$ çıkışı vardır. Bağlantı:

- Port A uçları port B uçlarına bağlanır.
- $\overline{OBF_A}$ çıkışı, giriş tarafı için strobe işareti olarak $\overline{STB_B}$'ye bağlanır.
- Çıkış tarafının alındı girişi $\overline{ACK_A}$, giriş tarafının IBF$_B$ çıkışına karşılık gelir. Biri aktif 0, diğeri aktif 1 olduğu için IBF$_B$ bir DEĞİL kapısından geçirilip $\overline{ACK_A}$'ya verilir.

Böylece 8255 kendi içinde bir geri döngü (loopback) kurmuş olur. İki ayrı 8255'in birinin grup A'sı çıkış, diğerininki giriş olacak biçimde bağlanması da aynı mantıkla yapılır.

Hoca zaman kısıtı nedeniyle mod 2'yi bu derste anlatmadan bırakır ve mod 1 örneğine geçer.

## 12. Proteus örneği: mod 1 ile tuş takımından 7 segment göstergeye

### 12.1 Amaç ve yardımcı entegreler

Amaç, 8255'in grup A ve grup B'sini mod 1'de kullanarak 4x4 tuş takımında basılan tuşun 7 segment karşılığını göstergede göstermektir. İki yardımcı devre vardır (ekrandan, 01:40:00 ve 01:45:00).

Birincisi MM74C922 tuş tarama kontrolcüsüdür. X uçlarıyla sütunları sürer, Y uçlarıyla satırları okur; kendi iç mantığıyla basılan tuşu bulur ve 16 değerden birine karşılık 0-F arası 4 bitlik değeri D, C, B, A uçlarında (aynı anlam sırasıyla) verir. Benzetimde 0 tuşuna basılınca D, C, B, A uçlarında ikilik 0, 8 numaralı tuşa basılınca ikilik 8 görülür. Entegrenin osilatör girişine kondansatörler bağlıdır; bu bağlantı sabit kabul edilir.

<!-- BELİRSİZ: 01:38:25'te hoca "2 okuttu" dedikten sonra 17 ve 16 numaralı uçlarda (A ve B) kırmızı olduğunu, bunun 0, 0, 1, 1 olduğunu söylüyor; bu 3'e karşılık gelir. Hangi tuşa basıldığı ve gösterilen değerin 2 mi 3 mü olduğu altyazıdan net değil. -->

Önemli uçlar:

- DA (data available): tuşa basılmadığında 0'dır. Bir tuşa basılınca DA'da anlık olarak 1 oluşur, yani aktif 1 çalışır. Bu, klavyenin strobe işaretiyle veri göndermesine benzer.
- $\overline{OE}$ (output enable): 0 verildiğinde basılan tuşun kodu D, C, B, A uçlarına çıkar; böylece verinin veri yoluna denetimli çıkması sağlanır.

Tuş tarayıcı satır ve sütun taramayı kendisi yaptığı için 8255 üzerinde ayrıca tuş tarama yapılmaz, değer doğrudan mod 1'de okunur.

İkincisi 4511 7 segment gösterge sürücüsüdür. Gösterge ortak katotludur: ortak uç 0'a bağlıdır, bir segmenti yakmak için o segment ucuna 1 verilir.

**Soru:** Bu 7 segment gösterge hangi tiptedir?

**Cevap:** Ortak uç 0'a bağlı olduğu için ortak katottur; yakmak için segment uçlarına 1 verilir.

4511'in A, B, C, D girişlerine verilen ikilik değere karşılık QA-QG çıkışlarında ortak katot gösterge değeri üretilir. Örneğin 0000 girişinde 0 yakmak için yalnız G segmenti 0, diğerleri 1 olur. LT ve BI uçları sabit kabul edilir. LE (latch enable, strobe olarak da kullanılır) ucu şöyle çalışır: LE sinyali verildiğinde A-D uçlarındaki değer içeri kopyalanır ve çıkışlarda gösterilir; LE kaldırıldıktan sonra girişler ne kadar değişirse değişsin gösterge değişmez.

### 12.2 Tuş tarama tarafının bağlantısı

Bastığımız tuştan okumak istediğimiz için grup A mod 1 giriş yönlü çalışır; giriş yönlü mod 1'de $\overline{OBF}$ yoktur.

**Soru:** Tuşa basılınca 74C922'nin DA ucunun 1 olması, 8255 mod 1 giriş tarafında hangi uca karşılık gelir?

**Cevap:** Mod 1 girişte $\overline{STB}$ ve IBF uçları vardır; DA $\overline{STB}$'ye karşılık gelir.

DA aktif 1, grup A'nın $\overline{STB}$ ucu (PC4) ise aktif 0'dır; bu yüzden DA bir DEĞİL kapısından geçirilip PC4'e verilir. Böylece tuşa basılınca 8255 grup A mod 1 girişe strobe gelmiş olur. 8255'in IBF çıkışı (PC5) tuş tarayıcının $\overline{OE}$ ucunu etkinleştirir ve basılan tuşun değeri port A'ya aktarılır; IBF aktif 1, $\overline{OE}$ aktif 0 olduğu için bu bağlantıda da bir DEĞİL kapısı vardır (ekrandan, 01:45:00).

### 12.3 Gösterge tarafının bağlantısı

7 segment sürücü port B'ye, yani grup B'ye bağlıdır. LED yakılacağı için grup B mod 1 çıkış olarak ayarlanır; çıkışın kontrol işaretleri $\overline{OBF}$ ve $\overline{ACK}$'tir. $\overline{OBF_B}$, 4511'in LE ucuna bağlanır. 4511'in $\overline{ACK}$'e karşılık gelen bir ucu yoktur; bu yüzden $\overline{OBF_B}$ iki DEĞİL kapısından geçirilip biraz geciktirilerek $\overline{ACK_B}$ olarak geri verilir. Dolayısıyla el sıkışma tam anlamıyla denetlenmiş olmaz: belirli bir süre sonra değerin göstergede yanacağı varsayılarak alındı işareti kendiliğinden üretilir.

### 12.4 Adres çözümleme

Adres çözümleme devresinde A15 gibi yüksek adres uçları da kullanılır; bu yüzden port adresi 8 bite sığmaz, 16 bitlik bir adrestir ve port adresleri DX üzerinden verilmelidir (ekrandan, 01:50:00). Hoca, bu devrenin A8-A3 gibi serbest bırakılan uçların başka kombinasyonlarında da çalışacağını, öğrencilerin ise 16 bitlik sabit bir adres gerekiyorsa çözümlemeyi yalnız o adreste çalışacak biçimde özelleştirmesi gerektiğini söyler.

Devrede adres uçları 74273 mandallarıyla tutulur. 74154 (4'e 16 kod çözücü) seçim girişleri A = A9, B = A10, C = A11, D = A12'dir. M/$\overline{IO}$ aktif 0 izin girişi E1'e, A13, A14, A15 bir 7427 kapısıyla birleştirilip bir DEĞİL kapısından geçtikten sonra E2'ye bağlıdır. 8255, $\overline{IO1}$ çıkışına bağlıdır.

> **Ek bilgi (derste anlatılmadı):** 7427 üç girişli VEYA DEĞİL (NOR) kapısıdır. Ardından gelen DEĞİL kapısıyla birlikte E2'ye A13 + A14 + A15 (VEYA) gider; E2 aktif 0 olduğu için seçim yalnız A15 = A14 = A13 = 0 iken yapılır. Hocanın tahtadaki çözümü de bu koşulu verir.

$\overline{IO1}$ çıkışı için seçim girişlerinde D C B A = 0 0 0 1 olmalıdır: A12 = 0, A11 = 0, A10 = 0, A9 = 1. M/$\overline{IO}$ = 0 ve A15 = A14 = A13 = 0'dır. 8255'in A1, A0 uçlarına işlemcinin A2, A1 uçları bağlıdır; ardışık çift adreslerdir. Önemsiz uçlar 0 alınınca adresler:

| Yazmaç | Adres | İkilik (A15...A0) |
|---|---|---|
| Port A | 200H | 0000 0010 0000 0000 |
| Port B | 202H | 0000 0010 0000 0010 |
| Port C | 204H | 0000 0010 0000 0100 |
| Kontrol sözcüğü | 206H | 0000 0010 0000 0110 |

### 12.5 Kod

Kaynak kod ekranda şöyledir (ekrandan, 01:55:00; açıklamalar eklendi):

```asm
START:
        mov dx, 206h      ; kontrol sozcugu adresi
        mov al, 09h       ; 0000 1001: BSR, PC4 = 1 -> INTE A = 1
        out dx, al
        mov al, 05h       ; 0000 0101: BSR, PC2 = 1 -> INTE B = 1
        out dx, al
        mov al, 0BCh      ; 1011 1100: mod ayari
        out dx, al
        mov dx, 202h
ENDLESS:
tekrar1: mov dx, 204h     ; port C = durum sozcugu
        in al, dx
        and al, 08h       ; INTR A biti
        cmp al, 00
        je tekrar1        ; tus okunana kadar bekle
        mov dx, 200h      ; port A
        in al, dx
        mov bl, al        ; tus kodunu sakla
tekrar: mov dx, 204h
        in al, dx
        and al, 01h       ; INTR B biti
        cmp al, 00
        je tekrar         ; grup B hazir olana kadar bekle
        mov dx, 202h      ; port B
        mov al, bl
        out dx, al        ; kodu 4511'e gonder
        JMP ENDLESS
```

Kodun açıklaması:

- `MOV DX, 206H` ile kontrol sözcüğü adresi DX'e alınır.
- 09H = 0000 1001B: D7 = 0 (BSR), D3 D2 D1 = 100 = 4, D0 = 1. PC4'ü 1 yapmak, INTE A'yı 1 yapmak demektir.
- 05H = 0000 0101B: BSR, uç 2, set. PC2'yi 1 yapmak INTE B'yi 1 yapmak demektir.
- 0BCH = 1011 1100B, yine kontrol sözcüğüne (DX hâlâ 206H) yazılır: D7 = 1 mod ayarı, D6 D5 = 01 grup A mod 1, D4 = 1 port A giriş, D3 = 1 port C yüksek yarısı giriş, D2 = 1 grup B mod 1, D1 = 0 port B çıkış, D0 = 0 port C düşük yarısı çıkış. Hoca için önemli olanlar grup A'yı mod 1 giriş, grup B'yi mod 1 çıkış yapmaktır.
- `MOV DX, 202H` satırı (port B) bu noktada kullanılmaz, önemli değildir.
- Sonsuz döngüde önce port C (204H) okunur, 08H ile maskelenir ve sıfır mı diye bakılır. Grup A giriş yönlü olduğu için 08H maskesi INTR A'nın 1 olup olmadığına bakar; diğer bitler sıfırlanır. INTR A 1 olana kadar döngüde kalınır. INTR A'nın 1 olması, bir tuşa basıldığı ve kodunun 8255'in içine alındığı anlamına gelir. Ardından port A (200H) okunur ve değer geçici olarak BL'ye saklanır.
- Sonra port C yeniden okunur, bu kez grup B'nin müsait olup olmadığını anlamak için. 01H ile maskelenir; port B çıkış yönlü olduğundan bu bit INTR B'dir. Önceden grup B'ye gönderilen verinin alışverişi bitmemişse beklenir; bitmişse grup B yeni veriyi almaya hazırdır.
- Grup B hazır olunca port A'dan okunan değer port B'ye (202H) yazılır.

Tuş tarayıcı basılan tuşun ikilik karşılığını verdiği için aynı değer 7 segment sürücüye gönderildiğinde basılan tuşun 7 segment karşılığı ekranda görülür. Bu sonsuz döngüde tekrarlanır. Hoca bir sınırlamaya dikkat çeker: bu bağlantıda tuşlar 0, 1, 2, ..., 9 olarak numaralanmıştır; 4511 onlu bir sürücü olduğundan 9'dan sonraki değerler için gösterim yoktur ve gösterge boş kalır.

> **Ek bilgi (derste anlatılmadı):** 8255 veri sayfasına göre mod ayar sözcüğü yazıldığında çıkış yazmaçları ve durum flip-floplarının sıfırlandığı belirtilir. Bu yüzden INTE bitlerini kuran BSR sözcükleri genelde mod sözcüğünden sonra yazılır. Derste gösterilen kodda sıra tersidir ve benzetimde çalıştığı görülmüştür; gerçek donanımda sıranın mod sözcüğü, ardından BSR sözcükleri olması büyük olasılıkla daha güvenlidir.

Hoca derste kullanılan örneği ve sunumu paylaşacağını, bir sonraki deneyin 8255 mod 1 ile ilgili olacağını söyler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): 80H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8255'te a) PC2'yi lojik 1 olacak biçimde, b) PC6'da görev çevrimi %66 olan bir kare dalga üretecek biçimde programlayın.

Çözüm (derste verildi, ekrandan 00:45:00 ve 00:50:00):

- Adresler: PA = 80H, PB = 82H, PC = 84H, CW = 86H.
- a) BSR sözcüğü 0 000 010 1 = 05H. `MOV AL, 05H` ve `OUT 86H, AL`.
- b) PC6 = 1 için 0 000 110 1 = 0DH, PC6 = 0 için 0 000 110 0 = 0CH. 1'de 2 birim, 0'da 1 birim kalınır: $d/T = 2x/3x \approx \%66$.

```asm
L1: MOV AL, 0DH
    OUT 86H, AL
    CALL DELAY
    CALL DELAY
    MOV AL, 0CH
    OUT 86H, AL
    CALL DELAY
    JMP L1
```

**Soru 2** (derste sözlü, 00:41:10): 86H portuna 05H değeri tek bir komutla yazılabilir mi?

Cevap (derste verildi): Hayır. `OUT` komutunda veri işleneni yalnız AL ya da AX olabilir; değer önce `MOV AL, 05H` ile AL'ye alınmalıdır.

**Soru 3** (derste sözlü, 01:20:14): Mod 1 giriş zamanlamasında $\overline{STB}$ ucunu kim sürer: 8086, 8255 ya da klavye? IBF'yi kim sürer?

Cevap (derste verildi): $\overline{STB}$'yi çevre birimi (klavye), IBF'yi 8255 sürer. INTR'yi de 8255 sürer, $\overline{RD}$'yi 8086 denetler.

**Soru 4** (ekrandan, 01:35:00): 8255 grup A mod 1 çıkış, grup B mod 1 giriş yönlü ayarlanarak bunlar arasında el sıkışma tabanlı G/Ç işlemleri nasıl yapılabilir?

Cevap (derste verildi): PA uçları PB uçlarına, $\overline{OBF_A}$ $\overline{STB_B}$'ye bağlanır; IBF$_B$ aktif 1, $\overline{ACK_A}$ aktif 0 olduğundan IBF$_B$ bir DEĞİL kapısından geçirilip $\overline{ACK_A}$'ya verilir.

**Soru 5** (derste sözlü, 01:43:47): Proteus örneğinde tuşa basılınca 74C922'nin DA ucunun 1 olması, 8255 mod 1 giriş tarafında hangi uca karşılık gelir ve nasıl bağlanır?

Cevap (derste verildi): $\overline{STB_A}$ (PC4) ucuna karşılık gelir. DA aktif 1, $\overline{STB}$ aktif 0 olduğu için araya bir DEĞİL kapısı konur. Benzer biçimde aktif 1 IBF$_A$ (PC5), bir DEĞİL kapısıyla tuş tarayıcının aktif 0 $\overline{OE}$ ucuna verilir.

**Soru 6** (derste sözlü, 01:40:55): Ortak ucu 0'a bağlı bir 7 segment gösterge hangi tiptedir ve bir segmenti yakmak için ne verilir?

Cevap (derste verildi): Ortak katottur; segmenti yakmak için o segmentin ucuna 1 verilir.

**Soru 7** (ekrandan, 01:50:00 ve 01:55:00): Proteus devresinde 74154'ün seçim girişleri A12-A9, izin girişleri M/$\overline{IO}$ ve A15-A13'ün VEYA'sı, 8255 $\overline{IO1}$ çıkışına, A1/A0 uçları işlemcinin A2/A1 uçlarına bağlıdır. 8255'in port adreslerini bulun ve kodda kontrol sözcüğüne yazılan 09H, 05H ve 0BCH değerlerini çözümleyin.

Cevap (derste verildi): A9 = 1, A12-A10 = 0, A15-A13 = 0, M/$\overline{IO}$ = 0 → PA = 200H, PB = 202H, PC = 204H, CW = 206H. 09H: BSR, PC4 = 1 (INTE A = 1). 05H: BSR, PC2 = 1 (INTE B = 1). 0BCH = 1011 1100B: grup A mod 1, port A giriş, PCH giriş, grup B mod 1, port B çıkış, PCL çıkış.

## Dersin Toparlaması

Ders, 8255'in 16 bitlik 8086 veri yoluna ardışık çift ve tek adreslerle bağlanmasını ve $\overline{BHE}$ ile A0 arasındaki eşdeğerliği hatırlatarak başladı. Ardından 8255'in üç modu karşılaştırıldı: denetimsiz basit G/Ç sağlayan mod 0, grup A ve grup B için tek yönlü el sıkışma sağlayan mod 1 ve yalnız grup A için çift yönlü el sıkışma sağlayan mod 2. Kontrol yazmacının mod ve BSR sözcükleri tekrarlandıktan sonra BSR moduyla tek bir port C ucunu kurma ve bu yolla %66 görev çevrimli bir kare dalga üretme örneği çözüldü.

Dersin ağırlığı mod 1'deydi. Dört yapılandırmanın kontrol sözcükleri, $\overline{STB}$, IBF, $\overline{OBF}$, $\overline{ACK}$ ve INTR uçlarının port C'deki yerleri, INTE bitlerinin BSR ile kurulması, giriş (klavye) ve çıkış (yazıcı) akışları zamanlama diyagramlarıyla incelendi. Kesmeler henüz işlenmediği için INTR bitlerinin durum sözcüğünden yoklanabileceği gösterildi. Ders, 74C922 tuş tarayıcıyı grup A mod 1 girişe, 4511 gösterge sürücüsünü grup B mod 1 çıkışa bağlayan Proteus örneğiyle bitti. Mod 2 bu derste anlatılmadı; sonraki laboratuvar deneyinin 8255 mod 1 ile ilgili olacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
