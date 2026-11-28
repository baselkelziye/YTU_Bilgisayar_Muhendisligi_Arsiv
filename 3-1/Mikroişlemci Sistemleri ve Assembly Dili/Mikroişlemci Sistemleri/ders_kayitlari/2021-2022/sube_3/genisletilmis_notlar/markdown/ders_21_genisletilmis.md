# Ders 21 Genişletilmiş Notu: 8254 Programlanabilir Aralık Zamanlayıcısı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Zamanlayıcı ve sayıcı kavramları
- 2. 8254'ün kullanım alanları ve genel özellikleri
- 3. İç yapı ve uç tanımları
- 4. Kontrol sözcüğü
- 5. Binary ve BCD modda en büyük sayma
- 6. 8254 ayarlama örneği
- 7. 8254'ün çalışma modları
- 8. İç yapıya yeniden bakış: Counter Latch ve Read-Back komutları
- 9. Durum baytı
- 10. Modların özeti ve sonraki derse bağlantı
- Örnek Sorular

## 1. Zamanlayıcı ve sayıcı kavramları

Bu derste yeni bir programlanabilir yardımcı devreye geçildi: 8254. Adı Programmable Interval Timer (PIT), yani programlanabilir aralık zamanlayıcısıdır. Bir bilgisayar sisteminde bazı işlemlerin belirli, periyodik aralıklarla yapılması gerekir. Hoca iki tanıdık örnek verdi. Birincisi bilgisayar açılırken yapılan kontroller: bir hata bulunursa hoparlörden belirli, sabit frekanslı sesler duyulur; bu sabit frekansı üretmek 8254'ün işi olabilir. İkincisi dinamik RAM'lerdir: DRAM hücrelerindeki değerin belirli aralıklarla yeniden yazılması (refresh) gerekir ve bu periyodik işlem de 8254 ile tetiklenebilir.

8254 yalnız bir sayıcı ya da yalnız bir zamanlayıcı değil, ikisidir. Aradaki fark devrenin iç yapısında değil, sayacın saat girişine neyin bağlandığındadır:

- Bir sayacın clock girişine **sabit frekanslı bir kare dalga** bağlanırsa devre bir **zamanlayıcı** olur. Saat darbelerinin süresi bilindiği için sayılan darbe sayısı geçen süreyi verir. Hoparlör sesi ve DRAM yenileme örnekleri zamanlayıcı kullanımlarıdır.
- Sayacın clock girişine **ayrık olayları algılayan bir sensör** bağlanırsa devre bir **sayıcı** olur.

Sayıcı örneği olarak hoca bir konveyör bant düşündürdü. Bandın iki yanına karşılıklı bir alıcı-verici ikilisi yerleştirilir; bir ürün aradan geçtiğinde sensör 0-1 geçişi şeklinde bir darbe üretir. Ürünlerin geliş aralıkları düzensizdir: biri 1 saniyede, diğeri 5 saniyede gelebilir, yani olaylar aperiyodiktir. 8254'ün saat girişine bu asenkron sensör bağlanırsa devre geçen ürünleri sayar. Benzer biçimde saat girişi ayakkabıya bağlanan bir butona ya da bir ivme ölçere bağlanırsa her adımda bir azalan bir adım sayıcı elde edilir.

## 2. 8254'ün kullanım alanları ve genel özellikleri

Slayttaki tanıma göre 8254 temelde yazılım kontrollü, kesin ve doğru zaman gecikmeleri oluşturmak için kullanılır; ayrıca olay sayıcı, gerçek zamanlı saat (real time clock), kare dalga üreteci, karmaşık dalga üreteci ve dijital "one shot" işlemleri için kullanılır (ekrandan, 00:10:00).

8254'e harici bir saat üreteci bağlanır. Bu üreteç sabit ve kararlı bir frekansta çalışıyorsa her saat darbesinin ne kadar süreye karşılık geldiği hesaplanabilir. 8254'ün içindeki sayacın değerindeki değişime bakılarak ne kadar zaman geçtiği ölçülür. Hassas zamanlamalar bu yolla yapılır.

**Karmaşık dalga şekli** derken hoca örneğin PWM işaretini kastetti. PWM işareti periyodu sabit bir kare dalgadır, ama bir periyot içinde 1'de kalma süresi ayarlanabilir. 8254 ile birlikte bazı yardımcı lojik devreler ve flip-floplar kullanılarak üretilebilir. Uzaktan kumandalı (RC) sistemlerde, örneğin bir model uçağın arka kanadının yüksekliğini değiştiren komut böyle bir işaretle verilir.

**One shot** işlemler belirli bir süre sonunda bir kez gerçekleşecek işlemlerdir: $t_0$ anından itibaren saymaya başla, tam 10 saniye sonra bir tetikleme üret. Zamanlaması hassas, bir kez yürütülen işlem demektir.

### 2.1 Genel özellikler

- 8254'te birbirinden bağımsız **üç adet 16 bitlik sayıcı** vardır.
- Her sayıcı diğerlerinden bağımsız olarak mod 0'dan mod 5'e kadar **altı moddan** herhangi birinde programlanabilir.
- Her sayıcı **8 MHz'e kadar** saat girişini destekler. Bu, $1/(8\times10^6)$ saniyelik (125 ns) hassas ölçümler yapılabileceği anlamına gelir.
- Sayıcılar **aşağı sayıcıdır** (down counter). Sayıcıya bir ilk değer (initial value) yüklenir, saat girişine bir kare dalga verilir ve her saat darbesinde değer bir azalır. Sayaç 0'a ulaştığında OUT ucunda bir değişiklik olur. Bu değişikliğin biçimi moda göre farklıdır; yine moda göre ilk değer sıfıra düştükten sonra periyodik olarak yeniden yüklenebilir ya da sayıcı bir kez çalışıp durabilir.

Genel olarak her sayıcı bir **frekans bölücü** gibi düşünülebilir: girişteki frekansı yüklenen değere bölerek bir çıkış üretir.

PC'deki kullanım örnekleri: sistem saatinin üretilmesi, DRAM'lerin yenilenmesi ve hoparlörden uyarı seslerinin üretilmesi.

## 3. İç yapı ve uç tanımları

### 3.1 Blok yapı

Slayttaki iç yapı şeması şu bloklardan oluşur (ekrandan, 00:15:00):

- **Data Bus Buffer:** D0-D7 veri uçlarını iç yola bağlayan tampon; 8254'ün 8086 ile haberleşmesini sağlar.
- **Read/Write Logic:** girişleri $\overline{RD}$, $\overline{WR}$, A0, A1 ve $\overline{CS}$'dir.
- **Control Word Register:** kontrol sözcüğünün yazıldığı yazmaç; üç sayıcıya bağlıdır.
- **Internal Bus:** iç yol.
- **Counter 0, Counter 1, Counter 2:** her birinin kendine ait CLK (giriş), GATE (giriş) ve OUT (çıkış) uçları vardır.

Her sayıcının kendine ait bir saat girişi ve sayma bittiğinde dış dünyaya çıktı veren kendi OUT ucu vardır. GATE ucu ise sayıcıyı donanımsal olarak dışarıdan kontrol etmeye yarar: saymayı duraklatmak ya da yeni bir saymayı tetiklemek için kullanılabilir.

### 3.2 8086 tarafındaki uçlar

**Veri uçları.** 8254'ün 8 veri ucu vardır. 8086'nın veri yolu 16 bittir; 16 bitlik veri yolu olan bir işlemcide 8 bitlik bir çevre birimi kullanılmaktadır. Ek donanım kullanmadan bağlanabilmesi için 8254, daha önce 8255 için yapıldığı gibi ardışık çift adreslere ya da ardışık tek adreslere yerleştirilir.

**$\overline{RD}$ ve $\overline{WR}$.** 8254'ün $\overline{RD}$ ucuna 8086'nın $\overline{RD}$ ucu, $\overline{WR}$ ucuna da 8086'nın $\overline{WR}$ ucu bağlanır.

**Adres uçları.** 8254'ün iki adres ucu (A1, A0) vardır. Bu yüzden cihaz G/Ç uzayında 4 baytlık yer kaplar; yani dışarıdan erişilebilir 4 yazmaç vardır. Seçim tablosu (ekrandan, 00:20:00):

| A1 | A0 | Seçim |
|----|----|-------|
| 0 | 0 | Counter 0 |
| 0 | 1 | Counter 1 |
| 1 | 0 | Counter 2 |
| 1 | 1 | Control Register |

Hoca bir adresin arkasında birden fazla yazmaç olduğunu özellikle belirtti: her sayıcı 16 bitlik olduğu için ona bir ilk değer yazmak iki bayt göndermeyi gerektirir; veri yolu 8 bit olduğundan 16 bitlik değer ancak iki seferde gönderilebilir.

**$\overline{CS}$.** Chip select ucu diğer çevre birimlerinde olduğu gibi çalışır: 8254'ün adreslerine bir IN/OUT komutu yürütüldüğünde adres çözücü $\overline{CS}$ üzerinden cihazı etkinleştirir. Cihaz seçilmezse veri uçları 8086'nın veri yoluna yüksek empedans gösterir; sanki uçlar hattan koparılmış gibi davranır.

### 3.3 Dış dünya tarafındaki uçlar

- **CLK:** sayıcılar için saat girişi.
- **GATE:** sayıcılar için dış kontrol ucu (saymayı durdurma ya da yeniden tetikleme).
- **OUT:** sayma işlemi bittiğinde değişen uç; slayta göre sayma bittiğinde 1 olur ve INTR için kullanılabilir (ekrandan, 00:20:00).

OUT ucu bir kesme istek ucu olarak da kullanılabilir. Hoca bunu önceki çevre birimleriyle ilişkilendirdi: 8251'de RxRDY ve TxRDY uçları, 8255'te mod 1 ve mod 2'deki INTRA ve INTRB uçları da kesme isteği için kullanılabiliyordu. Ancak derste şimdiye kadar hep yoklama (polling) mantığı kullanıldı ve 8254'te de bu sürdürülecek: bir işlemin bitip bitmediği, durum yazmacından OUT ucunun değeri okunarak anlaşılacak. Kesmeler görüldükten sonra bu uçlar kesme hattına bağlanarak farklı bir veri alışverişi kurulacak.

## 4. Kontrol sözcüğü

Kontrol sözcüğü (control word) 8254'ün programlandığı yazmaçtır. Ona bir değer yazıldığında sayıcılar ayarlanır ya da 8254'e bazı komutlar gönderilir.

### 4.1 Yazma koşulları ve bit düzeni

Kontrol yazmacına yazabilmek için adres uçlarında 11 bulunmalı, 8254 seçilmiş olmalı ve bir yazma işlemi yapılmalıdır. Slayttaki koşul: A1, A0 = 11, $\overline{CS}$ = 0, $\overline{RD}$ = 1, $\overline{WR}$ = 0 (ekrandan, 00:25:00).

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| SC1 | SC0 | RW1 | RW0 | M2 | M1 | M0 | BCD |

**SC (Select Counter), D7-D6:**

| SC1 | SC0 | Anlamı |
|-----|-----|--------|
| 0 | 0 | Counter 0 seçilir |
| 0 | 1 | Counter 1 seçilir |
| 1 | 0 | Counter 2 seçilir |
| 1 | 1 | Read-Back komutu |

Hoca 11 durumunu ilk anlatımda geçti, "özel bir durum" diyerek dersin sonuna bıraktı (bkz. Bölüm 8).

**RW (Read/Write), D5-D4:**

| RW1 | RW0 | Anlamı |
|-----|-----|--------|
| 0 | 0 | Counter Latch komutu |
| 0 | 1 | Yalnız düşük anlamlı bayt (LSB) okunur/yazılır |
| 1 | 0 | Yalnız yüksek anlamlı bayt (MSB) okunur/yazılır |
| 1 | 1 | Önce LSB, sonra MSB |

RW = 01 seçilirse seçilen 16 bitlik sayıcının yalnız düşük anlamlı 8 bitine ilk değer gönderilir. RW = 10 seçilirse yalnız yüksek anlamlı bayt gönderilir; örneğin ilk değer olarak AA00H gönderilmek istenirse RW = 10 seçip yalnız AAH göndermek yeter. RW = 11 seçilirse 16 bitlik değer iki paket halinde, önce LSB sonra MSB olarak gönderilir. Hoca, kontrol sözcüğü yazılırken değerin henüz gönderilmediğini, bu aşamada yalnız gönderme biçiminin programlandığını vurguladı.

**M (Mode), D3-D1:**

| M2 | M1 | M0 | Mod |
|----|----|----|-----|
| 0 | 0 | 0 | Mod 0 |
| 0 | 0 | 1 | Mod 1 |
| X | 1 | 0 | Mod 2 |
| X | 1 | 1 | Mod 3 |
| 1 | 0 | 0 | Mod 4 |
| 1 | 0 | 1 | Mod 5 |

Mod 2 ve mod 3'te D3 bitinin bir anlamı yoktur.

**BCD, D0:** 0 ise sayıcı 16 bitlik ikili (binary) sayıcıdır; 1 ise 4 onluk basamaklı BCD sayıcıdır. Bu bit hem gönderilecek ilk değerin hem de saymanın binary mi BCD mi olacağını belirler.

### 4.2 İlk değerin gönderilmesi

Bir sayıcı iki adımda ayarlanır:

1. Kontrol yazmacına, ilgili sayıcının numarası, bayt biçimi, mod ve sayma tipi yazılır.
2. Sayıcının kendi adresi hesaplanır ve oraya RW ayarına göre bir ya da iki yazma yapılır. Sayıcı adresine yapılan bu yazmalar ilk sayma değerini sayıcıya atar.

> **Hocanın vurgusu:** Kontrol yazmacına yazılan sözcük sayma değerini göndermez; değer ancak ikinci adımda, sayıcının kendi adresine yapılan yazmalarla gider. Bu önemli bir noktadır.

## 5. Binary ve BCD modda en büyük sayma

Hoca burada derse bir soru yöneltti: sayıcı binary modda ve RW = 11 (16 bit) ayarlandıysa sayıcıya yazılabilecek en büyük ilk değer nedir, sayıcı en çok kaç adım sayar?

Bir süre cevap gelmeyince soru yeniden açıklandı: sayıcıya ilk değer yüklenir, sayıcı bu değerden 0'a doğru sayar; en çok 16 bit gönderilebiliyorsa binary sayıcı en çok kaç adım sayar?

**Soru:** En büyük değer 65535 mi? **Cevap:** Evet. Gönderilebilecek bütün bitler 1 olursa FFFFH gönderilmiş olur; bunun onluk karşılığı 65535'tir. Sayıcı 0'a da düşeceği için toplam 65536 adım sayılabilir.

Binary modda geri sayma onaltılık düzende ilerler: ... FFF0, FFEF, ... gibi değerler birer birer azalır.

Ardından soru BCD mod için değiştirildi. 16 bitlik değere 4 BCD basamak sığar mı? Bir öğrencinin cevabıyla: sığar, çünkü her BCD basamak 4 bittir. BCD basamaklar 0'dan 9'a kadar değer alır. Dolayısıyla BCD modda yazılabilecek en büyük değer 9999'dur; sıfır da sayılınca en çok 10000 adım sayılabilir. BCD modda geri sayma onluk düzende yapılır: 9999, 9998, 9997, ..., 9990, 9989, ... Gösterim yine ikilidir, ama her basamak kendi ikili karşılığıyla tutulur.

Özetle:

| Sayma tipi | En büyük yazılabilen değer | En çok adım |
|------------|---------------------------|-------------|
| Binary | FFFFH (65535) | 65536 |
| BCD | 9999 | 10000 |

> **Ders sonrası not:** Hoca 65536 adımı "FFFFH ve sıfır da sayılınca" diye açıkladı. 8254'te FFFFH yazılırsa sayıcı 65535 saat darbesi sayar; 65536 adımlık en büyük sayma, ilk değer olarak 0000H yazılarak elde edilir. BCD modda da en büyük sayma (10000) ilk değer 0000 yazılarak elde edilir (büyük olasılıkla, 8254 veri sayfasına göre).

## 6. 8254 ayarlama örneği

### 6.1 Soru ve adresler

Slayttaki soru (ekrandan, 00:35:00): 98H adresinden itibaren ardışık çift adreslere yerleştirilmiş 8254 için

- CNTR0: mod 3, CLK0'ı 4282 (BCD)'ye bölecek şekilde ayarlayın.
- CNTR2: binary sayma, mod 3, CLK2'yi C26A hex'e bölecek şekilde ayarlayın.
- CLK0 = 1,2 MHz, CLK2 = 1,8 MHz ise çıkış frekansları nedir?

Ardışık çift adreslerde adresler şöyledir:

| Yazmaç | Adres |
|--------|-------|
| Counter 0 | 98H |
| Counter 1 | 9AH |
| Counter 2 | 9CH |
| Kontrol yazmacı | 9EH |

Önce tersten bir okuma yapıldı: slayttaki bir kodda 9EH adresine gönderilen 37H değeri kontrol sözcüğüdür. 0011 0111 açılırsa SC = 00 (Counter 0), RW = 11 (önce LSB sonra MSB), mod = 011 (mod 3) bulunur. Sonra aynı sorunun çözümü adım adım kuruldu.

> **Ders sonrası not:** Hoca adresleri sayarken bir yerde "98H'de Counter 1, 9AH'da Counter 2, 9CH'da Counter 3" dedi; doğrusu tablodaki gibidir (98H Counter 0, 9AH Counter 1, 9CH Counter 2). 8254'te Counter 3 yoktur ve hoca çözümün devamında 9CH'yi Counter 2 olarak kullandı.

### 6.2 Counter 0'ın ayarlanması (BCD, mod 3)

- Counter 0 seçimi: SC = 00.
- İlk değer 4282 (BCD). BCD bir değeri yazmak için basamaklar onaltılık sayı gibi düşünülür: 4 → 0100, 2 → 0010, 8 → 1000, 2 → 0010. Yazılacak ikili değer 0100 0010 1000 0010 = 4282H olur. Hoca beyaz tahtada bu dönüşümü yazarken 8'in karşılığını önce yanlış yazıp düzeltti.
- Değer 8 bite sığmadığı için 16 bit gönderilecek: RW = 11.
- Mod 3: 011.
- BCD sayma: D0 = 1.

Kontrol sözcüğü: 00 11 011 1 = **37H**. Bu değer kontrol yazmacına (9EH) gönderilir. İkinci adımda sayma değeri Counter 0'ın adresine (98H) yazılır; önce LSB (82H), sonra MSB (42H).

### 6.3 Counter 2'nin ayarlanması (binary, mod 3)

- Counter 2 seçimi: SC = 10.
- Değer 8 bite sığmıyor: RW = 11.
- Mod 3: 011.
- Binary sayma: D0 = 0.

Kontrol sözcüğü: 10 11 011 0 = **B6H**. Bu değer 9EH'ye gönderilir. Sayma değeri C26AH, hesap makinesinde onluk olarak 49770'tir (ekrandan, 00:40:00). Hoca "daha anlamlı bir sayı hatırlamıştım" diyerek sayının özel bir anlamı olmadığını belirtti. Değer AX'e alınır; AL'deki düşük bayt (6AH) Counter 2'nin adresine (9CH) gönderilir, sonra AH'deki yüksek bayt AL'ye kopyalanıp yine 9CH'ye gönderilir.

### 6.4 Kod

Slayttaki kod (ekrandan, 00:40:00):

```text
a) MOV AL, 37H           b) MOV AL, 0B6H
   OUT 9EH, AL              OUT 9EH, AL
   MOV AX, 4282H            MOV AX, 0C26AH
   OUT 98H, AL              OUT 9CH, AL
   MOV AL, AH               MOV AL, AH
   OUT 98H, AL              OUT 9CH, AL
```

Hoca a şıkkını önce tek tek MOV AL, 82H / OUT 98H, AL / MOV AL, 42H / OUT 98H, AL biçiminde yazdı; slayttaki biçimde ise değer bir kerede AX'e atanır, AL'de kalan 82H önce gönderilir, sonra AH'deki 42H AL'ye alınıp gönderilir. İki yazım aynı sonucu verir.

### 6.5 Çıkış frekansları

Mod 3 tekrarlı bir moddur, yani periyodik bir dalga üretir; soru bu bilgiyle cevaplanır. Sayıcı frekans bölücü olarak çalışır:

$$f_{OUT} = \frac{f_{CLK}}{N}$$

- Counter 0: $f_{OUT0} = 1{,}2\ \text{MHz} / 4282 \approx 280\ \text{Hz}$. Giriş 1,2 MHz'lik bir kare dalga, çıkış 280 Hz'lik bir kare dalgadır.
- Counter 2: $f_{OUT2} = 1{,}8\ \text{MHz} / 49770 \approx 36\ \text{Hz}$.

Python ile doğrulama: $1{,}2\times10^6/4282 = 280{,}24$ Hz, $1{,}8\times10^6/49770 = 36{,}17$ Hz.

> **Ders sonrası not:** Slayttaki soruda CNTR0 için "binary sayma" yazıyor; ancak değer 4282 (BCD) olarak verilmiş ve hoca kontrol sözcüğünü BCD = 1 ile (37H) kurdu, slayttaki kod da 37H kullanıyor. Çözüm BCD sayma üzerinedir. Ayrıca soru "OUT1 ve OUT2 frekansı" diye soruyor; ayarlanan sayıcılar 0 ve 2 olduğundan hesaplanan frekanslar OUT0 ve OUT2'dir.

## 7. 8254'ün çalışma modları

8254'ün altı modu vardır. Bir kısmı **bir kerelik** çalışır: yazılımla ayarlanır, saymaya başlar, sayma bitince bir kez tetikleme üretir ve durur. Bir kısmı **tekrarlı** çalışır: programlanır, ilk değer gönderilir, bir periyot çalışıp çıktı üretir, sonra ilk değeri kendisi yeniden yükleyip yeniden çalışır; yeniden programlamaya gerek yoktur ve periyodik sinyal üretilir. Bazı modlar dışarıdan GATE ucuyla tetiklenir, bazıları GATE ucuyla duraklatılır. Hoca modların adlarını ezberlemek yerine işlevleriyle öğrenilmesinin daha anlamlı olduğunu söyledi.

Zamanlama diyagramlarında WR satırı 8086'nın 8254'e yaptığı yazmaları (kontrol sözcüğü ve sayma değeri), CLK satırı ilgili sayıcının saat ucunu, GATE satırı geçit ucunu, OUT satırı çıkışı, en alttaki satır ise her saat periyodunda sayıcının içindeki değeri gösterir (N: henüz geçerli bir değer yok).

### 7.1 Mod 0: sayma sonunda kesme (interrupt on terminal count)

Slayttaki özet (ekrandan, 00:45:00):

- Kontrol yazıldıktan sonra OUT 1→0.
- Her CLK düşen kenarında sayma değerini azaltır.
- GATE = 1 ise geri sayar, GATE = 0 ise sayma durur.
- Sayma değeri 0 olduğunda OUT 0→1, öyle kalır.
- Yeni kontrol veya sayma değeri yazılırsa tekrar sayar.

Kontrol sözcüğü gönderilir gönderilmez OUT 0'a düşer (zaten 0'daysa 0'da kalır). İlk değer gönderilir, sayıcı her saat düşen kenarında bir azalır. Sayma değeri 0 olunca OUT 1'e çıkar ve öyle kalır. Sayma bitince bir kesme ya da tetikleme üretmeye uygun olduğu için adı "interrupt on terminal count"tur. GATE bu modda duraklatma (pause) işlevi görür: sayma sırasında GATE 0'a çekilirse sayma durur, yeniden 1'e çekilirse kaldığı yerden devam eder. Böylece araya dışarıdan bir gecikme konabilir.

**Diyagram örneği** (ekrandan, 00:50:00). 8086 kontrol yazmacına 10H göndermiştir: 0001 0000 → Counter 0, RW = 01 (yalnız LSB), mod 0, binary. Kontrol sözcüğü yazılır yazılmaz OUT 0'a düşer; henüz geçerli bir sayma değeri yüklenmediği için sayıcı değeri N olarak görünür. Ardından LSB = 3 gönderilir; değer saat işaretiyle örneklenip sayıcıya alınır ve sonraki her düşen kenarda bir azalır. Diyagramdaki sayıcı değerleri:

```text
N  N  N  N  0003  0002  0001  0002  0001  0000  FFFF
```

Sayma değeri 0 olunca OUT 1'e çıkar ve öyle kalır; sayıcı FFFF'e dönerek saymayı sürdürür. Hoca diyagramın başka bir örneğinde GATE'in 0'a düştüğü aralıklarda düşen kenarlar gelse bile sayıcının azalmadığını, beklediğini gösterdi.

> **Ders sonrası not:** Hoca mod 0'da sayma sürerken gönderilen yeni bir değerin önceki sayma bittikten sonra etkili olduğunu söyledi. Ekrandaki diyagramda ise ikinci yazma (LSB = 2) sayma 0001'deyken yapılıyor ve sayma 0002, 0001, 0000 diye yeni değerden sürüyor. Yani mod 0'da yeni değer bir sonraki saat darbesinde yüklenir. Mevcut periyodun bitmesini bekleyen davranış mod 2 ve mod 3'e, bir sonraki tetiklemeyi bekleyen davranış mod 1 ve mod 5'e aittir.

Mod 0 yazılımla kontrol edilen bir moddur: kontrol ve sayma değeri gönderilince sayma başlar, bitince OUT 0'dan 1'e çıkıp öyle kalır; tekrarlamak için yeni bir mod 0 komutu gönderilir.

### 7.2 Mod 1: donanımla yeniden tetiklenebilen tek darbe

Mod 1, mod 0'ın dışarıdan, donanımsal olarak kontrol edilebilen bir sürümüdür. Kontrol sözcüğü ve sayma değeri yüklenir; o sırada GATE'te 0 vardır ve OUT boşta (idle) 1'de bekler. Saymayı başlatmak için GATE'te bir 0-1 geçişi gerekir. Bu geçişten sonra OUT, mod 0'daki gibi 0'a düşer; sayma bitince 1'e çıkar.

Diyagram örneğinde kontrol sözcüğü 12H'dir (0001 0010: Counter 0, yalnız LSB, mod 1, binary) ve sayma değeri 3'tür (ekrandan, 01:15:00). OUT, GATE'te 0-1 geçişi görene kadar boşta bekler. Geçişten sonraki düşen kenarlarla sayıcı 3, 2, 1, 0 diye sayar; 0'da OUT yeniden 1'e çıkar ve yeni bir GATE geçişine kadar öyle kalır.

- Her yeni GATE yükselen kenarı, en son yüklenen sayma değeriyle saymayı yeniden başlatır.
- Sayma bitmeden GATE'te yeniden tetikleme gelirse en son yüklenen değer yeniden yüklenir ve sayma baştan başlar; OUT bu sırada 0'da kalır.
- Sayma sırasında gönderilen yeni bir sayma değeri hemen etkili olmaz; ancak bir sonraki GATE tetiklemesinde kullanılır. Örneğin 2 için sayma sürerken 4 gönderilirse 4'ten sayma bir sonraki GATE geçişinde başlar.

### 7.3 Mod 2: tekrarlı darbe üreteci

Mod 2 tekrarlı, periyodik ve darbe (puls) üreten bir moddur. Örneğin sayma değeri 10 ise sürenin 9 saat periyodu boyunca OUT 1'de kalır, tek bir saat periyodu boyunca 0'a düşer. OUT boşta 1'de bekler; sayma değerinin son adımında OUT 0'a düşer, bir saat periyodu sonra yeniden 1'e çıkar ve değer otomatik olarak yeniden yüklenir.

- GATE saymayı duraklatmak için kullanılır (GATE = 0 iken sayma durur).
- Yeni bir sayma değerinin etkisi mevcut periyot bittikten sonra görülür. Örneğin 4'ten geri sayılırken 5 gönderilirse 5 bir sonraki periyotta kullanılır.
- İlk yazma tam olarak verilen sayma kadar sürmeyebilir, ama ilk periyot dışındaki bütün periyotlar verilen sayma değerine tam uyar.

Diyagram örneği (ekrandan, 00:55:00): kontrol sözcüğü 14H (0001 0100: Counter 0, yalnız LSB, mod 2, binary), sayma değeri LSB = 3. Sayıcı değerleri:

```text
N  N  N  N  0003  0002  0001  0003  0002  0001  0003
```

Değer 1'deyken OUT bir saat periyodu boyunca 0'a düşer, sonra 1'e çıkar; böylece "uzun süre 1, kısa süre 0" biçiminde periyodik bir darbe dizisi üretilir.

#### Mod 2 örneği

**Soru:** Clock 0'a 2 MHz'lik bir işaret bağlıdır. Counter 0'ı 50 µs'de bir darbe üretecek şekilde ayarlayın.

Bu örnekte anlaşılması gereken nokta birim dönüşümüdür: saat frekansla, darbe ise periyotla (saniye cinsinden) verilmiştir. 50 µs'de bir tekrarlanan işaretin frekansı:

$$f_{OUT} = \frac{1}{50\times10^{-6}\ \text{s}} = 20\ \text{kHz}$$

Sayıcı giriş frekansını sayma değerine bölüyordu; o halde giriş frekansı çıkış frekansına bölünürse sayma değeri bulunur:

$$N = \frac{f_{CLK}}{f_{OUT}} = \frac{2\times10^6}{20\times10^3} = 100 = 64\text{H}$$

100 değeri 8 bite sığdığı için yalnız LSB göndermek yeterlidir. Kontrol sözcüğü: Counter 0 için 00, yalnız LSB için 01, mod 2 için 010, binary için 0 → 0001 0100 = **14H**. Önce 14H kontrol yazmacına, sonra 64H tek bir yazmayla Counter 0'ın adresine gönderilir; bu Counter 0'ın mod 2'de çalışmasını başlatır. <!-- BELİRSİZ: bu örneğin slayttaki kodu ve kullanılan port adresleri karelerde yakalanmadı. -->

### 7.4 Mod 3: kare dalga üreteci

Mod 2'de işaret uzun süre 1'de kalıp tek bir saat periyodu boyunca 0'a düşüyordu; doluluk oranı (duty cycle) çok yüksekti. Kare dalgada ise işaretin 1'de ve 0'da kalma süreleri birbirine eşit ya da çok yakındır. Mod 3 bu yüzden yaklaşık %50 doluluk oranlı, periyodik olarak tekrarlanan bir kare dalga üretir. GATE = 0 yine saymayı durdurur.

Diyagram örneği (ekrandan, 01:10:00): kontrol sözcüğü 16H (0001 0110: Counter 0, yalnız LSB, mod 3, binary), sayma değeri LSB = 4. Kontrol sözcüğü yazılınca OUT 1'e çıkar. Sayma değeri gönderildikten sonra sayıcı her düşen kenarda ikişer azalır:

```text
N  N  N  N  0004  0002  0004  0002  0004  0002 ...
```

Değer her yeniden yüklendiğinde OUT seviye değiştirir; böylece sayma değerinin yarısı kadar süre 1'de, yarısı kadar süre 0'da kalan bir kare dalga elde edilir.

Gönderilen değer tek sayı olursa fazlalık, işaretin 1 olduğu yarıya eklenir; doluluk oranı %50'den biraz büyük olur. GATE'in 0 olması saymayı o an durdurur.

#### Mod 3 örneği

**Soru:** Counter 1'in saat ucuna 2 MHz'lik bir saat işareti bağlıdır. Counter 1'i 1 kHz frekansında kare dalga üretecek şekilde ayarlayın.

$$N = \frac{2\times10^6}{1\times10^3} = 2000$$

2000 değeri hem BCD sınırına (9999) hem binary sınırına sığar. Hoca çeşitlilik olsun diye 2000'i BCD olarak gönderdi. 16 bitlik değer olduğu için RW = 11 seçilir. Kontrol sözcüğü: Counter 1 için 01, önce LSB sonra MSB için 11, mod 3 için 011, BCD için 1 → 0111 0111 = **77H**. Önce kontrol sözcüğü kontrol adresine yazılır; sonra 2000 (BCD) değerinin düşük anlamlı baytı (00H) ve ardından yüksek anlamlı baytı (20H) Counter 1'in adresine gönderilir. Bu andan itibaren sayıcı 2000 (BCD) değerinden geriye sayar; 2000'lik sayma süresinin yarısında OUT lojik 1'de, yarısında lojik 0'dadır. <!-- BELİRSİZ: bu örneğin slayttaki kodu ve port adresleri karelerde yakalanmadı; LSB/MSB değerleri (00H, 20H) BCD gösterimden kuruldu. -->

### 7.5 Mod 4: yazılımla tetiklenen tek darbe

Mod 4, mod 2'nin tek seferlik çalışan halidir. Boşta OUT lojik 1'dedir. Sayma değeri yüklenince sayma başlar; sayma boyunca OUT 1'de kalır, sayma değerinin son adımında bir saat periyodu boyunca 0'a düşer ve işlem sonlanır. Mod 2'de bu darbeler tekrarlı olarak gönderiliyordu; mod 4'te tek bir darbe gönderilir.

### 7.6 Mod 5: donanımla tetiklenen tek darbe

Mod 5, mod 4'ün GATE ile tetiklenen halidir: yine tek bir darbe üretilir, ama saymanın başlaması için GATE'te bir tetikleme gerekir. Kontrol sözcüğü ve sayma değeri gönderilir; OUT boşta bekler. GATE'ten tetikleme geldikten sonra sayıcı saat düşen kenarlarında geri sayar ve sayma sonunda OUT kısa bir süre 0'a düşüp işlemi bitirir.

> **Ders sonrası not:** Hoca mod 5'te OUT'un "bir sayma süresi boyunca sıfırda" kaldığını söyledi. Mod 4 ve mod 5'te OUT, sayma sonunda yalnız bir saat periyodu boyunca 0'a düşer (büyük olasılıkla, 8254 veri sayfasına göre).

## 8. İç yapıya yeniden bakış: Counter Latch ve Read-Back komutları

### 8.1 Sayıcının iç yapısı

8086 bir sayıcıya sayma değeri gönderdiğinde bu değer önce 8 bitlik iki **sayıcı yazmacına** (counter register), önce düşük sonra yüksek kısmına aktarılır. Ardından bu iki değer 16 bitlik **sayma elemanına** (count element) aktarılır ve sayma bu 16 bitlik ilk değerle yapılır. Yani sayıcı yazmaçları, 8086'dan gelen değerlerin tutulduğu ara yazmaçlardır.

Sayma elemanının o anki değeri istenirse 8 bitlik iki **çıkış tutucusuna** (output latch) kopyalanabilir. Bu sırada sayıcı saymaya devam eder; yalnız o anın bir "anlık görüntüsü" (snapshot) alınmış olur. Daha sonra çıkış tutucuları okunarak sayıcının o anda hangi değerde olduğu anlaşılır. Her sayıcının ayrıca bir **durum yazmacı** vardır. Sayma değeri ya da durum tutulabilir; bunun için iki ayrı komut vardır:

- **Counter Latch komutu:** yalnız sayma değerini tutar (kopyalar).
- **Read-Back komutu:** istenirse yalnız durumu, istenirse yalnız sayma değerini, istenirse ikisini birden tutar. Bu iki seçenek birbirinden bağımsız iki bitle kontrol edilir.

İki komut da kontrol yazmacına yazılır; bütün bu işlemler kontrol yazmacına gönderilen değerlerle sağlanır.

### 8.2 Counter Latch komutu

Kontrol sözcüğünde bir sayıcı seçilip (SC = 00, 01 ya da 10) RW bitlerine 00 yazılırsa komut Counter Latch olur. Bu durumda mod ve BCD bitlerinin anlamı yoktur (önemsiz, don't care). Komut kontrol yazmacına gönderildiği anda seçilen sayıcının o anki sayma değeri çıkış tutucularına aktarılır. Tutulan değer, seçilen sayıcının kendi adresinden okuma yapılarak elde edilir. Read-Back dışındaki bu durum (SC ≠ 11, RW = 00) Counter Latch'tir.

### 8.3 Read-Back komutu

Read-Back komutu hem sayma değerini hem durum değerini tutmayı sağlar ve istenirse birden fazla sayıcıya aynı anda uygulanır. Kontrol sözcüğünün en yüksek iki biti 11 olduğunda komut Read-Back'tir. Bit düzeni (hocanın anlatımına ve slayttaki örnek tabloya göre):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 1 | 1 | $\overline{COUNT}$ | $\overline{STATUS}$ | CNT 2 | CNT 1 | CNT 0 | 0 |

- D1, D2 ve D3 sırasıyla Counter 0, Counter 1 ve Counter 2 için tutma yapılıp yapılmayacağını seçer; hangi sayıcılar seçilecekse onlara 1 yazılır.
- D5 ve D4 aktif 0'dır: sayma değeri tutulacaksa D5'e, durum tutulacaksa D4'e 0 yazılır.

**Örnek:** Bütün sayıcıların hem durumunu hem sayma değerini tutmak için 1100 1110 = **CEH** kontrol yazmacına gönderilir. Sonra her sayıcının kendi adresinden sırayla okuma yapılır; 16 bitlik değer programlanmışsa her sayıcıdan 3'er okuma yapılır.

Hem durum hem sayma değeri tutulduysa sayıcının adresinden yapılan **ilk okuma durum baytını**, sonraki okumalar tutulan sayma değerini verir. Bunların ardından yapılan başka okumalar artık tutulmamış, o anki sayma değerini verir; sayıcı bu sırada saymaya devam ettiği için düşük ve yüksek bayt okunurken değer değişebilir, yani hatalı değer okunma olasılığı vardır.

### 8.4 Okunmamış tutma varken gelen komutlar

Bir sayıcının durumu ya da sayma değeri tutulmuş ve henüz okunmamışsa, aynı sayıcı için gelen yeni tutma komutları yok sayılır (discard edilir); okunana kadar eski değer korunur, üzerine yazılmaz. Slayttaki örnek dizi (ekrandan, 01:25:00), komutlar sırayla yapılırsa:

| Komut (D7...D0) | Açıklama | Sonuç |
|-----------------|----------|-------|
| 1100 0010 | Counter 0'ın sayma ve durumunu tut | Counter 0 için sayma ve durum tutuldu |
| 1110 0100 | Counter 1'in durumunu tut | Counter 1 için durum tutuldu |
| 1110 1100 | Counter 2 ve 1'in durumunu tut | Counter 2 için tutuldu, Counter 1 için tutulmadı |
| 1101 1000 | Counter 2'nin sayma değerini tut | Counter 2 için sayma tutuldu |
| 1100 0100 | Counter 1'in sayma ve durumunu tut | Counter 1 için sayma tutuldu, durum tutulmadı |
| 1110 0010 | Durum tut (bkz. not) | Komut yok sayıldı, durum zaten tutulmuş |

Hoca üçüncü satırı açıkladı: Counter 2 için durum tutma yapılır, ama Counter 1'in durumu ikinci komutta tutulmuş ve okunmamıştır; bu yüzden Counter 1 için komut uygulanmaz. Bu kural özellikle durum için anlamlıdır.

> **Ders sonrası not:** Son satırda D1 = 1 olduğu için komut Counter 0'ı seçer, ama slayttaki açıklamada "Counter 1" yazıyor. Bit düzenine göre doğrusu büyük olasılıkla "Counter 0'ın durumunu tut; komut yok sayıldı, Counter 0'ın durumu zaten tutulmuş"tur (Counter 0'ın durumu ilk komutta tutulmuş ve okunmamıştır).

## 9. Durum baytı

> **Hocanın vurgusu:** En çok karışan nokta durum baytının nereden okunduğudur. Durum baytı kontrol yazmacından okunmaz. Read-Back ile durum tutulduktan sonra ilgili sayıcının kendi adresinden okunur; çünkü her sayıcının kendine ait bir durum baytı vardır. Kontrol yazmacından okunsaydı hangi sayıcıya ait olduğu bilinemezdi.

Durum baytının yapısı (ekrandan, 01:30:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| OUTPUT | NULL COUNT | RW1 | RW0 | M2 | M1 | M0 | BCD |

- D7 = 1: OUT ucu 1; D7 = 0: OUT ucu 0.
- D6 = 1: null count (sayma değeri henüz okunabilir değil); D6 = 0: sayma değeri okunabilir.
- D5-D0: sayıcının programlandığı biçim (kontrol sözcüğündeki RW, mod ve BCD bitleri).

Hoca için en önemli bit D7'dir: fiziksel OUT ucunun lojik değeri buradan okunur. Yoklama mantığında bir sayıcının işini bitirip bitirmediği bu bitle anlaşılacaktır. Durum baytı ayrıca sayıcının okuma/yazma biçimini, modunu ve sayma tipini (BCD ya da binary) verir.

> **Ek bilgi (derste anlatılmadı):** NULL COUNT biti, sayıcıya yeni bir değer yazıldıktan sonra bu değer henüz sayma elemanına yüklenmemişken 1 olur. Değer sayma elemanına yüklenince 0'a döner. Bu yüzden yeni değer yazdıktan hemen sonra yapılan bir sayma okumasının yeni değeri yansıtıp yansıtmadığı bu bitten anlaşılabilir.

## 10. Modların özeti ve sonraki derse bağlantı

Hoca modları beyaz tahtada OUT dalga şekilleriyle kabaca özetledi (ekrandan, 01:15:00):

| Mod | Tetikleme | Tekrar | OUT davranışı | GATE'in etkisi |
|-----|-----------|--------|---------------|----------------|
| 0 | Yazılım | Tek sefer | Sayma boyunca 0, bitince 1'e çıkıp kalır | 0 iken sayma duraklar |
| 1 | GATE yükselen kenarı | Tek sefer (yeniden tetiklenebilir) | Tetiklemeden sonra 0, bitince 1'e çıkıp kalır | Yükselen kenar saymayı başlatır |
| 2 | Yazılım | Tekrarlı | Uzun süre 1, bir saat periyodu 0 (darbe dizisi) | 0 iken sayma durur |
| 3 | Yazılım | Tekrarlı | Yaklaşık %50 doluluk oranlı kare dalga | 0 iken sayma durur |
| 4 | Yazılım | Tek sefer | Sayma sonunda tek kısa darbe | Derste ayrıca anlatılmadı |
| 5 | GATE yükselen kenarı | Tek sefer | Tetiklemeden sonra sayma sonunda tek kısa darbe | Yükselen kenar saymayı başlatır |

Böylece 8254'ün işlevsel blokları, uç tanımları, kontrol sözcüğü, modlar, Counter Latch ve Read-Back komutları ile durum baytı tamamlandı. Örnekler sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:24:23): Sayıcı binary modda ve 16 bit yazılacak şekilde (RW = 11) ayarlandıysa yazılabilecek en büyük ilk değer nedir, sayıcı en çok kaç adım sayar? BCD modda ne olur?

> **Çözüm:** Binary modda en büyük değer FFFFH = 65535'tir; derste sıfır da sayılarak en çok 65536 adım denildi. BCD modda 16 bite 4 BCD basamak sığar, her basamak 0-9 arasıdır; en büyük değer 9999, en çok 10000 adım. (Ayrıntı için Bölüm 5'teki ders sonrası nota bakın.)

**Soru 2** (ekrandan, 00:35:00): 98H adresinden itibaren ardışık çift adreslere yerleştirilmiş 8254 için CNTR0'ı mod 3'te CLK0'ı 4282 (BCD)'ye, CNTR2'yi binary sayma ve mod 3'te CLK2'yi C26A hex'e bölecek şekilde ayarlayın. CLK0 = 1,2 MHz, CLK2 = 1,8 MHz ise çıkış frekansları nedir?

> **Çözüm:** Adresler: Counter 0 = 98H, Counter 2 = 9CH, kontrol = 9EH. Counter 0 kontrol sözcüğü 0011 0111 = 37H, sayma değeri 4282H (önce 82H, sonra 42H, 98H'ye). Counter 2 kontrol sözcüğü 1011 0110 = B6H, sayma değeri C26AH = 49770 (önce 6AH, sonra C2H, 9CH'ye). Kod Bölüm 6.4'teki gibidir. $f_{OUT0} = 1{,}2\ \text{MHz}/4282 \approx 280\ \text{Hz}$, $f_{OUT2} = 1{,}8\ \text{MHz}/49770 \approx 36\ \text{Hz}$.

**Soru 3** (ekrandan, 00:50:00): 8086, 8254'ün kontrol yazmacına 10H yazıyor. Bu kontrol sözcüğü sayıcıyı nasıl ayarlar?

> **Çözüm:** 0001 0000 → SC = 00 (Counter 0), RW = 01 (yalnız LSB), mod = 000 (mod 0), BCD = 0 (binary). Diyagramdaki diğer sözcükler aynı biçimde çözülür: 12H mod 1, 14H mod 2, 16H mod 3 (hepsi Counter 0, yalnız LSB, binary).

**Soru 4** (derste sözlü, 01:06:13): Clock 0'a 2 MHz'lik bir işaret bağlıdır. Counter 0'ı 50 µs'de bir darbe üretecek şekilde (mod 2) ayarlayın.

> **Çözüm:** $f_{OUT} = 1/50\ \mu\text{s} = 20\ \text{kHz}$, $N = 2\ \text{MHz}/20\ \text{kHz} = 100 = 64\text{H}$. Yalnız LSB yeterli; kontrol sözcüğü 0001 0100 = 14H. Önce 14H kontrol yazmacına, sonra 64H Counter 0'ın adresine yazılır.

**Soru 5** (derste sözlü, 01:10:35): Counter 1'in saat ucuna 2 MHz bağlıdır. Counter 1'i 1 kHz kare dalga üretecek şekilde ayarlayın.

> **Çözüm:** $N = 2\times10^6/10^3 = 2000$. Derste BCD seçildi: kontrol sözcüğü 0111 0111 = 77H (Counter 1, önce LSB sonra MSB, mod 3, BCD). Ardından Counter 1'in adresine 00H (LSB) ve 20H (MSB) yazılır.

**Soru 6** (derste sözlü, 01:24:03): Üç sayıcının hem durumunu hem sayma değerini Read-Back komutuyla tutmak için kontrol yazmacına hangi değer yazılmalıdır?

> **Çözüm:** D7-D6 = 11 (Read-Back), D5 = 0 (sayma tut, aktif 0), D4 = 0 (durum tut, aktif 0), D3 = D2 = D1 = 1 (üç sayıcı), D0 = 0 → 1100 1110 = CEH. Sonra her sayıcının adresinden okuma yapılır; ilk okuma durum baytını verir.

## Dersin Toparlaması

Bu derste 8254 programlanabilir aralık zamanlayıcısı tanıtıldı. Aynı devrenin saat girişine sabit frekans bağlanınca zamanlayıcı, aperiyodik olay sinyali bağlanınca sayıcı olduğu görüldü. 8254'ün üç bağımsız 16 bitlik aşağı sayıcısı, 8 bitlik veri yolu ve A1-A0 ile seçilen dört yazmacı (üç sayıcı ve kontrol) incelendi. Kontrol sözcüğünün SC, RW, M ve BCD alanları, ilk değerin önce kontrol yazmacına ayar, sonra sayıcı adresine değer yazılarak iki adımda yüklendiği ve sayıcıların $f_{OUT} = f_{CLK}/N$ ilişkisiyle frekans bölücü olarak çalıştığı örneklerle gösterildi. Altı mod tetikleme biçimi (yazılım ya da GATE), tekrarlılık ve OUT dalga şekli açısından karşılaştırıldı. Counter Latch ve Read-Back komutlarıyla sayma ve durum değerlerinin nasıl tutulup sayıcı adresinden okunduğu, durum baytında OUT ucunun D7 bitinde bulunduğu anlatıldı.

Sonraki derste 8254 örnekleri yapılacak: tek bir sayıcının üretemeyeceği frekansları iki sayıcıyı art arda bağlayarak elde etme, bir frekans sayıcının donanım bağlantısı ve Assembly kodu, belirli frekanslarda kare dalga üretimi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
