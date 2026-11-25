# Ders 3 Çalışma Özeti

## Genel Konular

- Ders bir makale tartışması biçiminde işlendi
  - Üç makale tartışıldı: "Experience with Processes and Monitors in Mesa", "Process Migration in DEMOS/MP" ve "Task Communication in DEMOS".
  - Öğrenciler makaleleri özetledi; hoca sorular sorup cevapları düzeltti ve makalenin özünü kendisi açıkladı.
  - Ekranda slayt paylaşılmadı. Kayıt Zoom konuşmacı görünümündeydi, bu yüzden bütün içerik altyazıdan alındı.
- Mesa ve Pilot'ta süreçler ve monitörler
  - Monitör kavramı eş zamanlılık (concurrency), yani birden fazla sürecin aynı anda birlikte çalışabilmesi içindir.
  - Literatürde monitörler kâğıt üzerinde çok tartışılmıştı, ama gerçek bir sistemde bazı şeylerin nasıl yapılacağı belirsizdi.
  - Makalede çözülmemiş sayılan başlıklar A'dan G'ye sıralanır: program yapısı, süreç oluşturma, monitör oluşturma, iç içe monitör çağrısında WAIT, istisnalar (exception), zamanlama (scheduling), giriş-çıkış.
  - Yazarlar Pilot işletim sistemine bu eş zamanlılık özelliklerini deneysel olarak ekliyor. Pilot, Mesa dilinde yazılmıştır.
- İkilik (duality)
  - Mesaj tabanlı yapı ile monitör/prosedür tabanlı yapı eşleştirilir: mesaj ↔ süreç, süreç ↔ monitör, send/reply ↔ call/return.
  - Bu ikilik yazarların kendi buluşu değildir; makalenin 14 numaralı kaynağındaki çalışmadan gelir.
- Monitörle eklenmek istenen üç yetenek
  - Yerel eş zamanlı programlama (local concurrent programming): bir uygulamanın kendi içinde, yapısını en iyi gösterecek alt parçalara bölünmesi.
  - Küresel kaynak paylaşımı (global resource sharing): aynı makinedeki birbirinden bağımsız uygulamaların ortak bir kaynağı düzgün paylaşması.
  - Kesmelerin (interrupt) yerine daha soyut bir model koymak.
- Birinci sınıf değer (first class value)
  - Bir değer birinci sınıf sayılmak için fonksiyona parametre olabilmeli, fonksiyonun sonucu olabilmeli, atamanın iki tarafında da kullanılabilmeli ve eşitlik için test edilebilmelidir.
  - C'de `int` birinci sınıftır, diziler ikinci sınıftır. Makale Mesa'da sürecin dilde birinci sınıf değer olarak ele alındığını söyler.
- Monitör ve öncelikli zamanlama (priority scheduling)
  - Hoca, monitör yapısının öncelikli zamanlamanın sağladığı özelliği ortadan kaldırdığı bir senaryo sordu. Senaryo makalede vardı, derste net bir cevap verilmedi.
- DEMOS/MP'de süreç göçü (process migration)
  - Bir sürecin dağıtık sistemde bir işlemciden başka bir işlemciye taşınması. İletişim link adı verilen bağlantılar üzerinden mesajlarla yapılır.
  - Bekleyen mesajlar (pending messages), yönlendirme adresi (forwarding address) ve göçün maliyeti tartışıldı.
- DEMOS'ta görev iletişimi (task communication)
  - Görev (task) sürecin bu makaledeki adıdır.
  - Makalenin özü, semafor ve monitör yerine link kavramını getirmektir.
  - Linkler tek yönlüdür; görevlerin link tabloları çekirdekte tutulur. Kod alanı, mesaj türleri (request, reply, general) ve link yetenekleri (capabilities) konuşuldu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makaleyi cümle cümle anlatmak yerine neyin ne olduğunu, makalenin özünü anlatmak gerekir
  - Hoca öğrencilerin ilk cevaplarını yetersiz buldu, çünkü "esas olayın özü atlandı": makale, monitörlerin gerçek bir sistemde uygulanmasında literatürde açık kalan soruları deneysel olarak çözmeye çalışıyor.
- Monitörde açık kalan uygulama soruları
  - WAIT: bir süreç WAIT yaptığında hangisinin devam edeceği belirsizdir; senaryoya göre biri ya da öteki daha iyi olabilir.
  - Öncelikli zamanlama: monitörle birlikte açlık (starvation) oluşabilir.
  - Zaman aşımı (timeout): monitör işlemi başladıktan sonra zaman aşımı olursa işlem iptal edilir, ama monitör kodu o ana kadar çalışmıştır; bunun nasıl geri alınacağı (unrolling), yarım kalan işlemin başına nasıl dönüleceği tartışılmalıdır.
  - Küçük ve çok sayıda nesne monitörle yönetilirse monitörleri yönetmenin performansı sorun olur.
- İşletim sistemi ile programlama dili iç içedir
  - Pilot Mesa'da yazılmıştır. Unix de C'de yazılmıştır; Unix'in doğal uygulama geliştirme dili C'dir, başka dillerde yazılan programlar da sonunda C kütüphanelerine iner.
- Birinci sınıf değerin dört özelliği
  - Tanım tartışmalıdır, ama genel kabul bu dört özelliğin dil tarafından doğal olarak (native) sağlanmasıdır.
- Süreç taşınırken çalıştırılamaz, ama ona mesaj gelmeye devam eder
  - Diğer süreçler bu sürecin çalışıp çalışmadığına bakmadan mesaj gönderebilir. Bu yüzden göç sırasında gelen ve kaynakta kuyrukta bekleyen mesajlar yeni yere iletilmelidir.
- Yönlendirme adresi, ağdaki yönlendirmeyle (forwarding) aynı fikirdir

## Kısa Tekrar Notları

- Mesa makalesi: monitörlerin gerçek sistemde (Pilot) uygulanmasında literatürde açık kalan soruları deneysel olarak çözer.
- Açık sorular: program yapısı, süreç ve monitör oluşturma, iç içe monitör çağrısında WAIT, istisnalar, zamanlama, giriş-çıkış.
- İkilik: mesaj ↔ süreç, süreç ↔ monitör, send/reply ↔ call/return. Bir sürecin ötekini çağırması, ona mesaj gönderip cevabını almaya denktir.
- Üç hedef: yerel eş zamanlı programlama, küresel kaynak paylaşımı, kesmelerin kaldırılması.
- Kesmeyi doğrudan yönetmek soyutlamayı kaldırır ve donanıma doğrudan müdahale gerektirir.
- Birinci sınıf değer: parametre olabilme, sonuç olabilme, atamada kullanılabilme, eşitlik testi.
- C'de `int` birinci sınıf, dizi ikinci sınıf. Yapılar (struct) kopyalanarak aktarılır. Fonksiyonların sınıfı tartışmalıdır (çalışma anında oluşturulamazlar).
- Bekleyen mesajlar: göç kararı, taşıma ve yeniden başlatma sırasında gelen ve kaynakta kuyrukta bekleyen mesajlar. Yeni adrese iletilmeli, linkler güncellenmelidir.
- Yönlendirme adresi: süreç artık o çekirdekte değilse eski yerde bırakılan, yeni yeri gösteren işaretçi.
- Göç maliyeti: doğrudan aktarım maliyeti ve linklerin güncellenmesi ile yönlendirmeden doğan artımlı maliyet.
- Basit olmayan süreçlerde program ve veri boyutu, sistem bilgisinin (süreç durumu) boyutunu gölgede bırakır.
- DEMOS: link, semafor ve monitöre alternatif. Linkler tek yönlüdür, karşılıklı iletişim için ikinci link gerekir.
- Link tabloları süreç adres alanının dışında, çekirdekte tutulur.
- Kod: link oluşturulurken görevin verdiği addır, her mesajla alıcıya gider; işlem kodu (opcode) gibi düşünülür.
- Üç mesaj türü: request, reply, general. General mesaj request/reply kısıtlarından kaçış yolu verir.
- Linki kaynak taraftaki görev oluşturur; link oluşturulurken erişim yetenekleri (access capabilities) de verilebilir.

## Detaylı Açıklamalar

- **Mesa makalesinin özü.** Monitör eş zamanlılık içindir. Literatürde monitörler üzerine çok şey yazılmıştı, ama bunların bir kısmı kâğıt üzerinde kalmış, bazı başlıklarda farklı yaklaşımları savunan yayınlar bir sonuca varmamıştı. Yazarlar Pilot'a eş zamanlılık özellikleri eklemek istiyor. Pilot'ta bu özellikler zaten var da onlarla oynanmıyor; yazarlar Pilot'u bu yönde geliştiriyor ve dönemin sıcak araştırma konusu olan açık soruları uygulamalı olarak görerek çözmeye çalışıyor. Hocanın saydığı açık sorular şunlardır: WAIT'in nasıl uygulanacağı, öncelikli zamanlamada monitörlerin durumu (açlık oluşabilir), zaman aşımında yarım kalan monitör işleminin nasıl geri alınacağı, istisna durumları ve çok sayıda küçük nesne monitörle yönetilirse oluşacak performans sorunu.

- **İkilik nereden geliyor?** Monitör yapısının arka tarafta bir program yapısıyla eşleştirilmesi gerekir. En akla yatkın eşleştirme monitörü prosedürlerle ilişkilendirmektir. Bir prosedüre bağlı süreç başka bir süreçle konuşacaktır; eş zamanlılığı içerdiği için bu yapı bir monitöre denk düşer. İki süreç konuşacaksa aralarında mesajlaşma olmalıdır; bu yüzden mesaj ile süreç arasında bir ikilik kurulur. Ortak bir amaç için eş zamanlı çalışan iki süreçte birinin diğerini çağırması, ona mesaj gönderip cevabını almasına, yani send/reply'a denk düşer; bu da call/return'dür. Hoca bu ikiliğin yazarların kendi önerisi olmadığını, daha önceki bir yayından (makalenin 14 numaralı kaynağı) geldiğini vurguladı.

- **Üç yetenek.** Yazarlar monitör yapısıyla Pilot ortamına üç şey kazandırmak istiyor. Birincisi yerel eş zamanlı programlama: aynı uygulamanın alt parçalara bölünmesi. İkincisi küresel kaynak paylaşımı: birbirinden bağımsız uygulamaların aynı makinedeki ortak bir kaynağı düzgün paylaşması. Üçüncüsü kesmeleri ortadan kaldırmak: kesmeyi doğrudan yönetmek soyutlamayı kaldırır ve donanıma doğrudan müdahale gerektirir. Bunun yerine daha soyut bir modelle hem gerekli uyandırma (wake-up) mekanizması hem de senkronizasyon sağlanır.

- **Birinci sınıf değer.** Makale "It treats a process as a first class value in the language" der. Bir değer şu dört özelliğin hepsine sahipse birinci sınıftır: fonksiyona parametre olabilmek, fonksiyonun sonucu olabilmek, bir atamanın sonuç tarafı olabilmek ve eşitlikte test edilebilmek. C'de bir `int` değişkene atama yapılabilir, fonksiyona gönderilebilir, fonksiyondan dönebilir, iki `int` eşit mi diye bakılabilir; bu yüzden `int` birinci sınıftır. Dizi ise fonksiyona dizi olarak gönderilemez, yalnız ilk adresi gönderilir; çalışma anında `A = B` ya da `A == B` diye dizinin tamamı üzerinde işlem yapılamaz. Bu yüzden diziler ikinci sınıftır. Yapılar daha ilginçtir: adresi verilmedikçe yerel bir kopyası çıkarılır, kopya üzerinde çalışılır, kopya geri döndürülür. Nesneye yönelik dillerde her şey nesne olarak aktarıldığı ve eşitlik metodu yazılabildiği için bu kavram daha anlamlıdır. C'de fonksiyonlar fonksiyon işaretçisiyle parametre olarak aktarılabilir ve iki işaretçinin aynı yeri gösterip göstermediği kontrol edilebilir, ama çalışma anında dinamik olarak fonksiyon oluşturulamaz. Bu yüzden bir grup C fonksiyonlarını ikinci sınıf, bir grup birinci sınıf sayar.

- **Süreç göçü ve bekleyen mesajlar.** Süreç taşınırken çalıştırılamaz. Ama diğer süreçlerin ona mesaj göndermesi bu sürecin çalışıp çalışmamasıyla ilgili değildir; aralarında iş birliği olan süreçler istedikleri anda mesaj gönderebilir. Bu yüzden süreç taşımak için durdurulduğunda, taşınırken ve hedef işlemcide yeniden başlatılırken gelen mesajlar olabilir. Ayrıca göç kararı verildiği anda kaynakta, işletim sisteminin sürece aktarmaya fırsat bulamadığı, kuyrukta bekleyen mesajlar da olabilir. Bunlara bekleyen mesaj denir. Bunlar yeni adrese iletilmeli ve sürecin değişen link adresleri güncellenmelidir.

- **Yönlendirme adresi ve maliyet.** Süreç artık o çekirdekte değilse eski yerine, yeni adresi gösteren bir yönlendirme adresi konur; bu, ağ yönlendirmedeki forwarding ile aynı fikirdir. Göçün maliyeti iki kısımda ele alınır: sürecin doğrudan aktarım maliyeti ve linklerin güncellenmesi, mesajların yönlendirilmesi gibi işlerden doğan artımlı maliyet. Makaleye göre basit olmayan süreçlerde program ve verinin boyutu, aktarılması gereken sistem bilgisinin (süreç durumu, süreç kontrol bloğu) boyutunu gölgede bırakır. Kuyrukta bekleyen her mesajın hedef makineye iletilmesinin maliyeti ise başka herhangi bir makineler arası mesajın maliyetiyle aynıdır; bu yüzden mesajlaşma yükü açısından çok şey değişmez.

- **DEMOS'ta linkler.** Makalenin özü semafor ya da monitör yerine link kavramını getirmektir. Link, bir görevin başka bir göreve mesaj göndermesini ya da belleğin bir kısmını okuyup yazmasını sağlar. Linkler tek yönlüdür; karşılıklı iletişim için bir link daha gerekir. Her görevin bir link tablosu vardır. Bu tablo sürecin adres alanının dışında, çekirdekte tutulur; böylece koruma altındadır ve çekirdek tarafından yönetilir.

- **Kod alanı.** Makalede "messages are identified by means of a code, which is simply a name specified by the task when it creates the link" denir. Mesajın gönderildiği linkin kodu her mesajla birlikte alıcı göreve iletilir. Böylece alıcı mesajı ilişkilendirip ne yapacağına karar verebilir. Hoca bunu bir işlem kodu gibi düşünmeyi önerdi: dosya açma, dosya kapama, dosyadan okuma, dosya silme gibi. Kodların gönderici ile alıcı arasında önceden anlaşılmış olması gerekir.

- **Mesaj türleri ve link yetenekleri.** Gönderildikleri linkin türüne göre üç tür mesaj vardır: request, reply ve general. General mesaj, kullanıcıya request ve reply mesajlarına konan kısıtlardan bir kaçış yolu verir. Linki, linke sahip olan kaynak taraftaki görev oluşturur. Link oluşturulurken linkin kime olacağıyla birlikte yetenekleri de verilebilir; yetenek, linkin hangi kaynağa ne tür erişim sağlayacağını (dosya mı, bellekte bir bölge mi) ve erişim iznini (access capabilities) belirtir.

<!-- BELİRSİZ: Öğrenci özetlerinin (Mesa, DEMOS/MP göç adımları, DEMOS örnek programları) önemli kısmı altyazıda bozuk; bypass linklerin ne işe yaradığı ve monitörün öncelikli zamanlamayı bozduğu senaryo derste net cevaplanmadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
