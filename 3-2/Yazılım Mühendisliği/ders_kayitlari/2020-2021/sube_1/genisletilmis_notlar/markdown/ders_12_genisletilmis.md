# Ders 12 Genişletilmiş Notu: Dönem Projesi Sunumları ve Kalite, Ölçme, Maliyet Tahmini ve Test Tekrarı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı: Dönem Projesi Sunumları
- 2. Kapsam, Kabuller ve Kısıtlar
- 3. Proje Planlama: İş-Zaman Çizelgesi, Ekip Yapısı, Model ve Maliyet
- 4. Risk Yönetimi ve Risk Tablosu
- 5. İsteklerin Modellenmesi: Kullanım Senaryoları, Kullanım Durumu Diyagramı, İzlenebilirlik
- 6. Nesneye Dayalı Modelleme ve Tasarım Diyagramları
- 7. Veri Tabanı Tasarımı ve Birim Testleri
- 8. Kapanış Tekrarı: Kalite Ölçütleri ve Özellikleri
- 9. Kapanış Tekrarı: Yazılım Ölçme ve Maliyet Tahmin Yöntemleri
- 10. Kapanış Tekrarı: Kullanıcı Testleri ve Sistem Testleri
- 11. Kapanış Tekrarı: SDLC ve Yazılım Yaşam Döngüsü

## 1. Dersin Yapısı: Dönem Projesi Sunumları

Bu ders dönemin son dersidir. İlk yaklaşık iki saat yirmi dakikada öğrenci grupları dönem projelerini sundu; son yirmi dakikada hoca, diğer şubeyle karşılaştırınca eksik kaldığını düşündüğü birkaç konuyu (kalite ölçütleri, ölçme, maliyet tahmini, test, yaşam döngüsü) kısaca tekrar etti.

Sunumlarda yalnız modelleme ve proje planlama kısmı istendi. Programın çalıştırılması, kod ayrıntıları ve testlerin canlı gösterimi ayrı bir uygulama oturumuna bırakıldı. Hoca uygulama oturumuna yalnız programı yazanların değil bütün grup üyelerinin katılmasını istedi; programda görevi olmayanlar da tasarımla programın bağlantısını açıklayabilmelidir.

Sekiz grubun konuları şunlardı:

- Üniversite kütüphanesi bilgi sistemi (dört grup): öğrenci, memur ve öğretim üyesi kullanıcıları; ödünç alma, iade, rezervasyon; kiosk ve akıllı kart.
- Poliklinik bilgi sistemi (üç grup): telefonla randevu, kayıt görevlisi, doktor muayenesi, rapor/reçete/sevk, veznede sigorta indirimiyle ödeme.
- Medya takip sistemi (bir grup): kullanıcının medya organlarını seçip belirli sıklıkla rapor alması, sıklığa göre ücret.

Sunumların ortak iskeleti: proje kapsamı ve tanımı, kabuller ve kısıtlar, iş-zaman çizelgesi, ekip organizasyonu, risk tablosu, kullanım senaryoları, kullanım durumu diyagramı, izlenebilirlik tablosu, kavramsal ve metotlu sınıf diyagramı, sıralama, etkinlik ve durum diyagramları, veri tabanı tasarımı, birim testleri ve ekran görüntüleri. Aşağıdaki bölümler bu iskeleti izler ve her başlıkta sunumlardan örnekler ile hocanın düzeltmelerini verir.

## 2. Kapsam, Kabuller ve Kısıtlar

Proje planının ilk parçası kapsamı ve bu kapsamın dayandığı kabulleri (varsayımları) ve kısıtları yazmaktır. Hoca, bütün grupların aynı ödevi bildiğini, bu yüzden sunumlarda genel tanımı geçip yalnız grubun kendine özgü kabul ve kısıtlarının anlatılmasını istedi.

### 2.1 Kütüphane projesi

Bir kütüphane grubu kabullerini projenin sağlam ilerlemesi açısından şöyle sıraladı:

- Binadaki internet ve elektrik altyapısının uygun olması, kiosk ve bilgisayarların düzgün çalışması.
- Ekip üyelerinin işi yapacak yeterlilikte olması.
- Yazılımın bilgisayar ve kiosklara sorunsuz yüklenip çalışması.
- Test ya da üretim aşamasında arıza, eksiklik veya hata olursa kütüphane çalışanlarının yazılım firmasına zamanında bilgi vermesi.
- Uzaktan bağlanma gerektiğinde bunun sorunsuz yapılabilmesi.

Kısıtlar: ekipte yalnız 5 kişi çalışır ve ek personel alınmaz; 4 aylık (120 gün) bir zaman kısıtı vardır; eldeki mevcut kaynak ve yazılımlar kullanılır.

Başka bir kütüphane grubu ödevdeki iş kurallarını şöyle özetledi: üç tür üye vardır (öğrenci, memur, öğretim üyesi); öğrenci ve memur aynı anda en fazla 3, öğretim üyesi en fazla 6 parça ödünç alabilir; ödünç süresi öğrenci ve memur için 1 ay, öğretim üyesi için 3 aydır; süreyi geçen her gün için 1 TL ceza uygulanır; ders kitaplarını yalnız öğretim üyeleri alabilir; istenen parça yoksa rezerve edilebilir; bir kitabın birden fazla kopyası olabilir ve her kopya ayrı bir nesne kabul edilir.

Dördüncü kütüphane grubu varsayımlarını şöyle yazdı: çalışan bir akıllı kart sistemi mevcuttur; müşteri donanımı yenidir, ilk donanım yatırımı gerekmez; ihtiyaçlar müşteriyle toplantılarda belirlenmiş, analiz aşamasındaki çalışmalar müşteriye sunulup onaylanmıştır. Bu grup mevcut sistemi de tanımladı: her şey ortak bir sunucudaki Excel dosyasında tutuluyor, kullanıcılar sistemi kullanamıyor, aynı anda yalnız bir çalışan kayıt ekleyebiliyor, ödünçteki yayın rezerve edilemiyor, gecikme ancak teslimde anlaşılıyor, kiosk atıl bekliyor. Önerilen sistemde kullanıcılar akıllı kartla kiosktan arama, rezervasyon ve hesap durumu görme işlemlerini yapacak, ödünç adet ve süreleri yönetimce esnek değiştirilebilecek, birden fazla çalışan eş zamanlı yayın ekleyebilecek, süresi geçenlere otomatik e-posta gidecek; raporlama, yedekleme, içe-dışa aktarma gibi fonksiyonel olmayan özellikler de bulunacak.

### 2.2 Poliklinik projesi

Bir poliklinik grubu ödevdeki muayene süresinin 30 dakika olmasına ek olarak iki kısıt koydu: gidilmeyen randevu için 24 saatlik bir ceza (24 saat sonra yeniden randevu alınabilir) ve indirimin yalnız belirli sigorta için yapılabilmesi.

Başka bir grubun kabulleri ekranda şöyleydi (ekrandan, 00:50:00):

- Sigorta sorgu sisteminin hazır bir sistem üzerinden yapılabildiği varsayılmıştır.
- Her doktorun tek bir branşı vardır.
- Doktorların her gün çalıştığı kabul edildi.
- En fazla 20 gün sonrası için randevu alınabilir.

Üçüncü grubun kabul ve kısıtları: her poliklinikte en az bir doktor bulunmak zorundadır; muayene 30 dakikadır; poliklinik yalnız rezervasyonla hasta kabul eder; rezervasyon için hasta telefonla görevliyi arar; kaydı yoksa kayıt görevlisi kaydeder; doktor hastanın muayene geçmişini sorgulayıp güncelleyebilir; ödeme vezneden nakit ya da kredi kartıyla yapılır ve sigorta sorgusu yapılabilir.

### 2.3 Medya takip projesi

Medya takip grubunun kabul ve kısıtları ekranda şöyleydi (ekrandan, 01:20:00):

- Sisteme kayıt olurken gerekli kısımlar doldurulmalı ve içerisinde "@" bulunan geçerli mail adresi olmalıdır.
- Sisteme kayıt aşamasında şifre en az 6 karakter olmalıdır.
- Medya organlarından rapor almak için sadece kurum veya kişiler kendi planına ekleyebilecektir.
- Takip sıklığı arttıkça abonelik ücreti de aynı oranda artacaktır.
- Bir kurum veya kişi istediği sayıda medya organı raporu ekleyebilir, ama aynı medya organının farklı sıklıklara sahip aboneliğini ekleyemez.
- Rapor sıklığı hazır olarak işaretlenebilir veya isteğe bağlı özel bir sıklık oluşturulabilir.
- Medya organları eklendikten sonra kaydet butonuna basılır, eklenen abonelikler ve ücret bilgisi gösterilir; daha önce abonelik eklenmişse giriş sayfasında gösterilir.

## 3. Proje Planlama: İş-Zaman Çizelgesi, Ekip Yapısı, Model ve Maliyet

### 3.1 İş-zaman çizelgesi (Gantt)

Grupların hepsi bir Gantt çizelgesi hazırladı. İlk kütüphane grubunun çizelgesinde ana başlıklar proje planı, analiz, yazılım, test ve hata düzeltmeydi. Analizin altında isteklerin modellenmesi, nesneye dayalı modelleme ve nesneye dayalı tasarım; yazılımın altında ödevdeki her istek (envantere DVD ekleme, ödünç verme, rezervasyon, iade, kullanıcıların ayrıştırılması, kiosk yazılımı) ayrı satır olarak yazıldı. Her satırda adam-gün (work days), tamamlanma yüzdesi (% done), başlangıç ve bitiş tarihleri bulunuyordu.

Başka bir grubun çizelgesi ekranda şu görevleri sıralıyordu (ekrandan, 01:35:00):

| No | Görev | Başlangıç | Bitiş |
|---|---|---|---|
| 2 | Fizibilite Analizi | 04/25/2021 | 04/30/2021 |
| 3 | Proje Planının Yapılması | 04/30/2021 | 05/02/2021 |
| 4 | Kullanım Senaryolarının Belirlenmesi | 05/02/2021 | 05/07/2021 |
| 6 | Nesneye Dayalı Modellemenin ve Diyagramların Gerçeklenmesi | 05/07/2021 | 05/10/2021 |
| 5 | Projenin Java İle Gerçeklenmesi | 05/10/2021 | 05/20/2021 |
| 8 | Refactoring | 05/20/2021 | 05/21/2021 |
| 7 | Birim Testi Sınamalarının Gerçeklenmesi | 05/21/2021 | 05/25/2021 |
| 9 | Proje İçin Raporun Hazırlanması | 05/25/2021 | 05/29/2021 |

Bu grup fizibiliteyi üçe ayırdı: yazılım fizibilitesi (hangi teknolojiler kullanılacak), donanım fizibilitesi (sistem hangi işletim sistemi ve donanım üzerinde çalışacak) ve ekonomik fizibilite. Gerçekleme çizelgede tek bir çizgi gibi görünse de arayüz ve arka uç ekipleri paralel çalışmış, sonra birleşip değişken ve sınıf adı çakışmalarını gidererek refactoring yapmıştır.

Bir poliklinik grubu planlanan toplantı tarihlerini gerçekleşen tarihlerle karşılaştırdı ve Gantt çizelgesinden ne kadar öteleme olduğunu gösterdi. Aynı grup, belgede yer alan tablo ve diyagramları ürün çalışırken şekillendirdiğini, ama yine de bir zaman planının neyle karşı karşıya olunduğunu ve projenin hangi tarihte teslim edilebileceğini görmek için gerekli olduğunu söyledi.

Hoca çizelgeyi Excel'de hazırlayan bir gruba, bir proje yönetimi aracı kullanmanın daha iyi olacağını söyledi. Diğer gruplar Microsoft Project ya da çevrim içi Gantt araçlarını kullanmıştı.

### 3.2 Ekip organizasyonu

Gruplar iki yaklaşım gösterdi. Bazıları rol temelli bir organizasyon şeması çizdi: proje yöneticisi, iş analisti, sistem analisti, sistem mimarı/tasarımcısı, yazılım mühendisi, test mühendisi, veri tabanı tasarımcısı. Bir grup proje sponsoru olarak dersin hocasını, paydaş olarak kütüphaneyi gösterdi. Diğerleri, herkes her aşamada (plan, tasarım, kod, test) çalıştığı için organizasyon şeması yerine doğrudan bir görev dağılım tablosu hazırladı. Bazı gruplar hiyerarşik görünen şemaya rağmen demokratik bir ekip yapısı kullandıklarını, proje yöneticisinin yalnız koordinasyon yaptığını belirtti.

### 3.3 Yazılım geliştirme modeli seçimi

Bir kütüphane grubu şelale modelini seçti. Modelin aşamaları ve her aşamanın çıktıları ekranda şöyleydi (ekrandan, 02:15:00):

- Planlama: ekip oluşumu, ön hazırlık, fizibilite, risk analizi.
- Gereksinim: toplantılar, kullanım senaryoları, SRS.
- Çözümleme: veri akış diyagramları, kullanım senaryosu çözümlemesi, UML kavramsal sınıf diyagramı.
- Tasarım: mimari, sınıf diyagramları.
- Gerçekleme: kodlama.
- Sınama: birim testi, kullanıcı kabul testi.

Şelale modelinin seçim nedenleri:

- Gereksinimler iyi tanımlanmış, açık ve sabittir.
- Değişiklik ve belirsizlik olmadığından sistem tanımı durağandır.
- Ekibin tecrübesi ve bilgisi ile teknoloji iyi anlaşılmıştır.
- Projede istenen fonksiyon sayısı az ve sınırlıdır.
- Sistem geliştirme tamamlandıktan sonra devreye alınacaktır (ara çıktıya ihtiyaç yoktur).
- Olası yeni fonksiyon ve özellik talepleri daha sonraki sürüm olarak ele alınabilecektir.

Başka bir grup, metot kaynaklı riskleri azaltmak için piyasada denenmiş genel yöntemleri (şelale, Scrum gibi) tercih ettiğini söyledi.

### 3.4 Maliyet ve fayda

Aynı şelale grubu maliyeti adam-gün üzerinden tahmin etti. Her ekip üyesinin hangi aşamada kaç gün çalışacağı tahmin edildi, kişi başı günlük maliyet 1000 TL alındı:

- Verilen: toplam iş = 70 adam-gün, günlük maliyet = 1000 TL/adam-gün.
- İşlem: $70 \times 1000$.
- Sonuç: proje maliyeti 70.000 TL.

Faydalar maddi ve maddi olmayan olarak ayrıldı. Maddi faydalar: iş yükünün azalmasıyla operasyon maliyetinin düşmesi, ek donanım alımına ve bakımına gerek olmaması, ödünç takibi kolaylaşınca kayıp oranının ve yeniden edinme maliyetinin düşmesi. Maddi olmayan faydalar: kaliteli ve etkin kütüphane hizmeti, kullanıcı memnuniyeti ve prestij artışı.

## 4. Risk Yönetimi ve Risk Tablosu

### 4.1 Grupların risk tabloları

İlk kütüphane grubunun risk tablosu ekranda şöyleydi (ekrandan, 00:10:00):

| Risk faktörü | Risk | Risk oranı | Nedeni | Önlemi |
|---|---|---|---|---|
| Misyon ve vizyon | Proje çakışması | Düşük | Firmanın başka çekici bir proje alması ya da projenin ortasında bir değişiklikle çakışma | Kayıp-kazanç analizi; aksama ihtimali %40'ı geçerse kaynak dengelerinin yeniden yapılması |
| Organizasyon ve yönetim | Proje ekibinin korunamaması | Düşük | Kilit kişilerin sorumluluklarını tamamlamadan ayrılması | Sözleşme yapılması, yerine geçebilecek kişinin kurum içinden tespiti |
| Müşteri | Müşteri gereksinimlerinin değişimi | Yüksek | Gereksinim değişikliklerinin proje süresince dikkate alınması | Aylık toplantılar, değişimin projeye etkisini konuşup güncellemelerin yapılması |
| Finansal ve ekonomik | Bütçe kısıtları | Orta | Bütçenin yeterli olmaması | Risk toleransı için ayrılan fondan kullanılması |
| Kapsam | Yeni teknoloji kullanımı | Düşük | Sık rastlanmayan teknolojilerin kullanılması | Teknoloji desteğinin alınması |
| Teknik | Arıza takibi | Orta | Arıza takip sürecinde eksiklik | Arıza takip ekibinin kurulması, haftalık toplantı ve durum güncellemesi |

Bir poliklinik grubunun tablosunda yalnız risk, gerçekleşme olasılığı ve çözüm önerisi sütunları vardı (ekrandan, 00:35:00): sistem hatası (düşük-normal; görevlilerin olası hatalarda hastalara hizmet vermesi), kişisel yaralanma (düşük), veri kaybı (düşük; verilerin başka platform ve cihazlarda saklanması), aşırı yükleme (düşük-normal; ek sunucuların devreye girmesi), sistem yetersizliği (düşük; güncelleme ve iyileştirme).

Web tabanlı poliklinik grubunun tablosunda etki ve olasılık ayrı sütunlardı (ekrandan, 01:05:00):

| ID | Risk | Türü/Grubu | Etkisi | Olasılık |
|---|---|---|---|---|
| 1 | Yazılımın geç teslim edilmesi | Proje | Büyük | Düşük |
| 2 | Yazılımsal mantık hataları | Yazılım | Büyük | Düşük |
| 3 | Kaynakların tüketilmesi/aşılması | Proje | Orta | Düşük |
| 4 | Sözleşme ve kanun ile ilgili riskler | Yasal | Büyük | Orta |
| 5 | Görev dağılımının yapılamaması | Yönetim | Orta | Düşük |

Grup, geç teslimin etkisinin büyük ama sistem çok karmaşık olmadığı için olasılığının düşük olduğunu; yasal risklerin (kişisel verilerin korunması mevzuatına uyum) etkisinin büyük, olasılığının daha yüksek olduğunu açıkladı.

### 4.2 Hocanın risk açıklaması

Poliklinik grubunun tablosunun ardından hoca diğer grupların da yanlış yönlenmemesi için riskle ilgili temel noktaları hatırlattı. Projeye başlarken, proje planı sırasında, ekipte ve projede ileride çıkabilecek problemleri öngörmek gerekir. Şu anda var olmayan ama değişimlerle ortaya çıkabilecek problemler önceden düşünülür, çıkmaması için önlem alınır ve riskin takibi yapılır. Risk tablosu bunun için oluşturulur.

Ardından hoca sordu: risk tablosunda hangi riskleri takip edeceğiz, nasıl belirleriz? Riskin takibi de bir maliyettir, bu yüzden hepsini izlemek istemeyiz.

**Soru:** Hangi riskler takip edilir? **Cevap (öğrenci):** Sistem hatası ve aşırı yüklemenin gerçekleşme olasılığı diğerlerinden yüksek olduğu için bunlar takip edilmeli. **Cevap (hoca):** Yalnız gerçekleşme olasılığı riskin derecesini belirlemeye yetmez. Risk gerçekleştiğinde yıkımının, etkisinin ne olacağı da belirlenmeli; ikisi çarpılarak riskin derecesi bulunur.

> **Hocanın vurgusu:** Riskin derecesi = gerçekleşme olasılığı × etkisi. Takip edilecek riskler bu dereceye göre seçilir.

**Soru (öğrenci):** Bunu oluşturmak için elimizde tam bir sistem olması gerekmez mi? Biz yalnız bir modülü kodladık, bu yüzden tablo farazi kaldı. **Cevap:** Sonunda tek bir modülün ürünü olacak olsa da başlarken bütünü planlıyorsunuz. Risk tablosu hiçbir parça gerçekleşmeden, projenin en başında, öngörüyle hazırlanır.

Daha sonra bir kütüphane grubuna da aynı soru soruldu. Grup tablosunda güvenlik riskini (teknik; siber saldırı olasılığı orta, etkisi büyük) ve süre riskini (proje; teslim tarihlerinin sarkma olasılığı yüksek, etkisi büyük) örnek verdi. Hoca "hangilerini takip etmemiz gerekir?" diye sorunca grup, etkisi büyük olan süre, güvenilirlik ve kullanılabilirlik risklerinin her kilometre taşında izlenmesini, olasılığı ve etkisi düşük olan maliyet, personel ve araç risklerinin elenebileceğini söyledi. Başka bir grup risklerini bir risk analiz grafiğine yerleştirerek en önemli iki riski belirledi ve her risk için etki azaltma (mitigation) planı yazdı.

## 5. İsteklerin Modellenmesi: Kullanım Senaryoları, Kullanım Durumu Diyagramı, İzlenebilirlik

### 5.1 Kullanım senaryosu belgesinin yapısı

Grupların kullandığı kullanım senaryosu şablonu şu bölümlerden oluşur: birincil aktör, diğer ilgililer ve ilgi alanları, ön koşullar, son koşullar, ana senaryo (numaralı adımlar) ve alternatif senaryolar (ana senaryonun ayrıldığı adımın numarasıyla, ör. 3.a, 8a, 12b).

Bir kütüphane grubunun "Ögenin Aranması" senaryosu ekranda şöyleydi (ekrandan, 01:40:00):

- Ana senaryo:
  - 1. Giriş yapan kişi arayüzün sağ kısmında bulunan kütüphanedeki ögelerin bulunduğu tabloda arama yapmak istemektedir.
  - 2. Tablonun altında bulunan arama kutusuna istediği ögenin içinde geçen bir anahtar kelimeyi veya ürünün bütün adını yazar.
  - 3. Kullanıcı tarafından girilen kelimeyi içerisinde içeren ögeler listelenir.
  - 4. Kullanıcı listelenen sonuçlardan aradığı ögeyi seçer.
- Alternatif senaryolar:
  - 3.a Kullanıcı tarafından girilen kelimeyi içerisinde bulunduran bir öge bulunamaz. (1) Tablo boş olarak kullanıcıya dönülür. (2) Tekrar arama yapması için arama çubuğunu temizlemelidir.

Bu senaryonun birincil aktörü kütüphaneye üye herhangi bir kişidir (öğrenci, öğretim görevlisi ya da memur); diğer ilgili yoktur; ön koşul kullanıcının kütüphane sistemine kullanıcı adı ve şifreyle kayıtlı olmasıdır; son koşul girilen anahtar kelimeyi içeren ögelerin tabloda listelenmesidir. Aynı grubun "Ögenin Ödünç Alınması" senaryosunda ana akışın 3. adımında öge envanterde varsa stok bir azaltılıp kullanıcının envanterine geçirilir; yoksa alternatif akışta öge rezerve edilip kullanıcının rezerve listesine alınır; 4. adımda kullanıcı türüne göre iade tarihi (1 ay ya da 3 ay) atanır.

Bir poliklinik grubunun "Alternatif Senaryolar" slaytı (ekrandan, 00:55:00):

- 8a. Randevu zamanı uygun değil.
  - 1. Girilen gün veya saat doludur, sistem tarafından veznedara belirtilir.
  - 2. Veznedara uygun başka bir saat önerilir.
  - 3. Veznedar bu saatin müşteriye uygun olup olmadığını kontrol eder.
  - 4. Müşteriye uygun olan saat sisteme girilir.
- 8b. Hastanın kaydı yoktur.
  - 1. Sistem hastanın kişisel bilgilerinden kaydını bulamaz.
  - 2. Yeni hasta kaydı için veznedara sekme açılır.
  - 3. Veznedar hastanın tam kaydını yapar.

Medya takip grubunun "haber takibi" senaryosunda birincil aktör kullanıcıdır; kullanıcı sistemdeki medya organlarını takip etmek, belli aralıklarla rapor almak ve kendine özel aralık seçebilmek ister. Ana senaryoda kullanıcı kayıt sayfasında e-posta, ad, şirket olup olmadığı ve şifreyi girerek kaydolur, katalogdan medya organı ve rapor aralığını seçer, "ekle" ile sepetine ekler, başka eklemeyecekse sistemin belirlediği fiyatla "kaydet"e basar. Alternatif akışlar: özel aralık seçmek (ör. saatlik), aynı medya organını tekrar eklemeye çalışınca bilgi mesajı, birden fazla medya organı ekleme.

### 5.2 Hocanın kullanım senaryosu düzeltmesi

Web tabanlı poliklinik grubu senaryoları kişilere göre (kayıt görevlisi, veznedar, hasta, sistem admini başlıkları altında) yazmıştı; örneğin veznedar için "hastanın TC numarasını alır, TC numarası ile sigortası sorgulanır, sistem dönen cevaba göre indirimleri yapar", sistem admini için "doktorun hesabı yoksa sistem admin tarafından oluşturulur" adımları vardı (ekrandan, 01:10:00). Hoca belgenin karıştığını belirtti.

> **Hocanın vurgusu:** Kullanım senaryosu kişilere göre değil, senaryo senaryo yazılır. Her senaryo için hangi uygulamayı gerçekleştirdiği, senaryonun aktörü, yan aktörleri, adımları ve alternatif adımları ayrı ayrı belirlenir. Önemli olan use case belgesinin formatını, kapsamını ve mantığını doğru öğrenmektir.

Hoca alternatif senaryoların nerede yazıldığını da sordu; grubun verdiği örnek (doktorun hesabı yoksa sistem admininin yeni hesap oluşturması) senaryolara dağılmış durumdaydı. Bir grup üyesi senaryoları sıralama ve etkinlik diyagramlarında da açıkladıklarını söyledi.

### 5.3 Kullanım durumu diyagramları

İlk kütüphane grubunun kullanım durumu diyagramında iki taraf vardı: kullanıcı tarafı (öğrenci, öğretim üyesi, memur) ve yönetici tarafı. Kullanıcı ödünç alabilir ya da iade edebilir. Ödünç almak için parça okutma ve kart okutma gerekir; rezervasyon ödünç almaya bağlıdır. İadede parça okutulur, gecikme varsa ceza ödeme işlemi devreye girer. Yönetici akıllı kart oluşturma, envanter sorgulama, yeni parça ekleme ve kullanıcı izinlerini değiştirme işlemlerini yapar; izin değiştirme ödünç süresini değiştirme ve ödünç limitini değiştirme olarak iki dala ayrılır.

Poliklinik grubunun diyagramı ekranda şöyleydi (ekrandan, 00:40:00):

- Aktörler: Doktor, Kayıt Görevlisi, Randevu Görevlisi, Veznedar, Sigorta Sunucusu.
- Doktor → Hasta Bilgileri Sorgulama; bu durum «include» ile Güncelleme / Ekleme'yi içerir; Rapor / Reçete / Sevk «extend» ile Hasta Bilgileri Sorgulama'ya bağlanır.
- Kayıt Görevlisi → Hasta Kaydı; Hasta Kaydı «include» ile Hasta Bilgisi'ni içerir ve «extend» ile Randevu Ayarlama'ya bağlanır.
- Randevu Görevlisi → Randevu Ayarlama; Randevu Ayarlama «include» ile Randevu Sorgulama ve Hasta Bilgisi'ni içerir.
- Hasta Bilgisi «include» ile Hasta Bilgileri Sorgulama ve Ücreti Hesaplama'ya bağlanır.
- Veznedar → Ödeme İşlemleri; Ödeme İşlemleri «include» ile Ödeme, Ücreti Hesaplama ve Sigorta Durumu'nu içerir; Sigorta Durumu Sigorta Sunucusu aktörüne bağlıdır.

Hasta sisteme doğrudan müdahil olmadığı için aktör olarak çizilmemiş, yalnız bilgisi tutulmuştur. Web tabanlı poliklinik grubu ise doktor ve kayıt görevlisinin sisteme giriş yapabilmesi için hesaplara ihtiyaç duyduğunu, bu hesapları oluşturma yetkisini onlara vermek yerine ayrı bir "sistem admini" aktörü tanımladığını açıkladı.

Bir kütüphane grubu diyagramında «extend» ve «include» farkını şöyle kullandı: ödünç alma işleminin iki olası sonucu (öge envanterde varsa kullanıcının envanterine eklenmesi, yoksa rezerve edilmesi) «extend» ile; iade işleminden sonra ögenin envanterden çıkarılması zorunlu olduğu için «include» ile gösterildi.

### 5.4 İzlenebilirlik tablosu

İzlenebilirlik tablosu gereksinimleri, onları gerçekleştiren aktörler ya da bakış açılarıyla eşleştirir. İlk kütüphane grubunun tablosunda 13 gereksinim vardı (kiosktan kart okutabilme, parça okutabilme, iade süresini ve ödünç limitini değiştirebilme, ceza ödeme, ödünç alma, rezervasyon, yeni parça ekleme, ders kitabı alabilme, e-posta alma vb.); kullanıcı işlemleri kullanıcıyla, limit değiştirme ve parça ekleme yöneticiyle eşleştirildi. Bazı gruplar tabloyu gereksinim × bakış açısı matrisi olarak hazırlayıp ilgili hücrelere çarpı koydu. Bir kütüphane grubu tabloda her işlem için ön şartları yazdı: her işlemden önce kullanıcı adı ve şifreyle giriş, ödünç almak için ögenin stokta olması, iade etmek için ögenin kullanıcının envanterinde olması.

## 6. Nesneye Dayalı Modelleme ve Tasarım Diyagramları

### 6.1 Kavramsal ve tasarım sınıf diyagramı

Hoca bir grubun sınıf diyagramını gösterirken sordu:

**Soru:** Bu hangi aşamada yapılan sınıf diyagramı? Kavramsal mı, tasarım sınıf diyagramı mı? **Cevap:** Kavramsal. Hoca bunu onayladı: diyagramda metotlar yoktur.

Gruplar genellikle iki diyagram sundu: analiz aşamasında metotsuz kavramsal sınıf diyagramı, tasarım aşamasında metotlu sınıf diyagramı. Web tabanlı poliklinik grubunun kavramsal diyagramında doktor, hasta, kayıt görevlisi ve veznedar "fonksiyonel" sınıflar; randevu, fatura, muayene kaydı ve klinik diğer sınıflardı. Kayıt görevlisi bir randevu nesnesi, veznedar bir fatura nesnesi oluşturur; randevu doktor ve hastayla bire-çok ilişkilidir.

### 6.2 Sınıf diyagramlarındaki ilişki örnekleri

- **Bire-çok ilişki:** Bir envanterde birden fazla parça, bir yazarın birden fazla parçası, bir kullanıcının birden fazla ödünç kaydı olabilir. Diyagramda "1" ve "*" ile gösterilir.
- **Bileşim (kompozisyon):** Bir poliklinik grubunda belge sınıfı hasta sınıfına sıkı bağlıdır; hasta olmadan anlamını yitirir.
- **Birebir zorunluluk:** Her randevunun bir ödemesi, her doktorun bir polikliniği olmalıdır.
- **Kalıtım:** Bir kütüphane grubunda "Item" üst sınıfından kitap, DVD ve dergi sınıfları türer; her biri kendine özgü ek niteliklere sahiptir. Başka bir grupta "Product" sınıfının kitap, dergi ve DVD çeşitleri vardır; kullanıcı da öğrenci, öğretim görevlisi ve memur olarak farklı süre ve kitap limitleriyle ayrılır.
- **Arayüz:** Kiosk bir arayüzdür; ödünç alma, arama ve iade işlemleri bu arayüzde tanımlanıp gerçekleştirilir (implement). Menü ve giriş sayfası için ayrı arayüz sınıfları vardır.

Medya takip grubunun sınıf diyagramında kullanıcı sınıfı (ID, ad, e-posta, şifre; bireysel ya da şirket), rapor sınıfı (rapor ID'si, seçilen sıklıklar listesi, yayın ID'si, kullanıcıya özel fiyat, kullanıcı ID'si), sıklık seçenekleri (ayda bir, haftada bir, günde bir ve özel) ve yayın sınıfı (ID, günlük standart fiyat, tip: dergi, gazete, televizyon, radyo) bulunuyordu. Tasarım diyagramında getter/setter metotlarına ek olarak kullanıcıya yeni fiyat üreten bir metot ve yeni yayın oluşturulduğunda çalışan bir kurucu vardı.

Hoca bir poliklinik grubunun diyagramında çokluk eksikliğini sordu:

**Soru:** Poliklinik tarafında neden sayı yok? **Cevap:** Öğrenci doktorun poliklinik bilgisinin poliklinik sınıfında tutulduğunu ve bağlantının veri tabanında sağlandığını açıkladı; çokluk sorusuna doğrudan cevap verilmedi.

> **Ek bilgi (derste anlatılmadı):** UML'de bir ilişkinin her iki ucuna da çokluk (ör. 1, 0..1, 1..*, *) yazılır. Bir uç boş bırakılırsa ilişkinin kaç nesneyi bağladığı belirsiz kalır; hocanın sorusu büyük olasılıkla bu eksikliğe yönelikti.

### 6.3 Sıralama (ardışıl) diyagramları

Bir öğrenci sıralama diyagramına İngilizce adıyla değinince hoca Türkçe "ardışıl diyagram" demenin daha iyi olacağını söyledi. <!-- BELİRSİZ: Altyazıda öğrencinin kullandığı ad "seconds/artificial" diye bozuk yazılmış; hocanın önerdiği Türkçe adın "ardışıl" olduğu altyazıdan çıkarıldı. -->

İlk kütüphane grubunun "Parça Ödünç Alma" sıralama diyagramı ekranda şöyleydi (ekrandan, 00:15:00):

```text
Nesneler: Kullanıcı | Otomasyon Sistemi | Kayıt: Kullanıcı | Kayıt: Ödünç Alma | Parça

Kullanıcı -> Otomasyon Sistemi : Ödünç Alacağı Kitabı Okutur
Otomasyon Sistemi -> Parça : parça = getParça()
Kullanıcı -> Otomasyon Sistemi : Kütüphane Kartını Okutur
Otomasyon Sistemi -> Kayıt: Kullanıcı : ödünç_uygun = kullanıcıAlabilirMi(parça)
Otomasyon Sistemi -> Kayıt: Kullanıcı : parça_sayısı = getKullanıcıdakiToplamParça()
Otomasyon Sistemi -> Kayıt: Kullanıcı : tarihi_geçmiş_parça_var = getTarihiGeçmişKontrol()
alt [parça_sayısı < getÖdünçAlmaLimiti() AND ödünç_uygun AND !tarihi_geçmiş_parça_var]
    Kayıt: Kullanıcı -> Kayıt: Ödünç Alma : yeniÖdünçKaydı()
[else]
    -> Kullanıcı : Ödünç Alma İşlemi Başarısız
```

`kullanıcıAlabilirMi` kontrolü kullanıcı türüne bağlı kısıtları uygular (ör. öğretim üyesi ders kitabı alabilir, memur alamaz). İade senaryosunda son teslim tarihi ödünç kaydından istenir; tarih geçmemişse parça iade edilir, geçmişse önce ceza hesaplanır, parça iade edilmiş yazılır ve ceza kullanıcı hesabına uygulanır. Rezervasyonda kullanıcının elinde parça olmadığı için parça kodu elle girilir; ek olarak parçanın daha önce rezerve edilip edilmediği kontrol edilir.

Başka bir kütüphane grubunun dergi ödünç alma diyagramı (ekrandan, 01:45:00):

```text
Nesneler: kullanici : Member | dergi : Magazine | Kiosk

kullanici -> dergi : item = dergi        (dönüş: item)
kullanici -> Kiosk : odunc(item)
Kiosk -> dergi : item.getStok()           (dönüş: stok)
Kiosk -> Kiosk : now = LocalDate.now()
Kiosk -> Kiosk : tur = kullanici.getTur()
Kiosk -> Kiosk : item.setDeadline()
Kiosk -> kullanici : true
```

Kullanıcının türü, teslim tarihinin (1 ay ya da 3 ay) belirlenmesi için alınır. Diğer bir grubun diyagramında önce kart taranıp doğrulanır; rezervasyon başarılı olursa e-posta gönderilir; ödünç alma ve iadede ceza servisine gidilip ceza olup olmadığı kontrol edilir.

### 6.4 Etkinlik diyagramları

İlk kütüphane grubunun "Kitap Ödünç Alma Sistemi Kullanım Senaryosu Aktivite Diyagramı" (ekrandan, 00:20:00):

```text
Başlangıç
  -> karar: Parça Mevcut?
       Parça Mevcut     : Ödünç Alma Menüsünü Seç -> Parçayı Kiosk'a Okut -> Kütüphane Kartını Okut
       Parça Mevcut Değil: Rezervasyon Menüsünü Seç -> Parça Kodunu Gir
  -> birleştirme çubuğu
  -> karar: Ödünç Alma Limiti Aşıldı?  -> evet: Mesaj Göster -> İşlemi İptal Et -> Başlangıca dön
  -> karar: Teslim Tarihi Geçmiş Parça Var? -> evet: Mesaj Göster -> İşlemi İptal Et -> Başlangıca dön
  -> Ödünç Alabilir: İşlemi Onayla -> Mesaj Göster -> Bitiş
```

Aynı grubun iade diyagramında teslim tarihi geçmişse gecikme gün sayısı ve buna bağlı ceza hesaplanır, kart bakiyesi sorgulanır; bakiye yeterliyse ödeme otomatik alınıp veri tabanı güncellenir, yetersizse kullanıcı ödeme seçenekleri menüsüne yönlendirilir; ödeme başarısız olursa işlem iptal edilip başa dönülür. Yönetici limit değiştirme diyagramında giriş başarısızsa giriş ekranı tekrar gösterilir; başarılıysa kullanıcı grupları listelenir, grup seçilip yeni limit girilir ve onaylanır.

Hoca bu sunum sırasında sordu:

**Soru:** Etkinlik diyagramlarında farklı yerlerde (farklı bürolarda) yürüyen işlemler nerede birleşiyor, öyle bir örneğiniz var mı? **Cevap (öğrenci):** Tasarımda bunları birbirinden ayırdık; bir araya getirince kullanıcı tek seferde birçok işlem yapabildiği için sürekli alternatif senaryo göstermek gerekiyordu ve diyagram karmaşıklaşıyordu. Hoca cevabı kabul edip devam ettirdi.

Başka bir poliklinik grubunun randevu alma etkinlik diyagramından sonra hoca diyagramda "yerler"in tanımlanmadığını belirtti. <!-- BELİRSİZ: Hocanın "yerler konusunda da şey yapılabilirdi, onu tanımlamamışsınız" sözünün hangi diyagram öğesini (büyük olasılıkla etkinliklerin hangi birimde yapıldığını gösteren bölmeleri) kastettiği altyazıdan kesin değil. -->

> **Ek bilgi (derste anlatılmadı):** UML etkinlik diyagramında işlemlerin hangi aktör ya da birimde yapıldığı kulvarlarla (swimlane, bölme) gösterilir. Paralel ya da farklı birimlerde yürüyen akışlar çatallanma (fork) ve birleşme (join) çubuklarıyla ayrılıp birleştirilir. Hocanın iki sorusu büyük olasılıkla bu gösterimlere yönelikti.

### 6.5 Durum diyagramları

İlk kütüphane grubu bütün kullanım senaryoları için tek bir durum diyagramı çizdi. Kiosk başlangıçta kapalıdır; açılınca sistem testi yapılır. Test başarısızsa "servis dışı" durumuna, teknik destek talebiyle "bakım" durumuna geçilir; bakım durumu yeniden sistem testine bağlanır ve testler başarılı olana kadar bu döngü sürer. Testler başarılıysa kiosk "bekleme (idle)" durumundadır. Bekleme durumunda kitap okutulur ya da barkod girilir, kitap menüsü durumuna geçilir, kart okutulunca kullanıcı bilgileri gelir; her adımda vazgeçip beklemeye dönülebilir. Hoca diyagramın anlaşıldığını ama ikiye ayrılsa daha sade olacağını söyledi.

Poliklinik grubunun muayene durum diyagramında hasta randevu alır, muayene olur, tedavi uygulanır; başka kliniğe sevk edilirse yeniden muayene ve tedavi döngüsü işler, tedavi bitince taburcu edilir. Ödeme durum diyagramında veznedar borcu sorgular, sigorta varsa indirim uygulanarak tutar belirlenir, yoksa doğrudan ödeme şekli belirleme durumuna geçilir. Medya takip grubunun durum diyagramında daha önce seçilmiş bir medya organı ya da boş rapor aralığı seçilirse medya organı rapora eklenmez ve mesaj gösterilir.

## 7. Veri Tabanı Tasarımı ve Birim Testleri

### 7.1 Veri tabanı tasarımı

İlk kütüphane grubunun ER diyagramında üç ana varlık vardı: parça, envanter ve kullanıcı. Envanter parçaları içerir (bire-çok). Parçanın künyesi, tipi ve barkodu vardır; barkod benzersiz anahtardır. Kullanıcı ile parça arasındaki bire-çok ödünç ilişkisine alım tarihi ve geçerlilik süresi nitelikleri eklenir. Kullanıcının künye, bakiye ve grup nitelikleri vardır; kart numarası benzersiz anahtardır.

Bir poliklinik grubu ER diyagramında normalizasyonu artırmak, yani veri tekrarını azaltmak için başka tabloların birincil anahtarlarını yabancı anahtar olarak kullandı: poliklinik tablosunun birincil anahtarı doktor tablosunda tutularak poliklinik bilgisinin tekrar etmesi önlendi; aynı yapı sigorta ve hasta tabloları arasında da kuruldu. Randevu tablosu tarih ve saat bilgisini tutar ve doktor ile hasta arasında köprü görevi görür.

Medya takip grubunun SQLite veri tabanında yedi tablo vardı (ekrandan, 01:30:00); görünenler: content (id, publicationId, text), frequencyChoices (id, name), media (id, name), member (id, name, eMail, password, isCompany), publication (id, name, typeId, dailyPrice), report (id, publicationId, freqChoiceId, price, memberId).

Kullanılan teknolojiler: Java (IntelliJ ve Eclipse, Swing arayüzü) ile MySQL; Python ile Qt arayüzü ve SQLite; React ön uç, Django arka uç ve SQLite ile web uygulaması. UML çizimleri için Violet ve Visual Paradigm kullanıldı.

### 7.2 Birim testleri

- Bir kütüphane grubu testleri çoğunlukla veri tabanı üzerinden yaptı: veri tabanına basit bir sorgu gönderip yanıt gelip gelmediğine bakan bağlantı testi, bilinen bir kullanıcıyla giriş testi, tabloya veri ekleyip varlığını sorgulama, tablodan silme ve bakiyenin sıfırın altında olup olmadığını kontrol eden fonksiyon için pozitif bakiyeli kullanıcıyla `false` beklenen test.
- Bir poliklinik grubu JUnit ile hasta ekleme, hasta bilgisi sorgulama, doktor ve poliklinik bilgisi sorgulama testleri yazdı.
- Web tabanlı poliklinik grubu testi koddan önce yazdı; böylece kodu yazarken ne yapılacağı belliydi. Python ile yazılan testlerde hasta getiren metoda yanlış bir kimlik numarası verildiğinde `assertFalse` ile sonucun `false` olduğu, gerçek bir numarada veri tabanındaki kayıtla eşleştiği kontrol edildi.
- Bir kütüphane grubu barkod girişini sınayan testler yazdı: boş (null) değer, değer gönderilmemesi, barkodun 11 haneli olması, farklı hane sayısı, ondalıklı (double) sayı, harf içermesi, boşluk içermesi (boşluklar atılıp rakamlar birleştirilir), sıfırla başlaması ve bunların birleşimleri; kitap veri tabanında varsa adedi bir artırılır, yoksa yeni kitap eklenir (ekrandan, 02:05:00).
- Başka bir kütüphane grubu JUnit ile yaklaşık 32 test yazdı; ödünç alma ve rezervasyon modüllerinin kurallara uyup uymadığını sınadı.

**Soru:** Burada test oluşturdunuz mu hiç? **Cevap:** Evet, JUnit kütüphanesiyle testler oluşturuldu. Hoca testlerden birinin uygulama oturumunda gösterilmesini istedi.

## 8. Kapanış Tekrarı: Kalite Ölçütleri ve Özellikleri

Sunumlar bittikten sonra hoca ekran paylaşıp bir beyaz tahtaya maddeleri yazarak kısa bir tekrar yaptı. Amacı, diğer şubenin hocasıyla konuştuklarında iki şubede farklı ya da eksik anlatılmış görünen noktaları tamamlamaktı. Tahtadaki son hâli şöyleydi (ekrandan, 02:35:00):

```text
kalite ölçütleri ve özellikleri

Ölçme Eylemi
    Veri Toplama
    Yorumlama
    Hesaplama
Yazılım Maliyet tahmin yöntemleri
    Bilirkişi
    Delphi
    Analiz
    İstatistiksel Modeller: PNR - COCOMO
KULLANICI Testi: 1. Alfa Testi   2. Beta Testi
```

Hoca kalite metriklerini derste daha çok McCall üzerinden gördüklerini hatırlattı. McCall kalite özellikleri üçgeninde özellikler üç bakış açısına ayrılır: kullanıcılar açısından, çalıştıranlar açısından ve bakım yapanlar açısından. Diğer şubede ise aynı özellikler iç kalite ve dış kalite özellikleri (ölçütleri) olarak ayrılmıştır. Hoca iki sınıflandırmayı birleştirdi:

- **İç kalite özellikleri:** Yazılım üzerinde düzeltme yapacaklar için önemli olanlardır. Örnekler: test edilebilirlik, bakım yapılabilirlik, yeniden kullanılabilirlik, bir işletim sisteminden diğerine aktarılabilirlik (taşınabilirlik). Bunlar yazılımcıların içeriden anlayabildiği özelliklerdir.
- **Dış kalite özellikleri:** Kullanıcılar açısından gördüğümüz özelliklerdir. Örnekler: doğruluk (accuracy), hassaslık, dayanıklılık (robustness), diğer ortamlarla uyum, bütünlük (integrity; güvenlikle de ilişkilidir).

Yani ayrımın ölçütü bakış açısıdır: kullanıcının baktığı taraf dış kalite, yazılımcının içeriden gördüğü taraf iç kalitedir.

## 9. Kapanış Tekrarı: Yazılım Ölçme ve Maliyet Tahmin Yöntemleri

### 9.1 Büyüklük ölçütleri

Yazılımın ölçülmesi için önce büyüklük ölçülür ve büyüklükle ilişkili bir ölçüt belirlenir.

**Soru:** Büyüklük ölçütü olarak hangi ölçütler vardı? **Cevap:** Satır sayısı (Line of Code, LOC) ve fonksiyon puanı (Function Point).

### 9.2 Ölçme eylemi

Hoca ölçme işleminin adımlarını sordu ve tahtaya yazdı:

1. **Veri toplama:** Örneğin LOC için benzer yazılımlarda kaç satırlık, hangi büyüklükte bir yazılımın ne bütçeyle, ne kadar iş gücüyle, ne kadar sürede tamamlandığı toplanır.
2. **Yorumlama:** Toplanan verilerdeki ilişkiler belirlenir (ör. şu büyüklükteki bir yazılım şu kadar sürede bitti).
3. **Hesaplama:** Bu ilişkiler üzerinden yeni yazılım için hesaplama yapılır.

### 9.3 Maliyet tahmin yöntemleri

Hoca sunumlardan önce bu konunun üzerinde durduklarını hatırlatıp yöntemleri sordu. Bir yazılımın maliyetini tahmin etmek için farklı yollar vardır:

- **Bilirkişi takdiri:** Bir uzmanın deneyimine dayanan tahmin.
- **Delphi yöntemi:** Birden fazla bilirkişiyi yönlendirerek ortak tahmine varılması.
- **Analiz yöntemi:** Hoca bunun COCOMO içinde de kullanıldığını söylediklerini hatırlattı. <!-- BELİRSİZ: "Kokomo'nun içinde de kullanılan analiz yöntemi" ifadesinin hangi yöntemi kastettiği altyazıdan net değil. -->
- **İstatistiksel ya da analitik modeller:** Modelleme yapılarak tahmin yürütülür. Hoca bu modellerden isim sorduğunda bir öğrenci PNR dedi; hoca Putnam ve Rayleigh adlarını andı. Tahtada "PNR" yazıldı.
- **COCOMO (Constructive Cost Model):** Boehm tarafından geliştirilmiştir ve en yaygın kullanılan tahmin yöntemidir. Hoca derste iş gücünün ve sürenin nasıl hesaplandığını formülleriyle verdiğini hatırlattı.

Hoca bunların dışında Albrecht yöntemi gibi başka yöntemler de olduğunu ama derslerde bunları kullandıklarını söyledi. Bu konuların hepsi birbirine bağlıdır: kalite ölçütleri, ölçme işi ve ölçmeden yola çıkarak maliyet tahmini.

> **Ek bilgi (derste anlatılmadı):** PNR, Putnam-Norden-Rayleigh modelinin kısaltmasıdır; iş gücünün zamana göre dağılımını Rayleigh eğrisiyle modeller (Putnam'ın SLIM modeli bu yaklaşıma dayanır). Albrecht, fonksiyon puanı yöntemini geliştiren araştırmacıdır. Bu açıklamalar büyük olasılıkla hocanın kastettikleriyle örtüşür, ama derste ayrıntılandırılmadı.

> **Ders sonrası not:** Hoca COCOMO'nun açılımını "Constructive Cost Modeling" diye söyledi; modelin yaygın adı "Constructive Cost Model"dir (COnstructive COst MOdel).

## 10. Kapanış Tekrarı: Kullanıcı Testleri ve Sistem Testleri

Kullanıcı testleri yazılım geliştirme sürecinin en sonunda gerçekleştirilen testlerdir ve iki adımlıdır.

**Soru:** Alfa testi neydi? **Cevap (öğrenci):** Geliştirici ortamında yapılan test. Hoca tamamladı: geliştirici ortamında, kullanıcıya benzer bir grup oluşturulup yazılımı test etmesi istenir.

- **1. Alfa testi:** Geliştirici ortamında, kullanıcıya benzer bir grupla yapılır.
- **2. Beta testi:** En son yapılan testtir; adını "beta sürümü"nden bildiğimiz gibi, yazılım potansiyel kullanıcılara verilip onlar tarafından test edilir.

**Soru (öğrenci):** Beta testinde geliştiriciler kullanıcının üzerinde bir denetim (supervise) görevi görüyor mu, yoksa kullanıcıyı tamamen yalnız mı bırakıyorlar? **Cevap:** Genel amaçlı bir ürünse beta sürümü, daha önce firmanın uygulamalarını kullanmış potansiyel kullanıcılara gönderilir ya da açık ortama bırakılır; hata bulup destek olanlara bazen ödül bile verilir. Ürün genel amaçlı değil de belirli bir kullanıcı ya da şirket için hazırlanmışsa, beta sürümü bir süre o kullanıcılara açık kalır; şirkettekiler ürünü incelemek ve değerlendirmekle görevlidir. Bu durumda bildirilen hataları geliştiriciler birebir izler, yani denetim rolü geliştiricilere düşer.

Hoca sistem testlerini de hatırlattı: performans testi, dayanıklılık testi gibi test tipleri sistem testlerinin içinde yer alır ve derste tek tek anlatılmıştır.

## 11. Kapanış Tekrarı: SDLC ve Yazılım Yaşam Döngüsü

Son olarak hoca iki kavram arasındaki farkı vurguladı:

- **Yazılım geliştirme yaşam döngüsü (Software Development Life Cycle, SDLC):** Ürün geliştirme yaşam döngüsüdür; yazılım geliştirme aşamalarını (analiz, tasarım, gerçekleştirme, test) kapsar.
- **Yazılım yaşam döngüsü (Software Life Cycle):** Ürünün tamamının yaşam döngüsüdür; geliştirme fikrinin ortaya atılmasından başlayıp yazılımın kullanım dışı kalmasına kadar geçen süredir. Evreleri: yazılım fikrinin doğması, fikrin geliştirilmesi, yazılımın oluşturulması, yazılımın düzenli olarak kullanılması ve kullanım dışı kalması.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:35:12): Risk tablosunda hangi riskleri takip ederiz? Takip edilecek riskleri nasıl belirleriz?

> **Çözüm (derste verildi):** Yalnız gerçekleşme olasılığı yetmez. Her riskin gerçekleşme olasılığı ile gerçekleştiğinde yaratacağı etki (yıkım) çarpılarak riskin derecesi bulunur. Riskin takibi de maliyet olduğu için derecesi yüksek olan riskler izlenir; olasılığı ve etkisi düşük olanlar elenebilir.

**Soru 2** (derste sözlü, 01:11:01): Gösterilen sınıf diyagramı hangi aşamada yapılmıştır; kavramsal mı, tasarım sınıf diyagramı mı?

> **Çözüm (derste verildi):** Kavramsaldır, çünkü diyagramda metotlar yoktur. Metotlar tasarım aşamasındaki sınıf diyagramına eklenir.

**Soru 3** (derste sözlü, 00:20:56): Etkinlik diyagramlarında farklı yerlerde (farklı bürolarda) yürüyen işlemler nerede birleşir?

> **Çözüm (derste verilmedi):** Derste grup işlemleri ayrı diyagramlarda tuttuğunu söyledi. UML'de farklı birimlerde yürüyen işlemler kulvarlarla (swimlane) gösterilir; paralel akışlar çatallanma (fork) çubuğuyla ayrılıp birleşme (join) çubuğunda birleştirilir.

**Soru 4** (derste sözlü, 00:57:02): Sınıf diyagramında doktor-poliklinik ilişkisinin poliklinik ucunda neden sayı yok?

> **Çözüm (derste verilmedi):** İlişkinin her iki ucuna da çokluk yazılmalıdır. Grubun kabulüne göre her doktor bir polikliniğe aittir ve bir poliklinikte en az bir doktor vardır; bu durumda büyük olasılıkla doktor ucunda 1..*, poliklinik ucunda 1 yazılmalıdır.

**Soru 5** (derste sözlü, 02:24:36): Büyüklük ölçütü olarak hangi ölçütler vardı?

> **Çözüm (derste verildi):** Satır sayısı (LOC) ve fonksiyon puanı (FP).

**Soru 6** (ekrandan ve sözlü, 02:26:09; ekrandan, 02:30:00): Ölçme eyleminde hangi alt işlemler vardır?

> **Çözüm (derste verildi):** Veri toplama, toplanan verinin yorumlanması (ilişkilerin belirlenmesi) ve bunlar üzerinden hesaplama.

**Soru 7** (ekrandan ve sözlü, 02:27:04; ekrandan, 02:30:00): Yazılım maliyet tahmin yöntemleri nelerdir? İstatistiksel modellerden isim veriniz.

> **Çözüm (derste verildi):** Bilirkişi takdiri, Delphi yöntemi, analiz yöntemi, istatistiksel/analitik modeller (PNR) ve Boehm'in geliştirdiği COCOMO.

**Soru 8** (ekrandan ve sözlü, 02:31:50; ekrandan, 02:35:00): Kullanıcı testleri hangi sırayla yapılır? Alfa testi nedir?

> **Çözüm (derste verildi):** Önce alfa testi, sonra beta testi. Alfa testi geliştirici ortamında kullanıcıya benzer bir grupla yapılır; beta testi en son, potansiyel kullanıcılarla yapılır.

**Soru 9** (derste sözlü, 02:33:12): Beta testinde geliştiriciler kullanıcıyı denetler mi, yoksa tamamen yalnız mı bırakır?

> **Çözüm (derste verildi):** Genel amaçlı üründe beta sürümü potansiyel kullanıcılara gönderilir ya da açık ortama bırakılır, hata bildirenlere bazen ödül verilir. Belirli bir kuruma hazırlanan üründe beta sürümü o kurumun kullanıcılarına açılır, kullanıcılar değerlendirmekle görevlidir ve geliştiriciler bildirilen hataları birebir izler.

## Dersin Toparlaması

Bu son derste dönem projeleri üzerinden dönem boyunca görülen yazılım mühendisliği süreci baştan sona uygulanmış olarak görüldü: kapsam, kabul ve kısıtlarla başlayan proje planı; Gantt çizelgesi, ekip yapısı, süreç modeli seçimi ve adam-gün maliyeti; olasılık ve etkiye göre derecelendirilen risk tablosu; senaryo senaryo yazılması gereken kullanım senaryoları ve «include»/«extend» ilişkili kullanım durumu diyagramları; metotsuz kavramsal ve metotlu tasarım sınıf diyagramları; sıralama, etkinlik ve durum diyagramları; veri tabanı tasarımı ve birim testleri. Hocanın düzeltmeleri özellikle risk derecesi, kullanım senaryosu biçimi, çokluk gösterimi ve diyagramların sadeliği üzerineydi.

Kapanıştaki tekrar ise dersin kalite ve yönetim tarafını bağladı: McCall'ın üç bakış açısı ile iç/dış kalite ayrımı, LOC ve fonksiyon puanı gibi büyüklük ölçütleri, veri toplama-yorumlama-hesaplama adımlarından oluşan ölçme eylemi, bilirkişi, Delphi, analiz, istatistiksel modeller ve COCOMO gibi maliyet tahmin yöntemleri, alfa ve beta kullanıcı testleri ve SDLC ile yazılım yaşam döngüsü arasındaki fark.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
