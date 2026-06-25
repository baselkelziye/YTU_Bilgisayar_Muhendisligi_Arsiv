# Ders 2 Çalışma Özeti

## Genel Konular

- 8086 Mikro İşlemci Pin Diyagramı (Bacak Bağlantıları)
  - Toplam 40 pin (DIP kılıf yapısında)
  - Pinlerin işlevsel gruplandırılması: Adres, Veri, Güç, Kontrol sinyalleri

- Adres ve Veri Yolları (Multiplex Yapı)
  - **AD0 - AD15:** Adres ve veri bacaklarının ortak kullanıldığı multiplex hatları (16 pin)
  - **A16 - A20:** Sadece adres bilgisi taşıyan ek 4 pin (toplam 20 adres ucu)
  - **ALE (Address Latch Enable):** Multiplex hatlarının ne zaman adres, ne zaman veri taşıdığını bildiren sinyal. ALE=1 olduğunda AD hatlarında adres bilgisi, ALE=0 olduğunda veri bilgisi bulunur.

- Kontrol Sinyalleri
  - **RD (Read):** Bellek veya çevre biriminden okuma yapılacağını belirtir (aktif düşük)
  - **WR (Write):** Bellek veya çevre birimine yazma yapılacağını belirtir (aktif düşük)
  - **IO/M (Input-Output/Memory):** İşlemin input-output mu bellek ile mi yapıldığını seçer
  - **BHE (Bus High Enable):** Yüksek anlamlı 8 bitlik verinin (D8-D15) taşınacağını aktif eder

- Giriş-Çıkış Modu
  - Mikro işlemci dış dünya ile iki yolla iletişim kurar: Input-Output birimleri veya Bellek (Memory)
  - IO/M sinyali hangi tür iletişim kurulduğunu belirler
  - AD hatları hem adres hem veri taşıdığı için zamanlama çok önemlidir

- Minimum ve Maximum Mod
  - **Minimum Mod:** Tek başına çalışan 8086 için kullanılır, kontrol sinyalleri doğrudan üretilir
  - **Maximum Mod:** Birden fazla işlemcinin birlikte çalıştığı durumlarda kullanılır (ko-prosesör)

- Kesme (Interrupt) Yapısı
  - **NMI (Non-Maskable Interrupt):** Dışarıdan gelen ve göz ardı edilemeyen kesme. Bayrak durumuna bakılmaksızın her zaman işlenir.
  - **INTR (Interrupt Request):** Normal kesme isteği, IF bayrağı aktif ise işlenir
  - Kesme mekanizması, çevre birimlerinden gelen acil durum sinyallerini yönetmek için kullanılır

## Hocanın Özellikle Vurguladığı Kısımlar

- ALE sinyalinin önemi: Adres ve veri hatlarının aynı pinleri kullanmasından dolayı, hangi bilginin ne zaman taşındığını ALE sinyali belirler. Bu zamanlama çok kritiktir.
- BHE pininin 16-bit veri yolunu 8-bit olarak ikiye bölme mantığı: BHE=0 iken D8-D15 (üst byte), A0=0 iken D0-D7 (alt byte) kullanılır
- IO/M sinyali sayesinde aynı adres hem bellek hem de input-output için kullanılabilir (isolated I/O)
- Minimum modda çalışılacaktır; maximum mod ile ileride uğraşılmayacaktır
- Çevre birimlerinin programlanması donanımsal bacak bağlantılarıyla doğrudan ilişkilidir

## Kısa Tekrar Notları

- 8086'da 20 adres ucu, 16 veri ucu, 40 pin toplam
- Multiplex yapı: AD0-AD15 hem adres hem veri taşır, ALE ile ayrılır
- RD/WR sinyalleri aktif düşüktür (0 geldiğinde aktif olur)
- IO/M=0 → Input-Output işlemi, IO/M=1 → Bellek işlemi
- BHE ile高位/低位 byte seçimi yapılır
- NMI her zaman kesme yapar, INTR IF bayrağına bağlıdır

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8086'nın pin diyagramını anlamak, bu işlemciyi programlamanın temelidir. İşlemcinin 40 pini vardır ve bu pinlerin çoğu çift işlevlidir (multiplex). En önemli multiplex yapı AD0-AD15 hatlarıdır. Bu 16 hat, hem adres bilgisi hem de veri bilgisi taşır. Birinci clock döngüsünde bu hatlarda adres bilgisi bulunurken, sonraki döngülerde veri bilgisi bulunur. Bu ayrımı sağlayan sinyal ALE'dir.

Adresleme işlemi şu şekilde çalışır: Mikro işlemci önce adres bilgisini AD hatlarına koyar, ardından ALE sinyalini aktif ederek dış devreye "şimdi adreste bilgi var" der. Dış devre (örneğin bir latch entegresi) bu adres bilgisini yakalar. Daha sonra mikro işlemci AD hatlarına veri bilgisi koyar ve RD veya WR sinyali ile okuma/yazma işlemini başlatır.

BHE (Bus High Enable) pini, 16-bit veri yolunun üst byte'ının (D8-D15) kontrolünü sağlar. BHE=0 olduğunda üst byte aktif olur, A0=0 olduğunda ise alt byte (D0-D7) aktif olur. Bu iki sinyalin kombinasyonu ile 16-bit, 8-bit upper veya 8-bit lower veri transferi yapılabilir.

IO/M sinyali, izole (isolated) input-output mimarisinin temelini oluşturur. Bu sinyal sayesinde aynı adres uzayı hem bellek hem de çevre birimleri için kullanılabilir. IO/M=1 ise bellek ile iletişim, IO/M=0 ise çevre birimi ile iletişim kurulur. Bu sayede bellek adresleme alanı ve input-output adresleme alanı birbirinden tamamen ayrılabilir.
