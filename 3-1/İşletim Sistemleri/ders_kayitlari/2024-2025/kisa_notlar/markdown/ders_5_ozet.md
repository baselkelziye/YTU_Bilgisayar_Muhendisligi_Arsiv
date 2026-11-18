# Ders 5 Çalışma Özeti

## Genel Konular

- Uygulama dersi: proseslerle çalışma
  - Bu derste bir araştırma görevlisi, önceki teorik derste görülen proses oluşturma ve farklılaştırma konusunun C ile Linux uygulamalarını yaptı. Kodlar bir sanal makinedeki Linux'ta `gcc` ile derlenip çalıştırıldı.
- Program, proses ve proses tablosu
  - Program diskte duran bir yapıdır; proses bu programın çalıştırılmış bir örneğidir (instance): CPU register'ları, bellek ve diğer alanlarıyla birlikte.
  - Prosesler işletim sisteminin **proses tablosunda** (process table) tutulur. Tablonun her satırı bir **proses tanımlayıcısıdır** (process descriptor): PID, durum, bulunduğu dizin, argümanlar, kod, veri, kullandığı kaynaklar, sinyaller, açık dosyalar gibi bilgiler.
  - İşletim sistemi proses oluştururken önce tabloya yeni bir proses tanımlayıcısı yazar, sonra program kodunu diskten okur. Kullanıcı tarafında bu iş `fork` ve `exec` sistem çağrılarıyla yapılır.
- `fork()`
  - Parent prosesin yanında, PID'si farklı ama diğer alanları aynı olan bir child proses oluşturur. `fork`'tan sonra program iki kola ayrılır.
  - Parent'ta çocuğun PID'sini, çocukta 0 döndürür. `if` ile dönüş değerine bakılarak parent ile çocuğa farklı işler yaptırılır.
- `getpid()` ve `getppid()`
  - `getpid()` o satırı çalıştıran prosesin PID'sini, `getppid()` onun parent'ının PID'sini döndürür. Programın ilk prosesinin parent'ı onu başlatan kabuktur (shell).
- `exec()` ailesi
  - Prosesin ana programdan çıkıp başka bir program çalıştırmasını sağlar (örneğin çocuğun `ls -l` çalıştırması).
- Proses sonlandırma: `exit()`, `atexit()`, `return`
  - `exit(0)` prosesi düzgün sonlandıran sistem çağrısıdır; `return` dil düzeyinde bir fonksiyon dönüşüdür.
  - `atexit(f)` proses sonlanmadan hemen önce çalışacak bir temizlik fonksiyonu kaydeder.
- Zombi proses
  - Sonlanmış ama hâlâ sistem kaynağı tüketen, kaydı tablodan silinmemiş proses.
- `wait()`
  - Parent'ın çocukların bitmesini beklemesini sağlar; biten çocuğun PID'sini döndürür, durum değeri `WIFEXITED` ve `WEXITSTATUS` makrolarıyla okunur. Bekleyecek çocuk kalmamışsa −1 döner.
- `kill()`
  - Bir prosese PID'siyle sinyal gönderip onu sonlandırır (örnekte `SIGTERM`). Sinyaller sonraki uygulamada görülecek.

## Hocanın Özellikle Vurguladığı Kısımlar

- `fork` dönüş değerleri (sınav için)
  - Görevli bu soruda bilinmesi gerekenleri şöyle özetledi: `getpid()` satırı çalıştıran prosesin PID'sini, `getppid()` parent'ın PID'sini döndürür; `fork` parent'a çocuğun PID'sini, çocuğa 0 döndürür.
- Art arda `fork` içeren "ekrana ne yazar" soruları
  - Görevli bu tip bir sorunun sınavda gelebileceğini söyledi; `fork`'ların yeri ve koşulları değiştirilerek sorulabilir. Çözümün anahtarı her `fork`'un parent'ta sıfırdan farklı, çocukta 0 döndürdüğünü izlemektir.
- `fork` ile `exec` farkı
  - `fork`'tan sonra parent da çocuk da aynı programı çalıştırmaya devam eder, yalnız `if` koşullarına göre farklı kollara girer. `exec` ise prosesi tamamen başka bir programa geçirir.
- `exit` ile `atexit` farkı
  - `exit` prosesi sonlandırır; `atexit` sonlanmadan önce son bir işin yapılmasını sağlar.

## Kısa Tekrar Notları

- Proses tablosu = proses tanımlayıcılarının (satırların) tablosu.
- `fork()`: parent'ta > 0 (çocuğun PID'si), çocukta 0, hatada < 0.
- `getpid()` kendi PID'si, `getppid()` parent'ın PID'si.
- `if (fork()) { parent } else { çocuk }`.
- `exec`: prosesin bellek uzayına başka bir program yüklenir.
- `exit(0)`: sistem çağrısı; `return 0`: dil düzeyinde dönüş.
- `atexit(f)`: sonlanmada çalışacak fonksiyonu kaydeder.
- `wait(&status)`: bir çocuğun bitmesini bekler, PID'sini döndürür; çocuk yoksa −1.
- `kill(pid, SIGTERM)`: prosese sonlandırma sinyali gönderir.
- Zombi: bitmiş ama kaydı silinmemiş proses; parent'ı `wait` ile toplamazsa (reap) oluşur.

## Detaylı Açıklamalar

- **Basit fork örneği.** Slayttaki `fork1.c`'de (ekrandan, 00:22:30) "Message before fork" bir kez, `fork()`'tan sonraki "Message after fork" iki kez yazılır, çünkü `fork`'tan sonraki satırı hem parent hem çocuk çalıştırır.
- **Kendini tanıma örneği.** Slayttaki `fork2.c`'de (ekrandan, 00:26:30) program önce `process id: %i - parent process id: %i` ile PID ve parent PID'yi, `fork`'tan sonra ayrıca `fork` sonucunu yazar. Slayttaki çıktı:

  ```text
  process id: 2703 - parent process id: 2512
  process id: 2703 - result : 2704 - parent process id: 2512
  process id: 2704 - result : 0 - parent process id: 2703
  ```

  Parent (2703) için `fork` sonucu çocuğun PID'sidir (2704); çocuğun (2704) `fork` sonucu 0, parent PID'si 2703'tür. İlk satırdaki 2512 programı başlatan kabuğun PID'sidir.
- **Kaynak koduyla farklılaştırma.** `fork3.c`'de (ekrandan, 00:29:30) `if (fork())` koşulu parent'ta doğru, çocukta yanlıştır; böylece parent "(2767) Parent do completely different stuff", çocuk "(2768) Child can do some stuff" yazar.
- **Fork alıştırma sorusu.** Slayttaki `fork4.c` (ekrandan, 00:31:30):

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

  Dört proses oluşur. Ana proses (P1) ilk `fork`'tan sıfırdan farklı değer alır ve dış `if`'e girer; ikinci `fork` ile P3'ü oluşturur, kendisi sıfırdan farklı değer aldığı için `!fork()` yanlıştır: "2 4" yazar. İlk `fork`'un çocuğu P2 0 aldığı için dış `else`'e düşer: "3 4". İkinci `fork`'un çocuğu P3 0 aldığı için `!fork()` doğrudur, içeride bir `fork` daha yapıp P4'ü oluşturur; P3 ve P4 "1 4" yazar. Görevlinin verdiği cevap `2 4 3 4 1 4 1 4` idi. Toplamda bir "2", bir "3", iki "1" ve dört "4" yazılır.

  > **Ders sonrası not:** Görevli "parent işini bitirmeden çocuk başlayamaz, çocuk parent'ı bekler" dedi ve cevabı bu sıraya göre verdi. Bu doğru değildir: `wait` gibi bir eşzamanlama yoksa parent ile çocuktan hangisinin önce çalışacağı zamanlayıcıya bağlıdır (teorik derste de hoca bu sıranın bilinemeyeceğini vurgulamıştı). Ajan kodu `gcc -Wall` ile derleyip çalıştırdı; çıktılar `3 4 2 4 1 4 1 4` ve `2 4 3 4 ...` gibi farklı sıralarla geldi, ama her çalıştırmada sayılar aynıydı (bir 2, bir 3, iki 1, dört 4). Doğru cevap çıktının hangi parçalardan oluştuğudur; sıra kesin değildir.

- **exec örneği.** Görevli, çocuk prosesin bir `exec` fonksiyonuyla `ls -l` çalıştırdığı bir örnek gösterdi: parent ve çocuk mesajlarından sonra dizindeki dosyalar izinleriyle listelendi. `exec` ailesinin farklı fonksiyonları (farklı parametre biçimleri) olduğunu, bunlara bakılmasını önerdi.
- **atexit örneği.** Slayttaki `atexit.c`'de (ekrandan, 00:46:00) parent `atexit(parentCleaner)` ile bir fonksiyon kaydeder, "this is parent ..." yazar ve `exit(0)` çağrılınca önce "cleaning up parent..." yazılır. Çocuk bu fonksiyonu kaydetmediği için yalnız "this is child ..." yazar. Ajan kodu derleyip çalıştırdı; slayttaki davranış elde edildi.
- **Zombi proses.** Slayttaki tanıma göre (ekrandan, 00:47:30) sonlanan bir proses hâlâ sistem kaynağı tüketir (işletim sisteminin tuttuğu çeşitli tablolarda kaydı vardır); buna zombi denir ("yaşayan ceset, yarı canlı yarı ölü"). Toplama (reaping) parent tarafından yapılır: parent çıkış durumunu alır ve çekirdek prosesi atar. Parent toplamadan sonlanırsa çocuk başka bir proses tarafından toplanır (karede proses adı okunmuyor, büyük olasılıkla `init`); bu yüzden açıkça toplama yalnız uzun süre çalışan proseslerde gerekir. Görevli, sonsuz döngüye giren kodlarla parent'ın ya da çocuğun bitişinin görülemediği örnekler gösterdi ve böyle prosesin `kill` ile PID'si verilerek öldürülebileceğini söyledi.
- **wait örnekleri.** `wait1.c`'de (ekrandan, 00:49:30) beş çocuk `exit(100+i)` ile biter ve parent beş kez `wait` çağırıp her çocuğun PID'sini ve durumunu yazar; sıra karışık olabilir. `wait2.c`'de (ekrandan, 00:52:30) beş çocuk için altı kez `wait` çağrılır; altıncı çağrıda beklenecek çocuk olmadığı için `wait` −1 döndürür ve ekranda "Child -1 terminated with exit status 100" satırı görülür.
- **kill örneği.** Slayttaki `kill.c`'de (ekrandan, 00:54:00) çocuk "is running" yazar, 2 saniye uyur ve "has finished" yazar; parent çocuğun PID'sini yazar, 2 saniye bekler ve `kill(childPid, SIGTERM)` ile çocuğu sonlandırır. Slayttaki çıktıda çocuk bitmiş, sonra parent "Parent process killed child process" yazmıştır.

  > **Ders sonrası not:** Bu örnekte iki proses de 2 saniye beklediği için sonuç zamanlamaya bağlıdır. Ajanın denemelerinde çocuk bazen "has finished" yazamadan sonlandırıldı. Çocuk zaten bitmiş ve henüz toplanmamışsa (zombi) `kill` yine başarılı döner; bu yüzden "killed" mesajı çocuğun gerçekten erken öldürüldüğünü göstermez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
