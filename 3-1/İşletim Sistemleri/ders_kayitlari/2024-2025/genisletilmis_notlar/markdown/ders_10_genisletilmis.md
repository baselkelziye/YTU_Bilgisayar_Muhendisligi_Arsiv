# Ders 10 Genişletilmiş Notu: Proses Senkronizasyonu: Kritik Kesim Problemi, Peterson Çözümü, Donanım Desteği, Mutex Kilitleri, Semaforlar, Klasik Problemler ve Monitörler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Komut Döngüsü, Veri Tutarsızlığı ve Yarış Durumu (Race Condition)
- 2. Kritik Kesim (Critical Section) Problemi ve Üç Temel Koşul
- 3. Yazılımsal Çözümler: Dekker Yaklaşımı ve Peterson Çözümü
- 4. Donanımsal Senkronizasyon Desteği (Synchronization Hardware)
- 5. Mutex Kilitleri (Mutex Locks) ve Spinlock
- 6. Semaforlar (Semaphores)
- 7. Klasik Senkronizasyon Problemleri
- 8. Monitörler (Monitors) ve Koşul Değişkenleri (Condition Variables)
- 9. İşletim Sistemi Örnekleri ve Alternatif Senkronizasyon Yaklaşımları
- Örnek Sorular
- Dersin Toparlaması

## 1. Komut Döngüsü, Veri Tutarsızlığı ve Yarış Durumu (Race Condition)

### 1.1 Komut Yürütme Döngüsü ve Kesme Kontrolü (Interrupt Check)

Önceki derste işlemci zamanlama (CPU scheduling) algoritmaları incelenirken 5. Bölüm (Proses Senkronizasyonu) sonraya bırakılmıştı; bu derste eşzamanlı çalışan proseslerin ve iş parçacıklarının (thread'lerin) senkronizasyonu ele alındı.

Konuya başlamadan önce hoca, ilk haftalarda anlatılan komut yürütme akışını (execution flow) ve kesme kontrolünü hatırlattı. İşletim sistemi kesme güdümlü (interrupt-driven) bir sistemdir. Bir makine komutu yürütülürken şu adımlar izlenir:

```text
+-----------------------------------+
| Komut Getirme (Instruction Fetch) |
+-----------------------------------+
                  |
                  v
+-----------------------------------+
| İşlenenleri Al ve Yürüt (Execute) |  <-- Bu aşama bitene kadar kesinti olmaz
+-----------------------------------+
                  |
                  v
+-----------------------------------+
| Kesme Kontrolü (Interrupt Check)  |  <-- Komut bittikten sonra kontrol edilir
+-----------------------------------+
         /                 \
  (Kesme yok)          (Kesme var)
       v                    v
Sonraki komuta geç    Başka prosese/komuta CPU tahsis et
```

Tek bir makine komutu (örneğin bir toplama veya yazmaca taşıma komutu) işlemciye girdiğinde, o komutun yürütmesi tamamlanana kadar araya kesme girmez; kesme kontrolü (`interrupt check`) **komut tamamlandıktan sonra, bir sonraki makine komutuna geçmeden önce** yapılır. Eğer bekleyen bir kesme varsa işlemci bir sonraki komuta geçmeden başka bir prosese veya thread'e tahsis edilir.

### 1.2 Sınırlı Tampon (Bounded-Buffer) ve `counter` Değişkeni

İşlemci kullanımını (CPU utilization) maksimize etmek için proseslerin veya thread'lerin eşzamanlı (concurrent) çalıştırıldığını biliyoruz. Ancak bir proses çalışmasını kısmen tamamlamışken yarıda kesilip işlemci başka bir prosese verildiğinde, ortak paylaşılan bir veriye eşzamanlı erişim nedeniyle **veri tutarsızlığı (data inconsistency)** meydana gelebilir. İşbirlikçi (cooperating) proseslerin doğru çalışabilmesi için veri tutarlılığının (data consistency) korunması gerekir.

Daha önce görülen üretici-tüketici (producer-consumer) probleminde sınırlı tamponda (`buffer[BUFFER_SIZE]`) kaç adet dolu eleman bulunduğunu takip etmek için ortak bir `counter` (başlangıçta `0`) değişkeni kullanıldığını düşünelim:

- **Üretici (Producer) Kodu:**

  ```c
  while (true) {
      /* produce an item in next_produced */
      while (counter == BUFFER_SIZE)
          ; /* do nothing (tampon doluysa bekle) */
      buffer[in] = next_produced;
      in = (in + 1) % BUFFER_SIZE;
      counter++;
  }
  ```

- **Tüketici (Consumer) Kodu:**

  ```c
  while (true) {
      while (counter == 0)
          ; /* do nothing (tampon bossa bekle) */
      next_consumed = buffer[out];
      out = (out + 1) % BUFFER_SIZE;
      counter--;
      /* consume the item in next_consumed */
  }
  ```

Notasyon hatırlatması: C dilinde `while (1) { ... }` ifadesi süslü parantez içindeki bloğu sonsuz kez çalıştırırken, sonunda noktalı virgül bulunan `while (şart);` ifadesi **şart doğru olduğu sürece hiçbir iş yapmadan o satırda bekle** anlamına gelir; şart bozulduğunda bir alt satıra geçilir.

### 1.3 Makine Dili Düzeyinde `counter++` ve `counter--` ile Yarış Durumu

Üst seviye C dilinde yazdığımız `counter++` ve `counter--` ifadeleri, işlemci mimarisinde doğrudan tek bir `INC` makine komutuna derlenirse bölünemez (atomik) çalışır ve sorun çıkmaz. Ancak birçok mimaride veya derleyici çıktısında bu ifadeler yazmaçlar üzerinden **üç ayrı makine komutuna** (örneğin `MOV AX, counter` $\to$ `ADD AX, 1` $\to$ `MOV counter, AX`) dönüşür (ekrandan, 00:16:30):

- `counter++` makine kodu karşılığı:

  ```text
  register1 = counter
  register1 = register1 + 1
  counter = register1
  ```

- `counter--` makine kodu karşılığı:

  ```text
  register2 = counter
  register2 = register2 - 1
  counter = register2
  ```

Başlangıçta tamponda 5 eleman olduğunu (`counter = 5`) ve üretici ile tüketicinin makine komutlarının zamanlayıcı nedeniyle şu sırayla (interleaving) çalıştığını düşünelim (ekrandan, 00:16:30):

| Adım | Çalışan Taraf ve Makine Komutu | Sonuç / Yazmaç ve Bellek Durumu |
|---|---|---|
| `S0` | producer execute `register1 = counter` | `{register1 = 5}` |
| `S1` | producer execute `register1 = register1 + 1` | `{register1 = 6}` (henüz belleğe yazılmadı, kesme geldi!) |
| `S2` | consumer execute `register2 = counter` | `{register2 = 5}` (bellekteki `counter` hâlâ 5!) |
| `S3` | consumer execute `register2 = register2 - 1` | `{register2 = 4}` |
| `S4` | producer execute `counter = register1` | `{counter = 6}` |
| `S5` | consumer execute `counter = register2` | `{counter = 4}` |

Normalde `5` olan `counter` değerinin bir üretici (`+1`) ve bir tüketici (`-1`) işleminden sonra tekrar **`5`** olması gerekirken, `S4` ve `S5` adımlarının çalışma sırasına göre bellekteki nihai değer **`4`** (veya `S5` önce çalışıp `S4` sonra çalışırsa **`6`**) olur.

Birden fazla proses veya thread'in ortak paylaşılan bir veriye aynı anda erişip onu değiştirmeye çalıştığı ve işlemin nihai sonucunun erişimlerin gerçekleşme sırasına bağlı olduğu bu duruma **yarış durumu (race condition)** denir.

## 2. Kritik Kesim (Critical Section) Problemi ve Üç Temel Koşul

### 2.1 Kritik Kesim Kavramı ve Genel Yapısı

Bilgisayar sisteminde işlemci (CPU) ve ana bellek gibi kaynaklar zaman paylaşımıyla prosesler arasında paylaştırılabilirken, yazıcı gibi G/Ç aygıtları veya aynı anda güncellenen ortak değişkenler aynı anda birden fazla proses tarafından paylaşılamaz.

Sistemde $n$ adet proses veya thread ($\{P_0, P_1, \dots, P_{n-1}\}$) bulunduğunu düşünelim. Her prosesin kendi kodu içinde ortak değişkenleri değiştirdiği, bir veritabanı tablosunu güncellediği veya bir dosyaya yazdığı, dolayısıyla yarış durumu (race condition) oluşabilecek kod bölgesine **kritik kesim (critical section)** denir. Temel kural şudur: **Bir proses kendi kritik kesiminde çalışıyorken, başka hiçbir proses kendi kritik kesimine giremez.**

Çok şeritli bir yolun dar bir köprüye girerken tek şeride düşmesine ve köprü çıkışında tekrar genişlemesine benzer biçimde, kritik kesim problemi dört bölümlü bir protokolle modellenir:

1. **Giriş Kesimi (Entry Section):** Prosesin kritik kesime girmek için izin istediği hazırlık bölümü.
2. **Kritik Kesim (Critical Section):** Ortak veriye erişilen bölüm (aynı anda yalnız bir proses bulunabilir).
3. **Çıkış Kesimi (Exit Section):** Kritik kesimden çıkarken iznin devredildiği veya kilidin bırakıldığı bölüm.
4. **Kalan Kesim (Remainder Section):** Prosesin ortak kaynakla ilgisi olmayan diğer normal kodları.

Herhangi bir $P_i$ prosesinin genel yapısı:

```c
do {
    /* entry section (giris kesimi) */

        /* critical section (kritik kesim) */

    /* exit section (cikis kesimi) */

        /* remainder section (kalan kesim) */
} while (true);
```

### 2.2 İki Proses İçin Basit `turn` Değişkenli Yaklaşım

İki proses ($P_i$ ve $P_j$) arasında sıranın kimde olduğunu tutan ortak bir `turn` değişkeni tanımlandığını varsayalım (ekrandan, 00:25:30):

```c
do {
    while (turn == j);

    /* critical section */

    turn = j;

    /* remainder section */
} while (true);
```

Burada $P_i$ prosesi `turn == j` olduğu sürece bekler; sıra kendisine geldiğinde (`turn == i`) kritik kesime girer ve çıkarken sırayı nezaketen $P_j$'ye (`turn = j`) devreder. Ancak bu basit yaklaşımın önemli eksiklikleri vardır:

1. `while (turn == j);` kontrolünün makine dilinde tek bir atomik `CMP` komutuyla yapılacağı her mimaride garanti edilemez.
2. İkiden fazla proses ($P_1, P_2, P_3, \dots$) olduğunda kimin kime sıra vereceği (`turn == j || turn == k ...`) bu yapıyla yönetilemez.
3. Bir proses kalan kesiminde (`remainder section`) çok uzun süre kalırsa ve kritik kesime girmek istemiyorsa bile `turn` değerini değiştirmeyeceği için diğer prosesin kritik kesime tekrar girmesini engeller (ilerleme / progress şartını bozar).

### 2.3 Kritik Kesim Probleminin Çözümü İçin Üç Zorunlu Şart

Kritik kesim problemine önerilen herhangi bir çözümün doğru kabul edilebilmesi için şu **üç koşulu** aynı anda sağlaması zorunludur:

1. **Karşılıklı Dışlama (Mutual Exclusion):** Eğer $P_i$ prosesi kendi kritik kesiminde çalışıyorsa, başka hiçbir proses kendi kritik kesiminde çalışamaz.
2. **İlerleme (Progress):** Kritik kesimde çalışan hiçbir proses yoksa ve kritik kesime girmek isteyen bazı prosesler varsa, bir sonraki adımda kritik kesime kimin gireceğinin seçimine yalnızca kalan kesiminde (`remainder section`) çalışmayan prosesler katılabilir ve bu seçim sonsuza dek ertelenemez (gereksiz yere geciktirilemez).
3. **Sınırlı Bekleme (Bounded Waiting):** Bir proses kritik kesime girmek için isteğini yaptıktan sonra ve bu isteği kabul edilmeden önce, diğer proseslerin kendi kritik kesimlerine girmelerine izin verilen sayıda bir **üst sınır (bound)** bulunmalıdır (aksi halde bazı prosesler hiç sıra alamaz ve açlık / starvation ya da kilitlenme doğar).

### 2.4 İşletim Sistemi Çekirdeğinde Kritik Kesim Yönetimi

Uygulama yazılımlarının yanı sıra işletim sistemi çekirdeğinin (kernel) kendisi de açık dosyalar listesi, bellek tahsis tabloları ve hazır kuyrukları gibi pek çok ortak veri yapısını barındırır. Çekirdek içindeki kritik kesimleri yönetmek için iki yaklaşım vardır:

1. **Kesmeli Çekirdekler (Preemptive Kernels):** Bir proses çekirdek modunda (kernel mode) çalışırken kesilmesine (preempt edilmesine) izin verir. Daha yüksek etkileşim ve gerçek zamanlı tepki sağlar ancak çekirdek veri yapılarının yarış durumlarına karşı dikkatle korunmasını gerektirir.
2. **Kesmesiz Çekirdekler (Nonpreemptive Kernels):** Çekirdek modunda çalışan bir prosesin çekirdek modundan çıkana, bloklanana veya CPU'yu kendi isteğiyle bırakana kadar kesilmesine izin vermez. Aynı anda çekirdek modunda yalnız bir süreç aktif olduğundan çekirdek veri yapılarında yarış durumu oluşmaz.

## 3. Yazılımsal Çözümler: Dekker Yaklaşımı ve Peterson Çözümü

### 3.1 Dekker Algoritması

Hoca, Stallings'in ders kitabında yer alan ve iki prosesin kritik kesim problemini donanım desteği olmadan çözmek için 4–5 aşamada geliştirilen **Dekker algoritmasına** değindi. İlk aşamalarda yalnızca `turn` veya yalnızca `flag` kullanıldığında bazı adımlarda karşılıklı dışlamanın (mutual exclusion), bazı adımlarda ise ilerlemenin (progress — kilitlenme veya sonlu erteleme nedeniyle) sağlanamadığını, son aşamada her ikisinin birleştirilmesiyle doğru çözüme ulaşıldığını belirterek öğrencilerin bu adımları kitaptan incelemesini istedi.

> **Hocanın vurgusu:** Dekker algoritmasının gelişim adımları (hangi adımda hangi şartın sağlanamadığı) sınavda sorulabilir; Stallings kitabının ilgili bölümünden mutlaka incelenmelidir.

### 3.2 Peterson Çözümü (Peterson's Solution)

Dekker algoritmasının karmaşıklığını sadeleştiren **Peterson çözümü**, iki proses ($P_i$ ve $P_j$, örneğin $P_0$ ve $P_1$) için geliştirilmiş klasik bir **yazılımsal (software) çözümdür** (ekrandan, 00:36:00). Algoritma, makine dilindeki temel `load` ve `store` komutlarının **atomik (kesilemez)** olduğunu varsayar.

İki proses şu iki veri öğesini paylaşır:

```c
int turn;
boolean flag[2];
```

- **`turn` değişkeni:** Kritik kesime girme sırasının kimde olduğunu gösterir (`turn == i` ise sıra $P_i$'dedir).
- **`flag` dizisi:** Bir prosesin kritik kesime girmeye **hazır (istekli)** olup olmadığını gösterir (`flag[i] = true` ise $P_i$ kritik kesime girmek istiyordur; başlangıçta her ikisi de `false`'tur).

$P_i$ prosesi için Peterson algoritması (karşı taraf $P_j$ için `i` ve `j` yer değiştirir):

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

Peterson çözümünün üç temel şartı sağladığının doğrulanması:

1. **Karşılıklı Dışlama (Mutual Exclusion):** Hem $P_i$ hem de $P_j$'nin aynı anda kritik kesime girebilmesi için her ikisinin de `while` döngüsünü kırması gerekir. İkisi de girmek istediğinde `flag[i] == true` ve `flag[j] == true` olur; ancak `turn` değişkeni aynı anda hem `i` hem `j` olamaz (son atamayı kim yaptıysa `turn` diğerinin değerini alır). Dolayısıyla biri `while` döngüsünde beklerken yalnızca diğeri kritik kesime girebilir.
2. **İlerleme (Progress):** Eğer $P_j$ kritik kesime girmek istemiyorsa `flag[j] == false` olur; bu durumda $P_i$ `while (flag[j] && turn == j)` koşulunda hiç beklemeden doğrudan kritik kesime girer.
3. **Sınırlı Bekleme (Bounded Waiting):** $P_j$ kritik kesimden çıkarken çıkış kesiminde `flag[j] = false` yapar (veya tekrar girmek isterse `turn = i` yapar); böylece beklemekte olan $P_i$ en fazla bir kez bekledikten sonra kritik kesime girer.

**Peterson Çözümünün Kısıtları:**

- Yalnızca **iki proses** için doğrudan uygulanabilir; 20 prosesin yarıştığı bir duruma doğrudan ölçeklenemez.
- Çağdaş işlemci mimarilerinde derleyici veya işlemci, aralarında bağımlılık olmayan `load` ve `store` işlemlerinin sırasını performans için değiştirebildiğinden (`flag[i] = true` ve `turn = j` gibi), donanım desteği olmadan modern çok çekirdekli sistemlerde doğru çalışması garanti edilemez.

## 4. Donanımsal Senkronizasyon Desteği (Synchronization Hardware)

Kritik kesim problemini çözmenin genel yolu **kilit (lock)** kullanmaktır: Bir proses kritik kesime girmeden önce kilidi alır (`acquire lock`), çıkarken kilidi bırakır (`release lock`).

### 4.1 Kesmelerin Devre Dışı Bırakılması (Disabling Interrupts)

Tek işlemcili (uniprocessor) bir sistemde kritik kesim problemi çok basit bir yolla çözülebilir: Paylaşılan bir değişken değiştirilirken **kesmeler devre dışı bırakılır (disable interrupts)**. Kesmeler kapalı olduğunda zamanlayıcı kesmesi devreye giremeyeceği için çalışan komut dizisi kesintiye uğramadan (preemption olmadan) tamamlanır.

Ancak **çok işlemcili (multiprocessor)** sistemlerde kesmeleri kapatmak uygulanabilir bir çözüm değildir:

- Tüm işlemcilerde kesmeleri kapatmak için her işlemciye mesaj göndermek çok zaman alır ve sistem verimini düşürür.
- Yalnızca 2–3 prosesin paylaştığı bir kaynak yüzünden tüm işlemcilerde kesmeleri kapatmak, o kaynakla hiçbir ilgisi olmayan yüzlerce başka prosesin de işlemcileri kullanmasını engeller. Hoca bu durumu ders kitabındaki ekonomi benzetmesiyle açıkladı: Enflasyonu düşürmek için ülkedeki hiç kimseye maaş vermeyip tüm tüketimi durdurursanız enflasyon düşer ama ekonomi tamamen durur ("ameliyat başarılı ama hasta öldü").

Bu nedenle modern bilgisayar mimarileri kesmeleri kapatmak yerine **özel atomik donanım komutları (special atomic hardware instructions)** sunar.

### 4.2 `test_and_set` Komutu

Bir bellek kelimesinin (word) içeriğini **bölünemez (atomik)** olarak test edip değiştiren donanım komutudur. Mantıksal işleyişini gösteren C notasyonu (ekrandan, 00:47:00):

```c
boolean test_and_set(boolean *target) {
    boolean rv = *target;
    *target = TRUE;
    return rv;
}
```

Komutun üç temel özelliği:

1. **Atomik olarak (bölünmeden) yürütülür.**
2. Kendisine geçirilen parametrenin **orijinal (eski) değerini** döndürür (`return rv`).
3. Parametrenin **yeni değerini her durumda `TRUE`** olarak ayarlar (`*target = TRUE`).

Başlangıçta `false` olarak ilklendirilen paylaşılan bir `boolean lock = false;` değişkeni kullanılarak $n$ proses arasında karşılıklı dışlama şöyle sağlanır:

```c
do {
    while (test_and_set(&lock))
        ; /* do nothing (kilit doluysa bekle) */

        /* critical section */

    lock = false;

        /* remainder section */
} while (true);
```

- Kilit boşken (`lock == false`) gelen ilk proses `test_and_set(&lock)` çağırdığında fonksiyon `false` döndürür ama aynı anda `lock` değişkenini `true` yapar. Döndürülen değer `false` olduğu için `while` döngüsü kırılır ve ilk proses kritik kesime girer.
- İlk proses içerideyken gelen diğer tüm prosesler `lock == true` olduğu için `test_and_set(&lock)` çağrısından `true` alır ve `while` döngüsünde bekler; ilk proses çıkarken `lock = false;` yaptığında bekleyenlerden yalnız biri içeri girebilir.

### 4.3 `compare_and_swap` (CAS) Komutu

İki kelime üzerinde çalışan ve koşula bağlı atomik takas/atama yapan donanım komutudur (ekrandan, 00:51:30):

```c
int compare_and_swap(int *value, int expected, int new_value) {
    int temp = *value;

    if (*value == expected)
        *value = new_value;

    return temp;
}
```

Komutun üç temel özelliği:

1. **Atomik olarak yürütülür.**
2. `value` parametresinin **orijinal (eski) değerini** (`temp`) döndürür.
3. Yalnızca `*value == expected` koşulu sağlanıyorsa `*value` değişkenine `new_value` değerini atar (`*value` beklenen değere eşit değilse hiçbir değişiklik yapmaz).

Başlangıçta `0` olarak ilklendirilen paylaşılan `int lock = 0;` değişkeniyle karşılıklı dışlama kullanımı:

```c
do {
    while (compare_and_swap(&lock, 0, 1) != 0)
        ; /* do nothing */

        /* critical section */

    lock = 0;

        /* remainder section */
} while (true);
```

`lock == 0` iken gelen ilk proses `compare_and_swap(&lock, 0, 1)` çağırdığında `*value == 0` koşulu sağlandığı için `lock` değeri `1` yapılır ve eski değer olan `0` döndürülür (`0 != 0` yanlış olduğundan döngüden çıkıp kritik kesime girer). Sonraki prosesler çağrı yaptığında `lock == 1` olduğu için `1 != 0` koşuluyla döngüde bekler, ta ki içerideki proses `lock = 0;` yapana kadar.

### 4.4 `test_and_set` ile Sınırlı Beklemeli (Bounded-Waiting) Çözüm

Yukarıdaki basit `test_and_set` ve `compare_and_swap` çözümleri karşılıklı dışlamayı sağlar ancak **sınırlı bekleme (bounded waiting)** şartını garanti etmez. Sınırlı beklemeyi de sağlamak için başlangıçta `false` olan `boolean waiting[n];` ve `boolean lock = false;` paylaşılan verileriyle şu algoritma kullanılır (ekrandan, 00:53:00):

```c
do {
    waiting[i] = true;
    key = true;
    while (waiting[i] && key)
        key = test_and_set(&lock);
    waiting[i] = false;

    /* critical section */

    j = (i + 1) % n;
    while ((j != i) && !waiting[j])
        j = (j + 1) % n;

    if (j == i)
        lock = false;
    else
        waiting[j] = false;

    /* remainder section */
} while (true);
```

Çıkış kesiminde $P_i$ prosesi kendisinden sonraki prosesleri (`j = (i + 1) % n`) dairesel sırayla tarar; bekleyen bir $P_j$ bulursa kilidi doğrudan ona devreder (`waiting[j] = false`), bekleyen kimse yoksa `lock = false` yapar. Böylece kritik kesime girmek isteyen her proses en fazla $n - 1$ tur içinde sırayı alır.

## 5. Mutex Kilitleri (Mutex Locks) ve Spinlock

Donanım tabanlı çözümler uygulama programcılarının doğrudan kullanması için karmaşık ve düşük seviyeli olduğundan, işletim sistemi tasarımcıları kritik kesim problemini çözmek için daha üst seviyeli yazılım araçları geliştirmiştir. Bunların en temeli **mutex (mutual exclusion) kilididir** (ekrandan, 00:59:00).

Bir mutex kilidinde kilidin müsait olup olmadığını gösteren bir `available` boolean değişkeni ve iki **atomik** işlem (`acquire()` ve `release()`) bulunur:

```c
acquire() {
    while (!available)
        ; /* busy wait (mesgul bekleme) */
    available = false;
}

release() {
    available = true;
}
```

Kullanım şablonu:

```c
do {
    acquire lock

        /* critical section */

    release lock

        /* remainder section */
} while (true);
```

Hem `acquire()` hem de `release()` çağrıları arka planda donanımsal atomik komutlar kullanılarak **atomik** olarak gerçeklenmelidir.

### Meşgul Bekleme (Busy Waiting) ve Spinlock

Yukarıdaki `acquire()` tanımında, bir proses kritik kesimdeyken kritik kesime girmek isteyen diğer herhangi bir proses `acquire()` çağrısı içindeki `while (!available);` döngüsünde sürekli dönerek bekler. Prosesin `waiting` durumuna geçmeden, işlemci üzerinde (`running` durumunda) boş döngü çalıştırarak beklemesine **meşgul bekleme (busy waiting)**, bu tür mutex kilidine ise **spinlock** (proses kilit açılana kadar olduğu yerde döndüğü / "spin" ettiği için) adı verilir.

- **Dezavantajı:** Tek işlemcili veya çok programlı sistemde bir proses CPU'da döngüyle beklerken başka bir prosesin verimli iş yapabileceği CPU döngülerini boşa harcar.
- **Avantajı:** Hoca bu noktada önemli bir soru sordu: *"Kilidi alamayan prosesi neden hemen `waiting` durumuna atmıyoruz?"* Çünkü bir prosesi `running` durumundan `waiting` durumuna almak, kilit açıldığında tekrar `ready` kuyruğuna koymak, zamanlayıcıdan sıra beklemek ve dağıtıcı (dispatcher) ile **bağlam değiştirmek (context switch)** kayda değer bir zaman alır. Eğer kilit yalnızca çok kısa bir süre tutulacaksa, çok işlemcili (multiprocessor) bir sistemde bir çekirdekte kilit kısa sürede bırakılırken diğer çekirdekteki thread'in bağlam değiştirmeden spinlock döngüsünde beklemesi **çok daha hızlıdır**.

## 6. Semaforlar (Semaphores)

### 6.1 Semafor Kavramı, $P$ ve $V$ İşlemleri

Mutex kilitleri yalnızca 0/1 (var/yok) durumunu temsil ederken, daha karmaşık senkronizasyon gereksinimleri için **Edsger Dijkstra** tarafından **semafor (semaphore)** yapısı önerilmiştir. Hoca semafor kelimesinin kökenini demiryolu benzetmesiyle açıkladı: İki hatlı bir demiryolunun maliyet nedeniyle tek hatlı bir köprüden geçtiği yerde, köprü girişlerinde kırmızı/yeşil bayrak (semafor) bulunur; hat boşsa yeşil yanar ve tren girer, tren içerideyken bayrak kırmızıya döner ve karşıdan gelen tren bekler.

Bir semafor $S$, başlangıç değerinin atanması dışında yalnızca iki standart **atomik** işlemle erişilebilen bir **tam sayı değişkenidir (integer variable)**:

1. **`wait(S)`** — Dijkstra'nın orijinal makalesindeki Felemenkçe *proberen* (test etmek) kelimesinden gelen **`P(S)`** işlemi:

   ```c
   wait(S) {
       while (S <= 0)
           ; // busy wait
       S--;
   }
   ```

2. **`signal(S)`** — Felemenkçe *verhogen* (artırmak) kelimesinden gelen **`V(S)`** işlemi:

   ```c
   signal(S) {
       S++;
   }
   ```

`wait(S)` ve `signal(S)` içinde $S$ tam sayı değerine yapılan tüm değişiklikler **bölünemez (atomik)** olarak yürütülmelidir.

### 6.2 Sayma Semaforu (Counting Semaphore) ve İkili Semafor (Binary Semaphore)

İki tür semafor kullanımı vardır (ekrandan, 01:21:30):

- **Sayma Semaforu (Counting Semaphore):** Tam sayı değeri kısıtlanmamış bir aralıkta değişebilir. Sonlu sayıda özdeş örnekten oluşan bir kaynağa erişimi kontrol etmek için kullanılır: Örneğin sistemde 5 adet yazıcı varsa semafor $S = 5$ ile ilklendirilir. Kaynağı kullanan her proses `wait(S)` çağırarak $S$'yi azaltır ($5 \to 4 \to 3 \to 2 \to 1 \to 0$). $S = 0$ olduğunda tüm kaynaklar doludur; 6. proses `wait(S)` çağırdığında mevcut proseslerden biri işini bitirip `signal(S)` ile sayacı artırana kadar bekler.
- **İkili Semafor (Binary Semaphore):** Tam sayı değeri yalnızca `0` ve `1` arasında değişebilir; işlevsel olarak **mutex kilidiyle aynıdır**.

### 6.3 Semaforla Proses Sıralama Senkronizasyonu

Semaforlar yalnızca kritik kesim korumak için değil, iki prosesin kod parçalarını belirli bir sıraya sokmak için de kullanılır. Slayttaki örnekte (ekrandan, 01:21:30) eşzamanlı çalışan $P_1$ ve $P_2$ prosesleri vardır; $P_1$ içinde `S1` (`printf("1")`) ifadesinin her zaman $P_2$ içindeki `S2` (`printf("2")`) ifadesinden **önce** çalışması istenmektedir.

Bunun için ortak bir `synch` semaforu tanımlanır ve başlangıç değeri **`0`** yapılır (`synch = 0`):

- **$P_1$ Prosesi:**

  ```c
  S1; /* printf("1"); */
  signal(synch);
  ```

- **$P_2$ Prosesi:**

  ```c
  wait(synch);
  S2; /* printf("2"); */
  ```

Yürütme analizi: İşlemci zamanlayıcısı önce $P_2$'yi çalıştırsa bile, başlangıçta `synch == 0` olduğu için $P_2$ `wait(synch)` satırında takılır ve `S2`'ye geçemez. Ancak $P_1$ çalışıp `S1` (`printf("1")`) ifadesini yürüttükten ve `signal(synch)` ile `synch` değerini `1`'e çıkardıktan sonra $P_2$ `wait(synch)` engelini aşarak `S2` (`printf("2")`) satırını çalıştırabilir. Böylece zamanlama sırası ne olursa olsun ekranda **daima `1`, ardından `2`** görülür.

### 6.4 Meşgul Beklemesiz (No Busy Waiting) Semafor Gerçeklemesi

Kritik kesimin uzun sürdüğü durumlarda `while (S <= 0);` ile işlemciyi meşgul etmek (busy waiting) verimsizdir. Bunu önlemek için her semafor bir tam sayı değeri (`value`) ve o semaforda bekleyen proseslerin listesiyle (`list`) bir yapı olarak tanımlanır:

```c
typedef struct {
    int value;
    struct process *list;
} semaphore;
```

İki temel işletim sistemi işlemi kullanılır:

- **`block()`:** Çağıran prosesi çalışır durumdan (`running`) bekleyen durumuna (`waiting`) geçirir ve ilgili semaforun bekleme kuyruğuna (`S->list`) yerleştirir.
- **`wakeup(P)`:** Bekleme kuyruğundaki bloklanmış `P` prosesini çıkarıp hazır kuyruğuna (`ready queue`) aktarır.

Bu iki işlemle `wait` ve `signal` şöyle gerçeklenir (ekrandan, 01:29:15):

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

Burada klasik tanımdan farklı olarak `S->value` negatif değerler alabilir; `S->value` negatif olduğunda mutlak değeri ($|S\to\text{value}|$) o an o semafor kuyruğunda bekleyen proses sayısını gösterir.

### 6.5 Kilitlenme (Deadlock), Açlık (Starvation) ve Öncelik Terslenmesi (Priority Inversion)

Semaforların dikkatsiz kullanımı ciddi senkronizasyon hatalarına yol açabilir (ekrandan, 01:31:30):

1. **Kilitlenme (Deadlock):** İki veya daha fazla prosesin, yalnızca bekleyen proseslerden biri tarafından tetiklenebilecek bir olayı (`signal`) sonsuza dek beklemesi durumudur. Başlangıçta $S = 1$ ve $Q = 1$ olarak ilklendirilmiş iki semaforu kullanan $P_0$ ve $P_1$ proseslerini ele alalım:

   ```text
   P0 Prosesi:              P1 Prosesi:
   -----------              -----------
   wait(S);                 wait(Q);
   wait(Q);                 wait(S);
     . . .                    . . .
   signal(S);               signal(Q);
   signal(Q);               signal(S);
   ```

   - Eğer önce $P_0$ baştan sona kesintisiz çalışıp bitse ve ardından $P_1$ çalışsa hiçbir sorun çıkmaz.
   - Ancak $P_0$ `wait(S);` çalıştırıp $S = 0$ yaptıktan hemen sonra bağlam değişimiyle $P_1$ devreye girip `wait(Q);` çalıştırarak $Q = 0$ yaparsa: $P_0$ bir sonraki satırda `wait(Q);` yapmak ister ama $Q$ kilidi $P_1$'dedir; $P_1$ ise `wait(S);` yapmak ister ama $S$ kilidi $P_0$'dadır. Her iki proses de `signal` satırlarına hiçbir zaman ulaşamayacağı için sonsuza dek kilitlenir (**deadlock**).
2. **Açlık (Starvation / Indefinite Blocking):** Semaforun bekleme listesinin (`S->list`) örneğin LIFO (son giren ilk çıkar) sırasıyla yönetilmesi durumunda kuyruğun altında kalan bir prosesin hiçbir zaman uyandırılmaması durumudur.
3. **Öncelik Terslenmesi (Priority Inversion):** Yüksek öncelikli bir prosesin ihtiyaç duyduğu bir çekirdek verisini/kilidini daha düşük öncelikli bir prosesin tutması ve bu sırada orta öncelikli başka proseslerin düşük öncelikli prosesi keserek kilidin bırakılmasını geciktirmesi sorunudur. Bu sorun **öncelik mirası protokolü (priority-inheritance protocol)** ile çözülür: Yüksek öncelikli prosesin beklediği kaynağı tutan düşük öncelikli proseslerin önceliği, kaynağı serbest bırakana kadar geçici olarak yüksek öncelikli prosesin seviyesine yükseltilir.

## 7. Klasik Senkronizasyon Problemleri

Literatürde yeni senkronizasyon araçlarını test etmek ve gerçek hayattaki (veritabanı erişimi, bilet satışı, kaynak tahsisi vb.) senkronizasyon kalıplarını modellemek için üç klasik problem tanımlanmıştır.

### 7.1 Sınırlı Tampon Problemi (Bounded-Buffer Problem)

Her biri bir öğe tutabilen $n$ adet tampondan oluşan havuzda üretici ve tüketici proseslerin senkronizasyonu için üç semafor tanımlanır (ekrandan, 01:36:30):

- `semaphore mutex = 1;` — Tampon havuzuna erişimde karşılıklı dışlama (mutual exclusion) sağlar.
- `semaphore full = 0;` — Dolu tampon gözlerinin sayısını tutar (başlangıçta 0).
- `semaphore empty = n;` — Boş tampon gözlerinin sayısını tutar (başlangıçta $n$).

Kritik kesim dışında her zaman $\text{full} + \text{empty} = n$ eşitliği korunur.

- **Üretici Proses Yapısı:**

  ```c
  do {
      /* produce an item in next_produced */

      wait(empty);
      wait(mutex);

      /* add next_produced to the buffer */

      signal(mutex);
      signal(full);
  } while (true);
  ```

- **Tüketici Proses Yapısı:**

  ```c
  do {
      wait(full);
      wait(mutex);

      /* remove an item from buffer to next_consumed */

      signal(mutex);
      signal(empty);

      /* consume the item in next_consumed */
  } while (true);
  ```

### 7.2 Okuyucular-Yazıcılar Problemi (Readers-Writers Problem)

Bir veritabanı veya dosya gibi ortak bir veri kümesi birden fazla eşzamanlı proses tarafından paylaşılmaktadır:

- **Okuyucular (Readers):** Veri kümesini yalnızca okur (`SELECT` gibi), herhangi bir güncelleme yapmaz. Aynı anda birden fazla okuyucunun veriyi okumasında hiçbir sakınca yoktur.
- **Yazıcılar (Writers):** Veri kümesini hem okuyabilir hem değiştirebilir (`INSERT`, `UPDATE`, `DELETE` gibi). Bir yazıcı paylaşılan veriye erişirken başka hiçbir prosesin (ne okuyucu ne de başka bir yazıcı) veriye erişmemesi gerekir.

**Birinci Okuyucular-Yazıcılar Problemi** çözümünde paylaşılan veriler şunlardır (ekrandan, 01:42:30):

- `semaphore rw_mutex = 1;` — Hem yazıcılar arasında karşılıklı dışlama sağlar hem de ilk giren okuyucu ile son çıkan okuyucu tarafından yazıcıları engellemek/serbest bırakmak için kullanılır.
- `semaphore mutex = 1;` — `read_count` değişkeni güncellenirken karşılıklı dışlama sağlar.
- `int read_count = 0;` — O anda veriyi okumakta olan proses sayısını tutar.

**Yazıcı (Writer) Prosesinin Yapısı:**

```c
do {
    wait(rw_mutex);

    /* writing is performed */

    signal(rw_mutex);
} while (true);
```

**Okuyucu (Reader) Prosesinin Yapısı:**

```c
do {
    wait(mutex);
    read_count++;
    if (read_count == 1)
        wait(rw_mutex); /* Ilk okuyucu iceri girerken yazicilari kilitler */
    signal(mutex);

    /* reading is performed */

    wait(mutex);
    read_count--;
    if (read_count == 0)
        signal(rw_mutex); /* Son okuyucu cikarken yazicilarin kilidini acar */
    signal(mutex);
} while (true);
```

Burada içeride en az bir okuyucu bulunduğu sürece sonradan gelen okuyucular `rw_mutex`'i beklemeden doğrudan okumaya katılabilir; bu nedenle birinci varyasyonda yazıcılar açlık (starvation) yaşayabilir. İkinci varyasyonda ise bir yazıcı beklemeye başladığında yeni okuyucu alınmaz (bu kez okuyucular açlık yaşayabilir).

### 7.3 Yemek Yiyen Filozoflar Problemi (Dining-Philosophers Problem)

Yuvarlak bir masanın etrafında 5 filozof oturmakta, ortada bir kâse pirinç pilavı ve her iki filozofun arasında birer adet olmak üzere masada toplam **5 adet yemek çubuğu (`chopstick[5]`)** bulunmaktadır.

- Bir filozof ya **düşünür (`thinking`)** ya da acıktığında **yemek yer (`eating`)**.
- Yemek yiyebilmesi için hem solundaki hem de sağındaki çubuğu (yani **iki çubuğu birden**) eline alması gerekir; tek çubukla yemek yiyemez. Yemeğini bitirdiğinde her iki çubuğu da bırakıp tekrar düşünmeye başlar.

Her çubuk başlangıç değeri `1` olan bir semafor (`semaphore chopstick[5];`) olarak modellendiğinde $i$. filozofun basit yapısı şöyledir:

```c
do {
    wait(chopstick[i]);
    wait(chopstick[(i + 1) % 5]);

    /* eat for a while */

    signal(chopstick[i]);
    signal(chopstick[(i + 1) % 5]);

    /* think for a while */
} while (true);
```

**Deadlock Sorunu:** Bu çözüm iki komşu filozofun aynı anda yemek yemesini engeller; ancak **5 filozofun tamamı aynı anda acıkıp kendi sol/sağ çubuğunu (`chopstick[i]`) alırsa**, tüm `chopstick` semaforları `0` olur. Ardından her filozof ikinci çubuğu (`chopstick[(i + 1) % 5]`) almak istediğinde sonsuza dek bekler ve **kilitlenme (deadlock)** meydana gelir.

**Deadlock Çözüm Yöntemleri:**

1. Masaya aynı anda **en fazla 4 filozofun** oturmasına izin vermek (5 çubuk olduğu için en az 1 filozof iki çubuğu da alabilir).
2. Bir filozofun çubukları yalnızca **her iki çubuk da müsaitse** (kritik kesim içinde kontrol ederek) almasına izin vermek.
3. **Asimetrik çözüm kullanmak:** Tek numaralı filozoflar önce sol, sonra sağ çubuğunu alırken; çift numaralı filozoflar önce sağ, sonra sol çubuğunu alır (veya turlara bölerek bir turda çift numaralıların `{0, 2, 4}` ile tek numaralıların `{1, 3}` sırayla yemesi sağlanır).

## 8. Monitörler (Monitors) ve Koşul Değişkenleri (Condition Variables)

Semaforlarda `wait` ve `signal` işlemlerinin sırasının yanlış yazılması veya unutulması kolaylıkla kilitlenmeye yol açtığından, uygulama geliştiriciler için daha yüksek seviyeli bir dil yapısı olan **monitör (monitor)** geliştirilmiştir (Concurrent Pascal, Mesa, C# ve Java'daki `synchronized` blokları/metotları gibi).

### 8.1 Monitör Yapısı ve Koşul Değişkenleri

Bir **monitör**, paylaşılan değişken bildirimlerini ve bu değişkenler üzerinde çalışan prosedür/fonksiyon gövdelerini tek bir modül içinde toplayan bir **soyut veri tipidir (abstract data type - ADT)**:

```text
monitor monitor_name
{
    /* paylasilan degisken bildirimleri */

    procedure P1 (. . .) {
        . . .
    }

    procedure Pn (. . .) {
        . . .
    }

    initialization_code (. . .) {
        . . .
    }
}
```

Monitör yapısı, **monitör içinde aynı anda yalnızca tek bir prosesin aktif olmasını** kendiliğinden garanti eder; programcının karşılıklı dışlama için açıkça kilit kodlamasına gerek kalmaz.

Özel senkronizasyon koşulları için monitör içinde **`condition x, y;`** biçiminde **koşul değişkenleri (condition variables)** tanımlanır. Bir koşul değişkeni üzerinde yalnızca iki işlem yapılabilir:

- **`x.wait()`:** Bu işlemi çağıran proses, başka bir proses `x.signal()` çağırana kadar askıya alınır (uyutulur).
- **`x.signal()`:** Eğer `x.wait()` ile uyutulmuş prosesler varsa onlardan **yalnızca birini** uyandırır (`resume`). Semaforun `signal()` işleminden farklı olarak, eğer `x` üzerinde bekleyen hiçbir proses yoksa `x.signal()` çağrısının **hiçbir etkisi olmaz** (boşa gider, sayaç artırmaz).

Bir $P$ prosesi `x.signal()` çağırarak bekleyen bir $Q$ prosesini uyandırdığında monitör içinde aynı anda ikisi birden çalışamayacağı için iki yaklaşım vardır:

1. **Signal and wait:** $P$ prosesi ya $Q$ monitörden çıkana kadar ya da başka bir koşulu bekler.
2. **Signal and continue:** $Q$ prosesi, $P$ monitörden çıkana kadar bekler.

### 8.2 Yemek Yiyen Filozofların Monitörle Çözümü

Yemek Yiyen Filozoflar problemi, bir filozofun çubukları yalnızca her iki çubuk da müsaitse alması kuralıyla monitör kullanılarak kilitlenmesiz (deadlock-free) olarak şöyle çözülür:

```c
monitor DiningPhilosophers
{
    enum { THINKING, HUNGRY, EATING } state[5];
    condition self[5];

    void pickup(int i) {
        state[i] = HUNGRY;
        test(i);
        if (state[i] != EATING)
            self[i].wait();
    }

    void putdown(int i) {
        state[i] = THINKING;
        // sol ve sag komsulari kontrol et
        test((i + 4) % 5);
        test((i + 1) % 5);
    }

    void test(int i) {
        if ((state[(i + 4) % 5] != EATING) &&
            (state[i] == HUNGRY) &&
            (state[(i + 1) % 5] != EATING)) {
            state[i] = EATING;
            self[i].signal();
        }
    }

    initialization_code() {
        for (int i = 0; i < 5; i++)
            state[i] = THINKING;
    }
}
```

Her $i$. filozof yemek yemeden önce `DiningPhilosophers.pickup(i);` çağırır, yemeğini yer ve ardından `DiningPhilosophers.putdown(i);` çağırır. Komşularından biri yemek yiyorsa filozof `EATING` durumuna geçemez ve `self[i].wait()` ile bekler; komşusu yemeği bitirip `putdown` yaptığında `test` fonksiyonuyla onu uyandırır. Bu çözümde deadlock oluşmaz (ancak açlık / starvation hâlâ mümkündür).

### 8.3 Semaforlarla Monitör Gerçeklemesi ve Öncelikli Bekleme (`x.wait(c)`)

Monitörler arka planda semaforlar kullanılarak gerçeklenebilir:

- Karşılıklı dışlama için `semaphore mutex = 1;` ve sinyal verip bekleyen proseslerin kendilerini askıya alması için `semaphore next = 0; int next_count = 0;` kullanılır. Her harici `F` prosedürü çağrısında girişte `wait(mutex);`, çıkışta ise `if (next_count > 0) signal(next); else signal(mutex);` çalıştırılır.
- Her `condition x` için `semaphore x_sem = 0; int x_count = 0;` tanımlanır.
- Kuyruktan uyandırılacak prosesi FIFO yerine bir **öncelik numarasına ($c$)** göre seçmek için `x.wait(c);` yapısı kullanılır; `x.signal()` çağrıldığında en küçük $c$ değerine (örneğin kaynağı en kısa süre kullanacak prosese, `ResourceAllocator` monitöründe olduğu gibi) öncelik verilir.

## 9. İşletim Sistemi Örnekleri ve Alternatif Senkronizasyon Yaklaşımları

### 9.1 İşletim Sistemlerinde Senkronizasyon

- **Solaris:** Uyarlanabilir mutex'ler (**adaptive mutexes** — çok işlemcili sistemde kilidi tutan thread çalışır durumdaysa spinlock yapar, uyuyorsa bloklanıp beklemeye geçer), koşul değişkenleri, okuyucu-yazıcı kilitleri ve bekleyen thread'leri sıralayan **turnike (turnstile)** veri yapılarını kullanır.
- **Windows:** Tek işlemcili sistemde çekirdek içinde kesmeleri maskeler, çok işlemcili sistemde **spinlock** kullanır; çekirdek dışında ise mutex, semafor, olay (**event**) ve zamanlayıcı (**timer**) gibi dağıtıcı nesneleri (**dispatcher objects**) sunar.
- **Linux:** 2.6 sürümünden itibaren tamamen kesmeli (preemptive) çekirdeğe sahiptir. En basit senkronizasyon için **atomik tam sayılar (`atomic_t`)**, çok işlemcide **spinlock** ve **semafor**, tek işlemcide ise spinlock yerine **çekirdek kesmesini açma/kapatma (`preempt_disable` / `preempt_enable`)** mekanizmalarını kullanır.
- **Pthreads:** POSIX standardı kapsamında kullanıcı seviyesinde mutex kilitleri (`pthread_mutex_t`), koşul değişkenleri ve okuma-yazma kilitleri sağlar.

### 9.2 Alternatif Yaklaşımlar

Çok çekirdekli sistemlerin yaygınlaşmasıyla kilit tabanlı programlamanın zorluklarını aşmak için üç alternatif yaklaşım öne çıkmıştır:

1. **İşlemsel Bellek (Transactional Memory):** Bellekten okuma ve yazma dizilerini tek bir atomik işlem (`atomic { /* read/write memory */ }`) olarak yürüten yazılımsal (STM) veya donanımsal (HTM) yaklaşımdır; açık kilit kullanımını ortadan kaldırır.
2. **OpenMP:** `#pragma omp critical` derleyici direktifi altında kalan kod bölgesini kritik kesim olarak işaretler ve aynı anda yalnız bir thread'in girmesini sağlar:

   ```c
   void update(int value) {
       #pragma omp critical
       {
           count += value;
       }
   }
   ```

3. **Fonksiyonel Programlama Dilleri:** Erlang ve Scala gibi fonksiyonel dillerde değişken durumlar (mutable state) yerine değiştirilemez veriler kullanıldığı için yarış durumu ve kilit ihtiyacı temelinden önlenir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:16:30)

Başlangıç değeri `counter = 5` olan ortak bir değişkene üretici proses `counter++` ve tüketici proses `counter--` işlemi uygulamaktadır. Makine dilinde bu işlemlerin üçer komutla (`register = counter`, `register = register +/- 1`, `counter = register`) gerçeklendiğini varsayarak, her iki işlem tamamlandığında `counter` değişkeninin `5` yerine `4` veya `6` değerini almasına yol açan komut serpiştirmesini (interleaving) gösteriniz. Bu duruma ne ad verilir?

**Çözüm (derste verildi):**

- Bu duruma **yarış durumu (race condition)** denir.
- `S0:` Üretici `register1 = counter` çalıştırır (`register1 = 5`).
- `S1:` Üretici `register1 = register1 + 1` çalıştırır (`register1 = 6`).
- `S2:` Tüketici `register2 = counter` çalıştırır (`register2 = 5`).
- `S3:` Tüketici `register2 = register2 - 1` çalıştırır (`register2 = 4`).
- Eğer önce üretici `counter = register1` (`counter = 6`), sonra tüketici `counter = register2` (`counter = 4`) çalıştırırsa sonuç **`4`** olur; tersi sırada yazılırsa sonuç **`6`** olur.

### Soru 2 (ekrandan, 01:21:30; derste sözlü, 01:21:00–01:23:12)

Başlangıç değeri `0` olan ortak bir `synch` semaforu (`synch = 0`) tanımlanmıştır. Eşzamanlı çalışan $P_1$ ve $P_2$ proseslerinin kodları aşağıda verilmiştir:

- **$P_1$ Prosesi:**
  ```c
  printf("1");
  signal(synch);
  ```
- **$P_2$ Prosesi:**
  ```c
  wait(synch);
  printf("2");
  ```

Bu iki proses çalıştırıldığında ekranda `12`, `21` veya başka bir çıktı görülme olasılıkları nelerdir? Neden?

**Çözüm (derste verildi):**

Ekranda **her zaman yalnızca `12`** çıktısı görülür (`21` görülmesi imkânsızdır). Çünkü işlemci önce $P_2$'ye verilse bile başlangıçta `synch = 0` olduğu için $P_2$ `wait(synch)` içindeki `while (synch <= 0);` koşulunda beklemeye takılır ve `printf("2")` satırına geçemez. Ancak $P_1$ çalışıp önce ekrana `1` bastıktan ve `signal(synch)` ile `synch` değerini `1`'e yükselttikten sonra $P_2$ beklemeyi aşarak `2` yazdırabilir.

### Soru 3 (ekrandan, 01:31:30)

Başlangıç değerleri $S = 1$ ve $Q = 1$ olan iki semaforu kullanan $P_0$ ve $P_1$ prosesleri aşağıda verilmiştir:

```text
P0:                  P1:
wait(S);             wait(Q);
wait(Q);             wait(S);
  ...                  ...
signal(S);           signal(Q);
signal(Q);           signal(S);
```

Bu kod yapısında hangi problem ortaya çıkabilir ve hangi yürütme sırasıyla gerçekleşir?

**Çözüm (derste verildi):**

Bu yapıda **kilitlenme (deadlock)** problemi ortaya çıkabilir. $P_0$ prosesi `wait(S);` çalıştırıp $S = 0$ yaptıktan hemen sonra zamanlayıcı işlemciyi $P_1$'e verirse ve $P_1$ de `wait(Q);` çalıştırıp $Q = 0$ yaparsa; bir sonraki adımda $P_0$ `wait(Q)` satırında ($Q = 0$ olduğu için), $P_1$ ise `wait(S)` satırında ($S = 0$ olduğu için) sonsuza dek birbirini bekler ve hiçbir zaman `signal` satırlarına ulaşamaz.

## Dersin Toparlaması

Bu derste eşzamanlı çalışan proses ve thread'lerin ortak kaynaklara erişirken veri tutarlılığını nasıl koruyacağı (**Proses Senkronizasyonu**) incelenmiştir. Makine komut döngüsü ve yarış durumu (race condition) tanımlanmış; kritik kesim probleminin üç temel koşulu (karşılıklı dışlama, ilerleme, sınırlı bekleme), iki proseslik yazılımsal Peterson çözümü, çok işlemcili sistemlerde atomik donanım komutları (`test_and_set` ve `compare_and_swap`), mutex kilitleri ve spinlock yapısı, Dijkstra'nın semaforları ($P$/`wait` ve $V$/`signal`, sayma ve ikili semaforlar, `block`/`wakeup` ile meşgul beklemesiz gerçekleme), klasik senkronizasyon problemleri (Sınırlı Tampon, Okuyucular-Yazıcılar, Yemek Yiyen Filozoflar), üst seviye monitör ve koşul değişkeni yapıları ile Solaris, Windows, Linux ve Pthreads gerçeklemeleri ele alınmıştır. Bir sonraki derste bu senkronizasyon araçlarının C ve Pthreads ile uygulamalı örnekleri yapılacak ve kilitlenme (deadlock) konusuna geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
