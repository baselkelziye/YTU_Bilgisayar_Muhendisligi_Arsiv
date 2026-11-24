# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin yapısı
  - Bu ders, dönem projesi sunumlarının üçüncü haftasıdır. Konu anlatımı yoktur.
  - Gruplar, TÜBİTAK 1512 Teknogirişim Sermaye Desteği programının iş planı biçiminde hazırladıkları iş fikirlerini sunar (ekrandan, 00:15:00). Bu derste dokuz sunum yapılır.
  - Sunumlar ortak bir iskeleti izler: iş fikri ve çıkış noktası, ürün/hizmet ve modüller, yenilikçi yön, rakip karşılaştırması, hedef kitle ve pazar analizi, iş paketleri ve iş-zaman çubuk grafiği, ekip, maliyet tablosu ve ticari beklenti/sürdürülebilirlik.
- Bu derste sunulan iş fikirleri
  - İşletmelere QR kodla giriş kaydı tutan, bulaş riskini analiz edip mekânlara puan veren bir salgın yönetim sistemi (mobil ve web).
  - Seslendirilmiş şiirlerin dijital ya da çiçek/çikolata kutusuyla hediye olarak gönderildiği bir abonelik platformu.
  - Restorandaki dolu/boş masaları uygulamadan görüp gitmeden sipariş verme ve uygulamadan ödeme yapma (garsonsuz sipariş) uygulaması.
  - Bebeklerde Moro (sıçrama) refleksini telefonla çekilen videodan yapay zekâyla değerlendirip ön teşhis raporu veren mobil uygulama.
  - Hayvanseverleri, veterinerleri ve evcil hayvan malzemesi satıcılarını bir sosyal ağda buluşturan, modüllü bir mobil uygulama.
  - Veterinerlerin tahlil sonuçlarını ortak platformda paylaştığı, hayvan sahiplerine mobil uygulama sunan web tabanlı bir veteriner yönetim (CRM) ve hizmet platformu.
  - Yerli üretim, uzaktan ve sesli komutla yönetilen robotik çim biçme makinesi.
  - İkinci el araç alım satımında parayı blokeli hesapta tutup, plaka alıcıya geçince satıcıya aktaran güvenli ödeme uygulaması.
  - Nokta bulutundan üç boyutlu yapı modeli oluşturan, inşaat sektörüne yönelik modelleme yazılımı.
- Sunumlarda kullanılan planlama ve analiz araçları
  - İş-zaman çubuk grafiği (Gantt): iş paketleri, alt faaliyetler, başlama-bitiş tarihleri ve süreler (ekrandan, 00:20:00; 01:35:00; 01:45:00).
  - Dönemsel ve toplam tahmini maliyet formu: personel, seyahat, alet/teçhizat/yazılım/yayın, danışmanlık/hizmet alımı, malzeme, genel giderler (ekrandan, 00:25:00).
  - Rakip karşılaştırma tablosu: teknik özellikler, yerli ve yabancı rakip, "farklara ilişkin açıklama/analiz" sütunu (ekrandan, 00:30:00).
  - Ticari kazanç tablosu: yıllara göre müşteri sayısı, ürün miktarı, ortalama fiyat ve ciro; birim maliyet, satış fiyatı ve kazanç oranı (ekrandan, 01:25:00).
  - Ölçülebilir başarı kriterleri (yüzde hedefleri) ve çevik (agile) geliştirme süreci.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu derste hoca sunumlar hakkında akademik bir değerlendirme yapmaz; sunumları sırayla yönetir.
- Sunumlarda sorulan sorular (adsız)
  - Masa doluluğu, uygulamayı kullanmayan müşteriler için restoran çalışanının sisteme girişiyle güncellenir.
  - Yapay zekâ ile ön teşhis veren uygulamada, yönlendirilen vakaların sonucunun (doğru/yanlış) modele geri beslenmesi sorulur; grup, verilerin hastanelerde toplanacağını ve klinik testten sonra yayına çıkılacağını söyler.
  - Araç satış uygulamasında resmî işlemlerin nasıl bağlanacağı sorulur; grup, noterlerin güvenli ödeme web servis altyapısını kullanmayı planladığını söyler.
  - Nokta bulutundan model oluşturmanın mimarların kullandığı 3B modelleme programlarıyla farkı sorulur; grup, elle çizimin hata, yorgunluk ve zaman maliyetini azaltmayı hedeflediğini söyler.

## Kısa Tekrar Notları

- 1512 iş planı sunumunun tipik bölümleri: iş fikri, ürün/hizmet, yenilikçi yön, rakip analizi, pazar ve hedef kitle, iş paketleri ve Gantt şeması, ekip, maliyet ve finansman, ticari beklenti ve sürdürülebilirlik.
- İş paketleri genellikle: işletme kuruluşu → gereksinim analizi/kurulum → yazılım (en uzun süre) → mobil uygulama → son test → pazarlama.
- Maliyet formunda her kalemin toplam maliyet içindeki payı yüzde olarak verilir.
- Ciro = ürün miktarı × ortalama fiyat; maliyet üzerinden kazanç oranı = (satış fiyatı − maliyet) / maliyet.
- Gelir modelleri: abonelik, tek seferlik satın alma, reklam, kurumsal aylık üyelik, komisyon, hizmet bedeli.
- Başarı kriterleri ölçülebilir (yüzde) hedeflerle verilir.

## Detaylı Açıklamalar

- **Salgın yönetim sistemi:** Mobil uygulamada üç hesap türü vardır: bireysel kullanıcılar (QR kod okutma, bulaş riski analizi, risk bildirimi), kurumsal kullanıcılar (bulaş riski analizi, anlık bireysel kullanıcı analizi) ve admin kullanıcılar (bulaş riski takibi, anlık bireysel kullanıcı analizi) (ekrandan, 00:10:00). İşletme girişindeki QR kod okutulduğunda giriş kaydı tutulur; pozitif test sonucu gelen kullanıcı için aynı mekâna girmiş diğer kullanıcılara bildirim gönderilir. Mekânlar, son bir aydaki ziyaretçiler içinde hastalananların oranına göre yıldızla puanlanır. Yurt içindeki salgın takip uygulaması rakipten çok tamamlayıcı olarak görülür.
- **Şiir hediye platformu:** Sanatçıların ya da kullanıcının kendi sesiyle seslendirilen şiirler ses kaydı olarak ya da hediye kutusuyla gönderilir; aylık/yıllık abonelik ve tek şiir satın alma vardır. Maliyet formunda dört dönem için personel 18.000, alet/teçhizat/yazılım/yayın 21.025, danışmanlık 22.500, malzeme 2.500, genel giderler 16.075 TL; dönem toplamı 80.100 TL, yıllık toplam 320.400 TL'dir (ekrandan, 00:25:00). Python ile kontrol edildi: toplamlar tutarlıdır; payların hesabı yaklaşık 320.000 TL'ye göre yapılmıştır (örneğin danışmanlık için %28,125, tam toplamla %28,09).
- **Garsonsuz sipariş uygulaması:** Müşteri, uygulamaya üye kafe/restoranları görür, gitmeden masa doluluğunu görüp masa seçer ve sipariş verir, yemekten sonra uygulamadan öder. Rakip tablosunda yerli rakip (eve teslim sipariş platformu) ve yabancı rakip (yalnız kendi kafelerinde gel-al sipariş veren bir kahve zinciri uygulaması) karşılaştırılır (ekrandan, 00:30:00). Pazarlama planında ilk iki hafta ücretsiz deneme sözleşmesi, firmalara zorla indirim dayatılmaması, ilk siparişte %50 indirim ve havayolu mil sistemine benzer bir puan sistemi yer alır (ekrandan, 00:35:00).
- **Bebek refleksi ölçümü:** Slaytta altı yenidoğan refleksi sayılır: arama, yakalama, tonik ense, basma ve adımlama, aksırma-öksürme ve Moro (sıçrama) refleksi (ekrandan, 00:40:00). Moro refleksinde kol ve bacaklar gövdeden uzaklaşıp yeniden içe bükülür. Hiç refleks alınmaması sinir sistemi hasarına, tek taraflı refleks kol siniri felci ya da köprücük kemiği kırığına işaret edebilir. İş paketleri: yapay veri seti (video) oluşturma, mobil uygulama ve yapay zekâ modelinin geliştirilip test edilmesi, klinik ortamda doktor/teknisyen testleri. Rakip projeler bileğe bağlanan üç eksenli ivme ölçer ve web kamerası kullanır; bu proje yalnız telefon kullanır. Slaytta Türkiye için 2019'da 1.183.000, son 10 yıl ortalaması 1.283.000 doğum verilir (ekrandan, 00:45:00). <!-- BELİRSİZ: slayttaki dünya değeri "Ortalama 1.141.000 Mn" olarak yazılmış, sunan sözlü olarak 141 milyon diyor; birim tutarsız. -->
- **Hayvanseverler platformu:** Modüller: bilgilendirme, profil, eğitim, veteriner, evcil hayvan malzemeleri dükkânı, zaman akışı ve çevremdeki hayvanlar (ekrandan, 00:55:00). Uygulama içinden satış yapılmaz, dükkânların e-ticaret sayfalarına yönlendirilir; hayvan ticareti yapan dükkânlar platforma alınmaz (ekrandan, 00:50:00). Teknolojiler: Android için Kotlin/Java ve Android Studio, iOS için Swift/SwiftUI ve Xcode, yerel veri için SQLite, bulut veri için Firebase, konum için Google Haritalar platformu (ekrandan, 01:00:00). Native geliştirme performans için seçilir; belirsizlik nedeniyle çevik süreç tercih edilir. Başarı kriterleri yüzde hedefleriyle verilir (örneğin temel bilgi edinmede en az %75). Benzer ürünler tek ya da birkaç işleve odaklanır (ekrandan, 01:05:00).
- **Veteriner yönetim platformu:** Veterinerlerin tahlil sonuçlarını ortak platformda görmesi aynı testin tekrarını önler. Gelir modeli, veterinerler için aylık ücretli web platformu ve mobil kullanıcılar için hayvan bakıcılığı, gezdirme, gıda, malzeme gibi hizmetlerden komisyondur (ekrandan, 01:10:00). Tutundurma stratejisi, platformu veterinerlere ilk etapta ücretsiz vermek ve hayvan sahiplerini veterinerler üzerinden kazanmaktır.
- **Robotik çim biçme makinesi:** Hedef, 30 dakikada 6.000 m² biçme, 45 dB ses, yaklaşık 100 litre toplama kapasitesi ve uzaktan/sesli komutla belirli alanların biçilmesidir. Gövde için TP100 paletli tank şasesi (alüminyum alaşım şase, plastik tekerlek, yaklaşık 650 g), OLED ekran ve HC-SR04 ultrasonik mesafe sensörü kullanılacaktır (ekrandan, 01:20:00). Ticari kazanç tablosunda ciro yıllara göre 2.362.500, 4.000.000, 27.000.000 ve 68.000.000 TL; birim maliyet 4.500 TL, satış fiyatı 7.875 TL, kazanç oranı %75'tir (ekrandan, 01:25:00). Python ile kontrol edildi: ciro = ürün miktarı × ortalama fiyat tutarlıdır; %75 maliyet üzerinden kâr oranıdır, satış fiyatına göre kâr marjı yaklaşık %42,9'dur.
- **Güvenli araç alım satımı:** Satıcı teklif oluşturur, alıcı kabul edince bedel alıcının blokeli hesabına aktarılır; plaka sorgusunda araç alıcıya geçmişse bloke çözülüp para satıcıya geçer. Avantajlar: nakit taşıma riski yok, EFT saati beklenmez, yeni müşteri ve mevduat kazanımı (ekrandan, 01:30:00). Kullanılacak teknolojiler: Xamarin, Web API, SQL Server, Entity Framework, Visual Studio. Gantt şemasında beş iş paketi vardır: işletme kuruluşu, gereksinim analizi/kurulum, yazılım, mobil cihaz uygulaması, pazarlama (ekrandan, 01:35:00).
- **Nokta bulutundan 3B model:** Modeli olmayan yapılardan nokta bulutuyla üç boyutlu model oluşturulur; rakiplere göre farklar doğruluk, verimlilik ve zamandır (ekrandan, 01:40:00). Zaman çizelgesinde yazılım iş paketi veri seti ve veri tabanı oluşturmayı da içerir (ekrandan, 01:45:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
