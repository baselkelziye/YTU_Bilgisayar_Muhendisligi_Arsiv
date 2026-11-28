# Ders 12 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumları
  - Dersin büyük bölümünde öğrenci grupları dönem projelerinin modelleme ve proje yönetimi kısımlarını sundu. Programın çalıştırılması ve kod ayrıntıları ayrı bir uygulama oturumuna bırakıldı.
  - Konular: üniversite kütüphanesi bilgi sistemi (dört grup), poliklinik bilgi sistemi (üç grup) ve medya takip sistemi (bir grup).
  - Sunumların ortak iskeleti: proje kapsamı, kabuller ve kısıtlar, iş-zaman çizelgesi (Gantt), ekip organizasyon şeması ya da görev dağılımı, risk tablosu, kullanım senaryoları ve kullanım durumu diyagramı, izlenebilirlik tablosu, kavramsal ve metotlu sınıf diyagramı, sıralama (ardışıl), etkinlik ve durum diyagramları, veri tabanı tasarımı, birim testleri.
- Kabuller ve kısıtlar
  - Kütüphane projesi kabulleri: fiziksel altyapının (internet, elektrik, kiosk, bilgisayar) çalışır olması, yazılımın kiosklara sorunsuz yüklenmesi, arızaların zamanında bildirilmesi. Kısıtlar: yalnız 5 kişilik ekip, 4 aylık (120 gün) süre, eldeki kaynakların kullanılması.
  - Kütüphane kuralları (bir grubun sunumu): öğrenci ve memur en fazla 3, öğretim üyesi en fazla 6 parça ödünç alır; ödünç süresi öğrenci ve memur için 1 ay, öğretim üyesi için 3 ay; geciken her gün için 1 TL ceza; ders kitabını yalnız öğretim üyeleri alabilir.
  - Poliklinik projesi kabulleri: sigorta sorgusu hazır bir sistem üzerinden yapılır, her doktorun tek branşı vardır, doktorlar her gün çalışır, en fazla 20 gün sonrası için randevu alınabilir (ekrandan, 00:50:00). Başka bir grubun kısıtları: muayene 30 dakika, gidilmeyen randevuya 24 saat ceza, indirim yalnız belirli sigortaya.
  - Medya takip projesi kabulleri: geçerli e-posta ("@" içermeli), en az 6 karakterli şifre, takip sıklığı arttıkça ücretin aynı oranda artması, aynı medya organının farklı sıklıkla iki kez eklenememesi (ekrandan, 01:20:00).
- Proje planlama ve iş-zaman çizelgesi
  - Gantt çizelgelerinde ana başlıklar (proje planı, analiz, yazılım, test ve hata düzeltme), adam-gün süreleri, tamamlanma yüzdesi, başlangıç ve bitiş tarihleri gösterildi.
  - Bir grubun çizelgesi: fizibilite analizi, proje planı, kullanım senaryoları, nesneye dayalı modelleme ve diyagramlar, Java ile gerçekleme, refactoring, birim testleri, rapor (ekrandan, 01:35:00).
  - Fizibilite türleri: yazılım (teknoloji seçimi), donanım (hangi işletim sistemi ve donanımda çalışacağı) ve ekonomik fizibilite.
  - Bir grup planlanan toplantı tarihlerini gerçekleşen tarihlerle karşılaştırarak çizelgedeki kaymayı gösterdi.
- Yazılım geliştirme modeli seçimi
  - Bir grup şelale modelini seçti: gereksinimler iyi tanımlanmış, açık ve sabit; değişiklik ve belirsizlik olmadığından sistem tanımı durağan; ekip teknolojiyi tanıyor; fonksiyon sayısı az ve sınırlı; sistem tamamlanınca devreye alınacak; yeni talepler sonraki sürüme bırakılabilir (ekrandan, 02:15:00).
  - Aşamalar: planlama, gereksinim, çözümleme, tasarım, gerçekleme, sınama (birim testi ve kullanıcı kabul testi).
- Maliyet ve fayda
  - Bir grup maliyeti adam-gün üzerinden tahmin etti: kişi başı günlük 1000 TL, toplam 70 adam-gün, yani 70.000 TL.
  - Maddi faydalar: operasyon maliyetinin azalması, yeni donanım alımına gerek olmaması, kayıp oranının düşmesi. Maddi olmayan faydalar: hizmet kalitesi, kullanıcı memnuniyeti, prestij.
- Risk yönetimi
  - Risk tablolarında risk faktörü/türü, risk, olasılık, etki, nedenleri ve önlemleri yer aldı (ekrandan, 00:10:00; ekrandan, 01:05:00).
  - Hoca, risk tablosunun proje başında, sistem henüz yokken öngörüyle hazırlandığını ve riskin derecesinin olasılık ile etkinin çarpımıyla belirlendiğini vurguladı.
- İsteklerin modellenmesi
  - Kullanım senaryosu belgesi: birincil aktör, diğer ilgililer ve ilgi alanları, ön koşullar, son koşullar, ana senaryo (numaralı adımlar), alternatif senaryolar (ör. 3.a, 8a, 8b).
  - Kullanım durumu diyagramlarında «include» (zorunlu alt işlem, ör. iade sonrası envanterden çıkarma) ve «extend» (koşullu ek davranış, ör. stok yoksa rezervasyon) ilişkileri kullanıldı (ekrandan, 00:40:00).
  - İzlenebilirlik tablosu gereksinimleri aktörler ya da bakış açılarıyla eşleştirir.
- Nesneye dayalı modelleme ve tasarım
  - Kavramsal sınıf diyagramında yalnız sınıflar, nitelikler ve ilişkiler bulunur; tasarım sınıf diyagramına metotlar eklenir.
  - İlişki türleri: bire-çok (ör. envanter-parça, yazar-parça), bileşim (hasta olmadan anlamı olmayan belge sınıfı), kalıtım (item üst sınıfından kitap, DVD, dergi), arayüz (kiosk arayüzündeki ödünç alma, arama, iade).
  - Sıralama diyagramlarında «alt» parçası ile koşullu akış gösterildi (ekrandan, 00:15:00).
  - Etkinlik diyagramlarında karar düğümleri, birleştirme çubukları, hata durumunda başa dönüş; durum diyagramlarında kiosk açılışı, sistem testi, servis dışı, bakım ve bekleme (idle) durumları.
- Veri tabanı ve birim testleri
  - ER diyagramlarında yabancı anahtarla normalizasyon (ör. poliklinik anahtarının doktor tablosunda tutulması) anlatıldı.
  - Birim testi örnekleri: veri tabanı bağlantısı, kullanıcı girişi, kayıt ekleme-sorgulama-silme, negatif bakiye kontrolü; barkod girişinde boş değer, 11 hane kontrolü, ondalıklı sayı, karakter, boşluk ve sıfırla başlama durumları. Araçlar: JUnit ve Python unittest; bir grup testi koddan önce yazdı.
- Kapanış tekrarı: kalite ölçütleri, ölçme, maliyet tahmini ve test
  - McCall kalite özellikleri (kullanıcı, çalıştıran ve bakım yapan açısından) ile iç/dış kalite özellikleri ayrımı.
  - Büyüklük ölçütleri (LOC, fonksiyon puanı) ve ölçme eyleminin üç adımı: veri toplama, yorumlama, hesaplama.
  - Maliyet tahmin yöntemleri: bilirkişi, Delphi, analiz, istatistiksel modeller (PNR) ve COCOMO.
  - Kullanıcı testleri: önce alfa, sonra beta testi; sistem testleri (performans, dayanıklılık).
  - Yazılım geliştirme yaşam döngüsü (SDLC) ile yazılım yaşam döngüsü farkı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Risk derecesi olasılık × etki ile belirlenir
  - Yalnız gerçekleşme olasılığını yazmak yeterli değildir; risk gerçekleşirse yıkımının (etkisinin) ne olacağı da tahmin edilmeli ve ikisi çarpılmalıdır.
  - Riskin takibi de bir maliyettir; bu yüzden hangi risklerin izleneceğine bu dereceye göre karar verilir.
  - Risk tablosu proje başında, hiçbir parça gerçekleşmeden, öngörüyle hazırlanır.
- Kullanım senaryosu belgesinin doğru biçimi
  - Belge kişilere göre değil senaryo senaryo yazılır: her senaryonun adı, birincil aktörü, yan aktörleri, adımları ve alternatif adımları ayrı ayrı belirtilir.
  - Alternatif senaryolar ana akışın hangi adımından ayrıldığıyla yazılmalıdır.
- Kavramsal ve tasarım sınıf diyagramı farkı
  - Metot içermeyen diyagram kavramsal (analiz aşaması) sınıf diyagramıdır; metotlar tasarım aşamasında eklenir.
- Diyagram ayrıntıları
  - İlişkilerde çokluk (sayı) her iki uçta yazılmalıdır.
  - Etkinlik diyagramında farklı yerlerde (birimlerde) yürüyen işlemlerin nerede birleştiği gösterilebilir.
  - Çok büyük bir durum diyagramı ikiye ayrılırsa daha sade olur.
- Proje iş-zaman çizelgesi için Excel yerine bir proje yönetimi aracı kullanmak daha iyidir.
- Alfa ve beta testi
  - Alfa testi geliştirici ortamında, kullanıcıya benzer bir grupla yapılır; beta testi en sonda, potansiyel kullanıcılarla yapılır.

## Kısa Tekrar Notları

- Sunum iskeleti: kapsam, kabul/kısıt, Gantt, ekip yapısı, risk tablosu, kullanım senaryoları, izlenebilirlik, sınıf, sıralama, etkinlik ve durum diyagramları, veri tabanı, birim testleri.
- Risk derecesi = olasılık × etki. Takip edilecek riskler bu dereceye göre seçilir.
- Kullanım senaryosu: aktör, ilgililer, ön koşul, son koşul, ana senaryo, alternatif senaryo.
- «include» zorunlu, «extend» koşullu davranış.
- Kavramsal sınıf diyagramı metotsuz, tasarım sınıf diyagramı metotlu.
- Şelale modeli: gereksinimler sabit ve açık, kapsam küçük, teslim tek seferde.
- Adam-gün maliyeti: 70 adam-gün × 1000 TL = 70.000 TL.
- Ölçme eylemi: veri toplama, yorumlama, hesaplama. Büyüklük ölçütleri: LOC ve fonksiyon puanı.
- Maliyet tahmini: bilirkişi, Delphi, analiz, istatistiksel modeller (PNR), COCOMO.
- Kullanıcı testi sırası: alfa, sonra beta.
- SDLC geliştirme aşamalarını, yazılım yaşam döngüsü fikirden kullanım dışı kalmaya kadar bütün ömrü kapsar.

## Detaylı Açıklamalar

- **Risk yönetimi.** Bir sunumda grup risklerin yalnız gerçekleşme olasılığını yazmıştı. Hoca bunun riskin derecesini belirlemeye yetmediğini, riskin gerçekleşmesi durumunda etkisinin de değerlendirilip olasılıkla çarpılması gerektiğini anlattı. Proje planı sırasında, proje başlamadan, ileride çıkabilecek problemler öngörülür; çıkmaması için önlem alınır ve risk izlenir. Riskin takibi de maliyet getirdiği için, derecesi yüksek olanlar seçilerek takip edilir. Bir grup, etkisi büyük olan süre, güvenilirlik ve kullanılabilirlik risklerini izlemeyi, etkisi küçük olan maliyet, personel ve araç risklerini elemeyi önerdi. Bir grubun tablosunda risk faktörleri misyon ve vizyon, organizasyon ve yönetim, müşteri, finansal, kapsam ve teknik olarak sınıflandı; örneğin müşteri gereksinimlerinin değişmesi (yüksek) için aylık toplantılarla değişimin projeye etkisinin konuşulması önlem olarak yazıldı (ekrandan, 00:10:00). Öğrenci, sistemin yalnız bir modülünü kodladıkları için tablonun farazi kaldığını söyleyince hoca risk tablosunun zaten proje başında bütün sistem için hazırlandığını hatırlattı.
- **Kullanım senaryosu belgesi.** Hoca bir grubun belgesinin kişilere göre yazıldığını ve karıştığını belirtti. Doğru biçimde her senaryo ayrı tanımlanır: hangi işlemi gerçekleştirdiği, birincil aktörü, yan aktörleri, adımları ve alternatif adımları. Örneğin bir poliklinik grubunun "Alternatif Senaryolar" slaytında 8a "Randevu zamanı uygun değil" (girilen gün veya saat doludur, sistem başka saat önerir, veznedar müşteriye uygunluğu kontrol eder, uygun saat girilir) ve 8b "Hastanın kaydı yoktur" (sistem kaydı bulamaz, yeni kayıt sekmesi açılır, tam kayıt yapılır) ana senaryonun 8. adımından ayrılan akışlardır (ekrandan, 00:55:00). Kütüphane grubunun "Ögenin Aranması" senaryosunda 3.a alternatifi, aranan kelimeyi içeren öge bulunamazsa tablonun boş dönmesi ve arama çubuğunun temizlenmesidir (ekrandan, 01:40:00).
- **Kullanım durumu diyagramı.** Poliklinik grubunun diyagramında aktörler doktor, kayıt görevlisi, randevu görevlisi, veznedar ve sigorta sunucusudur. "Hasta Bilgileri Sorgulama" «include» ile "Güncelleme / Ekleme"yi içerir; "Rapor / Reçete / Sevk" ona «extend» ile bağlanır; "Hasta Kaydı" «extend» ile "Randevu Ayarlama"ya, "Randevu Ayarlama" «include» ile "Randevu Sorgulama"ya bağlanır; "Ödeme İşlemleri" «include» ile "Ödeme", "Ücreti Hesaplama" ve "Sigorta Durumu"nu içerir (ekrandan, 00:40:00). Hasta sistemle doğrudan etkileşmediği için aktör olarak değil, bilgisi tutulan bir varlık olarak modellenmiştir.
- **Sınıf diyagramları.** Hoca bir grubun diyagramının kavramsal mı tasarım mı olduğunu sordu; metot olmadığı için kavramsal olduğu söylendi. Diğer gruplarda kalıtım (item üst sınıfından kitap, DVD, dergi), arayüz (kiosk arayüzü), bire-çok ilişkiler (bir envanterde çok parça, bir yazarın çok parçası) ve bileşim (belge sınıfı hasta sınıfı olmadan anlamını yitirir) örnekleri yer aldı. Hoca bir diyagramda poliklinik ucunda çokluk yazılmadığını sordu.
- **Sıralama diyagramı.** Kütüphane grubunun "Parça Ödünç Alma" diyagramında kullanıcı kitabı ve kartı okutur; otomasyon sistemi `getParça()`, `kullanıcıAlabilirMi(parça)`, `getKullanıcıdakiToplamParça()` ve `getTarihiGeçmişKontrol()` çağrılarını yapar. «alt» parçasında `[parça_sayısı < getÖdünçAlmaLimiti() AND ödünç_uygun AND !tarihi_geçmiş_parça_var]` koşulu sağlanırsa `yeniÖdünçKaydı()` oluşturulur, `[else]` dalında "Ödünç Alma İşlemi Başarısız" döner (ekrandan, 00:15:00). Başka bir grubun diyagramında kiosk `item.getStok()`, `LocalDate.now()`, `kullanici.getTur()` ve `item.setDeadline()` çağrılarıyla kullanıcı türüne göre teslim tarihi atar (ekrandan, 01:45:00).
- **Etkinlik ve durum diyagramları.** Kitap ödünç alma etkinlik diyagramında parça mevcutsa ödünç alma menüsü seçilir, parça kioska ve kart okutulur; mevcut değilse rezervasyon menüsü seçilip parça kodu girilir. İki dal birleşir; ödünç limiti aşıldıysa ya da teslim tarihi geçmiş parça varsa mesaj gösterilip işlem iptal edilerek başa dönülür, aksi halde işlem onaylanır (ekrandan, 00:20:00). Durum diyagramında kiosk kapalıyken açılır, sistem testi başarısızsa servis dışı ve bakım durumlarına geçer, başarılıysa bekleme (idle) durumuna gelir.
- **Şelale modeli ve maliyet.** Bir grup şelale modelini gereksinimlerin sabit, kapsamın küçük ve teslimin tek seferde olması nedeniyle seçti (ekrandan, 02:15:00). Aynı grup maliyeti 70 adam-gün × 1000 TL = 70.000 TL olarak hesapladı.
- **Kalite ölçütleri.** Hoca McCall kalite özelliklerini kullanıcılar, çalıştıranlar ve bakım yapanlar açısından üçe ayırdıklarını hatırlattı ve bunu iç/dış kalite ayrımıyla birleştirdi. İç kalite özellikleri yazılım üzerinde düzeltme yapanlar için önemlidir (test edilebilirlik, bakım yapılabilirlik, yeniden kullanılabilirlik, taşınabilirlik). Dış kalite özellikleri kullanıcının gördüğü özelliklerdir (doğruluk, hassaslık, dayanıklılık, uyum, bütünlük).
- **Ölçme ve maliyet tahmini.** Büyüklük ölçütleri satır sayısı (LOC) ve fonksiyon puanıdır. Ölçme eylemi veri toplama (benzer yazılımların büyüklüğü, bütçesi, iş gücü ve süresi), yorumlama (ilişkileri belirleme) ve hesaplamadan oluşur (ekrandan, 02:30:00). Maliyet tahmin yöntemleri bilirkişi takdiri, Delphi, analiz ve istatistiksel/analitik modellerdir; istatistiksel modellere ekranda PNR yazılarak Putnam ve Rayleigh adlarıyla anılan model örnek verildi, Boehm'in COCOMO modeli en yaygın olanıdır.
- **Test.** Kullanıcı testleri geliştirme sürecinin sonunda yapılır: önce alfa testi (geliştirici ortamında kullanıcıya benzer bir grupla), en son beta testi (potansiyel kullanıcılarla). Genel amaçlı ürünün beta sürümü kullanıcılara gönderilir ya da açık ortama bırakılır; belirli bir kuruma hazırlanan üründe beta sürümü o kurumun kullanıcılarına açılır ve geliştiriciler bildirilen hataları birebir izler. Performans ve dayanıklılık testleri sistem testleri arasındadır.
- **Yaşam döngüsü.** Yazılım geliştirme yaşam döngüsü (SDLC) analiz, tasarım, gerçekleştirme ve test gibi geliştirme aşamalarını kapsar. Yazılım yaşam döngüsü ise fikrin doğmasından geliştirilmesine, düzenli kullanımına ve kullanım dışı kalmasına kadar geçen bütün süredir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
