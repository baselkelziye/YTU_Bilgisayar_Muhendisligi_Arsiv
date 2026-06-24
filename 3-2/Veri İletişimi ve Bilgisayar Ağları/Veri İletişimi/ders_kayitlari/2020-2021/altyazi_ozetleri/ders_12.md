# Ders 12 Çalışma Özeti

## Genel Konular

- Connectionless ve connection-oriented servisler
  - Connectionless yapıda veri gönderimi öncesinde uçtan uca bağlantı kurulması gerekmez.
  - Connection-oriented yapıda veri aktarımı öncesinde bağlantı veya yol kurma mantığı bulunur.
- Switching kavramı
  - Switching, verinin ağ içindeki ara düğümler üzerinden hedefe yönlendirilmesi problemidir.
  - Veri bağı katmanından ağ katmanına doğru geçişte önemli bir konudur.
- Circuit switching
  - Gönderici ve alıcı arasında veri aktarımı süresince ayrılmış bir yol kurulur.
  - Telefon ağı benzeri yapılarda devre kurma mantığıyla ilişkilidir.
- Space division ve time division
  - Space division, fiziksel anahtarlama elemanlarıyla ayrı yollar kurma fikrine dayanır.
  - Time division, aynı fiziksel yapının zaman dilimlerine bölünerek kullandırılmasıdır.
- Packet switching
  - Veri paketlere bölünür ve ağ içinde taşınır.
  - Hat tamamen tek iletişime ayrılmadığı için kaynak paylaşımı daha esnek olabilir.
- Datagram ve virtual circuit
  - Datagram yapıda her paket bağımsız yönlendirilebilir; paketlerin izlediği yollar ve varış sırası farklı olabilir.
  - Virtual circuit yapıda veri gönderimi için önce mantıksal bir yol belirlenir; paketler bu yol üzerinden taşınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Connectionless ve connection-oriented ayrımı switching yöntemleriyle birlikte düşünülmelidir.
  - Bağlantı kurulup kurulmadığı, paketlerin ağda nasıl davranacağını etkiler.
- Circuit switching kaynak ayırır, packet switching kaynak paylaşır.
  - Bu fark verimlilik, gecikme ve esneklik açısından önemlidir.
- Datagram ve virtual circuit aynı paket anahtarlama ailesinde farklı mantıklardır.
  - Datagram bağımsız paketlere, virtual circuit ise önceden belirlenmiş mantıksal yola dayanır.

## Kısa Tekrar Notları

- Connectionless: ön bağlantı yoktur.
- Connection-oriented: aktarım öncesi bağlantı/yol mantığı vardır.
- Circuit switching ayrılmış devre kullanır.
- Packet switching veriyi paketlere böler.
- Datagram paketleri bağımsız taşır; virtual circuit mantıksal yol kurar.

## Detaylı Açıklamalar

Bu derste veri iletişimi konuları ağ katmanına yaklaşarak servis türleri ve anahtarlama yöntemleriyle tamamlanmıştır. Connectionless servislerde gönderici veriyi ağa bırakır; her paket bağımsız şekilde yönlendirilebilir. Connection-oriented servislerde ise aktarım öncesinde bağlantı veya mantıksal yol kurma fikri vardır.

Circuit switching, iletişim başlamadan önce gönderici ve alıcı arasında ayrılmış bir yol kurulmasına dayanır. Bu yol iletişim boyunca o bağlantıya tahsis edilir. Bu yapı gecikme açısından öngörülebilir olabilir; ancak kaynaklar boş kalsa bile başka iletişimlere kullandırılamayacağı için verimsizlik doğurabilir. Space division ve time division, devre anahtarlamada kaynak ayırmanın farklı yolları olarak ele alınır.

Packet switching'de veri paketlere bölünür. Datagram yaklaşımında her paket ağ içinde bağımsız yönlendirilir; bu nedenle paketler farklı yollardan gidebilir ve hedefe farklı sırada ulaşabilir. Virtual circuit yaklaşımında ise önce uygun bir mantıksal yol kurulur ve paketler bu yol üzerinden ilerler. Böylece paket anahtarlamanın kaynak paylaşımı korunurken bağlantı benzeri bir düzen sağlanır.
