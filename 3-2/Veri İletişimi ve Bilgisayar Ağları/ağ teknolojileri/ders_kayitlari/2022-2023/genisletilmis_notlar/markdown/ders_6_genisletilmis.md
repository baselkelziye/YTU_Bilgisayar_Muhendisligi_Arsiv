# Ders 6 Genişletilmiş Notu: Taşıma Katmanı: rdt 3.0, Boru Hattı Protokolleri ve TCP

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. rdt 3.0: Hata ve Kayıp Olan Kanal
- 2. rdt 3.0'ın Başarımı ve Boru Hattı
- 3. Go-Back-N
- 4. Seçici Tekrar
- 5. TCP'ye Genel Bakış ve Segment Yapısı
- 6. TCP Sıra Numaraları ve ACK'ler
- 7. TCP Gidiş-Dönüş Süresi ve Zaman Aşımı
- 8. TCP'de Güvenilir Veri Aktarımı
- 9. TCP Akış Denetimi
- 10. TCP Bağlantı Yönetimi
- Örnek Sorular

## 1. rdt 3.0: Hata ve Kayıp Olan Kanal

Ders, önceki haftada başlanan "kendi güvenilir veri aktarım protokolümüzü geliştirme" çalışmasının devamıyla açıldı. rdt 1.0'da alttaki kanalın kusursuz ve kayıpsız olduğu varsayılmıştı. rdt 2.0 ve sonraki sürümler bit hatalarını sağlama toplamı (checksum), ACK/NAK ve sıra numarasıyla ele almıştı. Bu derste kanal varsayımı bir adım daha ağırlaştırılır.

### 1.1 Yeni kanal varsayımı

Yeni varsayım şudur: alttaki kanal paketleri, yani hem veri paketlerini hem ACK'leri kaybedebilir. Sağlama toplamı, sıra numaraları, ACK'ler ve yeniden iletim işe yarar ama yetmez (ekrandan, 00:10:00). Çünkü kaybolan bir paket için alıcı hiçbir şey göndermez ve gönderici sonsuza kadar bekleyebilir.

Hoca çözümü insan konuşmasına benzetti: karşınızdakine bir şey söylediğinizde cevap gelmezse bir süre bekler, sonra sözünüzü tekrarlarsınız. Protokolde de gönderici "makul" bir süre ACK bekler. Bu sürede ACK gelmezse ya gönderilen paket kaybolmuştur ya da ACK kaybolmuştur. Her iki durumda da gönderici paketi yeniden gönderir.

> **Hocanın vurgusu:** Bekleme süresinin "makul" olması en önemli parametredir. Süre çok kısa olursa paket gereksiz yere yeniden gönderilir; çok uzun olursa kanal verimli kullanılmaz.

Paket kaybolmamış, sadece gecikmişse yeniden iletim alıcıda kopya (duplicate) paket oluşturur. Bu sorun rdt 2.1'de zaten çözülmüştü: sıra numarası aynıysa alıcı paketin kopya olduğunu anlar ve taşıma katmanı onu atar. Bunun için alıcı ACK içinde hangi paketi onayladığını, yani paketin sıra numarasını belirtmelidir. Makul süreyi ölçmek için geri sayım zamanlayıcısı (countdown timer) kullanılır; süre dolunca zamanlayıcı göndericiye bir kesme üretir ve gönderici paketi yeniden yollar.

### 1.2 rdt 3.0 gönderici sonlu durum makinesi

Sıra numarası olarak yalnız 0 ve 1 kullanılır, yani 1 bit yeterlidir. Gönderici makinesinin dört durumu vardır (ekrandan, 00:15:00):

- "Wait for call 0 from above": uygulama katmanından 0 numaralı paket için veri bekleme.
- "Wait for ACK0": 0 numaralı paketin onayını bekleme.
- "Wait for call 1 from above": 1 numaralı paket için veri bekleme.
- "Wait for ACK1": 1 numaralı paketin onayını bekleme.

İlk geçişte uygulamadan veri gelir (`rdt_send(data)`). Protokol veriyi, sıra numarasını (0) ve sağlama toplamını paketler, alttaki güvenilmez kanala verir ve zamanlayıcıyı başlatır (ekrandan, 00:15:00):

```text
rdt_send(data)
---------------------------------------
sndpkt = make_pkt(0, data, checksum)
udt_send(sndpkt)
start_timer
```

Bu sırada makine "ACK0 bekle" durumuna geçer. Hatasız ve doğru numaralı ACK gelirse zamanlayıcı durdurulur ve makine "üstten çağrı 1 bekle" durumuna geçer. Zaman aşımı olursa paket yeniden gönderilir ve zamanlayıcı yeniden başlatılır. Bozuk bir paket ya da yanlış numaralı ACK gelirse gönderici beklemeyi sürdürür; paketi zaman aşımı yeniden gönderecektir. 1 numaralı paket için aynı işlemler simetrik biçimde tekrarlanır: veri gelince sıra numarası 1, veri ve sağlama toplamı gönderilir ve zamanlayıcı başlatılır; ACK1 gelince zamanlayıcı durdurulur ve makine yeniden 0 konumuna döner.

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross slaytlarında rdt 3.0'ın alıcı makinesi ayrıca çizilmez, çünkü rdt 2.2'nin alıcısı değişmeden kullanılabilir. Alıcı kopya paketi zaten sıra numarasından tanıyıp atmaktadır.

### 1.3 rdt 3.0 çalışırken: dört senaryo

Hoca durum makinesinin dört durumu nasıl karşıladığını zaman çizelgeleriyle gösterdi.

- (a) Kayıpsız iletim: pkt0 gönderilir, alıcı alır ve ack0 yollar; gönderici ack0'ı alınca pkt1'i gönderir, alıcı ack1 yollar. Sıra numarası 1 bit olduğu için sonra yeniden 0'a dönülür.
- (b) Paket kaybı: pkt0 ve ack0 sorunsuz gider gelir. pkt1 yolda kaybolur. Gönderici pkt1'i gönderirken zamanlayıcıyı başlatmıştı; süre dolunca pkt1'i yeniden gönderir. Alıcı bu kez pkt1'i alır ve ack1 yollar.
- (c) ACK kaybı: pkt0 ve ack0 sorunsuzdur, pkt1 alıcıya ulaşır ama ack1 kaybolur (ekrandan, 00:20:00). Gönderici süre dolunca pkt1'i yeniden gönderir. Alıcıda iki kez pkt1 vardır; protokol kopyayı yok sayar ve ack1'i yeniden yollar. Gönderici ack1'i alınca sonraki pakete geçer.
- (d) Erken zaman aşımı / gecikmiş ACK: Zamanlayıcı süresi, ACK'in dönmesi için gereken süreden kısaysa ne olur? pkt1 alınmış ve ack1 gönderilmiştir ama ack1 henüz göndericiye ulaşmadan süre dolar ve pkt1 yeniden gönderilir. Bu sırada ilk ack1 gelir ve gönderici pkt0'ı (sonraki paketi) gönderir. Alıcı kopya pkt1'i alır ve ack1'i yeniden yollar. Gönderici bu kopya ack1'i yok sayar.

Hoca toparlarken protokolün basit bir dur-ve-bekle (stop-and-wait) protokolü olduğunu söyledi: paket gönderilir, zamanlayıcı başlatılır ve makul süre ACK beklenir; süre dolarsa paket yeniden gönderilir. Bazı durumlarda kopya paket ve kopya ACK oluşur ve protokole bunları yok sayan bir yöntem eklenmiştir.

## 2. rdt 3.0'ın Başarımı ve Boru Hattı

### 2.1 Gönderici kullanımı

Protokol doğru çalışıyor ama başarımı nasıl? Göndericinin kullanımı (utilization) $U_{sender}$, göndericinin gönderme işiyle meşgul olduğu zamanın oranıdır (ekrandan, 00:25:00).

Örnek: 1 Gbps bağlantı, 15 ms yayılma gecikmesi, 8000 bitlik paket (ekrandan, 00:25:00).

- Verilen: $L = 8000$ bit, $R = 10^9$ bit/s, tek yön yayılma gecikmesi 15 ms.
- Paketin kanala iletim süresi:

$$D_{trans} = \frac{L}{R} = \frac{8000\ \text{bit}}{10^9\ \text{bit/s}} = 8\ \mu s$$

- Zaman çizelgesi: gönderici ilk biti $t = 0$'da, son biti $t = L/R$'de gönderir. İlk bit alıcıya yayılma gecikmesi kadar sonra ulaşır. Son bit ulaşınca alıcı ACK gönderir. ACK göndericiye $t = RTT + L/R$ anında ulaşır.
- $RTT = 2 \times 15 = 30$ ms (ara adım eklendi).
- Kullanım:

$$U_{sender} = \frac{L/R}{RTT + L/R} = \frac{0{,}008\ \text{ms}}{30{,}008\ \text{ms}} \approx 0{,}00027$$

Python ile kontrol: $0{,}008 / 30{,}008 = 0{,}0002666$. Hoca bu başarımı "berbat" (horrible) diye niteledi: 1 Gbps'lik bağlantının yalnız on binde 2,7'si kullanılmaktadır.

> **Ders sonrası not:** Hoca zaman çizelgesini anlatırken bir yerde RTT'yi 15 ms diye söyledi. Slayttaki 15 ms tek yön yayılma gecikmesidir; RTT 30 ms'dir. Hocanın hesapta kullandığı "30 ms + 8 µs" doğrudur. Hoca ayrıca protokolü bir yerde "RDT 2.0" diye andı; söz konusu olan rdt 3.0'dır.

### 2.2 Boru hattı (pipelining)

Çözüm, bir paket gönderip ACK beklemek yerine ACK beklemeden birçok paketi yola çıkarmaktır. Hattaki paket sayısı arttıkça kullanım da artar. Bunun iki sonucu vardır:

- Tek bitlik sıra numarası yetmez; sıra numarası bit sayısı artırılmalıdır.
- Göndericide ve/veya alıcıda tampon gerekir. Bağlantısız ve güvenilmez bir alt katmanda paketler sırası bozuk gelebilir; bunları yeniden sıralamak için tampona koymak gerekir.

Örnek: üç paket gönderilip sonra ACK beklenir (ekrandan, 00:30:00). İlk paketin ACK'i yine $t = RTT + L/R$ anında gelir, ama bu süre içinde üç paket gönderilmiştir:

$$U_{sender} = \frac{3L/R}{RTT + L/R} = \frac{0{,}0024}{30{,}008} = 0{,}00081$$

Yani 3 paketlik boru hattı kullanımı 3 kat artırır (python ile: $0{,}024/30{,}008 = 0{,}00080$).

> **Ders sonrası not:** Slaytta pay $.0024$ diye yazılmıştır. Milisaniye cinsinden doğrusu $3 \times 0{,}008 = 0{,}024$'tür; slayttaki sonuç $0{,}00081$ ise $0{,}024/30{,}008$ ile uyumludur.

Hoca buradan "neden hattaki paket sayısını daha da artırmayalım?" sorusuyla boru hattı protokollerine geçti.

## 3. Go-Back-N

### 3.1 Gönderici penceresi

Go-Back-N'de (N'e geri dön) gönderici N boyutlu bir pencere tanımlar. Penceredeki paketler ACK beklemeden gönderilebilir. Sıra numarası uzayında renkler şöyledir:

- Yeşil: gönderildi ve onaylandı.
- Sarı: gönderildi, henüz onaylanmadı.
- Mavi: pencere içinde, kullanılabilir ama henüz gönderilmedi.
- Beyaz: pencere boyutu aşıldığı için kullanılamaz.

Paketler penceredeki boşluk kadar onaysız gönderilir, sonra ACK beklenir. Bir paket onaylanınca pencere kaydırılır.

Birikimli ACK (cumulative ACK) kullanılır: ACK(n), n dahil olmak üzere n'e kadar bütün paketleri onaylar. ACK(n) gönderilmesi, önceki bütün paketlerin güvenle alındığı anlamına gelir. ACK(n) alınınca gönderici pencereyi n+1'den başlayacak şekilde ilerletir. Yoldaki en eski paket için bir zamanlayıcı tutulur. n paketi için zaman aşımı olursa n paketi ve penceredeki ondan büyük sıra numaralı bütün paketler yeniden gönderilir.

### 3.2 Go-Back-N alıcısı

Bu örnekte paketlerin sırayla alınması gerektiği ve alıcıda tampon olmadığı varsayılır (ekrandan, 00:35:00).

- Alıcı yalnız ACK gönderir: o ana kadar doğru alınan, en yüksek sıralı (in-order) sıra numarasını onaylar. Bu kopya ACK'ler üretebilir.
- Alıcının yalnız `rcv_base` değerini, yani penceresinin tabanını hatırlaması yeter.
- Sırası bozuk paket geldiğinde alıcı onu atabilir (tamponlamaz) ya da tamponlayabilir; bu bir uygulama (implementation) kararıdır. Tampon yoksa paket atılır ve en yüksek sıralı paket yeniden onaylanır.

Slayttaki çizimde `rcv_base` alınmayı bekleyen ilk paketi gösterir; öncekiler alınmış ve onaylanmıştır. Pembe paketler alınmış ama sırası bozuk olduğu için onaylanmamıştır; tampon olmadığı için yerleştirilemezler.

### 3.3 Go-Back-N örneği (pencere boyutu 4)

Pencere 4 olduğundan 4 paket ACK beklemeden gönderilebilir.

- Gönderici pkt0, pkt1, pkt2, pkt3'ü gönderir.
- Alıcı pkt0'ı alır, ack0 yollar; pkt1'i alır, ack1 yollar.
- pkt2 kaybolur. pkt3 alıcıya ulaşır ama sırası bozuktur; atılır ve alıcı güvenle aldığı en yüksek numaralı paket için ack1'i yeniden yollar.
- Gönderici ack0 ve ack1'i alınca pencereyi kaydırır ve pkt4, pkt5'i gönderir. Alıcı bunları da sırası bozuk olduğu için atar ve her biri için yine ack1 yollar. Gönderici bu kopya ack1'leri yok sayar.
- Kayıp paketin zamanlayıcısı dolunca gönderici o paketi ve penceredeki sonraki bütün paketleri yeniden gönderir.

> **Ders sonrası not:** Hoca zaman aşımı adımını anlatırken "packet 1 timeout, send packet 1, ..." dedi. Örnekte kaybolan pkt2'dir; zaman aşımına uğrayan ve yeniden gönderilen paketler büyük olasılıkla standart slayttaki gibi pkt2, pkt3, pkt4, pkt5'tir.
<!-- BELİRSİZ: Go-Back-N örnek slaytının (yaklaşık 00:36-00:38) karesi yok; adımlar altyazıdan ve standart Kurose-Ross çizimiyle tutarlılıktan kuruldu. -->

Hoca bu yaklaşımın kusurunu vurguladı: alıcıda tampon olmadığı ve sırası bozuk paketler atıldığı için, alıcının aslında almış olduğu paketler gereksiz yere yeniden gönderilir.

## 4. Seçici Tekrar

### 4.1 Fikir

Seçici tekrarda (selective repeat) alıcı doğru alınan her paketi tek tek onaylar. Bunun için alıcının tamponu olmalı ve sırası bozuk paketleri tampona koymalıdır. Gönderici her onaysız paket için ayrı bir zamanlayıcı tutar ve yalnız ACK'i gelmeyen paketi yeniden gönderir.

Gönderici ve alıcının ayrı pencereleri vardır (ekrandan, 00:40:00). Göndericinin görünümünde `send_base` pencerenin tabanını, `nextseqnum` gönderilecek sonraki sıra numarasını gösterir; pencere boyutu N'dir. Sarı paketler gönderilmiş ama onaylanmamış, yeşiller onaylanmış, maviler kullanılabilir ama henüz gönderilmemiştir. Pencere tabanındaki sarı paketler onaylanmadıkça gönderici pencereyi kaydırmaz; o paketlerin ACK'i gelince pencere kayar.

### 4.2 Gönderici ve alıcı kuralları

Gönderici:

- Üstten veri gelince, penceredeki sonraki sıra numarası kullanılabiliyorsa paketi gönderir ve o paket için zamanlayıcı başlatır.
- n paketi için zaman aşımı olursa yalnız n paketini yeniden gönderir ve onun zamanlayıcısını yeniden başlatır.
- ACK(n) gelirse n paketini alındı diye işaretler. n en küçük onaysız paketse pencere tabanını bir sonraki onaysız sıra numarasına ilerletir.

Alıcı:

- Pencere içindeki n paketi gelirse ACK(n) gönderir.
- Paket sırası bozuksa tampona koyar.
- Sıralı teslim: eksik paket gelince tampondaki paketler sıraya konur ve uygulamaya iletilir, pencere ilerletilir.
- Kopya paketler yok sayılır.

> **Ders sonrası not:** Hoca alıcıyı anlatırken "bütün paketler gelince sıraya koy ve en yüksek sıralı paketi onayla" dedi. Seçici tekrarda alıcı her doğru paketi kendi sıra numarasıyla ayrı ayrı onaylar (gönderici kuralı da ACK(n)'i tek paket için işler); birikimli onay Go-Back-N'e özgüdür.

### 4.3 Seçici tekrar örneği (pencere boyutu 4)

- Gönderici pkt0, pkt1, pkt2, pkt3'ü gönderir. pkt2 kaybolur.
- ack0 ve ack1 göndericiye ulaşır. pkt3 alıcıda tampona konur ve ack3 gönderilir.
- Gönderici pkt4 ve pkt5'i gönderir; alıcı bunları da tampona koyar ve ack4, ack5 yollar. Go-Back-N'den farkı burasıdır: pkt3, pkt4 ve pkt5 atılmaz, tamponlanır.
- ack3 gelse de gönderici pencereyi kaydırmaz, çünkü pencere tabanındaki pkt2 onaylanmamıştır ve pencerenin 4 paketi zaten gönderilmiştir.
- pkt2'nin zamanlayıcısı dolunca yalnız pkt2 yeniden gönderilir; pkt3, pkt4, pkt5 gönderilmez.
- Alıcı pkt2'yi alınca tampondaki pkt3, pkt4, pkt5 ile sıraya koyar ve pkt2'yi onaylar. Gönderici ack2'yi alınca pencereyi 2, 3, 4, 5 alındığı için 6'ya kadar kaydırır.

### 4.4 Seçici tekrar ikilemi

Örnek: sıra numaraları 0, 1, 2, 3 (4 tabanlı sayma), pencere boyutu 3 (ekrandan, 00:45:00).

- (a) Sorun yok: pkt0, pkt1, pkt2 gönderilir ve alınır, ACK'ler göndericiye ulaşır. Gönderici penceresini kaydırıp pkt3'ü gönderir, pkt3 kaybolur, sonra yeni pkt0 gönderilir. Alıcı penceresi kaydığı için 0 numaralı paketi kabul eder; bu gerçekten yeni pakettir.
- (b) Sorun: pkt0, pkt1, pkt2 alınır, alıcı ACK'lerini gönderir ve penceresini 3, 0, 1'e kaydırır; ama üç ACK de kaybolur. Göndericide pkt0'ın zamanlayıcısı dolar ve eski pkt0 yeniden gönderilir. Bu paket, en baştaki pkt0'ın aynısıdır; ama alıcı penceresinde 0 numarası yeni bir paketi temsil ettiği için alıcı onu yeni paket sanıp kabul eder.

> **Hocanın vurgusu:** Gönderici ve alıcı pencereleri eş zamanlı olmalıdır; aksi hâlde (b)'deki sorun çıkar. Bu sorunu önlemek için sıra numarası uzayının boyutu ile pencere boyutu arasında bir ilişki gerekir.

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross'ta bu ilişki, seçici tekrarda pencere boyutunun sıra numarası uzayının yarısından büyük olmaması gerektiği biçiminde verilir. Örnekte sıra numarası uzayı 4 olduğu için pencere en fazla 2 olmalıdır; 3 seçildiği için ikilem doğmuştur.

Hoca ilk saati burada bitirdi ve ikinci saatte gerçek protokol TCP'ye geçti.

## 5. TCP'ye Genel Bakış ve Segment Yapısı

### 5.1 Genel özellikler

İkinci saatte konu yol haritası gösterildi: TCP'nin segment yapısı, güvenilir veri aktarımı, akış denetimi ve bağlantı yönetimi (ekrandan, 01:05:00). Hoca, TCP güvenilir veri aktarımı sağladığı için bir akış denetimi mekanizmasına da ihtiyaç duyduğunu belirtti.

TCP açık bir protokoldür; standart belgeleri RFC 793, 1122, 2018, 5681 ve 7323'tür (ekrandan, 01:10:00). Özellikleri (ekrandan, 01:10:00):

- Noktadan noktaya (point-to-point): bir gönderici, bir alıcı.
- Güvenilir, sıralı bayt akışı: UDP'den farklı olarak "mesaj sınırları" yoktur.
- Tam çift yönlü (full duplex) veri: aynı bağlantıda iki yönlü veri akışı. MSS (maximum segment size): bayt akışı yönetilirken bir segmentteki en büyük veri boyutu.
- Birikimli ACK'ler.
- Boru hattı: bağlantının bant genişliğini iyi kullanmak için; pencere boyutunu TCP tıkanıklık ve akış denetimi belirler.
- Bağlantı yönelimli: veri alışverişinden önce el sıkışma (denetim mesajları alışverişi) göndericinin ve alıcının durumunu ilkler; pencere boyutu, en büyük veri boyutu gibi denetim bilgileri burada değiş tokuş edilir.
- Akış denetimli: gönderici alıcıyı boğmaz.

> **Ders sonrası not:** Altyazıda RFC numarası "393" ve tam çift yönlülük "same direction" diye geçiyor; slaytta doğrusu RFC 793 ve "aynı bağlantıda (same connection) iki yönlü akış"tır.

### 5.2 TCP segment yapısı

Hoca segment başlığının alanlarını sırayla anlattı:

- Kaynak port ve hedef port numaraları (16 bit): TCP birçok uygulamaya hizmet verir; uygulamaları ayırt etmek için çoğullama ve çoğul çözmede (multiplexing/demultiplexing) benzersiz port numaraları kullanılır.
- Sıra numarası (32 bit).
- Onay (ACK) numarası (32 bit) ve A biti: A biti 1 ise ACK numarası geçerlidir.
- Başlık uzunluğu: TCP başlığı değişken uzunluktadır, bu alan uzunluğu verir.
- R, S, F bayrakları: RST bağlantıyı sıfırlama, SYN eşleme (bağlantı kurma), FIN bağlantıyı sonlandırma içindir.
- Alma penceresi (receive window, 16 bit): akış denetimi içindir, bayt cinsindendir; alıcı tamponunun kapasitesini bildirir, böylece alıcı boğulmaz.
- C ve E bitleri: tıkanıklık denetimi ve bildirimi için.
- Acil veri işaretçisi (urgent data pointer): TCP'de pek kullanılmaz.
- Uygulama verisi: değişken uzunluktadır.

<!-- BELİRSİZ: Segment yapısı slaytının karesi yok (yaklaşık 01:10-01:13); alan uzunlukları ve bayrak adları altyazıdan alındı, altyazının bu kısmı kısmen bozuk. Hocanın "RSD flags one byte" sözü bayrakların başlıkta bir bayt içinde yer aldığı anlamında anlaşıldı. -->

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross çiziminde C biti CWR (congestion window reduced), E biti ECE (ECN-echo) bayrağıdır; ikisi de açık tıkanıklık bildirimi (ECN) mekanizmasının parçasıdır. Başlık uzunluğu alanı 4 bittir ve uzunluğu 32 bitlik sözcük sayısı olarak verir.

## 6. TCP Sıra Numaraları ve ACK'ler

TCP'de sıra numarası, segmentteki ilk veri baytının bayt akışındaki numarasıdır. Gönderici penceresinde yine renkler vardır: yeşil gönderilmiş ve onaylanmış, sarı gönderilmiş ama onaylanmamış, mavi henüz gönderilmemiş ama pencere içinde olduğu için gönderilebilir.

ACK numarası, karşı taraftan beklenen sonraki baytın sıra numarasıdır; yani TCP birikimli ACK kullanır. Alıcının sırası bozuk gelen segmentleri nasıl ele alacağı TCP standardında belirtilmez; tamamen uygulayıcıya (implementation) bağlıdır.

### 6.1 Basit Telnet senaryosu

Telnet uygulaması TCP bağlantısı kullanır. Host A ile Host B arasında şu alışveriş olur (ekrandan, 01:15:00):

- Kullanıcı A'da 'C' karakterini yazar. A, `Seq=42, ACK=79, data='C'` gönderir. 42, 'C' verisinin sıra numarasıdır; ACK=79, A'nın B'den 78'e kadar baytları aldığını ve sıradaki baytı (79) beklediğini gösterir.
- B, 'C'nin alındığını onaylar ve 'C'yi geri yankılar: `Seq=79, ACK=43, data='C'`. ACK=43 = 42 + 1, çünkü A'dan bir bayt alınmıştır.
- A, yankılanan 'C'yi onaylar: `Seq=43, ACK=80`. ACK = 79 + 1 = 80, çünkü B'nin gönderdiği bir bayt alınmıştır.

Hoca bu örneğin TCP'nin iki yönlü, tam çift yönlü yapısını gösterdiğini vurguladı: her iki yönde hem sıra numarası hem onay numarası birlikte kullanılır.

> **Ders sonrası not:** Altyazıda sıra numarası bir yerde 52, onay numarası bir yerde 59 diye geçiyor; slayttaki değerler Seq=42 ve ACK=79'dur.

## 7. TCP Gidiş-Dönüş Süresi ve Zaman Aşımı

### 7.1 Zaman aşımı değeri nasıl seçilir?

rdt protokolünde gördüğümüz gibi zamanlayıcı süresi kritiktir. Ağ katmanı güvenilmez hizmet verir ve hız değişkendir, dolayısıyla RTT de değişir. TCP bu yüzden sabit değil değişken bir zamanlayıcı kullanır (ekrandan, 01:20:00):

- Zaman aşımı RTT'den uzun olmalıdır, ama RTT değişkendir.
- Çok kısa: erken zaman aşımı, gereksiz yeniden iletimler.
- Çok uzun: segment kaybına yavaş tepki.

### 7.2 RTT'nin tahmini

TCP o anki RTT'yi SampleRTT olarak ölçer: segmentin gönderilmesinden ACK'in alınmasına kadar geçen süre. Yeniden iletilen segmentler için ölçüm yapılmaz. SampleRTT değişkendir; daha "yumuşak" bir tahmin için yalnız son ölçüm değil son birkaç ölçümün ortalaması alınır (ekrandan, 01:20:00):

$$EstimatedRTT = (1-\alpha)\cdot EstimatedRTT + \alpha \cdot SampleRTT$$

Bu formül üstel ağırlıklı hareketli ortalamadır (EWMA, exponential weighted moving average). Tipik değer $\alpha = 0{,}125$'tir. Hocanın gösterdiği grafikte mavi eğri ölçülen SampleRTT'dir ve çok hızlı dalgalanır; EstimatedRTT bu dalgalanmayı yumuşatır. Yani sonraki tahmin, önceki tahmin ile o anki ölçümün ağırlıklı toplamıdır; $\alpha$ düzeltme katsayısıdır.

### 7.3 Zaman aşımı aralığı

Zaman aşımı aralığı, EstimatedRTT'ye bir "güvenlik payı" eklenerek bulunur. EstimatedRTT'de büyük dalgalanma varsa büyük, küçük dalgalanma varsa küçük güvenlik payı kullanılır (ekrandan, 01:25:00):

$$TimeoutInterval = EstimatedRTT + 4 \cdot DevRTT$$

DevRTT, SampleRTT'nin EstimatedRTT'den sapmasının EWMA'sıdır:

$$DevRTT = (1-\beta)\cdot DevRTT + \beta \cdot |SampleRTT - EstimatedRTT|$$

Tipik değer $\beta = 0{,}25$'tir (ekrandan, 01:25:00).

> **Ders sonrası not:** Hoca DevRTT'yi "derivative RTT" (türev) diye okudu; kısaltma "deviation" (sapma) sözcüğünden gelir ve formüldeki mutlak fark terimi de bunu gösterir.

## 8. TCP'de Güvenilir Veri Aktarımı

### 8.1 TCP gönderici olayları

- Uygulamadan veri alınınca: sıra numaralı segment oluşturulur. Sıra numarası, segmentteki ilk veri baytının bayt akışındaki numarasıdır. Zamanlayıcı çalışmıyorsa başlatılır; zamanlayıcı en eski onaysız segment için düşünülür ve süresi TimeoutInterval'dir.
- Zaman aşımı: zaman aşımına neden olan segment yeniden gönderilir ve zamanlayıcı yeniden başlatılır.
- ACK alınınca: ACK önceden onaylanmamış segmentleri onaylıyorsa, neyin onaylandığı bilgisi güncellenir; hâlâ onaysız segment varsa zamanlayıcı başlatılır.

### 8.2 TCP alıcısında ACK üretimi (RFC 5681)

Hoca RFC 5681'e göre hazırlanmış tabloyu anlattı:

- Beklenen sıra numarasıyla sıralı bir segment geldi ve beklenen sıra numarasına kadar bütün veri zaten onaylanmış: gecikmeli ACK. TCP sonraki segment için 500 ms bekler; sonraki segment gelmezse ACK gönderir (birikimli ACK kullanıldığı için).
- Beklenen sıra numarasıyla sıralı bir segment geldi ve başka bir segmentin ACK'i beklemede: hemen tek bir birikimli ACK gönderilir, iki sıralı segment birlikte onaylanır.
- Beklenenden büyük sıra numaralı, sırası bozuk segment geldi (boşluk tespit edildi): hemen kopya ACK gönderilir; ACK, beklenen sonraki baytın sıra numarasını gösterir.
- Boşluğu kısmen ya da tamamen dolduran segment geldi: segment boşluğun alt ucundan başlıyorsa hemen ACK gönderilir.

### 8.3 Yeniden iletim senaryoları

Kayıp ACK senaryosu (ekrandan, 01:30:00):

- Host A `Seq=92, 8 bytes of data` gönderir (92-99 arası baytlar).
- Host B alır ve `ACK=100` gönderir; 100, 99'a kadar bütün baytların alındığını gösterir.
- ACK=100 kaybolur. A'nın zamanlayıcısı dolar, `Seq=92, 8 bytes of data` yeniden gönderilir.
- B kopyayı alır ve `ACK=100`'ü yeniden gönderir.

Erken zaman aşımı senaryosu (ekrandan, 01:30:00):

- SendBase = 92. A, `Seq=92, 8 bytes of data` ve ardından `Seq=100, 20 bytes of data` gönderir.
- B, ilk segment için `ACK=100`, ikinci segment için `ACK=120` gönderir (100 + 20 = 120).
- ACK'ler gecikir ve ilk segmentin zamanlayıcısı dolar; A, `Seq=92, 8 bytes` segmentini yeniden gönderir.
- A ACK=100'ü alınca SendBase = 100, ACK=120'yi alınca SendBase = 120 olur. Alıcı kopya segment için yine 120'yi onaylar.

<!-- BELİRSİZ: Erken zaman aşımı senaryosunun yeniden iletim kısmı karede henüz açılmamış; adımlar altyazıdan kuruldu. -->

Birikimli ACK'in erken ACK kaybını örtmesi: `Seq=92, 8 bytes` alınır ve `ACK=100` gönderilir; `Seq=100, 20 bytes` alınır ve `ACK=120` gönderilir. ACK=100 kaybolur, ama ACK=120 gelince A, önceki bütün baytların güvenle alındığını anlar. A ACK=100'ü beklemez ve `Seq=120, 15 bytes` göndermeye devam eder.

### 8.4 TCP hızlı yeniden iletim

Kural (ekrandan, 01:35:00): gönderici aynı veri için 3 ek ACK alırsa ("üçlü kopya ACK"), en küçük sıra numaralı onaysız segmenti yeniden gönderir. Onaysız segment büyük ihtimalle kaybolmuştur, bu yüzden zaman aşımı beklenmez.

Örnek (ekrandan, 01:35:00):

- A, `Seq=92, 8 bytes` ve `Seq=100, 20 bytes` ile ardından üç segment daha gönderir.
- `Seq=100, 20 bytes` kaybolur.
- B ilk segment için `ACK=100` gönderir. Sonraki üç segment sırası bozuk geldiği için her biri için yine `ACK=100` gönderir; böylece A'ya 100 numaralı baytın kaybolduğunu bildirir.
- A, üç kopya ACK=100 alınca zamanlayıcının dolmasını beklemeden `Seq=100, 20 bytes` segmentini yeniden gönderir.

Slayttaki açıklamaya göre üç kopya ACK, eksik bir segmentten sonra üç segmentin alındığını gösterir; kayıp büyük olasılıktır, bu yüzden yeniden iletilir. Hoca bunu TCP'nin yeniden iletimi iyileştiren mekanizması olarak sundu.

## 9. TCP Akış Denetimi

Katman çiziminde üstte uygulama, ortada taşıma katmanı (TCP) vardır ve TCP'nin bir alıcı tamponu bulunur. Gönderici paket gönderdikçe tampon dolar; uygulama gelen veriyi tampondan alıp boşaltır. Soru şudur: ağ veriyi, uygulama katmanının soket tamponundan aldığından daha hızlı getirirse ne olur?

Hoca bunu, çok fazla su akan bir kaynaktan su içmeye benzetti: o kadar çok su gelir ki bir yudum bile yutamazsınız.

Akış denetimi, alıcının göndericiyi denetlemesidir: gönderici çok fazla ya da çok hızlı veri göndererek alıcının tamponunu taşırmamalıdır. Bunun için TCP başlığındaki alma penceresi (receive window) alanı kullanılır:

- Alıcı tamponunun toplam boyutu RcvBuffer, içindeki boş alan `rwnd`'dir.
- TCP alıcısı boş tampon alanını (`rwnd`) TCP başlığında bildirir.
- RcvBuffer boyutu soket seçenekleriyle ayarlanır; tipik varsayılan 4096 bayttır. Birçok işletim sistemi alma tamponunu kendiliğinden ayarlar.
- Gönderici, yoldaki onaysız verinin miktarını alınan `rwnd` değeriyle sınırlar.
- Bu, alıcı tamponunun taşmayacağını garanti eder.

<!-- BELİRSİZ: Akış denetimi slaytlarının karesi yok (yaklaşık 01:36-01:39); "4096 bayt" altyazıdan alındı. -->

## 10. TCP Bağlantı Yönetimi

### 10.1 El sıkışma

Veri alışverişinden önce gönderici ve alıcı "el sıkışır" (ekrandan, 01:40:00):

- Bağlantı kurmaya razı olurlar; her biri ötekinin bağlantı kurmaya istekli olduğunu bilir.
- Bağlantı parametrelerinde anlaşırlar; örneğin başlangıç sıra numaraları. Hoca tampon boyutunu ve port numaralarını da örnek olarak saydı.

Bağlantı kurulduktan sonra her iki tarafta bağlantı durumu ESTAB'dır ve bağlantı değişkenleri tutulur: istemciden sunucuya ve sunucudan istemciye sıra numaraları, sunucu ve istemcideki `rcvBuffer` boyutu. İstemci tarafında `Socket clientSocket = newSocket("hostname","port number");`, sunucu tarafında `Socket connectionSocket = welcomeSocket.accept();` ile soketler oluşturulur (ekrandan, 01:40:00).

İnsan konuşması benzetmesinde Alice "konuşalım" der, Bob "tamam" der ve bağlantı kurulur. Bilgisayarda host X "bağlantı istiyorum" der, sunucu "bağlantı kabul edildi" der.

### 10.2 İki yönlü el sıkışmanın sorunları

Kayıpsız ve gecikmesiz durumda iki yönlü el sıkışma çalışır: X bağlantı ister, bağlantı kurulur, X veri gönderir, veri kabul edilir ve bağlantı hatasız kapanır. Ama ağda gecikme ve kayıp vardır:

- Yarı açık bağlantı: bağlantı kurma isteği gecikir, X isteği yeniden gönderir. Sunucu bunu yeni bir bağlantı isteği sanar ve ikinci bir bağlantı açar; onayını gönderir. Ama X böyle bir onay beklememektedir; o bağlantıyı bekleyen bir istemci yoktur.
- Kopya veri kabulü: X bağlantı ister, sunucu kabul eder, X `data(x+1)` gönderir, veri alınır ve iki taraf bağlantıyı kapatır. Gecikmiş bağlantı isteği ve yeniden gönderilmiş `data(x+1)` daha sonra sunucuya ulaşır. Sunucu x'i unutmuştur; isteği yeni bağlantı sanıp ESTAB durumuna geçer ve `data(x+1)`'i yeni veri olarak kabul eder (ekrandan, 01:45:00).

Hoca kopya veri sorununu bir banka hesabı örneğiyle somutlaştırdı: birine 1 milyon TL gönderdiğinizi düşünün; kopya bağlantı ve kopya veri yüzünden aynı transfer ikinci kez yapılabilir.

### 10.3 Üç yönlü el sıkışma

Yarı açık bağlantı ve kopya veri sorunlarının çözümü üç yönlü el sıkışmadır. Başlangıçta her iki taraf LISTEN durumundadır.

- İstemci SYN biti 1 olan bir segmentle kendi başlangıç sıra numarasını (`Seq=x`) sunucuya gönderir.
- Sunucu SYN'i alır; SYN ve ACK bitleri 1, `ACKnum = x+1` ve kendi sıra numarası `Seq=y` olan bir segment gönderir. SYN biti eşleme içindir; bu segment sunucunun bağlantıyı kabul ettiğini gösterir.
- İstemci bunu alınca ACK biti 1, `ACKnum = y+1` olan segmenti gönderir; bu segment veri de taşıyabilir. Sunucu bunu alınca bağlantıyı kurulmuş (ESTAB) sayar.

Hoca bunu kaya tırmanışına benzetti: tırmanan kişi daha yukarı atlamak istediğinde aşağıda ipi tutan kişiye seslenir, o da ipi tuttuğunu bildirir; ikisi de karşısındakinin hazır olduğundan emin olmadan hareket etmez.

<!-- BELİRSİZ: Üç yönlü el sıkışma slaytının karesi yok ve altyazının 01:47:12 sonrası kısmı Whisper tekrarıyla bozuk; tırmanış benzetmesinin devamı okunamıyor. -->

### 10.4 Bağlantının kapatılması

İstemci ve sunucu bağlantının kendi taraflarını ayrı ayrı kapatır: FIN biti 1 olan bir TCP segmenti gönderilir (FIN, finalize bayrağı). Karşı taraf aldığı FIN'e ACK ile yanıt verir. Ders bu konunun başında sona erdi.

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross'ta FIN alan taraf ACK'ini kendi FIN'iyle birleştirebilir; eşzamanlı FIN alışverişleri de ele alınabilir. FIN'i son onaylayan taraf bir süre TIMED_WAIT durumunda bekler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): 1 Gbps bağlantı, 15 ms yayılma gecikmesi ve 8000 bitlik paketle çalışan dur-ve-bekle (rdt 3.0) protokolünde paketin iletim süresi ve göndericinin kullanımı nedir?

> **Çözüm (derste verildi):** $D_{trans} = L/R = 8000/10^9 = 8\ \mu s = 0{,}008$ ms. $RTT = 2 \times 15 = 30$ ms. $U_{sender} = \dfrac{L/R}{RTT + L/R} = \dfrac{0{,}008}{30{,}008} \approx 0{,}00027$.

**Soru 2** (ekrandan, 00:30:00): Aynı bağlantıda ACK beklemeden 3 paket gönderen bir boru hattı protokolünde göndericinin kullanımı nedir?

> **Çözüm (derste verildi):** $U_{sender} = \dfrac{3L/R}{RTT + L/R} = \dfrac{3 \times 0{,}008}{30{,}008} \approx 0{,}0008$. Kullanım dur-ve-beklenin 3 katıdır.

**Soru 3** (ekrandan, 00:45:00): Sıra numaraları 0, 1, 2, 3 ve pencere boyutu 3 olan seçici tekrar protokolünde, pkt0-pkt2 alındıktan sonra bütün ACK'ler kaybolursa ne olur?

> **Çözüm (derste verildi):** Alıcı penceresini 3, 0, 1'e kaydırmıştır. Gönderici zaman aşımında eski pkt0'ı yeniden gönderir; alıcı 0 numarasını penceresinde yeni paket olarak gördüğü için kopyayı yeni veri diye kabul eder. Gönderici ve alıcı pencereleri eş zamanlı olmadığı için hata oluşur; sıra numarası uzayı ile pencere boyutu arasında bir ilişki gerekir.

**Soru 4** (ekrandan, 01:15:00): Telnet senaryosunda A, `Seq=42, ACK=79, data='C'` gönderiyor. B'nin yankı segmentinin ve A'nın son onay segmentinin Seq ve ACK değerleri nedir?

> **Çözüm (derste verildi):** B: `Seq=79, ACK=43` (A'dan 1 bayt alındı, 42 + 1). A: `Seq=43, ACK=80` (B'den 1 bayt alındı, 79 + 1).

**Soru 5** (ekrandan, 01:30:00): A, `Seq=92, 8 bytes` ve `Seq=100, 20 bytes` segmentlerini gönderiyor. B'nin göndereceği ACK numaraları nedir ve ACK'ler gelince A'nın SendBase değeri nasıl değişir?

> **Çözüm (derste verildi):** İlk segment 92-99 baytlarını taşır, ACK=100. İkinci segment 100-119 baytlarını taşır, ACK=120. SendBase önce 92'den 100'e, sonra 120'ye ilerler.

**Soru 6** (ekrandan, 01:35:00): TCP göndericisi `Seq=100, 20 bytes` segmentinin ardından gönderdiği segmentler için üç kopya `ACK=100` alıyor. Gönderici ne yapar?

> **Çözüm (derste verildi):** Hızlı yeniden iletim: zaman aşımını beklemeden en küçük sıra numaralı onaysız segmenti, yani `Seq=100, 20 bytes` segmentini yeniden gönderir.

## Dersin Toparlaması

Ders, güvenilir veri aktarım protokolünün son sürümü rdt 3.0 ile başladı. Kayıp kanalda zamanlayıcı ve 1 bitlik sıra numarası doğru çalışma için yeterlidir, ama dur-ve-bekle yaklaşımı 1 Gbps'lik bir bağlantının yalnız on binde 2,7'sini kullanır. Bu verimsizlik boru hattı fikrine götürdü. Go-Back-N birikimli ACK ve tek zamanlayıcıyla basit bir alıcı sunar ama kayıpta bütün pencereyi yeniden gönderir. Seçici tekrar her paketi ayrı onaylayıp alıcıda tamponlayarak bu israfı önler; buna karşılık pencere boyutu sıra numarası uzayına göre seçilmezse eski ve yeni paketler karışır.

İkinci saatte bu ilkelerin gerçek karşılığı olan TCP incelendi: noktadan noktaya, bağlantı yönelimli, tam çift yönlü bir bayt akışı; bayt tabanlı sıra numaraları ve birikimli ACK'ler; EWMA ile tahmin edilen RTT ve buna eklenen güvenlik payıyla hesaplanan zaman aşımı; gecikmeli ACK, kopya ACK ve hızlı yeniden iletim; `rwnd` ile akış denetimi; üç yönlü el sıkışma ve FIN ile bağlantı kapatma. Konu yol haritasına göre sonraki adımlar tıkanıklık denetiminin ilkeleri ve TCP tıkanıklık denetimidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
