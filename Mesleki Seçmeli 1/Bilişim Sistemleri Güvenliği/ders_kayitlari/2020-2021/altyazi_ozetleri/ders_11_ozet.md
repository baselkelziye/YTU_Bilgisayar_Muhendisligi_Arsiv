# Ders 11 Çalışma Özeti

## Genel Konular

- Ağ saldırılarına karşı savunma
  - ARP, BGP, IP, UDP ve TCP gibi protokollerdeki güven varsayımlarının etkileri özetlenir.
  - TLS kullanımı, karma içerik, cookie bayrakları ve güvenli kanalın sınırları değerlendirilir.
- IP spoofing önleme
  - Ingress filtering ile servis sağlayıcı kendi ağından çıkan paketlerin kaynak IP adreslerini denetler.
  - Sahte kaynak IP kullanımının engellenmesi DDoS ve amplification saldırılarını azaltır.
- Firewall
  - Kaynak/hedef IP, protokol, kaynak/hedef port gibi alanlara göre trafik filtreleme yapılır.
  - Durum bilgili firewall içeriden dışarıya kurulan bağlantıları takip ederek dönüş trafiğine izin verebilir.
- IDS/IPS
  - Saldırı tespit sistemleri ağ trafiğini veya host davranışını analiz ederek şüpheli örüntüleri yakalar.
  - İmza tabanlı ve davranış tabanlı yaklaşımlar farklı güçlü ve zayıf yönlere sahiptir.
- VPN
  - IPsec ve OpenVPN gibi teknolojiler ağlar veya istemciler arasında şifreli tünel kurar.
  - VPN gizlilik ve bütünlük sağlar; ancak uç sistem güvenliğini tek başına garanti etmez.

## Hocanın Özellikle Vurguladığı Kısımlar

- TLS tek başına yeterli değildir
  - Sayfanın bir kısmı HTTPS, bir kısmı HTTP ise karma içerik güvenliği bozar.
- Ingress filtering yaygın uygulanmadığında küresel etki oluşur
  - Bir ağın sahte IP'ye izin vermesi başka ağlara saldırı olarak dönebilir.
- Firewall kuralı doğru bağlamda yazılmalıdır
  - Sadece port engellemek her uygulama saldırısını durdurmaz.

## Kısa Tekrar Notları

- Ingress filtering sahte kaynak IP'yi engeller.
- Firewall paket başlıklarına ve duruma göre karar verir.
- IDS saldırıyı tespit eder; IPS engellemeye çalışır.
- VPN şifreli tünel kurar.
- TLS karma içerikle zayıflayabilir.

## Detaylı Açıklamalar

- Sahte IP adresi, yansıtma ve amplifikasyon saldırılarının temel araçlarından biridir. Servis sağlayıcılar kendi müşterilerinden çıkan trafiğin kaynak IP'sini denetlerse, kendilerine ait olmayan adresle dışarı çıkan paketleri durdurabilir. Bu mekanizma ağ genelinde yaygın uygulanmadığında saldırganlar açık kalan ağlardan yararlanır.
- Firewall, ağ sınırında veya host üzerinde çalışabilir. Basit kurallar belirli porta gelen trafiği düşürebilir; daha gelişmiş durum bilgili firewall bağlantı durumunu takip eder. Uygulama katmanındaki SQL injection gibi saldırılar için yalnız port filtresi yetmez; içerik analizi veya uygulama güvenliği gerekir.
- IDS/IPS sistemleri bilinen saldırı imzalarını, anormal trafik hacmini veya protokol dışı davranışı tespit etmeye çalışır. VPN ise iletişimi şifreleyerek dış gözlemciye karşı koruma sağlar; fakat uç nokta ele geçirilmişse tünelin güvenliği saldırıyı engellemez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
