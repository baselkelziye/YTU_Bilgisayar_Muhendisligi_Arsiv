# Ders 3 Çalışma Özeti

## Genel Konular

- Congestion (Tıkanıklık) Kavramı
  - Trafik sıkışıklığı, günlük hayattan bir benzetmeyle açıklanır: yolların kapasitesinden fazla araç çıktığında yaşanan yavaşlama, durma, kazalar bilgisayar ağlarında da yaşanır.
  - Network layer'ın görevi, paketleri bir noktadan diğerine aktarmaktır; eğer topolojinin kapasitesinden fazla yüklenme olursa, paketler iletilemez hale gelir ve tamamen durma noktasına (congestion collapse) gelinebilir.
  - Bu sorun sadece network katmanına ait değildir; link, network ve transport katmanlarının hepsinde tedbirler alınmalıdır.

- Proaktif (Önleyici) vs Reaktif (Tepkisel) Yaklaşımlar
  - Proaktif (preventif): Tıkanıklık oluşmadan önce tedbir alınır; ağın kapasitesinin %70-80'inde kalınır. Dezavantaj: kullanılmayan %20-30'luk kapasite boşa harcanır.
  - Reaktif: Tıkanıklık oluştuktan sonra çözülür; daha esnek ama riskli. Dezavantaj: müdahale gecikirse congestion collapse yaşanabilir.
  - Mühendislik problemlerinde her zaman bir trade-off vardır; burada "güvenli" kalmak (proaktif) ile "verimli" olmak (reaktif) arasında seçim yapılır.

- Traffic Aware Routing (Trafik Farkında Yönlendirme)
  - Ağdaki trafik yoğunluğunu bilerek routing yapan algoritmalardır; bir link'te trafik eşik değerini aşarsa trafik alternatif yola yönlendirilir.
  - Dezavantaj: Çok sık güncelleme yapılırsa routerlar sürekli hesap yapar; oscillation (salınım) problemi ortaya çıkar (CF→EI→CF→EI şeklinde ping-pong).

- Admission Control (Kabul Kontrolü)
  - Network'e sadece yeterli kapasite varsa yeni trafik kabul edilir; özellikle virtual circuit (sanal devre) yapılarında uygulanabilir.
  - Connectionless datagram yapılarda uygulanması zordur çünkü her paket farklı yoldan gidebilir.

- Traffic Throttling (Trafik Yavaşlatma) / Explicit Congestion Notification
  - Bir router çıkışında tıkanıklık yaşarsa, paketlerdeki özel bir biti (ECN) set eder.
  - Forward (ileri) yönde: Hedef host'a ulaşan paketteki işaret, hedefin kaynağa "yavaşla" mesajı göndermesini sağlar (end-to-end).
  - Backward (geri) yönde: Router, geriye gönderdiği paketlerde işaret koyar; bir önceki router bunu görüp kendisi de yavaşlar (hop-by-hop).
  - Bu işaret için ayrı paket gönderilmez; paketin başlık alanındaki (header) özel bir bit kullanılır. Bu tekniğe "piggybacking" denir (fiziksel/link katmanından bilinen bir kavram).

- Load Shedding (Yük Atma)
  - Tüm yöntemler yetersiz kaldığında router, paketleri drop eder (gelmemiş kabul eder).
  - End-to-end veya link-by-link yapılabilir. Link-by-link daha hızlı rahatlama sağlar; end-to-end uzun vadede daha etkilidir (kaynak da yavaşlar).
  - Paket düşürme kararı: Hangi paketler düşürülecek? "Milk" (süt) yaklaşımı — en yeniler (video için uygun, son kareden devam edilir); "Wine" (şarap) yaklaşımı — en eskiler (dosya transferi için uygun, sıra önemli).
  - Bu karar transport katmanında değerlendirilir; network katmanı sadece paket drop eder.

## Hocanın Özellikle Vurguladığı Kısımlar

- Trade-off farkındalığı
  - Proaktif önlemler (capacity'nin %70-80'ini kullanmak) güvenlidir ama israf yaratır; reaktif önlemler verimlidir ama risk taşır. Mühendis bu dengeyi bilerek karar vermelidir.
  - Doğal felaket senaryoları (herkes aynı anda arama yapar) reaktif yaklaşımın ne kadar gerekli olduğunu gösterir; aksi takdirde sistem tamamen kilitlenir.

- Süt/Şarap benzetmesinin önemi
  - Hoca, "süt" ve "şarap" terimlerinin terminolojide yerleşik olduğunu ve hangi uygulama için hangi stratejinin seçilmesi gerektiğini vurgular. Sınavda bu kavramlar sorulabilir.

- Network layer'ın sınırları
  - Congestion control her ne kadar network layer'da da uygulansa, asıl çözümün transport katmanında (kaynak hızı ayarı) ve uygulama katmanında (kod seviyesinde) olduğu vurgulanır.

## Kısa Tekrar Notları

- Congestion = kapasite aşımı; 3 katmanda da müdahale gerekir
- Proaktif: %70-80 kullanım; reaktif: tıkanıklık sonrası müdahale
- Traffic aware routing: yoğunluğa göre yön değiştirme; oscillation riski
- Admission control: yeterli kapasite varsa kabul; virtual circuit'lerde uygun
- Traffic throttling: ECN ile paket işaretleme; forward (end-to-end) veya backward (hop-by-hop)
- Load shedding: paket drop; milk (yeni) vs wine (eski)
- Piggybacking: header bit alanı kullanımı

## Detaylı Açıklamalar

Tıkanıklık kontrolü mühendislik problemidir. Gerçek hayattan bir örnek: ev interneti veya telefon servisi, ortalama yoğunluğa göre (%70-80 doluluk) tasarlanır. Normal şartlarda herkes rahatça iletişim kurar. Ancak bir doğal felaket anında herkes aynı anda arama yapmak ister; bu durumda sistem tamamen kilitlenir. Çözüm: reaktif önlemler.

Traffic aware routing, topolojideki yoğunluğu ölçer ve routerları bilgilendirir. Eğer bir link'te eşik değer aşılırsa, trafik alternatif bir yola yönlendirilir. Ancak bu güncelleme çok sık yapılırsa, router'lar sürekli Dijkstra algoritması çalıştırmak zorunda kalır ve sürekli yön değişikliği (oscilasyon) yaşanır. Pratikte bu teknik, yavaş değişen trafik için uygundur; ani değişimler için congestion hâlâ oluşabilir.

Admission control, virtual circuit (sanal devre) yapılarında uygulanabilir; çünkü bu yapılarda bağlantı kurulmadan önce yolun tamamı bilinir. Network layer, "bu yol boyunca yeterli kapasite var mı?" sorusuna cevap verebilir ve yeterliyse yeni bağlantıyı kabul eder. Datagram yapısında her paket farklı yoldan gidebileceğinden bu kontrol zordur.

Traffic throttling, modern ve etkili bir yöntemdir. Router, çıkış kuyruğunda birikme yaşarsa gelen paketlerdeki ECN (Explicit Congestion Notification) bitini set eder. Bu set edilmiş paket hedefe ulaştığında, hedef host TCP ACK'sında kaynağa "yavaşla" bilgisi gönderir. Bu end-to-end (uçtan uca) yöntemdir. Alternatif olarak router, geriye gönderdiği paketlerde de aynı biti set edebilir; bu durumda bir önceki router yavaşlar (hop-by-hop). İki yöntem de kullanılabilir; önemli olan ayrı bir paket gönderilmeden header alanı kullanılmasıdır (piggybacking).

Load shedding en son çare olarak uygulanır. Eğer tüm yöntemler yetersiz kalırsa ve buffer dolmuşsa, router gelen paketleri drop eder. Bu, "yangına benzin dökmek" gibidir çünkü zaten tıkanık olan network'e ek bir retransmission yükü bindirir. Ancak başka çare kalmamıştır. Paket drop kararı önemlidir: gerçek zamanlı uygulamalar (video) için en yeni paketler düşürülür (süt mantığı — son kareden devam edilir), veri aktarımı (dosya indirme) için en eski paketler düşürülür (şarap mantığı — sıra korunmalı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
