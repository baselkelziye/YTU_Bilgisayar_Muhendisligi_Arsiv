# Ders 10 Çalışma Özeti

## Genel Konular

- ARP güvenliği
  - IP adresinden MAC adresine dönüşüm ARP ile yapılır.
  - ARP broadcast ve gratuitous ARP mekanizmaları kimlik doğrulama içermediği için sahte ARP duyuruları yapılabilir.
- IP spoofing
  - IP paketlerinde kaynak adres alanı sahte yazılabilir; IP'nin özgün tasarımında kaynak doğrulama yoktur.
  - Sahte kaynak adresi DDoS ve yansıtma saldırılarında kullanılır.
- DNS rebinding ve DNSSEC
  - DNS cevaplarının zaman içinde farklı IP'lere bağlanması web güvenlik sınırlarını zorlayabilir.
  - DNSSEC, DNS verisinin bütünlüğünü ve kaynağını doğrulamaya yönelik mekanizma olarak ele alınır.
- DDoS ve amplification
  - Açık DNS resolver'lar ve UDP tabanlı servisler küçük istekle büyük cevap üretip hedefe yansıtılabilir.
  - Botnet, sahte IP ve yüksek hacimli trafik hizmet kesintisi üretir.
- SYN flood ve SYN cookie
  - TCP handshake sırasında yarım açık bağlantılar kaynak tüketimine yol açabilir.
  - SYN cookie, sunucunun bağlantı durumunu saklamadan doğrulama yapmasını sağlayan savunmadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- ARP ve IP tasarımında güvenlik varsayımı zayıftır
  - Protokoller çalışır ağ varsayımıyla tasarlandığı için kimlik doğrulama sonradan eklenmek zorunda kalır.
- UDP amplification ciddi DDoS aracıdır
  - DNS gibi servisler sahte kaynak IP ile hedefe büyük trafik yönlendirebilir.
- SYN cookie protokol davranışını dikkatli kullanır
  - Sunucu kaynak tüketimini azaltırken TCP handshake mantığını korur.

## Kısa Tekrar Notları

- ARP, IP-MAC eşlemesi yapar.
- Gratuitous ARP kötüye kullanılabilir.
- IP spoofing kaynak adres sahteciliğidir.
- Open DNS resolver amplifikasyon aracı olabilir.
- SYN flood yarım açık bağlantılarla kaynak tüketir.
- SYN cookie durum saklamadan doğrulama sağlar.

## Detaylı Açıklamalar

- ARP protokolünde bir host, belirli IP adresinin hangi MAC adresine ait olduğunu yayınla sorar. Doğru hostun cevap vermesi beklenir; ancak protokol cevap verenin gerçekten o IP'ye sahip olduğunu doğrulamaz. Gratuitous ARP ile hostlar kendi eşleşmelerini duyurabilir; saldırgan bu mekanizmayı yanlış eşleşme yaymak için kullanabilir.
- IP protokolü paket taşımada hedef adrese odaklanır. Kaynak adresin doğruluğu ağ genelinde zorunlu olarak doğrulanmadığında saldırgan sahte kaynak IP kullanabilir. Bu, özellikle UDP tabanlı amplifikasyon saldırılarında hedefe yüksek hacimli cevap yönlendirmek için kullanılır.
- TCP SYN flood saldırısında saldırgan çok sayıda bağlantı başlatır, fakat handshake'i tamamlamaz. Sunucu yarım açık bağlantılar için kaynak ayırdığı için kapasite tükenebilir. SYN cookie, bağlantı bilgisini sunucu belleğinde tutmak yerine doğrulanabilir bir değer olarak istemciye yansıtarak bu riski azaltır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
