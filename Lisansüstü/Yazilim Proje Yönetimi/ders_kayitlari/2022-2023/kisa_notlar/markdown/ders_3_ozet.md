# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin kapsamı: üç halkanın kesişimi
  - Yazılım proje yönetimi üç alanın kesişiminde durur: yazılım mühendisliği (süreç modelleri, temel kurallar), proje yönetimi teknikleri ve yönetim bilimi.
  - Bu kesişimdeki konular: projeden önce bilgi toplama ve fizibilite, proje planının içeriği ve plan raporu, zaman ve kaynak planlaması (Gantt diyagramı), planların takibi, kalite yönetim planı, üst yönetim ve ekiple ilişkiler, iletişim.
  - Yazılım projelerinin ayırt edici yanı insan kaynağının ve tekniklerin daha fazla öne çıkmasıdır.
- Süreç modeli seçimi üzerine bir anket çalışması
  - Hangi metodolojinin hangi kurumda daha verimli olduğu sorusu yazılım mühendisliğinde genellikle anketlerle araştırılır; sonuçlar yazılım mühendisliğinin temel kurallarıyla ilişkilendirilerek yorumlanır.
  - Seçimi etkileyen etkenler: kurumun yapısı, proje ekibinin yapısı, işin alanı (hangi iş için yazılım geliştirildiği). Anketi yanıtlayanın görevi (proje yöneticisi, analist, yazılım mimarı) de sonucu etkiler.
  - İncelenen çalışmada veriler anonim bir çevrimiçi anketle toplanmış; anket Proje Yönetimi Enstitüsünün (www.pmi.org) web sitesinde, Akademik Araştırma bölümünde yayımlanmış, ayrıca 2000 proje yöneticisine ve ekip üyesine gönderilmiştir. Katılımcılardan yanıtlarını aktif rol aldıkları ve yakın zamanda tamamlanmış bir yazılım projesine dayandırmaları istenmiştir (ekrandan, 00:40:00).
  - Ankette sorulanlar: sanayi kolu, kuruluşun büyüklüğü, proje tipi (yazılım geliştirme, entegrasyon, özelleştirme/customization), proje süresi (1 yıldan kısa, 12-24 ay, 24 aydan uzun), bütçe ve kullanılan metodoloji (çevik, geleneksel, iteratif, hibrit; çeviklerin içinde Scrum, XP, Crystal vb.).
- Üç grup faktör
  - Örgütsel faktörler: sanayi, yıllık gelir ve çalışan sayısı (ekrandan, 00:35:00).
  - Proje faktörleri: bütçe ve kritiklik (projenin başarısının kullanıcı şirket için ne kadar kritik olduğu); süre bütçeyle birlikte değişir.
  - Takım (ekip) faktörleri: ekip sayısı ve ekip boyutu; küçük (<10), orta (11-30), büyük (>30) olarak sınıflandırılmıştır (ekrandan, 00:55:00).
- Çalışmanın bulguları (ekrandan, 00:50:00 ve 00:55:00)
  - Çevik yaklaşımlı projelerin %50,0'ının bütçesi 200.000 dolardan azdır. Yinelemeli (iteratif) ve karma (hibrit) projelerin sırasıyla %70,0 ve %45,8'inin bütçesi 200.000 dolar ile 1 milyon dolar arasındadır. Geleneksel projelerin %44,5'inin bütçesi 1 milyon doları aşar.
  - Küçük ekipler en çok çevik, iteratif ve hibrit yaklaşımlarda görülür (sırasıyla %69,8, %80,0 ve %50,8). Orta boy ekipler en çok geleneksel yaklaşımda görülür (%61,1). Büyük ekipler nadirdir: çevikte %9,3, gelenekselde %16,7.
  - Genel sonuç: daha küçük bütçeli, küçük projeler çevik yaklaşımı; büyük bütçeli büyük projeler yinelemeli ve karma yaklaşımları daha çok kullanmıştır.
- Dört yaklaşımın özellikleri (ekrandan, 01:00:00)
  - Çevik: orta gelir, az çalışan; düşük bütçe, orta-yüksek kritiklik; tek ekip, küçük ekip.
  - Geleneksel: yüksek gelir, çok çalışan; yüksek bütçe, yüksek kritiklik; birden çok ekip, orta boy ekip.
  - İteratif: az çalışan; orta bütçe, orta-yüksek kritiklik; tek ekip, küçük ekip.
  - Hibrit: kurum büyüklüğü önemsiz; orta bütçe, yüksek kritiklik; küçük ekip.
- Türkiye'de çevik yaklaşımın gelişimi (hocanın gözlemi)
  - Çevik kullanımı Türkiye'de 2005 civarında, önce küçük yazılım firmalarında başlamıştır; başlangıçta çoğu zaman yalnız görünür kısmı (günlük toplantı, çevik koç) uygulanmış, süreç tam izlenmemiştir. Gerçek uygulama 2010'dan sonra yerleşmiştir.
  - Son yıllarda kritik yazılım geliştiren kurumlar ve bankalar da çevik ve hibrit süreçleri kendilerine uyarlamaktadır. Ulusal Yazılım Mühendisliği Sempozyumu bu uygulama deneyimlerinin paylaşıldığı önemli bir toplantıdır.
  - Geçiş döneminde kritik projelerde tekrar tekrar kontrol için spiral model ve Rational Unified Process altındaki Unified Process kullanılmıştır.
- Planlama ilkeleri (ekrandan, 01:25:00)
  - Projenin sınırlarını belirleyin: nereye gideceğinizi bilmezseniz kaybolursunuz. Sınır dışı bir istek zaman ve kaynak planını değiştirir.
  - Müşteriyi planlama eylemlerine katın: öncelikleri, sınırları ve zamanlamayı müşteri belirler (zaman mı, kapsam mı, bütçe mi esnetilemez?).
  - Bildiklerinizi kullanarak kestirimde bulunun: bilginin kapsamı, doğruluğu ve belirginliği kestirimin doğruluğunu etkiler.
  - Planın her aşamasına risk değerlendirmesini ekleyin: teknik, mali, kişisel, politik riskler.
  - Gerçekçi olun.
  - Planların ölçeği: ince ayrıntılı planlar kısa vadeli, genel planlar uzun vadeli yapılır; zaman ilerledikçe ayrıntıya inilir. Planın gidişi takip edilir, gerekli düzenlemeler yapılır; kalite güvence eylemleri plana eklenir; değişikliğin nasıl kabul edileceği müşteriyle sözleşmeye bağlanır.
- Proje yönetiminde ölçüm (ekrandan, 01:30:00)
  - Proje ölçümü: yazılımın ölçülmesidir; odak teknik düzey; amaç iç kalite ölçütlerini yüksek tutmak; yöntem ölçüm sonuçlarına göre ekibi iyiye yönlendirmek.
  - Süreç ölçümü: yazılım geliştirme sürecinin ölçülmesidir; odak yönetimsel düzey; amaç dış kalite ölçütleri; yöntem sürecin tüm aşamalarında tutulan istatistiklere göre süreçleri iyileştirmek.
  - Geçmiş projelerden tutulan bilgiler: proje boyutu, süre, çalışan sayısı, harcanan iş gücü (adam-ay).
- Kalite ile ilgili etkenler ve ölçüt gizliliği (ekrandan, 01:35:00)
  - Etkenler: kişiler (yetenek ve isteklilik en önemli etken), ürün (karmaşıklık kaliteyi olumsuz etkiler), teknoloji (araçların ve donanımın kalitesi), çevresel koşullar, müşterinin özellikleri, iş koşulları (iş akışı kuralları, şirket kültürü).
  - Ölçütler bireysel, takım ve proje düzeyinde toplanır; amaç insanları utandırmak, övmek ya da tehdit etmek değildir.
- Süreç ölçütleri
  - Belirli sürede bulunan hata sayısı (teslimden/bakımdan önce ve sonra), hatayı gidermek için harcanan süre.
  - Güvenilirlik ve doğruluk (bulunan hata sayısının proje büyüklüğüne oranı), bakım kolaylığı (bir hatanın giderilme süresi), güvenlik (bulunan açık sayısı). <!-- BELİRSİZ: bu slayt (süreç ölçütleri) karelerde büyük görünmüyor; maddeler altyazıdan alındı. -->
- Risk yönetimi (ekrandan, 01:40:00 ve 01:50:00)
  - Risk ile uğraşma taktikleri: sonradan (reactive), risk gerçekleşince çözmek; önceden (proactive), riskleri gerçekleşmeden önlemeye çalışmak. Derste proaktif yaklaşım işlenir. Önlem seçilirken maliyeti de hesaba katılır.
  - Riskin üç anahtar kavramı: olasılık (risk %100 olasılıkla ortaya çıkacak diye bir şey yoktur), kayıp (risk gerçekleşince istenmeyen sonuçlar doğurur), gelecek (şu an sorun yoktur; risk belirli zaman aralıklarında ya da kilometre taşlarında yeniden değerlendirilir).
  - Proje riskleri: proje planını tehdit eder; gerçekleşirse zamanlama sarkar, maliyet artar (bütçe, zaman, personel riskleri).
  - Teknik riskler: yazılımın kalitesini ve zamanında bitirilmesini etkiler; çözümleme, tasarım, gerçekleme ve bakım aşamalarıyla ilgilidir; "son teknoloji" ürünler yüksek teknik risk taşır.
  - İşletme riskleri: pazar riski (ürüne talep olur mu?), satış riski (pazarlama ekibi ürünü nasıl satacağını biliyor mu?), MIS/MBA konuları.
- Risk tablosu ve risk grafiği (ekrandan, 01:55:00)
  - Tablo sütunları: risk numarası, adı, türü, etkisi, olasılığı. Etki-olasılık grafiğine yerleştirilen riskler arasından izlenecek olanlar seçilir.
  - Etkisi küçük ve olasılığı düşük olanlar izlenmez; diğerleri (etkisi büyük olanlar ve olasılığı yüksek olanlar) için ayrıntılı risk bilgi sayfası hazırlanır.
- Kabul ve kısıtlar
  - Proje başlarken kabuller (ör. her etkinlikte çalışacak yeterli personel var; müşteri tarafı yarı ürünleri değerlendirecek bir kişi ayırmış) ve kısıtlar (ör. bu dönemde yalnız bir sistem analisti var) yazılır. Kabul ve kısıtlar ürünle ve projeyle ilişkili olabilir; plan bunlara göre kurulur.
  - Kısıt baştan bilinen bir eksikliktir; risk ise şu an var olmayan, ileride ortaya çıkabilecek bir sorundur.
- Kaynaklar ve kurumlar
  - Temel kitap: Information Systems Project Management; risk kavramları için Pressman'ın kitabı.
  - PMI (Project Management Institute) ve PMP sertifikası, çevik alanda da sertifika; PMBOK (Project Management Body of Knowledge); Software Engineering Institute ve SWEBOK (Software Engineering Body of Knowledge).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu alandaki makalelerin çoğu anket çalışmasına dayanır
  - Makaleyi okurken projenin hangi sanayide, hangi örgüt yapısında yapıldığına ve anketi kimin yanıtladığına bakılmalıdır. Bu yüzden temel istatistik bilgisi gerekir.
- Model seçimi kuruma, projeye ve ekibe göre yapılır
  - Literatürdeki ön yargılar değil, kurumun, projenin ve ekibin özellikleri belirleyicidir. Küçük ekipte çevik ilk akla gelen cevaptır, ama son yıllarda büyük ve kritik projelerde de çevik ve hibrit kullanım artmıştır.
- Plan değişmez değildir
  - Özellikle çevik süreçlerde plan her aşamada gözden geçirilir; ilk başta çok ince ayrıntıya girilmez.
- Değişiklik isteği kaçınılmazdır
  - Müşteri başta ne istediğini tam bilmez; değişikliklerin nasıl kabul edileceği baştan sözleşmeyle belirlenmelidir.
- Risk önleminin maliyeti
  - Örneğin kritik bir çalışanın ayrılması riskine karşı yedekli çalışmak bir maliyettir; önlemin maliyeti riskin etkisiyle kıyaslanarak karar verilir.
- Pazarlama teknik iş kadar önemlidir
  - Teknik bakışla "en iyi yazılımı yaparsak en iyi firma oluruz" düşünülür, ama potansiyel müşteriler, ürünün uyarlanması ve tanıtım da başarı için teknik işler kadar önemlidir.

## Kısa Tekrar Notları

- Yazılım proje yönetimi = yazılım mühendisliği + proje yönetimi teknikleri + yönetim bilimi.
- Model seçimini etkileyen üç faktör grubu: örgütsel (sanayi, yıllık gelir, çalışan sayısı), proje (bütçe, kritiklik, süre), takım (ekip sayısı, ekip boyutu).
- Çevik: küçük bütçe, küçük ekip; geleneksel: yüksek bütçe, yüksek kritiklik, birden çok ve orta boy ekip; hibrit: kurum büyüklüğü önemsiz, yüksek kritiklik.
- Planlama ilkeleri: sınırları belirle, müşteriyi kat, bildiklerinle kestir, her aşamaya risk ekle, gerçekçi ol, kısa vadede ayrıntıya in, planı takip et, kaliteyi plana ekle, değişikliği sözleşmeye bağla, ölç.
- Proje ölçümü: teknik düzey, iç kalite. Süreç ölçümü: yönetimsel düzey, dış kalite.
- Ölçütler kişiyi utandırmak, övmek ya da tehdit etmek için kullanılmaz.
- Risk = olasılık + kayıp + gelecek. Reaktif ve proaktif taktik.
- Risk türleri: proje, teknik, işletme (pazar, satış).
- Risk tablosu: no, ad, tür, etki, olasılık. Küçük etki ve düşük olasılıklı riskler izlenmez.
- Kısıt bilinen eksikliktir; risk ileride ortaya çıkabilecek sorundur.
- Takip edilecek kaynaklar: PMI, PMBOK, SWEBOK.

## Detaylı Açıklamalar

- Anket çalışmasının mantığı
  - Bir kurumun hangi süreç modelini seçmesi gerektiği sorusunun genel bir cevabı yoktur. Araştırmacılar bu yüzden sahadan veri toplar: farklı sanayi kollarından, farklı büyüklükteki kurumlardan, farklı bütçe ve sürelerdeki projelerden yanıt alınır ve hangi koşulda hangi yaklaşımın seçildiği çapraz tablolarla incelenir. Derste gösterilen çalışmada anket PMI üzerinden proje yöneticileri ve ekip üyelerine ulaştırılmış, yanıtlar katılımcının yakın zamanda tamamladığı tek bir projeye dayandırılmıştır. Böylece "genel görüş" yerine somut bir projenin verisi toplanmıştır. Katılımcılar arasında bilgi teknolojisi alanında çalışanlar önemli bir ağırlık taşır.
  - Sonuçlarda klasik model seçilse bile çoğu projede evrimsel ve aşamalı (artımlı) yaklaşımların kullanıldığı görülür: ürün parçalar halinde, eklenerek kullanıma sunulur ve bu yüzden yazılım modüler geliştirilir.
- Ekip boyutu bulguları (ekrandan, 00:55:00)
  - Slayttaki ikinci grafik her yaklaşımdaki projelerin ekip boyutuna göre dağılımını gösterir. Değerler aşağıdadır; her satırın toplamı %100'dür (python ile kontrol edildi).

    | Yaklaşım | Küçük | Orta | Büyük |
    |---|---|---|---|
    | Çevik | 69,8 | 20,9 | 9,3 |
    | Geleneksel | 22,2 | 61,1 | 16,7 |
    | İteratif | 80,0 | 10,0 | 10,0 |
    | Hibrit | 50,8 | 33,9 | 15,3 |

  - Birinci grafik ekip sayısına göre dağılımdır (1 ekip / 2-3 ekip / 4 ve daha fazla ekip): çevik 48,9 / 39,5 / 11,6; geleneksel 11,1 / 33,3 / 55,6; iteratif 50,0 / 30,0 / 20,0; hibrit 25,4 / 33,9 / 40,7 (ekrandan, 00:55:00). Geleneksel projelerin yarıdan fazlası dört ve daha fazla ekiple yürütülür.
  - Ders sonrası not: Slaytta "orta öğretim ekipleri" yazıyor; bu, kaynaktaki "medium teams" ifadesinin hatalı çevirisidir, doğrusu "orta boy ekipler"dir. Bütçe bulgularının yazdığı slaytta da aynı ekip grafikleri görünmektedir; bütçe grafiği (Şekil 7a) ekranda yoktur.
- Planlama ve değişiklik yönetimi
  - Müşterinin önceliği planın biçimini belirler: teslim tarihi kesinse kapsam ya da kaynak esnetilir, bütçe kesinse kapsam ya da süre esnetilir. Kestirim yapılırken daha önce arşivlenmiş proje bilgileri kullanılır. Spiral modelde olduğu gibi her aşamada, bir prototip hazırlanırken bile, riskler konuşulur. Müşteri işini zamanla daha iyi anlar, geliştirici de iş alanının kurallarını zamanla öğrenir; bu yüzden değişiklik istekleri kaçınılmazdır ve değişiklik kuralları baştan sözleşmede yer almalıdır.
- Risk değerlendirme örnekleri
  - Projede yeni bir CASE aracı kullanılması teknik bir risktir. Ekip bu araç için eğitim almışsa olasılık düşer. Gerçekleşirse modellemeler hatalı olabilir; bu kaybın büyüklüğünü gösterir. Gelecek boyutunda risk belirli aralıklarla (ör. iki ayda bir) ya da kilometre taşlarında yeniden değerlendirilir.
  - Personel riskleri yalnız kilit kişinin ayrılması değildir; yanlış görevlendirme ve çalışanın bildiğini söylediği işi bilmemesi de personel riskidir. Zaman riski, planda sürenin az gösterilmesinden ya da rekabet nedeniyle müşterinin işi daha erken istemesinden doğabilir.
  - Teknik riskler aşamalara göre örneklenir: analizde UML diyagramlarında sorun, tasarımda ER diyagramının hatalı hazırlanması, kodlamada yanlış dil seçimi ya da dilin etkin kullanılamaması, yeni teknolojiye hakim olunmaması, dokümantasyon eksikliği ve teknolojinin kalıcılığı.
  - İşletme riskleri genel amaçlı paket yazılımlarda belirginleşir: hedef sektör iyi incelendi mi, fiyat doğru belirlendi mi, ürün bütün kurumlara uyar mı (ör. hukuk şirketleri için hazırlanan paketler)?
  - Sel, deprem gibi felaketler olasılığı düşük ama etkisi büyük riskler sınıfındadır ve izlenmesi gereken riskler arasındadır.
- Sektörde süreç modelleri (derste bir öğrencinin paylaşımı)
  - Sektörde neredeyse herkesin çevik çalıştığı, şelale modelinin pratikte görülmediği, yalnız dokümantasyon tarafında şelaleye benzeyen süreçler kaldığı söylendi. Büyük ve kritik projelerde dokümantasyonun ayrı bir maliyet kalemi olarak hesaplandığı, bu işi iş analistlerinin yaptığı, test güdümlü geliştirmenin maliyetinin de ayrıca hesaplandığı belirtildi. Altta bir platform kullanılıyorsa temel dokümantasyon oradan üretilebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
