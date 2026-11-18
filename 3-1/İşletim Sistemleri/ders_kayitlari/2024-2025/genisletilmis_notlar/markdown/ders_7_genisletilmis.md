# Ders 7 Genişletilmiş Notu: İş Parçacıkları (Threads), Çok Çekirdekli Programlama, Amdahl Yasası ve POSIX IPC Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çoklu Programlama, Çoklu İşleme, Çoklu Görev ve Çoklu İş Parçacığı Kavramları
- 2. İş Parçacığı (Thread) Mimarisi ve Motivasyonu
- 3. Çok Çekirdekli Programlama, Eşzamanlılık (Concurrency) ve Paralellik (Parallelism)
- 4. Ortak Veri Paylaşan Thread'lerde Yürütme Sırası ve Amdahl Yasası
- 5. Kullanıcı ve Çekirdek Thread'leri ile Eşleştirme Modelleri
- 6. Thread Kütüphaneleri: Pthreads, Windows ve Java
- 7. Örtük İş Parçacığı Kullanımı (Implicit Threading)
- 8. Çok İş Parçacıklı Sistemlerde Temel Problemler
- 9. İşletim Sistemi Örnekleri: Windows ve Linux Thread Yapıları
- 10. Uygulama: POSIX IPC (Pipe, FIFO, Mesaj Kuyruğu, Paylaşımlı Bellek) ve Pthread Mutex
- Örnek Sorular
- Dersin Toparlaması

## 1. Çoklu Programlama, Çoklu İşleme, Çoklu Görev ve Çoklu İş Parçacığı Kavramları

### 1.1 Tekli Programlama (Uniprogramming) ve Çoklu Programlama (Multiprogramming)

İlk bilgisayar sistemlerinin çalışma mantığına bakıldığında **tekli programlama (uniprogramming)** yaklaşımı görülür. Bu yaklaşımda bir `A` programı çalışmaya başladığında bellekte yerini alır ve işlemci kendisine tahsis edildiğinde yürütülür (`Run`). Ancak yürütme sırasında bir kesme (interrupt) veya G/Ç (I/O) isteği geldiğinde program beklemeye (`Wait`) alınır ve G/Ç işlemi tamamlanana kadar işlemci hiçbir iş yapmadan boşta bekler. İşlemcinin bu bekleme aralıklarında boş kalması istenen bir durum değildir; çünkü aynı sürede başka programlar işlemciyi kullanabilir.

Bekleme (`Wait`) aralıklarında işlemciyi boş bırakmak yerine belleğe birden fazla programın (`A`, `B`, `C`, ...) alınması ve aktif program beklemeye geçtiğinde işlemcinin sıradaki programa tahsis edilmesi yaklaşımına **çoklu programlama (multiprogramming)** denir. İki program bellekte yer alıyorsa iki programlı, üç program yer alıyorsa üç programlı çoklu programlama söz konusudur. Burada temel varsayım, hem `A` hem `B` hem de `C` programlarını aynı anda barındırabilecek büyüklükte bir ana belleğin bulunmasıdır.

Tek çekirdekli (single-core) bir işlemcide zaman ekseni tektir; yani herhangi bir $t$ anında fiziksel olarak yalnızca tek bir iş yürütülür. Ancak `A` prosesinden `B` prosesine, oradan `C` prosesine geçişler milisaniye hatta mikrosaniye mertebesinde gerçekleştiği için kullanıcıya tüm programlar eşzamanlı çalışıyormuş gibi bir **sanal paralellik** görüntüsü sunulur. İşlemcinin birden fazla çekirdeği veya sistemde birden fazla işlemci varsa birden fazla zaman akışı çizilebilir ve işler aynı anda yürütülerek **gerçek paralellik** elde edilir.

Önceki derslerde prosesler **işlemci yoğun (CPU-bound)** ve **G/Ç yoğun (I/O-bound)** olarak sınıflandırılmıştı. Çoklu programlamada bu iki tür proses dengeli biçimde seçilip zaman planlaması yapıldığında işlemcinin boş kalma olasılığı en aza iner. Örneğin tekli programlamada işlemci kullanım oranı (processor utilization) %20 seviyesindeyken (zamanın %80'i boşta geçerken), çoklu programlama ile bu oran %40 ve üzerine çıkarılabilir; ayrı ayrı çalıştırıldığında 30 dakika sürecek işler 15 dakikada tamamlanabilir ve bellek, yazıcı gibi diğer kaynakların kullanım verimliliği de artar.

### 1.2 Dört Temel Kavramın Karşılaştırılması

Hoca slaytlara sonradan eklediği dört temel kavramı birbirinden ayırarak açıkladı (ekrandan, 00:08:30):

- **Çoklu Programlama (Multiprogramming):** Ana bellekte (main memory) birden fazla programın (`P1, P2, P3, P4, ..., Pn`) aynı anda bulunmasıdır. Bellekte bulunan program artık bir proses haline gelmiştir ve çalışmaya hazırdır; yürütülmekte olan proses G/Ç kaynağı istediğinde veya sonlandığında işlemci bellekte bekleyen diğer prosese verilir. Temel amacı **maksimum CPU kullanımı (maximum CPU utilization)** ve **ana belleğin verimli yönetimi (efficient management of the main memory)** sağlamaktır.
- **Çoklu İşleme (Multiprocessing):** Bir bilgisayar sisteminin donanımsal olarak iki veya daha fazla işlemciyle (veya çok çekirdekli işlemci birimleriyle) yönetilmesidir. Örneğin 10 prosesin bulunduğu bir sistemde aynı $t$ anında bir proses `CPU 1` üzerinde, bir diğeri `CPU 2` üzerinde, bir başkası `CPU 3` üzerinde fiziksel olarak aynı anda çalışabilir. Daha önce görüldüğü üzere simetrik (SMP) veya asimetrik (AMP) yapıda olabilir.
- **Çoklu Görev (Multitasking):** Tek kullanıcılı (single-user multitasking) veya çok kullanıcılı (multi-user multitasking) bir sistemde, bir veya birden fazla kullanıcının birden çok işinin (görevinin) işlemci zamanının paylaştırılmasıyla yürütülmesidir.
- **Çoklu İş Parçacığı (Multithreading):** Tek bir prosesin kendi yürütme akışının (execution flow), kendi içerisinde paralel veya eşzamanlı yürütülebilecek birden fazla alt parçaya (**iş parçacığı / thread**) bölünmesidir. Bu durum `fork()` ile birden fazla bağımsız proses oluşturmaktan farklıdır; burada tek bir proses kendi içinde parçalanır.

## 2. İş Parçacığı (Thread) Mimarisi ve Motivasyonu

### 2.1 Proses ve Thread Yapısının Karşılaştırılması

Proses kavramı incelenirken her prosesin bir Proses Kontrol Bloğu (PCB), kendine ait bir **Proses Kimliği (PID)**, **program sayacı (program counter - PC)** ve **yazmaç kümesi (register set)** olduğu görülmüştü. Benzer şekilde her iş parçacığının (thread) da kendine ait bir **Thread ID**'si, **program sayacı (PC)**, **yazmaç kümesi (`registers`)** ve **yığını (`stack`)** vardır.

Slayttaki şemada (ekrandan, 00:31:50) tek iş parçacıklı (single-threaded) bir proses ile çok iş parçacıklı (multithreaded) bir prosesin bellek yerleşimi karşılaştırılmıştır:

```text
Tek İş Parçacıklı Proses (Single-Threaded Process):
+--------+--------+---------+
|  code  |  data  |  files  |
+--------+--------+---------+
| registers |     |  stack  |
+-----------+     +---------+
|           thread          |
+---------------------------+

Çok İş Parçacıklı Proses (Multithreaded Process):
+---------+---------+---------+
|   code  |   data  |  files  |   <-- Tüm thread'ler tarafından ortak paylaşılır
+---------+---------+---------+
|registers|registers|registers|   <-- Her thread'in kendine özel yazmaçları
+---------+---------+---------+
|  stack  |  stack  |  stack  |   <-- Her thread'in kendine özel yığını
+---------+---------+---------+
| thread 1| thread 2| thread 3|
+---------+---------+---------+
```

Şemada görüldüğü üzere, bir proses altında birden fazla thread oluşturulduğunda **kod segmenti (`code`)**, **veri segmenti (`data`)** ve **açık dosya tanımlayıcıları (`files`)** tüm thread'ler tarafından ortak kullanılır. Verinin ortak olması sayesinde thread'ler arasında veri paylaşmak için sıradan pipe, FIFO veya paylaşımlı bellek (`shm_open`/`mmap`) gibi karmaşık IPC mekanizmaları kurmaya gerek kalmaz; örneğin C'de tanımlanan global bir değişken veya Java'da bir sınıf değişkeni aynı prosesteki tüm thread'ler tarafından doğrudan erişilebilir. Buna karşılık her thread farklı bir kod parçasını veya fonksiyon çağrısını yürüttüğü için kendi program sayacını, yazmaçlarını ve yerel değişkenlerini/fonksiyon çağrı çerçevelerini tutan **yığınını (`stack`)** ayrı tutmak zorundadır.

### 2.2 Günlük Uygulamalarda ve Çekirdekte Çoklu Thread Kullanımı

Günümüzdeki modern uygulamaların neredeyse tamamı çok iş parçacıklı (multithreaded) yapıda çalışır:

- **Kelime işlemci (word processor):** Arkada tek bir proses çalışırken, bir thread kullanıcının klavyede bastığı tuşları algılayıp ekranı günceller, başka bir thread veriyi diskten getirir veya kaydeder, bir diğer thread arka planda yazım denetimi (spell checking) yapar ve başka bir thread ağ (network) işlemlerini yürütür.
- **Mesajlaşma uygulamaları (ör. WhatsApp):** Kullanıcı bir kişiye mesaj yazarken aynı anda karşı taraftan gelen mesajların alınması ve ekranda gösterilmesi farklı thread'ler aracılığıyla yürütülür.
- **Çok iş parçacıklı sunucu (multithreaded server) mimarisi:** Bir web sunucusuna veya öğrenci bilgi sistemine (OBS, Online Yıldız vb.) aynı anda yüzlerce kullanıcıdan istek (request) gelir. Sunucu her istek için `fork()` ile yeni bir proses oluşturursa hem ayrı bellek tahsisi hem de proses yönetimi çok ağır ve maliyetli olur. Bunun yerine sunucu tek bir proses olarak çalışır; bir istemciden istek geldiğinde o isteği işleyecek yeni bir **thread** oluşturur ve kendisi hemen diğer istemcilerin isteklerini dinlemeye (`listen`) devam eder.
- **İşletim sistemi çekirdeği (kernel):** İşletim sistemi çekirdeğinin kendisi de doğal olarak çok iş parçacıklı (multithreaded) yapıdadır; çekirdek servislerini yürütmek için çok sayıda ayrı proses açmak yerine daha az sayıda proses içinde çok sayıda çekirdek thread'i çalıştırır.

### 2.3 Çoklu Thread Kullanımının Dört Temel Faydası

1. **Cevap verebilirlik (Responsiveness):** Etkileşimli bir uygulamada prosesin bir parçası bloklansa veya uzun bir G/Ç işlemi yapsa bile diğer thread'ler çalışmaya devam ederek kullanıcıya kesintisiz yanıt verebilir.
2. **Kaynak paylaşımı (Resource sharing):** Prosesler arası haberleşme (IPC) için açıkça paylaşımlı bellek veya mesaj geçirme yapıları kurmak gerekirken, thread'ler ait oldukları prosesin belleğini ve kaynaklarını varsayılan olarak paylaşır.
3. **Ekonomi (Economy):** Yeni bir proses oluşturmak için bellek ve kaynak tahsis etmek maliyetlidir. Thread oluşturmak (thread creation) ve thread'ler arasında bağlam değiştirmek (context switching), proses oluşturmaya ve prosesler arası bağlam değiştirmeye göre çok daha hafif (lightweight) ve hızlıdır.
4. **Ölçeklenebilirlik (Scalability):** Çok işlemcili (multiprocessor) veya çok çekirdekli (multicore) bir mimaride çok iş parçacıklı bir prosesin farklı thread'leri farklı çekirdekler üzerinde gerçek anlamda paralel çalışabilir; tek iş parçacıklı bir proses ise sistemde kaç çekirdek olursa olsun aynı anda yalnızca tek bir çekirdekte çalışabilir.

## 3. Çok Çekirdekli Programlama, Eşzamanlılık (Concurrency) ve Paralellik (Parallelism)

### 3.1 Çok Çekirdekli Sistemlerde Programlama Zorlukları

Çok çekirdekli (multicore) veya çok işlemcili sistemler birden fazla komut getirme-çözme-yürütme (fetch-decode-execute) birimine sahiptir. Bu donanım gücü uygulama geliştiricilere önemli avantajlar sağlarken beş temel tasarım zorluğu getirir:

1. **Aktiviteleri bölme (Dividing activities):** Uygulamanın eşzamanlı yürütülebilecek bağımsız görevlere ayrıştırılması.
2. **Denge (Balance):** Bölünen parçaların birbirine yakın iş yüküne sahip olması.
3. **Veriyi bölme (Data splitting):** Görevlerin üzerinde çalışacağı verinin de (örneğin 1000 elemanlı bağımsız bir veri kümesinin) çekirdekler arasında bölüştürülmesi.
4. **Veri bağımlılığı (Data dependency):** Bir görevin çıktısı diğerinin girdisi ise görevlerin yürütme sırasının senkronize edilmesi.
5. **Test ve hata ayıklama (Testing and debugging):** Çok sayıda farklı yürütme yolu oluştuğu için hataları yakalamanın tek thread'li programlara göre çok daha zor olması.

### 3.2 Eşzamanlılık (Concurrency) ve Paralellik (Parallelism) Farkı

- **Eşzamanlılık (Concurrency):** Tek bir çekirdek (single core) üzerinde birden fazla görevin zaman dilimleriyle nöbetleşe çalıştırılarak ilerleme kaydetmesidir. İnsan gözü/algısı genellikle saniye mertebesindeki gecikmeleri fark ederken, işlemci saniyenin çok altında sürelerle bağlam değiştirdiği (context switch) için görevler aynı anda çalışıyormuş gibi algılanır (sanal paralellik).
  ```text
  Tek Çekirdekte Eşzamanlı Yürütme (Concurrency):
  CPU: | T1 | T2 | T3 | T4 | T1 | T2 | T3 | T4 | T1 | ... ---> Zaman
  ```
- **Paralellik (Parallelism):** Çok çekirdekli bir sistemde birden fazla görevin aynı anda fiziksel olarak yürütülmesidir (gerçek paralellik). Tek çekirdekte 10 birim sürecek bir iş iki çekirdekte çok daha kısa sürede tamamlanır:
  ```text
  Çok Çekirdekte Paralel Yürütme (Parallelism):
  Core 1: | T1 | T3 | T1 | T3 | T1 | ... ---> Zaman
  Core 2: | T2 | T4 | T2 | T4 | T2 | ... ---> Zaman
  ```

### 3.3 Paralellik Türleri ve Donanım Desteği

Paralellik kendi içinde ikiye ayrılır:

- **Veri paralelliği (Data parallelism):** Aynı verinin alt kümelerinin birden fazla çekirdeğe dağıtılması ve her çekirdekte aynı işlemin (aynı `X` fonksiyonunun) çalıştırılıp sonuçların sonradan birleştirilmesidir.
- **Görev paralelliği (Task parallelism):** Verinin değil, farklı görevlerin (thread'lerin) çekirdeklere dağıtılmasıdır. Her thread kendine özgü bir işlemi (bir çekirdek `X` fonksiyonunu, diğer çekirdek `Y` fonksiyonunu) yürütür; bu thread'ler aynı veri üzerinde veya farklı veriler üzerinde çalışabilir.

Yazılımsal thread sayısının artmasıyla birlikte donanım mimarisi desteği (architectural support) de gelişmiştir. İşlemciler fiziksel çekirdeklerin (cores) yanı sıra her çekirdek içinde birden fazla **donanım iş parçacığı (hardware threads)** barındırabilir. Örneğin Intel işlemcilerde genellikle çekirdek sayısının iki katı kadar donanım thread'i bulunur (8 fiziksel çekirdek varsa 16 donanım thread'i). Sun/Oracle SPARC T4 işlemcisinde ise 8 çekirdek ve her çekirdekte 8 donanım thread'i olmak üzere toplam $8 \times 8 = 64$ donanım thread'i desteği sunulmuştur.

## 4. Ortak Veri Paylaşan Thread'lerde Yürütme Sırası ve Amdahl Yasası

### 4.1 İki Thread ile Ortak Değişken Senaryosu

Hoca, çok iş parçacıklı bir proseste veri bölümünün ortak kullanılmasının yürütme sırasını nasıl etkilediğini göstermek için slayt üzerine (ekrandan, 00:31:50) şu örneği çizdi:

Başlangıçta ortak (global) bir `x = 1` değişkeni tanımlanmıştır. Ana program (`main`), `f()` ve `g()` fonksiyonlarını normal fonksiyon çağrısı olarak değil, iki ayrı **thread** olarak başlatır:

```text
Ortak veri: x = 1

Thread 1 - f() (Yıldız * senaryosu):     Thread 2 - g() (Üçgen Δ senaryosu):
1. x++                                   1. print(x)
2. print(x)                              2. x *= 2
                                         3. print(x)
```

Eğer `f()` ve `g()` sıradan fonksiyon çağrıları olsaydı önce `f()` baştan sona çalışıp biter, ardından `g()` çalışıp biterdi. Ancak bunlar iki ayrı thread olarak oluşturulduğunda, işlemci zamanlayıcısının (scheduler) hangi thread'i önce çalıştıracağını ve hangi satırdan sonra bağlam değiştireceğini önceden bilemeyiz. Her bir satırın kendi içinde **atomik (bölünemez)** olduğu varsayımıyla (aslında C'deki `print` çağrısı makine dili seviyesinde birden fazla komuttan oluştuğu için bölünebilir olsa da ilk analiz için atomik kabul edilir) olası yürütme senaryoları şöyledir:

- **Yıldız (`f()`) senaryosundan başlanırsa:**
  - İlk olarak `f()` içindeki `x++` çalışır ve `x` değeri `1`'den `2`'ye çıkar. Dolayısıyla yürütme `f()`'ten başlarsa ekranda **`1` görme ihtimali yoktur**; görülecek ilk sayı mutlaka `2` olacaktır.
  - Ardından `f()` içindeki `print(x)` çalışıp ekrana `2` yazdırabilir, sonra `g()`'ye geçilip `print(x)` ile bir kez daha `2` yazdırılabilir, ardından `x *= 2` ile `x = 4` olup son `print(x)` ile `4` yazdırılabilir (çıktı: `2, 2, 4`).
  - Veya `f()` içinde `x++` (`x = 2`) yapıldıktan hemen sonra (`f()` henüz yazdırmadan) işlemci `g()`'ye geçer; `g()` ekrana `2` yazar, `x *= 2` ile `x = 4` yapar ve ekrana `4` yazar, ardından `f()` kaldığı yerden devam edip kendi `print(x)` satırıyla bir kez daha `4` yazar (çıktı: `2, 4, 4`).
- **Üçgen (`g()`) senaryosundan başlanırsa:**
  - İlk olarak `g()` içindeki ilk `print(x)` çalışır ve ekrana `1` yazdırılır.
  - Sonra ister `g()` içindeki `x *= 2` (`1 * 2 = 2`) çalışsın, ister `f()` içindeki `x++` (`1 + 1 = 2`) çalışsın, `x` değeri `2` olur.
  - Örneğin `g()` önce `1` yazdırıp `x *= 2` ile `x = 2` yaptıktan hemen sonra (`g()` ikinci `print(x)` satırını çalıştırmadan) işlemci `f()`'e geçip `x++` çalıştırırsa `x = 3` olur. Bu durumda ekranda önce `1` görülür, **`2` değeri ekrana hiç basılmadan** doğrudan `3` görülür (çıktı: `1, 3, 3`).

> **Hocanın vurgusu:** İki thread ve birkaç satırlık kodda bile planlamaya bağlı olarak çok sayıda farklı çıktı senaryosu oluşmaktadır; dört farklı thread fonksiyonu olduğunda durum çok daha karmaşık hale gelir. Sınavda bu tür yürütme sırası ve mantık soruları sorulabilir.

### 4.2 Amdahl Yasası (Amdahl's Law)

Hem seri (ardışıl) hem de paralel bileşenler içeren bir uygulamaya ek işlemci çekirdekleri eklendiğinde elde edilebilecek potansiyel hızlanma kazancını (speedup) **Amdahl Yasası** formüle eder (ekrandan, 00:38:10 ve 00:41:20).

Bir işin tamamının tek çekirdekte çalışma süresine $t$ diyelim. Uygulamanın seri olarak çalışmak zorunda olan kısmının tüm işe oranı $S$ ($0 \le S \le 1$) ise, paralelleştirilebilir kısmının oranı $1 - S$ olur:

- Tek çekirdekte seri kısım $S \cdot t$, paralel kısım $(1 - S) \cdot t$ sürer; toplam süre $t$'dir.
- Sistemde $N$ adet işlemci çekirdeği (veya thread) bulunduğunda, seri kısım bölünemediği için yine $S \cdot t$ sürer; paralel kısım ise $N$ çekirdeğe bölünerek $\frac{(1 - S) \cdot t}{N}$ sürede tamamlanır.
- Tek çekirdekli sürenin ($t$), $N$ çekirdekli süreye oranlanmasıyla ($t$ çarpanları sadeleşerek) hızlanma üst sınırı elde edilir:

$$\text{speedup} \le \frac{1}{S + \frac{1 - S}{N}}$$

#### Sayısal Örnek 1 (Derste Çözülen Örnek)

Normalde tek çekirdekte $t = 10\text{ saniyede}$ biten bir işin %50'si seri ($S = 0.50$), %50'si paralelleştirilebilir ($1 - S = 0.50$) olsun ve sistemde $N = 5$ çekirdek bulunsun:

- **Verilenler:** $t = 10\text{ sn}$, $S = 0.50$, $1 - S = 0.50$, $N = 5$.
- **Seri kısmın süresi:** $10 \times 0.50 = 5\text{ sn}$ (çekirdek sayısından bağımsız, değişmez).
- **Paralel kısmın 5 çekirdekteki süresi:** $\frac{10 \times 0.50}{5} = \frac{5}{5} = 1\text{ sn}$.
- **Yeni toplam süre:** $5 + 1 = 6\text{ sn}$ (10 saniyeden 6 saniyeye inerek %40 süre kazancı sağlanır).
- **Hızlanma (speedup):** $\frac{1}{0.50 + \frac{0.50}{5}} = \frac{1}{0.50 + 0.10} = \frac{1}{0.60} = \frac{10}{6} \approx 1.67\text{ kat}$.

> **Ders sonrası not:** Hoca 00:40:15 civarında formülde oranları yüzde olarak yazarken $\frac{1}{50 + 50/5} = \frac{1}{60}$ şeklinde yazmıştır; formülde $S$ ve $1 - S$ oranları $[0, 1]$ aralığında ondalık sayı olarak ($0.50$) yerine konduğunda payda $0.60$ (yani sürenin %60'a düşmesi) ve hızlanma katsayısı $\frac{1}{0.60} \approx 1.67$ olur.

#### Sayısal Örnek 2 (Slayttaki Örnek)

Bir uygulamanın %75'i paralel ($1 - S = 0.75$) ve %25'i seri ($S = 0.25$) olsun. 1 çekirdekten $N = 2$ çekirdeğe geçildiğinde:

- 100 birimlik (100 saniyelik) işin seri kısmı $25\text{ sn}$, ikiye bölünen paralel kısmı $\frac{75}{2} = 37.5\text{ sn}$ sürer; toplam süre $25 + 37.5 = 62.5\text{ sn}$ olur.
- Hızlanma:
  $$\text{speedup} = \frac{1}{0.25 + \frac{0.75}{2}} = \frac{1}{0.25 + 0.375} = \frac{1}{0.625} = 1.6\text{ kat}$$

#### Sonsuz Çekirdek Limiti ($N \to \infty$)

Denklemde çekirdek sayısı sonsuza götürüldüğünde ($N \to \infty$), $\frac{1 - S}{N} \to 0$ olur ve hızlanma şu üst sınıra yaklaşır:

$$\lim_{N \to \infty} \text{speedup} = \frac{1}{S}$$

Örneğin işin %25'i seri ise ($S = 0.25$, 100 saniyelik işin 25 saniyesi), sisteme sonsuz tane çekirdek eklense bile paralel kısım sıfıra yaklaşırken 25 saniyelik seri kısım aynen kalır; toplam süre 25 saniyenin altına inemez ve hızlanma en fazla $\frac{1}{0.25} = 4$ kat olabilir. Dolayısıyla uygulamanın seri kısmı, ek çekirdeklerle elde edilebilecek performans kazancı üzerinde orantısız (disproportionate) bir kısıtlama yaratır.

## 5. Kullanıcı ve Çekirdek Thread'leri ile Eşleştirme Modelleri

Bilgisayar sisteminin katmanlı mimarisinde en altta donanım (hardware), onun üzerinde işletim sistemi çekirdeği (kernel mode) ve üstte kullanıcı uygulamaları (user mode) yer alır. Buna paralel olarak thread'ler de iki seviyede incelenir:

- **Kullanıcı Thread'leri (User Threads):** Çekirdeğin üzerinde, kullanıcı seviyesindeki thread kütüphaneleri (POSIX Pthreads, Windows threads, Java threads) tarafından yönetilir.
- **Çekirdek Thread'leri (Kernel Threads):** Doğrudan işletim sistemi çekirdeği tarafından desteklenir ve yönetilir (Windows, Linux, Mac OS X, Solaris, Tru64 UNIX gibi çağdaş genel amaçlı işletim sistemlerinin tamamında çekirdek thread desteği vardır).

Kullanıcı seviyesinde oluşturulan thread'lerin donanım üzerinde çalışabilmesi için çekirdek seviyesindeki thread'lerle ilişkilendirilmesi gerekir. Bunun için dört eşleştirme modeli tanımlanmıştır:

### 5.1 Çoğa-Bir Modeli (Many-to-One)

Kullanıcı seviyesindeki birden fazla thread, çekirdek seviyesindeki **tek bir çekirdek thread'ine** eşleştirilir:

```text
Kullanıcı Seviyesi:   [UT1]   [UT2]   [UT3]   [UT4]
                         \      |      |      /
                          v     v      v     v
Çekirdek Seviyesi:               ( KT1 )
```

- **Avantajı:** Thread yönetimi kullanıcı alanında yapılır ve çekirdekte fazla thread oluşturup kaynak israfı yapılmaz.
- **Dezavantajları:**
  1. Kullanıcı thread'lerinden herhangi biri bloklayan bir sistem çağrısı yaparsa, eşleştiği tek çekirdek thread'i de bloklanacağından **tüm proses (diğer tüm kullanıcı thread'leri) bloklanır**.
  2. Çekirdekte yalnızca tek bir thread bulunduğu için, tüm kullanıcı thread'leri aynı anda çalışmak istese bile çok çekirdekli bir sistemde **gerçek paralellik sağlanamaz**; hepsi tek çekirdek thread'i üzerinden seri olarak yürütülür.
- **Örnekler:** Solaris Green Threads, GNU Portable Threads (günümüzde çok az sistem bu modeli kullanır).

### 5.2 Bire-Bir Modeli (One-to-One)

Her bir kullanıcı seviyesi thread'i, ayrı bir çekirdek thread'ine eşleştirilir:

```text
Kullanıcı Seviyesi:   [UT1]   [UT2]   [UT3]   [UT4]
                        |       |       |       |
                        v       v       v       v
Çekirdek Seviyesi:    (KT1)   (KT2)   (KT3)   (KT4)
```

- **Avantajı:** Bir thread bloklandığında diğerleri çalışmaya devam edebilir ve çok işlemcili sistemlerde thread'ler farklı çekirdeklerde paralel çalışabilir; Çoğa-Bir modeline göre çok daha yüksek eşzamanlılık sağlar.
- **Dezavantajı:** Her kullanıcı thread'i oluşturulduğunda karşılığında bir de çekirdek thread'i oluşturulması gerekir; çok sayıda çekirdek thread'i sistem performansına ek yük (overhead) getirir.
- **Örnekler:** Windows, Linux, Solaris 9 ve sonrası.

### 5.3 Çoğa-Çok Modeli (Many-to-Many)

Kullanıcı seviyesindeki $M$ adet thread, çekirdek seviyesindeki daha az veya eşit sayıda ($N \le M$) çekirdek thread'ine çoğullanır (multiplex edilir):

```text
Kullanıcı Seviyesi (M):   [UT1]   [UT2]   [UT3]   [UT4]
                             \     /         \     /
                              \   /           \   /
Çekirdek Seviyesi (N <= M):   (KT1)   (KT2)   (KT3)
```

- Her kullanıcı thread'i sürekli çalışmadığı (zaman zaman kesme veya G/Ç beklemesine geçtiği) için çekirdekte boşta thread bekletmek yerine $M > N$ olacak şekilde bir havuz eşleştirmesi yapılır. Bir thread bloklandığında çekirdek başka bir kullanıcı thread'ini boşta olan çekirdek thread'ine atayabilir.
- Hoca bu modelde planlamadan kaynaklı olarak bazı kullanıcı thread'lerine uzun süre çekirdek thread'i sırası gelmemesi (**açlık / starvation**) riskine dikkat çekti; önemli bir kullanıcı thread'i çekirdek thread'i alamazsa işlemlerde gecikmeler yaşanabilir.

### 5.4 İki Seviyeli Model (Two-Level Model)

Çoğa-Çok modelinin sağladığı esnekliği korurken açlık ve gecikme sorununu önlemek için Çoğa-Çok ile Bire-Bir yaklaşımlarını birleştirir:

```text
Kullanıcı Seviyesi:   [UT1]   [UT2]   [UT3]       [UT4 (Öncelikli)]
                         \     |     /                    |
                          \    |    /                     v
Çekirdek Seviyesi:        (KT1) (KT2)                   (KT3)
                         (Many-to-Many)              (One-to-One)
```

Normal thread'ler Çoğa-Çok (Many-to-Many) havuzunda eşleştirilirken, yüksek önceliğe veya ayrıcalığa (privilege) sahip kritik bir kullanıcı thread'i doğrudan kendine özel bir çekirdek thread'ine Bire-Bir (One-to-One) bağlanır. Böylece o ayrıcalıklı thread beklemeye takılmadan doğrudan kendi çekirdek thread'ini kullanır ve bloklansa bile diğer thread'ler kendi havuzlarında çalışmaya devam eder (IRIX, HP-UX, Tru64 UNIX, Solaris 8 ve öncesi).

## 6. Thread Kütüphaneleri: Pthreads, Windows ve Java

Thread kütüphaneleri programcıya thread oluşturmak ve yönetmek için bir Uygulama Programlama Arayüzü (API) sunar. İki temel gerçekleme yolu vardır:

1. Çekirdek desteği olmadan tamamen **kullanıcı alanında (user space)** kütüphane sağlamak (kütüphane fonksiyonu çağrıları sistem çağrısı değil, yerel fonksiyon çağrısıdır).
2. İşletim sistemi tarafından desteklenen **çekirdek seviyesinde (kernel-level)** kütüphane sağlamak (kütüphane çağrıları çekirdeğe sistem çağrısı yapılmasına yol açar).

Günümüzde en yaygın üç thread kütüphanesi **POSIX Pthreads**, **Windows Threads** ve **Java Threads**'dir.

### 6.1 POSIX Pthreads

POSIX standardı (**IEEE 1003.1c**) kapsamında tanımlanmış, kullanıcı veya çekirdek seviyesinde gerçeklenebilen bir thread standardıdır; Linux ve macOS sistemlerinde yaygın olarak kullanılır (Windows'ta da `windows.h` thread yapılarını sarmalayan Pthreads uyumluluk kütüphaneleri mevcuttur). POSIX fonksiyon ve veri tipi adlandırma standardında kelimeler küçük harfle ve alt çizgi (`_`) ile ayrılır (`pthread_create`, `pthread_join`, `pthread_exit`, `pthread_attr_init`).

Slayttaki Pthreads toplama örneği (ekrandan, 01:10:20; `gcc -Wall` ile derlenip test edilmiştir):

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* thread'ler tarafindan paylasilan veri */
void *runner(void *param); /* thread'in calistiracagi fonksiyon */

int main(int argc, char *argv[]) {
    pthread_t tid;       /* thread kimligi (identifier) */
    pthread_attr_t attr; /* thread oznitelikleri (stack boyutu, zamanlama vb.) */

    if (argc != 2) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    /* varsayilan oznitelikleri al */
    pthread_attr_init(&attr);
    /* thread'i olustur */
    pthread_create(&tid, &attr, runner, argv[1]);
    /* thread'in sonlanmasini bekle */
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
    return 0;
}

/* Thread kontrolu bu fonksiyonda baslar */
void *runner(void *param) {
    int i, upper = atoi(param);
    sum = 0;

    for (i = 1; i <= upper; i++)
        sum += i;

    pthread_exit(0);
}
```

Kodun çalışma adımları:

- **`void *runner(void *param)`:** Thread tarafından çalıştırılacak fonksiyon `void *` türünde genel (generic) bir işaretçi parametre alır ve `void *` döndürür; böylece tam sayıdan karmaşık bir `struct` veya bağlı liste düğümüne kadar her türlü veri adres yoluyla thread'e geçirilebilir ve döndürülebilir.
- **`pthread_create(&tid, &attr, runner, argv[1])`:** Bu çağrı yapıldığı anda `main` thread'inin yanında ikinci bir yürütme akışı olarak `runner` fonksiyonu çalışmaya başlar ve komut satırı argümanı (`argv[1]`) parametre olarak aktarılır.
- **`pthread_join(tid, NULL)`:** `fork()` işlemindeki `wait()` çağrısına benzer; ana program (`main`), `tid` kimlikli thread işini bitirip `pthread_exit(0)` çağırana kadar bu satırda bekler. Eğer thread sonlanırken bir dönüş değeri göndermişse `pthread_join`'in ikinci parametresine bir işaretçi adresi verilerek bu değer alınabilir.
- **Çok sayıda thread'i döngüyle oluşturma ve bekleme:** Örneğin 10 thread çalıştırılacaksa `pthread_t workers[NUM_THREADS];` dizisi tanımlanır; bir `for` döngüsüyle tüm thread'ler oluşturulur ve ardından ikinci bir `for` döngüsüyle her biri için `pthread_join(workers[i], NULL);` çağrılır.
- **Birden fazla argüman gönderme:** Thread fonksiyonuna ID, toplam ve mesaj gibi birden çok veri gönderilecekse `struct thread_data { int thread_id; int sum; char *message; };` gibi bir yapı dizisi tanımlanır, adres `(void *)&thread_data_array[t]` şeklinde `pthread_create`'e verilir ve fonksiyon içinde `(struct thread_data *)threadarg` tür dönüşümüyle (casting) okunur.

### 6.2 Windows Threads

Windows API (`<windows.h>`) çekirdek seviyesinde Bire-Bir modelini kullanan thread fonksiyonları sunar (ekrandan, 01:20:00):

```c
/* thread'i olustur */
ThreadHandle = CreateThread(
    NULL,       /* varsayilan guvenlik oznitelikleri */
    0,          /* varsayilan yigin (stack) boyutu */
    Summation,  /* thread fonksiyonu */
    &Param,     /* thread fonksiyonuna gonderilecek parametre */
    0,          /* varsayilan olusturma bayraklari */
    &ThreadId); /* thread kimligini dondurur */

if (ThreadHandle != NULL) {
    /* thread'in bitmesini bekle (Pthreads'teki pthread_join karsiligi) */
    WaitForSingleObject(ThreadHandle, INFINITE);

    /* thread taniticisini (handle) kapat */
    CloseHandle(ThreadHandle);

    printf("sum = %d\n", Sum);
}
```

### 6.3 Java Threads

Java'da thread'ler JVM (Java Virtual Machine) tarafından yönetilir ve alttaki işletim sisteminin thread modeli kullanılarak gerçeklenir. Java'da thread oluşturmanın iki temel yolu vardır:

1. `Thread` sınıfından yeni bir sınıf türetmek (`extends Thread`) ve `public void run()` metodunu geçersiz kılmak (override).
2. **`Runnable` arayüzünü** (`public interface Runnable { public abstract void run(); }`) gerçekleyen (`implements Runnable`) bir sınıf tanımlamak ve bu sınıfın nesnesini `Thread` kurucusuna parametre olarak vermek.

`Thread` nesnesi üzerinden `.start()` metodu çağrıldığında bellekte yeni thread için yer ayrılır ve JVM içinde `run()` metodu çağrılır; ana thread ise `thrd.join()` ile alt thread'in tamamlanmasını bekler.

## 7. Örtük İş Parçacığı Kullanımı (Implicit Threading)

Uygulamalarda thread sayısı yüzlere veya binlere çıktığında, programcının her thread'i açıkça oluşturup (`create`), eşzamanlayıp sonlandırmasını (`join`) yönetmesi zorlaşır ve hata riskini artırır. **Örtük iş parçacığı kullanımı (implicit threading)** yaklaşımında thread oluşturma ve yönetimi uygulama geliştiriciden alınarak **derleyicilere (compilers)** ve **çalışma zamanı kütüphanelerine (run-time libraries)** devredilir. Başlıca üç yöntem incelenmiştir:

1. **Thread Havuzları (Thread Pools):** Her istek geldiğinde sıfırdan thread oluşturmak yerine, proses başlarken belirli sayıda thread oluşturulup bir havuzda bekletilir. Yeni bir iş geldiğinde havuzdan boş bir thread uyandırılıp göreve atanır (boş thread yoksa iş kuyrukta bekler); thread işi bitirdiğinde yok edilmez, tekrar kullanılmak üzere havuza döner. Böylece thread oluşturma maliyeti ortadan kalkar ve sistemdeki toplam eşzamanlı thread sayısı sınırlandırılmış olur.
2. **OpenMP:** C, C++ ve FORTRAN dillerinde paylaşımlı bellek ortamlarında paralel programlama desteği sağlayan derleyici direktifleri (`#pragma`) ve API kümesidir (ekrandan, 01:24:40). Paralel çalışabilecek kod bloklarını (**parallel regions**) işaretler ve sistemdeki çekirdek sayısı kadar thread oluşturarak işi paylaştırır:

   ```c
   #include <omp.h>
   #include <stdio.h>

   int main(int argc, char *argv[]) {
       /* seri kod (sequential code) */

       #pragma omp parallel
       {
           printf("I am a parallel region.");
       }

       /* seri kod (sequential code) */
       return 0;
   }
   ```

   Bir `for` döngüsündeki bağımsız dizi toplama işlemini çekirdekler arasında otomatik bölmek için `#pragma omp parallel for` direktifi kullanılır:

   ```c
   #pragma omp parallel for
   for (i = 0; i < N; i++) {
       c[i] = a[i] + b[i];
   }
   ```

3. **Grand Central Dispatch (GCD):** Apple tarafından macOS ve iOS için geliştirilmiş, C ve Objective-C dillerine çalışma zamanı kütüphanesi ve dil uzantısı olarak eklenmiş teknolojidir. Paralel çalışacak kod parçaları şapka ve süslü parantez (`^{ printf("I am a block"); }`) ile **blok (block)** olarak tanımlanır ve GCD'nin yönettiği dağıtım kuyruklarına (dispatch queues) yerleştirilir.

## 8. Çok İş Parçacıklı Sistemlerde Temel Problemler

Çok iş parçacıklı programlama hız ve verimlilik sağlarken işletim sistemi ve uygulama tasarımında dikkat edilmesi gereken önemli sorunlar doğurur:

### 8.1 `fork()` ve `exec()` Sistem Çağrılarının Semantiği

Çok iş parçacıklı bir proseste thread'lerden biri `fork()` sistem çağrısı yaptığında yeni çocuk proses nasıl oluşturulmalıdır? UNIX sistemlerinde bunun iki farklı biçimi vardır:

- Birincisi **tüm thread'leri kopyalar** (çoğaltır).
- İkincisi **yalnızca `fork()` çağrısını yapan thread'i** kopyalar.

`exec()` sistem çağrısı ise normalde çalıştığı gibi çalışır: çağrıldığı anda **tüm prosesin adres uzayını (dolayısıyla içindeki tüm thread'leri)** yeni programla değiştirir. Bu nedenle `fork()` sonrasında hemen `exec()` çağrılacaksa tüm thread'leri kopyalamak gereksizdir, yalnızca çağıran thread'in kopyalanması yeterlidir; ancak çocuk proses `exec()` çağırmadan çalışmaya devam edecekse tüm thread'lerin kopyalanması gerekebilir.

### 8.2 Sinyal İşleme (Signal Handling)

UNIX/Linux sistemlerinde **sinyaller (signals)**, belirli bir olayın gerçekleştiğini bir prosese bildirmek için kullanılır (örneğin `Ctrl+C` tuşlarıyla prosesi sonlandırmak veya bir kesme göndermek). Her sinyal şu adımları izler:

1. Belirli bir olay sinyali üretir.
2. Sinyal ilgili prosese iletilir.
3. Sinyal, iki sinyal işleyiciden (signal handler) biri tarafından ele alınır: çekirdeğin çalıştırdığı **varsayılan işleyici (default handler)** veya programcının tanımladığı **kullanıcı tanımlı işleyici (user-defined handler)** (örneğin `Ctrl+C` geldiğinde kapanmadan önce verileri dosyaya kaydeden özel bir fonksiyon).

Tek iş parçacıklı proseste sinyal doğrudan prosese giderken, örneğin 10 thread içeren çok iş parçacıklı bir proseste sinyalin nereye iletileceği konusunda dört seçenek vardır:

1. Sinyali, **sinyalin uygulanacağı (neden olan) thread'e** iletmek.
2. Sinyali prosesteki **tüm thread'lere** iletmek.
3. Sinyali prosesteki **belirli bazı thread'lere** iletmek.
4. Prosesin alacağı tüm sinyalleri karşılamak üzere **özel bir thread** görevlendirmek.

### 8.3 Thread İptali (Thread Cancellation)

Bir thread'in görevini tamamlamadan önce dışarıdan sonlandırılması işlemine **thread iptali (thread cancellation)**, iptal edilmek istenen thread'e ise **hedef thread (`target thread`)** denir. İki genel yaklaşım vardır:

- **Asenkron iptal (Asynchronous cancellation):** Hedef thread'i derhal, anında sonlandırır. Ancak hedef thread o sırada paylaşılan bir veriyi güncelliyorsa veya `malloc` ile sistem kaynakları tahsis etmişse, bu kaynaklar serbest bırakılamadan kesileceği için tehlikelidir.
- **Ertelenmiş iptal (Deferred cancellation):** Hedef thread kendi içinde periyodik olarak sonlanması gerekip gerekmediğini kontrol eder (iptal noktaları / cancellation points). Bu sayede thread kendisine tahsis edilmiş bellek ve kaynakları güvenli biçimde serbest bırakıp kaydedilmesi gereken verileri kaydettikten sonra düzenli olarak sonlanır.

Pthreads'te iptal isteği `pthread_cancel(tid);` ile gönderilir ve **varsayılan iptal türü ertelenmiş iptaldir (deferred cancellation)**.

### 8.4 Thread-Yerel Depolama (Thread-Local Storage - TLS) ve LWP

- **Thread-Local Storage (TLS):** Her thread'in kendi verisinin bir kopyasına sahip olmasını sağlar. Özellikle programcının thread oluşturma sürecini doğrudan kontrol edemediği (örneğin thread havuzu kullanılan) durumlarda faydalıdır. Yerel değişkenlerden farkı, yerel değişkenlerin yalnızca tek bir fonksiyon çağrısı süresince görünür olması, TLS verisinin ise fonksiyon çağrıları boyunca (`static` veriye benzer biçimde, ancak her thread'e özel olarak) yaşamasıdır.
- **Zamanlayıcı Aktivasyonları (Scheduler Activations) ve LWP (Lightweight Process):** Çoğa-Çok (Many-to-Many) ve İki Seviyeli (Two-Level) modellerde kullanıcı thread kütüphanesi ile çekirdek arasındaki iletişimi sağlamak için araya **Hafif Proses (Lightweight Process - LWP)** adı verilen bir ara veri yapısı konur. LWP, uygulamanın kullanıcı thread'lerini zamanlayabileceği **sanal bir işlemci (virtual processor)** gibi görünür ve her LWP bir çekirdek thread'ine bağlıdır.

## 9. İşletim Sistemi Örnekleri: Windows ve Linux Thread Yapıları

### 9.1 Windows Threads

Windows API çekirdek seviyesinde **Bire-Bir (One-to-One)** eşleştirme kullanır. Her Windows thread'i şu bileşenleri içerir:

- Bir thread kimliği (thread ID),
- İşlemci durumunu temsil eden yazmaç kümesi (register set),
- Kullanıcı modunda çalışırken kullanılan ayrı bir **kullanıcı yığını (user stack)** ve çekirdek modunda çalışırken kullanılan ayrı bir **çekirdek yığını (kernel stack)**,
- Çalışma zamanı kütüphaneleri (run-time libraries) ve dinamik bağlantı kütüphaneleri (DLL'ler) tarafından kullanılan özel veri depolama alanı (private data storage area).

Yazmaç kümesi, yığınlar ve özel depolama alanı birlikte thread'in **bağlamı (context)** olarak adlandırılır. Windows'ta bir thread'in temel veri yapıları üç parçalıdır:

1. **`ETHREAD` (Executive Thread Block):** Çekirdek alanında (kernel space) bulunur; thread'in ait olduğu prosesi gösteren işaretçiyi ve başlangıç adresini içerir, `KTHREAD`'e işaret eder.
2. **`KTHREAD` (Kernel Thread Block):** Çekirdek alanında bulunur; thread'in zamanlama ve senkronizasyon bilgilerini, çekirdek yığınını ve `TEB` işaretçisini tutar.
3. **`TEB` (Thread Environment Block):** Kullanıcı alanında (user space) bulunur; thread kimliğini, kullanıcı yığınını ve thread-yerel depolama (TLS) dizisini barındırır.

### 9.2 Linux Threads

Linux işletim sistemi prosesler ile thread'ler arasında ayrı veri yapıları kullanmaz; her yürütme birimini **görev (`task`)** olarak adlandırır ve tek bir `struct task_struct` veri yapısıyla temsil eder (ekrandan, 01:40:00).

Linux'ta yeni bir thread oluşturmak için `clone()` sistem çağrısı kullanılır. `clone()` çağrısına geçirilen bayraklar (flags), çocuk görevin (child task) ebeveyn görevin (parent task) veri yapılarını ne ölçüde paylaşacağını belirler:

| Bayrak (Flag) | Anlamı (Meaning) |
|---|---|
| `CLONE_FS` | Dosya sistemi bilgisi paylaşılır (File-system information is shared). |
| `CLONE_VM` | Aynı bellek uzayı paylaşılır (The same memory space is shared). |
| `CLONE_SIGHAND` | Sinyal işleyiciler paylaşılır (Signal handlers are shared). |
| `CLONE_FILES` | Açık dosyalar kümesi paylaşılır (The set of open files is shared). |

`struct task_struct`, proses veri yapılarını doğrudan içinde tutmak yerine onlara işaretçilerle (pointers) gösterir. `clone()` çağrılırken yukarıdaki bayraklar verilirse çocuk görevin `task_struct` yapısı ebeveynin tablolarına işaret eder (böylece thread oluşur); bayraklar verilmezse tablolar kopyalanır (`fork()` davranışı oluşur).

### 9.3 Teorik Bölüm Soru-Cevapları

**Soru:** Ana program (`main`), oluşturduğu thread'leri `join` ile beklemeden `return 0` satırına ulaşıp sonlanabilir mi ve bu durumda thread'lere ne olur? Thread'lerde de proseslerdeki gibi "zombi" kavramı var mıdır?
**Cevap:** Ana program `join` yapmadan `return 0` ile sonlanabilir; oluşturulan thread'ler kısa bir süre daha çalışmaya devam eder gibi görünse de ana proses sonlandığı için işletim sistemi tarafından kısa süre içinde tüm thread'ler yok edilir. Bu durum istenmediği için ana programın `join` ile alt thread'leri beklemesi gerekir. Thread'ler için doğrudan "zombi" şeklinde standart bir adlandırma (hocanın bilgisi dahilinde) yoktur; mantık tüm dillerde ve kütüphanelerde thread'in işini bitirmesi, `join` yapılması ve ardından ana programın kapanması şeklindedir.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla POSIX Pthreads standardında, `pthread_detach()` ile ayrılmamış (joinable durumdaki) bir thread sonlandığında, başka bir thread onun için `pthread_join()` çağırana kadar çıkış durumu ve thread tanımlayıcısı bellekte tutulmaya devam eder; bu durum işlevsel olarak zombi prosese benzer. Ayrıca `main()` fonksiyonu `pthread_exit()` yerine normal `return` veya `exit()` ile çıkarsa prosesin tamamı sonlandırıldığı için çalışan tüm thread'ler anında kapatılır.

**Soru:** Linux'ta thread'lerin `task` (görev) olarak adlandırılması, `multithreading` ile `multitasking` kavramlarının aynı şey olduğu anlamına mı gelir?
**Cevap:** Hayır, `multitasking` ile `multithreading` birbirinden farklı kavramlardır. `task` kelimesi yalnızca Linux çekirdeğinin kendi iç tasarımında hem proses hem de thread yapılarını adlandırmak için kullandığı terminolojidir; kavramsal ayrımı değiştirmez.

## 10. Uygulama: POSIX IPC (Pipe, FIFO, Mesaj Kuyruğu, Paylaşımlı Bellek) ve Pthread Mutex

Dersin ikinci yarısındaki uygulama bölümünde, önceki hafta teorisi işlenen Prosesler Arası Haberleşme (IPC) yöntemlerinin POSIX standartlarındaki C gerçeklemeleri ve Pthreads `mutex` ile üretici-tüketici problemi incelenmiştir.

### 10.1 IPC Kalıcılık (Persistence) Sınıflandırması

POSIX IPC mekanizmaları yaşam sürelerine (kalıcılıklarına / persistence) göre üçe ayrılır:

1. **Proses Kalıcı (Process-Persistent):** IPC nesnesi, onu açan prosesler var olduğu sürece yaşar; son proses kapandığında çekirdek tarafından otomatik silinir (örneğin sıradan `pipe`).
2. **Çekirdek Kalıcı (Kernel-Persistent):** IPC nesnesi, prosesler kapansa bile açıkça silinene veya işletim sistemi çekirdeği yeniden başlatılana (reboot) kadar varlığını sürdürür (örneğin POSIX mesaj kuyrukları ve POSIX paylaşımlı bellek).
3. **Dosya Sistemi Kalıcı (Filesystem-Persistent):** IPC nesnesi dosya sisteminde bir düğüm olarak yer alır ve açıkça silinene (`unlink`) kadar (sistem yeniden başlatılsa bile kalıcı diskteyse) varlığını korur (örneğin adlandırılmış borular / FIFO).

### 10.2 Örnek 1: Sıradan Pipe (`Ex_1_pipe.c` ve `Ex_1_pipe1.c`)

Sıradan boru hattı (`pipe`), tek yönlü bir iletişim kanalıdır. `int pipe1[2];` dizisiyle `pipe(pipe1)` çağrıldığında `pipe1[0]` **okuma ucu (read end)**, `pipe1[1]` ise **yazma ucu (write end)** olur.

İlk örnekte (`Ex_1_pipe.c`, ekrandan, 02:04:30) tek bir pipe kullanılarak istemci (ebeveyn proses) kullanıcıdan bir dosya adı (`hello.txt`) alır ve pipe üzerinden sunucuya (çocuk proses) gönderir; sunucu bu dosyayı açıp içeriğini (`Hello Yildiz`) doğrudan terminale (`STDOUT_FILENO`) yazar (`gcc -Wall` ile derlenip test edilmiştir):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 80

void client(int writefd);
void server(int readfd);

int main(int argc, char *argv[]) {
    int pipe1[2];
    pid_t childpid;

    pipe(pipe1); /* Iletisim icin tek bir pipe olustur */

    if ((childpid = fork()) == 0) { /* Child process */
        close(pipe1[1]);            /* Ebeveynin kullandigi yazma ucunu kapat */
        server(pipe1[0]);           /* Okuma ucuyla server fonksiyonunu cagir */
        exit(0);
    }

    /* Parent process */
    close(pipe1[0]);                /* Cocugun kullandigi okuma ucunu kapat */
    client(pipe1[1]);               /* Yazma ucuyla client fonksiyonunu cagir */

    waitpid(childpid, NULL, 0);     /* Cocuk prosesin bitmesini bekle */
    exit(0);
}

void client(int writefd) {
    char buff[MAX_LINE];
    size_t len;

    printf("Enter filename: ");
    if (fgets(buff, MAX_LINE, stdin) == NULL)
        return;
    len = strlen(buff);
    if (len > 0 && buff[len - 1] == '\n')
        len--; /* Sondaki '\n' karakterini cikar */

    write(writefd, buff, len);
}

void server(int readfd) {
    int fd;
    ssize_t n;
    char buff[MAX_LINE + 1];

    if ((n = read(readfd, buff, MAX_LINE)) <= 0) {
        fprintf(stderr, "server: filename read error\n");
        exit(1);
    }
    buff[n] = '\0';

    if ((fd = open(buff, O_RDONLY)) < 0) {
        snprintf(buff, sizeof(buff), "Cannot open file\n");
        write(STDOUT_FILENO, buff, strlen(buff));
    } else {
        while ((n = read(fd, buff, MAX_LINE)) > 0) {
            write(STDOUT_FILENO, buff, n);
        }
        close(fd);
    }
}
```

İkinci örnekte (`Ex_1_pipe1.c`) çift yönlü iletişim kurmak amacıyla `pipe1[2]` ve `pipe2[2]` olmak üzere **iki ayrı pipe** tanımlanır:

- Çocuk proses (server): `close(pipe1[1]);` ve `close(pipe2[0]);` yaparak `pipe1[0]`'dan dosya adını okur, dosyayı açıp içeriğini `pipe2[1]` ucuna yazar (`write(writefd, buff, n)`).
- Ebeveyn proses (client): `close(pipe1[0]);` ve `close(pipe2[1]);` yaparak `pipe1[1]`'e dosya adını yazar, ardından `pipe2[0]`'dan sunucunun gönderdiği dosya içeriğini `while ((n = read(readfd, buff, MAX_LINE)) > 0)` döngüsüyle okuyup ekrana basar.

**Soru:** İkinci örnekte ebeveyn proses (`client`) dosya adını gönderdikten hemen sonra `read()` satırına ulaştığında, çocuk proses (`server`) henüz dosyayı okuyup `pipe2`'ye yazmadıysa `client` neden boş okuyup çıkmıyor?
**Cevap:** Uygulama anlatımında kodda açık bir senkronizasyon değişkeni kullanılmadığı, `read()` çağrısının pipe'tan veri gelmesini bekliyor olabileceği belirtildi ancak kesin nedeni açık bırakıldı.

> **Ders sonrası not:** POSIX standartlarına göre sıradan bir `pipe` (veya `FIFO`) varsayılan olarak **bloklayan (blocking)** modda açılır. Pipe tamponu boşken ama pipe'ın yazma ucu (`pipe2[1]`) en az bir proses tarafından açık tutuluyorken `read(pipe2[0], ...)` çağrısı yapılırsa, `read()` `0` döndürmez; çekirdek okuyan prosesi veri yazılana kadar **uyku (waiting/blocked)** durumuna alır. Çocuk proses `write()` yaptığında ebeveyn uyanıp veriyi okur; çocuk proses işini bitirip `exit(0)` ile çıktığında yazma ucu kapandığı için bir sonraki `read()` çağrısı dosya sonu (`EOF`, yani `0`) döndürür ve döngü sonlanır.

### 10.3 Örnek 2: Adlandırılmış Pipe / FIFO (`Ex_2_server.c` ve `Ex_2_client.c`)

Sıradan `pipe` yalnızca aynı dosya içinde `fork()` ile oluşturulmuş akraba prosesler arasında kullanılabilirken, **FIFO (Named Pipe)** dosya sisteminde bir yola (`/tmp/fifo.1` ve `/tmp/fifo.2`) sahip olduğu için iki ayrı kaynak dosyada yazılmış bağımsız `server` ve `client` programları arasında iletişim sağlar:

- Sunucu (`Ex_2_server.c`), `mkfifo(FIFO1, FIFO_MODE)` ve `mkfifo(FIFO2, FIFO_MODE)` çağrılarıyla (`/tmp/fifo.1` ve `/tmp/fifo.2`, `<sys/stat.h>` başlığıyla) iki FIFO dosyasını oluşturur. Ardından `readfd = open(FIFO1, O_RDONLY, 0);` ve `writefd = open(FIFO2, O_WRONLY, 0);` ile uçları açıp `server(readfd, writefd)` fonksiyonunu çalıştırır.
- İstemci (`Ex_2_client.c`), aynı yolları ters yönlü olarak (`writefd = open(FIFO1, O_WRONLY, 0);` ve `readfd = open(FIFO2, O_RDONLY, 0);`) açar, dosya adını gönderip yanıtı ekrana basar ve sonunda `close(readfd); close(writefd); unlink(FIFO1); unlink(FIFO2);` çağrılarıyla `/tmp` altındaki FIFO dosyalarını dosya sisteminden siler.

**Soru:** Aynı pipe veya FIFO'yu birden fazla proses aynı anda okuyabilir mi?
**Cevap:** Pipe veya FIFO'da bir veri okunduğunda tampondan tüketilir (silinir); bu nedenle aynı anda tek bir prosesin okuması veya birden fazla proses okuyacaksa erişimin senkronize edilmesi ya da her proses çifti için ayrı pipe/FIFO oluşturulması gerekir.

### 10.4 Örnek 3: POSIX Mesaj Kuyruğu (`Ex_4_mq_dropone.c` ve `Ex_4_mq_takeone.c`)

Pipe ve FIFO bayt akışı (byte stream) taşırken, **POSIX mesaj kuyrukları (`<mqueue.h>`)** belirli bir uzunluğa ve **önceliğe (priority)** sahip yapılandırılmış mesajlar göndermeye olanak tanır (ekrandan, 02:39:00):

- **Mesaj bırakan program (`Ex_4_mq_dropone.c`):** Komut satırından `getopt(argc, argv, "qp:")` ile `-q` (kuyruğu oluştur) ve `-p <öncelik>` argümanlarını alır. Kuyruğu açmak için:

  ```c
  if (create_queue) {
      msgq_id = mq_open(MSGQOBJ_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, NULL);
  } else {
      msgq_id = mq_open(MSGQOBJ_NAME, O_RDWR);
  }
  ```

  Ardından `snprintf` ile proses kimliğini (`getpid()`) ve zamanı içeren mesajı hazırlar ve `mq_send(msgq_id, msgcontent, strlen(msgcontent) + 1, msgprio);` ile belirtilen öncelikle kuyruğa bırakıp `mq_close(msgq_id);` ile kapatır.
- **Mesaj alan program (`Ex_4_mq_takeone.c`):** Kuyruğu `mq_open` ile açar, `mq_getattr(msgq_id, &msgq_attr)` ile kuyruk özniteliklerini (`mq_maxmsg`, `mq_msgsize`, `mq_curmsgs`) ekrana yazdırır. Bir `for` döngüsü içinde `mq_receive(msgq_id, msgcontent, MAX_MSG_LEN, &sender)` çağrısıyla mesajları okur ve sonunda `mq_close(msgq_id)` ve `mq_unlink(MSGQOBJ_NAME)` ile kuyruğu siler.
- **Çalıştırma sonucu:** Kuyruk `-q -p 3` ile oluşturulup sırasıyla `-p 1`, `-p 6` ve `-p 2` öncelikli dört mesaj eklendiğinde, alıcı program iki mesaj çektiğinde kuyruğa eklenme sırasına göre değil, **önceliği en yüksek olandan başlayarak** önce `priority 6`, ardından `priority 3` mesajını teslim alır.

### 10.5 Örnek 4: POSIX Paylaşımlı Bellek (`Ex_5_shm_server.c` ve `Ex_5_shm_client.c`)

Paylaşımlı bellekte iki proses ortak bir bellek segmentini kendi sanal adres uzaylarına eşleyerek (`mmap`) doğrudan bir C yapısı (`struct msg_s`) üzerinden haberleşir (ekrandan, 02:54:30):

```c
struct msg_s {
    int type;
    char content[MAX_MSG_LENGTH];
};
```

- **Sunucu (`Ex_5_shm_server.c`):**
  1. Varsa eski nesneyi `shm_unlink(SHMOBJ_PATH)` ile temizler.
  2. `shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_EXCL | O_RDWR, S_IRWXU | S_IRWXG);` ile paylaşımlı bellek nesnesini oluşturur.
  3. `ftruncate(shmfd, shared_seg_size);` ile bellek nesnesinin boyutunu `1 * sizeof(struct msg_s)` bayt olarak ayarlar.
  4. `shared_msg = (struct msg_s *)mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);` çağrısıyla nesneyi kendi sanal adres uzayındaki `shared_msg` işaretçisine eşler.
  5. `shared_msg->type = random() % TYPES;` ve `snprintf(shared_msg->content, ...)` ile doğrudan belleğe rastgele bir mesaj yazar (ör. `type = 4`).
- **İstemci (`Ex_5_shm_client.c`):** Aynı `SHMOBJ_PATH` nesnesini `shm_open(SHMOBJ_PATH, O_RDWR, S_IRWXU | S_IRWXG)` (`O_CREAT` olmadan) ile açar, `mmap` ile kendi `shared_msg` işaretçisine bağlar ve sunucunun yazdığı `shared_msg->type` ile `shared_msg->content` değerlerini doğrudan ekrana yazdırır.

### 10.6 Örnek 5: Pthreads ve Mutex ile Üretici-Tüketici (`ex_sm.c`)

Uygulamanın son örneğinde (ekrandan, 03:04:30), aynı proses içindeki bir üretici (`producer`) ve bir tüketici (`consumer`) thread'in 25 elemanlı dairesel bir tampon (`shared_buff`) üzerinden haberleşmesi ve ortak tamponun **`pthread_mutex_t`** kilidiyle korunması gösterilmiştir:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_MAX 25
#define MOD(x) ((x) % BUFF_MAX)

struct item {
    int data;
};

/* Paylasilan tampon ve senkronizasyon degiskenleri */
struct item shared_buff[BUFF_MAX];
int free_index = 0;
int full_index = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* producer(void* arg) {
    while (1) {
        struct item new_item;
        new_item.data = rand() % 100; /* 0-99 arasi rastgele veri uret */

        usleep(1000000); /* 1 saniye bekle */

        /* Tamponda yer acilana kadar bekle */
        while (MOD(free_index + 1) == full_index) {
            usleep(1000000);
        }

        /* Paylasilan kaynagi degistirmeden once mutex'i kilitle */
        pthread_mutex_lock(&mtx);
        shared_buff[free_index] = new_item;
        free_index = MOD(free_index + 1);
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        struct item consumed_item;
        usleep(1000000);

        /* Tamponda okunacak veri olana kadar bekle */
        while (free_index == full_index) {
            usleep(1000000);
        }

        pthread_mutex_lock(&mtx);
        consumed_item = shared_buff[full_index];
        full_index = MOD(full_index + 1);
        pthread_mutex_unlock(&mtx);

        printf("Consumed item: %d\n", consumed_item.data);
    }
    return NULL;
}
```

`main` fonksiyonunda `pthread_create` ile `producer` ve `consumer` thread'leri başlatılır; her iki thread de paylaşılan `shared_buff` dizisine erişmeden önce `pthread_mutex_lock(&mtx)` ile karşılıklı dışlama (mutual exclusion) sağlar ve işini bitirince `pthread_mutex_unlock(&mtx)` ile kilidi açar.

## Örnek Sorular

### Soru 1 (ekrandan, 00:31:50; derste sözlü, 00:31:50–00:36:15)

Ortak bir `x = 1` tam sayı değişkenini paylaşan iki iş parçacığı (`Thread 1: f()` ve `Thread 2: g()`) aşağıda verilmiştir. Her bir satırın kendi içinde atomik (bölünemez) çalıştığını varsayarak:

- `f()` fonksiyonu:
  1. `x++`
  2. `print(x)`
- `g()` fonksiyonu:
  1. `print(x)`
  2. `x *= 2`
  3. `print(x)`

a) Yürütmeye önce `f()` thread'inden başlanırsa ekranda ilk çıktı olarak `1` görülmesi mümkün müdür? Olası çıktı dizilerinden ikisini bulunuz.
b) Ekranda `2` değeri hiç görülmeden `1` ve ardından `3` yazdırılması mümkün müdür? Nasıl?

**Çözüm (derste verildi):**

- **a)** Yürütmeye `f()`'ten başlanırsa ilk çalışan komut `x++` olduğundan `x` değeri `1`'den `2`'ye çıkar; henüz hiçbir `print(x)` çalışmadığı için **ekranda `1` görülmesi imkânsızdır**.
  - Senaryo 1: `f: x++` ($x=2$) $\to$ `f: print(x)` (`2` yazar) $\to$ `g: print(x)` (`2` yazar) $\to$ `g: x *= 2` ($x=4$) $\to$ `g: print(x)` (`4` yazar) $\implies$ Çıktı: **`2, 2, 4`**.
  - Senaryo 2: `f: x++` ($x=2$) $\to$ `g: print(x)` (`2` yazar) $\to$ `g: x *= 2` ($x=4$) $\to$ `g: print(x)` (`4` yazar) $\to$ `f: print(x)` (`4` yazar) $\implies$ Çıktı: **`2, 4, 4`**.
- **b)** Evet, mümkündür. Yürütmeye `g()`'den başlanır:
  1. `g: print(x)` çalışır ve ekrana **`1`** yazar ($x=1$).
  2. `g: x *= 2` çalışır ve $x = 2$ olur (ancak henüz ekrana basılmaz).
  3. Bağlam değişimiyle işlemci `f()`'e geçer ve `f: x++` çalışarak $x = 3$ olur.
  4. Ardından `f: print(x)` ve `g: print(x)` çalıştığında ekrana **`3`** ve **`3`** basılır; böylece `2` değeri ekranda hiç görülmeden **`1, 3, 3`** çıktısı elde edilir.

### Soru 2 (ekrandan, 00:38:10 ve 00:41:20)

a) Tek çekirdekte 10 saniyede tamamlanan bir uygulamanın %50'si seri, %50'si paralel çalıştırılabilir niteliktedir. Bu uygulama 5 çekirdekli bir sistemde çalıştırılırsa kaç saniyede tamamlanır ve hızlanma oranı (speedup) ne olur?
b) Bir uygulamanın %75'i paralel, %25'i seri bileşenden oluşmaktadır. Sistem 1 çekirdekten 2 çekirdeğe çıkarıldığında hızlanma kaç kat olur? Çekirdek sayısı sonsuza ($N \to \infty$) götürülürse hızlanma en fazla kaç kat olabilir?

**Çözüm (derste verildi):**

- **a)** $t = 10\text{ sn}$, $S = 0.50$, $1 - S = 0.50$, $N = 5$:
  - Seri kısım: $10 \times 0.50 = 5\text{ sn}$.
  - Paralel kısım: $\frac{10 \times 0.50}{5} = 1\text{ sn}$.
  - Toplam süre: $5 + 1 = 6\text{ sn}$. Hızlanma: $\text{speedup} = \frac{1}{0.50 + \frac{0.50}{5}} = \frac{1}{0.60} \approx 1.67\text{ kat}$.
- **b)** $S = 0.25$, $1 - S = 0.75$, $N = 2$:
  - $\text{speedup} = \frac{1}{0.25 + \frac{0.75}{2}} = \frac{1}{0.25 + 0.375} = \frac{1}{0.625} = 1.6\text{ kat}$.
  - $N \to \infty$ iken $\frac{1 - S}{N} \to 0$ olduğundan $\text{speedup}_{\max} = \frac{1}{S} = \frac{1}{0.25} = 4\text{ kat}$ (100 birimlik sürede seri olan 25 birimin altına inilemez).

### Soru 3 (derste sözlü, 02:46:20–02:48:50)

Bir POSIX mesaj kuyruğuna (`mq_send` ile) sırasıyla öncelik (priority) değerleri `3`, `1`, `6` ve `2` olan dört mesaj ekleniyor. Alıcı proses bu kuyruktan `mq_receive` ile art arda iki mesaj okuduğunda hangi önceliğe sahip mesajları, hangi sırayla teslim alır?

**Çözüm (derste verildi):**

POSIX mesaj kuyruklarında `mq_receive` her zaman kuyruktaki en eski ve **en yüksek öncelikli** mesajı döndürür. Kuyruktaki mesajların öncelikleri `{3, 1, 6, 2}` olduğundan, alıcı ilk okumada **`6`** öncelikli mesajı, ikinci okumada ise **`3`** öncelikli mesajı teslim alır.

## Dersin Toparlaması

Bu derste ilk olarak çoklu programlama, çoklu işleme, çoklu görev ve çoklu iş parçacığı kavramları arasındaki farklar ortaya konmuş; bir prosesin kendi adres uzayı içinde kod, veri ve dosyaları paylaşan hafif yürütme birimleri olarak **iş parçacıkları (threads)** incelenmiştir. Çok çekirdekli sistemlerde eşzamanlılık (concurrency) ile paralellik (parallelism) ayrımı, veri ve görev paralelliği, Amdahl Yasası ile hızlanma üst sınırı, kullanıcı ve çekirdek thread'lerini eşleştirme modelleri (Many-to-One, One-to-One, Many-to-Many, Two-Level), Pthreads/Windows/Java thread kütüphaneleri, örtük thread yöntemleri (Thread Pools, OpenMP, GCD), çoklu thread tasarım sorunları (`fork`/`exec`, sinyaller, iptal, TLS, LWP) ve Windows/Linux çekirdek yapıları ele alınmıştır. Uygulama bölümünde ise POSIX ortamında sıradan pipe, adlandırılmış pipe (FIFO), öncelikli mesaj kuyruğu (`mqueue`), paylaşımlı bellek (`shm_open`/`mmap`) ve Pthreads `mutex` ile üretici-tüketici problemi C kodları üzerinde çalıştırılarak doğrulanmıştır. Sonraki derslerde thread'lerin ve proseslerin ortak kaynaklara erişirken yaşadığı senkronizasyon ve kilitlenme (deadlock) konuları ile işlemci zamanlama (CPU scheduling) algoritmaları işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
