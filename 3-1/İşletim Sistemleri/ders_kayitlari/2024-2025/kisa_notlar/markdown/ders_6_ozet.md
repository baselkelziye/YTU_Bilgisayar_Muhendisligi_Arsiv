# Ders 6 Çalışma Özeti

## Genel Konular

- Prosesler arası haberleşme (interprocess communication, IPC)
  - Bir prosesin kendi bellek bölgesi ve kaynakları her zaman yeterli olmaz. Kendi kaynaklarıyla yetinen ve başka proseslerden etkilenmeyen prosese **bağımsız (independent)**, başka proseslerle veri paylaşan, onları etkileyen ya da onlardan etkilenen prosese **işbirlikçi (cooperating)** proses denir.
  - Örnekler: PostgreSQL veritabanı yönetim sistemi ile pgAdmin arayüzü iki ayrı prosestir ve haberleşir; WhatsApp ile mesaj göndermek iki farklı telefondaki prosesin ağ üzerinden haberleşmesidir.
  - IPC'nin gerekçeleri: bilgi paylaşımı, hesaplamayı hızlandırmak için iş bölümü, modülerlik ve kullanım kolaylığı (convenience).
- İki temel model: paylaşımlı bellek ve mesaj geçirme
  - Slayttaki şemada (ekrandan, 00:09:00) (a) mesaj geçirmede A ve B prosesleri çekirdekteki bir mesaj kuyruğu (m0, m1, m2, ...) üzerinden, (b) paylaşımlı bellekte iki prosesin adres uzayı arasındaki ortak bir bellek bölgesi üzerinden haberleşir.
  - **Mesaj geçirme (message passing):** Mesajlar çekirdek düzeyindeki bir veri yapısına yazılır ve oradan okunur; yönetimi çekirdek yapar, kullanımı kolaydır, ama kullanıcı modundan çekirdek moduna geçiş gerektirir.
  - **Paylaşımlı bellek (shared memory):** İki proses için ortak bir bellek bölgesi ayrılır; çekirdek iletişime karışmaz, prosesler kendi aralarında anlaşır. Okuma ile yazmanın eşzamanlanması proseslerin sorumluluğundadır.
- Üretici-tüketici (producer-consumer) problemi
  - Bir proses veri üretir, diğeri tüketir; e-ticaret siparişi, otobüs bileti gibi uygulamaların büyük çoğunluğu bu mantıktadır. Üretilen veri bir tamponda (buffer) tutulur.
  - **Sınırsız tampon (unbounded buffer):** pratikte sınır yoktur (depolama kapasitesi kadar). **Sınırlı tampon (bounded buffer):** sabit boyutludur; üretici tamponun dolu, tüketici boş olup olmadığını kontrol etmelidir.
  - Paylaşımlı bellekle sınırlı tampon çözümü: dairesel bir dizi ve `in`, `out` indisleri.
- Mesaj geçirme sistemi ayrıntıları
  - İki işlem: `send(message)` ve `receive(message)`; mesaj boyutu sabit ya da değişken olabilir.
  - Haberleşmek için bir haberleşme bağlantısı (communication link) kurulmalıdır. Tasarım soruları: bağlantı nasıl kurulur, ikiden fazla prosesle ilişkilendirilebilir mi, iki proses arasında kaç bağlantı olabilir, kapasitesi nedir, mesaj boyutu sabit mi değişken mi, tek yönlü mü çift yönlü mü?
  - Simpleks, yarı çift yönlü (half duplex) ve tam çift yönlü (full duplex) haberleşme.
  - Fiziksel gerçekleştirim: paylaşımlı bellek, donanım veriyolu (bus) ya da ağ. Mantıksal gerçekleştirim: doğrudan ya da dolaylı, eşzamanlı ya da eşzamansız, otomatik ya da açık tamponlama.
- Doğrudan ve dolaylı haberleşme
  - **Doğrudan:** `send(P, message)`, `receive(Q, message)`; bağlantı otomatik kurulur, her proses çifti arasında tek bağlantı vardır.
  - **Dolaylı:** mesajlar posta kutusuna (mailbox, port) gönderilir; posta kutusunun benzersiz bir kimliği vardır. İşlemler: posta kutusu oluşturma, gönderme ve alma, silme. `send(A, message)`, `receive(A, message)` (ekrandan, 00:41:30).
  - Üç prosesin bir posta kutusunu paylaşması durumunda mesajı kimin alacağı sorunu ve çözümleri.
- Eşzamanlama: bloklayan ve bloklamayan gönderme/alma, rendezvous
- Tamponlama: sıfır kapasite, sınırlı kapasite, sınırsız kapasite
- IPC sistem örnekleri
  - POSIX paylaşımlı bellek (`shm_open`, `ftruncate`, `mmap`, `shm_unlink`), Mach mesaj sistemi, Windows ALPC.
- İstemci-sunucu haberleşmesi
  - Soketler (TCP, UDP), uzaktan yordam çağrısı (RPC), pipe'lar (sıradan ve adlandırılmış), Java soketleri, URL yapısı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Paylaşımlı bellek ile mesaj geçirmenin farkı
  - Mesaj geçirmede çekirdek araya girer; güvenlidir ama kullanıcı modundan çekirdek moduna geçiş bir dezavantajdır. Paylaşımlı bellekte çekirdek yoktur; kullanımı kolaydır ama okuyanın, mesajın tamamen yazıldığından emin olması gerekir.
  - Hoca bunu ders notu alışverişine benzetti: Bölüm sekreterliğinde görevlinin kontrol ettiği bir yere bırakmak (güvenli ama belli saatlerde açık; mesaj geçirmeye uygun) ile bir odaya konmuş bir kutuya bırakmak (kolay ama güven sorunu var; paylaşımlı belleğe uygun).
- Bu yaklaşımlar yalnız işletim sistemi tasarımı için değildir
  - Kendi kullanıcı programlarımızda (veritabanı bağlantısı, çok oyunculu oyunlar, mobil ve web uygulamaları) da aynı haberleşme yaklaşımları kullanılır.
- Rendezvous
  - Hem gönderme hem alma bloklayan olduğunda buna Fransızca "randevu" sözcüğünden gelen rendezvous (randevu usulü haberleşme) denir.
- Soket = IP adresi + port numarası
  - Ağ üzerinde bir prosesi tanımlamak için PID yetmez; IP adresi ve port gerekir.

## Kısa Tekrar Notları

- Bağımsız proses: başkasını etkilemez, başkasından etkilenmez. İşbirlikçi proses: etkiler ya da etkilenir.
- IPC gerekçeleri: bilgi paylaşımı, hesaplama hızlandırma, modülerlik, kolaylık.
- İki model: paylaşımlı bellek (çekirdek dışında, prosesler yönetir) ve mesaj geçirme (çekirdek yönetir).
- Sınırlı tampon: `(in + 1) % BUFFER_SIZE == out` ise dolu, `in == out` ise boş; en fazla `BUFFER_SIZE - 1` eleman kullanılır.
- Mesaj geçirme: `send`, `receive`; doğrudan (proses adıyla) ya da dolaylı (posta kutusuyla).
- Bloklayan gönderme: alıcı alana kadar gönderen bekler. Bloklayan alma: mesaj gelene kadar alıcı bekler. İkisi birden: rendezvous.
- Tamponlama: sıfır kapasite (gönderen alıcıyı bekler), sınırlı kapasite n (bağlantı doluysa gönderen bekler), sınırsız kapasite (gönderen hiç beklemez).
- POSIX paylaşımlı bellek: `shm_open` → `ftruncate` → `mmap` → yaz/oku → `shm_unlink`.
- Sıradan pipe: tek yönlü, parent-child ilişkisi gerekir, ağ üzerinde kullanılamaz; çift yönlü haberleşme için iki pipe gerekir.
- Adlandırılmış pipe (FIFO): parent-child ilişkisi gerekmez, birden fazla proses kullanabilir.
- Soket: `IP:port` (ör. `161.25.19.8:1625`); 1024'ün altındaki portlar iyi bilinen (well-known) portlardır; `127.0.0.1` loopback adresidir.
- TCP: güvenilir, verinin eksiksiz iletildiğini garanti eder. UDP: garanti yok, ses/görüntü akışı gibi işlerde kullanılır.

## Detaylı Açıklamalar

- **İşbirlikçi proses örneği.** Hoca `fork` ile oluşturulan parent ve çocuğun haberleşmeden ayrı işler yapmasının bir eksiklik olduğunu söyledi ve şu örneği verdi: Parent bir dosyadaki verileri bir öğrenci yapısı dizisine okur ve çocuğa gönderir; çocuk diziyi sıralar ve sonucu parent'a döndürür; başka bir çocuk sıralanmış veriyi dosyaya yazar. Parent yalnız koordinasyon yapar ve veri prosesler arasında IPC ile gidip gelir. Haberleşen proseslerin parent-child olması gerekmez; mantıklı bir ilişki varsa herhangi iki proses haberleştirilebilir.
- **Sınırlı tampon için paylaşımlı bellek çözümü.** Slayttaki paylaşılan veri (ekrandan, 00:19:40):

  ```c
  #define BUFFER_SIZE 10
  typedef struct {
      . . .
  } item;

  item buffer[BUFFER_SIZE];
  int in = 0;
  int out = 0;
  ```

  Üretici (ekrandan, 00:22:30):

  ```c
  item next_produced;
  while (true) {
      /* produce an item in next_produced */
      while (((in + 1) % BUFFER_SIZE) == out)
          ; /* do nothing */
      buffer[in] = next_produced;
      in = (in + 1) % BUFFER_SIZE;
  }
  ```

  Tüketici (ekrandan, 00:23:30):

  ```c
  item next_consumed;
  while (true) {
      while (in == out)
          ; /* do nothing */
      next_consumed = buffer[out];
      out = (out + 1) % BUFFER_SIZE;
      /* consume the item in next_consumed */
  }
  ```

  Üretici `in`'in bir fazlasının mod `BUFFER_SIZE` değeri `out`'a eşitse tampon dolu demektir ve boş döngüde bekler; `out`'u tüketici değiştirince döngüden çıkar, elemanı `buffer[in]`'e yazar ve `in`'i dairesel olarak artırır. Tüketici `in == out` ise tüketecek bir şey olmadığı için bekler, değilse `buffer[out]`'tan elemanı alır ve `out`'u artırır. Slayttaki notta belirtildiği gibi bu çözüm doğrudur ama yalnız `BUFFER_SIZE - 1` eleman kullanabilir (10 elemanlı dizide en fazla 9).
- **Haberleşme yönü.** Simplekste mesaj yalnız A'dan B'ye gider. Yarı çift yönlüde (half duplex) iki yön de vardır ama aynı anda değil; A gönderirken B beklemek zorundadır. Tam çift yönlüde (full duplex) iki taraf aynı anda gönderebilir. Mesaj geçirmede kurulan bağlantının tek yönlü mü çift yönlü mü olacağı bu sınıflandırmayla ilgilidir.
- **Posta kutusunu üç proses paylaşırsa.** P1, P2 ve P3 bir A posta kutusunu paylaşsın; P1 gönderir, P2 ve P3 alır. Mesajı kim alacaktır? Mesaj alınınca silinmiyorsa ikisi de alabilir; yalnız birinin alması isteniyorsa sorun çıkar. Çözümler: bir bağlantının en fazla iki prosesle ilişkilendirilmesine izin vermek (en katı yaklaşım; etkileşimi düşürür), aynı anda yalnız bir prosesin `receive` yapmasına izin vermek ya da alıcıyı sistemin keyfi seçmesi (örneğin önce gelen ya da önceliği yüksek olan) ve göndericiye mesajın kimin tarafından alındığını bildirmek.
- **Bloklayan ve bloklamayan.** Bloklayan (blocking) eşzamanlı (senkron), bloklamayan (non-blocking) eşzamansız (asenkron) sayılır. Bloklayan göndermede gönderen, mesaj alınana kadar bekler; bloklayan almada alıcı, mesaj gelene kadar bekler. Bloklamayan göndermede gönderen mesajı gönderip devam eder; bloklamayan almada alıcı geçerli bir mesaj ya da boş (null) mesaj alır. Hoca, başka bir prosesin yazdığı bir dosyadan okurken `if` kontrollerinin ve istisna yönetiminin neden gerektiğini bloklamayan almayla ilişkilendirdi: orada bir mesaj olduğu yüzde yüz garanti edilemez. Dört kombinasyon vardır; ikisi de bloklayansa rendezvous olur.
- **POSIX paylaşımlı bellek.** Slayttaki üretici (ekrandan, 01:07:00) `shm_open(name, O_CREAT | O_RDWR, 0666)` ile "OS" adlı paylaşımlı bellek nesnesini oluşturur, `ftruncate(shm_fd, SIZE)` ile boyutunu 4096 bayt yapar, `mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0)` ile belleğe eşler, `sprintf` ile önce "Hello", işaretçiyi `strlen` kadar ilerletip "World!" yazar. Tüketici (ekrandan, 01:09:30) aynı adla `shm_open(name, O_RDONLY, 0666)` yapar, `PROT_READ` ile eşler, `printf("%s", (char *)ptr)` ile okur ve `shm_unlink(name)` ile nesneyi kaldırır. Nesnenin adı iki tarafta aynı olmalıdır; farklı olursa çağrılar hata (−1) döndürür. Ajan iki programı `<sys/mman.h>` ve `<unistd.h>` ekleyerek scratchpad'de `gcc -Wall` ile derleyip art arda çalıştırdı; tüketici `HelloWorld!` yazdı.
- **Mach ve Windows.** Mach'ta sistem çağrıları da mesajdır; her görev oluşturulurken Kernel ve Notify adlı iki posta kutusu verilir; mesajlar `msg_send`, `msg_receive` ve `msg_rpc` çağrılarıyla aktarılır. Posta kutusu doluysa gönderen süresiz bekleyebilir, en fazla n milisaniye bekleyebilir, hemen dönebilir ya da mesajı geçici olarak önbelleğe alabilir. Windows'ta mesaj geçirme merkezli ALPC (Advanced Local Procedure Call) yalnız aynı sistemdeki prosesler içindir; posta kutusuna benzeyen portlar kullanılır: istemci sunucunun bağlantı portuna (connection port) istek gönderir, sunucu iki özel haberleşme portu döndürür ve haberleşme bunlar üzerinden yapılır.
- **Pipe'lar.** Sıradan pipe (ekrandan, 01:18:30) üretici-tüketici biçiminde çalışır: üretici bir uca yazar, tüketici diğer uçtan okur; tek yönlüdür ve parent-child ilişkisi gerektirir. Her iki tarafta `fd[0]` ve `fd[1]` olmak üzere iki dosya tanımlayıcısı vardır; yazan taraf okuma ucunu, okuyan taraf yazma ucunu kapatır. Windows'ta bunlara anonim pipe (anonymous pipe) denir. Çift yönlü haberleşme için iki pipe gerekir. Parent-child ilişkisi olmadan haberleşmek için adlandırılmış pipe (named pipe, FIFO) kullanılır; birden fazla proses aynı anda kullanabilir.

  > **Ders sonrası not:** Hoca `fd[0]`'ın yazma, `fd[1]`'in okuma ucu olduğunu söyledi ve standart dosya tanımlayıcılarını "0 yazma, 1 okuma, 2 hata" diye andı. Doğrusu tersidir: pipe'ta `fd[0]` okuma (read end), `fd[1]` yazma (write end) ucudur; standart tanımlayıcılarda 0 standart girdi (stdin), 1 standart çıktı (stdout), 2 standart hatadır (stderr).

- **Soketler.** Soket bir haberleşme uç noktasıdır (endpoint) ve IP adresi ile port numarasının birleşimidir (ekrandan, 01:28:30). Slayttaki örnekte `161.25.19.8:1625` soketi 161.25.19.8 makinesindeki 1625 numaralı portu gösterir. Haberleşme bir soket çifti arasında olur. Hoca telefondaki uygulamalara gelen verinin port üzerinden doğru uygulamaya yönlendirildiğini, isteği gönderenin kendi IP ve port adresini de gönderdiği için cevabın ona döndüğünü anlattı (eski mektuplardaki iade adresine benzetti). Web için 8080 gibi portlar da kullanılır.
- **RPC ve Java soketleri.** Uzaktan yordam çağrısı (RPC), ağ üzerindeki haberleşmeyi soyutlayan bir programlama kolaylığıdır: kod bir fonksiyon çağırır, haberleşme işleri arka planda yapılır. Hoca bunu çok oyunculu oyunlarda kullanıldığını örnekledi. Java'da tarih sunucusu (date server) örneğinde bir `ServerSocket` nesnesi oluşturulur, bağlantılar sürekli dinlenir ve istemciye tarih bilgisi yazılır.
- **URL yapısı.** Hoca bir web sitesinde URL sözdizimini gösterip bunun IPC'nin web uygulamalarına özgü bir soyutlaması olduğunu söyledi: şema (`http`, `https`, `ftp` gibi protokol) ve `://`, ana bilgisayar adı (IP adresinin yerine), `:` ile port (HTTP için genellikle 80; yazılmazsa varsayılan kullanılır), yol (path), `?` ile başlayan sorgu dizgisi (parametreler `&` ile ayrılır) ve `#` ile parça tanımlayıcı (fragment identifier). Arka planda bir TCP soketi kurulur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
