# Ders 6 Çalışma Özeti

## Genel Konular

- Bilgisayarın tarihçesi
  - Hesaplama cihazları abaküsle başlar; slayta göre bilinen en eski abaküs M.Ö. 300 yılında Babilliler tarafından kullanılmıştır (ekrandan, 00:10:00).
  - Charles Babbage'ın mekanik tasarımları (Difference Engine, Analytical Engine): çarklar ve millerden oluşur, delikli kartlarla veri alır, buhar makineleriyle çalışır. Saklama (depolama) ve hesaplama olmak üzere iki ana parçası vardır; bunlar bugünkü bellek birimine ve merkezi işlem birimine karşılık gelir.
  - Ada Byron (Lovelace) bu makine için program yazan ve tarihe ilk programcı olarak geçen kişidir.
  - İlk elektronik bilgisayar: Atanasoff ve Berry'nin ABC computer'ı; 1939'da ilk prototip, 1941'de Iowa State Üniversitesi fizik binasının bodrumunda ilk üretim. İkincisi Newmann ve Flowers'ın Colossus Mark I'idir (1943) (ekrandan, 00:15:00).
  - Bu bilgisayarlar büyük ölçüde askeri ihtiyaçlarla (şifreli mesajları çözme, atış hesapları) gelişti.
  - İlk genel amaçlı bilgisayar ENIAC: 1946, U. Penn., ABD ordusu için; J. Presper Eckert ve John Mauchly; 30 ton, 167 m², 500.000 dolar maliyet; matematiksel hesaplar, hava tahmini, atomik enerji hesapları; veri girişi delikli kartlarla, programlama kablolar ve anahtarlar elle değiştirilerek yapılır; ondalık (decimal) veriyle çalışır (ekrandan, 00:20:00). Aynı anda yalnız bir program çalıştırabilir.
- Mainframe'ler
  - 1950'lerin sonu ile 1970'ler arasında çeşitli üreticiler üretti; IBM 700/7000 ve 360 serileriyle öne çıktı; 1980'lerde mini bilgisayarlar etkinleşti; NASA son mainframe'ini 2012'de kapattı; IBM üretime devam ediyor, son sürüm IBM z15 (ekrandan, 00:25:00).
  - Saniyede çok yüksek sayıda işlem (transaction) yapabilen, bankacılık ve finans gibi yoğun işlemli alanlarda kullanılan, çalışırken parça takılıp çıkarılabilen (hot swap), güvenliği yüksek ve hata riski düşük sistemlerdir.
  - Eski mainframe (IBM 7094) geniş klimalı odaları doldururken bugünkü IBM z13 bir rack kabinine sığar (ekrandan, 00:30:00).
- Kişisel bilgisayarlar ve mobil cihazlar
  - Olivetti Programma 101 (1965): gelişmiş bir masaüstü hesap makinesi, ama üzerinde program saklayabildiği için (stored program) kişisel bilgisayar tarihinin kilometre taşlarından biri.
  - Apple I (1976, Wozniak ve Jobs), 1980'lerde Commodore, Amstrad gibi ev bilgisayarları, 1990'larda masaüstü PC'ler ve internet, 2000'lerden sonra dizüstü, tablet, akıllı telefon ve giyilebilir cihazlar.
- Süper bilgisayarlar, paralel hesaplama ve sanallaştırma
  - Süper bilgisayar: karmaşık problemlerin birden fazla makinede eş zamanlı (paralel) çözülmesini sağlayan bilgisayar kümeleri (ekrandan, 00:35:00).
  - İşlemciler çoğu zaman düşük oranda kullanıldığı için tek fiziksel makinede birden çok sanal bilgisayar çalıştırma fikri, yani sanallaştırma (virtualization) doğdu.
- Bilgisayar ve gömülü sistem
  - Belirli ve sınırlı görevler için tasarlanan elektronik cihazlara gömülü sistem, çok sayıda farklı işi yapabilenlere bilgisayar denir. Akıllı telefon gömülü sistem olarak başlayıp bilgisayara yakın bir kapasiteye ulaştı.
- Von Neumann mimarisi
  - Giriş birimi, çıkış birimi, bellek birimi ve merkezi işlem birimi (CPU). CPU içinde kontrol birimi (Control Unit) ve aritmetik-lojik birim (ALU) vardır (ekrandan, 00:45:00).
  - Program ve veri aynı belleği paylaşır; giriş/çıkış, bellek ve aritmetik birim CPU tarafından yönetilir; ikili (binary) veriyle çalışır.
  - Bilgisayarın 0 ve 1 kullanmasının nedeni elektriğin var ya da yok olmasıdır (örneğin 0 V ve 5 V).
- Bilgisayar organizasyonu: donanım ve yazılım
  - Donanım: bilgisayarın fiziksel bölümü (monitör, klavye, fare, entegreler, kartlar, kablolar). Yazılım: mantıksal bölüm; programlar bilgisayarın gerçekleştireceği komutlardır (ekrandan, 00:50:00).
  - Donanım birimleri: merkezi işlem birimi, ana bellek, ikincil bellek, giriş birimleri, çıkış birimleri (ekrandan, 01:10:00).
  - Katmanlar: fiziksel cihazlar, mikroprogramlama, makine dili (donanım); işletim sistemi (süreç zamanlama, bellek yönetimi, dosya yönetimi, aygıt sürücüleri) ile derleyici, editör, yorumlayıcı, veritabanı (sistem yazılımı); oyunlar, eğitim yazılımları, kütüphane sistemi gibi uygulama yazılımları (ekrandan, 01:35:00).
- Bellek hiyerarşisi ve bellek türleri
  - Piramidin tepesinde inboard memory (register, cache, ana bellek), ortada outboard storage (manyetik disk, CD-ROM, CD-RW, DVD+RW, DVD-RAM), altta off-line storage (manyetik teyp, MO, WORM). Yukarı çıktıkça maliyet ve hız artar, aşağı indikçe kapasite artar (ekrandan, 01:15:00).
  - Ana bellek (RAM): her biri 1 byte'lık, adresi olan hücrelerden oluşur; bu adreslerde veri ya da komut saklanır; bilgiler 0 ve 1'lerden oluşur; elektrik kesilince içerik kaybolur (ekrandan, 01:20:00).
  - ROM: rastgele erişim mümkün, yalnız okuma yapılır, genelde ana kartta bilgisayar açılırken gereken komutları saklar (ekrandan, 01:30:00). EPROM ve EEPROM sınırlı sayıda yeniden yazılabilir; firmware'e benzer.
  - BIOS: işletim sistemi olmadan donanımın temel ayarlarının (örneğin hangi aygıttan boot edileceği) yapılabildiği arayüz.
  - İkincil bellek kalıcıdır: HDD, SSD, CD/DVD, flash bellek, harici diskler; uzun süreli arşiv için teyp. Rastgele ve sıralı erişim farkı.
- Veri kapasite birimleri
  - $2^{10}$ byte = 1024 byte = 1 KB; $2^{20}$ byte = 1 MB; $2^{30}$ byte = 1 GB; $2^{40}$ byte = 1 TB. Sonrası PB, EB, ZB, YB (ekrandan, 01:25:00).
- Analog ve dijital veri
  - Analog veri fiziksel bir ortamda saklanır (kaset gibi); çoğaltmak için yeni malzeme gerekir. Dijital veri sayısal olarak kodlanır; kolayca saklanır, çoğaltılır, dağıtılır ve değiştirilir.
- Programlama dilleri
  - Makine dili (0 ve 1'ler), assembly dilleri (2. nesil; assembler ile asm dosyası obj makine koduna çevrilir), yüksek seviyeli diller (Fortran, Pascal, C, Java, COBOL), nesneye dayalı diller (Java, C++, Python), 4. nesil diller (SQL) (ekrandan, 01:40:00; 01:45:00).
  - Derleyici (compiler) kaynak kodun tamamını makine koduna çevirir; yorumlayıcı (interpreter) programı satır satır çevirip çalıştırır (ekrandan, 01:50:00).
- Sayı sistemleri (tablet üzerinde)
  - 8 bit 1 byte'tır. Konumsal (positional) sayı sistemleri: ikili, sekizli, onlu, onaltılı. Konumsal olmayan (non-positional) sistem örneği: Roma rakamları (ekrandan, 02:10:00).
  - $(01000011)_2 = 67$; 1 byte ile işaretsiz 0-255, işaretli -128 ile 127 arası, toplam $2^8 = 256$ farklı değer saklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- 1 KB = 1024 byte'tır, 1000 byte değildir
  - Hoca slayttaki tabloda "1,000" yazan değerlerin yanlış olduğunu, ikinin kuvvetleri kullanıldığı için 1024 olması gerektiğini söyleyerek düzeltti.
- Bilgisayar mühendisi donanımı da bilmelidir
  - Ana kart, slot, takılabilecek kartlar gibi donanım bilgisi bilgisayar mühendisini yazılım mühendisinden ve programcıdan ayırır.
- "Cache" yazımı
  - Ön bellek "cache" diye yazılır; "cash" (para) ile karıştırılmamalıdır.
- Von Neumann mimarisinin temel birimleri
  - Bugünkü mimariler bu birimlerin üzerine kuruludur; birimlerden biri eksikse bilgisayar çalışamaz.
- C dilinin önemi
  - Unix bu dille yazıldı; pointer gibi güçlü bellek yönetimi araçları vardır; gömülü sistemlerde ve performans gereken işlerde mutlaka karşılaşılır. Birçok kaynakta orta seviyeli dil olarak geçer.
- Dil seçimi probleme göre yapılır
  - Algoritma tasarımı önemlidir, ama çok büyük veri, olay güdümlü (event driven) uygulamalar, veri bilimi gibi durumlarda dilin yetenekleri seçimi belirler.
- Java hem derlenen hem yorumlanan bir dildir
  - Hoca, slaytta Java'nın yalnız derleyici ile çalışan diller arasında gösterilmesinin düzeltilmesi gerektiğini söyledi.

## Kısa Tekrar Notları

- Abaküs, Babbage'ın Analytical Engine'i, ilk programcı Ada Byron.
- ABC (1939-1941) ilk elektronik bilgisayar; Colossus Mark I (1943); ENIAC (1946) ilk genel amaçlı bilgisayar.
- Mainframe: yüksek işlem kapasitesi, hot swap, yüksek güvenlik; IBM hâlâ üretiyor.
- Süper bilgisayar: paralel çalışan bilgisayar kümeleri. Sanallaştırma: tek fiziksel makinede birden çok sanal makine.
- Von Neumann: giriş, çıkış, bellek, CPU (kontrol birimi + ALU); program ve veri aynı bellekte.
- Bellek hiyerarşisi: register, cache, ana bellek, ikincil bellek, teyp; yukarı çıktıkça hız ve maliyet artar, kapasite azalır.
- RAM uçucudur, her hücre 1 byte ve adreslidir. ROM açılış komutlarını saklar. BIOS temel donanım ayarlarını sunar.
- 1 bit = 0 ya da 1; 8 bit = 1 byte; 1 KB = $2^{10}$ = 1024 byte.
- Makine dili, assembly, yüksek seviyeli, nesneye dayalı, 4. nesil diller.
- Derleyici kodun tamamını bir seferde çevirir, yorumlayıcı satır satır çevirir.
- $(01000011)_2 = 64 + 2 + 1 = 67$.
- 1 byte: işaretsiz 0-255, işaretli -128..127; her durumda 256 değer.

## Detaylı Açıklamalar

- **Tarihçe ve donanım birimlerinin kökeni.** Bilgisayar bir hesaplama cihazıdır ve kökeni abaküse kadar gider. Yoğun hesaplama ihtiyacı (örneğin logaritma tabloları) Charles Babbage'ı tamamen mekanik bir tasarıma yöneltti. Analytical Engine'in bilgiyi saklayan kısmı ile bu bilgiyi kullanarak hesap yapan çarkları, bugünkü bellek birimi ve CPU kavramlarının atasıdır. Elektriğin kullanımıyla birlikte 1940'larda elektronik bilgisayarlar ortaya çıktı. ENIAC'ı programlamak, bugünkü gibi klavyeyle kod yazmak değil, yüzlerce kablonun yerini ve anahtarların konumunu hesaplayıp elle değiştirmekti. Bu bilgisayarlar aynı anda yalnız bir iş yapabildiği için işler sıraya girerdi.
  > **Ders sonrası not:** Hoca ve slayt ENIAC'ın açılımını "Electronic Numerical Integrator and Calculator" diye verdi; yaygın kabul edilen açılım büyük olasılıkla "Electronic Numerical Integrator and Computer"dır. Hoca alanı yaklaşık 170 m² dedi, slaytta 167 m² yazıyor.
- **Mainframe'den kişisel bilgisayara.** Mainframe'ler bankacılık gibi çok sayıda kullanıcının ve işlemin olduğu alanlarda kullanılan, çalışırken disk ya da modül takılıp çıkarılabilen, çok güvenilir sistemlerdir. Boyutları, maliyetleri ve ürettikleri ısı nedeniyle kişisel kullanıma uygun değildiler. 1970-80'lerde kişisel bilgisayarlar, 1990'larda internetle haberleşen masaüstü PC'ler, 2000'lerden sonra mobil cihazlar yaygınlaştı. Bugün bir telefon, 1990'ların bilgisayarlarından çok daha fazla bellek ve işlem gücü sunuyor; kapasiteler neredeyse her iki yılda bir katlanıyor.
- **Süper bilgisayar ve sanallaştırma.** Süper bilgisayarlar saniyede trilyonlarca işlem yaparak satranç hamlelerini öngörme, şifre kırma, büyük asal sayı hesaplama, hava tahmini ve fizik hesapları gibi işlerde kullanılır. Bilgisayarları yan yana dizmek yer, ısı ve maliyet sorunu yarattı. İşlemcilerin çoğu zaman yüzde 5-10 kadar kullanıldığı görülünce, tek fiziksel makinede yazılımla birden çok sanal sunucu çalıştırma fikri (sanallaştırma) doğdu. Bu, kaynakların daha verimli kullanılmasını ve elektronik atığın azalmasını sağlar.
- **Von Neumann mimarisi ve ikili sistem.** Bir bilgisayarın girdi alabileceği bir birimi, sonucu göstereceği bir çıkış birimi, bilgiyi saklayacağı bir belleği ve bilgiyi işleyecek bir CPU'su olmalıdır. CPU içindeki kontrol birimi hangi komutun hangi sırayla çalışacağını yönetir ve diğer birimlere sinyal gönderir; ALU toplama, çıkarma, çarpma, bölme ve karşılaştırma gibi işlemleri yapar. Bilgisayarlar resim, video, metin, sayı ve komutların hepsini 0 ve 1 olarak saklar; fiziksel düzeyde bu, elektriğin var ya da yok olmasıdır.
- **Bellek hiyerarşisi.** İki sayı toplanacaksa değerler bellekten register'lara getirilir, işlem yapılır, sonuç önce register'a, sonra cache'e ya da ana belleğe yazılır. Ana belleğe erişim işlemcinin hızına göre yavaş kaldığı için araya kademeli cache katmanları (L1, L2, L3) konmuştur. Register kapasitesi en düşük, cache megabaytlar, ana bellek gigabaytlar, diskler terabaytlar mertebesindedir. İşletim sistemi ikincil bellekte durur; bilgisayar açılırken ROM'daki küçük program onu ana belleğe yükler.
  > **Ders sonrası not:** Hoca bir yerde "Hard Disk Drive dediğimiz manyetik tape'ler" dedi; HDD manyetik disktir, manyetik teyp (tape) ayrı bir sıralı erişimli arşiv ortamıdır. Hocanın sonraki anlatımı ve bellek piramidi de bu ayrımı yapar.
- **RAM, SSD ve ROM.** RAM rastgele erişimli olduğu için istenen adrese doğrudan gidilir; sıralı erişimde ise örneğin 100. adrese ulaşmak için önce önceki adreslerden geçmek gerekir. HDD'de dönen plakalar ve hareket eden bir kol vardır; SSD'de mekanik hareket yoktur. HDD daha ucuz ve yüksek kapasitelidir, SSD daha pahalıdır. Hoca SSD hücrelerinin sınırlı sayıda (yaklaşık 10.000-100.000) yazma döngüsüne dayanabildiğinin konuşulduğunu belirtti. ROM ve türevleri (EPROM, EEPROM) açılış komutlarını ve BIOS ayarlarını saklar; bu, cihazlara gelen firmware güncellemelerine benzer.
- **Analog ve dijital.** Kasete kaydedilen müzik analogdur; 100 kopya için 100 fiziksel malzeme gerekir. Dijital müzik sayısal olarak kodlanır, hızla çoğaltılır ve dağıtılır. Hoca, yüz yüze sınıfta sesin hava parçacıklarıyla analog iletildiğini, çevrim içi derste ise görüntü ve sesin dijitale çevrilip gönderildiğini örnek verdi. Görüntülerdeki piksel sayısı ve renk derinliği arttıkça veri boyutu büyüdüğü için bugün petabaytlar konuşuluyor.
- **Programlama dilleri.** Makine kodunda tek bir bitin değişmesi başka bir anlam taşıdığından doğrudan makine diliyle programlamak verimli değildir. Assembly dilleri komutları sözel hale getirir: örneğin `add ax, bx`, ax ve bx register'larındaki sayıları toplar. Her işlemci mimarisinin kendi komut seti olduğu için assembly mimariye özgüdür; assembler bu kodu object code'a çevirir. Assembly'de bir sıralama bile 15-20 satır tutabilir. Yüksek seviyeli dillerde C, Unix'in yazıldığı ve sistem seviyesine yakın bir dil olarak öne çıkar. Nesneye dayalı diller (Java, C++, Python) araba, bina, insan gibi gerçek dünya nesnelerini modellemek, yeniden kullanılabilir ve türetilebilir kod yazmak ve düğmeler ile pencereler üzerinden yürüyen olay güdümlü programlar geliştirmek için ortaya çıktı. 4. nesil diller (örneğin SQL; `select`, `insert`, `update`, `delete`) konuşma diline yakındır; her yeni soyutlama katmanı geliştirmeyi hızlandırır, ama makine dilinden uzaklaştıkça performans düşebilir. <!-- BELİRSİZ: Hoca sonda yapay zekâ için geliştirilmiş özel dillerden ve kutu-daire şekilleriyle çalışan görsel dillerden söz etti; bu dil grubunun adı altyazıda bozuk ("Konstantin Diller"). -->
- **Derleyici ve yorumlayıcı.** Derleyici kodun tamamını inceleyip bir seferde makine diline çevirir; yorumlayıcı komut komut çevirerek çalıştırır. Hocaya göre derlenen diller performans bakımından daha iyidir; yorumlanan diller platformdan bağımsızlık sağlar ve her değişiklikten sonra uzun bir derleme beklemeyi gerektirmez. C derlenen, Python ve MATLAB yorumlanan dillerdir; Java hem derlenir hem yorumlanır.
- **Sayı sistemleri.** Onluk sistemde basamaklar $10^0, 10^1, 10^2$; ikilik sistemde $2^0, 2^1, \dots, 2^7$ ağırlıklıdır. Onaltılık sistemde 9'dan sonra A-F (10-15) gelir ve $(10)_{16} = 16$; sekizlikte 7'den sonra $(10)_8 = 8$ gelir (ekrandan, 02:05:00). $(01000011)_2 = 2^6 + 2^1 + 2^0 = 64 + 2 + 1 = 67$. 8 bitle işaretsiz sistemde 0-255, işaretli sistemde (bir bit işaret için kullanıldığından) -128 ile 127 arası yazılır; her iki durumda $2^8 = 256$ farklı değer vardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
