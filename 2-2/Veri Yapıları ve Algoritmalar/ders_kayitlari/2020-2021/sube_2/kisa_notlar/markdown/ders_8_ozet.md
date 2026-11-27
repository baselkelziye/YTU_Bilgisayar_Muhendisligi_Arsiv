# Ders 8 Çalışma Özeti

## Genel Konular

- Bağlı listeyi ters çevirme
  - Amaç, bütün bağlantıları ters yöne çevirmektir: son eleman yeni baş (head) olur, eski ilk elemanın işaretçisi `NULL` olur. A, B, C, D, E, F sırasındaki liste F, E, D, C, B, A sırasına döner.
  - Yalnız değerleri değil, düğümlerin birbirini gösterdiği bağlantıları ters çevirmek istenir.
  - Derste önerilen yaklaşım iki işaretçiyle (previous ve current) çalışmaktır.
  - Listenin sonu baştan bilinmediği için işleme baştan (head'den) başlamak mantıklıdır. Sondan başlamak için önce bir kez sona kadar gitmek gerekir; bu ek bir tur maliyeti getirir.
- Bağlı listede en büyük elemanı sona taşıma (ya da en küçüğü başa alma)
  - Temel (en basit) çözüm: listeyi bir kez gezip en büyük değeri öğren, sonra o değerin düğümünü bulmak için yeniden gez, sonra sona kadar ilerleyip "sil ve ekle" işlemiyle düğümü sona koy.
  - Daha etkili çözüm: gezinti sırasında o ana kadarki en büyük elemanın adresini (max işaretçisi) tut. `NULL`a ulaşıldığında düğüm, tutulan adres sayesinde ikinci bir gezinti yapmadan listeden çıkarılıp sona eklenir.
  - Yalnız değeri bir geçici değişkende tutmak sona ekleme için yeterlidir, ama aradaki düğümü silmek için adresi tutmak gerekir.
  - Aynı yöntem en küçük elemanı başa almak için de kullanılabilir.
- Tek sayıları başa, çift sayıları sona toplama (sıra korunarak)
  - Tamsayılardan oluşan bir bağlı listede tek sayılar başa, çiftler sona gitmelidir; her grup kendi içinde listedeki ilk sırasını korumalıdır (sıralama istenmez).
  - Örnek: 2, 3, 1, 6, 7 listesi 3, 1, 7, 2, 6 olmalıdır.
  - Derste konuşulan çözüm: ilk çift sayının (örnekte 2) adresini tutan bir işaretçi tutulur. Liste gezilirken her tek sayı bu ilk çiftin önüne eklenir; çiftler yerinde bırakılır. Tekler bulundukları sırayla eklendiği için kendi aralarındaki sıra korunur.
- Kendi başına çalışılması önerilen konular
  - Çift yönlü (doubly) ve dairesel (circular) bağlı listelerde ileri-geri gezinti.
  - Liste işlemlerinin çalışma süresini 100, 1000, 10.000 gibi farklı eleman sayılarıyla deneysel olarak ölçmek; oluşturma ve sıralama sürelerinin $n^2$ ya da $\log n$ gibi büyüme biçimlerini gözlemek.
  - Seyrek (sparse) matrisi ve genel olarak matris yapısını bağlı listeyle göstermek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce temel çözüm
  - Bir probleme her zaman önce en basit çözümle başlanır, sonra bu çözümün daha etkili hâle getirilip getirilemeyeceği düşünülür (en büyük elemanı sona taşıma örneğinde olduğu gibi).
- Bağlı listelerle el alıştırması
  - Hoca, bu tür problemlerin algoritmasını tasarlamayı, akışını çizmeyi ve kodlamayı önerdi. Bağlı liste temel ve çok esnek bir veri yapısıdır; sonraki pek çok veri yapısında sıkça kullanılacaktır.

## Kısa Tekrar Notları

- Ters çevirme: previous ve current işaretçileriyle, baştan başlayarak her düğümün bağlantısı bir öncekine çevrilir; sonunda son düğüm yeni head olur.
- Sondan başlamak, sonu bulmak için fazladan bir tur gerektirir.
- En büyüğü sona taşıma: tek geçişte max düğümün adresini tut; `NULL`da düğümü çıkar ve sona bağla.
- Silme için değer değil adres gerekir.
- Tekler başa, çiftler sona: ilk çiftin adresini tut, her teki onun önüne ekle; iki grubun iç sırası korunur. 2, 3, 1, 6, 7 → 3, 1, 7, 2, 6.
- Alıştırma önerileri: çift yönlü ve dairesel listeler, deneysel süre ölçümü, seyrek matrisin bağlı listeyle gösterimi.

## Detaylı Açıklamalar

- Bu kayıt kısa bir uygulama oturumudur ve ekranda slayt ya da kod gösterilmemiştir; problemler sözlü olarak konuşulmuştur. Hoca, daha önce bağlı listeyle insertion sort anlattığını hatırlatıp öğrencilere bu tür problemleri kendi başlarına denemelerini önerdi ve birkaç yeni problem ortaya attı.
- Bağlı listeyi ters çevirmede her adımda current düğümün bağlantısı previous düğüme çevrilir, sonra iki işaretçi bir düğüm ilerletilir. İlk düğümün bağlantısı `NULL` olur, sonuna gelindiğinde son düğüm yeni head olur. Bir öğrencinin önerdiği "sondan kesip başa ekleme" fikrine hoca, istenenin bütün bağlantıları ters çevirmek olduğunu söyleyerek karşılık verdi. Listenin sonu bilinmediğinden baştan başlamak gerekir; sondan başlanacaksa önce bir kez sona kadar gidilmesi zaten ek bir maliyettir.
- En büyük elemanı sona taşıma probleminde temel çözüm üç gezinti kadar iş yapar: en büyük değeri bulmak, o değerin düğümünü bulmak, sona kadar gidip sil-ekle yapmak. Bir öğrenci en büyük değeri geçici bir değişkende tutmayı önerdi; hoca sona eklemenin bu şekilde yapılabileceğini, ama aradaki düğümü silmek için onun yerinin bilinmesi gerektiğini sordu. Sonuçta en büyük düğümün adresini (max işaretçisi) tutmanın doğru çözüm olduğu üzerinde anlaşıldı. Aynı yaklaşım en küçük elemanı başa almak için de geçerlidir.
- Tek-çift ayırma probleminde istenen sıralama değil, grupların kendi içindeki ilk sırayı koruyarak yeniden düzenlenmesidir. Örnek listede (2, 3, 1, 6, 7) ilk çift sayı 2'dir. Gezinti sırasında 3 bulunur ve 2'nin önüne eklenir; sonra 1 bulunur ve yine 2'nin önüne (3'ün arkasına) eklenir; 6 çift olduğu için bırakılır; 7 yine 2'nin önüne eklenir. `NULL`a gelindiğinde liste 3, 1, 7, 2, 6 olur. Hoca bu yöntemle tekleri başa ya da çiftleri başa almanın yalnız kontrol koşulunu değiştirmek olduğunu söyledi.
  <!-- BELİRSİZ: Bağlı listede bir düğümü başka bir düğümün "önüne" eklemek için bir önceki düğümün (örneğin son eklenen tek sayının) adresi de gerekir; derste bu ayrıntı açıkça konuşulmadı. -->
- Hoca ayrıca Josephus probleminin de daha önce konuşulduğunu hatırlattı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
