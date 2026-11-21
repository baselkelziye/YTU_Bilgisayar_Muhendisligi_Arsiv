# Ders 3 Çalışma Özeti

## Genel Konular

- Kaliteyi sağlama aktivitelerinin genel çerçevesi
  - Dönem başından bu yana işlenenler toparlandı: yazılım mühendisliği içinde kalitenin yeri, kalite modeli ve kalite özellikleri (kullanıcı, çalıştıran ve bakım yapan bakış açıları), kalite özelliklerinin metriklerle ilişkisi, standartlar.
  - Kaliteyi sağlamak için yapılanlar: geliştirmeye başlamadan önce uygun bir yazılım geliştirme süreç modeli seçmek, kurumun yazılım standartlarını belirlemek (el kitabı), geliştirme sırasında gözden geçirme (review), inceleme (inspection) ve test yapmak.
  - Bunların dışında konfigürasyon yönetimi, risk yönetimi, sürüm (release) yönetimi ve ölçüm de kaliteyi sağlama aktiviteleridir.
- Gözden geçirme ve onaylama
  - Yazılım geliştirme sürecinin her basamağı tamamlanınca durak noktalarında (milestone) yapılan işler gözden geçirilir ve gerekli düzeltmeler yapılır (ekrandan, 00:10:00).
  - Gözden geçirme bir "eleme" niteliğindedir: hatalar zamanında bulunur, hata bulma gideri düşük, hatanın bulunma olasılığı yüksek olur.
  - Süreç ilerledikçe hata bulma gideri artar, hata bulma olasılığı azalır (ekrandan, 00:15:00; Şekil 2.3).
- Gözden geçirmenin amaçları ve yararları
  - Amaçlar: işlevsel, mantıksal ve gerçekleştirme (kodlama) hatalarını bulup gidermek; yazılımın gereksinimlere uygun düzenlendiğini onaylamak; önceden belirlenen standartlara uygunluğu sağlamak.
  - Yararlar: yazılımın düzenli geliştirilmesi, proje yönetiminin kolaylaşması, müşteriye dağıtılacak ürünün kalitesinin artması.
- Gözden geçirme nedir, ne değildir
  - Teknik uzmanların çalışmalarının teknik uzmanlarca değerlendirildiği bir toplantı; ürünlerin teknik değerlendirmesi; bir kalite sağlama aktivitesi ve bir eğitim ortamı.
  - Proje özeti ya da proje ilerlemesi toplantısı, geliştirme ekibinin politik veya kişisel değerlendirmesi, sadece bilgi verme toplantısı değildir (ekrandan, 00:20:00).
  - Toplantı rolleri: gözden geçirme lideri, kullanıcı temsilcisi, standartlara uygunluğu kontrol eden (kalite güvence ekibinden) kişi, üretici (geliştirme ekibinden), kayıtçı.
- Gözden geçirme tipleri ve seçenek matrisi
  - Formal olmayan gözden geçirme (informal review), yapısal denetim (walkthrough), inceleme (inspection) ve round robin peer review.
  - Tablo 3.1 bu üç türü yedi ölçüte göre karşılaştırır (aşağıda Detaylı Açıklamalar).
  - Küçük projelerde gözden geçirme ve düzeltme geliştiricilerce yapılabilir; büyük projelerde hataları üçüncü kişi daha iyi göreceği için ayrı bir ekip daha doğrudur.
- Gözden geçirme ve onaylama basamakları
  - Sistem analizi, yazılım geliştirme planı, gereksinim analizi (SRS), tasarım (ön ve ayrıntılı), kodlama, sınama, bakım ve onarım basamaklarının sonunda gözden geçirme yapılır.
  - Basamak adları süreç modeline göre değişir (örneğin spiral modelin 6 adımı her turda tekrar eder); her modelde benzer adımlar vardır ve her biri gözden geçirilir.
- Gözden geçirme standartları
  - SDR (System Design Review), SSR (Software Specification Review), PDR (Preliminary Design Review, ön tasarım), TRR (Test Readiness Review, sınamaya hazır olmanın değerlendirilmesi) (ekrandan, 01:15:00).
- Yazılım incelemesi (inspection)
  - Kodu çalıştırmadan hataları bulmayı amaçlayan statik geçerleme (static verification) yöntemidir; test ise kodu çalıştıran dinamik yöntemdir.
  - Genel inceleme süreci üç aşamalıdır: planlama ve hazırlık; inceleme ve toparlama; düzeltme ve tamamlama (gerekirse yeniden inceleme).
  - Fagan inceleme süreci: aşamaları daha ayrıntılı; kod okuma yukarıdan aşağıya ve aşağıdan yukarıya incelemenin birleşimidir; ekip inceleme sorumlusu, inceleyiciler, yazar, kod okuyucu ve kayıtçıdan oluşur (ekrandan, 01:25:00).
  - Teknik inceleme raporu: neyin, kimlerce gözden geçirildiği, bulunan hata ve eksikler ve yapılacaklar ile sonuç kararı.
- Yazılım sınama (test) ve V model
  - Sınama, bir programdaki hataları bulmak amacıyla yapılan işlemlerdir; yazılımın fonksiyonel, performans, dayanıklılık ve yapısal bakımlardan yeterliliğini denetler (ekrandan, 01:30:00).
  - V modelde sol kol yazılım geliştirme aktiviteleri, sağ kol test aktiviteleridir; her test kendi karşısındaki geliştirme basamağının belgesini kullanır (ekrandan, 01:40:00).
- Birim test
  - Yazılım tasarımının en küçük birimi olan modül üzerinde, ayrıntılı tasarım tanımlarına dayanılarak yapılır; saydam kutu testi olarak, çok sayıda modül üzerinde paralel yürütülür (ekrandan, 01:55:00).
  - Test sürücü (driver) ve koçan (stub) kullanılır; test senaryosu (test case) bir program yolunu işletmek ya da bir gereksinime uygunluğu onaylamak için düzenlenen test verisi ve işlemlerdir (ekrandan, 02:00:00).
- Genişletilmiş V model ve alt test adımları
  - Regresyon testi (bütünlük testini tamamlayıcı), kabul testi, alfa ve beta testi, teşhis testi (ekrandan, 02:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Hatayı erken bulmak
  - Süreç ilerledikçe hatayı bulmak hem zorlaşır hem pahalılaşır; bu yüzden hataların teste kalmaması, her basamakta gözden geçirmeyle yakalanması istenir.
  - Slaytta: hataların %50-65'i tasarım aşamasında yapılır, gözden geçirmede bunların %75'i bulunabilir; bulunamayanlar sınama öncesinde 5-6 kat, sınama sırasında 15 kat, kullanım aşamasında 67 kat gider gerektirir (ekrandan, 00:20:00). Kullanımda kullanıcının güveninin sarsılması da maliyete eklenir.
- Gözden geçirme bir değerlendirme toplantısı değildir
  - En çok yakınma, toplantının kalite ya da test grubunun kişisel/politik değerlendirmesine dönmesinden gelir; amaç yalnız standartlara ve gereksinimlere uygunluk ile hataları ortaya çıkarmaktır.
- Review ile inspection arasındaki temel fark
  - Inspection'da yazılımcı sunum yapmaz, checklist önceden hazırlanır ve bulunan hatalar mutlaka sınıflandırılır; diğer iki türde checklist ve sınıflandırma yoktur.
- Statik ve dinamik geçerleme
  - Inspection kodu çalıştırmadan yapılır ve bütün ara ürünlere (gereksinim spesifikasyonu, yüksek seviye tasarım, formal spesifikasyon, ayrıntılı tasarım, program) uygulanabilir; test ise yalnız çalıştırılabilen program ve prototipe uygulanır.
- Terim düzeltmesi: verification ve validation
  - Sözlükte ikisi de hem "geçerleme" hem "doğrulama" diye çevrilebilir; testle uğraşanların ortak kararıyla validation = geçerleme, verification = doğrulama kullanılır. Hoca eski slaytlarında bu çevirinin ters kaldığını belirtti.
- Ön tasarım ile ayrıntılı tasarım gözden geçirmesinin farkı
  - Ön tasarımda gereksinimlerin mimariye doğru yansıtılması ve modül bağımsızlığı; ayrıntılı tasarımda modül içi algoritmalar, yerel veri yapıları, veri tabanı ve ara birim tasarımı incelenir.

## Kısa Tekrar Notları

- Kalite aktiviteleri: süreç modeli seçimi, standartlar, gözden geçirme, inceleme, test, konfigürasyon/risk/sürüm yönetimi, ölçüm.
- Gözden geçirme durak noktalarında (milestone) yapılır; hata bulma gideri süreçle artar, bulma olasılığı azalır.
- Gözden geçirme rolleri: lider, kullanıcı temsilcisi, kalite güvence temsilcisi, üretici, kayıtçı.
- Gözden geçirme türleri: informal review, walkthrough, inspection, round robin peer review.
- Inspection: lider var, takvim var, hazırlık var, yazılımcı sunumu yok, checklist var, hata sınıflandırma var, kayıtçı var.
- Standartlar: SDR, SSR, PDR, TRR. SRS standardı belgenin başlıklarını, SSR ise belgenin nasıl değerlendirileceğini tanımlar.
- Inspection = statik geçerleme (çalıştırmadan); test = dinamik (çalıştırarak).
- İnceleme süreci: planlama ve hazırlık → inceleme ve toparlama → düzeltme ve tamamlama.
- Fagan ekibi: inceleme sorumlusu, inceleyiciler, yazar, kod okuyucu, kayıtçı.
- Validation = geçerleme, verification = doğrulama.
- V model: kodlama ↔ birim test, alçak düzey tasarım ↔ bileşen testi, yüksek düzey tasarım ↔ bütünlük testi, ürün spesifikasyonu ↔ sistem testi, müşteri gereksinimleri ↔ işlemsel kullanım.
- Birim test: modül düzeyi, saydam kutu, driver ve stub, test case.
- Regresyon testi: değişiklik sonrası bütünlük testinin tekrarı. Alfa testi: ekip içi kullanıcı temsilcileri; beta testi: gerçek/potansiyel kullanıcılar.

## Detaylı Açıklamalar

- **Gözden geçirme neden gerekli?** Yazılım geliştirme süreci ilerledikçe bir hatayı bulmanın gideri katlanarak artar, hatayı bulma olasılığı ise düşer (Şekil 2.3, ekrandan, 00:15:00). Waterfall gibi modellerde test sona kaldığı için "önce geliştireyim, sonra test ederim" yaklaşımı hataları geç yakalar. Bu yüzden her basamağın sonunda yapılanlar kontrol edilir. Formal olmayan gözden geçirme daha hızlı ve sık yapılırken, inspection daha formal ve ayrıntılıdır. Gözden geçirme, inceleme ve test geliştirme sırasındaki üç temel kalite aktivitesidir.

- **Gözden geçirme seçenek matrisi.** Tablo 3.1'de (ekrandan, 00:25:00) GG (formal olmayan gözden geçirme), WT (walkthrough) ve İnc. (inspection) karşılaştırılır:

  | Ölçüt | GG | WT | İnc. |
  |---|---|---|---|
  | Gözden geçirme lideri | yok | var | var |
  | Toplantı takvimi | belki | var | var |
  | Gözden geçirenlerin hazırlığı | belki | var | var |
  | Yazılımcı sunum yapıyor mu | belki | var | yok |
  | Hataları bulmak için checklist | yok | yok | var |
  | Bulunan hatalar sınıflanıyor mu | yok | yok | var |
  | Kayıtçı not alıyor mu | belki | var | var |

  Formal olmayan gözden geçirmede lider önceden belirlenmeyebilir, toplantıda katılımcılardan biri seçilebilir. Inspection'da yazılımcıdan ayrıca sunum alınmaz: inceleme ekibi işi paylaşır, önceden çalışır, yalnız sorusu olursa geliştiriciye sorar. Her inceleyicinin kendi bakış açısıyla değerlendirmesi için checklist önceden hazırlanır.

- **Basamaklara göre neler gözden geçirilir?**
  - Sistem analizi: sistem düzeyindeki spesifikasyonların yazılıma ilişkin işlev ve görevler olarak dağıtımının doğruluğu, kalite güvencesini onaylama gereksinimlerinin tutarlılığı, görevlendirmenin yeterliliği; ana işlevler, ara birimler, performanslar ve tasarım kısıtlarının tanımları, alternatifler arasından seçimin tutarlılığı (fizibilite), teknolojik yapılabilirlik, sistemin sınanma esasları, sistem öğeleri arasındaki uyumluluk (ekrandan, 00:30:00).
  - Yazılım geliştirme planı: seçilen çözüme göre hazırlanan planda risk var mı; sorunun tanımı ve terimlerin doğruluğu, kaynakların yeterliliği ve sağlanma olasılığı, görevlerin uygunluğu, verimlilik, kalite, gider ve zamanlama tahminlerinin tutarlılığı.
  - Gereksinim analizi: sistem düzeyi gereksinimlere uygunluk, bilgi alanı analizinin doğruluğu ve tutarlılığı, sorunun bölümlere doğru ayrılması, iç ve dış ara birim tanımları, performansın yapılabilirliği, fonksiyonel olmayan gereksinimlerin doğru tanımlanması.
  - Yazılım tasarımı: veri yapıları, program yapısı ve işlemler ele alınır; önce ön tasarım, sonra ayrıntılı tasarım gözden geçirilir. Ön tasarımda gereksinimlerin yazılım mimarisine doğru yansıtılması, modüllerin etkinliği ve işlevsel bağımsızlığı, program yapısının uygunluğu, dış sistem öğeleri ve modüllere ait ara birimlerin tanımlanması, veri yapısının bilgi alanıyla tutarlılığı, bakım ve onarım sorunları incelenir (ekrandan, 00:35:00). Modül bağımsızlığı nesneye yönelik yaklaşımda sınıflar arası bağımsızlık olarak düşünülür: modül içi bağlılık (cohesion) yüksek, modüller arası bağlantı (coupling) yalnız gerektiği kadar olmalıdır; aksi halde bakım zorlaşır. Ayrıntılı tasarımda her modülün algoritması, iç yapıdaki bağımsızlık, yerel veri yapıları, veri tabanı ve ara birim tasarımı, girdi ve çıktıların tanımı incelenir.
  - Kodlama: ayrıntılı tasarımın programlama diline dönüştürülmesinin doğruluğu, yazım hataları, kodlama ve programlama dili standartlarına uygunluk, açıklamaların tutarlılığı ve uygunluğu, tasarım hatalarının düzeltilip düzeltilmediği.

- **Gözden geçirme standartları.** Yazılım mühendisliği standartları her basamaktaki gözden geçirmenin kurallarını ve checklist'lerini verir. Örneğin SRS standardı gereksinim belgesinde hangi başlıkların bulunacağını (içindekiler listesi gibi) tanımlar; SSR ise yazılmış gereksinim belgesi değerlendirilirken nelere bakılacağını tanımlar. TRR teste başlamadan önce nelerin tamamlanmış olması gerektiğini sorgulayan bir checklist niteliğindedir.

- **Inspection süreci.** Planlama ve hazırlık aşamasında incelemenin amacı, incelenecek parçalar, kimin hangi parçayı (plan, gereksinim, tasarım, kod, modüller) inceleyeceği, inceleyicilerin taşıması gereken özellikler ve uygulanacak teknikler belirlenir (ekrandan, 01:20:00). İnceleme ve toparlama aşamasında hatalar tespit edilip kayda geçirilir. Düzeltme ve tamamlama aşamasında hatalar sorumlu kişilerce düzelttirilip takip edilir; sonuç alınamazsa sürecin başına dönülür. Fagan modelinde (slayt başlığında 1986) aşamalar daha ayrıntılıdır: planlama, gözden geçirme (genel bakış), kişisel inceleme, inceleme toplantısı, düzeltme, tamamlama ve raporlama. <!-- BELİRSİZ: Fagan aşama şeklinin tam adları karede okunamadı; adlar altyazıdan alındı. --> Etkili kod okuma, programın fonksiyon, prosedür, alt program gibi en küçük parçalara ayrılıp önce parçaların kendi içindeki bütünlüğünün, sonra bütünle uyumunun incelendiği yukarıdan aşağıya ve aşağıdan yukarıya incelemenin birleşimidir.

- **Teknik inceleme raporu.** Raporda neyin ve kimlerce gözden geçirildiği, hangi hata ve eksiklerin bulunduğu ve ne yapılması gerektiği yazılır; hata sınıflandırması ve checklist sonuçları belirtilir. Sonuç kararı slayta göre şunlardan biridir: değişiklik yapılmaksızın kabul, belirtilen önemsiz hataların düzeltilmesi koşuluyla kabul, reddedilip düzeltme sonunda yeniden inceleme (ekrandan, 02:20:00, slayt listesinden).

- **V model.** Sol kolda müşteri gereksinimleri, ürün spesifikasyonu, yüksek düzey tasarım, alçak düzey tasarım ve kodlama; sağ kolda bileşen testi, bütünlük testi, sistem testi ve işlemsel kullanım vardır (Şekil 3.2, ekrandan, 01:40:00). Alt düzeylerde doğrulama (doğru yolla mı üretiyoruz), ürün spesifikasyonu ile sistem testi arasında geçerleme/doğrulama, en üstte geçerleme yapılır; çünkü kullanıcı programa dışarıdan bakar ve yalnız isteklerini karşılayıp karşılamadığıyla ilgilenir. Kodlama sonucu elde edilen kod birim testte, yüksek düzey tasarımdaki yapı ya da UML diyagramları bütünlük testinde, ürün spesifikasyonu sistem testinde kullanılır.

- **Birim test ve test senaryosu.** Birim testte modülün ara birimi, lokal veri yapısı, kontrol yapıları arasındaki ana yollar, hata arama yolları ve modül sınırları sınanır. Test edilen modülü çağıran modül yerine test sürücü (driver) test verisini aktarır ve sonuçları dışarı verir; modülün çağırdığı ama henüz test edilmemiş modüllerin yerine yapay modül (koçan, stub) konur. Java için JUnit gibi araçlar kullanılabilir. Bir programda birden fazla kontrol akışı olabilir; ikinci dereceden denklemin köklerini bulan programda deltanın durumuna göre üç farklı yol izlenir. Rastgele girilen veriler hep aynı yoldan geçebileceği için her yolu işletecek test verisi grupları kontrol akışına bakılarak hazırlanmalıdır. Test programlarının geliştirilmesi de diğer yazılımlar gibidir; test planı uyarınca tasarımla birlikte başlanmalıdır (ekrandan, 02:00:00).

- **Genişletilmiş V model.** Şekil 5.6'da (ekrandan, 02:05:00) bütünlük testinin yanında regresyon testi, sistem testinin üstünde kabul testi, işlemsel kullanımın yanında beta testi ve teşhis testi gösterilir. Regresyon testi birimlerde değişiklik olduğunda bütünlük testinin tekrarlanmasıdır. Kabul (onay) testinden önce alfa testi yapılır: ekip içinde kullanıcıları temsil eden bir grup yazılımı çalıştırır. Beta testinde yazılım potansiyel/gerçek kullanıcılara verilir. Teşhis testi işlemsel kullanımda genel bir hata görülünce ayrıntılara geri dönülebildiğini gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
