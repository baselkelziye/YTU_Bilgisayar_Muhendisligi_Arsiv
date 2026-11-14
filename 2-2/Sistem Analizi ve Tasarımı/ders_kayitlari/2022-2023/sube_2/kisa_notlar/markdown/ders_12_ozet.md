# Ders 12 Çalışma Özeti

## Genel Konular

- Bu ders tamamen dönem projesi sunumlarıyla geçti. Hoca yeni konu anlatmadı.
- Sunulan projeler
  - Restoran bilgi sistemi (Python, waterfall modeli, veri akış diyagramları).
  - Lastik oteli sistemi (Java, MySQL, nesne yönelik tasarım).
  - Sinema otomasyonu (Python, Django, SQLite).
  - Fitness center otomasyonu (Java, NetBeans, MySQL).
  - Pet shop bilgi sistemi (Java, MySQL, PDF fatura).
  - Otel otomasyonu (Java, MySQL, istatistik grafikleri).
  - Araç kiralama uygulaması (Flutter/Dart).
  - Spor salonu ağı (Java Spring Boot, React, MySQL).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanım senaryolarında cümleleri etken ve özneli yazın.
  - "Ödeme alınır" yerine "Çalışan ödemeyi alır" yazın.
  - Amaç, işi kimin yaptığını açıkça göstermek.
- Senaryodaki birinci aktör ile diyagramdaki aktör tutarlı olmalı.
  - Bir grupta diyagramda "müşteri", senaryoda "çalışan" yazıyordu. Hoca bunu sordu.
- Nesne yönelik yazdıysanız veri akış diyagramı ve yapı diyagramı kullanmayın.
  - Nesne yönelik yaklaşımda kullanım durumu (use case), sınıf ve ardışıl (sequence) diyagramları kullanılır.
  - Nesne yönelik yazılmadıysa use case ve kavramsal sınıf diyagramına gerek yoktur.
  - Veri akış ve yapı diyagramı yapısal (fonksiyonel) yaklaşımın araçlarıdır.
- Ardışıl diyagram sayısı en az kullanım senaryosu sayısı kadar olmalı.
  - Her senaryo bir akış, yani bir sorumluluktur. Her senaryo en az bir ardışıl diyagram üretir.
  - Alternatif akışlar için ayrı ardışıl diyagram gerekebilir.
  - Bir grupta 10 senaryo vardı ama tasarımda yalnız 6 sorumluluk gösterilmişti. Bir başka grupta bütün senaryolar tek ardışıl diyagramda toplanmıştı.
- Sınıfları ekranlara (UI) göre bölmeyin.
  - Nesne yönelik çözümleme kavramları modeller: yönetici, salon, seans, ders gibi.
  - Bir grupta sınıflar "yönetici main UI", "yönetici personel UI" gibi ekranlara göre bölünmüştü. Bu işlevsel çözümlemedir.
  - İş katmanı ile sunum katmanı ayrılmalı. Arayüzde iş kodu olmamalı.
- Analiz ve tasarım sınıf diyagramlarını ayrı tutun.
  - Önce yalnız kavram sınıflarından oluşan kavramsal diyagram çizilir.
  - Sonra davranışlar eklenir ve gerçek yazılım sınıflarından oluşan tasarım diyagramı çizilir.
- Raporda veri tabanı tasarımı ve görev dağılımı da yer almalı. Sunumda da gösterilmeli.
- Hata mesajı kullanıcıya yol göstermeli.
  - "Stoktan fazla girildi" yerine "Stokta 40 tane var" demek daha iyi.

## Kısa Tekrar Notları

- Dönem projesi aşamaları: ön inceleme, fizibilite, gereksinim analizi, sistem analizi, sistem tasarımı, gerçekleştirme, test, müşteri değerlendirmesi.
- Fizibilite türleri: teknik, ekonomik, zaman, sosyal (operasyonel), yönetim, yasal.
- Fizibilite matrisi: alternatif sistemleri fizibilite türlerine göre ağırlıklı puanlar ve en yüksek puanlıyı seçer.
- Yasal fizibilitede kişisel veri işleyen her sistem 6698 sayılı KVKK'ya uymalı.
- Zaman planı için Gantt şeması kullanılır.
- Kullanım senaryosu bileşenleri: birinci aktör, beklentiler, ön koşul, son koşul, ana akış, alternatif akış.
- Yapısal yaklaşım: veri akış diyagramı (taslak, 1. düzey, 2. düzey), veri sözlüğü, yapı diyagramı.
- Nesne yönelik yaklaşım: use case diyagramı, kavramsal sınıf diyagramı, tasarım sınıf diyagramı, ardışıl diyagram.
- Veri tabanı tasarımı: varlık-ilişki (ER) diyagramı.
- Ardışıl diyagram sayısı $\geq$ kullanım senaryosu sayısı.

## Detaylı Açıklamalar

Bu derste öğrenci grupları dönem projelerini sundu. Aşağıda örnek projelerin kullandığı yaklaşımlar özetlendi. Hocanın geri bildirimleri yukarıdaki vurgular bölümündedir.

### Restoran bilgi sistemi

- Problem: Var olan bir makarna restoranında müşteri sayısı arttı. Elle yürütülen sipariş takibi zaman ve iş yükü bakımından pahalı.
- Fizibilite
  - Teknik: Python, nesneye dayalı yaklaşım, Python arayüz kütüphaneleri.
  - Ekonomik: Toplam gider yaklaşık 35 bin dolar olarak tahmin edildi.
  - Zaman: Waterfall modeli ve Google Spreadsheet ile hazırlanan Gantt şeması.
  - Yasal: İsim girmek zorunlu değil. Girilirse veri KVKK kapsamında korunur.
- Gereksinim analizi
  - İki kritik gereksinim bulundu: kullanıcı dostu arayüz ve raporlanabilirlik.
  - Veri müşteri, çalışan ve yönetici anketlerinden toplandı. Çalışan anketinde kıdeme göre ağırlık katsayısı kullanıldı.
- Demo: Her masaya bir çalışan bakıyor, 8 çalışan ve 8 masa var. Veri tabanında her gün için ayrı tablo tutuluyor. Yönetim ekranı aylık müşteri sayısı ve gelir grafiği çiziyor.

### Lastik oteli

- Problem: Lastikleri belli süre saklayan bir işletmenin lastik sayısı arttı. Stok ve emanet takibi elle yapılamıyor.
- Ekonomik fizibilite
  - Saatlik ücret 150 TL, toplam çalışma 520 saat.
  - Gider $520 \times 150 = 78\,000$ TL. Satış fiyatı 120 bin TL olarak belirlendi.
- Fizibilite matrisi: Üç öneriden ikincisi 89 puanla seçildi.
- Sınıflar: Soyut `Person`, ondan türeyen `Customer` ve `Manager`. Ayrıca `Tire`, `Warehouse`, `Operations` ve `Report` sınıfları var.

### Sinema otomasyonu

- Teknik: Python, Django, SQLite, VS Code. Üç framework fizibilite matrisiyle karşılaştırıldı.
- Ekonomik: Bütçe 4000 dolar. Grup kendini "yeni girişim" olarak tanımladı.
- Demo: Bilet alma işlemi 5 dakika içinde tamamlanmalı (00:56:20). Böylece aynı koltuğu iki kişi alamaz. Satın alma ve iade sonrası e-posta gidiyor.

### Fitness center otomasyonu

- Fizibilite matrisi: Flutter-Firebase, Java-MySQL ve C#-MS SQL karşılaştırıldı. Java-MySQL 66 puanla seçildi.
- Zaman: Analiz 14, tasarım 12, gerçekleştirme 27 gün. Toplam 53 gün.
- Ekonomik: Aylık 1000 TL abonelik ve 50 müşteri varsayımıyla yatırım 3 ayda geri dönüyor.

### Pet shop bilgi sistemi

- Modüller: hayvan, kullanıcı, müşteri, ürün ve fatura panelleri.
- Teknik: Java ve MySQL. Ekonomik gider 123 400 TL, 2,5 ayda geri kazanılması bekleniyor. <!-- BELİRSİZ: Altyazıda tutar "123.400'li" diye bozuk (01:21:12); para birimi doğrulanamadı. -->
- Yasal: KVKK ve Hayvanları Koruma Kanunu dikkate alındı.
- Sahiplendirilen hayvanın ID'si $-1$ ile çarpılarak işaretleniyor.

### Otel otomasyonu

- Beş modül: kayıt, yemek takvimi, etkinlik takvimi, istatistik, oda bakım.
- Teknik: Java ve MySQL. 11 kullanım senaryosu var.
- Oda fiyatı sezona göre değişiyor. Taban fiyat 800 TL, Temmuz başında yaklaşık 2,5 katına çıkıyor.

### Araç kiralama uygulaması

- Teknik: Dart tabanlı Flutter. Tek kodla Android, iOS ve web.
- Üç sistemin maliyeti karşılaştırıldı: 229 643 TL, 264 500 TL ve 281 500 TL. İkinci sistem seçildi. <!-- BELİRSİZ: Seçim cümlesi altyazıda yarım kalıyor (01:52:49); "ikinci sistem" doğrulanamadı. -->
- Sınıflar: `Car`, `User`, `Main`, `Rent`. Veriler sunucu yerine yerelde tutuluyor.

### Spor salonu ağı

- Teknik: Java Spring Boot, React, MySQL.
- Gelir modeli: önce ücretsiz, kullanıcı sayısı artınca sponsorluk, hizmet bedeli ve reklam. Başa baş noktası 12. ay.

### Ders sonrası notlar

- Altyazıdaki "Gant şaması" Gantt şemasıdır. Henry Gantt'ın adını taşır.
- Altyazıdaki "zaman fisi piltesi" zaman fizibilitesidir.
- Bir grupta bir öğrenci "UML genel bir tanım, yapı diyagramı onun içinde" dedi (00:53:03). Bu doğru değil. Yapı diyagramı (structure chart) yapısal tasarımın aracıdır, UML diyagramlarından biri değildir.
- Bir grup Django ile web uygulaması yazdı. Django modelleri Python sınıflarıdır. Yine de hoca bu projede nesne yönelik çözümleme yapılmadığını düşündü.
- Lastik oteli maliyeti: $520 \text{ saat} \times 150 \text{ TL/saat} = 78\,000$ TL. Hesap doğru.
- Bir grupta her masaya bir çalışan ve bir bilgisayar düşüyordu. Bu, eşzamanlı sipariş sorununu çözmez, sadece donanım maliyetini artırır. Çok kullanıcılı sistemde ortak veri tabanı ve eşzamanlılık kontrolü gerekir.
- Bir grupta React ön yüz CORS hatası verdiği için demo Postman üzerinden backend istekleriyle yapıldı.
- Bazı sunumlarda altyazı gürültülü. Tutarlar altyazıdan alındı, kayıtta yanlış duyulmuş olabilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
