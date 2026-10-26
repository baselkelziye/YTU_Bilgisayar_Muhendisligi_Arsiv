# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin tarihi 23 Mayıs 2023 Salı. Ders Zoom üzerinden yapıldı.
  - Bu ders tamamen dönem projesi sunumlarıyla geçti. Hoca yeni konu anlatmadı.
- Sunum düzeni
  - Her grup yaklaşık 15 dakika sunum yaptı. Önce projenin aşamaları, sonra kısa bir demo gösterildi.
  - Bu hafta 8 grup planlanmıştı. Raporunu link olarak gönderen B grubu da sonradan sıraya alındı.
  - Sonraki hafta (ders 13) 6 grup sunum yapacak.
- Sunulan projeler
  - Restoran bilgi sistemi (Python, waterfall modeli, veri akış diyagramları).
  - K grubu: Lastik oteli sistemi (Java, MySQL, nesne yönelik tasarım).
  - F grubu: Sinema otomasyonu (Python, Django, SQLite).
  - B grubu: Fitness center otomasyonu (Java, NetBeans, MySQL).
  - A grubu: Pet shop bilgi sistemi (Java, MySQL, PDF fatura).
  - C grubu: Otel otomasyonu (Java, MySQL, istatistik grafikleri).
  - Ü grubu: Araç kiralama uygulaması (Flutter/Dart).
  - N grubu: Spor salonu ağı (Java Spring Boot, React, MySQL). Frontend çalışmadığı için Postman ile gösterildi.
- Duyuru
  - Telafi sınavı 30 Mayıs 2023 Salı, 12:00-13:00 arasında, dersten hemen önceki saatte yapılacak.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanım senaryolarında cümleleri etken ve özneli yazın.
  - "Ödeme alınır" yerine "Çalışan ödemeyi alır" yazın.
  - Amaç, işi kimin yaptığını açıkça göstermek.
- Senaryodaki birinci aktör ile diyagramdaki aktör tutarlı olmalı.
  - Restoran grubunda diyagramda "müşteri", senaryoda "çalışan" yazıyordu. Hoca bunu sordu.
- Nesne yönelik yazdıysanız veri akış diyagramı ve yapı diyagramı kullanmayın.
  - Nesne yönelik yaklaşımda kullanım durumu (use case), sınıf ve ardışıl (sequence) diyagramları kullanılır.
  - Veri akış ve yapı diyagramı yapısal (fonksiyonel) yaklaşımın araçlarıdır.
- Ardışıl diyagram sayısı en az kullanım senaryosu sayısı kadar olmalı.
  - Her senaryo bir akış, yani bir sorumluluktur. Her senaryo en az bir ardışıl diyagram üretir.
  - Alternatif akışlar için ayrı ardışıl diyagram gerekebilir.
  - Lastik oteli grubunda 10 senaryo vardı ama tasarımda yalnız 6 sorumluluk gösterilmişti.
- Sınıfları ekranlara (UI) göre bölmeyin.
  - Nesne yönelik çözümleme kavramları modeller: yönetici, salon, seans, ders gibi.
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

Bu derste öğrenci grupları dönem projelerini sundu. Her sunumdan sonra hoca kısa geri bildirim verdi. Bu geri bildirimler, dersin analiz ve tasarım konularının uygulamadaki karşılığını gösteriyor. Aşağıda grupların kullandığı yaklaşımlar ve hocanın düzeltmeleri özetlendi.

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
- Hocanın soruları
  - Diyagramda aktör "müşteri", senaryoda "çalışan" yazıyor. Grup arayüzü çalışanın kullandığını söyledi.
  - Kodda sınıf var, analizde veri akış diyagramı var. Grup yalnız menü kısmında sınıf kullandığını söyledi.
  - Görev dağılımı raporda vardı ama sunumda yoktu. Hoca sunumda da olmasını istedi.
- Demo: Her masaya bir çalışan bakıyor, 8 çalışan ve 8 masa var. Veri tabanında her gün için ayrı tablo tutuluyor. Yönetim ekranı aylık müşteri sayısı ve gelir grafiği çiziyor.

### Lastik oteli (K grubu)

- Problem: Lastikleri belli süre saklayan bir işletmenin lastik sayısı arttı. Stok ve emanet takibi elle yapılamıyor.
- Ekonomik fizibilite
  - Saatlik ücret 150 TL, toplam çalışma 520 saat.
  - Gider $520 \times 150 = 78\,000$ TL. Satış fiyatı 120 bin TL olarak belirlendi.
- Fizibilite matrisi: Üç öneriden ikincisi 89 puanla seçildi.
- Sınıflar: Soyut `Person`, ondan türeyen `Customer` ve `Manager`. Ayrıca `Tire`, `Warehouse`, `Operations` ve `Report` sınıfları var.
- Hocanın geri bildirimi
  - Analizde 10 senaryo var, tasarımda yalnız 6 sorumluluk gösterilmiş.
  - Senaryolar ya fazla bölünmüş ya da tasarımda karşılıksız kalmış.
  - Raporda veri tabanı tasarımı yok.

### Sinema otomasyonu (F grubu)

- Teknik: Python, Django, SQLite, VS Code. Üç framework fizibilite matrisiyle karşılaştırıldı.
- Ekonomik: Bütçe 4000 dolar. Grup kendini "yeni girişim" olarak tanımladı.
- Hoca, Python ile nesne yönelik yazılmadıysa use case ve kavramsal sınıf diyagramına gerek olmadığını söyledi.
- Demo: Bilet alırken koltuk seçimi 5 dakikada tamamlanmalı. Böylece aynı koltuğu iki kişi alamaz. Satın alma ve iade sonrası e-posta gidiyor.

### Fitness center otomasyonu (B grubu)

- Fizibilite matrisi: Flutter-Firebase, Java-MySQL ve C#-MS SQL karşılaştırıldı. Java-MySQL 66 puanla seçildi.
- Zaman: Analiz 14, tasarım 12, gerçekleştirme 27 gün. Toplam 53 gün.
- Ekonomik: Aylık 1000 TL abonelik ve 50 müşteri varsayımıyla yatırım 3 ayda geri dönüyor.
- Hocanın geri bildirimi
  - Sınıflar "yönetici main UI", "yönetici personel UI" gibi ekranlara göre bölünmüş. Bu işlevsel çözümlemedir.
  - Nesne yönelik çözümlemede kavramlar modellenir. İş katmanı ile sunum katmanı ayrılmalı.

### Pet shop bilgi sistemi (A grubu)

- Modüller: hayvan, kullanıcı, müşteri, ürün ve fatura panelleri.
- Teknik: Java ve MySQL. Ekonomik gider 123 400 TL, 2,5 ayda geri kazanılması bekleniyor.
- Yasal: KVKK ve Hayvanları Koruma Kanunu dikkate alındı.
- Sahiplendirilen hayvanın ID'si $-1$ ile çarpılarak işaretleniyor.
- Hocanın geri bildirimi: Stoktan fazla satış denendiğinde hata mesajı mevcut stok miktarını da söylemeli.

### Otel otomasyonu (C grubu)

- Beş modül: kayıt, yemek takvimi, etkinlik takvimi, istatistik, oda bakım.
- Teknik: Java ve MySQL. 11 kullanım senaryosu var.
- Bütün senaryolar tek bir ardışıl diyagramda toplanmış.
- Oda fiyatı sezona göre değişiyor. Taban fiyat 800 TL, Temmuz başında yaklaşık 2,5 katına çıkıyor.
- Hocanın geri bildirimi
  - Nesne yönelik yaptıysanız yapı diyagramına gerek yok.
  - Analiz modeli ile tasarım modelinin sınıf diyagramlarını ayrı tutun.

### Araç kiralama uygulaması (Ü grubu)

- Teknik: Dart tabanlı Flutter. Tek kodla Android, iOS ve web.
- Üç sistemin maliyeti karşılaştırıldı: 229 643 TL, 264 500 TL ve 281 500 TL. İkinci sistem seçildi.
- Sınıflar: `Car`, `User`, `Main`, `Rent`. Veriler sunucu yerine yerelde tutuluyor.

### Spor salonu ağı (N grubu)

- Teknik: Java Spring Boot, React, MySQL.
- Gelir modeli: önce ücretsiz, kullanıcı sayısı artınca sponsorluk, hizmet bedeli ve reklam. Başa baş noktası 12. ay.
- React frontend CORS hatası verdiği için demo Postman üzerinden backend istekleriyle yapıldı.

### Ders sonrası notlar

- Altyazıdaki "Gant şaması" Gantt şemasıdır. Henry Gantt'ın adını taşır.
- Altyazıdaki "zaman fisi piltesi" zaman fizibilitesidir.
- Sinema grubunda bir öğrenci "UML genel bir tanım, yapı diyagramı onun içinde" dedi. Bu doğru değil. Yapı diyagramı (structure chart) yapısal tasarımın aracıdır, UML diyagramlarından biri değildir.
- Sinema grubunda Django ile web uygulaması yazıldı. Django modelleri Python sınıflarıdır. Yine de hoca bu projede nesne yönelik çözümleme yapılmadığını düşündü.
- Lastik oteli maliyeti: $520 \text{ saat} \times 150 \text{ TL/saat} = 78\,000$ TL. Hesap doğru.
- Restoran grubunda her masaya bir çalışan ve bir bilgisayar düşüyor. Bu, eşzamanlı sipariş sorununu çözmez, sadece donanım maliyetini artırır. Çok kullanıcılı sistemde ortak veri tabanı ve eşzamanlılık kontrolü gerekir.
- Bazı sunumlarda altyazı gürültülü. İsimler ve tutarlar altyazıdan alındı, kayıtta yanlış duyulmuş olabilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
