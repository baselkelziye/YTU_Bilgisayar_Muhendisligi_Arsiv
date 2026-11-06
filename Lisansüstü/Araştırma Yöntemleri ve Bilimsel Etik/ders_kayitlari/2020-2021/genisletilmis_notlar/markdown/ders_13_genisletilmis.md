# Ders 13 Genişletilmiş Notu: Proje Önerisi Sunumları IV ve Final Duyurusu: Tarım, Galeri, Banka Dokümanları ve Sahte Haber

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- Dersin Yapısı
- 1. Sokak Hayvanları için Otomatik Besleme İstasyonu
- 2. Domates Hastalıklarını Tespit Eden Mobil Uygulama
- 3. GAN ile Otomatik Arayüz Testi Kodu Üretimi
- 4. Bulut Tabanlı Akıllı Galeri Uygulaması
- 5. Banka Dokümanlarında Çok Görevli Öğrenme
- 6. Topraksız Dikey Tarımda Makine Öğrenmesi
- 7. DOHTES: Sentetik Hiperspektral Görüntülerle Domates Hastalığı Tespiti
- 8. Türkçe Sahte Haber Tespiti
- Dersin Toparlaması

## Dersin Yapısı

Bu derste konu anlatımı yoktur. Dersin tamamı grupların araştırma projesi önerisi sunumlarına ayrılmıştır. Sekiz grup sırayla sunum yapar. Bölüm numaraları sunum sırasıyla aynıdır.

Hoca oturumu yönetir: grupları çağırır, sözü verir, her sunumun sonunda soru olup olmadığını sorar. Altyazıda hocanın sunumların içeriğine dair bir geri bildirimi yoktur. Bu yüzden notta "Hocanın vurgusu" bloğu bulunmaz. Aşağıdaki anlatım grupların kendi sunduğu içeriktir. Sayılar ve iddialar grupların sunumlarından aktarılmıştır, doğrulanmış bilgi olarak okunmamalıdır. Hatalı görünen yerler "Ders sonrası not" bloklarıyla işaretlenmiştir.

İki sunumda proje formatı açıkça TÜBİTAK 1002 Hızlı Destek Programı olarak anılır. Diğer sunumlar da benzer başlıkları izler: konu ve önem, amaç, yöntem, iş paketleri, riskler, etki, bütçe.

## 1. Sokak Hayvanları için Otomatik Besleme İstasyonu

### 1.1 Konu ve Problem

İlk grup, sokak hayvanları için otomatik besleme istasyonu önerir. Sunum, Türkiye'de sokak hayvanı sayısının yüksek olduğunu, ancak bunun hayvanların kültürümüzde değersiz olduğu anlamına gelmediğini söyleyerek başlar. Tarihsel bir örnek verilir: Osmanlı döneminde halkın görevlendirdiği kişiler sokak hayvanlarını besliyordu. Halk bu kişilerden mama alıp hayvanlara veriyor ya da onlara para verip hayvanları beslemelerini sağlıyordu.

<!-- BELİRSİZ: Bu kişilere verilen tarihsel meslek adı altyazıda "Mancacı" diye geçiyor; doğru yazımı anlaşılmıyor. -->

Grup bugünkü sorunları şöyle sıralar:

- **Yaşam alanının daralması:** Temel neden şehirleşme ve betonlaşmadır. Çevre kirliliği de hayvanların yaşama olasılığını düşürür.
- **Pandemi:** 20 günlük karantina gibi dönemlerde besleme aksar ya da unutulur.
- **Yanlış besleme:** Bireysel beslemede hayvana zararlı yiyecekler verilebilir. Sunumdaki örnek, köpekler için zararlı olan tavuk kemiğidir. Bu, sağlık sorunlarına hatta ölüme yol açar.
- **Agresifleşme:** Aç kalan hayvanlar agresifleşir. İnsanlar da koruma içgüdüsüyle aynı tepkiyi verir. Sonuçta çevresel ve toplumsal huzur bozulur.
- **Hijyen:** Parkta ya da bahçede bırakılan mama ve yemek artıkları çürür. Koku ve hijyen sorunu doğar.

Sunumda 2013 tarihli bir çalışmadan da alıntı yapılır. Alıntının özü şudur: Hayvanlar kentlerde insandan çok önce yaşıyordu. "Sokak hayvanı" adı kent yaşamından sonra ortaya çıktı. Kentlere bilinçsizce yerleşip doğayı tahrip eden insanın bu hayvanları dışlaması kabul edilemez.

### 1.2 Araştırma Sorusu ve Amaç

Araştırma sorusu şudur: İstanbul'daki sokak hayvanlarını daha verimli ve sağlıklı beslemek mümkün mü? Grup, kuracağı istasyonlarla hayvanların daha iyi koşullarda yaşayabileceğini düşünür. İstasyonların ekonomik, çevresel ve toplumsal faydası olduğunu da savunur.

Grup, başarı için otomatları yerleştirmenin yetmediğini vurgular. Hedefler şunlardır:

- Sürdürülebilirlik için toplumsal bir hayvan koruma bilinci oluşturmak.
- Ekonomik ve toplumsal faydayı net biçimde ortaya koymak. Bu hem projeye net bakmayı sağlar hem de halkın projeyi benimseme oranını artırır.
- Bir prototip yapıp şehrin küçük bir bölümünde test etmek, sonra tüm şehre yaymak.

### 1.3 Mevcut Durum ve Önerilen Sistem

Grup önce bugünkü uygulamayı anlatır. Belediyenin belli noktalara gidip mama bıraktığı projeler vardır. Grup bunu yeterince etkili bulmaz.

Önerilen istasyon üç tür hayvanı besler: kedi, köpek ve kuş. Kedi ve köpeklerin besleme alanı yerdedir. Kuşların alanı 3 metrelik bir direğin üstündedir. Tepede kuşlara yuva olabilecek kutular da bulunur.

Sistemin işleyişi şöyledir:

- Kameralar ve yapay zeka algoritmaları gelen hayvanın türünü ve boyutunu belirler. Hayvana uygun tipte mama verilir.
- Sensörler mama kaplarını ve depoları sürekli izler. Stok azalınca ilgili ekiplere bilgi gider. Ekipler hangi istasyonda mama azaldıysa oraya kısa sürede gidip doldurur. Grup bu işi belediyenin yapabileceğini düşünür, ama başka bir toplumsal projenin de üstlenebileceğini ekler.
- Halk da katkı sağlayabilir. Mobil uygulamadan ya da istasyondaki kredi kartı noktasından bağış yapılabilir.

### 1.4 Donanım Bileşenleri

- **Kamera:** Hayvanı tanımlar.
- **Mesafe sensörü:** Mama deposunun doluluk oranını ölçer.
- **Ödeme sistemi:** Bağış içindir.
- **Raspberry Pi:** İşlem gücünü sağlar.
- **3G/4G/LTE modülü:** İnternet erişimini sağlar.
- **Servo motor:** Hayvan gelince kapağı açar, mama bırakıldıktan sonra kapatır. Sunuma göre yaklaşık 15 kg'a kadar ağırlığı destekler.
- **Motor sürücü:** Motoru kontrol eder.
- **Güç kaynağı:** Bütün sistemi besler.

Birden fazla bileşen olduğu için bunlar tek bir kart üzerinde birleştirilip dış dünyaya bağlanacaktır. Son olarak prototip çizimi gösterilir: altta kameralar ve mamanın kaba döküldüğü açıklık, yan tarafta ödeme noktaları, yukarıda kuşlar için kamera sensörü ve yuva kutuları vardır.

<!-- BELİRSİZ: Bileşenlerin birleştirildiği kart altyazıda "sivik" diye geçiyor; prototip çiziminin ayrıntıları yalnız sözlü anlatılıyor. -->

Bu sunumdan sonra soru gelmez. Grup beklenen etkiyi ekonomik, çevresel ve toplumsal diye sayar, ancak altyazıda bunlar için ölçü ya da sayı verilmez.

## 2. Domates Hastalıklarını Tespit Eden Mobil Uygulama

### 2.1 Konu ve Önem

İkinci grup, Antalya bölgesinde hastalıklara bağlı domates üretim kayıplarını azaltmayı amaçlayan bir mobil uygulama önerir. Gerekçe sayılarla kurulur.

Dünya ölçeğinde sunulan veriler FAO'nun (Food and Agriculture Organization of the United Nations) 2018 verileridir:

- Domates üretimi 182 milyon tondur. Bu, dünya yaş sebze üretiminin %16'sıdır.
- Türkiye'de üretim 13 milyon tona yakındır. Bu, Türkiye'nin sebze üretiminin yaklaşık %41'idir.
- Türkiye'de domatesin yaklaşık %25-30'u sanayide kullanılır, kalanı sofralık tüketilir. Salça, ketçap, domates suyu ve konserve bu sanayinin ürünleridir.

Türkiye için 1 Temmuz 2019-30 Haziran 2020 dönemine ait veriler de verilir:

| Kalem | Değer |
|---|---|
| Üretim | yaklaşık 12,85 milyon ton (dünyada 4. sıra) |
| Üretim kaybı | 450 bin ton |
| Tüketim | yaklaşık 9,5 milyon ton |
| Kişi başı yıllık tüketim | altyazıda yaklaşık 14,5 kg |
| İhracat | 1,2 milyon ton (dünyada 5. sıra) |

> **Ders sonrası not:** Tablodaki kişi başı tüketim toplam tüketimle uyuşmuyor. Nüfus yaklaşık 83 milyon alınırsa $9{,}5 \times 10^{9} \text{ kg} / 83 \times 10^{6} \approx 114{,}5$ kg eder. Sunumda söylenen değer büyük olasılıkla 114,5 kg'dır ve altyazıda "14,5" diye kısalmıştır. Ayrıca kalemler üretimi tam kapatmaz: $12{,}85 - 0{,}45 - 9{,}5 - 1{,}2 = 1{,}7$ milyon ton açıkta kalır. Bu sunumda açıklanmıyor. Sunumda "dünyada ortalama 109 ila 120 kilo" denen yıllık tüketim de dünya ortalaması için büyük olasılıkla çok yüksektir; altyazı bu noktada bozuk olabilir.

Pilot bölge Antalya'dır. Hesap şöyledir: Verilen, Antalya üretiminin yaklaşık 2,53 milyon ton ve Türkiye üretiminin yaklaşık 12,85 milyon ton olmasıdır.

$$\frac{2{,}53}{12{,}85} \approx 0{,}197 = \%19{,}7$$

Bu değer sunumdaki %19,7 ile tutarlıdır. Grup seçimi iki gerekçeye dayandırır: ürüne ulaşmak kolaydır ve kullanıcıya ulaşmak kolaydır. Uygulama mobil olduğu için ileride ülkenin geri kalanına yayılması beklenir.

<!-- BELİRSİZ: 00:22:17'de "Türkiye'de üretilen domatesin %32'ye yakını ..." cümlesindeki bölge adı altyazıda maskeyle kapanmış; hangi bölge olduğu okunamıyor. -->

### 2.2 Hastalıklar

Sunuma göre dünyada tarımsal üretim kayıplarının %14,7'si yabancı otlardan, %11,2'si zararlılardan, %9,1'i hastalıklardan kaynaklanır. Toplam %35 eder. Grup bu hesaplara göre Türkiye'de her yıl yaklaşık 40 bin ton domatesin hastalık yüzünden kullanılamaz hale geldiğini söyler.

> **Ders sonrası not:** 40 bin ton değeri büyük olasılıkla %9,1'in 450 bin tonluk kayba uygulanmasından çıkmıştır ($450 \times 0{,}091 \approx 41$ bin ton). Oysa yüzdeler kaybın payı değil, üretimin payı gibi verilmiştir. Üretime uygulanırsa $12{,}85 \times 0{,}091 \approx 1{,}17$ milyon ton çıkar. Projenin gerekçesini oluşturan bu sayının dayanağı raporda açıkça gösterilmelidir.

Domates hastalıkları literatürde üç başlıkta incelenir: fungal, bakteriyel ve virüs hastalıkları. Belirtiler yaprakta, gövdede ve meyvede renk değişikliği ile şekil bozukluğu olarak görülür. Slaytlarda örnek görseller vardır. Biri yaprak ve meyvede kararmayla görülen, en yaygın hastalıklardan biri olarak sunulan bir hastalıktır. Diğerleri bakteriyel kanser, bakteriyel benek, solgunluk virüsü ve mozaik virüsüdür.

> **Ders sonrası not:** Sunumda kararma yapan hastalığın adı altyazıda "mitiliyosu" diye geçiyor ve bakteriyel denildi. Bu büyük olasılıkla mildiyödür; doğrusu mildiyönün bakteri değil, *Phytophthora infestans* adlı oomiset kaynaklı olmasıdır. Görsel konumları anlatılırken de virüsler için önce "sol üst ve sağ alt" denildi, sonra mozaik virüsü "sağ üst" olarak söylendi; bu büyük olasılıkla sağ alttır.

### 2.3 Amaç

Temel amaç, domates hastalığına en hızlı ve en yüksek başarı oranıyla tanı koymaktır. Literatürdeki kültürel ve kimyasal mücadele yöntemleri de kullanıcıya sunulacak, böylece hastalıkla doğru biçimde mücadele edilecektir. Nihai hedef üretim verimini artırıp Türkiye'deki domates ekonomisine katkı sağlamaktır.

### 2.4 Yöntem ve İş Paketleri

Yöntem üç iş paketi üzerinden anlatılır.

- **Veri ihtiyacının karşılanması (ilk 4 ay, başarıya katkı %50):** Açık kaynaklı veri setleri, özellikle PlantVillage kullanılacak. Ayrıca Antalya'da üreticilerle saha çalışması yapılıp birinci elden veri toplanacak. Hazır veri ile toplanan veri arasındaki farklar ve benzerlikler ön analizle incelenecek. Grup bu aşamayı en kritik aşama sayar, çünkü makine öğrenmesi ve derin öğrenmede en önemli adımın verinin toplanması ve kullanılabilir hale getirilmesi olduğunu düşünür.
- **Uygulamanın geliştirilmesi (5 ay, başarıya katkı yaklaşık %35):** React Native ile hem iOS hem Android uyumlu bir uygulama yazılacak. Ön yüz, arka yüz, web servisleri, veri tabanı bağlantıları ve makine öğrenmesi modelinin uygulamaya yüklenmesi bu pakete girer. İş yükü fazla olduğu için süre daha uzundur.
- **Son kullanıcı testleri ve yayın:** Uygulama markete çıkmadan önce üreticilerle, çiftçilerle demo sürümüyle pilot çalışma yapılacak. Amaç hem adaptasyonu hızlandırmak hem de geri bildirimle özellikle ön yüzde değişiklik yapmaktır.

Üçüncü paketin başarıya katkı oranı altyazıda söylenmez. İlk iki oran $\%50 + \%35 = \%85$ ettiğine göre kalan %15'tir (ara adım eklendi).

<!-- BELİRSİZ: Üçüncü iş paketinin süresi altyazıda geçmiyor; slaytta olabilir. -->

### 2.5 Model Süreci

Grup en önemli noktanın doğru modeli seçmek ve doğru tahmin yapmak olduğunu söyler. Süreç beş aşamadır:

1. **Görsel toplama:** Açık veri setleri ve saha çalışması.
2. **Görsel işleme:** Görseller daha küçük piksellere ayrılarak hesaplama hızlandırılır. Görsellerdeki bulanıklıklara karşı Gaussian blur uygulanır.
3. **Segmentasyon:** Bitki yaprağını arka plandan ayırmak için iki merkezli K-ortalama (K-means) kümeleme kullanılır. Böylece bitki yüzeyi esas alınır.
4. **Sınıflandırıcı seçimi:** Literatür araştırmasına göre görsel verilerde en verimli model evrişimsel sinir ağıdır (Convolutional Neural Network, CNN).
5. **Tahminlemeyi sonuçlandırma:** Hiperparametre araştırmaları yapılır, sonuçlar kıyaslanır, en iyi model seçilir.

> **Ders sonrası not:** Sunumda Gaussian blur'un bulanıklığa karşı kullanılacağı söylendi. Doğrusu büyük olasılıkla şudur: Gaussian blur görüntüyü yumuşatır ve gürültüyü azaltır, bulanıklığı gidermez, tersine artırır. Bulanıklık gidermek için keskinleştirme ya da ters evrişim (deconvolution) kullanılır.

### 2.6 Riskler

Riskler gerçekleşme olasılığına göre üç kategoride incelenir.

- **Düşük olasılık:** Yeterli sayıda hastalıklı ve sağlıklı yaprak verisi toplanamaması. Saha çalışması bu riski baştan azaltır.
- **Orta olasılık:** Testlerde hedeflenen başarının tutturulamaması. Hiperparametre yöntemleriyle farklı parametreler denenecek, gerekirse başka bir derin öğrenme yöntemine geçilecek.
- **Yüksek olasılık:** Son kullanıcının uygulamayı kullanmakta zorlanması. Hedef kitle çiftçi ve üreticilerdir. Geleneksel alışkanlıktan mobil uygulamayla erken teşhise geçmek onlar için büyük bir dönüşümdür. Üçüncü iş paketindeki pilot çalışma ve yakın çalışma bu riskin etkisini azaltır.

### 2.7 Çıktılar ve Beklenen Etki

Çıktı, yaygın mobil işletim sistemlerinde çalışan ve makine öğrenmesiyle tahmin yapan bir uygulamadır. Etkiler şöyle sıralanır:

- **Toplumsal ve çevresel:** Doğru teşhisle yanlış ilaçlama önlenir, toprak sağlığı ve kalitesi korunur.
- **Akademik:** Türkiye'de bu alanda çalışma azdır, örneğin kayısı üzerine yapılmış bir çalışma vardır. Domates çalışması bu araştırmaların artmasına katkı sağlayabilir.
- **Ekonomik:** Erken teşhis kaybı azaltır, ürün miktarı artar. Bu ya ihracata olumlu yansır ya da iç piyasada fiyatları düşürür.

### 2.8 Soru-Cevap

**Soru:** Hiç sentetik görüntü kullanmayı düşündünüz mü? Çok fazla veriye ihtiyaç duyulduğu için orada yoğun bir çalışma gerekecek.

**Cevap:** Düşünmedik. PlantVillage veri setinde yaklaşık 60 bin örnek var. Ancak derin öğrenme yöntemi çok veri istediği için, sağlıklı ve hastalıklı bitki için benzer verileri üretmek gündeme gelebilir. Yine de bunu sentetik veri olarak düşünmedik.

> **Ders sonrası not:** PlantVillage'ın özgün sürümünde büyük olasılıkla yaklaşık 54 bin görüntü vardır. 60 bin civarındaki sayı artırılmış (augmented) sürüme aittir. Bu görüntülerin tamamı domates değildir; domates sınıfları yalnız bir bölümüdür. Grubun "benzer veri üretme" dediği şey de sentetik veri üretimiyle aynı yöne gider.

Aynı derste 7. sunumun bu soruya yakın bir yol izlediğine dikkat edilebilir: o grup, sentetik veri üretimini projenin merkezine koyar.

## 3. GAN ile Otomatik Arayüz Testi Kodu Üretimi

### 3.1 Konu ve Problem

Üçüncü grup, TÜBİTAK 1002 kapsamında kullanıcı arayüzü testi için otomatik test kodu üretimi önerir. Sunum testin neden gerekli olduğunu üç durumla açıklar: Yazılan kodun doğru çalıştığından emin olmak, yeni bir özellik eklerken eski özelliklerin bozulmadığını görmek ve projeyi teslim ederken testlerden geçtiğini göstermek.

Kullanıcı arayüzü testinin kendine özgü zorlukları vardır. Arayüz çok sık değişir: Yeni bir buton eklenir, yazı tipi büyür ya da kalınlaşır. Bu projede arayüz olarak web uygulamaları düşünülür. Yeni web öğeleri eklendikçe karmaşıklık artar ve testlerin sürekli güncel tutulması gerekir.

Selenium gibi araçlar bu işi otomatikleştirir. Bu, otomatik test üretimi olarak anılır. Ancak adımları yine programcı yazar: "Bir web sayfası aç, şu URL'ye git, şu butonu bul, şu metni doldur." Grup programcının kodladığı bu kısmın da bilgisayar tarafından üretilmesini ister. Böylece hem hatalar bulunacak hem testler otomatik yürütülecektir.

### 3.2 Neden Üretken Model?

Grup, başarısı nedeniyle derin öğrenmeye yönelir. Fakat çoğunlukla kullanılan sınıflandırıcı ağlar bu işe uymaz, çünkü üretici bir ağ gerekir. Aradaki fark bir örnekle anlatılır:

- **Sınıflandırıcı:** Elimizde 100 kedi ve 100 köpek resmi varsa, yeni gelen resmin hangi sınıfa girdiğini anlamaya çalışır.
- **Üretici:** 100 kedi resminden 101. kediyi üretmeye çalışır.

Üretici derin öğrenmede en sık kullanılan ağ üretken çekişmeli ağdır (Generative Adversarial Network, GAN). Başka üretici modeller de vardır, ama grup en yaygın olduğu için önce bunu denemek ister. Bir de tek bir örnek değil, sıralı bir çıktı gerekir. Test senaryosunun adımları birbiri ardına anlamlı biçimde gelmelidir. Bu yüzden SeqGAN mimarisi seçilir.

> **Ek bilgi (derste anlatılmadı):** SeqGAN, ayrık dizi üretmek için önerilmiş bir GAN türüdür. Kelime ya da adım gibi ayrık çıktılarda ayırt edicinin geri bildirimi üreticiye doğrudan gradyan olarak aktarılamaz. SeqGAN bu sorunu üreticiyi pekiştirmeli öğrenmedeki gibi eğiterek aşar. Ayırt edicinin puanı ödül olarak kullanılır.

### 3.3 GAN'ın Çalışması

GAN, eğitim verisine çok benzeyen yeni örnekler üretir. Sunumda gösterilen resimlerdeki insanlar gerçek hayatta yoktur. Grup bunu GAN'ların potansiyeline örnek olarak gösterir: Üretilen resimler gerçekten neredeyse ayırt edilemez.

GAN iki ağdan oluşur:

- **Üretici (generator):** Rastgele gürültüden (noise) eğitim verisine benzeyen örnekler üretmeyi öğrenir.
- **Ayırt edici (discriminator):** İki örnekten hangisinin gerçek, hangisinin yapay olduğunu ayırt etmeyi öğrenir.

İki ağ zamanla birbirini besler. Ayırt edici iyi ayırıyorsa, üreticinin onu geçmek için daha iyi yapay örnekler üretmesi gerekir. Üretici iyi örnekler ürettikçe de ayırt edicinin bu farkı kapatması gerekir. Eğitim bittikten sonra yalnız üretici kullanılır. Eğitim verisini öğrendiği için artık gürültüden istediği kadar yapay örnek üretir.

> **Ders sonrası not:** Sunumda ayırt edicinin "çok iyi şeyler üretmesi" gerektiği söylendi. Ayırt edici üretim yapmaz. Doğrusu büyük olasılıkla, gerçek ve yapay örnekleri daha iyi ayırmayı öğrenmesi gerektiğidir.

### 3.4 Amaç ve İş Paketleri

Hedefler sırasıyla şunlardır:

1. Sayfa yapısı bilinen bir site taranır (crawl) ve ayrıntılı sayfa akışları çıkarılır.
2. GAN yöntemlerinden biriyle bu site üzerinde ilerleyebilecek daha fazla akış üretilir.
3. Bu akışlardan kullanıcı arayüzü test betikleri oluşturulur.
4. Test kodu üretimi sayesinde maliyet azaltılır. Grup yaklaşık %90 azalma hedefler.
5. Kapsamlı testler yürütülür. Değerlendirmede perplexity skoru kullanılacaktır.

> **Ek bilgi (derste anlatılmadı):** Perplexity, dil modelleri gibi dizi modellerinde kullanılan bir ölçüdür. Modelin gerçek dizilere ne kadar olasılık verdiğini özetler. Değerin düşük olması, modelin diziyi daha az "şaşırarak" açıkladığını gösterir.

İş paketleri aynı sırayı izler:

- **Akış üretimi:** Oluşturulan akışlardaki her kategori bir kümeye alınır. Gidilebilecek sayfaların sayısı ve elemanları çıkarılır. Bunun üzerinden GAN ile yeni akış üretilir.
- **Parametre optimizasyonu:** Derin öğrenme mimarilerinde çok sayıda hiperparametre vardır ve bunlar başarıyı doğrudan etkiler. Sezgisel parametre optimizasyon yöntemleriyle en iyi parametreler aranır.
- **Akışların incelenmesi:** Gidilme ihtimali olmayan akışlar veri setinden elenir. Yanlış akışların sebepleri araştırılır, gerekiyorsa mimari değiştirilir. Yeni mimariden gelen akışlardan bilinen sayfa yapısına uymayanlar süzülür. Sonuçta yalnız gidilebilecek akışlar kalır.
- **Test betiği üretimi:** Otomatik test betikleri "When ... then ... match" yapısıyla üretilir. Sunumdaki örnek şudur: Belirli bir URL'ye POST metodu gönderilir, durum kodunun 201 olduğu ve yanıtın beklenen yanıtla eşleştiği kontrol edilir.

> **Ders sonrası not:** Sunumda bu yapı Selenium'a bağlandı. Selenium bir tarayıcı otomasyon aracıdır ve HTTP durum kodunu doğrudan denetlemez. Anlatılan söz dizimi büyük olasılıkla Karate gibi "When method post, Then status 201, And match ..." biçimini kullanan bir API test aracına aittir. Ayrıca bu örnek arayüz testi değil, API testidir. Raporda ikisi ayrılmalıdır.

<!-- BELİRSİZ: "When ... then ... match" ifadesi altyazıda "Vend'en sonrasında match / Vendem Match" diye bozuk geçiyor; slayttaki kesin söz dizimi doğrulanamıyor. -->

### 3.5 Çıktılar ve Beklenen Etki

Araştırmada üretilen kodlar açık kaynak olarak GitHub'da paylaşılacak, böylece başka araştırmacılar da geliştirebilecektir. Bir bildiri ve bir makale hedeflenir. Ar-Ge çalışmaları sonrası geliştirmeler yapılırsa ürün ticari hale gelebilir: Web uygulaması kullanan ve arayüz testini otomatik üretmek isteyen bir şirket bu ürünü satın alıp üzerine ekleme yapabilir.

- **Toplumsal:** İnsan eforunun ve test kodu yazımının otomatikleştirilmesi.
- **Akademik:** Yapay zekayla, GAN ya da ileride LSTM gibi farklı mimarilerle test kodu üretimi.
- **Ekonomik:** Yanlış test edilen sistemler ciddi zaman ve para kaybına yol açar. Üretilen prototip belirli bir pazar payı oluşturabilir.
- **Güvenlik:** Yeni kurulan girişimler web sitelerindeki hataları önceden bulabilir, güvenlik açıklarına karşı önlem alabilir.

Bu sunumdan sonra soru gelmez.

## 4. Bulut Tabanlı Akıllı Galeri Uygulaması

### 4.1 Konu ve Mevcut Uygulamalar

Dördüncü grup, kullanıcıların cep telefonundaki fotoğraflara çok daha hızlı ulaşmasını sağlayan bir galeri uygulaması önerir. Çevrim içi ve çevrim dışı tarama yöntemleri birleştirilecektir.

<!-- BELİRSİZ: Sunumun ilk yaklaşık 30 saniyesi (00:44:00-00:44:30) altyazıda yok; konunun giriş cümleleri eksik. -->

Grup piyasada öne çıkan üç uygulamayı karşılaştırır:

| Uygulama | Güçlü yan | Zayıf yan |
|---|---|---|
| Android'de yüklü gelen fotoğraflar uygulaması | Daha fazla gruplama seçeneği. Google Drive ile eşitlenirse kategorilendirme yapar | Gizlilik ve istenmeyen iletişim ücreti nedeniyle kullanıcı tercih etmeyebilir |
| Sony Xperia albüm uygulaması | Tasarımı üstün | Hiç kategorilendirme yok |
| iOS galeri uygulaması | Çevrim dışı gruplama ve fotoğraflarda arama | Kategoriler çok kısıtlı. Android'de benzeri yok |

### 4.2 Öneri

Projenin öne çıkan noktası, görsel içeriğin bulut tabanlı taranması ve etiketlerin kullanıcıya dönmesidir. Kullanıcıya çok çeşitli fotoğraf kategorisi sunulur. Örneğin bir doğum günü fotoğrafını arayan kullanıcı "pasta" yazarak içinde pasta olan fotoğraflara ulaşır. Tarih aralığı gibi sınırlamalarla sonuçlar daraltılır, arama gerçek zamanlı yapılır. Başka bir örnek: Kullanıcı fotoğraf çekildiğinde kar yağdığını hatırlıyorsa "kar" diye arayabilir.

Grup estetik ve işlevsel kaygıları da vurgular. Gösterilen uygulamalar büyük firmaların ürünleridir, ama tasarımları grubun gözünde o kadar iyi değildir. Hedef daha kullanıcı dostu ve zaman kazandıran bir uygulamadır.

### 4.3 Fizibilite

- **Yazılım:** Android akıllı cihazlar için uygulama yazılacak. En yüksek pazar payı Android'de olduğu için bu seçilmiştir. Geniş kitleye ulaşmak için API 16 ve üzeri desteklenir. En güncel özellikler için hedef geliştirme kiti API 25'tir.
- **Donanım:** Android Studio çalıştıracak bir bilgisayar ve test cihazı gerekir. Yapay zeka modellerinin ilk prototipi bu cihazda yapılacağı için grafik kartı güçlü olmalıdır.
- **Yasal:** Kullanılan yazılım araçları açık kaynak, GNU ya da Apache lisanslıdır. Ancak program Google Cloud Vision API'ye hassas bilgi göndereceği için Google'ın sunduğu KVKK'lar geçerlidir.

> **Ders sonrası not:** Sunumda bütün araçların açık kaynak olduğu ve "Google'ın KVKK'larının" geçerli olduğu söylendi. Doğrusu büyük olasılıkla şudur: Google Cloud Vision API ticari bir servistir, açık kaynak değildir. KVKK ise Google'ın değil Türkiye'nin kişisel veri yasasıdır. Google'ın koşulları ayrıca geçerlidir, ama kişisel veri içeren fotoğrafların yurt dışındaki bir buluta gönderilmesi KVKK'nın yurt dışına veri aktarımı kurallarına da tabi olur.

### 4.4 Teknik Yöntem

Fotoğraftan bilgi alınabilecek yerler üç gruptur.

- **Meta veri:** Tarih, konum ve çözünürlük bilgisi vardır. Gruplama için kullanılır.
- **Bitmap tabanlı modüller:** Fotoğrafın kendisi de bir veridir. Çevrim dışı taramada yüz özelliklerine bakılarak vesikalık, mutlu ve gülümseyen fotoğraflar ayrılır. Benzerliğe göre gruplama, art arda çekilmiş çok benzer fotoğrafları bulur. Kullanıcı bunların istemediklerini silerek cihazda yer açar.
- **Bulut tabanlı modüller:** Grubun asıl üzerinde durduğu kısımdır. Bulut sunucularda işlem gücü yüksektir. Telefonun asıl görevi ise anlık veriyi kararlı biçimde göstermektir. Sunuma göre yüksek kapasiteli hesaplamalar mimari gereği mobil cihazda yapılmamalıdır.

Bu yüzden fotoğraflar bulutta bir defaya mahsus taranır ve etiketler uygulamaya alınır. Sonrasında çevrim dışı tarama yöntemleriyle arama gerçek zamanlı yapılır. Slaytta görülen vesikalık ve mutlu yüz örnekleri Google Cloud Vision API'nin yüz özelliklerini tanıma yöntemlerinden elde edilmiştir. Altta görülen örnekler içerik etiketleridir: kar, fırtına, hava durumu gibi.

### 4.5 İş Paketleri

Projede toplam 6 iş paketi vardır. Çoğu paralel yürür:

- **Paralel yürüyenler:** Görsellerin veri yönetimi, kullanıcı arayüzü, görsel arama modülü ve benzer fotoğrafları bulan algoritma.
- **Sıralı yürüyenler:** Google Cloud API'den etiketlerin ön yüze alınması ve arka planda çevrim dışı tarama modülü.

Riskler bölümünde benzer fotoğraf algoritması 4., Google Cloud API iletişimi 5. iş paketi olarak anılır.

### 4.6 Riskler, Çıktılar ve Bütçe

Sunumda üç büyük risk ve bunların B planı verilir:

| Risk | B planı |
|---|---|
| Benzer fotoğraf modelinin başarısının çok düşük kalması | Alternatif meta veri kullanımı. Grup bunun içerik tarama başarısını artıracağını düşünür |
| Google Cloud API iletişim maliyetinin yükselmesi | Başka veri sağlayıcısına geçmek ya da yerel sunucuda ön bellek tutarak servisi öyle sunmak |
| Uygulamanın çok enerji tüketmesi | Enerji tüketen kısımları yalnız limitsiz ağda ve şarjdayken çalıştırmak |

Çıktı olarak bir makale ve bir uygulama hedeflenir. Uygulama genel kullanıcıya olduğu kadar fotoğrafçı ve gazeteci gibi profesyonellere de yarayacaktır. Bütçe kalemleri bir cihaz, hizmet alımı olarak Google API'si ve iki bursiyerdir. Toplam tutar altyazıda söylenmez. Bu sunumdan sonra da soru gelmez.

## 5. Banka Dokümanlarında Çok Görevli Öğrenme

### 5.1 Konu ve Önem

Beşinci grup, çok görevli öğrenmeyle banka dokümanlarında ilgili alan tespiti, bilgi çıkarımı ve imza doğrulama önerir.

Sunum, Türkiye Bankalar Birliği verilerine göre milyonlarca insanın dijital bankacılık kullandığını ve bu sayının arttığını söyler. Dijital kanallardaki ürün ve hizmet çeşitliliği de artmaktadır. Buna karşılık bu kanallardan alınan müşteri evrakı tamamen elle işlenip arşivlenmektedir. Grup, bilgisayarlı görü yöntemleriyle belgelerden isim, kimlik numarası, kart numarası gibi bilgileri ve müşteri imzasını çıkarmayı önerir. İmza da doğrulanarak sahtecilik olup olmadığı tespit edilir.

Konunun önemi şöyle gerekçelendirilir:

- Doküman işleme rutin bir iştir, ama çok insan kaynağı ve zaman harcar.
- İnsan kaynaklı hatalar banka ve müşteri için maddi ve manevi zarara yol açabilir.
- İmzalar, insan gözüyle ayırt edilemeyecek kadar iyi taklit edilmiş olabilir.

### 5.2 Özgün Değer ve Hedefler

Literatürde imza doğrulama, bilgi alanı tespiti ve bilgi çıkarımı için ayrı çalışmalar vardır ve iyi başarı oranlarına ulaşılmıştır. Ancak üç problemi bir arada ele alıp bir belgeyi uçtan uca işleyerek arşivlenebilir hale getiren bir sistem yoktur. Grup bu boşluğu hedefler. Ayrıca literatürden farklı olarak çok görevli öğrenme (multi-task learning) kullanıp mevcut başarıları geçmeyi planlar.

Hedefler şunlardır:

- Bankacılık evrakında veri işlemeyi tamamen otomatikleştirmek, daha pratik ve güvenli hale getirmek.
- Üç görevi birlikte yapan bir çalışmayla literatüre katkı sağlamak.
- Çok görevli öğrenmenin ve farklı derin öğrenme mimarilerinin etkisini karşılaştırmalı olarak araştırıp yayımlamak. Bu, başka belge türlerinde çalışacak araştırmacılara da referans olur.

### 5.3 Veri

İmza doğrulama için açık kaynaklı farklı veri setleri vardır. Bankacılık evrakı için ise Türkçe açık veri seti yoktur. Grup literatüre böyle bir veri seti kazandırmayı hedefler.

Veri, grubun anlaştığı bir bankadan gelecektir. Bankada Ar-Ge süreçleri için müşteri verilerinin maskelendiği ve sentetik verilerle üretilmiş dokümanlar bulunur. Bunlardan 1000 tanesi alınacaktır. Belgeler ağırlıklı olarak hesap açılış sözleşmesi, para transferi formları ve kredi kartı başvuru formu gibi yaygın belgelerdir.

Görüntülerin işlenip etiketlenmesi ve model eğitimine hazırlanması için Amazon Mechanical Turk hizmeti alınacaktır. Bu 1000 taranmış görüntüden müşteri numarası, kart numarası, işlem tutarı gibi bilgilerin çıkarılması hedeflenir.

### 5.4 Üç Görev ve Literatür

Yöntem üç görevden oluşur:

1. **İmza doğrulama:** Belgenin güvenliğini sağlar.
2. **İlgili alanların tespiti:** Müşterinin girmesi beklenen isim, soy isim, adres, telefon numarası gibi alanlar bulunur.
3. **İçerik çıkarımı:** Bu alanlardaki bilgi optik karakter tanıma (optical character recognition, OCR) ile çıkarılır.

Grubun literatür okumasına göre geleneksel makine öğrenmesi ve bilgisayarlı görü yöntemleri imza doğrulamada ve alan tespitinde başarılıdır. Derin öğrenme mimarileri kullanıldığında bu başarı biraz düşer. Grubun hipotezlerinden biri, bu başarının artırılabileceği, hatta derin öğrenmenin geleneksel yöntemleri geçebileceğidir.

OCR tarafında el yazısı üzerine son yıllardaki bir derin ağ çalışmasında %6,8 karakter hata oranı bildirilir. Bu, $100 - 6{,}8 = 93{,}2$ yani %93,2 doğruluk demektir.

<!-- BELİRSİZ: Anılan el yazısı çalışmasının yazarı altyazıda "Buluşa" diye geçiyor; doğru ad anlaşılmıyor. -->

### 5.5 Neden Çok Görevli Öğrenme?

Üç görev için üç ayrı model eğitip bunları art arda bağlamak mümkündür. Ancak bu durumda sistemin başarısı her modelin başarısıyla sınırlanır. Örneğin bilgi içeren alanlar doğru bulunamazsa OCR modeli de başarılı çalışamaz. Bunu gidermek için sistemin üç göreve ortak eğitilmesi gerekir.

Grubun kullanmayı planladığı çok görevli öğrenme yapısı şöyledir:

```text
                         +-> imza doğrulama sınıflandırıcısı
belge -> ortak öznitelik |
         çıkarıcı        +-> alan tespiti sınıflandırıcısı
                         |
                         +-> OCR sınıflandırıcısı (RNN eklenmiş)

Eğitim: üç görev için ortak hesaplanan hata fonksiyonu, eş zamanlı
```

Üç ayrı özellik çıkarıcı yerine bir tane vardır. Çıkarılan özellikler göreve özel sınıflandırıcılara gider. Eğitim, üç görev için ortak hesaplanan bir hata fonksiyonuyla eş zamanlı yapılır.

Kaynak alınan çalışmada basit sınıflandırıcılar kullanılmıştır. Bu projede daha karmaşık sınıflandırıcılar gerekir. Örneğin OCR modeline RNN eklenmelidir. Grup, çok görevli öğrenmenin karmaşık modellerdeki başarısını ölçmeyi ayrı bir akademik katkı olarak görür.

> **Ders sonrası not:** Altyazıda "Şener ve Colton" diye anılan çalışma büyük olasılıkla Ozan Sener ve Vladlen Koltun'un "Multi-Task Learning as Multi-Objective Optimization" (NeurIPS 2018) makalesidir.

> **Ek bilgi (derste anlatılmadı):** Çok görevli öğrenmede ortak kayıp çoğu zaman görev kayıplarının ağırlıklı toplamıdır. Görevler birbiriyle çelişebildiği için ağırlıkların seçimi sonucu etkiler. Sener ve Koltun'un çalışması problemi tek bir toplam kayıp yerine çok amaçlı optimizasyon olarak ele alır.

### 5.6 Değerlendirme ve Riskler

Yöntemin gerçek hayata uygulanabilirliğini ölçmek için basit bir web uygulaması geliştirilir. Uygulama 10 kişilik bir grup tarafından 2 hafta test edilir. Her kullanımın sonunda ve test süresinin bitiminde farklı anketler yapılır.

Riskler ve B planları şunlardır:

- **Modelin beklenen başarıyı gösterememesi:** Üç omurga (backbone) mimarisi seçilmiştir: VGG, ResNet ve Inception. Yeterli olmazsa başka omurgalar denenir.
- **Yeterli veri toplanamaması:** Veri artırma (data augmentation) ile veri çoğaltılır.
- **Teste yeterli kişi katılmaması:** Bazı anketler Amazon Mechanical Turk üzerinden yapılır.

Bu sunumdan sonra içerikle ilgili soru-cevap yapılmaz.

## 6. Topraksız Dikey Tarımda Makine Öğrenmesi

### 6.1 Konu ve Önem

Altıncı grup, topraksız dikey tarımda yapay zeka ve makine öğrenmesiyle verim ve kaynak optimizasyonunu önerir. Gerekçe şudur: Nüfus arttıkça kaliteli besine ihtiyaç artar. Ekonomik ve ekolojik sorunlar ile insan kaynaklı hatalar besine ulaşmayı zorlaştırır. Betonlaşma nedeniyle verimli topraklar da azalır. Topraksız tarım uygulamaları bu ortamda ortaya çıkmıştır ve literatürde çok sayıda çalışması vardır. Grup bunların üzerine makine öğrenmesiyle optimizasyon eklemek ister.

Literatürdeki boşluk şöyle tanımlanır: Makine öğrenmesi uygulamaları genellikle geleneksel tarım üzerinedir ve daha çok ortam verilerine göre yapılacak işlem tahminine odaklanır. Grubun getirdiği yenilik, üretim sistemini kontrollü başlatmaktır. Üretim başlarken sistemin çok verimli, verimli, az verimli ya da verimsiz olacağı tahmin edilir ve sistem buna göre başlatılır.

<!-- BELİRSİZ: Ortam verilerine örnek olarak söylenen ifade altyazıda "fon açıkabı" diye bozuk geçiyor. -->

### 6.2 Araştırma Sorusu ve Hipotez

Araştırma sorusu şudur: Topraksız dikey tarımda yapay zeka ve makine öğrenmesi kullanarak ürün verimini artırmak ve aynı anda kaynak tüketimini azaltmak mümkün mü? Hipotez, bu uygulamalarla verimin artırılabileceğidir. Grup, kaybı azaltarak maliyeti düşürmeyi ve kâr marjını yükselterek bu uygulamaların yaygınlaşmasına katkı sağlamayı hedefler.

### 6.3 İş Paketleri ve Zamanlama

Plan 4 ana ve 11 ara iş paketinden oluşur.

| İş paketi | Ay | İçerik |
|---|---|---|
| 1. Ekonomik analiz | 1-2 | Topraksız ve geleneksel üretim arasında kâr-zarar karşılaştırması. Başvurudan önce de bir ekonomik analiz yapılmıştır |
| 2. Üretim sistemi altyapısı | 1-3 | Tamamen kapalı cam kabinin siparişi ve üretimi, sonra içine donanımların kurulması, ardından gerçek ölçümlerin başlatılması |
| 3. Veri seti araştırması | 3-10 | Bitki bilimi uzmanından danışmanlık, başlangıç veri seti ve optimum değerler, verilerin analizi ve üretimde kullanımı |
| 4. Raporlama ve gelecek planı | 9-12 | Sonuçların mevcut topraksız tarım verileriyle kıyaslanması, uluslararası bildiri, gelecek planları |

Üçüncü pakette her hasat sonunda elde edilen veriler başlangıç veri setine eklenir. Böylece veri seti sürekli büyür.

<!-- BELİRSİZ: İkinci iş paketindeki ölçüm adımı altyazıda "Numayına hekimini" diye bozuk geçiyor; tam adı anlaşılmıyor. -->

### 6.4 Uygulama Yöntemi

Sistemin teknik ekipmanları literatürdeki bir makaleden alınan görselle gösterilir. Grubun literatürden ayrıldığı nokta şudur: Katmanlı sistemlerde bitkiler genellikle PVC borular yardımıyla yetiştirilir, grup ise tepsi kullanmayı tercih eder.

<!-- BELİRSİZ: Tepsi tercihinin gerekçesi ve tepsi türü altyazıda "daha çeviri bir yaklaşımla ... paslama tepsileri" diye bozuk geçiyor. -->

Hasat tahmini çalışmalarında sık kullanılan algoritmalar KNN ve karar ağacıdır (Decision Tree). Grup bunlara üçüncü bir algoritma ekleyip karşılaştırma yapacaktır. Çıkan tahminler (çok verimli, verimli, az verimli, verimsiz) geleneksel tarım yöntemleriyle de kıyaslanacaktır.

<!-- BELİRSİZ: Eklenecek üçüncü algoritmanın adı altyazıda "S20" diye geçiyor; hangi algoritma olduğu anlaşılmıyor. -->

Pilot bitki nanedir. İlk veri bitki bilimi uzmanından alınır. Optimum büyüme koşulları olarak pH, EC, sıcaklık ve nem kullanılır. Hasat ilerledikçe yaprak büyüklüğü, genişliği ve besin değerleri gibi ek parametreler veriye eklenir. Eğitim bu genişleyen veriyle sürer.

> **Ek bilgi (derste anlatılmadı):** EC, elektriksel iletkenlik (electrical conductivity) demektir. Topraksız tarımda besin çözeltisindeki çözünmüş tuz miktarının dolaylı bir ölçüsü olarak izlenir. pH ise bitkinin besinleri alabilmesini etkiler. Bu yüzden ikisi birlikte takip edilir.

### 6.5 Riskler

Genel riskler hastalık, afet, ekonomik kriz ve pandemidir. Projeye özel riskler ve önlemler şöyledir:

| Risk | Önlem |
|---|---|
| Cihaz bozulması ve arızası | Önemli cihazların yedekli temini, bozulunca hemen değiştirme |
| Fidelerin hastalıklı olması | Kaliteli ve bilinen bir markadan temin |
| Depolanan verinin kaybı (grubun en büyük risk saydığı) | Verilerin birkaç farklı sunucuda yedeklenmesi |
| Optimum büyüme koşullarında referans değer hatası | Bitki bilimi uzmanıyla birlikte çalışmak |
| Bildirinin reddedilmesi | Farklı indeksli dergilere gönderme, geri dönüşte hızla revize edip yeniden başvurma |

> **Ders sonrası not:** Sunumda bildirinin "indeksli dergilere" gönderileceği söylendi. Doğrusu büyük olasılıkla şudur: Bildiri konferansa, makale dergiye gönderilir. Raporda hedeflenen çıktı türü netleştirilmelidir.

### 6.6 Beklenen Etki, Bütçe ve Gelecek Planı

Beklenen etkiler şöyle sıralanır:

- **Akademik:** Topraksız tarımda hasat tahmini yapılarak literatüre yeni bir bakış açısı kazandırılır. Eklenen verilerle bitki bilimine yeni bir veri seti kazandırılır.
- **Ekonomik:** Üretim cihazı bir prototiptir, seri üretilip satılabilir. Üretim arttıkça ithalat ihtiyacı azalır, ürün fazlası olursa ihracat yapılabilir.
- **Toplumsal:** Çevre koşullarından bağımsız, her alanda üretim yapan bir sistemle tarımsal üretim artar. Kaliteli besine erişim artar, yaşam kalitesi yükselir.
- **Çevresel:** Verimli hasat tahminiyle ziyan azalır. Su ve elektrik en uygun biçimde kullanılır, doğal kaynaklar korunur.

Toplam bütçe 24.328 TL'dir. Grup, öneren kuruluş katkısı düşüldükten sonra TÜBİTAK'tan talep edilen tutarı da 24.328 TL olarak verir. İhtiyaç kalemleri slaytta yer alır, sözlü olarak sayılmaz.

Gelecek planında amaç, her bitki için optimum büyüme koşullarını otomatik hesaplayan ve bunları farklı sistemlere uygulayan bir üründür. Böylece tarımda insan etkisi büyük oranda azalacaktır. Bu sunumdan sonra soru gelmez.

## 7. DOHTES: Sentetik Hiperspektral Görüntülerle Domates Hastalığı Tespiti

### 7.1 Konu ve Gerekçe

Yedinci grup, 1002 Hızlı Destek Programı kapsamında DOHTES (Domates Hastalık Tespit Sistemi) önerir. Domatesin seçilme nedeni değerli bir besin olmasıdır. Sunuma göre vitamin ve mineral bakımından zengindir, lifli yapıdadır, kalori ve yağı düşüktür, kolesterol içermez. İşlenmiş ve ham olarak çok tüketilir, ticareti yapılan tarım ürünleri arasında ilk sırada yer alır. Sunuma göre Türkiye dünya domates ihracatında üçüncü sıradadır. Grup "neden birinci olmayalım?" diye sorar ve erken teşhisle bu sırayı yükseltmeyi hedefler.

> **Ders sonrası not:** Türkiye'nin dünya domates ihracatındaki sırası 2. sunumda beşinci, bu sunumda üçüncü olarak verildi. Bu farkın nedeni büyük olasılıkla yıl, kaynak ya da taze ve işlenmiş ürün ayrımıdır. Raporda sıra, kaynağı ve yılıyla verilmelidir.

### 7.2 Hastalıklar ve Tespit Yöntemleri

Domateste sık görülen hastalıklar külleme gibi mantar hastalıkları, lekeli solgunluk virüsü gibi virüs hastalıkları ve bakteriyel hastalıklardır. Tespit çalışmalarında üç yöntem ailesi kullanılır:

- **Moleküler ve spektroskopik yöntemler:** Laboratuvar ister. Zaman ve bütçe açısından maliyetlidir.
- **Görüntü yöntemleri:** CNN tabanlı derin öğrenme modellerinin başarısıyla öne çıkmıştır.

Görüntü yöntemlerinde üç tür görüntü vardır:

- **Termografik görüntü:** Bitkinin ısıl bilgisinden elde edilir.
- **RGB görüntü:** Sunumun ağırlıklı olarak değerlendirdiği görüntü türüdür.
- **Hiperspektral görüntü:** Gözle görülebilir dalga boyundan daha geniş spektrumdaki bilgiyi kullanır.

### 7.3 Literatürdeki Yaklaşımlar

İlk RGB çalışmalarında temel yöntemler kullanılmıştır. İyi sonuç alınsa da öznitelik çıkarma (feature extraction) yorucu ve zaman alıcıdır. Bunu aşmak için derin öğrenmeye geçilmiştir. Başarı artar, fakat bu modeller çok veri ister. Bu yüzden sonraki çalışmalar sentetik veri üretimine yönelmiştir. Grubun referans çalışmalarından birinde GAN ile sentetik veri üretilmiş, üç sınıflandırma modeli karşılaştırılmış ve ResNet ciddi başarı göstermiştir. Grup bu sonuç ve ResNet'in bilinen başarısı nedeniyle sınıflandırmada ResNet'i tercih eder.

### 7.4 Fikir ve Özgün Değer

Bütün bu başarılar RGB görüntüler üzerindedir. Grup, RGB'de görülemeyen hastalıkları daha erken teşhis etmek ister. Hiperspektral görüntü bunu sağlayabilir, ama çok maliyetlidir. Bir hiperspektral kamera bile çok pahalıdır. Bu yüzden grup hiperspektral görüntüyü sentetik olarak üretmeyi önerir.

Grup, bunu yapan başka bir alandaki bir çalışmaya dayanır. Domates hastalığı tespitinde böyle bir çalışma yoktur. Yöntemi kendi sahasına uyarlamak grubun literatüre sunduğu yeniliktir.

<!-- BELİRSİZ: Dayanılan çalışma 01:21:23-01:21:39 aralığında altyazıda yok; çalışmanın adı ve alanı doğrulanamıyor. -->

### 7.5 Sistem

Tarladan iyi bir kamerayla alınan domates yaprağı görüntüsü sisteme verilir. Sistem hastalıklı ya da sağlıklı kararını erken verir. Sistemin iki temel bileşeni iki iş paketine karşılık gelir: koşullu GAN (conditional GAN, cGAN) ve ResNet.

```text
RGB domates yaprağı görüntüsü -> cGAN -> sentetik hiperspektral görüntü -> ResNet -> hastalıklı / sağlıklı
```

Bütçede iki kalem öne çıkar. Kaliteli görüntü önemli olduğu için bir RGB kamera istenir. Üretilen hiperspektral görüntüler çok disk gerektirdiği için bir disk istenir.

### 7.6 Birinci İş Paketi: cGAN (2 ay)

Önce model tasarlanır. cGAN iki ağdan oluşur: Üretici (generator) sentetik veri üretir, ayırt edici (discriminator) onu bir bakıma denetler. Eğitim, üretici ayırt ediciyi kandıracak kalitede veri üretene kadar sürer.

Burada bir sorun vardır: Hiperspektral görüntü üretmek için eğitimde hiperspektral görüntü gerekir, ama domates için böyle bir veri yoktur. Çözüm adımları şöyledir:

1. Başka bir alana ait açık kaynaklı hiperspektral veri seti ICVL kullanılır. Bu bir alan uyarlamasıdır (domain adaptation).
2. Düz GAN değil cGAN kullanıldığı için koşul olarak RGB görüntü, yani görüntü çifti gerekir. ICVL'de RGB karşılıklar yoktur.
3. RGB görüntüler, CIE 1964 10 derece eşleştirme fonksiyonuyla hiperspektral görüntülerden hesaplanır. Eğitim bu çiftlerle tamamlanır.
4. Elde edilen veri çiftleri ileride kullanılsın diye açık kaynak olarak paylaşılır.
5. Domates hastalıklı yapraklarını içeren açık bir RGB veri seti eğitilmiş cGAN'dan geçirilir ve sentetik hiperspektral domates görüntüleri üretilir.
6. RGB görüntüler de eklenerek kapsamlı bir veri seti oluşur. Bu da açık kaynak olarak paylaşılır. Grup bunu akademiye ve sanayiye katkı olarak görür.

> **Ders sonrası not:** Sunumda "hiperspektral kamera olan CIE 1964 10 derece" denildi. CIE 1964 10 derece bir kamera değildir. Doğrusu büyük olasılıkla CIE'nin 10 derece standart gözlemcisine ait renk eşleme fonksiyonlarıdır.

<!-- BELİRSİZ: RGB domates veri setinin adı altyazıda "Prens Bridge" diye geçiyor; doğru ad anlaşılmıyor. -->

### 7.7 İkinci İş Paketi: ResNet

Sentetik hiperspektral görüntülerle mozaik virüsü, yaprak küfü ve erken yaprak yanıklığı gibi 9 farklı hastalık tespit edilecektir.

ResNet'in çözdüğü problem şudur: Derin öğrenmede katman sayısı arttıkça öğrenme durur, hatta kötüleşir. Çözüm olarak artık bloklar (residual blocks) önerilmiştir. Sunuma göre bu bloklar peş peşe gelen iki evrişim katmanının çıkışlarının eklenmesiyle elde edilir. Mimari, 2015'te ImageNet geniş ölçekli görsel sınıflandırma yarışmasında birinci olmuştur.

> **Ders sonrası not:** Sunumdaki artık blok tanımı eksiktir. Doğrusu büyük olasılıkla şudur: Bloğun girişi, kısayol bağlantısıyla (skip connection) iki evrişim katmanının çıkışına eklenir. Eklenen şey iki katmanın çıkışları değildir.

Model eğitildikten sonra Antalya bölgesinde ziraat mühendisleri eşliğinde saha testi yapılacaktır. Bu sunumdan sonra soru gelmez.

## 8. Türkçe Sahte Haber Tespiti

### 8.1 Konu ve Önem

Son grup Türkçe sahte haber tespitini önerir. Teknoloji ilerledikçe sahte haberler hızla yayılır ve toplumu geniş biçimde etkiler. Sunumda sayılan zararlar yanlış bilgilendirme, korkuya sevk etme, umutsuzluk aşılama ve ekonomik kayıptır. Çoğu programlanmış botlardan gelen ve 7/24 yanlış bilgi yayan sayısız kaynak vardır. Verinin yayılma hızı, boyutu ve çeşitliliği düşünülünce sahte haberi tespit eden bir sınıflandırma algoritması geliştirmek zordur.

Sunumdaki iki grafikten şu sonuçlar çıkarılır:

- En yüksek yayılım hızı ve en yüksek risk; propaganda, manipülasyon, deepfake (video içerik değiştirme), provokatif içerik ve nefret söylemi içeren sahte haberlerdedir. Sahte bilimsel haberler ve dedikodu içeren asparagas haberler de çok hızlı yayılır.
- Sahte habere maruz kaldığını belirtenlerin oranında Türkiye %49 ile birinci sıradadır. Grup bunu genç nüfusa ve sosyal medyanın aktif kullanımına bağlar.

2015-2018 arası bir araştırmaya göre Türkiye'de haberlere erişim kaynakları şöyledir:

| Kaynak | Oran |
|---|---|
| Çevrim içi platformlar | %88 |
| Televizyon | %75 |
| Sosyal medya | %66 |
| Gazete ve dergi gibi basılı yayınlar | %50'nin altında |

### 8.2 Amaç ve Literatür

Literatürde sahte haber çalışmalarının çoğu İngilizcedir. Grup Türkçe araştırmanın azlığını Türkçe veri seti eksikliğine bağlar. Bu yüzden öncelikli amaç bir Türkçe veri seti oluşturup literatüre kazandırmaktır. Sonra doğal dil işleme ve makine öğrenmesiyle Türkçe haber metinlerinde sahtelik tespiti yapılacaktır.

Literatürde iki örnek anılır. İlkinde veri seti Twitter üzerinden oluşturulmuştur. Diğerinde haberler üç farklı kaynaktan toplanmıştır: GDELT, teyit.org ve elle derlenen veri.

- **GDELT:** 100'den fazla dilde, neredeyse her ülkeden dünya haber medyasını izleyen küresel bir veri tabanıdır. Geçerliliği artırmak için bu çalışmada yalnız Anadolu Ajansı gibi büyük ajansların haberleri kullanılmıştır.
- **teyit.org:** İnternette yayımlanan ve doğruluğu şüpheli içerikleri açık kaynaklara dayanarak analiz eden, Türkiye merkezli bir doğrulama platformudur.

### 8.3 Birinci Adım: Veri Seti

Grup için en kilit nokta veri setidir. Kaynaklar GDELT, Twitter ve Facebook gibi platformlardır. Önceki çalışmalardan farklı olarak Instagram gibi başka sosyal medya platformları da kullanılacaktır. Güvenilir haber sitelerinden de haber toplanıp karma bir veri seti oluşturulacaktır. Güvenilir sitelerden gelenler o sitenin güvenilirliğine bakılarak "doğru" etiketlenecek, diğerleri elle etiketlenecektir.

### 8.4 İkinci Adım: Ön İşleme

- **Durak kelimeler (stop words):** Hemen her cümlede bulunan, anlam taşımayan ama benzerlik ölçütlerini değiştiren kelimeler atılır.
- **Kod temizliği:** Veri internetten geldiği için HTML ve JavaScript kodları temizlenir.
- **Türkçe karakterler:** Grup, birçok algoritmanın bu karakterleri kabul etmeyeceğini söyler ve metinlerden arındırır.
- **Biçimsel analiz:** Türkçe doğal dil işleme kütüphanesi Zemberek ile yapılır.

> **Ders sonrası not:** Sunumda algoritmaların Türkçe karakterleri kabul etmeyeceği söylendi. Doğrusu büyük olasılıkla şudur: Güncel kütüphanelerin çoğu UTF-8 metinle çalışır, modeller de sayısal temsillerle çalışır. Türkçe karakterleri kaldırmak ise "sık" ve "sik" gibi kelimeleri birleştirerek anlam kaybına yol açabilir. Zemberek de Türkçe karakterli metinle çalışır, bu yüzden karakterleri ondan önce silmek biçimsel analizi zorlaştırır.

### 8.5 Üçüncü Adım: Sınıflandırma

Dört yöntem denenecek ve sonuçları karşılaştırılacaktır.

**Naive Bayes:** Bayes teoremine dayanır. Sunuma göre dengesiz veri setlerinde de iyi sonuç verebildiği için çok kullanılır. Her eleman için her durumun olasılığını hesaplar, olasılığı en yüksek olana göre sınıflandırır.

**Karar ağacı:** Özellik uzayını sınırlarla böler, her bölgede tek bir sınıfa ait örnekler bırakmaya çalışır. "If" yapıları gibi bir kural seti oluşturur. Kilit nokta, köke yerleştirilecek en ayırt edici özelliği bulmaktır. Grup bunun için entropi ve bilgi kazancından yararlanır. Sunuma göre entropi ne kadar büyükse özellik o kadar bilgi içerir.

> **Ders sonrası not:** "Entropi yani bilgi kazancı" ve "entropi büyüdükçe özellik o kadar bilgi içerir" ifadeleri hatalıdır. Doğrusu büyük olasılıkla şudur: Entropi bir düğümdeki belirsizliği ölçer. Bilgi kazancı ise bölme sonrası entropideki azalmadır. Köke, bilgi kazancı en yüksek özellik konur.

**Lojistik regresyon:** Çıkış sürekli değildir. Sonuç sıfır ya da birdir, yani doğru ya da sahte haberdir. Yöntem bağımsız değişkenler arasındaki ilişkiyi en iyi tanımlayan modeli bulur ve sınıflandırma yapar.

> **Ders sonrası not:** Sunumda yöntemin gerekçesi "problemimiz doğrusal" diye verildi. Doğrusu büyük olasılıkla "problemimiz ikili sınıflandırma" olmalıdır, çünkü gerekçe çıkışın iki değerli olmasıdır.

**CNN:** Veri eğitim, doğrulama ve test olarak ayrılır. Başlangıçta 3 katman, aktivasyon fonksiyonu olarak ReLU ve çıkış ikili olduğu için ikili çapraz entropi (binary cross-entropy) kaybı kullanılacaktır. Katman yapısı, epoch ve batch sayısı doğrulama setindeki başarı ve kayıp sonuçlarına göre değiştirilecektir.

Grup iki amacını böyle özetler: literatüre Türkçe sahte haber veri seti kazandırmak ve bu veri setinde dört yöntemi karşılaştırmak. Bu sunumdan sonra da soru gelmez.

## Dersin Toparlaması

Bu derste sekiz araştırma projesi önerisi dinlendi. Konular tarım (besleme istasyonu dışında üç proje), yazılım testi, mobil galeri, bankacılık evrakı ve doğal dil işleme alanlarına yayıldı. İki grup domates hastalığı üzerine çalıştı, ama yaklaşımları çok farklıydı: Biri mobil uygulama ve saha verisine, diğeri sentetik hiperspektral görüntü üretimine dayanıyordu.

Sunumlarda tekrar eden proje önerisi öğeleri şunlardı: araştırma sorusu ve hipotez, literatürdeki boşluk ve özgün değer, iş paketleri ve süreleri, olasılıklarına ya da önemlerine göre sıralanmış riskler ve B planları, akademik, ekonomik, toplumsal ve çevresel etki, bütçe. Veri neredeyse her projede ana zorluk olarak öne çıktı. Grupların çözümleri saha çalışması, sentetik veri, kurumdan temin ve açık veri setlerini birleştirmek oldu. Birkaç proje de yeni veri setini literatüre kazandırmayı ayrı bir katkı olarak sundu. Ders sonrası notlar ise bir öneride kaynak gösterilen sayıların ve kullanılan kavramların tek tek doğrulanması gerektiğini gösteriyor. Bu ders dönemin son dersiydi ve derste sonraki bir konuya dair akademik bağlantı kurulmadı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
