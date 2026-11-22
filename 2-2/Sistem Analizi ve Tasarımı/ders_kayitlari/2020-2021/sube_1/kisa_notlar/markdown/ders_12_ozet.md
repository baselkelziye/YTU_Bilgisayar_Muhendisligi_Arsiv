# Ders 12 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumları ve hocanın geri bildirimleri
  - Bu derste öğrenci grupları dönem boyunca hazırladıkları bilgi sistemi projelerini sundu. Her sunum ön inceleme (toplantılar, ekip yapısı, fizibilite, Gantt), sistem analizi, sistem tasarımı, gerçekleştirme ve müşteri değerlendirmesi bölümlerinden oluşuyordu.
  - Hoca sunumları dinlerken hangi diyagramın hangi aşamada çizildiğini sordu, eksik ya da yanlış yerleştirilmiş bölümleri düzeltti. Dersin akademik değeri bu düzeltmelerde ve sunulan diyagram örneklerindedir.
  - Sunulan sistemler: etkinlik bilgi sistemi (mobil), dijital oyun mağazası, takım elbise kiralama sistemi, kafe/restoran yönetim sistemi, film değerlendirme sistemi, sanal market sistemi, özel ders platformu ve freelance hizmet sistemi.
- Diyagramların yaşam döngüsündeki yeri
  - Veri akış diyagramı (VAD) sistem analizi aşamasında çizilir. Tasarım aşamasında yapı diyagramı çizilir.
  - Kullanım durumu (use case) diyagramı analiz aşamasında, kullanıcının ne iş yaptığını doğru anlayıp anlamadığımızı göstermek için çizilir. Tasarımda bunun karşılığı ardışıl (sequence) diyagramdır.
  - Nesneye yönelik projelerde analizde kavramsal sınıf diyagramı, tasarımda yöntemleri ve ilişkileriyle ayrıntılı UML sınıf diyagramı yer alır.
  - Sunumda sıra önce analiz, sonra tasarım, en son kodlamadır. Kodlamaya geçmeden tasarım diyagramları gösterilmelidir.
- Yapısal yaklaşımla çizilmiş örnekler (ekrandan, 00:15:00 ve 00:45:00)
  - Etkinlik bilgi sistemi yapı diyagramı: kök modül altında giriş (login) ve işlem seçimi; işlem seçimi altında etkinlik bulma, yeni etkinlik oluşturma, geçmiş etkinlikleri gösterme. Modüller arasında veri çiftleri (kullanıcı bilgisi, etkinlik listesi, etkinlik takvimi) ve "giriş bilgisi geçerli", "kayıt tamamlandı" gibi işaretler taşınıyor; eşkenar dörtgen seçimi gösteriyor.
  - Kafe yönetim sistemi VAD: özet (bağlam) düzeyinde Müşteri, Sipariş Yönetim Sistemi, Barista/Mutfak ve Teslimat Sistemi; 1. düzeyde 1.0 Sipariş Sistemi, 2.0 Finans Yönetimi, 3.0 Stok Yönetimi, 4.0 Teslimat Sistemi ile Müşteri, Barista/Mutfak ve Ürün Tedarikçisi.
  - Film değerlendirme sistemi 1. düzey VAD'sinde varlıktan varlığa doğrudan veri akışı çizilmemiş, aktarım araya bir işlem konarak yapılmış. Diyagramda daha önce kullanılmış bir varlık tekrar çizilirken kenarına çizgi eklenmiş dörtgen kullanılmış.
- Nesneye yönelik yaklaşımla çizilmiş örnekler
  - Kullanım senaryosu (use case) metinleri: senaryo adı, birincil aktörler, ön koşullar, temel olay akışı ve alternatif senaryolar (sanal market örneği: kayıt olma, ürün ekleme, ürün çıkarma/güncelleme, sipariş verme, siparişi değerlendirme).
  - Ardışıl diyagramlar: elbise ekleme, kiralama ve iade akışları; sipariş-stok-bütçe akışı; veri tabanına sorgu gönderen ortak metot.
  - UML sınıf diyagramları (ekrandan, 01:00:00 ve 01:35:00): `Movie` ve `Kullanici` veri sınıfları, bunları kullanan ekran ve giriş sınıfları; freelance sisteminde `InformationSystem` ana sınıfı, liste sınıfları (`UrunListesi`, `SorunListesi`, `MusteriListesi`) ve `Urun` ile `UrunListesi` arasında bütün-parça (aggregation) ilişkisi.
- Fizibilite ve zamanlama örnekleri
  - Teknik fizibilite: dil, IDE, veri tabanı seçimi ve gerekçesi (Java, Android Studio, Firebase, PostgreSQL, MySQL, SQLite, JavaFX, Java Swing).
  - Ekonomik fizibilite: personel, lisans ve sunucu maliyetleri; gelir modeli (satış ve oyun içi satın alımdan pay).
  - Sosyal ve yasal fizibilite: kullanıcıların sisteme bakışı, kişisel verilerin korunması, lisansların yasal temini.
  - Zaman fizibilitesi: Gantt diyagramı; özel ders platformu örneğinde 45 günlük plan (ekrandan, 01:20:00).
- Müşteri değerlendirmesi bölümü
  - Bu bölüm, sistem analizindeki müşteri istekleri (gereksinim belgesi, SRS) ile gerçekleştirilenleri karşılaştıran bir kontrol listesi olmalıdır: hangi istek yapıldı, hangisi yapılamadı, müşterinin bu konudaki görüşü ne.

## Hocanın Özellikle Vurguladığı Kısımlar

- VAD analizde, yapı diyagramı tasarımda çizilir
  - Bir grup VAD'yi tasarım aşamasına koymuştu. Hoca bunu düzeltti: VAD'ler sistem analizi aşamasının ürünüdür; tasarım aşamasında yapı diyagramı çizilir.
- Use case analizde, sequence tasarımda çizilir
  - Bir grup use case diyagramını tasarım aşamasına, ardışıl diyagramı analize koymuştu. Hoca "ters koymuşsun" dedi. Use case, prototip üretmek için değil, kullanıcının hangi işlemleri yaptığını doğru anladığımızı göstermek için analizde çizilir.
- Müşteri değerlendirmesi karşılaştırmalı olmalı
  - Müşterinin sözlü ya da genel memnuniyet ifadesi yeterli değildir. Bir tarafta gereksinim belgesindeki istekler, diğer tarafta gerçekleşenler yer almalı ve bir kontrol listesi gibi okunmalıdır.
- Fizibilitede tanım değil, yapılan iş anlatılır
  - Fizibilitenin ne olduğunu anlatmak yerine grubun hangi seçimleri yaptığı ve neden yaptığı anlatılmalıdır.
- Analiz önce, tasarım sonra, kod en son
  - Hoca sınıf diyagramını görmeden kod parçasına geçen bir gruptan geri dönüp tasarım diyagramlarını göstermesini istedi.
- Yaklaşım tutarlı olmalı
  - Hoca birçok gruba projeyi nesneye yönelik yaklaşımla mı yaptıklarını sordu; seçilen yaklaşıma uygun diyagram seti beklenir (yapısal: VAD, yapı diyagramı, ERD; nesneye yönelik: use case, kavramsal sınıf, ardışıl ve UML sınıf diyagramı).

## Kısa Tekrar Notları

- VAD: analiz. Yapı diyagramı: tasarım.
- Use case: analiz (kullanıcının işini doğru anladık mı?). Ardışıl diyagram: tasarım.
- Kavramsal sınıf diyagramı analizde, ayrıntılı UML sınıf diyagramı tasarımda.
- VAD'de iki varlık arasında doğrudan veri akışı çizilmez, araya işlem konur.
- Yapı diyagramında modüller arasında veri çiftleri ve işaretler (flag) taşınır; eşkenar dörtgen seçimi gösterir.
- Kullanım senaryosu metni: ad, aktörler, ön koşul, temel akış, alternatif akış.
- Müşteri değerlendirmesi = gereksinimler ile gerçekleşenlerin karşılaştırması.
- Gantt'ta süre = bitiş tarihi − başlangıç tarihi; işler arasında boşluk varsa toplam proje süresi iş sürelerinin toplamından uzun olur.
- Çoka çok ilişkiler veri tabanında ayrı ilişki tablosuyla gerçeklenir; ilişkili tablolar yabancı anahtarla bağlanır.

## Detaylı Açıklamalar

- Etkinlik bilgi sistemi (mobil uygulama)
  - Müşteri istekleri (ekrandan, 00:10:00): kullanıcıların etraflarındaki etkinlikleri ayrıntılarıyla (kapasite, isim, yer, zaman) ekleyebilmesi, bilgilerin kullanıcılar tarafından girilmesi, sade bir arayüz. İkinci toplantıda fizibilite sonuçları müşteriyle paylaşılmış, analist Java dilini önermiş ve müşteri onaylamış.
  - Modüller: kullanıcı işlemleri (kayıt, giriş, üyelik bilgileri), etkinlik listeleme (şehir bazında, ana ekran) ve etkinlik ekleme. Üyelikte istenen bilgiler isim, soyisim, yaş, şehir ve e-posta; etkinlik oluşturmada ad, tarih, zaman, kapasite ve tanım.
  - VAD: taslak (bağlam), birinci düzey (üye olma, etkinlik görüntüleme, katılma, yeni etkinlik oluşturma, kendi etkinliklerini görme, katılmaktan vazgeçme) ve ikinci düzey (giriş kontrolü, etkinlik arama ve listeleme, daha önce katılmadıysa katılma).
  - Yapı diyagramı (ekrandan, 00:15:00): kök `Event Information System`; altında `Login` (`Register`, `Current User take Information` → `Check Database`) ve `Select Operation` (`Finding an Event` → `Join the Event` → `Save User's information` / `Cancel Participating in the Event`; `Create New Event` → `Save the Event's information` / `Cancel creating new Event`; `Show past Events attended` → `Events List`).
  - ER diyagramı: kullanıcı varlığı (isim, şifre, e-posta, kullanıcı ID) ve etkinlik varlığı (başlık, açıklama, tarih, kapasite, etkinlik ID, şehir); özellikler elipsle çizilmiş. <!-- BELİRSİZ: altyazıda "depth" geçiyor, büyük olasılıkla "date" (tarih) -->
  - Teknik fizibilite: Firebase'in iki modülü kullanılmış. Authentication e-posta ve şifreyi doğrulayarak giriş sağlar, telefon numarası ve popüler hesaplarla girişi de destekler. Cloud Firestore, iOS, Android ve web uygulamalarının yerel SDK'larla doğrudan eriştiği, bulutta barındırılan bir NoSQL veri tabanıdır; belgeler içinde alt koleksiyonlarla hiyerarşik veri tutar (ekrandan, 00:20:00). Uygulama Android Studio'da Java ile yazılmış; Kotlin alternatifi yerine Java, ekibin deneyimi ve kütüphane zenginliği nedeniyle seçilmiş.
- Dijital oyun mağazası
  - Ekonomik fizibilitede gelir modeli: satılan her oyundan %20, oyun içi satın alımlardan (in-game transaction) %30 pay; maaş tablosunda Q çeyrek yıl (3 ay) anlamında.
  - Bilgi toplama aşamasında benzer platformlar incelenmiş, gereksinimler önceliklendirilmiş (önce hesap bilgileri, en son arkadaşlık sistemi) ve alternatif çözümler karşılaştırılmış.
  - Hoca use case diyagramının yerini sordu; grup "tasarım" dedi. Doğrusu analizdir; ardışıl diyagram tasarıma aittir.
- Takım elbise kiralama sistemi
  - Sistem tanımı: elbiseleri görüntüleme, zamana göre ücretlendirme, gecikmede ve hasarda ücret artırma ve raporlama modülleri.
  - Sosyal fizibilite (ekrandan, 00:35:00): insanların genelinin yılda 3-4 kez giyeceği için takım elbise almaya sıcak bakmadığı, ama özel günlerde giymek istediği görülmüş; bu yüzden kiralama bir ihtiyaç olarak değerlendirilmiş.
  - Ardışıl diyagramlar: elbise ekleme (elbise nesnesi oluşturup elbise sınıfındaki statik listeye ekleme), kiralama (elbise ve müşteri listelerinden seçim, kiralanmış nesnesi oluşturma, elbiseyi listeden çıkarma, kiralanmışlar listesine ekleme, tutar metodunu çağırma), iade (kiralanmış kaydı seçme, elbiseyi listeye geri ekleme, raporlama).
- Kafe/restoran yönetim sistemi
  - Proje nesneye yönelik tasarlanmış, ama başlangıçta ek çalışma olarak klasik VAD de çizilmiş (ekrandan, 00:45:00).
  - Kullanım senaryosu diyagramında aktörler müşteri, çalışan ve tedarikçi; "sipariş ver" kullanım durumu "menü seç" ve "ödeme"yi içeriyor (include).
  - UML sınıfları: worker, order, stock item, budget item ve veritabanı bağlantı sınıfı; sınıflar arasında kalıtım yok, veriler bağlantı sınıfındaki get metotlarıyla alınıyor.
  - Ardışıl diyagram: müşteri çalışana sipariş verir; çalışan stok durumuna bakar; stokta varsa malzeme alınır, stok kendini günceller ve durumu bildirir; yoksa müşteriye "stokta kalmadı" bildirimi gider; fatura tutarı bütçeye eklenir; bütçe ay sonunda maaşları öder.
- Film değerlendirme sistemi
  - Modüller: kayıt ve giriş, profil güncelleme, beğeni, izleme listesi, görüntüleme. Fizibilite altı başlıkta (yazılım, donanım, ekonomik, zaman, sosyal, yasal) yapılmış; zaman planı Gantt ve Trello panosuyla izlenmiş.
  - Sınıf yapısı (ekrandan, 01:00:00): toplam 12 sınıf; 8'i sayfa, 1'i veri tabanı bağlantısı ve metotları, 2'si veri taşıyan `Kullanici` ve `Movie`, 1'i programa giriş sınıfı. Kullanıcı giriş yapınca bir `Kullanici` örneği oluşturuluyor ve program boyunca veri tabanı iletişimi bu örnek üzerinden yürüyor; film ayrıntı sayfasına geçişte de bir `Movie` örneği aktarılıyor.
  - Veri tabanına sorgu metni parametre olarak verilip sonuç `ResultSet` olarak alınıyor.
- Sanal market sistemi
  - İki kullanıcı grubu: müşteri (kayıt, giriş, kategoriye göre filtreleme, sepet, sipariş, puanlama, ürün önerisi) ve satıcı/admin (ürün ekleme, güncelleme, silme). Teknik fizibilite: Java, nesneye yönelik yaklaşım, Java Swing arayüz, MySQL veri tabanı; süre 40 gün.
  - Kullanım senaryoları temel ve alternatif akışlarıyla yazılmış (ayrıntı genişletilmiş notta). Kavramsal sınıf diyagramı ve UML sınıf diyagramı ayrı ayrı gösterilmiş.
- Özel ders platformu
  - Öğrenci, öğretmen ve admin rolleri; ders satın alma, öğretmeni derecelendirme, rapor. Teknik fizibilite: Java, JavaFX, IntelliJ, SQLite; çevrim içi sürüm için PostgreSQL düşünülmüş. Açık kaynak yazılım lisans maliyetini düşürmüş.
  - Veri tabanında ilişkili tablolar yabancı anahtarla bağlanmış; öğretmen oylaması ve ders kayıtları gibi çoka çok ilişkiler için ayrı tablolar oluşturulmuş; birincil anahtarlar koddaki nesnelere de alan olarak eklenmiş.
  - Gantt (ekrandan, 01:20:00): dokuz iş, 30.03.2021-14.05.2021, toplam 45 gün; en uzun iş 12 günlük gerçekleştirme.
- Freelance hizmet sistemi
  - Üç kullanıcı tipi: müşteri, satıcı (freelancer) ve sorunları çözen moderatör (ekrandan, 01:30:00). Program konsol tabanlı; açılışta veriler dosyadan okunup bellekteki listelerde tutuluyor.
  - Sınıf diyagramı (ekrandan, 01:35:00): `InformationSystem` ürün, müşteri, freelancer, sipariş ve sorun listelerini tutar; `Urun` sınıfında ID, ad, fiyat, açıklama, süre, puan, yorum sayısı ve yeni puanı önceki puanların ortalamasıyla birleştiren `Puanla` metodu var.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
