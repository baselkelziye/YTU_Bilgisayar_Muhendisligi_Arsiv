# Ders 7 Çalışma Özeti

## Genel Konular

- Yazılım ölçümünün tekrarı
  - Daha önce görülen ölçütler hatırlatıldı: Halstead ölçütü (işleç ve işlenen sayılarından program gücü), McCabe döngüsel karmaşıklığı (akış grafındaki temel yol sayısı), büyüklük ölçütü (kod satırı, KLOC), fonksiyon noktası (Function Point) ve yazılım güvenirliği.
  - McCabe ölçüsü en yüksek modül büyüklüğünü saptamakta da kullanılır; çok sayıda projeden derlenen bilgiye göre bir modülde en çok $V(G) = 10$ olmalıdır, bu sayı aşılınca modülün sınanması büyük ölçüde zorlaşır (ekrandan, 00:25:00).
  - Güvenirlik modelleri istatistiksel verilere dayanır; bir yazılım birden fazla modele göre test edilip sonuçlar karşılaştırılmalıdır (ekrandan, 00:30:00).
- Yazılım kalite ölçütleri ve kalite modelleri
  - Nicel kalite ölçütleri farklı kişilerce farklı biçimde öbeklenir: ISO 9126, McCall ve arkadaşları, McConnell (ekrandan, 00:35:00).
  - McConnell kalite ölçütlerini dış ve iç kalite ölçütleri olarak iki gruba ayırır.
  - Bu modeller aslında çok farklı şeyleri ölçmez; farkları sınıflandırma biçimindedir.
- Ölçme, ölçüt ve ölçüm kavramları
  - Ölçme (measuring), ölçüt (metric) ve ölçüm (measurement) tanımları ve aralarındaki fark (ekrandan, 00:45:00).
- Ölçme ilkeleri
  - Ölçme eyleminin beş adımı: tanımlama, toplama, hesaplama, yorumlama, geri besleme (ekrandan, 00:50:00).
- Nesneye yönelik ölçütler
  - CK (Chidamber-Kemerer) ölçütlerinin tekrarı, WMC örneği ve eleştirileri (ekrandan, 00:55:00).
- Test yönetimi
  - Test metodolojisi, test planı, test tasarımı ve testin gerçekleştirilmesi; test spesifikasyonu belgesi ve içeriği (ekrandan, 01:25:00).
  - Test spesifikasyonu geliştirme adımları: yaz, incele, incelemeye dayalı düzelt, baseline (ekrandan, 01:30:00).
  - Test planı içeriği, test senaryosu belgesi, test çalışma ekibi yapısı (ekrandan, 01:35:00), yaşam döngüsü içinde test etkinlikleri.
- Yazılım risk yönetimi
  - Reaktif ve proaktif yaklaşım; riskin tanımı (olasılık, kayıp, gelecek); risk çeşitleri; risk tablosu ve risk takibi (ekrandan, 01:40:00 ve 01:50:00).
- Yazılım konfigürasyon yönetimi
  - Yazılımın elemanları (program, belge, veri yapısı), konfigürasyon maddesi (SCI), konfigürasyon tanımı, değişiklik kontrolü, denetim ve raporlama; ilgili standartlar.
  - Sürüm yönetimi (release management) ile ilişkisi.
- Yazılım bakımı
  - Bakım maliyetini azaltmanın yolları ve bakım yapılabilirliği ölçen özellikler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ölçemediğimiz bir ilerlemeyi yönetemeyiz
  - Yazılım; ne kadar iyi bir ürün çıkardığımızı, ne kadar zaman ve para harcadığımızı, ne büyüklükte ve ne kadar karmaşık bir iş yaptığımızı anlamak için ölçülür.
- Ölçüt ile ölçüm sonucu farklı şeylerdir
  - KLOC ya da fonksiyon noktası ölçüttür (birimdir); "8000 satır, yani 8 KLOC" gibi bir değer ölçüm sonucudur.
- Ölçmede geri besleme önemlidir
  - Örneğin modüllerin çoğunda McCabe değeri 10'un üzerine çıkmışsa ekibe modülleri bölüp karmaşıklığı azaltmaları önerilir.
- Ölçütler, yazılım mühendisliğinde ilk akademik araştırmaların yapıldığı konudur
  - Sayma ve hesaplamaya dayandığı için mühendislik çalışmalarına yakındır; ölçüm sonuçlarının maliyet tahmininde yapay sinir ağlarıyla kullanılması, test sayısı ve hata sayısı gibi güvenirlik konuları da çok çalışılmaktadır.
- Testi bağımsız bir ekip yapmalıdır
  - Sınayan kişiler yazılımı tasarlayan ve oluşturan gruptan olmamalıdır; sektörde birçok kurumda ayrı test ekibi vardır.
- Riskin önemi olasılık ile etkinin çarpımıdır
  - Yalnız etkiye bakılmaz; önemi yüksek ve orta olan riskler takibe alınır, düşükler listeden atılır.
  - Her önlemin bir maliyeti vardır; önlem bu maliyet hesaplanarak seçilir.
- Yazılım yalnız program kodu değildir
  - Program kodu, veri tabanı ve belgeler (gereksinim, tasarım, test spesifikasyonu, kullanıcı el kitabı) birlikte yazılımı oluşturur.

## Kısa Tekrar Notları

- Halstead: işleç ve işlenen sayılarından program gücü hesaplanır.
- McCabe: akış grafı, temel yol sayısı; her temel yol için bir test durumu gerekir; modül başına en çok $V(G) = 10$.
- Kod satırı ölçütü basittir ama tartışmalıdır; diller arası fark dönüşüm tablolarıyla giderilir.
- Fonksiyon noktası: girdi, çıktı, sorgu ve dosya sayılarından dolaylı ölçüm; ticari yazılımlardan doğmuştur, gerçek zamanlı yazılımlara uyarlama çalışmaları vardır.
- Güvenirlik: MTBF (hatalar arası ortalama süre), toplam hata sayısı, istatistiksel modeller.
- ISO 9126, McCall ve McConnell aynı kalite özelliklerini farklı sınıflandırır.
- McCall: üç bakış açısı (kullanma, değiştirme/bakım, taşınma) ve ağırlık katsayılarıyla metriklerden kalite faktörü.
- McConnell dış ölçütleri: doğruluk, etkinlik, güvenirlik, güvenlik, bütünlük, uyarlanabilirlik, hassaslık, sağlamlık, kullanılabilirlik.
- McConnell iç ölçütleri: yeniden kullanılabilirlik, bakım kolaylığı, esneklik, taşınabilirlik, okunabilirlik, anlaşılabilirlik, sınanabilirlik.
- Ölçme: bir özelliği sayısal ya da derecelendirilmiş veriye çevirmek. Ölçüt: ölçme biçimi (santigrat, Fahrenhayt; KLOC). Ölçüm: ölçme eyleminin sonucu.
- Ölçme adımları: tanımlama, toplama, hesaplama, yorumlama, geri besleme. Doğrudan ölçmede hesaplama adımı atlanabilir.
- CK, WMC: çok metotlu sınıf çok sorumluluk yüklenmiştir, bölünmesi uygun olabilir; uygulamaya özeldir, yeniden kullanılabilirliği düşüktür.
- Test spesifikasyonu: test planları, test senaryoları, test işlemleri, gerçek test sonuçları, referanslar, ekler.
- Test spesifikasyonu konfigürasyonun bir parçasıdır: yaz, incele, düzelt, baseline.
- Test senaryosu belgesi: ad/kimlik, yazar/tarih, ilgili gereksinim ya da test amacı, ön koşul ve varsayımlar, girdiler, adımlar, beklenen sonuçlar.
- Optimum test miktarı: kaçırılan hata sayısı ile test maliyetinin dengelendiği nokta; her projede farklıdır.
- Risk: olasılık (%100 değil), kayıp, gelecek. Çeşitler: proje, teknik, iş riskleri.
- Risk tablosu: ID, ad, çeşit, olasılık, etki; düşük olasılıklı ve etkili olanlar atılır; kalanlar için risk bilgi sayfası ve önlem.
- Konfigürasyon yönetimi: tanım, değişiklik kontrolü, denetim, raporlama. Standartlar: IEEE 828, IEEE 1042, ISO 9004 Kısım 6.
- Bakım ve onarıma elverişlilik: sınama kolaylığı, basitlik, değiştirilebilirlik, taşınabilirlik gibi özelliklerle ölçülür.

## Detaylı Açıklamalar

Ders, önceki haftalarda görülen yazılım ölçümü konusunun toparlanmasıyla başladı. Halstead ölçütü programdaki işleç ve işlenen sayılarından bir program gücü hesaplar. McCabe döngüsel karmaşıklığında her kontrol deyimi bir düğüm, aralarındaki akış bir kenar olur; akış grafından düğüm ve kenar sayılarıyla ya da kapalı bölgeler sayılarak modüldeki temel yol sayısı bulunur. Her temel yolun sınanması için ayrı bir test verisi, yani test durumu gerekir. Yazılıma dışarıdan bakıldığında bu yollar farklı senaryolara karşılık gelir ve kara kutu testinde bu senaryolara göre değer verilir. Slaytta McCabe ölçüsünün en yüksek modül büyüklüğünü saptamakta da kullanıldığı, çok sayıda projeden derlenen bilgilere göre modül büyüklüğünün en çok $V(G) = 10$ olması gerektiği ve bu sayı aşılınca modülün sınanmasının büyük ölçüde zorlaştığı yazıyordu (ekrandan, 00:25:00).

Büyüklük ölçütü en basit haliyle satır ya da komut sayısıdır. Bu ölçütün haklı eleştirileri vardır: daha az komutla yazılmış bir program daha çok düşünce emeği içerebilir. Programlama dilleri arasındaki fark ise dönüşüm tablolarıyla giderilmiştir. Fonksiyon noktası dolaylı bir ölçümdür: dosya, girdi, çıktı ve sorgu sayıları sayılıp birleştirilir. Ticari yazılımlardan doğmuştur; Function Point Users Group yöntemi yeni teknolojilere uyarlamak için çalışmaktadır ve gerçek zamanlı uygulamalar için de iyileştirme çabaları olmuştur. Güvenirlik ölçümünde ise yazılımın ne kadar süredir hatasız çalıştığı, toplam hata sayısı gibi değerlerden istatistiksel modeller kurulur. Slayta göre bir yazılım birden fazla modele göre test edilip sonuçlar karşılaştırılmalı; model değerlendirilirken modele göre yazılımın ne kadar geçerli olduğu, ölçümün ne kadar kolay olduğu, modelin yazılımın ne kadarına ihtiyaç duyduğu, kullanımının kolay ve anlaşılır olup olmadığı ve dış etkenlerden etkilenip etkilenmediği sorulmalıdır (ekrandan, 00:30:00).

Kalite ölçütleri kısmında üç yaklaşım karşılaştırıldı (ekrandan, 00:35:00). ISO 9126 işlevsellik (uygunluk, doğruluk, güvenlik), güvenilirlik (olgunluk, hata bağışıklığı), kullanılabilirlik, verimlilik, bakım kolaylığı ve taşınabilirlik başlıklarını sayar. McCall ve arkadaşları ölçütleri işlevsel, değiştirilme ve taşınma ölçütleri olarak üç bakış açısıyla gruplar ve metrikleri ağırlık katsayılarıyla çarpıp toplayarak kalite faktörünü hesaplayan daha kapsamlı bir model kurar. McConnell ise yalnız iki grup ayırır. Dış kalite ölçütleri yazılımı kullananları ilgilendirir: doğruluk (hata içermemesi, gereksinimlerde belirtildiği gibi çalışması), etkinlik (bellek ve işlemci gibi kaynakların en az kullanımı), güvenirlik (her koşulda istenildiği gibi çalışma, MTBF'nin yüksek olması), güvenlik (izinsiz ve yetkisiz işlemlerin mümkün olmaması), bütünlük (veriler ve işlemler arasındaki tutarlılık), uyarlanabilirlik, hassaslık, sağlamlık (aykırı girişlere ve güç ortamlara karşı çalışmayı sürdürme) ve kullanılabilirlik (ekrandan, 01:10:00). İç kalite ölçütleri yazılımı geliştirenleri ilgilendirir: yeniden kullanılabilirlik, bakım kolaylığı, esneklik, taşınabilirlik, okunabilirlik (yalnız kod düzeyinde), anlaşılabilirlik (sistem, bileşen ve kod düzeyinde) ve sınanabilirlik (ekrandan, 00:40:00). Slaytta da belirtildiği gibi bu ölçütler örtüşebilir; örneğin sınanabilirlik okunabilirlik, anlaşılabilirlik ve bakım yapılabilirlikle iç içedir.

Ardından temel kavramlar tanımlandı (ekrandan, 00:45:00). Ölçme, somut ya da soyut bir varlığın bir özelliğini sayısal ya da derecelendirilmiş bir veri olarak ifade etmektir ("ilk ara sınav çok zordu" derecelendirilmiş bir ifadedir). Ölçüt, bu özelliği ölçme biçimidir; sıcaklık için santigrat ya da Fahrenhayt, yazılım büyüklüğü için KLOC ya da fonksiyon noktası gibi. Ölçüm ise belli bir ölçüte göre yapılan ölçme eyleminin sonucudur; satırlar sayılıp 8000 satır bulunduğunda sonuç 8 KLOC'tur. Ölçme ilkelerine göre bu eylem beş adımdan oluşur (ekrandan, 00:50:00): tanımlama (yazılımın türüne ve kullanılan yaklaşıma uygun ölçütlerin seçilmesi), toplama (ölçütün gerektirdiği verilerin, örneğin fonksiyon noktası için girdi, çıktı, sorgu ve dosya sayılarının elde edilmesi), hesaplama (doğrudan ölçmede atlanabilir), yorumlama (değerin küçük, orta ya da büyük yazılım aralığına düşüp düşmediği, ekibin önceki yazılımlarıyla karşılaştırılması) ve geri besleme (sonuçların ekibe bildirilip yazılımın iyileştirilmesi).

Nesneye yönelik yaklaşımda analiz ve tasarım arasında kesintisiz bir geçiş olduğu için aynı ölçütler hem çözümlemede hem kodlamada kullanılabilir. CK ölçütlerinden WMC tekrar ele alındı (ekrandan, 00:55:00): C1 sınıfının M1...Mn metotlarının karmaşıklıkları c1...cn ile toplanır. Eleştiri olarak metot karmaşıklığının neye göre belirleneceği ve bu belirlemedeki öznelliğin güçlü mü zayıf mı olduğu sorulur. Ölçüt bir sınıfın karmaşıklığını belirler; çok sayıda metodu olan sınıf çok fazla sorumluluk yüklenmiştir ve dağıtılması uygun olabilir, böyle bir sınıf uygulamaya özeldir ve yeniden kullanılabilirliği düşüktür.

Test yönetimi kısmında testin planlama, tasarım ve gerçekleştirme adımlarıyla yürütüldüğü ve bunun için test spesifikasyonu adında bir belge düzenlendiği hatırlatıldı (ekrandan, 01:25:00). Bu belgede test planları (test şekilleri, zamanlama, gider, ortam ve kaynaklar), test senaryoları, test işlemleri (bütünleme biçimi, amaç, test edilen modüller, özel araç ve teknikler, test verisi ve beklenen sonuçlar), gerçek test sonuçları, referanslar ve ekler bulunur. Test spesifikasyonu yazılım konfigürasyonuna giren bir belgedir; yazılır, incelenir, incelemeye dayalı düzeltilir ve baseline olarak tanımlanır (ekrandan, 01:30:00). Test planında test stratejisi, test edilecek öğeler, doğrulama yöntemleri, tamamlanma kriterleri, hata ve sonuç raporlama, sorumluluklar, test ortamı, eleman ve eğitim ihtiyacı, test takvimi (Gantt şeması ile), risk yönetimi ve testin çıktıları yer alır. Test senaryosu belgesi ise senaryonun adı ve kimliği, yazarı ve tarihi, ilgili gereksinim ya da test amacı, ön koşul ve varsayımlar, girdiler, adımlar ve beklenen sonuçları içerir. Test ekibi yazılımı geliştiren gruptan bağımsız olmalıdır; görevi testleri hazırlamak ve yürütmek, bulunan hataları yazılımcıya bildirip izlemek ve sonuçları raporlamaktır. İyi bir testçi mükemmele ulaşılamayacağını ve neyin yeterli olduğunu bilir; optimum test miktarı her projede farklıdır (ekrandan, 01:35:00). Test etkinlikleri yaşam döngüsünün yalnız sonunda değil, baştan itibaren yer alır: planlamada sistem test planı, gereksinim analizinde alt sistem test planları ve use case'lere karşılık test senaryoları, tasarımda modül test planları, gerçeklemede birim, bütünlük ve sistem testleri yapılır.

Risk yönetiminde iki yaklaşım vardır (ekrandan, 01:40:00): reaktif yaklaşımda risk gerçekleşince çaresine bakılır, proaktif yaklaşımda riskler gerçekleşmeden önlenmeye çalışılır; derste proaktif yaklaşım işlendi. Riskin tanımında üç kavram vardır: olasılık (hiçbir risk %100 olasılıklı değildir), kayıp (risk gerçekleşince istenmeyen sonuçlar doğurur) ve gelecek (riskin ne zaman ortaya çıkabileceğine dair tahmin). Genel risk çeşitleri proje, teknik ve iş riskleridir. Pressman'ın eski baskılarındaki ayrıntılı sınıflamada müşteri, süreç, geliştirme ortamı, teknik altyapı, personel ve olağanüstü durum (yangın, sel, deprem gibi olasılığı düşük ama kaybı yüksek) riskleri sayılır. Risk tablosu oluşturulurken ekip olası riskleri adlandırır, çeşitlerini belirler, uzmanlık alanına göre alt türlere ayırır, olasılıkları (düşük, orta, yüksek ya da yüzde olarak) ve etkileri değerlendirir; ID, ad, çeşit, olasılık ve etki ile tablo yapılır, liste bir yerden sonra kesilir ve ele alınacak riskler için risk bilgi sayfaları açılır (ekrandan, 01:50:00). Önem olasılık ile etkinin çarpımıyla bulunur. Takip edilen her risk için kilometre taşlarında olasılık ve etkinin değişip değişmediğine bakılır, bir önlem (örneğin test ekibinin kilit üyesinin ayrılması riskine karşı yanına yardımcı yetiştirmek ya da ayrılmaması için anlaşmalar yapmak) ve bu önlemin maliyeti yazılır.

Konfigürasyon yönetimine giriş için önce yazılımın ne olduğu soruldu: yazılım programlar, belgeler ve veri yapılarından oluşur. Yazılıma ait bu maddelerin bütününe yazılım konfigürasyonu, her birine yazılım konfigürasyon maddesi (software configuration item) denir. Konfigürasyon tanımında her maddenin bilgileri (örneğin bir tablonun ne zaman yaratıldığı, kolonları, hangi uygulamalarca kullanıldığı; bir modülün ilgili gereksinimi, tasarım bilgisi ve kullandığı tablolar) kaydedilir; bunu günümüzde geliştirme platformları ve proje yönetim araçları otomatik yapar. Değişiklik kontrolünde her yeni sürümde hangi maddenin, hangi aşamada değiştiği izlenir; ayrıca konfigürasyon denetimi ve raporlama yapılır. İlgili standartlar IEEE 828 (SCM planları standardı), IEEE 1042 (SCM planları rehberi) ve ISO 9004 Kısım 6'dır. Konfigürasyon yönetimi, yeni sürüme geçişin kurallarını belirleyen sürüm yönetimiyle (release management) birlikte kullanılır; çevik yaklaşımlarda sürüm yönetimi klasik süreçlerden farklı işler. Son olarak bakım maliyetini azaltmak için bakım yapılabilirlik gerektiği; bunun anlaşılabilir sistem yapısı, standartlara uygun belgeler, standart programlama dili yapıları, test programları ve tasarımda hata bulma ile sağlandığı, bakım ve onarıma elverişliliğin ise sınanabilirlik, basitlik, değiştirilebilirlik, taşınabilirlik gibi özelliklerle ölçüldüğü belirtildi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
