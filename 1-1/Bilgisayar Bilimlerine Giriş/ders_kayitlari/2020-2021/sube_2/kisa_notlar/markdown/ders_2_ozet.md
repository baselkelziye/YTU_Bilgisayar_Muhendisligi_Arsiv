# Ders 2 Çalışma Özeti

<!-- BELİRSİZ: Bu kayıt slaytsız bir soru-cevap oturumudur; ekranda yalnız kapalı kamera simgesi vardır. Not yalnız altyazıdan yazılmıştır. -->

## Genel Konular

- Bilgisayar mühendisliğinde algoritma kurma yeteneği
  - Hocaya göre bilgisayar mühendisliğindeki en önemli becerilerden biri algoritma kurabilmektir. Tarihçe ve veri yapıları da önemlidir, ama temel beceri budur.
  - Bu beceri pratikle kazanılır: bir problem ortaya atılır, çözümü oluşturulur ve çözüm akış diyagramıyla ifade edilir. Bu, farklı problemlerle tekrar tekrar yapılır.
  - Akış diyagramı, algoritmanın en temel ifade biçimlerinden biri olarak derste ele alınacaktır.
- Gömülü sistemler ve genel amaçlı bilgisayar
  - Gömülü sistemler adanmış (dedicated) işler yapar: bir uçağın uçuş kontrol ya da silah kontrol sistemi, bir buzdolabının kontrol birimi gibi. Bir ya da birkaç işi hep aynı şekilde yapar.
  - PC ise genel amaçlıdır: kamera, ağ bağlantısı ya da farklı yazılımlar eklenerek görüntülü konuşma, veri tabanı sunucusu, hatta daktilo yerine bile kullanılabilir.
  - Gömülü sistemde donanım ve yazılım bileşenleri birlikte çalışır. Donanım hatası yazılım hatası gibi, yazılım hatası donanım hatası gibi görünebilir. Bu yüzden "gömülü yazılım" değil "gömülü sistem" diye bakmak gerekir.
  - Eskiden mikrodenetleyicide hata ayıklarken `printf` ile ekrana yazdırma imkânı yoktu; LED'ler ya da seri port üzerinden PC'ye mesaj kullanılırdı. Bugün JTAG gibi arayüzlerle mikrodenetleyiciye bağlanıp yazılım adım adım izlenebilir.
- Yeniden başlatmanın (reset) anlamı
  - Sürekli çalışan bir sistem durum makinesi (state machine) gibi düşünülebilir: belli adımlar ve koşullara bağlı geçişler vardır.
  - Sistem beklendiği gibi çalışmıyorsa ve hangi durumda olduğu bilinmiyorsa, onu bilinen bir duruma getirmek gerekir. Yeniden başlatma (power cycle) sistemi temiz ve bilinen ilk duruma getirir; ardından sistem izlenip sorunun ne olduğu anlaşılabilir.
  - Ama sürekli yeniden başlatılması gereken bir sistem zaten iyi tasarlanmamıştır.
- Ev internet bağlantısında sorun ayırma (bir öğrencinin sorusu üzerinden)
  - Önce bağlantının türü bilinmelidir: hücresel ağ mı, ADSL mi, fiber mi?
  - Modemin yönetim arayüzüne tarayıcıdan özel ağ adresi (192.168 ile başlayan bir adres) ile bağlanılır; donanım sürümü (V1, V2, ...) kontrol edilir ve gerekiyorsa firmware güncellenir.
  - Modemin konumu önemlidir; Wi-Fi sinyali duvarlardan geçerken zayıflar.
  - Sinyal artırıcı (repeater) Wi-Fi üzerinden bağlıysa, artırıcı ile modem arasındaki bağlantının kalitesi de sorun olabilir; mümkünse kabloya çevrilmelidir.
  - Sorunun ev içi Wi-Fi'de mi yoksa dış bağlantıda mı olduğunu ayırmak için modemin kendi hız testi ya da Ethernet kablosuyla bağlı bir bilgisayardan hız testi yapılır.
- Kablosuz iletişimde frekans
  - Frekans yükseldikçe taşınabilecek bilgi miktarı artar, ama yüksek frekanslı sinyaller duvarlardan zor geçer; çarpar, yansır.
  - Düşük frekanslı telsiz sinyalleri çok uzak mesafelere ulaşabilir, ama taşıdığı veri azdır.
  - Bu yüzden 5 GHz ile bağlanıp duvarlar arkasında sorun yaşanıyorsa 2.4 GHz'e geçmek faydalı olabilir.
- xDSL altyapısı ve trunk hatları
  - VDSL/ADSL'de santrale olan mesafe hızı belirler: birkaç kilometre uzaktaki abone yüksek hızlara çıkamaz, birkaç yüz metre mesafedeki abone çıkabilir.
  - Abonenin telefon kablosunun operatördeki ucu DSLAM denen cihaza bağlanır. Cihazın kalitesi, kablonun kalitesi ve bina içi kablolama hızı etkiler.
  - Santral binlerce aboneye tek tek bağlıdır, ama üst katmana tek bir yüksek kapasiteli trunk hattıyla bağlanır. Trunk kapasitesi abonelerin toplam hızından azdır. Herkes aynı anda kullandığında aboneler kapasite için yarışır; yoğun saatlerde internetin yavaşlamasının bir nedeni budur.
- Programlama dillerinin nesilleri ve C dili
  - Diller nesil nesil gelişmiştir: önce donanım üzerinde doğrudan çalışan alt seviye dil, sonra insan tarafından daha kolay okunabilen (human readable) ikinci, üçüncü, dördüncü, beşinci nesil diller.
  - Bu derste C öğrenilmeyecek, C'ye giriş yapılacak. Önce akış diyagramı çizmek öğrenilecek, sonra C'nin veri tipleri, ifadeleri ve kontrol yapıları görülüp akışta öğrenilenler C'ye uygulanacaktır. Yapılar (structure), dosyalar, işaretçiler, dosya ve fonksiyon işaretçileri sonraki dönemlerde gelir.
  - C riskli bir dildir: derleyici "programcı ne yaptığını biliyor" diye bakar; hatalı ifadelerde bile çoğu zaman hata, hatta uyarı vermez.
  - C birçok işletim sistemi çekirdeğinin yazıldığı dildir, 8 bitlik mikrodenetleyicilerden mainframe'lere kadar her mimaride çalışır ve doğru yazılırsa oldukça taşınabilirdir.
- Kripto para ve blockchain
  - Bitcoin gibi kripto paraları kişisel bilgisayarda üretmek artık verimli değildir. Hesaplama donanım seviyesinde, ASIC'lerle yapılır; PC'de yazılımla hesaplamak yalnız boşa elektrik harcatır.
  - Blockchain kripto paralarla tanındı, ama günlük hayat uygulamaları henüz tam başlamadı.
- Siber güvenliğe başlangıç
  - Siber güvenlik tek bir konu değildir: ağ, işletim sistemi ve veri (veri tabanı) güvenliğini kapsar. Her birinin nasıl çalıştığı bilinmeden güvenliği konuşulamaz.
  - Ağ tarafında önce TCP/IP'nin nasıl çalıştığı, sonra güvenlik duvarı (firewall) ve saldırı tespit sistemleri öğrenilir.
  - Önce temeller, iyi kaynaklardan okunmalıdır.
- Önerilen temel kaynaklar
  - İşletim sistemleri: Silberschatz (Operating System Concepts), Tanenbaum, Stallings.
  - Ağ programlama: Stevens'ın ağ programlama kitabı. Bilgisayar ağları: Tanenbaum (Computer Networks), Stallings (Data and Computer Communications).
- Sanal gerçeklik ve yapay zekâ üzerine görüşler
  - Sanal gerçekliğin bir sonraki adımı, dokunma ve koku gibi duyulara geri bildirim veren etkileşimli sistemlerdir.
  - GPT-3 gibi metin üreten modeller İngilizcede başarılı olsa da her dilin yapısı farklıdır; bir dilde kurulan model başka bir dilde aynı başarıyı göstermeyebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritma kurmak pratikle öğrenilir
  - Çalışma yöntemi: problem ortaya at, çözüm oluştur, akış diyagramıyla ifade et, farklı problemlerle tekrarla.
- Soru sormayı ve sorunu doğru ifade etmeyi öğrenmek
  - Bir teknik sorun sorulurken bağlantı türü, cihaz markası/modeli gibi bilgiler açıkça verilmelidir. "Herhalde" gibi belirsiz ifadeler yardım almayı zorlaştırır.
- Reset bilinen duruma dönüştür
  - Sistemin hangi durumda olduğu bilinmiyorsa bilinen başlangıç durumuna dönülür; ama sürekli reset gerektiren sistem kötü tasarlanmıştır.
- C riskli bir dildir
  - Derleyici hatalı ama geçerli ifadelerde sessiz kalabilir; bu yüzden C'yi öğrenmek dikkat ister.
- Kendi başına başka bir dil öğrenmeye şimdilik girmemek
  - Önce derste öğrenilecek mantık yerleşmeli. Başka bir paradigmayla (ör. nesne yönelimli) başlayanlar C'ye geçince bildiklerini C'ye uydurmaya çalışıp zorlanabilir.
- Temeller ve İngilizce
  - Siber güvenlik dahil her alanda önce işletim sistemi, ağ ve veri tabanı temelleri gelir.
  - Temel kaynakların neredeyse hepsi İngilizcedir; İngilizceyi okuma, yazma ve konuşma düzeyinde iyi bir seviyeye getirmek gerekir.
- Bilgisayar mühendisliği eğitimi
  - Bölüm belirli bir alt alanın (yapay zekâ, yazılım, gömülü sistem) uzmanını değil, bilgisayar mühendisinin sahip olması gereken temel bilgi ve sistematiğe sahip mühendisi yetiştirir.

## Kısa Tekrar Notları

- Algoritma kurmak bilgisayar mühendisliğinin temel becerisidir; akış diyagramı temel ifade biçimidir.
- Gömülü sistem: adanmış iş, donanım + yazılım birlikte. PC: genel amaçlı.
- Reset (power cycle) sistemi bilinen başlangıç durumuna getirir.
- Yüksek frekans: daha çok veri, duvardan zor geçer. Düşük frekans: uzağa gider, az veri taşır.
- DSL'de santral mesafesi hızı belirler; trunk hattı paylaşıldığı için yoğun saatte hız düşer.
- Sorun ayırma: Wi-Fi mi, dış bağlantı mı? Kabloyla hız testi yap.
- C: işletim sistemi çekirdeklerinin dili, taşınabilir, her mimaride çalışır, derleyici çoğu hatada sessiz kalır.
- Bu derste sıra: akış diyagramı, sonra C'nin veri tipleri, ifadeleri ve kontrol yapıları.
- Kripto para üretimi ASIC'lerle donanım seviyesinde yapılır.
- Siber güvenlik = ağ + işletim sistemi + veri güvenliği; önce temeller.

## Detaylı Açıklamalar

Bu oturum laboratuvar saatinde yapılan bir soru-cevap oturumudur; hoca slayt kullanmamış, öğrencilerin sohbet penceresinden yazdığı sorulara cevap vermiştir. Akademik açıdan en önemli mesaj, bilgisayar mühendisliğinde algoritma kurma becerisinin merkezde olmasıdır. Hoca bu becerinin ancak pratikle kazanılacağını söyler: öğrenci bir problem ortaya atar, çözümünü kurar, çözümü akış diyagramıyla ifade eder ve bunu farklı problemlerle tekrarlar. Derste önce tarihsel gelişim, sonra algoritma kavramı ve akış diyagramları ele alınacaktır.

Gömülü sistemler üzerine soru, adanmış sistem ile genel amaçlı bilgisayar arasındaki farkı açıklamaya fırsat verir. Uçak kontrol sistemleri ya da buzdolabı içindeki kontrol birimi tek bir işi ya da birkaç işi hep aynı biçimde yapar. PC'ye ise farklı donanım ve yazılım ekleyerek onu farklı amaçlarla kullanabiliriz. Gömülü sistemde donanım ve yazılım iç içe olduğundan hata ayıklama zordur; bir hatanın kaynağı donanımda mı yazılımda mı, kolayca anlaşılmaz. Eskiden LED ya da seri port ile durum izlenirken bugün JTAG gibi arayüzlerle kod adım adım izlenebilmektedir.

Yeniden başlatmanın neden işe yaradığı da durum makinesi bakışıyla açıklanır. Sürekli çalışan bir sistem belli adımlar ve koşullu geçişlerle ilerler. Sistem beklenmedik bir durumdaysa ve hangi durumda olduğu bilinmiyorsa, onu bilinen bir duruma getirmek gerekir. Yeniden başlatma bu bilinen durumu sağlar: açılışta her şey temiz bir başlangıç noktasındadır ve sistem buradan izlenebilir. Ancak hoca, sık sık yeniden başlatma gerektiren bir sistemin iyi bir sistem olmadığını ekler.

Bir öğrencinin yavaş internet sorusu, sorun ayırma (troubleshooting) yaklaşımının örneğine dönüşür. Önce bağlantının türü ve cihazın modeli öğrenilir. Modemin yönetim arayüzüne 192.168 ile başlayan özel ağ adresiyle bağlanılır, donanım sürümüne göre firmware güncellemesi kontrol edilir. Modemin konumu, sinyal artırıcının modeme nasıl bağlandığı ve kullanılan Wi-Fi bandı incelenir. Yüksek frekanslı sinyal daha çok veri taşır ama duvarlardan zor geçer; düşük frekanslı sinyal ise uzaklara gider ama az veri taşır. Son adım, sorunun ev içi kablosuz bağlantıda mı yoksa dış bağlantıda mı olduğunu ayırmaktır: modemin kendi hız testi ya da Ethernet kablosuyla bağlı bir bilgisayardan yapılan hız testi bunu gösterir.

DSL altyapısında abonenin telefon hattı operatör tarafında DSLAM'e bağlanır. Santrale olan mesafe, kablonun ve cihazın kalitesi hızı belirler. Santral her aboneye ayrı hatla bağlıdır, ama dünyanın geri kalanına tek bir yüksek kapasiteli trunk hattıyla çıkar. Bu hattın kapasitesi abonelerin toplam hızından azdır. Kimse kullanmazken abone neredeyse kendisine tanımlı hızın tamamını alır; çok sayıda abone aynı anda kullanmaya başladığında ise kapasite için yarışılır. Yoğun saatlerde internetin yavaşlamasının bir nedeni budur.

Programlama dilleri konusunda hoca, dillerin nesiller halinde geliştiğini, her yeni neslin dili insan için daha anlaşılır hale getirmeye çalıştığını söyler; ayrıntı tarihçe dersinde ele alınacaktır. C ile ilgili olarak bu dönem yalnız C'ye giriş yapılacağını belirtir. C, derleyicinin programcıya güvendiği bir dildir: hatalı ama sözdizimi geçerli ifadelerde derleyici çoğu zaman hata vermez, bazen uyarı bile vermez. Öte yandan C işletim sistemi çekirdeklerinin dilidir, 8 bitlik mikrodenetleyicilerden mainframe'lere kadar çalışır ve doğru yazıldığında farklı işletim sistemleri arasında az değişiklikle taşınabilir. Dersin sırası önce akış diyagramı, sonra C'nin veri tipleri, ifadeleri ve kontrol yapılarıdır.

> **Ders sonrası not:** Hoca C'yi "fonksiyonel dil" diye andı. Programlama paradigmaları açısından C prosedürel (yapısal) bir dildir; "fonksiyonel programlama" Haskell gibi dillerin ayrı bir paradigmasıdır. Hoca büyük olasılıkla "fonksiyonlarla yazılan prosedürel dil" anlamında kullandı.

Kripto para sorusunda hoca, bugün Bitcoin gibi paraların kişisel bilgisayarda üretilmesinin anlamlı olmadığını, hesaplamanın ASIC denen özel donanımlarla yapıldığını açıklar. Siber güvenlik sorusunda ise alanın ağ, işletim sistemi ve veri güvenliğinden oluştuğunu, her birinin önce nasıl çalıştığının öğrenilmesi gerektiğini vurgular ve temel kaynak olarak işletim sistemleri ile ağ kitaplarını önerir.

> **Ders sonrası not:** Hoca DSLAM'i "Digital Line Subscriber" diye açtı; doğrusu Digital Subscriber Line Access Multiplexer'dır. ASIC'i "Application Specific Integrated Software" diye açtı; doğrusu Application Specific Integrated Circuit'tir. GPT'nin açılımı Generative Pre-trained Transformer'dır. Hocanın 192.168 adresleri için kullandığı "sanal IP" ifadesinin yerleşik karşılığı "özel (private) IP adresi"dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
