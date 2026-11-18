# Ders 7 Çalışma Özeti

## Genel Konular

- Çoklu programlama, çoklu işleme, çoklu görev ve çoklu iş parçacığı kavramları
  - **Tekli programlama (uniprogramming):** Bellekte tek bir program yer alır; program G/Ç (I/O) veya kesme (interrupt) nedeniyle beklemeye (`Wait`) geçtiğinde işlemci boşta kalır.
  - **Çoklu programlama (multiprogramming):** Ana bellekte birden fazla programın (`P1, P2, ..., Pn`) eşzamanlı olarak bulunmasıdır (ekrandan, 00:08:30). Bir proses G/Ç beklemeye geçtiğinde işlemci başka bir prosese tahsis edilir; amaç işlemci kullanım oranını (CPU utilization) maksimize etmek ve ana belleği verimli yönetmektir.
  - **Çoklu işleme (multiprocessing):** Sistemde donanımsal olarak iki veya daha fazla fiziksel işlemci ya da çekirdeğin bulunması ve proseslerin aynı anda gerçek paralel olarak yürütülmesidir.
  - **Çoklu görev (multitasking):** Tek kullanıcılı (single-user) veya çok kullanıcılı (multi-user) sistemlerde birden fazla görevin çok hızlı bağlam değiştirmelerle (context switch) zaman paylaşımlı olarak yürütülmesidir (sanal paralellik).
  - **Çoklu iş parçacığı (multithreading):** Tek bir prosesin kendi yürütme akışının (execution flow) eşzamanlı çalışabilecek birden fazla iş parçacığına (thread) bölünmesidir.
- İş parçacığı (thread) yapısı ve много-thread programlamanın faydaları
  - Tek iş parçacıklı (single-threaded) ve çok iş parçacıklı (multithreaded) proses karşılaştırması: Aynı prosese ait tüm thread'ler **kod (`code`)**, **veri (`data`)** ve **açık dosyalar (`files`)** bölümlerini paylaşır; ancak her thread'in kendine ait bir **kimliği (Thread ID)**, **program sayacı (PC)**, **yazmaç kümesi (`registers`)** ve **yığını (`stack`)** vardır (ekrandan, 00:31:50).
  - Dört temel fayda: **Cevap verebilirlik (responsiveness)**, **kaynak paylaşımı (resource sharing)**, **ekonomi (economy)** ve **ölçeklenebilirlik (scalability)**.
- Çok çekirdekli programlama, eşzamanlılık (concurrency), paralellik (parallelism) ve Amdahl Yasası
  - **Eşzamanlılık (concurrency):** Tek çekirdek üzerinde görevlerin zaman dilimleriyle nöbetleşe ilerlemesidir. **Paralellik (parallelism):** Çok çekirdekli sistemde birden fazla görevin aynı anda fiziksel olarak yürütülmesidir.
  - **Veri paralelliği (data parallelism):** Aynı verinin alt kümelere bölünerek farklı çekirdeklerde aynı işlemle (`X` fonksiyonu) işlenmesidir. **Görev paralelliği (task parallelism):** Farklı görevlerin (`X` ve `Y` fonksiyonları) farklı çekirdeklere dağıtılmasıdır.
  - **Amdahl Yasası (Amdahl's Law):** Seri çalışma oranı $S$ ve çekirdek sayısı $N$ olan bir uygulamanın hızlanma üst sınırı (ekrandan, 00:38:10):
    $$\text{speedup} \le \frac{1}{S + \frac{1 - S}{N}}$$
    $N \to \infty$ iken hızlanma $1 / S$ değerine yakınsar.
- Kullanıcı ve çekirdek thread'leri ile çoklu thread eşleştirme modelleri
  - **Kullanıcı thread'leri (user threads):** Kullanıcı alanında thread kütüphaneleriyle yönetilir. **Çekirdek thread'leri (kernel threads):** Doğrudan işletim sistemi çekirdeği tarafından desteklenir ve yönetilir.
  - Eşleştirme modelleri: **Çoğa-Bir (Many-to-One)**, **Bire-Bir (One-to-One)**, **Çoğa-Çok (Many-to-Many)** ve **İki Seviyeli Model (Two-Level Model)**.
- Thread kütüphaneleri ve örtük iş parçacığı kullanımı (implicit threading)
  - Temel kütüphaneler: **POSIX Pthreads** (`pthread_create`, `pthread_join`, `pthread_exit`), **Windows Threads** (`CreateThread`, `WaitForSingleObject`, `CloseHandle`) ve **Java Threads** (`Thread` sınıfı ve `Runnable` arayüzü).
  - **Örtük iş parçacığı (implicit threading):** Thread oluşturma ve yönetimini derleyiciye ve çalışma zamanı kütüphanelerine devretme yaklaşımları: **Thread havuzları (thread pools)**, **OpenMP** (`#pragma omp parallel`, `#pragma omp parallel for`) ve **Grand Central Dispatch (GCD)**.
- Çok iş parçacıklı sistemlerde temel tasarım sorunları ve işletim sistemi örnekleri
  - `fork()` ve `exec()` çağrılarının semantiği, sinyal işleme (signal handling), thread iptali (asenkron ve ertelenmiş / deferred cancellation), thread-yerel depolama (Thread-Local Storage - TLS) ve zamanlayıcı aktivasyonları (Lightweight Process - LWP).
  - **Windows** (`ETHREAD`, `KTHREAD`, `TEB`) ve **Linux** (`struct task_struct`, `clone()` sistem çağrısı ve paylaşım bayrakları) gerçeklemeleri (ekrandan, 01:40:00).
- Uygulama: POSIX IPC (Pipe, FIFO, Mesaj Kuyruğu, Paylaşımlı Bellek) ve Pthread Mutex örnekleri
  - IPC kalıcılık (persistence) türleri: proses kalıcı (process-persistent), çekirdek kalıcı (kernel-persistent) ve dosya sistemi kalıcı (filesystem-persistent).
  - Tek yönlü ve çift yönlü sıradan `pipe()`, adlandırılmış boru (`mkfifo`), öncelikli POSIX mesaj kuyruğu (`mq_open`, `mq_send`, `mq_receive`), POSIX paylaşımlı bellek (`shm_open`, `ftruncate`, `mmap`) ve Pthreads `pthread_mutex_t` ile üretici-tüketici (producer-consumer) gerçeklemesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Proses oluşturma (`fork`) ile thread oluşturma arasındaki maliyet ve paylaşım farkı
  - `fork()` ile yeni proses oluşturulduğunda ayrı bir adres uzayı ve PID tahsis edilir; proseslerin haberleşmesi için pipe, mesaj kuyruğu veya paylaşımlı bellek gibi ek mekanizmalar gerekir. Thread'ler ise aynı prosesin kod ve veri bölümünü (örneğin global değişkenleri) doğrudan paylaştığından hem oluşturulmaları hem de aralarındaki bağlam değişimi (context switch) çok daha hafiftir.
- Ortak değişken kullanan thread'lerde yürütme sırasının belirsizliği
  - Ortak bir $x = 1$ değişkeni üzerinde çalışan iki thread'in ($f$ ve $g$ fonksiyonları) işlemciye hangi sırayla gireceği zamanlayıcıya (scheduler) bağlıdır. Komutların atomik olduğu varsayılsa bile farklı serpiştirme (interleaving) sıralarına göre ekranda `2, 2, 4` veya `1, 2, 3` gibi farklı çıktılar görülebilir; hoca sınavlarda bu tür yürütme senaryosu ve mantık sorularının gelebileceğini vurguladı.
- Amdahl Yasası'nda seri kısmın darboğaz oluşturması
  - Bir işin %25'i seri olmak zorundaysa (örneğin 100 saniyelik işin 25 saniyesi), sisteme sonsuz sayıda çekirdek ($N \to \infty$) eklense bile toplam süre 25 saniyenin altına inemez; seri kısım toplam performans kazancını sınırlar.
- Çoğa-Bir (Many-to-One) ve Çoğa-Çok (Many-to-Many) modellerinin kısıtları
  - Çoğa-Bir modelinde kullanıcı thread'lerinden biri bloklayan bir çağrı yaptığında tek çekirdek thread'i de bloklandığından tüm proses durur ve çok çekirdekli sistemde gerçek paralellik elde edilemez. Çoğa-Çok modelinde ise bloklanma sorunu aşılır ancak bazı kullanıcı thread'lerine uzun süre çekirdek thread'i sırası gelmemesi (açlık / starvation) riski doğabilir; kritik thread'ler için İki Seviyeli (Two-Level) modelde bire-bir ayrıcalık tanınır.
- Ana programın `pthread_join` ile alt thread'leri beklemesi
  - `fork()` sonrasındaki `wait()` çağrısına benzer biçimde, ana thread oluşturduğu iş parçacıklarını `pthread_join()` ile beklemelidir; aksi takdirde `main` fonksiyonu `return 0` ile sonlandığında proses kapanır ve çalışmakta olan thread'ler de işletim sistemi tarafından yarıda kesilir.

## Kısa Tekrar Notları

- **Uniprogramming:** Bellekte tek program; G/Ç beklemesinde CPU boş kalır.
- **Multiprogramming:** Bellekte birden fazla program; G/Ç beklemesinde CPU başka prosese geçer.
- **Multiprocessing:** Birden fazla fiziksel CPU/çekirdek ile gerçek paralel yürütme.
- **Multitasking:** Zaman paylaşımı ve hızlı bağlam değiştirmeyle görevlerin eşzamanlı yürütülmesi.
- **Multithreading:** Bir proses içinde birden fazla yürütme akışı (thread).
- Thread'lerin paylaştıkları: `code`, `data`, `files`. Her thread'e özel olanlar: `Thread ID`, `PC`, `registers`, `stack`.
- Çoklu thread avantajları: Cevap verebilirlik, kaynak paylaşımı, ekonomi, ölçeklenebilirlik.
- **Data parallelism:** Aynı veriyi bölüp farklı çekirdeklerde aynı fonksiyonu çalıştırma. **Task parallelism:** Farklı fonksiyonları/görevleri farklı çekirdeklerde çalıştırma.
- **Amdahl Yasası:** $\text{speedup} \le \frac{1}{S + \frac{1 - S}{N}}$; $N \to \infty \implies \text{speedup} \to \frac{1}{S}$.
- **Many-to-One:** $M$ kullanıcı thread'i $\to 1$ çekirdek thread'i (biri bloklanırsa hepsi bloklanır, paralel çalışamaz).
- **One-to-One:** $1$ kullanıcı thread'i $\to 1$ çekirdek thread'i (gerçek paralellik, yüksek çekirdek yükü; Windows ve Linux).
- **Many-to-Many:** $M$ kullanıcı thread'i $\to N$ çekirdek thread'i ($M \ge N$). **Two-Level:** Many-to-Many + kritik thread'ler için One-to-One bağlama.
- **Pthreads:** `pthread_attr_init(&attr)` $\to$ `pthread_create(&tid, &attr, runner, arg)` $\to$ `pthread_join(tid, NULL)` $\to$ `pthread_exit(0)`.
- **OpenMP:** `#pragma omp parallel` (çekirdek sayısı kadar thread oluşturur), `#pragma omp parallel for` (`for` döngüsünü paralelleştirir).
- **Thread iptali:** Asenkron (hemen sonlandırır) ve ertelenmiş / deferred (varsayılan; iptal noktasında güvenli sonlandırır).
- **LWP (Lightweight Process):** Kullanıcı thread'i ile çekirdek thread'i arasındaki ara veri yapısı (sanal işlemci).
- **Windows thread yapıları:** Çekirdek alanında `ETHREAD` ve `KTHREAD`, kullanıcı alanında `TEB`.
- **Linux `clone()` bayrakları:** `CLONE_FS` (dosya sistemi bilgisi), `CLONE_VM` (bellek uzayı), `CLONE_SIGHAND` (sinyal işleyiciler), `CLONE_FILES` (açık dosyalar).
- **IPC kalıcılığı:** Pipe $\to$ process-persistent; Mesaj kuyruğu ve paylaşımlı bellek $\to$ kernel-persistent; FIFO $\to$ filesystem-persistent.

## Detaylı Açıklamalar

- **Ortak değişken üzerinde çalışan iki thread örneği.** Hoca slaytta (ekrandan, 00:31:50) ortak bir `x = 1` tam sayı değişkenini kullanan iki ayrı thread fonksiyonu (`f` ve `g`) tanımladı:
  - `f()` fonksiyonu (Yıldız senaryosu): `x++`, ardından `print(x)` çalıştırır.
  - `g()` fonksiyonu (Üçgen senaryosu): `print(x)`, ardından `x *= 2`, ardından tekrar `print(x)` çalıştırır.
  - Her satırın kendi içinde atomik olduğu varsayıldığında:
    - Yürütme `f()`'ten başlarsa `x` önce 2 olur; dolayısıyla ekranda ilk değer olarak `1` görülmesi imkânsızdır. Ardından `f()`'teki veya `g()`'deki `print(x)` çalışarak `2` yazdırılır; `x *= 2` çalıştıktan sonra `4` değerine ulaşılır ve planlama sırasına göre `2, 2, 4` veya `2, 4, 4` çıktıları oluşabilir.
    - Yürütme `g()`'den başlarsa önce `1` yazdırılır, sonra `x *= 2` ile `x = 2` olur; hemen ardından `g()` ikinci `print(x)`'i çalıştırmadan işlemci `f()`'e geçip `x++` yaparsa `x = 3` olur ve ekranda `2` hiç görülmeden `1`'den sonra doğrudan `3` yazdırılabilir.
- **Amdahl Yasası ve sayısal örnekler.** Slaytta (ekrandan, 00:38:10 ve 00:41:20) verilen hızlanma formülü:
  $$\text{speedup} \le \frac{1}{S + \frac{1 - S}{N}}$$
  - **Örnek 1:** Tek çekirdekte $t = 10\text{ sn}$ süren bir işin %50'si seri ($S = 0.5$, yani $5\text{ sn}$), %50'si paralel ($1 - S = 0.5$, yani $5\text{ sn}$) olsun. Sistemde $N = 5$ çekirdek varsa paralel kısım $5 / 5 = 1\text{ sn}$ sürer; toplam süre $5 + 1 = 6\text{ sn}$ olur (%40 zaman kazancı, hızlanma $\frac{10}{6} \approx 1.67$ kat).
    - **Ders sonrası not:** Hoca 00:40:15 civarında oranı yüzde cinsinden yerine koyarken dil sürçmesiyle $\frac{1}{50 + 50/5} = \frac{1}{60}$ yazmıştır; formülde $S$ ve $1 - S$ ondalık oran ($0.50$) olarak yazıldığında hızlanma $\frac{1}{0.50 + 0.50/5} = \frac{1}{0.60} = \frac{10}{6} \approx 1.67$ kat, yeni çalışma süresi ise $10 \times 0.60 = 6\text{ sn}$ olur.
  - **Örnek 2:** Uygulama %75 paralel ($1 - S = 0.75$) ve %25 seri ($S = 0.25$) ise 1 çekirdekten $N = 2$ çekirdeğe geçildiğinde 100 birimlik iş $25 + \frac{75}{2} = 62.5$ birimde biter; hızlanma $\frac{1}{0.25 + 0.75/2} = \frac{1}{0.625} = 1.6$ kattır.
- **POSIX Pthreads ile toplama örneği.** Slaytta (ekrandan, 01:10:20) komut satırından alınan üst sınıra kadar $1 + 2 + \dots + \text{upper}$ toplamını alt thread'de hesaplayan C programı (`gcc -Wall` ile derlenip doğrulanmıştır):

  ```c
  #include <pthread.h>
  #include <stdio.h>
  #include <stdlib.h>

  int sum; /* thread'ler tarafindan paylasilan global veri */
  void *runner(void *param); /* thread fonksiyonu prototipi */

  int main(int argc, char *argv[]) {
      pthread_t tid;       /* thread kimligi */
      pthread_attr_t attr; /* thread oznitelik yapisi */

      if (argc != 2) {
          fprintf(stderr, "Kullanim: %s <tam_sayi>\n", argv[0]);
          return -1;
      }

      /* varsayilan oznitelikleri al */
      pthread_attr_init(&attr);
      /* thread'i olustur ve runner fonksiyonunu baslat */
      pthread_create(&tid, &attr, runner, argv[1]);
      /* thread'in sonlanmasini bekle */
      pthread_join(tid, NULL);

      printf("sum = %d\n", sum);
      return 0;
  }

  void *runner(void *param) {
      int i, upper = atoi(param);
      sum = 0;

      for (i = 1; i <= upper; i++)
          sum += i;

      pthread_exit(0);
  }
  ```

- **OpenMP ile paralel bölge ve döngü paralelleştirme.** Derleyici direktifleriyle açıkça thread oluşturmadan paralel programlama yapılır (ekrandan, 01:24:40):

  ```c
  #include <omp.h>
  #include <stdio.h>

  int main(int argc, char *argv[]) {
      /* seri kod */
      #pragma omp parallel
      {
          printf("I am a parallel region.");
      }
      /* dizi toplama dongusunun paralellestirilmesi:
      #pragma omp parallel for
      for (i = 0; i < N; i++) {
          c[i] = a[i] + b[i];
      }
      */
      return 0;
  }
  ```

- **Linux'ta görev (`task`) yapısı ve `clone()` sistem çağrısı.** Linux çekirdeği proses ile thread arasında yapısal bir ayrım yapmaz; her yürütme birimini bir görev (`task`) olarak adlandırır ve `struct task_struct` veri yapısıyla temsil eder (ekrandan, 01:40:00). `clone()` sistem çağrısına verilen bayraklar ebeveyn ve çocuk görev arasında nelerin paylaşılacağını belirler: `CLONE_FS` (dosya sistemi bilgisi paylaşılır), `CLONE_VM` (aynı bellek uzayı paylaşılır), `CLONE_SIGHAND` (sinyal işleyiciler paylaşılır) ve `CLONE_FILES` (açık dosyalar kümesi paylaşılır). Tüm bayraklar verildiğinde thread oluşturulmuş olur, hiçbiri verilmezse `fork()` benzeri davranış elde edilir.
- **Uygulama bölümündeki IPC ve Pthread örnekleri:**
  - **Sıradan Pipe (`Ex_1_pipe.c` ve `Ex_1_pipe1.c`):** İlk örnekte (ekrandan, 02:04:30) tek bir `pipe(pipe1)` oluşturulur; `fork()` sonrasında ebeveyn (client) okuma ucunu (`pipe1[0]`) kapatıp kullanıcıdan aldığı dosya adını (`hello.txt`) yazma ucuna (`pipe1[1]`) yazar. Çocuk proses (server) yazma ucunu (`pipe1[1]`) kapatıp `pipe1[0]`'dan dosya adını okur, dosyayı `open()` ile açar ve içeriğini ekrana (`STDOUT_FILENO`) basar. İkinci örnekte (`Ex_1_pipe1.c`) çift yönlü iletişim için `pipe1` ve `pipe2` kullanılır; server okuduğu dosya içeriğini `pipe2` üzerinden client'a geri gönderir.
    - **Ders sonrası not:** Bir öğrencinin "Server dosyayı yazmadan önce client `read()` satırına gelirse ne olur?" sorusu üzerine uygulama anlatımında senkronizasyonun nasıl sağlandığı açık bırakılmıştır; POSIX standartlarına göre `O_NONBLOCK` bayrağı verilmemiş sıradan bir pipe üzerinde yapılan `read()` sistem çağrısı, pipe tamponu boşken yazma ucu açık olduğu sürece çağıran prosesi otomatik olarak **bloklar (uyutur)** ve server `write()` yapana kadar bekletir.
  - **Adlandırılmış Pipe / FIFO (`Ex_2_server.c` ve `Ex_2_client.c`):** `mkfifo("/tmp/fifo.1", FIFO_MODE)` ve `mkfifo("/tmp/fifo.2", FIFO_MODE)` ile dosya sisteminde iki FIFO düğümü oluşturulur; aralarında ebeveyn-çocuk ilişkisi olmayan iki ayrı program bu dosyalar üzerinden çift yönlü haberleşir ve iş bitiminde `unlink()` ile FIFO dosyalarını siler.
  - **POSIX Mesaj Kuyruğu (`Ex_4_mq_dropone.c` ve `Ex_4_mq_takeone.c`):** `mq_open(MSGQOBJ_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, NULL)` ile çekirdek kalıcılığında bir kuyruk açılır (ekrandan, 02:39:00). `mq_send(msgq_id, msgcontent, strlen(msgcontent)+1, msgprio)` ile `3, 1, 6, 2` öncelikli mesajlar kuyruğa eklendiğinde, alıcı taraf `mq_receive()` çağırdığında mesajları FIFO sırasıyla değil, **en yüksek öncelikten başlayarak** (`6`, ardından `3`) teslim alır.
  - **POSIX Paylaşımlı Bellek (`Ex_5_shm_server.c` ve `Ex_5_shm_client.c`):** Sunucu `shm_open()` ile paylaşımlı bellek nesnesini oluşturur, `ftruncate()` ile boyutunu `sizeof(struct msg_s)` olarak ayarlar ve `mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0)` ile kendi sanal adres uzayına eşler (ekrandan, 02:54:30). İstemci aynı nesneyi `shm_open(..., O_RDWR, ...)` ve `mmap()` ile kendi adres uzayına bağlayarak sunucunun yazdığı `type` ve `content` alanlarını doğrudan bellekten okur.
  - **Pthreads ve Mutex ile Üretici-Tüketici (`ex_sm.c`):** Paylaşılan dairesel tampon (`shared_buff[BUFF_MAX]`), `free_index` ve `full_index` değişkenlerine yarış durumu (race condition) olmadan erişmek için `pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER` tanımlanır (ekrandan, 03:04:30); hem `producer` hem `consumer` thread'i kritik bölgeye girmeden önce `pthread_mutex_lock(&mtx)` ve çıkarken `pthread_mutex_unlock(&mtx)` çağırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
