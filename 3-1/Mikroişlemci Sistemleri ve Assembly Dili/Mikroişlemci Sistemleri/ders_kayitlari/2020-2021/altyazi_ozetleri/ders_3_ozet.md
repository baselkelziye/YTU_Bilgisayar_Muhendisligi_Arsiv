# Ders 3 Çalışma Özeti

## Genel Konular

- Basit Giriş-Çıkış Birimlerinin Adreslenmesi ve Donanımsal Tasarımı
  - Mikroişlemcinin çevre birimleriyle (LED, buton gibi) iletişim kurabilmesi için önce adres yolunu kullanarak hedef birimin chip select (CS) ucunu aktif etmesi, ardından veri yolundan okuma veya yazma yapması gerekir. Adres çözme (address decoding) işlemi NAND kapıları veya dekoderler kullanılarak gerçekleştirilir. Soruda verilen başlangıç adresinin binary karşılığı analiz edilerek hangi adres pinlerinin 1 veya 0 olması gerektiği belirlenir ve bu pinler bir NAND kapısına bağlanarak chip select sinyali üretilir.
- 74245 Transceiver Entegresi ve DIR Bacagı
  - 74245 entegresi çift yönlü veri iletimi sağlayan bir transceiver'dır. DIR (Direction) bacağına logic 1 verildiğinde A'dan B'ye (veri yazma/output), logic 0 verildiğinde B'den A'ya (veri okuma/input) veri aktarımı yapılır. Chip select (CS) bacağı aktif düşük (bubble) olduğundan 0 geldiğinde entegre enable olur. Bu entegre, mikroişlemci ile çevre birimleri arasında veri yönünü kontrol eden bir arayüz elemanıdır.
- OUT ve IN Komutlarıyla Port Erişimi
  - Assembly dilinde OUT komutu DX registerındaki port adresine AL'deki veriyi gönderir (yazar). IN komutu ise DX'teki port adresinden veriyi okuyarak AL'ye aktarır. Port adresi 16 bitlik (DX registerı) bir değerdir; sorularda verilen hexadecimal adres DX'e yüklenir. 8 bitlik işlemler için AL kullanılırken, 16 bitlik işlemler için AX kullanılabilir.
- Buton Okuma ve Sıfır Kontrolü
  - Butonlar mikroişlemciye bağlandığında pull-up direnç nedeniyle normal durumda port pini 1 (5V) değerini okur. Butona basıldığında pin ground'a çekilir ve 0 okunur. Bu nedenle buton uygulamalarında her zaman 0 değeri kontrol edilir. Döngü içinde port okunur, okunan değer 0xFF ile karşılaştırılır; eşitse hiçbir butona basılmamıştır (hepsi 1), eşit değilse bir veya daha fazla butona basılmıştır.
- 8255 Programlanabilir Çevre Arayüzü (PPI) Entegresi
  - 8255 entegresi mikroişlemci ile çevre birimleri arasında programlanabilir bir arayüz sağlar. 3 adet 8 bitlik portu (Port A, Port B, Port C) bulunur. Port C'nin özel bir özelliği vardır: üst 4 biti (PC4-PC7) Grup A'ya, alt 4 biti (PC0-PC3) Grup B'ye aittir ve bu 4 bitlik gruplar bağımsız olarak input/output olarak programlanabilir. 8 bitlik veri yolu üzerinden mikroişlemciye bağlanır.
- 8255'in İç Bacakları (A0, A1) ve Port Seçimi
  - 8255'in kendi içindeki A0 ve A1 pinleri (mikroişlemcinin A0 ve A1'i ile karıştırılmamalıdır!) hangi porta erişileceğini belirler: A0=0, A1=0 → Port A; A0=1, A1=0 → Port B; A0=0, A1=1 → Port C; A0=1, A1=1 → Control Word (programlama modu). Bu pinlere mikroişlemcinin uygun adres hatları bağlanarak port seçimi yapılır.
- Control Word (Kontrol Kelimesi) ve 8255'in Programlanması
  - 8255'i kullanmadan önce control word gönderilerek entegre programlanır. D7 biti (MSB) = 1 ise Mode Selection modu, = 0 ise Bit Set/Reset modu seçilir. D6-D5 bitleri Grup A'nın modunu (00=Mod 0, 01=Mod 1, 1x=Mod 2), D4 biti Port A'nın yönünü (1=input, 0=output), D3 biti Port C upper'ın yönünü, D2 biti Grup B'nin modunu, D1 biti Port B'nin yönünü, D0 biti Port C lower'ın yönünü belirler.
- 16 Bit Veri Yolunda 8 Bitlik Çevre Biriminin Kullanılması (BHE)
  - 8255'in veri yolu 8 bit olmasına rağmen mikroişlemcinin veri yolu 16 bit'tir. BHE (Bus High Enable) pini ile A0 pin'i birlikte kullanılarak bu uyumsuzluk çözülür: BHE=0, A0=1 → üst 8 bit (D8-D15) tek adresten okuma; BHE=1, A0=0 → alt 8 bit (D0-D7) çift adresten okuma. İki cycle'da 16 bitlik veri yolu elde edilir.
- Dekoder ile Adres Çözme
  - 3'e 8 dekoder gibi entegreler, birden fazla adres pinini aynı anda değerlendirerek chip select sinyali üretmek için kullanılır. Dekoderin enable pinlerine adres hatları ve IO/M sinyali bağlanarak istenen adres aralığında entegrenin aktif olması sağlanır. Dekoder kullanmak, çok sayıda NAND kapısı kullanmaktan daha pratik ve hataya açıktır.

## Hocanın Özellikle Vurguladığı Kısımlar

- 8255'in kendi A0-A1 pinleri ile mikroişlemcinin A0-A1 adres hatlarının kesinlikle karıştırılmaması gerektiği defalarca vurgulanmıştır. 8255'in A0-A1'i entegrenin kendi iç port seçim pinleridir.
- Adres çözümlemede chip select mantığının doğru kurulmasının kritik önemi: Yanlış adres çözme tasarımında entegre yanlış adreste aktif olur veya hiç aktif olmaz.
- Buton uygulamalarında her zaman 0'ın kontrol edildiği (pull-up direnç nedeniyle), bu bilginin örneklerde ve lablarda çok önemli olduğu vurgulanmıştır.
- Aynı adrese hem giriş hem çıkış birimi yerleştirilirse A0'ın farklı değerleriyle yazma ve okuma için farklı adreslerin oluşacağı, bu nedenle ek lojik işlemler gerektiği açıklanmıştır.
- Dekoder kullanımının NAND kapılarına göre daha mantıklı ve güvenilir bir adres çözme yöntemi olduğu özellikle tavsiye edilmiştir.

## Kısa Tekrar Notları

- 74245: DIR=1 → A'dan B'ye yazma; DIR=0 → B'den A'ya okuma; CS=0 → aktif
- 8255: 3×8 bit port (A, B, C); Port C = 4+4 bit bağımsız programlanabilir
- 8255 A0-A1: 00=Port A, 01=Port B, 10=Port C, 11=Control Word
- Control Word D7=1 → Mode Selection; D6-D5 → Mod seçimi; D4 → Port A yönü; D3 → Port C upper; D2 → Grup B modu; D1 → Port B yönü; D0 → Port C lower
- BHE=0, A0=1 → üst 8 bit (tek adres); BHE=1, A0=0 → alt 8 bit (çift adres)
- Buton okumada her zaman 0 kontrol edilir (pull-up direnç nedeniyle)
- OUT DX → AL'deki veriyi DX'in gösterdiği porta yazar; IN DX → porttan okur AL'ye koyar
- Dekoder ile adres çözme: Enable pinlerine adres hatları bağlanarak istenen adreste chip select üretilir

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Adres Çözme (Address Decoding) Mantığı:**
Mikroişlemci bir çevre birimine erişmek istediğinde önce adres yolundan hedef birimin bulunduğu adresi gönderir. Bu adres bilgisi bir adres çözme devresi (dekoder veya NAND kapıları) üzerinden geçirilerek hedef entegrenin chip select (CS) ucuna 0 sinyali üretir. Örneğin başlangıç adresi F0000H olan bir çıkış birimi tasarlanırken, bu adresin binary karşılığı (1111 0000 0000 0000 0000) analiz edilir. A19-A16 gibi sabit 1 olan pinler doğrudan NAND kapısına bağlanır, 0 olması gereken pinler ise NOT'lanarak bağlanır. Tüm koşullar sağlandığında NAND kapısının çıkışı 0 olur ve bu chip select'i aktif eder. IO/M sinyali de bu sürece dahil edilerek I/O erişimi mi bellek erişimi mi olduğu kontrol edilir.

**8255 Entegresi ve Port Yapısı:**
8255 Programlanabilir Çevre Arayüzü (PPI), mikroişlemci ile çevre birimleri arasında esnek bir bağlantı noktası sağlar. Üç portu vardır: Port A (8 bit), Port B (8 bit) ve Port C (8 bit). Port C'nin özel yapısı şudur: Üst 4 biti (PC4-PC7) Grup A kontrolüne, alt 4 biti (PC0-PC3) Grup B kontrolüne aittir. Bu sayede Port A 8 bit input/output olarak ayarlanırken, Port C'nin üst ve alt 4 bitlik kısımları ayrı ayrı input veya output olarak programlanabilir. Mod 0'da toplam 16 farklı input/output konfigürasyonu mümkündür.

**Control Word Detaylı Analiz:**
Control word 8 bitlik bir değerdir ve 8255'in kontrol yazmacına gönderilir. D7=1 ile Mode Selection moduna girilir. D6-D5 bitleri Grup A (Port A ve Port C upper) için mod seçer: 00=Mod 0 (basit I/O), 01=Mod 1 (handshake), 10 veya 11=Mod 2 (çift yönlü handshake, sadece Port A). D4=Port A'nın yönü (1=input, 0=output). D3=Port C upper'ın yönü. D2=Grup B (Port B) için mod seçimi (0=Mod 0, 1=Mod 1). D1=Port B'nin yönü. D0=Port C lower'ın yönü. Örneğin 10010011 binary = 93H gönderilirse: Mod 0, Port A input, Port C upper output, Port B Mod 0 input, Port C lower output olur.

**BHE ile 16 Bit Veri Yolu Oluşturma:**
8255 gibi 8 bitlik çevre birimlerini 16 bitlik veri yoluna bağlamak için BHE ve A0 pinleri birlikte kullanılır. Çift adreslerde (A0=0) alt 8 bit (D0-D7) üzerinden veri aktarımı yapılır. Tek adreslerde (A0=1) üst 8 bit (D8-D15) üzerinden veri aktarımı yapılır. Bir 8255'i çift adreslere, başka bir 8255'i tek adreslere yerleştirerek veya BHE'yi anahtarlama elemanı olarak kullanarak 8 bitlik iki cycle'da 16 bitlik veri yolu elde edilir. Sorularda "çift adresleri kullanın" denildiğinde A0=0 şartı chip select devresine eklenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
