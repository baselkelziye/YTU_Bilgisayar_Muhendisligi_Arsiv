# Ders 4 Çalışma Özeti

## Genel Konular

- Quality of Service (QoS) - Servis Kalitesi
  - Network üzerinden akan trafiğin kalitesini kontrol etme mekanizmalarının tümüdür. Tüm uygulamaların ihtiyaçları farklıdır; bu nedenle her birine farklı kalite seviyeleri sağlanmalıdır.
  - Uygulama kategorileri ve ihtiyaçları:
    - **E-posta**: Düşük bant genişliği, düşük gecikme hassasiyeti (asenkron, 10 dakika gecikse sorun olmaz); yüksek kayıp hassasiyeti.
    - **Dosya paylaşımı**: Yüksek bant genişliği, düşük gecikme/jitter hassasiyeti.
    - **Web erişimi**: Orta seviye her şey.
    - **Audio on demand, Telefon**: Düşük bant genişliği, yüksek gecikme ve jitter hassasiyeti.
    - **Video conferencing**: Yüksek bant genişliği, yüksek gecikme ve jitter hassasiyeti (real-time).
  - Her uygulamanın 4 kritere göre (bandwidth, delay, jitter, loss) farklı beklentisi vardır; QoS bu beklentileri karşılayacak şekilde trafiği yönetir.

- Trafik Şekillendirme (Traffic Shaping) ve Trafik Parlatması (Traffic Polishing)
  - Trafik şekillendirme host tarafında yapılır; uygulamanın ürettiği trafik, network'e gönderilmeden önce yeniden düzenlenir.
  - Trafik parlatması (holistik) ise ISS (servis sağlayıcı) tarafından tüm network genelinde yapılır; uygulamadan bağımsız, tüm topoloji ölçeğinde.
  - İki temel kontrol noktası: ortalama hız ve burstiness (ani artışlar).

- ATM (Asynchronous Transfer Mode) Ağları
  - 53 byte'lık hücre (cell) yapısı; klasik paket switching'in daha mikro versiyonu.
  - Sabit boyutlu hücre yapısı sayesinde QoS uygulaması daha kolaydır; günümüzde DSL/ADSL altyapısında ATM Adaptation Layer olarak hâlâ kullanılır.

- Servis Tipleri (CBR, VBR, ABR)
  - **CBR (Constant Bit Rate)**: Sabit bant genişliği. Örnek: telefon (4 kHz insan sesi, Nyquist teoremi → 8 kHz örnekleme).
  - **VBR (Variable Bit Rate)**: Değişken bant genişliği. İki türü:
    - Real-time VBR: Video conferencing (anlık bitrate ihtiyacı değişir, sahne içeriğine bağlı).
    - Non real-time VBR: Video on demand (client buffer sayesinde gerçek zamanlılık ortadan kalkar).
  - **ABR (Available Bit Rate)**: Kalan kapasite. File transfer gibi gecikme toleransı yüksek uygulamalar için.

- Noisy Neighbor Kavramı
  - Bazı uygulamalar (file sharing) tüm mevcut bant genişliğini kullanmaya meyillidir; diğer uygulamaları (video konferans) olumsuz etkiler.
  - Apartman komşusu benzetmesi: Yan dairede yüksek sesle müzik dinleyen biri, diğerlerini rahatsız eder.
  - Çözüm: uygulama tipine göre uygun kalite parametreleri uygulamak ve uygulama tipini tanımlayabilmek (P2P vs VoIP gibi).

## Hocanın Özellikle Vurguladığı Kısımlar

- Matristeki "low/medium/high" anlamı
  - Tablodaki "low, medium, high" ifadeleri mutlak bant genişliği değerlerini değil, o kritere olan hassasiyeti gösterir. Yani "bandwidth low" demek, "bant genişliği bu uygulama için kritik değil" demektir.
  - Bu ayrım sınavda sıkça karıştırılır; net anlaşılmalıdır.

- COVID-19 döneminin network trafiğine etkisi
  - Online eğitim, video konferans, streaming gibi uygulamaların artması ABR kapasitesini azaltmıştır. Aynı hızda internet bağlantısı olsa bile, başka uygulamalar (streaming) devredeyken download yavaşlayabilir.

- Bant genişliği asimetri
  - ADSL'de download yüksek, upload düşüktür; çünkü ev kullanıcısı ağırlıklı olarak servis alır. Bu bilinçli bir tasarım kararıdır.

- Sınavda çıkabilecek bilgiler
  - Hoca, telefon için 8 kHz / CBR, video conferencing için real-time VBR, dosya transferi için ABR gibi eşleştirmelerin sınavda çıkabileceğini vurgular.

## Kısa Tekrar Notları

- QoS 4 kriteri: bandwidth, delay, jitter, loss
- Uygulamalar farklı hassasiyetlere sahip; kategorize edilebilir
- Traffic shaping: host tarafında; Traffic polishing: ISS tarafında
- CBR (sabit), VBR (değişken - real-time ve non real-time), ABR (kalan)
- Nyquist teoremi: 4 kHz ses için 8 kHz örnekleme → telefon CBR 8 kHz
- Noisy neighbor: fazla kaynak tüketen uygulama, diğerlerini etkiler
- ATM: 53 byte hücre, QoS dostu

## Detaylı Açıklamalar

Quality of Service, farklı uygulamaların farklı ihtiyaçlarına cevap vermek için geliştirilmiş bir dizi mekanizmadır. Temel fikir: network kaynaklarını (bant genişliği, buffer, CPU) uygulamaların ihtiyacına göre paylaştırmak.

Hocanın matris açıklaması önemlidir. Matrisin satırları uygulamaları (e-posta, dosya paylaşımı, web, audio, video), sütunları kriterleri (bant genişliği, gecikme, jitter, kayıp) gösterir. Hücrelerdeki "low, medium, high" ise o uygulamanın o kritere olan hassasiyetini belirtir. Örneğin, telefon için "bandwidth low, delay high, jitter high, loss low"tur — yani telefon için bant genişliği çok kritik değildir (çok az bant yeter) ama gecikme ve jitter çok kritiktir (insan kulağı gecikmeyi fark eder).

Trafik şekillendirme iki yerde yapılabilir. Host tarafında, uygulamanın çıkışında bir "shape" mekanizması konur; bu, paketleri belirli bir profile göre düzenler. ISP tarafında ise tüm network ölçeğinde bir kontrol uygulanır. İkincisi daha karmaşıktır çünkü farklı uygulamaların, farklı kullanıcıların trafiğini dengelemek gerekir.

CBR, VBR, ABR kavramları ATM'den gelir. Günümüzdeki uygulamalar bu kategorilere eşlenebilir. CBR için en iyi örnek telefon: insan sesi 4 kHz ile sınırlıdır, Nyquist'e göre 8 kHz örnekleme yeterlidir, 64 kbps PCM (G.711) sabit bir bant genişliği gerektirir. VBR için en iyi örnek video: sahnenin karmaşıklığına göre anlık bitrate değişir. ABR ise file transfer gibi uygulamalar içindir — bant genişliği arttıkça daha hızlı, azaldıkça daha yavaş çalışır.

Noisy neighbor kavramı modern ağlarda özellikle bulut bilişim ve veri merkezlerinde önemlidir. Bir uygulama, diğerlerinin kaynağını tüketirse, "komşu" etkisi yaratır. Aynı fiziksel linki veya router'ı paylaşan uygulamalar birbirlerini yavaşlatabilir. QoS, bu durumu uygulama tiplerini tanıyarak ve farklı politikalar uygulayarak çözmeye çalışır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
