# Ders 9 Çalışma Özeti

## Genel Konular

- `fork()`, `wait()`, zombi (zombie) ve yetim (orphan) proseslerin tekrar incelenmesi
  - `fork()` çağrısı sonrasında ebeveyn (parent) ve çocuk (child) iki bağımsız proses olarak çalışır; hangisinin önce tamamlanacağı zamanlayıcıya bağlıdır. Standart kullanımda ebeveyn `wait()` çağrısıyla çocuğun tamamlanmasını bekler; önce çocuk proses `exit()` ile çıkış durumunu döndürür, ardından ebeveyn sonlanır.
  - **Zombi (zombie) proses:** Çocuk proses sonlandığı halde ebeveyn proses `wait()` çağırmamışsa (örneğin `while(1)` döngüsündeyse), çocuğun proses tablosundaki kaydı ve PID'si silinmez (ekrandan, 00:13:50).
  - **Yetim (orphan) proses:** Ebeveyn proses `wait()` yapmadan çocuktan önce sonlanırsa, çalışmaya devam eden çocuk proses yetim kalır ve `init` prosesi tarafından evlat edinilir (ekrandan, 00:14:40).
  - **Daemon (arka plan servisi):** Zombi veya yetim prosesten farklı olarak, yazdırma servisi gibi arka planda sürekli bekleyen ve ihtiyaç duyulduğunda çalışan düşük öncelikli sistem prosesidir.
- İşlemci zamanlama (CPU scheduling) temel kavramları
  - **CPU–G/Ç patlama döngüsü (CPU–I/O burst cycle):** Proseslerin yürütülmesi birbirini izleyen CPU patlaması (CPU burst) ve G/Ç beklemesi (I/O burst) adımlarından oluşur; CPU burst sürelerinin dağılımında kısa süreli patlamalar (1–3 ms) çoğunluktadır.
  - **Kısa vadeli zamanlayıcı (CPU scheduler / short-term scheduler):** Hazır kuyruğundaki (ready queue) proseslerden birini seçip işlemciyi tahsis eder.
  - **Kesmesiz (nonpreemptive) ve kesmeli (preemptive) zamanlama:** Zamanlama kararları dört durumda alınır: (1) çalışır durumdan beklemeye geçiş, (2) çalışır durumdan hazıra geçiş, (3) beklemeden hazıra geçiş, (4) sonlanma. Yalnızca 1 ve 4'te devreye giren zamanlama **kesmesiz (nonpreemptive)**, 2 ve 3'te de işlemciyi prosesin elinden alabilen zamanlama **kesmeli (preemptive)** olarak adlandırılır.
  - **Dağıtıcı (dispatcher) ve dağıtım gecikmesi (dispatch latency):** Seçilen prosese CPU kontrolünü veren (bağlam değiştirme, kullanıcı moduna geçiş ve program sayacına atlama işlemlerini yapan) modüldür; bir prosesi durdurup diğerini başlatması için geçen süreye **dispatch latency** denir.
- Zamanlama kriterleri (scheduling criteria)
  - Maksimize edilenler: **CPU kullanımı (CPU utilization)** ve **iş çıkarma oranı / verim (throughput)**.
  - Minimize edilenler: **Dönüş süresi (turnaround time)**, **bekleme süresi (waiting time)** ve **yanıt süresi (response time)**.
- Temel zamanlama algoritmaları
  - **İlk Gelen İlk Hizmet Alır (First-Come, First-Served - FCFS):** Kesmesizdir; hazır kuyruğuna ilk giren proses CPU'yu ilk alır. Uzun bir CPU-bound prosesin arkasında kısa proseslerin birikmesine **konvoy etkisi (convoy effect)** denir (ekrandan, 00:33:30).
  - **En Kısa İş Önce (Shortest-Job-First - SJF) ve En Kısa Kalan Süre Önce (Shortest-Remaining-Time-First - SRTF):** Bir sonraki CPU burst süresi en kısa olan prosese öncelik verir; ortalama bekleme süresini minimize etmede optimaldir (ekrandan, 00:39:15). Kesmeli versiyonuna **SRTF** denir (ekrandan, 00:46:40). Bir sonraki CPU burst süresi geçmiş ölçümlerin **üstel ortalamasıyla (exponential averaging)** tahmin edilir: $\tau_{n+1} = \alpha t_n + (1 - \alpha)\tau_n$ (ekrandan, 00:40:45).
  - **Öncelikli Zamanlama (Priority Scheduling):** Her prosese bir öncelik sayısı atanır ve en yüksek öncelikli (genellikle en küçük sayılı) proses seçilir (ekrandan, 00:50:15). Düşük öncelikli proseslerin hiç sıra alamaması sorununa **açlık (starvation)**, bekledikçe önceliğin artırılması çözümüne **yaşlandırma (aging)** denir.
  - **Round Robin (RR - Döngüsel Zamanlama):** Her prosese sabit bir **zaman dilimi (time quantum $q$)** verilir; süresi dolan proses kesilerek hazır kuyruğunun sonuna atılır (ekrandan, 00:55:20).
  - **Çok Seviyeli Kuyruk (Multilevel Queue) ve Çok Seviyeli Geri Bildirimli Kuyruk (Multilevel Feedback Queue):** Hazır kuyruğu etkileşimli (foreground - RR) ve toplu iş (background - FCFS) gibi birden fazla kuyruğa bölünür; geri bildirimli modelde prosesler CPU kullanım davranışlarına göre kuyruklar arasında terfi ettirilebilir veya indirilebilir.
- İş parçacığı (thread), çok işlemcili ve gerçek zamanlı (real-time) zamanlama
  - **Thread zamanlama kapsamları:** `PTHREAD_SCOPE_PROCESS` (PCS - proses içi yarışma) ve `PTHREAD_SCOPE_SYSTEM` (SCS - sistem geneli çekirdek thread'i yarışması) (ekrandan, 01:22:45).
  - **Çok işlemcili zamanlama:** Simetrik çoklu işleme (SMP), önbellek tutarlılığı ve **işlemci yakınlığı (processor affinity: soft/hard)**, **NUMA**, **yük dengeleme (load balancing: push/pull migration)**.
  - **Gerçek zamanlı zamanlama:** Yumuşak (soft) ve katı (hard) gerçek zamanlı sistemler; kesme gecikmesi (interrupt latency); periyodik işlerde **Rate-Monotonic (RM)** ve **Earliest-Deadline-First (EDF)** algoritmaları.
- İşletim sistemi örnekleri ve algoritma değerlendirme yöntemleri
  - **Linux** ($O(1)$ ve Completely Fair Scheduler - CFS / `vruntime`), **Windows** (32 seviyeli öncelik şeması) ve **Solaris** zamanlayıcıları.
  - **Algoritma değerlendirme:** Deterministik modelleme (ekrandan, 02:06:50), kuyruk teorisi (**Little Formülü: $n = \lambda \times W$**) ve simülasyonlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ebeveyn ve çocuk proseslerin sonlanma sırası
  - Uygulama dersinde sehven söylenen "önce parent biter, sonra child biter" ifadesi yanlıştır. Normal ve doğru kullanımda ebeveyn proses `wait()` ile çocuğunu bekler; önce çocuk işini bitirip `exit()` ile durum kodunu gönderir, ebeveyn bu bilgiyi aldıktan sonra sonlanır.
- `fork()` ile oluşan prosesler ve thread'ler arasındaki değişken paylaşımı farkı
  - Thread'ler aynı bellek uzayındaki global bir `x` değişkenini doğrudan paylaşır; birinin artırdığını diğeri görür. `fork()` yapıldığında ise bellek uzayı kopyalandığından ebeveyn ve çocuk proseslerin `x` değişkenleri birbirinden bağımsız iki ayrı bellek bölgesindedir; birinin `x`'i değiştirmesi diğerini etkilemez.
- Bekleme süresinin (waiting time) birden fazla kuyruk bekleyişinin toplamı olması
  - Kesmeli (preemptive) algoritmalarda (örneğin SRTF ve Round Robin) bir proses hazır kuyruğuna birden fazla kez girip çıkabilir; bir prosesin bekleme süresi yalnızca ilk girişte beklediği süre değil, hazır kuyruğunda beklediği tüm aralıkların toplamıdır. İlk yanıt alana kadar geçen süre ise **response time**'dır.
- Round Robin'de zaman dilimi ($q$) seçiminin etkisi
  - Zaman dilimi $q$ çok büyük seçilirse (tüm burst sürelerinden büyükse) Round Robin algoritması **FCFS**'ye dönüşür. Çok küçük seçilirse çok sık bağlam değişimi (context switch) yapılır ve bağlam değiştirme ek yükü (overhead) sistemi yavaşlatır.
- Çok işlemcili (SMP) sistemlerde işlemci yakınlığı (processor affinity)
  - Hoca bunu bölüm sekreterliğinde bir memurla başladığınız işe ertesi gün başka bir memurla devam etmeye çalıştığınızda her şeyi baştan anlatmak zorunda kalmanıza benzetti: Bir proses çalıştığı işlemcinin önbelleğini (cache) kendi verileriyle doldurur; başka işlemciye taşınırsa önbellek avantajını kaybeder. Bu yüzden prosesin aynı işlemcide kalması (**processor affinity**) tercih edilir.

## Kısa Tekrar Notları

- `fork()` dönüş değeri: $> 0$ ise ebeveyn (çocuğun PID'si), $== 0$ ise çocuk, $< 0$ ise hata.
- **Zombi proses:** Çocuk bitti (`exit`), ebeveyn `wait()` yapmadı. **Yetim (orphan) proses:** Ebeveyn bitti, çocuk hâlâ çalışıyor (`init` devralır).
- **Nonpreemptive:** Proses CPU'yu kendi bırakana (G/Ç beklemesi veya sonlanma) kadar tutar. **Preemptive:** Zamanlayıcı CPU'yu prosesin elinden alabilir.
- **Turnaround time:** Tamamlanma zamanı $-$ Varış zamanı (Bekleme süresi $+$ CPU burst süresi).
- **Waiting time:** Prosesin hazır kuyruğunda (ready queue) beklediği toplam süre.
- **Response time:** İstek verildikten ilk yanıt üretilene kadar geçen süre.
- **FCFS:** İlk gelen ilk çalışır; kesmesizdir; **konvoy etkisine (convoy effect)** yol açar.
- **SJF / SRTF:** En kısa bir sonraki CPU burst süresine sahip prosesi seçer (optimal ortalama bekleme süresi). Kesmesizi SJF, kesmelisi **SRTF**'dir.
- **Üstel ortalama tahmini:** $\tau_{n+1} = \alpha t_n + (1 - \alpha)\tau_n$; $\alpha = 0 \implies \tau_{n+1} = \tau_n$ (son ölçüm yok sayılır), $\alpha = 1 \implies \tau_{n+1} = t_n$ (yalnızca son ölçüm dikkate alınır).
- **Priority Scheduling:** En yüksek öncelikli proses çalışır; **açlık (starvation)** sorununu **yaşlandırma (aging)** çözer.
- **Round Robin (RR):** Her prosese $q$ zaman dilimi verilir; $q \to \infty$ ise FCFS olur, $q$ çok küçükse context switch yükü artar ($q$ genelde 10–100 ms, context switch $< 10\ \mu\text{s}$).
- **PCS (`PTHREAD_SCOPE_PROCESS`):** Kullanıcı thread'lerinin LWP için proses içi yarışması. **SCS (`PTHREAD_SCOPE_SYSTEM`):** Çekirdek thread'lerinin fiziksel CPU için sistem geneli yarışması.
- **Yük dengeleme (Load balancing):** **Push migration** (dolu işlemciden boş işlemciye itme) ve **Pull migration** (boş işlemcinin dolu işlemciden iş çekmesi).
- **Gerçek zamanlı zamanlama:** Periyot $p$, işlem süresi $t$, son teslim zamanı $d$ ($0 \le t \le d \le p$). **Rate-Monotonic (RM)** periyodu kısa olana statik öncelik verir; **EDF** deadline'ı en yakın olana dinamik öncelik verir.
- **Little Formülü:** $n = \lambda \times W$ ($n$: ortalama kuyruk uzunluğu, $\lambda$: ortalama varış oranı, $W$: kuyrukta ortalama bekleme süresi).

## Detaylı Açıklamalar

- **İç içe `fork()` çıktı analizi (`Ex_4_fork4.c`).** Ekranda (ekrandan, 00:11:30) gösterilen C kodu (`gcc -Wall` ile derlenip doğrulanmıştır):

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

  - İlk `printf("0 \n")` satırı henüz hiçbir `fork()` yapılmadan çalıştığı için ekrana **yalnızca bir kez ve en başta `0` basılır** (şıklarda `0` ile başlamayan seçenekler doğrudan elenir).
  - İlk `if (fork())` satırında: Çocuk proses (`0` döner) `else` bloğuna giderek bir kez `3` ve ardından `4` basar. Ebeveyn proses (`PID > 0` döner) `if` bloğuna girer ve ikinci `fork()` çağrısını yapar.
  - İkinci `if (!fork())` satırında: Ebeveyn için `fork()` pozitif döndüğünden `!fork()` değeri `0` olur; ebeveyn `else` bloğuna giderek bir kez `2` ve ardından `4` basar. İkinci çocuk için `fork()` değeri `0` döndüğünden `!0 = 1` olur ve içeri girip üçüncü `fork()`'u çalıştırır; böylece hem ikinci çocuk hem de onun çocuğu (torun proses) `1` ve ardından `4` basar. Sonuçta ekranda bir adet `0`, bir adet `2`, bir adet `3`, **iki adet `1`** ve toplam **dört adet `4`** (zamanlayıcıya bağlı sırada) görülür.
- **Zombi, yetim (orphan) ve çoklu `wait()` kod örnekleri:**
  - **Zombi proses (`Ex_8_zombie1.c`, ekrandan, 00:13:50):** `if (fork())` içinde ebeveyn `while(1);` ile sonsuz döngüde beklerken çocuk `else` bloğunda `exit(0);` ile sonlanır. Ebeveyn `wait()` çağırmadığı için çocuk proses tabloda zombi (`<defunct>`) olarak kalır.
  - **Yetim proses (`Ex_9_zombie2.c`, ekrandan, 00:14:40):** `if (fork())` içinde ebeveyn `exit(0);` ile hemen sonlanırken çocuk `else` bloğunda `while(1);` ile çalışmaya devam eder ve yetim (orphan) kalır.
  - **Beş çocuk oluşturup altı kez `wait()` çağırma (`Ex_11_wait2.c`, ekrandan, 00:16:30):** İlk döngüde 5 çocuk oluşturulup her biri `exit(100 + i)` ile (`100..104`) çıkar. İkinci döngü `numOfChilds + 1` (6) kez döndüğünde ilk 5 turda çocukların PID'leri ve `100..104` çıkış kodları yazdırılır; 6. turda bekleyecek çocuk kalmadığı için `wait(&child_status)` çağrısı `-1` döndürür, ancak `child_status` değişkeninde 5. turdaki son çocuğun durumu saklı kaldığından ekrana `Child -1 terminated with exit status 104` basılır.
- **Zamanlama algoritmalarının sayısal örnekleri:**
  - **FCFS Örneği (ekrandan, 00:33:30):** Burst süreleri $P_1 = 24, P_2 = 3, P_3 = 3$.
    - Sıra $P_1, P_2, P_3$ ise Gantt şeması: $P_1 (0\text{–}24), P_2 (24\text{–}27), P_3 (27\text{–}30)$. Bekleme süreleri: $P_1 = 0, P_2 = 24, P_3 = 27 \implies \text{Ortalama} = \frac{0 + 24 + 27}{3} = 17$.
    - Sıra $P_2, P_3, P_1$ ise Gantt şeması: $P_2 (0\text{–}3), P_3 (3\text{–}6), P_1 (6\text{–}30)$. Bekleme süreleri: $P_1 = 6, P_2 = 0, P_3 = 3 \implies \text{Ortalama} = \frac{6 + 0 + 3}{3} = 3$.
  - **Kesmesiz SJF Örneği (ekrandan, 00:39:15):** Burst süreleri $P_1 = 6, P_2 = 8, P_3 = 7, P_4 = 3$.
    - En kısadan uzuna sıra: $P_4 (0\text{–}3), P_1 (3\text{–}9), P_3 (9\text{–}16), P_2 (16\text{–}24)$.
    - Bekleme süreleri: $P_4 = 0, P_1 = 3, P_3 = 9, P_2 = 16 \implies \text{Ortalama} = \frac{3 + 16 + 9 + 0}{4} = \frac{28}{4} = 7$.
  - **Kesmeli SJF (SRTF) Örneği (ekrandan, 00:46:40):**
    - Verilenler (Varış zamanı, Burst süresi): $P_1(0, 8), P_2(1, 4), P_3(2, 9), P_4(3, 5)$.
    - $t=0$'da yalnız $P_1$ vardır, çalışmaya başlar. $t=1$'de $P_2$ gelir ($P_1$'in kalan süresi $7$, $P_2$'nin $4$); $4 < 7$ olduğundan $P_1$ kesilir ve $P_2$ çalışır ($1\text{–}5$). $t=2$'de $P_3(9)$ ve $t=3$'te $P_4(5)$ gelir ama $P_2$'nin kalan süresi daha küçüktür. $t=5$'te $P_2$ biter; kalan süreler $P_1=7, P_3=9, P_4=5$ olduğundan $P_4$ seçilir ($5\text{–}10$). $t=10$'da $P_1$ ($10\text{–}17$), $t=17$'de $P_3$ ($17\text{–}26$) çalışır.
    - Bekleme süreleri: $P_1 = (0 - 0) + (10 - 1) = 9$, $P_2 = 1 - 1 = 0$, $P_3 = 17 - 2 = 15$, $P_4 = 5 - 3 = 2$.
    - Ortalama bekleme süresi: $\frac{9 + 0 + 15 + 2}{4} = \frac{26}{4} = 6.5\text{ ms}$.
  - **Öncelikli Zamanlama (Priority Scheduling) Örneği (ekrandan, 00:50:15):**
    - Verilenler (Burst, Öncelik): $P_1(10, 3), P_2(1, 1), P_3(2, 4), P_4(1, 5), P_5(5, 2)$ (küçük sayı = yüksek öncelik).
    - Gantt şeması: $P_2 (0\text{–}1), P_5 (1\text{–}6), P_1 (6\text{–}16), P_3 (16\text{–}18), P_4 (18\text{–}19)$.
    - Bekleme süreleri: $P_2 = 0, P_5 = 1, P_1 = 6, P_3 = 16, P_4 = 18 \implies \text{Ortalama} = \frac{6 + 0 + 16 + 18 + 1}{5} = \frac{41}{5} = 8.2\text{ ms}$.
  - **Round Robin Örneği (ekrandan, 00:55:20):** Zaman dilimi $q = 4$, burst süreleri $P_1 = 24, P_2 = 3, P_3 = 3$.
    - Gantt şeması: $P_1 (0\text{–}4), P_2 (4\text{–}7), P_3 (7\text{–}10), P_1 (10\text{–}14), P_1 (14\text{–}18), P_1 (18\text{–}22), P_1 (22\text{–}26), P_1 (26\text{–}30)$.
    - Bekleme süreleri: $P_1 = 10 - 4 = 6$, $P_2 = 4$, $P_3 = 7 \implies \text{Ortalama} = \frac{6 + 4 + 7}{3} = \frac{17}{3} \approx 5.67\text{ ms}$.
  - **Deterministik Değerlendirme Örneği (ekrandan, 02:06:50):** $t=0$ anında gelen 5 prosesin burst süreleri $P_1 = 10, P_2 = 29, P_3 = 3, P_4 = 7, P_5 = 12$ olsun:
    - **FCFS:** Sıra $P_1(0\text{–}10), P_2(10\text{–}39), P_3(39\text{–}42), P_4(42\text{–}49), P_5(49\text{–}61)$; ortalama bekleme süresi $\frac{0 + 10 + 39 + 42 + 49}{5} = \frac{140}{5} = 28\text{ ms}$.
    - **Kesmesiz SJF:** Sıra $P_3(0\text{–}3), P_4(3\text{–}10), P_1(10\text{–}20), P_5(20\text{–}32), P_2(32\text{–}61)$; ortalama bekleme süresi $\frac{10 + 32 + 0 + 3 + 20}{5} = \frac{65}{5} = 13\text{ ms}$.
    - **Round Robin ($q = 10$):** Gantt şeması $P_1(0\text{–}10), P_2(10\text{–}20), P_3(20\text{–}23), P_4(23\text{–}30), P_5(30\text{–}40), P_2(40\text{–}50), P_5(50\text{–}52), P_2(52\text{–}61)$; ortalama bekleme süresi $\frac{0 + 32 + 20 + 23 + 40}{5} = \frac{115}{5} = 23\text{ ms}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
