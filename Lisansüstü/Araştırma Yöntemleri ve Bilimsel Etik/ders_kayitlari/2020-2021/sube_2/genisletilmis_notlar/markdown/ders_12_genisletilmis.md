# Ders 12 Genişletilmiş Notu: TÜBİTAK 1512 İş Fikri Sunumları III

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı ve sunum iskeleti
- 2. QR kodlu salgın yönetim sistemi
- 3. Seslendirilmiş şiir hediye platformu
- 4. Garsonsuz restoran sipariş uygulaması
- 5. Yapay zekâ ile bebek refleksi ölçümü
- 6. Hayvanseverler için modüllü mobil uygulama
- 7. Veteriner yönetim ve hizmet platformu
- 8. Robotik çim biçme makinesi
- 9. Güvenli ikinci el araç alım satım uygulaması
- 10. Nokta bulutundan üç boyutlu model oluşturma
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı ve sunum iskeleti

Bu ders, dönem projesi sunumlarının üçüncü haftasıdır ve konu anlatımı içermez. Gruplar, TÜBİTAK 1512 Teknogirişim Sermaye Desteği programının iş planı formatında hazırladıkları iş fikirlerini sunar (ekrandan, 00:15:00). Bu derste dokuz sunum yapılır; çoğu iki kişilik gruplarla, bir sunum tek kişiyle yapılır. Hoca sunumları sırayla yönetir; bu derste sunumlara akademik bir geri bildirim vermez.

Sunumların çoğu aynı iskeleti izler:

- İş fikri ve çıkış noktası: hangi problemden ya da pazar boşluğundan doğduğu.
- Ürün/hizmet tanımı, modüller ve kullanıcı tipleri.
- Yenilikçi yön ve rakiplerden fark (çoğu zaman bir karşılaştırma tablosuyla).
- Hedef kitle ve pazar büyüklüğü.
- İş paketleri ve iş-zaman çubuk grafiği (Gantt şeması).
- Ekip ve kurulacak şirket yapısı.
- Maliyet tablosu, finansman (destek ve öz kaynak) ve ticari beklenti/sürdürülebilirlik.

Birçok grubun iş paketi listesi benzer bir sırayı izler: işletme kuruluşu (yer, marka adı, malzeme/donanım), gereksinim analizi ve kurulum işlemleri (kullanılacak servisler, özellik listesi, personel planlaması), yazılım geliştirme (genellikle en uzun paket), mobil uygulama geliştirme, son test ve pazarlama.

## 2. QR kodlu salgın yönetim sistemi

İlk sunumda işletmeler için bir salgın yönetim sistemi anlatılır. Sunum, salgının hizmet sektörünü ve bu sektöre bağlı çalışanları nasıl etkilediğinden yola çıkar; amaç işletmelerin güvenli biçimde açık kalmasına teknolojiyle katkı vermektir. Sistem bir mobil uygulama ve bir web uygulamasından oluşur.

Mobil uygulamada üç hesap türü vardır (ekrandan, 00:10:00):

| Hesap türü | İşlevler |
|---|---|
| Bireysel kullanıcı | QR kod okutma, bulaş riski analizi, risk bildirimi |
| Kurumsal kullanıcı (işletme sahibi) | Bulaş riski analizi, anlık bireysel kullanıcı analizi |
| Admin kullanıcı | Bulaş riski takibi, anlık bireysel kullanıcı analizi |

Çalışma mantığı şöyledir. Sistem anlaşılan bir ilçede uygulanır. Her işletmenin girişine bir QR kod konur ve girişte okutulması zorunlu tutulur; böylece her giriş kaydedilir. Kayıtlı kullanıcıların test sonuçları gün sonunda sağlık sisteminden alınır. Pozitif sonuç çıkan bir kullanıcı için, aynı işletmeye girmiş diğer kullanıcılara bildirim gönderilir. Adminler kendilerine bağlı işletmeleri gün sonunda puanlar: örneğin bir mekâna son bir ayda 1000 kişi girmiş ve bunlardan 50'si hastalanmışsa, bu oranla ters orantılı bir yıldız puanı verilir. Bireysel kullanıcılar bulaş riski en düşük işletmeleri seçebilir; işletmeler de QR kodla doğrulanmayan kişileri içeri almayarak riski azaltır.

Ekip planı genel müdür, yardımcısı ve analiz, veri tabanı, mobil yazılım, web yazılım ekiplerinden oluşur; bir ilçe için hesaplanmıştır, bir il ölçeğinde sayıların artacağı belirtilir. Rekabet analizinde yurt içindeki resmî salgın takip uygulaması rakipten çok tamamlayıcı olarak görülür, çünkü işletme tarafı için bir çözüm sunmaz. Yurt dışında benzer QR tabanlı giriş-çıkış takibi yapan bir uygulama da örnek gösterilir. Sürdürülebilirlik açısından sistemin salgın sonrasında da kullanılabileceği söylenir.

## 3. Seslendirilmiş şiir hediye platformu

İkinci sunum, e-ticaret ve hediye sektöründen yola çıkan bir iş fikridir (ekrandan, 00:15:00). Sanatçılar ya da kullanıcıların kendisi tarafından seslendirilen şiirler, ses kaydı olarak ya da bir ses kaydının çiçek, çikolata gibi hediyelerle birlikte bir kutuda gönderilmesiyle hediye edilir. Gelir modeli aylık/yıllık abonelik ve tek şiir satın almadır. Ayrıca kullanıcıların şiir yazıp okuyabildiği ve paylaşabildiği bir forum bölümü vardır. Fark olarak kişiye özel bir hediye sunulması ve kullanıcının kendi sesiyle ya da tanınmış bir sesle hediye gönderebilmesi öne çıkarılır.

İş-zaman çubuk grafiğinde dört ana paket vardır: işletme kuruluşu (1 ay), gereksinim analizi/kurulum işlemleri (2 ay), yazılım (7 ay; gereksinimlerin belirlenmesi, yazılım standartları, entegrasyon analizi, veri tabanı, web sitesi, mobil uygulama analizi ve tasarımı, kullanıcı arayüzleri, testler) ve müşteri ilişkileri/pazarlama (2 ay) (ekrandan, 00:20:00). Personel alınmayacak, iki kurucu birlikte çalışacaktır; pazarlama sosyal medya ve video platformlarındaki reklamlarla yapılacaktır.

Dönemsel ve toplam tahmini maliyet formu (ekrandan, 00:25:00):

| Maliyet kalemi | Her dönem (I-IV) | Toplam (TL) | Pay |
|---|---|---|---|
| Personel | 18.000 | 72.000 | %22,5 |
| Seyahat | 0 | 0 | — |
| Alet/Teçhizat/Yazılım/Yayın | 21.025 | 84.100 | %26,25 |
| Danışmanlık/Hizmet alımı | 22.500 | 90.000 | %28,125 |
| Malzeme | 2.500 | 10.000 | %3,125 |
| Genel giderler | 16.075 | 64.300 | %20 |
| Toplam maliyet | 80.100 | 320.400 | |

Hesap adım adım: dönem toplamı $18.000 + 21.025 + 22.500 + 2.500 + 16.075 = 80.100$ TL; yıllık toplam $4 \times 80.100 = 320.400$ TL.

> **Ders sonrası not:** Tablodaki toplamlar python ile kontrol edildi ve tutarlıdır. Yüzde payları ise yaklaşık 320.000 TL'ye bölünerek hesaplanmış görünüyor; tam toplamla danışmanlık %28,09, malzeme %3,12, genel giderler %20,07, personel %22,47 olur.

Sunumda ayrıca altı bütçe kalemi için destekten karşılanacak tutar (toplam 196.100 TL) ile öz kaynak tutarı (yaklaşık 205.000 TL) ayrı ayrı anlatılır; ilk yıl hizmet verilmeyeceği için kâr tablosu hesaplanmadığı belirtilir.

## 4. Garsonsuz restoran sipariş uygulaması

Üçüncü sunum, eve sipariş uygulamalarının tersine, restorana fiziksel olarak gitmek isteyen müşteriye kolaylık sağlamayı hedefler. Sunan, restorandaki tipik süreci anlatarak problemi tanımlar: yer olup olmadığını görmek için gitmek, menü istemek, garsonu tekrar çağırmak, eksik ya da yanlış siparişler ve garsonla iletişim kurmak istemeyen müşteriler.

Uygulamanın iki kullanıcı kitlesi vardır: işletme sahipleri (kafe, restoran) ve müşteriler. Müşteri, uygulamayı kullanan çevredeki işletmeleri görür, seçtiği işletmenin doluluk oranını ve hangi masaların boş olduğunu gitmeden görür, masayı seçip siparişini verir; yemekten sonra ödemeyi de uygulamadan yapar.

Rakip karşılaştırma tablosu (ekrandan, 00:30:00):

| | Kendi uygulama | Yerli rakip (eve teslim platformu) | Yabancı rakip (kahve zinciri mobil sipariş) | Farklara ilişkin açıklama |
|---|---|---|---|---|
| Teknik özellik 1 | Online sipariş, eve ve işletmede servis | Online sipariş, eve teslimat | Online sipariş, kafede teslimat | Yerli firmalar restoranda masa kullanımı için alternatif sunmuyor; yabancı rakip yalnız kendi lokasyonları için gel-al sunuyor. |
| Teknik özellik 2 | Firma ve müşteri değerlendirme | Firma, ürün, teslimat değerlendirme | Kendi kafeleri dışında çalışmıyor | İki rakip de uçtan uca hizmet sunmuyor. |

Şirket iki ortaklı bir limited şirket olarak planlanır; başlangıçta iki geliştirici (web ve mobil) istihdam edilecektir. Pazardaki sipariş platformlarının yüksek komisyonları (sunumda kuryeli hizmette %34, diğerinde %12 ve ödemenin bir ay sonra yapılması örneği verilir) bir fırsat olarak görülür. Pazarlama planı (ekrandan, 00:35:00):

- Anlaşılan firmalarla ilk 2 hafta ücretsiz deneme sözleşmesi; sonrasında fiyatlandırma.
- Firmalara kendi istekleri dışında zorla indirim uygulatılmaması.
- Müşterilerin ilk siparişlerinde %50 indirim.
- Havayolu mil sistemine benzer bir puan sistemi: puanlar ek ürün, çekiliş ya da para puan olarak kullanılır; amaç müşteri bağlılığını artırmaktır.

Büyüme hedefi yıllara göre 400 firma/10 bin müşteri, 2 bin firma/100 bin müşteri, 10 bin firma/1 milyon müşteri ve 50 bin firma/7 milyon müşteri olarak verilir. Uygulamanın bulut servis sağlayıcılarında barındırılması ve pazarlamanın danışmanlık alınarak yürütülmesi planlanır.

## 5. Yapay zekâ ile bebek refleksi ölçümü

Dördüncü sunum sağlık alanında yapay zekâ destekli bir mobil uygulamadır. Amaç, bebek sağlığındaki olumsuz durumları ilerlemeden fark etmek ve takip etmektir. Slaytta yenidoğanlarda ilk aylarda görülen altı refleks sayılır (ekrandan, 00:40:00):

- Arama refleksi
- Yakalama refleksi
- Tonik ense refleksi
- Basma ve adımlama refleksi
- Aksırma-öksürme refleksi
- Moro (sıçrama) refleksi

Bu refleksler merkezi sinir sistemi için önemli göstergelerdir. Proje, ölçülmesi en kolay olan Moro refleksini ele alır: kol ve bacaklar gövdeden uzaklaşır ve yeniden içe bükülür; refleks yaklaşık altıncı aya kadar görülür. Problem, ebeveynlerin bu testi hastaneye gitmeyerek ertelemesi ve teşhisin gecikmesidir. Sunumda verilen klinik ipuçları: hiç refleks alınmaması sinir sistemi hasarı ya da ağır bir hastalık şüphesi doğurur; tek taraflı refleks kol siniri felci ya da köprücük kemiği kırığına işaret edebilir; refleksin uzun süre devam etmesi beyin hasarı şüphesi doğurabilir.

Uygulamada bebeğin videosu ekrandaki yönergelere göre çekilir, yapay zekâ modeli videoyu değerlendirir ve bir ön teşhis raporu verir; risk varsa hastaneye yönlendirir. İş paketleri:

- Yapay zekâ modelini eğitmek için video formatında (yapay) bir veri seti oluşturma.
- Mobil uygulamanın ve modelin geliştirilmesi ve bu veri setiyle test edilmesi.
- Sağlık Bakanlığı onayı için klinik ortamda doktor ya da teknisyen tarafından test.

Rakip olarak biri yerli biri yabancı iki proje gösterilir; bunlar bebeğin bileğine bağlanan üç eksenli ivme ölçer ve web kamerasıyla bilgisayarda hesaplama yapar. Bu projenin farkı yalnız telefonla çalışmasıdır. Yenidoğan istatistikleri slaytında Türkiye için 2019'da 1.183.000, son 10 yıl ortalaması 1.283.000 doğum verilir (ekrandan, 00:45:00). <!-- BELİRSİZ: Slayttaki dünya değeri "Ortalama 1.141.000 Mn" diye yazılmış; sunan sözlü olarak yaklaşık 141 milyon diyor. Birim tutarsız. --> Hedef kitle yalnız ebeveynler değil, bebeğe bakan yakınlar ve bakıcılardır. Maliyet kalemleri uygulama mağazası ücretleri, veri tabanı, taşeron yazılım firması ve teknik bakımdır; toplam bütçe 124.448 TL olarak verilir. İlk iki yıl uygulama ücretsiz olacak, gelir reklamdan sağlanacak; sonra uygulama ücreti alınacaktır. Model, artan kullanıcı verisiyle beslenerek iyileştirilecek, başarılı olursa başka reflekslere genişletilecektir.

## 6. Hayvanseverler için modüllü mobil uygulama

Beşinci sunum, hayvanların yaşam kalitesini yükseltmeyi ve daha bilinçli hayvan sahipleri yaratmayı hedefleyen bir mobil uygulamadır (ekrandan, 00:50:00). Hayvan sahibi sağlık, bakım, eğitim ve beslenme bilgilerini takip eder, hatırlatma alır; diğer hayvanseverlerle etkileşir, sahiplendirme ve kayıp ilanı verir. Veterinerler, evcil hayvan malzemesi dükkânları ve hayvanseverler tek platformda buluşur. Yalnız hayvan malzemesi satan dükkânlarla çalışılacak, hayvan ticareti yapan dükkânlar uygulamadan uzaklaştırılacaktır.

Proje modülleri (ekrandan, 00:55:00):

- Bilgilendirme modülü: akademik kaynaklarca doğrulanmış hayvan bilgileri; hayvan sahibi olmak gerekmez.
- Profil modülü: kullanıcı profili ve altında her hayvan için alt profil; sağlık, beslenme, eğitim, bakım verileri ve uyarılar.
- Eğitim modülü: doğrulanmış kaynaklara dayalı eğitim planlarıyla hayvanı kendi başına eğitme.
- Veteriner modülü: veterinerlerin profil açıp hizmet sunması ve makale yayımlaması.
- Evcil hayvan malzemeleri dükkânı modülü: ürün sergileme; satış uygulama içinde değil, dükkânın e-ticaret sayfasına yönlendirmeyle.
- Zaman akışı modülü: arkadaşların ya da çevredeki kullanıcıların paylaşımları (çiftleştirme, sahiplendirme, kayıp, bilgilendirme, danışma).
- Çevremdeki hayvanlar modülü: özellikle köpeklerin sosyalleşmesi için çevredeki hayvanlarla buluşma.

Başarı kriterleri yüzde hedefleriyle verilir: örneğin hayvanseverin deneyimi olmadığı bir hayvan hakkında temel bilgi edinmesi için en az %75, modüllerin tek uygulamada toplanması için %55-%70, bilgilerin her an takibi için en az %50. Geliştirme süreci için, beklenmedik sorunlar ve değişiklikler çıkabileceğinden esneklik sağlayan çevik (agile) yöntem seçilir.

Kullanılacak teknolojiler (ekrandan, 01:00:00):

| Teknoloji | Kullanım amacı |
|---|---|
| Kotlin, Java | Android uygulama altyapısı |
| Swift, SwiftUI | iOS uygulama altyapısı |
| Xcode | iOS geliştirme ortamı |
| Android Studio | Android geliştirme ortamı |
| SQLite | Yerel veri depolama |
| Firebase | Bulut veri depolama |
| Google Haritalar platformu | Konum işlemleri (yakındakini bulma, rota çizme) |

Grup, performans ve kalite için hibrit yerine native geliştirmeyi tercih eder. İş paketleri: ön araştırma ve analiz (literatür, pazar, rekabet, gereksinim analizi), yazılım tasarımı ve modelleme (ER diyagramı, UML şemaları), uygulama geliştirme ve test (hata, performans ve son kullanıcı testleri). Gelir modeli: hayvanseverler için ücretsiz, veteriner ve dükkânlar için aylık özel üyelik (50 TL'den üçüncü yılda 100 TL'ye); başlangıçta üç büyük şehirde 20'şer veteriner ve dükkâna belli süre ücretsiz kullanım karşılığında tanıtım işbirliği. Benzer ürün kıyaslamasında mevcut uygulamaların yalnız sahiplendirme, sosyal ağ, eş bulma ya da bakım/sağlık takibi gibi tek ya da birkaç işleve odaklandığı gösterilir (ekrandan, 01:05:00).

## 7. Veteriner yönetim ve hizmet platformu

Altıncı sunum da evcil hayvan alanındadır, ama veterinerlere odaklanır. Çıkış noktası, salgın döneminde evcil hayvan ürünü satışlarının ve hayvan edinme oranının belirgin biçimde artmasıdır (sunumda resmî olmayan veriler olarak verilir). Problem: hayvan sağlığında da farklı uzmanlık birimleri vardır; hayvan bir veterinerden diğerine gittiğinde aynı tahlil yeniden yapılabilir, çünkü her veterinerin kendi CRM sistemi vardır ve kayıtlar paylaşılmaz.

Önerilen çözüm, veterinerlerin tahlil sonuçlarını ortak bir platforma yüklediği, hayvan sahiplerinin de mobil uygulamadan bakım takibi yaptığı bir sistemdir. Böylece gereksiz tekrar testler ve veterinerlerin iş yükü azalır. Ticari beklenti ve sürdürülebilirlik slaytına göre proje evcil hayvan bakımının yoğun olduğu ilçelerden başlayıp ilçe ilçe büyüyecek, sonra diğer illere taşınacaktır; veterinerler için web platformu aylık ücretli, mobil kullanıcılar için ise hayvan bakıcılığı, gezdirme, çiftleştirme, gıda, malzeme gibi hizmetler komisyonlu sunulacaktır (ekrandan, 01:10:00).

Grubun vurguladığı strateji, ürünün kendisinden çok tutundurmadır: en iyi ürün bile pazarlanamazsa yatırım ve müşteri bulamaz. Bu yüzden web tabanlı (kurulum gerektirmeyen) CRM paneli ve uygulama ilk etapta veterinerlere ücretsiz verilecek; veterinerler hayvan sahiplerini uygulamaya yönlendirecek, kullanıcı sayısı arttıkça diğer veterinerlerin de katılması beklenecektir. Ürünün yaklaşık 9 ayda hazır olacağı, ardından 2 aylık pazarlama süreci öngörülür.

## 8. Robotik çim biçme makinesi

Yedinci sunum bir donanım ürünüdür. Sunan, tarım alet ve makineleri sektörünün imalat sanayinin yatırım malı üreten bir alt sektörü olduğunu, tarımsal mekanizasyon araçlarının iş gücü verimliliğini artırıp maliyeti düşürdüğünü anlatır. Türkiye'de bu sektör tarım alet-makine sanayisi ve traktör sanayisi olarak iki başlıkta incelenir. Çim biçme makinelerinde yerli üretim olmadığı ve ithalatın yüksek olduğu belirtilir; dışa bağımlılığı azaltacak yerli bir ürün hedeflenir.

Ürün hedefleri (piyasadaki ortalama makineyle karşılaştırmalı):

- Piyasadaki ortalama makine: yaklaşık 5.000 m², yaklaşık 1 saat şarj süresi, yaklaşık 56 dB.
- Hedef: 30 dakikada 6.000 m² biçme, 45 dB ses, yaklaşık iki kat (100 litre) toplama kapasitesi.
- Mobil uygulama ile manuel kurulum, belirli alanların uzaktan biçilmesi, sürüş ve hız kontrolü, sesli komut.
- Mesafe sensörüyle arazi dışına çıkmayı algılama.

Tasarım (ekrandan, 01:20:00): gövde için TP100 paletli tank şasesi kullanılacaktır; şase alüminyum alaşımdan, tekerlekler plastikten olacak, şasenin ağırlığı yaklaşık 650 gramdır. Açık kaynak donanım/yazılımlı geliştirme kartları, enerji ve şarj durumunu göstermek için OLED ekran ve HC-SR04 ultrasonik mesafe sensörü kullanılacaktır.

Pazar araştırmasında bir pazar raporuna göre küresel pazarın 2020'de 2,88 milyar dolar olduğu ve 2027'ye kadar yılda yaklaşık %5,4 büyüyeceği söylenir. İki öncü rakip markayla karşılaştırmada rakiplerin yaklaşık 5.000 m² ve %35 eğime kadar, 60 dakika şarjla, 59-63 dB seviyesinde çalıştığı; kendi ürünün 6.000 m², %45 eğim ve 45 dB hedeflediği belirtilir. Hedef müşteriler kamu kurumları, oteller, stadyum ve spor kulüpleri, peyzaj firmaları, inşaat firmaları, site yönetimleri ve tarım işletmeleridir. İş paketleri 13 aylık bir çizelgede tasarım ve kurulum, analiz, yazılım ve donanım, pilot test, başarı ölçümü, pazarlama ve satış olarak sıralanır.

Ticari kazanç tablosu (ekrandan, 01:25:00):

| | 1. yıl | 2. yıl | 3. yıl | 4. yıl |
|---|---|---|---|---|
| Tahmini müşteri sayısı | 50 | 200 | 1000 | 7500 |
| Tahmini ürün miktarı | 300 | 400 | 2000 | 4000 |
| Tahmini ortalama ürün fiyatı (TL) | 7.875 | 10.000 | 13.500 | 17.000 |
| Tahmini ciro (TL) | 2.362.500 | 4.000.000 | 27.000.000 | 68.000.000 |

Birim maliyet 4.500 TL, satış fiyatı 7.875 TL ve kazanç oranı %75 olarak verilir. Hesap adım adım:

- Ciro = ürün miktarı × ortalama fiyat; örneğin 1. yıl $300 \times 7.875 = 2.362.500$ TL, 3. yıl $2000 \times 13.500 = 27.000.000$ TL.
- Kazanç oranı = $\dfrac{7.875 - 4.500}{4.500} = \dfrac{3.375}{4.500} = 0{,}75$, yani %75.

> **Ders sonrası not:** Tablo python ile kontrol edildi ve ciro değerleri tutarlıdır. %75, maliyet üzerinden kâr oranıdır (markup). Satış fiyatına göre kâr marjı $3.375 / 7.875 \approx \%42{,}9$ olur; sunumda bu oran "kârlılık" olarak anılıyor.

## 9. Güvenli ikinci el araç alım satım uygulaması

Sekizinci sunum, ikinci el araç alım satımındaki dolandırıcılığı önlemeyi hedefleyen bir mobil uygulamadır. Çıkış noktası "önce para mı, önce satış mı" ikilemidir: alıcı önce devrin yapılmasını, satıcı önce paranın gönderilmesini ister. Uygulama iki tarafı ortak bir güven zemininde buluşturur.

İşleyiş diyagramı (sunumda anlatıldığı sırayla):

```text
1. Satıcı, kendi hesabından aracın bilgilerini girip bir teklif oluşturur ve alıcıya gönderir.
2. Alıcı teklifi kabul eder; teklif fiyatı kadar bakiye alıcının blokeli hesabına aktarılır.
3. Satış (noter işlemi) sonrası uygulama otomatik plaka sorgusu yapar.
4. Araç plakası alıcının kimlik numarasına geçmişse satış tamamlanmış sayılır.
5. Blokeli bakiye otomatik olarak satıcının hesabına aktarılır.
```

İş fikrinin avantajları slaytı (ekrandan, 01:30:00):

- Yeni müşteri kazanımı: her yeni işlem yeni bir müşteri çağrısıdır.
- Yeni pazarın sahibi: sistem şu an yalnız iki bankada vardır; rekabet azdır.
- EFT prosedürü yok: satış nöbetçi noterde yapılsa bile EFT saati beklenmez.
- Yüksek mevduat: kredisiz alım satımların nakit akışı hedeflenir.
- Yeni bir başvuru kanalı: ileride uygulama üzerinden kredi talebi.

Diğer avantajlar nakit taşıma riskinin ortadan kalkması, anlaşma bozulursa paranın alıcının hesabına iade edilmesi, banka çeki gibi masrafların olmaması ve her aşamada SMS/e-posta bildirimiyle kayıt tutulmasıdır. Dezavantajlar, kullanıcının anlaşılan bankanın müşterisi olması ve uygulamayı indirmesi zorunluluğudur. Kullanılacak teknolojiler Xamarin, Web API, SQL Server, Entity Framework ve Visual Studio'dur.

İş-zaman çubuk grafiği (ekrandan, 01:35:00): işletme kuruluşu (1 ay), gereksinim analizi/kurulum işlemleri (2 ay), yazılım (1 ay; özellik gereksinimleri, yazılım standartları, entegrasyon analizi, veri tabanı tabloları, kontrol katmanı fonksiyonları, testler), mobil cihazlar için uygulama geliştirme (2 ay; ekran tasarımları, arayüz, geliştirme, test ve QA) ve pazarlama (2 ay). Pazar verisi olarak el değiştiren araç sayısının 2010'da yaklaşık 3,9 milyondan 2018'de yaklaşık 7,7 milyona çıktığı söylenir.

## 10. Nokta bulutundan üç boyutlu model oluşturma

Son sunum, inşaat sektöründeki bir ihtiyaçtan doğan bir modelleme yazılımıdır: modeli olmayan yapıların (örneğin hastane, AVM gibi yapılar) tesis yönetimi için üç boyutlu modelinin çıkarılması. Ürün özellikleri ve rakiplere göre farklar (ekrandan, 01:40:00):

- Modeli olmayan yapılardan 3 boyutlu yapı oluşturur.
- Nokta bulutu kullanır.
- Anlaşılabilir ve kullanımı kolaydır.
- Rakiplere göre farklar: doğruluk, verimlilik, zaman.

Sunan, bir sandalye örneğiyle anlatır: gözümüzle sandalye olduğunu anlarız ama elle doğru çizip çizemeyeceğimiz belirsizdir; yazılım nokta bulutundaki X, Y, Z koordinatlarından modeli daha doğru ve daha kısa sürede çıkarır. Slayttaki görsellerde bir toplantı odasının nokta bulutu ve nesne sınıflarına göre renklendirilmiş (bölütlenmiş) hâli gösterilir. Rakipler elle çizim yapan mühendis/mimarlar ve yardımcı çizim yazılımlarıdır; hedef kitle inşaat, mühendislik, mimarlık ve iç mimarlık firmalarıdır.

Proje yönetimi, kalite standartlarını (ISO) temel alan bir akışla yürütülür: başlangıç toplantısı (kick-off), ana veri toplama, analiz ve test, canlı sisteme geçiş. Gelir modeli üç yıllıktır; ilk yıl 900 bin TL satış ve 385 bin TL gider ile 515 bin TL net gelir hedeflenir. Ekip uzaktan çalışacak dört kişiden (proje yöneticisi, kıdemli uzman, yazılım geliştirme uzmanı, sistem/ağ uzmanı) oluşur. Reklam için sosyal medya, arama motoru anahtar kelime çalışmaları ve müşteri referansları kullanılacaktır. Zaman çizelgesinde yazılım iş paketi özellik gereksinimleri, yazılım standartları, entegrasyon analizi, veri seti ve veri tabanı oluşturma ile testleri kapsar; ardından müşteri ilişkileri, son test ve pazarlama gelir (ekrandan, 01:45:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:37:20): Restorandaki masaların dolu ya da boş olduğunu uygulama nasıl anlayacak?

> **Cevap (sunan grup):** Müşteri uygulamadan bir masa seçtiğinde sistem o masayı otomatik olarak dolu işaretler. Uygulamayı kullanmadan gelen müşteriler için restoran çalışanı masanın dolu olduğunu sisteme girer.

**Soru 2** (derste sözlü, 00:48:07): Uygulama şüpheli bir durum bulup hastaneye yönlendirdiğinde, teşhisin doğru çıkıp çıkmadığı bilgisi modele geri beslenecek mi?

> **Cevap (sunan grup):** Veriler önce hastanelerde çalışılarak toplanacak; klinik testlerde belirli bir doğruluk ve güven düzeyi sağlandıktan sonra uygulama mağazalara çıkacak.

**Soru 3** (derste sözlü, 01:36:59): İşlemler uygulamadan yapılıyor, ama noter ve ruhsat gibi resmî işlemler yine alıcı ve satıcı tarafından mı yapılacak?

> **Cevap (sunan grup):** Noterlerin güvenli ödeme sisteminin web servis altyapısının kullanılması planlanıyor; güvenli ödeme bu şekilde sağlanacak.

**Soru 4** (derste sözlü, 01:45:58): Üç boyutlu model oluşturma, mimarların kullandığı 3B modelleme programlarıyla da yapılamıyor mu?

> **Cevap (sunan grup):** Hedef kitlede mimarlık firmaları da var. Amaç elle çizimin önüne geçmektir; elle çizimde hata oranı, göz yorgunluğu ve zaman kaybı yüzünden projeler yetişmeyebiliyor.

## Dersin Toparlaması

Bu derste dokuz grup, TÜBİTAK 1512 iş planı formatında iş fikirlerini sundu. Fikirlerin çoğu mobil uygulama ve web platformuydu (salgın yönetimi, hediye, restoran siparişi, bebek sağlığı, evcil hayvan, veteriner, araç satışı, 3B modelleme); biri donanım ürünüydü (robotik çim biçme makinesi). Sunumlar, bir iş fikrinin problem tanımı, yenilikçi yön, rakip karşılaştırma tablosu, iş paketleri ve Gantt şeması, maliyet formu ve ticari kazanç tablosuyla nasıl yapılandırıldığını gösterdi. Tablolardaki hesaplar (dönem ve yıl toplamları, ciro = miktar × fiyat, maliyet üzerinden kazanç oranı) kontrol edildiğinde tutarlıydı; yüzde payların hangi toplama göre hesaplandığına ve kâr oranı ile kâr marjının farkına dikkat edilmesi gerektiği görüldü.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
