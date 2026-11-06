# Ders 13 Genişletilmiş Notu: Uygulama Projesi Sunumları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi
- 2. 1. Sunum: Birim Dönüştürme Uygulaması
- 3. 2. Sunum: Makine Öğrenmesiyle Kredi Onayı
- 4. 3. Sunum: Düşme Tespitiyle Enkaz Belirleme
- 5. 4. Sunum: Film Veritabanı ve Paylaşım Sistemi
- 6. 5. Sunum: Demirbaş ve Zimmet Envanter Yönetimi
- 7. 6. Sunum: Süreç, Risk ve İç Kontrol Platformunun İkinci Fazı
- 8. 7. Sunum: Uçak İçi Alışveriş ve Ağırlama Sistemi
- 9. 8. Sunum: Üniversite İş ve Staj Portalı
- 10. Makale Sunumu: Proje Yönetiminde Duygusal Zeka
- 11. 9. Sunum: Havalimanı Hizmetleri ve Gelirleri Sistemi
- 12. Geri Bildirimlerden Çıkan Akademik Öğütler

## 1. Dersin Çerçevesi

Bu derste dönemin uygulama bölümüne devam edildi. Gruplar, hazırladıkları proje yönetimi raporlarını sundu. Sunumların büyük bölümü aynı iskeleti izledi: proje kapsamı, yazılım geliştirme modeli, risk analizi, iş kırılım yapısı (Work Breakdown Structure, WBS), zaman çizelgesi, görev ataması, bütçe, kalite planı ve yazılım gereksinim belirtimi (Software Requirements Specification, SRS).

Bu yüzden ders, tek bir konunun anlatımı değil, dönem boyunca görülen konuların farklı projelerde uygulanışını görme fırsatıdır. Hocanın katkısı sunum sonlarındaki sorularda ve araya girdiği kısa düzeltmelerde toplanıyor. Bu notta her sunum konu ve amaç, yöntem ve plan, sonuç ve hocanın geri bildirimi başlıklarıyla verilir. Dersteki sırada, bir de makale sunumu yer aldı.

## 2. 1. Sunum: Birim Dönüştürme Uygulaması

### 2.1 Konu ve Amaç

Grup, belirli birimler arasında dönüşüm yapan basit bir uygulama geliştirdi. Dönüşüm alanları uzaklık, alan, ağırlık, hacim, sıcaklık, mutfak birimleri, veri birimleri ve sayı sistemi birimleridir. Kullanıcı soldan bir alan seçer, açılan ikinci pencerede değeri girer, hangi birimden hangi birime dönüştüreceğini seçer ve sonucu görür. Değer girmek için sanal bir tuş takımı da kullanılabiliyor.

Hedef kitle, ödev ve çalışmalarında birim dönüşümüne ihtiyaç duyan öğrencilerdir. Uygulamanın çevrimdışı çalışması ve öğrencilerin İngilizce bilgisini desteklemesi de amaçlanmış. Grubun iki odak noktası var: kullanıcı dostu basit bir arayüz ve Java sayesinde farklı platformlarda sorunsuz çalışma. Tek kısıt tasarım kısıtıdır. Uygulama ilkokul seviyesindeki öğrencilerce de kullanılabilsin istendiği için tasarım basit tutulmuştur.

### 2.2 Yöntem ve Plan

Geliştirme modeli olarak şelale (waterfall) seçildi. Gerekçe, projenin basit olması ve bir adımın çıktısının sonraki adıma sorunsuz, maliyetsiz aktarılabilmesidir.

Proje küçük ve karmaşık olmadığı için riskler de düşük görüldü. İki risk tanımlandı. Her risk için bir gösterge ve bir aksiyon yazılması dikkat çekici:

- **Kontrolsüz proje yönetimi:** Projede tek kişi çalışacağı için ortaya çıkabilir. Gösterge, Gantt şemasındaki sürelere uyulmamasıdır. Aksiyon, projeye başka bir yazılımcı istihdam edilmesidir.
- **Tasarımın hedeflendiği kadar basit olmaması:** Gösterge, kullanıcı geri dönüşleridir. Aksiyon, daha basit arayüzlü yeni bir sürüm çıkarmaktır.

İş kırılım yapısı 3 seviyeli, 5 adımlıdır:

- Gereksinimlerin belirlenmesi.
- Risklerin analizi.
- Kabul testi planı.
- Yazılım geliştirme: mimari, tasarım, kodlama ve test.
- Kalite değerlendirme.

Plan 24 Mart'ta başlayıp 26 Mayıs'ta bitecek şekilde yapıldı ve grup bu plana uyabildiğini söyledi. Bütün işler tek kişiye atandı. Bütçe olarak yalnız uygulamanın geliştirileceği bilgisayar için 12.000 TL gider yazıldı.

Kalite planı şu adımlardan oluşuyor:

- SRS dokümanının gözden geçirilmesi (28 Mayıs'ta yapıldı).
- Asıl dönüşümü yapan ana sınıfın incelenmesi (30 Mayıs'ta yapıldı).
- Model, görünüm ve kontrol modülleri için birim testler (henüz yapılmadı). Model arka plandaki yazılım mantığıdır, görünüm kullanıcıyla iletişim kuran arayüz sınıflarıdır, kontrol kullanıcının veri girdiği kısımdır.
- Kullanılabilirlik testi: kullanıcılara uygulama kullandırılır, geri dönüşlere göre aksiyon alınır.
- Kabul testi: projenin eksiksiz tamamlandığını gösterir.

> **Ders sonrası not:** Takvimin bitişi 26 Mayıs olarak verildi, kalite planındaki gözden geçirmeler ise 28 ve 30 Mayıs tarihli. Sunumda bu iki adımın takvim içinde nerede olduğu söylenmedi.

### 2.3 Sonuç

Uygulama geliştirilmiş durumda. Kullanılabilirlik testi, birim testler ve kabul testi henüz planlanan aşamada.

### 2.4 Hocanın Geri Bildirimi

Hoca bütçe anlatılırken araya girdi: kişi iş gücü sayılmamış. Grup bunu doğruladı. Yani proje tek kişilik olsa da yalnız bilgisayar gideri yazan bütçe eksik kalıyor.

Asıl soru proje takibiyle ilgiliydi.

**Soru:** Hoca, planlananla gerçekleşen arasındaki kıyaslamayı nasıl yapacağını sordu. **Cevap:** Grup önce projenin zaten bittiğini ve Gantt şemasına uyulduğunu söyledi. Hoca bunun soruyu karşılamadığını belirterek projeyi yeni başlıyormuş gibi düşünmesini istedi. Sürüm kontrolü önerisini de kabul etmedi. Grup sonunda kazanılan değer analizi (Earned Value Analysis) dokümanına veri girerek plana uygun ilerleyip ilerlemediğini izleyebileceğini söyledi. Hoca, böyle bir aracın kullanılacağını onayladı.

**Soru:** Hoca bu aracın hangi zamanlarda çalıştırılacağını sordu. **Cevap:** Önemli görülen adımlarda, yani kilometre taşlarında (milestone).

> **Hocanın vurgusu:** Kilometre taşlarına ulaşıldığında neyin planlandığına bakılır. Karşılaştırma hem bütçe, hem zaman, hem kapsam açısından yapılır. Hoca duymayı beklediği cevabın bu olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Kazanılan değer analizinde üç temel büyüklük vardır: planlanan değer (PV), kazanılan değer (EV) ve gerçekleşen maliyet (AC). Zaman sapması $SV = EV - PV$, maliyet sapması $CV = EV - AC$ ile bulunur. Negatif değerler sırasıyla takvimin gerisinde kalmayı ve bütçenin aşılmasını gösterir. Böylece hem zaman hem bütçe tek bir ölçüm noktasında okunabilir.

## 3. 2. Sunum: Makine Öğrenmesiyle Kredi Onayı

### 3.1 Konu ve Amaç

Grup, banka müşterisinin kredi talebinin makine öğrenmesi yöntemleriyle değerlendirilmesini proje olarak aldı. Sürecin elle yürütüldüğü varsayıldı. Amaç, insan faktörünü azaltıp hızlı ve otomatik bir tahmin yapmaktır. Kullanılan müşteri bilgileri yaş, yıllık gelir, ev sahibi ya da kiracı olma, çalışma süresi, kredi puanı ve kredi geçmişinin süresidir.

Bu sunumun ayırt edici yanı bir senaryo kurgulamasıdır. Grup, derste anlatılan "proje ilerledikçe değişiklikler olabilir ve plan güncellenebilir" durumunu göstermek istedi.

### 3.2 Yöntem ve Plan

Başlangıç kapsamı dört işten oluşuyor: müşteri verilerinin elde edilip işlenmesi, verilerin eğitim ve test olarak ayrılması, modellerin kurulması, modellerin testi. Senaryonun başlangıcında müşteriye modelin doğru çıktı vermesinin mi, anlaşılır olup görselleştirilmesinin mi daha önemli olduğu soruluyor. Müşteri, modelin daha doğru çıktı vermesinin önemli olduğunu, çok anlaşılır olmasa da sorun olmadığını söylüyor.

Proje zor görülmediği için genel riskler tanımlandı:

- Takvimde gecikme. Aksiyon: sürenin uzatılması.
- Proje ekibinin bilgi olarak yetersiz kalması. Aksiyon: personelin eğitilmesi.
- Kritik bir personelin ayrılması. Aksiyon: ekipteki diğer kişilerin de o konuda bilgi sahibi olması.
- Müşteri taleplerinin karşılanamaması. Aksiyon: planı güncelleyip isteneni yapmak.

WBS şelale modeliyle kuruldu: analiz, tasarım, gerçekleme. Veri toplama analize dahil edildiği için analiz aşaması daha uzun. Gerçeklemede biri bitip diğeri başlayan bir düzen yok. Birden fazla model kurulacağı için model kurma ve bitenlerin testi eş zamanlı yürüyor.

### 3.3 Senaryo: Yeni Talep ve Plan Güncellemesi

Gerçekleme aşamasındaki bir toplantıda müşteri yeni bir talep getiriyor: modellerin daha net anlaşılması için görselleştirilmesi. Bunun üzerine plan güncelleniyor. Tek bir talebin nelere dokunduğu şöyle sıralandı:

- Kapsam değişiyor: modelin görselleştirilmesi kapsama ekleniyor.
- Planlanan adımlar değişiyor: gereksinim tablosunda gerçekleme kısmına görselleştirme ekleniyor.
- Zaman planı ve projenin bitiş tarihi değişiyor.
- Kaynak ve personel ihtiyacı değişiyor.
- Bunlara bağlı olarak maliyet değişiyor.

Grubun genel sonucu şudur: proje planları müşteri talebi, kaynak, personel, zaman ya da maliyet nedeniyle değişebilir. Plan revize edilir. Fakat eski proje planları yok edilmez, sürüm bilgileriyle saklanır.

### 3.4 Hocanın Geri Bildirimi

Hoca risk tablosunu yeniden açtırdı ve tablonun takibini sordu.

**Soru:** Bu tabloyu nasıl takip ediyorsunuz, takip edeceklerinizi nasıl belirliyorsunuz? On beş risk çıktığını düşünelim. Küçük bir projede bunların hepsi takip edilemez. Nasıl azaltırsınız? **Cevap:** Grup bir azaltma yapmadığını ve nasıl yapılacağını bilmediğini söyledi. Cevabı hoca verdi.

Tabloda etki ve olasılık oluşturulur. Bunlardan riskin derecesi çıkar. Sonra bir kural konur: şu sayıdan itibaren olanlar takip edilecek. Derecesi daha az olanlar kapsam dışında kalır. Takip edilecekler de aralarda izlenir. Hocanın anlatımı 4. sunumdaki sözüyle birlikte şöyle yazılabilir:

$$\text{Risk derecesi} = \text{etki} \times \text{olasılık}$$

> **Hocanın vurgusu:** Etki ve olasılık, takip edilecek riskleri ayıklamak için oluşturulur.

## 4. 3. Sunum: Düşme Tespitiyle Enkaz Belirleme

### 4.1 Konu ve Amaç

Grup, deprem bölgesinde yaşayan insanların akıllı telefonları için bir mobil uygulama planladı. Amaçlar üç başlıkta toplanıyor:

- Depremden sonra oluşabilecek enkazın tespit edilmesi.
- Enkazın konum verisinin ilgili kurum ve kuruluşlarla paylaşılması.
- Enkaz altında kalan kullanıcının ya da göçük altında kalması olası kişilerin bilgilerinin bu kurumlarla paylaşılması.

Hedefler ise şunlardır: akıllı telefonların en az %90'ında kullanılabilen bir uygulama, düşme tespiti için bir makine öğrenmesi modeli ve bilgilerin iletilmesi için sunucu tabanlı bir iletişim yapısı.

### 4.2 Yöntem ve Plan

Proje kaynakları yazılım mimarı, proje yöneticisi, Android ve iOS geliştirme uzmanları, web geliştirme uzmanı, yazılım analisti, DevOps uzmanı, yazılım test elemanı, jeofizik mühendisi ve arayüz tasarımcısıdır. Jeofizik mühendisinden backend kısmında danışman gibi yararlanılıyor. Kaynak tablosunda her kaynağın görevinin başlangıç ve bitiş tarihi ile kalan çalışması gösterildi. Yazılım analisti birçok işte karşımıza çıkıyor, proje sonunda ise en önemli iş test elemanlarına düşüyor.

WBS 5 temel işten oluşuyor:

- **Proje gereksinimleri:** son kullanıcı gereksinimleri (mobil ve web), dokümantasyon, sistem gereksinimleri, yazılım mimarisi, kullanıcı arayüz tasarımı (web ve mobil).
- **Geliştirme ortamı hazırlığı.**
- **Proje geliştirme:** frontend, backend (web servisleri ve makine öğrenmesi) ve mobil uygulama.
- **Test.**
- **Yükleme:** sunuculara dağıtım ve uygulama mağazalarında yayın.

İşler arasında ilişki var. Bazıları öncülü bitmeden başlamıyor, bazıları aynı anda başlıyor. Üç kilometre taşı anlatıldı:

- Web ve mobil arayüz tasarımlarının bitişi.
- Frontend'in bitişi. Bu noktada backend ve frontend tamamlanmış olur ve yalnız mobile yoğunlaşılabilir. Bu yüzden önemli bir eşik sayıldı.
- Testler tamamlanıp sürüm adayı onaylandıktan sonra ilk sürüm paketinin oluşması. Burada hem sunucu tarafı hem mobil uygulamalar yayına çıkıyor.

Mobil uygulamada Android ve iOS için aynı adımlar var: sensörlerin (jiroskop, ivme ölçer gibi) ayarlanması, uygulama izinlerini de içeren ayarlar kısmı ve bildirimler. Tek bir hibrit uygulama da düşünülebilirdi, ama iki ayrı uygulama planlandı. Bu yüzden iki ayrı uzmana ihtiyaç var. Takvim açısından ilginç bir ayrıntı da yayınlama süresidir: Android'de iki gün yazıldı, iOS'ta onay daha uzun sürebildiği için tahmini bir süre konuldu. Uygulama mağazalarının ücretleri de bütçeye eklendi.

> **Ders sonrası not:** Grup mağaza ücretlerini yıllık olarak anlattı ve Android için 25 dolar civarı dedi. Android mağazasının bu ücreti büyük olasılıkla yıllık değil, tek seferlik bir kayıt ücretidir.

### 4.3 Riskler

Grup bunların başlangıç riskleri olduğunu, proje ilerledikçe güncellenebileceğini, karşılaşılmayacağı anlaşılırsa kaldırılabileceğini söyledi.

- **İnternet bağlantısının kesilmesi:** Bluetooth üzerinden veri aktarımı. Grup bunu önemli bir risk sayıp projeye dahil etti.
- **Kullanıcının izin vermemesi (konum, Bluetooth):** İznin neden gerekli olduğunu açıklayan bilgilendirici mesajlar gösterilir.
- **Zarar gören alanda kullanıcı sayısının az olması:** Enkaz tespitinde çevredeki kişilerden de yararlanılıyor. Kişi azsa yerel olarak tespit zorlaşır, sunucu tarafı devreye girer.
- **Sunucunun aşırı yüklenmesi:** Sunucuların önüne yük dengeleyici (load balancer) konur. Yine de tıkanıklık olabileceği için yedek bir sunucuya aktarım planlanır.
- **GPS'in bozuk ya da hatalı veri üretmesi:** Çevrede aynı uygulamayı kullananların konum verisiyle düzeltme yapılır.

### 4.4 Maliyet ve Gecikmenin Etkisi

Toplam planlanan maliyet 109.213 TL olarak verildi. Dağılım yaklaşık olarak şöyle:

- Malzeme yaklaşık 60 bin TL. Bunun sebebi iOS cihazın pahalılığı ve dövizle ödenen yıllık ücretler.
- Çalışma yaklaşık 50 bin TL.

Ara toplam $60.000 + 50.000 = 110.000$ TL'dir (ara adım eklendi). Bu, 109.213 TL'lik toplamla yaklaşık olarak uyumludur.

Grup, projenin geliştirilmesine başladığını ve backend'in bir kısmını yazdığını söyledi. Bazı adımlar geç kaldığı için varyansla maliyet 130 bin TL'ye kadar çıkıyor. Planlanana göre bu fark $130.000 - 109.213 = 20.787$ TL'dir (ara adım eklendi).

Bu sunumun en öğretici kısmı, gecikmenin maliyet kalemlerini farklı etkilemesidir. Malzeme projenin başında bir kez alındığı için proje uzasa da neredeyse etkilenmez. Çalışma kalemi ise saatlik ücretlere bağlıdır. Proje aksadıkça kişilerin ücretleri işlemeye devam eder. Bu yüzden varyansın çoğu çalışma kaleminden gelir. Gecikmenin maliyeti 14.441 TL olarak gösterildi.

> **Ders sonrası not:** Planlanan maliyet ile gecikme maliyetinin toplamı $109.213 + 14.441 = 123.654$ TL eder. Bu, söylenen 130 bin TL ile aynı değildir. Aradaki farkın kaynağı sunumda açıklanmadı.

<!-- BELİRSİZ: 00:31:14'te "%30 bin liralık" geçiyor; 00:31:59'daki ifadeye göre 130 bin TL olarak alındı. 00:32:13'te "50-100 liralık yıllık ücretler" deniyor, slayttaki tutar altyazıdan okunamıyor. 00:33:22'deki "3600 liralık bir projenin 3600'luk kısmı" ifadesi anlaşılmıyor; gerçekleşen tutar burada verilmedi. -->

### 4.5 Hocanın Geri Bildirimi

Hoca bu grubun planlanan ile sonraki durum arasındaki değişiklikleri de incelediğini belirtti.

## 5. 4. Sunum: Film Veritabanı ve Paylaşım Sistemi

### 5.1 Konu ve Amaç

Grup, internet üzerinden çalışan bir film veritabanı ve paylaşım sistemi için proje planı hazırladı. Amaçlar, profesyonel ve izleyici sinema kitlesini bir araya getirmek, yorum gibi araçlarla etkileşim sağlamak, herkese bir arşiv ortamı sunmak ve sinemaseverler arasında sosyal bir ortam oluşturmaktır. Erişilebilirlik web arayüzüyle geniş tutulmak istendi.

Plan kapsam, varsayımlar, kısıtlar, kaynak hesapları, risk analizi ve bütçe tahminini içeriyor. Teslimden sonraki destek, bakım ve onarım süreçleri için de kısa bir çalışma yapılmış.

### 5.2 Yöntem ve Plan

Proje organizasyonunda bir ana yüklenici yapısı düşünüldü. Ekipte farklı roller var, bir üye birden fazla role sahip olabilir. Şimdilik gerekmese de olası bir alt yüklenici riskini ele alabilmek için organizasyona alt yüklenici kontrolü eklendi.

Sistemde iki kullanıcı türü var:

- **Yönetici:** Kullanıcıları, filmleri ve filmlerle bağlantılı oyuncu, yönetmen gibi kayıtları ekleme, silme, güncelleme yetkisine sahip.
- **Üye:** Film ve kişileri görüntüleyebilir, yorum yapabilir, kendi bilgilerini güncelleyip silebilir, kendine film arşivi oluşturabilir.

İş gücü ve zaman tahmininde derste görülen yöntemler kullanıldı. Fonksiyon noktası (function point) yönteminde veri iletişimi, dağıtık veri işleme gibi 14 madde puanlanarak bir etki derecesi elde edildi. Kullanıcının sisteme giriş, çıktı ve sorgulama sayıları için de ağırlık faktörü bulundu. Ardından COCOMO modeliyle iş hacmi ve proje süresi hesaplandı. Dil PHP seçildi, araştırmaya dayanarak 40, 50, 60 gibi değerler arasından 40 alındı. Sonuçlar:

- Proje süresi yaklaşık 6,7 ay.
- Proje süresi ve programcı sayısı hesaba katılınca toplam maliyet yaklaşık 225.000-230.000 TL.

Ara hesaplar sunumda gösterilmedi, yalnız sonuçlar söylendi.

> **Ders sonrası not:** Altyazıda 40 değeri "sınıf sayılarının satır sayıları" diye geçiyor. Fonksiyon noktasından satır sayısına geçiş bağlamında bu büyük olasılıkla fonksiyon noktası başına satır sayısıdır.

Araçların seçiminde açık kaynak ağırlıkta: geliştirme ortamı Visual Studio Code, veritabanı MySQL, dil PHP, proje planı için Microsoft Project'in Linux'ta çalışan açık kaynak karşılığı olarak tanıtılan ProjectLibre, belgeler için LibreOffice.

WBS şelale yapısında:

- **Analiz:** Bilgi toplama, modelleme ve SRS. Müşteriyle yakın temasın olduğu, kullanıcı durumları ve arayüzlerin belirlendiği aşama.
- **Tasarım:** Mimarinin seçilmesi, veritabanı tasarımı, tabloların oluşturulması.
- **Gerçekleme:** Kodlama, verilerin işlenmesi. Birim testleri eş zamanlı yazılıyor, kalite kontrolü bu aşamada başlıyor.
- **Test:** Bütünlük ve kullanıcı testleri.
- **Kullanıcı dokümanları.**

<!-- BELİRSİZ: 00:41:23'te 5 ana madde deniyor ama dört tanesi (analiz, tasarım, gerçekleme, test) sayılıyor. Beşinci madde olarak sonradan anlatılan kullanıcı dokümanları yazıldı, slayttan doğrulanamadı. -->

### 5.3 Riskler ve Kalite

Risk tablosu etki ve olasılıkla kuruldu:

| Risk | Etki | Olasılık | Not |
|---|---|---|---|
| Eğitim ve deneyim eksikliği | Büyük | Düşük | |
| Kullanıcının uygulamayı verimli kullanamaması | Yüksek | Orta | Eğitim ve demolar |
| Personel üzerinde pandemi etkisi | Oldukça yüksek | Orta-yüksek | Uzaktan çalışmanın etkisi belirsiz |
| Takvimde gecikme | Orta | Söylenmedi | |
| Yazılım ortamının hazırlanamaması | Orta | Düşük | Bileşenler açık kaynak |
| Yeterli testin olmaması | Yüksek | Düşük | Birim testler gerçeklemeyle başlıyor |
| Ekipten kişilerin ayrılması | Söylenmedi | Düşük | |

Kalite tarafında kodlama standartlarına uyum statik ve dinamik kod analiziyle kontrol edilecek. Kodlama sırasında birim testleri yazılacak. Ürün çıkmaya yaklaştıkça entegrasyon ve sistem testleri yürütülecek. Kısa aralıklarla sürüm çıkıp müşteriye demo yapılması, proje sonunda kabulü kolaylaştıracak.

### 5.4 Hocanın Geri Bildirimi

Hoca yine risk takibini sordu ve soruyu adım adım daralttı.

**Soru:** Risk takibini nasıl yapmayı planlıyorsun? **Cevap:** Grup testlerin kontrolü, müşteri demoları ve günlük toplantılar gibi bir takip yolu anlattı.

**Soru:** Yani hangi riskleri takip edeceksin? **Cevap:** En önemlisi kullanıcının uygulamayı verimli kullanması. Bunun kontrolü kısa aralıklı sürümler ve demolarla yapılacak. Yazılım ortamının hazırlanması ise belki yalnız başlangıçta sorun olur.

**Soru:** Daha sıkı takip etmen gereken başka hangi risk var? **Cevap:** Takvimde gecikme. Hoca, grubun kendi önem sırasına göre personel üzerindeki pandemi etkisinin geldiğini hatırlattı. Grup bunu moral ve motivasyonu yüksek tutma açısından ele aldı.

**Soru:** Takip etmeyeceklerin hangileri olabilir? **Cevap:** Olasılığı düşük olduğu için ekipten ayrılma riski, daha seyrek takip edilebilir.

> **Hocanın vurgusu:** Takip edilmeyecekler zaten etki derecesi ile olasılık çarpıldığında altta kalanlardır. Bu değerler onun için yazılır.

Sorular dizisi, risk tablosunun yazıldıktan sonra kenara konacak bir belge olmadığını gösteriyor. Tablodan bir sıralama çıkmalı, bu sıralama da takip planını belirlemelidir.

## 6. 5. Sunum: Demirbaş ve Zimmet Envanter Yönetimi

### 6.1 Konu ve Amaç

Grup, bir müşterinin demirbaş, personel ve personele ait zimmet kayıtlarını tutan bir web sistemi planladı. Zimmet tutanağı PDF olarak alınabiliyor. Gerekçe somuttur: müşteri bu kayıtları Excel üzerinden yönetiyor. Muhasebe incelemelerinde kayıtlarla gerçekte var olan demirbaşlar karşılaştırıldığında farklar çıkmış. Bazı demirbaşlar kayıtlarda yok ya da kayıp. Amaç, bu yönetimi daha otomatik ve düzenli hale getirmektir.

### 6.2 Yöntem ve Plan

Model olarak şelale seçildi. Gerekçe, müşterinin hâlihazırda kullandığı bir sistemin bulunması, yani gereksinimlerin belli olmasıdır. Aşamalar inceleme, gerçekleme, test, dağıtım ve bakımdır.

Altı risk belirlendi. Düşük olanlar için bile azaltma planı hazırlandı:

- **Kullanıcıların alıştıkları sistemden yenisine uyumunun zor olması:** Önem orta, olasılık düşük. Gereksinimler ve iş iyi analiz edilip planlanırsa bu sorunun olasılığı düşer.
- **Zimmet kayıtlarının yine iyi yönetilememesi ve karmaşanın tekrarlaması:** Excel'de her iade ya da yeni ihtiyaçta elle güncelleme gerekiyordu, geciken işlem unutulabiliyordu. Önlem, dağıtım sonrası takipte kurumda yetkili bir personel belirlenmesidir.
- **Teslimden sonra farklı ihtiyaçlar çıkması:** Geliştirme sırasında çıkan ufak bir şey bile teknik olarak büyük sıkıntı yaratabilir. Önlem, bileşenleri ve sistemi daha esnek tasarlamaktır.
- **Kapsamın bütün ihtiyaçları karşılayacak kadar geniş tutulması:** Analiz ve tasarımın iyi yapılmasıyla ilgilidir.
- **Ekipten birinin ayrılması:** Proje küçük olduğu için olasılık düşük görüldü.
- **Maliyetin belirlenenden yüksek olması:** Yazılım projelerinde en büyük maliyet yazılımcılar ve zamandan kaynaklanıyor.

Zaman çizelgesi MS Project'te 3. seviyeye kadar indirilerek hazırlandı. Bölümler başlama ve analiz, tasarım, gerçekleme, test, dağıtım ve bakımdır. Her aşamaya geçiş, önceki aşamanın bitmesi ön koşuluna bağlandı. Her bölümün sonuna bir kilometre taşı konuldu. Gerçekleme iki parçaya ayrıldı: ortamların oluşturulması, depo (repo) açılması gibi teknik işleri içeren hazırlık ve bileşenlerin tek tek yazıldığı geliştirme.

İş gücü ve bütçe birlikte verildi: bir proje yöneticisi, bir iş analisti, bir orta seviye ve bir kıdemli olmak üzere iki yazılımcı. Grup, bu seçimle sürenin kısaldığını söyledi. Donanım maliyetinin genellikle yazılım firmasınca karşılandığı varsayıldı. Yazılım kalemi, MS Project ve IntelliJ IDEA gibi araçların toplam maliyetidir. En büyük kalem yine personeldir. Müşteri ziyaretleri için 2.000 TL ayrıldı. Toplam bütçe 97.000 TL olarak planlandı.

Kalite planı şunları içeriyor:

- SRS'in iyi hazırlanması ve müşteriyle birlikte üzerinden geçilmesi, UML kullanım durumu (use case) diyagramlarıyla gösterim.
- Git pull request ile kod gözden geçirme: bir geliştirici isteği açar, diğerleri inceleyip onaylar, sonra kod aktarılır.
- Bütün servis ve bileşenler için birim testleri.
- Veritabanında veri tutarlılığı için ACID kurallarına bağlı kalınması.
- Test aşamasında çeşitli test araçlarının kullanılması.

SRS'te backend için Java ve Spring Boot (IntelliJ IDEA), frontend için TypeScript ve Angular (VS Code), veritabanı için Microsoft SQL Server seçildi. Hazır şablon kullanılması süreyi kısaltacak. Use case diyagramında yönetici ve kullanıcı rolleri var. Kullanıcı demirbaş, personel, zimmet işlemlerini ve bakım onarım kaydını yapabiliyor, listeleri dışa aktarabiliyor. Bazı ekranları görebiliyor, ama pasifleme ve güncelleme yapamıyor. Diyagramlar Lucidchart ile çizildi.

<!-- BELİRSİZ: 00:57:37'de hazırlık işleri "FITBOK'a tesaf açılışı ve RIPOL'un oluşturulması" diye geçiyor; büyük olasılıkla bir kod barındırma hizmetinde hesap ve repo açılışı. Hizmetin adı altyazıdan kesinleşmiyor. 01:03:41-01:04:17 arasındaki prototip gösterimi ekrana bağlı, ayrıntısı altyazıda anlaşılmıyor. -->

### 6.3 Sonuç

Grup planla birlikte bir prototip de hazırladı ve sisteme giriş ile demirbaş ekleme ekranlarını gösterdi.

### 6.4 Hocanın Geri Bildirimi

Hoca zaman çizelgesi anlatılırken araya girdi.

**Soru:** Bu projenin PERT görünümü var mı? **Cevap:** Grup hazır bir görünümü olmadığını belirtmedi, hoca bunun MS Project'ten alınabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** PERT görünümü, işleri düğüm ve bağımlılık okları olarak bir ağ üzerinde gösterir. Gantt şeması işlerin takvimdeki yerini öne çıkarırken, PERT ağı öncül ilişkilerini ve kritik yolu daha açık gösterir. Her iki görünüm de aynı plan verisinden üretilebilir.

**Soru:** Kalite planında ayrı bir gözden geçirme planına gerek var mı, yoksa bunu Gantt şemasında mı gösterdin? **Cevap:** Grup, kastettiğinin pull request ile yapılan kod gözden geçirmeleri olduğunu ve bunun kod kalitesini, dolayısıyla projenin kalitesini artıracağını anlattı.

Hoca bütçede iş gücünün aylık ve saatlik maliyet gibi birimlere göre belirlendiğini not etti. Risk, kalite ve prototip kısımlarında ise ayrıntıya girilmeden geçilmesini istedi.

## 7. 6. Sunum: Süreç, Risk ve İç Kontrol Platformunun İkinci Fazı

### 7.1 Konu ve Amaç

Grup, yürümekte olan gerçek bir projenin ikinci fazını, birçok parametresini değiştirerek sundu. Konu, bir şirketin süreçlerini, risklerini ve iç kontrollerini tek dijital platformda uçtan uca yönetmesini sağlayan bir uygulamadır. Uygulama şirketin içinde geliştirilmiyor, dış bir yazılım tedarikçisinden alınıyor.

İkinci fazın gerekçesi yaygınlaştırmadır. İlk fazda yapılan pilot çalışmada son kullanıcıya gidilince yeni ihtiyaçlar ortaya çıktı. Bunlar tek tek not alındı ve SRS için önemli bir veri oldu. Kapsam, bu yeni taleplerin karşılanmasıdır. Modüller süreç yönetimi, süreç performans yönetimi, risk yönetimi, iş sürekliliği ve iç kontroldür. İki örnek verildi:

- **Vekâlet sistemi:** İzne çıkan bir çalışan yetkilerini başka bir yöneticiye ya da çalışana aktarabilecek.
- **Onay akışları:** Süreçler uygulama içinde onaylardan geçecek. Vekâlet sistemi de bu akışlar kesilmesin diye gerekiyor.

### 7.2 Başarı Faktörleri ve Kazanımlar

Başarı faktörleri tarihlere bağlandı:

- İkinci fazın pilot çalışmasının 2021 sonuna kadar başarıyla hayata geçmesi. Bu pilotta yeni geliştirmeler iş birimlerince test edilip onaylanacak.
- Üst yönetimce önceliklendirilen yaygınlaştırmanın 2022 ilk çeyreğinin sonuna kadar tamamlanması.
- İç kontrol, kurumsal risk yönetimi ve süreç yönetiminin daha entegre ve verimli hale gelmesi, şirketin risk yönetimi kaslarının güçlenmesi.

Beklenen kazanımlar daha etkin süreç, risk ve iç kontrol yönetimi, standartların gelişmesi, operasyonel kontrollerin güçlenmesi, her seviyede karar alma süreçlerinin desteklenmesi, bilgi ve veri akışının doğru zamanlı ve otomatik olması ve müşteri memnuniyetidir.

### 7.3 Yöntem: Neden Kanban?

Bu sunumda modelin gerekçesi özellikle açık verildi. İki neden var:

- **Dışa bağımlılık:** Şirkette çevik dönüşüm bekleniyor. Fakat ekip sistem, mimari ve bilgi güvenliği gibi birçok ekibe bağımlı. Bir uygulama geliştirilirken bütün paydaşların eforu gerekiyor. Bu durumda sprint koşmak, yani Scrum uygulamak pek mümkün olmuyor.
- **Fazın içindeki yeni talepler:** Birinci fazda proje sürerken eş zamanlı yeni talepler geldi, takip edilen maddeler durdurularak ek geliştirmeler yapıldı. Aynı şey ikinci fazda da beklendiği için Kanban en uygun yöntem görüldü.

> **Ek bilgi (derste anlatılmadı):** Scrum işi sabit süreli sprintlere böler ve sprint içindeki kapsamı korumaya çalışır. Kanban ise sürekli bir iş akışı kullanır. İşler pano üzerinde aşamalardan geçer, devam eden iş sayısı sınırlanır. Bu yüzden öncelikleri sık değişen ya da dış ekipleri bekleyen işlerde daha rahat uygulanabilir.

### 7.4 Plan, Takvim ve Riskler

Proje ekibi dört gruptan oluşuyor:

- BT süreç yönetimi: analiz yapıyor, testleri tamamlıyor.
- Yazılım geliştirme tedarikçisi.
- İş birimleri: uygulamanın sahipleri ve son kullanıcıları.
- Danışmanlık: pilot çalışmaya destek, eğitim ve yeni geliştirmelerin aktarımı.

Takvimde başlangıç 12 Nisan, tamamlanma 17 Temmuz. Bu aralık 96 gündür, yani grubun söylediği gibi yaklaşık 3 aydır (ara adım eklendi). Tedarikçi hafta sonu da çalıştığını bildirdiği için hafta sonları takvime dahil edildi. Görsel takvimde yeşil tamamlananları, mavi üzerinde çalışılanları, sarı sıra bekleyenleri gösteriyor.

İlk kısım hazırlıktır. Yazılım ekipleri henüz tam olarak dahil değildir. Dokümantasyon planı ve SRS'e karşılık gelen kavramsal tasarım dokümanı bu kısımda tamamlanır. Modül işleri başlamadan önce uyarlama ve entegrasyon çalışmalarının bitmesi gerekir. Sonra modül bazında ilerlenir. Her modül için sıra şöyledir:

```text
geliştirme -> tedarikçi entegrasyon testi -> BT testleri
-> kullanıcı kabul testi (UAT) -> onay -> canlıya alma
```

Kilometre taşları entegrasyonun tamamlanması ile iş süreçleri, risk ve iç kontrol modüllerinin tamamlanıp canlıya alınmasıdır.

Riskler şöyle ele alındı:

- **Süreç, risk ve kontrol sahiplerinin projeyi sahiplenmemesi:** Etki çok yüksek, olasılık düşük, çünkü birinci faz yapıldı ve uygulama zaten kullanımda. Aksiyon her seviyede güçlü iletişim. BT tarafındaki ekip iş birimleriyle yakın çalışıyor, haftalık toplantılar yapılıyor, maddeler Jira'dan izleniyor.
- **Piyasa koşulları nedeniyle şirket önceliklerinin değişmesi:** Olasılık ve etki orta. Alınabilecek tek aksiyon süreyi uzatmak.
- **Geliştirme süresinin uzaması nedeniyle projenin uzaması:** Olasılık düşük. Modül bazlı ilerlendiği için bir modül bitince doğrudan canlıya alınıyor, son kullanıcı etkisini hemen görüyor. Kısa vadeli kazanımlar öne çıkarılıyor.
- **Hedeflenen kaynak ayrımının sağlanamaması.** Bu risk üzerinde durulmadan geçildi.

Bütçe adam-gün üzerinden çıkarıldı. Proje takviminden elde edilen toplam adam-gün eforu birim maliyetle çarpıldı ve yaklaşık 200 bin TL bulundu.

### 7.5 Sonuç ve Hocanın Geri Bildirimi

Proje başlamış ve devam ediyor. Hoca, SRS belgesinin raporda olup olmadığını sordu. Grup, belgenin fonksiyonel ve teknik gereksinimler olarak iki başlıkta raporda yer aldığını söyledi.

## 8. 7. Sunum: Uçak İçi Alışveriş ve Ağırlama Sistemi

### 8.1 Konu ve Amaç

Grup, uçak içi eğlence sistemine eklenen bir katalog planladı. Sistem 350 yolcunun erişimine olanak sağlamalı. Yolcular önlerindeki koltuğun arkasına yerleştirilmiş dokunmatik ekranlardan kataloğa ulaşıyor. İnternet bağlantısı sayesinde hem gümrüksüz (duty free) hem dışarıdan alışveriş yapılabiliyor. Grup, internet bağlantısı olmayan bugünkü sistemlerde böyle bir özelliğin bulunmadığını, ama birkaç yıl içinde geleceğini öngördüğünü söyledi.

### 8.2 Yöntem ve Plan

Proje planında roller ve sorumluluklar ile başlatma, planlama, yürütme, izleme-kontrol ve kapatma süreçleri tanımlandı. Geliştirme modeli olarak havacılıkta DO-178 için tarif edilen model alındı. Kodlama aşaması ise Scrum ile planlandı: her biri 2 hafta olan 7 sprint, yani $7 \times 2 = 14$ hafta (ara adım eklendi).

> **Ders sonrası not:** Altyazıda model adı "bir model" diye geçiyor. Havacılık bağlamında bu büyük olasılıkla V modelidir.

> **Ek bilgi (derste anlatılmadı):** DO-178, uçuş sistemlerindeki yazılımların sertifikasyonunda kullanılan bir kılavuzdur. Yazılımın kritiklik seviyesine göre hangi planların, gözden geçirmelerin ve doğrulama faaliyetlerinin gerektiğini belirler. Bu yüzden havacılık projelerinde kalite planı, proje içi tercihlerden çok bu sürecin aşamalarına göre şekillenir.

Risk yönetiminde her riske etki seviyesi ve olasılık verilip bir risk skoru çıkarıldı. Örnek olarak tecrübeli personelin ayrılması ve yeni işe alım yapılana kadar takvimin gecikmesi verildi. Sınıflandırma şöyle:

| Risk skoru | Seviye |
|---|---|
| 4 ve altı | Düşük |
| 4'ten büyük, 8 dahil | Orta |
| 8'den büyük | Yüksek |

Her risk için bir plan yapılıyor. Aylık risk azaltma toplantılarında aksiyonların durumu gözden geçirilip riskler kapatılmaya çalışılıyor. Düşük riskler için plan öngörülmedi. Bu, hocanın diğer sunumlarda sorduğu eşik mantığının bir uygulamasıdır. Pandeminin havacılığı çok etkilemesi nedeniyle pandemiyle ilgili çevresel risklere öncelik verildi.

Zaman çizelgesi MS Project'te 4 seviyeli, 89 kalemli bir iş listesidir. Aktivitelerin çoğu önceki aktivitenin bitmesini bekliyor, bazıları aynı anda başlıyor. Bu ilişkiler kaynak durumuna, personele ve işin yapısına göre belirlendi. Her tasarım gözden geçirmesinin sonuna kilometre taşı konuldu. Önemli tarihi olan görevler bitiş tarihiyle sınırlandırılarak bir kritik yol belirlenmeye çalışıldı.

Kilometre taşlarında üç temel çizgi (baseline) alınıyor:

- Kavramsal tasarım sonrası **fonksiyonel baseline**.
- Ön tasarımdan sonra, gereksinimler alt ekiplere tahsis edilince **tahsis baseline'ı**.
- Kritik tasarım sonrası **ürün baseline'ı**.

Kaynaklar bir proje sponsoru, bir proje yöneticisi, iki kıdemli iş analisti, bir iş analisti, bir kıdemli frontend ve bir frontend yazılımcı, iki kıdemli backend yazılımcı ve bir test mühendisidir. Kullanılan yazılım araçları da kaynak olarak planlandı. Görevler MS Project'te kişilerin çalışma yüzdesine göre atandı. Kaynak aşımı görülmediği için fazla mesai ya da ek istihdam plana alınmadı. Bütçe toplam 217 bin dolar. Ana kalemler personel ve yazılım araçlarıdır.

Kalite planının ekseni otorite denetimleridir. DO-178'e uygun projelerde otoritelerin gözden geçirdiği katılım aşamaları (Stage of Involvement, SOI) vardır. Bu aşamalar dört tanedir:

- Yazılım planlamasından sonra.
- Yazılım geliştirmeden sonra.
- Doğrulamadan sonra.
- Sertifikasyon aşamasında.

Bunlara hazırlık için iç gözden geçirmeler tanımlandı. SRS'te gereksinimler fonksiyonel, arayüz, sistem ve fonksiyonel olmayan diye dört kalemde toplandı. Her gereksinime bir kod verildi.

<!-- BELİRSİZ: 01:23:34'te kaynak listesinin sonu ("öğrencisi olarak öngördüm projeyi") anlaşılmıyor. -->

### 8.3 Hocanın Geri Bildirimi

Hoca, grubun kendi iş hayatıyla ilgili bir alandan bir proje alıp planını oluşturduğunu belirtti.

## 9. 8. Sunum: Üniversite İş ve Staj Portalı

### 9.1 Konu ve Amaç

Grup, bir üniversitenin bilgisayar mühendisliği öğrencileri için iş ve staj portalı planladı. Bölümdeki karışık ve düzensiz ilan panolarını dijital ortama taşımak, öğrencilerin ilanları kolay takip etmesini ve şirketlerin daha çok öğrenciye ulaşmasını sağlamak amaçlanıyor. Şirketler üye olup belli sürelerle ilan veriyor, öğrenciler de kullanıcı adı ve şifreyle sisteme giriyor. Sistem abonelik benzeri bir mekanizmayla kendini finanse edecek. Gelir, öğrenci bursu ve bölüm ihtiyaçları için kullanılacak.

### 9.2 Yöntem ve Plan

Model olarak çevik yöntem seçildi. Gerekçe, ürünü müşterinin karşısına en az hatayla çıkarmak, değişiklik ya da hatayı en kısa sürede çözebilmektir. Grup stand-up toplantıları, yinelemeler ve retrospektif, sürekli entegrasyon, Kanban, refactoring ve kaynak kod yönetimi gibi başlıkları saymaya başladı. Hocanın bu konudaki geri bildirimi aşağıda.

Risk planında üç risk ve tabloda etki, önlem stratejisi, çözüm etkinliği ve sorumlu sütunları var:

- **Gereksinimlerin belirlenmesinde gecikme:** Etkisi test faaliyetlerinin gecikmesidir. Çözüm müşteri ilişkilerini güçlendirmek, düzenli toplantılar yapmak, çıkan sorunları hızla çözmek, gereksinim takibi ve konfigürasyon yönetimi için yardımcı yazılım almaktır.
- **Test için öğrencilerin zamanında hazır olmaması.**
- **Yazılımın hazır olmaması:** Düzenli toplantılar yapılır, gerekli aksiyonlar alınır.

WBS'de proje planının altında veritabanı tasarımı, kodlama ve arayüz tasarımı ve test yer alıyor. Aktiviteler dört kullanıcı grubuna ayrılıyor:

- **Öğrenci:** üyelik, ilan ve başvuru görüntüleme, CV oluşturma.
- **Firma:** üyelik, başvuru değerlendirme, ilan ekleme, kampanya görüntüleme.
- **Memur:** kampanya satış onayı, gider ve gelir ekleme.
- **Yönetici:** haber-duyuru-ilan ekleme, kampanya ekleme, firma cezası verme ve kaldırma, ilan engelleme, memur ekleme, gelir-gider sorgulama.

İş gücü, grubun "adam-ay da denebilir" diyerek açıkladığı birimle verildi:

| Rol | Adam-ay |
|---|---|
| Proje yöneticisi | 15 |
| Veritabanı sorumlusu | 10 |
| Yazılım geliştirme sorumlusu | 10 |
| Test sorumlusu | 4 |
| Kalite sorumlusu | 2 |
| İş analisti | 4 |

Bu tablonun toplamı $15 + 10 + 10 + 4 + 2 + 4 = 45$ adam-aydır (ara adım eklendi). Görevler Jira'da Kanban panosuyla atanıyor, günlük Scrum uygulanıyor. Bütçe iki fazlı: 5. ayda 500.000 TL, proje tesliminde 1.000.000 TL, toplam $500.000 + 1.000.000 = 1.500.000$ TL.

Kalite planı işlevsellik, mevzuata uygunluk, zamanında teslim, yönetim performansı, dokümantasyon ve testlerle ilgili ölçümleri içeriyor. Testlerin ve dokümanların hangi oranda başarılı olduğu kaliteyi ölçen faktörler olarak verildi. Kalite güvencesi analiz ve iyileştirme başlıklarında ele alındı: kalite verisinden ders çıkarma, işleri daha iyi ve daha az maliyetle yapmanın yollarını arama. Kalite kontrolü ise projenin ömrü boyunca izleme ve kontrol etme aksiyonlarını kapsıyor.

> **Ders sonrası not:** Bu sunumdaki süreler kendi içinde tutarsız. Toplam 55 gün denirken alt işler 30, 26, 29 ve 55 gün olarak sayılıyor, bunların toplamı 140 gündür. Aylarla verilen takvim ise literatür taraması (Mayıs-Ekim, 6 ay), veri toplama (Kasım'a kadar, 7 ay), uygulama (Ekim-Ocak, 4 ay) ve rapor (Aralık-Şubat, 3 ay) diye gidiyor. Bu takvim Mayıs'tan Şubat'a 10 ay eder. Tabloda ise proje yöneticisi projenin tamamında aktif olduğu halde 15 adam-ay yazıyor. Doğru değerler sunumdan anlaşılmıyor.

<!-- BELİRSİZ: 01:30:01'de çevik başlıkları arasında "War" diye bir kelime geçiyor, karşılığı anlaşılmıyor. 01:31:12'de WBS'in "3 parçaya" ayrıldığı söyleniyor, kodlama ve arayüz tasarımının tek parça olup olmadığı slayttan doğrulanamadı. -->

### 9.3 Hocanın Geri Bildirimi

Grup, seçtiği çevik modelin yaklaşımlarını tek tek anlatırken hoca şunu söyledi: bunlar çevik yöntemlerin genel özellikleridir, saymaya gerek yok. Buradaki öğüt, sunumda genel bilgiyi tekrar etmek yerine projeye özgü olana yer vermektir.

## 10. Makale Sunumu: Proje Yönetiminde Duygusal Zeka

### 10.1 Konu ve Amaç

Bir grup, daha önce yapamadığı makale sunumunu bu derste yaptı. Makale "Project Managers' Emotional Intelligence: Ticket to Success" başlıklıdır. 2012'de IPMA Dünya Kongresi'nde sunulmuş, 5 yazarlı bir çalışmadır. Temel fikir şudur: iyi takım çalışması birbirini anlamaktan ve grubun duygularını avantaja çevirmekten geçer. Bir yazılım projesinin başarısı iyi takım çalışması gerektirir. Bu yüzden proje yöneticisinden takım içi iletişimi en verimli düzeye taşıması beklenir. Bunun için de yüksek duygusal zeka önemlidir.

### 10.2 Tanım ve Tarihçe

Duygusal zeka, basitçe kendinizin ve diğerlerinin duygularını izleyebilmek ve buna göre hareket etmektir. Kısaca duyguların farkında olmak ve onları yönetmek diye de söylenebilir. Sunuma göre en iyi özelliği, deneyimle öğrenilebilir olmasıdır.

Tarihçe şöyle anlatıldı:

- 1964: Michael Beldoch kavramı ilk kez kaleme aldı.
- 1989: Stanley Greenspan bir model geliştirdi.
- Sonra Peter Salovey ve John Mayer modeli geliştirdi.
- 1995: Daniel Goleman, "Duygusal Zeka Neden IQ'dan Daha Önemlidir" kitabıyla kavramı dünyada yaygınlaştırdı, iş dünyası için de ele aldı.

Goleman'dan şu söz aktarıldı: CEO'lar zekalarına ve iş konusundaki uzmanlıklarına bakılarak işe alınıyor, duygusal zeka yoksunluğu nedeniyle işten atılıyor.

> **Ders sonrası not:** Altyazıda "Bill Goldman" ve "Daniel Goldman" diye geçen ad Daniel Goleman, "Peter Salloway" Peter Salovey, "Michael Beldoke" Michael Beldoch olmalıdır. Sunumda EQ, "emotional question" diye açıldı. Bu büyük olasılıkla "emotional quotient" olmalıdır.

### 10.3 Duygusal Zekanın Dört Alanı

- **Öz farkındalık:** Duyguları dinlemek kendini anlamanın ilk adımıdır. Bu kişiler güçlü yanlarını iyi kullanır, daha önemlisi zayıf yanlarını da değerlendirir. Takım arkadaşlarından öğrenmeye açıktır. Olaylara farklı açılardan bakıp objektif değerlendirir, sorunlarda ara bulup çözüm geliştirir.
- **Öz yönetim:** Dört beceriden oluşur.
  - Öz kontrol: doğru duyguyu doğru zamanda gösterebilmek.
  - Uyum yeteneği: proje başarısı için pürüzsüz bir ortam sağlar.
  - Başarı yönelimi: en iyi sonuç için çabalamak.
  - Pozitif bakış açısı: pürüzsüz projeler yaratmayı sağlar.
- **Sosyal farkındalık:** Empati ve grup farkındalığından geçer. Empati başkalarının duygularını anlamayı ve bağ kurmayı sağlar, ama çaba ister. Grup farkındalığı, takımın hislerini analiz edebilmektir. Arkadaşların duygularını anlamak sosyal gerilimi azaltır ve açık iletişim sağlar.
- **İlişki yönetimi:** Liderlik (doğru grupları oluşturup pürüzsüz yönetebilmek), koçluk ve mentorluk (yapıcı ilişkiler kurmak), çatışma yönetimi ve ekip çalışması. Son ikisi el ele gider.

### 10.4 Proje Yönetimindeki Önemi

Proje yönetimi için yaygın iki söz aktarıldı: proje yönetiminin yarısı bilim, yarısı sanattır ve proje yöneticisi zamanının %80'ini iletişimle geçirir. Sunuma göre araştırmalar, hedeflere ulaşma, sağlıklı ilişkiler, emeğin karşılığını alma ve yaşamdan tatmin gibi başarı faktörleri ile duygusal zeka düzeyi arasında güçlü bir ilişki gösteriyor. Goleman'ın araştırma sonuçlarına göre fark yaratan liderlerin yetkinliklerinin %85'i duygusal zekayla ilgilidir.

Proje yöneticilerinin başlıca sorunları şöyle sıralandı: geri bildirim verme ve almayı da içeren iletişim sorunları, kültürel faktörler ve ortak değerleri oluşturamama, farklı kişiliklere saygı gösterememe ve ekip olamama.

### 10.5 Nasıl Geliştirilir?

Sunumdaki öneriler şunlardır:

- Duyguları fark etmek, adlandırmak ve doğru şekilde ifade etmek.
- İyi bir gözlemci olmak, hem kendini hem çevreyi gözlemlemek.
- Kendini ifade etmedeki eksikleri bulup gidermek, kitap okumak, atölyelere katılıp profesyonel destek almak.
- Sosyal girişkenliği ve öz güveni artırmak.
- Takım çalışmalarına ve sosyal sorumluluk projelerine katılmak.
- Olumsuz koşullardan ders çıkarmak, başkalarını da düşünerek hareket etmek.
- Proje yönetimi becerilerini geliştirmek ve teknik tarafın tek başına yeterli olmayacağını bilmek.

### 10.6 Sonuç

İnsan farklı amaçlarla iletişim kuran sosyal bir varlıktır. Kendini tanıtabildiği ve başkalarını anlayabildiği ölçüde toplumda yer edinir. Proje takımları da karşılaştıkları sorunlarda bilgi kadar sosyal ve duygusal becerilere ihtiyaç duyar. İletişim en önemli sosyal beceridir, duygusal zeka da onu destekleyen yeterlilikleri açıklar.

### 10.7 Hocanın Geri Bildirimi

Hocanın soruları, sunumun içeriğinden çok makalenin bilimsel niteliğine yöneldi.

**Soru:** Makalede kullanıcılar arasında bir anket çalışması var mı, yoksa bir durum değerlendirmesi mi? **Cevap:** Durum değerlendirmesi.

**Soru:** Bu 2012'de. Başka kaynaklara, daha yakın tarihli çalışmalara baktın mı? **Cevap:** Grup, Anthony Mersino'nun hazırladığı, bir eğitim firmasına ait bir eğitim dokümanından da yararlandığını söyledi.

**Soru:** Bunun tarihi var mı? **Cevap:** 2013 olması gerektiği söylendi.

Bu sorulardan çıkan öğüt açıktır: bir makale anlatılırken çalışmanın ampirik bir veriye mi dayandığı, yoksa bir değerlendirme mi olduğu belirtilmeli, konunun daha güncel kaynakları da araştırılmalıdır.

## 11. 9. Sunum: Havalimanı Hizmetleri ve Gelirleri Sistemi

### 11.1 Konu ve Amaç

Grup, bir havalimanı işletmecisinin havayolu şirketlerine verdiği tüm hizmetleri, her yıl yayımlanan ücret tarifelerine göre hesaplayıp faturalayan bir web uygulamasını anlattı. Benzer sistemler yurt dışında Airport Operation Database adıyla geçiyor. Bu sistemlerin alt birimleri olarak kule, terminal operasyonları, yer operasyonları, faturalama, uçuşların sezonlara göre hazırlanması ve gerçek zamanlı operasyonlar gösterildi. Proje, 2005-2006 yıllarında yazılmış bir masaüstü uygulamasını web ortamına taşıyor.

Farklı birimlerin işlemleri için modüller var:

- **Terminal operasyonları:** iç ve dış hat terminallerinde verilen hizmetler.
- **Yer hizmetleri:** uçaklara kalkış öncesi ve iniş sonrası verilen hizmetler.
- **Hava trafik:** uçağın bir havalimanından kalkışından diğerine inişine kadar verilen seyir hizmetleri.

### 11.2 Yöntem ve Plan

Şelale modeli kullanıldı. Gerekçe alanın kendisinden geliyor. Fatura kesebilmek için önce uçuş başlamalı, uçuş verileri girilmeli, sonra verilen hizmetler girilmelidir. Bu işlemler birbirine bağlıdır ve hepsi tamamlanmadan faturalandırma yapılamaz. Teknolojiler ASP.NET, C#, HTML5, CSS3, JavaScript ve Oracle'dır.

Use case akışı şöyledir:

- Kullanıcı girişi.
- Uçuş bilgileri: hava trafik kontrolörlerinden gelen bilgiler, kalkış ve varış havalimanı, kalkış ve slot saati.
- Uçuş ayrıntıları: uçağın tescili, sahibi olan firma, rota, firmanın izinli olup olmaması, iç ya da dış hat olması. Ücretlendirme havada geçen süreye de bağlı olduğu için rota önemlidir.
- Apron hizmetleri: örneğin pilota yol gösteren "follow me" aracı ve yakıt alımında itfaiye araçlarıyla verilen emniyet hizmeti.
- Yer hizmetleri: örneğin ikram ve uçağın 400 Hz elektrik ihtiyacı.
- Faturalama.

Riskler etki ve olasılıkla değerlendirildi:

- Takvimde gecikme ile yazılım ve donanım ortamının hazırlanması: yüksek.
- Ekipte personel değişikliği: etki orta, olasılık düşük.
- Personelin eğitim eksikliği: etki yüksek, olasılık düşük, çünkü sürekli eğitim veriliyor.
- Uygulamanın kullanılabilirliğinde sorun: etki yüksek.
- Kullanıcı geri bildirimlerinin anlaşılmaması: etki yüksek, olasılık düşük.

Zaman çizelgesi MS Project 2016 ile hazırlandı. Planlama, ön inceleme, veri toplama ve analiz, ardından demo ve ayrıntılı tasarım geliyor. Projeye özgü adımlar eski uygulamayla karşılaştırma ve eski uygulama verisinin entegrasyonudur. Kalite planı üç uygunluk başlığıyla verildi: SRS'teki kapsama uygunluk, zaman çizelgesine uygunluk ve seçilen geliştirme modelinin doğru uygulanması.

> **Ders sonrası not:** Altyazıda "11G ile 12G'ye geçtik" deniyor. Oracle sürümleri büyük olasılıkla 11g ve 12c'dir. Eski uygulamanın dili de "100'lü basic" diye geçiyor, bu büyük olasılıkla Visual Basic'tir.

<!-- BELİRSİZ: 01:50:48'de uçuş ayrıntıları ekranının adı "FIC" diye geçiyor, açılımı anlaşılmıyor. -->

### 11.3 Sonuç ve Hocanın Geri Bildirimi

Web uygulaması geliştirilmiş ve arayüz ekranları bir kolaj olarak gösterildi. Hoca sorusu olmadığını, grubun genel olarak anlattığını söyledi ve SRS belgesinin üzerinden de geçilmesini istedi.

## 12. Geri Bildirimlerden Çıkan Akademik Öğütler

Hoca bunları tek bir değerlendirme olarak sunmadı. Aşağıdaki liste, sunum sonlarındaki sorulardan ve araya girişlerden derlendi.

- **Plan yapmak yetmez, takip gerekir.** Planlanan ile gerçekleşen karşılaştırılmalı. Bunun için kazanılan değer analizi gibi bir araç kullanılır, ölçüm kilometre taşlarında bütçe, zaman ve kapsam açısından yapılır.
- **Risk tablosu bir sıralama üretmeli.** Etki ile olasılık çarpılır, çıkan dereceye göre bir eşik konur. Küçük bir projede bütün riskler takip edilemez. Altta kalanlar takip dışı bırakılabilir.
- **Bütçede iş gücü unutulmamalı.** Tek kişilik projede de kişi iş gücü sayılmalıdır.
- **Plan farklı görünümlerle incelenebilir.** Gantt şemasının yanında projenin PERT görünümü de MS Project'ten alınabilir.
- **Genel bilgiyi saymak yerine projeye özgü olan anlatılmalı.** Seçilen modelin genel özellikleri yerine, projede nasıl uygulandığı önemlidir.
- **Makale okurken yöntem sorgulanmalı.** Çalışmanın anket gibi bir veriye mi dayandığına, durum değerlendirmesi mi olduğuna ve daha güncel kaynaklar olup olmadığına bakılmalıdır.

## Dersin Toparlaması

Bu derste dönem boyunca işlenen proje yönetimi konuları dokuz farklı projede görüldü. Basit bir masaüstü uygulamasından havacılık sertifikasyonuna uzanan bu örnekler, model seçiminin projenin yapısına bağlı olduğunu gösteriyor. Gereksinimleri belli ve adımları birbirine bağlı işlerde şelale, dış ekiplere bağımlı ve yeni taleplerin sürekli geldiği işlerde Kanban, sertifikasyon gereken alanda ise o alanın süreci öne çıktı. 2. sunum bir müşteri talebinin kapsam, zaman, kaynak ve maliyeti birlikte değiştirdiğini, 3. sunum ise gecikmenin en çok çalışma kalemine yansıdığını örnekledi. Makale sunumu da proje başarısının teknik yanın yanında iletişim ve duygusal zekaya bağlı olduğunu hatırlattı.

Hocanın sorularının ortak noktası takiptir: planlanan ile gerçekleşenin kilometre taşlarında karşılaştırılması ve risklerin etki ile olasılığa göre ayıklanması. Hoca ayrıca derste anlaşılamayan yerlerin, daha anlaşılır örnekler içerdiğini söylediği tavsiye kitabından tamamlanabileceğini belirtti.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
