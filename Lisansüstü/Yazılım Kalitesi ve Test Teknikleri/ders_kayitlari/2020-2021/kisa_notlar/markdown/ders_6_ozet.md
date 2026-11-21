# Ders 6 Çalışma Özeti

## Genel Konular

- Yazılım ölçümünün amacı ve kimin için gerekli olduğu (geçen haftanın tekrarı)
  - "Ölçemediğinizi kontrol edemezsiniz" ilkesi bütün metrik alanları için geçerlidir. Mühendislik iki zorunluluğa dayanır: tasarım ve ölçüm. Yazılım geliştirmeyi bir sanat olmaktan çıkarıp mühendislik uygulamasına dönüştüren şey ölçütlerdir.
  - Proje yönetiminde biten projelerden arşiv verisi oluşturulur. Bu birikim yeni projede büyüklük, maliyet, iş gücü ve süre tahmini için kullanılır.
  - Yöneticiler için: üretim maliyetine karar vermek, çalışan ücretlerini belirlemek, personel verimliliğini ölçmek, altyapıda kullanılan yazılım ürünlerini kıyaslamak.
  - Yazılım mühendisleri için: sistem kalitesini izlemek, tasarım süresince yapılan değişikliklerde, gözden geçirmelerde ve test adımlarında yararlanmak, kalite ve performans gereksinimlerini ölçülebilir terimlerle belirlemek, sertifika çalışmaları, var olan ürün ve süreçlerden gelecekteki ürünler için tahmin yapmak.
- Halstead ölçütleri (ekrandan, 00:20:00)
  - Kaynak programın kalite güvencesini kestirmek için dört sayı saptanır: $m$ farklı işleç (operatör) sayısı, $k$ farklı işlenen (operand) sayısı, $M$ işleç yinelenmelerinin toplamı, $K$ işlenen yinelenmelerinin toplamı.
  - Slayttaki ölçütler: program uzunluğu $U = m\log_2 m + \log_2 k$, program hacmi $H = (M+K)\log_2(m+k)$, program gücü (program effort) $G = H/O$. Slayta göre oransal hacim ($O$) daima birden küçük bulunmalıdır.
  - Ders sonrası not: Slayttaki uzunluk formülünde ikinci terimin katsayısı eksik görünüyor. Halstead'in tahmini uzunluk formülü büyük olasılıkla $U = m\log_2 m + k\log_2 k$ biçimindedir.
- McCabe döngüsel karmaşıklığı (cyclomatic complexity)
  - Programın kontrol akışı gösterimine (program grafı / akış grafı) dayanır. Grafikteki her düğüm bir ya da birden çok deyimden oluşan bir görevi temsil eder (ekrandan, 00:25:00).
  - Graf içindeki kapalı bölgeler ile graf dışında kalan bölge sayılır, bu sayı modülün karmaşıklığını verir. Slayttaki örnekte bölgeler R1..R5, $V(G) = 5$ (ekrandan, 00:25:00). Düğüm ve kenar sayısından da hesaplanabilir.
  - Deyimler kontrol deyimleriyle birleştirilip tek düğüm gösterilse de sonuç değişmez: düğüm sayısı artınca kenar sayısı da artar, kapalı bölge sayısı aynı kalır.
  - Saydam kutu testindeki temel yol testinde $V(G)$ bağımsız yol sayısını verir; bu da gereken en az test durumu (test case) sayısıdır.
  - Tasarımda en yüksek modül büyüklüğünü saptamakta kullanılır: çok sayıda proje verisine göre $V(G)$ en çok 10 olmalıdır; aşılırsa modülün sınanması büyük ölçüde zorlaşır (ekrandan, 00:30:00).
- Büyüklük ölçütleri
  - Doğrudan ölçüm: tek bir değer sayılır. Satır sayısı (LOC, KLOC) en kolay ve ilk akla gelen ölçüttür; programlama diline ve programcıya bağlı olduğu için öznel kalır. Diller arası denklik için çevrim tabloları vardır.
  - Dolaylı ölçüm: işlev noktası (function point). Girdi, çıktı, sorgu, dosya (tablo) ve ara birim sayıları farklı ağırlıklarla toplanır (dosya sayısı girdi sayısından daha ağırlıklıdır). Sonra 0-5 arası puanlanan 14 soruyla bir düzeltme faktörü uygulanır. Ticari yazılımlar için geliştirilmiştir.
- Güvenirlik (reliability) modelleri
  - Güvenirlik bir kalite özelliğidir: yazılımın verdiği doğru sonuca ne kadar güvenilebileceği. Geçmiş bilgilere ve teste dayalı olarak toplam işletim süresindeki başarı oranı, düzeltmeden sonraki hata sayısı gibi değerlerle istatistiksel olarak kestirilir.
  - Yüze yakın model vardır. Bir yazılım birden fazla modele göre test edilip sonuçlar karşılaştırılmalıdır. Model değerlendirme soruları (ekrandan, 00:40:00): modele göre yazılım ne kadar geçerlidir, güvenirliğin ölçümü ne kadar kolaydır, yazılımın ne kadarına ihtiyaç vardır, kullanmak kolay ve anlaşılır mıdır, model dış etkenlerden etkileniyor mu.
- Chidamber & Kemerer (CK) metrik kümesi (ekrandan, 00:45:00 ve 00:50:00)
  - WMC (Weighted Methods per Class): sınıftaki tüm metotların karmaşıklıklarının toplamı; her metodun karmaşıklığı 1 alınırsa metot sayısıdır. Geliştirme ve bakım süresi hakkında fikir verir. Metot sayısı çok olan sınıflar uygulamaya özgü olur, tekrar kullanılabilirlikleri düşer.
  - DIT (Depth of Inheritance Tree): sınıfın kalıtım ağacının köküne uzaklığı; türetilmemiş sınıf için 0, çoklu kalıtımda en uzak köke olan uzaklık. Derin sınıfların davranışını tahmin etmek zordur, tasarım karmaşıklığı artar.
  - NOC (Number of Children): doğrudan türetilmiş alt sınıf sayısı. Çok fazlaysa kalıtımın yanlış kullanıldığının göstergesi olabilir; test bütçesi hakkında bilgi verir.
  - CBO (sınıflar arası bağımlılık, coupling): sınıfın bağımlı olduğu sınıf sayısı. Aşırı bağımlılık yeniden kullanımı azaltır, bakımı zorlaştırır, test maliyetini artırır.
  - RFC (Response For a Class): sınıftan bir nesnenin metotları çağrıldığında tetiklenebilecek tüm metotların sayısı; test ve hata ayıklama zorluğunun göstergesi.
  - LCOM (Lack of Cohesion in Methods): sınıfın iç uyumu. İlk tanım: metotların kullandığı nitelik kümelerinin kesişiminden oluşan ayrık kümelerin sayısı. Yenilenmiş tanım: $P$ ortak nitelik paylaşmayan metot çiftleri, $Q$ en az bir ortak nitelik paylaşan çiftler olmak üzere $|P|>|Q|$ ise $LCOM = |P|-|Q|$, aksi durumda 0.
- Test yönetimi ve test adımları
  - Test adımları (ekrandan, 01:15:00): test metodolojisi, test planlama, test tasarımı (dizaynı), testin gerçekleştirilmesi.
  - Test spesifikasyonu: testleri tanımlamak, planlamak, düzenlemek ve belgelemek için hazırlanan belge. İçeriği (ekrandan, 01:55:00): test planları (test şekilleri, zamanlama, gider, ortam, kaynaklar), test senaryoları, test işlemleri (her testin tanımı, amacı, test edilen modüller, araçlar ve beklenen sonuçlar), gerçek test sonuçları, referans, ekler.
  - Test yönetimi geri beslemeli bir süreçtir; hata mesajlarının içeriği de belge olarak test edilir. Test belgelemesi için bir IEEE standardı vardır.
- Test planı (ekrandan, 01:20:00)
  - İçerik: test stratejisi ve test edilecek öğeler, doğrulama yöntemleri, testlerin tamamlanma kriterleri, hata ve test sonuç raporlama, test sorumlulukları, test ortamı, eleman ve eğitim ihtiyacı, test takvimi, risk yönetimi, test çıktıları. Ayrıntılar değişebilir.
- Test senaryosu
  - Adı, yazarı, tarihi, ilgili gereksinimler (amacı), ön koşul ve varsayımlar, test girdileri, senaryo adımları, beklenen sonuçlar. Saklanan yazılım belgeleri arasındadır.
- Test çalışma ekibi ve optimum test miktarı (ekrandan, 01:25:00)
  - Bağımsızlık için test sorumluları yazılımı tasarlayan ve geliştiren gruptan olmamalıdır.
  - Ekibin görevi: test hazırlıkları, testleri yürütmek, hataları yazılımcıya bildirmek, izlemek, sonuçları raporlamak.
  - İyi bir testçi mükemmele ulaşılamayacağını bilir. Test miktarı arttıkça test maliyeti artar, kaçırılan hata sayısı azalır; iki eğrinin kesişimi optimum test miktarıdır.
- Yaşam döngüsü boyunca sınama etkinlikleri (ekrandan, 01:30:00)
  - Planlama: sistem test planı, yazılım kalite planı. Gereksinim analizi: alt sistem sınama planları. Tasarım: modül test planı, test tanımları, test eğitim el kitapları. Gerçekleme: birim test, bütünlük testi, sistem test. Kurulum: kullanıcı testi, test raporları.
- Teslim sonrası kalite sağlama: yazılım bakımı
  - Geliştirme teslim ve kullanıma başlama ile tamamlanır, kullanım süresinde bakım, onarım ve geliştirme gerekir (ekrandan, 01:40:00).
  - Bakım türleri: hata düzeltme, iyileştirme, uyarlama. En büyük pay uyarlamadadır; hata düzeltme ile iyileştirme kalanı yaklaşık yarı yarıya paylaşır. <!-- BELİRSİZ: slayttaki yüzde değerleri karelerde okunamadı -->
  - Bakım maliyeti geliştirme maliyetinden fazla olabilir; çünkü hata gereksinimdeyse sürecin başına dönmek gerekir.
  - Bakım maliyetlerinin azaltılması (ekrandan, 01:45:00): ürünü bakım ve onarıma elverişli (maintainability) oluşturmak; yetenekli ve deneyimli mühendisler, anlaşılabilir ve kolay işletilebilir sistem, standart dil/işletim sistemi/belge biçimi, test programlarından yararlanmak, tasarımda hata bulma ve düzeltme kolaylıkları.
  - Bakım ve onarıma elverişlilik; sınama kolaylığı, basitlik, değiştirilebilirlik, taşınabilirlik, güvenirlik ve esneklik özelliklerinin bileşkesidir.
- Yazılım konfigürasyon yönetimi (ekrandan, 01:50:00)
  - Programlar, belgeler ve veri yapılarına ait bütün maddelere topluca yazılım konfigürasyonu denir. Yazılım konfigürasyon maddesi (software configuration item), YKY işlemlerinin uygulandığı yazılım modülüdür.
  - Dört etkinlik: konfigürasyon tanımı (identification), değişiklik kontrolü (control), denetimi (auditing), raporlama (status accounting).
  - Sürüm (release) yönetimiyle iç içedir. İlgili standartlar: IEEE 828, IEEE 1042, ISO 9004.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ölçüm yazılım geliştirmeyi mühendisliğe dönüştürür
  - Tasarım sırasında ölçütler hesaplanarak daha iyi yazılım geliştirilir; güvenirlik gibi işlevsel olmayan gereksinimler istatistiksel modellerle iyileştirilir.
- McCabe sayısı ile test durumu sayısı ilişkisi
  - Temel yol testinde en az döngüsel karmaşıklık kadar test durumu gerekir ki bütün bağımsız yollar denensin.
- Bağımlılık (coupling) düşük tutulmalı
  - Bir sınıf ne kadar bağımsızsa başka uygulamalarda o kadar yeniden kullanılabilir; nesneye yönelik yaklaşımın amacı da yeniden kullanımdır.
- Test planlamadan, tasarlamadan gerçekleştirilmez
  - Önce planlama, sonra tasarım, sonra testin gerçekleştirilmesi gelir; test metodolojisi seçilen yazılım geliştirme süreç modeline göre sıralamada farklılaşabilir (örneğin test güdümlü geliştirmede test planı daha erken oluşturulur).
- Testte bağımsızlık ve optimum test
  - Bütün hataları yok etmek beklenmez; maliyet ile kaçırılan hata arasında optimum nokta aranır. Optimum test miktarının nasıl bulunacağı akademik bir araştırma konusudur.

## Kısa Tekrar Notları

- Halstead: $m, k, M, K$; hacim $H = (M+K)\log_2(m+k)$.
- McCabe: kapalı bölgeler + dış bölge = $V(G)$; temel yol testinde en az test durumu sayısı; modül için $V(G) \le 10$.
- LOC/KLOC doğrudan, function point dolaylı büyüklük ölçütüdür; FP'de 14 soru ile düzeltme faktörü.
- Güvenirlik modeli birden çok modelle denenip karşılaştırılır.
- CK: WMC, DIT, NOC, CBO, RFC, LCOM.
- Test adımları: metodoloji, planlama, tasarım, gerçekleştirme.
- Test spesifikasyonu: plan, senaryo, işlemler ve beklenen sonuç, gerçek sonuç, referans, ekler.
- Test planının on başlığı; test senaryosunun alanları.
- Test ekibi geliştirici gruptan bağımsız olmalı; optimum test = maliyet ile kaçırılan hata eğrilerinin kesişimi.
- Bakım: hata düzeltme, iyileştirme, uyarlama (en büyük pay uyarlama).
- Maintainability: sınama kolaylığı, basitlik, değiştirilebilirlik, taşınabilirlik, güvenirlik, esneklik.
- YKY: tanım, değişiklik kontrolü, denetim, raporlama.

## Detaylı Açıklamalar

- Ders, önceki haftanın konusu olan yazılım ölçümünün tekrarıyla başlar. Ölçüm hem proje yönetiminde (geçmiş projelerden tahmin) hem de yazılım kalitesinde (tasarım ve test sırasında karmaşıklığı denetleme) kullanılır. Halstead ölçütleri işleç ve işlenen sayılarından programın uzunluğu, hacmi ve gücü hakkında aritmetik bir fikir verir. McCabe ölçütü ise akış grafındaki bölgeleri sayarak kontrol yapısının karmaşıklığını verir. Bu değer saydam kutu testinin temel yol testinde bağımsız yol sayısını, dolayısıyla en az test durumu sayısını belirler; tasarımda da modüllerin $V(G)$ değerinin 10'u aşmaması önerilir.
- Büyüklük için iki yaklaşım vardır. Satır sayısı doğrudan ve kolay ölçülür ama dile bağlıdır. İşlev noktası ise girdi, çıktı, sorgu, dosya ve ara birim sayılarını ağırlıklandırıp 14 soruluk bir düzeltme faktörüyle birleştirir; bu yüzden dolaylı bir ölçümdür ve özellikle ticari yazılımlarda yaygınlaşmıştır.
- Nesneye yönelik yazılımlarda CK metrikleri sınıf düzeyindeki özellikleri sayısallaştırır. WMC, DIT ve NOC sınıfın büyüklüğü ve kalıtım hiyerarşisindeki yeriyle; CBO ve RFC sınıflar arası etkileşimle; LCOM sınıfın iç uyumuyla ilgilidir. Hepsinin ortak noktası yeniden kullanılabilirlik, bakım kolaylığı ve test maliyeti hakkında fikir vermeleridir.
- Dersin yeni konusu test planlama ve yönetimidir. Test kapsamındaki işler metodoloji, planlama, tasarım ve gerçekleştirme sırasıyla yürütülür ve test spesifikasyonu adlı belgede toplanır. Test planı stratejiden risk yönetimine kadar testin nasıl yürütüleceğini; test senaryosu ise hangi gereksinimin hangi girdi ve adımlarla, hangi beklenen sonuçla sınanacağını tanımlar. Senaryolar saklanır; sonradan bir hata çıktığında o modülün daha önce hangi verilerle test edildiğine geri dönülebilir.
- Test ekibi geliştiricilerden bağımsız olmalıdır. Test arttıkça maliyet yükselir, kaçırılan hata sayısı düşer; ikisinin kesiştiği nokta optimum test miktarıdır ve bundan sonra ihmal edilebilir sayıda hata kalır. Test etkinlikleri yaşam döngüsünün her evresine yayılır: planlamada sistem test ve kalite planı, analizde alt sistem planları, tasarımda modül test planı, gerçeklemede birim, bütünlük ve sistem testi, kurulumda kullanıcı testi ve raporlar.
- Teslimden sonra kalite, bakım ve konfigürasyon yönetimiyle sürdürülür. Bakım hata düzeltme, iyileştirme ve uyarlama işlerinden oluşur ve geliştirme maliyetini aşabilir; bu yüzden yazılım baştan bakım yapılabilir (maintainability) tasarlanmalıdır. Konfigürasyon yönetimi ise kod, belge ve veri yapılarından oluşan yazılım konfigürasyonunu tanımlar, değişiklikleri kontrol eder, denetler ve raporlar; sürüm yönetimiyle birlikte yürür ve IEEE 828, IEEE 1042 ve ISO 9004 gibi standartlara dayanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
