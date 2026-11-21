# Ders 11 Çalışma Özeti

## Genel Konular

- Bu ders öğrenci makale sunumlarına ayrıldı; beş sunum yapıldı
  - Konular: test aracıları (test agents) ve regresyon testi, yazılım hata tahmininde kalıtım metrikleri, GUI testleri için otomatik test scripti üretimi, makine öğrenmesiyle yazılım hata tahmini üzerine sistematik incelemeler, metamorfik test.
- Test aracıları (Test Agents) ve regresyon testi
  - Regresyon testi, yazılımda yapılan bir değişikliğin yazılımın değişmeyen diğer kısımlarını bozmadığını doğrulamak için yapılan testtir. Amaç, kritik işlevlerin hâlâ beklendiği gibi çalıştığını görmektir.
  - Geleneksel regresyon testi merkezîdir: test uzmanı kapsamı (scope) ve sırayı belirler, scriptler otomatik koşulur. Sorunlar: maliyetli planlama, kötü önceliklendirilmiş test paketleri, gözden kaçan senaryolar, çalışma anındaki değişikliklere esnek olmayan tepki.
  - Yazılım aracılarının ortak özellikleri (ekrandan, 00:20:00): özerklik, sosyal yetenek, duyarlılık, proaktivite.
  - Test aracısı vizyonu: test seçimi, önceliklendirme ve zamanlamanın büyük kısmını merkezî otomasyon çerçevesinden, aracıların kendi başına karar verdiği daha düşük bir soyutlama düzeyine kaydırmak (ekrandan, 00:25:00).
  - Uyarlanabilir özerklik iki boyutludur: kendi kendine yeterlilik (görevi dışarıdan yardım almadan yapmak) ve kendi kendine yönelim (kendi hedeflerine karar vermek).
  - Test aracısı durum modeli (ekrandan, 00:30:00): Entry, Idle, Execute, Interact, Out of Order, Regenerate.
  - Etkileşim düzeyleri: yanıt beklemeden bilgi yayma, birebir diyalog, birebir görev devri (delegasyon), bire çok diyalog/delegasyon.
- Yazılım hata tahmininde (SFP) kalıtımın etkinliği
  - Yazılım hata tahmini, hatalı sınıfları erken bulup testi bunlara yoğunlaştırarak kaliteyi artırmayı amaçlar. Süreç iki aşamalıdır: eğitim (metrik + hata bilgisiyle model kurma) ve tahmin (sınıfları hatalı/hatasız etiketleme).
  - Kaynak kodun kalitesi iç (dahili) metriklerle, yazılımın davranışı dış (harici) metriklerle ölçülür.
  - Kalıtım yeniden kullanım ve test edilebilirlik sağlar ama kalıtım ilişkisi büyüdükçe karmaşıklık ve ek test ihtiyacı artar (ekrandan, 00:45:00).
  - Literatürde 54 kalıtım metriği kataloglanmıştır; örnekler: DIT (kalıtım ağacı derinliği), NOC (alt sınıf sayısı), AIF, MIF, fan-in/fan-out, NAC, NDC (ekrandan, 00:50:00).
  - Teknikler: istatistiksel yöntemler (tek değişkenli ikili lojistik regresyon, lojistik regresyon) ve makine öğrenmesi (SVM, karar ağacı, AdaBoost, rastgele orman, k-NN, yapay sinir ağları/MLP).
- GUI testlerinde otomatik test scripti üretimi
  - Çevik ve yinelemeli geliştirmede her döngüde regresyon testi gerekir; bu çok adam-saat tüketir (ekrandan, 01:05:00).
  - Mevcut yaklaşımlar: capture & replay (yakala ve yeniden oynat, Selenium IDE), ekran tasarım belgelerinden model tabanlı test, iş akış diyagramı gibi yüksek soyutlamalı modellerden senaryo üreten araçlar (stateMatrix, TQCAssist) (ekrandan, 01:10:00).
  - Önerilen yöntem: kaynak kodun statik analizi ve uygulamanın dinamik analiziyle ekran geçiş bilgisini çıkarmak, test case'leri üretmek, test scriptlerini ve ekran geçiş diyagramını oluşturmak; otomatik üretilemeyen geçişleri kullanıcıya göstermek (ekrandan, 01:15:00 ve 01:20:00).
  - Deneyde test scripti hazırlama süresi 998 saniyeden 393 saniyeye inmiş, yaklaşık %61 azalma elde edilmiştir.
- Makine öğrenmesiyle yazılım hata tahmini: sistematik inceleme
  - Kitchenham'ın sistematik literatür inceleme kılavuzuna göre 1991-2013 arası çalışmalar taranmış: 122 çalışma, dahil etme/hariç tutma kurallarıyla 79, 15 soruluk kalite anketiyle 64 çalışma (ekrandan, 01:40:00).
  - En çok kullanılan veri seti NASA, sonra PROMISE; en çok kullanılan özellik seçimi korelasyon tabanlı özellik seçimi (CFS); performans ölçütleri accuracy, recall, precision, ROC/AUC, F-measure (ekrandan, 01:45:00).
  - Ortalama AUC'ye göre en iyi yöntem rastgele orman (0.83); makine öğrenmesi yöntemleri lojistik regresyondan biraz daha iyi, fakat karşılaştırma sayısı azdır.
  - Nesne yönelimli bir sistemde (Xerces sürümleri) 17 yöntemin karşılaştırmasında Bagging en iyi ortalamayı (0.828) vermiş, RF 0.826 ile çok yakın kalmıştır (ekrandan, 01:55:00).
- Metamorfik test
  - Test oracle problemi: bir girdiye karşılık doğru çıktının ne olması gerektiğini önceden belirlemek zordur, karmaşık yazılımlarda emek ister.
  - Metamorfik test (Chen ve arkadaşları, 1998), girdiler arasındaki bir dönüşüm ile çıktılar arasındaki ilişkiyi (metamorfik ilişki) kullanarak testi yapar; her girdinin beklenen çıktısını ayrı hesaplamak gerekmez.
  - Örnekler: $\sin(x) = \sin(x+360^\circ)$ ve $\sin(-x) = -\sin(x)$ (ekrandan, 02:05:00); bir arama sorgusuna kelime eklenince sonuç sayısının artmaması.
  - Süreç: metamorfik ilişkilerin kurulması, kaynak test senaryolarının oluşturulması, metamorfik test durumlarının yürütülmesi (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Metrikler yazılım kalitesi için çok önemlidir
  - Hoca, kalıtım metrikleri sunumundan sonra metriklerin yazılım kalitesindeki yerini ve derste üzerinde durulduğunu hatırlattı.
- Yazılım hata tahmini çok çalışılan bir alandır
  - Hoca, hata tahmini üzerine çok sayıda çalışma bulunduğunu, alanın yapay zeka uygulamalarıyla birleştiği için mühendislik yaklaşımına açık olduğunu söyledi.
  - Aynı konunun iki farklı açıdan (kalıtım metrikleri ve makine öğrenmesi teknikleri) incelenmesinin yararlı olduğunu belirtti.

## Kısa Tekrar Notları

- Regresyon testi: değişiklik sonrası değişmeyen kısımların hâlâ doğru çalıştığını doğrular.
- Geleneksel regresyon testi merkezî ve statik; test aracıları dağıtık, uyarlanabilir ve kendi kararını veren yapılar önerir.
- Yazılım aracısı özellikleri: özerklik, sosyal yetenek, duyarlılık, proaktivite.
- Test aracısı durumları: Idle, Execute, Interact, Out of Order, Regenerate.
- SFP: metriklerden hatalı sınıf tahmini; eğitim ve tahmin aşamaları.
- 54 kalıtım metriği; DIT ve NOC en bilinenler.
- CK (Chidamber-Kemerer) metrik seti hata tahmininde yaygın; CBO ve RFC çok kullanılmış.
- NASA ve PROMISE en çok kullanılan açık veri setleri; CFS en çok kullanılan özellik seçimi.
- Rastgele orman ve Bagging hata tahmininde en iyi sonuçları veren yöntemler arasında.
- GUI test otomasyonunda statik + dinamik analizle test scripti üretimi adam-saati yaklaşık %61 azaltmış.
- Metamorfik test, test oracle problemini metamorfik ilişkilerle hafifletir.

## Detaylı Açıklamalar

- Test aracıları paradigmasında her test aracısı kendi zamanlamasına ve karar mekanizmasına sahiptir. Idle durumunda bekleyen aracı, bir görev oluştuğunda ya da başka bir aracıdan görev aldığında Execute durumuna geçer ve yürütmeden önce ve sonra yardıma ihtiyacı olup olmadığına karar verir. Başka bir aracıdan talep geldiğinde Interact durumuna geçip yardım edip etmeyeceğine kendisi karar verir. İlk amacına hizmet edemeyeceğini anlayınca Out of Order durumuna geçer; gerekirse Regenerate durumunda bir test mühendisinin yardımıyla yeniden tasarlanır. Sunumda verilen örnekte kaynağı yetmeyen bir A aracısı B'den yardım ister; B talebin kendi çıkarına katkısı olmadığını görüp reddeder, C ise talebin kendi testleri için yararlı çıktı (log, hata raporu) üreteceğini görüp kabul eder.
- Önceki aracı tabanlı test çalışmaları da anlatıldı: bulanık mantıkla test seti seçen uyarlanabilir test yönetim sistemi (ATMS), koordinatör ve runner aracılarını ayıran BDI (Belief-Desire-Intention) tabanlı yaklaşım ve test yaşam döngüsünü gereksinim, oluşturma, yürütme ve raporlama aracılarıyla otomatikleştiren çalışma.
- Kalıtım metrikleri sunumunda hata tahmininin dahili metrikler, benzer projelerin metrikleri ve önceki sürümlerin hata bilgileriyle model kurduğu anlatıldı. Kalıtım uygun aralıkta tutulursa yazılım karmaşıklaşmaz; aşırı kalıtım ise yöntemlerin çok sayıda kalıtım almasına ve ek test ihtiyacına yol açar. CK metrik setinde kalıtım metriklerinin ayrı değerlendirilmesinin eksik olduğu, bu nedenle kalıtıma odaklanan bir çalışmanın yapıldığı belirtildi.
- GUI test sunumunda capture & replay ile hazırlanan scriptlerin bakım maliyetinin yüksek olduğu, model tabanlı yöntemlerin ise tamamlanmış tasarım belgesi gerektirdiği için şelale modeline uygun ama çevik süreçlerde zor olduğu vurgulandı. Önerilen yöntemde ilk URL'den başlayarak link ve butonlara basılır, her yeni ekran geçişi bir test case olarak kaydedilir, aranan ekran sayısı statik analizle bulunan varış noktası sayısını tutmazsa önceki ekrana dönülüp arama tekrarlanır. Otomatik üretilemeyen geçişler ekran geçiş diyagramında kesikli çizgiyle gösterilir ve kullanıcının bu testleri elle tamamlaması istenir; böylece tüm geçişler kapsanır.
- Sistematik inceleme sunumunda kalite anketinde her soru için "yes" 1, "partly" 0.5 puan alınmış, 9.5 ve üstü puan alan 64 çalışma seçilmiştir. Rastgele orman gürültülü ve eksik veride başarılı ve hızlı eğitilir; Naive Bayes hata tahmininde iyi performans gösterir ama özellikler arası korelasyonu dikkate almaz; SVM gereksiz özellikler ve yüksek boyutlulukla iyi başa çıkar (ekrandan, 01:50:00). İkinci incelenen çalışmada WEKA üzerinde 10 katlı çapraz doğrulama, Friedman testi ve Wilcoxon testiyle karşılaştırma yapılmış, Bagging en iyi Friedman ortalama sırasını (2.80) almıştır.
- Metamorfik test sunumunda metamorfik ilişkinin yalnız eşitlik olmak zorunda olmadığı, büyüktür/küçüktür gibi ilişkilerin de kullanılabildiği belirtildi. Sunumda bir arama motorunda tek kelimelik bir sorgunun ve buna bir kelime eklenmiş sorgunun sonuç sayıları karşılaştırılarak küçük bir metamorfik test canlı olarak yapıldı: iki kelimeli sorgu daha az sonuç verdi, ilişki sağlandı. Kaynak ve takip testlerinin çıktıları metamorfik ilişkiyi ihlal ederse program hatalı demektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
