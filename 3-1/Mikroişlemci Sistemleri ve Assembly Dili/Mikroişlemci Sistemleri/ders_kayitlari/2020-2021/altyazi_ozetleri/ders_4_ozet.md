# Ders 4 Çalışma Özeti

## Genel Konular

- 8255 Adresleme Tasarımının Tekrarı ve Farklı Senaryolar
  - Bir 8255 entegresinin bellek haritasına yerleştirilmesi için başlangıç adresi verilir ve bu adresten yola çıkılarak port A, port B, port C ve control word adresleri belirlenir. Çift adresli yerleştirmede A0=0 şartı chip select devresine eklenir; tek adresli yerleştirmede A0=1 şartı NOR veya NOT kapısıyla sağlanır. Farklı başlangıç adresleri farklı adres çözümleme devreleri gerektirir ancak temel mantık aynıdır.
- Sıra Düzen (Sequential) Adresleme ve BHE Kullanımı
  - Çift/tek adres kısıtlaması olmadan sıra düzen adresleme yapıldığında (örneğin C0, C1, C2, C3), A0 ve A1 doğrudan 8255'in A0 ve A1 pinlerine bağlanabilir. Ancak bu durumda 8 bitlik 8255 ile 16 bitlik veri yolu arasında uyumsuzluk oluşur. BHE (Bus High Enable) pini ile A0 birlikte kullanılarak üst 8 bit (D8-D15) ve alt 8 bit (D0-D7) ayrı ayrı enable edilir; böylece tek bir 8255 ile 16 bitlik veri yolu elde edilir.
- Dekoder vs. NAND Kapısı ile Adres Çözme Karşılaştırması
  - Adres çözme devresi dekoder veya NAND/AND/OR kapılarıyla kurulabilir. Dekoder kullanımı daha pratiktir çünkü enable pinlerine koşullar bağlanarak tek seferde çoklu adres kontrolü yapılabilir. NAND kapılarıyla yapılan tasarımlarda her bir koşulun ayrı ayrı kontrol edilmesi gerekir ve hata yapma riski artar. Ancak her iki yöntem de teorik olarak geçerlidir ve sınavlarda farklı çözümler kabul edilir.
- 8255'in Modları: Mod 0, Mod 1, Mod 2 ve BSR
  - Mod 0 (Basic I/O): Herhangi bir handshake mekanizması olmadan doğrudan porta veri yazma veya porttan veri okuma. Anlık değer aktarımı yapılır. Mod 1 (Handshake): Karşılıklı iletişim protokolü ile veri aktarımı. Bir port veri gönderirken diğer portun hazır olup olmadığı kontrol sinyalleriyle (STB, IBF, OBF, ACK) belirlenir. Mod 2 (Bidirectional): Sadece Port A için geçerli olan çift yönlü handshake modu. Port A hem input hem output olarak kullanılabilir. BSR (Bit Set/Reset): Port C'nin belirli bir pinini 1 veya 0 yapmak için kullanılan özel mod. D7=0 ile aktif edilir.
- Control Word Bit Diziliminin Detaylı Analizi
  - D7: Mode Selection (1) veya BSR (0) seçimi. D6-D5: Grup A mod seçimi (00=Mod 0, 01=Mod 1, 1x=Mod 2). D4: Port A yönü (1=input, 0=output). D3: Port C upper yönü. D2: Grup B mod seçimi (0=Mod 0, 1=Mod 1). D1: Port B yönü. D0: Port C lower yönü. Port B sadece Mod 0 ve Mod 1 destekler; Mod 2 desteklemez çünkü Mod 2'de Port C'nin alt bitleri de handshake sinyalleri için kullanılır.
- BSR (Bit Set/Reset) Modu ve Kullanımı
  - BSR modunda control word'ün D7=0 yapılır. D3-D2-D1 bitleri Port C'nin hangi pininin etkileneceğini binary olarak belirler (000=PC0, 001=PC1, ... 111=PC7). D0 biti ise seçilen pinin 1 (set) mi yoksa 0 (reset) mi yapılacağını belirler. Bu mod özellikle Mod 1 ve Mod 2'de handshake sinyallerini manuel olarak kontrol etmek için kullanılır.
- Keypad Tarama (Scanning) Prensibi
  - Keypad'ler satır-sütun yapısında çalışır. Sütunlar pull-up veya pull-down dirençlerle mikroişlemciye bağlanır. Pull-up dirençli yapıda sütunlar sırayla 0 ile taranır ve satırlardan 0 okunan yer tespit edilerek basılan tuş belirlenir. Pull-down dirençli yapıda ise sütunlar 1 ile taranır ve satırlardan 1 okunan yer kontrol edilir. Hangi direnç tipinin kullanıldığı, hangi değerin taranacağını ve hangi değerin kontrol edileceğini doğrudan etkiler.
- 7-Segment Display: Ortak Anot ve Ortak Katot
  - Ortak katotlu display'de tüm LED'lerin katotları birleştirilip GND'ye bağlanır; segmentleri yakmak için anotlara 1 verilir. Ortak anotlu display'de tüm LED'lerin anotları birleştirilip VCC'ye (1'e) bağlanır; segmentleri söndürmek için katotlara 1 verilir (ters mantık). Aynı rakamı göstermek için iki farklı display'e gönderilecek veriler birbirinin tümleyenidir. Örneğin "0" göstermek için ortak katotta 3FH, ortak anotta C0H gönderilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pull-up ve pull-down direnç farkının doğru anlaşılması gerektiği çok güçlü bir şekilde vurgulanmıştır. Yanlış direnç tipi varsayımıyla tüm keypad tarama mantığının ve kontrol değerlerinin tersine döneceği, bu hatanın sınavlarda sıkça yapıldığı belirtilmiştir.
- Ortak anot ve ortak katot display farkının iyi bilinmesi gerektiği; aksi halde ters veri gönderileceği ve ekranda yanlış karakter görüneceği vurgulanmıştır.
- Adres çözümlemede birden fazla doğru çözüm olabileceği; önemli olan mantığın doğru kurulması olduğu belirtilmiştir. Sınavlarda bu nedenle farklı tasarımlar kabul edilir.
- Control word gönderilmeden önce 8255'in hangi adreste olduğunu belirlemenin kritik önemi: Control word'ün doğru adrese gönderilmesi gerekir, aksi halde entegre programlanmaz.
- Dekoder kullanımının pratik avantajları vurgulanmış; kapı tabanlı tasarımlarda gözden kaçan senaryolar olabileceği uyarısı yapılmıştır.

## Kısa Tekrar Notları

- 8255 adresleme: Başlangıç adresinden port A, B, C ve control word adresleri türetilir
- Çift adresli: A0=0 şartı chip select'e eklenir; tek adresli: A0=1 şartı NOR/NOT ile sağlanır
- Sıra düzen adreslemede BHE + A0 ile 8 bitlik entegre 16 bit veri yoluna bağlanır
- Control Word: D7=1 → Mod seçimi; D7=0 → BSR modu
- Mod 0: Basit I/O (handshake yok); Mod 1: Handshake (tek yönlü); Mod 2: Çift yönlü (sadece Port A)
- BSR: D7=0, D3-D2-D1=pin seçimi (0-7), D0=set(1)/reset(0)
- Pull-up direnç → 0 ile tara, 0 kontrol et; Pull-down direnç → 1 ile tara, 1 kontrol et
- Ortak katot: Yakmak için 1 ver; Ortak anot: Söndürmek için 1 ver (ters mantık)
- Dekoder tercih edilir: Enable pinleriyle çoklu koşul kolayca kontrol edilir

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Adres Çözme Tasarım Adımları:**
Bir 8255 entegresini belirli bir adrese yerleştirmek için şu adımlar izlenir: 1) Başlangıç adresi binary olarak yazılır. 2) Port A, B, C ve control word için adresler belirlenir (çift/tek/sıra düzene göre). 3) Hangi mikroişlemci adres hatlarının (A2-A1 gibi) 8255'in A1-A0 pinlerine bağlanacağı belirlenir; bu pinler port seçimini sağlar. 4) Kalan üst adres pinleri (A3, A4, ... A7 gibi) ve IO/M sinyali kullanılarak chip select devresi tasarlanır. 5) Dekoder veya NAND/OR/NOT kapıları ile istenen adreste 0 sinyali üretilerek CS aktif edilir. 6) IO/M=0 (I/O erişimi) şartı da enable devresine eklenir.

**Mod 1 Handshake Sinyalleri:**
Mod 1'de portlar arası iletişim handshake sinyalleri ile senkronize edilir. Input tarafında STB (Strobe) sinyali karşı taraftan gelir ve "veri gönderdim, alabilecek misin?" anlamına gelir. 8255 bu sinyali alınca IBF (Input Buffer Full) sinyali üretir ve "veriyi aldım, hazır" der. Bu iki sinyalin ve interrupt enable'in birleşimiyle interrupt oluşur ve mikroişlemci veriyi okur. Output tarafında ise mikroişlemci WR sinyaliyle veriyi porta yazar, 8255 OBF (Output Buffer Full) sinyali üretir ve karşı tarafa "veri var, alabilecek misin?" der. Karşı taraf ACK (Acknowledge) sinyali gönderdiğinde veri aktarımı tamamlanır ve interrupt oluşur.

**BSR Modunun Pratik Kullanımı:**
BSR modu özellikle Mod 1 ve Mod 2 handshake mekanizmalarında Port C'nin handshake sinyallerini manuel olarak kontrol etmek için kullanılır. Örneğin Mod 1'de interrupt enable sinyalleri (INTE A = PC6, INTE B = PC2) BSR modunda set veya reset edilerek interrupt açılıp kapatılabilir. BSR modunda control word şu formatta gönderilir: D7=0 (BSR modu), D6-D4=önemsiz (X), D3-D2-D1=pin numarası (binary), D0=1(set)/0(reset). Örneğin PC2'yi 1 yapmak için: 0000 0101 = 05H gönderilir.

**Keypad Tarama Algoritması:**
Pull-up dirençli bir keypad'de tarama işlemi şu adımlarla yapılır: 1) Sütun portundan bir sütunu 0 yap (diğer sütunlar 1). 2) Satır portunu oku. 3) Hangi satırda 0 varsa o satır-sütun kesişimindeki tuşa basılmış demektir. 4) Bir sonraki sütuna geç ve tekrar et. Pull-down dirençli yapıda ise sütunlar 1 ile taranır ve satırlarda 1 kontrol edilir. Hangi tuşa basıldığının belirlenmesi için satır-sütun kombinasyonundan tuş indeksi hesaplanır. Bu tarama işlemi sürekli bir döngü içinde veya interrupt tabanlı olarak gerçekleştirilebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
