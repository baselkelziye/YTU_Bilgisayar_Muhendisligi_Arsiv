# Yazılım Mühendisliği Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Yazılım Mühendisliği (BLM3722)
* **Hoca:** Prof. Dr. Oya Kalıpsız
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023
* **Şube:** BLM3722 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Yazılım Mühendisliğine Giriş: Yazılım, Yazılım Türleri, Yanılgılar ve Temel Süreç Adımları | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Yazılım Geliştirme Süreç Modelleri, Çevik Yaklaşım, XP ve Scrum | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Dönem Projesi, CASE Araçları, CMMI Düzeyleri ve Kullanım Senaryolarına Giriş | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 5** | Nesneye Yönelik Çözümleme ve Tasarım: Use Case, Sınıf, Sıralama ve Etkinlik Diyagramları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Nesneye Yönelik Çözümleme, Etkinlik ve Durum Şemaları, Tasarım Kalıpları | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Vize Öncesi Tekrar, SRS Belgesi Örneği, Etkinlik Şemaları ve Yazılım Kalitesi | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Uygulama: Poliklinik Sistemi İçin Kullanım Şeması, Kullanım Senaryoları ve Sınıf Şeması | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 10** | Yazılım Kalitesi, Test Stratejisi ve Test Türleri | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Kalite Tekrarı, Yazılım Proje Yönetimi, Proje Planı ve Risk Yönetimi | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Uygulama: Otobüs Bileti Senaryosu İçin UML Sınıf, Sıralama, Etkinlik ve Durum Diyagramları | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Dönem Projesi Sunumları (1. Gün) | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Dönem Projesi Sunumları (2. Gün) | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

> [!NOTE]
> 4 numaralı kayıt (22 Mart 2023) arşivde yoktur; 26 Nisan 2023 haftası vize haftasıdır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Yazılım Mühendisliğine Giriş: Yazılım, Yazılım Türleri, Yanılgılar ve Temel Süreç Adımları
* **Genel Konular:**
  - Dersin tanıtımı: kaynak kitaplar, içerik, değerlendirme ve proje.
  - Yazılım nedir? Yazılımın elemanları ve "yazılım = program" yanılgısı.
  - Yazılım yaşam döngüsü (software life cycle) ve bakım (maintenance).
  - Yazılım türleri: sistem, mühendislik/bilimsel, gömülü, uygulama, hazır paket (COTS), ürün hattı (product line), kurumsal yazılımlar.
  - Eski yazılım (legacy software) kavramı.
  - Müşteri, yönetim ve programcı açısından yazılım hakkındaki yanılgılar (software myths).
  - Mühendislik kavramı: ölçme ve tasarım.
* **Hocanın Vurgusu:**
  - **Yazılım eşittir program değildir.** Bu derste bu yanlışı kesinlikle yapmamanız gerekiyor.
    - Yazılım; program, belgeler, veri tanımları/veri tabanı ve test verilerinin tümüdür.
  - **Mühendisliğin iki anahtar kelimesi:** ölçme ve tasarım. "Mühendis" kelimesi "hendese" (ölçme bilimi) kökünden gelir.
    - Mühendis ölçen, biçen kişidir.
  - **Hemen kod yazmaya başlanmaz.** Önce analiz, sonra tasarım, sonra gerçekleme yapılır.
  - **Analiz "ne?", tasarım "nasıl?" sorusuna cevap verir.**
    - Analiz: Müşteri ne istiyor? İş süreci nasıl işliyor? Hangi raporlar, hangi kalıcı veriler gerekiyor?
  - **Ekonomik, ucuz demek değildir.** Ekonomik çözüm, maliyete göre en fazla faydayı sağlayan çözümdür.
    - En düşük maliyetli çözüm her zaman en ekonomik değildir.
* **Detaylı Açıklamalar:** Bir yazılım projesinin üç tarafı vardır: müşteri, yönetim ve yazılım geliştirici.

### 🔹 Ders 2: Yazılım Geliştirme Süreç Modelleri, Çevik Yaklaşım, XP ve Scrum
* **Genel Konular:**
  - Geçen dersin tekrarı: yazılımın tanımı, yazılım türleri, eski yazılım, yanılgılar, yazılım mühendisliği tanımı, CASE.
  - Yazılım mühendisliğinin beslendiği bilim dalları ve yazılım sistemi kavramı.
  - Dersin hedefleri: ders sonunda bilinmesi gerekenler.
  - Klasik süreç modelleri: şelale (waterfall), prototip, artımlı (incremental), spiral, RAD, bileşen tabanlı (component-based), birleşik süreç (Unified Process).
  - Çevik (agile) yaklaşım: ortaya çıkışı ve ilkeleri.
  - Uç programlama (XP, Extreme Programming): planlama, tasarım, kodlama, test.
  - Scrum: koşu (sprint), günlük toplantı, Scrum panosu ve diğer modellerle karşılaştırma.
* **Hocanın Vurgusu:**
  - **Süreç adımları her zaman sırayla gitmez.** Adımların nasıl dizildiği hangi modelin uygulandığını belirler.
  - **Şelale modelinin en büyük dezavantajı:** Müşteri çalışan ürünü ancak en sonda görür.
    - Ara aşamalarda yalnızca raporlar ve modeller gider.
  - **Spiral model**, şelale, prototip ve artımlı modelin birleşimidir.
    - Her çevrimde risk analizi vardır ve çok belge üretir. Bu yüzden özellikle büyük ve hata kritik (safety-critical) projelerde kullanılır.
  - **Çevik modellerin temeli:** müşterinin çalışan yazılımı erken görmesi, müşterinin ekip içinde olması, dinamik ekip ve basitlik.
  - **"Çevik her projede başarılıdır" diye bir şey yok.** Model; projenin tipine, ekibin yapısına ve yazılımın konusuna göre seçilir.
    - Slayttaki tablo Scrum tarafından bakılarak hazırlanmış.
* **Detaylı Açıklamalar:** Ders sonunda şunlar biliniyor olmalı:

### 🔹 Ders 3: Dönem Projesi, CASE Araçları, CMMI Düzeyleri ve Kullanım Senaryolarına Giriş
* **Genel Konular:**
  - Sınav ağırlıkları ve dönem projesinin tanıtımı.
  - Üç proje konusu: seyahat acentesi bilet ve tatil sistemi, yazılım evi insan kaynakları sistemi, medya takip sistemi.
  - Analiz ve tasarımın önemi: "salıncak hikâyesi".
  - Sistem geliştirme yaşam döngüsü (SDLC) ve yazılım geliştirme yaşam döngüsü.
  - Temel ve destek (şemsiye) aktivitelerinin tekrarı. Ölçmenin önemi.
  - CASE araçları: üst, orta ve alt CASE.
  - Süreç sertifikasyonu: CMM, CMMI ve düzeyleri. Türkiye'deki durum.
* **Hocanın Vurgusu:**
  - **Projede her şey nesneye yönelik yapılacak:** analiz, modelleme, tasarım ve kodlama.
    - Sistem Analizi dersindeki gibi klasik yöntem seçme serbestliği yok.
  - **En az bir modül kodlanacak ve çalıştırılarak gösterilecek.** Sistemin tamamının çalışması gerekmiyor.
  - **Diyagramlar mutlaka bir araçla çizilecek.** Önerilen araç Violet UML.
    - Amaç hem standart çizim hem de diyagramlar arası geçişte (use case → sınıf → sıralama) tutarlılık.
  - **Grubu kurmak öğrencilerin sorumluluğunda.** Hoca listeden grup oluşturmayacak.
    - Bildirilen grup sonradan büyütülemez. Grupta ders bırakan olursa kalanlar işi bitirir.
  - **Grupta herkes aynı notu almayabilir.** Sunumda her üye her soruya cevap verebilmeli.
* **Detaylı Açıklamalar:** 1. **Seyahat acentesi bilet ve tatil sistemi:** - Havayolu, demiryolu ve tur biletleri satılıyor. Başka firmaların biletleri de satılabilir. - Bilet aldıkça ve tatile gittikçe puan biriken bir puan sistemi var. Biriken puanlar ödemede kullanılabiliyor. - Ödeme türleri: nakit, kredi kartı, çek. 2. **Yazılım evi insan kaynakları sistemi:** - Çalışanların bilgileri tutuluyor. Çalışan kaydı yapılıyor. - Yönetimin başlatıp bitirdiği projeler ve bu projelerin insan kaynağı takibi. - Görevler: analist, tasarımcı, programcı, yönetici. - Biten projeden çıkan çalışan başka projeye atanabilir ya da işten çıkarılabilir. - Maaş ve tazminat hesapları muhasebe programına bırakılıyor. Bu proje bu hesaplara girmiyor, yalnızca çalışanın hangi grupta olduğunu atıyor. 3. **Medya takip sistemi:** - Şirket radyo, televizyon, gazete ve dergileri takip ediyor. İnternet siteleri ve bloglar da eklenebilir. - Müşteriler şirket ya da şahıs olabilir. - Standart raporlar günlük, haftalık, aylık. Fiyatları belli. - Müşteriye özel raporların periyodu ve fiyatı anlaşmada belirlenir ve sonradan değişmez. - Takip edilen medya organları bir veri tabanında tutulur. Yeni çıkanlar eklenir, değişenler güncellenir, kapananlar silinir. - Şirket müşterilerin itibarı ve bilinirliği hakkında anketler düzenler. Anketler ayrıca ücretlendirilir. Kayıtlı anketörlerin iş planı sistem üzerinden yapılır. - Medya organları ortak bir arayüzle sorgulanır. Rapor belge olarak müşteriye gönderilir.

### 🔹 Ders 5: Nesneye Yönelik Çözümleme ve Tasarım: Use Case, Sınıf, Sıralama ve Etkinlik Diyagramları
* **Genel Konular:**
  - Proje gruplarıyla ilgili duyurular.
  - Gereksinim mühendisliğinin 7 adımının tekrarı (önceki dersin konusu). SRS belgesi ve izlenebilirlik tablosu.
  - Nesneye yönelik çözümleme: alan (domain) analizi, kullanım öyküsü ve kullanım senaryosu belgesi.
  - Use case diyagramı: gösterim, include ve extend ilişkileri.
  - Sınıfların ve etkileşimlerin belirlenmesi. Kavramsal sınıf diyagramı (alan modeli).
  - Analiz ve tasarım aşamasında hazırlanan belgeler.
  - Sıralama (sequence) diyagramı ve tasarım kalıplarıyla birlikte kullanımı.
* **Hocanın Vurgusu:**
  - **Projelerde izlenebilirlik tablosu (traceability matrix) olmalı:** Hangi gereksinimin hangi modülle, hangi sınıfla, hangi veri tabanı tablosuyla karşılandığı gösterilmeli.
  - **SRS raporu** IEEE 830 ve 2011 tarihli ISO/IEC/IEEE standardı dikkate alınarak, en azından özetlenerek hazırlanmalı.
  - **Her aktörün en az bir senaryosu olmalı.** Hiçbir senaryoyla ilişkilendirilemeyen aktör diyagramdan çıkarılır.
  - **Kavramsal sınıf diyagramında işlemler (metotlar) yazılmaz.** Yalnızca sınıf adı, öznitelikler ve sınıflar arası ilişkiler gösterilir.
    - İşlemler tasarım sınıf diyagramında eklenir.
  - **Tasarımda en az iki diyagram şarttır:** sıralama diyagramları ve tasarım sınıf diyagramı.
    - Bunlara etkinlik ve durum geçiş diyagramları da eklenmeli.
* **Detaylı Açıklamalar:** 1: kahveEkle(id, miktar) --> :Denetçi [Denetçi kalıbı] 2: tanim = tanimAl(id) :Denetçi --> :KahveKatalog [Uzman kalıbı] 3: tanim = bul(id) :KahveKatalog --> :Map<Kahve> 4: siparişEkle(tanim, miktar) :Denetçi --> :Sipariş 5: yarat(tanim, miktar) :Sipariş --> sk:SiparişKalemi [Yaratıcı kalıbı] 6: ekle(sk) :Sipariş --> siparişKalemleri ```

### 🔹 Ders 6: Nesneye Yönelik Çözümleme, Etkinlik ve Durum Şemaları, Tasarım Kalıpları
* **Genel Konular:**
  - Ders 5 Nisan 2023 Çarşamba günü yapıldı. Hoca dersi üniversitedeki sınıftan online verdi. Elektrik ve bağlantı kesintileri yüzünden ders iki kez bölündü.
  - Nesneye yönelik çözümleme (object-oriented analysis) süreci tekrar edildi:
    - Uygulama alanının çözümlenmesi (domain analysis).
  - Tasarım şemaları:
    - Ardışıl şema (sequence diagram) kısaca hatırlatıldı.
  - Tasarım kalıpları (design patterns):
    - Yaratıcı (Creator)
  - Yeniden kullanılabilirlik (reusability) kavramı ve tasarım kalıplarıyla ilişkisi.
  - Etkileşim şemaları (interaction diagrams): ardışıl şema ile işbirliği şeması (collaboration diagram) arasındaki fark.
  - Proje konuları ve gelecek haftaki uygulama dersi duyuruldu.
* **Hocanın Vurgusu:**
  - **Analiz ile tasarım farklıdır.** Analiz problemi anlamaktır: "ne yapılacak?" sorusunu cevaplar.
    - Tasarım ise çözümün nasıl kurulacağını gösterir. Analizin çıktısı SRS belgesidir. Tasarım bu belgeye dayanarak başlar.
  - **Kullanım öyküsü belgesine yalnız ilgi alanına giren bilgi yazılır.** Bizden istenmeyen konular belgeye konmaz.
  - **Kavramsal sınıf şemasında işlemler (metotlar) yazılmaz.** Yalnız sınıf adı, nitelikler ve ilişkiler gösterilir.
    - Metotlar tasarım sınıf şemasında eklenir.
  - **Etkinlik şeması**, işlemlerin farklı ortamlarda ve farklı aktörlerde nasıl yürüdüğünü gösterir.
    - Fork ve join yapısı bu yüzden önemlidir.
  - **Durum şeması**, bir nesnenin ya da aktörün yaşamı boyunca hangi durumlardan geçtiğini gösterir.
* **Detaylı Açıklamalar:** Hoca gereksinim analizinin adımlarını hatırlattı. Önce işin hedefi anlaşılır. Sonra uygulama alanı hakkında bilgi toplanır: mevcut uygulamalar, teknik literatür, müşteri anketleri, bugünkü ve gelecekteki gereksinimler. Bu bilgi, müşterinin dilini anlamak için gereklidir.

### 🔹 Ders 7: Vize Öncesi Tekrar, SRS Belgesi Örneği, Etkinlik Şemaları ve Yazılım Kalitesi
* **Genel Konular:**
  - Ders 12 Nisan 2023 Çarşamba günü online yapıldı. Vizeden önceki son konu dersiydi. Dersin büyük kısmı vize öncesi tekrar.
  - Ders planındaki değişiklikler ve sınav düzeni duyuruldu.
  - Tekrar edilen konular:
    - CASE (Computer-Aided Software Engineering) araçları.
  - IEEE 830 yapısına göre hazırlanmış örnek bir SRS belgesi incelendi: "Etkinlik Duyuru Sistemi" projesi.
  - Etkinlik şemasında (activity diagram) kulvarlı iki örnek: teklif (kota) hazırlama ve sipariş alma.
  - Tasarım kalıplarının tekrarı.
  - Yeni konu: yazılım kalitesi.
    - McCall'ın kalite faktörleri ve üç bakış açısı.
* **Hocanın Vurgusu:**
  - **Sınav düzeni değişti:** Tek vize yapılacak.
    - Vize 9. haftada online olacak. Önceden iki vize (ya da vize ve kısa sınav) planlanmıştı. Vize ile proje notunun ağırlıkları sonra duyurulacak.
  - **8. hafta uygulama dersi:** Gelecek hafta ders asistanı analiz ve tasarım şemalarıyla bir uygulama yapacak.
    - Uygulama laboratuvarda değil, online yapılacak.
  - **Kalite özellikleri vizeye dahil.** Test teknikleri vizeye dahil değil, vizeden sonra işlenecek.
  - **Hataları erken bulun.** Süreç ilerledikçe hata bulma maliyeti artar, hata bulma olasılığı düşer.
    - Her kilometre taşında gözden geçirme (review) yapılmalıdır.
  - **Projeye başlamadan bir süreç modeli seçin ve ona uyun.** Modelin kendi kontrolleri işinizi kolaylaştırır.
* **Detaylı Açıklamalar:** Bir öğrenci CASE araçlarını "UML şemalarını program yardımıyla çizmek için kullanılan programlar" diye tanımladı. Hoca bunun yalnız analiz ve tasarım desteği olduğunu söyledi. CASE araçları kodlamada, konfigürasyon yönetiminde ve testte (birim, bütünleştirme, sistem, kullanıcı testi) de kullanılır. Açık kaynaklı CASE araçları vardır. Büyük projelerde kullanılan profesyonel araçlar ise çok pahalıdır.

### 🔹 Ders 8: Uygulama: Poliklinik Sistemi İçin Kullanım Şeması, Kullanım Senaryoları ve Sınıf Şeması
* **Genel Konular:**
  - Ders 19 Nisan 2023 Çarşamba günü, Ramazan Bayramı'ndan önce online yapıldı. Vizeden bir hafta önceki uygulama dersiydi.
  - Dersi ders asistanı Arş. Grv. Elçin Güveyi anlattı. Prof. Dr. Oya Kalıpsız dersi açtı ve sözü asistana bıraktı.
  - Örnek vaka: bir polikliniğin hasta ve çalışan yönetim yazılımı.
  - Violet UML Editor ile üç çizim yapıldı:
    - Kullanım şeması (use case diagram): aktörler, etkileşimler, `include`, `extend`, aktör genelleştirmesi.
  - Vize sınavının biçimi duyuruldu.
* **Hocanın Vurgusu:**
  - **Vize:** Gelecek hafta, ders gününde ve ders saatinde online yapılacak.
    - Sorular test biçiminde olacak, ama şema çizdiren sorular da gelebilir.
  - **Kullanım senaryosunda mutlaka olması gerekenler:** birincil aktör, ilgililer ve beklentileri, ön koşul, son koşul, ana akış ve alternatif akışlar.
  - **extend, nesneye yönelik programlamadaki kalıtım değildir.** Yalnız bir işin bazı koşullarda genişlediğini, alternatif bir akışa girdiğini gösterir.
  - **Alternatif akışta yazılan durumlar, kullanım şemasında `extend` olarak da gösterilmelidir.** Asistan, özel rapor gereken reçete durumunu örnek verdi.
  - **Analist bakış açısıyla sınıf şemasında metotlar yazılmadı.** Yalnız sınıf adları ve nitelikler gösterildi.
* **Detaylı Açıklamalar:** Asistanın çizdiği şemanın metin hâli:

### 🔹 Ders 10: Yazılım Kalitesi, Test Stratejisi ve Test Türleri
* **Genel Konular:**
  - Ders 3 Mayıs 2023 Çarşamba günü, vizeden sonraki ilk derste online yapıldı.
  - Yeni bölüm: yazılım kalitesi ve test.
  - İşlenen konular:
    - Kodlama aşamasında kalite: programlama dili seçimi, açıklama satırları, anlamlı değişken adları.
  - Vize, proje, sunum ve final duyuruları.
* **Hocanın Vurgusu:**
  - **Testin tek amacı hatayı bulmaktır.** Hatayı düzeltmek testin işi değildir.
    - Bulunan hataları ayıklamak ve düzeltmek hata ayıklama (debugging) işidir.
  - **Hata ne kadar geç bulunursa o kadar pahalıya mal olur.** İlk aşamaları hızlı geçip hemen kodlamaya başlamak, sonradan daha zor bulunan hatalara yol açar.
    - Hoca bu grafiği her zaman akılda tutmayı önerdi.
  - **Kara kutu ile saydam kutu arasında seçim yapılmaz.** İkisi birlikte uygulanır.
  - **Saydam kutu testinin hedefi:** Bir modüldeki bütün bağımsız yolların en az bir kez çalıştırılması.
  - **Sınır değer analizinin mantığı:** Hata varsa çoğunlukla sınırlarda ortaya çıkar.
* **Detaylı Açıklamalar:** Gereksinimler analizden alınır. Tasarım yapılır ve değerlendirilir. Kodlama yapılır ve önce sözdizimi denetlenir. Sonra test aşamasına geçilir. Önce test planı hazırlanır. Ardından modüller, sonra bütün sistem test edilir. En son kullanıcı onay testi yapılır ve sistem kullanıma hazırlanır.

### 🔹 Ders 11: Kalite Tekrarı, Yazılım Proje Yönetimi, Proje Planı ve Risk Yönetimi
* **Genel Konular:**
  - Kayıt 10 Mayıs 2023 Çarşamba günü online yapılan derse ait, yaklaşık 2 saat 6 dakika sürüyor.
  - Dersin ilk yarısı geçen haftanın tekrarı: yazılım mühendisliği tanımı, yazılım kalite faktörleri, McCall kalite modeli, kaliteyi sağlama yolları ve test aşamaları.
  - İkinci yarıda yeni konu yazılım proje yönetimi (software project management): proje yönetiminin aşamaları, ölçüm (measurement), proje planının içeriği, iş kırılım yapısı (Work Breakdown Structure, WBS), Gantt diyagramı, kilometre taşları (milestones).
  - Risk yönetimi (risk management): riskin tanımı, risk türleri, risk tablosu, olasılık ve etki matrisi, risk bilgi sayfası ve önlemlerin maliyeti.
  - Ayrıntılı proje planı şablonu: kabuller ve kısıtlar, iş planı, bütçe, ekip organizasyonu, alan (kapsam) yönetimi, iletişim ve kalite yönetim planları.
  - Ders sonunda sınav ağırlıkları, proje sunumları ve gelecek haftanın uygulama dersi duyuruldu.
* **Hocanın Vurgusu:**
  - Yazılım mühendisliğinin üç anahtar kavramı: **kaliteli yazılım**, **en ekonomik şekilde elde etme** ve **mühendislik araç ve yöntemlerini kullanma**.
  - Mühendisliğin iki temel kavramı **tasarım** ve **ölçüm**dür. "Ölçemediğinizi yönetemezsiniz."
  - Kaliteyi sağlamanın yolları sırasıyla:
    - Bir süreç modeli seçip kurallı uygulamak (waterfall, Scrum vb.).
  - Test yalnızca hatayı ve yerini bulur.
    - Hatayı düzeltmek (debug) testin parçası değildir.
  - Birim testini kodu yazan geliştirici yapar, test ekibi yapmaz.

### 🔹 Ders 12: Uygulama: Otobüs Bileti Senaryosu İçin UML Sınıf, Sıralama, Etkinlik ve Durum Diyagramları
* **Genel Konular:**
  - Kayıt 17 Mayıs 2023 Çarşamba günü online yapılan uygulama dersine ait, yaklaşık 56 dakika sürüyor.
  - Hoca dersi açıyor ve uygulamayı bir araştırma görevlisine bırakıyor. Uygulamayı asistan anlatıyor.
  - Tek bir senaryo üzerinden dört UML diyagramı çiziliyor: sınıf diyagramı (class diagram), sıralama diyagramı (sequence diagram), etkinlik diyagramı (activity diagram) ve durum diyagramı (state diagram).
  - Senaryo: otobüs bileti satış sistemi. Yolcu sefer, otobüs ve koltuk seçer, rezervasyon yapar, ödeme yapar.
  - Diyagramlar Violet UML Editor ile çiziliyor.
* **Hocanın Vurgusu:**
  - Diyagramlar birbirine **tutarlı** olmalı.
    - Sıralama diyagramındaki mesajlar, sınıf diyagramındaki metotlardan seçilir.
  - Sınıf diyagramında nitelikler (attributes) genellikle private (`-`), onlara erişen metotlar public (`+`) gösterilir.
  - Otobüs ile koltuk arasındaki ilişki güçlü olduğu için **bileşim (composition)** seçildi.
    - Koltuk otobüsten bağımsız var olamaz.
  - Sıralama diyagramında nesneler yatay eksende, zaman dikey eksende ilerler.
    - Her nesnenin bir yaşam çizgisi (lifeline) ve etkinlik çubukları (activation bar) vardır.
  - Etkinlik diyagramı adımları yukarıdan aşağı sırayla verir.
    - Sistemin karar vermesi gereken yerler karar düğümüyle (decision) gösterilir.
* **Detaylı Açıklamalar:** RezervasyonEkranı - seferler: Sefer() + seferAra(gidis: String, varis: String, gun: Date): boolean + gosterSeferBilgileri(sefer: Sefer): void + otobüsSec(busX: Otobüs): void + koltukSec(koltukY: Koltuk): void

### 🔹 Ders 13: Dönem Projesi Sunumları (1. Gün)
* **Genel Konular:**
  - Kayıt 24 Mayıs 2023 Çarşamba günü online yapılan derse ait, yaklaşık 1 saat 38 dakika sürüyor.
  - Ders, dönem projesi sunumlarının ilk günü. Konu anlatımı yok. Bu hafta gönüllü dört grup sundu.
  - Sunulan projeler, dönem başında verilen üç vaka üzerine kurulu:
    - Bir medya takip şirketi için bilgi sistemi: medya organlarını izleme, müşteriye günlük/haftalık/aylık ve özel rapor, anket hizmeti.
  - Her sunumda proje planı (alan tanımı, kabuller ve kısıtlar, Gantt diyagramı, ekip organizasyonu, risk tablosu), gereksinim modelleme, nesneye dayalı modelleme ve tasarım diyagramları ile birim testleri anlatıldı.
  - Hoca sunumlar sırasında sorular sordu ve geri bildirim verdi. Bu özet, projelerin ortak içeriğini ve hocanın geri bildirimlerini adsız olarak toplar.
* **Hocanın Vurgusu:**
  - Grubun **bütün üyeleri** sunumda bulunmalı.
    - Hoca her sunumdan önce üyeleri tek tek yokladı ve herkesin hangi işi yaptığını sordu.
  - **Kabuller ve kısıtlar ayrı ayrı** yazılmalı.
    - Kabuller genellikle olumlu varsayımlardır. Kısıtlar problemdeki, sistemdeki veya projedeki sınırlamalardır.
  - Kısıt yazarken gerekçe verilmeli.
    - Örneğin "proje Java ile yazılmalıdır" yerine "grup üyelerinin en iyi bildiği dil Java'dır" ya da "bu sisteme en uygun dil Java'dır" gibi bir ifade daha doğru.
  - Risk tablosunda hangi risklerin takip edileceği belirlenmeli: etkisi büyük ve olasılığı yüksek (veya orta-yüksek) riskler takip edilir, düşük olanlar ihmal edilebilir.
    - Bunun için bir eşik konabilir.
  - Her geliştirici yazdığı birimin **birim testini** kendisi yazmalı.

### 🔹 Ders 14: Dönem Projesi Sunumları (2. Gün)
* **Genel Konular:**
  - Kayıt 31 Mayıs 2023 Çarşamba günü online yapılan derse ait, yaklaşık 2 saat 54 dakika sürüyor.
  - Ders, dönem projesi sunumlarının ikinci ve son günü. Önceki hafta sunmayan bütün gruplar sundu; on grup kadar sunum var. Konu anlatımı yok.
  - Projeler yine üç vaka üzerine: yazılım evinin insan kaynakları sistemi, medya takip şirketi bilgi sistemi ve seyahat acentesi bilet/tatil sistemi.
  - Sunumlarda proje planı, risk tablosu, use case diyagramı ve senaryo belgesi, izlenebilirlik tablosu, kavramsal ve tasarım sınıf diyagramları, sıralama, etkinlik ve durum diyagramları, tasarım kalıpları ve birim testleri anlatıldı.
  - Hoca sunumlarda tekrar eden alan tanımlarını geçtirdi ve sorularını kavramlar üzerine yoğunlaştırdı. Bu özet hocanın sorularını ve geri bildirimlerini adsız olarak toplar.
* **Hocanın Vurgusu:**
  - Alan tanımı herkes için aynı olduğundan yalnızca **gruba özgü** kabul ve kısıtlar anlatılmalı.
    - Kabuller ve kısıtlar ayrı başlıklarda yazılmalı.
  - Her grupta hangi **süreç modelinin** seçildiği soruldu.
    - Çevik (agile) model seçildiyse Gantt diyagramında Scrum'daki sprintler, yani parça parça ilerleyen bölümler görünmeli. Şelale gibi "analiz bitti, tasarım başladı" düzeni çevik model değildir.
  - Gantt diyagramında **milestone**'lar gösterilmeli: işin belli bir noktaya geldiği ve toplantı/değerlendirme yapılan yerler.
  - Risk tablosunda **önlem** sütunu da olmalı.
    - Önem derecesi olasılık ile etkinin çarpımından çıkar.
  - Riskler **projenize özgü** yazılmalı.
    - Bir dönem projesi için elektrik kesintisi veya genel veri güvenliği yerine "ekipten birinin dersi bırakması" ya da "bir üyenin bilgi eksikliği" gibi riskler daha anlamlıdır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
