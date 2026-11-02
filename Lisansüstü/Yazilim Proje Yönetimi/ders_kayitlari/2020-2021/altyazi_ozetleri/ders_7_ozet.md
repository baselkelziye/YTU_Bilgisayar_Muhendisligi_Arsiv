# Ders 7 Çalışma Özeti

## Genel Konular

- Ara sınav öncesi genel tekrar dersi.
- Yazılım proje yönetiminin üç bilgi alanı: proje yönetimi bilgi ve deneyimi, genel yönetim bilimi, yazılım mühendisliği teknikleri.
- Proje yönetimi yol haritası (Project Management Roadmap): projenin anlaşılması, tanımlanması, planlanması, çalıştırılması.
- Proje planının maddeleri.
- Şelale (waterfall) ve sarmal (spiral) model için iş kırılım yapısı (WBS) örnekleri.
- Faaliyetler arası ilişki tipleri, iş gücü ve görev ataması, kalite planı, SRS.
- Ekip ve organizasyon yapıları, PERT ve CPM, yazılım ölçümü ve maliyet tahmini tekrarı.
- Risk tablosu ve risk önlemleri.
- Makale sunum takvimi ve ara sınav duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Proje yönetimi yalnızca plan hazırlamak değildir. Plandan önceki hazırlık, plan, planın çalıştırılması ve izlenmesi bir bütündür.
- Proje yöneticisi üç alanda da bilgili olmalı: proje yönetimi, genel yönetim (örneğin organizasyon yapıları), yazılım mühendisliği teknikleri.
- WBS kullanılan yazılım geliştirme süreç modeline uygun kurulmalı. Öğrenciler spiral ve RAD gibi başka modeller için de WBS çıkarabilmeli.
- Yazılım projelerinde aktivite süreleri belirsiz olduğu için CPM yerine PERT kullanılır.
- "Ölçemediğinizi yönetemezsiniz."
- Uygulama projesinde en az üç evre görülmeli: hazırlık, planlama ve çalıştırma. Çalıştırma, en az gereksinim analizine kadar planlanan ile gerçekleşenin izlenmesi ve önlem alınmasıdır.
- SRS, müşteriyle yazılım geliştirici arasında bir anlaşma belgesidir. Proje planına eklenmesi uygundur.

## Kısa Tekrar Notları

- Proje yönetimi yol haritası (Jolyon Hallows):
  1. Projenin anlaşılması (understanding).
  2. Projenin tanımlanması (defining).
  3. Planın oluşturulması.
  4. Planın çalıştırılması (running) ve izlenmesi.
- Proje başarı faktörleri: zamanında bitme, bütçe içinde kalma, kapsamın uygun olması.
- Proje planı maddeleri: kapsam (hedef ve sınırlar), yazılım geliştirme modeli, risk analizi, varsayım ve kısıtlar, WBS, zaman çizelgesi ve aktivite ilişkileri, iş gücü, görev ataması, ekip yapısı, bütçe, kalite planı, SRS.
- WBS düzeyleri: 1.0 birinci düzey, 1.1 ikinci düzey, 1.3.1 üçüncü düzey.
- İlişki tipleri: FS, SS, FF, SF. Örnek FS: geliştirme bitince test başlar. Örnek SS: bilgi toplama başlayınca modelleme de başlayabilir.
- Spiral modelde her evrede aynı altı adım tekrarlanır: plan, müşteriden bilgi alma, risk analizi, tasarım, yapım (construction), müşteri değerlendirmesi.
- Kalite planı: kilometre taşları ve değerlendirme aralıkları (örneğin 6 ayda bir). Planlanan ile gerçekleşen zaman, iş gücü ve bütçe karşılaştırılır.
- Risk önemi = olasılık × etki. Önem sırasına göre sıralanır, önemsiz riskler izlenmez.
- Ara sınav: 27 Nisan 2021, online sistemde, büyük ihtimalle klasik.

## Detaylı Açıklamalar

### Kayıt hakkında

- Ders 7 kaydı iki parçadan oluşuyor ve parçalar arşivde ters sırayla birleşmiş.
  - İkinci parça (yaklaşık 02:15:39'dan sonra, 4,5 dakika) aslında dersin başı. Hoca derse "bu hafta önce genel tekrar yapacağım" diye başlıyor, sonra sistem hatası yüzünden toplantıdan çıkıp yeniden giriyor.
  - Birinci parça "ekran paylaşırken sistemde bir hata oluştu, o yüzden tekrar girdim" cümlesiyle başlıyor ve dersin geri kalanını içeriyor.
- Ders boyunca bağlantıda birçok kopukluk oldu. Bazı yerlerde birkaç dakikalık boşluklar var.

### Ders başı (ikinci parça)

- Bir öğrenci sınav öncesi slaytların yüklenip yüklenmeyeceğini sordu.
- Hoca 3-4 slayt dosyası paylaşacağını söyledi:
  - Üç özet slayt.
  - Fizibilite analizi, özellikle ekonomik fizibilitede geri ödeme (payback) analizi ve diğer analizler.
  - Bilgi sistemleri projelerinde proje yönetim aşamalarıyla ilgili genel bir dosya.
- Slaytlar derse giriş yapılan online sisteme yüklenecek.

### Yazılım proje yönetiminin bilgi alanları

- **Proje yönetimi bilgi ve deneyimi:** fizibilite, kaynak ve zaman yönetimi, proje adımlarının takibi. Örneğin alt yüklenicilerin ve dış kaynaklı (outsource) işlerin takibi ve bunların kuralları.
- **Genel yönetim bilimi:** işletme bilimindeki organizasyon bilgisi. Hem kurum içindeki bir proje birimi olarak hem de ekip yöneticisi olarak gerekli.
- **Yazılım mühendisliği teknikleri:** bu alan eksik olmamalı.
- Üç alanda da bilgili olan biri başarılı bir proje yöneticisi olabilir.

### Kaynaklar

- Jolyon Hallows, *Information Systems Project Management*, AMACOM yayınları. Hoca ders notlarını bu kitaptan ve Pressman'ın *Software Engineering* kitabının proje yönetimi bölümlerinden hazırladı.
- Proje yönetimi yol haritası kavramı bu kitaptan alındı. Project Management Institute (PMI) web sayfasında da benzer bir anlatım var.
- Kitabın eski baskılarının temel içeriği internette bulunabilir.

### Proje yönetimi yol haritası

- **Projenin anlaşılması (Understanding the Project):**
  - Proje nereden geldi, kim başlattı?
  - Öncesinde bitmiş veya bitmek üzere olan bir proje var mı?
  - Proje sıfırdan mı başlıyor, bir yazılımın iyileştirilmesi mi, yoksa yalnızca fizibilite projesi mi?
  - Projenin sahibi hangi departman? Bu departmanın son projesi neydi?
  - Proje sahibi başarı faktörlerinden (zaman, bütçe, kapsam) hangisine öncelik veriyor? Plan buna göre hazırlanır.
- **Projenin tanımlanması (Defining the Project):**
  - Çıktılar belirlenir: kod, SRS belgesi, use case diyagramları, plan dokümanı, tasarım belgeleri, test verileri, kullanıcı belgeleri.
  - Değişiklik takibinin nasıl yapılacağı tanımlanır. Bu, yapılandırma yönetimi (configuration management) işidir.
  - Örnek: plan hazırlandıktan sonra proje sahibi kapsam değişikliği veya yeni çıktı isterse bu değişiklik plana ve bütçeye nasıl aktarılacak?
- PMI bu iki adımı ayırmaz. Bunlar birlikte "proje giriş" veya "hazırlık" aşaması olarak da anılır.
- Sonra proje planı oluşturulur ve çalıştırılır.

### Proje planının maddeleri

- Bir öğrenci plan maddelerini saydı: başlangıç tarihi, çalışacak kişi sayısı, süre, bitiş tarihi, yapılacaklar, ekonomik fizibilite ve risk analizleri.
- Hocanın listesi:
  1. Projenin kapsamı: hedefi ve sınırları.
  2. Yazılım geliştirme süreç modeli.
  3. Risk analizi.
  4. Varsayımlar ve kısıtlar. Bunlar risk kategorilerine benzer kategorilerle tanımlanabilir.
  5. Alt aktiviteler (WBS).
  6. Zaman çizelgesi ve aktiviteler arası ilişkiler (Gantt, PERT).
  7. İş gücü.
  8. Görev ataması ve ekip yapısının belirlenmesi.
  9. Bütçe.
  10. Kalite planı.
  11. Yazılım gereksinim spesifikasyonu (SRS).
- Bu maddeler veya IEEE'nin proje planı standardı uygulama projesinde kullanılabilir.

### WBS örneği: şelale modeli

- Bir öğrenci şelale modelinin adımlarını saydı: ön inceleme ve analiz, tasarım, gerçekleştirme, test ve bakım.
- İkinci düzeye kadar WBS:

```text
1.0 Analiz
    1.1 Bilgi toplama
    1.2 Modelleme
    1.3 SRS hazırlama
2.0 Tasarım
    2.1 Mimari tasarım
    2.2 Ayrıntılı tasarım
3.0 Gerçekleme
    3.1 Kodlama
    3.2 Veri tabanının yaratılması
    3.3 Veri tabanına ilk bilgilerin girilmesi
4.0 Test
    4.1 Bütünlük testi
    4.2 Sistem testi
    4.3 Kullanıcı testi
```

- Üçüncü düzeye inilirse modelleme şöyle ayrılabilir: use case diyagramı, use case belgesi, kavramsal sınıf diyagramı.
- Bir öğrenci "1.1" numarasının hangi düzey olduğunu sordu. Cevap: ikinci düzey.
- WBS hiyerarşik numaralandırmayla veya ağaç diyagramıyla gösterilebilir.

### WBS örneği: sarmal (spiral) model

- Spiral modelin ana fikri: süreç yinelemelidir ve her yinelemede aynı adımlar yapılır.
- Bu yüzden analiz, tasarım, gerçekleme, test diye ayrılmaz. Evreler kullanılır:

```text
1.0 Prototip oluşturma
    1.1 Plan hazırlama
    1.2 Müşteriden bilgi alma
    1.3 Risk analizi yapma
    1.4 Analiz ve tasarım
    1.5 Yapım (construction): ayrıntılı tasarım, kodlama, mühendislik testi
    1.6 Müşteri değerlendirmesine sunma
2.0 Ürün oluşturma        (2.1-2.6 aynı adımlar)
3.0 Ürün zenginleştirme   (3.1-3.6 aynı adımlar)
4.0 Bakım                 (4.1-4.6 aynı adımlar)
```

- WBS ile adımlar daha kolay izlenir. Her adımın süresi, benzer büyüklükteki projelere bakılarak tahmin edilir. Her adım için iş gücü ve oradan bütçe bulunur.

### Faaliyetler arası ilişkiler ve zaman çizelgesi

- Bir öğrenci ilişki tiplerini saydı: finish to finish, start to finish, start to start, finish to start.
- Örnekler:
  - FS: geliştirme bitmeden test başlamaz.
  - SS: bilgi toplama başlayınca modelleme de başlayabilir. Gecikme eklenebilir; örneğin bilgi toplama başladıktan 3 gün sonra use case diyagramları ve kavramsal sınıf diyagramları hazırlanmaya başlanır.
- Örnek süre: önceki projelerden gelen bilgiye göre bilgi toplama bir hafta veya 15 gün sürecektir.

### İş gücü, görev ataması ve kalite planı

- Zaman çizelgesi ve PERT yardımıyla eski projelerle karşılaştırılarak iş gücü belirlenir. Tipi de yazılır. Örnek: 6 kişi-ay sistem analisti, 1 kişi-ay proje yöneticisi.
- Sonra görev paylaşımı yapılır ve buna göre bütçe hazırlanır.
- Kilometre taşı (milestone): projede gelinen önemli noktalar.
- Kalite planında kilometre taşları ve değerlendirme aralıkları belirtilir.
  - Dış sponsor varsa dönüm noktalarını beklemeden değerlendirme isteyebilir. Örneğin 6 ayda bir değerlendirme.
  - Değerlendirmede planlanan ile gerçekleşen zaman, iş gücü ve bütçe karşılaştırılır.

### Yazılım gereksinim spesifikasyonu (SRS)

- Gereksinim analizinde belli bir noktaya gelinmişse SRS proje planına eklenebilir. Proje kapsamını açıklar.
- Test dersindeki bağlantı: kullanıcı testi fonksiyonel gereksinimlere, sistem testi fonksiyonel olmayan gereksinimlere göre yapılır.
- SRS'de müşterinin istediği ve geliştiricinin gerçekleştireceği fonksiyonlar tanımlanır.
- Fonksiyonel gereksinimler hiyerarşik maddelerle yazılabilir veya modellenebilir: use case diyagramı, veri akış diyagramı (data flow diagram) ve bunların belgeleri.
- Hoca SRS konusunu yazılım mühendisliği derslerinden bilinen bir konu olarak gördü. Sorulan öğrenciler sorun olmadığını söyledi.

### Ekip ve organizasyon yapıları (tekrar)

- Ekip yapıları:
  - Demokratik: tüm üyeler eşit. Az kişilik ekiplerde kullanılır.
  - Şeflik: kararları bir kişi alır. Kararların doğruluğu şefin yeteneğine bağlıdır.
  - Hiyerarşik: bir proje yöneticisine (takım lideri) bağlı ekipler ve şefler. Kalabalık ve karmaşık profesyonel projeler için uygundur.
- Organizasyon yapıları:
  - Fonksiyonel: yazılım geliştirme işinin uzmanlık alanlarına göre ekipler (sistem analizi, programlama, pazarlama, bakım).
  - Proje: projenin modüllerine göre ekipler. Örnek: muhasebe-mali işler uygulamasında stok kontrol, finans, MIS ve müşteri ekranları takım liderleri.
  - Matris: çalışanlar hem birim yöneticilerine (yazılım mühendisleri, sistem analistleri, programcılar, test ekibi lideri) hem de proje yöneticilerine raporlar.
- Fonksiyonel ve proje organizasyonu farkı: fonksiyonel yapı yazılım geliştirme işinin alt başlıklarına, proje yapısı projenin kendi alt işlemlerine (modüllerine) göre kurulur.

### PERT ve CPM

- Bir öğrencinin cevabı: PERT ile proje gidişatı ve kritik yolu etkileyen kısımlar görülür. Kritik yolun eforu azaltılarak nasıl ilerletileceği de görülür.
- CPM süreleri belli kabul eder. Yazılım projelerinde ise her proje için analiz, tasarım, gerçekleştirme sürelerinin sabit olduğu söylenemez.
- PERT önce her aktivite için kötümser, iyimser ve en olası süreyi tahmin eder. Sonra hesaplama yapılır.
- CPM daha basittir ve belirlilik hâlinde kullanılır.

### Yazılım ölçümü ve maliyet tahmini (tekrar)

- Metrikler, yazılım ürününün, kullanıcı ve bakım özelliklerinin ve kalite faktörlerinin ölçülebilir hedeflere dönüşmesini sağlar.
- LOC doğrudan ölçümdür: satırlar sayılır. Objektif değildir ama büyüklük hakkında fikir verir.
- İşlev noktası dolaylı ölçümdür. Hem büyüklük hem karmaşıklık bilgisi verir. İlk olarak ticari uygulamalar için geliştirilmiştir.
  - Ham değer: sayı × ağırlık faktörü toplamı.
  - Düzeltme: $FP = \text{sayı toplamı} \times (0{,}65 + 0{,}01 \sum F_i)$, 14 soru 0-5 arası puanlanır.
- Maliyet tahmin yöntemleri: bilirkişi takdiri, Delphi (bilirkişi takdirinin genişletilmişi, çoklu karar verme), analiz yöntemi, istatistik modeller.
- Analiz yönteminde alt parçaların tahminleri birleştirilince toplam süre beklenenden çok uzun çıkabilir. Hallows'un kitabında buna "birleştirme şaşkınlığı" deniyor. Bu yüzden tahminin üzerinden birkaç kez geçilir ve süreler kısaltılır.
- İstatistik modeller: COCOMO ve Putnam KLOC kullanır. Albrecht yöntemi işlev noktası kullanır.

### Risk analizi

- Risk tablosu: her risk kategorisinden riskler belirlenir. Her riskin olasılığı ve etkisi (yıkımı) tahmin edilir. Böylece önemi ortaya çıkar.
- Riskler önemine göre sıralanır. Belli bir değerin altındakiler izlenmez, önemliler izlenir.
- Her risk için önlem belirlenir. Önlemlerin de maliyeti vardır. Olasılık artarsa önlemler devreye alınır.
- Örnekler:
  - Kilit ekip elemanının işten ayrılması: yedek eleman almak, sözleşme imzalamak, ücretini artırmak.
  - Yazılımda kullanılacak bir donanımın siparişinin gecikmesi.

### Uygulama projesi

- Uygulama konusu için ayrı cevap verilmiyor. Hoca konuları listeye ekliyor; uygun değilse cevap veriyor.
- Beklenti: seçilen konuda proje planı sıfırdan hazırlanacak. Proje en az gereksinim analizine kadar çalıştırılacak. Daha önce bir modülün programının da hazırlanması istenmişti.
- Planlanan ile gerçekleşen arasındaki farklar izlenecek ve önlemler belirtilecek.

### Duyurular

- **Makale sunum takvimi:**
  - 4 Mayıs 2021: iki öğrenci. Biri makalesindeki anketin mevcut sonuçlarını sunacak.
  - 11 Mayıs 2021: yaklaşık beş-altı öğrenci, iki kişilik bir grup dahil.
  - Bir günde en çok beş kişi sunum yapabilir. Kalan öğrenciler sonraki haftaya kalabilir.
- Makale ödevinde öğrenciler seçtikleri makaleyi analiz edip sunacak. Sonra IEEE formatında yaklaşık 3-4 sayfalık bir yazı teslim edecekler. Referansların verilmesi önemli.
- **Ara sınav (27 Nisan 2021):**
  - Şu an için klasik sınav düşünülüyor. Test olursa 2-3 gün önceden sisteme yüklenecek.
  - Sınav, derslerin yapıldığı online sistemdeki "ödevler/sınavlar" bölümünden yapılacak.
  - Cevaplar kâğıda yazılıp fotoğrafı yüklenebilir veya Word'de yazılıp yüklenebilir. Yükleme sorunu olursa hocaya e-posta atılmalı.
- Dersteki iki slayt sisteme yüklenecek.

### Ders sonrası notlar

- Altyazıdaki "Jolion Halos/Halovsun" Jolyon Hallows, "Amakom/Amacom" AMACOM, "Presma" Pressman, "Kokomo" COCOMO, "Carlock/K-Log" KLOC, "DERF/DELF" Delphi, "Sipral" spiral, "kiyerarşik/yerelşik" hiyerarşik olmalı.
- Bir öğrenci ilişki tiplerini sayarken "start to finish to start" gibi karışık ifadeler kullandı. Dört tip şunlardır: FS, SS, FF, SF.
- Hoca 5. derste ara sınavın "büyük ihtimalle test usulü" olacağını söylemişti. Bu derste klasik sınav düşündüğünü söyledi. Kesin şekil sınav sistemine yüklenen sorulardan anlaşılacak.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
