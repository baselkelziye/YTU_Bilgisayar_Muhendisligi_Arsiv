# Ders 4 Çalışma Özeti

## Genel Konular

- Proses yönetimine giriş
  - İşletim sistemi bir kontrol ve koordinasyon sistemidir; yönetilmesi gereken en önemli kaynaklardan biri işlemcidir. İşlemci proseslere tahsis edilir (allocation) ve geri alınır (deallocation).
  - Bu ve sonraki haftalarda proses kavramı, proses zamanlama (scheduling), prosesler üzerindeki işlemler ve prosesler arası haberleşme ele alınacaktır. Ana kaynak Silberschatz'ın kitabının slaytlarıdır; hoca diğer iki kaynağın (Stallings vb.) da okunmasını tavsiye etti.
- Proses kavramı
  - Batch sistemlerde çalışan işe "job", zaman paylaşımlı sistemlerde "user program" ya da "task" denir. Kitaplar job, proses ve program kavramlarını birbirinin yerine kullanabilir; derste "proses" kullanılır.
  - Derlenip bağlanmış (compile, link) çalıştırılabilir dosya diskte duran **pasif** bir varlıktır. Bu dosya belleğe yüklenip yürütülmeye başladığında **proses** adını alır; proses aktif bir varlıktır, yürütülen programdır.
  - Bir program birden fazla proses oluşturabilir (örneğin bir web tarayıcısı görev yöneticisinde aynı adlı çok sayıda proses olarak görünür).
- Prosesin bellekteki yerleşimi
  - Slayttaki şemada (ekrandan, 00:20:00) adres 0'dan max'a doğru: text, data, heap ve en üstte stack.
  - **Text (kod) bölümü:** programın makine kodu.
  - **Data bölümü:** global ve statik değişkenler, `main`'in komut satırı parametreleri ve ortam değişkenleri.
  - **Stack:** yerel değişkenler, sabit uzunluklu diziler, fonksiyon parametreleri, dönüş adresleri. Stack yüksek adresten aşağı doğru, heap aşağıdan yukarı doğru büyür.
  - **Heap:** çalışma zamanında dinamik olarak ayrılan bellek (`malloc`).
  - Ayrıca program sayacı (program counter), PSW/bayrak register'ları ve diğer register değerleri prosesin "anlık etkinliği" olarak saklanır.
  - Sonsuz özyinelemede stack dolar ve heap sınırına dayanır; işletim sistemi buna izin vermez ve program **stack overflow** hatasıyla sonlandırılır.
- Proses durum modelleri
  - İki durumlu model: running (CPU'da) ve waiting/not running (bellekte bekliyor).
  - Üç durumlu model: running, waiting ve G/Ç durumu; G/Ç'ye yalnız running durumundan geçilebilir.
  - Beş durumlu model (ekrandan, 00:30:00): new, ready, running, waiting, terminated.
- Proses Kontrol Bloğu (PCB)
  - Her proses için tutulan veri yapısı: proses durumu, proses numarası (PID), program sayacı, CPU register'ları, CPU zamanlama bilgisi (öncelik, kuyruk), bellek yönetimi bilgisi, muhasebe (accounting) bilgisi ve açık dosyalar/G/Ç durum bilgisi (file descriptor'lar).
  - PCB çoğunlukla ana bellekte tutulur.
- Prosesler arası geçiş ve bağlam değişimi (context switch)
  - Kesme ya da sistem çağrısında çalışan prosesin durumu PCB'sine kaydedilir, diğer prosesin durumu kendi PCB'sinden yüklenir (ekrandan, 00:40:00).
  - Bu süre (context switch time) bir ek yüktür (overhead); bu sırada sistem yararlı iş yapmaz.
- Thread'lere kısa giriş
  - Bir proses içinde birden fazla yürütme akışı (thread) olabilir; her thread için TCB (thread control block) tutulur. Ayrıntısı sonraki konudadır.
- Proses zamanlama (scheduling)
  - Zamanlama kuyrukları: job queue (sistemdeki bütün prosesler), ready queue (bellekte, çalışmaya hazır prosesler), device queue'lar (bir aygıtı bekleyen prosesler).
  - Linux'ta proses `task_struct` C yapısıyla temsil edilir ve bu yapılar çift bağlı bir liste hâlinde tutulur (ekrandan, 00:50:00).
  - Short-term (CPU) scheduler, long-term (job) scheduler ve medium-term scheduler (swap in / swap out).
  - G/Ç bağımlı (I/O-bound) ve CPU bağımlı (CPU-bound) prosesler, proses karışımı (process mix).
  - Mobil sistemlerde ön plan/arka plan ayrımı ve pil tasarrufu.
- Prosesler üzerindeki işlemler
  - Proses oluşturma: parent (ebeveyn) proses child (çocuk) proses oluşturur, proses ağacı oluşur; en kökte `init` (PID 1) vardır.
  - Kaynak paylaşımı ve yürütme seçenekleri; adres uzayının kopyalanması ve yeni programın yüklenmesi.
  - UNIX'te `fork()` ve `exec()` sistem çağrıları; Windows'ta `CreateProcess()`.
  - `getpid()`, `getppid()`, `wait()`, `exit()`, `abort`, `atexit()`.
  - Proses sonlandırma, cascading termination, zombi ve yetim (orphan) prosesler.
- Uygulama: kabuk (shell) komutları ve betikleri
  - Derste bir araştırma görevlisi Linux kabuk komutlarını, dosya izinlerini (`chmod`) ve basit kabuk betiklerini gösterdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Program ile proses farkı
  - Program diskte duran pasif bir dosyadır; proses belleğe yüklenmiş ve yürütülen aktif programdır. Derleyicinin kendisi bile çalışırken bir prosestir.
- Durum geçişleri (sınavda sık yapılan hata)
  - Yarıda kesilen bir proses ya G/Ç nedeniyle **waiting** durumuna ya da zaman dilimi dolduğu için doğrudan **ready** durumuna gider.
  - Waiting durumundan doğrudan running durumuna dönülemez; önce ready kuyruğuna girilir, sonra scheduler onu CPU'ya gönderir.
  - New durumundan yalnız ready durumuna geçilebilir.
- Ready durumunun nedeni
  - CPU bellekten çok hızlıdır; proses bellekten getirilene kadar CPU boş kalmasın diye hazır prosesler bir kuyrukta bekletilir. Hoca bunu kırmızı ışıktan yeşile geçince gaza basmaya hazır olmaya benzetti.
- `fork()` dönüş değeri
  - Negatif: proses oluşturulamadı. Sıfır: çocuk prosesin içindesiniz. Pozitif: parent'ın içindesiniz ve değer çocuğun PID'sidir.
  - Kod `fork()`'tan sonra ikiye ayrılır; aynı değişken parent'ta çocuğun PID'sini, çocukta 0'ı tutar.
- Parent ile çocuktan hangisinin önce çalışacağı bilinemez
  - Çıktıların sırası değişebilir; CPU'ya hangisinin önce gireceğine işletim sistemi karar verir ve araya başka prosesler de girer.
- Concurrent ile paralel farkı
  - Tek çekirdekte gerçek paralellik yoktur; hızlı bağlam değişimiyle oluşan "sanal paralellik" eş zamanlı (concurrent) yürütmedir. Birden fazla çekirdek ya da işlemci varsa gerçek paralellik olur.
- Fork bombası
  - Kendini yeniden çağıran bir fonksiyon içinde `fork()` kullanmak proses sayısını her adımda ikiye katlar; işletim sistemi bunu sınırlamazsa bellek dolar ve sistem kilitlenir.

## Kısa Tekrar Notları

- Proses = yürütülen program. Bellekte text, data, heap, stack bölümleri vardır.
- Beş durum: new, ready, running, waiting, terminated.
- Geçişler: new→ready (admitted), ready→running (scheduler dispatch), running→ready (interrupt), running→waiting (I/O or event wait), waiting→ready (I/O or event completion), running→terminated (exit).
- PCB: durum, PID, program sayacı, register'lar, zamanlama bilgisi, bellek bilgisi, muhasebe bilgisi, G/Ç durumu.
- Context switch: eski prosesin durumunu PCB'ye kaydet, yenisininkini yükle; süresi ek yüktür, donanım desteğiyle (register setleri) kısalır.
- Kuyruklar: job queue, ready queue, device queue.
- Short-term scheduler sık (milisaniyeler) çalışır; long-term scheduler seyrek (saniyeler, dakikalar) çalışır ve çoklu programlama derecesini kontrol eder; medium-term scheduler swap out/in ile bu dereceyi ayarlar.
- I/O-bound: az hesap, çok G/Ç. CPU-bound: çok hesap, az G/Ç. İyi bir proses karışımı gerekir.
- `fork()` = kopya proses oluşturur; `exec()` = prosesin bellek uzayına yeni program yükler; `wait()` = parent çocuğu bekler; `exit()` = sonlanır ve durum değerini parent'a gönderir.
- `fork` dönüş değerinin üç durumu: `< 0` hata, `== 0` çocuk, `> 0` parent.
- Cascading termination: parent sonlanınca bütün alt ağaç sonlandırılır.
- Zombi ve yetim proses ayrımı için aşağıdaki ders sonrası nota bakın.
- `chmod` sayısal izinler: r=4, w=2, x=1; üç basamak sırasıyla sahip, grup, diğerleri.

## Detaylı Açıklamalar

- **Bellek düzeni ve deneme.** Hoca, aynı fonksiyonda art arda tanımlanan iki yerel değişkenin adreslerini `%p` ile yazdırınca stack'te adreslerin azaldığını, `malloc` ile ayrılan bir dizinin elemanlarında ise adreslerin arttığını gözlemleyebileceğimizi söyledi. Global değişkenlerin stack'te değil ayrı bir data bölümünde tutulmasının nedenine senkronizasyon konusunda dönülecek.

  > **Ders sonrası not:** Hoca stack ve heap'in büyüme yönünü "big endian, little endian" kavramlarıyla ilişkilendirdi. Bu iki kavram çok baytlı bir değerin baytlarının bellekteki sırasıdır; stack'in büyüme yönü ile ilgisi yoktur. Stack'in hangi yöne büyüdüğü işlemci mimarisine ve çağrı kurallarına bağlıdır (x86'da aşağı doğru).

- **Durum modellerinin gelişimi.** İlk tasarımlarda iki durum (running, waiting) vardı. G/Ç işlemleri için üçüncü bir durum eklendi; burada waiting durumundan G/Ç durumuna geçilemez, çünkü bellekte bekleyen ve yürütülmeyen bir prosesin G/Ç isteği yapması mümkün değildir. Günümüzde temel alınan beş durumlu modeldir, ama Windows ve UNIX gibi gerçek sistemler ek durumlar tanımlar. Hoca durum geçişlerini Theory of Computation dersindeki durum makinelerine (deterministik ve deterministik olmayan sonlu otomatlara) benzetti.
- **Beş durumlu model.** Slayttaki diyagram (ekrandan, 00:30:00):

  ```text
  new --admitted--> ready --scheduler dispatch--> running --exit--> terminated
                    ready <------interrupt------- running
                    running --I/O or event wait--> waiting
                    waiting --I/O or event completion--> ready
  ```

- **Bağlam değişimi.** Slayttaki şemada (ekrandan, 00:40:00) P0 çalışırken bir kesme ya da sistem çağrısı gelir; işletim sistemi P0'ın durumunu PCB0'a kaydeder, PCB1'den P1'in durumunu yükler ve P1 çalışır. Bu sırada P0 boştadır (idle). P1 için kesme geldiğinde aynı işlem ters yönde yapılır. Kaydetme, boşta geçen süre ve yükleme birlikte context switch süresidir. Bu süre PCB'nin büyüklüğüne, işletim sistemi rutinlerinin karmaşıklığına ve donanım desteğine bağlıdır; işlemcide bu işe ayrılmış register setleri varsa PCB register'larda tutularak geçiş hızlanabilir.
- **Linux `task_struct`.** Slayttaki alanlar (ekrandan, 00:50:00): `pid_t pid` (proses kimliği), `long state` (durum), `unsigned int time_slice` (zamanlama bilgisi), `struct task_struct *parent` (parent proses), `struct list_head children` (çocuklar), `struct files_struct *files` (açık dosyalar), `struct mm_struct *mm` (adres uzayı). Hoca açık dosyaların yalnız metin dosyaları olmadığını, ağ bağlantılarının da file descriptor kullandığını söyledi.
- **Kuyruk örneği.** Slayttaki ready queue'da önce PCB7, sonra PCB2 vardır; kuyruğun başı ve sonu ayrı tutulur. Manyetik teyp kuyrukları boştur, disk kuyruğunda PCB3, PCB14 ve PCB6, terminal kuyruğunda PCB5 bulunur.
- **Scheduler'lar.**
  - Short-term (CPU) scheduler ready queue'dan bir proses seçip CPU'ya verir. Çok sık çağrıldığı için hızlı olmalıdır. Bazı sistemlerde tek scheduler budur.
  - Long-term scheduler hangi proseslerin ready queue'ya alınacağına karar verir ve çoklu programlama derecesini (degree of multiprogramming) kontrol eder. Hoca örnek olarak 500 programlık bir sistemde bu derecenin örneğin 100 ile 500 arasında gezebileceğini söyledi. Hangi prosesin G/Ç bağımlı, hangisinin CPU bağımlı olacağı önceden bilinmez; işletim sistemi istatistiklere dayalı tahmin yapar.
  - Medium-term scheduler, yanlış kararlarla bozulan dengeyi swap out (prosesi bellekten diske çıkarmak) ve swap in (diskten geri getirmek) ile düzeltir. Swap out çoklu programlama derecesini doğrudan azaltır.
- **Proses oluşturma.** Parent prosesin adres uzayı önce birebir kopyalanır, sonra çocuk prosese kendi programı yüklenir. UNIX'te bu iki adım iki ayrı sistem çağrısıdır: `fork()` kopyayı (yeni PID ve bellek alanıyla) oluşturur, `exec()` ailesi çocuğun bellek uzayına yeni programı yükler. Slayttaki örnek (ekrandan, 01:36:00):

  ```c
  #include <sys/types.h>
  #include <stdio.h>
  #include <unistd.h>

  int main()
  {
  pid_t pid;
      /* fork a child process */
      pid = fork();
      if (pid < 0) { /* error occurred */
          fprintf(stderr, "Fork Failed");
          return 1;
      }
      else if (pid == 0) { /* child process */
          execlp("/bin/ls","ls",NULL);
      }
      else { /* parent process */
          /* parent will wait for the child to complete */
          wait(NULL);
          printf("Child Complete");
      }
      return 0;
  }
  ```

  Ajan bu kodu `#include <sys/wait.h>` eklenerek scratchpad'de `gcc -Wall` ile derleyip çalıştırdı: önce `ls` çıktısı, sonra `Child Complete` yazıldı. Windows'taki karşılığı `CreateProcess()`'tir; slayttaki örnekte (ekrandan, 01:38:20) çocuk proses olarak `C:\WINDOWS\system32\mspaint.exe` çalıştırılır, parent `WaitForSingleObject(pi.hProcess, INFINITE)` ile çocuğu bekler.
- **`getpid` örneği.** Slayttaki `fork2.c` (ekrandan, 01:45:30) önce kendi PID'sini, `fork()`'tan sonra hem PID'yi hem `fork` sonucunu yazar. Ekrandaki çıktıda parent 2682 olarak `result : 2683`, çocuk 2683 olarak `result : 0` yazmıştır.
- **Sonlandırma.** `exit()` ile proses biter ve bir durum değeri parent'a gönderilir; parent bunu `wait(&status)` ile alır. Kaynaklar işletim sistemince geri alınır. Parent, çocuğu `abort` ile sonlandırabilir: çocuk kaynaklarını aşmışsa, görevi gereksiz kalmışsa ya da parent sonlanıyorsa ve sistem çocuğun yalnız devam etmesine izin vermiyorsa. `atexit()` ile çıkışta çalışacak bir fonksiyon (dosya kapatma, veritabanı bağlantısını kesme gibi) kaydedilir; `exit`'ten farklıdır.

  > **Ders sonrası not:** Hoca "wait kullanılmadı, çocuk yaşıyor, parent yaşamıyor; bu zombi proses" dedi ve yetimi zombinin özel hâli olarak andı. Standart tanımlar farklıdır: **zombi**, sonlanmış ama parent'ı henüz `wait` çağırmadığı için proses tablosundaki kaydı silinmemiş çocuktur; **yetim (orphan)**, parent'ı sonlandığı hâlde çalışmaya devam eden çocuktur ve `init` (ya da bir alt toplayıcı proses) tarafından evlat edinilir. Slayttaki `zombie2.c` örneğinde (ekrandan, 01:57:30) parent biter, çocuk `while(1)` ile çalışmaya devam eder ve `ps` çıktısında parent PID'si 1 görünür; yani bu çocuk aslında yetim prosestir.

- **`wait` örneği.** Slayttaki `wait1.c`'de (ekrandan, 02:00:30) beş çocuk `exit(100+i)` ile sonlanır; parent beş kez `wait` çağırıp `WEXITSTATUS` ile durum değerini yazar. Ekrandaki çıktıda sıra 100, 101, 103, 104, 102'dir; çocukların bitiş sırası CPU'nun dağıtımına bağlıdır.
- **Kabuk uygulaması.** Bir araştırma görevlisi `mkdir`, `cd`, `ls`, `rmdir`, `touch`, `rm`, `cat`, `nano`, `useradd`/`userdel`, `groupadd`/`groupdel`, `usermod -a -G` komutlarını gösterdi. `chmod 754 dosya`: sahip rwx (7), grup r-x (5), diğerleri r-- (4); aynısı `chmod u=rwx,g=rx,o=r dosya` ile de yapılır, `-R` alt klasörlere uygular. `444` yalnız okuma verir ve `nano` dosyayı yazılamaz (unwritable) bildirir. Betiklerde `$0` betik adı, `$1`... parametreler, `$#` parametre sayısıdır; `>` dosyanın üzerine yazar, `>>` sona ekler; `|` (pipe) bir komutun çıktısını sonrakine girdi olarak verir (`ps aux | egrep root`, `echo ... | tr a-z A-Z`). `expr` ile aritmetikte çarpma `\*` diye kaçırılır. Python'da `subprocess` modülüyle kabuk komutları çalıştırılabilir.

  > **Ders sonrası not:** Uygulama notlarında yazma izni 3 olarak yazılmıştı; derste bir öğrencinin uyarısıyla doğrusunun 2 olduğu kabul edildi (r=4, w=2, x=1; 3 = w+x).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
