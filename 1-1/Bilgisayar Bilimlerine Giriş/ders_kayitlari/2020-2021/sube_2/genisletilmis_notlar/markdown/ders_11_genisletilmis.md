# Ders 11 Genişletilmiş Notu: Linux Komut Satırı Temelleri ve GCC Kurulumu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Ortam
- 2. İşletim Sistemiyle Etkileşim Yolları ve Terminal
- 3. Dosya Sisteminde Gezinme
- 4. Mutlak ve Göreli Yol
- 5. Dosya Oluşturma, Taşıma, Kopyalama ve Silme
- 6. Dosya Adı, Uzantı ve Dosya Türü
- 7. Editör, İlk C Dosyası ve `file` Komutu
- 8. Dosya İçeriğine Bakma ve Kılavuz Sayfaları
- 9. Klasör İşlemleri ve Büyük-Küçük Harf Duyarlılığı
- 10. Süreçleri İzleme: `ps` ve `top`
- 11. Terminal Geçmişi
- 12. Log İzleme: `tail` ve Süreç Sonlandırma
- 13. Boru Hattı: `|`, `grep` ve `more`
- 14. Linux Dağıtımı, Sürümler ve Paket Yönetimi
- 15. GCC Kurulumu: `sudo`, Bağımlılıklar ve Depo Güncellemesi
- 16. Soru-Cevap: for mu while mı?
- 17. Soru-Cevap: VMware'de İnternet Bağlantısı

## 1. Dersin Amacı ve Ortam

Bu oturum bir laboratuvar oturumudur. Önceki hafta VMware üzerine Ubuntu işletim sistemi kurulmuştu. Bu hafta, yalnız Ubuntu'da değil bütün Linux ve Unix sistemlerinde kullanılabilen temel komutlar uygulamalı olarak gösterildi. Hoca bunların ilerideki derslerde gerekeceğini anlattı: önce kod yazmaya hazırlık yapılacak, sonra C ile kod yazılmaya başlanacak. Öğrencilerden sanal makinelerini açıp oturum açmaları ve masaüstü hazır durumdayken hocayla birlikte ilerlemeleri istendi (ekrandan, 00:20:00: Ubuntu 20.04 masaüstü, VMware Player penceresi içinde).

## 2. İşletim Sistemiyle Etkileşim Yolları ve Terminal

Her işletim sistemi, kullanıcının kendisiyle etkileşime geçebilmesi için farklı arayüzler sunar. Telefondaki işletim sistemi girdi olarak dokunmatik ekran sağlar; işlemler dokunarak yapılır. Masaüstü ya da dizüstü bilgisayardaki işletim sistemi ise genellikle klavye ve fare üzerinden etkileşim sağlar: programlar çift tıklanarak, sağ ya da sol tıklanarak çalıştırılır, işler menüler üzerinden yürür.

Bir başka etkileşim yolu kabuktur (shell). Kabuk, komut satırı ya da terminal üzerinden işletim sistemine doğrudan komut göndermeyi sağlar. Grafik arayüzde yapılan her şey buradan da yapılabilir.

Terminali açmanın birkaç yolu gösterildi:

- Kenar çubuğuna eklenmiş bir terminal kısayoluna tıklamak.
- Alt+F2'ye basıp açılan komut penceresine `gnome-terminal` yazmak. Hoca, çalıştırdığı terminalin aslında bir terminal öykünücüsü (emulator) olduğunu, adının GNOME Terminal olduğunu söyledi.
- Sol alttaki "Show Applications" düğmesine tıklayıp "terminal" yazmaya başlamak. Çıkan simgeye sağ tıklayıp "Add to Favorites" denirse terminal sol menüye eklenir.

## 3. Dosya Sisteminde Gezinme

### 3.1 `pwd`

`pwd` komutu terminalin o anda dosya sisteminde hangi klasörde (directory) olduğunu gösterir. Terminal ana ekrandan açıldığında başlangıç klasörü kullanıcının ev klasörüdür: `/home/<kullanıcı_adı>` (ekrandan, 00:25:00). Dosya sistemi hiyerarşik bir yapıdır, yani iç içe geçmiş birçok klasörden oluşur.

### 3.2 `ls` ve komut adları

Bulunulan klasördeki dosya ve klasörleri listelemek için `ls` (list) kullanılır. Derste ev klasöründe `ls` çıktısı `Desktop Documents Downloads Music Pictures Public Templates Videos` oldu (ekrandan, 00:25:00).

Hoca komut adlarının çoğunun yapılan işin kısaltması olduğuna dikkat çekti: taşımak için "move" yerine `mv`, listelemek için "list" yerine `ls`, klasör değiştirmek için "change directory" yerine `cd`.

### 3.3 `cd` ve Tab ile tamamlama

Masaüstüne geçmek için `cd` yazılır, bir boşluk bırakılır ve gidilecek klasörün adı yazılır. Hoca burada bir kolaylık gösterdi: büyük `D` ve `e` yazılıp Tab'a basılınca ad kendiliğinden `Desktop/` olarak tamamlanır. Masaüstü boş olduğu için orada `ls` hiçbir şey göstermedi.

### 3.4 `ls -la` ve gizli dosyalar

`ls` komutuna seçenek de verilebilir. `-l` sonucu yan yana yazmak yerine uzun liste biçiminde verir; `-a` gizli dosyaları da listeler. Masaüstünde `ls -la` çıktısı şöyleydi (ekrandan, 00:25:00; kullanıcı adı sütunları gösterilmedi):

```text
total 8
drwxr-xr-x  2 ...  4096 Kas  9 11:00 .
drwxr-xr-x 15 ...  4096 Kas 16 09:59 ..
```

Masaüstü boş olsa bile `.` ve `..` satırları görünür. Ev klasörü `ls -la` ile listelendiğinde ise `ls`'in göstermediği pek çok yeni ad ortaya çıktı: `.bash_history`, `.bash_logout`, `.bashrc`, `.cache`, `.config`, `.gnupg`, `.local`, `.profile`, `.ssh`, `.sudo_as_admin_successful` (ekrandan, 00:30:00).

Adı nokta ile başlayan dosya ve klasörler gizlidir. Hoca neden gizlendiklerini şöyle açıkladı: bu dosyalarda kullanıcının doğrudan kullanmayacağı uygulamaların geçici dosyaları ya da kullanıcının profiline ait temel bilgiler tutulur. Kullanıcının bunları düzenlemesi, değiştirmesi ya da kurcalaması beklenmez; bu yüzden dosya sisteminde doğrudan görünmeyecek şekilde tutulurlar.

## 4. Mutlak ve Göreli Yol

Ev klasörünü listelerken `ls -la` komutuna bir yol verildi: `/home/<kullanıcı_adı>/`. Bu, mutlak (absolute) yoldur: `/` ile, yani sistemin kökü (root) ile başlar, sonra `home` klasörünü, sonra kullanıcı klasörünü belirtir. `ls`'e hiçbir yol yazılmazsa bulunulan klasörün içeriği gösterilir. Başka bir yol yazılırsa o klasör listelenir; örneğin `ls -la /tmp` `/tmp` klasörünün içeriğini verir.

Aynı klasörü listelemenin ikinci yolu göreli (relative) yol vermektir. Dosya sisteminde `.` ve `..` adlı klasörler gerçekte yoktur, ama bu semboller anlam taşır:

- `.` bulunulan klasörü gösterir.
- `..` bir üst klasörü gösterir.

O anda masaüstünde (`/home/<kullanıcı_adı>/Desktop`) bulunulduğu için, ev klasörünü listelemek için `ls -la ../` yazmak yeterlidir. Derste iki komutun çıktıları alt alta gösterildi ve aynı oldukları görüldü (ekrandan, 00:30:00): ikisi de `total 76` ile başlayan aynı listeyi verdi.

## 5. Dosya Oluşturma, Taşıma, Kopyalama ve Silme

Bu bölümde yapılan komut dizisi ekranda şöyledir (ekrandan, 00:35:00):

```text
touch test.txt
mv test.txt ../
mv ../test.txt .
cp test.txt ../
rm ../test.txt
rm test.txt
```

Adım adım:

1. `touch test.txt`: komut satırından boş bir dosya oluşturur. Hoca dosya oluşturmanın başka yollarının da görüleceğini söyledi. Dosya hemen masaüstünde belirdi.
2. `mv test.txt ../`: dosya buradan alınıp bir üst klasöre taşınır. Masaüstündeki simge kayboldu; dosya yöneticisinde ev klasörü açılınca orada görüldü. `mv` aynı zamanda dosyanın adını değiştirmek için de kullanılır.
3. `mv ../test.txt .`: dosya bulunulan klasöre (`.`) geri getirilir.
4. `cp test.txt ../`: dosyanın bir üst klasörde bir kopyası oluşturulur. Bu kez masaüstündeki dosya yerinde kalır.
5. `rm ../test.txt`: yanlış yerde oluşturulduğuna karar verilen kopya silinir. `rm` (remove), kendisine verilen yoldaki dosyayı (yol mutlak ya da göreli olabilir) ortadan kaldırır.
6. `rm test.txt`: asıl dosya da silinir.

## 6. Dosya Adı, Uzantı ve Dosya Türü

`touch test.txt` yazılırken dosya adının iki parçası olduğuna dikkat çekildi: noktadan önceki ad kısmı ve noktadan sonraki uzantı kısmı. Hoca bu düzenin DOS'un 8+3 yapısıyla başladığını, bugün 255+3 biçiminde sürdüğünü söyledi.

> **Ders sonrası not:** Hoca adların bugün "255+3" düzeninde olduğunu söyledi. Linux'un ext4 dosya sisteminde 255 baytlık sınır büyük olasılıkla uzantı dahil bütün dosya adı içindir; uzantı ayrı bir alan değil, adın bir parçasıdır.

Uzantı, masaüstü yöneticisinin dosyayı nasıl göstereceğini belirlemesine yardım eder; kullanıcı da dosyaya bakar bakmaz ne dosyası olduğunu anlar. Ancak uzantının dosyanın gerçek türüyle doğrudan bir bağlantısı yoktur. Bir `.txt` dosyasının uzantısı `.jpg` yapılırsa dosya JPEG dosyasına dönüşmez, çünkü içeriğinde hiçbir şey değişmez. Uzantılar yalnız dosyaların türünün, ne işe yaradığının ve nasıl kullanılacağının insanlar tarafından anlaşılması için icat edilmiş bir yapıdır.

Hoca bunun güvenlikteki karşılığına da değindi: virüs saldırılarında resim uzantılı ama aslında çalıştırılabilir (executable) dosyalar gönderilirdi ve benzer denemeler hâlâ yapılıyor.

## 7. Editör, İlk C Dosyası ve `file` Komutu

### 7.1 Komut satırı neden gösteriliyor

Hoca bütün işlerin grafik arayüzden de yapılabileceğini, komut satırını özellikle sistemin çalışma mantığını görmek için gösterdiğini söyledi. Ders kapsamında teknik olarak bir editör ve bir derleyici kullanılacak:

- Derleyici: GCC (GNU C Compiler).
- Editör: gedit.

gedit'i çalıştırmak için Alt+F2'ye basılır, açılan "Run a Command" kısmına `gedit` yazılır. Bir öğrencinin "editörü nasıl açıyoruz?" sorusuna hoca bu yolu tekrar gösterdi; gedit zaten açıksa yeni bir sekme açılır.

### 7.2 Hello World ve sözdizimi renklendirmesi

Programlamaya genelde Hello World örneğiyle başlanır. Hoca gedit'te aşağıdaki programı yazdı ve masaüstüne `first.c` olarak kaydetti (ekrandan, 00:45:00; `cat first.c` çıktısı):

```c
#include <stdio.h>

int main(void)  {


	printf("Hello World");


	return 0;
}
```

Bu kod ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı ve ekrana `Hello World` yazdı (derste program henüz derlenmedi; GCC dersin sonunda kuruldu).

Dosya kaydedilmeden önce pencere başlığında "Untitled Document 1" ve yanında bir yıldız görünüyordu; yıldız dosyanın henüz kaydedilmediğini gösterir. Bu sırada metnin tamamı aynı renkteydi. Dosya `.c` uzantısıyla kaydedilince bütün metnin renkleri değişti: `int` ve `void` yeşil, `return` kırmızı, `#include` satırı turuncuya yakın bir renkte görünmeye başladı. Editör, uzantıdan bu metnin bir C programı olduğunu anladı ve o dile uygun şekilde renklendirerek kullanıcıya yardım etti. Masaüstündeki simge de metin dosyası görünümünden C dosyası görünümüne geçti; yani hem pencere yöneticisi hem editör işleri uzantıya göre koşullandırdı.

### 7.3 Aynı içerik, farklı uzantı

Ardından `cp first.c text.txt` ile dosyanın bir kopyası `.txt` uzantısıyla oluşturuldu. `text.txt` gedit'te açılınca hiçbir renklendirme yapılmadı, çünkü editör onu sıradan bir metin dosyası olarak gördü.

Uzantı işleri insan için okunur hale getirir: dosyanın içine girmeden, pencere yöneticisinde ya da komut satırında listelerken hangi dosyanın ne olduğu anlaşılır. Ama sistemin dosyanın türünü anlaması için bunlara ihtiyacı yoktur. Bunun için `file` komutu vardır (ekrandan, 00:40:00):

```text
$ file first.c
first.c: C source, ASCII text
$ file text.txt
text.txt: C source, ASCII text
```

Uzantıları farklı olmasına rağmen `file` iki dosyanın da C kaynak kodu olduğunu söyledi. Hoca bunu "iş her zaman içeriktedir" diye özetledi; uzantı daha çok insanın ve editörün işi nasıl yapacağını belirlemek içindir.

> **Hocanın vurgusu:** Dosya uzantısı dosyanın türünü belirlemez; türü içerik belirler. Uzantı insanların ve uygulamaların işini kolaylaştırmak içindir.

## 8. Dosya İçeriğine Bakma ve Kılavuz Sayfaları

### 8.1 `cat`

Bir dosyanın içeriğine bakmak için her seferinde onu bir editörde açmak gerekmez. Hoca, özellikle komut satırı ortamlarında kullanılabilecek editörlerin sınırlı olduğunu hatırlattı. Kişisel bilgisayarlarda çoğunlukla grafik arayüz kullanılır, ama sunucu sistemleri ve asıl bilgisayar sistemleri hâlâ komut satırından yönetilir. `cat first.c` dosyanın içeriğini doğrudan ekrana yazar; `cat text.txt` de aynı içeriği gösterir (ekrandan, 00:45:00).

### 8.2 `wc`

`wc` komutu "word count" kısaltmasıdır. Verilen dosyanın kaç satır, kaç kelime ve kaç karakterden oluştuğunu söyler. Derste çıktı şöyleydi (ekrandan, 00:45:00):

```text
$ wc text.txt
10 10 79 text.txt
```

Sırasıyla 10 satır, 10 kelime ve 79 karakter (ara adım eklendi). Ajan, yukarıdaki programı girintileri sekme karakteriyle yazarak denedi ve `wc` aynı sonucu verdi. Satırlar boş satırlar dahil sayılır. Kelimeler boşluklarla ayrılan parçalardır: `#include`, `<stdio.h>`, `int`, `main(void)`, `{`, `printf("Hello`, `World");`, `return`, `0;`, `}`.

### 8.3 `man`

Komutlar hakkında ayrıntılı bilgi kılavuz sayfalarından (manual pages) alınır. `man wc` yazılınca `wc` komutunun nasıl çalıştığı, parametreleri ve çıktısı anlatılır. Bu ekranda hareket edilebilir:

- Space ile ilerlenir.
- Sona gelince bir uyarı sesi duyulur.
- `q` ile çıkılır.

`man`'in kendi kullanımı için bile kılavuz vardır: `man man`. Derste `man cat` ve `man cp` de açıldı. Hoca `cp` için yalnız en basit kullanımı gösterdiğini, kılavuzda çok daha fazla seçenek bulunduğunu, bunları ara ara okumakta fayda olduğunu söyledi. `man cd` ise "No manual entry for cd" sonucunu verdi (ekrandan, 00:45:00).

> **Ders sonrası not:** Hoca `cd`'nin kılavuzunun olmamasını komutun çok basit olmasına bağladı. Asıl neden büyük olasılıkla `cd`'nin ayrı bir program değil, kabuğun yerleşik (builtin) komutu olmasıdır; bilgisi `help cd` ile alınabilir.

## 9. Klasör İşlemleri ve Büyük-Küçük Harf Duyarlılığı

Dosya sistemi dosyalardan ve klasörlerden oluşur. Dosya `touch` ile oluşturuluyordu; klasör `mkdir` (make directory) ile oluşturulur. Derste şu komutlar çalıştırıldı (ekrandan, 00:45:00):

```text
mkdir First
mkdir FiRst
mkdir FiRsT
```

Üç komutun her biri masaüstünde ayrı bir klasör oluşturdu. Adlar aynı harflerden oluşuyor, yalnız bazı harflerin büyük ya da küçük olması farklı. Buna rağmen klasörler oluşturulabildi, çünkü Linux dosya sisteminde büyük-küçük harf fark eder; yapı büyük-küçük harfe duyarlıdır (case sensitive).

Klasörleri silmenin birkaç yolu vardır:

- `rm FiRst/` hata verir: `rm: cannot remove 'FiRst/': Is a directory` (ekrandan, 00:45:00). `rm` dosyalar için kullanılır; klasör için kullanılması pek tercih edilmez.
- `rm` ile klasör silinecekse, silmenin özyinelemeli (recursive) yapılacağı `-r` seçeneğiyle belirtilmelidir. Hoca bunun "işin karışık yolu" olduğunu söyledi.
- Daha sade yol `rmdir <klasör_adı>` yazmaktır.

Son olarak düzen için `first.c` `First` klasörünün altına taşındı, `text.txt` silindi. Sonraki ekranlarda terminal `~/Desktop/First` klasöründe çalışıyor.

Hoca buraya kadarki komutların temel komutlar olduğunu söyledi: bir dosya oluşturmak, düzenlemek, dosya ya da klasörü başka yerlere taşımak. Bundan sonrası komutları birbirine bağlamak, çıktıyı yönlendirmek, kullanıcı yönetimi ve sistem yönetimi gibi daha yönetimsel işlerdir.

## 10. Süreçleri İzleme: `ps` ve `top`

Sistemde çalışan işlemlerin (process) listesini almak için `ps` yazılır. Tek başına `ps` pek bir şey söylemez, çünkü yalnız o terminal içinde çalışan süreçleri gösterir. `ps -ef` yazılırsa sistemdeki bütün süreçler görülür.

Aynı izleme işi başka araçlarla da yapılabilir; `top` bunlardan biridir. `top`, çalışan süreçlerin tamamını işlemci ve bellek kullanımına göre sıralı gösterir; süreçlerin hangi kullanıcıya ait olduğunu, bellek ve işlemci kullanımını da verir. Derste `top` ekranının üst kısmında görev sayıları (`Tasks: 279 total, 1 running, 278 sleeping`), işlemci kullanımı, toplam ve boş bellek (`MiB Mem : 3908,4 total`) ile takas alanı görüldü; altında PID, USER, PR, NI, VIRT, RES, SHR, S, %CPU, %MEM, TIME+ ve COMMAND sütunları vardı (ekrandan, 00:50:00). En üstte `gnome-shell` ve `gnome-terminal-` süreçleri, altında `systemd`, `kthreadd` gibi root kullanıcısına ait süreçler yer alıyordu.

## 11. Terminal Geçmişi

Hoca terminalin bir tampon (buffer) yapısı olduğunu anlattı. Çıktılar arkaya doğru uzar; ama sonsuza kadar değil, belli bir tampon boyutu kadar. Yine de geriye doğru oldukça fazla sayıda ekran çıktısı ve komut görülebilir.

Günümüzdeki pek çok terminalde iki kolaylık daha vardır:

- Yukarı ve aşağı ok tuşlarıyla daha önce çalıştırılan komutlar arasında gezilir. Parametresi yanlış girilen bir komut çağrılıp düzeltilerek yeniden çalıştırılabilir; aynı iş tekrar edilecekse komutu baştan yazmak gerekmez.
- Ctrl+R ile eski komutlar arasında arama yapılır. Örneğin arama kısmına `ls` yazılınca daha önce çalıştırılan `ls -la` bulundu ve yeniden kullanılabildi.

## 12. Log İzleme: `tail` ve Süreç Sonlandırma

### 12.1 `tail` ve `-n`

`tail`, parametre olarak verilen dosyanın son satırlarını gösterir. `first.c` gibi kısa bir dosya verilirse zaten dosyanın tamamı görünür. `/var/log/syslog` verilirse, sistemle ilgili bütün olayların (event), uyarıların, bilgilerin ve hataların düştüğü log dosyasının son 10 satırı gösterilir.

10 satırla sınırlı değildir. `man tail` ile özelliklerine bakıldığında `-n` seçeneğiyle kaç satır gösterileceğinin ayarlanabildiği görülür; varsayılan 10'dur, istenirse 100 yapılabilir. Hoca, sanal makine ağa doğrudan bağlı olmadığı ve sistemde fazla hareket olmadığı için ardışık çalıştırmalarda hep aynı satırların göründüğünü, daha canlı bir sistemde farkın görüleceğini söyledi.

### 12.2 `tail -f`

`tail`'in `-f` seçeneği kullanıldığında son 10 satır gösterilir ama komut bitmez; imleç solda aktif kalır. Çünkü `tail` bir yandan sistemde yeni bir hareket olmasını bekler ve log dosyasına eklenen satırları ekrana basmaya devam eder.

Hoca bunu bir deneyle gösterdi: `tail -f /var/log/syslog` açıkken yeni bir terminal açtı. Loga hemen yeni bir satır düştü (ekrandan, 00:55:00 ve 01:00:00):

```text
Started VTE child process 4958 launched by gnome-terminal-server process 3913.
```

Yani 4958 kimlikli yeni bir terminal süreci, 3913 kimlikli süreç tarafından açıldı. Yeni terminal kapatılınca da kapandığına dair bilgi loga düştü.

### 12.3 Çalışan bir süreci bulmak ve durdurmak

`tail -f` teknik olarak hâlâ çalışmaktadır. Bunu görmek için yeni bir terminal açılıp `ps -ef` çalıştırıldı; listede `tail` komutu çalışır durumda görüldü. `ps -ef` çıktısındaki sütunlar arasında sürecin kimliği (PID) ve onu başlatan üst sürecin kimliği (PPID) vardır. Hoca, terminalin süreç ailesini ve onun altında çalışan `tail` sürecini bu şekilde ayırt etti (ekrandan, 00:55:00).

Çalışan `tail` komutu iki yolla durdurulabilir:

- Başka bir terminalden `kill` komutuyla sürecin sonlanması istenir. Derste bu yapıldı ve `tail` çıktısının sonunda `Killed` yazdı.
- Komutun çalıştığı terminalde Ctrl+C'ye basılır. Komut yeniden başlatılıp bu yolla da sonlandırıldı (ekranda `^C` görünüyor).

## 13. Boru Hattı: `|`, `grep` ve `more`

Bazı komutlar, örneğin `ps -ef`, bir ekranda takip edilebilecekten çok daha fazla çıktı üretebilir. Normalde bir komutun çıktısı terminale, yani ekrana düşer. Bunun yerine çıktı başka bir komuta yönlendirilebilir; bunun için iki komutun arasına boru (pipe) işareti `|` konur.

Hoca `|` işaretinin klavyede nasıl yazılacağını da anlattı. Türkçe Q klavyede sol Shift'in yanında küçüktür-büyüktür (`<>`) tuşu vardır. Bu tuşta küçüktür aşağıda, büyüktür yukarıda, sağ altta da `|` görülür. Sağ alttaki karakter için sağdaki AltGr tuşuyla bu tuşa birlikte basılır. Farklı bir klavye dizilimi kullanılıyorsa başka bir tuş birleşimi gerekebilir. Hoca bu işaretin `l` harfi değil, boru işareti olduğunu ayrıca belirtti.

Çıktı içinde arama için `grep` kullanılır. `grep <kelime>`, kendisine gelen çıktıda o kelimenin geçtiği satırları ayıklar ve bulduğu yerleri kırmızıyla gösterir. Derste hoca kendi kullanıcısına ait süreçleri görmek için `ps -ef` çıktısını kullanıcı adına göre süzdü. Çıktı azaldı ama hâlâ uzundu. Bu kez `grep`'in çıktısı da `more` komutuna aktarıldı. `more`, kılavuz sayfalarına benzer şekilde çıktıda Enter ile satır satır, Space ile sayfa sayfa ilerlemeyi sağlar. Kullanılan zincir:

```text
ps -ef | grep <kullanıcı_adı> | more
```

## 14. Linux Dağıtımı, Sürümler ve Paket Yönetimi

### 14.1 Komut bulunamadığında

Yazılan C kodunu derlemek için GCC kullanılacaktı; bunun için `gcc` yazmak gerekir. Hoca önce komut satırının "biraz akıllı" olduğunu gösterdi. Var olmayan bir komut yazıldığında (`gyh`) terminal komutun bulunamadığını söylüyor ve benzer komutları öneriyor (ekrandan, 01:00:00):

```text
Command 'gyh' not found, did you mean:
  command 'gyp' from deb gyp ...
  command 'gh' from deb gitsome ...
  command 'gth' from deb genomethreader ...
Try: sudo apt install <deb name>
```

Hoca normal terminallerin böyle çalışmadığını, bir komutu bulamayınca "komut bulunamadı" deyip geçtiğini söyledi. `gcc` için ise mesaj şuydu:

```text
Command 'gcc' not found, but can be installed with:
sudo apt install gcc
```

### 14.2 Dağıtım nedir

Ubuntu bir Linux işletim sistemidir ama aynı zamanda bir dağıtımdır. Linux işletim sisteminin temelini Linux çekirdeği ve sistem yazılımları oluşturur. Dağıtım hazırlayan, çekirdeğin bir sürümünü alır, çevresine sistem uygulamalarını, sonra kendi uygulamalarını dizer ve hepsini bir paket halinde sunar.

Sürümler arasında bu paketlerde değişiklik yapılır. Küçük (minor) değişiklikler yalnız güncellemelerle çözülür. Alttaki sistem paketlerinden biri ya da işletim sisteminin çekirdeği değişiyorsa, yani büyük (major) bir değişiklik varsa, yeni bir sürüm çıkarılır.

### 14.3 Sürüm numaraları ve LTS

Derste Ubuntu 20 kullanılıyor. Kurulum sırasında bazı öğrenciler 18.04 kurulu olduğunu, başka bir sürüm kullanılıp kullanılamayacağını sormuştu. Hoca bunun teknik olarak sorun olmadığını söyledi ve sürümleri şöyle anlattı: sürümler 18, 20, büyük olasılıkla sonra 22 diye gider; çift sayılar kararlı ve kullanılabilir sürümlerdir, tek sayılar aradaki test sürümleridir. Sürümün yanında LTS (Long Term Support) ibaresi görülürse, üretici o sürümü uzun süre destekleyecek demektir. Bu yüzden 18.04 hâlâ kullanılabilir: güncellemeleri çıkıyor, bakımı sürüyor. Ancak 12 LTS gibi çok eski bir sürümü kullanmanın bir anlamı yoktur.

> **Ders sonrası not:** Hoca tek sayılı sürümlerin test sürümü olduğunu söyledi. Ubuntu sürüm numarası büyük olasılıkla yıl.ay biçimindedir (20.04 = 2020 Nisan). LTS sürümleri çift yılların Nisan sürümleridir; aradaki sürümler (20.10, 21.04 gibi) test sürümü değil, yaklaşık 9 ay desteklenen normal sürümlerdir.

### 14.4 Uygulama kurmanın yolları

Uygulama kurmanın birkaç yolu vardır. Biri grafik arayüzdür; bu derste ilgilenilen kısım değildir. Diğeri komut satırıdır ve o da farklı yollarla yapılabilir:

- Dağıtıcının kendi paketleme yöntemiyle kurmak. Ubuntu'da Debian'a ait deb paket biçimi ve `dpkg` kullanılır. Önceden derlenmiş bir ikili dosya (binary) alınır, çevresine gerekli dosyalar eklenip paket haline getirilir. Paket bilgisayara indirilir ve kurulumda ilgili yerlere otomatik olarak yerleştirilir.
- Kendi yazdığımız ya da başkasının yazdığı kodu derleyip, programın çalışması için gereken bütün dosyaları gerekli yerlere elle koymak. Örneğin oluşan ikili dosyayı `bin` klasörünün altına, kullanacağı ayar dosyasını `etc` altına koymak; çıktılarını yazacağı bir klasör gerekiyorsa `var/log` altında klasör açmak ve izinlerini ayarlamak.

## 15. GCC Kurulumu: `sudo`, Bağımlılıklar ve Depo Güncellemesi

### 15.1 Neden `sudo`

Kurulum komutu `apt install gcc`'dir, ama başına `sudo` konur. Bir sisteme uygulama yüklemek yönetimsel (administrative) bir iştir. Hoca ilk kurulumda anlattıklarını hatırlattı: root kullanıcısının grafik ekrandan oturum açmasına zaten izin verilmez, terminalde de çoğu zaman kısıtlı olması istenir. Bu yüzden yönetimsel bir iş yapılacağı zaman root yetkisi istenir. `apt` uygulamasının yaptığı iş yönetimsel olduğu için başına bilerek `sudo` yazılır:

```text
sudo apt install gcc
```

Komut çalışınca şifre soruldu (`[sudo] password for ...`). Bu şifre, Ubuntu kurulumunda kullanıcı için verilen şifredir.

### 15.2 Bağımlılıklar ve depo

Terminal, GCC paketini kurabilmek için başka paketleri de kurması gerektiğini söyledi (ekrandan, 01:05:00). Ekranda kurulacak ek paketler arasında `binutils`, `binutils-common`, `binutils-x86-64-linux-gnu`, `cpp-9`, `gcc-10-base`, `gcc-9`, `gcc-9-base`, `libc6-dev` gibi paketler vardı. Özet satırları şöyleydi:

```text
9 upgraded, 21 newly installed, 0 to remove and 229 not upgraded.
Need to get 28,7 MB/36,9 MB of archives.
After this operation, 92,9 MB of additional disk space will be used.
Do you want to continue? [Y/n]
```

Hoca nedenini şöyle açıkladı: birçok uygulama başka uygulamalarla ilişkilidir; aralarında bağımlılık (dependency) vardır. Eskiden bu bağımlılıkları kullanıcının elle çözmesi gerekirdi. Bugün dağıtıcıların, farklı mimariler ve farklı işletim sistemi sürümleri için bütün paketlerin tutulduğu bir deposu (repository) vardır. Kullanıcı yalnız istediği programı söyler; kurulum aracı paketin içindeki bilgilere bakarak nelerin gerektiğini bulur, hepsini internetten indirir ve kurar.

### 15.3 `apt update`

`y` yazıp Enter'a basınca kurulum başlamalıydı. Ama kurulum için deponun adreslerini ve yapısını bilmek gerekir. APT bu makinede ilk kez çalıştırıldığı için depo bilgileri güncel değildi. Önce depo bilgileri güncellendi, sonra kurulum yeniden çalıştırıldı:

```text
sudo apt update
sudo apt install gcc
```

İkinci komut, ok tuşlarıyla geçmişten çağrılıp Enter'a basılarak çalıştırıldı. APT veritabanlarını aldı, paketleri indirdi ve tek tek kurdu. Kurulumun sonunda `Setting up gcc (4:9.3.0-1ubuntu2) ...` satırı görüldü (ekrandan, 01:10:00).

Hoca, ilerideki laboratuvarlarda C ile çalışılacağı için herkesin GCC kurulumunu önceden tamamlamasını, son dakikaya bırakmamasını istedi. Kalan sürede öğrencilerin bu komutları denemesini, yanılmasını, sorun çıkarıp çözmeye çalışmasını, çözemediği yeri sormasını beklediğini söyledi.

> **Hocanın vurgusu:** Bir sorun bildirirken yalnız "çalışmıyor" denmemeli. Çalışmayan şeyin nasıl çalışmadığını gösteren ekran çıktısı ya da hata mesajı paylaşılmalı; sorun ancak ipucu ve bilgiyle çözülebilir.

## 16. Soru-Cevap: for mu while mı?

Bir öğrenci for ve while döngülerini anlamadığını yazdı. Hoca önce sorunun ne olduğunu netleştirmek istedi: for'un ya da while'ın kendisiyle mi ilgili, yoksa hangisinin ne zaman kullanılacağıyla mı? Sonra iki örnek soruyla kuralı anlattı.

Birincisi: 1'den 10'a kadar olan sayıların toplanması. Burada yapılacak işin kaç kez tekrar edileceği bellidir: on adımda toplama yapılacak (1 ile 2, sonra 3, sonra 4 diye). Bu yüzden for kullanılır.

İkincisi: verilen bir dizide 7'den büyük ilk sayının bulunması. Öğrenci "if" diye cevap verdi; hoca if'in tek başına yetmediğini söyledi. Burada aranan sayı bulunduğu anda durulacaktır. Dizi 50 elemanlıysa her zaman 50 elemana bakmak gerekmez:

- En iyi durum: ilk eleman 7'den büyüktür (örneğin 8); tek bakışta bitirilir.
- En kötü durum: bütün elemanlar 7'den küçük ya da eşittir; hepsine tek tek bakmak gerekir.

Bu yüzden while kullanılır ve iki koşul birlikte denetlenir: indis dizinin boyutundan küçük olduğu sürece ve bakılan sayı 7'den küçük ya da eşit olduğu sürece (hocanın deyişiyle "sekizden küçük olduğu sürece") dönülür.

> **Hocanın vurgusu:** Yapılacak işin kaç kez tekrar edileceği biliniyorsa for, bir koşul sağlanana kadar dönülecekse while kullanılır.

Hoca son olarak alıştırma olarak, verilen bir dizide verilen bir sayıdan küçük olan ilk elemanı bulan algoritmanın çizilmesini önerdi (çözümü derste verilmedi; aşağıdaki Örnek Sorular bölümüne bakın).

## 17. Soru-Cevap: VMware'de İnternet Bağlantısı

**Soru:** VMware'de sanal makineyi internete nasıl bağlayacağız?

**Cevap:** Ekstra bir şey yapılmadıysa, varsayılan ayarlarla oluşturulan sanal makinenin zaten internet bağlantısı vardır. Yoksa VMware'de sanal makine ayarlarına (Virtual Machine Settings) girilir ve Network Adapter bölümüne bakılır. Bağdaştırıcı yok görünüyorsa ya da aygıt durumunda "Connected" ve "Connect at power on" işaretli değilse sorun vardır, düzeltilmesi gerekir. Ağ bağlantısı NAT olarak bırakılırsa, bilgisayarın internet bağlantısı varsa sanal makinenin de otomatik olarak internet bağlantısı olur. Diğer seçenekler bu aşama için fazla ileri olduğundan onlara girilmemesini önerdi. Buna rağmen sorun sürerse ekran görüntüsüyle durum tespit edilip hocaya iletilmelidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:11:55)

1'den 10'a kadar olan sayıları toplamak için hangi döngü kullanılır?

> **Çözüm (derste verildi):** for. Tekrar sayısı bellidir (on adım). Aşağıdaki C kodu ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı ve `55` yazdı.

```c
#include <stdio.h>

int main(void) {
    int toplam = 0;
    for (int i = 1; i <= 10; i++)
        toplam += i;
    printf("%d\n", toplam);
    return 0;
}
```

**Soru 2** (derste sözlü, 01:12:52)

Verilen bir dizi içinde 7'den büyük ilk sayıyı bulmak için hangi yapı kullanılır?

> **Çözüm (derste verildi):** while. İndis dizinin boyutundan küçük ve bakılan eleman 7'den küçük ya da eşit olduğu sürece dönülür; en iyi durumda ilk elemanda, en kötü durumda bütün elemanlara bakıldıktan sonra durulur. Aşağıdaki kod derste yazılmadı; ajan tarafından örnek bir diziyle (`3, 7, 5, 9, 2, 8`) derlenip denendi ve `dizi[3] = 9` sonucunu verdi.

```c
#include <stdio.h>

int main(void) {
    int dizi[6] = {3, 7, 5, 9, 2, 8};
    int n = 6, i = 0;

    while (i < n && dizi[i] <= 7) {
        i++;
    }
    if (i < n)
        printf("7'den buyuk ilk sayi: dizi[%d] = %d\n", i, dizi[i]);
    else
        printf("7'den buyuk sayi yok\n");
    return 0;
}
```

**Soru 3** (derste sözlü, 01:14:14)

Verilen bir dizide, verilen bir sayıdan küçük olan ilk elemanı bulan algoritmayı çizin.

> **Çözüm (derste verilmedi):** Soru 2 ile aynı yapı kullanılır, yalnız koşul değişir. İndis $i = 0$'dan başlar. $i < n$ ve $dizi[i] \geq esik$ olduğu sürece $i$ bir artırılır. Döngü bitince $i < n$ ise aranan eleman $dizi[i]$'dir; değilse dizide eşikten küçük eleman yoktur. Aşağıdaki kod ajan tarafından yazıldı ve `12, 9, 15, 4, 20, 7, 3, 11` dizisi ile eşik 8 için derlenip denendi; sonuç `dizi[3] = 4` oldu.

```c
#include <stdio.h>

int main(void) {
    int dizi[8] = {12, 9, 15, 4, 20, 7, 3, 11};
    int n = 8, esik = 8, i = 0;

    while (i < n && dizi[i] >= esik) {
        i++;
    }
    if (i < n)
        printf("%d'den kucuk ilk eleman: dizi[%d] = %d\n", esik, i, dizi[i]);
    else
        printf("%d'den kucuk eleman yok\n", esik);
    return 0;
}
```

**Soru 4** (ekrandan, 00:45:00)

`wc text.txt` komutunun çıktısı `10 10 79 text.txt` ise bu üç sayı neyi gösterir?

> **Çözüm (derste verildi):** Sırasıyla satır sayısı (10), kelime sayısı (10) ve karakter sayısı (79).

## Dersin Toparlaması

Bu laboratuvar oturumunda Ubuntu üzerinde komut satırının temelleri uygulamalı olarak görüldü. Dosya sisteminde gezinme (`pwd`, `ls`, `cd`), mutlak ve göreli yol, gizli dosyalar, dosya ve klasör işlemleri (`touch`, `mv`, `cp`, `rm`, `mkdir`, `rmdir`) ve Linux'un büyük-küçük harfe duyarlı olması gösterildi. Uzantının yalnız insan ve uygulamalar için bir ipucu olduğu, dosyanın türünü içeriğin belirlediği `file` komutuyla kanıtlandı. `cat`, `wc` ve `man` ile dosya içeriğine ve komut kılavuzlarına bakıldı; `ps`, `top`, `tail -f`, `kill` ve Ctrl+C ile süreçler ve sistem logu izlendi; `|`, `grep` ve `more` ile çıktılar birbirine bağlandı.

Son olarak dağıtım, sürüm ve paket kavramları üzerinden `sudo apt update` ve `sudo apt install gcc` ile C derleyicisi kuruldu. Bu kurulum, ilerideki laboratuvarlarda gedit ile yazılacak C programlarının GCC ile derlenip çalıştırılması için bir hazırlıktır. Hoca bu konulara laboratuvarlarda, Linux'ta çalışma ve kod yazma tarafıyla devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
