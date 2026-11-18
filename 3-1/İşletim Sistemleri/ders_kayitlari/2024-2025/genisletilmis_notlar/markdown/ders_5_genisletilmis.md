# Ders 5 Genişletilmiş Notu: Uygulama: Proses Oluşturma ve Yönetimi (fork, exec, exit, atexit, wait, kill)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulamanın Kapsamı
- 2. Program, Proses ve Proses Tablosu
- 3. fork ile Proses Oluşturma
- 4. getpid, getppid ve fork'un Dönüş Değeri
- 5. Parent ile Çocuğa Farklı İş Yaptırmak
- 6. Fork Alıştırma Sorusu
- 7. exec ile Başka Bir Program Çalıştırmak
- 8. Proses Sonlandırma: exit, atexit ve return
- 9. Zombi Prosesler
- 10. wait ile Eşzamanlama
- 11. kill ile Proses Sonlandırma
- 12. Ders Sonundaki Sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulamanın Kapsamı

Dersin başındaki kısa bir duyurudan sonra (idari bilgiler nota alınmadı) ders bir araştırma görevlisinin yürüttüğü uygulamayla devam etti. Hoca, görevlinin önceki derste görülen proseslerin oluşturulması ve farklılaştırılması (differentiation) konusunda, yani `fork` ve `exec` sistem çağrılarıyla ilgili farklı program uygulamaları yapacağını söyledi.

Görevli önceki uygulamada kabuk (shell) programlamanın görüldüğünü hatırlattı. Bu ikinci uygulamada proseslerin tanımı, oluşturulması, farklılaştırılması, yönetimi, sonlandırılması ve eşzamanlanması (senkronizasyonu) ele alındı. Örnekler bir sanal makinedeki Linux'ta, ilgili klasördeki C dosyaları `gcc` ile derlenip çalıştırılarak gösterildi; görevli farklı bir C derleyicisi de kullanılabileceğini belirtti.

## 2. Program, Proses ve Proses Tablosu

Prosesi tanımlamadan önce programı tanımlamak gerekir. Program diskte bulunan bir yapıdır. Proses ise bu programın çalıştırılmış bir örneğidir (instance); CPU register'ları, bellek ve çeşitli alanlarıyla birlikte programın çalışan hâlidir.

Prosesler işletim sisteminin **proses tablosu** (process table) adı verilen bir yapısında tutulur. Tablonun her satırına **proses tanımlayıcısı** (process descriptor) denir. Proses tanımlayıcısında prosesin kimliği (ID), durumu, kullandığı kaynaklar, çalıştıracağı kod, bulunduğu dizin, argümanları, verisi, sinyalleri ve hangi dosyalarda işlem yaptığı gibi bilgiler bulunur.

İşletim sistemi bir prosesi şöyle oluşturur: Önce proses tablosuna prosesin oluşturulduğuna dair bir satır, yani içindeki bilgilerle bir proses tanımlayıcısı yazar. Sonra program kodunu diskten okur. Kullanıcı tarafında ise bu iş iki sistem çağrısıyla yapılır: `fork` ve `exec`.

## 3. fork ile Proses Oluşturma

Bir program çalışmaya başladığında onu çalıştıran ana bir proses, yani parent proses vardır; bu her programda böyledir. Program çalışırken ana prosesin yanında bir proses daha oluşsun ve işlemeye devam etsin istersek `fork` sistem çağrısını kullanırız. `fork` çağrıldıktan sonra parent prosesin dışında yeni bir proses oluşur: PID'si farklı, diğer alanları tamamen aynı olan bir proses. Buna **child proses** denir. Örneğin parent'ın PID'si 1001 ise çocuğunki 1002 olabilir.

Parent proses programı yukarıdan aşağı çalıştırırken `fork` satırına gelince bir çocuk oluşturur ve program artık iki farklı kolda ilerler.

Slayttaki ilk örnek `fork1.c` (ekrandan, 00:22:30): `main` içinde önce `printf("Message before fork\n")`, sonra `fork()`, sonra `printf("Message after fork\n")` ve `return 0` vardır. Slayttaki not: "Message after fork is printed twice". Önce parent proses programı çalıştırır ve "Message before fork" mesajını yazar. `fork`'a gelince program iki dala ayrılır; `fork`'tan sonraki `printf`'i hem parent hem çocuk çalıştırır, bu yüzden "Message after fork" iki kez yazılır. Görevli örneği derleyip çalıştırdı ve aynı çıktıyı gösterdi.

> **Ders sonrası not:** Görevli "önce parent işini yapıp bitirecek, sonra child başlayacak; child parent'ı bekler" dedi ve bunu "önemli" diye vurguladı. Bu doğru değildir: `fork`'tan sonra parent ile çocuktan hangisinin önce çalışacağına zamanlayıcı karar verir ve `wait` gibi bir eşzamanlama yoksa sıra bilinemez. Teorik derste hoca da bu sıranın değişebileceğini vurgulamıştı. Ajanın denemesinde (Bölüm 6) çocuk proseslerin çıktısı parent'tan önce de geldi.

## 4. getpid, getppid ve fork'un Dönüş Değeri

Proseslerin kimliklerini öğrenmek için iki yararlı fonksiyon vardır:

- **`getpid()`** (get process ID): o satırı, örneğin o `printf`'i çalıştıran prosesin PID'sini döndürür.
- **`getppid()`** (get parent process ID): o prosesi oluşturan parent prosesin PID'sini döndürür.

Akla şu soru gelebilir: Programı çalıştıran ana proses zaten parent değil mi; onun parent'ı nedir? Onun parent'ı kabuktur (shell), yani işletim sisteminin parent prosesi de oluşturan kabuk yapısıdır; `getppid()` onun PID'sini döndürür.

`fork` da bir değer döndürür. Parent'ta `fork` çağrıldığında bir çocuk oluşturur ve **oluşturulan çocuğun PID'sini** döndürür. Çocukta ise **0** döndürür; görevli bunu "çocuk zaten oluşturulmuş bir şey, onun `fork`'ta bir değeri yok" diye açıkladı.

Slayttaki `fork2.c` (ekrandan, 00:26:30):

```c
#include <stdio.h>
#include <unistd.h>

int main ( void )  {

    int forkResult;

    printf("process id: %i - parent process id: %i\n",getpid(),getppid());
    forkResult = fork();
    printf("process id: %i - result : %d - parent process id: %i\n",getpid(),forkResult,getppid());

    return 0;
}
```

Slayttaki çıktı:

```text
process id: 2703 - parent process id: 2512
process id: 2703 - result : 2704 - parent process id: 2512
process id: 2704 - result : 0 - parent process id: 2703
```

Adım adım:

- İlk satırı yalnız parent yazar: kendi PID'si 2703, parent'ı (kabuk) 2512.
- `fork`'tan sonra parent kendi PID'sini (2703), `fork` sonucunu yani çocuğun PID'sini (2704) ve kabuğun PID'sini (2512) yazar.
- Çocuk kendi PID'sini (2704) yazar; bu, parent'ın `fork`'tan aldığı değerle uyuşur. Çocuğun `fork` sonucu 0'dır, çünkü o bir şey oluşturmadı. Çocuğun parent PID'si 2703'tür ve parent'ın PID'siyle uyuşur.

Görevlinin canlı çalıştırmasında PID'ler farklıydı (kabuk için 2491 gibi bir değer görüldü), ama ilişkiler aynıydı.

> **Hocanın vurgusu:** Görevli bu soruda bilinmesi gerekenleri şöyle özetledi: `getpid()` satırı çalıştıran prosesin PID'sini, `getppid()` parent prosesin PID'sini, `fork` ise parent'ta çocuğun PID'sini döndürür; çocukta `fork` sonucu 0'dır.

## 5. Parent ile Çocuğa Farklı İş Yaptırmak

Önceki iki örnekte parent ile çocuk aynı işi yapıyordu: çocuk oluşturuldu ama ikisi de programı aynı biçimde devam ettirdi, yalnız değişkenlerin değerleri farklıydı. İkisine farklı iş yaptırmak için `fork`'un dönüş değerine `if` ile bakılır: değer 0 ise çocuk, değilse parent o kola girer.

Slayttaki `fork3.c` (ekrandan, 00:29:30):

```c
printf("(%i) Parent does something...\n", getpid());

if(fork())  {  // Parent
    printf("(%i) Parent do completely different stuff\n",getpid());
} else {       // Child
    printf("(%i) Child can do some stuff\n",getpid());
}
```

İlk `printf`'i daha hiç `fork` yapılmadan ana proses yazar. `if (fork())` satırında parent için `fork` sıfırdan farklı bir sayı (çocuğun PID'si) döndürdüğü için `if`'in içine girilir. Aynı satırda oluşan çocukta `fork`'tan dönen değer 0 olduğu için `if`'e girilmez, `else`'e düşülür. Böylece parent ile çocuk farklı işleri yapar. Slayttaki çıktı:

```text
(2767) Parent does something...
(2767) Parent do completely different stuff
(2768) Child can do some stuff
```

## 6. Fork Alıştırma Sorusu

Görevli, sınavda buna benzer bir sorunun gelebileceğini söyleyerek bir alıştırma verdi ve katılımcılara birkaç dakika düşünme süresi tanıdı. Slayttaki `fork4.c` (ekrandan, 00:31:30):

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
    if (fork()) {
        if (!fork()) {
            fork();
            printf("1 ");
        }
        else {
            printf("2 ");
        }
    }
    else {
        printf("3 ");
    }
    printf("4 ");
    return 0;
}
```

Görevlinin çözümü şöyleydi (prosesler P1, P2, P3, P4 diye numaralandırıldı):

- **P1 (ana proses):** İlk `fork` P2'yi oluşturur ve P1'e sıfırdan farklı bir değer döndürür; P1 dış `if`'e girer. İçteki `fork` P3'ü oluşturur ve P1'e yine sıfırdan farklı bir değer döndürür; ama değil (`!`) alındığı için iç `if`'e girilmez, `else`'e düşülür ve "2" yazılır. Dış `else`'e girilmez; en sonda "4" yazılır.
- **P2 (ilk `fork`'un çocuğu):** İlk `fork`'tan 0 aldığı için dış `if`'e girmez, dış `else`'e düşer ve "3" yazar; sonra "4" yazar.
- **P3 (içteki `fork`'un çocuğu):** İçteki `fork`'tan 0 alır; değili doğru olduğu için iç `if`'e girer. Oradaki `fork` P4'ü oluşturur. P3 "1", sonra "4" yazar.
- **P4 (P3'ün çocuğu):** `fork()` satırından sonra başlar; herhangi bir koşul yoktur, "1" ve "4" yazar.

Görevlinin verdiği çıktı: `2 4 3 4 1 4 1 4`. Görevli çıktının "çiftliğine" dikkat çekti: her proses en sonda "4" yazar.

**Soru:** Son `fork`'ta bir değişkene atama yapılsaydı ne olurdu? **Cevap:** O da oluşturduğu çocuğun PID'sini döndürürdü; hangisinin parent hangisinin çocuk olduğuna göre değer değişirdi.

> **Ders sonrası not:** Görevli çözümü "parent işini bitirmeden çocuk başlayamaz" varsayımıyla sıraladı. Bu varsayım doğru değildir; proseslerin çalışma sırası zamanlayıcıya bağlıdır. Ajan kodu scratchpad'de `gcc -Wall` ile uyarısız derleyip birkaç kez çalıştırdı: çıktılar `3 4 2 4 1 4 1 4` ve `2 4 3 4 ...` gibi farklı sıralarla geldi; ama her çalıştırmada bir "2", bir "3", iki "1" ve dört "4" yazıldı. Sorunun güvenilir cevabı hangi proseslerin hangi parçaları yazdığıdır; tam sıra garanti değildir. Görevli de çocuklar arasında işletim sisteminden kaynaklanan küçük kaymalar olabileceğini söylemişti.

## 7. exec ile Başka Bir Program Çalıştırmak

`fork`'ta, ister parent ister çocuk olsun, prosesler aynı ana programı çalıştırmaya devam eder; yalnız `if` koşullarıyla farklı kollara girer. `exec`'te ise prosesin ana programdan çıkıp farklı bir programı, farklı bir kodu çalıştırması istenir. Örneğin `fork` ile parent ve çocuk oluşturulur; çocuk kendi mesajını yazdıktan sonra bir `exec` fonksiyonuyla "bu programdan çık, şu komutu çalıştır" denir.

Görevli, çocuğun `exec` ile `ls -l` çalıştırdığı bir örneği derleyip çalıştırdı. Beklenen ve elde edilen çıktı şuydu: önce parent ve çocuk mesajları, ardından bulunulan dizindeki dosyaların izinleriyle birlikte listelenmesi. `exec` ailesinin her biri farklı biçimde parametre alan çeşitli fonksiyonları olduğunu, bunlara bakılmasını önerdi.

> **Ek bilgi (derste anlatılmadı):** `exec` ailesindeki fonksiyon adlarının ekleri parametre biçimini belirtir: `l` argümanların tek tek liste olarak (`execl`, `execlp`), `v` bir dizi olarak (`execv`, `execvp`) verildiğini; `p` programın `PATH` ortam değişkenindeki dizinlerde aranacağını; `e` yeni programa ayrıca bir ortam değişkenleri dizisi verildiğini gösterir. `exec` başarılı olursa geri dönmez, çünkü prosesin kodu tamamen değişmiştir.

## 8. Proses Sonlandırma: exit, atexit ve return

C programlarını genellikle `return 0` ile bitiririz. Prosesleri normal ve düzgün biçimde sonlandırmak için de **`exit`** fonksiyonu vardır; `exit(0)` prosesin düzgün sonlandığını belirtir.

**`atexit`** ise prosese şunu söylemektir: "Sen bitiyorsun, `exit` ile bitireceksin; ama bitmeden senden son bir kez bir şey yapmanı istiyorum." Yani `atexit` ile kaydedilen fonksiyon proses sonlanmadan önce çalışır.

`return` ile `exit` farkı: `return` programlama dili düzeyinde bir fonksiyon dönüşüdür; bir fonksiyonun değer döndürmesi ya da programın bitmesiyle ilgilidir. `exit` ise bir sistem çağrısıdır; prosesin sonlandırılmasını sağlar.

Slayttaki `atexit.c` (ekrandan, 00:46:00):

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parentCleaner ( void );

int main ( void )  {

    if(fork())  { // parent process
        atexit(parentCleaner);
        printf("this is parent %i\n",getpid());
    } else  {     // child process
        printf("this is child %i\n",getpid());
    }
    exit(0);
}

void parentCleaner ( void )  {

    printf("cleaning up parent...\n");

}
```

Slayttaki açıklama: `atexit` "proses sonlandığında kaynakları temizlemek için bir fonksiyon kaydeder". Slayttaki çıktı:

```text
this is parent 3262
cleaning up parent...
this is child 3263
```

Parent `atexit(parentCleaner)` ile temizlik fonksiyonunu kaydeder ve kendi PID'sini yazar. `exit(0)` çağrılınca, proses bitmeden önce kaydedilen fonksiyon çalışır ve "cleaning up parent..." yazılır. Çocuk bu fonksiyonu kaydetmediği için yalnız kendi PID'sini yazar. Görevli örneği çalıştırıp aynı davranışı gösterdi. Ajan da kodu `gcc -Wall` ile uyarısız derleyip çalıştırdı ve aynı yapıda çıktı aldı.

## 9. Zombi Prosesler

Normalde bir proses `exit` ile sonlandığında proses tablosundan silinir ve işi biter. Ancak bazı durumlarda proses işini bitirmiş olsa da tablodan silinemez. Görevli bunu zombiye benzetti: aslında ölü ama yaşıyor gibi. Slayttaki tanım (ekrandan, 00:47:30):

- Bir proses sonlandığında hâlâ sistem kaynaklarını tüketir; işletim sisteminin tuttuğu çeşitli tablolarda kaydı vardır.
- Buna zombi denir: "yaşayan ceset, yarı canlı yarı ölü".
- Toplama (reaping) sonlanmış çocuk üzerinde parent tarafından yapılır: parent'a çıkış durumu bilgisi verilir ve çekirdek prosesi atar.
- Parent toplamazsa ne olur? Herhangi bir parent bir çocuğu toplamadan sonlanırsa çocuk başka bir proses tarafından toplanır (karede proses adı okunmuyor, büyük olasılıkla `init`). Bu yüzden açıkça toplama yalnız uzun süre çalışan proseslerde gerekir.

Görevli iki örnek gösterdi. Birinde parent sonsuz bir `while` döngüsünde kaldığı için çocuğun bittiği görülemiyor; diğerinde parent bitiyor ama çocuk sonsuz döngüye girdiği için bitişi görülemiyor. Görevli böyle bir prosesin `kill` ile PID'si verilerek öldürülebileceğini söyledi.

> **Ders sonrası not:** Görevlinin anlatımında zombi; döngüde kalan, bitmemiş prosesleri de kapsayacak biçimde anlatıldı. Slayttaki tanıma göre zombi, **sonlanmış** ama parent'ı tarafından henüz toplanmamış (`wait` çağrılmamış) prosestir. Parent'ı sonlanmış ve hâlâ çalışan bir çocuk ise yetim (orphan) prosestir. Sonsuz döngüdeki bir proses ölmemiştir, dolayısıyla zombi değildir.

## 10. wait ile Eşzamanlama

Bir parent kendine ait birden fazla çocuk oluşturabilir. **`wait`** ile parent'a "sen bitme, çocukların bitmesini bekle" denir; böylece parent ile çocuklar arasında bir eşzamanlama sağlanır.

### 10.1 wait1.c

Slayttaki `wait1.c`'de (ekrandan, 00:49:30) `numOfChilds` 5'tir. İlk döngüde parent beş kez `fork` yapar; her çocuk `(pid[i] = fork()) == 0` koşuluna girip hemen `exit(100+i)` ile sonlanır. Parent bu koşula girmez, çünkü `fork` ona sıfırdan farklı değer döndürür. İkinci döngüde parent beş kez `wait(&child_status)` çağırır. `wait` sonlanmış bir çocuğun PID'sini döndürür; `WIFEXITED(child_status)` ile çocuğun normal sonlanıp sonlanmadığı kontrol edilir, `WEXITSTATUS(child_status)` ile çıkış değeri okunur ve "Child %d terminated with exit status %d" yazılır. Slayttaki çıktıda PID'ler 3630, 3631, 3633, 3634, 3632 sırasıyla gelmiştir.

Görevli kodu çalıştırdığında çocukların sırasında küçük bir kayma oldu; bunu işletim sisteminden kaynaklanan anlık bir durum olarak açıkladı. Parent, bütün çocuklar bitene kadar bekledi ve en son kendisi bitti.

> **Ders sonrası not:** Görevli `wait`'i "sistemde şu an parent'ın bitmesini bekleyen bir çocuk var mı" diye kontrol eden bir fonksiyon olarak anlattı. Doğrusu, `wait` parent'ı çocuklarından biri **sonlanana** kadar bekletir ve sonlanan çocuğun PID'sini döndürür; çocuğun çıkış durumu, adresi verilen `child_status` değişkenine yazılır.

### 10.2 wait2.c: fazladan bir wait

Görevli bir değişiklik sordu: Beş çocuk oluşturulup altı kez `wait` çağrılırsa ne olur? Beklenti önce beş çocuğun yazılması, sonra altıncının beklenmesidir. Ama parent'ın beklenecek başka çocuğu yoktur; `wait` bir değer bulamayınca −1 döndürür. Slayttaki çıktı (ekrandan, 00:52:30):

```text
Child 3656 terminated with exit status 101
Child 3657 terminated with exit status 102
Child 3658 terminated with exit status 103
Child 3659 terminated with exit status 104
Child 3655 terminated with exit status 100
Child -1 terminated with exit status 100
```

> **Ek bilgi (derste anlatılmadı):** Altıncı satırda çıkış değerinin yine 100 görünmesinin nedeni, `wait` başarısız olduğunda `child_status` değişkenine yeni bir değer yazmaması ve değişkenin bir önceki çocuğun durumunu tutmaya devam etmesidir. Bu yüzden `wait`'in dönüş değeri −1 ise durum değişkeni yorumlanmamalıdır.

## 11. kill ile Proses Sonlandırma

Parent, bir çocuğu o kendisi bitmeden sonlandırmak isterse ya da bitmiş bir zombi prosesi sistemden silmek isterse **`kill`** fonksiyonunu kullanabilir. `kill`'e iki şey verilir: öldürülecek prosesin PID'si ve gönderilecek sinyal. Sinyaller bir sonraki uygulamada görülecek.

Slayttaki `kill.c` (ekrandan, 00:54:00):

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void childProcess() {
    printf("Child process (PID: %d) is running.\n", getpid());
    sleep(2); // Child process 2 saniye uyusun
    printf("Child process (PID: %d) has finished.\n", getpid());
}

int main() {
    pid_t childPid;

    // Child process oluştur
    if ((childPid = fork()) == 0) {
        // Child process
        childProcess();
    } else if (childPid > 0) {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d).\n", getpid(), childPid);

        // Parent, child process'i öldür
        sleep(2); // Ölmeden önce biraz bekleyelim
        if (kill(childPid, SIGTERM) == 0) {
            printf("Parent process killed child process (PID: %d).\n", childPid);
        } else {
            perror("kill");
        }
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}
```

Slayttaki çıktı:

```text
Parent process (PID: 5033) created child process (PID: 5034).
Child process (PID: 5034) is running.
Child process (PID: 5034) has finished.
Parent process killed child process (PID: 5034).
```

Parent `fork`'tan sıfırdan büyük bir değer aldığı için `else if` koluna girer, kendi PID'sini ve çocuğun PID'sini yazar, sonra 2 saniye bekler (`sleep`). Bu arada çocuk çalışmaya başlar. Parent beklemeden sonra tuttuğu çocuk PID'siyle `kill(childPid, SIGTERM)` çağırır; işlem başarılıysa "Parent process killed child process" yazar. Görevli kodu derleyip çalıştırdı. Böylece normal sistemin bitirmesini beklemeden, kullanıcı tarafında, PID verilerek bir proses sonlandırılabilir.

> **Ders sonrası not:** Parent da çocuk da 2 saniye beklediği için bu örneğin sonucu zamanlamaya bağlıdır. Ajan kodu scratchpad'de `gcc -Wall` ile uyarısız derleyip çalıştırdı; denemelerde çocuk çoğu zaman "has finished" yazamadan sonlandırıldı. Çocuk zaten bitmiş ama henüz toplanmamışsa (zombi) `kill` yine 0 döndürür; bu yüzden "killed" mesajı çocuğun gerçekten yarıda kesildiğini kanıtlamaz.

## 12. Ders Sonundaki Sorular

**Soru:** Yetim (orphan) proses de bir parent tarafından mı oluşturuluyor? **Cevap:** Görevli bunun biraz yetkiyle ve parent'ın yapacağı işle ilgili farklı bir durum olduğunu, ama sonuçta ikisinin de (zombi ve yetim) bitmeyen bir şey olduğunu söyledi.

> **Ders sonrası not:** Bu cevap kesin değildir. Yetim proses, parent'ı sonlandığı hâlde çalışmaya devam eden çocuktur ve başka bir proses (büyük olasılıkla `init`) tarafından evlat edinilir. Zombi ise sonlanmış ama toplanmamış prosestir; yani zombi "bitmeyen" bir proses değildir.

**Soru:** Bir örnekte `sleep` kullanıldı; parent ile çocuğun aynı anda çalışması nasıl sağlanır? **Cevap:** Görevli, parent ile çocuğun birlikte çalışması için bir eşzamanlama yapılması gerektiğini, bunun farklı yollarla (örneğin `sleep` ile parent'ı bekletip çocuğun işini yapmasına izin vererek) ayarlanabileceğini söyledi. `sleep` bitince parent işine devam eder. Bir prosesin içinde farklı akışların aynı anda çalışmasının thread'lerle ilgili olduğunu, bunun birkaç uygulama sonra görüleceğini belirtti.

## Örnek Sorular

**Soru 1** (ekrandan, 00:26:30): `fork2.c` çalıştırıldığında parent'ın PID'si 2703, kabuğun PID'si 2512 ve çocuğun PID'si 2704 ise çıktının satırları nelerdir?

> **Çözüm:** `process id: 2703 - parent process id: 2512`, ardından parent için `process id: 2703 - result : 2704 - parent process id: 2512` ve çocuk için `process id: 2704 - result : 0 - parent process id: 2703`. Son iki satırın sırası değişebilir.

**Soru 2** (ekrandan, 00:31:30): `fork4.c` programı ekrana ne yazar?

> **Çözüm:** Dört proses oluşur. Ana proses "2 4", ilk `fork`'un çocuğu "3 4", içteki `fork`'un çocuğu "1 4" ve onun çocuğu "1 4" yazar. Görevlinin verdiği sıra `2 4 3 4 1 4 1 4`'tür. Ajanın denemelerinde sıra çalıştırmadan çalıştırmaya değişti, ama her seferinde bir "2", bir "3", iki "1" ve dört "4" yazıldı.

**Soru 3** (ekrandan, 00:46:00): `atexit.c`'de "cleaning up parent..." mesajını hangi proses, ne zaman yazar?

> **Çözüm:** Yalnız parent yazar, çünkü `atexit(parentCleaner)` çağrısı parent kolundadır. Mesaj parent `exit(0)` çağırdığında, proses sonlanmadan hemen önce yazılır.

**Soru 4** (ekrandan, 00:52:30): Beş çocuk oluşturan bir programda parent altı kez `wait` çağırırsa altıncı çağrı ne döndürür?

> **Çözüm:** Beklenecek çocuk kalmadığı için −1 döndürür. Ekrandaki "Child -1 terminated with exit status 100" satırında durum değeri bir önceki çağrıdan kalmıştır.

## Dersin Toparlaması

Bu uygulamada proseslerin işletim sisteminde proses tablosunda proses tanımlayıcıları olarak tutulduğu, kullanıcı tarafında `fork` ve `exec` ile oluşturulduğu görüldü. `fork`'un parent'a çocuğun PID'sini, çocuğa 0 döndürdüğü, `getpid` ve `getppid` ile bu ilişkinin doğrulanabileceği ve `if` ile parent ile çocuğa farklı işler yaptırılabileceği örneklerle gösterildi; art arda `fork` içeren bir alıştırma sorusu çözüldü. `exec` ile prosesin başka bir program çalıştırması, `exit`, `atexit` ve `return` farkı, zombi proses kavramı, `wait` ile parent'ın çocukları beklemesi ve `kill` ile bir prosesin PID'siyle sonlandırılması ele alındı.

Görevli sinyallerin bir sonraki uygulamada, thread'lerin ise birkaç uygulama sonra görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
