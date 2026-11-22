# Ders 9 Çalışma Özeti

## Genel Konular

- Veri varlıkları ve nesneler (tekrar) (ekrandan, 00:10:00)
  - Ders, Satzinger, Jackson ve Burd'ün "Systems Analysis and Design in a Changing World" kitabının slaytlarıyla veri tabanı tasarımı tekrarıyla başladı.
  - Geleneksel yaklaşımda hangi verinin tutulacağı ve veri parçaları arasındaki ilişki varlık ilişki diyagramıyla (ERD) modellenir. Model analizde başlar, tasarımda ayrıntılanır ve son halini alır.
  - Geleneksel yaklaşımda veri varlıkları işlemlerden ayrıdır: işlem 1, 2, 3 girdileri alıp çıktı üretir, sürekli veriyi veri tabanındaki varlıktan alır ve geri yazar.
  - Nesneye yönelik yaklaşımda nesne, kendi verisini ve bu veriyi işleyen metotları tek birimde toplar. Metotlar gelen mesajla tetiklenir, sonucunda yine bir mesaj gönderilir.
  - ERD'de varlıkların yalnız özellikleri tanımlanır; nesnelerde önce sınıf tanımlanır, sonra özellikler ve davranışlar (metotlar) belirtilir.
- Basit ER diyagramı ve kardinalite (ekrandan, 00:15:00)
  - Müşteri ile sipariş: bir müşteri sıfır ya da çok sipariş verebilir; bir sipariş tam olarak bir müşteriye aittir.
  - Bu kitapta kullanılan gösterim hem sayısal ilişkiyi (kardinalite) hem zorunlu/seçimlik durumu gösterdiği için tercih edilmiştir.
  - Sembollerin anlamı: çatal (kaz ayağı) "çok", çizgi "bir", daire "sıfır" demektir. Sıfırdan başlayan ilişki seçimlik (optional), birden başlayan ilişki zorunludur (mandatory).
  - Chen gösteriminde iki varlık arasındaki ilişki bir eşkenar dörtgenle (ilişki fiili yazılarak) gösterilir; özellikler varlığa bağlı elipslerle çizilir. Gerçek uygulamalarda özellik çok olduğu için elipsle göstermek pratik değildir.
- Özellikleri gösterilmiş genişletilmiş ERD (ekrandan, 00:20:00)
  - Customer (Cust number*, Name, Bill address, Home phone, Office phone) 1 — 0..çok Order (Order ID*, Order date, Amount).
  - Order 1 — 1..çok Order Item (Item ID*, Quantity, Price). Bir siparişin en az bir kalemi vardır; her kalem tam olarak bir siparişe bağlıdır.
  - Yıldız (*) tanımlayıcıyı, yani anahtarı gösterir.
- Birincil anahtar (primary key)
  - Varlıktaki (ileride tablodaki) bir satıra birincil anahtar üzerinden erişilir ve tablo buna göre indekslenir.
  - Birincil anahtar biricik (unique) ve boş olmayan (not null) olmalıdır.
  - Anahtar, birden fazla alanın birleşimiyle de biricik yapılabilir.
  - Anahtar olmaya uygun birden fazla alan olabilir (öğrenci numarası, kimlik numarası). Hangisinin birincil anahtar olacağına analizde karar verilir: veri tipi, erişim hızı ve kullanıcıların hangisini daha kolay kullandığı belirleyicidir.
- Müşteri-sipariş örnek verisi
  - Bir müşteri iki sipariş vermiş (çok), bir müşteri üye olup hiç sipariş vermemiş (sıfır), bir müşteri tek siparişte üç ürün almış. Bu, ERD'deki kardinalitelerin gerçek veride nasıl göründüğünü gösterir.
- Sınıf diyagramı
  - Sınıflar yalnız veri varlıklarını değil nesneleri gösterir; genelleştirme/özelleştirme (kalıtım) ve bütün-parça (aggregation) hiyerarşilerini de içerir.
  - Motorlu araç hiyerarşisi (ekrandan, 00:30:00): MotorVehicle üst sınıfının alt sınıfları Truck, Car, Tractor; Car'ın alt sınıfları SportsCar, Sedan, SportUtility. Üst sınıfın özellikleri alt sınıflara otomatik geçer.
  - Bütün-parça ilişkisi: bilgisayar sınıfına işlemci, ana bellek, klavye, disk, monitör gibi parçalar eşkenar dörtgen uçlu çizgiyle bağlanır. <!-- BELİRSİZ: bu slaytın karesi yok, parça listesi altyazıdan alındı -->
  - Sınıf sembolü üç bölmelidir: sınıf adı, özellikler, metotlar.
- Banka hesap sistemi sınıf diyagramı (ekrandan, 00:35:00)
  - Customer (name, address, phone) 1 — 0..* Account (accountNumber, balance, dateOpened; makeDeposit, makeWithdrawal).
  - Account'tan kalıtımla SavingsAccount (interestRate; calculateInterest) ve CheckingAccount (checkStyle, minimumBalance).
- Ders kaydı sınıf diyagramı ve ilişki sınıfı (ekrandan, 00:40:00)
  - Course (courseNumber, title, creditHours; addCourse) 1 — 0..* CourseSection (sectionNumber, startTime, roomNumber; openSection, closeSection).
  - CourseSection 0..* — 0..* Student (studentID, name, major; admitStudent, recordDegree).
  - Bu çoka çok ilişkiye kesikli çizgiyle CourseEnrollment ilişki sınıfı (grade; postGrade) bağlanır.
- Çoka çok ilişkinin veri tabanında gerçeklenmesi
  - Çoka çok ilişki veri tabanında doğrudan gösterilemez; araya bir ilişki tablosu (relation table) konur.
  - Ders kayıt tablosunun birincil anahtarı, şube numarasını içeren ders/şube anahtarı ile öğrenci numarasının birleşimidir; notu (grade) bu tabloda tutulur.
- Sistem tasarımı (ekrandan, 01:10:00)
  - Tanım: belirlenmiş gereksinimlerin ana sistem içinde işlevsel bir öğe haline getirilmesi, yani yazılım şekline dönüştürülmesidir.
  - İki aşamada yapılır: ön (genel) tasarım ve ayrıntılı tasarım.
  - Ön tasarım: uygulamanın alt modülleri, modüllerin ara birimleri ve kısıtları, sistem altyapısı ve mimarisi belirlenir. Analizde çıkan sistem gereksinimleri girdi olarak alınır.
  - Ön tasarım adımları: donanım envanteri, iş yükü tahmini, yazılım (paket program) değerlendirmesi, satıcı firma seçimi (donanım/yazılım desteği, kurulum, eğitim, bakım), elde etme türü (satın alma, kiralama, leasing), sistem mimarisi.
  - Ayrıntılı tasarım (ekrandan, 01:15:00): ön tasarımdaki modüller alt modüllere ayrılır; dosya/tablolar, ekran görüntüleri ve rapor biçimleri tasarlanır, programlar için ayrıntılı planlar hazırlanır.
- Yapı diyagramı (structure chart) (ekrandan, 01:20:00)
  - Programın modüllerini hiyerarşik olarak gösterir. Üst modül alt modülleri çağırır; aynı düzeydeki modüller soldan sağa çalışma sırasıyla dizilir.
  - Ana modülün altındaki yarım daire ok, alt modüllerin döngü içinde tekrarlandığını gösterir.
  - İçi boş daireli küçük ok veri (argüman ya da dönen değer), içi dolu daireli ok kontrol bilgisidir (evet/hayır gibi lojik değer).
  - Eşkenar dörtgen, bir modülün bir koşula göre çalışıp çalışmayacağını gösterir.
  - Yapı diyagramı veri akış diyagramından çıkarılabilir, ama VAD'daki her işlem modül olmak zorunda değildir; modül yapısına tasarımcı karar verir.
  - Modüller numaralanarak da hiyerarşi gösterilebilir (2.1, 2.2, 2.3 gibi).
- Ayrıntılı tasarım başlıkları
  - Veri tabanı, çıktı, girdi, program ve ara birim tasarımı.
  - Çıktı tasarımı: amaca hizmet eden, kullanıcıya göre anlamlı, doğru zaman aralığında (günlük, aylık) ve doğru ortamda (grafik ya da liste) verilen çıktılar.
  - Girdi tasarımı: kolay kullanım, uyum, doğruluk; GIGO (garbage in, garbage out) ilkesi.
  - Girdi kodlaması (ekrandan, 01:25:00): kısa olmalı, kolay değişmemeli ve önceden kararlaştırılmalı, tekil olmalı, karıştırılabilecek sembollerden kaçınılmalı, kısaltmalar anlamlı olmalı, araya eleman eklemeye izin vermeli.
  - Veri tabanı tasarımı: kullanışlı veri, veri bütünlüğü, etkin güncelleme.
  - Ara birim tasarımı: etkinlik, verimlilik, kullanıcı görüşü, ergonomi (göz yormayan renkler, sayfalar arasında tutarlı tasarım).
- Kodlama ve test (ekrandan, 01:30:00)
  - Kodlama: spesifikasyonlara uygun olarak yazılımın seçilen programlama diline çevrilmesi.
  - Akış: sistem gereksinimleri, kodlama (çıktı: programlar), denetim (uygun değilse revizyonla kodlamaya dönülür), test (modüler, genel, onaylama; çıktı: test planı ve işlemleri), sistemin kullanıma hazır olması.
  - Programlama dili seçimi uygulama alanına, algoritmaya, veri yapısına, kullanım ortamına ve geliştiricilerin bilgisine bağlıdır.
  - İyi kod: yeterli ama aşırı olmayan açıklama satırları, her modülün adı/işlevi/amacı, okunabilir yazım düzeni, kurum standardına uygun anlamlı adlar.
- Yazılım kalitesi ve test
  - Kaliteli yazılım, önceden belirlenmiş işlevsel gereksinimlere ve yazılım geliştirme standartlarına tamamen uyan yazılımdır.
  - Kalite faktörleri: doğruluk, güvenilirlik, verimlilik, güvenlik, kullanışlılık, hata bulma kolaylığı, esneklik, test etme kolaylığı, taşınabilirlik, tekrar kullanılabilirlik, bağlanabilirlik (interoperability).
  - Test basamakları (ekrandan, 01:35:00): ünite (birim) testi, bütünlük testi, sistem testi, onaylama testi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri varlığı ile nesne farkı
  - Hoca bu farkın akılda kalması gerektiği için konuyu yeniden ele aldığını söyledi. Varlıkta yalnız özellik vardır; nesnede veri, metot ve mesaj birlikte bulunur.
- ERD'de iki yönlü okuma
  - İlişki iki yönden okunur: müşteriden siparişe "sıfır ya da çok", siparişten müşteriye "bir ve yalnız bir".
  - Sayısal kardinalite (bire bir, bire çok, çoka çok) ile zorunluluk/seçimlik ayrı bilgilerdir; birden başlayan uç zorunlu, sıfırdan başlayan uç seçimliktir.
- Birincil anahtarın özellikleri
  - Biricik ve boş olmayan alan seçilmelidir. Birden fazla aday varsa karar analizde verilir.
- Çoka çok ilişki için ilişki tablosu
  - Veri tabanında doğrudan gösterilemez; ara tablo eklenir ve ilişkiye ait özellik (ör. not) bu tabloda tutulur.
- Girdi tasarımında sorumluluk
  - Kullanıcı yanlış girdi diye tasarımcı kendini aklayamaz. Ekran iyi tasarlanırsa kullanıcı hatalı bilgi girmez; bu yüzden giriş ekranları web tasarımcılarıyla birlikte hazırlanır.
- Yapı diyagramında ayrıntı
  - Her ayrıntıyı göstermek diyagramı karıştırır; temel veri ve kontrol akışlarını göstermek yeterlidir.

## Kısa Tekrar Notları

- ERD: varlık + özellik + ilişki; sınıf diyagramı: sınıf + özellik + metot + kalıtım + bütün-parça.
- Kaz ayağı = çok, çizgi = bir, daire = sıfır. Sıfır = seçimlik, bir = zorunlu.
- Chen gösterimi: ilişki eşkenar dörtgen, özellik elips.
- Sınıf diyagramında çokluk `1`, `0..*` gibi yazılır.
- Birincil anahtar: biricik ve boş olmayan; birleşik anahtar mümkündür.
- Çoka çok ilişki: ara ilişki tablosu (ör. CourseEnrollment, grade).
- Sistem tasarımı: ön tasarım (modüller, mimari, envanter, iş yükü, yazılım ve satıcı seçimi) + ayrıntılı tasarım (veri tabanı, çıktı, girdi, program, ara birim).
- Yapı diyagramı: yarım daire ok döngü, boş daire veri, dolu daire kontrol, eşkenar dörtgen koşul.
- GIGO: yanlış girdi yanlış çıktı üretir.
- Kodlama akışı: kodlama, denetim (revizyon döngüsü), test, kullanıma hazır sistem.
- Test basamakları: birim, bütünlük, sistem, onaylama.

## Detaylı Açıklamalar

Dersin ilk yarısı veri tabanı tasarımının tekrarıdır. Geleneksel yaklaşımda veri ve işlem birbirinden ayrıdır: işlemler sırayla tanımlanır ve sürekli saklanan veriyi veri tabanındaki varlıktan okuyup geri yazar. Bu verinin yapısı varlık ilişki diyagramıyla modellenir. Nesneye yönelik yaklaşımda ise veri ve onu işleyen metotlar bir nesnede birleşir; nesne hangi sınıfa aittir, hangi özellikleri ve davranışları vardır, hangi mesajlarla tetiklenir, bunlar sınıf diyagramında görülür. Derste her iki yaklaşım başlangıç düzeyinde verilir ve dönem projelerinde hangisi istenirse o kullanılabilir.

ER diyagramında müşteri ile sipariş örneği iki yönden okunur. Müşteri ucunda tek çizgi, sipariş ucunda daire ve kaz ayağı vardır (ekrandan, 00:15:00). Müşteri siteye kayıt olmuş ama henüz sipariş vermemiş olabilir, bu yüzden sipariş ucu "sıfır ya da çok"tur. Bir siparişin ise iki sahibi olamaz ve sahipsiz de olamaz, bu yüzden müşteri ucu "bir ve yalnız bir"dir. Genişletilmiş diyagramda (ekrandan, 00:20:00) siparişle sipariş kalemi arasında "bir — bir ya da çok" ilişkisi vardır: kasadan geçmiş bir alışverişin en az bir kalemi olur. Hoca bunu market fişindeki ürün satırlarına benzetti; her kalemin ürün numarası, miktarı ve fiyatı vardır.

Birincil anahtar, varlığın bir satırına erişmeyi sağlayan alandır. Biricik ve boş olmayan olmalıdır. Bazen tek bir alan yetmez, birkaç alanın birleşimi anahtar olur. Öğrenci bilgi sisteminde hem öğrenci numarası hem kimlik numarası (yabancı öğrencide pasaport numarası) anahtar olmaya uygundur; hangisinin birincil anahtar olacağına analizde, veri tipi, erişim hızı ve kullanım kolaylığına bakılarak karar verilir. Öğrenciler için öğrenci numarası daha kolaydır.

> **Ek bilgi (derste anlatılmadı):** Anahtar olabilecek alanların her birine aday anahtar (candidate key) denir. Bunlardan seçilen birincil anahtar, seçilmeyenler alternatif (ikincil) anahtar olur. Hocanın "anahtar özelliğini taşıyacak birden fazla kolon" dediği durum budur.

Sınıf diyagramında banka örneği (ekrandan, 00:35:00) bir tasarım sınıf diyagramıdır, çünkü metotlar da gösterilmiştir. Account soyut üst sınıftır; SavingsAccount ve CheckingAccount onun accountNumber, balance, dateOpened özelliklerini ve makeDeposit, makeWithdrawal metotlarını kalıtımla alır, kendi özelliklerini (interestRate, calculateInterest; checkStyle, minimumBalance) ekler. Ders kaydı örneğinde (ekrandan, 00:40:00) CourseSection ile Student arasındaki ilişki her iki uçta `0..*`dır: bir şubeyi hiç öğrenci almamış olabilir (şube kapatılır) ya da çok öğrenci almış olabilir (ek şube açılabilir); bir öğrenci hiç ders seçmemiş ya da çok ders seçmiş olabilir. Bu çoka çok ilişki veri tabanında doğrudan tutulamaz; araya ders kayıt tablosu konur. Bu tablonun anahtarı şube ve öğrenci anahtarlarının birleşimidir, öğretim üyesinin gireceği not da bu tablodadır.

İkinci yarıda sistem tasarımı bütünüyle gözden geçirildi. Ön tasarımda uygulama alt modüllere ayrılır, modüllerin ara birimleri, kısıtları ve sistem mimarisi belirlenir; envanter, iş yükü, yazılım paketi değerlendirmesi, satıcı ve elde etme türü kararları da bu aşamadadır. Modül yapısı yapı diyagramıyla gösterilir. Bordro programı örneğinde (ekrandan, 01:20:00) ana modül "Payroll program" bir döngüyle her çalışan için "Enter time cards", "Calculate amounts" ve "Output payroll" modüllerini soldan sağa çağırır; bunların altında zaman kartı girme, çalışan kaydı okuma, zaman kartı doğrulama, ücret oranlarını alma, ücret hesaplama (taban, fazla mesai, vergi, diğer kesintiler), çalışan kaydını güncelleme, bordro işlemlerini yazma ve genel defteri güncelleme gibi alt modüller vardır. Okların yanındaki boş daireli küçük oklar modüller arasında giden argümanları ve dönen değerleri gösterir. Sipariş örneğinde bir modülün çalışıp çalışmaması bir koşula bağlıdır ve bu eşkenar dörtgenle gösterilir; hoca slaytta eşkenar dörtgenin yanlış yerde durduğunu, iki modül arasında olması gerektiğini söyledi. <!-- BELİRSİZ: sipariş yapı diyagramı ve numaralı envanter yapı diyagramı slaytlarının karesi yok -->

Ayrıntılı tasarımda veri tabanı, çıktı, girdi, program ve ara birim tasarlanır. Girdi kodlamasında eğitim derecesi gibi değerler yazıyla değil 1, 2, 3, 4 gibi kodlarla girilir; böylece sınıflama ve işlem hızlanır. Kodlama kuralları (ekrandan, 01:25:00) kısa, değişmeyen, tekil, karışmayan, anlamlı ve genişletilebilir kod ister. Ardından kodlama aşaması gelir: kod denetlenir, uygun değilse revizyonla düzeltilir, sonra test edilir (ekrandan, 01:30:00). Bu aşamanın iki çıktısı programlar ile test planı ve işlemleridir. Son olarak yazılım kalitesinin faktörleri ve test basamakları sayıldı: birim testi kodlamanın hemen arkasından yapılır, bütünlük testi modüllerin birlikte doğru çalışıp çalışmadığını, sistem testi sistemin diğer elemanlarıyla uyumunu, onaylama testi de kullanıcının belirttiği gereksinimlere uygunluğu sınar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
