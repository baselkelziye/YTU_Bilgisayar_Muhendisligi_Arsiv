# Ders 12 Çalışma Özeti

## Genel Konular

- Bu ders öğrencilerin makale sunumlarına ayrılmıştır. On sunum yapılmış, hoca her sunumu yazılım kalitesi ve test bakış açısıyla yorumlamıştır.
- GitHub depoları arasında yazılım benzerliğinin otomatik değerlendirilmesi
  - Açık kaynak depolardan yeniden kullanım maliyeti düşürür. Mevcut bir projeden yeniden kullanılan kodun, sıfırdan yazılmış kodun ilk sürümlerinden daha kaliteli olduğu söylenir.
  - Düşük seviyeli benzerlik kaynak koda (değişken adları, fonksiyon adları, API çağrıları) dayanır. Yüksek seviyeli benzerlik meta verilere (README dosyaları, yıldızlama etkinlikleri) dayanır.
  - MudaBlue (2004): kaynak koddaki tanımlayıcıları çıkarır, yorum gibi etkisiz öğeleri siler, Latent Semantic Analysis (LSA) uygular. Yazılımı bir belge, her tanımlayıcıyı bir kelime gibi görür.
  - CLAN (2012, McMillan, Grechanik, Poshyvanyk): API çağrılarını anlamsal bağlantı (semantic anchor) olarak kullanır. Kaynak kodu terim-belge matrisi (TDM) olarak temsil eder: her sütun bir belge, her satır bir terim, her hücre terimin o belgede görünme frekansıdır (ekrandan, 00:10:00). Yalnız API çağrılarını kullandığı için MudaBlue'dan daha yüksek hassasiyet elde ettiği iddia edilir.
  - RepoPal (2017): yalnız meta verilere bakar. README benzerliği, yıldız tabanlı benzerlik (iki kullanıcının yıldızladığı depo kümelerinin Jaccard indeksi) ve zaman tabanlı benzerlik çarpılarak toplam benzerlik bulunur.
  - CrossSim: açık kaynak ekosistemini graf olarak temsil eden hibrit bir yaklaşımdır. Hem düşük hem yüksek seviyeli benzerliği tek modelde kullanır.
- Çevik yaklaşımla güvenlik açısından kritik sistemlerde kalite güvencesi
  - Kritik sistemler bileşen sayısı ve etkileşimler arttıkça karmaşıklaşır. Güvenlik, bileşenlerden ve aralarındaki etkileşimlerden ortaya çıkan bir özelliktir. Karmaşıklığın ana kaynağı yazılımdır.
  - Sunumda verilen örnek: 2011'de ABD'deki tıbbi cihaz hatalarının %24'ü yalnız yazılım hatalarına bağlanmıştır.
  - Cynefin çerçevesi beş durum ayırır: basit, komplike, karmaşık, kaotik ve düzensizlik. Komplike durumda neden-sonuç ilişkisi sabittir ama uzman analizi gerekir; önerilen model "algıla, analiz et, yanıtla"dır. Karmaşık durumda neden-sonuç önceden açıklanamaz; önerilen model "dene (probe), algıla (sense), yanıtla (respond)" öğrenme yaklaşımıdır (ekrandan, 00:20:00).
  - Yazılım tasarımı karmaşık bir iştir; artımlı geliştirme ve "dene-algıla-yanıtla" uygundur. Tasarımı belli bir yazılımın üretimi komplikedir ama karmaşık değildir; "algıla-analiz et-yanıtla" uygundur.
  - Çevik geliştirme doğrulama önyargısına (confirmation bias) açıktır. Bağımsız denetim için gereksinimlerin, verilen kararların ve gerekçelerinin belgelenmesi gerekir.
- Otomatik yazılım onarımı (Automatic Software Repair)
  - Program hatalarıyla otomatik başa çıkmanın iki yaklaşımı vardır: yazılım iyileştirme (healing) ve yazılım onarımı (repairing) (ekrandan, 00:30:00).
  - İyileştirme süreci hata algılandıktan sonra iyileştirme ve doğrulama adımlarından oluşur. Programın hatalı kodunu değiştirmez, çalışmayı kurtarır. Onarım süreci yerelleştirme (localization), yama üretimi (patch/fix) ve doğrulama adımlarından oluşur.
  - Onarım teknikleri genel ya da hataya özgü (fault-specific) tasarlanabilir. Genel teknikler herhangi bir hata sınıfını onarabilir; hataya özgü tekniklerin kapsamı dar, verimi yüksektir (ekrandan, 00:35:00).
  - Yama üretiminde iki yaklaşım vardır: üret-ve-doğrula (generate and validate) ve anlam güdümlü (semantic-driven). Anlam güdümlü yaklaşımın adımları davranış analizi, problem üretimi ve yama üretimidir (ekrandan, 00:40:00).
- Makine öğrenmesiyle yazılım kalite tahmini
  - Bu çalışmalarda öne çıkan kalite faktörleri güvenilirlik ve sürdürülebilirliktir. Güvenilirlik hata tahminiyle, sürdürülebilirlik teslimden sonraki değişiklik eforuyla ölçülür.
  - 13 metrik seçilmiştir, çoğu nesneye yönelik (CK) metriklerdir: WMC, LOC, CBO, DIT, NOC, LCOM, RFC, IC, CBM, MPC, DAC, SIZE1, SIZE2 (ekrandan, 00:50:00).
  - Veri: PROMISE hata tahmini kümeleri ve UIMS, QUES sürdürülebilirlik kümeleri (ekrandan, 00:55:00). Eğitimde hata oranı yüksek olan POI kümesi kullanılmıştır.
  - Ön işleme: eksik değer doldurma (imputation) ve normalizasyon. Sınıflar dengesiz olduğu için doğruluk (accuracy) yerine precision, recall ve AUC kullanılmış, 10 katlı çapraz doğrulama yapılmıştır.
  - Yöntemler: karar ağacı, rastgele orman, Bayes ağı, kural tabanlı sınıflandırma, KNN, genetik programlama, SVM, yapay sinir ağı, AdaBoost, bagging.
  - Sonuç: hata tahmininde en yüksek AUC Bayes ağında (0.849), sürdürülebilirlik tahmininde rastgele ormandadır (0.814) (ekrandan, 01:05:00). Genel değerlendirmede rastgele orman ve bagging en güvenilir yöntemler bulunmuştur.
- Kötü koku, yeniden düzenleme ve kullanıcı incelemeleri
  - Kötü koku, tasarım ilkelerinin ihlal edildiğini gösteren ve kaliteyi olumsuz etkileyen kod yapılarıdır. Farklı dedektörler farklı eşikler kullandığı için sonuçları uyuşmaz.
  - Kokular sürdürülebilirliği ve anlaşılabilirliği düşürür.
  - Yeniden düzenleme (refactoring), dış davranışı değiştirmeden iç yapıyı iyileştirmektir. Kod, tasarım ve gereksinim seviyesinde yapılabilir. Değerlendirmesi metrik tabanlı ya da uzman tabanlı olur. İncelenen çalışmaya göre en başarılı araçlar arama tabanlı algoritmalardır.
  - Mobil uygulama incelemeleri hata bildirimi, özellik isteği, bilgi verme, bilgi arama gibi sınıflara ayrılır. Özellik seçimi için bilgi kazancı ve ki-kare kullanılır.
- Test edilemeyen sistemler ve test kâhini (oracle) problemi
  - Test kâhini, beklenen çıktıyı belirleyip gerçek çıktıyla karşılaştıran mekanizmadır. Kâhin uygulanamıyorsa sistem "test edilemeyen sistem" olur.
  - Beş teknik incelenmiştir: N-versiyon testi, metamorfik test, bildirimler (assertions), makine öğrenmesi kâhinleri ve istatistiksel hipotez testi.
  - N-versiyon testinde test edilen sistem bir referans uygulamayla (RI) karşılaştırılır. İki sistem aynı hatayı yaparsa ilişkili başarısızlık oluşur.
  - Metamorfik testte kaynak ve takip test senaryoları arasında beklenen bir ilişki (metamorfik ilişki, MR) tanımlanır.
  - Karşılaştırma tablosuna göre N-versiyon, metamorfik test, ML kâhinleri ve istatistiksel hipotez testi ilişkili başarısızlık yaşayabilir. Bildirimler için bu bilinmiyor (ekrandan, 01:45:00).
- Modern yazılım sistemlerinde test senaryosu önceliklendirme (TCP)
  - Test senaryoları, en çok faydayı en önce sağlayacak sırayla çalıştırılmak üzere sıralanır. Genel ya da sürüme özgü önceliklendirme yapılabilir.
  - Statik teknikler: çağrı grafı, string tabanlı, konu (topic) tabanlı. Dinamik teknikler: açgözlü (total, additional), uyarlanır rastgele test (ART), arama tabanlı (ekrandan, 01:50:00).
  - Ölçütler APFD ve maliyeti de hesaba katan APFDc'dir. Değerlendirmede mutasyon analizi kullanılmıştır.
  - 58 GitHub projesi üzerinde metot seviyesindeki önceliklendirme, sınıf seviyesindekinden daha iyi sonuç vermiştir. Statik teknikler dinamiklerden biraz daha iyi bulunmuştur. Çağrı tabanlı teknikler daha ucuzdur (ekrandan, 02:00:00).
- Dağıtık sürekli çevik testte geliştirici ile test uzmanı iletişimi
  - Çalışmada iki dağıtık ekip 18 ay boyunca eylem araştırmasıyla izlenmiş, farklı rollerle görüşme yapılmıştır (ekrandan, 02:10:00).
- Açık kaynaklı yazılımda kalite güvencesi
  - Soğan modelinde içten dışa dört katman vardır: çekirdek geliştiriciler, katkıda bulunan geliştiriciler, hata raportörleri ve kullanıcılar.
  - Kapalı kaynağa göre belgelenmiş bir yöntem, resmi test ve resmi risk değerlendirmesi çoğu zaman yoktur.
  - Açık kaynakta kalite çerçevesi üç süreçtir: hata tespiti, hata doğrulaması ve çözüm doğrulaması (eş incelemeyle).
- Model tabanlı ve risk tabanlı testin karşılaştırılması
  - Model tabanlı test (MBT) adımları: gereksinim yönetimi, modelleme, üretim, somutlaştırma, yürütme (ekrandan, 02:35:00).
  - Risk seviyesi olasılık ve etkiyle belirlenir. Risk tabanlı test (RBT) adımları: gereksinim yönetimi, risk belirleme, analiz ve değerlendirme, risk azaltma, yürütme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sunum konusunun dersle ilişkisi
  - Hoca, depo benzerliği konusunun yazılım kalitesinden çok yöntemlerle ilgili olduğunu söylemiş, sunumu kaliteye ağırlık vererek özetlemesini istemiştir. Konunun Software Quality dergisinden alındığını öğrenince itirazını geri almıştır.
- Kaynak dergiler
  - IEEE Transactions on Software Engineering'deki makaleler karmaşık konuları derinlemesine işler; özetlemesi zordur.
- Yazılım mühendisliğinde yapay zekâ
  - Yazılım kalitesi ve makine öğrenmesi üzerine çok sayıda çalışma vardır. Yazılım mühendisliğinde akıllı sistemler, yapay zekâ uygulamaları, makine öğrenmesi ve yazılım mühendisliği adlı ayrı konferanslar düzenlenir.
- Healing (iyileştirme) yaklaşımının özü
  - Hoca healing işlemlerini "çalışma sırasında hatayı özümseyip hataya rağmen çalışmayı sürdüren işlemler" diye özetlemiştir. Sunucu bunu hatayı yalnız örten bir yara bandına benzetmiştir.

## Kısa Tekrar Notları

- Düşük seviyeli benzerlik koda, yüksek seviyeli benzerlik meta verilere dayanır. CLAN API çağrılarını ve TDM ile LSA'yı kullanır. RepoPal yıldız ve README verisine bakar.
- Cynefin: komplike durumda "algıla-analiz et-yanıtla", karmaşık durumda "dene-algıla-yanıtla" kullanılır. Yazılım tasarımı karmaşık, yazılım üretimi komplikedir.
- Healing çalışmayı kurtarır, programı düzeltmez. Repair hatanın yerini bulur, yama üretir ve doğrular.
- Dengesiz sınıflarda accuracy yanıltıcıdır; precision, recall ve AUC kullanılır.
- Hata tahmininde en iyi AUC Bayes ağında (0.849), sürdürülebilirlik tahmininde rastgele ormandadır (0.814).
- Yeniden düzenleme dış davranışı değiştirmeden iç yapıyı iyileştirir. Gerekliliğini kod kokuları gösterir.
- Kâhin problemi için beş teknik vardır: N-versiyon, metamorfik test, bildirimler, ML kâhinleri, istatistiksel hipotez testi.
- TCP'de ölçütler APFD ve APFDc'dir. Metot seviyesi sınıf seviyesinden daha iyidir.
- Açık kaynakta kalite çerçevesi: hata tespiti, hata doğrulaması, çözüm doğrulaması.
- MBT gereksinimden model ve test türetir. RBT testleri risk (olasılık × etki) sırasına koyar.

## Detaylı Açıklamalar

- **Yazılım benzerliği ve öneri sistemleri.** Benzerlik kavramı, öneri sistemlerindeki içerik tabanlı ve işbirlikçi filtrelemenin temelidir. Sunucu bunu bir yemek sipariş uygulamasıyla anlatmıştır. Yemeklerin içeriği biliniyorsa kullanıcıya benzer yemekler önerilir; buna içerik tabanlı filtreleme denir. Yemekler hakkında bilgi yoksa benzer siparişler veren kullanıcılar bulunur ve onların siparişleri önerilir; buna işbirlikçi filtreleme denir. Yazılımda da depo benzerliği, geliştiriciye hangi kütüphaneyi kullanacağı gibi öneriler sunmak için kullanılır. Kesin bir "kopyalanmıştır" tanımı yapmak zordur, çünkü benzerliğin türü kullanılan yönteme bağlıdır.
- **Cynefin ve çevik geliştirme.** Çevik yöntemler sistemin küçük bir parçasını üretip değerlendirerek problemi keşfeder. Bu yüzden karmaşık problemlerde tasarım için uygundur. Bedeli, plan tabanlı geliştirmenin titizliğinden ödün vermektir. Ekip yazılımın neyi amaçladığını bildiği için testlerde kendi beklentisini doğrulayan kanıt arama eğilimindedir. Bu ihmal değil, doğrulama önyargısıdır. Çalışmanın sonucu: karmaşık sistem tasarımında "dene-algıla-yanıtla", tasarımı belli sistemin üretiminde "algıla-analiz et-yanıtla" uygundur.
- **Kalite tahmini akışı.** ISO standardına dayalı akışta önce kaliteyi belirleyen ölçümler seçilir. Sonra bu ölçümler bir fonksiyon ya da algoritmayla birleştirilip tahmin yapılır. İncelenen çalışmada bu analiz adımındaki fonksiyonlar makine öğrenmesi modelleridir. Sunumda geç yakalanan hataların maliyeti vurgulanmıştır: yazılım hatalarının yıllık maliyeti yaklaşık 59 milyar dolar olarak tahmin edilmiştir. Kalitenin erken tahmini hem geliştiriciye kolaylık hem kullanıcıya güven sağlar.
- **Test kâhini teknikleri.** N-versiyon testinde referans uygulamayı geliştirmek zaman ve çaba ister. Bu yükü azaltmak için üç öneri vardır: performanstan çok hızlı geliştirilecek bir RI tasarlamak, benzer sistemleri ya da önceki sürümleri RI olarak seçmek, çevrimiçi kod havuzlarından bileşen hasadıyla RI temin etmek (ekrandan, 01:30:00). Metamorfik testte birden çok MR kullanmak etkinliği artırır. MR'ler spesifikasyondan türetilmişse spesifikasyon hataları teste de yayılabilir ve bulunamaz (ekrandan, 01:35:00). ML kâhinlerinde başarılı ve başarısız senaryoların dengesi ile veri setinin boyutu etkinliği belirler (ekrandan, 01:40:00). İstatistiksel hipotez testi deterministik olmayan sistemlerde kullanılır. Önem seviyesi yükseldikçe yanlış pozitifler artar, yanlış negatifler azalır.
- **Açık kaynakta hata yaşam döngüsü.** Hata bulan kullanıcı ya hatayı görmezden gelir, ya hata izleme sistemine form doldurur, ya da e-posta listesi veya forumla bildirir. Doğrulamada geliştiriciler raporu okur, kodu inceler ve hatayı açık, devam ediyor, yinelenen ya da geçersiz olarak işaretler. Çözüm geliştiren kişi önce kendi kodunu inceler, sonra topluluğa gönderir. Diğer geliştiriciler eş inceleme yapar; çözüm uygunsa onaylanır, değilse hata yeniden açılır.
- **MBT ve RBT'nin sınırları.** MBT test süresini ve maliyetini azaltır, gereksinimlerle izlenebilirlik sağlar. Ama güncel olmayan gereksinimleri yönetemez, başarısız testlerin analizi zordur, sistemin bazı kısımlarını modellemek güçtür (ekrandan, 02:45:00). RBT yüksek riskli hataları önce bulur. Ancak gereksinim ile test arasındaki izlenebilirliği yönetmek zordur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
