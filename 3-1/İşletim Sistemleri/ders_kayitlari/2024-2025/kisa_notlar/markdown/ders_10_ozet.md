# Ders 10 Çalışma Özeti

## Genel Konular

- Yarış durumu (race condition) ve veri tutarsızlığı
  - İşlemcide tek bir makine komutu yürütülürken kesme kontrolü (interrupt check) komut bittikten sonra yapıldığı için tek makine komutu bölünemezdir (atomiktir). Ancak üst seviye dildeki `counter++` ve `counter--` gibi ifadeler makine düzeyinde üç ayrı komuta (bellekten yazmaca yükle, artır/azalt, belleğe geri yaz) dönüştüğünde bu komutlar arasında bağlam değişimi (context switch) gerçekleşebilir.
  - Üretici ve tüketicinin başlangıçta `counter = 5` olan ortak değişkene eşzamanlı erişmesi sonucunda değerin `5` yerine `4` veya `6` kalmasına **yarış durumu (race condition)** denir (ekrandan, 00:16:30).
- Kritik kesim (critical section) problemi ve üç temel çözüm şartı
  - Ortak değişkenlerin, tabloların veya dosyaların güncellendiği kod parçasına **kritik kesim (critical section)** denir. Bir prosesin yapısı dört bölümden oluşur: **giriş kesimi (entry section)**, **kritik kesim (critical section)**, **çıkış kesimi (exit section)** ve **kalan kesim (remainder section)**.
  - Geçerli bir çözümün sağlaması gereken üç koşul: **Karşılıklı dışlama (mutual exclusion)**, **ilerleme (progress)** ve **sınırlı bekleme (bounded waiting)**.
  - Çekirdek düzeyinde kritik kesim yönetimi: **kesmeli çekirdekler (preemptive kernels)** ve **kesmesiz çekirdekler (nonpreemptive kernels)**.
- Yazılımsal çözümler: Dekker algoritması ve Peterson çözümü
  - İki proses için `turn` değişkenli basit yaklaşım (`while (turn == j);`, ekrandan, 00:25:30) ve Stallings kitabındaki **Dekker algoritması**.
  - **Peterson çözümü (Peterson's solution):** İki prosesin (`Pi` ve `Pj`) paylaşılan `int turn;` ve `boolean flag[2];` değişkenleriyle kritik kesime güvenli girmesini sağlayan yazılımsal algoritmadır (ekrandan, 00:36:00). Üç koşulu da sağlar ancak ikiden fazla prosese doğrudan genellenemez ve `load`/`store` komutlarının atomik olmasını gerektirir.
- Donanımsal senkronizasyon desteği (synchronization hardware)
  - Tek işlemcili sistemlerde kesmeleri kapatmak (disabling interrupts) işe yarasa da çok işlemcili sistemlerde tüm işlemcileri durdurmak çok verimsizdir.
  - Atomik donanım komutları: **`test_and_set`** (`boolean test_and_set(boolean *target)`, ekrandan, 00:47:00), **`compare_and_swap`** (`int compare_and_swap(int *value, int expected, int new_value)`, ekrandan, 00:51:30) ve `test_and_set` ile sınırlı beklemeyi sağlayan $n$ proseslik algoritma (ekrandan, 00:53:00).
- Mutex kilitleri (mutex locks) ve spinlock
  - Uygulama ve sistem programcıları için donanım komutlarını soyutlayan en temel araçtır: `acquire()` ile kilit alınır, `release()` ile bırakılır (ekrandan, 00:59:00).
  - Kilidi alamayan prosesin işlemcide (`running` durumunda) kalarak `while (!available);` döngüsünde beklemesine **meşgul bekleme (busy waiting)**, bu tür kilide **spinlock** denir.
- Semaforlar (semaphores)
  - Dijkstra tarafından önerilen, bir tam sayı değişkeni $S$ üzerinde yalnızca iki atomik işlemle çalışan senkronizasyon aracıdır: **`wait(S)`** (**`P`** — *proberen*, test et/bekle) ve **`signal(S)`** (**`V`** — *verhogen*, artır/sinyal ver).
  - **Sayma semaforu (counting semaphore)** ve **ikili semafor (binary semaphore)** (ekrandan, 01:21:30).
  - **Meşgul beklemesiz (no busy waiting) semafor:** Bekleyen prosesleri `block()` ile semaforun bekleme listesine (`S->list`) alıp `waiting` durumuna geçiren ve `signal()` geldiğinde `wakeup(P)` ile `ready` kuyruğuna uyandıran yapı (ekrandan, 01:29:15).
  - Semaforların yanlış kullanımından doğan **kilitlenme (deadlock)**, **açlık (starvation)** ve **öncelik terslenmesi (priority inversion — çözümü: priority-inheritance protocol)** (ekrandan, 01:31:30).
- Klasik senkronizasyon problemleri
  - **Sınırlı Tampon (Bounded-Buffer) Problemi:** `mutex = 1`, `full = 0`, `empty = n` semaforlarıyla çözüm (ekrandan, 01:36:30).
  - **Okuyucular-Yazıcılar (Readers-Writers) Problemi:** `rw_mutex = 1`, `mutex = 1`, `read_count = 0` ile çoklu okuyucu ve tekil yazıcı senkronizasyonu (ekrandan, 01:42:30).
  - **Yemek Yiyen Filozoflar (Dining-Philosophers) Problemi:** `chopstick[5]` semafor dizisi, herkesin sağ çubuğu aynı anda almasıyla oluşan deadlock ve çözüm yöntemleri (masaya 4 kişi alma, iki çubuğu atomik alma, tek-çift asimetrik çözüm).
- Monitörler (monitors), işletim sistemi örnekleri ve alternatif yaklaşımlar
  - **Monitör** soyut veri tipi, **koşul değişkenleri (`condition x, y;` — `x.wait()`, `x.signal()`)** ve Yemek Yiyen Filozoflar probleminin monitörle çözümü.
  - **Solaris** (adaptive mutex, turnstile), **Windows** (dispatcher objects), **Linux** (`atomic_t`, spinlock, kernel preemption) ve **Pthreads** senkronizasyon araçları.
  - **Alternatif yaklaşımlar:** İşlemsel bellek (Transactional Memory), OpenMP (`#pragma omp critical`) ve fonksiyonel programlama dilleri (Erlang, Scala).

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek bir C satırının makine düzeyinde bölünebilir olması
  - C dilinde tek satır olarak yazılan `counter++` veya `counter--` işlemi, işlemci mimarisinde her zaman tek bir `INC` komutuna karşılık gelmez; çoğu zaman `LOAD`, `ADD` ve `STORE` gibi üç ayrı makine komutuna derlenir. Kesme kontrolü her makine komutunun sonunda yapıldığı için, bu üç komutun ortasında zamanlayıcı kesmesi gelirse veri tutarsızlığı (race condition) ortaya çıkar.
- Kritik kesim çözümünün üç temel şartı ve Dekker/Peterson algoritmaları
  - Bir senkronizasyon çözümünün geçerli sayılması için **mutual exclusion**, **progress** ve **bounded waiting** şartlarının üçünü birden sağlaması gerekir. Hoca, Stallings kitabındaki Dekker algoritmasının adımlarının (hangi adımda hangi şartın sağlanamadığının) ve Peterson çözümünün sınav için mutlaka incelenmesini vurguladı.
- Çok işlemcili sistemlerde kesmeleri kapatmanın verimsizliği
  - Tek işlemcili sistemde kritik kesime girerken kesmeleri kapatmak (disabling interrupts) basit bir çözümdür; ancak çok işlemcili bir sistemde 2–3 prosesin paylaştığı bir değişken yüzünden tüm işlemcilerde kesmeleri kapatmak diğer yüzlerce bağımsız prosesi de durdurur. Hoca bunu kitaptaki "insanlara hiç maaş vermeyerek enflasyonu düşürmeye" ve "ameliyat başarılı ama hasta öldü" durumuna benzetti.
- Meşgul beklemenin (busy waiting / spinlock) neden her zaman kötü olmadığı
  - İlk bakışta kilidi alamayan prosesi `waiting` durumuna atmak mantıklı görünse de, `waiting` durumundan tekrar `ready` kuyruğuna girmek, zamanlayıcıyı beklemek ve bağlam değiştirmek (context switch + dispatch latency) ciddi zaman alır. Kilit çok kısa süre tutuluyorsa prosesin `running` durumunda kalıp `while` döngüsünde beklemesi (spinlock) bağlam değiştirmeden çok daha hızlı sonuç verir.
- Semaforlarda $P$ ve $V$ notasyonu ile sıralama ve kilitlenme soruları
  - Sınavlarda ve literatürde `wait` yerine Felemenkçe *proberen*'den gelen **`P`**, `signal` yerine *verhogen*'den gelen **`V`** harfleri kullanılır. Hoca özellikle iki proses arasında `synch = 0` semaforuyla çalışan `S1; signal(synch);` / `wait(synch); S2;` sıralama örneğini (her zaman `1, 2` basmasını) ve iki semaforun (`S` ve `Q`) ters sırayla beklenmesinden doğan **deadlock** örneğini sınav tipi sorular olarak vurguladı.

## Kısa Tekrar Notları

- **Race condition:** Birden fazla prosesin ortak veriye eşzamanlı erişip değiştirmesi ve nihai sonucun yürütme sırasına bağlı olması.
- **Kritik kesim çözümünün 3 şartı:** 1) Karşılıklı dışlama (Mutual Exclusion), 2) İlerleme (Progress), 3) Sınırlı bekleme (Bounded Waiting).
- **Peterson çözümü:** `flag[i] = true; turn = j; while (flag[j] && turn == j);` $\to$ kritik kesim $\to$ `flag[i] = false;`. İki proseslik yazılımsal çözümdür.
- **`test_and_set(boolean *target)`:** Atomik olarak `*target`'ın eski değerini döndürür ve `*target = TRUE` yapar.
- **`compare_and_swap(int *value, int expected, int new_value)`:** Atomik olarak `*value`'nun eski değerini döndürür; yalnızca `*value == expected` ise `*value = new_value` atamasını yapar.
- **Mutex lock:** `acquire()` (`while (!available); available = false;`) ve `release()` (`available = true;`). Meşgul bekleme yapan mutex'e **spinlock** denir.
- **Semafor işlemleri:** `wait(S)` (`P(S)`): `while (S <= 0); S--;` ve `signal(S)` (`V(S)`): `S++;`.
- **Binary semaphore:** `0` veya `1` değerini alır. **Counting semaphore:** Sınırsız tam sayı değerini alır ($N$ kopyalı kaynağı yönetir).
- **No-busy-waiting semafor:** `wait` içinde `S->value--; if (S->value < 0) block();`; `signal` içinde `S->value++; if (S->value <= 0) wakeup(P);`.
- **Priority inversion:** Düşük öncelikli prosesin, yüksek öncelikli prosesin beklediği kilidi tutması; **priority-inheritance protocol** (düşük öncelikli prosesin geçici olarak yüksek önceliği miras alması) ile çözülür.
- **Bounded-Buffer semaforları:** `mutex = 1` (karşılıklı dışlama), `full = 0` (dolu göz sayısı), `empty = n` (boş göz sayısı).
- **Readers-Writers semaforları:** `rw_mutex = 1` (yazıcılar ve ilk/son okuyucu için), `mutex = 1` (`read_count` değişkenini korumak için), `read_count = 0`.
- **Dining Philosophers deadlock çözümü:** Masaya en çok 4 filozof oturtmak, iki çubuğu kritik kesimde birlikte almak veya asimetrik çözüm (tekler önce sol sonra sağ, çiftler önce sağ sonra sol).
- **Monitör:** İçindeki paylaşılan verilere aynı anda yalnızca tek bir prosedürün erişebildiği yüksek seviyeli soyut veri tipi; senkronizasyon için `x.wait()` ve `x.signal()` koşul değişkenlerini kullanır.

## Detaylı Açıklamalar

- **Yarış durumu (race condition) makine kodu analizi.** Slaytta (ekrandan, 00:16:30) üreticinin `counter++` ve tüketicinin `counter--` ifadelerinin makine dilinde üçer komutla gerçeklendiği durum incelenmiştir:
  - `counter++` gerçeklemesi: `register1 = counter` $\to$ `register1 = register1 + 1` $\to$ `counter = register1`.
  - `counter--` gerçeklemesi: `register2 = counter` $\to$ `register2 = register2 - 1` $\to$ `counter = register2`.
  - Başlangıçta `counter = 5` iken şu serpiştirme (interleaving) gerçekleşirse:
    - `S0:` üretici `register1 = counter` çalıştırır (`register1 = 5`),
    - `S1:` üretici `register1 = register1 + 1` çalıştırır (`register1 = 6`),
    - `S2:` zamanlayıcı kesmesiyle tüketici devreye girer ve `register2 = counter` çalıştırır (`register2 = 5`),
    - `S3:` tüketici `register2 = register2 - 1` çalıştırır (`register2 = 4`),
    - `S4:` üretici `counter = register1` çalıştırır (`counter = 6`),
    - `S5:` tüketici `counter = register2` çalıştırır (`counter = 4`).
    Bir ekleme ve bir çıkarma sonunda `counter` değerinin `5` kalması gerekirken `4` (veya `S4` ile `S5` yer değiştirirse `6`) olduğu görülür.
- **Peterson çözümü.** İki proses ($P_i$ ve $P_j$, burada $j = 1 - i$) arasında paylaşılan `int turn;` ve `boolean flag[2];` (başlangıçta `false`) değişkenlerini kullanan $P_i$ prosesinin kodu (ekrandan, 00:36:00):

  ```c
  do {
      flag[i] = true;
      turn = j;
      while (flag[j] && turn == j);

      /* critical section */

      flag[i] = false;

      /* remainder section */
  } while (true);
  ```

  - $P_i$ kritik kesime girmek istediğinde önce kendi bayrağını kaldırır (`flag[i] = true`) ve nezaketen sırayı karşı tarafa verir (`turn = j`). Eğer $P_j$ kritik kesime girmek istemiyorsa (`flag[j] == false`), $P_i$ döngüde hiç beklemeden kritik kesime girer (ilerleme / progress sağlanır). Eğer her ikisi de aynı anda girmek isterse `turn` değişkeni yalnızca birinin (`i` veya `j`) değerini tutacağından yalnız biri girer (karşılıklı dışlama sağlanır), çıkan proses kendi `flag` değerini `false` yaptığı için bekleyen proses en fazla bir tur sonra içeri girer (sınırlı bekleme sağlanır).
- **Donanım komutları: `test_and_set` ve `compare_and_swap`.**
  - `test_and_set` tanımı ve kullanımı (ekrandan, 00:47:00):

    ```c
    boolean test_and_set(boolean *target) {
        boolean rv = *target;
        *target = TRUE;
        return rv;
    }

    /* Paylasilan lock = false ile karsilikli dislama: */
    do {
        while (test_and_set(&lock))
            ; /* do nothing */
        /* critical section */
        lock = false;
        /* remainder section */
    } while (true);
    ```

  - `compare_and_swap` tanımı ve kullanımı (ekrandan, 00:51:30):

    ```c
    int compare_and_swap(int *value, int expected, int new_value) {
        int temp = *value;
        if (*value == expected)
            *value = new_value;
        return temp;
    }

    /* Paylasilan lock = 0 ile karsilikli dislama: */
    do {
        while (compare_and_swap(&lock, 0, 1) != 0)
            ; /* do nothing */
        /* critical section */
        lock = 0;
        /* remainder section */
    } while (true);
    ```

- **Semaforlarla sıralama, meşgul beklemesiz gerçekleme ve deadlock.**
  - **Sıralama (ekrandan, 01:21:30):** $P_1$'deki `S1` (`printf("1")`) komutunun her zaman $P_2$'deki `S2` (`printf("2")`) komutundan önce çalışmasını garanti etmek için ortak `synch = 0` semaforu tanımlanır; $P_1$ içinde `S1; signal(synch);` ve $P_2$ içinde `wait(synch); S2;` çalıştırılır. İşlemciye önce $P_2$ girse bile `synch == 0` olduğu için `wait(synch)` satırında bekler ve ekranda daima `1`, ardından `2` görülür.
  - **Meşgul beklemesiz (no busy waiting) semafor (ekrandan, 01:29:15):**

    ```c
    wait(semaphore *S) {
        S->value--;
        if (S->value < 0) {
            add this process to S->list;
            block();
        }
    }

    signal(semaphore *S) {
        S->value++;
        if (S->value <= 0) {
            remove a process P from S->list;
            wakeup(P);
        }
    }
    ```

  - **İki semaforlu kilitlenme (deadlock) örneği (ekrandan, 01:31:30):** Başlangıçta $S = 1$ ve $Q = 1$ olan iki semafor için $P_0$ prosesi `wait(S); wait(Q);`, $P_1$ prosesi ise ters sırayla `wait(Q); wait(S);` çağırır. $P_0$ önce `wait(S)` çalıştırıp $S = 0$ yaptıktan hemen sonra bağlam değişimiyle $P_1$ çalışıp `wait(Q)` ile $Q = 0$ yaparsa, artık $P_0$ `wait(Q)`'da, $P_1$ ise `wait(S)`'de sonsuza dek birbirini bekler ve **deadlock** oluşur.
- **Klasik senkronizasyon problemlerinin semafor çözümleri:**
  - **Sınırlı Tampon (Bounded-Buffer, ekrandan, 01:36:30):** Başlangıçta `mutex = 1`, `full = 0`, `empty = n`.
    - Üretici: `wait(empty); wait(mutex); /* tampona ekle */ signal(mutex); signal(full);`
    - Tüketici: `wait(full); wait(mutex); /* tampondan al */ signal(mutex); signal(empty);`
  - **Okuyucular-Yazıcılar (Readers-Writers, ekrandan, 01:42:30):** Başlangıçta `rw_mutex = 1`, `mutex = 1`, `read_count = 0`.
    - Yazıcı: `wait(rw_mutex); /* yazma islemi */ signal(rw_mutex);`
    - Okuyucu:

      ```c
      do {
          wait(mutex);
          read_count++;
          if (read_count == 1)
              wait(rw_mutex); /* Ilk okuyucu yazicilari kilitler */
          signal(mutex);

          /* reading is performed */

          wait(mutex);
          read_count--;
          if (read_count == 0)
              signal(rw_mutex); /* Son okuyucu yazicilara izin verir */
          signal(mutex);
      } while (true);
      ```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
