# Ders 8 Çalışma Özeti

## Genel Konular

- Sistem tasarımının tanımı ve aşamaları
  - Sistem tasarımı, analizde belirlenen gereksinimlerin sistem içinde işlevsel öğeler hâline getirilmesi, başka bir deyişle yazılımı hazırlanacak biçime dönüştürülmesidir.
  - İki aşamada yapılır: ön tasarım (genel tasarım) ve ayrıntılı tasarım.
  - Analiz aşamasında hem geleneksel yaklaşımla veri akış diyagramları hem de nesneye yönelik yaklaşımla kullanım durumu (use case) diyagramları ve veri analizi yapılmıştı; tasarım bunların üzerine kurulur.
- Ön tasarım (genel tasarım)
  - Sistemin belirlenen amaç ve hedeflere nasıl ulaştırılacağına ilişkin tanımlar geliştirilir: işlevler tanımlanır, gereksinimlere karşılık gelen modüller belirlenir, yazılım bağımsız öğelere ayrılır, veri yapıları oluşturulur, modül ara birimleri kurulur ve kısıtlar belirlenir.
  - Sonuçlar bir rapor hâlinde düzenlenir; rapor incelenir, kabul edilir ya da gerekirse yeniden düzenlenir.
  - Genel tasarım yalnız yazılımı değil bütün sistemi kapsar: sistemin altyapısının (donanım, ağ, platform) belirlenmesi ve sistem mimarisinin oluşturulması. Analiz sonuçları (gereksinimler) bu çalışmanın girdisidir.
- Altyapıyı belirleme süreci (ekrandan, 00:10:00)
  - Amaç, işletmede var olan donanım, yazılım ve ağ yapısından başlayarak önerilen sistem çözümüne uygun altyapıyı ortaya koymaktır.
  - Adımlar sırasıyla: var olan bilgisayar donanım ve yazılım envanterini belirleme; iş yüklerinin tahmini; donanımı değerlendirme ve yazılımı değerlendirme (paralel); satıcı firmayı belirleme; finansal satın alım türünü belirleme.
- Envanter belirleme
  - Teçhizatın modeli ve üreticisi; durumu (kullanılıyor mu, bakım gerekiyor mu, çalışır durumda mı); yaşı ve planlanan kullanım süresi; işletme içindeki fiziksel yeri; sorumlu çalışan ya da bölüm; finansal durumu (işletmenin malı mı, leasing ile mi alındı, kiralık mı).
- İş yükü tahmini
  - Sistem analisti var olan ve planlanan iş yüklerini hesaplayarak donanım altyapısının kapasitesinin bu iş yükleri için yeterli olup olmadığını belirler.
  - Örnek: haftada, ayda, yılda ne kadar kayıt işlenip saklanacağına göre disk kapasitesi; ağda ne kadar iletim gerekeceği.
  - Hesapların doğru yapılması, her yeni sistemle donanımın gereksiz yere büyümesini ve karmaşıklaşmasını önler (slayt küçük resminden, ekrandan, 00:15:00).
- Yazılım değerlendirme: paket yazılım alım kriterleri (ekrandan, 00:15:00)
  - Performans etkinliği: ihtiyaç duyulan tüm işleri yerine getirme, işleri istenildiği şekilde yapma, iyi tasarlanmış ekran çıktıları, yeterli kapasite.
  - Performans verimliliği: hızlı cevap zamanı, verimli giriş, verimli çıkış, verimli veri saklama, verimli yedekleme.
  - Kullanım kolaylığı: iyi tasarlanmış kullanıcı ara birimi, yardım menüleri, esnek ara birim, yeterli geri besleme, hata düzeltme.
  - Esneklik: girdi seçeneği, çıktı seçeneği, diğer yazılımlarla birlikte kullanılma.
  - Dokümantasyon kalitesi: iyi organizasyon, yeterli çevrim içi kaynak, web sitesinde sık sorulan sorular (FAQ).
  - Üretici desteği: teknik destek, ürün güncellemesinin web sitesi üzerinden yapılabilmesi.
  - Örnekler: veri tabanı yönetim sistemi, proje yönetim programı ya da anahtar teslim bir uygulamanın bir parçası için alınan hazır insan kaynakları paketi. Hangi işin hazır paketle yapılacağına, hangisinin yeniden geliştirileceğine bu niteliklere bakılarak karar verilir.
- Satıcı firmayı belirleme
  - En önemli etken satıcının kullanıcıya sunduğu hizmetlerdir; dört grupta değerlendirilir: donanım desteği, yazılım desteği, kuruluş ve eğitim, bakım.
  - Donanım desteği: ürün kalitesi ve garanti. Yazılım desteği: toplam yazılım ihtiyacını karşılama, özel programlama gereksinimi, garanti. Kuruluş ve eğitim: zaman programına uygunluk, eğitim verilip verilmediği, müşteri hizmetleri. Bakım: rutin bakım ve acil durumda cevap verme süresi.
  - Örnek: aynı veri tabanı yönetim sisteminin iki bayisi varsa hangisinden alınacağına bu ölçütlerle karar verilir.
- Finansal satın alma türü: satın alma, leasing, kiralama (ekrandan, 00:25:00)
  - Satın alma, avantajlar: uzun dönemde leasing ve kiralamadan ucuz; sistemin değiştirilebilmesi; vergi indirimi; tam kontrol. Dezavantajlar: ilk ödemenin yüksek olması; eskime riski; seçimin yanlış yapılması durumunda yatırımın batma riski; tam sorumluluk.
  - Leasing, avantajlar: sermayenin bağlanmaması; finansmana ihtiyaç olmaması; kira bedelinden düşük olması. Dezavantajlar: sözleşme bitince işletmenin sisteme sahip olamaması; ödeme gecikirse yüksek faiz; satın almadan daha pahalı olması.
  - Kiralama, avantajlar: sermayenin bağlanmaması; finansmana ihtiyaç duyulmaması; sistemin kolayca değiştirilmesi; bakım ve garantinin genelde fiyata dahil olması. Dezavantajlar: işletmenin sistemin gerçek sahibi olmaması; satıcı riski üstlendiği için kira bedelinin çok yüksek olması.
- Sistem mimarisi (mimari tasarım)
  - Programın ana yapısal öğeleri arasındaki ilişkiler belirlenir. Amaç modüler bölümlere ayrılmış bir program yapısı geliştirmek ve modüller arasındaki ilişkilerin denetimini göstermektir.
  - Hangi modüller olacağı, modüller arası ilişkiler ve tanımları, modülerlik, yeniden kullanılabilirlik, modüller arası veri alışverişi ve ortak veri kullanımı bu aşamada ele alınır.
  - Verinin program içinde akışını sağlayacak ara birimler tanımlanır. Klasik yaklaşımda sistem mimarisi yapı diyagramı (structure chart) ile gösterilir.
- Yapı diyagramı (structure chart) sembolleri
  - Modül: dikdörtgen. Üstteki modül, altındaki alt modülleri çağırır; her alt modül kendi alt modüllerine ayrılabilir.
  - Ucu içi boş yuvarlak olan küçük ok: modüller arasında veri (sayısal ya da karakter bilgi) aktarımı.
  - Ucu içi dolu yuvarlak olan küçük ok: kontrol akışı, yani lojik bilgi (evetse çalış, hayırsa çalışma gibi bir karar bilgisi).
  - Eşkenar dörtgen: seçim (if); iki alt modülden yalnız biri çalışır.
  - Alt modülleri kapsayan yarım daire biçiminde ok: tekrar (döngü); kapsanan modüller her kayıt için yeniden çalışır.
  - Modüller veri akış diyagramındaki gibi numaralandırılabilir (1.0; 2.0, 2.1...; 3.0, 3.1...).
- Yapı diyagramı örnekleri (ekrandan, 00:30:00; 00:35:00; 00:45:00)
  - Ücret bordrosu programı: zaman kartlarını gir, ödenecek miktarları hesapla, bordro çıktısını al olmak üzere üç ana modül; her çalışan için tekrar eden döngü; modüller arası yalnız veri akışı.
  - Yeni sipariş oluşturma: müşteri bilgisini kaydet (var olan müşteri mi, yeni müşteri mi seçimi), siparişi kaydet, sipariş işlemini yürüt, onay üret; her sipariş kalemi için tekrar eden işlem.
  - Envanter güncelleme ve raporlama: 1.0 altında 2.0 Envanter Güncelleme (2.1 İşlem Girişi, 2.2 İşlem Doğrulama, 2.3 İşlem Düzeltme, 2.4 Dosya Güncelleme) ve 3.0 Raporlama (3.1 Günlük Raporlama, 3.2 Özet Raporlama).
- Ayrıntılı tasarım
  - Ön tasarımda oluşturulan modüller alt modüllere ayrılır ve ayrıntılı tanımlanır; dosyalar ya da tablolar, ekran görüntüleri ve rapor biçimleri tasarlanır, programlar için kodlamaya kadar inen ayrıntılı planlar hazırlanır (ekrandan, 00:20:00).
  - Kapsamı: çıktı tasarımı, girdi tasarımı, veri tabanı tasarımı, program tasarımı ve ara birim tasarımı.
- Çıktı tasarımı (ekrandan, 01:25:00; 01:30:00)
  - Çıktı, bilgi sisteminin kullanıcılara verdiği bilgidir; analistler en faydalı çıktıyı elde etmek için kullanıcılarla etkileşimli çalışır.
  - Gerekenler: belirlenen amaca hizmet etme, kullanıcı için anlamlı olma, uygun miktarda olma, hangi kullanıcılara dağıtılacağının doğru belirlenmesi, zamanında sağlanma (günlük, aylık, yıllık ya da koşula bağlı raporlar), doğru çıktı yönteminin (ortamının) seçilmesi.
  - Çıktılar bilgilerin alfabetik, kronolojik ya da maliyete göre sıralanması, kabul edilebilir sınırların belirlenmesi ve grafik tipinin, renginin ve ölçeğinin ayarlanmasıyla yönlendirilir.
- Girdi tasarımı
  - Girilen verinin kalitesi çıktı bilgisinin kalitesini belirler (GIGO ilkesi: hatalı veri girilirse hatalı çıktı alınır).
  - Girdi tasarımı kullanımı kolay, uyumlu, doğru girdi almayı sağlayan, görünüşü güzel, basit ve etkin olmalıdır; kullanıcının hatasız giriş yapabileceği en kolay biçim sağlanmalıdır.
- Girdi tasarımında kodlama (ekrandan, 01:20:00)
  - Burada kodlama program yazmak değil, verilere sınıflamayı mümkün kılacak kodlar vermektir. Örnek: öğrenim durumu için ilkokul 1, ortaokul 2, lise 3, üniversite 4; yaş yerine doğum tarihinin girilmesi; uluslararası hastalık kodlaması; fakülte ve bölüme göre kodlanmış öğrenci numaraları.
  - İyi bir kodlamada: mümkün olduğunca kısa olma; kolay değişmeyecek biçimde olma ve koda başlamadan önce kesin karar verilmiş olma; tekrarlanmama, tekil (unique) olma; birbiriyle karıştırılabilecek sembollerden kaçınma; kısaltmalar varsa anlamlı olma; araya eleman eklemeye izin verecek biçimde değişikliğe açık olma.
- Veri tabanı tasarımı
  - Veri yapısı program yapısını etkilediği için tasarım kalitesini önemli ölçüde belirler. Gereksinim analizinde tanımlanan veri yapılarının mantıksal gösterimleri seçilir; anlamlı bilgi alma ve veri bütünlüğü (veri güvenliği) önemlidir.
- Ara birim tasarımı
  - Ekran yapılarında etkinlik, kullanıcı alışkanlıklarına uygunluk, hatayı en aza indirme (her bilgiyi yeniden yazdırmak yerine açılır menüden seçtirme), ergonomi.
  - Renk ergonomisi: gözü yormayan renkler; beyaz üzerine mavi ya da mavi üzerine beyaz uygun, yeşil ile kırmızı ve çok canlı, parlak renkler yorucu.
  - Bütün ekranlar aynı tarzda olmalı; kullanıcı şaşırtılmamalı. Bilgi verme ekranları, program kesildiğinde çıkan ekranlar ve hata tipini gösteren mesajlar da ara birim tasarımına girer.
- Yapısal ve nesneye yönelik tasarım farkı
  - Girdi, çıktı, veri tabanı ve program tasarımı iki yaklaşımda da vardır; değişen kullanılan diyagramlar ve ifade biçimidir. Yapısal yaklaşımda yapı diyagramı ve ER diyagramı, nesneye yönelik yaklaşımda sıralama (sequence) diyagramı ve ayrıntılı sınıf diyagramı kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yapı diyagramının amacı
  - Analizde çizilen veri akış diyagramlarının modüler yaklaşımla yazılım tasarımına dönüştürülmesidir.
  - Modül sayısı VAD'daki işlem sayısına eşit olmak zorunda değildir; daha çok ya da daha az olabilir. Yapı yaygın (yayvan) ya da daha hiyerarşik olabilir; hangisi VAD'ı en iyi modüler hâle getiriyorsa o seçilir.
- Veri ve kontrol akışı ayrımı
  - İçi boş yuvarlak uçlu ok veri, içi dolu yuvarlak uçlu ok lojik (kontrol) bilgi taşır. Bir sayıya ya da bilgiye bakılarak verilen bir kararın iletilmesi kontrol akışıdır.
- Veri akış diyagramı kuralı
  - Dış varlıktan dış varlığa, dış varlıktan veri deposuna ya da depodan depoya doğrudan veri aktarılamaz; arada mutlaka bir işlem bulunmalıdır. Sınavda en sık görülen hata bu kuralın çiğnenmesiydi.
- Girdi kodlamasının önemi
  - Kodlama sınıflamayı ve istatistiği mümkün kılar: öğrenim durumu serbest metinle girilirse çalışanlar arasında kaç ilkokul mezunu olduğu sayılamaz.
  - Kodlar analiz ve girdi tasarımı sırasında son biçimini almalıdır; sistem kullanılmaya başlandıktan sonra yeniden düzenlemek çok zordur.
- Teknik kişiler de ekonomik kararlara katılabilir
  - Satın alma, leasing ve kiralama gibi kararlar ekonomik olsa da mühendislerin bu kararlarda yer alabileceği göz ardı edilmemelidir.

## Kısa Tekrar Notları

- Sistem tasarımı = gereksinimlerin yazılımı hazırlanacak biçime dönüştürülmesi; ön (genel) tasarım + ayrıntılı tasarım.
- Altyapı süreci: envanter → iş yükü tahmini → donanım ve yazılım değerlendirme → satıcı firma → finansal satın alım türü.
- Yazılım değerlendirme ölçütleri: performans etkinliği, performans verimliliği, kullanım kolaylığı, esneklik, dokümantasyon kalitesi, üretici desteği.
- Satıcı hizmetleri: donanım desteği, yazılım desteği, kuruluş ve eğitim, bakım.
- Satın alma: uzun vadede ucuz, tam kontrol ama tam sorumluluk. Leasing: sermaye bağlanmaz ama sonunda sahip olunmaz. Kiralama: kolay değişir, bakım dahil ama pahalı.
- Mimari tasarım klasik yaklaşımda yapı diyagramı (structure chart) ile gösterilir.
- Yapı diyagramı: dikdörtgen modül, içi boş yuvarlak uçlu ok veri, içi dolu yuvarlak uçlu ok kontrol, eşkenar dörtgen seçim, yarım daire ok döngü.
- Ayrıntılı tasarım: çıktı, girdi, veri tabanı, program ve ara birim tasarımı.
- GIGO: girdi kalitesi çıktı kalitesini belirler.
- İyi kod: kısa, kalıcı, tekil, karışmayan semboller, anlamlı kısaltma, genişlemeye açık.
- Ara birimde tutarlılık ve renk ergonomisi önemlidir.
- Nesneye yönelik tasarımda yapı diyagramı yerine sıralama diyagramı, ER yerine ayrıntılı sınıf diyagramı.

## Detaylı Açıklamalar

- **Ön tasarımın iki yüzü.** Ön tasarımda iki farklı iş birlikte yürür. Birincisi altyapının belirlenmesidir: işletmede hangi donanım ve yazılımın bulunduğu çıkarılır (envanter), yeni sistemin iş yükü tahmin edilir ve var olan kaynakların yetip yetmediğine bakılır. Yetmeyen kısımlar için donanım ve yazılım değerlendirilir, satın alınacak ürünler için satıcı firma seçilir ve satın alma, leasing ya da kiralama arasında karar verilir. İkincisi yazılımın mimari tasarımıdır: yeni geliştirilecek yazılımın modülleri, modüller arası ilişkiler ve veri alışverişi belirlenir. Bu ikinci kısım yazılım geliştiricinin asıl işidir ve klasik yaklaşımda yapı diyagramıyla gösterilir.

- **Bordro yapı diyagramı (ekrandan, 00:30:00).** En üstte "Payroll program" modülü vardır ve altındaki üç ana modülü kapsayan yarım daire ok, bu modüllerin her çalışan için tekrar çalıştığını gösterir. "Enter time cards" modülü çalışma kartını girer, çalışan kaydını okur ve kartı doğrular; geçerli zaman kartı bilgisini üst modüle verir. "Calculate amounts" modülü çalışanın ücret ve vergi oranlarını alır, ödeme miktarlarını hesaplar; bunun için temel ücret, fazla mesai, vergi ve diğer kesintiler ayrı alt modüllerde hesaplanır. "Output payroll" modülü çalışan kaydını günceller, bordro işlemlerini yazar ve genel muhasebe defterini günceller. Hoca bu örnekte modüller arasında yalnız veri aktarıldığını, kontrol akışı olmadığını söyledi. <!-- BELİRSİZ: Karede "Valid flag" adlı bir akış da var; bayrak niteliğinde olduğu için büyük olasılıkla kontrol akışıdır, ama kare çözünürlüğünde ucunun dolu mu boş mu olduğu seçilemiyor. -->

- **Sipariş yapı diyagramı (ekrandan, 00:35:00).** "Create new order" modülü müşteri bilgisini kaydeder, siparişi kaydeder, sipariş işlemini yürütür ve onay üretir. Müşteri bilgisi kaydedilirken müşterinin var olan bir müşteri mi yoksa yeni mi olduğuna bakılır: var olan müşteriyse bilgisi alınır, yeni müşteriyse yeni müşteri kaydı oluşturulur. Bu iki alt modül arasındaki eşkenar dörtgen, ikisinden yalnız birinin çalışacağını gösterir. Sipariş kaydında siparişin her kalemi için istenen ürün alınır, ürünün envanterde olup olmadığına ve fiyatına bakılır, yeni sipariş satırı eklenir; bu kısım bir döngüdür.

- **Girdi kodlaması neden yapılır?** Bir personel dosyasına öğrenim durumu serbest metin olarak girilirse aynı değer farklı biçimlerde yazılabilir ve "kaç çalışan ilkokul mezunu" gibi bir soru cevaplanamaz. Her değere bir kod verilirse (ilkokul 1, ortaokul 2, lise 3, üniversite 4) veri standarda oturur, sayısal olarak işlenebilir ve sınıflanabilir. Uluslararası hastalık kodları ve fakülte ile bölüm bilgisini içeren öğrenci numaraları da bu tür kodlamalardır.

> **Ek bilgi (derste anlatılmadı):** GIGO, İngilizce "Garbage In, Garbage Out" (çöp girerse çöp çıkar) deyiminin kısaltmasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
