# Ders 9 Çalışma Özeti

## Genel Konular

- CPU Scheduling'e Giriş
  - Scheduling kriterleri, algoritmaları, multi-processor scheduling, thread scheduling, OS örnekleri.
  - Process'ler CPU-bound (yoğun hesaplama) veya I/O-bound (yoğun giriş/çıkış) olabilir. Her process CPU burst ve I/O burst'lerden oluşur.
  - Burst süreleri öngörülemez; istatistik ve tahmin yöntemleri kullanılabilir.

- Scheduling Türleri
  - Long-term scheduler: Programları memory'ye alır (admission).
  - Short-term scheduler: Ready queue'dan CPU'ya process seçer (CPU scheduling).
  - Medium-term scheduler: Swap out/in ile process'leri memory'ye alıp çıkarır (swapping).

- Scheduling Zamanlamaları
  - 4 durum: (1) Running → Waiting (non-preemptive), (2) Running → Terminated (non-preemptive), (3) Running → Ready (preemptive), (4) Waiting → Ready (preemptive).
  - Sadece 1 ve 4 durumlarında scheduling yapılırsa non-preemptive.
  - 3 ve 4 durumlarında da yapılırsa preemptive.

- Dispatcher
  - Scheduler'ın seçtiği process'i CPU'da çalıştırmaya başlatan modül.
  - Dispatch latency: Context switch + user mode'a geçiş + uygun yere atlama için harcanan süre. Bu süre az olmalıdır.

- Scheduling Kriterleri
  - CPU Utilization: İşlemci meşguliyet oranı. Çok yüksek olmamalı.
  - Throughput: Birim zamanda tamamlanan iş sayısı. Maksimize edilmeli.
  - Turnaround Time: Process'in sisteme girmesinden çıkmasına kadar geçen süre. Minimize edilmeli.
  - Waiting Time: Ready queue'da geçen toplam süre. Minimize edilmeli.
  - Response Time: İlk cevap üretme süresi. Minimize edilmeli.

- Scheduling Algoritmaları
  - **FCFS (First Come First Served)**: Basit, kuyruk bazlı. Convoy effect oluşabilir. Non-preemptive.
  - **SJF (Shortest Job First)**: Burst time'a göre sırala. Optimal ortalama waiting time. Non-preemptive.
  - **SRTF (Shortest Remaining Time First)**: SJF'nin preemptive versiyonu. Yeni gelen daha kısa ise preempt.
  - **Priority Scheduling**: Önceliğe göre seçim. Starvation olabilir. Aging çözüm.
  - **Round Robin (RR)**: Time quantum ile sıralı. Preemptive. Fair.
  - **Multilevel Queue**: Birden fazla kuyruk, her birinin kendi algoritması. Geçiş yok.
  - **Multilevel Feedback Queue**: Kuyruklar arası geçiş var. En genel.

- Multi-Processor Scheduling
  - Birden fazla işlemci olduğunda scheduling daha karmaşık hale gelir.
  - Asymmetric multiprocessing: Sadece bir işlemci scheduling yapar, diğerleri sadece çalışır.
  - Symmetric multiprocessing (SMP): Her işlemci kendi scheduling kararını verebilir.
  - Processor affinity: Process'in belirli bir işlemcide çalışma isteği (cache reuse için).
  - Load balancing: İşlemciler arası yük dağılımı.

- Thread Scheduling
  - User-level thread: Library tarafından yönetilir, kernel habersiz.
  - Kernel-level thread: Kernel tarafından yönetilir. Modern OS'lerde tercih edilir.
  - Many-to-one, one-to-one, many-to-many modelleri.

- Algoritma Örnekleri
  - Linux: CFS (Completely Fair Scheduler), CFS'nin yerine artık EEVDF (Earliest Eligible Virtual Deadline First) kullanılıyor.
  - Windows: Multilevel feedback queue, 32 seviyeli öncelik.
  - Solaris: Multilevel feedback queue, çok sayıda kuyruk.

## Hocanın Özellikle Vurguladığı Kısımlar

- CPU Utilization'da %100'den Kaçınılması
  - Hoca, "tabii ki utilization'ın 1 olmasını yani %100 olmasını da tercih etmem. Çünkü biraz payı olabilmeli" der. Araba örneği: 220 hız yapabilen araçta sürekli 220 ile gitmek acil durumda hızlanma şansı bırakmaz.

- Convoy Effect
  - FCFS'de uzun process arkasında kısa process'ler birikir. Düğün alayı örneği: önde düğün alayı arabaları, arkadakiler geçemiyor.

- Preemption Getirdiği Problemler
  - Hoca vurgular: "Eğer kullandığımız yapı ya da yaptığımız iş belli bir önümüzdeyse tabi ki kullanılabilecek bir model." Ancak preemption paylaşılan veriye erişim sırasında senkronizasyon problemleri yaratır. Mutex ve senkronizasyon gerekir.

- Preemption Kernel Modundayken Olmamalı
  - "Bir tane daha şey: kernel modundayken preemption oluşması. Bunların her birinde aslında ne sıkıntısı var teknik olarak bakacak olursanız. Siz bir veri üzerinde değişiklik yapıyordunuz. O sırada sistemin preemptive olduğu için çalışmanız durduruldu kenara alındınız." Hoca bu durumun ortalığı ciddi şekilde karıştırabileceğini vurgular.

- Starvation ve Deadlock
  - Hoca, preemption'un düzgün çözümlenmediğinde starvation ve deadlock'a yol açabileceğini belirtir.

- Dispatcher vs Scheduler Ayrımı
  - Hoca vurgular: "Scheduler aslında demeyin ki slide'in en başında yazan şey olarak özetleyebilirsiniz. Ready queue'dan bir işlemin CPU'da çalıştırılmak üzere seçilmesi durumu. Neye göre? Belirlenmiş olan kritere göre." Dispatcher ise seçilen process'i CPU'da çalıştıran, kernel mode'dan user mode'a geçen modüldür.

## Kısa Tekrar Notları

- CPU scheduling türleri: long-term, short-term, medium-term.
- Preemptive vs non-preemptive.
- FCFS, SJF, SRTF, Priority, RR, Multilevel Queue, Multilevel Feedback Queue.
- Kriterler: CPU utilization, throughput, turnaround time, waiting time, response time.
- Multi-processor: asymmetric, symmetric multiprocessing.
- Linux: CFS / EEVDF.
- Windows: 32 seviyeli öncelik.
- Dispatcher: scheduler'ın seçtiği process'i CPU'ya yükler.

## Detaylı Açıklamalar

Ders 9, CPU scheduling kavramını kriterler ve algoritmalar üzerinden derinlemesine ele alır. Bu ders, geçen haftalarda giriş yapılan scheduling konusunu detaylandırır.

Process'ler CPU-bound ve I/O-bound olabilir. Her process'in çalışması CPU burst ve I/O burst'lerden oluşur. Burst süreleri önceden bilinemez; istatistiksel yöntemlerle tahmin edilebilir. Tipik bir sistemde kısa CPU burst'ler daha sık görülür, uzun CPU burst'ler daha nadirdir.

Scheduling kriterleri sistem türüne göre farklı ağırlıklandırılır. Batch sistemlerde throughput (birim zamanda tamamlanan iş sayısı) önemlidir. İnteraktif sistemlerde response time (ilk cevap süresi) önemlidir. Genel olarak CPU utilization yüksek, turnaround/waiting/response time düşük olmalıdır.

FCFS (First Come First Served) en basit algoritmadır. Process'ler geliş sırasına göre çalıştırılır. Non-preemptive'tir. Dezavantajı convoy effect: uzun process CPU'dayken kısa process'ler kuyrukta birikir. Ortalama waiting time optimal değildir.

SJF (Shortest Job First) her seferinde en kısa burst time'a sahip process'i seçer. Non-preemptive versiyonu optimal ortalama waiting time verir. Dezavantajı: burst time'ı önceden bilmek gerekir, uzun process'ler starvation'a uğrayabilir.

SRTF (Shortest Remaining Time First) SJF'nin preemptive versiyonudur. Yeni gelen process'in burst time'ı, mevcut process'in kalan süresinden az ise preempt yapılır.

Priority Scheduling'de her process'e bir öncelik değeri atanır. Düşük değer yüksek öncelik anlamına gelir. Dezavantajı starvation: düşük öncelikli process'ler uzun süre bekleyebilir. Çözüm: aging (process yaşlandıkça önceliği artar).

Round Robin her process'e eşit zaman quantum (time slice) verir. Quantum sonunda process preempt yapılır, ready queue'nun sonuna eklenir. Quantum çok küçükse context switch overhead fazla, çok büyükse cevap süresi artar.

Multilevel Queue, process'leri öncelik kategorilerine göre farklı kuyruklara ayırır. Her kuyruğun kendi scheduling algoritması olabilir. Process'ler kuyruklar arası taşınmaz.

Multilevel Feedback Queue, en genel algoritmadır. Process'ler CPU-bound ise alt kuyruğa, I/O-bound ise üst kuyruğa taşınır. Bu sayede I/O-bound process'ler hızlı cevap alır, CPU-bound process'ler arka planda çalışır.

Multi-processor scheduling, birden fazla işlemci olduğunda devreye girer. Asymmetric multiprocessing'de sadece bir işlemci scheduling yapar. Symmetric multiprocessing'de (SMP) her işlemci kendi kararını verebilir. Processor affinity, process'in belirli bir işlemcide kalma isteğidir (cache reuse için). Load balancing, işlemciler arası yük dağılımıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
