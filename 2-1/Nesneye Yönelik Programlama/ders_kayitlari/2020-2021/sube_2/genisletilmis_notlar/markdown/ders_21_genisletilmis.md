# Ders 21 Genişletilmiş Notu: Çoklu İş Parçacığına Giriş (Multithreading) ve JUnit ile Birim Sınama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Multitasking, multithreading, process ve thread
- 2. Paralel programlamanın zorlukları ve hızlanma sınırı
- 3. Thread'in yaşam döngüsü
- 4. Bir thread nasıl beklemeli?
- 5. Bir görevi ayrı thread'de çalıştırmanın dört adımı
- 6. Maç seyreden taraftarlar örneği
- 7. Birim sınama ve xUnit ailesi
- 8. JUnit 3.x ile test hazırlama
- 9. JUnit 4.x'in getirdikleri
- 10. Video kiralama örneği: tasarım
- 11. Video kiralama örneği: kaynak kod
- 12. Kara kutu ve beyaz kutu sınaması
- 13. Test sınıflarının yazılması ve çalıştırılması
- 14. Testlerle hata yakalama
- Örnek Sorular

## 1. Multitasking, multithreading, process ve thread

Multithreading, bir program akışında birden fazla paralel akışla aynı anda birden fazla iş yapmak demektir. Bunu anlamak için önce multitasking'den farkını ve process (süreç) ile thread (iş parçacığı) kavramlarını bilmek gerekir. Bunlar aslında işletim sistemi düzeyinde tanımlanan kavramlardır; programlama dilleri işletim sisteminin bu yeteneklerini kullanabilecek biçimde tasarlanır.

Multitasking, bir bilgisayar sisteminde aynı anda birden fazla programın çalışmasıdır. Programların nasıl ve hangi sırayla çalıştırıldığına göre alt türler ortaya çıkar. Yıllardır bilgisayarlardaki mikroişlemciler birden fazla çekirdek içerir; cep telefonları bile 4, 6, 8 çekirdeklidir. Bu, her çekirdeğe bir görev verilirse aynı anda birden fazla işin yapılabileceği anlamına gelir. İşletim sisteminin sürekli çalışması gereken kısımları bazı çekirdeklere atanır, kalan kaynaklarda kullanıcının çalıştırdığı uygulamalar yürütülür. Bir uygulama birden fazla işi aynı anda yaptırarak daha yüksek başarım elde edebilir.

Hocanın örneği bir web sayfasının açılmasıdır: bir yandan sayfadaki betikler çalışır, bir yandan resimler iner. Betik çalıştırma ve inen resmi ekrana çizme işleri aynı anda yapılırsa sayfa önümüze daha kısa sürede tamamlanmış olarak gelir.

Bunun için birden fazla çekirdek şart değildir. Tek çekirdekli bir bilgisayarda da işlerin biraz birini, sonra ötekini, sonra bir başkasını yaparak, yani her göreve sırayla biraz çalışma zamanı vererek multitasking yapılabilir. Görevler aslında sırayla çalışır, ama biri diğerine çok hızlı geçildiği için paralel çalışıyormuş gibi görünür. Multithreading ise işin gerçekten paralel yürütülmesidir: işlemcide birden fazla çekirdek varsa görevler gerçekten aynı anda çalışabilir.

Process ile thread arasında da fark vardır; process, thread'e göre daha kapsamlı bir yürütme birimidir.
<!-- BELİRSİZ: 00:09:34 civarında process ve thread farkı altyazıda bozuk ("Process, thread'den daha az bir süreçtir"); hocanın kesin tanımı anlaşılamadı. -->

> **Ek bilgi (derste anlatılmadı):** Genel kullanımda process, kendi bellek alanı olan, çalışan bir programdır. Thread ise bir process içindeki yürütme akışıdır; aynı process'in thread'leri belleği paylaşır. Bu yüzden thread oluşturmak process oluşturmaktan daha hafiftir, ama paylaşılan bellek tutarlılık sorunlarına yol açabilir.

Hoca ayrıca donanımın kendi içinde de paralellik olduğunu hatırlattı. Mikroişlemcinin tek bir işlem birimi yoktur: aritmetik işlemleri, mantık işlemlerini ve ondalıklı sayı işlemlerini yapan ayrı bileşenleri vardır. Kod bu farklı bileşenlere ihtiyaç duyuyorsa işler bu alt bileşenlerde paralel yürütülebilir. Ayrıca kod makine diline çevrildiğinde, birbirine bağımlı olmayan komutlar sıra dışı çalıştırılabilir. Örneğin `x = x + 2` komutunda x okunur, 2 eklenir, sonuç tekrar x'e yazılır; bu adımlar sırayla yapılmalıdır. Ama `x = x + 2` ile `y = y / 3` (x tam sayı, y ondalıklı) birbirinden bağımsızdır ve herhangi bir sırayla yapılabilir. Derleyiciler ve hatta mikroişlemciler bu bağımlılıkları algılayıp komutları verilen sıranın dışında düzenleyebilir. Yani bize hissettirmeden bazı şeyler zaten paralel yürüyor olabilir. Fakat programın algoritmasını bilinçli olarak paralel çalışabilecek görevlere ayırırsak program her durumda daha hızlı çalışır. Bu tür programlar yazmaya multithreaded program yazmak denir.

## 2. Paralel programlamanın zorlukları ve hızlanma sınırı

Bu derste konuya yalnız bir bakış atılacaktır; konu çok daha derindir. En temel problem, ortak paylaşılan kaynaklara eş zamanlı erişimde ortaya çıkan tutarlılık sorunlarıdır. Algoritmayı bu sorunlara yol açmayacak biçimde tasarlamak çok zordur. Bunun yerine bilgisayar bilimleri literatüründe bu tutarsızlıkları önleyecek yapılar önerilmiştir: monitörler ve semaforlar. Ders bunlara girmeyecek; temel senkronizasyon problemlerini çözmek için daha basit bir mekanizma olan ve Java'nın desteklediği nesne kilidi mantığına kadar ilerleyecek. Hoca, paralel programlamanın bir buzdağı olduğunu, burada yalnız ucunun keşfedileceğini, ayrıntının işletim sistemleri dersinde görüleceğini söyledi.

Hoca bir soru sordu: işinizi aynı anda yürütülebilecek dört parçaya ayırırsanız iş dört kat hızlanır mı? Genelde hayır. Birincisi, kodun paralel çalışması için işletim sisteminin hazırlık yapması, thread'ler açması gerekir; thread açmak ve yürütmeye başlamak ek yük getirir. İkincisi, thread'lerin bir kısmı büyük olasılıkla birbirini beklemek zorunda kalır; çabuk biten, geriden gelen yavaş thread'i beklemek zorunda olabilir. Bu nedenlerle "ne kadar thread, o kadar kat performans" kuralı geçerli değildir; program thread sayısından daha düşük bir çarpanla hızlanır, ama sonuçta hızlanır.

## 3. Thread'in yaşam döngüsü

Oluşturulan her thread bir yaşam döngüsünden geçer. Bu döngüde thread çeşitli durumlardan birinde bulunur; bir durumdan diğerine geçişin olayları ve kuralları vardır (ekrandan, 00:15:00; slayt 211):

```text
            new             start
  ------> [ new ] -------------------> [ runnable ] <---------------------------+
                                         |      ^                               |
                              scheduler  |      |  yield, time slice            |  notify, notifyAll,
                                         v      |                               |  IO complete,
                                       [ running ] ----------------------> [ blocked ]
                                         |          IO, sleep, wait, join       sleep expired,
                              terminate  |                                     join complete
                                         v
                                       [ dead ]
```

- **new:** Thread de aslında bir nesnedir. Constructor ile oluşturulduğunda "yeni oluşturulmuş" durumundadır, hemen koşmaya başlamaz.
- **runnable:** `start` çağrılınca thread çalışmaya hazır hale gelir. Hemen çalışmaz; işletim sisteminin zamanlayıcısını (scheduler) bekler.
- **running:** Scheduler "sıra sende" dediğinde thread koşmaya başlar ve verilen kodu yürütür.
- **blocked:** Thread bir şeyi beklemek zorundaysa bu duruma alınır.
- **dead:** İşi biten thread sonlanır; onunla ilgili sistem kaynakları temizlenir.

Scheduler'ın belirleyici olmasının nedeni, işletim sisteminin çalıştığı bilgisayarın kaynaklarının farklı olabilmesidir: tek çekirdekli ya da çok çekirdekli olabilir. Eski işletim sistemleri multithreading'i desteklemiyor, yalnız sırayla birinden ötekine geçiyordu. Java'nın taşınabilirliği düşünüldüğünde de kodun güçlü bir bilgisayarda çalışacağı varsayılamaz; çok daha düşük kaynaklı bir sistemde çalışıyor olabilir.

Running durumundaki thread verilen kodu baştan sona yürüteceğinin garantisi yoktur; büyük olasılıkla yürütmez. Time slice (zaman dilimi) kavramı vardır: scheduler hiçbir thread'e işlemcinin tüm hakkını vermez. Birden fazla çekirdek olsa bile aynı anda yürütülmesi gereken başka süreçler ve uygulamalar vardır. Bir noktada scheduler thread'e "bu kadar çalıştın, biraz kenara geç, diğerleri çalışsın" der; thread'e ayrılan zaman dilimi biter ve thread yeniden runnable durumunda beklemeye başlar. Programcı `yield` komutuyla bir thread'in gönüllü olarak "bu kadar çalışmam yeterli" demesini de sağlayabilir; bu ders kapsamında kullanılmayacak ama mümkündür. Yani thread işini bitirene kadar running ve runnable durumları arasında gidip gelir.

Thread çalışmaya devam etmek için bir şey beklemek zorundaysa ne olur? Bu bir girdi/çıktı (G/Ç) işlemi olabilir: kullanıcının komut satırından bilgi girmesini beklemek, bir ağ bağlantısını dinleyip akıştan byte gelmesini beklemek ya da diske bir şey yazmak (bir önceki hafta görüldü). Disk işlemleri bellek işlemlerine göre yavaştır. Scheduler G/Ç yapacak thread'e "bu işi ben yapacağım, ama disk uygun olana kadar vakit var; sen biraz dinlen, iş bitince seni uygun zamanda tekrar çağırırım" der. Hoca burada önce "runnable konumunda bekler" deyip hemen düzeltti: thread runnable'da değil, ayrı bir blok kuyruğunda bekler.

Thread başka bir thread ile senkronize olmak, onun işini bitirmesini beklemek için de blocked durumuna geçebilir. `wait` ve `join` komutları bunun içindir: bir thread ötekine katılır (join), biri ötekini bekler (wait). Bunlar bu derste ayrıntılı görülmeyecek, ama `sleep` işlemi görülecek: bir thread belli bir süre iş yapmadan uykuda beklemeyi seçebilir. Örneğin bir ağ bağlantısı dinleniyorsa sürekli "paket geldi mi" diye yoklamak yerine 3 saniyede bir yoklamak, arada uykuda beklemek, yani meşgul beklememek tercih edilebilir.

G/Ç işlemi gerçekleşince ya da uyku süresi dolunca thread hemen running durumuna geçmez, runnable durumuna geri düşer ve scheduler'ın sırayı kendisine vermesini bekler. Blocked'dan runnable'a geçişin olayları şunlardır: G/Ç'nin bitmesi, uyku süresinin dolması, join (katılma) işleminin tamamlanması ya da kendisini bekleyen thread'leri bilgilendiren `notify` veya `notifyAll` çağrısı.

> **Hocanın vurgusu:** Bu konudan çıkarılacak üç sonuç var. Birincisi, thread'iniz sürekli çalışmaz, aralarda bekler. İkincisi, bir thread'in ne zaman çalışacağı üzerinde hiçbir kontrolünüz yoktur; esas kontrol scheduler'ın elindedir. Üçüncüsü, birden fazla thread'iniz varsa bunların hangi sırada çalışacağının, hangisinin önce hangisinin sonra biteceğinin hiçbir garantisi yoktur. Algoritmayı tasarlarken "önce şu başlar, sonra şu biter" diye bir varsayım kesinlikle yapılmamalıdır.

## 4. Bir thread nasıl beklemeli?

Slaytta bu soru şöyle cevaplanır (ekrandan, 00:25:00; slayt 212): bir thread bir engel yüzünden görevine devam edemiyorsa engel kalkana kadar beklemelidir. Engel, gereken bilginin ağdan, başka bir thread'den ya da kullanıcıdan henüz gelmemiş olmasıdır.

Hocanın benzetmesi bir araba yolculuğudur: yanınızdaki arkadaşınız ya da çocuk sürekli "geldik mi, geldik mi" diye sorar; "daha var, otur, uyu, kitap oku" dersiniz ama soru devam eder ve can sıkıcıdır. Thread'de de sürekli "işlem tamamlandı mı" diye bakmak ya da işlemciyi elden kaçırmamak için boş bir döngüde sürekli bir sayacı artırmak gibi şeyler kodlanabilir. Buna busy waiting (meşgul bekleme) denir; slayttaki örnek boş bir döngüyü 10.000 kez çalıştırmaktır. Scheduler'ın bu tuzağa düşüp düşmeyeceği bilinemez; farklı işletim sistemlerinin scheduler'ları farklı algoritmalarla çalışır, busy waiting işe yarayabilir de yaramayabilir de. Ama yarasa da yaramasa da bilgisayara boş yere iş yaptırmak, diğer bütün süreçler düşünüldüğünde sistemin responsiveness'ını (hızlı ve akıcı yanıt verme özelliğini) azaltır ve sistem kaynaklarını verimsiz kullanır.

Bunun yerine thread `sleep` komutuyla blocked durumuna alınmalıdır. Uyuyan thread, meşgul bekleyen thread'in aksine sistem kaynağı tüketmez. Ancak bir risk vardır: uyku durumuna geçen thread uyanamayabilir. Bu yüzden `sleep` kullanıldığında checked bir istisna olan `java.lang.InterruptedException` yakalanmalıdır. Hoca, basit örneklerde bu istisnayla pek karşılaşılmadığını, ama checked olduğu için `try-catch` ile işlenmesinin zorunlu olduğunu belirtti.

## 5. Bir görevi ayrı thread'de çalıştırmanın dört adımı

Bir görevi yeni bir thread üzerinde kodlayıp koşturmak için dört işlem gerekir (ekrandan, 00:30:00; slayt 213):

1. Paralel çalışması istenen kod, `Runnable` arayüzünü gerçekleyen bir sınıfın `run` metoduna yazılır. `Runnable` `java.lang` paketindedir, ayrıca import gerekmez. `run` metodu `public void run()` biçimindedir, parametre almaz ve `Runnable` arayüzünde tanımlıdır.
2. `new` ile constructor kullanılarak bu sınıftan bir nesne oluşturulur.
3. Yine `java.lang` paketindeki `Thread` sınıfından bir nesne oluşturulur; constructor'ına ikinci adımda oluşturulan nesne parametre olarak verilir.
4. Bu `Thread` nesnesinin `start` metodu çağrılarak thread başlatılır. `Thread` sınıfının `run` metodu da vardır, ama doğrudan çağrılmaz; çağrılırsa kod paralel değil sıralı çalışır.

Paralel çalışacak kodun bulunduğu sınıf `Thread` sınıfından kalıtımla da türetilebilir. Hoca bunu önermiyor: bu durumda Java'daki tek kalıtım hakkı kullanılmış olur ve iş mantığı gereği kurulması gereken bir kalıtım ilişkisi kurulamayabilir. Kalıtım ağır bir ilişkidir, yalnız gerçekten gerektiğinde kullanılır ve bu hak iş mantığına ayrılmalıdır; altyapı için harcanmamalıdır. `Runnable` arayüzünü gerçekleyen bir sınıf yazmak yeterlidir. Slayttaki ifadeyle: kendi thread'inizi `Thread`'den kalıtımla kodlamayın, yoksa tek kalıtım hakkınızı boşa harcarsınız.

Dikkat edilecek bir nokta daha vardır: `run` metodu parametre almadığına göre paralel çalışacak göreve bilgi nasıl aktarılır? Ya nesne oluşturulurken constructor üzerinden ya da setter metotları üzerinden. Setter kullanılıyorsa bu çağrılar mutlaka dördüncü adımdan, yani `start`'tan önce yapılmalıdır.

## 6. Maç seyreden taraftarlar örneği

### 6.1 Senaryo

Maç seyreden birkaç kişinin simülasyonu yapılacak (sayı dört, altı, fark etmez). Maç sürerken bu kişiler ara sıra, rastgele bir sürede heyecanlanıp kendi tuttukları takıma tezahürat yapar. Her taraftar 0 ile 1000 milisaniye arasında rastgele bir sürede heyecanlanır ve 10 kez tezahürat yaptıktan sonra yorulup maçı sessizce seyretmeye devam eder (ekrandan, 00:30:00).

Rastgele süre, işlerin rastgeleliğini vurgulamak için seçildi. Thread'lerin hangi işi hangi sırada yapacağı zaten bizim kontrolümüzde olmadığı için bir belirsizlik vardır; multithreading örneklerinde bazı şeyleri rastgele aralıklarla yaparak bu belirsizlik bilerek artırılır. Bu, sonraki derslerde görülecek senkronizasyon problemlerini daha belirgin ortaya çıkaran bir etken olarak kullanılacak; o etken olmasa da senkronizasyon problemi çıkabileceği de görülecek. Bu örnekte ise senkronizasyon problemi yoktur: heyecanlanan taraftar ekrana yalnız bir satır yazar, birinin okuyup ötekinin yazdığı ortak bir kaynak yoktur. Böylece multithreaded koda en basit biçimde ilk adım atılır.

### 6.2 SoccerFan sınıfı

Taraftar sınıfının adı `SoccerFan`'dır. Birinci adım gereği `implements Runnable` denir. Tezahürat sayısı (10) ve en uzun bekleme süresi (1000 ms) değişmeyeceği için `public static final int` sabitler olarak tanımlanır; sabit oldukları için böyle tanımlamanın sakıncası yoktur. Her taraftarın tuttuğu takım ve tezahürat metni farklı olacağından bunlar normal üye alanlardır ve constructor ile verilir. Hoca bilgiyi genelde constructor üzerinden aktarmayı tercih ediyor. Ardından `public void run()` metodu kodlanır; sınıfın `Runnable`'ı gerçeklemesi ve `run` metodu birlikte birinci adımı oluşturur.

0 ile n arasında rastgele bir tam sayı üretmek için `java.util.Random` türünden bir nesne varsayılan constructor ile oluşturulur, sonra `nextInt`, `nextDouble` gibi metotlarından biri çağrılır. `run` içinde bir `for` döngüsü, tezahürat sayısı kadar dönerek takım adını ve tezahüratı ekrana yazar, ardından 0-1000 ms arasında rastgele bir süre bekler. Busy waiting yapılmayacağı için `Thread` sınıfının statik `sleep` metodu kullanılır ve parametre olarak rastgele sayı verilir. `sleep` checked bir istisna olan `InterruptedException` oluşturabileceği için `for` döngüsü `try` bloğuna alınır, istisna `catch` ile yakalanır ve `printStackTrace` çağrılır; hoca bir önceki hafta bir istisna ele alınırken en azından bunun yapılması gerektiğini söylemişti.

<!-- BELİRSİZ: SoccerFan slaytı (214) karelerde görünmüyor. Aşağıdaki kod altyazıdaki anlatıma göre kurulmuştur; sabit ve alan adları ekrandakinden farklı olabilir. -->

```java
import java.util.Random;

public class SoccerFan implements Runnable {
    public static final int STEPS = 10;   // tezahürat sayısı (ad tahmini)
    public static final int DELAY = 1000; // en uzun bekleme, ms (ad tahmini)
    private String team;
    private String shout;

    public SoccerFan(String team, String shout) {
        this.team = team;
        this.shout = shout;
    }

    public void run() {
        Random random = new Random();
        try {
            for (int i = 0; i < STEPS; i++) {
                System.out.println(team + " " + shout);
                Thread.sleep(random.nextInt(DELAY));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
```

### 6.3 Match sınıfı

İkinci, üçüncü ve dördüncü adımlar ayrı bir sınıfın `main` metodunda yapılır (ekrandan, 00:35:00; slayt 215):

```java
package nyp14a;

public class Match {
    public static void main(String[] args) {
        Thread aThread;
        aThread = new Thread( new SoccerFan("G.S.", "Rulez!") );
        aThread.start( );
        aThread = new Thread( new SoccerFan("G.S.", "is the champ!") );
        aThread.start( );
        aThread = new Thread( new SoccerFan("F.B.", "is no.1!") );
        aThread.start( );
        aThread = new Thread( new SoccerFan("F.B.", "is the best!") );
        aThread.start( );
    }
}
```

Aynı işler `SoccerFan` sınıfında da yapılabilirdi, ama hoca iş mantığını oluşturan sınıf ile onu multithreaded çalıştıracak sınıfı ayırmayı tercih etti. Bunlar özünde iki farklı görevdir ve nesneye yönelim de bir programı mümkün olduğunca kendi içinde en yüksek uyuma sahip parçalara ayırmayı ister. `Thread` değişkeni ileride gerekeceği için yukarıda tanımlandı. `new SoccerFan(...)` ile ikinci adım yapılır; ayrı bir geçici `SoccerFan` değişkeni tanımlanmadı, çünkü ihtiyaç yoktu; nesne doğrudan `Thread` constructor'ına verildi (üçüncü adım). `start` ile dördüncü adım tamamlanır. Aynı iş dört kez tekrarlanarak dört taraftar multithreaded olarak çalıştırılır.

### 6.4 Çalıştırma ve sonuç

`G.S. Rulez!`, `G.S. is the champ!`, `F.B. is no.1!`, `F.B. is the best!` nesneleri bu sırayla oluşturulup başlatıldı. `SoccerFan`'ın kodunda taraftar önce bağırıp sonra beklediği için en azından ilk tezahüratların bu sırayla geleceği düşünülebilir; önce bekleyip sonra bağırsalardı zaten her şey rastgele olurdu. Ama bu bile olmadı. Hocanın ilk çalıştırmasında ilk tezahüratlar ikinci, üçüncü, birinci, dördüncü nesne sırasıyla geldi (2-3-1-4). İkinci çalıştırmada birinci nesne birinci, üçüncü nesne ikinci, ikinci nesne üçüncü sırada çıktı. Dördüncü nesne birkaç çalıştırmada hep dördüncü sırada çıktı; hoca bu eğilimi gördüğünü ama önceden bilemeyeceğini, başka donanım, işletim sistemi, JDK ya da IDE'de farklı olabileceğini söyledi. Her taraftar 10 kez tezahürat yaptığı için toplam 40 satır çıktı oluşur.

> **Ders sonrası not:** Yukarıdaki `SoccerFan` ve `Match` kodu birlikte `java Match.java` ile çalıştırıldı: 40 satır çıktı alındı ve satırların sırası her çalıştırmada değişti; ilk satırların sırası da oluşturma sırasına uymadı.

### 6.5 Soru: thread nasıl başlatılır? `run` ile `start` farkı

**Soru:** Thread'i nasıl başlatıyoruz, hangi metot kullanılıyor?

**Cevap:** Dördüncü adımda `Thread` nesnesinin `start` metodu çağrılır. `SoccerFan` nesnesi bir `Thread` ile ilişkilendirilir ve o thread başlatılır. `SoccerFan` doğrudan başlatılamaz, çünkü onun `start` diye bir metodu yoktur; yalnız `run` metodu vardır ve `run`'ı doğrudan çağırmak multithreaded çalışmak anlamına gelmez.

Hoca bunu göstermek için `main`'in başına iki `SoccerFan` nesnesi daha ekleyip (birinin tezahüratı "... is the real champ" idi) bunların `run` metodunu doğrudan çağırdı. Sonuçta önce birinci nesne 10 tezahüratını tamamen yaptı, sonra ikinci nesne 10 tezahüratını yaptı; ancak bundan sonra `start` ile başlatılan dört taraftar paralel olarak, karışık sırayla tezahürat yaptı. Ardından `Match` içindeki `start` çağrılarını `run` yaptı (ekrandan, 00:45:00): bu durumda her nesne 10 tezahüratını bitirip sırayı ötekine bıraktı ve program çok daha uzun sürdü; multithreaded çalışsaydı iş çoktan bitmiş olurdu. `start` ile çalıştırıldığında ise iş çok daha çabuk bitti.

> **Hocanın vurgusu:** Bir thread ancak `start` metoduyla başlatılır. Thread'lerin yanlışlıkla `start` yerine `run` metodunu çağırmayın; yoksa işler multithreaded değil sıralı yürür.

## 7. Birim sınama ve xUnit ailesi

Konunun ikinci yarısı birim sınamadır (unit testing). Unit testing, en küçük programlama biriminin sınanması demektir. Nesneye yönelik programlamada en küçük programlama birimi sınıflar, aslında nesnelerdir: `new` ile ilklendirilip kullanılan temel birim odur, onu kodlayabilmek için de sınıf yazmak gerekir. Bu nedenle "birim" denince sınıflar ve nesneler düşünülür.

Ders boyunca yazılan birçok kodda işin doğru yapılıp yapılmadığını anlamak için testler yapıldı; örneğin parça-bütün ve bire-çok sahiplik ilişkilerinde, ders ve öğrenci örneğinde aynı öğrencinin aynı derse iki kez eklenmemesi, kapasite aşılmışsa yeni öğrenci eklenmemesi gibi kurallar sınandı. Bu yapılırken boolean dönen metotlar çağrıldı, sonucun true ya da false olmasına göre testin başarılı olup olmadığına bakıldı, bir yerde takılınca neden takıldığı açıklanıp hata arandı. Fark ettirmeden epey iş yapıldı. Bu işlerin bir kısmının otomatikleştirilmesi yararımızadır. Hoca yazılım mühendisliği dersinde de söyleneceği gibi yazılımın sınanmasının zor bir iş olduğunu vurguladı: yazılım geliştirmenin kendisi zor olduğu için onun sınaması da zordur; bu yüzden işi kolaylaştıran gereçlere çok ihtiyaç vardır.

Önceki haftalarda yapılan test işlerinin bir kısmını otomatikleştirip testleri hızla çalıştırmayı ve sonuçlarını anlamayı sağlayan gereçler xUnit ailesidir. X yerine kullanılan programlama dili konur: Java için JUnit, C# için CSUnit çatısı (framework) vardır; başka diller için de benzerleri vardır. Altyapıyı her sınama kodunda tekrar yazmak yerine bu işleri hazır sunan bir çatının üstünde asıl testleri tasarlamaya odaklanmak yarar sağlar.

JUnit'in çalışma biçimini değiştiren ve önemli yetenekler getiren iki temel sürümü vardır: 3.x ve 4.x (sonraki sürümler de çıktı). Temel birim sınama işlemleri 3.x ile yapılabilir; 4.x'te işin içine istisnalar da girer. Ders istisnaları da işlediği için asıl öğrenilmesi gereken 4.x'tir. Geriye uyumluluk olduğu için önce 3.x, sonra 4.x gösterildi; hoca projelerde 4.x kullanmanın daha yararlı olacağını söyledi.

## 8. JUnit 3.x ile test hazırlama

Slayttaki diyagramda (ekrandan, 01:05:00; slayt 230) iki paket vardır. `junit.framework` paketinde `TestCase` sınıfı (korumalı `setup()` metoduyla) ve `Assert` sınıfı bulunur. `myPackage` paketi iş mantığını içeren sınıfların bulunduğu pakettir: `AppClass1`, `AppClass2` iş sınıfları; `TestAppClass1` (`+testXXX()`), `TestAppClass2` (`+testYYY()`) test sınıfları; `TestAll` (`+suite(): Test`) ise suite sınıfıdır. Test sınıfları `TestCase`'ten türetilir ve sınadıkları iş sınıfına bağımlıdır.

- **Test sınıfları:** `AppClass1`'in test vakaları `TestAppClass1` adlı bir sınıfta, `AppClass2`'ninkiler `TestAppClass2`'de kodlanır. JUnit 3.x'te test sınıfı adının `Test` ile başlaması zorunludur.
- **Test vakaları:** Bir sınıfın birden fazla sorumluluğu olabileceği için bir test sınıfında birden fazla sınama yapılır. Adı `test` ile başlayan her metot (`testXXX`, `testYYY`, `testZZZ`) bir test vakası (test case, test senaryosu) olur. Aynı sınıfla ilgili test senaryoları aynı test sınıfında biriktirilir.
- **Suite:** Test sınıfları ayrı ayrı çalıştırılabileceği gibi birkaçı bir suite altında birleştirilip tek adımda başlatılabilir; bunun için statik `TestAll.suite()` metodu kullanılır.
- **Kalıtım:** Test sınıflarının birim sınaması olarak algılanıp yürütülebilmesi için `junit.framework.TestCase` sınıfından kalıtımla türetilmesi gerekir.
- **setUp:** `TestCase`'in korumalı `setup` metodunun özel bir görevi vardır. Bir şeyi sınamadan önce onu ilklendirmek, ilişkili olduğu nesneleri ve aralarındaki ilişkileri kurmak, yani sahneyi hazırlamak gerekir. Önceki örneklerde de önce ders ve öğrenciler oluşturulup öğrenci derse eklenmiş, sonra eklenip eklenemediği, kapasite dolunca ekleme yapılmaması gibi kontroller yapılmıştı. Bütün test metotlarının ortak ön hazırlığı bu metoda yazılır ve JUnit çatısı her test metodundan önce onu otomatik olarak çalıştırır.

Test metotlarında testin başarılı olup olmadığını ölçmek için `Assert` sınıfının statik metotlarından biri kullanılır. Normalde elde edilen sonuç ile beklenen sonuç birbirine eşitse test başarılıdır:

| Metot | Test ne zaman başarılı? |
|---|---|
| `assertEquals(beklenen, sonuc : Object)` | İki nesne birbirine eşitse |
| `assertNotEquals(Object, Object)` | İki nesne eşit değilse |
| `assertTrue(boolean)` | Verilen boolean ifade true ise |
| `assertFalse(boolean)` | Verilen boolean ifade false ise |
| `assertNull(Object)` | Verilen nesne null ise |
| `assertNotNull(Object)` | Verilen nesne null değilse |

`assertNull`/`assertNotNull`, bir metodun döndürdüğü nesnenin null olup olmamasına göre kurulan senaryolar içindir. Slaytta metotların public olduğu gösterilmiş, statik oldukları gösterilmemiştir; hoca bunların statik olduğunu sözlü olarak ekledi.

## 9. JUnit 4.x'in getirdikleri

JUnit 4.x, 3.x ile uyumludur. Ek olarak test sınıflarının adını `Test` ile, test metotlarının adını küçük harfle `test` ile başlatma zorunluluğunu kaldırır. İki önemli yenilik getirir: annotation (ek açıklama) ile çalışma ve bir istisnanın oluşup oluşmadığını sınama.

- Test sınıflarını `TestCase`'ten kalıtımla türetmek artık gerekmez. Geriye uyumluluk için hâlâ yapılabilir, ama tek kalıtım hakkını başka bir nedenle kullanmak gerekiyorsa onu test altyapısı için harcamak zorunda kalınmaz.
- Test metotlarının adının `test` ile başlaması gerekmez; her test metodunun başına `@Test` annotation'ı koymak yeterlidir.
- `setUp` metodu yerine hazırlık amaçlı yazılan metodun başına `@Before` konur; bu metot her test metodundan önce otomatik çalışır.
- İstisna sınaması: Bir istisna oluştuğunda (checked ya da unchecked) program kesilir. Ama sınama sırasında istisnayı bilerek oluşturmak ve sonraki test vakasıyla devam etmek isteriz; 3.x'te bu yapılamıyordu, 4.x'te yapılabilir. `@Test` annotation'ına `expected = <İstisnaAdı>.class` parametresi verilir. Bu metodun gövdesine istisnayı oluşturabilecek çağrılar yazılır; checked bir istisnaysa metodun onu `throws` ile bildirmesi gerekir. Burada assert kullanmak gerekmez: metot içinde o istisna fırlatılmışsa birim sınaması başarılıdır, fırlatılmamışsa başarısızdır.

Hoca, JUnit 4'te zorunlu olmasa da bir metodun ne işe yaradığını adından anlayabilmenin önemli olduğunu düşündüğü için test metotlarının adını yine `test` kelimesiyle başlatmayı tercih ettiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** JUnit 4'te bu annotation'lar `org.junit` paketindedir (`org.junit.Test`, `org.junit.Before`), assert metotları da genellikle `import static org.junit.Assert.*;` ile kullanılır. JUnit 5'te ise `@Before` yerine `@BeforeEach`, `expected` yerine `assertThrows` kullanılır.

## 10. Video kiralama örneği: tasarım

Çatıyı denemek için sınanacak bir şeye ihtiyaç vardır. Örnek, Martin Fowler'ın *Refactoring: Improving the Design of Existing Code* (Addison-Wesley, 1999) kitabından alınmıştır (ekrandan, 01:15:00; slayt 232). Kitap, nesne yöneliminin yanlış anlaşılmasından doğan tasarım kusurlarını (code smell, ölçeğine göre anti-pattern) ve bunların nasıl tanınıp giderileceğini anlatır.

Örnek bir video kaset kiralama sistemidir. Müşteriler çeşitli filmleri belirli sürelerle kiralar. Her kiralama işlemi bir `Rental` nesnesinde tutulur. Bir müşterinin n adet kira kaydı vardır; bir kira kaydı bir filmle ilişkilidir. Sistemde üç tür film vardır: normal filmler, yeni çıkan filmler (new release) ve çocuk filmleri. Farklı türdeki filmlerin farklı sürelerde kiralanmasının bedelleri ve kazandırdığı bonus puanlar farklıdır.

Sınıf diyagramı:

| Sınıf | Alanlar | Metotlar |
|---|---|---|
| `Movie` | `- _priceCode : int` | `+ getCharge(daysRented : int) : double`, `+ getBonus(daysRented : int) : int` |
| `Rental` | `- _daysRented : int` | `+ getCharge() : double`, `+ getBonus() : int`, `+ getMovieTitle() : String` |
| `Customer` | | `+ statement()`, `+ getTotalCharge() : double`, `+ getTotalBonus() : int` |

İlişkiler: `Customer` (1) → `Rental` (*), `Rental` (1) → `Movie` (1); oklar tek yönlüdür.

Hoca bu programı kendisi tasarlasaydı farklı türde filmler olduğu için `Movie`'yi soyut bir üst sınıf, `NewRelease`, `Regular` ve `Childrens`'ı somut alt sınıflar yapacağını söyledi. Örnekte film türü bir fiyat koduyla tutulmuştur; bu çok doğru bir tasarım değildir. Ama refactoring, adı üstünde, tasarım kusurları olan bir kodu adım adım iyileştirmektir; kitaptaki örnek başta çok daha kötüdür ve 12 kadar adımdan geçirilerek iyileştirilir. Buradaki hal yaklaşık 9. adımdır ve epey derli toplu, iyi bir tasarım sayılır; tek istisna, kalıtım ve çok biçimliliğin kullanılmamış olmasıdır.

- `Customer.statement()`: Müşterinin hangi filmi kaç günlüğüne kiraladığını ve her kiralamadan doğan borcu satır satır yazıp sonda toplam borcu ve toplam bonusu ekleyen bir makbuz oluşturur ve bunu `String` olarak döndürür. Toplam borç ve toplam bonus iki yardımcı metotla hesaplanır. Bire-çok sahiplik olduğu için kira kaydı ekleme metodu da vardır.
- `Rental`: Filmin kaç gün kiralandığını tutar. `Movie`'ye sahiplik ilişkisi olduğu için hangi filmle ilişkili olduğu da gizli bir üye alanda tutulur. `getCharge()` bu kiralamadan doğan borcu, `getBonus()` bonusu hesaplar; `getMovieTitle()` kiralanan filmin adını verir.
- `Movie`: Fiyat kodunu tutar; `getCharge` ve `getBonus` burada da tanımlıdır.

Bir film kaç gün kiralandığını bilmez. Bunu bilmesi için `Movie`'den `Rental`'a da bir ok çizip çift yönlü bir sahiplik ilişkisi kurmak gerekirdi. Ama dersin başındaki araba-insan örneğinden bilindiği gibi çift yönlü ilişkilerin tutarlılığını sağlamak ve sürdürmek için yazılacak kod daha karmaşıktır; ters yönde ilişkiye ihtiyaç yoksa kodlanmaz. Bunun yerine `Rental`, `Movie`'ye "sen şu kadar gün kiralandın, bedel ne olur, hesapla bana söyle" der; gün sayısını `getCharge` metoduna parametre olarak verir. Bonus için de aynısı `getBonus` ile yapılır.

### 10.1 Sequence diyagramı ve bağlaşım

Slaytın sağında `statement` metodunun sequence diyagramı vardır. Kullanıcı `aCustomer`'a `statement()` çağrısı yapar. Tüm kira kayıtları için (`*[for all rentals]`) `aCustomer`, `aRental`'a `getMovieTitle()` çağrısı yapar, o da `aMovie`'ye `getTitle()` çağrısı yapar; sonra `aCustomer`, `aRental`'a `getCharge()` çağrısı yapar, o da `aMovie`'ye `getCharge(_daysRented)` çağrısı yapar ("tek kira için ücret hesabı ve makbuz satırı basımı tamamlanır"). Ardından `aCustomer` kendi `getTotalCharge()` metodunu çağırır; bu metot tüm kayıtlar için `getCharge()` çağırır, `aRental` da `aMovie`'ye `getCharge(_daysRented)` çağrısı yapar. Aynı yapı `getTotalBonus()` → `getBonus()` → `getBonus(_daysRented)` için tekrarlanır ve "makbuz basımı tamamlanır".

Diyagrama metotları okumadan bakıldığında bile `Customer`'dan `Rental`'a ve `Rental`'dan `Movie`'ye çağrılar olduğu, `Customer`'dan `Movie`'ye hiç doğrudan çağrı olmadığı görülür. Bu katmanlı bir yapı sağlar. `statement` içinde film adını yazarken `Customer` doğrudan `Movie` nesnesine erişseydi, sınıf diyagramında gösterilmese bile `Customer`'dan `Movie`'ye sahiplik olmadan bir kullanma ilişkisi (bağımlılık) oluşacaktı. `Rental` zaten `Movie`'ye bağlı olduğu için `Customer` film adını dolaylı olarak `Rental` üzerinden alır ve `Customer` ile `Movie` arasında hiçbir ilişki kurulmaz. `getMovieTitle()` metodunun eklenme nedeni budur; `Movie` için bir getter yerine yalnız gereken bilgi, yani film adı için bir metot konmuştur.

> **Hocanın vurgusu:** İyi bir nesneye yönelik tasarımda bağlaşım (coupling) düşük, yani gereksiz ilişkilerden kaçınılmış olmalı; uyum (cohesion) yüksek, yani bir sınıfa atanan sorumluluklar birbirine olabildiğince yakın, aynı problem alanında olmalıdır. Bu iki ilke iyi tasarım için çok önemlidir. Derste yapılan bütün örneklerde tasarım fark ettirmeden bu ilkelere göre kuruldu.

## 11. Video kiralama örneği: kaynak kod

### 11.1 Üye alanların alt çizgiyle adlandırılması

Kodda üye alanlar alt çizgiyle başlayan adlar almıştır (`_name`, `_rentals`, `_title`, `_priceCode`). Bu, özellikle yapısal programlamada struct alanlarını geçici değişkenlerden ayırt etmek için iyi bir programlama alışkanlığı olarak bilinir. Nesneye yönelik programlamada da benzer bir amaçla kullanılır. IDE'de renklendirme sayesinde neyin üye alan, neyin geçici değişken ya da parametre olduğu bir bakışta görülür: örneğin `addRental` metodunda üye alan `_rentals` mavi, parametre `arg` koyu gri renklidir. Ama IDE kullanma lüksü her zaman yoktur: kâğıt üzerinde kod anlatırken, not bastırılınca ya da kitap olarak yayımlanınca renk bilgisi kaybolur. Refactoring kitaplarında kodun öncesi ve sonrası karşılaştırmalı verilir; renkli baskı pahalı olduğu için kitap genelde siyah-beyaz basılır, renkli fotokopi neredeyse orijinal kitap kadar pahalıdır, e-kitap okuyucunun renkli ekranı olmayabilir. Üye alanı, parametreyi ve geçici değişkeni ayırt edemeyen okuyucu bir kod kokusunu ve doğru refactoring'i anlayamaz. Kaybolan renk bilgisinin yerine üye alanlar alt çizgiyle adlandırılır.

### 11.2 Customer sınıfı

`Customer` sınıfı (ekrandan, 01:30:00 ve 02:15:00):

```java
package fowler_09;

import java.util.*;

public class Customer {
    private String _name;
    private Vector<Rental> _rentals = new Vector<Rental>();
    public Customer (String name){
        _name = name;
    }
    public void addRental(Rental arg) {
        _rentals.addElement(arg);
    }
    public String getName (){
        return _name;
    }
    public String statement( ) {
        Enumeration<Rental> rentals = _rentals.elements();
        String result = "Rental Record for " + getName() + "\n";
        while (rentals.hasMoreElements()) {
            Rental aRental = (Rental) rentals.nextElement();
            //show figures for this rental
            result += "\t" + aRental.getMovieTitle()+ "\t" +
            String.valueOf(aRental.getCharge()) + "\n";
        }
        //add footer lines
        result += "Amount owed is " + getTotalCharge() + "\n";
        result += "You earned " + getTotalBonus()
                + " frequent renter points";
        return result;
    }
    // getTotalCharge() ve getTotalBonus() aşağıda (karede görünmüyor)
}
```

Kira kayıtları `Vector<Rental>` listesinde tutulur. Kira kaydı ekleme metodunda aynı filmin bir daha eklenmemesi gibi bir kontrol yoktur; belki müşteri aynı kasetten iki tane kiralayıp birini kendisi izlerken birini arkadaşına vermek isteyebilir. Hoca bu tür kontrollerin daha önce çok yapıldığını, bu örneğin refactoring üzerine olduğunu ve bunların birim sınamasını yapmanın öğrencilere bırakıldığını söyledi.

`statement` vektörün üzerinde doğrudan dolaşmak yerine bir `Enumeration` (hocanın deyişiyle iterator) alıp onun üzerinden dolaşır; doğrudan dolaşmak da sorun olmazdı. Makbuz "Rental Record for <müşteri adı>" ile başlar. `while` döngüsünde listede sonraki eleman varsa alınır, film adı ve kiralamanın ücreti sekmeyle ayrılarak bir satıra yazılır. Sonda toplam borç ("Amount owed is ...") ve toplam bonus ("You earned ... frequent renter points") eklenip string döndürülür.

`getTotalCharge` metodu `for` döngüsüyle doğrudan `_rentals` üzerinde dolaşır, her kiralamanın `getCharge` metodunu çağırıp kümülatif toplama ekler ve toplamı döndürür. `getTotalBonus` da her kira kaydının bonusunu aynı biçimde toplar.

### 11.3 Rental sınıfı

`Rental` hangi filmle ilişkili olduğunu ve kaç gün kiralandığını iki üye alanda tutar; bu iki bilgi constructor ile verilir ve ikisinin de getter metodu vardır. Ek olarak `getCharge`, `getBonus` ve `getMovieTitle` metotları vardır. `getCharge`, ilişkili olduğu filme "sen şu kadar gün kiralandın, toplam kira bedelini döndür" der; `getBonus` da benzer işi yapar. `getMovieTitle`, `Customer` ile `Movie` arasında ek bir ilişki kurmamak için `Movie` nesnesinin `getTitle` metodunu çağırıp film adını döndürür.
<!-- BELİRSİZ: Rental.java karelerde açık görünmüyor; yukarıdaki anlatım altyazıdan alınmıştır. -->

### 11.4 Movie sınıfı

`Movie` sınıfının başı (ekrandan, 01:35:00):

```java
package fowler_09;

public class Movie {
    public static final int CHILDRENS = 2;
    public static final int REGULAR = 0;
    public static final int NEW_RELEASE = 1;
    private String _title;
    private int _priceCode;
    public Movie(String title, int priceCode) {
        _title = title;
        _priceCode = priceCode;
    }
    public int getPriceCode() {
        return _priceCode;
    }
    public void setPriceCode(int arg) {
        _priceCode = arg;
    }
    public String getTitle (){
        return _title;
    }
```

Fiyat kodu için üç tane `public static final` alan tanımlanmıştır: `_priceCode` 0 ise normal film, 1 ise yeni çıkan film, 2 ise çocuk filmidir. Hoca kalıtımdan vazgeçilse bile bu üç sabit yerine en azından `enum` kullanılmasının daha iyi olacağını söyledi (enum önceki haftalarda görülmüştü). Bunun nedeni şöyle bir düşünce olabilir: film türünü uzun string'lerle tutmak yerine (Unicode'da her karakter birkaç byte tutar) küçük bir tam sayıyla tutmak bellekten tasarruf sağlar; altyapı ona göre kurulmuşsa kod da ona göre devam eder. Ama yine de kusurlu bir tasarımdan adım adım iyiye gidilmektedir.

> **Ders sonrası not:** Hoca bu düşünceyi anlatırken 1 byte'lık bir alanda "258 kadar" farklı değer tutulabileceğini söyledi; doğrusu 1 byte'ta $2^8 = 256$ farklı değer tutulur. Ayrıca Java'da 1 byte'lık tür `byte`'tır; `short` 2 byte'tır.

Ad ve fiyat kodu constructor ile verilir. Fiyat kodunun hem getter'ı hem setter'ı vardır, çünkü bir filmin fiyat kodu değişebilmelidir: çocuk filmi çocuk filmi olarak kalır, ama yeni çıkan bir film birkaç ay sonra dükkân sahibinin kararıyla normal filme çevrilebilir. Belki çok yeni çıkan bir çocuk filmi de bir süre yeni film olarak işaretlenebilir. Film adı için de getter vardır.

`getCharge` metodu (ekrandan, 01:40:00 ve 02:00:00; 1,5 değeri düzeltilmiş haliyle):

```java
    public double getCharge( int daysRented ) {
        double result = 0;
        switch ( getPriceCode() ) {
        case Movie.REGULAR:
            result += 2;
            if (daysRented > 2)
                result += (daysRented - 2) * 1.5;
            break;
        case Movie.NEW_RELEASE:
            result += daysRented * 3;
            break;
        case Movie.CHILDRENS:
            result += 1.5;
            if (daysRented > 3)
                result += (daysRented - 3) * 1.5;
            break;
        }
        return result;
    }
```

Müşterinin (dükkân sahibinin) tarif ettiği kurallar şunlardır: normal filmlerde her kiralama için en az 2 lira alınır, kaset bu bedelle 2 gün tutulabilir, 2 günü aşan her gün için günlük 1,5 lira eklenir. Yeni çıkan filmler günü 3 liradan kiralanır. Çocuk filmlerinde her kiralama için 1,5 lira ödenir, kaset bununla 3 gün tutulabilir, 3 günü aşan her gün için günlük 1,5 lira eklenir.

`getBonus` metodunun kuralı: hangi film kiralanırsa kiralansın her kiralama 1 puan kazandırır; kiralanan film yeni çıkan bir filmse ve 1 günden fazla kiralanmışsa 1 ek puan daha kazanılır.
<!-- BELİRSİZ: getBonus metodunun gövdesi karelerde görünmüyor; kural altyazıdan alınmıştır. -->

> **Hocanın vurgusu:** Kod yazarken kendinizi bir if-else-if zinciri ya da switch-case yapısı içinde kod yazarken görüyorsanız bu, tasarımınızı kalıtım ve çok biçimlilikle iyileştirmeniz gerektiğinin en önemli göstergesidir. Doğru tasarımda `Movie` soyut olur; `Regular`, `NewRelease` ve `Childrens` somut alt sınıflar olur; uzun `getCharge` metodunun her `case`'i ilgili alt sınıfa taşınır ve `getCharge` üst sınıfta soyut kalır. `getBonus` da üst sınıfta soyut olur; `NewRelease` alt sınıfında fiyat koduna bakmadan "kiralama günü 1'den büyükse 2, değilse 1 döndür" denir.

## 12. Kara kutu ve beyaz kutu sınaması

Aslında metot kodlarının ayrıntısını bilmek gerekmiyordu. Dükkân sahibi gereksinimleri vermiştir: üç tür film vardır, kiralama bedelleri şudur, bonus mantığı şudur. Bu gereksinimlerin doğru kodlanıp kodlanmadığını kaynak kodu bilmeden de sınamak mümkündür: "şu tür filmi şu kadar gün kiralarsam şu kadar tutmalı" diyerek girdiler verilir ve hesabın doğru olup olmadığı ölçülür. Buna kara kutu sınaması (black box testing) denir.

Kaynak kod biliniyorsa test vakaları, her metodun içindeki her `if`, `else` dalından ya da her `case` dalından en az bir kez geçecek biçimde hazırlanabilir; böylece daha sağlam bir test yapılır. Sınanan işin iç yapısını (burada kaynak kodu) bilip test vakalarında ona göre ince ayar yapma yaklaşımına beyaz kutu sınaması (white box testing) denir. Hoca bunu ek bilgi olarak verdi.

## 13. Test sınıflarının yazılması ve çalıştırılması

Burada istisna oluşmadığı için test kodu JUnit 3.x'e göre yazıldı. `Rental` için ayrı bir test sınıfı yazılmadı; sınamalar `Customer` ve `Movie` üzerinden yapılabilir. `Movie` çok karmaşık bir sınıf değildir; `getCharge`'daki switch-case temel karmaşıklığı oluşturur, ama hangi türde filmin kaç gün kiralandığına dair sınamalar `Customer.statement` üzerinden yapılabilir. Bu yüzden `TestCustomer` daha fazla ve ayrıntılı test vakası içerir.

### 13.1 TestMovie

İş sınıfının adı `Movie` olduğu için test sınıfının adı `TestMovie`'dir ve `TestCase`'ten türetilmiştir (ekrandan, 01:45:00):

```java
package fowler_09;

import junit.framework.TestCase;

public class TestMovie extends TestCase {

    public void testMovie( ) {
        Movie matrix = new Movie("The Matrix",Movie.REGULAR);
        Movie monster = new Movie("Monsters, Inc.",Movie.CHILDRENS);
        Movie surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
        assertTrue("Bunlar farklı tür filmlerdir",
                matrix.getPriceCode() != monster.getPriceCode() );
        assertTrue("Bunlar farklı tür filmlerdir",
                matrix.getPriceCode() != surrogate.getPriceCode() );
        assertFalse("Bunlar farklı tür filmlerdir",
                monster.getPriceCode() == surrogate.getPriceCode() );
    }

}
```

Bu, olabilecek en basit test türüdür: tek bir metotta birden fazla assert kullanılır. Normalde her test metodunda tek bir assert tercih edilir ve `TestCustomer`'da öyle yapılacaktır. Ama burada yapılan iş üç farklı iş değil, tek bir iştir: sistemde farklı türde filmler olduğuna göre üç farklı türde film oluşturup bunların gerçekten farklı türde algılanıp algılanmadığına bakmak. Üç nesne aynı amaçla karşılaştırıldığı için tek bir test metodu yeterli görüldü. Hem `assertTrue` hem `assertFalse`'u göstermek için hem `!=` hem `==` kullanıldı. "Surrogates" kod ilk yazıldığında yeni çıkan bir filmdi; yıllar içinde normal film oldu, ama hoca örneği her yıl güncellemeye gerek görmediğini söyledi. Daha düzgün bir test vakası yazılsaydı filmler `setUp` metodunda oluşturulabilirdi.

Dikkatli bir öğrenci fark edecektir: assert metotları anlatılırken örneğin `assertTrue` tek parametreli verilmişti, burada iki parametreli sürümü çağrıldı. Bütün assert metotları aşırı yüklenmiştir (overloaded); ilk parametre olarak bir string alan sürümleri de vardır. Bu string, test vakası başarısız olursa neden başarısız olduğunu bildirir. "The Matrix" ile "Monsters, Inc." farklı türde filmler olduğu için fiyat kodları eşit olmamalıdır; bir hata yüzünden aynı çıkarsa JUnit kırmızı çubukla uyarır ve bu açıklamayı gösterir. Önceki elle yazılan testlerde yalnız "hata numarası şu" gibi bir şey yazdırılıyor, nereden kaynaklandığını anlamak için test kodunu ayrıntılı okumak gerekiyordu; açıklama string'i bu işi kolaylaştırır.

### 13.2 TestCustomer

`TestCustomer` da `TestCase`'ten türetilmiştir. Burada bir müşteri ve farklı türlerden birkaç film tanımlanır (filmlerin farklı türde olduğuna bir önceki testle güvenilebilir), bu filmler müşteriye değişik sürelerle kiralanır ve doğru bedel ile doğru bonusun verilip verilmediğine bakılır. Müşteri ve filmlerin oluşturulması her test metodunda tekrarlanacağı için korumalı `setUp` metodu override edilip orada yapılır. Filmler müşteriye `setUp`'ta kiralanmaz; çünkü test vakaları farklı filmlerin farklı sürelerde kiralanmasına dayanır. `setUp`'a yalnız ortak kısımlar yazılır.

Karede görünen kısım (ekrandan, 01:50:00):

```java
        // setUp() içinin sonu
        surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
        terminator = new Movie("Terminator Salvation",Movie.NEW_RELEASE);
    }

    public void testGetName( ) {
        String sonuc = musteri.getName( );
        assertEquals("Örnek Müşteri",sonuc);
    }

    public void testStatementWhenEmpty( ) {
        String sonuc = musteri.statement();
        String beklenen = "Rental Record for Örnek Müşteri\n";
        beklenen += "Amount owed is 0.0\n";
        beklenen += "You earned 0 frequent renter points";
        assertEquals(beklenen, sonuc);
    }

    public void testStatementWithMoviesLongRent( ) {
        musteri.addRental( new Rental(matrix, 3) );
        musteri.addRental( new Rental(monster, 4) );
        // devamı karede görünmüyor
```

(Ekrandaki müşteri adı ve müşteri değişkeninin adı notta genel bir adla değiştirildi. Sınıfın alanları `musteri : Customer`, `matrix`, `monster`, `surrogate`, `terminator : Movie` ve `setUp()` ile beş test metodudur: `testGetName`, `testStatementWhenEmpty`, `testStatementWithMoviesLongRent`, `testStatementWithMoviesShortRent`, `testNewReleaseRentalBonus`.)

- **testGetName:** Müşterinin adı alınıp bir string'e yazılır ve beklenen adla `assertEquals` ile karşılaştırılır. "Bu kadar basit bir şeyin sınanmasına gerek var mı?" sorusuna hocanın cevabı evettir: adda Türkçe karakter geçtiği için bu test, çalışılan platformun Türkçe karakterleri düzgün destekleyip desteklemediğini de sınamış olur.
- **testStatementWhenEmpty:** Müşteri hiç film kiralamamışsa borcu 0 lira, bonusu 0 olmalıdır. `setUp`'ta müşteriye film verilmemiştir. Basılması gereken makbuz elle `beklenen` string'inde biriktirilir; elde edilen sonuçla aynıysa test başarılıdır. Burada ek açıklama string'i yazılmadı. Metot adları `test2` gibi değil, neyin sınandığını açıkça anlatan uzun adlardır; bu kodun anlaşılabilirliği için önemlidir.
- **testStatementWithMoviesLongRent:** Farklı türde filmler uzun süreliğine kiralanır ve elde edilen makbuz olması gerekenle karşılaştırılır. Beklenen değerler bir kenarda elle hesaplanmalıdır; örneğin normal filmde 2 günden fazla kiralama ile 2 gün ve altı kiralama farklı sonuç vermelidir.
- **testStatementWithMoviesShortRent:** Aynı kontrol kısa süreli kiralamalar için yapılır; yine `assertEquals` kullanılır.
- **testNewReleaseRentalBonus:** Bonus için farklı bir durum vardır: bir normal film ve yeni filmler kiralanarak yeni filmden daha fazla bonus kazanılan durum da sınanır; basılan makbuz olması gereken makbuzla karşılaştırılır.

### 13.3 Eclipse'te JUnit'in projeye eklenmesi ve çalıştırma

JUnit, Eclipse ve NetBeans ile birlikte gelir, ama Eclipse'te projeye elle eklenmesi gerekir: projeye sağ tıklanır, Build Path > Configure Build Path seçilir, Libraries altında Classpath'e tıklanıp Add Library denir, listeden JUnit seçilip Next ile işlem tamamlanır. Bundan sonra gereken sınıflar import edilebilir.

Bir test sınıfına sağ tıklanıp "Run As > JUnit Test" seçilince JUnit perspektifi açılır. `TestMovie` çalıştırıldığında tek test vakası sorunsuz çalıştı ve yeşil çubuk göründü.

### 13.4 TestAll ve suite

`TestAll`, `TestCustomer` ile `TestMovie`'yi bir araya getirip hepsini birden yürütür (ekrandan, 01:55:00):

```java
package fowler_09;

import junit.framework.*;

public class TestAll {
    public static Test suite( ) {
        TestSuite suite = new TestSuite("Bütün testler");
        suite.addTestSuite(TestCustomer.class);
        suite.addTestSuite(TestMovie.class);
        return suite;
    }

}
```

`suite` metodu `public static` olmak ve `Test` türünden nesne döndürmek zorundadır. Suite'e constructor'da bir ad verilir, `addTestSuite` ile test sınıfları eklenir; böylece içlerindeki bütün test vakaları çalıştırmaya dahil olur. `TestCustomer`'da adı `test` ile başlayan 5, `TestMovie`'de 1 metot olduğu için `TestAll` çalıştırılınca 6 test vakası yürütülür. Hepsi başarılı oldu ve yeşil çubuk göründü.

**Soru:** Daha önce elle yazdığımız testlerde ekrana "bunlar farklı tür filmlerdir" gibi bir mesaj yazdırıyorduk; buradaki string ne işe yarıyor?

**Cevap:** O string ekrana her zaman yazılmaz; test başarısız olursa "başarısız oldu, bunlar farklı tür filmlerdir ama sende aynı çıktı" anlamında gösterilen hata açıklamasıdır. Hoca bunu hemen bir hata yaparak gösterdi (bkz. bölüm 14).

## 14. Testlerle hata yakalama

### 14.1 Fiyat kodu hatası

Hoca `Movie.getCharge` içindeki `REGULAR` durumunu yorum satırına aldı (yani bu `case`'i kodlamayı unutmuş gibi yaptı) ve yalnız `TestMovie`'yi çalıştırdı. Test başarısız oldu ve kırmızıyla gösterildi. Failure trace'te bir assertion hatası oluştuğu, verilen "Bunlar farklı tür filmlerdir" açıklamasının eklendiği ve ayrıca hatanın nereden kaynaklandığını gösteren, `printStackTrace` benzeri bir yığın izi görüldü. Kod düzeltildi ve JUnit panelindeki yeşil düğmeyle test yeniden çalıştırılınca yeşil çubuk göründü.
<!-- BELİRSİZ: 01:56:37-01:57:16 arasında hocanın önce REGULAR ve NEW_RELEASE için aynı değeri (0) verme fikrinden mi yoksa doğrudan case'i yorum satırına almaktan mı söz ettiği altyazıdan tam anlaşılmıyor; ilgili kare yok. -->

### 14.2 Ücret hesabı hatası

Daha karmaşık bir hata için hoca, normal filmlerde 2 günü aşan her gün için istenen 1,5 lira yerine yanlış anlayıp 1,0 lira yazdı (`result += (daysRented - 2) * 1.0;`) ve `TestAll`'u çalıştırdı. Kırmızı çubuk çıktı: "Runs: 6/6, Errors: 0, Failures: 1"; başarısız olan test `testStatementWithMoviesLongRent` idi (ekrandan, 02:00:00).

JUnit kendi açıklayıcı bilgisini vermekte epey başarılıdır. `assertEquals` iki string'i karşılaştırdığı için `junit.framework.ComparisonFailure` verdi ve beklenen ile elde edilen string'leri gösterdi. String uzun olduğu için baş tarafı "..." ile kısaltılmış, ilk farklılaşan yer gösterilmiştir; farkın başladığı ve bittiği yer köşeli parantezle işaretlenmiştir:

```text
junit.framework.ComparisonFailure: expected:<...
    The Matrix 3.[5
    Monsters, Inc. 3.0
    Surrogates 6.0
Amount owed is 12.5]
You earned 4 freque...> but was:<...
    The Matrix 3.[0
    Monsters, Inc. 3.0
    Surrogates 6.0
Amount owed is 12.0]
You earned 4 freque...>
```

Beklenen makbuza göre "The Matrix" için 3,5, "Monsters, Inc." için 3, "Surrogates" için 6 lira alınmalı, toplam borç 12,5 olmalıydı; elde edilen ise "The Matrix" için 3, toplam 12 oldu. Bu değerler kurallardan adım adım şöyle çıkar:

- "The Matrix" (normal film, 3 gün): $2 + (3 - 2) \times 1{,}5 = 3{,}5$ lira; hatalı kodda $2 + (3 - 2) \times 1{,}0 = 3{,}0$ lira.
- "Monsters, Inc." (çocuk filmi, 4 gün): $1{,}5 + (4 - 3) \times 1{,}5 = 3{,}0$ lira.
- "Surrogates" (yeni film): 6,0 lira, yani günü 3 liradan 2 gün (ara adım eklendi: gün sayısı karede görünmüyor, 6/3 = 2 gün olarak çıkarıldı).
- Toplam: $3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$ lira; hatalı kodda $12{,}0$ lira.
- Bonus: her kiralama 1 puan, 2 gün kiralanan yeni film 1 puan daha: $1 + 1 + 2 = 4$ puan.

> **Ders sonrası not:** Hoca konuşurken elde edilen toplamı "toplam puanı da 12" diye söyledi; 12, puan değil toplam borçtur ("Amount owed is 12.0"). Puan her iki durumda da 4'tür. Ücret ve puan değerleri, ekrandaki `Customer` ve `Movie` koduna göre kurulan (`Rental` ve `getBonus` altyazıdaki anlatımdan yazılan) bir sürümle `java` ile çalıştırılarak doğrulandı: doğru kodla 3,5 / 3,0 / 6,0, toplam 12,5 ve 4 puan çıktı.

Bu nokta atışı işaretleme hatanın nereden kaynaklandığına dair çok önemli bir ipucudur ve hatayı daha çabuk düzeltmeyi sağlar. Test vakasının adı açıklayıcı olduğu için sorunun uzun süreli kiralamalarla ilgili olduğu zaten anlaşılıyordu, ama üç tür film vardı. Hoca normal, yeni ve çocuk filmlerinin uzun ve kısa süreli kiralamaları için 6 ayrı test vakası yazmak yerine 2 test vakası yazmış, üç durumu tek bir test vakasında sınamıştı; 6 metotla yapmanın belki daha iyi olacağını, ama JUnit farkın yerini nokta atışı gösterdiği için buna gerek kalmadığını söyledi. "The Matrix" normal filmdir; demek ki normal filmin uzun süreli kiralanmasında sorun vardır. `Movie`'de `REGULAR` durumunun uzun kiralama kısmına bakılınca 1,5 yerine 1 yazıldığı görüldü. Düzeltilip kaydedildi, bütün testler yeniden çalıştırılınca yeşil çubuk göründü.

## Örnek Sorular

Aşağıdaki sorular, hocanın bir sınavda çıkabilecek soru türlerine örnek olarak derste okuduğu ve ekranda gösterdiği sorulardır (sorular İngilizce sorulacağı için metinler İngilizce bırakıldı).

**Soru 1** (derste sözlü, 02:07:11): What is the name of the method that is coded for changing a member field's value?

A) setter method B) getter method C) constructor method D) initializer method E) none of the above

> **Çözüm:** Bir üye alanın değerini değiştirmek için yazılan metot setter metodudur; cevap A.
<!-- BELİRSİZ: Altyazıda hocanın cevabı "Doğru cevap, E, set" diye bozuk geçiyor; konu gereği doğru cevap A (setter) olmalı. -->

**Soru 2** (derste sözlü, 02:07:42): The method that is used for reading the value of a member field without changing it is coded as ...

A) setters B) getters C) constructors D) initializers E) none of the above

> **Çözüm:** Hoca cevabı B (getter) olarak verdi.

**Soru 3** (ekrandan, 02:10:00): Aşağıdaki `Car` sınıfının (slayt 33) satırları numaralandırılmış olarak verilir ve bazı satırlar (constructor içindeki atama, getter, setter ve `introduceSelf` gövdeleri) boş bırakılır. Soru: belirtilen satırın derleme hatası vermemesi için hangi numaralı satıra hangi komut yazılmalıdır?

```java
package nyp01a;                                 // 1
public class Car {                              // 2
    private String plate;                       // 3
    public Car( String plateNr ) {              // 4
        plate = plateNr;                        // 5 (boş bırakılır)
    }
    public String getPlate() {
        return plate;                           // (boş bırakılır)
    }
    public void setPlate(String plate) {
        this.plate = plate;                     // (boş bırakılır)
    }
    public void introduceSelf( ) {
        System.out.println( "My plate: " + getPlate() ); // (boş bırakılır)
    }
    public static void main( String[] args ) {
        Car aCar;
        aCar = new Car( "34 RA 440" );
        aCar.introduceSelf( );
    }
}
```

> **Çözüm:** Hocanın örnek cevabı: 5. satıra `plate = plateNr;` yazılmalıdır.
<!-- BELİRSİZ: Hangi satırların boş bırakılacağı altyazıda bozuk okunuyor (02:09:20-02:09:31); yalnız 5. satırın cevabı net. -->

**Soru 4** (ekrandan, 02:10:05): Aynı `Car` kodu verilip `main` metodu çalıştırıldığında hangi çıktının elde edileceği sorulur. Şıklar: A) plaka yazdırılır, B) hiçbir şey çıkmaz, C) derleme hatası verir, ... E) istisna (exception) verir.

> **Çözüm:** Hoca cevabı A (plaka yazdırılır) olarak verdi. Kod `java Car.java` ile çalıştırıldı; çıktı: `My plate: 34 RA 440`.

**Soru 5** (derste sözlü, 02:11:42): Verilen sequence diyagramını (bölüm 10.1'deki `statement` diyagramı) destekleyen `statement` metodunun kaynak kodu aşağıdaki şıklardan hangisinde verilmiştir? (Şıklarda farklı gövdelere sahip `statement` metotları vardır.)

> **Çözüm:** Hoca doğru cevabın derste gösterilen `Customer.statement()` metodu olduğunu söyledi (bölüm 11.2): her kira kaydı için `getMovieTitle()` ve `getCharge()` çağrılır, sonra `getTotalCharge()` ve `getTotalBonus()` ile alt satırlar eklenir; `Customer` `Movie`'yi doğrudan çağırmaz.

## Dersin Toparlaması

Dersin ilk yarısında multithreading'e giriş yapıldı. Multitasking'in birden fazla programın aynı anda (gerekirse sırayla, hızlı geçişle) çalışması, multithreading'in ise bir programın işini gerçekten paralel akışlara bölmesi olduğu görüldü. Thread'in yaşam döngüsü (new, runnable, running, blocked, dead) ve scheduler'ın belirleyici rolü anlatıldı: thread'lerin ne zaman ve hangi sırayla çalışacağı garanti değildir. Busy waiting yerine `sleep` kullanılması ve `InterruptedException`'ın yakalanması gerektiği vurgulandı. Bir görevi ayrı thread'de çalıştırmanın dört adımı (`Runnable` + `run`, nesne, `new Thread(...)`, `start`) taraftar örneğiyle uygulandı; `run`'ın doğrudan çağrılmasının paralelliği ortadan kaldırdığı gösterildi.

İkinci yarıda JUnit ile birim sınama işlendi: 3.x'te `TestCase`'ten türeyen, adı `test` ile başlayan metotlar, `setUp` ve suite; 4.x'te `@Test`, `@Before` ve `expected` ile istisna sınaması. Fowler'ın video kiralama örneği üzerinden düşük bağlaşım ve yüksek uyum ilkeleri, switch-case'in bir tasarım kokusu olduğu, kara ve beyaz kutu sınaması anlatıldı; `TestMovie`, `TestCustomer` ve `TestAll` yazılıp bilerek yapılan hataların JUnit tarafından nasıl yakalandığı gösterildi. Multithreading konusunun kalan kısmı (ortak kaynaklara erişim, senkronizasyon ve nesne kilidi) sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
