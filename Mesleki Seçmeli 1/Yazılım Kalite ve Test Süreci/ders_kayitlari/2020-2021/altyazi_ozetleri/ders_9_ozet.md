# Ders 9 Çalışma Özeti

## Genel Konular

- Vize sonrası değerlendirme: geç yüklenen kağıtlar ve final sınavının yapısı.
- Yazılım kalite iyileştirme (software process improvement) kavramı.
- Standartların sınıflandırılması: kaynağa göre ve geliştirme sürecine göre.
- Yazılım geliştirme ortamı sertifika sistemleri: CMMI, SPICE, ISO.
- CMMI (Capability Maturity Model Integration) olgunluk düzeyleri.
- CMMI anahtar süreç alanları (key process areas).
- Türkiye'den CMMI örnekleri ve üniversite akreditasyonuyla benzetme.
- People CMM: çalışanlara yönelik yetenek olgunluk modeli ve düzeyleri.
- Çevik (agile) yaklaşımlar ve XP'nin dört temel değeri.
- Çevik modellerde kalite: geleneksel modellerle farklar.
- Statik ve dinamik doğrulama (static / dynamic verification).
- Test güdümlü yazılım geliştirme (Test Driven Development, TDD).
- Proje takvimi: test raporlarının teslim haftaları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Vize süresi, kağıda yazıp tarayıp yükleme dahil yeterliydi.
- Süre bittikten sonra yükleyenler ve mail ile gönderenler, gecikme süresine göre daha düşük baremden notlandırılacak.
- Vize ilk sınav olduğu için yorum sorusu azdı. Finalde daha kıyaslamalı ve mühendis olarak yorum katmanızı isteyen sorular gelebilir.
- CMMI süreç odaklı bir kalite yaklaşımıdır. Ürünün kalitesini ağırlıkla onu üreten sürecin kalitesi belirler.
- Yeni kurulmuş bir yazılım ekibi CMMI sertifikası alamaz. Hem yetkinlik hem olgunluk gerekir; belli bir proje arşivi olmalıdır.
- Sertifika kalıcı değildir. Kurum belli aralıklarla yeniden ölçülür. Düzeyi korumak süreklilik ister.
- 2. düzeyde konfigürasyon yönetimi mutlaka yapılmalıdır.
- 3. düzeyin en önemli farkı risk yönetimidir. Risk yönetimi bütün projelerde yapılmalıdır.
- 4. düzey yalnız ölçüm yapmak değildir. Ölçümler arşivlenmeli ve yeni projelerin tahmininde kullanılmalıdır.
- 5. düzeyde yenilikçilik ve sürekli süreç iyileştirmesi aranır.
- Statik doğrulamaya örnek inceleme (inspection), yani kod incelemedir (code inspection). Test dinamik doğrulamadır.
- Çevik modellerde dinamik kalite değerlendirmesi (test) statik değerlendirmeden daha çok uygulanır.

## Kısa Tekrar Notları

- Standart sınıflandırması: kaynağa göre (IEEE, ISO, DoD) ve desteklediği süreç adımına göre (plan, gereksinim, tasarım).
- IEEE 830: kaynağı IEEE olan, yazılım gereksinim analizini kontrol altında tutan standart. Projede SRS bununla yazıldı.
- Kalite sağlama sırası: standartlar ve süreç modeli seçilir; geliştirirken gözden geçirme, inceleme ve test yapılır; konfigürasyon yönetimi ve ölçüm arşivi oluşturulur.
- Sertifika sistemleri: CMM / CMMI (ABD), SPICE (Avrupa), ISO 9000 ailesi.
- Süreç iyileştirme döngüsü: ölç, analiz et, değiştir, yeniden ölç.
- CMMI düzeyleri:
  - 1 Başlangıç (Initial),
  - 2 Yönetilen (Managed),
  - 3 Tanımlı (Defined),
  - 4 Sayısal Yönetilen (Quantitatively Managed),
  - 5 En İyileştiren (Optimizing).
- 4. düzeyin anahtar alanı niceliksel (sayısal) proje yönetimidir.
- 5. düzeyin anahtar alanları kurumsal yenilenme ve yaygınlaştırma ile nedensel analiz ve çözümlemedir.
- People CMM düzeyleri: Başlangıç, Tekrarlanabilir, Tanımlı, Yönetilen, En İyileşen.
- XP'nin dört değeri: basitlik, iletişim, geri besleme, cesaret.
- TDD: önce birim test senaryosu yazılır, test başarısız olur, kod yazılarak test geçirilir, gerekirse kod yeniden düzenlenir.

## Detaylı Açıklamalar

### Vize Sonrası Değerlendirme

- Hoca kağıtlara genel olarak baktı, notlandırmayı tamamlamadı.
- Boş kağıt görünen veya farklı dosya gönderen öğrenciler oldu. Hoca hepsini dikkate alacağını söyledi.
- Proje grupları bir Word dosyasına işlendi. Dosya ders sonrası dokümanlar sayfasına yüklenecek. Herkes kendi grubunu kontrol etmeli.

### Kalite İyileştirmeye Giriş: Standartlar

- Kalite sağlamak için standartlar konur ve bunlara uyularak yazılım geliştirilir.
- Standartlar iki şekilde sınıflandırılır:
  - Kaynağa göre: standardı oluşturan ve destekleyen kurum (IEEE, ISO, DoD).
  - Yazılım geliştirme sürecine göre: hangi süreç adımını desteklediği (geliştirme planı, gereksinim, tasarım belgeleri).
- IEEE standartlarında iki sınıflandırma da görülür.
- Projede IEEE 830 standardı özetlenerek kullanıldı.
- Kurumlar sertifikasyona doğrudan başvurmadan da listedeki koşullara bakarak kendilerini iyileştirebilir.

### Sertifika Sistemleri

- CMM ve CMMI ABD menşelidir. CMMI, CMM'nin ilerlemiş hâlidir.
  - Açılım: Capability Maturity Model, yetenek olgunluk modeli.
- SPICE Avrupa'da yazılım sürecinin iyileştirilmesi için kontrol adımları tanımlar.
  - CMMI ile aynı işi yapar. Uygulama şekli ve hitap ettiği yerler farklıdır.
- ISO da proje yönetimi ve gerçekleştirme süreçleriyle ilgili tanımlar yapmıştır (ISO 9000 ailesi).
- CMMI'nin tanımı:
  - Etkin bir yazılım sürecinin anahtar elemanlarını tanımlayan çerçeve modeldir.
  - Süreç olgunluğunu değerlendirmek için bir ölçüm aracıdır.
- CMMI ABD'de Carnegie Mellon Üniversitesi'ndeki Software Engineering Institute (SEI) merkezli başlatıldı.
  - Bazı ülkelerde temsilciler aracılığıyla başvuru yapılır.
  - Başvuran kurum denetlenir ve hangi düzeyin koşullarını sağladığına karar verilir.

### Neden Sertifika?

- Bazı ihalelere girmek için belli bir düzey sertifikası istenir.
- Askeri ihalelere girmek için firmaların CMMI 3. düzeyde olması gerekir.
- Geliştirilen yazılımın güvenirliğini göstermek için de istenir.
- Hoca bunu üniversite akreditasyonuna benzetti:
  - Türkiye'de MÜDEK, uluslararası alanda ABET akreditasyonu.
  - Bölüm, mezunlarının dışarıda kabul görmesi için denetimden geçer.
  - Belli süre sonra yeniden değerlendirilir.
- "Çok iyi bir yazılım eviyiz" demek ile "CMMI şu düzeydeyiz" demek farklıdır. İkincisi ölçülebilir bir değerlendirmeye dayanır.

### CMMI Olgunluk Düzeyleri

| Düzey | Ad | Özellik |
| --- | --- | --- |
| 1 | Başlangıç (Initial) | Süreç gelişigüzel ve kaotik; kişisel gayrete bağlı; krizde planlar terk edilir; süreç yetenekleri önceden kestirilemez |
| 2 | Yönetilen (Managed) | Proje yönetimi kontrolleri kurulmuştur; projeler belgelenmiş planlara göre yürür; gereksinimler yönetilir; ölçüm yapılır; konfigürasyon yönetimi zorunludur |
| 3 | Tanımlı (Defined) | Süreçler iyi tanımlanmış ve anlaşılmıştır; kurum bazında tutarlıdır; tüm projelerde uyarlanmış standart süreç kullanılır; risk yönetimi yapılır |
| 4 | Sayısal Yönetilen (Quantitatively Managed) | Önemli alt süreçler istatistiksel ve nicel tekniklerle kontrol edilir; kalite ve süreç performansı için sayısal hedefler konur |
| 5 | En İyileştiren (Optimizing) | Sayısal geri besleme ve yeni teknolojilerle sürekli süreç iyileştirmesi; yenilikçilik |

- Düzeyler basamak basamak çıkılır. Bir kurum doğrudan 4. düzeyi hedefleyemez.
- Üst düzey alt düzeyin koşullarını da sağlar. 3. düzeydeki kurumda proje, gereksinim ve konfigürasyon yönetimi zaten vardır.
- 3. düzeyde risk yönetiminin anlamı: şu an sorun olmasa da ileride sorun çıkarabilecek kaynakları araştırıp tüm projelerde izlemektir.
- 4. düzey ile önceki düzeylerin farkı:
  - 2. ve 3. düzeyde de ölçüm yapılır.
  - 4. düzeyde ölçümlerden bir arşiv oluşur.
  - Yeni proje başlarken büyüklük tahmin edilir. Arşivdeki benzer büyüklükteki projelerin maliyetine bakılır.
- 5. düzeyde sorulanlar:
  - Süreçten gelen sayısal geri beslemelerle sürekli iyileştirme yapılıyor mu?
  - Çalışanların ürettiği yeni fikirler değerlendiriliyor mu?
  - Kurum sürekli değişen süreçler içinde mi?

### Türkiye'den Örnekler

- Hata toleransı düşük alanlarda (özellikle askeri projeler) CMMI 3 sertifikası gerekir.
- Hocanın verdiği örnekler:
  - Askeri yazılım üreten firmalara test yapan TÜBİTAK MAM 4. düzey sertifika almıştı.
  - Huawei'de ve Aselsan'da sertifikasyon çalışmaları var.
  - Bankacılık uygulamaları geliştiren Cybersoft 4. düzeydeydi.
  - Milsoft yıllardır 5. düzeyde.
- Milsoft'un projelerinde teslim süreleri diğer firmalara göre daha uzun. 5. düzeyi sürdürmek için kanıt belgeleri hazırlamak gerekiyor.
- Hoca, bu bilgilerin sürekli takip edilmesi gerektiğini söyledi. Üç yıl önceki düzey bugün geçerli olmayabilir.

### CMMI Anahtar Süreç Alanları

- Anahtar süreç alanı: bir düzeye ulaşmak için yazılım geliştirme sürecinde yapılması gereken işler.

| Düzey | Anahtar süreç alanları |
| --- | --- |
| 1 Başlangıç | Yok (işler bireysel çabaya bağlı) |
| 2 Yönetilen | Gereksinim yönetimi, proje planlama, proje izleme ve kontrol, tedarikçi sözleşme yönetimi, ölçümleme ve analiz, süreç ve ürün kalite güvencesi, konfigürasyon yönetimi |
| 3 Tanımlı | Gereksinimleri geliştirme, teknik çözüm, ürün entegrasyonu, doğrulama ve onaylama, kurumsal süreç tanımlama ve odaklanma, kurumsal eğitim, entegre ürün ve süreç geliştirme (IPPD) için tümleşik proje yönetimi, risk yönetimi, entegrasyon için kurumsal altyapı |
| 4 Sayısal Yönetilen | Kurumsal süreç başarımı, niceliksel proje yönetimi |
| 5 En İyileştiren | Kurumsal yenilenme ve yaygınlaştırma, nedensel analiz ve çözümleme |

- 2. düzeyde ölçüm vardır ama süreklilik yoktur. Sonraki projede eski ölçümlere dayanarak tahmin yapılmaz.
- 3. düzeyde 2. düzeyin işleri kurumsal hâle gelir. Bütün projelerde aynı şekilde izlenir.
- 3. düzeyde ürün entegrasyonu: geliştirilen ürünlerin birbiriyle uyumlu ve birlikte çalışabilir olması.
- 4. düzeyin en önemli alanı sayısal proje yönetimidir.
- 5. düzeyde yeni teknolojilere, yöntemlere ve süreç modellerine ne kadar yaklaşıldığına bakılır.

### CMMI'de Süreç Alanı Grupları

- Eskiden kurumun proje yönetimi, mühendislik ve destek düzeyleri ayrı ayrı seviyelendirilirdi.
- CMMI'de (Integration) gruplar arasında etkileşim vardır. Süreç alanları dört gruba ayrılır:
  - süreç yönetimi,
  - proje yönetimi,
  - mühendislik,
  - destek.
- Destek süreç alanları iki gruptur:
  - Temel destek: ölçümleme ve analiz, kalite sağlama, konfigürasyon yönetimi.
  - İleri destek: kurumsal entegrasyon altyapısı, nedensel analiz ve çözümleme, karar analizi ve çözümleme.

### People CMM

- People CMM, insanlarla ilgili konuları tanımlayıp iyileştirmek isteyen kurumlar için geliştirildi.
- Hocaya göre çalışanlar kurumun işlerinden ayrı görülemeyeceği için People CMM de CMMI'nin içine katıldı.
- Hedefleri:
  - yazılım geliştirme yeteneğini tanımlamak ve sağlamak,
  - iş gücünün yeteneklerini artırarak kurumun yeteneğini artırmak,
  - sürekli iyileştirme içine girmek,
  - çalışanın ve kurumun hedeflerini birlikte tutmak,
  - insan değerlerini elde tutmak.

| Düzey | Ad | Süreç alanları |
| --- | --- | --- |
| 1 | Başlangıç | Kaotik ortam; çalışanlara yalnız ürettikleri iş açısından bakılır; performans yönetimi ve eğitim yoktur |
| 2 | Tekrarlanabilir (Repeatable) | Tazminat, eğitim, performans yönetimi, işe alım, iletişim, ergonomik çalışma ortamı |
| 3 | Tanımlı (Defined) | Katılımcı kültür, yeteneğe bağlı pratikler, kariyer geliştirme, yetenek geliştirme, iş gücü planlama, bilgi ve beceri analizi |
| 4 | Yönetilen (Managed) | Kurumsal performans ayarlama, kurumsal yetenek yönetimi, takım temelli pratikler, ekip kurma, danışmanlık (mentoring) |
| 5 | En İyileşen (Optimizing) | Sürekli iş gücü inovasyonu, koçluk (coaching), kişisel yetenek geliştirme |

- 2. ve 3. düzey farkı:
  - 2. düzeyde kurumdaki işlerle ilgili eğitimler verilir.
  - 3. düzeyde eğitimler çalışanların kariyer planına ve kazandırılacak yeteneklere göre planlanır.
  - 3. düzeyde ekip elemanı seçiminde yetenekler dikkate alınır. Şirket kültürü aranır.
- 4. düzeyde çalışanların ekip kurma becerisi ve ekip yapısı önemlidir.
  - Hoca, firmaların ekip çalışması ve ortak proje geliştirme tarafı güçlü mezunlar istediğini söyledi.
- 5. düzeyde sürekli iş gücü inovasyonu yaratıcılık demektir.
  - Firmalar yukarıdan verilen projelerin yanında çalışanların önerdiği projelere de imkân tanır.
  - Koçluk sistemiyle kişilere yeni yetenekler kazandırılır.

### Çevik Yaklaşımlar ve XP

- Çevik yaklaşımlar artan müşteri taleplerini daha hızlı karşılamak için geleneksel modellere alternatif olarak çıktı.
- Gereksinim değişimlerine hızlı uyum sağlarlar. Müşteri yazılım ekibinin içinde yer alır.
- Derste anılan çevik modeller: Scrum, XP, Kanban.
- XP dört temel değer üzerine kuruludur: basitlik, iletişim, geri besleme, cesaret.
- XP pratikleri:
  - planlama oyunu,
  - küçük ve kısa aralıklı sürümler (release),
  - sistem metaforu,
  - basit tasarım,
  - test odaklılık,
  - devamlı yeniden tasarım (refactoring),
  - eşli programlama (pair programming),
  - ortak kod mülkiyeti,
  - sürekli tümleştirme (continuous integration),
  - devam ettirilebilir hız (haftada 40 saat),
  - müşterinin ekip üyesi olması,
  - kodlama standartları.
- Devam ettirilebilir hız People CMM kurallarıyla örtüşür. Fazla mesai yoktur; süreklilik sağlanır.
- Scrum ile XP farkı (hocanın anlatımı):
  - Scrum XP'den sonra geliştirildi.
  - Scrum'da koşu (sprint) vardır, süresi yaklaşık iki haftadır. Her koşuda tanımlanan işler eklenerek ilerlenir.
  - XP'de küçük artımlarla yeni sürümler çıkar. Artımlı (incremental) geliştirme ve sürekli tümleştirme vardır.

### Çevik Modellerde Kalite

- Geleneksel modellere göre farklar:
  - Dinamik kalite değerlendirmesi (test) statik değerlendirmeden daha çok uygulanır.
  - Kalite işlemleri sürecin daha erken adımlarında başlar. Test planlaması baştan yapılır.
  - Kalite aktiviteleri daha sık yapılır. Her küçük parça geliştirildiğinde test edilir.
  - Kullanıcı hikâyeleri (user story), birim testler ve müşteri geri beslemesiyle doğruluk ve süreklilik sağlanır.
- Geleneksel modellerde test geliştirmenin sonuna doğru yapılır.
- Statik doğrulama (static verification): program çalıştırılmadan kod üzerinden yapılan analiz.
  - Ders içi örnek: inceleme (inspection), kod inceleme (code inspection).
  - Test çalıştırarak yapılır, dinamiktir.
- Bir öğrencinin sorusu: kod üzerinde analiz ile inceleme aynı şey değil mi?
  - Hoca: inceleme daha ayrıntılı bir değerlendirmedir. "Analiz" denince gözden geçirme (review) de anlaşılabilir.
  - Derste statik doğrulama örneği olarak verilen ad inceleme (inspection) olduğu için bu ad beklendi.

### Test Güdümlü Yazılım Geliştirme (TDD)

- TDD, çevik modellerdeki kalite farklarını sağlayacak şekilde çalışan bir geliştirme yaklaşımıdır.
- Gereksinim analizinde bir kullanıcı senaryosu (use case) oluşturulur. Hemen ardından bu senaryonun test senaryosu düşünülür.
- Küçük ve hızlı iterasyonlarla, araçlarla hazırlanmış testler yazılır.
- TDD adımları:
  - Adım 1: Birim test senaryoları (test case) yazılır.
  - Adım 2: Kod henüz yazılmadığı için testin başarısız olduğu görülür.
  - Adım 3: Kod yazılarak testin geçmesi sağlanır.
  - Adım 4: Test yeniden çalıştırılır. Geçmezse kod yeniden düzenlenir.
- Şirketlere yansıması: test grubu ayrı değil, sistem analizi ekibinin içinde yer alır. Test senaryoları sistem analizi sırasında geliştirilir.
- Hakan Erdoğmuş'un çalışması:
  - IEEE Software dergisinin editörlüğünü yapmış, Boğaziçi mezunu bir araştırmacıdır.
  - 24 lisans öğrencisiyle "önce test" ve "sonra test" yaklaşımlarını karşılaştırmıştır.
  - Sonuç: TDD programcı üretkenliğini artırdı. Kalitede belirgin bir iyileşme görülmedi.
  - TDD programcıyı kodu ve test sonuçlarını yedeklemeye de yöneltti.

### Proje Takvimi

- 9. hafta tamamlandı. Test çalışmalarının iki hafta içinde, 11. haftaya kadar hazırlanması bekleniyor.
- Son teslim (deadline) 12. haftadır.
- Test planı ve test raporları için format verilmeyecek. Derste anlatılanlar esas alınacak.
- Hoca istediklerini önümüzdeki hafta metin hâline getirip paylaşacak. Belki bir örnek de koyacak.

### Ders sonrası notlar

- Altyazıda "capability majority model" geçer. Doğrusu Capability Maturity Model'dir. CMMI'deki I, Integration demektir.
- CMMI 2013'ten beri SEI yerine CMMI Institute tarafından yönetilir. CMMI Institute 2016'da ISACA bünyesine katıldı.
- SPICE, ISO/IEC 15504 standardıdır. Bu standardın yerini bugün ISO/IEC 33000 serisi almıştır.
- Hocanın andığı "ISO 9003" büyük olasılıkla yazılım için kılavuz olan ISO 9000-3'tür. Bugünkü karşılığı ISO/IEC 90003'tür.
- Hoca People CMM düzeylerini ilk sürümdeki adlarla verdi. People CMM 2. sürümde 2. düzeyin adı Managed, 4. düzeyin adı Predictable'dır.
- Erdoğmuş ve arkadaşlarının çalışması 2005 yılında yayımlandı. Hoca derste hem "kalitede fark yok" hem "kalitede biraz geride" dedi. Çalışmanın sonucu, kalitede anlamlı bir fark bulunmadığıdır.
- Scrum'da koşu süresi en fazla bir aydır. İki hafta yaygın bir seçimdir. XP'de de 1-2 haftalık iterasyonlar vardır.
- Hocanın verdiği firma düzeyleri ders tarihindeki (Aralık 2020) bilgilerdir. Güncel düzeyler CMMI Institute'un yayımladığı değerlendirme listesinden kontrol edilmelidir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
