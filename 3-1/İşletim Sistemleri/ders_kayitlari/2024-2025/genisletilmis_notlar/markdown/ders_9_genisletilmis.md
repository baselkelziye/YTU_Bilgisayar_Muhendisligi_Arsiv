# Ders 9 Genişletilmiş Notu: İşlemci Zamanlama (CPU Scheduling): FCFS, SJF, SRTF, Öncelikli Zamanlama, Round Robin, Çok İşlemcili ve Gerçek Zamanlı Zamanlama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ebeveyn-Çocuk Proses İlişkisi, Zombi ve Yetim (Orphan) Prosesler
- 2. İşlemci Zamanlama (CPU Scheduling) Temel Kavramları
- 3. Zamanlama Kriterleri (Scheduling Criteria)
- 4. Temel Zamanlama Algoritmaları: FCFS, SJF, SRTF, Priority ve Round Robin
- 5. Çok Seviyeli Kuyruk ve Çok Seviyeli Geri Bildirimli Kuyruk
- 6. İş Parçacığı Zamanlama (Thread Scheduling)
- 7. Çok İşlemcili Zamanlama (Multiple-Processor Scheduling)
- 8. Gerçek Zamanlı İşlemci Zamanlama (Real-Time CPU Scheduling)
- 9. İşletim Sistemi Örnekleri: Linux, Windows ve Solaris Zamanlayıcıları
- 10. Algoritma Değerlendirme Yöntemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Ebeveyn-Çocuk Proses İlişkisi, Zombi ve Yetim (Orphan) Prosesler

### 1.1 `fork()` ve `wait()` Kullanımında Ebeveyn-Çocuk Sıralaması

Derse başlamadan önce hoca, önceki uygulama derslerinin birinde teorik anlatımla çelişebilecek şekilde ifade edilen bir noktayı açıklığa kavuşturdu. Bir proseste `fork()` sistem çağrısı yapıldığında, o ana kadar hesaplanmış değişken değerleriyle birlikte prosesin bire bir kopyası bellekte başka bir bölgeye yerleştirilir ve birbirinden bağımsız iki proses (ebeveyn / `parent` ve çocuk / `child`) oluşur. Normal şartlarda zamanlayıcının (scheduler) hangisini önce çalıştıracağı ve hangisinin önce biteceği öngörülemez; çocuk proses ebeveyne bilgi vermeden tek başına da sonlanabilir.

Ancak uygulama dersinde sehven kullanılan "önce parent işini bitirir, sonra child işini bitirir" ifadesi genel bir kural olarak **yanlıştır** (ancak özel `if` koşullarıyla böyle bir senaryo zorlanırsa gerçekleşebilir ki bu da rutin kullanımın dışındadır). Standart ve sağlıklı ebeveyn-çocuk ilişkisinde **ebeveyn proses her zaman çocuk prosesten sonra sonlanmalıdır**:

```text
Ebeveyn (Parent) Proses                   Çocuk (Child) Proses
-----------------------                   --------------------
pid = fork(); --------------------------> Çocuk çalışmaya başlar
   |                                         | (görevini yürütür)
wait(&status); (Beklemeye geçer)             |
   |                                      exit(0); (Durum bilgisi gönderir)
   |<----------------------------------------+
(Çocuğun PID ve çıkış kodunu alır)
   |
Ebeveyn sonlanır
```

Normal kullanımda ebeveyn proses `wait()` sistem çağrısıyla çocuğun tamamlanmasını bekler; çocuk proses görevini tamamladığında `return 0` veya `exit(0)` ile çıkış durumunu (status) gönderir, `wait()` çağrısı hangi çocuk PID'sinden hangi durum bilgisinin geldiğini yakalar ve ebeveyn proses bundan sonra sonlanma aşamasına geçer.

### 1.2 Prosesler (`fork`) ile İş Parçacıkları (`thread`) Arasındaki Bellek Farkı

Thread'ler aynı proses kimliği (PID) ve aynı bellek uzayı altındaki farklı yürütme akışlarıdır (execution flows); dolayısıyla tek bir global `x` değişkenini doğrudan paylaşırlar ve ayrıca bir "thread'ler arası haberleşme" mekanizmasına ihtiyaç duymazlar.

Buna karşılık bir C programında `int x = 5;` tanımlanıp `fork()` çağrıldığında hem ebeveyn proseste hem de çocuk proseste `x = 5` bulunur; ancak bunlar **iki farklı bellek uzayındaki iki bağımsız `x` değişkenidir**. Bir prosesin kendi `x` değişkenini artırması veya azaltması diğer prosesin `x` değişkenini etkilemez.

`fork()` dönüş değerine göre program ayrıştırma (program differentiation) yapısı şöyledir:

- `fork() > 0`: Başarılı işlem; **ebeveyn (parent)** proses içindeyizdir (dönen değer çocuğun PID'sidir).
- `fork() == 0`: **Çocuk (child)** proses içindeyizdir.
- `fork() < 0`: Hatalı işlem; yeni proses oluşturulamamıştır.

### 1.3 İç İçe `fork()` Çıktı Analizi (`Ex_4_fork4.c`)

Hoca ekranda (ekrandan, 00:11:30) aşağıdaki C kodunu açarak olası ekran çıktılarını analiz etti (`gcc -Wall` ile derlenip doğrulanmıştır):

```c
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("0 \n");
    if (fork()) {
        if (!fork()) {
            fork();
            printf("1 \n");
        } else {
            printf("2 \n");
        }
    } else {
        printf("3 \n");
    }
    printf("4 \n");
    return 0;
}
```

Adım adım yürütme ağacı ve çıktı analizi:

1. **`printf("0 \n");`:** Henüz hiçbir `fork()` çağrılmadan önce çalıştığı için bu satır yalnızca ana proses tarafından yürütülür. Dolayısıyla çıktı **kesinlikle `0` ile başlamalıdır** ve ekranda yalnızca **bir tane `0`** görülür.
2. **Birinci `if (fork())`:** Ana proses ($P_0$) bir çocuk ($C_1$) oluşturur:
   - Çocuk proses ($C_1$) için `fork()` `0` döndürür; `if` koşulu yanlış olduğundan `else` bloğuna gider, ekrana **`3`** ve ardından **`4`** basıp sonlanır.
   - Ebeveyn proses ($P_0$) için `fork()` pozitif bir PID (örneğin `500`) döndürür; `if` bloğunun içine girer.
3. **İkinci `if (!fork())`:** Ebeveyn proses ($P_0$) ikinci bir çocuk ($C_2$) oluşturur:
   - Ebeveyn ($P_0$) için `fork()` pozitif bir değer döndürür; C dilinde sıfırdan farklı bir sayının mantıksal değili (`!500`) `0` olduğundan ebeveyn `else` bloğuna düşer, ekrana **`2`** ve ardından **`4`** basıp sonlanır.
   - İkinci çocuk ($C_2$) için `fork()` `0` döndürür; `!0` değeri `1` (doğru) olduğundan `if (!fork())` bloğunun içine girer.
4. **Üçüncü `fork();` ve `printf("1 \n");`:** İkinci çocuk ($C_2$) bir `fork()` daha yaparak kendi çocuğunu ($C_3$, yani ana prosesin torununu) oluşturur. Hem $C_2$ hem de $C_3$ bir alt satırdaki `printf("1 \n");` ve blok dışındaki `printf("4 \n");` satırlarını çalıştırır; böylece ekrana **iki adet `1`** ve iki adet daha `4` basılır.

Sonuç olarak ekranda hangi sırayla basılacağı işletim sistemi zamanlayıcısına bağlı olmakla birlikte:

- İlk satır mutlaka `0` olur,
- Toplamda bir adet `0`, iki adet `1`, bir adet `2`, bir adet `3` ve dört adet `4` basılır (örnek bir geçerli çıktı: `0, 2, 4, 3, 4, 1, 4, 1, 4`).

### 1.4 Zombi, Yetim (Orphan) ve Çoklu `wait()` Kod Örnekleri

Hoca uygulama klasöründeki üç önemli durumu kod üzerinde gösterdi:

1. **Zombi (Zombie) Proses (`Ex_8_zombie1.c`, ekrandan, 00:13:50):**

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>

   int main(void) {
       if (fork()) { // Parent
           printf("Running parent, pid : %i\n", getpid());
           while (1);
       } else {      // Child
           printf("Terminating child, pid : %i\n", getpid());
           exit(0);
       }
       exit(0);
   }
   ```

   Çocuk proses `exit(0)` ile sonlanmıştır; ancak ebeveyn proses `while(1);` içinde çalışmaya devam etmekte ve `wait()` çağırmamaktadır. Ebeveyne "ben tamamlandım" bilgisi teslim edilemediği için çocuk proses bellekteki yürütmesini bitirmiş olsa bile işletim sisteminin proses listesinde (`ps` çıktısında) PID'siyle birlikte varlığını sürdürür. Ölmüş ama proses tablosunda hâlâ görünen bu prosese **zombi (zombie) proses** denir.

2. **Yetim (Orphan) Proses (`Ex_9_zombie2.c`, ekrandan, 00:14:40):**

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>

   int main(void) {
       if (fork()) { // Parent
           printf("Running parent, pid : %i\n", getpid());
           exit(0);
       } else {      // Child
           printf("Terminating child, pid : %i\n", getpid());
           while (1);
       }
       exit(0);
   }
   ```

   Burada ebeveyn proses `exit(0)` ile hemen sonlanırken çocuk proses `while(1);` sonsuz döngüsü içinde yaşamaya devam eder. Ebeveyni ölmüş ama kendisi çalışmaya devam eden bu prosese **yetim (orphan) proses** denir; işletim sisteminde `init` prosesi tarafından evlat edinilir.

3. **Çoklu Çocuk Proseste `wait()` ve Fazladan Bekleme (`Ex_11_wait2.c`, ekrandan, 00:16:30):**

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <sys/types.h>
   #include <sys/wait.h>

   #define numOfChilds 5

   int main(void) {
       int i;
       int child_status;
       pid_t pid[numOfChilds];
       pid_t wpid;

       for (i = 0; i < numOfChilds; i++) {
           if ((pid[i] = fork()) == 0) {
               exit(100 + i); // create & exit child
           }
       }

       for (i = 0; i < numOfChilds + 1; i++) {
           wpid = wait(&child_status); // wait for child
           if (WIFEXITED(child_status)) { // check exit status
               printf("Child %d terminated with exit status %d\n",
                      wpid, WEXITSTATUS(child_status));
           } else {
               printf("Child %d terminate abnormally\n", wpid);
           }
       }
       exit(0);
   }
   ```

   İlk döngüde 5 çocuk proses oluşturulur ve her biri `exit(100 + i)` ile (`100`, `101`, `102`, `103`, `104` durum kodlarıyla) sonlanır. İkinci döngü ise `numOfChilds + 1` (yani 6) kez `wait(&child_status)` çağırır:
   - İlk 5 çağrıda çocukların sonlanma sırasına göre (zamanlayıcıya bağlı olarak örneğin `100, 101, 102, 103, 104` veya `100, 102, ...`) gerçek PID'leri ve çıkış durumları yakalanıp yazdırılır.
   - 6. çağrıda ise bekleyecek başka çocuk proses kalmadığı için `wait()` hata olarak `wpid = -1` döndürür ve `child_status` değişkenini değiştirmez. `child_status` içinde en son sonlanan (5.) çocuğun çıkış kodu (`104`) saklı kaldığından ekrana 6. satır olarak `Child -1 terminated with exit status 104` yazdırılır.

## 2. İşlemci Zamanlama (CPU Scheduling) Temel Kavramları

### 2.1 CPU–G/Ç Patlama Döngüsü (CPU–I/O Burst Cycle)

Çoklu programlamanın (multiprogramming) temel amacı işlemci kullanım oranını (CPU utilization) maksimize etmektir. Bir prosesin yürütülmesi, birbirini izleyen bir **CPU patlaması (CPU burst — işlemcide komut yürütme)** ve bir **G/Ç beklemesi (I/O burst — G/Ç tamamlanmasını bekleme)** döngüsünden oluşur:

```text
[CPU burst] (load, add, store...)
     |
     v
[I/O burst] (read from file / wait for I/O)
     |
     v
[CPU burst] (increment, write...)
     |
     v
[I/O burst] ... ---> Son CPU burst ile proses sonlanır
```

Bir proses G/Ç beklemesine (I/O burst) geçtiğinde işlemciden çıkarılır; bu bekleme aralığında işlemcinin hangi prosese verileceğine karar verme işlemine **proses zamanlama (process scheduling / CPU scheduling)** denir.

> **Hocanın vurgusu:** Zombi ve yetim proseslerle sıkça karıştırılan bir diğer kavram **daemon** proseslerdir. Daemon'lar (örneğin yazıcı/yazdırma servisi), arka planda sürekli bekleyen, önceliği nispeten düşük olan ve yalnızca ilgili olay/ihtiyaç doğduğunda aktif hale gelip işini yaptıktan sonra tekrar arka plana dönen servis prosesleridir.

CPU burst sürelerinin dağılımı (frekans histogramı) incelendiğinde, proseslerin çok büyük çoğunluğunun çok kısa süreli CPU patlamaları (örneğin 1–3 milisaniye) yaptığı, çok az sayıda prosesin ise uzun CPU patlamalarına sahip olduğu görülür.

### 2.2 CPU Zamanlayıcı (CPU Scheduler) ve Kesmeli/Kesmesiz Zamanlama

Bellekte çalışmaya hazır halde bekleyen (`ready` durumundaki) prosesler **hazır kuyruğunda (ready queue)** tutulur. Hazır kuyruğundaki proseslerden birini seçip işlemciyi ona tahsis eden işletim sistemi bileşenine **kısa vadeli zamanlayıcı (short-term scheduler)** veya **CPU zamanlayıcı (CPU scheduler)** denir. Hazır kuyruğu mutlaka ilk giren ilk çıkar (FIFO) yapısında olmak zorunda değildir; öncelikli kuyruk (priority queue), ağaç veya sıradan bağlantılı liste olarak gerçeklenebilir.

Beş durumlu proses durum diyagramında CPU zamanlama kararları şu **dört durumda** gündeme gelir:

1. Bir proses çalışır durumdan (`running`) bekleme durumuna (`waiting`) geçtiğinde (örneğin G/Ç isteği veya `wait()` çağrısı),
2. Bir proses çalışır durumdan (`running`) hazır durumuna (`ready`) geçtiğinde (örneğin zaman dilimi dolup kesme geldiğinde),
3. Bir proses bekleme durumundan (`waiting`) hazır durumuna (`ready`) geçtiğinde (örneğin G/Ç tamamlandığında),
4. Bir proses sonlandığında (`terminate`).

Bu dört duruma göre iki temel zamanlama rejimi tanımlanır:

- **Kesmesiz Zamanlama (Nonpreemptive / Cooperative Scheduling):** Zamanlama yalnızca **1. ve 4. durumlarda** yapılır. Bir proses işlemciyi bir kez aldığında, kendi isteğiyle G/Ç beklemesine geçene veya sonlanana kadar işlemciyi bırakmaz; işlemci zorla elinden alınamaz (örneğin bir yazıcının tahsis edildiğinde belgenin tamamı basılana kadar başka işe verilmemesi gibi).
- **Kesmeli Zamanlama (Preemptive Scheduling):** **2. ve 3. durumlarda da** zamanlama yapılır; yani çalışmakta olan bir prosesin süresi dolduğunda veya daha yüksek öncelikli bir proses hazır kuyruğuna girdiğinde işlemci çalışan prosesin elinden alınabilir. Günümüzdeki modern işletim sistemlerinin tamamı zaman paylaşımlı olduğundan kesmeli (preemptive) zamanlama kullanır.

Kesmeli zamanlama şu tasarım sorunlarına dikkat edilmesini gerektirir:

- **Paylaşılan veriye erişim:** Bir proses paylaşılan bir veriyi güncellerken yarıda kesilir ve ikinci proses aynı veriyi okumaya/değiştirmeye kalkarsa tutarsızlık (yarış durumu / race condition) doğar.
- **Çekirdek modunda kesilme:** Çekirdek (kernel) bir sistem çağrısını yürütürken çekirdek veri yapılarını değiştiriyor olabilir; bu sırada kesilmesinin etkileri gözetilmelidir.
- **Kritik işletim sistemi aktiviteleri:** Kesme işleme gibi kritik çekirdek kodları çalışırken kesmelerin geçici olarak devre dışı bırakılması gerekebilir.

### 2.3 Dağıtıcı (Dispatcher) ve Dağıtım Gecikmesi (Dispatch Latency)

**Dağıtıcı (dispatcher)** module, kısa vadeli zamanlayıcı (CPU scheduler) tarafından seçilen prosese CPU'nun fiziksel kontrolünü veren modüldür. Üç temel görevi vardır:

1. **Bağlam değiştirme (switching context):** Çıkarılan prosesin durumunu PCB'ye kaydedip yeni prosesin PCB'sini yüklemek.
2. **Kullanıcı moduna geçme (switching to user mode).**
3. Kullanıcı programını yeniden başlatmak için program sayacının (PC) gösterdiği **uygun konuma atlama (jumping to the proper location)**.

Dağıtıcının bir prosesi durdurup diğer prosesi çalışmaya başlatması için geçen süreye **dağıtım gecikmesi (dispatch latency)** denir; bu sürenin olabildiğince kısa olması gerekir.

## 3. Zamanlama Kriterleri (Scheduling Criteria)

Farklı işlemci zamanlama algoritmalarını karşılaştırmak için beş temel performans ölçütü (kriteri) kullanılır:

1. **CPU Kullanımı (CPU Utilization — Maksimize edilir):** İşlemcinin mümkün olduğunca dolu/meşgul tutulmasıdır (boşta kalma süresinin en aza indirilmesi).
2. **İş Çıkarma Oranı / Verim (Throughput — Maksimize edilir):** Birim zamanda (örneğin saniye başına) yürütmesi tamamlanan proses sayısıdır.
3. **Dönüş Süresi (Turnaround Time — Minimize edilir):** Belirli bir prosesin sisteme girişinden (hazır kuyruğuna gelişinden) tamamlanıp çıkmasına kadar geçen toplam süredir (kuyrukta bekleme süreleri $+$ CPU'da çalışma süresi $+$ G/Ç süresi).
4. **Bekleme Süresi (Waiting Time — Minimize edilir):** Bir prosesin **hazır kuyruğunda (ready queue)** işlemci sırası beklerken geçirdiği sürelerin **toplamıdır**. (Bir proses işlemciye girip çıktıktan sonra tekrar hazır kuyruğuna dönerse tüm bekleyişleri toplanır).
5. **Yanıt Süresi (Response Time — Minimize edilir):** Etkileşimli bir sistemde bir isteğin gönderildiği andan **ilk yanıtın üretilmesine** (sonucun tamamlanmasına değil, ilk tepkinin verilmesine) kadar geçen süredir (bir anlamda ilk bekleme süresidir).

**Optimizasyon hedefleri:** CPU kullanımı ve throughput **maksimize** edilirken; turnaround time, waiting time ve response time **minimize** edilmeye çalışılır.

## 4. Temel Zamanlama Algoritmaları: FCFS, SJF, SRTF, Priority ve Round Robin

### 4.1 İlk Gelen İlk Hizmet Alır (First-Come, First-Served - FCFS)

En basit zamanlama algoritmasıdır; hazır kuyruğuna ilk gelen proses işlemciyi ilk alır (FIFO kuyruğu). **Kesmesizdir (nonpreemptive)**; işlemciyi alan proses CPU burst süresini tamamlayana kadar işlemcide kalır.

#### Sayısal Örnek 1 (Geliş Sırası: $P_1, P_2, P_3$)

$t = 0$ anında üç prosesin çok küçük farklarla $P_1, P_2, P_3$ sırasıyla hazır kuyruğuna girdiğini varsayalım (ekrandan, 00:33:30):

| Proses | Burst Time (CPU Patlama Süresi) |
|---|---|
| $P_1$ | 24 |
| $P_2$ | 3 |
| $P_3$ | 3 |

Gantt şeması:

```text
+------------------------------------------------+------+------+
|                       P1                       |  P2  |  P3  |
+------------------------------------------------+------+------+
0                                                24     27     30
```

- **Bekleme süreleri:** $P_1 = 0$, $P_2 = 24$, $P_3 = 27$.
- **Ortalama bekleme süresi (Average waiting time):**
  $$\frac{0 + 24 + 27}{3} = \frac{51}{3} = 17\text{ birim zaman}$$

#### Sayısal Örnek 2 (Geliş Sırası: $P_2, P_3, P_1$)

Aynı prosesler kuyruğa $P_2, P_3, P_1$ sırasıyla girmiş olsaydı Gantt şeması şöyle olurdu:

```text
+------+------+------------------------------------------------+
|  P2  |  P3  |                       P1                       |
+------+------+------------------------------------------------+
0      3      6                                                30
```

- **Bekleme süreleri:** $P_1 = 6$, $P_2 = 0$, $P_3 = 3$.
- **Ortalama bekleme süresi:**
  $$\frac{6 + 0 + 3}{3} = \frac{9}{3} = 3\text{ birim zaman}$$

Görüldüğü üzere FCFS algoritmasında ortalama bekleme süresi proseslerin geliş sırasına aşırı duyarlıdır (17'den 3'e düşmüştür).

#### Konvoy Etkisi (Convoy Effect)

Uzun CPU burst süresine sahip bir **CPU-bound** proses (örneğin $P_1 = 24$) işlemciyi aldığında, kısa CPU burst süresine sahip tüm **I/O-bound** prosesler ($P_2, P_3$) tıpkı tek şeritli yolda yavaş giden bir tırın arkasına takılan otomobiller gibi hazır kuyruğunda birikir. Kısa prosesler G/Ç yapıp tekrar hazır kuyruğuna döndüklerinde yine uzun prosesin arkasında beklemek zorunda kalır. Bu duruma **konvoy etkisi (convoy effect)** denir ve hem CPU hem de aygıt kullanım verimliliğini düşürür.

### 4.2 En Kısa İş Önce (SJF) ve En Kısa Kalan Süre Önce (SRTF)

Market kasasında az sayıda ürünü olan müşteriye öncelik verilmesine benzer biçimde, **En Kısa İş Önce (Shortest-Job-First - SJF)** algoritması her prosesi **bir sonraki CPU burst süresinin uzunluğuyla** ilişkilendirir ve işlemciyi en kısa CPU burst süresine sahip prosese verir.

- SJF, verilen bir proses kümesi için **minimum ortalama bekleme süresini verdiği kanıtlanmış optimal algoritmadır**.
- Temel zorluğu, bir prosesin **bir sonraki CPU burst süresinin önceden kesin olarak bilinememesidir**.

#### Kesmesiz (Nonpreemptive) SJF Sayısal Örneği

$t = 0$ anında hazır kuyruğunda bulunan dört prosesin CPU burst süreleri aşağıda verilmiştir (ekrandan, 00:39:15):

| Proses | Burst Time |
|---|---|
| $P_1$ | 6 |
| $P_2$ | 8 |
| $P_3$ | 7 |
| $P_4$ | 3 |

Öncelikli kuyruk en kısa işten en uzuna doğru $P_4 (3) \to P_1 (6) \to P_3 (7) \to P_2 (8)$ şeklinde sıralanır. Gantt şeması:

```text
+------+------------+--------------+----------------+
|  P4  |     P1     |      P3      |       P2       |
+------+------------+--------------+----------------+
0      3            9              16               24
```

- **Bekleme süreleri:** $P_1 = 3$, $P_2 = 16$, $P_3 = 9$, $P_4 = 0$.
- **Ortalama bekleme süresi:**
  $$\frac{3 + 16 + 9 + 0}{4} = \frac{28}{4} = 7\text{ birim zaman}$$

#### Bir Sonraki CPU Burst Süresinin Tahmini (Üstel Ortalama)

Bir sonraki CPU burst süresi kesin olarak bilinemeyeceği için geçmişteki gerçek CPU burst sürelerinden **üstel ortalama (exponential averaging)** yöntemiyle tahmin edilir (ekrandan, 00:40:45):

- $t_n$: $n$. CPU patlamasının **gerçekleşen (actual)** uzunluğu,
- $\tau_{n+1}$: Bir sonraki ($(n+1)$.) CPU patlaması için **tahmin edilen (predicted)** değer,
- $\alpha$: $0 \le \alpha \le 1$ aralığında ağırlık katsayısı (genellikle $\alpha = \frac{1}{2}$ seçilir).

Tahmin formülü:

$$\tau_{n+1} = \alpha t_n + (1 - \alpha)\tau_n$$

> **Ders sonrası not:** Slaytta (ekrandan, 00:40:45) 4. maddede baskı hatası olarak $\tau_{n=1}$ yazılmıştır; hoca derste (00:40:48) bunun dizgi hatası olduğunu ve doğrusunun $\tau_{n+1} = \alpha t_n + (1 - \alpha)\tau_n$ olduğunu özellikle vurgulayarak düzeltmiştir.

Özel durumlar:

- **$\alpha = 0$ ise:** $\tau_{n+1} = \tau_n$ olur; son gerçekleşen CPU burst süresi ($t_n$) dikkate alınmaz, geçmiş tahmin aynen korunur.
- **$\alpha = 1$ ise:** $\tau_{n+1} = t_n$ olur; önceki tahmin geçmişi tamamen unutulur, yalnızca en son gerçekleşen CPU burst süresi esas alınır.
- Formül geriye doğru açıldığında ($\tau_n$ yerine $\alpha t_{n-1} + (1-\alpha)\tau_{n-1}$ yazıldığında) daha eski ölçümlerin ağırlığının $(1-\alpha)^j$ çarpanıyla üstel olarak azaldığı görülür. Hoca, tahmin formülünü aşırı karmaşıklaştırmanın işletim sistemine ek hesaplama yükü getireceğini hatırlattı.

#### Kesmeli SJF: En Kısa Kalan Süre Önce (Shortest-Remaining-Time-First - SRTF)

SJF algoritmasının kesmeli (preemptive) versiyonuna **Shortest-Remaining-Time-First (SRTF)** denir. Hazır kuyruğuna yeni bir proses geldiğinde, yeni prosesin CPU burst süresi o sırada çalışmakta olan prosesin **kalan (remaining)** süresinden daha kısaysa çalışan proses kesilir ve işlemci yeni prosese verilir.

Slayttaki SRTF sayısal örneği (ekrandan, 00:46:40):

| Proses | Varış Zamanı (Arrival Time) | Patlama Süresi (Burst Time) |
|---|---|---|
| $P_1$ | 0 | 8 |
| $P_2$ | 1 | 4 |
| $P_3$ | 2 | 9 |
| $P_4$ | 3 | 5 |

Adım adım zaman analizi:

- **$t = 0$:** Kuyrukta yalnızca $P_1$ (kalan: 8) vardır; $P_1$ işlemciye alınır ve $t=1$'e kadar 1 birim çalışır.
- **$t = 1$:** $P_2$ gelir. Kalan süreler: $P_1 = 7$, $P_2 = 4$. $4 < 7$ olduğundan $P_1$ kesilir ve $P_2$ işlemciye alınır.
- **$t = 2$:** $P_3$ gelir. Kalan süreler: $P_1 = 7$, $P_2 = 3$, $P_3 = 9$. En kısa kalan süre $P_2$ (3) olduğundan $P_2$ devam eder.
- **$t = 3$:** $P_4$ gelir. Kalan süreler: $P_1 = 7$, $P_2 = 2$, $P_3 = 9$, $P_4 = 5$. En kısa kalan süre $P_2$ (2) olduğundan $P_2$ devam eder.
- **$t = 5$:** $P_2$ tamamlanır (kalan: 0). Kuyruktaki proseslerin kalan süreleri: $P_1 = 7$, $P_3 = 9$, $P_4 = 5$. En kısa kalan süre $P_4$ (5) olduğundan $P_4$ işlemciye alınır ve $t=10$'a kadar çalışıp biter.
- **$t = 10$:** Kalan süreler: $P_1 = 7$, $P_3 = 9$. $P_1$ seçilir ve $t=17$'ye kadar çalışıp biter.
- **$t = 17$:** Son kalan $P_3$ (9 birim) çalışır ve $t=26$'da tamamlanır.

Gantt şeması:

```text
+----+--------+----------+--------------+------------------+
| P1 |   P2   |    P4    |      P1      |        P3        |
+----+--------+----------+--------------+------------------+
0    1        5          10             17                 26
```

Her prosesin toplam bekleme süresi:

- **$P_1$:** $t=0$'da geldi ve hemen girdi ($0 - 0 = 0$); $t=1$'de çıkarılıp $t=10$'a kadar bekledi ($10 - 1 = 9$) $\implies \text{Toplam} = 9\text{ ms}$.
- **$P_2$:** $t=1$'de geldi ve $t=1$'de girdi $\implies 1 - 1 = 0\text{ ms}$.
- **$P_3$:** $t=2$'de geldi ve $t=17$'de girdi $\implies 17 - 2 = 15\text{ ms}$.
- **$P_4$:** $t=3$'te geldi ve $t=5$'te girdi $\implies 5 - 3 = 2\text{ ms}$.

**Ortalama bekleme süresi:**

$$\frac{(10 - 1) + (1 - 1) + (17 - 2) + (5 - 3)}{4} = \frac{9 + 0 + 15 + 2}{4} = \frac{26}{4} = 6.5\text{ ms}$$

### 4.3 Öncelikli Zamanlama (Priority Scheduling)

Her prosese bir tam sayı **öncelik değeri (priority number)** atanır ve işlemci en yüksek önceliğe sahip prosese tahsis edilir (kitapta ve slaytlarda **en küçük tam sayı en yüksek önceliği** temsil eder).

- Kesmeli (preemptive) veya kesmesiz (nonpreemptive) olarak çalıştırılabilir.
- **SJF algoritması da aslında bir öncelikli zamanlama algoritmasıdır:** Öncelik değeri, tahmin edilen bir sonraki CPU burst süresinin tersidir (süre ne kadar kısaysa öncelik o kadar yüksektir).
- **Temel problem — Açlık (Starvation / Indefinite Blocking):** Düşük öncelikli prosesler, sisteme sürekli daha yüksek öncelikli prosesler geldiği sürece işlemciyi hiçbir zaman alamayabilir.
- **Çözüm — Yaşlandırma (Aging):** Sistemde uzun süre bekleyen proseslerin öncelik değerinin zaman geçtikçe kademeli olarak artırılmasıdır (örneğin öncelik numarasının 5'ten 4'e, 3'e, 1'e çekilmesi).

#### Öncelikli Zamanlama Sayısal Örneği

$t = 0$ anında hazır bulunan beş prosesin CPU burst süreleri ve öncelikleri aşağıda verilmiştir (ekrandan, 00:50:15):

| Proses | Burst Time | Priority (1 = En Yüksek) |
|---|---|---|
| $P_1$ | 10 | 3 |
| $P_2$ | 1 | 1 |
| $P_3$ | 2 | 4 |
| $P_4$ | 1 | 5 |
| $P_5$ | 5 | 2 |

Öncelik sırasına göre ($P_2 \to P_5 \to P_1 \to P_3 \to P_4$) Gantt şeması:

```text
+----+----------+--------------------+----+----+
| P2 |    P5    |         P1         | P3 | P4 |
+----+----------+--------------------+----+----+
0    1          6                    16   18   19
```

- **Bekleme süreleri:** $P_2 = 0$, $P_5 = 1$, $P_1 = 6$, $P_3 = 16$, $P_4 = 18$.
- **Ortalama bekleme süresi:**
  $$\frac{6 + 0 + 16 + 18 + 1}{5} = \frac{41}{5} = 8.2\text{ ms}$$

### 4.4 Round Robin (RR - Döngüsel Zamanlama)

Özellikle zaman paylaşımlı (time-sharing) sistemler için tasarlanmış **kesmeli (preemptive)** bir algoritmadır. Her prosese küçük bir işlemci zamanı birimi olan **zaman dilimi (time quantum $q$)** tanımlanır (genellikle 10–100 milisaniye). Hazır kuyruğu dairesel bir FIFO kuyruğu olarak çalışır; işlemciyi alan proses en fazla $q$ birim çalıştıktan sonra zamanlayıcı kesmesiyle (timer interrupt) kesilir ve hazır kuyruğunun en sonuna eklenir.

#### Round Robin Sayısal Örneği ($q = 4$)

$t = 0$ anında gelen üç proses için zaman dilimi $q = 4$ seçilmiştir (ekrandan, 00:55:20):

| Proses | Burst Time |
|---|---|
| $P_1$ | 24 |
| $P_2$ | 3 |
| $P_3$ | 3 |

- $P_1$ ilk 4 birim çalışır ($0\text{–}4$), kalan süresi 20'dir; kesilip kuyruk sonuna geçer.
- $P_2$ toplam 3 birim olduğu için $q=4$ dolmadan ($4\text{–}7$ arasında) işini bitirip çıkar.
- $P_3$ toplam 3 birim olduğu için $7\text{–}10$ arasında işini bitirip çıkar.
- Kuyrukta yalnız $P_1$ kaldığından her 4 birimde bir zamanlayıcı kesmesi oluşsa da başka bekleyen proses olmadığı için $P_1$ arka arkaya 4'er birimlik dilimlerle $t=30$'a kadar çalışmasını tamamlar.

Gantt şeması:

```text
+------+-----+-----+------+------+------+------+------+
|  P1  | P2  | P3  |  P1  |  P1  |  P1  |  P1  |  P1  |
+------+-----+-----+------+------+------+------+------+
0      4     7     10     14     18     22     26     30
```

- **Bekleme süreleri:**
  - $P_1$: $0\text{–}4$ arası çalıştı, $4$'ten $10$'a kadar bekledi ($10 - 4 = 6$), sonrasında hiç beklemedi $\implies 6$.
  - $P_2$: $0$'dan $4$'e kadar bekledi $\implies 4$.
  - $P_3$: $0$'dan $7$'ye kadar bekledi $\implies 7$.
- **Ortalama bekleme süresi:**
  $$\frac{6 + 4 + 7}{3} = \frac{17}{3} \approx 5.67\text{ birim zaman}$$

#### Zaman Dilimi ($q$) Seçiminin Performansa Etkisi

Round Robin algoritması genellikle SJF'den daha yüksek ortalama dönüş süresine (turnaround time) yol açar, ancak **çok daha iyi yanıt süresi (response time)** sağlar. Zaman dilimi $q$'nun büyüklüğü kritik önem taşır:

- **$q$ çok büyük seçilirse:** Örneğin proseslerin burst süreleri $5, 8, 7$ iken $q = 10$ seçilirse her proses tek seferde işini bitirir ve Round Robin algoritması **FCFS (FIFO)** algoritmasına dönüşür.
- **$q$ çok küçük seçilirse:** Örneğin 10 birimlik tek bir proses için:
  - $q = 12$ ise **0** bağlam değişimi (context switch) yapılır,
  - $q = 6$ ise **1** bağlam değişimi yapılır,
  - $q = 1$ ise **9** bağlam değişimi yapılır.
  Her bağlam değişimi belirli bir süre (örneğin $< 10\ \mu\text{s}$) harcadığından, $q$ bağlam değiştirme süresine yaklaşırsa işlemci zamanının büyük kısmı bağlam değiştirme ek yüküne (overhead) harcanır. Pratikte $q$ genellikle **10 ms ile 100 ms** arasında seçilir ve CPU patlamalarının %80'inin tek bir zaman dilimi ($q$) içinde tamamlanması hedeflenir.

## 5. Çok Seviyeli Kuyruk ve Çok Seviyeli Geri Bildirimli Kuyruk

### 5.1 Çok Seviyeli Kuyruk (Multilevel Queue Scheduling)

Prosesler doğaları gereği etkileşimli **ön plan (foreground / interactive)** prosesleri ve **arka plan (background / batch)** prosesleri gibi farklı gruplara ayrıldığından, tüm prosesleri tek bir hazır kuyruğunda toplamak yerine hazır kuyruğu birden fazla ayrı kuyruğa bölünür:

```text
En Yüksek Öncelik ---> [ Sistem Prosesleri (System Processes) ]
                       [ Etkileşimli Prosesler (Interactive Processes) ]
                       [ Etkileşimli Düzenleme Prosesleri (Interactive Editing) ]
                       [ Toplu İş Prosesleri (Batch Processes) ]
En Düşük Öncelik  ---> [ Öğrenci Prosesleri (Student Processes) ]
```

- Her kuyruğun kendi zamanlama algoritması olabilir: Örneğin ön plan (etkileşimli) kuyruğu hızlı yanıt için **Round Robin** ile, arka plan (batch) kuyruğu ise **FCFS** ile yönetilir.
- Kuyruklar arasında da zamanlama yapılmalıdır:
  1. **Sabit öncelikli kesmeli zamanlama (Fixed priority scheduling):** Ön plan kuyruğu tamamen boşalmadan arka plan kuyruğundaki hiçbir proses çalıştırılmaz (açlık / starvation doğurabilir).
  2. **Kuyruklar arası zaman dilimi (Time slice):** Her kuyruğa CPU zamanının belirli bir yüzdesi verilir (örneğin %80 ön plan RR kuyruğuna, %20 arka plan FCFS kuyruğuna).

### 5.2 Çok Seviyeli Geri Bildirimli Kuyruk (Multilevel Feedback Queue)

Normal çok seviyeli kuyrukta bir proses sisteme girdiğinde bir kuyruğa kalıcı olarak atanır. **Çok Seviyeli Geri Bildirimli Kuyruk (Multilevel Feedback Queue)** ise bir prosesin davranışına göre **kuyruklar arasında hareket etmesine** izin verir; böylece açlık önlenir ve CPU burst süresi önceden bilinmeden kısa işlere öncelik tanınır.

Slayttaki üç kuyruklu örnek yapı:

```text
Giriş ---> [ Q0: Round Robin (q = 8 ms)  ] ---> Tamamlanırsa Çıkış
                    | (8 ms'de bitmezse indirilir)
                    v
           [ Q1: Round Robin (q = 16 ms) ] ---> Tamamlanırsa Çıkış
                    | (16 ms'de bitmezse indirilir)
                    v
           [ Q2: FCFS                    ] ---> Tamamlanırsa Çıkış
```

- Yeni gelen bir proses önce en üstteki $Q_0$ kuyruğuna ($q = 8\text{ ms}$) girer. 8 ms içinde işini bitirirse sistemden çıkar (kısa ve etkileşimli prosesler hızla tamamlanır).
- 8 ms içinde bitmezse kuyruk $Q_1$'e ($q = 16\text{ ms}$) düşürülür. Orada da 16 ms içinde tamamlanamazsa en alttaki $Q_2$ (FCFS) kuyruğuna indirilir. Çok uzun bekleyen prosesler ise açlığı önlemek için üst kuyruklara terfi ettirilebilir (aging).

> **Ders sonrası not:** Hoca 01:02:35 civarında şemayı anlatırken sehven "Q2'den Q1'e, oradan Q0'a yükseltilir" gibi yukarı doğru bir sıralama telaffuz etmiş ancak hemen ardından "burada da bitmediyse çok fazla CPU ihtiyacınız var, burada devam edeceksiniz" demiştir; slayttaki standart şemada yeni iş en yüksek öncelikli $Q_0$ ($q = 8\text{ ms}$) kuyruğuna girer, süresi yetmezse $Q_1$ ($q = 16\text{ ms}$) ve $Q_2$ (FCFS) kuyruklarına indirilir (ancak açlığı önlemek için yaşlandırma / aging ile ters yönde terfi de mümkündür).

## 6. İş Parçacığı Zamanlama (Thread Scheduling)

Kullanıcı seviyesi (user-level) ve çekirdek seviyesi (kernel-level) thread ayrımı bulunan sistemlerde işletim sistemi zamanlayıcısı prosesleri değil, **çekirdek seviyesi thread'leri** zamanlar. İki farklı yarışma kapsamı (contention scope) vardır:

1. **Proses Yarışma Kapsamı (Process-Contention Scope - PCS):** Çoğa-Bir (Many-to-One) ve Çoğa-Çok (Many-to-Many) modellerinde, thread kütüphanesi kullanıcı seviyesindeki thread'leri mevcut bir LWP (Lightweight Process) üzerinde çalışmak üzere **aynı prosesin kendi thread'leri arasında** yarıştırır.
2. **Sistem Yarışma Kapsamı (System-Contention Scope - SCS):** Çekirdeğin, hangi çekirdek thread'inin fiziksel işlemci (CPU) üzerinde çalışacağını belirlemek için **sistemdeki tüm thread'leri** birbiriyle yarıştırmasıdır (Bire-Bir / One-to-One modelini kullanan Windows ve Linux sistemleri yalnızca SCS kullanır).

POSIX Pthreads API'sinde kapsam `PTHREAD_SCOPE_PROCESS` (PCS) ve `PTHREAD_SCOPE_SYSTEM` (SCS) sabitleriyle kontrol edilir (ekrandan, 01:22:45):

```c
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

int main(int argc, char *argv[]) {
    int i, scope;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    /* varsayilan oznitelikleri al */
    pthread_attr_init(&attr);

    /* mevcut zamanlama kapsamini (scope) sorgula */
    if (pthread_attr_getscope(&attr, &scope) != 0)
        fprintf(stderr, "Unable to get scheduling scope\n");
    else {
        if (scope == PTHREAD_SCOPE_PROCESS)
            printf("PTHREAD_SCOPE_PROCESS");
        else if (scope == PTHREAD_SCOPE_SYSTEM)
            printf("PTHREAD_SCOPE_SYSTEM");
        else
            fprintf(stderr, "Illegal scope value.\n");
    }

    /* zamanlama algoritmasini SCS (SYSTEM) olarak ayarla */
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    /* thread'leri olustur ve bekle ... */
    return 0;
}
```

## 7. Çok İşlemcili Zamanlama (Multiple-Processor Scheduling)

Sistemde birden fazla homojen işlemci bulunduğunda zamanlama daha karmaşık hale gelir:

- **Asimetrik Çoklu İşleme (Asymmetric Multiprocessing - AMP):** Tüm zamanlama kararlarını, G/Ç işlemlerini ve sistem aktivitelerini tek bir ana işlemci (master server) yürütür; diğer işlemciler yalnızca kullanıcı kodunu çalıştırır.
- **Simetrik Çoklu İşleme (Symmetric Multiprocessing - SMP):** Her işlemci kendi kendini zamanlar (self-scheduling); tüm prosesler ortak bir hazır kuyruğunda tutulabilir veya her işlemcinin kendine özel bir hazır kuyruğu olabilir.

### 7.1 İşlemci Yakınlığı (Processor Affinity) ve NUMA

Bir proses belirli bir işlemci üzerinde çalışırken o işlemcinin **önbelleği (cache memory)** prosesin kullandığı verilerle dolar. Eğer proses bir sonraki çalışmasında başka bir işlemciye taşınırsa, ilk işlemcinin önbelleğindeki veriler geçersiz kılınmalı ve ikinci işlemcinin önbelleği sıfırdan doldurulmalıdır. Hoca bunu bölüm sekreterliğinde bir memurla başladığınız işi ertesi gün başka bir memurla sürdürmeye çalıştığınızda tüm süreci baştan anlatmak zorunda kalmanıza benzetti.

Bu maliyeti önlemek için SMP sistemleri bir prosesi aynı işlemci üzerinde tutmaya çalışır; buna **işlemci yakınlığı (processor affinity)** denir:

- **Yumuşak Yakınlık (Soft Affinity):** İşletim sistemi bir prosesi aynı işlemcide tutmaya çalışır ancak kesin garanti vermez (yük dengesizliği varsa taşıyabilir).
- **Katı Yakınlık (Hard Affinity):** Prosesin sistem çağrılarıyla yalnızca belirli bir işlemci kümesinde çalışmayı zorunlu kılmasıdır.

Ayrıca **NUMA (Non-Uniform Memory Access)** mimarilerinde her CPU'nun kendi yerel belleğine erişimi hızlı, diğer CPU'ya bağlı bellek bölgesine erişimi ise daha yavaştır; işlemci yakınlığı yerel bellekte kalmayı sağlayarak NUMA performansını da korur.

### 7.2 Yük Dengeleme (Load Balancing) ve Çok Çekirdekli İşlemciler

SMP sistemlerde bir işlemci aşırı yüklüyken diğerlerinin boşta kalmasını önlemek için **yük dengeleme (load balancing)** yapılır. İki yöntem birlikte kullanılır:

1. **İtme Göçü (Push Migration):** Özel bir periyodik görev tüm işlemcilerin yükünü kontrol eder; aşırı yüklü bir işlemci görürse oradaki prosesleri daha az yüklü veya boş işlemcilere **iter**.
2. **Çekme Göçü (Pull Migration):** Boşta kalan (idle) bir işlemci, meşgul bir işlemcinin kuyruğundan bekleyen bir görevi kendi üzerine **çeker**.

Çok çekirdekli (multicore) işlemcilerde ise bir thread bellekten veri beklerken (**memory stall** — önbellek ıskası nedeniyle ana belleğin beklenildiği boşluk) çekirdeğin boş kalmaması için çekirdek içinde iki veya daha fazla donanım thread'i çalıştırılır: `Thread 0` bellek beklemeye (`M`) geçtiği anda çekirdek `Thread 1`'in hesaplama döngüsünü (`C`) yürütür.

## 8. Gerçek Zamanlı İşlemci Zamanlama (Real-Time CPU Scheduling)

Gerçek zamanlı sistemler ikiye ayrılır:

- **Yumuşak Gerçek Zamanlı Sistemler (Soft Real-Time Systems):** Kritik gerçek zamanlı proseslere normal proseslere göre öncelik verilir ancak görevin belirli bir sürede tamamlanacağı **garanti edilmez**.
- **Katı Gerçek Zamanlı Sistemler (Hard Real-Time Systems):** Görevin mutlaka **son teslim zamanından (deadline)** önce tamamlanması zorunludur; gecikme kabul edilemez.

### 8.1 Olay Gecikmesi: Kesme Gecikmesi ve Dağıtım Gecikmesi

Bir olay (örneğin sıcaklık düşüşü veya sensör sinyali) gerçekleştiğinde sistemin buna yanıt vermesi iki gecikmenin toplamına bağlıdır:

1. **Kesme Gecikmesi (Interrupt Latency):** Donanımdan kesme sinyalinin CPU'ya ulaşmasından ilgili kesme servis rutininin (ISR) başlamasına kadar geçen süredir (kesme türünün belirlenmesi ve mevcut prosesin bağlamının kaydedilmesi).
2. **Dağıtım Gecikmesi (Dispatch Latency):** Zamanlayıcının mevcut prosesi durdurup gerçek zamanlı prosese CPU'yu teslim etmesi için geçen süredir (çakışma / conflict aşaması ve dağıtım / dispatch aşaması).

### 8.2 Periyodik Prosesler, Rate-Monotonic ve Earliest-Deadline-First Algoritmaları

Gerçek zamanlı sistemlerde periyodik olarak tekrarlanan her proses üç parametreyle tanımlanır:

- $p$: Periyot (prosesin hangi zaman aralıklarıyla tekrar geldiği),
- $t$: İşlem süresi (processing time / CPU burst),
- $d$: Son teslim zamanı (deadline — işin bitmesi gereken süre).

Bu üç büyüklük arasında her zaman şu bağıntı vardır:

$$0 \le t \le d \le p$$

Periyodik görevleri zamanlamak için iki temel algoritma kullanılır:

1. **Oran Monotonik Zamanlama (Rate-Monotonic Scheduling - RM):** Statik öncelikli ve kesmeli bir algoritmadır; her prosese **periyodunun tersiyle ($1/p$) orantılı** bir öncelik atar. Yani **periyodu daha kısa olan proses (daha sık gelen proses) daha yüksek önceliğe sahiptir**.
   - Örneğin $P_1$'in periyodu $p_1 = 50$, işlem süresi $t_1 = 20$ ve $P_2$'nin periyodu $p_2 = 100$, işlem süresi $t_2 = 35$ olsun ($d_i = p_i$). $p_1 < p_2$ olduğundan $P_1$ daha yüksek önceliklidir: $P_1$ $0\text{–}20$ arasında çalışır, ardından $P_2$ $20\text{–}50$ arasında 30 birim çalışır; $t=50$'de $P_1$'in yeni periyodu başladığı için $P_2$ kesilir ve $P_1$ $50\text{–}70$ arasında çalışır, ardından $P_2$ kalan 5 birimini $70\text{–}75$ arasında tamamlar (her ikisi de deadline'ına yetişir).
   - Ancak $P_1(p_1=50, t_1=25)$ ve $P_2(p_2=80, t_2=35)$ olduğunda RM algoritmasında $P_2$, $t=80$ anındaki son teslim zamanını kaçırır (**missed deadline**).
2. **En Yakın Son Teslim Zamanı Önce (Earliest-Deadline-First Scheduling - EDF):** Öncelikleri periyotlara göre sabit değil, **son teslim zamanlarına (deadlines) göre dinamik olarak** atar. Son teslim zamanı (deadline) en yakın olan proses en yüksek önceliği alır. RM algoritmasının deadline kaçırdığı $P_1(p_1=50, t_1=25)$ ve $P_2(p_2=80, t_2=35)$ örneğinde EDF algoritması $t=50$ anında $P_2$'nin deadline'ı ($80$) $P_1$'in yeni deadline'ından ($100$) daha yakın olduğu için $P_2$'yi kesmez ve her iki prosesin de tüm deadline'larını yakalamasını sağlar.

## 9. İşletim Sistemi Örnekleri: Linux, Windows ve Solaris Zamanlayıcıları

- **Linux Zamanlama:**
  - Sürüm 2.5 ile sabit zamanda çalışan **$O(1)$ zamanlayıcı** kullanılmıştır (0–99 arası gerçek zamanlı öncelikler, 100–140 arası nice değerine bağlı zaman paylaşımlı öncelikler).
  - Sürüm 2.6.23 ile birlikte **Tamamen Adil Zamanlayıcı (Completely Fair Scheduler - CFS)** yapısına geçilmiştir. CFS sabit zaman dilimleri yerine her göreve CPU zamanının bir oranını tahsis eder ve her görevin ne kadar çalıştığını **sanal çalışma süresi (`vruntime`)** değişkeninde tutar; işlemciyi her adımda **en küçük `vruntime`** değerine sahip göreve verir.
- **Windows Zamanlama:**
  - Öncelik tabanlı ve kesmeli (preemptive) zamanlama kullanır; Windows'ta zamanlayıcıya **dispatcher** adı verilir.
  - **32 seviyeli öncelik şeması** vardır: **1–15** arası değişken sınıf (variable class: idle, below normal, normal, above normal, high), **16–31** arası gerçek zamanlı sınıf (real-time class) ve **0** numaralı öncelik bellek yönetimi thread'ine (memory-management thread) ayrılmıştır. Windows 7 ile birlikte çok sayıda thread'in çekirdek müdahalesi olmadan yönetilebilmesi için **Kullanıcı Modu Zamanlama (User-Mode Scheduling - UMS)** eklenmiştir.
- **Solaris Zamanlama:**
  - Öncelik tabanlı altı zamanlama sınıfı içerir: Time sharing (varsayılan), Interactive, Real time, System, Fair share ve Fixed priority. Her sınıfın kendi öncelikleri ve zaman dilimi (time quantum) tabloları vardır; aynı öncelikteki thread'ler Round Robin ile çalıştırılır.

## 10. Algoritma Değerlendirme Yöntemleri

Bir işletim sistemi için hangi zamanlama algoritmasının seçileceğine karar vermek üzere dört değerlendirme yöntemi kullanılır:

### 10.1 Deterministik Modelleme (Deterministic Modeling)

Önceden belirlenmiş sabit bir iş yükü alınır ve her algoritma için performans değeri (örneğin ortalama bekleme süresi) analitik olarak hesaplanır. Slayttaki örnekte (ekrandan, 02:06:50) $t = 0$ anında gelen 5 proses verilmiştir:

| Proses | Burst Time (ms) |
|---|---|
| $P_1$ | 10 |
| $P_2$ | 29 |
| $P_3$ | 3 |
| $P_4$ | 7 |
| $P_5$ | 12 |

Üç algoritma için hesaplanan ortalama bekleme süreleri:

1. **FCFS:**
   - Gantt şeması: $P_1(0\text{–}10) \to P_2(10\text{–}39) \to P_3(39\text{–}42) \to P_4(42\text{–}49) \to P_5(49\text{–}61)$.
   - Ortalama bekleme süresi: $\frac{0 + 10 + 39 + 42 + 49}{5} = \frac{140}{5} = 28\text{ ms}$.
2. **Kesmesiz SJF:**
   - Gantt şeması: $P_3(0\text{–}3) \to P_4(3\text{–}10) \to P_1(10\text{–}20) \to P_5(20\text{–}32) \to P_2(32\text{–}61)$.
   - Ortalama bekleme süresi: $\frac{10 + 32 + 0 + 3 + 20}{5} = \frac{65}{5} = 13\text{ ms}$.
3. **Round Robin ($q = 10\text{ ms}$):**
   - Gantt şeması: $P_1(0\text{–}10) \to P_2(10\text{–}20) \to P_3(20\text{–}23) \to P_4(23\text{–}30) \to P_5(30\text{–}40) \to P_2(40\text{–}50) \to P_5(50\text{–}52) \to P_2(52\text{–}61)$.
   - Bekleme süreleri: $P_1 = 0$, $P_2 = 10 + (40 - 20) + (52 - 50) = 32$, $P_3 = 20$, $P_4 = 23$, $P_5 = 30 + (50 - 40) = 40$.
   - Ortalama bekleme süresi: $\frac{0 + 32 + 20 + 23 + 40}{5} = \frac{115}{5} = 23\text{ ms}$.

### 10.2 Kuyruk Modelleri (Queueing Models) ve Little Formülü

Gerçek sistemlerde proses gelişleri ve CPU/G/Ç burst süreleri olasılıksal dağılımlarla modellenir. Kararlı durumdaki (steady-state) herhangi bir kuyruk sistemi için **Little Formülü** geçerlidir:

$$n = \lambda \times W$$

Burada:

- $n$: Kuyruktaki ortalama proses sayısı (ortalama kuyruk uzunluğu),
- $\lambda$: Kuyruğa birim zamanda yeni proses geliş oranı (ortalama varış hızı, ör. saniyede 7 proses),
- $W$: Bir prosesin kuyrukta ortalama bekleme süresi.

**Sayısal Örnek (derste sözlü, 02:09:11):** Sisteme saniyede ortalama $\lambda = 7\text{ proses/sn}$ geliyorsa ve kuyrukta ortalama $n = 14\text{ proses}$ bulunuyorsa, bir prosesin kuyruktaki ortalama bekleme süresi $W = \frac{n}{\lambda} = \frac{14}{7} = 2\text{ saniyedir}$.

### 10.3 Simülasyonlar ve Gerçekleme (Implementation)

Kuyruk modellerinin matematiksel olarak yetersiz kaldığı karmaşık durumlarda bilgisayar sisteminin yazılımsal bir modeli (**simülasyon**) kurulur ve rastgele sayı üreteçleri veya gerçek sistemlerden toplanmış iz kayıtları (**trace tapes**) ile farklı algoritmalar test edilir. Tamamen kesin sonuç veren ancak en maliyetli yöntem ise algoritmayı gerçek işletim sistemi çekirdeğine kodlayarak (**implementation**) gerçek çalışma koşullarında ölçmektir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:11:30)

Aşağıdaki C programı çalıştırıldığında ekran çıktısı hakkında hangileri kesin olarak söylenebilir?

```c
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("0 \n");
    if (fork()) {
        if (!fork()) {
            fork();
            printf("1 \n");
        } else {
            printf("2 \n");
        }
    } else {
        printf("3 \n");
    }
    printf("4 \n");
    return 0;
}
```

**Çözüm (derste verildi):**

1. İlk `printf("0 \n");` çağrısı tüm `fork()` çağrılarından önce çalıştığı için çıktı **kesinlikle `0` ile başlar** ve ekranda yalnızca **1 adet `0`** bulunur.
2. İlk `fork()` sonrasında çocuk proses `else` dalından **`3`** ve ardından **`4`** basar (1 adet `3`).
3. Ebeveyn proses ikinci `fork()` çağrısında pozitif PID aldığı için `!fork()` koşulu `0` olur ve içteki `else` dalından **`2`** ve ardından **`4`** basar (1 adet `2`).
4. İkinci çocuk proses `!0 = 1` ile içeri girip bir `fork()` daha yapar; kendisi ve çocuğu birer kez **`1`** ve birer kez **`4`** basar (**2 adet `1`**).
5. Toplamda ekranda 1 adet `0` (en başta), 2 adet `1`, 1 adet `2`, 1 adet `3` ve 4 adet `4` yer alır.

### Soru 2 (ekrandan, 00:46:40)

Aşağıdaki tabloda varış zamanları (Arrival Time) ve CPU patlama süreleri (Burst Time) verilen dört proses **En Kısa Kalan Süre Önce (SRTF / Preemptive SJF)** algoritmasıyla zamanlanmaktadır. Gantt şemasını çiziniz ve ortalama bekleme süresini (average waiting time) hesaplayınız.

| Proses | Arrival Time (ms) | Burst Time (ms) |
|---|---|---|
| $P_1$ | 0 | 8 |
| $P_2$ | 1 | 4 |
| $P_3$ | 2 | 9 |
| $P_4$ | 3 | 5 |

**Çözüm (derste verildi):**

- Gantt şeması: $P_1 (0\text{–}1) \to P_2 (1\text{–}5) \to P_4 (5\text{–}10) \to P_1 (10\text{–}17) \to P_3 (17\text{–}26)$.
- Bekleme süreleri:
  - $P_1$: $(0 - 0) + (10 - 1) = 9\text{ ms}$
  - $P_2$: $1 - 1 = 0\text{ ms}$
  - $P_3$: $17 - 2 = 15\text{ ms}$
  - $P_4$: $5 - 3 = 2\text{ ms}$
- Ortalama bekleme süresi: $\frac{9 + 0 + 15 + 2}{4} = \frac{26}{4} = 6.5\text{ ms}$.

### Soru 3 (ekrandan, 02:06:50)

$t = 0$ anında hazır kuyruğuna $P_1, P_2, P_3, P_4, P_5$ sırasıyla giren beş prosesin CPU patlama süreleri sırasıyla $10, 29, 3, 7, 12\text{ ms}$'dir. Bu prosesler için **FCFS**, **Kesmesiz SJF** ve **Round Robin ($q = 10\text{ ms}$)** algoritmalarının ortalama bekleme sürelerini hesaplayıp karşılaştırınız.

**Çözüm (derste verildi):**

- **FCFS:** Sıra $P_1(0\text{–}10), P_2(10\text{–}39), P_3(39\text{–}42), P_4(42\text{–}49), P_5(49\text{–}61)$.
  $$\text{Ortalama Bekleme} = \frac{0 + 10 + 39 + 42 + 49}{5} = \frac{140}{5} = 28\text{ ms}$$
- **Kesmesiz SJF:** Sıra $P_3(0\text{–}3), P_4(3\text{–}10), P_1(10\text{–}20), P_5(20\text{–}32), P_2(32\text{–}61)$.
  $$\text{Ortalama Bekleme} = \frac{10 + 32 + 0 + 3 + 20}{5} = \frac{65}{5} = 13\text{ ms}$$
- **Round Robin ($q = 10\text{ ms}$):** Sıra $P_1(0\text{–}10), P_2(10\text{–}20), P_3(20\text{–}23), P_4(23\text{–}30), P_5(30\text{–}40), P_2(40\text{–}50), P_5(50\text{–}52), P_2(52\text{–}61)$.
  $$\text{Ortalama Bekleme} = \frac{0 + 32 + 20 + 23 + 40}{5} = \frac{115}{5} = 23\text{ ms}$$
- Bu iş yükü için en düşük ortalama bekleme süresini **SJF (13 ms)** verir, onu **RR (23 ms)** ve **FCFS (28 ms)** izler.

## Dersin Toparlaması

Bu derste önce `fork()` ve `wait()` çağrılarında ebeveyn-çocuk sonlanma sırası, zombi ve yetim (orphan) proseslerin nasıl oluştuğu kod örnekleri üzerinde netleştirilmiş; ardından **İşlemci Zamanlama (CPU Scheduling)** konusu tüm boyutlarıyla incelenmiştir. CPU–G/Ç patlama döngüsü, kesmeli (preemptive) ve kesmesiz (nonpreemptive) zamanlama, dağıtıcı (dispatcher) ve beş temel zamanlama kriteri tanımlanmış; FCFS (ve konvoy etkisi), SJF, üstel ortalama ile burst tahmini, SRTF, Öncelikli Zamanlama (açlık ve yaşlandırma), Round Robin, Çok Seviyeli Kuyruk ve Çok Seviyeli Geri Bildirimli Kuyruk algoritmaları sayısal örneklerle çözülmüştür. Son olarak thread zamanlama kapsamları (PCS/SCS), çok işlemcili SMP sistemlerde işlemci yakınlığı (affinity) ve yük dengeleme, gerçek zamanlı sistemlerde Rate-Monotonic ve EDF algoritmaları, Linux/Windows/Solaris zamanlayıcıları ve algoritma değerlendirme yöntemleri (deterministik modelleme, Little formülü ve simülasyon) ele alınmıştır. Bir sonraki derste (5. Bölüm) eşzamanlı çalışan proses ve thread'lerin ortak verilere güvenli erişimini sağlayan **Proses Senkronizasyonu (Process Synchronization)** konusu işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
