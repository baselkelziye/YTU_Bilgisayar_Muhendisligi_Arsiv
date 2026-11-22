# Ders 9 Genişletilmiş Notu: Ara Sınav Çözümleri, Komut Kümesi Mimarisi, Adresleme Modları ve Aritmetik Birim Tasarımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ara Sınav Sorularının Çözümü
- 2. Komut Kümesi Mimarisi ve Komut Biçimi
- 3. Program Sayacı ve Komutların Yürütülmesi
- 4. Adresleme Modları
- 5. Veri Transferi Komutları
- 6. Aritmetik Komutlar
- 7. Lojik ve Bit İşleme Komutları
- 8. Kaydırma ve Döndürme Komutları
- 9. Program Kontrol Komutları
- 10. Koşullu Dallanma ve Bayrak Koşulları
- 11. Kesmeler
- 12. Datapath'e Giriş: Yazmaç Dosyası ve Fonksiyon Birimi
- 13. Aritmetik Birim Tasarımı
- Örnek Sorular
- Dersin Toparlaması

## 1. Ara Sınav Sorularının Çözümü

Ders, ara sınav sorularının çözümüyle başladı. Hoca, öğrencilerin karşısına çıkan soruların şık sayısının ekrandakinden farklı olabileceğini, ama soru kökünün aynı olduğunu belirtti. Soruların metinleri ve çözümleri aşağıdaki "Örnek Sorular" bölümünde toplu olarak verilmiştir. Burada çözümlerde kullanılan yöntemler özetlenir.

### 1.1 Bayraklar ve taşma

İkiye tümleyen sayılarla yapılan bir işlemde bayraklar iki yoldan bulunabilir. Birinci yol üst seviyedir: sayılar onluğa çevrilir, işlem onlukta yapılır. Sonuç sıfırdan farklıysa $Z=0$, negatifse $N=1$ olur. Sonuç 8 bitlik işaretli aralıkta ($-128\ldots127$) kalıyorsa taşma olmaz, yani $V=0$ olur. İkinci yol işlemi doğrudan ikilikte yapmaktır. $A-B$ işlemi $A+(-B)$ olarak düşünülür ve $-B$, $B$'nin ikiye tümleyeni alınarak bulunur. Toplamın 8. biti işaret bayrağını verir. Taşma bayrağı 6. basamaktan 7. basamağa giden elde ile 7. basamaktan çıkan eldenin XOR'udur: $V=C_6\oplus C_7$. Hoca bu ifadenin, iki negatif (ya da iki pozitif) sayı toplanınca sonucun beklenen işarette çıkmaması durumunu özetlediğini hatırlattı.

### 1.2 Aritmetik sola kaydırmada taşma

Aritmetik sola kaydırma (SHLA) bit düzeyinde mantıksal sola kaydırmayla aynıdır: en yüksek anlamlı bit kaybolur, diğer bitler bir basamak sola kayar, sağdan 0 girer. En yüksek bit 1 iken 0 olursa işaret değişmiştir, bu da taşma demektir.

### 1.3 Bellek, ROM, MUX, sayıcı ve PLA soruları

Bellek sorularında modülün veri bit sayısı veri yolunu, adres gözü sayısının $\log_2$'si adres yolunu verir. Bellek genişletmede toplam kapasite modül kapasitesine bölünür. Veri genişliklerinin oranı sütun sayısını (veri yolu genişletme), göz sayılarının oranı satır sayısını (kapasite genişletme) verir. Satır sayısı kadar çıkışlı bir kod çözücü gerekir.

ROM'un birinci katı bir kod çözücü, ikinci katı programlanabilir bir OR dizisidir. Kod çözücü çıkışları minterimlere karşılık gelir; bu yüzden bir çıkışa bağlı işaretler doğrudan o çıkışın minterimlerini verir. MUX sorusunda doğruluk tablosu kurulur: seçim uçlarına 00 verilince 0 numaralı giriş çıkışa aktarılır, ve bu böyle devam eder. PLA sorusunda AND katının çıkışları kısmen indirgenmiş terimlerdir. Eksik değişkenler $(C+\bar C)$ gibi çarpanlarla eklenerek terimler minterimlere açılır. Hoca bu sorunun püf noktasının bu genişletme olduğunu söyledi.

## 2. Komut Kümesi Mimarisi ve Komut Biçimi

Haftanın asıl konusu, daha önce görülen RTL ve datapath tasarımından sonra merkezi işlem biriminin tasarımına geçmek için gereken ön adımlardır: komut kümesi mimarisi (Instruction Set Architecture, ISA) ve adresleme modları.

ISA, bir mikroişlemcinin hangi assembly komutlarını desteklediğini gösterir. Bir assembly komutunu desteklemek ile ona donanım karşılığı koymak sıkı biçimde ilişkilidir: her assembly komutunun arkasında bir donanım vardır. Karmaşık bir komut kümesi isteniyorsa arkadaki donanım da o kadar karmaşık olur. Hocaya göre bu durum yazılım ile donanımın birbirine çok yakın olduğunu gösterir.

Standart bir komut üç bölgede ele alınır (ekrandan, 00:25:00):

```text
| Opcode | Mode | Address or operand |
```

- **Opcode** alanı birbirinden farklı kaç komut tipi üretilebileceğini belirler. Kaç farklı komut kullanılacaksa alan genişliği ona göre seçilir.
- **Mode** alanı adresleme modunu belirtir: doğrudan adres mi, dolaylı adres mi, sabit değer mi kullanılacağı burada söylenir.
- **Address or operand** alanı kullanılacak adresi, sabiti ya da işleneni tanımlar.

Komut genişliği bilgisayar mimarisine göre değişir. CISC (Complex Instruction Set Computer) mimarisinde, örneğin assembly dersinden bilinen 8086'da, komut uzunlukları farklıdır: bazı komutlar bir-iki byte'a sığarken bazıları dört byte tutar. RISC (Reduced Instruction Set Computer) mimarisinin temel yaklaşımı az sayıda basit komut ve olabildiğince sade bir tasarımdır. Komut genişlikleri her zaman aynıdır ve alanlar benzer biçimde bölünür. Bunun bedeli karmaşık komutların hazır olmamasıdır; onlar kütüphaneler ya da kod dizileriyle üst seviyede gerçeklenir. Derste RISC'e benzeyen, eşit uzunlukta komutlarla çalışan "single cycle computer" incelenecektir.

## 3. Program Sayacı ve Komutların Yürütülmesi

Bir assembly kodu derlenince makine kodu üretilir. Bu kod program belleğine üretildiği sırayla yerleştirilir. Kod bir sayaç yardımıyla yürütülür; bu sayaca program sayacı (Program Counter, PC) denir. Örnek tasarımda PC'nin reset değeri 0'dır, yani okunan ilk program gözü 0000 adresidir. Hoca özel bir durum olarak 8086'nın resetten sonra FFFF0 adresindeki komutu okuyarak başladığını ekledi.

PC her komut yürütüldükçe artar ve sıradaki komuta geçer. Koşullu ya da koşulsuz bir dallanma varsa PC'nin önündeki kontrol birimi bunu yakalar, ofset miktarını bulur ve PC'yi o kadar değiştirir. Böylece dallanma adresine gidilir. Dallanma olmadığı sürece ardışık komutlar sırayla yürütülür.

### 3.1 Doğrudan adresli yükleme örneği

PC 250 adresini gösteriyor olsun. 250 adresindeki opcode "ACC'ye (akümülatöre) değer yükle", mod doğrudan adresleme, adres alanı 500 olsun. Bu komutun anlamı şudur: bellekte 500 adresine git, oradaki içeriği al, ACC'ye yükle. 500 adresinin içeriği 800 olduğu için ACC'ye 800 yüklenir (ekrandan, 00:35:00).

### 3.2 Koşullu dallanma örneği

PC 300 adresini gösteriyor olsun. Opcode "ACC sıfırsa dallan", mod doğrudan, adres 500 olsun. Komut alınıp çözüldükten sonra ACC'deki değere bakılır. ACC = 0 ise 500 adresindeki komuta gitmek için PC'ye 500 yüklenir. Program akışı böylece PC değiştirilerek değiştirilir. ACC ≠ 0 ise sıradaki komuta geçilir. Bu yapı aslında bir if mantığı kurar.

Sıradaki komutun adresi bellek yerleşiminden bulunur. Bu örnekte opcode ile mod bir word, adres ikinci bir word kaplar. Yani her komut iki word'tür ve sıradaki komut 302 adresinden başlar.

**Soru:** Dallanmada 500'den devam ediliyor, değil mi? 500'deki adresten geri dönülmüyor mu?
**Cevap:** ACC sıfırsa PC 500'e götürülür. 500'den sonraki komutlarda dallanma yoksa akış 500'den aşağı doğru devam eder. ACC sıfır değilse sıradaki komut 302'dir ve akış oradan aşağı doğru devam eder.

### 3.3 Hemen (immediate) adresli yükleme

Aynı 250 adresindeki komutta mod "immediate" olursa ikinci word'teki değer bir adres değil, yüklenecek sabitin kendisidir. ACC'ye doğrudan 500 sabiti yüklenir. Bir öğrenci örnekte modun immediate diye yazılmadığını sordu. Hoca, modun immediate olduğunun belirtilmesi gerektiğini, kendisinin önceki örneği hatırlayarak öyle anlattığını söyledi.

## 4. Adresleme Modları

Adresleme modları formal olarak bir tabloyla verildi. Örnekteki durum şudur: PC = 250, R1 = 400, 250 adresinde opcode ve mod, 251 adresinde ADRS ya da NBR = 500, 252 adresinde sıradaki komut. Bellekte M[400] = 700, M[500] = 800, M[752] = 600 vardır. M[800] = 300 ve M[900] = 200 değerleri tablodaki sonuçlardan çıkar (ekrandan, 00:40:00 ve 00:45:00).

| Mod | Sembolik gösterim | Yazmaç transferi | Etkin adres | ACC içeriği |
|---|---|---|---|---|
| Direct | LDA ADRS | ACC $\leftarrow$ M[ADRS] | 500 | 800 |
| Immediate | LDA #NBR | ACC $\leftarrow$ NBR | 251 | 500 |
| Indirect | LDA [ADRS] | ACC $\leftarrow$ M[M[ADRS]] | 800 | 300 |
| Relative | LDA \$ADRS | ACC $\leftarrow$ M[ADRS+PC] | 752 | 600 |
| Index | LDA ADRS(R1) | ACC $\leftarrow$ M[ADRS+R1] | 900 | 200 |
| Register | LDA R1 | ACC $\leftarrow$ R1 | — | 400 |
| Register-indirect | LDA (R1) | ACC $\leftarrow$ M[R1] | 400 | 700 |

(ekrandan, 00:45:00)

### 4.1 Doğrudan ve hemen adresleme

Hoca 8086 karşılıklarını öğrencilere sordu. Doğrudan adreslemede `MOV AL,[100H]` yazılıyordu: verilen sayı bir adresi gösterir ve o adresin içeriği yüklenir. 8086'da hedef yazmaç seçilebilir; single cycle computer'da ise yapı daha dar olabilir ve genelde akümülatör kullanılır. Örnekte 500 numaralı gözdeki 800 ACC'ye yüklenir. Hemen adreslemede 8086'da köşeli parantez kullanılmaz: `MOV AL,100H` AL'ye 100H değerinin kendisini aktarır. Tabloda sabit olduğunu belirtmek için başa # konmuştur. Örnekte ACC'ye 500 yüklenir.

### 4.2 Dolaylı adresleme

Dolaylı adreslemede verilen adresin içeriğine gidilir ve elde edilen değer yine adres olarak kullanılır; yani iki katmanlı bir adresleme yapılır. Örnekte 500'ün içeriği olan 800 bir adres olarak kullanılır. 800'ün içeriği 300 olduğu için ACC'ye 300 yüklenir. Hoca 8086'da bunun tam karşılığı olmadığını söyledi: 8086'da dolaylılık yazmaçlar üzerinden yapılır, "bir adres içeriğinin adres içeriği" biçiminde yapılmaz.

### 4.3 Göreli (relative) adresleme

Göreli adreslemede PC'ye verilen sabit kadar ofset eklenir. Hoca bunu 8086'daki jump komutlarından hatırlattı. Örneğin ofseti FF olan bir jump bir adım geri gitmek demektir, çünkü FF 8 bitlik ikiye tümleyende $-1$'dir. Örnekte birinci komut yürütülürken PC otomatik olarak 252 olur. Buna 500 eklenince 752 adresine gidilir ve oradaki 600 ACC'ye aktarılır.

### 4.4 İndis adresleme

İndis adreslemede R1 bir indis olarak kullanılır. Hoca 8086 karşılığını sordu. Öğrencilerin verdiği SI/BX örneklerini yazmaç dolaylı adreslemeye benzettiğini söyledi ve aradığı örneği verdi: `DIZI[BX]`. Burada DIZI bir başlangıç adresidir ve bu adresten BX kadar ötedeki içerik okunur. Örnekte 500 başlangıç adresine R1 = 400 eklenir, 900 adresindeki 200 ACC'ye yüklenir.

### 4.5 Yazmaç ve yazmaç dolaylı adresleme

Yazmaç adreslemede iki işlenen de yazmaçtır, yani yazmaçlar arası bir transfer yapılır. Örnekte R1'deki 400 ACC'ye yüklenir. Yazmaç dolaylı adreslemede yazmaçtaki değer bir adres gibi kullanılır. 8086'da `MOV AL,[SI]` buna karşılık gelir. Örnekte R1 = 400 adresindeki 700 ACC'ye aktarılır. Hoca 8086'daki `[SI+DI]`, `[BX+SI+DI]` ya da sabit ofset artı yazmaç biçimlerinin de bu başlık altında incelendiğini söyledi.

<!-- BELİRSİZ: Altyazıda 8086 örnekleri "SI artı DI", "BX artı SI artı DI" diye geçiyor; 8086'da SI ile DI aynı adres ifadesinde birlikte kullanılamaz. Hoca büyük olasılıkla BX+SI, BX+DI, BP+SI gibi biçimleri kastetti. -->

## 5. Veri Transferi Komutları

Bir komut kümesinde olmazsa olmaz komut gruplarından ilki veri transferidir. Bunlar bellek ile yazmaç arasında ya da yazmaçlar arasında veri aktarır. Slayttaki tipik veri transferi komutları şunlardır (ekrandan, 00:55:00):

| Ad | Kısaltma |
|---|---|
| Load | LD |
| Store | ST |
| Move | MOVE |
| Exchange | XCH |
| Push | PUSH |
| Pop | POP |
| Input | IN |
| Output | OUT |

- **Load:** Bellekteki bir değeri alıp bir yazmaca aktarır, yani işlemciye veri getirir. Hoca bu aktarımın hangi kanaldan yapıldığının ALU ve single cycle computer tasarımında ayrıntılı görüleceğini söyledi.
- **Store:** İşlemcideki bir yazmaçtan bir bellek adresine veri yazar.
- **Move:** İki yazmaç arasında veri aktarımı için ayrıştırılmış bir komut olarak düşünülebilir.
- **Exchange:** 8086'da da vardı. Üçüncü bir değişkene gerek duymadan iki yazmacın ya da iki adres bölgesinin içeriğini tek seferde değiştirir; bir swap işlemidir.
- **Push/Pop:** Yığın kullanılırken gereken komutlardır. Fonksiyon çağrılarında dönüş adresleri, kesmelerde ise dönüş adresleri ile bayrak yazmacı otomatik olarak yığına atılır. Sistemin otomatik işleyişi için zaten bir yığın gerektiğinden, onu PUSH/POP ile kullanma ihtiyacı da doğar. Yığının üstünü gösteren bir işaretçi vardır. Her PUSH yeni veriyi mevcut verinin üstüne koyar, her POP en üstteki değeri çeker; yani yığın son giren ilk çıkar (LIFO) mantığıyla çalışır.
- **In/Out:** İşlemci yalnız kendi içindeki birimlerle çalışamaz, dış dünyayla da etkileşmelidir. IN, dış dünyaya bağlı bir port adresindeki yazmacı okur. Hocanın örneği şuydu: 8 tuşlu bir buton yapısında basılan tuşlar 1, basılmayanlar 0 olarak bir yazmaçta tutulur ve işlemci bu yazmacı okuyarak hangi tuşa basıldığını anlar. OUT, bir port adresine değer gönderir. Örneğin bir yazmacın uçlarına bağlı LED'lerde 1 olan bitler yanar, 0 olanlar söner. VGA monitör, yazıcı ya da klavye de böyle G/Ç birimleridir.

G/Ç işlemlerini bellek işlemlerinden ayırmak avantajlıdır. Ayırmadan bütün işlemler MOV komutlarıyla da yapılabilir. Ama o zaman bellek uzayı ile G/Ç uzayı iç içe girer ve ikisini ayrı, daha geniş kapasiteyle kullanma imkânı kaybolur.

Hoca 8086'daki yığın davranışını da hatırlattı. Yığın olarak ilgili kesimin en uzak adresi kullanılıyordu ve her PUSH'ta yığın işaretçisi (SP) 2 azalıyordu. Bunun nedeni yığına byte değil, her seferinde bir word (2 byte) yazılıp okunabilmesidir. Adres değerleri yığına bir şey atıldıkça azalır, ama SP de böyle azaldığı için her zaman yığının üstünü gösterir.

## 6. Aritmetik Komutlar

Aritmetik komutlar, tasarlanan basit bilgisayarda ALU üzerinden gerçekleştirilir. Slayttaki tipik aritmetik komutlar şunlardır (ekrandan, 01:00:00):

| Ad | Kısaltma |
|---|---|
| Increment | INC |
| Decrement | DEC |
| Add | ADD |
| Subtract | SUB |
| Multiply | MUL |
| Divide | DIV |
| Add with carry | ADDC |
| Subtract with borrow | SUBB |
| Subtract reverse | SUBR |
| Negate | NEG |

### 6.1 CISC ve RISC'te yürütme süresi

CISC mimarisinde çarpma ve bölme gibi karmaşık komutlar bulunabilir. Böyle bir çarpma ya da bölme 10-20 saat çevrimi mertebesinde sürerken bir INC bir saat çevriminde tamamlanabilir. Yani CISC'te hem komut uzunlukları hem yürütme süreleri farklıdır, bu da karmaşık bir kontrol yapısı gerektirir. RISC'te (adı üstünde, indirgenmiş komut kümesi) karmaşık komutlar yoktur. Her komutun uzunluğu ve yürütme süresi aynıdır; örneğin INC de load/store da bir saat çevriminde yapılabilir. Bu eşitliği sağlamak için bazı karmaşık komutlardan vazgeçilir.

### 6.2 Komutlar

- **INC/DEC:** Bir değeri bir arttırır ya da azaltır; 8086'da da vardı.
- **ADD/SUB:** Toplama ve çıkarma; ikişer işlenen beklenir.
- **MUL:** Hoca 8086'da gizli işlenenleri hatırlattı. `MUL BL` arka planda AL'yi ve AX'i kullanır: AL ile BL çarpılır, sonuç AX'e yazılır. `MUL BX` gibi 16 bitlik çarpmada gizli işlenenler AX ve DX'tir ve 32 bitlik sonuç bunlara yazılır. Komutlardan genelde iki işlenen beklenir, ama bazen gizli işlenenler olabilir. Bunlar komut tanımında önceden belirtilmiş olmalıdır.
- **DIV:** Hoca önce "RISC'te bölme asla yapamayız" dedi, sonra kendini düzeltti: 2'ye ya da 2'nin katlarına bölme, sağa kaydırmayla kolayca yapılabilir. Bir birim sağa kaydırmak ikiye bölmek, sola kaydırmak ikiyle çarpmaktır. Böylece RISC'te basit çarpma ve bölme üst seviyede gerçeklenebilir.
- **ADDC (eldeli toplama):** 8086'daki ADC'dir. Büyük veri genişlikleri için kütüphane yazarken düşük anlamlı 16 bitten gelen elde, yüksek anlamlı 16 bitin toplamına ADC ile eklenir. Eldenin 1 ya da 0 olmasına göre dallanmak ya da bir döngüde eldenin kaç kez 1 olduğunu saymak için de kullanılabilir.
- **SUBB:** Ödünçlü (eldeli) çıkarma.
- **SUBR (ters çıkarma):** $A-B$ yerine $B-A$ işlemini yapan komut olarak düşünülebilir.
- **NEG:** Hoca önce NEG'i bire tümleyen diye anlattı, sonra lojik komutlar kısmında düzeltti (bkz. 7. bölüm).

> **Ders sonrası not:** NEG işleneninin ikiye tümleyenini, yani negatifini hesaplar. Bire tümleyen (bit düzeyinde değil alma) NOT/complement komutudur. Hoca da bu düzeltmeyi derste yaptı.

## 7. Lojik ve Bit İşleme Komutları

Lojik işlemler bit düzeyinde (bitwise) yapılan işlemlerdir. Slayttaki tipik komutlar şunlardır (ekrandan, 01:10:00):

| Ad | Kısaltma |
|---|---|
| Clear | CLR |
| Set | SET |
| Complement | NOT |
| AND | AND |
| OR | OR |
| Exclusive-OR | XOR |
| Clear carry | CLRC |
| Set carry | SETC |
| Complement carry | COMC |

- **CLR:** Bir yazmacın ya da bellek adresinin bütün bitlerini sıfırlar; işlenen olarak adres ya da yazmaç verilir.
- **SET:** İşlenenin bütün bitlerini 1 yapar.
- **NOT (complement):** Bire tümleyen alır. Hoca burada NEG'i düzeltti: NEG ikiye tümleyen alır. Örneğin yazmaçta 2 varken `NEG ACC` sonucunda ACC $-2$'yi gösterir.
- **AND/OR/XOR:** İki işlenenin (ör. iki 8 bitlik yazmaç) aynı sıradaki bitlerini AND, OR ya da XOR işlemine sokar.
- **CLRC/SETC/COMC:** Elde bayrağını sıfırlar, 1 yapar ya da tersler.

### 7.1 Bir bitin değerini test etmek

Hoca öğrencilere sordu: R1 yazmacının 4 numaralı biti 1 mi, 7 numaralı biti 0 mı, nasıl anlaşılır? (ekrandan, 01:10:00)

Bir öğrenci 4. biti için yalnız o biti 1 olan bir sayı oluşturup R1 ile AND'lemeyi önerdi. Bu sayı $(0001\,0000)_2=10\text{H}$'dir. `AND R1,10H` sonucu R1'in 4. biti 1 ise sıfırdan farklı olur. Ardından sonucun sıfırdan farklı olup olmadığına göre koşullu dallanma yapılır.

7. bitin 0 olduğunu anlamak için önce XOR önerildi. Hoca bunun işe yaramadığını gösterdi: 7. biti 1 olan bir maskeyle XOR yapılınca sonucun sıfırdan farklı çıkması diğer bitlere de bağlıdır. Yani bir bitin değerini anlamak için başka bitlerin değerini bilmek gerekir. Maske $80\text{H}$ ile OR da istenen sonucu vermez. Doğru yollar şunlardır:

- R1'i $80\text{H}$ ile AND'leyip sonucun 0 olup olmadığına bakmak; bu, 4. bit testinin tersidir.
- OR kullanılacaksa aranan biti 0, diğer bitleri 1 olan bir maske gerekir: $(0111\,1111)_2=7\text{FH}$. R1 bu maskeyle OR'lanınca alt 7 bit kesinlikle 1 olur. En yüksek bit ise R1'in 7. bitine eşit kalır. Sonuç FF ile karşılaştırılır: FF ise R1'in 7. biti 1, değilse 0'dır.

### 7.2 Bir yazmaçtaki 1'leri saymak

Hoca bir yazmaçtaki 1'lerin sayısının nasıl bulunacağını sordu ve cevabı ADC ile bağladı. Her adımda bir kaydırma uygulanırsa en düşük anlamlı bit eldeye (carry) düşer. Her adımda bir ADC yürütülürse elde toplanır ve 1'lerin sayısı bulunur. Sayının kaybolmaması gerekiyorsa kaydırma yerine döndürme (rotate) kullanılabilir.

## 8. Kaydırma ve Döndürme Komutları

Slayttaki tipik kaydırma ve döndürme komutları şunlardır (ekrandan, 01:15:00 ve 01:20:00):

| Ad | Kısaltma | Davranış (slayt diyagramından) |
|---|---|---|
| Logical shift right | SHR | soldan 0 girer, en düşük bit C'ye |
| Logical shift left | SHL | sağdan 0 girer, en yüksek bit C'ye |
| Arithmetic shift right | SHRA | işaret biti korunur ve tekrarlanır, en düşük bit C'ye |
| Arithmetic shift left | SHLA | sağdan 0 girer, en yüksek bit C'ye |
| Rotate right | ROR | en düşük bit en yükseğe döner ve C'ye kopyalanır |
| Rotate left | ROL | en yüksek bit en düşüğe döner ve C'ye kopyalanır |
| Rotate right with carry | RORC | C ile birlikte döndürme |
| Rotate left with carry | ROLC | C ile birlikte döndürme |

### 8.1 Mantıksal kaydırma

Mantıksal kaydırma değerlere eksi/artı olarak bakmaz, bitleri bir basamak kaydırır. SHR'de bitler bir sağa kayar, en düşük anlamlı bit elde bayrağına aktarılır, soldan 0 girer:

$$\text{SHR}(1100\,1111)=0110\,0111,\quad C=1$$

SHL'de bitler bir sola kayar, en yüksek anlamlı bit eldeye gider, sağdan 0 girer. Bir daha kaydırılırsa sıradaki bit eldedeki değeri ezer:

$$\text{SHL}(1100\,1111)=1001\,1110,\quad C=1$$

(ekrandan, 01:15:00; python ile doğrulandı)

### 8.2 Aritmetik kaydırma

> **Hocanın vurgusu:** Aritmetik sağa kaydırmada sayının işareti korunur. SHRA'nın en önemli özelliği budur. SHLA ise SHL ile aynı sonucu verir.

Hoca örnek olarak $(1100\,0000)_2$ sayısını aldı. Sayı negatiftir. İkiye tümleyeni $(0100\,0000)_2=64$ olduğu için değeri $-64$'tür. SHRA'da işaret biti korunur ve boşalan yere işaret bitiyle besleme yapılır; diğer bitler birer basamak sağa kayar:

$$\text{SHRA}(1100\,0000)=1110\,0000$$

Bu sayı da negatiftir. İkiye tümleyeni $(0010\,0000)_2=32$ olduğundan değeri $-32$'dir. Yani $-64$ aritmetik olarak ikiye bölünmüş olur. Sayı pozitif olsaydı, örneğin $(0100\,0000)_2=64$, sağa aritmetik kaydırma $(0010\,0000)_2=32$ verirdi; bu da yine beklenen sonuçtur (python ile doğrulandı).

<!-- BELİRSİZ: Altyazıda ikiye tümleyen ara adımı "0, 0, 0, 0, 0, 0, 1, 0" diye geçiyor; doğrusu 0100 0000'dır. Hocanın tahtadaki yazımı karede görülmedi. -->

### 8.3 Döndürme

Kaydırmada besleme 0 ya da işaret biti iledir. Döndürmede besleme sayının kendi uç bitleriyle yapılır. ROR'da bütün basamaklar bir sağa kayar, en düşük anlamlı bit dönüp en yüksek anlamlı biti besler ve aynı zamanda eldeye kopyalanır. ROL'de en yüksek anlamlı bit hem eldeye kopyalanır hem sağdan yazmacı besler. RORC ve ROLC'de ise 8 bitlik yazmaç elde biti ile birlikte sanki 9 bitlik bir değer gibi döndürülür.

Hoca, buraya kadar görülen komut tiplerinin basit bir CPU tasarımında gereken komutlar olduğunu ve hepsinin donanım karşılığının gerçeklenmesi gerektiğini söyleyerek dersin ilk bölümünü bitirdi.

## 9. Program Kontrol Komutları

Şimdiye kadar görülen veri aktarım, aritmetik, lojik ve kaydırma komutları program akışını etkilemez ve kontrol mantığı içermez. Akışı değiştirmek için kontrol komutları kullanılır (ekrandan, 01:45:00):

| Ad | Kısaltma |
|---|---|
| Branch | BR |
| Jump | JMP |
| Call procedure | CALL |
| Return from procedure | RET |
| Compare (by subtraction) | CMP |
| Test (by ANDing) | TEST |

### 9.1 Koşullu dallanma (branch)

Branch komutları verilen etikete (label) dallanır. Dallanma, PC'nin mevcut değeri ile hedef arasındaki ofsetin bir toplayıcıyla PC'ye eklenmesiyle yapılır. Koşul sağlanıyorsa PC bir anda ofset kadar değişir ve etikete gidilir. Sağlanmıyorsa PC sıradaki komutu gösterecek biçimde güncellenir. Önceki örneklerde her komut iki word kapladığı için PC 2 arttırılıyordu. 8086'da ise komut boyları farklı olduğu için sıradaki komutun adresi yürütülen komuta göre belirlenir.

Branch komutunun bir koşula ihtiyacı vardır. Bu koşul önce CMP, TEST ya da herhangi bir aritmetik işlemle üretilir, ardından koşullu dallanma komutu yürütülür.

### 9.2 Koşulsuz dallanma (jump)

JMP koşulsuz dallanmadır. İki temel kullanımı vardır:

- Program akışında uzak bir etikete gitmek. Göreli adreslemeyle ancak belli bir ofsete kadar gidilebilir; daha uzak bölgeler için jump gerekir.
- İç içe if yapılarını belli bir noktada kırmak. Örneğin iç içe iki if varsa ve birinci koşul sağlanmadığında ağaç kırılamazsa, akış sıradaki komuta geçer ve ikinci if her durumda yürütülmek zorunda kalır. JMP ile bütün if ağacının dışına çıkılabilir.

Jump ile bir fonksiyona gidip jump ile geri dönmek de mümkündür. Bu durumda yazmaç değerleri olduğu gibi korunur ve hiçbir otomatik işlem yapılmaz.

### 9.3 CALL ve RET

Bunun daha anlamlı ve kontrollü karşılığı alt program çağırmadır. CALL ile bir alt yordama gidilince işlemci geri dönüş adreslerini otomatik olarak yığına atar. Geri dönmek için RET kullanılır; RET yığının en üstündeki değeri çekip PC'ye yükler.

> **Hocanın vurgusu:** Alt yordam içinde yığına bir şey konduysa RET'ten önce bunlar uygun sırayla yığından kaldırılmalıdır. Kaldırılmazsa RET yığının en üstündeki keyfi değeri dönüş adresi sanır ve yanlış adrese döner.

8086'da donanımsal ya da yazılımsal bir kesme gelince kesme alt programına otomatik dallanılır. Bu sırada yığına dönüş adresleriyle birlikte bayrak yazmacı da atılır. Bu yüzden kesme alt programından RET ile değil, IRET (interrupt return) ile dönülür. IRET yığının üstünden bayrakları ve dönüş adreslerini çeker.

### 9.4 CMP ve TEST

CMP, SUB komutunun aynısıdır. Tek farkı şudur: SUB'da sonuç bir yazmaçta saklanır, CMP'de ise sonuç saklanmaz, yalnız bayraklar güncellenir. TEST de bit düzeyinde AND'e karşılık gelir: AND'de sonuç saklanır ve bayraklar etkilenir, TEST'te sonuç saklanmaz, yalnız bayraklar etkilenir.

Kullanım amaçları da farklıdır. CMP, bir yazmaçtaki değerin bir referans değerden büyük, küçük ya da eşit olduğunu incelemek, yani büyüklük karşılaştırması yapmak için kullanılır. Bu karşılaştırma işaretsiz ya da işaretli sayılar için yapılabilir. TEST ise bir yazmaçtaki belli bir bitin 0 ya da 1 olup olmadığını anlamak için kullanılır.

## 10. Koşullu Dallanma ve Bayrak Koşulları

Koşullu dallanma komutları iki başlık altında incelenir: basit ve karmaşık komutlar.

### 10.1 Basit koşullu dallanmalar

Basit komutlar, program durum yazmacındaki (bayrak yazmacı) tek bir bite bakarak dallanır. Bir işlemin sonucunun sıfır olup olmadığı için sıfır bayrağına (Z), elde oluşup oluşmadığı için elde bayrağına (C), sonucun negatif olup olmadığı için işaret bayrağına (N), taşma olup olmadığı için taşma bayrağına (V) bakılır. Altyazıda geçen komutlar şunlardır:

- Branch if zero (BZ): $Z=1$ ise dallanır. Branch if not zero (BNZ): $Z=0$ ise dallanır.
- Branch if carry (BC): $C=1$ ise dallanır. Branch if not carry (BNC): $C=0$ ise dallanır.
- Branch if negative (BN): $N=1$, yani sonuç negatifse dallanır. Branch if not negative (BNN): $N=0$ ise dallanır.
- Branch if overflow (BV): $V=1$ ise dallanır. Branch if not overflow (BNV): $V=0$ ise dallanır.

<!-- BELİRSİZ: Basit dallanma tablosunun karesi okunmadı; kısaltmalar altyazıdaki adlardan ve ders kitabının adlandırmasından alındı. -->

> **Hocanın vurgusu:** İşlem sonucu 0 ise sıfır bayrağı 1 olur. Bu çok karıştırılır, buna çok dikkat edin.

### 10.2 Karmaşık dallanmalar: işaretsiz sayılar

Karmaşık komutlar tek bir bayrağa değil, bir bayrak grubuna bakarak karar verir. Bunlar işaretsiz ve işaretli sayılardaki büyüklük karşılaştırmalarıdır. İşaretsiz sayılarda büyüklük ve küçüklük için **above/below**, işaretli sayılarda **greater/less** kelimeleri kullanılır; eşitlik iki durumda da **equal**'dır. BG, BL gibi bir komut görülürse işaretli, above/below görülürse işaretsiz sayılar içindir.

Kullanım biçimi şudur (ekrandan, 01:55:00):

```text
        CMP R1,R2
        Bxx ETIKET
        ...
ETIKET:
```

Hoca 8 bitlik işaretsiz aralığı sordu. Bir öğrenci önce 127 dedi. Hoca işaretsiz olduğunu hatırlatınca doğru cevap geldi: 0 ile 255 arası, toplam 256 değer. CMP $R1-R2$ işlemini yapar ve burada C bir ödünç bitidir (ekrandan, 01:55:00):

| Koşul | Kısaltma | Durum | Bayraklar |
|---|---|---|---|
| Branch if above | BA | $A>B$ | $C+Z=0$ |
| Branch if above or equal | BAE | $A\ge B$ | $C=0$ |
| Branch if below | BB | $A<B$ | $C=1$ |
| Branch if below or equal | BBE | $A\le B$ | $C+Z=1$ |
| Branch if equal | BE | $A=B$ | $Z=1$ |
| Branch if not equal | BNE | $A\ne B$ | $Z=0$ |

Analiz derste öğrencilere sorularak yapıldı:

- $R1>R2$ ise çıkarmada ödünç oluşmaz ($C=0$). Değerler farklı olduğu için $Z=0$ olur. İki koşulu birden ifade eden ifade $C+Z=0$'dır, yani C ile Z'nin OR'u 0 olmalıdır.
- $R1\ge R2$ ise eşit olsalar bile $C=0$ olur. Z ise eşitlikte 1, büyüklükte 0'dır. Bu yüzden yalnız $C=0$ yeterlidir.
- $R1<R2$ ise kesinlikle bir ödünç üretilir. Ödünç bayrağı çıkarmada elde bayrağının kendisidir. Z'nin 0 olmasına ayrıca bakmaya gerek yoktur; $C=1$ yeterlidir.
- $R1\le R2$ ise ya eşitlikte $Z=1$ ya da küçüklükte $C=1$ olur. Herhangi birinin 1 olması yeterlidir: $C+Z=1$.
- Eşitlik için $Z=1$, eşitsizlik için $Z=0$ yeterlidir.

### 10.3 Karmaşık dallanmalar: işaretli sayılar

İşaretli sayılarda durum daha karmaşıktır (ekrandan, 01:50:00 ve 02:05:00):

| Koşul | Kısaltma | Durum | Bayraklar |
|---|---|---|---|
| Branch if greater | BG | $A>B$ | $(N\oplus V)+Z=0$ |
| Branch if greater or equal | BGE | $A\ge B$ | $N\oplus V=0$ |
| Branch if less | BL | $A<B$ | $N\oplus V=1$ |
| Branch if less or equal | BLE | $A\le B$ | $(N\oplus V)+Z=1$ |
| Branch if equal | BE | $A=B$ | $Z=1$ |
| Branch if not equal | BNE | $A\ne B$ | $Z=0$ |

Eşitlik ve eşitsizlik için işaretli sayılarda da yalnız Z bayrağına bakmak yeterlidir. 8 bitte işaretli aralık $-128\ldots127$'dir. Çıkarmanın sonucu bu aralığa sığmıyorsa taşma bayrağı 1 olur.

**$R1>R2$ durumu.** Üç senaryo vardır:

- R1 pozitif, R2 negatif. Pozitiften negatif çıkarılınca sonuç 127'nin üstüne taşabilir.
- İkisi de pozitif ve R1 daha büyük. Sonuç kesinlikle aralıkta kalır: $V=0$, $N=0$.
- İkisi de negatif ve R1 daha büyük (ör. $-1$ ve $-2$). Negatif çıkarmak pozitife çevirdiği için sonuç yine aralıkta kalır: $V=0$, $N=0$.

İncelenmesi gereken senaryo pozitif-negatif olanıdır. Taşma olmazsa sonuç pozitiftir: $V=0$, $N=0$. Taşma olursa, pozitiften negatif çıkarmak iki pozitif sayıyı toplamak gibi olduğu için sonuç negatif görünür: $V=1$, $N=1$. Yani her üç senaryoda taşma bayrağı ile işaret bayrağı aynı değerdedir. Bu durum XOR ile anlaşılır: $N\oplus V=0$. Eşitlik istenmediği için ayrıca $Z=0$ olmalıdır. İkisini birleştiren koşul $(N\oplus V)+Z=0$'dır.

**Soru:** Negatif ile pozitif neden karşılaştırılmadı?
**Cevap:** Çünkü $R1>R2$ durumu ele alınıyor. Negatif eksi pozitif durumu $R1<R2$ ve $R1\le R2$ analizinde incelenir.

**$R1\ge R2$ durumu.** Aynı senaryolara eşitlik eklenir. $N\oplus V$ yine 0 olmalıdır. Z ise 0 da 1 de olabileceği için formülden çıkarılır: $N\oplus V=0$.

**$R1<R2$ durumu.** Senaryolar şunlardır:

- İkisi de pozitif. Sonuç aralıkta kalır, $V=0$; küçükten büyük çıkarıldığı için $N=1$.
- İkisi de negatif (ör. $-2$ ve $-1$). Sonuç aralıkta kalır, $V=0$, $N=1$.
- Negatif eksi pozitif. Bu iki negatif sayının toplamı gibidir. Taşma olmazsa sonuç negatiftir: $V=0$, $N=1$. Taşma olursa ($-128$ tarafından) sonuç pozitif çıkar: $V=1$, $N=0$.

Her durumda taşma ve işaret bayrakları terstir: $N\oplus V=1$. $R1\le R2$ için eşitlikte Z de 1 olabileceğinden ikisinin OR'u aranır: $(N\oplus V)+Z=1$.

Bir öğrencinin sorusu üzerine hoca negatif eksi pozitif senaryosunu iki örnekle açtı:

- $-2-1=-3$: taşma yok, sonuç negatif, $N=1$, $V=0$.
- $-120-20=-140$: $-128$'in altına taşar, $V=1$. İki negatif sayının toplamı ancak sonuç pozitif çıkarsa taşmış sayılır. Bit düzeyinde $-120$ ile $-20$ toplanınca 8. bit 0 çıkar, yani $N=0$ olur.

Hoca öğrenciye işlemi bit düzeyinde kendisinin yapmasını önerdi. Kontrol: $-140$'ın 8 bitlik karşılığı $(0111\,0100)_2=116$'dır, en yüksek bit 0'dır (python ile doğrulandı). Ayrıca 8 bitlik bütün $(R1,R2)$ çiftleri için hem işaretsiz hem işaretli tablolardaki altı koşul python'da kaba kuvvetle denendi; hepsi doğru çıktı.

Bu analizin donanım sonucu şudur: örneğin BG komutu desteklenecekse, işlem sonucunda üretilen N, V ve Z bayraklarını alıp $(N\oplus V)+Z$ fonksiyonunu hesaplayan ve sonuç 0 ise "doğru" üreten bir donanım eklenmelidir.

## 11. Kesmeler

8086'dan bilindiği gibi dış dünyadan kesme istekleri gelebilir. Bunların değerlendirilip değerlendirilmeyeceğini açıp kapatan bir bayrak vardır: kesme bayrağı (IF). IF kuruluysa ve bir kesme isteği gelmişse, o sırada yürütülen komut bittikten sonra istek değerlendirilir. Tasarımda bu, her komutun sonunda kontrol edilen bir "end of instruction" durum bitiyle sağlanır varsayılır. Kesme isteğine bir kesme alındı (interrupt acknowledge) sinyaliyle cevap verilir. Ardından istekte bulunandan hangi kesme alt programına dallanılacağını gösteren bir vektör adresi beklenir. Bu adres PC'ye yüklenince kesme alt programı yürütülür. Kesme de program akışını kıran ve değiştiren bir yaklaşım olduğu için komut kümesi mimarisi içinde ele alındı. Hoca bununla ISA konusunu kabaca tamamladı.

## 12. Datapath'e Giriş: Yazmaç Dosyası ve Fonksiyon Birimi

Varılması hedeflenen nihai yapı bir single cycle computer'dır. Hoca bu yapının alt modüllerini adım adım inşa edeceklerini söyledi. Datapath şeklinde mavi ile işaretlenen bölgeler ardışıl devreleri, yani yazmaç içeren kısımları gösterir. Bu bölgelerde veri aktarımı senkrondur, saat işaretinin ilgili kenarında olur. Geri kalan kısımlar kombinasyonel devrelerdir.

### 12.1 Yazmaç dosyası (register file)

Yazmaç dosyası içinde n bitlik yazmaçlar barındırır. Yazmaçlar arası, yazmaçla bellek arası ve ALU/shifter sonuçlarından yazmaca veri aktarımını desteklemelidir. Yapı, RTL konusundaki ortak MUX yolu tasarımına benzer (ekrandan, 02:15:00):

- Dört yazmaç vardır (R0-R3). Bunlardan herhangi biri A kanalına, herhangi biri de B kanalına çıkarılabilmelidir.
- A kanalı için n bitlik bir 4x1 MUX gerekir. Dört girişten birini seçmek için 2 seçim ucu gerekir: **A select** (A address). 00, 01, 10 ya da 11 verilerek R0-R3'ten biri A data çıkışına aktarılır.
- B kanalı için de ayrı bir n bitlik 4x1 MUX ve 2 bitlik **B select** (B address) vardır.
- İki kanalın ayrı MUX'ları olması, aynı yazmacın iki kanaldan birden çıkmasını sağlar; örneğin R0 ile R0'ı toplamak ya da R0 ile R1'i OR'lamak gibi.

Yazmaç dosyasına giren veri (D data) üç kaynaktan gelebilir:

- Bellekten okunan değer (MUX D üzerinden).
- Fonksiyon biriminden gelen aritmetik/lojik işlem sonucu (önce MUX F, sonra MUX D üzerinden).
- Shifter'dan gelen kaydırma/döndürme sonucu (yine MUX F ve MUX D üzerinden).

Yazma tarafında komutlarda iki kaynak ve bir hedef bulunur. Örneğin `ADD R1,R2,R3` komutu $R1\leftarrow R2+R3$ demektir. Hedef yazmaç, 2 bitlik **Destination select** (D address) ile sürülen 2x4 kod çözücüyle seçilir. Kod çözücünün her çıkışı bir AND kapısında **Load enable** ile birleşir ve ilgili yazmacın Load ucunu sürer. Bazı komutlarda sonuç saklanmaz; örneğin `CMP R1,R2`'de Load enable 0 tutulur. Toplama örneğinde Load enable 1, Destination select 01 yapılır. Toplam sonucu bütün yazmaçların veri girişine gider, ama yalnız R1'in yükleme kapısı açık olduğu için saatin yükselen kenarında değer yalnız R1'e yüklenir (ekrandan, 02:25:00).

Blok diyagram olarak yazmaç dosyasının n bitlik A ve B çıkışları, n bitlik bir D girişi ve dört kontrol ucu vardır: D select, A select, B select, Load enable. Bu yapı herhangi bir yazmacı A kanalına, herhangi birini B kanalına çıkarmayı ve işlem sonucunu herhangi bir üçüncü yazmaca yazmayı destekler. Hoca bunun, RTL konusunda ortak yol, adanmış (dedicated) MUX ve üç durumlu (tristate) yol üzerinden görülen yapıların özelleşmiş bir hâli olduğunu hatırlattı.

### 12.2 MUX B ve sabit değer

MUX B olmasaydı, komut içinde sabit taşıyan (immediate) işlemler yapılamazdı. Böyle bir komutun makine kodunda sabit doğrudan komuta gömülüdür; örneğin hocanın verdiği örnekte son 3 bit 3 değerini taşır. Komut çözücü bu sabiti çıkarır ve fonksiyon birimine aktarmak gerekir. MUX B, 1 bitlik **MB select** ile ya yazmaç dosyasının B kanalını ya da komuttan gelen sabiti (Constant in) Bus B'ye aktarır (ekrandan, 02:30:00).

<!-- BELİRSİZ: Hocanın sabit içeren örnek komutu karede görülmedi; altyazıdan yalnız sabitin 3 değerinde olduğu anlaşılıyor. -->

### 12.3 Fonksiyon birimi

Fonksiyon birimi (function unit) aritmetik/lojik işlemleri ve kaydırma işlemlerini yapar (ekrandan, 02:30:00):

- **ALU:** A ve B girişleri vardır. Fonksiyon seçimi 4 bittir ($S_{2:0}$ ve $C_{in}$, G select). Yani $2^4=16$ farklı fonksiyon yapılabilir: $A+B$, $A-B$, $A+\bar B$ gibi işlemler ya da A'yı veya B'yi aktarma gibi transferler. ALU durum bayraklarını da üretir: taşma (V), elde (C), işaret (N) ve bir sıfır algılayıcı üzerinden sıfır (Z).
- **Shifter:** Yalnız B kanalına bağlıdır, bu yüzden komutlar buna göre düzenlenmelidir. 2 bitlik H select ile dört fonksiyondan birini uygular: sağa kaydır, sola kaydır, döndürme gibi. Sağa ve sola kaydırmada besleme girişleri ($I_R$, $I_L$) vardır.
- **MUX F:** ALU ile shifter kombinasyonel devrelerdir ve ikisi de her zaman çalışır; hangisinin çalışacağı baştan seçilemez. Hangisinin çıkışının dışarı aktarılacağını 1 bitlik **MF select** seçer. Örneğin shifter çıkışı için MF select 1 yapılır.
- **MUX D:** Fonksiyon biriminin çıkışı ile bellekten gelen veri (Data in) arasında seçim yapar ve sonucu Bus D üzerinden yazmaç dosyasına götürür. Bus A "Address out", Bus B "Data out" olarak belleğe gider.

**Soru:** Bu yapıda belleğe yazma ya da bellekten okuma yok, değil mi?
**Cevap:** Hafıza birimi ve onun kontrol uçları henüz çizilmedi. Bir bellek eklenip kontrol uçları tanımlanınca, örneğin R1'in içeriği belleğin bir adresine yazılabilecek. Şu aşamada yalnız CPU'nun çekirdek, fonksiyonel kısmıyla ilgileniliyor. Program belleği, makine kodlarını çözen komut çözücü (instruction decoder) ve PC kontrolü ileride adım adım eklenecek.

Önümüzdeki adımlar şöyle sıralandı: aritmetik birim tasarımı, lojik birim tasarımı, ikisini birleştirerek ALU tasarımı, tek başına shifter tasarımı, son olarak ALU ile shifter'ı birleştirerek fonksiyon birimi tasarımı.

## 13. Aritmetik Birim Tasarımı

### 13.1 Genel yapı

ALU blok olarak bir A kanalı, bir B kanalı, fonksiyon seçim uçları, toplama için $C_{in}$ ve $C_{out}$ uçları ve işlem sonucunu veren G çıkışlarından oluşur. Hoca toplayıcı-çıkarıcı devreyi hatırlattı: tam toplayıcının $C_{in}$ ucuna bağlanan değer aynı zamanda bir kontrol ucu gibi kullanılıyordu. ALU'da da $C_{in}$ normalde bir elde girişidir, ama yapılan bağlantılarla bir kontrol ucu görevi de görür. Dört kontrol ucundan biri $C_{in}$, diğer üçü fonksiyon seçim uçlarıdır.

Aritmetik birim en genel anlamda n bitlik bir paralel toplayıcıyla tasarlanır. A kanalı bir "A lojiği"nden, B kanalı bir "B lojiği"nden geçip toplayıcıya verilir. Bu lojikler olmasaydı yapılabilecek tek işlem $A+B$ olurdu. Örneğin toplayıcı-çıkarıcıda bir kanal bir XOR katından geçiriliyordu. Tasarımda önce istenen fonksiyonlar tanımlanır, sonra bunları sağlayan lojikler bulunur.

Derste ele alınan özel durumda A lojiği yoktur: A doğrudan toplayıcının X girişine gider, B ise S0 ve S1 ile kontrol edilen bir "B input logic"ten geçerek Y girişine gelir. Çıkış şudur (ekrandan, 02:35:00):

$$G = X + Y + C_{in}$$

**Soru:** Bu tasarımda X'in A olmaktan başka şansı yok, değil mi? Onu A diye verip B'yi düzenleyeceğiz.
**Cevap:** Evet, böyle ilerlenecek.

### 13.2 Fonksiyon tablosu ve $X_i$, $Y_i$, $C_{in}$ değerleri

S0 ve S1 dört durum verir. Hoca eldenin durumunu da hesaba katmak için bir kontrol daha ekledi ve önce X, sonra karışmasın diye K adını verdi. Toplam 8 durum vardır. İstenen fonksiyonlar ve her biri için toplayıcı girişlerine gelmesi gereken değerler adım adım bulundu (ekrandan, 02:45:00 ve 02:50:00):

| $K$ | $S_1$ | $S_0$ | $G$ | $X_i$ | $Y_i$ | $C_{in}$ |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | $A$ | $A_i$ | 0 | 0 |
| 0 | 0 | 1 | $A+B$ | $A_i$ | $B_i$ | 0 |
| 0 | 1 | 0 | $A+\bar B$ | $A_i$ | $\bar B_i$ | 0 |
| 0 | 1 | 1 | $A-1$ | $A_i$ | 1 | 0 |
| 1 | 0 | 0 | $A+1$ | $A_i$ | 0 | 1 |
| 1 | 0 | 1 | $A+B+1$ | $A_i$ | $B_i$ | 1 |
| 1 | 1 | 0 | $A+\bar B+1$ | $A_i$ | $\bar B_i$ | 1 |
| 1 | 1 | 1 | $A$ | $A_i$ | 1 | 1 |

Satırların gerekçeleri derste öğrencilerle birlikte kuruldu:

- **$G=A$ (000):** X'e zaten A bağlıdır. A'ya bir şey eklenmemesi için B ne olursa olsun bütün $Y_i=0$ ve $C_{in}=0$ olmalıdır.
- **$G=A+B$ (001):** $Y_i=B_i$, $C_{in}=0$.
- **$G=A+\bar B$ (010):** Her $B_i$ bitinin bire tümleyeni $Y_i$'ye gelmeli, $C_{in}=0$.
- **$G=A-1$ (011):** Bir öğrenci bütün $Y_i$'lere 1, $C_{in}$'e 0 vermeyi önerdi. n bitlik $11\ldots1$ ikiye tümleyende $-1$ olduğu için A ile $-1$ toplanır ve $A-1$ elde edilir. Hoca başka alternatifler de olduğunu söyledi; örneğin $Y_i$'ye $-2$, $C_{in}$'e 1 vermek. Ama bunu zorlama buldu. Çünkü amaç, ilk yarıda $C_{in}=0$, ikinci yarıda $C_{in}=1$ tutarak K'yı doğrudan $C_{in}$'e bağlamak ve elde için ayrı bir devre kullanmamaktır.
- **$G=A+1$ (100):** $C_{in}=1$ ve bütün $Y_i=0$.
- **$G=A+B+1$ (101):** $Y_i=B_i$, $C_{in}=1$.
- **$G=A+\bar B+1$ (110):** $\bar B+1=-B$ olduğu için bu işlem $A-B$'dir. Hoca, fonksiyonun tabloda doğrudan "$A-B$" diye verilebileceğini ve bu eşitliğin mutlaka hatırlanması gerektiğini söyledi. $Y_i=\bar B_i$, $C_{in}=1$.
- **$G=A$ (111):** Bir öğrenci $Y_i$'ye 1 vermeyi önerdi. Bütün $Y_i$'ler 1 olunca $-1$ elde edilir ve $-1+1$ birbirini götürür, geriye A kalır.

Tablodan iki sonuç hemen görülür: $C_{in}=K$, yani dışarıdan verilen K kontrolü doğrudan $C_{in}$'e bağlanır; ve $X_i=A_i$, çünkü X tarafında lojik kullanılmamıştır. Geriye yalnız $Y_i=f(B_i,K,S_1,S_0)$ fonksiyonunu bulmak kalır.

### 13.3 Karnaugh haritası ile $Y_i$

$Y_i$ için dört değişkenli bir Karnaugh haritası kuruldu: bir eksende $B_iK$, diğer eksende $S_1S_0$ (Gray sırası 00, 01, 11, 10). Tablodan okunan değerler şunlardır:

- $S_1S_0=00$: B'den ve K'dan bağımsız olarak $Y_i=0$.
- $S_1S_0=01$: $Y_i=B_i$.
- $S_1S_0=10$: $Y_i=\bar B_i$.
- $S_1S_0=11$: her durumda $Y_i=1$.

K'nın 0 ve 1 olduğu sütunlarda aynı değerler çıktığı için K fonksiyondan düşer. Hoca iki grup aldı ve önce yanlış yazıp sonra düzeltti: bir grupta $S_0$ düşer ve $S_1\bar B_i$ kalır, diğer grupta $S_1$ düşer ve $S_0B_i$ kalır:

$$Y_i = B_iS_0 + \bar{B_i}S_1$$

Bu B girişi lojiği her bit diliminde (bit slice) gerçeklenince fonksiyon tablosunu yerine getiren aritmetik birim tasarlanmış olur. İfade doğruluk tablosuyla kaba kuvvetle kontrol edildi. Ayrıca 8 bitlik birimin sekiz satırın hepsinde tablodaki G'yi verdiği örnek sayılarla python'da doğrulandı.

**Soru:** Fonksiyon çıkarmadan, tablodan doğrudan MUX'larla da B girişi lojiği tasarlanabilir, değil mi?
**Cevap:** Kesinlikle. Her lojik tasarım MUX'la yapılabilir; MUX'larla lojik fonksiyonların nasıl tasarlandığı daha önce görülmüştü.

> **Ek bilgi (derste anlatılmadı):** MUX çözümünde $S_1S_0$ seçim uçlarına bağlanmış bir 4x1 MUX'un girişlerine sırasıyla $0$, $B_i$, $\bar B_i$ ve $1$ verilir. Bu, Karnaugh haritasındaki dört satırın doğrudan karşılığıdır.

Hoca daha sonra daha genel durumların görüleceğini söyledi: $C_{in}$ de sabitlenmeyecek, K, $S_1$, $S_0$, $A_i$ ve $B_i$'nin bir fonksiyonu olabilecek; o zaman A girişi lojiği, B girişi lojiği ve elde lojiği tasarımla bulunacak.

## Örnek Sorular

Aşağıdaki sorular dersin başında ekranda çözülen ara sınav soruları ile derste sözlü sorulan sorulardır.

### Soru 1 (ekrandan, 00:05:00)

8 bit ikiye tümleyen biçiminde verilen işaretli iki sayı $A=(1100\,0010)_2$ ve $B=(0011\,1011)_2$ için $A-B$ işleminin sonucuna göre N (negative), V (overflow) ve Z (zero) bayrakları ne olur?

A) N=0, V=0, Z=0 B) N=1, V=1, Z=1 C) N=0, V=1, Z=0 D) N=1, V=0, Z=0 E) N=0, V=0, Z=1

**Çözüm (derste verildi):**

- Onluk yol: $A=-(0011\,1110)_2=-62$, $B=59$. $-62-59=-121<0$ olduğu için $N=1$. $-128\le-121\le127$ olduğu için $V=0$. Sonuç sıfırdan farklı olduğu için $Z=0$.
- İkilik yol: $-B=(1100\,0101)_2$.

```text
   1100 0010
 + 1100 0101
 -----------
 1 1000 0111     C6 = 1, C7 = 1
```

$N=1$ (8. bit), $V=C_6\oplus C_7=0$, $Z=0$. Doğru cevap D (python ile doğrulandı).

### Soru 2 (ekrandan, 00:05:00)

8 bit ikiye tümleyen biçiminde verilen $(1011\,0100)_2$ sayısının onluk karşılığı ve "aritmetik sola kaydırma" sonucunda V (taşma) bitinin değeri nedir?

**Çözüm (derste verildi):** $(1011\,0100)_2=-(0100\,1100)_2=-76$. SHLA sonucu $(0110\,1000)_2=+104$ olur. En yüksek bit 1 iken 0 oldu, yani işaret değişti: $V=1$. Onlukta da $-76\to+104$ işaret değişimi taşmayı gösterir ($-152$ 8 bite sığmaz). Python ile doğrulandı.

<!-- BELİRSİZ: Soru 2'nin şıkları karede görünmüyor. -->

### Soru 3 (derste sözlü, 00:07:56)

$16G\times32$ bellek modülü için adres ve veri yolu genişlikleri nedir?

**Çözüm (derste verildi):** Veri yolu 32 bittir. $16G=2^4\cdot2^{30}=2^{34}$ adres gözü vardır, yani adres yolu $\log_2 2^{34}=34$ bittir.

### Soru 4 (derste sözlü, 00:08:31)

3 adres girişli ve her gözünde 4 veri biti olan bir ROM'un ($2^3\times4=8\times4$) işaretlenmiş bağlantılarına göre çıkış fonksiyonlarından hangisi doğrudur?

**Çözüm (derste verildi):** ROM'un birinci katı bir kod çözücü, ikinci katı programlanabilir bir OR dizisidir. Kod çözücü çıkışları minterimlerdir, bu yüzden her çıkış kendisine bağlı minterimlerin toplamıdır. Altyazıya göre şıklardaki fonksiyonlar sırasıyla $m_2,m_5,m_7$; $m_0,m_7$; $m_1,m_4$ ve $m_1,m_5,m_7$ minterimlerini içeriyordu ve doğru cevap D idi.

<!-- BELİRSİZ: ROM şekli ve şıkların tam metni karede görülmedi; minterim listesi altyazıdan alındı. -->

### Soru 5 (ekrandan, 00:10:00)

$256K\times4$ RAM modülleri kullanılarak $1M\times32$ RAM oluşturmak için kaç tane $256K\times4$ RAM modülüne ihtiyaç vardır? Kullanılması gereken kod çözücü (decoder) boyutu nedir?

A) 8 modül ve 2-to-4 B) 8 modül ve 3-to-8 C) 16 modül ve 2-to-4 D) 16 modül ve 3-to-8 E) 32 modül ve 2-to-4 F) 32 modül ve 3-to-8

**Çözüm (derste verildi):**

$$\frac{1M\times32}{256K\times4}=\underbrace{4}_{\text{kapasite}}\times\underbrace{8}_{\text{sütun, veri yolu genişletme}}=32\ \text{modül}$$

4 satır için 4 çıkışlı, yani 2 girişli bir 2x4 kod çözücü gerekir. Hocanın ikinci kontrolü şöyledir: $1M$ için 20, $256K$ için 18 adres ucu gerekir; kalan 2 uç kod çözücünün girişleridir. Doğru cevap E (python ile doğrulandı).

### Soru 6 (ekrandan, 00:10:00)

Şekilde verilen 4x1 MUX'un çıkışı aşağıdakilerden hangisidir? (X seçim ucu $S_0$'a, W seçim ucu $S_1$'e bağlıdır.)

**Çözüm (derste verildi):** Altyazıya göre girişler şöyledir: 0 numaralı giriş $Y\cdot Z$ (hoca slayttaki AND işaretinin eksik yazıldığını düzeltti), 1 numaralı giriş $\bar Z$, 2 numaralı giriş $\bar Y$, 3 numaralı giriş $Y$ XNOR $Z$.

$$F=\bar W\bar X\,YZ+\bar WX\,\bar Z+W\bar X\,\bar Y+WX\,(Y\odot Z)$$

Doğruluk tablosundan $F(W,X,Y,Z)=\Sigma m(3,4,6,8,9,12,15)$ çıkar ve doğru cevap A'dır. Bu sonuç doğruluk tablosuyla kaba kuvvetle python'da doğrulandı.

<!-- BELİRSİZ: MUX girişlerinin şekildeki bağlantıları karede tam görülmedi; giriş fonksiyonları altyazıdan alındı. -->

### Soru 7 (ekrandan, 00:15:00)

Aşağıda verilen senkron sayıcının sayma aralığını belirleyiniz. Sayıcının paralel girişleri $D_3D_2D_1D_0=1000$'dır. $Q_3$, $Q_2$ ve $Q_0$ bir AND kapısına girer. AND çıkışı Reset ile OR'lanıp LOAD ucuna gider; CLEAR ucunda 1 vardır.

**Çözüm (derste verildi):** Sayıcı ilk anda sıfırdan saymaya başlar. $Q_3=Q_2=Q_0=1$ olduğu ilk an, yani $1101$ durumunda LOAD üretilir ve $1000$ yüklenir. Bu yüzden sayıcı ilk turdan sonra $1000$ ile $1101$ arasında, yani 8 ile 13 arasında sayar (python ile benzetildi: $0,1,\ldots,13,8,9,\ldots,13,8,\ldots$).

### Soru 8 (derste sözlü, 00:15:28)

T flip-flop'larla kurulmuş asenkron sayıcının sayma yönü nedir?

**Çözüm (derste verildi):** T uçlarında 1 olduğu için her flip-flop kendi saat girişinin tetikleme kenarında durum değiştirir; bu bir asenkron dalgalı (ripple) sayıcıdır. Saat düşen kenarda tetikliyorsa ve $Q_0$, $Q_1$'in, $Q_1$ de $Q_2$'nin saatini sürüyorsa dalga şekli $Q_2Q_1Q_0$ olarak $000, 001, 010, 011, 100, \ldots$ verir; yani yukarı sayıcıdır. Tetikleme yönleri yükselen kenar yapılınca $000, 111, 110, 101, \ldots$ elde edilir ve sayıcı aşağı sayıcı olur. Altyazıya göre doğru cevap A idi.

<!-- BELİRSİZ: Soru 8'in şekli ve şıkları karede görülmedi. -->

### Soru 9 (derste sözlü, 00:17:58)

Verilen doğrusal geri beslemeli kaydırmalı yazmacın (LFSR) durum geçişleri nedir?

**Çözüm (derste verildi):** Sonraki durumlar şimdiki durumlar cinsinden yazılır: $Q_C^+=Q_B$, $Q_B^+=Q_A$, $Q_A^+=Q_B\odot Q_C$ (XNOR). $Q_AQ_BQ_C$'nin 8 durumu için geçişler (ara adım eklendi, python ile hesaplandı):

| $Q_AQ_BQ_C$ | Sonraki |
|---|---|
| 000 | 100 |
| 001 | 000 |
| 010 | 001 |
| 011 | 101 |
| 100 | 110 |
| 101 | 010 |
| 110 | 011 |
| 111 | 111 |

<!-- BELİRSİZ: LFSR şekli ve şıklar karede görülmedi. Altyazıya göre C ve E şıkları doğruydu. -->

### Soru 10 (ekrandan, 00:20:00)

Şekildeki PLA'nın çıkış fonksiyonlarından hangisi doğru yazılmıştır? Şıklar: A) $F$, B) $G$, C) $H(A,B,C)=\Sigma m(0,1,2,3,6,7)$, D) Hepsi.

**Çözüm (derste verildi):** AND katındaki terimler eksik değişkenlerle genişletilerek minterimlere açılır (ekrandan, 00:20:00):

- $\bar A\bar B=\bar A\bar B\bar C+\bar A\bar BC=m_0+m_1$
- $\bar AB=m_2+m_3$
- $A\bar B\bar C=m_4$
- $\bar B\bar C=m_4+m_0$
- $AC=m_5+m_7$
- $BC=m_7+m_3$
- $B\bar C=m_6+m_2$
- $\bar AB\bar C=m_2$

OR katındaki bağlantılara göre $F=m_0+m_1+m_2+m_3+m_5+m_7$, $G=m_0+m_1+m_4+m_2=\Sigma m(0,1,2,4)$, $H=m_0+m_1+m_7+m_3+m_6+m_2=\Sigma m(0,1,2,3,6,7)$. Üç fonksiyon da şıklarla uyuşur ve doğru cevap D (Hepsi) olur.

<!-- BELİRSİZ: A ve B şıklarının metni karede görünmüyor; F ve G'nin minterim listeleri hocanın el yazısından ve altyazıdan alındı. -->

### Soru 11 (derste sözlü, 01:06:21)

R1 yazmacının 4 numaralı bitinin 1 olup olmadığı ve 7 numaralı bitinin 0 olup olmadığı lojik işlemlerle nasıl anlaşılır?

**Çözüm (derste verildi):** 4. bit için `AND R1,10H`; sonuç 0'dan farklıysa bit 1'dir ve buna göre koşullu dallanılır. 7. bit için ya `80H` ile AND edilip sonucun 0 olup olmadığına bakılır ya da `7FH` ile OR edilip sonuç FF ile karşılaştırılır: FF ise bit 1, değilse 0'dır. XOR ve 80H ile OR bu iş için uygun değildir.

### Soru 12 (derste sözlü, 01:11:03)

Bir yazmaçtaki 1'lerin sayısı hangi komutlarla bulunabilir?

**Çözüm (derste verildi):** Her adımda kaydırılır; en düşük bit eldeye düşer ve her adımda ADC ile elde bir sayaca eklenir. Değerin kaybolmaması isteniyorsa kaydırma yerine döndürme kullanılır.

### Soru 13 (derste sözlü, 01:51:42)

8 bitlik yazmaçlarda işaretsiz ve işaretli olarak yazılabilecek sayı aralıkları nedir? $R1>R2$ iken $R1-R2$ işleminde C ve Z bayrakları ne olur?

**Çözüm (derste verildi):** İşaretsiz aralık 0..255 (256 değer), işaretli aralık $-128..127$'dir. $R1>R2$ ise ödünç yoktur ($C=0$) ve sonuç sıfır değildir ($Z=0$), yani $C+Z=0$ olur.

### Soru 14 (derste sözlü, 02:42:21)

Aritmetik birim fonksiyon tablosunda $G=A$ (000), $G=A-1$ (011) ve $G=A$ (111) için $Y_i$ ve $C_{in}$'e ne verilmelidir?

**Çözüm (derste verildi):** 000 için $Y_i=0$, $C_{in}=0$. 011 için bütün $Y_i=1$ (ikiye tümleyende $-1$), $C_{in}=0$. 111 için bütün $Y_i=1$, $C_{in}=1$; $-1+1$ birbirini götürür ve geriye A kalır.

## Dersin Toparlaması

Ders, ara sınav sorularıyla lojik tasarım konularının (ikiye tümleyen bayrakları, bellek genişletme, ROM/PLA/MUX ile fonksiyon okuma, sayıcılar, LFSR) tekrarıyla başladı. Ardından bir işlemcinin komut kümesi mimarisine geçildi. Komutların Opcode, Mode ve Address alanlarından oluştuğu, program sayacının akışı nasıl yürüttüğü ve yedi temel adresleme modunun etkin adresi nasıl belirlediği görüldü. Sonra komut grupları incelendi: veri transferi, aritmetik, lojik ve bit işleme, kaydırma ve döndürme, program kontrolü. İşaretsiz (above/below) ve işaretli (greater/less) koşullu dallanmaların bayrak koşulları ayrıntılı olarak türetildi; en kritik sonuç işaretli karşılaştırmada $N\oplus V$'nin rolüydü.

Son bölümde single cycle computer'ın datapath'ine geçildi. Yazmaç dosyasının A/B select, Destination select ve Load enable ile nasıl kontrol edildiği; fonksiyon biriminin ALU, shifter, MUX B, MUX F ve MUX D bileşenleri tanıtıldı. Aritmetik birim, bir paralel toplayıcı ve $Y_i=B_iS_0+\bar{B_i}S_1$ B girişi lojiğiyle sekiz işlemi yapacak biçimde tasarlandı. Bir sonraki adım lojik birim tasarımı ve aritmetik birimle birleştirilerek ALU'nun oluşturulmasıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
