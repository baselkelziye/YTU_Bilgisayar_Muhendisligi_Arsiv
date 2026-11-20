# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin yeri ve çevre birimlerine geçiş
  - 8086'yı çalışır hale getiren yardımcı devreler (saat üreteci, yol tutucu ve tamponlar) önceki derslerde tamamlanmıştır. Bu dersten itibaren arayüz (interface) entegrelerine geçilir.
  - Dönem boyunca görülecek yardımcı devre grupları: paralel veri alışverişi yapan programlanabilir devreler, seri haberleşme devreleri, zamanlayıcı/sayıcılar, sayısal-analog ve analog-sayısal çeviriciler, kesme denetleyicisi; ardından hafıza birimlerinin 8086'ya bağlanması.
  - Programlanabilir arayüzlerden önce, kullanıcının kendi tasarladığı (custom) basit çevre birimlerinin 8086'ya bağlanması ele alınır. Ekrandaki konu listesi: çevre birimleri, G/Ç assembly komutları, G/Ç haritalama yöntemleri, basit arayüz devreleri (düğme ve LED arayüzü), basit çevre birimleri ve adres çözümleme, çevre birimleri kontrolü (ekrandan, 00:05:00). Adres çözümleme ve kontrol başlıklarına bu kayıtta geçilemedi.
- Çevre birimleri (peripheral devices)
  - Mikroişlemcinin dış dünyaya karşı giriş ve/veya çıkış yaptığı cihazlardır; hafıza birimleri gibi belirli bir adres bölgesine yerleştirilirler, ama adres genişlikleri hafızaya göre dardır, 1-4 bayt (ekrandan, 00:10:00).
  - Bir cihazın kapladığı alan adres ucu sayısıyla belirlenir: 256 KB'lık bir hafıza $2^8 \cdot 2^{10} = 2^{18}$ olduğundan 18 adres ucuna sahiptir; 8255'in 2 adres ucu vardır, $2^2 = 4$ gözlük, yani 4 baytlık alan kaplar. Her göz 1 bayttır.
  - Giriş ve çıkış her zaman mikroişlemciye göre tanımlanır: mikroişlemciden dışarı veri çıkaran birim çıkış birimidir ve `OUT` ile yazılır; dışarıdan mikroişlemciye veri aktaran birim giriş birimidir ve `IN` ile okunur.
- G/Ç assembly komutları
  - Toplam 8 varyasyon vardır (ekrandan, 00:15:00):

    | | IN komutu | OUT komutu |
    |---|---|---|
    | Fixed address | `IN AL, p8` / `IN AX, p8` | `OUT p8, AL` / `OUT p8, AX` |
    | Variable address | `IN AL, DX` / `IN AX, DX` | `OUT DX, AL` / `OUT DX, AX` |

  - `p8`, 8 bite sığan port adresidir; adres komutun içine gömülür (fixed address). Port adresi 8 bite sığmıyorsa adres mutlaka DX üzerinden verilir (variable address).
  - Veri tarafında yalnız AL (8 bit) ya da AX (16 bit) kullanılabilir; başka yazmaç seçeneği yoktur.
  - 8 bite sığan bir adresi de DX ile vermek geçerlidir (`MOV DX, 10H` ardından `IN AL, DX`), ama iki komut gerektiği için daha uzun sürer. G/Ç komutları sık çalıştığından adres 8 bite sığıyorsa doğrudan verilmesi tercih edilir.
- Çift ve tek adreste 8 ve 16 bitlik G/Ç
  - Çift adresten 8 bitlik işlemde veri, veri yolunun düşük baytından (D0-D7) gelir ya da oraya konur; $A0 = 0$ olur ve bu sanal "bus low enable" işaretinin görevini görür.
  - Tek adresten 8 bitlik işlemde veri yüksek bayttan (D8-D15) gelir ya da oraya konur; $\overline{BHE} = 0$ olur.
  - Çift adresten 16 bitlik işlemde (örnek `IN AX, 10H`) AL ← [10H] D0-D7'den, AH ← [11H] D8-D15'ten gelir; $A0 = 0$ ve $\overline{BHE} = 0$ birlikte üretilir, işlem bir okuma-yazma çevriminde biter (ekrandan, 00:45:00).
  - Tek adresten 16 bitlik işlemde (örnek `IN AX, 11H`) AL ← [11H] D8-D15'ten, AH ← [12H] D0-D7'den gelir; 11H ve 12H farklı satırlarda olduğu için iki okuma-yazma çevrimi gerekir (ekrandan, 00:35:00 ve 00:45:00).
- Hafıza ve G/Ç uzayının çift/tek bloklar halinde düzenlenmesi
  - 8086'nın 20 adres ucu vardır, hafıza kapasitesi 1M×8'dir; ama 16 bit veri okuyabilmek için uygun arayüz 512K×16'dır (ekrandan, 00:50:00): çift bayt bloğu ve tek bayt bloğu yan yana, A0 dışındaki bitler aynı satırı seçer.
  - G/Ç uzayı en çok $2^{16}$ = 64 KB'tır, çünkü port adresi en fazla 16 bitlik DX ile verilir. Uygun arayüz 32K×16'dır: 32K'lık çift ve 32K'lık tek blok.
  - 80386/80486'da veri yolu 32 bit olduğu için dört blok vardır; 4'e tam bölünen adresten 32 bitlik veri bir seferde D0-D7, D8-D15, D16-D23, D24-D31 üzerinden okunur.
- G/Ç haritalama yöntemleri
  - Isolated I/O: $M/\overline{IO}$ ucu adres çözümlemede kullanılır. Memory mapped I/O: bu uç adres çözümlemede kullanılmaz (ekrandan, 00:55:00).
  - Mikroişlemci hafıza işleminde $M/\overline{IO} = 1$, G/Ç işleminde $M/\overline{IO} = 0$ üretir. `MOV AL, [10H]` ile `IN AL, 10H` adres uçlarında aynı değeri oluşturur; ikisini ayıran tek şey bu uçtur.
  - Isolated I/O: hafıza uzayının tamamı (1 MB) hafızaya, G/Ç uzayının tamamı (64 KB) G/Ç'ye ayrılır; daha hızlı özel `IN`/`OUT` komutları ve daha basit G/Ç adres çözümleme devreleri kullanılabilir (ekrandan, 01:00:00).
  - Memory mapped I/O: tek bir 1 MB'lık uzay vardır, düşük 64 KB'lık kısımda bir G/Ç bölgesi tanımlanır; G/Ç'ye `MOV` komutlarıyla erişilir, hafızayı ve G/Ç'yi ayıran fiziksel uca gerek yoktur, adres çözümleme bir adım daha basittir.
- Düğme (buton) arayüzü
  - İki tip düğme: momentary (kapı zili gibi, bırakınca geri döner) ve latched (basınca kapanır, ters yönde basınca açılır, durumu korur).
  - Düğme bir giriş arayüzüdür. İki temel kural: basılı ve bırakılmış durumda anlamlı ve farklı lojik seviyeler üretilmeli; besleme ile toprak hiçbir durumda kısa devre olmamalı.
  - Altı aday devre incelenir (ekrandan, 01:05:00): yalnız beslemeye ya da yalnız toprağa bağlı düğmeler bırakılınca uç boşta (float) kaldığı için; uç doğrudan toprağa ya da beslemeye bağlıyken düğmenin diğer seviyeye bağlandığı devreler basıldığında kısa devre yaptığı için geçersizdir.
  - Geçerli iki devre 10 kΩ dirençlidir: düğme beslemeye, direnç toprağa bağlıysa (R2) basılı değilken lojik 0, basılıyken lojik 1; düğme toprağa, direnç beslemeye bağlıysa (R1) basılı değilken lojik 1, basılıyken lojik 0 okunur (ekrandan, 01:10:00). Basılıyken dirençten $5\,V / 10\,k\Omega = 0{,}5\,mA$ akar, kısa devre olmaz.
  - Yoklama (polling) mantığında uç sürekli okunur; ilk devrede ucun 1'e çıkması, ikincisinde 0'a düşmesi basıldı demektir.
- Kontak gürültüsü (contact bounce)
  - Düğmedeki yay ve metal kontaklar yüzünden tek basışta seviye birçok kez açılıp kapanır (ekrandan, 01:15:00).
  - Yazılımsal çözüm: ilk değişim yakalandıktan sonra belirli süre boş döngüde beklenir, uç tekrar okunur; iki örnekte de beklenen seviye varsa basış kabul edilir. Bekleme süresi düğmenin fiziksel yapısına göre yeterince uzun olmalıdır.
  - Donanımsal çözüm: flip-flop tabanlı debounce switch yapısı; çıkışı temiz bir geçiş verir.
- LED arayüzü
  - LED (Light Emitting Diode) bir çıkış birimidir; mikroişlemcinin durum bildirimlerini dış dünyaya aktarır. Anot (A, artı uç) ile katot (K) arasında pozitif gerilim farkı ve uygun akım olduğunda ışık verir.
  - İki kural: LED doğru yönde kutuplanmalı; veri sayfasındaki en büyük akım aşılmamalı, aşılırsa LED kısa ömürlü olur.
  - Ekrandaki veriler (ekrandan, 01:20:00): uç 2,4 V ve 0,1 mA verebilir; transistör Si, $\beta = 100$; LED 2 V ve 10 mA ile en parlak yanar. Direnç değerleri bu kayıtta hesaplanmadı.
  - D1 (uç → LED → toprak, dirençsiz): uca 5 V verilince yanar ama akım sınırlanmadığı için ömrü kısa olur.
  - D2 (uç → LED → +5 V, anot uçta): uca verilebilecek en yüksek değer 5 V, diğer taraf da 5 V olduğu için asla pozitif fark oluşmaz, yanmaz.
  - D3 (uç → R1 → LED → toprak): uca lojik 1 verilince uzun ömürlü yanar, ama mikroişlemci ucu az akım verebildiği için sönük yanar.
  - D5 (+5 V → R4 → LED → uç): uca lojik 0 verilince yanar; akım mikroişlemcinin içine doğru aktığı için D3'ten daha parlak yanar.
  - D4 (uç → R3 → NPN BJT tabanı; +5 V → LED → R2 → kollektör): uca lojik 1 verilince transistör iletime geçer, LED kaynaktan sürülür; mikroişlemciden doğrudan sürmenin doğru yolu budur.

## Hocanın Özellikle Vurguladığı Kısımlar

- `IN AL, DX` geçerli midir?
  - Hocanın sınavlarda sormayı sevdiği bir sorudur. `MOV BL, AX` tip hatası verir, ama `IN AL, DX` geçerlidir: DX burada veri değil port adresidir; 16 bitlik adresteki 1 baytlık veri AL'ye alınır.
- Referans her zaman mikroişlemcidir
  - Giriş/çıkış birimi tanımları ve `IN`/`OUT` komutlarının yönü mikroişlemciye göre belirlenir.
- Hizalama ve okuma-yazma çevrimi
  - Çift adresten 8 bit, tek adresten 8 bit ve çift adresten 16 bit işlemler bir çevrimde; tek adresten 16 bit işlem iki çevrimde biter. Assembly'de veri ve kodu çift adreslere hizalamanın sebebi budur.
- Port adresi seçimi
  - Adres 8 bite sığıyorsa komuta gömülmeli, sığmıyorsa DX kullanılmalıdır; 8 bite sığan adresi DX ile vermek geçerli ama yavaştır.
- Devreyi okuyarak kod yazmak
  - Lojik 1 ile yanan LED'ler de, lojik 0 ile yanan LED'ler de vardır; basılınca 0 veren düğme de, 1 veren düğme de vardır. Kontrol kodu devre şemasına bakılarak yazılmalıdır.
- Mikroişlemci ucu akım verme ve çekme
  - Ucun dışarı akım verme kabiliyeti düşüktür; akım çeken (D5) ya da transistörle sürülen (D4) bağlantı LED'i daha parlak yakar.

## Kısa Tekrar Notları

- Çevre birimi: dış dünyaya G/Ç yapan, 1-4 baytlık adres bölgesi kaplayan cihaz. 8255: 2 adres ucu, 4 bayt.
- 8 G/Ç komutu: `IN AL/AX, p8|DX`, `OUT p8|DX, AL/AX`. Veri yalnız AL ya da AX'te.
- p8 = 8 bite sığan port adresi (fixed). Sığmıyorsa DX (variable).
- Çift adres, 8 bit: D0-D7, $A0 = 0$. Tek adres, 8 bit: D8-D15, $\overline{BHE} = 0$.
- `IN AX, 10H`: AL ← [10H], AH ← [11H], tek çevrim. `IN AX, 11H`: AL ← [11H], AH ← [12H], iki çevrim.
- Hafıza 1M×8, uygun arayüz 512K×16. G/Ç 64K×8, uygun arayüz 32K×16.
- $M/\overline{IO}$: hafızada 1, G/Ç'de 0. Adres çözümlemede kullanılırsa isolated I/O, kullanılmazsa memory mapped I/O.
- Isolated: ayrı 1 MB ve 64 KB uzay, `IN`/`OUT`. Memory mapped: tek 1 MB uzay, G/Ç düşük 64 KB'ta, `MOV` ile erişim.
- Düğme kuralları: iki durumda farklı ve anlamlı seviye, kısa devre yok. Geçerli devreler 10 kΩ pull-down ve pull-up dirençli olanlardır.
- Kontak gürültüsü: yazılımda bekle-tekrar oku; donanımda flip-flop tabanlı debounce switch.
- LED: doğru kutuplama, akım sınırı. D2 hiç yanmaz; D1 kısa ömürlü; D3 sönük; D5 parlak (lojik 0); D4 transistörle (lojik 1).

## Detaylı Açıklamalar

- **G/Ç komutlarında veri yolu ve kontrol uçları.** `IN AL, 10H` komutunda 10H çift olduğu için mikroişlemci 10H portundaki 8 bitlik veriyi veri yolunun düşük baytından (D0-D7) okur, önce iç geçici yazmaca, sonra AL'ye aktarır. 10H yazıldığında A0 zaten 0 olduğu için ayrı bir "bus low enable" ucuna gerek yoktur; A0 bu görevi görür. `OUT 11H, AL` komutunda adres tek olduğundan AL'deki veri D8-D15'e konur ve $\overline{BHE}$ ucunda 0 üretilir (ekrandan, 00:20:00). Bu kural hafıza işlemleri için de geçerlidir ve hafıza konusunda genişletilecektir.
- **Neden 512K×16?** 10H (`0001 0000B`) ile 11H (`0001 0001B`) yalnız A0'da farklıdır; A0 adres çözümlemeye katılmazsa kalan bitler aynı satırı gösterir. Uzay çift ve tek bloklara bölünüp aynı satırdaki iki sütun birlikte seçilince iki bayt aynı anda veri yoluna çıkar. 11H (`0001 0001B`) ile 12H (`0001 0010B`) ise farklı satırlardadır (ekrandan, 00:35:00); bu yüzden tek adresten 16 bit okuma iki çevrime bölünür: önce 11H tek bloktan D8-D15 üzerinden AL'ye, sonra 12H çift bloktan D0-D7 üzerinden AH'ye. Little endian düzen nedeniyle düşük adresteki bayt AL'ye (düşük anlamlı bayt), yüksek adresteki bayt AH'ye gider.
- **80486 örneği.** 32 bitlik veri yolunda dört blok vardır; 4'e bölünen bir adresten 32 bitlik okumada bloklar sırasıyla D0-D7, D8-D15, D16-D23, D24-D31'e bağlanır ve veri tek seferde okunur. 32 adres ucu toplam 4 GB'lık alana karşılık gelir.
  - **Ders sonrası not:** Hoca 486 için de "512K çarpı 16'lık" ifadesini kullandı (00:36:31); 4 GB'lık uzay dört bloğa bölündüğünde uygun arayüz $2^{32}/4 = $ 1G×32 olur.
- **G/Ç haritalamada ayrım.** `MOV AL, [10H]` ile `IN AL, 10H` adres uçlarına aynı değeri çıkarır. Adres çözümleme yalnız adres uçlarına bakarsa iki işlem ayrılamaz; bu durumda G/Ç hafıza uzayının bir parçası olur (memory mapped I/O). $M/\overline{IO}$ ucuna da bakılırsa iki uzay birbirinden ayrılır (isolated I/O). Hoca memory mapped yaklaşımı "tasarım olarak" anlatırken 8086'nın bunu desteklediğini söylemediğini ayrıca belirtti.
  - **Ders sonrası not:** Hoca bir yerde "hafıza işlemi ise $M/\overline{IO}$ ucunda sıfır" dedi (00:54:56); hemen ardından doğrusunu verdi: hafıza işleminde 1, G/Ç işleminde 0.
- **Düğme devrelerinin analizi.** Ucun bağlandığı giriş içeri akım çekmiyor kabul edilir. R2'li devrede düğme açıkken dirençten akım akmadığından uçta 0 V (lojik 0) görülür; düğme kapanınca uç doğrudan 5 V'a bağlanır (lojik 1), 5 V'un tamamı direnç üzerinde düşer ve $5\,V / 10\,k\Omega = 0{,}5\,mA$ akım akar, kısa devre yoktur. R1'li devrede tersi geçerlidir: açıkken akım akmadığından uç 5 V (lojik 1), basılınca toprağa bağlanır (lojik 0).
  - **Ders sonrası not:** Hoca akımı önce 100 µA ve 2 mA olarak söyledi, sonra 0,5 mA olarak düzeltti (01:11:06-01:12:08); doğrusu 0,5 mA'dir.
- **LED ve mikroişlemci ucu.** 8086 TTL lojik kullanır, uçta yalnız 0 V ya da 5 V oluşturabilir ve besleme de 5 V'tur; bu yüzden D2 hiçbir zaman yanmaz. D5'te akım dışarıdaki 5 V kaynaktan mikroişlemci ucuna doğru akar; uçların akım çekme sınırı, verme sınırına göre çok daha geniştir, bu yüzden D5, D3'ten parlaktır. D4'te NPN BJT'nin tabanı ile emiteri arasında pozitif gerilim oluşunca transistör iletime geçer ve +5 V → LED → R2 → toprak yolu tamamlanır.
  - **Ders sonrası not:** Hoca uçların doğrudan sürmede "100 mA civarında" kaldığını söyledi (01:24:30); slayttaki veri ucun 2,4 V ve 0,1 mA verebildiğini gösterir (ekrandan, 01:20:00). LED'in en parlak yanması için gereken 10 mA'ye göre bu değer çok düşüktür; D3'ün sönük yanmasının sebebi budur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
