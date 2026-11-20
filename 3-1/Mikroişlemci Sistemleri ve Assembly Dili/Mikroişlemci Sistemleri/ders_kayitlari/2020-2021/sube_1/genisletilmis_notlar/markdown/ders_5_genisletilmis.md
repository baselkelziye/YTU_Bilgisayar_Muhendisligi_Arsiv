# Ders 5 Genişletilmiş Notu: Çevre Birimleri, G/Ç Komutları, G/Ç Haritalama ve Basit Düğme/LED Arayüzleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yeri: yardımcı devrelerden arayüzlere
- 2. Çevre birimleri ve hafıza birimleri
- 3. G/Ç assembly komutları
- 4. Çift ve tek adreste 8 ve 16 bitlik G/Ç
- 5. Hafıza ve G/Ç uzayının çift/tek bloklar halinde görülmesi
- 6. G/Ç haritalama yöntemleri
- 7. Düğme arayüzü
- 8. Kontak gürültüsü
- 9. LED arayüzü
- Örnek Sorular

## 1. Dersin yeri: yardımcı devrelerden arayüzlere

Önceki derslerde 8086'nın uç tanımları verilmiş, ardından işlemciyi enerji verildiğinde çalışabilir hale getiren yardımcı entegreler görülmüştü: saat darbesi üreteci, adres ve veri yolları için tutucu (latch) ve tampon devreler. Bu noktadan sonra ders, yardımcı entegrelerden arayüz (interface) cihazlarına döner.

Dönem boyunca bu yardımcı devreler beş grupta incelenecektir:

- Paralel veri alışverişi yapan programlanabilir hazır yardımcı devreler,
- Seri haberleşme yapan programlanabilir hazır yardımcı devreler,
- Zamanlayıcı ve sayıcı programlanabilir entegreler,
- Sayısal-analog ve analog-sayısal çevirici entegreler,
- Kesme denetleyicisi.

Bunlar G/Ç cihazları konusunda genel bir fikir verir. Son olarak hafıza birimlerinin 8086 ile arayüzü ele alınır. Ders bittiğinde hedef, bir insan arayüzü için giriş-çıkış yönlü kaba bir tasarım yapabilmek ve bir hafıza birimini mikroişlemciye bağlamak için gerekli ön bilgiye sahip olmaktır.

Programlanabilir arayüzlerin bir ön adımı vardır: kullanıcının kendi geliştirdiği (custom) çevre birimlerini 8086'ya bağlamak. Bu dersin konusu budur. Ekrandaki konu listesi (ekrandan, 00:05:00) şöyledir: çevre birimleri, G/Ç assembly komutları, G/Ç haritalama yöntemleri, basit arayüz devreleri (düğme arayüzü, LED arayüzü), basit çevre birimleri ve adres çözümleme (basit çıkış birimi, basit giriş birimi), çevre birimleri kontrolü. Kayıttaki süre LED arayüzünün sonuna kadar yetti; adres çözümleme ve çevre birimi kontrolü başlıklarına geçilemedi.

Hoca, giriş-çıkış komutlarının Assembly dersinde çok üzerinde durulmayan bir konu olduğunu, bu yüzden dersi daha önce almış olanlar için de yeni sayılacağını belirtti.

## 2. Çevre birimleri ve hafıza birimleri

Çevre birimleri (peripheral devices), mikroişlemci açısından giriş ya da çıkış işlemlerinin yapıldığı cihazlardır. Giriş ve çıkış dış dünyaya karşı yapılır. Mikroişlemci bir insanla etkileşimdeyse, insanın anlayacağı göstergeler ya da insanın bastığı tuşları anlamlandıran birimler bu işi görür.

Ekrandaki tanım üç maddedir (ekrandan, 00:10:00):

- Giriş ve/veya çıkış cihazlarıdır.
- Hafıza birimleri gibi belirli bir adres bölgesine yerleştirilirler.
- Hafıza birimine göre adres genişlikleri dardır (1-4 bayt).

### 2.1 Kapladıkları alan ve adres ucu sayısı

Mikroişlemcinin karşılaştığı birimler yalnız G/Ç birimleri değildir; hafıza birimleri de vardır. Bu yüzden çevre birimleri hafızayla karşılaştırılarak anlatılır. Hafıza elemanları 64 KB, 256 KB gibi büyük kapasitelerdedir; tek başına 1 MB'lık hafıza uzayının dörtte birini ya da tamamını doldurabilir. G/Ç birimleri ise çok daha az yer kaplar; örneğin 8255 hafıza uzayında yalnız 4 baytlık alan kaplar.

Bir cihazın kapladığı alan doğrudan adres ucu sayısına bağlıdır. Hocanın örneği:

- 256 KB'lık bir hafıza birimi: $256\text{K} = 2^8 \cdot 2^{10} = 2^{18}$, yani 18 adres ucu vardır ve 256 KB'lık alan kaplar.
- 8255: 2 adres ucu vardır; $2^2 = 4$ göz eder. Her göz 1 bayt olduğundan 4 baytlık alan kaplar.

Hafıza birimlerinde olduğu gibi çevre birimlerinin de belirli adresleri vardır. Bilgisayarın donanım özelliklerinde her cihazın hangi adres aralığına yerleştirildiği görülebilir; bu aralıklar örneğin anakart üreticisi tarafından tanımlanır ve işletim sistemi ile diğer programlar cihazlara bu adresler üzerinden erişir.

### 2.2 Referans mikroişlemcidir

Çıkış birimi ve giriş birimi, hem 8086'nın uçları hem de komutları açısından her zaman mikroişlemciye göre tanımlanır.

- Çıkış birimi: mikroişlemcinin dış dünyaya veri çıkarmasını sağlayan birimdir. Ona veri yazmak için 8086 komut setindeki `OUT` komutu kullanılır.
- Giriş birimi: dış dünyadaki bir veriyi mikroişlemciye aktaran birimdir. Veri aktarımında `IN` komutu kullanılır.

> **Hocanın vurgusu:** Hem çevre biriminin tanımı hem komutların yönü mikroişlemci referans alınarak yapılmalıdır.

## 3. G/Ç assembly komutları

`IN` ve `OUT` için toplam 8 komut varyasyonu vardır; 4'ü `IN`, 4'ü `OUT` ile ilgilidir (ekrandan, 00:15:00):

| | IN komutu | OUT komutu |
|---|---|---|
| Fixed address | `IN AL, p8` | `OUT p8, AL` |
| | `IN AX, p8` | `OUT p8, AX` |
| Variable address | `IN AL, DX` | `OUT DX, AL` |
| | `IN AX, DX` | `OUT DX, AX` |

### 3.1 Adres parametresi: p8 ya da DX

`p8` kısaltması 8 bitlik bir port adresidir. Kullanılacak port adresi 8 bite sığıyorsa, `p8` yerine adres doğrudan komuta yazılır; buna fixed address denir. Port adresi 8 bite sığmıyorsa adres kesinlikle DX yazmacı üzerinden verilir; buna variable address denir.

**Soru:** Adres 8 bite sığıyor olsa da DX üzerinden verilebilir mi? **Cevap:** Evet. Önce `MOV DX, 10H`, sonra `IN AL, DX` çalıştırmak geçerlidir. Ama aynı iş iki komutla yapılmış olur, mikroişlemci için daha uzun sürer. `IN` ve `OUT` sürekli çalıştırılan komutlar olduğundan ne kadar hızlı bir kod bloğu kurulursa o kadar avantajlıdır. Bu yüzden tercih: adres 8 bite sığıyorsa komutun içine gömmek, sığmıyorsa DX kullanmak.

### 3.2 Veri parametresi: AL ya da AX

Komutların ikinci parametresi verinin nerede olacağını belirtir. Bu parametre yalnız AL (8 bitlik işlem) ya da AX (16 bitlik işlem) olabilir; başka bir seçenek yoktur (ekrandan, 00:20:00 ve 00:25:00, slaytta AL ve AX işaretlenmiştir).

## 4. Çift ve tek adreste 8 ve 16 bitlik G/Ç

### 4.1 Çift adresten 8 bit: `IN AL, 10H`

`IN AL, 10H` komutu şu anlama gelir: 10H numaralı porttan değeri oku; bu 8 bitlik bir değerdir; onu AL yazmacına aktar (ekrandan, 00:30:00). Arka planda şu da vardır: 10H çift bir sayıdır. Mikroişlemci 10H portundaki veriyi veri yolunun düşük anlamlı baytından, yani D0-D7 uçlarından bekler, önce bu uçlardan okur, sonra AL'ye aktarır.

Bu sırada bir kontrol ucu da 0 olur. Geçen hafta anlatılan, mikroişlemcide fiziksel olarak tanımlı olmayan sanal "bus low enable" ucu A0'dır. 10H adresi A19-A0 uçlarına yazıldığında A0'ın 0 olduğu görülür. Adres zaten çift olduğu için mikroişlemci ikinci bir kontrol ucuna ihtiyaç duymaz; bu görevi A0 görür.

### 4.2 Tek adresten 8 bit: `OUT 11H, AL`

`OUT 11H, AL` komutunda (ekrandan, 00:20:00, slayta "OUT 11H, AL" yazılmıştır) AL'deki 8 bitlik değer veri yolunun yüksek anlamlı baytına, D8-D15 uçlarına çıkar ve oradan 11H portuna gider. Veri yolunun yüksek baytı kullanıldığı için mikroişlemci aktif 0 olan $\overline{BHE}$ (Bus High Enable) ucunda 0 üretir. Bunun neden böyle olduğu adres çözümleme ile daha net görülecektir.

> **Ders sonrası not:** Hoca bu örnekte bir an "adres yolunun yüksek anlamlı byte'ı" dedi (00:19:57), hemen ardından D8-D15 uçlarını söyledi; doğrusu veri yolunun yüksek anlamlı baytıdır.

### 4.3 Kural

Bu kural hem G/Ç hem hafıza işlemleri için geçerlidir; hafıza tarafı dönem sonunda hafıza konusunda genişletilecektir. Fixed ve variable adres durumlarının ikisinde de aynıdır:

- Çift adresten 8 bitlik işlem: `IN` komutunda veri D0-D7'den beklenir, `OUT` komutunda veri D0-D7'ye konur. Dış dünyaya bus low enable, yani $A0 = 0$ ile bildirilir.
- Tek adresten 8 bitlik işlem: `IN` komutunda veri D8-D15'ten beklenir, `OUT` komutunda veri D8-D15'e konur. $\overline{BHE} = 0$ üretilir.

### 4.4 Çift adresten 16 bit: `IN AX, 10H`

Her adres 8 bitlik bir göz olduğundan `IN AX, 10H` şu anlama gelir: AL'ye 10H'nin içeriğini, AH'ye 11H'nin içeriğini ata; yani 10H'den başlayan iki gözdeki veriyi AX'e aktar. Little endian düzen nedeniyle düşük adresteki 10H, 16 bitlik verinin düşük anlamlı baytıdır ve AL'ye gider; 11H yüksek anlamlı bayttır ve AH'ye gider.

Bu işlemin birinci kısmı çift adresten 8 bitlik bir işleme, ikinci kısmı tek adresten 8 bitlik bir işleme karşılık gelir. İkisinin aynı anda olabilmesi için mikroişlemci $\overline{BHE}$ ucunu 0 yapar; adres çift olduğu için A0'ın (bus low enable) 0 olması da garantidir. Her iki kontrol ucu aktif olunca veri hem D0-D7'ye hem D8-D15'e, yani veri yolunun tamamına aynı anda aktarılır. Mikroişlemci AL'ye D0-D7'deki veriyi, AH'ye D8-D15'teki veriyi yazar. `OUT` olsaydı AH'deki veri D8-D15'e, AL'deki veri D0-D7'ye yazılırdı.

Tahtadaki özet (ekrandan, 00:45:00): `IN AX, 10H` için `AX <-- [10H, 11H]`; D0-D7 → AL, D8-D15 → AH; "1 okuma yazma clock cycle".

> **Ders sonrası not:** Altyazıda bir yerde "D0, D17" geçer (00:28:39); bu, D0-D7'nin yanlış yazımıdır.

### 4.5 Tek adresten 16 bit: `IN AX, 11H`

`IN AX, 11H` komutunda mikroişlemci AL'ye 11H'nin, AH'ye 12H'nin içeriğini aktarmak ister. 11H ve 12H ikilik yazıldığında (ekrandan, 00:35:00):

- 11H = `0001 0001B`
- 12H = `0001 0010B`

Mikroişlemcinin görmek istediği uzay tek ve çift olmak üzere iki blok halindedir. Tahtadaki çizimde 11H tek blokta bir satırda ("1"), 12H ise çift blokta bir üst satırda ("2") yer alır. İki adres farklı satırlara düştüğü için tek adresten 16 bitlik işlem bir okuma-yazma çevriminde yapılamaz. Mikroişlemci önce tek adresten 8 bitlik işlemi, ikinci çevrimde de çift adresten 8 bitlik işlemi yapar.

Bir öğrencinin sorusu üzerine hoca adımları tahtada tekrar yazdı (ekrandan, 00:45:00): `IN AX, 11H` için `AX <-- [11H:12H]`; D8-D15 → LSb → AL; D0-D7 → MSb → AH; "2 okuma yazma clock cycle".

- 11H tek adres olduğu için veri D8-D15 üzerinden gelir. Mikroişlemci bu uçları örnekler, değeri içindeki geçici (temporary) yazmaçta tutar, sonra AL'ye aktarır. 11H'deki değer, 11H'den başlayan 16 bitlik verinin düşük anlamlı baytıdır.
- 12H çift adres olduğu için veri D0-D7 üzerinden gelir; yine geçici yazmaçtan AH'ye aktarılır. 12H'deki değer yüksek anlamlı bayttır.

**Soru:** Komutlar nereden okunuyor? **Cevap:** Komutlar program kod segmentinde, RAM üzerinde yerleşiktir; sırası gelen komut oradan alınır.

> **Hocanın vurgusu:** Assembly'de veri ve programları çift adreslere hizalı yazmaya çalışmanın arkasındaki sebep budur. Hizalı olursa komut bir okuma-yazma çevriminde gerçekleşir; hiza bozulursa çevrim sayısı ikiye çıkar.

### 4.6 Özet

Ekrandaki yazılı özet de aynıdır: port adresi 8 bite sığıyorsa fixed addressing ile komutun içinde verilir; 16 bite sığan bir adresse DX üzerinden verilir. `IN AL, DX`, `IN AX, DX`, `OUT DX, AL`, `OUT DX, AX` kullanılacaksa öncesinde DX'te uygun port adresi oluşturulmalıdır. Herhangi bir adresten 8 ya da 16 bitlik işlem yapılabilir:

- Çift adresten 8 bit, tek adresten 8 bit, çift adresten 16 bit: bir okuma-yazma çevrimi.
- Tek adresten 16 bit: iki okuma-yazma çevrimi, çünkü tek adres hafıza uzayının bir satırındayken sonraki çift adres başka bir satırdadır. Bunu mikroişlemci otomatik olarak yapar.

## 5. Hafıza ve G/Ç uzayının çift/tek bloklar halinde görülmesi

### 5.1 512K×16 hafıza arayüzü

10H (`0001 0000B`) ile 11H (`0001 0001B`) arasında değişen tek bit A0'dır. A0 adres çözümlemeye katılmaz, yalnız çift ve tek adresleri ayırmak için kullanılırsa geriye kalan bitler aynıdır ve aynı satırı gösterir. Uzay tek blok ve çift blok olarak ikiye bölündüğünde 10H ve 11H aynı satıra düşer. A0 = 0 çift bloğu, $\overline{BHE}$ aktifliği (A0 = 1 olan adres) tek bloğu seçer. Çift bloktan çıkan veri D0-D7'ye, tek bloktan çıkan veri D8-D15'e gider. Aynı satırdaki iki sütun birlikte seçilebiliyorsa iki bayt aynı anda veri yoluna çıkar.

8086'nın 20 adres ucu olduğu için hafıza kapasitesi toplam 1 MB'tır. Ama mikroişlemci bir seferde 16 bit veri de okumak isteyeceği için bu uzayı 1M adet 8 bitlik tek tek adreslenebilir göz olarak değil, 16 bitlik gözler olarak görmek ister: 1 MB'ı 16 bite bölünce 512K×16'lık bir hafıza arayüzü elde edilir; 512K çift ve 512K tek adres. Tahtada bu "Hafıza: kapasite 1M×8, uygun arayüz 512K×16" diye yazılmıştır (ekrandan, 00:50:00).

### 5.2 32K×16 G/Ç arayüzü

Hoca G/Ç uzayının en büyük kapasitesini ve bunun sebebini sordu; bir öğrenci 64 KB diye doğru cevap verdi. Sebebi port adresinin ya 8 bitlik bir sayı ya da 16 bitlik DX ile verilebilmesidir. Kullanılabilecek en büyük adres değeri $2^{16} = 64\text{K}$'dır; her göz 1 bayt olduğundan G/Ç uzayının kapasitesi 64K×8 = 64 KB'tır.

Mikroişlemci G/Ç'de de 16 bitlik veri okumak isteyebileceği için uygun arayüz 32K×16'dır: 64 KB'lık G/Ç uzayı 32K'lık iki alt bloktan oluşturulur. $\overline{BHE} = 0$ ise tek adresler, bus low enable (A0) = 0 ise çift adresler aktif edilir. Çift adresten 16 bitlik işlemde ikisi birden 0 olur, iki bloğun aynı satırı aktif olur ve 16 bitlik veri bir seferde veri yoluna aktarılır.

### 5.3 80386 ve 80486'da dört blok

80386 ve 80486'da veri yolları 32 bit olduğu için çift ve tek olmak üzere iki değil, dört blok vardır. Verilen adres 4'e tam bölünebiliyorsa 32 bitlik veri tek satırdan, anlam sırası doğru olarak ilgili yazmaca (örneğin EAX) aktarılır. Bloklardan çıkan veriler sırasıyla D0-D7, D8-D15, D16-D23 ve D24-D31 veri uçlarına gider ve 32 bitlik veri bir seferde okunur. 80486'nın 32 adres ucu vardır; bu da toplam 4 GB'lık bir alana karşılık gelir. Bu örnek, mikroişlemcinin tasarımı gereği hafıza ya da G/Ç uzayının nasıl oluşturulması gerektiğini gösterir.

> **Ders sonrası not:** Hoca 486 için konuşurken "512K çarpı 16'lık" ifadesini de kullandı (00:36:31); bu 8086'ya aittir. 4 GB'lık uzay 32 bitlik dört bloğa bölündüğünde uygun arayüz $2^{32} / 4 = 2^{30}$, yani 1G×32 olur.

## 6. G/Ç haritalama yöntemleri

G/Ç haritalama yöntemleri, mikroişlemcinin fiziksel bir ucu olan $M/\overline{IO}$ ucunun adres çözümlemede kullanılıp kullanılmamasından doğar (ekrandan, 00:55:00):

- Isolated I/O Mapping: $M/\overline{IO}$ ucu adres çözümleme için kullanılır.
- Memory Mapped I/O: $M/\overline{IO}$ ucu adres çözümleme için kullanılmaz.

### 6.1 $M/\overline{IO}$ ucu

Uç etiketinde IO'nun üzerinde bir çizgi vardır. Mikroişlemci hafıza işlemi yaparken bu uçta 1 üretir (M aktif 1 gibi); G/Ç işlemi yaparken IO aktif 0 gibi davranır ve uçta 0 oluşur. Dolayısıyla uç 1 ise hafıza işlemi, 0 ise G/Ç işlemi yapılmaktadır. `OUT` komutu kullanılmışsa uçta 0 oluşur.

> **Ders sonrası not:** Hoca açıklamanın başında bir an "hafıza işlemi ise $M/\overline{IO}$ ucunda sıfır" dedi (00:54:56); hemen ardından doğrusunu verdi: hafıza işleminde 1, G/Ç işleminde 0.

$M/\overline{IO}$ ucuna bakmadan ayırt edilemeyen bir durum vardır: `MOV AL, [10H]` ile `IN AL, 10H` (aynı örnek için `OUT` karşılığı da olabilir) adres uçlarına aynı değeri, 10H'yi çıkarır. Yalnız adres uçlarına bakarak işlemin G/Ç mi hafıza mı olduğu anlaşılamaz; bunun tek yolu $M/\overline{IO}$ ucuna bakmaktır. Çevre birimleri bu uca bakmadan adreslenirse memory mapped I/O, bakarak adreslenirse isolated I/O olur.

<!-- BELİRSİZ: Hocanın bu karşılaştırmada kullandığı MOV örneğinin tam yazımı altyazıda net değil (00:56:27-00:56:58); "100H değil 10H olsun" düzeltmesi geçiyor. -->

### 6.2 Isolated I/O

Isolated I/O'da toplam 1 MB'lık hafıza alanı ile 64 KB'lık G/Ç alanı ayrı ayrı kullanılır. Ekrandaki özellikler (ekrandan, 01:00:00):

- Hafıza uzayının tamamı hafıza birimleri için kullanılabilir; hafıza uzayında G/Ç için yer ayrılmamıştır.
- G/Ç için daha hızlı olan özel komutlar (`IN`, `OUT`) kullanılabilir ve anlamlı sonuç üretir.
- G/Ç için daha basit, yalnız G/Ç birimlerine özel adres çözümleme devreleri kurulabilir.

Bu yöntemde $M/\overline{IO}$ adres çözümlemeye katıldığı için adres çözümleme devresi bir adım daha karmaşıktır.

### 6.3 Memory mapped I/O

Memory mapped I/O'da tek bir uzay vardır. Toplam kapasitesi 1 MB'tır ve düşük anlamlı 64 KB'lık kısmı içinde bir G/Ç bölgesi tanımlanır; kalan kısım hafızaya ayrılır. Hafıza ve G/Ç iç içe girmiştir. Özellikleri:

- Hafıza ve G/Ç için iki ayrı komuta gerek yoktur; yalnız `MOV` komutlarıyla hem hafıza hem G/Ç işlemleri yapılabilir.
- Hafıza ve G/Ç işlemlerini ayıran fiziksel uçlara gerek yoktur.
- $M/\overline{IO}$ adres çözümlemeye katılmadığı için adres çözümleme devresi daha basittir.

Hoca, bunu "tasarım olarak" anlattığını, 8086'nın bunu desteklediğini söylemediğini ayrıca belirtti.

> **Ders sonrası not:** Hoca memory mapped I/O'yu anlatırken "hem giriş çıkış işlemleri hem de in-out işlemleri" dedi (01:00:13); kastedilen hem hafıza hem G/Ç işlemleridir.

## 7. Düğme arayüzü

### 7.1 Düğme tipleri

Düğmeler (butonlar) fiziksel olarak iki tiptedir:

- Momentary (anlık): kapı zili gibidir; basılı tutulduğu sürece kapalıdır, bırakılınca kendisi geri döner.
- Latched: basınca kapanır, ters yönde basınca açılır; hangi duruma basıldıysa o durumu korur.

Tasarımda hangisiyle çalışıldığı yapılacak tasarımı belirler; bu derste herhangi biriyle çalışıldığı varsayılabilir.

### 7.2 İki temel kural

Düğme arayüzü basit bir giriş arayüzüdür: dış dünyadan mikroişlemciye veri aktarır. Düğme basıldığında ve basılmadığında ucunda oluşan lojik seviyeler tasarım ve kodlama açısından çok önemlidir. Ayrıca momentary düğmelerin içinde yay vardır ve bu yay kontak gürültüsü oluşturur; tasarım buna karşı yazılımsal ya da donanımsal önlem içermelidir (Bölüm 8).

Devre tasarımı için iki kural vardır:

1. Düğmeye basıldığında ve bırakıldığında uçta anlamlı ve birbirinden farklı lojik seviyeler oluşmalıdır. Basınca bir lojik değer üretip bırakınca boşta (float) kalan bir devre istenen devre değildir.
2. Düğmeye basıldığında ya da bırakıldığında besleme ile toprak kısa devre olmamalıdır.

### 7.3 Altı aday devrenin incelenmesi

Ekranda altı aday devre vardır (ekrandan, 01:05:00). Koyu noktalar mikroişlemciye ya da arayüze bağlanacak uçtur; üçgenler besleme gerilimi (5 V), diğer semboller toprak (0 V) gösterir.

- Devre 1 (besleme → düğme → uç): Basınca uçta lojik 1 görülür, bu iyidir. Bırakınca uçta hiçbir lojik seviye yoktur, uç boşta kalır; 0 olması garanti değildir. Geçersiz.
- Devre 2 (toprak → düğme → uç): Basınca lojik 0, bırakınca boşta. Geçersiz.
- Devre 3 (besleme → düğme → uç, uç doğrudan toprağa bağlı): Basılı değilken uç lojik 0'dır; ama basınca 5 V ile toprak kısa devre olur ve kaynak yanar. Geçersiz.
- Devre 4 (toprak → düğme → uç, uç doğrudan beslemeye bağlı): Basılı değilken lojik 1; basınca yine 5 V ile toprak kısa devre olur. Geçersiz.

Tahtada ilk dört devrenin üzeri çizilmiş ve R2'li devrenin yanına "düğme basılı değilken lojik 0" yazılmıştır (ekrandan, 01:10:00). Son iki devre geçerli düğme arayüzleridir.

### 7.4 Geçerli devreler: dirençli bağlantı

Analizde ucun bağlandığı mikroişlemcinin içeri doğru çok küçük, hatta sıfır akım çektiği varsayılır; böylece uçta oluşan gerilim mikroişlemci tarafından düşürülmez.

**R2'li devre (besleme → düğme → uç, uç → R2 = 10 kΩ → toprak):**

- Düğme basılı değilken devre yalnız direnç ve topraktan ibarettir. Ucun içinden akım akmadığı için direnç üzerinde gerilim düşmez; uçta 0 V, yani lojik 0 görülür.
- Düğme basılıyken uç doğrudan 5 V'a bağlıdır; lojik 1 görülür, bu kesindir.
- Kısa devre olur mu? Bir öğrenciye soruldu. Hayır: 5 V'un tamamı direnç üzerinde düşer. Akım hesabı (verilen: 5 V, 10 kΩ):

$$I = \frac{5\,V}{10\,k\Omega} = 0{,}5\,mA, \qquad V_R = 0{,}5\,mA \cdot 10\,k\Omega = 5\,V$$

> **Ders sonrası not:** Hoca hesabı yaparken önce 100 µA, sonra 2 mA dedi, öğrencilerle birlikte 0,5 mA olarak düzeltti (01:11:06-01:12:08). Doğrusu 0,5 mA'dir.

Bu devrede yoklama (polling) mantığıyla uç sürekli okunur: "uç 1'e çıktı mı? Hayır. Tekrar oku..." Uç 1'e çıktığında düğmeye basıldığı anlaşılır.

**R1'li devre (toprak → düğme → uç, uç → R1 = 10 kΩ → besleme):**

- Düğme basılı değilken akım akmadığı için direnç üzerinde gerilim düşmez, uçta 5 V, yani lojik 1 görülür.
- Düğme basılıyken uç doğrudan toprağa bağlıdır; lojik 0 görülür, bu kesindir. 5 V'un tamamı yine direnç üzerinde harcanır, kısa devre oluşmaz.

Yoklamada bu kez "uç 0'a düştü mü?" diye okunur; 0'a düştüğünde düğmeye basılmıştır.

## 8. Kontak gürültüsü

Kontak gürültüsü (contact bounce), düğmelerin içindeki yaylı ve metalik yapıların birbirine dokunup çekilmesinden doğan bir gürültüdür. Düğmeye basınca beklenen, uç seviyesinin bir kez lojik 0'a düşüp orada kalmasıdır. Gerçekte ise geçiş sırasında seviye birçok kez gidip gelir; sanki düğme yüzlerce kez açılıp kapanmış gibi bir etki oluşur. Ekranda R1'li devre ile "Düğme t anında kapanırsa" başlıklı, geçişte salınım gösteren bir dalga şekli ve altında beklenen temiz geçiş çizilmiştir (ekrandan, 01:15:00).

Ekrandaki maddeler: kontak gürültüsünü gidermek için yazılımsal veya donanımsal çözümler uygulanmalıdır; yazılımsal olarak ilk değişim yakalandıktan sonra belirli süre aktif bekleme yapılıp uç tekrar kontrol edilir (ekrandan, 01:15:00).

### 8.1 Yazılımsal çözüm

Seviyenin değiştiği ilk anda belirli bir süre boş bir döngüde beklenir, sonra uç tekrar örneklenir. İki örneklemede de lojik 0 görülmüşse tuşa basıldı kabul edilir. İlk örneklemeden ikinciye kadar geçen süre, düğmenin fiziksel yapısı dikkate alınarak yeterince uzun olmalıdır; amaç ikinci okumanın gürültünün bittiği bir ana denk gelmesidir.

Bu yapılmaz ve uç çok hızlı kontrol edilirse "basıldı, bırakıldı, basıldı, bırakıldı..." gibi okunur, oysa tuşa bir kez basılmıştır.

### 8.2 Donanımsal çözüm

Donanımda debounce switch denilen yapı kullanılır. Bu aslında bir flip-flop yapısıdır: tuş basılırken ve bırakılırken oluşan kontak gürültüleri flip-flop'tan geçirilince Q çıkışında temiz bir geçiş elde edilir. Yüz yüze eğitimde kullanılan lojik deney setlerinde bu yapı özel bir switch grubu olarak bulunur.

## 9. LED arayüzü

### 9.1 LED ve iki kural

Düğmeler bir giriş birimiydi: tuşa basılır ve mikroişlemcinin buna göre bir işlev yapması beklenir. LED'ler ise mikroişlemcinin durum ve bildirimlerini dış dünyaya aktaran ışık lambalarıdır; çıkış birimidir. LED (Light Emitting Diode) diyot temelli bir elemandır; üzerinden belirli bir gerilim ve akım geçince ışık üretir. Sembolü, diyot sembolüne iki ok eklenerek çizilir. Anot (A) ve katot (K) uçları tanımlıdır; "artıdan anot" diye hatırlanabilir (ekrandan, 01:20:00, slaytın üstünde A ve K işaretli LED sembolü).

İki kural vardır:

1. LED bir diyot olduğu için yalnız doğru yönde kutuplandığında ışık verir: anot ile katot arasında pozitif gerilim farkı gerekir.
2. Veri sayfasındaki en büyük akım aşılmamalıdır. Uygun akım ve gerilimle LED en parlak ve en uzun ömürlü çalışır; fazlası LED'i kısa ömürlü yapar, kısa sürede yanabilir.

Ekrandaki devre verileri (ekrandan, 01:20:00):

- Uç 2,4 V, 0,1 mA verebilir.
- Transistör Si, $\beta = 100$.
- LED 2 V, 10 mA ile en parlak.

Bu veriler direnç hesabı içindir; bu kayıtta direnç değerleri hesaplanmadı.

Koyu uç mikroişlemciye ya da çevre birimine bağlıdır. Bu uca `OUT` ile istenen zaman lojik 0 (0 V) ya da lojik 1 (5 V) verilebilir. 8086 TTL lojiği destekler; uçta 0 V ya da 5 V dışında bir değer oluşturulamaz. Besleme gerilimleri de 5 V'tur.

### 9.2 D1: dirençsiz bağlantı

D1'de uç → LED (anot uçta) → toprak bağlantısı vardır. Uca 5 V verilirse LED ışık verir (tahtada uçtaki "0V" çizilip "5V" yazılmıştır, ekrandan, 01:25:00). Hoca bunun denenebileceğini anlattı: bir LED dirençsiz olarak 9 V'luk bir pile ya da 3 V'luk bir kaynağa bağlanırsa ışık verir, hemen patlamaz. Ama LED'in ve tellerin iç direnci çok düşük olduğundan LED'in desteklediğinden çok daha yüksek bir akım geçer ve ömrü kısa olur.

### 9.3 D2: hiç yanmayan bağlantı

D2'de uç → LED (anot uçta) → +5 V bağlantısı vardır. Öğrencilerden "lojik 0'da yanar" cevabı geldi; hoca kuralları hatırlattı. Uca verilebilecek en yüksek değer 5 V'tur, diğer taraf da 5 V'tur. LED'in yanması için anottan katoda pozitif gerilim farkı gerekir; bu bağlantıda bu fark hiçbir zaman oluşmaz, LED asla yanmaz. Tahtada D2'nin üzeri çizilmiştir (ekrandan, 01:25:00).

### 9.4 D3: dirençli doğrudan sürme

D3'te uç → R1 → LED → toprak bağlantısı vardır. Uca lojik 1 (5 V) verilince, direnç uygun hesaplandıysa LED uzun ömürlü yanar. Ama mikroişlemcinin çok sayıda bacağı vardır ve bir uç doğrudan bir eleman sürerken yüksek akım veremez. Uç ya da bağlı çevre birimi LED'i parlak yakacak akımı desteklemeyebilir; bu yüzden D3 sönük yanabilir.

> **Ders sonrası not:** Hoca uçların doğrudan sürmede "100 mA civarında" kaldığını söyledi (01:24:30). Slayttaki veriye göre uç 2,4 V'ta yalnız 0,1 mA verebilir (ekrandan, 01:20:00). LED'in en parlak yanması için 10 mA gerektiğine göre, D3'ün sönük yanmasının sebebi bu 0,1 mA'lık sınırdır.

### 9.5 D5: akım çeken bağlantı

D5'te +5 V → R4 → LED → uç bağlantısı vardır; LED, D2 ile aynı konumdadır ama ters çevrilmiştir (anot dirence, katot uca bakar). Bu, bir öğrencinin önerdiği duruma örnektir. Uca lojik 0 verilince LED, direnç uygun hesaplandıysa uzun ömürlü ve parlak yanar; hatta D3'ten daha parlak yanar. Sebep: mikroişlemcinin dış dünyaya akım verme kabiliyeti düşükken, belirli sınırlar içinde kalmak şartıyla dış dünyadan akım çekme kabiliyeti çok daha geniştir.

D3 ile D5 arasındaki fark şudur: D3'te akımı mikroişlemci ucu oluşturur ve uç yüksek akım veremediği için LED düşük parlaklıkta yanar. D5'te LED dışarıdaki beslemeden sürülür ve akım mikroişlemcinin içine doğru akar.

### 9.6 D4: transistörle sürme

Mikroişlemciden sürerek bir LED'i parlak ve uzun ömürlü yakmak isteniyorsa kurulacak devre D4'tür. Uç → R3 → Q1'in tabanı; +5 V → D4 → R2 → Q1'in kollektörü; emiter topraktadır. Mikroişlemciden gelen düşük akım transistörü açıp kapatır, LED ise kaynaktan sürülür.

**Soru:** Q1 NPN tipi bir BJT ise LED'in yanması için uçta hangi lojik seviye olmalı? **Cevap:** Lojik 1. Taban ile emiter arasında pozitif gerilim farkı olunca transistör iletime geçer; bu da +5 V → LED → direnç → toprak yolunu tamamlar.

Toparlarsak: uygun devre tasarımıyla kontrol ucuna lojik 1 vererek yanan LED'ler de (D3, D4), lojik 0 vererek yanan LED'ler de (D5) vardır. Düğmelerde de basılınca 0, bırakılınca 1 veren tasarımlar ya da tersi mümkündür.

> **Hocanın vurgusu:** Devre şeması anlaşılarak hangi kontrol işaretinin beklendiği belirlenmeli ve kod buna göre yazılmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:45:36)

`IN AL, DX` komutu geçerli midir? `MOV BL, AX` ile karşılaştırın.

Çözüm (derste verildi): `MOV BL, AX` tip hatası verir, çünkü 16 bitlik AX değeri 8 bitlik BL'ye atılamaz. `IN AL, DX` ise geçerlidir ve çalışır: DX burada veri tutmaz, 16 bitle ifade edilen bir port adresidir. O adresteki 1 baytlık veri alınıp AL'ye aktarılır. Hoca bunun sınavlarda sormayı sevdiği bir soru olduğunu söyledi.

**Soru 2** (ekrandan, 00:35:00 ve 00:45:00)

`IN AX, 11H` ve `IN AX, 10H` komutlarında AL ve AH'ye hangi adreslerin içeriği, hangi veri uçlarından gelir? Her biri kaç okuma-yazma çevriminde biter?

Çözüm (derste verildi):

- `IN AX, 11H`: `AX <-- [11H:12H]`. 11H (`0001 0001B`) tek adres: D8-D15 üzerinden AL'ye. 12H (`0001 0010B`) çift adres ve farklı satırda: D0-D7 üzerinden AH'ye. 2 okuma-yazma çevrimi.
- `IN AX, 10H`: `AX <-- [10H, 11H]`. 10H çift adres: D0-D7 üzerinden AL'ye; 11H aynı satırda: D8-D15 üzerinden AH'ye. A0 = 0 ve $\overline{BHE} = 0$ birlikte; 1 okuma-yazma çevrimi.

**Soru 3** (derste sözlü, 00:48:31; ekrandan, 00:50:00)

8086'nın G/Ç uzayının en büyük kapasitesi nedir, neden? Hafıza ve G/Ç uzayı için kapasite ve uygun arayüz nedir?

Çözüm (derste verildi): Port adresi en fazla 16 bitlik DX ile verilebildiği için G/Ç uzayı $2^{16} = 64\text{K}$ göz, yani 64K×8 = 64 KB'tır; uygun arayüz 32K×16'dır. Hafıza 20 adres ucu nedeniyle 1M×8'dir; uygun arayüz 512K×16'dır.

**Soru 4** (derste sözlü, 01:05:01; ekrandan, 01:05:00)

Ekrandaki altı düğme devresinden hangileri geçerli bir düğme arayüzüdür? Geçersizlerin sorunu nedir?

Çözüm (derste verildi): Yalnız besleme ya da yalnız toprağa bağlı düğmeli iki devre bırakılınca uç boşta kaldığı için; ucu doğrudan toprağa ya da beslemeye bağlı iki devre basılınca kısa devre yaptığı için geçersizdir. 10 kΩ dirençli iki devre geçerlidir: R2'li devrede basılı değilken lojik 0, basılıyken lojik 1; R1'li devrede basılı değilken lojik 1, basılıyken lojik 0. Basılıyken dirençten $5\,V/10\,k\Omega = 0{,}5\,mA$ akar.

**Soru 5** (derste sözlü, 01:19:59-01:27:48; ekrandan, 01:20:00)

Ekrandaki D1-D5 LED devreleri yanar mı, nasıl yanar?

Çözüm (derste verildi):

- D1: uca 5 V verilince yanar, ama dirençsiz olduğu için ömrü kısa olur.
- D2: hiç yanmaz; uca verilebilecek en yüksek gerilim 5 V, diğer uç da 5 V.
- D3: uca lojik 1 verilince uzun ömürlü ama sönük yanar (uç az akım verir).
- D5: uca lojik 0 verilince uzun ömürlü ve parlak yanar (akım uca doğru çekilir).
- D4 (NPN BJT): uca lojik 1 verilince transistör iletime geçer, LED kaynaktan sürülerek yanar.

## Dersin Toparlaması

Bu derste çevre birimlerinin hafıza birimlerinden farkı (dar adres bölgesi, adres ucu sayısıyla belirlenen alan) ve 8086'nın sekiz `IN`/`OUT` varyasyonu görüldü. Port adresinin 8 bite sığdığında komuta gömüldüğü, sığmadığında DX ile verildiği; verinin yalnız AL ya da AX'te olabileceği öğrenildi. Çift adresli işlemlerin D0-D7 ve A0 ile, tek adresli işlemlerin D8-D15 ve $\overline{BHE}$ ile yürüdüğü, tek adresten 16 bit okumanın iki çevrim sürdüğü ve bunun hafıza ile G/Ç uzayının 512K×16 ve 32K×16 olarak çift/tek bloklara bölünmesinden kaynaklandığı açıklandı. $M/\overline{IO}$ ucunun adres çözümlemede kullanılmasına göre isolated I/O ile memory mapped I/O ayrıldı.

Dersin ikinci yarısında basit arayüz devreleri işlendi: düğmenin iki kuralı (iki durumda farklı ve anlamlı seviye, kısa devre yok), pull-down ve pull-up dirençli geçerli devreler, kontak gürültüsünün yazılım ve donanımla giderilmesi; LED'in kutuplama ve akım kuralları ile beş LED bağlantısının karşılaştırması. Planlanan adres çözümleme ve çevre birimi kontrolü başlıklarına bu kayıtta geçilemedi. Sonraki oturumun konusu 8255 olarak duyuruldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
