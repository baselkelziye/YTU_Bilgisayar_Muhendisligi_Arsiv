# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 30 Mayıs 2023 Salı. Ders Zoom üzerinden yapıldı. Dönemin son dersi.
  - Bu ders de dönem projesi sunumlarıyla geçti. Hoca yeni konu anlatmadı.
- Sunum düzeni
  - Bu hafta 6 grup planlandı. Sıra: E, M, H, D, G, J.
  - O ve P grupları rapor teslim etmediği için katılmadı.
  - H grubu sunum yapmadı. Yalnız teslim ettiği belgelerle değerlendirilecek.
- Sunulan projeler
  - E grubu: Online market sistemi (Swift mobil, React web, Firebase).
  - M grubu: Scooter kiralama otomasyonu (C#, Microsoft SQL Server).
  - D grubu: Online bankacılık sistemi (Java, NetBeans, MySQL).
  - G grubu: Kütüphane masa ve mola takip sistemi (Java, JavaFX, MongoDB Atlas).
  - J grubu: Süpermarket bilgi sistemi (Node.js, PostgreSQL).
- Kapanış ve final bilgisi
  - Hoca 14 haftalık dönemi değerlendirdi.
  - Final sınavı vize sınavına benzer biçimde, çevrim içi yapılacak.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dersin amacı yalnız kod yazmak değil.
  - Problemi baştan ele almak, anlamak ve anladığını biçimsel (formal) olarak ifade etmek gerekir.
  - Sonra buna uygun bir çözüm önerisi geliştirilir. Gerçekleştirme aşaması bu öneriyi taşımalıdır.
- Ekonomik fizibilitede gelir modeli açık olmalı.
  - Bankacılık grubunda kredi verilmiyor, komisyon ve kur makası sıfır. Hoca bankanın nereden para kazanacağını sordu.
- "Kaba taslak" bir tahmin kuruşuna kadar verilmez.
  - Bankacılık grubu "kaba taslak" dediği maliyeti 529 bin TL'nin kuruşuna kadar yazmıştı.
- Sunumda belirsiz ifadelerden kaçının.
  - Hoca "sallıyorum" gibi gündelik ifadeleri uyardı.
- Ekip içi görev dağılımı belli olmalı.
  - Hoca J grubuna "Bir iş ayrımı yapmadınız mı?" diye sordu.
- Katılmayan grup üyeleri hoca tarafından tek tek soruldu. Katkı vermeyen üyeler grup tarafından bildirildi.
- Teslim edilen kodun çalışması gerekir.
  - H grubunun jar dosyası açılırken exception verip kapanıyordu.

## Kısa Tekrar Notları

- Ekonomik fizibilite yöntemleri: geri ödeme süresi, net bugünkü değer (NBD), iç verim oranı (İVO).
- İVO, kullanılan iskonto oranından büyükse proje kârlıdır.
- Fizibilite matrisi alternatif sistemleri ağırlıklı puanlarla karşılaştırır.
- Veri akış diyagramı düzeyleri: taslak (bağlam, 0. düzey), 1. düzey, 2. düzey.
- Veri sözlüğü: veri akışı, veri deposu ve veri yapısı girdilerini tanımlar.
- Süreç tanımlama formu: süreç adı, tanımı, girdileri, çıktıları ve sözde kod ile mantığı.
- ER diyagramı: dikdörtgen varlık, elips nitelik, eşkenar dörtgen ilişki. Anahtar nitelik altı çizili gösterilir.
- Yasal fizibilitede KVKK, bankacılıkta ayrıca BDDK ve SPK mevzuatı dikkate alınır.

## Detaylı Açıklamalar

Bu derste son altı grubun dönem projesi sunumları yapıldı. Hoca sunumlar sırasında fizibilite, gelir modeli ve ekip çalışması üzerine sorular sordu. Dersin sonunda dönemi değerlendirdi ve final sınavı hakkında kısa bilgi verdi.

### Online market sistemi (E grubu)

- Problem: Mevcut marketler hız ve ürün çeşitliliği bakımından yetersiz. Pandemi ile birlikte evden alışveriş alışkanlığı arttı.
- Ekip: proje yöneticisi, iki yazılımcı, sistem analisti ve hem tasarımcı hem müşteri rolünde bir üye.
- Teknik fizibilite
  - Mobil için Swift, web için React, veri tabanı için Firebase.
  - Use case diyagramları Violet UML Editor ile, veri akış, ER ve yapı diyagramları draw.io ile çizildi.
- Ekonomik fizibilite
  - Toplam maliyet 97 200 TL.
  - Net bugünkü değer 198 bin TL olarak hesaplandı.
  - İç verim oranı %74, kullanılan iskonto oranı %20. İVO daha büyük olduğu için proje kârlı kabul edildi.
- Zaman: 11 Nisan - 21 Mayıs arası 40 gün. Waterfall modeli.
- Fizibilite matrisi: Java-SQL, Swift-React ve Flutter karşılaştırıldı. Swift-React seçildi.
- Gereksinim analizi için anket yapıldı. Alışveriş sonrası müşteriye değerlendirme anketi soruluyor.
- Veri akış diyagramı 1. düzeyde yöneticiden 1, müşteriden 6 süreç var.
- Demo: Yetersiz bakiyede satın alma engelleniyor. Firebase Authentication ile şifre sıfırlama e-postası gönderiliyor.
- Hoca uygulamanın neden İngilizce yapıldığını sordu. Grup küresel kitleye hitap etmek için dedi.

### Scooter kiralama otomasyonu (M grubu)

- Kullanıcılar: operatör ve yönetici. Müşteri sisteme doğrudan erişmiyor, işlemleri operatör yapıyor.
- Teknik: C# (Visual Studio) ve Microsoft SQL Server. Ekip bu dillere yatkın olduğu için 3. sistem seçildi.
- Ekonomik: Yazılım yaklaşık 6000 dolar, bilgisayar 1000-1500 dolar. Toplam 7000-7500 dolar.
- Zaman: ön inceleme ve fizibilite 2 hafta, analiz 1 hafta, tasarım 2 hafta, kodlama 4 hafta.
- Veri depoları: müşteri, bakım, operatörler, scooter kayıtları, kiralama geçmişi.
- Kiralama akışı (2. düzey DFD)
  - Operatör scooter ve müşteri numarasını girer. Sistem ikisinin de var olduğunu kontrol eder.
  - Scooter "kirada" durumuna geçer. Kiralama geçmişine tarih ve saatle yeni kayıt eklenir.
- Teslim akışı
  - Müşterinin son kiralama kaydı bulunur. Başlangıç zamanı ile teslim zamanından süre ve ücret hesaplanır.
  - Scooter yeniden "uygun" durumuna geçer.
- Fiyat güncellemesi: Var olan fiyat düzenlenmez, listeye yeni fiyat eklenir. Böylece geçmiş kayıtlar doğru kalır.

### Online bankacılık sistemi (D grubu)

- Senaryo: Bir yatırımcı tamamen çevrim içi bir banka kurmak istiyor.
  - Para transferinde komisyon yok, kredi verilmiyor, döviz ve altında alış-satış makası başta sıfır.
  - Fatura ödemesi (elektrik, su, doğal gaz) yapılabiliyor.
- Hocanın sorusu: Banka nereden para kazanacak? Grup önce müşteri çekmeyi, sonra makası açarak gelir elde etmeyi planladığını söyledi.
- Teknik: Java ve NetBeans, veri tabanı MySQL. Yazılım geliştirme modeli olarak waterfall seçildi.
- Sosyal fizibilite: Ankette kullanıcılar sade ve kolay sistemi karmaşık ve çok işlevli sisteme tercih etti.
- Yasal fizibilite: KVKK, aydınlatma metni, BDDK ve SPK mevzuatı.
- Ekonomik: Maliyet yaklaşık 529 bin TL, ayrılan bütçe yaklaşık 1 milyon TL.
- Veri sözlüğü örnekleri
  - Veri akışı: kişisel bilgiler (isim, soy isim, TC, cinsiyet, telefon, doğum tarihi).
  - Veri deposu: hesaplar listesi (hesap türü, IBAN, bakiye), günde ortalama 20 giriş.
  - Veri yapısı: para transferi (gönderici hesap, miktar, alıcı IBAN, güncel bakiyeler).
- ER diyagramı: banka hesabı, müşteri, kayıtlı hesaplar, admin. IBAN anahtar nitelik.
  - Bir müşterinin birden çok banka hesabı ve birden çok kayıtlı hesabı olabilir.
- Demo: Yeni müşteri kaydı admin onayından sonra aktif oluyor. Bakiyesi olan hesap silinemiyor. Geçersiz IBAN'a para gönderilemiyor.

### Kütüphane masa ve mola takip sistemi (G grubu)

- Problem: Kütüphanede boş masa bulmak için dolaşma, sıra bekleme ve uzun molalarla masa işgal etme.
- Ekip: 5 kişilik grubun 2 üyesi çalışmaya katılmadı. Proje 3 kişiyle yapıldı.
- Teknik: Java, JavaFX arayüz, MongoDB Atlas bulut veri tabanı.
  - MongoDB Atlas seçme nedenleri: altyapı gerektirmemesi, otomatik yedekleme, şifreleme ve erişim kontrolü.
- Gereksinim analizi: Anket katılımcılarının en büyük sorunu boş masa bulmak için kütüphaneyi dolaşmaktı (56 kişi).
- Kullanım senaryoları
  - Rezervasyon: Boş masa varsa oda ve masa seçilir. Yoksa kullanıcıya sıra numarası verilir.
  - Mola: Kullanıcının mola hakkı (kredi) var. Mola süresi aşıldıkça kredi düşer. Kredisi biten kullanıcı kütüphaneden çıkarılır.
  - Çıkış: Masa boşalır. Sırada biri varsa masa doğrudan ona atanır.
- Sınıflar: üye, kütüphane, sıra, oda.
- Demo: Doluluk %100 olunca "sıraya gir" düğmesi çıkıyor. Masadan kalkan kullanıcının yerine sıradaki kullanıcı otomatik atanıyor.
- Müşteri geri bildirimi: Sistem biraz yavaş.

### Süpermarket bilgi sistemi (J grubu)

- Modüller: kullanıcı işlemleri, stok ve ürün işlemleri, alışveriş, kampanya, şube yönetimi.
- Teknik: Node.js ve PostgreSQL.
- Ekonomik: Geri ödeme süresi 2 yıl olarak tahmin edildi.
- Riskler: güvenlik (veri sızıntısı), veri kaybı (çözüm: düzenli yedekleme), doğal afetler.
- Admin işlemleri: çalışan, ürün, şube bilgileri ve belirli tarih aralığında yüzdelik indirim kampanyası.
- Demo: Sepete eklenen ürün stoktan düşüyor, sepetten çıkarılınca geri ekleniyor. Satın alma modülü yapılmadı.

### Ders sonrası notlar

- E grubunun ekonomik analizi doğru yorumlandı: İVO (%74) iskonto oranından (%20) büyükse NBD pozitiftir ve proje kabul edilir. Altyazıda "iş kontrolün" diye geçen ifade iskonto oranıdır.
- E grubunun geri ödeme süresi altyazıda anlaşılmıyor ("2,12'den 26 ay"). Kesin değer için kayda bakın.
- D grubu "fonksiyonel yaklaşım" seçtiğini ve Java kullandığını söyledi. Java nesne yönelik bir dildir. Fonksiyonel (yapısal) çözümleme de seçilebilir, ama bu durumda tasarım araçları veri akış diyagramı ve yapı diyagramı olur. Grup tutarlı olarak bunları kullandı.
- D grubu waterfall ile "waterfall iteratif" modelini birlikte andı. Klasik waterfall'da aşamalar geri dönüşsüzdür. Geri dönüş isteniyorsa yinelemeli (iterative) waterfall ya da artımlı modeller kullanılır.
- Altyazıdaki "Sınav-i Mülkiyet Kanunu" 6769 sayılı Sınai Mülkiyet Kanunu'dur.
- Altyazıdaki "KBKK" 6698 sayılı Kişisel Verilerin Korunması Kanunu'dur (KVKK).
- G grubunun maliyeti altyazıda tam anlaşılmıyor. İki bilgisayar (2×2750 dolar) ve yazılım (11 000 dolar) toplamı 16 500 dolar eder. Açıklanan toplam 17 234 dolar. Aradaki 734 dolarlık fark büyük ihtimalle MongoDB Atlas'ın yıllık ücretidir, ama aylık tutar kayıtta net duyulmuyor.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
