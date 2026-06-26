# Ders 6 Çalışma Özeti

## Genel Konular

- CPU Scheduling'e Giriş
  - Her sistemde scheduling vardır. Scheduling kriterleri, sistem türüne (batch, interactive, real-time) göre değişir.
  - Bu ders genel kavramlar, kriterler ve algoritmalar üzerinde durur. Sonraki derslerde thread scheduling, multi-processor scheduling ve işletim sistemi örnekleri işlenir.

- CPU ve I/O Burst (Patlama) Kavramı
  - Process'in çalışması CPU burst ve I/O burst'lerden oluşur. Her iki tür zamanla birbirini takip eder.
  - CPU-bound process: Daha fazla CPU burst (uzun hesaplama).
  - I/O-bound process: Daha fazla I/O burst (bekleme, giriş/çıkış).
  - Gerçek hayatta çoğu CPU burst kısa süreli olur; uzun CPU burst'ler sayıca azdır.

- Scheduling Türleri
  - Long-term scheduler: Hangi programlar memory'ye alınacak (admission).
  - Short-term scheduler: Ready queue'dan hangi process CPU'ya alınacak. Çok hızlı olmalı.
  - Medium-term scheduler: Swap out/in ile process'leri memory'ye alıp çıkartır.

- Scheduling Anları (Ne Zaman Devreye Girer)
  - 1) Process running'den waiting'e geçerse (I/O başlatma, wait).
  - 2) Process running'den terminate'a geçerse.
  - 3) Process running'den ready'e geçerse (interrupt, time quantum).
  - 4) Process waiting'den ready'e geçerse (I/O tamamlandı).
  - 1 ve 2 → Non-preemptive.
  - 3 ve 4 → Preemptive.

- Scheduling Kriterleri
  - CPU utilization: İşlemci ne kadar meşgul. Çok yüksek olmamalı (%100 = acil durum, müdahale alanı kalmaz).
  - Throughput: Birim zamanda tamamlanan iş sayısı.
  - Turnaround time: Process'in sisteme girmesinden tamamlanmasına kadar geçen süre.
  - Waiting time: Ready queue'da geçen toplam süre.
  - Response time: İlk sonuç üretme zamanı.
  - Batch sistemlerde throughput; interaktif sistemlerde response time önemlidir.

- Scheduling Algoritmaları
  - **FCFS (First Come First Served)**: İlk gelen ilk servis alır. Non-preemptive. Basit ama convoy effect oluşabilir (uzun process arkaya kuyruk olur, tıpkı düğün konvoyu).
  - **SJF (Shortest Job First)**: En kısa burst time'a sahip process önce çalışır. Non-preemptive versiyonu optimaldir (minimum average waiting time) ama burst time'ı bilmek gerekir.
  - **SRTF (Shortest Remaining Time First)**: SJF'nin preemptive versiyonu. Kalan en kısa süreli process seçilir.
  - **Priority Scheduling**: Her process'e bir öncelik değeri atanır. Düşük değer = yüksek öncelik (veya tersi). Starvation (açlık) problemi olabilir; çözüm: aging (öncelik yaşla büyür).
  - **Round Robin (RR)**: Her process'e eşit zaman quantum (time slice) verilir (tipik 10-100 ms). Preemptive. Ready queue circular (FIFO) olarak gezilir. Quantum çok küçükse context switch fazla, çok büyükse FCFS'ye yaklaşır.
  - **Multilevel Queue**: Ready queue birden fazla alt kuyruğa bölünür (foreground/interactive, background/batch). Her kuyruğun kendi scheduling algoritması olabilir. Process'ler kuyruklar arası taşınmaz.
  - **Multilevel Feedback Queue**: Process'ler davranışına göre kuyruklar arası taşınabilir. CPU-bound process aşağı, I/O-bound yukarı. En genel algoritma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dispatch Latency Kavramı
  - Hoca özellikle vurgular: Dispatcher'ın seçtiği process'i mümkün olan en kısa sürede CPU'da çalıştırmaya başlatması gerekir. Context switch, user mode'a geçiş, uygun yere atlama için harcanan süre "dispatch latency"dir. Bu süre az olmalıdır.

- CPU Utilization'ın %100 Olmaması Gerektiği
  - Hoca, "%100 CPU kullanımı tercih edilir" denilmesine rağmen, %100 olmaması gerektiğini vurgular. Çünkü bir pay bırakılmalı; acil durum, güncelleme, yeni iş gelmesi gibi durumlar için alan lazım. Otomobil örneği: 220 yapabilen araçta sürekli 220 ile gitmek, acil durumda hızlanma şansı bırakmaz.

- Convoy Effect (Konvoy Etkisi)
  - Hoca, FCFS'nin uzun process'in arkasında kısa process'ler yığılması durumunu "konvoy" örneğiyle açıklar: Düğün alayında arabaların sağdan soldan geçememesi gibi, kısa işler de uzun işin bitmesini bekler.

- Tıkanıklık ve Performans
  - Çok fazla context switch sistemi yavaşlatır; optimum bir nokta vardır. Quantum çok küçükse overhead fazla, çok büyükse cevap süresi artar.

- Preemption Getirdiği Problemler
  - Hoca vurgular: Preemption iyi bir şey ama paylaşılan veriye erişim sırasında problem yaratır. Bir process veri üzerinde değişiklik yaparken preemptive olarak kesilirse, başka process aynı veriye erişip tutarsızlık yaratabilir. Senkronizasyon gerekir.

## Kısa Tekrar Notları

- CPU-bound vs I/O-bound process farkı.
- Preemptive vs Non-preemptive scheduling.
- FCFS: basit, convoy effect, non-preemptive.
- SJF: optimal ortalama waiting time, non-preemptive.
- SRTF: SJF preemptive.
- RR: time quantum, fair, context switch overhead.
- Throughput, Turnaround, Waiting, Response time kriterleri.
- Multilevel Queue: kuyruklar arası geçiş yok.
- Multilevel Feedback Queue: dinamik kuyruk değişimi.

## Detaylı Açıklamalar

Ders 6, CPU scheduling kavramını derinlemesine ele alır. Scheduling, OS'nin en temel görevlerinden biridir; kaynakların etkin paylaşımını sağlar. Ders, kavramlar, kriterler ve klasik algoritmalar üzerinde yoğunlaşır.

Process'lerin yaşam döngüsü boyunca CPU ve I/O burst'leri sırayla gerçekleşir. CPU-bound process daha çok hesaplama yapar, I/O-bound process daha çok bekler. Bu özellik scheduling kararlarını etkiler.

Short-term scheduler, ready queue'dan hangi process'in CPU'ya alınacağına karar verir. Hızlı olmalıdır (milisaniyeler mertebesinde). Scheduling kararları 4 farklı anda verilir: (1) Running → Waiting (non-preemptive), (2) Running → Terminated (non-preemptive), (3) Running → Ready (preemptive), (4) Waiting → Ready (preemptive).

Scheduling kriterleri sistem türüne göre farklı ağırlıklandırılır. Batch sistemlerde throughput, interaktif sistemlerde response time, gerçek zamanlı sistemlerde deadline'a uyum önemlidir.

FCFS (First Come First Served) en basit algoritmadır; non-preemptive'tir. Dezavantajı convoy effect: uzun bir process CPU'da iken kısa process'ler kuyrukta bekler. Ortalama waiting time optimal değildir.

SJF (Shortest Job First) her seferinde en kısa burst time'a sahip process'i seçer. Non-preemptive versiyonu minimum ortalama waiting time verir (optimal). Dezavantajı: burst time'ın önceden bilinmesi gerekir, uzun process'ler starvation'a uğrayabilir.

SRTF (Shortest Remaining Time First) SJF'nin preemptive versiyonudur. Yeni process geldiğinde, kalan süresi mevcut process'in kalan süresinden az ise preempt yapılır.

Priority Scheduling'de her process'e bir öncelik değeri atanır. Düşük değer yüksek öncelik anlamına gelir (Unix'te olduğu gibi). Dezavantajı starvation: düşük öncelikli process'ler uzun süre bekleyebilir. Çözüm: aging (process yaşlandıkça önceliği artar).

Round Robin her process'e eşit zaman quantum (time slice) verir. Quantum sonunda process preempt yapılır, ready queue'nun sonuna eklenir. Quantum çok küçükse context switch overhead fazla, çok büyükse cevap süresi artar. Tipik değer 10-100 ms arasındadır. RR, time-sharing sistemler için idealdir.

Multilevel Queue, process'leri öncelik kategorilerine göre farklı kuyruklara ayırır (ör. system, interactive, batch). Her kuyruğun kendi scheduling algoritması olabilir. Process'ler kuyruklar arası taşınmaz.

Multilevel Feedback Queue, en genel algoritmadır. Process'ler CPU-bound ise alt kuyruğa, I/O-bound ise üst kuyruğa taşınır. Bu sayede I/O-bound process'ler hızlı cevap alır, CPU-bound process'ler arka planda çalışır.

Convoy effect (FCFS) ve starvation (priority scheduling) algoritmaların tipik problemleridir. Aging ve uygun quantum seçimi bunlara karşı geliştirilen tekniklerdir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
