# Ders 3 Genişletilmiş Notu: Makale Tartışması: Mesa Monitörleri, DEMOS/MP Süreç Göçü ve DEMOS Görev İletişimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. Experience with Processes and Monitors in Mesa
- 3. Mesa Makalesinde İkilik (Duality)
- 4. Makalenin Asıl Konusu: Monitörlerde Açık Kalan Sorular
- 5. Monitörle Kazandırılmak İstenen Üç Yetenek
- 6. Birinci Sınıf Değer (First Class Value)
- 7. Monitörler ve Öncelikli Zamanlama
- 8. Process Migration in DEMOS/MP
- 9. Task Communication in DEMOS
- 10. Örnek Sorular

## 1. Dersin Biçimi

Bu ders bir makale okuma ve tartışma dersiydi. Öğrenciler o hafta için verilen üç makaleyi önceden okuyup özetlemişti. Derste her makale için önce gönüllü bir öğrenci makaleyi özetledi, sonra hoca sorular sordu, öğrencilerin cevaplarını değerlendirdi ve makalenin özünü kendisi açıkladı. Tartışma Türkçe ve İngilizce karışık yürüdü.

Tartışılan üç makale şunlardır:

- "Experience with Processes and Monitors in Mesa"
- "Process Migration in DEMOS/MP"
- "Task Communication in DEMOS"

Kayıtta ekran paylaşımı yoktu; görüntü yalnız Zoom'da konuşan kişinin adını gösteriyordu. Bu yüzden notun tamamı altyazıdan hazırlandı. Hocanın makaleden sesli okuduğu cümleler İngilizce olarak korunmuştur.

Hoca bir makaleyi anlatırken cümleleri birebir aktarmak yerine "neyin ne olduğunu gösterecek şekilde", yani makalenin hangi sorunu neden ve nasıl çözdüğünü anlatmayı istedi.

## 2. Experience with Processes and Monitors in Mesa

Bir öğrenci makaleyi İngilizce özetledi. Özete göre yazarlar, kişisel bilgisayarlar için eş zamanlı (concurrent) bir işletim sistemi olarak tasarlanan Pilot'u ve onun üzerindeki deneyimlerini anlatıyor. Hem Pilot'un kendisi hem de onun desteklediği uygulama programları Mesa dilinde yazılmıştır. Makale, monitörler üzerine daha önceki literatüre ve yayımlanmış çalışmalara dayanır.

<!-- BELİRSİZ: Öğrenci özetinin geri kalanı (sistemin satır sayısı ve uygulama türleri dahil) altyazıda büyük ölçüde bozuk; burada yalnız okunabilen kısım verildi. -->

Hoca, makalede daha önce literatürde belirtilmiş ama çözülmediği söylenen başlıkların A'dan G'ye sıralandığını hatırlattı:

- Program yapısı (program structure)
- Süreç oluşturma (creating processes)
- Monitör oluşturma (creating monitors)
- İç içe monitör çağrısında WAIT
- İstisnalar (exceptions)
- Zamanlama (scheduling)
- Giriş-çıkış (input-output)

<!-- BELİRSİZ: Altyazıda dördüncü madde "Nested Rate" diye geçiyor; hocanın sonraki anlatımı (iç içe monitör çağrıları ve WAIT) ile birlikte "iç içe monitör çağrısında WAIT" olarak yorumlandı. -->

## 3. Mesa Makalesinde İkilik (Duality)

Hoca, yazarların bu sorunlarla uğraşırken bir dizi "ikileme" yaptığını söyledi. Makalede bu "duality" diye geçer: bir taraftaki bir kavram öbür taraftaki bir kavramla eşleştirilir, böylece daha kolay kabul edilebilir ve uygulanabilir bir çözüm ortaya konur. Hocanın sorusu, bu eşleştirmelerde neyin neyle eşleştirildiğiydi.

**Soru:** Makaledeki eşleştirmeler nelerdir? **Cevap:** Bir öğrenci mesajın süreçle, sürecin monitörle, send ve reply'ın da call ve return ile eşleştirildiğini söyledi. Hoca cevabın doğru olduğunu, ama biraz açılması gerektiğini söyledi.

Ardından başka öğrenciler de yorum yaptı:

- Bir öğrenciye göre yazarlar mesajlaşmayı programlama dili düzeyine indirmiş; mesaj sistemindeki send ve reply'ı bir metodun çağrısı ve dönüşü gibi eşleştirmiş, yani mesaj yapısını doğrudan kodun içine geçirmiştir.
- Bir öğrenci, yazarların eş zamanlılığı dilde gerçekleştirmek istediğini, monitörün bu ikiliği zaten desteklediğini ve Mesa'nın da bu kavramı desteklediğini söyledi.
- Bir öğrenci de bu eşleştirmenin aslında mesaj iletme (message passing) ile paylaşılan bellek (shared memory) arasında olduğunu söyledi: mesaj iletmede iletişim mesajlarla, paylaşılan bellek tarafında ise süreçler ve monitörler aracılığıyla kurulur; send/reply, monitör çağrılması ve değer döndürülmesine (call/return) denk düşer.

### 3.1 Hocanın Açıklaması: İkilik Nereden Geliyor?

Hoca, monitör yapısının arka tarafta bir program yapısıyla eşleştirilmesi gerektiğini söyledi. En akla yatkın ve en mantıklı görünen yol, monitörü prosedürlerle ilişkilendirmektir. Böyle olunca bir prosedür ve ona bağlı bir süreç olacak, bu süreç başka bir süreçle konuşacaktır. Bu yapı eş zamanlılığı içereceği için bir monitöre eşdeğer olur.

Bir süreç başka bir süreçle konuşacaksa aralarında bir mesajlaşma olmalıdır. Bu yüzden mesaj ile süreç arasında bir ikilik öngörülür. Ortak bir amaç için eş zamanlı çalışan iki süreç varsa, birinin diğerini çağırması aslında ona mesaj gönderip sonra cevabını almasına denk düşer; yani call/return, send/reply'a denktir.

> **Hocanın vurgusu:** Bu ikilik yazarların kendi öngörüsü değildir. Makalenin 14 numaralı kaynağındaki daha önceki bir yayının sonucudur.

> **Ek bilgi (derste anlatılmadı):** Mesaj tabanlı sistemlerle prosedür (monitör) tabanlı sistemlerin birbirinin ikilisi olduğu fikri, literatürde büyük olasılıkla Lauer ve Needham'ın 1979 tarihli "On the Duality of Operating System Structures" makalesiyle bilinir. Bu çalışmaya göre iki yapıdan biriyle yazılan bir sistem öbürüne dönüştürülebilir ve iki sistemin başarımı temelde aynı olur.

## 4. Makalenin Asıl Konusu: Monitörlerde Açık Kalan Sorular

Hoca gelen yorumları "tatmin edici değil" diye değerlendirdi, çünkü olayın özü atlanmıştı. Monitör kavramı eş zamanlılık içindir; yani birden fazla sürecin aynı anda bir arada çalışabilmesi için. Literatürde bununla ilgili çok şey tartışılmıştı. Ancak bunlar kâğıt üzerindeydi; gerçek bir uygulamada bazı şeylerin nasıl yapılacağı net değildi. Bazı başlıklardaki tartışmalar da bir sonuca varmamıştı: bir yaklaşımın ötekinden daha iyi olduğunu savunan farklı yayınlar vardı.

Hocanın üzerinde durduğu açık sorular şunlardır:

- **İç içe monitör çağrıları:** İç içe geçmiş monitör çağrıları olduğunda ne olacağı düşünülmesi ve incelenmesi gereken bir konudur.
- **WAIT:** Monitörün kritik parçalarından biri WAIT sistem çağrısıdır. Standart işletim sistemleri dersinde de anlatılan farklı durumları vardır: WAIT'ten sonra ya öbür süreç devam eder ya da WAIT'i yapan devam eder, diğeri bekler. WAIT'in nasıl uygulanacağıyla ilgili belirsizlik vardır; bazı senaryolarda biri, bazılarında öteki daha iyidir.
- **Öncelikli zamanlama:** Öncelikli zamanlama uygulandığında monitörlerin durumu ne olacaktır? Açlık (starvation) oluşabilir; literatürde bu da görülür.
- **Zaman aşımı (timeout):** Bir monitör işlemi başladıktan sonra zaman aşımı olursa bir şeyi iptal etmek (abort) gerekir. Fakat monitör o ana kadar çalışmıştır, o da bir kod parçasıdır. Bunun nasıl geri alınacağı, bir "unrolling" olup olmadığı, işlem (transaction) bitmeden başına nasıl dönüleceği tartışılmalıdır.
- **İstisnalar:** İstisna durumları da tartışılmalıdır.
- **Çok sayıda küçük nesne:** Büyük değil de küçük ve çok sayıda nesne olursa ve bunların hepsini monitör üzerinden yönetmek gerekirse, monitörleri yönetmenin başarımı ne olacaktır?

<!-- BELİRSİZ: Hocanın WAIT'in farklı durumlarını anlattığı bölümün başı altyazıda eksik (yaklaşık 00:15:32-00:15:39 arası kayıp). -->

> **Ek bilgi (derste anlatılmadı):** WAIT/signal için iki bilinen anlam vardır. Hoare monitörlerinde signal yapan süreç hemen bekler ve uyandırılan süreç monitörü alır. Mesa'da ise signal (Mesa'da NOTIFY) yalnız bir ipucudur: signal yapan çalışmaya devam eder, uyanan süreç daha sonra çalışır ve koşulu yeniden kontrol etmelidir; bu yüzden Mesa'da WAIT büyük olasılıkla bir `while` döngüsü içinde kullanılır.

Hoca, yazarların Pilot'u kullanma sebebinin Pilot'a eş zamanlılık özellikleri eklemek olduğunu söyledi. Bu özellikleri monitörle, yani o dönemin sıcak araştırma konusuyla ekliyorlar ve yukarıda sayılan, araştırılması gereken noktaları deneysel olarak, birebir uygulayarak görmek istiyorlar.

> **Hocanın vurgusu:** Pilot'ta bu özellikler zaten var da yazarlar onlarla oynuyor değil. Yazarlar Pilot'u bu yönde geliştiriyor, eklemeyi kendileri yapıyor.

### 4.1 İşletim Sistemi ile Programlama Dili

Pilot, o dönemin programlama dili olan Mesa'da yazılmıştır. Hoca, dil ile işletim sisteminin çoğu zaman iç içe olduğunu söyledi. Örneğin Unix C'de yazılmıştır ve Unix'in doğal uygulama geliştirme dili her zaman C'dir. Başka dillerde geliştirme yapılsa bile, alt tarafta C kütüphanelerine kadar inilir.

## 5. Monitörle Kazandırılmak İstenen Üç Yetenek

Hoca, açılışta makaleyi özetleyen öğrencinin de değindiği hedefleri toparladı. Yazarlar monitör yapısını kullanarak Pilot programlama ve çalıştırma ortamına üç şey kazandırmak istiyor:

- **Yerel eş zamanlı programlama (local concurrent programming):** Bir uygulamanın kendi içinde, uygulamanın yapısını en iyi şekilde ortaya koyacak biçimde alt parçalara bölünebilmesi.
- **Küresel kaynak paylaşımı (global resource sharing):** Birinci maddede aynı uygulamanın alt parçaları söz konusuydu; burada birbirinden bağımsız uygulamalar söz konusudur. Aynı sistemdeki, aynı makinedeki bağımsız uygulamalar küresel bir kaynağı düzgün bir şekilde paylaşacaktır.
- **Kesmelerin yerine geçmek (replacing interrupts):** Kesmeyi doğrudan yönetmek aradaki soyutlamayı (abstraction) kaldırır ve donanıma doğrudan müdahale etmeyi gerektirir. Bu her anlamda sıkıntılıdır. Yazarlar kesmeyi ortadan kaldırıp daha soyut bir modelle ifade ederek hem gerekli uyandırma (wake-up) mekanizmasını hem de senkronizasyonu sağlamaya çalışıyor.

## 6. Birinci Sınıf Değer (First Class Value)

Hoca makaleden şu cümleyi okudu: "This scheme has a number of important properties. It treats a process as a first class value in the language." Sorusu, bir dilde "first class value" kavramının ne anlama geldiğiydi.

**Soru:** Bir dilde birinci sınıf değer ne demektir? **Cevap:** Öğrencilerden gelen ilk cevaplar (kesmelerin yerine geçmesi, öncelikli zamanlama, zaman aşımı) hoca tarafından reddedildi; bunların birinci sınıf değerle ilgisi yoktu. Bir öğrenci, bir değişkene atanabilen ya da bir dizinin elemanı olabilen değerlerin kastedildiğini tahmin etti. Hoca bunun tartışılan bir konu olduğunu, yüzde yüz net bir tanımı olmadığını, bu konuda çalışanların farklı yorumları bulunduğunu söyledi ve genel kabulü anlattı.

Bir değer şu dört özelliğin hepsine sahipse birinci sınıf değerdir:

- Bir fonksiyonun parametresi olabilmek.
- Bir fonksiyonun sonucu olabilmek.
- Bir atamanın atama (sonuç) tarafı olabilmek; atamalarda hem sağda hem solda kullanılabilmek.
- Bir eşitlikte test edilebilmek.

> **Hocanın vurgusu:** Genel olarak bu dört özelliği dilin doğal haliyle, yani native olarak sağlıyor olması gerekir.

### 6.1 C Dilinden Örnekler

Hoca kavramı canlandırmak için C'den örnekler verdi.

- **Tam sayı (`int`):** Bir `int` değişkene atama yapılabilir, değer bir fonksiyona gönderilebilir, fonksiyondan geri dönebilir ve iki `int` değerin eşit olup olmadığı kontrol edilebilir. Bu yüzden C'de tam sayılar birinci sınıftır.
- **Dizi:** Tam sayılardan oluşan bir dizi fonksiyona dizi olarak gönderilemez; adresi, yani ilk elemanın adresi gönderilir. İlk tanımlamada (ilklendirmede) bütün elemanlara değer verilebilir, ama çalışma anında atama işaretiyle bütün diziye değer atanamaz: `A = B` ya da `A == B` diye dizinin tamamı üzerinde işlem yapılamaz. Bu yüzden diziler ikinci sınıf (second class) sayılır.
- **Yapı (`struct`):** Yapılar daha ilginçtir. Yapının adresi verilmedikçe fonksiyonda yapının yerel bir kopyası çıkarılır, o kopya üzerinde çalışılır ve kopya geri döndürülür. Dizide durum böyle değildir.
- **Fonksiyon:** C'de fonksiyon, parametre olarak (fonksiyon işaretçisiyle) aktarılabilir. İki fonksiyon işaretçisinin aynı yeri gösterip göstermediği de kontrol edilebilir. Fakat C'de çalışma anında dinamik olarak fonksiyon oluşturulamaz. Bir grup bu yüzden C fonksiyonlarının ikinci sınıf olduğunu söyler; bir grup ise diğer özellikleri sağladığı için birinci sınıf sayar. Tartışma açıktır.

**Soru:** Bir dizi fonksiyondan geri dönebiliyorsa, fonksiyondan dönüldüğünde çalışma anında atanmış olmuyor mu? **Cevap:** Hayır; dönen şey dizinin adresidir. Yapılarda ise kopya çıkarılır, kopya gönderilir ve kopya geri döndürülür.

Birinci sınıf olmak için değerin tamamını bir bütün olarak görebilmek ve tamamı üzerinde bir bütün olarak işlem yapabilmek gerekir. Hoca bunun nesneye yönelik dillerde daha mümkün ve daha anlamlı olduğunu söyledi: orada neredeyse her şey nesnedir, nesne olarak aktarılır ve nesnenin içine eşitlik (equality) metodu yazılabilir.

## 7. Monitörler ve Öncelikli Zamanlama

Hoca, makalede adreslenen noktalardan birinin öncelikli zamanlama olduğunu hatırlattı. Öncelikli zamanlamanın mantığı, önceliği yüksek olan sürecin önceliği düşük olan süreçten önce çalışmasıdır. Hocanın sorusu, monitör kullanılırken nasıl bir senaryonun bu özelliği bir anda ortadan kaldırdığıydı.

Bir öğrenci, monitörlerin süreçlerin başka süreçleri engellemesine yol açtığı bir sorunun ele alındığını söyledi. Başka bir öğrenci, yüksek öncelikli bir sürecin sürekli sıra alması yüzünden düşük öncelikli sürecin ilerleyemediği bir örnek verdi. Hoca bunun üzerine "Monitör burada nerede?" diye sordu ve monitörün "sistemi yönetmek" için olmadığını belirtti; cevabın daha teknik ve özel olması gerektiğini söyledi.

Hoca soruyu herkes için İngilizce tekrarladı: "Could you give a scenario in which the monitor structure defeats or negates the priority scheduling?" Cevabın makalede olduğunu, yazarların bu durumu bir senaryoyla tartıştığını ve olası bir çözüm önerdiğini söyledi.

Bir öğrenci makaledeki örneğin, bir sürecin monitöre girmeye çalışırken önceki bir süreç tarafından engellenmesiyle ilgili olduğunu ve P2, P3 gibi farklı öncelikli süreçler içerdiğini anlattı; monitörlerin süreçlerin önceliklerini fiilen boşa çıkarabildiğini (subvert) söyledi.

<!-- BELİRSİZ: Öğrencinin anlattığı senaryonun ayrıntıları altyazıda bozuk (yaklaşık 00:35:03-00:36:15) ve hoca senaryoyu kendisi toparlamadan bir sonraki makaleye geçti. -->

> **Ek bilgi (derste anlatılmadı):** Mesa makalesindeki senaryo büyük olasılıkla bugün öncelik terslenmesi (priority inversion) denen durumdur: düşük öncelikli P1 monitöre girer, yüksek öncelikli P3 aynı monitöre girmek isteyince bekler, orta öncelikli P2 de P1'in yerine çalışır. Böylece P3, P2'den yüksek öncelikli olduğu halde dolaylı olarak P2'yi bekler. Makalede önerilen çözüm büyük olasılıkla monitöre, ona girebilecek süreçlerin en yüksek önceliğini vermektir.

## 8. Process Migration in DEMOS/MP

### 8.1 Öğrenci Özeti

Bir öğrenci makalenin, dağıtık sistemlerde bir sürecin bir işlemciden başka bir işlemciye taşınmasını konu aldığını anlattı. Taşıma, link adı verilen ortam üzerinden mesajlarla çalışan bağlantı tabanlı bir yöntemle yapılır ve amaçlardan biri daha iyi başarımdır.

<!-- BELİRSİZ: Öğrenci özetinin geri kalanı ve hocanın sorduğu "bir sürecin bir işlemciden ötekine göç adımları nelerdir?" sorusunun cevabı altyazıda büyük ölçüde bozuk (yaklaşık 00:37:58-00:40:47). Bir öğrenci sonradan bekleyen mesajlarla ilgili bir noktanın "8. adımın sonunda" geçtiğini söyledi. -->

### 8.2 Bekleyen Mesajlar (Pending Messages)

Hoca, makalede bir "pending message" olayı olduğunu söyledi ve bunun ne demek olduğunu, neden önemli olduğunu, orada neyin çözülmesi gerektiğini sordu.

**Soru:** Bekleyen mesaj nedir, neden önemlidir? **Cevap:** Bir öğrenci, süreç taşındıktan sonra eski konuma gönderilen mesajların hâlâ geliyor olmasının ve linklerin hâlâ eski konumu göstermesinin sorun olduğunu söyledi. Hoca bunun sorunun ikinci kısmı olduğunu, bir de birinci kısmı olduğunu belirtti ve öğrenciyi adım adım sorularla yönlendirdi.

Hocanın yönlendirmesi şöyle ilerledi:

- Süreç taşınırken çalıştırılabilir mi? Hayır.
- Diğer süreçlerin bu sürece mesaj gönderip göndermemesi, bu sürecin çalışıp çalışmamasıyla ilgili mi? Değil. Aralarında iş birliği olan süreçler istedikleri herhangi bir anda birbirine mesaj gönderebilir.

Öyleyse sürece mesajlar şu sürelerin hepsinde gelebilir:

- Süreci taşımak için durdurduğumuzda,
- Süreç taşınırken,
- Süreç diğer çekirdekte, diğer işlemcide yeniden çalıştırılmaya başlatılırken.

Dahası, süreci taşımaya karar verdiğimiz anda kaynak noktada, işletim sisteminin sürece aktarmaya henüz fırsat bulamadığı ama kuyrukta bekleyen mesajlar da olabilir. İşte bunlar bekleyen mesajlardır. Sonrasında öğrencinin söylediği durum gelir: sürecin link adresleri değiştiği için bu mesajların yeni adrese gönderilmesi ve linklerin güncellenmesi gerekir. Yani sorunun birinci kısmı, geçiş anında, durum netleşmeden gelen ve bekleyen mesajları doğru yere ulaştırabilmektir.

### 8.3 Yönlendirme Adresi (Forwarding Address)

**Soru:** Makaledeki forwarding address ne anlama gelir? **Cevap:** Sürecin yeni adresini gösteren bir işaretçidir (pointer).

Hoca bunu şöyle açıkladı: Süreç artık o sistemde, o çekirdekte değildir; başka bir çekirdektedir. O zaman eski yere bir yönlendirme adresi konur. Bu, ağ yönlendirmedeki (network routing) forwarding ile aynıdır, başka bir farkı yoktur.

### 8.4 Göçün Maliyeti (Cost of Migration)

**Soru:** Göçün maliyeti makalede hangi kavramlar üzerinden ifade edilmiştir? **Cevap:** Bir öğrenci iki tür maliyetten söz edildiğini söyledi: biri doğrudan aktarım maliyeti, öteki mesaj bağlantılarının güncellenmesinden doğan artımlı (incremental) maliyet.

**Soru:** Hangisi daha ağır basar? **Cevap:** Öğrenci ikisinin de ağır olduğunu, ama artımlı olanın değişken olduğunu söyledi. Hoca bunun üzerine makalenin "Cost of Migration" bölümündeki bir cümleye dikkat çekti:

"For non-trivial processes, the size of the program and data overshadow the size of the system information."

"Overshadow" gölgede bırakmak demektir. Sistem açısından aktarılması gereken bilgi, sürecin durumu (state), süreç kontrol bloğu gibi bilgilerdir. "Non-trivial" burada basit olmayan, belirli bir boyutun üzerinde olan, karmaşıklığı ve kullandığı veri fazla olan süreçler anlamındadır. Böyle süreçlerde sürecin kendisini, yani program ve verisini aktarmak, sistem bilgisini aktarmaktan daha ağır basar.

Hoca aynı bölümden bir cümle daha okudu:

"In addition, each message that is pending in the queue for the migrating process must be forwarded to the destination machine. The cost of each of these messages is the same as for any other inter-machine message."

Yani haberleşen süreçler zaten başka makinelerdeyse, mesajlaşma yükü açısından çok fazla bir şey değişmez. Öğrencinin söylediği artımlı maliyet; linklerin güncellenmesi ve yönlendirmenin yapılması gibi işlerle işin içine girer.

## 9. Task Communication in DEMOS

### 9.1 Öğrenci Özeti

Bir öğrenci makalenin görevler (task) arasındaki iletişim ve veri paylaşımı mekanizmalarını tartıştığını, bu veri paylaşımının semafor ya da monitöre bir alternatif olduğunu söyledi. Özette, aynı veri üzerinde aynı anda çalışan birden fazla görevin (ortalama, standart sapma, aritmetik ortalama hesaplayan görevler) ve bir hava durumu programındaki görev kümesinin örnek olarak verildiği anlatıldı.

<!-- BELİRSİZ: Öğrenci özetindeki örneklerin ayrıntıları altyazıda bozuk (yaklaşık 00:49:53-00:51:19). -->

### 9.2 Makalenin Özü: Link

**Soru:** Burada mesajlaşmanın temeli olarak, alternatif olarak ne ortaya atılmıştır? **Cevap:** Bir öğrenci, literatürdeki semafor ve monitör tipindeki kaynak paylaşımına alternatif olarak link, görev ve mesaj kavramları üzerinden yeni bir süreçler arası iletişim sistemi önerildiğini söyledi.

**Soru:** Görev (task) yeni bir şey mi, yoksa link mi? **Cevap:** Görev, sürecin başka bir adıdır; makalede daha anlamlı bulunduğu için süreç yerine görev terimi kullanılmıştır. Hoca bunu onayladı ve makalenin özünün semafor ya da monitör yerine link kavramını getirmek olduğunu vurguladı.

**Soru:** Link nedir? **Cevap:** Bir öğrenciye göre link, bir görevin başka bir göreve mesaj göndermesine ya da belleğin bir kısmını okuyup yazmasına izin verir. Başka bir öğrenci, iki görev arasındaki iletişimi ve okuma-yazma için bellek alanına mesaj göndermeyi sağlayan bu yapıların tek yönlü olduğunu, karşılıklı haberleşme için bir link daha gerektiğini ekledi. Hoca bunu "link her zaman tek taraflı çalışıyor" diye özetledi.

<!-- BELİRSİZ: İlk öğrencinin linkin içeriğiyle ilgili cümlesi ("content and address") altyazıda tam anlaşılmıyor. -->

### 9.3 Link Tabloları

**Soru:** Görevler linklerini ne üzerinden yönetir, nasıl bir yapı vardır? **Cevap:** Her görevin bir link tablosu vardır ve bu tabloda linklerin yönetilebilmesi için linklere ait kimlikler (ID) bulunur. Bu tablolar sürecin adres alanının dışında, çekirdekte tutulur. Hoca ve öğrenci bunun linkleri koruma altına almak ve çekirdek tarafından yönetilmelerini sağlamak için olduğunda anlaştı.

### 9.4 Kod (Code) Alanı

**Soru:** Link yapısında "kod" diye bir şey var; bildiğimiz program parçası mı, başka bir şey mi? **Cevap:** Bir öğrenci kodun linkin hangi amaca hizmet ettiğini gösteren bir bilgi olduğunu düşündü; başka bir öğrenci linkin boyutu ve konumuyla ilgili bilgi olduğunu not aldığını, ama emin olmadığını söyledi. Hoca makaleden okuyarak cevapladı:

"Messages are identified by means of a code, which is simply a name specified by the task when it creates the link."

"The code from the link on which a message was sent is passed to a receiving task along with each message."

Yani kod, görevin linki oluştururken verdiği bir addır ve mesajın gönderildiği linkin kodu her mesajla birlikte alıcı göreve gider. Böylece alıcı mesajı ilişkilendirip ne yapacağına karar verebilir. Hoca bunu bir aksiyon kodu, işlem kodu gibi düşünmeyi önerdi: dosya açma, dosya kapama, dosyadan okuma, dosya silme gibi. Bunların gönderici ile alıcı arasında önceden anlaşılmış olması gerekir; amaç işi kolaylaştırmaktır.

### 9.5 Bypass Linkleri

Hoca bypass linklerinin ne işe yaradığını sordu. Bir öğrenci cevap vermeye çalıştı, ama cevabı altyazıda anlaşılmıyor ve hoca bir sonraki soruya geçti.

<!-- BELİRSİZ: Bypass linklerin görevi derste net olarak cevaplanmadı. -->

### 9.6 Mesaj Türleri

**Soru:** Kaç tür mesaj vardır? **Cevap:** Üç tür mesaj vardır ve bu türler mesajın gönderildiği linkin türüne göre belirlenir: request (istek) mesajı, reply (cevap) mesajı ve general (genel) mesaj.

**Soru:** General mesaj nedir? **Cevap:** Kullanıcıya, request ve reply mesajlarına konan kısıtlardan bir kaçış yolu verir.

### 9.7 Linki Kim Oluşturur, Link Yetenekleri

**Soru:** Bir link oluşturulurken linki kim oluşturur, oluşturulmasını kim talep eder? **Cevap:** Linke sahip olan görev, yani kaynak taraf linki oluşturur. Hoca "kaynak tarafı" diye onayladı.

**Soru:** Linki oluştururken linkin kime olacağıyla birlikte linkin yetenekleri de verilebilir mi; yetenek ne işe yarar? **Cevap:** Bir öğrenci makaledeki cümleyi aktardı: linkler yetenekler (capabilities) gibi işlenir, çekirdek bütün link işlemlerine katılır, ama bir linkin kavramsal kontrolü linkin adreslendiği sürece aittir. Hoca yeteneğin ne işe yaradığını tekrar sordu. Başka bir öğrenci, yeteneğin linkin amacı olduğunu, yani linkin bir dosyaya mı yoksa bellekte belli bir bölgeye mi erişeceğini, donanıma ve kaynaklara erişme türünü belirttiğini söyledi. Hoca bunun bir erişim kontrolü, erişim izni de olabileceğini sordu; öğrenci makalede "access capabilities" diye geçtiğini söyledi ve hoca bunu onayladı.

> **Ek bilgi (derste anlatılmadı):** Yetenek (capability), sahibine belirli bir nesne üzerinde belirli işlemleri yapma hakkı veren, taklit edilemez bir belirteçtir. Erişim denetim listelerinde haklar nesneye bağlı tutulurken, yetenek tabanlı sistemlerde haklar özneye (göreve) bağlı tutulur. DEMOS'ta link tablolarının çekirdekte tutulması, görevlerin linkleri sahteleyememesini büyük olasılıkla bu yüzden sağlar.

## 10. Örnek Sorular

Bu derste ekranda soru gösterilmedi. Aşağıdaki sorular hocanın derste sözlü olarak sorduğu sorulardır.

1. (derste sözlü, 00:10:05) Mesa makalesinde yazarlar hangi kavramları birbiriyle eşleştiriyor (duality)?
   - Derste verilen cevap: mesaj ↔ süreç, süreç ↔ monitör, send/reply ↔ call/return. Bir sürecin ötekini çağırması, ona mesaj gönderip cevabını almasına denktir. Bu ikilik makalenin 14 numaralı kaynağından gelir.

2. (derste sözlü, 00:22:36) "It treats a process as a first class value in the language" cümlesindeki first class value ne demektir?
   - Derste verilen cevap: fonksiyona parametre olabilen, fonksiyonun sonucu olabilen, atamada kullanılabilen ve eşitlik için test edilebilen değer. C'de `int` birinci sınıf, dizi ikinci sınıftır.

3. (derste sözlü, 00:33:57) Monitör yapısının öncelikli zamanlamayı boşa çıkardığı bir senaryo verin.
   - Derste net bir çözüm toparlanmadı.

> **Çözüm (derste verilmedi):** Düşük öncelikli P1 monitöre girer ve monitördeyken yüksek öncelikli P3 aynı monitöre girmek ister; P3 monitör serbest kalana kadar bekler. Bu sırada orta öncelikli P2 hazır olursa P1'in yerine çalışır. Sonuçta P3, kendisinden düşük öncelikli P2'nin bitmesini dolaylı olarak bekler (öncelik terslenmesi). Mesa makalesinde önerilen çözüm büyük olasılıkla monitöre, onu kullanabilecek süreçlerin en yüksek önceliğini vermektir.

4. (derste sözlü, 00:41:09) Süreç göçünde pending message ne demektir, neden önemlidir?
   - Derste verilen cevap: Süreç taşınırken çalışmaz, ama diğer süreçler ona mesaj göndermeye devam eder. Durdurma, taşıma ve hedefte yeniden başlatma sırasında gelen mesajlar ile kaynakta kuyrukta bekleyen mesajlar yeni adrese iletilmeli, linkler güncellenmelidir.

5. (derste sözlü, 00:45:26) Forwarding address ne anlama gelir?
   - Derste verilen cevap: Süreç başka bir çekirdeğe taşındığında eski yerde bırakılan, yeni adresi gösteren işaretçi; ağ yönlendirmedeki forwarding ile aynı fikir.

6. (derste sözlü, 00:46:15) Göçün maliyeti makalede hangi kavramlar üzerinden ifade edilir, hangisi ağır basar?
   - Derste verilen cevap: Doğrudan aktarım maliyeti ve linklerin güncellenmesinden doğan artımlı maliyet. Basit olmayan süreçlerde program ve verinin boyutu, sistem bilgisinin boyutunu gölgede bırakır; bekleyen her mesajın iletilmesi ise sıradan bir makineler arası mesaj kadar tutar.

7. (derste sözlü, 00:52:43) DEMOS'ta link nedir, görevler linklerini nasıl yönetir?
   - Derste verilen cevap: Link, bir görevin başka göreve mesaj göndermesini ya da bellek alanını okuyup yazmasını sağlayan tek yönlü yapıdır. Her görevin çekirdekte tutulan bir link tablosu vardır.

8. (derste sözlü, 00:54:55) Link yapısındaki "kod" nedir?
   - Derste verilen cevap: Linki oluşturan görevin verdiği addır; her mesajla alıcıya gider ve işlem kodu gibi kullanılır. Gönderici ile alıcı arasında önceden anlaşılmış olmalıdır.

9. (derste sözlü, 00:58:49) Kaç tür mesaj vardır, general mesaj nedir?
   - Derste verilen cevap: request, reply ve general. General mesaj request ve reply kısıtlarından kaçış yolu verir.

10. (derste sözlü, 01:00:22) Linki kim oluşturur, linkin yeteneği ne işe yarar?
    - Derste verilen cevap: Linki kaynak taraftaki görev oluşturur. Yetenek, linkin hangi kaynağa ne tür erişim sağlayacağını ve erişim iznini (access capabilities) belirtir.

<!-- BELİRSİZ: Hocanın sorduğu "bypass linkleri ne işe yarar?" (00:56:58) ve "göç adımları nelerdir?" (00:39:23) soruları derste net cevaplanmadığı için listeye alınmadı. -->

## Dersin Toparlaması

Bu derste üç makale üzerinden süreçler arası iletişim ve eş zamanlılığın uygulamadaki sorunları tartışıldı. Mesa makalesi, monitörlerin literatürde kâğıt üzerinde kalan ya da sonuca bağlanmayan yönlerini (iç içe monitör çağrıları, WAIT, öncelikli zamanlama, zaman aşımı, istisnalar, çok sayıda küçük nesne) Pilot işletim sistemine ekleyerek deneysel olarak çözmeye çalışıyor; bunu yaparken mesaj ile süreç ve send/reply ile call/return arasındaki ikilikten yararlanıyor. Aradaki bir soru üzerinden birinci sınıf değer kavramı C örnekleriyle açıklandı.

DEMOS/MP makalesi, dağıtık bir sistemde bir sürecin başka bir işlemciye taşınmasını; özellikle göç sırasında gelen ve kuyrukta bekleyen mesajların yönlendirme adresleri ve link güncellemeleriyle doğru yere ulaştırılmasını ve bunun maliyetini ele alıyor. DEMOS görev iletişimi makalesi ise semafor ve monitör yerine, çekirdekte tutulan tek yönlü linkleri; link kodlarını, mesaj türlerini ve erişim yeteneklerini öneriyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
