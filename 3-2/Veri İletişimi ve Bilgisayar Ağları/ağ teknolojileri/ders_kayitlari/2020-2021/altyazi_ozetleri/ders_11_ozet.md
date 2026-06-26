# Ders 11 Çalışma Özeti

## Genel Konular

- Connection Release (Bağlantı Sonlandırma)
  - Bağlantı kurmak kadar sonlandırmak da hassas bir süreçtir; network katmanı güvenilir olmadığı için son pakete kadar verilerin düzgün iletilmesi garanti edilmelidir.
  - Duplex (çift yönlü) haberleşmede her iki yön bağımsız uniplex akışla sağlanır; bu nedenle bir taraf bağlantıyı kapatmak istese, diğer taraftan hâlâ veri akabilir.
  - Asimetric release: A tarafı disconnect isteği gönderir; bu istek B'ye ulaştığında, A→B yönü kapanır ama B→A yönü hâlâ açıktır. B, kendi verisini bitirip sonra kendisi de disconnect gönderir.
  - Symmetric release: İki tarafın aynı anda bağlantıyı kapatmaya karar vermesi gerekir; bu, transport layer'ın tek başına çözemeyeceği bir problemdir (two army problem).

- Two Army Problem (İki Ordu Problemi)
  - Beyaz bayraklılar vadide, siyah bayraklılar iki tarafta (toplam 4 siyah vs 3 siyah).
  - Siyahlar saldırıda başarılı olmak için eş zamanlı saldırmalı; birbirleriyle mesajlaşmaları gerekir.
  - Ancak mesajlaşma vadiden geçer ve beyazlar tarafından görülür.
  - Bu, senkronize kapanma probleminin neden tek başına transport layer ile çözülemeyeceğini gösterir; üst katman (uygulama) müdahalesi gerekebilir.

- Üç Yönlü El Sıkışma ile Bağlantı Sonlandırma
  - 3 mesajlaşma ile bağlantı sonlandırılabilir: DR (Disconnect Request) → DR (karşı taraftan) → ACK.
  - Her iki taraf bir timer başlatır; bu timer, ağda hâlâ dolaşan paketlerin (farklı yollardan farklı gecikmelerle) hedefe ulaşmasını bekleyecek kadar uzun olmalıdır.
  - Normal koşullarda 3-way handshake (kurulumdakine benzer şekilde) bağlantı sonlandırmada da kullanılabilir; ancak kavramsal olarak "3-way handshake" denilince genellikle bağlantı kurulumu kastedilir.

- En Kötü Durum Senaryoları
  - **Senaryo 1**: Final ACK kaybolur. Host2 timer'ı başlatır, tekrar retransmission yapar.
  - **Senaryo 2**: DR kaybolur. Host1 tekrar retransmission yapar.
  - **Senaryo 3**: Ağ çok kötü durumda; her iki taraf da timeout'a uğrar. Bu durumda her iki taraf bağlantıyı zorla kapatır; olası veri kaybı kabul edilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- 3-way handshake'in bağlantı kurulumu ile ilişkilendirilmesi
  - Hoca, "3-way handshake" dendiğinde akla ilk gelenin bağlantı kurulumu olduğunu, bu nedenle bağlantı sonlandırmada bu terimin kullanılmaması gerektiğini vurgular. Yanlış kullanım öğrencileri yanıltabilir.

- Two army problem'in önemi
  - Transport layer'ın sınırlarını gösterir: senkronize kapatma sorunu üst katmanın yardımı olmadan çözülemez. Bu, gerçek hayatta da karşımıza çıkan bir problemdir.

- Timer'ın önemi
  - Network'te hâlâ dolaşan paketler için yeterli süre beklenmelidir. Bu süre, network'ün en kötü gecikmesine göre belirlenmelidir; aksi takdirde veri kaybı yaşanır.

## Kısa Tekrar Notları

- Connection release: kurulum kadar hassas
- Asimetric: tek taraf kapatır, diğer taraf verisini bitirir
- Symmetric: iki taraf aynı anda kapatmalı (zor problem)
- Two army problem: senkron kapatmanın imkansızlığı
- 3 mesaj: DR → DR → ACK (3-way handshake benzeri)
- Timer: network'teki paketleri bekleyecek kadar uzun
- Worst case: her iki taraf timeout

## Detaylı Açıklamalar

Bağlantı sonlandırma, bağlantı kurulumu kadar dikkat gerektiren bir süreçtir. Çünkü güvenilir bir bağlantıda, bağlantı sonlandırılmadan önce gönderilen tüm verilerin karşı tarafa ulaşmış olması garanti edilmelidir. Bunu sağlamak için, network'te hâlâ dolaşan paketlerin teslim edilmesi beklenmelidir.

Hoca, duplex haberleşmenin aslında iki ayrı uniplex akıştan oluştuğunu vurgular. Bu nedenle, bir taraf bağlantıyı kapatmak istediğinde, sadece kendi yönündeki akışı durdurur. Karşı taraf hâlâ veri gönderebilir. Karşı taraf verisini bitirip kendi disconnect isteğini gönderdiğinde, bağlantı tamamen sonlanır.

Asimetric release, iki tarafın bağımsız hareket edebildiği bir senaryodur. A disconnect isteği gönderir; B bunu alır ve onaylar. A artık veri göndermeyi durdurur; ama B hâlâ A'ya veri gönderebilir. B de kendi verisini bitirip disconnect isteği gönderdiğinde, bağlantı tamamen kapanır. Bu, pratikte yaygın olan modeldir.

Symmetric release ise daha karmaşıktır. İki tarafın aynı anda kapatmaya karar vermesi gerekir. Ancak bu, two army problemi nedeniyle tek başına transport katmanıyla çözülemez. Çünkü "ben kapatıyorum" mesajı kaybolabilir; karşı taraf "acaba gerçekten kapatıyor mu?" diye emin olamaz. Pratikte, üst katman (uygulama) bu senkronizasyonu sağlar (örn. "Dosya aktarımı tamamlandı, şimdi kapat" mesajı uygulama seviyesinde değiş tokuş edilir).

Two army problem, eş zamanlı karar verme problemlerinin klasik örneğidir. İki taraf, karşı tarafın da aynı anda harekete geçeceğinden emin olmadan harekete geçmemelidir. Ama "emin olma" mesajı da aynı sorunu taşır. Bu, bazı durumlarda üst katman müdahalesi gerektiren bir sınırdır.

3-way handshake (DR → DR → ACK) ile bağlantı sonlandırma, normal koşullarda çalışır. Her iki taraf bir timer başlatır; bu timer, ağda hâlâ dolaşan paketlerin (farklı yollardan farklı gecikmelerle) hedefe ulaşmasını bekleyecek kadar uzun olmalıdır. Ancak ağ çok kötü durumdaysa (her iki taraf da timeout'a uğrarsa), bağlantı zorla kapatılır ve olası veri kaybı kabul edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
