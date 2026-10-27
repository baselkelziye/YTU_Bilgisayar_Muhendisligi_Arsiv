# Ders 12 Çalışma Özeti

## Genel Konular

- Ders 15 Kasım 2021 Pazartesi günü online yapıldı. Hoca dönemin 7. haftası olduğunu söylüyor. Kayıt yaklaşık 1 saat 33 dakika.
- Veri bağlantı katmanının (data link layer) görevleri: çerçeveleme (framing), akış denetimi (flow control), hata denetimi (error control), adresleme, bağlantı yönetimi.
- Bağlantı yönetimi (line discipline):
  - noktadan noktaya hatlar için ENQ/ACK,
  - çok noktalı hatlar için yoklama/seçme (poll/select).
- Akış denetimi:
  - dur ve bekle (stop-and-wait),
  - kayan pencere (sliding window).
- Hat kullanım oranı (link utilization) hesabı ve $a$ parametresi.
- Hata denetimi ve otomatik yeniden gönderim isteği (ARQ, Automatic Repeat reQuest):
  - dur ve bekle ARQ,
  - N geri dön (Go-Back-N),
  - seçici ret / seçici yineleme (Selective Reject / Selective Repeat).
- Sırtlama (piggybacking).
- Vize duyurusu ve Cihan Hoca'nın bu grupla son dersi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış denetiminin amacı, alıcının alabileceğinden fazla veriye maruz kalmasını engellemektir.
- Alıcının boğulmasının nedenleri:
  - İki uç farklı hızlarda çalışabilir.
  - Alıcının çerçeve başına yaptığı iş göndericininkinden fazla olabilir.
  - Alıcı daha zayıf bir sistem olabilir (CPU, RAM).
- Tampon (buffer) dolarsa çerçeveler düşürülür. Her yeniden gönderim hat kapasitesini boşa harcar.
- Tek atlamalık (single hop) mesafede akış denetimini veri bağlantı katmanı yapar. Araya başka ağlar girdiğinde bu iş taşıma katmanına düşer. O zaman sorun alıcının kapasitesi değil, aradaki ağların yoğunluğudur.
- Bir mesaja cevap gelmediğinde iki ihtimal vardır: mesaj hiç gitmemiştir ya da cevap yolda kaybolmuştur. Gönderici bu ikisini ayırt edemez. Hoca bunu "lütfen unutmayın" diye vurguluyor.
- Çözüm, belli bir süre sonra (zaman aşımı, timeout) aynı mesajı yeniden göndermektir.
- Yoklama/seçme düzeninde hattı her zaman birincil (primary) istasyon yönetir. Hangi ikincilin (secondary) ne zaman konuşacağına o karar verir.
- Dur ve bekle, mesafe uzadıkça hattı çok verimsiz kullanır.
- Kayan pencerede pencere boyutu $2^n$ değil, $2^n - 1$ seçilir. Aksi halde gelen ACK'nın hangi çerçeveyi kastettiği belirsiz kalır.
- Pencere $W \ge 2a + 1$ seçilirse gönderici pencere bitmeden ilk ACK'yı alır ve hat (kuramsal olarak) %100 kullanılır.
- Go-Back-N'de alıcı, hatalı çerçeveden sonra gelenleri hiç değerlendirmez. Bunun nedeni gerçekleme kolaylığıdır. Ek tampon, sıralama ve zamanlayıcı gerekmez.
- Veri bağlantı katmanının bir kısmı ağ kartında gerçeklenir. Tampon ve zamanlayıcı kartın maliyetini artırdığı için basit yöntemler daha çok tercih edilir.
- Hoca düşünme sorusu bıraktı: Selective Repeat'i ne zaman, Go-Back-N'i ne zaman kullanırsınız? Hata algılama/düzeltme sorusunda olduğu gibi hattın özelliklerini birlikte düşünmenizi istiyor.

## Kısa Tekrar Notları

- **ENQ/ACK:** Noktadan noktaya hat. Bir uç ENQ gönderir, karşı uç ACK veya NAK ile cevap verir. Veri gönderilir, her çerçeve onaylanır, en sonda EOT ile bağlantı kapatılır.
- **Poll:** Birincil, ikincillere tek tek "gönderecek verin var mı?" diye sorar. Verisi olan veriyle, olmayan NAK ile cevap verir.
- **Select:** Birincil, veri göndermek istediği ikincile adresli bir SEL çerçevesi gönderir. İkincil hazırsa ACK, değilse NAK döner.
- **Dur ve bekle:** Her çerçeveden sonra ACK beklenir.
- **$a$ parametresi:** $a = \dfrac{t_{prop}}{t_{frame}} = \dfrac{d / v}{L / R}$
- **Dur ve bekle verimi:** $U = \dfrac{1}{1 + 2a}$
- **Kayan pencere verimi:** $W \ge 2a+1$ ise $U = 1$, aksi halde $U = \dfrac{W}{2a+1}$.
- **Sıra numarası:** $n$ bit ile $0 \ldots 2^n - 1$ arası numaralar. Numaralar mod $2^n$ ile döner.
- **ACK numarası:** Alıcının beklediği bir sonraki çerçevenin numarasıdır. "ACK 2", "0 ve 1 geldi, 2'yi bekliyorum" demektir.
- **Go-Back-N:** Hata olan çerçeveden itibaren hepsi yeniden gönderilir.
- **Selective Repeat:** Yalnız hatalı çerçeve yeniden gönderilir. Alıcı sıra dışı (out of order) gelenleri tamponlayıp sıraya koymalıdır.
- **Piggybacking:** Çift yönlü iletişimde ACK bilgisi ayrı çerçeve yerine karşı yöne giden veri çerçevesinin içine konur.

## Detaylı Açıklamalar

### Bağlantı Yönetimi

Hat yapısı ikiye ayrılır:

- **Noktadan noktaya (point-to-point):** Geniş alan ağlarında (WAN) yaygındır. Uç noktalardaki hatlar çoğullanıp tek hatta toplanır.
- **Çok noktalı (multipoint):** Yerel ağlarda (LAN) yaygındır. Ortam paylaşılır. Aynı anda iki istasyon gönderirse çarpışma (collision) olur.

**ENQ/ACK akışı:**

1. Bağlantı kurulumu: Gönderici ENQ yollar, alıcı ACK ile cevap verir.
2. Veri aktarımı: Her veri çerçevesi için ACK beklenir.
3. Bağlantının sonlandırılması: Gönderici EOT (End of Transmission) yollar.

Karşı taraf art arda olumsuz cevap verirse bir süre beklenir (back-off) ve sonra yeniden denenir.

**Poll/Select:** Hat bir veri yoluna (bus) bağlı çok sayıda cihazdan oluşur. Tüm ikinciller aynı hattı dinlediği için her poll ve select çerçevesine ikincilin adresi yazılır. Böylece yalnız ilgili istasyon cevap verir.

- **Select akışı:** SEL → ACK → veri → ACK → … → EOT.
- **Poll akışı:** POLL → (verisi varsa) veri → ACK → … → EOT. Verisi yoksa NAK.
- Birincil, belli bir süre sonra konuşmakta olan ikincile zaman aşımı çerçevesi gönderip iletişimi kesebilir.

### Dur ve Bekle Akış Denetimi

Günlük hayattan örnek: Kasada telefon numaranızı söylerken üç rakam söyleyip kasiyerin yazmasını beklersiniz, sonra devam edersiniz.

Alıcı yavaşlamak isterse ACK'ları geciktirir. Böylece gönderici alıcının hızına iner.

Bir çerçevenin gönderilip onaylanması için geçen süre:

$$T = t_{frame} + t_{prop} + t_{ack} + t_{prop}$$

ACK çerçevesi çok küçük olduğu için $t_{ack}$ ihmal edilir:

$$T \approx t_{frame} + 2\,t_{prop}, \qquad U = \frac{t_{frame}}{t_{frame} + 2\,t_{prop}} = \frac{1}{1+2a}$$

Burada $t_{prop} = d/v$ (mesafe / yayılma hızı), $t_{frame} = L/R$ (çerçeve boyu / veri hızı).

**Örnek (slayttan):** İki nokta arası $d = 1000$ km $= 10^6$ m. Veri hızı $R = 155{,}52$ Mbps. Yayılma hızı $v = 2 \times 10^8$ m/s. Çerçeve boyu $L = 424$ bit. Dur ve bekle ile hat kullanım oranı nedir?

$$t_{prop} = \frac{10^6}{2\times 10^8} = 5 \text{ ms}$$

$$t_{frame} = \frac{424}{155{,}52\times 10^6} \approx 2{,}726\ \mu\text{s}$$

$$a = \frac{t_{prop}}{t_{frame}} \approx 1834$$

$$U = \frac{1}{1 + 2a} \approx \frac{1}{3669} \approx 2{,}7 \times 10^{-4}$$

Hat zamanının yalnız yaklaşık on binde 2,7'si kullanılıyor. Sayılar Python ile doğrulandı.

### Kayan Pencere Akış Denetimi

Gönderici her çerçeve için ayrı ayrı beklemek yerine, pencere içindeki çerçeveleri art arda gönderir.

- Her iki uçta da pencere kadar tampon gerekir.
- Çerçeveler numaralanır. $n$ bitlik numara alanı ile $2^n$ farklı numara verilir.
- Göndericide işaretçinin solu "gönderilmiş", sağı "gönderilmeyi bekleyen" çerçevelerdir. Gönderilmiş olmak onaylanmış olmak demek değildir.
- ACK gelince onaylanan çerçeveler tampondan atılır ve pencere sağa kayar.
- Alıcı her çerçeve için ayrı ACK gönderebileceği gibi birkaçını tek ACK ile onaylayabilir.

**Örnek akış ($n = 3$, numaralar 0–7, pencere 7):**

1. Gönderici Data 0 ve Data 1'i yollar.
2. Alıcı ikisini de alır ve tek bir ACK 2 gönderir ("2'yi bekliyorum").
3. Gönderici pencereyi iki kaydırır.
4. Data 2 gelir, alıcı ACK 3 gönderir, pencere bir kayar.

**Pencere neden $2^n - 1$?** Pencere $2^n = 8$ olsun. Gönderici 0'ı yollar ve ACK 1 alır. Sonra 1, 2, …, 7, 0 çerçevelerini (8 çerçeve) yollar. Ardından yeniden ACK 1 gelirse iki anlam taşıyabilir:

- 8 çerçevenin hepsi alındı ve alıcı yeni turdaki 1'i bekliyor.
- Hiçbiri alınmadı ve önceki ACK 1 tekrarlandı.

Gönderici bu ikisini ayırt edemez. Pencere 7 seçilince bu belirsizlik ortadan kalkar.

**Pencere boyu ve verim:** Gönderici $W$ çerçeveyi $W \cdot t_{frame}$ sürede yollar. İlk ACK $t_{frame} + 2\,t_{prop}$ sonra gelir. Normalize edersek bu süre $1 + 2a$ çerçeve süresidir.

$$U = \begin{cases} 1, & W \ge 2a+1 \\ \dfrac{W}{2a+1}, & W < 2a+1 \end{cases}$$

### Hata Denetimi ve ARQ

Alıcı, geçen hafta görülen VRC, CRC gibi yöntemlerle hatayı fark eder. Hatalı çerçeve için NAK gönderir ve gönderici aynı çerçeveyi yeniden yollar.

Hata durumları:

- Veri çerçevesi bozuk gelir: Alıcı NAK gönderir.
- Veri çerçevesi kaybolur: Alıcı hiçbir şey göndermez. Göndericinin zamanlayıcısı dolar ve çerçeve yeniden gönderilir.
- ACK veya NAK kaybolur: Gönderici de zaman aşımıyla yeniden gönderir.

Bu yüzden ARQ'da her iki yöntemde de gönderici tarafında zamanlayıcı (timer) gerekir.

**Go-Back-N örneği:** Gönderici 0, 1, 2, 3, 4'ü yollar. Alıcı 0, 1, 2'yi alıp RR 3 (Receive Ready 3) der. 3 bozuk gelir ve alıcı REJ 3 gönderir. O sırada gönderici 4 ve 5'i de yollamıştır. Gönderici bunları bırakıp 3'ten itibaren hepsini yeniden yollar.

Başka bir senaryoda alıcı 0 ve 1'den sonra 3'ü görürse 2'nin kaybolduğunu anlar ve REJ 2 gönderir.

Gönderici tüm pencereyi yollayıp hiç ACK alamazsa zaman aşımından sonra P (poll) biti 1 olan bir çerçeve göndererek alıcının durumunu sorar. Alıcı "bir sonraki beklediğim çerçeve şu" diye cevap verir.

**Selective Repeat örneği:** Gönderici 0, 1, 2, 3, 4'ü yollar. SREJ 2 gelir. Bu, 0 ve 1'in doğru alındığı, 2'nin hatalı olduğu anlamına gelir. Gönderici yalnız 2'yi yeniden yollar ve kaldığı yerden 5, 6 diye devam eder. Çerçeveler sıra dışı gittiği için alıcı onları tamponlayıp sıraya koymalıdır.

**Piggybacking:** A'dan B'ye ve B'den A'ya aynı anda veri gidiyorsa B, A'ya vereceği ACK'yı kendi veri çerçevesinin içine koyabilir. Hat daha verimli kullanılır. Gönderilecek veri oluşsun diye ACK biraz geciktirilebilir. Bu yüzden zaman aşımı süreleri biraz daha uzun tutulur.

### Duyurular

- Önümüzdeki hafta (8. hafta) vize haftası. Sınav yüz yüze yapılacak, uzaktan sınav yok.
- Sınav ders saatinde değil. Saatini ve dersliğini sınav takviminden kontrol edin, güncellemeleri takip edin.
- COVID nedeniyle sınav süresi kısıtlı. Geç kalmayın.
- Sınav çoktan çok seçmeli. Birden fazla şık doğru olabilir. Bir yanlış şık işaretlenirse soru yanlış sayılır. Dört şıklı sorularda üç yanlış, beş şıklı sorularda dört yanlış bir doğruyu götürür.
- Bu ders Cihan Hoca'nın bu grupla son dersi. Vizeden sonra online grup Furkan Hoca ile devam edecek.

### Ders sonrası notlar

- **Veri hızı:** Hoca örneği okurken veri hızını "55.52 Mbps" diye söylüyor. Slayttaki değer 155,52 Mbps'tir (OC-3/STM-1 hızı). 424 bit de ATM hücresinin boyudur (53 bayt).
- **Slayttaki yuvarlama:** Slayt $a \approx 1850$ ve $U = 1/(1+3700) \approx 2{,}7\times 10^{-4}$ veriyor. Kesin değerler $a \approx 1834$ ve $U \approx 2{,}73\times 10^{-4}$'tür. Sonuç değişmiyor.
- **ENQ/ACK akışı:** Hoca bağlantı kurulumunu anlatırken "ENQ'ya cevap olarak bir Enquiry alıyorsunuz" diyor. Cevap ENQ değil, ACK'dır.
- **Mod alma:** Hoca numaraların "n'e göre modülü alınarak" döndüğünü söylüyor. $n$ bitlik numara alanında işlem mod $2^n$ ile yapılır.
- **Selective Repeat pencere sınırı:** Derste yalnız Go-Back-N için geçerli $2^n - 1$ sınırı anlatıldı. Selective Repeat'te pencere en fazla $2^{n-1}$ olabilir. Aksi halde alıcı yeni çerçeveyi eski çerçevenin tekrarı sanabilir.
- **$W \ge 2a+1$ ifadesi:** Hoca bu koşulu "bant genişliği–gecikme çarpımının iki katı artı 1" diye anlatıyor. Doğrusu, $a$'nın çerçeve sayısı cinsinden ifade edilmiş yayılma gecikmesi olduğudur. Yani $a$, bant genişliği–gecikme çarpımının çerçeve boyuna bölünmüş halidir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
