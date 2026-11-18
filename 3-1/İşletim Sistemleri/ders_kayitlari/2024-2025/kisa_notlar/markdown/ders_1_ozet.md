# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin yapısı ve kaynakları
  - Ders teorik ve kavram ağırlıklıdır; kavramlar ve kavramlar arasındaki ilişkiler üzerine kuruludur.
  - Ana kaynak Silberschatz, Galvin ve Gagne'nin "Operating System Concepts" kitabıdır (slaytlar 9. baskıdan, ekrandan, 01:32:00).
  - Yardımcı kaynaklar: William Stallings, "Operating Systems: Internals and Design Principles" ve Tanenbaum'un kitapları (Minix işletim sistemi).
  - Ders; Bilgisayar Organizasyonu, Veri Yapıları ve Algoritmalar ile Programlama derslerinin devamı niteliğindedir. Linked list, struct, instruction gibi kavramların bilinmesi beklenir.
- Bilgisayar sisteminin temel bileşenleri
  - İşlemci (CPU): programları çalıştırır (execute), veriyi işler.
  - Bellek: işlenecek veriyi ve programın komutlarını saklar.
  - Bus (yol) yapıları: işlemci ile belleği bağlar. Üç türü vardır:
    - Adres yolu (address bus): bellekteki adresi gösterir.
    - Veri yolu (data bus): bellekten gelen ya da belleğe yazılan veri ve komutları taşır.
    - Kontrol yolu (control bus): işlemin okuma mı yazma mı olduğunu belirtir.
  - Çevresel birimler (peripheral devices): yazıcı, klavye, disk, USB, ses kartı gibi giriş/çıkış aygıtları.
- Program çalıştırma ve komut çevrimi (instruction cycle)
  - Program bir komut dizisidir (series of instructions); komutlar sırayla işlemciye getirilip çalıştırılır.
  - Program sayacı (program counter, PC) bir sonraki komutun adresini gösterir.
  - Adımlar: getir (fetch), çöz (decode), çalıştır (execute), gerekirse belleğe geri yaz (write back).
  - Örnek program (ekrandan, 00:25:00): `MOV AX, 5`, `ADD AX, 5`, `MOV [1234], AX`.
  - Bir satırlık C kodu, işlemcinin komut kümesine göre birden çok makine komutuna karşılık gelebilir (örneğin `a++` çoğu işlemcide `INC` ile karşılanır, karşılığı olmayan işlemcide birkaç komuta çevrilir).
- Von Neumann ve Harvard mimarileri
  - Von Neumann: komut ve veri aynı bellekte, ayrı bölgelerde durur; işlemci ile bellek arasında tek bus vardır. Intel x86 bu mimariye yakındır.
  - Harvard: program belleği ile veri belleği ayrıdır, dolayısıyla iki ayrı bus vardır. PIC, Atmel gibi işlemciler bu mimariye yakındır.
  - Günümüz işlemcileri iki yapının iyi yanlarını alan melez (hibrit) yapılardır.
- İşletim sisteminin tarihçesi
  - 1945-55: vakum tüplü bilgisayarlar.
  - Transistörler ve toplu işlem (batch) sistemleri: delikli kartlar, kart okuyucu, teyp sürücüsü ve bir insan operatör. Bu dönemde "işletim sistemi" görevini bir insan görür; bir iş bitmeden başkası araya giremez.
  - Çoklu programlama (multiprogramming): bellekte işletim sistemine ve her işe ayrı bölge ayrılır. Kaynak paylaşımı (resource allocation) ve koruma gereği ortaya çıkar.
  - Sonrasında kişisel bilgisayarlar ve mobil sistemler.
- Bellek hiyerarşisi
  - Register (en hızlı, en az yer), önbellek (cache), ana bellek (RAM), manyetik disk, teyp, katı hal diskleri.
  - Kalıcı (non-volatile): manyetik diskler. Uçucu (volatile): register, cache, ana bellek.
  - Disk okuma-yazma kafası mekanik bir düzenektir; işletim sistemi aygıt sürücüleri (device driver) üzerinden bu donanımları yönetir.
- Emülatör gösterimi (ekrandan, 01:05:40)
  - PC, IR, MAR (memory address register), MBR (memory buffer register) ile fetch akışı: PC → MAR → adres yolu → bellek → MBR → decode → execute.
  - Execute sonucunda bayraklar (CF, OF, ZF, SF) etkilenir.
- Kesme (interrupt)
  - Çalışan bir programın akışının başka bir etken tarafından durdurulmasıdır.
  - Nedenleri: daha yüksek öncelikli bir sürecin işlemciyi istemesi; giriş/çıkış (I/O) işlemi sırasında işlemcinin boşta kalmaması için sürecin işlemciden çıkarılması.
  - Kesme kontrolü bir komutun sonunda yapılır; komut tamamlanmadan kesme kabul edilmez.
  - İstisna: gerçek zamanlı sistemler ve PLC'lerde anında yanıt (immediate response) vardır; komut yarıda kesilir.
  - Kesmelerin kapatılması CPU kullanımını (CPU utilization) düşürür.
  - Kesmesiz program akışı: fonksiyon çağrısı ya da I/O sırasında dönüş adresi yığına (stack) yazılır, iş bitince oradan devam edilir (ekrandan, 01:28:30).
- İşletim sisteminin tanımı ve amaçları
  - Kullanıcı ile bilgisayar donanımı arasında aracılık eden programdır (ekrandan, 01:32:00); bu tanım doğru ama eksiktir.
  - Amaçlar: kullanıcı programlarını çalıştırmak ve problem çözmeyi kolaylaştırmak, sistemi kullanışlı kılmak, donanımı verimli kullanmak.
  - Ek görevler: bileşenler arası iletişim, verim (throughput) artırma, kaynakların hesabını tutma, koruma ve güvenlik, izleme, bilgisayarlar arası iletişim (DNS istemcisi, DHCP gibi servisler).
  - Katmanlı yapı: donanım, işletim sistemi, sistem ve uygulama programları, kullanıcılar. Modern sistemlerde kullanıcı donanıma doğrudan erişemez.
  - Kaynak tahsis edici (resource allocator) ve kontrol programı (control program) olarak iki rol.
  - Bilgisayar açıldığında çalışan çekirdek (kernel) işletim sisteminin özüdür; Linux aslında bir çekirdektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ders kavram ağırlıklıdır, kitap okunmalıdır
  - Kavramlar tahtaya yazılarak öğrenilmez; kitabı okuyup özümsemek gerekir. Çıkmış sorulara güvenmek yanıltıcıdır.
- Önceki derslerin bilgisi gereklidir
  - Bilgisayar organizasyonundaki komut çalıştırma ve assembly kavramları bellek erişimi konularında kullanılacaktır.
- Bir komut için birden çok bellek erişimi gerekebilir
  - AX'in gösterdiği bellek adresine 5 numaralı adresteki değeri kopyalayan bir komutta komutu getirmek, 5 numaralı adresi okumak ve sonucu yazmak için üç ayrı bellek erişimi olur. Hoca bunun 8086'da geçerli bir komut olmayabileceğini belirterek mantığı göstermek için verdi.
- Kesme kontrolü komut sonunda yapılır, gerçek zamanlı sistemler istisnadır
  - Bilgisayar sistemlerinde "kesin böyledir" denebilecek şeyler azdır; çözümler zamanla gereksinimlere göre değişmiştir.
- I/O işlemcinin işi değildir
  - Bir milyon elemanı sıralamak CPU için kısa sürer ama ekrana yazdırmak çok uzun sürer. Bu sırada işlemciyi meşgul etmek diğer programları bekletir.
- İşletim sisteminin tek bir kesin tanımı yoktur
  - Tanım bakış açısına, kullanım alanına ve beklentiye göre değişir (kullanıcı açısından kolay kullanım ve performans; çoklu kullanıcıda adil paylaşım; el bilgisayarında batarya verimi; gömülü sistemde kısıtlı arayüz).

## Kısa Tekrar Notları

- Bilgisayar sistemi: CPU, bellek, bus (adres, veri, kontrol) ve çevresel birimler.
- Komut çevrimi: fetch, decode, execute, write back.
- PC bir sonraki komutun adresini tutar; fonksiyon çağrısında her zaman +1 artmaz, dönüş adresi yığında saklanır.
- Von Neumann: tek bellek, tek bus. Harvard: ayrı program ve veri belleği, iki bus.
- Batch sistemlerde işletim sistemi görevini insan operatör görüyordu.
- Çoklu programlama, kaynak paylaşımı ve koruma gereğini doğurdu.
- Bellek hiyerarşisi: register > cache > RAM > disk; hız azalır, kapasite artar.
- Kesme: daha öncelikli iş ya da I/O beklemesi nedeniyle akışın durdurulması; komut sonunda kontrol edilir.
- İşletim sistemi: kaynak tahsis edici ve kontrol programı; kullanıcı ile donanım arasındaki katman.
- Kernel, işletim sisteminin bilgisayar açıldığında çalışan çekirdeğidir.

## Detaylı Açıklamalar

- **Bilgisayar sistemi ve buslar.** Bir bilgisayar sisteminde programların çalışması için işlemci, işlemcinin üzerinde çalışacağı veri ve komutların saklandığı bellek ve bunları birbirine bağlayan bus yapıları gerekir. Hoca bunu Paint üzerinde bir CPU kutusu, komut (instruction) ve veri (data) bölümlerine ayrılmış bir bellek kutusu ve aralarındaki üç çizgiyle çizdi (ekrandan, 00:25:00). Üç çizgi üç tel değildir; her bus kendi içinde ayrıntılıdır, çizim bir soyutlamadır.
- **Komut çevrimi örneği.** Ekrandaki üç satırlık programda (`MOV AX, 5` / `ADD AX, 5` / `MOV [1234], AX`) önce PC birinci satırı gösterir, komut bellekten okunur ve çalıştırılır; ardından ikinci komut gelir. Üçüncü komut sonucu 1234 adresine yazmayı istediğinden bu kez kontrol yolundan yazma sinyali gönderilir. Ekranda üçüncü satır `MOV [1234]` olarak kesik görünür; ikinci operand (`AX`) anlatımdan alınmıştır (ekrandan, 00:25:00).

  ```text
  MOV AX, 5      ; AX <- 5
  ADD AX, 5      ; AX <- AX + 5 = 10
  MOV [1234], AX ; bellekteki 1234 adresine AX yazılır
  ```

- **Derleyicinin işlemciye göre çevirmesi.** Hoca Compiler Explorer'da (godbolt.org) bir sayının karesini döndüren C fonksiyonunu x86-64 gcc ve MIPS clang için derleyerek farklı işlemcilerde farklı makine kodu çıktığını gösterdi (ekrandan, 01:03:10). Derleyici hedef işlemciyi bilir; işletim sistemi ise bu komutların bellekte nasıl tutulup çalıştırılacağını yönetir. Ekrandaki kod:

  ```c
  #include <stdio.h>
  int square(int num) {
      //printf("%d",num);
      return num * num;
  }
  ```

  Daha sonra (01:20 civarı) `printf` satırı açılarak ekrana yazmanın doğrudan yapılamadığı, bus ve buffer üzerinden geçen bir I/O işlemi olduğu anlatıldı.
- **Emülatör.** Hoca basit bir mikroişlemci emülatöründe "Büyük Sayı - Küçük Sayı" programını çalıştırdı (ekrandan, 01:05:40). Bellekteki program:

  ```text
  000: MOV R1,08
  001: MOV R2,09
  002: CMP R1,R2
  003: JGE 06
  004: SUB R2,R1
  005: JMP 07
  006: SUB R1,R2
  007: HALT
  ```

  İşlem kaydında "Komut IR'dan ALU'ya yüklendi", "Control bus okuma moduna ayarlandı", "Operant adresi adres busa yerleştirildi" gibi adımlar görülür. Bu, komut çevriminin görsel hâlidir.
- **Kesmesiz komut çevrimi durum diyagramı.** Slayttaki diyagramda adımlar: komut adresi hesaplama, komut getirme, komut çözme, operand adresi hesaplama, operand getirme (birden çok operand olabilir), veri işlemi, operand adresi hesaplama, operand saklama (birden çok sonuç olabilir); dizi ya da vektör verisinde operand adresi hesaplamaya geri dönülür, komut bitince sonraki komuta geçilir (ekrandan, 01:16:00).
- **İşletim sisteminin rolleri.** Kullanıcı donanımın mekanizmasını bilemez; işletim sistemi bunu onun adına yapar ve donanımı verimli kullanır. Çoklu kullanıcılı sistemde bir sürecin başka bir sürecin bellek alanına erişmemesi, bir sürecin diğerini işlemciden çıkaramaması, verilerin üzerine yazılmaması gerekir; bu da kaynakların hesabının tutulmasını gerektirir. Ağ iletişimi de işletim sistemi servisleriyle yürür: tarayıcı adres çözümlemesi için işletim sisteminin DNS istemcisi servisini kullanır; bu servis kapatılırsa internet olduğu hâlde adres çözümlenemez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
