# Ders 9 Çalışma Özeti

## Genel Konular

- Ağ güvenliğine giriş
  - Oturum yönetimi konusu ağ güvenliği bağlamına bağlanarak katmanlı ağ mimarisi üzerinden güvenlik değerlendirmesi yapılır.
  - Fiziksel katman, veri bağlantı katmanı, ağ katmanı, taşıma katmanı ve uygulama katmanı arasındaki görev ayrımı açıklanır.
- IP adresleme
  - IPv4 ve IPv6 adreslerinin gösterimi, kısaltılması ve ağ/host ayrımı ele alınır.
  - IP adresi mantıksal adresleme sağlar; paketlerin ağlar arasında yönlendirilmesi bu adreslere dayanır.
- TCP ve UDP kavramları
  - TCP bağlantılı, sıralı ve güvenilir aktarım sağlamaya çalışır.
  - UDP bağlantısızdır; daha düşük yükle çalışır fakat güvenilirlik ve sıra garantisi vermez.
- DNS yapısı
  - Alan adlarının IP adreslerine çevrilmesi, recursive resolver, authoritative server ve hiyerarşik sorgu mantığı üzerinden incelenir.
  - DNS cevaplarının doğruluğu ve resolver davranışı ağ güvenliği açısından önem taşır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağ katmanlarında güvenlik varsayımı dikkatli kurulmalıdır
  - Alt katmandaki güven eksikliği üst katmandaki protokolü etkileyebilir.
- TCP byte stream olarak düşünülmelidir
  - Gönderilen veri alıcıda aynı parça sınırlarıyla gelmek zorunda değildir.
- DNS yalnız isim çözme değil güvenlik yüzeyidir
  - Yanlış veya manipüle edilmiş DNS cevabı kullanıcıyı yanlış hedefe yönlendirebilir.

## Kısa Tekrar Notları

- IP mantıksal adresleme sağlar.
- TCP bağlantılı ve güvenilir aktarım hedefler.
- UDP bağlantısız ve hafiftir.
- DNS isimleri IP adreslerine çözer.
- Recursive resolver cevabı bulmak için hiyerarşide sorgu yapar.

## Detaylı Açıklamalar

- Ağ güvenliği, tek bir protokolün güvenliği olarak görülmemelidir. Ethernet, IP, TCP/UDP ve DNS gibi katmanlar birlikte çalışır. Bir katmanda yapılan sahtecilik, yönlendirme hatası veya kimlik doğrulama eksikliği üst katmandaki uygulamayı etkileyebilir.
- TCP, uygulamaya kesintisiz byte akışı sunar; alıcı bir seferde bir byte, yüz byte veya bin byte okuyabilir. Bu nedenle uygulama protokolleri kendi mesaj sınırlarını doğru tanımlamalıdır. UDP ise hızlı ve düşük maliyetlidir; fakat kayıp, tekrar veya sıra bozulması uygulama tarafından ele alınmalıdır.
- DNS, kullanıcıların alan adıyla hizmetlere ulaşmasını sağlar. Ancak DNS cevabı yanlışsa kullanıcı doğru alan adını yazmış olsa bile yanlış IP'ye gidebilir. Bu nedenle DNS güvenliği, ağ tabanlı saldırıların anlaşılmasında merkezi öneme sahiptir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
