# Ders 26 Genişletilmiş Notu: Makefile, Thread'ler ve pthread Kütüphanesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Makefile ile Çok Dosyalı Projeyi Derlemek
- 2. Neden Thread? Dizi Toplama Örneği
- 3. Program, Proses ve Thread
- 4. Birçok Proses Tek İşlemciyi Nasıl Paylaşır?
- 5. Thread Kavramı ve Kullanım Alanları
- 6. Proses ile Thread Arasındaki Farklar
- 7. Thread'lerle İlgili Sorunlar: Deadlock ve Starvation
- 8. pthread Kütüphanesi ve pthread_create
- 9. Derste Yazılan Thread Örnekleri
- 10. Paylaşılan Değişken, Atomiklik ve Kilit
- 11. Yemek Yiyen Filozoflar Problemi
- 12. Thread'lerin C Konularıyla İlişkisi
- 13. Yapısal Programlamadan Nesneye Yönelik Programlamaya
- Örnek Sorular
- Dersin Toparlaması

## 1. Makefile ile Çok Dosyalı Projeyi Derlemek

Ders, son uygulama oturumunda gösterilmesi planlanan makefile örneğinin kısa bir açıklamasıyla başladı. Makefile daha önceki derslerde kısaca anılmıştı; bu derste biraz daha ayrıntılandırıldı.

### 1.1 Örnek proje

Projede üç dosya vardır: `main` fonksiyonunu içeren `uygulama.c`, bir başlık dosyası olan `func.h` ve `square.c`. Ekrandaki `uygulama.c` şöyledir (ekrandan, 00:10:00):

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

`main` içinde `square` fonksiyonu çağrılır, ama fonksiyon bu dosyada yazılmamıştır. Çağrı, `func.h` başlık dosyasındaki fonksiyon başlığı (prototip) sayesinde derlenir. Aynı başlık dosyasını içeren `square.c` dosyasında ise fonksiyonun gövdesi, yani implementasyonu vardır. Böylece iki dosya başlık dosyası üzerinden birbirini "görür".

**Soru:** Başlık dosyasına fonksiyon prototipinden başka ne yazılabilir? **Cevap:** Struct tanımları ve makro tanımları yazılabilir. Ama herhangi bir fonksiyonun implementasyonu başlık dosyasına yazılmaz.

### 1.2 Makefile ne işe yarar?

Hoca 30-40 dosyalı, dosyaları başlık dosyalarıyla birbirine bağlanmış bir C projesi düşünmemizi istedi. IDE kullanılmıyorsa her dosyayı derlemek, bağlamak ve sonunda çalıştırılabilir dosyayı oluşturmak gerekir. Dev-C++'ta tek dosyalı bir programı derlerken bile derleme günlüğünde `gcc.exe` komutunun `bt.c` dosyasından `bt.exe` oluşturduğu görülür. Dosya sayısı artınca, dosya yolları da uzayınca bu komutlar uzayıp gider. Makefile, arka planda yapılan bu uzun derleme işlemlerini bir kez yazıp sonra bu dosyayı çağırarak derlemeyi sağlar. Hoca Dev-C++'ın da arka planda bir makefile oluşturduğunu hatırlattı.

Örnek makefile'da şu söylenir: `program` hedefi `uygulama.o` ve `square.o` dosyalarından oluşacaktır. `uygulama.o`, `gcc` ile `uygulama.c` derlenerek; `square.o`, `gcc` ile `square.c` derlenerek oluşturulur. Son kural iki nesne dosyasını birleştirip `program` adlı çalıştırılabilir dosyayı üretir. Tek dosyalı programda da sıra aynıdır: önce `.c` dosyasından nesne dosyası, sonra nesne dosyasından çalıştırılabilir dosya oluşturulur.

<!-- BELİRSİZ: Makefile dosyasının içeriği hiçbir kareye girmedi; hedef, bağımlılık ve komut satırlarının tam yazımı altyazıdaki anlatımdan kurulmuştur. -->

Hoca bunun çok basit bir makefile olduğunu, gerçek projelerde derleyicinin optimizasyon seviyeleri gibi çok daha derin parametreler ve karmaşık işlemler bulunduğunu söyledi.

> **Hocanın vurgusu:** Makefile'ı bugün herkes kullanmayabilir, ama özellikle düşük seviyeli programlamanın yapıldığı gömülü sistemlerde ve her şeyin kendi araçlarınızla yapılması gereken alanlarda hâlâ kullanılır. Bazı durumlarda yalnız derleyici yüklenir, hatta derleyici kurumun kendisi tarafından yazılır. "Hiçbir IDE yok, yalnız derleyici kurulu; bu projeyi tek komutla nasıl derlersiniz?" sorusu iş görüşmelerinde sorulabiliyor. Cevap: önce bir makefile yazarım.

> Bu notu hazırlayan ajan, `func.h` dosyasına `int square(int x);` ve `square.c` dosyasına `return x*x;` gövdesini kendisi yazarak (bu iki dosyanın içeriği derste gösterilmedi) projeyi Linux'ta `gcc -Wall -c uygulama.c`, `gcc -Wall -c square.c` ve `gcc uygulama.o square.o -o program` adımlarıyla derledi. Çıktı: `Program started!`, `81`, `Program successfully ended`.

> **Ek bilgi (derste anlatılmadı):** Bir makefile kuralı `hedef: bağımlılıklar` satırı ve altında sekme karakteriyle başlayan komut satırlarından oluşur. `make` komutu, bir hedefin bağımlılıklarından biri hedeften daha yeniyse yalnız o hedefi yeniden üretir. Bu yüzden büyük projelerde yalnız değişen dosyalar yeniden derlenir.

## 2. Neden Thread? Dizi Toplama Örneği

Hoca bu derste kısaca thread konusunu anlatıp birkaç örnek göstereceğini, ardından nesneye yönelik programlamaya bir giriş yapacağını söyledi. Bu konunun normalde işletim sistemleri dersinin konusu olduğunu, ama önceki dönemlerde de anlatıldığı için burada da anlatmak istediğini belirtti.

Şimdiye kadar yazılan programlar `main`'den başlıyor, `main`'in son süslü parantezinde bitiyordu. Oysa bir programda birbirinden bağımsız, birbirini beklemesi gerekmeyen alt programlar ya da fonksiyonlar olabilir.

Örnek olarak iki dizinin karşılıklı elemanlarının toplandığını düşünelim. Birinci elemanlar toplanırken ikinci elemanların toplanmasına bir engel yoktur; önce birinciyi, sonra ikinciyi toplamak zorunda değiliz. Toplama işleminin doğası gereği hangi elemanın önce toplandığı fark etmez. (Kümülatif toplam olsaydı fark ederdi.)

Hoca tablette döngüyü açarak her adımda iki elemanı toplayan bir yazım gösterdi (ekrandan, 00:20:00):

```c
for(i=0;i<N/2;i++){
    d1[i]   += d2[i];
    d1[i+1] += d2[i+1];
}
```

Hocaya göre bu kod, elemanları teker teker toplayan döngüden daha hızlı çalışır; üçlü, dörtlü gruplarla biraz daha hızlanır, ama bir yere kadar. Çünkü işlemci, mimarisi sayesinde bu bağımsız işlemleri iç içe yürütebilir.

> **Ders sonrası not:** Tahtadaki döngüde `i` birer arttığı ve her adımda `i` ile `i+1` toplandığı için aynı elemanlar iki kez toplanır, dizinin ikinci yarısı da hiç toplanmaz. Hocanın kastettiği döngü açma (N çift iken) şöyle yazılır: `for(i=0;i<N;i+=2){ d1[i]+=d2[i]; d1[i+1]+=d2[i+1]; }`.

Programın çalışmasını (execution) bir yerine birden fazla akışa bölmeye thread denir. Hoca Word'ü örnek verdi: biz bir şeyler yazarken program hatalı gördüğü yerlerin altını çizer. Yazım denetimi bir algoritma, bizim yazmamız ve biçimlendirmemiz başka algoritmalardır. Bunların hepsinin aynı anda oluyormuş gibi görünmesi thread'lerle sağlanır.

## 3. Program, Proses ve Thread

Thread'e geçmeden önce daha genel kavramlar tanımlandı (ekrandan, 00:25:00).

- **Program:** Herhangi bir dilde (C, C++) yazılmış, bizim anlayacağımız metinler, fonksiyonlar ve komutlar içeren şey.
- **Proses:** Program derlenip (compile), bağlanıp (link) belleğe yüklendikten sonra çalıştırılabilir (executable) hale gelir. Bu haline, yani çalışan programa proses denir. İşletim sistemi her prosese bir proses kimliği (PID) atar.
- **Thread:** Prosesin içindeki yürütme akışı (aşağıda ayrıntılı).

Hoca Ctrl+Alt+Del ile Görev Yöneticisi'ni açıp Ayrıntılar sekmesini gösterdi. Burada çalışan proseslerin adları, PID'leri ve durumları vardır: bazıları bekliyordur (waiting), bazıları sonlanmıştır (terminated), bazıları çalışıyordur. Ayrıca her prosesin ne kadar CPU ve ne kadar bellek kullandığı da görülür; "Sütun seç" ile CPU zamanı gibi başka sütunlar eklenebilir. Temel öncelik (base priority) sütunu eklendiğinde bazı proseslerin yüksek, bazılarının normal, bazılarının düşük öncelikli olduğu ve her birinin kaç thread kullandığı görülür; Windows Gezgini'nin çok sayıda thread kullandığı gösterildi.

Buradan şu soru çıkar: çok sayıda proses "çalışıyor" görünüyor, ama işlemci bir tane. Bu nasıl oluyor?

## 4. Birçok Proses Tek İşlemciyi Nasıl Paylaşır?

### 4.1 Saat hızı

Hoca CPU hızının birimini sordu. Örneğin 2,4 GHz, saniyede $2{,}4\times10^9$ saat darbesi demektir; yani saniyede bu kadar kare dalga üretilir ve işlemci her yükselen ya da düşen kenarda bir işlem adımı yapar (ekrandan, 00:25:00). Bu, işlemcinin işlem yapma kapasitesinin çok yüksek olduğunu gösterir.

> **Ders sonrası not:** Hoca bir saat darbesinin süresini "2,4 çarpı 10 üzeri eksi 9 saniye" diye söyledi. Periyot frekansın tersidir: $T = \dfrac{1}{2{,}4\times10^9\ \text{Hz}} \approx 4{,}17\times10^{-10}\ \text{s} \approx 0{,}42\ \text{ns}$.

### 4.2 Çekirdekler

İlk açıklama çok çekirdekli yapıdır. Hocanın bilgisayarında 8 çekirdek vardır. Bir komut getirilir (fetch instruction), çözülür (decode instruction), yürütülür (execute instruction) ve sonuç geri yazılır (write back). Dört çekirdek varsa bu adımlar dört ayrı akış için aynı anda yürütülebilir, yani 4 ayrı proses aynı anda işlenebilir. Ama proses sayısı 4'ten çok fazladır; bu tek başına yeterli değildir.

### 4.3 Zamanlama ve bağlam değiştirme

İkinci açıklama proses zamanlamasıdır (process scheduling). P1 işlemciye alınır, belli bir süre çalışır. Sonra işletim sistemi "sen bir geç, P2'yi alacağım" der. Zaman çok küçük parçalara bölünür ve bu parçalar arasında prosesler değiştirilir: P1, sonra P2, sonra P3, sonra yeniden P1. Bu geçişe anahtarlama (switching), daha özel adıyla bağlam değiştirme (context switching) denir. Çalışma zaman paylaşımı esasına göre yürür: $0$–$t_1$ aralığında bir proses, $t_1$–$t_2$ aralığında başka bir proses çalışır (ekrandan, 00:30:00).

P1 işlemciden çıkarıldığında tamamlanmamıştır. Kodunun ne kadarı işlendiyse, o ana kadarki durumu (bayrak registerları vb.) belleğe kaydedilir. Hoca bunu özyinelemeli fonksiyonlarda bazı bilgilerin belleğe kaydedilmesine benzetti. P1 tekrar çağrıldığında bellekten durumu alınır ve en son kaldığı yerden devam eder.

### 4.4 Süpermarket örneği

Bir kasa (işlemci) ve dört müşteri (proses) olsun. Kasiyer herkese adil davranmak için kimseyi baştan sona bitirmeden, herkesten parça parça almaya karar verir. İşler: P1 10 birim, P2 4 birim (hoca önce 2 dedi, sonra 4'e çevirdi), P3 8 birim, P4 6 birim (ekrandan, 00:30:00). Kasiyer her müşteriden sırayla 2'şer birim alır ve her birinde "senden şu kadarı geçti" diye not tutar; tekrar o müşteriye geldiğinde kaldığı yerden devam eder.

```text
Başlangıç:  P1=10  P2=4  P3=8  P4=6
1. tur:     P1=8   P2=2  P3=6  P4=4
2. tur:     P1=6   P2=0  P3=4  P4=2   -> P2 çıkar
3. tur:     P1=4         P3=2  P4=0   -> P4 çıkar
4. tur:     P1=2         P3=0         -> P3 çıkar
5. tur:     P1=0                      -> P1 çıkar
```

**Soru:** Buradan ilk kim çıkar? **Cevap:** 2'şer birim alınırsa önce P2, sonra P4, sonra P3, en son P1 çıkar. (Tablo ara adım olarak eklendi.)

Kasiyer isterse farklı davranıp önce P1'i bitirip diğerlerini bekletebilir. Bu tamamen kasiyerin kararıdır; bilgisayarda bu kararları işletim sistemi verir. Örneğin bir prosese çok öncelik verildiyse işletim sistemi onu bir süre bekletebilir. Hoca buraya kadar hâlâ proses seviyesinde olunduğunu, anlatılanların birden fazla prosesin aynı anda çalışması için donanımın ve işletim sisteminin sunduğu çözümlerden bazıları olduğunu vurguladı.

## 5. Thread Kavramı ve Kullanım Alanları

### 5.1 Tek ve çok thread'li prosesler

Bir program `main` ile başlar, `main`'in sonunda biter. Başlangıçtan bitişe giden bu akışa thread denir. Her proses en az bir yürütme akışı (execution flow) içermek zorundadır, çünkü çalışan program zaten prosestir. `main`'den başlayıp tek koldan ilerleyen programa tek thread'li proses (single thread, single process) denir (ekrandan, 00:40:00).

Bazı programlarda akış bir noktaya kadar tek koldan gider, sonra ikiye bölünür ve program iki koldan yürütülür. Birbirinden bağımsız, sırayla yürütülmesine gerek olmayan bir program bloğu varsa bu blok bölünerek daha hızlı çalıştırılabilir; amaç işlemcinin daha verimli kullanılması ve programın daha kısa sürede bitmesidir. Dizilerin toplanması ve matrislerin çarpılması bu konunun çok kullanılan örnekleridir: matris çarpımında birinci matrisin bir satırı ile ikinci matrisin bir sütunu çarpılırken aynı anda başka bir satır-sütun çarpımı da yapılabilir; hiçbir engel yoktur.

> **Hocanın vurgusu:** Thread desteği programlama dilinin sağlaması gereken bir özelliktir. Dilde bununla ilgili bir kütüphane varsa thread'ler gerçeklenebilir.

### 5.2 Sanal paralellik

Her proses birden fazla thread içerebilir ve thread'ler eş zamanlı (concurrent) çalışıyormuş gibi görünür. Tek çekirdekli bir bilgisayar düşünelim: bir thread işlemciye girer, belli bir süre çalışır, sonra diğer thread girer. Bu giriş çıkışlar nanosaniyeler mertebesinde olduğu için bize eş zamanlıymış gibi görünür. Gerçekte birinci thread girer, sonra ikinci thread girer; aradaki planlamayı işletim sistemi programa göre yapar. Buna sanal paralellik denir.

### 5.3 Örnekler

Hoca şu örnekleri verdi:

- Grafik kullanıcı arayüzleri; arayüzün birçok özelliği aynı anda çalışır.
- Web tarayıcısı: aynı anda 5-6 sekme açılabilir ve her biri ayrı bir programmış gibi, birbirini etkilemeden çalışır. Tarayıcının kendisi bir prosestir, altındaki parçalar thread'lerdir.
- Gerçek zamana yakın sistemler: bir taraftan girdi alıp öbür taraftan hızla çıktı vermesi gereken programlar. Thread'ler, sonuca daha hızlı ulaşılması gereken durumlarda kullanılır.

Hoca ekrandaki slaytta da aynı soruyu gösterdi: Neden bir proseste birden fazla thread'e ihtiyaç duyarız, neden tek (varsayılan) ana thread her durumda yetmez? Gerçek zamanlı girdiler alıp her girdiye bir çıktı üretmesi gereken bir proses çok thread içermiyorsa bütün işlem senkron hale gelir: proses bir girdi alır, işler, çıktı üretir, sonra sıradakine geçer (ekrandan, 00:35:00).

Kantin örneği: Self servis bir kantinde önce fiş kuyruğu, sonra yemek kuyruğu, en sonda da yenen yemeğin artıklarının atıldığı bir kuyruk vardır. Bu üç süreç birbirinden bağımsızdır ve eş zamanlı yürümelidir. Günlük hayatta "önce fiş kuyruğu bitsin, sonra yemek kuyruğuna sıra gelsin" denemez. Problem bu tür simülasyonlar ya da matris çarpımı gibi gerçeklemeler içeriyorsa thread kullanmak gerekir.

## 6. Proses ile Thread Arasındaki Farklar

### 6.1 Bellek alanı

Bir proses birden fazla thread içerebilir, ama bir thread proses içermez; proses tektir, thread'ler onun alt bölümleridir.

Program çalıştırılıp proses haline gelince bellekte ona bir alan ayrılır. Hoca bu alanı tablette şöyle çizdi (ekrandan, 00:40:00): komutlar (instruction), stack, heap, statik ve global değişkenler, ilk değer verilmemiş (uninitialized) veri ve veri (data). Heap bölgesinde `malloc` ile oluşturulan veriler tutulur. İşletim sistemi heap'i büyütebilir; stack genellikle sabittir. Bu alan büyüyüp küçülebilir, ama bir proses başka bir prosesin adres alanına erişemez.

Thread'ler bu alanın içindeki küçük parçalardır; her thread'in proses içinde kendine ait bir kontrol bloğu vardır. Bir thread gerektiğinde başka bir thread'in verisine erişebilir. Prosesler adres alanlarını birbiriyle paylaşamazken thread'ler paylaşabilir; çünkü thread'lerin birbiriyle haberleşme imkânı vardır.

> **Ders sonrası not:** Hoca çizdiği bellek düzenine "Proses Kontrol Bloğu" dedi. Büyük olasılıkla kastettiği prosesin adres alanıdır. İşletim sistemleri derslerinde proses kontrol bloğu (PCB), işletim sisteminin her proses için tuttuğu ve PID, durum, register değerleri, açık dosyalar gibi bilgileri içeren veri yapısının adıdır.

### 6.2 Dosya tanımlayıcıları

`fscanf` gibi fonksiyonlarda standart girdi, standart çıktı ve standart hata görülmüştü; okuma-yazma işlemleri bunlar üzerinden yapılır. Bunlar dosya tanımlayıcılarıdır (file descriptor). Her prosese ayrı ayrı tahsis edilir ve prosesin bilgileri arasında tutulur. Thread'ler ise aynı prosesin altında çalıştıkları için açık dosya tanımlayıcılarını ortak kullanır.

### 6.3 Eşzamanlama, bağlam değiştirme ve haberleşme

- Prosesler birbirinden bağımsız çalışır ve prosesler arası eşzamanlama ancak çekirdek (kernel) tarafından, yani işletim sisteminin gözetiminde yapılır.
- Thread'ler arasındaki eşzamanlama ise prosesin içine yazılan kodla yapılmalıdır; işletim sistemi buna çok fazla müdahil olamaz.
- Thread'ler arası bağlam değiştirme, prosesler arasındakinden daha hızlıdır; çünkü işletim sisteminin karmaşık işlemleri yerine bizim yazdığımız basit kodlar üzerinden yürür.
- İki proses ancak prosesler arası iletişim (interprocess communication, IPC) yöntemleriyle haberleşebilir. Thread'ler arasında haberleşme ise bellekte ortak alanların paylaşımıyla yapılabilecek kadar kolaydır.

Hoca, işletim sistemlerinin thread'leri doğrudan gerçekleyen bir kütüphanesi olmadığını, thread'leri bir prosesin parçası gibi gördüğünü söyledi.

> **Ders sonrası not:** Bu ifade büyük olasılıkla thread'lerin C'de işletim sistemi çekirdeği yerine bir kütüphane (pthread) üzerinden kullanıldığını anlatmak içindir. Günümüz işletim sistemlerinin (Linux, Windows) çekirdekleri thread'leri doğrudan destekler ve zamanlar; pthread gibi kütüphaneler bu desteğin üzerine kurulur.

### 6.4 fork ve thread

Slayttaki "Bir thread yeni bir program çalıştırırsa (exec) ne olur?" sorusu üzerine hoca şunu anlattı: Bir program ikiye, o da ikiye bölünürse ve her parça proses gibi çalışırsa bellek çok kısa sürede proseslerle dolabilir. Proses oluşturmada `fork` vardır; oluşturulan prosesin bir kopyası (duplicate) çıkarılır ve prosesler ikinin katları şeklinde (2, 4, 8) çoğaltılabilir. Hocaya göre bu thread'lerde pek yoktur, olsaydı iş daha da karışırdı. Bu konular işletim sistemleri dersinde anlatılacaktır.

## 7. Thread'lerle İlgili Sorunlar: Deadlock ve Starvation

### 7.1 Genel sorunlar

- **Hata ayıklama zordur.** Dev-C++'ta yapılan adım adım hata ayıklamada değişkenleri rahatça izlemek gerekir; ama bir thread'in çalışmasının nerede başlayıp nerede kesildiği, nerede kaldığı bilinmez.
- **Aşırı thread kullanımı.** Problemi en küçük parçalara bölelim derken çok fazla bölmek performansı düşürebilir.
- **Eşzamanlama (senkronizasyon).** Asıl önemli sorun budur. Problem modüler parçalara bölünüp thread'ler oluşturulduktan sonra bu thread'ler arasında eşzamanlama sağlanmalıdır.

### 7.2 El çevirme benzetmesi

Hoca sınıfta da kullandığı bir benzetme yaptı: Bir elinizi içten dışa, diğerini dıştan içe doğru çevirin ve ikisini gerçekten aynı anda yapmaya çalışın; büyük olasılıkla yapamazsınız. Thread'in yaptığı da budur: iki işi aynı anda yapmaz; birini yapar, o bitince hemen diğerine geçer ve bu o kadar hızlı olur ki ikisi aynı anda oluyormuş gibi bir yanılsama oluşur. Bu çoklu thread'e (multi-thread) örnektir. İki elin gerçekten aynı anda zıt yönlerde çevrilmesi ise çoklu işlemeye (multiprocessing), yani iki prosesin gerçekten aynı anda çalışmasına benzer.

### 7.3 Eşzamanlama bize bırakılır

T1, T2, T3, ..., Tn thread'lerinin yönetilmesi, yani eşzamanlanması gerekir: önce hangisi gelecek, hangisi ne kadar süre kalacak, ortak bir değişken (global değişken) üzerinde nasıl işlem yapacaklar (ekrandan, 00:50:00). Proseslerin eşzamanlamasını işletim sistemi kendisi yapar; thread'lerin eşzamanlamasına ise yazdığımız kodlarla ve verdiğimiz önceliklerle biz müdahil oluruz. Eşzamanlamaya çalışırken yeterince iyi yapamazsak bazı problemlere sebep oluruz.

**Soru:** Thread eşzamanlamasında ortaya çıkan iki temel problem nedir? **Cevap:** Kilitlenme (deadlock) ve açlık (starvation).

### 7.4 Kilitlenme (deadlock)

Bazen programların kilitlendiğini görürüz; bunun nedeni büyük olasılıkla programı yazanın thread'leri doğru eşzamanlamamasıdır. Prosesin içindeki thread'ler ortak bir değişkene ulaşmak isteyebilir, bir thread başka bir thread'in çalışmasını beklemek zorunda kalabilir. Thread'ler arasındaki geçişte programın yürütülmesinin kararsız kalıp durması ve thread'lerin birbiriyle haberleşememesi gibi problemlere kilitlenme denir. Genellikle kaynak paylaşımından (resource sharing) kaynaklanır; kaynak bir değişken, CPU ya da bir bellek bölgesi olabilir (ekrandan, 00:50:00).

Hoca bunu deneyimsiz bir trafik polisinin kavşağı düzenlerken kilitlemesine benzetti. Dört yönlü bir kavşakta dört yönden araç grupları gelir; her grup karşıya geçmek ister ama önündeki grup yüzünden geçemez. Kimse kıpırdayamaz ve arkada uzun kuyruklar oluşur; buna "trafik kilitlendi" denir. Bu yüzden trafikte kavşaktaki aracın önce kavşağı boşaltması, diğer yönlerden gelenlerin beklemesi kuralı vardır. Kilitlenmenin çözümü kaynakların bırakılmasıdır (release): polis bazı araçları geri çeker, kavşak açılır ve diğerleri geçebilir. Kilitlenen bir programı kapatıp yeniden açtığımızda da kaynaklar bırakılır ve thread'ler kaynaklara yeniden erişip ilerleyebilir.

### 7.5 Açlık (starvation)

İngilizcede "starve to death" ifadesiyle anlatılır. T1, T2, T3 thread'lerine sıra verilir, ama öyle bir thread vardır ki ona hiç sıra gelmez. T1, T2, T3'ün işi bitmiş, programın bitmesini beklemektedir; ama prosesin tamamlanması için bitmesi gereken bir thread kalmıştır ve unutulmuştur. Kaynakları hiçbir şekilde kullanamama durumuna açlık problemi denir. Açlık prosesler için de geçerlidir.

Hoca işletim sistemi kitaplarında anlatılan bir anekdotu aktardı: Eski bir bilgisayar kapatılmak istenirken hâlâ açık bir proses olduğu uyarısı gelir; bakıldığında yıllardır eşzamanlama yüzünden sırası gelmemiş, işini tamamlayamamış bir proses bulunur. Önceden özellikle Linux tabanlı sistemlerde `fork` ile oluşturulan prosesler için prosesler arası iletişim konusunda eşzamanlama komutları vardı.

> **Ders sonrası not:** Hoca anekdotu 80'li yıllar ve yaklaşık 20 yıl diye anlattı. İşletim sistemi kitaplarındaki hikaye büyük olasılıkla 1973'te kapatılan MIT'deki IBM 7094'te 1967'den beri çalışmayı bekleyen düşük öncelikli bir prosestir.

## 8. pthread Kütüphanesi ve pthread_create

Ekrandaki slayt dizisinin ana başlıkları şunlardır: thread nedir, neden gereklidir, thread ve proses farkı, thread'lerle ilgili sorunlar, thread'in tanımlanması, oluşturulması, sonlandırılması ve örnekler (ekrandan, 00:15:00).

Thread oluşturmak için programlama dilinin bununla ilgili bir kütüphanesi olmalıdır, tıpkı `fscanf` için bir kütüphane kullanıldığı gibi. C'de bunun için POSIX thread (pthread) kütüphanesi vardır ve `#include <pthread.h>` ile kullanılır. Başka dillerde başka kütüphaneler vardır; nesneye yönelik programlama dersinde Java thread'leri, işletim sistemleri dersinde ise pthread'ler işletim sistemi bakış açısıyla ayrıntılı anlatılacaktır.

Her thread'in kendine ait, benzersiz (unique) bir kimliği (thread ID) vardır ve bu kimlik `pthread_t` türündedir; işlemlerde bu değişkenin işaretçisi kullanılır.

Yeni thread oluşturmak için `pthread_create` kullanılır. Söz dizimi ve parametreleri slaytta şöyledir (ekrandan, 00:55:00):

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);
```

- `pthread_t *thread`: Oluşturulan yeni thread'in kimliğinin saklanacağı `pthread_t` değişkeninin işaretçisi.
- `const pthread_attr_t *attr`: Thread özelliklerini ayarlayan özellik nesnesinin işaretçisi. `NULL` verilirse thread varsayılan özelliklerle oluşturulur. Hoca bu konunun çok derin olduğunu, işletim sistemi dersinde görülecek teorik konuların her birinin uygulamada bu özellikler altında ele alındığını söyledi.
- `void *(*start_routine)(void *)`: Thread'in çalıştıracağı fonksiyonun işaretçisi; bu fonksiyon thread'in yürüteceği kod parçasını içerir. Fonksiyonun içinde ne yapılacaksa (dizi toplamak, matris çarpmak) o yazılır.
- `void *arg`: Thread fonksiyonuna gönderilecek `void *` türündeki argüman; sayı, metin gibi gerekli her şey bu parametreyle gönderilebilir.
- Dönüş değeri (`int`): Thread başarıyla oluşturulursa 0, değilse bir hata numarası döner.

Hoca Java thread'lerinin farklı oluşturulduğunu, pthread'in daha basit bir kütüphane olduğunu belirtti.

## 9. Derste Yazılan Thread Örnekleri

Aradan sonra hoca Dev-C++'ta örnekler yazdı. Thread'lerin Linux kütüphaneleriyle daha uyumlu çalıştığını söyledi.

### 9.1 Sık yapılan yanılgı: thread baştan başlamaz

Hoca önce tablette bir şema çizdi (ekrandan, 01:10:00): `main` içinde `T1()` ve `T2()` başlatılır; T1, `f` fonksiyonuyla, T2 de `g` fonksiyonuyla ilişkilendirilmiştir. Bu bir fonksiyon çağrısı gibi görünse de doğrudan bir fonksiyon çağrısı değildir.

T1 ve T2 eş zamanlı çalışmaya başlar. İşlemcide önce T1'in bir parçası çalışır; örneğin bir `printf` biter, sonra sıra T2'ye gelir. T1 belki bir döngünün ya da `if`'in içindeydi; çalışması orada donup kalır, T2 çalışır. T1'e sıra geri geldiğinde T1 baştan başlamaz, kaldığı yerden devam eder. Bunun için kaldığı yeri ve o ana kadarki değişkenlerin son değerlerini hatırlaması gerekir; bunlar proses içinde thread'e ait alanlarda saklanır.

> **Hocanın vurgusu:** "Hocam, F çalışırken G çalıştı; F tekrar çalışınca baştan mı başlıyor?" Hayır, baştan başlamıyor, kaldığı yerden devam ediyor. T1 ve T2 birbirini çağırmayan, birbirinden bağımsız iki akıştır; fonksiyon içinde fonksiyon çağırmak gibi değildir. Bu çok karıştırılan bir kavramdır.

### 9.2 İlk thread: hello

Ekrandaki ilk program (ekrandan, 01:15:00):

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

Adım adım:

- `pthread_t tid;` ile thread kimliği için bir değişken oluşturulur. `_t` eki bu kütüphanede tür adları için kullanılan bir gösterimdir.
- `pthread_create`'e kimliğin adresi (`&tid`) gönderilir; özellikler için `NULL` (varsayılan) verilir; çalışacak fonksiyon `hello`'dur; argüman olarak `"hello thread"` metni gönderilir.
- `hello` fonksiyonu `void *` döndürür ve `void *` parametre alır. Hoca bunun nedenini fonksiyonun her türden veriyle çalışabilecek genel bir biçimde tanımlanması gerektiği diye açıkladı. Fonksiyon içinde gelen argüman, daha önce void işaretçileri konusunda görüldüğü gibi, önce doğru türe (`char *`) çevrilir (cast) ve yazdırılır.
- `sleep(5)` thread'i 5 saniye uyutur, yani beklemeye alır: "Ben bekleyebilirim, benden başka thread varsa sıra ona gelebilir."
- `pthread_exit(NULL)` thread'den çıkar. `NULL` yerine bir değer verilirse bu değer thread'i bekleyen yere döner.

Derste çalıştırıldığında önce `main`'deki mesaj, sonra thread fonksiyonundaki mesaj yazıldı. Hoca bunu görmenin iyi olduğunu söyledi.

**Soru:** Bu programda (proseste) kaç thread vardır? **Cevap:** İki. Birincisi `main`'den başlayan ana thread, ikincisi `pthread_create` ile oluşturulan yeni thread.

> **Ders sonrası not:** Ekrandaki kodda `sleep` için `<time.h>` eklenmiş. Linux'ta `sleep` `<unistd.h>` içinde bildirilir; kod `<time.h>` ile `gcc -Wall` altında `implicit declaration of function 'sleep'` hatası verdi. Derste kullanılan Windows derleyicisinde büyük olasılıkla tanım başka bir başlık üzerinden geldiği için sorun çıkmadı. `<unistd.h>` ile derlenip çalıştırıldığında yalnız `Returned to main` yazıldı: `main` `return` ile bitince proses de biter ve thread'in mesajı yazılamayabilir. Bu yüzden `join` gerekir.

### 9.3 pthread_join ile beklemek

Her şeyin bitmesini ve `main`'in en son kapanmasını istiyorsak `pthread_join` kullanılır. `pthread_join(tid, NULL);` çağrısı, `tid` kimlikli thread bitene kadar çağıranı bekletir; ikinci parametre thread'in dönüş değeri içindir, burada kullanılmadığı için `NULL` verilmiştir.

`join` eklendiğinde ekranda önce `hello thread` yazıldı, sonra 5 saniye beklendi ve ardından `Returned to main` geldi. Hoca nedenini şöyle açıkladı: thread uyutuldu ama bitmedi; thread bitmeyince fonksiyon bitmedi; fonksiyon bitmeyince `join` tamamlanamadı; `join` tamamlanamadığı için sonraki `printf` yazdırılamadı.

### 9.4 İki thread ve çalışma sırası

Ardından `join`'den önce bir `printf("After thread call\n");` satırı ve ikinci bir thread eklendi (ekrandan, 01:20:00):

```c
int main(){
    pthread_t tid, tid2;
    pthread_create(&tid,NULL,hello,"hello thread");
    pthread_create(&tid2,NULL,hello,"hello thread_2");
    printf("After thread call\n");
    pthread_join(tid,NULL);
    printf("Returned to main");
    return 0;
}
```

Tek thread'li halde çalıştırıldığında bazen önce `After thread call`, bazen önce `hello thread` göründü. Ama `Returned to main` her zaman en sondadır; çünkü thread bitmeden `join`'in altındaki satıra gelinemez. `join`'den önceki `printf` ise thread'in çıktısından önce de sonra da yazılabilir.

İkinci thread eklenince prosesteki thread sayısı üç oldu. Hoca hangisinin önce çalışacağının kestirilemeyeceğini vurguladı. Bir çalıştırmada sıra şöyleydi: `hello thread`, `After thread call` (ana thread), `hello thread_2`, son olarak `main`'e dönüş. Hoca, ikinci thread'in de `join` edilmesi gerektiğini ve istenirse önce ikinci, sonra birinci thread'in beklenebileceğini gösterdi.

> Bu notu hazırlayan ajan, iki `join`'li sürümü (`<unistd.h>` ile ve `sleep(1)` kullanarak) Linux'ta `gcc -Wall -pthread` ile derleyip çalıştırdı; bir çalıştırmadaki çıktı `hello thread`, `After thread call`, `hello thread_2`, `Returned to main` oldu. İlk üç satırın sırası çalıştırmadan çalıştırmaya değişebilir.

### 9.5 Döngüyle birden çok thread

Hoca aynı fonksiyonu döngüyle üç kez çalıştıran bir sürüm yazdı (ekrandan, 01:25:00):

```c
int main(){
    pthread_t tid;
    int i;
    for(i=0;i<3;i++){
        pthread_create(&tid,NULL, hello,(void*)&tid);
    }
    printf("Returned to main");
    pthread_exit(NULL);
    return 0;
}
```

Burada her thread'e argüman olarak thread kimlik değişkeninin adresi gönderilir. `hello` fonksiyonunda gelen `void *` önce `int *`'a çevrilir ve gösterdiği değer thread kimliği olarak yazdırılır. Fonksiyonun içine bir de `static int x = 0;` sayacı konur ve her çağrıda `x++` yapılır; böylece her thread'in "thread id" ve "statik" değeri yazdırılır. `main`'in sonunda `return` yerine `pthread_exit(NULL)` çağrılır; bu, ana thread'den çıkar ama diğer thread'lerin çalışmasına izin verir.

Derste çıktıda thread kimliği 2 olan thread statik değer 1 ile, kimliği 3 olan thread statik değer 2 ile çalıştı ve araya `main`'in mesajı girdi. Hoca, üç thread olması gerekirken iki thread varmış gibi göründüğünü fark etti. Sonra bir global değişken `g = 0` ekleyip fonksiyonda `g++` yaptı ve döngüyü 5'e çıkardı; bu kez kimlikler 2, 3, 4, 5 diye başladı, en son `main`'e dönüldü ve bir thread'in aynı kimlikle çalıştığı görüldü. Hoca, aynı fonksiyonla bu şekilde birden fazla thread oluşturmaya thread havuzu dendiğini söyledi.

<!-- BELİRSİZ: hello fonksiyonunun statik ve global değişkenli son hali kareye tam girmedi; yukarıdaki anlatım altyazıdan kurulmuştur. -->

> **Ders sonrası not:** Bütün thread'lere aynı `tid` değişkeninin adresi gönderildiği için thread'ler bu adresi okuduğunda değer, döngünün sonraki adımında `pthread_create` tarafından çoktan değiştirilmiş olabilir. "İki thread varmış gibi" görünmesinin ve aynı kimliğin iki kez yazılmasının nedeni büyük olasılıkla budur. Her thread'e ayrı bir değer göndermek için her thread'e ayrı bir değişkenin (örneğin bir dizinin `i`. elemanının) adresi verilmelidir. Ayrıca `pthread_t`'nin bir `int` gibi okunması taşınabilir değildir.

### 9.6 Thread'e struct göndermek

Thread fonksiyonu tek bir `void *` argüman aldığı için birden çok veri göndermek gerekiyorsa bir struct gönderilir. Struct `void *` olarak geçer ve fonksiyonda kendi türüne geri çevrilir. Ekrandaki örnek (ekrandan, 01:30:00):

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

`main`'de `malloc` ile bir `struct args` alanı ayrılır, alanlarına değer verilir ve bu işaretçi `(void *)` olarak `hello`'ya gönderilir. `hello` içinde gelen `input`'un bu türde olduğu söylenip (`(struct args*)input`) alanlarına `->` ile erişilir.

> Bu kod, ekranda görünmeyen ilk satırlardaki `#include <stdio.h>`, `#include <stdlib.h>` ve `#include <pthread.h>` eklenerek Linux'ta `gcc -Wall -pthread` ile derlendi. `hello` fonksiyonunda `return` olmadığı için `control reaches end of non-void function` uyarısı verdi; sonuna `return NULL;` eklenince uyarısız derlendi ve `name: Allen`, `age: 20` yazdı.

### 9.7 Farklı thread'ler, farklı fonksiyonlar

Her thread için aynı fonksiyonu kullanmak zorunlu değildir. Hoca `hello2` adlı ikinci bir fonksiyon yazıp ikinci bir thread'i onunla ilişkilendirdi ve önce ikinci, sonra birinci thread'i `join` etti. Önce normal olan, sonra yeni fonksiyon çalıştı. Word örneğinde olduğu gibi bir thread yazım denetimi yaparken başka bir thread başka bir iş yapar; bunlar bu mantıkla oluşturulur.

### 9.8 Çevrim içi kaynaktaki örnekler

Hoca sohbetten paylaştığı bir bağlantıda, alanında otorite saydığı bir öğretim üyesinin sistem programlama dersi notlarındaki thread bölümünü ("Unit 9: Threads") açtı. Önceki bölümler işletim sistemi üzerinde proses oluşturma ve proses eşzamanlama gibi konular içerir; hoca merak edenlerin thread ile ilgili kısımlara bakmasını önerdi. Buradan şu noktalar gösterildi:

- **Thread'den değer döndürmek:** Thread bir mesaj oluşturup bunu `main`'e döndürür; `join`'in ikinci parametresiyle dönen değer alınıp yazdırılır. Thread işini bitirdiğinde onu çağırana bir değer göndermek istenebilir.
- **Derleme:** Linux'ta `gcc` ile derlerken `-lpthread` yazılması gerekir; bu, pthread kütüphanesinin bağlanacağını söyler.
- **Thread ve işletim sistemi:** `getpid` ve `getppid` çalışan prosesin ve onun üst (parent) prosesinin kimliğini getirir. Hoca bunların Unix tabanlı olduğunu, Windows'ta çalışmadığını söyledi. Örnekte dört thread oluşturulup aynı fonksiyonla ilişkilendirilir, her biri belli bir süre bekletilir ve ayrı ayrı `join` edilir.

## 10. Paylaşılan Değişken, Atomiklik ve Kilit

### 10.1 Global değişken neden tehlikeli?

> **Hocanın vurgusu:** "Global değişken kullanmayın" denmesinin asıl yeri burasıdır. Bir değişkene birden fazla thread erişiyorsa tutarsız sonuçlarla karşılaşılabilir.

Çevrim içi kaynaktaki ilk örnek şudur (ekrandan, 01:35:00):

```c
int shared = 10;

void * fun(void * args){
  time_t start = time(NULL);
  time_t end = start+3; //run for 3 seconds

  while(time(NULL) < end){
    shared++;
  }

  return NULL;
}

int main(){
  pthread_t thread_id;

  pthread_create(&thread_id, NULL, fun, NULL);

  pthread_join(thread_id, NULL);

  printf("shared: %d\n", shared);

  return 0;
}
```

Thread 3 saniye boyunca `shared` değişkenini arttırır; ana thread `join` ile bekler ve sonucu yazdırır. Derste çalıştırılınca `shared`'in çok büyük bir değere ulaştığı görüldü. Hoca, tek thread olduğu için bunun çok anlamlı görünmeyebileceğini, ama bu değişken üzerinde birden fazla thread'in işlem yaptığının düşünülmesi gerektiğini söyledi.

> Bu kod ekrandaki `#include` satırlarından okunabilenler (`stdio.h`, `pthread.h`, `time.h`) ile Linux'ta `gcc -Wall -pthread` ile derlendi ve uyarısız çalıştı; ajanın denemesinde çıktı `shared: 704336206` oldu. Değer makinenin hızına göre değişir.

### 10.2 Atomiklik

Hoca bunu assembly derslerinde görülen bakış açısıyla açıkladı. Bir thread'de `A = A + 1`, diğerinde `A = A - 1` olsun ve `A`'nın başlangıç değeri 10 olsun. Bu C satırlarının her biri yaklaşık şu komutlara karşılık gelir:

```text
Thread 1 (A = A + 1)        Thread 2 (A = A - 1)
MOV AX, A                    MOV AX, A
ADD AX, 1                    SUB AX, 1
MOV A, AX                    MOV A, AX
```

Hoca komutların tam yazımını hatırlamadığını, bunlara yakın olduğunu söyledi. İşlemcide tek bir makine komutu bölünemez: bir komut çalışırken başka bir thread'e geçiş isteği gelirse önce o komut biter. Ama tek C satırının karşılığı üç komuttur, dolayısıyla C satırı bölünebilir.

Senaryo: Thread 1 `A`'nın değerini (10) registera alır ve bu sırada Thread 2'ye geçilir. Thread 2 de `A`'yı okur; `A` hâlâ 10'dur. Thread 2 değeri bir azaltır (9) ve belleğe yazar. Thread 1'e dönüldüğünde, kaldığı yerden devam ettiği için `A`'yı yeniden okumaz; elindeki 10'u bir arttırıp 11 yazar. İşlemler sırayla yapılsaydı sonuç 10 olacaktı.

> **Ders sonrası not:** Hoca anlatımın sonunda `A`'nın değerinin "hâlâ 10" olarak görüleceğini söyledi. Anlatılan araya girme senaryosunda bir güncelleme kaybolur ve sonuç, hangi thread'in en son yazdığına göre 11 ya da 9 olur; doğru sonuç olan 10 ancak iki işlem birbirinin arasına girmeden yapılırsa elde edilir. Asıl mesaj değişmez: ortak değişken üzerindeki bölünebilir işlemler tutarsız sonuç verebilir.

Bu, atomiklik yani bölünemezlik kavramıdır. Bir thread'deki işlem ile diğer thread'deki işlem kavşak örneğindeki gibi ortak bir kaynağa erişiyorsa ve bu tutarsızlık yaratabiliyorsa buna dikkat etmek gerekir.

### 10.3 Kilit mekanizması: banka örneği

Kaynaktaki ikinci örnek bir banka simülasyonudur (ekrandan, 01:40:00). Kullanıcı komut satırından thread sayısını verir; her thread rastgele bir miktar seçip hesaba ya yatırır (`balance = balance + v; credits = credits + v;`) ya da çeker (`balance = balance - v; debits = debits + v;`). Mevcut bakiye, yatırılan ve çekilen toplamlar global değişkenlerdir. Bu, yukarıdaki arttırma-azaltma sorununun aynısıdır. Derste program önce argümansız çalıştırıldı ve "geçersiz thread sayısı" hatası verdi; sonra thread sayısı argüman olarak verilerek çalıştırıldı.

Çözüm bir kilit (lock) mekanizmasıdır. Hoca bunu bir toplulukta yalnız mikrofonu olanın konuşabilmesine benzetti: kilide sahip olan thread ortak değişken üzerinde işlem (örneğin arttırma) yapar. Kaynaktaki basit kilit örneğinde thread kilit değişkenini bir yapar; kilit başkasındaysa bir bekleme döngüsünde bekler, değilse ortak değişkeni arttırır ve işi bitince kilidi serbest bırakır.

Bu tür kilitlenme ve eşzamanlama problemlerinde karşılıklı dışlama (mutual exclusion, mutex) ve kilitlenmeden kaçınma (deadlock avoidance) gibi başka mekanizmalar kullanılır. Hoca bunların işletim sistemlerinin konusu olduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** pthread kütüphanesinde karşılıklı dışlama `pthread_mutex_t` türüyle yapılır: `pthread_mutex_lock(&m);` ile kilit alınır, ortak değişken üzerindeki işlem yapılır, `pthread_mutex_unlock(&m);` ile kilit bırakılır. Kilit sıradan bir `int` değişkenle elle yazılırsa kilidi kontrol etme ve alma adımları da bölünebilir olduğu için iki thread aynı anda kilidi aldığını sanabilir; mutex bu adımları atomik yapar.

## 11. Yemek Yiyen Filozoflar Problemi

Hoca konuyu bilinen bir eşzamanlama problemiyle bitirdi. Yuvarlak bir masada filozoflar oturur; her birinin önünde yemek ve her iki filozof arasında bir çatal vardır. Yemek yiyebilmek için bir filozofun hem sağındaki hem solundaki çatala sahip olması gerekir. Dolayısıyla bir filozof yemek yerken iki yanındaki komşusu yiyemez, ama karşıdaki bir filozof yiyebilir.

Kaynaktaki simülasyonda her filozof bir thread, her çatal bir mutex ile temsil edilir (ekrandan, 01:45:00 ve 01:50:00). Önce çatallar `malloc` ile ayrılan mutex'lerle hazırlanır (`pthread_mutex_init`), sonra her filozofa solundaki ve sağındaki çatalın adresi atanır; 0 numaralı filozof masa yuvarlak olduğu için son numaralı filozofla bir çatal paylaşır. Ardından:

```c
printf("Starting Threads\n");
//start the threads
for(i=0;i<NUM_PHIL;i++){
  pthread_create(&(philosophers[i].thread_id), NULL,
                 eat, (void *) &(philosophers[i]));
}

//join the threads
for(i=0;i<NUM_PHIL;i++){
  pthread_join(philosophers[i].thread_id, NULL);
}

printf("All threads joined\n");
//clean memory
for(i=0;i<NUM_PHIL-1;i++){
  pthread_mutex_destroy(forks[i].lock);
  free(forks[i].lock);
}

return 0;
```

Her filozof thread'ine kendi struct'ının adresi gönderilir; thread'ler döngüyle başlatılır, döngüyle `join` edilir ve sonunda mutex'ler yok edilip bellekleri serbest bırakılır. Kaynakta her filozofun önce sol, sonra sağ çatalı kilitlediği ve bu sıralamanın kilitlenmeyi önlemediği belirtilir (ekrandan, 01:50:00).

Derste simülasyon çalıştırıldı; filozof sayısı arttırılabilir. Çıktıda örneğin bir filozofun çatalı bıraktığı, ardından komşusunun o çatalı aldığı görüldü ve simülasyon böyle devam etti. Hoca bunun incelenmeye değer, önemli bir problem olduğunu söyledi.

<!-- BELİRSİZ: Ekrandaki kodun son temizlik döngüsü NUM_PHIL-1'e kadar gidiyor; çatal sayısının NUM_PHIL mi NUM_PHIL-1 mi olduğu kodun görünmeyen başından doğrulanamadı. -->

## 12. Thread'lerin C Konularıyla İlişkisi

Hoca thread konusunu bu dönem görülen C konularıyla şöyle ilişkilendirdi:

- Struct konusu: thread'e struct parametre olarak gönderilir.
- Fonksiyon işaretçileri: hangi thread'in hangi fonksiyonla çalışacağı fonksiyon işaretçisiyle ayarlanır.
- Thread'lerden geriye değer döndürme ve statik değişkenler kullanılabilir.
- Dosya işlemleri de işin içine katılabilir.

Bunlar sayesinde eş zamanlı çalışan programlar tasarlanabilir.

## 13. Yapısal Programlamadan Nesneye Yönelik Programlamaya

Dersin son kısmında hoca dersin adını hatırlattı: Yapısal Programlama. Bu derste yapısalcı bir yöntem kullanıldı ve aynı yöntem veri yapıları ve işletim sistemleri derslerinde de kullanılacaktır. Değişkenlerin başlangıçta tanımlanması, programın belli bir sıraya göre adım adım yazılması ve gereken yerde fonksiyonlarla modüler hale getirilmesi bu dersin kapsamındaydı.

Bu dersin kapsamında olmayan, ama program yazmayı kolaylaştıran yeni bir teknik nesneye yönelik programlamadır (C++, Java, C# ile). C++, Java, C# ve hatta Python'ın sözdizimine bakıldığında C'ye çok benzediği görülecektir. Temel fark şudur: orada struct yerine struct'ların farklı bir versiyonu olan sınıflar (class) görülür.

Struct'lara yalnız özellikler (feature) konabiliyordu: bir insanın yaşı, kilosu, boyu, adı, soyadı gibi. İnsanın konuşmasıyla ilgili bir davranış ise programın içinde ayrı fonksiyonlar yazılarak oluşturuluyordu; bu da programı şişiriyor. Ayrıca struct'lar arasında veri tabanlarındaki gibi bire çok, çoka çok ya da alt-üst ilişkisi kurulamıyor. Nesneye yönelik programlama bunu sağlar: struct benzeri bir yapı oluşturulur ve adına sınıf denir. Sınıfa özelliklerin yanında eylemler de tanımlanır; bu eylemlere metot denir.

Örneğin derste daha önce struct olarak yapılan oda ya da karmaşık sayı örneği düşünülsün. `Room` sınıfının özellikleri vardır; ek olarak alan hesabı gibi bir metot tanımlanır. Sınıftan, struct'larda olduğu gibi, istenen kadar nesne üretilir. `room1.calculateArea()` gibi bir çağrıda nesne kendi üyelerine atanmış değerleri alır ve metottaki algoritmayı uygular. `main` başka bir sınıfta, hatta başka bir dosyada olabilir; orada `Room` sınıfından nesne üretilir. Nesneler, struct değişkenleri gibi fonksiyonlara gönderilebilir; ama struct'lardan farklı olarak nesneler arasında bire bir, bire çok, çoka çok ve kalıtımla kurulan genel-özel (alt-üst) ilişkiler tanımlanabilir.

<!-- BELİRSİZ: Room sınıfı örneğinin kodu kareye girmedi; metot adı altyazıdan alınmıştır. -->

> **Hocanın vurgusu:** Yapısal programlamada algoritma geliştirme ve dilin temel kavramları öğrenilir; nesneye yönelik programlama bunun üzerine yeni eklentiler getirir. Bu ders veri yapıları, işletim sistemleri ve algoritma analizi gibi birçok dersin ön hazırlığıdır; burada öğrenilenler kalıcı bilgilerdir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:07:30): Bir başlık (header) dosyasına fonksiyon prototipinden başka neler yazılabilir?

> **Cevap (derste verildi):** Struct tanımları ve makro tanımları. Fonksiyonların implementasyonu (gövdesi) başlık dosyasına yazılmaz, `.c` dosyasında yazılır.

**Soru 2** (derste sözlü, 00:12:32): Hiçbir IDE yok, yalnız derleyici kurulu. Çok dosyalı bir C projesini tek komutla nasıl derlersiniz?

> **Cevap (derste verildi):** Bir makefile yazılır. Makefile'da her `.c` dosyasının `gcc` ile nesne dosyasına nasıl derleneceği ve nesne dosyalarının hangi çalıştırılabilir dosyada birleşeceği kurallar halinde tanımlanır; ardından makefile tek komutla çağrılır.

**Soru 3** (derste sözlü, 00:22:11): CPU hızının birimi nedir; 2,4 GHz ne anlama gelir?

> **Cevap (derste verildi):** GHz (gigahertz). 2,4 GHz saniyede $2{,}4\times10^9$ saat darbesi demektir; işlemci her darbe kenarında bir işlem adımı yapar. Bir darbenin süresi $1/(2{,}4\times10^9)\approx 0{,}42$ ns'dir (periyot hesabı ders sonrası düzeltildi, bkz. Bölüm 4.1).

**Soru 4** (derste sözlü, 00:29:00; ekrandan, 00:30:00): Tek kasalı bir markette P1, P2, P3, P4 müşterilerinin sırasıyla 10, 4, 8 ve 6 birimlik işi vardır. Kasiyer her tur herkesten sırayla 2'şer birim alırsa müşteriler hangi sırayla çıkar?

> **Cevap (derste verildi):** P2, P4, P3, P1. Kalan işler turlara göre: 1. tur sonunda 8, 2, 6, 4; 2. turda P2 biter; 3. turda P4; 4. turda P3; 5. turda P1 biter.

**Soru 5** (derste sözlü, 00:47:45): Thread eşzamanlamasında karşılaşılan iki temel problem nedir?

> **Cevap (derste verildi):** Kilitlenme (deadlock): kaynak paylaşımı yüzünden thread'lerin birbirini bekleyip ilerleyememesi. Açlık (starvation): eşzamanlama kötü yapıldığı için bir thread'e hiç sıra gelmemesi.

**Soru 6** (derste sözlü, 01:15:29; ekrandan, 01:15:00): Bölüm 9.2'deki programda (proseste) kaç thread vardır?

> **Cevap (derste verildi):** İki: `main`'den başlayan ana thread ve `pthread_create` ile oluşturulan thread.

**Soru 7** (ekrandan, 00:35:00): Bir proseste neden birden fazla thread'e ihtiyaç duyulur; neden tek (varsayılan) ana thread her durumda yetmez?

> **Cevap (derste verildi):** Gerçek zamanlı girdiler alıp her girdiye bir çıktı üretmesi gereken bir proses tek thread'le çalışırsa bütün işlem senkron olur: bir girdi alınır, işlenir, çıktı üretilir ve ancak sonra sıradaki girdiye geçilir. Birden fazla thread ile girdi alma ve işleme gibi bağımsız işler eş zamanlı yürütülebilir.

## Dersin Toparlaması

Bu derste önce çok dosyalı bir C projesinin makefile ile nasıl derlendiği görüldü: başlık dosyası fonksiyon prototiplerini, `.c` dosyaları gövdeleri taşır; her `.c` dosyası nesne dosyasına derlenir ve nesne dosyaları bağlanarak çalıştırılabilir dosya oluşturulur. Ardından program, proses ve thread kavramları ayrıldı; birçok prosesin tek işlemciyi çok çekirdek, zamanlama ve bağlam değiştirme ile nasıl paylaştığı süpermarket örneğiyle anlatıldı. Thread'in proses içindeki bir yürütme akışı olduğu, aynı prosesin thread'lerinin belleği ve dosya tanımlayıcılarını paylaştığı, eşzamanlamalarının ise programcıya bırakıldığı vurgulandı; kötü eşzamanlamanın kilitlenme ve açlığa yol açtığı kavşak ve unutulan proses örnekleriyle gösterildi.

İkinci yarıda C'de `pthread.h` ile thread oluşturma (`pthread_create`), sonlandırma (`pthread_exit`) ve bekleme (`pthread_join`) örnekleri yazıldı. Thread'lerin çalışma sırasının kestirilemediği, thread'e struct gönderilebildiği ve farklı thread'lerin farklı fonksiyonlarla çalışabildiği görüldü. Ortak değişken üzerindeki `A = A + 1` gibi işlemlerin atomik olmadığı, bu yüzden kilit ve mutex gerektiği banka ve yemek yiyen filozoflar örnekleriyle anlatıldı. Ders, yapısal programlamanın kapsamının özetlenmesi ve struct'ların metot da taşıyan hali olan sınıflarla nesneye yönelik programlamaya kısa bir girişle bitti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
