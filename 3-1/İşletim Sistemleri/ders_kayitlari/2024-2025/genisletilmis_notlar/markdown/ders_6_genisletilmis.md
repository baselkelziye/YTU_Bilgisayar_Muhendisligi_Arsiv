# Ders 6 Genişletilmiş Notu: Prosesler Arası Haberleşme (IPC): Paylaşımlı Bellek, Mesaj Geçirme, Pipe'lar, Soketler ve RPC

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Prosesler Arası Haberleşme?
- 2. İki Temel Model: Mesaj Geçirme ve Paylaşımlı Bellek
- 3. İşbirlikçi Prosesler
- 4. Üretici-Tüketici Problemi ve Sınırlı Tampon
- 5. Mesaj Geçirme Sistemi
- 6. Doğrudan ve Dolaylı Haberleşme
- 7. Eşzamanlama: Bloklayan ve Bloklamayan İşlemler
- 8. Tamponlama
- 9. IPC Sistem Örnekleri: POSIX, Mach, Windows
- 10. İstemci-Sunucu Haberleşmesi: Soketler, RPC ve Pipe'lar
- 11. URL: Web'de IPC'nin Soyutlaması
- Örnek Sorular
- Dersin Toparlaması

## 1. Neden Prosesler Arası Haberleşme?

Önceki uygulamada `fork` ve `exec` ile ilgili örnekler yapılmıştı. Bu derste prosesler konusunun devamı olan prosesler arası haberleşme (interprocess communication, IPC) işlendi.

Bir proses oluşturulduğunda kendisine ait bir bellek bölgesi ve bazı kaynaklar olduğunu biliyoruz. Ama proses yürütme sırasında başka şeylere de ihtiyaç duyabilir; kendisine ayrılan bellek ve kaynaklar her zaman yeterli olmaz. Yetiyorsa bu bağımsız (independent) bir prosestir. Başka kaynaklardan ek veri ya da kaynak gerekiyorsa birliktelik, yani haberleşme ve işbirliği (cooperation) gerekir. Birlikte çalışan (cooperating) prosesler başka proseslerden etkilenebilir ya da başka prosesleri etkileyebilir. Bunun en sık görülen biçimi veri paylaşımıdır.

Hoca iki örnek verdi:

- **Veritabanı:** Veritabanı yönetim sistemi olarak PostgreSQL kullandığımızı düşünelim. pgAdmin tamamen bir arayüzdür ve veritabanı yönetim sistemiyle doğrudan ilgisi yoktur. Veritabanı yönetim sistemi bir proses, pgAdmin başka bir prosestir. "Tablo oluştur" isteği arka planda veritabanı yönetim sistemine gönderilir ve bir cevap gelir; iki farklı proses haberleşir.
- **WhatsApp:** Olayı tek bir bilgisayardan genelleştirirsek, WhatsApp kendi telefonunuzda bir proses, arkadaşınızın WhatsApp'ı onun telefonunda başka bir prosestir. Oluşturduğunuz mesaj ağ üzerinden karşı taraftaki prosese gönderilir. Bu haberleşmeler IPC araçları, yani işletim sistemi servisleri sayesinde gerçekleşir.

IPC'ye neden ihtiyaç vardır?

- **Bilgi paylaşımı (information sharing):** Her proses bir işi tek başına yapmaya yetmez; ya paylaşan ya da paylaşılan taraf olursunuz.
- **Hesaplamayı hızlandırma (computation speedup):** İş bölümü yapıldığında hesaplama hızlanabilir.
- **Modülerlik:** Bilgisayar biliminin her alanında vazgeçilmezdir; bir prosesin bütün işleri yapması yazılım mühendisliği ilkelerine de aykırıdır.
- **Kolaylık (convenience).**

## 2. İki Temel Model: Mesaj Geçirme ve Paylaşımlı Bellek

Proseslerin haberleşmesi için iki temel yaklaşım ya da model önerilmiştir; bunlar birer algoritma değildir: **paylaşımlı bellek** (shared memory) ve **mesaj geçirme** (message passing). Bu modellerin altında farklı araçlar ve teknikler geliştirilmiştir.

Slayttaki şemada (ekrandan, 00:09:00) A ve B prosesleri aynı bilgisayarın belleğinde çizilmiştir. Hoca bunun daha genel düşünülebileceğini, B'nin başka bir bilgisayardaki bir proses de olabileceğini, mekanizmanın ve mantığın aynı kaldığını söyledi.

- **(a) Mesaj geçirme:** İşletim sistemi çekirdek düzeyinde mesaj gönderen ve alan için bir veri yapısı tutar; şemada bu bir mesaj kuyruğudur (message queue: m0, m1, m2, m3, ..., mn). Bir proses mesaj oluşturur, mesaj çekirdekteki kuyruğa aktarılır ve diğer proses oradan okur. İletişim her zaman A'dan B'ye tek yönlü olmak zorunda değildir; B'den A'ya da olabilir. Burada kullanıcı modundan çekirdek moduna geçiş vardır. Mesajların okunup yazılması çekirdek tarafından yönetildiği için kullanımı kolaydır ve bazı avantajları vardır.

  **Soru:** Mesaj geçirmenin bir dezavantajı olabilir mi? **Cevap:** Kullanıcı modundan çekirdek moduna geçiş bir dezavantajdır; bu geçiş istendiği anda bedavaya yapılamaz. Mesaj geçirmeye dayanan yöntemler çekirdek moduna geçiş gerektirir.

- **(b) Paylaşımlı bellek:** Çekirdek devrede değildir; iki proses için ortak kullanıma uygun bir bellek bölgesi oluşturulup tahsis edilir. Hangi proses oraya yazacak, hangisi oradan okuyacak, kendi aralarında anlaşırlar. Hoca bunu ortak bir posta kutusuna benzetti: biri oraya bırakır, diğeri oradan alır.

Mesaj talep üzerine de oluşturulabilir: A'nın "B'ye göndereyim" demesi gerekmez; B, A'dan bir veri isteyebilir. Örneğin bir SQL sorgusu hazırlayıp veritabanı yönetim sistemine gönderirsiniz ve size bir sonuç döner.

Paylaşımlı bellekte şöyle bir sorun vardır: A'nın mesajını yazması zaman alır. B'nin, mesajın tamamen yazıldığından emin olduktan sonra okumaya başlaması gerekir; bu bir yöntemdir. Ya da A bir yandan üretip yazarken B bir yandan yazılmış olanları tüketebilir; hoca bunu bir fabrikadaki üretim bandına benzetti. Bunlar farklı alt tekniklerdir; bu yüzden bunlara model denir ve altlarındaki teknikler ve algoritmalar sonraki konularda görülecektir.

## 3. İşbirlikçi Prosesler

Bağımsız proses, başka bir prosesin çalışmasından etkilenmeyen ve başka bir prosesi etkilemeyen, kaynak alışverişi olmayan normal bir prosestir. Hoca önceki uygulamadaki `fork` örneğini hatırlattı: Bir noktaya kadar parent çalışır, sonra parent ve çocuk birlikte çalışır, çocuk işini bitirince bir sinyal gönderir. Bu aralıkta parent ile çocuk arasında hiçbir haberleşme yoksa, neden iş parent ve çocuk diye bölündü? Biri bir işi, diğeri ondan bağımsız başka bir işi yapacaksa bir eksiklik vardır; bu eksiklik IPC ile kapatılır: "Sen çocuk olarak işin şu kısmını yap ve sonucu bana gönder, ben de onu kullanayım."

Hocanın örneği: Parent prosesin görevi bir dosyayı açıp verileri bir öğrenci yapısı (structure) dizisine okumak olsun. Parent diziyi çocuğa gönderir; çocuğun görevi yalnız diziyi sıralamaktır. Sıralanmış dizi parent'a geri gelir. Başka bir çocuk da veriyi yeniden dosyaya yazar. Parent yalnız aradaki işleri koordine eder. Bunlar ayrı proseslerdir ve veri aralarında IPC ile gidip gelir; bunlara **işbirlikçi prosesler** (cooperating processes) denir.

**Soru:** Haberleşen proseslerin parent-child ilişkisi olması gerekir mi? **Cevap:** Gerekmez; teorik olarak birbirinden bağımsız herhangi bir X prosesi ile Y prosesi haberleştirilebilir. Ama aralarında mantıklı bir ilişki olmalıdır.

## 4. Üretici-Tüketici Problemi ve Sınırlı Tampon

### 4.1 Paradigma

Haberleşmeyle ilgili bazı kavramsal problemler tanımlanmış ve literatüre girmiştir; bunların çözümleri pek çok farklı probleme uyarlanabilir. Hoca bir e-ticaret uygulamasından sipariş vermeyi örnek verdi: Satıcının ürünü üretip veritabanında bir yere yazması, sizin de sipariş oluşturup o ürünü tüketmeniz gerekir. Otobüs bileti almak da öyledir: biri bir kaynak üretir, siz tüketirsiniz. Hoca bu **üretici-tüketici** (producer-consumer) yaklaşımının bu tür uygulamaların yüzde 95'inde aynı mantıkla karşımıza çıktığını, işletim sistemindeki prosesler arasında da var olduğunu söyledi; bunu bir paradigma ya da iş mantığı olarak tanımladı.

Üretilen şeyler bir tampon (buffer) bellek bölgesinde saklanmalıdır; bu bir veritabanı, bir dosya ya da başka bir veri saklama ortamı olabilir. İki tür vardır:

- **Sınırsız tampon (unbounded buffer):** Pratikte bir sınır verilmez; sınırsız üretilebilir. Sınır depolama alanının kapasitesidir (örneğin sabit diskin kapasitesi).
- **Sınırlı tampon (bounded buffer):** Önceden belli bir tampon uzunluğu verilir; üretim ve tüketim buna göre yapılır. Örneğin 100 elemanlı bir dizi düşünelim; bir proses sayı yazar, diğeri okur. Yazmadan önce üretici prosesin tamponun dolu olup olmadığını, okuyan prosesin de tüketeceği bir şey olup olmadığını (tamponun boş olup olmadığını) kontrol etmesi gerekir.

### 4.2 Paylaşımlı bellek çözümü

Slayttaki paylaşılan veri (ekrandan, 00:19:40):

```c
#define BUFFER_SIZE 10
typedef struct {
    . . .
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
```

`item` yapısının içi üç noktayla bırakılmıştır; istenen her şey yazılabilir: bir öğrenci yapısı, bir tamsayı ya da başka bir şey. Bu türden `BUFFER_SIZE` (burada 10) elemanlı bir dizi oluşturulur. Yazan prosesin ve okuyan prosesin sınırları takip etmesi için iki indis (ya da işaretçi) tutulur: yazan `in` ile gösterilen yere yazar, okuyan `out` ile gösterilen yerden okur. C tarzı olduğu için indisler 0'dan `BUFFER_SIZE - 1`'e kadardır.

Üretici (ekrandan, 00:22:30):

```c
item next_produced;
while (true) {
    /* produce an item in next_produced */
    while (((in + 1) % BUFFER_SIZE) == out)
        ; /* do nothing */
    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
}
```

Üretilecek eleman `next_produced`'tır ve bir yerden gelir; işlem sonsuz bir döngüde sürekli devam eder. Hoca tahtaya bir dizi çizdi: üretici bir uçtan ekler, tüketici diğer uçtan tüketir. İndisler hep artarsa dizinin başındaki tüketilmiş bölgeler boşa gider; bu yüzden dairesel (circular) bir yapı kullanılır ve `in`'in bir fazlası `BUFFER_SIZE`'a göre mod alınır. Bu değer `out`'a eşitse tampon doludur ve üretici hiçbir şey yapmadan bekler. Boş `while` döngüsünün sonundaki tek başına noktalı virgül "boşta bekle" demektir. Tüketici `out`'u değiştirdiğinde bu koşul bozulur ve döngüden çıkılır. Koşul sağlanmıyorsa üretilen eleman `buffer[in]`'e yazılır ve `in` güncellenir.

Tüketici (ekrandan, 00:23:30):

```c
item next_consumed;
while (true) {
    while (in == out)
        ; /* do nothing */
    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    /* consume the item in next_consumed */
}
```

`in` ile `out` eşitse ikisi aynı yeri gösteriyor, yani tüketilecek bir şey yoktur; tüketici bekler. Yeni bir şey eklenince bu durum bozulur; tüketici `out`'un gösterdiği yerden elemanı alır ve `out`'u artırır.

**Soru:** Neyi tüketeceğiz, tüketip ne yapacağız? **Cevap:** Slaytta "consume the item" yazan yere istenen kod yazılır: veritabanından gelen veriyi bir tabloda göstermek ya da üzerinde algoritmalar çalıştırmak gibi. Önemli olan, gelen verinin kendi dünyamızdan değil başka bir prosesin ürettiği yerden gelmesidir.

Slayttaki not: "Solution is correct, but can only use BUFFER_SIZE-1 elements." Yani 10 elemanlı tamponda en fazla 9 eleman aynı anda bulunabilir.

> **Ek bilgi (derste anlatılmadı):** Bir elemanın boş bırakılmasının nedeni, tamponun dolu ve boş durumlarını yalnız `in` ve `out` ile ayırt edebilmektir. On eleman da kullanılsaydı dolu tamponda `in` yeniden `out`'a eşit olurdu ve bu durum boş tampondan ayırt edilemezdi. Bütün elemanları kullanmak için ayrıca bir sayaç (count) değişkeni tutulabilir; ancak bu durumda sayacın iki proses tarafından güncellenmesi eşzamanlama sorununa yol açar.

## 5. Mesaj Geçirme Sistemi

### 5.1 Eşzamanlılık ve haberleşme

Mesaj geçirme, proseslerin çekirdek aracılığıyla haberleşmesidir. Bu bir mekanizmadır ve içinde bir eşzamanlama (senkronizasyon) olması gerekir. Hoca eşzamanlı (senkron) ve eşzamansız (asenkron) haberleşme kavramlarını sordu:

**Soru:** Şu anda bizim yaptığımız haberleşme eşzamanlı mı eşzamansız mı? **Cevap:** Hoca şöyle açıkladı: Eşzamanlı haberleşmede ben konuşurum, konuşmamı bitiririm, siz ancak ondan sonra duymaya başlarsınız; mesaj oluşturulur, oluşturma işi biter, sonra tüketme aşamasına geçilir. Gerçekte yaptığımız (yüz yüze de çevrim içi de) haberleşme eşzamansızdır. Ama bazı durumlarda haberleşmenin eşzamanlı olması gerekir: Örneğin bir veri üretilirken bir parçasının tüketilmesi istenmeyebilir; önce verinin tamamı üretilsin, sonra tamamı tüketilsin. Bu yüzden eşzamanlamaya ihtiyaç vardır.

### 5.2 send ve receive

Mesaj sistemi, paylaşılan bir değişkene başvurmadan prosesleri haberleştirmeyi sağlar; işletim sisteminin çekirdeğindedir. İki işlemi vardır:

- **`send(message)`:** Üretici proses mesajı gönderir; mesaj (ya da kopyası) çekirdek tarafına gider.
- **`receive(message)`:** Tüketici proses mesajı alır ve tüketir.

Mesajın uzunluğu sabit ya da değişken olabilir; bu tasarıma ve kullanılan yönteme bağlıdır.

### 5.3 Haberleşme bağlantısı ve tasarım soruları

P ve Q adlı iki proses haberleşmek istiyorsa üretirken de tüketirken de çekirdeğe erişmeleri gerekir. Bunun için bir **haberleşme bağlantısı** (communication link) gerekir; "mesaj hazırlandı, çekirdeğe gönderiyorum" denemez, işlemler bu bağlantı üzerinden yapılır ve ardından mesaj alışverişi (send/receive) gerçekleşir.

Bunlar zihnimizdeki taslaklar, yani modellerdir. Gerçekleştirme (implementation) aşamasında şu sorular dikkate alınmalıdır:

- Bağlantı nasıl kurulur; nasıl bir veri yapısıdır ve çekirdeğe nasıl erişir?
- Bir bağlantı ikiden fazla prosesle ilişkilendirilebilir mi?
- Haberleşen her proses çifti arasında kaç bağlantı olabilir? Örneğin A, B'ye veri göndermek için bir bağlantı oluşturduysa aynı bağlantı B'den A'ya göndermek için de kullanılabilir mi? Kullanılamıyorsa iki bağlantı oluşturulur. Hoca bu iki yaklaşımı unutmamamızı, ileride soracağını söyledi.
- Bağlantının kapasitesi nedir?
- Mesaj boyutu sabit mi, değişken mi?
- Bağlantı tek yönlü (unidirectional) mü, çift yönlü (bidirectional) mü?

### 5.4 Simpleks, yarı çift yönlü, tam çift yönlü

Haberleşme sınıflandırmalarından biri (elektronikte daha ayrıntılı incelenir) şöyledir:

- **Simpleks (simplex):** Mesaj yalnız A'dan B'ye gider; B'den A'ya gidemez.
- **Yarı çift yönlü (half duplex):** İki yön de vardır ama aynı anda değil; A, B'ye gönderirken B beklemek zorundadır.
- **Tam çift yönlü (full duplex):** A, B'ye gönderirken B de aynı anda A'ya gönderebilir.

Mesaj geçirmede iki proses arasındaki bağlantının tek yönlü mü çift yönlü mü olacağı bu sınıflandırmanın sonucudur.

### 5.5 Gerçekleştirim

Bağlantının fiziksel gerçekleştirimi şunlarla olabilir:

- Paylaşımlı bellek: mesajın çekirdeğe gitmesi bu iş için ayrılmış bir bellek bölgesi üzerinden sağlanabilir (hoca bunun ikinci modeldeki paylaşımlı bellekle karıştırılmamasını istedi).
- Donanım veriyolu (bus).
- Ağ.

Mantıksal gerçekleştirim seçenekleri:

- Doğrudan ya da dolaylı.
- Eşzamanlı ya da eşzamansız.
- Otomatik ya da açık (explicit) tamponlama.

Hoca bunların ayrıntılarının kitapta olduğunu ve dersin biraz ileri ama gerekli konuları olduğu için okunmasını tavsiye etti.

### 5.6 Paylaşımlı bellekte güven sorunu

Paylaşımlı bellekte haberleşme işletim sistemi tarafından değil, yalnız kullanıcı prosesleri tarafından kontrol edilir. Hoca bunu öğrenciler arasında ders notu alışverişi örneğiyle anlattı:

- Bölüm sekreterliğinde görevlinin kontrol ettiği bir yer olsun. Satıcı notu oraya bırakır, alıcı oradan alır ve parasını bırakır. Mekanizma güvenlidir, ama sekreterlik öğle arasında kapalıdır, her zaman açık değildir; belli bir kontrol mekanizmasıyla çalışır. Arada çekirdek gibi bir aracı vardır; bu mesaj geçirmeye uygundur.
- Eskiden var olan "sadaka taşı" gibi, bir çalışma odasına bir kutu konsun. Satmak isteyen notu oraya koyar, almak isteyen alır ve parasını bırakır. Burada güven meselesi vardır.

Paylaşımlı bellekte de ortak bir bölgeden okunan ve yazılan verilerin doğru okunup yazılacağından emin olmak gerekir: Mesaj tamamen yazıldı mı, hâlâ yazılmaya devam ediyor mu? Birinde kullanım kolaydır ama güven sorunu ve eksikler vardır; diğerinde ekstra bir kontrol mekanizması vardır. Temel problem, paylaşımlı belleğe erişecek proseslerin ne zaman ve ne sırayla erişeceği ve erişimlerinin nasıl eşzamanlanacağıdır. Eşzamanlama ayrı bir konu olarak daha sonra ayrıntılı işlenecektir.

## 6. Doğrudan ve Dolaylı Haberleşme

> **Ders sonrası not:** Hoca doğrudan ve dolaylı haberleşmeyi paylaşımlı belleğin altındaki iki yaklaşım olarak anlattı ve paylaşımlı bir bellek bölgesi üzerinden açıkladı. Ana kitapta (Silberschatz) bu iki yaklaşım büyük olasılıkla mesaj geçirmenin adlandırma (naming) seçenekleri olarak verilir: doğrudan haberleşmede proses adı, dolaylı haberleşmede posta kutusu kullanılır.

### 6.1 Doğrudan haberleşme

P ve Q prosesleri için P gönderici ya da alıcı, Q da gönderici ya da alıcı olabilir. Gönderen bir sistem çağrısına benzer bir işlemde alıcının adını yazar:

- `send(P, message)`: P prosesine mesaj gönder.
- `receive(Q, message)`: Q prosesinden mesaj al.

Burada P ve Q yerine gerçekte proses kimlikleri (PID) yazılır; bunun uygulaması bir sonraki uygulama dersinde yapılacaktır. Alıcı tarafta `scanf`'teki gibi bir değişkenin adresi verilir; okunacak veri belli bir bellek bölgesinden alınıp kendi yerel belleğe kopyalanır.

Doğrudan haberleşmede bağlantının özellikleri:

- Bağlantılar otomatik olarak kurulur.
- Bir bağlantı tam olarak bir proses çiftiyle ilişkilidir; her çift arasında tek bir bağlantı vardır.
- Bağlantı tek yönlü olabilir ama genellikle çift yönlüdür; çünkü her iki taraf da hem yazabilir hem okuyabilir.

### 6.2 Dolaylı haberleşme

Mesajlar bir **posta kutusuna** (mailbox) yönlendirilir; bunlara **port** da denir. Mesajlar posta kutusuna gönderilir ve oradan okunur. Her posta kutusunun benzersiz (unique) bir kimliği vardır ve ayrı bir veri yapısıdır. Prosesler ancak ortak bir posta kutusunu paylaşıyorlarsa haberleşebilir.

Bağlantının özellikleri:

- Bağlantı yalnız ortak bir posta kutusunu paylaşan prosesler arasında kurulur.
- Bir bağlantı birden fazla prosesle ilişkilendirilebilir.
- Her proses çifti arasında birden fazla bağlantı olabilir.
- Bağlantı tek yönlü ya da çift yönlü olabilir.

İşlemler (ekrandan, 00:41:30):

- Yeni bir posta kutusu (port) oluşturmak.
- Posta kutusu üzerinden mesaj göndermek ve almak.
- Posta kutusunu silmek.

Temel işlemler (primitives): `send(A, message)` A posta kutusuna mesaj gönderir; `receive(A, message)` A posta kutusundan mesaj alır.

Hoca dolaylı haberleşmeyi farkında olmadan kullandığımızı söyledi: Bir web ya da mobil uygulamadan veritabanına bağlanıp SQL sorgusuyla veri çektiğinizde verinin geldiği yer aslında bir posta kutusu, yani bir porttur. Soket programlama da bu yaklaşımın bir biçimidir.

### 6.3 Posta kutusu paylaşımı sorunu

P1, P2 ve P3 bir A posta kutusunu paylaşsın; haberleşen prosesler iki tane olmak zorunda değildir. P1 gönderdiğinde mesajı kim alacaktır? Kim isterse alabilir. Mesaj alınınca silinmiyorsa P1'in gönderdiği mesajı hem P2 hem P3 alabilir; bu isteniyorsa sorun yoktur. Ama yalnız birinin alması isteniyorsa sorun çıkar: bir yere bir nesne koydunuz ve bir başkası onu alırken ondan başkasının da alma olasılığı varsa nesne çoğalmaz.

Çözümler:

- **En katı yaklaşım:** Bir bağlantı en fazla iki prosesle ilişkilendirilebilir; üç proses bir posta kutusunu paylaşamaz. Bu garanti sağlar, ama böyle zorlayıcı bir kısıtlama işletim sisteminin etkileşimini düşürür.
- Belli bir zaman aralığında yalnız bir prosesin `receive` işlemi yapmasına izin vermek: bir proses posta kutusuna eriştiyse diğerine izin verilmez.
- Alıcıyı sistemin keyfi olarak seçmesi: önce gelen, önceliği yüksek olan ya da başka bir ölçüte göre biri alır. Ayrıca göndericiye "mesaj alındı" (ve kimin aldığı) bilgisi verilebilir.

Bunların dışında başka yaklaşımlar da önerilebilir.

## 7. Eşzamanlama: Bloklayan ve Bloklamayan İşlemler

Eşzamanlamanın ayrıntısı thread'ler konusundan sonra ayrı bir konu olarak gelecektir. Mesaj geçirme bloklayan (blocking) ya da bloklamayan (non-blocking) biçimde yapılabilir. Bloklamak bir şeyi yarıda kesmek, kesintiye uğratmak demektir. Bloklayan işlem eşzamanlı (senkron), bloklamayan işlem eşzamansız (asenkron) olarak ifade edilir.

- **Bloklayan gönderme (blocking send):** Gönderen, mesaj alınana kadar bloklanır. Hoca bunu şöyle anlattı: Üretici mesajı üretti; tüketici mesajı alana ya da tamamen okuyana kadar üretici tarafın sesini kesmesi, durması.
- **Bloklayan alma (blocking receive):** Alıcı, bir mesaj gelene kadar bloklanır.
- **Bloklamayan gönderme (non-blocking send):** Gönderen mesajı gönderir ve devam eder.
- **Bloklamayan alma (non-blocking receive):** Alıcı ya geçerli bir mesaj ya da boş (null) mesaj alır.

Hoca bloklamayan almayı dosya okuma örneğiyle ilişkilendirdi: Java'da ya da C'de bir dosyadan okurken istisna (exception) oluşabileceği için `fread`, `fwrite` gibi işlemlerde dosyanın açılıp açılmadığını ve verinin okunup okunmadığını `if` ile kontrol etmemiz söylenir. Tek başına bir programda bu çok önemli görünmeyebilir. Ama dosya bir başka prosesin oluşturduğu ve içine veri yazdığı bir dosyaysa, oraya bir verinin yazılmış olması gerekir ki okuyabilesiniz. Okuyamazsanız istisna oluşur ve program yarıda kesilir. Bu yüzden istisna yönetimi ya da istisnadan kaçınma (exception avoiding) için `if` kontrolleri yapılır. Orada bir mesaj olduğu yüzde yüz garanti edilemez.

Farklı kombinasyonlar mümkündür: bloklayan gönderme ile bloklamayan alma ya da bloklamayan gönderme ile bloklayan alma gibi; toplam dört durum vardır. İkisinin de bloklayan olduğu duruma **rendezvous** denir.

**Soru:** "Rendezvous" hangi dilden bir kelimeye benziyor? **Cevap:** Fransızca; "randevu" demektir. Buna randevu usulü haberleşme denir: Ben konuşurken siz beklersiniz, konuşmam biter; siz dinlerken de ben sizi beklerim. Üretici sürekli `send`, tüketici sürekli `receive` yapar.

## 8. Tamponlama

Şemadaki mesaj kuyruğunda (m0, m1, m2, ...) üreticinin gönderdiği mesajlar belli bir düzenle sıralanmalıdır. Genellikle ilk gelen mesajın ilk iletilmesi beklenir, ama yerine göre yığın (stack) mantığıyla son gelen ilk çıkar biçiminde de düşünülebilir. Mesaj kuyruğu bağlantıya bağlıdır. Hoca bunun yalnız çekirdek tarafı için değil, paylaşımlı bellek için de geçerli olduğunu söyledi; paylaşımlı belleğe de birden fazla nesne konabilir ve orada da kuyruk benzeri bir yapı düşünülebilir.

Kuyruk üç biçimde gerçekleştirilir:

- **Sıfır kapasite (zero capacity):** Bağlantıda hiçbir mesaj tutulmaz; gönderen, alıcı alana kadar bekler (rendezvous).
- **Sınırlı kapasite (bounded capacity):** n mesajlık sınırlı bir uzunluk vardır; bağlantı dolana kadar gönderen gönderebilir, doluysa beklemek zorundadır.
- **Sınırsız kapasite (unbounded capacity):** Gönderen hiç beklemez; üretecek bir şey varsa üretmeye devam eder.

## 9. IPC Sistem Örnekleri: POSIX, Mach, Windows

Ara sonrasında hoca kitabın birçok bölümünde önce konunun teorik tarafının anlatıldığını, son kısımlarda farklı işletim sistemlerindeki yaklaşımların örneklendiğini söyledi. Bu örneklerin C üzerinde programlanması bir sonraki uygulama dersinde yapılacaktır; ayrıca öğrencilere tanımlanan Red Hat eğitim içeriklerinde de IPC ile ilgili bölümler vardır.

### 9.1 POSIX paylaşımlı bellek

İşletim sistemleriyle ve programlamayla ilgili birkaç standart geliştirilmiştir; bunlardan biri POSIX'tir. POSIX, IPC için işletim sistemi fonksiyonları sunabilir; bunlar sistem çağrısı olmayabilir, kütüphane düzeyinde olabilir. Paylaşımlı bellek kullanmak için önce proses tarafında bir paylaşımlı bellek segmenti oluşturulur (`shm_open` ile bir ad ve oluşturma bayrakları verilir); bu bölge daha önce oluşturulmuşsa paylaşmak için de aynı fonksiyon kullanılır. Nesnenin boyutu belirlenir. Sonra C'deki `fprintf` gibi `sprintf` ile gönderilecek veri paylaşımlı bellek alanına yazılır. Slaytta bir string gönderilmiştir ama bir yapı (structure) değişkeni de gönderilebilir.

Slayttaki POSIX üretici (ekrandan, 01:07:00):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
/* the size (in bytes) of shared memory object */
const int SIZE = 4096;
/* name of the shared memory object */
const char *name = "OS";
/* strings written to shared memory */
const char *message_0 = "Hello";
const char *message_1 = "World!";

/* shared memory file descriptor */
int shm_fd;
/* pointer to shared memory obect */
void *ptr;

   /* create the shared memory object */
   shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

   /* configure the size of the shared memory object */
   ftruncate(shm_fd, SIZE);

   /* memory map the shared memory object */
   ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

   /* write to the shared memory object */
   sprintf(ptr,"%s",message_0);
   ptr += strlen(message_0);
   sprintf(ptr,"%s",message_1);
   ptr += strlen(message_1);

   return 0;
}
```

Hoca kodu şöyle açıkladı: Mesaj boyutu (4096) ve paylaşımlı bellek nesnesinin adı ("OS") tanımlanır; iki mesaj gönderilecektir. Paylaşımlı bellek için bir dosya tanımlayıcısı (`shm_fd`) tutulur. Bu mekanizmaların çoğunda arka planda bir dosya saklanır. Hoca Word açıkken simgesinin yanında görülen ve Word kapanınca kendiliğinden kaybolan geçici dosyayı örnek verdi; bu, güvenlik ve yedekleme amaçlı bir yerel tampondur. Haberleşmede de bir dosya tutulur. PCB'de dosya tanımlayıcılarının saklandığı konuşulmuştu; bunların bazıları haberleşme için kullanılabilir. Paylaşımlı bellek açılır, nesnenin boyutu belirlenir, bellek bölgesine eşlenir (`mmap`) ve `sprintf` ile ilk mesaj yazılır. Sonra işaretçi mesaj uzunluğu kadar ilerletilir ve ikinci mesaj yazılır; bir kuyruk gibi önce bir mesaj, sonra diğeri. Haberleşmenin mantığını (protokolünü) iki proses de bilmelidir; burada mesajlar uç uca eklenir ve okuyan buna göre okur.

Slayttaki POSIX tüketici (ekrandan, 01:09:30):

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
/* the size (in bytes) of shared memory object */
const int SIZE = 4096;
/* name of the shared memory object */
const char *name = "OS";
/* shared memory file descriptor */
int shm_fd;
/* pointer to shared memory obect */
void *ptr;

   /* open the shared memory object */
   shm_fd = shm_open(name, O_RDONLY, 0666);

   /* memory map the shared memory object */
   ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

   /* read from the shared memory object */
   printf("%s",(char *)ptr);

   /* remove the shared memory object */
   shm_unlink(name);

   return 0;
}
```

Boyut yine 4096, ad yine "OS"tur. Paylaşımlı bellek nesnesinin adı iki tarafta da aynı olmalıdır; biri "OS1" yapılırsa haberleşme sağlanmaz ve çağrıların dönüş değerlerine bakılırsa −1 döndüğü görülür. Tüketici de paylaşımlı belleği açar, eşleme yapıp bölgeye erişir, işaretçideki veriyi ekrana basar ve `shm_unlink` ile nesneyi kaldırır, yani bağlantıyı (link) yok eder. Okuyan iki kez ya da daha fazla da okuyabilir.

Ajan iki kodu scratchpad'de derleyip art arda çalıştırdı. `mmap` için `<sys/mman.h>`, `ftruncate` için `<unistd.h>` eklendi ve nesne adı çakışmasın diye değiştirildi; `gcc -Wall` uyarı vermedi. Üretici çalıştıktan sonra tüketici `HelloWorld!` yazdı ve nesne silindi.

Hoca bu tür uygulamaların genellikle basit örneklerle gösterildiğini söyledi: A prosesi x = 5 sayısını B prosesine gönderir, B karesini alıp geri gönderir. Amaç verinin gidip geldiğini göstermektir.

### 9.2 Mach

Mach mesaj tabanlı bir sistemdir; sistem çağrıları bile mesaj olarak ifade edilir. Hoca bu örneklerin, iki ders önce anlatılan beş durumlu proses modeli gibi bir ana yapıyı temel alıp farklı biçimlerde gerçekleştirildiğini söyledi (örneğin Linux'un bir sürümünde beş yerine çok daha fazla durum görülebilir).

- Her görev (task) oluşturulduğunda Kernel ve Notify adlı iki posta kutusu verilir.
- Mesaj aktarımı için üç sistem çağrısı vardır: `msg_send`, `msg_receive` ve `msg_rpc`.
- Haberleşme için posta kutuları kullanılır ve bunlar için port ayırma (port allocate) yapılır.
- Gönderme esnektir. Posta kutusu doluysa gönderen süresiz bekleyebilir, en fazla n milisaniye bekleyebilir, hemen dönebilir ya da mesajı geçici olarak önbelleğe alabilir.

Hoca bir öğrencinin "posta kutusu nerede?" sorusunu hatırlattı: Normal paylaşımlı bellekte bölge bellekte herhangi bir yere konabilir, ama çekirdek tarafında da bir paylaşımlı bellek olabilen durumlar vardır; bu da bir seçenektir.

### 9.3 Windows

Windows'ta IPC, mesaj geçirme merkezli (message-passing centric) **ALPC** (Advanced Local Procedure Call) ile sağlanır ve yalnız aynı sistemdeki prosesler içindir. Posta kutularına benzeyen portlar kullanılır; hoca Windows'un "port" kavramının işletim sistemi kavramlarındakinden biraz farklı olduğunu, adını değiştirip kullandığını söyledi.

Haberleşme şöyle işler:

- İstemci (client), sunucunun bağlantı portunu (connection port) açar.
- İstemci bir bağlantı isteği gönderir.
- Sunucu iki özel haberleşme portu döndürür.
- İstemci ile sunucu arasındaki haberleşme bu portlar üzerinden `send` ve `receive` çağrılarıyla gerçekleşir.

Hoca istemci-sunucu modelinin günümüz haberleşmelerinde en çok kullanılan yapı olduğunu söyledi: istemci istek gönderir, isteğe port üzerinden bir cevap gelir. POSIX örneği daha basittir (aç, eşle, yaz; aç, eşle, oku), Windows'ta ise port açıldıktan sonra üç aşamalı denebilecek bir işlem vardır.

> **Ders sonrası not:** Hoca istemciyi alıcı (receiver), sunucuyu gönderici (sender) gibi düşünmemizi söyledi. İstemci-sunucu modelinde iki taraf da hem gönderir hem alır: istemci istek gönderip yanıt alır, sunucu istek alıp yanıt gönderir. Bu benzetme yalnız sunucunun veri sağlayan taraf olduğu durumlar için geçerlidir.

## 10. İstemci-Sunucu Haberleşmesi: Soketler, RPC ve Pipe'lar

Buraya kadarki örnekler aynı bilgisayardaki iki prosesi haberleştirmek içindi. Farklı bilgisayarlar söz konusuysa, örneğin WhatsApp'tan mesaj ya da Instagram'dan görüntü gönderdiğinizde, proses sizin telefonunuzda, arkadaşınızın telefonunda ve Instagram sunucusunda çalışır. Bu, geniş alan ağı (WAN, internet) içindeki istemci-sunucu yapısıdır. Bu yapılarda günümüzde en çok soketler kullanılır. Soketler ağ dersinin konusudur, burada basit örnekleri konuşuldu.

### 10.1 TCP ve UDP

İki soket türü vardır:

- **TCP:** Bir yerden bir yere gönderilen verinin tam ve bozulmadan aktarıldığını garanti eder. Bir dosya indirirken ya da mesaj alırken tek bir bit bile değişebilir: dijital olarak oluşturulan mesaj fiziksel hatlarla (elektrik, telefon hatları) taşınır, yolda hata olabilir; ayrıca en kısa yol algoritmalarıyla aktarılır. TCP doğru iletimi temin eder.
- **UDP:** Bu garanti her zaman gerekmez. Müzik dinlerken bir bit eksik gelse kulak bunu pek hissetmez; akış (stream) verilerinde kullanılabilir.

### 10.2 RPC ve çok oyunculu oyunlar

Uzaktan yordam çağrıları (remote procedure call, RPC) oyun programlamada da kullanılır. Hoca bu yaklaşımların yalnız işletim sistemi içi haberleşme için olmadığını, kendi kullanıcı proseslerimizde de geçerli olduğunu vurguladı: "İşletim sistemi tasarlamıyoruz, ne işimize yarayacak?" diye düşünülmemelidir. Önceki dönem yaptırdığı bir projeyi anlattı: İki ya da üç oyuncunun birbirini sabote edebildiği (birinin yemeğini bozmak, malzemeyi döküp dağıtmak gibi) ve işi önce bitirenin kazandığı bir yemek yapma yarışması oyunu. Bunun basit bir ağ üzerinde haberleşmesi gerekiyordu ve RPC'lerin özel hâlleri kullanıldı. Python, Java ve C'de bunlarla ilgili pek çok kütüphane vardır. Java'da ayrıca uzaktan yöntem çağrısı (RMI) vardır. Hoca kitabın bu örnekleri gelişmişten basite doğru anlattığını, kendisinin daha anlamlı olsun diye tersinden anlatacağını söyledi.

### 10.3 Sıradan pipe'lar

Pipe, iki proses arasında haberleşmeyi sağlayan basit bir boru gibidir: bir proses veriyi boruya ekler, diğeri öbür uçtan okur; hoca bunu bir su hattına benzetti. İçinde bir kuyruk yapısı vardır ve ekstra bir şeye gerek duyulmaz. Üretici-tüketici türü problemlerde kullanılabilir.

Slayttaki bilgiler (ekrandan, 01:18:30):

- Sıradan pipe'lar standart üretici-tüketici biçiminde haberleşme sağlar.
- Üretici bir uca (yazma ucu) yazar, tüketici diğer uçtan (okuma ucu) okur.
- Bu yüzden sıradan pipe'lar tek yönlüdür.
- Haberleşen prosesler arasında parent-child ilişkisi gerekir.
- Şemada parent ve child'ın her birinde `fd[0]` ve `fd[1]` vardır; pipe aralarındadır.
- Windows bunlara anonim pipe (anonymous pipe) der. Unix ve Windows kod örnekleri kitaptadır.

Pipe'ın her ucunda iki dosya tanımlayıcısı vardır ama ikisi birden etkin olmaz. Örneğin parent yazma yetkisine sahipse çocuk yazamaz; parent okuma ucunu kapatır ve yazma ucunu kullanır, çocuk tam tersini yapar. `fork` sonrası hangi tarafın parent hangisinin çocuk olduğu `if` ile kontrol edilir ve dosya tanımlayıcıları iki tarafta simetrik biçimde ayarlanır. Çift yönlü haberleşme için iki pipe gerekir; pipe'ın kendi yapısında başka bir çözüm yoktur. Pipe aslında tamamen bir dosya gibidir; paylaşımlı bellekteki oluşturma çağrısına benzer biçimde bir pipe oluşturma çağrısı yapılır ve yapılandırılır.

> **Ders sonrası not:** Hoca `fd[0]`'ın yazma ucu, `fd[1]`'in okuma ucu olduğunu söyledi ve standart dosya tanımlayıcılarını "0 yazma, 1 okuma, 2 hata" diye andı. Doğrusu tersidir: UNIX'te `pipe(fd)` çağrısından sonra `fd[0]` okuma ucu (read end), `fd[1]` yazma ucudur (write end). Standart tanımlayıcılarda da 0 standart girdi (stdin), 1 standart çıktı (stdout), 2 standart hatadır (stderr). Hoca yer yer "sıfır yazma için olabilir ama..." diyerek kendisi de tereddüt etti.

Sıradan pipe'ın temel özellikleri ve sınırları:

- Haberleşme tek yönlüdür; çift yönlü için iki pipe gerekir.
- Haberleşen prosesler arasında parent-child ilişkisi gerekir.
- Ağ üzerinde kullanılamaz.

Sıradan pipe'ı parent ile çocuk arasında kolay yapan şudur: Pipe bir kez oluşturulur ve `fork` ile iki tarafa da kopyalandığı için iki taraftan da erişilebilir; paylaşımlı bellek gibi düşünülebilir. Ekstra bir kimliğe ya da posta kutusu numarasına gerek yoktur; parent ve çocuk doğrudan veri gönderip alabilir. Kurulumu basit, okuması ve yazması kolaydır.

### 10.4 Adlandırılmış pipe'lar

Parent-child ilişkisi olmadan haberleşmek için **adlandırılmış pipe** (named pipe) kullanılır; bunlara **FIFO** da denir. Parent-child ilişkisi gerekmez, birkaç farklı proses aynı adlandırılmış pipe'ı aynı anda kullanabilir. Windows ve UNIX sistemlerinde örnekleri vardır. Hoca bunların kodlarını önceden hazırladığını ve uygulamada anlatılacağını söyledi.

### 10.5 RPC'nin yapısı

RPC, özellikle ağ sistemlerinde haberleşmeyle ilgili işlerin soyutlanmasını sağlayan bir programlama kolaylığıdır: belli fonksiyonları çağırırsınız, haberleşme işlemleri arka planda gerçekleşir. Bir istemci ve bir sunucu vardır; istemcideki kullanıcı bir çağrıyla çekirdeğe bir mesaj gönderir ve `send`, `receive` çağrılarıyla mesaj gönderilip alınır.

### 10.6 Java soketleri

Kullandığımız birçok şey düşük seviyeli değil, uygulama seviyesine yakındır; ama etkileşimi yüksek mobil ve web uygulamalarında da haberleşme gerekir. En basit örnek, veritabanından veri çekmek için bir SQL bağlantısı (SQL connection) açıp SQL komutu göndermektir (C#'ta da benzeri vardır). Bir IP adresinden ya da bir kaynaktan veri çekmek Java soketleriyle yapılabilir; TCP ve UDP soketleri vardır. Tarih sunucusu (date server) örneğinde önce bir sunucu soketi (`ServerSocket`) nesnesi oluşturulur; burada işaretçi yoktur, nesne üretilir. Sürekli dinlenir, soketin açılıp açılmadığı kontrol edilir; istemci tarafında bir akış (stream) açılıp tarih bilgisi okunur ve ekrana yazdırılır. Soket programlama ağ derslerinde ayrıntılı anlatılır.

### 10.7 Soket: IP adresi ve port

Soket bir haberleşme uç noktasıdır (endpoint). Bir bilgisayardaki iki prosesi haberleştirmek için gereken bilgi proseslerin kimlikleridir (PID). Ama internet söz konusuysa (buradaki WhatsApp ile karşıdaki WhatsApp gibi) IP adresine de ihtiyaç vardır. OSI referans modeli standardına göre bir istek olduğunda bir paket oluşturulur ve önüne IP bilgisi eklenir. IP'ye eriştikten sonra istenen prosesin, PID'ye benzeyen ama ondan farklı bir tanımlayıcısına, yani **port numarasına** ihtiyaç vardır. IP adresi ile port numarasının birleştirilmesine (concatenation: bir şeyin sonuna öbürünü eklemek) **soket** denir.

Slayttaki bilgiler (ekrandan, 01:28:30):

- Soket bir haberleşme uç noktası olarak tanımlanır.
- IP adresi ile portun birleşimidir; port, bir makinedeki ağ servislerini ayırt etmek için mesaj paketinin başına konan bir sayıdır.
- `161.25.19.8:1625` soketi, 161.25.19.8 makinesindeki 1625 numaralı portu gösterir.
- Haberleşme bir soket çifti arasında olur.
- 1024'ün altındaki bütün portlar iyi bilinen (well-known) portlardır ve standart servisler için kullanılır.
- Özel IP adresi `127.0.0.1` (loopback), prosesin çalıştığı sistemin kendisini gösterir.

Hoca portu telefon örneğiyle açıkladı: Telefonda n tane uygulama vardır; Gmail'e ya da WhatsApp'a gelen bir verinin doğru uygulamayla eşleştirilmesi port üzerinden olur. Örneğin 1625 numaralı port WhatsApp'a ait olsun; 161.25.19.8'e 1625 portundan gelen veri WhatsApp'a yönlendirilir. Bir istekte bulunurken "Ben WhatsApp uygulamasıyım, IP adresim şu, port adresim bu; senden şunu talep ediyorum" denir. Karşı tarafta paket açılır ve cevap gönderenin adresine döner; hoca bunu eski mektuplardaki iade adresine benzetti. Telefonun paketlerini inceleyen uygulamalarla IP ve port bilgileri kolayca görülebilir. 8080 portu da web uygulamaları üzerinden haberleşmede kullanılabilir. Slayttaki şemada bir ana bilgisayar (host) ile bir web sunucusu arasındaki iletişim bu soketler üzerinden gösterilir.

## 11. URL: Web'de IPC'nin Soyutlaması

Hoca son olarak bir web sitesinde URL sözdizimini gösterdi (ekrandan, 01:31:30). Bir web adresi, IPC'nin web uygulamalarına özgü bir soyutlamasıdır. Web tarayıcınız (Opera, Firefox, Chrome) bir proses, karşıdaki web sunucusu başka bir prosestir; ikisi arasındaki haberleşmeden başka bir şey değildir.

URL'nin parçaları:

- **Şema (scheme):** Web üzerinde hangi protokolle haberleşileceğini belirtir; genellikle HTTP ya da HTTPS, ama FTP ya da e-posta protokolleri de olabilir. Ardından `://` gelir.
- **Ana bilgisayar adı (host name):** Karşı bilgisayarın IP adresine ihtiyaç vardır, ama IP adresleri ezberlenmez; bu yüzden bir ad kullanılır.
- **Port:** Ana bilgisayar adından `:` ile ayrılır; HTTP genellikle 80 numaralı porttur. Şemadan sonra `://`, porttan önce yalnız `:` kullanılması karışıklığı önlemek için belirlenmiş bir standarttır. Port genellikle yazılmaz, otomatik eklenir.
- **Yol (path):** Uygulamanın hangi sayfasına ya da program parçasına bağlanılacağını gösterir; bir web uygulaması tek bir programdan değil birden çok kod dosyasından oluşur (örnekte bir PHP sayfası).
- **Sorgu dizgisi (query string):** `?` ile başlar ve çağrılan sayfaya, bir fonksiyon çağrısındaki gibi parametreler verir; birden fazla parametre `&` ile ayrılır.
- **Parça tanımlayıcı (fragment identifier):** `#` ile sayfadaki belirli bir kimliğe sahip bölüme gidilir.

Arka planda bir TCP (ya da UDP) soketi kurulur. Hoca örnek verdi: Öğrenci bilgi sistemine kullanıcı adı ve şifreyle bağlanmak istediğinizde port numarası vermezsiniz, otomatik eklenir; kullanıcı adı ve şifre bağlanılan uygulamanın alacağı parametrelerdir. Hesap açılırsa açılır, hata verirse hata verir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:50): Mesaj geçirmenin paylaşımlı belleğe göre bir dezavantajı nedir?

> **Çözüm:** Mesajlar çekirdekteki bir veri yapısı üzerinden geçtiği için her gönderme ve almada kullanıcı modundan çekirdek moduna geçiş gerekir; bu ek bir maliyettir. Paylaşımlı bellekte bölge bir kez kurulduktan sonra çekirdek araya girmez.

**Soru 2** (ekrandan, 00:19:40): `BUFFER_SIZE` 10 olan sınırlı tampon çözümünde tampon en fazla kaç eleman tutabilir? Dolu ve boş durumlar nasıl anlaşılır?

> **Çözüm:** En fazla `BUFFER_SIZE - 1 = 9` eleman. `((in + 1) % BUFFER_SIZE) == out` ise tampon dolu, `in == out` ise boştur.

**Soru 3** (derste sözlü, 00:24:30): Şu anda yaptığımız (yüz yüze ve çevrim içi) haberleşme eşzamanlı mı eşzamansız mı?

> **Çözüm:** Hocaya göre eşzamansızdır. Eşzamanlı haberleşmede konuşan konuşmasını bitirmeden dinleyen duymaya başlayamazdı; gerçekte dinleyici konuşma sürerken duyar.

**Soru 4** (derste sözlü, 00:48:50): Hem gönderme hem alma bloklayan olduğunda bu duruma ne ad verilir?

> **Çözüm:** Rendezvous (Fransızca "randevu"). Gönderen, alıcı mesajı alana kadar; alıcı da mesaj gelene kadar bekler.

**Soru 5** (ekrandan, 01:28:30): `161.25.19.8:1625` soketi neyi gösterir? `127.0.0.1` adresi ne anlama gelir?

> **Çözüm:** 161.25.19.8 IP adresli makinedeki 1625 numaralı portu gösterir. `127.0.0.1` loopback adresidir ve prosesin çalıştığı sistemin kendisini gösterir.

## Dersin Toparlaması

Bu derste prosesler arası haberleşmenin neden gerektiği, bağımsız ve işbirlikçi prosesler ile iki temel model olan paylaşımlı bellek ve mesaj geçirme anlatıldı. Üretici-tüketici problemi ve sınırlı tampon için paylaşımlı bellek çözümü kod üzerinden incelendi. Mesaj geçirmede haberleşme bağlantısının tasarım soruları, simpleks, yarı ve tam çift yönlü haberleşme, doğrudan ve dolaylı (posta kutusu) haberleşme, bloklayan ve bloklamayan işlemler, rendezvous ve tamponlama türleri ele alındı. POSIX paylaşımlı bellek, Mach ve Windows ALPC örnekleri verildi; istemci-sunucu haberleşmesinde soketler, TCP ve UDP, RPC, sıradan ve adlandırılmış pipe'lar, Java soketleri ve URL yapısı tartışıldı.

Hoca bu konuların C ile uygulamasının bir sonraki uygulama dersinde yapılacağını, eşzamanlamanın ise thread'ler konusundan sonra ayrı bir konu olarak ayrıntılı işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
