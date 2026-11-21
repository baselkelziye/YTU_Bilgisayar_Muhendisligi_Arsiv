# Ders 1 Genişletilmiş Notu: Pervasive ve Mobil Hesaplamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Alanı ve İşleyişi
- 2. Kaynaklar, Hedefler ve Konu Akışı
- 3. Sensör Ağlarından IoT'ye
- 4. Mobil Uygulama Trendinin Seyri
- 5. Crowdsourcing: Taksiden Trafik Tahminine
- 6. Sıradaki Talep: Uzun Vadeli Tahmin ve Karar Destek Sistemleri
- 7. Otonom Araçlar ve Kontrollü Ortamda Test
- 8. İnsan Duyuları ve Sensörler
- 9. Düşme Tespiti ve Çarpma Şiddeti Tahmini
- 10. Sensör Verisi ve Dijital Adli Bilişim
- Örnek Sorular

## 1. Dersin Alanı ve İşleyişi

Dersin İngilizce karşılığı "Pervasive and Mobile Computing"tir (ekrandan, 00:15:00). Hoca, Türkçe adın anlatmak istediği alanı tam karşılamadığını, bu yüzden İngilizce adı özellikle vurguladığını söyledi. Pervasive ve ubiquitous kavramları, bir hizmete her an, her yerden ve her cihaz üzerinden erişebilmeyi temsil eder. Bu alan bugün bulut bilişim, büyük veri, derin öğrenme ve mobil programlama gibi birçok konuya doğrudan dokunur.

> **Ek bilgi (derste anlatılmadı):** "Ubiquitous computing" terimi büyük olasılıkla 1980'lerin sonunda Mark Weiser tarafından ortaya atılmıştır. Fikir, hesaplamanın masaüstü bilgisayardan çıkıp gündelik nesnelere ve ortama dağılmasıdır. "Pervasive computing" de büyük ölçüde aynı anlamda kullanılır.

Hoca dersin yaklaşımını şöyle özetledi: Mobil teknolojilerle problemler nasıl çözülüyor, gidişat nereye doğru, hangi teknolojiler yükselen trendde ve bunların altında yatan fikir ve kavramlar neler? Ders boyunca özellikle mobil teknolojilerdeki terminoloji aktarılacak. Hocaya göre bu alanda teori yaklaşık %30, pratik yaklaşık %70 ağırlıktadır. İnsanın hayatına dokunan teknolojiler varlığını sürdürür; bilgisayar bilimi de artık belli kuramları oturtmuş olduğu için yeni teknolojiler genelde bu teorilerin üzerine inşa edilir, yepyeni büyük teoriler üretmek kolay değildir. Bu yüzden derste bazı teknolojilerin arka planına da bakılacak.

Ders slaytlar üzerinden yürür, ama konu konuyu açar ve örnekler tartışılır. Hoca interaktif bir ders yürütmeyi sevdiğini, "böyle bir problemde ne yaparsınız, hangi yaklaşım uygulanır" gibi sorular soracağını ve öğrencilerin fikirlerini süzgeçten geçirmeden paylaşmasını beklediğini söyledi. Dönem içinde birbirine bağlı olması planlanan veri üzerinde çalışılacak ödevler ve dönem sonunda bir proje olacak. Konuların mümkün olduğunca gerçek hayattaki çözümler üzerinden seçilmesi, öğrencinin kendi araştırmasıyla konu bulması ve mümkünse veriyi alıp işleyen bir programlama çalışması yapması bekleniyor; tasarım, mimari ya da protokol çalışması da olabilir. Hedeflerden biri ders içindeki araştırmalardan konferans bildirisi ya da makale düzeyinde bir yayın çıkmasıdır. Çevrim içi derste yaklaşık 40 dakikada bir 10 dakikalık ara verilecek.

Hoca, dersin mobil programlamanın ince ayrıntılarına girmediğini özellikle belirtti. Mobil işletim sistemlerine uygulama geliştirirken nelere dikkat edileceği konuşulacak, ama programlama anlamında çok fazla bir şey yapılmayacak.

> **Hocanın vurgusu:** Yüksek lisans, bilgiyi bulmanın ötesinde araştırma yapmayı öğrenmek demektir. Bu kültürü edinmek hem tez sürecini hem iş hayatını kolaylaştırır.

Araştırma için Google Scholar üzerinden Elsevier, IEEE, ACM ve Springer gibi alandaki yayınevlerinin makalelerine kütüphane proxy'si ya da kütüphane ayarlarıyla uzaktan erişilebileceği söylendi.

## 2. Kaynaklar, Hedefler ve Konu Akışı

### 2.1 Kaynaklar

Ekranda gösterilen izlencedeki kaynak kitaplar şunlardır (ekrandan, 00:15:00):

- Frank Adelstein, Sandeep K. S. Gupta, Golden Richard III, Loren Schwiebert, *Fundamentals of Mobile and Pervasive Computing*, 2004.
- Michael Saylor, *The Mobile Wave: How Mobile Intelligence Will Change Everything*, 2012.
- Reza B'Far, *Mobile Computing Principles: Designing and Developing Mobile Applications with UML and XML*, 2004.
- Robert Scoble, Shel Israel, *Age of Context: Mobile, Sensor, Data and the Future of Privacy*, 2013.
- Dan Chalmers, *Sensing and Systems in Pervasive Computing: Engineering Context Aware Systems*, 2011.
- Stefan Poslad, *Ubiquitous Computing: Smart Devices, Environments and Interactions*, 2009.

Yardımcı kaynak olarak dergi ve konferans bildirileri gösterildi. Dergiler: IEEE Transactions on Mobile Computing, Elsevier Pervasive and Mobile Computing, Springer Mobile Networks and Applications, IEEE Internet of Things. Konferanslar: ACM MobiHoc (Mobile Ad Hoc Networking and Computing), IEEE PerCom (Pervasive Computing and Communications), ACM MobiCom (Mobile Computing and Networking), IEEE MASS (Mobile Ad Hoc and Sensor Systems), IEEE ISSNIP (Intelligent Sensors, Sensor Systems and Information Processing). Hoca bu kitapların güzel olduğunu, ama dersi kitap üzerinden işlemediğini; bu yayınları takip ederek konuları her yıl güncellediğini söyledi. Bu dergi ve konferanslar, öğrencilerin araştırma konusu ararken başvurabileceği kaynaklardır.

### 2.2 Hedefler, çıktılar ve içerik

İzlencedeki tabloya göre (ekrandan, 00:20:00):

- **Hedefler:** Küçük mobil cihazlar için uygulama geliştirmede yönergeler, tasarım ilkeleri ve deneyim kazandırmak (bağlam ve konum farkında servisler dahil); hücresel ağlara, kablosuz internete ve sensör cihazlarına bağlantıyı destekleyen kablosuz iletişim ve ağ ilkelerini tanıtmak; bu cihazlar üzerinden mobil iş kavramlarını destekleyen işlem ve e-ticaret ilkelerini anlamak; mahremiyet dahil mobil hesaplamanın sosyal ve etik konularını kavramak.
- **Çıktılar:** Mobil hesaplama ilkelerini ve kavramlarını öğrenmek; mobil hesaplamanın teorik ve pratik konularını incelemek; mobil teknolojileri kullanarak mobil uygulama tasarlama ve gerçekleştirme yeteneği kazanmak.
- **İçerik:** Mobil sistemler ve teknolojiler; mobil işletim sistemleri; kablosuz iletişim; sensör ağları/uygulamaları ve mobil teknolojilerle etkileşimleri; mobil hesaplama; mobil cihazlarda sensör verisini kullanan mobil uygulamalar.

### 2.3 Konu akışı ve hocanın konu tanıtımları

İzlencedeki geçici programda dönemin konuları şu sırayla verildi (ekrandan, 00:20:00): pervasive/ubiquitous ve mobil hesaplamaya giriş; çevresel zeka (ambient intelligence) ve bağlam farkında sistemler; sensör ağları; mobil cihazlar, işletim sistemleri ve geliştirme platformları; mobil cihazlardaki sensörler ve veri toplama; mobil cihazlarda veri yönetimi ve yerinde işleme; makine öğrenmesi tekniklerinin mobil platformlarda uygulanması; akıllı telefonlardaki sensörler ve sensör verisi toplama; crowdsourcing ve açık veri; kablosuz iletişim; mobil hesaplamada güvenlik ve mahremiyet; konum tabanlı servisler ve uygulamalar; nesnelerin interneti (IoT). Hoca konuları sırayla şöyle tanıttı.

**Çevresel zeka ve bağlam farkında sistemler.** Hocaya göre bağlam farkında (context-aware) sistemler şu anda en önemli sistemlerin başında geliyor. Son on yıla kadar standart işler yapılmaya çalışılırken artık insanların davranışları ve duyguları ön plana çıktı. Onları bulundukları ortamda izleyerek, hayatlarındaki davranışları analiz ederek çözüm getirme ihtiyacı doğdu. Bu ihtiyaç akıllı binaları, akıllı ulaşımı ve giyilebilir teknolojileri tetikledi. Bazı teknolojiler (Google Glass gibi) büyük vaatle doğdu ama devam edemedi. Akıllı saatler ise uzun süre mücadele ettikten sonra kendini ispatladı. Yine de giyilebilir teknolojilerin tam yaygınlaştığı söylenemez; daha çok iş yerlerinde akıllı eldiven, akıllı baret gibi ürünler kullanılıyor. Bunlar da etrafta ne olup bittiğini algılama, yani bağlam ihtiyacını gösteriyor.

**Sensör ağları.** Hikaye askeri uygulamalarla, sonra tarım ve çevre uygulamalarıyla hayatımıza giren kablosuz sensör ağlarıyla başlıyor ve bugün IoT'ye dönüşüyor. Sensör ağı kavramı hâlâ var ve çalışılıyor, ama büyük ölçüde IoT'ye evrilmiş durumda. Hocaya göre bu dönüşümü sağlayan en önemli yapı taşı mobil telefonlardır.

**Mobil cihazlar ve platformlar.** Mobil cihazlar, üzerlerinde çalışan işletim sistemleri (bazılarında işletim sistemi yoktur) ve platformların özellikleri tartışılacak.

**Sensörler ve veri toplama.** Mobil cihazlardaki sensörlerle neler yapılabileceği, hangi sensörle hangi verinin toplandığı ve tasarımda sensör seçiminin nasıl yapılması gerektiği incelenecek. Burada yalnız parasal maliyet değil, veri toplamanın enerji maliyeti ve veri aktarmadaki büyüklükten kaynaklanan bant genişliği ihtiyacı da hesaba katılır.

**Veri yönetimi ve yerinde işleme.** Toplanan veri nerede, nasıl saklanacak? Cihazda mı kalacak, buluta mı gidecek, arada bir yapı mı kurulacak? Burada yerinde işleme (in-situ processing) kavramı gelir: Veriyi ham olarak mı taşımalıyız, yoksa cihazda işleyip bir karar ya da çıkarım üretip yalnız onu mu merkeze iletmeliyiz?

**Mobil platformlarda makine öğrenmesi.** Sunucularda eğitim ve test yapmaya, eğitmenli ve eğitmensiz öğrenme yöntemlerini koşmaya alışkınız. Akıllı telefonların kısıtları son yıllarda büyük ölçüde aşıldı, cebimizdeki telefonlar oldukça yetenekli hale geldi. Yeni zorluk akıllı saatlerdir; kapasiteleri telefona göre geride kalıyor. Bu cihazlarda hangi teknikler uygulanabilir, derin öğrenme modelleri entegre edilebilir mi, eğitim ve test nerede yapılır, model nerede çalışır, yeniden ayarlamak (refine) gerekir mi, cihazda eğitim yapılıyorsa ne kadar veri saklanmalı gibi sorular tartışılacak. Veri saklama sorusu güvenlik konusuna da bağlanır.

**Crowdsourcing ve açık veri.** Hoca crowdsourcing'i çok önemli bir kavram olarak niteledi; birçok çözümde uygulanıyor. Açık veri ise belediyelerin ve kurumların topladığı veriyi herkese açması, araştırma gruplarının bundan yararlanmasıdır; bu bir kazan-kazan modelidir. Hocaya göre bunun en güzel örneklerinden biri Stack Overflow'dur.

**Kablosuz iletişim.** Pervasive ve mobil hesaplamanın kalbindedir, çünkü her an her yerden işlem yapabilmenin tek yolu kablosuz iletişimdir. Hangi protokolün ne kadar enerji tükettiği, kısıtları, nerelerde kullanılabileceği (açık alan, kapalı alan, engelli ve engelsiz alan) tartışılacak.

**Güvenlik ve mahremiyet.** Kablosuz iletişim varsa güvenlik olmazsa olmazdır: verinin taşınma sırasında korunması ve mobil cihazlardaki sorunlar, örneğin zararlı yazılımlar (malware) ve bunlara karşı yaklaşımlar. Mahremiyet son yıllarda çok daha önem kazandı; Türkiye'de KVKK, yurt dışında GDPR ile artık istenen veri alınıp işlenemiyor. Hem kullanıcı onayı almak hem de bazı verileri karartarak kullanmak gerekiyor.

**Konum tabanlı servisler.** Hocaya göre en sık kullanılan uygulamaların başında gelir. Yalnız dış mekânda GPS değil, bina içindeki konumu takip etmek de kritik hale geldi. Büyük binalarda yönlendirme, alışveriş merkezlerinde gezinme davranışının incelenmesi, bir mağazada hangi bölümde ne kadar vakit geçirildiğinin pazarlama aracı olarak tespiti bu konunun örnekleridir.

**IoT.** Cihazlar arasındaki protokoller, normal protokollerden farkları ve gidişat; son haftada büyük veriyle birlikte ele alınacak.

## 3. Sensör Ağlarından IoT'ye

Hoca, "veri bilimi" (data science) kavramının aslında bilgisayarcıların hep yaptığı veriyle çalışma işini yeniden adlandırdığını, sensör ağlarının IoT'ye dönüşme hikayesinin de buna benzediğini söyledi. IoT öyle anlatıldı ki yepyeni bir konsept gelmiş gibi göründü. Oysa ikisinde de sensör, işlemci ve bellek vardır ve veri işlenir.

Fark şuradadır. Sensör ağı daha çok dış ortamlar için düşünülmüş, özel donanımların tasarlandığı bir yapıdır. Bir düğüm (node) tasarlanır ve araziye dağıtılır; bu daha çok askeri alanda ve çevresel uygulamalarda hâlâ devam eder. Ancak dağıtılan düğümlerin birçoğu zarar görür ve çevre kirliliği yaratabilir. IoT'de ise zaten kullanılan eşyalar akıllı hale getirilir: çamaşır makinesi, bulaşık makinesi, akıllı ev. Eşyanın içine özel bir elektronik tasarım konur. Eşya zaten kullanıldığı için IoT çok daha anlamlı hale geldi.

## 4. Mobil Uygulama Trendinin Seyri

Hoca teknoloji trendlerini dönemlerle anlattı. 1990'ların sonunda yalnız HTML ile web sayfası yapmak çok kazançlıydı. Sonra PHP ile dinamik web programcılığı geldi ve yaklaşık on yıl o alanda iyi kazançlar elde edildi; 2010'dan sonra bu trend yavaş yavaş azaldı. 2007 civarında iOS ve Android'in duyurulmasıyla akıllı telefon kavramı konuşulmaya başlandı ve 2010'larda mobil uygulama patlaması yaşandı.

Hocaya göre mobil programlama hâlâ popüler, mobilde stabil bir kariyer ve iyi bir kazanç mümkün; ama uygulamaya yönelik Ar-Ge belli bir hız kaybetti ve uygulama geliştirmede bir doygunluğa gidiliyor. Araştırma tarafında ise hâlâ çok güzel konular var: mobil işletim sistemi seviyesinde zararlı yazılım (malware) tespiti, güvenlik, yapay zekayla parmak izi tanıma ve yüz tanımayla (Face ID) telefonun anında açılması gibi.

> **Hocanın vurgusu:** Kariyerde ana alanın dışında bir yan alanı "cepte" tutmak gerekir. Sıkışıldığında bu alan bir joker gibi kullanılır. Güncel takip edilmezse belli bir süre sonra sıradan olunur.

## 5. Crowdsourcing: Taksiden Trafik Tahminine

### 5.1 Taksi çağırma fikri

Hoca, 2010'ların başında aklına gelen bir taksi çağırma uygulaması fikrini anlattı. Fikir şuydu: Yağmur yağıyor, zor durumdasınız. Binanın arkasında, görmediğiniz bir noktada çok yakınınızda bir taksi var, ama onu çağıramıyorsunuz. Konum bilgisinin paylaşılmasıyla bu problem çözülür. Hocaya göre bu tür işler crowdsourcing kavramının hayatımıza girmesini sağlayan en önemli örneklerdendir. O dönemde bu tarz projeler azdı; son yıllarda arka arkaya girişim fikirleri çıktı.

### 5.2 Trafik süresi tahmini

Büyük firmalar özelinde Yandex ve Google Maps, trafiği tahmin etme işini yine crowdsourcing yaklaşımıyla hayatımıza soktu. Gelişim şöyle oldu:

- İlk dönemde en iyi ihtimalle yarım saat önce köprüden geçmiş birine "trafik nasıl" diye sorulurdu.
- Sonra İBB renkli bir harita sundu: kırmızı, turuncu, yeşil. Kullanıcı buna bakıp "herhalde 40 dakikada gideriz" diye kendi hesabını yapıyordu.
- Bugün "47 dakika" gibi dakika düzeyinde ve çok yüksek oranda doğru tahminler veriliyor.

Bu tahminlere başka parametreler de eklenebilir. Bir lokasyonda belli sayıda kaza olmuşsa bu risk parametresi olarak denkleme konur ve tahmin 47 yerine 52 dakika olabilir. Ama yolda bir tır devrilmesi gibi öngörülemeyen olaylar tahmini tamamen bozabilir.

### 5.3 Araçlardan toplanan veri ve yol durumu

Hoca, Yandex ve Google'dan daha ne talep edilebileceğini sordu. Bir öğrenci, araçların içindeki bilgisayarın topladığı veriden, dışarıda kamera olmadan yolun buzlanma ve kayma oranlarını çıkarıp merkeze aktaran ve trafik haritası gibi bir buzlanma/çakıl haritası üreten bir sistem gördüğünü anlattı. Hoca bunun aranan örneklerden biri olduğunu söyledi ve ekledi:

- Artık telefonun yanında araçlar da yeni bir IoT cihazı olarak işin içine giriyor. Hoca, araç anahtarının araca gömülmesi ve kodun başka birine gönderilerek aracın açılabilmesi gibi yeni özelliklerin artıları ve eksileri olduğunu belirtti.
- Araçlardan toplanan verilerle çukur ve tümsek gibi yol risklerinin tespiti ve belediyeye bildirilmesi harika bir yöntemdir. Hızlar nasıl crowdsourcing ile toplanıyorsa, telefonlar ya da araçlar üzerinden toplanan verilerle, araç gezdirmeden bir şehrin yol kalitesi hakkında rapor çıkarılabilir.
- Araca gömülü sensör daha iyidir. Telefon işin içine girince başka filtreler de devreye sokulmalıdır, çünkü telefon sensörleri hassasiyet açısından sorunludur.
- Hız haritası gibi risk haritaları da çıkarılabilir; hoca bu konuda küçük bir proje yaptıklarını söyledi.

Başka bir öğrenci sıradaki aşamanın otonom sürüş olduğunu, kullanıcının "beni en hızlı yoldan götür" demeyi bekleyeceğini söyledi. Hoca, otonom araçların bu derste de konuşulacağını, alanın araştırmaya çok müsait ama hukuki açıdan ve kararların bedeli açısından tehlikeli olduğunu, kendi görüşüne göre otonom araçların hayatımıza çok hızlı girmeyeceğini söyledi.

## 6. Sıradaki Talep: Uzun Vadeli Tahmin ve Karar Destek Sistemleri

Hoca, kendi beklediği cevabı bir konferansta duyduğu bir fikirle verdi: Artık elimizde yeterli donanım ve derin öğrenme gibi büyük veriyi verimli işleyen yazılım çözümleri var. O halde "yarın havalimanına kaç dakikada giderim" diye sorup planlama yapabilmeliyiz.

Bugün ise trafik durumu en fazla 1-2 saat ileriye kadar iyi öngörülebiliyor. Google ileri dönük tahmin verebiliyor, ama bu tahmin "yarım saat ile bir saat arası" gibi çok geniş bir aralık oluyor. Üstelik yarın için, bir sonraki gün için ve farklı saatler için aynı tahmin veriliyor. Yani hâlâ özelleşmiş, çözünürlüğü yüksek bir tahmin yapılamıyor; "47 dakika"ya alışmış biri için bu aralık çok geniş.

Hava tahmini burada örnek olarak verildi. Eskiden 2-3 günü tahmin etmek zorken bugün yaklaşık 15 gün ciddi doğrulukla tahmin yapılabiliyor. Yine de örüntüler kayabiliyor: olay iki gün önceye ya da bir gün sonraya kayıyor, şiddeti değişiyor. Özellikle mevsim geçişlerinde tahmin edilen olayın hiç gerçekleşmediği günler oluyor; yaz ve kışta tahminler daha iyi.

Hocaya göre tahmin ve öneri sistemlerinin başarı oranını yükseltmek bugünün en büyük zorluklarındandır ve bu sistemler aslında karar destek sistemleridir. Farklı hava tahmin kaynakları farklı şeyler söyleyebilir; sonra ya kullanıcı bir yorum yapar ya da meteorolojiyi iyi bilen biri kaynakları birleştirip "bu olayı abarttılar" ya da "olay akşama kayacak" der. Yani kararlarda insan hâlâ işin içindedir. Hoca, yapay zekanın belli işleri kolaylaştıracağını, ama yakın zamanda kesin karar verici konuma geleceğini düşünmediğini, insanın "başkan", yapay zekanın ise destek veren yardımcı olarak kalacağını söyledi. Satranç gibi kuralları belli alanlarda ise bilgisayar bütün kombinasyonları hesaplayabildiği için insandan çok daha başarılıdır.

## 7. Otonom Araçlar ve Kontrollü Ortamda Test

Hoca, otonom aracı sahaya ilk kez sürecek olsak nerede test edeceğimizi sordu. Öğrencilerden gelen cevaplar şunlardı:

- Otonom araçlar genelde haritalanmış yollarda çalışabiliyor ve orada bile kusurları var. Kırsalda çevrede başka sensör, araç ya da kamera olmadığı için araç yalnız kalır; bu zorlayıcı bir test alanı olur ama risklidir.
- Riski azaltmak istenirse kampüs uygun bir yerdir: yollar haritalanmış, kameralar var, GPS iyi çalışıyor, veri alınabilecek farklı uç noktalar var ve alan trafiğe kapalıdır.
- Bir öğrenci bütün hataları görmek için aracı doğrudan şehir trafiğine sokacağını söyledi.
- Başka bir öğrenci kontrollü, ama gerçekçi olması için kullanılan bir alanı tercih etti.

Hoca, kontrollü ortam fikrinin doğru olduğunu söyledi. Bu tür sistemlerde parametre sayısını azaltmak için değişkenleri kontrol edilebilen ortamlar tercih edilmelidir. Kampüs örneği güzeldi; hocanın kendi tercihi metrobüs hattıdır. Bunun örneği sürücüsüz metrolarda görülür. Şehir merkezi dışındaki alanlar ve otoyollar da iyi adaylardır, çünkü orada da tanımlı bir yapı vardır.

> **Hocanın vurgusu:** Robotlar dahil gelecekteki çözümler hep kontrollü ortamlarla başlayacak. Tasarım ve test aşamasında buna çok dikkat etmek gerekir.

Hoca, bu araçların öğrenme yeteneği olduğunu, ama örneğin 300 bin kilometreye gelene kadar öğrenme sürecinde yaratacakları olumsuz olayların kabul edilemeyebileceğini söyledi. Bu riski azaltmak için otonom araçlar birçok sensör kullanır: lidar, kameralar, GPS. Aynı sensörü birden fazla açıdan kullananlar da vardır.

## 8. İnsan Duyuları ve Sensörler

### 8.1 İnsan mı, sensörlü bilgisayar mı?

Hoca, insanın beş duyusunu (görme, duyma, tatma, dokunma ve koku) hatırlattı ve duyularla karar verilecek bir durumda insanın mı yoksa sensörleri olan bir bilgisayarın mı daha iyi olduğunu sordu. Öğrencilerin cevapları:

- İnsan daha iyidir; ama bilgisayar her durumda aynı uyarana aynı yanıtı verir, insanın yanıtı ise duygu durumuna göre değişir. İki tarafın da artıları ve eksileri vardır.
- İnsanın yaşı, deneyimi ve birikimi devreye girer. Beş duyunun dışında içgüdü ve refleks gibi etkenler vardır. Bugün işleri otomasyona tam teslim etmememizin nedeni ona güvenmememizdir. Koku tarafı robotlar için henüz çözülmemiştir.
- Otonom bir sistem daha önce görmediği, eğitildiği verilerden çok farklı bir durumla karşılaşınca doğaçlama yapamayacağı için başarısız olur; insan ise tamamen yeni bir şeye de mantıklı bir yorum getirebilir.
- Önceden tanımlı işlerde makineler insandan öndedir; refleks ve hızda da öyledir. Makineler sıkılmadan tekrar eder. Yepyeni bir iş için insana, tanımlı ve çok tekrarlanan bir iş için makineye güvenilir.

### 8.2 Hocanın cevabı: ölçümde sensörler üstündür

Hoca, öğrencilerin çoğunun karar verme kritikliği açısından cevap verdiğini, kendisinin soruya başka bir açıdan baktığını söyledi. Koku ve tat alma şu an teknolojide rekabet noktasında değil ve kritiklik içermiyor; bu iki duyu devre dışı bırakılabilir. Asıl ilginç nokta ölçümdür: Bir tepeye çıkan insana yüksekliği sorsanız tahmin eder (500 metre, 1200 metre), ama sensör, kalitesine göre belli bir hata payıyla, tam olarak kaç metrede olunduğunu söyler. Teknolojik cihazlar bizden çok daha iyi ve doğru ölçüm yapar. En güzel örnek uçaktır: Sensörleri uçaktan alıp yalnız pilota güvenirseniz hava açıksa inersiniz, sis varsa görmeden inme şansı yoktur.

> **Hocanın vurgusu:** Teknolojik cihazları değerlendirirken ölçüm yapan (sense eden) bileşenlerin ne kadar güçlü olduğunu ve birçok noktada insandan önde olduklarını unutmadan tasarım yapılmalıdır. Bu da doğru sensör seçimini getirir.

### 8.3 Sensör seçimi

Tasarımda şu sorular sorulur: Jiroskop mu, ivmeölçer mi, GPS mi, Bluetooth Low Energy mi? Hoca BLE ile beacon teknolojisini, iç mekânda konum belirleme için kastettiğini belirtti. Kamera kullanılacak mı? Birden fazla sensör aynı anda mı kullanılmalı, yoksa risk almamak için tek sensör yeterli mi? Örneğin park ederken kullanılan ultrasonik sensörler kısa mesafede işi çözer, ama uzun mesafede işe yaramaz. Bu yüzden sensörlerin maliyeti ve yetenekleri birlikte değerlendirilmelidir.

### 8.4 Yedeklilik, aykırı değer ve çoğunluk oylaması

Sensörlerin bozulma olasılığı vardır. Bunu en aza indirmek için yedekli (redundant) bir yapı kullanılır: aynı ölçüm için birden fazla sensör konur. Örneğin 3 sensörden biri çok uç bir değer üretirse aykırı değer tespitiyle (outlier detection) dışarıda bırakılabilir. Bunlar da veri işlemenin parçalarıdır.

Hoca sensör ağlarından bir örnek verdi. Ormana dağıtılmış sensörlerden 5'i 28 derece, 1'i 72 derece okuyor:

- Alarm doğruysa durum çok kritiktir, orman yanıyordur.
- Yanlışsa ekip boşuna gönderilmiş olur. Kamera yoksa görmeden karar verilmek zorundadır.
- Çoğunluk oylaması (majority voting) ile karar verilir: 6 okumanın 5'i 28 derece dediği için sonuç 28 derecedir ve 72 derece aykırı değer sayılır.

Hoca burada kollektif öğrenme (ensemble) denen yapının da işin içine girdiğini ve bu tarafta çeşitli tekniklerin uygulandığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Aynı örnekte okumaların aritmetik ortalaması yaklaşık 35,33 derece çıkar; yani tek bir hatalı sensör ortalamayı belirgin biçimde kaydırır. Çoğunluk oylaması ya da medyan (burada 28) böyle uç değerlere karşı daha dayanıklıdır (ara adım python ile kontrol edildi).

### 8.5 Mobil ve giyilebilir cihazlardaki sensörler

Çevresel zeka ve bağlam farkındalığı (durum farkındalığı) düşünüldüğünde cihaz üzerindeki sensörler vazgeçilmezdir. Bilgisayarlarda mikrofon ve kamera artık standarttır, ama bir dizüstünde jiroskop ya da ivmeölçer olsun diye uğraşılmaz. Telefonda ise bunların önemi büyüktür: oyun oynarken kullanılır, bir kişinin düşüp düşmediğini anlamak için kullanılır; düşme tespiti en çok akıllı saatlerde devreye girer.

Yeni dönemde biyomedikal sensörler (biyosensörler) popülerleşiyor: kan oksijeni gibi ölçümler. Hoca, akıllı saatlerin kalp ritim düzensizliğini haber vererek insanların hayatını kurtardığı örneklerin anlatıldığını, gelişmenin sağlık alanına yöneldiğini söyledi. Bu işler önce adım sayısı ve günlük egzersiz takibiyle başladı, bugün tansiyon gibi ölçümlere kadar geldi. Ancak küçük cihazın içine konan sensörün hâlâ bir hata payı var: Telefondaki jiroskop ya da ivmeölçer ile daha büyük bir cihazdakinin doğruluk oranları arasında fark vardır.

## 9. Düşme Tespiti ve Çarpma Şiddeti Tahmini

### 9.1 Senaryo ve basit karar kuralı

Hoca, tez bile olabilecek ilginç bir konu olarak şu senaryoyu anlattı: Issız bir yerde size bir araba ya da bisiklet çarpıyor, ya da biri vurup kaçıyor ve bayılıyorsunuz. Bunu anlamanın yollarından biri, kolunuzda saat ya da üzerinizde telefon varsa düştüğünüzü tespit etmektir. Belli bir süre hareketsiz kaldığınız anlaşılırsa acil bir durum var demektir. Düşüp kalktıysanız ve hareket ediyorsanız bir yere haber vermeye gerek yoktur. Hoca bunun tanımlı bir senaryo için çok basit bir karar verme taktiği olduğunu, istisnai durumların bu kuralı çürütebileceğini belirtti.

Düşme tespiti (fall detection) yaklaşık 2012'den 2020'lerin başına kadar yüzlerce çalışmanın konusu oldu. Hocanın tespit etmek istediği ise farklı bir şeydi: Düşme bir kaza sonrasında olabilir ve çarpmanın şiddeti çok önemlidir. Yediğimiz darbenin, itilme kuvvetinin ya da yere ne kadar sert düştüğümüzün şiddeti hesaplanabilir mi? Bu bilgi gelen sağlık ekibi için çok yararlı olur.

### 9.2 Öğrencilerden gelen fikirler

- İlk kullanılacak sensör büyük ihtimalle ivmeölçerdir. Asıl sorun gerçek bir düşmeyi yanlış alarmdan ayırmaktır: Telefon masaya sert konmuş olabilir. Kişi gerçekten düştüğünde telefon yere çarpmayabilir; telefon ön cepte olabilir, kişi sırt üstü düşmüş ya da başını vurmuş olabilir. Saat ve telefonun verileri karşılaştırılarak, birbirlerine göre konumlarına bakılarak bir işlem yapılabilir.
- Tek bir sensörden alınan veriye göre karar vermek yanıltıcı olabilir. Telefon, bileklik, belki ayak bileği takısı ya da kulaklıktaki bir ivmeölçerle başın hareketi gibi birden fazla noktadan veri toplanabilir.
- Çarpma sonrasında kol ya da bacak hareket etti mi, kişi hareketsiz mi kaldı, nabızda değişiklik oldu mu gibi diğer sensör bilgileri de kullanılabilir. Bu durumlar yapay ortamda canlandırılıp veri toplanabilir ve yapay zekayla işlenebilir; basınç sensörü de düşünülebilir.

### 9.3 Intrusive ve non-intrusive çözümler

Hoca, vücudun farklı pozisyonlarından ve açılarından bilgi almanın karar verme noktasını daha gelişmiş ve daha iyi hale getireceğini kabul etti. Ama telefon ve saat dışında insana başka bir cihaz bağlamak intrusive'dir.

Intrusive çözüm, kişiyi rahatsız eden, onu işin içine sokan ve konforunu bozan yapıdır: ya kullanıcı katkı sağlar (telefona sürekli bilgi girer) ya da üzerine bir şey bağlanır. Kişinin zaten varsayılan olarak taşıdığı telefondan veri toplamak ise non-intrusive'dir. Hoca bu kavramların ders boyunca kullanılacağını söyledi. Yaşlılar gibi sağlık açısından kritik gruplar, şekerini ölçmek ya da holter taşımak zorunda kalmaları gibi, ek cihazları gönüllü takabilir ve bu yaygınlaşabilir. Ama normal genç bir kullanıcı için çözüm üretiliyorsa, kullanıcı ek cihaz takmak istemeyecektir; elinde telefon ya da saat olmalıdır.

### 9.4 Cihazın konumu ve çarpma fiziği

Bir araç kişiye çarptığında bir ivme oluşur. Cihazın vücuttaki yeri (üst bölgede mi, alt bölgede mi) ölçülen ivme değerlerini değiştirir. Kalça bölgesinde oluşan ivme ile vücudun üst bölümünün daha yukarıdan düşmesiyle oluşan ivme arasında, çok büyük olmasa da, fark olacaktır. Sistem buna göre tasarlanmalıdır. Hız da sonucu belirler: 40 km/sa'te çarpan araç kişiyi biraz havaya kaldırabilir, 60 km/sa'te bayağı uçurur, daha yüksek hızlarda ise hayatta kalma şansı pek kalmaz.

Hedef aracın hızını tespit etmektir; doğrudan bilinemese bile yavaş, orta hızlı ve yüksek hızlı olarak üç kategoride bilgi verilebilir. Hoca, büyük olasılıkla 2013 yılında yaptıkları bir çalışmada bu üç sınıf (yüksek, orta, düşük) için yaklaşık %70 başarıyla tahmin yapabildiklerini söyledi. Deney bir manken ve go-kart aracıyla yapılmış, telefon mankenin cebine konmuştu.

Hoca, fiziksel tarafta $F = m\,a$ ilişkisinin, etki-tepkinin, aracın kütlesindeki ivmenin kişiye kuvvet olarak aktarılmasının ve kişinin kütlesinin işin içinde olduğunu, bu yüzden deneyde kişi ile araç arasındaki oranı manken ve go-kart arasında kurmaya çalıştıklarını anlattı. Hocaya göre en zor ve en değerli kısım yüksek-orta-düşük demek değil, aracın hızını tahmin etmek olurdu. Bunun için belirli deney düzenekleri kurmak gerekir.

### 9.5 Dönemin telefonlarındaki kısıt: ±2g

Hoca, o zamanki telefonlarda çalışmayı olumsuz etkileyen bir kısıt olduğunu söyleyip bunun ne olabileceğini sordu. Bir öğrenci jiroskobun eksen sayısının, işlem gücünün ve sensör hassasiyetinin (ayrık ölçüm aralıklarının) düşük olabileceğini söyledi. Hoca hassasiyet konusunun doğru noktaya değindiğini belirterek cevabı verdi: O dönemde Android işletim sistemi ivmeölçeri ±2g aralığında çalıştırıyordu. Sensör ±4g destekliyor olmasına rağmen işletim sistemi yazılımsal olarak ±2g ile hizmet veriyordu. Deneylerde araç yavaş da çarpsa hızlı da çarpsa ölçülen değer 2g'ye çıkıp orada kalıyordu, yani sensör doyuma ulaşıyordu.

<!-- BELİRSİZ: 01:58:40 civarında altyazı "yazılımsal olarak ±4g'yi desteklemesine rağmen ... yazılımsal olarak ±2g" diyor; ilk "yazılımsal" büyük olasılıkla "donanımsal" olmalı. Notta sensör donanımının ±4g desteklediği biçiminde yazıldı. -->

Bu sınırlamanın nedeni, aralığı dar tutarak hassasiyeti oyun oynarken yapılan küçük hareketlere ayırmaktı. Bugün telefonlardaki ivmeölçerlerde ±8g, hatta ±16g konuşulabiliyor. Bu da araç çarpma şiddeti gibi bir araştırma için yeni bir imkân sağlıyor.

> **Hocanın vurgusu:** Bu örnek, kullanılacak sensörlerin özelliklerini çok iyi incelemek gerektiğini anlatan mükemmel bir örnektir.

> **Ek bilgi (derste anlatılmadı):** $g$, yer çekimi ivmesidir ve yaklaşık $9{,}81\ \text{m/s}^2$ değerindedir. Bu durumda ±2g aralığı yaklaşık ±19,6 m/s², ±16g aralığı yaklaşık ±156,9 m/s² ölçüm sınırına karşılık gelir. Aynı bit çözünürlüğünde aralık daraldıkça bir ölçüm adımı küçülür, yani küçük hareketlere hassasiyet artar; bu, derste anlatılan tercihin büyük olasılıkla nedenidir.

## 10. Sensör Verisi ve Dijital Adli Bilişim

Hoca, çarpma anının ve şiddetinin tespit edilebilmesinin, adli kurumların kullandığı dijital adli bilişim (digital forensics) açısından değerli olacağını söyledi. Bu verinin manipüle edilebileceği itirazı ayrı bir problemdir. Bugün sokak kameraları, ev ve iş yeri güvenlik kameraları delil olarak kullanılıyor ve ses kaydı ile görüntü manipülasyonları da yaşanıyor; bu, veri bütünlüğü (data integrity), veri mahremiyeti (data privacy) ve veri güvenliği (data security) konularının önemli bir parçasıdır. Hocaya göre ileride teknolojik cihazlardan elde edilen hareket bilgileriyle de kararlar verilecek. En güzel örneklerden biri, bir kişinin kaza sırasında telefon kullanıp kullanmadığının tespitidir: kaza anı belirlenir, o andaki telefonun aktif logları incelenir ve konuşma tespit edilirse davanın gidişatı değişebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:19:39): Google Maps ve Yandex trafikte dakika düzeyinde süre tahmini veriyor. Bu servislerden daha neyi talep edebiliriz?

> **Cevap (derste verildi):** Öğrencilerden araçlardan toplanan veriyle buzlanma ve yol riski haritaları ile otonom yönlendirme önerileri geldi. Hocanın cevabı uzun vadeli ve yüksek çözünürlüklü tahmindir: "Yarın sabah havalimanına kaç dakikada giderim?" sorusuna bugünkü "yarım saat ile bir saat arası" gibi geniş aralık yerine dakika düzeyinde, güne ve saate özel bir cevap.

**Soru 2** (derste sözlü, 01:30:25): Otonom bir aracı ilk kez sahaya sürecek olsanız ve riski en aza indirmeniz istense, aracı nerede test edersiniz?

> **Cevap (derste verildi):** Değişken sayısı azaltılmış, kontrollü bir ortamda: trafiğe kapalı ve haritalanmış bir kampüs, metrobüs hattı (sürücüsüz metrolar gibi), şehir dışı alanlar ve otoyollar.

**Soru 3** (derste sözlü, 01:36:38): Duyularımızı kullanarak karar vereceğimiz bir durumda, sensörleri olan bir bilgisayara göre biz mi daha iyiyiz, o mu?

> **Cevap (derste verildi):** Karar verme açısından insanın yeni durumlara uyum ve yorum yeteneği, makinenin ise tanımlı işlerde tutarlılık ve hız üstünlüğü vardır. Hocanın vurguladığı açı ölçümdür: Yükseklik ölçmede ya da sisli havada uçak indirmede sensörler insandan çok daha doğru ölçüm yapar. Bu yüzden tasarımda doğru sensör seçimi önemlidir.

**Soru 4** (derste sözlü, 01:49:26): Saat ya da telefon sensörlerini kullanarak bir kazadaki çarpmanın şiddetini tahmin etmek mümkün müdür? Bunun için neler kritiktir?

> **Cevap (derste verildi):** İvmeölçer temel sensördür. Kritik noktalar: gerçek düşmeyi yanlış alarmdan (telefonun masaya sert konması) ayırmak, cihazın vücuttaki konumu (kalça ya da üst gövde ölçülen ivmeyi değiştirir), birden fazla cihazdan veri birleştirme ve çözümün non-intrusive kalması. Hocanın çalışmasında şiddet düşük, orta, yüksek olarak üç sınıfta yaklaşık %70 başarıyla tahmin edilmişti.

**Soru 5** (derste sözlü, 01:57:17): O dönemki telefonlarda çarpma şiddeti çalışmasını olumsuz etkileyen kısıt neydi?

> **Cevap (derste verildi):** Android işletim sistemi ivmeölçeri yazılımsal olarak ±2g aralığında çalıştırıyordu; her çarpma 2g'de doyuma ulaştığı için şiddetler birbirinden ayrılamıyordu. Bugün ±8g ve ±16g aralıkları kullanılabiliyor.

## Dersin Toparlaması

Bu ilk derste pervasive ve mobil hesaplamanın kapsamı, dönem boyunca işlenecek konular ve dersin interaktif, araştırma odaklı yapısı tanıtıldı. Sensör ağlarının IoT'ye dönüşümü, mobil uygulama trendinin doygunluğa yaklaşması ve crowdsourcing'in trafik tahmini ile yol durumu tespitindeki rolü örneklerle konuşuldu. Tahmin sistemlerinin hâlâ insanın son kararı verdiği karar destek sistemleri olduğu, otonom sistemlerin kontrollü ortamlarda test edilmesi gerektiği vurgulandı.

Dersin ikinci yarısı sensörlerin ölçümde insandan üstün olduğu fikrine, buna bağlı olarak sensör seçimine, yedekliliğe ve çoğunluk oylamasına ayrıldı. Düşme tespiti ve çarpma şiddeti örneği, intrusive/non-intrusive ayrımını, cihaz konumunun etkisini ve ±2g kısıtı üzerinden sensör özelliklerini incelemenin önemini gösterdi. Hoca bir sonraki derste yine günlük örnekler ve soru-cevap üzerinden çevresel zekaya ve bağlam farkında sistemlere geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
