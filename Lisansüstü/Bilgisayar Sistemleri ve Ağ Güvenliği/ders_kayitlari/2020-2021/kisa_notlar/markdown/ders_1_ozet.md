# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı ve kapsamı
  - Ders iki yönlüdür: bir yandan güvenliğin temelleri öğrenilir, öbür yandan sistemler ve ağ protokolleri açısından güvenlik tehdidi oluşturan unsurlar incelenir.
  - Zafiyetler birdenbire ortaya çıkmamıştır. Var olan eksiklikler bulunup kötü amaçla kullanılmış, bundan sonra da bu zafiyetlerden etkilenmemek için neler yapılması gerektiği sorusu doğmuştur.
  - Konu sürekli değiştiği için sabit bir ders kitabı yoktur. Çevrim içi kaynaklar, gerektiğinde güvenlik forumlarındaki yazılar takip edilir.
  - Slaytlar Stanford CS155 (Computer Security) dersinden alınmıştır.
- Bilgisayar güvenliği problemi neden var? (ekrandan, 00:20:00)
  - **Lots of buggy software:** Hata içermeyen yazılım yok denebilir. Hatalar yanlış mantık kurgusundan, API'lerin yanlış kullanılmasından ya da algoritmanın uç durumları ele almamasından doğabilir.
    - Bazı hatalar "zararsızdır": uygulama beklendiği gibi çalışmaz ama başka bir şekilde de çalıştırılamaz.
    - Bazı hatalar ise uygulamanın, tasarlandığından farklı olarak saldırganın istediği şekilde çalışmasını sağlar. Asıl tehlike budur.
  - **Social engineering is very effective:** İnsanların merakına, zevkine, o anki ruh haline hitap eden mesajlarla normalde yapmayacakları bir işi (link tıklamak, form doldurmak, sayfa ziyaret etmek) yapmaları sağlanır.
  - **Money can be made from finding and exploiting vulns:** Son yıllardaki patlamanın temel motivasyonu paradır.
    - Marketplace for exploits: zafiyetten yararlanan exploit'ler açık artırma mantığıyla satılır.
    - Marketplace for owned machines (PPI, pay-per-install): para ödenerek örneğin bin bilgisayara istenen uygulama yükletilir; saldırı sahibi bile bilinmeyen bu makineler üzerinden yapılır.
    - Many methods to profit from owned machines (ekrandan, 00:10:00).
- 2019'da en çok "distinct" zafiyeti olan 10 ürün (ekrandan, 00:10:00)
  - Android 414, Debian Linux 360, Windows Server 2016 357, Windows 10 357, Windows Server 2019 351, Acrobat Reader DC 342, Acrobat DC 342, cPanel 321, Windows 7 250, Windows Server 2008 248.
  - "Distinct" demek, bu zafiyetlerin birbirinin türevi olmadığı, birbirini tetiklemediği anlamına gelir. Her zafiyet bir saldırı vektörüdür (attack vector).
- Örnek olay: Zoom istemcisi (ekrandan, 00:30:00 - 00:50:00)
  - Kullanıcılar mahremiyet bekler, ama üç sorun ortaya çıkmıştır:
    - (1) Problems with crypto (Marczak and Scott-Railton, April 2020): bir kripto kütüphanesini projeye eklemek ve dokümandaki örnekle kullanmak güvenliği sağlamaz; hangi mantıkla ve hangi sırayla kullanılacağını bilmek gerekir.
    - (2) How not to save a user click (J. Leitschuh, July 2019): yerel Zoom web sunucusu `localhost:19421` portunu dinler; zoom.com sayfası tarayıcıya `http://localhost:19421/launch?action=join&confno=[conference number]` isteğini gönderttirir. Araya diyalog girmediği için herhangi bir web sitesi kullanıcıyı haberi olmadan bir konferansa katabilir.
    - (3) Disable MacOS hardened runtime (P. Wardle, April 2020): hardened runtime kod enjeksiyonuna, library hijacking'e ve süreç bellek alanının kurcalanmasına karşı korur. Zoom bununla uyumlu olmadığı için `disable-library-validation:true` ile çalışır; saldırgan libssl'i proxy'leyen zararlı bir kütüphane yerleştirerek kamera ve mikrofona erişir.
- İşletim sistemi erişim denetimi ve referans monitör
  - Sistem çağrısının yapılıp yapılamayacağı kullanıcıya ve yetkilerine bağlıdır (temel erişim denetimi).
  - Referans monitör, işletim sistemine gelen bütün istekleri inceleyen, bilinen bir zafiyeti tetikleyip tetiklemediğine bakan ve isteğin devam edip etmeyeceğine karar veren bağımsız bir mekanizmadır.
  - Unix dosya sisteminde owner, group ve others için okuma, yazma ve çalıştırma izinleri vardır; referans monitör bunun üstüne ikinci, bağımsız bir denetim katmanı ekler.
- Dersin hedefleri ve konu başlıkları (ekrandan, 00:55:00)
  - Zafiyet tekniklerini anlamak (savunma kurabilmek için), güvenlik araçlarının hangi durumda kullanılacağını ve sonuçlarına ne zaman güvenileceğini öğrenmek, güvenli sistem mimarisi kurmak.
  - Part 1, basics (architecting for security): uygulamaların, işletim sisteminin ve eski kodun (legacy code) güvenliği; sandboxing, access control, security testing.
  - Part 2, web security: sağlam web siteleri kurmak, tarayıcı güvenlik modelini anlamak.
  - Ağ güvenliği (network security) de işlenir. Mobil güvenlik bu derste işlenmez.
- Sistemler neden ele geçirilir? (ekrandan, 01:20:00)
  - IP adresi ve bant genişliği çalma: saldırganın amacı rastgele bir İnternet kullanıcısı gibi görünmektir.
    - Spam (ör. Storm botnet). Spamalytics: 1:12M ilaç spam'i satışla, 1:260K tebrik kartı spam'i bulaşmayla sonuçlanır.
    - Denial of service: bir sistemin ağ ya da işlemci açısından bir üst hizmet sınırı vardır; bunu aşan istekle hizmet veremez hâle gelir.
    - Click fraud.
  - Kullanıcı bilgisini çalma: banka bilgileri, e-posta, kurum uzaktan bağlantı bilgileri, oyun hesapları.
    - Silent Banker / man-in-the-browser: kullanıcı ile banka arasına giren saldırgan sayfaya zararlı JavaScript enjekte eder, kullanıcının sayfada yaptığı her şeyin kopyası saldırgana gider. Genel adı man-in-the-middle'dır.
    - Finansal zararlılar (Kaspersky 2017, ekrandan, 01:25:00): keylogger ile banka şifresi kaydeder, spam e-posta ve hacklenmiş sitelerle yayılır, gelecekteki yüklemeler için erişimi korur.
    - FinSpy: iOS, Android ve Windows sürümleri; kişileri, arama geçmişini, konumu, mesajları gönderir.
  - Ransomware (ekrandan, 01:30:00): verileri şifreler, açmak için fidye ister.
    - WannaCry, SMB protokolündeki (port 445) zafiyetle yayılan bir solucandır. 14 Nisan 2017'de EternalBlue zafiyeti ShadowBrokers tarafından yayımlanmış, 12 Mayıs 2017'de solucan tespit edilmiştir (silahlaştırma 3 hafta).
    - Saldırgan bu sürede ağı tanır, yayılır; bu yaklaşım advanced persistent threat (APT) kapsamında değerlendirilir.
  - Sunucu tarafı saldırılar (ekrandan, 01:35:00): veri hırsızlığı (Equifax, Temmuz 2017, yaklaşık 143M kayıt; Apache Struts'taki bilinen RCE zafiyeti), siyasi motivasyon, ziyaret eden kullanıcılara bulaştırma (MPack, iframe ile).
  - Şirketler müşteri verisini nasıl kaybediyor? (PrivacyRights.org 2020, ekrandan, 01:40:00)
- Zafiyet pazarı (ekrandan, 01:45:00)
  - Option 1, bug bounty: Google up to \$31,337; Microsoft up to \$100K; Apple up to \$200K; Stanford up to \$1K; Pwn2Own \$15K.
  - Option 2: Zerodium, iOS için \$2M'a, Android için \$2.5M'a kadar (2019). Müşterileri ağırlıkla Avrupa ve Kuzey Amerika'daki devlet kurumlarıdır.
- Hangi koda güvenebiliriz? Ken Thompson'ın arka kapısı (ekrandan, 01:50:00 - 02:00:00)
  - Login programına, kaynaktan derlesek bile derleyiciye, derleyicinin kaynağını incelesek bile derleyici ikilisine (binary) güvenemeyiz.
  - Sonuç: hiçbir şeye tam güvenilemez, ama bu ilerlemeyi engeller. Çözüm Trusted Computing Base (TCB) yaklaşımıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Güvenlik denemeleri yalnız izole ortamda yapılmalı
  - Bütün denemeler kendi makinedeki sanal makineler ve onların arasındaki sanal ağ üzerinde yapılmalıdır. Ev ya da iş ağından deneme yapmak suçtur ve hukuki sorun doğurur; kayıtlar tutulur.
  - Konular saldırmak için değil, zafiyetleri anlamak, korunma yollarını görmek ve araçları doğru kullanmak için anlatılır.
- Kripto kütüphanesi kullanmak güvenlik için yeterli değildir
  - Doğru kütüphane ve API bilgisi gereklidir ama yeterli değildir; kullanım mantığı ve sırası da bilinmelidir ("gerek ve yeter koşul" benzetmesi).
- Rekabet baskısı güvenlik zafiyeti doğurur
  - Teslim tarihine yetişmek için bazı şeylerden feragat edilir; bu da otomatik olarak zafiyet oluşturur. Zoom örneği bunun canlı bir örneğidir. Pandemiyle kullanıcı sayısı patlayınca Zoom düşük öncelikli bir hedeften yüksek öncelikli bir hedefe dönüşmüştür.
- Kullanıcı onayı ve sosyal mühendislik
  - Uyumlu olmayan uygulama kararı kullanıcıya bırakınca kullanıcı (toplantıya katılmaya odaklandığı için) "evet" der. Hoca bunu Windows XP döneminde imzasız sürücü yükleme uyarısına benzetti.
- Veri kaybının büyük kısmı hacklemeden değil, dikkatsizlikten gelir
  - Accidental disclosure (%22) ve physical document loss (%21) birlikte %43'tür; bu, malware/hacking'in (%32) üzerindedir.
  - Hurdaya verilen, diski silinmemiş terminal bilgisayarları gibi örneklerle şifrelenmemiş diskin riski vurgulandı.
- Trusted Computing Base
  - Sistemin bir minimum parçasının ele geçirilmediği varsayılır ve güvenli ortam onun üstüne kurulur; firmware kriptografik olarak imzalanır, ama imzalayanın arka kapı koymadığı da varsayılmak zorundadır.

## Kısa Tekrar Notları

- Güvenlik probleminin üç nedeni: hatalı yazılım, etkili sosyal mühendislik, zafiyetlerden para kazanılabilmesi.
- Exploit: zafiyeti açığa çıkarıp veri sızdırmayı ya da kontrolü ele geçirmeyi sağlayan kod.
- Owned machine: kontrolü ele geçirilmiş sistem. PPI: makine başına ücretle yükleme hizmeti.
- 2019'da en çok farklı zafiyet: Android (414).
- Zoom `localhost:19421`: diyalogsuz web isteği, herhangi bir site kullanıcıyı toplantıya katabilir.
- `disable-library-validation:true`: kütüphanelerin hash kontrolü yapılmaz, libssl proxy'lenip şifrelenmeden önceki düz metin çalınabilir.
- Referans monitör: işletim sisteminin erişim denetiminden bağımsız ikinci denetim katmanı.
- DoS: sistemin hizmet üst sınırını aşan istekle hizmet verememesi.
- Man-in-the-browser: tarayıcıya enjekte edilen JavaScript ile yapılan man-in-the-middle saldırısı.
- WannaCry: SMB (port 445), EternalBlue (14 Nisan 2017), tespit 12 Mayıs 2017.
- Equifax 2017: yaklaşık 143M kayıt, Apache Struts RCE.
- Müşteri verisi kaybı: malware/hacking %32, accidental disclosure %22, physical document loss %21, lost/stolen laptops or servers %17, insider misuse/attack %8.
- Thompson'ın arka kapısı: derleyici login programını görünce login arka kapısını, derleyiciyi görünce derleyici arka kapısını ekler.
- TCB: minimal güvenilir taban üzerine güvenli ortam kurmak.

## Detaylı Açıklamalar

- **Hatanın güvenlik açısından anlamı.** Her hata uygulamanın beklendiği gibi çalışmamasına yol açtığı için kötüdür. Ancak güvenlik açısından önemli olan, hatanın uygulamayı saldırganın istediği yöne "evirmeye" izin verip vermediğidir. Hello World düzeyinin üstündeki her yazılımda hata bulma ihtimali vardır.
- **Zafiyet ekonomisi.** Ele geçirilen her bilgisayardan telefon numarası, kişi bilgisi, e-posta ve şifresi, sosyal güvenlik numarası (bizdeki TC kimlik numarasına denk), yazışmalar, fotoğraf ve ses kayıtları alınabilir; saldırgan sistemin en yetkili kullanıcısı düzeyindedir. Veriler şifrelenip fidye de istenebilir. Hoca PPI'ı, mafyanın kendi işleri için ayak takımını kullanmasına benzetti: saldırı sahibi bilinmeyen makinelerden yapılır, makine sahipleri bunu çoğu zaman saldırıdan sonra fark eder ve hukuken zor durumda kalabilir. Hoca ayrıca kısa süre önce Active Directory etki alanlarına şifre kullanmadan yönetici olarak girilebilmesini sağlayan bir açığın gösterildiğini anlattı; güçlü şifreler bile böyle bir zafiyete karşı işe yaramaz.
- **Zoom örneği (localhost web sunucusu).** Linke tıklanınca tarayıcı açılır, tarayıcı da uygulamayı başlatır. Bunun için pek çok uygulama içine gömülü küçük bir web sunucusu barındırır ve REST/HTTP istekleriyle konuşur. Zoom'da istek `http://localhost:19421/launch?action=join&confno=[conference number]` biçimindedir (ekrandan, 00:35:00). Web isteği bir diyalog gerektirmediği için herhangi bir site bu isteği gönderebilir ve kullanıcıyı haberi olmadan bir konferansa katabilir; iki kişi arasındaki görüşmeye üçüncü biri girmiş olur. Hocaya göre bu tasarımsal bir hatadır; web sunucusu daha sonra Apple'ın MRT aracıyla kaldırılmıştır. Ayrıca tarayıcı ile uygulama arasındaki işletim sistemi kanalı düzgün kapatılmazsa uygulama tarayıcıdaki tuşlamaları ve tıklamaları dinleyebilir hâle gelebilir.
- **Zoom örneği (hardened runtime).** MacOS'un hardened runtime özelliği, kullanıcı Zoom'a kamera ve mikrofon izni verdikten sonra uygulama kodunun değişmediğini garanti eder (ekrandan, 00:40:00). Zoom bu özellikle uyumlu olmadığı için kullanıcıdan onay ister; onay verilince `disable-library-validation:true` olur ve sistem yüklenen kütüphanelerin kriptografik hash'ini denetlemez. Zoom kütüphaneleri başlangıçta dinamik olarak yükler. Saldırgan `libssl.1.0.0` adında, gerçek libssl'e aracılık eden (proxy) bir kütüphane yerleştirir (ekrandan, 00:50:00). Gerçek SSL arkada çalışmaya devam eder, görüşme şifreli gider, ama ses, görüntü, ekran paylaşımı ve sohbet şifrelemeye girmeden önce düz metin hâlinde saldırgana kopyalanır.
- **Referans monitör.** İşletim sistemi bir zafiyet sonucu ele geçirildiğinde bunu fark etmeyebilir. Bütünlüğü ayrıca denetlenen bağımsız bir referans monitör ise o yapı bozulduğunda bütün erişimi engelleyebilir. Uygulamaların bu yeni yapıya uyması gerekir; geçiş dönemlerinde kullanıcıya sorulan her izne "evet" demek ciddi açıklar doğurur.
- **Saldırı ekonomisinden sayılar.** Saatlik DoS saldırısı 20 dolar, 24 saatlik saldırı 100 dolar olarak verildi (24 katı değil, toptan indirim). WannaCry fidye ekranında belirli tarihten sonra ödemenin artacağı, daha sonra dosyaların kaybolacağı yazıyordu ve 300 dolarlık Bitcoin isteniyordu. <!-- BELİRSİZ: DoS fiyatları ve WannaCry ekranındaki tarih/tutar karede görülmedi, yalnız altyazıdan alındı. -->
- **Fidye yazılımı tablosu (ekrandan, 01:30:00).** Saldırıya uğrayan kullanıcı yüzdesine göre: WannaCry 7.71, Locky 6.70, Cerber 5.89, Jaff 2.58, Cryrar/ACCDFISA 2.20, Spora 2.19, Purgen/GlobeImposter 2.11, Shade 2.06, Crysis 1.25, CryptoWall 1.13. Hoca yedeğin bile canlı sistemde son duruma dönmek için yetmeyebileceğini, yedek alma politikasının önemli olduğunu söyledi.
- **Ziyaretçiye bulaştırma.** Sosyal mühendislikle ilgi alanına göre (spor, moda, araba) hazırlanmış bir siteye yönlendirilen kullanıcı, oraya zararlı yüklemek için kurulmuş bir sayfada vakit geçirir. MPack gibi PHP tabanlı paketler zararlıyı, neredeyse sıfır boyutlu görünmez bir iframe olarak sayfaya gömer; yönetim konsolu bulaşma istatistiği verir, birkaç yüz dolara satılır, bir yıllık destek sözleşmesi bile alınabilir. Buna karşı tarayıcıların güvenli tarama (safe browsing) listeleri kullanılır: tarayıcı girilen siteyi üreticisine (Google, Mozilla, Apple vb.) sorar. <!-- BELİRSİZ: Altyazıda "MPEG" geçiyor; CS155 slaytlarında bu paketin adı büyük olasılıkla MPack'tir. -->
- **Zafiyet pazarının iki yüzü.** Aydınlık tarafta bug bounty programları vardır. Karanlık tarafa kaymayı önlemek için Zerodium gibi şirketler çok daha yüksek fiyat verir; Windows uzaktan kod çalıştırma (zero click) için 1 milyon dolara, Chrome RCE/LPE için 500 bin dolara, VMware ESXi sanal makineden kaçış için 200 bin dolara kadar ödeme listelenmiştir (altyazıdan). Zerodium'un kendi sitesine göre müşterileri ağırlıkla Avrupa ve Kuzey Amerika'daki devlet kurumlarıdır; hoca bunu savaşın siber alana kaymasının göstergesi olarak yorumladı.
- **Thompson'ın arka kapısı (ACM, 1984, Turing ödülü konuşması).** Ubuntu'yu indirip SHA-256 hash'ini kontrol etsek bile login programında arka kapı olmadığını bilemeyiz. Kaynaktan derlesek derleyiciye güvenmek zorundayız. Derleyicinin kaynağını inceleyip yeniden derlesek bile, GCC kendini derleyen bir derleyici olduğu için başlangıçta güvenmek zorunda olduğumuz bir derleyici ikilisi vardır (tavuk-yumurta ilişkisi). Slayttaki saldırı adımı 1 şöyledir (ekrandan, 01:55:00):

  ```c
  compile(s) {
      if (match(s, "login-program")) {
          compile("login-backdoor");
          return
      }
      if (match(s, "compiler-program")) {
          compile("compiler-backdoor");
          return
      }
      /* regular compilation */
  }
  ```

  Bu bir sözde koddur, derlenebilir bir C programı değildir. Değiştirilmiş derleyici derlenir, sonra kaynak özgün hâline döndürülür. Kaynağı incelemek olağandışı bir şey göstermez, ama derleyiciyi derlemek yine bozuk bir derleyici ikilisi üretir.
- **Güven zinciri.** Postayla gelen bir dizüstü bilgisayarda uygulamalar ve işletim sistemi arka kapılı olabilir. Yeniden kurmak için işletim sistemine, ona da UEFI/BIOS'a güvenmek gerekir; ama BIOS da değiştirilebilir (ShadowHammer örneği). Sonunda anakarta kadar inilir. Bu yüzden Trusted Computing Base yaklaşımı kullanılır (ekrandan, 02:00:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
