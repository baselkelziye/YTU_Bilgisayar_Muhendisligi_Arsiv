# Ders 10 Lab Çalışma Özeti

## Genel Konular

- Ağ saldırılarının gözlemlenmesi
  - ARP, DNS, TCP/UDP ve HTTP trafiği araçlarla izlenerek paket seviyesinde güvenlik etkileri incelenir.
- SQL injection veya web güvenliği uygulamalarının sürdürülmesi
  - Web uygulamasında zafiyetli girdi noktaları, HTTP istekleri ve veritabanı etkileri pratik olarak değerlendirilir.
- Trafik analizi
  - Paket başlıkları, kaynak/hedef adresleri, portlar ve protokol alanları saldırı davranışını anlamada kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Paket düzeyi gözlem teoriyi somutlaştırır
  - ARP, IP, TCP ve DNS alanları doğrudan incelendiğinde protokol zayıflıkları daha anlaşılır hale gelir.
- Uygulama saldırıları ağ izlerinden takip edilebilir
  - Web formu, HTTP isteği, SQL sorgusu ve dönen cevap arasında ilişki kurulmalıdır.

## Kısa Tekrar Notları

- Ağ trafiği protokol başlıkları üzerinden analiz edilir.
- ARP ve DNS cevapları güvenlik açısından kritik ipucu taşır.
- HTTP istekleri web saldırılarını görünür kılar.
- Port ve protokol bilgisi filtreleme ve tespit için kullanılır.

## Detaylı Açıklamalar

- Laboratuvar düzeyinde ağ güvenliği, paketlerin başlık ve içerik alanlarını inceleyerek anlaşılır. Kaynak/hedef IP, MAC adresi, port numarası, TCP bayrakları ve DNS cevapları saldırı türünü sınıflandırmada kullanılır.
- Web güvenliği uygulamalarında tarayıcıdan çıkan HTTP isteği ile sunucunun veritabanına gönderdiği sorgu arasında bağlantı kurmak önemlidir. Bu ilişki kurulmadan SQL injection, CSRF veya cookie tabanlı saldırıların etkisi tam anlaşılamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
