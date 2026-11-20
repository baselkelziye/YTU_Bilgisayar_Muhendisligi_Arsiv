# Ders 13 Genişletilmiş Notu: 8251 Proteus Örnekleri ve 8254 Programlanabilir Zamanlayıcıya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8251 örneklerinin Proteus devresi
- 2. 208H'den itibaren ardışık çift adreslere 8251 yerleştirme
- 3. Adres çözümleme devresini tasarlama
- 4. Verilen devreden adres aralığını bulma
- 5. Örnek 1: sürekli karakter gönderme
- 6. Örnek 2: gelen karakterin bir sonrakini geri gönderme
- 7. 8254 Programlanabilir Aralık Zamanlayıcısı
- 8. 8254 iç yapısı ve uç tanımları
- 9. 8254 kontrol sözcüğü
- 10. 8254 ayarlama örneği
- Örnek Sorular

## 1. 8251 örneklerinin Proteus devresi

Ders, önceki haftada işlenen 8251 USART konusunun yarım kalan örnekleriyle başlar. İki örnek vardır: biri veri göndermeye, diğeri veri almaya ilişkindir. Hoca, laboratuvar konusu da 8251 olduğu için bu örneklerin hem laboratuvara hem de sınava hazırlık açısından faydalı olacağını belirtir.

### 1.1 Devredeki bileşenler

Proteus'taki "8086 Demo Board" tasarımında şu bileşenler vardır (ekrandan, 00:05:00):

- 8086 mikroişlemci,
- yolları ayrıştırmak için kullanılan yardımcı blok (74273 tutucular); çıkışında bütün adres yolunu temsil eden ADR yolu ve veri için AD yolu bulunur,
- adres çözümleme devresi: 74HC154 (4'e 16 kod çözücü), 74HC4002 ve 74HC4078 NOR kapıları, NOT kapıları,
- 8251A,
- bir mantık analizörü ve bir sanal terminal (virtual terminal).

Hoca, veri yolu için ayrı bir "data bus" yerine doğrudan AD yolunu kullanmanın yeterli olduğunu hatırlatır.

8251 için standart bağlantı yapısı kullanılır: tek bir adres ucu (C/$\overline{D}$), $\overline{RD}$ ve $\overline{WR}$ uçları ve bir $\overline{CS}$ ucu. Simülasyonun çalışması için gereken en az bağlantılar da verilir: CTS ve RESET uçları toprağa çekilir. Modem uçları (DTR, DSR, RTS vb.) kullanılmaz.

### 1.2 Saat girişi ve baud faktörü

8251'in RxC (alma saati) ve TxC (gönderme saati) uçlarına 9600 Hz frekanslı bir kare dalga üreteci bağlıdır. Asenkron modda 8251, mod yazmacındaki baud faktörüne göre bu frekansı bölerek kullanır. İki ayrı saat üreteci, biri RxC'ye diğeri TxC'ye bağlansaydı alma ve gönderme farklı frekanslarda yapılacaktı.

### 1.3 Mantık analizörü

Mantık analizörüne yol (bus) ya da tekil uçlar bağlanabilir. Tekil bir uç bağlandığında o uçtaki lojik değer her değiştiğinde bir tetikleme olur ve değer ekrana kaydedilir. Hoca bunu "uzun süreli ekrana sahip, kayıt yapan, içten tetiklemeli bir osiloskop" diye anlatır. Yol bağlansaydı 8 bitlik değer değiştiğinde kayıt tetiklenecekti.

Kullanımda dikkat edilecekler:

- "Capture" tuşuna basıldığında sistemde tekrarlanan bir veri varsa bir periyodu kaydedilir.
- Tetikleme anahtarları en sola getirildiğinde yükselen kenar, düşen kenar ve seviye değişimlerinin hepsinde tetikleme olur.

### 1.4 Sanal terminal

Sanal terminal 8251'den bağımsız bir görselleştirme arayüzüdür; aynı zamanda 8086'lı sistemin konuştuğu dış çevre birimi gibi düşünülür. Üzerinden hem veri gönderilip hem veri alınabilir.

Asenkron haberleşmede iki uç haberleşme parametrelerini önceden bilir: baud hızı, parite kullanılıp kullanılmayacağı (kullanılıyorsa tek mi çift mi) ve stop biti sayısı. Bu örneklerde sanal terminalin ayarları sabit kabul edilir ve 8086 tarafı ona uydurulur. Terminalin özellikleri (sağ tık, "Edit Properties"):

- 9600 baud,
- 8 veri biti,
- parite yok,
- 1 stop biti.

Simülasyon sırasında terminal penceresi kapatılırsa yeniden başlatmada gelmeyebilir; bu durumda Debug menüsünden "Virtual Terminal" seçilerek tekrar açılır.

## 2. 208H'den itibaren ardışık çift adreslere 8251 yerleştirme

Sorunun ön bilgisi şudur: 208H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8251, 8086 ile arabirimlenmek isteniyor. Önce bu durumda adres çözümleme devresinin nasıl kurulacağı, sonra da elimizdeki devrenin hangi adres aralığını çözdüğü incelenir.

### 2.1 Yazılım tarafı: DX ile adresleme

208H, 8 bitlik doğrudan port adresine sığmaz. Bu yüzden port adresi önce DX'e yüklenir, erişim `IN AL, DX` / `OUT DX, AL` ile DX üzerinden yapılır. DX 16 bitlik olduğu için adresler de 16 bit olarak düşünülür: 0208H.

### 2.2 İkinci adres: 20AH, 210H değil

Birinci adres 208H'dir. Onaltılık sayarken 208H'den sonraki çift adres 20AH'dir.

> **Hocanın vurgusu:** En çok yapılan hatalardan biri 208H'den sonra 210H yazmaktır. Bunu yazmayın.

Bu hatayı fark etmenin yolu ikilik açılıma bakmaktır. 8251'in bir adres ucu vardır, yani adres uzayında 2 bayt kaplar; iki adres arasında yalnız bir bit değişmelidir. Hoca bunu Excel'de gösterir (ekrandan, 00:15:00):

```text
bit    15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
0208H   0  0  0  0  0  0  1  0  0  0  0  0  1  0  0  0
020AH   0  0  0  0  0  0  1  0  0  0  0  0  1  0  1  0
0210H   0  0  0  0  0  0  1  0  0  0  0  1  0  0  0  0   (hatalı)
```

0208H ile 020AH arasında yalnız A1 değişir. 0208H ile 0210H arasında ise iki bit (A4 ve A3) değişir. İki bitin değişmesi 4 baytlık bir alan demektir; 8251 yalnız 2 bayt kapladığı için bu adres seçimi hatalıdır.

### 2.3 Aranan koşul

Doğru adreslerden çıkan koşullar şunlardır (ekrandan, 00:20:00):

- A15, A14, ..., A10, A8, A7, A6, A5, A4, A2 ve A0 = 0,
- A9 = 1 ve A3 = 1,
- M/$\overline{IO}$ = 0 (G/Ç komutlarıyla çalışılacağı için),
- A1 serbest: iki farklı adres durumunu bu bit oluşturur.

Bu koşullar sağlandığında $\overline{CS}$ üretecek, diğer durumlarda üretmeyecek bir mantık aranır.

## 3. Adres çözümleme devresini tasarlama

Hoca, Proteus'taki devreye bakmadan önce kendi tasarımını yapar; amaç farklı bir yoldan aynı sonuca ulaşmaktır.

### 3.1 74HC154 4'e 16 kod çözücü

Devrede kullanılan kod çözücünün özellikleri:

- İki izin ucu (E1, E2) vardır ve ikisi de aktif sıfırdır. Bunlardan birine 0 dışında bir değer gelirse bütün çıkışlar 1 olur.
- İki izin ucu da 0 ise, D C B A sırasıyla yazılan ikilik sayının ondalık karşılığı kaçsa o numaralı çıkıştan lojik 0, diğer bütün çıkışlardan lojik 1 çıkar.
- Seçim uçlarında harf büyüdükçe anlam sırası büyür; D en anlamlı uçtur.
- 16 çıkış vardır.

8251'in $\overline{CS}$ ucu da aktif sıfır olduğu için kod çözücünün aktif sıfır çıkışı bu ucu doğrudan sürebilir.

### 3.2 17 koşulu 6 girişe sığdırmak

16 adres biti ve M/$\overline{IO}$ ile toplam 17 koşul vardır, kod çözücünün ise 6 girişi (2 izin, 4 seçim) vardır. Çözüm, 0 olması gereken uçları birleştirip aktif sıfır izin uçlarına vermektir.

İstenen davranış "girişlerin hepsi 0 iken 0, diğer durumlarda 1" üreten bir mantıktır. İki girişli doğruluk tablosu:

| x | y | çıkış |
|---|---|-------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Bu tablo OR kapısıdır. Buna göre:

- A15, A14, A13, A12, A11, A10, A8, A7, A6, A5, A4 ve A2 büyük bir OR kapısına girer, çıkışı E1'e bağlanır.
- A0 ve M/$\overline{IO}$ ikinci bir OR kapısına girer, çıkışı E2'ye bağlanır.
- A9 en anlamlı seçim ucu D'ye, A3 ikinci anlam sırasındaki C'ye verilir; B ve A toprağa bağlanır.

### 3.3 Hangi çıkış aktif olur?

208H ya da 20AH geldiğinde OR kapılarına giren bitlerin hepsi 0 olduğu için iki izin ucu da 0 olur. Seçim uçlarında D = A9 = 1, C = A3 = 1, B = 0, A = 0 vardır:

$$DCBA = 1100_2 = \text{C}_{16} = 12$$

Dolayısıyla Y12 çıkışı 0 olur ve bu çıkış "CS8251" olarak 8251'in $\overline{CS}$ ucuna verilir. Hoca kendi tasarımını Proteus'taki devreyle karşılaştırır: tasarım farklı olsa da aynı çıkış elde edilmiştir.

### 3.4 A1 ucu nereye gider?

**Soru:** A1 ucunu adres çözümleme devresine bağlamak mantıklı mı? **Cevap:** Hayır. 208H ve 20AH için iki farklı durum oluşmalıdır ve bunu oluşturan A1'dir. A1 doğrudan 8251'in C/$\overline{D}$ adres ucuna bağlanır. C/$\overline{D}$ = 1 iken kontrol tipli yazmaçlara, 0 iken veri tipli yazmaçlara erişilir.

## 4. Verilen devreden adres aralığını bulma

Bazen soru tersinden verilir: elimizde bir adres çözümleme devresi vardır ve cihazın hangi adres aralığında olduğu sorulur. Proteus'taki devre şöyledir (ekrandan, 00:25:00):

- 74HC154'ün seçim uçları: A ← A0, B ← A2, C ← A3, D ← A9.
- U2 (74HC4002 NOR) girişleri: A15, A14, A13, M/$\overline{IO}$; çıkışı bir NOT kapısından geçip E1'e gider.
- U9 (74HC4078 NOR) girişleri: A12, A11, A10, A8, A7, A6, A5, A4; çıkışı bir NOT kapısından geçip E2'ye gider.
- $\overline{CS}$ ucu olarak 12 numaralı çıkış kullanılmıştır.

### 4.1 Adım adım çözüm

Adresleme A15'ten A0'a kadar gittiği için 16 bitlik bir adres söz konusudur. Bitler dörtlü gruplar halinde yazılır ve her birinin alması gereken değer bulunur.

1. Y12'nin aktif olması için izin uçlarında 0, seçim uçlarında D C B A = 1 1 0 0 olmalıdır. Buradan A9 = 1, A3 = 1, A2 = 0, A0 = 0 bulunur.
2. A1 için devrede hiçbir koşul yoktur; X (serbest) bırakılır.
3. E1 = 0 olması için NOT kapısının girişi 1 olmalıdır. Bu bir NOR çıkışı olduğuna göre bütün girişleri 0 olmalıdır: A15 = A14 = A13 = 0 ve M/$\overline{IO}$ = 0. Yani cihaz G/Ç komutlarıyla çalışır.
4. Aynı mantıkla E2 için A12, A11, A10, A8, A7, A6, A5, A4 = 0 bulunur.

Onaltılık olarak birinci basamak 0, ikinci basamak 2, üçüncü basamak 0'dır; dördüncü basamakta A1'in 0 ya da 1 olmasına göre 8 ya da A elde edilir:

- A1 = 0 → 0208H: veri yazmaçlarına erişim,
- A1 = 1 → 020AH: kontrol yazmaçlarına erişim.

## 5. Örnek 1: sürekli karakter gönderme

Soru: 208H adresinden itibaren ardışık çift adreslere yerleştirilmiş 8251 ile, 8251 hazır olduğu sürece dış dünyaya sabit bir karakter ("A") gönderilsin ve gönderme mantığının nasıl tetiklendiği mantık analizöründe incelensin.

### 5.1 Algoritma

1. 8251 açıldığında hangi durumda olduğundan emin olunamaz. Önce mod yazmacına erişilip asenkron mod ayarlanır.
2. Kontrol yazmacı üzerinden 8251 resetlenir; artık nerede olduğu bilinir.
3. Gerçek mod ve kontrol değerleri yazılır.
4. Durum sözcüğü okunur; TxRDY geldiğinde büyük "A" gönderilir.
5. Bu işlem sonsuz döngüde tekrarlanır.

### 5.2 Kod

Program EXE tipindedir; veri ve yığın kesimleri vardır ama bu örnekte kullanılmaz. Kod kesimi (ekrandan, 00:30:00 ve 00:40:00):

```asm
START:
    MOV AX, DATA
    MOV DS, AX

    MOV DX, 020Ah
    MOV AL, 01001101B
    OUT DX, AL

    MOV AL, 40H
    OUT DX, AL

    MOV AL, 01001101B
    OUT DX, AL

    MOV AL, 00010001B
    OUT DX, AL

ENDLESS:
    MOV DX, 020AH
TEKRAR:
    IN  AL, DX
    AND AL, 01H
    JZ  TEKRAR

    MOV DX, 0208H
    MOV AL, 41H
    OUT DX, AL

    JMP ENDLESS
CODE ENDS
    END START
```

### 5.3 Reset bloğu

Adres ucu 1 iken yapılan ilk erişimin mod yazmacına gideceği bilinir. Burada ne yazıldığı çok önemli değildir; önemli olan son iki bitin 00'dan farklı olmasıdır.

**Soru:** Mod yazmacının son iki biti ne işe yarıyordu? **Cevap:** Baud faktörünü ayarlar. D1 D0 = 00 senkron haberleşme anlamına gelir; senkron modda 8251 senkronizasyon 1 (ve gerekirse senkronizasyon 2) karakterlerini bekler. Asenkron mod seçilirse bir sonraki erişim kontrol yazmacına gider. Bu yüzden D1 D0'ın 00 dışında olması buradaki tek kritik koşuldur.

**Soru:** Kontrol yazmacına 01000000B (40H) yazmanın anlamı nedir? **Cevap:** D6 biti yazılımsal (iç) resettir. Bu iki satırla önce mod yazmacına erişilip asenkron ayar yapılır, ardından C/$\overline{D}$ = 1 ile kontrol yazmacına erişilip reset biti etkinleştirilir; sonuçta 8251 resetlenir.

### 5.4 Asıl ayarlar

Resetten sonra mod yazmacına yine 01001101B yazılır. Bitlerin anlamı (ekrandan, 00:35:00):

| Bitler | Değer | Anlamı |
|--------|-------|--------|
| D7 D6 | 01 | 1 stop biti |
| D5 D4 | 00 | parite yok |
| D3 D2 | 11 | 8 veri biti |
| D1 D0 | 01 | baud faktörü ×1 |

Faktör 1, RxC ve TxC'deki frekansın 1'e bölünüp olduğu gibi kullanılması demektir: $9600\,\text{Hz} / 1 = 9600$ baud. Bu değerler sanal terminaldeki ayarlarla uyumludur.

> **Hocanın vurgusu:** Çalışırken de bu şekilde, yazılan değeri bit bit mod yazmacı tablosuyla karşılaştırarak ilerleyin.

Kontrol yazmacına 00010001B (11H) yazılır:

- D4 (ER) = 1: önceden kalan hata bitleri temizlenir,
- D2 (RxE) = 0: alıcı etkin değil,
- D0 (TxEN) = 1: yalnız gönderici etkin.

Soruda yalnız veri gönderilmesi istendiği için bu ayar yeterlidir.

### 5.5 Sonsuz döngü

41H, ASCII'de büyük "A" karakterinin karşılığıdır. ASCII karakterler 7 bittir (1000001); en yüksek anlamlı bite 0 konunca 8 bitlik 41H elde edilir.

020AH adresinde yazmada kontrol yazmacı, okumada durum sözcüğü vardır (ekrandan, 00:40:00). `IN AL, DX` ile durum sözcüğü okunur ve `AND AL, 01H` ile maskelenir. Durum sözcüğünün en düşük anlamlı biti TxRDY'dir. TxRDY = 1, önceki gönderme işleminin tamamlandığı ve 8086 yeni bir değer yazarsa 8251'in onu göndermeye başlayacağı anlamına gelir.

AND işleminden sonra:

- TxRDY = 0 ise (gönderme sürüyor, 8251 meşgul) sonuç 0'dır, sıfır bayrağı 1 olur ve `JZ TEKRAR` ile tekrar okunur.
- TxRDY = 1 ise sonuç sıfır değildir, sıfır bayrağı 0 olur ve döngüden çıkılır.

Döngüden çıkınca 41H, AL üzerinden 0208H adresine, yani 8251'in Data Out tamponuna yazılır. Veriyi bit bit göndermeyi 8251 kendisi halleder. `JMP ENDLESS` ile başa dönülür; az önce gönderilen karakterin işlemi hâlâ sürüyor olabileceği için bekleme döngüsünde birkaç tur dönülebilir, TxRDY 1'e çıkınca sıradaki "A" gönderilir.

Kod çalıştırıldığında sanal terminalde art arda "A" karakterleri görülür (ekrandan, 00:45:00).

### 5.6 Mantık analizöründe dalga şekli

Mantık analizörünün A0 kanalına TxRDY, A1 kanalına TxD (seri veri çıkışı) bağlıdır. TxRDY'nin 1'e çıktığı anda yeni karakter yazılır ve gönderme başlar. 1 stop biti, parite yok ve 8 veri bitiyle bir karakterin çerçevesi şöyledir (ara adım eklendi):

```text
hat:      idle  start  D0 D1 D2 D3 D4 D5 D6 D7  stop  idle
değer:     1      0     1  0  0  0  0  0  1  0    1     1
```

Önce start biti gider, sonra veri en düşük anlamlı bitinden başlayarak gönderilir. 41H = 0100 0001 olduğu için önce bir tane 1, sonra beş tane 0, sonra 1 ve son olarak 0 gelir. Parite olmadığı için araya bir şey girmez; ardından stop biti (1) gelir. Start bitinden önce ve stop bitinden sonra hat boşta (idle) olduğu için lojik 1'dedir. Analizör ekranında hoca, beş sıfırın her birinin yaklaşık eşit genişlikte olduğunu ve stop bitinden sonra hattın bir süre boşta kaldığını, TxRDY tekrar 1'e çıkınca yeni verinin basıldığını gösterir.

> **Ek bilgi (derste anlatılmadı):** 9600 baud'da bir bit yaklaşık $1/9600 \approx 104\,\mu\text{s}$ sürer. Start, 8 veri ve 1 stop bitiyle bir karakter 10 bit, yani yaklaşık 1.04 ms tutar.

## 6. Örnek 2: gelen karakterin bir sonrakini geri gönderme

İkinci örnekte de 8251 0208H ve 020AH adreslerindedir; sanal terminal 9600 baud, 8 veri biti, parite yok, 1 stop bitiyle çalışır ve RxC/TxC uçlarına 9600 Hz bağlıdır. İstenen: dış dünyadan gelen her karakter için onun bir sonrakini geri basmak. Örneğin terminalde "A" basılırsa "B", "C" basılırsa "D" gelmelidir.

Sanal terminal ekranı hem veri girişi hem veri çıkışı için çalışır: birinci örnekte 8251'in gönderdiği karakterler bu ekranda görülmüştü; bu örnekte ekranda basılan karakterler 8251'e gider.

Hoca, simülasyonun eski sürümlerinde seri olarak alınan verinin yanlışlıkla bir bit fazla ötelendiğini, bu yüzden kodda bir düzeltme satırı bulunduğunu; yeni sürümde hatanın giderildiğini ve o satırın çıkarılabileceğini söyler.

### 6.1 Başlangıç bloğu

Başlangıç bloğu birinci örnekle aynıdır: mod yazmacına son iki biti 00 dışında bir değer, kontrol yazmacına 40H (reset), ardından mod yazmacına 01001101B (1 stop, parite yok, 8 veri biti, faktör ×1).

Fark kontrol sözcüğündedir: 00010101B (ekrandan, 00:50:00).

- D4 (ER) = 1: önceki hata bitleri temizlenir,
- D2 (RxE) = 1: alıcı etkin,
- D0 (TxEN) = 1: gönderici etkin.

Böylece 8251 hem dış dünyaya veri gönderebilir hem de dış dünyadan veri alabilir.

### 6.2 Kod

Kodun görünen kısmı (ekrandan, 00:50:00):

```asm
ENDLESS:
    MOV DX, 020AH
TEKRAR:
    IN  AL, DX
    AND AL, 02H
    JZ  TEKRAR

    MOV DX, 0208H
    IN  AL, DX
    INC AL

    MOV BL, AL

    MOV DX, 020AH
TEKRAR2:
    IN  AL, DX
    AND AL, 01H
    JZ  TEKRAR2

    MOV DX, 0208H
    MOV AL, BL
    OUT DX, AL
    JMP ENDLESS
```

<!-- BELİRSİZ: Karede kod TEKRAR2'deki IN AL, DX satırında kesiliyor; sonraki satırlar (AND AL, 01H ile JMP ENDLESS arası) hocanın anlatımından kuruldu. -->

### 6.3 Durum sözcüğünün iki biti

Durum sözcüğü 02H ile maskelenir. Hoca, bunun yerine TEST komutu ya da iki kez kaydırıp elde bayrağına bakmak gibi yolların da kullanılabileceğini, bunun kod akışında programcıya kalmış olduğunu belirtir.

- D0: TxRDY. 1 olması "veri gönderme tamam" demektir; 8086 Data Out tamponuna yeni değer yazabilir.
- D1: RxRDY. 8251 dış dünyadan veriyi bit bit alır; alma bitince RxRDY 1'e çıkar. 1 olması "veri alma tamam" demektir; 8086 Data In tamponunu okuyabilir.

### 6.4 Akış

1. Birinci blokta RxRDY 1 olana kadar dönülür.
2. RxRDY 1 olunca 0208H'deki Data In tamponu okunur (AL'ye), AL bir artırılır ve geçici olarak BL'de saklanır.
3. İkinci blokta TxRDY 1 olana kadar dönülür.
4. TxRDY 1 olunca artırılmış değer Data Out tamponuna (0208H) yazılır ve sonsuz döngüde başa dönülür.

Hoca örneği şöyle özetler: seri olarak gelen veri, 8251 tamponundaki değer henüz çöpken okunmaz; hazır olana kadar beklenir, hazır olunca okunur. Gönderirken de 8251'deki önceki veri ezilmez; 8251 göndermeye hazır olunca yeni veri yazılır.

### 6.5 Çalıştırma ve bağlantılar

Sanal terminal penceresi bazen hemen etkin olmaz, iki kez tıklamak gerekebilir. Çalıştırıldığında küçük "a" gönderilince "b", büyük "A" gönderilince "B", "N" gönderilince "O" gelir. Karede terminalde "bBB{" dizisi görülür (ekrandan, 00:55:00).

> **Ders sonrası not:** Hoca "Z'yi gönderdiğimde hatalı bir şey geldi" dedi. Karede görülen "{" karakteri, büyük olasılıkla küçük "z" (7AH) gönderildiğini gösterir: 7AH + 1 = 7BH, ASCII'de "{" karakteridir. Program yalnız bir artırma yaptığı için alfabenin sonunda başa dönmez.

Seri haberleşme bağlantısında 8251'in gönderen ucu (TxD) terminalin alan ucuna (RXD), terminalin gönderen ucu (TXD) 8251'in alan ucuna (RxD) bağlanır. Bir taraf için gönderilen veri diğer taraf için alınan veridir; bu yüzden birinin Tx'i diğerinin Rx'ine bağlanır.

## 7. 8254 Programlanabilir Aralık Zamanlayıcısı

Aradan sonra 8251 konusu kapanır ve 8254 entegresine geçilir. Slaytta bu bölümün konuları şöyle listelenir (ekrandan, 01:10:00): 8254 Programmable Interval Timer (PIT), iç yapı ve uç tanımları, kontrol sözcüğü, mod 0-5, Counter Latch komutu, Read-Back komutu ve durum baytı. Hoca, sayma değerinin o anki halinin tutulabildiğini (latch) ve durumun da okunabildiğini, durum baytındaki her bitin görevinin anlatılacağını söyler.

### 7.1 Neden donanım zamanlayıcı?

8254, temelde yazılım denetimli, kesin ve doğru zaman gecikmeleri oluşturmak için kullanılan programlanabilir bir yardımcı devredir (ekrandan, 01:15:00). Yani donanımsal bir zamanlayıcıdır.

Alternatifi gecikmeyi yazılımla üretmektir. Bir fonksiyon yazılır ve içindeki boş döngü sayısından hareket edilir: her komutun kaç saat çevriminde yürütüldüğü ve 8086'nın saat frekansı bilindiği için bir komutun, bir komut bloğunun ve fonksiyon çağırma/dönüş sürelerinin toplamı hesaplanabilir. Fakat bu yöntemin sorunları vardır:

- süre saat frekansına bağlıdır,
- yazılımdaki küçük değişiklikler ya da araya giren kesmeler süreyi uzatır veya değiştirir.

Bu yüzden özel zamanlama işleri için özel bir donanıma ihtiyaç vardır; 8254'ün temel kullanım amacı budur.

8254 ayrıca şu amaçlarla kullanılır: olay sayıcı, gerçek zamanlı saat (real time clock), kare dalga üreteci, karmaşık dalga üreteci ve tek seferlik tetikleme üreten darbe üreteci (digital one shot).

### 7.2 Zamanlayıcı ve sayıcı

> **Hocanın vurgusu:** Sayıcı (olay sayıcı) ve zamanlayıcı iki ayrı kavramdır; birbirinden ayırt etmek gerekir.

8254'te 3 ayrı sayıcı ve her birinin ayrı bir saat girişi vardır. Bir sayıcının saat girişi iki farklı mantıkla kullanılabilir:

- **Zamanlayıcı:** Saat girişine sabit frekanslı bir saat üreteci bağlanır. Örneğin 1 kHz'lik işaret bağlanırsa periyot 1 ms olur; her değişim tam 1 ms'dir. Böylece 1 ms hassasiyetle zamanlama yapılabilir: 1 ms'nin altındaki hassasiyete sahip olunmaz, ama geçen sürenin kaç milisaniye olduğu kesin bulunur. Periyotlar eşittir.
- **Sayıcı (olay sayıcı):** Saat girişine bir olaydan tetiklenen işaret bağlanır. Hocanın örneği bir konveyör banttır: bandın iki yanında karşılıklı bir kızılötesi alıcı ve verici vardır. Ürünlerin birbirini engellemediği, sensörün önünden aynı anda tek ürün ve aralıklı geçtiği varsayılırsa, her ürün geçerken sensörün önü kapanır, ürün geçince alıcı vericiyi yeniden görür; böylece her ürün için bir darbe oluşur. Bu darbeler düzensizdir: uzun süre ürün gelmeyebilir, sonra peş peşe iki ürün geçebilir.

Kısacası sayıcı olarak kullanmak için saat girişine bir sensör çıkışı, zamanlayıcı olarak kullanmak için bir saat üreteci bağlanır.

### 7.3 Temel özellikler

- 8254'te birbirinden bağımsız 3 sayıcı (counter) vardır.
- Sayıcılar 16 bitlik ve programlanabilirdir.
- Her sayıcı 6 farklı moddan birinde çalıştırılabilir.
- Sayıcılar en çok 8 MHz'e kadar saat girişi kabul eder.

### 7.4 Frekans bölücü olarak sayıcı

Hoca, Lojik Devreler dersindeki asenkron sayıcıyı hatırlatır: bir flip-flop'un Q çıkışı ikinci flip-flop'un saat girişine, onun Q çıkışı bir sonrakine bağlanır ve her saat darbesinde Q tümlenir. Bu düzende en baştaki yüksek frekanslı saat her flip-flop geçişinde yarıya bölünür. Flip-flop'un ikiye bölmesinin nedeni bir bitlik sayıcı olmasıdır; yalnız 0 ve 1 değerlerini alabilir.

8254'teki 16 bitlik sayıcı da aynı mantıkla düşünülebilir: içine yüklenen değer neyse giriş frekansını o değere bölen bir frekans bölücü gibi çalışır. 8254 sayıcıları aşağı sayıcıdır (down counter): bir ilk değer yüklenir, sayıcı o değerden geriye doğru sayar ve sayma değeri sıfıra ulaştığında OUT ucunda bir değişikliğe yol açar.

### 7.5 PC'de kullanımı

Slayttaki kullanım alanları (ekrandan, 01:20:00):

- Sistem saati (time of day) için saniyede 18.2 frekanslı işaret üretmek. Hoca pilli BIOS'taki gerçek zamanlı saat yapılarının da bulunduğunu, ama sistem saatini belirlemekte 8254 sayıcılarından birinin kullanılabildiğini söyler.
- 15 µs'de bir dinamik RAM yenileme işareti üretmek.
- Farklı frekanslarda PC hoparlörüyle uyarı sesleri üretmek. Örneğin bilgisayar açılırken RAM eksik ya da bozuksa veya sabit diskte sorun varsa hoparlörden gelen sesler 8254 ile üretilir.

<!-- BELİRSİZ: 01:19:35-01:19:59 arasında altyazı kopuk; sistem saatiyle ilgili sözlü ayrıntı alınamadı, slayt metni kullanıldı. -->

RAM yenilemesinin nedeni şöyle açıklanır: RAM'de her bellek hücresi temelde bir kondansatör ve bir transistörden oluşur. Veri, kondansatörün yük saklama kapasitesinden yararlanarak saklanır; fakat kaçak akımlar yüzünden yük yavaş yavaş azalır. Bu yüzden belli aralıklarla hücredeki değerin yeniden yazılması gerekir. Hoca DDR'nin (Double Data Rate) saat işaretinin hem yükselen hem düşen kenarında çalışabilen bir yapı olduğunu da ekler.

> **Ders sonrası not:** Hoca DDR için "belki bu yenileme frekansı çok daha yüksek anlamına geliyor" dedi. DDR'deki çift kenar, büyük olasılıkla veri aktarım hızıyla ilgilidir; hücrelerin yenileme aralığını doğrudan belirlemez.

## 8. 8254 iç yapısı ve uç tanımları

### 8.1 Her sayıcının uçları

Üç sayıcının her biri için bir CLK girişi, bir OUT çıkışı ve dışarıdan kontrol için bir GATE ucu vardır (ekrandan, 01:25:00):

- **CLK:** Sayıcılar için saat girişi. Zamanlayıcı olarak kullanılıyorsa saat darbesinin, sayıcı olarak kullanılıyorsa sensör çıkışının bağlandığı uçtur.
- **GATE:** Sayıcılar için dış kontrol ucu; sayıcıları dışarıdan kontrol etmeyi ve tetiklemeyi sağlar. Ayrıntısı modlarda görülecektir.
- **OUT:** Sayma işlemi bittiğinde dış dünyaya fiziksel bir işaret gönderir; slayta göre sayma bitince 1 olur ve INTR için kullanılabilir.

OUT ucu 8086'nın kesme isteği (INTR) ucuna bağlanarak kesme isteği oluşturabilir: 8254 belli bir süre sayacak şekilde ayarlanır, süre bitince kesme gelir. Hoca bunun bir kullanım örneği olarak çoklu görevi (multitasking) verir: 8254 örneğin 3 ya da 5 ms'de bir tetikleme gönderir, her tetiklemede görev değiştirilerek (task switching) kullanıcıya çok görevli bir çıktı sunulur.

### 8.2 Veri yolu ve 8086'ya bağlantı

8254'ün D0-D7 veri uçları vardır; yani 8 bitlik bir yardımcı devredir ve şimdiye kadar görülen kurallar onun için de geçerlidir. 8086, bellek arayüzü ×16 olarak düzenlenmişse bir okuma/yazma çevriminde tek adresten 8 bit, çift adresten 8 bit ve çift adresten 16 bit aktarabilir. Bu çerçevede 8254 ya ardışık çift adreslere ya da ardışık tek adreslere yerleştirilir. Hoca, üçüncü bir durumun derste görüldüğünü, ama ek donanım gerektirdiği için ders kapsamı dışında bırakıldığını hatırlatır.

### 8.3 Kontrol uçları ve adres uçları

- $\overline{CS}$: adres çözümleme devresinden gelir.
- $\overline{RD}$, $\overline{WR}$: mikroişlemcinin aynı adlı uçlarına bağlanır ve mikroişlemci açısından tanımlanır. 8086 yazmak isterse $\overline{WR}$'ye, okumak isterse $\overline{RD}$'ye 0 gönderir; uçlar aktif sıfırdır.
- A1, A0: iki adres ucu.

> **Hocanın vurgusu:** 8254'ün iki adres ucu olduğu için 8086'nın adres uzayında 4 baytlık yer kaplar.

Adres uçlarına göre erişim (ekrandan, 01:25:00):

| A1 | A0 | Seçim |
|----|----|-------|
| 0 | 0 | Counter 0 |
| 0 | 1 | Counter 1 |
| 1 | 0 | Counter 2 |
| 1 | 1 | Kontrol yazmacı |

> **Ders sonrası not:** Hoca 00 değeri için "sayıcı 1'e erişmemizi sağlıyor" dedi; slayttaki tabloya göre 00 Counter 0'ı seçer.

## 9. 8254 kontrol sözcüğü

Kontrol sözcüğüne yazmak için cihazın seçilmiş olması ($\overline{CS}$ = 0), yazma yapılması ($\overline{RD}$ = 1, $\overline{WR}$ = 0) ve adres uçlarında 11 bulunması gerekir. Bu durumda 8254'e gönderilen 8 bitlik değer kontrol yazmacına aktarılır (ekrandan, 01:30:00).

```text
 D7    D6    D5    D4    D3   D2   D1   D0
SC1   SC0   RW1   RW0   M2   M1   M0   BCD
```

İki özel durum vardır ve hoca bunları sonraya bırakır: SC1 SC0 = 11 (Read-Back komutu) ve RW1 RW0 = 00 (Counter Latch komutu). Burada genel mod ayarı anlatılır.

### 9.1 SC1 SC0: sayıcı seçimi

En yüksek anlamlı iki bit hangi sayıcıyla işlem yapılacağını belirtir:

| SC1 | SC0 | Anlamı |
|-----|-----|--------|
| 0 | 0 | Counter 0 |
| 0 | 1 | Counter 1 |
| 1 | 0 | Counter 2 |
| 1 | 1 | Read-Back komutu |

### 9.2 RW1 RW0: sayma değerinin kaç bayt gönderileceği

Sayıcılar 16 bitliktir, fakat 8254 ile 8086 8 bit üzerinden anlaşır, çünkü 8254'ün 8 veri biti vardır. RW bitleri sayma değerinin kaç bayt halinde gönderileceğini belirler:

| RW1 | RW0 | Anlamı |
|-----|-----|--------|
| 0 | 0 | Counter Latch komutu |
| 0 | 1 | yalnız düşük anlamlı bayt |
| 1 | 0 | yalnız yüksek anlamlı bayt |
| 1 | 1 | önce düşük, sonra yüksek anlamlı bayt |

Hocanın örnekleri:

- Counter 0'ın 100'den geriye sayması isteniyorsa 100 8 bite sığar; yalnız düşük baytı göndermek yeter, RW = 01.
- 60000 gibi bir değer 8 bite sığmaz, 16 bite sığar; iki paket halinde önce düşük, sonra yüksek bayt gönderilir, RW = 11.
- Yalnız yüksek baytı göndermek (RW = 10), örneğin 256'nın tam katı olan sayma değerleri için kullanılabilir.

### 9.3 M2 M1 M0: mod

D3, D2 ve D1 mod ayarını yapar. Üç bit 8 durum oluşturur ama 6 mod vardır; bu yüzden bazı bitler önemsizdir (X):

| M2 | M1 | M0 | Mod |
|----|----|----|-----|
| 0 | 0 | 0 | Mod 0 |
| 0 | 0 | 1 | Mod 1 |
| X | 1 | 0 | Mod 2 |
| X | 1 | 1 | Mod 3 |
| 1 | 0 | 0 | Mod 4 |
| 1 | 0 | 1 | Mod 5 |

### 9.4 BCD biti: ikili ya da BCD sayma

Son bit, hocanın deyişiyle 8254'ün çalışma mantığını anlamak açısından önemlidir: sayıcıda saklanan değerin ikili mi BCD mi olacağını belirtir. 0 ikili 16 bitlik sayma, 1 BCD (4 basamaklı, "4 decades") sayma demektir.

**İkili mod:** 16 bitlik değer 4 onaltılık basamaktan oluşur. Yazılabilecek en büyük değer bütün bitlerin 1 olduğu FFFFH'dir. Sayıcı birer azalarak gittiği için örneğin 8000H'den sonraki değer 7FFFH olur. Toplamda 65536 farklı değer sayılabilir (ekrandan, 01:35:00).

**BCD modu:** Her 4 ikilik basamak bir BCD basamağını gösterir ve 0'dan 9'a kadar bir ondalık değer taşır. 8 ve 9'u yazabilmek için 4 bit gerekir: 0 → 0000, 1 → 0001, ..., 7 → 0111, 8 → 1000, 9 → 1001.

**Soru:** BCD modunda 16 bitlik sayıcıya yazılabilecek en büyük değer nedir? **Cevap:** 9999. Örneğin sayıcı 8000 (BCD) değerindeyken sonraki değer 7999 olur; yani sayıcı ondalık sayar. Toplamda 10000 adım sayılabilir.

BCD'nin tercih nedeni insanın okumasının kolay olmasıdır; ikili modun tercih nedeni daha geniş bir sayma aralığına erişebilmektir.

## 10. 8254 ayarlama örneği

### 10.1 Bir kontrol sözcüğünün anlamı

Hoca önce bir 8254'e gönderilen kontrol sözcüğünün anlamını soran bir örnek çözer. Değer 0 0 1 1 0 1 1 0'dır (36H):

- SC1 SC0 = 00: Counter 0,
- RW1 RW0 = 11: 16 bitlik sayma değeri, önce düşük sonra yüksek bayt,
- M2 M1 M0 = 011: mod 3,
- BCD = 0: ikili sayma.

### 10.2 98H'den itibaren adres yerleşimi

8254, 98H adresinden itibaren ardışık çift adreslere yerleştirilmiştir; 4 baytlık yer kaplayacağı için adresleri 98H, 9AH, 9CH ve 9EH olur (ekrandan, 01:40:00). Hoca, önce yanlış söylediği bir noktayı düzeltir: bu yerleşim ancak işlemcinin A1 ve A2 uçları sırasıyla 8254'ün A0 ve A1 uçlarına bağlıysa sağlanır. Bu durumda:

| Adres | İşlemci A2 A1 | Birim |
|-------|---------------|-------|
| 98H | 0 0 | Counter 0 (CNTR0) |
| 9AH | 0 1 | Counter 1 (CNTR1) |
| 9CH | 1 0 | Counter 2 (CNTR2) |
| 9EH | 1 1 | Kontrol yazmacı |

### 10.3 Soru metni

Slayttaki soru (ekrandan, 01:40:00):

- CNTR0: ikili sayma, mod 3, CLK0'ı 4282 (BCD)'ye bölecek şekilde ayarlayın.
- CNTR2: ikili sayma, mod 3, CLK2'yi C26A hex'e bölecek şekilde ayarlayın.
- CLK0 = 1.2 MHz, CLK2 = 1.8 MHz ise çıkış frekansları nedir?

Hoca son maddedeki "OUT1"in yanlış yazıldığını, OUT0 olması gerektiğini belirtir (ekrandan, 01:45:00).

### 10.4 Counter 0 ayarı

Kontrol sözcüğü:

- Counter 0 → SC = 00,
- değer 8 bite sığmaz → RW = 11,
- mod 3 → 011,
- ikili → 0.

Sonuç 0011 0110B = 36H. Hoca önce BCD bitini 1 alıp 37H der, sonra ikili sayma için bitin 0 olduğunu hatırlayıp 36H'ye düzeltir.

Sayma değeri ondalık 4282 olarak AX'e yüklenir. Sayıcı ikili sayacağı için değer ondalık sayı olarak verilir; assembler bunu ikiliye çevirir.

```asm
    MOV AL, 36H
    OUT 9EH, AL      ; kontrol yazmacı
    MOV AX, 4282     ; ondalık 4282
    OUT 98H, AL      ; önce düşük bayt
    MOV AL, AH
    OUT 98H, AL      ; sonra yüksek bayt
```

RW = 11 seçildiği için sayıcı önce LSB, sonra MSB bekler; kod bu sırayı sağlar.

> **Ek bilgi (derste anlatılmadı):** Ondalık 4282'nin onaltılık karşılığı 10BAH'dir; yani düşük bayt BAH, yüksek bayt 10H olarak gönderilir.

### 10.5 Counter 2 ayarı

Kontrol sözcüğü:

- Counter 2 → SC = 10,
- değer 8 bite sığmaz → RW = 11,
- mod 3 → 011,
- ikili → 0.

Sonuç 1011 0110B = B6H.

```asm
    MOV AL, 10110110B
    OUT 9EH, AL      ; kontrol yazmacı
    MOV AX, 0C26AH
    OUT 9CH, AL      ; Counter 2, düşük bayt
    MOV AL, AH
    OUT 9CH, AL      ; Counter 2, yüksek bayt
```

### 10.6 Çıkış frekansları

Sayıcı frekans bölücü olarak çalıştığı için çıkış frekansı giriş frekansının sayma değerine bölümüdür.

OUT0 için:

$$f_{OUT0} = \frac{1.2\,\text{MHz}}{4282} = \frac{1\,200\,000}{4282} \approx 280.24\,\text{Hz}$$

Hoca sonucu 280 Hz olarak verir ve birimi onaltılık "H" ile karışmasın diye "Hz" yazar.

> **Ders sonrası not:** Hoca bölmenin tam olduğunu söyledi; 1 200 000 / 4282 tam bölünmez (kalan 1040), sonuç yaklaşık 280.24 Hz'dir (python ile kontrol edildi).

OUT2 için bölen C26AH'dir. Hoca 1.8 MHz'i onaltılığa çevirip C26AH'ye böler ve 24H bulur; 24H = 32 + 4 = 36:

$$f_{OUT2} = \frac{1\,800\,000}{\text{C26A}_{16}} = \frac{1\,800\,000}{49770} \approx 36.17\,\text{Hz}$$

Tam sayı bölümü 36 Hz'dir (python ile kontrol edildi: 1 800 000 = 36 × 49770 + 8280).

Hoca bu bölümün sonunda iki cevabı tekrarlar: BCD modda bir sayıcıya yazılabilecek en büyük değer 9999, ikili modda FFFFH'dir.

### 10.7 Modlara kısa bakış

Hoca modların ayrıntısına süre yetmediği için girmez; yalnız genel bir çerçeve verir: bazı modlar GATE ucundan dışarıdan tetiklenebilir (yeniden başlatılabilir ya da durdurulabilir), bazıları tekrarlı, bazıları tek seferlik işaret üretir. Modların ayrıntısına girilirse konu yarıda kalacağı için ders burada bitirilir.

> **Ders sonrası not:** Hoca bu bölümde "5 tane modumuz var" dedi; slayttaki tabloda ve dersin başındaki anlatımda olduğu gibi 8254'te mod 0'dan mod 5'e kadar 6 mod vardır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00 ve 00:20:00): 208H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8251'i 8086 ile arabirimlemek için adres çözümleme devresini 74HC154 (4'e 16 kod çözücü) ile tasarlayın.

Çözüm (derste verildi):

- Adresler 0208H ve 020AH'dir (210H değil).
- Koşullar: A15-A10, A8-A4, A2, A0 = 0; A9 = A3 = 1; M/$\overline{IO}$ = 0; A1 serbest.
- A15-A10, A8-A4 ve A2 bir OR kapısından E1'e; A0 ve M/$\overline{IO}$ ikinci bir OR kapısından E2'ye verilir.
- A9 → D, A3 → C, B ve A → toprak. DCBA = 1100 = 12, Y12 → 8251 $\overline{CS}$.
- A1 → 8251 C/$\overline{D}$.

**Soru 2** (derste sözlü, 00:12:33): 208H'den sonraki adres yanlışlıkla 210H yazılırsa hata nasıl fark edilir?

Çözüm (derste verildi): 0208H ve 0210H'nin ikilik açılımında iki bit (A4 ve A3) değişir. İki bitin değişmesi 4 baytlık bir alan demektir; 8251 yalnız 2 bayt kapladığından adres hatalıdır. Doğrusu 020AH'dir; burada yalnız A1 değişir.

**Soru 3** (ekrandan, 00:25:00): Proteus'taki devrede 74HC154'ün seçim uçlarına A0, A2, A3, A9 (A'dan D'ye); E1'e NOT(NOR(A15, A14, A13, M/$\overline{IO}$)); E2'ye NOT(NOR(A12, A11, A10, A8, A7, A6, A5, A4)) bağlıdır ve $\overline{CS}$ Y12'den alınmıştır. 8251'in adreslerini bulun.

Çözüm (derste verildi): Y12 için DCBA = 1100 → A9 = 1, A3 = 1, A2 = 0, A0 = 0. NOR çıkışlarının 1 olması için bütün girişleri 0 olmalıdır. A1 serbesttir. Adresler 0208H (veri) ve 020AH (kontrol/durum).

**Soru 4** (derste sözlü, 00:30:44): 8251 mod yazmacının son iki biti (D1 D0) ne işe yarar, başlangıçta neden 00'dan farklı olmalıdır?

Çözüm (derste verildi): Baud faktörünü belirler. 00 senkron mod demektir ve 8251 senkronizasyon karakterlerini bekler. Asenkron mod seçilirse bir sonraki yazma kontrol yazmacına gider; reset komutunun kontrol yazmacına ulaşması için bu gerekir.

**Soru 5** (derste sözlü, 00:32:17): 8251 kontrol yazmacına 01000000B yazmanın anlamı nedir?

Çözüm (derste verildi): D6 iç (yazılımsal) reset bitidir; 8251 resetlenir.

**Soru 6** (ekrandan, 00:30:00 ve 00:40:00): 0208H/020AH adreslerindeki 8251 ile, 8251 hazır olduğu sürece sürekli "A" karakteri gönderen programı yazın ve mod/kontrol sözcüklerini açıklayın.

Çözüm (derste verildi): Kod Bölüm 5.2'dedir. Mod sözcüğü 01001101B: 1 stop, parite yok, 8 veri biti, ×1. Kontrol sözcüğü 00010001B: hata temizle, yalnız gönderici etkin. Döngüde durum sözcüğünün D0 (TxRDY) biti beklenir, ardından 41H 0208H'ye yazılır.

**Soru 7** (derste sözlü, 00:44:50): 41H, 1 stop biti, parite yok ve 8 veri bitiyle gönderilirken TxD ucundaki dalga şekli nasıldır?

Çözüm (derste verildi): idle 1 → start 0 → LSB önce 1, 0, 0, 0, 0, 0, 1, 0 → stop 1 → idle 1.

**Soru 8** (ekrandan, 00:50:00): Dış dünyadan gelen her karakterin bir sonrakini geri gönderen programı yazın.

Çözüm (derste verildi): Kontrol sözcüğü 00010101B (hata temizle, RxE, TxEN). RxRDY (D1, `AND AL, 02H`) beklenir, 0208H okunur, `INC AL`, BL'de saklanır; TxRDY (D0) beklenir, BL 0208H'ye yazılır. Kod Bölüm 6.2'dedir.

**Soru 9** (derste sözlü, 01:34:26): 8254'te BCD modunda 16 bitlik sayıcıya yazılabilecek en büyük değer nedir? İkili modda nedir?

Çözüm (derste verildi): BCD'de 9999 (10000 adım), ikili modda FFFFH (65536 farklı değer).

**Soru 10** (derste sözlü, 01:36:17): 8254'ün kontrol yazmacına 00110110B yazılırsa ne olur?

Çözüm (derste verildi): Counter 0 seçilir, sayma değeri 16 bit olarak önce düşük sonra yüksek bayt beklenir, mod 3, ikili sayma.

**Soru 11** (ekrandan, 01:40:00): 98H adresinden itibaren ardışık çift adreslere yerleştirilmiş 8254 için: CNTR0 ikili sayma, mod 3, CLK0'ı 4282 (BCD)'ye bölecek; CNTR2 ikili sayma, mod 3, CLK2'yi C26A hex'e bölecek şekilde ayarlayın. CLK0 = 1.2 MHz, CLK2 = 1.8 MHz ise OUT0 ve OUT2 frekansları nedir?

Çözüm (derste verildi; frekanslar python ile kontrol edildi):

- Adresler: 98H CNTR0, 9AH CNTR1, 9CH CNTR2, 9EH kontrol.
- CNTR0: kontrol sözcüğü 36H → 9EH; ondalık 4282 önce düşük, sonra yüksek bayt olarak 98H'ye.
- CNTR2: kontrol sözcüğü B6H → 9EH; C26AH önce düşük, sonra yüksek bayt olarak 9CH'ye.
- $f_{OUT0} = 1\,200\,000 / 4282 \approx 280.24$ Hz (hoca 280 Hz dedi).
- $f_{OUT2} = 1\,800\,000 / 49770 \approx 36.17$ Hz (hoca 24H = 36 Hz buldu).

## Dersin Toparlaması

Dersin ilk yarısında 8251 konusu iki Proteus örneğiyle kapatıldı. 208H'den itibaren ardışık çift adreslere yerleştirilen 8251 için adres çözümleme devresi önce sıfırdan tasarlandı, sonra verilen devreden adres geri çıkarıldı; iki adres arasında yalnız bir bitin değişmesi gerektiği ve A1'in 8251'in C/$\overline{D}$ ucuna gittiği vurgulandı. Ardından 8251'i bilinen duruma getirme sırası (mod → reset → mod → kontrol), TxRDY ile sürekli gönderme ve RxRDY/TxRDY ile alıp bir artırarak geri gönderme programları incelendi; mantık analizöründe asenkron seri çerçeve (start, LSB önce veri, stop) gösterildi.

İkinci yarıda 8254 Programlanabilir Aralık Zamanlayıcısına giriş yapıldı: donanım zamanlayıcının neden gerektiği, zamanlayıcı ile olay sayıcı farkı, üç bağımsız 16 bitlik aşağı sayıcı, CLK/GATE/OUT uçları, 4 baytlık adres yerleşimi ve kontrol sözcüğünün bit alanları. Örnekte sayıcıların frekans bölücü olarak programlanması ve çıkış frekanslarının hesabı görüldü. 8254'ün altı modunun ayrıntısı, Counter Latch ve Read-Back komutları ile durum baytı sonraki derslere kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
