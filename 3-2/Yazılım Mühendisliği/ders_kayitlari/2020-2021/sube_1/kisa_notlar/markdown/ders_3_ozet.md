# Ders 3 Çalışma Özeti

## Genel Konular

- Klasik süreç modellerinin tekrarı
  - Şelale (waterfall, lineer) modeli: bir aşama bitmeden diğerine geçilmez.
  - Prototip modeli: analiz ve tasarım sırasında müşteriyle üzerinde deneme yapılacak bir ön ürün geliştirilir, son ürün bu denemelerden sonra geliştirilir.
  - Spiral model: şelale ile prototipin karışımıdır ve risk analizini sürece katar. Altı alt adım (müşteriyle iletişim, planlama, risk analizi, modelleme, construction, dağıtım ve müşteri değerlendirmesi) prototip, ürün, ürünü zenginleştirme ve bakım evrelerinin her birinde tekrarlanır. Artımlı ve evrimsel bir modeldir; daha çok hata kritik ürünlerde kullanılır.
  - RAD (Rapid Application Development): rekabete dayalı, hızlı geliştirilmesi gereken bir ürün için kurumun olanakları varsa aynı anda birden fazla ekiple paralel geliştirme yapılır.
  - Unified Process (ekrandan, 00:05:00 ve 00:10:00): iletişim, planlama, modelleme, construction ve dağıtım etkinlikleri inception, elaboration, construction ve transition evrelerine dağılır; çıktısı yazılım artımıdır (software increment). Nesneye yönelik uygulamalara uygundur ve Rational araçlarıyla birlikte kullanılmaya yatkın olarak tanıtılır.
- Evrelerin ürünleri (ekrandan, 00:10:00)
  - Inception: vizyon belgesi, başlangıç use case modeli, başlangıç proje sözlüğü, iş durumu (business case), başlangıç risk değerlendirmesi, evreleri ve iterasyonları içeren proje planı, gerekirse iş modeli, bir ya da daha fazla prototip.
  - Elaboration: use case modeli, işlevsel olmayanlar dahil ek gereksinimler, analiz modeli, yazılım mimarisi tanımı, çalıştırılabilir mimari prototip, ön tasarım modeli, gözden geçirilmiş risk listesi, iterasyon planı ve kilometre taşlarını içeren proje planı, ön kullanıcı kılavuzu.
  - Construction: tasarım modeli, yazılım bileşenleri, bütünleştirilmiş yazılım artımı, test planı ve prosedürü, test durumları, kullanıcı ve kurulum kılavuzları gibi destek belgeleri.
  - Transition: teslim edilen yazılım artımı, beta test raporları, genel kullanıcı geri beslemesi.
- Çevik (agile) yaklaşımların ortaya çıkışı
  - Çevik yaklaşımlar, artan müşteri taleplerini daha hızlı karşılamak için geleneksel modellere alternatif olarak ortaya çıkmıştır; geliştirme sırasında geç ortaya çıkan gereksinim değişikliklerini çabuk karşılamayı esas alan modellere verilen genel addır (ekrandan, 01:25:00).
  - Çevik yaklaşım tek başına bir süreç modeli değildir; çevik yaklaşımla oluşturulmuş çok sayıda süreç modeli vardır. Derste XP, Scrum ve Kanban ele alındı.
- Çevik manifestonun 12 ilkesi (ekrandan, 00:15:00 ve 00:20:00)
  - Değerli yazılımın erken ve sürekli teslimiyle müşteri memnuniyeti, geliştirmenin geç evrelerinde bile değişen gereksinimlere açık olmak, çalışan yazılımı sık teslim etmek.
  - İş insanları ile geliştiricilerin proje boyunca her gün birlikte çalışması, motive bireylere güvenmek, en etkili iletişim yolunun yüz yüze konuşma olması.
  - İlerlemenin temel ölçüsünün çalışan yazılım olması, sürdürülebilir bir hız, teknik mükemmelliğe ve iyi tasarıma sürekli dikkat.
  - Basitlik (yapılmayacak işi en çoğa çıkarma sanatı), kendi kendini örgütleyen ekipler, ekibin düzenli aralıklarla kendini değerlendirip davranışını ayarlaması.
- Geleneksel modellere göre çevik modellerde kalite (ekrandan, 00:35:00)
  - Dinamik kalite değerlendirme (gerçek veriyle test) statik değerlendirmeden (gözden geçirme) daha fazla uygulanır.
  - Kalite işlemleri sürecin daha erken adımlarında başlar ve daha kısa aralıklarla yapılır.
  - Kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle doğruluk ve süreklilik sağlanır.
- Çevik ekip yapısı
  - Yüz yüze iletişim, ekip üyelerinin çevik yaklaşım konusunda eğitilmesi, müşteriyle ve birbirleriyle sürekli iş birliği, karşılıklı saygı ve güven.
  - Proje yöneticisi kalkmaz, koordinatör gibi çalışır; ekip kendi kendini düzenler, süreci yerel ortama uyarlar ve artımların zamanlamasını kendisi belirler.
- Çevik süreçlerin dört karşıtlığı (ekrandan, 00:40:00)
  - Bireyler ve etkileşimler / süreçler ve gereçler; çalışan yazılım / ayrıntılı belgeler; müşterinin sürece katılımı / sözleşme pazarlığı; değişikliklere uyum sağlamak / bir planı izlemek.
  - Çevik süreçler sağdaki maddelerin yararını kabul eder ama soldakilere daha çok önem verir. İlerleme olmadan yalnızca uyum sağlamak başarı değildir: artımsal gelişim, erken ve sık teslim, başarımın birincil ölçütü doğru çalışan yazılım.
- Extreme Programming (XP)
  - Dört temel değer: basitlik, iletişim, geri besleme, cesaret (sonradan saygı da eklenir).
  - Özellikler: planlama oyunu, küçük ve kısa aralıklı yayımlar, sistem metaforu, basit tasarım, test, refactoring, eşli programlama, ortak kod mülkiyeti, sürekli bütünleştirme, sürdürülebilir hız, ekip üyesi müşteri, kodlama standartları.
  - Adımlar: planlama, tasarım, kodlama, sınama; her döngü bir artımsal ürün verir (ekrandan, 01:10:00).
  - Planlama: müşteri kullanıcı öykülerini yazar ve önemine göre derecelendirir; yaklaşık 3 haftada gerçeklenemeyecek öyküler alt öykülere bölünür; önce yüksek riskli ya da yüksek öncelikli öyküler gerçeklenir. İlk artım projenin hızını ölçmek için kullanılır ve sonraki teslim tarihleri buna göre belirlenir.
  - Tasarım: basit tasarım, CRC kartları, gerektiğinde prototip (spike solution) ve refactoring.
  - Kodlama: eşli programlama. Sınama: birim test, sürekli bütünleştirme, kabul testi ve test güdümlü geliştirme.
- CRC (Class, Responsibility, Collaboration) kartları (ekrandan, 01:15:00)
  - Her sınıf için adı, açıklaması, üst ve alt sınıfları, sorumlulukları ve iş birliği yaptığı sınıflar yazılır. Örnek: kasada yapılan ödemeyi simgeleyen Satış sınıfı.
- Test güdümlü yazılım geliştirme (TDD) (ekrandan, 01:20:00)
  - Küçük ve hızlı iterasyonlarla, araçlarla hazırlanmış testler yazılarak ilerlenir; çevik yaklaşımlara uygundur.
  - Önce birim test durumları yazılır; kod olmadığı için ilk başta başarısız olurlar. Kod yazıldıkça testler tekrar tekrar koşturulur ve geçtikleri görülür, gerekirse kod yeniden düzenlenir.
- Scrum (ekrandan, 01:05:00 ve 01:40:00)
  - Adımlar: görev listesi, koşu (sprint), işlev gösterimi; döngü görev listesine geri döner.
  - Görev listesi, önceliklendirilmiş kullanıcı öyküleridir. Koşuda listeden bir madde seçilir ve önceden belirlenmiş kısa bir sürede (örneğin 1-4 hafta) gerçeklenir.
  - Koşu süresince proje liderinin yönettiği günlük kısa toplantılar (örneğin 15 dakika) yapılır. Üç soru: son toplantıdan bu yana ne yaptınız, karşılaştığınız engeller nelerdi, yarınki toplantıda neleri başarmayı hedefliyorsunuz.
  - İşlev gösterimi: müşterinin en yeni işlevi ya da o ana kadar gerçeklenen tüm işlevleri sınaması.
  - Roller: Product Owner (ürün sahibi), Scrum Master, geliştirme ekibi. Ürün sahibi ürün backlog'unu oluşturur, takım ve ürün sahibi her sprintte yapılacak işleri ayırır, sprint sonunda sprint review yapılır.
- Scrum ile diğer modellerin karşılaştırması (ekrandan, 02:10:00)
  - Şelale, spiral, iteratif ve Scrum; tanımlı süreçler, final ürün, maliyet, tamamlanma tarihi, dış çevreye duyarlılık, takım esnekliği, bilirkişi desteği ve başarı olasılığı ölçütlerine göre karşılaştırıldı (tablo Detaylı Açıklamalar'da).
- Kanban (ekrandan, 02:15:00)
  - Az sayıda görevi akıcı ve eş zamanlı yönetmeyi sağlar; ilk kez Japonya'da Toyota'da kullanılmıştır; "sinyal" ya da "büyük görsel tahta" anlamındadır.
  - Evrimsel değişim çerçevesidir. İlkeler: müşteri ihtiyaçlarını anla ve odaklan, insanları değil işi yönet, ekosistemi sürekli gözden geçir. İş listesinde sürekli değişiklik varsa Kanban tercih edilir.
  - Tahtada işler sütunlar boyunca ilerler: yapılacaklar (to do), planlananlar, geliştirilenler, test edilenler, dağıtıma hazır olanlar ve tamamlananlar (done).
- XP, Scrum ve Kanban karşılaştırması
  - Kanban'da rol yoktur ve mevcut plan değiştirilebilir; Scrum'da roller net tanımlıdır ve sprint içindeki değişiklik daha zordur; XP'de müşteri ve ekip vardır, bir özellik başka bir iterasyonda değiştirilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çevik süreçler sektörde çok kullanıldığı için kavramların yerleşmesi
  - Hoca konuları bilerek tekrar tekrar anlattığını, çevik kavramların mezuniyet sonrası iş hayatında da sorulduğunu belirtti.
- Çevik demek belgesiz çalışmak değildir
  - Gerekli belgeler yine hazırlanır; yalnızca amacı belirsiz, çok ayrıntılı belgeler yerine çalışan yazılım ve bakım için gerekli belgeler üretilir. Analiz ve tasarım gözden çıkarılmaz.
- Müşteri ekibin bir parçasıdır
  - Klasik modellerde müşteriye analizden ve tasarımdan sonra sorulur; çevikte müşteri tarafından seçilen temsilciler sürekli ekibin içindedir.
- Plan dinamiktir
  - Plan kısa aralıklarla izlenir ve değişikliklere göre güncellenir; XP'de ilk artımla ölçülen proje hızına göre sonraki teslim tarihleri yeniden belirlenir.
- XP artımlı bir süreç modelidir
  - Hoca öğrenciden duymak istediği özelliğin bu olduğunu söyledi: kısa aralıklı yayımlar, hataların erken test edilmesi.
- Scrum en yaygın kullanılan çevik modeldir
  - XP ilk kullanılan çevik model, Scrum ise sektörde en çok kullanılandır; doğru uygulayanlar da yalnızca adını kullananlar da vardır. Çevik yaklaşımın gerçek çözüm olup olmadığı akademik çalışmalarda sorgulanmaktadır.

## Kısa Tekrar Notları

- Çevik yaklaşım: geç gelen gereksinim değişikliklerini çabuk karşılamayı esas alan modellerin genel adı.
- Çevik manifesto: 12 ilke; dört karşıtlık (bireyler/süreçler, çalışan yazılım/belgeler, müşteri katılımı/sözleşme, değişime uyum/plan).
- Çevik kalite: daha fazla dinamik test, erken başlayan ve sık yapılan kalite etkinlikleri.
- XP değerleri: basitlik, iletişim, geri besleme, cesaret (+saygı).
- XP döngüsü: planlama (kullanıcı öyküleri, kabul test kriterleri, iterasyon planı) → tasarım (basit tasarım, CRC, spike/prototip) → kodlama (eşli programlama, refactoring) → test (birim test, sürekli bütünleştirme, kabul testi) → yayım (yazılım artımı, proje hızı hesaplanır).
- CRC: Class, Responsibility, Collaboration.
- TDD: önce test, testler başta başarısız, kod yazıldıkça geçer, gerekirse yeniden düzenleme.
- Scrum: görev listesi → koşu (1-4 hafta) → işlev gösterimi; günlük 15 dakikalık ayakta toplantı ve üç soru.
- Scrum rolleri: Product Owner, Scrum Master, geliştirme ekibi.
- Kanban: Toyota kökenli, büyük görsel tahta, insanları değil işi yönet, rol yok, sürekli değişen iş listesine uygun.

## Detaylı Açıklamalar

- Unified Process diyagramı (ekrandan, 00:05:00) iletişim, planlama, modelleme, construction ve dağıtım etkinliklerini bir döngü olarak gösterir. Inception evresi iletişim ve planlamayı, elaboration planlama ve modellemeyi, construction ve transition ise construction ile dağıtım etkinliklerini kapsar; döngünün çıktısı yazılım artımı olarak üretime (production) verilir. Transition evresinde kullanıma alınan artımın beta test raporları ve kullanıcı geri beslemeleri değerlendirilir.
- Çevik manifestonun ilkeleri derste orijinal İngilizce metin üzerinden okundu. Hocanın vurguladığı noktalar: geliştiricilerin ve müşterinin aynı projede bir arada çalışması, iş bir evreden diğerine kağıt üzerinden devredildiğinde sonradan soru sormanın verimsizliği, belgeleme kurallarının çok sıkı olduğu klasik modellere karşılık temel ölçünün çalışan yazılım olması, işe mümkün olduğunca basit bir tasarımla başlayıp ayrıntıyı sonraki evrelere bırakmak ve ekibin düzenli aralıklarla kendini değerlendirmesi. Bu iç değerlendirmeler XP'de ve Scrum'da farklı toplantı yapılarıyla gerçekleştirilir.
- XP'nin özellikleri arasında ortak kod mülkiyeti, analistin, tasarımcının ve programcının yalnız kendi işini değil ürünün tamamında ne yapıldığını bilmesi olarak açıklandı. Sürdürülebilir hız, ekip üyelerinin haftalık çalışma süresinin sınırlı tutulmasıdır. <!-- BELİRSİZ: haftalık saat sınırı altyazıda düştü; slayt önizlemesinde "40 saat / hafta" gibi okunuyor ama önizleme küçük. -->
- XP döngüsü (ekrandan, 02:05:00) şöyle aktarılabilir:

```text
planlama : kullanıcı öyküleri, değerler, kabul test kriterleri, iterasyon planı
   |
tasarım  : basit tasarım, CRC kartları, spike çözümler (prototipler)
   |
kodlama  : eşli programlama, refactoring (kodlama ile tasarım arasında döngü)
   |
test     : birim test, sürekli bütünleştirme, kabul testi
   |
yayım    : yazılım artımı, proje hızı hesaplanır --> planlamaya geri dönülür
```

- Eşli programlamada iki programcı aynı bilgisayar başındadır; biri kodu yazarken diğeri gözden geçirir ve gerektiğinde müdahale eder. Kodlama sırasında birim test yapılır, tamamlanan parça diğerleriyle bütünleştirilir (sürekli bütünleştirme), müşteri kabul testini yapar ve yeni bir yayım çıkar.
- Örnek CRC kartı (ekrandan, 01:15:00):

| Satış sınıfı | |
|---|---|
| Açıklama | Kasada yapılan ödemeyi simgeleyen sınıf |
| Üst sınıf(lar) | Yok |
| Alt sınıf(lar) | Yok |
| **Sorumluluk** | **İşbirlikçi** |
| Satışın yapıldığı tarih ve saati saklamak | |
| Yapılan ödeme tutarını saklamak | Ödeme |
| Satılan malların listesine erişim | Mal |

- TDD konusunda hoca, bu alanda araştırma yapan bir akademisyenin çalışmalarına göre TDD'nin programcı üretkenliğini artırdığını ama kalite açısından çok büyük fark yaratmadığını, programcıyı kodu ve test sonuçlarını saklamaya teşvik ettiğini aktardı.
- Scrum'da hafta başındaki toplantıda o hafta hangi use case'lerin çalışır hale getirilip test edileceği belirlenir ve iş dağıtımı yapılır. Günlük toplantılarda herkes kendisine verilen işlerin ne kadarını tamamladığını, karşılaştığı engelleri ve sıradaki işleri söyler; herkes birbirine karşı sorumludur. Toplantılar kısa olsun diye ayakta yapılır ve motive edici olmalıdır. Adı, rugby'de oyuncuların kısa ve itici güç yaratan toplanmasından gelir. Toplantılar iç içe döngüler gibidir: günlük (24 saatlik) işler, en fazla 30 günlük sprint işleri ve ürün backlog'u.
- Scrum ve diğer modeller tablosu (ekrandan, 02:10:00):

| Kriter | Waterfall | Spiral | İteratif | Scrum |
|---|---|---|---|---|
| Tanımlı süreçler | Gerekli | Gerekli | Gerekli | Planlama ve kapatma aşamasında |
| Final ürün | Planlamada tanımlanmış | Planlamada tanımlanmış | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Proje maliyeti | Planlama esnasında hesaplanıyor | Kısmen değişken | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Tamamlanma tarihi | Planlama esnasında belirleniyor | Kısmen değişken | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Dış çevreye duyarlılık | Sadece planlamada | Planlama öncelikli | İterasyon sonlarında | Her zaman |
| Takım esnekliği, yaratıcılığı | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | İterasyonlar boyunca yaratıcılıkta ve esneklikte limit yok |
| Bilirkişi desteği (harici) | Proje eğitimi esnasında | Proje eğitimi esnasında | Proje eğitimi esnasında | Gerekirse proje içinde takıma bile dahil edilebiliyor |
| Başarı olasılığı | Düşük | Orta düşüklükte | Orta seviye | Yüksek |

- Hoca, şelalede planlamada verilen tarih ve maliyet tutmadığı için projenin başarısız görünebildiğini, Scrum'da ise maliyetin proje ilerledikçe şekillendiğini ve bir süre sonra gerçekçi bir fikir verilebildiğini açıkladı. Scrum'da kod ve yapılan işler anonimdir, herkes her konuyu bilir; bu bir kişinin analizden teste ya da tasarıma kaydırılabilmesi anlamına gelir. Başarı olasılığı Scrum'da yüksek görünse de yüzde yüz değildir ve projeye göre değişir.
- Kanban 1940'ların sonlarından beri üretim yönetiminde kullanılan bir felsefedir; süpermarket raflarındaki stok takibinden esinlenerek üretim bandındaki kaynakları görselleştirmek için geliştirilmiş, zamanla bir kalite modeline dönüşmüş ve 2000'li yıllardan itibaren çevik yazılım süreçlerinde kullanılmaya başlanmıştır. Tahtada farklı renkli yapışkan notlar kullanılır: hocanın verdiği örnekte kullanıcı hikayeleri mor, görevler turkuaz, işle ilgili özellikler kırmızı. <!-- BELİRSİZ: Kanban tahtası görseli karelerde yok; sütunlar ve renkler altyazıdan aktarıldı. -->
- Son karşılaştırmada Kanban'da çok görevliliği ve boşa geçen zamanı azaltmak ile müşteri ihtiyaçlarını en öncelikli değerlendirmek; Scrum'da ekibin ortak kararı, her sprintte doğru olanı yapma cesareti, zorluklara karşı açık sözlülük ve saygı; XP'de iletişim, basitlik, geri bildirim, cesaret ve saygı değerleri öne çıkarıldı.

- Ders sonrası not: Hoca çevik manifestonun 1999-2000 yıllarında ortaya çıktığını söyledi; Agile Manifesto büyük olasılıkla Şubat 2001'de yayımlanmıştır. Hoca Scrum adını "Amerikan rugby futbolu" toplantılarına bağladı; terim büyük olasılıkla rugby union'daki "scrum" (hücum düzeni) toplanmasından gelir, Amerikan futbolundan değil.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
