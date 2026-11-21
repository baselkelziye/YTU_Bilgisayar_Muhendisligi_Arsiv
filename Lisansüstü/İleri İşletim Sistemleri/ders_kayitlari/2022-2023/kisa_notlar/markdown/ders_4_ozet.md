# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin biçimi: iki makalenin tartışılması
  - Ders, öğrencilerin önceden okuduğu iki makalenin soru-cevap biçiminde tartışılmasıyla geçti. Ekranda slayt ya da makale paylaşılmadı; içerik sözlü anlatımdan ve makaleden sesli okunan cümlelerden alındı.
  - Birinci makale Hoare'un 1974 tarihli monitör makalesiydi (adı derste söylenmedi; büyük olasılıkla "Monitors: An Operating System Structuring Concept"). Monitör kavramını teorik ve küçük, yerel örneklerle inceler.
  - İkinci makale Mesa programlama dilinde ve Pilot işletim sisteminde monitörlerle edinilen deneyimi anlatır (büyük olasılıkla Lampson ve Redell, "Experience with Processes and Monitors in Mesa"). Monitör kavramını gerçek bir işletim sisteminde uygular.
- Semafor
  - Süreçler arasında senkronizasyon sağlamak için işletim sisteminin sunduğu temel ilkellerden (primitive) biridir.
  - Arkasında bir değişken vardır ve iki temel işlemi vardır. Dijkstra bunları P ve V diye adlandırdı: P "test etmek", V "artırmak" anlamındaki Hollandaca sözcüklerden gelir. Zamanla P işlemi wait, V işlemi signal adını aldı.
  - Semaforda doğru ilk değeri vermek ve P/V sonuçlarına göre doğru davranmak programcının sorumluluğundadır. Yanlış kullanım kilitlenmeye (Hoare'un deyişiyle "deadly embrace") yol açar.
- Monitörün tanımı ve adı
  - Kaynak dağıtan her zamanlayıcı (scheduler), bir miktar yerel yönetim verisinden ve kaynak almak/bırakmak isteyen programların çağırdığı prosedür ve fonksiyonlardan oluşur. Bu veri ve prosedür topluluğuna monitör denir.
  - Notasyon Simula 67'nin class notasyonuna dayanır. Yani bugünkü nesneye yönelik programlamadaki sınıf kavramının monitörlerde 1974'te kullanıldığı görülür.
  - Brinch Hansen aynı amaç için "shared" sözcüğünü kullanmıştı. Kavram Brinch Hansen ve Dijkstra ile birlikte ortaya çıktı; Hoare yapıyı geliştirip örneklerle sınadı.
  - "Monitor" burada görüntüleme değil, gözetleme, denetleme anlamındadır.
- Monitörün yapısı
  - Monitör adı ve `monitor` anahtar sözcüğüyle başlar, `end` ile biter.
  - İçinde sırasıyla monitöre yerel veri bildirimleri, bir ya da daha çok prosedür ve en altta yerel verinin ilk değer ataması bulunur.
  - İlk değer atama kısmı sınıftaki yapıcıya (constructor) karşılık gelir. Kullanıcı hatasını azaltır.
  - Aynı monitör tanımından, kullanım disiplini aynı olan farklı kaynaklar için çalışma anında birden fazla kopya oluşturulabilir.
- Semafor ile monitör farkı
  - Semaforda paylaşılan global bir değişken ve işletim sisteminin sağladığı iki işlem vardır; geri kalan bütün sorumluluk kaynağa erişen süreçtedir.
  - Monitörde kaynağın durumunu tutan veriye doğrudan değil, monitörün prosedürleri üzerinden erişilir. Bütün yükü monitör üstlenir.
  - Semaforlar monitörlerin atasıdır, tersi değil. Makale semaforun monitörle, monitörün de semaforla gerçeklenebildiğini gösterir.
- Koşul değişkeni (condition variable)
  - Monitör yapısının özüdür. wait ve signal işlemleri vardır.
  - Makalenin ifadesiyle koşul "değişkeni" ne doğru ne yanlıştır; programın erişebileceği saklı bir değeri yoktur. İçeride bir değeri olabilir, ama süreçler bu değere göre karar vermez.
  - Görevi süreçleri bekletmek ve kaynak serbest kalınca yeniden çalıştırmaktır. Her koşul değişkeninin arkasında bekleyen süreçlerden oluşan bir kuyruk vardır.
  - Kuyruk programlara açık değildir. Süreç beklediğinin farkında olmaz; kaynağa yalnız kendisi erişiyormuş gibi yazılır.
  - Kuyruk ilk başta FIFO (ilk gelen ilk hizmet alır) çalışır. Makale sonra koşul değişkenleri için öncelik (priority) kavramını önerir.
- Makaledeki örnekler ve gerçek işletim sistemi karşılıkları
  - Tek kaynak zamanlayıcısı (single resource scheduler): CPU ya da yazıcı gibi her an yalnız bir sürecin kullanabileceği kaynaklar.
  - Sınırlı tampon (bounded buffer): üretici ve tüketici hızları farklı olduğunda aradaki tamponlama.
  - Alarm saati (scheduled wait): ileride oluşacak bir zaman olayından haberdar olup ona göre davranmak (timer).
  - Tampon havuzu (buffer allocation).
  - Disk kafası zamanlayıcısı (disk head scheduler): asansör (elevator) problemine benzer; amaç ortalama bekleme süresini en aza indirmektir.
  - Okuyucular-yazarlar (readers and writers).
- Mesa ve Pilot makalesi
  - Monitör kavramı literatürde çok tanımlanmış ve çalışılmış, ama gerçek sistemlerde karşılığı az bulunmuştu. Makale gerçek bir sistemde (Pilot işletim sistemi, Mesa dili) ortaya çıkan sorunları ele alır.
  - Öğrencinin aktardığı sorunlar: monitör çağrılarının anlamı, wait/signal'in farklı tanımlarının karmaşıklığı, öncelikli zamanlama, zaman aşımı (timeout), iptal (abort) ve diğer istisnai durumlar, yaratma ve yok etme, çok sayıda küçük nesnenin izlenmesi.
  - Monitörlerin kullanıldığı üç alan: yerel eşzamanlı programlama (local concurrent programming), global kaynak paylaşımı (global resource sharing) ve kesmelerin yerine geçme (replacing interrupts).
- Kesmelerin monitörle soyutlanması
  - Diske yazan süreç monitör üzerinden çağrı yapar ve yazma bitene kadar uyutulur; işlemciyi bırakır.
  - Yazma bitince donanım kesmesi oluşur, işletim sistemi monitörün signal tarafını tetikler, süreç kaldığı yerden devam eder.
  - Böylece alt seviyedeki kesme mekanizması üst seviyede basit bir uyutma-uyandırma işlemine dönüşür. Bugünkü dillerdeki asenkron yapıların temeli burada görülür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Semaforlar monitörlerin atasıdır
  - Bir öğrencinin "monitör semaforun atası gibi" yorumunu hoca düzeltti: önce semafor vardır, monitör semaforlar üzerine kurulur.
- Monitörün asıl kazancı soyutlamadır
  - Programcı kaç sürecin aynı kaynağa eriştiğinden ve buna karşı alınacak önlemlerin karmaşıklığından tamamen yalıtılır. Yalnız kullanma isteğini dile getirir.
  - Semaforda ise programcı ilk değeri doğru vermeli ve P/V sonuçlarını kendisi denetlemelidir.
- Koşul değişkeninin değeri süreçleri ilgilendirmez
  - Hoca "değeri var mı, değerinin önemi var mı?" sorusu üzerinde uzun durdu. Cevap: süreçler açısından önemi yoktur; arkasındaki kuyruk süreçleri bekletmek ve uyandırmak için vardır.
- Örneklerin anlamı
  - Makaledeki örnekler ikna etmesi zor durumlar olduğu için değil, işletim sistemindeki temel kaynak kullanım senaryolarının monitörle karşılanabildiğini göstermek için verilmiştir.
- Monitörü kim yazar?
  - Koşul değişkeninin kuyruğunu ve yönetimini insanlar kodlar; işletim sisteminin bir parçası ya da paylaşılan kütüphane (runtime) olarak sunulur. Dinamik olarak arkada kendiliğinden oluşan bir şey yoktur.
  - Semafor desteği olan bir sistemde programcı kendi monitörünü yazabilir, ama bunun yapılmaması istenir; amaç bu hataya açık işi programcıdan almaktır.
- Donanım desteği zinciri
  - Atomik komutlar olmadan semafor yazılamaz. Intel, ARM, PowerPC gibi bugünkü bütün işlemcilerde atomik komutlar vardır. Atomik komut semaforu, semafor da monitörü mümkün kılar.
- Fikirlerin yaşı
  - Sınıf kavramı Simula 67'den gelir; monitör makalesi 1974'tür. Bugün yeni sanılan pek çok yapının temeli bu eski makalelerdedir.

## Kısa Tekrar Notları

- Semafor: global değişken + P (test, wait) ve V (artır, signal).
- Monitör: yerel veri + prosedürler + ilk değer atama; Simula 67 class notasyonu; Brinch Hansen'de adı "shared".
- Monitör = kaynak zamanlayıcı (resource scheduler). Paylaşmak istediğim kaynak için bir monitör oluştururum.
- Koşul değişkeni: wait/signal; programa açık değeri yok; arkasında gizli bir süreç kuyruğu var.
- Kuyruk FIFO'dur; öncelik eklenince açlık (starvation) riski doğar, çözümü yaşlandırmadır (aging).
- FCFS'de uzun iş öndeyse arkadakiler uzun bekler: konvoy etkisi.
- Örnekler: tek kaynak, sınırlı tampon, alarm saati, tampon havuzu, disk kafası (asansör), okuyucular-yazarlar.
- Monitör semaforla, semafor monitörle gerçeklenebilir.
- Atomik komut -> semafor -> monitör zinciri.
- Mesa/Pilot: yerel eşzamanlı programlama, global kaynak paylaşımı, kesmelerin yerine geçme.
- Sıkı bağlı (tightly coupled) süreç grubunun bir sonraki adımı tek süreç içinde çok iş parçacığı (multi-thread) yapısıdır.
- Kesme -> işletim sistemi -> monitör signal -> uyuyan süreç uyanır.

## Detaylı Açıklamalar

- Semafordan monitöre geçiş neden gerekti?
  - Birden fazla sürecin aynı kaynak üzerinde birbirini etkilemeden çalışabilmesi, yani kaynakların verimli kullanımı için semafor gibi yöntemler tanımlandı. Semaforda tek bir paylaşılan değişken ve onu güncelleyen iki işlem vardır. Doğru ilk değer verme, işlem sonuçlarını denetleme ve yeniden deneme gibi bütün yük uygulamadadır. Bu hataya açıktır ve kötü kullanımda kilitlenme olur.
  - Monitör bu yükü kendine alır. Paylaşılan kaynağın durum verisi monitörün içinde gizlidir; süreçler yalnız monitörün prosedürlerini çağırır. Bu, veri soyutlamanın (data abstraction) işletim sistemi kaynak yönetimine uygulanmasıdır.
- Koşul değişkeni nasıl çalışır?
  - Kaynak meşgulken gelen süreç koşul değişkeninde wait ile bekletilir ve o değişkenin kuyruğuna konur. Kaynağı kullanan süreç işini bitirince signal ile kuyruktaki sıradaki süreç uyandırılır. Kuyruk süreçlere görünmez; her süreç kaynağı tek başına kullanıyormuş gibi yazılır.
  - Hocanın özeti: koşul değişkeni önce bekletmek, sonra uygun anda yeniden çalıştırmak için vardır. Sıraya koymak bunun aracıdır.
- FIFO, öncelik, açlık ve konvoy
  - FIFO en basit yöntemdir ve çok bekleyenin önce hizmet almasını sağlar. Ama öndeki süreç kaynağı çok uzun kullanacaksa arkadakilerin bekleme süresi çok uzar. Hoca bunu yavaş bir konvoyun arkasında kalmaya benzetti: geçemez, hızlanamazsınız.
  - Öncelik eklemek önemli işlerin çabuk yapılmasını sağlar, ama düşük öncelikliler hiç kaynak alamayabilir (açlık). Çözüm yaşlandırmadır: bekledikçe önceliği yükselir, hizmet aldıktan sonra olması gereken değere geri çekilir.
- Disk kafası zamanlayıcısı ve asansör
  - Kafa X konumundayken veri Y konumundadır; kafayı götürmenin maliyeti gecikmedir. Diske birçok uygulama erişir ve aynı anda iki farklı yerden okunamaz. İstekler, ortalama gecikme en az olacak biçimde sıraya sokulmalıdır. Mutlak en az mümkün değildir, ortalama en aza indirilir. Asansörde de hedef, doğru kata gitmenin yanında ortalama bekleme süresini ve enerjiyi azaltmaktır.
- Mesa makalesindeki üç alan
  - Yerel eşzamanlı programlama: bir uygulama, içindeki eşzamanlılığı ifade etmek için sıkı bağlı bir senkron süreç grubu olarak yazılır. Bunun ileri adımı çok iş parçacıklı yapıdır.
  - Global kaynak paylaşımı: birbirinden bağımsız programlar aynı kaynakları birbirini etkilemeden kullanır. Kaynak meşgulse monitör çağıran süreci kuyruğa alır, süreç bunun farkında olmaz.
  - Kesmelerin yerine geçme: klasik yaklaşımda kesme programın akışını zorla özel bir adrese götürür (forced branch), kesme rutini çalışır ve geri döner. Monitörle bu, uyutma ve uyandırmaya dönüşür. Uykudaki parça işlemciyi kullanmaz; programcı diskin 10 saniyede mi 1 milisaniyede mi yazdığıyla ilgilenmez. Program sıkı bağlı parçalara bölünmüşse diğer parçalar ilerlemeye devam eder.
- Ders sonrası not: Hoca P ve V'nin yeni adlarını anlatırken "test etmek V'ye dönüşüyor" dedi. Doğrusu P (test) işleminin wait, V (artırma) işleminin signal adını almasıdır; hoca da cümlenin devamında V'nin signal olduğunu söyledi.
- Ders sonrası not: Hoca Mesa makalesinin 1977'de yazıldığını söyledi. Makale büyük olasılıkla 1979'da SOSP'de sunulmuş, 1980'de Communications of the ACM'de yayımlanmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
