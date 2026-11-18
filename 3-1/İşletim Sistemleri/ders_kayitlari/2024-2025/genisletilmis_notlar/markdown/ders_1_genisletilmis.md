# Ders 1 Genişletilmiş Notu: Derse Giriş, Bilgisayar Sistemi Bileşenleri, Komut Çevrimi, Kesmeler ve İşletim Sisteminin Tanımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Niteliği ve Kaynaklar
- 2. Bilgisayar Sisteminin Bileşenleri
- 3. Bir Programın Çalışması ve Komut Çevrimi
- 4. Von Neumann ve Harvard Mimarileri
- 5. İşletim Sistemine Neden İhtiyaç Var?
- 6. İşletim Sisteminin Tarihçesi
- 7. Donanım Özeti ve Bellek Hiyerarşisi
- 8. Derleyici ve Emülatör Gösterimi
- 9. G/Ç Aygıtları, Buslar ve İşletim Sisteminin Yaşam Alanları
- 10. Komut Çevrimi Durum Diyagramı
- 11. Kesmeler (Interrupts)
- 12. İşletim Sisteminin Tanımı, Amaçları ve Görevleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Niteliği ve Kaynaklar

İşletim Sistemleri dersi, veri yapıları ya da algoritmalar gibi çok işlem gerektiren derslerden farklı olarak teorik ve kavram ağırlıklı bir derstir. Önce teori öğrenilir; teori de büyük ölçüde kavramlar ve kavramlar arasındaki ilişkiler üzerine kuruludur. Dönemin büyük bölümü işletim sisteminin bileşenlerine ayrılmıştır: süreç yönetimi (process management), bellek yönetimi (memory management), sanal bellek yönetimi (virtual memory management) gibi. Hocaya göre süreç yönetimi tek başına 7-8 haftalık bir konudur.

Ana kaynak Silberschatz, Galvin ve Gagne'nin "Operating System Concepts" kitabıdır. Derste kullanılan slaytlar bu kitabın 9. baskısına aittir (ekrandan, 01:32:00). Hoca kitabın belli bir bakış açısıyla yazıldığını, konuların ortaya çıkışının 25-30 yıl öncesine dayandığını ve bu yüzden ek kaynaklara da ihtiyaç olduğunu söyledi. İkinci kaynak William Stallings'in "Operating Systems: Internals and Design Principles" kitabıdır. Üçüncü olarak, Minix adlı küçük ölçekli işletim sisteminin yazarı Tanenbaum'un kitapları anıldı. Bazı kitaplar C ya da Java örneklerine ağırlık verir; bu derste asıl önemli olan kavramlardır.

> **Hocanın vurgusu:** Kavramlar tahtaya yazılarak öğrenilmez; kitabı okuyup kavramları özümsemek gerekir. Derse gelmeden slaytlara bakmak, dersi dinlemek ve kitabı okumak başarı için yeterlidir. Çıkmış sorulara güvenmek yanıltıcıdır.

Hoca, işletim sisteminin donanım üzerine kurulmuş çok karmaşık bir sistem yazılımı olduğunu, bu yüzden dersin bir ders silsilesinin devamı olduğunu vurguladı. Bilgisayar Organizasyonu, Veri Yapıları ve Algoritmalar ile Programlama derslerinde görülen kavramlar (linked list nedir, struct nedir, instruction nedir) bilinmelidir. Bellek erişimleri konusunda assembly örnekleri verileceği için assembly dilinin temel kavramlarının hatırlanması gerekir.

## 2. Bilgisayar Sisteminin Bileşenleri

Hoca "bilgisayar sistemi" ifadesindeki "sistem" kelimesine dikkat çekti: Sistem dediğimiz şeyin bileşenleri vardır. Donanım açısından ilk bileşen işlemcidir; programların çalıştırılabilmesi (execute) ve verilerin işlenebilmesi için gerekir. İşlemci tek başına işe yaramaz; üzerinde çalışacağı veriyi saklamak ve yazdığımız programları işlemciye getirip götürmek için belleğe ihtiyaç vardır. İşlemci ile belleğin birbirine bağlanması için de bus (yol) yapıları gerekir.

Buslar genel olarak üç türlüdür:

- **Adres yolu (address bus):** Bellekteki adresi gösterir. İşlemciye bir komutun ya da verinin gelebilmesi için o komutun bellekteki adresinin gösterilmesi gerekir.
- **Veri yolu (data bus):** Bellekten gelecek ya da belleğe yazılacak veri ve komutları taşır.
- **Kontrol yolu (control bus):** Bellekte okuma (read) mı yazma (write) mı yapılacağını belirtir.

Hoca bu yapıyı Paint'te çizdi: solda bir CPU kutusu, sağda üst kısmı komutlara (instruction), alt kısmı verilere (data) ayrılmış bir bellek kutusu ve aralarında üç çizgi; CPU içinde de program sayacını (PC) gösteren küçük bir kutu (ekrandan, 00:25:00). Üç bus çizildiğinde bunlar üç tel değildir; her biri kendi içinde ayrıntılıdır, seri ya da paralel iletişim gibi mekanizmalar içerebilir. Çizim yalnızca bir soyutlamadır (abstraction). Komut ve verinin her zaman tek bir bellekte bir arada bulunması gerekmez; bu en genel bilgisayar mimarisinin en basit hâlidir.

## 3. Bir Programın Çalışması ve Komut Çevrimi

Bir program çalıştırıldığında başlangıç satırından itibaren komutlar adım adım (step by step) işlemciye getirilir. Hangi komutun getirileceğini CPU içindeki özel bir eleman belirler: **program sayacı (program counter, PC)**. PC "bana 3. satırdaki komutu getir, sonra 4. satırdakini getir" der. Komut, adres yolunun gösterdiği yerden, veri yolu üzerinden gelir. Okuma yapılacaksa kontrol yolundan okuma sinyali, yazma yapılacaksa yazma sinyali gönderilir.

### 3.1 Üç satırlık örnek program

Hoca işlemci içindeki AX register'ını bir değişken gibi düşünmemizi istedi. Programlarda yazdığımız x, y, z gibi değişkenler bellekte durur, ama işlemcide bir karşılıkları olmalıdır; bu karşılık genel ya da özel amaçlı register'lar üzerinden olur. Ekranda yazılan program şudur (ekrandan, 00:25:00; üçüncü satır ekranda `MOV [1234]` olarak kesik görünür, `AX` operandı anlatımdan alınmıştır):

```text
MOV AX, 5       ; AX'in içine 5 kopyalanır
ADD AX, 5       ; AX'teki veriye 5 daha eklenir (5 + 5 = 10)
MOV [1234], AX  ; köşeli parantez bellek demektir: AX'teki veri 1234 adresine kopyalanır
```

Bu programın çalışması için önce PC birinci satırı gösterir, komut bellekten okunur (getirilir) ve çalıştırılır. Sonra PC ikinci satırı gösterir; komut yine bellekten okunarak getirilir ve çalıştırılır. Üçüncü komut getirilip çalıştırıldığında bir sonuç üretilir; fakat bu komut sonucun 1234 adresine yazılmasını ister. Bu kez yazma sinyaliyle belleğe gidilir ve AX'te saklanan toplam belleğe geri yazılır. Programın bütün satırları böyle sürekli bir döngü içinde çalıştırılır.

### 3.2 Komut çevrimi (instruction cycle)

Komutlar "pat diye" çalıştırılmaz; belli aşamalardan geçer. Buna **komut çevrimi** ya da komut döngüsü (instruction cycle) denir:

- **Getirme (fetch):** PC'nin gösterdiği adrese gidilir, oradaki komut getirilir. Hoca "gidip getirmek" ifadesinin altını çizdi.
- **Çözme (decode):** İşlemci gelen komutun ne olduğunu anlamalıdır: toplama mı, çıkarma mı, karşılaştırma mı, döngü mü? Burada C kodu yoktur, her şey makine komutu üzerindendir.
- **Çalıştırma (execute):** Ne yapılacağı anlaşıldıktan sonra komut yürütülür.
- **Geri yazma (write back):** Sonucun belleğe geri yazılması gerekiyorsa bu işlem yapılır.

Bu döngü program başladığından bitene kadar sürer. C'de ya da Java'da yazılan tek bir satır, işlemcide tek bir komuta karşılık gelmek zorunda değildir. Örneğin `a++` için birçok işlemcide `INC` komutu vardır; komutun birebir karşılığı varsa en temiz dönüşüm yapılır. Karşılığı olmayan bir işlemcide ise derleme aşamasında o işlemcinin anlayacağı komutlara dönüştürülür ve tek satırlık C kodu çok sayıda makine komutuna karşılık gelebilir. Bu durumda bellek ile işlemci arasındaki gidiş geliş döngüsü birden fazla kez yaşanır.

### 3.3 Tek programdan çok programa

Örnekte yaptığımız şey, bir sayıyı alıp 5 eklemek ve belleğe yazmaktı; bir hesap makinesinde 4 ile 4'ü toplamaktan çok farkı yoktur. Oysa bugünkü bilgisayarlarda tek program yoktur: Ses gider, arka planda başka programlar çalışır, internet bağlantısı sürer; belki binlerce komut aynı anda işlenmektedir. Bu karmaşanın içinden sorun çıkmadan bütün programların iş birliği içinde yaşayabilmesi için ek bir mekanizma gerekir. Bu mekanizmanın adı **işletim sistemidir**; "operate" bir şeyin işletilmesi demektir.

## 4. Von Neumann ve Harvard Mimarileri

Her mimaride bellek komut ve veri olarak ikiye ayrılmaz. Belleği komut ve veri bölgelerine ayırıp ikisini tek bellek üzerinde tutan yapıya **Von Neumann mimarisi** denir. Bu mimaride işlemci ile bellek arasında tek bir bus vardır. **Harvard mimarisinde** ise program belleği ile veri belleği ayrıdır; iki bellek olduğu için doğal olarak iki ayrı bus yapısı vardır. Hoca bunu "bir yanda sağ kol, bir yanda sol kol" gibi iki kollu bir yapıya benzetti. İkisinin de kendine göre avantaj ve dezavantajları vardır.

Intel mimarisi (x86) genellikle Von Neumann'a yakındır. PIC, Atmel gibi diğer işlemci mimarileri Harvard'a yakındır. Bunların derinlikleriyle işletim sistemi dersinde çok işimiz olmasa da bilmemiz gerekir: Yazılan bir işletim sistemi işlemciye uygun olmalıdır. Format attıktan sonra ekran kartı, ses kartı, ethernet gibi sürücülerin tanıtılması gerektiği gibi, işletim sisteminin işlemciyi de tanıması, komut çevriminin mekanizmasını bilmesi gerekir. Program bir komut dizisidir (series of instructions); bu komutlar tek tek işlemciye getirilir, çalıştırılır, gerekirse belleğe geri yazılır. Çalışan birden fazla programa ileride **süreç (process)** diyeceğiz; süreç, programın biraz daha özelleşmiş hâlidir.

## 5. İşletim Sistemine Neden İhtiyaç Var?

Modern bilgisayarlar bir ya da daha fazla işlemciden, bir ana bellekten, disklerden ve yazıcı, modem gibi diğer donanım aygıtlarından oluşur. Sistemde artık tek kullanıcı da yoktur. Bir yanda donanım, diğer yanda kullanıcının doğrudan etkileşimde olduğu uygulamalar (e-posta programı, web tarayıcısı, müzik uygulaması) vardır. İşletim sistemi bu ikisi arasında katman görevi gören, yönetici bir yazılımdır.

Bu görev tarih boyunca hep yazılımla yapılmamıştır. Eskiden büyük sunuculara programlar delikli kartlarla verilirdi ve kullanıcı programını bilgisayara doğrudan veremezdi; arada bir görevli, yani bir insan vardı. "İşletim sistemi" o insandı. O görevli, örneğin birinin 300 birimlik, başka birinin 1 milyon birimlik işini belli bir sıraya koyar. Hoca bunu market kasasına benzetti: Önünüzdeki müşteri bir sürü ürün almış, sizin elinizde tek ürün var; "önüme geç, çok bekleme" denir. Ortalama bekleme süresini azaltmak için yapılan bu planlama işletim sisteminin görevlerinden biridir. Benzer şekilde, bir iş giriş/çıkış (örneğin yazıcıya çıktı alma) beklerken işlemci boşta kalır; işlemci boşta durmasın diye başka birinin işini araya almak da o görevlinin işiydi. Bugün bunu işletim sistemi yazılımları çok daha rahat yapar.

İşletim sistemi ilk başta bir **kaynak yöneticisi** olarak düşünülmüştür: İşlemci, bellek ve farklı kullanıcıların programlarını en uygun şekilde yönetmek. Bir sunucuya birden fazla kullanıcı bağlandığında ise ek bir gereksinim ortaya çıkar. Hoca sınıfa "kendi bilgisayarınızı on kişiye açtığınızı düşünün, ne sıkıntı olabilir?" diye sordu; cevap güvenliktir. Burada güvenlik yalnızca kişisel verilerin korunması değildir. Benim programım da başkasının programı da bellektedir ve C'de pointer ile istediğim bellek bölgesine erişebilirim. İşletim sistemi bir programın başka bir programın bellek uzayına erişememesini garanti altına almalıdır. Bu koruma (protection) da işletim sisteminin görevidir.

## 6. İşletim Sisteminin Tarihçesi

Bilgisayar sistemlerinin kuşakları kabaca şöyle sıralandı:

- **1945-1955:** Vakum tüplü bilgisayarlar.
- **Transistörler ve toplu işlem (batch) sistemleri:** "Batch" toplu işlem demektir. `.bat` uzantılı dosyalarda olduğu gibi, önce bir programın, sonra diğerinin, sonra bir başkasının çalışmasını sağlayan küçük bir ek programla işler toplu hâlde yürütülür.
- **Günümüze doğru:** Kişisel bilgisayarlar, mobil sistemler.

### 6.1 Batch sistemlerde iş akışı

Programcı delikli kartını getirir ve kart okuyucuya verir (slaytta IBM 1401 olarak geçen bir arayüz). Hoca bunu hastanede tahlil vermeye benzetti: Örneği cihaza siz vermezsiniz, görevliye verirsiniz. Kart okuyucu girdiyi teyp sürücüsüne aktarır; bir operatör bu ara çıktıyı asıl bilgisayara verir, bilgisayar işi yapar, çıktı yine teybe ve oradan yazıcıya gider. O dönemin yazıcıları nokta vuruşlu yazıcılardı. Bu sistemde işletim sistemi bir insandır. Programlar Fortran ya da assembly gibi dillerde yazılırdı ve bir iş bitmeden başkasının işi araya giremezdi. Bu yüzden işletim sisteminin görevi kolaydı: Girdiyi al, bilgisayara ver, çıktıyı gönder.

Hoca market örneğini sürdürdü: Kasiyer herkesi en az bekletmek için herkesin ürünlerinden üçer üçer okutursa hesaplar karışır; kimin ne kadar ürününün okutulduğunu not etmesi, yani bir senkronizasyon sağlaması gerekir. Batch sistemlerde böyle bir şey yoktu; günümüz işletim sistemlerinde vardır ve ilerleyen konularda görülecektir.

### 6.2 Çoklu programlama

Çoklu programlama (multiprogramming) sistemlerinde bilgisayar belleğinde işletim sistemine bir yer, her bir işe (job) de ayrı bir bölge ayrılır. Bu, günümüz sistemlerine çok daha benzer bir yapıdır. Artık işletim sisteminin kaynakların paylaşımını (resource allocation) ve güvenliği sağlaması gerekir; yani görevi arttı ve bir evrimleşme gerekti.

## 7. Donanım Özeti ve Bellek Hiyerarşisi

Slayttaki genel şemada bir CPU, bir bellek, aralarında tek çizgiyle gösterilmiş ama içinde adres, kontrol ve veri yollarını barındıran bir bus ve çevresel birimler (peripheral devices) vardır. Kitapta "CPU pipeline" olarak geçen yapı, komut çevriminin (fetch, decode, execute) başka bir adıdır.

Hoca birden fazla programın aynı anda fiziksel olarak çalışmasını ölçekleme (scaling) üzerinden anlattı: Bir iş bir işçiyle 10 birim zamanda yapılıyorsa iki işçiyle 5 birim zamanda yapılır. İşlemciye farklı çekirdekler (core) koyarak, yani işçiyi artırarak bu ölçekleme sağlanır. 10 ya da 20 çekirdekli bir işlemcide birim zamanda 10-20 program komutu çalıştırılabilir. Hoca bunu "superscalar CPU" kavramıyla birlikte andı; çok iş parçacıklı ve çok çekirdekli yongalara ileride dönülecek.

> **Ders sonrası not:** Hoca aynı anda birden fazla programın çalışmasını superscalar CPU'larla ve çekirdek sayısını artırmakla birlikte anlattı. Superscalar, tek bir çekirdeğin aynı saat döngüsünde birden fazla komutu çalıştırabilmesidir; birden fazla programın fiziksel olarak aynı anda çalışmasını sağlayan şey ise çok çekirdekli (multicore) ya da çok işlemcili yapılardır. İki kavram farklıdır.

### 7.1 Bellek türleri

Bellek veriyi saklamak için kullanılan araçtır. Veriyi yalnızca işlemcide ya da diskte tutmayız; farklı kullanım amaçları ve kısıtlar farklı sınıflandırmalar doğurmuştur:

- **Register'lar:** İşlemci içindeki kaydedici bölgeler. Çok hızlıdır ama alan (kapasite) kısıtlıdır.
- **Ana bellek (main memory):** Görece daha yavaş ama daha fazla veri tutar; günümüzde RAM olarak bilinir.
- **Önbellek (cache):** Register ile ana bellek arasını dengelemek için kullanılır. Hocaya göre önbellekler yaklaşık 20 yıl önce bu hiyerarşiye girmiştir.
- **Manyetik diskler, manyetik teypler, katı hal diskleri:** Bunlar yetersiz kaldığında devreye girer.

Bazı bellekler kalıcıdır (manyetik diskler elektrik olmadan da veriyi saklar), bazıları uçucudur (volatile): Register ve cache uçucudur; ana bellek de bilgisayar kapatıldığında sıfırlanır.

### 7.2 Disk yapısı

Eski disklerin yapısını hoca üst üste dizilmiş 500 CD'ye benzetti: Ortada bir mil vardır, plakalar sürekli döner ve bir okuma-yazma kafası diskteki veriyi alıp ana belleğe, oradan işlemciye götürür. Burada mekanik bir düzenek vardır ve işletim sisteminin bu mekanizmayı bilmesi gerekir. Onlarca çeşit aygıt olduğu için işletim sistemi bunları tek başına bilemez; aygıt sürücüleri (device driver) denen ek yazılımlarla ara katmanlar oluşturur.

Okuma-yazma kafası manyetorezistif bir yapıdadır: Kafadaki direnç üzerinden bir gerilim ya da akım bilgisi alınır, bu analog bilgi 0 ve 1'lere dönüştürülür ($V = I \cdot R$ ilişkisine dayanır). Bu yüzden sabit diskler bir darbe ya da manyetik alan etkisiyle kolay bozulur: Kafadaki direnç ya da disk yüzeyindeki yapı bozulursa veri doğru okunamaz.

## 8. Derleyici ve Emülatör Gösterimi

### 8.1 Compiler Explorer

Aradan sonra hoca Compiler Explorer'da (godbolt.org) basit bir C kodu gösterdi (ekrandan, 01:03:10):

```c
#include <stdio.h>
// Type your code here, or load an example.
int square(int num) {
    //printf("%d",num);
    return num * num;
}
```

Bu kod önce x86-64 gcc ile, sonra MIPS clang ile derlendi ve iki işlemci için farklı assembly çıktısı oluştu. Derleyici kodu hangi işlemciye çevireceğini bilir. Ama programın ve verinin belleğin neresinde tutulacağı (Harvard mı, Von Neumann mı, ikisinin birleşimi mi; günümüzde ikisinin iyi yanlarını alan hibrit sistemler vardır) ve bu mekanizmanın yönetimi işletim sisteminin idaresindedir.

### 8.2 Mikroişlemci emülatörü

Hoca, bu dönem mikroişlemciler dersinde kullanılacak emu8086'nın çok daha basit bir hâli olan bir emülatörde "Büyük Sayı - Küçük Sayı" programını çalıştırdı (ekrandan, 01:05:40). Emülatörün belleğindeki program şöyledir:

```text
000: MOV R1,08
001: MOV R2,09
002: CMP R1,R2
003: JGE 06
004: SUB R2,R1
005: JMP 07
006: SUB R1,R2
007: HALT
```

Program çalıştırıldığında belleğe yüklenir ve PC'nin gösterdiği adresten komutlar sırayla gelir. Fetch aşaması tek adımda olmaz: PC'deki değer **MAR (memory address register)**'a yazılır; MAR'dan adres yolu üzerinden belleğe gidilir; bellekten gelen komut **MBR (memory buffer register)**'a alınır; MBR'den komut kaydına (IR) geçer ve decode edilir. Decode çok daha karmaşık bir işlemdir. Ardından execute gelir. Toplamada elde, çıkarmada ödünç oluşabilir; bunlar bayraklara yansır. Ekranda CF (carry), OF (overflow), ZF (zero) ve SF (sign) bayrakları görülür. Emülatörün işlem kaydında "Komut IR'dan ALU'ya yüklendi", "Control bus okuma moduna ayarlandı", "Operant adresi adres busa yerleştirildi", "İlgili adresteki veri data busa yerleştirildi", "Operant ALU'ya alındı", "Registara veri yazıldı" gibi adımlar listelenir. Program 007 adresindeki `HALT` ile durur.

Hoca burada şu soruyu açtı: İkinci satırı çalıştırırken başka bir program acilen işlemciye girmek isterse (tek işlemci olduğunu varsayalım) ne olur? Benim programımın yarıda kesilmesi gerekir; market kasasında işleminizin yarıda kesilmesi gibi. O ana kadarki ilerleme ve değişkenlerin değerleri bir yerde saklanmalı, araya giren programın işi bitince kaldığım yerden devam etmeliyim. Bu saklamayı işletim sistemi düzenler. Tek programda iş bu kadar karmaşıksa, çok sayıda program ve kullanıcıyla, hele çok işlemcili sistemlerde karmaşıklık çok daha fazladır.

## 9. G/Ç Aygıtları, Buslar ve İşletim Sisteminin Yaşam Alanları

G/Ç (I/O) aygıtları çok çeşitlidir: yazıcı, tarayıcı, mikrofon, hoparlör, kamera ve daha birçoğu. İşletim sistemi her birinin mekanizmasını kullanabilmelidir. Gerçek sistemde bus yapısı üç çizgiden ibaret değildir: CPU içinde ve dışında önbellekler vardır, önbellekler arasında cache bus, ana bellekle bağlantıda memory bus bulunur. Aradaki bağlantı doğrudan kurulmaz; araya yerel buslar (local bus) girer ve modem, ses kartı, yazıcı, USB sürücüsü gibi aygıtlar bunlar üzerinden sisteme dahil olur. Örneğin USB'deki bir Word dosyasını açtığınızda dosya belleğe yüklenmeli; yazım denetimi yaparken bile veri işlemciye girmelidir.

> **Hocanın vurgusu:** En önemli üç kaynak işlemci, ana bellek ve bus'tır. Diğer bütün aygıtlar sisteme dahil olabilmek için bu üçüne muhtaçtır.

İşletim sistemlerinin "yaşam alanları" (habitat) da farklıdır:

- **Mainframe'ler:** Buzdolabı büyüklüğünde, ciddi soğutma gerektiren, yüzlerce kullanıcılı sistemler.
- **Sunucular (server):** Günümüzde daha küçük ölçekli, kendilerine özel işletim sistemleri olan makineler.
- **Bulut ve dağıtık sistemler:** Google Drive gibi hizmetler gerçekte bir yerdeki fiziksel bilgisayarlarda, dağıtık bir yapıda çalışır.
- **Mobil işletim sistemleri, IoT aygıtları, akıllı kartlar, gerçek zamanlı sistemler:** Her birinin kendi yapılandırmasına uygun bir işletim sistemi vardır.

Stallings'in slaytındaki daha ayrıntılı şemada işlemcinin içinde PC, MAR, MBR, IR (instruction register) ve yürütme birimi, dışında ana bellek ve G/Ç modülleri görülür. G/Ç modüllerinin de kendi yerel buffer'ları olmalıdır. Klavyeden basılan bir tuş işlemciye hemen gitmez; bus tahsis edilene kadar buffer'da bekler. Bu buffer'ların da yönetilmesi gerekir.

### 9.1 Neden "x86"?

Hoca sınıfa x86 adının nereden geldiğini sordu. Günümüz Intel tabanlı işlemcilerin atası 8086'dır (8 bitlik 8085 de vardır). 8086'nın kendisi 16 bitliktir; onun devamı olan işlemciler 32 bittir ve normalde "x32" denebilecekken ataya saygıdan "x86" denmiştir. Sonra yine aynı mimari üzerine 64 bitlik x64 işlemciler çıktı. Gömülü sistemlerde karşılaşılacak Atmel ve bazı Arduino işlemcileri Harvard mimarisine yakındır; ama modern işlemciler iki mimarinin iyi taraflarını alan melez yapılardır, kesin bir ayrım yapılamaz. Ekran kartlarındaki GPU'lar da bir kaynaktır; derin öğrenme gibi işlerde program GPU'da çalıştırılır ve işletim sistemi bu kaynağı nasıl yöneteceğine de karar verir.

## 10. Komut Çevrimi Durum Diyagramı

Slaytta kesme olmayan durum için komut çevriminin durum diyagramı gösterildi (ekrandan, 01:16:00). Bu, bir sistemde tek bir programın çalıştığı ve o program bitene kadar başka kimsenin araya giremediği senaryodur. Diyagramdaki adımlar şunlardır:

```text
Komut adresi hesaplama  ->  Komut getirme (instruction fetch)
  ->  Komut işlemini çözme (instruction operation decoding)
  ->  Operand adresi hesaplama  <->  Operand getirme   (birden çok operand olabilir)
  ->  Veri işlemi (data operation)
  ->  Operand adresi hesaplama  <->  Operand saklama   (birden çok sonuç olabilir)
  ->  Dizi/vektör verisi ise: operand adresi hesaplamaya dön
  ->  Komut tamamlandı: sonraki komutu getirmek için komut adresi hesaplamaya dön
```

**Komut adresi hesaplama:** PC'nin göstereceği adres hesaplanır. Bu genellikle "+1" şeklindedir ama her zaman öyle olmaz. Program çalışırken bir fonksiyon çağrısı yapılırsa, fonksiyon belki 300. satırdadır; 300, 301, 302 diye devam edilip sonra kalınan yere dönülmelidir. Bu hesaplamada yığın belleği (stack memory) de işin içindedir.

**Operand getirme:** `MOV AX, 5` komutu çözüldüğünde AX zaten işlemcinin içindedir, 5 de bilinen bir sayıdır; belleğe tekrar gitmek gerekmez. Ama hoca şöyle bir komut düşündü: AX'in gösterdiği bellek adresine (örneğin AX'te 300 varsa bellekteki 300 adresine) 5 numaralı bellek adresindeki değeri yaz. Bu durumda komutu getirmek için bir kez, 5 numaralı adresteki veriyi getirmek için bir kez daha gidilir (ikisi de okuma); üçüncü kez de bu veriyi AX'in gösterdiği yere yazmak için gidilir. Yani üç bellek erişimi yapılır. Hoca böyle bir komutun 8086'da geçerli olmayabileceğini, mantığı göstermek için verdiğini belirtti.

> **Ek bilgi (derste anlatılmadı):** x86 mimarisinde `MOV` komutu iki operandının ikisinin birden bellek olmasına izin vermez; bellekten belleğe kopyalama için önce bir register'a almak ya da `MOVS` gibi dizi komutlarını kullanmak gerekir. Hocanın örneği bu yüzden kavramsaldır.

**Operand adresi hesaplama** de basit değildir: AX'in gösterdiği yerin gerçekte neresi olduğunu bulmak gerekir. Bu konu bellek yönetiminde, korumalı mod (protected mode) ile birlikte ayrıntılı ele alınacak. Dizi şeklinde bir veride, örneğin bir döngüyle blok aktarım yapılırken, bu adımlar yeni komuta geçilene kadar tekrarlanır.

## 11. Kesmeler (Interrupts)

### 11.1 Kesme nedir?

"Interrupt" bir şeyin araya girmesi, akışın kesilmesi, durdurulması anlamındadır. Belli bir program çalışırken başka bir etkenin bu programın çalışmasını durdurmasıdır.

**Soru:** Bir program neden başka bir etken tarafından durdurulur? Sınıftan "sonsuz döngü" cevabı geldi. **Cevap:** Hoca buna exception (istisna) dendiğini söyleyip asıl iki nedeni anlattı. Birincisi, bir süreç çalışırken daha acil bir süreç işlemciyi kullanmak isteyebilir; o zaman aciliyeti ve önemi düşük süreç işlemciden çıkarılır, daha yüksek öncelikli süreç işlemciyi kullanır. İkincisi giriş/çıkıştır.

Hoca ikinci nedeni Compiler Explorer'daki koda `printf("%d",num);` satırını açarak anlattı. Ekrana yazmak için değişkeni alıp doğrudan ekran kartına gönderemeyiz. Veri bus'a girecek, bus'tan ekrana gönderilecektir. Önce bus'ın uygunluğu kontrol edilir; uygun değilse veri buffer'da bekletilir. Hoca bunu bir trene benzetti: Yol doluysa tren yola giremez. Bir G/Ç işlemi yaparken süreç aslında işlemcide değildir; işlemci boştadır, hiçbir çalıştırma yoktur. Bu durumda sürecin işlemciden çıkarılması için bir kesme (bir tür sinyal) gönderilir ve başka bir süreç işlemciye alınır. Amaç işlemci kullanımını (**CPU utilization**) artırmaktır.

### 11.2 Kesme kontrolü ne zaman yapılır?

Kesmeli durum diyagramında komutun sonunda bir **kesme kontrolü (interrupt check)** adımı vardır. Bir komut getirilmiş, çözülmüş ya da çalıştırma aşamasına geçilmişken kesme kabul etmemek en makul olandır; kabul edilirse sonraki seferde fetch ve decode baştan yapılmak zorunda kalınır. Bu yüzden komut tamamlanana kadar kesme bekletilir; komut bittiğinde kesme oluşmuşsa önce kesme işlenir, sonra programa devam edilir.

Bu kural her zaman geçerli değildir. İlk dönemlerde "kesme gelirse mevcut komut bitene kadar bekler, anında yanıt (immediate response) yoktur" denmiştir ve kişisel bilgisayarlarda ve birçok sunucu sisteminde bu mantık hâlâ sürer. Fakat gerçek zamanlı sistemlerde ve endüstriyel otomasyonda kullanılan PLC'lerde anında yanıt vardır: İstek geldiğinde komutun devam etmesine izin verilmeden komut yarıda kesilir. Sonraki adımda komut ya baştan başlar ya da komutun yığın durumu belli bir noktaya kadar korunabiliyorsa saklanır ve kesmeye yanıt verildikten sonra devam edilir.

> **Hocanın vurgusu:** Bilgisayar sistemlerinde bazı şeyler için "kesin böyledir" denemez. 40 yıl önce böyle olan bir şey, yeni gereksinimlerle bugün farklı olabilir.

### 11.3 Kesme güdümlü işletim sistemleri

Günümüz işletim sistemleri kesme güdümlüdür (interrupt driven). Çok sayıda işlemci, çekirdek, kullanıcı, program ve süreç vardır; işlemcinin boşta kalma olasılığı yüksektir. İşlemciyi boş bırakmamak ve CPU kullanımını yüksek tutmak için sistem kesmelerle sürekli kontrol edilir. Bir sınıf arkadaşının belirttiği gibi, bir programın kesilmesini istemiyorsak kesmeleri geçici olarak kapatabiliriz; ancak bu sistemin CPU kullanımını düşürür.

**Soru:** CPU kullanımı düşerse kişisel bilgisayarlarda nasıl bir etki görürüz? **Cevap:** Sınıftan "görüntü kasar" cevabı geldi. Hoca oyun örneğiyle onayladı: CPU anında tahsis edilemez, sürekli gecikme ve yığılma olur; trafiğe benzer. Oysa işlemci aslında boştadır.

Hoca bunu bir deneyle somutlaştırdı: Bir milyon elemanlı bir diziyi rastgele sayılarla doldurun, ekrana yazdırın, sıralayın ve tekrar yazdırın. Sıralama CPU için hiçbir şeydir: Saniyede yaklaşık bir milyar işlem yapan bir işlemcide, en kötü durumda $n^2 = (10^6)^2 = 10^{12}$ işlem yaklaşık $10^{12} / 10^9 = 1000$ saniyede biter. Ama bir milyon veriyi ekrana yazdırmak çok daha uzun sürer; hocanın tahminiyle on dakika kadar. Bu sürede programınız işlemciyi meşgul ederse diğer programlar etkilenir; çünkü sizin işiniz işlemciyle değil ekranladır. İşletim sistemi bu yüzden kesmeleri açıp kapatmayı eski bir usul olarak kullanmıştır; hocaya göre kesmelerin açık kalması kapalı kalmasından daha iyidir.

### 11.4 Kesmesiz program akışı

Slayttaki "Flow of Control Without Interrupts" şekli (ekrandan, 01:28:30) bir kullanıcı programını ve bir G/Ç programını gösterir. Kullanıcı programında 1, 2, 3 numaralı kod parçaları arasında `WRITE` çağrıları vardır; G/Ç programında 4 numaralı hazırlık kodu, "I/O Command" ve 5 numaralı bitiş kodu (END) bulunur.

Bir fonksiyon çağrısı ya da `printf` gibi bir G/Ç işlemi yapıldığında o andaki program adresi yığın belleğe kaydedilir, fonksiyonun adresi PC'ye yazılır ve oradan devam edilir. Hocanın örneğinde çağrı 4. satırda, fonksiyon 300. satırdadır: 300, 301, 302, 303 diye ilerlenir; fonksiyon bitince yığından 4 çekilir ve program 4, 5, 6, 7 diye kaldığı yerden sürer. Başka bir G/Ç çağrısında (örneğin 600. satırdaki bir fonksiyon) aynı şey tekrarlanır. Kesme olmadan program fonksiyonlarla, `printf` ve `scanf`'lerle böyle çalışır ve biter.

Buna G/Ç bekleme süresi eklendiğinde, G/Ç işleminin başlatılması için küçük bekleme aralıkları (latency) oluşur; bu aralıklarda işlemci boştadır, yani boşa geçen zamandır. G/Ç beklemesi uzadıkça işlemci daha uzun süre boş kalır.

## 12. İşletim Sisteminin Tanımı, Amaçları ve Görevleri

### 12.1 Tanım

Eski kitaplarda ya da internette işletim sistemi genellikle "kullanıcı ile bilgisayar arasında iletişim kuran yazılım" olarak tanımlanır. Slayttaki tanım da budur: "Bilgisayarın kullanıcısı ile bilgisayar donanımı arasında aracılık eden bir program" (ekrandan, 01:32:00). Hocaya göre bu tanım doğrudur ama eksiktir; işletim sisteminin ilk çıktığındaki görevi budur, zamanla beklentiler farklı boyutlara ulaşmıştır.

Slayttaki amaçlar (ekrandan, 01:32:00):

- Kullanıcı programlarını çalıştırmak ve kullanıcı problemlerini çözmeyi kolaylaştırmak.
- Bilgisayar sistemini kullanışlı (convenient) hâle getirmek.
- Bilgisayar donanımını verimli kullanmak.

Kullanıcı donanımın mekanizmasını, işlemcinin ve busların neye göre çalıştığını, derleme ve çalıştırmanın nasıl yapıldığını bilemez. İşletim sistemi bunları onun adına yapar. Bunu yaparken donanımı en uygun şekilde kullanmalıdır: "Çok güzel bir işlemcim var ama ondan faydalanamıyorsam kötü bir durumdur."

### 12.2 Ayrıntılı amaçlar

Hoca başka bir kaynaktan aldığı daha kapsamlı listeyi anlattı:

- Bilgisayar ile kullanıcı arasındaki iletişimi kolaylaştırmak.
- Bilgisayar sisteminin bileşenleri arasındaki iletişimi kolaylaştırmak (işlemci ile G/Ç aygıtı, bellek ile G/Ç aygıtı).
- Verimi artırmak: Birim zamanda elde edilen çıktıyı, yani **throughput**'u en üst düzeye çıkarmak; CPU, bellek ve bus kullanımını olabildiğince artırmak.
- Bir kullanıcının işini yapması için gereken zamanı en aza indirmek.
- Çok kullanıcılı ya da çok programlı sistemlerde kaynakları optimize etmek. Tek program olsa o program işini en kısa sürede bitirip çıkardı; iş çoğullaşınca optimizasyon gerekir.
- Kaynakların hesabını tutmak: CPU gibi bellek ve diskler de tahsis edilir. Hangi sürece, hangi veriye bellekte ya da diskte neresinin tahsis edildiği izlenmeli, başkasının oraya girmesi engellenmelidir. Bir süreç başka bir sürecin adres uzayına giremez, müdahale edemez. Bu konular bellek ve disk yönetiminde ayrıntılı görülecek.
- Bilgisayar sistemini güvenli kullanmayı sağlamak: Bir kullanıcı diğerinin hesabına girememelidir. En basitinden bir şifreleme sistemi ya da klasör koruma sistemiyle bu güvence altına alınır.
- Olası sistem sorunlarını ve kaynak kullanımını izlemek (monitoring).

Hoca bu listeye bilgisayarlar arasındaki iletişimi de ekledi. Bir web sayfasına bağlanmak istediğinizde, o sitenin kurulu olduğu bilgisayardaki bir sürece bağlanırsınız; sizden oraya istek gider, oradan size cevap gelir. Bunun için önce sitenin IP adresi bulunmalıdır. Bu adresi DNS sunucusu verir: DNS, "www" ile başlayan bir adrese karşılık gelen IP adresini döndüren sözlük benzeri bir servistir. Tarayıcıya adres yazdığımızda DNS'i biz çalıştırmayız; tarayıcı arka planda işletim sisteminin DNS servisini kullanır. Hoca Windows'taki "Hizmetler" (Services) listesinde DNS Client servisini gösterdi. Bu servis kapatılırsa ve tarayıcının kendine ait bir yapılandırması yoksa adres çözümlenemez; internet olduğu hâlde internete çıkılamaz. Benzer şekilde, gelen cevabın size ulaşması için sizin de bir IP adresiniz olmalıdır; bu adresi modem atar ve bilgisayar bunu DHCP istemcisi servisi üzerinden alır. Bunların hepsi işletim sisteminin görevleri arasındadır.

### 12.3 Bilgisayar sisteminin yapısı

Bilgisayar sistemi şu bileşenlerden oluşur:

- **Donanım:** bellek, işlemci, G/Ç aygıtları ve buslar.
- **İşletim sistemi:** Kullanıcılar ve kullanıcı uygulamaları ile donanım arasındaki kontrolü ve koordinasyonu sağlar. Kontrol kaynakların yönetimi içindir; koordinasyon süreçlerin yönetimi içindir.
- **Uygulama programları:** kelime işlemci, derleyici, web tarayıcısı, veritabanı sistemi, oyun.
- **Kullanıcılar:** insanlar, başka makineler ya da başka bilgisayar sistemleri.

Koordinasyona örnek olarak hoca ağ iletişimini verdi: Bir yerden bir yere bağlanmanın belli bir prosedürü vardır (gelecek dönem veri iletişimi dersinde görülecek yedi katmanlı OSI modeli gibi). Bu prosedürün bilgisayar üzerindeki koordinasyonunu işletim sistemi sağlar. Tarayıcılar en tepedeki uygulama yazılımlarıdır; aşağıdaki süreçler işletim sistemince kontrol ve koordine edilir.

Katmanlı şemada en altta donanım, onu saran işletim sistemi, onun üstünde sistem ve uygulama yazılımları ve en üstte kullanıcılar vardır. Modern sistemlerde kullanıcı donanıma doğrudan erişme yetkisine sahip değildir. Eskiden erişilebiliyordu, ama bunun özellikle çok kullanıcılı sistemlerde birçok dezavantajı vardı. Sistem yazılımları işletim sisteminin biraz üzerindedir ama tamamen kullanıcıya ait değildir; örneğin diske format atan yazılım bir sistem yazılımıdır. İşletim sisteminin içinde onun çekirdeği (kernel) bulunur.

### 12.4 Bakış açısına göre işletim sistemi

- **Kullanıcı açısından:** Kolay kullanım ve iyi performans yeterlidir. Hangi CPU'nun tahsis edildiği, kaç iş parçacığının çalıştığı, hangi busların kullanıldığı kullanıcıyı ilgilendirmez.
- **Çok kullanıcılı sistemlerde:** Bütün kullanıcıları memnun etmek gerekir; bu da işletim sistemine ek görevler yükler.
- **Adanmış iş istasyonları (workstation):** Kaynakların paylaşımını sağlamalıdır.
- **El bilgisayarları (handheld):** Kaynakları zayıf ve belli bir amaç için tasarlanmıştır; işletim sistemi bataryayı çok iyi kullanmalıdır, çok yüksek performans beklenmez.
- **Gömülü bilgisayarlar (Raspberry Pi, Arduino gibi):** Kullanıcı arayüzü çok kısıtlıdır; arka planda hesaplama ağırlıklı işler yapar.

### 12.5 Kaynak tahsis edici ve kontrol programı

İşletim sistemi bir **kaynak tahsis edicidir (resource allocator)**: Özellikle donanım kaynaklarını yönetir, bunların uygulamalara ve kullanıcılara verimli ve adil dağıtılmasına karar verir, olası çatışmaları çözer ve bunun için mekanizmalar geliştirir. Hoca ileride (7. ya da 8. bölümde) anlatılacak ölümcül kilitlenme (deadlock) kavramını örnek verdi; işletim sistemleri bu konuda zaman içinde farklı mantıklar kullanmıştır.

İşletim sistemi aynı zamanda bir **kontrol programıdır (control program)**: Programlarda oluşan hataları önler ve bilgisayar sisteminin uygunsuz kullanımının önüne geçer. Bir süreç başka bir sürecin adres uzayına erişemez; bir süreç başka bir süreci işlemciden çıkaramaz. İşlemciye doğrudan sahip olsaydım başka bir süreci işlemciden çıkarabilirdim; işletim sistemi bunu engeller. Aynı şey bellek ve G/Ç aygıtları için de geçerlidir.

### 12.6 Kesin bir tanım yok

> **Hocanın vurgusu:** İşletim sisteminin "mutlaka budur" denebilecek kesin bir tanımı yoktur; tanım bakış açısına, kullanım alanına ve beklentiye göre değişir.

Eskiden donanım satın alındığında işletim sistemi de onunla birlikte gelirdi ve çok önemli görülmezdi. Günümüzde işletim sistemi donanımdan çok daha bağımsızdır ve ayrıca satılabilir. Bu, işletim sisteminin misyonunun zamanla değiştiğini gösterir. Bilgisayarı açtığımızda çalışan şey aslında işletim sisteminin çekirdeğidir (kernel). Örneğin Linux aslında bir işletim sistemi değil bir çekirdektir; onun farklı sürümleri (dağıtımları) işletim sistemi olur. Çekirdek dışındaki her şey ya sistem programı ya da uygulama programıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:00): Bir bilgisayar sisteminde işlemci ile belleği bağlayan buslar kaç türlüdür ve görevleri nelerdir?

> **Çözüm:** Üç türlüdür. Adres yolu bellekteki adresi gösterir; veri yolu bellekten gelen ya da belleğe yazılan veri ve komutları taşır; kontrol yolu işlemin okuma mı yazma mı olduğunu belirtir.

**Soru 2** (derste sözlü, 00:26:00): Bir komutun çalıştırılması hangi aşamalardan oluşur?

> **Çözüm:** Komut çevrimi: getirme (fetch), çözme (decode), çalıştırma (execute) ve gerekiyorsa sonucu belleğe geri yazma (write back).

**Soru 3** (ekrandan, 00:25:00): `MOV AX, 5`, `ADD AX, 5`, `MOV [1234], AX` programı çalıştığında hangi bellek erişimleri yapılır ve sonuçta 1234 adresinde ne bulunur?

> **Çözüm:** Her komut için PC'nin gösterdiği adresten bir okuma (fetch) yapılır, yani üç komut okuması olur. İlk iki komut işlemci içinde çalışır: AX önce 5, sonra 10 olur. Üçüncü komutta kontrol yolundan yazma sinyali gönderilir ve AX'teki 10 değeri 1234 adresine yazılır.

**Soru 4** (derste sözlü, 00:37:00): Bir bilgisayarı on kullanıcıya açtığınızda, programları çalıştırmak dışında işletim sisteminden ek olarak ne beklenir?

> **Çözüm:** Güvenlik ve koruma. Yalnızca kişisel verilerin korunması değil, bir programın başka bir programın bellek uzayına erişememesinin de garanti altına alınması gerekir.

**Soru 5** (derste sözlü, 01:13:00): Intel tabanlı işlemcilere neden "x86" denir?

> **Çözüm:** Günümüz Intel tabanlı işlemcilerin mimari atası 8086'dır. Sonraki 32 bitlik işlemciler bu atanın adını yaşatmak için x86 diye anılmıştır; 64 bitlik devamları x64'tür.

**Soru 6** (derste sözlü, 01:20:00): Çalışan bir program neden başka bir etken tarafından durdurulur?

> **Çözüm:** Daha yüksek öncelikli bir süreç işlemciyi istediğinde düşük öncelikli süreç işlemciden çıkarılır. Ayrıca süreç G/Ç yaparken işlemci boşta kalacağından, CPU kullanımını artırmak için süreç bir kesmeyle işlemciden çıkarılır ve başka bir sürece yer açılır. Sonsuz döngü gibi hata durumları ise exception olarak anılır.

**Soru 7** (derste sözlü, 01:26:00): CPU kullanımı düşerse kişisel bilgisayarda nasıl bir etki görülür?

> **Çözüm:** Görüntü takılır, örneğin oyunda sürekli donmalar yaşanır; CPU sürece anında tahsis edilemez, gecikme ve yığılma oluşur. Oysa işlemci aslında boştadır.

## Dersin Toparlaması

Bu ilk derste işletim sisteminin neden gerekli olduğu, donanımın temel bileşenlerinden başlanarak kuruldu. İşlemci, bellek ve üç tür bus ile bir programın komut çevrimi (fetch, decode, execute, write back) içinde nasıl çalıştığı, Von Neumann ve Harvard mimarileri, bellek hiyerarşisi ve aygıt sürücüleri ele alındı. Tarihçe, işletim sistemi görevinin batch sistemlerdeki insan operatörden çoklu programlamaya ve kaynak paylaşımı ile korumayı üstlenen yazılımlara nasıl geçtiğini gösterdi. Kesmeler, daha öncelikli işlerin ve G/Ç beklemelerinin işlemciyi boşa harcatmaması için kullanılan temel mekanizma olarak tanıtıldı.

Ders, işletim sisteminin kesin bir tanımının olmadığı, kaynak tahsis edici ve kontrol programı olarak iki temel rolü bulunduğu ve bilgisayar açıldığında çalışan çekirdeğin işletim sisteminin özü olduğu vurgulanarak kapandı. Hoca sonraki derste aynı slaytlardan devam edileceğini ve işletim sistemi servislerinin ayrıntılı ele alınacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
