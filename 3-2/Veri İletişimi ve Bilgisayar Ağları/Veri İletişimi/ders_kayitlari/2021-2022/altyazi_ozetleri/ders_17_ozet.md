# Ders 17 Çalışma Özeti

## Genel Konular

- Ders 20 Aralık 2021 Pazartesi akşamı online yapıldı. Slaytlarda "Week 12" yazıyor. Dersi Dr. Furkan Çakmak anlatıyor.
- Kayıt, oturumu açan hocanın toplantı yönetimini (host) Furkan Çakmak'a devretmesiyle başlıyor. Ders yaklaşık bir saat sonra başlıyor. Sabah grubu da bu derse katılabiliyor.
- Proje ödevi önceki hafta verildi. Bu yüzden konu sırası değişti: TCP/IP ve ağ cihazları bir hafta öne alındı.
- Ders, veri bağı katmanından ağ katmanına geçişin girişi niteliğinde.
- Konular:
  - Bilgisayar ağlarının sınıflandırması: yayınlı (broadcast) ve anahtarlamalı (switched) ağlar.
  - Devre anahtarlama (circuit switching):
    - Üç aşama.
    - Uzay bölmeli anahtarlama (space division) ve çapraz çubuk (crossbar).
    - Çok katlı anahtarlama.
    - Zaman bölmeli anahtarlama (time division) ve TSI (Time Slot Interchange).
    - Karma (hybrid) yapılar ve yazılım tabanlı anahtarlama.
  - Paket anahtarlama (packet switching): datagram yaklaşımı ve sanal devre (virtual circuit) yaklaşımı.
  - Sanal devre türleri: anahtarlamalı sanal devre (Switched Virtual Circuit, SVC) ve kalıcı sanal devre (Permanent Virtual Circuit, PVC).
  - Paket boyutunun iletim süresine etkisi.
  - Bağlantısız (connectionless) ve bağlantı yönelimli (connection-oriented) hizmetlerin karşılaştırması.
  - Katmanlara göre ağ cihazları: repeater, bridge, router, gateway. Ayrıntısı gelecek haftaya bırakıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Devre anahtarlamada üç aşama vardır: bağlantı kurma, veri iletimi, bağlantıyı sonlandırma. Hoca bunu sabit hatlı telefonla anlattı:
  - Ahizeyi kaldırma ve çevir sesi.
  - Numara tuşlama.
  - Karşı tarafın çalması ve açması: bağlantı kuruldu.
  - Konuşma: veri iletimi.
  - Kapatma: bağlantı sonlandı.
- Devre kurulduktan sonra hat boş bile olsa ücret ödenir. Paket anahtarlamada ücret gönderilen veri miktarına göredir.
- Ses trafiği düzenli bir akıştır. Veri trafiği patlamalıdır (bursty). Paket anahtarlama patlamalı veri için tasarlanmıştır.
- Devre anahtarlamada hat koparsa onarılana kadar iletişim kesilir. Datagramda paketler başka yoldan gidebilir.
- **Datagram ile sanal devre farkı sınavlarda her yıl soruluyor:**
  - Datagramda her pakette alıcı ve gönderici adresi bulunur.
  - Sanal devrede pakette yalnızca sanal kanal tanımlayıcısı (Virtual Channel/Circuit Identifier, VCI) bulunur.
- Paket boyutunu küçültmek iletimi belli bir noktaya kadar hızlandırır. Daha da küçültünce başlık ek yükü yüzünden yavaşlar. Hoca "bu kısım kafanızda iyi canlansın" dedi.
- Bağlantısız ve bağlantı yönelimli hizmet benzetmesi:
  - **Datagram:** Arabayla Ankara'ya gitmek. Bolu Dağı kapalıysa Bilecik'ten gidilir; her kavşakta yeniden karar verilir.
  - **Sanal devre:** Trenle gitmek. Yol baştan bellidir, değiştirilemez, ama hızlı ve yüksek kapasitelidir.
- Karşılaştırma tablosu sınav için önemli:
  - Bağlantı kurulumu.
  - Rota belirleme.
  - Adres bilgisi.
  - Paket sırası.
  - Değişen koşullara uyum.

## Kısa Tekrar Notları

- **Devre anahtarlama:** İki uç arasında sabit bir yol ayrılır. Sabit gecikme vardır. Hat boştayken kapasite boşa gider.
- **Crossbar:** $N$ giriş ve $M$ çıkış için $N \times M$ anahtar (kesişim noktası) gerekir. 3 giriş ve 4 çıkış için 12 anahtar gerekir.
- **Çok katlı (multistage) anahtarlama:** Anahtar sayısını azaltmak için ara katlar kullanılır. Örnek: Erzurum'dan bir çağrı Ankara santrali üzerinden İstanbul'a bağlanır.
- **TSI (Time Slot Interchange):** Zaman dilimlerindeki veriyi bellekte tutar ve sırasını değiştirerek çıkışa verir. Esnektir ama gecikme ekler.
- **Datagram:** Bağlantı kurma aşaması yoktur. Her paket bağımsız yönlendirilir. Paketler farklı sırayla varabilir ya da kaybolabilir. Posta ve kargo benzetmesine uyar.
- **Sanal devre:** Önce bir yol belirlenir. Tüm paketler bu yoldan sırayla gider. Pakette yalnızca VCI taşınır.
- **SVC:** Yol her iletişim başında bir çağrı kurma paketiyle belirlenir. Yol bozulursa yeni bir çağrı kurulur.
- **PVC:** Yolu servis sağlayıcı kalıcı olarak tanımlar. Yol bozulursa sağlayıcının müdahalesi gerekir. Değişime uyumu en yavaş olandır.
- **Uyum sırası (hızlıdan yavaşa):** datagram > SVC > PVC.
- **Katmanlara göre cihazlar:**
  - Fiziksel katman: repeater.
  - Veri bağı katmanı: bridge ve switch.
  - Ağ katmanı: router.
  - Üst katmanlar: gateway.

## Detaylı Açıklamalar

### Ağların sınıflandırması

- Bilgisayar ağları ikiye ayrılır:
  - **Yayınlı ağlar:** bus, star ve ring topolojili LAN'lar. Gönderilen veriyi herkes duyar.
  - **Anahtarlamalı ağlar:** WAN'lar. Uzak uçlar ara düğümler üzerinden bağlanır.
- LAN'da 20 bilgisayarı mesh ile bağlamak bile mümkündür. Erzurum ile İstanbul'u ring ya da mesh ile bağlamak mümkün değildir. Bu yüzden WAN'da anahtarlama gerekir.
- Anahtarlamalı ağların üç türü vardır: devre anahtarlamalı, paket anahtarlamalı ve mesaj anahtarlamalı.

### Devre anahtarlama ayrıntıları

- **Crossbar:**
  - Slayttaki çizimde A, B, C girişleri ile 1–4 çıkışları bir matrisle bağlanıyor.
  - Her kesişimde transistör gibi açılıp kapanan bir anahtar var. A–1, B–2 ve C–4 bağlantıları kapalı.
  - A, 1 ile konuşurken 3 numara A'ya ulaşmak isterse meşgul sesi alır.
  - Eski santrallerde operatörlerin kabloları takıp çıkarması aynı işi elle yapıyordu.
- **Crossbar'ın ölçek sorunu:**
  - Türkiye'de 3000 uç nokta olsaydı her biri için 3000 anahtar gerekirdi.
  - Bu yüzden çok katlı yapılar ve çoğullama (multiplexing) kullanılır.
- **Zaman bölmeli anahtarlama:**
  - 4 kaynak (A, B, C, D) için zaman 4 dilime bölünür. Her kaynak kendi diliminde gönderir.
  - Sıralamanın önemli olduğu durumlarda TSI kullanılır. TSI veriyi bir tampona (buffer) alır ve yeniden sıralar.
- **Karma yapılar:** Uzay ve zaman bölmeli anahtarlama birlikte kullanılabilir. Böylece hem esneklik hem hız sağlanır.
- **Yazılım tabanlı anahtarlama:**
  - Bugün cep telefonlarında arama VoIP (Voice over IP) ile yapılır.
  - Hücresel veri ya da Wi-Fi üzerinden ses paket olarak taşınır.

### Datagram yaklaşımı

- PTT veya kargo benzetmesi:
  - Aynı adrese 4 mektup gönderilir. Her biri farklı yoldan, farklı sürede gidebilir.
  - Bazıları sırası karışmış olarak varabilir. Biri hiç ulaşmayabilir.
- **Ara düğümler (router):**
  - Ağın o anki durumuna göre her paket için yönlendirme kararı verirler.
  - Paketlerin izlediği yollar farklı olabilir. Örnek yollar: A–C–D–F–Z, A–C–F–Z, A–B–D–C–F–Z.
- **Avantajları:**
  - Bağlantı kurma aşaması yoktur.
  - Az sayıda paket hızlı gönderilir.
  - Tıkanıklık (congestion) ya da arızada paket hemen başka yola sapabilir.
- **Dezavantajları:**
  - Her pakette tam adres taşındığı için başlık büyüktür.
  - Paketler sırasız varabilir, alıcı onları yeniden sıralamalıdır.
  - Her düğümde yönlendirme kararı gecikme ekler.

### Sanal devre yaklaşımı

- Veri gönderilmeden önce bir kurulum paketi gider ve yolu belirler, örneğin A–B–D–F–Z. Tüm paketler bu yolu izler.
- **SVC:**
  - Yol her iletişim başında kurulur.
  - Hattaki bir kopukluk, yeni bir bağlantı kurulana kadar iletişimi durdurur.
- **PVC:**
  - Yolu servis sağlayıcı sizin adınıza kalıcı olarak tanımlar.
  - Bir bağlantı koparsa yolu sağlayıcının yenilemesi gerekir.
- **Avantajları:**
  - Paket sırası korunur.
  - Her düğümde yönlendirme kararı gerekmez.
  - Hata denetimi ve yeniden gönderim daha kolaydır.
  - Uzun süreli, yoğun veri akışında başarım yüksektir. Bu yüksek hizmet kalitesi (Quality of Service, QoS) anlamına gelir.
- Tek bir fiziksel hat birden çok sanal devre tarafından paylaşılabilir. Hoca bunu İstanbul–Eskişehir–Ankara–Konya tren hattıyla anlattı.
- **Dezavantajları:**
  - Tıkanıklık ve arızaya datagramdan daha geç tepki verir.
  - Bir düğüm çökerse o düğümden geçen tüm sanal devreler aynı anda etkilenir ve yeniden kurulmalıdır.

### Karşılaştırma tablosu

| Ölçüt | Datagram | SVC | PVC |
| --- | --- | --- | --- |
| Bağlantı kurulumu | Yok | Her iletişim başında kurulum paketiyle | Servis sağlayıcı tanımlar |
| Rota belirleme | Her düğümde, her paket için | Kurulumda bir kez | Sağlayıcının belirlediği sabit rota |
| Pakette taşınan | Alıcı ve gönderici adresi | VCI | VCI |
| Paket sırası | Korunmaz | Korunur | Korunur |
| Değişen koşullara uyum | En hızlı | Orta (yeni bağlantı kurulur) | En yavaş (sağlayıcı müdahalesi gerekir) |

### Paket boyutu ve iletim süresi

- Hocanın örneği:
  - X'ten Y'ye A ve B düğümleri üzerinden, yani 3 bağlantı (hop) üzerinden 40 baytlık veri gönderiliyor.
  - Her pakete 3 baytlık başlık ekleniyor.
- Paket küçüldükçe düğümler bir paketi iletirken bir sonrakini alabilir. Bu boru hattı (pipelining) etkisi iletimi hızlandırır.
- Ama paket sayısı arttıkça toplam başlık yükü de artar.
- Paket iletim süresini birim alırsak, toplam süre $(\text{hop} + k - 1) \times (\text{paket boyutu})$ olur. Burada $k$ paket sayısıdır. Python ile hesaplanan değerler:

| Paket sayısı | Paket boyutu (bayt) | Toplam süre (bayt-zamanı) |
| --- | --- | --- |
| 1 | 43 | 129 |
| 2 | 23 | 92 |
| 5 | 11 | 77 |
| 10 | 7 | 84 |

- En iyi sonuç 5 pakettedir. 10 pakete bölünce süre yeniden artar. Hocanın "belli bir değerden daha küçüğe bölemiyorsunuz" dediği nokta budur. Bu örnek Stallings'in ders kitabındaki şekille aynıdır.

### Ağ cihazlarına giriş

- **Repeater:** Fiziksel katmanda zayıflayan sinyali (attenuation) yeniler.
- **Bridge:** Veri bağı katmanında iki LAN'ı birleştirir.
- **Router:** Ağ katmanında çalışır. Datagram ve sanal devre anlatımlarındaki "düğüm"ler router'dır.
- **Gateway:** Taşıma, oturum, sunum ve uygulama katmanlarında çalışır.
- Ayrıntılar gelecek haftaya bırakıldı.

### Duyurular

- Toplam iki hafta kaldı. Bir hafta daha ders anlatılacak, son hafta öğrenci sunumları yapılacak.
- Sunumlar ders kayıtlarıyla birlikte paylaşılıyor, eksik olanlar yüklenecek.

### Ders sonrası notlar

- **SVC kurulumu ve oturum katmanı:**
  - Hoca SVC'deki yolun "oturum katmanında (session layer) gönderilen bir paketle" kurulduğunu söyledi.
  - Aslında sanal devre kurulumu ağ katmanında bir çağrı kurma sinyalleşmesiyle yapılır. Örneğin X.25'te Call Request/Call Accepted paketleri, ATM'de Q.2931 sinyalleşmesi kullanılır.
  - Yol bozulduğunda yeniden kurulumu da ağ katmanı veya sinyalleşme yapar; oturum katmanı değil.
- **Tuş sesleri:** Hoca "her tuşun farklı bir frekansı var" dedi. Tuşlu telefonlar DTMF (Dual-Tone Multi-Frequency) kullanır. Her tuş, bir düşük ve bir yüksek frekanstan oluşan iki tonun birleşimidir. Örneğin "1" tuşu 697 Hz + 1209 Hz'dir.
- **Zil gerilimi:** Hoca 70–80 V dedi. Sabit hatlarda zil sinyali genellikle 75–90 V (etkin değer), 20–25 Hz'lik alternatif gerilimdir. Hat normalde yaklaşık 48 V DC ile beslenir.
- **Crossbar ölçeği:** $N$ uçlu tam bir crossbar yaklaşık $N^2$ anahtar ister; 3000 uç için yaklaşık 9 milyon anahtar gerekir. Hocanın "her biri için 3000 anahtar" ifadesi bu toplamla tutarlıdır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
