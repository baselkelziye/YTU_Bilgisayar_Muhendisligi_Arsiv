# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin alanı: Pervasive and Mobile Computing
  - Dersin İngilizce karşılığı "Pervasive and Mobile Computing"tir (ekrandan, 00:15:00). Türkçe adı alanı tam karşılamadığı için hoca İngilizce adı özellikle vurgular.
  - Pervasive ve ubiquitous kavramları, bir hizmete her an, her yerden ve her cihaz üzerinden erişebilmeyi anlatır.
  - Alan; bulut bilişim, büyük veri, derin öğrenme ve mobil programlama gibi birçok konuya doğrudan dokunur.
  - Hocaya göre bu alanda teori yaklaşık %30, pratik yaklaşık %70 ağırlıktadır. Yeni teknolojiler genelde bilgisayar biliminin oturmuş teorileri üzerine inşa edilir.
  - Dersin amacı mobil programlamanın ince ayrıntıları değildir. Mobil işletim sistemlerine uygulama geliştirirken nelere dikkat edileceği konuşulur, ama programlama ağırlıklı bir ders değildir.
- Dersin hedefleri, çıktıları ve içeriği (ekrandan, 00:20:00)
  - Hedefler: küçük mobil cihazlar için uygulama geliştirmede yönergeler, tasarım ilkeleri ve deneyim kazandırmak (bağlam ve konum farkında servisler dahil); hücresel ağlara, kablosuz internete ve sensör cihazlarına bağlantıyı destekleyen kablosuz iletişim ve ağ ilkelerini tanıtmak; bu cihazlar üzerinden işlem (transaction) ve e-ticaret ilkelerini anlamak; mahremiyet dahil mobil hesaplamanın sosyal ve etik yönlerini kavramak.
  - Çıktılar: mobil hesaplama ilkelerini ve kavramlarını öğrenmek; teorik ve pratik konuları incelemek; mobil teknolojilerle mobil uygulama tasarlayıp gerçekleştirme yeteneği kazanmak.
  - İçerik: mobil sistemler ve teknolojiler, mobil işletim sistemleri, kablosuz iletişim, sensör ağları ve mobil teknolojilerle etkileşimleri, mobil hesaplama, mobil cihazlarda sensör verisi kullanan uygulamalar.
- Dönem boyunca işlenecek konular (ekrandan, 00:20:00)
  - Pervasive/ubiquitous ve mobil hesaplamaya giriş.
  - Çevresel zeka (ambient intelligence) ve bağlam farkında (context-aware) sistemler.
  - Sensör ağları.
  - Mobil cihazlar, işletim sistemleri ve geliştirme platformları.
  - Mobil cihazlardaki sensörler ve veri toplama.
  - Mobil cihazlarda veri yönetimi ve yerinde işleme (in-situ processing).
  - Makine öğrenmesi tekniklerinin mobil platformlarda uygulanması.
  - Akıllı telefonlardaki sensörler ve sensör verisi toplama.
  - Kitle kaynak kullanımı (crowdsourcing) ve açık veri (open data).
  - Kablosuz iletişim.
  - Mobil hesaplamada güvenlik ve mahremiyet.
  - Konum tabanlı servisler ve uygulamalar.
  - Nesnelerin interneti (IoT).
- Konuların hocanın anlatımıyla kapsamı
  - Bağlam farkında sistemler: insanların davranışlarını ve duygularını bulundukları ortamda algılayıp analiz ederek çözüm üretme ihtiyacından doğdu. Akıllı binalar, akıllı ulaşım ve giyilebilir teknolojiler (akıllı saat, iş yerlerinde akıllı eldiven ve baret) bu ihtiyacın örnekleridir. Bazı giyilebilirler (Google Glass) tutunamadı, akıllı saatler ise uzun mücadeleden sonra yaygınlaştı.
  - Sensör ağları: askeri, sonra tarım ve çevre uygulamalarıyla başladı; bugün büyük ölçüde IoT'ye evrildi. Bu dönüşümün en önemli yapı taşı mobil telefonlardır.
  - Sensörler ve veri toplama: hangi sensörle ne verisi toplanır, sensör seçimi nasıl yapılır; parasal maliyetin yanında veri toplamanın enerji maliyeti ve veri aktarmanın bant genişliği ihtiyacı.
  - Veri yönetimi ve yerinde işleme: veri cihazda mı saklanacak, buluta mı taşınacak? Ham veri mi taşınmalı, yoksa cihazda işlenip yalnız karar ya da çıkarım mı merkeze iletilmeli?
  - Mobilde makine öğrenmesi: akıllı telefonlar oldukça yetenekli hale geldi; akıllı saatler hâlâ daha kısıtlı. Derin öğrenme modeli bu cihazlara entegre edilebilir mi, eğitim ve test nerede yapılır, model nerede çalışır, ne kadar veri saklanır gibi sorular.
  - Crowdsourcing ve açık veri: belediye ve kurumların topladığı verileri herkese açması; araştırma gruplarıyla kazan-kazan modeli. Stack Overflow en güzel örneklerdendir.
  - Kablosuz iletişim: her an her yerden işlem yapabilmenin tek yolu olduğu için alanın kalbindedir. Protokollerin enerji tüketimi, kısıtları, açık/kapalı ve engelli/engelsiz alanlarda kullanımı tartışılır.
  - Güvenlik ve mahremiyet: taşınan verinin korunması, mobil cihazlardaki zararlı yazılımlar (malware). KVKK ve GDPR ile kullanıcı onayı alma ve bazı verileri karartarak (anonimleştirerek) kullanma zorunluluğu.
  - Konum tabanlı servisler: dış mekânda GPS, iç mekânda bina içi konum takibi. Büyük binalarda yönlendirme, alışveriş merkezlerinde ve mağazalarda müşterinin hangi bölümde ne kadar vakit geçirdiğini pazarlama için tespit etme.
  - IoT ve büyük veri: cihazlar arası protokoller ve normal protokollerden farkları.
- Sensör ağları ile IoT arasındaki fark
  - İkisinde de sensör, işlemci, bellek vardır ve veri işlenir; IoT kavramı yepyeni bir şeymiş gibi pazarlanmıştır.
  - Sensör ağı daha çok dış ortamlar için düşünülmüş, özel donanımların (düğüm, node) tasarlandığı bir yapıdır; askeri ve çevresel uygulamalarda kullanılır, etrafa dağıtılan düğümler çevre kirliliği yaratabilir.
  - IoT'de zaten kullanılan eşyalar (çamaşır makinesi, bulaşık makinesi, akıllı ev) içine elektronik tasarım konularak akıllı hale getirilir. Bu yüzden IoT daha anlamlı hale gelmiştir.
- Mobil uygulama trendinin seyri
  - 1990'ların sonunda statik HTML ile web sayfası yapmak, ardından PHP ile dinamik web programcılığı çok kazançlı dönemler oldu.
  - 2007 civarında iOS ve Android ile akıllı telefon kavramı yaygınlaştı; 2010'larda mobil uygulama patlaması yaşandı.
  - Hocaya göre bugün mobil uygulama geliştirmede belli bir doygunluğa gidiliyor. Araştırma tarafında ise işletim sistemi seviyesinde zararlı yazılım tespiti, güvenlik, parmak izi ve yüz tanıma ile hızlı kilit açma gibi konular hâlâ açık.
- Crowdsourcing örnekleri
  - Taksi çağırma: yağmurda taksi bulamazken binanın arkasındaki yakın taksiyi çağıramama problemi; konum paylaşımıyla çözülen bu fikir crowdsourcing kavramını hayatımıza sokan işlerden biridir.
  - Trafik tahmini: önceden köprüden geçen birine sormak, sonra İBB'nin renkli trafik haritası, bugün Google Maps ve Yandex'in kullanıcılardan toplanan hızlarla "47 dakika" gibi dakika düzeyinde tahmin vermesi. Belli bir lokasyondaki kaza geçmişi risk parametresi olarak denkleme katılabilir.
  - Yol durumu: araçlardan toplanan verilerle buzlanma, çukur ve tümsek tespiti ve belediyeye bildirme; yolların kalitesi için araç gezdirmeden rapor çıkarma. Telefon sensörleri hassasiyet açısından sorunlu olduğundan ek filtreler gerekir; araca gömülü sensör daha iyidir. Bu verilerle risk haritaları çıkarılabilir.
- Tahmin ve karar destek sistemleri
  - Bugün en fazla 1-2 saatlik trafik durumu iyi öngörülebiliyor. Yarın havalimanına ne kadar sürede gidileceği için verilen tahmin (yarım saat ile bir saat arası) çok geniş ve çözünürlüğü düşük.
  - Hava tahmini yıllar içinde 2-3 günden yaklaşık 15 güne kadar yüksek doğrulukla yapılır hale geldi, ama örüntüler kayabiliyor; farklı kaynaklar farklı tahmin verebiliyor.
  - Bu sistemler karar destek sistemleridir: son yorumu hâlâ insan yapar. Hocaya göre yapay zeka yakın zamanda kesin karar verici değil, destekleyici konumda olacak. Satranç gibi kuralları belli alanlarda ise bilgisayar bütün kombinasyonları hesaplayabildiği için üstündür.
- Otonom araçlar ve kontrollü ortamda test
  - Otonom araçlar lidar, kamera, GPS gibi birçok sensör kullanır; aynı sensörü birden fazla açıdan kullananlar vardır.
  - Öğrenme sürecinde yaratabilecekleri olumsuz olaylar kabul edilemeyebilir; bu yüzden test, değişken sayısı azaltılmış kontrollü ortamlarda yapılmalıdır.
  - Derste önerilen ortamlar: haritalanmış, trafiğe kapalı kampüs; hocanın tercihi olarak metrobüs hattı (sürücüsüz metrolar örneği); şehir dışı alanlar ve otoyollar.
- İnsan duyuları ve sensörler
  - İnsanın beş duyusu (görme, duyma, tatma, dokunma, koklama) vardır. Tat ve koku şu an teknolojide rekabet noktasında değildir.
  - Ölçüm yapmada teknolojik cihazlar insandan çok daha iyidir: tepede bulunulan yüksekliği insan tahmin eder, sensör (belli hata payıyla) ölçer. Sisli havada uçağın sensörsüz inme şansı yoktur.
  - Bu yüzden doğru sensör seçimi önemlidir: jiroskop, ivmeölçer, GPS, iç mekân konumu için Bluetooth Low Energy (beacon), kamera, kısa mesafede çalışan ultrasonik park sensörleri. Tek sensör yeter mi, aynı anda birden fazlası mı kullanılmalı, maliyet ve yetenekler birlikte değerlendirilmelidir.
- Yedeklilik ve aykırı değer tespiti
  - Sensör bozulma olasılığına karşı yedekli (redundant) yapı kurulur: birden fazla sensör konur, uç değer üreten sensör aykırı değer tespitiyle dışarıda bırakılır.
  - Orman yangını örneği: 5 sensör 28 derece, 1 sensör 72 derece diyorsa çoğunluk oylaması (majority voting) ile karar verilir. Burada kollektif öğrenme yaklaşımları da devreye girer.
- Mobil ve giyilebilir cihazlarda sensörler
  - Bağlam farkındalığı için cihaz üzerindeki sensörler vazgeçilmezdir. Dizüstü bilgisayarda jiroskop, ivmeölçer pek aranmaz, ama telefonda oyun ve düşme tespiti için önemlidir.
  - Giyilebilirler adım sayma ve egzersiz takibiyle başladı; bugün kalp ritim düzensizliği, kan oksijeni, tansiyon gibi sağlık ölçümlerine yöneldi.
  - Küçük cihaza konan sensörün hata payı, daha büyük cihazdaki jiroskop ya da ivmeölçere göre daha yüksektir.
- Düşme tespiti ve çarpma şiddeti tahmini
  - Senaryo: ıssız bir yerde araç ya da bisiklet çarpması, kişi bayılıyor. Saat ya da telefondan düşme tespit edilir; belli süre hareketsizlik varsa acil durum bildirilir, kişi kalkıp hareket ediyorsa bildirim gerekmez.
  - Düşme tespiti 2012'den 2020'ye kadar çok sayıda çalışmanın konusu oldu. Hocanın ilgilendiği açık soru çarpmanın şiddetini, hatta aracın hızını tahmin etmekti; bu bilgi sağlık ekibine yararlı olur.
  - Derste konuşulan zorluklar: telefonun masaya sert konmasını gerçek düşmeden ayırmak (yanlış alarm), telefonun vücuttaki konumu, tek sensöre dayanmanın yanıltıcılığı, saat ve telefon verisini birleştirme, kulaklık gibi başka konumlardan veri alma.
  - Cihazın vücuttaki konumu (kalça bölgesi ya da üst gövde) ölçülen ivme değerini değiştirir; sistem buna göre tasarlanmalıdır.
  - Hocanın eski bir çalışmasında (yaklaşık 2013) manken ve go-kart aracıyla deney yapılmış, çarpma şiddeti düşük, orta, yüksek olarak 3 sınıfta yaklaşık %70 başarıyla tahmin edilmiştir.
  - Kısıt: o dönem Android, ivmeölçeri yazılımsal olarak ±2g aralığında çalıştırıyordu; her çarpma 2g'de doyuma ulaşıyordu. Dar aralık, oyunlardaki küçük hareketlere hassasiyet sağlamak için seçilmişti. Bugün telefon ivmeölçerlerinde ±8g, hatta ±16g konuşulabiliyor.
  - Fizik tarafı: $F = m\,a$, etki-tepki ve araç ile kişinin kütle oranı gibi dinamikler işin içindedir.
- Dijital adli bilişim
  - Cihaz verileri ileride adli süreçlerde kullanılabilir: çarpma anı ve şiddeti, kaza anında telefonun kullanılıp kullanılmadığı (aktif loglar). Ses ve görüntü kayıtları gibi bu verilerin de manipülasyonu mümkündür; bu konu veri bütünlüğü, mahremiyet ve güvenlikle ilgilidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlam farkında sistemler
  - Hocaya göre bugün en önemli sistemlerin başında gelir; insan davranışını ve duygusunu algılamak çözümlerin merkezine geçti.
- Kablosuz iletişim alanın kalbidir
  - Her an her yerden işlem yapabilmenin tek yolu kablosuz iletişimdir. Güvenlik de bununla birlikte olmazsa olmazdır.
- Sensör seçimi ve sensör özellikleri
  - Sensörler ölçümde insandan çok daha iyidir; tasarım yapılırken bu unutulmamalıdır.
  - ±2g örneği, kullanılacak sensörün özelliklerini (aralık, hassasiyet, yazılım kısıtı) çok iyi incelemek gerektiğini gösterir.
- Kontrollü ortam
  - Otonom araç ve robot gibi sistemlerde tasarım ve test kontrollü, değişkenleri azaltılmış ortamlardan başlamalıdır.
- Intrusive ve non-intrusive çözümler
  - Kişinin konforunu bozan, üzerine cihaz bağlanan ya da sürekli veri girişi isteyen çözüm intrusive'dir. Zaten taşınan telefon ya da saatten veri toplamak non-intrusive'dir. Genç ve sağlıklı kullanıcılar ek cihaz takmak istemez; yaşlılar gibi sağlık açısından kritik gruplar gönüllü takabilir.
- Araştırma kültürü
  - Yüksek lisansın amacı bilgiyi bulmanın ötesinde araştırma yapmayı öğrenmektir. Dergi ve konferanslar (IEEE, ACM, Elsevier, Springer) takip edilmelidir.
  - Kariyerde ana alanın yanında "cepte" bir yan alan bulundurmak, güncel kalmak için önemlidir.

## Kısa Tekrar Notları

- Pervasive/ubiquitous: her an, her yerden, her cihazdan erişim.
- Sensör ağı: dış ortam, özel düğüm donanımı. IoT: mevcut eşyaya gömülen elektronik. Köprü: akıllı telefon.
- Veri toplamanın maliyeti: para, enerji, bant genişliği.
- Yerinde işleme: ham veri yerine cihazda üretilen karar ya da çıkarımı merkeze göndermek.
- Crowdsourcing örnekleri: taksi çağırma, trafik süresi tahmini, çukur/tümsek/buzlanma tespiti, Stack Overflow.
- Uzun vadeli, yüksek çözünürlüklü seyahat süresi tahmini hâlâ çözülmemiş bir problem.
- Tahmin sistemleri karar destek sistemleridir; son karar insanda.
- Otonom sistemler kontrollü ortamda test edilir (kampüs, metrobüs hattı, otoyol).
- Sensörler ölçümde insandan üstün; yedeklilik + aykırı değer tespiti + çoğunluk oylaması.
- Düşme tespiti: düşme + hareketsizlik süresi; zorluk yanlış alarm ve cihaz konumu.
- Eski Android ivmeölçer kısıtı ±2g; bugün ±8g ve ±16g.
- Intrusive: konforu bozan; non-intrusive: zaten taşınan cihazdan veri.

## Detaylı Açıklamalar

Bu ilk derste hoca, dersin alanını "Pervasive and Mobile Computing" olarak tanımladı ve bu alanın bulut bilişim, büyük veri, derin öğrenme ve mobil programlamanın kesişiminde durduğunu anlattı. Dersin amacı programlama ayrıntısı değil; mobil teknolojilerle problemlerin nasıl çözüldüğünü, hangi teknolojilerin yükseldiğini ve bunların altında yatan kavram ve terminolojiyi kazandırmaktır. Ekranda gösterilen ders izlencesinde kaynak kitaplar (Fundamentals of Mobile and Pervasive Computing, The Mobile Wave, Mobile Computing Principles, Age of Context, Sensing and Systems in Pervasive Computing, Ubiquitous Computing) ve izlenecek dergi ile konferanslar (IEEE Transactions on Mobile Computing, Elsevier Pervasive and Mobile Computing, Springer Mobile Networks and Applications, IEEE Internet of Things, ACM MobiHoc, IEEE PerCom, ACM MobiCom, IEEE MASS, IEEE ISSNIP) listelendi (ekrandan, 00:15:00). Hoca dersi kitap üzerinden değil, bu yayınları takip ederek her yıl güncellediği konular üzerinden işlediğini söyledi.

Sensör ağları ile IoT karşılaştırması dersin önemli kavramsal noktalarından biridir. Sensör ağlarında ormana ya da araziye dağıtılan, özel olarak tasarlanmış düğümler vardır. IoT'de ise zaten kullandığımız eşyanın içine elektronik konur. Teknik olarak ikisi de sensör, işlemci ve bellekten oluşan, veri işleyen yapılardır; fark, uygulama alanında ve donanımın kimin için tasarlandığındadır. Hocaya göre bu iki dünyayı birleştiren yapı akıllı telefondur.

Crowdsourcing konusu taksi ve trafik örnekleriyle açıldı. Trafik tahmini, kullanıcı telefonlarından toplanan hız verisinin işlenmesiyle renkli haritalardan dakika düzeyinde süre tahminine geldi. Aynı mantık yol yüzeyi için de kullanılabilir: araçlardan ve telefonlardan toplanan ivme verisiyle çukur, tümsek ya da buzlanma tespit edilip belediyeye bildirilebilir. Ancak telefon sensörleri hassasiyet açısından zayıf olduğundan ek filtreleme gerekir. Hoca, sıradaki büyük talebin uzun vadeli ve yüksek çözünürlüklü tahmin olduğunu söyledi: bugün yarınki yolculuk için verilen yarım saat ile bir saat arası tahmin, dakika düzeyinde tahmine alışmış biri için çok geniştir. Hava tahminindeki gelişme bu açıdan örnek gösterildi. Bu sistemler son kararı insana bırakan karar destek sistemleridir.

Ders, insan duyuları ile sensörlerin karşılaştırılmasıyla sensör seçimine bağlandı. Hoca, ölçüm yapma konusunda teknolojik cihazların insandan çok daha iyi olduğunu yükseklik ve sisli havada uçak indirme örnekleriyle anlattı. Sensör bozulmasına karşı birden fazla sensör konması ve uç değerin dışarıda bırakılması gerekir. Orman yangını örneğinde 5 sensör 28 derece, 1 sensör 72 derece okuyorsa çoğunluk oylamasıyla 28 derece kabul edilir. Bu küçük örnek, sensör verisinin işlenmesinde kollektif karar yaklaşımlarının yerini gösterir.

Son bölümde düşme tespiti ve çarpma şiddeti tahmini problemi tartışıldı. Basit karar kuralı "düştü ve belli süre hareketsiz kaldıysa acil durum" biçimindedir. Daha zor problem, çarpmanın şiddetini ya da aracın hızını tahmin etmektir. Hocanın eski çalışmasında şiddet üç sınıfta yaklaşık %70 başarıyla tahmin edilmiş, ama o dönemki Android ivmeölçerinin yazılımsal olarak ±2g ile sınırlı olması her çarpmanın 2g'de doyuma ulaşmasına yol açmıştır. Bu dar aralık oyunlardaki küçük hareketlere hassasiyet için seçilmişti. Örnek, bir sensörün yalnız varlığının değil, aralığının ve yazılımsal kısıtlarının da incelenmesi gerektiğini gösterir. Hoca ayrıca bu tür verilerin ileride adli süreçlerde (çarpma anı, kaza anında telefon kullanımı) kullanılabileceğini, bunun da veri bütünlüğü ve mahremiyet sorularını beraberinde getirdiğini belirtti.

<!-- BELİRSİZ: 01:58:40 civarında altyazı "yazılımsal olarak ±4g'yi desteklemesine rağmen Android yazılımsal olarak ±2g" diyor; ilk "yazılımsal" büyük olasılıkla "donanımsal" olmalı (sensör donanımı ±4g destekliyordu). -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
