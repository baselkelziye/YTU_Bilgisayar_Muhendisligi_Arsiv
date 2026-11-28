# Ders 9 Çalışma Özeti

## Genel Konular

- Nesneye yönelik tasarım sürecine giriş (ekrandan, 00:15:00)
  - Analiz "ne?" sorusuna, tasarım "nasıl?" sorusuna yanıt arar.
  - Nesne modeli analizden tasarıma taşınır: doğrudan problem alanıyla ilgili nesnelerden oluşan model, yardımcı nesnelerle zenginleştirilir.
  - Ana işlem grupları: nesne tasarımı (problem alanıyla ilgili nesneler) ve sistem tasarımı (alt yapıyı ve gereçleri oluşturan nesneler).
  - Sistem katmanında bulunabilecek bileşenler: yazılım mimarisi (istemci-sunucu, eşler arası, olay tabanlı vb.), kullanıcı arayüzü, veri yönetimi, ağ programlama.
  - Sistem katmanı çoğunlukla sıfırdan oluşturulmaz; hazır altyapı programları (framework) kullanılır.
- Tasarımın belgelendirilmesi (ekrandan, 00:20:00)
  - Ayrıntılı UML sınıf şemaları vazgeçilmezdir.
  - Tasarımın ihtiyacına göre şu belgelerin bileşimleri de kullanılır: sözleşmeler, UML etkileşim şemaları (sıralama/sequence ve işbirliği/collaboration), UML etkinlik şemaları (activity) ve UML durum diyagramları (state).
  - Sıralama şemaları nesnelerin işleme giriş sırasını, işbirliği şemaları nesnelerin birbiriyle nasıl ilişkili çalıştığını gösterir; etkinlik şemaları eş zamanlı etkinlikleri daha iyi gösterir.
- Tasarım kalıpları (design patterns)
  - Sıklıkla karşılaşılan, tanımlanabilir bir probleme sistematik çözüm getiren prensiplerdir ("aklın yolu birdir"). Kalıplara, getirdiği çözümü belirten, kolay hatırlanan ve iletişimi kolaylaştıran adlar verilir.
  - Gamma, Helm, Johnson ve Vlissides'in ortaya koyduğu 23 kalıp "Gang of Four" (GoF) kalıpları olarak bilinir. Derste, nesnelere sorumluluk atarken temel alınan genel sorumluluk atama prensipleri Larman'ın kitabı üzerinden işlendi.
  - Nesne tasarımında sınıfları ve sorumlulukları belirlemeden önce tasarım kalıpları incelenmelidir.
- İşlenen dokuz kalıp (kahve sitesi örneğiyle)
  - Yaratıcı (Creator): B sınıfı A nesnelerini içeriyorsa (kümeleme dahil), kaydını tutuyorsa, sıkı biçimde kullanıyorsa ya da A'nın yaratılması için gerekli verilere sahipse A'yı B yaratır. Sipariş birçok Sipariş Kalemi içerdiği için kalemleri Sipariş yaratır (ekrandan, 00:25:00).
  - Bilginin Uzmanı (Expert): sorumluluk, onu yerine getirecek veriye sahip sınıfa verilir. Siparişin toplam bedelini Sipariş bilir; Sipariş Kalemi kendi bedeli için Kahve nesneleriyle işbirliği yapar (ekrandan, 00:30:00).
  - Az Bağımlılık (Low Coupling): bir sınıf diğer sınıflardaki değişimlerden az etkilenmeli. Gerçekte Ödeme Müşteriyle ilişkilidir, ama Ödeme sorumluluğu Siparişe verilirse bağımlılık azalır (ekrandan, 00:35:00).
  - Denetçi (Controller): kullanıcı arayüzünün arkasında durup sistem olaylarını alan ve ilgili nesnelere yönlendiren sınıf; her kullanım senaryosu için bir denetçi atanabilir. Window, applet, frame gibi yapılar denetçi değildir.
  - İyi Uyum (High Cohesion): bir sınıfın sorumlulukları birbiriyle ilgili ve tek konuya yoğun olmalıdır (ekrandan, 00:40:00).
  - Çok Şekillilik (Polymorphism): tiplere göre değişen davranışlar çok şekilli metotlarla tasarlanır. Örnek: farklı kredi kartı onay programları ortak bir arayüzün arkasında.
  - Yapay Sınıf (Pure Fabrication): uyum ve bağımlılık sorunlarını çözmek için gerçek dünyada olmayan sınıflar; gereğinden fazla kullanılmamalıdır (ekrandan, 00:45:00).
  - Dolaylılık (Indirection): sorumluluk bir ara birim nesnesine verilerek bileşenler arasına dolaylılık konur.
  - Değişimlerden Korunma (Protected Variation): kararsız noktaların etrafında sorumluluklar arayüzlere atanır; kredi kartı onay sistemi değişse de sistem etkilenmez (ekrandan, 01:40:00).
- Sınav uygulama sorusunun çözümü: e-kuaförüm.com bilgi sistemi (ekrandan, 01:15:00 - 01:25:00)
  - Use case diyagramı, "Randevu Alma" kullanım senaryosu belgesi ve kavramsal sınıf diyagramı üzerinden geçildi.
- Nesne modelleme tekrarı: kahve sitesi (ekrandan, 01:30:00 ve 01:35:00)
  - Kullanım senaryosu, senaryo belgesi, kavramsal ve tasarım sınıf diyagramı; tasarım sınıf diyagramına Denetçi sınıfı eklendi.
  - Ürün ekleme işleminin ardışıl (sequence) diyagramında Denetçi, Uzman ve Yaratıcı kalıplarının kullanımı (ekrandan, 00:55:00).
- Etkinlik şemaları tekrarı: havalimanı check-in örneği (ekrandan, 01:45:00)
- Yazılım kalitesi ve McCall modeli (ekrandan, 01:50:00 - 02:15:00)
  - McCall'un kalite üçgeni: ürün işletimi, ürün gözden geçirme (revizyon), ürün geçişi.
  - Kalite özellikleri ölçütlerle (kriterlerle) eşleştirilerek sayısallaştırılır.
  - Alternatif modeller: ISO 9126 (iç ve dış kalite özellikleri) ve David Garvin'in kalite boyutları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Analizde "ne?", tasarımda "nasıl?" sorusu
  - Sınıf diyagramı analizde özellikler ve ilişkilerle başlar; işlemler (metotlar) tasarımda tamamlanır.
- Yeniden kullanılabilirlik (reusability)
  - Tasarım kalıplarının, alan modellemenin, alana özgü dillerin ve nesneye yönelik yaklaşımın ortak amacı yeniden kullanılabilirliği artırmaktır. Hoca, kalıpları anlatırken sürekli bu kalite özelliğinden söz ettiğini vurguladı.
- "High cohesion, low coupling"
  - İyi tasarımın kuralı: modül ya da nesnenin içi sıkı ilişkili, modüller/nesneler arası ilişki zayıf olmalıdır.
- Kalıplar birbiriyle çelişebilir
  - Bir kalıba uymak diğerine tam uymamayı getirebilir; kalıplar birlikte değerlendirilerek en uygun çözüm seçilir.
- Projelerde etkinlik diyagramı
  - Kendi uygulamanız için mutlaka etkinlik (activity) diyagramı çizilmelidir; tasarımda sequence, activity ve state diyagramları ile tasarım sınıf diyagramı kullanılması öğütlenir.
- Sınav çözümünde basitlik
  - Çözüm karmaşık değildir; en basit hali çözüm olarak karşımıza çıkar. Çalışan ile İşlem arasındaki çokluk (bir işlemi mutlaka bir çalışan yapar, bir çalışan çok sayıda işlem yapabilir) ve Kuaför/Kalfa/Çırak genelleştirmesi özellikle istendi.
- Kalite özellikleri tanımsaldır
  - Doğruluk, kullanışlılık gibi özellikler doğrudan ölçülemez; ölçütlerle ve ağırlıklarla sayısallaştırılır.
- Tasarım kalıpları kaliteyi iyileştirir ama ölçütlerle doğrudan ilişkili değildir
  - Kalite ölçütlerle ölçülür; kalıplar bu ölçütlerin iyi olmasını sağlamak için kullanılır.

## Kısa Tekrar Notları

- Tasarım: nesne tasarımı + sistem tasarımı; sistem katmanı için framework kullanılır.
- Tasarım belgeleri: ayrıntılı UML sınıf şeması (vazgeçilmez), sözleşmeler, sequence/collaboration, activity, state diyagramları.
- GoF: Gamma, Helm, Johnson, Vlissides; 23 kalıp.
- Dokuz sorumluluk atama kalıbı: Yaratıcı, Bilginin Uzmanı, Az Bağımlılık, Denetçi, İyi Uyum, Çok Şekillilik, Yapay Sınıf, Dolaylılık, Değişimlerden Korunma.
- Yaratıcı: içeren, kaydını tutan, sıkı kullanan ya da gerekli veriye sahip olan sınıf yaratır.
- Uzman: veriye sahip olan sınıf sorumluluğu alır.
- Denetçi: sistem olaylarını alıp yönlendiren sınıf; arayüz pencereleri denetçi değildir.
- Yapay sınıf az kullanılmalı; çok kullanılırsa yazılım gerçek dünyadan uzaklaşır, bağımlılık artar.
- Dolaylılık + çok şekillilik -> değişimlerden korunma.
- Etkinlik şeması sembolleri: denetim akışı, başlangıç, sinyal alma, eylem, karar, eşgüdüm (fork/join), etkinlik sonu, sinyal gönderme.
- McCall: işletim (correctness, reliability, efficiency, integrity, usability), revizyon (maintainability, flexibility, testability), geçiş (portability, reusability, interoperability).
- ISO 9126: iç ve dış kalite özellikleri.
- Kalite özelliği = ölçütlerin ağırlıklı toplamı (örneğin etkinlik = çalışma etkinliği ve bellek etkinliği).

## Detaylı Açıklamalar

- Nesneye yönelik tasarım süreci
  - Analizde problem alanının nesneleri ve aralarındaki ilişkiler belirlenir; tasarımda bu model, sistem katmanının bileşenlerini (mimari, arayüz, veri yönetimi, ağ) temsil eden yardımcı nesnelerle zenginleştirilir. Use case diyagramından başlanarak sınıf diyagramının ilk hali çıkarılır; tasarımda nesneler arası ilişkiler ve her nesnenin işlemleri tamamlanır. Mimari, arayüz, veri yönetimi ve ağ programlama sıfırdan yazılmaz; fizibilitede seçilen altyapı (framework) üzerinde tanımlamalar geliştirilir.
- Tasarım kalıplarının mantığı
  - Bir problem bir kez iyi çözüldüyse aynı çözüm yeniden düşünülmeden kullanılır. Bu, yazılım kalitesinin önemli faktörlerinden yeniden kullanılabilirliği destekler. Kütüphaneler, paket programlar, alan modelleme ve alana özgü diller de aynı amaca hizmet eder.
- Kahve sitesi örneğinde sorumluluk atamaları
  - Sipariş, birçok Sipariş Kalemi içerdiği için kalemleri yaratır (Yaratıcı). Siparişin toplam bedelini Sipariş bilir, ama bunun için her Sipariş Kalemi kendi bedelini hesaplar; bir kalemde birden çok kahve olabileceği için Sipariş Kalemi Kahve nesneleriyle işbirliği yapar (Uzman). Gerçekte ödemeyi müşteri yapar ve Yaratıcı kalıbına göre Ödemeyi Müşteri yaratmalıdır; ancak bu durumda Müşteri ödeme hakkında bilgi taşımak zorunda kalır. Sorumluluk Siparişe verilirse hem bağımlılık azalır (Az Bağımlılık) hem de ödeme bilgisinin uzmanı zaten Sipariş olduğu için uyum iyileşir (İyi Uyum). Kredi kartı onayı dışarıdan alınan bir hizmettir; farklı kart tipleri ortak bir arayüzün arkasında çok şekilli onay fonksiyonlarıyla ele alınır (Çok Şekillilik). Bu ara birim nesneleri dolaylılık sağlar ve yeni kart tipleri eklense de sistemi değişimlerden korur.
- Ürün ekleme işleminin ardışıl diyagramı (ekrandan, 00:55:00)
  - Nesneler: `:Denetçi`, `:KahveKatalog`, `:Map<Kahve>`, `:Sipariş`, `siparişKalemleri: List<SiparişKalemi>`.
  - Mesajlar: `kahveEkle(id, miktar)` Denetçiye gelir; 2: `tanim = tanimAl(id)` (Denetçi -> KahveKatalog); 3: `tanim = bul(id)` (KahveKatalog -> Map<Kahve>); 4: `siparişEkle(tanim, miktar)` (Denetçi -> Sipariş); 5: `yarat(tanim, miktar)` ile `sk: SiparişKalemi` oluşturulur; 6: `ekle(sk)` (Sipariş -> siparişKalemleri).
  - Diyagram üzerindeki notlar: ilk mesajda Denetçi, katalogdan tanım alırken Uzman, kalem yaratılırken Yaratıcı kalıbı.
- Kuaför sınav sorusunun çözümü
  - Use case diyagramında aktörler Müşteri, Çalışan ve Yönetici'dir; çalışan tipleri use case diyagramında ayrılmaz. Kavramsal sınıf diyagramında ise Çalışan, Kuaför, Kalfa ve Çırak alt sınıflarına genelleştirilir; İşlem sınıfı hangi işlemin hangi ücretle yapıldığını, Bölüm sınıfı koltuk sayısını ve cinsiyete göre bölümü tutar. Kavramsal diyagramda metotlar yoktur; bunlar tasarımda eklenir.
- McCall kalite modeli
  - McCall, kalite özelliklerinin çoğunun tanımsal olduğunu, bu yüzden her özelliğin ölçülebilir ölçütlerle eşleştirilmesi gerektiğini söyler. Bir özellik, ilgili ölçütlerin önem derecesine göre katsayılarla çarpılıp toplanmasıyla hesaplanır. Ölçütler de tam sayısal olmayabilir; örneğin basitlik, algoritma karmaşıklığı ya da döngüsel karmaşıklık gibi başka ölçümlerle sayısallaştırılır.
  - Hoca, yeniden kullanılabilirliği McCall'un koyduğu ürün geçişi tarafının yanında ürün revizyonu tarafına da yazdığını söyledi: yeniden kullanılabilirlik arttıkça bakım yapılabilirlik de iyileşir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
