# Ders 5 Çalışma Özeti

## Genel Konular

- Nesneye yönelik analiz yaklaşımı (ekrandan, 00:05:00)
  - Çözümleme (analiz), bir şeyi anlayabilmek için onu parçalarına ayırmaktır.
  - Analizde uygulama/problem alanı ve kullanıcı gereksinimleri anlaşılır; koddaki sınıflar, nesneler ve bunlar arasındaki üst düzey etkileşimler belirlenir. Sonuçta çözümleme modeli oluşturulur.
  - Nesneye yönelik analizde gereksinimler kullanım öyküleri (use case belgeleri) ve kullanım senaryosu (use case) diyagramlarıyla, veri tarafı ise sınıf diyagramlarıyla modellenir.
- Uygulama alanının çözümlenmesi (domain analysis)
  - Amaç uygulama alanını anlamak ve elde edilen bilgileri analiz modeline taşımaktır.
  - Bilgi kaynakları: teknik literatür, mevcut uygulamalar, müşteri anketleri, uzman tavsiyeleri, mevcut ve gelecekteki gereksinimler.
  - Alana özgü terimlerden bir sözlük oluşturulur. Kullanıcılarla görüşme (interview) ve yerinde inceleme de bilgi toplama yollarıdır.
- Gereksinimlerin belirlenmesi ve doğal dille yazılmış gereksinim belgesi (ekrandan, 00:10:00)
  - Gereksinimler belgesi, müşterinin programdan beklentilerini doğal konuşma diliyle anlatan belgedir.
  - Örnek: NextGenPOS perakende satış programı (Larman'ın nesneye yönelik analiz ve tasarım kitabından). Kasadaki alış-verişlere yardımcı olur, her işlemi saklar, mali bilgileri harici bütçe sistemine, mal çıkış bilgilerini harici envanter sistemine iletir, raporlama ve analiz yapılabilir, müşteriye fiş verir, her satışta KDV'yi hesaplar, tüm şubelerin işlemlerini merkezi sunucuya iletir.
  - Bu metinden kullanım öykülerine geçilir.
- Kullanım öyküleri (use case belgeleri) (ekrandan, 00:15:00)
  - Programın yapacağı işleri ayrıntılı adımlarla ve belli kurallara uyarak anlatan belgelerdir.
  - Amaçları: ürünün sağlaması beklenen işlevleri ve çalışma ortamını belirlemek, son kullanıcı ile yazılım ekibi arasında anlaşma zemini kurmak, kullanıcı ile sistemin etkileşimini açık ve belirsizlikten uzak tanımlamak, doğrulama testleri için zemin oluşturmak.
  - Bölümleri: giriş bölümü (sistem neyi, hangi koşul ve sınırlar içinde yapacak; öykü adı, birincil aktör, ilgililer, ön koşul, son koşul), ana senaryo (ana başarılı akış), alternatif senaryolar.
- Örnek kullanım öyküsü: Satış İşlemi (ekrandan, 00:20:00)
  - Birincil aktör kasiyerdir. İlgililer: kasiyer (doğru ve hızlı giriş, ödeme hatası olmaması), satıcı (komisyonlarının güncellenmesi), müşteri (en az çabayla hızlı hizmet, iade için fiş).
  - Ön koşul: kasiyerin kimliği doğrulanır. Son koşul: ödeme tahsil edilir, satış kaydedilir, fiş yazılır.
  - Ana senaryo 11 adımdır; 3. ve 4. adımlar her ürün için tekrarlanır.
  - Alternatif öyküler: 3a geçersiz barkod, 3-7a müşterinin bir kalem malı alışverişten çıkarması (ekrandan, 00:25:00).
- Sınıfların belirlenmesi (ekrandan, 00:30:00)
  - Kullanıcı gereksinimleri belgesinden ve kullanım senaryolarından aday sınıflar elde edilir; saklanan bilgi ve gereken hizmetler incelenir.
  - Üyeler sıfat ve eylemler taranarak, sorumluluklar CRC kartlarıyla belirlenir.
  - Sorumluluklar dağıtılır: bir yerde yoğunlaşmamalı, genelden özele tanımlanmalı, bir bilgiyle ilgili davranışlar o bilgiyle aynı sınıfta olmalı (encapsulation), tek bir şey hakkındaki bilgi tek sınıfta yer almalı.
- Kullanım senaryosu diyagramının temel elemanları (ekrandan, 00:35:00)
  - Aktörler çöp adamla, başka bir sistem olan aktör kutuyla, use case'ler elipsle, sistem sınırı dörtgenle gösterilir.
  - Örnek: ATM sistemi; banka müşterisi, banka memuru ve bakım personeli aktörleri; nakit çekme, fon transferi gibi use case'ler.
- Veri varlıkları ile nesneler arasındaki fark (ekrandan, 00:50:00)
  - Geleneksel (yapısal) yaklaşımda veri varlıkları ER diyagramıyla modellenir ve ilişkisel veritabanıyla kullanılır; veri ile işlemler ayrı yerlerdedir.
  - Nesneye yönelik yaklaşımda sınıf hem özellikleri (veri) hem de bu veri üzerinde çalışan metotları (davranış) içerir; nesneler veriyi enkapsüle eder, mesajlarla etkileşir.
- Sınıf diyagramı (ekrandan, 00:55:00 ve 01:00:00)
  - Genelleştirme/özelleştirme hiyerarşileri (süper sınıf, alt sınıf, kalıtım) ve bütün-parça (aggregation) ilişkileri içerir.
  - Örnekler: motorlu taşıt hiyerarşisi, bilgisayar ve parçaları, müşteri sınıf sembolü, banka hesap sistemi, derse kayıt sınıf diyagramı (ilişki sınıfı ile).

## Hocanın Özellikle Vurguladığı Kısımlar

- Gereksinim analizi raporu (SRS) her projede bulunmalıdır
  - Başka hiçbir belge olmasa bile SRS hazırlanmalıdır, çünkü müşteriyle yazılım ekibi arasında sözleşme niteliği taşır.
- Doğal dille yazılmış gereksinim metnini analist yönlendirmelidir
  - Metin tamamen kullanıcıya bırakılırsa kullanıcı kendisi için önemli ama sistem için gereksiz ayrıntılara yer verir. Metni analistin hazırlaması ya da yönlendirmesi daha faydalıdır.
- Ana senaryodaki adımlar birleştirilmez
  - Her adım ayrı bir işlem olarak yazılır; böylece test sırasında her birinin doğru çalışıp çalışmadığı ayrı ayrı kontrol edilebilir.
- Aktör canlı olmak zorunda değildir
  - Bir sensör ya da başka bir sistem de aktör olabilir. Bir use case'te birden fazla aktör olabilir, ama yalnız biri birincil aktördür.
- Use case diyagramları genelden ayrıntıya doğru çizilir
  - Veri akış diyagramlarında olduğu gibi önce bütün sistem ve temel alt senaryolar gösterilir, sonra her use case ayrı diyagramlarda ayrıntılandırılır.
- Analiz aşamasındaki sınıf diyagramı kabadır
  - Analizde metotlara çok girilmez; hangi sınıflar, hangi özellikler ve hangi ilişkiler olduğu genel olarak çizilir. Metotlar ve tasarım kalıpları (design patterns) tasarım aşamasında eklenir.

## Kısa Tekrar Notları

- Analiz = parçalara ayırarak anlama; sonuç çözümleme modelidir.
- Domain analizi: literatür, mevcut uygulamalar, anketler, uzman görüşü, sözlük, görüşme, yerinde inceleme.
- Sıra: doğal dille gereksinim metni, kullanım öyküsü (use case belgesi), use case diyagramı, sınıflar ve sınıf diyagramı.
- Use case belgesi: ad, birincil aktör, ilgililer ve ilgi alanları, ön koşul, son koşul, ana senaryo, alternatif senaryolar.
- Alternatif senaryolar ana senaryodaki adım numarasıyla adlandırılır (3a, 3-7a gibi).
- Use case diyagramı: aktör çöp adam, use case elips, sistem sınırı dörtgen.
- Sınıf belirleme: sıfat ve eylem taraması, CRC kartları, sorumlulukların dağıtılması, encapsulation.
- Yapısal yaklaşımda veri ve işlemler ayrıdır; nesnede ikisi bir aradadır.
- Sınıf diyagramında genelleştirme/özelleştirme (kalıtım), aggregation (bütün-parça) ve çokluklu ilişkiler (1, 0..*) bulunur.
- İlişkinin kendi özelliği varsa ilişki sınıfı (association class) kullanılır: derse kayıtta not (grade) ve not girme (postGrade).

## Detaylı Açıklamalar

- Nesneye yönelik analizin ilk kademesi gereksinim analizinde kullanım öykülerinin oluşturulmasıdır. Önce kullanıcıdan konuşma dilinde bir hikaye alınır; bu hikayenin doğru alınması için analist kullanıcıyı yönlendirir. NextGenPOS örneğindeki metin sistemi çok ayrıntıya girmeden ama çerçevesini çizecek kadar anlatır: perakende satış programı kasadaki işlemlere yardım eder, işlemleri saklar, bütçe ve envanter sistemleri harici sistemlerdir, yalnız satış işlemlerinde fiş verilir, KDV hesaplanır ve birden fazla şubenin işlemleri merkezi sunucuya gider (ekrandan, 00:10:00).
- Bu metinden kullanım öyküsüne geçilir. Satış İşlemi öyküsünde birincil aktör kasiyerdir. Kasa açığı maaşından kesildiği için kasiyer doğru ve hızlı giriş ister, ödeme hatası istemez. Satıcı (mağazada müşteriyle ilgilenen kişi) komisyonlarının doğru güncellenmesini ister; bu uygulamada kasada hangi satıcının işlem yaptığının kodu girilir. Müşteri en az çabayla hızlı hizmet ve ürün iadesinde kullanmak üzere doğru bir fiş ister. Ön koşul kasiyerin kimliğinin doğrulanması, son koşul ödemenin tahsil edilmesi, satışın kaydedilmesi ve fişin yazılmasıdır; satış ayrıca bütçe ve envanter sistemlerine aktarılır (ekrandan, 00:20:00).
- Ana senaryodaki adımlar fonksiyonel (işlevsel) gereksinimlerdir. Müşteri kasaya gelir, kasiyer yeni satış başlatır, barkodu okutur, sistem satış kalemini (tanım, fiyat, toplam bedel) oluşturur; 3. ve 4. adımlar her ürün için tekrarlanır. Sistem toplamı vergiyle birlikte hesaplar, kasiyer toplamı bildirip ödeme ister, müşteri öder ve sistem tahsil eder, sistem kaydı tutup envanter ve mali sisteme bilgi gönderir, fişi verir, müşteri ayrılır.
- Ana senaryo her şeyin yolunda gittiği akıştır; use case belgesi alternatif öyküler eklenmeden tamamlanmış sayılmaz. 3a'da barkod geçersizse sistem uyarı mesajı verir ve kaydı reddeder, okutma tekrarlanır. 3-7a'da müşteri 3. ile 7. adımlar arasında herhangi bir anda bir kalem malı çıkarmak isteyebilir (örneğin toplamı duyunca parası yetmediği için); kasiyer çıkarılacak ürünün barkodunu okutur, sistem güncel toplamı bildirir ve akış ilgili adımlardan devam eder (ekrandan, 00:25:00).
- Use case belgeleri ve diyagramları işlevsel gereksinimleri gösterir. Nesneye yönelik modelin bir de veri tarafı vardır: hangi sınıfların kullanıldığı ve aralarındaki ilişkiler. Sınıflar gereksinim belgesindeki sıfat ve eylemler taranarak bulunur, sorumluluklar CRC kartlarıyla (çevik yaklaşımda XP'de görülmüştü) belirlenir.
- Geleneksel yaklaşımda veri varlıkları (ör. müşteri) ER diyagramında özellikleri ve ilişkileriyle modellenir; işlemler (işlem 1, 2, 3) ayrıdır ve veriyi dışarıdan kullanır. Nesneye yönelik yaklaşımda sınıf bir varlık tipidir, nesne onun özel halidir; nesne hem verisini hem de bu veriyi işleyen metotları içerir ve işlemler mesajlarla başlatılır (ekrandan, 00:50:00).
- Sınıf diyagramında genelleştirme/özelleştirme hiyerarşisi kalıtımı gösterir: MotorVehicle süper sınıfının altında Truck, Car, Tractor; Car'ın altında SportsCar, Sedan, SportUtility vardır; Sedan arabanın bütün özelliklerini kalıtımla alır (ekrandan, 00:55:00). Banka hesap sisteminde bir müşterinin hiç hesabı olmayabilir ya da birden çok hesabı olabilir (0..*); alt hesap türü üst sınıf Account'un tüm özelliklerine ek olarak faiz oranı (interest rate) özelliğine sahiptir. Derse kayıt diyagramında Course ile CourseSection arasında 1 - 0..*, CourseSection ile Student arasında 0..* - 0..* ilişki vardır; bu ilişkinin özelliği olan not, CourseEnrollment ilişki sınıfında (grade, postGrade) tutulur (ekrandan, 01:00:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
