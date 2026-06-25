# Ders 5 Çalışma Özeti

## Genel Konular

- Mod 0'ın Tekrarı: Basit Giriş-Çıkış (Simple I/O)
  - Mod 0 herhangi bir handshake mekanizması içermeyen en basit I/O modudur. Porta veri yazmak istendiğinde doğrudan OUT komutuyla yazılır; porttan veri okumak istendiğinde doğrudan IN komutuyla okunur. Karşı tarafın hazır olup olmadığını bekleme veya kontrol etme yoktur. Anlık değer aktarımı yapılır. Örnek olarak porta bağlı LED'ler doğrudan yakılıp söndürülebilir veya porttan buton durumu okunabilir.
- Mod 1: Handshake Mekanizmalı İletişim
  - Mod 1'de portlar arası veri aktarımı handshake (el sıkışma) protokolü ile senkronize edilir. Bir port veri gönderdiğinde karşı tarafa "veri var, alabilecek misin?" sinyali (OBF - Output Buffer Full) gönderilir. Karşı taraf "veriyi aldım" anlamına gelen ACK (Acknowledge) sinyali döndürdüğünde veri aktarımı tamamlanır. Input tarafında ise karşı taraf STB (Strobe) sinyali gönderir, 8255 IBF (Input Buffer Full) sinyali üretir. Bu sinyallerin kombinasyonuyla interrupt oluşur ve mikroişlemci veri okuma/yazma işlemini gerçekleştirir.
- Mod 1'de Port C'nin Handshake Sinyalleri
  - Mod 1 kullanıldığında Port C'nin pinlerinin çoğu handshake kontrol sinyalleri için ayrılır. Port A input için: PC4=STB_A, PC5=IBF_A, PC3=INTR_A; Port A output için: PC6=OBF_A, PC7=ACK_A, PC3=INTR_A. Port B input için: PC2=STB_B, PC1=IBF_B, PC0=INTR_B; Port B output için: PC1=OBF_B, PC2=ACK_B, PC0=INTR_B. Handshake sinyallerinde kullanılmayan Port C pinleri (Port A input durumunda PC6-PC7, Port A output durumunda PC4-PC5) genel amaçlı I/O olarak kullanılabilir.
- Mod 2: Çift Yönlü (Bidirectional) Handshake
  - Mod 2 sadece Port A için geçerlidir ve Port A'nın hem input hem output olarak handshake ile kullanılmasını sağlar. 5 adet handshake kontrol sinyali Port C'nin üst 4 pininden kullanılır: PC4=STB_A(input), PC5=IBF_A(input), PC6=OBF_A(output), PC7=ACK_A(output), PC3=INTR_A. Bu modda Port C'nin üst 4 biti tamamen handshake kontrolüne ayrıldığından genel amaçlı I/O olarak kullanılamaz. Port B ise Mod 0 veya Mod 1'de bağımsız olarak kullanılabilir.
- Control Word'ün Mod 1 ve Mod 2 İçin Yapılandırılması
  - Mod 1 için: D7=1, D6-D5=01 (Grup A Mod 1), D4=Port A yönü (1=input, 0=output), D3 ve D2 handshake sinyallerinden dolayı kısıtlanır, D2=1 (Port B Mod 1), D1=Port B yönü. Mod 2 için: D7=1, D6-D5=1x (Grup A Mod 2), D4=önemsiz (çift yönlü olduğu için input/output ayrımı yok), D3=önemsiz, D2=Port B modu, D1=Port B yönü, D0=Port C lower yönü.
- BSR (Bit Set/Reset) ile Interrupt Enable Kontrolü
  - Mod 1 ve Mod 2'de interruptların çalışabilmesi için Port C'deki ilgili pinlerin set edilmesi gerekir. Bu işlem BSR modu ile yapılır. Örneğin Mod 1'de Port A input için INTE_A = PC4'ü set etmek gerekir; bunun için BSR modunda PC4'ü 1 yapan control word gönderilir. Benzer şekilde INTE_B = PC2'yi set etmek için PC2'yi 1 yapan BSR komutu gönderilir. Bu işlemler programın başında veya gerektiğinde yapılabilir.
- Status Word (Durum Kelimesi) Okuma
  - Port C'den okuma yapılarak handshake sinyallerinin güncel durumu kontrol edilebilir. Buna status word denir. Input için: IBF (veri buffer'da mı?), STB (yeni veri geldi mi?), INTR (interrupt oluştu mu?) bilgileri okunur. Output için: OBF (output buffer dolu mu?), ACK (karşı taraf veriyi aldı mı?), INTR bilgileri okunur. Bu kontroller yapılarak yazılım seviyesinde handshake yönetimi sağlanır. Status word'ün hangi bitlerin hangi sinyale karşılık geldiği arayüzler PDF'inde tanımlıdır.
- İki 8255 Arasında Handshake Bağlantısı
  - Bir 8255'in Port A'sı (output, Mod 1) ile başka bir 8255'in Port A'sı (input, Mod 1) arasında handshake kurulabilir. Gönderen tarafın OBF sinyali, alıcı tarafın STB sinyaline bağlanır. Alıcı tarafın ACK sinyali, gönderen tarafın ACK girişine bağlanır. Bu sayede bir entegreden diğerine senkronize veri aktarımı yapılır. Benzer yapı Port B ile de kurulabilir.
- Proteus Örneği: Keypad-Display Handshake Uygulaması
  - Keypad'ten girilen sayının 7-segment display'e handshake ile yazdırıldığı bir örnek incelenmiştir. Port A input olarak keypad'ten veri okur (Mod 1), Port B output olarak 7-segment display'e yazar (Mod 1). Keypad'ten bir tuşa basıldığında STB sinyali oluşur, IBF ile veri alındığı onaylanır, interrupt ile mikroişlemci tetiklenir ve okunan değer Port B'den display'e yazılır. Bu örnek handshake mekanizmasının pratik uygulamasını göstermektedir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Handshake mekanizmasının neden gerekli olduğu vurgulanmıştır: Doğrudan port yazma/okuma yerine handshake kullanıldığında veri kaybı önlenir, karşı tarafın hazır olup olmadığı kontrol edilir ve senkronize iletişim sağlanır. Yazıcı-bilgisayar iletişimi bunun tipik bir örneğidir.
- Port C'nin Mod 1 ve Mod 2'de handshake sinyalleri için kullanıldığı ve bu pinlere dışarıdan buton gibi elemanlar bağlanmaması gerektiği özellikle vurgulanmıştır. Yanlış pin kullanımı handshake sinyallerini bozar.
- Mod 2'nin sadece Port A için geçerli olduğu ve Port B'nin Mod 2'ye sokulamayacağı net bir şekilde belirtilmiştir.
- BSR modunun handshake sinyallerini (özellikle interrupt enable pinlerini) kontrol etmek için kullanıldığı ve bu bilginin lab uygulamalarında önemli olacağı vurgulanmıştır.
- Handshake lab uygulamalarında öğrencilerin zorlanabileceği uyarısı yapılmış; konunun dikkatlice dinlenmesi gerektiği belirtilmiştir.

## Kısa Tekrar Notları

- Mod 0: Basit I/O, handshake yok, direkt IN/OUT
- Mod 1: Handshake, tek yönlü (input veya output), Port C pinleri kontrol sinyali olarak kullanılır
- Mod 2: Çift yönlü handshake, sadece Port A, Port C'nin 5 pini handshake için kullanılır
- Input handshake: STB (karşı taraf gönderir) → IBF (8255 üretir) → INTR (interrupt)
- Output handshake: WR → OBF (8255 üretir) → ACK (karşı taraf gönderir) → INTR
- BSR ile INTE pinleri set/reset edilir: PC4 (INTE_A input), PC2 (INTE_B input), PC6 (INTE_A output), PC1 (INTE_B output)
- Status word okunarak IBF, OBF, ACK durumları yazılımsal olarak kontrol edilebilir
- Control Word: D7=1, D6-D5=mod seçimi (00/01/1x), D4=Port A yönü, D3=Port C upper, D2=Port B modu, D1=Port B yönü, D0=Port C lower
- Port B sadece Mod 0 ve Mod 1 destekler; Mod 2 desteklemez

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Handshake Mekanizmasının Detaylı Çalışma Prensibi:**
Handshake, iki cihaz arasında senkronize veri aktarımı sağlayan bir iletişim protokolüdür. Mod 1'de input senaryosunda: Karşı taraf veri yoluna veriyi koyar ve STB (Strobe) sinyalini 0'a çeker (aktif düşük). Bu sinyal 8255'e "veri geldi" bilgisini iletir. 8255 veriyi input buffer'a alır ve IBF (Input Buffer Full) sinyalini 1 yapar. IBF=1 ve STB'nin yükselen kenarı birlikte değerlendirilerek INTR (interrupt) sinyali üretilir, ancak bunun için INTE (Interrupt Enable) bayrağının set edilmesi gerekir. Mikroişlemci interrupt'ı alınca IN komutuyla veriyi okur. Read sinyalinin düşen kenarıyla IBF tekrar 0'a düşer ve bir sonraki STB için hazır hale gelir.

Output senaryosunda: Mikroişlemci WR sinyalini aktif ederek veriyi porta yazar. Bu işlem OBF (Output Buffer Full) sinyalini 0'a çeker ve karşı tarafa "veri hazır, alabilirsin" bilgisi gider. Karşı taraf veriyi aldıktan sonra ACK sinyalini 0'a çeker. ACK'nin yükselen kenarı ve OBF'nin 1'e dönmesiyle INTR üretilir ve mikroişlemci yeni veri yazmaya hazır hale gelir. Bu mekanizma sayesinde mikroişlemci çok hızlı veri gönderse bile karşı tarafın yetişememesi durumunda veri kaybı yaşanmaz.

**Mod 2 Çift Yönlü Çalışma:**
Mod 2'de Port A hem input hem output olarak handshake ile çalışabilir. Bu modda Port C'nin PC3-PC7 pinlerinin beşi handshake sinyalleri için kullanılır. Input kısmı: PC4=STB_A, PC5=IBF_A. Output kısmı: PC6=OBF_A, PC7=ACK_A. Ortak: PC3=INTR_A. Bu yapı sayesinde aynı port üzerinden sırayla okuma ve yazma yapılabilir. Örneğin bir hesap makinesi uygulamasında Port A'dan keypad verisi okunabilir, işlem yapıldıktan sonra sonuç aynı Port A üzerinden display'e yazdırılabilir. Port B bu modda bağımsız olarak Mod 0 veya Mod 1'de kullanılabilir.

**BSR Modunun Handshake ile İlişkisi:**
Mod 1 ve Mod 2'de interruptların üretilmesi için INTE (Interrupt Enable) bayraklarının set edilmesi gerekir. Bu bayraklar Port C'nin belirli pinlerine karşılık gelir ve BSR modu ile kontrol edilir. Port A input için INTE_A = PC4, Port A output için INTE_A = PC6, Port B input için INTE_B = PC2, Port B output için INTE_B = PC1'dir. BSR modunda control word'ün D7=0 yapılır, D3-D2-D1 ile hedef pin binary olarak seçilir ve D0=1 ile pin set edilir. Örneğin PC2'yi set etmek (INTE_B'yi aktif etmek) için: 0000 0101 = 05H control word olarak gönderilir. Bu işlem programın başlangıcında veya ihtiyaç duyulduğunda yapılabilir.

**Status Word ile Yazılımsal Handshake Kontrolü:**
Handshake sinyallerini donanımsal olarak interrupt'a bağlamak yerine yazılımsal olarak da kontrol edilebilir. Bunun için Port C'den okuma yapılır (status word okuma). Status word'ün ilgili bitleri IBF, OBF, ACK gibi sinyallerin güncel durumunu gösterir. Örneğin bir veri göndermeden önce OBF bitini kontrol ederek output buffer'ın boş olup olmadığı anlaşılır. Buffer boşsa yeni veri yazılabilir. Benzer şekilde veri okumadan önce IBF bitine bakılarak buffer'da yeni veri olup olmadığı kontrol edilir. Bu yöntem polling (yoklama) olarak adlandırılır ve interrupt'a alternatif bir yaklaşımdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
