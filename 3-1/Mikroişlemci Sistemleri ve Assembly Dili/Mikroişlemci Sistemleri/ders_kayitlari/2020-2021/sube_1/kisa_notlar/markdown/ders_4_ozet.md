# Ders 4 Çalışma Özeti

## Genel Konular

- Laboratuvar ortamı: Proteus ile 8086 benzetimi
  - Laboratuvar çalışmalarında fiziksel deney kartı yerine Proteus 8 Professional benzetim yazılımı kullanılır.
  - Her laboratuvar sorusunun iki adımı vardır: şematik üzerinde donanım bağlantılarını yapmak (gerekirse ek eleman eklemek) ve problemi çözen 8086 assembly kodunu yazmak.
  - Laboratuvar konuları sırasıyla 8255 temel G/Ç, 8255 el sıkışma (handshake), USART, sayıcılar ve kesmelerdir (ekrandan, 00:05:00).
- Yeni proje oluşturma adımları
  - "New Project" ile projeye ad verilir; şematik varsayılan şablondan oluşturulur, PCB yerleşimi oluşturulmaz.
  - "Firmware Project" seçilir: aile ve denetleyici olarak 8086, derleyici olarak MASM32 seçilir. MASM32 ilk kullanımda indirilip kurulmalıdır; derleyici seçmeyi unutmak sık yapılan bir hatadır.
  - Özet ekranında "8086 compiled by MASM32, autoplace processor on schematic" görülür (ekrandan, 00:15:00). Bitince iki sekme açılır: Schematic Capture (devre) ve Source Code (assembly kodu).
- Proteus'un yerleştirdiği 8086 ve uç bağlantıları
  - RESET toprağa bağlıdır, çünkü işlemci çalışırken sürekli reset durumunda kalmamalıdır.
  - READY ve MN/$\overline{MX}$ lojik 1'e (üçgen sembolü: güç/lojik 1) bağlıdır. Derste 8086 minimum modda kullanılır; MN/$\overline{MX}$ = 1 minimum mod, 0 maksimum mod demektir.
  - Üzerinde çizgi (şapka) olan giriş, 0 verildiğinde etkin olur (aktif düşük); şapkasız uç 1'de etkindir. ALE şapkasız bir çıkıştır: 1 olduğunda yolda adres bilgisi bulunduğunu bildirir.
  - AD[0..15] uçları zaman paylaşımlıdır (time multiplexing): bazen adres, bazen veri taşır. A[16..19] yalnız adres taşır ve 20 bitlik adresi tamamlar.
  - Kalın mavi çizgiler yol (bus, çok bitli), ince kırmızı çizgiler tek hattır.
- Şematik çizim teknikleri
  - Yol çizme, yolu terminalle sonlandırma ve iki yolu birleştirme.
  - Etiketleme (label): yola, tek hatta ya da terminale "Edit Properties" ile ad verilir. Aynı adı taşıyan iki nokta arada kablo olmasa da bağlı sayılır; karmaşık devrede uzun kablo çekmek gerekmez.
  - "Pick Devices" penceresinde anahtar kelimeyle eleman aranır: 74273, flip-flop, direnç ("res") gibi. 74273, temizleme girişli sekizli pozitif kenar tetiklemeli D flip-flop'tur (ekrandan, 00:25:00).
  - Güç, toprak ve "default" terminal sol araç çubuğundan alınır; işlemci uçlarına (örneğin $\overline{RD}$, $\overline{WR}$) terminal bağlanıp etiketlenebilir.
- 8255 ile temel G/Ç ve devre blokları
  - 8255, butonlardan veri okuyup LED'e yazmak gibi temel G/Ç işlemi yapan çevre birimidir. Sol tarafta D0-D7 veri uçları (AD0-AD7'ye bağlı), sağda 8'er bitlik PA, PB, PC portları vardır.
  - Örnek şemada 8255'in A0 ucu adres hattı A1'e, A1 ucu A2'ye, $\overline{CS}$ ucu CS8255 etiketine bağlıdır (ekrandan, 00:30:00).
  - Lab şablonundaki bloklar: işlemci, adres tutma (74273'ler), adres çözümleme (74LS137 kod çözücü), yardımcı çevre birimi (8255, sayıcı, USART, ADC/DAC) ve G/Ç elemanları (buton, LED, 7 parçalı gösterge, osiloskop).
- Adres tutma: 74273 D flip-flop'ları
  - AD hatları adres taşıdığı anda adres, saat (CLK) sinyaliyle flip-flop çıkışlarına aktarılıp tutulur; 20 bitlik adres ADR[0..19] etiketiyle kullanılır.
  - CLK, işlemcinin "yolda adres var" bilgisini veren sinyalle beslenmelidir; bunu bulmak laboratuvar görevine bırakıldı. MR (reset) girişi için veri sayfasına bakılmalıdır.
- 3'e 8 kod çözücü: 74LS137
  - $n$ girişli kod çözücü $2^n$ çıkış verir; 3 giriş (C, B, A) 8 çıkışa (Y0-Y7) eşlenir. C en anlamlı, A en az anlamlı bittir.
  - Üç etkinleştirme girişinden G1 aktif yüksek, $\overline{GL}$ ve $\overline{G2}$ aktif düşüktür (ekrandan, 00:35:00).
  - Çıkışlar aktif düşüktür: seçilen çıkış 0, diğerleri 1 olur. CBA = 001 için Y0..Y7 = 1 0 1 1 1 1 1 1.
  - Kod çözücünün bir çıkışı 8255'in $\overline{CS}$ ucunu sürer; böylece 8255 yalnız istenen adreste çalışır.
- 16 bitlik veri yolunda 8 bitlik çevre birimi
  - $\overline{BHE}$ ve A0 tablosu (ekrandan, 00:45:00): $\overline{BHE}$=0, A0=1 tek adresteki byte (D8-D15); $\overline{BHE}$=1, A0=0 çift adresteki byte (D0-D7); diğer iki durum tabloda "anlamlı değil" olarak verilmiştir.
  - Örnek: başlangıç G/Ç adresi F8h olan ve yalnız çift adresleri kullanan 8255 için adresler F8h, FAh, FCh, FEh'dir. Hepsinde A0 = 0'dır ve veri D0-D7 üzerinden aktarılır; A2-A1 8255'in yazmaç seçimini yapar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Proje oluştururken derleyici (MASM32) mutlaka seçilmelidir.
  - Derleyici seçilmezse yazılan assembly kodu derlenemez; ilk kullanımda MASM32 indirilip kurulmalıdır.
- Uç adlarının üzerindeki şapka etkin seviyeyi belirtir.
  - Şapkalı uç 0'da, şapkasız uç 1'de etkindir. Bağlantı yaparken (RESET, READY, MN/$\overline{MX}$ gibi) buna dikkat edilmelidir.
- Etiketleme karmaşık devrelerde zorunlu bir alışkanlıktır.
  - Aynı adlı etiketler bağlıdır; onlarca kablo çekmek yerine etiket kullanmak devreyi okunur kılar.
- 74273'lerin CLK girişi doğru sinyalle beslenmelidir.
  - Adresler AD hatlarında tam olduğu anda flip-flop'lar tetiklenmelidir ki adres doğru tutulsun.
- Çift adres dizisi F8h, FAh, FCh, FEh'dir.
  - On altılık düzende F9h'den sonra FAh gelir; çift adreslerde FBh ve FDh atlanır.

## Kısa Tekrar Notları

- Proteus: Firmware Project, aile 8086, derleyici MASM32; Schematic Capture ve Source Code sekmeleri.
- RESET = 0 (toprak), READY = 1, MN/$\overline{MX}$ = 1 (minimum mod).
- Şapka = aktif düşük. ALE çıkıştır, 1'de yolda adres vardır.
- AD0-AD15 adres/veri zaman paylaşımlı; A16-A19 yalnız adres; toplam 20 bit adres.
- Kalın mavi = yol, ince = tek hat. Aynı etiket = aynı bağlantı.
- 74273: sekizli D flip-flop, adres tutma için; CLK adres anında tetiklenmeli.
- 74LS137: 3'e 8 kod çözücü, G1 aktif yüksek, $\overline{GL}$ ve $\overline{G2}$ aktif düşük, çıkışlar aktif düşük.
- Blok yapısı: işlemci, adres tutma, adres çözümleme, çevre birimi, G/Ç elemanları.
- F8h tabanlı çift adresli 8255: F8h, FAh, FCh, FEh; A0 = 0, veri D0-D7, A2-A1 yazmaç seçimi.

## Detaylı Açıklamalar

- **Laboratuvar akışı ve Proteus.** Bu kayıt, dersin laboratuvar bölümünün tanıtımıdır ve bir araştırma görevlisi tarafından anlatılmıştır. Laboratuvarlarda bir problem verilir; öğrenci hem şematik üzerinde donanımı kurar hem de 8086 için assembly kodunu yazar. Proteus'ta proje oluşturulurken Firmware Project adımında 8086 ve MASM32 seçilir; bu yapıldığında şematik sekmesine bazı uçları önceden bağlanmış bir 8086 otomatik yerleştirilir. Çift tıklanınca program dosyasının yeri ve saat frekansı gibi işlemci özellikleri görülür.

- **8086'nın otomatik bağlantıları.** Ekranda gösterilen 8086 sembolünde RESET (21) toprağa, READY (22) ve MN/$\overline{MX}$ (33) lojik 1'e bağlıdır (ekrandan, 00:20:00). RESET'in 0 olması işlemcinin sürekli sıfırlanmamasını, READY'nin 1 olması bekleme durumuna girilmemesini, MN/$\overline{MX}$'in 1 olması minimum modu sağlar. Minimum mod, ek tampon ve yol denetleyicisi gerektirmediği için derste tercih edilir. AD[0..15] uçları hem adres hem veri taşır ama aynı anda değil; zaman paylaşımıyla önce adres, sonra veri yola konur. A[16..19] uçlarıyla birlikte 20 bitlik adres oluşur.

- **Etiketleme.** Proteus'ta bir yola ya da hatta sağ tıklayıp "Edit Properties" ile etiket verilir (örneğin AD[0..15], AD0, ALE, RD). Aynı etiketi taşıyan başka bir nokta, arada kablo olmasa da elektriksel olarak bağlı sayılır. Bu sayede bir yol, devrenin uzak bir yerindeki birçok elemana kablo çekmeden ulaştırılır. Örneğin AD0 etiketli hat 74273'ün D0 girişine (3 numaralı uç) bağlanarak düşük anlamlı byte'ın ilk biti aktarılır.

- **Adres tutma ve adres çözümleme.** Laboratuvar şablonunda üç adet 74273 vardır: biri AD0-AD7'yi, biri AD8-AD15'i, biri AD16-AD19'u alır; çıkışları ADR[0..19] yoluna bağlıdır (ekrandan, 00:40:00). AD hatlarında adres bulunduğu anda CLK tetiklenirse adres çıkışlarda tutulur ve veri evresinde de kullanılabilir. Tutulan adres bitlerinden bazıları 74LS137 kod çözücünün C, B, A girişlerine verilir; uygun kombinasyon gelince seçilen çıkış 0 olur ve CS8255 etiketiyle 8255'in $\overline{CS}$ ucunu etkinleştirir. Böylece 8255 yalnız soruda istenen adreslerde okuma ya da yazma yapar.

- **F8h örneği.** 8255 dört ardışık port adresi kullanır. Başlangıç adresi F8h ve yalnız çift adres istenince adresler F8h (1111 1000), FAh (1111 1010), FCh (1111 1100), FEh (1111 1110) olur (ekrandan, 00:45:00). Dördünde de A0 = 0'dır; bu da $\overline{BHE}$ tablosuna göre çift adresteki byte'ın, yani D0-D7'nin kullanılması demektir. Değişen bitler A2 ve A1'dir (00, 01, 10, 11); bu iki bit 8255'in hangi yazmacının seçileceğini belirler. Kalan üst bitler (A7-A3) adres çözümlemede kod çözücüye verilir; ayrıntılı adres çözümleme bir sonraki derslere bırakılmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
