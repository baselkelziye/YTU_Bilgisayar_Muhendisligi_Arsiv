# Ders 11 Genişletilmiş Notu: Kilitlenmeler (Deadlocks): Sistem Modeli, Kaynak Tahsis Grafı, Önleme, Kaçınma (Banker Algoritması), Tespit ve Kurtarma ile POSIX Semafor ve Pthreads Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Üretici-Tüketici (Producer-Consumer) Senkronizasyon Uygulamaları
- 2. Kilitlenme (Deadlock) Kavramı, Sistem Modeli ve Dört Zorunlu Şart
- 3. Kaynak Tahsis Grafı (Resource-Allocation Graph — RAG) ve Döngü Analizi
- 4. Kilitlenmelerle Başa Çıkma Yöntemleri ve Deadlock Önleme (Prevention)
- 5. Deadlock Kaçınma (Avoidance): Güvenli Durum (Safe State) ve İddia Kenarı (Claim Edge)
- 6. Banker Algoritması (Banker's Algorithm) ve Adım Adım Sayısal Örnek
- 7. Deadlock Tespiti (Detection): Bekleme Grafı (Wait-for Graph) ve Çoklu Kaynak Tespit Algoritması
- 8. Deadlock'tan Kurtarma (Recovery): Proses Sonlandırma ve Kaynak Geri Alma
- 9. Laboratuvar Uygulaması: POSIX ve System V Semaforları ile Pthreads Senkronizasyon Örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Üretici-Tüketici (Producer-Consumer) Senkronizasyon Uygulamaları

Dersin ilk bölümünde hoca, önceki haftada teorik olarak işlenen proses ve iş parçacığı (thread) senkronizasyonu araçlarının (**semafor**, **mutex**, **koşul değişkeni** ve **monitör**) üretici-tüketici (producer-consumer / bounded-buffer) problemi üzerinde nasıl kodlandığını örnek dosyalar üzerinden gösterdi.

### 1.1 POSIX Semaforları ve İş Parçacıkları ile Üretici-Tüketici (`ProConsSem.c`)

İlk örnekte, aynı proses içindeki iki iş parçacığının (biri `producer`, diğeri `consumer`) 10 elemanlı ortak bir tamponu (`buffer[SIZE]`) paylaştığı senaryo ele alındı. İş parçacıkları aynı adres alanını paylaştığı için ayrıca bir prosesler arası haberleşme (IPC) mekanizmasına gerek duyulmaz; ancak tampon dolduğunda üreticinin beklemesi, tampon boşaldığında tüketicinin beklemesi ve biri tampona yazarken diğerinin aynı anda okuma/çıkarma yapamaması (kritik kesim / *critical section* koruması) gerekir.

Ekranda gösterilen `ProConsSem.c` kodunun üst kısmı şöyledir (ekrandan, 00:08:30):

```c
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10 // Tampon boyutu
int buffer[SIZE]; // Paylasilan tampon
int in = 0;  // Ureticinin ekleme pozisyonu
int out = 0; // Tuketicinin alma pozisyonu

// Semaforlar
sem_t empty; // Tampondaki bos yer sayisini tutar
sem_t full;  // Tampondaki dolu yer sayisini tutar
sem_t mutex; // Tampona erisim icin ikili semafor

// Uretici fonksiyonu
void* producer(void* arg) {
    while (1) {
        int item = rand() % 100; // Rastgele bir veri uret

        sem_wait(&empty); // Bos yer var mi kontrol et
        sem_wait(&mutex); // Tampona erisim kilidini al
        buffer[in] = item;
        in = (in + 1) % SIZE;
        sem_post(&mutex); // Tampon kilidini birak
        sem_post(&full);  // Dolu yer sayisini bir artir
    }
}
```

Burada üç adet POSIX semaforu (`sem_t`) kullanılmaktadır:
- `mutex`: Tampona karşılıklı dışlamalı (mutual exclusion) erişim sağlayan ikili semafor (binary semaphore; başlangıç değeri `1`).
- `empty` ve `full`: Tampondaki boş ve dolu göz sayısını izleyen sayma semaforları (counting semaphores; başlangıç değerleri `sem_init` içinde sırasıyla `SIZE` yani `10` ve `0` olarak atanır).

Hoca, teorik ders kitabında Felemenkçe kökenli $P(S)$ (*proberen*) ve $V(S)$ (*verhogen*) veya `wait()` ve `signal()` olarak adlandırılan semafor işlemlerinin C'deki POSIX kütüphanesinde **`sem_wait()`** ve **`sem_post()`** isimleriyle yer aldığını vurguladı.

Üretici ve tüketici iş parçacıklarının içerisine `sleep(1)` (veya milisaniye düzeyinde bekleme) eklendiğinde, beklemeye giren iş parçacığından diğerine zoraki bağlam değişimi (context switch) gerçekleşir ve ekranda "41 ekledi $\to$ 41 tüketti $\to$ 67 ekledi $\to$ 67 tüketti" şeklinde bire bir sıralı bir akış görülür. Ancak `sleep` çağrıları kaldırılıp döngü `for (i = 0; i < 100; i++)` biçiminde çalıştırıldığında, işletim sistemi kendisine bağlam değişimi yapana kadar üreticinin art arda birkaç sayı (örneğin önce 67, hemen ardından 34) ekleyebildiği, yani gerçek çalışma zamanında üretim ve tüketimlerin her zaman bire bir sırayla gitmek zorunda olmadığı gözlemlenir. Ana programda (`main`) iş parçacıkları `pthread_create` ile başlatılır, ana programın erken sonlanmaması için `pthread_join` ile beklenir ve program biterken `malloc` sonrası `free` yapılmasına benzer biçimde semaforlar `sem_destroy` ile temizlenir.

### 1.2 Koşul Değişkenleri ile Üretici-Tüketici (`ProConsCond.c`)

İkinci örnekte aynı problem semafor kullanmadan, doğrudan bir `mutex` kilidi ve iki adet **koşul değişkeni (condition variable — `full` ve `empty`)** ile çözülmüştür (ekrandan, 00:14:00):

```c
        pthread_mutex_lock(&mutex); // Mutex kilidi al

        // Dizi doluysa bekle
        while ((in + 1) % SIZE == out) {
            pthread_cond_wait(&full, &mutex);
        }

        // Uretilen sayiyi diziye ekle
        buffer[in] = item;
        printf("Uretici: %d ekledi\n", item);
        in = (in + 1) % SIZE; // Ekleme pozisyonunu guncelle

        // Tuketiciyi uyandir
        pthread_cond_signal(&empty);

        pthread_mutex_unlock(&mutex); // Mutex kilidini serbest birak
        //sleep(1); // Biraz bekle
```

Bu yapıda üretici önce `pthread_mutex_lock(&mutex)` ile kilidi alır. Tampon doluysa (`(in + 1) % SIZE == out`) `pthread_cond_wait(&full, &mutex)` çağrısıyla iş parçacığı `waiting` durumuna geçerek bekler. Boş yer varsa sayıyı diziye yazar, `waiting` durumunda bekleyen tüketiciyi uyandırmak için `pthread_cond_signal(&empty)` sinyalini gönderir ve `pthread_mutex_unlock(&mutex)` ile kilidi bırakır. Tüketici tarafında da simetrik olarak boş tampon kontrolü `empty` koşul değişkeni üzerinde yapılır.

### 1.3 Java, Python ve C Dilinde Monitör Yaklaşımı

C dilinde doğrudan yerleşik bir `monitor` yapısı bulunmazken, Java'da **`synchronized`** anahtar kelimesiyle metotların veya kod bloklarının (`synchronized (list) { ... }`) doğrudan bir monitör gibi çalıştırılabildiği; ortak kaynak üzerinde bir `synchronized` fonksiyon çalışırken aynı kaynağa başka bir `synchronized` bloğun erişmesinin engellendiği gösterildi. Python'da da `Condition` nesneleriyle aynı senaryonun iş parçacıkları üzerinde kurulabildiği belirtildi. C dilinde monitör benzetimi yapmak istendiğinde ise iki koşul değişkeni (`full`, `empty`), bir `mutex` kilidi ve tampon dizisini tek bir `struct` (yapı) içinde toplayarak tüm üretici ve tüketici işlemlerinin bu monitör yapısı üzerinden yürütülebildiği açıklandı.

### 1.4 Paylaşımlı Bellek (Shared Memory) Üzerinden Ayrı Proseslerle Üretici-Tüketici

Üretici ve tüketici aynı proseste çalışan iki iş parçacığı değil de **iki ayrı proses** olduğunda, hem tamponun (`buffer`) hem de senkronizasyonu sağlayan semaforların prosesler arasında paylaşılması gerekir. Hoca bunun iki farklı tasarımını gösterdi:
1. Tek bir kaynak kod içinde `init`, `producer` ve `consumer` fonksiyonlarının bulunduğu, komut satırı argümanına göre farklı kabuklardan (shell) ayrı prosesler olarak çalıştırılan yapı.
2. İstemci-sunucu (client-server) mimarisine benzer biçimde, `producer`, `consumer` ve ortadaki yönetici `test` (driver) programlarının ayrı dosyalarda yer aldığı yapı. Burada yönetici program ortak bir anahtar (`key`) ile paylaşımlı belleği (`shared memory`) açar, boş/dolu semaforlarını ilklendirir ve iş bittiğinde kaynakları temizler; üretici ve tüketici prosesler ise aynı `key` üzerinden paylaşımlı bellekteki semaforları (`sem_wait`/`sem_post`) ve tamponu kullanarak güvenli biçimde veri alışverişi yapar.

---

## 2. Kilitlenme (Deadlock) Kavramı, Sistem Modeli ve Dört Zorunlu Şart

### 2.1 Kilitlenme (Deadlock) Nedir ve Sorumluluk Kimdedir?

İşletim sistemlerinde kaynakları verimli kullanmak için çoklu prosesler oluşturulur, prosesler arası haberleşme (IPC) yapılır ve yarış durumlarını (race condition) önlemek için senkronizasyon araçları kullanılır. Ancak kaynakları koruyup senkronize ederken yapılan tasarım veya programlama hataları, proseslerin birbirini sonsuza kadar beklediği **kilitlenme (deadlock)** durumuna yol açabilir.

Hoca, dersin başında deadlock konusunun genel çerçevesini şöyle özetledi: Deadlock'u önlemek, deadlock'tan kaçınmak veya deadlock'u tespit etmek için literatürde çeşitli veri yapıları ve algoritmalar önerilmiştir; ancak bu algoritmaların zaman karmaşıklığı çok yüksektir. İşletim sistemi her kaynak talebinde sürekli güvenlik kontrolü yapan katı bir bekçi gibi davranırsa sistemin kaynak kullanımı (utilization) ve etkileşimi (interactivity) düşer, kullanıcı programlarında takılmalar yaşanır. Bu nedenle güncel işletim sistemleri şu yaklaşımı benimser: Çekirdek (kernel) kendi iç kodunda deadlock oluşmaması için gerekli garantiyi sağlar (örneğin mavi ekran hatalarının bir kısmı çekirdek içi deadlock'lardan kaynaklanır ve güncellemelerle düzeltilir); kullanıcı seviyesindeki uygulamalarda (web, mobil, veritabanı vb.) ise semaforları, kilitleri ve paylaşımlı kaynakları kurallara uygun kullanmak uygulama programcısının sorumluluğundadır.

### 2.2 Sistem Modeli (System Model)

Bir kod parçasını, servisi veya sistemi modellerken sistemde sonlu sayıda kaynak tipi bulunduğu kabul edilir:
- **Kaynak tipleri:** $R_1, R_2, \dots, R_m$ (örneğin işlemci döngüleri / CPU cycles, bellek alanları / heap-stack, G/Ç aygıtları, yazıcılar, dosyalar, semaforlar).
- **Kaynak örnekleri (instances):** Her $R_i$ kaynak tipinin $W_i$ adet özdeş örneği vardır (örneğin 5 adet işlemci çekirdeği, 8 adet bellek bloğu, 3 adet yazıcı).
- **Kaynak kullanım döngüsü:** Bir proses bir kaynağı kullanırken sırasıyla üç adımı izler:
  1. **`request` (Talep etme):** Proses kaynağı işletim sisteminden talep eder (örneğin yığın bölgesi yetersiz kaldığında `malloc` ile heap bölgesinden bellek istemek veya bir mutex/semafor kilidi talep etmek). Talep hemen karşılanamıyorsa proses bekler.
  2. **`use` (Kullanma):** Proses tahsis edilen kaynak üzerinde işlemini yürütür.
  3. **`release` (Serbest bırakma):** Proses işi bittiğinde kaynağı serbest bırakır (`free`, `delete` veya `unlock`).

Hoca burada öğrencilerin sık yaptığı bir hataya değindi: C'de `malloc` ile bellek alıp program sonunda `free` yapmamak (Java ve Python'da çöp toplayıcı / *garbage collector* belirli aralıklarla temizlik yapsa da büyük veri işlerken bazen `System.gc()` gibi çağrılarla elle tetiklemek gerekebilir), kullanılmayan kaynağın meşgul görünmesine ve o kaynağa ihtiyaç duyan diğer proseslerin zincirleme olarak beklemesine neden olur. Tıpkı bir sınıfta dersini geç bitiren bir hocanın sonraki dersi geciktirmesi, onun da bir sonrakini geciktirmesi ve bu gecikmenin dairesel bir döngüye dönüşmesi gibi sistemde kilitlenme zeminini hazırlar.

### 2.3 Deadlock Karakterizasyonu: Dört Zorunlu Şart

Bir sistemde kilitlenme (deadlock) oluşabilmesi için aşağıdaki **dört koşulun dördünün de aynı anda (`VE` / `AND` şartıyla)** gerçekleşmesi zorunludur. Bu dört koşuldan herhangi biri sağlanmazsa (`false` yapılırsa) deadlock meydana gelmez:

1. **Karşılıklı Dışlama (Mutual Exclusion):** En az bir kaynak paylaşılamaz (nonsharable) modda tutulmalıdır; yani belirli bir zaman diliminde o kaynak üzerinde yalnızca tek bir proses işlem gerçekleştirebilir. Başka bir proses o kaynağı talep ederse kaynak serbest bırakılana kadar bekletilir.

> **Ders sonrası not:** Hoca derste bu koşulu açıklarken *"Bir kaynak üzerinde, belirli bir zaman diliminde en fazla bir proses, sadece bir proses işlem gerçekleştirebilir. Bu şartı sağlıyorsak sıkıntı yok. Ama mutual exclusion'ı ihlal edecek bir durum varsa o zaman deadlock ihtimali var, başladı"* (00:32:02) ve semafor örneğinde *"Mutual exclusion, yani belli bir kritik bölgeye bile girememiş"* (00:37:47) ifadelerini kullanmıştır. Büyük olasılıkla ders kitabındaki (Silberschatz, Bölüm 7.2.1) tanıma göre doğrusu şöyledir: **Karşılıklı dışlama (mutual exclusion)**, deadlock'u engelleyen bir durum değil, tam tersine deadlock oluşabilmesi için var olması gereken birinci zorunlu koşuldur (kaynağın aynı anda birden fazla proses tarafından paylaşılamaması kilitlenmeye yol açar). Eğer kaynaklar eşzamanlı paylaşıma açıksa (yani mutual exclusion yoksa), prosesler birbirini beklemeyeceği için deadlock oluşamaz.

2. **Tut ve Bekle (Hold and Wait):** Halihazırda en az bir kaynağı elinde tutmakta olan bir proses, o sırada başka prosesler tarafından tutulmakta olan ek kaynakları talep edip bekliyor olmalıdır (örneğin belleği elinde tutarken başka bir prosesin kullandığı yazıcıyı beklemek).
3. **Zorla Geri Almama (No Preemption):** Bir prosese tahsis edilmiş olan kaynak, o prosesin elinden zorla geri alınamaz (`cannot be preempted`); kaynak ancak proses görevini tamamladıktan sonra kendi isteğiyle (`voluntarily`) serbest bırakılabilir. İşlemci (CPU) zamanlamasında Round Robin algoritmasıyla işlemci bir prosesten zorla alınabilirken, yazıcı veya dosya gibi kaynakları bir prosesin elinden işin ortasında almak çıktının (printout) hatalı üretilmesine neden olacağından bu kaynaklarda zorla geri alma yapılamaz.
4. **Dairesel Bekleme (Circular Wait):** Bekleyen proseslerden oluşan $\{P_0, P_1, \dots, P_n\}$ kümesinde $P_0$ prosesi $P_1$'in tuttuğu kaynağı, $P_1$ prosesi $P_2$'nin tuttuğu kaynağı, $\dots$, $P_{n-1}$ prosesi $P_n$'in tuttuğu kaynağı ve $P_n$ prosesi de $P_0$'ın tuttuğu kaynağı bekliyor olmalıdır.

> **Hocanın vurgusu:** Sınavlarda öğrenciler geçen hafta anlatılan Kritik Kesim (Critical Section) probleminin üç çözüm şartı (*Mutual Exclusion*, *Progress*, *Bounded Waiting*) ile Deadlock oluşumunun dört şartını (*Mutual Exclusion*, *Hold and Wait*, *No Preemption*, *Circular Wait*) birbirine çok sık karıştırmaktadır. Bu iki kavramın şartlarını kesinlikle birbirine karıştırmayın.

#### İki Semaforlu Klasik Deadlock Örneği

Hoca, dört şartın bir araya gelişini geçen derste de gösterilen iki semaforlu ($S_1 = 1, S_2 = 1$) örnek üzerinden somutlaştırdı:

```text
Başlangıç: S1 = 1, S2 = 1

P1 Prosesi:              P2 Prosesi:
-----------              -----------
wait(S1);   // (1. adım) wait(S2);   // (2. adım)
wait(S2);   // (bekler)  wait(S1);   // (bekler)
/* kritik kesim */       /* kritik kesim */
```

Eğer $P_1$ peş peşe her iki `wait` komutunu çalıştırabilseydi kritik kesime girip çıkardı; ancak 1. adımda $P_1$ `wait(S1)` çalıştırıp $S_1 = 0$ yaptıktan hemen sonra, 2. adımda $P_2$ devreye girip `wait(S2)` çalıştırarak $S_2 = 0$ yaparsa:
- $P_1$ elinde $S_1$'i tutarken $S_2$'yi bekler, $P_2$ ise elinde $S_2$'yi tutarken $S_1$'i bekler (*Hold and Wait* ve *Circular Wait*).
- Semaforlar başka bir prosesin elinden zorla alınamaz (*No Preemption*) ve paylaşılamaz (*Mutual Exclusion*).
- Sonuçta her iki proses de kritik kesime dahi giremeden sonsuza kadar olduğu yerde bekler ve **deadlock** gerçekleşir.

---

## 3. Kaynak Tahsis Grafı (Resource-Allocation Graph — RAG) ve Döngü Analizi

Deadlock problemini algoritmik olarak inceleyebilmek için sistem durumu yönlü bir graf (veya iki parçalı graf / *bipartite graph*) olan **Kaynak Tahsis Grafı (Resource-Allocation Graph)** ile modellenir (ekrandan, 00:40:00). Graf $G = (V, E)$ kümesinde düğümler ($V$) ve yönlü kenarlar ($E$) şöyle tanımlanır:

- **Düğümler ($V$):** İki tiptir (kod içinde bir bayrak / `flag` değişkeniyle ayırt edilebilir):
  1. $P = \{P_1, P_2, \dots, P_n\}$: Sistemdeki tüm aktif **prosesler** (görsel olarak **daire** ile çizilir).
  2. $R = \{R_1, R_2, \dots, R_m\}$: Sistemdeki tüm **kaynak tipleri** (görsel olarak **dikdörtgen** ile çizilir; bir kaynak tipinin birden fazla örneği varsa dikdörtgenin içine örnek sayısı kadar nokta veya küçük kare konur).
- **Yönlü Kenarlar ($E$):**
  1. **Talep Kenarı (Request Edge — $P_i \to R_j$):** Okun yönü prosesten kaynağa doğrudur; $P_i$ prosesinin $R_j$ kaynak tipinden bir örnek talep ettiğini (`request` / `demand`) ve şu anda bu kaynağı beklediğini gösterir. (Ok dikdörtgenin dış çerçevesine işaret eder).
  2. **Atama Kenarı (Assignment Edge — $R_j \to P_i$):** Okun yönü kaynağın içindeki belirli bir örnek noktasından prosese doğrudur; $R_j$ kaynağının bir örneğinin $P_i$ prosesine tahsis edilmiş (`assigned` / `allocated` / `granted` / `given` / `supplied`) ve $P_i$ tarafından tutulmakta olduğunu gösterir.

```text
Talep Kenarı (Request Edge):        Atama Kenarı (Assignment Edge):
  ( Pi ) -------> [ :: Rj ]           ( Pi ) <------- [ .:: Rj ]
  (Pi, Rj'den bir örnek istiyor)      (Rj'nin bir örneği Pi'ye atanmış)
```

> **Hocanın vurgusu:** Sınavda bir kaynak tahsis grafı verilip "Yukarıdaki graftan aşağıdaki ifadelerden hangileri çıkarılır?" diye sorulduğunda, talep etmeyi ifade eden **`request` / `demand`** kelimeleri ile kaynağın prosese atanmış olmasını ifade eden **`assigned` / `allocated` / `granted` / `given` / `supplied`** kelimelerinin anlamlarını ve ok yönlerini ($P \to R$ talep, $R \to P$ atama) doğru eşleştirmek gerekir.

### 3.1 Üç Temel Kaynak Tahsis Grafı Senaryosu

Slaytlarda üç farklı graf durumu karşılaştırılmıştır:

1. **Döngü İçermeyen Graf (Örnek 1):** Sistemde $P_1, P_2, P_3$ prosesleri ile $R_1$ (1 örnek), $R_2$ (2 örnek), $R_3$ (1 örnek), $R_4$ (3 örnek) kaynakları vardır.
   - Atamalar: $R_1 \to P_2$, $R_2 \to P_1$, $R_2 \to P_2$, $R_3 \to P_3$ ($R_4$ tamamen boştur).
   - Talepler: $P_1 \to R_1$, $P_2 \to R_3$.
   - Bu grafta yönlü oklar takip edildiğinde ($P_1 \to R_1 \to P_2 \to R_3 \to P_3$) hiçbir kapalı döngü (cycle) oluşmaz. $P_3$ işini bitirip $R_3$'ü serbest bıraktığında (`free`/`release`), $P_2$ $R_3$'ü alıp tamamlanır ve ardından $P_1$ de $R_1$'i alarak tamamlanır.
2. **Döngü İçeren ve Deadlock Olan Graf (Örnek 2):** Bir önceki grafa ek olarak $P_3 \to R_2$ talep kenarı eklendiğinde:
   - Grafta iki döngü oluşur: $P_1 \to R_1 \to P_2 \to R_3 \to P_3 \to R_2 \to P_1$ ve $P_2 \to R_3 \to P_3 \to R_2 \to P_2$.
   - $P_3$, $R_2$ kaynağından bir örnek beklemektedir; ancak $R_2$'nin iki örneği de $P_1$ ve $P_2$ tarafından tutulmaktadır ve $P_1$ ile $P_2$ de birbirini/diğer kaynakları beklemektedir. Hiçbir proses ilerleyemediği için sistemde **kesin deadlock vardır**.
3. **Döngü İçeren Ancak Deadlock Olmayan Graf (Örnek 3, ekrandan, 00:46:30):**

```text
                    ( P2 )
                      ^
                     /
              [  R1 (2 örnek) ]
               ^             \
              /               v
          ( P1 )            ( P3 )
              ^               /
               \             v
              [  R2 (2 örnek) ]
                     \
                      v
                    ( P4 )
```

Bu grafta $P_1 \to R_1 \to P_3 \to R_2 \to P_1$ şeklinde açık bir **döngü (cycle)** mevcuttur ve bir döngü tespit algoritması (cycle detection) bu grafta `true` döndürür. Ancak **deadlock yoktur**: Çünkü $R_1$'in ikinci örneğini tutan $P_2$ ile $R_2$'nin ikinci örneğini tutan $P_4$ başka hiçbir kaynak talep etmemektedir. $P_2$ veya $P_4$ işini bitirip elindeki kaynağı serbest bıraktığında (`release`), $P_1$ veya $P_3$ beklediği kaynağı alır ve döngü kırılır.

### 3.2 Kaynak Tahsis Grafından Çıkarılan Temel Kurallar

- Grafta **döngü (cycle) yoksa** $\implies$ sistemde kesinlikle **deadlock yoktur**.
- Grafta **döngü (cycle) varsa**:
  - Her kaynak tipinden **yalnızca 1 örnek (single instance)** bulunuyorsa $\implies$ döngü olması **kesin deadlock** demektir (gerekli ve yeterli koşuldur).
  - Kaynak tiplerinden **birden fazla örnek (multiple instances)** bulunuyorsa $\implies$ deadlock **olabilir (olasılık vardır)**, ancak kesin değildir.

> **Hocanın vurgusu:** Hoca, yakın zamanda yapılan bir araştırma görevlisi sınavında bu konudan soru sorduğunu ve adayların grafta döngü görür görmez "döngü var, öyleyse kesin deadlock vardır" hatasına düştüğünü belirtti. Çok örnekli kaynak tahsis grafında döngü bulunması %100 deadlock demek değildir; yalnız deadlock olasılığını gösterir.

**Soru:** Graftaki döngünün kesin deadlock oluşturması için tüm düğümlerden geçen bir Hamilton döngüsü olması mı gerekir?
**Cevap:** Hoca, bütün düğümlerden veya kenarlardan geçmesinin şart olmadığını, alt bir kümede oluşan döngünün de (kaynaklar başka proseslerce bırakılamıyorsa) deadlock için yeterli olduğunu açıkladı.

> **Ders sonrası not:** Hoca bu soru-cevap sırasında Hamilton ve Euler döngülerini karşılaştırırken *"Şimdi Hamilton olması için bütün yollardan geçmen gerek. Euler cycle dediğin o, senin bütün nodlardan geçeceğin dediğin şey"* (00:48:48) demiştir. Büyük olasılıkla çizge kuramında (graph theory) bu iki kavramın tanımı tam tersidir: Graftaki her **kenardan (yoldan)** tam bir kez geçen kapalı tura **Euler döngüsü (Eulerian cycle)**, her **düğümden (node/vertex)** tam bir kez geçen kapalı döngüye ise **Hamilton döngüsü (Hamiltonian cycle)** denir.

---

## 4. Kilitlenmelerle Başa Çıkma Yöntemleri ve Deadlock Önleme (Prevention)

İşletim sistemlerinde deadlock problemiyle başa çıkmak için genel olarak üç ana yaklaşım (dört yöntem) vardır:

1. **Sistemin hiçbir zaman deadlock durumuna girmemesini sağlamak:**
   - **Deadlock Prevention (Önleme):** Dört zorunlu koşuldan en az birini katı kurallarla ortadan kaldırır.
   - **Deadlock Avoidance (Kaçınma):** Önlemeye göre daha esnektir; kaynak taleplerini dinamik olarak izleyip sistemin güvensiz duruma düşmesini engeller.
2. **Sistemin deadlock durumuna girmesine izin verip sonradan kurtarmak (Detection and Recovery):** Deadlock tespit algoritmasıyla kilitlenmeyi yakalar ve kurtarma mekanizmasını çalıştırır.
3. **Problemi tamamen göz ardı etmek (Ignorance):** Sistemde hiç deadlock olmayacakmış gibi davranır; UNIX, Linux ve Windows dahil günümüzdeki genel amaçlı işletim sistemlerinin çoğunda bu yaklaşım kullanılır.

### 4.1 Deadlock Prevention (Kilitlenmeyi Önleme)

Kaynak taleplerinin yapılma biçimine kısıtlamalar getirerek dört gerekli şarttan en az birinin gerçekleşmesini engeller:

- **1. Karşılıklı Dışlamanın (Mutual Exclusion) Önlenmesi:** Salt okunur (read-only) dosyalar gibi paylaşılabilir kaynaklar için karşılıklı dışlama gerekmez; birden fazla proses aynı anda okuyabilir. Ancak yazıcı veya yazılabilir bellek alanı gibi doğası gereği paylaşılamaz (nonsharable) kaynaklarda karşılıklı dışlama kaldırılamaz; dolayısıyla her zaman uygulanabilir değildir.
- **2. Tut ve Bekle (Hold and Wait) Durumunun Önlenmesi:** Bir proses bir kaynak talep ettiğinde elinde başka hiçbir kaynak tutmadığından emin olunur. İki protokol uygulanabilir:
  - Proses çalışmaya başlamadan önce ihtiyaç duyacağı tüm kaynakları tek seferde talep edip alır; ya da
  - Proses yalnızca elinde hiçbir kaynak yokken yeni kaynak talep edebilir (yeni bir kaynak istemeden önce elindekileri bırakmak zorundadır).
  - **Dezavantajı:** Her iki durumda da kaynak kullanımı (utilization) çok düşüktür ve popüler kaynakları bekleyen proseslerde **açlık (starvation)** meydana gelebilir.
- **3. Zorla Geri Almama (No Preemption) Durumunun Önlenmesi:** Bazı kaynakları elinde tutan bir proses, hemen tahsis edilemeyecek yeni bir kaynak talep ettiğinde, halihazırda elinde tuttuğu tüm kaynaklar zorla geri alınır (`preempted` / serbest bırakılır). Geri alınan bu kaynaklar, prosesin beklediği kaynaklar listesine eklenir; proses ancak hem eski kaynaklarını hem de talep ettiği yeni kaynağı yeniden alabildiğinde kaldığı yerden (`restart`) devam ettirilir.
  - **Dezavantajı:** Geri alınan kaynakların listesini tutmak ve prosesleri durdurup yeniden başlatmak yüksek iş yükü doğurur; ayrıca yazıcı gibi durum bilgisi kolayca kaydedilemeyen kaynaklara uygulanamaz.
- **4. Dairesel Beklemenin (Circular Wait) Önlenmesi:** Sistemdeki tüm kaynak tiplerine bire bir tam sıralama fonksiyonu ($F: R \to \mathbb{N}$) atanır ve her prosesin kaynakları yalnızca **artan sıra numarasıyla (increasing order of enumeration)** talep etmesi zorunlu kılınır.
  - Slaytta örnek olarak iki hesap (`from` ve `to`) arasında para aktaran iki iş parçacığı (`transaction 1`: $A$'dan $B$'ye \$25, `transaction 2`: $B$'den $A$'ya \$50) gösterilmiştir. Kilitler (`first_mutex`, `second_mutex`) sıra gözetmeden alınırsa deadlock oluşabilirken, kilitlere sıra numarası verilip her işlemin kilitleri aynı sırada alması sağlandığında dairesel bekleme kırılır. Ancak dinamik sistemlerde bu sıralamayı korumak ($O(n \log n)$ veya $O(n^2)$ sıralama/denetim yükü) ek maliyet getirir.

---

## 5. Deadlock Kaçınma (Avoidance): Güvenli Durum (Safe State) ve İddia Kenarı (Claim Edge)

**Deadlock Avoidance (Kaçınma)** yönteminde sistem, önleme (prevention) kadar katı kısıtlamalar koymaz; bunun yerine her prosesin çalışma süresi boyunca her kaynak tipinden talep edebileceği **maksimum kaynak sayısını** önceden (*a priori* bilgi olarak) bildirmesini ister. Deadlock kaçınma algoritması, kaynak tahsis durumunu dinamik olarak izler ve dairesel bekleme oluşma tehlikesi belirdiğinde müdahale eder.

### 5.1 Güvenli Durum (Safe State) ve Güvensiz Durum (Unsafe State)

Bir proses mevcut (available) bir kaynağı talep ettiğinde sistem şu soruya yanıt arar: *"Bu kaynağı hemen tahsis edersem (immediate allocation) sistem güvenli durumda (safe state) kalır mı, yoksa güvensiz duruma (unsafe state) mı geçer?"*

- **Güvenli Durum (Safe State):** Sistemdeki prosesler için öyle bir $\langle P_1, P_2, \dots, P_n \rangle$ güvenli yürütme sırası (safe sequence) varsa ki; listedeki her $P_i$ prosesinin gelecekte talep edebileceği kaynaklar, şu anda boşta olan kaynaklar (`Available`) ile listede kendisinden önce gelen tüm $P_j$ ($j < i$) proseslerinin elinde tuttuğu kaynakların toplamıyla karşılanabiliyorsa, sistem **güvenli durumdadır**.
  - $P_i$'nin kaynak ihtiyacı hemen mevcut değilse, $P_i$ kendisinden önceki tüm $P_j$ prosesleri bitene kadar bekler; onlar bitip kaynaklarını bıraktığında $P_i$ kaynaklarını alır, işini tamamlar ve kaynaklarını $P_{i+1}$ için serbest bırakır.
- **Güvensiz Durum (Unsafe State) ve Deadlock İlişkisi:**

```text
+---------------------------------------+
|             unsafe (güvensiz)         |
|   +------------------+                |
|   |     deadlock     |                |
|   +------------------+                |
+---------------------------------------+
|              safe (güvenli)           |
+---------------------------------------+
```

- Sistem **safe state** içindeyse $\implies$ kesinlikle **deadlock oluşmaz**.
- Sistem **unsafe state** içine girerse $\implies$ **deadlock oluşma ihtimali vardır** (her unsafe durum kesin deadlock değildir, ancak prosesler maksimum taleplerini kullanmaya kalkarsa sistem kilitlenebilir).
- **Avoidance (Kaçınma) ilkesi:** Sistemin hiçbir zaman *unsafe* duruma geçmesine izin vermez.

### 5.2 Tek Örnekli Kaynaklar İçin Kaynak Tahsis Grafı Algoritması (Claim Edge)

Her kaynak tipinden yalnızca **tek bir örnek** varsa, kaçınma işlemi kaynak tahsis grafına üçüncü bir kenar türü eklenerek yapılır:
- **İddia Kenarı (Claim Edge — $P_i \dashrightarrow R_j$):** Kesikli çizgiyle (dashed line) gösterilir; $P_i$ prosesinin ileride $R_j$ kaynağını talep *edebileceğini* belirtir.
- **Kenar dönüşüm yaşam döngüsü:**
  1. Başlangıçta olası talepler **iddia kenarı ($P_i \dashrightarrow R_j$)** olarak grafta yer alır.
  2. $P_i$ kaynağı gerçekten talep ettiğinde iddia kenarı **talep kenarına ($P_i \to R_j$)** dönüşür.
  3. Kaynak prosese tahsis edildiğinde talep kenarı yön değiştirerek **atama kenarına ($R_j \to P_i$)** dönüşür.
  4. Proses işi bitip kaynağı serbest bıraktığında (`release`), atama kenarı tekrar başlangıçtaki **iddia kenarına ($P_i \dashrightarrow R_j$)** dönüşür.

**Algoritma Kuralı:** $P_i$ prosesi $R_j$ kaynağını talep ettiğinde, $P_i \to R_j$ talep kenarının $R_j \to P_i$ atama kenarına dönüştürülmesi yalnızca (kesikli iddia kenarları da dahil edildiğinde) **grafta herhangi bir döngü (cycle) oluşturmuyorsa** onaylanır.

```text
Güvenli Durum:                     Güvensiz (Unsafe) Durum:
      [ R1 ]                             [ R1 ]
      /    ^                             /    ^
     v      \                           v      \
  ( P1 )    ( P2 )                   ( P1 )    ( P2 )
     :      :                           :      /
     v      v                           v     /
      [ R2 ]                             [ R2 ]
(P1 - - > R2 ve P2 - - > R2)       (R2 ---> P2 ataması yapılırsa döngü oluşur!)
```

Slayttaki örnekte $R_1$ kaynağı $P_1$'e atanmıştır ($R_1 \to P_1$), $P_2$ ise $R_1$'i talep etmektedir ($P_2 \to R_1$). Hem $P_1$ hem $P_2$'nin $R_2$'ye kesikli iddia kenarı vardır ($P_1 \dashrightarrow R_2$, $P_2 \dashrightarrow R_2$). Bu sırada $P_2$ prosesi $R_2$'yi talep ederse ve $R_2 \to P_2$ ataması yapılırsa, $P_1 \dashrightarrow R_2 \to P_2 \to R_1 \to P_1$ şeklinde bir döngü oluşur! Bu durum **unsafe state**'tir; çünkü hemen ardından $P_1$ de $R_2$'yi talep ederse kesin deadlock meydana gelir. Dolayısıyla kaçınma algoritması $R_2$'yi $P_2$'ye tahsis etmez (veya $P_1$ önce $R_1$'i bırakana kadar bekletir).

---

## 6. Banker Algoritması (Banker's Algorithm) ve Adım Adım Sayısal Örnek

Kaynak tiplerinin **birden fazla örneği (multiple instances)** olduğunda, graf üç boyutlu karmaşık bir yapıya dönüşeceği için döngü tespiti kullanılamaz; bunun yerine Dijkstra tarafından önerilen **Banker Algoritması (Banker's Algorithm)** kullanılır.

Hoca bu algoritmanın adını bankacılık sistemindeki karşılama oranına (sermaye yeterlilik rasyosuna) benzetti: Bir bankanın kasasında fiziksel olarak 10 birim para varken, kredi verip mevduat toplayarak kaydi (sistemde yazılı) para miktarını 100 birime çıkardığını düşünelim (%10 karşılama oranı). Müşterilerin tamamı aynı anda paralarını çekmek isterse banka talepleri karşılayamaz ve batar (kilitlenir). Banker algoritması da eldeki kaynakları proseslere "kullandıktan sonra iade etmek üzere" öyle bir sırayla tahsis eder ki, hiçbir zaman tüm taleplerin kilitlendiği bir darboğaz yaşanmasın.

### 6.1 Banker Algoritmasının Veri Yapıları

Sistemde $n$ adet proses ve $m$ adet kaynak tipi olsun:
- **`Available[m]` ($m$ elemanlı vektör):** $\text{Available}[j] = k$ ise $R_j$ kaynak tipinden şu anda boşta (kullanılabilir) $k$ adet örnek vardır.
- **`Max[n][m]` ($n \times m$ boyutlu matris):** $\text{Max}[i, j] = k$ ise $P_i$ prosesi çalışma süresince $R_j$ kaynak tipinden en fazla $k$ adet örnek talep edebilir.
- **`Allocation[n][m]` ($n \times m$ boyutlu matris):** $\text{Allocation}[i, j] = k$ ise $P_i$ prosesine halihazırda $R_j$ kaynak tipinden $k$ adet örnek tahsis edilmiştir.
- **`Need[n][m]` ($n \times m$ boyutlu matris):** $\text{Need}[i, j] = k$ ise $P_i$ prosesinin görevini tamamlamak için $R_j$ kaynak tipinden daha $k$ adet örneğe ihtiyacı olabilir. Her zaman şu formülle türetilir:
  $$\text{Need}[i, j] = \text{Max}[i, j] - \text{Allocation}[i, j]$$

### 6.2 Güvenlik Algoritması (Safety Algorithm)

Sistemin güvenli bir durumda olup olmadığını bulan algoritma şu 4 adımdan oluşur (ekrandan, 01:26:30):

1. Uzunlukları sırasıyla $m$ ve $n$ olan `Work` ve `Finish` vektörlerini tanımla ve ilklendir:
   $$\text{Work} = \text{Available}$$
   $$\text{Finish}[i] = \text{false} \quad (i = 0, 1, \dots, n-1 \text{ için})$$
2. Aşağıdaki iki koşulu birden sağlayan bir $i$ indisi bul:
   - (a) $\text{Finish}[i] == \text{false}$
   - (b) $\text{Need}_i \le \text{Work}$
   Böyle bir $i$ bulunamazsa **Adım 4**'e git.
3. Seçilen $P_i$ prosesinin kaynakları alıp işini bitirdiğini ve elindeki kaynakları iade ettiğini varsay:
   $$\text{Work} = \text{Work} + \text{Allocation}_i$$
   $$\text{Finish}[i] = \text{true}$$
   Tekrar **Adım 2**'ye dön.
4. Eğer tüm $i$ değerleri için $\text{Finish}[i] == \text{true}$ ise sistem **güvenli durumdadır (safe state)**.

**Zaman Karmaşıklığı:** $m$ boyutlu vektör karşılaştırması her adımda $n$ proses üzerinden en fazla $n$ tur tekrarlandığından algoritmanın çalışma zamanı karmaşıklığı **$O(m \times n^2)$**'dir (hoca $m$ ve $n$ birbirine yakın kabul edildiğinde bunun yaklaşık $O(n^3)$ mertebesinde yüksek bir maliyet oluşturduğunu vurguladı).

### 6.3 Kaynak Talep Algoritması (Resource-Request Algorithm for Process $P_i$)

$P_i$ prosesi için $\text{Request}_i$ talep vektörü geldiğinde şu 3 adım işletilir:

1. Eğer $\text{Request}_i \le \text{Need}_i$ ise **Adım 2**'ye geç. Aksi takdirde proses bildirdiği maksimum talebi aştığı için hata ver (`error condition`).
2. Eğer $\text{Request}_i \le \text{Available}$ ise **Adım 3**'e geç. Aksi takdirde kaynaklar şu an mevcut olmadığı için $P_i$ beklemek zorundadır.
3. Kaynaklar $P_i$'ye tahsis edilmiş gibi sistem tablolarını **geçici olarak (pretend to allocate)** güncelle:
   $$\text{Available} = \text{Available} - \text{Request}_i$$
   $$\text{Allocation}_i = \text{Allocation}_i + \text{Request}_i$$
   $$\text{Need}_i = \text{Need}_i - \text{Request}_i$$
   Bu yeni durum üzerinde **Güvenlik Algoritmasını (Safety Algorithm)** çalıştır:
   - Durum **safe (güvenli)** çıkarsa $\implies$ kaynaklar $P_i$'ye kalıcı olarak tahsis edilir.
   - Durum **unsafe (güvensiz)** çıkarsa $\implies$ $P_i$ bekletilir ve tablolar eski değerlerine geri döndürülür (`restore old resource-allocation state`).

### 6.4 Banker Algoritması Adım Adım Sayısal Örneği

Slaytta verilen sistemde 5 proses ($P_0, P_1, P_2, P_3, P_4$) ve 3 kaynak tipi vardır: **$A$ (10 örnek)**, **$B$ (5 örnek)**, **$C$ (7 örnek)** (ekrandan, 01:30:00).

$T_0$ anındaki sistem görüntüsü (`Allocation`, `Max`, `Available`) ve buradan $\text{Need} = \text{Max} - \text{Allocation}$ ile hesaplanan `Need` matrisi aşağıdaki tabloda birleştirilmiştir:

| Proses | `Allocation` ($A\ B\ C$) | `Max` ($A\ B\ C$) | `Need = Max - Allocation` ($A\ B\ C$) | Başlangıç `Available` ($A\ B\ C$) |
| :--- | :---: | :---: | :---: | :---: |
| **$P_0$** | `0 1 0` | `7 5 3` | **`7 4 3`** | **`3 3 2`** |
| **$P_1$** | `2 0 0` | `3 2 2` | **`1 2 2`** | |
| **$P_2$** | `3 0 2` | `9 0 2` | **`6 0 0`** | |
| **$P_3$** | `2 1 1` | `2 2 2` | **`0 1 1`** | |
| **$P_4$** | `0 0 2` | `4 3 3` | **`4 3 1`** | |
| **Toplam** | **`7 2 5`** | | | $\text{Toplam}(10,5,7) - \text{Alloc}(7,2,5) = (3,3,2)$ |

#### Güvenli Sıranın (Safe Sequence) Bulunması:

Başlangıçta $\text{Work} = \text{Available} = (3, 3, 2)$ ve $\text{Finish} = [\text{false}, \text{false}, \text{false}, \text{false}, \text{false}]$:

1. **$P_0$ kontrolü:** $\text{Need}_0 = (7, 4, 3) \le \text{Work}(3, 3, 2)$ mi? **Hayır** ($7 > 3, 4 > 3, 3 > 2$). $P_0$ bekler.
2. **$P_1$ kontrolü:** $\text{Need}_1 = (1, 2, 2) \le \text{Work}(3, 3, 2)$ mi? **Evet.**
   - (Ara adım: $P_1$'e ihtiyacı olan $(1, 2, 2)$ verildiğinde boşta $(3,3,2) - (1,2,2) = (2, 1, 0)$ kalır ve $P_1$'in elindeki kaynak $(2,0,0) + (1,2,2) = (3, 2, 2)$ olur).
   - $P_1$ işini bitirip tüm kaynaklarını iade ettiğinde:
     $$\text{Work} = \text{Work} + \text{Allocation}_1 = (3, 3, 2) + (2, 0, 0) = (5, 3, 2), \quad \text{Finish}[1] = \text{true}$$
3. **$P_2$ kontrolü:** $\text{Need}_2 = (6, 0, 0) \le \text{Work}(5, 3, 2)$ mi? **Hayır** ($6 > 5$). $P_2$ bekler.
4. **$P_3$ kontrolü:** $\text{Need}_3 = (0, 1, 1) \le \text{Work}(5, 3, 2)$ mi? **Evet.**
   - $P_3$ çalışıp tamamlandığında elindeki $\text{Allocation}_3 = (2, 1, 1)$ kaynağını bırakır:
     $$\text{Work} = (5, 3, 2) + (2, 1, 1) = (7, 4, 3), \quad \text{Finish}[3] = \text{true}$$
5. **$P_4$ kontrolü:** $\text{Need}_4 = (4, 3, 1) \le \text{Work}(7, 4, 3)$ mi? **Evet.**
   - $P_4$ çalışıp tamamlandığında elindeki $\text{Allocation}_4 = (0, 0, 2)$ kaynağını bırakır:
     $$\text{Work} = (7, 4, 3) + (0, 0, 2) = (7, 4, 5), \quad \text{Finish}[4] = \text{true}$$
6. **Başa dönüp kalan $P_0$ ve $P_2$ kontrolü:**
   - $\text{Need}_0 = (7, 4, 3) \le \text{Work}(7, 4, 5)$ olduğundan **$P_0$** çalıştırılır:
     $$\text{Work} = (7, 4, 5) + (0, 1, 0) = (7, 5, 5), \quad \text{Finish}[0] = \text{true}$$
   - Son olarak $\text{Need}_2 = (6, 0, 0) \le \text{Work}(7, 5, 5)$ olduğundan **$P_2$** çalıştırılır:
     $$\text{Work} = (7, 5, 5) + (3, 0, 2) = (10, 5, 7), \quad \text{Finish}[2] = \text{true}$$

Tüm prosesler tamamlanabildiği ve başlangıçtaki toplam kaynak sayısına $(10, 5, 7)$ ulaşıldığı için sistem **güvenli durumdadır (safe state)**; güvenli yürütme sırası **`<P1, P3, P4, P0, P2>`** (veya $P_4$'ten sonra önce $P_2$ sonra $P_0$ seçilirse `<P1, P3, P4, P2, P0>`) şeklindedir.

#### Ek Kaynak Talebi Senaryoları (`P1 Request (1, 0, 2)`, ekrandan, 01:38:30):

Şimdi $T_0$ anında $P_1$ prosesinin $\text{Request}_1 = (1, 0, 2)$ talebinde bulunduğunu düşünelim:
1. $\text{Request}_1(1, 0, 2) \le \text{Need}_1(1, 2, 2)$ $\implies$ **Doğru**.
2. $\text{Request}_1(1, 0, 2) \le \text{Available}(3, 3, 2)$ $\implies$ **Doğru**.
3. Geçici atama yapılır:
   - $\text{Available} = (3, 3, 2) - (1, 0, 2) = (2, 3, 0)$
   - $\text{Allocation}_1 = (2, 0, 0) + (1, 0, 2) = (3, 0, 2)$
   - $\text{Need}_1 = (1, 2, 2) - (1, 0, 2) = (0, 2, 0)$
4. Güvenlik algoritması bu yeni tablo üzerinde çalıştırıldığında yine **`<P1, P3, P4, P0, P2>`** sırasının güvenli olduğu görülür ($\text{Need}_1 = (0, 2, 0) \le \text{Work}(2, 3, 0) \implies \text{Work} = (2, 3, 0) + (3, 0, 2) = (5, 3, 2)$ ve devamı aynıdır). Dolayısıyla $P_1$'in $(1, 0, 2)$ talebi **hemen onaylanır (granted)**.

> **Ders sonrası not:** Hoca bu slaytı (`Example: P1 Request (1,0,2)`, ekrandan, 01:38:30) anlatırken $(3, 3, 2)$'den $(1, 0, 2)$ çıkarıldığında kalan `Available` değerini sözlü olarak *"2, 1, 0"* diye okumuş, ardından bir öğrencinin sorusu üzerine *"2 tane A var, 3 tane A istiyor"* demiştir (01:38:45, 01:40:53). Büyük olasılıkla hoca $B$ bileşenini bir önceki genel çözümde $\text{Need}_1 = (1, 2, 2)$ çıkarıldığında kalan $(2, 1, 0)$ değeriyle karıştırmıştır; slaytta açıkça yazılı olduğu üzere $(3, 3, 2) - (1, 0, 2)$ işleminin sonucu **`Available = (2, 3, 0)`**'dır.

Slayttaki iki ek soru ve sınıftaki soru-cevap:
- **$P_4$ prosesinin `(3, 3, 0)` talebi onaylanabilir mi?**
  - **Cevap:** Hayır. Mevcut durumda $\text{Available} = (2, 3, 0)$ (veya başlangıçta bile bakılsa $P_1$ sonrası $(2, 3, 0)$) olduğu için elde yalnızca $2$ adet $A$ kaynağı vardır; $(3, 3, 0) \not\le (2, 3, 0)$ olduğundan kaynak yetersizdir ve $P_4$'e bu kaynak verilemez.
  - **Soru:** Önce $P_1$'i çalıştırıp kaynaklarını geri aldıktan sonra `Available` $(5, 3, 2)$ olunca $P_4$'e $(3, 3, 0)$ veremez miyiz?
  - **Cevap:** Hoca, anlık talep kontrolünde (`Resource-Request Algorithm`) o andaki `Available` vektörüne bakıldığını; $P_4$ o anda $(3, 3, 0)$ istediğinde elde bu kaynak yoksa $P_4$'ün bekletileceğini açıkladı. Bunu günlük hayattan bir benzetmeyle anlattı: Bir kişi sizden borç veya alacak istediğinde elinizde para yoksa *"Falancadan alacağım var, o borcunu ödeyince ben de sana vereceğim, sen şimdilik bekle"* dersiniz; yani o anda ödeme yapamazsınız, $P_4$ beklemek zorundadır.
- **$P_0$ prosesinin `(0, 2, 0)` talebi onaylanabilir mi?**
  - **Cevap:** Hoca derste mevcut kaynak sayısı açısından $(0, 2, 0) \le \text{Available}(2, 3, 0)$ olduğu için eldeki kaynakların buna yettiğini ("elimde de bu kadar varsa bunu verebiliyorum") söyledi (01:39:41).

> **Ders sonrası not:** Hoca $P_0$'ın $(0, 2, 0)$ talebi için yalnızca mevcut `Available` miktarının yeterli olduğuna (`(0,2,0) <= (2,3,0)`) değinip geçmiştir. Büyük olasılıkla Silberschatz kitabındaki (Bölüm 7.5.3) tam çözüme göre, $(0, 2, 0)$ kaynağı $P_0$'a geçici olarak verildiğinde $\text{Available} = (2, 3, 0) - (0, 2, 0) = (2, 1, 0)$ kalır; bu durumda kalan ihtiyaçlar ($\text{Need}_0 = (7,2,3)$, $\text{Need}_1 = (0,2,0)$, $\text{Need}_2 = (6,0,0)$, $\text{Need}_3 = (0,1,1)$, $\text{Need}_4 = (4,3,1)$) incelendiğinde hiçbir prosesin kalan ihtiyacı $\text{Available}(2, 1, 0)$ ile karşılanamaz (çünkü $P_1$'e 2 adet $B$, $P_3$'e ise 1 adet $C$ lazımdır). Dolayısıyla sistem **unsafe (güvensiz)** duruma düşeceği için kaynak mevcut olsa bile $P_0$'ın $(0, 2, 0)$ talebi onaylanmaz ve $P_0$ bekletilir.

---

## 7. Deadlock Tespiti (Detection): Bekleme Grafı (Wait-for Graph) ve Çoklu Kaynak Tespit Algoritması

Sistemde deadlock önleme (prevention) veya kaçınma (avoidance) mekanizmaları kullanılmıyorsa, sistemin deadlock durumuna girmesine izin verilir ve şu iki bileşen çalıştırılır:
1. Sistemin durumunu inceleyip bir deadlock oluşup oluşmadığını belirleyen **Deadlock Tespit Algoritması (Detection Algorithm)**.
2. Tespit edilen deadlock durumunu ortadan kaldıran **Kurtarma Algoritması (Recovery Scheme)**.

### 7.1 Tek Örnekli Kaynaklar İçin Bekleme Grafı (Wait-for Graph)

Tüm kaynak tiplerinin yalnızca **tek bir örneği (single instance)** varsa, kaynak tahsis grafındaki (RAG) kaynak düğümleri ($R_j$) aradan çıkarılarak yalnızca proseslerden oluşan **Bekleme Grafı (Wait-for Graph)** elde edilir:
- Kaynak tahsis grafında $P_i \to R_q$ (talep) ve $R_q \to P_j$ (atama) kenarları varsa, bu durum aslında $P_i$ prosesinin $P_j$ prosesinin $R_q$ kaynağını serbest bırakmasını beklediği anlamına gelir.
- Bekleme grafında bu ilişki doğrudan **$P_i \to P_j$** kenarıyla gösterilir ($P_i$, $P_j$'yi bekliyor).

```text
Kaynak Tahsis Grafı (RAG):            Bekleme Grafı (Wait-for Graph):

          [ R1 ] <-- ( P1 )                         ( P1 )
            |          |                              |
            v          v                              v
          ( P2 ) --> [ R3 ]    ======>              ( P2 )
          /   \        |                            / |  \
         v     v       v                           v  |   v
      [ R4 ]  [ R5 ] ( P5 )                     (P3)  |  (P5)
        |       ^                                 |   |
        v       |                                 v   v
      ( P3 ) ->( P4 )                            ( P4 )
```

- **Kesinlik Kuralı:** Bekleme grafında (Wait-for Graph) bir **döngü (cycle) varsa $\iff$ sistemde %100 kesin olarak deadlock vardır** (örneğin yukarıdaki grafta $P_1 \to P_2 \to P_3 \to P_4 \to P_1$ ve $P_2 \to P_4 \to P_2$ döngüleri deadlock olduğunu kesin olarak gösterir).
- **Karmaşıklık:** Sistem periyodik olarak bu graf üzerinde döngü tespit algoritması çalıştırır. $n$ düğümlü bir grafta döngü tespiti yaklaşık **$O(n^2)$** işlem gerektirir.

### 7.2 Çok Örnekli Kaynaklar İçin Deadlock Tespit Algoritması

Kaynakların birden fazla örneği olduğunda Wait-for Graph yeterli olmaz; çünkü bir kaynağın bazı örnekleri tutulurken başka bir örneği boşta olabilir. Bu durumda yeniden matris tabanlı bir algoritma kullanılır:
- **`Available[m]`:** Boştaki kaynak örneklerinin sayısı.
- **`Allocation[n][m]`:** Her prosese halihazırda atanmış kaynaklar.
- **`Request[n][m]`:** Her prosesin **şu anda (anlık olarak)** talep ettiği kaynaklar (Banker algoritmasındaki gelecekteki maksimum `Need` yerine burada o anki gerçek `Request` matrisi kullanılır).

**Algoritma Adımları:**
1. $\text{Work} = \text{Available}$ olarak ilklendir. Her $i = 0, 1, \dots, n-1$ için: eğer $\text{Allocation}_i \neq 0$ ise $\text{Finish}[i] = \text{false}$, aksi halde (elinde hiç kaynak yoksa) $\text{Finish}[i] = \text{true}$ yap.
2. Hem $\text{Finish}[i] == \text{false}$ hem de $\text{Request}_i \le \text{Work}$ koşulunu sağlayan bir $i$ indisi bul. Bulunamazsa **Adım 4**'e git.
3. Seçilen $P_i$'nin talebinin karşılandığını ve elindeki kaynakları bırakacağını varsay (iyimser yaklaşım):
   $$\text{Work} = \text{Work} + \text{Allocation}_i$$
   $$\text{Finish}[i] = \text{true}$$
   Tekrar **Adım 2**'ye git.
4. Eğer herhangi bir $i$ için **$\text{Finish}[i] == \text{false}$** kalmışsa, sistem **deadlock durumundadır** ve $\text{Finish}[i] == \text{false}$ olan bütün $P_i$ prosesleri kilitlenmiştir. (Karmaşıklık: **$O(m \times n^2)$**).

#### Sayısal Tespit Örneği (ekrandan, 01:49:00):

Sistemde 5 proses ($P_0 \dots P_4$) ve 3 kaynak tipi vardır: **$A$ (7 örnek)**, **$B$ (2 örnek)**, **$C$ (6 örnek)**. $T_0$ anındaki tablo:

| Proses | `Allocation` ($A\ B\ C$) | `Request` ($A\ B\ C$) | `Available` ($A\ B\ C$) |
| :--- | :---: | :---: | :---: |
| **$P_0$** | `0 1 0` | `0 0 0` | **`0 0 0`** |
| **$P_1$** | `2 0 0` | `2 0 2` | |
| **$P_2$** | `3 0 3` | `0 0 0` | |
| **$P_3$** | `2 1 1` | `1 0 0` | |
| **$P_4$** | `0 0 2` | `0 0 2` | |
| **Toplam** | **`7 2 6`** | | $\text{Toplam}(7,2,6) - \text{Alloc}(7,2,6) = (0,0,0)$ |

**Durum 1 ($\text{Request}_2 = (0, 0, 0)$ iken):**
- Başlangıçta $\text{Work} = (0, 0, 0)$'dır. Hiçbir ek talebi olmayan ($\text{Request} = (0, 0, 0)$) $P_0$ ve $P_2$ prosesleri mevcut kaynaklarıyla işlerini tamamlayıp ellerindeki kaynakları serbest bırakabilir:
  1. **$P_0$** tamamlanır $\implies \text{Work} = (0, 0, 0) + (0, 1, 0) = (0, 1, 0)$.
  2. **$P_2$** tamamlanır $\implies \text{Work} = (0, 1, 0) + (3, 0, 3) = (3, 1, 3)$.
  3. Artık eldeki $\text{Work}(3, 1, 3)$ ile **$P_3$** ($\text{Request}_3 = (1, 0, 0) \le (3, 1, 3)$) tamamlanır $\implies \text{Work} = (3, 1, 3) + (2, 1, 1) = (5, 2, 4)$.
  4. Ardından **$P_1$** ($\text{Request}_1 = (2, 0, 2) \le (5, 2, 4)$) tamamlanır $\implies \text{Work} = (5, 2, 4) + (2, 0, 0) = (7, 2, 4)$.
  5. Son olarak **$P_4$** ($\text{Request}_4 = (0, 0, 2) \le (7, 2, 4)$) tamamlanır $\implies \text{Work} = (7, 2, 4) + (0, 0, 2) = (7, 2, 6)$.
- `<P0, P2, P3, P1, P4>` sırasıyla tüm prosesler için $\text{Finish}[i] = \text{true}$ olur; **deadlock yoktur**. (Hoca burada önemli bir noktayı vurguladı: Bir prosesin kaynağı serbest bırakması demek ille de prosesin tamamen sonlanması demek değildir; yazıcı veya dosya ile işi biten proses kaynağı `release` edip kendi hesaplamasına devam edebilir).

**Durum 2 ($P_2$ prosesi ek olarak 1 adet $C$ kaynağı talep ederse: $\text{Request}_2 = (0, 0, 1)$):**
- Başlangıçta yalnızca **$P_0$** ($\text{Request}_0 = (0, 0, 0) \le (0, 0, 0)$) tamamlanabilir ve $\text{Work} = (0, 1, 0)$ olur.
- Eldeki $\text{Work} = (0, 1, 0)$ kaynağı ne $P_1$'in $(2, 0, 2)$, ne $P_2$'nin $(0, 0, 1)$, ne $P_3$'ün $(1, 0, 0)$, ne de $P_4$'ün $(0, 0, 2)$ talebini karşılamaya yeter!
- Sonuçta $P_0$ dışındaki **$\{P_1, P_2, P_3, P_4\}$ proseslerinden oluşan sistem deadlock durumuna girmiştir**.

### 7.3 Tespit Algoritmasının Kullanım Maliyeti

$O(m \times n^2)$ karmaşıklıklı bu algoritmanın **ne zaman ve ne sıklıkla** çağrılacağı üç etkene bağlıdır:
1. Deadlock'un ne sıklıkla oluşma ihtimali olduğu,
2. Deadlock oluştuğunda kaç prosesin bundan etkileneceği (kaç prosesin geri sarılması / `rollback` gerekeceği).
Her kaynak talebinde algoritmayı çalıştırmak aşırı işlemci yükü yaratırken, rastgele veya uzun aralıklarla çalıştırmak kaynak tahsis grafında birden fazla döngü birikmesine ve deadlock'a hangi prosesin sebep olduğunun anlaşılamamasına yol açar.

---

## 8. Deadlock'tan Kurtarma (Recovery): Proses Sonlandırma ve Kaynak Geri Alma

Deadlock tespit edildiğinde sistemin kilitlenmeden çıkması için iki temel kurtarma (recovery) yöntemi vardır:

### 8.1 Proses Sonlandırma (Process Termination)

Kilitlenmeyi kırmak için prosesler sonlandırılır (`abort`) ve tuttukları kaynaklar geri alınır (ekrandan, 02:00:00):
1. **Kilitlenmiş tüm prosesleri sonlandırmak (`Abort all deadlocked processes`):** Deadlock'u kesin olarak çözer ancak maliyeti çok yüksektir; uzun süredir çalışan proseslerin tüm kısmi hesaplamaları çöpe gider.
2. **Deadlock döngüsü kırılana kadar her seferinde tek bir prosesi sonlandırmak (`Abort one process at a time`):** Her proses sonlandırıldığında tespit algoritması yeniden çalıştırılarak kilitlenmenin çözülüp çözülmediği kontrol edilir; bu da ek algoritma çalıştırma maliyeti doğurur.

Hoca bu noktada Windows Görev Yöneticisi (Task Manager) üzerinden çalışan bir prosesin bellek dökümünün (**Create memory dump file / core dump**, yaklaşık 50 MB boyutunda `.DMP` dosyası) nasıl alındığını canlı olarak gösterdi: Bir proses beklenmedik şekilde sonlandırılırken (`abort` / `crash`), geliştiricilerin hatanın hangi komutta veya veride oluştuğunu sonradan özel analiz yazılımlarıyla inceleyebilmesi için prosesin o anki bellek görüntüsü (kod, veri, program sayacı vb.) bir `core dump` dosyasına kaydedilir.

#### Kurban Seçim Ölçütleri (Victim Selection Criteria):

Prosesleri tek tek sonlandırırken hangi prosesin "kurban" (*victim*) seçileceğine şu 6 ölçüte bakılarak karar verilir (ekrandan, 02:00:00):
1. Prosesin önceliği (*Priority of the process*),
2. Prosesin şu ana kadar ne kadar süre çalıştığı ve tamamlanmasına ne kadar süre kaldığı (*How long process has computed, and how much longer to completion* — bitmesine çok az kalmış bir prosesi öldürmek yerine yeni başlamış olanı sonlandırmak daha az maliyetlidir),
3. Prosesin şu ana kadar kullandığı kaynak miktarı (*Resources the process has used*),
4. Prosesin tamamlanmak için ihtiyaç duyduğu ek kaynak miktarı (*Resources process needs to complete*),
5. Kilitlenmeyi çözmek için kaç prosesin sonlandırılması gerekeceği (*How many processes will need to be terminated*),
6. Prosesin etkileşimli (*interactive*) mi yoksa toplu iş (*batch*) prosesi mi olduğu (*Is process interactive or batch?*).

### 8.2 Kaynak Geri Alma (Resource Preemption)

Prosesleri tamamen öldürmek yerine, deadlock döngüsü kırılana kadar bazı proseslerin elinden kaynakları zorla geri alınıp diğer proseslere verilir. Burada üç kritik sorun ele alınmalıdır:
1. **Kurban Seçimi (`Selecting a victim`):** Maliyeti en aza indirecek (`minimize cost`) kaynak ve proses seçilir.
2. **Geri Sarma (`Rollback`):** Elinden kaynağı alınan proses normal çalışmasına devam edemeyeceği için güvenli bir duruma geri sarılmalı (`rollback to some safe state`) ve o noktadan yeniden başlatılmalıdır (örneğin MS Word gibi uygulamaların kilitlendiğinde otomatik kurtarma / yedekleme noktasına dönmesi).
3. **Açlık (`Starvation`):** Maliyet ölçütüne göre her seferinde aynı düşük öncelikli proses kurban seçilirse o proses işini hiçbir zaman bitiremez. Bunu önlemek için bir prosesin kaç kez geri sarıldığı (`number of rollbacks`) da maliyet hesabına dahil edilir.

Hoca teorik kısmı tamamlarken gerçek hayattan bir yazılım mühendisliği örneği verdi: Otobüs veya tren bileti satış sistemlerinde koltuk seçimi yapılırken düşük seviyeli karmaşık kilitler nedeniyle tüm veritabanını deadlock'a sokmak yerine, seçilen koltuk ödeme tamamlanana kadar durum makinesi (state machine) mantığıyla 10–20 dakikalığına "rezerve/bloke" durumuna alınır; süre dolduğunda ödeme yapılmamışsa koltuk otomatik olarak tekrar "boş (free)" durumuna döndürülür. Ancak savunma sanayii ve gömülü sistemler gibi gerçek zamanlı kritik ortamlarda doğrudan işletim sistemi düzeyindeki senkronizasyon ve deadlock kurallarının titizlikle uygulanması şarttır.

---

## 9. Laboratuvar Uygulaması: POSIX ve System V Semaforları ile Pthreads Senkronizasyon Örnekleri

Dersin ikinci yarısında (02:16:35'ten itibaren) araştırma görevlisi tarafından Ubuntu sanal makinesi üzerinde POSIX semaforları, System V semaforları ve Pthreads (POSIX Threads) kütüphanesinin C uygulamaları adım adım çalıştırılarak gösterildi.

### 9.1 POSIX Semaforları: İsimli (`Named`) ve İsimsiz (`Unnamed`) Semaforlar

Semafor, birden fazla proses veya iş parçacığının ortak bir kaynağa yarış durumu (race condition), açlık (starvation) ve kilitlenme (deadlock) oluşturmadan erişmesini sağlayan, negatif olmayan bir tam sayı (`integer`) tutan senkronizasyon yapısıdır. POSIX semaforları ikiye ayrılır (ekrandan, 02:20:00):

| Özellik | İsimli Semaforlar (`Named Semaphores`) | İsimsiz Semaforlar (`Unnamed Semaphores`) |
| :--- | :--- | :--- |
| **Erişim Yöntemi** | `/somename` biçiminde null-sonlandırmalı bir isim dizgesiyle erişilir. | Bellek adresi (`sem_t *`) üzerinden erişilir. |
| **Prosesler Arası Paylaşım** | Farklı prosesler `sem_open()` fonksiyonuna **aynı ismi** vererek doğrudan erişebilir. | İş parçacıkları arasında global değişkenle; farklı prosesler arasında ise **paylaşımlı bellek (`shared memory`)** bölgesine yerleştirilerek kullanılır. |
| **Oluşturma / İlklendirme** | `sem_open()` | `sem_init()` |
| **Bekleme ve Sinyal** | `sem_wait()`, `sem_timedwait()`, `sem_trywait()`, `sem_post()` | `sem_wait()`, `sem_timedwait()`, `sem_trywait()`, `sem_post()` |
| **Kapatma ve Yok Etme** | `sem_close()` (bellek alanını bırakır, isim sistemde kalır) ve `sem_unlink()` (ismi sistemden tamamen siler) | `sem_destroy()` (hem belleği bırakır hem semaforu yok eder) |

#### Örnek 1: İsimli İkili Semafor ile İki Prosesin Senkronizasyonu (`Ex_3_semA.c` ve `Ex_3_semB.c`, ekrandan, 02:26:00)

Ayrı terminallerde çalıştırılan iki prosesten $A$ prosesi (`Ex_3_semA.c`) semaforu oluşturup kritik kesime girerken, $B$ prosesi (`Ex_3_semB.c`) aynı isimli semaforu açarak sırasını bekler:

```c
/* Ex_3_semA.c (Semaforu olusturan A prosesi) */
sem_t *bin_sem;
struct timeval t0, t1;

// Semaforu olustur ve ilklendir:
// SEM_NAME: isim, O_CREAT: olusturma bayragi,
// 0644: dosya izinleri (Owner: R/W, Group: R-only, Others: R-only),
// 1: baslangic degeri (1 = unlocked / kullanima hazir)
bin_sem = sem_open(SEM_NAME, O_CREAT, 0644, 1);
if (bin_sem == SEM_FAILED) {
    perror("unable to create semaphore");
    sem_unlink(SEM_NAME);
    exit(-1);
}

while (i < 10) {
    sem_wait(bin_sem); // Degeri 1 azalt (0 olur), kritik kesime gir
    gettimeofday(&t0, 0);
    printf("Process A enters the critical section at %ld \n",
           (t0.tv_sec * 1000 + t0.tv_usec / 1000) % 10000000);
    long sum = 0;
    for (long j = 0; j < 100000000; j++) {
        sum += j;
    }
    gettimeofday(&t1, 0);
    printf("Process A leaves the critical section at %ld \n",
           (t1.tv_sec * 1000 + t1.tv_usec / 1000) % 10000000);

    sem_post(bin_sem); // Degeri 1 artir (1 olur), bekleyen prosesi uyandir
    i++;
    sleep(2);
}

sem_close(bin_sem);    // Semafor nesnesini kapat
sem_unlink(SEM_NAME);  // Isimli semaforu sistemden sil
exit(0);
```

Diğer terminaldeki `Ex_3_semB.c` ise semafor zaten var olduğu için `bin_sem = sem_open(SEM_NAME, 0, 0644, 0);` çağrısıyla aynı semafora bağlanır ve döngü sonunda yalnızca `sem_close(bin_sem);` çağırır. Programlar çalıştırıldığında milisaniye cinsinden zaman damgalarında $B$ prosesinin tam $A$ prosesi kritik kesimden çıktığı (`leaves`) anda kritik kesime girdiği (`enters`) gözlemlenir.

### 9.2 System V Semaforları ve Paylaşımlı Bellek ile Üretici-Tüketici

İkinci uygulamada 10 elemanlı bir tampon üzerinde **System V** paylaşımlı bellek (`shmget` ile `IPC_CREAT | 0666` bayrakları kullanılarak `BUFFER_SIZE + 2` boyutunda oluşturulur) ve 2 elemanlı System V semafor grubu (`semget(key, 2, IPC_CREAT | 0666)`) kullanılmıştır:
- **0. Semafor (boş alan sayacı):** Başlangıç değeri `BUFFER_SIZE` (`10`) olarak atanır.
- **1. Semafor (dolu alan sayacı):** Başlangıç değeri `0` olarak atanır.
- Önce `./program init` (veya çoklu dosya versiyonunda `./test init`) çalıştırılarak paylaşımlı bellek ve semaforlar ilklendirilir; ardından ayrı terminallerde `producer` ve `consumer` çalıştırılır. Eğer `init` çalıştırılmadan veya `cleanup` ile paylaşımlı bellek ve semaforlar silindikten sonra `producer` çalıştırılırsa, bellek alanı ve semafor mevcut olmadığı için **Segmentation fault (core dumped)** hatası alınır (ekrandan, 02:50:00). Hoca burada paylaşımlı bellek kullanılmasının kodu kısa tutmak için tercih edildiğini; aynı senkronizasyonun borular (`pipe`, `FIFO`) veya internet/ağ üzerinden çalışan uygulamalarda (örneğin WhatsApp gibi mesajlaşma sistemlerinde) **soket (`socket`)** programlama ile de yapılabileceğini ekledi.

### 9.3 Pthreads ile Çoklu İş Parçacığı (Multithreading) Programlama

`fork()` ile yeni alt prosesler oluşturulduğunda global değişkenler, yerel değişkenler ve kod alanı kopyalandığı için bellekte fazla yer kaplar. Buna karşılık aynı proses içinde oluşturulan **iş parçacıkları (threads)**:
- Prosesin bellek alanını (kod, veri, heap), açık dosya ve soket tanımlayıcılarını (`file/socket descriptors`) ve sinyal (`signal`) bilgilerini **ortak paylaşır**;
- Her iş parçacığı kendi benzersiz kimliğine (**Thread ID**, `pthread_self()` ile öğrenilir), kendi yerel değişkenlerinin tutulduğu **yığın (`stack`)** alanına, **yazmaçlarına (`registers`)** ve **program sayacına (`program counter`)** sahiptir.

#### İş Parçacığı Oluşturma, Sonlandırma ve Argüman Aktarımı (`Ex_1` ve `Ex_2`)

- **`pthread_create(&thread_id, &attr, start_routine, arg)`:** Yeni bir iş parçacığı başlatır. `start_routine`, `void* (*start_routine)(void*)` imzasına sahip bir fonksiyondur ve yalnızca **tek bir `void*` argümanı** alabilir. İş parçacığına birden fazla veri (örneğin hem `thread_id`, hem `sum`, hem de `message` dizgesi) gönderilmek istendiğinde bu veriler bir **`struct`** içinde paketlenir ve `struct` dizisinin ilgili elemanının adresi `void*` olarak geçirilir.
- İş parçacığı, başlangıç fonksiyonu (`start_routine`) döndüğünde veya açıkça **`pthread_exit()`** çağrıldığında sonlanır.
- 5 farklı iş parçacığının farklı dillerde *"Hello World"* bastığı örnekte (`Ex_1_pthread1.out`, ekrandan, 02:50:00), senkronizasyon olmadığı için iş parçacıklarının işletim sistemi zamanlayıcısına bağlı olarak her çalıştırmada farklı sırada (`Thread 1: French` $\to$ `Thread 4: German` $\to$ `Thread 3: Klingon` $\to$ `Thread 0: English` $\to$ `Thread 2: Spanish`) ekrana çıktı verdiği görüldü. Aynı şekilde ortak bir karakter dizisi üzerinde uzunluk ölçme, boşluk sayma, büyük harfe (`uppercase`) ve küçük harfe (`lowercase`) çevirme geri çağırım (`callback`) fonksiyonlarını rastgele çalıştıran iş parçacıklarında da senkronizasyon olmadığında hangi harflerin büyük veya küçük kalacağının öngörülemediği (yarış durumu / *race condition*) gösterildi.

#### Birleştirilebilir (`Joinable`) ve Ayrık (`Detached`) İş Parçacıkları (`Ex_4`)

Her iş parçacığı ya **joinable** (varsayılan / default durum) ya da **detached** durumdadır:
- **Joinable Thread:** Ana iş parçacığı (`main thread`), `pthread_join()` çağrısıyla alt iş parçacığının bitmesini bekler ve döndürdüğü sonucu (`result` işaretçisini) alır.
- **Detached Thread:** Ana iş parçacığı alt iş parçacığından bir dönüş değeri beklemiyorsa iş parçacığı `detached` yapılır. Bu durumda `main` iş parçacığı iş parçacıklarını oluşturduktan sonra onları beklemeden kendi çalışmasını bitirip çıkabilir (`pthread_exit`); ayrık iş parçacıkları ise proses işletim sistemi tarafından tamamen sonlandırılana kadar kendi fonksiyonlarını çalıştırmaya ve çıktı üretmeye devam eder. `Detached` bir iş parçacığına sonradan `pthread_join` yapılamaz.

### 9.4 Pthreads Mutex Kilitleri ve Koşul Değişkenleri Uygulaması (`Ex_6` ve `Watcher` Örneği)

- **Mutex ile Semafor Arasındaki Sahiplik (Ownership) Farkı:** İkili semaforlarda sahiplik kavramı yoktur; bir proses semaforu kilitleyip (`wait`) başka bir proses açabilir (`post`). Mutex kilitlerinde ise **sahiplik (ownership)** vardır: Mutex kilidini yalnızca `pthread_mutex_lock` ile kilitleyen iş parçacığı `pthread_mutex_unlock` ile açabilir.
- **Mutex Örneği (`Ex_6`):** Ortak bir `counter` değişkenini artırarak `"Job X started"` ve `"Job X finished"` yazdıran iki iş parçacığı, mutex kullanılmadığında ilk iş parçacığı henüz bitmeden ikinci iş parçacığı `counter` değerini `2` yaptığı için ekrana iki kez `"Job 2 finished"` basmaktadır (`Job 1 finished` kaybolmaktadır). Fonksiyonun girişine `pthread_mutex_lock(&lock)` ve çıkışına `pthread_mutex_unlock(&lock)` eklendiğinde (`PTHREAD_MUTEX_INITIALIZER` ile ilklendirilerek), birinci iş parçacığı `"Job 1 started"` $\to$ `"Job 1 finished"` adımlarını tamamlayıp kilidi bırakmadan ikinci iş parçacığı kritik kesime giremez ve karışıklık tamamen giderilir.
- **Koşul Değişkeni (`Condition Variable`) ve `Watcher` İş Parçacığı Örneği:** Son uygulamada 3 iş parçacığı çalışmaktadır:
  - `Thread 1` ve `Thread 2`, ortak `count` değişkenini mutex kilidi altında birer birer artırır ve `count` değeri belirlenen sınıra (`COUNT_LIMIT = 12`) ulaştığında `pthread_cond_signal()` ile sinyal gönderir.
  - `Thread 3` (`watch_count` fonksiyonunu çalıştıran gözlemci / *watcher* iş parçacığı) ise döngüde meşgul bekleme (busy waiting / spinlock) yapmak yerine `pthread_cond_wait()` ile `waiting` durumunda uyur.
  - Sayacın `12` olmasıyla gönderilen sinyal alındığında `Thread 3` uyanır (bu sırada `Thread 2` araya girip sayacı `13` yapmıştır), `count` değerine `100` ekleyerek `113` yapar; ardından `Thread 1` ve `Thread 2` kalan artırmaları tamamlayıp `main` iş parçacığında `pthread_join` sonrasında nihai değer `120` olarak ekrana basılır ve `mutex`, `attr` ile `condition variable` yok edilerek (`destroy`) program sonlandırılır.

---

## Örnek Sorular

### Soru 1: Çok Örnekli Kaynak Tahsis Grafında Döngü ve Deadlock Analizi (ekrandan, 00:46:30)

**Soru:** Sistemde $P_1, P_2, P_3, P_4$ prosesleri ile ikişer örneği bulunan $R_1$ ve $R_2$ kaynak tipleri vardır. Kaynak tahsis grafındaki kenarlar şöyledir:
- Atama kenarları: $R_1 \to P_2$, $R_1 \to P_3$, $R_2 \to P_1$, $R_2 \to P_4$.
- Talep kenarları: $P_1 \to R_1$, $P_3 \to R_2$.
Bu grafta bir döngü (cycle) var mıdır? Sistemde deadlock oluşur mu? Nedenini açıklayınız.

**Çözüm (derste verildi):**
- Grafta $P_1 \to R_1 \to P_3 \to R_2 \to P_1$ şeklinde yönlü bir **döngü (cycle) vardır**.
- Ancak sistemde **deadlock yoktur**. Çünkü kaynak tiplerinin birden fazla (ikişer) örneği vardır ve $R_1$'in bir örneğini tutan $P_2$ ile $R_2$'nin bir örneğini tutan $P_4$ prosesleri hiçbir kaynak talep etmemektedir (bekleme durumunda değillerdir). $P_2$ işini bitirip elindeki $R_1$ kaynağını serbest bıraktığında (`release`), bu kaynak $P_1$'e tahsis edilir; $P_1$ tamamlanıp $R_2$'yi bıraktığında da $P_3$ kaynağını alarak tamamlanır.

### Soru 2: İddia Kenarlı (Claim Edge) Kaynak Tahsis Grafında Güvenli Durum Kontrolü (derste sözlü ve ekrandan, 01:06:33)

**Soru:** Tek örnekli $R_1$ ve $R_2$ kaynaklarının bulunduğu bir sistemde $R_1 \to P_1$ atama kenarı, $P_2 \to R_1$ talep kenarı ve $P_1 \dashrightarrow R_2$, $P_2 \dashrightarrow R_2$ iddia kenarları (claim edges) mevcuttur. Bu sırada $P_2$ prosesi $R_2$ kaynağını talep ederse, Deadlock Avoidance algoritması $R_2$'yi $P_2$'ye tahsis eder mi?

**Çözüm (derste verildi):**
- **Tahsis etmez.** Eğer $P_2$'nin talebi kabul edilip $P_2 \to R_2$ kenarı $R_2 \to P_2$ atama kenarına dönüştürülürse, grafta $P_1 \dashrightarrow R_2 \to P_2 \to R_1 \to P_1$ şeklinde bir döngü oluşur ve sistem **güvensiz duruma (unsafe state)** girer. Çünkü hemen ardından $P_1$ de $R_2$'yi talep ederse her iki proses birbirinin tuttuğu kaynağı bekleyeceğinden kesin deadlock oluşacaktır.

### Soru 3: Banker Algoritması Güvenli Sıra ve Ek Talep Analizi (ekrandan, 01:30:00, 01:38:30)

**Soru:** 5 proses ($P_0 \dots P_4$) ve 3 kaynak tipi ($A$: 10 örnek, $B$: 5 örnek, $C$: 7 örnek) bulunan bir sistemde $T_0$ anındaki `Allocation` ve `Max` matrisleri şöyledir:
- $P_0$: `Allocation = (0, 1, 0)`, `Max = (7, 5, 3)`
- $P_1$: `Allocation = (2, 0, 0)`, `Max = (3, 2, 2)`
- $P_2$: `Allocation = (3, 0, 2)`, `Max = (9, 0, 2)`
- $P_3$: `Allocation = (2, 1, 1)`, `Max = (2, 2, 2)`
- $P_4$: `Allocation = (0, 0, 2)`, `Max = (4, 3, 3)`

a) `Available` vektörünü ve `Need` matrisini bulunuz.
b) Sistemin güvenli durumda (safe state) olup olmadığını gösteriniz ve güvenli yürütme sırasını yazınız.
c) $P_1$ prosesinin $\text{Request}_1 = (1, 0, 2)$ talebi hemen karşılanabilir mi? Bu atama sonrasında $P_4$'ün $(3, 3, 0)$ talebi karşılanabilir mi?

**Çözüm (derste verildi):**
- **a)** Toplam atanmış kaynaklar $\sum \text{Allocation} = (7, 2, 5)$ olduğundan $\text{Available} = (10, 5, 7) - (7, 2, 5) = (3, 3, 2)$'dir. $\text{Need} = \text{Max} - \text{Allocation}$ hesabıyla:
  $\text{Need}_0 = (7, 4, 3)$, $\text{Need}_1 = (1, 2, 2)$, $\text{Need}_2 = (6, 0, 0)$, $\text{Need}_3 = (0, 1, 1)$, $\text{Need}_4 = (4, 3, 1)$.
- **b)** $\text{Work} = (3, 3, 2)$ ile başlandığında sırasıyla:
  1. $P_1$ ($\text{Need}_1 = (1,2,2) \le (3,3,2)$) $\implies \text{Work} = (5, 3, 2)$,
  2. $P_3$ ($\text{Need}_3 = (0,1,1) \le (5,3,2)$) $\implies \text{Work} = (7, 4, 3)$,
  3. $P_4$ ($\text{Need}_4 = (4,3,1) \le (7,4,3)$) $\implies \text{Work} = (7, 4, 5)$,
  4. $P_0$ ($\text{Need}_0 = (7,4,3) \le (7,4,5)$) $\implies \text{Work} = (7, 5, 5)$,
  5. $P_2$ ($\text{Need}_2 = (6,0,0) \le (7,5,5)$) $\implies \text{Work} = (10, 5, 7)$.
  Sistem **güvenli durumdadır**; güvenli sıra **`<P1, P3, P4, P0, P2>`**'dir.
- **c)** $P_1$'in $(1, 0, 2)$ talebi hem $\text{Need}_1(1, 2, 2)$'den hem de $\text{Available}(3, 3, 2)$'den küçük-eşittir. Geçici atama yapıldığında $\text{Available} = (2, 3, 0)$, $\text{Allocation}_1 = (3, 0, 2)$ ve $\text{Need}_1 = (0, 2, 0)$ olur; `<P1, P3, P4, P0, P2>` sırası yine güvenli kaldığı için **$P_1$'in talebi onaylanır**. Bu atamadan sonra $\text{Available} = (2, 3, 0)$ kaldığı için $P_4$'ün $(3, 3, 0)$ talebi $(3, 3, 0) \not\le (2, 3, 0)$ nedeniyle **karşılanamaz** ($P_4$ bekletilir).

### Soru 4: Çoklu Kaynak Deadlock Tespit Algoritması Analizi (ekrandan, 01:49:00)

**Soru:** $A(7), B(2), C(6)$ kaynaklı bir sistemde $\text{Available} = (0, 0, 0)$ iken `Allocation` ve `Request` matrisleri şöyledir:
- $P_0$: `Alloc = (0, 1, 0)`, `Request = (0, 0, 0)`
- $P_1$: `Alloc = (2, 0, 0)`, `Request = (2, 0, 2)`
- $P_2$: `Alloc = (3, 0, 3)`, `Request = (0, 0, 0)`
- $P_3$: `Alloc = (2, 1, 1)`, `Request = (1, 0, 0)`
- $P_4$: `Alloc = (0, 0, 2)`, `Request = (0, 0, 2)`

a) Bu durumda sistemde deadlock var mıdır?
b) Eğer $P_2$ prosesi ek olarak 1 adet $C$ kaynağı talep ederse ($\text{Request}_2 = (0, 0, 1)$) sistemin durumu ne olur?

**Çözüm (derste verildi):**
- **a)** Talebi $(0, 0, 0)$ olan $P_0$ ve $P_2$ tamamlanıp kaynaklarını bıraktığında $\text{Work} = (0, 1, 0) + (3, 0, 3) = (3, 1, 3)$ olur; ardından sırasıyla $P_3, P_1, P_4$ de taleplerini alıp tamamlanabildiği için (`<P0, P2, P3, P1, P4>`) tüm prosesler için $\text{Finish}[i] = \text{true}$ olur ve **deadlock yoktur**.
- **b)** $\text{Request}_2 = (0, 0, 1)$ olduğunda başlangıçta yalnızca $P_0$ tamamlanabilir ve $\text{Work} = (0, 1, 0)$ olur. Elde hiç $A$ ve $C$ kaynağı bulunmadığından kalan hiçbir prosesin talebi karşılanamaz; **$\{P_1, P_2, P_3, P_4\}$ prosesleri arasında deadlock oluşur**.

---

## Dersin Toparlaması

Bu derste ilk olarak üretici-tüketici (bounded-buffer) probleminin POSIX semaforları, koşul değişkenleri, monitörler ve paylaşımlı bellek üzerinde çalışan ayrı proseslerle gerçeklenmesi incelenmiş; ardından işletim sistemlerinde **kilitlenme (deadlock)** konusu baştan sona ele alınmıştır. Bir sistemde deadlock oluşabilmesi için **Karşılıklı Dışlama (Mutual Exclusion)**, **Tut ve Bekle (Hold and Wait)**, **Zorla Geri Almama (No Preemption)** ve **Dairesel Bekleme (Circular Wait)** şartlarının dördünün birden aynı anda sağlanması gerektiği; **Kaynak Tahsis Grafında (RAG)** döngü bulunmasının tek örnekli kaynaklarda kesin deadlock, çok örnekli kaynaklarda ise yalnızca deadlock olasılığı anlamına geldiği öğrenilmiştir. Deadlock ile başa çıkmak için kullanılan **Önleme (Prevention)**, **Kaçınma (Avoidance — Claim Edge ve $O(m \times n^2)$ karmaşıklıklı Banker Algoritması)**, **Tespit (Detection — Wait-for Graph ve matris tabanlı tespit algoritması)** ve **Kurtarma (Recovery — Proses Sonlandırma ve Kaynak Geri Alma)** yöntemleri sayısal örneklerle analiz edilmiş; yüksek algoritmik maliyet nedeniyle modern işletim sistemlerinin kullanıcı seviyesindeki deadlock'ları göz ardı ederek sorumluluğu uygulama geliştiricisine bıraktığı vurgulanmıştır. Dersin uygulama bölümünde ise isimli/isimsiz POSIX semaforları, System V semaforları ve Pthreads (`joinable`/`detached` iş parçacıkları, mutex sahipliği ve koşul değişkenleri) Ubuntu üzerinde canlı kod örnekleriyle pekiştirilmiştir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
