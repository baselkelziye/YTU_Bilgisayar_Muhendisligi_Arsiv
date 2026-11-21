# Ders 8 Çalışma Özeti

## Genel Konular

- Kalite iyileştirme ve süreç iyileştirme
  - Bölüm hedefleri: yazılım iyileştirme sürecini anlamak, CMMI süreç modeli yeterlik düzeylerini incelemek, yazılım geliştirme süreci ile anahtar süreç alanları ilişkisini özetlemek, çalışanlar yetenek modelini (People CMM) incelemek (ekrandan, 00:10:00).
  - Standartlar yazılımı geliştirirken uyulması gereken kurallardır; sertifika programları ise yazılım evinin (ya da kurum içindeki yazılım geliştirme biriminin) süreci iyileştirmek için sağlaması gereken koşulları tanımlar.
  - Yazılım geliştirme ortamı sertifika sistemleri: CMM, CMMI, SPICE, ISO (ekrandan, 00:15:00).
  - Sertifika, bazı ihalelere girişte ön koşul olarak istenebilir (örneğin belirli projelerde CMMI 2 ya da 3 şartı); özellikle askerî yazılım projelerinde ve uluslararası projelerde bu hedef yaygındır.
- CMMI'nin yeri ve çalışma biçimi
  - Yetenek ve Olgunluk Modeli (CMM) daha sonra CMMI'ye dönüştü: proses, proje yönetimi, teknik işler ve destek işleri bütünleşik olarak tek bir sertifika sisteminde toplandı.
  - Carnegie Mellon Üniversitesi'ne bağlı Software Engineering Institute (SEI) tarafından geliştirilir ve sertifikası buradan, ücret ödenerek ve gerekleri yerine getirilerek alınır.
  - SPICE Avrupa'da CMMI'ye benzeyen bir yetkinlik modelidir; Türk Standartları Enstitüsü de SPICE'ı model alarak bir sistem oluşturmaya çalışmaktadır. Derste daha yaygın olduğu için CMMI incelendi.
  - Temel fikir: yazılım sektöründe ürünün kalitesini ağırlıkla onu üreten sürecin kalitesi belirler; süreç odaklı bir kalite yaklaşımı vardır. CMMI etkin bir yazılım sürecinin anahtar elemanlarını tanımlayan bir çerçeve model ve yazılım sürecinin olgunluğunu değerlendirmek için bir ölçüm aracıdır (ekrandan, 00:15:00).
  - Süreç iyileştirme döngüsü: ölçüm → analiz → değişim (ekrandan, 00:20:00). Kurum ölçülür, hangi düzeyin koşullarını sağladığı analiz edilir, sağlamıyorsa kurum içinde değişim yapılır.
- CMMI yeterlik düzeyleri (beş düzey)
  - 1. Başlangıç (Initial): süreç gelişigüzel ve kaotiktir, başarı kişisel gayretlere bağlıdır; kriz durumunda var olan planlar terk edilir; süreç yetenekleri önceden kestirilemez.
  - 2. Yönetilebilir (Managed): proje yönetimi kontrolleri kurulmuştur, projeler belgelenen planlara uygun yürütülür ve yönetilir; gereksinimler yönetilir, ilişkili ürünler oluşturulur ve denetlenir; ürün ve hizmetler kendilerine özgü gereksinim, standart ve hedefleri sağlar.
  - 3. Tanımlı (Defined): süreçler iyi tanımlanmış ve anlaşılmıştır, standartlar, prosedürler, araçlar ve metotlarla anlatılmıştır; standart süreç tanımlarıyla kurumsal tutarlılık sağlanır; tüm projelerde standart yazılım geliştirme sürecinin uyarlanmış hali kullanılır (ekrandan, 00:25:00).
  - 4. Niceliksel (sayısal) yönetilen (Quantitatively Managed): süreç başarımı için önemli alt süreçler istatistiksel ve diğer nicel tekniklerle kontrol edilir; kalite ve süreç performansının nicel hedefleri konur; işler gerçek veriler baz alınarak tahmin edilebilir.
  - 5. En iyileştirilmiş (Optimizing): süreçten gelen sayısal geri beslemeler ve teknolojilerden yararlanılarak sürekli süreç iyileştirmesi yapılır; 4. ve 5. düzey arasındaki önemli ayrım, adreslenen süreçlerin değişme derecesidir (ekrandan, 00:30:00).
- CMMI anahtar süreç alanları (key process areas)
  - Etkin bir yazılım süreci için tanımlanan anahtar süreç alanlarının düzeylere göre dağılımıdır; birinci düzeyde anahtar süreç alanı yoktur (ekrandan, 00:45:00).
  - II. düzey: gereksinimlerin yönetimi, proje planlama, proje izleme ve kontrol, tedarikçi sözleşme yönetimi, ölçümleme ve analiz, süreç ve ürün kalite güvence, konfigürasyon yönetimi.
  - III. düzey: gereksinimlerin geliştirilmesi, teknik çözüm, ürün entegrasyonu, doğrulama (verifikasyon), kurumsal süreç tanımlama ve odaklanma, kurumsal eğitim, bütünleşik ürün ve süreç geliştirme için bütünleşik proje yönetimi, risk yönetimi, entegrasyon için kurumsal altyapı. <!-- BELİRSİZ: III. düzey listesinin tam yazımı yalnız küçük slayt önizlemesinden ve anlatımdan okunabildi -->
  - IV. düzey: organizasyonel süreç başarımı, niceliksel proje yönetimi. V. düzey: organizasyonel yenilenme ve yaygınlaştırma, nedensel analizler ve çözümleme (ekrandan, 00:50:00).
  - CMMI'de süreç alanları süreç yönetimi, proje yönetimi, mühendislik ve destek olarak gruplanır. Destek süreç alanları: temel (ölçümleme ve analiz, kalite sağlama, konfigürasyon yönetimi) ve ileri (organizasyonel entegrasyon altyapısı, nedensel analiz ve çözümleme, karar analizi ve çözümleme) (ekrandan, 00:55:00).
- People CMM (P-CMM)
  - 1992'de SEI tarafından projelendirildi; kurumlar performanslarını artırmak için birbiriyle ilişkili insan, süreç ve teknoloji kavramlarına odaklanmalıdır. İnsanla ilgili konuları iyileştirmek isteyen kurumlar için CMM'in yapısına benzeyen bir olgunluk çerçevesidir; insan değerlerinin yönetimini ve geliştirilmesini yönlendirir (ekrandan, 01:05:00). Artık CMMI'nin içine katılmıştır.
  - Temel hedefleri: yazılım geliştirme yeteneğini tanımlamak ve sağlamak, iş gücünün yeteneklerini artırarak kurumun yeteneklerini artırmak, her çalışanın ve kurumun hedeflerini birlikte tutmak, insan değerlerini elde tutmak.
  - Düzeyler: 1 Başlangıç; 2 Tekrarlanabilir (tazminat, eğitim, performans yönetimi, personel sağlama, iletişim, çalışma ortamı); 3 Tanımlı (katılımcı kültür, yeteneğe dayalı pratikler, kariyer geliştirme, yetenek geliştirme, iş gücü planlama, bilgi ve becerilerin analizi) (ekrandan, 01:10:00); 4 Yönetilen (organizasyonel performans ayarlama, organizasyonel yetenek yönetimi, takım temelli pratikler, takım kurma, danışmanlık); 5 En iyileşen (sürekli iş gücü inovasyonu, koçluk, kişisel yetenek geliştirme) (ekrandan, 01:15:00).
- Ara sınav öncesi genel tekrar
  - Yazılım mühendisliğinin katmanlı yapısı: kalite bakış açısı, süreçler, yöntemler, yazılım araçları (ekrandan, 01:20:00).
  - McCall kalite üçgeni ve kalite faktörleri; McCall modelinde kalite faktörleri, ağırlıklı metrik toplamlarıyla ölçülebilir hale getirilir.
  - Kaliteyi sağlama aktiviteleri, hata bulma gideri ile hata bulma olasılığının süreçle değişimi (ekrandan, 01:25:00), standartlar ve IEEE 830.
  - Doğrulama (verification) ve geçerleme (validation), V model, gözden geçirme ve onaylama (ekrandan, 01:30:00), test türleri.
  - Birim testi, test case, test sürücü ve koçan; yukarıdan aşağı, aşağıdan yukarı ve sandviç bütünleme (ekrandan, 01:35:00); regresyon, sistem ve kabul testi.
  - Saydam kutu (temel yol testi, McCabe) ve kara kutu testi (eşdeğer bölümleme, sınır değer analizi), keşif testi (ekrandan, 01:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- 2. düzey ile 4. düzey arasındaki ölçüm farkı
  - 2. düzeyde de ölçüm yapılır; 4. düzeyi ayıran şey proje yönetiminin ölçümlere göre yapılmasıdır. Bitmiş projelerden bir ölçüm arşivi (function point, satır sayısı, iş gücü, süre, risk bilgileri) varsa ve yeni projelerin maliyet, iş gücü ve süre tahminleri bu arşive dayanılarak yapılıp kanıtlanabiliyorsa kurum 4. düzeydedir.
  - Bu yüzden yeni kurulmuş bir firma hemen 4. düzeyde olamaz; önce ölçümlerle tamamlanmış projeleri olmalıdır.
- 4. ve 5. düzey ayrımı
  - Belirleyici olan süreçlerdeki değişme derecesi, yani yenilikçilik ve yaratıcılığın planlanıp planlanmadığıdır.
- 3. düzeyin belirtisi
  - 2. düzeyde yapılan her şeyin bütün projelerde, kurumsal bir yapı içinde yapılması; 2. düzeyde görülmeyen ek olarak bütün projelerde risk yönetimi.
- Sertifikasyonun ekibe yansıması
  - Kalite birimi test ve geliştirme ekiplerine standartlar ve metrikler verir, onlardan sürekli metrik ve rapor toplar; geliştirici "böyle tasarladım" deyip geçemez, belirli bir standarda uymak zorundadır.
  - Hoca bunu üniversitelerin MÜDEK ve ABET akreditasyonuna benzetti: iyi olduğunu söylemek yetmez, yapılan her çalışma belgelenmelidir.
- Doğrulama ve geçerleme tanımları (hoca slaytı derste düzeltti)
  - Geçerleme (validation): doğru yazılım üretildi mi? Doğrulama (verification): yazılım doğru yolla üretildi mi?
- Güncel bilgi kaynakları
  - Yazılım mühendisliğindeki yeni düzenlemeler için SEI'nin sitesi, proje yönetimi için Project Management Body of Knowledge (PMBOK) önerildi.

## Kısa Tekrar Notları

- Ürün kalitesini büyük ölçüde süreç kalitesi belirler; CMMI süreç odaklıdır.
- İyileştirme döngüsü: ölçüm → analiz → değişim.
- CMMI düzeyleri: başlangıç, yönetilebilir, tanımlı, niceliksel yönetilen, en iyileştirilmiş.
- 1. düzeyde anahtar süreç alanı yoktur.
- 2. düzey: gereksinim yönetimi, proje planlama, izleme ve kontrol, tedarikçi sözleşmesi, ölçüm ve analiz, kalite güvence, konfigürasyon yönetimi.
- 3. düzey: kurumsal süreç tanımı, kurumsal eğitim, bütünleşik proje yönetimi, risk yönetimi.
- 4. düzey: ölçüm arşivine dayalı niceliksel proje yönetimi. 5. düzey: kurumsal yenilikçilik, nedensel analiz.
- CMMI süreç alanı grupları: süreç yönetimi, proje yönetimi, mühendislik, destek.
- P-CMM: 1992, SEI; insan, süreç, teknoloji; düzeyler başlangıç, tekrarlanabilir, tanımlı, yönetilen, en iyileşen.
- Katmanlı yapı: kalite bakış açısı → süreçler → yöntemler → araçlar.
- Hata ne kadar geç bulunursa bulma gideri o kadar artar, bulma olasılığı o kadar düşer.
- V model: birim ve bütünlük testi doğrulama, sistem testi doğrulama ve geçerleme, işlemsel kullanım geçerleme.
- İnceleme (inspection) bütün ara ürünlere, test yalnız çalıştırılabilir prototip ya da programa uygulanır.
- Kara kutu: dış davranış, eşdeğer bölümleme, sınır değer; saydam kutu: iç yapı, temel yol, McCabe.

## Detaylı Açıklamalar

- Bu ders iki bölümden oluştu: yeni konu olarak kalite iyileştirme (CMMI ve People CMM), ardından ara sınav öncesi dönemin genel tekrarı.
- Kalite iyileştirme, daha önceki haftalarda konuşulan kaliteyi sağlama aktiviteleri ve standartlarla birleştirilebilir. Standartlar yazılımı gerçekleştirirken uyulacak kurallardır; sertifika programları ise yazılım evinin süreci iyileştirmek için sağlaması gereken koşulları tanımlar. Kurum bir sertifika programına başvurur, koşulları sağladığını gösterir ve sertifikayı alır. Sertifika, örneğin bazı ihalelerde "CMMI 3 sahibi olmak" gibi ön koşulları karşılamaya yarar.
- CMMI'nin bakışı ürün yönelimli değil süreç yönelimlidir: ürün kalitesini anlamak için sürece bakılır. Gereksinim analizi yapılmış mı, gereksinim belgesi IEEE 830'a uygun mu, tasarım spesifikasyonu yazılıp belgelenmiş mi, konfigürasyon ve risk yönetimi yapılıyor mu gibi sorular sürecin anahtar elemanlarını oluşturur.
- Düzeylerin mantığı şudur. Birinci düzeyde kurum yalnızca iyileşmeye niyetlenmiştir; standart bir durum yoktur. İkinci düzeyde bütün projelerde proje yönetimi fikri vardır, ancak projeden projeye eksiklikler olabilir. Üçüncü düzeyde bu uygulamalar kurumsal hale gelir, her projede hangi süreç modeli seçildiyse o uygulanır ve risk yönetimi eklenir. Dördüncü düzeyde ölçüm arşivi yeni projelerin planlanmasında kullanılır; eski projelerin tasarım ölçütleri yeni projelerin tasarım kararlarını daha gerçekçi kılar. Beşinci düzeyde kurumsal boyutta yeni fikir üretme, bu fikirleri yayma ve eski proje sonuçlarının nedenlerini analiz etme vardır.
- CMMI'de "bütünleşik" denen şey, CMM döneminde ayrı ayrı yürütülen süreç yönetimi, proje yönetimi, mühendislik ve destek alanlarındaki düzey çalışmalarının birleştirilip kurumun bir bütün olarak değerlendirilmesidir.
- Hocanın verdiği örneklere göre yurt içinde savunma alanında yıllardır 5. düzeyde ya da 4. düzeyde olan firmalar ve 4. düzeyde bankacılık yazılımları vardır; hoca bu bilgilerin zamanla değişebileceğini, güncellenmesi gerektiğini de söyledi.
- People CMM, insanla ilgili konularda olgunluğu tanımlar. İkinci düzeyde personel alımı, eğitim, tazminat ve performans yönetimi gibi işler tekrarlanabilir kurallara bağlanır (her alımda yeni kural koymak yerine belirli bir kural çerçevesinde işe alım). Üçüncü düzeyde çalışanların proje önerisi verebildiği katılımcı bir kültür, kurumun ihtiyaçlarıyla paralel kariyer ve yetenek geliştirme planları ve iş gücü planlaması vardır. Dördüncü düzeyde kurumsal performans düzeyleri ve ekip temelli pratikler, beşinci düzeyde inovasyon, koçluk ve kişiye özel yetenek geliştirme beklenir.
- Tekrar bölümünde yazılım mühendisliği tanımı (mühendislik yaklaşımını yazılım geliştirme süreçlerinde kullanarak yeni yazılımlar geliştirme) ve katmanlı yapı hatırlatıldı: bir yazılım aracı ancak kullanılan yöntem ve süreçlerle uyumluysa başarı getirir, hepsinin temelinde kalite bakış açısı vardır.
- McCall kalite üçgeninde ürün kullanımı (doğruluk, güvenirlik, kullanışlılık, bütünlük), ürün değişikliği (bakım yapılabilirlik, esneklik, test edilebilirlik) ve ürün geçişi (taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik) bakış açıları vardır. Kalite faktörleri tanımsal olduğu için daha kolay ölçülen metriklerin ağırlıklı toplamıyla sayısallaştırılır.
- Kaliteyi sağlama aktiviteleri: standartlar, doğrulama ve geçerleme, gözden geçirme ve denetim, test, hata ve kusur analizi, değişim ve konfigürasyon yönetimi, eğitim, risk yönetimi. Bunların bir kısmı geliştirmeden önce konan kurallar, bir kısmı geliştirme sırasında, bir kısmı sonrasında yapılır. Hata ne kadar erken bulunursa o kadar ucuzdur; önleme maliyeti (kalite planlama, formal teknik gözden geçirme, test, eğitim) hatalı teslimden daha az maliyetlidir.
- Standartlar kaynağına (ISO, IEEE) ve geliştirme aşamasına (proje yönetimi, gereksinim spesifikasyonu, tasarım) göre sınıflanabilir; IEEE 830 gereksinim spesifikasyonunun nasıl yazılacağını anlatan IEEE standardıdır.
- Test tekrarı: birim testi en küçük modül üzerinde, genellikle saydam kutu olarak yapılır; test case belirli bir program yolunu işletmek ya da bir gereksinimi sınamak için hazırlanan veri ve işlemlerdir. Modül bağımsız değilse test sürücü (çağıran yerine) ve koçan (çağrılan alt program yerine konan kukla program) gerekir. Bütünleme yukarıdan aşağı ya da aşağıdan yukarı yapılır, ikisinin birlikte kullanımına sandviç test denir. Aşağıdan yukarı bütünlemede alttaki modüller test edilmiş olmalıdır; her birleştirmede birleşen yapı yeniden test edilir. Sistem testinde güvenlik, dayanıklılık, yetenek ve performans testleri; kabul testinde konfigürasyon incelemesi ve onaylama testi vardır.
- Kara kutu testi bütünleme, sistem ve kullanıcı testlerinde uygulanır; iç yapı bilinmeden girdiler verilir, istenen çıktılar ve anormal veriye tepki incelenir. Keşif testi, ürün spesifikasyonu ya da gereksinim belgesi olmadan ürünün çalıştırılıp genel olarak sınanmasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
