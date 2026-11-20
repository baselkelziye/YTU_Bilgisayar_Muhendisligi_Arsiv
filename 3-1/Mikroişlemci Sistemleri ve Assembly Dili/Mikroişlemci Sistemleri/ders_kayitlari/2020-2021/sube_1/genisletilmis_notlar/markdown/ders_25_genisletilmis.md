# Ders 25 Genişletilmiş Notu: Hafıza Birimleri ve 8086 Hafıza Arayüzü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı: hafıza birimleri neden gerekli
- 2. ROM ve 8086 reset vektörü
- 3. ROM çeşitleri
- 4. ROM'un iç yapısı: 4x4 ROM ve sigortalar
- 5. ROM blok diyagramı
- 6. RAM: rastgele erişim, SRAM ve DRAM
- 7. SRAM hücresi: yazma ve okuma
- 8. SRAM blok diyagramı ve iç yapısı
- 9. DRAM hücresi, yenileme ve satır/sütun adresleme
- 10. 8086 adres uzayı ve çift/tek bank düzeni
- 11. A0 ve BHE ile erişim türleri
- 12. Adres çözümleme: izole I/O, separate bank decoder ve separate bank strobe
- 13. Adres çözümleme elemanları: 3x8 ve 2x4 dekoder
- 14. Örnek 1: 27128 EPROM ile F0000H'den 64 KB
- 15. Örnek 2: 32Kx8 RAM ile 0 adresinden 128 KB
- 16. Örnek: 80486 ve dört banklı hafıza
- 17. Hizalı adresler ve çözümlemenin kolaylığı
- Örnek Sorular

## 1. Dersin kapsamı: hafıza birimleri neden gerekli

Bu derste hafıza (memory) arayüzü işlenir. Plan üç adımdır: önce hafıza birimlerinin genel özellikleri ve uç tanımları, sonra bu birimlerin birleştirilerek daha büyük birimler elde edilmesi, en son da elde edilen hafıza bloklarının 8086'nın belirli adres aralıklarına yerleştirilmesi. Slayttaki konu listesi şöyledir (ekrandan, 00:10:00): hafıza birimleri (ROM: Masked ROM, PROM, EPROM, EEPROM, Flash Memory; RAM: SRAM, DRAM), adres çözümleme, 8086-hafıza birimleri arayüzü ve örnekler.

Hoca, dersin başında söylenen bir noktayı hatırlatır: bir mikroişlemci tek başına operasyonel bir anlam ifade etmez. Çalışabilmesi için hafıza birimlerinin (RAM ve ROM olarak iki ayrı birim), dış dünyayla iletişim için çevre birimlerinin ve çeşitli yardımcı birimlerin bağlı olması gerekir. Bu derste ROM ve RAM şu amaçlarla ele alınır:

- ROM kalıcı bir hafızadır ve daha çok BIOS ROM gibi üzerinde program barındıran yapılar için kullanılır.
- RAM daha çok geçici işlem sonuçlarının tutulduğu birincil hafıza birimidir.

Hoca önemli bir farka da dikkat çeker: şimdiye kadar kullanılan bütün çevre birimleri 8 bitlikti. Burada ise mikroişlemciyle uyumlu, 16 bit genişlikte bir hafıza arayüzü kurulacaktır. 8086 tasarımı gereği çift adresten 8 bitlik, tek adresten 8 bitlik ve çift adresten 16 bitlik işlemleri tek bir okuma/yazma çevriminde yapar. Hafıza arayüzü bu tasarımı destekleyecek biçimde kurulmalıdır. Dönemin başında özel (custom) I/O cihazlarında 16 bitlik bir I/O cihazının nasıl kurulacağına bakılmıştı; buradaki yapı ona benzese de genel çevre birimlerinden farklıdır.

## 2. ROM ve 8086 reset vektörü

ROM, yalnız okunabilen bir hafıza birimidir. Kalıcıdır (non-volatile): enerjisi kesilse bile üzerindeki veri kaybolmaz. Bu özelliği nedeniyle 8086'nın reset vektöründe bir ROM bulunur.

Hoca burada bir soru sorar: 8086'nın reset vektörü nedir? Yani sistem resetlendiğinde ya da ilk kez enerji verildiğinde işlemci hangi hafıza adresinden yürütmeye başlar? 8086'nın adres uzayı 20 bitliktir ve 20 bitlik adres Code Segment (CS) ile Instruction Pointer (IP) çiftinden oluşturulur. Dolayısıyla soru, reset sonrasında CS ve IP'ye yüklenen ilk değerlerin ve bunlardan hesaplanan fiziksel adresin ne olduğudur. Öğrencilerden ilk gelen "FFFF" cevabı tek başına yeterli değildir; doğru cevap şudur:

- CS = FFFFH
- IP = 0000H
- Fiziksel adres = CS × 10H + IP = FFFF0H

İşlemci bu 20 bitlik adresten itibaren çalışmaya başladığı için burada bir ROM yerleşik olmalıdır. Bu ROM, sistem reset olduktan sonra açılış (boot) işlemlerini ele alır ve gerekli yönlendirmeyi yapar. Bu yüzden reset vektöründe BIOS ROM'un yerleşik olduğu söylenebilir.

## 3. ROM çeşitleri

Slayttaki ROM çeşitleri şunlardır (ekrandan, 00:15:00):

- **Masked ROM:** Üretim aşamasında maskelenerek programlanır. Üretildiği anda hafıza gözlerine değerler yazılmıştır.
- **PROM (programmable read-only memory):** Üretimden boş çıkar, kullanıcı tarafından bir kez programlanır.
- **EPROM (erasable programmable read-only memory):** Silinip yeniden programlanabilir. Silme ultraviyole ışıkla yapılır. Bazı çiplerin üzerinde, bazen bantla kapatılmış bir pencere vardır; bant açılıp çip 20-30 dakika UV ışıkta bekletilince program silinir. Sonra pencere kapatılıp çip yeniden programlanır.
- **EEPROM (electrically erasable programmable read-only memory):** Elektriksel olarak silinip yazılır. Çip üzerindeki programlama uçlarına uygun koşullandırılmış değerler uygulanarak içerik silinir ve farklı koşullarla yeniden programlanır.
- **Flash bellek:** Günümüzde flash disklerde de bulunan yapıdır. Blok olarak silinip blok olarak yazılabilme özelliğinden yararlanılarak geliştirilmiştir.

Bir kez ya da tekrar programlanabilen yapılarda programlama, bir sigortanın bağlantıyı sağlaması ya da koparması olarak modellenir. Bu modelin nasıl çalıştığı bir sonraki bölümdeki örnekte görülür.

## 4. ROM'un iç yapısı: 4x4 ROM ve sigortalar

### 4.1 Yapı ve kapasite

Slayttaki basit ROM'un (ekrandan, 00:20:00) iki adres ucu (A1, A0) ve dört veri ucu (D3-D0) vardır. Adres uçları 2x4'lük bir dekodere girer; dekoderin 0-3 numaralı çıkışları aktif 0'dır ve her biri bir hafıza satırını sürer. Her satır ile her veri hattı arasında, gate ucu satıra bağlı bir transistör ve onunla seri bir sigorta (slaytta mavi ile çizilmiş) vardır. Veri hatları üstten R pull-up dirençleriyle beslemeye bağlıdır.

$n$ adres ucu dekoderden geçince $2^n$ satırdan biri seçilir; yani içeride $2^n$ hafıza gözü (satır) vardır. Her satır $m$ bit saklar. Bu yüzden $n$ adres ve $m$ veri uçlu bir ROM'un kapasitesi

$$2^n \times m$$

olarak ifade edilir. Bu örnekte $2^2 \times 4 = 4 \times 4$'lük bir ROM vardır. Adres ile hafıza gözü arasındaki seçimi sağlamak için $n \times 2^n$'lik bir dekoder, burada 2x4'lük dekoder kullanılır.

### 4.2 Seçilen ve seçilmeyen satırlar

Hoca öğrencilere sorar: bir adres uygulandığında yalnız bir satır seçilmişse, seçilmeyen dekoder çıkışlarında ne vardır? Dekoder çıkışları aktif 0 olduğu için seçilmeyen çıkışlarda lojik 1, seçilen çıkışta lojik 0 bulunur.

Hoca anlatırken bir yerde karışıklık yaşar ("yanlış söyledim, pardon") ve modeli yeniden kurar. Kurduğu sonuç şudur: seçilmeyen satırların çıkış hatlarına katkısı yoktur; yalnız seçilen satırdaki hücreler veri hatlarını etkiler. Bir veri hattına (örneğin D3) yalnız seçilen satırdaki hücre katkı yapar:

- Seçilen satırda sigorta **korunmuşsa**, transistörün drain ile source uçları arasında bağlantı sağlanır ve hat lojik 0'a çekilir.
- Sigorta **yakılmışsa**, source ile drain arasındaki bağlantı kurulamaz; hat yalnız pull-up dirençle sürüldüğü için lojik 1 görünür.

Seçili olsa bile sigortası yakılmış bir hücrenin de hatta bir katkısı yoktur. Kısacası, bu yapıda **sigortayı korumak 0, yakmak 1 yazmak** demektir.

<!-- BELİRSİZ: 00:19:10-00:19:42 arasında hoca seçilen ve seçilmeyen satır için transistör durumunu önce yanlış anlatıp "yanlış söyledim, pardon" diyerek düzeltiyor; düzeltilmiş hali yukarıdaki gibidir, ara anlatım altyazıdan tam izlenemiyor. -->

### 4.3 Sigortalarla değer yazma

Hoca dört gözün programlanmasını sözlü olarak verir (sıra D3, D2, D1, D0):

| Göz (adres) | Sigortalar (D3-D0) | İkilik | Onaltılık |
|---|---|---|---|
| 0 (00) | yak, koru, yak, koru | 1010 | AH |
| 1 (01) | koru, koru, yak, yak | 0011 | 3H |
| 2 (10) | koru, yak, koru, yak | 0101 | 5H |
| 3 (11) | koru, yak, yak, yak | 0111 | 7H |

ROM'un bir hafıza gözüne değer yazmak, bu yapıda sigortayı yakmak ya da korumak olarak karşılık bulur.

## 5. ROM blok diyagramı

En genel haliyle bir ROM'un uçları şunlardır (ekrandan, 00:25:00):

- $n$ adet **adres** ucu: ROM açısından giriş yönlüdür.
- $m$ adet **veri** ucu: ROM yalnız okunabildiği için operasyon sırasında yalnız çıkış yönlüdür.
- $\overline{CS}$ (chip select): aktif 0.
- $\overline{OE}$ (output enable): aktif 0.

Slaytta bağlantı ilişkileri şöyle yazılıdır: $2^n \times m$ kapasiteli ROM; $\overline{OE} \leftrightarrow \overline{RD}$; $\overline{CS} \leftrightarrow$ adres çözümleme.

ROM 8086'lı bir sisteme bağlanırken:

- $\overline{CS}$ ucu adres çözümleme devresine bağlanır. Bir hafıza elemanı bir adres alanına yerleştirildiğinde, o alanla ilgili bir komut yürütülürken cihazın seçilmesi gerekir; bunu adres çözümleme devresinden gelen bir uç sağlar.
- $\overline{OE}$ ucu, okuma yapıldığında verinin cihazdan dışarı çıkmasını sağlar. Bu uca mikroişlemcinin $\overline{RD}$ ucu bağlanır.
- Adres uçlarına mikroişlemcinin adres uçları, veri uçlarına mikroişlemcinin veri uçları bağlanır.

## 6. RAM: rastgele erişim, SRAM ve DRAM

RAM (Random Access Memory) uçucudur (volatile): enerjisi kesildiğinde üzerindeki veri kaybolur. Bilgisayarlarda ana hafıza (main memory) olarak kullanılır ve erişim hızı daha yüksektir.

> **Ders sonrası not:** Hoca "erişim hızı daha yüksek RAM'e göre" dedi; bağlam RAM ile ROM'u karşılaştırdığı için kastedilen "ROM'a göre" olmalıdır.

"Rastgele erişim" adı, "sıralı erişim" (sequential access) ile karşıtlık içindir. Rastgele erişim, herhangi bir hafıza gözüne doğrudan adres değeri vererek erişebilmektir. Sıralı erişimli birimlerde belirli bir adrese ulaşmak için baştan itibaren ilerlemek gerekir; manyetik bant gibi ikincil hafıza birimleri buna örnektir.

RAM'in iki çeşidi vardır:

- **Statik RAM (SRAM):** Flip-flop temelli atomik bileşenlerden oluşur. Hoca, bir SRAM hücresi için yanlış hatırlamıyorsa 6 transistör gerektiğini söyler (slayttaki hücrede M1-M6 olarak görülür).
- **Dinamik RAM (DRAM):** Bir transistör ve bir kapasiteden oluşur. Kapasite de transistör temelli düşünülürse hücre başına yaklaşık 2 transistör eder. Bu yüzden DRAM'de veri yoğunluğu, yani birim alanda saklanan veri miktarı daha yüksektir.

DRAM'in temel sıkıntısı, verinin kapasitenin yüküne bağlı olmasıdır. Kaçak akımlar nedeniyle saklanan veri kaybolabilir; bu yüzden DRAM'deki veri belirli aralıklarla yeniden şarj edilmeli, yani aynı veri tekrar üzerine yazılmalıdır.

## 7. SRAM hücresi: yazma ve okuma

### 7.1 Yapı

Slaytta iki çizim vardır (ekrandan, 00:30:00): solda çapraz bağlı iki evirici ve iki erişim transistörü (M5, M6), sağda aynı hücrenin transistör düzeyinde çizimi (M1-M4 eviriciler, VDD besleme). Slaytın altında WL: word line (adres), BL: bit line (data) yazılıdır. Hoca, çapraz bağlı kapıları bir flip-flop mantığı olarak düşünmeyi önerir.

- **BL** ve $\overline{BL}$: verinin kendisi ve tersi, yani veri ucu.
- **WL**: hücrenin adresi gibi düşünülebilecek seçim hattı.
- **VDD**: transistörlerin besleme gerilimi. Adres seçimi kalksa bile çapraz bağlı kapıların beslemesi sürer.

### 7.2 1 yazma

Hücre seçilince WL'ye 1 verilir ve erişim transistörleri yolları bağlar. BL'de bit değeri, örneğin lojik 1, $\overline{BL}$'de lojik 0 vardır. Çapraz bağlı kapılar 1-0-0-1 biçiminde kendi içinde tutarlı bir duruma geçer. Word seçimi kalktıktan sonra da besleme var oldukça bu değer saklanır.

### 7.3 0 yazma

Aynı işlem 0 için yapılır: hücre seçilir (WL=1), BL=0, $\overline{BL}$=1. Bu kez Q ucunda 0, $\overline{Q}$ ucunda 1 vardır ve yine kararlı bir durum oluşur. Veri ucundaki işaret kalksa bile kapılar beslendiği için 0 saklanır.

### 7.4 Okuma

İçeride saklı veri X, tersi Y noktasında bulunur. Hücre seçilip WL'ye 1 verilince X bit hattına, X'in tersi $\overline{BL}$ hattına çıkar. Hatlardaki gerilim kayıplarını telafi etmek için iki hat bir karşılaştırıcıdan geçirilir. Karşılaştırıcı artı ve eksi uçlarındaki gerilimlerin farkını alır: fark pozitifse lojik 1, negatifse lojik 0 çıkarır. Böylece içeride gerilim kayıpları olsa bile saklanan orijinal değer dışarı aktarılır.

Bu yapı SRAM'in temel atomik hafıza birimidir ve bir bit için 6 transistör gerektirir.

## 8. SRAM blok diyagramı ve iç yapısı

### 8.1 Blok diyagram

SRAM'in uçları şunlardır (ekrandan, 00:35:00):

- $n$ adet **adres** ucu: yalnız giriş.
- $m$ adet **veri** ucu: giriş ve çıkış (çift yönlü). RAM'e hem yazılabilir hem okunabilir; operasyon sırasında ikisi de desteklenmelidir.
- $\overline{WE}$ (write enable), $\overline{RE}$ (read enable), $\overline{CS}$ (chip select): aktif 0.

Slayttaki bağlantı ilişkileri: $2^n \times m$ kapasiteli SRAM; $\overline{RE} \leftrightarrow \overline{RD}$; $\overline{WE} \leftrightarrow \overline{WR}$; $\overline{CS} \leftrightarrow$ adres çözümleme.

Cihaz 8086'nın belirli bir hafıza aralığına yerleştirilmişse, yalnız o aralıkla ilgili işlemde aktif olmalıdır; bu yüzden $\overline{CS}$ ucuna adres çözümleme devresinden gelen uç bağlanır. Cihaz seçildikten sonra okuma mı yazma mı yapılacağını mikroişlemcinin $\overline{RD}$ ve $\overline{WR}$ uçları belirler.

> **Hocanın vurgusu:** Tasarımlarda ROM için varsayılan olarak ROM blok diyagramı, SRAM için SRAM blok diyagramı kullanılacaktır.

### 8.2 İç yapı

Slayttaki SRAM iç yapısında (ekrandan, 00:40:00) A2-A0 adres uçları 3x8'lik bir dekodere girer ve 0-7 numaralı aktif-0 çıkışlar sekiz satırı seçer; her satırda D3-D0 için dört hücre vardır. $\overline{WE}$ ve $\overline{CS}$ bir OR kapısından geçerek hücrelerin yazma denetimine, $\overline{CS}$ ve $\overline{OE}$ ikinci bir OR kapısından geçerek çıkış tutucularına (output latch) gider. Genel olarak $n$ adres ucu için $n \times 2^n$'lik bir dekoder ve $2^n$ satır vardır; $m$ veri ucu varsa her satır $m$ bit saklar. Kapasite yine $2^n \times m$'dir. ROM'dan farkı, okuma ve yazma yönlerini denetleyen ek bir kontrol devresinin bulunmasıdır.

**Okuma:** $\overline{WE}=1$, $\overline{CS}=0$, $\overline{OE}=0$. $\overline{WE}$ 1 olduğu için yazma denetim kapısının çıkışı 1'dir ve içeriye veri kopyalama tarafı kapanır. $\overline{OE}$ ve $\overline{CS}$ 0 olduğu için çıkış denetimi aktiftir. Uygulanan adrese karşılık gelen satırdaki hücrelerin değerleri çıkış tutucularına, oradan dış dünyaya aktarılır.

**Yazma:** $\overline{WE}=0$, $\overline{CS}=0$, $\overline{OE}=1$. Dışarıya veri gönderen çıkış tutucuları seçili değildir. Adrese göre bir satır aktif olur ve dış dünyadan gelen değerler hücrelerin yazma girişleri üzerinden o satırdaki atomik hafıza birimlerine aktarılır.

## 9. DRAM hücresi, yenileme ve satır/sütun adresleme

### 9.1 Hücre ve "delikli kova" benzetmesi

DRAM hücresi bir transistör ve bir kapasiteden oluşur (ekrandan, 00:45:00; slaytta "1-bit DRAM cell", "bit line", "word line"). SRAM'de her atomik birim bir flip-flop iken DRAM'de kapasite kullanıldığı için saklanan yük zamanla kaybolabilir.

Hoca bunu bir benzetmeyle anlatır: transistör-kapasite ikilisi altında delik olan bir kova gibidir. Musluk açıkken kova dolar; musluk kesildiğinde, yani hücre seçilmediğinde, su zamanla akıp gider. Kova boşsa tekrar bakıldığında yine boş görülür; yani 0 değeri kaybolmaz, ama 1 değeri kaçak akımlar nedeniyle kaybolabilir.

Word line, hücrenin seçilmesine ilişkin adres (ya da enable) ucu gibidir; veri bit line üzerindedir.

### 9.2 1 ve 0 yazma

- **1 yazma:** Bit hattına 1 konur, word line 1 yapılır. Transistörün source ve drain uçları bağlanır, besleme gerilimi kapasiteyi şarj eder. Word line 0'a çekildiğinde bağlantı kesilir ama yük kapasitede kalır; hücrede 1 saklanır.
- **0 yazma:** Kapasitenin başta 1'e karşılık gelen bir yüke sahip olduğu varsayılır. Bit hattına 0 konur, word line 1 yapılır. Kapasite lojik 0 tarafına bağlanınca yükler akar ve kapasite deşarj olur. Seçim kaldırıldığında kapasite boştur ve okumada 0 görülür.

### 9.3 Yenileme (refresh)

Hoca lojik dersinden hatırlatır: kullanılan teknolojiye göre hangi gerilimin lojik 0, hangisinin lojik 1 sayılacağına dair standartlar vardır (giriş ve çıkış yönünde ayrı aralıklar). Slayttaki grafikte (ekrandan, 00:45:00) Vcap ekseni, HIGH/LOW eşik çizgisi, "0 stored", "1 written" ve "refreshes" işaretleri vardır. Başta hücrede 0 saklıdır; 1 yazılınca kapasite gerilimi Vcc'ye çıkar. Hücre tekrar seçilmezse gerilim üstel olarak düşmeye başlar ve böyle devam ederse bir süre sonra eşiğin altına inerek 0 olarak algılanır. Bu yüzden belirli bir değere indikten sonra içerideki değer yeniden yazılır, yani kapasite yeniden şarj edilir. Seçim kalkınca değer yine düşer ve işlem tekrarlanır.

Yenileme frekansı şöyle optimize edilir: bütün hafızaya değerleri yeniden yazmak maliyetli olduğu için sıklığı olabildiğince düşük tutmak mantıklıdır; ama sıklık, gerilimin eşik altına inmesine izin vermeyecek bir minimumun üstünde olmalıdır. Optimum değer bu ikisi arasında seçilir.

Hoca, 8088 kullanan sistemlerde 8254 zamanlayıcısının sayıcılarından birinin yenileme hızını belirlemek için özel olarak ayrıldığını hatırlatır.

### 9.4 Satır ve sütun seçimi

DRAM'de veri yoğun bir alan kullanımı olduğu için tasarımda bir optimizasyona gidilmiştir: ek olarak **sütun seçimi** ve **satır seçimi** uçları vardır. İç yapıda satırlar ve sütunlar için iki ayrı dekoder bulunur. Hoca anlatımda sütundan başlar: önce sütun seçimi aktif edilir ve adres uçlarından sütun adresi verilir; dekoder $2^n$ sütundan birini seçer. Bir sonraki çevrimde sütun seçimi kapatılıp satır seçimi aktif yapılır ve aynı adres uçlarından bu kez satır adresi gönderilir; ikinci dekoder $2^n$ satırdan birini seçer. Bir satır ve bir sütun belirlenince o hücrenin değeri dışarı çıkar.

Aynı $n$ adres ucu iki kez kullanıldığı için $2^n \times 2^n$ hücre seçeneği vardır. Her adres çiftinde $m$ bitlik veriye erişildiğine göre DRAM'in kapasitesi

$$2^n \times 2^n \times m = 2^{2n} \times m$$

olur. Read enable mikroişlemcinin $\overline{RD}$, write enable $\overline{WR}$ ucuna eşdeğerdir; adres uçlarına mikroişlemcinin adres uçları, $m$ adet çift yönlü veri ucuna veri uçları bağlanır. Bu ardışık kullanım, adres uçlarını iki kez kullanarak daha geniş bir adres uzayı sağlar.

> **Ek bilgi (derste anlatılmadı):** Gerçek DRAM çiplerinde bu iki uç RAS (row address strobe) ve CAS (column address strobe) olarak adlandırılır ve genellikle önce satır adresi (RAS), sonra sütun adresi (CAS) verilir. Hocanın anlatımda sütundan başlaması yalnız bir anlatım seçimidir; ilke aynıdır.

Hoca, bu dersteki tasarımların SRAM ve ROM üzerinden yürüyeceğini, benzer bir arayüzün DRAM için de kurulabileceğini söyler.

## 10. 8086 adres uzayı ve çift/tek bank düzeni

### 10.1 Temel varsayımlar

Slayttaki maddeler şunlardır (ekrandan, 00:50:00):

- 8086 → 20 adres ucu, 16 veri ucu var.
- Hafıza birimleri → 8 veri ucuna sahip.
- 8086 → çift adresten 16 bitlik, tek adresten 8 bitlik, çift adresten 8 bitlik işlemleri bir okuma/yazma çevriminde yapmayı desteklemeli.

20 adres ucuyla $2^{20} = 1M$ hafıza gözü adreslenir. Her göz 1 bayt (8 bit) olduğundan adresleme kapasitesi $2^{20} \times 8$ bit, yani 1 MB'dir. Ama 8086 veriyi bir seferde 16 bitlik paketler halinde okuyup yazabilir. Hoca, SRAM ve ROM'ların veri genişliğinin ($m$) aksi belirtilmedikçe 8 kabul edileceğini söyler.

### 10.2 Komut örnekleri

Hoca öğrencilerden her durum için bir komut örneği ister. Tahtaya yazılanlar (ekrandan, 00:55:00):

```text
MOV AX,[0]   ; AL <- [0], AH <- [1]   (çift adresten 16 bit)
MOV AL,[1]   ; AL <- [1]              (tek adresten 8 bit)
MOV AH,[0]   ; AH <- [0]              (çift adresten 8 bit)
```

Bir öğrenci `WORD PTR` ile bir örnek önerir; hoca, hedef AX olduğu için `WORD PTR`'ye gerek olmadığını, BX'in değeri belirsiz kalmasın diye sabit `[0]` adresiyle yazmanın daha net olduğunu söyler. İşlemci bu üç işlemin her birini tek seferde yapabilmektedir.

### 10.3 Çift ve tek banka ayırma

Bu üç işlemi tek çevrimde yapabilmek için çift ve tek adreslerin aynı anda seçilebilmesi gerekir. Bunun için 1 MB'lik alan çift ve tek iki bloğa (banka) ayrılır ve bir satır tek seferde seçilecek biçimde düzenlenir. Tahtadaki çizimde (ekrandan, 00:55:00) bir banka "A0=1", diğerine "A0=0" yazılıdır ve altına "diğer A'lar aynı" notu düşülmüştür: tek banktaki bir adres ile aynı satırdaki çift bank adresi arasındaki tek fark A0'dır.

Bu yüzden tasarımda A0 bank seçimine ayrılır, kalan adres uçları satır seçimi için kullanılır. Böylece bir satırdaki iki değer birlikte veri yoluna çıkar ve işlemci ikisini tek seferde okur. Tasarım üç durumu da karşılar:

- Tek adresten 8 bitlik değer, tek banktaki bir satıra denk gelir. Karşıdaki çift bank satırı da aktif olabilir, ama işlemci veriyi yalnız ilgili bölgeden okuduğu için sorun olmaz.
- Çift adresten 8 bitlik işlem de aynı mantıkla çalışır.
- Çift adresten 16 bitlik işlem bir satırın iki gözünü birlikte okur.

Bu işlemlerde veri yolunun hangi yarısının kullanıldığı da önemlidir. Çift adresten yapılan okumalar veri yolunun düşük anlamlı baytında (D0-D7), tek adresten yapılanlar yüksek anlamlı baytında (D8-D15) olur. Öyleyse **tek bank D8-D15'e, çift bank D0-D7'ye** bağlanmalıdır.

### 10.4 1M×8 yerine 512K×16

Toplamı 1 MB olan alan, her biri 8 bit genişliğinde iki banka bölünür. Slayttaki çizime göre (ekrandan, 01:00:00) 8086, 1 MB'yi $1M \times 8$ olarak değil, **$512K \times 16$** olarak görmek ister. 1 MB toplam kapasitedir; $512K \times 16$ ise hafıza arayüzünün görmek istediği biçimdir (tüm kapasite kullanılırsa). Hoca, işlemciye $1M \times 8$'lik bir arayüzle bağlantı yapılırsa kapasitenin yarısının kullanılamaz hale geleceğini söyler.

### 10.5 Tek adresten 16 bitlik işlem

Hoca, konuşulmamış olan dördüncü durumu sorar: `MOV AX,[1]` gibi tek adresten 16 bitlik bir işlem yapılırsa ne olur? Burada AL'ye 1 adresinin, AH'ye 2 adresinin içeriği aktarılmalıdır (tahtada: `; AL <- [1], AH <- [2]`, ekrandan 01:00:00). 1 adresi tek banktadır; o satır seçilince veri D8-D15'e çıkar. Aynı satırdaki diğer gözün adresi 0'dır ve işe yaramaz. Aranan 2 adresi bir sonraki satırdadır. Bu yüzden işlemci önce 1 adresinin bulunduğu satırı aktif yapıp veriyi AL'ye alır, sonra 2 adresinin bulunduğu satırı aktif yapıp D0-D7 üzerinden gelen değeri AH'ye alır. Tek adresten 16 bitlik işlem ancak **iki okuma/yazma çevriminde** gerçekleşir.

> **Hocanın vurgusu:** Mikroişlemci açısından hizalama önemlidir. Bir word dizisi tek adresten başlayarak yerleştirilirse bu, yarı yarıya performans kaybı demektir.

## 11. A0 ve BHE ile erişim türleri

### 11.1 Neden iki kontrol ucu

Hoca, iki bankı yalnız A0 ile seçmenin yeterli olmadığını açıklar (anlatımda bir an "A0 ve A1" der, hemen "A0'ın değerleri" diye düzeltir). Desteklenmesi gereken üç durum vardır: yalnız çift bankı seçmek, yalnız tek bankı seçmek ve 16 bitlik işlemlerde iki bankın aynı satırını birlikte seçmek. Üç durum için iki değişken gerekir:

- **A0**, dönemin başında anıldığı diğer adıyla **$\overline{BLE}$ (bus low enable)**: çift bankı aktif eder. A0=0 olduğunda çift bank seçilir.
- **$\overline{BHE}$ (bus high enable)**: tek bankı aktif eder. $\overline{BHE}$=0 olduğunda tek bank seçilir.

İkisi de adlarından anlaşılacağı gibi aktif 0'dır.

### 11.2 Çift adresten 8 bit

Komut `MOV AL,[0]` gibi olsun (ekrandan, 01:05:00). Segment değeri ne olursa olsun 16 ile çarpıldığı için adresin çift ya da tek olması offsetten gelir; offset çift olduğu için adres çifttir. Hedef 8 bitlik olduğundan işlem çift adresten 8 bitliktir. İşlemci uçlarda şunları üretir: adresin son biti 0 olduğu için A0=0; işlem çift adresten 8 bitlik olduğu için $\overline{BHE}$=1. Yalnız çift bank seçilir, verilen adrese göre bir satır aktif olur ve değer D0-D7'ye çıkar. İşlemci veri yolunun düşük anlamlı baytını örnekler ve AL'ye aktarır. Bu yüzden çift banka D0-D7'nin bağlanması şarttır.

### 11.3 Tek adresten 8 bit

Komut `MOV AL,[1]` olsun. Adres tek, işlem 8 bitliktir. İşlemci A0=1, $\overline{BHE}$=0 üretir ve veriyi D8-D15'ten bekler. A0=1 olduğu için çift bank seçilmez, $\overline{BHE}$=0 olduğu için tek bank seçilir. Tek bankta bir satır aktif olur, 8 bitlik değer veri yolunun yüksek anlamlı baytına çıkar ve işlemci bunu AL'ye kopyalar.

### 11.4 Çift adresten 16 bit

Komut `MOV AX,[0]` olsun (ekrandan, 01:25:00, slayt "çift adresten 16 bit"). A0=0 ve işlem 16 bitlik olduğu için $\overline{BHE}$=0'dır; iki bank birden seçilir. İşlemci veriyi D0-D15'in tamamında bekler: düşük anlamlı bayt D0-D7'de, yüksek anlamlı bayt D8-D15'te. A0 bank seçimine ayrıldığı için A1-A19, bu adres ile bir sonraki adres için aynıdır; iki bankta aynı satıra hitap eder. 0 adresinin içeriği D0-D7'ye, 1 adresinin içeriği D8-D15'e aktarılır ve işlemci bu uçları örnekleyip AX'e alır.

### 11.5 Tek adresten 16 bit

`MOV AX,[1]` komutunda 1 ve 2 adreslerinin A1-A19 değerleri aynı değildir; farklı satırlara denk gelirler. İşlemci önce tek adresten 8 bitlik bir işlem, ardından ikinci bir 8 bitlik işlem yürütür, yani iki kez okuma/yazma yapar.

> **Hocanın vurgusu:** Tek adresten yapılan 16 bitlik okuma/yazma işlemleri iki çevrimde tamamlanır; bu yüzden veri tanımlamalarının hizalı olması çok önemlidir. Hoca bu konunun iyi takip edilmesinin önemli olduğunu ayrıca belirtti.

Özet tablo:

| Komut | Erişim | A0 | $\overline{BHE}$ | Veri uçları | Çevrim |
|---|---|---|---|---|---|
| `MOV AL,[0]` | çift adres, 8 bit | 0 | 1 | D0-D7 | 1 |
| `MOV AL,[1]` | tek adres, 8 bit | 1 | 0 | D8-D15 | 1 |
| `MOV AX,[0]` | çift adres, 16 bit | 0 | 0 | D0-D15 | 1 |
| `MOV AX,[1]` | tek adres, 16 bit | iki ayrı 8 bitlik erişim | | önce D8-D15, sonra D0-D7 | 2 |

## 12. Adres çözümleme: izole I/O, separate bank decoder ve separate bank strobe

### 12.1 Neden adres çözümleme

Slayttaki maddeler (ekrandan, 01:10:00):

- Hafıza ve I/O çipleri ortak veri ve adres yollarını kullanır.
- Bir seferde yola veri çıkan tek bir çip sağlamak için adres çözümleme kullanılır.
- Hafıza ve I/O çiplerini yalnız belirli adres aralıklarına yerleştirmek için adres çözümleme gereklidir.

Adres çözümleme daha önce I/O cihazları için uygulanmıştı. Hafıza arayüzünde fark, işlemcinin çift adresten 16 bitlik işlemi tek seferde yapabilmesidir; bunu desteklemek için bellek çift ve tek bloklara ayrılır. Hoca bunun I/O tarafıyla çelişmediğini hatırlatır: bir I/O cihazını ardışık çift adreslere yerleştirmek, onu çift blokta peş peşe gelen satırlara yerleştirmek demektir; ardışık tek adresler de tek bloğa karşılık gelir.

### 12.2 İzole I/O ve M/IO

Cihazın bir hafıza arayüzü, bir de I/O arayüzü vardır. Bu ikisi ayrı ayrı kullanılıp toplam kapasite artırılmak istenirse **izole I/O** kullanılır; bunun anlamı M/$\overline{IO}$ ucunun adres çözümlemeye katılmasıdır. Toplam kapasite 1 MB olarak bırakılıp bu alanın bir kısmı I/O'ya ayrılırsa bu **memory mapped I/O** olur ve M/$\overline{IO}$ adres çözümlemede kullanılmaz. Aksi belirtilmedikçe izole I/O kullanılacaktır; yani adres çözümlemede M/$\overline{IO}$ mutlaka kullanılır. Hafıza işlemlerinde M/$\overline{IO}$=1 olmalıdır, bu yüzden aktif-1 bir enable ucuna bağlanabilir.

### 12.3 Temel kural

Hafıza cihazlarına A1'den başlayarak, kapasitelerinin gerektirdiği $A_i$ ucuna kadar adres uçları bağlanır. Geri kalan üst adres uçları adres çözümleme mantığına gider. A0 ve $\overline{BHE}$'nin nerede kullanıldığına göre iki yöntem vardır.

### 12.4 Separate bank decoder

A0 ve $\overline{BHE}$ adres çözümleme devresine girer. Adres çözümleme mantığı iki çıkış üretir: biri çift blok için, diğeri tek blok için seçim ucu. Hafıza birimlerinin okuma/yazma uçlarına doğrudan $\overline{RD}$ ve $\overline{WR}$ bağlanır.

### 12.5 Separate bank strobe

Çift ve tek blokları içeren adres aralığı için tek bir chip select üretilir. İki bankı ayırt etmek için A0 ve $\overline{BHE}$, $\overline{RD}$ ve $\overline{WR}$ ile birleştirilir. $\overline{RD}$ aktif 0, $\overline{BHE}$ aktif 0 ve bağlanacakları read enable ucu da aktif 0 olduğu için, iki aktif-0 işareti bir aktif-0 uçta birleştirmek amacıyla **OR** kapısı kullanılır. A0 ile $\overline{RD}$ için de aynısı geçerlidir. Çift adresten bir okuma yapılırken A0=0, $\overline{BHE}$=1 olduğundan çift bank seçilir, tek bank seçilmez. Yazma işlemi için de aynı yapı $\overline{WR}$ ile kurulur.

> **Hocanın vurgusu:** Separate bank strobe ile separate bank decoder yöntemlerinin ayırt edilmesi önemli bir konudur.

## 13. Adres çözümleme elemanları: 3x8 ve 2x4 dekoder

Slayta göre adres çözümleme lojiği için çok girişli NAND kapısı, dekoder entegresi ya da PAL, PLD gibi programlanabilir lojik elemanlar kullanılabilir (ekrandan, 01:30:00). Hoca karmaşık devre tasarımlarının ve ROM'un da kullanılabileceğini ekler; derste daha çok dekoderler kullanılır.

**3x8 dekoder:** Üç giriş ucu vardır; en anlamlısı C, en düşük anlamlısı A'dır. C=1, B=1, A=0 verilirse ikilik 110 = 6 olduğundan 6 numaralı çıkış seçilir. Üç enable ucu vardır: biri aktif 1, ikisi aktif 0. Çıkışların hepsi aktif 0'dır: seçim yapıldığında yalnız bir çıkış 0, diğerleri 1 olur; cihaz seçilmezse çıkışların hepsi 1'dir. Bu, aktif-0 chip select için uygun bir çıkıştır.

**2x4 dekoder:** Daha düşük kapasiteler ya da daha az adres ucu için kullanılır. İki giriş ucu vardır (B daha anlamlı), bir aktif-0 enable ucu ve dört aktif-0 çıkış vardır. Enable'a 0 verilince BA sırasıyla verilen ikilik değere karşılık gelen çıkış 0, diğerleri 1 olur; cihaz seçilmezse hepsi 1'dir.

## 14. Örnek 1: 27128 EPROM ile F0000H'den 64 KB

### 14.1 Soru

Ekrandaki soru (ekrandan, 01:35:00):

> Örnek 1: 27128 EPROM (16Kx8)'den 4 adet kullanarak F0000H adresinden itibaren 64 KByte'lık bir alana EPROM yerleştiriniz.

Çözüm sayfasında ayrıca EPROM'un $\overline{CE}$/$\overline{OE}$ doğruluk tablosu vardır:

| $\overline{CE}$ | $\overline{OE}$ | Data |
|---|---|---|
| H | X | Hi-Z |
| L | H | Hi-Z |
| L | L | Data out |

### 14.2 Uç tanımları

Cihaz bir ROM olduğu için adres ve veri uçları ile $\overline{CE}$ (chip enable) ve $\overline{OE}$ uçlarına bakılır; ikisi de aktif 0'dır. 16Kx8 demek 16K hafıza gözü demektir:

$$16K = 2^4 \times 2^{10} = 2^{14}, \qquad \log_2 2^{14} = 14$$

Yani 14 adres ucu gerekir (whiteboard'da "16·2^10 = 2^4·2^10 = 2^14, log2 2^14 = 14", ekrandan 01:35:00). Kapasite "×8" olduğundan 8 veri ucu vardır.

### 14.3 Hafıza düzeni

Dört adet 16 KB'lık çip toplam 64 KB eder, ama işlemci bunu $32K \times 16$ biçiminde görmek ister. Çözüm sayfasında "8086 16 bit data interface yapılmalı, çift-tek bank uygulanmalı" ve "4 × (16Kx8) → 64KB → (32Kx16): data yolu genişletme, kapasite genişletme" yazılıdır (ekrandan, 01:35:00). Çipler 2x2'lik bir düzende yerleşir: bir sütun tek blok, diğeri çift blok; aynı satırdaki iki çip birlikte seçilerek 16 bit veri çıkarır. Böylece çift adresten 8 bit, tek adresten 8 bit ve çift adresten 16 bitlik işlemler desteklenir.

### 14.4 Adres aralıkları

Başlangıç F0000H'dir. 64 KB ilerlemek için kaç bit değişeceğine bakılır:

$$64K = 2^6 \times 2^{10} = 2^{16}$$

Yani alt 16 bit (dört onaltılık basamak) 0'dan 1'e döner ve bitiş adresi FFFFFH olur. Yarım adım (32K = $2^{15}$) gidildiğinde 15 bit değişir ve birinci satırın bitişi F7FFFH, ikinci satırın başlangıcı F8000H olur (ekrandan, 01:40:00):

- 1. satır: F0000H - F7FFFH (32 KB)
- 2. satır: F8000H - FFFFFH (32 KB)

İkilik yazım (A19 en solda):

```text
            A19-A16  A15  A14 ......... A1   A0
F0000H       1111     0   00 0000 0000 0000   0
F7FFFH       1111     0   11 1111 1111 1111   1
F8000H       1111     1   00 0000 0000 0000   0
FFFFFH       1111     1   11 1111 1111 1111   1
```

Bu tablodan:

- A0 çift ve tek bankı ayırmak için kullanılır ($\overline{BHE}$ ile birlikte).
- A1-A14, her satır içinde tüm değerleri alan 14 uçtur ve dört EPROM'un 14 adres ucuna ortak olarak bağlanır.
- A15 satırları ayırır: 0 ise üst satır, 1 ise alt satır.
- A16-A19 her iki satırda da 1'dir.

### 14.5 Bank ayırma: separate bank strobe

Çip bir ROM olduğu için yalnız okuma vardır; çift ve tek blokları ayırmak için separate bank strobe kullanılır. Whiteboard çizimine göre (ekrandan, 01:45:00) A0 ile $\overline{RD}$ bir OR kapısında birleşip çift sütundaki iki çipin $\overline{OE}$ ucuna, $\overline{RD}$ ile $\overline{BHE}$ ikinci bir OR kapısında birleşip tek sütundaki iki çipin $\overline{OE}$ ucuna gider. Tüm çiplerin adres uçlarına A1-A14 bağlanır. Böylece A0'dan A14'e kadar 15 uç kullanılmış olur.

### 14.6 Satır seçimi: dekoder

İki satırı ayıran A15'tir; ayrıca A16-A19 1 olmalıdır. Whiteboard'daki 3x8 dekoder bağlantısı (ekrandan, 01:50:00):

- C = A17, B = A16, A = A15
- M/$\overline{IO}$ → aktif-1 enable (hafıza işleminde M/$\overline{IO}$=1)
- A18 ve A19 → terslenerek aktif-0 enable uçlarına

<!-- BELİRSİZ: Hoca A18 ve A19 için "NAT kapısından geçirdim" diyor; bunun her biri için bir DEĞİL kapısı mı yoksa iki girişli bir NAND kapısı mı olduğu altyazıdan ve karelerden kesin okunamıyor. İkisi de A18=A19=1 koşulunda aktif-0 enable'ı 0 yapar. -->

Her iki satır için A17=1, A16=1'dir. A15=0 iken CBA = 110 olur ve **Y6** üst satırı seçer; A15=1 iken CBA = 111 olur ve **Y7** alt satırı seçer. Y6 üst satırdaki iki çipin, Y7 alt satırdaki iki çipin $\overline{CE}$ ucuna gider. Bu çözümde separate bank strobe mantığı kullanılmıştır.

### 14.7 Veri uçlarının birleştirilmesi

Hoca bir sonraki örneğe geçerken veri bağlantısını söylemediğini fark edip geri döner. Üst ve alt satır aynı anda seçilemez. Bu yüzden aynı sütundaki iki çipin D0'ları, D1'leri, ..., D7'leri ortak bağlanır. Tek blok sütununun veri uçları işlemcinin D8-D15 uçlarına, çift blok sütununun veri uçları D0-D7 uçlarına bağlanır; toplam 16 veri ucu elde edilir. İki satır aynı anda seçilemediği için ortak bağlantıda çakışma olmaz.

## 15. Örnek 2: 32Kx8 RAM ile 0 adresinden 128 KB

### 15.1 Soru ve uç tanımları

Aynı mantık bir RAM ile uygulanır: 32Kx8 kapasitesinde 4 adet RAM kullanarak 128 KB'lık bir alan 0 adresinden itibaren yerleştirilecek; adres çözümleme devresi nasıl kurulur?

Her eleman 32Kx8'dir: $32K = 2^5 \times 2^{10} = 2^{15}$, yani 15 adres ucu. RAM olduğu için $\overline{WE}$, $\overline{OE}$ ve $\overline{CS}$ uçları vardır. Toplam 128 KB'yi işlemci $64K \times 16$ olarak görmek ister.

### 15.2 Adres aralıkları

0 adresinden başlayıp 128K göz ilerlemek $128K = 2^{17}$ olduğu için 17 ucun değişmesi demektir: dört onaltılık basamak (16 bit) ve beşinci basamağın en düşük biti. Bitiş adresi 1FFFFH'dir. Dört RAM yine 2x2 düzende yerleşir:

- 1. satır: 00000H - 0FFFFH (64 KB)
- 2. satır: 10000H - 1FFFFH (64 KB)

(Altyazıda bu adresler "0'dan 0FF'e" ve "1.000'dan 1FF'e" diye kısaltılmış duyuluyor; doğru beş basamaklı yazım yukarıdaki gibidir.)

### 15.3 Bağlantılar

- A0 çift ve tek bank seçimine ayrılır.
- A1-A15 bütün RAM'lerin adres uçlarına bağlanır.
- Veri uçları: aynı sütundaki iki RAM'in D0'ları, D1'leri... ortak bağlanır; bir sütun D8-D15'e, diğeri D0-D7'ye gider. İki satır aynı anda seçilmeyecek biçimde adres çözümleme kurulduğu için çakışma olmaz.
- Satırları ayıran A16'dır (üst satır 0, alt satır 1); A17, A18 ve A19 0 olmalıdır.
- Dekoderde girişler A18, A17, A16 olarak düşünülürse üst satır için 000, alt satır için 001 oluşur: **0 numaralı çıkış** üst satırı, **1 numaralı çıkış** alt satırı seçer. Bir chip select ucu bir satırdaki iki RAM'e birden gider; böylece her satır kendi içinde birlikte seçilir.

Kısmen görünen bir karede dekoder girişleri C=A18, B=A17, A=A16, M/$\overline{IO}$ aktif-1 enable'a, A19 aktif-0 enable'a bağlı olarak görülür (ekrandan, 01:50:00).

<!-- BELİRSİZ: RAM örneğinin tam devre çizimi karelerde görünmüyor; 01:50:00 karesinin sol kenarında yalnız dekoder kısmen okunuyor, ikinci aktif-0 enable'ın bağlantısı ve çıkış etiketleri net değil. -->

### 15.4 Bank strobe'ları

RAM olduğu için hem okuma hem yazma vardır. $\overline{RD}$, $\overline{BHE}$ ve A0 ile birleştirilir; $\overline{WR}$ de $\overline{BHE}$ ve A0 ile birleştirilir. Hepsi aktif 0 olduğu için OR kullanılır. Böylece dört strobe işareti oluşur:

- "Read High" ve "Read Low": tek ve çift sütunların $\overline{OE}$ uçlarına.
- "Write High" ve "Write Low": tek ve çift sütunların $\overline{WE}$ uçlarına.

Tek adresle işlem yapıldığında tek sütun aktif olur; adrese göre ya üst ya alt satır seçilir. Adres çözümleme nedeniyle iki satırdaki bloklar aynı anda seçilemez, bu yüzden veri uçları anlatılan mantıkla birleştirilebilir.

## 16. Örnek: 80486 ve dört banklı hafıza

Hoca daha önce de değindiği bir örneği gösterir. 80486 (altyazıda "8486"), 32 bit veri yoluna ve 32 bit adres yoluna sahiptir ve bankları denetlemek için 4 kontrol ucu vardır. Hafıza arayüzünü $\times 32$ görmek ister, ama hafıza birimlerinin her biri 8 bittir; bu yüzden dörtlü bank yerleşimi zorunludur. Her bank için $\overline{BE0}$, $\overline{BE1}$, $\overline{BE2}$, $\overline{BE3}$ seçim uçları vardır.

80486 şu işlemleri tek okuma/yazma çevriminde destekler:

- çift adresten 8 bit ve tek adresten 8 bit,
- çift adresten 16 bit,
- 4'ün tam katı adreslerden 32 bit.

Bunun için adresler 4'e bölümünden kalanı 0, 1, 2 ve 3 olan dört banka gruplanır. A0 ve A1 bank seçimine ayrılır ve strobe işareti üretmekte kullanılır. Geri kalan adres uçlarından kapasiteyi sağlayacak kadarı hafıza bloklarının adres uçlarına bağlanır. Veri uçları her sütunda ortaktır. Strobe'lar, ilgili $\overline{BE}$ ucu $\overline{RD}$ ile birleştirilip o sütunun $\overline{OE}$ uçlarına bağlanarak üretilir.

Ekrandaki çözüm sayfasında (ekrandan, 01:55:00) şunlar yazılıdır: 256 KB'lık EPROM modülleri yerleştirilecek; $2\,\text{MB} / 256\,\text{KB} = 8$, yani 8 adet EPROM gerekli; 256 KB'lık modül 18 adres ucuna (A0-A17) ve 8 veri ucuna sahip; $8 \times (256K \times 8) \to 2\,\text{MB} = (512K \times 32)$; veri yolu 4 kat, kapasite 2 kat arttı. Banklar şöyledir:

| Bank ucu | EPROM'lar | Veri yolu |
|---|---|---|
| $\overline{BE3}$ | EPROM B3, EPROM A3 | D24-D31 |
| $\overline{BE2}$ | EPROM B2, EPROM A2 | D16-D23 |
| $\overline{BE1}$ | EPROM B1, EPROM A1 | D8-D15 |
| $\overline{BE0}$ | EPROM B0, EPROM A0 | D0-D7 |

Sayfanın altındaki "Assembly instruction" notu: 8 bitlik komut her bir banktan okuma, 16 bitlik komut ikili banklardan okuma, 32 bitlik komut tüm banklardan okuma yapar.

## 17. Hizalı adresler ve çözümlemenin kolaylığı

Hoca, derste görülen örneklerin hepsinin separate bank strobe ile çözüldüğünü, separate bank decoder örneğinin "örnek1.pdf" dosyasında bulunduğunu söyler ve geçmiş yılların bir vize sorusunu (özellikle RAM kısmını) öğrencilerin kendilerinin çözmesini önerir.

Son olarak bir noktayı vurgular: adresler kapasiteye hizalı geliyorsa adres çözümleme mantığı hızlıca çıkarılabilir. Hizalı olmak, yerleştirilecek kapasitenin başlangıç adresinin, o kapasite 0 adresinden başlatılmış gibi düşünüldüğünde referans başlangıç noktalarından birine denk gelmesidir. Hizalıysa adres çözümleme devresi çok kolaydır; değilse ek işlem gerekir. Hoca bununla ilgili bir vize örneği olduğunu düşünür, ama kontrol edince onun da hizalı olduğunu görür; bu yüzden hizasız bir örnek gösterilmez.

> **Ek bilgi (derste anlatılmadı):** Bu derste geçen iki örnek de hizalıdır: F0000H, 64 KB'nin ($10000H$) katıdır; 00000H de 128 KB'nin katıdır. Bu durumda alt adres bitleri bloğun içinde serbestçe değişirken üst bitler sabit kalır ve doğrudan dekoder girişlerine ya da enable uçlarına verilebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:10:50): 8086'nın reset vektörü nedir? Reset sonrasında CS ve IP'ye hangi değerler yüklenir ve işlemci hangi fiziksel adresten çalışmaya başlar?

**Çözüm:** CS = FFFFH, IP = 0000H. Fiziksel adres = FFFFH × 10H + 0000H = FFFF0H. Bu adreste BIOS ROM bulunmalıdır.

**Soru 2** (derste sözlü, 00:18:47): 4x4 ROM'da aktif-0 çıkışlı 2x4 dekoder bir satırı seçtiğinde, seçilmeyen dekoder çıkışlarında hangi lojik değer vardır?

**Çözüm:** Çıkışlar aktif 0 olduğu için seçilen çıkış lojik 0, seçilmeyen çıkışlar lojik 1'dir.

**Soru 3** (derste sözlü, 00:22:36): 4x4 ROM'da sigortayı korumak 0, yakmak 1 ise; 0. gözde D3-D0 için "yak, koru, yak, koru", 1. gözde "koru, koru, yak, yak", 2. gözde "koru, yak, koru, yak", 3. gözde "koru, yak, yak, yak" programlanırsa gözlere hangi değerler yazılmış olur?

**Çözüm:** 0. göz 1010 = AH, 1. göz 0011 = 3H, 2. göz 0101 = 5H, 3. göz 0111 = 7H.

**Soru 4** (derste sözlü, 00:51:31; tahta ekrandan, 00:55:00): Çift adresten 16 bitlik, tek adresten 8 bitlik ve çift adresten 8 bitlik birer komut örneği veriniz.

**Çözüm:** `MOV AX,[0]` (AL←[0], AH←[1]); `MOV AL,[1]` (AL←[1]); `MOV AH,[0]` (AH←[0]).

**Soru 5** (derste sözlü, 00:58:24; tahta ekrandan, 01:00:00): `MOV AX,[1]` komutu yürütülürse ne olur?

**Çözüm:** AL'ye 1 adresinin, AH'ye 2 adresinin içeriği gelmelidir. 1 adresi tek bankta, 2 adresi çift bankta ama bir sonraki satırdadır; A1-A19 değerleri farklıdır. İşlemci önce 1 adresini D8-D15 üzerinden AL'ye, sonra 2 adresini D0-D7 üzerinden AH'ye okur. İşlem iki okuma/yazma çevriminde tamamlanır.

**Soru 6** (ekrandan, 01:35:00): 27128 EPROM (16Kx8)'den 4 adet kullanarak F0000H adresinden itibaren 64 KByte'lık bir alana EPROM yerleştiriniz.

**Çözüm:** Her çip 14 adres, 8 veri ucu; düzen $32K \times 16$. Satırlar F0000H-F7FFFH ve F8000H-FFFFFH. A1-A14 tüm çiplere; A0+$\overline{RD}$ (OR) çift sütunun, $\overline{BHE}$+$\overline{RD}$ (OR) tek sütunun $\overline{OE}$'sine. 3x8 dekoder: C=A17, B=A16, A=A15, M/$\overline{IO}$ aktif-1 enable'a, A18 ve A19 terslenerek aktif-0 enable'lara; Y6 üst satırın, Y7 alt satırın $\overline{CE}$'sine. Tek sütun D8-D15'e, çift sütun D0-D7'ye; aynı sütundaki çiplerin veri uçları ortak. Ayrıntı için Bölüm 14.

**Soru 7** (derste sözlü, 01:48:18): 32Kx8 kapasitesindeki 4 adet RAM kullanarak 128 KB'lık bir alanı 0 adresinden itibaren yerleştiriniz.

**Çözüm:** Her RAM 15 adres ucu; düzen $64K \times 16$. Satırlar 00000H-0FFFFH ve 10000H-1FFFFH. A1-A15 tüm RAM'lere; A16 satırı ayırır, A17-A19 = 0 olmalı. Dekoderin 0 numaralı çıkışı üst satırı, 1 numaralı çıkışı alt satırı seçer. $\overline{RD}$ ve $\overline{WR}$, A0 ve $\overline{BHE}$ ile OR'lanarak dört strobe (Read High/Low, Write High/Low) üretilir ve $\overline{OE}$/$\overline{WE}$ uçlarına gider. Ayrıntı için Bölüm 15.

**Soru 8** (ekrandan, 01:55:00): 80486 sistemine 256 KB'lık EPROM modülleri kullanarak 2 MB'lık bir alan yerleştirmek için gerekli donanımı çiziniz.

<!-- BELİRSİZ: Soru metninin başı karede sayfanın üst kenarında kesik; yalnız "256KB'lık memory modülleri (EPROM) yerleştirmek için gerekli donanımı çiziniz" kısmı ve 2 MB hesabı okunuyor. Başlangıç adresi görünmüyor. -->

**Çözüm (ekrandaki çözüm sayfasından):** $2\,\text{MB} / 256\,\text{KB} = 8$ adet 256Kx8 EPROM gerekir (her biri 18 adres ucu, 8 veri ucu). $8 \times (256K \times 8) = 512K \times 32$: veri yolu 4 kat, kapasite 2 kat artar. Dört bank ($\overline{BE0}$-$\overline{BE3}$) sırasıyla D0-D7, D8-D15, D16-D23, D24-D31'e bağlanır; her bankta iki EPROM (A ve B satırı) vardır. Strobe'lar $\overline{BE_i}$ ile $\overline{RD}$ birleştirilerek her sütunun $\overline{OE}$ ucuna verilir.

## Dersin Toparlaması

Bu derste önce hafıza birimleri tanıtıldı. ROM kalıcıdır, 8086'nın FFFF0H'deki reset vektöründe BIOS ROM olarak bulunur; iç yapısı dekoder, sigortalı transistörler ve pull-up dirençlerden oluşur, kapasitesi $2^n \times m$'dir. RAM tarafında SRAM flip-flop temelli, yenileme gerektirmeyen ama hücre başına 6 transistör isteyen bir yapıdır; DRAM ise bir transistör ve bir kapasiteyle daha yoğundur, ama periyodik yenileme ister ve adres uçlarını satır ve sütun için iki kez kullanarak $2^{2n} \times m$ kapasiteye ulaşır. ROM ve SRAM için blok diyagramlar ve $\overline{OE}\leftrightarrow\overline{RD}$, $\overline{WE}\leftrightarrow\overline{WR}$, $\overline{CS}\leftrightarrow$ adres çözümleme ilişkileri verildi.

Dersin ikinci yarısı 8086'nın hafıza arayüzüne ayrıldı. 8086, 1 MB'yi $512K \times 16$ olarak görmek ister: bellek A0 ile seçilen ve D0-D7'ye bağlı çift bank ile $\overline{BHE}$ ile seçilen ve D8-D15'e bağlı tek bank olarak ikiye ayrılır. Çift adresten 8/16 bit ve tek adresten 8 bit tek çevrimde, tek adresten 16 bit iki çevrimde yapılır; bu yüzden veri hizalaması önemlidir. Adres çözümlemede hafıza çiplerine A1'den itibaren adres uçları bağlanır, üst uçlar ve M/$\overline{IO}$ dekodere gider; banklar separate bank decoder ya da separate bank strobe ile ayrılır. 27128 EPROM ve 32Kx8 RAM örnekleri strobe yöntemiyle çözüldü, 80486'nın dört banklı yapısı genelleme olarak gösterildi. Bu ders dönemin son konusuydu; hafıza arayüzü önceki kesme ve çevre birimi konularıyla birlikte dönemin kapanışını oluşturdu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
