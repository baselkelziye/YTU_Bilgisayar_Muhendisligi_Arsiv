# Ders 6 Çalışma Özeti

## Genel Konular

- Alan modeli (domain model) ve kavramsal sınıf diyagramı (ekrandan, 00:45:00)
  - UML sınıf diyagramına geçmeden önce uygulama alanındaki kavramların (nesnelerin) bir "görsel sözlüğü" çıkarılır: alandaki kavramlar, bunlar hakkında tutulacak bilgiler (özellikler) ve kavramlar arasındaki ilişkiler gösterilir.
  - Örnek (kısmi alan modeli, video mağazası): `Customer` (address, name, phoneNumber), `VideoStore` (address, name, phoneNumber), `Video` (ID) sınıfları.
  - İlişkiler: `Customer` * — `Rents-from` → 1 `VideoStore`; `VideoStore` 1 — `Stocks` → * `Video`; `Customer` 1 — `Rents` → 1..* `Video`.
  - Bağlantılarda ilişki adı okun üzerinde yazılır; çokluk (multiplicity) bire bir, bire çok, `1..*`, sınırlı aralık (örneğin 1 ile 40 arası) ya da sabit bir sayı (örneğin 5) olabilir. Notasyon ER diyagramından farklıdır ama mantık benzerdir.
  - Analizde önce özellikler (attribute) verilir; işlemler (operation) tasarımda ayrıntılandırılır.
- UP kullanım senaryosu modelindeki ürünler (artifacts) (ekrandan, 00:50:00)
  - İş modelleme (Business Modeling): alan modeli.
  - Gereksinimler (Requirements): metin olarak kullanım senaryoları (use case belgeleri), use case diyagramları, sistem sıralama diyagramları (system sequence diagrams) ve sistem işlemleri sözleşmeleri (system operation contracts).
  - Tasarım (Design): tasarım modeli; tam sınıf diyagramı ve tamamlanmış sıralama diyagramları burada ortaya çıkar.
  - Bu ürünler kısmidir ve her iterasyonda geliştirilir.
- Tasarım kalıpları ve yeniden kullanılabilirlik
  - Yeniden kullanılabilirlik (reusability) geliştirici açısından önemli bir kalite özelliğidir; tasarım kalıpları yeniden kullanılabilir nesne modelleridir.
  - Tasarımda mutlaka tasarım kalıplarına yer verilmelidir; analizde hangi kalıpların kullanılabileceği düşünülmeye başlanır.
  - Nesneye yönelik analiz ve tasarımın öncüleri olarak Booch, Jacobson ve Rumbaugh anıldı. <!-- BELİRSİZ: altyazıda adlar bozuk ("Buç, Jacobs'ın Romba"); bağlamdan Booch, Jacobson, Rumbaugh olarak düzeltildi. -->
- Kullanım senaryoları (use case) (ekrandan, 00:55:00)
  - Use case'ler özellikle fonksiyonel gereksinimleri yakalamanın bir yoludur; bir sistemin kullanılmasına ilişkin hikâyelerdir.
  - Hedefler: farklı use case seviyelerini tanımak, popüler Cockburn formatında use case yazmak, öz (essential) ve somut (concrete) use case'leri ayırt etmek, kılavuzları uygulamak, use case diyagramlarını okumak ve yazmak.
  - Temel kavramlar: birincil aktör (primary actor, örneğin mağaza görevlisi), destek aktörü (supporting actor, örneğin kredi onay servisi gibi dış sistemler).
  - Senaryo (scenario): aktörler ile sistem arasındaki eylem ve etkileşimlerin belirli bir sırası; burada sıra önemlidir.
  - Use case: bir aktörün bir hedefe ulaşmak için sistemi kullanmasını anlatan, ilgili başarılı ve başarısız senaryoların toplamıdır.
- Kısa format use case örneği (ekrandan, 01:00:00)
  - "Rent Videos": Müşteri kiralayacağı videolarla gelir. Görevli müşterinin ve her videonun ID'sini girer. Sistem her biri için bilgi verir. Görevli kiralama raporunu ister. Sistem raporu üretir, rapor videolarla birlikte müşteriye verilir.
- Use case seviyeleri ve Temel İş Süreci (EBP) kılavuzu (ekrandan, 01:05:00 ve 01:10:00)
  - Çok ayrıntılı, bütün organizasyonu kapsayan use case'ler büyük resmi kaçırtır, yönetim ve karmaşıklık sorunları getirir; çok küçük adımlar da anlamsızdır.
  - Cockburn'ün EBP tanımı: bir kişinin bir yerde bir zamanda, bir iş olayına karşılık gerçekleştirdiği, ölçülebilir iş değeri katan ve veriyi tutarlı bir durumda bırakan görev.
  - EBP seviyesindeki bir use case genellikle tek bir ya da iki adımdan değil, birkaç adımdan oluşur.
  - Use case'ler veri akış diyagramlarındaki gibi aşama aşama, basitten karmaşığa doğru ayrıntılandırılır.
- Use case diyagramı (ekrandan, 01:15:00)
  - Örnek: Video Store Information System. Solda insan aktörler (Clerk, Customer, Administrator), sağda dış sistem aktörü («actor» Credit Authorization Service).
  - Use case'ler: Pay Fines, Rent Items, Manage Memberships, Log In, Manage Inventory, Manage Users.
  - Kural: birincil (canlı) aktörler sola, destek aktörleri (dış sistemler) sağa çizilir; bilgisayar sistemi aktörü kutu şeklinde gösterilir.
  - Uyarı: Diyagram çizmeye çok zaman harcanmamalıdır; use case çalışmasının özü metin (belge) yazmaktır.
- Use case modelleme kılavuzları (ekrandan, 01:20:00)
  - EBP seviyesindeki (kullanıcı seviyesi hedef, user-level goal) use case'ler tercih edilir.
  - Kalite kontrolü: Configure System benzeri bir use case, gerekirse Start Up ve Shut Down use case'leri ve System Administrator aktörü var mı?
  - Küçük ekiplerde önce taslak use case diyagramı çizilir, ekipçe üzerinde anlaşılır, sonra bir seviye daha ayrıntılandırılır.
- Tam ayrıntılı (fully dressed) use case örneği (ekrandan, 01:25:00)
  - UC1 Rent Videos: kullanıcı seviyesi hedef; birincil aktör görevli; ön koşul: görevli tanıtılmış ve kimliği doğrulanmış.
  - Paydaşlar ve ilgileri: görevli hızlı ve doğru giriş ister; müşteri az zahmetle hızlı hizmet ister; muhasebe işlemlerin doğru kaydedilmesini ister; pazarlama müşteri alışkanlıklarını izlemek ister.
  - Ana başarı senaryosu ("happy path") 9 adımdır; 3-4. adımlar her kalem için tekrarlanır.
  - Uzantılar (alternatif akışlar): sistem çökerse görevli sistemi yeniden başlatıp kurtarma ister; müşteri yeniyse üyelik işlemi yapılır; müşteri ID'si bulunamazsa giriş düzeltilir.
  - Özel gereksinimler (mesaj ve raporların dili), teknoloji ve veri çeşitlemeleri (ID barkodla okunabilir ya da klavyeden girilebilir), sıklık ve açık konular da belgeye yazılır.
- Öz (essential) ve somut (concrete) use case (ekrandan, 01:30:00)
  - "Arayüzü dışarıda tut": öz use case arayüz ayrıntılarını erteler, aktörlerin niyetine odaklanır.
  - Öz: "Görevli müşteri ID'sini girer." Somut (daha kötü): "Görevli müşteri kimlik kartını alır ve barkodu lazer okuyucuyla okur."
- Nesne yönelimli tasarım diyagramları
  - Sıralama şeması (sequence diagram): nesneler arasındaki iş birliğini ve etkinleşme sırasını gösterir (ekrandan, 01:50:00).
  - Etkinlik şeması (activity diagram): denetim akışı, başlangıç, eylem, karar, eş güdüm (fork/join) gösterimleri; analizde başlanır, tasarımda tamamlanır.
  - Durum şeması (state diagram): bir nesnenin durumları ve olaylarla durumlar arası geçişler (ekrandan, 01:55:00).
  - Tasarım modelini tamamlamak için sınıf diyagramı bütün özellik ve işlemleriyle tamamlanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Use case diyagramını okuyabilmek ve yazabilmek
  - Verilen bir use case diyagramından sistemin hangi fonksiyonel gereksinimleri anlattığı okunabilmeli; sıfırdan verilen bir hikâyenin use case diyagramı çizilebilmelidir. Hoca sınavlara çalışırken buna dikkat edilmesini söyledi.
- Use case'in özü belgedir
  - Diyagram canlandırmak için çizilir, ilk çizimin ideal olması için uğraşılmaz; asıl ayrıntı (aktörler, ön koşullar, adımlar, alternatifler) use case belgesindedir.
- Adım adım ayrıntılandırma
  - Use case'ler tek seferde en karmaşık haliyle çizilmez; veri akış diyagramlarındaki bağlam diyagramı → 1. düzey → 2. düzey gibi aşama aşama ilerlenir. Örneğin tedarikçi işlemleri, temel kiralama süreci anlaşılmadan aynı diyagrama katılmamalıdır.
- İşlem sırası
  - Gereksinim analizinde hangi olayın hangisinden önce olduğu doğru tanımlanmalıdır; tasarıma bu sıra aktarılır.
- Tasarımda tamamlanması gereken diyagramlar
  - Etkinlik, durum, sınıf ve sıralama diyagramları tasarım sırasında tamamlanmalıdır.

## Kısa Tekrar Notları

- Alan modeli = görsel sözlük: kavramlar, özellikleri ve ilişkileri; işlemler analizde değil tasarımda ayrıntılanır.
- UP ürünleri: alan modeli (iş modelleme); metin use case, use case diyagramı, sistem sıralama diyagramı, sistem işlem sözleşmeleri (gereksinimler); tasarım modeli (tasarım).
- Use case = ilgili başarılı ve başarısız senaryoların toplamı; senaryo = belirli bir eylem ve etkileşim sırası.
- Birincil aktör sola, destek aktörü (dış sistem) sağa.
- EBP: bir kişi, bir yer, bir zaman, bir iş olayı, ölçülebilir iş değeri, tutarlı veri.
- Fully dressed use case bölümleri: seviye, birincil aktör, paydaşlar ve ilgileri, ön koşullar, ana başarı senaryosu, uzantılar, özel gereksinimler, teknoloji ve veri çeşitlemeleri, sıklık, açık konular.
- Öz use case arayüzden bağımsızdır ("Keep the UI out").
- Kalite kontrolü: Configure System, Start Up / Shut Down use case'leri, System Administrator aktörü.
- Sıralama şemasında: düz ok = mesaj (metot çağırma), kesikli ok = geri dönüş, `[koşul]` = koşullu mesaj, `* [koşul]` = döngü, `new` = nesne oluşturma.
- Durum şeması: başlangıç ve bitiş işaretleri, durumlar yuvarlak köşeli kutular, geçişler olay etiketli oklar.

## Detaylı Açıklamalar

- **Alan modelinden sınıf diyagramına.** Nesneye yönelik analizde ilk adım, uygulama alanındaki kavramları bulmaktır. Video mağazası örneğinde müşteri, mağaza ve video kavramları ile bunların adres, ad, telefon ve ID gibi özellikleri belirlenir. Kavramlar arasındaki "kiralar", "kiralama yapar", "stoklar" gibi ilişkiler, okun yönü ve çoklukla birlikte gösterilir. Bu kavramsal sınıf diyagramı, use case'ler hazırlandıktan sonra oluşturulur ve tasarımda işlemleri eklenerek yazılım sınıf diyagramına dönüşür (ekrandan, 00:45:00).
- **UP'de ürünlerin yeri.** Unified Process'te gereksinimler use case modeli içinde toplanır: metin use case'ler, use case diyagramları, sistemi tek bir kara kutu gibi gösteren sistem sıralama diyagramları (`:System` nesnesine `foo(x)`, `bar(y)` gibi sistem işlemleri) ve bu işlemlerin sözleşmeleri. Tasarım kalıpları eklendiğinde ortaya çıkan model tasarım modelidir. Ürünler her iterasyonda biraz daha ayrıntılandırılır (ekrandan, 00:50:00).
- **Use case belgesi ve diyagramı.** Use case çalışması esasen bir metin (belge) yazma işidir: birincil aktör, diğer ilgililer, ön koşullar, üst seviye bir algoritma gibi sıralanmış adımlar ve alternatif akışlar belgede yer alır. Diyagram ise veri akış diyagramlarındaki bağlam diyagramı gibi sistemin özetini verir. Video Store Information System diyagramında görevli, müşteri ve yönetici solda; ödeme ve kiralama işlemlerinde kredi kontrolü yapan Credit Authorization Service sağda yer alır. Görevli üyelikleri yönetir, sisteme giriş yapar ve kiralama işlemini yürütür; yönetici envanteri ve kullanıcıları yönetir (ekrandan, 01:15:00). <!-- BELİRSİZ: karede aktörlerden use case'lere giden çizgilerin hangi use case'e bağlandığı tam seçilemiyor; yalnız görevli ve yönetici bağlantıları anlatımla desteklendi. -->
- **EBP ve doğru seviye.** İş süreci anlatılırken "Bütün gün ne yapıyorsunuz?" sorusu sorulmuş gibi düşünülür: "bütün gün sistemdeydim, çalışıyordum" yanıtı yetmez; hangi işlerin yapıldığı ortaya çıkarılmalıdır. Use case seviyesi genelden başlayıp her adımda bir seviye daha ayrıntılandırılır. EBP seviyesi genelde birkaç adımlı bir use case'tir (ekrandan, 01:05:00 ve 01:10:00).
- **Tam ayrıntılı Rent Videos ana başarı senaryosu (ekrandan, 01:25:00):**
  - 1. Müşteri kiralayacağı video ya da oyunlarla kasaya gelir.
  - 2. Görevli müşteri ID'sini girer.
  - 3. Görevli kiralama tanımlayıcısını girer.
  - 4. Sistem kiralama kalemini kaydeder ve kalem açıklamasını gösterir. (Görevli bitti diyene kadar 3-4. adımları tekrarlar.)
  - 5. Sistem toplamı gösterir.
  - 6. Müşteri öder; sistem ödemeyi işler.
  - 7. Görevli kiralama raporunu ister.
  - 8. Sistem raporu üretir; görevli raporu müşteriye verir.
  - 9. Müşteri kiraladıkları ve raporla ayrılır.
- **Durum şeması örneği: NextGenPOS kasası (ekrandan, 01:55:00).** Güç açılınca kasa "Boşta bekleme" durumuna geçer. "Satış başlatıldı" ile "Satış kaydetme"ye geçilir; her "Barkod girildi" olayında aynı durumda kalınır. "Ürün iptal düğmesine basıldı" ile "Satıştan tek ürün silme"ye gidilir ve barkod girilince satış kaydetmeye dönülür. "Alınacak ürün kalmadı" ile "Ödeme bekleme"ye, "Ödeme alındı" ile "Makbuz verme"ye geçilir; ardından kasa yeniden boşta bekler. Boşta beklerken "Kapatma düğmesine basıldı" olayı bitiş durumuna götürür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
