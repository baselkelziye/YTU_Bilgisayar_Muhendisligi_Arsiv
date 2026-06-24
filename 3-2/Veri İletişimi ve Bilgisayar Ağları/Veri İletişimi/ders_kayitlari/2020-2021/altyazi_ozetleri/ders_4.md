# Ders 4 Çalışma Özeti

## Genel Konular

- Data link control
  - Veri bağı katmanı framing, akış kontrolü, hata kontrolü ve bağlantı yönetimi gibi görevleri üstlenir.
  - Gönderilecek veri frame adı verilen parçalara ayrılır.
- Framing
  - Frame başlangıç ve bitişinin belirlenmesi alıcının veriyi doğru ayırabilmesi için gereklidir.
  - Senkronizasyon ve frame sınırlarının korunması veri bağı katmanı kontrolünün temel parçalarındandır.
- Flow control
  - Göndericinin alıcının işleyebileceğinden daha hızlı veri göndermesini engeller.
  - Amaç, alıcının tamponlarının taşmasını ve veri kaybını önlemektir.
- Stop-and-wait
  - Gönderici bir frame yollar ve alıcıdan onay gelmeden yenisini göndermez.
  - Basittir, fakat hat kapasitesini verimsiz kullanabilir.
- Sliding window
  - Gönderici belirli sayıda frame'i onay beklemeden art arda gönderebilir.
  - Window boyutu, aynı anda uçuşta bulunabilecek frame sayısını belirler.
- ACK, NACK ve zaman aşımı
  - ACK doğru alınan frame'i onaylar.
  - NACK veya zaman aşımı, yeniden iletim gereksinimini doğurur.
  - Piggybacking, onay bilgisinin ters yöndeki veriyle birlikte taşınmasıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış kontrolü hız farkı problemidir.
  - Gönderici çok hızlı, alıcı daha yavaşsa veri kaybı oluşabilir.
- Window mantığı stop-and-wait'e göre daha verimlidir.
  - Hat boş kalmadan birden fazla frame gönderilebilir.
- Onay mekanizması sadece hata için değil, iletimin düzeni için de gereklidir.
  - Alıcı neyi aldığını, gönderici de neyi tekrar göndermesi gerektiğini bilmelidir.

## Kısa Tekrar Notları

- Frame, veri bağı katmanının taşıma birimidir.
- Framing, frame sınırlarını belirler.
- Flow control, gönderici ve alıcı hızını dengeler.
- Stop-and-wait basit ama yavaştır.
- Sliding window, birden fazla frame'in aynı anda gönderilmesini sağlar.

## Detaylı Açıklamalar

Bu derste veri bağı katmanı kontrol mekanizmaları üzerinde durulmuştur. Framing, üst katmandan gelen bit dizisinin anlamlı bloklara ayrılmasıdır. Alıcı tarafın hangi bitlerin hangi frame'e ait olduğunu anlaması için başlangıç ve bitiş bilgileri güvenilir biçimde korunmalıdır.

Akış kontrolü, alıcı kapasitesi ile gönderici hızı arasındaki farktan doğar. Stop-and-wait yönteminde gönderici her frame'den sonra onay beklediği için basit bir düzen kurulur. Ancak gecikmenin yüksek olduğu hatlarda bu yaklaşım verimsizdir. Sliding window tekniği, göndericinin bir pencere boyutu kadar frame'i onay beklemeden göndermesine izin vererek hattın kullanımını artırır.

Onay ve yeniden iletim mekanizmaları veri bütünlüğü için önemlidir. ACK doğru alınan frame'i bildirir; NACK, eksik veya hatalı frame için tekrar isteme anlamına gelir. Zaman aşımı da onayın kaybolduğu veya frame'in ulaşmadığı durumları yakalamak için kullanılır.
