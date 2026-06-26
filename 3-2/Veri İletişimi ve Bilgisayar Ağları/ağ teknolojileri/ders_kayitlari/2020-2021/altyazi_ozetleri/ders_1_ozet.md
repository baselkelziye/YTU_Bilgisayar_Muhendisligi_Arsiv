# Ders 1 Çalışma Özeti

## Genel Konular

- Bilgisayar Ağlarına Giriş ve Referans Modeli
  - Ağ Teknolojileri dersinin amacı, network (ağ) ve transport (taşıma) katmanlarını kapsamasıdır; ders 5. baskı Tanenbaum kitabını takip eder ve network katmanından başlayarak 5-6-7. bölümlere kadar ilerler.
  - OSI referans modelinin 7 katmanı teorik olarak bilinmelidir; TCP/IP referans modeli pratikte 4 katmana indirgenmiştir; ders kapsamında 5 katmanlı yapı (physical, link, network, transport, application) kabul edilerek session ve presentation katmanları atlanır.
  - Network katmanının temel görevi, paketleri birden fazla link üzerinden uçtan uca (end-to-end), birden fazla atlama (hop) ile kaynaktan hedefe "store and forward" (sakla ve gönder) mantığıyla iletmektir.

- Paket Anahtarlama ve Connectionless/Connection-Oriented Servisler
  - Veriler, mesaj (message) halinden paket adı verilen daha küçük anlamlı parçalara bölünerek iletilir; tüm mesaj bir bütün olarak değil parçalar halinde gönderilir.
  - Paketin tamamı aradaki bir router bufferına (belleğine) gelip tamamlanmadan ileri yönlendirilmez; bu, store-and-forward prensibidir.
  - Connectionless (bağlantısız) servis mektupla haberleşmeye benzer: önceden uyarı yoktur, gelen zarf açılır; connection-oriented (bağlantı odaklı) servis ise telefon görüşmesine benzer: önce bağlantı kurulur, sonra iletişim gerçekleşir.
  - Internet'in temel felsefesi connectionless servis üzerine kuruludur (TCP/IP), ancak bu tek yol değildir; alt katmanlarda (data link) veya üst katmanda (transport TCP) connection-oriented çalışma mümkündür.

- Routing ve İnternet Yapısı
  - Internet Service Provider (ISS) ve Internet Exchange Point (IXP) kavramları; ISS'ler arası trafik değişimi genellikle maliyetli ve politik nedenlerle yönlendirilir.
  - Her router bir paketin son noktası değildir; sadece hedefe doğru ilerletir (forwarding).
  - Topoloji, routerlar, hostlar ve bağlantıların oluşturduğu graf benzeri yapıdır; hatlar çift yönlü veya tek yönlü olabilir; maliyet, güvenilirlik, politika gibi kriterlere göre ağırlıklandırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Geçmişteki (eski) yöntemlerin tekrar gündeme gelebileceği
  - Hoca, "history repeats itself" mantığını vurgular: mesela 1960'larda kullanılıp kenara atılan ALOHA algoritması RFID ile tekrar gündeme gelmiştir; Distance Vector Routing sensör ağlarda yeniden denenebilir. Bu nedenle tarihsel bilgi ileride işe yarar.
  - Mühendis olarak geçmişte benzer durumlarda uygulanan çözümleri bilmek, yeni problemlerle karşılaşıldığında ilk başvurulacak kaynaktır.

- Mühendislik kapsamı
  - Dersin sadece kavramsal değil, mühendislik perspektifiyle verildiği; "veri iletişimi" (datacom) dersinde öğrenilen OSI, 5-katman yapı, servis ve arayüz gibi temel bilgilerin hatırlanması gerektiği vurgulanır.
  - Kitap (Tanenbaum) ve slaytlar yeterli değildir; ders kayıtları, hocaların yorumları, ek bilgiler sınav ve uygulama için kritiktir.

## Kısa Tekrar Notları

- Ders Tanenbaum 5. baskıyı takip eder; network katmanından başlar
- OSI 7 katman → TCP/IP 4 katman → Ders 5 katman (üst 3: network, transport, application)
- Network katmanı: uçtan uca, çoklu hop, store-and-forward
- Connectionless = mektup; Connection-oriented = telefon
- ISS/IXP kavramları; trafik maliyeti
- Router: hedefe doğru yönlendiren, son nokta olmayan cihaz

## Detaylı Açıklamalar

Dersin ilk dersi olduğu için, dersin işleyişi ve genel çerçevesi anlatılmıştır. Hocalar iki grup halinde dersi yürütür (Cihan Hoca ile Ali Gökhan Yavuz birlikte). Kayıtlar tutulur, dolayısıyla kaçırılan dersler kayıttan izlenebilir; ancak aktif katılım önerilir.

Network katmanının genişletilmiş tanımı: Mevcut linklerle sağlanan bağlantıyı uçtan uca genişletir, topolojiyi büyütür. Bir paketin A noktasından D noktasına gitmesi için B, C gibi aradaki düğümlerden geçmesi gerekir; her geçiş bir "hop"tur. Bu nedenle network layer, link layer'ın (tek atlama) sağladığını birden fazla atlama için sağlar.

Paket kavramı: Network açısından bakıldığında, "veri" paket adı verilen yapısal birimler halinde taşınır. Bir paket 100 byte ise, tüm 100 byte bir router'a ulaşmalı, sonra hedefe doğru yönlendirilmelidir. Bu da buffer (bellek) ihtiyacı doğurur.

Connectionless vs Connection-oriented: TCP/IP dünyasında network katmanı connectionless'tır. Ancak her katmanda bu seçim yapılabilir. Örneğin, network katmanı connectionless olsa bile, üstündeki transport katmanında TCP kullanılarak connection-oriented servis sağlanabilir. Bu, katmanlı yapının esnekliğini gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
