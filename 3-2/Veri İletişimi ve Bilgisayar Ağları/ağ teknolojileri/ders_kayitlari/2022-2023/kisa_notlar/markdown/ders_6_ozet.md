# Ders 6 Çalışma Özeti

## Genel Konular

- rdt 3.0: hem bit hatası hem paket kaybı olan kanal
  - Yeni kanal varsayımı: alttaki kanal veri paketlerini ve ACK'leri kaybedebilir. Sağlama toplamı (checksum), sıra numarası, ACK ve yeniden iletim yardımcıdır ama yetmez (ekrandan, 00:10:00).
  - Çözüm insan konuşmasına benzer: gönderen "makul" bir süre ACK bekler. Bu sürede ACK gelmezse paket ya da ACK kaybolmuş olabilir; paket yeniden gönderilir.
  - Süre çok kısa seçilirse paket gereksiz yere yeniden gönderilir; çok uzun seçilirse kanal verimli kullanılmaz.
  - Paket sadece gecikmişse yeniden iletim kopya (duplicate) paket üretir. Alıcı bunu sıra numarasından anlar ve atar. Alıcı ACK içinde hangi paketi onayladığını (sıra numarasını) belirtmelidir.
  - Geri sayım zamanlayıcısı (countdown timer) makul süre dolunca gönderene kesme üretir.
- rdt 3.0 gönderici sonlu durum makinesi
  - Sıra numarası olarak 0 ve 1 kullanılır (1 bit). Dört durum vardır: "üstten çağrı 0 bekle", "ACK0 bekle", "üstten çağrı 1 bekle", "ACK1 bekle" (ekrandan, 00:15:00).
  - Uygulamadan veri gelince `sndpkt = make_pkt(0, data, checksum)`, `udt_send(sndpkt)` ve `start_timer` yapılır; makine "ACK0 bekle" durumuna geçer (ekrandan, 00:15:00).
  - Doğru ACK gelirse zamanlayıcı durdurulur ve sonraki duruma geçilir. Zaman aşımında paket yeniden gönderilir ve zamanlayıcı yeniden başlatılır. Bozuk paket ya da yanlış ACK beklemeyi sürdürür.
- rdt 3.0 çalışma senaryoları
  - (a) Kayıpsız iletim; (b) paket kaybı: pkt1 kaybolur, zaman aşımında yeniden gönderilir.
  - (c) ACK kaybı: ack1 kaybolur, pkt1 yeniden gönderilir; alıcı kopyayı atar ve ack1'i yeniden yollar (ekrandan, 00:20:00).
  - (d) Erken zaman aşımı / gecikmiş ACK: zamanlayıcı ACK'in dönüş süresinden kısaysa pkt1 gereksiz yere yeniden gönderilir; kopya paket ve kopya ACK oluşur, protokol bunları yok sayar.
- rdt 3.0'ın (dur-ve-bekle) başarımı
  - Gönderici kullanımı $U_{sender}$: göndericinin gönderme ile meşgul olduğu zamanın oranı.
  - Örnek: 1 Gbps bağlantı, 15 ms yayılma gecikmesi, 8000 bitlik paket (ekrandan, 00:25:00).
  - $D_{trans} = L/R = 8000 / 10^9 = 8\ \mu s$.
  - $U_{sender} = \dfrac{L/R}{RTT + L/R} = \dfrac{0{,}008}{30{,}008} \approx 0{,}00027$ (milisaniye cinsinden). Başarım çok kötüdür.
- Boru hattı (pipelining)
  - Tek paket gönderip ACK beklemek yerine ACK beklemeden birden çok paket gönderilir. Bunun için sıra numarası bit sayısı artırılmalı, göndericide ve/veya alıcıda tampon olmalıdır.
  - 3 paketlik boru hattı kullanımı 3 kat artırır: $U_{sender} = \dfrac{3L/R}{RTT + L/R} = \dfrac{0{,}0024}{30{,}008} = 0{,}00081$ (ekrandan, 00:30:00).
- Go-Back-N (N'e geri dön)
  - Gönderici N boyutlu bir pencere kullanır: yeşil (gönderildi ve onaylandı), sarı (gönderildi, onay bekliyor), mavi (kullanılabilir, henüz gönderilmedi), beyaz (pencere dışı, kullanılamaz).
  - Birikimli ACK: ACK(n), n dahil olmak üzere n'e kadar bütün paketleri onaylar. ACK(n) gelince pencere n+1'den başlayacak şekilde kaydırılır.
  - En eski yoldaki paket için tek zamanlayıcı vardır. Zaman aşımında n paketi ve penceredeki ondan büyük sıra numaralı bütün paketler yeniden gönderilir.
  - Alıcı: yalnız ACK gönderir; o ana kadar doğru alınan en yüksek sıralı (in-order) sıra numarasını onaylar. Kopya ACK üretebilir; yalnız `rcv_base` değerini hatırlaması yeter. Sırası bozuk paketi atabilir ya da tamponlayabilir (uygulama kararıdır); derste tampon yok varsayılmıştır (ekrandan, 00:35:00).
  - Örnek (pencere 4): pkt2 kaybolur; pkt3 sırası bozuk olduğu için atılır ve ack1 yeniden gönderilir. Zaman aşımında kayıp paket ve ardından gelenler yeniden gönderilir.
- Seçici tekrar (Selective Repeat)
  - Alıcı doğru gelen her paketi tek tek onaylar; sırası bozuk paketleri tamponlar.
  - Göndericide her paket için ayrı zamanlayıcı vardır; zaman aşımında yalnız o paket yeniden gönderilir. ACK(n) gelince paket onaylandı diye işaretlenir; n en küçük onaysız paketse pencere tabanı sonraki onaysız sıra numarasına ilerler.
  - Göndericinin ve alıcının pencereleri ayrıdır (ekrandan, 00:40:00).
  - Örnek (pencere 4): pkt2 kaybolur; pkt3, pkt4, pkt5 tamponlanır ve ayrı ayrı onaylanır. Zaman aşımında yalnız pkt2 yeniden gönderilir; sonra pencere kayar.
- Seçici tekrar ikilemi
  - Sıra numaraları 0, 1, 2, 3, pencere boyutu 3 (ekrandan, 00:45:00).
  - (a) pkt3 kaybolur, sonra yeni pkt0 gelir: sorun yok.
  - (b) Bütün ACK'ler kaybolur; zaman aşımında eski pkt0 yeniden gönderilir. Alıcı penceresini kaydırdığı için bunu yeni pkt0 sanar ve kabul eder. Bu iki durumu alıcı ayırt edemez; sıra numarası uzayı ile pencere boyutu arasında bir ilişki gerekir.
- TCP'ye genel bakış
  - RFC 793, 1122, 2018, 5681, 7323 (ekrandan, 01:10:00).
  - Noktadan noktaya (bir gönderici, bir alıcı); güvenilir, sıralı bayt akışı (mesaj sınırı yok); tam çift yönlü (aynı bağlantıda iki yönlü akış); MSS: en büyük segment boyutu.
  - Birikimli ACK; boru hattı (pencere boyutunu tıkanıklık ve akış denetimi belirler); bağlantı yönelimli (veri alışverişinden önce el sıkışma ile denetim bilgisi alışverişi); akış denetimli (gönderici alıcıyı boğmaz).
- TCP segment yapısı
  - 16 bitlik kaynak ve hedef port numaraları (çoğullama/çoğul çözme için), 32 bitlik sıra numarası ve 32 bitlik onay (ACK) numarası, A biti (ACK geçerli).
  - Başlık uzunluğu alanı (başlık değişken uzunluktadır), RST, SYN, FIN bayrakları, 16 bitlik alma penceresi (bayt cinsinden, akış denetimi için), C ve E bitleri (tıkanıklık bildirimi), acil veri işaretçisi, değişken uzunlukta uygulama verisi.
  <!-- BELİRSİZ: segment yapısı slaytının karesi yok; alan adları altyazıdan ve standart Kurose-Ross slaytından alındı. -->
- TCP sıra numaraları ve ACK'ler
  - Sıra numarası: segmentteki ilk veri baytının bayt akışındaki numarası. ACK numarası: karşı taraftan beklenen sonraki baytın sıra numarası (birikimli ACK).
  - Sırası bozuk segmentin nasıl ele alınacağını TCP standardı belirlemez; uygulayıcıya bırakılmıştır.
  - Telnet örneği: A, `Seq=42, ACK=79, data='C'` gönderir; B, `Seq=79, ACK=43, data='C'` ile yankılar; A, `Seq=43, ACK=80` ile onaylar (ekrandan, 01:15:00).
- TCP gidiş-dönüş süresi ve zaman aşımı
  - Zaman aşımı RTT'den uzun olmalı ama RTT değişkendir. Çok kısa: erken zaman aşımı, gereksiz yeniden iletim. Çok uzun: segment kaybına yavaş tepki (ekrandan, 01:20:00).
  - SampleRTT: segmentin gönderilmesinden ACK gelene kadar ölçülen süre; yeniden iletilen segmentler ölçülmez.
  - $EstimatedRTT = (1-\alpha)\,EstimatedRTT + \alpha\,SampleRTT$, üstel ağırlıklı hareketli ortalama (EWMA), tipik $\alpha = 0{,}125$.
  - $TimeoutInterval = EstimatedRTT + 4\,DevRTT$; $DevRTT = (1-\beta)\,DevRTT + \beta\,|SampleRTT - EstimatedRTT|$, tipik $\beta = 0{,}25$ (ekrandan, 01:25:00).
- TCP gönderici ve alıcı olayları
  - Gönderici: uygulamadan veri gelince sıra numaralı segment oluşturur, zamanlayıcı çalışmıyorsa başlatır (zamanlayıcı en eski onaysız segment içindir). Zaman aşımında o segmenti yeniden gönderir ve zamanlayıcıyı yeniden başlatır. Önceden onaysız segmentleri onaylayan ACK gelince durumu günceller; hâlâ onaysız segment varsa zamanlayıcıyı başlatır.
  - Alıcı (RFC 5681): beklenen sıralı segment geldi ve öncesi onaylıysa gecikmeli ACK (500 ms sonraki segment beklenir); başka bir segmentin ACK'i bekliyorsa hemen tek birikimli ACK; beklenenden büyük sıra numaralı segment gelirse (boşluk) hemen kopya ACK; boşluğu dolduran segment gelirse hemen ACK.
- TCP yeniden iletim senaryoları
  - Kayıp ACK: `Seq=92, 8 bytes` gönderilir, `ACK=100` kaybolur; zaman aşımında segment yeniden gönderilir (ekrandan, 01:30:00).
  - Erken zaman aşımı: `Seq=92, 8 bytes` ve `Seq=100, 20 bytes` gönderilir; `ACK=100` ve `ACK=120` gelir, SendBase önce 100 sonra 120 olur (ekrandan, 01:30:00).
  - Birikimli ACK önceki ACK kaybını örter: `ACK=100` kaybolsa da `ACK=120` gelince gönderici 120'den devam eder.
- TCP hızlı yeniden iletim
  - Gönderici aynı veri için 3 ek ACK (üçlü kopya ACK) alırsa en küçük sıra numaralı onaysız segmenti zaman aşımını beklemeden yeniden gönderir (ekrandan, 01:35:00).
  - Örnek: `Seq=100, 20 bytes` kaybolur, alıcı sürekli `ACK=100` yollar; üçüncü kopya ACK'te segment yeniden gönderilir.
- TCP akış denetimi
  - Ağ veriyi, uygulamanın soket tamponundan aldığından hızlı getirirse tampon taşar. Gönderici, alıcının tamponunu boğmamalıdır.
  - Alıcı boş tampon alanını (`rwnd`) TCP başlığındaki alma penceresi alanında bildirir. Tampon boyutu soket seçenekleriyle ayarlanır (varsayılan 4096 bayt); birçok işletim sistemi bunu kendiliğinden ayarlar. Gönderici yoldaki onaysız veriyi `rwnd` ile sınırlar; böylece tampon taşmaz.
- TCP bağlantı yönetimi
  - Veri alışverişinden önce iki taraf el sıkışır: bağlantı kurmaya razı olduklarını bilir, başlangıç sıra numarası gibi parametrelerde anlaşır. Her iki tarafta bağlantı durumu ESTAB, sıra numaraları ve `rcvBuffer` boyutu tutulur (ekrandan, 01:40:00).
  - İki yönlü el sıkışmanın sorunları: gecikmiş/yeniden gönderilmiş bağlantı isteği yarı açık bağlantıya yol açar; ayrıca kopya veri yeni veri sanılıp kabul edilebilir (ekrandan, 01:45:00).
  - Üç yönlü el sıkışma: istemci SYN biti 1, `Seq=x` gönderir; sunucu SYN ve ACK biti 1, `ACKnum=x+1`, `Seq=y` gönderir; istemci ACK biti 1, `ACKnum=y+1` gönderir ve bağlantı kurulur.
  - Bağlantıyı kapatma: istemci ve sunucu kendi taraflarını FIN biti 1 olan segmentle kapatır, karşı taraf aldığı FIN'e ACK ile yanıt verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Zaman aşımı süresinin "makul" olması
  - Hoca bunu protokolün en önemli parametresi olarak vurguladı: kısa olursa gereksiz yeniden iletim, uzun olursa kanalın verimsiz kullanımı olur. TCP'de bu yüzden RTT sürekli tahmin edilir.
- Dur-ve-bekle protokolünün başarımı
  - 1 Gbps bağlantıda kullanım yaklaşık 0,00027 çıkar; hoca bu başarımı "berbat" diye niteledi ve boru hattına geçişin gerekçesi olarak kullandı.
- Göndericinin ve alıcının pencerelerinin eş zamanlı olması
  - Seçici tekrar ikileminde hoca, iki tarafın penceresi uyuşmazsa alıcının eski paketi yeni paket sanacağını vurguladı.
- Bankacılık örneği
  - Kopya bağlantı ve kopya veri sorunu para transferinde aynı işlemin iki kez yapılmasına yol açabilir; üç yönlü el sıkışma bu yüzden gereklidir.
- Hızlı yeniden iletim
  - Üç kopya ACK, eksik segmentten sonra üç segmentin alındığını gösterir; gönderici zaman aşımını beklemez.

## Kısa Tekrar Notları

- rdt 3.0 = checksum + 1 bitlik sıra numarası + ACK + zamanlayıcı; kopyalar sıra numarasıyla atılır.
- Dur-ve-bekle: $U = (L/R)/(RTT + L/R)$; örnekte $8\ \mu s / 30{,}008\ ms \approx 0{,}00027$.
- Boru hattı: n paket ACK beklemeden gönderilir, kullanım n kat artar; daha fazla sıra numarası biti ve tampon gerekir.
- Go-Back-N: birikimli ACK, tek zamanlayıcı, zaman aşımında pencerenin tamamı yeniden gönderilir, alıcı sırası bozuk paketi atar.
- Seçici tekrar: tek tek ACK, paket başına zamanlayıcı, yalnız kayıp paket yeniden gönderilir, alıcı tamponlar; pencere sıra numarası uzayına göre büyük olursa ikilem oluşur.
- TCP: noktadan noktaya, güvenilir sıralı bayt akışı, tam çift yönlü, MSS, birikimli ACK, boru hattı, bağlantı yönelimli, akış denetimli.
- TCP sıra numarası bayt sayar; ACK numarası beklenen sonraki bayttır.
- $EstimatedRTT$: EWMA, $\alpha = 0{,}125$; $TimeoutInterval = EstimatedRTT + 4\,DevRTT$, $\beta = 0{,}25$.
- Gecikmeli ACK 500 ms; boşlukta hemen kopya ACK; üç kopya ACK'te hızlı yeniden iletim.
- Akış denetimi: alıcı `rwnd` (boş tampon) bildirir, gönderici onaysız veriyi bununla sınırlar.
- Üç yönlü el sıkışma: SYN(x) → SYN+ACK(y, x+1) → ACK(y+1); kapatma FIN ve ACK ile.

## Detaylı Açıklamalar

- rdt 3.0 neden zamanlayıcıya ihtiyaç duyar?
  - rdt 2.x yalnız bit hatalarına karşı tasarlanmıştı; kanal paket kaybetmez varsayılıyordu. Paket ya da ACK kaybolduğunda gönderici sonsuza kadar bekleyebilir. rdt 3.0 bu yüzden her gönderimde zamanlayıcı başlatır. Süre dolunca paket yeniden gönderilir. Kaybolan şey ACK ise ya da paket yalnız gecikmişse alıcıya aynı paket iki kez ulaşır; 1 bitlik sıra numarası bunun kopya olduğunu gösterir, alıcı veriyi atar ama ACK'i yeniden gönderir.
- Dur-ve-bekle başarım hesabı
  - Verilenler: $R = 1$ Gbps $= 10^9$ bit/s, $L = 8000$ bit, tek yön yayılma gecikmesi 15 ms, dolayısıyla $RTT = 30$ ms. İletim süresi $L/R = 8\ \mu s = 0{,}008$ ms. Gönderici $t = 0$'da ilk biti, $t = L/R$'de son biti gönderir; ACK $t = RTT + L/R$'de gelir. Kullanım $U = 0{,}008 / 30{,}008 \approx 0{,}000267$, yani gönderici zamanın yaklaşık on binde 2,7'sinde meşguldür (python ile doğrulandı).
  - Ders sonrası not: Hoca bir yerde RTT'yi 15 ms diye söyledi; slayttaki 15 ms tek yön yayılma gecikmesidir, RTT 30 ms'dir. Hocanın hesapta kullandığı 30 ms + 8 µs doğrudur.
- Go-Back-N ile seçici tekrarın farkı
  - Go-Back-N'de alıcı basittir: tampon tutmaz, yalnız beklenen paketi kabul eder, sırası bozuk geleni atar ve son sıralı paketi yeniden onaylar. Bedeli, kayıp bir paketten sonra gelen ve aslında doğru alınmış paketlerin de yeniden gönderilmesidir. Seçici tekrar bu israfı önler: alıcı sırası bozuk paketleri tamponlar ve tek tek onaylar, gönderici yalnız zaman aşımına uğrayan paketi yeniden gönderir. Bunun için her paketin kendi zamanlayıcısı ve alıcıda tampon gerekir.
  - Ders sonrası not: Hoca seçici tekrar alıcısını anlatırken bir yerde "en yüksek sıralı paket onaylanır" dedi; seçici tekrarda alıcı her doğru paketi kendi sıra numarasıyla tek tek onaylar, birikimli onay Go-Back-N'e ve TCP'ye özgüdür.
- TCP zaman aşımı hesabı
  - SampleRTT çok dalgalıdır; EWMA ile yumuşatılmış EstimatedRTT elde edilir. Yeni ölçümün ağırlığı $\alpha = 0{,}125$'tir. Güvenlik payı RTT'deki dalgalanmayla orantılıdır: dalgalanma büyükse pay büyür. DevRTT, SampleRTT'nin EstimatedRTT'den sapmasının EWMA'sıdır; zaman aşımı EstimatedRTT'ye dört DevRTT eklenerek bulunur.
  - Ders sonrası not: Hoca DevRTT'yi "derivative RTT" diye okudu; kısaltma "deviation" (sapma) sözcüğündendir.
- Üç yönlü el sıkışma neden gerekli?
  - İki yönlü el sıkışmada gecikmiş bir bağlantı isteği sunucuya bağlantı bittikten sonra ulaşırsa sunucu yeni bir bağlantı açar (yarı açık bağlantı) ve yeniden gönderilen veriyi yeni veri sanabilir. Üç yönlü el sıkışmada her iki taraf karşı tarafın başlangıç sıra numarasını onaylar; böylece eski istekler ve kopya veriler ayırt edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
