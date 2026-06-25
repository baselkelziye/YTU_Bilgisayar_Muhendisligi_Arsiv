# Ders 2 Lab Çalışma Özeti

## Genel Konular

- 8086 mikroişlemcinin pin yapısı ve pinlerin işlevleri (BHE, ALE, AD0-AD15, Reset, Ready, MN/MX, RD, WR vb.)
- AD0-AD15 hatlarında zaman çoğullama (time multiplexing): adres ve verinin aynı hatları paylaşması
- Aktif düşük (active low) ve aktif yüksek (active high) kavramları; pin isimlerinin üzerindeki çizginin anlamı
- Proteus simülasyon ortamında proje oluşturma, 8086 ailesi ve MASM derleyicisi seçimi
- Bus bağlantıları, terminal kullanımı ve etiketleme (label) işlemleri
- 74273 entegresi: 8 bitlik D tipi pozitif kenar tetiklemeli flip-flop
- 8255 PPI (Programlanabilir Çevre Birimi Arayüzü): Port A, B, C yapısı ve giriş/çıkış olarak programlanabilmesi
- 3-8 dekoder ile adres çözümleme (address decoding)
- Adres çözümlemede çift adres kullanımı ve BHE sinyalinin rolü
- Flip-flop'ların zaman çoğullamalı veri yolundan adres süzme görevi
- Proteus'ta debug (hata ayıklama) özelliği: adım adım simülasyon ve register değerlerinin binary olarak görüntülenmesi

## Hocanın Özellikle Vurguladığı Kısımlar

- AD0-AD15 hattının neden "AD" olarak adlandırıldığı: adres (address) ve veri (data) yollarının aynı pinleri paylaşması (zaman çoğullama)
- ALE sinyalinin kritik önemi: ALE 1'den 0'a düşerken adres bilgisi latch'lenir; bu sinyal flip-flop'ların clock girişine bağlanarak adres veriden ayrıştırılır
- BHE (Bus High Enable) pininin aktif düşük çalışması: şapkalı (çizgili) gösterim 0'da aktif anlamına gelir
- MN/MX pininin şapkasız olması nedeniyle 1 ile beslenmesi ve işlemciyi minimum modda çalıştırması
- Çift adres kullanımının nedeni: A0'ın sürekli 0 olması; 8 bitlik veri yolunun düşük yarımının (D0-D7) aktif olması
- 74273 flip-flop'ların adres çözümlemedeki rolü: AD hattından gelen verilerden sadece adres bilgisini süzerek dekoderin girişine aktarması
- Dekoder çıkışlarının aktif düşük (bubble) olması: ilgili giriş değeri geldiğinde seçilen çıkışın 0'a düşmesi
- 8255'in sadece belirli bir adres aralığında çalışmasının adres çözümleme ile sağlanması
- Adres tablosu oluştururken başlangıç adresinden itibaren ardışık çift adreslerin sıralanması (örneğin F8h, FAh, FCh, FEh)

## Kısa Tekrar Notları

- **Zaman Çoğullama (Time Multiplexing):** AD0-AD15 hattında adres ve veri aynı hatları farklı zamanlarda kullanır; ALE sinyali adresin hatta olduğu anı belirtir
- **BHE (Bus High Enable):** Aktif düşük; 0 olduğunda bus'ın yüksek 8 biti (D8-D15) aktif olur, 0 olduğunda düşük 8 bit (D0-D7) aktif olur
- **ALE (Address Latch Enable):** Aktif yüksek; 1'den 0'a düşüşte adres bilgisi latch'lenir
- **MN/MX:** Şapkasız (aktif yüksek); 1 = minimum mod, 0 = maksimum mod
- **74273:** Oktal (8 bit) D tipi pozitif kenar tetiklemeli flip-flop; clock'un yükselen kenarında girişteki veriyi çıkışa aktarır
- **8255 PPI:** D0-D7 veri yolu, Port A/B/C (her biri 8 bit); ASM'de IN ve OUT komutlarıyla kullanılır
- **3-8 Dekoder:** 3 bitlik giriş (C=MSB, A=LSB), 8 çıkış; enable pinleri (G1=aktif yüksek, G2A/G2B=aktif düşük) sağlandığında giriş değerine karşılık gelen çıkış low olur
- **Adres Çözümleme:** 8255'e belirli bir başlangıç adresi atanır; dekoder ve flip-flop'lar yardımıyla sadece o adres aralığında cihaz aktif hale getirilir
- **Debug (Proteus):** Simülasyonu adım adım çalıştırma; her adımda register'lardaki binary değerler görüntülenebilir

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

- **8086 Adres-Veri Yolu Mimarisi:** 8086, 20 bit adres ve 16 bit veri yoluna sahiptir. Adresin ilk 16 biti (A0-A15) veri yolu (D0-D15) ile aynı hatları paylaşır; buna AD0-AD15 denir. Adresin kalan 4 biti (A16-A19) ayrı hatlardadır. Zaman çoğullama sayesinde pin sayısı azaltılmıştır ancak adres ve verinin ayrıştırılması için ek devre elemanları (flip-flop, dekoder) gerekir.

- **ALE ve Flip-Flop ile Adres Ayırma:** AD hattındaki verinin adres mi veri mi olduğunu ALE sinyali belirler. ALE 1 olduğu sırada hatta adres vardır. ALE'nin 1'den 0'a düşüş anında adres bilgisi kararlı hale gelir. Bu sinyal, 74273 flip-flop'ların clock girişine bağlanarak adres bilgilerinin latch'lenmesi sağlanır. Flip-flop'ların MR (Master Reset) pinleri de uygun şekilde beslenmelidir.

- **Adres Çözümleme Adımları:**
  1. AD hattından flip-flop'lar yardımıyla adres süzülür (ALE clock olarak kullanılır)
  2. Süzülen adreslerden A1 ve A0, 8255'in port seçim girişlerine (A1, A0) bağlanır
  3. Kalan üst adres bitleri (A7-A3 gibi) dekoderin girişine (C, B, A) bağlanır
  4. Dekoderin enable pinleri ve giriş kombinasyonu, istenen başlangıç adresine göre ayarlanır
  5. Dekoder çıkışındaki aktif düşük sinyal, 8255'in chip select (CS) girişine bağlanarak sadece ilgili adreste 8255 aktif olur

- **Çift Adres ve BHE İlişkisi:** 8255 ile 8 bitlik veri yolu (D0-D7) üzerinden haberleşildiğinde BHE=0 olmalıdır (aktif düşük). BHE=0 olması A0=0 ile birlikte gerçekleşir; bu da sadece çift adreslerin (F8h, FAh, FCh, FEh gibi) kullanılması anlamına gelir. Tek adresler (F9h, FBh gibi) kullanılmaz çünkü bu durumda BHE=1 olur ve düşük 8 bit aktif olmaz.

- **Proteus'ta Proje Oluşturma:** New Project > İsim verilir > Schematic (default) > PCB yok (Do not create PCB) > Firmware Project: Family ve Controller olarak 8086 seçilir > Compiler olarak MASM seçilir (gerekirse kurulum yapılır) > Finish. Workspace'te hem kaynak kod editörü hem de şematik capture (sürükle-bırak devre tasarımı) bulunur.

- **Bus Terminal ve Label Kullanımı:** Bus hatlarını doğrudan çekmek yerine terminal ile kesilip aynı isimli label ile başka bir noktadan çağrılabilir. Bu, karmaşık devrelerin okunabilirliğini artırır. Place Label veya Place Wire ile tekil hatlar da etiketlenebilir.

- **Dekoder Enable Koşulları:** 74HC138 gibi 3-8 dekoderlerde 3 enable pini vardır: G1 (aktif yüksek), G2A ve G2B (aktif düşük). Dekoderin çalışması için G1=1, G2A=0, G2B=0 olmalıdır. Bu koşullar sağlandıktan sonra CBA girişindeki binary değere karşılık gelen çıkış low olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
