# Ders 12 Genişletilmiş Notu: 8255 Mod 0 Uygulamaları, BSR Modu ve Mod 1 El Sıkışma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arayüzler dokümanı ve 8255 kontrol yazmacı tekrarı
- 2. 8255'i adres uzayına yerleştirmek
- 3. 4 buton, 4 LED örneği
- 4. Yedi parçalı gösterge
- 5. Tuş takımı (keypad)
- 6. 8255 modlarına genel bakış: mod 0, mod 1, mod 2
- 7. BSR modu ve kare dalga örneği
- 8. Mod 1: el sıkışmalı G/Ç
- Örnek Sorular
- Dersin Toparlaması

## 1. Arayüzler dokümanı ve 8255 kontrol yazmacı tekrarı

Ders, önceki derste başlanan 8255 örneklerinin tekrarıyla açılır. Bu bölümde kullanılan temel kaynak "arayüzler" adlı bir PDF'tir. Bu doküman derste kullanılan entegrelerin bit düzenlerini, kontrol kelimelerini, bacak bağlantılarını ve gerekli yerlerde adım adım programlama akışlarını özetler. Hoca, bit anlamlarını ezberlemeye gerek olmadığını, dokümanı doğru okumanın yeterli olduğunu vurguladı.

Ekranda gösterilen ilk sayfada şu tablolar vardır (ekrandan, 00:15:00):

- 8255 adresleme tablosu,
- 8255 bit set/reset (BSR) mod kontrol yazmacı,
- 8255 basit G/Ç (mod 0) kontrol yazmacı,
- 8255 mod 1 grup A ve grup B kontrol yazmaçları, mod 1 giriş ve çıkış blok şemaları,
- 8255 mod 2 kontrol yazmacı, blok şeması ve durum kelimesi,
- mod 1 giriş ve çıkış durum (status) kelimeleri,
- 8255 ve 8086 bacak şemaları, 8086 bayrak yazmacı.

### 1.1 8255 adresleme

8255'in iki adres ucu (A1, A0) dört iç birimden birini seçer (ekrandan, 00:15:00):

| A1 | A0 | Seçilen |
|----|----|---------|
| 0 | 0 | Port A |
| 0 | 1 | Port B |
| 1 | 0 | Port C, durum |
| 1 | 1 | Kontrol |

Hocanın örneğinde 8255, 80H adresine yerleştirilmiştir. 8086'nın veri yolunun düşük baytını kullandığı için yalnız çift adresler kullanılır: 80H port A, 82H port B, 84H port C, 86H kontrol yazmacıdır (ekrandan, 00:20:00). 86H adresine bir veri göndermek entegreyi programlamak anlamına gelir; bu, yazılımla yapılan bir tür donanım programlamadır.

### 1.2 Kontrol yazmacının iki biçimi

Kontrol yazmacına gönderilen 8 bitlik kelimenin anlamı en anlamlı bite (D7) göre değişir.

**D7 = 0: bit set/reset (BSR) modu.** Bu biçimde yalnız port C'nin tek bir pini 1 ya da 0 yapılır (ekrandan, 00:15:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 0 | X | X | X | $B_2$ | $B_1$ | $B_0$ | S/R |

D6-D4 önemsizdir. D3-D1, port C'nin hangi pininin seçileceğini ikilik olarak verir. D0 = 1 seçilen pini set eder (1), D0 = 0 reset eder (0).

Hocanın örneği: PC3'ü 1 yapmak. Pin numarası 3 = 011, S/R = 1, önemsiz bitler 0 alınırsa kelime `0000 0111` = 07H olur. Bu değer kontrol adresine (86H) gönderilince PC3 ucundan 1 alınır.

**D7 = 1: mod seçimi.** Hoca, laboratuvarda da en çok kullanılan modun mod 0 olduğunu belirtti. Mod 0 kontrol kelimesi şöyledir (ekrandan, 00:15:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 1 | 0 | 0 | PA | $PC_U$ | 0 | PB | $PC_L$ |

Yön bitlerinde 1 giriş, 0 çıkış demektir. 8255'in içinde iki kontrol birimi vardır:

- **Grup A:** port A ile port C'nin üst yarısını (PC7-PC4) kontrol eder. Modu D6D5 ile seçilir: 00 mod 0, 01 mod 1, 1X mod 2.
- **Grup B:** port B ile port C'nin alt yarısını (PC3-PC0) kontrol eder. Modu D2 ile seçilir: 0 mod 0, 1 mod 1. Grup B'nin mod 2'si yoktur; grup A'nın iki mod biti olmasının nedeni budur.

Örneğin mod 0'da D4 = 1 verilirse port A'nın bütün pinleri giriş olarak tanımlanır ve oradan veri okunur.

## 2. 8255'i adres uzayına yerleştirmek

Hoca bu konuyu 8086 dersinin "kesinlikle anlaşılması gereken en önemli konusu" olarak niteledi. 8086 mimarisi adres uzayındaki bir birime erişim üzerine kurulmuştur: önce adres verisiyle o adresteki entegre seçilir, adres mandallanır, sonra veri, adresin etkinleştirdiği entegreye gönderilir.

> **Hocanın vurgusu:** Bir entegreyi adres uzayına yerleştirmek, 8086 dersinin anlaşılması gereken en önemli konusudur.

### 2.1 Demo kart: adres ve veri yolunun ayrılması

Örnek, Proteus'taki "8086 Demo Board" şeması üzerinde incelendi (ekrandan, 00:25:00). Sol tarafta 8086 (U1) vardır; saat devresi modelin içinde tanımlıdır, ayrıca osilatör tasarlamak gerekmez. Mavi kalın çizgiler yolları (bus) gösterir: AD0-AD15 adres/veri yolu, AD16-AD19 yalnız adres bitleridir. Yollar, şemada kabloların karmaşık görünmemesi için kullanılır.

Üç adet 74273 entegresi (U6, U7, U10) mandal (latch) görevi görür. Bunların saat girişi ALE'den (bir DEĞİL kapısı üzerinden) sürülür ve çıkışları A0-A19 adres yolunu oluşturur.

Mandalın neden gerektiği şöyle açıklandı: 8086'da adres ve veri aynı bacakları paylaşır. İşlemci önce adresi gönderir ve ilgili birimi seçer. Ardından aynı bacaklardan veri gönderilir. Adres bir yerde tutulmazsa yeni gelen veri adresin üzerine yazılır ve başka bir adres bölgesi seçilir. ALE durumu değiştiğinde mandal ilk gelen değeri (adresi) tutar; böylece adres yolunda adres sabit kalırken veri yolunda yeni veri güncellenir.

### 2.2 Tersten gitmek: şemadan adres çıkarma

Önce bağlantı şemasından adres çıkarıldı (ekrandan, 00:25:00 ve 00:30:00). Bağlantılar:

| 74LS137 ucu | Bağlı sinyal | Gereken değer |
|---|---|---|
| A (LSB) | A5 | 1 |
| B | A6 | 1 |
| C (MSB) | A7 | 0 |
| E1 (etkin yüksek) | A0'ın değili | A0 = 0 |
| E2 (etkin düşük) | $M/\overline{IO}$ | 0 (G/Ç) |
| üçüncü etkinleştirme ucu (etkin düşük) | A4 VEYA A3 | A3 = A4 = 0 |
| Y3 (etkin düşük çıkış) | $\overline{CS8255}$ | 0 |

8255 tarafında CPU'nun A1 ucu 8255'in A0'ına, CPU'nun A2 ucu 8255'in A1'ine bağlıdır (ekrandan, 00:25:00).

Akıl yürütme adım adım şöyledir:

1. $\overline{CS}$ etkin düşüktür, yani 8255'in seçilmesi için Y3 çıkışından 0 gelmelidir.
2. 74LS137 "kabarcıklı" (etkin düşük çıkışlı) bir kod çözücüdür: seçilen çıkıştan 0, diğerlerinden 1 çıkar. Y3'ün seçilmesi için C B A = 011 olmalıdır. Hoca bunu tahtada A8...A0 dizisinin altına yazdı: A7 = 0, A6 = 1, A5 = 1 (ekrandan, 00:30:00).
3. Kod çözücü etkin değilse girişlerin önemi yoktur; bütün çıkışlar 1 kalır. Bu yüzden etkinleştirme uçları da incelenir. E1'e A0'ın değili gelir ve bu ucun 1 olması gerekir; demek ki A0 = 0 olmalıdır.
4. $M/\overline{IO}$ ucu, isolated G/Ç kullanıldığında bellek (1) ile G/Ç (0) erişimini ayırır. Burada bir çevre birimi seçildiği için bu ucun 0 olması gerekir. Bu uç adres uzayında değildir, ama kod çözücüyü kontrol eder.
5. A3 ve A4 bir VEYA kapısından geçip etkin düşük uca gider; çıkışın 0 olması için ikisi de 0 olmalıdır.
6. Kalan A2 ve A1, 8255'in port seçme uçlarıdır: 00 port A, 01 port B, 10 port C, 11 kontrol.

Sonuç olarak A7-A0 = `0110 0xx0` olur:

| A2 A1 | Adres | Birim |
|---|---|---|
| 00 | 60H | Port A |
| 01 | 62H | Port B |
| 10 | 64H | Port C |
| 11 | 66H | Kontrol |

Bu adresler python ile 00H-FFH aralığı taranarak doğrulandı; koşulları yalnız bu dört adres sağlar.

> **Ek bilgi (derste anlatılmadı):** Gerçek 74LS137'de 4 numaralı uç (LE) büyük olasılıkla bir adres mandalı izin ucudur; LE = 0 iken giriş geçirgen, LE = 1 iken son adres tutulur. Derste bu uç bir etkinleştirme ucu gibi ele alındı ve A3 = A4 = 0 istendi; bu koşulda kod çözücü girişleri geçirgen kalır ve sonuç değişmez. Adres yalnız A0-A7'den çözüldüğü için üst bitler (A8-A15) büyük olasılıkla önemsiz kabul edilmektedir.

### 2.3 Düzden gitmek: adresten devre tasarlamak

"8255'i 60H adresine yerleştirin" denirse bu devre tek çözüm değildir. Hoca örnek olarak kod çözücü girişlerine farklı adres bitleri (ör. A4, A5) bağlanıp başka bir çıkıştan (ör. Y4) $\overline{CS}$ alınabileceğini, VEYA kapısına giden bitlerin de değiştirilebileceğini, bazı durumlarda ek bir DEĞİL kapısı gerekebileceğini söyledi. <!-- BELİRSİZ: hocanın sözlü verdiği alternatif bağlantının bit ataması altyazıda net değil; karede çizimi yok. -->

Kod çözücü kullanmak, VE kapılarıyla lojik devre kurmaktan daha pratiktir: birden fazla adres biti tek entegrede değerlendirilir. VE kapılarının çoğu iki, bazıları üç girişlidir; daha fazla girişli kapı bulunmadığı için birden çok kapıyı birleştirmek gerekir.

> **Hocanın vurgusu:** Tasarımda dikkat edilecek tek nokta, entegrenin yalnız istenen adreste seçilmesidir. 60H istendiği halde devre 80H'de ya da 90H'de de entegreyi seçiyorsa çözüm doğru değildir.

## 3. 4 buton, 4 LED örneği

### 3.1 Devre

Aynı adres çözme devresiyle 60H-66H'ye yerleşmiş 8255'in port C'sine butonlar ve LED'ler bağlıdır (ekrandan, 00:35:00 ve 00:40:00):

- PC0-PC3: pull-up dirençlerle +5 V'a bağlı, diğer ucu toprağa giden 4 buton,
- PC4-PC7: 4 LED (D1-D4).

Pull-up yapıda butona basılmadığında uca +5 V (1) gelir. Butona basılınca akım kolay yolu tercih edip toprağa gider ve uç 0'a düşer. Bu yüzden program, ucun 0'a düştüğü anı kontrol etmelidir; butona basıldığını gösteren anlamlı veri 0'dır.

### 3.2 Kontrol kelimesi

Port C'nin alt yarısı (butonlar) giriş, üst yarısı (LED'ler) çıkış olmalıdır; mod 0 kullanılır. Bit set/reset değil mod seçimi yapılacağı için D7 = 1'dir. Hoca, yalnız "PC5'teki LED'i yak" gibi tek bir pinlik bir iş istenseydi BSR'nin de kullanılabileceğini, ama burada bir giriş/çıkış düzeni kurulduğu için mod seçiminin gerektiğini söyledi.

Hoca kelimeyi MSB'den başlayarak kurdu; port A ve port B bu örnekte kullanılmadığı için farkı göstermek amacıyla port A'yı giriş, port B'yi çıkış seçti:

| Bit | D7 | D6 D5 | D4 (PA) | D3 ($PC_U$) | D2 | D1 (PB) | D0 ($PC_L$) |
|---|---|---|---|---|---|---|---|
| Değer | 1 | 00 | 1 (giriş) | 0 (çıkış) | 0 | 0 (çıkış) | 1 (giriş) |

Kelime `1001 0001` = 91H olur. Programda ise 81H (`1000 0001`) kullanılmıştır; bu da port C üst çıkış, alt giriş düzenini kurar, yalnız port A çıkıştır.

Simülasyonda Proteus'un uç renkleri gözlendi: kırmızı 1 (+5 V), mavi 0 seviyesini gösterir. 91H gönderildiğinde port A giriş, port B çıkış olarak farklı seviyelerde görüldü; 81H'ye dönülünce port A'nın durumu değişti.

### 3.3 Program

Programın kodu ekranda okunmuştur (ekrandan, 00:45:00):

```asm
CODE    SEGMENT PUBLIC 'CODE'
        ASSUME CS:CODE

START:
        MOV AL, 81H
        OUT 66H, AL
        MOV AL, 0FFH
        out 64H, AL
        ; Write your code here
ENDLESS:
        IN AL, 64H
        OR AL, 0F0H
        CMP AL, 0FFH
        JZ ENDLESS
        MOV CL, 4
        SHL AL, CL
        OUT 64H, AL
        JMP ENDLESS
CODE    ENDS
        END START
```

Adım adım akış:

1. `MOV AL, 81H` / `OUT 66H, AL`: kontrol yazmacına mod 0 ve yön bilgisi yazılır.
2. `MOV AL, 0FFH` / `OUT 64H, AL`: port C'ye FFH yazılır; amaç LED'leri yakmaktır.
3. `IN AL, 64H`: port C okunur; anlamlı kısım, giriş olarak ayarlanan alt yarıdır (butonlar).
4. `OR AL, 0F0H`: üst dört bit 1 yapılır. F0H'nin alt yarısındaki 0'lar VEYA işleminde hiçbir şeyi değiştirmez; alt yarı butonların okunan değeri olarak kalır.
5. `CMP AL, 0FFH` / `JZ ENDLESS`: hiçbir butona basılmadıysa alt yarı da F'dir (pull-up), AL = FFH olur ve döngü başa döner. Bu döngü "butona basıldı mı" denetimidir.
6. Basıldıysa `MOV CL, 4` / `SHL AL, CL`: AL dört kez sola kaydırılır; buton bitleri LED bitlerinin yerine geçer.
7. `OUT 64H, AL`: yeni değer port C'ye yazılır; basılan butona karşılık gelen LED söner. Sonra döngüye dönülür.

**Soru:** `OR AL, 0F0H` ne işe yarıyor? (Bir öğrenci hangi butona basıldığını anlamak için olduğunu önerdi.) **Cevap:** F0H üst yarıyı 1'ler; böylece yanan LED'lerin değeri karşılaştırmayı bozmaz ve kaydırmadan sonra basılmayan butonlara karşılık gelen LED'ler yeniden yanar. Döngü tekrar ettiği için bir önceki turda sönmüş bir LED de böylece tekrar yakılmış olur.

**Soru:** `CMP AL, 0FFH` ile ne kontrol ediliyor? Bir öğrenci "lambaların hepsi yanıksa başa dönüyor" dedi. **Cevap:** Eksik: lambaların hepsi yanık **ve** hiçbir butona basılmamışsa başa döner. Butona basılmadığında alt yarı +5 V'a bağlı olduğu için F'dir; üst yarı da F olduğundan AL = FFH olur.

**Soru:** AL dört kez sola kaydırılınca ne olur? Bir öğrenci "alt ve üst dörtlülerin yer değiştirmesi gerekmiyor mu" diye sordu. **Cevap:** Evet; alt yarıdaki buton deseni üst yarıya taşınır. Sağdaki bitler (üst yarı) LED çıkışları, alttakiler buton girişleridir; basılan butonun 0'ı, karşısındaki LED'i söndürür.

Hocanın sayısal örneği (ara adımlar eklendi):

- Butonlardan alt yarı `1011` okunsun (PC2'deki butona basılmış).
- `OR AL, 0F0H` sonrası AL = `1111 1011` = FBH. FFH olmadığı için döngüden çıkılır.
- `SHL AL, 4` sonrası AL = `1011 0000` = B0H.
- Port C'ye B0H yazılır: PC7, PC5, PC4 = 1, PC6 = 0; PC6'daki LED söner.

Simülasyonda butona basıldığında ilgili LED söndü; buton bırakıldığında program yine döngüde döndü ve F0H ile VEYA yapıldığı için LED'lerin durumu aynen kaldı.

## 4. Yedi parçalı gösterge

### 4.1 Ortak anot ve ortak katot

Yedi parçalı göstergenin içinde diyotlar (LED'ler) vardır. Diyotun anot ve katot uçları vardır; ortak anotlu yapıda bütün diyotların anotları, ortak katotlu yapıda katotları birleştirilmiştir (ekrandan, 00:50:00).

- Ortak anotlu göstergenin çalışması için ortak uca 1 verilmelidir. Bir parçayı yakmak için o parçanın ucuna 0 verilir; söndürmek istenen parçalar 1'lenir.
- Ortak katotlu göstergenin çalışması için ortak uca 0 verilmelidir. Yakmak istenen parçaya 1 verilir.
- Ortak uç doğru seviyede değilse parçalara ne verilirse verilsin bir şey görünmez. Proteus'ta bu, mantık durum kaynaklarıyla gösterildi.

Parçalar a, b, c, d, e, f, g ve nokta (h) olarak adlandırılır.

### 4.2 Kodlama

Hoca önce a'yı en anlamlı bit kabul ederek "3" rakamını kodladı: 3 yazmak için e ve f sönük kalmalı, nokta (h) da söndürülebilir; ortak anotta bu üç parça 1'lenir ve `0000 1101` elde edilir. Ardından sırayı düzeltti: en anlamlı bit h, en anlamsız bit a'dır.

> **Ders sonrası not:** Hoca sırayı düzelttikten sonra "3" için "D0H" dedi. h = D7, a = D0 sırasında e, f, h'nin 1 olduğu kelime `1011 0000` = B0H'dir; `0000 1101` dizisinin bitleri ters çevrilir, yarım baytlar yer değiştirmez (python ile doğrulandı).

"0" rakamı için ortadaki g parçası ve nokta sönük kalmalıdır:

| Rakam | Yanan parçalar | Ortak anot | Ortak katot |
|---|---|---|---|
| 0 | a, b, c, d, e, f | C0H (`1100 0000`) | 3FH (`0011 1111`) |
| 3 | a, b, c, d, g | B0H (`1011 0000`) | — |

(3 için ortak anot değeri ders sonrası düzeltmedir; 0 değerleri derste verildi ve python ile doğrulandı.)

Aynı rakam için iki mimaride farklı değer gönderilmesi gerekir; yani mikroişlemciden 8255'e gidecek veri gösterge tipine göre değişir.

### 4.3 Demo kartta 7 segment sürme

Demo kartta ortak anotlu gösterge doğrudan +5 V'a bağlı ve parçaları port B'ye (PB0-PB7) bağlıdır (ekrandan, 00:55:00). Adresleme aynıdır (60H-66H). Port B çıkış olmalıdır; port A ve C'nin durumu bu iş için önemsizdir.

Programda rakam kodları veri bölütünde `DB` ile bir tablo olarak yazılmıştır; bu yüzden önce veri bölütü (DS) ayarlanır. Ardından:

- 80H kontrol yazmacına (66H) gönderilir: mod seçimi, mod 0, bütün portlar çıkış.
- Port A'ya (60H) F0H, port C'ye (64H) FFH yazılır; bunlar yalnız uçlardaki seviyelerin gözlenmesi içindir.
- Tablodan alınan C0H port B'ye (62H) yazılır; ortak anotta g ve nokta söner, göstergede 0 görünür.

<!-- BELİRSİZ: 7 segment programının kodu karede görünmüyor; adımlar altyazıdan kuruldu. -->

## 5. Tuş takımı (keypad)

### 5.1 Tarama mantığı

Tuş takımları da klavye gibi sütundan sürülür, satırdan okunur. Bir satırdaki tuşlar farklı sütunlara aittir; hangi sütun etkin seviyeyle sürülüyorsa o satırdan okunan değer o sütundaki tuşa aittir. Bu yüzden sütunlar belli bir sırayla (bir döngü içinde) sürülür ve her adımda satırlar okunur; okunan satır ile o anda sürülen sütun birlikte hangi tuşa basıldığını belirler.

- **Pull-up dirençli yapı:** satır uçlarına sürekli 1 gelir. Sütun 0 ile sürülür; tuşa basılınca +5 V tuş üzerinden 0'a çekilir ve satırda 0 okunur. Anlamlı değer 0'dır.
- **Pull-down dirençli yapı:** satırlarda sürekli 0 vardır. Sütun 1 ile sürülür; tuşa basılınca bağlantı kurulur ve satırda 1 okunur.

Hoca pull-down örneğinde, sütunlar `010` deseniyle sürülürken ilgili satırın 1 olup olmadığına bakılarak 5 tuşunun denetlenebileceğini söyledi.

### 5.2 Demo kart bağlantısı

Demo kartta 4x3'lük bir tuş takımı vardır (ekrandan, 01:00:00):

- Sütunlar (1-4-7-*, 2-5-8-0, 3-6-9-#) port A'nın PA0-PA2 uçlarından sürülür; PA0 sağ sütuna (3), PA1 orta sütuna (2), PA2 sol sütuna (1) gider.
- Satırlar (A: 1-2-3, B: 4-5-6, C: 7-8-9, D: *-0-#) pull-up dirençlerle +5 V'a bağlıdır ve PC0-PC3'e gider.

Port A çıkış, port C'nin alt yarısı giriş olmalıdır. Port A yarım olarak programlanamadığı için bütünüyle çıkış yapılır. Örneğin port A'ya `1111 1101` sürülürse yalnız orta sütun 0'dır; bu durumda 2, 5, 8 ya da 0'a basıldığı port C okunarak anlaşılır. Sol sütun 0 ile sürülürse basılan tuşlar 1, 4, 7 ya da * olarak yorumlanır.

### 5.3 Program

Programın akışı altyazıdan şöyle kuruldu:

```asm
        MOV AL, 81H
        OUT 66H, AL      ; PA çıkış, PC alt giriş, mod 0
        MOV BL, 00H      ; BL sıfırlanır
        MOV AL, 0FDH
        OUT 60H, AL      ; yalnız orta sütun 0 ile sürülür
ENDLESS:
        IN  AL, 64H      ; satırları oku
        TEST AL, 02H     ; PC1 (B satırı) denetlenir
        ...              ; tuşa basıldıysa TUSVAR'a gidilir, yoksa döngü sürer
TUSVAR:
        MOV BL, 0FFH
```

<!-- BELİRSİZ: keypad programının kodu karede görünmüyor; atlama komutları ve etiket adları altyazıdan tahmin edilemedi, yalnız anlatılan komutlar yazıldı. -->

- 81H: yalnız port C'nin alt yarısı giriş, diğerleri çıkış, mod 0.
- FDH = `1111 1101`: yalnız PA1 = 0, yani orta sütun sürülür.
- `TEST AL, 02H`: AL ile `0000 0010` arasında VE işlemi yapar, sonucu saklamaz, yalnız bayrakları günceller. Burada PC1'in, yani B satırının 0 olup olmadığı denetlenir. Orta sütun ile B satırının kesiştiği tuş 5'tir.

**Soru:** Bu yapı neyi kontrol ediyor? **Cevap:** Bir öğrencinin doğru cevabıyla: 5 tuşuna basılıp basılmadığını. Basıldıysa program sonsuz döngüden çıkıp "tuş var" etiketli alt koda gider ve BL'ye FFH yazar.

Simülasyon adım adım (debug) çalıştırıldı: başlangıçta BX = 0000H ve tuşa basılmadığı için program aşağı inmez. 5'e basılınca kontrol sağlanır, program etikete atlar ve BX'in düşük baytı FFH olur. Debug modunda tuş basılı tutulduğu sürece atlama tekrarlanır.

> **Ek bilgi (derste anlatılmadı):** `TEST` komutu büyük olasılıkla bilinen haliyle `AND` gibi bitleri karşılaştırır ama hedef işleneni değiştirmez; yalnız ZF, SF, PF bayraklarını ayarlar (CF ve OF sıfırlanır). Pull-up yapıda basılı tuşun biti 0 olduğu için `TEST AL, 02H` sonrası ZF = 1 olması büyük olasılıkla "tuşa basıldı" anlamına gelir.

## 6. 8255 modlarına genel bakış: mod 0, mod 1, mod 2

- **Mod 0 (basit G/Ç):** herhangi bir kontrol mekanizması yoktur. Veri gönderilir ya da okunur; karşı tarafın veriyi alıp almadığı, bir önceki verinin gidip gitmediği denetlenmez. Port A, B ve C giriş ya da çıkış olarak ayarlanır.
- **Mod 1 (el sıkışmalı G/Ç):** port A ve port B için el sıkışma (handshake) yapılır. Port A veri gönderdiyse karşı taraftan "alındı" sinyali gelmeden yeni veri göndermez; port B veri alıyorsa veri akışı bitmeden yeni veri almaz, "aldım" sinyalini gönderdikten sonra yeni veri talep eder. Port C, bu el sıkışma ve kesme sinyallerini taşır. Bir port ya okuma ya yazma yapar; port A'dan okuma yapılıyorsa port A'dan yazma yapılamaz.
- **Mod 2 (çift yönlü G/Ç):** el sıkışma burada iki yönlüdür ve yalnız port A için kullanılabilir; port A hem okuma hem yazma yapar. Port B ayrıca mod 0 ya da mod 1 olarak programlanabilir. Port C yine el sıkışma sinyallerini içerir.

Kontrol kelimesinde grup A'nın iki mod biti vardır: `10` ya da `11` yazılarak mod 2'ye geçilir. Grup B'nin tek mod biti vardır: 0 mod 0, 1 mod 1.

## 7. BSR modu ve kare dalga örneği

### 7.1 BSR biçimi

Kontrol kelimesinin MSB'si 0 ise BSR modu etkindir. D6-D4 bir anlam taşımaz; D3, D2, D1 port C'nin hangi pininin set ya da reset edileceğini ikilik olarak verir; en sağdaki D0 bu pinin 1 (set) ya da 0 (reset) yapılacağını söyler.

### 7.2 Örnek

Slayttaki örnek (ekrandan, 01:10:00): "80H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8255'te PC2'yi lojik 1 olacak şekilde, PC6'da ise duty cycle'ı %66 olan bir kare dalga üretecek şekilde programlayın."

Adresler 80H, 82H, 84H, 86H'dir; kontrol yazmacı 86H'dir.

**PC2'yi 1 yapmak:** BSR modu (D7 = 0), önemsiz bitler 0, pin numarası 2 = 010, S/R = 1:

$$0000\,0101_2 = 05H$$

Bu değer 86H'ye gönderilir.

**PC6'da %66 duty cycle'lı kare dalga:** Bir periyodun (cycle) yaklaşık %66'sında çıkış 1, %33'ünde 0 olmalıdır; yani çıkış iki zaman birimi 1'de kalır, bir zaman birimi 0'a iner. Değişen tek alan pin numarasıdır: 6 = 110.

- Set kelimesi: `0000 1101` = 0DH,
- Reset kelimesi: `0000 1100` = 0CH.

Akış: PC6 set edilir (0DH → 86H), arka arkaya iki gecikme alt programı çağrılır, PC6 reset edilir (0CH → 86H), bir gecikme çağrılır ve bu döngü sürekli tekrarlanır. Sonuçta çıkış, periyodun üçte ikisinde 1 olan bir kare dalga üretir. Bütün kelimeler python ile doğrulandı.

<!-- BELİRSİZ: kare dalga programının kodu karede görünmüyor; gecikme alt programının adı ve döngü komutları altyazıdan net değil. -->

## 8. Mod 1: el sıkışmalı G/Ç

### 8.1 Kontrol kelimeleri ve port C uçlarının dağılımı

Mod 1'de bir port çıkış olarak atandıysa yalnız gönderim için, giriş olarak atandıysa yalnız okuma için el sıkışma sinyalleriyle çalışır. Port C uçları el sıkışma ve kesme sinyallerine ayrılır. Slayttaki dört durum (ekrandan, 01:15:00 ve 01:20:00):

| Durum | Kontrol kelimesi | El sıkışma uçları | Serbest uçlar |
|---|---|---|---|
| Port A giriş | `1 0 1 1 (1/0) X X X` | PC4 = $\overline{STB_A}$, PC5 = $IBF_A$, PC3 = $INTR_A$ | PC6, PC7 (D3 ile yönü seçilir) |
| Port A çıkış | `1 0 1 0 (1/0) X X X` | PC6 = $\overline{ACK_A}$, PC7 = $\overline{OBF_A}$, PC3 = $INTR_A$ | PC4, PC5 (D3 ile yönü seçilir) |
| Port B giriş | `1 X X X X 1 1 X` | PC2 = $\overline{STB_B}$, PC1 = $IBF_B$, PC0 = $INTR_B$ | yok |
| Port B çıkış | `1 X X X X 1 0 X` | PC2 = $\overline{ACK_B}$, PC1 = $\overline{OBF_B}$, PC0 = $INTR_B$ | yok |

Grup A için D6D5 = 01 mod 1'i seçer, D4 port A'nın yönüdür. Grup B için D2 = 1 mod 1'i seçer, D1 port B'nin yönüdür. Port C'nin alt ve üst yarısına artık ayrı ayrı yön verilemez, çünkü bu uçlar durum sinyalleri olur. Port A giriş iken yalnız PC6 ve PC7, port A çıkış iken yalnız PC4 ve PC5 genel amaçlı kullanılabilir. Port B'nin uçları (PC0-PC2) okuma da yazma da yapsa aynı kalır; port A'nın kullandığı uçlar ise yöne göre değişir.

> **Hocanın vurgusu:** En sık yapılan hatalardan biri, port A çıkışken serbest olan PC4-PC5 yerine PC6-PC7'yi kullanmaya çalışmaktır; bu durumda PC6 ve PC7 başka iki durum sinyaline atanmıştır. Port A'nın giriş ya da çıkış seçilmesi, port C'nin hangi uçlarının boşta kalacağını belirler. Bunların ezberlenmesine gerek yoktur, arayüzler dokümanında yazar.

### 8.2 Sinyallerin anlamı

Hoca el sıkışmayı kavramsal olarak şöyle anlattı: karşı taraf veri göndermeden önce "veri göndereceğim" diye bir sinyal gönderir; siz "şimdi gönderebilirsin" dersiniz ve veri gelir. Veriyi aldığınızda bunu karşı tarafa bildirirsiniz; karşı taraf bu sinyali almadan yeni veri göndermez.

- **$\overline{STB}$ (strobe):** başka bir birimden gelen "sana veri gönderiyorum" sinyali.
- **IBF (input buffer full):** "veriyi aldım, giriş tamponuna koydum, içeride tutuyorum" sinyali.
- **$\overline{OBF}$ (output buffer full):** "çıkışıma veriyi yerleştirdim, sana göndereceğim" sinyali.
- **$\overline{ACK}$ (acknowledge):** karşı tarafın "veriyi aldım" sinyali.
- **INTR:** alım ya da gönderim bittiğinde işlemciye kesme isteği.

Bu çiftler birbiriyle el sıkışır: STB ile IBF giriş tarafında, OBF ile ACK çıkış tarafında haberleşmeyi sağlar.

Slayttaki "8255 Mod 1" örneği bir yazıcı bağlantısıdır (ekrandan, 01:30:00): CPU yavaş bir çevre birimine (yazıcıya) veri göndermek istediğinde, aktarıma hazır olup olmadığını sormak için el sıkışma sinyali gönderir; yazıcı hazır olunca CPU'ya bir onay (acknowledgement) yollar ve veri, veri yolundan aktarılır. Şemada D0-D7, Strobe, ACK ve Busy hatları vardır.

### 8.3 Kesme ve INTE bitleri

Her portun içinde bir kesme izin bayrağı vardır: INTE A ve INTE B. Bu bayraklar BSR modunda port C'nin ilgili biti set edilerek açılır: port A giriş için PC4, port A çıkış için PC6, port B için PC2. Bu bitlere 0 gönderilirse kesme oluşmaz, yani kesme kapatılmış olur; kesme denetimi yapılacaksa bunların 1'lenmesi gerekir.

Port A'nın kesme çıkışı her iki yönde de PC3'te, port B'ninki PC0'dadır. Kesme oluştuysa giriş tarafında verinin alındığı, çıkış tarafında verinin gönderildiği anlaşılır.

> **Ders sonrası not:** Hoca kesmenin oluşumunu bir yerde "PC6 ve PC7'nin orlanması" gibi anlattı. Arayüzler dokümanındaki blok şemada INTR, INTE bayrağı ile el sıkışma sinyallerinin bir VE kapısından çıkar (ekrandan, 01:15:00); yani kesme için koşulların hepsi birlikte sağlanmalıdır.

### 8.4 Zamanlama

**Giriş (okuma):** Karşı taraf veri gönderirken $\overline{STB}$'yi 0'a çeker ("sana veri gönderiyorum"; etkin düşük). 8255 veriyi alınca IBF 1 olur ("aldım"). Bir süre sonra, iki koşul birlikte sağlandığında INTR 1 olur ve kesme oluşur. İşlemci $\overline{RD}$ ile okumayı yapınca kesme sıfıra iner.

**Çıkış (yazma):** İşlemci bir şey yazarken $\overline{WR}$ sinyali gelir; WR 0'a düşünce (yazma bitince) $\overline{OBF}$ 0'a düşer, yani "çıkış tamponumda veri var, göndermeye hazırım" bilgisi verilir. Karşı taraf veriyi aldığında $\overline{ACK}$ 0'a çeker; bundan bir süre sonra kesme oluşur.

> **Ek bilgi (derste anlatılmadı):** 8255 veri sayfasına göre (büyük olasılıkla) giriş tarafında IBF, $\overline{STB}$'nin düşen kenarıyla 1 olur ve $\overline{RD}$'nin yükselen kenarıyla sıfırlanır; INTR ise $\overline{STB}$ tekrar 1 olduğunda (IBF = 1 ve INTE = 1 iken) 1 olur ve $\overline{RD}$'nin düşen kenarıyla düşer. Çıkış tarafında $\overline{OBF}$, $\overline{WR}$'nin yükselen kenarıyla 0 olur ve $\overline{ACK}$ ile tekrar 1'e çıkar; INTR, $\overline{ACK}$ tekrar 1 olduğunda oluşur.

### 8.5 Durum kelimesi

Mod 1'de port C okunursa durum (status) bilgisi elde edilir: IBF ya da OBF oluşmuş mu, kesme var mı, kesme izni açık mı. Arayüzler dokümanındaki durum kelimeleri (ekrandan, 00:15:00):

| Durum | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|---|
| Mod 1 giriş | I/O | I/O | $IBF_A$ | $INTE_A$ | $INTR_A$ | $INTE_B$ | $IBF_B$ | $INTR_B$ |
| Mod 1 çıkış | $\overline{OBF_A}$ | $INTE_A$ | I/O | I/O | $INTR_A$ | $INTE_B$ | $\overline{OBF_B}$ | $INTR_B$ |

Serbest kalan uçlar (port A girişte D7-D6, çıkışta D5-D4) normal giriş/çıkış verisi gibi okunur. Port B'nin kesmesi PC0'dan okunur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Demo karttaki bağlantı şemasına göre (A5, A6, A7 → 74LS137 A, B, C; $\overline{A0}$ → E1; $M/\overline{IO}$ → E2; A3 + A4 → üçüncü etkinleştirme ucu; Y3 → $\overline{CS}$; CPU A1, A2 → 8255 A0, A1) 8255'in port ve kontrol adreslerini bulun.

> **Çözüm:** Y3 için A7 A6 A5 = 011; A0 = 0; G/Ç erişimi; A3 = A4 = 0. A7-A0 = `0110 0xx0` → port A 60H, port B 62H, port C 64H, kontrol 66H.

**Soru 2** (ekrandan, 00:45:00): 4 buton 4 LED programında `OR AL, 0F0H`, `CMP AL, 0FFH` ve `SHL AL, CL` (CL = 4) satırları ne işe yarar?

> **Çözüm:** OR, LED bitlerini (üst yarı) 1'leyerek karşılaştırmayı yalnız butonlara bağlar ve kaydırmadan sonra basılmayan butonların LED'lerini yeniden yakar. CMP ile AL = FFH ise hiçbir butona basılmamıştır ve döngü sürer. SHL, buton desenini LED bitlerine taşır; basılan butonun LED'i söner. Örneğin alt yarı `1011` ise AL = FBH, kaydırma sonrası B0H yazılır ve PC6'daki LED söner.

**Soru 3** (derste sözlü, 01:02:09): Tuş takımı programında port A'ya FDH yazıldıktan sonra port C okunup `TEST AL, 02H` yapılıyor. Bu yapı neyi kontrol eder?

> **Çözüm:** FDH yalnız orta sütunu (2-5-8-0) 0 ile sürer; 02H maskesi PC1'i, yani ikinci satırı (4-5-6) denetler. Kesişim 5 tuşudur; program 5'e basılıp basılmadığını kontrol eder.

**Soru 4** (ekrandan, 01:10:00): 80H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8255'te PC2'yi lojik 1 olacak şekilde, PC6'da ise duty cycle'ı %66 olan bir kare dalga üretecek şekilde programlayın.

> **Çözüm:** Kontrol yazmacı 86H. PC2 set: 05H. PC6 set: 0DH, reset: 0CH. Döngü: 0DH → 86H, iki gecikme; 0CH → 86H, bir gecikme; başa dön.

**Soru 5** (derste sözlü, 01:27:58; araştırma sorusu): Grup A mod 1 çıkış, grup B mod 1 giriş olarak ayarlanır ve port A ile port B birbirine bağlanırsa (bir taraf yazar, diğer taraf okur) el sıkışma için port C uçları nasıl bağlanmalıdır? Hoca tahtada port A çıkış tarafının el sıkışma uçlarını port B giriş tarafının uçlarına bağlayan eğriler çizdi (ekrandan, 01:25:00).

> **Çözüm (derste verilmedi):** Veri hattı: PA0-PA7 → PB0-PB7. Kontrol kelimesi: D7 = 1, D6D5 = 01 (grup A mod 1), D4 = 0 (port A çıkış), D3 = PC4-PC5 yönü (ör. 0), D2 = 1 (grup B mod 1), D1 = 1 (port B giriş), D0 = X (0) → `1010 0110` = A6H (python ile doğrulandı). El sıkışma: $\overline{OBF_A}$ (PC7) → $\overline{STB_B}$ (PC2), yani "veri hazır" sinyali alıcının strobe girişini tetikler; $IBF_B$ (PC1) → $\overline{ACK_A}$ (PC6), yani alıcı veriyi aldığını gönderene bildirir. IBF etkin yüksek, $\overline{ACK}$ etkin düşük olduğu için bu hatta büyük olasılıkla bir DEĞİL kapısı gerekir. Kesmeler kullanılacaksa INTE A (PC6) ve INTE B (PC2) bitleri BSR ile set edilir.

## Dersin Toparlaması

Bu derste 8255'in mod 0 kullanımı, demo kart üzerindeki örneklerle pekiştirildi. Önce bir bağlantı şemasından 8255'in adresi tersten çıkarıldı: 74LS137 kod çözücünün girişleri ve etkinleştirme uçları adım adım incelenerek 60H, 62H, 64H, 66H adresleri bulundu; düz yönde tasarımda tek doğru olmadığı, ama entegrenin yalnız istenen adreste seçilmesi gerektiği vurgulandı. Ardından pull-up dirençli butonlar ve LED'lerle çalışan bir program satır satır incelendi; ortak anot ve ortak katot göstergelerin farklı kodlaması ve tuş takımının sütundan sürülüp satırdan okunması gösterildi.

Dersin ikinci bölümünde BSR modu bir kare dalga örneğiyle uygulandı ve mod 1'e giriş yapıldı: port C uçlarının STB, IBF, OBF, ACK, INTR sinyallerine nasıl dağıldığı, INTE bitlerinin BSR ile açılıp kapatılması ve durum kelimesi anlatıldı. Hoca, grup A çıkış ve grup B giriş olacak şekilde iki portun el sıkışmayla bağlanmasını araştırma sorusu olarak bıraktı ve mod 1'in bir sonraki derste kısaca tekrar edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
