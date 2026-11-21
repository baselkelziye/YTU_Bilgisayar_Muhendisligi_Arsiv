# Ders 4 Genişletilmiş Notu: Derleme Makalesi ve Trafik Akış Tahmini; Mobil Hesaplama ve Mobil İşletim Sistemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derleme (Survey) Makalesi
- 2. Literatür Taraması Nasıl Yapılır
- 3. Trafik Akış Tahmini: Problemin Bakış Açıları
- 4. Trafik Tahmininde Problem Türü ve Başarım Ölçütleri
- 5. Lokasyonlar: Ayrı Model, Kümeleme ve Zor Noktalar
- 6. Mobil Dünyaya Giriş: Mobil Hesaplama
- 7. Mobil Donanım ve Geleceğin Cihazları
- 8. İşletim Sistemi Türleri ve Telefonların Evrimi
- 9. Mobil Hesaplamanın Dezavantajları ve Enerji Tüketimi
- 10. Mobil İşletim Sistemlerinin Tarihi ve Güncel Sistemler
- 11. Android ve iOS Mimarisi
- 12. Mobil İşletim Sistemi ile PC İşletim Sistemi Arasındaki Farklar
- 13. Mobil İşletim Sistemi Tasarım Ölçütleri ve Güvenlik
- Örnek Sorular

## 1. Derleme (Survey) Makalesi

Dersin ilk yarısı, akıllı ulaşım alanındaki bir problem üzerine derleme makalesi hazırlamanın yöntemine ayrıldı. Hoca konuya, akıllı ulaşımın bu dersin ilgi alanına girdiğini, özellikle crowdsourcing ile insanların cihazlarından ya da sahaya yerleştirilmiş cihazlardan bilgi toplayıp yorumlayarak çözüm üretmenin bu alandaki temel tekniklerden biri olduğunu hatırlatarak girdi.

### 1.1 Derleme makalesi ile araştırma makalesi farkı

Hoca önce derleme makalesi ile araştırma makalesinin farkını sordu.

**Soru:** Derleme makalesi ile araştırma makalesi arasındaki fark nedir? **Cevap (bir öğrenci):** Derleme makalesinde amaç yeni bir yöntem ortaya koymak değil, literatürdeki mevcut yöntemleri karşılaştırmak ve yorumlamaktır. Hoca bunu onayladı ve genişletti: derleme (survey) makale, o güne kadar yapılmış çalışmaları inceleyerek alanda araştırma yapacak birine okuduğunda o alanla ilgili temel bütün bilgileri sağlayan makaledir.

Derleme makalesi yeni bir test ya da araştırma sonucu sunmaz. Yine de özgün bir yönünün, en azından farklı bir fikrinin olması önemlidir. "Her şeyi aldım, koydum, derledim, sundum" diyen makaleler genelde kabul görmez. Okuyan başka bir araştırmacıyı tetikleyecek bir fikir çıkmalıdır.

Hocaya göre derleme makaleleri akademik değerlendirmede çok puan getirmez, ama çok ciddi atıf alabilir ve yazarının o alanı bildiğinin iyi bir kanıtıdır. Tipik bir derlemede en az 80-150 makale taranır. Bunların hepsinin ayrıntılı içeriğine tek tek bakılmaz; hangi alt alanlara girdikleri belirlenip gruplanarak çalışılır.

> **Hocanın vurgusu:** Derleme makalesinin, özellikle doktora tezi yapacak öğrenciler için en önemli kazancı, alandaki açık problemi yakalama şansıdır. Derlemelerde genelde "Open Issues" başlığı bulunur; burada alanda henüz çözülmemiş konular ortaya konur. Böylece yazar hem kendine bir yol çizer hem de okuyanlara "bu alanlar açık, araştırmaya ihtiyaç var" diyen bir makale hazırlamış olur.

### 1.2 Outline ve makalenin yapısı

Hazırlığın ilk adımı bir outline çıkarmaktır: derlemede hangi başlıklar ve alt başlıklar olacak, hangi konular araştırılacak. Bu iki iş iç içedir. Önce araştırılacak başlıklar kabaca belirlenir, sonra tarama sırasında görülenlere göre outline yeniden şekillendirilir. Outline sağlam olunca alt bölümleri yazmak kolaylaşır. "Bir yerden yazmaya başlayayım, sonra toparlarım" yaklaşımı genelde istenen sonucu vermez.

Makalenin olmazsa olmaz bölümleri şunlardır:

- **Abstract:** En son yazılır.
- **Introduction:** Problem nedir, bu alanda ne tür çalışmalar yapılıyor ve neden yapılıyor, motivasyon nedir, yapılan çalışmaya yakın (yine survey niteliğinde olabilecek) çalışmalar hangileridir ve makalenin geri kalanında hikâye nasıl akacaktır. Genelde sona bırakılır, ama önce yazmayı tercih edenler de olur.
- **Ana bölümler:** Derleme olduğu için ayrı bir "Related Work" bölümü yoktur. Onun yerine konunun önemli ana başlıkları belirlenip belki 3-4 bölüm ve alt bölümler hâlinde yazılır.
- **Open Issues:** Toplanan çalışmalar tartışılır, "bu yapılmış ama şu kısma değinilmemiş, burası açık" denir. Makalenin en değerli kısımlarından biridir.
- **Conclusion:** Abstract ile birlikte en sona bırakılır.

Grafik ve tablo eklenebilir, ama yalnız okuyana gerçekten bir şey kazandırıyorsa. Derlemede alandaki çalışmaları gruplamak çok kritiktir.

> **Hocanın vurgusu:** Bir alana girip tarama yaptığınızda çok sayıda çalışma birikir. Bunları gruplamadan problemleri alt problemlere indirgeme şansınız yoktur.

Hoca ayrıca etraftaki cümleleri birleştirerek oluşturulmuş bir metnin yayın önünde büyük engel olduğunu belirtti. Başka çalışmalardan kalıp ifadeler alınabilir, ama metin birebir aynı olmamalı ve yazarın kendi emeğiyle oluşmalıdır. Uluslararası okuyucuya ulaşması için derlemenin İngilizce yazılması önemlidir; ulusal düzeyde yazılan derlemelerin aldığı atıf sınırlı kalır. Makale yazarken LaTeX kullanmak biçimlendirmeyle uğraşmayı büyük ölçüde ortadan kaldırır.

## 2. Literatür Taraması Nasıl Yapılır

Derlemede en önemli işlerden biri, yapılmış çalışmaları bulmaktır.

**Soru:** Referans çalışmaları bulmak için ilk nereden başlıyoruz? **Cevap (bir öğrenci):** Google Scholar.

Google Scholar'a anahtar kelimeler yazılarak başlanır. Dikkat edilecek iki şey vardır: çalışmaların yayın tarihi (güncelliği) ve aldıkları atıf sayısı. Atıf sayısının düşük olması bir çalışmanın değerini düşürmez. Ama çok atıf almış bir çalışma, özellikle son döneme aitse, kaçırılmamalıdır. Son beş yıl en kritik dönemdir; yine de son 10 ya da 20 yılda yapılmış "kült" çalışmalar varsa onlara da yer verilmelidir. Dergi makaleleri her zaman bir adım öndedir, ama çok iyi konferanslarda çok iyi çalışmalar da yayımlanır ve bunlar da gözden kaçırılmamalıdır.

Google Scholar'ın ötesinde yayıncıların arama motorları taranır: IEEE Xplore, Scopus, ScienceDirect, Springer'in kendi arama motoru.

### 2.1 Önceki derlemeler

Hocaya göre en büyük rakip, o alanda daha önce yazılmış derleme makaleleridir. İlk iş, "survey" anahtar kelimesini de kullanarak (başlıkta her zaman geçmeyebilir) alanda daha önce yapılmış bir derleme olup olmadığına bakmaktır. Varsa bunlar toplanır ve problemi hangi bakış açısıyla ele aldıkları incelenir.

Bir alanda derleme yazılmış olması, başka bir derleme yazılamayacağı anlamına gelmez. Çalışmaları onlardan tamamen farklı biçimde gruplayıp başka bir noktayı öne çıkarmak da değerlidir. Örneğin 3-5 yıl önce yazılmış bir derleme yalnız klasik makine öğrenmesi tekniklerini ele almış, son yıllardaki derin öğrenme çalışmalarını hiç değerlendirmemişse, alanda yeni bir derlemeye ihtiyaç vardır: yöntemler, başarılar ve kısıtlar değişmiş, yeni teknolojiler gelmiştir.

### 2.2 Anahtar kelimeler

Anahtar kelime seçimi çok önemlidir. Hoca bunu bir örnekle anlattı: sensörler sahaya rastgele atıldığında bazıları aynı bölgeye düşer. Kapsama alanını (coverage) en üst düzeye çıkarmak için sensörlerin yerini ya da kameraların yönünü değiştirmek gerekir. Bu problem "multimedia sensor network" ya da "video sensor network" diye arandığında tam istenen sonuçlar gelmiyordu. Sonunda "directional sensor network" kavramına ulaşıldı. Yönlü bakış açısına sahip sensör düğümleri (yalnız kamera değil, mikrofon da) bu gruba girer. Fiziksel bir sensör etrafını 360 derece algılayabilirken kamera ve mikrofon gibi açılı bakan sensörler yalnız belirli bir "pasta dilimini" algılar.

Kısacası literatür, akla gelen anahtar kelimelerin dışındaki bir terimle genişlemiş olabilir; bunu yakalamak çok şeyi değiştirebilir.

### 2.3 Kaynakçadan geriye doğru tarama

Bulunan çalışmaların kaynakça bölümleri çok değerlidir. Kaynakçalardan özyinelemeli olarak geriye doğru gidildiğinde çok değerli bir referans listesi oluşur. Böylece Google Scholar'da ya da veritabanlarında bulunamayan çalışmalar, o alandaki araştırmacıların işaret ettiği yerlerden bulunur. Yalnız makale ve bildiri değil; patent, kitap ve tez de doğrudan kaynak gösterilebilecek önemli çalışmalardır.

## 3. Trafik Akış Tahmini: Problemin Bakış Açıları

Derlemenin konusu trafik akış tahminidir. Meteorolojide hava durumu nasıl tahmin ediliyorsa, burada da trafik akış hızı tahmin edilmeye çalışılır. Hoca problemin tek bir bakış açısı olmadığını vurguladı ve öğrencilerle birlikte bakış açılarını çıkardı.

### 3.1 Öğrencilerden gelen ilk fikirler

- Günün saatine, yolların yoğunluğuna ve geçmiş verilere dayalı tahmin.
- Otonom araçlar yaygınlaştığında insan sürücülerle otonom sürücülerin trafiğe etkisi. Hoca bunun ileriye dönük, "Open Issues" bölümüne uygun bir başlık olduğunu söyledi.
- Geçmiş veriden geleceği tahmin etme (future prediction). Başka problemlerde bu bakış açısıyla geliştirilen çözümlerin trafiğe uyarlanıp uyarlanamayacağı da düşünülebilir.

### 3.2 Tahmin ufku: kısa, orta ve uzun vade

Hoca literatürdeki temel ayrımlardan birini verdi. Literatürde en yaygın olan kısa vadeli (short term) trafik akış tahminleridir, ama orta vadeli (mid term) kavramıyla da karşılaşılır. Bu ufukların tanımlanmış süreleri vardır ve çalışmadan çalışmaya biraz değişir:

- **Kısa vade:** yaklaşık bir-iki saate kadar.
- **Orta vade:** yaklaşık iki saat ile beş-altı saat arası.
- **Uzun vade:** sonrası; örneğin ertesi günü, 12 saat sonrasını ya da iki gün sonrasını tahmin etmek.

Uzun vadeli tahminle ilgili çok az çalışma vardır ya da bu çalışmalar yeni yeni yapılmaktadır. Bir derleme yalnız kısa vadeye ya da yalnız uzun vadeye odaklanabilir; ya da üçünü birlikte ele alıp problemi bu üç kola ayırarak kurgulanabilir.

### 3.3 Terimler ve yöntemler

Literatürde aynı probleme çok farklı adlarla rastlanır: traffic prediction, traffic flow prediction, traffic speed prediction, traffic flow speed prediction, traffic flow estimation, traffic estimation. Derlemenin başında problemin literatürde hangi adlarla ele alındığını ve bu adlar arasında gerçekten bir fark olup olmadığını belirtmekte fayda vardır.

Derlemede tartışılabilecek sorular şunlardır: Hangi temel yaklaşımlar kullanılıyor; istatistiksel yöntemler mi, örnek tabanlı öğrenme (instance-based learning) mi, derin öğrenme mi? Aralarındaki fark nedir? Problem gerçekten derin öğrenmeye ihtiyaç duyacak kadar karmaşık mı? Kısa vade için kullanılan yaklaşım uzun vadeye uygulanabilir mi?

### 3.4 Veri setleri ve girdi parametreleri

Literatürde hangi veri setlerinin kullanıldığı, bunlarda hangi özniteliklerin bulunduğu ve modele girdi olarak neler verilebileceği de derlemenin konusudur. Trafik akış hızı ve zamanın (haftanın günü, saat, ay) yanında sınıfta şu parametreler konuşuldu:

- **Hava durumu ve araç tipi.** Hoca hava durumunun çok önemli olduğunu söyledi. Şu an probleme en çok katılmaya çalışılan parametreler meteorolojik olanlardır: yağmur ya da buzlanma trafiğin şeklini değiştirir. Kış ortasında hafta sonu güneş açması bile trafiği etkiler.
- **Kullanıcı özellikleri.** Bir öğrenci, sürücünün nereden çıkıp nereye gittiğinin, ara sokak mı otoyol mu kullanacağının da kategorize edilebileceğini söyledi.
- **Etkinlikler.** Maç olan günlerde ilgili bölgede trafik tamamen kilitlenebilir. Etkinliğin büyüklüğü, o bölge ve komşu bölgeler için çok önemli bir parametredir. Düğün, asker uğurlaması gibi özel etkinlikler ve kutlamalar gibi halk etkinlikleri de hesaba katılabilir.
- **Afetler ve özel dönemler.** Deprem, sel gibi doğal afetler ve yangın gibi olaylar trafiği etkiler. Bu, problemin özel dönemler için ayrıca çözülmesi gerektiği tartışmasını açar. Örneğin bayramlarda trafik akışı normal akıştan tamamen farklıdır. Bu, sisteme bir parametre olarak mı verilmeli, yoksa bu dönemler için ayrı modeller mi kurulmalı? Deprem sonrası günlerde trafiğin nasıl seyrettiği de kategorize edilip tabloda verilebilir.
- **Yol çalışmaları.** Bir öğrenci, bakım çalışması ve şerit kapamaları gibi güncel yol bilgilerinin yoğunluğu doğrudan etkilediğini söyledi. Hoca bunu çok önemsediği bir başlık olarak niteledi. Bu bilgiler karayolları idaresinden ve büyük şehirlerde belediyeden gelir; bakımın ne zaman başlayıp ne kadar süreceği sisteme girilmelidir. Problem bu hâliyle büyük veri içeren bir problemdir.
- **Yapısal özellikler.** Bir öğrenci sohbet penceresinden trafik ışıklarını ve virajları ekledi. Bunlar da trafiğin hızını etkiler.
- **Kaza ("kader parametresi").** Kaza önceden belli değildir. Yine de bir bölgedeki kaza sıklığı gün, saat ve zaman bazında modele katılarak bir risk parametresi oluşturulabilir. Bu tür kaza verileri sigortacılık şirketlerinde ve emniyet birimlerinde bulunur. Araç arızası gibi hiç hesaba katılamayan olaylar da vardır.
- **Komşu lokasyonlar.** Dersin ikinci yarısının başında hoca bir parametre daha ekledi: bir lokasyonun etrafındaki diğer lokasyonlardan gelen bilgi. Örneğin bir köprü girişinde bir sensör, onun hemen gerisinde başka sensörler vardır ve bunlar birbirine bağlıdır. Bu bağlı yapı bir graf gibi düşünülüp bağlantıların bilgisi kullanılarak tahmin iyileştirilebilir. Hoca bunun aktif olarak araştırılan bir yaklaşım olduğunu söyledi.

Parametreleri doğrudan ve dolaylı etki edenler, etkisi yüksek ve düşük olanlar diye sıralamak bile çok önemli bir çıktıdır. Ama bu sıralama bilimsel olarak desteklenmelidir: ya bir formülle, ya bir deneyle, ya da önceki çalışmalara atıf yaparak.

> **Hocanın vurgusu:** Trafik tahminine etki eden parametrelerin listesini çıkarmak başlı başına harika bir çıktıdır. Ama bu bilgilerin nereden alınabileceğini de paylaşmak gerekir.

### 3.5 Veri kaynakları

Veri kaynakları iki anlamda düşünülmelidir. Birincisi parametrelerin kaynaklarıdır: bazı bilgiler açık veri olarak paylaşılır, bazıları API'ler üzerinden kolayca çekilir, bazılarını temin etmek ise mümkün değildir. Tablolarda bu durum "açık / var / yok" gibi başlıklarla gösterilebilir.

İkincisi hız verisinin toplandığı kaynaklardır. Hız verisi araçlardan ya da telefonlardan toplanabilir. Yol kenarındaki tabelalar araçların Bluetooth sinyalini okuyup giriş ve çıkış zamanlarını kaydederek hızı ölçebilir. Yol kenarı birimleri (roadside unit) ile ölçüm yapılabilir. Yolun altına konan ve metal yoğunluğunu algılayan dedektörler araç yoğunluğunu ölçer; araçlar yavaş hareket ettiğinde yoğunluk yüksek görünür. Kullanılan kaynağa göre veri de değişir.

Hoca bir inceliğe dikkat çekti: bir bölgede yolun açık olması, hızın doğru tespit edildiği anlamına gelmez. Hız sınırı izin veriyorsa 100 ile gidilebilecek bir yolda bir sürücü 60 ile gidiyorsa, ya da bir kamyon yavaş geçiyorsa, o bölgenin 60 ile geçilebileceği sonucu çıkmaz. Bölgenin hız tahmini yapılırken bu durum göz önüne alınmalıdır.

### 3.6 Problemin ikinci ucu: rotalama

Bir öğrencinin sürücünün rotasına değinmesi üzerine hoca problemin iki ucu olduğunu açıkladı. Birinci uçta sensör ya da lokasyon bazlı hız tahmini yapılır. İkinci uçta bu tahminler rotalama algoritmalarıyla birleştirilerek en hızlı rota üretilir. Derlemenin bu tarafa ne kadar gireceği tartışılır, ama en azından tahminlerin çıktılarının birleştirilmesinin de önemli olduğu vurgulanmalıdır.

## 4. Trafik Tahmininde Problem Türü ve Başarım Ölçütleri

### 4.1 Sınıflandırma mı, regresyon mu?

**Soru:** Trafik tahmini nasıl bir problemdir; sınıflandırma mı, regresyon mu, gözetimsiz mi? **Cevap:** Bir öğrenci, mevcut durumlardan öğrenildiği için daha çok gözetimli (supervised) bir problem olduğunu söyledi. Hoca da "geçmişte şu şartlarda hız şöyle olmuş" diye etiketlenmiş veri kullanıldığı için gözetimli yaklaşımın uygun olduğunu onayladı. Başka bir öğrenci, akış hızı tahmin edildiği için problemin regresyon olarak ele alınması gerektiğini söyledi.

Hoca bunu netleştirdi: bu bir regresyon problemidir, çünkü sürekli (continuous) bir değer tahmin edilir. Bir bölgenin o saatte kırmızı, sarı, turuncu ya da yeşil olup olmadığı tahmin edilmek istenseydi problem bir sınıflandırma problemine indirgenebilirdi. Ama burada bir lokasyondaki hızın belirli bir saat ve dakikada ne olacağı tahmin edilir.

> **Ders sonrası not:** Hoca 00:41:01'de "kontinuyus veriler var. Yani diskret veriler tahmin etmeye çalışıyoruz" dedi. Bağlamdan anlaşıldığı üzere kastedilen sürekli değer tahminidir; ayrık (discrete) değer tahmini sınıflandırmaya karşılık gelir.

### 4.2 Regresyon ölçütleri

Sınıflandırmada recall, precision, accuracy ve F-measure gibi ölçütler kullanılır. Regresyonda ise:

- Gerçek ile tahmin arasındaki farkın karesine dayanan karesel hata (bir öğrencinin önerisi); bunun kökü alınarak ya da alınmadan kullanılır.
- MAE (Mean Absolute Error).
- MAPE (Mean Absolute Percentage Error).

> **Ek bilgi (derste anlatılmadı):** Bu ölçütlerin yaygın tanımları şöyledir: $\mathrm{MSE}=\frac{1}{n}\sum_{i}(y_i-\hat{y}_i)^2$, $\mathrm{RMSE}=\sqrt{\mathrm{MSE}}$, $\mathrm{MAE}=\frac{1}{n}\sum_{i}|y_i-\hat{y}_i|$, $\mathrm{MAPE}=\frac{100}{n}\sum_{i}\left|\frac{y_i-\hat{y}_i}{y_i}\right|$. Burada $y_i$ gerçek, $\hat{y}_i$ tahmin edilen değerdir.

### 4.3 Mutlak hata ile yüzde hata

Hoca mutlak ve yüzdesel hata arasındaki farkı bir örnekle gösterdi.

- Verilen: gerçek hız 30 km/sa, tahmin 36 km/sa.
- Mutlak sapma: $|36-30| = 6$ km/sa.
- Yüzdesel hata: $6/30 = 0{,}20$, yani %20.
- Verilen: gerçek hız 60 km/sa, sapma yine 6 km/sa.
- Yüzdesel hata: $6/60 = 0{,}10$, yani %10.

Mutlak sapma iki durumda da 6 km/sa'tir, ama yüzdesel hata yarı yarıya farklıdır. Düşük hızlardaki sapmanın etkisi ile yüksek hızlardaki sapmanın etkisi farklıdır. Bu yüzden MAPE mi, MAE mi, yoksa karesel hata mı tercih edilmeli ve hangisi daha anlamlıdır, bunu tartışmak da derlemenin konusudur.

### 4.4 Karşılaştırılabilirlik sorunu

> **Hocanın vurgusu:** Bu alandaki çalışmaların en büyük sorunlarından biri, iki yaklaşımı karşılaştırırken elma ile armudu karşılaştırma durumunun ortaya çıkmasıdır. Herkes belirli bir ülkenin belirli bir şehrinin veri setini kullandığı için ortak veri seti azdır. Aynı veri setini kullanan çalışmalar zaman zaman çıkar, ama bu en önemli sorunlardan biridir.

Derlemede şunlar ortaya konmalıdır: hangi başarım ölçütleri kullanılıyor; şimdiye kadarki çalışmalar hangi yöntemleri kullanmış ve ne kadar başarılı olmuş (artı eksi kaç km/sa hata ya da yüzde kaç hata); trafik karmaşıklığı yüksek bir şehirde ulaşılan en iyi nokta nedir ("şu yılda, şu şehirde, şu şartlarda, şu veriyle hata şuraya kadar indirilmiş" biçiminde). Bir şehirde eğitilen modelin başka bir şehre uygulandığında aynı başarıyı verip vermeyeceği de bir soru işaretidir.

Hoca ayrıca bazı makalelerin sonucu bile net vermediğine dikkat çekti. Bu yüzden karşılaştırma tablolarında "not available" gibi bir ifade kullanmak gerekebilir. Kategorizasyon yapıldıktan sonra tabloların hangi başlıklarla kurulacağına karar verilmelidir.

## 5. Lokasyonlar: Ayrı Model, Kümeleme ve Zor Noktalar

### 5.1 Lokasyon başına model mi, ortak model mi?

Büyük bir şehirde binlerce sensör lokasyonu vardır (hoca İstanbul için yaklaşık 7 bin ile 10 bin arası sayı verdi). Her lokasyon için ayrı öğrenme yapıp ayrı model kurmak mümkündür. Bir öğrenci lokasyonların kümelenip kümeler üzerinde model kurulabileceğini önerdi.

Hoca iki seçeneği şöyle değerlendirdi: her lokasyonu tek tek modellemek en özel ve en güzel çözümdür, ama maliyeti yüksektir; her lokasyon için ayrı ayrı eğitmek ve ayrı modeller çalıştırmak gerekir. Bunu verimli hâle getirmenin yolu, trafik karakteristiği birbirine benzeyen lokasyonları kümeleyip onlar için ortak model kullanmaktır. Bu çok akıllıca bir yaklaşımdır. Belirli bölgelerde trafik akşam ve sabah hemen hemen aynı karakteristiği gösterir. Tek tek modelleme ile ortak modelleme arasındaki fark da ortaya konmalıdır: arada ciddi bir başarı farkı varsa gruplamadan vazgeçmek gerekebilir. Hoca, trafik karakteristiği benzer noktaların bulunmasını ve bunun tahmin başarısına etkisini zevkli bir araştırma konusu olarak gösterdi.

### 5.2 Tahmini en zor noktalar nasıl bulunur?

Hoca şu soruyu sordu: kısa bir zamanınız var ve binlerce lokasyon içinden tahmini en zor olan, örneğin ilk yüz noktayla uğraşmak istiyorsunuz. Kolay yeri tahmin etmenin bir esprisi yoktur; her gün aynı saatlerde aynı karakteristiği gösteren bir yeri tahmin etmek zor değildir. Peki en zor noktalar nasıl belirlenir?

- Bir öğrenci yoğun trafiğin olduğu yerleri, sanayi ve okul bölgelerini ve etkinliklerin kesiştiği yerleri önerdi. Hoca bunun yanlış olmadığını, ama alternatif bir fikrin peşinde olduğunu söyledi.
- Başka bir öğrenci en çok talep edilen noktaları önerdi. Hoca buna ana arterleri ekledi: ara sokaklardan önce ana arterlerdeki problemleri çözmek tercih edilebilir.
- Üçüncü bir öğrenci, gözlemlenmesi zor, bir gün çok sıkışık diğer gün boş olan, "karakteristik davranmayan" yolları önerdi. Hoca aradığı anahtar kavramın bu olduğunu söyledi.

Karakteristik davranmayan yerleri tespit etmenin kolay bir yolu, her lokasyondaki hızların standart sapmasını bulmaktır. Standart sapması yüksek bir lokasyonda değişiklikler de fazladır. Karşı argüman olarak "sabah hep yavaş, akşam hep hızlı olan bir yerin standart sapması da yüksek çıkar, ama tahmini kolaydır" denebilir. Hoca bunun doğru olduğunu kabul etti; yine de lokasyonları standart sapmaya göre sıralamak, hızların değişkenlik gösterdiği yerleri bulmak için iyi bir ilk adımdır. Bu yöntem karakteristiği değişen yerleri yüzde yüz vermez, ama güçlü bir ipucu verir.

> **Ek bilgi (derste anlatılmadı):** Örneklem standart sapması $s=\sqrt{\frac{1}{n-1}\sum_{i}(x_i-\bar{x})^2}$ biçiminde hesaplanır. Günün saatine bağlı düzenli bir değişimi ayırmak için standart sapmanın her saat dilimi içinde ayrı hesaplanması büyük olasılıkla daha anlamlı bir zorluk ölçüsü verir.

Hoca son olarak beklentisinin konuşulan her şeyi içeren bir çalışma olmadığını söyledi; bunlar ancak 30 sayfayı aşan çok daha kapsamlı bir derlemeye sığar. Önemli olan, okuyanın alanın temel bilgilerini alması ve farklı bir gruplama ya da bakış açısıyla "şu noktayı düşünmek güzel olabilir" diyebilmesidir.

## 6. Mobil Dünyaya Giriş: Mobil Hesaplama

Dersin ikinci yarısında "Mobile World" başlıklı haftalık sunuma geçildi (ekrandan, 01:15:00). İlk derste genel kavramlar tanıtılmıştı; bu derste mobil dünyaya daha ayrıntılı bir giriş yapıldı.

### 6.1 Önceki haftalardan hatırlatma: çevresel zeka

Geçen haftalarda bağlam (context) ve bağlam farkındalığı (context awareness) konuşulmuştu. Çevresel zeka (ambient intelligence), ortamdaki kişisel aktiviteleri algılayan ve bunlarla ilgili çözüm üretebilen bütün elektronik cihazlardan oluşan sistemlere verilen addır. Bu kavram geçmişte çok daha sık kullanılıyordu. Günümüzde yerini "smart" sözcüğüyle başlayan alt alanlara bıraktı: akıllı ulaşım (smart transportation), akıllı şehir (smart city), akıllı binalar (smart buildings).

Çevresel zekanın önemi şudur: insanlarla aynı dili konuşan cihazlar üretebilmek için önce cihazların çevresel farkındalığını sağlamak gerekir. Bunun yolu sensörleri kullanmak ve onlardan toplanan verileri yorumlamaktır. Trafik tahmini örneğinde görüldüğü gibi, tek bir problemde bile onlarca başlık çıkar.

### 6.2 Mobil hesaplamanın tanımı

Slayttaki tanım (ekrandan, 01:15:00): "Mobile Computing is a technology that allows transmission of data, voice, and video via a computer or any other wireless enabled device without having to be connected to a fixed physical link." Yani mobil hesaplama; veri, ses ve görüntünün, sabit bir fiziksel bağlantıya gerek kalmadan bir bilgisayar ya da kablosuz iletişim yapabilen herhangi bir cihaz üzerinden iletilmesini sağlayan teknolojidir.

Mobil hesaplamayla birlikte konumdan, zamandan ve cihazdan bağımsız hareket etmek mümkün oldu. Bu da verinin kablolara ihtiyaç olmadan taşınabildiği bir dönemi ifade eder.

**Soru:** Kablosuz iletişim ne kadar süredir var? Bir öğrenci Tesla'dan beri var olduğunu, bir diğeri radyolardan beri var olduğunu, bir başkası telgrafın da bir veri iletimi olduğunu söyledi. Hoca soruyu daralttı: bugün düşündüğümüz anlamda dijital veriyi kablosuz taşımak ne kadar süredir yapılıyor? **Cevap:** Bir öğrenci 15-20 yıl dedi. Hoca yaklaşık 20 yıllık bir hikâyeden söz edildiğini onayladı. Her şeyin kablosuz hâle gelmesini sağlayan akıllı telefonlardır ve bu dönüşüm yaklaşık 2007-2008'de başlar; 2010'lu yıllardan itibaren çevremiz yoğun radyo sinyalleriyle doludur.

### 6.3 Mobil hesaplamanın üç bileşeni

Hareketlilik özelliği üç başlık getirdi (ekrandan, 01:20:00):

- **Mobile Communication:** Çok farklı protokoller vardır; ilerleyen haftalarda yeri geldikçe işlenecek.
- **Mobile Hardware:** Yalnız telefonlar değil; son dönemde giyilebilir cihazlar ve gömülü sistemler. Amaç, insanın rahatça ve estetik kaygı duymadan taşıyabileceği olabildiğince küçük cihazlar tasarlamaktır.
- **Mobile Software:** Bütün bu mobil cihazlar için geliştirilen yazılımlar. Mobil işletim sistemleri bunların en önemlilerinden biridir.

## 7. Mobil Donanım ve Geleceğin Cihazları

### 7.1 Mobil donanıma damga vuran firma

**Soru:** Mobil donanımda damga vuran firma hangisidir? Öğrenciler sırasıyla Apple'ın akıllı saatini, çok sayıda sensör üreten Sony'yi, Nvidia'yı ve ARM'yi söyledi. Hoca ARM'ye gelmek istediğini söyleyip şunu sordu: ARM, komut kümesi olarak RISC mimarisini mi, CISC mimarisini mi kullanır? **Cevap:** RISC.

ARM, azaltılmış komut kümesi (Reduced Instruction Set) mimarisiyle enerji verimliliğinde Intel'in çok önüne geçti. Intel de bu pazara girmeye çalışıyor ve zaman zaman cihazları görülüyor. Ama doğru hamleleri yapan firma o alanda kalıcı olur ve rakiplerini alana sokmaz. Masaüstünde bir dönem Microsoft'un yaptığı gibi; Microsoft da bütün çabasına rağmen mobil alana tam olarak giremedi.

### 7.2 Gelecek beklentisi

Hoca her yıl sorduğu bir soruyu sordu: "Yeni bir dönem başlıyor" dedirtecek bir sonraki teknoloji ne olabilir? Bir öğrenci dışarıdan giyilen, omurgayı ve kemikleri destekleyen, insanın hareket kabiliyetini artıran dış iskelet (exoskeleton) cihazları beklediğini söyledi. Hoca buna sanal deneyimlerin (örneğin konsolda boşlukta raket sallayarak tenis oynamanın) kas sistemini zayıflatabileceği yorumunu ekledi.

**Soru:** Vücudumuzun teknolojik gelişmeden en çok etkilenen ve zarar gören noktası neresidir? **Cevap:** Bir öğrenci önce gözü, sonra boynu söyledi; hocanın kastettiği boyundu. Toplu taşımada oturan ve ayakta duran herkes sürekli telefona bakma pozisyonundadır; boyunla ilgili şikâyetler ve tedavi süreçleri artmıştır. Hocaya göre dış iskelet tarzı teknolojik destekler, bu tür sağlık sorunlarını gidermek için büyük olasılıkla hayatımıza girecek.

## 8. İşletim Sistemi Türleri ve Telefonların Evrimi

### 8.1 Mobil işletim sisteminin normal işletim sisteminden farkı

**Soru:** Mobil işletim sistemlerinin normal işletim sistemlerinden farkı nedir? Öğrencilerden gelen cevaplar:

- RISC mimarisi üzerinde çalıştığı için enerji tasarrufu yapması gerekir. big.LITTLE mimarisinde büyük çekirdekler kullanılmadığında kapatılır, küçük çekirdekler kullanılır. Bu performans sorunlarını da beraberinde getirir ve işletim sistemi buna göre optimizasyon yapmak zorunda kalır.
- En büyük fark pilin kısıtlı olmasıdır. Bu yüzden işlemler istendiği kadar yüksek frekansta yapılamaz. big.LITTLE yönetimi işletim sistemi katmanına taşar: çok güç gerektiren işler için işlemcinin büyük kısmı devreye alınır, diğer işler için küçük (LITTLE) kısım kullanılır. Bunu yönetmek başlı başına işletim sisteminin bir yeteneğidir.
- İletişim tarafında da optimizasyon gerekir. İşletim sistemi iletişim sıklığını doğru ayarlamalı ve sınırlı kaynakları doğru idare etmelidir. Mobil işletim sistemlerinde verilecek hemen bütün örneklerin sonu, kısıtlı kaynakların doğru yönetilmesine çıkar.

Hoca bunu bir kaynak optimizasyonu problemi olarak özetledi. Yaklaşık 20 yıl önce bilgisayarlarda da RAM ve ikincil bellek kısıtlıydı ve yazılımlar buna göre geliştiriliyordu. Telefonlar gelince aynı kısıtlar yeniden başladı. Bugün kaynaklar oldukça zenginleşmiş olsa da her şey dönüp dolaşıp enerjiye bağlanır. Hocanın esprisiyle, kimyacılar bir ay dayanan bir pil bulsa, bu alanda araştırma yapan bilgisayar mühendislerinin bir kısmının problemi kalmaz.

> **Hocanın vurgusu:** Teknolojik olarak devrim yaratacak alanlardan biri pil, yani enerji depolama teknolojisidir. Güncel telefonlarda ekran büyüdükçe enerji tüketimi artar, ama batarya da büyüyerek bu fark telafi edilmeye çalışılır. Sonuçta mobil işletim sistemlerinde kaynak yönetimine çok daha fazla dikkat etmek gerekir; masaüstü bir PC işletim sisteminde böyle bir kaygı yoktur.

İletişimde de durum benzerdir. PC'de birkaç bağlantı yolu vardır, ama kaynak yönetimi açısından bunlar arasında geçiş yapma zorunluluğu yoktur. Telefonda ise işletim sistemi, daha önce tanıdığı bir kablosuz ağa girildiğinde ağı tarar ve bulduğu anda kendiliğinden kablosuz bağlantıya geçer. İlk dönemlerde bu iş elle açılıp kapatılarak yapılıyordu.

### 8.2 İşletim sistemi kategorileri

**Soru:** İşletim sistemlerini kaç başlık altında kategorize edersiniz? Sınıfta şu kategoriler çıktı:

- **Masaüstü işletim sistemleri (Desktop OS):** PC'ler için.
- **Mobil işletim sistemleri (Mobile OS).**
- **Sunucu işletim sistemleri (Server OS):** Masaüstü PC'lere benzeseler de aynı anda çok sayıda kullanıcıyı, eldeki kaynakları paylaştırarak yönetmek zorunda oldukları için farklı tasarlanırlar.
- **Gömülü işletim sistemleri (Embedded OS):** Örneğin sensör ağları için tasarlanmış TinyOS ve Contiki.
- **Gerçek zamanlı işletim sistemleri (Real-Time OS):** Bir öğrencinin özetiyle, uçak gibi ani ve hassas işlemlerin yapıldığı makinelerde işlemin gerçek zamanlı yapılmasını sağlayan sistemlerdir; donanım da bunu destekler.

### 8.3 Telefonların evrimi

Hoca haberleşmenin gelişiminde telefonun rolünü özetleyen bir zaman çizelgesi gösterdi (ekrandan, 01:35:00). Slayttaki "Evolution of Phones" görselinde şu yıllar yer alır: 1876, 1898, 1920, 1963, 1973, 1980, 1992, 2013. Hikâye 1876'da başlar, 1970'lerden itibaren kablosuz telefonlara gelinir ve özellikle 2000'li yıllardan itibaren akıllı telefonlara geçilir.

Akıllı telefonları akıllı yapan şunlardır: işlem yeteneğinin artması, çevreleriyle iletişim kurabilmeleri ve kamera, mikrofon ve çeşitli sensörlere sahip olmaları.

### 8.4 Feature phone ve KaiOS

Feature phone, yalnız telefon konuşması ve mesajlaşma yapılabilen düz telefonlara verilen addır. Bütün telefonların genel adı mobile phone olsa da bu eski tip telefonlara feature phone denir. Akıllı telefonlar için Android, iOS ve Symbian gibi işletim sistemleri yazıldı. Symbian, işin en başında yer alan ilk mobil işletim sistemi sayılabilir.

**Soru:** Feature phone'ların bir işletim sistemi var mı? **Cevap:** Bir öğrenci, işletim sisteminin genelde çoklu görev (multitasking) olan ve kaynak yönetiminin gerektiği yerlerde kullanıldığını söyledi. Feature phone'larda donanım düzeyinde bir mantık vardır, ama işletim sistemini gerektirecek karmaşıklık yoktur. Hoca da bu telefonlarda normalde bir işletim sistemi olmadığını, arka planda gömülü bir cihaz için çalışan ve telefonun yeteneklerini yöneten bir yazılım bulunduğunu söyledi; buna middleware demek daha doğrudur.

Son dönemde ise feature phone'ları hedefleyen bir işletim sistemi çıktı. Hocanın anlattığına göre bu sistemin çıkış noktası şuydu: dünyadaki telefon kullanıcılarının önemli bir bölümü, özellikle Afrika ve Asya'da, maddi nedenlerle akıllı telefon kullanamıyor. Ellerinde arama, mesajlaşma ve biraz da internet erişimi olan standart telefonlar var. Bu telefonlarda çalışan ve bir mağaza üzerinden YouTube, Twitter, Instagram gibi temel uygulamaların yüklenmesini sağlayan bir işletim sistemi geliştirildi. Hoca adını dersin ilerleyen bölümünde verdi: **KaiOS** (K-A-I-O-S). Hocaya göre bu, telefonların önemli bir kısmını kısmen akıllı hâle getirmenin iyi bir yoludur, kaynakları da büyük olasılıkla daha verimli kullanır.

## 9. Mobil Hesaplamanın Dezavantajları ve Enerji Tüketimi

### 9.1 Dezavantajlar

Slaytta mobil hesaplamanın dezavantajları şöyle sıralanır (ekrandan, 01:40:00):

- Expensive (pahalı).
- Short battery life (kısa pil ömrü).
- Small screen display (küçük ekran).
- Slow internet speed (yavaş internet).
- Communication depends upon network (iletişim ağa bağımlı).
- Risky to carry (taşıması riskli).
- Security (güvenlik).

Hoca bunların standart bilgiler olduğunu belirtti. Kısa pil ömrü hâlâ bir sorundur. Yavaş internet ise artık söz konusu değildir; çok yüksek hızlarda iletişim kurulabilir. Ama bir ağa ihtiyaç olduğu kesindir. Bu ağın, veri taşınırken ortamdaki girişimlerden (interference) çok etkilenmemesi gerekir; verinin doğru aktarılıp aktarılmadığı ve çıkış gücünün ayarlanması gibi sorunlar telefonda hâlâ yaşanır.

### 9.2 Mobil işletim sisteminin yönettiği bileşenler

Slayttaki tanıma göre mobil işletim sistemi akıllı telefonlar, tabletler, PDA'lar ve diğer mobil cihazlar için bir işletim sistemidir (ekrandan, 01:40:00). Yönettiği bileşenler: dokunmatik ekran, hücresel iletişim, Bluetooth, Wi-Fi, GPS ile mobil navigasyon, kamera, video kamera, konuşma tanıma, ses kaydedici, müzik çalar, yakın alan iletişimi (NFC) ve kızılötesi verici (infrared blaster). Bunların yanında bütün uygulamaların yönetimi de işletim sisteminin işidir.

### 9.3 En çok enerji tüketen bileşenler

**Soru:** Bu bileşenler içinde en çok enerjiyi hangisi tüketir? **Cevap:** Bir öğrenci hücresel haberleşmeyi söyledi; sinyalin zayıf olduğu durumlarda bağlantı için daha fazla güç harcandığından tüketim daha da artar. İkinci aday dokunmatik ekrandır. Hoca bu ikisinin en çok öne çıkan başlıklar olduğunu söyledi. Ardından açık kaldığında pili ciddi tüketen GPS ve Bluetooth gelir. Onların hemen arkasında kamera vardır; yeni nesil telefonlarda saniyede 60 ya da 120 kare, 4K ya da Full HD çekim ciddi enerji gerektirir.

### 9.4 Eski telefonlar sensör düğümü olarak

Hoca eski telefonların birer sensör düğümü olarak kullanılabileceğini söyledi: kamera ya da mikrofon olarak kullanılabilir, birbirleriyle haberleştirilebilirler; bu konuda çeşitli projeler vardır. Çöpe gitmelerindense ciddi işlem ve kaynak kapasiteleri değerlendirilebilir. Tek ihtiyaç telefonun bir enerji kaynağına bağlı olmasıdır. Örneğin ek donanım almadan, eski bir telefonu kamera ve mikrofon olarak kullanan bir yazılımla bir bebek monitörü uygulaması kolayca gerçekleştirilebilir. Bugünkü telefonlar beş yıl sonra eskidiğinde güçlü birer IoT cihazı olarak kullanılabilecektir.

### 9.5 Ekranın enerjisini azaltmak

**Soru:** Ekranın enerji tüketimini azaltmak için hangi yöntemler var?

- **OLED teknolojisi (donanımsal çözüm):** Bir öğrenci yalnız belirli LED'lerin yandığı ekranları hatırlattı. Hoca bunun televizyonlarda da çok uygulanan OLED teknolojisi olduğunu söyledi. Firmalar farklı adlar verse de (örneğin QLED) prensip noktasal piksellerin tek tek yanıp sönmesidir. Bu ekranlar tam siyahı sağlayabilir ve arka planda sürekli yanan bir ışık gerekmediği için enerji tasarrufu sağlar.
- **Koyu tema (yazılımsal çözüm):** Bundan beş yıl önce pek rağbet görmeyen koyu temalar, işletim sistemlerinin bu işe el atmasıyla yaygınlaştı. Bugün neredeyse her uygulama geliştirici, biri koyu olmak üzere iki tema ekliyor. Bu, OLED ekranı daha verimli kullanır ve enerji tüketimini ciddi oranda azaltır.
- **E-mürekkep ekranlar:** Bir öğrenci Amazon Kindle cihazlarındaki Paperwhite ekranların enerji tasarrufunun çok yüksek olduğunu hatırlattı. Hoca, bir dönem bir üreticinin bir yüzünde klasik ekran, diğer yüzünde Kindle benzeri ekran olan çift ekranlı bir telefon çıkardığını anlattı. İşlerin çoğu e-mürekkep tarafında yapılıyor, yalnız gerektiğinde klasik ekrana geçiliyor ve telefon çok uzun dayanıyordu. Hocaya göre bu teknolojinin arkası gelmedi; tıpkı Google Glass gibi denendi ama tutmadı. Kullanıcılar sürekli açık ekran istiyor; akıllı saatler bile "hiç kapanmayan ekran" diye tanıtılıyor.

### 9.6 Diğer enerji tasarrufu yöntemleri

- **İşlemci frekansını yönetmek:** Bir öğrenci, işlemci frekansını yöneten temel bir programın (governor) olduğunu ve bunun yazılımsal olarak optimize edilebildiğini söyledi. Hoca bunu işlemci frekansıyla oynamak olarak özetledi.
- **Ayrı bir sensör işlemcisi:** Telefona iki işlemci koyup birini ana işlerden, diğerini sensörlerden sorumlu yapmak.
- **Arka plan işlerinin sıklığını ayarlamak:** Örneğin bir mesajlaşma uygulaması kontrolünü saniyede bir yerine 5 ya da 10 saniyede bir yapar. Bu özellikleri işletim sistemi sunar, uygulama geliştiriciler kullanır.
- **Bildirim yönetimi:** Eskiden SMS'te yaşanan kirlilik bugün bildirimlerde yaşanıyor. Android, belirli bir süre içinde gelen bildirimleri gruplayarak göstermek gibi önlemler aldı.

Governor'ın kullanıcıya açılması önerisi üzerine hoca, telefonlarda bilgisayardaki gibi çoklu kullanıcı kavramı olmadığını hatırlattı. Telefon ya tek kullanıcıyla ya da root yetkisiyle kullanılır. Kullanıcıya bütün yönetici haklarını vermek farklı güvenlik sorunlarına yol açtığı için istenmez.

Bir öğrenci şu noktaya dikkat çekti: mobil uygulamaların çoğu paralellik gözetilmeden yazılıyor ve ortalama en fazla iki iş parçacığı kullanıyor, oysa cihazlarda dört ya da sekiz çekirdek bulunuyor. Tek çekirdeği kullanan bir uygulamada çekirdek belirli bir frekansın ve sıcaklığın üstüne çıkınca kapatılıyor (ya da yavaşlatılıyor); normalde bir dakikada bitecek bir iş bazen birkaç katı sürebiliyor. Hoca bunun donanım ile yazılımın paralel gitmediği noktalardan biri olduğunu, mobil uygulamaların kaynak yönetiminde bugün çok verimli çalışmadığını ve bu yönde yapısal düzenlemeler bekleneceğini söyledi.

## 10. Mobil İşletim Sistemlerinin Tarihi ve Güncel Sistemler

### 10.1 Zaman çizelgesi

Slaytta 2006-2012 arası mobil işletim sistemlerinin zaman çizelgesi gösterildi (ekrandan, 02:05:00). Çizelgede LiMo, MeeGo (ikisi Tizen'de birleşir), Symbian, webOS, Windows Mobile / Windows Phone, bada, iOS ve Android sürüm hatları yer alır. İşin başlangıcını Symbian yapar, ardından iOS ve Android devreye girer.

**Soru:** Artık pek popüler olmayan hangi mobil işletim sistemleri vardır? **Cevap:** BlackBerry ve Windows Phone. BlackBerry hâlâ kendi telefonlarını üretiyor. Fiziksel klavyesi ve kendine özel e-posta sunucusu nedeniyle bazı kullanıcılar ve şirketler tercih ediyor, ama pazar payı çok düşük. Bugün iOS ve Android açık ara liderdir.

**Soru:** Ufukta yeni bir işletim sistemi var mı? Öğrenciler Huawei'nin işletim sistemini (sohbet penceresinde HarmonyOS diye yazıldı) ve Google'ın Fuchsia'sını söyledi. Hocaya göre Fuchsia da bir altyapı bağımlılığından kurtulma arayışıdır ve büyük olasılıkla önümüzdeki birkaç yıl içinde görülecektir. Samsung'un Tizen'i telefonlarda tutunamadı, ama akıllı cihazlarda ve televizyonlarda kullanılmaya devam ediyor. Mobil işletim sistemi fikriyle doğup IoT cihazlarına evrilmiş iyi bir örnektir. Bada, webOS ve Ubuntu'nun mobil sürümü de vardı, ama hiçbiri şu an yaygın değildir.

Hocanın beklentisi şudur: telefon tarafında Windows, Unix/Linux ve macOS'un masaüstündeki yerleşikliğine benzer bir durum oluştu. Belki bir rakip daha çıkar, ama bir sonraki işletim sistemi tartışması büyük olasılıkla telefonlardan çok IoT cihazları üzerine olacak.

### 10.2 Güncel mobil işletim sistemleri

Slayttaki "Up-to-date Mobile Operating Systems" listesi (ekrandan, 02:10:00):

- Android.
- EMUI (Emotion User Interface): Android Open Source Project tabanlı.
- HTC Sense.
- MIUI (Xiaomi).
- Nokia X Platform (Google servisleri çıkarılmış): AOSP tabanlı.
- LG UX.
- Oxygen OS.
- TouchWiz (Samsung).
- ZenUI (Asus).
- iOS.
- Windows 10 Mobile.
- BlackBerry 10: QNX OS tabanlı.
- Firefox OS (Java benzeri kodu yok).
- Tizen: Linux tabanlı.
- Ubuntu OS (Java benzeri kodu yok).

Pazar payı grafiğinde Android'in en üstte olduğu ve iOS'un belirli bir payı koruduğu görülür; bu tablo yıllar içinde fazla değişmez.

## 11. Android ve iOS Mimarisi

### 11.1 Android'in dört katmanı

Android mimarisi dört katmandan oluşur (ekrandan, 02:15:00):

- **Applications:** Home, Contacts, Phone, Browser gibi uygulamalar.
- **Application Framework:** Uygulama geliştirmeyi sağlayan çatı. Activity Manager, Window Manager, Content Providers, View System, Package Manager, Telephony Manager, Resource Manager, Location Manager, Notification Manager gibi yönetici ve sağlayıcılar burada bulunur; bunlar uygulama geliştirirken kullanılan paketlerdir.
- **Libraries ve Android Runtime:** Kütüphaneler (Surface Manager, Media Framework, SQLite, OpenGL ES, FreeType, WebKit, SGL, SSL, libc) işletim sistemine daha yakın, performans sağlamak için sunulmuş bir katmandır. Framework'teki birçok yapı bunları kullanır. Geliştirici de bu katmana müdahale edebilir: Native Development Kit (NDK) ile yerel geliştirme yapılarak performans oldukça artırılabilir ve oluşturulan yerel kütüphaneler Java üzerinden (JNI ile) çağrılır. Android Runtime kısmında Core Libraries ve slayttaki çizimde Dalvik Virtual Machine yer alır.
- **Linux Kernel:** Standart bir Linux çekirdeği kullanılır. Display, Camera, Flash Memory, Binder (IPC), Keypad, WiFi ve Audio sürücüleri ile Power Management bulunur. Geliştirici kendi sürücüsünü de yazabilir, ama bu sık karşılaşılan bir durum değildir.

> **Hocanın vurgusu:** Linux çekirdeğindeki en önemli kısımlardan biri güç yönetiminden (Power Management) sorumlu olan kısımdır.

### 11.2 Yenilik 1: Android App Bundle

**Soru:** Android'in yeni paket yapısı nedir? **Cevap (bir öğrenci):** APK yerine AAB, yani Android App Bundle. **Soru:** APK'dan farkı nedir? Bir öğrenci bağımlılıkları doğrudan içinde tutmayıp ortak kütüphane kullanıyor olabileceğini tahmin etti; hoca bunun fena bir fikir olmadığını ama tam karşılığı olmadığını söyledi.

Hocanın açıklaması: Android'deki büyük sorun, bütün cihaz biçimlerine ait dosyaların uygulama paketine konmasıydı. Farklı ekran boyutları için ikonlar, farklı diller için fontlar aynı pakete giriyordu. Bu da paketi şişiriyordu; kapsamlı bir uygulamada 60 MB, 100 MB'lık paketler oluşuyordu. Android şu kararı verdi: bütün seçenekler merkezde saklanır, uygulamayı indirmek isteyen cihazın özelliklerine bakılır ve yalnız o cihaz için gerekli parçalar gönderilir.

Hocanın örneğinde 60 MB yerine 10-20 MB'lık bir paket ulaşır. Getirisi üç maddedir:

- Gereksiz indirme trafiği oluşmaz.
- Cihaz belleğinde daha az yer kaplanır.
- Kurulum daha hızlı olur.

Android'in yalnız üst segment değil alt segment telefonları da hedeflediği düşünülürse, bu özellik donanım kısıtı olan ve eski sürüm çalıştıran cihazlar için çok daha önemlidir.

### 11.3 Yenilik 2: Android Runtime (ART)

Eskiden Android'de bir Java sanal makinesi, yani Dalvik Virtual Machine vardı; şimdi onun yerinde Android Runtime yapısı bulunur. **Soru:** Bu yeni yapı neyi iyileştirdi? Bir öğrenci, değişikliğin lisanslama sorunlarıyla ilgili olduğunu duyduğunu, teknik tarafı bilmediğini söyledi. Hoca bunun da bir neden olduğunu kabul etti.

Teknik açıklama şöyledir: Android'de bir uygulamayı çalıştırmak için önce derlemek, sonra oluşan çalıştırılabilir dosyaları çalıştırmak gerekir. Bu derleme iki aşamada yapılabilir: kurulum (installation) sırasında ya da çalıştırma sırasında. Çalıştırma sırasında yapılırsa yorumlayıcı (interpreter) devreye girdiği için performans düşer. ART'ta ise uygulama yüklenirken çalıştırılabilir kod da üretilir; böylece uygulama çalıştırıldığı anda performans yüksek olur. Tek dezavantajı, kurulum sırasında hem paket hem de üretilen kod için yaklaşık iki kat alan gerekmesi ve kurulumun yavaşlamasıdır. Kurulum yavaşlar, ama çalışma sırasında performans kazanılır.

> **Ek bilgi (derste anlatılmadı):** Dalvik çalışma anında derleme (JIT, just-in-time) kullanıyordu. ART ise kurulum anında önceden derleme (AOT, ahead-of-time) yaklaşımıyla geldi. Sonraki Android sürümlerinde büyük olasılıkla JIT ve AOT birlikte, profil tabanlı olarak kullanılmaktadır.

### 11.4 iOS mimarisi

iOS da dört katmanlıdır: Cocoa Touch, Media Layer, Core Services Layer ve Core OS Layer. Kullanıcıya yakın katman ve medya servisleri üstte, temel servisler altta yer alır. Apple, geliştiricinin alt seviyelere inmesine pek izin vermez; erişimi daha üst seviyede keser, ama üst seviyeyi daha fazla katmana ayırmıştır. Android ise geliştiriciye her zaman daha fazla esneklik verir. Hoca, Windows Phone artık kritik olmadığı için onun mimarisi üzerinde durmadı.

## 12. Mobil İşletim Sistemi ile PC İşletim Sistemi Arasındaki Farklar

Slayttaki beş fark (ekrandan, 02:20:00) hocanın anlatımıyla birlikte şöyledir.

### 12.1 Güç (Power) ve wake-lock

Slayt: Android'de işlemci ve ekran varsayılan olarak kapanır. Bir süreç işlemciyi ya da ekranı çalışır tutmak istiyorsa bunları "wake-lock" ile açıkça kilitlemelidir.

**Soru:** Wake-lock nedir? Bir öğrenci, kaynağı kullanırken başkalarının kullanmasını engelleyen bir mekanizma olup olmadığını sordu. Hoca açıkladı: telefon uyku moduna geçtiğinde ya da kilitlendiğinde belirli bir süre sonra arka planda çalışan uygulamalar da durdurulur. Bu yapı hâlâ vardır. Eski Android sürümlerinde bu programcının kontrolündeydi ve programcı tarafından açılması gerekiyordu. Yeni sürümlerde kullanıcı da bir uygulamanın arka planda çalışıp çalışamayacağını seçebilir.

Hoca bunu bir örnekle anlattı: eski Android sürümlerinde arka planda çalışması gereken bir uygulama, belirli bir süre sonra kapanıyordu. Sorunun nedeni wake-lock mekanizmasıydı: programcı wake-lock almazsa uygulama ne kadar arka planda çalışacak biçimde yazılırsa yazılsın çalışmaya devam etmiyordu.

> **Hocanın vurgusu:** İşletim sistemlerinin yeteneklerini çok iyi analiz etmek gerekir. Bunları iyi kullanınca pil tüketimi azaldığı için kullanıcı deneyimi de artar. Kullanıcı bir uygulamada ilk olarak ne kadar pil tükettiğine bakar. Bugün bir mobil işletim sistemi geliştirilecek olsa ilk öncelik güç ve enerji yönetimidir.

### 12.2 Arayüz (Interface)

Slayt: Dokunmatik ekran ana girdi yöntemidir; tuş takımı, ses vb. tarafından desteklenir. Geleneksel pencere yöntemi ağır olduğu için katmanlar ve görünümler (layers and views) kullanılır.

Hoca, telefonla etkileşimde sesli komutların ve dikte etmenin çok daha aktif kullanıldığını ekledi. Bilgisayara pek bir şey dikte ettirilmez, ama telefonda mesajlar sesle yazdırılabilir. Bu yüzden konuşmadan metne (speech-to-text) ve metinden konuşmaya (text-to-speech) telefonlarda çok sık kullanılır.

### 12.3 Bellek (Memory)

Slayt: Android daha az bellek kullanacak biçimde optimize edilmiştir; uygulamalar en az RAM'e yüklenecek şekilde yapılandırılır. Linux çekirdeğinde zaten "out of memory" desteği vardır, Android bunun üstüne kullanılmayan uygulamaları sonlandırmak için "Low Memory Killer" ekler. Framework'te kullanılan bütün kütüphaneler optimize edilmiştir; örneğin C kütüphanesi olarak glibc yerine bionic kullanılır.

Hocanın anlatımıyla Low Memory Killer, aktivitenin bulunduğu duruma (state) bağlı olarak kullanıcıdan onay almadan aktiviteyi yok etme hakkına sahiptir. Bu yüzden aktivitenin hangi durumda bırakıldığı önemlidir. Özellikle belleği düşük telefonlarda Android, kapatılmamış eski uygulamaların aktivitelerini kendiliğinden bellekten temizler.

**Soru:** PC'de bellek yetersiz kalınca ne yapılır? **Cevap:** Sanal bellek, yani sayfalama (paging). Veri ikincil belleğe taşınır, yalnız kullanılan kısım ana bellekte kalır, gerektiğinde ikincil bellekten geri alınır.

Bir öğrenci, bazı özel Android sürümlerinde (LineageOS gibi) RAM'e ek olarak swap alanı tanımlanabildiğini hatırlattı. Hoca bu özelliğin telefonlara da konduğunu kabul etti. Ancak telefonda bellekten ikincil belleğe gidip gelmenin maliyeti PC'dekinden yüksektir: PC'deki veri yolu hızıyla karşılaştırıldığında flash belleğe erişim daha yavaştır, harici bir depolama kullanılıyorsa daha da yavaştır. Bu yüzden mobil cihazlarda uygulamaların bellekten temizlenmesi yönüyle bellek yönetimi çok kritiktir.

### 12.4 İletişim işlemcisi (Communication processor)

Slayt: Android, iletişim işlemcisi üzerinde çalışan başka bir özel işletim sistemiyle haberleşir. GPRS/EDGE/3G/LTE desteklenir; bunlar masaüstü sistemlerde gerekmez. Hoca, işletim sisteminin bu protokoller arasında geçiş yapabilmesinin çok önemli olduğunu ekledi.

### 12.5 Taşınabilirlik (Portability)

Slayt: x86 masaüstü için yapılmıştır; mobil işletim sistemleri başlıca gömülü sistemler için yapılmış ARM üzerinde çalışır. İşletim sistemlerinin çoğu bütün donanım mimarilerine taşınmış olsa da bu mimariler için optimize değildir. Hoca, mobil işletim sistemlerinin ilk etapta daha çok ARM üzerinde çalıştığını, son dönemde başka mimarileri de destekleyecek biçimde evrildiğini söyledi.

## 13. Mobil İşletim Sistemi Tasarım Ölçütleri ve Güvenlik

### 13.1 Tasarım ölçütleri

Slaytta "Mobile OS Design Criteria" başlığı boş bırakılmıştı (ekrandan, 02:30:00); ölçütler sınıfta tartışılarak çıkarıldı.

**Soru:** Bir mobil işletim sistemi tasarlayacak olsanız ölçütleriniz ne olur?

- Belleğin etkin kullanımı, performansı artırmaya yönelik tasarım ve enerji tasarrufuna yönelik tasarım (bir öğrenci).
- Kullanıcı deneyimi (bir öğrenci): makine ne kadar güçlü ve verimli olursa olsun son kullanıcıya hitap etmiyorsa değeri olmaz. Örnek olarak Linux'un uzun süre kullanıcı deneyimi ve arayüz eksikliği yüzünden yaygınlaşamadığı verildi.
- Güvenlik (bir öğrenci): telefonda pek çok kişisel veri taşınır.

Hoca güvenliğin çok önemli olduğunu onayladı. iOS ile Android karşılaştırıldığında, iOS'un güvenlik konusunda birçok karşılaştırma testinde ve kullanıcı algısında açık ara önde olduğu söylenebilir.

**Soru:** Bunu ne belirliyor? **Cevap (bir öğrenci):** Apple'da donanım ve yazılım üreticisi aynı firma olduğu için aradaki bağlantı çok güçlüdür. Hoca şöyle açıkladı: bir tarafta hem donanımı hem yazılımı üreten ve donanım çeşitliliği kısıtlı bir firma, diğer tarafta dünyada en az 10, belki 20-30 markaya işletim sistemi sağlayan bir yapı vardır. İkincisinin güvenliğini sağlamak çok zordur, çünkü her donanımı verimli yönetecek kodun işletim sistemine gömülmesi sistemin yavaşlaması anlamına gelir.

### 13.2 Mobil zararlı yazılımlar

**Soru:** Telefonlarda virüs ya da zararlı yazılımla (malware) karşılaşıyor muyuz? Öğrencilerden gelen örnekler:

- Google'ın birkaç yıl önce mağazasından çok sayıda uygulamayı kaldırdığı bir temizlik. Söylendiğine göre bazı uygulamalar, uygulamaya özgü veri dizinlerinde şifrelenmeden tutulan önbellek dosyalarından parola bilgilerini çalabiliyordu.
- Bir tablete bulaşan ve sürekli reklam gösteren, silinemeyen, rootkit gibi yetkili biçimde yerleşen reklam yazılımı (adware).
- Dışarıdan normal görünen ama ekranın üzerinde görünmez bir katman (overlay) oluşturup basılan tuşların yerini kaydeden zararlı yazılımlar. Bunlar şifreleri çalabilir; kaydedilen konumlar klavye düzenine göre yanlış da olabilir.

### 13.3 Zararlı yazılım tespiti

**Soru:** Mağazalar bir yazılımın zararlı olup olmadığını bilimsel olarak nasıl anlıyor olabilir? Öğrencilerden gelen cevaplar:

- Anormal davranış tespiti.
- Statik kod analizi: kodu decompile ederek incelemek.
- Bir öğrenci, otomatik araçlarla yalnız statik analiz yapıldığında zararlı içeriğin birkaç kez kodlanarak ya da şifrelenerek kolayca gizlenebildiğini söyledi. iOS'ta gönderilen uygulamalar ayrıntılı olarak, insanlar tarafından da incelenir. Android'de uygulama sayısı çok fazla olduğu için otomatik araçlar kullanılır ve bazı şeyler gözden kaçabilir. Hoca iOS'un değerlendirme sürecinin daha uzun olduğunu ekledi.

**Soru:** Zararlı yazılım taramadan kaçmak için kendini saklayabilir mi? **Cevap (bir öğrenci):** Yetki yükseltme bulduğunda kendini önyükleme dosyalarına yazabilir ya da sistemle birlikte gelen gömülü bir uygulama gibi gösterebilir. Bu durumda cihaz sıfırlansa bile yeniden ortaya çıkar.

Hoca tespit yöntemlerinden birini açıkladı: zararlı olduğundan şüphelenilen uygulama, telefona zarar vermeden sandbox ortamında çalıştırılıp test edilir.

### 13.4 Akıllı zararlı yazılımlar ve gerçek kullanıcıyı taklit eden sandbox'lar

Zararlı yazılımlar da akıllandı. Gerçek bir telefonda çalışıp çalışmadıklarını anlamaya çalışırlar; gerçek bir telefonda değillerse zararlı davranışı sergilemezler.

**Soru:** Bir zararlı yazılım gerçek bir telefonda çalışıp çalışmadığını anlamak için neye bakıyor olabilir?

- Çekirdek frekansı gibi sanal makinenin veremeyeceği bilgiler (bir öğrenci). Hoca, sandbox'ın bu bilgileri de otomatik olarak sağladığını varsayınca ne olacağını sordu.
- Sistem dosyalarına bakmak ya da makineyi zorlayıp tepkisini ölçmek (bir öğrenci): bir şeyler çalıştırdıktan sonra sıcaklık artışı, ona bağlı frekans düşüşü ve RAM performansındaki azalma gibi koşulları değerlendiren zararlı yazılımlar vardır.

Hoca bunu doğruladı: zararlı yazılım telefonun kaynaklarının davranışını inceler ve beklenen davranışı görmezse bir sandbox içinde olduğunu anlar. Bu karakteristik de taklit edilirse bir sonraki adımda zararlı yazılım telefonun gerçekten bir kullanıcı tarafından kullanılıp kullanılmadığını incelemeye başlar. Gerçek bir telefon belirli aralıklarla taşınır, ona arama ve mesaj gelir, GPS koordinatı değişir, jiroskop ve ivmeölçerden veri gelir. Buna karşı, gerçek hayatta kullanılan bir telefonun davranışını modellemeye çalışan sandbox'lar da geliştirilmektedir. Hoca, yalnız sistemi değil kullanıcıyı da taklit etmeyi güncel ve popüler bir araştırma konusu olarak gösterdi.

> **Ek bilgi (derste anlatılmadı):** Sandbox ya da emülatör ortamını sezip davranışını değiştiren zararlı yazılım tekniklerine literatürde genel olarak "evasion" ya da "anti-emulation" teknikleri denir. Sensör verisinin kullanıcı benzeri biçimde üretilmesi, bu dersin konusu olan mobil sensör verisinin güvenlik alanındaki bir uygulamasıdır.

## Örnek Sorular

**1.** (derste sözlü, 00:04:29) Derleme (survey) makalesi ile araştırma makalesi arasındaki fark nedir?

> **Cevap (derste verildi):** Araştırma makalesi yeni bir yöntem, deney ya da sonuç sunar. Derleme makalesi ise alandaki mevcut çalışmaları tarar, gruplar, karşılaştırır, yorumlar ve açık problemleri ortaya koyar. Yeni bir test sonucu sunmasa da özgün bir bakış açısı içermelidir.

**2.** (derste sözlü, 00:39:35) Trafik akış hızı tahmini bir sınıflandırma problemi midir, regresyon problemi mi? Gözetimli midir?

> **Cevap (derste verildi):** Geçmişte etiketlenmiş veriden öğrenildiği için gözetimlidir. Sürekli bir değer (hız) tahmin edildiği için regresyon problemidir. Bölgenin renk sınıfı (kırmızı, sarı, yeşil) tahmin edilseydi sınıflandırmaya indirgenebilirdi.

**3.** (derste sözlü, 00:41:28) Regresyon problemlerinde hangi başarım ölçütleri kullanılır? Gerçek hız 30 km/sa iken 36 km/sa tahmin edilirse mutlak ve yüzdesel hata nedir? Gerçek hız 60 km/sa iken sapma yine 6 km/sa ise?

> **Cevap (derste verildi):** Karesel hata (kökü alınarak ya da alınmadan), MAE ve MAPE. Birinci durumda mutlak hata $|36-30|=6$ km/sa, yüzdesel hata $6/30=\%20$'dir. İkinci durumda mutlak hata yine 6 km/sa, yüzdesel hata $6/60=\%10$'dur. Düşük ve yüksek hızlardaki sapmanın etkisi farklı olduğundan ölçüt seçimi tartışılmalıdır.

**4.** (derste sözlü, 00:46:39) Binlerce sensör lokasyonu içinden trafik hızını tahmin etmesi en zor olanları kısa sürede nasıl belirlersiniz?

> **Cevap (derste verildi):** Her lokasyondaki hızların standart sapması hesaplanır ve lokasyonlar buna göre sıralanır. Standart sapması yüksek, yani karakteristik davranmayan lokasyonlar en zor adaylardır. Bu yöntem düzenli günlük değişimi olan yerleri de yüksek gösterebilir, ama iyi bir ilk adımdır. Ana arterler ve en çok talep edilen noktalar da öncelik ölçütü olarak önerildi.

**5.** (derste sözlü, 01:29:24) İşletim sistemlerini hangi kategorilere ayırabilirsiniz?

> **Cevap (derste verildi):** Masaüstü, mobil, sunucu (çok kullanıcıyı ve kaynak paylaşımını yöneten), gömülü (TinyOS, Contiki gibi sensör ağı işletim sistemleri) ve gerçek zamanlı işletim sistemleri.

**6.** (derste sözlü, 01:37:55) Bir akıllı telefonda en çok enerjiyi hangi bileşenler tüketir? Ekranın enerji tüketimini azaltmak için neler yapılabilir?

> **Cevap (derste verildi):** En çok hücresel haberleşme ve ekran; ardından GPS, Bluetooth ve kamera. Ekran için donanımsal çözüm OLED (piksellerin tek tek yanması, arka ışık gerekmemesi), yazılımsal çözüm koyu temadır. E-mürekkep ekranlar da çok az enerji tüketir.

**7.** (derste sözlü, 02:12:33) Android App Bundle (AAB), APK'ya göre ne avantaj sağlar?

> **Cevap (derste verildi):** Bütün cihaz seçenekleri (ikon boyutları, dil ve font dosyaları vb.) merkezde tutulur; indiren cihaza yalnız ona uygun parçalar gönderilir. Böylece paket küçülür (hocanın örneğinde 60 MB yerine 10-20 MB), gereksiz indirme trafiği oluşmaz, depoda daha az yer kaplanır ve kurulum hızlanır.

**8.** (derste sözlü, 02:16:27) Dalvik sanal makinesinin yerine gelen Android Runtime (ART) neyi iyileştirir? Bedeli nedir?

> **Cevap (derste verildi):** Kod çalışma anında yorumlanmak yerine kurulum sırasında derlenip çalıştırılabilir kod üretilir; böylece çalışma anında performans artar. Bedeli, kurulumun yavaşlaması ve derleme sırasında yaklaşık iki kat alan gerekmesidir.

**9.** (ekrandan, 02:20:00) Mobil işletim sistemlerini PC işletim sistemlerinden ayıran beş temel fark nedir?

> **Cevap (slayttan):** (1) Güç: işlemci ve ekran varsayılan olarak kapanır, çalışır tutmak için wake-lock gerekir. (2) Arayüz: dokunmatik ekran ana girdidir; tuş takımı ve sesle desteklenir, pencereler yerine katmanlar ve görünümler kullanılır. (3) Bellek: az bellek için optimize edilmiştir; Low Memory Killer kullanılmayan uygulamaları sonlandırır, glibc yerine bionic kullanılır. (4) İletişim işlemcisi: GPRS/EDGE/3G/LTE, ayrı bir işlemcide çalışan özel bir işletim sistemiyle yürütülür. (5) Taşınabilirlik: mobil işletim sistemleri başlıca ARM üzerinde çalışır; başka mimarilere taşınsalar da onlar için optimize değildir.

**10.** (derste sözlü, 02:24:11) PC'de bellek yetmediğinde kullanılan çözüm nedir ve mobil cihazlarda neden aynı ölçüde tercih edilmez?

> **Cevap (derste verildi):** PC'de sanal bellek ve sayfalama ile veri ikincil belleğe taşınır ve gerektiğinde geri alınır. Mobilde flash belleğe (hele harici depolamaya) gidip gelmenin maliyeti daha yüksektir. Bu yüzden Android, Low Memory Killer ile kullanılmayan uygulamaları bellekten temizlemeye ağırlık verir.

**11.** (derste sözlü, 02:35:42) Akıllı bir zararlı yazılım, sandbox içinde mi yoksa gerçek bir telefonda mı çalıştığını nasıl anlamaya çalışır? Buna karşı ne yapılır?

> **Cevap (derste verildi):** Önce sanal ortamın veremeyeceği donanım bilgilerine ve kaynak davranışına bakar (yük altında sıcaklık artışı, frekans düşüşü, RAM performansı). Bu da taklit edilirse telefonun gerçekten kullanılıp kullanılmadığını inceler: taşınma, gelen arama ve mesajlar, GPS değişimi, ivmeölçer ve jiroskop verisi. Buna karşı gerçek kullanıcı davranışını modelleyen sandbox'lar geliştirilmektedir.

## Dersin Toparlaması

Dersin ilk yarısı, bir derleme makalesinin nasıl kurulacağını trafik akış tahmini örneği üzerinden gösterdi. Bir derleme yalnız çalışmaları toplamaz; onları anlamlı bir biçimde gruplar ve açık problemleri ortaya koyar. Trafik tahmininde tahmin ufku (kısa, orta, uzun vade), yöntem aileleri, girdi parametreleri ve veri kaynakları, regresyon ölçütleri ve bunların karşılaştırılabilirliği, lokasyon başına ya da kümelenmiş modelleme ve rotalama ile birleşme farklı bakış açıları olarak çıktı.

İkinci yarıda mobil dünyaya geçildi. Mobil hesaplama iletişim, donanım ve yazılım bileşenleriyle tanımlandı. Mobil işletim sistemlerinin masaüstü sistemlerden temel farkının kısıtlı kaynakların, özellikle enerjinin yönetimi olduğu görüldü: wake-lock, Low Memory Killer, ayrı iletişim işlemcisi, ARM üzerinde çalışma, koyu tema ve OLED gibi çözümler bunun örnekleridir. Android ve iOS mimarileri, Android'in AAB ve ART yenilikleri ve mobil güvenlikte sandbox ile zararlı yazılım arasındaki yarış ele alındı. Hoca bir sonraki derste aynı konuya devam edileceğini ve sensörlere geçileceğini söyledi: çevresel zekada hangi sensörlerin kullanılacağı, ne tür değerler ürettikleri ve bu değerlerin ne kadar doğru olduğu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
