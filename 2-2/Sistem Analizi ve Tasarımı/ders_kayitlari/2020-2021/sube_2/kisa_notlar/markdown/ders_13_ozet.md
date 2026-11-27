# Ders 13 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumlarının devamı
  - Bu derste kalan gruplar dönem projesi olarak geliştirdikleri bilgi sistemlerini sundu. Sunumlar yine sistem geliştirme yaşam döngüsünü izledi: müşteri görüşmesi ve gereksinimler, ekip yapısı ve roller, fizibilite, Gantt diyagramıyla zaman planı, analiz (veri akış diyagramı, kullanım senaryosu, veri sözlüğü), tasarım (yapı diyagramı, sınıf ve ardışıl diyagramlar, ER diyagramı), gerçekleştirme ve test, çalışan uygulamanın gösterimi.
  - Sunulan sistemler: salgın döneminde restoran müşteri takip sistemi, Kızılay için bağış takip bilgi sistemi, kripto para madenciliği izleme uygulaması, okul servisi yönetim sistemi, salgın önlemli maç bileti satış sistemi, üniversite kampüs bilgi sistemi ve hastane bilgi sistemi.
- Fizibilite çalışmasının biçimleri
  - Alternatif sistemlerin (işletim sistemi, programlama dili, geliştirme ortamı, veri tabanı) avantaj ve dezavantajlarıyla karşılaştırıldığı teknik fizibilite tabloları (ekrandan, 00:45:00).
  - Teknik, ekonomik, sosyal, yasal ve zaman fizibilitesine ağırlık verilerek puanlanan fizibilite matrisi; en yüksek puanlı alternatif seçilir.
  - Ekonomik fizibilitede toplam yatırım maliyeti, beklenen gelir, net bugünkü değer, iç verim oranı, başa baş noktası ve geri ödeme süresi.
  - Yasal fizibilitede kişisel verilerin korunması kanunu ve yazılım lisansları.
  - Zaman fizibilitesinde her aşama için en iyi ve en kötü gün tahminlerinden ortalama süre çıkarılıp Gantt diyagramı kurulması.
- Analiz modelleri
  - Düzeyli veri akış diyagramları: bağlam (taslak) diyagramı, birinci düzey (işlemler, veri depoları, dış varlıklar), ikinci düzey (bir işlemin alt işlemlere açılması) (ekrandan, 00:20:00; 01:05:00; 01:35:00).
  - Veri sözlüğü girişleri: veri akışı, veri deposu, veri yapısı ve veri elemanı girişleri (ekrandan, 00:50:00).
  - Kullanım senaryosu diyagramı ve her kullanım durumunun metin senaryosu.
- Tasarım modelleri
  - Yapı diyagramı, kavramsal ve tasarım sınıf diyagramları, ardışıl (sequence) diyagram (ekrandan, 01:20:00), ER diyagramı ve tablo yapısı.
- Hocanın geri bildirimleri ve dönemin toparlanması
  - Kullanım senaryosu diyagramında ortak bir ön koşul (giriş yapma) hiyerarşik elipslerle değil, `include` ilişkisiyle gösterilir.
  - Kullanıcının parasını harcatan işlemlerde onay adımı konmalı; harici kaynaktan gelmesi gereken veri (yemekhane menüsü gibi) elle değil kaynağından çekilmeli.
  - Ders, algoritma ve fonksiyon ölçeğinden modül, alt sistem ve dış sistemlerle haberleşen büyük ölçekli bilgi sistemlerine geçişi; fonksiyonel (yapısal) ve nesneye yönelik çözümlemenin temellerini tanıtıcı düzeyde verdi. Çevik süreçlerdeki kullanıcı hikâyeleri ve sprint planlaması bu temellerin üzerine kurulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanım senaryosu diyagramında ilişkiler
  - Birçok kullanım durumu girişi gerektiriyorsa giriş kullanım durumu `include` ile bağlanır; diyagram, bütün senaryolar girişten türemiş gibi hiyerarşik çizilmez (00:40:38).
- Kullanıcı arayüzünde güvenli tasarım
  - Bakiyeden para düşen "üye ol" gibi işlemlerde "Emin misiniz?" onayı olmalıdır; aksi halde her tıklamada para gider (01:21:39).
- Dış kaynaklarla bütünleşme
  - Kampüs uygulamasındaki yemekhane menüsü elle girilmek yerine yayımlandığı sayfadan çekilmeliydi (01:22:59).
- Sunumun amacı
  - Sunum raporun satır satır okunması değildir; ayrıntı raporda kalır, sunumda süreç ve temel özellikler anlatılır.
- Dersin kapsamı
  - Büyük ölçekli problemler doğrudan kod yazarak çözülemez: önce problem çözümlenir, çözüm tasarımlarla ifade edilir, ancak sonra gerçeklemeye geçilir.

## Kısa Tekrar Notları

- Sistem geliştirme aşamaları: ön inceleme, analiz, tasarım, gerçekleştirme, test.
- Fizibilite türleri: teknik, ekonomik, sosyal, yasal, zaman (bazı gruplarda yönetim fizibilitesi de).
- Fizibilite matrisi: alternatifler ağırlıklı ölçütlerle puanlanır, en yüksek puanlı seçilir.
- Ekonomik fizibilite araçları: yatırım maliyeti, net bugünkü değer, iç verim oranı, başa baş noktası, geri ödeme süresi.
- Veri akış diyagramı düzeyleri: bağlam diyagramı tek işlem; birinci düzey ana işlemler ve veri depoları; ikinci düzey bir işlemin alt işlemleri (ör. 2.1, 2.2).
- Veri akış oklarında veri adları yazılır ("Randevu talebi", "Aşı bilgisi").
- Veri sözlüğü girişi: ad, tanım, veri elemanları, açıklama.
- Kullanım senaryosunda ortak adım `include` ile gösterilir.
- Ardışıl diyagramda koşullu mesaj köşeli parantezli bekçi (guard) koşuluyla yazılır.
- ER/tablo tasarımında eşsiz bir anahtar (TC kimlik numarası, otomatik artan bağış numarası) birincil anahtar seçilir; alt türler ayrı tablolarda yabancı anahtarla bağlanır.
- Test iki katmanlı yapılabilir: önce ekip, sonra müşteri rolündeki kişi.
- Müşterinin sonradan gelen isteği (ör. aşı birimi) yeni bir modül olarak sisteme eklenir.

## Detaylı Açıklamalar

- Restoran müşteri takip sistemi
  - Grup, salgında iç mekânlardan restoranların takibinin en zor olduğunu (birbirini tanımayan müşteriler, yemek sırasında maske takılamaması, mesafenin işletmeye kalması) gerekçe olarak sundu; aerosol ve damlacık yayılımını gösteren bir slayt kullandı (ekrandan, 00:05:00).
  - Çözüm: restoranların müşterilerini kaydedip izleyebileceği ve müşterilerin hangi restoranlarda bulunduğunu görebileceği bir web sistemi. Üst yönetim için üç aktör (yönetici, müşteri izleyen kişi, çalışan) ve role göre erişim tanımlandı; yönetici her yere erişir, çalışan yalnız ana sayfayı görür.
  - İki teknoloji yığını araştırıldı: MongoDB-Express-React-Node ve Spring tabanlı Java. Yönetim bölümü Spring ile yazıldı; giriş sayfası ve Hibernate sorguları geliştirme ortamında gösterildi (ekrandan, 00:10:00). Müşteri tarafında harita üzerinde restoranlar, HES kodu ile kayıt ve değerlendirme bırakma vardı.
- Kızılay bağış takip bilgi sistemi
  - Amaç: Türkiye'nin her yerinden yapılan bağışların kayıt altına alınması ve takibi için Kızılay çalışanlarına yönelik bir sistem (ekrandan, 00:15:00). Kan, ayni ve nakdi bağışlar ile kanın hangi şehirde, hangi hastanede olduğunun takibi istendi.
  - Zaman fizibilitesi: her üye her aşama için en çok ve en az gün tahmini verdi, ortalamayla 33 günlük Gantt planı çıktı. Fizibilite matrisinde üç alternatif teknik, sosyal, ekonomik ve zaman ağırlıklarıyla puanlandı; ücretsiz PostgreSQL kullanan üçüncü alternatif seçildi.
  - Birinci düzey veri akış diyagramında 11 işlem ve D1-D7 veri depoları vardı (ekrandan, 00:20:00); ikinci düzeyde bağış görüntüleme üç alt görüntülemeye, ayni bağış alma giysi, erzak ve hizmet bağışına açıldı.
  - Veri tabanı: bütün bağışlar tek ve eşsiz bir bağış numarasıyla (otomatik artan sequence) bağışlar tablosunda; bağışçılar TC kimlik numarası birincil anahtarıyla; her bağış türü kendi tablosunda bağış numarasını yabancı anahtar olarak alır.
  - Test: önce ekip, sonra müşteri rolüne giren her üye bütün fonksiyonları denedi (ekrandan, 00:25:00). Gösterimde kan nakli işlemi istenen 4 ünite yerine eldeki 3 üniteyi nakletti (ekrandan, 00:30:00).
- Madencilik izleme uygulaması
  - Müşteri isteği: madencilik sisteminin sıcaklık ve hız değerlerini uzaktan izleyen bir mobil uygulama ve cüzdan bilgisi eklentisi.
  - Fizibilite: yazılım (Python, Android Studio, Flutter, Firebase, Visual Studio Code), donanım, yasal (ücretsiz araçlar, lisanslı işletim sistemi) ve ekonomik fizibilite; çalışan giderleri tablosu (ekrandan, 00:35:00). Proje 38 günde bitti.
  - Ön yüz UML'inde PoolStats, User, MinerStats sınıfları; arka yüz UML'inde main, Miner (IP, ID, port) ve Wallet (Ethermine API) sınıfları. Ardışıl diyagram, kullanıcı verisinin Firebase sunucusu, web sunucusu, veri tabanı, Ethermine sunucusu ve madencilik makinesi arasındaki akışını gösterdi.
  - Eşsiz kullanıcı kimliği sayesinde her kullanıcı yalnız kendi sistemlerini ve cüzdanını görür. Gelir-gider ekranı günlük, haftalık, aylık kazancı gösterdi (ekrandan, 00:40:00).
- Okul servisi yönetim sistemi
  - Problem: büyüyen bir servis firmasında öğrenci, servis, şoför bilgilerinin ve ödemelerin takibinin zorlaşması; çözüm yönetim kademesine hizmet eden bir bilgi sistemi.
  - Teknik fizibilite tablosu iki alternatifi (Windows, C#, Visual Studio, Access ile macOS, Java, MonoDevelop, MySQL) karşılaştırdı ve birinciyi seçti (ekrandan, 00:45:00). Ekonomik fizibilitede birinci senaryo 47.320 TL, ikinci senaryo 49.384 TL; net bugünkü değer, iç verim oranı, başa baş noktası ve geri ödeme süresi hesaplandı.
  - Analiz: firma ile veri toplama ve 10 soruluk anket; yönetici ve öğrenci aktörlü kullanım senaryosu diyagramı ve senaryo metinleri; ER ve veri akış diyagramları; veri sözlüğünde veri akışı, veri deposu, veri yapısı ve veri elemanı girişleri (ekrandan, 00:50:00).
  - Uygulamada şifreler özetlenerek (MD5) saklandı, SQL enjeksiyonuna karşı tırnak karakterleri engellendi; durak bölgesi tablosu gösterildi (ekrandan, 00:55:00).
- Maç bileti satış sistemi
  - Toplantı raporlarında ürün isterleri, görev dağılımı ve şelale (waterfall) modelinin seçimi kayıtlıydı (ekrandan, 01:00:00).
  - Salgın önlemi seçilen maçlarda koltuklar aralarında boşluk kalacak biçimde otomatik dizilir ve kırmızı-yeşil renklendirilir; satışta HES kodu, sistemin tuttuğu doğrulanmış HES kodları tablosuyla karşılaştırılarak simüle edilir.
  - Taslak (bağlam) veri akış diyagramı: Üye ve Yönetim dış varlıkları ile "Maç Bilet Satış Sistemi" arasındaki veri akışları (ekrandan, 01:05:00). ER diyagramında bir maçın birden çok bileti vardır.
- Üniversite kampüs bilgi sistemi
  - Modüller: üyelik ve hesap (kart bakiyesi yükleme), kulüp (kayıt, ayrılma, yıllık ücret), kütüphane (katalog arama, kitap ayırma), bilgi (ring ve yemekhane).
  - Alternatif olmadığından fizibilite matrisi kurulmadı; yasal fizibilite kişisel verilerin korunması kanunu kapsamında incelendi, sosyal fizibilite için kapalı uçlu anket yapıldı.
  - Kulüp modülünün ardışıl diyagramında koşullu bakiye güncelleme mesajı vardır (ekrandan, 01:20:00). Uygulama Django ile yazıldı; kimlik doğrulama, yönetim paneli ve şifre özetleme çatıdan alındı (ekrandan, 01:25:00).
- Hastane bilgi sistemi
  - Üç müşteri görüşmesi: sistem isteği, teslim ve sonradan istenen aşı birimi (iki doz, ikinci doz birinciden 14 gün sonra) için ek modül.
  - Fizibilite: teknik (Java, PostgreSQL), sosyal, yönetim, yasal (ekrandan, 01:30:00), ekonomik; Gantt'a göre 1 Nisan - 11 Mayıs, yaklaşık 40 gün.
  - Birinci düzey veri akış diyagramında beş modül; ikinci düzeyde randevu (2.1 talep alma, 2.2 talep uygunluk kontrolü), muayene (4.1, 4.2) ve aşı (5.1, 5.2) alt işlemleri (ekrandan, 01:35:00).
  - Konsol uygulamasında aynı çalışana aynı saate ikinci randevu talebi "uygun değil" diye reddedildi (ekrandan, 01:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
