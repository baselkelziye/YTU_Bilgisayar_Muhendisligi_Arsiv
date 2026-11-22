# Ders 11 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumlarının kapsamı
  - Bu ders, öğrenci gruplarının dönem projelerinin analiz ve tasarım kısmını sundukları bir oturumdur. Sunumlarda projeye giriş, zaman planlaması, fizibilite ve analiz ile tasarım aşamalarında hazırlanan modeller anlatılmıştır.
  - Her grup üyesi kendi üstlendiği rolü (proje yöneticisi, sistem analisti, tasarımcı, programcı, müşteri rolü, test) ve bu rolde ürettiği belgeleri anlatmıştır.
  - Sunulan örnek sistemler: sıralı oylama yapan bir kurum içi oylama sistemi, birden çok kütüphaneyi tek veri tabanında toplayan bir kütüphane uygulaması, gişe görevlisinin kullandığı bir otopark takip sistemi ve bir üniversitede kulüp işlemlerini yürüten bir kulüp yönetim sistemi.
- Proje başlatma ve gereksinim belirleme
  - Müşteriyle tanışma toplantısı, kullanıcı isteklerinin alınması, isteklerin değerlendirilip müşteriye değerlendirme raporu sunulması ve son teslim tarihinin birlikte belirlenmesi.
  - Müşteri istekleri bir tabloda listelenip her birinin gerçekleştirilme durumu izlenmiştir (ekrandan, 00:30:00). Örnek istekler: tek uygulamadan birden çok kütüphaneye erişim, mail ile üyelik, ödünç alma, kitap konumunu görme, benzer kitap önerisi, yorum yapma, bağış, basit arayüz.
  - Gerçekleştirilmesi zor ya da maliyetli istekler (çok kısa teslim süresi, olmayan kitap için sıraya girme ve mail bildirimi) müşteriyle konuşularak süre ve maliyet gerekçesiyle uzlaşmaya varılmış ya da kapsamdan çıkarılmıştır.
  - Müşteriyle çevik (agile) bir yaklaşımla sürekli iletişim: istek formları üzerinden geri bildirim alma, ara sürümleri gösterme ve revizyon yapma.
- Fizibilite çalışmaları
  - Teknik fizibilite: hangi platform, dil ve veri tabanının seçileceği; seçeneklerin avantaj ve dezavantajları (örneğin sistemi yalnız gişe görevlisine mi yoksa doğrudan araç sahibine mi açmak).
  - Ekonomik fizibilite: toplam geliştirme maliyetleri, çalışanların yıllık ücret maliyetleri, yıllık yürütme maliyetleri, gelir tablosu; maliyet fayda analizinde net bugünkü değer (NPV), geri ödeme süresi ve yatırımın geri dönüş oranı.
  - Kaynak fizibilitesi: proje ekip yapısı, organizasyon şeması, çalışan ve materyal kaynak atamaları ve standart ücretleri.
  - Zaman fizibilitesi: iş kırılım yapısı (WBS) ile Gantt şeması, kilometre taşları, öncül ilişkileri ve PERT diyagramı.
  - Pazar analizi, teknoloji analizi, finansman (destek programları) ve satış/pazarlama planı da fizibilite raporunun parçası olarak sunulmuştur.
- Analizde kullanılan modeller
  - Nesneye yönelik analiz: kullanım durumu (use case) diyagramı ve senaryo dokümanı (senaryo, aktörler, ilgililer ve beklentileri, ön koşullar, ana akış, alternatif akış).
  - Yapısal analiz: taslak (bağlam) veri akış diyagramı, birinci düzey ve ikinci düzey veri akış diyagramları.
- Tasarımda kullanılan modeller
  - Nesneye yönelik tasarım: UML sınıf diyagramı ve sıralama (sequence) diyagramı.
  - Yapısal tasarım: yapı diyagramı (veri çiftleri ve kontrol akışı ile modüller arası çağrı ilişkileri).
  - Veri tasarımı: E-R diyagramı ve ilişkisel tablo yapısı; belge tabanlı (NoSQL) veri tabanında koleksiyon tasarımı.
  - Ara birim tasarımı: önce kâğıt üzerinde eskiz, sonra bir tasarım aracıyla prototip; sade ve dikkat dağıtmayan renk ve düzen.
- Gerçekleştirme ve teknoloji seçimi gerekçeleri
  - Sunumlarda dil, çatı (framework) ve veri tabanı seçimleri gerekçeleriyle anlatılmıştır: tek kod tabanından birden çok platforma uygulama çıkarma, asenkron çalışma desteği, ekip üyelerinin bildiği dil, ücretsiz kullanım sınırı yeterli bir veri tabanı, sunucu gerektirmeyen gömülü bir SQL motoru.
  - Güvenlik tasarımı: parolanın özetlenerek (hash) saklanması, veri tabanı ve sunucunun ayrı konteynerlerde çalıştırılması, giriş sonrası verilen oturum jetonu (token), belli süre işlem yapmayan kullanıcının oturumunun kapatılması, iç nesne kimliklerinin ön yüze açılmaması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yaklaşım seçimi ile diyagramlar tutarlı olmalıdır
  - Yazılım nesneye yönelik hazırlanıyorsa tasarım da nesneye yönelik olmalı (sınıf ve sıralama diyagramları); yapısal yaklaşım seçildiyse analizden tasarıma her şey yapısal olmalıdır (veri akış ve yapı diyagramları).
  - Sunuma hangi diyagramların konacağına, projenin hangi yaklaşımla hazırlandığı düşünülerek baştan karar verilmelidir.
- Belirleyici olan dil değil yaklaşımdır
  - Nesneye yönelik bir dil (örneğin Java) kullanılsa bile, nesne özellikleri kullanılmadan yazılmış bir yazılım yapısal yaklaşımla hazırlanmış sayılabilir. Bu durumda yapı diyagramı ile belgelemek doğrudur.
- İkinci düzey veri akış diyagramı ayrıntı içindir
  - Birinci düzeyde bütün uygulama tek diyagramda görünür. İkinci düzeyde her süreç için ayrı bir diyagram çizilir; bütün sistem tek bir ikinci düzey diyagramda birleştirilmez.
- Gerçek bir müşteriyle çalışmanın değeri
  - Gerçek bir kullanıcıyla iletişim, gereksinim toplama ve revizyon sürecini daha gerçekçi kılar.

## Kısa Tekrar Notları

- Proje raporu: giriş, zaman planı, fizibilite (teknik, ekonomik, kaynak, zaman, yasal), analiz modelleri, tasarım modelleri.
- Nesneye yönelik yol: use case diyagramı + senaryo dokümanı, sınıf diyagramı, sıralama diyagramı.
- Yapısal yol: bağlam (taslak) VAD, 1. düzey VAD, her süreç için ayrı 2. düzey VAD, yapı diyagramı.
- Senaryo dokümanı: aktörler, ilgililer ve beklentileri, koşullar, ana akış, alternatif akış.
- Use case diyagramında yan işlevler "extend" ilişkisiyle ana kullanım durumuna bağlanabilir.
- Gantt şeması: WBS numarası, iş adı, süre, başlangıç, bitiş, öncül, kilometre taşları (süresi 0 olan toplantılar).
- Ekonomik fizibilite: geliştirme maliyeti, yıllık yürütme maliyeti, gelir; NPV, geri ödeme süresi, geri dönüş oranı.
- E-R tasarımında çoka çok ilişki bir bağlantı tablosuyla (örneğin kullanıcı ve kitap arasındaki yorum tablosu) çözülür.
- Dil seçimi yaklaşımı belirlemez; belgeleme seçilen yaklaşıma göre yapılır.

## Detaylı Açıklamalar

Bu oturumda dersin teorik kısmında işlenen sistem analizi ve tasarımı adımlarının bir dönem projesinde nasıl uygulandığı öğrenci sunumları üzerinden görülmüştür. Sunumların ortak akışı şöyledir: sistemin amacı ve neden gerekli olduğu, ekip yapısı ve roller, müşteriyle yapılan toplantılar ve istek değişiklikleri, fizibilite çalışmaları, analiz modelleri, tasarım modelleri ve kısaca uygulamanın arayüzü.

Fizibilite bölümünde ekonomik analizin tablolarla nasıl kurulduğu görülmüştür. Bir sunumda yıllık yürütme maliyetleri tekrarlayan harcamalar olarak listelenmiştir (ekrandan, 00:10:00): internet bağlantısı 16.000 \$, ekipman bakım ve onarımı 18.000 \$, bilgisayar işlemleri/programlama 45.000 \$, eğitim ve sürekli destek (yardım masası) 14.000 \$, ekipman amortismanı 22.000 \$, kaynaklar 16.500 \$; toplam 131.500 \$. Aynı sunumda işletme döneminin ilk üç yılı için toplam gider 690.026 \$, toplam gelir 772.260 \$ ve ek kâr 82.234 \$ olarak verilmiştir (ekrandan, 00:15:00). Başka bir sunumda geliştiricilerin saatlik ücretleri, günde 8 saat çalışma varsayımı ve zaman planındaki gün sayıları çarpılarak geliştirme maliyeti bulunmuş, satış fiyatı ve müşteri sayısı henüz belirlenmediği için geri ödeme analizinin yapılamadığı, bu analizin geliri maliyete oranlayarak yapılacağı belirtilmiştir.

Zaman fizibilitesi için bir otopark sisteminin Gantt şeması örnek olarak gösterilmiştir (ekrandan, 00:50:00). Şemada iş kırılım yapısı şöyledir: 1 Analiz (ilk toplantı, problemin tanımı ve sistemin planlanması, fizibilite çalışması, sistem gereksinimlerinin belirlenmesi, analiz bitimi toplantısı), 2 Tasarım (genel tasarım, ayrıntılı tasarım, tasarım bitimi toplantısı), 3 Geliştirme ve Test (ön yüz geliştirme, arka plan geliştirme ve birim test paralel; ardından sistem testi ve kullanıcı testleri), 4 Proje teslim toplantısı. Süresi 0 gün olan toplantılar kilometre taşı olarak işaretlenmiştir.

Analiz modellerinde iki yaklaşım görülmüştür. Nesneye yönelik analiz yapan gruplar use case diyagramı ve her senaryo için senaryo dokümanı hazırlamıştır. Bir oylama sisteminde çalışan, yetkili ve yönetici olmak üzere üç aktör vardır; profil düzenleme, oy verme ve sonuç görme bütün aktörlerce yapılırken oylama oluşturma yalnız yetkili ve yöneticiye, yetki değiştirme yalnız yöneticiye verilmiştir. Otopark sisteminde ana aktör gişe görevlisidir; abonelik işlemi ve boş yer sorgulama, ana giriş-çıkış işlemlerini genişleten (extend) kullanım durumları olarak gösterilmiştir. Senaryo dokümanında ana akış (araç sahibi bilgisini verir, görevli sisteme girer, park yeri seçilir, çıkışta plaka verilir, ücret hesaplanır) ve alternatif akış (yanlış plaka girilirse sistem hata mesajı verir) yazılmıştır.

Yapısal analizde bir kütüphane sistemi için bağlam diyagramı ve ikinci seviye veri akış diyagramları gösterilmiştir (ekrandan, 00:35:00). Örneğin 1.0 sürecinin içinde "1.1 Giriş bilgilerinin veri tabanı ile karşılaştırılması" ve "1.2 Üye girişi / yeni üye kaydı" alt süreçleri, "Üye Listesi" veri deposuyla alışveriş yapar. 2.0 sürecinin içinde "2.1 Kitabın veri tabanında aranması" (Kitaplık deposundan kitap bilgisi okunur) ve "2.2 Kullanıcı mevcut ceza kontrolü" vardır; sonuç kullanıcıya bildirim mesajı olarak döner ve ödünç kayıt listesi güncellenir.

Tasarım modellerinde nesneye yönelik gruplar UML sınıf diyagramı ve sıralama diyagramı hazırlamıştır. Otopark sisteminin sıralama diyagramında (ekrandan, 00:55:00) JVM, Arayüz, SisAn, Otopark, Abonman, OtoparkDurum, AbonmanDurum, Araç ve Hakkımızda nesneleri; `main()`, `new`, `<<create>>` mesajları ve Otopark nesnesinin kendine gönderdiği `AracGiris()`, `AracCikis()`, `AbonmanGiris()`, `AbonmanHakSorgula()`, `UcretSorgula()` gibi çağrılar görülür.

Yapısal yaklaşımı seçen bir grubun yapı diyagramı (ekrandan, 01:10:00) "Kulüp Yönetim Sistemi" ana modülünden giriş ekranına, ana sayfaya ve veri tabanına giden çağrıları; ana sayfadan kullanıcı profili, kulüp profili ve etkinlikler modüllerine, etkinlik sayfasından etkinlik durumu ve onun altındaki "Etkinlik Onayla", "Etkinlik Sil", "Etkinlik Red" modüllerine inen hiyerarşiyi gösterir. Oklar üzerindeki küçük daireler modüller arasında taşınan veri çiftlerini (kullanıcı bilgileri, token, etkinlik bilgileri, etkinlik durumu) temsil eder.

Veri tasarımında bir kütüphane sistemi için E-R diyagramı gösterilmiştir (ekrandan, 00:40:00). Ana tablolar Users, Books ve Libraries'dir. BookCopies tablosu bir kitabı bir kütüphaneye bağlar ve kopya sayısını tutar; BookLoans hangi kullanıcının hangi kopyayı hangi tarihte aldığını ve iade edilip edilmediğini tutar; Comments, kullanıcı ile kitap arasındaki çoka çok ilişkiyi çözen bağlantı tablosudur; BookGenres bir kitabın birden çok türünü tutar. Belge tabanlı veri tabanı kullanan bir grup ise farklı kullanıcı türlerini (hepsi aynı kullanıcı sınıfının alt türleri olduğu için) tek koleksiyonda saklamış, kulüplere bağlı etkinlikleri ayrı koleksiyon açmadan kulüp belgesinin içinde tutmuştur.

Hocanın genel geri bildirimi, projede seçilen yaklaşımın bütün belgelerde tutarlı olması gerektiğidir. Yapı diyagramını iyi hazırlayan ama yazılımı nesneye yönelik hazırladığını söyleyen bir gruba sıralama diyagramı olup olmadığı sorulmuş; dilin değil yaklaşımın önemli olduğu, nesne özellikleri kullanılmadıysa yazılımın yapısal yaklaşımla hazırlanmış sayılabileceği belirtilmiştir. Bütün sistemi tek bir ikinci düzey veri akış diyagramında birleştiren gruba ise ikinci düzeyin her süreç için ayrı diyagram olduğu hatırlatılmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
