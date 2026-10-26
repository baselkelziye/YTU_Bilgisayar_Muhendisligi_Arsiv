# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 14 Mart 2023 Salı. Ders Zoom üzerinden yapıldı.
  - İlk 11 dakika proje gruplarının duyurusudur. Konu anlatımı yaklaşık 00:12'de başlar.
  - Yaklaşık 01:16'dan sonra asistan Elçin Hoca zaman fizibilitesini MS Project ile uygulamalı anlatır.
- Proje grupları ve konular
  - Gruplar A'dan P'ye kadar harflendi. Konular: pet shop, fitness center, otel, bankacılık, market, sinema bileti, kütüphane, maç bileti, araç kiralama, ulaşım firması, restoran, scooter kiralama vb.
  - Her grubun en az 5 modülü olmalı. Modül bilgisi eksik gruplar aynı gün e-posta atmalı.
  - Açıkta kalan 16 öğrenci boş yerlere ve yeni gruplara (O ve P) atanacak.
- Bilgi sistemi geliştirme sürecinin ilk aşaması: ön inceleme
  - Temel soru: Bu sisteme gerçekten ihtiyaç var mı?
  - Diğer sorular: Neye ihtiyacımız var? Ne kadar zamanımız var? Tahmini bütçe ne? Fayda maliyeti karşılıyor mu?
  - Sonuç tek bir karardır: tamam mı, devam mı?
  - Çıktı: kapsam tanımlama belgesi (Project Charter).
- İkinci aşama: fizibilite çalışması
  - Amaç: Proje yapılabilir mi, yapılması için gerçekten neye ihtiyaç var?
  - Çıktı: fizibilite raporu.
  - Fizibilite tipleri: teknik, zaman, sosyal (operasyonel), yönetim, yasal ve ekonomik.
- Ekonomik fizibilite yöntemleri
  - Bugünkü değer yöntemi, iç verim oranı, başa baş noktası, geri ödeme süresi.
- Fizibilite matrisi
  - Alternatif sistemler, ağırlıklı puanlama ile karşılaştırılır.
- Zaman fizibilitesi uygulaması (asistan)
  - Gantt şeması, faaliyetler arası ilişkiler (FS, SS, FF, SF), kritik yol, bolluk (slack), kilometre taşı (milestone), kaynak atama, PERT diyagramı.
  - MS Project ile örnek bir bitirme projesi planı kuruldu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fizibilitede sadece geliştirme aşamasını düşünmeyin.
  - Sistemin yaşam ömrü boyunca işletme ihtiyaçlarını da hesaba katın. "İki laptop yeter" yaklaşımı yanlıştır.
  - Kısa ve orta vadede kullanıcı ve veri artışının projeksiyonunu yapın.
- Yasal fizibilitede en sık yapılan hata: "Sistem yasalara tamamen uygundur" cümlesini yazmak.
  - Bu, yasal fizibilite değildir.
  - Doğrusu: Uyulması gereken kanunları, yönetmelikleri, lisansları, patentleri ve bunların maliyetlerini alternatifleriyle ortaya koymak. Örnek: KVKK yükümlülükleri.
- Sosyal fizibilitede ikinci sık hata: "Sistem kullanıcılara gösterildi, beğenildi" yazmak.
  - Sosyal fizibilite proje başında yapılır. Anket ve görüşmelerle kullanıcının neyi kabul edip etmeyeceği ortaya konur.
- Teknik risklere ve ekibin teknik yetersizliklerine dikkat edin.
  - Örnek: Ekip .NET Core bilmiyorsa eğitim süresi ve maliyeti fizibiliteye eklenmelidir.
- Fizibilite matrisinde en az 2, tercihen 3 veya daha fazla alternatif sistem önerin.
  - Genellikle tek bir sütun (bir alternatif) seçilir. Alternatifleri parça parça birleştirmek pek tercih edilmez.
- Dersi tekrar dinleyin. Fizibilite tiplerini kaynaklardan ve internetten örnekleriyle inceleyin. Projelerinizde uygulayacaksınız.

## Kısa Tekrar Notları

- Ön inceleme = "Bu sisteme ihtiyaç var mı, yapabilir miyiz?" sorusunun kaba cevabı. Çıktısı Project Charter.
- Project Charter içeriği: kapsam (ürün ne), kalite tanımları, zaman (fazlar), maliyet (kırılımlarıyla), kaynaklar.
- Fizibilite = ayrıntılı yapılabilirlik analizi. Çıktısı fizibilite raporu.
- Teknik fizibilitenin 3 alt başlığı: yazılım, donanım, iletişim (ağ).
- Ekonomik fizibilitede her şey para birimine çevrilir.
- Bugünkü değer çarpanı: $PVIF = \dfrac{1}{(1+i)^n}$ ($i$: iskonto oranı, $n$: yıl).
- İç verim oranı: Net bugünkü değeri sıfırlayan iskonto oranı.
- Başa baş noktası: Toplam gelir ile toplam giderin eşitlendiği nokta.
- Geri ödeme süresi = Yatırım tutarı / Yıllık net nakit girişi.
- Gantt'ta faaliyet ilişkileri:
  - FS (bitiş-başlangıç): A bitince B başlar. MS Project'te varsayılan.
  - SS (başlangıç-başlangıç): A başlayınca B de başlar.
  - FF (bitiş-bitiş): A bitince B de biter.
  - SF (başlangıç-bitiş): B'nin bitmesi için A'nın başlaması gerekir.
- Kritik yol: Gecikmesi toplam proje süresini uzatan faaliyetlerin yolu. MS Project'te kırmızı görünür.
- Bolluk (slack): Kritik yolda olmayan bir faaliyetin projeyi geciktirmeden kayabileceği süre.
- Kilometre taşı: Süresi 0 gün olan önemli nokta (toplantı, teslim). Gantt'ta elmas ile gösterilir.

## Detaylı Açıklamalar

Ders, bilgi sistemi geliştirme sürecinin ilk iki aşamasını anlatır: ön inceleme ve fizibilite. Hoca bu aşamaları şelale (waterfall) modeli üzerinden ele alır. Dersin son yarım saatinde asistan, zaman fizibilitesinin nasıl yapıldığını MS Project üzerinde gösterir.

### Proje grupları ve beklentiler

- Gruplar e-postaların geliş sırasına göre harflendirildi.
- Hoca, bazı konuları çakışma olmasın diye değiştirdi. Örnek: M grubunun araç kiralama konusu scooter kiralamaya dönüştürüldü.
- Modüller sistemin ana fonksiyonlarıdır. Ders kapsamında en az bu modüller için analiz ve tasarım çıktıları (diyagramlar ve rapor) beklenir.
  - Mobil/web ön yüz, veri erişim katmanı gibi ayrıntılar gruplara kalmıştır.
- Proje beklentileri ve rapor içeriği için bir doküman Online YıldızEdu ders duvarında paylaşılacak.

### Ön inceleme

- Ön inceleme ayrı bir safha olabilir ya da fizibilitenin ilk adımı sayılabilir. Büyük projelerde ayrı tutulabilir.
- Sorulan sorular:
  - Bu sisteme gerçekten ihtiyaç var mı? Mevcut sistemi iyileştirmek yetmez mi?
  - Sistemi geliştirmek için neye ihtiyacımız var? (insan kaynağı, sunucu, ağ, veri depolama vb., kabaca)
  - Ne kadar zamanımız var? Esnek takvim mi, kesin teslim tarihi (hard deadline) mi?
  - Tahmini bütçe ne? Kabaca "10 kişi, 3 ay" gibi bir tahmin yeterlidir.
  - Fayda maliyeti karşılıyor mu? ("Attığımız taş ürküttüğümüz kuşa değecek mi?")
- Çıktı: Kapsam tanımlama belgesi, yani Project Charter. Bu belge bir "niyet beyanıdır".
  - İçeriği: ürünün ne olduğu, kalite kriterleri, zaman planı (fazlar), maliyet kırılımları, kullanılacak kaynaklar.
- Ardından üst yönetim proje yöneticisiyle bir değerlendirme toplantısı yapar. Karar: proje bırakılır, revize edilir ya da devam edilir.

### Fizibilite çalışması

- Amaç: Projenin yapılabilir olup olmadığını ve neye ihtiyaç duyduğunu daha kesin ortaya koymak.
- Hoca güneş/rüzgâr santrali örneğini verir: yatırım, teşvik, arazi, işletme masrafı, satış imkânı hesaplanır.
- Bilgi sistemi sadece para kazandırmak zorunda değildir. Verimliliği artırdığı ya da kaynak ihtiyacını azalttığı için de tercih edilebilir.
  - Örnek: 100 kişi çalıştırmak yerine "sistem + 5 kişi" daha ucuza gelebilir.

#### Teknik fizibilite

- Hem geliştirme aşaması hem de sistemin devrede kaldığı yaşam ömrü incelenir.
- Üç alt başlık:
  - **Yazılım fizibilitesi:** İşletim sistemi (Windows, Linux, mainframe'de z/OS gibi zorunlu durumlar), geliştirme ortamı, veritabanı yönetim sistemi, uygulama sunucuları, destek yazılımları. Lisans ve bakım bedelleri karşılaştırılır.
  - **Donanım fizibilitesi:** Ekip cihazları, uç birimler, barkod okuyucu, yazıcı, erişim noktası, gömülü sistemler vb. Kısa ve orta vadeli kapasite projeksiyonu yapılır.
  - **İletişim (ağ) fizibilitesi:** Geliştirme ve işletme için ağ ihtiyacı. Kullanıcı ve işlem sayısı arttıkça gereken kapasite artışı.
- Riskler mutlaka değerlendirilir:
  - Seçilen teknolojinin desteği birkaç yıl içinde bitebilir.
  - Donanım mimarisi değişebilir.
  - Ekibin bilmediği bir teknoloji eğitim süresi ve maliyeti getirir.
- Örnek: Sunucu satın almak mı, bulutta kiralamak mı? Alternatifler karşılaştırılır.

#### Zaman fizibilitesi

- Proje planı oluşturulur: ana adımlar, alt faaliyetler, sıraları, başlangıç-bitiş ilişkileri.
- Her faaliyete insan ve teknik kaynak atanır.
- Proje yöneticisi ve yönetim, gidişatı bu plan üzerinden takip eder.

#### Sosyal (operasyonel) fizibilite

- Sistemin hedef kitlesi sistemi kabul edecek mi?
- Kullanıcının alışkanlıklarına uygun giriş yöntemi seçilmeli: klavye, tıklama, barkod, QR, RFID, sesli komut.
- Örnekler:
  - 3-6 yaş için eğitici oyun: Çocuktan klavye kullanması beklenmez. Dokunma ya da sesli komut düşünülebilir.
  - Muhasebe birimi: Excel'e ya da eski sisteme benzeyen arayüzler tercih edilebilir.

#### Yönetim fizibilitesi

- Sistem yönetimin iş yapış ve karar verme süreçlerini nasıl etkiliyor?
- Yönetim ne kadar fayda sağlayacak?
- Yeni raporlar veya uyarılar istenebilir. Örnek: Siparişler 3 hafta boyunca belli bir oranda düşerse alarm üretilmesi.

#### Yasal fizibilite

- Hizmet verilen alandaki regülasyonlar incelenir. Örnek: Finans piyasalarında yönlendirme yapan bir sistem için otoritelerden izin veya denetim gerekebilir.
- Patent ve fikri sınai haklar: Kullanılan bir algoritmanın patenti varsa lisans bedeli ve sözleşme gerekir.
- Kurumun yaptığı anlaşmalara uyum kontrol edilir.
- Açık kaynak alternatifleri ve bunların zaman/maliyet etkisi değerlendirilir.
- KVKK örneği: Kişisel veri tutan sistemlerde silme talepleri, güvenlik testleri, raporlamalar gibi ek geliştirmeler ve maliyetler doğar.

#### Ekonomik fizibilite

- Diğer bütün fizibilitelerden gelen maliyetler para cinsine çevrilir.
- Maliyetler ile kazanç veya verimlilik artışı bir terazinin iki kefesine konur.
- Fayda maliyeti karşılamıyorsa proje revize edilir: zaman planı, kaynak planı veya yasal çözüm değiştirilir.
- Dört temel yöntem:
  - **Bugünkü değer yöntemi:** Projenin tüm nakit giriş ve çıkışları bugünkü değere indirilip karşılaştırılır. Net nakit girişleri yatırım harcamalarından büyükse proje kabul edilir.
    - İskonto oranı için pratik bir yol: piyasadaki ağırlıklı sektörlerin faiz oranlarının ortalaması.
    - Enflasyon yüksekse iskonto oranı da yüksek alınır.
  - **İç verim oranı (karlılık oranı):** Nakit girişleri ile yatırım maliyetini eşitleyen, yani net bugünkü değeri sıfırlayan iskonto oranıdır. Yüksek olması istenir.
  - **Başa baş noktası:** İşletme aşamasında toplam gelir ile toplam giderin kesiştiği nokta. Yatırımcılar bu noktanın mümkün olduğunca erken (grafikte sola) gelmesini ister.
  - **Geri ödeme süresi:** Yatırım tutarı / yıllık net nakit girişi. Başlangıçtaki yatırımın kaç yılda geri döneceğini gösterir.

### Fizibilite matrisi

- Her alternatif sistem bir sütun, her fizibilite tipi bir satırdır.
- Her satıra bir ağırlık (%) verilir. Ağırlıkların toplamı %100 olmalıdır.
- Her hücreye bir puan verilir. Ağırlıklı toplam en yüksek olan alternatif seçilir.
- Slayttaki örnek (slayt 38, kareden):

| Fizibilite | Ağırlık | Sistem 1 | Sistem 2 | Sistem 3 |
| :--- | :---: | :---: | :---: | :---: |
| Teknik | %30 | 50 | 95 | 60 |
| Ekonomik | %30 | 60 | 85 | 90 |
| Zaman | %10 | 95 | 80 | 85 |
| Operasyonel | %30 | 60 | 100 | 100 |
| **Toplam** | %100 | **60,5** | **92** | **83,5** |

- Hesap: Sistem 2 için $0{,}3\cdot95 + 0{,}3\cdot85 + 0{,}1\cdot80 + 0{,}3\cdot100 = 92$.

### Zaman fizibilitesi uygulaması (asistan)

- Gantt şeması 1910'larda Henry Gantt tarafından önerildi. Projenin her işi bir faaliyettir.
- İşler ana başlıklar ve alt kırılımlar (iş paketleri) hâlinde yazılır. MS Project bunları WBS (Work Breakdown Structure, Türkçesi ÇÇY: çalışma çözümleme yapısı) sütununda otomatik numaralandırır.
- Öncül (predecessor) sütununa faaliyetin ID'si yazılır.
  - Sadece "2" yazmak FS ilişkisi demektir (varsayılan).
  - Başka ilişkiler için "8SS" gibi yazılır.
  - Birden fazla öncül noktalı virgülle ayrılır.
  - Gecikme eklemek için "5+1 gün" gibi yazılır.
- Kilometre taşı 0 gün olarak girilir. Örnek: literatür taraması sonrası danışman toplantısı, ara rapor teslimi.
- Örnek plan: bir bitirme projesi
  - Literatür taraması (IEEE, Elsevier, SpringerLink, Google Scholar): Ali ve Veli paralel çalışır.
  - Danışman toplantısı: kilometre taşı, son işten 1 gün sonra.
  - Veri seti oluşturma: görüntü toplama (5 gün) ve etiketleme (8 gün), SS ilişkisiyle aynı anda başlar.
  - Ara rapor yazımı: etiketleme bittikten 1 gün sonra başlar. Rapor teslimi kilometre taşıdır.
  - Uygulama: 20 gün.
- Format menüsünden "kritik görevler" seçilince kritik yol kırmızı görünür. Kritik olmayan işlerdeki bolluk gri çizgiyle gösterilir.
- Çalışma zamanını değiştirme (Change Working Time): Cumartesi ve pazar çalışma günü yapılınca 41 günlük proje Mayıs yerine Nisan'da biter.
- Resource Sheet: Kaynaklara saatlik ücret girilir. Her faaliyetin maliyeti otomatik hesaplanır.
- Network Diagram menüsü PERT diyagramını gösterir. Her faaliyet bir düğümdür. Kritik olanlar kırmızıdır.
- MS Project yerine açık kaynak araçlar da kullanılabilir. Hoca, üniversitenin yazılım dağıtım sisteminde (altyazıda "Distro") eski MS Project sürümlerinin öğrencilere açık olduğunu söyledi.
- Asistan ders dosyalarını ve örnek projeyi kendi Avesis sayfasında paylaşacak.

### Ders sonrası notlar

- **Bugünkü değer tablosu (slayt 13):** Tablonun satırları yıl ($n$), sütunları iskonto oranıdır ($i$ = %1-%9). Python ile kontrol edildi; slaytta iki hatalı değer var:
  - %9 ve 1 yıl: Slaytta 0,870 yazıyor. Doğrusu $1/1{,}09 \approx 0{,}917$.
  - %8 ve 4 yıl: Slaytta 0,835 yazıyor. Doğrusu $1/1{,}08^4 \approx 0{,}735$.
- **Tablonun okunuşu:** Hoca tabloyu anlatırken satır ile sütunu karıştırdı ("oran yüzde onsa 99 kuruş", "9 yıl sonra 87 kuruş").
  - %1 iskontoda 1 yıl sonraki 1 TL bugün 0,990 TL eder.
  - %1 iskontoda 9 yıl sonraki 1 TL bugün $1/1{,}01^9 \approx 0{,}914$ TL eder.
  - %5 iskontoda 9 yıl sonraki 1 TL bugün $1/1{,}05^9 \approx 0{,}645$ TL eder. Hocanın "65 kuruş" sonucu bu satıra denk geliyor.
- **Bugünkü değer formülü:** Slayttaki $V = Q_0 \frac{Q_n}{(1+i)^n}$ yazımı eksik. Doğru net bugünkü değer formülü: $NBD = \sum_{n=0}^{N} \frac{Q_n}{(1+i)^n}$. Burada $Q_0$ genellikle negatif olan ilk yatırımdır.
- **Fizibilite matrisi:** Hoca sonuçları "60, 92, 83" ve "92 ve 84" diye okudu. Slayttaki doğru değerler 60,5; 92 ve 83,5. Ağırlıkların toplamı zaten %100; hocanın "normalizasyon yapmamışız" sözü ağırlıklar için geçerli değil.
- **SF ilişkisi:** Altyazıdaki anlatım karışık. Doğrusu: Başlangıç-bitiş (SF) ilişkisinde ardıl faaliyet, öncül faaliyet başlamadan bitemez. Örnek: Yeni sistem devreye girmeden eski sistemin desteği sonlanamaz.
- **Varsayılan çalışma saatleri:** Altyazıda "13-15" diye geçiyor. MS Project'in varsayılanı 08:00-12:00 ve 13:00-17:00'dir.
- Dersin sonunda hoca asistana "Ercan Hoca" diye teşekkür ediyor gibi görünüyor; altyazı hatası, kastedilen Elçin Hoca.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
