# Ders 22 Genişletilmiş Notu: Bilgisayar Mimarisi, Haberleşme ve İşletim Sistemlerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sözlük Uygulaması Üzerine Sorular
- 2. Bilgisayar Mimarisi ve CPU'nun Birimleri
- 3. Makine Dili, Komut Seti, RISC ve CISC
- 4. Temel İşlemler ve Komutun Yapısı
- 5. Makine Döngüsü
- 6. İşlemci Hızı ve Bilgisayarların Karşılaştırılması
- 7. Bilgisayar ile Cihazlar Arasındaki Haberleşme
- 8. Paralel ve Seri Haberleşme
- 9. Haberleşme Hızı ve Bant Genişliği
- 10. Kablolu Haberleşme ve Portlar
- 11. Protokoller
- 12. Kablosuz Haberleşme Türleri
- 13. RISC Üzerine Bir Soru ve İşletim Sisteminin Tanımı
- 14. Toplu, Etkileşimli ve Gerçek Zamanlı İşleme
- 15. Zaman Paylaşımı, Çoklu Programlama ve Çoklu Görev
- 16. Gömülü Sistemler
- 17. İşletim Sistemi Mimarisi

## 1. Sözlük Uygulaması Üzerine Sorular

Ders, öğrencilerin yazdığı sözlük uygulamasıyla ilgili sorularla başladı. Bu sorular karakter dizileriyle çalışırken karşılaşılan genel durumları gösterdiği için burada özetleniyor.

### 1.1 Küçük ve Büyük Harf Karışık Girilirse

Hoca, kelimeler küçük ve büyük harf karışık alınsaydı ne yapılabileceğini sordu. Bir öğrenci, ASCII tablosuna göre harfin büyük harf aralığında mı küçük harf aralığında mı olduğunu `if` ile kontrol edeceğini söyledi. Hoca kontrolün gerekli olduğunu kabul etti, ama asıl vurgulamak istediği nokta başkaydı: Bu tür problemlerde genelde kullanıcının nasıl girdiğinden bağımsız olarak, bilgi alındıktan sonra hepsi küçük harfe ya da büyük harfe çevrilir. Sözlük de tek biçimde saklanır. Büyük harfle saklanıyorsa hep büyük, küçük harfle saklanıyorsa hep küçük harfle saklanır.

### 1.2 Aynı Kelime İki Kez Girilirse

İkinci soru, aynı kelimenin iki kez girilmesi durumunda ne olacağıydı. Bir öğrenci, kendi çözümünde aynı kelimeden iki tanesinin listede alt alta, sıralı biçimde durduğunu söyledi. Hoca bunun gerçek bir uygulamada kabul edilmeyeceğini belirtti: Bir sözlükte iki tane aynı kelime olmaz. Yapılması gereken, kelimeyi eklemeden önce var olup olmadığını kontrol etmek ve varsa kullanıcıya kelimenin hâlihazırda bulunduğunu bildiren bir mesaj vermektir.

### 1.3 `string.h` Olmadan Kelime Uzunluğu

**Soru:** `string.h` kullanılmayacaksa, kelime ararken `strlen` ile döngü kurmak yerine ne yapılabilir?

**Cevap:** Her karakter grubunun sonunda null karakteri bulunur. `while` ile null karakterini görene kadar ilerlenirse kelimenin uzunluğu bulunmuş olur.

Hoca, `strlen` ve `strcmp` gibi hazır fonksiyonların neden kullandırılmadığını iki gerekçeyle açıkladı. Birincisi, bu işin nasıl yapıldığını kendiniz denemeniz gerekir. İkincisi, bu fonksiyonları ileride zaten kullanacaksınız: Sonraki dönemlerde onlarla daha çok çalışılacaktır. Amaç işi zorlaştırmak değil, öğrenmeyi sağlamaktır.

### 1.4 Arama Adımı Sayısı

**Soru:** Aynı harfle başlayan iki kelime olsun. İkinci sıradaki kelimeyi ararsak arama adımı sayısı iki olmalı, değil mi?

**Cevap:** Evet. İlk sıradaki kelime aranırsa adım sayısı bir, ikinci sıradaki aranırsa iki olur.

## 2. Bilgisayar Mimarisi ve CPU'nun Birimleri

### 2.1 Mimari Ne Demektir?

Konuya geçerken hoca, "bilgisayar mimarisi" (computer architecture) denince ne anlaşıldığını sordu. Bir öğrenci farklı ünitelerden bir bilgisayarın oluşmasını, örnek olarak da işlemci, GPU ve belleği söyledi. Hoca bunu şöyle tamamladı: Bilgisayarın işini yapmasını sağlayan bütün birimler bilgisayar mimarisinin birer parçasıdır. Bunların başında CPU (Central Processing Unit) gelir.

Mobil cihazlarda ve gömülü sistemlerde (embedded systems) işlemci birimine ayrı bir ad verilir: mikroişlemci (microprocessor). Bu ad, boyutlarının çok daha küçük olması ve özel tasarımlarından gelir.

Ana bellek (main memory) ve anakart (motherboard) da mimarinin parçalarıdır. Anakart, bütün bu parçaların birbiriyle konuşmasını sağladığı için hocanın "çok önemli bir birim" dediği parçadır.

### 2.2 CPU'nun Birimleri

Hoca CPU'nun birimlerini sordu. Öğrencilerden transistör cevabı geldi. Hoca, transistörlerin en küçük yapı taşı olduğunu ama daha üst seviyedeki birimleri sorduğunu söyledi. Üç birim şunlardır:

- Kontrol birimi (control unit)
- Aritmetik mantık birimi (arithmetic logic unit)
- Register birimi: Hoca önce "memory unit" dedi, sonra buna register unit dediğimizi belirtti.

Bir öğrencinin "çekirdek" cevabını hoca, işletim sisteminden bahsetmediğimiz gerekçesiyle kabul etmedi.

> **Ders sonrası not:** Hoca "çekirdek" cevabını işletim sistemiyle ilişkilendirerek reddetti; büyük olasılıkla burada iki ayrı kavram karışmıştır. İşletim sisteminin çekirdeği (kernel) bir yazılımdır, işlemci çekirdeği (core) ise donanımdır. Hoca da Bölüm 6'da işlemcilerin çekirdek sayısından söz etti. Sorunun cevabı olan üç birim bundan etkilenmez.

### 2.3 Bellek Hiyerarşisi ve Register Türleri

Register, veriyi saklamak için kullanılan, en küçük ve veriye en hızlı ulaşılan birimdir. Register'dan sonraki sıra şöyledir:

- Register
- Cache: kendi içinde seviyeleri vardır
- Ana bellek (main memory)
- İkincil bellek (secondary memory)

Bu sırada ilerledikçe kapasite artar, maliyet azalır. Register, birim başına en yüksek maliyete sahip bellek bölgesidir.

Register'lar ikiye ayrılır. Genel amaçlı register'larda (general purpose register) işlenecek veri saklanır. Özel amaçlı register'larda (special purpose register) ise programın akışıyla ve komutlarla (instruction) ilgili bilgiler saklanır.

## 3. Makine Dili, Komut Seti, RISC ve CISC

### 3.1 Makine Dili ve Komut Seti

Makine dili (machine language), bütün işlerin sıfır ve birlerden oluşan kombinasyonlarla yaptırıldığı dildir. Her CPU'nun bir komut seti (instruction set) vardır ve o CPU'ya yaptırılabilecek bütün işler bu sette tanımlıdır. Toplama, çıkarma, çarpma, bir bilgiyi bir yerden bir yere taşıma, rotate ve shift gibi aritmetik ve mantık işleri burada yer alır. Bir koşula göre programın hangi noktadan devam edeceğini belirleyen komutlar da bu settedir.

### 3.2 İki Temel Yaklaşım

Hoca temelde iki işlemci mimarisi olduğunu söyleyip bunları sordu. Bir öğrenci 8086 mimarisini önerdi.

<!-- BELİRSİZ: Altyazıda "80-86" geçiyor; 8086 olarak okundu. -->

Hoca, özele girilirse çok daha fazla mimari sayılabileceğini, kendisinin ise konsept olarak iki bakış açısından söz ettiğini açıkladı. Söz konusu mimarilerin hepsi bu iki yaklaşımın altında yer alır:

- **RISC (Reduced Instruction Set Computer):** Komutlar genelleştirilmiş ve basittir. Hoca, genelleştirme yapıldığında komutların kendiliğinden basitleştiğini söyledi. Karmaşık bir iş yapılacaksa bu basit komutların kombinasyonları oluşturulur.
- **CISC (Complex Instruction Set Computer):** Basit işler için basit komutlar yine vardır. Ama bu yaklaşım şöyle der: Karmaşık bir işi basit komutların kombinasyonundan yapmak yerine, o iş için komut setine ayrı bir komut tanımlarım. Bu yüzden CISC mimarisinde komut sayısı doğal olarak daha fazladır.

### 3.3 Biri Diğerinden Üstün mü?

Hoca, birinin diğerinden net biçimde avantajlı olup olmadığını sordu. Öğrencilerden gelen cevaplar şöyleydi: İkisinin de kendine göre avantajları vardır. RISC daha hızlı tasarlanır ve çalışır ama çok karmaşık programlara uygun değildir. RISC daha genel işlere uygunken CISC daha özel işleri daha hızlı yapar. Hoca bu sonuncusuna "kısmen" dedi. RISC'in insan diline daha yakın olduğu ve kodunun daha hızlı yazıldığı yönündeki yorumu ise doğru bulmadı.

Hocanın verdiği cevap şöyle özetlenebilir:

| | RISC | CISC |
|---|---|---|
| **Komutlar** | Genel, basit | Karmaşık işler için ayrı komutlar |
| **Enerji** | Verimli | Daha çok tüketir |
| **Performans** | Enerji verimliliği öne çıkar | Özellikle karmaşık işlerde daha performanslı |
| **Örnek** | ARM işlemci serisi, cep telefonları | Intel, PC ortamları |

Karmaşık komutlar genelde çok daha yüksek enerji tükettiği için, genel komutlar kullanan RISC işlemcileri enerjiyi verimli kullanır. Bu nedenle ARM serisi RISC mimarisini tercih eder ve cep telefonu gibi enerji kısıtı olan cihazlarda çok tercih edilir. CISC ise daha çok Intel'in tercih ettiği, PC ortamlarında kullanılan, performans odaklı bir mimaridir. Karmaşık bir işi birden fazla komutu arka arkaya çalıştırmak yerine tek komutta yapmak performans sağlar.

> **Hocanın vurgusu:** Seçim yapılacak işe bağlıdır. Performans arıyorsanız ve karmaşık işlerle uğraşıyorsanız CISC, enerji verimli bir tasarım istiyorsanız RISC öne çıkar.

## 4. Temel İşlemler ve Komutun Yapısı

### 4.1 Temel İşlemler (Elementary Operations)

Hoca, şimdiye kadar öğrenilen aritmetik ve mantık işlemlerini sordu. Bir öğrenci toplama, çıkarma, çarpma, bölme, mod ve karşılaştırma operatörlerini saydı. Hoca ise komut setlerindeki temel işlemleri şöyle sıraladı:

- AND, OR, XOR ve bir öğrencinin hatırlattığı NOT: Bu mantık kapıları (logic gate) toplama ve çıkarmada da kullanılır.
- Store
- Shift
- Rotate
- Jump

Bu işlemler operandlarla çalışır. Örneğin AND yapacaksanız iki operanda, NOT yapacaksanız bir operanda ihtiyacınız vardır.

### 4.2 Shift (Kaydırma)

Bir öğrenci shift işlemini bitleri sağdan ya da soldan kaydırmak olarak tanımladı. Hocanın örneği `0111` idi.

<!-- BELİRSİZ: Altyazıda başlangıç değeri "0, 1, 1" ve "011" diye geçiyor, bir bit düşmüş. Hocanın söylediği dört sonuç yalnız 0111 ile tutuyor (python ile doğrulandı). -->

- Sola kaydırma: `0111` → `1110`
- Sağa kaydırma: `0111` → `0011`

Hoca, bunun sayıyı ikiyle çarpmak ve ikiye bölmek anlamına geldiğini söyledi. Örnekte $0111_2 = 7$ alınırsa sola kaydırmada $7 \times 2 = 14 = 1110_2$, sağa kaydırmada kalan atılarak $7 / 2 \rightarrow 3 = 0011_2$ bulunur (ara adım eklendi). Hoca, gerçekte 4 bitle çalışılmadığını, genelde 8 ve 8'in katı bitlerle çalışıldığını da ekledi.

### 4.3 Rotate (Döndürme)

Rotate işleminde bitler yine kayar, ama uçtan çıkan bit diğer uçtan geri girer (ara adım eklendi). Aynı `0111` için:

- Sağa döndürme: `0111` → `1011`. En sağdaki `1` en sola geçer.
- Sola döndürme: `0111` → `1110`. En soldaki `0` en sağa geçer.

Sola döndürme bu örnekte sola kaydırmayla aynı sonucu verir, çünkü uçtan çıkan bit `0`'dır. Sağa işlemlerde ise fark görülür: Kaydırma `0011`, döndürme `1011` verir (ara adım eklendi).

### 4.4 Store

Store işlemi, register'daki verinin alınıp belleğe kaydedilmesini gerçekleştirir.

### 4.5 İşlem Kodu ve Operand

Komut setinde tanımlı bir komutun iki kısmı vardır. İşlem kodu (operation code, opcode) ne iş yapılacağını, operand ise bu işin hangi veri üzerinde yapılacağını söyler.

Hocanın örneğinde komutun başındaki `0011` kısmı işlem kodu, kalanı operanddır. Diyelim ki `0011` işlem kodu store anlamına gelsin. Hoca bunu onaltılık gösterimde `35A7` komutu üzerinden anlattı. Komut işlemciye geldiğinde işlemci önce `3`'e bakar ve bunun store olduğunu anlar. Kalan `5A7` ise bu işlemin üzerinde yapılacağı bilgidir. Onaltılık rakamlar ikiliye çevrilirse (ara adım eklendi):

$$
\texttt{35A7}_{16} = \underbrace{0011}_{\text{opcode}}\ \underbrace{0101\ 1010\ 0111}_{\text{operand}}
$$

<!-- BELİRSİZ: Altyazıda operand sözlü olarak "010101011", işlem kodu bir yerde "001" diye geçiyor. Hoca ekranda yazıyordu. Bit dizisi burada altyazıdaki 3, 5, A7 değerlerinden kuruldu. -->

İşlemci bu sıfır-bir kombinasyonlarından ne yapması gerektiğini böyle anlar. Her kombinasyonun işlem kodu olarak bir anlamı vardır. Hoca, bunların ezbere bilinmesinin mümkün olmadığını da söyledi.

## 5. Makine Döngüsü

Hoca makine döngüsünü (machine cycle) üç adımlı bir çizimle gösterdi: fetch, decode ve execute. CPU tarafındaki döngü genel olarak böyle gerçekleşir.

- **Fetch:** Bir sonraki komut bellekten alınır ve program sayacı (program counter) bir artırılır. Böylece program, bir sonraki komut neyse o noktaya getirilir.
- **Decode:** Komut register'ındaki (instruction register) bit örüntüsü (bit pattern) çözümlenir, yani ne yapılacağına karar verilir. Çözümlenen, fetch adımında alınan komut bilgisidir.
- **Execute:** İlgili işlem gerçekleştirilir.

<!-- BELİRSİZ: Döngünün çizimi ve ekrana yazılan İngilizce tanımlar altyazıda yalnızca sözlü olarak var. -->

## 6. İşlemci Hızı ve Bilgisayarların Karşılaştırılması

### 6.1 Saat ve Darbe

Hoca, iki bilgisayarın gücünün nasıl karşılaştırılacağını sordu. Bir öğrenci, saniyede bu döngüden kaç işlem geçtiğine bakılabileceğini söyledi. Hoca "işlem geçmesi" ifadesini kullanmamayı önerdi ve şöyle açıkladı: Bilgisayarın bir saati vardır, buna osilatör (oscillator) denir. Saat sürekli darbe (pulse) üretir. Bu darbenin saniyede kaç kez üretildiği, işlemci hızını ifade etmemizi sağlar.

Sonra 1 GHz'in saniyede kaç darbe demek olduğu soruldu. Hoca 1 kHz için $2^{10}$, 1 MHz için $2^{20}$, 1 GHz için $2^{30}$ değerlerini söyledi. Bir öğrenci "milyar" dedi. Hoca bunu onayladı ve 1 GHz'in saniyede $2^{30}$ darbe demek olduğunu söyledi.

> **Ders sonrası not:** Hoca frekans için $2^{10}$, $2^{20}$ ve $2^{30}$ dedi; doğrusu büyük olasılıkla ondalık öneklerdir: 1 kHz = $10^3$, 1 MHz = $10^6$, 1 GHz = $10^9$ Hz. İkili katlar büyük olasılıkla bellek boyutu için kullanılır. Hoca da $2^{10}$ değerini önce kilobyte için söyledi. Fark küçüktür: $2^{30} = 1\,073\,741\,824$, yani $10^9$'un yaklaşık 1,07 katıdır. Bu yüzden "saniyede yaklaşık bir milyar darbe" sonucu değişmez.

### 6.2 GHz Tek Başına Yeterli mi?

Hoca şu soruyu sordu: Biri 1 GHz, diğeri 2 GHz olan iki işlemci varsa, 2 GHz olan daha hızlıdır diyebilir miyiz? Bir öğrenci düz mantıkla bunu söyleyebilmemiz gerektiğini belirtti. Hoca da düz mantıkla öyle olduğunu kabul etti, ama doğrudan bu sonuca varılamayacağını açıkladı.

Sebep, işlemci mimarilerindeki tasarım farklarıdır. Bir komutun bir işlemcide kaç saat döngüsünde (clock cycle), diğerinde kaç saat döngüsünde çalıştığını bilmiyoruz. Örneğin toplama komutu birinde 3, diğerinde 5 döngüde gerçekleşebilir. Hoca, 1,4 GHz ile 1,6 GHz gibi birbirine yakın değerleri düşünmemizi istedi. Intel ve AMD gibi farklı işlemci aileleri de vardır: Bir Intel işlemcinin hertz değeri daha yüksek olsa bile AMD'ninki daha performanslı çalışabilir. İşlemcinin hangi cihaz üzerinde çalıştığı da önemlidir.

Bir öğrenci, aynı mimaride bile çekirdek sayısı gibi etkenlerin performansı değiştirebileceğini ekledi. Hoca bunu genişletti: Fark yalnız ailelerden gelmez. Aynı ailede, örneğin Intel'de de 8086, 80386, 80486 diye devam eden farklı mimariler vardır ve bunların komut setleri de farklılık gösterir. Çekirdek sayıları da önemlidir.

<!-- BELİRSİZ: Altyazıda "86 ile başlıyor, 80, 386, 80, 486" geçiyor; 8086, 80386, 80486 olarak okundu. -->

> **Hocanın vurgusu:** GHz üzerinden yapılan yorum yalnızca genel bir fikir verir. Bir bilgisayarın daha hızlı ya da daha yavaş olduğu GHz değerine bakılarak net biçimde söylenemez.

### 6.3 Benchmark

Net karşılaştırma için bir öğrencinin önerdiği yol kullanılır: Bilgisayarları aynı teste sokmak, aynı işlemleri yaptırıp süreleri karşılaştırmak. Bunun adı benchmark testidir (benchmarking). İki makineye aynı iş yaptırılır, işlerin tamamlanma süreleri hesaplanır ve böylece iki cihazın performansı hakkında fikir sahibi olunur.

> **Hocanın vurgusu:** Bu "çok çok önemli": Bir konuda daha iyi performans gösteren işlemci, başka bir işi yaparken diğerine göre daha düşük performans gösterebilir. Bir işlemcinin diğerinden her kalemde üstün olduğu söylenemez. Sonuç yaptırılan işe bağlıdır.

Bunun sebebi, yaptırılan işte belleğe erişmenin ya da GPU kullanmanın gerekebilmesidir. Bunlara bağlı olarak benchmark sonuçlarında sapmalar görülebilir. Yine de genel olarak benchmark testlerinden faydalanılır.

Hoca, öğrencilerin benchmark deneyimlerini sordu. Bir öğrenci, testlerde tek çekirdek ve çok çekirdek performansı, üç boyutlu işleme gibi farklı ölçütler bulunduğunu, kendi gözlemine göre Intel işlemcilerin genelde tek çekirdekte, AMD'lerin çok çekirdekte iyi olduğunu söyledi. Bir diğeri Intel XTU ile thermal throttling olup olmadığına baktığını anlattı. Başka bir öğrenci ise ekran kartının termal macununu değiştirdikten sonra hem sıcaklıkta hem de benchmark skorunda büyük fark gördüğünü aktardı.

### 6.4 Donanım Uyumu

Bir öğrenci, GPU'nun önemli olduğunu bilerek güçlü bir ekran kartı aldığını ama işlemci farkını o dönem bilmediği için yanına eski nesil bir işlemci seçtiğini anlattı. Bu örnekten sonra hoca, donanımın kendi içinde uyumlu olmasının çok önemli olduğunu söyledi. Apple kendi donanımını ve yazılımını birlikte tasarladığı için çok daha performanslı ürünler ortaya koyabilmektedir.

## 7. Bilgisayar ile Cihazlar Arasındaki Haberleşme

Aradan sonra hoca, bir bilgisayarla diğer cihazlar arasındaki haberleşmeyi sağlayan parçanın adını sordu. Bu cihaz bir monitör, disk sürücü, CD sürücü ya da modem olabilir. Parçanın adı denetleyicidir (controller). Hoca, haberleşmenin normalde bir ara birim (intermediary) üzerinden yürütüldüğünü tahtaya İngilizce olarak yazdı.

<!-- BELİRSİZ: Ekrana yazılan İngilizce tanımın tamamı altyazıda net değil ("Communication between a computer and other devices is normally handled ... an intermediary"). -->

Hoca bunu bir şekille gösterdi. Şekilde bir CPU ve birimlerin birbiriyle üzerinden haberleştiği bir bus yapısı vardır. Bus üzerinde CD sürücü, modem, monitör ve disk için birer denetleyici bulunur.

<!-- BELİRSİZ: Şekil yalnızca sözlü olarak anlatılıyor. -->

**Soru:** Bu şekilde haberleşme stili farklı olan hangisidir?

**Cevap:** Ana bellek (main memory). Araya bir denetleyici girmez, CPU ana belleğe doğrudan erişir. Bu da daha hızlı iletişim sağlar.

Hoca bunun gerekçesini şöyle açıkladı: CPU ana belleğe doğrudan adres bazında eriştiği için erişim çok hızlıdır. Denetleyici ise arada bir dönüşüm yapar. Ayrıca denetleyiciler farklı aparatlar ve markalar için ilgili sürücülerin (driver) yüklenmesiyle kullanılabilir. Bütün bunların bir maliyeti vardır. Ana bellekte böyle bir maliyet yoktur. Hoca bu noktada doğrudan bellek erişimini (Direct Memory Access, DMA) hatırlatıp bunun önemli bir performans sağladığını söyledi.

> **Ders sonrası not:** Hoca CPU'nun ana belleğe doğrudan erişimini DMA adıyla andı; DMA büyük olasılıkla başka bir şeydir: Denetleyicinin, veri aktarımı için her adımda CPU'yu aracı etmeden ana belleğe kendisinin erişmesidir. Performans kazancı da büyük olasılıkla CPU'nun bu aktarım sırasında başka işlere dönebilmesinden gelir. CPU'nun adres bazında ana belleğe erişmesi ise DMA'dan ayrı bir konudur.

## 8. Paralel ve Seri Haberleşme

Hoca iki haberleşme tipini sordu: paralel (parallel communication) ve seri (serial communication).

- **Paralel haberleşme:** Bir bilgi aktarılırken bir $t$ anında farklı hatlar (line) üzerinden aynı anda aktarılır.
- **Seri haberleşme:** Bilgi, sinyaller hâlinde aynı hat üzerinden arka arkaya aktarılır.

Paralel haberleşme örneği olarak bir öğrenci, mikrofon ve ses çıkışı tek girişte olan kulaklıkları önerdi. Hoca bunu tercih etmedi, daha net bir örnek olarak yazıcıları (printer) verdi. Seri haberleşme örneği olarak ise bir öğrencinin söylediği SATA disklerden söz edildi. Eskiden paralel diskler de vardı. Paralel haberleşmeye sahip cihazlar yapmak daha maliyetlidir ve daha karmaşık bir haberleşme yolu tasarlamayı gerektirir. Bu yüzden son yıllarda birçok cihaz seri haberleşme kullanır.

Hemen ardından gelen soru, sık yapılan bir karışıklığı gösteriyor.

**Soru:** Paralelde gönderilen şeyleri yazıcı kendisi sıraya koymuyor mu? Paralellikte sıra yok mu?

**Cevap:** Bu iki ayrı şeydir. Bilgisayarın gönderdiği işleri yazıcının kuyruğa (queue) koyması iş bazında bir konudur. Paralel haberleşme ise bir işi yaparken o işe ait bilgilerin gönderilme biçimidir. Örneğin bir satırın bilgileri gönderilirken 8 hat varsa aynı anda 8 bit gönderilebilir. Seride aynı bilgiler aynı hat üzerinden sırayla, arka arkaya gönderilir.

> **Ders sonrası not:** Hoca bu örneğin sonunda "aynı anda 8 tane byte" dedi; doğrusu büyük olasılıkla, kendisinin hemen önce söylediği gibi, 8 hatta aynı anda 8 bittir. Her hat bir anda bir bit taşır.

## 9. Haberleşme Hızı ve Bant Genişliği

### 9.1 Haberleşme Hızının Birimi

Haberleşme söz konusu olduğunda hız ve aktarılan bilgi boyutu önemlidir. Hoca haberleşme hızının (communication rate) birimini sordu. Bir öğrencinin hertz önerisini kabul etmedi. Başka bir öğrenci, SATA'dan hatırladığı "saniyede 6 gigabit" ifadesinden yola çıkarak doğru cevaba ulaştı: bit per second (bps). Genelde kilobit per second (Kbps), megabit per second (Mbps) ve son dönemde gigabit per second (Gbps) konuşulur.

Hoca sonra 8 Kbps'nin neye denk geldiğini sordu.

- Verilen: 8 kilobit per second
- İşlem: 1 byte = 8 bit olduğundan bit cinsinden değer 8'e bölünür: $8 / 8 = 1$
- Sonuç: 8 Kbps = 1 kilobyte per second

> **Hocanın vurgusu:** Bu kısım önemlidir. Bu birim kilobit'tir, kilobyte değildir. Byte olarak ifade etmek istediğinizde sekize bölmeniz gerekir.

**Soru:** Speed test gibi yerlerde gördüğümüz kısaltma bit cinsinden. Saniyede bir kilobyte demek istediğimizde bunun ayırt edici bir kısaltması var mı?

**Cevap:** Hoca ekrana genelde nasıl yazıldığını yazarak gösterdi.

<!-- BELİRSİZ: Hocanın ekrana yazdığı kısaltma altyazıda yok ("Yani genelde şöyle yazar", 01:09:11). -->

> **Ek bilgi (derste anlatılmadı):** Yaygın yazımda büyük olasılıkla küçük `b` bit, büyük `B` byte anlamına gelir. Buna göre Kbps ya da kb/s kilobit per second, KBps ya da KB/s kilobyte per second demektir.

### 9.2 Bant Genişliği

Hoca bant genişliğini (bandwidth) sordu. Bir öğrenci "maksimum veri aktarım hızı", bir başkası "belli bir yol üzerinden gidebilecek en fazla veri miktarı" dedi. Hoca iki cevabı da onayladı: Bant genişliği, teknik olarak o hattın taşıyabileceği en fazla veri miktarını söyler.

Sonra evdeki bağlantılar üzerinden konuştu. Bir öğrenci modeminin 100 megabit olduğunu, hattının ise eve gelen kabloya kadar en fazla 75 verebildiğini aktardı. Hoca burada iki farklı kavram olduğunu vurguladı. Biri, fiziksel hattın taşıyabileceği kapasitedir. Diğeri, kullanılan cihazın sağlayabildiği bilgi akış hızıdır. Bu da ayrı bir bant genişliği anlamına gelir. Yani tek bir bant genişliğinden söz edilmez. Hangi cihaz ya da hat için konuştuğumuza bağlıdır.

## 10. Kablolu Haberleşme ve Portlar

### 10.1 Kablolu ve Kablosuz

Haberleşmede temelde iki tip vardır: kablolu (wired communication) ve kablosuz (wireless communication). Kablolu haberleşme denince bir öğrencinin aklına LAN kablosuyla yapılan yerel ağ haberleşmesi geldi. Hoca, yerel ağın (Local Area Network) yanında metropol ağ (Metropolitan Area Network) ve geniş ağ (Wide Area Network) da olduğunu, bunların muhtemelen ileride görüleceğini söyledi. Bilgisayara bağlanan bir disk de kablolu haberleşme yapar.

Bir öğrenci, bağlanan diskin seri haberleştiğini söyledi. Hoca bunu doğruladı ve haberleşmenin USB portu üzerinden gerçekleştiğini ekledi.

### 10.2 Fiziksel Portlar

Portlar giriş-çıkış kapılarıdır. Cihazlar birbirine bu portlar üzerinden bağlanır. Öğrencilerin saydığı fiziksel portlar şunlardı: M.2, USB, HDMI, kulaklık girişi, internet bağlantı girişi, şarj girişi ve artık çok kullanılmasa da eski görüntü portları.

<!-- BELİRSİZ: Altyazıda "DGA port" geçiyor. VGA ya da DVI olabilir. Kısa notta ikisi de yazılı, altyazıda hangisi olduğu net değil. -->

Bir öğrenci kendi makinesinde hâlâ 9 pinli ve 25 pinli port bulunduğunu söyledi. Hoca, geçenlerde çıkardığı Commodore 64'ün kocaman 25 pinini anarak o dönemin pinlerinin tek tek sayılabildiğini anlattı.

<!-- BELİRSİZ: Altyazıda "9 bin, 25 bin" geçiyor; pin olarak okundu. -->

M.2 sorulduğunda hoca bunu kullanmadığını ve bilmediğini, bakacağını söyledi. Öğrenciler, bunun ince uzun SSD'leri takmak için kullanılan çok ince bir yuva olduğunu açıkladı.

> **Ek bilgi (derste anlatılmadı):** M.2 büyük olasılıkla anakart üzerindeki küçük bir bağlantı yuvası standardıdır. Bu yuvaya takılan SSD'ler, modele göre büyük olasılıkla SATA ya da NVMe arayüzüyle haberleşir.

### 10.3 Sanal Portlar

Fiziksel portların dışında sanal portlar da vardır. Sanal portlar genelde 0 ile 65535 arasında numaralandırılır. Bilgisayarlar bu kapılar üzerinden birbiriyle haberleşir ve bilgi transferi yapar. Derste geçen örnekler şunlardır:

- FTP (File Transfer Protocol): dosya aktarımı için kullanılır
- SSH: güvenli haberleşmeyi sağlar
- SMTP (Simple Mail Transfer Protocol), POP3 ve IMAP: e-posta için kullanılır ve farklı portlar kullanırlar
- HTTP: port 80
- HTTPS: port 443, güvenli web bağlantısı istendiğinde kullanılır

Hoca FTP için önce 23 dedi. Bir öğrenci 21 olması gerektiğini, 22'nin ise SSH olduğunu söyledi. Hoca 21 olabileceğini kabul etti.

> **Ders sonrası not:** Hoca FTP portu için önce 23 dedi; doğrusu büyük olasılıkla 21'dir. Öğrencinin söylediği gibi SSH büyük olasılıkla 22'dir, 23 ise büyük olasılıkla Telnet'e aittir.

### 10.4 Portlar ve Güvenlik

Hoca bu konuya şu nedenle girdiğini söyledi: Haberleşme farklı kapılar üzerinden yürür ve bir portun tehlike yaratacağını düşünüyorsanız onu kapatabilirsiniz. Portlar bilgisayarın giriş-çıkış kapılarıdır. Birçok saldırı bu portlar üzerinden gerçekleşir. Portlar açıksa gelebilecek saldırılara karşı tedbir almanız gerekir. Fiziksel portlar zaten kullanıcının kontrolündedir.

Bir öğrenci kendi deneyimini ekledi: Yeni aldığı bir makinenin giriş kayıtlarına bakınca, adresleri otomatik olarak tarayan programların makineye deneye deneye girmeye çalıştığını görmüş, ek güvenlik önlemi almadığında bunun gerçekten yaşanabildiğini fark etmiş.

<!-- BELİRSİZ: Öğrencinin bu cümlesi altyazıda bozuk ("elsiz güvenlik yöntemi"); anlatılan ek önlemin ne olduğu net değil. -->

Hoca bu örneği doğruladı: Port taraması (port scan) yapılarak açık port bulunur ve oradan kaba kuvvet saldırısı (brute force attack) yapılabilir. Hoca kaba kuvvet saldırısını, bir porta çok sayıda bilgi gönderip bu sayıyı artırarak bilgisayarı hizmet engelleme (Denial of Service) durumuna, yani cevap veremez noktaya getirmek olarak anlattı.

> **Ders sonrası not:** Hoca brute force saldırısını bilgisayarı cevap veremez hâle getirmek olarak anlattı; doğrusu büyük olasılıkla bunlar iki ayrı saldırıdır. Kaba kuvvet saldırısı, şifre gibi bir bilgiyi çok sayıda deneme yaparak bulmaya çalışmaktır. Öğrencinin anlattığı "deneye deneye girme" buna uyar. Porta çok sayıda istek gönderip sistemi cevap veremez hâle getirmek ise Denial of Service saldırısıdır.

## 11. Protokoller

### 11.1 Protokol Nedir?

Protokol, iki cihazın ya da iki birimin birbiriyle haberleşirken kullanacağı kurallara verilen addır. Derste sayılan protokoller şunlardır:

- Ağ haberleşmesinde kullanılanlar: IP (Internet Protocol), TCP, UDP
- Bluetooth, NFC, Wi-Fi
- FTP, SMTP, SSH, IMAP, HTTP: Bunların hem kuralları hem de kullandıkları kapılar vardır

Hepsinin kuralları farklıdır. İki farklı cihaz bu kurallar kullanılarak birbiriyle haberleştirilir.

### 11.2 Wi-Fi "Kablosuz İnternet" Değildir

**Soru:** Wi-Fi deyince protokolü mü, yoksa interneti mi kastediyoruz?

**Cevap:** Wi-Fi deyince akla kablosuz internet gelmemelidir. Kablosuz internet diye bir şey yoktur. İnternet, bütün bilgisayarların birbirine bağlandığı bir ağ yapısıdır. Bu geniş ağda diğer bilgisayarlarla haberleşirken farklı yöntemler kullanılır. Modeme doğrudan kabloyla bağlıysanız Ethernet protokolünü, kablosuz bağlanıyorsanız Wi-Fi protokolünü kullanırsınız.

Wi-Fi'nin kendi içinde de farklı protokolleri vardır. IEEE 802 ile başlayan ve a, b, g, n diye adlandırılan birçok protokol tanımı, en üst seviyede Wi-Fi protokolü diye ifade edilir. Hoca bu adlandırmayı hücresel ağlardaki 2G, 3G, 4G, 4.5G, 5G ile karşılaştırdı: Bunlar haberleşmenin temel prensiplerini korur, ama haberleşmeyi hızlandıran ve hata oranını düşüren yenilikler içerir.

> **Ek bilgi (derste anlatılmadı):** Wi-Fi alt protokolleri büyük olasılıkla IEEE 802.11 ailesinin sürümleridir. Örneğin 802.11a, 802.11b, 802.11g ve 802.11n. Ethernet de büyük olasılıkla aynı IEEE 802 ailesinde, 802.3 adıyla tanımlıdır.

## 12. Kablosuz Haberleşme Türleri

Hoca kablosuz haberleşme tiplerini sordu. Öğrencilerin cevapları üzerinden liste oluştu. Ethernet kablosu önerisi, kablolu olduğu için listeye girmedi. Televizyon önerisi de kabul edilmedi, çünkü televizyon bir protokol değil, bu protokollerden yararlanan bir cihazdır.

Kabul edilen türler şunlardır:

- Bluetooth
- GSM üzerinden haberleşme
- Wi-Fi
- NFC
- Kızılötesi (infrared)

### 12.1 GSM ve Hücresel Ağ

Bir öğrenci SMS'i örnek verdi. Hoca bunu daha genel bir ifadeyle GSM üzerinden haberleşme olarak adlandırdı. SMS'in açılımı Short Message Service'tir.

**Soru:** Telefonlardaki mobil veri GSM'in içine mi dahildir, yoksa ayrı bir protokol müdür?

**Cevap:** Telefonlar baz istasyonları üzerinden, GSM şebekesi üzerinden haberleşir. Buna hücresel ağ (cellular network) denir. GSM genel addır. Altında 2G, 3G, 4.5G, 5G gibi farklı protokoller vardır ve her biri ayrı bir kural silsilesi olarak kabul edilir.

> **Ders sonrası not:** Hoca GSM'i 2G'den 5G'ye kadar hepsinin genel adı olarak kullandı; GSM büyük olasılıkla dar anlamda 2G standardının adıdır. Hepsini kapsayan ad olarak hocanın da söylediği "hücresel ağ" daha uygundur.

### 12.2 Radyo Dalgaları

Hoca, bu haberleşme protokollerinin temelinde radyo dalgalarının kullanıldığını söyledi. Bilgi, farklı frekanslardaki radyo dalgaları üzerinden taşınır. Radyo da böyle çalışır: AM ve FM bantlarında farklı megahertzlerdeki yayınları dinlersiniz.

### 12.3 Kızılötesi ve Sensörler

Bir öğrenci kızılötesinin kumandalarda hâlâ kullanıldığını hatırlattı. Hoca, kızılötesinin diğerlerinden farkını sordu. Bir öğrenci kısa mesafede çalıştığını söyledi. Hoca bunu doğru buldu, ama özel bir durumun da gerektiğini belirtti. Bir diğer öğrenci kızılötesinin duvarlardan "kolay kolay" geçemediğini söyledi. Hoca ifadeyi düzeltti: "Kolay kolay" dersek biraz zorlayınca geçermiş gibi anlaşılır. Oysa önünde engel varsa kızılötesiyle haberleşme sağlanamaz. Kumandanın önüne bir şey geldiğinde çalışmamasının sebebi budur.

Hoca kızılötesinin pasif hâlini de andı: Binaların koridorlarında hareketi algılayıp ışığı yakan, belli bir süre hareket olmayınca kapatan sistemler buna örnektir. Araçlardaki park sensörleri ise ultrasonik ses dalgalarıyla çalışır ve park ederken yakında bir cisim, araç ya da insan olup olmadığını algılar. Hoca bunu da kablosuz haberleşmenin parçalarından biri olarak andı.

> **Ders sonrası not:** Hoca park sensörünü kablosuz haberleşme parçası olarak andı; bu sensörler büyük olasılıkla haberleşme değil, algılama yapar. Pasif kızılötesi sensörler için de büyük olasılıkla aynısı geçerlidir. Ayrıca kızılötesi ve ultrasonik ses radyo dalgası değildir. Bu yüzden Bölüm 12.2'deki radyo dalgası açıklaması büyük olasılıkla yalnız Bluetooth, Wi-Fi, NFC ve hücresel ağ için geçerlidir.

## 13. RISC Üzerine Bir Soru ve İşletim Sisteminin Tanımı

### 13.1 ARM Mimarili Dizüstü Bilgisayarlar

Son bölüme geçerken bir öğrenci RISC ve CISC konusuna döndü.

**Soru:** Karmaşık işler için CISC gerektiğini konuştuk. Apple ise ARM mimarili bir dizüstü bilgisayar tanıttı. Mimari bu kadar karmaşık komutlara sahip değilse bu nasıl mümkün oluyor?

**Cevap:** Burada keskin bir ifade kullanmak niyetimiz yoktu. RISC mimarisinin dizüstü bilgisayarda kullanılamayacağını hiçbir zaman söylemiyoruz. RISC felsefesi kullanılarak yeni tip bir işlemci mimarisi tasarlanmış olabilir. RISC felsefesinde olmak, bütün işlemcilerin aynı performansı gösterdiği anlamına gelmez. Bu yüzden yeni çıkan işlemcinin komut setine ve nasıl tasarlandığına bakmak gerekir. RISC felsefesini kullanması, karmaşık işleri yapamayacağı anlamına gelmez. Derste vurgulanan, bu iki felsefenin ilk çıkış noktasındaki farktır.

Hoca buna benzer bir örnek de verdi: Android uzunca bir süre yalnız ARM kullanıyordu, daha sonra Intel işlemcili cihazlara da destek vermeye başladı.

### 13.2 İşletim Sistemi Nedir?

Hoca konuya şöyle girdi: Donanımın verimli çalışabilmesi için iyi bir işletim sistemine ihtiyaç vardır. Bir öğrenci işletim sistemini bilgisayarın kaynak yönetimini sağlayan yazılım olarak tanımladı. Hoca da bunu duymak istediğini söyledi: İşletim sistemi (operating system), bilgisayarın kaynaklarını verimli biçimde kullanmasını sağlayan bir yazılımdır.

Derste sayılan işletim sistemleri şunlardır:

- PC ortamı: Windows, macOS, Linux, Unix
- Mobil: Android, iOS
- Bu işletim sistemlerinin sunucu sürümleri: Sunucularda birden fazla kişi aynı bilgisayara bağlanıp aynı anda iş yapabilir.

## 14. Toplu, Etkileşimli ve Gerçek Zamanlı İşleme

Hoca işletim sistemlerinin tarihçesine bu kavramlarla girdi.

### 14.1 Toplu İşleme (Batch Processing)

İlk önerilen cevaplar delikli kağıtlar ve elimizdeki veri oldu. Hoca, delikli kağıtların o döneme ait bir kullanım olduğunu ama kavramın ondan bağımsız olduğunu söyledi. Bir öğrenci, "batch" sözcüğünün yığın, toplu anlamına geldiğini hatırlattı. Bu doğru yöne götürdü.

Bir ya da birden fazla işi arka arkaya, tek bir sefer içinde, kullanıcıyla etkileşim olmadan gerçekleştirmeye toplu işleme denir. Eskiden bilgisayara yapılacak işler arka arkaya tanımlanırdı. Bilgisayar sıradaki işi alır, tamamlar, sonucu üretir ve bir sonraki işe geçerdi.

Toplu işlemenin olmazsa olmazı iş kuyruğudur (job queue). İşlem görecek işler bu kuyrukta saklanır. Kuyruk FIFO (First In, First Out) mantığıyla çalışır: Kuyruğa ilk giren, hizmeti ilk alır. Hoca, ileride LIFO (Last In, First Out) gibi örneklerin de görüleceğini söyledi.

Toplu işleme, kullanıcının program çalışırken işe müdahil olmasını engeller. Bu, bugünkü çalışma biçimimizden oldukça uzak bir yapıdır.

### 14.2 Etkileşimli İşleme (Interactive Processing)

Bugünkü yapıya yaklaşmak için atılan adım etkileşimli işlemedir. Program çalışırken kullanıcı onunla etkileşim içindedir, başka bir seçim yaparak üretilen sonucu yönlendirebilir. Bugünkü olay güdümlü programlama (event driven programming) ile tasarlanan pencere yöneticilerinde (window manager) tek bir yol yoktur: Pencerede bir yere basar, başka bir seçeneği seçer, menüden yapılacak işi belirlersiniz. Hoca bir de etkileşimli işlemeyle ilgili bir video gösterdi.

<!-- BELİRSİZ: 01:58:47 civarında gösterilen videonun içeriği altyazıda yok. -->

**Soru:** Fark şu mu: Birinde `5 mod 2` girip sonucu hemen alıyoruz, öbüründe önce 5'i, sonra işlemi, sonra 2'yi ayrı ayrı mı giriyoruz?

**Cevap:** Bu, anlatmak için çok basit bir ifade olur. Bir programa bütün girdiyi verirsiniz, örneğin toplama, çıkarma ve çarpmayı verirsiniz, bunları arka arkaya yapar ve sonucu üretir. Bu toplu işlemedir. Etkileşimli işlemeyle kastedilen ise şudur: Word'de bir şey yazarken sürekli yazıp silebilirsiniz. Müzik dinlerken müziği istediğiniz yerde durdurup yeniden çalıştırabilirsiniz.

**Soru:** C ile kod yazıp çalıştırınca bu toplu işleme gibi mi oluyor?

**Cevap:** Öyle düşünmeyin. Şu andaki bilgisayarlar aynı anda birden fazla iş yapmanıza izin verir. Hem müzik dinleyip hem internette gezip hem de bir doküman okuyabilirsiniz. Toplu işleme olsaydı bunların hiçbiri aynı anda olamazdı, biri gerçekleşirken diğerlerinin beklemesi gerekirdi.

**Soru:** Toplu işleme yalnız bir pencere açmamıza izin veren bir şey mi?

**Cevap:** Mesele pencere açmak değildir. Toplu işleme tarihte kalmış bir yaklaşımdır ve bugünkü şartlara uydurulmamalıdır. Tek bir iş yapmak demektir: CPU aynı anda başka hiçbir şey çalıştırmadan, kullanıcıyla da etkileşmeden girdiyi alır, programı çalıştırır ve çıktıyı üretir. Bir C programı çalıştırdığınızda böyle görünse de, program çalışırken arka planda başka programlar da çalışır. Ayrıca yazdığınız C programları her zaman girdiyi alıp çıktıyı beklemenizi gerektirmez. Çoğu zaman her girdiden sonra ürettiği çıktıyla size başka adımlar sorarak yeniden etkileşime geçer. Eski yapıda ise işi verdikten sonra, girdiyi de verdiyseniz, o programa bir daha müdahil olamazsınız. Temel fark budur.

Bu kavramı bugün de kullanan yapılar vardır. Örneğin bir bankada her gece saat 3'te çalışacak bir süreç tanımlanabilir. Birden fazla süreç arka arkaya devreye girerek faturalarla ilgili transferler gibi arka plan işlerini toplu işleme mantığıyla yapar. Bunlara bir öğrencinin de söylediği gibi cron job denir ve veri tabanında ya da başka işlerde kullanılabilir. Ama bu cihazlar eski tip bir cihaz gibi aynı anda tek bir iş yapmaz.

### 14.3 Gerçek Zamanlı İşleme (Real-Time Processing)

Öğrencilerden saat ve kronometre, verilen işi anında yapmak, grafik kartının anlık işlem yapması gibi öneriler geldi. Hoca bunları tanım olarak yeterli bulmadı, grafik kartı üzerinden anlatılmamasını istedi.

Bir bilgisayara verilen görevin (task) belirtilen bir süre içinde tamamlanmasına gerçek zamanlı işleme denir. Bu süreler gerçek dünya şartları gözetilerek belirlenen son teslim süreleridir (deadline) ve saniye ya da milisaniye cinsinden ifade edilir.

Hocanın örneği müzik dinlemedir. Gerçek zamanlı işleme olmasaydı müziği kesintili dinleyebilirdiniz. Radyodan dinlerken o anda gelen müziği 5 ya da 10 saniye sonra duyabilirdiniz. Eski tip toplu işleme cihazlarında ise verilen iş sırası geldiğinde yapılırdı. Bu 5 dakika sonra da olabilirdi, 1 saat sonra da. Bu yüzden orada gerçek zamanlı işlemeden söz edilmez. Hoca, bugün Word, Excel ya da bir oyun açtığımızda bunların gerçek zamanlı gerçekleştiğini gördüğümüzü de söyledi.

> **Ders sonrası not:** Hoca Word ve Excel'i gerçek zamanlı işleme örneği olarak andı; bunlar büyük olasılıkla etkileşimli işleme örneğidir. Teknik anlamda gerçek zamanlı sistemde büyük olasılıkla belirli bir deadline'a uyulması gerekir, hızlı cevap vermek tek başına yetmez. Derste verilen deadline tanımı doğrudur.

## 15. Zaman Paylaşımı, Çoklu Programlama ve Çoklu Görev

Hoca gelişimi şöyle özetledi: Eskiden bir kullanıcı bir cihazda farklı programlar çalıştırıyordu. Sonra birden fazla kullanıcı aynı cihazda programlar çalıştırmaya başladı. Bugün birden fazla işi aynı anda çalıştırabiliyoruz. Bu yol, zaman paylaşımına çıkar.

### 15.1 Zaman Paylaşımı (Time-Sharing)

Bir öğrenci, Bluetooth cihazlarının sesi aynı anda çıkarmak için eşzamanlı olmasını örnek önerdi. Hoca bunun farklı bir örnek olduğunu, kavramın işletim sistemi ve bilgisayar üzerinde yapılan işler üzerinden değerlendirilmesi gerektiğini söyledi.

Eskiden bir kişi, bilgisayarda iş yapmak için diğer kişinin işini bitirmesini beklerdi. Bugün bir bilgisayara birden fazla kullanıcı bağlanıp CPU'yu paylaşarak işlerini gerçekleştirebilir. Bu, zaman paylaşımı sayesinde olur: İşletim sistemi bir kullanıcıya belirli bir zaman, diğer kullanıcıya belirli bir zaman verir. Böylece aynı bilgisayar üzerinden birden fazla kişiye hizmet sunulur.

### 15.2 Çoklu Programlama (Multiprogramming)

Bir öğrenci çoklu programlamayı, bir programın birden fazla işi birbirini beklemeden paralel yapması olarak tanımladı. Hoca bunun başka bir şeye gittiğini söyledi. Başka bir öğrencinin önerisi de farklı kullanıcılardan alınan bilgileri aynı anda işlemekti. Hoca bunun üzerine tanımı ekrana yazdı.

<!-- BELİRSİZ: Hocanın 02:06:50-02:08:32 arasında ekrana yazdığı tanımın metni altyazıda yok. Aşağıdaki anlatım, sözlü açıklamadan kuruldu. -->

Zaman paylaşımı açıklanırken çoklu programlamadan yararlanılır. Çoklu programlamada zaman aralıklara (interval) bölünür ve bir $t$ anında yalnızca bir iş yapılır. İşlemci her sürece belirli bir süre çalışma imkânı verir. Ek işlemci ya da çekirdek yoksa bir $t$ anında gerçekten yalnız bir iş yapılıyordur.

Word'e yazarken, internette okurken ve müzik dinlerken bunların her biri işlemcide bir süre çalışır, sonra işlemciyi diğerine bırakır. Siz bunların aynı anda çalıştığını düşünürsünüz, ama aslında işlemciyi kesintili olarak kullanırlar. Zaman paylaşımının mantığı buradan gelir.

### 15.3 Çoklu Görev (Multitasking)

Çoklu programlama tekniğinin tek kullanıcılı ortama aktarılmış hâline çoklu görev (multitasking) denir. Bugünkü bilgisayarlarımızda uygulanan yapı budur. Bu sayede birden fazla görev aynı anda yönetilebilir. Bunu yapan işletim sistemidir. Birden fazla programı aynı anda çalıştırabilmemiz, işletim sisteminin bu özelliği sayesindedir.

## 16. Gömülü Sistemler

Hoca gömülü sisteme (embedded system) örnek istedi.

**Soru:** BIOS gömülü sistem olarak söylenebilir mi?

**Cevap:** Hayır, BIOS (Basic Input Output System) tamamen farklı bir şeydir. Genelde bilgisayarların donanımlarını temel seviyede yapılandırmak için kullanılan bir yazılımdır.

Bir öğrencinin IoT cihazları önerisini hoca kabul etti, ama ne tür bir cihaz kastedildiğini sordu. Öğrenci bunu tarif etmekte zorlandı.

> **Hocanın vurgusu:** İfade etmekte zorlanıyoruz. Bir şey aklınıza geliyor ama onu tarif etmekte zorlanıyorsunuz. Konuya tam hâkim olmamak sorun değildir, ama bilip de anlatamıyorsanız bir sorun var demektir. Bu konuda kendinizi geliştirmeniz gerekir.

Başka bir öğrenci, ekmek kızartma makinelerinin ekmeğin kızarıp kızarmadığını anlayan sistemlerini örnek verdi. Hoca bu örneği çok beğendi ve şu tanımı yazdı: Gömülü sistemler, belirli görevlere adanmış cihazlardır (devices that are dedicated to specific tasks). Tıbbi cihazlar, araç elektroniği, ev aletleri ve cep telefonları buna örnektir.

Bilgisayar normalde belirli bir görevi yapmak için değil, birçok görevi yönetmek üzere tasarlanır. Çamaşır makinesinin görevi ise çamaşır yıkamaktır ve bununla ilgili programları vardır. İşte bu bir gömülü sistemdir. Ekmek kızartma makinesi, evdeki cihazlar ve arabadaki belirli yetenekler de böyledir.

Telefon artık bilgisayar biçimine dönüştüğü için akıllı telefonları bu kategoride saymamak gerekebilir. Ama üzerinde işletim sistemi olmayan eski tip telefonlar bu kategoride değerlendirilebilir.

Gömülü sistemlerin her biri için doğrudan bir işletim sistemi var denemez. Bazılarında vardır: Örneğin arabalar için Android tabanlı bir işletim sistemi vardır. Fakat bulaşık makinesi, klima gibi IoT cihazlarında şu an için işletim sistemi gerektiren bir durum yoktur. Çünkü belli görevler vardır ve cihazdan bunları yapması istenir. Bu durumda bir işletim sisteminin karmaşık yapısına ihtiyaç duyulmaz. İşletim sistemi, bilgisayarlarımızdaki gibi çok fazla kaynağı yönetme ve çok fazla işi aynı anda yapma ihtiyacı olduğunda gerekir.

## 17. İşletim Sistemi Mimarisi

### 17.1 Yazılımların Sınıflandırılması

İşletim sistemi mimarisine (operating system architecture) geçmeden önce hoca yazılımları sınıflandırdı. İşletim sistemi de bir yazılımdır. Sınıflandırma şöyledir:

- Yazılım (software)
  - Uygulama yazılımı (application software)
  - Sistem yazılımı (system software)
    - Yardımcı yazılım (utility software)
    - İşletim sistemi (operating system)
      - Kullanıcı arayüzü (user interface)
      - Çekirdek (kernel)

Uygulama yazılımları günlük kullandığımız Word, müzik dinleme ve video izleme programları gibi yazılımlardır.

### 17.2 Yardımcı Yazılımlar

Bir öğrencinin önerdiği gibi, yardımcı yazılımlar sistemi yönetmek için kullanılan yardımcı araçlardır. Windows'taki görev yöneticisi önerisine hoca, işletim sisteminin bir parçası gibi düşünülebileceğini ama çok yanlış olmadığını söyledi. Windows'ta otomatik güncellemeleri yöneten parça da yardımcı yazılım sayılır.

Üçüncü taraf (third party) yardımcı yazılımlar ve işletim sistemine ait yardımcı yazılımlar vardır. Sabit diski bölümlere (partition) ayırma ve diski temizleme ile ilgili sistemsel yazılımların hepsi bu başlık altında geçer. Yardımcı yazılımlar destek verir, işletim sistemi ise bilgisayarın yönetiminde temel (core) görevi gerçekleştirir.

> **Ders sonrası not:** Hoca bu örneklere "bellek yönetimi" diyerek başladı; verdiği örnekler sabit diskle ilgili olduğundan kastı büyük olasılıkla disk yönetimidir. Bellek yönetimini hoca az sonra çekirdeğin görevleri arasında saydı.

### 17.3 Çekirdek (Kernel)

Çekirdek, bir işletim sisteminin yapması gereken bütün temel işlerden sorumlu parçadır. Hoca bu görevleri öğrencilerle birlikte saydı:

- Süreç yönetimi (process management): işleri yönetmek
- Bellek yönetimi (memory management)
- Dosya yönetimi (file management)
- Giriş-çıkış yönetimi (I/O management): ekran, klavye, fare gibi giriş-çıkış birimlerinin yönetimi
- Ağ yönetimi (network management)

**Soru:** Device management de olabilir mi?

**Cevap:** Bu çok genel bir ifadedir. I/O yönetimiyle aynı anlama gelir, birbirinin yerine kullanılabilir.

Dersin sonunda bir öğrenci çekirdeğin tam olarak ne olduğunu yeniden sordu.

**Soru:** Kernel tam olarak nedir?

**Cevap:** Bu görevlerin hepsini arka planda, müdahale olmadan, kendi kendine çalışarak yönetebilen işletim sistemi birimidir. Çekirdeğe ancak yetkili bir kişi belirli müdahaleler yapabilir. Süreç, bellek ve dosya yönetimi gibi görevler çekirdekte kodlanmıştır. İşletim sistemi bilgisayarın yönetimini bu kodlar aracılığıyla yapar. Dışarıdan gelen müdahaleler yalnız kullanıcının isteklerini karşılamak içindir.

### 17.4 Kullanıcı Arayüzü

Çekirdek bu işleri yaparken, kullanıcının bilgisayarı kullanabilmesi için dışarıdan bilgi alması ve dışarıya bilgi vermesi gerekir. Bunun için kullanıcı arayüzü vardır. Hoca bu yapıyı bir çizimle gösterdi: Ortada çekirdek, onun etrafında kullanıcı arayüzü vardır. Kullanıcı dışarıdan, kullanıcı arayüzü aracılığıyla çekirdeğe komut aktararak işletim sistemine işlerini yaptırır.

İki seçenek vardır:

- **Komut satırı (shell, kabuk):** Genelde fare kullanmadan, klavyeden yazılan komutlarla işletim sistemine ulaşılır. Eski bir yöntemdir ama hâlâ geçerlidir ve işleri grafik arayüzden daha hızlı yaptırmak için sık kullanılır. Grafik arayüz bilgisayarın yükünü artırdığı için, uzaktaki bir bilgisayara grafik arayüz kurmadan, doğrudan portlar üzerinden ulaşılıp iş yaptırılabilir.
- **Grafik kullanıcı arayüzü (graphical user interface):** Bir grafik arayüz ve pencere yöneticisi yapısı vardır. İşler farklı pencereler üzerinden, düğmelerle ve çeşitli alanlara tıklayarak yapılır. Hoca bunu komutların grafik arayüze aktarılmış hâli gibi düşünebileceğimizi söyledi. Bugün kullandığımız bilgisayarlarda genelde bu yapıyla çalışıyoruz.

Hoca, komut satırı üzerinden yaptırılamayacak bir iş olmadığını, bunun grafik arayüzden daha kuvvetli bir yapı olduğunu söyledi.

> **Ders sonrası not:** Hoca hemen ardından "komut satırında yaptırabileceğiniz her şeyi grafik arayüzde de yaptırabilirsiniz" dedi; doğrusu büyük olasılıkla tersidir: Grafik arayüzde yapılan her şey komut satırından da yapılabilir. Hocanın bir önceki cümlesi de bunu destekler.

## Dersin Toparlaması

Bu derste bilgisayar donanımından işletim sistemine doğru ilerlendi. CPU'nun birimleri, bellek hiyerarşisi, komut seti, RISC ve CISC yaklaşımları, temel işlemler ve makine döngüsü işlemcinin bir komutu nasıl çalıştırdığını gösterdi. Saat hızının tek başına karşılaştırma ölçütü olmadığı, bu yüzden benchmark testlerine başvurulduğu görüldü. Ardından bilgisayarın dış dünyayla haberleşmesine geçildi: denetleyiciler, paralel ve seri haberleşme, hız birimleri, bant genişliği, portlar, protokoller ve kablosuz haberleşme türleri. Son bölümde işletim sisteminin toplu işlemeden çoklu göreve uzanan gelişimi, gömülü sistemlerle farkı ve kernel ile kullanıcı arayüzünden oluşan yapısı anlatıldı.

Hoca, işletim sistemlerinde küçük bir kısmın kaldığını söyledi. Bu kısım iki hafta sonra tamamlanacak, ardından ağ (network) konusuna geçilecek ve ders bir algoritmayla bitirilecektir.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
