# Ders 11 Çalışma Özeti

## Genel Konular

- Ağ saldırılarının tekrarı: on-path ve off-path saldırgan (ekrandan, 00:05:00)
  - On-path saldırgan iki taraf arasındaki yolun üzerindedir (man in the middle). Off-path saldırgan yolun kenarındadır, ama yol üzerindeki bir sistemi ele geçirirse trafiği izleyebilir, kesebilir ya da değiştirebilir.
  - Ele geçirilen sistemin sunucu olması gerekmez; router görevi gören bir host ele geçirilirse üzerinden akan bütün trafik saldırganın kontrolüne geçer.
  - ARP ve BGP saldırıları, sistemi buffer overflow gibi bir yolla ele geçirmeye gerek kalmadan, yalnız doğru paketleri göndererek off-path saldırganı on-path hale getirebilir.
- Ağ protokollerinde CIA eksikliği
  - Ethernet, IP, TCP ve UDP gizlilik (confidentiality) sağlamaz; her şey açık metin (clear text) gider.
  - Bütünlük (integrity) için trafiğin değişip değişmediğini kontrol eden bir mekanizma yoktur.
  - Kaynak doğrulama (source authentication) neredeyse yoktur; TCP'de üç yönlü el sıkışmadaki sıra numaraları zayıf bir doğrulama sağlar.
  - Süreklilik (availability) açısından, örneğin RST paketleriyle mevcut bir bağlantı uzaktan sonlandırılabilir.
- "Ağın kötü niyetli olduğunu varsay" ilkesi (ekrandan, 00:10:00)
  - Dinlenmeye karşı koruma ve verinin on-path saldırgan tarafından değiştirilmediğinin güvencesi için her zaman TLS kullanılmalıdır.
  - HTTPS ve TLS yalnız hassas veri için değildir: web sitelerine kötü niyetli JavaScript ya da zararlı yazılım enjekte edilen saldırılar olmuştur.
  - Çerezler `HttpOnly` (yerel JavaScript erişemesin) ve `Secure` (yalnız geçerli HTTPS bağlantısında gönderilsin) olarak işaretlenmelidir.
  - Yeni protokol yazmak yerine analizden geçmiş, olgunlaşmış protokoller kullanılmalıdır.
- Denial of Service (DoS) tekrarı (ekrandan, 00:15:00)
  - DoS Bug: bir makinenin servisi bozmasına izin veren tasarım hatası; genelde protokol asimetrisi (isteği göndermek kolay, cevabı üretmek zor) ya da sunucuda durum (state) tutma gereği.
  - DoS Flood: bir botnet ya da kontrol edilen başka makinelerden çok sayıda istek gönderme.
  - SYN flood ve savunması SYN cookie: el sıkışma tamamlanana kadar durum bilgisi tutulmaz.
  - UDP amplification: küçük bir sorgu büyük bir cevap doğurur; sahte kaynak IP ile cevaplar kurbana yönlenir. DNS ve NTP sık kullanılan yükselticilerdir. 2018 memcached saldırısında istek/cevap oranı yaklaşık 1'e 50 bindir.
  - Mirai IoT botnet'in başarısı: IoT cihazlarının düşük güvenliği, saldırının basitliği ve tespit edilmesi zor, yükü az stateless tarama.
  - Google Project Shield: önde bir proxy, tamamlanmamış bağlantıları arkaya iletmez. Saldırı bu kez GET flood'a döner (ekrandan, 00:20:00): botlar gerçek TCP bağlantısı ve TLS el sıkışması tamamlayıp büyük içerik ister; rastgele kaynak IP kullanamadıkları için kurban site botları engelleyebilir ya da hız sınırı koyabilir.
  - Ingress filtering: ISP yalnız meşru kaynak IP'li paketleri dışarı iletmelidir. Hocanın aktardığı 2017 verisine göre otonom sistemlerin %33'ü, duyurulan IP bloklarının %23'ü sahte kaynak IP'ye (spoofing) izin veriyordu.
  - Client puzzle: istemciye CPU ya da bellek yoğun bir soru sorarak bağlantıyı yavaşlatmak; zararı, masum istemcilere de ek yük ve enerji tüketimi getirmesidir.
- Firewall (ekrandan, 00:25:00)
  - Amaç: yerel ağı (LAN) internetten ayırmak ve yalnız bazı trafiğin geçmesine izin vermek. Kurallar bazen router üzerinde, bazen ayrı bir cihazdadır.
  - Gereksiz açık servisler (internetten erişilmesi gerekmeyen servisler, recursive DNS resolver'lar, Windows dosya paylaşımı) saldırı noktalarıdır.
  - Paket filtreleme beşli (five tuple) üzerinden yapılır: kaynak IP, hedef IP, protokol, kaynak port, hedef port. Örnek kural: "Drop all inbound packets to TCP port 445" (Windows dosya paylaşımı).
  - Yalnız web sunucusuna erişim istenirse "hedef port 80 değilse düşür" kuralı, içeriden başlayan bağlantıların dönüş paketlerini de engeller. Çözüm stateful filtering'dir: firewall dışarı giden bağlantıları takip eder ve dönüş paketlerine izin verir.
  - Port aralıkları: 0-1023 well-known (sistem servisleri), 1024-49151 kayıtlı (registered) portlar, 49152-65535 dinamik/geçici portlar.
- NAT (ekrandan, 00:30:00)
  - NAT iki farklı adres uzayı arasında eşleme yapar; çoğu ev router'ı hem NAT hem firewall'dur.
  - Özel (private) alt ağlar: `10.0.0.0 - 10.255.255.255`, `172.16.0.0 - 172.31.255.255`, `192.168.0.0 - 192.168.255.255`. Bu adresler farklı yerel ağlarda tekrar kullanılabilir.
- Network firewall ve local (host) firewall
  - Ağ sınırındaki firewall'a ek olarak hostların üzerinde de firewall çalıştırılır (örneğin Linux'ta iptables); ikisi birlikte kullanılır.
- Uygulama seviyesinde filtreleme ve çıkış (egress) trafiği
  - E-posta virüs taraması (protokolün ve MIME kodlamasının anlaşılması, eklerin açılıp taranması), HTTP POST isteklerinde SQL injection kalıplarının (tırnak, `--`, `or 1=1`) aranması.
  - Dışarı çıkan trafik de incelenmelidir: kötü niyetli sitelere erişimi engellemek, veri sızmasını önlemek, bant genişliğini daraltan uygulamaları kapatmak.
- Saldırı tespit sistemleri (IDS)
  - Ağ kurallarını ihlal eden trafiği tespit eder ve SIEM (Security Information and Event Management) sistemine ne, ne zaman ve nerede tespit edildiğini raporlar.
  - İki yaklaşım: signature detection (kural tabanlı) ve anomaly detection (makine öğrenmesi/derin öğrenme; önce normalin öğrenilmesi gerekir).
  - Açık kaynak IDS'ler: Snort, Suricata, Zeek.
  - Örnek Snort kuralı (ekrandan, 00:35:00): `alert icmp 192.168.1.10 any -> any any (msg: "ICMP Attempt Attack"; sid:1000005)`.
- VPN ve Zero Trust
  - VPN, internet üzerinde sanal özel ağ kurar. İki temel tip: uzaktan bağlanan istemci (remote client) ve iki lokasyonun birbirine bağlanması (site-to-site).
  - En çok kullanılan protokoller IPsec (IETF) ve açık kaynak OpenVPN'dir.
  - Zero Trust: iç ağın güvenli olduğu varsayılmaz, çünkü saldırıların büyük kısmı içeriden gelir; servisler internette barındırılır ve uygulamalar doğrudan korunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağın her unsuru saldırgan kabul edilir
  - Trafiğin dinlenmesini istemiyorsanız TLS kullanmak birinci kuraldır; yoksa trafiğin kopyalanmadığının garantisi yoktur.
- HTTPS tek başına yeterli güvence değildir
  - Sunucu ele geçirilip sayfaya kötü niyetli JavaScript konmuşsa, bu kod HTTPS üzerinden gelir, yerelde çalışır ve SOP/CORS önlemleri devre dışı kalır.
- Kendi protokolünü ve kendi güvenliğini yazmak tehlikelidir
  - Bir protokolün olgunlaşması ve açıklardan etkilenmediğinin gösterilmesi zordur; analizden geçmiş protokoller kullanılmalıdır.
- Ingress filtering ISP'lerin sorumluluğudur
  - ISP arkasındaki bütün adresleri bildiği için sahte adreslerin dışarı çıkmasını engelleyebilir. Az sayıda ISP bile bunu yapmazsa savunma işe yaramaz ve ISP'yi zorlayan bir şey yoktur.
- Stateful filtering gerekliliği
  - Yalnız hedef porta bakan kural, içeriden başlayan bağlantıların dönüşünü keser.

## Kısa Tekrar Notları

- On-path: yolun üzerinde (MITM). Off-path: kenarda; ARP/BGP ile on-path olabilir.
- Ethernet/IP/TCP/UDP: gizlilik yok, bütünlük yok, kaynak doğrulama çok zayıf, RST ile bağlantı kesilebilir.
- Çözüm: her zaman TLS; çerezlerde `HttpOnly` ve `Secure`.
- DoS Bug = protokol asimetrisi ya da sunucu durumu; DoS Flood = botnet.
- SYN flood'a karşı SYN cookie; amplification'da DNS, NTP, memcached.
- Proxy korumasına karşı GET flood; savunma engelleme ve hız sınırı.
- Ingress filtering: ISP yalnız meşru kaynak IP'yi iletir.
- Firewall beşlisi: kaynak IP, hedef IP, protokol, kaynak port, hedef port.
- Stateful filtering dönüş trafiğine izin verir.
- Portlar: 0-1023, 1024-49151, 49152-65535.
- Private: 10/8, 172.16/12, 192.168/16.
- IDS: signature ya da anomaly; Snort, Suricata, Zeek; raporlar SIEM'e gider.
- VPN: remote client ve site-to-site; IPsec ve OpenVPN.
- Zero Trust: iç ağa güvenme.

## Detaylı Açıklamalar

- Ders, önceki haftanın ağ güvenliği konusunun tamamlayıcısıdır ve önce tekrar slaytlarıyla başlar. Off-path saldırgan diyagramında saldırgan iki uç arasındaki yolun dışında durur; ama bugüne kadar görülen yöntemlerle (örneğin buffer overflow) yol üzerindeki bir router'ı ele geçirirse yoldaki trafiği izleyebilir, kesebilir ve değiştirebilir (ekrandan, 00:05:00). ARP ve BGP ise bunu sistemi ele geçirmeden, yalnız sahte paketlerle sağlar.
- Hoca CIA üçlüsünü ağ protokolleri açısından tek tek değerlendirdi. Gizlilikte hiçbir koruma yoktur. Bütünlükte trafiğin değiştirildiğini anlayacak bir karşılaştırma noktası yoktur. Kaynak doğrulamada yalnız TCP'nin el sıkışmasındaki sıra numaraları ilk ve ikinci paketin aynı kaynaktan geldiğini zayıf biçimde gösterebilir. Süreklilikte RST paketleriyle bağlantılar uzaktan kesilebilir.
- "Assume network is malicious" slaytı (ekrandan, 00:10:00): "Always Assume: The network is out to get you." Çözüm: büyük ölçekli dinlemeye (örneğin istihbarat kurumları) karşı koruma ya da verinin değiştirilmediğinin güvencesi için her zaman TLS. Not: HTTPS ve TLS yalnız hassas materyal için değildir; sitelere kötü niyetli JavaScript ya da zararlı yazılım enjekte edilen saldırılar olmuştur. Hoca burada, daha önce gösterdiği, kaç siteye bulaştığını izleyen yönetim konsolu olan dark web örneğini hatırlattı: sunucu ele geçirilmişse zararlı kod HTTPS üzerinden de gelir ve same origin ile CORS önlemleri işe yaramaz.
- DoS tekrarında saldırganın az eforla kurbana çok kaynak harcatması temel kriterdir (ekrandan, 00:15:00). DoS her katmanda (link, transport, uygulama) mümkündür. Amplification'da sahte kaynak IP'li küçük UDP sorgusu kurbana istemediği büyük cevaplar gelmesine yol açar ve bant genişliğini daraltır; internette yanlış yapılandırılmış, herkese açık yüz binlerce yükseltici host vardır. Mirai kötü yazılmış ve yeni bir şey içermemesine rağmen başarılı oldu: IoT cihazlarının güvenliği çok düşüktü, saldırı basitti ve stateless tarama hem zor tespit ediliyor hem de az yük getirdiği için çok cihazı kısa sürede tarayabiliyordu. Project Shield'ın proxy çözümüne karşı saldırganlar gerçek adreslerden bağlantı kurup GET flood yapar (ekrandan, 00:20:00); hoca GitHub saldırısını (1,35 Tbps) örnek verdi.
- Ingress filtering için hoca, ISP'nin kendi ağından gelemeyecek bir adresin dışarı çıkmasını engellemesi gerektiğini anlattı. ISP'ye kazanç değil ek yük getirdiği için uygulanması zordur. Client puzzle'da istemcinin işlemci ve belleğinin sunucudan zayıf olduğu kabul edilir; ama bu yöntem masum istemcileri de yavaşlatır.
- Firewall bölümünde (ekrandan, 00:25:00) router, bir taraftan diğerine aktaracağı her paket için firewall'a sorar; ikisi tek cihazda da olabilir. Popüler TCP/UDP servisleri standart portlarda çalışır (HTTPS 443, SSH 22). Recursive DNS resolver kendi domeni dışındaki istekleri de üst sunuculara giderek çözer; Windows dosya paylaşımı ise başından beri çok zafiyet içerir ve yerelde çoğu zaman şifre bile kullanılmaz. Port 445'e gelen bütün paketleri düşüren kural bu yüzden tipik bir örnektir.
- Stateful filtering: "hedef port 80 değilse düşür" kuralı dışarıdan yalnız web sunucusuna erişimi sağlar, ama içeriden başlayan bağlantıların dönüş paketleri de (dinamik portlara geldikleri için) düşer. Firewall dışarı giden bağlantıları takip ederek ilgili dönüş portuna gelen paketlere izin verir.
- NAT slaytında (ekrandan, 00:30:00) yerel ağdaki `192.168.100.3`, `192.168.100.4`, `192.168.100.5` adresli bilgisayarlar varsayılan ağ geçidi `192.168.1.1` olan Router/NAT cihazının arkasındadır; cihazın internetteki public adresi `145.12.131.7`'dir. Hoca üç özel alt ağı en büyükten küçüğe 10 (A sınıfı), 172 (B sınıfı) ve 192.168 (C sınıfı) olarak sıraladı.
- IDS tarafında Snort kuralı (ekrandan, 00:35:00) iki kısımdan oluşur. Kural başlığı (rule header): action `alert`, protocol `icmp`, source address `192.168.1.10`, source port `any`, direction `->`, destination address `any`, destination port `any`. Kural seçeneği (rule option): `msg: "ICMP Attempt Attack"; sid:1000005`. Yani 192.168.1.10'dan gelen her ICMP paketi için log'a ya da log sunucusuna "ICMP Attempt Attack" mesajı yazılır.
- VPN ile internetteki sıkıntılara rağmen herhangi bir yerden kurumsal ağa erişilir. Uzaktan bağlanan bir satış, pazarlama ya da mühendislik çalışanı remote client tipine, farklı il veya ülkedeki lokasyonların bağlanması ikinci tipe örnektir. Zero Trust'ta iç ağ güvenli sayılmaz; örneğin Google gibi bir ortamda servisler herkese açık yerde barındırılır ve uygulama ile ağ doğrudan korunur.
- Ders sonrası notlar:
  - Altyazıda port aralığı "1 ile 23 arası" geçiyor; büyük olasılıkla Whisper "1023"ü bozmuştur. Standart aralık 0-1023'tür.
  - Hoca public adresi "145.12.131.17" diye okudu; slaytta `145.12.131.7` yazıyor (ekrandan, 00:30:00).
  - Hoca GitHub saldırısını "1.35 TB per second" diye söyledi; doğrusu saniyede 1,35 terabit (Tbps).
  - Hoca IDS'leri sıralarken Zeek'i "son dönemde" çıkan olarak andı; büyük olasılıkla Zeek, 1990'lardan beri geliştirilen Bro'nun 2018'de değişen adıdır ve Suricata'dan eskidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
