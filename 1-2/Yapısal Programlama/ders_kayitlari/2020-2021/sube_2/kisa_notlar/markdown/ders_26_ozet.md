# Ders 26 Çalışma Özeti

## Genel Konular

- Makefile ile çok dosyalı C projesini derleme
  - Örnek proje üç dosyadan oluşur: `main` fonksiyonunu içeren `uygulama.c`, `square` fonksiyonunun prototipini içeren başlık dosyası `func.h` ve fonksiyonun gövdesini içeren `square.c` (ekrandan, 00:10:00).
  - `uygulama.c` içinde `int num=9;` tanımlanır, `printf("%d\n",square(num));` ile fonksiyon çağrılır; fonksiyonun kendisi bu dosyada yazılmaz, başlık dosyası sayesinde görülür (ekrandan, 00:10:00).
  - Başlık dosyasına fonksiyon prototipleri, struct tanımları ve makro tanımları yazılır; fonksiyon gövdesi (implementasyon) yazılmaz.
  - Derleme iki adımlıdır: her `.c` dosyası `gcc` ile ayrı ayrı nesne dosyasına (`uygulama.o`, `square.o`) derlenir, sonra nesne dosyaları bağlanarak çalıştırılabilir dosya (`program`) oluşturulur. Makefile bu kuralları bir kez yazıp tek komutla çağırmayı sağlar.
  - Dev-C++ gibi bir IDE de arka planda bu adımları (ve proje için bir makefile'ı) kendisi oluşturur; derleme günlüğünde `gcc` komutu görülür.
  <!-- BELİRSİZ: Makefile'ın satırları kareye girmedi; hedef ve bağımlılıkların tam yazımı altyazıdan kurulmuştur. -->
- Paralel çalıştırma fikri: dizi toplama örneği
  - İki dizinin karşılıklı elemanları toplanırken bir elemanın toplanması diğerini beklemek zorunda değildir.
  - Döngüyü açarak her adımda iki eleman toplamak (`d1[i]+=d2[i]; d1[i+1]+=d2[i+1];`) tekli döngüden biraz daha hızlı çalışabilir (ekrandan, 00:20:00).
  - Matris çarpımında da satır-sütun çarpımları birbirinden bağımsızdır; bu tür işler thread'lere bölünmeye uygundur.
- Program, proses ve thread
  - Program: C/C++ gibi bir dilde yazılmış metin (komutlar, fonksiyonlar). Derlenip bağlanıp belleğe yüklenince çalıştırılabilir hale gelen ve çalışan haline proses denir (ekrandan, 00:25:00).
  - İşletim sistemi her prosese bir kimlik (PID) verir. Görev Yöneticisi'nin Ayrıntılar sekmesinde proseslerin adı, PID'i, durumu (çalışıyor, bekliyor, sonlanmış), CPU ve bellek kullanımı, temel önceliği ve thread sayısı görülebilir.
  - Thread: proses içindeki bir yürütme akışıdır. Her proseste en az bir akış (ana thread) vardır; `main`'den başlayıp `main`'in sonuna kadar tek koldan giden program tek thread'li bir prosestir.
- Birçok proses tek işlemciyi nasıl paylaşır?
  - Saat hızı: 2,4 GHz saniyede $2{,}4\times10^9$ saat darbesi demektir; işlemci her darbe kenarında bir işlem adımı yapar (ekrandan, 00:25:00).
  - Çok çekirdek: her çekirdek bir komutu getirme (fetch), çözme (decode), yürütme (execute), geri yazma (write back) adımlarını ayrı yürütür; 4 çekirdek aynı anda 4 ayrı akışı işleyebilir. Ama proses sayısı çekirdek sayısından çok fazladır.
  - Zamanlama (scheduling) ve bağlam değiştirme (context switching): bir proses belli bir süre çalışır, durumu (registerlar, kaldığı yer) belleğe kaydedilir, sıradaki prosese geçilir; geri gelindiğinde kaldığı yerden devam eder. Zaman paylaşımı esasına dayanır.
  - Süpermarket benzetmesi: tek kasa (işlemci), dört müşteri (proses). P1=10, P2=4, P3=8, P4=6 birimlik işi olan müşterilerden sırayla 2'şer birim alınırsa çıkış sırası P2, P4, P3, P1 olur (ekrandan, 00:30:00).
- Thread'lerin kullanım alanları
  - Grafik arayüzler, Word'de yazarken arka planda yazım denetimi yapılması, web tarayıcısında birbirini etkilemeyen sekmeler.
  - Gerçek zamana yakın sistemler: bir yandan girdi alıp hızla çıktı üretmesi gereken programlar.
  - Kantin benzetmesi: fiş kuyruğu, yemek kuyruğu ve çöp/iade kuyruğu birbirini beklemeden eş zamanlı yürür.
  - Tek çekirdekte thread'ler gerçekte sırayla çalışır, geçişler çok hızlı olduğu için eş zamanlı görünür; buna sanal paralellik denir.
- Proses ve thread farkı
  - Bir proses birden çok thread içerebilir; thread proses içermez.
  - Prosesin bellek düzeni: komutlar (instruction), stack, heap (`malloc` ile ayrılan alan), statik ve global değişkenler, ilk değer verilmemiş veri, ilk değer verilmiş veri (ekrandan, 00:40:00). Bir proses başka bir prosesin adres alanına erişemez; thread'ler aynı prosesin alanını paylaşır.
  - Açık dosya tanımlayıcıları (stdin, stdout, stderr ve açılan dosyalar) her prosese ayrıdır, aynı prosesin thread'leri ise bunları ortak kullanır.
  - Prosesler arası eşzamanlama çekirdek (kernel) tarafından yapılır; thread'ler arası eşzamanlama büyük ölçüde programcının koduna bırakılır.
  - Thread'ler arası bağlam değiştirme, prosesler arasındakinden daha hızlıdır. Prosesler ancak prosesler arası iletişim (IPC) yöntemleriyle haberleşir; thread'ler ortak bellek alanı üzerinden kolayca haberleşir.
  - Proseslerde `fork` ile bir prosesin kopyası oluşturulabilir.
- Thread'lerle ilgili sorunlar
  - Hata ayıklamak zordur: bir thread'in nerede kesilip nerede devam ettiği önceden bilinmez.
  - Aşırı sayıda thread, bölmenin getirdiği ek yük yüzünden performansı düşürebilir.
  - Asıl sorun eşzamanlamadır (senkronizasyon): hangi thread'in ne zaman, ne kadar çalışacağı ve ortak değişkene nasıl erişeceği.
  - Kilitlenme (deadlock): ortak kaynağı (değişken, CPU, bellek bölgesi) bekleyen thread'lerin birbirini bekleyip hiç ilerleyememesi. Dört yönlü kavşakta araçların birbirinin yolunu tıkaması örneği (ekrandan, 00:50:00); çözüm kaynakların serbest bırakılmasıdır.
  - Açlık (starvation): eşzamanlama kötü yapıldığı için bir thread'e (ya da prosese) hiç sıra gelmemesi; diğerleri bitse bile o thread tamamlanamaz.
- POSIX thread kütüphanesi (`pthread.h`)
  - C dilinde thread'ler `#include <pthread.h>` ile kullanılır; her thread'in benzersiz bir kimliği `pthread_t` türündedir.
  - `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);` (ekrandan, 00:55:00)
    - `thread`: yeni thread'in kimliğinin yazılacağı `pthread_t` değişkeninin adresi.
    - `attr`: thread özellikleri; `NULL` verilirse varsayılan özellikler kullanılır.
    - `start_routine`: thread'in çalıştıracağı fonksiyonun işaretçisi; fonksiyon `void *` alır, `void *` döndürür.
    - `arg`: fonksiyona gönderilecek `void *` argüman.
    - Dönüş değeri: başarıda 0, değilse bir hata numarası.
  - `pthread_exit(NULL)`: thread'i sonlandırır; `NULL` yerine bir değer verilirse bu değer thread'i bekleyene döner.
  - `pthread_join(tid, NULL)`: çağıran thread, `tid` thread'i bitene kadar bekler.
  - Linux'ta `gcc` ile derlerken `-lpthread` (ya da `-pthread`) ile kütüphane bağlanmalıdır.
- Derste yazılan örnekler
  - Tek thread: `hello` fonksiyonu gelen `void *` argümanı `char *`'a çevirip yazar, 5 saniye bekler ve `pthread_exit` ile çıkar (ekrandan, 01:15:00).
  - İki thread ve `join`: `"hello thread"` ve `"hello thread_2"` ile iki thread oluşturulur, `join`'den önceki `printf` ile thread çıktılarının sırası önceden kestirilemez (ekrandan, 01:20:00).
  - Döngüyle birden çok thread oluşturma; fonksiyon içindeki `static` sayaç ve global sayaç ile thread'lerin ortak değişkeni paylaştığının gösterilmesi (ekrandan, 01:25:00).
  - Thread'e struct gönderme: `struct args { char* name; int age; }` türündeki veri `(void *)` olarak gönderilir, fonksiyonda `((struct args*)input)->name` biçiminde geri çevrilir (ekrandan, 01:30:00).
  - Farklı thread'lerin farklı fonksiyonlarla (`hello`, `hello2`) çalıştırılabilmesi.
- Paylaşılan değişken, atomiklik ve kilit
  - `A = A + 1` gibi tek C satırı birden çok makine komutuna (belleği registera al, arttır, belleğe yaz) karşılık gelir; makine komutu bölünemez ama C satırı bölünebilir.
  - Bir thread `A = A + 1`, diğeri `A = A - 1` yaparken komutlar araya girerse sonuç tutarsız olabilir. Bu yüzden ortak kaynağa erişen işlemler atomik (bölünemez) yapılmalıdır.
  - Kilit (lock) mekanizması: kilidi alan thread ortak değişken üzerinde işlem yapar, diğerleri bekler, işlem bitince kilit bırakılır. Toplulukta yalnız mikrofonu olanın konuşması benzetmesi. Banka hesabına para yatırıp çeken thread'ler örneği gösterildi (ekrandan, 01:40:00).
  - Karşılıklı dışlama (mutex) ve kilitlenmeden kaçınma bu sorunlar için kullanılan mekanizmalardır.
- Yemek yiyen filozoflar problemi
  - Yuvarlak masada her filozofun iki yanında birer çatal vardır; yemek için hem sağdaki hem soldaki çatalı alması gerekir. Komşu filozoflar aynı anda yiyemez.
  - Her filozof bir thread, her çatal bir mutex ile modellenir; thread'ler döngüyle `pthread_create` ile başlatılıp `pthread_join` ile beklenir, sonunda mutex'ler `pthread_mutex_destroy` ile yok edilir (ekrandan, 01:45:00).
- Yapısal programlamadan nesneye yönelik programlamaya
  - Yapısal programlama: değişkenlerin baştan tanımlanması, programın adım adım sırayla yazılması, gereken yerde fonksiyonlarla modüler hale getirilmesi.
  - Nesneye yönelik programlamada (C++, Java, C#) struct'ın gelişmiş hali olan sınıflar (class) vardır. Struct yalnız özellik (veri) tutar; sınıfa bunlara ek olarak davranış (metot) da eklenir.
  - Örnek: `Room` sınıfından nesne üretilir ve `room1.calculateArea()` gibi bir metot çağrılınca nesnenin kendi üye değerleri kullanılır. Nesneler arasında bire bir, bire çok, çoka çok ve kalıtımla kurulan genel-özel ilişkiler tanımlanabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makefile'ın temel yapısını bilmek
  - Gömülü sistemler gibi yalnız derleyicinin kurulu olduğu, IDE'nin olmadığı ortamlarda proje makefile ile derlenir. "IDE yok, yalnız derleyici var; projeyi tek komutla nasıl derlersiniz?" sorusu iş görüşmelerinde sorulabiliyor; cevap makefile yazmaktır.
- Thread fonksiyonu baştan başlamaz
  - Sık yapılan yanılgı: T1 kesilip T2 çalıştıktan sonra T1'e dönüldüğünde fonksiyonun baştan başladığını sanmak. Thread kaldığı yerden, değişkenlerinin son değerleriyle devam eder. Bu bilgiler proses içindeki thread'e ait alanda saklanır.
  - T1 ve T2'yi başlatmak fonksiyon çağrısına benzese de iç içe fonksiyon çağrısı değildir; iki bağımsız akıştır.
- Thread fonksiyonunun imzası
  - Thread fonksiyonu `void *` alır ve `void *` döndürür; böylece her türden veri gönderilebilir. İçeride doğru türe çevirme (cast) gerekir.
- Global değişken kullanmayın uyarısının asıl nedeni
  - Birden çok thread aynı global değişkene erişirse sonuç tutarsız olabilir. Atomiklik ve eşzamanlama burada önem kazanır.
- Thread çalışma sırası kestirilemez
  - Aynı program art arda çalıştırıldığında çıktı sırası değişebilir; yalnız `join` ile beklenen satırın sırası kesindir.
- El çevirme benzetmesi
  - İki eli zıt yönlerde gerçekten aynı anda çevirmek çoklu işlemeye (multiprocessing), biri bitince hemen diğerine geçerek aynı anda yapıyormuş gibi görünmek çoklu thread'e (sanal paralellik) benzetildi.
- C konularıyla bağlantı
  - Thread'e struct parametre olarak gönderilir, thread'in çalışacağı fonksiyon fonksiyon işaretçisiyle verilir, thread'den değer döndürülür, statik değişkenler kullanılır, dosya işlemleri eklenebilir; böylece eş zamanlı çalışan programlar tasarlanabilir.

## Kısa Tekrar Notları

- Başlık dosyası: prototip, struct ve makro tanımları; gövde `.c` dosyasında.
- Derleme: `.c` → `.o` (derleme), `.o` dosyaları → çalıştırılabilir dosya (bağlama). Makefile bu adımları kurallaştırır.
- Program yazılı metindir; çalışan program prosestir; proses içindeki yürütme akışı thread'dir.
- Zamanlama + bağlam değiştirme = birçok proses tek işlemciyi zaman paylaşımıyla kullanır.
- Tek çekirdekte thread'ler sırayla çalışır, eş zamanlı görünür (sanal paralellik).
- Prosesler adres alanını paylaşmaz; thread'ler aynı prosesin belleğini ve dosya tanımlayıcılarını paylaşır.
- Thread sorunları: zor hata ayıklama, aşırı thread yükü, eşzamanlama; eşzamanlama hataları: deadlock ve starvation.
- `pthread_create(&tid, NULL, fonk, arg)` başarıda 0 döndürür; `pthread_exit(deger)`, `pthread_join(tid, &donus)`.
- Thread fonksiyonu: `void *fonk(void *arg)`.
- Linux'ta derleme: `gcc dosya.c -lpthread`.
- `A = A + 1` atomik değildir; ortak değişkene erişim kilit/mutex ile korunur.
- Yemek yiyen filozoflar: filozof = thread, çatal = mutex.
- Struct yalnız veri tutar; sınıf veri ve metot tutar.

## Detaylı Açıklamalar

- **Makefile örneği.** Proje `uygulama.c`, `func.h` ve `square.c` dosyalarından oluşur. `uygulama.c`'nin içeriği ekranda şöyledir (ekrandan, 00:10:00):

```c
#include <stdio.h>
#include "func.h"

int main(){
    int num=9;

    printf("Program started!\n");
    printf("%d\n",square(num));
    printf("Program successfully ended\n");

    return 0;
}
```

  `func.h` yalnız `square` fonksiyonunun prototipini, `square.c` ise gövdesini içerir. Makefile'da `program` hedefinin `uygulama.o` ve `square.o`'dan oluşacağı, bu iki nesne dosyasının da `gcc` ile kendi `.c` dosyalarından derleneceği yazılır; son kural iki nesne dosyasını bağlayıp `program`'ı üretir. Tek dosyalı bir programda bile IDE önce nesne dosyası sonra çalıştırılabilir dosya üretir; dosya sayısı 30-40'a çıkınca bu komutları elle yazmak uzar, makefile bu yükü kaldırır. Büyük projelerde derleyici optimizasyon seviyeleri gibi pek çok ayrıntılı parametre eklenir.

  > Bu notu hazırlayan ajan, `func.h` (yalnız `int square(int x);`) ve `square.c` (`return x*x;`) dosyalarını kendisi yazarak programı iki adımda (`gcc -Wall -c` ile nesne dosyaları, sonra bağlama) derledi; çıktı `Program started!`, `81`, `Program successfully ended` oldu. `square.c`'nin gövdesi derste gösterilmedi.

- **Proses zamanlaması.** İşletim sistemi bir prosesi işlemciye alır, belli bir süre çalıştırır, sonra o ana kadarki durumunu (registerlar, bayraklar, kaldığı yer) belleğe kaydedip diğer prosese geçer. Bu geçişe bağlam değiştirme denir; özyinelemeli fonksiyonlarda çağrı bilgilerinin belleğe kaydedilmesine benzer. Süpermarket örneğinde kasiyer herkese adil davranmak için her müşteriden 2'şer birim alır. Başlangıç: P1=10, P2=4, P3=8, P4=6. Birinci tur sonunda P1=8, P2=2, P3=6, P4=4; ikinci turda P2 biter; üçüncü turda P4; dördüncü turda P3; beşinci turda P1 biter. Kasiyer isterse önce uzun işi olanı bitirip diğerlerini bekletebilir; bu tür kararları işletim sistemi verir ve bir prosese çok öncelik verilmişse onu bekletebilir.

- **Proses ve thread bellek ilişkisi.** Proses çalıştırılınca bellekte ona bir alan ayrılır. İşletim sistemi heap bölgesini büyütebilir; stack genellikle sabittir. Proses başka bir prosesin alanına erişemez. Thread'ler aynı proses alanının parçalarıdır; bu yüzden ortak değişkenler ve açık dosyalar üzerinden haberleşebilirler. Bu kolaylık eşzamanlama sorumluluğunu da getirir.

- **Kilitlenme ve açlık.** Deneyimsiz bir trafik polisi kavşağı düzenlemeye çalışırken kilitleyebilir: dört yönden gelen araçlar birbirinin yolunu tıkar, kimse kıpırdayamaz. Çözüm araçların bir kısmının geri çekilmesi, yani kaynağın bırakılmasıdır. Kilitlenen bir programı kapatıp yeniden açmak da kaynakları bırakmanın kaba bir yoludur. Açlıkta ise eşzamanlama kötü yapıldığı için bir thread'e hiç sıra gelmez; işletim sistemi kitaplarında, kapatılmak istenen eski bir bilgisayarda yıllardır sırası gelmemiş bir prosesin bulunduğu anlatılır.

- **İlk thread örneği** (ekrandan, 01:15:00):

```c
#include <stdio.h>
#include <pthread.h>
#include <time.h>
void *hello(void *input){
    printf("%s\n",(char*)input);
    sleep(5);
    pthread_exit(NULL);
}

int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,hello,"hello thread");
    printf("Returned to main");
    return 0;
}
```

  Bu programda iki thread vardır: `main`'den başlayan ana thread ve `pthread_create` ile oluşturulan thread. Derste ilk çalıştırmada önce `main`'deki mesaj, sonra thread'in mesajı yazıldı. `sleep` thread'i bekletir; bu sırada başka bir thread'e sıra gelebilir. `main`'in thread'in bitmesini beklemesi için `pthread_join(tid,NULL);` eklenir.

- **İki thread ve join** (ekrandan, 01:20:00): `pthread_t tid, tid2;` tanımlanır, iki thread `"hello thread"` ve `"hello thread_2"` argümanlarıyla oluşturulur, ardından `printf("After thread call\n");`, `pthread_join(tid,NULL);` ve `printf("Returned to main");` gelir. Derste çıktıda bazen önce `After thread call`, bazen önce `hello thread` görüldü; `Returned to main` ise `join` yüzünden her zaman en sonda yazılır. Hoca önce ikinci thread'in, sonra birincinin beklenmesini de gösterdi.

- **Thread'e struct gönderme** (ekrandan, 01:30:00):

```c
struct args {
    char* name;
    int age;
};

void *hello(void *input) {
    printf("name: %s\n", ((struct args*)input)->name);
    printf("age: %d\n", ((struct args*)input)->age);
}

int main() {
    struct args *Allen = (struct args *)malloc(sizeof(struct args));
    char allen[] = "Allen";
    Allen->name = allen;
    Allen->age = 20;

    pthread_t tid;
    pthread_create(&tid, NULL, hello, (void *)Allen);
    pthread_join(tid, NULL);
    return 0;
}
```

  > Bu kod ekrandaki halinin başındaki `#include` satırları (`stdio.h`, `stdlib.h`, `pthread.h`) eklenerek Linux'ta `gcc -Wall -pthread` ile derlendi; `hello` fonksiyonunda `return` olmadığı için `control reaches end of non-void function` uyarısı verdi. Sonuna `return NULL;` eklenince uyarısız derlendi ve `name: Allen`, `age: 20` yazdı.

- **Atomiklik.** `A` ortak bir değişken ve değeri 10 olsun. Bir thread `A = A + 1`, diğeri `A = A - 1` çalıştırır. Her satır yaklaşık "belleği registera al, registerı değiştir, registerı belleğe yaz" komutlarına karşılık gelir. Birinci thread `A`'yı registera aldıktan sonra kesilip ikinci thread de `A`'yı (hâlâ 10) okursa, iki thread kendi hesapladığı değeri yazar ve son yazanın değeri kalır. Beklenen sonuç 10'dur, ama bu araya girme yüzünden 9 ya da 11 çıkabilir. Bu yüzden ortak kaynağa erişen işlemlerin bölünemez olması gerekir.

  > **Ders sonrası not:** Hoca anlatımın sonunda `A`'nın değerinin "hâlâ 10" görüneceğini söyledi. Anlattığı araya girme senaryosunda doğru sonuç 9 ya da 11'dir (bir güncelleme kaybolur); 10 ancak işlemler sırayla yapılırsa elde edilir.

- **Kaynak.** Hoca derste bir üniversitenin sistem programlama dersinin çevrim içi "Unit 9: Threads" notlarını açıp oradaki paylaşılan değişken (`shared`), banka hesabı ve yemek yiyen filozoflar örneklerini gösterdi; thread'den değer döndürme, `getpid`/`getppid` ile proses kimliği alma (Unix'e özgü olduğu için Windows'ta çalışmadığını söyledi) ve thread havuzu örnekleri de buradadır.

- **Ders sonrası notlar**
  - Hoca 2,4 GHz için periyodu "2,4 çarpı 10 üzeri eksi 9 saniye" diye söyledi; doğrusu $T = 1/(2{,}4\times10^9)\approx 4{,}17\times10^{-10}$ saniye (yaklaşık 0,42 ns).
  - Tahtadaki döngü `for(i=0;i<N/2;i++)` içinde `d1[i]` ve `d1[i+1]` toplanıyor; `i` birer arttığı için elemanlar iki kez toplanır. Doğrusu (N çift iken) `for(i=0;i<N;i+=2){ d1[i]+=d2[i]; d1[i+1]+=d2[i+1]; }` biçimindedir.
  - Hoca proses bellek düzenini "Proses Kontrol Bloğu" diye adlandırdı. Büyük olasılıkla kastettiği prosesin adres alanıdır; işletim sistemi derslerinde proses kontrol bloğu (PCB), işletim sisteminin her proses için tuttuğu (PID, durum, registerlar, açık dosyalar gibi bilgileri içeren) veri yapısının adıdır.
  - Ekrandaki kodda `sleep` için `<time.h>` eklenmiş. Linux'ta `sleep` `<unistd.h>` içindedir; `<time.h>` ile `gcc -Wall` `implicit declaration of function 'sleep'` hatası verdi. Windows'taki derleyicide büyük olasılıkla `pthread.h` üzerinden tanımlı geldiği için derste sorun çıkmadı.
  - Açlık hikayesinde hoca 80'li yıllar ve 20 yıl dedi; işletim sistemi kitaplarında anlatılan hikaye büyük olasılıkla 1973'te kapatılan bir IBM 7094'te 1967'den beri bekleyen bir prosestir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
